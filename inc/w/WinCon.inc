' ########################################################################################
' Microsoft Windows
' File: WinCon.inc
' Contents: Public data structures, data types, and procedures exported by the NT
' console subsystem.
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
%WINCON_INC = 1

#IF NOT %DEF(%NOGDI)
#INCLUDE ONCE "wingdi.inc"
#ENDIF

' // Size = 4 bytes
TYPE COORD WORD
   x AS INTEGER   ' SHORT X
   y AS INTEGER   ' SHORT Y
END TYPE

TYPE SMALL_RECT1 WORD
   xLeft   AS INTEGER
   xTop    AS INTEGER
   xRight  AS INTEGER
   xBottom AS INTEGER
END TYPE

TYPE SMALL_RECT2 WORD
   nLeft   AS INTEGER
   nTop    AS INTEGER
   nRight  AS INTEGER
   nBottom AS INTEGER
END TYPE

TYPE SMALL_RECT3 WORD
   Left   AS INTEGER
   Top    AS INTEGER
   Right  AS INTEGER
   Bottom AS INTEGER
END TYPE

' // Size = 8 bytes
UNION SMALL_RECT WORD
   SMALL_RECT1
   SMALL_RECT2
   SMALL_RECT3
END UNION

'typedef struct _KEY_EVENT_RECORD {
'    BOOL bKeyDown;
'    WORD wRepeatCount;
'    WORD wVirtualKeyCode;
'    WORD wVirtualScanCode;
'    union {
'        WCHAR UnicodeChar;
'        CHAR   AsciiChar;
'    } uChar;
'    DWORD dwControlKeyState;
'} KEY_EVENT_RECORD, *PKEY_EVENT_RECORD;

' // Size = 2 bytes
UNION KEY_EVENT_RECORD_UNION_uChar WORD
   UnicodeChar AS WORD   ' WCHAR UnicodeChar
   AsciiChar   AS BYTE   ' CHAR   AsciiChar
END UNION

' // Size = 16 bytes
TYPE KEY_EVENT_RECORD DWORD FILL
   bKeyDown          AS LONG    ' BOOL bKeyDown
   wRepeatCount      AS WORD    ' WORD wRepeatCount
   wVirtualKeyCode   AS WORD    ' WORD wVirtualKeyCode
   wVirtualScanCode  AS WORD    ' WORD wVirtualScanCode
   KEY_EVENT_RECORD_UNION_uChar
   dwControlKeyState AS DWORD   ' DWORD dwControlKeyState
END TYPE

'//
'// ControlKeyState flags
'//

%RIGHT_ALT_PRESSED  = &H0001???      ' the right alt key is pressed.
%LEFT_ALT_PRESSED   = &H0002???      ' the left alt key is pressed.
%RIGHT_CTRL_PRESSED = &H0004???      ' the right ctrl key is pressed.
%LEFT_CTRL_PRESSED  = &H0008???      ' the left ctrl key is pressed.
%SHIFT_PRESSED      = &H0010???      ' the shift key is pressed.
%NUMLOCK_ON         = &H0020???      ' the numlock light is on.
%SCROLLLOCK_ON      = &H0040???      ' the scrolllock light is on.
%CAPSLOCK_ON        = &H0080???      ' the capslock light is on.
%ENHANCED_KEY       = &H0100???      ' the key is enhanced.

%NLS_DBCSCHAR       = &H00010000???  ' // DBCS for JPN: SBCS/DBCS mode.
%NLS_ALPHANUMERIC   = &H00000000???  ' // DBCS for JPN: Alphanumeric mode.
%NLS_KATAKANA       = &H00020000???  ' // DBCS for JPN: Katakana mode.
%NLS_HIRAGANA       = &H00040000???  ' // DBCS for JPN: Hiragana mode.
%NLS_ROMAN          = &H00400000???  ' // DBCS for JPN: Roman/Noroman mode.
%NLS_IME_CONVERSION = &H00800000???  ' // DBCS for JPN: IME conversion.
%NLS_IME_DISABLE    = &H20000000???  ' // DBCS for JPN: IME enable/disable.

' // Size = 16 bytes
TYPE MOUSE_EVENT_RECORD DWORD FILL
   dwMousePosition   AS COORD   ' COORD dwMousePosition
   dwButtonState     AS DWORD   ' DWORD dwButtonState
   dwControlKeyState AS DWORD   ' DWORD dwControlKeyState
   dwEventFlags      AS DWORD   ' DWORD dwEventFlags
END TYPE

'//
'// ButtonState flags
'//

%FROM_LEFT_1ST_BUTTON_PRESSED = &H0001???
%RIGHTMOST_BUTTON_PRESSED     = &H0002???
%FROM_LEFT_2ND_BUTTON_PRESSED = &H0004???
%FROM_LEFT_3RD_BUTTON_PRESSED = &H0008???
%FROM_LEFT_4TH_BUTTON_PRESSED = &H0010???

'//
'// EventFlags
'//

%MOUSE_MOVED    = &H0001???
%DOUBLE_CLICK   = &H0002???
%MOUSE_WHEELED  = &H0004???
'#if(_WIN32_WINNT >= 0x0600)
%MOUSE_HWHEELED = &H0008???
'#endif /* _WIN32_WINNT >= 0x0600 */

' // Size = 4 bytes
TYPE WINDOW_BUFFER_SIZE_RECORD WORD
   dwSize AS COORD   ' COORD dwSize
END TYPE

' // Size = 4 bytes
TYPE MENU_EVENT_RECORD DWORD
   dwCommandId AS DWORD   ' UINT dwCommandId
END TYPE

' // Size = 4 bytes
TYPE FOCUS_EVENT_RECORD DWORD
   bSetFocus AS LONG   ' BOOL bSetFocus
END TYPE

'typedef struct _INPUT_RECORD {
'    WORD EventType;
'    union {
'        KEY_EVENT_RECORD KeyEvent;
'        MOUSE_EVENT_RECORD MouseEvent;
'        WINDOW_BUFFER_SIZE_RECORD WindowBufferSizeEvent;
'        MENU_EVENT_RECORD MenuEvent;
'        FOCUS_EVENT_RECORD FocusEvent;
'    } Event;
'} INPUT_RECORD, *PINPUT_RECORD;

' // Size = 16 bytes
UNION INPUT_RECORD_UNION_Event DWORD
   KeyEvent              AS KEY_EVENT_RECORD
   MouseEvent            AS MOUSE_EVENT_RECORD
   WindowBufferSizeEvent AS WINDOW_BUFFER_SIZE_RECORD
   MenuEvent             AS MENU_EVENT_RECORD
   FocusEvent            AS FOCUS_EVENT_RECORD
END UNION

' // Size = 20 bytes
TYPE INPUT_RECORD_UNION DWORD
   Event AS INPUT_RECORD_UNION_Event
   INPUT_RECORD_UNION_Event
END TYPE

TYPE INPUT_RECORD DWORD
   EventType AS WORD
   INPUT_RECORD_UNION
END TYPE

'//
'//  EventType flags:
'//

%KEY_EVENT                = &H0001???     ' Event contains key event record
%MOUSE_EVENT              = &H0002???     ' Event contains mouse event record
%WINDOW_BUFFER_SIZE_EVENT = &H0004???     ' Event contains window change event record
%MENU_EVENT               = &H0008???     ' Event contains menu event record
%FOCUS_EVENT              = &H0010???     ' event contains focus change

'typedef struct _CHAR_INFO {
'    union {
'        WCHAR UnicodeChar;
'        CHAR   AsciiChar;
'    } Char;
'    WORD Attributes;
'} CHAR_INFO, *PCHAR_INFO;

' // Size = 2 bytes
UNION CHAR_INFO_UNION_Char WORD
   UnicodeChar AS WORD
   AsciiChar   AS BYTE
END UNION

' // Size = 4 bytes
TYPE CHAR_INFO WORD
   Char AS CHAR_INFO_UNION_Char
   Attributes AS WORD
END TYPE

'//
'// Attributes flags:
'//

%FOREGROUND_BLUE            = &H0001??     ' text color contains blue.
%FOREGROUND_GREEN           = &H0002??     ' text color contains green.
%FOREGROUND_RED             = &H0004??     ' text color contains red.
%FOREGROUND_INTENSITY       = &H0008??     ' text color is intensified.
%BACKGROUND_BLUE            = &H0010??     ' background color contains blue.
%BACKGROUND_GREEN           = &H0020??     ' background color contains green.
%BACKGROUND_RED             = &H0040??     ' background color contains red.
%BACKGROUND_INTENSITY       = &H0080??     ' background color is intensified.

%COMMON_LVB_LEADING_BYTE    = &H0100??  ' // Leading Byte of DBCS
%COMMON_LVB_TRAILING_BYTE   = &H0200??  ' // Trailing Byte of DBCS
%COMMON_LVB_GRID_HORIZONTAL = &H0400??  ' // DBCS: Grid attribute: top horizontal.
%COMMON_LVB_GRID_LVERTICAL  = &H0800??  ' // DBCS: Grid attribute: left vertical.
%COMMON_LVB_GRID_RVERTICAL  = &H1000??  ' // DBCS: Grid attribute: right vertical.
%COMMON_LVB_REVERSE_VIDEO   = &H4000??  ' // DBCS: Reverse fore/back ground attribute.
%COMMON_LVB_UNDERSCORE      = &H8000??  ' // DBCS: Underscore.

%COMMON_LVB_SBCSDBCS        = &H0300??  ' // SBCS or DBCS flag.

' // Size = 22 bytes
TYPE CONSOLE_SCREEN_BUFFER_INFO WORD
   dwSize              AS COORD        ' COORD dwSize
   dwCursorPosition    AS COORD        ' COORD dwCursorPosition
   wAttributes         AS WORD         ' WORD  wAttributes
   srWindow            AS SMALL_RECT   ' SMALL_RECT srWindow
   dwMaximumWindowSize AS COORD        ' COORD dwMaximumWindowSize
END TYPE

' // Size = 96 bytes
TYPE CONSOLE_SCREEN_BUFFER_INFOEX WORD
   cbSize               AS DWORD        ' ULONG
   dwSize               AS COORD        ' COORD
   dwCursorPosition     AS COORD        ' COORD
   wAttributes          AS WORD         ' WORD
   srWindow             AS SMALL_RECT   ' SMALL_RECT
   dwMaximumWindowSize  AS COORD        ' COORD
   wPopupAttributes     AS WORD         ' WORD
   bFullscreenSupported AS LONG         ' BOOL
   ColorTable(15)       AS DWORD        ' COLORREF
END TYPE

' // Size = 8 bytes
TYPE CONSOLE_CURSOR_INFO DWORD
   dwSize   AS DWORD   ' DWORD  dwSize
   bVisible AS LONG    ' BOOL   bVisible
END TYPE

' // Size = 8 bytes
TYPE CONSOLE_FONT_INFO DWORD
   nFont      AS DWORD   ' DWORD  nFont
   dwFontSize AS COORD   ' COORD  dwFontSize
END TYPE

'#if(_WIN32_WINNT >= 0x0500)

' // Size = 16 bytes
TYPE CONSOLE_SELECTION_INFO DWORD
   dwFlags           AS DWORD        ' DWORD dwFlags
   dwSelectionAnchor AS COORD        ' COORD dwSelectionAnchor
   srSelection       AS SMALL_RECT   ' SMALL_RECT srSelection
END TYPE

#IF NOT %DEF(%NOGDI)
' // Size = 84 bytes
TYPE CONSOLE_FONT_INFOEX DWORD
   cbSize     AS DWORD   ' ULONG
   nFont      AS DWORD   ' DWORD
   dwFontSize AS COORD   ' COORD
   FontFamily AS DWORD   ' UINT
   FontWeight AS DWORD   ' UINT
   FaceName   AS WSTRINGZ * %LF_FACESIZE   ' WCHAR
END TYPE
#ENDIF

%HISTORY_NO_DUP_FLAG = &H1
' // Size = 16 bytes
TYPE CONSOLE_HISTORY_INFO DWORD
   cbSize                 AS DWORD   ' UINT
   HistoryBufferSize      AS DWORD   ' UINT
   NumberOfHistoryBuffers AS DWORD   ' UINT
   dwFlags                AS DWORD   ' DWORD
END TYPE

'//
'// Selection flags
'//

%CONSOLE_NO_SELECTION            = &H0000???
%CONSOLE_SELECTION_IN_PROGRESS   = &H0001???   ' // selection has begun
%CONSOLE_SELECTION_NOT_EMPTY     = &H0002???   ' // non-null select rectangle
%CONSOLE_MOUSE_SELECTION         = &H0004???   ' // selecting with mouse
%CONSOLE_MOUSE_DOWN              = &H0008???   ' // mouse is down

'#endif /* _WIN32_WINNT >= 0x0500 */

'//
'// typedef for ctrl-c handler routines
'//

'typedef
'BOOL
'(WINAPI *PHANDLER_ROUTINE)(
'    DWORD CtrlType
'    );

%CTRL_C_EVENT        = 0
%CTRL_BREAK_EVENT    = 1
%CTRL_CLOSE_EVENT    = 2
'// 3 is reserved!
'// 4 is reserved!
%CTRL_LOGOFF_EVENT   = 5
%CTRL_SHUTDOWN_EVENT = 6

'//
'//  Input Mode flags:
'//

%ENABLE_PROCESSED_INPUT = &H0001???
%ENABLE_LINE_INPUT      = &H0002???
%ENABLE_ECHO_INPUT      = &H0004???
%ENABLE_WINDOW_INPUT    = &H0008???
%ENABLE_MOUSE_INPUT     = &H0010???
%ENABLE_INSERT_MODE     = &H0020???
%ENABLE_QUICK_EDIT_MODE = &H0040???
%ENABLE_EXTENDED_FLAGS  = &H0080???
%ENABLE_AUTO_POSITION   = &H0100???

'//
'// Output Mode flags:
'//

%ENABLE_PROCESSED_OUTPUT   = &H0001???
%ENABLE_WRAP_AT_EOL_OUTPUT = &H0002???

'//
'// direct API definitions.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PeekConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PeekConsoleInputA IMPORT "KERNEL32.DLL" ALIAS "PeekConsoleInputA" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS INPUT_RECORD _                     ' __out PINPUT_RECORD lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsRead AS DWORD _                ' __out LPDWORD lpNumberOfEventsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PeekConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "PeekConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PeekConsoleInputW IMPORT "KERNEL32.DLL" ALIAS "PeekConsoleInputW" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF INPUT_RECORD  _                                ' __out PINPUT_RECORD lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsRead AS DWORD _                ' __out LPDWORD lpNumberOfEventsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO PeekConsoleInput = PeekConsoleInputW
#ELSE
   MACRO PeekConsoleInput = PeekConsoleInputA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleInputA IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleInputA" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS INPUT_RECORD _                     ' __out PINPUT_RECORD lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsRead AS DWORD _                ' __out LPDWORD lpNumberOfEventsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nNumberOfCharsToRead AS LONG, _
    lpNumberOfCharsRead AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleInputW IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleInputW" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS INPUT_RECORD _                     ' __out PINPUT_RECORD lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsRead AS DWORD _                ' __out LPDWORD lpNumberOfEventsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ReadConsoleInput = ReadConsoleInputW
#ELSE
   MACRO ReadConsoleInput = ReadConsoleInputA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleInputA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputA" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleInputA IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleInputA" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS INPUT_RECORD _                     ' __in CONST INPUT_RECORD *lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsWritten AS DWORD _             ' __out LPDWORD lpNumberOfEventsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleInputW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleInputW" (BYVAL hConsoleInput AS DWORD, _
    BYVAL lpBuffer AS INPUT_RECORD PTR, BYVAL nLength AS DWORD, _
    lpNumberOfEventsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleInputW IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleInputW" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS INPUT_RECORD _                     ' __in CONST INPUT_RECORD *lpBuffer
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYREF lpNumberOfEventsWritten AS DWORD _             ' __out LPDWORD lpNumberOfEventsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WriteConsoleInput = WriteConsoleInputW
#ELSE
   MACRO WriteConsoleInput = WriteConsoleInputA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleOutputA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputA IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleOutputA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS CHAR_INFO _                        ' __out PCHAR_INFO lpBuffer
 , BYVAL dwBufferSize AS COORD _                        ' __in COORD dwBufferSize
 , BYVAL dwBufferCoord AS COORD _                       ' __in COORD dwBufferCoord
 , BYREF lpReadRegion AS SMALL_RECT _                   ' __in OUT PSMALL_RECT lpReadRegion
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleOutputW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpReadRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputW IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleOutputW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS CHAR_INFO _                        ' __out PCHAR_INFO lpBuffer
 , BYVAL dwBufferSize AS COORD _                        ' __in COORD dwBufferSize
 , BYVAL dwBufferCoord AS COORD _                       ' __in COORD dwBufferCoord
 , BYREF lpReadRegion AS SMALL_RECT _                   ' __in OUT PSMALL_RECT lpReadRegion
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ReadConsoleOutput = ReadConsoleOutputW
#ELSE
   MACRO ReadConsoleOutput = ReadConsoleOutputA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleOutputA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputA IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleOutputA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS CHAR_INFO _                        ' __in CONST CHAR_INFO *lpBuffer
 , BYVAL dwBufferSize AS COORD _                        ' __in COORD dwBufferSize
 , BYVAL dwBufferCoord AS COORD _                       ' __in COORD dwBufferCoord
 , BYREF lpWriteRegion AS SMALL_RECT _                  ' __in OUT PSMALL_RECT lpWriteRegion
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleOutputW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpBuffer AS CHAR_INFO PTR, BYVAL dwBufferSize AS DWORD, _
    BYVAL dwBufferCoord AS DWORD, lpWriteRegion AS SMALL_RECT) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputW IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleOutputW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS CHAR_INFO _                        ' __in CONST CHAR_INFO *lpBuffer
 , BYVAL dwBufferSize AS COORD _                        ' __in COORD dwBufferSize
 , BYVAL dwBufferCoord AS COORD _                       ' __in COORD dwBufferCoord
 , BYREF lpWriteRegion AS SMALL_RECT _                  ' __in OUT PSMALL_RECT lpWriteRegion
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WriteConsoleOutput = WriteConsoleOutputW
#ELSE
   MACRO WriteConsoleOutput = WriteConsoleOutputA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputCharacterA IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleOutputCharacterA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpCharacter AS ASCIIZ _                        ' __out LPSTR lpCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwReadCoord AS COORD _                         ' __in COORD dwReadCoord
 , BYREF lpNumberOfCharsRead AS DWORD _                 ' __out LPDWORD lpNumberOfCharsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfCharsRead AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputCharacterW IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleOutputCharacterW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpCharacter AS WSTRINGZ _                      ' __out LPWSTR lpCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwReadCoord AS COORD _                         ' __in COORD dwReadCoord
 , BYREF lpNumberOfCharsRead AS DWORD _                 ' __out LPDWORD lpNumberOfCharsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ReadConsoleOutputCharacter = ReadConsoleOutputCharacterW
#ELSE
   MACRO ReadConsoleOutputCharacter = ReadConsoleOutputCharacterA
#ENDIF

' lpAttribute has been declared as BYREF ANY instead of DWORD because it can be a single WORD
' variable (one attribute) or a buffer of nLength * sizeof(WORD).
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ReadConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "ReadConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpAttribute AS WORD PTR, BYVAL nLength AS DWORD, _
    BYVAL dwReadCoord AS DWORD, lpNumberOfAttrsRead AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION ReadConsoleOutputAttribute IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleOutputAttribute" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpAttribute AS ANY _                           ' __out LPWORD lpAttribute [may return an array of words]
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwReadCoord AS COORD _                         ' __in COORD dwReadCoord
 , BYREF lpNumberOfAttrsRead AS DWORD _                 ' __out LPDWORD lpNumberOfAttrsRead
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS ASCIIZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputCharacterA IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleOutputCharacterA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpCharacter AS ASCIIZ _                        ' __in LPCSTR lpCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD dwWriteCoord
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    szCharacter AS WSTRINGZ, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputCharacterW IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleOutputCharacterW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpCharacter AS WSTRINGZ _                      ' __in LPCWSTR lpCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD dwWriteCoord
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WriteConsoleOutputCharacter = WriteConsoleOutputCharacterW
#ELSE
   MACRO WriteConsoleOutputCharacter = WriteConsoleOutputCharacterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WriteConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "WriteConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL lpAttribute AS WORD PTR, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfAttrsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION WriteConsoleOutputAttribute IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleOutputAttribute" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpAttribute AS WORD _                          ' __in CONST WORD *lpAttribute
 , BYVAL nLength AS DWORD _                             ' __in DWORD nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD dwWriteCoord
 , BYREF lpNumberOfAttrsWritten AS DWORD _              ' __out LPDWORD lpNumberOfAttrsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FillConsoleOutputCharacterA LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterA" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS BYTE, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FillConsoleOutputCharacterA IMPORT "KERNEL32.DLL" ALIAS "FillConsoleOutputCharacterA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL cCharacter AS BYTE _                           ' __in CHAR  cCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD  nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD  dwWriteCoord
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FillConsoleOutputCharacterW LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputCharacterW" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL bCharacter AS WORD, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfCharsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FillConsoleOutputCharacterW IMPORT "KERNEL32.DLL" ALIAS "FillConsoleOutputCharacterW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL cCharacter AS WORD _                           ' __in WCHAR  cCharacter
 , BYVAL nLength AS DWORD _                             ' __in DWORD  nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD  dwWriteCoord
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO FillConsoleOutputCharacter = FillConsoleOutputCharacterW
#ELSE
   MACRO FillConsoleOutputCharacter = FillConsoleOutputCharacterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FillConsoleOutputAttribute LIB "KERNEL32.DLL" _
    ALIAS "FillConsoleOutputAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL wAttribute AS WORD, BYVAL nLength AS DWORD, _
    BYVAL dwWriteCoord AS DWORD, lpNumberOfAttrsWritten AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION FillConsoleOutputAttribute IMPORT "KERNEL32.DLL" ALIAS "FillConsoleOutputAttribute" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL wAttribute AS WORD _                           ' __in WORD   wAttribute
 , BYVAL nLength AS DWORD _                             ' __in DWORD  nLength
 , BYVAL dwWriteCoord AS COORD _                        ' __in COORD  dwWriteCoord
 , BYREF lpNumberOfAttrsWritten AS DWORD _              ' __out LPDWORD lpNumberOfAttrsWritten
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION GetConsoleMode IMPORT "KERNEL32.DLL" ALIAS "GetConsoleMode" ( _
   BYVAL hConsoleHandle AS DWORD  _                     ' __in HANDLE hConsoleHandle
 , BYREF lpMode AS DWORD _                              ' __out LPDWORD lpMode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNumberOfConsoleInputEvents IMPORT "KERNEL32.DLL" ALIAS "GetNumberOfConsoleInputEvents" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpNumberOfEvents AS DWORD _                    ' __out LPDWORD lpNumberOfEvents
 ) AS LONG                                              ' BOOL

'#define CONSOLE_REAL_OUTPUT_HANDLE (LongToHandle(-2))
'#define CONSOLE_REAL_INPUT_HANDLE (LongToHandle(-3))
#IF %DEF(%USEPNDECL)
%CONSOLE_REAL_OUTPUT_HANDLE = -2
%CONSOLE_REAL_INPUT_HANDLE  = -3
#ELSE
%CONSOLE_REAL_OUTPUT_HANDLE = &HFFFFFFFE???
%CONSOLE_REAL_INPUT_HANDLE  = &HFFFFFFFD???
#ENDIF

DECLARE FUNCTION GetConsoleScreenBufferInfo IMPORT "KERNEL32.DLL" ALIAS "GetConsoleScreenBufferInfo" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpConsoleScreenBufferInfo AS CONSOLE_SCREEN_BUFFER_INFO _ ' __out PCONSOLE_SCREEN_BUFFER_INFO lpConsoleScreenBufferInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetConsoleScreenBufferInfoEx IMPORT "KERNEL32.DLL" ALIAS "GetConsoleScreenBufferInfoEx" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpConsoleScreenBufferInfoEx AS CONSOLE_SCREEN_BUFFER_INFOEX _ ' __inout_bcount_part(sizeof(ULONG), sizeof(CONSOLE_SCREEN_BUFFER_INFOEX) - sizeof(ULONG)) PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx)
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetConsoleScreenBufferInfo IMPORT "KERNEL32.DLL" ALIAS "SetConsoleScreenBufferInfo" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpConsoleScreenBufferInfoEx AS CONSOLE_SCREEN_BUFFER_INFO _ ' __in PCONSOLE_SCREEN_BUFFER_INFOEX lpConsoleScreenBufferInfoEx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetLargestConsoleWindowSize IMPORT "KERNEL32.DLL" ALIAS "GetLargestConsoleWindowSize" ( _
   BYVAL hConsoleOutput AS DWORD _                       ' __in HANDLE hConsoleOutput
 ) AS DWORD                                              ' COORD

DECLARE FUNCTION GetConsoleCursorInfo IMPORT "KERNEL32.DLL" ALIAS "GetConsoleCursorInfo" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpConsoleCursorInfo AS CONSOLE_CURSOR_INFO _   ' __out PCONSOLE_CURSOR_INFO lpConsoleCursorInfo
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION GetCurrentConsoleFont IMPORT "KERNEL32.DLL" ALIAS "GetCurrentConsoleFont" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL bMaximumWindow AS LONG _                       ' __in BOOL bMaximumWindow
 , BYREF lpConsoleCurrentFont AS CONSOLE_FONT_INFO _    ' __out PCONSOLE_FONT_INFO lpConsoleCurrentFont
 ) AS LONG                                              ' BOOL

#IF NOT %DEF(%NOGDI)
DECLARE FUNCTION GetCurrentConsoleFontEx IMPORT "KERNEL32.DLL" ALIAS "GetCurrentConsoleFontEx" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL bMaximumWindow AS LONG _                       ' __in BOOL bMaximumWindow
 , BYREF lpConsoleCurrentFontEx AS CONSOLE_FONT_INFOEX _ ' __out PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetCurrentConsoleFontEx IMPORT "KERNEL32.DLL" ALIAS "SetCurrentConsoleFontEx" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL bMaximumWindow AS LONG _                       ' __in BOOL bMaximumWindow
 , BYREF lpConsoleCurrentFontEx AS CONSOLE_FONT_INFOEX _ ' __in PCONSOLE_FONT_INFOEX lpConsoleCurrentFontEx
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION GetConsoleHistoryInfo IMPORT "KERNEL32.DLL" ALIAS "GetConsoleHistoryInfo" ( _
   BYREF lpConsoleHistoryInfo AS CONSOLE_HISTORY_INFO _ ' __out PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetConsoleHistoryInfo IMPORT "KERNEL32.DLL" ALIAS "SetConsoleHistoryInfo" ( _
   BYREF lpConsoleHistoryInfo AS CONSOLE_HISTORY_INFO _ ' __in PCONSOLE_HISTORY_INFO lpConsoleHistoryInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetConsoleFontSize IMPORT "KERNEL32.DLL" ALIAS "GetConsoleFontSize" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL nFont AS DWORD _                               ' __in DWORD nFont
 ) AS DWORD                                             ' COORD

DECLARE FUNCTION GetConsoleSelectionInfo IMPORT "KERNEL32.DLL" ALIAS "GetConsoleSelectionInfo" ( _
   BYREF lpConsoleSelectionInfo AS CONSOLE_SELECTION_INFO _ ' __out PCONSOLE_SELECTION_INFO lpConsoleSelectionInfo
 ) AS LONG                                              ' BOOL

'#endif /* _WIN32_WINNT >= 0x0500 */

DECLARE FUNCTION GetNumberOfConsoleMouseButtons IMPORT "KERNEL32.DLL" ALIAS "GetNumberOfConsoleMouseButtons" ( _
   BYREF lpNumberOfMouseButtons AS DWORD _              ' __out LPDWORD lpNumberOfMouseButtons
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetConsoleMode IMPORT "KERNEL32.DLL" ALIAS "SetConsoleMode" ( _
   BYVAL hConsoleHandle AS DWORD  _                     ' __in HANDLE hConsoleHandle
 , BYVAL dwMode AS DWORD _                              ' __in DWORD dwMode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetConsoleActiveScreenBuffer IMPORT "KERNEL32.DLL" ALIAS "SetConsoleActiveScreenBuffer" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlushConsoleInputBuffer IMPORT "KERNEL32.DLL" ALIAS "FlushConsoleInputBuffer" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetConsoleScreenBufferSize LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleScreenBufferSize" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetConsoleScreenBufferSize IMPORT "KERNEL32.DLL" ALIAS "SetConsoleScreenBufferSize" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL dwSize AS COORD _                              ' __in COORD dwSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetConsoleCursorPosition LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleCursorPosition" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwCursorPosition AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetConsoleCursorPosition IMPORT "KERNEL32.DLL" ALIAS "SetConsoleCursorPosition" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL dwCursorPosition AS COORD _                    ' __in COORD dwCursorPosition
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetConsoleCursorInfo IMPORT "KERNEL32.DLL" ALIAS "SetConsoleCursorInfo" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpConsoleCursorInfo AS CONSOLE_CURSOR_INFO _   ' __in CONST CONSOLE_CURSOR_INFO *lpConsoleCursorInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ScrollConsoleScreenBufferA LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferA" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG
#ELSE
DECLARE FUNCTION ScrollConsoleScreenBufferA IMPORT "KERNEL32.DLL" ALIAS "ScrollConsoleScreenBufferA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpScrollRectangle AS SMALL_RECT _              ' __in CONST SMALL_RECT *lpScrollRectangle
 , BYREF lpClipRectangle AS SMALL_RECT _                ' __in CONST SMALL_RECT *lpClipRectangle
 , BYVAL dwDestinationOrigin AS COORD _                 ' __in COORD dwDestinationOrigin
 , BYREF lpFill AS CHAR_INFO _                          ' __in CONST CHAR_INFO *lpFill
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ScrollConsoleScreenBufferW LIB "KERNEL32.DLL" _
    ALIAS "ScrollConsoleScreenBufferW" (BYVAL hConsoleOutput AS DWORD, _
    lpScrollRectangle AS SMALL_RECT, lpClipRectangle AS SMALL_RECT, _
    BYVAL dwDestinationOrigin AS DWORD, lpFill AS CHAR_INFO) AS LONG
#ELSE
DECLARE FUNCTION ScrollConsoleScreenBufferW IMPORT "KERNEL32.DLL" ALIAS "ScrollConsoleScreenBufferW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpScrollRectangle AS SMALL_RECT _              ' __in CONST SMALL_RECT *lpScrollRectangle
 , BYREF lpClipRectangle AS SMALL_RECT _                ' __in CONST SMALL_RECT *lpClipRectangle
 , BYVAL dwDestinationOrigin AS COORD _                 ' __in COORD dwDestinationOrigin
 , BYREF lpFill AS CHAR_INFO _                          ' __in CONST CHAR_INFO *lpFill
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ScrollConsoleScreenBuffer = ScrollConsoleScreenBufferW
#ELSE
   MACRO ScrollConsoleScreenBuffer = ScrollConsoleScreenBufferA
#ENDIF

DECLARE FUNCTION SetConsoleWindowInfo IMPORT "KERNEL32.DLL" ALIAS "SetConsoleWindowInfo" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL bAbsolute AS LONG _                            ' __in BOOL bAbsolute
 , BYREF lpConsoleWindow AS SMALL_RECT _                ' __in CONST SMALL_RECT *lpConsoleWindow
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetConsoleTextAttribute LIB "KERNEL32.DLL" _
    ALIAS "SetConsoleTextAttribute" (BYVAL hConsoleOutput AS DWORD, _
    BYVAL dwAttributes AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SetConsoleTextAttribute IMPORT "KERNEL32.DLL" ALIAS "SetConsoleTextAttribute" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL wAttributes AS WORD _                          ' __in WORD wAttributes
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetConsoleCtrlHandler IMPORT "KERNEL32.DLL" ALIAS "SetConsoleCtrlHandler" ( _
   BYVAL HandlerRoutine AS DWORD _                      ' __in PHANDLER_ROUTINE HandlerRoutine
 , BYVAL Add AS LONG _                                  ' __in BOOL Add
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GenerateConsoleCtrlEvent IMPORT "KERNEL32.DLL" ALIAS "GenerateConsoleCtrlEvent" ( _
   BYVAL dwCtrlEvent AS DWORD  _                        ' __in DWORD dwCtrlEvent
 , BYVAL dwProcessGroupId AS DWORD _                    ' __in DWORD dwProcessGroupId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AllocConsole IMPORT "KERNEL32.DLL" ALIAS "AllocConsole" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreeConsole IMPORT "KERNEL32.DLL" ALIAS "FreeConsole" ( _
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)
DECLARE FUNCTION AttachConsole IMPORT "KERNEL32.DLL" ALIAS "AttachConsole" ( _
   BYVAL dwProcessId AS DWORD _                         ' __in DWORD dwProcessId
 ) AS LONG                                              ' BOOL

%ATTACH_PARENT_PROCESS = &HFFFFFFFF???   ' ((DWORD)-1)
'#endif /* _WIN32_WINNT >= 0x0500 */

DECLARE FUNCTION GetConsoleTitleA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleTitleA" ( _
   BYREF lpConsoleTitle AS ASCIIZ  _                    ' __out LPSTR lpConsoleTitle
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleTitleW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleTitleW" ( _
   BYREF lpConsoleTitle AS WSTRINGZ _                   ' __out LPWSTR lpConsoleTitle
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleTitle = GetConsoleTitleW
#ELSE
   MACRO GetConsoleTitle = GetConsoleTitleA
#ENDIF

'#if(_WIN32_WINNT >= 0x0600)
DECLARE FUNCTION GetConsoleOriginalTitleA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleOriginalTitleA" ( _
   BYREF lpConsoleTitle AS ASCIIZ  _                    ' __out LPSTR lpConsoleTitle
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleOriginalTitleW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleOriginalTitleW" ( _
   BYREF lpConsoleTitle AS WSTRINGZ _                   ' __out LPWSTR lpConsoleTitle
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleOriginalTitle = GetConsoleOriginalTitleW
#ELSE
   MACRO GetConsoleOriginalTitle = GetConsoleOriginalTitleA
#ENDIF
'#endif /* _WIN32_WINNT >= 0x0600 */

DECLARE FUNCTION SetConsoleTitleA IMPORT "KERNEL32.DLL" ALIAS "SetConsoleTitleA" ( _
   BYREF lpConsoleTitle AS ASCIIZ _                     ' __in LPCSTR lpConsoleTitle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetConsoleTitleW IMPORT "KERNEL32.DLL" ALIAS "SetConsoleTitleW" ( _
   BYREF lpConsoleTitle AS WSTRINGZ _                   ' __in LPCWSTR lpConsoleTitle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetConsoleTitle = SetConsoleTitleW
#ELSE
   MACRO SetConsoleTitle = SetConsoleTitleA
#ENDIF

' // Size = 16 bytes
TYPE CONSOLE_READCONSOLE_CONTROL DWORD
   nLength           AS DWORD   ' __in ULONG // sizeof( CONSOLE_READCONSOLE_CONTROL )
   nInitialChars     AS DWORD   ' __in ULONG
   dwCtrlWakeupMask  AS DWORD   ' __in ULONG
   dwControlKeyState AS DWORD   ' __out ULONG
END TYPE

DECLARE FUNCTION ReadConsoleA IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleA" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nNumberOfCharsToRead AS DWORD _                ' __in DWORD nNumberOfCharsToRead
 , BYREF lpNumberOfCharsRead AS DWORD _                 ' __out LPDWORD lpNumberOfCharsRead
 , BYREF pInputControl AS ANY _                         ' __in_opt PCONSOLE_READCONSOLE_CONTROL pInputControl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReadConsoleW IMPORT "KERNEL32.DLL" ALIAS "ReadConsoleW" ( _
   BYVAL hConsoleInput AS DWORD _                       ' __in HANDLE hConsoleInput
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYVAL nNumberOfCharsToRead AS DWORD _                ' __in DWORD nNumberOfCharsToRead
 , BYREF lpNumberOfCharsRead AS DWORD _                 ' __out LPDWORD lpNumberOfCharsRead
 , BYREF pInputControl AS ANY _                         ' __in_opt PCONSOLE_READCONSOLE_CONTROL pInputControl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ReadConsole = ReadConsoleW
#ELSE
   MACRO ReadConsole = ReadConsoleA
#ENDIF

DECLARE FUNCTION WriteConsoleA IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleA" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS ASCIIZ _                           ' __in CONST VOID *lpBuffer
 , BYVAL nNumberOfCharsToWrite AS DWORD _               ' __in DWORD nNumberOfCharsToWrite
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WriteConsoleW IMPORT "KERNEL32.DLL" ALIAS "WriteConsoleW" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYREF lpBuffer AS WSTRINGZ _                         ' __in CONST VOID *lpBuffer
 , BYVAL nNumberOfCharsToWrite AS DWORD _               ' __in DWORD nNumberOfCharsToWrite
 , BYREF lpNumberOfCharsWritten AS DWORD _              ' __out LPDWORD lpNumberOfCharsWritten
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO WriteConsole = WriteConsoleW
#ELSE
   MACRO WriteConsole = WriteConsoleA
#ENDIF

%CONSOLE_TEXTMODE_BUFFER = 1

DECLARE FUNCTION CreateConsoleScreenBuffer IMPORT "KERNEL32.DLL" ALIAS "CreateConsoleScreenBuffer" ( _
   BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in CONST SECURITY_ATTRIBUTES *lpSecurityAttributes
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lpScreenBufferData AS DWORD _                  ' __in LPVOID lpScreenBufferData
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION GetConsoleCP IMPORT "KERNEL32.DLL" ALIAS "GetConsoleCP" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetConsoleCP IMPORT "KERNEL32.DLL" ALIAS "SetConsoleCP" ( _
   BYVAL wCodePageID AS DWORD _                         ' __in UINT wCodePageID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetConsoleOutputCP IMPORT "KERNEL32.DLL" ALIAS "GetConsoleOutputCP" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetConsoleOutputCP IMPORT "KERNEL32.DLL" ALIAS "SetConsoleOutputCP" ( _
   BYVAL wCodePageID AS DWORD _                         ' __in UINT wCodePageID
 ) AS LONG                                              ' BOOL

'#if(_WIN32_WINNT >= 0x0500)

%CONSOLE_FULLSCREEN          = 1   ' // fullscreen console
%CONSOLE_FULLSCREEN_HARDWARE = 2   ' // console owns the hardware

DECLARE FUNCTION GetConsoleDisplayMode IMPORT "KERNEL32.DLL" ALIAS "GetConsoleDisplayMode" ( _
   BYREF lpModeFlags AS DWORD _                         ' __out LPDWORD lpModeFlags
 ) AS LONG                                              ' BOOL

%CONSOLE_FULLSCREEN_MODE = 1
%CONSOLE_WINDOWED_MODE   = 2

DECLARE FUNCTION SetConsoleDisplayMode IMPORT "KERNEL32.DLL" ALIAS "SetConsoleDisplayMode" ( _
   BYVAL hConsoleOutput AS DWORD _                      ' __in HANDLE hConsoleOutput
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lpNewScreenBufferDimensions AS COORD _         ' __out_opt PCOORD lpNewScreenBufferDimensions
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetConsoleWindow IMPORT "KERNEL32.DLL" ALIAS "GetConsoleWindow" ( _
 ) AS DWORD                                             ' HWND

'#endif /* _WIN32_WINNT >= 0x0500 */

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION GetConsoleProcessList IMPORT "KERNEL32.DLL" ALIAS "GetConsoleProcessList" ( _
   BYREF lpdwProcessList AS DWORD _                     ' __out LPDWORD lpdwProcessList
 , BYVAL dwProcessCount AS DWORD _                      ' __in DWORD dwProcessCount
 ) AS DWORD                                             ' DWORD

'//
'// Aliasing apis.
'//

DECLARE FUNCTION AddConsoleAliasA IMPORT "KERNEL32.DLL" ALIAS "AddConsoleAliasA" ( _
   BYREF Source AS ASCIIZ _                             ' __in LPSTR Source
 , BYREF Target AS ASCIIZ _                             ' __in LPSTR Target
 , BYREF ExeName AS ASCIIZ _                            ' __in LPSTR ExeName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddConsoleAliasW IMPORT "KERNEL32.DLL" ALIAS "AddConsoleAliasW" ( _
   BYREF Source AS WSTRINGZ _                           ' __in LPWSTR Source
 , BYREF Target AS WSTRINGZ _                           ' __in LPWSTR Target
 , BYREF ExeName AS WSTRINGZ _                           ' __in LPWSTR ExeName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AddConsoleAlias = AddConsoleAliasW
#ELSE
   MACRO AddConsoleAlias = AddConsoleAliasA
#ENDIF

DECLARE FUNCTION GetConsoleAliasA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasA" ( _
   BYREF Source AS ASCIIZ _                             ' __in LPSTR Source
 , BYREF TargetBuffer AS ASCIIZ _                       ' __out LPSTR TargetBuffer
 , BYVAL TargetBufferLength AS DWORD _                  ' __in DWORD TargetBufferLength
 , BYREF ExeName AS ASCIIZ _                            ' __in LPSTR ExeName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleAliasW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasW" ( _
   BYREF Source AS WSTRINGZ _                           ' __in LPWSTR Source
 , BYREF TargetBuffer AS WSTRINGZ _                     ' __out LPWSTR TargetBuffer
 , BYVAL TargetBufferLength AS DWORD _                  ' __in DWORD TargetBufferLength
 , BYREF ExeName AS WSTRINGZ _                          ' __in LPWSTR ExeName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleAlias = GetConsoleAliasW
#ELSE
   MACRO GetConsoleAlias = GetConsoleAliasA
#ENDIF

DECLARE FUNCTION GetConsoleAliasesLengthA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasesLengthA" ( _
   BYREF ExeName AS ASCIIZ _                            ' __in LPSTR ExeName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleAliasesLengthW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasesLengthW" ( _
   BYREF ExeName AS WSTRINGZ _                          ' __in LPWSTR ExeName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleAliasesLength = GetConsoleAliasesLengthW
#ELSE
   MACRO GetConsoleAliasesLength = GetConsoleAliasesLengthA
#ENDIF

DECLARE FUNCTION GetConsoleAliasExesLengthA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasExesLengthA" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleAliasExesLengthW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasExesLengthW" ( _
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleAliasExesLength = GetConsoleAliasExesLengthW
#ELSE
   MACRO GetConsoleAliasExesLength = GetConsoleAliasExesLengthA
#ENDIF

' PB declare
'DECLARE FUNCTION GetConsoleAliasesA LIB "Kernel32.dll" _
'    ALIAS "GetConsoleAliasesA" (BYVAL AliasBuffer AS DWORD, _
'    BYVAL AliasBufferLength AS DWORD, ExeName AS ASCIIZ) AS DWORD

DECLARE FUNCTION GetConsoleAliasesA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasesA" ( _
   BYREF AliasBuffer AS ASCIIZ _                        ' __out LPSTR AliasBuffer
 , BYVAL AliasBufferLength AS DWORD _                   ' __in DWORD AliasBufferLength
 , BYREF ExeName AS ASCIIZ _                            ' __in LPSTR ExeName
 ) AS DWORD                                             ' DWORD

' PB declare
'DECLARE FUNCTION GetConsoleAliasesW LIB "Kernel32.dll" _
'    ALIAS "GetConsoleAliasesW" (BYVAL AliasBuffer AS DWORD, _
'    BYVAL AliasBufferLength AS DWORD, ExeName AS WSTRINGZ) AS DWORD

DECLARE FUNCTION GetConsoleAliasesW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasesW" ( _
   BYREF AliasBuffer AS WSTRINGZ _                      ' __out LPWSTR AliasBuffer
 , BYVAL AliasBufferLength AS DWORD _                   ' __in DWORD AliasBufferLength
 , BYREF ExeName AS WSTRINGZ _                          ' __in LPWSTR ExeName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleAliases = GetConsoleAliasesW
#ELSE
   MACRO GetConsoleAliases = GetConsoleAliasesA
#ENDIF

DECLARE FUNCTION GetConsoleAliasExesA IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasExesA" ( _
   BYREF ExeNameBuffer AS ASCIIZ _                      ' __out LPSTR ExeNameBuffer
 , BYVAL ExeNameBufferLength AS DWORD _                 ' __in DWORD ExeNameBufferLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetConsoleAliasExesW IMPORT "KERNEL32.DLL" ALIAS "GetConsoleAliasExesW" ( _
   BYREF ExeNameBuffer AS WSTRINGZ _                    ' __out LPWSTR ExeNameBuffer
 , BYVAL ExeNameBufferLength AS DWORD _                 ' __in DWORD ExeNameBufferLength
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetConsoleAliasExes = GetConsoleAliasExesW
#ELSE
   MACRO GetConsoleAliasExes = GetConsoleAliasExesA
#ENDIF
