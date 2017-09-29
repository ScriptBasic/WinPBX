' ========================================================================================
' TLB_EVENTS.INC - Include file for the TypeLyb Browser
' (C) 2011 by José Roca. All rights reserved.
' Generates code for events sink.
' ========================================================================================

GLOBAL TLB_SelectedEvents AS STRING

DECLARE FUNCTION LV_Events_GetCheckedItems (BYVAL hDlg AS DWORD) AS STRING
DECLARE FUNCTION LV_Events_AddCheckItem (BYVAL hDlg AS DWORD, BYVAL strText AS STRING, BYVAL lParam AS LONG) AS LONG
DECLARE FUNCTION TLB_SelectEventsDialog (BYVAL hParent AS DWORD, BYVAL strCaption AS STRING) AS LONG
DECLARE FUNCTION TLB_MakeEventFunctions (BYVAL hWnd AS DWORD, BYVAL fSelected AS LONG) AS LONG

' ========================================================================================
' Get a list of checked items
' ========================================================================================
FUNCTION LV_Events_GetCheckedItems (BYVAL hDlg AS DWORD) AS STRING

   LOCAL hLv AS DWORD
   LOCAL nCount AS LONG
   LOCAL i AS LONG
   LOCAL szItem AS ASCIIZ * 255

   TLB_SelectedEvents = ""
   hLv = GetDlgItem(hDlg, 100)
   nCount = ListView_GetItemCount(hLv)
   FOR i = 0 TO nCount - 1
      IF ListView_GetCheckState (hLv, i) THEN
         ListView_GetItemText hLv, i, 0, szItem, SIZEOF(szItem)
         TLB_SelectedEvents = TLB_SelectedEvents & "#" & szItem & "#"
      END IF
   NEXT

   FUNCTION = TLB_SelectedEvents

END FUNCTION
' ========================================================================================

' ========================================================================================
' Add an item with a check box
' ========================================================================================
FUNCTION LV_Events_AddCheckItem (BYVAL hDlg AS DWORD, BYVAL strText AS STRING, BYVAL lParam AS LONG) AS LONG
   DIM lvi AS LVITEM
   IF hDlg = 0 THEN EXIT FUNCTION
   IF IsWindow(hDlg) = 0 THEN EXIT FUNCTION
   lvi.mask     = %LVIF_TEXT OR %LVIF_PARAM
   lvi.pszText  = STRPTR(strText)
   lvi.iItem    = SendMessage(hDlg, %LVM_GETITEMCOUNT, 0, BYVAL 0)
   lvi.iSubItem = 0
   lvi.lParam   = lParam
   FUNCTION = SendMessage(hDlg, %LVM_INSERTITEM, 0, VARPTR(lvi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Select events dialog
' ========================================================================================
FUNCTION TLB_SelectEventsDialog (BYVAL hParent AS DWORD, BYVAL strCaption AS STRING) AS LONG

   LOCAL hDlg2 AS LONG
   LOCAL dwStyle AS DWORD
   LOCAL dwExStyle AS DWORD
   LOCAL i AS LONG

   DIALOG NEW hParent, strCaption, , , 238, 166, %WS_POPUP OR %WS_CAPTION OR %WS_SYSMENU OR %DS_MODALFRAME, 0 TO hDlg2

   CONTROL ADD BUTTON, hDlg2, 101, "&All events", 5, 148, 70, 14, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT
   CONTROL ADD BUTTON, hDlg2, 102, "&Selected events", 83, 148, 70, 14, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT
   CONTROL ADD BUTTON, hDlg2, %IDCANCEL, "&Cancel", 161, 148, 70, 14, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT

   ' Create the listview
   dwStyle = %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %LVS_REPORT OR %LVS_SMALLICON
   CONTROL ADD "SysListView32", hDlg2, 100, "", 5, 5, 226, 139, dwStyle, %WS_EX_CLIENTEDGE
   dwExStyle = SendMessage(GetDlgItem(hDlg2, 100), %LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0)
   dwExStyle = dwExStyle OR %LVS_EX_CHECKBOXES
   SendMessage GetDlgItem(hDlg2, 100), %LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwExStyle

   ' Add the items
   FOR i = LBOUND(TLB_EventsArray) TO UBOUND(TLB_EventsArray)
      LV_Events_AddCheckItem GetDlgItem(hDlg2, 100), TLB_EventsArray(i), 0
   NEXT

   TLB_SelectedEvents = ""

   DIALOG SHOW MODAL hDlg2, CALL SelectEventsDlgProc

END FUNCTION
' ========================================================================================

' ========================================================================================
CALLBACK FUNCTION SelectEventsDlgProc() AS LONG

   SELECT CASE CBMSG

   CASE %WM_COMMAND

      SELECT CASE CBCTL
         CASE 101
            IF CBCTLMSG = %BN_CLICKED THEN
               TLB_SelectedEvents = "All"
               DIALOG END CBHNDL, 1
            END IF
         CASE 102
            IF CBCTLMSG = %BN_CLICKED THEN
               LV_Events_GetCheckedItems(CBHNDL)
               DIALOG END CBHNDL, 2
            END IF
         CASE %IDCANCEL
            IF CBCTLMSG = %BN_CLICKED THEN
               TLB_SelectedEvents = ""
               DIALOG END CBHNDL, 0
            END IF
      END SELECT

   END SELECT

END FUNCTION
' ========================================================================================

' ========================================================================================
' Generates code for the event functions
' ========================================================================================
FUNCTION TLB_MakeEventFunctions (BYVAL hWnd AS DWORD, BYVAL fSelected AS LONG) AS LONG

   LOCAL hr                 AS LONG                   ' // HRESULT
   LOCAL nEventsCount       AS LONG                   ' // Number of events
   LOCAL wszPath            AS WSTRINGZ * %MAX_PATH   ' // Path (unicode)
   LOCAL pITypeLib          AS ITypeLib               ' // TypeLib interface
   LOCAL TypeInfoCount      AS LONG                   ' // Number of TypeInfos
   LOCAL i                  AS LONG                   ' // LOOP counter
   LOCAL pTKind             AS DWORD                  ' // TYPEKIND
   LOCAL pITypeInfo         AS ITypeInfo              ' // TypeInfo interface
   LOCAL pTypeAttr          AS TYPEATTR PTR           ' // Address of a pointer to the TYPEATTR structure
   LOCAL bstrName           AS WSTRING                ' // Member's name (unicode)
   LOCAL bstrDocString      AS WSTRING                ' // Documentation string (unicode)
   LOCAL pdwHelpContext     AS DWORD                  ' // Help context
   LOCAL bstrHelpFile       AS WSTRING                ' // Help file (unicode)
   LOCAL idx                AS LONG                   ' // Index
   LOCAL fIsEventsInterface AS LONG                   ' // Flag
   LOCAL strInterfaceName   AS STRING                 ' // Interface name
   LOCAL szText             AS ASCIIZ * 255           ' // General purpose variable
   LOCAL xCount             AS LONG                   ' // Counter variable
   LOCAL x                  AS LONG                   ' // Loop counter
   LOCAL szName             AS ASCIIZ * 255           ' // Name
   LOCAL pFuncDesc          AS FUNCDESC  PTR          ' // Pointer to a FUNCDESC structure
   LOCAL cParams            AS LONG                   ' // Number of parameters
   LOCAL vt                 AS WORD                   ' // Variant type
   LOCAL szFmt              AS ASCIIZ * 15            ' // Date format
   LOCAL szDate             AS ASCIIZ * 255           ' // Formatted date
   LOCAL strBaseClass       AS STRING                 ' // Base class

   IF hWnd = %NULL THEN EXIT FUNCTION
   IF ISTRUE m_Busy THEN EXIT FUNCTION

'   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
'   IF hStatusbar THEN hPrefixBox = GetDlgItem(hStatusbar, %IDC_DIALOG1_EDITPREFIX)
'   IF hPrefixBox THEN GetWindowText(hPrefixBox, szText, SIZEOF(szText))
'   TLB_PrefixStr = szText

   szFmt = "dd MMM yyyy"
   GetDateFormat %LOCALE_USER_DEFAULT, 0, BYVAL %NULL, szFmt, szDate, SIZEOF(szDate)

   ' --- Show the select events dialog ---------------------------------------------------
   nEventsCount = UBOUND(TLB_EventsArray) - LBOUND(TLB_EventsArray) + 1
   IF nEventsCount = 0 THEN
      MessageBox BYVAL %NULL, "This component doesn't have events", _
         " " & FUNCNAME$, %MB_OK OR %MB_ICONINFORMATION OR %MB_TASKMODAL
      EXIT FUNCTION
   END IF
   IF nEventsCount > 1 THEN
      IF ISTRUE fSelected THEN
         TLB_SelectEventsDialog hWnd, "Events Interfaces"
         IF TLB_SelectedEvents = "" THEN EXIT FUNCTION
         IF TLB_SelectedEvents = "All" THEN TLB_SelectedEvents = ""
      END IF
   END IF

   ' --- Empty the buffer ----------------------------------------------------------------
   m_Buffer = ""
   m_BufLen = 0

   ' --- This function isn't reentrant, so don't allow to reenter until we have finished.
   m_Busy = %TRUE
   m_Abort = %FALSE
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%TRUE, 0))

   ' --- Loads the TypeLib ---------------------------------------------------------------
   wsZPath = m_SelPath
   hr = LoadTypeLibEx(wszPath, %REGKIND_NONE, pITypeLib)
   IF hr <> %S_OK OR ISFALSE ISOBJECT(pITypeLib) THEN
      MessageBox BYVAL %NULL, "Error &H" & HEX$(hr) & " loading " & m_SelPath, _
             " " & FUNCNAME$ & ": LoadTypeLibEx", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      EXIT FUNCTION
   END IF

   ' --- Retrieves the number of TypeInfos -----------------------------------------------
   TypeInfoCount = pITypeLib.GetTypeInfoCount
   IF TypeInfoCount = 0 THEN
      MessageBox BYVAL %NULL, "This TypeLib doesn't have Type Infos" , _
         " " & FUNCNAME$ & ": ITypeLib::GetTypeInfoCount", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
      pITypeLib = NOTHING
      EXIT FUNCTION
   END IF

   ' ========================================================================================
   ' Parses the TypeLib
   ' ========================================================================================
   FOR i = 0 TO TypeInfoCount - 1

      ' --- Allow for a breath and check the abort flag ----------------------------------
      TLB_DoEvents hWnd
      IF m_Abort THEN EXIT FOR

      ' --- Retrieves the TypeKind -------------------------------------------------------
      hr = pITypeLib.GetTypeInfoType(i, pTKind)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the InfoType", _
            " " & FUNCNAME$ & ": ITypeLib::GetTypeInfoType", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Retrieves the TypeInfo interface ---------------------------------------------
      hr = pITypeLib.GetTypeInfo(i, pITypeInfo)
      IF hr <> %S_OK THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the TypeInfo interface" , _
            " " & FUNCNAME$ & ": ITypeLib_GetTypeInfo", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      ' --- Gets the address of a pointer to the TYPEATTR structure ----------------------
      hr = pITypeInfo.GetTypeAttr(pTypeAttr)
      IF hr <> %S_OK OR pTypeAttr = %NULL THEN
         MessageBox BYVAL %NULL, "Error " & FORMAT$(hr) & " retrieving the address of the TypeAttr structure" , _
            " " & FUNCNAME$ & ": ITypeInfo_GetTypeAttr", %MB_OK OR %MB_ICONERROR OR %MB_TASKMODAL
         EXIT FOR
      END IF

      SELECT CASE pTKind

         CASE %TKIND_INTERFACE, %TKIND_DISPATCH

            DO
               hr = pITypeLib.GetDocumentation(i, bstrName, bstrDocString, pdwHelpContext, bstrHelpFile)
               IF hr <> %S_OK THEN EXIT DO
               idx = 0
               fIsEVentsInterface = 0
               strInterfaceName = bstrName
               IF LEN(TLB_SelectedEvents) > 0 AND INSTR(TLB_SelectedEvents, "#" & strInterfaceName & "#") > 0 THEN fIsEventsInterface = %TRUE
               IF TLB_SelectedEvents = "" THEN
                  ARRAY SCAN TLB_EventsArray(), = strInterfaceName, TO idx
                  IF ISTRUE idx THEN fIsEventsInterface = %TRUE
               END IF
               IF ISFALSE fIsEventsInterface THEN EXIT DO
               szText = strInterfaceName
               DO
                  IF LEFT$(strInterfaceName, 1) <> "_" THEN EXIT DO
                  strInterfaceName = MID$(strInterfaceName, 2)
               LOOP
               TLB_AddLine("' ########################################################################################")
               TLB_AddLine("' Class C" & strInterfaceName)
               TLB_AddLine("' Interface name = " & szText)
               szText = GUIDTXT$(@pTypeAttr.guid)
               IF szText <> "{00000000-0000-0000-0000-000000000000}" THEN TLB_AddLine("' IID = " & szText)
               szText = bstrDocString
               REPLACE ANY $CR & $LF WITH "  " IN szText
               IF LEN(szText) THEN TLB_AddLine("' " & szText)
               IF @pTypeAttr.wTypeFlags THEN TLB_AddLine("' Attributes = " & FORMAT$(@pTypeAttr.wTypeFlags) & " [&H" & HEX$(@pTypeAttr.wTypeFlags) & "]" & TLB_InterfaceFlagsToStr(@pTypeAttr.wTypeFlags))
               TLB_AddLine("' Code generated by the " & $cCaption)
               TLB_AddLine("' Date: " & szDate & "   Time: " & TIME$)
               TLB_AddLine("' ########################################################################################")
               TLB_AddLine("")
               TLB_AddLine("CLASS C" & strInterfaceName & " GUID$(" & $DQ & GUIDTXT$(GUID$) & $DQ & ")" & " AS EVENT")
               TLB_AddLine("")
               IF UCASE$(strBaseClass) = "IUNKNOWN" THEN
                  TLB_AddLine("INTERFACE " & strInterfaceName & "Impl " & "GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")")
               ELSE
                  TLB_AddLine("INTERFACE " & strInterfaceName & "Impl " & "GUID$(" & $DQ & GUIDTXT$(@pTypeAttr.guid) & $DQ & ")" & " AS EVENT")
               END IF
               TLB_AddLine("")
'               IF pTKind = %TKIND_INTERFACE THEN
'                  TLB_AddLine("  INHERIT IUnknown")
'               ELSE
'                  TLB_AddLine("  INHERIT IDispatch")
'               END IF
               strBaseClass = TLB_GetImplementedInterface(pITypeInfo, 0)
               IF UCASE$(strBaseClass) <> "IUNKNOWN" AND UCASE$(strBaseClass) <> "IDISPATCH" THEN
                  strBaseClass = TLB_GetBaseClass(hWnd, pITypeLib, strInterfaceName)
               END IF
'               IF UCASE$(strBaseClass) <> "IUNKNOWN" THEN strBaseClass = "DUAL"
               IF UCASE$(strBaseClass) <> "IUNKNOWN" THEN strBaseClass = "IDispatch"
               TLB_AddLine("  INHERIT " & strBaseClass)
               TLB_AddLine("")
               xCount = @pTypeAttr.cFuncs
               FOR x = 0 TO xCount - 1
                  ' Gets a reference to the FuncDesc interface
                  hr = pITypeInfo.GetFuncDesc(x, pFuncDesc)
                  IF hr <> %S_OK OR pFuncDesc = %NULL THEN EXIT FOR
                  ' Retrieves the name of the method
                  pITypeInfo.GetDocumentation(@pFuncDesc.memid, bstrName, bstrDocString, pdwHelpContext, BYVAL %NULL)
                  IF hr <> %S_OK THEN EXIT FOR
                  szName = bstrName
                  IF szName = "QueryInterface" OR _
                     szName = "AddRef" OR _
                     szName = "Release" OR _
                     szName = "GetTypeInfoCount" OR _
                     szName = "GetTypeInfo" OR _
                     szName = "GetIDsOfNames" OR _
                     szName = "Invoke" THEN
                     pITypeInfo.ReleaseFuncDesc(pFuncDesc)
                     pFuncDesc = 0
                     ITERATE FOR
                  END IF
                  ' Parameters
                  TLB_AddLine("   ' =====================================================================================")
                  cParams = @pFuncDesc.cParams
                  IF pTKind = %TKIND_INTERFACE THEN
                     IF cParams THEN
                        TLB_AddLine("   METHOD " & szName & " ( _")
                     ELSE
                        IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_HRESULT THEN
                           TLB_AddLine("   METHOD " & szName & " () AS LONG")
                        ELSE
                           TLB_AddLine("   METHOD " & szName)
                        END IF
                     END IF
                  ELSE
                     IF cParams THEN
                        TLB_AddLine("   METHOD " & szName & " <" & FORMAT$(@pFuncDesc.memid) & "> ( _")
                     ELSE
                        TLB_AddLine("   METHOD " & szName & " <" & FORMAT$(@pFuncDesc.memid) & ">")
                     END IF
                  END IF
                  IF cParams THEN TLB_GetParametersInfo(hWnd, pITypeInfo, pFuncDesc, szName, 0, %CODEGEN_EVENTS, %FALSE, %FALSE, "", %FALSE)
                  IF pTKind = %TKIND_INTERFACE THEN
                     IF cParams THEN
                        IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_HRESULT THEN
                           TLB_AddLine("   ) AS LONG                                            ' HRESULT")
                        ELSE
                           TLB_AddLine("   )                                                    ' void")
                        END IF
                     END IF
                  ELSE
                     IF cParams THEN
'                        IF @pFuncDesc.elemdescFunc.tdesc.vt = %VT_HRESULT THEN
'                           TLB_AddLine("   )                                                    ' HRESULT")
'                        ELSE
                           TLB_AddLine("   )                                                    ' void")
'                        END IF
                     END IF
                  END IF
                  TLB_AddLine("")
                  TLB_AddLine("     ' *** Insert your code here ***")
                  TLB_AddLine("")
                  TLB_AddLine("   END METHOD")
                  TLB_AddLine("   ' =====================================================================================")
                  TLB_AddLine("")
               NEXT
               ' Releases the FuncDesc interface
               pITypeInfo.ReleaseFuncDesc(pFuncDesc)
               pFuncDesc = 0
               TLB_AddLine("END INTERFACE")
               TLB_AddLine("")
               TLB_AddLine("END CLASS")
               TLB_AddLine("")
               '----------
               EXIT DO
            LOOP
      END SELECT
      ' --- Releases the TYPEATTR structure ----------------------------------------------
      pITypeInfo.ReleaseTypeAttr(pTypeAttr)
      pTypeAttr = 0
      ' --- Releases the TypeInfo interface ----------------------------------------------
      pITypeInfo = NOTHING
   NEXT

   ' --- Show the report --------------------------------------------------------------
   LOCAL hPageCtrl             AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hRichEditBox          AS DWORD                ' // Handle of the rich edit box
   LOCAL hMenu                 AS DWORD                ' // Menu handle
   LOCAL hSubMenu              AS DWORD                ' // Submenu handle

   ' Fill the richedit box with the generated code
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
   IF hPageCtrl THEN
      hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
      szText = ""
      SendMessage hRichEditBox, %WM_SETTEXT, 0, VARPTR(szText)
      m_Buffer = LEFT$(m_Buffer, m_BufLen)
      SendMessage hRichEditBox, %WM_SETTEXT, 0, STRPTR(m_Buffer)
   END IF
   ' Hide the Trees tab and show the Code tab
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   IF hPageCtrl THEN
      ' Hides all the pages excepting the Code page
      ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %SW_HIDE
      ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %SW_HIDE
      ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS), %SW_HIDE
      ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_CODE), %SW_SHOW
      SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURSEL, 2, 0
      SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_SETCURFOCUS, 2, 0
   END IF
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%TRUE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_STOP, MAKLNG(%FALSE, 0))
   hMenu = GetMenu(hWnd)
   hSubmenu = GetSubMenu(hMenu, 0)
   CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
   CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_ENABLED
'         CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
   SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_CODE))

   m_Busy = %FALSE
   m_Abort = %FALSE
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
