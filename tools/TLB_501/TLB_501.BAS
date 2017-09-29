'###############################################################################
' TLB_501.BAS - TypeLib Browser v. 5.0 Build 1
' (C) 2011 by José Roca. All rights reserved.
'###############################################################################

' SED_PBWIN   ' Use the PBWIN compiler
#DIM ALL
#COMPILE EXE

' // Workaround for XP SP3, that GPFs if nCount is negative.
FUNCTION AfxSpaces (BYVAL nCount AS LONG) AS STRING
   IF nCount > 0 THEN FUNCTION = SPACE$(nCount)
END FUNCTION

#INCLUDE "OCIDL.INC"
#INCLUDE "COMMCTRL.INC"
#INCLUDE "RICHEDIT.INC"
#INCLUDE "HTMLHELP.INC"
#INCLUDE "TLB_UTILS.INC"
#INCLUDE "TLB_501.PBH"
#INCLUDE "TLB_DIALOG.INC"
' Wrappers
#INCLUDE "EditCtrl.inc"
#INCLUDE "TreeViewCtrl.inc"
#INCLUDE "ListViewCtrl.inc"
' Resource file
#RESOURCE RES, "TLB_501.RES"

'-------------------------------------------------------------------------------
'
' PROCEDURE: WinMain
' PURPOSE:   Program entry point, calls initialization function, processes
'            message loop.
'
'-------------------------------------------------------------------------------

FUNCTION WinMain _
   ( _
   BYVAL hInstance      AS DWORD, _       ' handle of current instance
   BYVAL hPrevInstance  AS DWORD, _       ' handle of previous instance(not used in Win32)
   BYVAL pszCmdLine     AS ASCIIZ PTR, _  ' address of command line
   BYVAL nCmdShow       AS LONG _         ' show state of window
   ) AS LONG

   LOCAL tmsg              AS tagMsg                     ' message information
   LOCAL ticc              AS INIT_COMMON_CONTROLSEX     ' specifies common control classes to register
   LOCAL rXFactor          AS SINGLE                     ' horizontal scaling factor
   LOCAL rYFactor          AS SINGLE                     ' vertical scaling factor
   LOCAL hLibRichEd        AS DWORD                      ' handle to rich edit DLL
   LOCAL hWnd              AS DWORD                      ' handle of main window
   LOCAL hWndModeless      AS DWORD                      ' handle of the current active window
   LOCAL hAccel            AS DWORD                      ' handle of accelerator table

   ' Save the handle of the application instance
   ghInstance = hInstance

   ' Load the common controls library and
   ' specify the classes to register.
   ticc.dwSize = SIZEOF(ticc)
   ticc.dwICC  = %ICC_LISTVIEW_CLASSES OR %ICC_TREEVIEW_CLASSES OR %ICC_BAR_CLASSES OR _
                 %ICC_TAB_CLASSES
   InitCommonControlsEx ticc

   ' Load the rich edit DLL
   hLibRichEd = phnxLoadRichEdit("")

   ' Register custom messages
   gdwADM_ALIGNCONTROLS = RegisterWindowMessage("ADM_ALIGNCONTROLS")
   gdwADM_LAYOUT        = RegisterWindowMessage("ADM_LAYOUT")

   ' Register window classes
   IF ISTRUE TLB_400_RegisterClasses() THEN
      ' Unload the rich edit DLL
      IF ISTRUE hLibRichEd THEN FreeLibrary hLibRichEd
      FUNCTION = %FALSE
      EXIT FUNCTION
   END IF

   ' Load the accelerator table.
   ' An accelerator table that is loaded from a resource
   ' is freed automatically when the program terminates.
   hAccel = LoadAccelerators(ghInstance, BYVAL %IDR_DIALOG1_MAINMENU)

   ' Get the ratios between the design and current screen resolutions
   phnxGetResolutionRatios rXFactor, rYFactor

   ' Create the Dialog1 window
'   hWnd = CreateWindowEx(%WS_EX_WINDOWEDGE, _                                          ' extended styles
'                         "TLB_400_CLASS", _                                            ' class name
'                         $cCaption, _                                                  ' caption
'                         %WS_OVERLAPPEDWINDOW OR %WS_VISIBLE, _                        ' window styles
'                         156 * rXFactor, 273 * rYFactor, _                             ' left, top
'                         800 * rXFactor, 566 * rYFactor, _                             ' width, height
'                         %NULL, %NULL, _                                               ' handle of owner, menu handle
'                         ghInstance, BYVAL %NULL)                                      ' handle of instance, creation parameters

   LOCAL rc          AS RECT
   LOCAL nLeft       AS LONG
   LOCAL nTop        AS LONG
   LOCAL nWidth      AS LONG
   LOCAL nHeight     AS LONG

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, BYVAL VARPTR(rc), 0

'   nWidth  = 800 * rXFactor
'   nHeight = 566 * rYFactor
   nWidth  = (rc.nRight - rc.nLeft) * rXFactor
   nHeight = (rc.nBottom - rc.nTop) * rYFactor
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

'   hWnd = CreateWindowEx(%WS_EX_WINDOWEDGE, _                                          ' extended styles
'                         "TLB_400_CLASS", _                                            ' class name
'                         $cCaption, _                                                  ' caption
'                         %WS_OVERLAPPEDWINDOW OR %WS_VISIBLE, _                        ' window styles
'                         nLeft * rXFactor, nTop * rYFactor, _                             ' left, top
'                         800 * rXFactor, 566 * rYFactor, _                             ' width, height
'                         %NULL, %NULL, _                                               ' handle of owner, menu handle
'                         ghInstance, BYVAL %NULL)                                      ' handle of instance, creation parameters

   hWnd = CreateWindowEx(%WS_EX_WINDOWEDGE, _                                          ' extended styles
                         "TLB_400_CLASS", _                                            ' class name
                         $cCaption, _                                                  ' caption
                         %WS_OVERLAPPEDWINDOW OR %WS_VISIBLE, _                        ' window styles
                         nLeft * rXFactor, nTop * rYFactor, _                          ' left, top
                         nWidth, nHeight, _                                            ' width, height
                         %NULL, %NULL, _                                               ' handle of owner, menu handle
                         ghInstance, BYVAL %NULL)                                      ' handle of instance, creation parameters

   ' If window could not be created, return "failure"
   IF ISFALSE hWnd THEN
      ' Unload the rich edit DLL
      IF ISTRUE hLibRichEd THEN FreeLibrary hLibRichEd
      FUNCTION = %FALSE
      EXIT FUNCTION
   END IF

   ' Adjust the size of the window so that it conforms
   ' to the specified size of the client area
'   phnxAdjustWindowRect hWnd, 792 * rXFactor, 516 * rYFactor

   ' Initialize this instance of the window
   IF ISTRUE Dialog1_InitWindow(hWnd, BYVAL pszCmdLine) THEN
      SendMessage hWnd, %WM_CLOSE, 0, 0
      ' Unload the rich edit DLL
      IF ISTRUE hLibRichEd THEN FreeLibrary hLibRichEd
      FUNCTION = %FALSE
      EXIT FUNCTION
   END IF

   ' Center the window relative to the screen
   phnxCenterWindow hWnd, %NULL
   ' Make the window visible; update its client area
   ShowWindow hWnd, nCmdShow
   UpdateWindow hWnd

   ' Main message loop of program.
   ' Acquire and dispatch messages until a WM_QUIT message is received.
   WHILE ISTRUE GetMessage(tmsg, BYVAL %NULL, 0, 0)
      IF ISFALSE TranslateAccelerator(hWnd, hAccel, tmsg) THEN
         IF ISFALSE Dialog1_TranslateMessage(hWnd, tmsg) THEN
            hWndModeless = phnxGetFormHandle(GetFocus())
            IF (ISFALSE hWndModeless) OR (ISFALSE IsDialogMessage(hWndModeless, tmsg)) THEN
               TranslateMessage tmsg
               DispatchMessage tmsg
            END IF
         END IF
      END IF
   WEND

   ' Unload the rich edit DLL
   IF ISTRUE hLibRichEd THEN FreeLibrary hLibRichEd

   FUNCTION = tmsg.wParam

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: TLB_400_RegisterClasses
' PURPOSE:   Registers the window classes that are used in the program.
' RETURNS:   FALSE if successful, TRUE if registration failed.
'
'-------------------------------------------------------------------------------

FUNCTION TLB_400_RegisterClasses () AS LONG

   LOCAL szClassName    AS ASCIIZ * %MAX_PATH      ' class name
   LOCAL twcx           AS WNDCLASSEX              ' class information
   LOCAL cxIcon         AS LONG                    ' width of a small icon in pixels
   LOCAL cyIcon         AS LONG                    ' height of a small icon in pixels

   ' Width and height of a small icon
   cxIcon = GetSystemMetrics(%SM_CXSMICON)
   cyIcon = GetSystemMetrics(%SM_CYSMICON)

   ' Register the window classes that belong to the Dialog1 window
   ' -------------------------------------------------------------

   ' Register the Dialog1 window
   szClassName        = "TLB_400_CLASS"
   twcx.cbSize        = SIZEOF(twcx)                                                                                 ' size of WNDCLASSEX structure
   twcx.style         = %CS_BYTEALIGNWINDOW OR %CS_DBLCLKS                                                           ' class styles
   twcx.lpfnWndProc   = CODEPTR(Dialog1_WndProc)                                                                     ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                                                                            ' extra class bytes
   twcx.cbWndExtra    = 4                                                                                            ' extra window bytes
   twcx.hInstance     = ghInstance                                                                                   ' instance of the process that is registering the window
   twcx.hIcon         = LoadIcon(ghInstance, BYVAL %IDI_TLB_LOGO_32)                                                 ' handle of class icon
   twcx.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)                                                          ' handle of class cursor
   twcx.hbrBackground = %COLOR_BTNFACE + 1                                                                           ' brush used to fill background of window's client area
   twcx.lpszMenuName  = %IDR_DIALOG1_MAINMENU                                                                        ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                                                                          ' class name
   twcx.hIconSm       = LoadImage(ghInstance, BYVAL %IDI_TLB_LOGO_16, %IMAGE_ICON, cxIcon, cyIcon, %LR_DEFAULTCOLOR) ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Register the Grid window
   szClassName        = "TLB_400_GRID_CLASS"
   twcx.cbSize        = SIZEOF(twcx)                              ' size of WNDCLASSEX structure
   twcx.style         = %CS_DBLCLKS                               ' class styles
   twcx.lpfnWndProc   = CODEPTR(Dialog1_Grid_WndProc)             ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                         ' extra class bytes
   twcx.cbWndExtra    = 0                                         ' extra window bytes
   twcx.hInstance     = ghInstance                                ' instance of the process that is registering the window
   twcx.hIcon         = %NULL                                     ' handle of class icon
   twcx.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)       ' handle of class cursor
   twcx.hbrBackground = %COLOR_BTNFACE + 1                        ' brush used to fill background of window's client area
   twcx.lpszMenuName  = %NULL                                     ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                       ' class name
   twcx.hIconSm       = %NULL                                     ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Register the Trees window
   szClassName        = "TLB_400_TREES_CLASS"
   twcx.cbSize        = SIZEOF(twcx)                              ' size of WNDCLASSEX structure
   twcx.style         = %CS_DBLCLKS                               ' class styles
   twcx.lpfnWndProc   = CODEPTR(Dialog1_Trees_WndProc)            ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                         ' extra class bytes
   twcx.cbWndExtra    = 0                                         ' extra window bytes
   twcx.hInstance     = ghInstance                                ' instance of the process that is registering the window
   twcx.hIcon         = %NULL                                     ' handle of class icon
   twcx.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)       ' handle of class cursor
   twcx.hbrBackground = %COLOR_BTNFACE + 1                        ' brush used to fill background of window's client area
   twcx.lpszMenuName  = %NULL                                     ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                       ' class name
   twcx.hIconSm       = %NULL                                     ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Register the splitterbar class
   szClassName        = "Splitterbar_Class32"
   twcx.cbSize        = SIZEOF(twcx)                                    ' size of WNDCLASSEX structure
   twcx.style         = %CS_GLOBALCLASS OR %CS_HREDRAW OR %CS_VREDRAW   ' class styles
   twcx.lpfnWndProc   = CODEPTR(SplitterbarClass32_WndProc)             ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                               ' extra class bytes
   twcx.cbWndExtra    = 4                                               ' extra window bytes
   twcx.hInstance     = ghInstance                                      ' instance of the process that is registering the window
   twcx.hIcon         = %NULL                                           ' handle of class icon
   twcx.hCursor       = %NULL                                           ' handle of class cursor
   twcx.lpszMenuName  = %NULL                                           ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                             ' class name
   twcx.hIconSm       = %NULL                                           ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Register the Code window
   szClassName        = "TLB_400_CODE_CLASS"
   twcx.cbSize        = SIZEOF(twcx)                              ' size of WNDCLASSEX structure
   twcx.style         = %CS_DBLCLKS                               ' class styles
   twcx.lpfnWndProc   = CODEPTR(Dialog1_Code_WndProc)             ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                         ' extra class bytes
   twcx.cbWndExtra    = 0                                         ' extra window bytes
   twcx.hInstance     = ghInstance                                ' instance of the process that is registering the window
   twcx.hIcon         = %NULL                                     ' handle of class icon
   twcx.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)       ' handle of class cursor
   twcx.hbrBackground = %COLOR_BTNFACE + 1                        ' brush used to fill background of window's client area
   twcx.lpszMenuName  = %NULL                                     ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                       ' class name
   twcx.hIconSm       = %NULL                                     ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' Register the Options window
   szClassName        = "TLB_400_OPTIONS_CLASS"
   twcx.cbSize        = SIZEOF(twcx)                              ' size of WNDCLASSEX structure
   twcx.style         = %CS_DBLCLKS                               ' class styles
   twcx.lpfnWndProc   = CODEPTR(Dialog1_Options_WndProc)          ' address of window procedure used by class
   twcx.cbClsExtra    = 0                                         ' extra class bytes
   twcx.cbWndExtra    = 0                                         ' extra window bytes
   twcx.hInstance     = ghInstance                                ' instance of the process that is registering the window
   twcx.hIcon         = %NULL                                     ' handle of class icon
   twcx.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)       ' handle of class cursor
   twcx.hbrBackground = %COLOR_BTNFACE + 1                        ' brush used to fill background of window's client area
   twcx.lpszMenuName  = %NULL                                     ' resource identifier of the class menu
   twcx.lpszClassName = VARPTR(szClassName)                       ' class name
   twcx.hIconSm       = %NULL                                     ' handle of small icon shown in caption/system Taskbar
   IF ISFALSE RegisterClassEx(twcx) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF

   ' All registration successful
   FUNCTION = %FALSE

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_WndProc
' PURPOSE:   Processes messages for the Dialog1 window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_WndProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL sBtnText       AS STRING                     ' toolbar button caption
   LOCAL szItem         AS ASCIIZ * %MAX_PATH         ' working variable
   LOCAL tkf            AS KEYBOARDFOCUS              ' keyboard focus and default ID information
   LOCAL ttbb           AS TBBUTTON                   ' specifies or receives the attributes of a toolbar button
   LOCAL ttci           AS TC_ITEM                    ' specifies or receives the attributes of a tab
   LOCAL ptkf           AS KEYBOARDFOCUS PTR          ' pointer to keyboard focus and default ID information
   LOCAL ptnmhdr        AS NMHDR PTR                  ' information about a notification message
   LOCAL ptttdi         AS NMTTDISPINFO PTR           ' tooltip notification message information
   LOCAL pttbb          AS TBBUTTON PTR               ' address of array of toolbar button info
   LOCAL plEdge         AS LONG PTR                   ' address of array of right edges
   LOCAL ptmis          AS MEASUREITEMSTRUCT PTR      ' receives the dimensions of an owner-drawn control or menu item
   LOCAL ptdis          AS DRAWITEMSTRUCT PTR         ' provides drawing information about an owner-drawn control or menu item
   LOCAL ptmmi          AS MINMAXINFO PTR             ' pointer to the maximized and tracking info
   LOCAL rXFactor       AS SINGLE                     ' horizontal scaling factor
   LOCAL rYFactor       AS SINGLE                     ' vertical scaling factor
   LOCAL hWndChild      AS DWORD                      ' handle of child window
   LOCAL hWndBar        AS DWORD                      ' handle of toolbar or statusbar with embedded control
   LOCAL hImageList     AS DWORD                      ' handle of imagelist control
   LOCAL hImlButton     AS DWORD                      ' handle of imagelist with button bitmaps for owner-drawn menu
   LOCAL hMenu          AS DWORD                      ' handle of owner-drawn menu attached to window
   LOCAL hFont          AS DWORD                      ' handle of font used by form
   LOCAL hFontCtrl      AS DWORD                      ' handle of unique font used by control
   LOCAL hImage         AS DWORD                      ' handle of bitmap, icon, cursor or metafile
   LOCAL lMsgResult     AS LONG                       ' value returned to message after message is processed

   SELECT CASE uMsg
      CASE %WM_COMMAND
         ' If the Enter key is pressed when a button has the focus
         ' and the button is not an immediate child of the top-level
         ' window, pass the message to the parent of the button
         IF ISTRUE lParam THEN
            IF GetParent(lParam) <> hWnd THEN
               SendMessage GetParent(lParam), uMsg, wParam, lParam
               FUNCTION = %FALSE
               EXIT FUNCTION
            END IF
         END IF

         SELECT CASE LOWRD(wParam)
            CASE %IDM_OPEN
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_FileOpen(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_SAVE
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_Save(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_RELOAD
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_FileReload(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_EXIT
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_FileExit(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_IDENTIFIERS
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_CodeIdentifiers(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_ENUMERATIONS
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_CodeEnumerations(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_MODULES
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_CodeModules(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_RECORDS
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_CodeStructures(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_INTERFACES
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_InterfacesDirectInterfaces(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_DISPINTERFACES
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_InterfacesDispatchInterfaces(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_HELP
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_Help(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_TOOLBAR_HELP
               ' If the message was processed
               IF ISTRUE Dialog1_Toolbar_Help(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_ABOUT
               ' If the message was processed
               IF ISTRUE Dialog1_MainMenu_About(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_CODE
               ' If the message was processed
               IF ISTRUE Dialog1_Toolbar1_Interfaces(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_EVENTS
               ' If the message was processed
               IF ISTRUE Dialog1_Toolbar1_Events(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDM_STOP
               ' If the message was processed
               IF ISTRUE Dialog1_Toolbar1_Stop(hWnd) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF

            CASE %IDC_DIALOG1_EDITPREFIX
               IF HIWRD(wParam) = %EN_CHANGE THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_EditPrefix_Change(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE ELSE
               ' If the message was processed
               IF ISTRUE Dialog1_OnCommand(hWnd, LOWRD(wParam), lParam, HIWRD(wParam)) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_NOTIFY
         ptnmhdr = lParam

         SELECT CASE @ptnmhdr.code
            CASE %TTN_GETDISPINFO
               ptttdi        = lParam
               @ptttdi.hinst = ghInstance

               SELECT CASE @ptttdi.hdr.hwndFrom
                  CASE SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_GETTOOLTIPS, 0, 0)
                     @ptttdi.lpszText = @ptttdi.hdr.idFrom
                     EXIT FUNCTION

                  CASE SendMessage(GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %TCM_GETTOOLTIPS, 0, 0)
                     @ptttdi.lpszText = %IDS_STRING3 + %OFFSET_BROWSE + @ptttdi.hdr.idFrom
                     EXIT FUNCTION
               END SELECT

            CASE ELSE

               SELECT CASE @ptnmhdr.idFrom
                  CASE %IDC_DIALOG1_TOOLBAR1
                     IF @ptnmhdr.code = %TBN_DROPDOWN THEN
                        ' If the notification was processed
                        IF ISTRUE Dialog1_Toolbar1_DropDown(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                           FUNCTION = lMsgResult
                           EXIT FUNCTION
                        END IF
                     END IF

                  CASE %IDC_DIALOG1_TAB1

                     SELECT CASE @ptnmhdr.code
                        CASE %TCN_SELCHANGE
                           ' If the notification was processed
                           IF ISTRUE Dialog1_Tab1_SelChange(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                              FUNCTION = lMsgResult
                              EXIT FUNCTION
                           END IF

                           ' Show the selected page
                           SELECT CASE SendMessage(@ptnmhdr.hwndFrom, %TCM_GETCURSEL, 0, 0)
                              CASE 0
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %SW_SHOW

                              CASE 1
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %SW_SHOW

                              CASE 2
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_CODE), %SW_SHOW

                              CASE 3
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS), %SW_SHOW
                           END SELECT

                           PostMessage hWnd, %WM_NEXTDLGCTL, @ptnmhdr.hwndFrom, %TRUE

                        CASE %TCN_SELCHANGING
                           ' If the notification was processed
                           IF ISTRUE Dialog1_Tab1_SelChanging(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                              FUNCTION = lMsgResult
                              EXIT FUNCTION
                           END IF

                           ' Hide the current page
                           SELECT CASE SendMessage(@ptnmhdr.hwndFrom, %TCM_GETCURSEL, 0, 0)
                              CASE 0
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %SW_HIDE

                              CASE 1
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %SW_HIDE

                              CASE 2
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_CODE), %SW_HIDE

                              CASE 3
                                 ShowWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS), %SW_HIDE
                           END SELECT

                     END SELECT
               END SELECT

         END SELECT

         ' If the message was processed
         IF ISTRUE Dialog1_OnNotify(hWnd, wParam, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF

      CASE %WM_INITMENU
         ' If the menu is attached to the window, its handle
         ' is saved and is used to restore the menu items to
         ' to their original type and state when it closes.
         IF GetMenu(hWnd) = wParam THEN
            ghMenuActive = wParam
         ELSE
            ghMenuActive = %NULL
         END IF

      CASE %WM_INITMENUPOPUP
         ' If the message was processed
         IF ISTRUE Dialog1_OnInitMenuPopup(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF
         ' Place routines that modify menu items before CoolMenu_ToOwnerDraw()
         ' If this is not the system menu
         IF ISFALSE HIWRD(lParam) THEN CoolMenu_ToOwnerDraw wParam

      CASE %WM_MENUCHAR
         IF HIWRD(wParam) = %MF_POPUP THEN
            lMsgResult = CoolMenu_OnMenuChar(lParam, ASC(UCASE$(CHR$(LOWRD(wParam)))))
            IF ISTRUE lMsgResult THEN
               FUNCTION = lMsgResult
               EXIT FUNCTION
            END IF
         END IF

      CASE %WM_MENUSELECT
         ' If the menu was dismissed
         IF (lParam = %NULL) AND (HIWRD(wParam) = &HFFFF??) THEN
            CoolMenu_Revert ghMenuActive
            ghMenuActive = %NULL
         END IF

      CASE %WM_ERASEBKGND
         ' If the message was processed
         IF ISTRUE Dialog1_OnEraseBkgnd(hWnd, wParam) THEN
            FUNCTION = %TRUE
            EXIT FUNCTION
         END IF

      CASE %WM_MEASUREITEM
         ptmis = lParam
         IF @ptmis.CtlType = %ODT_MENU THEN
            IF ISTRUE CoolMenu_OnMeasureItem(BYVAL lParam) THEN
               FUNCTION = %TRUE
               EXIT FUNCTION
            END IF
         END IF

      CASE %WM_DRAWITEM
         ptdis = lParam
         IF @ptdis.CtlType = %ODT_MENU THEN
            IF ISTRUE CoolMenu_OnDrawItem(BYVAL lParam) THEN
               FUNCTION = %TRUE
               EXIT FUNCTION
            END IF
         END IF

      CASE %WM_SYSCOLORCHANGE
         ' Forward this message to common controls so that they will
         ' be properly updated when the user changes the color settings.
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TAB1), %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_GRID), %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TREES), %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1), %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_ACTIVATE
         IF LOWRD(wParam) = %WA_INACTIVE THEN
            ' Save the control with the keyboard focus
            SaveCtrlFocus hWnd
         ELSE
            ' Set the keyboard focus to the control with
            ' the focus when the window was deactivated
            RestoreCtrlFocus hWnd
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_OnSetFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF
         ' Set the keyboard focus to the control with
         ' the focus when the window was deactivated
         RestoreCtrlFocus hWnd

      CASE %WM_KILLFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_OnKillFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %DM_GETDEFID
         ' Get the identifier of the default push button
         FUNCTION = GetDefID(hWnd)
         EXIT FUNCTION

      CASE %DM_SETDEFID
         ' Set the identifier of the default push button
         FUNCTION = SetDefID(hWnd, wParam)
         EXIT FUNCTION

      CASE %WM_NEXTDLGCTL
         ' Set the keyboard focus to a different control
         GetNextDlgCtl hWnd, wParam, lParam
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_CLOSE
         ' If the message was processed
         IF ISTRUE Dialog1_OnClose(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_QUERYENDSESSION
         ' If the message was processed
         IF ISTRUE Dialog1_OnQueryEndSession(hWnd, wParam, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         ' Destroy pages associated with tab control(s)
         DestroyWindow GetDlgItem(hWnd, %IDC_DIALOG1_GRID)
         DestroyWindow GetDlgItem(hWnd, %IDC_DIALOG1_TREES)
         DestroyWindow GetDlgItem(hWnd, %IDC_DIALOG1_CODE)
         DestroyWindow GetDlgItem(hWnd, %IDC_DIALOG1_OPTIONS)
         ' Free memory used by custom menu
         hMenu = GetMenu(hWnd)
         SetMenu hWnd, %NULL
         CoolMenu_Destroy hMenu

         DeleteObject RemoveProp(hWnd, "FONT")
         hWndChild = GetDlgItem(hWnd, %IDC_DIALOG1_TAB1)
         ImageList_Destroy SendMessage(hWndChild, %TCM_SETIMAGELIST, 0, %NULL)
         hWndBar = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
         DeleteObject SendMessage(GetDlgItem(hWndBar, %IDC_DIALOG1_EDITPREFIX), %WM_GETFONT, 0, 0)
         hWndChild = GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1)
         ImageList_Destroy SendMessage(hWndChild, %TB_SETIMAGELIST, 0, %NULL)
         ImageList_Destroy SendMessage(hWndChild, %TB_SETDISABLEDIMAGELIST, 0, %NULL)
         ptkf = RemoveProp(hWnd, "KEYBOARDFOCUS")
         Dialog1_OnDestroy hWnd, lMsgResult
         IF ISTRUE ptkf THEN HeapFree GetProcessHeap(), 0, ptkf
         PostQuitMessage lMsgResult
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SIZE
         IF wParam <> %SIZE_MINIMIZED THEN
            ' Update the size and position of aligned controls
            SendMessage hWnd, gdwADM_ALIGNCONTROLS, wParam, lParam
            ' Resize the window and its controls
            SendMessage hWnd, gdwADM_LAYOUT, hWnd, %IDD_DIALOG1
         END IF
         ' If the message was processed
         IF ISTRUE Dialog1_OnSize(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE gdwADM_ALIGNCONTROLS
         ' Update the size and position of aligned controls
         hWndChild = GetDlgItem(hWnd, %IDC_DIALOG1_STATUSBAR1)
         SendMessage hWndChild, %WM_SIZE, wParam, lParam
         InvalidateRect hWndChild, BYVAL %NULL, %TRUE
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TOOLBAR1), %TB_AUTOSIZE, 0, 0
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE gdwADM_LAYOUT
         ' Resize the window and its controls
         phnxGetResolutionRatios rXFactor, rYFactor
         Layout_Apply wParam, ghInstance, lParam, %FALSE, rXFactor, rYFactor
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_GETMINMAXINFO
         ' Set the pointer to the address of the MINMAXINFO structure
         ptmmi = lParam
         ' Get the font used by the form
         hFont = SendMessage(hWnd, %WM_GETFONT, 0, 0)
         ' A bug in the operating system causes the WM_GETMINMAXINFO message to be sent
         ' before the WM_NCCREATE and WM_CREATE messages.  A nonzero font handle indicates
         ' that the window has processed these messages and is fully initialized.
         IF ISTRUE hFont THEN
            ' Get the ratios between the design and current screen resolutions
            phnxGetResolutionRatios rXFactor, rYFactor
            ' Set the minimum and maximum sizes that can be
            ' produced by dragging the borders of the window
            @ptmmi.ptMinTrackSize.x = 260 * rXFactor
            @ptmmi.ptMinTrackSize.y = 200 * rYFactor
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_GETFONT
         ' Return the handle of the font used by the form
         FUNCTION = GetProp(hWnd, "FONT")
         EXIT FUNCTION

      CASE %WM_SETFONT
         ' Get the current font used by the form
         hFont = GetProp(hWnd, "FONT")
         ' Set the new font
         SetProp hWnd, "FONT", wParam
         IF ISTRUE lParam THEN
            InvalidateRect hWnd, BYVAL %NULL, %TRUE
            UpdateWindow hWnd
         END IF
         FUNCTION = hFont
         EXIT FUNCTION

      CASE %WM_PAINT
         ' If the message was processed
         IF ISTRUE Dialog1_OnPaint(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %MYCREATEMESSAGE
         FUNCTION = Dialog1_OnMyCreateMessage(hWnd, wParam, lParam)
         EXIT FUNCTION

      CASE %MYSETFOCUSMESSAGE
         FUNCTION = Dialog1_OnMySetFocusMessage(hWnd, wParam, lParam)
         EXIT FUNCTION

      CASE %MYENUMMESSAGE
         FUNCTION = Dialog1_OnMyEnumMessage(hWnd, wParam, lParam)
         EXIT FUNCTION

      CASE %WM_CREATE
         ' Allocate memory for the keyboard focus and default ID
         ptkf = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(tkf))
         IF ISFALSE ptkf THEN
            FUNCTION = -1
            EXIT FUNCTION
         END IF
         ' Set the initial default ID
         @ptkf.wDefID = 0
         SetProp hWnd, "KEYBOARDFOCUS", ptkf

         ' Create and save the font used by the form
         hFont = GetStockObject(%DEFAULT_GUI_FONT)
         SendMessage hWnd, %WM_SETFONT, hFont, %FALSE

         ' Get the ratios between the design and current screen resolutions
         phnxGetResolutionRatios rXFactor, rYFactor

         ' Create the Statusbar1 statusbar control
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "msctls_statusbar32", _                               ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR _                         ' window styles
                                    %CCS_BOTTOM OR %SBARS_SIZEGRIP, _                     ' class styles
                                    0 * rXFactor, 492 * rYFactor, _                       ' left, top
                                    792 * rXFactor, 20 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_STATUSBAR1, _                      ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         ' Save the handle of the statusbar.  It is used when embedding controls
         hWndBar = hWndChild
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Allocate memory for the coordinate of the right edge of each part
         plEdge = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, 4 * 4)
         IF ISTRUE plEdge THEN
            @plEdge[0] = 100 * rXFactor
            @plEdge[1] = 138 * rXFactor
            @plEdge[2] = 292 * rXFactor
            @plEdge[3] = -1
            SendMessage hWndChild, %SB_SETPARTS, 4, BYVAL plEdge
            ' Free memory that was allocated for the edge info
            HeapFree GetProcessHeap(), 0, BYVAL plEdge
         END IF
         ' Set the icons
         hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_TYPELIBS_16, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR OR %LR_SHARED)
         SendMessage hWndChild, %SB_SETICON, 0, hImage
         hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_SPEAKER, %IMAGE_ICON, 0, 0, %LR_DEFAULTCOLOR OR %LR_SHARED)
         SendMessage hWndChild, %SB_SETICON, 3, hImage
         ' Set text
         szItem = "0 TypeLibs"
         SendMessage hWndChild, %SB_SETTEXT, 0, BYVAL VARPTR(szItem)
         szItem = "Prefix"
         SendMessage hWndChild, %SB_SETTEXT, 1, BYVAL VARPTR(szItem)
         ' Update the size of the statusbar
         SendMessage hWndChild, %WM_SIZE, 0, 0

         ' Create the EditPrefix edit control
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE, _                                  ' extended styles
                                    "Edit", _                                             ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR _           ' window styles
                                    %WS_TABSTOP OR _
                                    %ES_LEFT OR %ES_AUTOHSCROLL, _                        ' class styles
                                    141 * rXFactor, 0 * rYFactor, _                       ' left, top
                                    150 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_EDITPREFIX, _                      ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         ' Embed the control
         SetParent hWndChild, hWndBar
         hFontCtrl = phnxCreateFont("Verdana", 8, %FW_BOLD, 0, 0, 0, %ANSI_CHARSET)
         SendMessage hWndChild, %WM_SETFONT, hFontCtrl, %TRUE

         ' Set the text limit
         SendMessage hWndChild, %EM_SETLIMITTEXT, 255, 0

         ' Create the Toolbar1 toolbar control
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "ToolbarWindow32", _                                  ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %CCS_TOP OR %TBSTYLE_TOOLTIPS OR %TBSTYLE_FLAT OR _   ' class styles
                                    %TBSTYLE_LIST, _
                                    0 * rXFactor, 0 * rYFactor, _                         ' left, top
                                    792 * rXFactor, 36 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_TOOLBAR1, _                        ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         ' Set the extended class styles for the control
         SendMessage hWndChild, %TB_SETEXTENDEDSTYLE, 0, %TBSTYLE_EX_DRAWDDARROWS
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE


         ' Create and initialize the ImageList_24 image list
         hImageList = ImageList_Create(24, 24, %ILC_MASK OR %ILC_COLOR24, 7, 0)
         IF ISTRUE hImageList THEN
            ' Set the background color to use for drawing images
            ImageList_SetBkColor hImageList, %CLR_NONE
            ' Add the images to the imagelist
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_INTERFACES_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_EVENTS_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_STOP_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_SAVE_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_RELOAD_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_HELP_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_EXIT_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
         END IF

         ' Set the imagelist used with default images
         SendMessage hWndChild, %TB_SETIMAGELIST, 0, hImageList

         ' Create and initialize the ImageList_D_24 image list
         hImageList = ImageList_Create(24, 24, %ILC_MASK OR %ILC_COLOR24, 7, 0)
         IF ISTRUE hImageList THEN
            ' Set the background color to use for drawing images
            ImageList_SetBkColor hImageList, %CLR_NONE
            ' Add the images to the imagelist
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_INTERFACES_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_EVENTS_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_STOP_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_SAVE_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_RELOAD_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_HELP_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_EXIT_D_24)
            ImageList_AddMasked hImageList, hImage, &H00FF00FF???
            DeleteObject hImage
         END IF

         ' Set the imagelist used with disabled images
         SendMessage hWndChild, %TB_SETDISABLEDIMAGELIST, 0, hImageList

         ' Allocate memory for the button info array
         pttbb = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, 7 * SIZEOF(ttbb))
         IF ISTRUE pttbb THEN
            ' Send the TB_BUTTONSTRUCTSIZE message, for backward compatibility
            SendMessage hWndChild, %TB_BUTTONSTRUCTSIZE, SIZEOF(ttbb), 0
            ' Set the size of the bitmaps
            SendMessage hWndChild, %TB_SETBITMAPSIZE, 0, MAKLNG(24, 24)
            ' Add strings to the internal list
            sBtnText = "Reload" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Code" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Events" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Stop" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Save" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Help" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            sBtnText = "Exit" + CHR$(0, 0)
            SendMessage hWndChild, %TB_ADDSTRING, %NULL, BYVAL STRPTR(sBtnText)
            ' Add buttons to the toolbar
            @pttbb[0].iBitmap   = 4
            @pttbb[0].idCommand = %IDM_RELOAD
            @pttbb[0].fsState   = %TBSTATE_ENABLED
            @pttbb[0].fsStyle   = %BTNS_BUTTON
            @pttbb[0].dwData    = 0
            @pttbb[0].iString   = 0

            @pttbb[1].iBitmap   = 0
            @pttbb[1].idCommand = %IDM_CODE
            @pttbb[1].fsState   = 0
            @pttbb[1].fsStyle   = %BTNS_DROPDOWN
            @pttbb[1].dwData    = 0
            @pttbb[1].iString   = 1

            @pttbb[2].iBitmap   = 1
            @pttbb[2].idCommand = %IDM_EVENTS
            @pttbb[2].fsState   = 0
            @pttbb[2].fsStyle   = %BTNS_BUTTON
            @pttbb[2].dwData    = 0
            @pttbb[2].iString   = 2

            @pttbb[3].iBitmap   = 2
            @pttbb[3].idCommand = %IDM_STOP
            @pttbb[3].fsState   = 0
            @pttbb[3].fsStyle   = %BTNS_BUTTON
            @pttbb[3].dwData    = 0
            @pttbb[3].iString   = 3

            @pttbb[4].iBitmap   = 3
            @pttbb[4].idCommand = %IDM_SAVE
            @pttbb[4].fsState   = 0
            @pttbb[4].fsStyle   = %BTNS_BUTTON
            @pttbb[4].dwData    = 0
            @pttbb[4].iString   = 4

            @pttbb[5].iBitmap   = 5
            @pttbb[5].idCommand = %IDM_TOOLBAR_HELP
            @pttbb[5].fsState   = 0
            @pttbb[5].fsStyle   = %BTNS_BUTTON
            @pttbb[5].dwData    = 0
            @pttbb[5].iString   = 5

            @pttbb[6].iBitmap   = 6
            @pttbb[6].idCommand = %IDM_EXIT
            @pttbb[6].fsState   = %TBSTATE_ENABLED
            @pttbb[6].fsStyle   = %BTNS_BUTTON
            @pttbb[6].dwData    = 0
            @pttbb[6].iString   = 6
            SendMessage hWndChild, %TB_ADDBUTTONS, 7, BYVAL pttbb
            ' Free memory that was allocated for the button info
            HeapFree GetProcessHeap(), 0, BYVAL pttbb
            ' Update the size of the toolbar
            SendMessage hWndChild, %TB_AUTOSIZE, 0, 0
         END IF

         ' Create the Grid window
         hWndChild = CreateWindowEx(%WS_EX_CONTROLPARENT, _                               ' extended styles
                                    "TLB_400_GRID_CLASS", _                               ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPCHILDREN OR _     ' window styles
                                    %WS_CLIPSIBLINGS, _
                                    5 * rXFactor, 61 * rYFactor, _                        ' left, top
                                    641 * rXFactor, 251 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_GRID, _                            ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters

         ' Create the Trees window
         hWndChild = CreateWindowEx(%WS_EX_CONTROLPARENT, _                               ' extended styles
                                    "TLB_400_TREES_CLASS", _                              ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_CLIPCHILDREN OR _                    ' window styles
                                    %WS_CLIPSIBLINGS, _
                                    5 * rXFactor, 61 * rYFactor, _                        ' left, top
                                    641 * rXFactor, 251 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_TREES, _                           ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters

         ' Create the Code window
         hWndChild = CreateWindowEx(%WS_EX_CONTROLPARENT, _                               ' extended styles
                                    "TLB_400_CODE_CLASS", _                               ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_CLIPCHILDREN OR _                    ' window styles
                                    %WS_CLIPSIBLINGS, _
                                    5 * rXFactor, 61 * rYFactor, _                        ' left, top
                                    641 * rXFactor, 251 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_CODE, _                            ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters

         ' Create the Options window
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE OR %WS_EX_CONTROLPARENT, _          ' extended styles
                                    "TLB_400_OPTIONS_CLASS", _                            ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_BORDER, _                            ' window styles
                                    5 * rXFactor, 61 * rYFactor, _                        ' left, top
                                    641 * rXFactor, 251 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_OPTIONS, _                         ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters

         ' Create the Tab1 tab control
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "SysTabControl32", _                                  ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPCHILDREN OR _     ' window styles
                                    %WS_CLIPSIBLINGS OR %WS_GROUP OR %WS_TABSTOP OR _
                                    %TCS_FORCELABELLEFT OR %TCS_TABS OR _                 ' class styles
                                    %TCS_FIXEDWIDTH OR %TCS_TOOLTIPS, _
                                    1 * rXFactor, 38 * rYFactor, _                        ' left, top
                                    649 * rXFactor, 278 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_TAB1, _                            ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create and initialize the ImageList_16 image list
         hImageList = ImageList_Create(16, 16, %ILC_MASK OR %ILC_COLOR24, 6, 0)
         IF ISTRUE hImageList THEN
            ' Set the background color to use for drawing images
            ImageList_SetBkColor hImageList, %CLR_NONE
            ' Add the images to the imagelist
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_TYPELIBS_16, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_SPEAKER, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_GRID_16, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_TREEVIEW_16, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_INTERFACES_16, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
            hImage = LoadImage(ghInstance, BYVAL %IDI_TLB_OPTIONS_16, %IMAGE_ICON, 16, 16, %LR_DEFAULTCOLOR)
            ImageList_ReplaceIcon hImageList, -1, hImage
            DeleteObject hImage
         END IF

         ' Set the imagelist associated with the tab control
         SendMessage hWndChild, %TCM_SETIMAGELIST, 0, hImageList

         ' Set the width and height of each tab
         SendMessage hWndChild, %TCM_SETITEMSIZE, 0, MAKLNG(100 * rXFactor, 19 * rYFactor)
         ' Insert tabs
         szItem       = "TypeLibs"
         ttci.mask    = %TCIF_TEXT OR %TCIF_IMAGE
         ttci.pszText = VARPTR(szItem)
         ttci.iImage  = 2
         SendMessage hWndChild, %TCM_INSERTITEM, 0, BYVAL VARPTR(ttci)

         szItem       = "Type Info"
         ttci.mask    = %TCIF_TEXT OR %TCIF_IMAGE
         ttci.pszText = VARPTR(szItem)
         ttci.iImage  = 3
         SendMessage hWndChild, %TCM_INSERTITEM, 1, BYVAL VARPTR(ttci)

         szItem       = "Code"
         ttci.mask    = %TCIF_TEXT OR %TCIF_IMAGE
         ttci.pszText = VARPTR(szItem)
         ttci.iImage  = 4
         SendMessage hWndChild, %TCM_INSERTITEM, 2, BYVAL VARPTR(ttci)

         szItem       = "Options"
         ttci.mask    = %TCIF_TEXT OR %TCIF_IMAGE
         ttci.pszText = VARPTR(szItem)
         ttci.iImage  = 5
         SendMessage hWndChild, %TCM_INSERTITEM, 3, BYVAL VARPTR(ttci)

         ' Load the ownerdraw menu data
         CoolMenu_SetData GetMenu(hWnd), ghInstance, %IDR_DIALOG1_MAINMENU

         ' Create and initialize the ImageListMenu_16 image list
         hImlButton = ImageList_Create(16, 16, %ILC_MASK OR %ILC_COLOR24, 7, 0)
         IF ISTRUE hImlButton THEN
            ' Set the background color to use for drawing images
            ImageList_SetBkColor hImlButton, %CLR_NONE
            ' Add the images to the imagelist
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_OPEN_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_SAVE_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_RELOAD_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_EXIT_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_HELP_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_ABOUT_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
            hImage = LoadBitmap(ghInstance, BYVAL %IDB_TLB_INTERFACES_16)
            ImageList_AddMasked hImlButton, hImage, &H00FF00FF???
            DeleteObject hImage
         END IF

         ' Set the imagelist used for menu button bitmaps
         CoolMenu_SetImageList GetMenu(hWnd), %TRUE, hImlButton

         ' If the message was processed
         IF ISTRUE Dialog1_OnCreate(hWnd, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Grid_WndProc
' PURPOSE:   Processes messages for the Grid window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Grid_WndProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL szItem         AS ASCIIZ * %MAX_PATH      ' working variable
   LOCAL tlvc           AS LVCOLUMN                ' specifies or receives the attributes of a listview column
   LOCAL ptnmhdr        AS NMHDR PTR               ' information about a notification message
   LOCAL rXFactor       AS SINGLE                  ' horizontal scaling factor
   LOCAL rYFactor       AS SINGLE                  ' vertical scaling factor
   LOCAL hWndChild      AS DWORD                   ' handle of child window
   LOCAL hWndHdr        AS DWORD                   ' handle of listview child header control
   LOCAL dwExStyle      AS DWORD                   ' extended class styles of a control
   LOCAL hFont          AS DWORD                   ' handle of font used by panel
   LOCAL lMsgResult     AS LONG                    ' value returned to message after message is processed

   SELECT CASE uMsg
      CASE %WM_NOTIFY
         ptnmhdr = lParam

         SELECT CASE @ptnmhdr.idFrom
            CASE %IDC_DIALOG1_LISTVIEW1

               SELECT CASE @ptnmhdr.code
                  CASE %LVN_COLUMNCLICK
                     ' If the notification was processed
                     IF ISTRUE Dialog1_ListView1_ColumnClick(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                        FUNCTION = lMsgResult
                        EXIT FUNCTION
                     END IF

                  CASE %LVN_ITEMCHANGED
                     ' If the notification was processed
                     IF ISTRUE Dialog1_ListView1_ItemChanged(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                        FUNCTION = lMsgResult
                        EXIT FUNCTION
                     END IF

                  CASE %NM_CLICK
                     ' If the notification was processed
                     IF ISTRUE Dialog1_ListView1_Click(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                        FUNCTION = lMsgResult
                        EXIT FUNCTION
                     END IF

                  CASE %NM_DBLCLK
                     ' If the notification was processed
                     IF ISTRUE Dialog1_ListView1_DblClk(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                        FUNCTION = lMsgResult
                        EXIT FUNCTION
                     END IF
               END SELECT

         END SELECT

         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnNotify(hWnd, wParam, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF

      CASE %WM_SYSCOLORCHANGE
         ' Forward this message to common controls so that they will
         ' be properly updated when the user changes the color settings.
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_LISTVIEW1), %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_SETFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnSetFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_KILLFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnKillFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_NEXTDLGCTL
         ' Set the keyboard focus to a different control
         GetNextDlgCtl hWnd, wParam, lParam
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_DESTROY
         Dialog1_Grid_OnDestroy hWnd, lMsgResult
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SIZE
         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnSize(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_PAINT
         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnPaint(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_CREATE
         ' Get the ratios between the design and current screen resolutions
         phnxGetResolutionRatios rXFactor, rYFactor

         ' Create font used by container
         hFont = GetStockObject(%DEFAULT_GUI_FONT)

         ' Create the ListView1 listview control
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE, _                                  ' extended styles
                                    "SysListView32", _                                    ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %LVS_REPORT OR %LVS_SINGLESEL OR _                    ' class styles
                                    %LVS_SHOWSELALWAYS OR %LVS_NOSORTHEADER, _
                                    0 * rXFactor, 5 * rYFactor, _                         ' left, top
                                    261 * rXFactor, 121 * rYFactor, _                     ' width, height
                                    hWnd, %IDC_DIALOG1_LISTVIEW1, _                       ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         ' Set the extended class styles for the control
         ' Note: LVS_EX_GRIDLINES doesn't work properly with XP.
         ' See: http://support.microsoft.com/kb/813791
'         dwExStyle = %LVS_EX_GRIDLINES OR %LVS_EX_HEADERDRAGDROP OR %LVS_EX_FULLROWSELECT OR _
'                     %LVS_EX_INFOTIP OR %LVS_EX_DOUBLEBUFFER
         dwExStyle = %LVS_EX_HEADERDRAGDROP OR %LVS_EX_FULLROWSELECT OR _
                     %LVS_EX_INFOTIP OR %LVS_EX_DOUBLEBUFFER
         SendMessage hWndChild, %LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dwExStyle
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Remove the buttons style from the header control to give it a flat appearance
         hWndHdr = SendMessage(hWndChild, %LVM_GETHEADER, 0, 0)
         SetWindowLong hWndHdr, %GWL_STYLE, GetWindowLong(hWndHdr, %GWL_STYLE) XOR %HDS_BUTTONS
         SetWindowPos hWndChild, %NULL, 0, 0, 0, 0, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOSIZE OR %SWP_DRAWFRAME

         ' Add the columns
         szItem = "Description"
         tlvc.mask     = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
         tlvc.fmt      = %LVCFMT_LEFT
         tlvc.cx       = 400 * rXFactor
         tlvc.pszText  = VARPTR(szItem)
         tlvc.iSubItem = 0
         SendMessage hWndChild, %LVM_INSERTCOLUMN, 0, BYVAL VARPTR(tlvc)

         szItem = "File name"
         tlvc.mask     = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
         tlvc.fmt      = %LVCFMT_LEFT
         tlvc.cx       = 120 * rXFactor
         tlvc.pszText  = VARPTR(szItem)
         tlvc.iSubItem = 1
         SendMessage hWndChild, %LVM_INSERTCOLUMN, 1, BYVAL VARPTR(tlvc)

         szItem = "Full Path"
         tlvc.mask     = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
         tlvc.fmt      = %LVCFMT_LEFT
         tlvc.cx       = 500 * rXFactor
         tlvc.pszText  = VARPTR(szItem)
         tlvc.iSubItem = 2
         SendMessage hWndChild, %LVM_INSERTCOLUMN, 2, BYVAL VARPTR(tlvc)

         szItem = "CLSID"
         tlvc.mask     = %LVCF_FMT OR %LVCF_WIDTH OR %LVCF_TEXT OR %LVCF_SUBITEM
         tlvc.fmt      = %LVCFMT_LEFT
         tlvc.cx       = 250 * rXFactor
         tlvc.pszText  = VARPTR(szItem)
         tlvc.iSubItem = 3
         SendMessage hWndChild, %LVM_INSERTCOLUMN, 3, BYVAL VARPTR(tlvc)

         ' If the message was processed
         IF ISTRUE Dialog1_Grid_OnCreate(hWnd, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Trees_WndProc
' PURPOSE:   Processes messages for the Trees window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Trees_WndProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL ptnmhdr        AS NMHDR PTR            ' information about a notification message
   LOCAL ptttdi         AS NMTTDISPINFO PTR     ' tooltip notification message information
   LOCAL rXFactor       AS SINGLE               ' horizontal scaling factor
   LOCAL rYFactor       AS SINGLE               ' vertical scaling factor
   LOCAL hWndChild      AS DWORD                ' handle of child window
   LOCAL hFont          AS DWORD                ' handle of font used by panel
   LOCAL lMsgResult     AS LONG                 ' value returned to message after message is processed

   SELECT CASE uMsg
      CASE %WM_COMMAND

         SELECT CASE LOWRD(wParam)
            CASE %IDC_DIALOG1_SPLITTERBAR1
               IF HIWRD(wParam) = %SBARN_POSCHANGED THEN
                  SendMessage phnxGetFormHandle(lParam), gdwADM_LAYOUT, phnxGetFormHandle(lParam), %IDD_DIALOG1
               END IF

            CASE ELSE
               ' If the message was processed
               IF ISTRUE Dialog1_Trees_OnCommand(hWnd, LOWRD(wParam), lParam, HIWRD(wParam)) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_NOTIFY
         ptnmhdr = lParam

         SELECT CASE @ptnmhdr.code
            CASE %TTN_GETDISPINFO
               ptttdi        = lParam
               @ptttdi.hinst = ghInstance

               SELECT CASE @ptttdi.hdr.hwndFrom
               END SELECT

            CASE ELSE

               SELECT CASE @ptnmhdr.idFrom
                  CASE %IDC_DIALOG1_TREEVIEW1
                     IF @ptnmhdr.code = %TVN_SELCHANGED THEN
                        ' If the notification was processed
                        IF ISTRUE Dialog1_TreeView1_SelChanged(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                           FUNCTION = lMsgResult
                           EXIT FUNCTION
                        END IF
                     END IF

                  CASE %IDC_DIALOG1_TREEVIEW2
                     IF @ptnmhdr.code = %TVN_SELCHANGED THEN
                        ' If the notification was processed
                        IF ISTRUE Dialog1_TreeView2_SelChanged(hWnd, BYVAL ptnmhdr, lMsgResult) THEN
                           FUNCTION = lMsgResult
                           EXIT FUNCTION
                        END IF
                     END IF
               END SELECT

         END SELECT

         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnNotify(hWnd, wParam, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF

      CASE %WM_SYSCOLORCHANGE
         ' Forward this message to common controls so that they will
         ' be properly updated when the user changes the color settings.
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TREEVIEW1), %WM_SYSCOLORCHANGE, wParam, lParam
         SendMessage GetDlgItem(hWnd, %IDC_DIALOG1_TREEVIEW2), %WM_SYSCOLORCHANGE, wParam, lParam

      CASE %WM_SETFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnSetFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_KILLFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnKillFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_NEXTDLGCTL
         ' Set the keyboard focus to a different control
         GetNextDlgCtl hWnd, wParam, lParam
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_DESTROY
         Dialog1_Trees_OnDestroy hWnd, lMsgResult
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SIZE
         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnSize(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_PAINT
         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnPaint(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_CREATE
         ' Get the ratios between the design and current screen resolutions
         phnxGetResolutionRatios rXFactor, rYFactor

         ' Create font used by container
         hFont = GetStockObject(%DEFAULT_GUI_FONT)

         ' Create the TreeView1 treeview control
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE, _                                  ' extended styles
                                    "SysTreeView32", _                                    ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR _           ' window styles
                                    %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR _
                                    %WS_TABSTOP OR _
                                    %TVS_HASBUTTONS OR %TVS_HASLINES OR _                 ' class styles
                                    %TVS_LINESATROOT OR %TVS_SHOWSELALWAYS, _
                                    5 * rXFactor, 25 * rYFactor, _                        ' left, top
                                    66 * rXFactor, 26 * rYFactor, _                       ' width, height
                                    hWnd, %IDC_DIALOG1_TREEVIEW1, _                       ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Splitterbar1 splitterbar control
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Splitterbar_class32", _                              ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_CLIPSIBLINGS OR _     ' window styles
                                    %SBSTYLE_VERTICAL OR %SBSTYLE_RAISED, _               ' class styles
                                    400 * rXFactor, 25 * rYFactor, _                      ' left, top
                                    3 * rXFactor, 81 * rYFactor, _                        ' width, height
                                    hWnd, %IDC_DIALOG1_SPLITTERBAR1, _                    ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters

         ' Set the background color
         SendMessage hWndChild, %SBARM_SETBKCOLOR, 0, &H000080FF???
         ' Set the offsets
         SendMessage hWndChild, %SBARM_SETOFFSETS, 0, MAKLNG(100 * rXFactor, 100 * rXFactor)

         ' Create the TreeView2 treeview control
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE, _                                  ' extended styles
                                    "SysTreeView32", _                                    ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR _           ' window styles
                                    %WS_CLIPCHILDREN OR %WS_CLIPSIBLINGS OR _
                                    %WS_TABSTOP OR _
                                    %TVS_HASBUTTONS OR %TVS_HASLINES OR _                 ' class styles
                                    %TVS_LINESATROOT OR %TVS_SHOWSELALWAYS, _
                                    510 * rXFactor, 43 * rYFactor, _                      ' left, top
                                    66 * rXFactor, 26 * rYFactor, _                       ' width, height
                                    hWnd, %IDC_DIALOG1_TREEVIEW2, _                       ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' If the message was processed
         IF ISTRUE Dialog1_Trees_OnCreate(hWnd, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Code_WndProc
' PURPOSE:   Processes messages for the Code window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Code_WndProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL szRichEdClass     AS ASCIIZ * %MAX_PATH         ' class name of rich edit control
   LOCAL szFaceName        AS ASCIIZ * %LF_FACESIZE      ' font name
   LOCAL tlf               AS LOGFONT                    ' font attributes
   LOCAL tcf               AS CHARFORMAT                 ' rich edit character formatting information
   LOCAL ptnmhdr           AS NMHDR PTR                  ' information about a notification message
   LOCAL rXFactor          AS SINGLE                     ' horizontal scaling factor
   LOCAL rYFactor          AS SINGLE                     ' vertical scaling factor
   LOCAL hWndChild         AS DWORD                      ' handle of child window
   LOCAL hFont             AS DWORD                      ' handle of font used by panel
   LOCAL dwMask            AS DWORD                      ' specifies the attributes of an item to retrieve or set
   LOCAL hDC               AS DWORD                      ' handle of memory device context
   LOCAL lMsgResult        AS LONG                       ' value returned to message after message is processed

   SELECT CASE uMsg
      CASE %WM_COMMAND

         SELECT CASE LOWRD(wParam)
            CASE %IDC_DIALOG1_RICHEDIT_VIEWCODE
               IF HIWRD(wParam) = %EN_CHANGE THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_RichEdit_ViewCode_Change(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE ELSE
               ' If the message was processed
               IF ISTRUE Dialog1_Code_OnCommand(hWnd, LOWRD(wParam), lParam, HIWRD(wParam)) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_NOTIFY
         ptnmhdr = lParam

         SELECT CASE @ptnmhdr.idFrom

         END SELECT

         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnNotify(hWnd, wParam, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF

      CASE %WM_SETFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnSetFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_KILLFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnKillFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_NEXTDLGCTL
         ' Set the keyboard focus to a different control
         GetNextDlgCtl hWnd, wParam, lParam
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_DESTROY
         Dialog1_Code_OnDestroy hWnd, lMsgResult
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SIZE
         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnSize(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_PAINT
         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnPaint(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_CREATE
         ' Get the ratios between the design and current screen resolutions
         phnxGetResolutionRatios rXFactor, rYFactor

         ' Create font used by container
         hFont = GetStockObject(%DEFAULT_GUI_FONT)

         ' Get the class name of the rich edit control
         szRichEdClass = phnxGetRichEditClass()

         ' Create the RichEdit_ViewCode rich edit control
         hWndChild = CreateWindowEx(%WS_EX_CLIENTEDGE, _                                  ' extended styles
                                    szRichEdClass, _                                      ' class name
                                    "", _                                                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_HSCROLL OR _          ' window styles
                                    %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR _
                                    %ES_LEFT OR %ES_AUTOHSCROLL OR %ES_AUTOVSCROLL OR _   ' class styles
                                    %ES_MULTILINE OR %ES_NOHIDESEL OR _
                                    %ES_WANTRETURN OR %ES_SAVESEL, _
                                    100 * rXFactor, 58 * rYFactor, _                      ' left, top
                                    66 * rXFactor, 23 * rYFactor, _                       ' width, height
                                    hWnd, %IDC_DIALOG1_RICHEDIT_VIEWCODE, _               ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         ' Subclass the control
         SetProp hWndChild, "OLDWNDPROC", SetWindowLong(hWndChild, %GWL_WNDPROC, CODEPTR(Dialog1_RichEdit_ViewCode_SubclassProc))

         ' Set the font
         hDC = GetDC(%NULL)
         szFaceName = "Fixedsys"
         EnumFontFamilies hDC, BYVAL VARPTR(szFaceName), CODEPTR(EnumFontFamProc), BYVAL VARPTR(tlf)
         ReleaseDC %NULL, hDC
         tcf.cbSize          = SIZEOF(tcf)
         tcf.dwMask          = %CFM_BOLD OR %CFM_ITALIC OR %CFM_UNDERLINE OR %CFM_STRIKEOUT OR _
                               %CFM_FACE OR %CFM_CHARSET OR %CFM_SIZE
         tcf.yHeight         = 11 * 20
         tcf.bCharSet        = tlf.lfCharSet
         tcf.bPitchAndFamily = tlf.lfPitchAndFamily
         tcf.szFaceName      = tlf.lfFaceName
         SendMessage hWndChild, %EM_SETCHARFORMAT, %SCF_ALL, BYVAL VARPTR(tcf)
         ' Set the text limit
         SendMessage hWndChild, %EM_SETLIMITTEXT, 31457279, 0
         ' Specify which notifications the control sends to its parent window
         SendMessage hWndChild, %EM_SETEVENTMASK, 0, %ENM_CHANGE

         ' If the message was processed
         IF ISTRUE Dialog1_Code_OnCreate(hWnd, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_RichEdit_ViewCode_SubclassProc
' PURPOSE:   Processes messages for the subclassed RichEdit window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_RichEdit_ViewCode_SubclassProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' control handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL lpOldWndProc      AS DWORD    ' address of original window procedure

   lpOldWndProc = GetProp(hWnd, "OLDWNDPROC")

   SELECT CASE uMsg
      CASE %WM_DESTROY
         ' Remove control subclassing
         SetWindowLong hWnd, %GWL_WNDPROC, RemoveProp(hWnd, "OLDWNDPROC")

      CASE %WM_KEYDOWN
         ' If the message was processed
         IF ISTRUE Dialog1_RichEdit_ViewCode_OnKeyDown(hWnd, wParam, lParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF
   END SELECT

   FUNCTION = CallWindowProc(lpOldWndProc, hWnd, uMsg, wParam, lParam)

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: Dialog1_Options_WndProc
' PURPOSE:   Processes messages for the Options window.
'
'-------------------------------------------------------------------------------

FUNCTION Dialog1_Options_WndProc _
   ( _
   BYVAL hWnd     AS DWORD, _ ' window handle
   BYVAL uMsg     AS DWORD, _ ' type of message
   BYVAL wParam   AS DWORD, _ ' first message parameter
   BYVAL lParam   AS LONG _   ' second message parameter
   ) AS LONG

   LOCAL trc            AS RECT        ' bounding or formatting rectangle
   LOCAL rXFactor       AS SINGLE      ' horizontal scaling factor
   LOCAL rYFactor       AS SINGLE      ' vertical scaling factor
   LOCAL hWndChild      AS DWORD       ' handle of child window
   LOCAL hFont          AS DWORD       ' handle of font used by panel
   LOCAL lMsgResult     AS LONG        ' value returned to message after message is processed

   SELECT CASE uMsg
      CASE %WM_COMMAND

         SELECT CASE LOWRD(wParam)
            CASE %IDC_DIALOG1_CHECK_USEMETHOD
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseMethod_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEPROPGETSET
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UsePropGetSet_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USESETPREFIX
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseSetPrefix_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEPRMNAMES
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseParameterNames_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_AddParameterNamesPrefix_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEINTNAMESWITHEXOBJ
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseInterfaceNamesWithExternalObjects_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEPREFIX
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UsePrefix_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEENUMPREFIX
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseEnumPrefix_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEHEXNUMBERS
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseHexNumbers_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_MIXDISPINTERFACES
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_MixDispInterfaces_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_RETRIEVELICENSEKEY
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_RetrieveLicenseKey_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE %IDC_DIALOG1_CHECK_USEAUTOMATIONVIEW
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  ' If the notification was processed
                  IF ISTRUE Dialog1_Check_UseAutomationView_Clicked(hWnd, lParam) THEN
                     FUNCTION = %FALSE
                     EXIT FUNCTION
                  END IF
               END IF

            CASE ELSE
               ' If the message was processed
               IF ISTRUE Dialog1_Options_OnCommand(hWnd, LOWRD(wParam), lParam, HIWRD(wParam)) THEN
                  FUNCTION = %FALSE
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_ERASEBKGND
         GetClientRect hWnd, trc
         ' Erase background
         FillRect wParam, trc, (%COLOR_WINDOW + 1)
         FUNCTION = %TRUE
         EXIT FUNCTION

      CASE %WM_CTLCOLORSTATIC

         SELECT CASE GetDlgCtrlID(lParam)
            CASE %IDC_DIALOG1_CHECK_USEMETHOD
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEPROPGETSET
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEPREFIX
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEENUMPREFIX
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEHEXNUMBERS
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_MIXDISPINTERFACES
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_RETRIEVELICENSEKEY
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEAUTOMATIONVIEW
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USESETPREFIX
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEINTNAMESWITHEXOBJ
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_USEPRMNAMES
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

            CASE %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX
               SetBkColor wParam, GetSysColor(%COLOR_WINDOW)
               ' Return handle of brush used to paint background
               FUNCTION = GetSysColorBrush(%COLOR_WINDOW)
               EXIT FUNCTION

         END SELECT

      CASE %WM_SETFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Options_OnSetFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_KILLFOCUS
         ' If the message was processed
         IF ISTRUE Dialog1_Options_OnKillFocus(hWnd, wParam) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_NEXTDLGCTL
         ' Set the keyboard focus to a different control
         GetNextDlgCtl hWnd, wParam, lParam
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_DESTROY
         Dialog1_Options_OnDestroy hWnd, lMsgResult
         FUNCTION = %FALSE
         EXIT FUNCTION

      CASE %WM_SIZE
         ' If the message was processed
         IF ISTRUE Dialog1_Options_OnSize(hWnd, wParam, LOWRD(lParam), HIWRD(lParam)) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_PAINT
         ' If the message was processed
         IF ISTRUE Dialog1_Options_OnPaint(hWnd) THEN
            FUNCTION = %FALSE
            EXIT FUNCTION
         END IF

      CASE %WM_CREATE
         ' Get the ratios between the design and current screen resolutions
         phnxGetResolutionRatios rXFactor, rYFactor

         ' Create font used by container
         hFont = GetStockObject(%DEFAULT_GUI_FONT)

         ' Create the Check_UsePropGetSet checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use METHOD and PROPERTY GET/SET statements", _       ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 28 * rYFactor, _                       ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEPROPGETSET, _             ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseMethod checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use METHOD statements only", _                       ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 58 * rYFactor, _                       ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEMETHOD, _                 ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseSetPrefix checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use SET_ instead of PUT_ as prefix", _               ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 88 * rYFactor, _                       ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USESETPREFIX, _              ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseParameterNames checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use parameter names in interface declarations", _    ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 118 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEPRMNAMES, _               ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_AddParameterNamexPrefix checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Add prefix to parameter names", _                    ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 148 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_ADDPRMNAMESPREFIX, _         ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseNamesWithExternalObjects checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use interface names with external objects", _        ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 178 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEINTNAMESWITHEXOBJ, _      ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UsePrefix checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use prefix in interface names", _                    ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 208 * rYFactor, _                       ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEPREFIX, _                 ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseEnumPrefix checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use enumeration names as prefix in constants", _     ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 238 * rYFactor, _                       ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEENUMPREFIX, _             ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseHexNumbers checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use hexadecimal numbers in constants", _             ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 268 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEHEXNUMBERS, _             ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_MixDispatchInterfaces checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Include dispatch only interfaces", _                 ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 298 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_MIXDISPINTERFACES, _         ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Retrieve the license key of the ActiveX control
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Retrieve license key", _                             ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 328 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_RETRIEVELICENSEKEY, _        ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' Create the Check_UseAutomationView checkbox
         hWndChild = CreateWindowEx(%NULL, _                                              ' extended styles
                                    "Button", _                                           ' class name
                                    "Use automation view", _                              ' caption
                                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR _          ' window styles
                                    %BS_AUTOCHECKBOX OR %BS_LEFT OR %BS_VCENTER, _        ' class styles
                                    30 * rXFactor, 358 * rYFactor, _                      ' left, top
                                    311 * rXFactor, 21 * rYFactor, _                      ' width, height
                                    hWnd, %IDC_DIALOG1_CHECK_USEAUTOMATIONVIEW, _         ' handle of parent, control ID
                                    ghInstance, BYVAL %NULL)                              ' handle of instance, creation parameters
         SendMessage hWndChild, %WM_SETFONT, hFont, %TRUE

         ' If the message was processed
         IF ISTRUE Dialog1_Options_OnCreate(hWnd, lParam, lMsgResult) THEN
            FUNCTION = lMsgResult
            EXIT FUNCTION
         END IF
         FUNCTION = %FALSE
         EXIT FUNCTION
   END SELECT

   FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)

END FUNCTION
'=========================================================================================
