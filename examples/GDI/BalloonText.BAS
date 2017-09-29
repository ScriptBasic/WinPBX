' ########################################################################################
'MESSAGE http://www.powerbasic.com/support/forums/Forum7/HTML/001944.html
'FORUM:  Source Code
'TOPIC:  'Ballon' instead of Msgbox
'NAME:   Semen Matusovski, Member
'DATE:   June 12, 2003 02:04 PM

'In alive app I process input form and there are reasons to expect a lot of user's mistake.
'I move focus to error field. In addition it's necessary to give info about error type.

'I decided that often MsgBox will be terrible in this case and made a replacement a-la 'ballon'.
'A text can have some lines (divided by $CrLf or |).

'I used %WM_SETCURSOR in test dialog for demo purposes only (I don't want to replace tooltips).
'Ballon window is closed, if happends one of following events:
'1) WM_TIMER (2 seconds)
'2) user presses key or clicks mouse button
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

GLOBAL BallonText_hHook AS DWORD
GLOBAL BallonText_hWnd  AS DWORD

FUNCTION BallonTextGetMsgProc (BYVAL nCode AS LONG, BYVAL wParam AS DWORD, BYVAL lParam AS tagMsg PTR) AS LONG
   IF nCode = %HC_ACTION THEN
      SELECT CASE AS LONG @lParam.Message
         CASE %WM_KEYDOWN, %WM_LBUTTONDOWN, %WM_RBUTTONDOWN, %WM_MBUTTONDOWN
            SendMessage BallonText_hWnd, %WM_TIMER, 1, 0
      END SELECT
   END IF
   FUNCTION = CallNextHookEx(BallonText_hHook, nCode, wParam, BYVAL lParam)
END FUNCTION

FUNCTION BallonTextWndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   DIM szText        AS STATIC STRING
   DIM hFont         AS STATIC DWORD
   DIM hRgn(3)       AS STATIC DWORD
   DIM rcText        AS STATIC RECT

   DIM hWndCenter    AS LOCAL  DWORD
   DIM rcWnd(1)      AS LOCAL  RECT
   DIM tm            AS LOCAL  TEXTMETRIC
   DIM ps            AS LOCAL  PAINTSTRUCT
   DIM pt(2)         AS LOCAL  POINTAPI
   DIM Blank         AS LOCAL  POINTAPI
   DIM Dimension     AS LOCAL  POINTAPI
   DIM ArrowDown     AS LOCAL  DWORD
   DIM pCreateStruct AS CREATESTRUCT PTR

   DIM ncm           AS LOCAL  NONCLIENTMETRICS

   SELECT CASE wMsg

      CASE %WM_CREATE
         BallonText_hHook = SetWindowsHookEx (%WH_GETMESSAGE, CODEPTR(BallonTextGetMsgProc), 0, GetCurrentThreadId)

         DIALOG GET TEXT hWnd TO szText
         REPLACE "|" WITH $CRLF IN szText

         ps.hDC = GetDC (hWnd)
         ncm.cbSize = SIZEOF(NONCLIENTMETRICS)
         SystemParametersInfo %SPI_GETNONCLIENTMETRICS, 0, BYVAL VARPTR(ncm), 0

         hFont = CreateFontIndirect (ncm.lfMessageFont)

         SelectObject ps.hDC, hFont
         GetTextMetrics ps.hDC, tm

         RESET rcText
         DrawText ps.hDC, BYVAL STRPTR(szText), LEN(szText), rcText, %DT_CALCRECT

         Blank.Y = 0.75 * (tm.tmHeight + tm.tmExternalLeading) + 1
         Blank.X = tm.tmAveCharWidth * 3 + 1
         ArrowDown = (tm.tmHeight + tm.tmExternalLeading)
         Dimension.x = Blank.X + rcText.nRight + Blank.X
         Dimension.y = Blank.Y + rcText.nBottom + Blank.Y

         pt(0).x = Blank.X + tm.tmAveCharWidth * 0.5 - 1
         pt(0).y = Dimension.y - 1
         pt(1).x = pt(0).x
         pt(1).y = Dimension.y + ArrowDown + 1
         pt(2).x = pt(0).x + ArrowDown + 2
         pt(2).y = pt(0).y

         ReleaseDC hWnd, ps.hDC

         hRgn(0) = CreateRoundRectRgn(0, 0, Blank.X + rcText.nRight + Blank.X, _
            Blank.Y + rcText.nBottom + Blank.Y, Blank.Y, Blank.Y)
         hRgn(1) = CreatePolygonRgn(pt(0), 3, %ALTERNATE)

         hRgn(2) = CreateRectRgn (0, 0, 0, 0)
         CombineRgn hRgn(2), hRgn(1), hRgn(0), %RGN_OR

         hRgn(3) = CreateRectRgn (0, 0, 0, 0)
         CombineRgn hRgn(3), hRgn(2), 0, %RGN_COPY

         pCreateStruct = lParam
         hWndCenter = @pCreateStruct.lpCreateParams
         GetWindowRect hWndCenter, rcWnd(0)

         rcWnd(1).nRight  = Blank.X + rcText.nRight + Blank.X
         rcWnd(1).nLeft   = rcWnd(0).nLeft + MAX(0, (rcWnd(0).nRight - rcWnd(0).nLeft - rcWnd(1).nRight) \ 2)
         rcWnd(1).nBottom = Blank.Y + rcText.nBottom + Blank.Y + ArrowDown
         rcWnd(1).nTop    = rcWnd(0).nTop - rcWnd(1).nBottom + 0.75 * tm.tmHeight

         OffSetRect rcText, Blank.X, Blank.Y
         SetWindowPos hWnd, 0, rcWnd(1).nLeft, rcWnd(1).nTop, rcWnd(1).nRight,  rcWnd(1).nBottom, _
            %SWP_NOZORDER OR %SWP_NOOWNERZORDER OR %SWP_NOACTIVATE OR %SWP_SHOWWINDOW
         SetWindowRgn hWnd, hRgn(3), 0

         DeleteObject hRgn(0)
         DeleteObject hRgn(1)

         SetTimer hWnd, 1, 2000, BYVAL 0

      CASE %WM_TIMER
         DestroyWindow hWnd

      CASE %WM_PAINT
         BeginPaint hWnd, ps
         SelectObject ps.hDC, hFont
         FillRgn ps.hDC, hRgn(2), GetSysColorBrush(%COLOR_INFOBK)
         FrameRgn ps.hDC, hRgn(2), GetSysColorBrush(%COLOR_3DDKSHADOW), 1, 1
         SetBkMode ps.hDC, %TRANSPARENT
         DrawText ps.hDC, BYVAL STRPTR(szText), LEN(szText), rcText, %DT_CENTER
         EndPaint hWnd, ps

      CASE %WM_DESTROY
         KillTimer hWnd, 1
         DeleteObject hFont
         DeleteObject hRgn(2)
         UnhookWindowsHookEx BallonText_hHook

   END SELECT

   FUNCTION = DefWindowProc (hWnd, wMsg, wParam, lParam)

END FUNCTION

FUNCTION ShowBallonText (BYVAL hWndOwner AS DWORD, BYVAL hWndCenter AS DWORD, szText AS STRING) AS LONG

   DIM szClassName AS STATIC ASCIIZ * 11
   DIM wce         AS STATIC WNDCLASSEX

   IF wce.cbSize = 0 THEN
      szClassName = "BallonText"

      wce.cbSize        = SIZEOF(wce)
      wce.style         = %CS_HREDRAW OR %CS_VREDRAW OR %CS_GLOBALCLASS OR %CS_SAVEBITS
      wce.lpfnWndProc   = CODEPTR(BallonTextWndProc)
    ' wce.cbClsExtra = 0
    ' wce.cbWndExtra = 0
      wce.hInstance = GetModuleHandle("")
    ' wce.hIcon = 0
      wce.hCursor = LoadCursor(0, BYVAL %IDC_ARROW)
      wce.hbrBackground = 0
    ' wce.lpszMenuName = 0
      wce.lpszClassName = VARPTR(szClassName)
    ' wce.hIconSm = 0

      RegisterClassEx wce
   END IF

   IF BallonText_hWnd THEN IF IsWindow(BallonText_hWnd) THEN DestroyWindow BallonText_hWnd
   BallonText_hWnd = CreateWindowEx (0, szClassName, BYVAL STRPTR(szText), %WS_POPUP, 0, 0, 0, 0, hWndOwner, 0, wce.hInstance, BYVAL hWndCenter)

END FUNCTION

CALLBACK FUNCTION DlgProc

   DIM i AS LONG

   SELECT CASE CBMSG
      CASE %WM_INITDIALOG
         CONTROL ADD TEXTBOX, CBHNDL, 101, "", 10, 10, 50, 15
         CONTROL ADD TEXTBOX, CBHNDL, 102, "", 10, 30, 100, 15
      CASE %WM_SETCURSOR
         DIM hWndLast AS STATIC DWORD
         IF hWndLast <> CBWPARAM THEN hWndLast = CBWPARAM: ShowBallonText CBHNDL, CBWPARAM, "hWnd = &&H" + HEX$(CBWPARAM, 8)
   END SELECT

END FUNCTION

FUNCTION PBMAIN

   DIM hDlg AS LOCAL DWORD

   DIALOG NEW 0, "Balloon Text", , , 200, 95, %DS_MODALFRAME OR %DS_SETFOREGROUND OR %DS_CENTER OR _
      %WS_VISIBLE OR %WS_OVERLAPPED OR %WS_SYSMENU OR %WS_CAPTION, 0  TO hDlg

   DIALOG SHOW MODAL hDlg CALL DlgProc

END FUNCTION
