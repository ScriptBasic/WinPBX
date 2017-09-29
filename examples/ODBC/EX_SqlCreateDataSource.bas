' ========================================================================================
' Demostrates the use of the SQLCreateDataSource function
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "odbcinst.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WINMAIN (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hDlg AS LONG

   DIALOG NEW 0, "SQLCreateDataSource Demo", , , 400, 240, %WS_OVERLAPPED OR %WS_THICKFRAME OR %WS_SYSMENU OR _
   %WS_MINIMIZEBOX OR %WS_MAXIMIZEBOX OR %WS_VISIBLE OR %DS_CENTER TO hDlg
   ' For icon from resource, instead use something like, LoadIcon(hInst, 'APPICON')
   DIALOG SEND hDlg, %WM_SETICON, %ICON_SMALL, LoadIcon(%Null, BYVAL %IDI_APPLICATION)
   DIALOG SEND hDlg, %WM_SETICON, %ICON_BIG, LoadIcon(%Null, BYVAL %IDI_APPLICATION)

   CONTROL ADD BUTTON, hDlg, %IDOK, "&Ok", 0, 0, 50, 14, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT
   CONTROL ADD BUTTON, hDlg, %IDCANCEL, "&Close", 0, 0, 50, 14, %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT

   DIALOG SHOW MODAL hDlg, CALL DlgProc

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Dialog procedure
' ========================================================================================
CALLBACK FUNCTION DlgProc() AS LONG

   LOCAL rc AS RECT

   SELECT CASE CB.MSG

      CASE %WM_SIZE
         ' Resize the two sample buttons of the Dialog
         IF CB.WPARAM <> %SIZE_MINIMIZED THEN
            GetClientRect CB.HNDL, rc
            MoveWindow GetDlgItem(CBHNDL, %IDOK), (rc.nRight - rc.nLeft) - 185, (rc.nBottom - rc.nTop) - 35, 75, 23, %True
            MoveWindow GetDlgItem(CBHNDL, %IDCANCEL), (rc.nRight - rc.nLeft) - 95, (rc.nBottom - rc.nTop) - 35, 75, 23, %True
            DIALOG REDRAW CB.HNDL
         END IF

      CASE %WM_COMMAND
         SELECT CASE CB.CTL
            CASE %IDOK
               IF CB.CTLMSG = %BN_CLICKED THEN
                  SQLCreateDataSource(CB.HNDL, "")
               END IF
            CASE %IDCANCEL
               IF CB.CTLMSG = %BN_CLICKED THEN DIALOG END CB.HNDL, 0
         END SELECT

   END SELECT

END FUNCTION
' ========================================================================================
