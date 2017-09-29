' ========================================================================================
' TLB_DIALOG.INC - Include file for the TypeLyb Browser
' (C) 2011 by José Roca. All rights reserved.
' Message crackers.
' ========================================================================================

'-------------------------------------------------------------------------------
' Functions and procedures
'-------------------------------------------------------------------------------
#INCLUDE "COMDLG32.INC"
#INCLUDE "TLB_PROCS.INC"
#INCLUDE "TLB_EVENTS.INC"
#INCLUDE "TLB_DISPINT.INC"

'-------------------------------------------------------------------------------

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_InitWindow
' PURPOSE:   Initializes main window of this application instance.
' RETURN:    FALSE if initialization was successful, TRUE to close the window on
'            failure.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_InitWindow _
   ( _
   BYVAL hWnd     AS DWORD, _ ' handle of main window
   BYVAL lParam   AS LONG _   ' address of command line
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_TranslateMessage
' PURPOSE:   Preprocesses messages.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_TranslateMessage _
   ( _
   BYVAL hWnd  AS DWORD, _    ' handle of window
         tmsg  AS tagMsg _    ' message information
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnClose
' PURPOSE:   Dialog1 WM_CLOSE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnClose _
   ( _
   BYVAL hWnd  AS DWORD _  ' window handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnCreate
' PURPOSE:   Dialog1 WM_CREATE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnCreate _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL lptcs       AS DWORD, _ ' address of CREATESTRUCT structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnDestroy
' PURPOSE:   Dialog1 WM_DESTROY message handler.
'
'-------------------------------------------------------------------------------

SUB Dialog1_OnDestroy _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
         lMsgResult  AS LONG _   ' value returned to message
   )

   LOCAL strIniFileName AS STRING

   strIniFileName = TLB_ExePath & $IniFile

   ' Saves the options in the .INI file
   TLB_IniWrite strIniFileName, "Browser options", "UseMethod", FORMAT$(m_UseMethod)
   TLB_IniWrite strIniFileName, "Browser options", "UsePropGetSet", FORMAT$(m_UsePropGetSet)
   TLB_IniWrite strIniFileName, "Browser options", "UsePrefix", FORMAT$(m_UsePrefix)
   TLB_IniWrite strIniFileName, "Browser options", "UseEnumPrefix", FORMAT$(m_UseEnumPrefix)
   TLB_IniWrite strIniFileName, "Browser options", "UseHexNumbers", FORMAT$(m_UseHexNumbers)
   TLB_IniWrite strIniFileName, "Browser options", "CodeGeneration", FORMAT$(m_CodeGeneration)
   TLB_IniWrite strIniFileName, "Browser options", "ColumnToSort", FORMAT$(m_ColumnToSort)
   TLB_IniWrite strIniFileName, "Browser options", "SortOrder", m_SortOrder
   TLB_IniWrite strIniFileName, "Browser options", "MixDispInterfaces", FORMAT$(m_MixDispInterfaces)
   TLB_IniWrite strIniFileName, "Browser options", "RetrieveLicenseKey", FORMAT$(m_RetrieveLicenseKey)
   TLB_IniWrite strIniFileName, "Browser options", "UseAutomationView", FORMAT$(m_UseAutomationView)
   TLB_IniWrite strIniFileName, "Browser options", "UseSetPrefix", FORMAT$(m_UseSetPrefix)
   TLB_IniWrite strIniFileName, "Browser options", "UseIntNamesWithExObj", FORMAT$(m_UseIntNamesWithExObj)
   TLB_IniWrite strIniFileName, "Browser options", "UseParameterNames", FORMAT$(m_UseParameterNames)
   TLB_IniWrite strIniFileName, "Browser options", "AddParameterNamesPrefix", FORMAT$(m_AddParameterNamesPrefix)
   TLB_IniWrite strIniFileName, "Browser paths",   "LastAccessedFolder", m_LastPath

END SUB

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnQueryEndSession
' PURPOSE:   Dialog1 WM_QUERYENDSESSION message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnQueryEndSession _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL lSource     AS LONG, _  ' source of end-session request
   BYVAL fLogOff     AS LONG, _  ' logoff flag
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnSize
' PURPOSE:   Dialog1 WM_SIZE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnSize _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL lState   AS LONG, _  ' resizing state
   BYVAL cxClient AS LONG, _  ' width of client area
   BYVAL cyClient AS LONG _   ' height of client area
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnPaint
' PURPOSE:   Dialog1 WM_PAINT message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnPaint _
   ( _
   BYVAL hWnd  AS DWORD _  ' window handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnKillFocus
' PURPOSE:   Dialog1 WM_KILLFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnKillFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' window handle
   BYVAL hWndNewFocus   AS DWORD _  ' handle of window receiving focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnSetFocus
' PURPOSE:   Dialog1 WM_SETFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnSetFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' window handle
   BYVAL hWndOldFocus   AS DWORD _  ' handle of window losing focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnNotify
' PURPOSE:   Dialog1 WM_NOTIFY message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnNotify _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL lCtrlId     AS LONG, _  ' control identifier
   BYVAL lptnmhdr    AS DWORD, _ ' address of NMHDR structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

   ' See note in Dialog1_OnMySetFocusMessage

   LOCAL ptnmhdr    AS NMHDR PTR

   ptnmhdr = lptnmhdr

   SELECT CASE @ptnmhdr.idFrom
      CASE %IDC_DIALOG1_TAB1
         SELECT CASE @ptnmhdr.code
            CASE %TCN_SELCHANGE
               SELECT CASE SendMessage(@ptnmhdr.hwndFrom, %TCM_GETCURSEL, 0, 0)
                  CASE 0 : SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_GRID))
                  CASE 1 : SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_TREES))
                  CASE 2 : SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_CODE))
                  CASE 3 : SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS))
               END SELECT
         END SELECT
   END SELECT
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_FileOpen
' PURPOSE:   MainMenu1 IDM_OPEN notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_FileOpen _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   IF ISTRUE m_Busy THEN EXIT FUNCTION

   m_abort = %FALSE
   TLB_PrefixStr = ""
   m_SelDesc = ""
   m_selPath = TLB_OpenTypeLib(hWnd)
   IF m_selPath <> "" THEN TLB_Enumerator(hWnd, m_selPath)

   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_Save
' PURPOSE:   MainMenu1 IDM_SAVE_AS notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_Save _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   TLB_SaveReport(hWNd, TLB_PrefixStr & ".inc")
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_FileExit
' PURPOSE:   MainMenu1 IDM_EXIT notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_FileExit _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   ' Send message to quit the application
   SendMessage hWnd, %WM_CLOSE, 0, 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnCommand
' PURPOSE:   Dialog1 WM_COMMAND message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnCommand _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL lCtrlId     AS LONG, _  ' identifier of menu item, control, or accelerator
   BYVAL hWndCtrl    AS DWORD, _ ' handle of control
   BYVAL lNotifyCode AS LONG _   ' notification code
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnInitMenuPopup
' PURPOSE:   Dialog1 WM_INITMENUPOPUP message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnInitMenuPopup _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL hMenu       AS DWORD, _ ' handle of pop-up menu
   BYVAL lItemPos    AS LONG, _  ' zero-based pop-up item position
   BYVAL fSystemMenu AS LONG _   ' system menu flag
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_InterfacesDirectInterfaces
' PURPOSE:   MainMenu IDM_DISPINT notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_InterfacesDirectInterfaces _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   m_ItemName = ""
   TLB_Enumerate(hWnd, m_ItemName, %ENUM_INTERFACES, %REPORT_VIEWCODE)
   FUNCTION = %TRUE

END FUNCTION

' PROCEDURE: Dialog1_MainMenu_InterfacesDirectInterfaces
' PURPOSE:   MainMenu IDM_DISPINT notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_InterfacesDispatchInterfaces _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   TLB_EnumDispInterfaces(hWnd)
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_Help
' PURPOSE:   MainMenu IDM_HELP notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_Help _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   LOCAL szPath AS ASCIIZ * %MAX_PATH
   szPath = TLB_ExePath & "TLB_501.CHM"
   HtmlHelp 0, szPath, %HH_DISPLAY_TOC, 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_About
' PURPOSE:   MainMenu IDM_ABOUT notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_About _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   LOCAL strCaption AS STRING
   LOCAL strMessage AS STRING

   strCaption = "About TypeLib Browser"
   strMessage = "TypeLib Browser version " & $cVersion & $CRLF & _
                "Object browser and code generator for PowerBASIC" & $CRLF & _
                $cCopyright
   TLB_MsgBox hWnd, strMessage, %MB_OK, strCaption

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Tab1_SelChange
' PURPOSE:   Tab1 TCN_SELCHANGE notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Tab1_SelChange _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

   LOCAL hTabCtrl     AS DWORD
   LOCAL TabIdx       AS LONG
   LOCAL hPageCtrl    AS DWORD
   LOCAL hRichEditBox AS DWORD
   LOCAL hMenu        AS DWORD
   LOCAL hSubMenu1    AS DWORD
   LOCAL hSubMenu2    AS DWORD
   LOCAL buffer       AS STRING

   hMenu = GetMenu(hWndParent)
   hSubMenu1 = GetSubMenu(hMenu, 0)
   hSubMenu2 = GetSubMenu(hMenu, 1)
   hTabCtrl = @ptnmhdr.hwndFrom
   TabIdx = SendMessage(hTabCtrl, %TCM_GETCURSEL, 0, 0)

   hPageCtrl = GetDlgItem(hWndParent, %IDC_DIALOG1_CODE)
   IF hPageCtrl THEN
      hRichEditBox = GetDlgItem(hPageCtrl, %IDC_DIALOG1_RICHEDIT_VIEWCODE)
      IF hRichEditBox THEN buffer = Edit_GetText(hRichEditBox)
   END IF

   SELECT CASE TabIdx
      CASE 0   ' Grid
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%TRUE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%FALSE, 0))
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_RELOAD, %MF_ENABLED
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_SAVE, %MF_GRAYED
         CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
      CASE 1   ' Trees
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_RELOAD, %MF_GRAYED
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_SAVE, %MF_GRAYED
         IF TLB_LibName = "" THEN
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%TRUE, 0))
            CoolMenu_EnableMenuItem hSubMenu2, %IDM_INTERFACES, %MF_ENABLED
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_ENABLED
         END IF
         IF UBOUND(TLB_EventsArray) > - 1 THEN
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%TRUE, 0))
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         END IF
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%FALSE, 0))
      CASE 2   ' Code
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
'         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
'         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         IF LEN(buffer) > 0 THEN SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%TRUE, 0))
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_RELOAD, %MF_GRAYED
         IF LEN(buffer) > 0 THEN CoolMenu_EnableMenuItem hSubMenu1, %IDM_SAVE, %MF_ENABLED
'         CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         IF TLB_LibName = "" THEN
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%TRUE, 0))
            CoolMenu_EnableMenuItem hSubMenu2, %IDM_INTERFACES, %MF_ENABLED
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_ENABLED
         END IF
         IF UBOUND(TLB_EventsArray) > - 1 THEN
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%TRUE, 0))
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         END IF
      CASE 3   ' Options
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%FALSE, 0))
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_RELOAD, %MF_GRAYED
         CoolMenu_EnableMenuItem hSubMenu1, %IDM_SAVE, %MF_GRAYED
         CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         IF TLB_LibName = "" THEN
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%TRUE, 0))
            CoolMenu_EnableMenuItem hSubMenu2, %IDM_INTERFACES, %MF_ENABLED
            CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_ENABLED
         END IF
         IF UBOUND(TLB_EventsArray) > - 1 THEN
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%TRUE, 0))
         ELSE
            SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
         END IF
   END SELECT

   DrawMenuBar hWndParent

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Tab1_SelChanging
' PURPOSE:   Tab1 TCN_SELCHANGING notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Tab1_SelChanging _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnCreate
' PURPOSE:   Page1 WM_CREATE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnCreate _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lptcs       AS DWORD, _ ' address of CREATESTRUCT structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

   ' Send a custom message with the handle of the ListView
   ' to know when its safe to load the items
   PostMessage GetParent(hWnd), %MYCREATEMESSAGE, hWnd, 0
   lMsgResult = %FALSE
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnDestroy
' PURPOSE:   Page1 WM_DESTROY message handler.
'
'-------------------------------------------------------------------------------

SUB Dialog1_Grid_OnDestroy _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
         lMsgResult  AS LONG _   ' value returned to message
   )

END SUB

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnSize
' PURPOSE:   Page1 WM_SIZE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnSize _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL lState   AS LONG, _  ' resizing state
   BYVAL cxClient AS LONG, _  ' width of client area
   BYVAL cyClient AS LONG _   ' height of client area
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnPaint
' PURPOSE:   Page1 WM_PAINT message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnPaint _
   ( _
   BYVAL hWnd  AS DWORD _  ' control handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnKillFocus
' PURPOSE:   Page1 WM_KILLFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnKillFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndNewFocus   AS DWORD _  ' handle of window receiving focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnSetFocus
' PURPOSE:   Page1 WM_SETFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnSetFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndOldFocus   AS DWORD _  ' handle of window losing focus
   ) AS LONG

   LOCAL hStatusbar AS DWORD
   LOCAL szText     AS ASCIIZ * %MAX_PATH

   hStatusbar = GetDlgItem(GetParent(hWnd), %IDC_DIALOG1_STATUSBAR1)
   szText = "Double click the wanted item to retrieve information"
   SendMessage hStatusbar, %SB_SETTEXT, 3, BYVAL VARPTR(szText)

   ' Post a message to set the focus in the ListView
   ' See note in Dialog1_OnMySetFocusMessage
   PostMessage GetParent(hWnd), %MYSETFOCUSMESSAGE, GetDlgItem(hWnd, %IDC_DIALOG1_LISTVIEW1), 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnCreate
' PURPOSE:   Page2 WM_CREATE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnCreate _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lptcs       AS DWORD, _ ' address of CREATESTRUCT structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnDestroy
' PURPOSE:   Page2 WM_DESTROY message handler.
'
'-------------------------------------------------------------------------------

SUB Dialog1_Trees_OnDestroy _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
         lMsgResult  AS LONG _   ' value returned to message
   )

END SUB

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnSize
' PURPOSE:   Page2 WM_SIZE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnSize _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL lState   AS LONG, _  ' resizing state
   BYVAL cxClient AS LONG, _  ' width of client area
   BYVAL cyClient AS LONG _   ' height of client area
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnPaint
' PURPOSE:   Page2 WM_PAINT message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnPaint _
   ( _
   BYVAL hWnd  AS DWORD _  ' control handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnKillFocus
' PURPOSE:   Page2 WM_KILLFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnKillFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndNewFocus   AS DWORD _  ' handle of window receiving focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnSetFocus
' PURPOSE:   Page2 WM_SETFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnSetFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndOldFocus   AS DWORD _  ' handle of window losing focus
   ) AS LONG

   LOCAL hStatusbar AS DWORD
   LOCAL szText     AS ASCIIZ * %MAX_PATH

   hStatusbar = GetDlgItem(GetParent(hWnd), %IDC_DIALOG1_STATUSBAR1)
   szText = "Double click the wanted item to retrieve information"
   SendMessage hStatusbar, %SB_SETTEXT, 3, BYVAL VARPTR(szText)

   ' Post a message to set the focus in the TreeView
   ' See note in Dialog1_OnMySetFocusMessage
   PostMessage GetParent(hWnd), %MYSETFOCUSMESSAGE, GetDlgItem(hWnd, %IDC_DIALOG1_TREEVIEW1), 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnCreate
' PURPOSE:   Page3 WM_CREATE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnCreate _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lptcs       AS DWORD, _ ' address of CREATESTRUCT structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnDestroy
' PURPOSE:   Page3 WM_DESTROY message handler.
'
'-------------------------------------------------------------------------------

SUB Dialog1_Code_OnDestroy _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
         lMsgResult  AS LONG _   ' value returned to message
   )

END SUB

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnSize
' PURPOSE:   Page3 WM_SIZE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnSize _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL lState   AS LONG, _  ' resizing state
   BYVAL cxClient AS LONG, _  ' width of client area
   BYVAL cyClient AS LONG _   ' height of client area
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnPaint
' PURPOSE:   Page3 WM_PAINT message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnPaint _
   ( _
   BYVAL hWnd  AS DWORD _  ' control handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnKillFocus
' PURPOSE:   Page3 WM_KILLFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnKillFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndNewFocus   AS DWORD _  ' handle of window receiving focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnSetFocus
' PURPOSE:   Page3 WM_SETFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnSetFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndOldFocus   AS DWORD _  ' handle of window losing focus
   ) AS LONG

   LOCAL hStatusbar AS DWORD
   LOCAL szText     AS ASCIIZ * %MAX_PATH

   hStatusbar = GetDlgItem(GetParent(hWnd), %IDC_DIALOG1_STATUSBAR1)
   szText = "Ctrl+A = Select all | Ctrl+C = Copy to clipboard | Ctrl+V = Copy from clipboard"
   SendMessage hStatusbar, %SB_SETTEXT, 3, BYVAL VARPTR(szText)

   ' Post a message to set the focus in the ListView
   ' See note in Dialog1_OnMySetFocusMessage
   PostMessage GetParent(hWnd), %MYSETFOCUSMESSAGE, GetDlgItem(hWnd, %IDC_DIALOG1_RICHEDIT_VIEWCODE), 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnEraseBkgnd
' PURPOSE:   Dialog1 WM_ERASEBKGND message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnEraseBkgnd _
   ( _
   BYVAL hWnd  AS DWORD, _ ' window handle
   BYVAL hDC   AS DWORD _  ' handle of device context
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_OnNotify
' PURPOSE:   Page1 WM_NOTIFY message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_OnNotify _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' control identifier
   BYVAL lptnmhdr    AS DWORD, _ ' address of NMHDR structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_ListView1_ColumnClick
' PURPOSE:   ListView1 LVN_COLUMNCLICK notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_ListView1_ColumnClick _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

   LOCAL ptnmlvi    AS NMLISTVIEW PTR
   LOCAL hListView  AS DWORD

   ptnmlvi = ptnmhdr
   m_ColumnToSort = @ptnmlvi.iSubItem

   ' Retrieves the ListView window handle
   hListView = GetDlgItem(hWndParent, %IDC_DIALOG1_LISTVIEW1)
   IF hListView = %NULL THEN EXIT FUNCTION

   ' Disables redraw to minimize flicker
   SendMessage hListView, %WM_SETREDRAW, %FALSE, 0

   ' Sorts items by the clicked column
   TLB_ListviewSortItems hListView

   ' Enables redraw and repaints the control
   SendMessage hListView, %WM_SETREDRAW, %TRUE, 0
   InvalidateRect hListView, BYVAL %NULL, %TRUE
   UpdateWindow hListView

   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_ListView1_ItemChanged
' PURPOSE:   ListView1 LVN_ITEMCHANGED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_ListView1_ItemChanged _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnCommand
' PURPOSE:   Page2 WM_COMMAND message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnCommand _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' identifier of menu item, control, or accelerator
   BYVAL hWndCtrl    AS DWORD, _ ' handle of control
   BYVAL lNotifyCode AS LONG _   ' notification code
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_OnNotify
' PURPOSE:   Page2 WM_NOTIFY message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_OnNotify _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' control identifier
   BYVAL lptnmhdr    AS DWORD, _ ' address of NMHDR structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

   LOCAL ptnmhdr      AS NMHDR PTR
   LOCAL hTreeView    AS DWORD
   LOCAL hItem        AS DWORD
   LOCAL hParent      AS DWORD
   LOCAL szItemName   AS ASCIIZ * %MAX_PATH
   LOCAL szParentName AS ASCIIZ * %MAX_PATH

   IF lCtrlId = %IDC_DIALOG1_TREEVIEW1 THEN
      ptnmhdr = lptnmhdr
      IF @ptnmhdr.code = %NM_DBLCLK THEN
         ' Retrieves the selected item
         hTreeView = GetDlgItem(hWnd, lCtrlId)
         hItem = TreeView_GetSelection(hTreeView)
         szItemName = TV_GetItemText(hTreeView, hItem)
         ' Retrieves the name of the parent node
         hParent = TreeView_GetParent(hTreeView, hItem)
         IF hParent THEN szParentName = TV_GetItemText(hTreeView, hParent)
         m_ItemName = szItemName
         SELECT CASE szParentName
            CASE "CoClasses" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_COCLASSES, 0)
            CASE "Enumerations" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_CONSTANTS, %REPORT_VIEWONLY)
            CASE "Modules" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_MODULES, %REPORT_VIEWONLY)
            CASE "Interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Oleautomation interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Dual interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Dispatch interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Dispatchable interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Hidden interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Restricted interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Events interfaces" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_INTERFACES, %REPORT_VIEWONLY)
            CASE "Structures" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_RECORDS, %REPORT_VIEWONLY)
            CASE "Unions" : PostMessage(GetParent(hWnd), %MYENUMMESSAGE, %ENUM_RECORDS, %REPORT_VIEWONLY)
         END SELECT
      END IF
   END IF

   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_TreeView1_SelChanged
' PURPOSE:   TreeView1 TVN_SELCHANGED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_TreeView1_SelChanged _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_TreeView2_SelChanged
' PURPOSE:   TreeView2 TVN_SELCHANGED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_TreeView2_SelChanged _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnCommand
' PURPOSE:   Page3 WM_COMMAND message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnCommand _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' identifier of menu item, control, or accelerator
   BYVAL hWndCtrl    AS DWORD, _ ' handle of control
   BYVAL lNotifyCode AS LONG _   ' notification code
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_OnNotify
' PURPOSE:   Page3 WM_NOTIFY message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_OnNotify _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' control identifier
   BYVAL lptnmhdr    AS DWORD, _ ' address of NMHDR structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_RichEdit_ViewCode_Change
' PURPOSE:   RichEdit1 EN_CHANGE notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_RichEdit_ViewCode_Change _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Toolbar1_Interfaces
' PURPOSE:   Toolbar1 IDM_INTERFACES notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Toolbar1_Interfaces _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   ' Retrieves the license key
   IF ISTRUE m_RetrieveLicenseKey AND TLB_StrLicKey = "" THEN
      IF UBOUND(TLB_ProgIDsArray) > -1 THEN
         TLB_StrLicKey = TLB_GetRuntimeLicenseKey(TLB_ProgIDsArray(LBOUND(TLB_ProgIDsArray)))
      END IF
   END IF

   ' Enumerate all
   m_ItemName  = ""
   TLB_Enumerate(hWnd, m_ItemName, %ENUM_ALL, %REPORT_VIEWCODE)
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Toolbar1_Events
' PURPOSE:   Toolbar1 IDM_EVENTS notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Toolbar1_Events _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   TLB_MakeEventFunctions hWnd, %TRUE
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Toolbar1_Stop
' PURPOSE:   Toolbar1 IDM_STOP notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Toolbar1_Stop _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   m_Abort = %TRUE
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Toolbar_Help
' PURPOSE:   Toolbar IDM_TOOLBAR_HELP notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Toolbar_Help _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   ' Displays the library help file, if any
   LOCAL p AS LONG
   LOCAL szName AS ASCIIZ * %MAX_PATH

   ' Get the name of the help file and let HtmlHelp to find it
   ' (the path in the type library is usually wrong)
   szName = TLB_LibDoc.szHelpFile
   p = INSTR(-1, szName, "\")
   IF p THEN szName = MID$(szName, p + 1)

   IF LEN(szName) THEN
      IF RIGHT$(UCASE$(szName), 4) = ".HLP" THEN
         WinHelp hWnd, TLB_LibDoc.szHelpFile, %HELP_CONTENTS, %NULL
      ELSEIF RIGHT$(UCASE$(szName), 4) = ".CHM" THEN
         HtmlHelp hWnd, szName, %HH_DISPLAY_TOC, %NULL
      END IF
   END IF

END FUNCTION

'-------------------------------------------------------------------------------

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnCreate
' PURPOSE:   Preferences WM_CREATE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnCreate _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lptcs       AS DWORD, _ ' address of CREATESTRUCT structure
         lMsgResult  AS LONG _   ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnDestroy
' PURPOSE:   Preferences WM_DESTROY message handler.
'
'-------------------------------------------------------------------------------

SUB Dialog1_Options_OnDestroy _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
         lMsgResult  AS LONG _   ' value returned to message
   )

END SUB

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnSize
' PURPOSE:   Preferences WM_SIZE message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnSize _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL lState   AS LONG, _  ' resizing state
   BYVAL cxClient AS LONG, _  ' width of client area
   BYVAL cyClient AS LONG _   ' height of client area
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnPaint
' PURPOSE:   Preferences WM_PAINT message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnPaint _
   ( _
   BYVAL hWnd  AS DWORD _  ' control handle
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnKillFocus
' PURPOSE:   Preferences WM_KILLFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnKillFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndNewFocus   AS DWORD _  ' handle of window receiving focus
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnSetFocus
' PURPOSE:   Preferences WM_SETFOCUS message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnSetFocus _
   ( _
   BYVAL hWnd           AS DWORD, _ ' control handle
   BYVAL hWndOldFocus   AS DWORD _  ' handle of window losing focus
   ) AS LONG

   LOCAL hStatusbar AS DWORD
   LOCAL szText     AS ASCIIZ * %MAX_PATH

   hStatusbar = GetDlgItem(GetParent(hWnd), %IDC_DIALOG1_STATUSBAR1)
   szText = "Check the wanted options using the mouse or the space bar"
   SendMessage hStatusbar, %SB_SETTEXT, 3, BYVAL VARPTR(szText)

   ' Post a message to set the focus
   ' See note in Dialog1_OnMySetFocusMessage
   PostMessage GetParent(hWnd), %MYSETFOCUSMESSAGE, GetDlgItem(hWnd, %IDC_DIALOG1_CHECK_USEPROPGETSET), 0

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_OnCommand
' PURPOSE:   Preferences WM_COMMAND message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_OnCommand _
   ( _
   BYVAL hWnd        AS DWORD, _ ' control handle
   BYVAL lCtrlId     AS LONG, _  ' identifier of menu item, control, or accelerator
   BYVAL hWndCtrl    AS DWORD, _ ' handle of control
   BYVAL lNotifyCode AS LONG _   ' notification code
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseMethod_Clicked
' PURPOSE:   Check1 BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseMethod_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseMethod = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)
   IF ISTRUE m_UseMethod THEN
      SendMessage GetDlgItem(hWndParent, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_SETCHECK, %BST_UNCHECKED, 0
      m_UsePropGetSet = SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_GETCHECK, 0, 0)
   END IF

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UsePropGetSet_Clicked
' PURPOSE:   Check_UsePropGetSet BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UsePropGetSet_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UsePropGetSet = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)
   IF ISTRUE m_UseMethod THEN
      SendMessage GetDlgItem(hWndParent, %IDC_DIALOG1_CHECK_USEMETHOD), %BM_SETCHECK, %BST_UNCHECKED, 0
      m_UseMethod = SendMessage(GetDlgItem(hWndParent, %IDC_DIALOG1_CHECK_USEMETHOD), %BM_GETCHECK, 0, 0)
   END IF

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UsePrefix_Clicked
' PURPOSE:   Check2 BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UsePrefix_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UsePrefix = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseEnumPrefix_Clicked
' PURPOSE:   Check3 BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseEnumPrefix_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseEnumPrefix = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseHexNumbers_Clicked
' PURPOSE:   Check_UseHexNumbers BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseHexNumbers_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseHexNumbers = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseSetPrefix_Clicked
' PURPOSE:   Check_UseSetPrefix BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseSetPrefix_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseSetPrefix = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseParameterNames_Clicked
' PURPOSE:   Check_UseParameterNames BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseParameterNames_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseParameterNames = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_AddParameterNamesPrefix_Clicked
' PURPOSE:   Check_AddParameterNamesPrefix BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_AddParameterNamesPrefix_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_AddParameterNamesPrefix = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseInterfaceNamesWithExternalObjects_Clicked
' PURPOSE:   Check_UseInterfaceNamesWithExternalObjects BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseInterfaceNamesWithExternalObjects_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseIntNamesWithExObj = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_MixDispInterfaces_Clicked
' PURPOSE:   Check_MixDispInterfaces BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_MixDispInterfaces_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_MixDispInterfaces = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_RetrieveLicenseKey_Clicked
' PURPOSE:   Check_RetrieveLicenseKey BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_RetrieveLicenseKey_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_RetrieveLicenseKey = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Check_UseAutomationView_Clicked
' PURPOSE:   Check_UseAutomationView BN_CLICKED notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Check_UseAutomationView_Clicked _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

   m_UseAutomationView = SendMessage(hWndCtrl, %BM_GETCHECK, 0, 0)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_EditPrefix_Change
' PURPOSE:   EditPrefix EN_CHANGE notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_EditPrefix_Change _
   ( _
   BYVAL hWndParent  AS DWORD, _ ' handle of parent window
   BYVAL hWndCtrl    AS DWORD _  ' handle of control
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_ListView1_Click
' PURPOSE:   ListView1 NM_CLICK notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_ListView1_Click _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_ListView1_DblClk
' PURPOSE:   ListView1 NM_DBLCLK notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_ListView1_DblClk _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG

   LOCAL hListView  AS DWORD
   LOCAL tlvi       AS LVITEM
   LOCAL iItem      AS LONG
   LOCAL szPath     AS ASCIIZ * %MAX_PATH
   LOCAL szDesc     AS ASCIIZ * %MAX_PATH
   LOCAL p          AS LONG

   m_SelDesc = ""
   m_selPath = ""

   ' Retrieves the path of the selected item
   hListView = @ptnmhdr.hwndFrom
   iItem = ListView_GetSelectionMark(hListView)

   tlvi.mask = %LVIF_TEXT
   tlvi.cchTextMax = %MAX_PATH
   tlvi.iItem = iItem
   tlvi.pszText = VARPTR(szDesc)
   tlvi.iSubItem = 0
   IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
      m_SelDesc = szDesc
      p = INSTR(-1, m_SelDesc, " (Ver ")
      IF p THEN m_SelDesc = LEFT$(m_SelDesc, p - 1)
   END IF

   tlvi.mask = %LVIF_TEXT
   tlvi.cchTextMax = %MAX_PATH
   tlvi.iItem = iItem
   tlvi.pszText = VARPTR(szPath)
   tlvi.iSubItem = 2
   IF SendMessage(hListView, %LVM_GETITEM, 0, VARPTR(tlvi)) = %TRUE THEN
      m_SelPath = szPath
      ' Retrieves information about the typelib
      TLB_Enumerator GetParent(hWndParent), szPath
   END IF

   lMsgResult = %FALSE
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_FileReload
' PURPOSE:   MainMenu IDM_RELOAD notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_FileReload _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   LOCAL hGridTab   AS DWORD
   LOCAL hListView  AS DWORD
   LOCAL hStatusbar AS DWORD
   LOCAL nCount     AS LONG
   LOCAL szText     AS ASCIIZ * %MAX_PATH

   ' Retrieves the handle of the grid tab
   hGridTab = GetDlgItem(hWnd, %IDC_DIALOG1_GRID)
   IF hGridTab = %NULL THEN EXIT FUNCTION

   ' Retrieves the ListView window handle
   hListView = GetDlgItem(hGridTab, %IDC_DIALOG1_LISTVIEW1)
   IF hListView = %NULL THEN EXIT FUNCTION

   ' Disables redraw to minimize flicker
   SendMessage hListView, %WM_SETREDRAW, %FALSE, 0

   ' Deletes all the items of the ListView
   nCount = SendMessage(hListView, %LVM_GETITEMCOUNT, 0, 0)
   IF nCount THEN SendMessage(hListView, %LVM_DELETEALLITEMS, 0, 0)

   ' Enumerates all the typelibs
   TLB_RegEnumTypeLibs hListView

   ' Sorts items
   IF m_SortOrder = "ASCEND" THEN m_SortOrder = "DESCEND" ELSE m_SortOrder = "ASCEND"
   TLB_ListviewSortItems hListView

   ' Enables redraw and repaints the control
   SendMessage hListView, %WM_SETREDRAW, %TRUE, 0
   InvalidateRect hListView, BYVAL %NULL, %TRUE
   UpdateWindow hListView

   ' Retrieves the Statusbar window handle
   hStatusbar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)

   ' Display the number of typelibs found
   nCount = SendMessage(hListView, %LVM_GETITEMCOUNT, 0, 0)
   IF hStatusbar THEN
      szText = FORMAT$(nCount) & " TypeLibs"
      SendMessage hStatusbar, %SB_SETTEXT, 0, BYVAL VARPTR(szText)
      szText = "Double click the wanted item to retrieve information"
      SendMessage hStatusbar, %SB_SETTEXT, 3, BYVAL VARPTR(szText)
   END IF

   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnMyCreateMessage
' PURPOSE:   Dialog1 MYMESSAGE message handler.
' RETURN:    Any meaningful value.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnMyCreateMessage _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL hOptionsTab    AS DWORD
   LOCAL strIniFilePath AS STRING
   LOCAL hMenu          AS DWORD
   LOCAL hSubMenu       AS DWORD

   strIniFilePath = TLB_ExePath & $IniFile

   ' Retrieves the handle of the options tab
   hOptionsTab = GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS)
   ' Reads the .ini file to set the saved state of the options
   IF hOptionsTab THEN
      m_UseMethod = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseMethpd", ""))
      IF m_UseMethod = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEMETHOD), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEMETHOD), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UsePrefix = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UsePrefix", ""))
      IF m_UsePrefix = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPREFIX), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPREFIX), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseEnumPrefix = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseEnumPrefix", ""))
      IF m_UseEnumPrefix = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEENUMPREFIX), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEENUMPREFIX), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseHexNumbers = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseHexNumbers", ""))
      IF m_UseHexNumbers = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEHEXNUMBERS), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEHEXNUMBERS), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UsePropGetSet = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UsePropGetSet", ""))
      IF m_UsePropGetSet = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      ' Set default to m_UsePropGetSet if option not set
      IF m_UseMethod <> %BST_CHECKED AND m_UsePropGetSet <> %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_SETCHECK, %BST_CHECKED, 0
         m_UsePropGetSet = SendMessage(GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPROPGETSET), %BM_GETCHECK, 0, 0)
      END IF
      m_MixDispInterfaces = VAL(TLB_IniRead(strIniFilePath, "Browser options", "MixDispInterfaces", ""))
      IF m_MixDispInterfaces = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_MIXDISPINTERFACES), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_MIXDISPINTERFACES), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_RetrieveLicenseKey = VAL(TLB_IniRead(strIniFilePath, "Browser options", "RetrieveLicenseKey", ""))
      IF m_RetrieveLicenseKey = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_RETRIEVELICENSEKEY), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_RETRIEVELICENSEKEY), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseAutomationView = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseAutomationView", ""))
      IF m_UseAutomationView = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEAUTOMATIONVIEW), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEAUTOMATIONVIEW), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseSetPrefix = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseSetPrefix", ""))
      IF m_UseSetPrefix = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USESETPREFIX), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USESETPREFIX), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseIntNamesWithExObj = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseIntNamesWithExObj", ""))
      IF m_UseIntNamesWithExObj = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEINTNAMESWITHEXOBJ), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEINTNAMESWITHEXOBJ), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      m_UseParameterNames = VAL(TLB_IniRead(strIniFilePath, "Browser options", "UseParameterNames", ""))
      IF m_UseParameterNames = %BST_CHECKED THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPRMNAMES), %BM_SETCHECK, %BST_CHECKED, 0
      ELSE
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_USEPRMNAMES), %BM_SETCHECK, %BST_UNCHECKED, 0
      END IF
      ' Set default to m_UseAddParameterNamesPrefix if required
      IF TLB_IniRead(strIniFilePath, "Browser options", "AddParameterNamesPrefix", "") = "" THEN
         SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX), %BM_SETCHECK, %BST_CHECKED, 0
         m_AddParameterNamesPrefix = SendMessage(GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX), %BM_GETCHECK, 0, 0)
      ELSE
         m_AddParameterNamesPrefix = VAL(TLB_IniRead(strIniFilePath, "Browser options", "AddParameterNamesPrefix", ""))
         IF m_AddParameterNamesPrefix = %BST_CHECKED THEN
            SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX), %BM_SETCHECK, %BST_CHECKED, 0
         ELSE
            SendMessage GetDlgItem(hOptionsTab, %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX), %BM_SETCHECK, %BST_UNCHECKED, 0
         END IF
      END IF
   END IF

   m_LastPath = TLB_IniRead(strIniFilePath, "Browser paths", "LastAccessedFolder", "")
   m_ColumnToSort = VAL(TLB_IniRead(strIniFilePath, "Browser options", "ColumnToSort", ""))
   m_SortOrder = TLB_IniRead(strIniFilePath, "Browser options", "SortOrder", "")
   IF TRIM$(m_SortOrder) = "" THEN m_SortOrder = "DESCEND"
   m_PrevColSort = m_ColumnToSort

   ' Disable non-available menus
   hMenu = GetMenu(hWnd)
   hSubMenu = GetSubMenu(hMenu, 0)
   CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
   CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_GRAYED
   CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED
   DrawMenuBar hWnd

   ' Load the typelibs
   Dialog1_MainMenu_FileReload hWnd
   FUNCTION = %S_OK

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Toolbar1_DropDown
' PURPOSE:   Toolbar1 TBN_DROPDOWN notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Toolbar1_DropDown _
   ( _
   BYVAL hWndParent  AS DWORD, _       ' handle of parent window
   BYVAL ptnmhdr     AS NMHDR PTR, _   ' message information
         lMsgResult  AS LONG _         ' value returned to message
   ) AS LONG


   LOCAL tbn      AS TBNOTIFY PTR      ' for toolbar notification messages
   LOCAL rc       AS RECT              ' bounding rectangle for a specified toolbar button
   LOCAL hMenu    AS DWORD             ' menu handle
   LOCAL hSubMenu AS DWORD             ' submenu handle

   tbn = ptnmhdr
   SELECT CASE @tbn.iItem
      CASE %IDM_CODE
         ' Show the Interfaces menu below the toolbar button
         hMenu = GetMenu(hWndParent)
         hSubMenu = GetSubMenu(hMenu, 1)
         SendMessage(@tbn.hdr.hwndFrom, %TB_GETRECT, @tbn.iItem, VARPTR(rc))
         MapWindowPoints(@tbn.hdr.hwndFrom, %HWND_DESKTOP, BYVAL VARPTR(rc), 2)
         TrackPopupMenu(hSubMenu, 0, rc.nLeft, rc.nBottom, 0, hWndParent, BYVAL %NULL)
   END SELECT

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnMySetFocusMessage
' PURPOSE:   Dialog1 MYSETFOCUSMESSAGE message handler.
' RETURN:    Any meaningful value.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnMySetFocusMessage _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL hWndCtrl AS DWORD, _ ' The handle of the control
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   ' Note: To be able to set the focus in the first control of a page
   ' in the tab control we need to set the focus in the page and then,
   ' in the OnSetFocus event of the page, we need to post a %MYSETFOCUSMESSAGE
   ' custom message with the handle of the control that we want to gain
   ' the focus. This is needed to ensure that this message is the last
   ' one processed and that no other control steals the focus.

   SetFocus hWndCtrl
   FUNCTION = %S_OK

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_OnMyEnumMessage
' PURPOSE:   Dialog1 MYENUMMESSAGE message handler.
' RETURN:    Any meaningful value.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_OnMyEnumMessage _
   ( _
   BYVAL hWnd        AS DWORD, _ ' window handle
   BYVAL nEnumType   AS DWORD, _ ' Enumeration type
   BYVAL nReportType AS LONG _   ' Report type
   ) AS LONG

   SELECT CASE nEnumType
      CASE %ENUM_COCLASSES
         TLB_EnumCoClasses(hWnd, m_ItemName)
      CASE %ENUM_CONSTANTS, %ENUM_MODULES, %ENUM_RECORDS, %ENUM_INTERFACES
         TLB_Enumerate(hWnd, m_ItemName, nEnumType, nReportType)
   END SELECT
   FUNCTION = %S_OK

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_CodeIdentifiers
' PURPOSE:   MainMenu IDM_IDENTIFIERS notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_CodeIdentifiers _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   LOCAL hPageCtrl      AS DWORD                ' // Handle of the page of the Tab control
   LOCAL hRichEditBox   AS DWORD                ' // Handle of the rich edit box
   LOCAL hMenu          AS DWORD                ' // Menu handle
   LOCAL hSubMenu       AS DWORD                ' // Submenu handle
   LOCAL szText         AS ASCIIZ * 255         ' // General purpose variable

   IF hWnd = %NULL THEN EXIT FUNCTION
   hPageCtrl = GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
   IF hPageCtrl = %NULL THEN EXIT FUNCTION

   m_Buffer = ""
   m_BufLen = 0
   TLB_LibraryHeader
   TLB_EnumIdentifiers hWnd

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
   SetFocus(GetDlgItem(hWnd, %IDC_DIALOG1_CODE))

   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_RELOAD, MAKLNG(%FALSE, 0))
'   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_CODE, MAKLNG(%FALSE, 0))
'   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_EVENTS, MAKLNG(%FALSE, 0))
   SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_ENABLEBUTTON, %IDM_SAVE, MAKLNG(%TRUE, 0))
   hMenu = GetMenu(hWnd)
   hSubmenu = GetSubMenu(hMenu, 0)
   CoolMenu_EnableMenuItem hSubMenu, %IDM_RELOAD, %MF_GRAYED
   CoolMenu_EnableMenuItem hSubMenu, %IDM_SAVE, %MF_ENABLED
'   CoolMenu_EnableMenuItem hMenu, 1, %MF_BYPOSITION OR %MF_GRAYED

   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_CodeEnumerations
' PURPOSE:   MainMenu IDM_ENUMERATIONS notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_CodeEnumerations _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   m_ItemName = ""
   TLB_Enumerate(hWnd, m_ItemName, %ENUM_CONSTANTS, %REPORT_VIEWCODE)
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_CodeModules
' PURPOSE:   MainMenu IDM_MODULES notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_CodeModules _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   m_ItemName = ""
   TLB_Enumerate(hWnd, m_ItemName, %ENUM_MODULES, %REPORT_VIEWCODE)
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_MainMenu_CodeStructures
' PURPOSE:   MainMenu IDM_RECORDS notification handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_MainMenu_CodeStructures _
   ( _
   BYVAL hWnd  AS DWORD _  ' handle of window that owns the menu
   ) AS LONG

   m_ItemName = ""
   TLB_Enumerate(hWnd, m_ItemName, %ENUM_RECORDS, %REPORT_VIEWCODE)
   FUNCTION = %TRUE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_RichEdit_ViewCode_OnKeyDown
' PURPOSE:   RichEdit_ViewCode WM_KEYDOWN message handler.
' RETURN:    TRUE if message was processed, FALSE if it was not.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_RichEdit_ViewCode_OnKeyDown _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL lVirtKey AS LONG, _  ' virtual key code
   BYVAL lKeyData AS LONG _   ' key data
   ) AS LONG

   IF lVirtKey = %VK_ESCAPE THEN
      FUNCTION = %TRUE
   END IF

END FUNCTION
