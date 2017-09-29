' ########################################################################################
' Microsoft Windows
' File: WinUser.inc
' Contents: USER procedure declarations, constant definitions and macros
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Note: windows.inc must be included before this file, but can't be done here.
' You must do it in your application.

#INCLUDE THIS ONCE
%WINUSER_INC = 1

'//
'// Define API decoration for direct importing of DLL references.
'//

'#ifndef WINVER
'#define WINVER  0x0500      /* version 5.0 */
'#endif /* !WINVER */

'#include <stdarg.h>

'#IF NOT %DEF(%NOUSER) ' -------------------------------------------------------
'#ifndef NOUSER

'typedef HANDLE HDWP;
'typedef VOID MENUTEMPLATEA;
'typedef VOID MENUTEMPLATEW;

'typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

'typedef INT_PTR (CALLBACK* DLGPROC)(HWND, UINT, WPARAM, LPARAM);
'typedef VOID (CALLBACK* TIMERPROC)(HWND, UINT, UINT_PTR, DWORD);
'typedef BOOL (CALLBACK* GRAYSTRINGPROC)(HDC, LPARAM, int);
'typedef BOOL (CALLBACK* WNDENUMPROC)(HWND, LPARAM);
'typedef LRESULT (CALLBACK* HOOKPROC)(int code, WPARAM wParam, LPARAM lParam);
'typedef VOID (CALLBACK* SENDASYNCPROC)(HWND, UINT, ULONG_PTR, LRESULT);

'typedef BOOL (CALLBACK* PROPENUMPROCA)(HWND, LPCSTR, HANDLE);
'typedef BOOL (CALLBACK* PROPENUMPROCW)(HWND, LPCWSTR, HANDLE);

'typedef BOOL (CALLBACK* PROPENUMPROCEXA)(HWND, LPSTR, HANDLE, ULONG_PTR);
'typedef BOOL (CALLBACK* PROPENUMPROCEXW)(HWND, LPWSTR, HANDLE, ULONG_PTR);

'typedef int (CALLBACK* EDITWORDBREAKPROCA)(LPSTR lpch, int ichCurrent, int cch, int code);
'typedef int (CALLBACK* EDITWORDBREAKPROCW)(LPWSTR lpch, int ichCurrent, int cch, int code);

'#if(WINVER >= 0x0400)
'typedef BOOL (CALLBACK* DRAWSTATEPROC)(HDC hdc, LPARAM lData, WPARAM wData, int cx, int cy);
'#endif /* WINVER >= 0x0400 */
'#else /* !STRICT */

'#define IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16) == 0)
'#define MAKEINTRESOURCEA(i) ((LPSTR)((ULONG_PTR)((WORD)(i))))
'#define MAKEINTRESOURCEW(i) ((LPWSTR)((ULONG_PTR)((WORD)(i))))

FUNCTION IS_INTRESOURCE (BYVAL dwInteger AS DWORD) AS LONG
   SHIFT RIGHT dwInteger, 16
   FUNCTION = (dwInteger = 0)
END FUNCTION
FUNCTION MAKEINTRESOURCEA (BYVAL wInteger AS WORD) AS DWORD
   FUNCTION = MAK(DWORD, wInteger, 0)
END FUNCTION
FUNCTION MAKEINTRESOURCEW (BYVAL wInteger AS WORD) AS DWORD
   FUNCTION = MAK(DWORD, wInteger, 0)
END FUNCTION

#IF %DEF(%UNICODE)
   MACRO MAKEINTRESOURCE = MAKEINTRESOURCEW
#ELSE
   MACRO MAKEINTRESOURCE = MAKEINTRESOURCEA
#ENDIF

'/*
' * Queue status flags for GetQueueStatus() and MsgWaitForMultipleObjects()
' */
%QS_KEY            = &H0001???
%QS_MOUSEMOVE      = &H0002???
%QS_MOUSEBUTTON    = &H0004???
%QS_POSTMESSAGE    = &H0008???
%QS_TIMER          = &H0010???
%QS_PAINT          = &H0020???
%QS_SENDMESSAGE    = &H0040???
%QS_HOTKEY         = &H0080???
%QS_ALLPOSTMESSAGE = &H0100???
'#if(_WIN32_WINNT >= 0x0501)
%QS_RAWINPUT       = &H0400???
'#endif /* _WIN32_WINNT >= 0x0501 */

%QS_MOUSE          = %QS_MOUSEMOVE OR %QS_MOUSEBUTTON

'#if (_WIN32_WINNT >= 0x0501)
'#define QS_INPUT           (QS_MOUSE         | \
'                            QS_KEY           | \
'                            QS_RAWINPUT)
'#else
'#define QS_INPUT           (QS_MOUSE         | \
'                            QS_KEY)
'#endif // (_WIN32_WINNT >= 0x0501)

#IF %WINVER >= &H0501
%QS_INPUT          = %QS_MOUSE OR %QS_KEY OR %QS_RAWINPUT ' Windows XP and later
#ELSE
%QS_INPUT          = %QS_MOUSE OR %QS_KEY
#ENDIF

%QS_ALLEVENTS      = %QS_INPUT OR %QS_POSTMESSAGE OR %QS_TIMER OR %QS_PAINT OR %QS_HOTKEY

%QS_ALLINPUT       = %QS_INPUT OR %QS_POSTMESSAGE OR %QS_TIMER OR %QS_PAINT OR %QS_HOTKEY OR %QS_SENDMESSAGE

%USER_TIMER_MAXIMUM  = &H7FFFFFFF???
%USER_TIMER_MINIMUM  = &H0000000A???

'#IF NOT %DEF(%NORESOURCE) ' ---------------------------------------------------
'#ifndef NORESOURCE

'/*
' * Predefined Resource Types
' */
'#define RT_CURSOR           MAKEINTRESOURCE(1)
'#define RT_BITMAP           MAKEINTRESOURCE(2)
'#define RT_ICON             MAKEINTRESOURCE(3)
'#define RT_MENU             MAKEINTRESOURCE(4)
'#define RT_DIALOG           MAKEINTRESOURCE(5)
'#define RT_STRING           MAKEINTRESOURCE(6)
'#define RT_FONTDIR          MAKEINTRESOURCE(7)
'#define RT_FONT             MAKEINTRESOURCE(8)
'#define RT_ACCELERATOR      MAKEINTRESOURCE(9)
'#define RT_RCDATA           MAKEINTRESOURCE(10)
'#define RT_MESSAGETABLE     MAKEINTRESOURCE(11)

%RT_CURSOR       = 1??
%RT_BITMAP       = 2??
%RT_ICON         = 3??
%RT_MENU         = 4??
%RT_DIALOG       = 5??
%RT_STRING       = 6??
%RT_FONTDIR      = 7??
%RT_FONT         = 8??
%RT_ACCELERATOR  = 9??
%RT_RCDATA       = 10??
%RT_MESSAGETABLE = 11??

'#define DIFFERENCE     11
'#define RT_GROUP_CURSOR MAKEINTRESOURCE((ULONG_PTR)RT_CURSOR + DIFFERENCE)
'#define RT_GROUP_ICON   MAKEINTRESOURCE((ULONG_PTR)RT_ICON + DIFFERENCE)
'#define RT_VERSION      MAKEINTRESOURCE(16)
'#define RT_DLGINCLUDE   MAKEINTRESOURCE(17)
'#if(WINVER >= 0x0400)
'#define RT_PLUGPLAY     MAKEINTRESOURCE(19)
'#define RT_VXD          MAKEINTRESOURCE(20)
'#define RT_ANICURSOR    MAKEINTRESOURCE(21)
'#define RT_ANIICON      MAKEINTRESOURCE(22)
'#endif /* WINVER >= 0x0400 */
'#define RT_HTML         MAKEINTRESOURCE(23)
'#ifdef RC_INVOKED
'#define RT_MANIFEST                        24
'#define CREATEPROCESS_MANIFEST_RESOURCE_ID  1
'#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID 2
'#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID 3
'#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID 1   /* inclusive */
'#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID 16  /* inclusive */
'#else  /* RC_INVOKED */
'#define RT_MANIFEST                        MAKEINTRESOURCE(24)
'#define CREATEPROCESS_MANIFEST_RESOURCE_ID MAKEINTRESOURCE( 1)
'#define ISOLATIONAWARE_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(2)
'#define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(3)
'#define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE( 1 /*inclusive*/)
'#define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID MAKEINTRESOURCE(16 /*inclusive*/)
'#endif /* RC_INVOKED */

%DIFFERENCE      = 11??
%RT_GROUP_CURSOR = 12??
%RT_GROUP_ICON   = 14??
%RT_VERSION      = 16??
%RT_DLGINCLUDE   = 17??
%RT_PLUGPLAY     = 19??
%RT_VXD          = 20??
%RT_ANICURSOR    = 21??
%RT_ANIICON      = 22??
%RT_HTML         = 23??
%RT_MANIFEST     = 24??
%CREATEPROCESS_MANIFEST_RESOURCE_ID  = 1??
%ISOLATIONAWARE_MANIFEST_RESOURCE_ID = 2??
%ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID = 3??
%MINIMUM_RESERVED_MANIFEST_RESOURCE_ID = 1??    ' /* inclusive */
%MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID = 16??  ' /* inclusive */
'#ENDIF ' #IF NOT %DEF(%NORESOURCE) --------------------------------------------

DECLARE FUNCTION wvsprintfA IMPORT "USER32.DLL" ALIAS "wvsprintfA" ( _
   BYREF lpOutput AS ASCIIZ _                           ' __out LPSTR lpOutput
 , BYREF lpFmt AS ASCIIZ _                              ' __in LPCSTR lpFmt
 , BYREF arglist AS ANY _                               ' __in va_list arglist
 ) AS LONG                                              ' int

' Usage example:
' DIM rgArgs(1) AS DWORD
' LOCAL wszOut AS WSTRINGZ * 1024
' LOCAL wszName AS WSTRINGZ * 260
' wszName = "John Doe"
' rgArgs(0) = VARPTR(wszName)
' rgArgs(1) = 23
' wvsprintfW(wszOut, "Hi, my mane is %s and I'm %lu years old", rgArgs(0))
' ? wszOut
DECLARE FUNCTION wvsprintfW IMPORT "USER32.DLL" ALIAS "wvsprintfW" ( _
   BYREF lpOutput AS WSTRINGZ _                         ' __out LPWSTR lpOutput
 , BYREF lpFmt AS WSTRINGZ _                            ' __in LPCWSTR lpFmt
 , BYREF arglist AS ANY _                               ' __in va_list arglist
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO wvsprintf = wvsprintfW
#ELSE
   MACRO wvsprintf = wvsprintfA
#ENDIF

DECLARE FUNCTION wsprintfA CDECL IMPORT "USER32.DLL" ALIAS "wsprintfA" ( _
   BYREF lpOut AS ASCIIZ _                              ' __out LPSTR lpOut
 , BYREF lpFmt AS ASCIIZ _                              ' __in LPCSTR lpFmt
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

' Usage example:
' LOCAL wszOut AS WSTRINGZ * 1024
' LOCAL wszName AS WSTRINGZ * 260
' wszName = "John Doe"
' wsprintfW(wszOut, "Hi, my mane is %s and I'm %lu years old", wszName, BYVAL 23)
' ? wszOut
DECLARE FUNCTION wsprintfW CDECL IMPORT "USER32.DLL" ALIAS "wsprintfW" ( _
   BYREF lpOut AS WSTRINGZ _                            ' __out LPWSTR lpOut
 , BYREF lpFmt AS WSTRINGZ _                            ' __in LPCWSTR lpFmt
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO wsprintf = wsprintfW
#ELSE
   MACRO wsprintf = wsprintfA
#ENDIF

'/*
' * SPI_SETDESKWALLPAPER defined constants
' */
'#define SETWALLPAPER_DEFAULT    ((LPWSTR)-1)
%SETWALLPAPER_DEFAULT = &HFFFFFFFF???

'#IF NOT %DEF(%NOSCROLL) '------------------------------------------------------
'#ifndef NOSCROLL

'/*
' * Scroll Bar Constants
' */
'%SB_HORZ = 0&
'%SB_VERT = 1&
'%SB_CTL  = 2&
'%SB_BOTH = 3&

'/*
' * Scroll Bar Commands
' */
'%SB_LINEUP        = 0&
'%SB_LINELEFT      = 0&
'%SB_LINEDOWN      = 1&
'%SB_LINERIGHT     = 1&
'%SB_PAGEUP        = 2&
'%SB_PAGELEFT      = 2&
'%SB_PAGEDOWN      = 3&
'%SB_PAGERIGHT     = 3&
'%SB_THUMBPOSITION = 4&
'%SB_THUMBTRACK    = 5&
'%SB_TOP           = 6&
'%SB_LEFT          = 6&
'%SB_BOTTOM        = 7&
'%SB_RIGHT         = 7&
'%SB_ENDSCROLL     = 8&

'#endif /* !NOSCROLL */
'#ENDIF ' #IF NOT %DEF(%NOSCROLL) ----------------------------------------------

'#IF NOT %DEF(%NOSHOWWINDOW) '--------------------------------------------------
'#ifndef NOSHOWWINDOW

'/*
' * ShowWindow() Commands
' */
'%SW_HIDE            = 0&
'%SW_SHOWNORMAL      = 1&
'%SW_NORMAL          = 1&
'%SW_SHOWMINIMIZED   = 2&
'%SW_SHOWMAXIMIZED   = 3&
'%SW_MAXIMIZE        = 3&
'%SW_SHOWNOACTIVATE  = 4&
'%SW_SHOW            = 5&
'%SW_MINIMIZE        = 6&
'%SW_SHOWMINNOACTIVE = 7&
'%SW_SHOWNA          = 8&
'%SW_RESTORE         = 9&
'%SW_SHOWDEFAULT     = 10&
'%SW_FORCEMINIMIZE   = 11&
'%SW_MAX             = 11&

'/*
' * Old ShowWindow() Commands
' */
%HIDE_WINDOW         = 0&
%SHOW_OPENWINDOW     = 1&
%SHOW_ICONWINDOW     = 2&
%SHOW_FULLSCREEN     = 3&
%SHOW_OPENNOACTIVATE = 4&

'/*
' * Identifiers for the WM_SHOWWINDOW message
' */
%SW_PARENTCLOSING = 1&
%SW_OTHERZOOM     = 2&
%SW_PARENTOPENING = 3&
%SW_OTHERUNZOOM   = 4&

'#endif /* !NOSHOWWINDOW */
'#ENDIF '#IF NOT %DEF(%NOSHOWWINDOW) '------------------------------------------

'#if(WINVER >= 0x0500)
'/*
' * AnimateWindow() Commands
' */
%AW_HOR_POSITIVE = &H00000001???
%AW_HOR_NEGATIVE = &H00000002???
%AW_VER_POSITIVE = &H00000004???
%AW_VER_NEGATIVE = &H00000008???
%AW_CENTER       = &H00000010???
%AW_HIDE         = &H00010000???
%AW_ACTIVATE     = &H00020000???
%AW_SLIDE        = &H00040000???
%AW_BLEND        = &H00080000???

'#endif /* WINVER >= 0x0500 */


'/*
' * WM_KEYUP/DOWN/CHAR HIWORD(lParam) flags
' */
%KF_EXTENDED = &H0100???
%KF_DLGMODE  = &H0800???
%KF_MENUMODE = &H1000???
%KF_ALTDOWN  = &H2000???
%KF_REPEAT   = &H4000???
%KF_UP       = &H8000???

'#IF NOT %DEF(%NOVIRTUALKEYCODES) '---------------------------------------------
'#ifndef NOVIRTUALKEYCODES

'/*
' * Virtual Keys, Standard Set
' */
%VK_LBUTTON    = &H01&
%VK_RBUTTON    = &H02&
%VK_CANCEL     = &H03&
%VK_MBUTTON    = &H04&    ' NOT contiguous with L RBUTTON

'#if(_WIN32_WINNT >= 0x0500)
%VK_XBUTTON1   = &H05&    ' NOT contiguous with L & RBUTTON
%VK_XBUTTON2   = &H06&    ' NOT contiguous with L & RBUTTON
'#endif /* _WIN32_WINNT >= 0x0500 */

'/*
' * 0x07 : unassigned
' */

%VK_BACK       = &H08&
%VK_TAB        = &H09&

'/*
' * 0x0A - 0x0B : reserved
' */
%VK_LINEFEED   = &H0A&   ' Not defined in the Windows 7 SDK

%VK_CLEAR      = &H0C&
%VK_RETURN     = &H0D&

%VK_SHIFT      = &H10&
%VK_CONTROL    = &H11&
%VK_MENU       = &H12&
%VK_PAUSE      = &H13&
%VK_CAPITAL    = &H14&

%VK_KANA       = &H15&
%VK_HANGEUL    = &H15&  ' old name - should be here for compatibility
%VK_HANGUL     = &H15&
%VK_JUNJA      = &H17&
%VK_FINAL      = &H18&
%VK_HANJA      = &H19&
%VK_KANJI      = &H19&

%VK_ESCAPE     = &H1B&

%VK_CONVERT    = &H1C&
%VK_NONCONVERT = &H1D&
%VK_ACCEPT     = &H1E&
%VK_MODECHANGE = &H1F&

%VK_SPACE      = &H20&
%VK_PGUP       = &H21&
%VK_PRIOR      = &H21&
%VK_NEXT       = &H22&
%VK_PGDN       = &H22&
%VK_END        = &H23&
%VK_HOME       = &H24&
%VK_LEFT       = &H25&
%VK_UP         = &H26&
%VK_RIGHT      = &H27&
%VK_DOWN       = &H28&
%VK_SELECT     = &H29&
%VK_PRINT      = &H2A&
%VK_EXECUTE    = &H2B&
%VK_SNAPSHOT   = &H2C&
%VK_INSERT     = &H2D&
%VK_DELETE     = &H2E&
%VK_HELP       = &H2F&

'/*
' * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
' * 0x40 : unassigned
' * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
' */

%VK_0          = &H30&
%VK_1          = &H31&
%VK_2          = &H32&
%VK_3          = &H33&
%VK_4          = &H34&
%VK_5          = &H35&
%VK_6          = &H36&
%VK_7          = &H37&
%VK_8          = &H38&
%VK_9          = &H39&
%VK_A          = &H41&
%VK_B          = &H42&
%VK_C          = &H43&
%VK_D          = &H44&
%VK_E          = &H45&
%VK_F          = &H46&
%VK_G          = &H47&
%VK_H          = &H48&
%VK_I          = &H49&
%VK_J          = &H4A&
%VK_K          = &H4B&
%VK_L          = &H4C&
%VK_M          = &H4D&
%VK_N          = &H4E&
%VK_O          = &H4F&
%VK_P          = &H50&
%VK_Q          = &H51&
%VK_R          = &H52&
%VK_S          = &H53&
%VK_T          = &H54&
%VK_U          = &H55&
%VK_V          = &H56&
%VK_W          = &H57&
%VK_X          = &H58&
%VK_Y          = &H59&
%VK_Z          = &H5A&

%VK_LWIN       = &H5B&
%VK_RWIN       = &H5C&
%VK_APPS       = &H5D&

'/*
' * 0x5E : reserved
' */

%VK_SLEEP      = &H5F&

%VK_NUMPAD0    = &H60&
%VK_NUMPAD1    = &H61&
%VK_NUMPAD2    = &H62&
%VK_NUMPAD3    = &H63&
%VK_NUMPAD4    = &H64&
%VK_NUMPAD5    = &H65&
%VK_NUMPAD6    = &H66&
%VK_NUMPAD7    = &H67&
%VK_NUMPAD8    = &H68&
%VK_NUMPAD9    = &H69&
%VK_MULTIPLY   = &H6A&
%VK_ADD        = &H6B&
%VK_SEPARATOR  = &H6C&
%VK_SUBTRACT   = &H6D&
%VK_DECIMAL    = &H6E&
%VK_DIVIDE     = &H6F&
%VK_F1         = &H70&
%VK_F2         = &H71&
%VK_F3         = &H72&
%VK_F4         = &H73&
%VK_F5         = &H74&
%VK_F6         = &H75&
%VK_F7         = &H76&
%VK_F8         = &H77&
%VK_F9         = &H78&
%VK_F10        = &H79&
%VK_F11        = &H7A&
%VK_F12        = &H7B&
%VK_F13        = &H7C&
%VK_F14        = &H7D&
%VK_F15        = &H7E&
%VK_F16        = &H7F&
%VK_F17        = &H80&
%VK_F18        = &H81&
%VK_F19        = &H82&
%VK_F20        = &H83&
%VK_F21        = &H84&
%VK_F22        = &H85&
%VK_F23        = &H86&
%VK_F24        = &H87&

'/*
' * 0x88 - 0x8F : unassigned
' */

%VK_NUMLOCK    = &H90&
%VK_SCROLL     = &H91&

'/*
' * NEC PC-9800 kbd definitions
' */
%VK_OEM_NEC_EQUAL  = &H92&   ' "=" key on numpad

'/*
' * Fujitsu/OASYS kbd definitions
' */
%VK_OEM_FJ_JISHO   = &H92&   ' "Dictionary" key
%VK_OEM_FJ_MASSHOU = &H93&   ' "Unregister word" key
%VK_OEM_FJ_TOUROKU = &H94&   ' "Register word" key
%VK_OEM_FJ_LOYA    = &H95&   ' "Left OYAYUBI" key
%VK_OEM_FJ_ROYA    = &H96&   ' "Right OYAYUBI" key

'/*
' * 0x97 - 0x9F : unassigned
' */

'/*
' * VK_L* & VK_R* - left and right Alt, Ctrl and Shift virtual keys.
' * Used only as parameters to GetAsyncKeyState() and GetKeyState().
' * No other API or message will distinguish left and right keys in this way.
' */
%VK_LSHIFT   = &HA0&
%VK_RSHIFT   = &HA1&
%VK_LCONTROL = &HA2&
%VK_RCONTROL = &HA3&
%VK_LMENU    = &HA4&
%VK_RMENU    = &HA5&

'#if(_WIN32_WINNT >= 0x0500)
%VK_BROWSER_BACK        = &HA6&
%VK_BROWSER_FORWARD     = &HA7&
%VK_BROWSER_REFRESH     = &HA8&
%VK_BROWSER_STOP        = &HA9&
%VK_BROWSER_SEARCH      = &HAA&
%VK_BROWSER_FAVORITES   = &HAB&
%VK_BROWSER_HOME        = &HAC&

%VK_VOLUME_MUTE         = &HAD&
%VK_VOLUME_DOWN         = &HAE&
%VK_VOLUME_UP           = &HAF&
%VK_MEDIA_NEXT_TRACK    = &HB0&
%VK_MEDIA_PREV_TRACK    = &HB1&
%VK_MEDIA_STOP          = &HB2&
%VK_MEDIA_PLAY_PAUSE    = &HB3&
%VK_LAUNCH_MAIL         = &HB4&
%VK_LAUNCH_MEDIA_SELECT = &HB5&
%VK_LAUNCH_APP1         = &HB6&
%VK_LAUNCH_APP2         = &HB7&

'#endif /* _WIN32_WINNT >= 0x0500 */

'/*
' * 0xB8 - 0xB9 : reserved
' */

%VK_OEM_1        = &HBA&   ' ";:" for US
%VK_OEM_PLUS     = &HBB&   ' "+" any country
%VK_OEM_COMMA    = &HBC&   ' "," any country
%VK_OEM_MINUS    = &HBD&   ' "-" any country
%VK_OEM_PERIOD   = &HBE&   ' "." any country
%VK_OEM_2        = &HBF&   ' "/?" for US
%VK_OEM_3        = &HC0&   ' "`~" for US

'/*
' * 0xC1 - 0xD7 : reserved
' */

'/*
' * 0xD8 - 0xDA : unassigned
' */

%VK_OEM_4        = &HDB&  ' "[{" for US
%VK_OEM_5        = &HDC&  ' "\|" for US
%VK_OEM_6        = &HDD&  ' "]}" for US
%VK_OEM_7        = &HDE&  ' """" for US
%VK_OEM_8        = &HDF&

'/*
' * 0xE0 : reserved
' */

'/*
' * Various extended or enhanced keyboards
' */
%VK_OEM_AX       = &HE1&  ' "AX" key on Japanese AX kbd
%VK_OEM_102      = &HE2&  ' "<>" or "\|" on RT 102-key kbd.
%VK_ICO_HELP     = &HE3&  ' Help key on ICO
%VK_ICO_00       = &HE4&  ' 00 key on ICO

'#if(WINVER >= 0x0400)
%VK_PROCESSKEY   = &HE5&
'#endif /* WINVER >= 0x0400 */

%VK_ICO_CLEAR    = &HE6


'#if(_WIN32_WINNT >= 0x0500)
%VK_PACKET       = &HE7&
'#endif /* _WIN32_WINNT >= 0x0500 */

'/*
' * 0xE8 : unassigned
' */

'/*
' * Nokia/Ericsson definitions
' */
%VK_OEM_RESET    = &HE9&
%VK_OEM_JUMP     = &HEA&
%VK_OEM_PA1      = &HEB&
%VK_OEM_PA2      = &HEC&
%VK_OEM_PA3      = &HED&
%VK_OEM_WSCTRL   = &HEE&
%VK_OEM_CUSEL    = &HEF&
%VK_OEM_ATTN     = &HF0&
%VK_OEM_FINISH   = &HF1&
%VK_OEM_COPY     = &HF2&
%VK_OEM_AUTO     = &HF3&
%VK_OEM_ENLW     = &HF4&
%VK_OEM_BACKTAB  = &HF5&

%VK_ATTN         = &HF6&
%VK_CRSEL        = &HF7&
%VK_EXSEL        = &HF8&
%VK_EREOF        = &HF9&
%VK_PLAY         = &HFA&
%VK_ZOOM         = &HFB&
%VK_NONAME       = &HFC&
%VK_PA1          = &HFD&
%VK_OEM_CLEAR    = &HFE&

'/*
' * 0xFF : reserved
' */

'#endif /* !NOVIRTUALKEYCODES */
'#ENDIF '#IF NOT %DEF(%NOVIRTUALKEYCODES) '-------------------------------------

'#IF NOT %DEF(%NOWH) '---------------------------------------------
'#ifndef NOWH

'/*
' * SetWindowsHook() codes
' */
%WH_MIN             = -1&
%WH_MSGFILTER       = -1&
%WH_JOURNALRECORD   = 0&
%WH_JOURNALPLAYBACK = 1&
%WH_KEYBOARD        = 2&
%WH_GETMESSAGE      = 3&
%WH_CALLWNDPROC     = 4&
%WH_CBT             = 5&
%WH_SYSMSGFILTER    = 6&
%WH_MOUSE           = 7&

'#if defined(_WIN32_WINDOWS)
%WH_HARDWARE        = 8&
'#endif

%WH_DEBUG           = 9&
%WH_SHELL           = 10&
%WH_FOREGROUNDIDLE  = 11&

'#if(WINVER >= 0x0400)
%WH_CALLWNDPROCRET  = 12&
'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0400)
%WH_KEYBOARD_LL     = 13&
%WH_MOUSE_LL        = 14&
'#endif // (_WIN32_WINNT >= 0x0400)

'#if(WINVER >= 0x0400)
'#if (_WIN32_WINNT >= 0x0400)
'#define WH_MAX             14
'#else
'#define WH_MAX             12
'#endif // (_WIN32_WINNT >= 0x0400)
'#else
'#define WH_MAX             11
'#endif
%WH_MAX             = 14&   ' depending on Windows version

%WH_MINHOOK         = %WH_MIN
%WH_MAXHOOK         = %WH_MAX

'/*
' * Hook Codes
' */
%HC_ACTION      = 0&
%HC_GETNEXT     = 1&
%HC_SKIP        = 2&
%HC_NOREMOVE    = 3&
%HC_NOREM       = %HC_NOREMOVE
%HC_SYSMODALON  = 4&
%HC_SYSMODALOFF = 5&

'/*
' * CBT Hook Codes
' */
%HCBT_MOVESIZE     = 0&
%HCBT_MINMAX       = 1&
%HCBT_QS           = 2&
%HCBT_CREATEWND    = 3&
%HCBT_DESTROYWND   = 4&
%HCBT_ACTIVATE     = 5&
%HCBT_CLICKSKIPPED = 6&
%HCBT_KEYSKIPPED   = 7&
%HCBT_SYSCOMMAND   = 8&
%HCBT_SETFOCUS     = 9&

'/*
' * HCBT_ACTIVATE structure pointed to by lParam
' */

' // Size = 8 bytes
TYPE CBTACTIVATESTRUCT DWORD
   fMouse     AS LONG    ' BOOL
   hWndActive AS DWORD   ' HWND
END TYPE

'#if(_WIN32_WINNT >= 0x0501)
'/*
' * WTSSESSION_NOTIFICATION struct pointed by lParam, for WM_WTSSESSION_CHANGE
' */

' // Size = 8 bytes
TYPE WTSSESSION_NOTIFICATION DWORD
   cbSize      AS DWORD   ' DWORD
   dwSessionId AS DWORD   ' DWORD
END TYPE

'/*
' * codes passed in WPARAM for WM_WTSSESSION_CHANGE
' */

%WTS_CONSOLE_CONNECT        = 1&
%WTS_CONSOLE_DISCONNECT     = 2&
%WTS_REMOTE_CONNECT         = 3&
%WTS_REMOTE_DISCONNECT      = 4&
%WTS_SESSION_LOGON          = 5&
%WTS_SESSION_LOGOFF         = 6&
%WTS_SESSION_LOCK           = 7&
%WTS_SESSION_UNLOCK         = 8&
%WTS_SESSION_REMOTE_CONTROL = 9&

'#endif /* _WIN32_WINNT >= 0x0501 */

'/*
' * WH_MSGFILTER Filter Proc Codes
' */
%MSGF_DIALOGBOX  = 0&
%MSGF_MESSAGEBOX = 1&
%MSGF_MENU       = 2&
%MSGF_MOVE       = 3&
%MSGF_SIZE       = 4&
%MSGF_SCROLLBAR  = 5&
%MSGF_NEXTWINDOW = 6&
%MSGF_MAX        = 8&
%MSGF_USER       = 4096&

'/*
' * Shell support
' */
%HSHELL_WINDOWCREATED       = 1&
%HSHELL_WINDOWDESTROYED     = 2&
%HSHELL_ACTIVATESHELLWINDOW = 3&

'#if(WINVER >= 0x0400)
%HSHELL_WINDOWACTIVATED     = 4&
%HSHELL_GETMINRECT          = 5&
%HSHELL_REDRAW              = 6&
%HSHELL_TASKMAN             = 7&
%HSHELL_LANGUAGE            = 8&
%HSHELL_SYSMENU             = 9&
%HSHELL_ENDTASK             = 10&

'#endif /* WINVER >= 0x0400 */
'#if(_WIN32_WINNT >= 0x0500)
%HSHELL_ACCESSIBILITYSTATE  = 11&
%HSHELL_APPCOMMAND          = 12&
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)
%HSHELL_WINDOWREPLACED      = 13&
%HSHELL_WINDOWREPLACING     = 14&
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0602)   ' // Windows 8
'#define HSHELL_MONITORCHANGED 16
'#endif /* _WIN32_WINNT >= 0x0602 */
%HSHELL_MONITORCHANGED = 16&

%HSHELL_HIGHBIT            = &H8000???
%HSHELL_FLASH              = %HSHELL_REDRAW OR %HSHELL_HIGHBIT
%HSHELL_RUDEAPPACTIVATED   = %HSHELL_WINDOWACTIVATED OR %HSHELL_HIGHBIT

'#if(_WIN32_WINNT >= 0x0500)
'/* wparam for HSHELL_ACCESSIBILITYSTATE */
%ACCESS_STICKYKEYS = &H0001???
%ACCESS_FILTERKEYS = &H0002???
%ACCESS_MOUSEKEYS  = &H0003???


%APPCOMMAND_BROWSER_BACKWARD       = 1&
%APPCOMMAND_BROWSER_FORWARD        = 2&
%APPCOMMAND_BROWSER_REFRESH        = 3&
%APPCOMMAND_BROWSER_STOP           = 4&
%APPCOMMAND_BROWSER_SEARCH         = 5&
%APPCOMMAND_BROWSER_FAVORITES      = 6&
%APPCOMMAND_BROWSER_HOME           = 7&
%APPCOMMAND_VOLUME_MUTE            = 8&
%APPCOMMAND_VOLUME_DOWN            = 9&
%APPCOMMAND_VOLUME_UP              = 10&
%APPCOMMAND_MEDIA_NEXTTRACK        = 11&
%APPCOMMAND_MEDIA_PREVIOUSTRACK    = 12&
%APPCOMMAND_MEDIA_STOP             = 13&
%APPCOMMAND_MEDIA_PLAY_PAUSE       = 14&
%APPCOMMAND_LAUNCH_MAIL            = 15&
%APPCOMMAND_LAUNCH_MEDIA_SELECT    = 16&
%APPCOMMAND_LAUNCH_APP1            = 17&
%APPCOMMAND_LAUNCH_APP2            = 18&
%APPCOMMAND_BASS_DOWN              = 19&
%APPCOMMAND_BASS_BOOST             = 20&
%APPCOMMAND_BASS_UP                = 21&
%APPCOMMAND_TREBLE_DOWN            = 22&
%APPCOMMAND_TREBLE_UP              = 23&
'#if(_WIN32_WINNT >= 0x0501)
%APPCOMMAND_MICROPHONE_VOLUME_MUTE = 24&
%APPCOMMAND_MICROPHONE_VOLUME_DOWN = 25&
%APPCOMMAND_MICROPHONE_VOLUME_UP   = 26&
%APPCOMMAND_HELP                   = 27&
%APPCOMMAND_FIND                   = 28&
%APPCOMMAND_NEW                    = 29&
%APPCOMMAND_OPEN                   = 30&
%APPCOMMAND_CLOSE                  = 31&
%APPCOMMAND_SAVE                   = 32&
%APPCOMMAND_PRINT                  = 33&
%APPCOMMAND_UNDO                   = 34&
%APPCOMMAND_REDO                   = 35&
%APPCOMMAND_COPY                   = 36&
%APPCOMMAND_CUT                    = 37&
%APPCOMMAND_PASTE                  = 38&
%APPCOMMAND_REPLY_TO_MAIL          = 39&
%APPCOMMAND_FORWARD_MAIL           = 40&
%APPCOMMAND_SEND_MAIL              = 41&
%APPCOMMAND_SPELL_CHECK            = 42&
%APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE = 43&
%APPCOMMAND_MIC_ON_OFF_TOGGLE      = 44&
%APPCOMMAND_CORRECTION_LIST        = 45&
%APPCOMMAND_MEDIA_PLAY             = 46&
%APPCOMMAND_MEDIA_PAUSE            = 47&
%APPCOMMAND_MEDIA_RECORD           = 48&
%APPCOMMAND_MEDIA_FAST_FORWARD     = 49&
%APPCOMMAND_MEDIA_REWIND           = 50&
%APPCOMMAND_MEDIA_CHANNEL_UP       = 51&
%APPCOMMAND_MEDIA_CHANNEL_DOWN     = 52&
'#endif /* _WIN32_WINNT >= 0x0501 */
'#if(_WIN32_WINNT >= 0x0600)
%APPCOMMAND_DELETE                 = 53&
%APPCOMMAND_DWM_FLIP3D             = 54&
'#endif /* _WIN32_WINNT >= 0x0600 */

%FAPPCOMMAND_MOUSE = &H8000??
%FAPPCOMMAND_KEY   = 0??
%FAPPCOMMAND_OEM   = &H1000??
%FAPPCOMMAND_MASK  = &HF000??

'#define GET_APPCOMMAND_LPARAM(lParam) ((short)(HIWORD(lParam) & ~FAPPCOMMAND_MASK))
'#define GET_DEVICE_LPARAM(lParam)     ((WORD)(HIWORD(lParam) & FAPPCOMMAND_MASK))
'#define GET_MOUSEORKEY_LPARAM         GET_DEVICE_LPARAM
'#define GET_FLAGS_LPARAM(lParam)      (LOWORD(lParam))
'#define GET_KEYSTATE_LPARAM(lParam)   GET_FLAGS_LPARAM(lParam)

MACRO GET_APPCOMMAND_LPARAM(lParam) = BITS%(HI(WORD, lParam) AND (NOT %FAPPCOMMAND_MASK))
MACRO GET_DEVICE_LPARAM(lParam)     = BITS??(HI(WORD, lParam) AND %FAPPCOMMAND_MASK))
MACRO GET_MOUSEORKEY_LPARAM         = GET_DEVICE_LPARAM
MACRO GET_FLAGS_LPARAM(lParam)      = LO(WORD, lParam)
MACRO GET_KEYSTATE_LPARAM(lParam)   = GET_FLAGS_LPARAM(lParam)

'#endif /* _WIN32_WINNT >= 0x0500 */

' // Size = 20 bytes
TYPE SHELLHOOKINFO DWORD
   hwnd AS DWORD   ' HWND
   rc   AS RECT    ' RECT
END TYPE

'/*
' * Message Structure used in Journaling
' */

UNION EVENTMSG_TIME_UNION
   time    AS DWORD   ' DWORD
   ' // For compatibility with the PB includes
   dtime   AS DWORD   ' DWORD
END UNION

' // Size = 20 bytes
TYPE EVENTMSG DWORD
   message AS DWORD   ' UINT
   paramL  AS DWORD   ' UINT
   paramH  AS DWORD   ' UINT
   EVENTMSG_TIME_UNION
   hwnd    AS DWORD   ' HWND
END TYPE

'/*
' * Message structure used by WH_CALLWNDPROC
' */

' // Size = 16 bytes
TYPE CWPSTRUCT DWORD
   lParam  AS LONG    ' LPARAM
   wParam  AS LONG    ' WPARAM
   message AS DWORD   ' UINT
   hwnd    AS DWORD   ' HWND
END TYPE

'#if(WINVER >= 0x0400)
'/*
' * Message structure used by WH_CALLWNDPROCRET
' */

' // Size = 20 bytes
TYPE CWPRETSTRUCT DWORD
   lResult AS LONG    ' LRESULT
   lParam  AS LONG    ' LPARAM
   wParam  AS DWORD   ' WPARAM
   message AS DWORD   ' UINT
   hwnd    AS DWORD   ' HWND
END TYPE

'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0400)

'/*
' * Low level hook flags
' */

'#define LLKHF_EXTENDED       (KF_EXTENDED >> 8)
'#define LLKHF_INJECTED       0x00000010
'#define LLKHF_ALTDOWN        (KF_ALTDOWN >> 8)
'#define LLKHF_UP             (KF_UP >> 8)

%LLKHF_EXTENDED = &H00000001???
%LLKHF_INJECTED = &H00000010???
%LLKHF_ALTDOWN  = &H00000020???
%LLKHF_UP       = &H00000080???

%LLMHF_INJECTED = &H00000001???

'/*
' * Structure used by WH_KEYBOARD_LL
' */

' // Size = 20 bytes
TYPE KBDLLHOOKSTRUCT DWORD
   vkCode      AS DWORD   ' DWORD
   scanCode    AS DWORD   ' DWORD
   flags       AS DWORD   ' DWORD
   time        AS DWORD   ' DWORD
   dwExtraInfo AS DWORD   ' ULONG_PTR
END TYPE

'/*
' * Structure used by WH_MOUSE_LL
' */

' // Size = 24 bytes
TYPE MSLLHOOKSTRUCT DWORD
   pt          AS POINT   ' POINT     pt
   mouseData   AS DWORD   ' DWORD     mouseData
   flags       AS DWORD   ' DWORD     flags
   time        AS DWORD   ' DWORD     time
   dwExtraInfo AS DWORD   ' ULONG_PTR dwExtraInfo
END TYPE

'#endif // (_WIN32_WINNT >= 0x0400)

'/*
' * Structure used by WH_DEBUG
' */

' // Size = 20 bytes
TYPE DEBUGHOOKINFO DWORD
   idThread          AS DWORD   ' DWORD
   idThreadInstaller AS DWORD   ' DWORD
   lParam            AS LONG    ' LPARAM
   wParam            AS DWORD   ' WPARAM
   code              AS LONG    ' int
END TYPE

'/*
' * Structure used by WH_MOUSE
' */

' // Size = 20 bytes
TYPE MOUSEHOOKSTRUCT DWORD
   pt           AS POINT   ' POINT
   hwnd         AS DWORD   ' HWND
   wHitTestCode AS DWORD   ' UINT
   dwExtraInfo  AS DWORD   ' ULONG_PTR
END TYPE

' // Size = 24 bytes
TYPE MOUSEHOOKSTRUCTEX DWORD
   MOUSEHOOKSTRUCT
   mouseData AS DWORD   ' DWORD   mouseData
END TYPE

'#endif
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(WINVER >= 0x0400)
'/*
' * Structure used by WH_HARDWARE
' */

' // Size = 16 bytes
TYPE HARDWAREHOOKSTRUCT DWORD
   hwnd    AS DWORD   ' HWND
   message AS DWORD   ' UINT
   wParam  AS DWORD   ' WPARAM
   lParam  AS LONG    ' LPARAM
END TYPE

'#endif /* WINVER >= 0x0400 */
'#endif /* !NOWH */

'#ENDIF '#IF NOT %DEF(%NOWH) '-------------------------------------

'/*
' * Keyboard Layout API
' */

%HKL_PREV = 0???
%HKL_NEXT = 1???

%KLF_ACTIVATE       = &H00000001???
%KLF_SUBSTITUTE_OK  = &H00000002???
%KLF_UNLOADPREVIOUS = &H00000004???
%KLF_REORDER        = &H00000008???
'#if(WINVER >= 0x0400)
%KLF_REPLACELANG    = &H00000010???
%KLF_NOTELLSHELL    = &H00000080???
'#endif /* WINVER >= 0x0400 */
'#endif /* WINVER >= 0x0400 */
%KLF_SETFORPROCESS  = &H00000100???
%KLF_SHIFTLOCK      = &H00010000???
%KLF_RESET          = &H40000000???
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(WINVER >= 0x0500)
'/*
' * Bits in wParam of WM_INPUTLANGCHANGEREQUEST message
' */
%INPUTLANGCHANGE_SYSCHARSET = &H0001???
%INPUTLANGCHANGE_FORWARD    = &H0002???
%INPUTLANGCHANGE_BACKWARD   = &H0004???
'#endif /* WINVER >= 0x0500 */

'/*
' * Size of KeyboardLayoutName (number of characters), including nul terminator
' */
%KL_NAMELENGTH = 9

DECLARE FUNCTION LoadKeyboardLayoutA IMPORT "USER32.DLL" ALIAS "LoadKeyboardLayoutA" ( _
   BYREF pwszKLID AS ASCIIZ _                           ' __in LPCSTR pwszKLID
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HKL

DECLARE FUNCTION LoadKeyboardLayoutW IMPORT "USER32.DLL" ALIAS "LoadKeyboardLayoutW" ( _
   BYREF pwszKLID AS WSTRINGZ _                         ' __in LPCWSTR pwszKLID
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HKL

#IF %DEF(%UNICODE)
   MACRO LoadKeyboardLayout = LoadKeyboardLayoutW
#ELSE
   MACRO LoadKeyboardLayout = LoadKeyboardLayoutA
#ENDIF

DECLARE FUNCTION ActivateKeyboardLayout IMPORT "USER32.DLL" ALIAS "ActivateKeyboardLayout" ( _
   BYVAL hkl AS DWORD _                                 ' __in HKL hkl
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HKL

'#if(WINVER >= 0x0400)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ToUnicodeEx LIB "User32.dll" ALIAS "ToUnicodeEx" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, pwszBuff AS WSTRINGZ, _
    BYVAL cchBuff AS LONG, BYVAL uFlags AS DWORD, _
    OPTIONAL BYVAL dwhkl AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ToUnicodeEx IMPORT "USER32.DLL" ALIAS "ToUnicodeEx" ( _
   BYVAL wVirtKey AS DWORD _                            ' __in UINT wVirtKey
 , BYVAL wScanCode AS DWORD _                           ' __in UINT wScanCode
 , BYREF lpKeyState AS BYTE _                           ' __in_bcount(256) CONST BYTE *lpKeyState
 , BYREF pwszBuff AS WSTRINGZ _                         ' __out LPWSTR pwszBuff
 , BYVAL cchBuff AS LONG _                              ' __in int cchBuff
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 , OPTIONAL BYVAL dwhkl AS DWORD _                      ' __in_opt HKL dwhkl
 ) AS LONG                                              ' int
#ENDIF
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION UnloadKeyboardLayout IMPORT "USER32.DLL" ALIAS "UnloadKeyboardLayout" ( _
   BYVAL hkl AS DWORD _                                 ' __in HKL hkl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetKeyboardLayoutNameA IMPORT "USER32.DLL" ALIAS "GetKeyboardLayoutNameA" ( _
   BYREF pwszKLID AS ASCIIZ _                           ' __out LPSTR pwszKLID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetKeyboardLayoutNameW IMPORT "USER32.DLL" ALIAS "GetKeyboardLayoutNameW" ( _
   BYREF pwszKLID AS WSTRINGZ _                         ' __out LPWSTR pwszKLID
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetKeyboardLayoutName = GetKeyboardLayoutNameW
#ELSE
   MACRO GetKeyboardLayoutName = GetKeyboardLayoutNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetKeyboardLayoutList LIB "User32.dll" _
    ALIAS "GetKeyboardLayoutList" (BYVAL nBuff AS LONG, _
    BYVAL lpList AS DWORD PTR) AS LONG
#ELSE
DECLARE FUNCTION GetKeyboardLayoutList IMPORT "USER32.DLL" ALIAS "GetKeyboardLayoutList" ( _
   BYVAL nBuff AS LONG _                                ' __in int nBuff
 , BYREF lpList AS DWORD _                              ' __out HKL FAR *lpList
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION GetKeyboardLayout IMPORT "USER32.DLL" ALIAS "GetKeyboardLayout" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 ) AS DWORD                                             ' HKL

'#if(WINVER >= 0x0500)

UNION MOUSEMOVEPOINT_TIME_UNION
   time        AS DWORD   ' DWORD
   ' // For compatibility with the PB includes
   dtime       AS DWORD   ' DWORD
END UNION

' // Size = 16 bytes
TYPE MOUSEMOVEPOINT DWORD
   x           AS LONG    ' int
   y           AS LONG    ' int
   MOUSEMOVEPOINT_TIME_UNION
   dwExtraInfo AS DWORD   ' ULONG_PTR
END TYPE

'/*
' * Values for resolution parameter of GetMouseMovePointsEx
' */
%GMMP_USE_DISPLAY_POINTS         = 1&
%GMMP_USE_HIGH_RESOLUTION_POINTS = 2&

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetMouseMovePointsEx LIB "User32.dll" _
    ALIAS "GetMouseMovePointsEx" (BYVAL cbSize AS DWORD, _
    lppt AS MOUSEMOVEPOINT, BYVAL lpptBuf AS MOUSEMOVEPOINT PTR, _
    BYVAL nBufPoints AS LONG, BYVAL resolution AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetMouseMovePointsEx IMPORT "USER32.DLL" ALIAS "GetMouseMovePointsEx" ( _
   BYVAL cbSize AS DWORD _                              ' __in UINT cbSize
 , BYREF lppt AS MOUSEMOVEPOINT _                       ' __in LPMOUSEMOVEPOINT lppt
 , BYREF lpptBuf AS MOUSEMOVEPOINT _                    ' __out LPMOUSEMOVEPOINT lpptBuf
 , BYVAL nBufPoints AS LONG _                           ' __in int nBufPoints
 , BYVAL resolution AS DWORD _                          ' __in DWORD resolution
 ) AS LONG                                              ' int
#ENDIF

'#endif /* WINVER >= 0x0500 */

'#IF NOT %DEF(%NODESKTOP) '----------------------------
'#ifndef NODESKTOP

'/*
' * Desktop-specific access flags
' */
%DESKTOP_READOBJECTS      = &H0001???
%DESKTOP_CREATEWINDOW     = &H0002???
%DESKTOP_CREATEMENU       = &H0004???
%DESKTOP_HOOKCONTROL      = &H0008???
%DESKTOP_JOURNALRECORD    = &H0010???
%DESKTOP_JOURNALPLAYBACK  = &H0020???
%DESKTOP_ENUMERATE        = &H0040???
%DESKTOP_WRITEOBJECTS     = &H0080???
%DESKTOP_SWITCHDESKTOP    = &H0100???

'/*
' * Desktop-specific control flags
' */
%DF_ALLOWOTHERACCOUNTHOOK = &H0001???

'#IF %DEF (%WINGDI_INC)
'#IF NOT %DEF(%NOGDI)
'#ifdef _WINGDI_
'#ifndef NOGDI

DECLARE FUNCTION CreateDesktopA IMPORT "USER32.DLL" ALIAS "CreateDesktopA" ( _
   BYREF lpszDesktop AS ASCIIZ _                        ' __in LPCSTR lpszDesktop
 , BYREF lpszDevice AS ASCIIZ _                         ' __reserved LPCSTR lpszDevice
 , BYREF pDevmode AS DEVMODEA _                         ' __reserved DEVMODEA* pDevmode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , OPTIONAL BYREF lpsa AS SECURITY_ATTRIBUTES _         ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 ) AS DWORD                                             ' HDESK

DECLARE FUNCTION CreateDesktopW IMPORT "USER32.DLL" ALIAS "CreateDesktopW" ( _
   BYREF lpszDesktop AS WSTRINGZ _                      ' __in LPCWSTR lpszDesktop
 , BYREF lpszDevice AS WSTRINGZ _                       ' __reserved LPCWSTR lpszDevice
 , BYREF pDevmode AS DEVMODEW _                         ' __reserved DEVMODEW* pDevmode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , OPTIONAL BYREF lpsa AS SECURITY_ATTRIBUTES _         ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 ) AS DWORD                                             ' HDESK

#IF %DEF(%UNICODE)
   MACRO CreateDesktop = CreateDesktopW
#ELSE
   MACRO CreateDesktop = CreateDesktopA
#ENDIF

DECLARE FUNCTION CreateDesktopExA IMPORT "USER32.DLL" ALIAS "CreateDesktopExA" ( _
   BYREF lpszDesktop AS ASCIIZ _                        ' __in LPCSTR lpszDesktop
 , BYREF lpszDevice AS ASCIIZ _                         ' __reserved LPCSTR lpszDevice
 , BYREF pDevmode AS DEVMODEA _                         ' __reserved DEVMODEA* pDevmode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , BYREF lpsa AS SECURITY_ATTRIBUTES _                  ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 , BYVAL ulHeapSize AS DWORD _                          ' __in ULONG ulHeapSize
 , BYVAL pvoid AS DWORD _                               ' __reserved PVOID pvoid
 ) AS DWORD                                             ' HDESK

DECLARE FUNCTION CreateDesktopExW IMPORT "USER32.DLL" ALIAS "CreateDesktopExW" ( _
   BYREF lpszDesktop AS WSTRINGZ _                      ' __in LPCWSTR lpszDesktop
 , BYREF lpszDevice AS WSTRINGZ _                       ' __reserved LPCWSTR lpszDevice
 , BYREF pDevmode AS DEVMODEW _                         ' __reserved DEVMODEW* pDevmode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , BYREF lpsa AS SECURITY_ATTRIBUTES _                  ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 , BYVAL ulHeapSize AS DWORD _                          ' __in ULONG ulHeapSize
 , BYVAL pvoid AS DWORD _                               ' __reserved PVOID pvoid
 ) AS DWORD                                             ' HDESK

#IF %DEF(%UNICODE)
   MACRO CreateDesktopEx = CreateDesktopExW
#ELSE
   MACRO CreateDesktopEx = CreateDesktopExA
#ENDIF

'#endif /* NOGDI */
'#endif /* _WINGDI_ */

'#ENDIF    ' /* %NOGDI */
'#ENDIF    ' /* %WINGDI_INC */

DECLARE FUNCTION OpenDesktopA IMPORT "USER32.DLL" ALIAS "OpenDesktopA" ( _
   BYREF lpszDesktop AS ASCIIZ _                        ' __in LPCSTR lpszDesktop
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL fInherit AS LONG _                             ' __in BOOL fInherit
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 ) AS DWORD                                             ' HDESK

DECLARE FUNCTION OpenDesktopW IMPORT "USER32.DLL" ALIAS "OpenDesktopW" ( _
   BYREF lpszDesktop AS WSTRINGZ _                      ' __in LPCWSTR lpszDesktop
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL fInherit AS LONG _                             ' __in BOOL fInherit
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 ) AS DWORD                                             ' HDESK

#IF %DEF(%UNICODE)
   MACRO OpenDesktop = OpenDesktopW
#ELSE
   MACRO OpenDesktop = OpenDesktopA
#ENDIF

DECLARE FUNCTION OpenInputDesktop IMPORT "USER32.DLL" ALIAS "OpenInputDesktop" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL fInherit AS LONG _                             ' __in BOOL fInherit
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 ) AS DWORD                                             ' HDESK

DECLARE FUNCTION EnumDesktopsA IMPORT "USER32.DLL" ALIAS "EnumDesktopsA" ( _
   BYVAL hwinsta AS DWORD _                             ' __in_opt HWINSTA hwinsta
 , BYVAL lpEnumFunc AS DWORD _                          ' __in DESKTOPENUMPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDesktopsW IMPORT "USER32.DLL" ALIAS "EnumDesktopsW" ( _
   BYVAL hwinsta AS DWORD _                             ' __in_opt HWINSTA hwinsta
 , BYVAL lpEnumFunc AS DWORD _                          ' __in DESKTOPENUMPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDesktops = EnumDesktopsW
#ELSE
   MACRO EnumDesktops = EnumDesktopsA
#ENDIF

DECLARE FUNCTION EnumDesktopWindows IMPORT "USER32.DLL" ALIAS "EnumDesktopWindows" ( _
   BYVAL hDesktop AS DWORD _                            ' __in_opt HDESK hDesktop
 , BYVAL lpfn AS DWORD _                                ' __in WNDENUMPROC lpfn
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SwitchDesktop IMPORT "USER32.DLL" ALIAS "SwitchDesktop" ( _
   BYVAL hDesktop AS DWORD _                            ' __in HDESK hDesktop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetThreadDesktop IMPORT "USER32.DLL" ALIAS "SetThreadDesktop" ( _
   BYVAL hDesktop AS DWORD _                            ' __in HDESK hDesktop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CloseDesktop IMPORT "USER32.DLL" ALIAS "CloseDesktop" ( _
   BYVAL hDesktop AS DWORD _                            ' __in HDESK hDesktop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetThreadDesktop IMPORT "USER32.DLL" ALIAS "GetThreadDesktop" ( _
   BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 ) AS DWORD                                             ' HDESK

'#endif  /* !NODESKTOP */
'#ENDIF ' #IF NOT %DEF(%NODESKTOP) '-------------------

'#IF NOT %DEF(%NOWINDOWSTATION) '----------------------
'#ifndef NOWINDOWSTATION

'/*
' * Windowstation-specific access flags
' */
%WINSTA_ENUMDESKTOPS      = &H0001???
%WINSTA_READATTRIBUTES    = &H0002???
%WINSTA_ACCESSCLIPBOARD   = &H0004???
%WINSTA_CREATEDESKTOP     = &H0008???
%WINSTA_WRITEATTRIBUTES   = &H0010???
%WINSTA_ACCESSGLOBALATOMS = &H0020???
%WINSTA_EXITWINDOWS       = &H0040???
%WINSTA_ENUMERATE         = &H0100???
%WINSTA_READSCREEN        = &H0200???

%WINSTA_ALL_ACCESS        = %WINSTA_ENUMDESKTOPS OR %WINSTA_READATTRIBUTES OR %WINSTA_ACCESSCLIPBOARD OR _
                            %WINSTA_CREATEDESKTOP OR %WINSTA_WRITEATTRIBUTES OR %WINSTA_ACCESSGLOBALATOMS OR _
                            %WINSTA_EXITWINDOWS OR %WINSTA_ENUMERATE OR %WINSTA_READSCREEN

'/*
' * Windowstation creation flags.
' */
%CWF_CREATE_ONLY          = &H00000001???

'/*
' * Windowstation-specific attribute flags
' */
%WSF_VISIBLE              = &H0001???

DECLARE FUNCTION CreateWindowStationA IMPORT "USER32.DLL" ALIAS "CreateWindowStationA" ( _
   BYREF lpwinsta AS ASCIIZ _                           ' __in_opt LPCSTR lpwinsta
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , OPTIONAL BYREF lpsa AS SECURITY_ATTRIBUTES _         ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 ) AS DWORD                                             ' HWINSTA

DECLARE FUNCTION CreateWindowStationW IMPORT "USER32.DLL" ALIAS "CreateWindowStationW" ( _
   BYREF lpwinsta AS WSTRINGZ _                         ' __in_opt LPCWSTR lpwinsta
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 , OPTIONAL BYREF lpsa AS SECURITY_ATTRIBUTES _         ' __in_opt LPSECURITY_ATTRIBUTES lpsa
 ) AS DWORD                                             ' HWINSTA

#IF %DEF(%UNICODE)
   MACRO CreateWindowStation = CreateWindowStationW
#ELSE
   MACRO CreateWindowStation = CreateWindowStationA
#ENDIF

DECLARE FUNCTION OpenWindowStationA IMPORT "USER32.DLL" ALIAS "OpenWindowStationA" ( _
   BYREF lpszWinSta AS ASCIIZ _                         ' __in LPCSTR lpszWinSta
 , BYVAL fInherit AS LONG _                             ' __in BOOL fInherit
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 ) AS DWORD                                             ' HWINSTA

DECLARE FUNCTION OpenWindowStationW IMPORT "USER32.DLL" ALIAS "OpenWindowStationW" ( _
   BYREF lpszWinSta AS WSTRINGZ _                       ' __in LPCWSTR lpszWinSta
 , BYVAL fInherit AS LONG _                             ' __in BOOL fInherit
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in ACCESS_MASK dwDesiredAccess
 ) AS DWORD                                             ' HWINSTA

#IF %DEF(%UNICODE)
   MACRO OpenWindowStation = OpenWindowStationW
#ELSE
   MACRO OpenWindowStation = OpenWindowStationA
#ENDIF

DECLARE FUNCTION EnumWindowStationsA IMPORT "USER32.DLL" ALIAS "EnumWindowStationsA" ( _
   BYVAL lpEnumFunc AS DWORD _                          ' __in WINSTAENUMPROCA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumWindowStationsW IMPORT "USER32.DLL" ALIAS "EnumWindowStationsW" ( _
   BYVAL lpEnumFunc AS DWORD _                          ' __in WINSTAENUMPROCW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumWindowStations = EnumWindowStationsW
#ELSE
   MACRO EnumWindowStations = EnumWindowStationsA
#ENDIF

DECLARE FUNCTION CloseWindowStation IMPORT "USER32.DLL" ALIAS "CloseWindowStation" ( _
   BYVAL hWinSta AS DWORD _                             ' __in HWINSTA hWinSta
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessWindowStation IMPORT "USER32.DLL" ALIAS "SetProcessWindowStation" ( _
   BYVAL hWinSta AS DWORD _                             ' __in HWINSTA hWinSta
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetProcessWindowStation IMPORT "USER32.DLL" ALIAS "GetProcessWindowStation" ( _
 ) AS DWORD                                             ' HWINSTA

'#endif  /* !NOWINDOWSTATION */
'#ENDIF ' #IF NOT %DEF(%NOWINDOWSTATION) '-------------


'#IF NOT %DEF(%NOSECURITY) ' -----------------------------------
'#ifndef NOSECURITY

DECLARE FUNCTION SetUserObjectSecurity IMPORT "USER32.DLL" ALIAS "SetUserObjectSecurity" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYREF pSIRequested AS SECURITY_INFORMATION _         ' __in PSECURITY_INFORMATION pSIRequested
 , BYREF pSID AS SECURITY_DESCRIPTOR _                  ' __in PSECURITY _DESCRIPTOR pSID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUserObjectSecurity IMPORT "USER32.DLL" ALIAS "GetUserObjectSecurity" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYREF pSIRequested AS SECURITY_INFORMATION _         ' __in PSECURITY_INFORMATION pSIRequested
 , BYREF pSID AS SECURITY_DESCRIPTOR _                  ' __out PSECURITY_DESCRIPTOR pSID
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpnLengthNeeded AS DWORD _                     ' __out LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL

%UOI_FLAGS    = 1&
%UOI_NAME     = 2&
%UOI_TYPE     = 3&
%UOI_USER_SID = 4&
'#if(WINVER >= 0x0600)
%UOI_HEAPSIZE = 5&
%UOI_IO       = 6&
'#endif /* WINVER >= 0x0600 */

' // Size = 12 bytes
TYPE USEROBJECTFLAGS DWORD
   fInherit  AS LONG    ' BOOL
   fReserved AS LONG    ' BOOL
   dwFlags   AS DWORD   ' DWORD
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUserObjectInformationA LIB "User32.dll" _
    ALIAS "GetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetUserObjectInformationA IMPORT "USER32.DLL" ALIAS "GetUserObjectInformationA" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYREF pvInfo AS ANY _                                ' __out PVOID pvInfo
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , OPTIONAL BYREF lpnLengthNeeded AS DWORD _            ' __out_opt LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUserObjectInformationW LIB "User32.dll" _
    ALIAS "GetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD, _
    lpnLengthNeeded AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetUserObjectInformationW IMPORT "USER32.DLL" ALIAS "GetUserObjectInformationW" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYREF pvInfo AS ANY _                                ' __out PVOID pvInfo
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , OPTIONAL BYREF lpnLengthNeeded AS DWORD _            ' __out_opt LPDWORD lpnLengthNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetUserObjectInformation = GetUserObjectInformationW
#ELSE
   MACRO GetUserObjectInformation = GetUserObjectInformationA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetUserObjectInformationA LIB "User32.dll" _
    ALIAS "SetUserObjectInformationA" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SetUserObjectInformationA IMPORT "USER32.DLL" ALIAS "SetUserObjectInformationA" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYREF pvInfo AS ANY _                                ' __in PVOID pvInfo
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetUserObjectInformationW LIB "User32.dll" _
    ALIAS "SetUserObjectInformationW" (BYVAL hObj AS DWORD, _
    BYVAL nIndex AS LONG, BYVAL pvInfo AS DWORD, BYVAL nLength AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SetUserObjectInformationW IMPORT "USER32.DLL" ALIAS "SetUserObjectInformationW" ( _
   BYVAL hObj AS DWORD _                                ' __in HANDLE hObj
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYREF pvInfo AS ANY _                                ' __in PVOID pvInfo
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetUserObjectInformation = SetUserObjectInformationW
#ELSE
   MACRO SetUserObjectInformation = SetUserObjectInformationA
#ENDIF

'#endif  /* !NOSECURITY */
'#ENDIF ' #IF NOT %DEF(%NOSECURITY) '-------------------------------

'#if(WINVER >= 0x0400)
' // Size = 48 bytes
TYPE WNDCLASSEXA BYTE
   cbSize        AS DWORD        ' UINT
   ' /* Win 3.x */
   style         AS DWORD        ' UINT
   lpfnWndProc   AS DWORD        ' WNDPROC
   cbClsExtra    AS LONG         ' int
   cbWndExtra    AS LONG         ' int
   hInstance     AS DWORD        ' HINSTANCE
   hIcon         AS DWORD        ' HICON
   hCursor       AS DWORD        ' HCURSOR
   hbrBackground AS DWORD        ' HBRUSH
   lpszMenuName  AS ASCIIZ PTR   ' LPCSTR
   lpszClassName AS ASCIIZ PTR   ' LPCSTR
   ' /* Win 4.0 */
   hIconSm       AS DWORD        ' HICON
END TYPE

' // Size = 48 bytes
' // Predefined as of PBWIN 10
TYPE WNDCLASSEXW BYTE
   cbSize        AS DWORD        ' UINT
   ' /* Win 3.x */
   style         AS DWORD        ' UINT
   lpfnWndProc   AS DWORD        ' WNDPROC
   cbClsExtra    AS LONG         ' int
   cbWndExtra    AS LONG         ' int
   hInstance     AS DWORD        ' HINSTANCE
   hIcon         AS DWORD        ' HICON
   hCursor       AS DWORD        ' HCURSOR
   hbrBackground AS DWORD        ' HBRUSH
   lpszMenuName  AS WSTRINGZ PTR ' LPCWSTR
   lpszClassName AS WSTRINGZ PTR ' LPCWSTR
   ' /* Win 4.0 */
   hIconSm       AS DWORD        ' HICON
END TYPE

#IF %DEF(%UNICODE)
MACRO WNDCLASSEX = WNDCLASSEXW
#ELSE
MACRO WNDCLASSEX = WNDCLASSEXA
#ENDIF ' UNICODE

'#endif /* WINVER >= 0x0400 */

' // Size = 40 bytes
TYPE WNDCLASSA BYTE
   style         AS DWORD        ' UINT
   lpfnwndproc   AS DWORD        ' WNDPROC
   cbClsextra    AS LONG         ' int
   cbWndExtra    AS LONG         ' int
   hInstance     AS DWORD        ' HINSTANCE
   hIcon         AS DWORD        ' HICON
   hCursor       AS DWORD        ' HCURSOR
   hbrBackground AS DWORD        ' HBRUSH
   lpszMenuName  AS ASCIIZ PTR   ' LPCSTR
   lpszClassName AS ASCIIZ PTR   ' LPCSTR
END TYPE

' // Size = 40 bytes
TYPE WNDCLASSW BYTE
   style         AS DWORD          ' UINT
   lpfnwndproc   AS DWORD          ' WNDPROC
   cbClsextra    AS LONG           ' int
   cbWndExtra    AS LONG           ' int
   hInstance     AS DWORD          ' HINSTANCE
   hIcon         AS DWORD          ' HICON
   hCursor       AS DWORD          ' HCURSOR
   hbrBackground AS DWORD          ' HBRUSH
   lpszMenuName  AS WSTRINGZ PTR   ' LPCWSTR
   lpszClassName AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

#IF %DEF(%UNICODE)
MACRO WNDCLASS = WNDCLASSW
#ELSE
MACRO WNDCLASS = WNDCLASSA
#ENDIF ' UNICODE

DECLARE FUNCTION IsHungAppWindow IMPORT "USER32.DLL" ALIAS "IsHungAppWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0501)

DECLARE SUB DisableProcessWindowsGhosting IMPORT "USER32.DLL" ALIAS "DisableProcessWindowsGhosting" ( _
 )                                                      ' VOID
'#endif /* WINVER >= 0x0501 */

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

'/*
' * Message structure
' */

#IF NOT %DEF(%MSG_DEFINED)
%MSG_DEFINED = 1
' // Size = 28 bytes
TYPE tagMSG DWORD
   hwnd    AS DWORD   ' HWND
   message AS DWORD   ' UINT
   wParam  AS DWORD   ' WPARAM
   lParam  AS LONG    ' LPARAM
   time    AS DWORD   ' DWORD
   pt      AS POINT   ' POINT
END TYPE
#ENDIF

'#define POINTSTOPOINT(pt, pts)                          \
'        { (pt).x = (LONG)(SHORT)LOWORD(*(LONG*)&pts);   \
'          (pt).y = (LONG)(SHORT)HIWORD(*(LONG*)&pts); }

SUB POINTSTOPOINT(BYREF pt AS POINT, BYREF pts AS POINTS)
    pt.x = LO(WORD, pts.x)
    pt.y = HI(WORD, pts.y)
END SUB

'#define POINTTOPOINTS(pt)      (MAKELONG((short)((pt).x), (short)((pt).y)))

MACRO POINTTOPOINTS(pt, pts)
   pts.x = BITS(INTEGER, pt.x)
   pts.y = BITS(INTEGER, pt.y)
END MACRO

'#define MAKEWPARAM(l, h)      ((WPARAM)(DWORD)MAKELONG(l, h))
'#define MAKELPARAM(l, h)      ((LPARAM)(DWORD)MAKELONG(l, h))
'#define MAKELRESULT(l, h)     ((LRESULT)(DWORD)MAKELONG(l, h))

MACRO MAKEWPARAM(l, h) = MAK(DWORD, l, h)
MACRO MAKELPARAM(l, h) = BITS(LONG, MAK(DWORD, l, h))
MACRO MAKELRESULT(l, h) = BITS(LONG, MAK(DWORD, l, h))

'#endif /* !NOMSG */
'#ENDIF    ' #IF NOT %DEF(%NOMSG) '---------------------------------------------

'#IF NOT %DEF(%NOWINOFFSETS) '--------------------------------------------------
'#ifndef NOWINOFFSETS

'/*
' * Window field offsets for GetWindowLong()
' */
%GWL_WNDPROC        = -4&
%GWL_HINSTANCE      = -6&
%GWL_hwndParent     = -8&
%GWL_STYLE          = -16&
%GWL_EXSTYLE        = -20&
%GWL_USERDATA       = -21&
%GWL_ID             = -12&

%GWLP_WNDPROC       = -4&
%GWLP_HINSTANCE     = -6&
%GWLP_hwndParent    = -8&
%GWLP_USERDATA      = -21&
%GWLP_ID            = -12&

'/*
' * Class field offsets for GetClassLong()
' */
%GCL_MENUNAME       = -8&
%GCL_HBRBACKGROUND  = -10&
%GCL_HCURSOR        = -12&
%GCL_HICON          = -14&
%GCL_HMODULE        = -16&
%GCL_CBWNDEXTRA     = -18&
%GCL_CBCLSEXTRA     = -20&
%GCL_WNDPROC        = -24&
%GCL_STYLE          = -26&
%GCW_ATOM           = -32&

'#if(WINVER >= 0x0400)
%GCL_HICONSM        = -34&
'#endif /* WINVER >= 0x0400 */

%GCLP_MENUNAME      = -8&
%GCLP_HBRBACKGROUND = -10&
%GCLP_HCURSOR       = -12&
%GCLP_HICON         = -14&
%GCLP_HMODULE       = -16&
%GCLP_WNDPROC       = -24&
%GCLP_HICONSM       = -34&

'#endif /* !NOWINOFFSETS */
'#ENDIF ' #IF NOT %DEF(%NOWINOFFSETS) '-----------------------------------------

'#IF NOT %DEF(%NOWINMESSAGES) '-------------------------------------------------
'#ifndef NOWINMESSAGES

'/*
' * Window Messages
' */

'%WM_NULL     = &H0000???
'%WM_CREATE   = &H0001???
'%WM_DESTROY  = &H0002???
'%WM_MOVE     = &H0003???
'%WM_SIZE     = &H0005???

'%WM_ACTIVATE = &H0006???

'/*
' * WM_ACTIVATE state values
' */
%WA_INACTIVE    = 0&
%WA_ACTIVE      = 1&
%WA_CLICKACTIVE = 2&

'%WM_SETFOCUS         = &H0007???
'%WM_KILLFOCUS        = &H0008???
%WM_ENABLE           = &H000A???
%WM_SETREDRAW        = &H000B???
%WM_SETTEXT          = &H000C???
%WM_GETTEXT          = &H000D???
%WM_GETTEXTLENGTH    = &H000E???
'%WM_PAINT            = &H000F???
'%WM_CLOSE            = &H0010???
'#ifndef _WIN32_WCE
%WM_QUERYENDSESSION  = &H0011???
%WM_QUERYOPEN        = &H0013???
%WM_ENDSESSION       = &H0016???
'#endif
'%WM_QUIT             = &H0012???
%WM_ERASEBKGND       = &H0014???
%WM_SYSCOLORCHANGE   = &H0015???
%WM_SHOWWINDOW       = &H0018???
%WM_WININICHANGE     = &H001A???
%WM_SETTINGCHANGE    = %WM_WININICHANGE

'#endif /* WINVER >= 0x0400 */

%WM_DEVMODECHANGE    = &H001B???
'%WM_ACTIVATEAPP      = &H001C???
%WM_FONTCHANGE       = &H001D???
%WM_TIMECHANGE       = &H001E???
'%WM_CANCELMODE       = &H001F???
%WM_SETCURSOR        = &H0020???
'%WM_MOUSEACTIVATE    = &H0021???
%WM_CHILDACTIVATE    = &H0022???
%WM_QUEUESYNC        = &H0023???

%WM_GETMINMAXINFO    = &H0024???

'/*
' * Struct pointed to by WM_GETMINMAXINFO lParam
' */

' // Size = 40 bytes
TYPE MINMAXINFO DWORD
   ptReserved     AS POINT
   ptMaxSize      AS POINT
   ptMaxPosition  AS POINT
   ptMinTrackSize AS POINT
   ptMaxTrackSize AS POINT
END TYPE

%WM_PAINTICON            = &H0026???
%WM_ICONERASEBKGND       = &H0027???
%WM_NEXTDLGCTL           = &H0028???
%WM_SPOOLERSTATUS        = &H002A???
'%WM_DRAWITEM             = &H002B???
%WM_MEASUREITEM          = &H002C???
%WM_DELETEITEM           = &H002D???
%WM_VKEYTOITEM           = &H002E???
%WM_CHARTOITEM           = &H002F???
%WM_SETFONT              = &H0030???
%WM_GETFONT              = &H0031???
%WM_SETHOTKEY            = &H0032???
%WM_GETHOTKEY            = &H0033???
%WM_QUERYDRAGICON        = &H0037???
%WM_COMPAREITEM          = &H0039???
'#if(WINVER >= 0x0500)
'#ifndef _WIN32_WCE
%WM_GETOBJECT            = &H003D???
'#endif
'#endif /* WINVER >= 0x0500 */
%WM_COMPACTING           = &H0041???
%WM_OTHERWINDOWCREATED   = &H0042???  ' no longer suported
%WM_OTHERWINDOWDESTROYED = &H0043???  ' no longer suported
%WM_COMMNOTIFY           = &H0044???  ' no longer suported
%WM_WINDOWPOSCHANGING    = &H0046???
%WM_WINDOWPOSCHANGED     = &H0047???

'#define WM_POWER                        0x0048
%WM_POWER                = &H0048???

'/*
' * wParam for WM_POWER window message and DRV_POWER driver notification
' */
%PWR_OK             = 1&
%PWR_FAIL           = -1&
%PWR_SUSPENDREQUEST = 1&
%PWR_SUSPENDRESUME  = 2&
%PWR_CRITICALRESUME = 3&

%WM_COPYDATA                   = &H004A???
%WM_CANCELJOURNAL              = &H004B???

'/*
' * lParam of WM_COPYDATA message points to...
' */

' // Size = 12 bytes
TYPE COPYDATASTRUCT DWORD
   dwData AS DWORD   ' ULONG_PTR
   cbData AS DWORD   ' DWORD
   lpData AS DWORD   ' PVOID
END TYPE

'#if(WINVER >= 0x0400)
' // Size = 12 bytes
TYPE MDINEXTMENU DWORD
   hmenuIn   AS DWORD   ' HMENU
   hmenuNext AS DWORD   ' HMENU
   hwndNext  AS DWORD   ' HWND
END TYPE
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)
'%WM_NOTIFY                     = &H004E???
%WM_INPUTLANGUAGECHANGEREQUEST = &H0050???
%WM_INPUTLANGCHANGEREQUEST     = &H0050???
%WM_INPUTLANGUAGECHANGE        = &H0051???
%WM_INPUTLANGCHANGE            = &H0051???
%WM_TCARD                      = &H0052???
'%WM_HELP                       = &H0053???
%WM_USERCHANGED                = &H0054???
%WM_NOTIFYFORMAT               = &H0055???

%NFR_ANSI            = 1&
%NFR_UNICODE         = 2&
%NF_QUERY            = 3&
%NF_REQUERY          = 4&

%WM_CONTEXTMENU      = &H007B???
%WM_STYLECHANGING    = &H007C???
%WM_STYLECHANGED     = &H007D???
%WM_DISPLAYCHANGE    = &H007E???
%WM_GETICON          = &H007F???
%WM_SETICON          = &H0080???

'%WM_NCCREATE         = &H0081???
'%WM_NCDESTROY        = &H0082???
'%WM_NCCALCSIZE       = &H0083???
'%WM_NCHITTEST        = &H0084???
'%WM_NCPAINT          = &H0085???
'%WM_NCACTIVATE       = &H0086???
%WM_GETDLGCODE       = &H0087???
'#ifndef _WIN32_WCE
%WM_SYNCPAINT        = &H0088???
'#endif
'%WM_NCMOUSEMOVE      = &H00A0???
'%WM_NCLBUTTONDOWN    = &H00A1???
'%WM_NCLBUTTONUP      = &H00A2???
'%WM_NCLBUTTONDBLCLK  = &H00A3???
'%WM_NCRBUTTONDOWN    = &H00A4???
'%WM_NCRBUTTONUP      = &H00A5???
'%WM_NCRBUTTONDBLCLK  = &H00A6???
'%WM_NCMBUTTONDOWN    = &H00A7???
'%WM_NCMBUTTONUP      = &H00A8???
'%WM_NCMBUTTONDBLCLK  = &H00A9???

'#if(_WIN32_WINNT >= 0x0500)
'%WM_NCXBUTTONDOWN    = &H00AB???
'%WM_NCXBUTTONUP      = &H00AC???
'%WM_NCXBUTTONDBLCLK  = &H00AD???
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)
%WM_INPUT_DEVICE_CHANGE = &H00FE???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0501)
%WM_INPUT            = &H00FF???
'#endif /* _WIN32_WINNT >= 0x0501 */

%WM_KEYFIRST         = &H0100???
'%WM_KEYDOWN          = &H0100???
'%WM_KEYUP            = &H0101???
'%WM_CHAR             = &H0102???
%WM_DEADCHAR         = &H0103???
'%WM_SYSKEYDOWN       = &H0104???
'%WM_SYSKEYUP         = &H0105???
%WM_SYSCHAR          = &H0106???
%WM_SYSDEADCHAR      = &H0107???
'#if(_WIN32_WINNT >= 0x0501)
%WM_UNICHAR          = &H0109???
%WM_KEYLAST          = &H0109???
%UNICODE_NOCHAR      = &HFFFF???
'#else
'#define WM_KEYLAST                      0x0108
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(WINVER >= 0x0400)
%WM_IME_STARTCOMPOSITION = &H010D???
%WM_IME_ENDCOMPOSITION   = &H010E???
%WM_IME_COMPOSITION      = &H010F???
%WM_IME_KEYLAST          = &H010F???
'#endif /* WINVER >= 0x0400 */

'%WM_INITDIALOG       = &H0110???
'%WM_COMMAND          = &H0111???
%WM_SYSCOMMAND       = &H0112???
'%WM_TIMER            = &H0113???
'%WM_HSCROLL          = &H0114???
'%WM_VSCROLL          = &H0115???
%WM_INITMENU         = &H0116???
%WM_INITMENUPOPUP    = &H0117???
'#if(WINVER >= 0x0601)
%WM_GESTURE          = &H0119???
%WM_GESTURENOTIFY    = &H011A???
'#endif /* WINVER >= 0x0601 */
%WM_MENUSELECT       = &H011F???
%WM_MENUCHAR         = &H0120???
%WM_ENTERIDLE        = &H0121???
'#if(WINVER >= 0x0500)
'#ifndef _WIN32_WCE
%WM_MENURBUTTONUP    = &H0122???
%WM_MENUDRAG         = &H0123???
%WM_MENUGETOBJECT    = &H0124???
%WM_UNINITMENUPOPUP  = &H0125???
%WM_MENUCOMMAND      = &H0126???
'#ifndef _WIN32_WCE
'#if(_WIN32_WINNT >= 0x0500)
%WM_CHANGEUISTATE    = &H0127???
%WM_UPDATEUISTATE    = &H0128???
%WM_QUERYUISTATE     = &H0129???

'/*
' * LOWORD(wParam) values in WM_*UISTATE*
' */

%UIS_SET        = 1&
%UIS_CLEAR      = 2&
%UIS_INITIALIZE = 3&

'/*
' * HIWORD(wParam) values in WM_*UISTATE*
' */
%UISF_HIDEFOCUS = &H1&
%UISF_HIDEACCEL = &H2&
'#if(_WIN32_WINNT >= 0x0501)
%UISF_ACTIVE    = &H4&
'#endif /* _WIN32_WINNT >= 0x0501 */
'#endif /* _WIN32_WINNT >= 0x0500 */
'#endif

'#endif
'#endif /* WINVER >= 0x0500 */

%WM_CTLCOLORMSGBOX   = &H0132???
%WM_CTLCOLOREDIT     = &H0133???
%WM_CTLCOLORLISTBOX  = &H0134???
%WM_CTLCOLORBTN      = &H0135???
%WM_CTLCOLORDLG      = &H0136???
%WM_CTLCOLORSCROLLBAR= &H0137???
%WM_CTLCOLORSTATIC   = &H0138???
%MN_GETHMENU         = &H01E1???

'%WM_MOUSEFIRST       = &H0200???
'%WM_MOUSEMOVE        = &H0200???
'%WM_LBUTTONDOWN      = &H0201???
'%WM_LBUTTONUP        = &H0202???
'%WM_LBUTTONDBLCLK    = &H0203???
'%WM_RBUTTONDOWN      = &H0204???
'%WM_RBUTTONUP        = &H0205???
'%WM_RBUTTONDBLCLK    = &H0206???
'%WM_MBUTTONDOWN      = &H0207???
'%WM_MBUTTONUP        = &H0208???
'%WM_MBUTTONDBLCLK    = &H0209???
'#if (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
'%WM_MOUSEWHEEL       = &H020A???
'#endif
'#if (_WIN32_WINNT >= 0x0500)
%WM_XBUTTONDOWN      = &H020B???
%WM_XBUTTONUP        = &H020C???
%WM_XBUTTONDBLCLK    = &H020D???
'#endif
'#if (_WIN32_WINNT >= 0x0600)
'#define WM_MOUSEHWHEEL                  0x020E
%WM_MOUSEHWHEEL      = &H020E???   ' Windows Vista
'#endif

'#if (_WIN32_WINNT >= 0x0600)
'#IF %WINVER >= &H0600
'%WM_MOUSELAST                    = &H020E???   ' // Predefined as &H020D in PBWin 10
%WM_MOUSELAST_VISTA              = &H020E???   ' to avoid namimg conlfict
'#elif (_WIN32_WINNT >= 0x0500)
'#ELSEIF %WINVER >= &H0500
'%WM_MOUSELAST                    = &H020D???
'#elif (_WIN32_WINNT >= 0x0400) || (_WIN32_WINDOWS > 0x0400)
'#ELSEIF %WINVER >= &H0400 OR %WINVER > &H0400
'%WM_MOUSELAST                    = &H020A???
'#ELSE
'%WM_MOUSELAST                    = &H0209???
'#ENDIF ' /* (_WIN32_WINNT >= 0x0600) */

'#if(_WIN32_WINNT >= 0x0400)
'/* Value for rolling one detent */
%WHEEL_DELTA                    = 120%
'#define GET_WHEEL_DELTA_WPARAM(wParam)  ((short)HIWORD(wParam))
MACRO GET_WHEEL_DELTA_WPARAM(wParam) = BITS%(HI(WORD, wParam))

'/* Setting to scroll one page for SPI_GET/SETWHEELSCROLLLINES */
'#define WHEEL_PAGESCROLL                (UINT_MAX)
%WHEEL_PAGESCROLL               = &HFFFFFFFF??? ' %UINT_MAX
'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0500)
'#define GET_KEYSTATE_WPARAM(wParam)     (LOWORD(wParam))
'#define GET_NCHITTEST_WPARAM(wParam)    ((short)LOWORD(wParam))
'#define GET_XBUTTON_WPARAM(wParam)      (HIWORD(wParam))
MACRO GET_KEYSTATE_WPARAM(wParam)  = LO(WORD, wParam)
MACRO GET_NCHITTEST_WPARAM(wParam) = BITS%(LO(WORD, wParam))
MACRO GET_XBUTTON_WPARAM(wParam)   = HI(WORD, wParam)

'/* XButton values are WORD flags */
%XBUTTON1      = &H0001???
%XBUTTON2      = &H0002???
'/* Were there to be an XBUTTON3, its value would be 0x0004 */
'#endif /* _WIN32_WINNT >= 0x0500 */

%WM_PARENTNOTIFY     = &H0210???
%WM_ENTERMENULOOP    = &H0211???
%WM_EXITMENULOOP     = &H0212???

'#if(WINVER >= 0x0400)
%WM_NEXTMENU         = &H0213???
%WM_SIZING           = &H0214???
'%WM_CAPTURECHANGED   = &H0215???
%WM_MOVING           = &H0216???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)

%WM_POWERBROADCAST   = &H0218???

'#ifndef _WIN32_WCE
%PBT_APMQUERYSUSPEND         = &H0000???
%PBT_APMQUERYSTANDBY         = &H0001???

%PBT_APMQUERYSUSPENDFAILED   = &H0002???
%PBT_APMQUERYSTANDBYFAILED   = &H0003???

%PBT_APMSUSPEND              = &H0004???
%PBT_APMSTANDBY              = &H0005???

%PBT_APMRESUMECRITICAL       = &H0006???
%PBT_APMRESUMESUSPEND        = &H0007???
%PBT_APMRESUMESTANDBY        = &H0008???

%PBTF_APMRESUMEFROMFAILURE   = &H00000001???

%PBT_APMBATTERYLOW           = &H0009???
%PBT_APMPOWERSTATUSCHANGE    = &H000A???

%PBT_APMOEMEVENT             = &H000B???
%PBT_APMRESUMEAUTOMATIC      = &H0012???
'#if (_WIN32_WINNT >= 0x0502)
#IF NOT %DEF(%PBT_POWERSETTINGCHANGE)
%PBT_POWERSETTINGCHANGE      = &H8013???
' // Size = 24 bytes
TYPE POWERBROADCAST_SETTING DWORD
   PowerSetting AS GUID    ' GUID
   DataLength   AS DWORD   ' DWORD
   Data(0)      AS BYTE    ' UCHAR
END TYPE
#ENDIF ' // PBT_POWERSETTINGCHANGE
'#endif // (_WIN32_WINNT >= 0x0502)
'#endif

'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)
%WM_DEVICECHANGE     = &H0219???
'#endif /* WINVER >= 0x0400 */

%WM_MDICREATE        = &H0220???
%WM_MDIDESTROY       = &H0221???
%WM_MDIACTIVATE      = &H0222???
%WM_MDIRESTORE       = &H0223???
%WM_MDINEXT          = &H0224???
%WM_MDIMAXIMIZE      = &H0225???
%WM_MDITILE          = &H0226???
%WM_MDICASCADE       = &H0227???
%WM_MDIICONARRANGE   = &H0228???
%WM_MDIGETACTIVE     = &H0229???

%WM_MDISETMENU       = &H0230???
%WM_ENTERSIZEMOVE    = &H0231???
%WM_EXITSIZEMOVE     = &H0232???
%WM_DROPFILES        = &H0233???
%WM_MDIREFRESHMENU   = &H0234???

'#if(WINVER >= 0x0601)
%WM_TOUCH            = &H0240???
'#endif /* WINVER >= 0x0601 */

'#if(WINVER >= 0x0400)
%WM_IME_SETCONTEXT       = &H0281???
%WM_IME_NOTIFY           = &H0282???
%WM_IME_CONTROL          = &H0283???
%WM_IME_COMPOSITIONFULL  = &H0284???
%WM_IME_SELECT           = &H0285???
%WM_IME_CHAR             = &H0286???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0500)
%WM_IME_REQUEST          = &H0288???
'#endif /* WINVER >= 0x0500 */
'#if(WINVER >= 0x0400)
%WM_IME_KEYDOWN          = &H0290???
%WM_IME_KEYUP            = &H0291???
'#endif /* WINVER >= 0x0400 */

'#if((_WIN32_WINNT >= 0x0400) || (WINVER >= 0x0500))
'%WM_MOUSEHOVER        = &H02A1???
'%WM_MOUSELEAVE        = &H02A3???
'#endif
'#if(WINVER >= 0x0500)
%WM_NCMOUSEHOVER      = &H02A0???
%WM_NCMOUSELEAVE      = &H02A2???
'#endif /* WINVER >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)
%WM_WTSSESSION_CHANGE = &H02B1???

%WM_TABLET_FIRST      = &H02c0???
%WM_TABLET_LAST       = &H02df???
'#endif /* _WIN32_WINNT >= 0x0501 */

%WM_CUT               = &H0300???
%WM_COPY              = &H0301???
%WM_PASTE             = &H0302???
%WM_CLEAR             = &H0303???
%WM_UNDO              = &H0304???
%WM_RENDERFORMAT      = &H0305???
%WM_RENDERALLFORMATS  = &H0306???
%WM_DESTROYCLIPBOARD  = &H0307???
%WM_DRAWCLIPBOARD     = &H0308???
%WM_PAINTCLIPBOARD    = &H0309???
%WM_VSCROLLCLIPBOARD  = &H030A???
%WM_SIZECLIPBOARD     = &H030B???
%WM_ASKCBFORMATNAME   = &H030C???
%WM_CHANGECBCHAIN     = &H030D???
%WM_HSCROLLCLIPBOARD  = &H030E???
%WM_QUERYNEWPALETTE   = &H030F???
%WM_PALETTEISCHANGING = &H0310???
%WM_PALETTECHANGED    = &H0311???
%WM_HOTKEY            = &H0312???

'#if(WINVER >= 0x0400)
%WM_PRINT             = &H0317???
%WM_PRINTCLIENT       = &H0318???
'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0500)
%WM_APPCOMMAND        = &H0319???
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)
%WM_THEMECHANGED      = &H031A???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0501)
%WM_CLIPBOARDUPDATE              = &H031D???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0600)
%WM_DWMCOMPOSITIONCHANGED        = &H031E???
%WM_DWMNCRENDERINGCHANGED        = &H031F???
%WM_DWMCOLORIZATIONCOLORCHANGED  = &H0320???
%WM_DWMWINDOWMAXIMIZEDCHANGE     = &H0321???
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if(_WIN32_WINNT >= 0x0601)
%WM_DWMSENDICONICTHUMBNAIL         = &H0323???
%WM_DWMSENDICONICLIVEPREVIEWBITMAP = &H0326???
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if(WINVER >= 0x0600)
%WM_GETTITLEBARINFOEX            = &H033F???
'#endif /* WINVER >= 0x0600 */

'#if(WINVER >= 0x0400)

%WM_HANDHELDFIRST     = &H0358???
%WM_HANDHELDLAST      = &H035F???

%WM_AFXFIRST          = &H0360???
%WM_AFXLAST           = &H037F???
'#endif /* WINVER >= 0x0400 */

%WM_PENWINFIRST       = &H0380???
%WM_PENWINLAST        = &H038F???


'#if(WINVER >= 0x0400)
%WM_APP               = &H8000???
'#endif /* WINVER >= 0x0400 */


'/*
' * NOTE: All Message Numbers below 0x0400 are RESERVED.
' *
' * Private Window Messages Start Here:
' */
'%WM_USER = &H0400???

'#if(WINVER >= 0x0400)

'/*  wParam for WM_SIZING message  */
%WMSZ_LEFT        = 1&
%WMSZ_RIGHT       = 2&
%WMSZ_TOP         = 3&
%WMSZ_TOPLEFT     = 4&
%WMSZ_TOPRIGHT    = 5&
%WMSZ_BOTTOM      = 6&
%WMSZ_BOTTOMLEFT  = 7&
%WMSZ_BOTTOMRIGHT = 8&

'#IF NOT %DEF(%NONCMESSAGES) ' -------------------------------------------------
'#ifndef NONCMESSAGES

'/*
' * WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes
' */
%HTERROR       = -2&
%HTTRANSPARENT = -1&
%HTNOWHERE     = 0&
%HTCLIENT      = 1&
%HTCAPTION     = 2&
%HTSYSMENU     = 3&
%HTGROWBOX     = 4&
%HTSIZE        = %HTGROWBOX
%HTMENU        = 5&
%HTHSCROLL     = 6&
%HTVSCROLL     = 7&
%HTMINBUTTON   = 8&
%HTMAXBUTTON   = 9&
%HTLEFT        = 10&
%HTRIGHT       = 11&
%HTTOP         = 12&
%HTTOPLEFT     = 13&
%HTTOPRIGHT    = 14&
%HTBOTTOM      = 15&
%HTBOTTOMLEFT  = 16&
%HTBOTTOMRIGHT = 17&
%HTBORDER      = 18&
%HTREDUCE      = %HTMINBUTTON
%HTZOOM        = %HTMAXBUTTON
%HTSIZEFIRST   = %HTLEFT
%HTSIZELAST    = %HTBOTTOMRIGHT
'#if(WINVER >= 0x0400)
%HTOBJECT      = 19&
%HTCLOSE       = 20&
%HTHELP        = 21&
'#endif /* WINVER >= 0x0400 */

'/*
' * SendMessageTimeout values
' */
%SMTO_NORMAL         = &H0000???
%SMTO_BLOCK          = &H0001???
%SMTO_ABORTIFHUNG    = &H0002???
'#if(WINVER >= 0x0500)
%SMTO_NOTIMEOUTIFNOTHUNG = &H0008???
'#endif /* WINVER >= 0x0500 */
'#if(WINVER >= 0x0600)
%SMTO_ERRORONEXIT    = &H0020???
'#endif /* WINVER >= 0x0600 */

'#endif /* !NONCMESSAGES */

'#ENDIF   ' #IF NOT %DEF(%NONCMESSAGES) ' --------------------------------------

'/*
' * WM_MOUSEACTIVATE Return Codes
' */
%MA_ACTIVATE         = 1&
%MA_ACTIVATEANDEAT   = 2&
%MA_NOACTIVATE       = 3&
%MA_NOACTIVATEANDEAT = 4&

'/*
' * WM_SETICON / WM_GETICON Type Codes
' */
%ICON_SMALL  = 0&
%ICON_BIG    = 1&
'#if(_WIN32_WINNT >= 0x0501)
%ICON_SMALL2 = 2&
'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION RegisterWindowMessageA IMPORT "USER32.DLL" ALIAS "RegisterWindowMessageA" ( _
   BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION RegisterWindowMessageW IMPORT "USER32.DLL" ALIAS "RegisterWindowMessageW" ( _
   BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO RegisterWindowMessage = RegisterWindowMessageW
#ELSE
   MACRO RegisterWindowMessage = RegisterWindowMessageA
#ENDIF

'/*
' * WM_SIZE message wParam values
' */
%SIZE_RESTORED  = 0&
%SIZE_MINIMIZED = 1&
%SIZE_MAXIMIZED = 2&
%SIZE_MAXSHOW   = 3&
%SIZE_MAXHIDE   = 4&

'/*
' * Obsolete constant names
' */
%SIZENORMAL     = %SIZE_RESTORED
%SIZEICONIC     = %SIZE_MINIMIZED
%SIZEFULLSCREEN = %SIZE_MAXIMIZED
%SIZEZOOMSHOW   = %SIZE_MAXSHOW
%SIZEZOOMHIDE   = %SIZE_MAXHIDE

'/*
' * WM_WINDOWPOSCHANGING/CHANGED struct pointed to by lParam
' */
' // Size = 28 bytes
TYPE WINDOWPOS DWORD
   hWnd            AS DWORD   ' HWND
   hWndInsertAfter AS DWORD   ' HWND
   x               AS LONG    ' int
   y               AS LONG    ' int
   cx              AS LONG    ' int
   cy              AS LONG    ' int
   flags           AS DWORD   ' UINT
END TYPE

'/*
' * WM_NCCALCSIZE parameter structure
' */

' // Size = 52 bytes
TYPE NCCALCSIZE_PARAMS DWORD
   rgrc(2) AS RECT            ' RECT rgrc[3]
   lppos   AS WINDOWPOS PTR   ' PWINDOWPOS
END TYPE

'/*
' * WM_NCCALCSIZE "window valid rect" return values
' */
%WVR_ALIGNTOP    = &H0010&
%WVR_ALIGNLEFT   = &H0020&
%WVR_ALIGNBOTTOM = &H0040&
%WVR_ALIGNRIGHT  = &H0080&
%WVR_HREDRAW     = &H0100&
%WVR_VREDRAW     = &H0200&
%WVR_REDRAW      = %WVR_HREDRAW OR %WVR_VREDRAW
%WVR_VALIDRECTS  = &H0400&

'#IF NOT %DEF(%NOKEYSTATES) ' --------------------------------------------------
'#ifndef NOKEYSTATES

'/*
' * Key State Masks for Mouse Messages
' */
%MK_LBUTTON  = &H0001??
%MK_RBUTTON  = &H0002??
%MK_SHIFT    = &H0004??
%MK_CONTROL  = &H0008??
%MK_MBUTTON  = &H0010??
'#if(_WIN32_WINNT >= 0x0500)
%MK_XBUTTON1 = &H0020??
%MK_XBUTTON2 = &H0040??
'#endif /* _WIN32_WINNT >= 0x0500 */

'#endif /* !NOKEYSTATES */
'#ENDIF   ' #IF NOT %DEF(%NOKEYSTATES) ' ---------------------------------------


'#if(_WIN32_WINNT >= 0x0400)
'#IF NOT %DEF(%NOTRACKMOUSEEVENT) ' --------------------------------------------
'#ifndef NOTRACKMOUSEEVENT

%TME_HOVER     = &H00000001???
%TME_LEAVE     = &H00000002???
'#if(WINVER >= 0x0500)
%TME_NONCLIENT = &H00000010???
'#endif /* WINVER >= 0x0500 */
%TME_QUERY     = &H40000000???
%TME_CANCEL    = &H80000000???

%HOVER_DEFAULT = &HFFFFFFFF???
'#endif /* _WIN32_WINNT >= 0x0400 */


'#if(_WIN32_WINNT >= 0x0400)

#IF NOT %DEF(%TRACKMOUSEEVENT_DEFINED)
%TRACKMOUSEEVENT_DEFINED = 1
' // Size = 16 bytes
TYPE tagTRACKMOUSEEVENT DWORD
   cbSize      AS DWORD   ' DWORD
   dwFlags     AS DWORD   ' DWORD
   hwndTrack   AS DWORD   ' HWND
   dwHoverTime AS DWORD   ' DWORD
END TYPE
' The TRACKMOUSEEVENTAPI name is used in the old PB's win32api.inc instead of tagTRACKMOUSEVENT
MACRO TRACKMOUSEEVENTAPI = tagTRACKMOUSEEVENT
' // For compatibility with the PB includes
MACRO TRACKMOUSEEVENT_type = tagTRACKMOUSEEVENT
' The EVENTTRACK name is used in the old PB's commctrl.inc instead of tagTRACKMOUSEVENT
MACRO EVENTTRACK = tagTRACKMOUSEEVENT
#ENDIF

DECLARE FUNCTION TrackMouseEvent IMPORT "USER32.DLL" ALIAS "TrackMouseEvent" ( _
   BYREF lpEventTrack AS tagTRACKMOUSEEVENT _           ' LPTRACKMOUSEEVENT lpEventTrack
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0400)

'#endif /* !NOTRACKMOUSEEVENT */
'#ENDIF   ' #IF NOT %DEF(%NOTRACKMOUSEEVENT) ' ---------------------------------
'#endif /* _WIN32_WINNT >= 0x0400 */


'#endif /* !NOWINMESSAGES */
'#ENDIF ' #IF NOT %DEF(%NOWINMESSAGES) '----------------------------------------


'#IF NOT %DEF(%NOWINSTYLES) ' --------------------------------------------------
'#ifndef NOWINSTYLES

' // Note: The remed WS_XXX styles are predefined in the compiler.

'/*
' * Window Styles
' */
'%WS_OVERLAPPED         = &H00000000&
'%WS_POPUP              = &H80000000&
'%WS_CHILD              = &H40000000&
'%WS_MINIMIZE           = &H20000000&
'%WS_VISIBLE            = &H10000000&
'%WS_DISABLED           = &H08000000&
'%WS_CLIPSIBLINGS       = &H04000000&
'%WS_CLIPCHILDREN       = &H02000000&
'%WS_MAXIMIZE           = &H01000000&
'%WS_CAPTION            = &H00C00000&  ' WS_BORDER OR WS_DLGFRAME
'%WS_BORDER             = &H00800000&
'%WS_DLGFRAME           = &H00400000&
'%WS_VSCROLL            = &H00200000&
'%WS_HSCROLL            = &H00100000&
'%WS_SYSMENU            = &H00080000&
'%WS_THICKFRAME         = &H00040000&
'%WS_GROUP              = &H00020000&
'%WS_TABSTOP            = &H00010000&

'%WS_MINIMIZEBOX        = &H00020000&
'%WS_MAXIMIZEBOX        = &H00010000&

'%WS_TILED              = %WS_OVERLAPPED
'%WS_ICONIC             = %WS_MINIMIZE
'%WS_SIZEBOX            = %WS_THICKFRAME

'/*
' * Common Window Styles
' */
'%WS_OVERLAPPEDWINDOW   = %WS_OVERLAPPED OR %WS_CAPTION OR %WS_SYSMENU OR %WS_THICKFRAME OR %WS_MINIMIZEBOX OR %WS_MAXIMIZEBOX
'%WS_TILEDWINDOW        = %WS_OVERLAPPEDWINDOW
'%WS_POPUPWINDOW        = %WS_POPUP OR %WS_BORDER OR %WS_SYSMENU
'%WS_CHILDWINDOW        = %WS_CHILD

'/*
' * Extended Window Styles
' */
'%WS_EX_DLGMODALFRAME   = &H00000001&
'%WS_EX_NOPARENTNOTIFY  = &H00000004&
'%WS_EX_TOPMOST         = &H00000008&
'%WS_EX_ACCEPTFILES     = &H00000010&
'%WS_EX_TRANSPARENT     = &H00000020&
'#if(WINVER >= 0x0400)
'%WS_EX_MDICHILD        = &H00000040&
'%WS_EX_TOOLWINDOW      = &H00000080&
'%WS_EX_SMCAPTION       = &H00000080&
'%WS_EX_WINDOWEDGE      = &H00000100&
'%WS_EX_CLIENTEDGE      = &H00000200&
'%WS_EX_CONTEXTHELP     = &H00000400&
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)

'%WS_EX_RIGHT           = &H00001000&
'%WS_EX_LEFT            = &H00000000&
'%WS_EX_RTLREADING      = &H00002000&
'%WS_EX_LTRREADING      = &H00000000&
'%WS_EX_LEFTSCROLLBAR   = &H00004000&
'%WS_EX_RIGHTSCROLLBAR  = &H00000000&

'%WS_EX_CONTROLPARENT   = &H00010000&
'%WS_EX_STATICEDGE      = &H00020000&
'%WS_EX_APPWINDOW       = &H00040000&

'%WS_EX_OVERLAPPEDWINDOW = %WS_EX_WINDOWEDGE OR %WS_EX_CLIENTEDGE
'%WS_EX_PALETTEWINDOW    = %WS_EX_WINDOWEDGE OR %WS_EX_TOOLWINDOW OR %WS_EX_TOPMOST

'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0500)
'%WS_EX_LAYERED         = &H00080000&

'#endif /* _WIN32_WINNT >= 0x0500 */


'#if(WINVER >= 0x0500)
'%WS_EX_NOINHERITLAYOUT = &H00100000&
'%WS_EX_LAYOUTRTL       = &H00400000&
'#endif /* WINVER >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)
'%WS_EX_COMPOSITED      = &H02000000&
'#endif /* _WIN32_WINNT >= 0x0501 */
'#if(_WIN32_WINNT >= 0x0500)
'%WS_EX_NOACTIVATE      = &H08000000&
'#endif /* _WIN32_WINNT >= 0x0500 */


' // Note: The remed CS_XXX styles are predefined in the compiler.

'/*
' * Class styles
' */
'%CS_VREDRAW         = &H0001???
'%CS_HREDRAW         = &H0002???
'%CS_KEYCVTWINDOW    = &H0004???
'%CS_DBLCLKS         = &H0008???
'%CS_OWNDC           = &H0020???
'%CS_CLASSDC         = &H0040???
'%CS_PARENTDC        = &H0080???
'%CS_NOKEYCVT        = &H0100???
'%CS_NOCLOSE         = &H0200???
'%CS_SAVEBITS        = &H0800???
'%CS_BYTEALIGNCLIENT = &H1000???
'%CS_BYTEALIGNWINDOW = &H2000???
%CS_PUBLICCLASS     = &H4000???
%CS_GLOBALCLASS     = %CS_PUBLICCLASS

'%CS_IME             = &H00010000???
'#if(_WIN32_WINNT >= 0x0501)
'%CS_DROPSHADOW      = &H00020000???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#endif /* !NOWINSTYLES */
'#ENDIF ' #IF NOT %DEF(%NOWINSTYLES) '------------------------------------------

'#if(WINVER >= 0x0400)
'/* WM_PRINT flags */
%PRF_CHECKVISIBLE    = &H00000001???
%PRF_NONCLIENT       = &H00000002???
%PRF_CLIENT          = &H00000004???
%PRF_ERASEBKGND      = &H00000008???
%PRF_CHILDREN        = &H00000010???
%PRF_OWNED           = &H00000020???

'/* 3D border styles */
%BDR_RAISEDOUTER     = &H0001???
%BDR_SUNKENOUTER     = &H0002???
%BDR_RAISEDINNER     = &H0004???
%BDR_SUNKENINNER     = &H0008???

%BDR_OUTER           = %BDR_RAISEDOUTER OR %BDR_SUNKENOUTER
%BDR_INNER           = %BDR_RAISEDINNER OR %BDR_SUNKENINNER
%BDR_RAISED          = %BDR_RAISEDOUTER OR %BDR_RAISEDINNER
%BDR_SUNKEN          = %BDR_SUNKENOUTER OR %BDR_SUNKENINNER

%EDGE_RAISED         = %BDR_RAISEDOUTER OR %BDR_RAISEDINNER
%EDGE_SUNKEN         = %BDR_SUNKENOUTER OR %BDR_SUNKENINNER
%EDGE_ETCHED         = %BDR_SUNKENOUTER OR %BDR_RAISEDINNER
%EDGE_BUMP           = %BDR_RAISEDOUTER OR %BDR_SUNKENINNER

'/* Border flags */
%BF_LEFT             = &H0001???
%BF_TOP              = &H0002???
%BF_RIGHT            = &H0004???
%BF_BOTTOM           = &H0008???

%BF_TOPLEFT          = %BF_TOP OR %BF_LEFT
%BF_TOPRIGHT         = %BF_TOP OR %BF_RIGHT
%BF_BOTTOMLEFT       = %BF_BOTTOM OR %BF_LEFT
%BF_BOTTOMRIGHT      = %BF_BOTTOM OR %BF_RIGHT
%BF_RECT             = %BF_LEFT OR %BF_TOP OR %BF_RIGHT OR %BF_BOTTOM

%BF_DIAGONAL         = &H0010???

'// For diagonal lines, the BF_RECT flags specify the end point of the
'// vector bounded by the rectangle parameter.
%BF_DIAGONAL_ENDTOPRIGHT    = %BF_DIAGONAL OR %BF_TOP OR %BF_RIGHT
%BF_DIAGONAL_ENDTOPLEFT     = %BF_DIAGONAL OR %BF_TOP OR %BF_LEFT
%BF_DIAGONAL_ENDBOTTOMLEFT  = %BF_DIAGONAL OR %BF_BOTTOM OR %BF_LEFT
%BF_DIAGONAL_ENDBOTTOMRIGHT = %BF_DIAGONAL OR %BF_BOTTOM OR %BF_RIGHT

%BF_MIDDLE  = &H0800???  '* Fill in the middle
%BF_SOFT    = &H1000???  '* For softer buttons
%BF_ADJUST  = &H2000???  '* Calculate the space left over
%BF_FLAT    = &H4000???  '* For flat rather than 3D borders
%BF_MONO    = &H8000???  '* For monochrome borders

DECLARE FUNCTION DrawEdge IMPORT "USER32.DLL" ALIAS "DrawEdge" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF qrc AS RECT _                                  ' __inout LPRECT qrc
 , BYVAL edge AS DWORD _                                ' __in UINT edge
 , BYVAL grfFlags AS DWORD _                            ' __in UINT grfFlags
 ) AS LONG                                              ' BOOL

'/* flags for DrawFrameControl */

%DFC_CAPTION     = 1&
%DFC_MENU        = 2&
%DFC_SCROLL      = 3&
%DFC_BUTTON      = 4&
'#if(WINVER >= 0x0500)
%DFC_POPUPMENU   = 5&
'#endif /* WINVER >= 0x0500 */

%DFCS_CAPTIONCLOSE        = &H0000???
%DFCS_CAPTIONMIN          = &H0001???
%DFCS_CAPTIONMAX          = &H0002???
%DFCS_CAPTIONRESTORE      = &H0003???
%DFCS_CAPTIONHELP         = &H0004???

%DFCS_MENUARROW           = &H0000???
%DFCS_MENUCHECK           = &H0001???
%DFCS_MENUBULLET          = &H0002???
%DFCS_MENUARROWRIGHT      = &H0004???
%DFCS_SCROLLUP            = &H0000???
%DFCS_SCROLLDOWN          = &H0001???
%DFCS_SCROLLLEFT          = &H0002???
%DFCS_SCROLLRIGHT         = &H0003???
%DFCS_SCROLLCOMBOBOX      = &H0005???
%DFCS_SCROLLSIZEGRIP      = &H0008???
%DFCS_SCROLLSIZEGRIPRIGHT = &H0010???

%DFCS_BUTTONCHECK         = &H0000???
%DFCS_BUTTONRADIOIMAGE    = &H0001???
%DFCS_BUTTONRADIOMASK     = &H0002???
%DFCS_BUTTONRADIO         = &H0004???
%DFCS_BUTTON3STATE        = &H0008???
%DFCS_BUTTONPUSH          = &H0010???

%DFCS_INACTIVE            = &H0100???
%DFCS_PUSHED              = &H0200???
%DFCS_CHECKED             = &H0400???

'#if(WINVER >= 0x0500)
%DFCS_TRANSPARENT         = &H0800???
%DFCS_HOT                 = &H1000???
'#endif /* WINVER >= 0x0500 */

%DFCS_ADJUSTRECT          = &H2000???
%DFCS_FLAT                = &H4000???
%DFCS_MONO                = &H8000???

DECLARE FUNCTION DrawFrameControl IMPORT "USER32.DLL" ALIAS "DrawFrameControl" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL uState AS DWORD _                              ' __in UINT uState
 ) AS LONG                                              ' BOOL

'/* flags for DrawCaption */
%DC_ACTIVE   = &H0001???
%DC_SMALLCAP = &H0002???
%DC_ICON     = &H0004???
%DC_TEXT     = &H0008???
%DC_INBUTTON = &H0010???
'#if(WINVER >= 0x0500)
%DC_GRADIENT = &H0020???
'#endif /* WINVER >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0501)
%DC_BUTTONS  = &H1000???
'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION DrawCaption IMPORT "USER32.DLL" ALIAS "DrawCaption" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprect AS RECT _                               ' __in CONST RECT * lprect
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' BOOL

'#define IDANI_OPEN          1
'#define IDANI_CAPTION       3
%IDANI_OPEN    = 1&
%IDANI_CAPTION = 3&

DECLARE FUNCTION DrawAnimatedRects IMPORT "USER32.DLL" ALIAS "DrawAnimatedRects" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL idAni AS LONG _                                ' __in int idAni
 , BYREF lprcFrom AS RECT _                             ' __in CONST RECT *lprcFrom
 , BYREF lprcTo AS RECT _                               ' __in CONST RECT *lprcTo
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */

'#IF NOT %DEF(%NOCLIPBOARD) ' --------------------------------------------------
'#ifndef NOCLIPBOARD

'/*
' * Predefined Clipboard Formats
' */
%CF_TEXT            =  1???
%CF_BITMAP          =  2???
%CF_METAFILEPICT    =  3???
%CF_SYLK            =  4???
%CF_DIF             =  5???
%CF_TIFF            =  6???
%CF_OEMTEXT         =  7???
%CF_DIB             =  8???
%CF_PALETTE         =  9???
%CF_PENDATA         = 10???
%CF_RIFF            = 11???
%CF_WAVE            = 12???
%CF_UNICODETEXT     = 13???
%CF_ENHMETAFILE     = 14???
'#if(WINVER >= 0x0400)
%CF_HDROP           = 15???
%CF_LOCALE          = 16???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0500)
%CF_DIBV5           = 17???
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0500)
%CF_MAX             = 18???   ' varies by Windows version
'#elif(WINVER >= 0x0400)
'#define CF_MAX              17
'#else
'#define CF_MAX              15
'#endif

%CF_OWNERDISPLAY    = &H0080???
%CF_DSPTEXT         = &H0081???
%CF_DSPBITMAP       = &H0082???
%CF_DSPMETAFILEPICT = &H0083???
%CF_DSPENHMETAFILE  = &H008E???

'/*
' * "Private" formats don't get GlobalFree()'d
' */
%CF_PRIVATEFIRST    = &H0200???
%CF_PRIVATELAST     = &H02FF???

'/*
' * "GDIOBJ" formats do get DeleteObject()'d
' */
%CF_GDIOBJFIRST     = &H0300???
%CF_GDIOBJLAST      = &H03FF???

'#endif /* !NOCLIPBOARD */
'#ENDIF   ' #IF NOT %DEF(%NOCLIPBOARD) ' ---------------------------------------

'/*
' * Defines for the fVirt field of the Accelerator table structure.
' */
%FVIRTKEY   = &H01?        ' Assumed to be == TRUE
%FNOINVERT  = &H02?
%FSHIFT     = &H04?
%FCONTROL   = &H08?
%FALT       = &H10?

' // Size = 6 bytes
TYPE ACCELAPI WORD
   fVirt AS BYTE   ' BYTE
   key   AS WORD   ' WORD
   cmd   AS WORD   ' WORD
END TYPE
MACRO tagACCEL = ACCELAPI

' // Size = 64 bytes
TYPE PAINTSTRUCT DWORD
   hDC             AS DWORD   ' HDC
   fErase          AS LONG    ' BOOL
   rcPaint         AS RECT    ' RECT
   fRestore        AS LONG    ' BOOL
   fIncUpdate      AS LONG    ' BOOL
   rgbReserved(31) AS BYTE    ' BYTE rgbReserved[32]
END TYPE

' // Size = 48 bytes
TYPE CREATESTRUCTA DWORD
   lpCreateParams AS LONG          ' LPVOID
   hInstance      AS DWORD         ' HINSTANCE
   hMenu          AS DWORD         ' HMENU
   hwndParent     AS DWORD         ' HWND
   cy             AS LONG          ' int
   cx             AS LONG          ' int
   y              AS LONG          ' int
   x              AS LONG          ' int
   style          AS LONG          ' LONG
   lpszName       AS ASCIIZ PTR    ' LPCSTR
   lpszClass      AS ASCIIZ PTR    ' LPCSTR
   dwExStyle      AS DWORD         ' DWORD
END TYPE

' // Size = 48 bytes
TYPE CREATESTRUCTW DWORD
   lpCreateParams AS LONG           ' LPVOID
   hInstance      AS DWORD          ' HINSTANCE
   hMenu          AS DWORD          ' HMENU
   hwndParent     AS DWORD          ' HWND
   cy             AS LONG           ' int
   cx             AS LONG           ' int
   y              AS LONG           ' int
   x              AS LONG           ' int
   style          AS LONG           ' LONG
   lpszName       AS WSTRINGZ PTR   ' LPCWSTR
   lpszClass      AS WSTRINGZ PTR   ' LPCWSTR
   dwExStyle      AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
MACRO CREATESTRUCT = CREATESTRUCTW
#ELSE
MACRO CREATESTRUCT = CREATESTRUCTA
#ENDIF ' UNICODE

'/*
' * HCBT_CREATEWND parameters pointed to by lParam
' */

' // Size = 8 bytes
TYPE CBT_CREATEWNDA DWORD
   lpcs            AS CREATESTRUCTA PTR   ' struct tagCREATESTRUCTA*
   hWndInsertAfter AS DWORD               ' HWND
END TYPE

' // Size = 8 bytes
TYPE CBT_CREATEWNDW DWORD
   lpcs            AS CREATESTRUCTW PTR   ' struct tagCREATESTRUCTW*
   hWndInsertAfter AS DWORD               ' HWND
END TYPE

#IF %DEF(%UNICODE)
MACRO CBT_CREATEWND = CBT_CREATEWNDW
#ELSE
MACRO CBT_CREATEWND = CBT_CREATEWNDA
#ENDIF ' UNICODE

' // Size = 8 bytes
TYPE WINDOWPLACEMENT DWORD
   length           AS DWORD   ' UINT
   flags            AS DWORD   ' UINT
   showCmd          AS DWORD   ' UINT
   ptMinPosition    AS POINT   ' POINT
   ptMaxPosition    AS POINT   ' POINT
   rcNormalPosition AS RECT    ' RECT
END TYPE

%WPF_SETMINPOSITION       = &H0001???
%WPF_RESTORETOMAXIMIZED   = &H0002???
'#if(_WIN32_WINNT >= 0x0500)
%WPF_ASYNCWINDOWPLACEMENT = &H0004???
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(WINVER >= 0x0400)
' // Size = 12 bytes
' // Note: NMHDR is built-in in PB
' // code should be DWORD, but it is defined as LONG in PBWin 9 built-in structure
TYPE NMHDR   ' DWORD
   hwndFrom AS DWORD   ' HWND
   idfrom   AS DWORD   ' UINT_PTR
   code     AS LONG    ' UINT // NM_ code
END TYPE

' // Size = 8 bytes
TYPE STYLESTRUCT DWORD
   styleOld AS DWORD   ' DWORD
   styleNew AS DWORD   ' DWORD
END TYPE
'#endif /* WINVER >= 0x0400 */

'/*
' * Owner draw control types
' */
%ODT_MENU      = 1&
%ODT_LISTBOX   = 2&
%ODT_COMBOBOX  = 3&
%ODT_BUTTON    = 4&
'#endif /* WINVER >= 0x0400 */
%ODT_STATIC    = 5&

'/*
' * Owner draw actions
' */
%ODA_DRAWENTIRE = &H0001???
%ODA_SELECT     = &H0002???
%ODA_FOCUS      = &H0004???

'/*
' * Owner draw state
' */
%ODS_SELECTED        = &H0001???
%ODS_GRAYED          = &H0002???
%ODS_DISABLED        = &H0004???
%ODS_CHECKED         = &H0008???
%ODS_FOCUS           = &H0010???
'#if(WINVER >= = &H0400)
%ODS_DEFAULT         = &H0020???
%ODS_COMBOBOXEDIT    = &H1000???
'#endif /* WINVER >= = &H0400 */
'#if(WINVER >= = &H0500)
%ODS_HOTLIGHT        = &H0040???
%ODS_INACTIVE        = &H0080???
'#if(_WIN32_WINNT >= = &H0500)
%ODS_NOACCEL         = &H0100???
%ODS_NOFOCUSRECT     = &H0200???
'#endif /* _WIN32_WINNT >= 0x0500 */
'#endif /* WINVER >= 0x0500 */

'/*
' * MEASUREITEMSTRUCT for ownerdraw
' */

' // Size = 24 bytes
TYPE MEASUREITEMSTRUCT DWORD
   CtlType    AS DWORD   ' UINT
   CtlID      AS DWORD   ' UINT
   itemID     AS DWORD   ' UINT
   itemWidth  AS DWORD   ' UINT
   itemHeight AS DWORD   ' UINT
   itemData   AS DWORD   ' ULONG_PTR
END TYPE

'/*
' * DRAWITEMSTRUCT for ownerdraw
' */

' // Size = 48 bytes
TYPE DRAWITEMSTRUCT DWORD
   CtlType    AS DWORD   ' UINT
   CtlID      AS DWORD   ' UINT
   itemID     AS DWORD   ' UINT
   itemAction AS DWORD   ' UINT
   itemState  AS DWORD   ' UINT
   hwndItem   AS DWORD   ' HWND
   hDC        AS DWORD   ' HDC
   rcItem     AS RECT    ' RECT
   itemData   AS DWORD   ' ULONG_PTR
END TYPE

'/*
' * DELETEITEMSTRUCT for ownerdraw
' */

' // Size = 20 bytes
TYPE DELETEITEMSTRUCT DWORD
   CtlType  AS DWORD   ' UINT
   CtlID    AS DWORD   ' UINT
   itemID   AS DWORD   ' UINT
   hwndItem AS LONG    ' HWND
   itemData AS DWORD   ' ULONG_PTR
END TYPE

'/*
' * COMPAREITEMSTUCT for ownerdraw sorting
' */

' // Size = 32 bytes
TYPE COMPAREITEMSTRUCT DWORD
   CtlType    AS DWORD   ' UINT
   CtlID      AS DWORD   ' UINT
   hwndItem   AS DWORD   ' HWND
   itemID1    AS DWORD   ' UINT
   itemData1  AS DWORD   ' ULONG_PTR
   itemID2    AS DWORD   ' UINT
   itemData2  AS DWORD   ' ULONG_PTR
   dwLocaleId AS DWORD   ' DWORD
END TYPE

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

'/*
' * Message Function Templates
' */

DECLARE FUNCTION GetMessageA IMPORT "USER32.DLL" ALIAS "GetMessageA" ( _
   BYREF lpMsg AS tagMSG _                              ' __out LPMSG lpMsg
 , BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL wMsgFilterMin AS DWORD _                       ' __in UINT wMsgFilterMin
 , BYVAL wMsgFilterMax AS DWORD _                       ' __in UINT wMsgFilterMax
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMessageW IMPORT "USER32.DLL" ALIAS "GetMessageW" ( _
   BYREF lpMsg AS tagMSG _                              ' __out LPMSG lpMsg
 , BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL wMsgFilterMin AS DWORD _                       ' __in UINT wMsgFilterMin
 , BYVAL wMsgFilterMax AS DWORD _                       ' __in UINT wMsgFilterMax
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetMessage = GetMessageW
#ELSE
   MACRO GetMessage = GetMessageA
#ENDIF

DECLARE FUNCTION TranslateMessage IMPORT "USER32.DLL" ALIAS "TranslateMessage" ( _
   BYREF lpMsg AS tagMSG _                              ' __in CONST MSG *lpMsg
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DispatchMessageA IMPORT "USER32.DLL" ALIAS "DispatchMessageA" ( _
   BYREF lpMsg AS tagMSG _                              ' __in CONST MSG *lpMsg
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DispatchMessageW IMPORT "USER32.DLL" ALIAS "DispatchMessageW" ( _
   BYREF lpMsg AS tagMSG _                              ' __in CONST MSG *lpMsg
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO DispatchMessage = DispatchMessageW
#ELSE
   MACRO DispatchMessage = DispatchMessageA
#ENDIF

DECLARE FUNCTION SetMessageQueue IMPORT "USER32.DLL" ALIAS "SetMessageQueue" ( _
   BYVAL cMessagesMax AS LONG _                         ' __in int cMessagesMax
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PeekMessageA IMPORT "USER32.DLL" ALIAS "PeekMessageA" ( _
   BYREF lpMsg AS tagMSG _                              ' __out LPMSG lpMsg
 , BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL wMsgFilterMin AS DWORD _                       ' __in UINT wMsgFilterMin
 , BYVAL wMsgFilterMax AS DWORD _                       ' __in UINT wMsgFilterMax
 , BYVAL wRemoveMsg AS DWORD _                          ' __in UINT wRemoveMsg
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PeekMessageW IMPORT "USER32.DLL" ALIAS "PeekMessageW" ( _
   BYREF lpMsg AS tagMSG _                              ' __out LPMSG lpMsg
 , BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL wMsgFilterMin AS DWORD _                       ' __in UINT wMsgFilterMin
 , BYVAL wMsgFilterMax AS DWORD _                       ' __in UINT wMsgFilterMax
 , BYVAL wRemoveMsg AS DWORD _                          ' __in UINT wRemoveMsg
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PeekMessage = PeekMessageW
#ELSE
   MACRO PeekMessage = PeekMessageA
#ENDIF

'/*
' * PeekMessage() Options
' */
%PM_NOREMOVE       = &H0000???
%PM_REMOVE         = &H0001???
%PM_NOYIELD        = &H0002???
'#if(WINVER >= 0x0500)
%PM_QS_INPUT       = %QS_INPUT * 256
%PM_QS_POSTMESSAGE = (%QS_POSTMESSAGE OR %QS_HOTKEY OR %QS_TIMER) * 256
%PM_QS_PAINT       = %QS_PAINT * 256
%PM_QS_SENDMESSAGE = %QS_SENDMESSAGE * 256
'#endif /* WINVER >= 0x0500 */

'#endif /* !NOMSG */
'#ENDIF   ' #IF NOT %DEF(%NOMSG) '----------------------------------------------

DECLARE FUNCTION RegisterHotKey IMPORT "USER32.DLL" ALIAS "RegisterHotKey" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL id AS LONG _                                   ' __in int id
 , BYVAL fsModifiers AS LONG _                          ' __in UINT fsModifiers
 , BYVAL vk AS LONG _                                   ' __in UINT vk
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnregisterHotKey IMPORT "USER32.DLL" ALIAS "UnregisterHotKey" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL id AS LONG _                                   ' __in int id
 ) AS LONG                                              ' BOOL

%MOD_ALT        = &H0001???
%MOD_CONTROL    = &H0002???
%MOD_SHIFT      = &H0004???
%MOD_WIN        = &H0008???
'#if(WINVER >= 0x0601)
%MOD_NOREPEAT   = &H4000???
'#endif /* WINVER >= 0x0601 */

%IDHOT_SNAPWINDOW  = -1&    ' SHIFT-PRINTSCRN
%IDHOT_SNAPDESKTOP = -2&    ' PRINTSCRN

'#ifdef WIN_INTERNAL
'    #ifndef LSTRING
'    #define NOLSTRING
'    #endif /* LSTRING */
'    #ifndef LFILEIO
'    #define NOLFILEIO
'    #endif /* LFILEIO */
'#endif /* WIN_INTERNAL */

'#if(WINVER >= 0x0400)
%ENDSESSION_LOGOFF   = &H80000000???
%ENDSESSION_CRITICAL = &H40000000???
%ENDSESSION_CLOSEAPP = &H00000001???
'#endif /* WINVER >= 0x0400 */

%EWX_LOGOFF       = 0???
%EWX_SHUTDOWN     = &H00000001???
%EWX_REBOOT       = &H00000002???
%EWX_FORCE        = &H00000004???
%EWX_POWEROFF     = &H00000008???
'#if(_WIN32_WINNT >= 0x0500)
%EWX_FORCEIFHUNG  = &H00000010???
'#endif /* _WIN32_WINNT >= 0x0500 */
%EWX_QUICKRESOLVE = &H00000020???
'#if(_WIN32_WINNT >= 0x0600)
%EWX_RESTARTAPPS  = &H00000040???
'#endif /* _WIN32_WINNT >= 0x0600 */

DECLARE FUNCTION ExitWindowsEx IMPORT "USER32.DLL" ALIAS "ExitWindowsEx" ( _
   BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL dwReason AS DWORD _                            ' __in DWORD dwReason
 ) AS LONG                                              ' BOOL

'#define ExitWindows(dwReserved, Code) ExitWindowsEx(EWX_LOGOFF, 0xFFFFFFFF)
FUNCTION ExitWindows (OPTIONAL BYVAL dwReserved AS DWORD, BYVAL uReserved AS DWORD) AS LONG
   FUNCTION = ExitWindowsEx(%EWX_LOGOFF, &HFFFFFFFF???)
END FUNCTION

DECLARE FUNCTION SwapMouseButton IMPORT "USER32.DLL" ALIAS "SwapMouseButton" ( _
   BYVAL fSwap AS LONG _                                ' __in BOOL fSwap
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMessagePos IMPORT "USER32.DLL" ALIAS "GetMessagePos" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetMessageTime IMPORT "USER32.DLL" ALIAS "GetMessageTime" ( _
 ) AS LONG                                              ' LONG

DECLARE FUNCTION GetMessageExtraInfo IMPORT "USER32.DLL" ALIAS "GetMessageExtraInfo" ( _
 ) AS LONG                                              ' LPARAM

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION IsWow64Message IMPORT "USER32.DLL" ALIAS "IsWow64Message" ( _
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(WINVER >= 0x0400)
DECLARE FUNCTION SetMessageExtraInfo IMPORT "USER32.DLL" ALIAS "SetMessageExtraInfo" ( _
   BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LPARAM
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION SendMessageA IMPORT "USER32.DLL" ALIAS "SendMessageA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION SendMessageW IMPORT "USER32.DLL" ALIAS "SendMessageW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam)
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO SendMessage = SendMessageW
#ELSE
   MACRO SendMessage = SendMessageA
#ENDIF

DECLARE FUNCTION SendMessageTimeoutA IMPORT "USER32.DLL" ALIAS "SendMessageTimeoutA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL fuFlags AS DWORD _                             ' __in UINT fuFlags
 , BYVAL uTimeout AS DWORD _                            ' __in UINT uTimeout
 , OPTIONAL BYREF lpdwResult AS DWORD _                 ' __out_opt PDWORD_PTR lpdwResult
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION SendMessageTimeoutW IMPORT "USER32.DLL" ALIAS "SendMessageTimeoutW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL fuFlags AS DWORD _                             ' __in UINT fuFlags
 , BYVAL uTimeout AS DWORD _                            ' __in UINT uTimeout
 , OPTIONAL BYREF lpdwResult AS DWORD _                 ' __out_opt PDWORD_PTR lpdwResult
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO SendMessageTimeout = SendMessageTimeoutW
#ELSE
   MACRO SendMessageTimeout = SendMessageTimeoutA
#ENDIF

DECLARE FUNCTION SendNotifyMessageA IMPORT "USER32.DLL" ALIAS "SendNotifyMessageA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SendNotifyMessageW IMPORT "USER32.DLL" ALIAS "SendNotifyMessageW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SendNotifyMessage = SendNotifyMessageW
#ELSE
   MACRO SendNotifyMessage = SendNotifyMessageA
#ENDIF

DECLARE FUNCTION SendMessageCallbackA IMPORT "USER32.DLL" ALIAS "SendMessageCallbackA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL lpResultCallBack AS DWORD _                    ' __in SENDASYNCPROC lpResultCallBack
 , BYVAL dwData AS DWORD _                              ' __in ULONG_PTR dwData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SendMessageCallbackW IMPORT "USER32.DLL" ALIAS "SendMessageCallbackW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL lpResultCallBack AS DWORD _                    ' __in SENDASYNCPROC lpResultCallBack
 , BYVAL dwData AS DWORD _                              ' __in ULONG_PTR dwData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SendMessageCallback = SendMessageCallbackW
#ELSE
   MACRO SendMessageCallback = SendMessageCallbackA
#ENDIF

'#if(_WIN32_WINNT >= 0x0501)
' // Size = 20 bytes
TYPE BSMINFO DWORD
   cbSize AS DWORD   ' UINT
   hdesk  AS DWORD   ' HDESK
   hwnd   AS DWORD   ' HWND
   luid   AS QUAD    ' LUID
END TYPE

DECLARE FUNCTION BroadcastSystemMessageExA IMPORT "USER32.DLL" ALIAS "BroadcastSystemMessageExA" ( _
   BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpInfo AS DWORD _                              ' __inout_opt LPDWORD lpInfo
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , OPTIONAL BYREF pbsmInfo AS BSMINFO _                 ' __out_opt PBSMINFO pbsmInfo
 ) AS LONG                                              ' long

DECLARE FUNCTION BroadcastSystemMessageExW IMPORT "USER32.DLL" ALIAS "BroadcastSystemMessageExW" ( _
   BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpInfo AS DWORD _                              ' __inout_opt LPDWORD lpInfo
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , OPTIONAL BYREF pbsmInfo AS BSMINFO _                 ' __out_opt PBSMINFO pbsmInfo
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO BroadcastSystemMessageEx = BroadcastSystemMessageExW
#ELSE
   MACRO BroadcastSystemMessageEx = BroadcastSystemMessageExA
#ENDIF

'#if(WINVER >= 0x0400)

'#if defined(_WIN32_WINNT)
DECLARE FUNCTION BroadcastSystemMessageA IMPORT "USER32.DLL" ALIAS "BroadcastSystemMessageA" ( _
   BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpInfo AS DWORD _                              ' __inout_opt LPDWORD lpInfo
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' long

DECLARE FUNCTION BroadcastSystemMessageW IMPORT "USER32.DLL" ALIAS "BroadcastSystemMessageW" ( _
   BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpInfo AS DWORD _                              ' __inout_opt LPDWORD lpInfo
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD  _                             ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO BroadcastSystemMessage = BroadcastSystemMessageW
#ELSE
   MACRO BroadcastSystemMessage = BroadcastSystemMessageA
#ENDIF

'// The Win95 version isn't A/W decorated
DECLARE FUNCTION BroadcastSystemMessage IMPORT "USER32.DLL" ALIAS "BroadcastSystemMessage" ( _
   BYVAL flags AS DWORD _                               ' __in DWORD flags
 , BYREF lpInfo AS DWORD _                              ' __inout_opt LPDWORD lpInfo
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' long

'#endif

'//Broadcast Special Message Recipient list
%BSM_ALLCOMPONENTS       = &H00000000???
%BSM_VXDS                = &H00000001???
%BSM_NETDRIVER           = &H00000002???
%BSM_INSTALLABLEDRIVERS  = &H00000004???
%BSM_APPLICATIONS        = &H00000008???
%BSM_ALLDESKTOPS         = &H00000010???

'//Broadcast Special Message Flags
%BSF_QUERY               = &H00000001???
%BSF_IGNORECURRENTTASK   = &H00000002???
%BSF_FLUSHDISK           = &H00000004???
%BSF_NOHANG              = &H00000008???
%BSF_POSTMESSAGE         = &H00000010???
%BSF_FORCEIFHUNG         = &H00000020???
%BSF_NOTIMEOUTIFNOTHUNG  = &H00000040???
'#if(_WIN32_WINNT >= 0x0500)
%BSF_ALLOWSFW            = &H00000080???
%BSF_SENDNOTIFYMESSAGE   = &H00000100???
'#endif /* _WIN32_WINNT >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0501)
%BSF_RETURNHDESK         = &H00000200???
%BSF_LUID                = &H00000400???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#define BROADCAST_QUERY_DENY         0x424D5144  // Return this value to deny a query.
%BROADCAST_QUERY_DENY    = &H424D5144???  ' Return this value to deny a query.
'#endif /* WINVER >= 0x0400 */

'// RegisterDeviceNotification

'#if(WINVER >= 0x0500)
'typedef  PVOID           HDEVNOTIFY;
'typedef  HDEVNOTIFY     *PHDEVNOTIFY;

%DEVICE_NOTIFY_WINDOW_HANDLE         = &H00000000???
%DEVICE_NOTIFY_SERVICE_HANDLE        = &H00000001???
'#if(_WIN32_WINNT >= 0x0501)
%DEVICE_NOTIFY_ALL_INTERFACE_CLASSES = &H00000004???
'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION RegisterDeviceNotificationA IMPORT "USER32.DLL" ALIAS "RegisterDeviceNotificationA" ( _
   BYVAL hRecipient AS DWORD _                          ' __in HANDLE hRecipient
 , BYREF NotificationFilter AS ANY _                    ' __in LPVOID NotificationFilter
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HDEVNOTIFY

DECLARE FUNCTION RegisterDeviceNotificationW IMPORT "USER32.DLL" ALIAS "RegisterDeviceNotificationW" ( _
   BYVAL hRecipient AS DWORD _                          ' __in HANDLE hRecipient
 , BYREF NotificationFilter AS ANY _                    ' __in LPVOID NotificationFilter
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HDEVNOTIFY

#IF %DEF(%UNICODE)
   MACRO RegisterDeviceNotification = RegisterDeviceNotificationW
#ELSE
   MACRO RegisterDeviceNotification = RegisterDeviceNotificationA
#ENDIF

DECLARE FUNCTION UnregisterDeviceNotification IMPORT "USER32.DLL" ALIAS "UnregisterDeviceNotification" ( _
   BYVAL Handle AS DWORD _                              ' __in HDEVNOTIFY Handle
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0502)

'#if !defined(_HPOWERNOTIFY_DEF_)

'#define _HPOWERNOTIFY_DEF_

'typedef  PVOID           HPOWERNOTIFY;
'typedef  HPOWERNOTIFY   *PHPOWERNOTIFY;

'#endif

DECLARE FUNCTION RegisterPowerSettingNotification IMPORT "USER32.DLL" ALIAS "RegisterPowerSettingNotification" ( _
   BYVAL hRecipient AS DWORD _                          ' __in HANDLE hRecipient
 , BYREF PowerSettingGuid AS GUID _                     ' __in LPCGUID PowerSettingGuid
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HPOWERNOTIFY

DECLARE FUNCTION UnregisterPowerSettingNotification IMPORT "USER32.DLL" ALIAS "UnregisterPowerSettingNotification" ( _
   BYVAL Handle AS DWORD _                              ' __in HDEVNOTIFY Handle
 ) AS LONG                                              ' BOOL
'#endif // (_WIN32_WINNT >= 0x0502)
'#endif /* WINVER >= 0x0500 */


DECLARE FUNCTION PostMessageA IMPORT "USER32.DLL" ALIAS "PostMessageA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD  _                             ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PostMessageW IMPORT "USER32.DLL" ALIAS "PostMessageW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PostMessage = PostMessageW
#ELSE
   MACRO PostMessage = PostMessageA
#ENDIF

DECLARE FUNCTION PostThreadMessageA IMPORT "USER32.DLL" ALIAS "PostThreadMessageA" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PostThreadMessageW IMPORT "USER32.DLL" ALIAS "PostThreadMessageW" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PostThreadMessage = PostThreadMessageW
#ELSE
   MACRO PostThreadMessage = PostThreadMessageA
#ENDIF

'#define PostAppMessageA(idThread, wMsg, wParam, lParam)\
'        PostThreadMessageA((DWORD)idThread, wMsg, wParam, lParam)
'MACRO PostAppMessage(idThread, wMsg, wParam, lParam) = PostThreadMessage(idThread, wMsg, wParam, lParam)

'#define PostAppMessageW(idThread, wMsg, wParam, lParam)\
'        PostThreadMessageW((DWORD)idThread, wMsg, wParam, lParam)
'MACRO PostAppMessageW(idThread, wMsg, wParam, lParam) = PostThreadMessageW(idThread, wMsg, wParam, lParam)

#IF %DEF(%UNICODE)
   MACRO PostAppMessage = PostThreadMessageW
#ELSE
   MACRO PostAppMessage = PostThreadMessageA
#ENDIF

'/*
' * Special HWND value for use with PostMessage() and SendMessage()
' */
'#define HWND_BROADCAST  ((HWND)0xffff)
%HWND_BROADCAST = &HFFFFFFFF???

'#if(WINVER >= 0x0500)
'#define HWND_MESSAGE     ((HWND)-3)
%HWND_MESSAGE   = &HFFFFFFFD???
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION AttachThreadInput IMPORT "USER32.DLL" ALIAS "AttachThreadInput" ( _
   BYVAL idAttach AS DWORD _                            ' __in DWORD idAttach
 , BYVAL idAttachTo AS DWORD _                          ' __in DWORD idAttachTo
 , BYVAL fAttach AS LONG _                              ' __in BOOL fAttach
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReplyMessage IMPORT "USER32.DLL" ALIAS "ReplyMessage" ( _
   BYVAL lResult AS LONG _                              ' __in LRESULT lResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WaitMessage IMPORT "USER32.DLL" ALIAS "WaitMessage" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WaitForInputIdle IMPORT "USER32.DLL" ALIAS "WaitForInputIdle" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DefWindowProcA IMPORT "USER32.DLL" ALIAS "DefWindowProcA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DefWindowProcW IMPORT "USER32.DLL" ALIAS "DefWindowProcW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO DefWindowProc = DefWindowProcW
#ELSE
   MACRO DefWindowProc = DefWindowProcA
#ENDIF

DECLARE SUB PostQuitMessage IMPORT "USER32.DLL" ALIAS "PostQuitMessage" ( _
   BYVAL nExitCode AS LONG _                            ' __in int nExitCode
 )                                                      ' VOID

DECLARE FUNCTION CallWindowProcA IMPORT "USER32.DLL" ALIAS "CallWindowProcA" ( _
   BYVAL lpPrevWndFunc AS DWORD _                       ' __in FARPROC lpPrevWndFunc
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION CallWindowProcW IMPORT "USER32.DLL" ALIAS "CallWindowProcW" ( _
   BYVAL lpPrevWndFunc AS DWORD _                       ' __in FARPROC lpPrevWndFunc
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO CallWindowProc = CallWindowProcW
#ELSE
   MACRO CallWindowProc = CallWindowProcA
#ENDIF

DECLARE FUNCTION InSendMessage IMPORT "USER32.DLL" ALIAS "InSendMessage" ( _
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION InSendMessageEx LIB "User32.dll" ALIAS "InSendMessageEx" _
    (lpReserved AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION InSendMessageEx IMPORT "USER32.DLL" ALIAS "InSendMessageEx" ( _
   BYVAL lpReserved AS DWORD _                          ' __reserved LPVOID lpReserved
 ) AS DWORD                                             ' DWORD
#ENDIF

'/*
' * InSendMessageEx return value
' */
%ISMEX_NOSEND   = &H00000000???
%ISMEX_SEND     = &H00000001???
%ISMEX_NOTIFY   = &H00000002???
%ISMEX_CALLBACK = &H00000004???
%ISMEX_REPLIED  = &H00000008???

'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION GetDoubleClickTime IMPORT "USER32.DLL" ALIAS "GetDoubleClickTime" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetDoubleClickTime IMPORT "USER32.DLL" ALIAS "SetDoubleClickTime" ( _
   BYVAL uInterval AS DWORD _                           ' __in UINT uInterval
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RegisterClassA IMPORT "USER32.DLL" ALIAS "RegisterClassA" ( _
   BYREF lpWndClass AS WNDCLASSA _                      ' __in CONST WNDCLASSA *lpWndClass
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION RegisterClassW IMPORT "USER32.DLL" ALIAS "RegisterClassW" ( _
   BYREF lpWndClass AS WNDCLASSW _                      ' __in CONST WNDCLASSW *lpWndClass
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO RegisterClass = RegisterClassW
#ELSE
   MACRO RegisterClass = RegisterClassA
#ENDIF

DECLARE FUNCTION UnregisterClassA IMPORT "USER32.DLL" ALIAS "UnregisterClassA" ( _
   BYREF lpClassName AS ASCIIZ _                        ' __in LPCSTR lpClassName
 , OPTIONAL BYVAL hInstance AS DWORD _                  ' __in_opt HINSTANCE hInstance
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnregisterClassW IMPORT "USER32.DLL" ALIAS "UnregisterClassW" ( _
   BYREF lpClassName AS WSTRINGZ _                      ' __in LPCWSTR lpClassName
 , OPTIONAL BYVAL hInstance AS DWORD _                  ' __in_opt HINSTANCE hInstance
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UnregisterClass = UnregisterClassW
#ELSE
   MACRO UnregisterClass = UnregisterClassA
#ENDIF

DECLARE FUNCTION GetClassInfoA IMPORT "USER32.DLL" ALIAS "GetClassInfoA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpClassName AS ASCIIZ _                        ' __in LPCSTR lpClassName
 , BYREF lpWndClass AS WNDCLASSA _                      ' __out LPWNDCLASSA lpWndClass
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetClassInfoW IMPORT "USER32.DLL" ALIAS "GetClassInfoW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpClassName AS WSTRINGZ _                      ' __in LPCWSTR lpClassName
 , BYREF lpWndClass AS WNDCLASSW _                      ' __out LPWNDCLASSW lpWndClass
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetClassInfo = GetClassInfoW
#ELSE
   MACRO GetClassInfo = GetClassInfoA
#ENDIF

'#if(WINVER >= 0x0400)
DECLARE FUNCTION RegisterClassExA IMPORT "USER32.DLL" ALIAS "RegisterClassExA" ( _
   BYREF lpwcx AS WNDCLASSEXA _                         ' __in CONST WNDCLASSEXA *lpwcx
 ) AS WORD                                              ' ATOM

DECLARE FUNCTION RegisterClassExW IMPORT "USER32.DLL" ALIAS "RegisterClassExW" ( _
   BYREF lpwcx AS WNDCLASSEXW _                         ' __in CONST WNDCLASSEXW *lpwcx
 ) AS WORD                                              ' ATOM

#IF %DEF(%UNICODE)
   MACRO RegisterClassEx = RegisterClassExW
#ELSE
   MACRO RegisterClassEx = RegisterClassExA
#ENDIF

DECLARE FUNCTION GetClassInfoExA IMPORT "USER32.DLL" ALIAS "GetClassInfoExA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpszClass AS ASCIIZ _                          ' __in LPCSTR lpszClass
 , BYREF lpwcx AS WNDCLASSEXA _                         ' __out LPWNDCLASSEXA lpwcx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetClassInfoExW IMPORT "USER32.DLL" ALIAS "GetClassInfoExW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpszClass AS WSTRINGZ _                        ' __in LPCWSTR lpszClass
 , BYREF lpwcx AS WNDCLASSEXW _                         ' __out LPWNDCLASSEXW lpwcx
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetClassInfoEx = GetClassInfoExW
#ELSE
   MACRO GetClassInfoEx = GetClassInfoExA
#ENDIF

'#endif /* WINVER >= 0x0400 */

'#define CW_USEDEFAULT       ((int)0x80000000)
%CW_USEDEFAULT  = &H80000000&

'/*
' * Special value for CreateWindow, et al.
' */
'#define HWND_DESKTOP        ((HWND)0)
'%HWND_DESKTOP   = 0???

'#if(_WIN32_WINNT >= 0x0501)
'typedef BOOLEAN (WINAPI * PREGISTERCLASSNAMEW)(LPCWSTR);
'#endif /* _WIN32_WINNT >= 0x0501 */

' ========================================================================================
' Creates an overlapped, pop-up, or child window with an extended window style; otherwise,
' this function is identical to the CreateWindow function. For more information about
' creating a window and for full descriptions of the other parameters of CreateWindowEx,
' see CreateWindow.
' ========================================================================================
DECLARE FUNCTION CreateWindowExA IMPORT "USER32.DLL" ALIAS "CreateWindowExA" ( _
   BYVAL dwExStyle AS DWORD _                           ' __in DWORD dwExStyle
 , BYREF lpClassName AS ASCIIZ _                        ' __in_opt LPCSTR lpClassName
 , BYREF lpWindowName AS ASCIIZ _                       ' __in_opt LPCSTR lpWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL hMenu AS DWORD _                      ' __in_opt HMENU hMenu
 , OPTIONAL BYVAL hInstance AS DWORD _                  ' __in_opt HINSTANCE hInstance
 , OPTIONAL BYREF lpParam AS ANY _                      ' __in_opt LPVOID lpParam
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateWindowExW IMPORT "USER32.DLL" ALIAS "CreateWindowExW" ( _
   BYVAL dwExStyle AS DWORD _                           ' __in DWORD dwExStyle
 , BYREF lpClassName AS WSTRINGZ _                      ' __in_opt LPCWSTR lpClassName
 , BYREF lpWindowName AS WSTRINGZ _                     ' __in_opt LPCWSTR lpWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL hMenu AS DWORD _                      ' __in_opt HMENU hMenu
 , OPTIONAL BYVAL hInstance AS DWORD _                  ' __in_opt HINSTANCE hInstance
 , OPTIONAL BYREF lpParam AS ANY _                      ' __in_opt LPVOID lpParam
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO CreateWindowEx = CreateWindowExW
#ELSE
   MACRO CreateWindowEx = CreateWindowExA
#ENDIF
' ========================================================================================

'#define CreateWindowA(lpClassName, lpWindowName, dwStyle, x, y,\
'nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)\
'CreateWindowExA(0L, lpClassName, lpWindowName, dwStyle, x, y,\
'nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)
'#define CreateWindowW(lpClassName, lpWindowName, dwStyle, x, y,\
'nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)\
'CreateWindowExW(0L, lpClassName, lpWindowName, dwStyle, x, y,\
'nWidth, nHeight, hwndParent, hMenu, hInstance, lpParam)

' ========================================================================================
' Creates an overlapped, pop-up, or child window. It specifies the window class, window
' title, window style, and (optionally) the initial position and size of the window. The
' function also specifies the window's parent or owner, if any, and the window's menu.
' To use extended window styles in addition to the styles supported by CreateWindow, use
' the CreateWindowEx function.
' ========================================================================================
' // Note: Implemented as functions instead of macros because, otherwise, conflict with
' // the CreateWindow method of the CWindow class.
FUNCTION CreateWindowA (BYREF lpClassName AS ASCIIZ, BYREF lpWindowName AS ASCIIZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, _
         BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, BYVAL hMenu AS DWORD, BYVAL hInstance AS DWORD, BYVAL lpParam AS DWORD) AS LONG
   FUNCTION = CreateWindowExA(0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, BYVAL lpParam)
END FUNCTION

FUNCTION CreateWindowW (BYREF lpClassName AS WSTRINGZ, BYREF lpWindowName AS WSTRINGZ, BYVAL dwStyle AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG, BYVAL nWidth AS LONG, _
         BYVAL nHeight AS LONG, BYVAL hwndParent AS DWORD, BYVAL hMenu AS DWORD, BYVAL hInstance AS DWORD, BYVAL lpParam AS DWORD) AS LONG
   FUNCTION = CreateWindowExW(0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, BYVAL lpParam)
END FUNCTION

#IF %DEF(%UNICODE)
   MACRO CreateWindow = CreateWindowW
#ELSE
   MACRO CreateWindow = CreateWindowA
#ENDIF
' ========================================================================================

DECLARE FUNCTION IsWindow IMPORT "USER32.DLL" ALIAS "IsWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsMenu IMPORT "USER32.DLL" ALIAS "IsMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsChild IMPORT "USER32.DLL" ALIAS "IsChild" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DestroyWindow IMPORT "USER32.DLL" ALIAS "DestroyWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShowWindow IMPORT "USER32.DLL" ALIAS "ShowWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nCmdShow AS LONG _                             ' __in int nCmdShow
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
DECLARE FUNCTION AnimateWindow IMPORT "USER32.DLL" ALIAS "AnimateWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwTime AS DWORD _                              ' __in DWORD dwTime
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)
'#if defined(_WINGDI_) && !defined(NOGDI)

DECLARE FUNCTION UpdateLayeredWindow IMPORT "USER32.DLL" ALIAS "UpdateLayeredWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hdcDst AS DWORD _                              ' __in_opt HDC hdcDst
 , BYREF pptDst AS POINT _                              ' __in_opt POINT *pptDst
 , BYREF psize AS SIZE _                                ' __in_opt SIZE *psize
 , BYVAL hdcSrc AS DWORD _                              ' __in_opt HDC hdcSrc
 , BYREF pptSrc AS POINT _                              ' __in_opt POINT *pptSrc
 , BYVAL crKey AS DWORD _                               ' __in COLORREF crKey
 , BYREF pblend AS BLENDFUNCTION _                      ' __in_opt BLENDFUNCTION *pblend
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'/*
' * Layered Window Update information
' */
' // Size = 40 bytes
TYPE UPDATELAYEREDWINDOWINFO DWORD
   cbSize   AS DWORD               ' DWORD
   hdcDst   AS DWORD               ' HDC
   pptDst   AS POINT PTR           ' POINT CONST
   psize    AS SIZE PTR            ' SIZE CONST
   hdcSrc   AS DWORD               ' HDC
   pptSrc   AS POINT PTR           ' POINT CONST
   crKey    AS DWORD               ' COLORREF
   pblend   AS BLENDFUNCTION PTR   ' BLENDFUNCTION CONST *
   dwFlags  AS DWORD               ' DWORD
   prcDirty AS RECT PTR            ' RECT CONST
END TYPE

DECLARE FUNCTION UpdateLayeredWindowIndirect IMPORT "USER32,DLL" ALIAS "UpdateLayeredWindowIndirect" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pULWInfo AS UPDATELAYEREDWINDOWINFO _          ' __in const *pULWInfo
 ) AS LONG                                              ' BOOL

'#endif

'#if(_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION GetLayeredWindowAttributes IMPORT "USER32.DLL" ALIAS "GetLayeredWindowAttributes" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , OPTIONAL BYREF pcrKey AS DWORD _                     ' __out_opt COLORREF *pcrKey
 , OPTIONAL BYREF pbAlpha AS BYTE _                     ' __out_opt BYTE *pbAlpha
 , OPTIONAL BYREF pdwFlags AS DWORD _                   ' __out_opt DWORD *pdwFlags
 ) AS LONG                                              ' BOOL

%PW_CLIENTONLY = &H00000001???

DECLARE FUNCTION PrintWindow IMPORT "USER32.DLL" ALIAS "PrintWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL hdcBlt AS DWORD _                              ' __in  HDC hdcBlt
 , BYVAL nFlags AS DWORD _                              ' __in  UINT nFlags
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION SetLayeredWindowAttributes IMPORT "USER32.DLL" ALIAS "SetLayeredWindowAttributes" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL crKey AS DWORD _                               ' __in COLORREF crKey
 , BYVAL bAlpha AS BYTE _                               ' __in BYTE bAlpha
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

%LWA_COLORKEY    = &H00000001???
%LWA_ALPHA       = &H00000002???

%ULW_COLORKEY    = &H00000001???
%ULW_ALPHA       = &H00000002???
%ULW_OPAQUE      = &H00000004???

%ULW_EX_NORESIZE = &H00000008???


'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(WINVER >= 0x0400)
DECLARE FUNCTION ShowWindowAsync IMPORT "USER32.DLL" ALIAS "ShowWindowAsync" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYVAL nCmdShow AS LONG _                             ' __in  int nCmdShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlashWindow IMPORT "USER32.DLL" ALIAS "FlashWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYVAL bInvert AS LONG _                              ' __in  BOOL bInvert
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
' // Size = 20 bytes
TYPE FLASHWINFO DWORD
   cbSize    AS DWORD   ' UINT
   hwnd      AS DWORD   ' HWND
   dwFlags   AS DWORD   ' DWORD
   uCount    AS DWORD   ' UINT
   dwTimeout AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION FlashWindowEx IMPORT "USER32.DLL" ALIAS "FlashWindowEx" ( _
   BYREF pfwi AS FLASHWINFO _                           ' __in PFLASHWINFO pfwi
 ) AS LONG                                              ' BOOL

%FLASHW_STOP      = 0???
%FLASHW_CAPTION   = &H00000001???
%FLASHW_TRAY      = &H00000002???
%FLASHW_ALL       = %FLASHW_CAPTION OR %FLASHW_TRAY
%FLASHW_TIMER     = &H00000004???
%FLASHW_TIMERNOFG = &H0000000C???

'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION ShowOwnedPopups IMPORT "USER32.DLL" ALIAS "ShowOwnedPopups" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYVAL fShow AS LONG _                                ' __in  BOOL fShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenIcon IMPORT "USER32.DLL" ALIAS "OpenIcon" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CloseWindow IMPORT "USER32.DLL" ALIAS "CloseWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MoveWindow IMPORT "USER32.DLL" ALIAS "MoveWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL bRepaint AS LONG _                             ' __in BOOL bRepaint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowPos IMPORT "USER32.DLL" ALIAS "SetWindowPos" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hWndInsertAfter AS DWORD _                     ' __in_opt HWND hWndInsertAfter
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowPlacement IMPORT "USER32.DLL" ALIAS "GetWindowPlacement" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpwndpl AS WINDOWPLACEMENT _                   ' __inout WINDOWPLACEMENT *lpwndpl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowPlacement IMPORT "USER32.DLL" ALIAS "SetWindowPlacement" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpwndpl AS WINDOWPLACEMENT _                   ' __in CONST WINDOWPLACEMENT *lpwndpl
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0601)
%WDA_NONE        = &H00000000???
%WDA_MONITOR     = &H00000001???

DECLARE FUNCTION GetWindowDisplayAffinity IMPORT "USER32.DLL" ALIAS "GetWindowDisplayAffinity" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pdwAffinity AS DWORD _                         ' __out DWORD* pdwAffinity
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowDisplayAffinity IMPORT "USER32.DLL" ALIAS "SetWindowDisplayAffinity" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwAffinity AS DWORD _                          ' __in DWORD dwAffinity
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0601 */

'#IF NOT %DEF(%NODEFERWINDOWPOS) ' ---------------------------------------------
'#ifndef NODEFERWINDOWPOS

DECLARE FUNCTION BeginDeferWindowPos IMPORT "USER32.DLL" ALIAS "BeginDeferWindowPos" ( _
   BYVAL nNumWindows AS LONG _                          ' __in int nNumWindows
 ) AS DWORD                                             ' HDWP

DECLARE FUNCTION DeferWindowPos IMPORT "USER32.DLL" ALIAS "DeferWindowPos" ( _
   BYVAL hWinPosInfo AS DWORD _                         ' __in HDWP hWinPosInfo
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hWndInsertAfter AS DWORD _                     ' __in_opt HWND hWndInsertAfter
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' HDWP

DECLARE FUNCTION EndDeferWindowPos IMPORT "USER32.DLL" ALIAS "EndDeferWindowPos" ( _
   BYVAL hWinPosInfo AS DWORD _                         ' __in HDWP hWinPosInfo
 ) AS LONG                                              ' BOOL

'#endif /* !NODEFERWINDOWPOS */
'#ENDIF   ' #IF NOT %DEF(%NODEFERWINDOWPOS) ' ----------------------------------

DECLARE FUNCTION IsWindowVisible IMPORT "USER32.DLL" ALIAS "IsWindowVisible" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsIconic IMPORT "USER32.DLL" ALIAS "IsIconic" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AnyPopup IMPORT "USER32.DLL" ALIAS "AnyPopup" ( _
 ) AS LONG                                              ' VOID

DECLARE FUNCTION BringWindowToTop IMPORT "USER32.DLL" ALIAS "BringWindowToTop" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsZoomed IMPORT "USER32.DLL" ALIAS "IsZoomed" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

'/*
' * SetWindowPos Flags
' */
%SWP_NOSIZE         = &H0001???
%SWP_NOMOVE         = &H0002???
%SWP_NOZORDER       = &H0004???
%SWP_NOREDRAW       = &H0008???
%SWP_NOACTIVATE     = &H0010???
%SWP_FRAMECHANGED   = &H0020???  ' The frame changed: send WM_NCCALCSIZE
%SWP_SHOWWINDOW     = &H0040???
%SWP_HIDEWINDOW     = &H0080???
%SWP_NOCOPYBITS     = &H0100???
%SWP_NOOWNERZORDER  = &H0200???  ' Don't do owner Z ordering
%SWP_NOSENDCHANGING = &H0400???  ' Don't send WM_WINDOWPOSCHANGING

%SWP_DRAWFRAME      = %SWP_FRAMECHANGED
%SWP_NOREPOSITION   = %SWP_NOOWNERZORDER

'#if(WINVER >= 0x0400)
%SWP_DEFERERASE     = &H2000???
%SWP_ASYNCWINDOWPOS = &H4000???
'#endif /* WINVER >= 0x0400 */

%HWND_TOP       = 0???            ' ((HWND)0)
%HWND_BOTTOM    = 1???            ' ((HWND)1)
%HWND_TOPMOST   = &HFFFFFFFF???   ' ((HWND)-1)
%HWND_NOTOPMOST = &HFFFFFFFE???   ' ((HWND)-2)

'#IF NOT %DEF(%NOCTLMGR) ' -----------------------------------------------------
'#ifndef NOCTLMGR

'/*
' * WARNING:
' * The following structures must NOT be DWORD padded because they are
' * followed by strings, etc. that do not have to be DWORD aligned.
' */
'#include <pshpack2.h>

'/*
' * original NT 32 bit dialog template:
' */
' // Size = 18 bytes
TYPE DLGTEMPLATEA BYTE
   style           AS DWORD
   dwExtendedStyle AS DWORD
   cdit            AS WORD
   x               AS INTEGER
   y               AS INTEGER
   cx              AS INTEGER
   cy              AS INTEGER
END TYPE

' // Size = 18 bytes
TYPE DLGTEMPLATEW BYTE
   style           AS DWORD
   dwExtendedStyle AS DWORD
   cdit            AS WORD
   x               AS INTEGER
   y               AS INTEGER
   cx              AS INTEGER
   cy              AS INTEGER
END TYPE

#IF %DEF(%UNICODE)
MACRO DLGTEMPLATE = DLGTEMPLATEW
#ELSE
MACRO DLGTEMPLATE = DLGTEMPLATEA
#ENDIF

'/*
' * 32 bit Dialog item template.
' */
' // Size = 18 bytes
TYPE DLGITEMTEMPLATEA BYTE
   style         AS DWORD     ' DWORD
   ExtendedStyle AS DWORD     ' DWORD
   x             AS INTEGER   ' short
   y             AS INTEGER   ' short
   cx            AS INTEGER   ' short
   cy            AS INTEGER   ' short
   id            AS WORD      ' WORD
END TYPE

' // Size = 18 bytes
TYPE DLGITEMTEMPLATEW BYTE
   style         AS DWORD     ' DWORD
   ExtendedStyle AS DWORD     ' DWORD
   x             AS INTEGER   ' short
   y             AS INTEGER   ' short
   cx            AS INTEGER   ' short
   cy            AS INTEGER   ' short
   id            AS WORD      ' WORD
END TYPE

#IF %DEF(%UNICODE)
MACRO DLGITEMTEMPLATE = DLGITEMTEMPLATEW
#ELSE
MACRO DLGITEMTEMPLATE = DLGITEMTEMPLATEA
#ENDIF

'#include <poppack.h> /* Resume normal packing */

DECLARE FUNCTION CreateDialogParamA IMPORT "USER32.DLL" ALIAS "CreateDialogParamA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD  _              ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateDialogParamW IMPORT "USER32.DLL" ALIAS "CreateDialogParamW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO CreateDialogParam = CreateDialogParamW
#ELSE
   MACRO CreateDialogParam = CreateDialogParamA
#ENDIF

DECLARE FUNCTION CreateDialogIndirectParamA IMPORT "USER32.DLL" ALIAS "CreateDialogIndirectParamA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplate AS DLGTEMPLATEA _                   ' __in LPCDLGTEMPLATEA lpTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateDialogIndirectParamW IMPORT "USER32.DLL" ALIAS "CreateDialogIndirectParamW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplate AS DLGTEMPLATEW _                   ' __in LPCDLGTEMPLATEW lpTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO CreateDialogIndirectParam = CreateDialogIndirectParamW
#ELSE
   MACRO CreateDialogIndirectParam = CreateDialogIndirectParamA
#ENDIF

'#define CreateDialogIndirectA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   CreateDialogIndirectParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
'MACRO CreateDialogIndirectA(hInstance,lpTemplate,hwndParent,lpDialogFunc) = CreateDialogIndirectParamA(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION CreateDialogIndirectA ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplate AS DLGTEMPLATEA _                   ' __in LPCDLGTEMPLATEA lpTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' HWND

   FUNCTION = CreateDialogIndirectParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0)

END FUNCTION

'#define CreateDialogIndirectW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   CreateDialogIndirectParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
'MACRO CreateDialogIndirectW(hInstance,lpTemplate,hwndParent,lpDialogFunc) = CreateDialogIndirectParamW(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION CreateDialogIndirectW ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplate AS DLGTEMPLATEW _                   ' __in LPCDLGTEMPLATEW lpTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' HWND

   FUNCTION = CreateDialogIndirectParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0)

END FUNCTION

#IF %DEF(%UNICODE)
MACRO CreateDialogIndirect = CreateDialogIndirectW
#ELSE
MACRO CreateDialogIndirect = CreateDialogIndirectA
#ENDIF


'#define CreateDialogA(hInstance, lpName, hwndParent, lpDialogFunc) \
'   CreateDialogParamA(hInstance, lpName, hwndParent, lpDialogFunc, 0L)
'MACRO CreateDialogA(hInstance,lpName,hwndParent,lpDialogFunc) = CreateDialogParamA(hInstance,lpName,hwndParent,lpDialogFunc,0)

FUNCTION CreateDialogA ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD  _              ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' HWND

   FUNCTION = CreateDialogParamA(hInstance, lpTemplateName, hwndParent, lpDialogFunc, 0)

END FUNCTION

'#define CreateDialogW(hInstance, lpName, hwndParent, lpDialogFunc) \
'   CreateDialogParamW(hInstance, lpName, hwndParent, lpDialogFunc, 0L)
'MACRO CreateDialogW(hInstance,lpName,hwndParent,lpDialogFunc) = CreateDialogParamW(hInstance,lpName,hwndParent,lpDialogFunc,0)

FUNCTION CreateDialogW ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD  _              ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' HWND

   FUNCTION = CreateDialogParamW(hInstance, lpTemplateName, hwndParent, lpDialogFunc, 0)

END FUNCTION

#IF %DEF(%UNICODE)
MACRO CreateDialog = CreateDialogW
#ELSE
MACRO CreateDialog = CreateDialogA
#ENDIF

DECLARE FUNCTION DialogBoxParamA IMPORT "USER32.DLL" ALIAS "DialogBoxParamA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS LONG                                              ' INT_PTR

DECLARE FUNCTION DialogBoxParamW IMPORT "USER32.DLL" ALIAS "DialogBoxParamW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS LONG                                              ' INT_PTR

#IF %DEF(%UNICODE)
   MACRO DialogBoxParam = DialogBoxParamW
#ELSE
   MACRO DialogBoxParam = DialogBoxParamA
#ENDIF

DECLARE FUNCTION DialogBoxIndirectParamA IMPORT "USER32.DLL" ALIAS "DialogBoxIndirectParamA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF hDialogTemplate AS DLGTEMPLATEA _              ' __in LPCDLGTEMPLATEA hDialogTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' INT_PTR

DECLARE FUNCTION DialogBoxIndirectParamW IMPORT "USER32.DLL" ALIAS "DialogBoxIndirectParamW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF hDialogTemplate AS DLGTEMPLATEW _              ' __in LPCDLGTEMPLATEW hDialogTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 , OPTIONAL BYVAL lInitParam AS LONG _                  ' __in LPARAM lInitParam
 ) AS DWORD                                             ' INT_PTR

#IF %DEF(%UNICODE)
   MACRO DialogBoxIndirectParam = DialogBoxIndirectParamW
#ELSE
   MACRO DialogBoxIndirectParam = DialogBoxIndirectParamA
#ENDIF

'#define DialogBoxA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   DialogBoxParamA(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
'MACRO DialogBoxA(hInstance,lpTemplate,hwndParent,lpDialogFunc) = DialogBoxParamA(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION DialogBoxA ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' INT_PTR
   FUNCTION = DialogBoxParamA(hInstance, lpTemplateName, hwndParent, lpDialogFunc, 0)
END FUNCTION

'#define DialogBoxW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   DialogBoxParamW(hInstance, lpTemplate, hWndParent, lpDialogFunc, 0L)
'MACRO DialogBoxW(hInstance,lpTemplate,hwndParent,lpDialogFunc) = DialogBoxParamW(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION DialogBoxW ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' INT_PTR
   FUNCTION = DialogBoxParamW(hInstance, lpTemplateName, hwndParent, lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
MACRO DialogBox = DialogBoxW
#ELSE
MACRO DialogBox = DialogBoxA
#ENDIF

'#define DialogBoxIndirectA(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   DialogBoxIndirectParamA(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
'MACRO DialogBoxIndirectA(hInstance,lpTemplate,hwndParent,lpDialogFunc) =
' DialogBoxIndirectParamA(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION DialogBoxIndirectA ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF hDialogTemplate AS DLGTEMPLATEA _              ' __in LPCDLGTEMPLATEA hDialogTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' INT_PTR
   FUNCTION = DialogBoxIndirectParamA(hInstance, hDialogTemplate, hwndParent, lpDialogFunc, 0)
END FUNCTION

'#define DialogBoxIndirectW(hInstance, lpTemplate, hwndParent, lpDialogFunc) \
'   DialogBoxIndirectParamW(hInstance, lpTemplate, hwndParent, lpDialogFunc, 0L)
'MACRO DialogBoxIndirectW(hInstance,lpTemplate,hwndParent,lpDialogFunc) = DialogBoxIndirectParamW(hInstance,lpTemplate,hwndParent,lpDialogFunc,0)

FUNCTION DialogBoxIndirectW ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF hDialogTemplate AS DLGTEMPLATEW _              ' __in LPCDLGTEMPLATEW hDialogTemplate
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL lpDialogFunc AS DWORD _               ' __in_opt DLGPROC lpDialogFunc
 ) AS DWORD                                             ' INT_PTR
   FUNCTION = DialogBoxIndirectParamW(hInstance, hDialogTemplate, hwndParent, lpDialogFunc, 0)
END FUNCTION

#IF %DEF(%UNICODE)
MACRO DialogBoxIndirect = DialogBoxIndirectW
#ELSE
MACRO DialogBoxIndirect = DialogBoxIndirectA
#ENDIF

DECLARE FUNCTION EndDialog IMPORT "USER32.DLL" ALIAS "EndDialog" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nResult AS DWORD _                             ' __in INT_PTR nResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDlgItem IMPORT "USER32.DLL" ALIAS "GetDlgItem" ( _
   BYVAL hDlg AS DWORD _                                ' __in_opt HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION SetDlgItemInt IMPORT "USER32.DLL" ALIAS "SetDlgItemInt" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYVAL uValue AS DWORD _                              ' __in UINT uValue
 , BYVAL bSigned AS LONG _                              ' __in BOOL bSigned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDlgItemInt IMPORT "USER32.DLL" ALIAS "GetDlgItemInt" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYREF lpTranslated AS LONG _                         ' __out_opt BOOL *lpTranslated
 , BYVAL bSigned AS LONG _                              ' __in BOOL bSigned
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetDlgItemTextA IMPORT "USER32.DLL" ALIAS "SetDlgItemTextA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetDlgItemTextW IMPORT "USER32.DLL" ALIAS "SetDlgItemTextW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetDlgItemText = SetDlgItemTextW
#ELSE
   MACRO SetDlgItemText = SetDlgItemTextA
#ENDIF

DECLARE FUNCTION GetDlgItemTextA IMPORT "USER32.DLL" ALIAS "GetDlgItemTextA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYREF lpString AS ASCIIZ _                           ' __out LPSTR lpString
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetDlgItemTextW IMPORT "USER32.DLL" ALIAS "GetDlgItemTextW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetDlgItemText = GetDlgItemTextW
#ELSE
   MACRO GetDlgItemText = GetDlgItemTextA
#ENDIF

DECLARE FUNCTION CheckDlgButton IMPORT "USER32.DLL" ALIAS "CheckDlgButton" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDButton AS LONG _                            ' __in int nIDButton
 , BYVAL uCheck AS DWORD _                              ' __in UINT uCheck
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CheckRadioButton IMPORT "USER32.DLL" ALIAS "CheckRadioButton" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDFirstButton AS LONG _                       ' __in int nIDFirstButton
 , BYVAL nIDLastButton AS LONG _                        ' __in int nIDLastButton
 , BYVAL nIDCheckButton AS LONG _                       ' __in int nIDCheckButton
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsDlgButtonChecked IMPORT "USER32.DLL" ALIAS "IsDlgButtonChecked" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDButton AS LONG _                            ' __in int nIDButton
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SendDlgItemMessageA IMPORT "USER32.DLL" ALIAS "SendDlgItemMessageA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION SendDlgItemMessageW IMPORT "USER32.DLL" ALIAS "SendDlgItemMessageW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL nIDDlgItem AS LONG _                           ' __in int nIDDlgItem
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO SendDlgItemMessage = SendDlgItemMessageW
#ELSE
   MACRO SendDlgItemMessage = SendDlgItemMessageA
#ENDIF

DECLARE FUNCTION GetNextDlgGroupItem IMPORT "USER32.DLL" ALIAS "GetNextDlgGroupItem" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL hCtl AS DWORD _                                ' __in_opt HWND hCtl
 , BYVAL bPrevious AS LONG _                            ' __in BOOL bPrevious
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetNextDlgTabItem IMPORT "USER32.DLL" ALIAS "GetNextDlgTabItem" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL hCtl AS DWORD _                                ' __in_opt HWND hCtl
 , BYVAL bPrevious AS LONG _                            ' __in BOOL bPrevious
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetDlgCtrlID IMPORT "USER32.DLL" ALIAS "GetDlgCtrlID" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' int

DECLARE FUNCTION GetDialogBaseUnits IMPORT "USER32.DLL" ALIAS "GetDialogBaseUnits" ( _
 ) AS LONG                                              ' long

DECLARE FUNCTION DefDlgProcA IMPORT "USER32.DLL" ALIAS "DefDlgProcA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DefDlgProcW IMPORT "USER32.DLL" ALIAS "DefDlgProcW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYVAL Msg AS DWORD _                                 ' __in UINT Msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO DefDlgProc = DefDlgProcW
#ELSE
   MACRO DefDlgProc = DefDlgProcA
#ENDIF

'/*
' * Window extra byted needed for private dialog classes.
' */
'#ifndef _MAC
'#define DLGWINDOWEXTRA 30
%DLGWINDOWEXTRA = 30&
'#else
'#define DLGWINDOWEXTRA 48
'#define DLGWINDOWEXTRA 48
'#endif

'#endif /* !NOCTLMGR */
'#ENDIF   ' #IF NOT %DEF(%NOCTLMGR) ' ------------------------------------------

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

DECLARE FUNCTION CallMsgFilterA IMPORT "USER32.DLL" ALIAS "CallMsgFilterA" ( _
   BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 , BYVAL nCode AS LONG _                                ' __in int nCode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CallMsgFilterW IMPORT "USER32.DLL" ALIAS "CallMsgFilterW" ( _
   BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 , BYVAL nCode AS LONG _                                ' __in int nCode
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CallMsgFilter = CallMsgFilterW
#ELSE
   MACRO CallMsgFilter = CallMsgFilterA
#ENDIF

'#endif /* !NOMSG */
'#ENDIF   ' #IF NOT %DEF(%NOMSG) '----------------------------------------------

'#IF NOT %DEF(%NOCLIPBOARD) ' --------------------------------------------------
'#ifndef NOCLIPBOARD

'/*
' * Clipboard Manager Functions
' */

DECLARE FUNCTION OpenClipboard IMPORT "USER32.DLL" ALIAS "OpenClipboard" ( _
   OPTIONAL BYVAL hWndNewOwner AS DWORD _               ' __in_opt HWND hWndNewOwner
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CloseClipboard IMPORT "USER32.DLL" ALIAS "CloseClipboard" ( _
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
DECLARE FUNCTION GetClipboardSequenceNumber IMPORT "USER32.DLL" ALIAS "GetClipboardSequenceNumber" ( _
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION GetClipboardOwner IMPORT "USER32.DLL" ALIAS "GetClipboardOwner" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION SetClipboardViewer IMPORT "USER32.DLL" ALIAS "SetClipboardViewer" ( _
   BYVAL hWndNewViewer AS DWORD _                       ' __in HWND hWndNewViewer
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetClipboardViewer IMPORT "USER32.DLL" ALIAS "GetClipboardViewer" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION ChangeClipboardChain IMPORT "USER32.DLL" ALIAS "ChangeClipboardChain" ( _
   BYVAL hWndRemove AS DWORD _                          ' __in HWND hWndRemove
 , BYVAL hWndNewNext AS DWORD _                         ' __in HWND hWndNewNext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetClipboardData IMPORT "USER32.DLL" ALIAS "SetClipboardData" ( _
   BYVAL uFormat AS DWORD _                             ' __in UINT uFormat
 , OPTIONAL BYVAL hMem AS DWORD _                       ' __in_opt HANDLE hMem
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetClipboardData IMPORT "USER32.DLL" ALIAS "GetClipboardData" ( _
   BYVAL uFormat AS DWORD _                             ' __in UINT uFormat
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION RegisterClipboardFormatA IMPORT "USER32.DLL" ALIAS "RegisterClipboardFormatA" ( _
   BYREF lpszFormat AS ASCIIZ _                         ' __in LPCSTR lpszFormat
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION RegisterClipboardFormatW IMPORT "USER32.DLL" ALIAS "RegisterClipboardFormatW" ( _
   BYREF lpszFormat AS WSTRINGZ _                       ' __in LPCWSTR lpszFormat
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO RegisterClipboardFormat = RegisterClipboardFormatW
#ELSE
   MACRO RegisterClipboardFormat = RegisterClipboardFormatA
#ENDIF

DECLARE FUNCTION CountClipboardFormats IMPORT "USER32.DLL" ALIAS "CountClipboardFormats" ( _
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumClipboardFormats IMPORT "USER32.DLL" ALIAS "EnumClipboardFormats" ( _
   BYVAL format AS DWORD _                              ' __in UINT format
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetClipboardFormatNameA IMPORT "USER32.DLL" ALIAS "GetClipboardFormatNameA" ( _
   BYVAL format AS DWORD _                              ' __in UINT format
 , BYREF lpszFormatName AS ASCIIZ _                     ' __out LPSTR lpszFormatName
 , BYVAL cchMaxCount AS LONG _                          ' __in int cchMaxCount
 ) AS LONG                                              ' int

DECLARE FUNCTION GetClipboardFormatNameW IMPORT "USER32.DLL" ALIAS "GetClipboardFormatNameW" ( _
   BYVAL format AS DWORD _                              ' __in UINT format
 , BYREF lpszFormatName AS WSTRINGZ _                   ' __out LPWSTR lpszFormatName
 , BYVAL cchMaxCount AS LONG _                          ' __in int cchMaxCount
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetClipboardFormatName = GetClipboardFormatNameW
#ELSE
   MACRO GetClipboardFormatName = GetClipboardFormatNameA
#ENDIF

DECLARE FUNCTION EmptyClipboard IMPORT "USER32.DLL" ALIAS "EmptyClipboard" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsClipboardFormatAvailable IMPORT "USER32.DLL" ALIAS "IsClipboardFormatAvailable" ( _
   BYVAL format AS DWORD _                              ' __in UINT format
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPriorityClipboardFormat LIB "User32.dll" _
    ALIAS "GetPriorityClipboardFormat" (BYVAL lpPriorityList AS DWORD PTR, _
    BYVAL nCount AS LONG) AS LONG
#ELSE
DECLARE FUNCTION GetPriorityClipboardFormat IMPORT "USER32.DLL" ALIAS "GetPriorityClipboardFormat" ( _
   BYREF paFormatPriorityList AS DWORD _                ' __in UINT *paFormatPriorityList
 , BYVAL cFormats AS LONG _                             ' __in int cFormats
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION GetOpenClipboardWindow IMPORT "USER32.DLL" ALIAS "GetOpenClipboardWindow" ( _
 ) AS DWORD                                             ' HWND

'#if(WINVER >= 0x0600)
DECLARE FUNCTION AddClipboardFormatListener IMPORT "USER32.DLL" ALIAS "AddClipboardFormatListener" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveClipboardFormatListener IMPORT "USER32.DLL" ALIAS "RemoveClipboardFormatListener" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetUpdatedClipboardFormats LIB "User32.dll" _
    ALIAS "GetUpdatedClipboardFormats" (BYVAL lpuiFormats AS DWORD PTR, _
    BYVAL cFormats AS DWORD, pcFormatsOut AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION GetUpdatedClipboardFormats IMPORT "USER32.DLL" ALIAS "GetUpdatedClipboardFormats" ( _
   BYREF lpuiFormats AS DWORD _                         ' __out PUINT lpuiFormats
 , BYVAL cFormats AS DWORD _                            ' __in  UINT cFormats
 , BYREF pcFormatsOut AS DWORD _                        ' __out PUINT pcFormatsOut
 ) AS LONG                                              ' BOOL
#ENDIF
'#endif /* WINVER >= 0x0600 */

'#endif /* !NOCLIPBOARD */
'#ENDIF   ' #IF NOT %DEF(%NOCLIPBOARD) ' ---------------------------------------

'/*
' * Character Translation Routines
' */

DECLARE FUNCTION CharToOemA IMPORT "USER32.DLL" ALIAS "CharToOemA" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CharToOemW IMPORT "USER32.DLL" ALIAS "CharToOemW" ( _
   BYREF lpszSrc AS WSTRINGZ _                          ' __in LPCWSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CharToOem = CharToOemW
#ELSE
   MACRO CharToOem = CharToOemA
#ENDIF

DECLARE FUNCTION OemToCharA IMPORT "USER32.DLL" ALIAS "OemToCharA" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OemToCharW IMPORT "USER32.DLL" ALIAS "OemToCharW" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS WSTRINGZ _                          ' __out LPWSTR lpszDst
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OemToChar = OemToCharW
#ELSE
   MACRO OemToChar = OemToCharA
#ENDIF

DECLARE FUNCTION CharToOemBuffA IMPORT "USER32.DLL" ALIAS "CharToOemBuffA" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 , BYVAL cchDstLength AS LONG _                         ' __in DWORD cchDstLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CharToOemBuffW IMPORT "USER32.DLL" ALIAS "CharToOemBuffW" ( _
   BYREF lpszSrc AS WSTRINGZ _                          ' __in LPCWSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 , BYVAL cchDstLength AS LONG _                         ' __in DWORD cchDstLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CharToOemBuff = CharToOemBuffW
#ELSE
   MACRO CharToOemBuff = CharToOemBuffA
#ENDIF

DECLARE FUNCTION OemToCharBuffA IMPORT "USER32.DLL" ALIAS "OemToCharBuffA" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS ASCIIZ _                            ' __out LPSTR lpszDst
 , BYVAL cchDstLength AS LONG _                         ' __in DWORD cchDstLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OemToCharBuffW IMPORT "USER32.DLL" ALIAS "OemToCharBuffW" ( _
   BYREF lpszSrc AS ASCIIZ _                            ' __in LPCSTR lpszSrc
 , BYREF lpszDst AS WSTRINGZ _                          ' __out LPWSTR lpszDst
 , BYVAL cchDstLength AS LONG _                         ' __in DWORD cchDstLength
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OemToCharBuff = OemToCharBuffW
#ELSE
   MACRO OemToCharBuff = OemToCharBuffA
#ENDIF

DECLARE FUNCTION CharUpperA IMPORT "USER32.DLL" ALIAS "CharUpperA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __inout LPSTR lpsz
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION CharUpperW IMPORT "USER32.DLL" ALIAS "CharUpperW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __inout LPWSTR lpsz
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO CharUpper = CharUpperW
#ELSE
   MACRO CharUpper = CharUpperA
#ENDIF

DECLARE FUNCTION CharUpperBuffA IMPORT "USER32.DLL" ALIAS "CharUpperBuffA" ( _
   BYREF lpsz AS ASCIIZ  _                              ' __in LPSTR lpsz
 , BYVAL cchLength AS LONG _                            ' __in DWORD cchLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CharUpperBuffW IMPORT "USER32.DLL" ALIAS "CharUpperBuffW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPWSTR lpsz
 , BYVAL cchLength AS LONG _                            ' __in DWORD cchLength
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CharUpperBuff = CharUpperBuffW
#ELSE
   MACRO CharUpperBuff = CharUpperBuffA
#ENDIF

DECLARE FUNCTION CharLowerA IMPORT "USER32.DLL" ALIAS "CharLowerA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __inout LPSTR lpsz
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION CharLowerW IMPORT "USER32.DLL" ALIAS "CharLowerW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __inout LPWSTR lpsz
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO CharLower = CharLowerW
#ELSE
   MACRO CharLower = CharLowerA
#ENDIF

DECLARE FUNCTION CharLowerBuffA IMPORT "USER32.DLL" ALIAS "CharLowerBuffA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPSTR lpsz
 , BYVAL cchLength AS DWORD _                           ' __in DWORD cchLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CharLowerBuffW IMPORT "USER32.DLL" ALIAS "CharLowerBuffW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPWSTR lpsz
 , BYVAL cchLength AS DWORD _                           ' __in DWORD cchLength
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CharLowerBuff = CharLowerBuffW
#ELSE
   MACRO CharLowerBuff = CharLowerBuffA
#ENDIF

DECLARE FUNCTION CharNextA IMPORT "USER32.DLL" ALIAS "CharNextA" ( _
   BYREF lpsz AS ASCIIZ _                               ' __in LPCSTR lpsz
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION CharNextW IMPORT "USER32.DLL" ALIAS "CharNextW" ( _
   BYREF lpsz AS WSTRINGZ _                             ' __in LPCWSTR lpsz
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO CharNext = CharNextW
#ELSE
   MACRO CharNext = CharNextA
#ENDIF

DECLARE FUNCTION CharPrevA IMPORT "USER32.DLL" ALIAS "CharPrevA" ( _
   BYREF lpszStart AS ASCIIZ  _                         ' __in LPCSTR lpszStart
 , BYREF lpszCurrent AS ASCIIZ _                        ' __in LPCSTR lpszCurrent
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION CharPrevW IMPORT "USER32.DLL" ALIAS "CharPrevW" ( _
   BYREF lpszStart AS WSTRINGZ _                        ' __in LPCWSTR lpszStart
 , BYREF lpszCurrent AS WSTRINGZ _                      ' __in LPCWSTR lpszCurrent
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
   MACRO CharPrev = CharPrevW
#ELSE
   MACRO CharPrev = CharPrevA
#ENDIF

'#if(WINVER >= 0x0400)
DECLARE FUNCTION CharNextExA IMPORT "USER32.DLL" ALIAS "CharNextExA" ( _
   BYVAL CodePage AS WORD _                             ' __in WORD CodePage
 , BYREF lpCurrentChar AS ASCIIZ _                      ' __in LPCSTR lpCurrentChar
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPSTR

MACRO CharNextEx = CharNextExA

DECLARE FUNCTION CharPrevExA IMPORT "USER32.DLL" ALIAS "CharPrevExA" ( _
   BYVAL CodePage AS WORD _                             ' __in WORD CodePage
 , BYREF lpStart AS ASCIIZ _                            ' __in LPCSTR lpStart
 , BYREF lpCurrentChar AS ASCIIZ _                      ' __in LPCSTR lpCurrentChar
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPSTR

MACRO CharPrevEx = CharPrevExA
'#endif /* WINVER >= 0x0400 */

'/*
' * Compatibility defines for character translation routines
' */
'#define AnsiToOem CharToOemA
'#define OemToAnsi OemToCharA
'#define AnsiToOemBuff CharToOemBuffA
'#define OemToAnsiBuff OemToCharBuffA
'#define AnsiUpper CharUpperA
'#define AnsiUpperBuff AnsiUpperBuff
'#define AnsiLower CharLowerA
'#define AnsiLowerBuff CharLowerBuffA
'#define AnsiNext CharNextA
'#define AnsiPrev CharPrevA

MACRO AnsiToOem = CharToOemA
MACRO OemToAnsi = OemToCharA
MACRO AnsiToOemBuff = CharToOemBuffA
MACRO OemToAnsiBuff = OemToCharBuffA
MACRO AnsiUpper = CharUpperA
MACRO AnsiUpperBuff = AnsiUpperBuff
MACRO AnsiLower = CharLowerA
MACRO AnsiLowerBuff = CharLowerBuffA
MACRO AnsiNext = CharNextA
MACRO AnsiPrev = CharPrevA

'#IF NOT %DEF(%NOLANGUAGE) ' ---------------------------------------------------
'#ifndef  NOLANGUAGE
'/*
' * Language dependent Routines
' */

DECLARE FUNCTION IsCharAlphaA IMPORT "USER32.DLL" ALIAS "IsCharAlphaA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsCharAlphaW IMPORT "USER32.DLL" ALIAS "IsCharAlphaW" ( _
   BYVAL ch AS WORD _                                   ' __in WCHAR ch
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsCharAlpha = IsCharAlphaW
#ELSE
   MACRO IsCharAlpha = IsCharAlphaA
#ENDIF

DECLARE FUNCTION IsCharAlphaNumericA IMPORT "USER32.DLL" ALIAS "IsCharAlphaNumericA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsCharAlphaNumericW IMPORT "USER32.DLL" ALIAS "IsCharAlphaNumericW" ( _
   BYVAL ch AS WORD _                                  ' __in WCHAR ch
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsCharAlphaNumeric = IsCharAlphaNumericW
#ELSE
   MACRO IsCharAlphaNumeric = IsCharAlphaNumericA
#ENDIF

DECLARE FUNCTION IsCharUpperA IMPORT "USER32.DLL" ALIAS "IsCharUpperA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsCharUpperW IMPORT "USER32.DLL" ALIAS "IsCharUpperW" ( _
   BYVAL ch AS WORD _                                   ' __in WCHAR ch
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsCharUpper = IsCharUpperW
#ELSE
   MACRO IsCharUpper = IsCharUpperA
#ENDIF

DECLARE FUNCTION IsCharLowerA IMPORT "USER32.DLL" ALIAS "IsCharLowerA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsCharLowerW IMPORT "USER32.DLL" ALIAS "IsCharLowerW" ( _
   BYVAL ch AS WORD _                                   ' __in WCHAR ch
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsCharLower = IsCharLowerW
#ELSE
   MACRO IsCharLower = IsCharLowerA
#ENDIF

'#endif  /* !NOLANGUAGE */
'#ENDIF   ' #IF NOT %DEF(%NOLANGUAGE) ' ----------------------------------------

DECLARE FUNCTION SetFocus IMPORT "USER32.DLL" ALIAS "SetFocus" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetActiveWindow IMPORT "USER32.DLL" ALIAS "GetActiveWindow" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetFocus IMPORT "USER32.DLL" ALIAS "GetFocus" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetKBCodePage IMPORT "USER32.DLL" ALIAS "GetKBCodePage" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetKeyState IMPORT "USER32.DLL" ALIAS "GetKeyState" ( _
   BYVAL nVirtKey AS LONG _                             ' __in int nVirtKey
 ) AS INTEGER                                           ' SHORT

DECLARE FUNCTION GetAsyncKeyState IMPORT "USER32.DLL" ALIAS "GetAsyncKeyState" ( _
   BYVAL vKey AS LONG _                                 ' __in int vKey
 ) AS INTEGER                                           ' SHORT

DECLARE FUNCTION GetKeyboardState IMPORT "USER32.DLL" ALIAS "GetKeyboardState" ( _
   BYREF lpKeyState AS BYTE _                           ' __out_ecount(256) PBYTE lpKeyState
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetKeyboardState IMPORT "USER32.DLL" ALIAS "SetKeyboardState" ( _
   BYREF lpKeyState AS BYTE _                           ' __in_ecount(256) LPBYTE lpKeyState
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetKeyNameTextA IMPORT "USER32.DLL" ALIAS "GetKeyNameTextA" ( _
   BYVAL lParam AS LONG _                               ' __in LONG lParam
 , BYREF lpString AS ASCIIZ _                           ' __out LPSTR lpString
 , BYVAL cchSize AS DWORD _                             ' __in int cchSize
 ) AS LONG                                              ' int

DECLARE FUNCTION GetKeyNameTextW IMPORT "USER32.DLL" ALIAS "GetKeyNameTextW" ( _
   BYVAL lParam AS LONG _                               ' __in LONG lParam
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL cchSize AS DWORD _                             ' __in int cchSize
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetKeyNameText = GetKeyNameTextW
#ELSE
   MACRO GetKeyNameText = GetKeyNameTextA
#ENDIF

DECLARE FUNCTION GetKeyboardType IMPORT "USER32.DLL" ALIAS "GetKeyboardType" ( _
   BYVAL nTypeFlag AS LONG _                            ' __in int nTypeFlag
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ToAscii LIB "User32.dll" ALIAS "ToAscii" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, lpChar AS WORD, BYVAL uFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION ToAscii IMPORT "USER32.DLL" ALIAS "ToAscii" ( _
   BYVAL uVirtKey AS DWORD _                            ' __in UINT uVirtKey
 , BYVAL uScanCode AS DWORD _                           ' __in UINT uScanCode
 , BYREF lpKeyState AS BYTE _                           ' __in_ecount_opt(256) CONST BYTE *lpKeyState
 , BYREF lpChar AS DWORD _                              ' __out LPWORD lpChar
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' int
#ENDIF

'#if(WINVER >= 0x0400)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ToAsciiEx LIB "User32.dll" ALIAS "ToAsciiEx" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, lpChar AS WORD, BYVAL uFlags AS DWORD, _
    OPTIONAL BYVAL dwHKL AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ToAsciiEx IMPORT "USER32.DLL" ALIAS "ToAsciiEx" ( _
   BYVAL uVirtKey AS DWORD _                            ' __in UINT uVirtKey
 , BYVAL uScanCode AS DWORD _                           ' __in UINT uScanCode
 , BYREF lpKeyState AS ANY _                            ' __in_ecount_opt(256) CONST BYTE *lpKeyState
 , BYREF lpChar AS DWORD _                              ' __out LPWORD lpChar
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , OPTIONAL BYVAL dwhkl AS DWORD _                      ' __in_opt HKL dwhkl
 ) AS LONG                                              ' int
#ENDIF
'#endif /* WINVER >= 0x0400 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ToUnicode LIB "User32.dll" ALIAS "ToUnicode" _
    (BYVAL uVirtKey AS DWORD, BYVAL uScanCode AS DWORD, _
    BYVAL lpKeyState AS BYTE PTR, pwszBuff AS WSTRINGZ, _
    BYVAL cchBuff AS LONG, BYVAL uFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ToUnicode IMPORT "USER32.DLL" ALIAS "ToUnicode" ( _
   BYVAL wVirtKey AS DWORD _                            ' __in UINT wVirtKey
 , BYVAL wScanCode AS DWORD _                           ' __in UINT wScanCode
 , BYREF lpKeyState AS BYTE _                           ' __in_bcount_opt(256) CONST BYTE *lpKeyState
 , BYREF pwszBuff AS WSTRINGZ _                         ' __out LPWSTR pwszBuff
 , BYVAL cchBuff AS LONG _                              ' __in int cchBuff
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION OemKeyScan IMPORT "USER32.DLL" ALIAS "OemKeyScan" ( _
   BYVAL wOemChar AS WORD _                             ' __in WORD wOemChar
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION VkKeyScanA IMPORT "USER32.DLL" ALIAS "VkKeyScanA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 ) AS INTEGER                                           ' SHORT

DECLARE FUNCTION VkKeyScanW IMPORT "USER32.DLL" ALIAS "VkKeyScanW" ( _
   BYVAL ch AS WORD _                                   ' __in WCHAR ch
 ) AS INTEGER                                           ' SHORT

#IF %DEF(%UNICODE)
   MACRO VkKeyScan = VkKeyScanW
#ELSE
   MACRO VkKeyScan = VkKeyScanA
#ENDIF

'#if(WINVER >= 0x0400)

DECLARE FUNCTION VkKeyScanExA IMPORT "USER32.DLL" ALIAS "VkKeyScanExA" ( _
   BYVAL ch AS BYTE _                                   ' __in CHAR ch
 , BYVAL dwhkl AS DWORD _                               ' __in HKL dwhkl
 ) AS INTEGER                                           ' SHORT

DECLARE FUNCTION VkKeyScanExW IMPORT "USER32.DLL" ALIAS "VkKeyScanExW" ( _
   BYVAL ch AS WORD _                                   ' __in WCHAR ch
 , BYVAL dwhkl AS DWORD _                               ' __in HKL dwhkl
 ) AS INTEGER                                           ' SHORT

#IF %DEF(%UNICODE)
   MACRO VkKeyScanEx = VkKeyScanExW
#ELSE
   MACRO VkKeyScanEx = VkKeyScanExA
#ENDIF

'#endif /* WINVER >= 0x0400 */

%KEYEVENTF_EXTENDEDKEY = &H0001???
%KEYEVENTF_KEYUP       = &H0002???
'#if(_WIN32_WINNT >= 0x0500)
%KEYEVENTF_UNICODE     = &H0004???
%KEYEVENTF_SCANCODE    = &H0008???
'#endif /* _WIN32_WINNT >= 0x0500 */

DECLARE SUB keybd_event IMPORT "USER32.DLL" ALIAS "keybd_event" ( _
   BYVAL bVk AS BYTE _                                  ' __in BYTE bVk
 , BYVAL bScan AS BYTE _                                ' __in BYTE bScan
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwExtraInfo AS DWORD _                         ' __in ULONG_PTR dwExtraInfo
 )                                                      ' VOID

%MOUSEEVENTF_MOVE        = &H0001???   ' mouse move
%MOUSEEVENTF_LEFTDOWN    = &H0002???   ' left button down
%MOUSEEVENTF_LEFTUP      = &H0004???   ' left button up
%MOUSEEVENTF_RIGHTDOWN   = &H0008???   ' right button down
%MOUSEEVENTF_RIGHTUP     = &H0010???   ' right button up
%MOUSEEVENTF_MIDDLEDOWN  = &H0020???   ' middle button down
%MOUSEEVENTF_MIDDLEUP    = &H0040???   ' middle button up
%MOUSEEVENTF_XDOWN       = &H0080???   ' /* x button down */
%MOUSEEVENTF_XUP         = &H0100???   ' /* x button down */
%MOUSEEVENTF_WHEEL       = &H0800???   ' wheel button rolled
'#if (_WIN32_WINNT >= 0x0600)
'#define MOUSEEVENTF_HWHEEL      0x01000 /* hwheel button rolled */
%MOUSEEVENTF_HWHEEL_VISTA = &H01000???   ' /* hwheel button rolled */
'#endif
'#if(WINVER >= 0x0600)
%MOUSEEVENTF_MOVE_NOCOALESCE = &H2000???   ' /* do not coalesce mouse moves */
'#endif /* WINVER >= 0x0600 */
%MOUSEEVENTF_VIRTUALDESK = &H4000???   '/* map to entire virtual desktop */
%MOUSEEVENTF_ABSOLUTE    = &H8000???   ' absolute move

DECLARE SUB mouse_event IMPORT "USER32.DLL" ALIAS "mouse_event" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dx AS DWORD _                                  ' __in DWORD dx
 , BYVAL dy AS DWORD _                                  ' __in DWORD dy
 , BYVAL dwData AS DWORD _                              ' __in DWORD dwData
 , BYVAL dwExtraInfo AS DWORD _                         ' __in ULONG_PTR dwExtraInfo
 )                                                      ' VOID

'#if (_WIN32_WINNT > 0x0400)

UNION MOUSEINPUT_TIME_UNION
   time        AS DWORD   ' DWORD
   ' // For compatibility with the PB includes
   dtime       AS DWORD   ' DWORD
END UNION

' // Size = 24 bytes
TYPE MOUSEINPUT DWORD
   dx          AS LONG    ' LONG
   dy          AS LONG    ' LONG
   mouseData   AS DWORD   ' DWORD
   dwFlags     AS DWORD   ' DWORD
   MOUSEINPUT_TIME_UNION
   dwExtraInfo AS DWORD   ' ULONG_PTR
END TYPE

UNION KEYBDINPUT_TIME_UNION
   time        AS DWORD   ' DWORD
   ' // For compatibility with the PB includes
   dtime       AS DWORD   ' DWORD
END UNION

' // Size = 16 bytes
TYPE KEYBDINPUT DWORD FILL
   wVk         AS WORD    ' WORD
   wScan       AS WORD    ' WORD
   dwFlags     AS DWORD   ' DWORD
   KEYBDINPUT_TIME_UNION
   dwExtraInfo AS DWORD   ' ULONG_PTR
END TYPE

' // Size = 8 bytes
TYPE HARDWAREINPUT DWORD FILL
   uMsg    AS DWORD   ' DWORD
   wParamL AS WORD    ' WORD
   wParamH AS WORD    ' WORD
END TYPE

%INPUT_MOUSE    = 0???
%INPUT_KEYBOARD = 1???
%INPUT_HARDWARE = 2???

'typedef struct tagINPUT {
'    DWORD   type;

'    union
'    {
'        MOUSEINPUT      mi;
'        KEYBDINPUT      ki;
'        HARDWAREINPUT   hi;
'    };
'} INPUT, *PINPUT, FAR* LPINPUT;

' // Size = 24 bytes
UNION INPUTAPI_UNION DWORD
   mi AS MOUSEINPUT
   ki AS KEYBDINPUT
   hi AS HARDWAREINPUT
END UNION

' // Size = 28 bytes
TYPE INPUTAPI DWORD
   dtype AS DWORD
   INPUTAPI_UNION
END TYPE

MACRO tagINPUT = INPUTAPI

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SendInput LIB "User32.dll" ALIAS "SendInput" _
    (BYVAL cInputs AS DWORD, BYVAL pInputs AS INPUTAPI PTR, _
    BYVAL cbSize AS LONG) AS DWORD
#ELSE
DECLARE FUNCTION SendInput IMPORT "USER32.DLL" ALIAS "SendInput" ( _
   BYVAL cInputs AS DWORD _                             ' __in UINT cInputs
 , BYREF pInputs AS INPUTAPI _                          ' __in LPINPUT pInputs
 , BYVAL cbSize AS LONG _                               ' __in int cbSize
 ) AS DWORD                                             ' UINT
#ENDIF

'#endif // (_WIN32_WINNT > 0x0400)

'#if(WINVER >= 0x0601)

'/*
' * Touch Input defines and functions
' */

'/*
' * Touch input handle
' */
'DECLARE_HANDLE(HTOUCHINPUT);

' // Size = 40 bytes
TYPE TOUCHINPUT DWORD
   x           AS LONG    ' LONG
   y           AS LONG    ' LONG
   hSource     AS DWORD   ' HANDLE
   dwID        AS DWORD   ' DWORD
   dwFlags     AS DWORD   ' DWORD
   dwMask      AS DWORD   ' DWORD
   dwTime      AS DWORD   ' DWORD
   dwExtraInfo AS DWORD   ' ULONG_PTR
   cxContact   AS DWORD   ' DWORD
   cyContact   AS DWORD   ' DWORD
END TYPE


'/*
' * Conversion of touch input coordinates to pixels
' */
'#define TOUCH_COORD_TO_PIXEL(l)         ((l) / 100)
MACRO TOUCH_COORD_TO_PIXEL(l) = (l / 100)

'/*
' * Touch input flag values (TOUCHINPUT.dwFlags)
' */
%TOUCHEVENTF_MOVE            = &H0001???
%TOUCHEVENTF_DOWN            = &H0002???
%TOUCHEVENTF_UP              = &H0004???
%TOUCHEVENTF_INRANGE         = &H0008???
%TOUCHEVENTF_PRIMARY         = &H0010???
%TOUCHEVENTF_NOCOALESCE      = &H0020???
%TOUCHEVENTF_PEN             = &H0040???
%TOUCHEVENTF_PALM            = &H0080???

'/*
' * Touch input mask values (TOUCHINPUT.dwMask)
' */
%TOUCHINPUTMASKF_TIMEFROMSYSTEM  = &H0001???   ' // the dwTime field contains a system generated value
%TOUCHINPUTMASKF_EXTRAINFO       = &H0002???   ' // the dwExtraInfo field is valid
%TOUCHINPUTMASKF_CONTACTAREA     = &H0004???   ' // the cxContact and cyContact fields are valid

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetTouchInputInfo LIB "User32.dll" _
    ALIAS "GetTouchInputInfo" ( _
    BYVAL hTouchInput AS DWORD, _        ' input event handle; from touch message lParam
    BYVAL cInputs AS DWORD, _            ' number of elements in the array
    BYVAL pInputs AS TOUCHINPUT PTR, _   ' array of touch inputs
    BYVAL cbSize AS LONG) _              ' sizeof(TOUCHINPUT)
    AS LONG
#ELSE
DECLARE FUNCTION GetTouchInputInfo IMPORT "USER32.DLL" ALIAS "GetTouchInputInfo" ( _
   BYVAL hTouchInput AS DWORD _                         ' __in HTOUCHINPUT hTouchInput               // input event handle; from touch message lParam
 , BYVAL cInputs AS DWORD _                             ' __in UINT cInputs                          // number of elements in the array
 , BYREF pInputs AS TOUCHINPUT _                        ' __out_ecount(cInputs) PTOUCHINPUT pInputs  // array of touch inputs
 , BYVAL cbSize AS LONG _                               ' __in int cbSize                            // sizeof(TOUCHINPUT)
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CloseTouchInputHandle IMPORT "USER32.DLL" ALIAS "CloseTouchInputHandle" ( _
   BYVAL hTouchInput AS DWORD _                         ' __in HTOUCHINPUT hTouchInput               // input event handle; from touch message lParam
 ) AS LONG                                              ' BOOL

'/*
' * RegisterTouchWindow flag values
' */
%TWF_FINETOUCH = &H00000001???
%TWF_WANTPALM  = &H00000002???

DECLARE FUNCTION RegisterTouchWindow IMPORT "USER32.DLL" ALIAS "RegisterTouchWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL ulFlags AS DWORD _                             ' __in ULONG ulFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnregisterTouchWindow IMPORT "USER32.DLL" ALIAS "UnregisterTouchWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsTouchWindow IMPORT "USER32.DLL" ALIAS "IsTouchWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , OPTIONAL BYREF pulFlags AS DWORD _                   ' __out_opt PULONG pulFlags
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0601 */

'#if(_WIN32_WINNT >= 0x0500)

' // Size = 8 bytes
TYPE LASTINPUTINFO DWORD
   cbSize AS DWORD   ' UINT
   dwTime AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION GetLastInputInfo IMPORT "USER32.DLL" ALIAS "GetLastInputInfo" ( _
   BYREF plii AS LASTINPUTINFO _                        ' __out PLASTINPUTINFO plii
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0500 */

DECLARE FUNCTION MapVirtualKeyA IMPORT "USER32.DLL" ALIAS "MapVirtualKeyA" ( _
   BYVAL uCode AS DWORD _                               ' __in UINT uCode
 , BYVAL uMapType AS DWORD _                            ' __in UINT uMapType
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION MapVirtualKeyW IMPORT "USER32.DLL" ALIAS "MapVirtualKeyW" ( _
   BYVAL uCode AS DWORD _                               ' __in UINT uCode
 , BYVAL uMapType AS DWORD _                            ' __in UINT uMapType
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO MapVirtualKey = MapVirtualKeyW
#ELSE
   MACRO MapVirtualKey = MapVirtualKeyA
#ENDIF

'#if(WINVER >= 0x0400)

DECLARE FUNCTION MapVirtualKeyExA IMPORT "USER32.DLL" ALIAS "MapVirtualKeyExA" ( _
   BYVAL uCode AS DWORD _                               ' __in UINT uCode
 , BYVAL uMapType AS DWORD _                            ' __in UINT uMapType
 , OPTIONAL BYVAL dwhkl AS DWORD _                      ' __in_opt HKL dwhkl
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION MapVirtualKeyExW IMPORT "USER32.DLL" ALIAS "MapVirtualKeyExW" ( _
   BYVAL uCode AS DWORD _                               ' __in UINT uCode
 , BYVAL uMapType AS DWORD _                            ' __in UINT uMapType
 , OPTIONAL BYVAL dwhkl AS DWORD _                      ' __in_opt HKL dwhkl
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO MapVirtualKeyEx = MapVirtualKeyExW
#ELSE
   MACRO MapVirtualKeyEx = MapVirtualKeyExA
#ENDIF

%MAPVK_VK_TO_VSC     = 0
%MAPVK_VSC_TO_VK     = 1
%MAPVK_VK_TO_CHAR    = 2
%MAPVK_VSC_TO_VK_EX  = 3
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0600)
%MAPVK_VK_TO_VSC_EX  = 4
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION GetInputState IMPORT "USER32.DLL" ALIAS "GetInputState" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetQueueStatus IMPORT "USER32.DLL" ALIAS "GetQueueStatus" ( _
   BYVAL flags AS DWORD _                               ' __in UINT flags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCapture IMPORT "USER32.DLL" ALIAS "GetCapture" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION SetCapture IMPORT "USER32.DLL" ALIAS "SetCapture" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION ReleaseCapture IMPORT "USER32.DLL" ALIAS "ReleaseCapture" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MsgWaitForMultipleObjects IMPORT "USER32.DLL" ALIAS "MsgWaitForMultipleObjects" ( _
   BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF pHandles AS DWORD _                            ' __in CONST HANDLE *pHandles
 , BYVAL fWaitAll AS LONG _                             ' __in BOOL fWaitAll
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 , BYVAL dwWakeMask AS DWORD _                          ' __in DWORD dwWakeMask
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
' // The PB declare is lacking the dwFlags parameter
DECLARE FUNCTION MsgWaitForMultipleObjectsEx LIB "User32.dll" _
    ALIAS "MsgWaitForMultipleObjectsEx" (BYVAL nCount AS DWORD, _
    BYVAL pHandless AS DWORD PTR, BYVAL dwMilliseconds AS DWORD, _
    BYVAL dwWakeMask AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION MsgWaitForMultipleObjectsEx IMPORT "USER32.DLL" ALIAS "MsgWaitForMultipleObjectsEx" ( _
   BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF pHandles AS DWORD _                            ' __in CONST HANDLE *pHandles
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 , BYVAL dwWakeMask AS DWORD _                          ' __in DWORD dwWakeMask
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD
#ENDIF

%MWMO_WAITALL        = &H0001???
%MWMO_ALERTABLE      = &H0002???
%MWMO_INPUTAVAILABLE = &H0004???

'/*
' * Windows Functions
' */

DECLARE FUNCTION SetTimer IMPORT "USER32.DLL" ALIAS "SetTimer" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL nIDEvent AS DWORD _                            ' __in UINT_PTR nIDEvent
 , BYVAL uElapse AS DWORD _                             ' __in UINT uElapse
 , OPTIONAL BYVAL lpTimerFunc AS DWORD _                ' __in_opt TIMERPROC lpTimerFunc
 ) AS DWORD                                             ' UINT_PTR

DECLARE FUNCTION KillTimer IMPORT "USER32.DLL" ALIAS "KillTimer" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL uIDEvent AS DWORD _                            ' __in UINT_PTR uIDEvent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsWindowUnicode IMPORT "USER32.DLL" ALIAS "IsWindowUnicode" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnableWindow IMPORT "USER32.DLL" ALIAS "EnableWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL bEnable AS LONG _                              ' __in BOOL bEnable
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsWindowEnabled IMPORT "USER32.DLL" ALIAS "IsWindowEnabled" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LoadAcceleratorsA IMPORT "USER32.DLL" ALIAS "LoadAcceleratorsA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTableName AS ASCIIZ _                        ' __in LPCSTR lpTableName
 ) AS DWORD                                             ' HACCEL

DECLARE FUNCTION LoadAcceleratorsW IMPORT "USER32.DLL" ALIAS "LoadAcceleratorsW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpTableName AS WSTRINGZ _                      ' __in LPCWSTR lpTableName
 ) AS DWORD                                             ' HACCEL

#IF %DEF(%UNICODE)
   MACRO LoadAccelerators = LoadAcceleratorsW
#ELSE
   MACRO LoadAccelerators = LoadAcceleratorsA
#ENDIF

DECLARE FUNCTION CreateAcceleratorTableA IMPORT "USER32.DLL" ALIAS "CreateAcceleratorTableA" ( _
   BYREF paccel AS ACCELAPI _                           ' __in LPACCEL paccel
 , BYVAL cAccel AS LONG _                               ' __in int cAccel
 ) AS DWORD                                             ' HACCEL

DECLARE FUNCTION CreateAcceleratorTableW IMPORT "USER32.DLL" ALIAS "CreateAcceleratorTableW" ( _
   BYREF paccel AS ACCELAPI _                           ' __in LPACCEL paccel
 , BYVAL cAccel AS LONG _                               ' __in int cAccel
 ) AS DWORD                                             ' HACCEL

#IF %DEF(%UNICODE)
   MACRO CreateAcceleratorTable = CreateAcceleratorTableW
#ELSE
   MACRO CreateAcceleratorTable = CreateAcceleratorTableA
#ENDIF

DECLARE FUNCTION DestroyAcceleratorTable IMPORT "USER32.DLL" ALIAS "DestroyAcceleratorTable" ( _
   BYVAL hAccel AS DWORD _                              ' __in HACCEL hAccel
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CopyAcceleratorTableA IMPORT "USER32.DLL" ALIAS "CopyAcceleratorTableA" ( _
   BYVAL hAccelSrc AS DWORD _                           ' __in HACCEL hAccelSrc
 , BYREF lpAccelDst AS ACCELAPI _                       ' __out LPACCEL lpAccelDst
 , BYVAL cAccelEntries AS LONG _                        ' __in int cAccelEntries
 ) AS LONG                                              ' int

DECLARE FUNCTION CopyAcceleratorTableW IMPORT "USER32.DLL" ALIAS "CopyAcceleratorTableW" ( _
   BYVAL hAccelSrc AS DWORD _                           ' __in HACCEL hAccelSrc
 , BYREF lpAccelDst AS ACCELAPI  _                      ' __out LPACCEL lpAccelDst
 , BYVAL cAccelEntries AS LONG _                        ' __in int cAccelEntries
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO CopyAcceleratorTable = CopyAcceleratorTableW
#ELSE
   MACRO CopyAcceleratorTable = CopyAcceleratorTableA
#ENDIF

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

DECLARE FUNCTION TranslateAcceleratorA IMPORT "USER32.DLL" ALIAS "TranslateAcceleratorA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hAccTable AS DWORD _                           ' __in HACCEL hAccTable
 , BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 ) AS LONG                                              ' int

DECLARE FUNCTION TranslateAcceleratorW IMPORT "USER32.DLL" ALIAS "TranslateAcceleratorW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hAccTable AS DWORD _                           ' __in HACCEL hAccTable
 , BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO TranslateAccelerator = TranslateAcceleratorW
#ELSE
   MACRO TranslateAccelerator = TranslateAcceleratorA
#ENDIF

'#endif /* !NOMSG */
'#ENDIF   ' #IF NOT %DEF(%NOMSG) '----------------------------------------------

'#IF NOT %DEF(%NOSYSMETRICS) ' -------------------------------------------------
'#ifndef NOSYSMETRICS

'/*
' * GetSystemMetrics() codes
' */

%SM_CXSCREEN            = 0&
%SM_CYSCREEN            = 1&
%SM_CXVSCROLL           = 2&
%SM_CYHSCROLL           = 3&
%SM_CYCAPTION           = 4&
%SM_CXBORDER            = 5&
%SM_CYBORDER            = 6&
%SM_CXDLGFRAME          = 7&
%SM_CYDLGFRAME          = 8&
%SM_CYVTHUMB            = 9&
%SM_CXHTHUMB            = 10&
%SM_CXICON              = 11&
%SM_CYICON              = 12&
%SM_CXCURSOR            = 13&
%SM_CYCURSOR            = 14&
%SM_CYMENU              = 15&
%SM_CXFULLSCREEN        = 16&
%SM_CYFULLSCREEN        = 17&
%SM_CYKANJIWINDOW       = 18&
%SM_MOUSEPRESENT        = 19&
%SM_CYVSCROLL           = 20&
%SM_CXHSCROLL           = 21&
%SM_DEBUG               = 22&
%SM_SWAPBUTTON          = 23&
%SM_RESERVED1           = 24&
%SM_RESERVED2           = 25&
%SM_RESERVED3           = 26&
%SM_RESERVED4           = 27&
%SM_CXMIN               = 28&
%SM_CYMIN               = 29&
%SM_CXSIZE              = 30&
%SM_CYSIZE              = 31&
%SM_CXFRAME             = 32&
%SM_CYFRAME             = 33&
%SM_CXMINTRACK          = 34&
%SM_CYMINTRACK          = 35&
%SM_CXDOUBLECLK         = 36&
%SM_CYDOUBLECLK         = 37&
%SM_CXICONSPACING       = 38&
%SM_CYICONSPACING       = 39&
%SM_MENUDROPALIGNMENT   = 40&
%SM_PENWINDOWS          = 41&
%SM_DBCSENABLED         = 42&
%SM_CMOUSEBUTTONS       = 43&

'#if(WINVER >= 0x0400)
%SM_CXFIXEDFRAME        = %SM_CXDLGFRAME  ' win40 name change
%SM_CYFIXEDFRAME        = %SM_CYDLGFRAME  ' win40 name change
%SM_CXSIZEFRAME         = %SM_CXFRAME     ' win40 name change
%SM_CYSIZEFRAME         = %SM_CYFRAME     ' win40 name change

%SM_SECURE              = 44&
%SM_CXEDGE              = 45&
%SM_CYEDGE              = 46&
%SM_CXMINSPACING        = 47&
%SM_CYMINSPACING        = 48&
%SM_CXSMICON            = 49&
%SM_CYSMICON            = 50&
%SM_CYSMCAPTION         = 51&
%SM_CXSMSIZE            = 52&
%SM_CYSMSIZE            = 53&
%SM_CXMENUSIZE          = 54&
%SM_CYMENUSIZE          = 55&
%SM_ARRANGE             = 56&
%SM_CXMINIMIZED         = 57&
%SM_CYMINIMIZED         = 58&
%SM_CXMAXTRACK          = 59&
%SM_CYMAXTRACK          = 60&
%SM_CXMAXIMIZED         = 61&
%SM_CYMAXIMIZED         = 62&
%SM_NETWORK             = 63&
%SM_CLEANBOOT           = 67&
%SM_CXDRAG              = 68&
%SM_CYDRAG              = 69&
'#endif /* WINVER >= 0x0400 */
%SM_SHOWSOUNDS          = 70&
'#if(WINVER >= 0x0400)
%SM_CXMENUCHECK         = 71&   ' Use instead of GetMenuCheckMarkDimensions()
%SM_CYMENUCHECK         = 72&
%SM_SLOWMACHINE         = 73&
%SM_MIDEASTENABLED      = 74&
'#endif /* WINVER >= 0x0400 */

'#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
%SM_MOUSEWHEELPRESENT   = 75&
'#endif
'#if(WINVER >= 0x0500)
%SM_XVIRTUALSCREEN      = 76&
%SM_YVIRTUALSCREEN      = 77&
%SM_CXVIRTUALSCREEN     = 78&
%SM_CYVIRTUALSCREEN     = 79&
%SM_CMONITORS           = 80&
%SM_SAMEDISPLAYFORMAT   = 81&
'#endif /* WINVER >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0500)
%SM_IMMENABLED          = 82&
'#endif /* _WIN32_WINNT >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0501)
%SM_CXFOCUSBORDER       = 83&
%SM_CYFOCUSBORDER       = 84&
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0501)
%SM_TABLETPC            = 86&
%SM_MEDIACENTER         = 87&
%SM_STARTER             = 88&
%SM_SERVERR2            = 89&
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0600)
%SM_MOUSEHORIZONTALWHEELPRESENT = 91
%SM_CXPADDEDBORDER              = 92
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if(WINVER >= 0x0601)
%SM_DIGITIZER           = 94
%SM_MAXIMUMTOUCHES      = 95
'#endif /* WINVER >= 0x0601 */

'#if (WINVER < 0x0500) && (!defined(_WIN32_WINNT) || (_WIN32_WINNT < 0x0400))
'#define SM_CMETRICS             76
'#elif WINVER == 0x500
'#define SM_CMETRICS             83
'#elif WINVER == 0x501
'#define SM_CMETRICS             91
'#elif WINVER == 0x600
'#define SM_CMETRICS             93
'#else
'#define SM_CMETRICS             97
'#endif

#IF %WINVER < &H0500
   %SM_CMETRICS = 76&
#ELSEIF %WINVER = &H500
   %SM_CMETRICS = 83&
#ELSEIF %WINVER = &H501
   %SM_CMETRICS = 91&
#ELSEIF %WINVER = &H600
   %SM_CMETRICS = 93&
#ELSE
   %SM_CMETRICS = 97&
#ENDIF

'#if(WINVER >= 0x0500)
%SM_REMOTESESSION       = &H1000&

'#if(_WIN32_WINNT >= 0x0501)
%SM_SHUTTINGDOWN        = &H2000&
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(WINVER >= 0x0501)
%SM_REMOTECONTROL       = &H2001&
'#endif /* WINVER >= 0x0501 */

'#if(WINVER >= 0x0501)
%SM_CARETBLINKINGENABLED = &H2002&
'#endif /* WINVER >= 0x0501 */

'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION GetSystemMetrics IMPORT "USER32.DLL" ALIAS "GetSystemMetrics" ( _
   BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS LONG                                              ' int

'#endif /* !NOSYSMETRICS */
'#ENDIF   ' #IF NOT %DEF(%NOSYSMETRICS) ' --------------------------------------

'#IF NOT %DEF(%NOMENUS) ' ------------------------------------------------------
'#ifndef NOMENUS

DECLARE FUNCTION LoadMenuA IMPORT "USER32.DLL" ALIAS "LoadMenuA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpMenuName AS ASCIIZ _                         ' __in LPCSTR lpMenuName
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION LoadMenuW IMPORT "USER32.DLL" ALIAS "LoadMenuW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpMenuName AS WSTRINGZ _                       ' __in LPCWSTR lpMenuName
 ) AS DWORD                                             ' HMENU

#IF %DEF(%UNICODE)
   MACRO LoadMenu = LoadMenuW
#ELSE
   MACRO LoadMenu = LoadMenuA
#ENDIF

DECLARE FUNCTION LoadMenuIndirectA IMPORT "USER32.DLL" ALIAS "LoadMenuIndirectA" ( _
   BYREF lpMenuTemplate AS ANY _                        ' __in CONST MENUTEMPLATEA *lpMenuTemplate
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION LoadMenuIndirectW IMPORT "USER32.DLL" ALIAS "LoadMenuIndirectW" ( _
   BYREF lpMenuTemplate AS ANY _                        ' __in CONST MENUTEMPLATEW *lpMenuTemplate
 ) AS DWORD                                             ' HMENU

#IF %DEF(%UNICODE)
   MACRO LoadMenuIndirect = LoadMenuIndirectW
#ELSE
   MACRO LoadMenuIndirect = LoadMenuIndirectA
#ENDIF

DECLARE FUNCTION GetMenu IMPORT "USER32.DLL" ALIAS "GetMenu" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION SetMenu IMPORT "USER32.DLL" ALIAS "SetMenu" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYVAL hMenu AS DWORD _                      ' __in_opt HMENU hMenu
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChangeMenuA IMPORT "USER32.DLL" ALIAS "ChangeMenuA" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL cmd AS DWORD _                                 ' __in UINT cmd
 , BYREF lpszNewItem AS ASCIIZ _                        ' __in_opt LPCSTR lpszNewItem
 , BYVAL cmdInsert AS DWORD _                           ' __in UINT cmdInsert
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChangeMenuW IMPORT "USER32.DLL" ALIAS "ChangeMenuW" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL cmd AS DWORD _                                 ' __in UINT cmd
 , BYREF lpszNewItem AS WSTRINGZ _                      ' __in_opt LPCWSTR lpszNewItem
 , BYVAL cmdInsert AS DWORD _                           ' __in UINT cmdInsert
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ChangeMenu = ChangeMenuW
#ELSE
   MACRO ChangeMenu = ChangeMenuA
#ENDIF

DECLARE FUNCTION HiliteMenuItem IMPORT "USER32.DLL" ALIAS "HiliteMenuItem" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uIDHiliteItem AS DWORD _                       ' __in UINT uIDHiliteItem
 , BYVAL uHilite AS DWORD _                             ' __in UINT uHilite
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMenuStringA IMPORT "USER32.DLL" ALIAS "GetMenuStringA" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uIDItem AS DWORD _                             ' __in UINT uIDItem
 , BYREF lpString AS ASCIIZ _                           ' __out LPSTR lpString
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' int

DECLARE FUNCTION GetMenuStringW IMPORT "USER32.DLL" ALIAS "GetMenuStringW" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uIDItem AS DWORD _                             ' __in UINT uIDItem
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL cchMax AS LONG _                               ' __in int cchMax
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetMenuString = GetMenuStringW
#ELSE
   MACRO GetMenuString = GetMenuStringA
#ENDIF

DECLARE FUNCTION GetMenuState IMPORT "USER32.DLL" ALIAS "GetMenuState" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uId AS DWORD _                                 ' __in UINT uId
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION DrawMenuBar IMPORT "USER32.DLL" ALIAS "DrawMenuBar" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0501)
%PMB_ACTIVE = &H00000001???
'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION GetSystemMenu IMPORT "USER32.DLL" ALIAS "GetSystemMenu" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL bRevert AS LONG _                              ' __in BOOL bRevert
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION CreateMenu IMPORT "USER32.DLL" ALIAS "CreateMenu" ( _
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION CreatePopupMenu IMPORT "USER32.DLL" ALIAS "CreatePopupMenu" ( _
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION DestroyMenu IMPORT "USER32.DLL" ALIAS "DestroyMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CheckMenuItem IMPORT "USER32.DLL" ALIAS "CheckMenuItem" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uIDCheckItem AS DWORD _                        ' __in UINT uIDCheckItem
 , BYVAL uCheck AS DWORD _                              ' __in UINT uCheck
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION EnableMenuItem IMPORT "USER32.DLL" ALIAS "EnableMenuItem" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uIDEnableItem AS DWORD _                       ' __in UINT uIDEnableItem
 , BYVAL uEnable AS DWORD _                             ' __in UINT uEnable
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSubMenu IMPORT "USER32.DLL" ALIAS "GetSubMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL nPos AS LONG _                                 ' __in int nPos
 ) AS DWORD                                             ' HMENU

DECLARE FUNCTION GetMenuItemID IMPORT "USER32.DLL" ALIAS "GetMenuItemID" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL nPos AS LONG _                                 ' __in int nPos
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetMenuItemCount IMPORT "USER32.DLL" ALIAS "GetMenuItemCount" ( _
   OPTIONAL BYVAL hMenu AS DWORD _                      ' __in_opt HMENU hMenu
 ) AS LONG                                              ' int

DECLARE FUNCTION InsertMenuA IMPORT "USER32.DLL" ALIAS "InsertMenuA" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS ASCIIZ _                 ' __in_opt LPCSTR lpNewItem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InsertMenuW IMPORT "USER32.DLL" ALIAS "InsertMenuW" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS WSTRINGZ _               ' __in_opt LPCWSTR lpNewItem
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InsertMenu = InsertMenuW
#ELSE
   MACRO InsertMenu = InsertMenuA
#ENDIF

DECLARE FUNCTION AppendMenuA IMPORT "USER32.DLL" ALIAS "AppendMenuA" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS ASCIIZ _                 ' __in_opt LPCSTR lpNewItem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AppendMenuW IMPORT "USER32.DLL" ALIAS "AppendMenuW" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS WSTRINGZ _               ' __in_opt LPCWSTR lpNewItem
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AppendMenu = AppendMenuW
#ELSE
   MACRO AppendMenu = AppendMenuA
#ENDIF

DECLARE FUNCTION ModifyMenuA IMPORT "USER32.DLL" ALIAS "ModifyMenuA" ( _
   BYVAL hMnu AS DWORD _                                ' __in HMENU hMnu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS ASCIIZ _                 ' __in_opt LPCSTR lpNewItem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ModifyMenuW IMPORT "USER32.DLL" ALIAS "ModifyMenuW" ( _
   BYVAL hMnu AS DWORD _                                ' __in HMENU hMnu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL uIDNewItem AS DWORD _                          ' __in UINT_PTR uIDNewItem
 , OPTIONAL BYREF lpNewItem AS WSTRINGZ _               ' __in_opt LPCWSTR lpNewItem
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ModifyMenu = ModifyMenuW
#ELSE
   MACRO ModifyMenu = ModifyMenuA
#ENDIF

DECLARE FUNCTION RemoveMenu IMPORT "USER32.DLL" ALIAS "RemoveMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteMenu IMPORT "USER32.DLL" ALIAS "DeleteMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMenuItemBitmaps IMPORT "USER32.DLL" ALIAS "SetMenuItemBitmaps" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uPosition AS DWORD _                           ' __in UINT uPosition
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , OPTIONAL BYVAL hBitmapUnchecked AS DWORD _           ' __in_opt HBITMAP hBitmapUnchecked
 , OPTIONAL BYVAL hBitmapChecked AS DWORD _             ' __in_opt HBITMAP hBitmapChecked
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMenuCheckMarkDimensions IMPORT "USER32.DLL" ALIAS "GetMenuCheckMarkDimensions" ( _
 ) AS LONG                                              ' long

DECLARE FUNCTION TrackPopupMenu IMPORT "USER32.DLL" ALIAS "TrackPopupMenu" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL nReserved AS LONG _                            ' __in int nReserved
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYREF prcRect AS RECT _                     ' __in_opt CONST RECT *prcRect
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0400)
'/* return codes for WM_MENUCHAR */
%MNC_IGNORE  = 0&
%MNC_CLOSE   = 1&
%MNC_EXECUTE = 2&
%MNC_SELECT  = 3&

' // Size = 20 bytes
TYPE TPMPARAMS DWORD
   cbSize    AS DWORD   ' UINT /* Size of structure */
   rcExclude AS RECT    ' RECT /* Screen coordinates of rectangle to exclude when positioning */
END TYPE

DECLARE FUNCTION TrackPopupMenuEx IMPORT "USER32.DLL" ALIAS "TrackPopupMenuEx" (_
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL fuFlags AS DWORD _                             ' __in UINT fuFlags
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYREF ptpm AS TPMPARAMS _                   ' __in_opt LPTPMPARAMS ptpm
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0601)
DECLARE FUNCTION CalculatePopupWindowPosition IMPORT "USER32.DLL" ALIAS "CalculatePopupWindowPosition" (_
   BYREF anchorPoint AS POINT _                         ' __in const POINT *anchorPoint
 , BYREF windowSize AS SIZE _                           ' __in const SIZE *windowSize
 , BYVAL flags AS DWORD _                               ' __in UINT /* TPM_XXX values */ flags
 , BYREF excludeRect AS RECT _                          ' __in_opt RECT *excludeRect
 , BYREF popupWindowPosition AS RECT _                  ' __out RECT *popupWindowPosition
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if(WINVER >= 0x0500)

%MNS_NOCHECK         = &H80000000???
%MNS_MODELESS        = &H40000000???
%MNS_DRAGDROP        = &H20000000???
%MNS_AUTODISMISS     = &H10000000???
%MNS_NOTIFYBYPOS     = &H08000000???
%MNS_CHECKORBMP      = &H04000000???

%MIM_MAXHEIGHT       = &H00000001???
%MIM_BACKGROUND      = &H00000002???
%MIM_HELPID          = &H00000004???
%MIM_MENUDATA        = &H00000008???
%MIM_STYLE           = &H00000010???
%MIM_APPLYTOSUBMENUS = &H80000000???

' // Size = 28 bytes
TYPE MENUINFO DWORD
   cbSize          AS DWORD   ' DWORD
   fMask           AS DWORD   ' DWORD
   dwStyle         AS DWORD   ' DWORD
   cyMax           AS DWORD   ' UINT
   hbrBack         AS DWORD   ' HBRUSH
   dwContextHelpID AS DWORD   ' DWORD
   dwMenuData      AS DWORD   ' ULONG_PTR
END TYPE

DECLARE FUNCTION GetMenuInfo IMPORT "USER32.DLL" ALIAS "GetMenuInfo" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYREF lpcmi AS MENUINFO _                            ' __inout LPMENUINFO lpcmi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMenuInfo IMPORT "USER32.DLL" ALIAS "SetMenuInfo" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYREF lpcmi AS MENUINFO _                            ' __in LPCMENUINFO lpcmi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EndMenu IMPORT "USER32.DLL" ALIAS "EndMenu" ( _
 ) AS LONG                                              ' BOOL

'/*
' * WM_MENUDRAG return values.
' */

%MND_CONTINUE = 0&
%MND_ENDMENU  = 1&

' // Size = 20 bytes
TYPE MENUGETOBJECTINFO DWORD
   dwFlags AS DWORD   ' DWORD
   uPos    AS DWORD   ' UINT
   hmenu   AS DWORD   ' HMENU
   riid    AS DWORD   ' PVOID
   pvObj   AS DWORD   ' PVOID
END TYPE

'/*
' * MENUGETOBJECTINFO dwFlags values
' */
%MNGOF_TOPGAP     = &H00000001???
%MNGOF_BOTTOMGAP  = &H00000002???

'/*
' * WM_MENUGETOBJECT return values
' */
%MNGO_NOINTERFACE = &H00000000???
%MNGO_NOERROR     = &H00000001???
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0400)
%MIIM_STATE       = &H00000001???
%MIIM_ID          = &H00000002???
%MIIM_SUBMENU     = &H00000004???
%MIIM_CHECKMARKS  = &H00000008???
%MIIM_TYPE        = &H00000010???
%MIIM_DATA        = &H00000020???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%MIIM_STRING      = &H00000040???
%MIIM_BITMAP      = &H00000080???
%MIIM_FTYPE       = &H00000100???

%HBMMENU_CALLBACK        = &HFFFFFFFF??? ' ((HBITMAP) -1)
%HBMMENU_SYSTEM          =  1???         ' ((HBITMAP)  1)
%HBMMENU_MBAR_RESTORE    =  2???         ' ((HBITMAP)  2)
%HBMMENU_MBAR_MINIMIZE   =  3???         ' ((HBITMAP)  3)
%HBMMENU_MBAR_CLOSE      =  5???         ' ((HBITMAP)  5)
%HBMMENU_MBAR_CLOSE_D    =  6???         ' ((HBITMAP)  6)
%HBMMENU_MBAR_MINIMIZE_D =  7???         ' ((HBITMAP)  7)
%HBMMENU_POPUP_CLOSE     =  8???         ' ((HBITMAP)  8)
%HBMMENU_POPUP_RESTORE   =  9???         ' ((HBITMAP)  9)
%HBMMENU_POPUP_MAXIMIZE  = 10???         ' ((HBITMAP)  10)
%HBMMENU_POPUP_MINIMIZE  = 11???         ' ((HBITMAP)  11)
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0400)

' // Size = 48 bytes
TYPE MENUITEMINFOA DWORD
   cbSize        AS DWORD        ' UINT
   fMask         AS DWORD        ' UINT
   fType         AS DWORD        ' UINT     // used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
   fState        AS DWORD        ' UINT      // used if MIIM_STATE
   wID           AS DWORD        ' UINT      // used if MIIM_ID
   hSubMenu      AS DWORD        ' HMENU     // used if MIIM_SUBMENU
   hbmpChecked   AS DWORD        ' HBITMAP   // used if MIIM_CHECKMARKS
   hbmpUnchecked AS DWORD        ' HBITMAP   // used if MIIM_CHECKMARKS
   dwItemData    AS DWORD        ' ULONG_PTR // used if MIIM_DATA
   dwTypeData    AS ASCIIZ PTR   ' LPSTR     // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
   cch           AS DWORD        ' UINT      // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
#IF %WINVER >= &H0500
   hbmpItem      AS DWORD        ' HBITMAP   // used if MIIM_BITMAP
#ENDIF   ' /* WINVER >= 0x0500 */
END TYPE

' // Size = 48 bytes
TYPE MENUITEMINFOW DWORD
   cbSize        AS DWORD          ' UINT
   fMask         AS DWORD          ' UINT
   fType         AS DWORD          ' UINT      // used if MIIM_TYPE (4.0) or MIIM_FTYPE (>4.0)
   fState        AS DWORD          ' UINT      // used if MIIM_STATE
   wID           AS DWORD          ' UINT      // used if MIIM_ID
   hSubMenu      AS DWORD          ' HMENU     // used if MIIM_SUBMENU
   hbmpChecked   AS DWORD          ' HBITMAP   // used if MIIM_CHECKMARKS
   hbmpUnchecked AS DWORD          ' HBITMAP   // used if MIIM_CHECKMARKS
   dwItemData    AS DWORD          ' ULONG_PTR // used if MIIM_DATA
   dwTypeData    AS WSTRINGZ PTR   ' LPWSTR    // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
   cch           AS DWORD          ' UINT      // used if MIIM_TYPE (4.0) or MIIM_STRING (>4.0)
#IF %WINVER >= &H0500
   hbmpItem      AS DWORD          ' HBITMAP   // used if MIIM_BITMAP
#ENDIF   ' /* WINVER >= 0x0500 */
END TYPE

#IF %DEF(%UNICODE)
MACRO MENUITEMINFO = MENUITEMINFOW
#ELSE
MACRO MENUITEMINFO = MENUITEMINFOA
#ENDIF

DECLARE FUNCTION InsertMenuItemA IMPORT "USER32.DLL" ALIAS "InsertMenuItemA" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPosition AS LONG _                          ' __in BOOL fByPosition
 , BYREF lpmi AS MENUITEMINFOA _                        ' __in LPCMENUITEMINFOA lpmi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InsertMenuItemW IMPORT "USER32.DLL" ALIAS "InsertMenuItemW" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPosition AS LONG _                          ' __in BOOL fByPosition
 , BYREF lpmi AS MENUITEMINFOW _                        ' __in LPCMENUITEMINFOW lpmi
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InsertMenuItem = InsertMenuItemW
#ELSE
   MACRO InsertMenuItem = InsertMenuItemA
#ENDIF

DECLARE FUNCTION GetMenuItemInfoA IMPORT "USER32.DLL" ALIAS "GetMenuItemInfoA" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPosition AS LONG _                          ' __in BOOL fByPosition
 , BYREF lpmii AS MENUITEMINFOA _                       ' __inout LPMENUITEMINFOA lpmii
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMenuItemInfoW IMPORT "USER32.DLL" ALIAS "GetMenuItemInfoW" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPosition AS LONG _                          ' __in BOOL fByPosition
 , BYREF lpmii AS MENUITEMINFOW _                       ' __inout LPMENUITEMINFOW lpmii
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetMenuItemInfo = GetMenuItemInfoW
#ELSE
   MACRO GetMenuItemInfo = GetMenuItemInfoA
#ENDIF

DECLARE FUNCTION SetMenuItemInfoA IMPORT "USER32.DLL" ALIAS "SetMenuItemInfoA" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPositon AS LONG _                           ' __in BOOL fByPositon
 , BYREF lpmii AS MENUITEMINFOA _                       ' __in LPCMENUITEMINFOA lpmii
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMenuItemInfoW IMPORT "USER32.DLL" ALIAS "SetMenuItemInfoW" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL item AS DWORD _                                ' __in UINT item
 , BYVAL fByPositon AS LONG _                           ' __in BOOL fByPositon
 , BYREF lpmii AS MENUITEMINFOW _                       ' __in LPCMENUITEMINFOW lpmii
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetMenuItemInfo = SetMenuItemInfoW
#ELSE
   MACRO SetMenuItemInfo = SetMenuItemInfoA
#ENDIF

%GMDI_USEDISABLED    = &H0001???
%GMDI_GOINTOPOPUPS   = &H0002???

DECLARE FUNCTION GetMenuDefaultItem IMPORT "USER32.DLL" ALIAS "GetMenuDefaultItem" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL fByPos AS DWORD _                              ' __in UINT fByPos
 , BYVAL gmdiFlags AS DWORD _                           ' __in UINT gmdiFlags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetMenuDefaultItem IMPORT "USER32.DLL" ALIAS "SetMenuDefaultItem" ( _
   BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uItem AS DWORD _                               ' __in UINT uItem
 , BYVAL fByPos AS DWORD _                              ' __in UINT fByPos
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMenuItemRect IMPORT "USER32.DLL" ALIAS "GetMenuItemRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL uItem AS DWORD _                               ' __in UINT uItem
 , BYREF lprcItem AS RECT _                             ' __out LPRECT lprcItem
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MenuItemFromPoint IMPORT "USER32.DLL" ALIAS "MenuItemFromPoint" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL pt AS POINT _                                  ' __in pt POINT
 ) AS LONG                                              ' int

' // Same as above, but using x, y coordinates
DECLARE FUNCTION MenuItemFromXY IMPORT "USER32.DLL" ALIAS "MenuItemFromPoint" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL hMenu AS DWORD _                               ' __in HMENU hMenu
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS LONG                                              ' int

'#endif /* WINVER >= 0x0400 */

'/*
' * Flags for TrackPopupMenu
' */
'%TPM_LEFTBUTTON      = &H0000???
'%TPM_RIGHTBUTTON     = &H0002???
'%TPM_LEFTALIGN       = &H0000???
'%TPM_CENTERALIGN     = &H0004???
'%TPM_RIGHTALIGN      = &H0008???

'#if(WINVER >= 0x0400)
'%TPM_TOPALIGN        = &H0000???
'%TPM_VCENTERALIGN    = &H0010???
'%TPM_BOTTOMALIGN     = &H0020???

%TPM_HORIZONTAL      = &H0000???  ' Horz alignment matters more
%TPM_VERTICAL        = &H0040???  ' Vert alignment matters more
%TPM_NONOTIFY        = &H0080???  ' Don't send any notification msgs
%TPM_RETURNCMD       = &H0100???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%TPM_RECURSE         = &H00001???
%TPM_HORPOSANIMATION = &H00400???
%TPM_HORNEGANIMATION = &H00800???
%TPM_VERPOSANIMATION = &H01000???
%TPM_VERNEGANIMATION = &H02000???
'#if(_WIN32_WINNT >= 0x0500)
%TPM_NOANIMATION     = &H04000???
'#endif /* _WIN32_WINNT >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0501)
%TPM_LAYOUTRTL       = &H08000???
'#endif /* _WIN32_WINNT >= 0x0501 */
'#endif /* WINVER >= 0x0500 */
'#if(_WIN32_WINNT >= 0x0601)
%TPM_WORKAREA        = &H10000???
'#endif /* _WIN32_WINNT >= 0x0601 */


'#endif /* !NOMENUS */
'#ENDIF   ' #IF NOT %DEF(%NOMENUS) ' -------------------------------------------


'#if(WINVER >= 0x0400)
'//
'// Drag-and-drop support
'// Obsolete - use OLE instead
'//

' // Size = 28 bytes
TYPE DROPSTRUCT DWORD
   hwndSource    AS DWORD   ' HWND
   hwndSink      AS DWORD   ' HWND
   wFmt          AS DWORD   ' DWORD
   dwData        AS DWORD   ' ULONG_PTR
   ptDrop        AS POINT   ' POINT
   dwControlData AS DWORD   ' DWORD
END TYPE

%DOF_EXECUTABLE = &H8001???      ' wFmt flags
%DOF_DOCUMENT   = &H8002???
%DOF_DIRECTORY  = &H8003???
%DOF_MULTIPLE   = &H8004???
%DOF_PROGMAN    = &H0001???
%DOF_SHELLDATA  = &H0002???

%DO_DROPFILE    = &H454C4946???
%DO_PRINTFILE   = &H544E5250???

DECLARE FUNCTION DragObject IMPORT "USER32.DLL" ALIAS "DragObject" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hwndParent
 , BYVAL hwndFrom AS DWORD _                            ' __in HWND hwndFrom
 , BYVAL fmt AS DWORD _                                 ' __in UINT fmt
 , BYVAL data AS DWORD _                                ' __in ULONG_PTR data
 , OPTIONAL BYVAL hcur AS DWORD _                       ' __in_opt HCURSOR hcur
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DragDetect IMPORT "USER32.DLL" ALIAS "DragDetect" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL pt AS POINT _                                  ' __in pt POINT
 ) AS LONG                                              ' BOOL

' // Same as above, but using x, y coordinates
DECLARE FUNCTION DragDetectXY IMPORT "USER32.DLL" ALIAS "DragDetect" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION DrawIcon IMPORT "USER32.DLL" ALIAS "DrawIcon" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 ) AS LONG                                              ' BOOL

'#IF NOT %DEF(%NODRAWTEXT) ' ---------------------------------------------------
'#ifndef NODRAWTEXT

'/*
' * DrawText() Format Flags
' */
%DT_TOP                  = &H00000000???
%DT_LEFT                 = &H00000000???
%DT_CENTER               = &H00000001???
%DT_RIGHT                = &H00000002???
%DT_VCENTER              = &H00000004???
%DT_BOTTOM               = &H00000008???
%DT_WORDBREAK            = &H00000010???
%DT_SINGLELINE           = &H00000020???
%DT_EXPANDTABS           = &H00000040???
%DT_TABSTOP              = &H00000080???
%DT_NOCLIP               = &H00000100???
%DT_EXTERNALLEADING      = &H00000200???
%DT_CALCRECT             = &H00000400???
%DT_NOPREFIX             = &H00000800???
%DT_INTERNAL             = &H00001000???

'#if(WINVER >= 0x0400)
%DT_EDITCONTROL          = &H00002000???
%DT_PATH_ELLIPSIS        = &H00004000???
%DT_END_ELLIPSIS         = &H00008000???
%DT_MODIFYSTRING         = &H00010000???
%DT_RTLREADING           = &H00020000???
%DT_WORD_ELLIPSIS        = &H00040000???
'#if(WINVER >= 0x0500)
%DT_NOFULLWIDTHCHARBREAK = &H00080000???
'#if(_WIN32_WINNT >= 0x0500)
%DT_HIDEPREFIX           = &H00100000???
%DT_PREFIXONLY           = &H00200000???
'#endif /* _WIN32_WINNT >= 0x0500 */
'#endif /* WINVER >= 0x0500 */

' // Size = 20 bytes
TYPE DRAWTEXTPARAMS DWORD
   cbSize        AS DWORD   ' UINT
   iTabLength    AS LONG    ' int
   iLeftMargin   AS LONG    ' int
   iRightMargin  AS LONG    ' int
   uiLengthDrawn AS DWORD   ' UINT
END TYPE

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION DrawTextA IMPORT "USER32.DLL" ALIAS "DrawTextA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpchText AS ASCIIZ _                           ' __in LPCSTR lpchText
 , BYVAL cchText AS LONG _                              ' __in int cchText
 , BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL format AS DWORD _                              ' __in UINT format
 ) AS LONG                                              ' int

DECLARE FUNCTION DrawTextW IMPORT "USER32.DLL" ALIAS "DrawTextW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpchText AS WSTRINGZ _                         ' __in LPCWSTR lpchText
 , BYVAL cchText AS LONG _                              ' __in int cchText
 , BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL format AS DWORD _                              ' __in UINT format
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DrawText = DrawTextW
#ELSE
   MACRO DrawText = DrawTextA
#ENDIF

'#if(WINVER >= 0x0400)

DECLARE FUNCTION DrawTextExA IMPORT "USER32.DLL" ALIAS "DrawTextExA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpchText AS ASCIIZ _                           ' __in LPSTR lpchText
 , BYVAL cchText AS LONG _                              ' __in int cchText
 , BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL format AS DWORD _                              ' __in UINT format
 , OPTIONAL BYREF lpdtp AS DRAWTEXTPARAMS _             ' __in_opt LPDRAWTEXTPARAMS lpdtp
 ) AS LONG                                              ' int

DECLARE FUNCTION DrawTextExW IMPORT "USER32.DLL" ALIAS "DrawTextExW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpchText AS WSTRINGZ _                         ' __in LPWSTR lpchText
 , BYVAL cchText AS LONG _                              ' __in int cchText
 , BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL format AS DWORD _                              ' __in UINT format
 , OPTIONAL BYREF lpdtp AS DRAWTEXTPARAMS _             ' __in_opt LPDRAWTEXTPARAMS lpdtp
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DrawTextEx = DrawTextExW
#ELSE
   MACRO DrawTextEx = DrawTextExA
#ENDIF

'#endif /* !NODRAWTEXT */
'#ENDIF   ' #IF NOT %DEF(%NODRAWTEXT) ' ----------------------------------------

DECLARE FUNCTION GrayStringA IMPORT "USER32.DLL" ALIAS "GrayStringA" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL hBrush AS DWORD _                              ' __in_opt HBRUSH hBrush
 , BYVAL lpOutputFunc AS DWORD _                        ' __in_opt GRAYSTRINGPROC lpOutputFunc
 , BYVAL lpData AS LONG _                               ' __in LPARAM lpData
 , BYVAL nCount AS LONG _                               ' __in int nCount
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG  _                              ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GrayStringW IMPORT "USER32.DLL" ALIAS "GrayStringW" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL hBrush AS DWORD _                              ' __in_opt HBRUSH hBrush
 , BYVAL lpOutputFunc AS DWORD _                        ' __in_opt GRAYSTRINGPROC lpOutputFunc
 , BYVAL lpData AS LONG _                               ' __in LPARAM lpData
 , BYVAL nCount AS LONG _                               ' __in int nCount
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GrayString = GrayStringW
#ELSE
   MACRO GrayString = GrayStringA
#ENDIF

'#if(WINVER >= 0x0400)
'/* Monolithic state-drawing routine */
'/* Image type */
%DST_COMPLEX    = &H0000???
%DST_TEXT       = &H0001???
%DST_PREFIXTEXT = &H0002???
%DST_ICON       = &H0003???
%DST_BITMAP     = &H0004???

'/* State type */
%DSS_NORMAL     = &H0000???
%DSS_UNION      = &H0010???  ' Gray string appearance
%DSS_DISABLED   = &H0020???
%DSS_MONO       = &H0080???
'#if(_WIN32_WINNT >= 0x0500)
%DSS_HIDEPREFIX = &H0200???
%DSS_PREFIXONLY = &H0400???
'#endif /* _WIN32_WINNT >= 0x0500 */
%DSS_RIGHT      = &H8000???

DECLARE FUNCTION DrawStateA IMPORT "USER32.DLL" ALIAS "DrawStateA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hbrFore AS DWORD _                             ' __in_opt HBRUSH hbrFore
 , BYVAL qfnCallBack AS DWORD _                         ' __in_opt DRAWSTATEPROC qfnCallBack
 , BYVAL lData AS LONG _                                ' __in LPARAM lData
 , BYVAL wData AS DWORD _                               ' __in WPARAM wData
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DrawStateW IMPORT "USER32.DLL" ALIAS "DrawStateW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hbrFore AS DWORD _                             ' __in_opt HBRUSH hbrFore
 , BYVAL qfnCallBack AS DWORD _                         ' __in_opt DRAWSTATEPROC qfnCallBack
 , BYVAL lData AS LONG _                                ' __in LPARAM lData
 , BYVAL wData AS DWORD _                               ' __in WPARAM wData
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DrawState = DrawStateW
#ELSE
   MACRO DrawState = DrawStateA
#ENDIF

DECLARE FUNCTION TabbedTextOutA IMPORT "USER32.DLL" ALIAS "TabbedTextOutA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL nTabPositions AS LONG _                        ' __in int nTabPositions
 , BYREF lpnTabStopPositions AS LONG _                  ' __in CONST INT *lpnTabStopPositions
 , BYVAL nTabOrigin AS LONG _                           ' __in int nTabOrigin
 ) AS LONG                                              ' long

DECLARE FUNCTION TabbedTextOutW IMPORT "USER32.DLL" ALIAS "TabbedTextOutW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL nTabPositions AS LONG _                        ' __in int nTabPositions
 , BYREF lpnTabStopPositions AS LONG _                  ' __in CONST INT *lpnTabStopPositions
 , BYVAL nTabOrigin AS LONG _                           ' __in int nTabOrigin
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO TabbedTextOut = TabbedTextOutW
#ELSE
   MACRO TabbedTextOut = TabbedTextOutA
#ENDIF

DECLARE FUNCTION GetTabbedTextExtentA IMPORT "USER32.DLL" ALIAS "GetTabbedTextExtentA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL nTabPositions AS LONG _                        ' __in int nTabPositions
 , BYREF lpnTabStopPositions AS LONG _                  ' __in CONST INT *lpnTabStopPositions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetTabbedTextExtentW IMPORT "USER32.DLL" ALIAS "GetTabbedTextExtentW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL nTabPositions AS LONG _                        ' __in int nTabPositions
 , BYREF lpnTabStopPositions AS LONG _                  ' __in CONST INT *lpnTabStopPositions
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetTabbedTextExtent = GetTabbedTextExtentW
#ELSE
   MACRO GetTabbedTextExtent = GetTabbedTextExtentA
#ENDIF

DECLARE FUNCTION UpdateWindow IMPORT "USER32.DLL" ALIAS "UpdateWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetActiveWindow IMPORT "USER32.DLL" ALIAS "SetActiveWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetForegroundWindow IMPORT "USER32.DLL" ALIAS "GetForegroundWindow" ( _
 ) AS DWORD                                             ' HWND

'#if(WINVER >= 0x0400)

DECLARE FUNCTION PaintDesktop IMPORT "USER32.DLL" ALIAS "PaintDesktop" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

' Although you can access this function by using LoadLibrary and GetProcAddress
' combined in Microsoft Windows versions prior to Windows XP, the function is
' not accessible using the standard Include file and library linkage. The header
' files included in Windows XP Service Pack 1 (SP1) and Windows Server 2003
' document this function and make it accessible using the appropriate Include
' file and library linkage. However, this function is deprecated and not intended
' for general use. It is recommended that you do not use it in new programs
' because it might be altered or unavailable in subsequent versions of Windows.

DECLARE SUB SwitchToThisWindow IMPORT "USER32.DLL" ALIAS "SwitchToThisWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL fUnknown AS LONG _                             ' __in BOOL fUnknown
 )                                                      ' VOID

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION SetForegroundWindow IMPORT "USER32.DLL" ALIAS "SetForegroundWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION AllowSetForegroundWindow IMPORT "USER32.DLL" ALIAS "AllowSetForegroundWindow" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 ) AS LONG                                              ' BOOL

%ASFW_ANY = &HFFFFFFFF??? ' ((DWORD)-1)

DECLARE FUNCTION LockSetForegroundWindow IMPORT "USER32.DLL" ALIAS "LockSetForegroundWindow" ( _
   BYVAL uLockCode AS DWORD _                           ' __in UINT uLockCode
 ) AS LONG                                              ' BOOL

%LSFW_LOCK   = 1???
%LSFW_UNLOCK = 2???

'#endif /* _WIN32_WINNT >= 0x0500 */

DECLARE FUNCTION WindowFromDC IMPORT "USER32.DLL" ALIAS "WindowFromDC" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetDC IMPORT "USER32.DLL" ALIAS "GetDC" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION GetDCEx IMPORT "USER32.DLL" ALIAS "GetDCEx" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL hrgnClip AS DWORD _                            ' __in_opt HRGN hrgnClip
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 ) AS DWORD                                             ' HDC

'/*
' * GetDCEx() flags
' */
%DCX_WINDOW           = &H00000001???
%DCX_CACHE            = &H00000002???
%DCX_NORESETATTRS     = &H00000004???
%DCX_CLIPCHILDREN     = &H00000008???
%DCX_CLIPSIBLINGS     = &H00000010???
%DCX_PARENTCLIP       = &H00000020???
%DCX_EXCLUDERGN       = &H00000040???
%DCX_INTERSECTRGN     = &H00000080???
%DCX_EXCLUDEUPDATE    = &H00000100???
%DCX_INTERSECTUPDATE  = &H00000200???
%DCX_LOCKWINDOWUPDATE = &H00000400???

%DCX_VALIDATE         = &H00200000???

DECLARE FUNCTION GetWindowDC IMPORT "USER32.DLL" ALIAS "GetWindowDC" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION ReleaseDC IMPORT "USER32.DLL" ALIAS "ReleaseDC" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 ) AS LONG                                              ' int

DECLARE FUNCTION BeginPaint IMPORT "USER32.DLL" ALIAS "BeginPaint" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPaint AS PAINTSTRUCT _                       ' __out LPPAINTSTRUCT lpPaint
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION EndPaint IMPORT "USER32.DLL" ALIAS "EndPaint" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPaint AS PAINTSTRUCT _                       ' __in CONST PAINTSTRUCT *lpPaint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUpdateRect IMPORT "USER32.DLL" ALIAS "GetUpdateRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpRect AS RECT _                               ' __out_opt LPRECT lpRect
 , BYVAL bErase AS LONG _                               ' __in BOOL bErase
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetUpdateRgn IMPORT "USER32.DLL" ALIAS "GetUpdateRgn" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hRgn AS DWORD _                                ' __in HRGN hRgn
 , BYVAL bErase AS LONG _                               ' __in BOOL bErase
 ) AS LONG                                              ' int

DECLARE FUNCTION SetWindowRgn IMPORT "USER32.DLL" ALIAS "SetWindowRgn" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hRgn AS DWORD _                                ' __in_opt HRGN hRgn
 , BYVAL bRedraw AS LONG _                              ' __in BOOL bRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION GetWindowRgn IMPORT "USER32.DLL" ALIAS "GetWindowRgn" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hRgn AS DWORD _                                ' __in HRGN hRgn
 ) AS LONG                                              ' int

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION GetWindowRgnBox IMPORT "USER32.DLL" ALIAS "GetWindowRgnBox" ( _
   BYVAL hWnd AS DWORD  _                               ' __in HWND hWnd
 , BYREF lprc AS RECT _                                 ' __out LPRECT lprc
 ) AS LONG                                              ' int

'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION ExcludeUpdateRgn IMPORT "USER32.DLL" ALIAS "ExcludeUpdateRgn" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' int

DECLARE FUNCTION InvalidateRect IMPORT "USER32.DLL" ALIAS "InvalidateRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpRect AS RECT _                               ' __in_opt CONST RECT *lpRect
 , BYVAL bErase AS LONG _                               ' __in BOOL bErase
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ValidateRect IMPORT "USER32.DLL" ALIAS "ValidateRect" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 , OPTIONAL BYREF lpRect AS RECT _                      ' __in_opt CONST RECT *lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InvalidateRgn IMPORT "USER32.DLL" ALIAS "InvalidateRgn" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hRgn AS DWORD _                                ' __in_opt HRGN hRgn
 , BYVAL bErase AS LONG _                               ' __in BOOL bErase
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ValidateRgn IMPORT "USER32.DLL" ALIAS "ValidateRgn" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYVAL hRgn AS DWORD _                       ' __in_opt HRGN hRgn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RedrawWindow IMPORT "USER32.DLL" ALIAS "RedrawWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lprcUpdate AS RECT _                           ' __in_opt CONST RECT *lprcUpdate
 , BYVAL hrgnUpdate AS DWORD _                          ' __in_opt HRGN hrgnUpdate
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' BOOL

'/*
' * RedrawWindow() flags
' */
%RDW_INVALIDATE      = &H0001???
%RDW_INTERNALPAINT   = &H0002???
%RDW_ERASE           = &H0004???

%RDW_VALIDATE        = &H0008???
%RDW_NOINTERNALPAINT = &H0010???
%RDW_NOERASE         = &H0020???

%RDW_NOCHILDREN      = &H0040???
%RDW_ALLCHILDREN     = &H0080???

%RDW_UPDATENOW       = &H0100???
%RDW_ERASENOW        = &H0200???

%RDW_FRAME           = &H0400???
%RDW_NOFRAME         = &H0800???


'/*
' * LockWindowUpdate API
' */

DECLARE FUNCTION LockWindowUpdate IMPORT "USER32.DLL" ALIAS "LockWindowUpdate" ( _
   OPTIONAL BYVAL hWndLock AS DWORD _                   ' __in_opt HWND hWndLock
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScrollWindow IMPORT "USER32.DLL" ALIAS "ScrollWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL XAmount AS LONG _                              ' __in int XAmount
 , BYVAL YAmount AS LONG _                              ' __in int YAmount
 , OPTIONAL BYREF lpRect AS RECT _                      ' __in_opt CONST RECT *lpRect
 , OPTIONAL BYREF lpClipRect AS RECT _                  ' __in_opt CONST RECT *lpClipRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScrollDC IMPORT "USER32.DLL" ALIAS "ScrollDC" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 , OPTIONAL BYREF lprcScroll AS RECT _                  ' __in_opt CONST RECT *lprcScroll
 , OPTIONAL BYREF lprcClip AS RECT _                    ' __in_opt CONST RECT *lprcClip
 , OPTIONAL BYVAL hrgnUpdate AS DWORD _                 ' __in_opt HRGN hrgnUpdate
 , OPTIONAL BYREF lprcUpdate AS RECT _                  ' __out_opt LPRECT lprcUpdate
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScrollWindowEx IMPORT "USER32.DLL" ALIAS "ScrollWindowEx" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 , BYREF prcScroll AS RECT _                            ' __in_opt CONST RECT *prcScroll
 , BYREF prcClip AS RECT _                              ' __in_opt CONST RECT *prcClip
 , BYVAL hrgnUpdate AS DWORD _                          ' __in_opt HRGN hrgnUpdate
 , BYREF prcUpdate AS RECT _                            ' __out_opt LPRECT prcUpdate
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' int

%SW_SCROLLCHILDREN = &H0001???   ' /* Scroll children within *lprcScroll. */
%SW_INVALIDATE     = &H0002???   ' /* Invalidate after scrolling */
%SW_ERASE          = &H0004???   ' /* If SW_INVALIDATE, don't send WM_ERASEBACKGROUND */
'#if(WINVER >= 0x0500)
%SW_SMOOTHSCROLL   = &H0010???   ' /* Use smooth scrolling */
'#endif /* WINVER >= 0x0500 */

'#IF NOT %DEF(%NOSCROLL) ' -----------------------------------------------------
'#ifndef NOSCROLL

DECLARE FUNCTION SetScrollPos IMPORT "USER32.DLL" ALIAS "SetScrollPos" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 , BYVAL nPos AS LONG _                                 ' __in int nPos
 , BYVAL bRedraw AS LONG _                              ' __in BOOL bRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION GetScrollPos IMPORT "USER32.DLL" ALIAS "GetScrollPos" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 ) AS LONG                                              ' int

DECLARE FUNCTION SetScrollRange IMPORT "USER32.DLL" ALIAS "SetScrollRange" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 , BYVAL nMinPos AS LONG _                              ' __in int nMinPos
 , BYVAL nMaxPos AS LONG _                              ' __in int nMaxPos
 , BYVAL bRedraw AS LONG _                              ' __in BOOL bRedraw
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetScrollRange IMPORT "USER32.DLL" ALIAS "GetScrollRange" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 , BYREF lpMinPos AS LONG _                             ' __out LPINT lpMinPos
 , BYREF lpMaxPos AS LONG _                             ' __out LPINT lpMaxPos
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShowScrollBar IMPORT "USER32.DLL" ALIAS "ShowScrollBar" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wBar AS LONG _                                 ' __in int wBar
 , BYVAL bShow AS LONG _                                ' __in BOOL bShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnableScrollBar IMPORT "USER32.DLL" ALIAS "EnableScrollBar" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wSBflags AS DWORD _                            ' __in UINT wSBflags
 , BYVAL wArrows AS DWORD _                             ' __in UINT wArrows
 ) AS LONG                                              ' BOOL

'/*
' * EnableScrollBar() flags
' */
%ESB_ENABLE_BOTH   = &H0000???
%ESB_DISABLE_BOTH  = &H0003???

%ESB_DISABLE_LEFT  = &H0001???
%ESB_DISABLE_RIGHT = &H0002???

%ESB_DISABLE_UP    = &H0001???
%ESB_DISABLE_DOWN  = &H0002???

%ESB_DISABLE_LTUP  = %ESB_DISABLE_LEFT
%ESB_DISABLE_RTDN  = %ESB_DISABLE_RIGHT

'#endif  /* !NOSCROLL */
'#ENDIF   ' #IF NOT %DEF(%NOSCROLL) ' ------------------------------------------

DECLARE FUNCTION SetPropA IMPORT "USER32.DLL" ALIAS "SetPropA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , OPTIONAL BYVAL hData AS DWORD _                      ' __in_opt HANDLE hData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetPropW IMPORT "USER32.DLL" ALIAS "SetPropW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , OPTIONAL BYVAL hData AS DWORD _                      ' __in_opt HANDLE hData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetProp = SetPropW
#ELSE
   MACRO SetProp = SetPropA
#ENDIF

DECLARE FUNCTION GetPropA IMPORT "USER32.DLL" ALIAS "GetPropA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetPropW IMPORT "USER32.DLL" ALIAS "GetPropW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS DWORD                                             ' HANDLE

' // Not a macro because GetPropW conflicts with the GetPropW method of the IMimeMessageW interface.
#IF %DEF(%UNICODE)
DECLARE FUNCTION GetProp IMPORT "USER32.DLL" ALIAS "GetPropW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS DWORD                                             ' HANDLE
#ELSE
DECLARE FUNCTION GetProp IMPORT "USER32.DLL" ALIAS "GetPropA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS DWORD                                             ' HANDLE
#ENDIF

DECLARE FUNCTION RemovePropA IMPORT "USER32.DLL" ALIAS "RemovePropA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION RemovePropW IMPORT "USER32.DLL" ALIAS "RemovePropW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO RemoveProp = RemovePropW
#ELSE
   MACRO RemoveProp = RemovePropA
#ENDIF

DECLARE FUNCTION EnumPropsExA IMPORT "USER32.DLL" ALIAS "EnumPropsExA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lpEnumFunc AS DWORD _                          ' __in PROPENUMPROCEXA lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumPropsExW IMPORT "USER32.DLL" ALIAS "EnumPropsExW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lpEnumFunc AS DWORD _                          ' __in PROPENUMPROCEXW lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumPropsEx = EnumPropsExW
#ELSE
   MACRO EnumPropsEx = EnumPropsExA
#ENDIF

DECLARE FUNCTION EnumPropsA IMPORT "USER32.DLL" ALIAS "EnumPropsA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lpEnumFunc AS DWORD _                          ' __in PROPENUMPROCA lpEnumFunc
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumPropsW IMPORT "USER32.DLL" ALIAS "EnumPropsW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lpEnumFunc AS DWORD _                          ' __in PROPENUMPROCW lpEnumFunc
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumProps = EnumPropsW
#ELSE
   MACRO EnumProps = EnumPropsA
#ENDIF

DECLARE FUNCTION SetWindowTextA IMPORT "USER32.DLL" ALIAS "SetWindowTextA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYREF lpString AS ASCIIZ _                  ' __in_opt LPCSTR lpString
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowTextW IMPORT "USER32.DLL" ALIAS "SetWindowTextW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYREF lpString AS WSTRINGZ _                ' __in_opt LPCWSTR lpString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetWindowText = SetWindowTextW
#ELSE
   MACRO SetWindowText = SetWindowTextA
#ENDIF

DECLARE FUNCTION GetWindowTextA IMPORT "USER32.DLL" ALIAS "GetWindowTextA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpString AS ASCIIZ _                           ' __out LPSTR lpString
 , BYVAL nMaxCount AS LONG _                            ' __in int nMaxCount
 ) AS LONG                                              ' int

DECLARE FUNCTION GetWindowTextW IMPORT "USER32.DLL" ALIAS "GetWindowTextW" ( _
   BYVAL hWnd AS DWORD   _                              ' __in HWND hWnd
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL nMaxCount AS LONG _                            ' __in int nMaxCount
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetWindowText = GetWindowTextW
#ELSE
   MACRO GetWindowText = GetWindowTextA
#ENDIF

DECLARE FUNCTION GetWindowTextLengthA IMPORT "USER32.DLL" ALIAS "GetWindowTextLengthA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' int

DECLARE FUNCTION GetWindowTextLengthW IMPORT "USER32.DLL" ALIAS "GetWindowTextLengthW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetWindowTextLength = GetWindowTextLengthW
#ELSE
   MACRO GetWindowTextLength = GetWindowTextLengthA
#ENDIF

DECLARE FUNCTION GetClientRect IMPORT "USER32.DLL" ALIAS "GetClientRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpRect AS RECT _                               ' __out LPRECT lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowRect IMPORT "USER32.DLL" ALIAS "GetWindowRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpRect AS RECT _                               ' __out LPRECT lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AdjustWindowRect IMPORT "USER32.DLL" ALIAS "AdjustWindowRect" ( _
   BYREF lpRect AS RECT _                               ' __inout LPRECT lpRect
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL bMenu AS LONG _                                ' __in BOOL bMenu
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AdjustWindowRectEx IMPORT "USER32.DLL" ALIAS "AdjustWindowRectEx" ( _
   BYREF lpRect AS RECT _                               ' __inout LPRECT lpRect
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL bMenu AS LONG _                                ' __in BOOL bMenu
 , BYVAL dwExStyle AS DWORD _                           ' __in DWORD dwExStyle
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0400)
%HELPINFO_WINDOW   = &H0001&
%HELPINFO_MENUITEM = &H0002&

' // Size = 28 bytes
TYPE HELPINFO DWORD
   cbSize       AS DWORD   ' UINT      /* Size in bytes of this struct  */
   iContextType AS LONG    ' int       /* Either HELPINFO_WINDOW or HELPINFO_MENUITEM */
   iCtrlId      AS LONG    ' int       /* Control Id or a Menu item Id. */
   hItemHandle  AS DWORD   ' HANDLE    /* hWnd of control or hMenu.     */
   dwContextId  AS DWORD   ' DWORD_PTR /* Context Id associated with this item */
   MousePos     AS POINT   ' POINT     /* Mouse Position in screen co-ordinates */
END TYPE

DECLARE FUNCTION SetWindowContextHelpId IMPORT "USER32.DLL" ALIAS "SetWindowContextHelpId" ( _
   BYVAL hwnd AS DWORD  _                               ' __in HWND hwnd
 , BYVAL dwContextHelpId AS DWORD _                     ' __in DWORD dwContextHelpId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowContextHelpId IMPORT "USER32.DLL" ALIAS "GetWindowContextHelpId" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetMenuContextHelpId IMPORT "USER32.DLL" ALIAS "SetMenuContextHelpId" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL dwContextHelpId AS DWORD _                     ' __in DWORD dwContextHelpId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMenuContextHelpId IMPORT "USER32.DLL" ALIAS "GetMenuContextHelpId" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 ) AS DWORD                                             ' DWORD

'#endif /* WINVER >= 0x0400 */


'#IF NOT %DEF(%NOMB) ' ---------------------------------------------------------
'#ifndef NOMB

'/*
' * MessageBox() Flags
' */
'%MB_OK                        = &H00000000???
'%MB_OKCANCEL                  = &H00000001???
'%MB_ABORTRETRYIGNORE          = &H00000002???
'%MB_YESNOCANCEL               = &H00000003???
'%MB_YESNO                     = &H00000004???
'%MB_RETRYCANCEL               = &H00000005???
'#if(WINVER >= 0x0500)
'%MB_CANCELTRYCONTINUE         = &H00000006???
'#endif /* WINVER >= 0x0500 */

'%MB_ICONHAND                  = &H00000010???
'%MB_ICONQUESTION              = &H00000020???
'%MB_ICONEXCLAMATION           = &H00000030???
'%MB_ICONASTERISK              = &H00000040???

'#if(WINVER >= 0x0400)
'%MB_USERICON                  = &H00000080???
'%MB_ICONWARNING               = %MB_ICONEXCLAMATION
'%MB_ICONERROR                 = %MB_ICONHAND
'#endif /* WINVER >= 0x0400 */

'%MB_ICONINFORMATION           = %MB_ICONASTERISK
'%MB_ICONSTOP                  = %MB_ICONHAND

'%MB_DEFBUTTON1                = &H00000000???
'%MB_DEFBUTTON2                = &H00000100???
'%MB_DEFBUTTON3                = &H00000200???
'#if(WINVER >= 0x0400)
'%MB_DEFBUTTON4                = &H00000300???
'#endif /* WINVER >= 0x0400 */

'%MB_APPLMODAL                 = &H00000000???
'%MB_SYSTEMMODAL               = &H00001000???
'%MB_TASKMODAL                 = &H00002000???
'#if(WINVER >= 0x0400)
'%MB_HELP                      = &H00004000???  ' Help Button
'#endif /* WINVER >= 0x0400 */

'%MB_NOFOCUS                   = &H00008000???
'%MB_SETFOREGROUND             = &H00010000???
'%MB_DEFAULT_DESKTOP_ONLY      = &H00020000???

'%MB_TOPMOST                   = &H00040000???
'%MB_RIGHT                     = &H00080000???
'%MB_RTLREADING                = &H00100000???

'#endif /* WINVER >= 0x0400 */

'#ifdef _WIN32_WINNT
'#if (_WIN32_WINNT >= 0x0400)
'#define MB_SERVICE_NOTIFICATION          0x00200000L
'#else
'#define MB_SERVICE_NOTIFICATION          0x00040000L
'#endif
'#define MB_SERVICE_NOTIFICATION_NT3X     0x00040000L
'#endif

'%MB_SERVICE_NOTIFICATION      = &H00200000???
'%MB_SERVICE_NOTIFICATION_NT3X = &H00040000???

'%MB_TYPEMASK                  = &H0000000F???
'%MB_ICONMASK                  = &H000000F0???
'%MB_DEFMASK                   = &H00000F00???
'%MB_MODEMASK                  = &H00003000???
'%MB_MISCMASK                  = &H0000C000???

DECLARE FUNCTION MessageBoxA IMPORT "USER32.DLL" ALIAS "MessageBoxA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS ASCIIZ _                             ' __in_opt LPCSTR lpText
 , BYREF lpCaption AS ASCIIZ _                          ' __in_opt LPCSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 ) AS LONG                                              ' int

DECLARE FUNCTION MessageBoxW IMPORT "USER32.DLL" ALIAS "MessageBoxW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS WSTRINGZ _                           ' __in_opt LPCWSTR lpText
 , BYREF lpCaption AS WSTRINGZ _                        ' __in_opt LPCWSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO MessageBox = MessageBoxW
#ELSE
   MACRO MessageBox = MessageBoxA
#ENDIF

DECLARE FUNCTION MessageBoxExA IMPORT "USER32.DLL" ALIAS "MessageBoxExA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS ASCIIZ _                             ' __in_opt LPCSTR lpText
 , BYREF lpCaption AS ASCIIZ _                          ' __in_opt LPCSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL wLanguageId AS WORD _                          ' __in WORD wLanguageId
 ) AS LONG                                              ' int

DECLARE FUNCTION MessageBoxExW IMPORT "USER32.DLL" ALIAS "MessageBoxExW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS WSTRINGZ _                           ' __in_opt LPCWSTR lpText
 , BYREF lpCaption AS WSTRINGZ _                        ' __in_opt LPCWSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL wLanguageId AS WORD _                          ' __in WORD wLanguageId
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO MessageBoxEx = MessageBoxExW
#ELSE
   MACRO MessageBoxEx = MessageBoxExA
#ENDIF

' Undocumented
DECLARE FUNCTION MessageBoxTimeoutA IMPORT "USER32.DLL" ALIAS "MessageBoxTimeoutA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS ASCIIZ _                             ' __in_opt LPCSTR lpText
 , BYREF lpCaption AS ASCIIZ _                          ' __in_opt LPCSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL wLanguageId AS WORD _                          ' __in WORD wLanguageId
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS LONG                                              ' int

' Undocumented
DECLARE FUNCTION MessageBoxTimeoutW IMPORT "USER32.DLL" ALIAS "MessageBoxTimeoutW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpText AS WSTRINGZ _                           ' __in_opt LPCWSTR lpText
 , BYREF lpCaption AS WSTRINGZ _                        ' __in_opt LPCWSTR lpCaption
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL wLanguageId AS WORD _                          ' __in WORD wLanguageId
 , BYVAL dwMilliseconds AS DWORD _                      ' __in DWORD dwMilliseconds
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO MessageBoxTimeout = MessageBoxTimeoutW
#ELSE
   MACRO MessageBoxTimeout = MessageBoxTimeoutA
#ENDIF

'#if(WINVER >= 0x0400)

'typedef VOID (CALLBACK *MSGBOXCALLBACK)(LPHELPINFO lpHelpInfo);

' // Size = 40 bytes
TYPE MSGBOXPARAMSA DWORD
   cbSize             AS DWORD        ' UINT
   hWndOwner          AS DWORD        ' HWND
   hInstance          AS DWORD        ' HINSTANCE
   lpszText           AS ASCIIZ PTR   ' LPCSTR
   lpszCaption        AS ASCIIZ PTR   ' LPCSTR
   dwStyle            AS DWORD        ' DWORD
   lpszIcon           AS ASCIIZ PTR   ' LPCSTR
   dwContextHelpId    AS DWORD        ' DWORD_PTR
   lpfnMsgBoxCallback AS LONG         ' MSGBOXCALLBACK
   dwLanguageId       AS DWORD        ' DWORD
END TYPE

' // Size = 40 bytes
TYPE MSGBOXPARAMSW DWORD
   cbSize             AS DWORD          ' UINT
   hWndOwner          AS DWORD          ' HWND
   hInstance          AS DWORD          ' HINSTANCE
   lpszText           AS WSTRINGZ PTR   ' LPCWSTR
   lpszCaption        AS WSTRINGZ PTR   ' LPCWSTR
   dwStyle            AS DWORD          ' DWORD
   lpszIcon           AS WSTRINGZ PTR   ' LPCWSTR
   dwContextHelpId    AS DWORD          ' DWORD_PTR
   lpfnMsgBoxCallback AS LONG           ' MSGBOXCALLBACK
   dwLanguageId       AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
MACRO MSGBOXPARAMS = MSGBOXPARAMSW
#ELSE
MACRO MSGBOXPARAMS = MSGBOXPARAMSA
#ENDIF

DECLARE FUNCTION MessageBoxIndirectA IMPORT "USER32.DLL" ALIAS "MessageBoxIndirectA" ( _
   BYREF lpmbp AS MSGBOXPARAMSA _                       ' __in CONST MSGBOXPARAMSA * lpmbp
 ) AS LONG                                              ' int

DECLARE FUNCTION MessageBoxIndirectW IMPORT "USER32.DLL" ALIAS "MessageBoxIndirectW" ( _
   BYREF lpmbp AS MSGBOXPARAMSW _                       ' __in CONST MSGBOXPARAMSW * lpmbp
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO MessageBoxIndirect = MessageBoxIndirectW
#ELSE
   MACRO MessageBoxIndirect = MessageBoxIndirectA
#ENDIF

DECLARE FUNCTION MessageBeep IMPORT "USER32.DLL" ALIAS "MessageBeep" ( _
   BYVAL uType AS DWORD _                               ' __in UINT uType
 ) AS LONG                                              ' BOOL

'#endif /* !NOMB */
'#ENDIF   ' #IF NOT %DEF(%NOMB) ' ----------------------------------------------

DECLARE FUNCTION ShowCursor IMPORT "USER32.DLL" ALIAS "ShowCursor" ( _
   OPTIONAL BYVAL bShow AS LONG _                       ' __in BOOL bShow
 ) AS LONG                                              ' int

DECLARE FUNCTION SetCursorPos IMPORT "USER32.DLL" ALIAS "SetCursorPos" ( _
   BYVAL X As LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0600)
DECLARE FUNCTION SetPhysicalCursorPos IMPORT "USER32.DLL" ALIAS "SetPhysicalCursorPos" ( _
   BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION SetCursor IMPORT "USER32.DLL" ALIAS "SetCursor" ( _
   OPTIONAL BYVAL hCursor AS DWORD _                    ' __in_opt HCURSOR hCursor
 ) AS DWORD                                             ' HCURSOR

DECLARE FUNCTION GetCursorPos IMPORT "USER32.DLL" ALIAS "GetCursorPos" ( _
   BYREF lpPoint AS POINT _                             ' __out LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0600)
DECLARE FUNCTION GetPhysicalCursorPos IMPORT "USER32.DLL" ALIAS "GetPhysicalCursorPos" ( _
   BYREF lpPoint AS POINT _                             ' __out LPPOINT lpPoint
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION ClipCursor IMPORT "USER32.DLL" ALIAS "ClipCursor" ( _
   OPTIONAL BYREF lpRect AS RECT _                      ' __in_opt CONST RECT *lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetClipCursor IMPORT "USER32.DLL" ALIAS "GetClipCursor" ( _
   BYREF lpRect AS RECT _                               ' __out LPRECT lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCursor IMPORT "USER32.DLL" ALIAS "GetCursor" ( _
 ) AS DWORD                                             ' HCURSOR

DECLARE FUNCTION CreateCaret IMPORT "USER32.DLL" ALIAS "CreateCaret" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hBitmap AS DWORD _                             ' __in_opt HBITMAP hBitmap
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCaretBlinkTime IMPORT "USER32.DLL" ALIAS "GetCaretBlinkTime" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetCaretBlinkTime IMPORT "USER32.DLL" ALIAS "SetCaretBlinkTime" ( _
   BYVAL uMSeconds AS DWORD _                           ' __in UINT uMSeconds
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DestroyCaret IMPORT "USER32.DLL" ALIAS "DestroyCaret" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION HideCaret IMPORT "USER32.DLL" ALIAS "HideCaret" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShowCaret IMPORT "USER32.DLL" ALIAS "ShowCaret" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCaretPos IMPORT "USER32.DLL" ALIAS "SetCaretPos" ( _
   BYVAL X AS LONG  _                                   ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCaretPos IMPORT "USER32.DLL" ALIAS "GetCaretPos" ( _
   BYREF lpPoint AS POINT _                             ' __out LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ClientToScreen IMPORT "USER32.DLL" ALIAS "ClientToScreen" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPoint AS POINT _                             ' __inout LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScreenToClient IMPORT "USER32.DLL" ALIAS "ScreenToClient" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPoint AS POINT _                             ' __inout LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0600)
DECLARE FUNCTION LogicalToPhysicalPoint IMPORT "USER32.DLL" ALIAS "LogicalToPhysicalPoint" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPoint AS POINT _                             ' __inout LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PhysicalToLogicalPoint IMPORT "USER32.DLL" ALIAS "PhysicalToLogicalPoint" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpPoint AS POINT _                             ' __inout LPPOINT lpPoint
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0600 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MapWindowPoints LIB "User32.dll" ALIAS "MapWindowPoints" _
    (BYVAL hWndFrom AS DWORD, BYVAL hWndTo AS DWORD, BYVAL lppt AS POINT PTR, _
    BYVAL cPoints AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION MapWindowPoints IMPORT "USER32.DLL" ALIAS "MapWindowPoints" ( _
   BYVAL hWndFrom AS DWORD _                            ' __in_opt HWND hWndFrom
 , BYVAL hWndTo AS DWORD _                              ' __in_opt HWND hWndTo
 , BYREF lpPoints AS ANY _                              ' __in LPPOINT lpPoints
 , BYVAL cPoints AS DWORD _                             ' __in UINT cPoints
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION WindowFromPoint IMPORT "USER32.DLL" ALIAS "WindowFromPoint" ( _
   BYVAL Point AS POINT _                               ' __in POINT Point
 ) AS DWORD                                             ' HWND

' // Same as above, but using x, y coordinates
DECLARE FUNCTION WindowFromXY IMPORT "USER32.DLL" ALIAS "WindowFromPoint" ( _
   BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS DWORD                                             ' HWND

'#if(WINVER >= 0x0600)
DECLARE FUNCTION WindowFromPhysicalPoint IMPORT "USER32.DLL" ALIAS "WindowFromPhysicalPoint" ( _
   BYVAL Point AS POINT _                               ' __in POINT Point
 ) AS DWORD                                             ' HWND
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION ChildWindowFromPoint IMPORT "USER32.DLL" ALIAS "ChildWindowFromPoint" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL Point AS POINT _                               ' __in POINT Point
 ) AS DWORD                                             ' HWND

' Same as above, but using x, y coordinates
DECLARE FUNCTION ChildWindowFromXY IMPORT "USER32.DLL" ALIAS "ChildWindowFromPoint" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS DWORD                                             ' HWND

'#if(WINVER >= 0x0400)
%CWP_ALL             = &H0000???
%CWP_SKIPINVISIBLE   = &H0001???
%CWP_SKIPDISABLED    = &H0002???
%CWP_SKIPTRANSPARENT = &H0004???

DECLARE FUNCTION ChildWindowFromPointEx IMPORT "USER32.DLL" ALIAS "ChildWindowFromPointEx" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pt AS POINT _                                  ' __in POINT pt
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HWND

' Same as above, but using x, y coordinates
DECLARE FUNCTION ChildWindowFromXYEx IMPORT "USER32.DLL" ALIAS "ChildWindowFromPointEx" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HWND

'#endif /* WINVER >= 0x0400 */

'#IF NOT %DEF(%NOCOLOR) ' ------------------------------------------------------
'#ifndef NOCOLOR

'/*
' * Color Types
' */
%CTLCOLOR_MSGBOX               = 0&
%CTLCOLOR_EDIT                 = 1&
%CTLCOLOR_LISTBOX              = 2&
%CTLCOLOR_BTN                  = 3&
%CTLCOLOR_DLG                  = 4&
%CTLCOLOR_SCROLLBAR            = 5&
%CTLCOLOR_STATIC               = 6&
%CTLCOLOR_MAX                  = 7&

%COLOR_SCROLLBAR               = 0&
%COLOR_BACKGROUND              = 1&
%COLOR_ACTIVECAPTION           = 2&
%COLOR_INACTIVECAPTION         = 3&
%COLOR_MENU                    = 4&
%COLOR_MSGBOX                  = 4&
%COLOR_WINDOW                  = 5&
%COLOR_WINDOWFRAME             = 6&
%COLOR_MENUTEXT                = 7&
%COLOR_MSGBOXTEXT              = 7&
%COLOR_WINDOWTEXT              = 8&
%COLOR_CAPTIONTEXT             = 9&
%COLOR_ACTIVEBORDER            = 10&
%COLOR_INACTIVEBORDER          = 11&
%COLOR_APPWORKSPACE            = 12&
%COLOR_HIGHLIGHT               = 13&
%COLOR_HIGHLIGHTTEXT           = 14&
%COLOR_BTNFACE                 = 15&
%COLOR_BTNSHADOW               = 16&
%COLOR_GRAYTEXT                = 17&
%COLOR_BTNTEXT                 = 18&
%COLOR_INACTIVECAPTIONTEXT     = 19&
%COLOR_BTNHIGHLIGHT            = 20&

'#if(WINVER >= 0x0400)
%COLOR_3DDKSHADOW              = 21&
%COLOR_3DLIGHT                 = 22&
%COLOR_INFOTEXT                = 23&
%COLOR_INFOBK                  = 24&
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%COLOR_HOTLIGHT                = 26&
%COLOR_GRADIENTACTIVECAPTION   = 27&
%COLOR_GRADIENTINACTIVECAPTION = 28&
'#if(WINVER >= 0x0501)
%COLOR_MENUHILIGHT             = 29&
%COLOR_MENUBAR                 = 30&
'#endif /* WINVER >= 0x0501 */
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0400)
%COLOR_DESKTOP             = %COLOR_BACKGROUND
%COLOR_3DFACE              = %COLOR_BTNFACE
%COLOR_3DSHADOW            = %COLOR_BTNSHADOW
%COLOR_3DHIGHLIGHT         = %COLOR_BTNHIGHLIGHT
%COLOR_3DHILIGHT           = %COLOR_BTNHIGHLIGHT
%COLOR_BTNHILIGHT          = %COLOR_BTNHIGHLIGHT
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION GetSysColor IMPORT "USER32.DLL" ALIAS "GetSysColor" ( _
   BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0400)
DECLARE FUNCTION GetSysColorBrush IMPORT "USER32.DLL" ALIAS "GetSysColorBrush" ( _
   BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS DWORD                                             ' HBRUSH
'#endif /* WINVER >= 0x0400 */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSysColors LIB "User32.dll" ALIAS "SetSysColors" _
    (BYVAL nChanges AS LONG, BYVAL lpSysColor AS LONG PTR, _
    BYVAL lpColorValues AS DWORD PTR) AS LONG
#ELSE
DECLARE FUNCTION SetSysColors IMPORT "USER32.DLL" ALIAS "SetSysColors" ( _
   BYVAL cElements AS LONG _                            ' __in int cElements
 , BYREF lpaElements AS LONG _                          ' __in CONST INT * lpaElements
 , BYREF lpaRgbValues AS DWORD _                        ' __in CONST COLORREF * lpaRgbValues
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif /* !NOCOLOR */
'#ENDIF   ' #IF NOT %DEF(%NOCOLOR) ' -------------------------------------------

DECLARE FUNCTION DrawFocusRect IMPORT "USER32.DLL" ALIAS "DrawFocusRect" ( _
   BYVAL hDC AS DWORD  _                                ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in CONST RECT * lprc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FillRect IMPORT "USER32.DLL" ALIAS "FillRect" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 , BYVAL hbr AS DWORD _                                 ' __in HBRUSH hbr
 ) AS LONG                                              ' int

DECLARE FUNCTION FrameRect IMPORT "USER32.DLL" ALIAS "FrameRect" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 , BYVAL hbr AS DWORD _                                 ' __in HBRUSH hbr
 ) AS LONG                                              ' int

DECLARE FUNCTION InvertRect IMPORT "USER32.DLL" ALIAS "InvertRect" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetRect IMPORT "USER32.DLL" ALIAS "SetRect" ( _
   BYREF lprc AS RECT _                                 ' __out LPRECT lprc
 , BYVAL xLeft AS LONG _                                ' __in int xLeft
 , BYVAL yTop AS LONG _                                 ' __in int yTop
 , BYVAL xRight AS LONG _                               ' __in int xRight
 , BYVAL yBottom AS LONG _                              ' __in int yBottom
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetRectEmpty IMPORT "USER32.DLL" ALIAS "SetRectEmpty" ( _
   BYREF lprc AS RECT _                                 ' __out LPRECT lprc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CopyRect IMPORT "USER32.DLL" ALIAS "CopyRect" ( _
   BYREF lprcDst AS RECT _                              ' __out LPRECT lprcDst
 , BYREF lprcSrc AS RECT _                              ' __in CONST RECT *lprcSrc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InflateRect IMPORT "USER32.DLL" ALIAS "InflateRect" ( _
   BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IntersectRect IMPORT "USER32.DLL" ALIAS "IntersectRect" ( _
   BYREF lprcDst AS RECT _                              ' __out LPRECT lprcDst
 , BYREF lprcSrc1 AS RECT _                             ' __in CONST RECT *lprcSrc1
 , BYREF lprcSrc2 AS RECT _                             ' __in CONST RECT *lprcSrc2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnionRect IMPORT "USER32.DLL" ALIAS "UnionRect" ( _
   BYREF lprcDst AS RECT _                              ' __out LPRECT lprcDst
 , BYREF lprcSrc1 AS RECT _                             ' __in CONST RECT *lprcSrc1
 , BYREF lprcSrc2 AS RECT _                             ' __in CONST RECT *lprcSrc2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SubtractRect IMPORT "USER32.DLL" ALIAS "SubtractRect" ( _
   BYREF lprcDst AS RECT _                              ' __out LPRECT lprcDst
 , BYREF lprcSrc1 AS RECT _                             ' __in CONST RECT *lprcSrc1
 , BYREF lprcSrc2 AS RECT _                             ' __in CONST RECT *lprcSrc2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OffsetRect IMPORT "USER32.DLL" ALIAS "OffsetRect" ( _
   BYREF lprc AS RECT _                                 ' __inout LPRECT lprc
 , BYVAL dx AS LONG _                                   '__in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsRectEmpty IMPORT "USER32.DLL" ALIAS "IsRectEmpty" ( _
   BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EqualRect IMPORT "USER32.DLL" ALIAS "EqualRect" ( _
   BYREF lprc1 AS RECT _                                ' __in CONST RECT *lprc1
 , BYREF lprc2 AS RECT _                                ' __in CONST RECT *lprc2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PtInRect IMPORT "USER32.DLL" ALIAS "PtInRect" ( _
   BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 , BYVAL pt AS POINT _                                  ' __in POINT pt
 ) AS LONG                                              ' BOOL

' Same as above, but using x, y coordinates
DECLARE FUNCTION PtInRectXY IMPORT "USER32.DLL" ALIAS "PtInRect" ( _
   BYREF lprc AS RECT _                                 ' __in CONST RECT *lprc
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS LONG                                              ' BOOL


'#IF NOT %DEF(%NOWINOFFSETS) ' -------------------------------------------------
'#ifndef NOWINOFFSETS

DECLARE FUNCTION GetWindowWord IMPORT "USER32.DLL" ALIAS "GetWindowWord" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS WORD                                              ' WORD

DECLARE FUNCTION SetWindowWord IMPORT "USER32.DLL" ALIAS "SetWindowWord" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL wNewWord AS WORD _                             ' __in WORD wNewWord
 ) AS WORD                                              ' WORD

DECLARE FUNCTION GetWindowLongA IMPORT "USER32.DLL" ALIAS "GetWindowLongA" ( _
   BYVAL hWnd AS DWORD  _                               ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS LONG                                              ' long

DECLARE FUNCTION GetWindowLongW IMPORT "USER32.DLL" ALIAS "GetWindowLongW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO GetWindowLong = GetWindowLongW
#ELSE
   MACRO GetWindowLong = GetWindowLongA
#ENDIF

DECLARE FUNCTION SetWindowLongA IMPORT "USER32.DLL" ALIAS "SetWindowLongA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL dwNewLong AS LONG _                            ' __in LONG dwNewLong
 ) AS LONG                                              ' long

DECLARE FUNCTION SetWindowLongW IMPORT "USER32.DLL" ALIAS "SetWindowLongW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL dwNewLong AS LONG _                            ' __in LONG dwNewLong
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO SetWindowLong = SetWindowLongW
#ELSE
   MACRO SetWindowLong = SetWindowLongA
#ENDIF

'#ifdef _WIN64

'DECLARE FUNCTION GetWindowLongPtrA IMPORT "USER32.DLL" ALIAS "GetWindowLongPtrA" ( _
'   BYVAL hWnd AS QUAD _                                 ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' ) AS QUAD                                              ' LONG_PTR

'DECLARE FUNCTION GetWindowLongPtrW IMPORT "USER32.DLL" ALIAS "GetWindowLongPtrW" ( _
'   BYVAL hWnd AS QUAD _                                 ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' ) AS QUAD                                              ' LONG_PTR

'#IF %DEF(%UNICODE)
'   MACRO GetWindowLongPtr = GetWindowLongPtrW
'#ELSE
'   MACRO GetWindowLongPtr = GetWindowLongPtrA
'#ENDIF

'DECLARE FUNCTION SetWindowLongPtrA IMPORT "USER32.DLL" ALIAS "SetWindowLongPtrA" ( _
'   BYVAL hWnd AS QUAD _                                 ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' , BYVAL dwNewLong AS QUAD _                            ' __in LONG_PTR dwNewLong
' ) AS QUAD                                              ' LONG_PTR

'DECLARE FUNCTION SetWindowLongPtrW IMPORT "USER32.DLL" ALIAS "SetWindowLongPtrW" ( _
'   BYVAL hWnd AS QUAD _                                 ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' , BYVAL dwNewLong AS QUAD _                            ' __in LONG_PTR dwNewLong
' ) AS QUAD                                              ' LONG_PTR

'#IF %DEF(%UNICODE)
'   MACRO SetWindowLongPtr = SetWindowLongPtrW
'#ELSE
'   MACRO SetWindowLongPtr = SetWindowLongPtrA
'#ENDIF

'#endif /* _WIN64 */

DECLARE FUNCTION GetClassWord IMPORT "USER32.DLL" ALIAS "GetClassWord" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS WORD                                              ' WORD

DECLARE FUNCTION SetClassWord IMPORT "USER32.DLL" ALIAS "SetClassWord" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL wNewWord AS WORD _                             ' __in WORD wNewWord
 ) AS WORD                                              ' WORD

DECLARE FUNCTION GetClassLongA IMPORT "USER32.DLL" ALIAS "GetClassLongA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetClassLongW IMPORT "USER32.DLL" ALIAS "GetClassLongW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetClassLong = GetClassLongW
#ELSE
   MACRO GetClassLong = GetClassLongA
#ENDIF

DECLARE FUNCTION SetClassLongA IMPORT "USER32.DLL" ALIAS "SetClassLongA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL dwNewLong AS DWORD _                           ' __in LONG dwNewLong
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetClassLongW IMPORT "USER32.DLL" ALIAS "SetClassLongW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nIndex AS LONG _                               ' __in int nIndex
 , BYVAL dwNewLong AS DWORD _                           ' __in LONG dwNewLong
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO SetClassLong = SetClassLongW
#ELSE
   MACRO SetClassLong = SetClassLongA
#ENDIF

'#ifdef _WIN64

'DECLARE FUNCTION GetClassLongPtrA IMPORT "USER32.DLL" ALIAS "GetClassLongPtrA" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' ) AS DWORD                                             ' ULONG_PTR

'DECLARE FUNCTION GetClassLongPtrW IMPORT "USER32.DLL" ALIAS "GetClassLongPtrW" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' ) AS DWORD                                             ' ULONG_PTR

'#IF %DEF(%UNICODE)
'   MACRO GetClassLongPtr = GetClassLongPtrW
'#ELSE
'   MACRO GetClassLongPtr = GetClassLongPtrA
'#ENDIF

'DECLARE FUNCTION SetClassLongPtrA IMPORT "USER32.DLL" ALIAS "SetClassLongPtrA" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' , BYVAL dwNewLong AS LONG _                            ' __in LONG_PTR dwNewLong
' ) AS DWORD                                             ' ULONG_PTR

'DECLARE FUNCTION SetClassLongPtrW IMPORT "USER32.DLL" ALIAS "SetClassLongPtrW" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL nIndex AS LONG _                               ' __in int nIndex
' , BYVAL dwNewLong AS LONG _                            ' __in LONG_PTR dwNewLong
' ) AS DWORD                                             ' ULONG_PTR

'#IF %DEF(%UNICODE)
'   MACRO SetClassLongPtr = SetClassLongPtrW
'#ELSE
'   MACRO SetClassLongPtr = SetClassLongPtrA
'#ENDIF

'#endif /* _WIN64 */

'#endif /* !NOWINOFFSETS */
'#ENDIF   ' #IF NOT %DEF(%NOWINOFFSETS) ' --------------------------------------

'#if(WINVER >= 0x0500)

DECLARE FUNCTION GetProcessDefaultLayout IMPORT "USER32.DLL" ALIAS "GetProcessDefaultLayout" ( _
   BYREF pdwDefaultLayout AS DWORD _                    ' __out DWORD *pdwDefaultLayout
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetProcessDefaultLayout IMPORT "USER32.DLL" ALIAS "SetProcessDefaultLayout" ( _
   BYVAL dwDefaultLayout AS DWORD _                     ' __in DWORD dwDefaultLayout
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION GetDesktopWindow IMPORT "USER32.DLL" ALIAS "GetDesktopWindow" ( _
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetParent IMPORT "USER32.DLL" ALIAS "GetParent" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION SetParent IMPORT "USER32.DLL" ALIAS "SetParent" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWndChild
 , OPTIONAL BYVAL hWndNewParent AS DWORD _              ' __in_opt HWND hWndNewParent
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION EnumChildWindows IMPORT "USER32.DLL" ALIAS "EnumChildWindows" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL lpEnumFunc AS DWORD _                          ' __in WNDENUMPROC lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindWindowA IMPORT "USER32.DLL" ALIAS "FindWindowA" ( _
   OPTIONAL BYREF lpClassName AS ASCIIZ _               ' __in_opt LPCSTR lpClassName
 , OPTIONAL BYREF lpWindowName AS ASCIIZ _              ' __in_opt LPCSTR lpWindowName
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION FindWindowW IMPORT "USER32.DLL" ALIAS "FindWindowW" ( _
   OPTIONAL BYREF lpClassName AS WSTRINGZ _             ' __in_opt LPCWSTR lpClassName
 , OPTIONAL BYREF lpWindowName AS WSTRINGZ _            ' __in_opt LPCWSTR lpWindowName
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO FindWindow = FindWindowW
#ELSE
   MACRO FindWindow = FindWindowA
#ENDIF

'#if(WINVER >= 0x0400)

DECLARE FUNCTION FindWindowExA IMPORT "USER32.DLL" ALIAS "FindWindowExA" ( _
   OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL hWndChildAfter AS DWORD _             ' __in_opt HWND hWndChildAfter
 , OPTIONAL BYREF lpszClass AS ASCIIZ _                 ' __in_opt LPCSTR lpszClass
 , OPTIONAL BYREF lpszWindow AS ASCIIZ _                ' __in_opt LPCSTR lpszWindow
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION FindWindowExW IMPORT "USER32.DLL" ALIAS "FindWindowExW" ( _
   OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYVAL hWndChildAfter AS DWORD _             ' __in_opt HWND hWndChildAfter
 , OPTIONAL BYREF lpszClass AS WSTRINGZ _               ' __in_opt LPCWSTR lpszClass
 , OPTIONAL BYREF lpszWindow AS WSTRINGZ _              ' __in_opt LPCWSTR lpszWindow
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO FindWindowEx = FindWindowExW
#ELSE
   MACRO FindWindowEx = FindWindowExA
#ENDIF

DECLARE FUNCTION GetShellWindow IMPORT "user32.dll" ALIAS "GetShellWindow" ( _
 ) AS DWORD                                             ' HWND

'#endif /* WINVER >= 0x0400 */


DECLARE FUNCTION RegisterShellHookWindow IMPORT "user32.dll" ALIAS "RegisterShellHookWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeregisterShellHookWindow IMPORT "user32.dll" ALIAS "DeregisterShellHookWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumWindows IMPORT "USER32.DLL" ALIAS "EnumWindows" ( _
   BYVAL lpEnumFunc AS DWORD _                          ' __in WNDENUMPROC lpEnumFunc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumThreadWindows IMPORT "USER32.DLL" ALIAS "EnumThreadWindows" ( _
   BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 , BYVAL lpfn AS DWORD _                                ' __in WNDENUMPROC lpfn
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

'#define EnumTaskWindows(hTask, lpfn, lParam) EnumThreadWindows(HandleToUlong(hTask), lpfn, lParam)
'MACRO EnumTaskWindows(hTask, lpfn, lParam) = EnumThreadWindows(hTask, lpfn, lParam)
MACRO EnumTaskWindows = EnumThreadWindows

DECLARE FUNCTION GetClassNameA IMPORT "USER32.DLL" ALIAS "GetClassNameA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpClassName AS ASCIIZ _                        ' __out LPSTR lpClassName
 , BYVAL nMaxCount AS LONG _                            ' __in int nMaxCount
 ) AS LONG                                              ' int

DECLARE FUNCTION GetClassNameW IMPORT "USER32.DLL" ALIAS "GetClassNameW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lpClassName AS WSTRINGZ _                      ' __out LPWSTR lpClassName
 , BYVAL nMaxCount AS LONG _                            ' __in int nMaxCount
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetClassName = GetClassNameW
#ELSE
   MACRO GetClassName = GetClassNameA
#ENDIF

DECLARE FUNCTION GetTopWindow IMPORT "USER32.DLL" ALIAS "GetTopWindow" ( _
   OPTIONAL BYVAL hWnd AS DWORD _                       ' __in_opt HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION GetWindowThreadProcessId IMPORT "USER32.DLL" ALIAS "GetWindowThreadProcessId" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , OPTIONAL BYREF lpdwProcessId AS DWORD _              ' __out_opt LPDWORD lpdwProcessId
 ) AS DWORD                                             ' DWORD

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION IsGUIThread IMPORT "USER32.DLL" ALIAS "IsGUIThread" ( _
   BYVAL bConvert AS LONG _                             ' __in BOOL bConvert
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0501 */

'#define GetWindowTask(hWnd) \
'        ((HANDLE)(DWORD_PTR)GetWindowThreadProcessId(hWnd, NULL))

'MACRO GetWindowTask(hWnd) = GetWindowThreadProcessId(hWnd, BYVAL %NULL)
FUNCTION GetWindowTask (BYVAL hWnd AS DWORD) AS DWORD                                             ' DWORD
   FUNCTION = GetWindowThreadProcessId(hWnd, BYVAL %NULL)
END FUNCTION

DECLARE FUNCTION GetLastActivePopup IMPORT "USER32.DLL" ALIAS "GetLastActivePopup" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HWND

'/*
' * GetWindow() Constants
' */
%GW_HWNDFIRST    = 0???
%GW_HWNDLAST     = 1???
%GW_HWNDNEXT     = 2???
%GW_HWNDPREV     = 3???
%GW_OWNER        = 4???
%GW_CHILD        = 5???
'#if(WINVER <= 0x0400)
'%GW_MAX          = 5???
'#else
%GW_ENABLEDPOPUP = 6???
%GW_MAX          = 6???
'#endif

DECLARE FUNCTION GetWindow IMPORT "USER32.DLL" ALIAS "GetWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL uCmd AS DWORD _                                ' __in UINT uCmd
 ) AS DWORD                                             ' HWND

'#define GetNextWindow(hWnd, wCmd) GetWindow(hWnd, wCmd)
'#define GetSysModalWindow() (NULL)
'#define SetSysModalWindow(hWnd) (NULL)

FUNCTION GetNextWindow (BYVAL hWnd AS DWORD, BYVAL wCmd AS DWORD) AS DWORD
   FUNCTION = GetWindow(hWnd, wCmd)
END FUNCTION

'#IF NOT %DEF(%NOWH) ' ---------------------------------------------------------
'#ifndef NOWH

DECLARE FUNCTION SetWindowsHookA IMPORT "USER32.DLL" ALIAS "SetWindowsHookA" ( _
   BYVAL nFilterType AS LONG _                          ' __in int nFilterType
 , BYVAL pfnFilterProc AS DWORD _                       ' __in HOOKPROC pfnFilterProc
 ) AS DWORD                                             ' HHOOK

DECLARE FUNCTION SetWindowsHookW IMPORT "USER32.DLL" ALIAS "SetWindowsHookW" ( _
   BYVAL nFilterType AS LONG _                          ' __in int nFilterType
 , BYVAL pfnFilterProc AS DWORD _                       ' __in HOOKPROC pfnFilterProc
 ) AS DWORD                                             ' HHOOK

#IF %DEF(%UNICODE)
   MACRO SetWindowsHook = SetWindowsHookW
#ELSE
   MACRO SetWindowsHook = SetWindowsHookA
#ENDIF

DECLARE FUNCTION UnhookWindowsHook IMPORT "USER32.DLL" ALIAS "UnhookWindowsHook" ( _
   BYVAL nCode AS LONG _                                ' __in int nCode
 , BYVAL pfnFilterProc AS DWORD _                       ' __in HOOKPROC pfnFilterProc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowsHookExA IMPORT "USER32.DLL" ALIAS "SetWindowsHookExA" ( _
   BYVAL idHook AS LONG _                               ' __in int idHook
 , BYVAL lpfn AS DWORD _                                ' __in HOOKPROC lpfn
 , BYVAL hmod AS DWORD _                                ' __in_opt HINSTANCE hmod
 , BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 ) AS DWORD                                             ' HHOOK

DECLARE FUNCTION SetWindowsHookExW IMPORT "USER32.DLL" ALIAS "SetWindowsHookExW" ( _
   BYVAL idHook AS LONG _                               ' __in int idHook
 , BYVAL lpfn AS DWORD _                                ' __in HOOKPROC lpfn
 , BYVAL hmod AS DWORD _                                ' __in_opt HINSTANCE hmod
 , BYVAL dwThreadId AS DWORD _                          ' __in DWORD dwThreadId
 ) AS DWORD                                             ' HHOOK

#IF %DEF(%UNICODE)
   MACRO SetWindowsHookEx = SetWindowsHookExW
#ELSE
   MACRO SetWindowsHookEx = SetWindowsHookExA
#ENDIF

DECLARE FUNCTION UnhookWindowsHookEx IMPORT "USER32.DLL" ALIAS "UnhookWindowsHookEx" ( _
   BYVAL hhk AS DWORD _                                 ' __in HHOOK hhk
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CallNextHookEx IMPORT "USER32.DLL" ALIAS "CallNextHookEx" ( _
   BYVAL hhk AS DWORD _                                 ' __in_opt HHOOK hhk
 , BYVAL nCode AS LONG _                                ' __in int nCode
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS DWORD _                              ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

'/*
' * Macros for source-level compatibility with old functions.
' */
'#define DefHookProc(nCode, wParam, lParam, phhk)\
'        CallNextHookEx((HHOOK)*phhk, nCode, wParam, lParam)
'MACRO DefHookProc(nCode, wParam, lParam, phhk) = CallNextHookEx(phhk, nCode, wParam, lParam)
FUNCTION DefHookProc ( _
   BYVAL nCode AS LONG _                                ' __in int nCode
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS DWORD, _                             ' __in LPARAM lParam
   OPTIONAL BYVAL hhk AS DWORD _                        ' __in_opt HHOOK hhk
 ) AS LONG                                              ' LRESULT
   FUNCTION = CallNextHookEx(hhk, nCode, wParam, lParam)
END FUNCTION
'#endif /* !NOWH */
'#ENDIF   ' #IF NOT %DEF(%NOWH) ' ----------------------------------------------

'#IF NOT %DEF(%NOMENUS) ' ------------------------------------------------------
'#ifndef NOMENUS


'/* ;win40  -- A lot of MF_* flags have been renamed as MFT_* and MFS_* flags */
'/*
' * Menu flags for Add/Check/EnableMenuItem()
' */
%MF_INSERT          = &H00000000???
%MF_CHANGE          = &H00000080???
%MF_APPEND          = &H00000100???
%MF_DELETE          = &H00000200???
%MF_REMOVE          = &H00001000???

%MF_BYCOMMAND       = &H00000000???
%MF_BYPOSITION      = &H00000400???

%MF_SEPARATOR       = &H00000800???

'%MF_ENABLED         = &H00000000???
'%MF_GRAYED          = &H00000001???
'%MF_DISABLED        = &H00000002???

'%MF_UNCHECKED       = &H00000000???
'%MF_CHECKED         = &H00000008???
%MF_USECHECKBITMAPS = &H00000200???

%MF_STRING          = &H00000000???
%MF_BITMAP          = &H00000004???
%MF_OWNERDRAW       = &H00000100???

%MF_POPUP           = &H00000010???
%MF_MENUBARBREAK    = &H00000020???
%MF_MENUBREAK       = &H00000040???

'%MF_UNHILITE        = &H00000000???
'%MF_HILITE          = &H00000080???

'#if(WINVER >= 0x0400)
%MF_DEFAULT         = &H00001000???
'#endif /* WINVER >= 0x0400 */
%MF_SYSMENU         = &H00002000???
%MF_HELP            = &H00004000???
'#if(WINVER >= 0x0400)
%MF_RIGHTJUSTIFY    = &H00004000???
'#endif /* WINVER >= 0x0400 */

%MF_MOUSESELECT     = &H00008000???
'#if(WINVER >= 0x0400)
'%MF_END             = &H00000080???  ' /* Obsolete -- only used by old RES files */
'#endif /* WINVER >= 0x0400 */


'#if(WINVER >= 0x0400)
%MFT_STRING         = %MF_STRING
%MFT_BITMAP         = %MF_BITMAP
%MFT_MENUBARBREAK   = %MF_MENUBARBREAK
%MFT_MENUBREAK      = %MF_MENUBREAK
%MFT_OWNERDRAW      = %MF_OWNERDRAW
%MFT_RADIOCHECK     = &H00000200???
%MFT_SEPARATOR      = %MF_SEPARATOR
%MFT_RIGHTORDER     = &H00002000???
%MFT_RIGHTJUSTIFY   = %MF_RIGHTJUSTIFY

'/* Menu flags for Add/Check/EnableMenuItem() */
'%MFS_GRAYED    = &H00000003???
'%MFS_DISABLED  = %MFS_GRAYED
'%MFS_CHECKED   = %MF_CHECKED
'%MFS_HILITE    = %MF_HILITE
'%MFS_ENABLED   = %MF_ENABLED
'%MFS_UNCHECKED = %MF_UNCHECKED
'%MFS_UNHILITE  = %MF_UNHILITE
'%MFS_DEFAULT   = %MF_DEFAULT
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)

DECLARE FUNCTION CheckMenuRadioItem IMPORT "USER32.DLL" ALIAS "CheckMenuRadioItem" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL first AS DWORD _                               ' __in UINT first
 , BYVAL last AS DWORD _                                ' __in UINT last
 , BYVAL check AS DWORD _                               ' __in UINT check
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */

'/*
' * Menu item resource format
' */

' // Size = 4 bytes
TYPE MENUITEMTEMPLATEHEADER WORD
   versionNumber AS WORD   ' WORD
   offset        AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE MENUITEMTEMPLATE WORD
   mtOption AS WORD           ' WORD
   mtID     AS WORD           ' WORD
   mtString AS WSTRINGZ * 1   ' WCHAR mtString[1]
END TYPE

%MF_END = &H00000080???

'#endif /* !NOMENUS */
'#ENDIF   ' #IF NOT %DEF(%NOMENUS) ' -------------------------------------------

'#IF NOT %DEF(%NOSYSCOMMANDS) ' ------------------------------------------------
'#ifndef NOSYSCOMMANDS

' // Note: The remed equates are predefined in the compiler.

'/*
' * System Menu Command Values
' */
'%SC_SIZE         = &HF000???
'%SC_MOVE         = &HF010???
'%SC_MINIMIZE     = &HF020???
'%SC_MAXIMIZE     = &HF030???
'%SC_NEXTWINDOW   = &HF040???
'%SC_PREVWINDOW   = &HF050???
'%SC_CLOSE        = &HF060???
'%SC_VSCROLL      = &HF070???
'%SC_HSCROLL      = &HF080???
'%SC_MOUSEMENU    = &HF090???
'%SC_KEYMENU      = &HF100???
'%SC_ARRANGE      = &HF110???
'%SC_RESTORE      = &HF120???
'%SC_TASKLIST     = &HF130???
'%SC_SCREENSAVE   = &HF140???
'%SC_HOTKEY       = &HF150???
'#if(WINVER >= 0x0400)
'%SC_DEFAULT      = &HF160???
'%SC_MONITORPOWER = &HF170???
'%SC_CONTEXTHELP  = &HF180???
%SC_SEPARATOR    = &HF00F???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0600)
%SCF_ISSECURE    = &H00000001???
'#endif /* WINVER >= 0x0600 */

'#define GET_SC_WPARAM(wParam) ((int)wParam & 0xFFF0)
MACRO GET_SC_WPARAM(wParam) = BITS(LONG, wParam AND &HFFF0)

'/*
' * Obsolete names
' */
%SC_ICON        = %SC_MINIMIZE
%SC_ZOOM        = %SC_MAXIMIZE

'#endif /* !NOSYSCOMMANDS */
'#ENDIF   ' #IF NOT %DEF(%NOSYSCOMMANDS) ' -------------------------------------

'/*
' * Resource Loading Routines
' */

DECLARE FUNCTION LoadBitmapA IMPORT "USER32.DLL" ALIAS "LoadBitmapA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpBitmapName AS ASCIIZ _                       ' __in LPCSTR lpBitmapName
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION LoadBitmapW IMPORT "USER32.DLL" ALIAS "LoadBitmapW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpBitmapName AS WSTRINGZ _                     ' __in LPCWSTR lpBitmapName
 ) AS DWORD                                             ' HBITMAP

#IF %DEF(%UNICODE)
   MACRO LoadBitmap = LoadBitmapW
#ELSE
   MACRO LoadBitmap = LoadBitmapA
#ENDIF

DECLARE FUNCTION LoadCursorA IMPORT "USER32.DLL" ALIAS "LoadCursorA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpCursorName AS ASCIIZ _                       ' __in LPCSTR lpCursorName
 ) AS DWORD                                             ' HCURSOR

DECLARE FUNCTION LoadCursorW IMPORT "USER32.DLL" ALIAS "LoadCursorW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpCursorName AS WSTRINGZ _                     ' __in LPCWSTR lpCursorName
 ) AS DWORD                                             ' HCURSOR

#IF %DEF(%UNICODE)
   MACRO LoadCursor = LoadCursorW
#ELSE
   MACRO LoadCursor = LoadCursorA
#ENDIF

DECLARE FUNCTION LoadCursorFromFileA IMPORT "USER32.DLL" ALIAS "LoadCursorFromFileA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS DWORD                                             ' HCURSOR

DECLARE FUNCTION LoadCursorFromFileW IMPORT "USER32.DLL" ALIAS "LoadCursorFromFileW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS DWORD                                             ' HCURSOR

#IF %DEF(%UNICODE)
   MACRO LoadCursorFromFile = LoadCursorFromFileW
#ELSE
   MACRO LoadCursorFromFile = LoadCursorFromFileA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateCursor LIB "User32.dll" ALIAS "CreateCursor" _
    (BYVAL hInstance AS DWORD, BYVAL nXhotspot AS LONG, _
    BYVAL nYhotspot AS LONG, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL lpANDbitPlane AS BYTE PTR, BYVAL lpXORbitPlane AS BYTE PTR) AS DWORD
#ELSE
DECLARE FUNCTION CreateCursor IMPORT "USER32.DLL" ALIAS "CreateCursor" ( _
   BYVAL hInst AS DWORD _                               ' __in_opt HINSTANCE hInst
 , BYVAL xHotSpot AS LONG _                             ' __in int xHotSpot
 , BYVAL yHotSpot AS LONG _                             ' __in int yHotSpot
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYREF pvANDPlane AS ANY _                            ' __in CONST VOID *pvANDPlane
 , BYREF pvXORPlane AS ANY _                            ' __in CONST VOID *pvXORPlane
 ) AS DWORD                                             ' HCURSOR
#ENDIF

DECLARE FUNCTION DestroyCursor IMPORT "USER32.DLL" ALIAS "DestroyCursor" ( _
   BYVAL hCursor AS DWORD _                             ' __in HCURSOR hCursor
 ) AS LONG                                              ' BOOL

' // Note: CopyCursor is implemented as a call to the CopyIcon function.
DECLARE FUNCTION CopyCursor IMPORT "USER32.DLL" ALIAS "CopyIcon" ( _
   BYVAL hCursor AS DWORD _                             ' __in HCURSOR hCursor
 ) AS DWORD                                             ' HCURSOR

'#endif

'/*
' * Standard Cursor IDs
' */
'#define IDC_ARROW           MAKEINTRESOURCE(32512)
'#define IDC_IBEAM           MAKEINTRESOURCE(32513)
'#define IDC_WAIT            MAKEINTRESOURCE(32514)
'#define IDC_CROSS           MAKEINTRESOURCE(32515)
'#define IDC_UPARROW         MAKEINTRESOURCE(32516)
'#define IDC_SIZE            MAKEINTRESOURCE(32640)  /* OBSOLETE: use IDC_SIZEALL */
'#define IDC_ICON            MAKEINTRESOURCE(32641)  /* OBSOLETE: use IDC_ARROW */
'#define IDC_SIZENWSE        MAKEINTRESOURCE(32642)
'#define IDC_SIZENESW        MAKEINTRESOURCE(32643)
'#define IDC_SIZEWE          MAKEINTRESOURCE(32644)
'#define IDC_SIZENS          MAKEINTRESOURCE(32645)
'#define IDC_SIZEALL         MAKEINTRESOURCE(32646)
'#define IDC_NO              MAKEINTRESOURCE(32648) /*not in win3.1 */
'#if(WINVER >= 0x0500)
'#define IDC_HAND            MAKEINTRESOURCE(32649)
'#endif /* WINVER >= 0x0500 */
'#define IDC_APPSTARTING     MAKEINTRESOURCE(32650) /*not in win3.1 */
'#if(WINVER >= 0x0400)
'#define IDC_HELP            MAKEINTRESOURCE(32651)
'#endif /* WINVER >= 0x0400 */

%IDC_ARROW        = 32512???
%IDC_IBEAM        = 32513???
%IDC_WAIT         = 32514???
%IDC_CROSS        = 32515???
%IDC_UPARROW      = 32516???
%IDC_SIZE         = 32640???
%IDC_ICON         = 32641???
%IDC_SIZENWSE     = 32642???
%IDC_SIZENESW     = 32643???
%IDC_SIZEWE       = 32644???
%IDC_SIZENS       = 32645???
%IDC_SIZEALL      = 32646???
%IDC_NO           = 32648???
'#if(WINVER >= 0x0500)
%IDC_HAND         = 32649???
'#endif /* WINVER >= 0x0500 */
%IDC_APPSTARTING  = 32650???
'#if(WINVER >= 0x0400)
%IDC_HELP         = 32651???
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION SetSystemCursor IMPORT "USER32.DLL" ALIAS "SetSystemCursor" ( _
   BYVAL hcur AS DWORD _                                ' __in HCURSOR hcur
 , BYVAL id AS LONG _                                   ' __in DWORD id
 ) AS LONG                                              ' BOOL

' // Size = 20 bytes
TYPE ICONINFO DWORD
   fIcon    AS LONG    ' BOOL
   xHotspot AS DWORD   ' DWORD
   yHotspot AS DWORD   ' DWORD
   hbmMask  AS DWORD   ' HBITMAP
   hbmColor AS DWORD   ' HBITMAP
END TYPE

DECLARE FUNCTION LoadIconA IMPORT "USER32.DLL" ALIAS "LoadIconA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpIconName AS ASCIIZ _                         ' __in LPCSTR lpIconName
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION LoadIconW IMPORT "USER32.DLL" ALIAS "LoadIconW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF lpIconName AS WSTRINGZ _                       ' __in LPCWSTR lpIconName
 ) AS DWORD                                             ' HICON

#IF %DEF(%UNICODE)
   MACRO LoadIcon = LoadIconW
#ELSE
   MACRO LoadIcon = LoadIconA
#ENDIF

DECLARE FUNCTION PrivateExtractIconsA IMPORT "USER32.DLL" ALIAS "PrivateExtractIconsA" ( _
   BYREF szFileName AS ASCIIZ _                         ' __in LPCSTR szFileName
 , BYVAL nIconIndex AS LONG _                           ' __in int nIconIndex
 , BYVAL cxIcon AS LONG _                               ' __in int cxIcon
 , BYVAL cyIcon AS LONG _                               ' __in int cyIcon
 , BYREF phicon AS DWORD _                              ' __out HICON *phicon
 , BYREF piconid AS DWORD _                             ' __out UINT *piconid
 , BYVAL nIcons AS DWORD _                              ' __in UINT nIcons
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION PrivateExtractIconsW IMPORT "USER32.DLL" ALIAS "PrivateExtractIconsW" ( _
   BYREF szFileName AS WSTRINGZ  _                         ' __in LPCWSTR szFileName
 , BYVAL nIconIndex AS LONG _                           ' __in int nIconIndex
 , BYVAL cxIcon AS LONG _                               ' __in int cxIcon
 , BYVAL cyIcon AS LONG _                               ' __in int cyIcon
 , BYREF phicon AS DWORD _                              ' __out HICON *phicon
 , BYREF piconid AS DWORD _                             ' __out UINT *piconid
 , BYVAL nIcons AS DWORD _                              ' __in UINT nIcons
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO PrivateExtractIcons = PrivateExtractIconsW
#ELSE
   MACRO PrivateExtractIcons = PrivateExtractIconsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreateIcon LIB "User32.dll" ALIAS "CreateIcon" _
    (BYVAL hInstance AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
    BYVAL nPlanes AS BYTE, BYVAL nBitsPixel AS BYTE, _
    BYVAL lpANDbits AS BYTE PTR, BYVAL lpXORbits AS BYTE PTR) AS DWORD
#ELSE
DECLARE FUNCTION CreateIcon IMPORT "USER32.DLL" ALIAS "CreateIcon" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL cPlanes AS BYTE _                              ' __in BYTE cPlanes
 , BYVAL cBitsPixel AS BYTE _                           ' __in BYTE cBitsPixel
 , BYREF lpbANDbits AS BYTE _                           ' __in CONST BYTE *lpbANDbits
 , BYREF lpbXORbits AS BYTE _                           ' __in CONST BYTE *lpbXORbits
 ) AS DWORD                                             ' HICON
#ENDIF

DECLARE FUNCTION DestroyIcon IMPORT "USER32.DLL" ALIAS "DestroyIcon" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LookupIconIdFromDirectory IMPORT "USER32.DLL" ALIAS "LookupIconIdFromDirectory" ( _
   BYVAL presbits AS BYTE PTR _                         ' __in PBYTE presbits
 , BYVAL fIcon AS LONG _                                ' __in BOOL fIcon
 ) AS LONG                                              ' int

'#if(WINVER >= 0x0400)
DECLARE FUNCTION LookupIconIdFromDirectoryEx IMPORT "USER32.DLL" ALIAS "LookupIconIdFromDirectoryEx" ( _
   BYVAL presbits AS BYTE PTR _                         ' __in PBYTE presbits
 , BYVAL fIcon AS LONG _                                ' __in BOOL fIcon
 , BYVAL cxDesired AS LONG _                            ' __in int cxDesired
 , BYVAL cyDesired AS LONG _                            ' __in int cyDesired
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS LONG                                              ' int
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION CreateIconFromResource IMPORT "USER32.DLL" ALIAS "CreateIconFromResource" ( _
   BYVAL presbits AS BYTE PTR _                         ' __in PBYTE presbits
 , BYVAL dwResSize AS DWORD _                           ' __in DWORD dwResSize
 , BYVAL fIcon AS LONG _                                ' __in BOOL fIcon
 , BYVAL dwVer AS DWORD _                               ' __in DWORD dwVer
 ) AS DWORD                                             ' HICON

'#if(WINVER >= 0x0400)

DECLARE FUNCTION CreateIconFromResourceEx IMPORT "USER32.DLL" ALIAS "CreateIconFromResourceEx" ( _
   BYVAL presbits AS BYTE PTR _                         ' __in PBYTE presbits
 , BYVAL dwResSize AS DWORD _                           ' __in DWORD dwResSize
 , BYVAL fIcon AS LONG _                                ' __in BOOL fIcon
 , BYVAL dwVer AS DWORD _                               ' __in DWORD dwVer
 , BYVAL cxDesired AS LONG _                            ' __in int cxDesired
 , BYVAL cyDesired AS LONG _                            ' __in int cyDesired
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HICON

'/* Icon/Cursor header */
'#endif /* WINVER >= 0x0400 */

' // Size = 24 bytes
TYPE CURSORSHAPE BYTE
   xHotSpot    AS LONG   ' int
   yHotSpot    AS LONG   ' int
   cx          AS LONG   ' int
   cy          AS LONG   ' int
   cbWidth     AS LONG   ' int
   Planes      AS BYTE   ' BYTE
   BitsPixel   AS BYTE   ' BYTE
   alignment__ AS WORD   ' // To keep DWORD alignment
END TYPE

%IMAGE_BITMAP      = 0???
%IMAGE_ICON        = 1???
%IMAGE_CURSOR      = 2???
'#if(WINVER >= 0x0400)
%IMAGE_ENHMETAFILE = 3???

%LR_DEFAULTCOLOR     = &H0000???
%LR_MONOCHROME       = &H0001???
%LR_COLOR            = &H0002???
%LR_COPYRETURNORG    = &H0004???
%LR_COPYDELETEORG    = &H0008???
%LR_LOADFROMFILE     = &H0010???
%LR_LOADTRANSPARENT  = &H0020???
%LR_DEFAULTSIZE      = &H0040???
%LR_VGACOLOR         = &H0080???
%LR_LOADMAP3DCOLORS  = &H1000???
%LR_CREATEDIBSECTION = &H2000???
%LR_COPYFROMRESOURCE = &H4000???
%LR_SHARED           = &H8000???

DECLARE FUNCTION LoadImageA IMPORT "USER32.DLL" ALIAS "LoadImageA" ( _
   BYVAL hInst AS DWORD _                               ' __in_opt HINSTANCE hInst
 , BYREF name AS ASCIIZ _                               ' __in LPCSTR name
 , BYVAL type AS DWORD _                                ' __in UINT type
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL fuLoad AS DWORD _                              ' __in UINT fuLoad
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION LoadImageW IMPORT "USER32.DLL" ALIAS "LoadImageW" ( _
   BYVAL hInst AS DWORD _                               ' __in_opt HINSTANCE hInst
 , BYREF name AS WSTRINGZ _                             ' __in LPCWSTR name
 , BYVAL type AS DWORD _                                ' __in UINT type
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL fuLoad AS DWORD _                              ' __in UINT fuLoad
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
   MACRO LoadImage = LoadImageW
#ELSE
   MACRO LoadImage = LoadImageA
#ENDIF

DECLARE FUNCTION CopyImage IMPORT "USER32.DLL" ALIAS "CopyImage" ( _
   BYVAL h AS DWORD _                                   ' __in HANDLE h
 , BYVAL type AS DWORD _                                ' __in UINT type
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HANDLE

%DI_MASK           = &H0001???
%DI_IMAGE          = &H0002???
%DI_NORMAL         = &H0003???
%DI_COMPAT         = &H0004???
%DI_DEFAULTSIZE    = &H0008???
'#if(_WIN32_WINNT >= 0x0501)
%DI_NOMIRROR       = &H0010???
'#endif /* _WIN32_WINNT >= 0x0501 */

DECLARE FUNCTION DrawIconEx IMPORT "USER32.DLL" ALIAS "DrawIconEx" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYVAL xLeft AS LONG _                                ' __in int xLeft
 , BYVAL yTop AS LONG _                                 ' __in int yTop
 , BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 , BYVAL cxWidth AS LONG _                              ' __in int cxWidth
 , BYVAL cyWidth AS LONG _                              ' __in int cyWidth
 , BYVAL istepIfAniCur AS DWORD _                       ' __in UINT istepIfAniCur
 , BYVAL hbrFlickerFreeDraw AS DWORD _                  ' __in_opt HBRUSH hbrFlickerFreeDraw
 , BYVAL diFlags AS DWORD _                             ' __in UINT diFlags
 ) AS LONG                                              ' long

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION CreateIconIndirect IMPORT "USER32.DLL" ALIAS "CreateIconIndirect" ( _
   BYREF piconinfo AS ICONINFO _                        ' __in PICONINFO piconinfo
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION CopyIcon IMPORT "USER32.DLL" ALIAS "CopyIcon" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION GetIconInfo IMPORT "USER32.DLL" ALIAS "GetIconInfo" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 , BYREF piconinfo AS ICONINFO _                        ' __out PICONINFO piconinfo
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0600)
' // Size = 548 bytes
TYPE ICONINFOEXA DWORD
   cbSize    AS DWORD   ' DWORD
   fIcon     AS LONG    ' BOOL
   xHotspot  AS DWORD   ' DWORD
   yHotspot  AS DWORD   ' DWORD
   hbmMask   AS DWORD   ' HBITMAP
   hbmColor  AS DWORD   ' HBITMAP
   wResID    AS WORD    ' WORD
   szModName AS ASCIIZ * %MAX_PATH
   szResName AS ASCIIZ * %MAX_PATH
END TYPE

' // Size = 1068 bytes
TYPE ICONINFOEXW DWORD
   cbSize    AS DWORD   ' DWORD
   fIcon     AS LONG    ' BOOL
   xHotspot  AS DWORD   ' DWORD
   yHotspot  AS DWORD   ' DWORD
   hbmMask   AS DWORD   ' HBITMAP
   hbmColor  AS DWORD   ' HBITMAP
   wResID    AS WORD    ' WORD
   szModName AS WSTRINGZ * %MAX_PATH
   szResName AS WSTRINGZ * %MAX_PATH
END TYPE

#IF %DEF(%UNICODE)
MACRO ICONINFOEX = ICONINFOEXW
#ELSE
MACRO ICONINFOEX = ICONINFOEXA
#ENDIF

DECLARE FUNCTION GetIconInfoExA IMPORT "USER32.DLL" ALIAS "GetIconInfoExA" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 , BYREF piconinfo AS ICONINFOEXA _                     ' __out PICONINFOEXA piconinfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetIconInfoExW IMPORT "USER32.DLL" ALIAS "GetIconInfoExW" ( _
   BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 , BYREF piconinfo AS ICONINFOEXW _                     ' __out PICONINFOEXW piconinfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetIconInfoEx = GetIconInfoExW
#ELSE
   MACRO GetIconInfoEx = GetIconInfoExA
#ENDIF
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if(WINVER >= 0x0400)
%RES_ICON   = 1??
%RES_CURSOR = 2??
'#endif /* WINVER >= 0x0400 */

'#ifdef OEMRESOURCE


'/*
' * OEM Resource Ordinal Numbers
' */
%OBM_CLOSE        = 32754???
%OBM_UPARROW      = 32753???
%OBM_DNARROW      = 32752???
%OBM_RGARROW      = 32751???
%OBM_LFARROW      = 32750???
%OBM_REDUCE       = 32749???
%OBM_ZOOM         = 32748???
%OBM_RESTORE      = 32747???
%OBM_REDUCED      = 32746???
%OBM_ZOOMD        = 32745???
%OBM_RESTORED     = 32744???
%OBM_UPARROWD     = 32743???
%OBM_DNARROWD     = 32742???
%OBM_RGARROWD     = 32741???
%OBM_LFARROWD     = 32740???
%OBM_MNARROW      = 32739???
%OBM_COMBO        = 32738???
%OBM_UPARROWI     = 32737???
%OBM_DNARROWI     = 32736???
%OBM_RGARROWI     = 32735???
%OBM_LFARROWI     = 32734???

%OBM_OLD_CLOSE    = 32767???
%OBM_SIZE         = 32766???
%OBM_OLD_UPARROW  = 32765???
%OBM_OLD_DNARROW  = 32764???
%OBM_OLD_RGARROW  = 32763???
%OBM_OLD_LFARROW  = 32762???
%OBM_BTSIZE       = 32761???
%OBM_CHECK        = 32760???
%OBM_CHECKBOXES   = 32759???
%OBM_BTNCORNERS   = 32758???
%OBM_OLD_REDUCE   = 32757???
%OBM_OLD_ZOOM     = 32756???
%OBM_OLD_RESTORE  = 32755???

%OCR_NORMAL       = 32512???
%OCR_IBEAM        = 32513???
%OCR_WAIT         = 32514???
%OCR_CROSS        = 32515???
%OCR_UP           = 32516???
%OCR_SIZE         = 32640???   ' OBSOLETE: use %OCR_SIZEALL
%OCR_ICON         = 32641???   ' OBSOLETE: use %OCR_NORMAL
%OCR_SIZENWSE     = 32642???
%OCR_SIZENESW     = 32643???
%OCR_SIZEWE       = 32644???
%OCR_SIZENS       = 32645???
%OCR_SIZEALL      = 32646???
%OCR_ICOCUR       = 32647???   ' OBSOLETE: use %OIC_WINLOGO
%OCR_NO           = 32648???
'#if(WINVER >= 0x0500)
%OCR_HAND         = 32649???
'#endif /* WINVER >= 0x0500 */
'#if(WINVER >= 0x0400)
%OCR_APPSTARTING  = 32650???
'#endif /* WINVER >= 0x0400 */

%OIC_SAMPLE       = 32512???
%OIC_HAND         = 32513???
%OIC_QUES         = 32514???
%OIC_BANG         = 32515???
%OIC_NOTE         = 32516???
'#if(WINVER >= 0x0400)
%OIC_WINLOGO      = 32517???
%OIC_WARNING      = %OIC_BANG
%OIC_ERROR        = %OIC_HAND
%OIC_INFORMATION  = %OIC_NOTE
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0600)
%OIC_SHIELD       = 32518???
'#endif /* WINVER >= 0x0600 */

'#endif /* OEMRESOURCE */

'#define ORD_LANGDRIVER    1     /* The ordinal number for the entry point of
'                                ** language drivers.
'                                */
%ORD_LANGDRIVER = 1& ' The ordinal number for the entry point of language drivers.

'#IF NOT %DEF(%NOICONS) ' ------------------------------------------------------
'#ifndef NOICONS

'/*
' * Standard Icon IDs
' */
'#ifdef RC_INVOKED
'#define IDI_APPLICATION     32512
'#define IDI_HAND            32513
'#define IDI_QUESTION        32514
'#define IDI_EXCLAMATION     32515
'#define IDI_ASTERISK        32516
'#if(WINVER >= 0x0400)
'#define IDI_WINLOGO         32517
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0600)
'#define IDI_SHIELD          32518
'#endif /* WINVER >= 0x0600 */
'#else
'#define IDI_APPLICATION     MAKEINTRESOURCE(32512)
'#define IDI_HAND            MAKEINTRESOURCE(32513)
'#define IDI_QUESTION        MAKEINTRESOURCE(32514)
'#define IDI_EXCLAMATION     MAKEINTRESOURCE(32515)
'#define IDI_ASTERISK        MAKEINTRESOURCE(32516)
'#if(WINVER >= 0x0400)
'#define IDI_WINLOGO         MAKEINTRESOURCE(32517)
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0600)
'#define IDI_SHIELD          MAKEINTRESOURCE(32518)
'#endif /* WINVER >= 0x0600 */
'#endif /* RC_INVOKED */

%IDI_APPLICATION = 32512???
%IDI_HAND        = 32513???
%IDI_QUESTION    = 32514???
%IDI_EXCLAMATION = 32515???
%IDI_ASTERISK    = 32516???
%IDI_WINLOGO     = 32517???
%IDI_SHIELD      = 32518???

'#if(WINVER >= 0x0400)
'#define IDI_WARNING     IDI_EXCLAMATION
'#define IDI_ERROR       IDI_HAND
'#define IDI_INFORMATION IDI_ASTERISK
%IDI_WARNING     = %IDI_EXCLAMATION
%IDI_ERROR       = %IDI_HAND
%IDI_INFORMATION = %IDI_ASTERISK
'#endif /* WINVER >= 0x0400 */

'#endif /* !NOICONS */
'#ENDIF   ' #IF NOT %DEF(%NOICONS) ' -------------------------------------------

DECLARE FUNCTION LoadStringA IMPORT "USER32.DLL" ALIAS "LoadStringA" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYVAL uID AS DWORD _                                 ' __in UINT uID
 , BYREF lpBuffer AS ASCIIZ _                           ' __out LPSTR lpBuffer
 , BYVAL cchBufferMax AS LONG _                         ' __in int cchBufferMax
 ) AS LONG                                              ' int

DECLARE FUNCTION LoadStringW IMPORT "USER32.DLL" ALIAS "LoadStringW" ( _
   BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYVAL uID AS DWORD _                                 ' __in UINT uID
 , BYREF lpBuffer AS WSTRINGZ _                         ' __out LPWSTR lpBuffer
 , BYVAL cchBufferMax AS LONG _                         ' __in int cchBufferMax
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO LoadString = LoadStringW
#ELSE
   MACRO LoadString = LoadStringA
#ENDIF

' // Note: The remed IDs are predefined in the compiler.

'/*
' * Dialog Box Command IDs
' */
'%IDOK       = 1??
'%IDCANCEL   = 2??
'%IDABORT    = 3??
'%IDRETRY    = 4??
'%IDIGNORE   = 5??
'%IDYES      = 6??
'%IDNO       = 7??
'#if(WINVER >= 0x0400)
'%IDCLOSE    = 8??
'%IDHELP     = 9??
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
'%IDTRYAGAIN = 10??
'%IDCONTINUE = 11??
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0501)
#IF NOT %DEF(%IDTIMEOUT)
%IDTIMEOUT  = 32000??
#ENDIF
'#endif /* WINVER >= 0x0501 */


'#IF NOT %DEF(%NOCTLMGR) ' -----------------------------------------------------
'#ifndef NOCTLMGR

'/*
' * Control Manager Structures and Definitions
' */

'#IF NOT %DEF(%NOWINSTYLES) ' --------------------------------------------------
'#ifndef NOWINSTYLES

'/*
' * Edit Control Styles
' */
'%ES_LEFT        = &H0000???
'%ES_CENTER      = &H0001???
'%ES_RIGHT       = &H0002???
'%ES_MULTILINE   = &H0004???
'%ES_UPPERCASE   = &H0008???
'%ES_LOWERCASE   = &H0010???
'%ES_PASSWORD    = &H0020???
'%ES_AUTOVSCROLL = &H0040???
'%ES_AUTOHSCROLL = &H0080???
'%ES_NOHIDESEL   = &H0100???
'%ES_OEMCONVERT  = &H0400???
'%ES_READONLY    = &H0800???
'%ES_WANTRETURN  = &H1000???
'#if(WINVER >= 0x0400)
'%ES_NUMBER      = &H2000???
'#endif /* WINVER >= 0x0400 */

'#endif /* !NOWINSTYLES */
'#ENDIF   ' #IF NOT %DEF(%NOWINSTYLES) ' ---------------------------------------

'/*
' * Edit Control Notification Codes
' */
'%EN_SETFOCUS     = &H0100???
'%EN_KILLFOCUS    = &H0200???
'%EN_CHANGE       = &H0300???
'%EN_UPDATE       = &H0400???
'%EN_ERRSPACE     = &H0500???
'%EN_MAXTEXT      = &H0501???
'%EN_HSCROLL      = &H0601???
'%EN_VSCROLL      = &H0602???

'#if(_WIN32_WINNT >= 0x0500)
%EN_ALIGN_LTR_EC = &H0700???
%EN_ALIGN_RTL_EC = &H0701???
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(WINVER >= 0x0400)
'/* Edit control EM_SETMARGIN parameters */
%EC_LEFTMARGIN   = &H0001???
%EC_RIGHTMARGIN  = &H0002???
%EC_USEFONTINFO  = &HFFFF???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
'/* wParam of EM_GET/SETIMESTATUS  */
%EMSIS_COMPOSITIONSTRING        = &H0001???

'/* lParam for EMSIS_COMPOSITIONSTRING  */
%EIMES_GETCOMPSTRATONCE         = &H0001???
%EIMES_CANCELCOMPSTRINFOCUS     = &H0002???
%EIMES_COMPLETECOMPSTRKILLFOCUS = &H0004???
'#endif /* WINVER >= 0x0500 */

'#IF NOT %DEF(%NOWINMESSAGES) ' ------------------------------------------------
'#ifndef NOWINMESSAGES

'/*
' * Edit Control Messages
' */
%EM_GETSEL              = &H00B0???
%EM_SETSEL              = &H00B1???
%EM_GETRECT             = &H00B2???
%EM_SETRECT             = &H00B3???
%EM_SETRECTNP           = &H00B4???
%EM_SCROLL              = &H00B5???
%EM_LINESCROLL          = &H00B6???
%EM_SCROLLCARET         = &H00B7???
%EM_GETMODIFY           = &H00B8???
%EM_SETMODIFY           = &H00B9???
%EM_GETLINECOUNT        = &H00BA???
%EM_LINEINDEX           = &H00BB???
%EM_SETHANDLE           = &H00BC???
%EM_GETHANDLE           = &H00BD???
%EM_GETTHUMB            = &H00BE???
%EM_LINELENGTH          = &H00C1???
%EM_REPLACESEL          = &H00C2???
%EM_GETLINE             = &H00C4???
%EM_LIMITTEXT           = &H00C5???
%EM_CANUNDO             = &H00C6???
%EM_UNDO                = &H00C7???
%EM_FMTLINES            = &H00C8???
%EM_LINEFROMCHAR        = &H00C9???
%EM_SETTABSTOPS         = &H00CB???
%EM_SETPASSWORDCHAR     = &H00CC???
%EM_EMPTYUNDOBUFFER     = &H00CD???
%EM_GETFIRSTVISIBLELINE = &H00CE???
%EM_SETREADONLY         = &H00CF???
%EM_SETWORDBREAKPROC    = &H00D0???
%EM_GETWORDBREAKPROC    = &H00D1???
%EM_GETPASSWORDCHAR     = &H00D2???
'#if(WINVER >= 0x0400)
%EM_SETMARGINS          = &H00D3???
%EM_GETMARGINS          = &H00D4???
%EM_SETLIMITTEXT        = %EM_LIMITTEXT
%EM_GETLIMITTEXT        = &H00D5???
%EM_POSFROMCHAR         = &H00D6???
%EM_CHARFROMPOS         = &H00D7???
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%EM_SETIMESTATUS        = &H00D8???
%EM_GETIMESTATUS        = &H00D9???
'#endif /* WINVER >= 0x0500 */

'#endif /* !NOWINMESSAGES */
'#ENDIF   ' #IF NOT %DEF(%NOWINMESSAGES) ' -------------------------------------

'/*
' * EDITWORDBREAKPROC code values
' */
%WB_LEFT        = 0&
%WB_RIGHT       = 1&
%WB_ISDELIMITER = 2&

' // Note: The remed BS_XXX styles are predefined in the compiler.
'/*
' * Button Control Styles
' */
'%BS_PUSHBUTTON      = &H00000000???
'%BS_DEFPUSHBUTTON   = &H00000001???
'%BS_DEFAULT         = %BS_DEFPUSHBUTTON
'%BS_CHECKBOX        = &H00000002???
'%BS_AUTOCHECKBOX    = &H00000003???
'%BS_RADIOBUTTON     = &H00000004???
'%BS_3STATE          = &H00000005???
'%BS_AUTO3STATE      = &H00000006???
'%BS_GROUPBOX        = &H00000007???
'%BS_USERBUTTON      = &H00000008???
'%BS_AUTORADIOBUTTON = &H00000009???
'%BS_OWNERDRAW       = &H0000000B???
'%BS_LEFTTEXT        = &H00000020???
'#if(WINVER >= 0x0400)
'%BS_TEXT            = &H00000000???
'%BS_ICON            = &H00000040???
'%BS_BITMAP          = &H00000080???
'%BS_LEFT            = &H00000100???
'%BS_RIGHT           = &H00000200???
'%BS_CENTER          = &H00000300???
'%BS_TOP             = &H00000400???
'%BS_BOTTOM          = &H00000800???
'%BS_VCENTER         = &H00000C00???
'%BS_PUSHLIKE        = &H00001000???
'%BS_MULTILINE       = &H00002000???
'%BS_NOTIFY          = &H00004000???
'%BS_FLAT            = &H00008000???
%BS_RIGHTBUTTON     = %BS_LEFTTEXT
'#endif /* WINVER >= 0x0400 */

' // The remed BN_XXX equates are predefined in the compiler.

'/*
' * User Button Notification Codes
' */
'%BN_CLICKED        = 0&
'%BN_PAINT          = 1&
'%BN_HILITE         = 2&
'%BN_UNHILITE       = 3&
'%BN_DISABLE        = 4&
'%BN_DOUBLECLICKED  = 5&
'#if(WINVER >= 0x0400)
%BN_PUSHED         = %BN_HILITE
%BN_UNPUSHED       = %BN_UNHILITE
'%BN_DBLCLK         = %BN_DOUBLECLICKED
'%BN_SETFOCUS       = 6&
'%BN_KILLFOCUS      = 7&
'#endif /* WINVER >= 0x0400 */

'/*
' * Button Control Messages
' */
%BM_GETCHECK       = &H00F0???
%BM_SETCHECK       = &H00F1???
%BM_GETSTATE       = &H00F2???
%BM_SETSTATE       = &H00F3???
%BM_SETSTYLE       = &H00F4???
'#if(WINVER >= 0x0400)
%BM_CLICK          = &H00F5???
%BM_GETIMAGE       = &H00F6???
%BM_SETIMAGE       = &H00F7???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0600)
%BM_SETDONTCLICK   = &H00F8???
'#endif /* WINVER >= 0x0600 */

'#if(WINVER >= 0x0400)
%BST_UNCHECKED     = &H0000&
%BST_CHECKED       = &H0001&
%BST_INDETERMINATE = &H0002&
%BST_PUSHED        = &H0004&
%BST_FOCUS         = &H0008&
'#endif /* WINVER >= 0x0400 */


'/*
' * Static Control Constants
' */
'%SS_LEFT            = &H00000000???
'%SS_CENTER          = &H00000001???
'%SS_RIGHT           = &H00000002???
'%SS_ICON            = &H00000003???
'%SS_BLACKRECT       = &H00000004???
'%SS_GRAYRECT        = &H00000005???
'%SS_WHITERECT       = &H00000006???
'%SS_BLACKFRAME      = &H00000007???
'%SS_GRAYFRAME       = &H00000008???
'%SS_WHITEFRAME      = &H00000009???
'%SS_USERITEM        = &H0000000A???
'%SS_SIMPLE          = &H0000000B???
'%SS_LEFTNOWORDWRAP  = &H0000000C???
'#if(WINVER >= 0x0400)
'%SS_NOWORDWRAP      = %SS_LEFTNOWORDWRAP
'%SS_OWNERDRAW       = &H0000000D???
'%SS_BITMAP          = &H0000000E???
'%SS_ENHMETAFILE     = &H0000000F???
'%SS_ETCHEDHORZ      = &H00000010???
'%SS_ETCHEDVERT      = &H00000011???
'%SS_ETCHEDFRAME     = &H00000012???
%SS_TYPEMASK        = &H0000001F???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0501)
'%SS_REALSIZECONTROL = &H00000040???
'#endif /* WINVER >= 0x0501 */
'%SS_NOPREFIX        = &H00000080???  ' Don't do "&" character translation
'#if(WINVER >= 0x0400)
'%SS_NOTIFY          = &H00000100???
'%SS_CENTERIMAGE     = &H00000200???
'%SS_RIGHTJUST       = &H00000400???
'%SS_REALSIZEIMAGE   = &H00000800???
'%SS_REALSIZE        = %SS_REALSIZEIMAGE
'%SS_SUNKEN          = &H00001000???
'%SS_ENDELLIPSIS     = &H00004000???
'%SS_PATHELLIPSIS    = &H00008000???
'%SS_WORDELLIPSIS    = &H0000C000???
'%SS_ELLIPSISMASK    = &H0000C000???
'#endif /* WINVER >= 0x0400 */

'#IF NOT %DEF(%NOWINMESSAGES) ' ------------------------------------------------
'#ifndef NOWINMESSAGES
'/*
' * Static Control Mesages
' */
%STM_SETICON  = &H0170???
%STM_GETICON  = &H0171???
'#if(WINVER >= 0x0400)
%STM_SETIMAGE = &H0172???
%STM_GETIMAGE = &H0173???
%STN_CLICKED  = 0&
%STN_DBLCLK   = 1&
%STN_ENABLE   = 2&
%STN_DISABLE  = 3&
'#endif /* WINVER >= 0x0400 */
%STM_MSGMAX   = &H0174???

'#endif /* !NOWINMESSAGES */
'#ENDIF   ' #IF NOT %DEF(%NOWINMESSAGES) ' -------------------------------------

'/*
' * Dialog window class
' */
'#define WC_DIALOG       (MAKEINTATOM(0x8002))
%WC_DIALOG = &H8002???

'/*
' * Get/SetWindowWord/Long offsets for use with WC_DIALOG windows
' */
%DWL_MSGRESULT = 0&
%DWL_DLGPROC   = 4&
%DWL_USER      = 8&

'#ifdef _WIN64

'#undef DWL_MSGRESULT
'#undef DWL_DLGPROC
'#undef DWL_USER

'#endif /* _WIN64 */

'#define DWLP_MSGRESULT  0
'#define DWLP_DLGPROC    DWLP_MSGRESULT + sizeof(LRESULT)
'#define DWLP_USER       DWLP_DLGPROC + sizeof(DLGPROC)

%DWLP_MSGRESULT  = 0
%DWLP_DLGPROC    = %DWLP_MSGRESULT + 4
%DWLP_USER       = %DWLP_DLGPROC + 4

'/*
' * Dialog Manager Routines
' */

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

DECLARE FUNCTION IsDialogMessageA IMPORT "USER32.DLL" ALIAS "IsDialogMessageA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsDialogMessageW IMPORT "USER32.DLL" ALIAS "IsDialogMessageW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsDialogMessage = IsDialogMessageW
#ELSE
   MACRO IsDialogMessage = IsDialogMessageA
#ENDIF

'#endif /* !NOMSG */
'#ENDIF   ' #IF NOT %DEF(%NOMSG) '----------------------------------------------

DECLARE FUNCTION MapDialogRect IMPORT "USER32.DLL" ALIAS "MapDialogRect" ( _
   BYVAL hDlg AS DWORD  _                               ' __in HWND hDlg
 , BYREF lpRect AS RECT _                               ' __inout LPRECT lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DlgDirListA IMPORT "USER32.DLL" ALIAS "DlgDirListA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpPathSpec AS ASCIIZ _                         ' __inout LPSTR lpPathSpec
 , BYVAL nIDListBox AS LONG _                           ' __in int nIDListBox
 , BYVAL nIDStaticPath AS LONG _                        ' __in int nIDStaticPath
 , BYVAL uFileType AS DWORD _                           ' __in UINT uFileType
 ) AS LONG                                              ' int

DECLARE FUNCTION DlgDirListW IMPORT "USER32.DLL" ALIAS "DlgDirListW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpPathSpec AS WSTRINGZ _                       ' __inout LPWSTR lpPathSpec
 , BYVAL nIDListBox AS LONG _                           ' __in int nIDListBox
 , BYVAL nIDStaticPath AS LONG _                        ' __in int nIDStaticPath
 , BYVAL uFileType AS DWORD _                           ' __in UINT uFileType
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DlgDirList = DlgDirListW
#ELSE
   MACRO DlgDirList = DlgDirListA
#ENDIF

'/*
' * DlgDirList, DlgDirListComboBox flags values
' */
%DDL_READWRITE = &H0000???
%DDL_READONLY  = &H0001???
%DDL_HIDDEN    = &H0002???
%DDL_SYSTEM    = &H0004???
%DDL_DIRECTORY = &H0010???
%DDL_ARCHIVE   = &H0020???

%DDL_POSTMSGS  = &H2000???
%DDL_DRIVES    = &H4000???
%DDL_EXCLUSIVE = &H8000???

DECLARE FUNCTION DlgDirSelectExA IMPORT "USER32.DLL" ALIAS "DlgDirSelectExA" ( _
   BYVAL hWndDlg AS DWORD _                             ' __in HWND hWndDlg
 , BYREF lpString AS ASCIIZ  _                          ' __out LPSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL idListBox AS LONG _                            ' __in int idListBox
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DlgDirSelectExW IMPORT "USER32.DLL" ALIAS "DlgDirSelectExW" ( _
   BYVAL hWndDlg AS DWORD _                             ' __in HWND hWndDlg
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL chCount AS LONG _                              ' __in int chCount
 , BYVAL idListBox AS LONG _                            ' __in int idListBox
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DlgDirSelectEx = DlgDirSelectExW
#ELSE
   MACRO DlgDirSelectEx = DlgDirSelectExA
#ENDIF

DECLARE FUNCTION DlgDirListComboBoxA IMPORT "USER32.DLL" ALIAS "DlgDirListComboBoxA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpPathSpec AS ASCIIZ _                         ' __inout LPSTR lpPathSpec
 , BYVAL nIDComboBox AS LONG _                          ' __in int nIDComboBox
 , BYVAL nIDStaticPath AS LONG _                        ' __in int nIDStaticPath
 , BYVAL uFiletype AS DWORD _                           ' __in UINT uFiletype
 ) AS LONG                                              ' int

DECLARE FUNCTION DlgDirListComboBoxW IMPORT "USER32.DLL" ALIAS "DlgDirListComboBoxW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpPathSpec AS WSTRINGZ _                       ' __inout LPWSTR lpPathSpec
 , BYVAL nIDComboBox AS LONG _                          ' __in int nIDComboBox
 , BYVAL nIDStaticPath AS LONG _                        ' __in int nIDStaticPath
 , BYVAL uFiletype AS DWORD _                           ' __in UINT uFiletype
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DlgDirListComboBox = DlgDirListComboBoxW
#ELSE
   MACRO DlgDirListComboBox = DlgDirListComboBoxA
#ENDIF

DECLARE FUNCTION DlgDirSelectComboBoxExA IMPORT "USER32.DLL" ALIAS "DlgDirSelectComboBoxExA" ( _
   BYVAL hWndDlg AS DWORD _                             ' __in HWND hWndDlg
 , BYREF lpString AS ASCIIZ _                           ' __out LPSTR lpString
 , BYVAL cchOut AS LONG _                               ' __in int cchOut
 , BYVAL idComboBox AS LONG _                           ' __in int idComboBox
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DlgDirSelectComboBoxExW IMPORT "USER32.DLL" ALIAS "DlgDirSelectComboBoxExW" ( _
   BYVAL hWndDlg AS DWORD _                             ' __in HWND hWndDlg
 , BYREF lpString AS WSTRINGZ _                         ' __out LPWSTR lpString
 , BYVAL cchOut AS LONG _                               ' __in int cchOut
 , BYVAL idComboBox AS LONG _                           ' __in int idComboBox
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DlgDirSelectComboBoxEx = DlgDirSelectComboBoxExW
#ELSE
   MACRO DlgDirSelectComboBoxEx = DlgDirSelectComboBoxExA
#ENDIF

' // Note: The remed DS_XXX styles are predefined in the compiler.

'/*
' * Dialog Styles
' */
'%DS_ABSALIGN      = &H01???
'%DS_SYSMODAL      = &H02???
'%DS_LOCALEDIT     = &H20???   ' Edit items get Local storage.
'%DS_SETFONT       = &H40???   ' User specified font for Dlg controls
'%DS_MODALFRAME    = &H80???   ' Can be combined with WS_CAPTION
'%DS_NOIDLEMSG     = &H100???  ' WM_ENTERIDLE message will not be sent
'%DS_SETFOREGROUND = &H200???  ' not in win3.1
'#if(WINVER >= 0x0400)
'%DS_3DLOOK        = &H0004???
'%DS_FIXEDSYS      = &H0008???
'%DS_NOFAILCREATE  = &H0010???
'%DS_CONTROL       = &H0400???
'%DS_CENTER        = &H0800???
'%DS_CENTERMOUSE   = &H1000???
'%DS_CONTEXTHELP   = &H2000???

'%DS_SHELLFONT     = %DS_SETFONT OR %DS_FIXEDSYS
'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WCE >= 0x0500)
%DS_USEPIXELS     = &H8000???
'#endif

%DM_GETDEFID      = %WM_USER + 0
%DM_SETDEFID      = %WM_USER + 1

'#if(WINVER >= 0x0400)
%DM_REPOSITION    = %WM_USER + 2
'#endif /* WINVER >= 0x0400 */
'/*
' * Returned in HIWORD() of DM_GETDEFID result if msg is supported
' */
%DC_HASDEFID      = &H534B??

'/*
' * Dialog Codes
' */
'%DLGC_WANTARROWS      = &H0001&    ' Control wants arrow keys
'%DLGC_WANTTAB         = &H0002&    ' Control wants tab keys
'%DLGC_WANTALLKEYS     = &H0004&    ' Control wants all keys
'%DLGC_WANTMESSAGE     = &H0004&    ' Pass message to control
'%DLGC_HASSETSEL       = &H0008&    ' Understands EM_SETSEL message
'%DLGC_DEFPUSHBUTTON   = &H0010&    ' Default pushbutton
'%DLGC_UNDEFPUSHBUTTON = &H0020&    ' Non-default pushbutton
'%DLGC_RADIOBUTTON     = &H0040&    ' Radio button
'%DLGC_WANTCHARS       = &H0080&    ' Want WM_CHAR messages
'%DLGC_STATIC          = &H0100&    ' Static item: don't include
'%DLGC_BUTTON          = &H2000&    ' Button item: can be checked

%LB_CTLCODE  = 0&

'/*
' * Listbox Return Values
' */
%LB_OKAY     = 0&
%LB_ERR      = -1&
%LB_ERRSPACE = -2&

'/*
'**  The idStaticPath parameter to DlgDirList can have the following values
'**  ORed if the list box should show other details of the files along with
'**  the name of the files;
'*/
'/* all other details also will be returned */


' // Note: The remed LBN_XXX equates are predefined in the compiler.

'/*
' * Listbox Notification Codes
' */
'%LBN_ERRSPACE  = -2&
'%LBN_SELCHANGE = 1&
'%LBN_DBLCLK    = 2&
'%LBN_SELCANCEL = 3&
'%LBN_SETFOCUS  = 4&
'%LBN_KILLFOCUS = 5&

'#IF NOT %DEF(%NOWINMESSAGES) ' ------------------------------------------------
'#ifndef NOWINMESSAGES

'/*
' * Listbox messages
' */
%LB_ADDSTRING           = &H180???
%LB_INSERTSTRING        = &H181???
%LB_DELETESTRING        = &H182???
%LB_SELITEMRANGEEX      = &H183???
%LB_RESETCONTENT        = &H184???
%LB_SETSEL              = &H185???
%LB_SETCURSEL           = &H186???
%LB_GETSEL              = &H187???
%LB_GETCURSEL           = &H188???
%LB_GETTEXT             = &H189???
%LB_GETTEXTLEN          = &H18A???
%LB_GETCOUNT            = &H18B???
%LB_SELECTSTRING        = &H18C???
%LB_DIR                 = &H18D???
%LB_GETTOPINDEX         = &H18E???
%LB_FINDSTRING          = &H18F???
%LB_GETSELCOUNT         = &H190???
%LB_GETSELITEMS         = &H191???
%LB_SETTABSTOPS         = &H192???
%LB_GETHORIZONTALEXTENT = &H193???
%LB_SETHORIZONTALEXTENT = &H194???
%LB_SETCOLUMNWIDTH      = &H195???
%LB_ADDFILE             = &H196???
%LB_SETTOPINDEX         = &H197???
%LB_GETITEMRECT         = &H198???
%LB_GETITEMDATA         = &H199???
%LB_SETITEMDATA         = &H19A???
%LB_SELITEMRANGE        = &H19B???
%LB_SETANCHORINDEX      = &H19C???
%LB_GETANCHORINDEX      = &H19D???
%LB_SETCARETINDEX       = &H19E???
%LB_GETCARETINDEX       = &H19F???
%LB_SETITEMHEIGHT       = &H1A0???
%LB_GETITEMHEIGHT       = &H1A1???
%LB_FINDSTRINGEXACT     = &H1A2???
%LB_SETLOCALE           = &H1A5???
%LB_GETLOCALE           = &H1A6???
%LB_SETCOUNT            = &H1A7???
'#if(WINVER >= 0x0400)
%LB_INITSTORAGE         = &H1A8???
%LB_ITEMFROMPOINT       = &H1A9???
'#endif /* WINVER >= 0x0400 */
'#if(_WIN32_WCE >= 0x0400)
%LB_MULTIPLEADDSTRING   = &H1B1???
'#endif

'#if(_WIN32_WINNT >= 0x0501)
%LB_GETLISTBOXINFO      = &H1B2???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0501)
'#define LB_MSGMAX               0x01B3
'#elif(_WIN32_WCE >= 0x0400)
'#define LB_MSGMAX               0x01B1
'#elif(WINVER >= 0x0400)
'#define LB_MSGMAX               0x01B0
'#else
'#define LB_MSGMAX               0x01A8
'#endif

%LB_MSGMAX             = &H1B3???  ' depends on Windows version

'#endif /* !NOWINMESSAGES */
'#ENDIF   ' #IF NOT %DEF(%NOWINMESSAGES) ' -------------------------------------

'#IF NOT %DEF(%NOWINSTYLES) ' --------------------------------------------------
'#ifndef NOWINSTYLES

' // Note: The remed LBX_XXX equates are predefined in the compiler.

'/*
' * Listbox Styles
' */
'%LBS_NOTIFY            = &H0001???
'%LBS_SORT              = &H0002???
'%LBS_NOREDRAW          = &H0004???
'%LBS_MULTIPLESEL       = &H0008???
'%LBS_OWNERDRAWFIXED    = &H0010???
'%LBS_OWNERDRAWVARIABLE = &H0020???
'%LBS_HASSTRINGS        = &H0040???
'%LBS_USETABSTOPS       = &H0080???
'%LBS_NOINTEGRALHEIGHT  = &H0100???
'%LBS_MULTICOLUMN       = &H0200???
'%LBS_WANTKEYBOARDINPUT = &H0400???
'%LBS_EXTENDEDSEL       = &H0800???
'%LBS_DISABLENOSCROLL   = &H1000???
'%LBS_NODATA            = &H2000???
'#if(WINVER >= 0x0400)
'%LBS_NOSEL             = &H4000???
'#endif /* WINVER >= 0x0400 */
%LBS_COMBOBOX          = &H8000???
'%LBS_STANDARD          = %LBS_NOTIFY OR %LBS_SORT OR %WS_VSCROLL OR %WS_BORDER

'#endif /* !NOWINSTYLES */
'#ENDIF   ' #IF NOT %DEF(%NOWINSTYLES) ' ---------------------------------------


'/*
' * Combo Box return Values
' */
%CB_OKAY     = 0&
%CB_ERR      = -1&
%CB_ERRSPACE = -2&

'/*
' * Combo Box Notification Codes
' */
'%CBN_ERRSPACE     = -1&
'%CBN_SELCHANGE    = 1&
'%CBN_DBLCLK       = 2&
'%CBN_SETFOCUS     = 3&
'%CBN_KILLFOCUS    = 4&
'%CBN_EDITCHANGE   = 5&
'%CBN_EDITUPDATE   = 6&
'%CBN_DROPDOWN     = 7&
'%CBN_CLOSEUP      = 8&
'%CBN_SELENDOK     = 9&
'%CBN_SELENDCANCEL = 10&
'%CBN_SELCANCEL    = %CBN_SELENDCANCEL

'#IF NOT %DEF(%NOWINSTYLES) ' --------------------------------------------------
'#ifndef NOWINSTYLES

'/*
' * Combo Box styles
' */
'%CBS_SIMPLE            = &H0001???
'%CBS_DROPDOWN          = &H0002???
'%CBS_DROPDOWNLIST      = &H0003???
'%CBS_OWNERDRAWFIXED    = &H0010???
'%CBS_OWNERDRAWVARIABLE = &H0020???
'%CBS_AUTOHSCROLL       = &H0040???
'%CBS_OEMCONVERT        = &H0080???
'%CBS_SORT              = &H0100???
'%CBS_HASSTRINGS        = &H0200???
'%CBS_NOINTEGRALHEIGHT  = &H0400???
'%CBS_DISABLENOSCROLL   = &H0800???
'#if(WINVER >= 0x0400)
'%CBS_UPPERCASE         = &H2000???
'%CBS_LOWERCASE         = &H4000???
'#endif /* WINVER >= 0x0400 */

'#endif  /* !NOWINSTYLES */
'#ENDIF   ' #IF NOT %DEF(%NOWINSTYLES) ' ---------------------------------------


'/*
' * Combo Box messages
' */
'#IF NOT %DEF(%NOWINMESSAGES) ' ------------------------------------------------
'#ifndef NOWINMESSAGES

%CB_GETEDITSEL            = &H0140???
%CB_LIMITTEXT             = &H0141???
%CB_SETEDITSEL            = &H0142???
%CB_ADDSTRING             = &H0143???
%CB_DELETESTRING          = &H0144???
%CB_DIR                   = &H0145???
%CB_GETCOUNT              = &H0146???
%CB_GETCURSEL             = &H0147???
%CB_GETLBTEXT             = &H0148???
%CB_GETLBTEXTLEN          = &H0149???
%CB_INSERTSTRING          = &H014A???
%CB_RESETCONTENT          = &H014B???
%CB_FINDSTRING            = &H014C???
%CB_SELECTSTRING          = &H014D???
%CB_SETCURSEL             = &H014E???
%CB_SHOWDROPDOWN          = &H014F???
%CB_GETITEMDATA           = &H0150???
%CB_SETITEMDATA           = &H0151???
%CB_GETDROPPEDCONTROLRECT = &H0152???
%CB_SETITEMHEIGHT         = &H0153???
%CB_GETITEMHEIGHT         = &H0154???
%CB_SETEXTENDEDUI         = &H0155???
%CB_GETEXTENDEDUI         = &H0156???
%CB_GETDROPPEDSTATE       = &H0157???
%CB_FINDSTRINGEXACT       = &H0158???
%CB_SETLOCALE             = &H0159???
%CB_GETLOCALE             = &H015A???
'#if(WINVER >= 0x0400)
%CB_GETTOPINDEX           = &H015B???
%CB_SETTOPINDEX           = &H015C???
%CB_GETHORIZONTALEXTENT   = &H015D???
%CB_SETHORIZONTALEXTENT   = &H015E???
%CB_GETDROPPEDWIDTH       = &H015F???
%CB_SETDROPPEDWIDTH       = &H0160???
%CB_INITSTORAGE           = &H0161???
'#if(_WIN32_WCE >= 0x0400)
%CB_MULTIPLEADDSTRING     = &H0163???
'#endif
'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0501)
%CB_GETCOMBOBOXINFO       = &H0164???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0501)
'#define CB_MSGMAX                   0x0165
'#elif(_WIN32_WCE >= 0x0400)
'#define CB_MSGMAX                   0x0163
'#elif(WINVER >= 0x0400)
'#define CB_MSGMAX                   0x0162
'#else
'#define CB_MSGMAX                   0x015B
'#endif

%CB_MSGMAX                = &H0165???  ' depends on Windows version

'#endif  /* !NOWINMESSAGES */
'#ENDIF   '   #IF NOT %DEF(%NOWINMESSAGES) ' -----------------------------------

'#IF NOT %DEF(%NOWINSTYLES) ' --------------------------------------------------
'#ifndef NOWINSTYLES

'/*
' * Scroll Bar Styles
' */
'%SBS_HORZ                    = &H0000???
'%SBS_VERT                    = &H0001???
'%SBS_TOPALIGN                = &H0002???
'%SBS_LEFTALIGN               = &H0002???
'%SBS_BOTTOMALIGN             = &H0004???
'%SBS_RIGHTALIGN              = &H0004???
'%SBS_SIZEBOXTOPLEFTALIGN     = &H0002???
'%SBS_SIZEBOXBOTTOMRIGHTALIGN = &H0004???
'%SBS_SIZEBOX                 = &H0008???
'#if(WINVER >= 0x0400)
'%SBS_SIZEGRIP                = &H0010???
'#endif /* WINVER >= 0x0400 */

'#endif /* !NOWINSTYLES */
'#ENDIF   '   #IF NOT %DEF(%NOWINSTYLES) ' -------------------------------------

'/*
' * Scroll bar messages
' */
'#ifndef NOWINMESSAGES
'#IF NOT %DEF(%NOWINMESSAGES) ' ------------------------------------------------

%SBM_SETPOS           = &H0E0??? ' not in win3.1
%SBM_GETPOS           = &H0E1??? ' not in win3.1
%SBM_SETRANGE         = &H0E2??? ' not in win3.1
%SBM_SETRANGEREDRAW   = &H0E6??? ' not in win3.1
%SBM_GETRANGE         = &H0E3??? ' not in win3.1
%SBM_ENABLE_ARROWS    = &H0E4??? ' not in win3.1
'#if(WINVER >= 0x0400)
%SBM_SETSCROLLINFO    = &H0E9???
%SBM_GETSCROLLINFO    = &H0EA???
'#endif /* WINVER >= 0x0400 */

'#if(_WIN32_WINNT >= 0x0501)
%SBM_GETSCROLLBARINFO = &H0EB???
'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(WINVER >= 0x0400)
'%SIF_RANGE            = &H0001???
'%SIF_PAGE             = &H0002???
'%SIF_POS              = &H0004???
'%SIF_DISABLENOSCROLL  = &H000q8???
'%SIF_TRACKPOS         = &H0010???
'%SIF_ALL              = %SIF_RANGE OR %SIF_PAGE OR %SIF_POS OR %SIF_TRACKPOS

' // Size = 28 bytes
TYPE SCROLLINFO DWORD
   cbSize    AS DWORD   ' UINT
   fMask     AS DWORD   ' UINT
   nMin      AS LONG    ' int
   nMax      AS LONG    ' int
   nPage     AS DWORD   ' UINT
   nPos      AS LONG    ' int
   nTrackPos AS LONG    ' int
END TYPE


DECLARE FUNCTION SetScrollInfo IMPORT "USER32.DLL" ALIAS "SetScrollInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 , BYREF lpsi AS SCROLLINFO _                           ' __in LPCSCROLLINFO lpsi
 , BYVAL redraw AS LONG _                               ' __in BOOL redraw
 ) AS LONG                                              ' int

DECLARE FUNCTION GetScrollInfo IMPORT "USER32.DLL" ALIAS "GetScrollInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL nBar AS LONG _                                 ' __in int nBar
 , BYREF lpsi AS SCROLLINFO _                           ' __inout LPSCROLLINFO lpsi
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0400 */
'#endif /* !NOWINMESSAGES */
'#ENDIF   ' #IF NOT %DEF(%NOWINMESSAGES) ' -------------------------------------
'#endif /* !NOCTLMGR */
'#ENDIF   ' #IF NOT %DEF(%NOCTLMGR) ' ------------------------------------------

'#IF NOT %DEF(%NOMDI) ' --------------------------------------------------------
'#ifndef NOMDI

'/*
' * MDI client style bits
' */
%MDIS_ALLCHILDSTYLES = &H0001???

'/*
' * wParam Flags for WM_MDITILE and WM_MDICASCADE messages.
' */
%MDITILE_VERTICAL     = &H0000???
%MDITILE_HORIZONTAL   = &H0001???
%MDITILE_SKIPDISABLED = &H0002???
'#if(_WIN32_WINNT >= 0x0500)
%MDITILE_ZORDER       = &H0004???
'#endif /* _WIN32_WINNT >= 0x0500 */

' // Size = 36 bytes
TYPE MDICREATESTRUCTA DWORD
   szClass AS ASCIIZ PTR   ' LPCSTR
   szTitle AS ASCIIZ PTR   ' LPCSTR
   hOwner  AS DWORD        ' HANDLE
   x       AS LONG         ' int
   y       AS LONG         ' int
   cx      AS LONG         ' int
   cy      AS LONG         ' int
   style   AS DWORD        ' DWORD
   lParam  AS LONG         ' LPARAM
END TYPE

' // Size = 36 bytes
TYPE MDICREATESTRUCTW DWORD
   szClass AS WSTRINGZ PTR   ' LPCWSTR
   szTitle AS WSTRINGZ PTR   ' LPCWSTR
   hOwner  AS DWORD          ' HANDLE
   x       AS LONG           ' int
   y       AS LONG           ' int
   cx      AS LONG           ' int
   cy      AS LONG           ' int
   style   AS DWORD          ' DWORD
   lParam  AS LONG           ' LPARAM
END TYPE

#IF %DEF(%UNICODE)
MACRO MDICREATESTRUCT = MDICREATESTRUCTW
#ELSE
MACRO MDICREATESTRUCT = MDICREATESTRUCTA
#ENDIF

' // Size = 8 bytes
TYPE CLIENTCREATESTRUCT DWORD
   hWindowMenu  AS DWORD   ' HANDLE
   idFirstChild AS DWORD   ' UINT
END TYPE

DECLARE FUNCTION DefFrameProcA IMPORT "USER32.DLL" ALIAS "DefFrameProcA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hWndMDIClient AS DWORD _                       ' __in_opt HWND hWndMDIClient
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DefFrameProcW IMPORT "USER32.DLL" ALIAS "DefFrameProcW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hWndMDIClient AS DWORD _                       ' __in_opt HWND hWndMDIClient
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO DefFrameProc = DefFrameProcW
#ELSE
   MACRO DefFrameProc = DefFrameProcA
#ENDIF

DECLARE FUNCTION DefMDIChildProcA IMPORT "USER32.DLL" ALIAS "DefMDIChildProcA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DefMDIChildProcW IMPORT "USER32.DLL" ALIAS "DefMDIChildProcW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO DefMDIChildProc = DefMDIChildProcW
#ELSE
   MACRO DefMDIChildProc = DefMDIChildProcA
#ENDIF

'#IF NOT %DEF(%NOMSG) '---------------------------------------------------------
'#ifndef NOMSG

DECLARE FUNCTION TranslateMDISysAccel IMPORT "USER32.DLL" ALIAS "TranslateMDISysAccel" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWndClient
 , BYREF lpMsg AS tagMSG _                              ' __in LPMSG lpMsg
 ) AS LONG                                              ' BOOL

'#endif /* !NOMSG */
'#ENDIF   ' #IF NOT %DEF(%NOMSG) '----------------------------------------------

DECLARE FUNCTION ArrangeIconicWindows IMPORT "USER32.DLL" ALIAS "ArrangeIconicWindows" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION CreateMDIWindowA IMPORT "USER32.DLL" ALIAS "CreateMDIWindowA" ( _
   BYREF lpClassName AS ASCIIZ _                        ' __in LPCSTR lpClassName
 , BYREF lpWindowName AS ASCIIZ _                       ' __in LPCSTR lpWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateMDIWindowW IMPORT "USER32.DLL" ALIAS "CreateMDIWindowW" ( _
   BYREF lpClassName AS WSTRINGZ _                      ' __in LPCWSTR lpClassName
 , BYREF lpWindowName AS WSTRINGZ _                     ' __in LPCWSTR lpWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL X AS LONG _                                    ' __in int X
 , BYVAL Y AS LONG _                                    ' __in int Y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO CreateMDIWindow = CreateMDIWindowW
#ELSE
   MACRO CreateMDIWindow = CreateMDIWindowA
#ENDIF

'#if(WINVER >= 0x0400)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TileWindows LIB "User32.dll" ALIAS "TileWindows" _
    (BYVAL hwndParent AS DWORD, BYVAL dwHow AS DWORD, lpRect AS RECT, _
    BYVAL cKids AS DWORD, BYVAL lpKids AS DWORD PTR) AS WORD
#ELSE
DECLARE FUNCTION TileWindows IMPORT "USER32.DLL" ALIAS "TileWindows" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL wHow AS DWORD _                                ' __in UINT wHow
 , BYREF lpRect AS RECT _                               ' __in_opt CONST RECT * lpRect
 , OPTIONAL BYVAL cKids AS DWORD _                      ' __in UINT cKids
 , OPTIONAL BYREF lpKids AS DWORD _                     ' __in_opt const HWND FAR * lpKids
 ) AS WORD                                              ' WORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CascadeWindows LIB "User32.dll" ALIAS "CascadeWindows" _
    (BYVAL hwndParent AS DWORD, BYVAL uHow AS DWORD, lpRect AS RECT, _
    BYVAL cKids AS DWORD, BYVAL lpKids AS DWORD PTR) AS WORD
#ELSE
DECLARE FUNCTION CascadeWindows IMPORT "USER32.DLL" ALIAS "CascadeWindows" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL wHow AS DWORD _                                ' __in UINT wHow
 , BYREF lpRect AS RECT _                               ' __in_opt CONST RECT * lpRect
 , BYVAL cKids AS DWORD _                               ' __in UINT cKids
 , BYREF lpKids AS DWORD _                              ' __in const HWND FAR * lpKids
 ) AS WORD                                              ' WORD
#ENDIF

'#endif /* WINVER >= 0x0400 */
'#endif /* !NOMDI */
'#ENDIF   ' #IF NOT %DEF(%NOMDI) ' ---------------------------------------------

'#endif /* !NOUSER */
'#ENDIF   ' #IF NOT %DEF(%NOUSER) ' --------------------------------------------

'/****** Help support ********************************************************/

'#IF NOT %DEF(%NOHELP) ' -------------------------------------------------------
'#ifndef NOHELP

'typedef DWORD HELPPOLY;

TYPE MULTIKEYHELPA BYTE
   mkSize      AS DWORD          ' DWORD
   mkKeylist   AS STRING * 1     ' CHAR
   szKeyphrase AS ASCIIZ * 128   ' CHAR szKeyphrase[1]  ' arbitrary string length: change as needed
END TYPE

TYPE MULTIKEYHELPW BYTE
   mkSize      AS DWORD           ' DWORD  mkSize
   mkKeylist   AS WSTRING * 1     ' WCHAR  mkKeylist
   szKeyphrase AS WSTRINGZ * 128  ' WCHAR  szKeyphrase[1]  ' arbitrary string length: change as needed
END TYPE

#IF %DEF(%UNICODE)
MACRO MULTIKEYHELP = MULTIKEYHELPW
#ELSE
MACRO MULTIKEYHELP = MULTIKEYHELPA
#ENDIF

' // Size = 28 bytes
TYPE HELPWININFOA DWORD
   wStructSize AS LONG         ' int
   x           AS LONG         ' int
   y           AS LONG         ' int
   dx          AS LONG         ' int
   dy          AS LONG         ' int
   wMax        AS LONG         ' int
'   rgchMember  AS ASCIIZ * 2   ' CHAR rgchMember[2]
   rgchMember  AS ASCIIZ * 128
END TYPE

' // Size = 28 bytes
TYPE HELPWININFOW DWORD
   wStructSize AS LONG           ' int
   x           AS LONG           ' int
   y           AS LONG           ' int
   dx          AS LONG           ' int
   dy          AS LONG           ' int
   wMax        AS LONG           ' int
'   rgchMember  AS WSTRINGZ * 2  ' WCHAR rgchMember[2]
   rgchMember  AS WSTRINGZ * 128
END TYPE

#IF %DEF(%UNICODE)
MACRO HELPWININFO = HELPWININFOW
#ELSE
MACRO HELPWININFO = HELPWININFOA
#ENDIF

'/*
' * Commands to pass to WinHelp()
' */
%HELP_CONTEXT      = &H0001???    ' // Display topic in ulTopic
%HELP_QUIT         = &H0002???    ' // Terminate help
%HELP_INDEX        = &H0003???    ' // Display index
%HELP_CONTENTS     = &H0003???
%HELP_HELPONHELP   = &H0004???    ' // Display help on using help
%HELP_SETINDEX     = &H0005???    ' // Set current Index for multi index help
%HELP_SETCONTENTS  = &H0005???
%HELP_CONTEXTPOPUP = &H0008???
%HELP_FORCEFILE    = &H0009???
%HELP_KEY          = &H0101???    ' // Display topic for keyword in offabData
%HELP_COMMAND      = &H0102???
%HELP_PARTIALKEY   = &H0105???
%HELP_MULTIKEY     = &H0201???
%HELP_SETWINPOS    = &H0203???
'#if(WINVER >= 0x0400)
%HELP_CONTEXTMENU  = &H000a???
%HELP_FINDER       = &H000b???
%HELP_WM_HELP      = &H000c???
%HELP_SETPOPUP_POS = &H000d???

%HELP_TCARD              = &H8000???
%HELP_TCARD_DATA         = &H0010???
%HELP_TCARD_OTHER_CALLER = &H0011???

'// These are in winhelp.h in Win95.
%IDH_NO_HELP             = 28440???
%IDH_MISSING_CONTEXT     = 28441??? ' // Control doesn't have matching help context
%IDH_GENERIC_HELP_BUTTON = 28442??? ' // Property sheet help button
%IDH_OK                  = 28443???
%IDH_CANCEL              = 28444???
%IDH_HELP                = 28445???

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION WinHelpA IMPORT "USER32.DLL" ALIAS "WinHelpA" ( _
   BYVAL hWndMain AS DWORD _                            ' __in_opt HWND hWndMain
 , BYREF lpszHelp AS ASCIIZ _                           ' __in_opt LPCSTR lpszHelp
 , BYVAL uCommand AS DWORD _                            ' __in UINT uCommand
 , BYVAL dwData AS DWORD _                              ' __in ULONG_PTR dwData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WinHelpW IMPORT "USER32.DLL" ALIAS "WinHelpW" ( _
   BYVAL hWndMain AS DWORD _                            ' __in_opt HWND hWndMain
 , BYREF lpszHelp AS WSTRINGZ _                         ' __in_opt LPCWSTR lpszHelp
 , BYVAL uCommand AS DWORD _                            ' __in UINT uCommand
 , BYVAL dwData AS DWORD _                              ' __in ULONG_PTR dwData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WinHelp = WinHelpW
#ELSE
   MACRO WinHelp = WinHelpA
#ENDIF

'#endif /* !NOHELP */
'#ENDIF   ' #IF NOT %DEF(%NOHELP) ' --------------------------------------------

'#if(WINVER >= 0x0500)
%GR_GDIOBJECTS  = 0&  ' Count of GDI objects
%GR_USEROBJECTS = 1&  ' Count of USER objects
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0601)
%GR_GDIOBJECTS_PEAK  = 2   ' /* Peak count of GDI objects */
%GR_USEROBJECTS_PEAK = 4   ' /* Peak count of USER objects */
'#endif /* WINVER >= 0x0601 */

'#if(WINVER >= 0x0601)
%GR_GLOBAL   = -2???   ' ((HANDLE)-2)
'#endif /* WINVER >= 0x0601 */

'#if(WINVER >= 0x0500)
DECLARE FUNCTION GetGuiResources IMPORT "USER32.DLL" ALIAS "GetGuiResources" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL uiFlags AS DWORD _                             ' __in DWORD uiFlags
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */


'#IF NOT %DEF(%NOSYSPARAMSINFO) ' ----------------------------------------------
'#ifndef NOSYSPARAMSINFO

'/*
' * Parameter for SystemParametersInfo
' */
%SPI_GETBEEP                 = &H0001???
%SPI_SETBEEP                 = &H0002???
%SPI_GETMOUSE                = &H0003???
%SPI_SETMOUSE                = &H0004???
%SPI_GETBORDER               = &H0005???
%SPI_SETBORDER               = &H0006???
%SPI_GETKEYBOARDSPEED        = &H000A???
%SPI_SETKEYBOARDSPEED        = &H000B???
%SPI_LANGDRIVER              = &H000C???
%SPI_ICONHORIZONTALSPACING   = &H000D???
%SPI_GETSCREENSAVETIMEOUT    = &H000E???
%SPI_SETSCREENSAVETIMEOUT    = &H000F???
%SPI_GETSCREENSAVEACTIVE     = &H0010???
%SPI_SETSCREENSAVEACTIVE     = &H0011???
%SPI_GETGRIDGRANULARITY      = &H0012???
%SPI_SETGRIDGRANULARITY      = &H0013???
%SPI_SETDESKWALLPAPER        = &H0014???
%SPI_SETDESKPATTERN          = &H0015???
%SPI_GETKEYBOARDDELAY        = &H0016???
%SPI_SETKEYBOARDDELAY        = &H0017???
%SPI_ICONVERTICALSPACING     = &H0018???
%SPI_GETICONTITLEWRAP        = &H0019???
%SPI_SETICONTITLEWRAP        = &H001A???
%SPI_GETMENUDROPALIGNMENT    = &H001B???
%SPI_SETMENUDROPALIGNMENT    = &H001C???
%SPI_SETDOUBLECLKWIDTH       = &H001D???
%SPI_SETDOUBLECLKHEIGHT      = &H001E???
%SPI_GETICONTITLELOGFONT     = &H001F???
%SPI_SETDOUBLECLICKTIME      = &H0020???
%SPI_SETMOUSEBUTTONSWAP      = &H0021???
%SPI_SETICONTITLELOGFONT     = &H0022???
%SPI_GETFASTTASKSWITCH       = &H0023???
%SPI_SETFASTTASKSWITCH       = &H0024???
'#if(WINVER >= = &H0400)
%SPI_SETDRAGFULLWINDOWS      = &H0025???
%SPI_GETDRAGFULLWINDOWS      = &H0026???
%SPI_GETNONCLIENTMETRICS     = &H0029???
%SPI_SETNONCLIENTMETRICS     = &H002A???
%SPI_GETMINIMIZEDMETRICS     = &H002B???
%SPI_SETMINIMIZEDMETRICS     = &H002C???
%SPI_GETICONMETRICS          = &H002D???
%SPI_SETICONMETRICS          = &H002E???
%SPI_SETWORKAREA             = &H002F???
%SPI_GETWORKAREA             = &H0030???
%SPI_SETPENWINDOWS           = &H0031???

%SPI_GETHIGHCONTRAST         = &H0042???
%SPI_SETHIGHCONTRAST         = &H0043???
%SPI_GETKEYBOARDPREF         = &H0044???
%SPI_SETKEYBOARDPREF         = &H0045???
%SPI_GETSCREENREADER         = &H0046???
%SPI_SETSCREENREADER         = &H0047???
%SPI_GETANIMATION            = &H0048???
%SPI_SETANIMATION            = &H0049???
%SPI_GETFONTSMOOTHING        = &H004A???
%SPI_SETFONTSMOOTHING        = &H004B???
%SPI_SETDRAGWIDTH            = &H004C???
%SPI_SETDRAGHEIGHT           = &H004D???
%SPI_SETHANDHELD             = &H004E???
%SPI_GETLOWPOWERTIMEOUT      = &H004F???
%SPI_GETPOWEROFFTIMEOUT      = &H0050???
%SPI_SETLOWPOWERTIMEOUT      = &H0051???
%SPI_SETPOWEROFFTIMEOUT      = &H0052???
%SPI_GETLOWPOWERACTIVE       = &H0053???
%SPI_GETPOWEROFFACTIVE       = &H0054???
%SPI_SETLOWPOWERACTIVE       = &H0055???
%SPI_SETPOWEROFFACTIVE       = &H0056???
%SPI_SETCURSORS              = &H0057???
%SPI_SETICONS                = &H0058???
%SPI_GETDEFAULTINPUTLANG     = &H0059???
%SPI_SETDEFAULTINPUTLANG     = &H005A???
%SPI_SETLANGTOGGLE           = &H005B???
%SPI_GETWINDOWSEXTENSION     = &H005C???
%SPI_SETMOUSETRAILS          = &H005D???
%SPI_GETMOUSETRAILS          = &H005E???
%SPI_SETSCREENSAVERRUNNING   = &H0061???
%SPI_SCREENSAVERRUNNING      = %SPI_SETSCREENSAVERRUNNING
'#endif /* WINVER >= = &H0400 */
%SPI_GETFILTERKEYS           = &H0032???
%SPI_SETFILTERKEYS           = &H0033???
%SPI_GETTOGGLEKEYS           = &H0034???
%SPI_SETTOGGLEKEYS           = &H0035???
%SPI_GETMOUSEKEYS            = &H0036???
%SPI_SETMOUSEKEYS            = &H0037???
%SPI_GETSHOWSOUNDS           = &H0038???
%SPI_SETSHOWSOUNDS           = &H0039???
%SPI_GETSTICKYKEYS           = &H003A???
%SPI_SETSTICKYKEYS           = &H003B???
%SPI_GETACCESSTIMEOUT        = &H003C???
%SPI_SETACCESSTIMEOUT        = &H003D???
'#if(WINVER >= = &H0400)
%SPI_GETSERIALKEYS           = &H003E???
%SPI_SETSERIALKEYS           = &H003F???
'#endif /* WINVER >= = &H0400 */
%SPI_GETSOUNDSENTRY          = &H0040???
%SPI_SETSOUNDSENTRY          = &H0041???
'#if(_WIN32_WINNT >= = &H0400)
%SPI_GETSNAPTODEFBUTTON      = &H005F???
%SPI_SETSNAPTODEFBUTTON      = &H0060???
'#endif /* _WIN32_WINNT >= = &H0400 */
'#if (_WIN32_WINNT >= = &H0400) || (_WIN32_WINDOWS > = &H0400)
%SPI_GETMOUSEHOVERWIDTH      = &H0062???
%SPI_SETMOUSEHOVERWIDTH      = &H0063???
%SPI_GETMOUSEHOVERHEIGHT     = &H0064???
%SPI_SETMOUSEHOVERHEIGHT     = &H0065???
%SPI_GETMOUSEHOVERTIME       = &H0066???
%SPI_SETMOUSEHOVERTIME       = &H0067???
%SPI_GETWHEELSCROLLLINES     = &H0068???
%SPI_SETWHEELSCROLLLINES     = &H0069???
%SPI_GETMENUSHOWDELAY        = &H006A???
%SPI_SETMENUSHOWDELAY        = &H006B???

'#if (_WIN32_WINNT >= 0x0600)
%SPI_GETWHEELSCROLLCHARS     = &H006C??
%SPI_SETWHEELSCROLLCHARS     = &H006D??
'#endif

%SPI_GETSHOWIMEUI            = &H006E???
%SPI_SETSHOWIMEUI            = &H006F???
'#endif

'#if(WINVER >= 0x0500)
%SPI_GETMOUSESPEED           = &H0070???
%SPI_SETMOUSESPEED           = &H0071???
%SPI_GETSCREENSAVERRUNNING   = &H0072???
%SPI_GETDESKWALLPAPER        = &H0073???
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0600)
%SPI_GETAUDIODESCRIPTION     = &H0074???
%SPI_SETAUDIODESCRIPTION     = &H0075???

%SPI_GETSCREENSAVESECURE     = &H0076???
%SPI_SETSCREENSAVESECURE     = &H0077???
'#endif /* WINVER >= 0x0600 */

'#if(_WIN32_WINNT >= 0x0601)
%SPI_GETHUNGAPPTIMEOUT           = &H0078???
%SPI_SETHUNGAPPTIMEOUT           = &H0079???
%SPI_GETWAITTOKILLTIMEOUT        = &H007A???
%SPI_SETWAITTOKILLTIMEOUT        = &H007B???
%SPI_GETWAITTOKILLSERVICETIMEOUT = &H007C???
%SPI_SETWAITTOKILLSERVICETIMEOUT = &H007D???
%SPI_GETMOUSEDOCKTHRESHOLD       = &H007E???
%SPI_SETMOUSEDOCKTHRESHOLD       = &H007F???
%SPI_GETPENDOCKTHRESHOLD         = &H0080???
%SPI_SETPENDOCKTHRESHOLD         = &H0081???
%SPI_GETWINARRANGING             = &H0082???
%SPI_SETWINARRANGING             = &H0083???
%SPI_GETMOUSEDRAGOUTTHRESHOLD    = &H0084???
%SPI_SETMOUSEDRAGOUTTHRESHOLD    = &H0085???
%SPI_GETPENDRAGOUTTHRESHOLD      = &H0086???
%SPI_SETPENDRAGOUTTHRESHOLD      = &H0087???
%SPI_GETMOUSESIDEMOVETHRESHOLD   = &H0088???
%SPI_SETMOUSESIDEMOVETHRESHOLD   = &H0089???
%SPI_GETPENSIDEMOVETHRESHOLD     = &H008A???
%SPI_SETPENSIDEMOVETHRESHOLD     = &H008B???
%SPI_GETDRAGFROMMAXIMIZE         = &H008C???
%SPI_SETDRAGFROMMAXIMIZE         = &H008D???
%SPI_GETSNAPSIZING               = &H008E???
%SPI_SETSNAPSIZING               = &H008F???
%SPI_GETDOCKMOVING               = &H0090???
%SPI_SETDOCKMOVING               = &H0091???
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if(WINVER >= 0x0500)

%SPI_GETACTIVEWINDOWTRACKING         = &H1000???
%SPI_SETACTIVEWINDOWTRACKING         = &H1001???
%SPI_GETMENUANIMATION                = &H1002???
%SPI_SETMENUANIMATION                = &H1003???
%SPI_GETCOMBOBOXANIMATION            = &H1004???
%SPI_SETCOMBOBOXANIMATION            = &H1005???
%SPI_GETLISTBOXSMOOTHSCROLLING       = &H1006???
%SPI_SETLISTBOXSMOOTHSCROLLING       = &H1007???
%SPI_GETGRADIENTCAPTIONS             = &H1008???
%SPI_SETGRADIENTCAPTIONS             = &H1009???
%SPI_GETKEYBOARDCUES                 = &H100A???
%SPI_SETKEYBOARDCUES                 = &H100B???
%SPI_GETMENUUNDERLINES               = %SPI_GETKEYBOARDCUES
%SPI_SETMENUUNDERLINES               = %SPI_SETKEYBOARDCUES
%SPI_GETACTIVEWNDTRKZORDER           = &H100C???
%SPI_SETACTIVEWNDTRKZORDER           = &H100D???
%SPI_GETHOTTRACKING                  = &H100E???
%SPI_SETHOTTRACKING                  = &H100F???
%SPI_GETMENUFADE                     = &H1012???
%SPI_SETMENUFADE                     = &H1013???
%SPI_GETSELECTIONFADE                = &H1014???
%SPI_SETSELECTIONFADE                = &H1015???
%SPI_GETTOOLTIPANIMATION             = &H1016???
%SPI_SETTOOLTIPANIMATION             = &H1017???
%SPI_GETTOOLTIPFADE                  = &H1018???
%SPI_SETTOOLTIPFADE                  = &H1019???
%SPI_GETCURSORSHADOW                 = &H101A???
%SPI_SETCURSORSHADOW                 = &H101B???
'#if(_WIN32_WINNT >= = &H0501)
%SPI_GETMOUSESONAR                   = &H101C???
%SPI_SETMOUSESONAR                   = &H101D???
%SPI_GETMOUSECLICKLOCK               = &H101E???
%SPI_SETMOUSECLICKLOCK               = &H101F???
%SPI_GETMOUSEVANISH                  = &H1020???
%SPI_SETMOUSEVANISH                  = &H1021???
%SPI_GETFLATMENU                     = &H1022???
%SPI_SETFLATMENU                     = &H1023???
%SPI_GETDROPSHADOW                   = &H1024???
%SPI_SETDROPSHADOW                   = &H1025???
%SPI_GETBLOCKSENDINPUTRESETS         = &H1026???
%SPI_SETBLOCKSENDINPUTRESETS         = &H1027???
'#endif /* _WIN32_WINNT >= = &H0501 */

%SPI_GETUIEFFECTS                    = &H103E???
%SPI_SETUIEFFECTS                    = &H103F???

'#if(_WIN32_WINNT >= 0x0600)
%SPI_GETDISABLEOVERLAPPEDCONTENT     = &H1040???
%SPI_SETDISABLEOVERLAPPEDCONTENT     = &H1041???
%SPI_GETCLIENTAREAANIMATION          = &H1042???
%SPI_SETCLIENTAREAANIMATION          = &H1043???
%SPI_GETCLEARTYPE                    = &H1048???
%SPI_SETCLEARTYPE                    = &H1049???
%SPI_GETSPEECHRECOGNITION            = &H104A???
%SPI_SETSPEECHRECOGNITION            = &H104B???
'#endif /* _WIN32_WINNT >= 0x0600 */

%SPI_GETFOREGROUNDLOCKTIMEOUT        = &H2000???
%SPI_SETFOREGROUNDLOCKTIMEOUT        = &H2001???
%SPI_GETACTIVEWNDTRKTIMEOUT          = &H2002???
%SPI_SETACTIVEWNDTRKTIMEOUT          = &H2003???
%SPI_GETFOREGROUNDFLASHCOUNT         = &H2004???
%SPI_SETFOREGROUNDFLASHCOUNT         = &H2005???
%SPI_GETCARETWIDTH                   = &H2006???
%SPI_SETCARETWIDTH                   = &H2007???

'#if(_WIN32_WINNT >= = &H0501)
%SPI_GETMOUSECLICKLOCKTIME           = &H2008???
%SPI_SETMOUSECLICKLOCKTIME           = &H2009???
%SPI_GETFONTSMOOTHINGTYPE            = &H200A???
%SPI_SETFONTSMOOTHINGTYPE            = &H200B???

'/* constants for SPI_GETFONTSMOOTHINGTYPE and SPI_SETFONTSMOOTHINGTYPE: */
%FE_FONTSMOOTHINGSTANDARD            = &H0001???
%FE_FONTSMOOTHINGCLEARTYPE           = &H0002???
'%FE_FONTSMOOTHINGDOCKING             = &H8000???   ' // Removed in the Windows 7 SDK

%SPI_GETFONTSMOOTHINGCONTRAST        = &H200C???
%SPI_SETFONTSMOOTHINGCONTRAST        = &H200D???

%SPI_GETFOCUSBORDERWIDTH             = &H200E???
%SPI_SETFOCUSBORDERWIDTH             = &H200F???
%SPI_GETFOCUSBORDERHEIGHT            = &H2010???
%SPI_SETFOCUSBORDERHEIGHT            = &H2011???

%SPI_GETFONTSMOOTHINGORIENTATION     = &H2012???
%SPI_SETFONTSMOOTHINGORIENTATION     = &H2013???

'/* constants for SPI_GETFONTSMOOTHINGORIENTATION and SPI_SETFONTSMOOTHINGORIENTATION: */
%FE_FONTSMOOTHINGORIENTATIONBGR      = &H0000???
%FE_FONTSMOOTHINGORIENTATIONRGB      = &H0001???
'#endif /* _WIN32_WINNT >= = &H0501 */

'#if(_WIN32_WINNT >= 0x0600)
%SPI_GETMINIMUMHITRADIUS             = &H2014???
%SPI_SETMINIMUMHITRADIUS             = &H2015???
%SPI_GETMESSAGEDURATION              = &H2016???
%SPI_SETMESSAGEDURATION              = &H2017???
'#endif /* _WIN32_WINNT >= 0x0600 */

'#endif /* WINVER >= = &H0500 */


'/*
' * Flags
' */
%SPIF_UPDATEINIFILE    = &H0001???
%SPIF_SENDWININICHANGE = &H0002???
%SPIF_SENDCHANGE       = %SPIF_SENDWININICHANGE

%METRICS_USEDEFAULT = -1&

' Note: If the iPaddedBorderWidth member of the NONCLIENTMETRICS structure is present,
' this structure is 4 bytes larger than for an application that is compiled with
' WINVER less than or equal to &H0502.
' If an application that is compiled for Windows Server 2008 or Windows Vista
' must also run on Windows Server 2003 or Windows XP/2000, use the GetVersionEx
' function to check the operating system version at run time and, if the
' application is running on Windows Server 2003 or Windows XP/2000, subtract the
' size of the iPaddedBorderWidth member from the cbSize member of the
' NONCLIENTMETRICS structure before calling the SystemParametersInfo function,
' e.g. cbSize = SIZEOF(NONCLIENTMETRICS) - 4.

' // Size = 344 bytes
TYPE NONCLIENTMETRICSA DWORD
   cbSize             AS DWORD      ' UINT
   iBorderWidth       AS LONG       ' int
   iScrollWidth       AS LONG       ' int
   iScrollHeight      AS LONG       ' int
   iCaptionWidth      AS LONG       ' int
   iCaptionHeight     AS LONG       ' int
   lfCaptionFont      AS LOGFONTA   ' LOGFONTA
   iSMCaptionWidth    AS LONG       ' int
   iSMCaptionHeight   AS LONG       ' int
   lfSMCaptionFont    AS LOGFONTA   ' LOGFONTA
   iMenuWidth         AS LONG       ' int
   iMenuHeight        AS LONG       ' int
   lfMenuFont         AS LOGFONTA   ' LOGFONTA
   lfStatusFont       AS LOGFONTA   ' LOGFONTA
   lfMessageFont      AS LOGFONTA   ' LOGFONTA
#IF %WINVER >= &H0600
   iPaddedBorderWidth AS LONG
#ENDIF   ' /* WINVER >= 0x0600 */
END TYPE

' // Size = 504 bytes
TYPE NONCLIENTMETRICSW DWORD
   cbSize             AS DWORD      ' UINT
   iBorderWidth       AS LONG       ' int
   iScrollWidth       AS LONG       ' int
   iScrollHeight      AS LONG       ' int
   iCaptionWidth      AS LONG       ' int
   iCaptionHeight     AS LONG       ' int
   lfCaptionFont      AS LOGFONTW   ' LOGFONTW
   iSMCaptionWidth    AS LONG       ' int
   iSMCaptionHeight   AS LONG       ' int
   lfSMCaptionFont    AS LOGFONTW   ' LOGFONTW
   iMenuWidth         AS LONG       ' int
   iMenuHeight        AS LONG       ' int
   lfMenuFont         AS LOGFONTW   ' LOGFONTW
   lfStatusFont       AS LOGFONTW   ' LOGFONTW
   lfMessageFont      AS LOGFONTW   ' LOGFONTW
#IF %WINVER >= &H0600
   iPaddedBorderWidth AS LONG
#ENDIF   ' /* WINVER >= 0x0600 */
END TYPE

#IF %DEF(%UNICODE)
MACRO NONCLIENTMETRICS = NONCLIENTMETRICSW
#ELSE
MACRO NONCLIENTMETRICS = NONCLIENTMETRICSA
#ENDIF

%ARW_BOTTOMLEFT  = &H0000???
%ARW_BOTTOMRIGHT = &H0001???
%ARW_TOPLEFT     = &H0002???
%ARW_TOPRIGHT    = &H0003???
%ARW_STARTMASK   = &H0003???
%ARW_STARTRIGHT  = &H0001???
%ARW_STARTTOP    = &H0002???

%ARW_LEFT        = &H0000???
%ARW_RIGHT       = &H0000???
%ARW_UP          = &H0004???
%ARW_DOWN        = &H0004???
%ARW_HIDE        = &H0008???

' // Size = 20 bytes
TYPE MINIMIZEDMETRICS DWORD
   cbSize   AS DWORD   ' UINT
   iWidth   AS LONG    ' int
   iHorzGap AS LONG    ' int
   iVertGap AS LONG    ' int
   iArrange AS LONG    ' int
END TYPE

'#IF %DEF(%WINGDI) ' -----------------------------------------------------------
'#IF NOT %DEF(%NOGDI) ' --------------------------------------------------------
'#ifdef _WINGDI_
'#ifndef NOGDI

' // Size = 76 bytes
TYPE ICONMETRICSA DWORD
   cbSize       AS DWORD     ' UINT
   iHorzSpacing AS LONG      ' int
   iVertSpacing AS LONG      ' int
   iTitleWrap   AS LONG      ' int
   lfFont       AS LOGFONT   ' LOGFONTA
END TYPE

' // Size = 108 bytes
TYPE ICONMETRICSW DWORD
   cbSize       AS DWORD     ' UINT
   iHorzSpacing AS LONG      ' int
   iVertSpacing AS LONG      ' int
   iTitleWrap   AS LONG      ' int
   lfFont       AS LOGFONTW  ' LOGFONTW
END TYPE

#IF %DEF(%UNICODE)
MACRO ICONMETRICS = ICONMETRICSW
#ELSE
MACRO ICONMETRICS = ICONMETRICSA
#ENDIF

'#endif /* NOGDI */
'#endif /* _WINGDI_ */
'#ENDIF   ' #IF NOT %DEF(%NOGDI) ' ---------------------------------------------
'#ENDIF   ' #IF DEF(%WINGDI) ' -------------------------------------------------

' // Size = 8 bytes
TYPE ANIMATIONINFO DWORD
   cbSize      AS DWORD   ' UINT
   iMinAnimate AS LONG    ' int
END TYPE

' // Size = 28 bytes
TYPE SERIALKEYSA DWORD
   cbSize         AS DWORD        ' UINT
   dwFlags        AS DWORD        ' DWORD
   lpszActivePort AS ASCIIZ PTR   ' LPSTR
   lpszPort       AS ASCIIZ PTR   ' LPSTR
   iBaudRate      AS DWORD        ' UINT
   iPortState     AS DWORD        ' UINT
   iActive        AS DWORD        ' UINT
END TYPE

' // Size = 28 bytes
TYPE SERIALKEYSW DWORD
   cbSize         AS DWORD          ' UINT
   dwFlags        AS DWORD          ' DWORD
   lpszActivePort AS WSTRINGZ PTR   ' LPWSTR
   lpszPort       AS WSTRINGZ PTR   ' LPWSTR
   iBaudRate      AS DWORD          ' UINT
   iPortState     AS DWORD          ' UINT
   iActive        AS DWORD          ' UINT
END TYPE

#IF %DEF(%UNICODE)
MACRO SERIALKEYS = SERIALKEYSW
#ELSE
MACRO SERIALKEYS = SERIALKEYSA
#ENDIF

'/* flags for SERIALKEYS dwFlags field */
%SERKF_SERIALKEYSON = &H00000001???
%SERKF_AVAILABLE    = &H00000002???
%SERKF_INDICATOR    = &H00000004???

' // Size = 12 bytes
TYPE HIGHCONTRASTA DWORD
   cbSize            AS DWORD        ' UINT
   dwFlags           AS DWORD        ' DWORD
   lpszDefaultScheme AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE HIGHCONTRASTW DWORD
   cbSize            AS DWORD          ' UINT
   dwFlags           AS DWORD          ' DWORD
   lpszDefaultScheme AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
MACRO HIGHCONTRAST = HIGHCONTRASTW
#ELSE
MACRO HIGHCONTRAST = HIGHCONTRASTA
#ENDIF

'/* flags for HIGHCONTRAST dwFlags field */
%HCF_HIGHCONTRASTON       = &H00000001???
%HCF_AVAILABLE            = &H00000002???
%HCF_HOTKEYACTIVE         = &H00000004???
%HCF_CONFIRMHOTKEY        = &H00000008???
%HCF_HOTKEYSOUND          = &H00000010???
%HCF_INDICATOR            = &H00000020???
%HCF_HOTKEYAVAILABLE      = &H00000040???
%HCF_LOGONDESKTOP         = &H00000100???
%HCF_DEFAULTDESKTOP       = &H00000200???

'/* Flags for ChangeDisplaySettings */
%CDS_UPDATEREGISTRY       = &H00000001???
%CDS_TEST                 = &H00000002???
%CDS_FULLSCREEN           = &H00000004???
%CDS_GLOBAL               = &H00000008???
%CDS_SET_PRIMARY          = &H00000010???
%CDS_VIDEOPARAMETERS      = &H00000020???
'#if(WINVER >= 0x0600)
%CDS_ENABLE_UNSAFE_MODES  = &H00000100???
%CDS_DISABLE_UNSAFE_MODES = &H00000200???
'#endif /* WINVER >= 0x0600 */
%CDS_RESET                = &H40000000???
%CDS_RESET_EX             = &H20000000???
%CDS_NORESET              = &H10000000???

'#include <tvout.h>
#INCLUDE ONCE "TVOUT.INC"

'/* Return values for ChangeDisplaySettings */
%DISP_CHANGE_SUCCESSFUL  =  0&
%DISP_CHANGE_RESTART     =  1&
%DISP_CHANGE_FAILED      = -1&
%DISP_CHANGE_BADMODE     = -2&
%DISP_CHANGE_NOTUPDATED  = -3&
%DISP_CHANGE_BADFLAGS    = -4&
%DISP_CHANGE_BADPARAM    = -5&
'#if(_WIN32_WINNT >= 0x0501)
%DISP_CHANGE_BADDUALVIEW = -6&
'#endif /* _WIN32_WINNT >= 0x0501 */

'#ifdef _WINGDI_
'#ifndef NOGDI

DECLARE FUNCTION ChangeDisplaySettingsA IMPORT "USER32.DLL" ALIAS "ChangeDisplaySettingsA" ( _
   BYREF lpDevMode AS DEVMODEA _                        ' __in_opt DEVMODEA* lpDevMode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' long

DECLARE FUNCTION ChangeDisplaySettingsW IMPORT "USER32.DLL" ALIAS "ChangeDisplaySettingsW" ( _
   BYREF lpDevMode AS DEVMODEW _                        ' __in_opt DEVMODEW* lpDevMode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO ChangeDisplaySettings = ChangeDisplaySettingsW
#ELSE
   MACRO ChangeDisplaySettings = ChangeDisplaySettingsA
#ENDIF

DECLARE FUNCTION ChangeDisplaySettingsExA IMPORT "USER32.DLL" ALIAS "ChangeDisplaySettingsExA" ( _
   BYREF lpszDeviceName AS ASCIIZ _                     ' __in_opt LPCSTR lpszDeviceName
 , BYREF lpDevMode AS DEVMODEA _                        ' __in_opt DEVMODEA* lpDevMode
 , BYVAL hwnd AS DWORD _                                ' __reserved HWND hwnd
 , BYVAL dwflags AS DWORD _                             ' __in DWORD dwflags
 , OPTIONAL BYREF lParam AS ANY _                       ' __in_opt LPVOID lParam
 ) AS LONG                                              ' long

DECLARE FUNCTION ChangeDisplaySettingsExW IMPORT "USER32.DLL" ALIAS "ChangeDisplaySettingsExW" ( _
   BYREF lpszDeviceName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszDeviceName
 , BYREF lpDevMode AS DEVMODEW _                        ' __in_opt DEVMODEW* lpDevMode
 , BYVAL hwnd AS DWORD _                                ' __reserved HWND hwnd
 , BYVAL dwflags AS DWORD _                             ' __in DWORD dwflags
 , OPTIONAL BYREF lParam AS ANY _                       ' __in_opt LPVOID lParam
 ) AS LONG                                              ' long

#IF %DEF(%UNICODE)
   MACRO ChangeDisplaySettingsEx = ChangeDisplaySettingsExW
#ELSE
   MACRO ChangeDisplaySettingsEx = ChangeDisplaySettingsExA
#ENDIF

%ENUM_CURRENT_SETTINGS  = &HFFFFFFFF???   ' ((DWORD)-1)
%ENUM_REGISTRY_SETTINGS = &HFFFFFFFE???   ' ((DWORD)-2)

DECLARE FUNCTION EnumDisplaySettingsA IMPORT "USER32.DLL" ALIAS "EnumDisplaySettingsA" ( _
   BYREF lpszDeviceName AS ASCIIZ _                     ' __in_opt LPCSTR lpszDeviceName
 , BYVAL iModeNum AS DWORD _                            ' __in DWORD iModeNum
 , BYREF lpDevMode AS DEVMODEA _                        ' __out DEVMODEA* lpDevMode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDisplaySettingsW IMPORT "USER32.DLL" ALIAS "EnumDisplaySettingsW" ( _
   BYREF lpszDeviceName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszDeviceName
 , BYVAL iModeNum AS DWORD _                            ' __in DWORD iModeNum
 , BYREF lpDevMode AS DEVMODEW _                        ' __out DEVMODEW* lpDevMode
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDisplaySettings = EnumDisplaySettingsW
#ELSE
   MACRO EnumDisplaySettings = EnumDisplaySettingsA
#ENDIF

'#if(WINVER >= 0x0500)

DECLARE FUNCTION EnumDisplaySettingsExA IMPORT "USER32.DLL" ALIAS "EnumDisplaySettingsExA" ( _
   BYREF lpszDeviceName AS ASCIIZ _                     ' __in_opt LPCSTR lpszDeviceName
 , BYVAL iModeNum AS DWORD _                            ' __in DWORD iModeNum
 , BYREF lpDevMode AS DEVMODEA _                        ' __out DEVMODEA* lpDevMode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDisplaySettingsExW IMPORT "USER32.DLL" ALIAS "EnumDisplaySettingsExW" ( _
   BYREF lpszDeviceName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpszDeviceName
 , BYVAL iModeNum AS DWORD _                            ' __in DWORD iModeNum
 , BYREF lpDevMode AS DEVMODEW _                        ' __out DEVMODEW* lpDevMode
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDisplaySettingsEx = EnumDisplaySettingsExW
#ELSE
   MACRO EnumDisplaySettingsEx = EnumDisplaySettingsExA
#ENDIF

'/* Flags for EnumDisplaySettingsEx */
%EDS_RAWMODE     = &H00000002???
%EDS_ROTATEDMODE = &H00000004???

DECLARE FUNCTION EnumDisplayDevicesA IMPORT "USER32.DLL" ALIAS "EnumDisplayDevicesA" ( _
   BYREF lpDevice AS ASCIIZ _                           ' __in_opt LPCSTR lpDevice
 , BYVAL iDevNum AS DWORD _                             ' __in DWORD iDevNum
 , BYREF lpDisplayDevice AS DISPLAY_DEVICEA _           ' __inout PDISPLAY_DEVICEA lpDisplayDevice
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDisplayDevicesW IMPORT "USER32.DLL" ALIAS "EnumDisplayDevicesW" ( _
   BYREF lpDevice AS WSTRINGZ _                         ' __in_opt LPCWSTR lpDevice
 , BYVAL iDevNum AS DWORD _                             ' __in DWORD iDevNum
 , BYREF lpDisplayDevice AS DISPLAY_DEVICEW _           ' __inout PDISPLAY_DEVICEW lpDisplayDevice
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDisplayDevices = EnumDisplayDevicesW
#ELSE
   MACRO EnumDisplayDevices = EnumDisplayDevicesA
#ENDIF

'/* Flags for EnumDisplayDevices */
%EDD_GET_DEVICE_INTERFACE_NAME = &H00000001???

'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0601)

DECLARE FUNCTION GetDisplayConfigBufferSizes IMPORT "USER32.DLL" ALIAS "GetDisplayConfigBufferSizes" ( _
   BYVAL flags AS DWORD _                               ' __in UINT32 flags
 , BYREF numPathArrayElements AS DWORD _                ' __out UINT32* numPathArrayElements
 , BYREF numModeInfoArrayElements AS DWORD _            ' __out UINT32* numModeInfoArrayElements
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SetDisplayConfig IMPORT "USER32.DLL" ALIAS "SetDisplayConfig" ( _
   BYVAL numPathArrayElements AS DWORD _                ' __in UINT32 numPathArrayElements
 , BYREF pathArray AS DISPLAYCONFIG_PATH_INFO _         ' __in DISPLAYCONFIG_PATH_INFO* pathArray
 , BYVAL numModeInfoArrayElements AS DWORD _            ' __in UINT32 numModeInfoArrayElements
 , BYREF modeInfoArray AS DISPLAYCONFIG_MODE_INFO _     ' __in DISPLAYCONFIG_MODE_INFO* modeInfoArray
 , BYVAL flags AS DWORD _                               ' __in UINT32 flags
 ) AS LONG                                              ' LONG

DECLARE FUNCTION QueryDisplayConfig IMPORT "USER32.DLL" ALIAS "QueryDisplayConfig" ( _
   BYVAL flags AS DWORD _                               ' __in UINT32 flags
 , BYREF numPathArrayElements AS DWORD _                ' __inout UINT32* numPathArrayElements
 , BYREF pathArray AS DISPLAYCONFIG_PATH_INFO _         ' __out DISPLAYCONFIG_PATH_INFO* pathArray
 , BYREF numModeInfoArrayElements AS DWORD _            ' __inout UINT32* numModeInfoArrayElements
 , BYREF modeInfoArray AS DISPLAYCONFIG_MODE_INFO _     ' __out DISPLAYCONFIG_MODE_INFO* modeInfoArray
 , BYREF currentTopologyId AS DWORD _                   ' __out DISPLAYCONFIG_TOPOLOGY_ID* currentTopologyId
 ) AS LONG                                              ' LONG

DECLARE FUNCTION DisplayConfigGetDeviceInfo IMPORT "USER32.DLL" ALIAS "DisplayConfigGetDeviceInfo" ( _
   BYREF requestPacket AS DISPLAYCONFIG_DEVICE_INFO_HEADER _ ' __inout DISPLAYCONFIG_DEVICE_INFO_HEADER* requestPacket
 ) AS LONG                                              ' LONG

DECLARE FUNCTION DisplayConfigSetDeviceInfo IMPORT "USER32.DLL" ALIAS "DisplayConfigSetDeviceInfo" ( _
   BYREF setPacket AS DISPLAYCONFIG_DEVICE_INFO_HEADER _ ' __in DISPLAYCONFIG_DEVICE_INFO_HEADER* setPacket
 ) AS LONG                                              ' LONG

'#endif /* WINVER >= 0x0601 */

'#endif /* NOGDI */
'#endif /* _WINGDI_ */

DECLARE FUNCTION SystemParametersInfoA IMPORT "USER32.DLL" ALIAS "SystemParametersInfoA" ( _
   BYVAL uiAction AS DWORD _                            ' __in UINT uiAction
 , BYVAL uiParam AS DWORD _                             ' __in UINT uiParam
 , BYREF pvParam AS ANY _                               ' __inout_opt PVOID pvParam
 , BYVAL fWinIni AS DWORD _                             ' __in UINT fWinIni
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SystemParametersInfoW IMPORT "USER32.DLL" ALIAS "SystemParametersInfoW" ( _
   BYVAL uiAction AS DWORD _                            ' __in UINT uiAction
 , BYVAL uiParam AS DWORD _                             ' __in UINT uiParam
 , BYREF pvParam AS ANY _                               ' __inout_opt PVOID pvParam
 , BYVAL fWinIni AS DWORD _                             ' __in UINT fWinIni
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SystemParametersInfo = SystemParametersInfoW
#ELSE
   MACRO SystemParametersInfo = SystemParametersInfoA
#ENDIF

'#endif  /* !NOSYSPARAMSINFO  */
'#ENDIF   ' #IF NOT %DEF(%NOSYSPARAMSINFO) ' -----------------------------------

'/*
' * Accessibility support
' */

' // Size = 24 bytes
TYPE FILTERKEYS DWORD
   cbSize      AS DWORD   ' UINT
   dwFlags     AS DWORD   ' DWORD
   iWaitMSec   AS DWORD   ' DWORD // Acceptance Delay
   iDelayMSec  AS DWORD   ' DWORD // Delay Until Repeat
   iRepeatMSec AS DWORD   ' DWORD // Repeat Rate
   iBounceMSec AS DWORD   ' DWORD // Debounce Time
END TYPE

'/*
' * FILTERKEYS dwFlags field
' */
%FKF_FILTERKEYSON    = &H00000001???
%FKF_AVAILABLE       = &H00000002???
%FKF_HOTKEYACTIVE    = &H00000004???
%FKF_CONFIRMHOTKEY   = &H00000008???
%FKF_HOTKEYSOUND     = &H00000010???
%FKF_INDICATOR       = &H00000020???
%FKF_CLICKON         = &H00000040???

' // Size = 8 bytes
TYPE STICKYKEYS DWORD
   cbSize  AS DWORD   ' UINT
   dwFlags AS DWORD   ' DWORD
END TYPE

'/*
' * STICKYKEYS dwFlags field
' */
%SKF_STICKYKEYSON    = &H00000001???
%SKF_AVAILABLE       = &H00000002???
%SKF_HOTKEYACTIVE    = &H00000004???
%SKF_CONFIRMHOTKEY   = &H00000008???
%SKF_HOTKEYSOUND     = &H00000010???
%SKF_INDICATOR       = &H00000020???
%SKF_AUDIBLEFEEDBACK = &H00000040???
%SKF_TRISTATE        = &H00000080???
%SKF_TWOKEYSOFF      = &H00000100???
'#if(_WIN32_WINNT >= 0x0500)
%SKF_LALTLATCHED     = &H10000000???
%SKF_LCTLLATCHED     = &H04000000???
%SKF_LSHIFTLATCHED   = &H01000000???
%SKF_RALTLATCHED     = &H20000000???
%SKF_RCTLLATCHED     = &H08000000???
%SKF_RSHIFTLATCHED   = &H02000000???
%SKF_LWINLATCHED     = &H40000000???
%SKF_RWINLATCHED     = &H80000000???
%SKF_LALTLOCKED      = &H00100000???
%SKF_LCTLLOCKED      = &H00040000???
%SKF_LSHIFTLOCKED    = &H00010000???
%SKF_RALTLOCKED      = &H00200000???
%SKF_RCTLLOCKED      = &H00080000???
%SKF_RSHIFTLOCKED    = &H00020000???
%SKF_LWINLOCKED      = &H00400000???
%SKF_RWINLOCKED      = &H00800000???
'#endif /* _WIN32_WINNT >= 0x0500 */

' // Size = 28 bytes
TYPE MOUSEKEYS DWORD
   cbSize          AS DWORD   ' UINT
   dwFlags         AS DWORD   ' DWORD
   iMaxSpeed       AS DWORD   ' DWORD
   iTimeToMaxSpeed AS DWORD   ' DWORD
   iCtrlSpeed      AS DWORD   ' DWORD
   dwReserved1     AS DWORD   ' DWORD
   dwReserved2     AS DWORD   ' DWORD
END TYPE

'/*
' * MOUSEKEYS dwFlags field
' */
%MKF_MOUSEKEYSON     = &H00000001???
%MKF_AVAILABLE       = &H00000002???
%MKF_HOTKEYACTIVE    = &H00000004???
%MKF_CONFIRMHOTKEY   = &H00000008???
%MKF_HOTKEYSOUND     = &H00000010???
%MKF_INDICATOR       = &H00000020???
%MKF_MODIFIERS       = &H00000040???
%MKF_REPLACENUMBERS  = &H00000080???
'#if(_WIN32_WINNT >= 0x0500)
%MKF_LEFTBUTTONSEL   = &H10000000???
%MKF_RIGHTBUTTONSEL  = &H20000000???
%MKF_LEFTBUTTONDOWN  = &H01000000???
%MKF_RIGHTBUTTONDOWN = &H02000000???
%MKF_MOUSEMODE       = &H80000000???
'#endif /* _WIN32_WINNT >= 0x0500 */

' // Size = 12 bytes
TYPE ACCESSTIMEOUT DWORD
   cbSize       AS DWORD   ' UINT
   dwFlags      AS DWORD   ' DWORD
   iTimeOutMSec AS DWORD   ' DWORD
END TYPE

'/*
' * ACCESSTIMEOUT dwFlags field
' */
%ATF_TIMEOUTON     = &H00000001???
%ATF_ONOFFFEEDBACK = &H00000002???

'/* values for SOUNDSENTRY iFSGrafEffect field */
%SSGF_NONE    = 0???
%SSGF_DISPLAY = 3???

'/* values for SOUNDSENTRY iFSTextEffect field */
%SSTF_NONE    = 0???
%SSTF_CHARS   = 1???
%SSTF_BORDER  = 2???
%SSTF_DISPLAY = 3???

'/* values for SOUNDSENTRY iWindowsEffect field */
%SSWF_NONE    = 0???
%SSWF_TITLE   = 1???
%SSWF_WINDOW  = 2???
%SSWF_DISPLAY = 3???
%SSWF_CUSTOM  = 4???

' // Size = 48 bytes
TYPE SOUNDSENTRYA DWORD
   cbSize                 AS DWORD        ' UINT
   dwFlags                AS DWORD        ' DWORD
   iFSTextEffect          AS DWORD        ' DWORD
   iFSTextEffectMSec      AS DWORD        ' DWORD
   iFSTextEffectColorBits AS DWORD        ' DWORD
   iFSGrafEffect          AS DWORD        ' DWORD
   iFSGrafEffectMSec      AS DWORD        ' DWORD
   iFSGrafEffectColor     AS DWORD        ' DWORD
   iWindowsEffect         AS DWORD        ' DWORD
   iWindowsEffectMSec     AS DWORD        ' DWORD
   lpszWindowsEffectDLL   AS ASCIIZ PTR   ' LPSTR
   iWindowsEffectOrdinal  AS DWORD        ' DWORD
END TYPE

' // Size = 48 bytes
TYPE SOUNDSENTRYW DWORD
   cbSize                 AS DWORD          ' UINT
   dwFlags                AS DWORD          ' DWORD
   iFSTextEffect          AS DWORD          ' DWORD
   iFSTextEffectMSec      AS DWORD          ' DWORD
   iFSTextEffectColorBits AS DWORD          ' DWORD
   iFSGrafEffect          AS DWORD          ' DWORD
   iFSGrafEffectMSec      AS DWORD          ' DWORD
   iFSGrafEffectColor     AS DWORD          ' DWORD
   iWindowsEffect         AS DWORD          ' DWORD
   iWindowsEffectMSec     AS DWORD          ' DWORD
   lpszWindowsEffectDLL   AS WSTRINGZ PTR   ' LPWSTR
   iWindowsEffectOrdinal  AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
MACRO SOUNDSENTRY_STRUCT = SOUNDSENTRYW
MACRO SOUNDSENTRY_TYPE = SOUNDSENTRYW
#ELSE
MACRO SOUNDSENTRY_STRUCT = SOUNDSENTRYA
MACRO SOUNDSENTRY_TYPE = SOUNDSENTRYA
#ENDIF

'/*
' * SOUNDSENTRY dwFlags field
' */
%SSF_SOUNDSENTRYON = &H00000001???
%SSF_AVAILABLE     = &H00000002???
%SSF_INDICATOR     = &H00000004???

'#if(_WIN32_WINNT >= 0x0600)
DECLARE FUNCTION SoundSentry IMPORT "User32.dll" ALIAS "SoundSentry" () AS LONG
'#endif /* _WIN32_WINNT >= 0x0600 */

' // Size = 8 bytes
TYPE TOGGLEKEYS DWORD
  cbSize  AS DWORD   ' UINT
  dwFlags AS DWORD   ' DWORD
END TYPE

'/*
' * TOGGLEKEYS dwFlags field
' */
%TKF_TOGGLEKEYSON  = &H00000001???
%TKF_AVAILABLE     = &H00000002???
%TKF_HOTKEYACTIVE  = &H00000004???
%TKF_CONFIRMHOTKEY = &H00000008???
%TKF_HOTKEYSOUND   = &H00000010???
%TKF_INDICATOR     = &H00000020???

'#if(_WIN32_WINNT >= 0x0600)
' // Size = 12 bytes
TYPE AUDIODESCRIPTION DWORD
   cbSize  AS DWORD   ' UINT  // sizeof(AudioDescriptionType)
   Enabled AS LONG    ' BOOL  // On/Off
   Locale  AS DWORD   ' DWORD // locale ID for language
END TYPE
'#endif /* _WIN32_WINNT >= 0x0600 */

'/*
' * Set debug level
' */

DECLARE SUB SetDebugErrorLevel IMPORT "USER32.DLL" ALIAS "SetDebugErrorLevel" ( _
   BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 )                                                      ' VOID

'/*
' * SetLastErrorEx() types.
' */

%SLE_ERROR      = &H00000001???
%SLE_MINORERROR = &H00000002???
%SLE_WARNING    = &H00000003???

DECLARE SUB SetLastErrorEx IMPORT "USER32.DLL" ALIAS "SetLastErrorEx" ( _
   BYVAL dwErrCode AS DWORD _                           ' __in DWORD dwErrCode
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 )                                                      ' VOID

DECLARE FUNCTION InternalGetWindowText IMPORT "USER32.DLL" ALIAS "InternalGetWindowText" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYREF pString AS WSTRINGZ _                          ' __out LPWSTR pString
 , BYVAL cchMaxCount AS LONG _                          ' __in int cchMaxCount
 ) AS LONG                                              ' int

' Although you can access this function by using LoadLibrary and GetProcAddress
' combined in Microsoft Windows versions prior to Windows XP, the function is
' not accessible using the standard Include file and library linkage. The header
' files included in Windows XP Service Pack 1 (SP1) and Windows Server 2003
' document this function and make it accessible using the appropriate Include
' file and library linkage. However, this function is deprecated and not intended
' for general use. It is recommended that you do not use it in new programs
' because it might be altered or unavailable in subsequent versions of Windows.

'#if defined(WINNT)
DECLARE FUNCTION EndTask IMPORT "USER32.DLL" ALIAS "EndTask" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL fShutDown AS LONG _                            ' __in BOOL fShutDown
 , BYVAL fForce AS LONG _                               ' __in BOOL fForce
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION CancelShutdown IMPORT "USER32.DLL" ALIAS "CancelShutdown" ( _
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)

'/*
' * Multimonitor API.
' */

%MONITOR_DEFAULTTONULL    = &H00000000???
%MONITOR_DEFAULTTOPRIMARY = &H00000001???
%MONITOR_DEFAULTTONEAREST = &H00000002???

DECLARE FUNCTION MonitorFromPoint IMPORT "USER32.DLL" ALIAS "MonitorFromPoint" ( _
   BYVAL pt AS POINT _                                  ' __in POINT pt
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HMONITOR

' // Same as above, but using x, y coordinates
DECLARE FUNCTION MonitorFromXY IMPORT "USER32.DLL" ALIAS "MonitorFromPoint" ( _
   BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HMONITOR

DECLARE FUNCTION MonitorFromRect IMPORT "USER32.DLL" ALIAS "MonitorFromRect" ( _
   BYREF lprc AS RECT _                                 ' __in LPCRECT lprc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HMONITOR

DECLARE FUNCTION MonitorFromWindow IMPORT "USER32.DLL" ALIAS "MonitorFromWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HMONITOR

%MONITORINFOF_PRIMARY = &H00000001???

'#ifndef CCHDEVICENAME
'#define CCHDEVICENAME 32
#IF NOT %DEF(%CCHDEVICENAME)
%CCHDEVICENAME = 32&
#ENDIF
'#endif

' // Size = 40 bytes
TYPE MONITORINFO DWORD
   cbSize    AS DWORD   ' DWORD
   rcMonitor AS RECT    ' RECT
   rcWork    AS RECT    ' RECT
   dwFlags   AS DWORD   ' DWORD
END TYPE

' // Size = 72 bytes
TYPE MONITORINFOEXA DWORD
   MONITORINFO
   szDevice AS ASCIIZ * %CCHDEVICENAME
END TYPE

' // Size = 104 bytes
TYPE MONITORINFOEXW DWORD
   MONITORINFO
   szDevice AS WSTRINGZ * %CCHDEVICENAME
END TYPE

#IF %DEF(%UNICODE)
MACRO MONITORINFOEX = MONITORINFOEXW
#ELSE
MACRO MONITORINFOEX = MONITORINFOEXA
#ENDIF

DECLARE FUNCTION GetMonitorInfoA IMPORT "USER32.DLL" ALIAS "GetMonitorInfoA" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HMONITOR hMonitor
 , BYREF lpmi AS ANY _                                  ' __inout LPMONITORINFO lpmi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorInfoW IMPORT "USER32.DLL" ALIAS "GetMonitorInfoW" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HMONITOR hMonitor
 , BYREF lpmi AS ANY _                                  ' __inout LPMONITORINFO lpmi
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetMonitorInfo = GetMonitorInfoW
#ELSE
   MACRO GetMonitorInfo = GetMonitorInfoA
#ENDIF

'typedef BOOL (CALLBACK* MONITORENUMPROC)(HMONITOR, HDC, LPRECT, LPARAM);

DECLARE FUNCTION EnumDisplayMonitors IMPORT "USER32.DLL" ALIAS "EnumDisplayMonitors" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC hdc
 , BYREF lprcClip AS RECT _                             ' __in_opt LPCRECT lprcClip
 , BYVAL lpfnEnum AS DWORD _                            ' __in MONITORENUMPROC lpfnEnum
 , BYVAL dwData AS LONG _                               ' __in LPARAM dwData
 ) AS LONG                                              ' BOOL

'#IF NOT %DEF(%NOWINABLE) ' ----------------------------------------------------
'#ifndef NOWINABLE

'/*
' * WinEvents - Active Accessibility hooks
' */

DECLARE SUB NotifyWinEvent IMPORT "USER32.DLL" ALIAS "NotifyWinEvent" ( _
   BYVAL event AS DWORD _                               ' __in DWORD event
 , BYVAL hwnd AS DWORD _                                ' __in HWND  hwnd
 , BYVAL idObject AS LONG _                             ' __in LONG  idObject
 , BYVAL idChild AS LONG _                              ' __in LONG  idChild
 )                                                      ' VOID

'typedef VOID (CALLBACK* WINEVENTPROC)(
'    HWINEVENTHOOK hWinEventHook,
'    DWORD         event,
'    HWND          hwnd,
'    LONG          idObject,
'    LONG          idChild,
'    DWORD         idEventThread,
'    DWORD         dwmsEventTime);

DECLARE FUNCTION SetWinEventHook IMPORT "USER32.DLL" ALIAS "SetWinEventHook" ( _
   BYVAL eventMin AS DWORD _                            ' __in DWORD eventMin
 , BYVAL eventMax AS DWORD _                            ' __in DWORD eventMax
 , BYVAL hmodWinEventProc AS DWORD _                    ' __in_opt HMODULE hmodWinEventProc
 , BYVAL pfnWinEventProc AS DWORD _                     ' __in WINEVENTPROC pfnWinEventProc
 , BYVAL idProcess AS DWORD _                           ' __in DWORD idProcess
 , BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HWINEVENTHOOK

'#if(_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION IsWinEventHookInstalled IMPORT "USER32.DLL" ALIAS "IsWinEventHookInstalled" ( _
   BYVAL event AS DWORD _                               ' __in DWORD event
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >= 0x0501 */

'/*
' * dwFlags for SetWinEventHook
' */
%WINEVENT_OUTOFCONTEXT   = &H0000???  ' Events are ASYNC
%WINEVENT_SKIPOWNTHREAD  = &H0001???  ' Don't call back for events on installer's thread
%WINEVENT_SKIPOWNPROCESS = &H0002???  ' Don't call back for events on installer's process
%WINEVENT_INCONTEXT      = &H0004???  ' Events are SYNC, this causes your dll to be injected into every process

DECLARE FUNCTION UnhookWinEvent IMPORT "USER32.DLL" ALIAS "UnhookWinEvent" ( _
   BYVAL hWinEventHook AS DWORD _                       ' __in HWINEVENTHOOK hWinEventHook
 ) AS LONG                                              ' BOOL

'/*
' * idObject values for WinEventProc and NotifyWinEvent
' */

'/*
' * hwnd + idObject can be used with OLEACC.DLL's OleGetObjectFromWindow()
' * to get an interface pointer to the container.  indexChild is the item
' * within the container in question.  Setup a VARIANT with vt VT_I4 and
' * lVal the indexChild and pass that in to all methods.  Then you
' * are raring to go.
' */


'/*
' * Common object IDs (cookies, only for sending WM_GETOBJECT to get at the
' * thing in question).  Positive IDs are reserved for apps (app specific),
' * negative IDs are system things and are global, 0 means "just little old
' * me".
' */

%CHILDID_SELF      = 0&
%INDEXID_OBJECT    = 0&
%INDEXID_CONTAINER = 0&

'/*
' * Reserved IDs for system objects
' */
%OBJID_WINDOW            = &H00000000&   ' ((LONG)0x00000000)
%OBJID_SYSMENU           = &HFFFFFFFF&   ' ((LONG)0xFFFFFFFF)
%OBJID_TITLEBAR          = &HFFFFFFFE&   ' ((LONG)0xFFFFFFFE)
%OBJID_MENU              = &HFFFFFFFD&   ' ((LONG)0xFFFFFFFD)
%OBJID_CLIENT            = &HFFFFFFFC&   ' ((LONG)0xFFFFFFFC)
%OBJID_VSCROLL           = &HFFFFFFFB&   ' ((LONG)0xFFFFFFFB)
%OBJID_HSCROLL           = &HFFFFFFFA&   ' ((LONG)0xFFFFFFFA)
%OBJID_SIZEGRIP          = &HFFFFFFF9&   ' ((LONG)0xFFFFFFF9)
%OBJID_CARET             = &HFFFFFFF8&   ' ((LONG)0xFFFFFFF8)
%OBJID_CURSOR            = &HFFFFFFF7&   ' ((LONG)0xFFFFFFF7)
%OBJID_ALERT             = &HFFFFFFF6&   ' ((LONG)0xFFFFFFF6)
%OBJID_SOUND             = &HFFFFFFF5&   ' ((LONG)0xFFFFFFF5)
%OBJID_QUERYCLASSNAMEIDX = &HFFFFFFF4&   ' ((LONG)0xFFFFFFF4)
%OBJID_NATIVEOM          = &HFFFFFFF0&   ' ((LONG)0xFFFFFFF0)

'/*
' * EVENT DEFINITION
' */
%EVENT_MIN               = &H00000001???
%EVENT_MAX               = &H7FFFFFFF???

'/*
' *  EVENT_SYSTEM_SOUND
' *  Sent when a sound is played.  Currently nothing is generating this, we
' *  this event when a system sound (for menus, etc) is played.  Apps
' *  generate this, if accessible, when a private sound is played.  For
' *  example, if Mail plays a "New Mail" sound.
' *
' *  System Sounds:
' *  (Generated by PlaySoundEvent in USER itself)
' *      hwnd            is NULL
' *      idObject        is OBJID_SOUND
' *      idChild         is sound child ID if one
' *  App Sounds:
' *  (PlaySoundEvent won't generate notification; up to app)
' *      hwnd + idObject gets interface pointer to Sound object
' *      idChild identifies the sound in question
' *  are going to be cleaning up the SOUNDSENTRY feature in the control panel
' *  and will use this at that time.  Applications implementing WinEvents
' *  are perfectly welcome to use it.  Clients of IAccessible* will simply
' *  turn around and get back a non-visual object that describes the sound.
' */
%EVENT_SYSTEM_SOUND              = &H0001???

'/*
' * EVENT_SYSTEM_ALERT
' * System Alerts:
' * (Generated by MessageBox() calls for example)
' *      hwnd            is hwndMessageBox
' *      idObject        is OBJID_ALERT
' * App Alerts:
' * (Generated whenever)
' *      hwnd+idObject gets interface pointer to Alert
' */
%EVENT_SYSTEM_ALERT              = &H0002???

'/*
' * EVENT_SYSTEM_FOREGROUND
' * Sent when the foreground (active) window changes, even if it is changing
' * to another window in the same thread as the previous one.
' *      hwnd            is hwndNewForeground
' *      idObject        is OBJID_WINDOW
' *      idChild    is INDEXID_OBJECT
' */
%EVENT_SYSTEM_FOREGROUND         = &H0003???

'/*
' * Menu
' *      hwnd            is window (top level window or popup menu window)
' *      idObject        is ID of control (OBJID_MENU, OBJID_SYSMENU, OBJID_SELF for popup)
' *      idChild         is CHILDID_SELF
' *
' * EVENT_SYSTEM_MENUSTART
' * EVENT_SYSTEM_MENUEND
' * For MENUSTART, hwnd+idObject+idChild refers to the control with the menu bar,
' *  or the control bringing up the context menu.
' *
' * Sent when entering into and leaving from menu mode (system, app bar, and
' * track popups).
' */
%EVENT_SYSTEM_MENUSTART          = &H0004???
%EVENT_SYSTEM_MENUEND            = &H0005???

'/*
' * EVENT_SYSTEM_MENUPOPUPSTART
' * EVENT_SYSTEM_MENUPOPUPEND
' * Sent when a menu popup comes up and just before it is taken down.  Note
' * that for a call to TrackPopupMenu(), a client will see EVENT_SYSTEM_MENUSTART
' * followed almost immediately by EVENT_SYSTEM_MENUPOPUPSTART for the popup
' * being shown.
' *
' * For MENUPOPUP, hwnd+idObject+idChild refers to the NEW popup coming up, not the
' * parent item which is hierarchical.  You can get the parent menu/popup by
' * asking for the accParent object.
' */
%EVENT_SYSTEM_MENUPOPUPSTART     = &H0006???
%EVENT_SYSTEM_MENUPOPUPEND       = &H0007???

'/*
' * EVENT_SYSTEM_CAPTURESTART
' * EVENT_SYSTEM_CAPTUREEND
' * Sent when a window takes the capture and releases the capture.
' */
%EVENT_SYSTEM_CAPTURESTART       = &H0008???
%EVENT_SYSTEM_CAPTUREEND         = &H0009???

'/*
' * Move Size
' * EVENT_SYSTEM_MOVESIZESTART
' * EVENT_SYSTEM_MOVESIZEEND
' * Sent when a window enters and leaves move-size dragging mode.
' */
%EVENT_SYSTEM_MOVESIZESTART      = &H000A???
%EVENT_SYSTEM_MOVESIZEEND        = &H000B???

'/*
' * Context Help
' * EVENT_SYSTEM_CONTEXTHELPSTART
' * EVENT_SYSTEM_CONTEXTHELPEND
' * Sent when a window enters and leaves context sensitive help mode.
' */
%EVENT_SYSTEM_CONTEXTHELPSTART   = &H000C???
%EVENT_SYSTEM_CONTEXTHELPEND     = &H000D???

'/*
' * Drag & Drop
' * EVENT_SYSTEM_DRAGDROPSTART
' * EVENT_SYSTEM_DRAGDROPEND
' * Send the START notification just before going into drag&drop loop.  Send
' * the END notification just after canceling out.
' * Note that it is up to apps and OLE to generate this, since the system
' * doesn't know.  Like EVENT_SYSTEM_SOUND, it will be a while before this
' * is prevalent.
' */
%EVENT_SYSTEM_DRAGDROPSTART      = &H000E???
%EVENT_SYSTEM_DRAGDROPEND        = &H000F???

'/*
' * Dialog
' * Send the START notification right after the dialog is completely
' *  initialized and visible.  Send the END right before the dialog
' *  is hidden and goes away.
' * EVENT_SYSTEM_DIALOGSTART
' * EVENT_SYSTEM_DIALOGEND
' */
%EVENT_SYSTEM_DIALOGSTART        = &H0010???
%EVENT_SYSTEM_DIALOGEND          = &H0011???

'/*
' * EVENT_SYSTEM_SCROLLING
' * EVENT_SYSTEM_SCROLLINGSTART
' * EVENT_SYSTEM_SCROLLINGEND
' * Sent when beginning and ending the tracking of a scrollbar in a window,
' * and also for scrollbar controls.
' */
%EVENT_SYSTEM_SCROLLINGSTART     = &H0012???
%EVENT_SYSTEM_SCROLLINGEND       = &H0013???

'/*
' * Alt-Tab Window
' * Send the START notification right after the switch window is initialized
' * and visible.  Send the END right before it is hidden and goes away.
' * EVENT_SYSTEM_SWITCHSTART
' * EVENT_SYSTEM_SWITCHEND
' */
%EVENT_SYSTEM_SWITCHSTART        = &H0014???
%EVENT_SYSTEM_SWITCHEND          = &H0015???

'/*
' * EVENT_SYSTEM_MINIMIZESTART
' * EVENT_SYSTEM_MINIMIZEEND
' * Sent when a window minimizes and just before it restores.
' */
%EVENT_SYSTEM_MINIMIZESTART      = &H0016???
%EVENT_SYSTEM_MINIMIZEEND        = &H0017???

'#if(_WIN32_WINNT >= 0x0600)
%EVENT_SYSTEM_DESKTOPSWITCH      = &H0020???
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if(_WIN32_WINNT >= 0x0601)
%EVENT_SYSTEM_END                = &H00FF???

%EVENT_OEM_DEFINED_START         = &H0101???
%EVENT_OEM_DEFINED_END           = &H01FF???

%EVENT_UIA_EVENTID_START         = &H4E00???
%EVENT_UIA_EVENTID_END           = &H4EFF???

%EVENT_UIA_PROPID_START          = &H7500???
%EVENT_UIA_PROPID_END            = &H75FF???
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if(_WIN32_WINNT >= 0x0501)
%EVENT_CONSOLE_CARET             = &H4001???
%EVENT_CONSOLE_UPDATE_REGION     = &H4002???
%EVENT_CONSOLE_UPDATE_SIMPLE     = &H4003???
%EVENT_CONSOLE_UPDATE_SCROLL     = &H4004???
%EVENT_CONSOLE_LAYOUT            = &H4005???
%EVENT_CONSOLE_START_APPLICATION = &H4006???
%EVENT_CONSOLE_END_APPLICATION   = &H4007???

'/*
' * Flags for EVENT_CONSOLE_START/END_APPLICATION.
' */
'#if defined(_WIN64)
'#define CONSOLE_APPLICATION_16BIT       0x0000
'#else
'#define CONSOLE_APPLICATION_16BIT       0x0001
'#endif
%CONSOLE_APPLICATION_16BIT       = &H0001???

'/*
' * Flags for EVENT_CONSOLE_CARET
' */
%CONSOLE_CARET_SELECTION         = &H0001???
%CONSOLE_CARET_VISIBLE           = &H0002???

'#endif /* _WIN32_WINNT >= 0x0501 */

'#if(_WIN32_WINNT >= 0x0601)
%EVENT_CONSOLE_END       = &H40FF???
'#endif /* _WIN32_WINNT >= 0x0601 */

'/*
' * Object events
' *
' * The system AND apps generate these.  The system generates these for
' * real windows.  Apps generate these for objects within their window which
' * act like a separate control, e.g. an item in a list view.
' *
' * When the system generate them, dwParam2 is always WMOBJID_SELF.  When
' * apps generate them, apps put the has-meaning-to-the-app-only ID value
' * in dwParam2.
' * For all events, if you want detailed accessibility information, callers
' * should
' *      * Call AccessibleObjectFromWindow() with the hwnd, idObject parameters
' *          of the event, and IID_IAccessible as the REFIID, to get back an
' *          IAccessible* to talk to
' *      * Initialize and fill in a VARIANT as VT_I4 with lVal the idChild
' *          parameter of the event.
' *      * If idChild isn't zero, call get_accChild() in the container to see
' *          if the child is an object in its own right.  If so, you will get
' *          back an IDispatch* object for the child.  You should release the
' *          parent, and call QueryInterface() on the child object to get its
' *          IAccessible*.  Then you talk directly to the child.  Otherwise,
' *          if get_accChild() returns you nothing, you should continue to
' *          use the child VARIANT.  You will ask the container for the properties
' *          of the child identified by the VARIANT.  In other words, the
' *          child in this case is accessible but not a full-blown object.
' *          Like a button on a titlebar which is 'small' and has no children.
' */

'/*
' * For all EVENT_OBJECT events,
' *      hwnd is the dude to Send the WM_GETOBJECT message to (unless NULL,
' *          see above for system things)
' *      idObject is the ID of the object that can resolve any queries a
' *          client might have.  It's a way to deal with windowless controls,
' *          controls that are just drawn on the screen in some larger parent
' *          window (like SDM), or standard frame elements of a window.
' *      idChild is the piece inside of the object that is affected.  This
' *          allows clients to access things that are too small to have full
' *          blown objects in their own right.  Like the thumb of a scrollbar.
' *          The hwnd/idObject pair gets you to the container, the dude you
' *          probably want to talk to most of the time anyway.  The idChild
' *          can then be passed into the acc properties to get the name/value
' *          of it as needed.
' *
' * Example #1:
' *      System propagating a listbox selection change
' *      EVENT_OBJECT_SELECTION
' *          hwnd == listbox hwnd
' *          idObject == OBJID_WINDOW
' *          idChild == new selected item, or CHILDID_SELF if
' *              nothing now selected within container.
' *      Word '97 propagating a listbox selection change
' *          hwnd == SDM window
' *          idObject == SDM ID to get at listbox 'control'
' *          idChild == new selected item, or CHILDID_SELF if
' *              nothing
' *
' * Example #2:
' *      System propagating a menu item selection on the menu bar
' *      EVENT_OBJECT_SELECTION
' *          hwnd == top level window
' *          idObject == OBJID_MENU
' *          idChild == ID of child menu bar item selected
' *
' * Example #3:
' *      System propagating a dropdown coming off of said menu bar item
' *      EVENT_OBJECT_CREATE
' *          hwnd == popup item
' *          idObject == OBJID_WINDOW
' *          idChild == CHILDID_SELF
' *
' * Example #4:
' *
' * For EVENT_OBJECT_REORDER, the object referred to by hwnd/idObject is the
' * PARENT container in which the zorder is occurring.  This is because if
' * one child is zordering, all of them are changing their relative zorder.
' */
%EVENT_OBJECT_CREATE                 = &H8000???  ' hwnd + ID + idChild is created item
%EVENT_OBJECT_DESTROY                = &H8001???  ' hwnd + ID + idChild is destroyed item
%EVENT_OBJECT_SHOW                   = &H8002???  ' hwnd + ID + idChild is shown item
%EVENT_OBJECT_HIDE                   = &H8003???  ' hwnd + ID + idChild is hidden item
%EVENT_OBJECT_REORDER                = &H8004???  ' hwnd + ID + idChild is parent of zordering children

'/*
' * NOTE:
' * Minimize the number of notifications!
' *
' * When you are hiding a parent object, obviously all child objects are no
' * longer visible on screen.  They still have the same "visible" status,
' * but are not truly visible.  Hence do not send HIDE notifications for the
' * children also.  One implies all.  The same goes for SHOW.
' */

%EVENT_OBJECT_FOCUS                  = &H8005???  ' hwnd + ID + idChild is focused item
%EVENT_OBJECT_SELECTION              = &H8006???  ' hwnd + ID + idChild is selected item (if only one), or idChild is OBJID_WINDOW if complex
%EVENT_OBJECT_SELECTIONADD           = &H8007???  ' hwnd + ID + idChild is item added
%EVENT_OBJECT_SELECTIONREMOVE        = &H8008???  ' hwnd + ID + idChild is item removed
%EVENT_OBJECT_SELECTIONWITHIN        = &H8009???  ' hwnd + ID + idChild is parent of changed selected items

'/*
' * NOTES:
' * There is only one "focused" child item in a parent.  This is the place
' * keystrokes are going at a given moment.  Hence only send a notification
' * about where the NEW focus is going.  A NEW item getting the focus already
' * implies that the OLD item is losing it.
' *
' * SELECTION however can be multiple.  Hence the different SELECTION
' * notifications.  Here's when to use each:
' *
' * (1) Send a SELECTION notification in the simple single selection
' *     case (like the focus) when the item with the selection is
' *     merely moving to a different item within a container.  hwnd + ID
' *     is the container control, idChildItem is the new child with the
' *     selection.
' *
' * (2) Send a SELECTIONADD notification when a new item has simply been added
' *     to the selection within a container.  This is appropriate when the
' *     number of newly selected items is very small.  hwnd + ID is the
' *     container control, idChildItem is the new child added to the selection.
' *
' * (3) Send a SELECTIONREMOVE notification when a new item has simply been
' *     removed from the selection within a container.  This is appropriate
' *     when the number of newly selected items is very small, just like
' *     SELECTIONADD.  hwnd + ID is the container control, idChildItem is the
' *     new child removed from the selection.
' *
' * (4) Send a SELECTIONWITHIN notification when the selected items within a
' *     control have changed substantially.  Rather than propagate a large
' *     number of changes to reflect removal for some items, addition of
' *     others, just tell somebody who cares that a lot happened.  It will
' *     be faster an easier for somebody watching to just turn around and
' *     query the container control what the new bunch of selected items
' *     are.
' */

%EVENT_OBJECT_STATECHANGE            = &H800A???  ' hwnd + ID + idChild is item w/ state change

'/*
' * Examples of when to send an EVENT_OBJECT_STATECHANGE include
' *      * It is being enabled/disabled (USER does for windows)
' *      * It is being pressed/released (USER does for buttons)
' *      * It is being checked/unchecked (USER does for radio/check buttons)
' */
%EVENT_OBJECT_LOCATIONCHANGE         = &H800B???  ' hwnd + ID + idChild is moved/sized item

'/*
' * Note:
' * A LOCATIONCHANGE is not sent for every child object when the parent
' * changes shape/moves.  Send one notification for the topmost object
' * that is changing.  For example, if the user resizes a top level window,
' * USER will generate a LOCATIONCHANGE for it, but not for the menu bar,
' * title bar, scrollbars, etc.  that are also changing shape/moving.
' *
' * In other words, it only generates LOCATIONCHANGE notifications for
' * real windows that are moving/sizing.  It will not generate a LOCATIONCHANGE
' * for every non-floating child window when the parent moves (the children are
' * logically moving also on screen, but not relative to the parent).
' *
' * Now, if the app itself resizes child windows as a result of being
' * sized, USER will generate LOCATIONCHANGEs for those dudes also because
' * it doesn't know better.
' *
' * Note also that USER will generate LOCATIONCHANGE notifications for two
' * non-window sys objects:
' *      (1) System caret
' *      (2) Cursor
' */

%EVENT_OBJECT_NAMECHANGE             = &H800C???  ' hwnd + ID + idChild is item w/ name change
%EVENT_OBJECT_DESCRIPTIONCHANGE      = &H800D???  ' hwnd + ID + idChild is item w/ desc change
%EVENT_OBJECT_VALUECHANGE            = &H800E???  ' hwnd + ID + idChild is item w/ value change
%EVENT_OBJECT_PARENTCHANGE           = &H800F???  ' hwnd + ID + idChild is item w/ new parent
%EVENT_OBJECT_HELPCHANGE             = &H8010???  ' hwnd + ID + idChild is item w/ help change
%EVENT_OBJECT_DEFACTIONCHANGE        = &H8011???  ' hwnd + ID + idChild is item w/ def action change
%EVENT_OBJECT_ACCELERATORCHANGE      = &H8012???  ' hwnd + ID + idChild is item w/ keybd accel change

'#if(_WIN32_WINNT >= 0x0600)
%EVENT_OBJECT_INVOKED                = &H8013???  ' // hwnd + ID + idChild is item invoked
%EVENT_OBJECT_TEXTSELECTIONCHANGED   = &H8014???  ' // hwnd + ID + idChild is item w? test selection change

'/*
' * EVENT_OBJECT_CONTENTSCROLLED
' * Sent when ending the scrolling of a window object.
' *
' * Unlike the similar event (EVENT_SYSTEM_SCROLLEND), this event will be
' * associated with the scrolling window itself. There is no difference
' * between horizontal or vertical scrolling.
' *
' * This event should be posted whenever scroll action is completed, including
' * when it is scrolled by scroll bars, mouse wheel, or keyboard navigations.
' *
' *   example:
' *          hwnd == window that is scrolling
' *          idObject == OBJID_CLIENT
' *          idChild == CHILDID_SELF
' */
%EVENT_OBJECT_CONTENTSCROLLED        = &H8015???
'#endif /* _WIN32_WINNT >= 0x0600 */

'#if(_WIN32_WINNT >= 0x0601)
%EVENT_SYSTEM_ARRANGMENTPREVIEW      = &H8016???
'#endif /* _WIN32_WINNT >= 0x0601 */

'#if(_WIN32_WINNT >= 0x0601)
%EVENT_OBJECT_END                    = &H80FF???

%EVENT_AIA_START                     = &HA000???
%EVENT_AIA_END                       = &HAFFF???
'#endif /* _WIN32_WINNT >= 0x0601 */

'/*
' * Child IDs
' */

'/*
' * System Sounds (idChild of system SOUND notification)
' */
%SOUND_SYSTEM_STARTUP          = 1&
%SOUND_SYSTEM_SHUTDOWN         = 2&
%SOUND_SYSTEM_BEEP             = 3&
%SOUND_SYSTEM_ERROR            = 4&
%SOUND_SYSTEM_QUESTION         = 5&
%SOUND_SYSTEM_WARNING          = 6&
%SOUND_SYSTEM_INFORMATION      = 7&
%SOUND_SYSTEM_MAXIMIZE         = 8&
%SOUND_SYSTEM_MINIMIZE         = 9&
%SOUND_SYSTEM_RESTOREUP        = 10&
%SOUND_SYSTEM_RESTOREDOWN      = 11&
%SOUND_SYSTEM_APPSTART         = 12&
%SOUND_SYSTEM_FAULT            = 13&
%SOUND_SYSTEM_APPEND           = 14&
%SOUND_SYSTEM_MENUCOMMAND      = 15&
%SOUND_SYSTEM_MENUPOPUP        = 16&
%CSOUND_SYSTEM                 = 16&

'/*
' * System Alerts (indexChild of system ALERT notification)
' */
%ALERT_SYSTEM_INFORMATIONAL    = 1&       ' MB_INFORMATION
%ALERT_SYSTEM_WARNING          = 2&       ' MB_WARNING
%ALERT_SYSTEM_ERROR            = 3&       ' MB_ERROR
%ALERT_SYSTEM_QUERY            = 4&       ' MB_QUESTION
%ALERT_SYSTEM_CRITICAL         = 5&       ' HardSysErrBox
%CALERT_SYSTEM                 = 6&

' // Size = 48 bytes
TYPE GUITHREADINFO DWORD
   cbSize        AS DWORD   ' DWORD
   flags         AS DWORD   ' DWORD
   hwndActive    AS DWORD   ' HWND
   hwndFocus     AS DWORD   ' HWND
   hwndCapture   AS DWORD   ' HWND
   hwndMenuOwner AS DWORD   ' HWND
   hwndMoveSize  AS DWORD   ' HWND
   hwndCaret     AS DWORD   ' HWND
   rcCaret       AS RECT    ' RECT
END TYPE

%GUI_CARETBLINKING   = &H00000001???
%GUI_INMOVESIZE      = &H00000002???
%GUI_INMENUMODE      = &H00000004???
%GUI_SYSTEMMENUMODE  = &H00000008???
%GUI_POPUPMENUMODE   = &H00000010???
'#if(_WIN32_WINNT >= 0x0501)
'#if defined(_WIN64)
'#define GUI_16BITTASK       0x00000000
'#else
'#define GUI_16BITTASK       0x00000020
'#endif
%GUI_16BITTASK       = &H00000020???

DECLARE FUNCTION GetGUIThreadInfo IMPORT "USER32.DLL" ALIAS "GetGUIThreadInfo" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 , BYREF pgui AS GUITHREADINFO _                        ' __inout PGUITHREADINFO pgui
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BlockInput IMPORT "USER32.DLL" ALIAS "BlockInput" ( _
   BYVAL fBlockIt AS LONG _                             ' BOOL fBlockIt
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0600)

%USER_DEFAULT_SCREEN_DPI = 96

DECLARE FUNCTION SetProcessDPIAware IMPORT "USER32.DLL" ALIAS "SetProcessDPIAware" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsProcessDPIAware IMPORT "USER32.DLL" ALIAS "IsProcessDPIAware" ( _
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >= 0x0600 */

DECLARE FUNCTION GetWindowModuleFileNameA IMPORT "USER32.DLL" ALIAS "GetWindowModuleFileNameA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszFileName AS ASCIIZ _                        ' __out LPSTR pszFileName
 , BYVAL cchFileNameMax AS DWORD _                      ' __in UINT cchFileNameMax
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetWindowModuleFileNameW IMPORT "USER32.DLL" ALIAS "GetWindowModuleFileNameW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszFileName AS WSTRINGZ _                      ' __out LPWSTR pszFileName
 , BYVAL cchFileNameMax AS DWORD _                      ' __in UINT cchFileNameMax
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetWindowModuleFileName = GetWindowModuleFileNameW
#ELSE
   MACRO GetWindowModuleFileName = GetWindowModuleFileNameA
#ENDIF

'#ifndef NO_STATE_FLAGS
'#IF NOT %DEF(%NO_STATE_FLAGS)
%STATE_SYSTEM_UNAVAILABLE     = &H00000001???  ' Disabled
%STATE_SYSTEM_SELECTED        = &H00000002???
%STATE_SYSTEM_FOCUSED         = &H00000004???
%STATE_SYSTEM_PRESSED         = &H00000008???
%STATE_SYSTEM_CHECKED         = &H00000010???
%STATE_SYSTEM_MIXED           = &H00000020???  ' 3-state checkbox or toolbar button
%STATE_SYSTEM_INDETERMINATE   = %STATE_SYSTEM_MIXED
%STATE_SYSTEM_READONLY        = &H00000040???
%STATE_SYSTEM_HOTTRACKED      = &H00000080???
%STATE_SYSTEM_DEFAULT         = &H00000100???
%STATE_SYSTEM_EXPANDED        = &H00000200???
%STATE_SYSTEM_COLLAPSED       = &H00000400???
%STATE_SYSTEM_BUSY            = &H00000800???
%STATE_SYSTEM_FLOATING        = &H00001000???  ' Children "owned" not "contained" by parent
%STATE_SYSTEM_MARQUEED        = &H00002000???
%STATE_SYSTEM_ANIMATED        = &H00004000???
%STATE_SYSTEM_INVISIBLE       = &H00008000???
%STATE_SYSTEM_OFFSCREEN       = &H00010000???
%STATE_SYSTEM_SIZEABLE        = &H00020000???
%STATE_SYSTEM_MOVEABLE        = &H00040000???
%STATE_SYSTEM_SELFVOICING     = &H00080000???
%STATE_SYSTEM_FOCUSABLE       = &H00100000???
%STATE_SYSTEM_SELECTABLE      = &H00200000???
%STATE_SYSTEM_LINKED          = &H00400000???
%STATE_SYSTEM_TRAVERSED       = &H00800000???
%STATE_SYSTEM_MULTISELECTABLE = &H01000000???  ' Supports multiple selection
%STATE_SYSTEM_EXTSELECTABLE   = &H02000000???  ' Supports extended selection
%STATE_SYSTEM_ALERT_LOW       = &H04000000???  ' This information is of low priority
%STATE_SYSTEM_ALERT_MEDIUM    = &H08000000???  ' This information is of medium priority
%STATE_SYSTEM_ALERT_HIGH      = &H10000000???  ' This information is of high priority
%STATE_SYSTEM_PROTECTED       = &H20000000???  ' access to this is restricted
%STATE_SYSTEM_VALID           = &H3FFFFFFF???
'#ENDIF
'#endif

%CCHILDREN_TITLEBAR   = 5&
%CCHILDREN_SCROLLBAR  = 5&

'/*
' * Information about the global cursor.
' */

' // Size = 20 bytes
TYPE CURSORINFO DWORD
   cbSize      AS DWORD   ' DWORD
   flags       AS DWORD   ' DWORD
   hCursor     AS DWORD   ' HCURSOR
   ptScreenPos AS POINT   ' POINT
END TYPE

%CURSOR_SHOWING    = &H00000001???

DECLARE FUNCTION GetCursorInfo IMPORT "USER32.DLL" ALIAS "GetCursorInfo" ( _
   BYREF pci AS CURSORINFO _                            ' __inout PCURSORINFO pci
 ) AS LONG                                              ' BOOL

'/*
' * Window information snapshot
' */

' // Size = 60 bytes
TYPE WINDOWINFO DWORD FILL
   cbSize          AS DWORD   ' DWORD
   rcWindow        AS RECT    ' RECT
   rcClient        AS RECT    ' RECT
   dwStyle         AS DWORD   ' DWORD
   dwExStyle       AS DWORD   ' DWORD
   dwWindowStatus  AS DWORD   ' DWORD
   cxWindowBorders AS DWORD   ' UINT
   cyWindowBorders AS DWORD   ' UINT
   atomWindowType  AS WORD    ' ATOM
   wCreatorVersion AS WORD    ' WORD
END TYPE

%WS_ACTIVECAPTION  = &H0001???

DECLARE FUNCTION GetWindowInfo IMPORT "USER32.DLL" ALIAS "GetWindowInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pwi AS WINDOWINFO _                            ' __inout PWINDOWINFO pwi
 ) AS LONG                                              ' BOOL

'/*
' * Titlebar information.
' */

' // Size = 44 bytes
TYPE TITLEBARINFO DWORD
   cbSize     AS DWORD                      ' DWORD
   rcTitleBar AS RECT                       ' RECT
   rgstate (%CCHILDREN_TITLEBAR) AS DWORD   ' DWORD rgstate[CCHILDREN_TITLEBAR + 1]
END TYPE

DECLARE FUNCTION GetTitleBarInfo IMPORT "USER32.DLL" ALIAS "GetTitleBarInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pti AS TITLEBARINFO _                          ' __inout PTITLEBARINFO pti
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0600)
' // Size = 140 bytes
TYPE TITLEBARINFOEX DWORD
   cbSize                       AS DWORD
   rcTitleBar                   AS RECT
   rgstate(%CCHILDREN_TITLEBAR) AS DWORD
   rgrect(%CCHILDREN_TITLEBAR)  AS RECT
END TYPE
'#endif /* WINVER >= 0x0600 */

'/*
' * Menubar information
' */

' // Size = 32 bytes
TYPE MENUBARINFO DWORD
   cbSize      AS DWORD               ' DWORD cbSize
   rcBar       AS RECT                ' RECT rcBar;          // rect of bar, popup, item
   hMenu       AS DWORD               ' HMENU hMenu;         // real menu handle of bar, popup
   hwndMenu    AS DWORD               ' hwnd of item submenu if one
   fBarFocused AS BIT * 1 IN DWORD    ' BOOL fBarFocused:1;  // bar, popup has the focus
   fFocused    AS BIT * 1             ' BOOL fFocused:1;     // item has the focus
END TYPE

DECLARE FUNCTION GetMenuBarInfo IMPORT "USER32.DLL" ALIAS "GetMenuBarInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL idObject AS LONG _                             ' __in LONG idObject
 , BYVAL idItem AS LONG _                               ' __in LONG idItem
 , BYREF pmbi AS MENUBARINFO _                          ' __inout PMENUBARINFO pmbi
 ) AS LONG                                              ' BOOL

'/*
' * Scrollbar information
' */

' // Size = 60 bytes
TYPE SCROLLBARINFO DWORD
   cbSize        AS DWORD                   ' DWORD
   rcScrollBar   AS RECT                    ' RECT
   dxyLineButton AS LONG                    ' int
   xyThumbTop    AS LONG                    ' int
   xyThumbBottom AS LONG                    ' int
   reserved      AS LONG                    ' int
   rgstate(%CCHILDREN_SCROLLBAR) AS DWORD   ' DWORD rgstate[CCHILDREN_SCROLLBAR + 1]
END TYPE

DECLARE FUNCTION GetScrollBarInfo IMPORT "USER32.DLL" ALIAS "GetScrollBarInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL idObject AS LONG _                             ' __in LONG idObject
 , BYREF psbi AS SCROLLBARINFO _                        ' __inout PSCROLLBARINFO psbi
 ) AS LONG                                              ' BOOL

'/*
' * Combobox information
' */

' // Size = 52 bytes
TYPE COMBOBOXINFO DWORD
   cbSize      AS DWORD   ' DWORD
   rcItem      AS RECT    ' RECT
   rcButton    AS RECT    ' RECT
   stateButton AS DWORD   ' DWORD
   hwndCombo   AS DWORD   ' HWND
   hwndItem    AS DWORD   ' HWND
   hwndList    AS DWORD   ' HWND
END TYPE

DECLARE FUNCTION GetComboBoxInfo IMPORT "USER32.DLL" ALIAS "GetComboBoxInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWndCombo
 , BYREF pcbi AS COMBOBOXINFO _                         ' __inout PCOMBOBOXINFO pcbi
 ) AS LONG                                              ' BOOL

'/*
' * The "real" ancestor window
' */
%GA_PARENT    = 1&
%GA_ROOT      = 2%
%GA_ROOTOWNER = 3&

DECLARE FUNCTION GetAncestor IMPORT "USER32.DLL" ALIAS "GetAncestor" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL gaFlags AS DWORD _                             ' __in UINT gaFlags
 ) AS DWORD                                             ' HWND

'/*
' * This gets the REAL child window at the point.  If it is in the dead
' * space of a group box, it will try a sibling behind it.  But static
' * fields will get returned.  In other words, it is kind of a cross between
' * ChildWindowFromPointEx and WindowFromPoint.
' */

DECLARE FUNCTION RealChildWindowFromPoint IMPORT "USER32.DLL" ALIAS "RealChildWindowFromPoint" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL ptParentClientCoords AS POINT _                ' __in POINT ptParentClientCoords
 ) AS DWORD                                             ' HWND

' // Same as above, but using x, y coordinates
DECLARE FUNCTION RealChildWindowFromXY IMPORT "USER32.DLL" ALIAS "RealChildWindowFromPoint" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 ) AS DWORD                                             ' HWND

'/*
' * This gets the name of the window TYPE, not class.  This allows us to
' * recognize ThunderButton32 et al.
' */

DECLARE FUNCTION RealGetWindowClassA IMPORT "USER32.DLL" ALIAS "RealGetWindowClassA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF ptszClassName AS ASCIIZ _                      ' __out LPSTR ptszClassName
 , BYVAL cchClassNameMax AS DWORD _                     ' __in UINT cchClassNameMax
 ) AS DWORD                                             ' UINT

'/*
' * This gets the name of the window TYPE, not class.  This allows us to
' * recognize ThunderButton32 et al.
' */

DECLARE FUNCTION RealGetWindowClassW IMPORT "USER32.DLL" ALIAS "RealGetWindowClassW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF ptszClassName AS WSTRINGZ _                    ' __out LPWSTR ptszClassName
 , BYVAL cchClassNameMax AS DWORD _                     ' __in UINT cchClassNameMax
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO RealGetWindowClass = RealGetWindowClassW
#ELSE
   MACRO RealGetWindowClass = RealGetWindowClassA
#ENDIF

'/*
' * Alt-Tab Switch window information.
' */

' // Size = 40 bytes
TYPE ALTTABINFO DWORD
   cbSize    AS DWORD   ' DWORD
   cItems    AS LONG    ' int
   cColumns  AS LONG    ' int
   cRows     AS LONG    ' int
   iColFocus AS LONG    ' int
   iRowFocus AS LONG    ' int
   cxItem    AS LONG    ' int
   cyItem    AS LONG    ' int
   ptStart   AS POINT   ' POINT
END TYPE

DECLARE FUNCTION GetAltTabInfoA IMPORT "USER32.DLL" ALIAS "GetAltTabInfoA" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL iItem AS LONG _                                ' __in int iItem
 , BYREF pati AS ALTTABINFO  _                          ' __inout PALTTABINFO pati
 , BYREF pszItemText AS ASCIIZ _                        ' __out LPSTR pszItemText
 , BYVAL cchItemText AS DWORD _                         ' __in UINT cchItemText
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetAltTabInfoW IMPORT "USER32.DLL" ALIAS "GetAltTabInfoW" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL iItem AS LONG _                                ' __in int iItem
 , BYREF pati AS ALTTABINFO _                           ' __inout PALTTABINFO pati
 , BYREF pszItemText AS WSTRINGZ _                      ' __out LPWSTR pszItemText
 , BYVAL cchItemText AS DWORD _                         ' __in UINT cchItemText
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetAltTabInfo = GetAltTabInfoW
#ELSE
   MACRO GetAltTabInfo = GetAltTabInfoA
#ENDIF

'/*
' * Listbox information.
' * Returns the number of items per row.
' */

DECLARE FUNCTION GetListBoxInfo IMPORT "USER32.DLL" ALIAS "GetListBoxInfo" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' DWORD

'#endif /* NOWINABLE */
'#ENDIF   ' #IF NOT %DEF(%NOWINABLE) ' -----------------------------------------
'#endif /* WINVER >= 0x0500 */


'#if(_WIN32_WINNT >= 0x0500)
DECLARE FUNCTION LockWorkStation IMPORT "USER32.DLL" ALIAS "LockWorkStation" ( _
 ) AS LONG                                              ' BOOL
'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION UserHandleGrantAccess IMPORT "USER32.DLL" ALIAS "UserHandleGrantAccess" ( _
   BYVAL hUserHandle AS DWORD _                         ' __in HANDLE hUserHandle
 , BYVAL hJob AS DWORD _                                ' __in HANDLE hJob
 , BYVAL bGrant AS LONG _                               ' __in BOOL   bGrant
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)

'/*
' * Raw Input Messages.
' */

'DECLARE_HANDLE(HRAWINPUT);

'/*
' * WM_INPUT wParam
' */

'/*
' * Use this macro to get the input code from wParam.
' */
'#define GET_RAWINPUT_CODE_WPARAM(wParam)    ((wParam) & 0xff)
MACRO GET_RAWINPUT_CODE_WPARAM(wParam) =  wParam AND &Hff

'/*
' * The input is in the regular message flow,
' * the app is required to call DefWindowProc
' * so that the system can perform clean ups.
' */
%RIM_INPUT     = 0&

'/*
' * The input is sink only. The app is expected
' * to behave nicely.
' */
%RIM_INPUTSINK = 1&

'/*
' * Raw Input data header
' */

' // Size = 16 bytes
TYPE RAWINPUTHEADER DWORD
   dwType  AS DWORD   ' DWORD
   dwSize  AS DWORD   ' DWORD
   hDevice AS DWORD   ' HANDLE
   wParam  AS DWORD   ' WPARAM
END TYPE

'/*
' * Type of the raw input
' */
%RIM_TYPEMOUSE    = 0&
%RIM_TYPEKEYBOARD = 1&
%RIM_TYPEHID      = 2&

'/*
' * Raw format of the mouse input
' */
'typedef struct tagRAWMOUSE {
'    /*
'     * Indicator flags.
'     */
'    USHORT usFlags;

'    /*
'     * The transition state of the mouse buttons.
'     */
'    union {
'        ULONG ulButtons;
'        struct  {
'            USHORT  usButtonFlags;
'            USHORT  usButtonData;
'        };
'    };


'    /*
'     * The raw state of the mouse buttons.
'     */
'    ULONG ulRawButtons;

'    /*
'     * The signed relative or absolute motion in the X direction.
'     */
'    LONG lLastX;

'    /*
'     * The signed relative or absolute motion in the Y direction.
'     */
'    LONG lLastY;

'    /*
'     * Device-specific additional information for the event.
'     */
'    ULONG ulExtraInformation;

'} RAWMOUSE, *PRAWMOUSE, *LPRAWMOUSE;

' // Size = 4 bytes
TYPE RAWMOUSEBUTTON WORD
   usButtonFlags AS WORD
   usButtonData  AS WORD
END TYPE

' // Size = 4 bytes
UNION RAWMOUSE_UNION
   ulButtons AS DWORD
   RAWMOUSEBUTTON
END UNION

' // Size = 24 bytes
TYPE RAWMOUSE DWORD
   usFlags            AS WORD    ' // indicator flags
   RAWMOUSE_UNION                ' // the transition state of the mouse buttons
   ulRawButtons       AS DWORD   ' // the raw state of the mouse buttons
   lLastX             AS LONG    ' // the signed relative or absolute motion in the X direction
   lLastY             AS LONG    ' // the signed relative or absolute motion in the Y direction
   ulExtraInformation AS DWORD   ' // device-specific additional information for the event
END TYPE

'/*
' * Define the mouse button state indicators.
' */

%RI_MOUSE_LEFT_BUTTON_DOWN   = &H0001??  ' // Left Button changed to down.
%RI_MOUSE_LEFT_BUTTON_UP     = &H0002??  ' // Left Button changed to up.
%RI_MOUSE_RIGHT_BUTTON_DOWN  = &H0004??  ' // Right Button changed to down.
%RI_MOUSE_RIGHT_BUTTON_UP    = &H0008??  ' // Right Button changed to up.
%RI_MOUSE_MIDDLE_BUTTON_DOWN = &H0010??  ' // Middle Button changed to down.
%RI_MOUSE_MIDDLE_BUTTON_UP   = &H0020??  ' // Middle Button changed to up.

%RI_MOUSE_BUTTON_1_DOWN      = %RI_MOUSE_LEFT_BUTTON_DOWN
%RI_MOUSE_BUTTON_1_UP        = %RI_MOUSE_LEFT_BUTTON_UP
%RI_MOUSE_BUTTON_2_DOWN      = %RI_MOUSE_RIGHT_BUTTON_DOWN
%RI_MOUSE_BUTTON_2_UP        = %RI_MOUSE_RIGHT_BUTTON_UP
%RI_MOUSE_BUTTON_3_DOWN      = %RI_MOUSE_MIDDLE_BUTTON_DOWN
%RI_MOUSE_BUTTON_3_UP        = %RI_MOUSE_MIDDLE_BUTTON_UP

%RI_MOUSE_BUTTON_4_DOWN      = &H0040??
%RI_MOUSE_BUTTON_4_UP        = &H0080??
%RI_MOUSE_BUTTON_5_DOWN      = &H0100??
%RI_MOUSE_BUTTON_5_UP        = &H0200??

'/*
' * If usButtonFlags has RI_MOUSE_WHEEL, the wheel delta is stored in usButtonData.
' * Take it as a signed value.
' */
%RI_MOUSE_WHEEL              = &H0400??

'/*
' * Define the mouse indicator flags.
' */
%MOUSE_MOVE_RELATIVE      = 0???
%MOUSE_MOVE_ABSOLUTE      = 1???
%MOUSE_VIRTUAL_DESKTOP    = &H02???  ' // the coordinates are mapped to the virtual desktop
%MOUSE_ATTRIBUTES_CHANGED = &H04???  ' // requery for mouse attributes
'#if(WINVER >= 0x0600)
%MOUSE_MOVE_NOCOALESCE    = &H08???  ' // do not coalesce mouse moves
'#endif /* WINVER >= 0x0600 */

'/*
' * Raw format of the keyboard input
' */
'typedef struct tagRAWKEYBOARD {
'    /*
'     * The "make" scan code (key depression).
'     */
'    USHORT MakeCode;

'    /*
'     * The flags field indicates a "break" (key release) and other
'     * miscellaneous scan code information defined in ntddkbd.h.
'     */
'    USHORT Flags;

'    USHORT Reserved;

'    /*
'     * Windows message compatible information
'     */
'    USHORT VKey;
'    UINT   Message;

'    /*
'     * Device-specific additional information for the event.
'     */
'    ULONG ExtraInformation;


'} RAWKEYBOARD, *PRAWKEYBOARD, *LPRAWKEYBOARD;

' // Size = 16 bytes
TYPE RAWKEYBOARD DWORD FILL
   MakeCode         AS WORD    ' // the "make" scan code (key depression)
   Flags            AS WORD    ' // the flags field indicates a "break" (key release) and other
   Reserved         AS WORD    ' // miscellaneous scan code information defined in ntddkbd.h
   VKey             AS WORD    ' // Windows message compatible information
   Message          AS DWORD
   ExtraInformation AS DWORD   ' // device-specific additional information for the event
END TYPE

'/*
' * Define the keyboard overrun MakeCode.
' */

%KEYBOARD_OVERRUN_MAKE_CODE  = &HFF??

'/*
' * Define the keyboard input data Flags.
' */
%RI_KEY_MAKE             = 0??
%RI_KEY_BREAK            = 1??
%RI_KEY_E0               = 2??
%RI_KEY_E1               = 4??
%RI_KEY_TERMSRV_SET_LED  = 8??
%RI_KEY_TERMSRV_SHADOW   = &H10??

'/*
' * Raw format of the input from Human Input Devices
' */

' // Size = 12 bytes
TYPE RAWHID DWORD
   dwSizeHid   AS DWORD   ' DWORD // byte size of each report
   dwCount     AS DWORD   ' DWORD // number of input packed
   bRawData(0) AS BYTE    ' BYTE  bRawData[1]
END TYPE

'/*
' * RAWINPUT data structure.
' */
'typedef struct tagRAWINPUT {
'    RAWINPUTHEADER header;
'    union {
'        RAWMOUSE    mouse;
'        RAWKEYBOARD keyboard;
'        RAWHID      hid;
'    } data;
'} RAWINPUT, *PRAWINPUT, *LPRAWINPUT;

' // Size = 24 bytes
UNION RAWINPUT_UNION DWORD
   mouse     AS RAWMOUSE      ' RAWMOUSE
   keyboard  AS RAWKEYBOARD   ' RAWKEYBOARD
   hid       AS RAWHID        ' RAWHID
END UNION

UNION RAWINPUT_DATA_UNION DWORD
   data   AS RAWINPUT_UNION
   RAWINPUT_UNION
END UNION

' // Size = 40 bytes
TYPE RAWINPUT DWORD
   header AS RAWINPUTHEADER
   RAWINPUT_DATA_UNION
END TYPE

'#ifdef _WIN64
'#define RAWINPUT_ALIGN(x)   (((x) + sizeof(QWORD) - 1) & ~(sizeof(QWORD) - 1))
'#else   // _WIN64
'#define RAWINPUT_ALIGN(x)   (((x) + sizeof(DWORD) - 1) & ~(sizeof(DWORD) - 1))
'#endif  // _WIN64

'#define NEXTRAWINPUTBLOCK(ptr) ((PRAWINPUT)RAWINPUT_ALIGN((ULONG_PTR)((PBYTE)(ptr) + (ptr)->header.dwSize)))

'/*
' * Flags for GetRawInputData
' */

%RID_INPUT  = &H10000003???
%RID_HEADER = &H10000005???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetRawInputData LIB "User32.dll" ALIAS "GetRawInputData" _
    (BYVAL hRawInput AS DWORD, BYVAL uiCommand AS DWORD, _
    BYVAL pData AS DWORD, pcbSize AS DWORD, BYVAL cbSizeHeader AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION GetRawInputData IMPORT "USER32.DLL" ALIAS "GetRawInputData" ( _
   BYVAL hRawInput AS DWORD _                           ' __in HRAWINPUT hRawInput
 , BYVAL uiCommand AS DWORD _                           ' __in UINT uiCommand
 , BYREF pData AS ANY _                                 ' __out LPVOID pData
 , BYREF pcbSize AS DWORD _                             ' __inout PUINT pcbSize
 , BYVAL cbSizeHeader AS DWORD _                        ' __in UINT cbSizeHeader
 ) AS DWORD                                             ' UINT
#ENDIF

'/*
' * Raw Input Device Information
' */
%RIDI_PREPARSEDDATA = &H20000005???
%RIDI_DEVICENAME    = &H20000007??? ' the return value is the character length, not the byte size
%RIDI_DEVICEINFO    = &H2000000b???

' // Size = 16 bytes
TYPE RID_DEVICE_INFO_MOUSE DWORD
   dwId                AS DWORD   ' DWORD
   dwNumberOfButtons   AS DWORD   ' DWORD
   dwSampleRate        AS DWORD   ' DWORD
   fHasHorizontalWheel AS LONG    ' BOOL
END TYPE

' // Size = 24 bytes
TYPE RID_DEVICE_INFO_KEYBOARD DWORD
   dwType                 AS DWORD   ' DWORD
   dwSubType              AS DWORD   ' DWORD
   dwKeyboardMode         AS DWORD   ' DWORD
   dwNumberOfFunctionKeys AS DWORD   ' DWORD
   dwNumberOfIndicators   AS DWORD   ' DWORD
   dwNumberOfKeysTotal    AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE RID_DEVICE_INFO_HID DWORD FILL
   dwVendorId      AS DWORD   ' DWORD
   dwProductId     AS DWORD   ' DWORD
   dwVersionNumber AS DWORD   ' DWORD
   ' Top level collection UsagePage and Usage
   usUsagePage     AS WORD    ' USHORT
   usUsage         AS WORD    ' USHORT
END TYPE

'typedef struct tagRID_DEVICE_INFO {
'    DWORD cbSize;
'    DWORD dwType;
'    union {
'        RID_DEVICE_INFO_MOUSE mouse;
'        RID_DEVICE_INFO_KEYBOARD keyboard;
'        RID_DEVICE_INFO_HID hid;
'    };
'} RID_DEVICE_INFO, *PRID_DEVICE_INFO, *LPRID_DEVICE_INFO;

' // Size = 24 bytes
UNION RID_DEVICE_INFO_UNION DWORD
   mouse    AS RID_DEVICE_INFO_MOUSE
   keyboard AS RID_DEVICE_INFO_KEYBOARD
   hid      AS RID_DEVICE_INFO_HID
END UNION

' // Size = 32 bytes
TYPE RID_DEVICE_INFO DWORD
   cbSize AS DWORD   ' DWORD
   dwType AS DWORD   ' DWORD
   RID_DEVICE_INFO_UNION
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetRawInputDeviceInfoA LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoA" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetRawInputDeviceInfoA IMPORT "USER32.DLL" ALIAS "GetRawInputDeviceInfoA" ( _
   BYVAL hDevice AS DWORD _                             ' __in_opt HANDLE hDevice
 , BYVAL uiCommand AS DWORD _                           ' __in UINT uiCommand
 , BYREF pData AS ANY _                                 ' __in LPVOID pData
 , BYREF pcbSize AS DWORD _                             ' __inout PUINT pcbSize
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetRawInputDeviceInfoW LIB "User32.dll" _
    ALIAS "GetRawInputDeviceInfoW" (BYVAL hDevice AS DWORD, _
    BYVAL uiCommand AS DWORD, BYVAL pData AS DWORD, pcbSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetRawInputDeviceInfoW IMPORT "USER32.DLL" ALIAS "GetRawInputDeviceInfoW" ( _
   BYVAL hDevice AS DWORD _                             ' __in_opt HANDLE hDevice
 , BYVAL uiCommand AS DWORD _                           ' __in UINT uiCommand
 , BYREF pData AS ANY _                                 ' __in LPVOID pData
 , BYREF pcbSize AS DWORD _                             ' __inout PUINT pcbSize
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetRawInputDeviceInfo = GetRawInputDeviceInfoW
#ELSE
   MACRO GetRawInputDeviceInfo = GetRawInputDeviceInfoA
#ENDIF

'/*
' * Raw Input Bulk Read: GetRawInputBuffer
' */

DECLARE FUNCTION GetRawInputBuffer IMPORT "USER32.DLL" ALIAS "GetRawInputBuffer" ( _
   BYREF pData AS RAWINPUT _                            ' __out PRAWINPUT pData
 , BYREF pcbSize AS DWORD _                             ' __inout PUINT pcbSize
 , BYVAL cbSizeHeader AS DWORD _                        ' __in UINT cbSizeHeader
 ) AS DWORD                                             ' UINT

'/*
' * Raw Input request APIs
' */

' // Size = 12 bytes
TYPE RAWINPUTDEVICE DWORD FILL
   usUsagePage AS WORD    ' USHORT // Toplevel collection UsagePage
   usUsage     AS WORD    ' USHORT // Toplevel collection Usage
   dwFlags     AS DWORD   ' DWORD
   hwndTarget  AS DWORD   ' HWND   // Target hwnd. NULL = follows keyboard focus
END TYPE

%RIDEV_REMOVE       = &H00000001???
%RIDEV_EXCLUDE      = &H00000010???
%RIDEV_PAGEONLY     = &H00000020???
%RIDEV_NOLEGACY     = &H00000030???
%RIDEV_CAPTUREMOUSE = &H00000200???  ' // effective when mouse nolegacy is specified, otherwise it would be an error
%RIDEV_NOHOTKEYS    = &H00000200???  ' // effective for keyboard.
%RIDEV_APPKEYS      = &H00000400???  ' // effective for keyboard.
'#if(_WIN32_WINNT >= 0x0501)
%RIDEV_EXINPUTSINK  = &H00001000???
%RIDEV_DEVNOTIFY    = &H00002000???
'#endif /* _WIN32_WINNT >= 0x0501 */
%RIDEV_EXMODEMASK   = &H000000F0???

'#define RIDEV_EXMODE(mode)  ((mode) & RIDEV_EXMODEMASK)
MACRO RIDEV_EXMODE(mode) = mode AND %RIDEV_EXMODEMASK

'#if(_WIN32_WINNT >= 0x0501)
'/*
' * Flags for the WM_INPUT_DEVICE_CHANGE message.
' */
%GIDC_ARRIVAL            = 1
%GIDC_REMOVAL            = 2

'#if (_WIN32_WINNT >= 0x0601)
'#define GET_DEVICE_CHANGE_WPARAM(wParam)  (LOWORD(wParam))
MACRO GET_DEVICE_CHANGE_WPARAM(wParam) = LO(WORD, wParam)
'#elif (_WIN32_WINNT >= 0x0501)
'#define GET_DEVICE_CHANGE_LPARAM(lParam)  (LOWORD(lParam))
MACRO GET_DEVICE_CHANGE_LPARAM(lParam) = LO(WORD, lParam)
'#endif /* (_WIN32_WINNT >= 0x0601) */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RegisterRawInputDevices LIB "User32.dll" _
    ALIAS "RegisterRawInputDevices" _
    (BYVAL pRawInputDevices AS RAWINPUTDEVICE PTR, _
    BYVAL uiNumDevices AS DWORD, BYVAL cbSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION RegisterRawInputDevices IMPORT "USER32.DLL" ALIAS "RegisterRawInputDevices" ( _
   BYREF pRawInputDevices AS RAWINPUTDEVICE _           ' __in PCRAWINPUTDEVICE pRawInputDevices
 , BYVAL uiNumDevices AS DWORD _                        ' __in UINT uiNumDevices
 , BYVAL cbSize AS DWORD _                              ' __in UINT cbSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetRegisteredRawInputDevices LIB "User32.dll" _
    ALIAS "GetRegisteredRawInputDevices" _
    (BYVAL pRawInputDevices AS RAWINPUTDEVICE PTR, puiNumDevices AS DWORD, _
    BYVAL cbSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetRegisteredRawInputDevices IMPORT "USER32.DLL" ALIAS "GetRegisteredRawInputDevices" ( _
   BYREF pRawInputDevices AS RAWINPUTDEVICE _           ' __out PRAWINPUTDEVICE pRawInputDevices
 , BYREF uiNumDevices AS DWORD _                        ' __inout PUINT puiNumDevices
 , BYVAL cbSize AS DWORD _                              ' __in UINT cbSize
 ) AS DWORD                                             ' UINT
#ENDIF

' // Size = 8 bytes
TYPE RAWINPUTDEVICELIST DWORD
   hDevice AS DWORD   ' HANDLE
   dwType  AS DWORD   ' DWORD
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetRawInputDeviceList LIB "User32.dll" _
    ALIAS "GetRawInputDeviceList" _
    (BYVAL pRawInputDeviceList AS RAWINPUTDEVICELIST PTR, _
    puiNumDevices AS DWORD, _
    BYVAL cbSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION GetRawInputDeviceList IMPORT "USER32.DLL" ALIAS "GetRawInputDeviceList" ( _
   BYREF pRawInputDeviceList AS RAWINPUTDEVICELIST _    ' __out PRAWINPUTDEVICELIST pRawInputDeviceList
 , BYREF puiNumDevices AS DWORD _                       ' __inout PUINT puiNumDevices
 , BYVAL cbSize AS DWORD _                              ' __in UINT cbSize
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DefRawInputProc LIB "User32.dll" ALIAS "DefRawInputProc" _
    (BYVAL paRawInput AS RAWINPUT PTR, BYVAL nInput AS LONG, _
    BYVAL cbSizeHeader AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION DefRawInputProc IMPORT "USER32.DLL" ALIAS "DefRawInputProc" ( _
   BYREF paRawInput AS RAWINPUT _                       ' __in PRAWINPUT* paRawInput
 , BYVAL nInput AS LONG _                               ' __in INT nInput
 , BYVAL cbSizeHeader AS DWORD _                        ' __in UINT cbSizeHeader
 ) AS LONG                                              ' LRESULT
#ENDIF

'#endif /* _WIN32_WINNT >= 0x0501 */

'/*
' * Message Filter
' */

'#if(WINVER >= 0x0600)
%MSGFLT_ADD    = 1
%MSGFLT_REMOVE = 2

DECLARE FUNCTION ChangeWindowMessageFilter IMPORT "USER32.DLL" ALIAS "ChangeWindowMessageFilter" ( _
   BYVAL message AS DWORD _                             ' __in UINT message
 , BYVAL dwFlag AS DWORD _                              ' __in DWORD dwFlag
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0600 */

'#if(WINVER >= 0x0601)

'/*
' * Message filter info values (CHANGEFILTERSTRUCT.ExtStatus)
' */
%MSGFLTINFO_NONE                     = 0
%MSGFLTINFO_ALREADYALLOWED_FORWND    = 1
%MSGFLTINFO_ALREADYDISALLOWED_FORWND = 2
%MSGFLTINFO_ALLOWED_HIGHER           = 3

' // Size = 8 bytes
TYPE CHANGEFILTERSTRUCT DWORD
   cbSize    AS DWORD   ' DWORD
   ExtStatus AS DWORD   ' DWORD
END TYPE

'/*
' * Message filter action values (action parameter to ChangeWindowMessageFilterEx)
' */
%MSGFLT_RESET    = 0
%MSGFLT_ALLOW    = 1
%MSGFLT_DISALLOW = 2

DECLARE FUNCTION ChangeWindowMessageFilterEx IMPORT "USER32.DLL" ALIAS "ChangeWindowMessageFilterEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd                                      // Window
 , BYVAL message AS DWORD _                             ' __in UINT message                                   // WM_ message
 , BYVAL action AS DWORD _                              ' __in DWORD action                                   // Message filter action value
 , OPTIONAL BYREF pChangeFilterStruct AS CHANGEFILTERSTRUCT _ ' __inout_opt PCHANGEFILTERSTRUCT pChangeFilterStruct // Optional
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x0601 */


'#if(WINVER >= 0x0601)

'/*
' * Gesture defines and functions
' */

'/*
' * Gesture information handle
' */
'DECLARE_HANDLE(HGESTUREINFO);


'/*
' * Gesture flags - GESTUREINFO.dwFlags
' */
%GF_BEGIN   = &H00000001???
%GF_INERTIA = &H00000002???
%GF_END     = &H00000004???

'/*
' * Gesture IDs
' */
%GID_BEGIN        = 1
%GID_END          = 2
%GID_ZOOM         = 3
%GID_PAN          = 4
%GID_ROTATE       = 5
%GID_TWOFINGERTAP = 6
%GID_PRESSANDTAP  = 7
%GID_ROLLOVER     = %GID_PRESSANDTAP

'/*
' * Gesture information structure
' *   - Pass the HGESTUREINFO received in the WM_GESTURE message lParam into the
' *     GetGestureInfo function to retrieve this information.
' *   - If cbExtraArgs is non-zero, pass the HGESTUREINFO received in the WM_GESTURE
' *     message lParam into the GetGestureExtraArgs function to retrieve extended
' *     argument information.
' */
' // Size = 48 bytes
TYPE GESTUREINFO QWORD FILL   ' Must be 8 bytes aligned
   cbSize       AS DWORD    ' UINT // size, in bytes, of this structure (including variable length Args field)
   dwFlags      AS DWORD    ' DWORD // see GF_* flags
   dwID         AS DWORD    ' DWORD // gesture ID, see GID_* defines
   hwndTarget   AS DWORD    ' HWND // handle to window targeted by this gesture
   ptsLocation  AS POINTS   ' POINTS // current location of this gesture
   dwInstanceID AS DWORD    ' DWORD // internally used
   dwSequenceID AS DWORD    ' DWORD // internally used
   ullArguments AS QUAD     ' ULONGLONG // arguments for gestures whose arguments fit in 8 BYTES
   cbExtraArgs  AS DWORD    ' UINT // size, in bytes, of extra arguments, if any, that accompany this gesture
   alignment__  AS DWORD    ' // To keep 8 byte alignment
END TYPE

'/*
' * Gesture notification structure
' *   - The WM_GESTURENOTIFY message lParam contains a pointer to this structure.
' *   - The WM_GESTURENOTIFY message notifies a window that gesture recognition is
' *     in progress and a gesture will be generated if one is recognized under the
' *     current gesture settings.
' */
' // Size = 20 bytes
TYPE GESTURENOTIFYSTRUCT DWORD
   cbSize       AS DWORD    ' UINT // size, in bytes, of this structure
   dwFlags      AS DWORD    ' DWORD // unused
   hwndTarget   AS DWORD    ' HWND // handle to window targeted by the gesture
   ptsLocation  AS POINTS   ' POINTS // starting location
   dwInstanceID AS DWORD    ' DWORD // internally used
END TYPE

'/*
' * Gesture argument helpers
' *   - Angle should be a double in the range of -2pi to +2pi
' *   - Argument should be an unsigned 16-bit value
' */
'#define GID_ROTATE_ANGLE_TO_ARGUMENT(_arg_)     ((USHORT)((((_arg_) + 2.0 * 3.14159265) / (4.0 * 3.14159265)) * 65535.0))
MACRO GID_ROTATE_ANGLE_TO_ARGUMENT(arg) = BITS(WORD, (arg + 2.0 * 3.14159265) / (4.0 * 3.14159265)) * 65535.0

'#define GID_ROTATE_ANGLE_FROM_ARGUMENT(_arg_)   ((((double)(_arg_) / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265)
MACRO GID_ROTATE_ANGLE_FROM_ARGUMENT(arg) = ((arg / 65535.0) * 4.0 * 3.14159265) - 2.0 * 3.14159265

'/*
' * Gesture information retrieval
' *   - HGESTUREINFO is received by a window in the lParam of a WM_GESTURE message.
' */
DECLARE FUNCTION GetGestureInfo IMPORT "USER32.DLL" ALIAS "GetGestureInfo" ( _
   BYVAL hGestureInfo AS DWORD _                        ' __in HGESTUREINFO hGestureInfo
 , BYREF pGestureInfo AS GESTUREINFO _                  ' __out PGESTUREINFO pGestureInfo
 ) AS LONG                                              ' BOOL

'/*
' * Gesture extra arguments retrieval
' *   - HGESTUREINFO is received by a window in the lParam of a WM_GESTURE message.
' *   - Size, in bytes, of the extra argument data is available in the cbExtraArgs
' *     field of the GESTUREINFO structure retrieved using the GetGestureInfo function.
' */
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetGestureExtraArgs LIB "User32.dll" _
    ALIAS "GetGestureExtraArgs" ( _
    BYVAL hGestureInfo AS DWORD, _   ' HGESTUREINFO
    BYVAL cbExtraArgs AS DWORD, _    ' UINT
    BYVAL pExtraArgs AS BYTE PTR) _
    AS LONG   ' BOOL
#ELSE
DECLARE FUNCTION GetGestureExtraArgs IMPORT "USER32.DLL" ALIAS "GetGestureExtraArgs" ( _
   BYVAL hGestureInfo AS DWORD _                        ' __in HGESTUREINFO hGestureInfo
 , BYVAL cbExtraArgs AS DWORD _                         ' __in UINT cbExtraArgs
 , BYREF pExtraArgs AS ANY _                            ' __out_bcount(cbExtraArgs) PBYTE pExtraArgs
 ) AS LONG                                              ' BOOL
#ENDIF

'/*
' * Gesture information handle management
' *   - If an application processes the WM_GESTURE message, then once it is done
' *     with the associated HGESTUREINFO, the application is responsible for
' *     closing the handle using this function. Failure to do so may result in
' *     process memory leaks.
' *   - If the message is instead passed to DefWindowProc, or is forwarded using
' *     one of the PostMessage or SendMessage class of API functions, the handle
' *     is transfered with the message and need not be closed by the application.
' */
DECLARE FUNCTION CloseGestureInfoHandle IMPORT "USER32.DLL" ALIAS "CloseGestureInfoHandle" ( _
   BYVAL hGestureInfo AS DWORD _                        ' __in HGESTUREINFO hGestureInfo
 ) AS LONG                                              ' BOOL

'/*
' * Gesture configuration structure
' *   - Used in SetGestureConfig and GetGestureConfig
' *   - Note that any setting not included in either GESTURECONFIG.dwWant or
' *     GESTURECONFIG.dwBlock will use the parent window's preferences or
' *     system defaults.
' */
' // Size = 12 bytes
TYPE GESTURECONFIG DWORD
   dwID    AS DWORD   ' DWORD // gesture ID
   dwWant  AS DWORD   ' DWORD // settings related to gesture ID that are to be turned on
   dwBlock AS DWORD   ' DWORD // settings related to gesture ID that are to be turned off
END TYPE

'/*
' * Gesture configuration flags - GESTURECONFIG.dwWant or GESTURECONFIG.dwBlock
' */

'/*
' * Common gesture configuration flags - set GESTURECONFIG.dwID to zero
' */
%GC_ALLGESTURES                              = &H00000001???

'/*
' * Zoom gesture configuration flags - set GESTURECONFIG.dwID to GID_ZOOM
' */
%GC_ZOOM                                     = &H00000001???

'/*
' * Pan gesture configuration flags - set GESTURECONFIG.dwID to GID_PAN
' */
%GC_PAN                                      = &H00000001???
%GC_PAN_WITH_SINGLE_FINGER_VERTICALLY        = &H00000002???
%GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY      = &H00000004???
%GC_PAN_WITH_GUTTER                          = &H00000008???
%GC_PAN_WITH_INERTIA                         = &H00000010???

'/*
' * Rotate gesture configuration flags - set GESTURECONFIG.dwID to GID_ROTATE
' */
%GC_ROTATE                                   = &H00000001???

'/*
' * Two finger tap gesture configuration flags - set GESTURECONFIG.dwID to GID_TWOFINGERTAP
' */
%GC_TWOFINGERTAP                             = &H00000001???

'/*
' * PressAndTap gesture configuration flags - set GESTURECONFIG.dwID to GID_PRESSANDTAP
' */
%GC_PRESSANDTAP                              = &H00000001???
%GC_ROLLOVER                                 = %GC_PRESSANDTAP

%GESTURECONFIGMAXCOUNT = 256   ' // Maximum number of gestures that can be included
                               ' // in a single call to SetGestureConfig / GetGestureConfig

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetGestureConfig LIB "User32.dll" ALIAS "SetGestureConfig" ( _
    BYVAL hwnd           AS DWORD, _              ' window for which configuration is specified
    BYVAL dwReserved     AS DWORD, _              ' reserved, must be 0
    BYVAL cIDs           AS DWORD, _              ' count of GESTURECONFIG structures
    BYVAL pGestureConfig AS GESTURECONFIG PTR, _  ' array of GESTURECONFIG structures, dwIDs will be processed in the
    _                                             ' order specified and repeated occurances will overwrite previous ones
    BYVAL cbSize         AS DWORD) _              ' sizeof(GESTURECONFIG)
    AS LONG   ' BOOL
#ELSE
DECLARE FUNCTION SetGestureConfig IMPORT "USER32.DLL" ALIAS "SetGestureConfig" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd                                  // window for which configuration is specified
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved                           // reserved, must be 0
 , BYVAL cIDs AS DWORD _                                ' __in UINT cIDs                                  // count of GESTURECONFIG structures
 , BYREF pGestureConfig AS GESTURECONFIG _              ' __in_ecount(cIDs) PGESTURECONFIG pGestureConfig // array of GESTURECONFIG structures, dwIDs will be processed in the order specified and repeated occurances will overwrite previous ones
 , BYVAL cbSize AS DWORD _                              ' __in UINT cbSize                                // sizeof(GESTURECONFIG)
 ) AS LONG                                              ' BOOL
#ENDIF

%GCF_INCLUDE_ANCESTORS           = &H00000001???   ' // If specified, GetGestureConfig returns consolidated configuration
                                                   ' // for the specified window and it's parent window chain

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetGestureConfig LIB "User32.dll" ALIAS "GetGestureConfig" ( _
    BYVAL hwnd           AS DWORD, _              ' window for which configuration is required
    BYVAL dwReserved     AS DWORD, _              ' reserved, must be 0
    BYVAL dwFlags        AS DWORD, _              ' see GCF_* flags
    BYVAL pcIDs          AS DWORD PTR, _          ' *pcIDs contains the size, in number of GESTURECONFIG structures,
    _                                             ' of the buffer pointed to by pGestureConfig
    BYVAL pGestureConfig AS GESTURECONFIG PTR, _
    _                                             ' pointer to buffer to receive the returned array of GESTURECONFIG structures
    BYVAL cbSize         AS DWORD) _              ' sizeof(GESTURECONFIG)
    AS LONG   ' BOOL
#ELSE
DECLARE FUNCTION GetGestureConfig IMPORT "USER32.DLL" ALIAS "GetGestureConfig" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd        // window for which configuration is required
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved // reserved, must be 0
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags    // see GCF_* flags
 , BYREF pcIDs AS DWORD _                               ' __in PUINT pcIDs      // *pcIDs contains the size, in number of GESTURECONFIG structures, of the buffer pointed to by pGestureConfig
 , BYREF pGestureConfig AS GESTURECONFIG _              ' __inout_ecount(*pcIDs) PGESTURECONFIG pGestureConfig pointer to buffer to receive the returned array of GESTURECONFIG structures
 , BYVAL cbSize AS DWORD _                              ' __in UINT cbSize      // sizeof(GESTURECONFIG)
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif /* WINVER >= 0x0601 */

'#if(WINVER >= 0x0601)

'/*
' * GetSystemMetrics(SM_DIGITIZER) flag values
' */
%NID_INTEGRATED_TOUCH  = &H00000001???
%NID_EXTERNAL_TOUCH    = &H00000002???
%NID_INTEGRATED_PEN    = &H00000004???
%NID_EXTERNAL_PEN      = &H00000008???
%NID_MULTI_INPUT       = &H00000040???
%NID_READY             = &H00000080???

'#endif /* WINVER >= 0x0601 */

%MAX_STR_BLOCKREASON = 256

DECLARE FUNCTION ShutdownBlockReasonCreate IMPORT "USER32.DLL" ALIAS "ShutdownBlockReasonCreate" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pwszReason AS WSTRINGZ _                       ' __in LPCWSTR pwszReason
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShutdownBlockReasonQuery IMPORT "USER32.DLL" ALIAS "ShutdownBlockReasonQuery" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYREF pwszBuff AS WSTRINGZ _                         ' __out LPWSTR pwszBuff
 , BYREF pcchBuff AS DWORD _                            ' __inout DWORD *pcchBuff
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShutdownBlockReasonDestroy IMPORT "USER32.DLL" ALIAS "ShutdownBlockReasonDestroy" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 ) AS LONG                                              ' BOOL
