' ########################################################################################
' Microsoft Windows
' File: Imm.inc
' Contents: Input Method Manager definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IMM_INC = 1

#INCLUDE ONCE "windows.inc"

'typedef DWORD   HIMC;
'typedef DWORD   HIMCC;

'typedef HKL FAR  *LPHKL;
'typedef UINT FAR *LPUINT;

' // Size = 28 bytes
TYPE COMPOSITIONFORM DWORD
   dwStyle      AS DWORD   ' DWORD dwStyle
   ptCurrentPos AS POINT   ' POINT ptCurrentPos
   rcArea       AS RECT    ' RECT  rcArea
END TYPE

' // Size = 32 bytes
TYPE CANDIDATEFORM DWORD
   dwIndex      AS DWORD   ' DWORD dwIndex
   dwStyle      AS DWORD   ' DWORD dwStyle
   ptCurrentPos AS POINT   ' POINT ptCurrentPos
   rcArea       AS RECT    ' RECT  rcArea
END TYPE

' // Size = 28 bytes
TYPE CANDIDATELIST DWORD  ' ** NOT A REAL TYPE: for documentation purposes
   dwSize      AS DWORD   ' DWORD dwSize
   dwStyle     AS DWORD   ' DWORD dwStyle
   dwCount     AS DWORD   ' DWORD dwCount
   dwSelection AS DWORD   ' DWORD dwSelection
   dwPageStart AS DWORD   ' DWORD dwPageStart
   dwPageSize  AS DWORD   ' DWORD dwPageSize
   dwOffset(0) AS DWORD   ' DWORD dwOffset[1]
END TYPE

'typedef struct tagREGISTERWORDA {
'    ;
'    ;
'} REGISTERWORDA, *PREGISTERWORDA, NEAR *NPREGISTERWORDA, FAR *LPREGISTERWORDA;

' // Size = 8 bytes
TYPE REGISTERWORDA DWORD
   lpReading AS ASCIIZ PTR   ' LPSTR   lpReading
   lpWord    AS ASCIIZ PTR   ' LPSTR   lpWord
END TYPE

' // Size = 8 bytes
TYPE REGISTERWORDW DWORD
   lpReading AS WSTRINGZ PTR   ' LPWSTR   lpReading
   lpWord    AS WSTRINGZ PTR   ' LPWSTR   lpWord
END TYPE

' MACRO REGISTERWORD = REGISTERWORDA
' Not allowed. Conflicts with the RegisterWord method of the IActiveIME interface.
' We need to use a duplicate type instead.

#IF %DEF(%UNICODE)
' // Size = 8 bytes
TYPE REGISTERWORD DWORD
   lpReading AS WSTRINGZ PTR   ' LPWSTR   lpReading
   lpWord    AS WSTRINGZ PTR   ' LPWSTR   lpWord
END TYPE
#ELSE
' // Size = 8 bytes
TYPE REGISTERWORD DWORD
   lpReading AS ASCIIZ PTR   ' LPSTR   lpReading
   lpWord    AS ASCIIZ PTR   ' LPSTR   lpWord
END TYPE
#ENDIF

'#if (WINVER >= 0x040A)

' // Size = 32 bytes
TYPE RECONVERTSTRING DWORD
   dwSize            AS DWORD   ' DWORD dwSize
   dwVersion         AS DWORD   ' DWORD dwVersion
   dwStrLen          AS DWORD   ' DWORD dwStrLen
   dwStrOffset       AS DWORD   ' DWORD dwStrOffset
   dwCompStrLen      AS DWORD   ' DWORD dwCompStrLen
   dwCompStrOffset   AS DWORD   ' DWORD dwCompStrOffset
   dwTargetStrLen    AS DWORD   ' DWORD dwTargetStrLen
   dwTargetStrOffset AS DWORD   ' DWORD dwTargetStrOffset
END TYPE

'#endif /* WINVER >= 0x040A */

%STYLE_DESCRIPTION_SIZE = 32

' // Size = 36 bytes
TYPE STYLEBUFA DWORD
   dwStyle AS DWORD                                    ' DWORD dwStyle
   szDescription AS ASCIIZ * %STYLE_DESCRIPTION_SIZE   ' CHAR  szDescription[STYLE_DESCRIPTION_SIZE]
END TYPE

' // Size = 68 bytes
TYPE STYLEBUFW DWORD
   dwStyle AS DWORD                                      ' DWORD dwStyle
   szDescription AS WSTRINGZ * %STYLE_DESCRIPTION_SIZE   ' WCHAR  szDescription[STYLE_DESCRIPTION_SIZE]
END TYPE

#IF %DEF(%UNICODE)
MACRO STYLEBUF = STYLEBUFW
#ELSE
MACRO STYLEBUF = STYLEBUFA
#ENDIF

'#if (WINVER >= 0x040A)

%IMEMENUITEM_STRING_SIZE = 80

' // Size = 112 bytes
TYPE IMEMENUITEMINFOA DWORD
   cbSize        AS DWORD                               ' UINT    cbSize
   fType         AS DWORD                               ' UINT    fType
   fState        AS DWORD                               ' UINT    fState
   wID           AS DWORD                               ' UINT    wID
   hbmpChecked   AS DWORD                               ' HBITMAP hbmpChecked
   hbmpUnchecked AS DWORD                               ' HBITMAP hbmpUnchecked
   dwItemData    AS DWORD                               ' DWORD   dwItemData
   szString      AS ASCIIZ * %IMEMENUITEM_STRING_SIZE   ' CHAR    szString[IMEMENUITEM_STRING_SIZE]
   hbmpItem      AS DWORD                               ' HBITMAP hbmpItem;
END TYPE

' // Size = 192 bytes
TYPE IMEMENUITEMINFOW DWORD
   cbSize        AS DWORD                                 ' UINT    cbSize
   fType         AS DWORD                                 ' UINT    fType
   fState        AS DWORD                                 ' UINT    fState
   wID           AS DWORD                                 ' UINT    wID
   hbmpChecked   AS DWORD                                 ' HBITMAP hbmpChecked
   hbmpUnchecked AS DWORD                                 ' HBITMAP hbmpUnchecked
   dwItemData    AS DWORD                                 ' DWORD   dwItemData
   szString      AS WSTRINGZ * %IMEMENUITEM_STRING_SIZE   ' WCHAR   szString[IMEMENUITEM_STRING_SIZE]
   hbmpItem      AS DWORD                                 ' HBITMAP hbmpItem;
END TYPE

#IF %DEF(%UNICDE)
MACRO IMEMENUITEMINFO = IMEMENUITEMINFOW
#ELSE
MACRO IMEMENUITEMINFO = IMEMENUITEMINFOA
#ENDIF

' // Size = 36 bytes
TYPE IMECHARPOSITION DWORD
   dwSize      AS DWORD   ' DWORD       dwSize
   dwCharPos   AS DWORD   ' DWORD       dwCharPos
   pt          AS POINT   ' POINT       pt
   cLineHeight AS DWORD   ' UINT        cLineHeight
   rcDocument  AS RECT    ' RECT        rcDocument
END TYPE

'typedef BOOL    (CALLBACK* IMCENUMPROC)(HIMC, LPARAM);

'#endif /* WINVER >= 0x040A */


'// prototype of IMM API

DECLARE FUNCTION ImmInstallIMEA IMPORT "IMM32.DLL" ALIAS "ImmInstallIMEA" ( _
   BYREF lpszIMEFileName AS ASCIIZ _                    ' __in LPCSTR lpszIMEFileName
 , BYREF lpszLayoutText AS ASCIIZ _                     ' __in LPCSTR lpszLayoutText
 ) AS DWORD                                             ' HKL

DECLARE FUNCTION ImmInstallIMEW IMPORT "IMM32.DLL" ALIAS "ImmInstallIMEW" ( _
   BYREF lpszIMEFileName AS WSTRINGZ _                  ' __in LPCWSTR lpszIMEFileName
 , BYREF lpszLayoutText AS WSTRINGZ _                   ' __in LPCWSTR lpszLayoutText
 ) AS DWORD                                             ' HKL

#IF %DEF(%UNICODE)
   MACRO ImmInstallIME = ImmInstallIMEW
#ELSE
   MACRO ImmInstallIME = ImmInstallIMEA
#ENDIF

DECLARE FUNCTION ImmGetDefaultIMEWnd IMPORT "IMM32.DLL" ALIAS "ImmGetDefaultIMEWnd" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION ImmGetDescriptionA IMPORT "IMM32.DLL" ALIAS "ImmGetDescriptionA" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYREF lpszDescription AS ASCIIZ _                    ' __out LPSTR lpszDescription
 , BYVAL uBufLen AS DWORD _                             ' __in  UINT uBufLen
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ImmGetDescriptionW IMPORT "IMM32.DLL" ALIAS "ImmGetDescriptionW" ( _
   BYVAL hKl AS DWORD _                                 ' __in  HKL hKL
 , BYREF lpszDescription AS WSTRINGZ _                  ' __out LPWSTR lpszDescription
 , BYVAL uBufLen AS DWORD _                             ' __in  UINT uBufLen
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO ImmGetDescription = ImmGetDescriptionW
#ELSE
   MACRO ImmGetDescription = ImmGetDescriptionA
#ENDIF

DECLARE FUNCTION ImmGetIMEFileNameA IMPORT "IMM32.DLL" ALIAS "ImmGetIMEFileNameA" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYREF lpszFileName AS ASCIIZ _                       ' __out LPSTR lpszFileName
 , BYVAL uBufLen AS DWORD _                             ' __in  UINT uBufLen
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ImmGetIMEFileNameW IMPORT "IMM32.DLL" ALIAS "ImmGetIMEFileNameW" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYREF lpszFileName AS WSTRINGZ _                     ' __out LPWSTR lpszFileName
 , BYVAL uBufLen AS DWORD _                             ' __in  UINT uBufLen
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO ImmGetIMEFileName = ImmGetIMEFileNameW
#ELSE
   MACRO ImmGetIMEFileName = ImmGetIMEFileNameA
#ENDIF

DECLARE FUNCTION ImmGetProperty IMPORT "IMM32.DLL" ALIAS "ImmGetProperty" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL fdwIndex AS DWORD _                            ' __in DWORD fdwIndex
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmIsIME IMPORT "IMM32.DLL" ALIAS "ImmIsIME" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSimulateHotKey IMPORT "IMM32.DLL" ALIAS "ImmSimulateHotKey" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwHotKeyID AS DWORD _                          ' __in DWORD dwHotKeyID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmCreateContext IMPORT "IMM32.DLL" ALIAS "ImmCreateContext" ( _
 ) AS DWORD                                             ' HIMC

DECLARE FUNCTION ImmDestroyContext IMPORT "IMM32.DLL" ALIAS "ImmDestroyContext" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetContext IMPORT "IMM32.DLL" ALIAS "ImmGetContext" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' HIMC

DECLARE FUNCTION ImmReleaseContext IMPORT "IMM32.DLL" ALIAS "ImmReleaseContext" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmAssociateContext IMPORT "IMM32.DLL" ALIAS "ImmAssociateContext" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 ) AS DWORD                                             ' HIMC

'#if (WINVER >= 0x040A)
DECLARE FUNCTION ImmAssociateContextEx IMPORT "IMM32.DLL" ALIAS "ImmAssociateContextEx" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x040A */

DECLARE FUNCTION ImmGetCompositionStringA IMPORT "IMM32.DLL" ALIAS "ImmGetCompositionStringA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpBuf AS ANY _                                 ' __out LPVOID lpBuf
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS LONG                                              ' LONG

DECLARE FUNCTION ImmGetCompositionStringW IMPORT "IMM32.DLL" ALIAS "ImmGetCompositionStringW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpBuf AS ANY _                                 ' __out LPVOID lpBuf
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO ImmGetCompositionString = ImmGetCompositionStringW
#ELSE
   MACRO ImmGetCompositionString = ImmGetCompositionStringA
#ENDIF

DECLARE FUNCTION ImmSetCompositionStringA IMPORT "IMM32.DLL" ALIAS "ImmSetCompositionStringA" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpComp AS ANY _                                ' __in LPVOID lpComp
 , BYVAL dwCompLen AS DWORD _                           ' __in DWORD dwCompLen
 , BYREF lpRead AS ANY _                                ' __in LPVOID lpRead
 , BYVAL dwReadLen AS DWORD _                           ' __in DWORD dwReadLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetCompositionStringW IMPORT "IMM32.DLL" ALIAS "ImmSetCompositionStringW" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF lpComp AS ANY _                                ' __in LPVOID lpComp
 , BYVAL dwCompLen AS DWORD _                           ' __in DWORD dwCompLen
 , BYREF lpRead AS ANY _                                ' __in LPVOID lpRead
 , BYVAL dwReadLen AS DWORD _                           ' __in DWORD dwReadLen
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmSetCompositionString = ImmSetCompositionStringW
#ELSE
   MACRO ImmSetCompositionString = ImmSetCompositionStringA
#ENDIF

DECLARE FUNCTION ImmGetCandidateListCountA IMPORT "IMM32.DLL" ALIAS "ImmGetCandidateListCountA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpdwListCount AS DWORD _                       ' __out LPDWORD lpdwListCount
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmGetCandidateListCountW IMPORT "IMM32.DLL" ALIAS "ImmGetCandidateListCountW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpdwListCount AS DWORD _                       ' __out LPDWORD lpdwListCount
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ImmGetCandidateListCount = ImmGetCandidateListCountW
#ELSE
   MACRO ImmGetCandidateListCount = ImmGetCandidateListCountA
#ENDIF

DECLARE FUNCTION ImmGetCandidateListA IMPORT "IMM32.DLL" ALIAS "ImmGetCandidateListA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpCandList AS CANDIDATELIST _                  ' __out LPCANDIDATELIST lpCandList
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmGetCandidateListW IMPORT "IMM32.DLL" ALIAS "ImmGetCandidateListW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpCandList AS CANDIDATELIST _                  ' __out LPCANDIDATELIST lpCandList
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ImmGetCandidateList = ImmGetCandidateListW
#ELSE
   MACRO ImmGetCandidateList = ImmGetCandidateListA
#ENDIF

DECLARE FUNCTION ImmGetGuideLineA IMPORT "IMM32.DLL" ALIAS "ImmGetGuideLineA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpBuf AS ASCIIZ _                              ' __out LPSTR lpBuf
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmGetGuideLineW IMPORT "IMM32.DLL" ALIAS "ImmGetGuideLineW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpBuf AS WSTRINGZ _                            ' __out LPWSTR lpBuf
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ImmGetGuideLine = ImmGetGuideLineW
#ELSE
   MACRO ImmGetGuideLine = ImmGetGuideLineA
#ENDIF

DECLARE FUNCTION ImmGetConversionStatus IMPORT "IMM32.DLL" ALIAS "ImmGetConversionStatus" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpfdwConversion AS DWORD _                     ' __out_opt LPDWORD lpfdwConversion
 , BYREF lpfdwSentence AS DWORD _                       ' __out_opt LPDWORD lpfdwSentence
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetConversionStatus IMPORT "IMM32.DLL" ALIAS "ImmSetConversionStatus" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL fdwConversion AS DWORD _                       ' __in DWORD fdwConversion
 , BYVAL fdwSentence AS DWORD _                         ' __in DWORD fdwSentence
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetOpenStatus IMPORT "IMM32.DLL" ALIAS "ImmGetOpenStatus" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetOpenStatus IMPORT "IMM32.DLL" ALIAS "ImmSetOpenStatus" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL fOpen AS LONG _                                ' __in BOOL fOpen
 ) AS LONG                                              ' BOOL

#IF NOT %DEF(%NOGDI)

'#if defined(_WINGDI_) && !defined(NOGDI)
DECLARE FUNCTION ImmGetCompositionFontA IMPORT "IMM32.DLL" ALIAS "ImmGetCompositionFontA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lplf AS LOGFONTA _                             ' __out LPLOGFONTA lplf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetCompositionFontW IMPORT "IMM32.DLL" ALIAS "ImmGetCompositionFontW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lplf AS LOGFONTW _                             ' __out LPLOGFONTW lplf
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmGetCompositionFont = ImmGetCompositionFontW
#ELSE
   MACRO ImmGetCompositionFont = ImmGetCompositionFontA
#ENDIF

DECLARE FUNCTION ImmSetCompositionFontA IMPORT "IMM32.DLL" ALIAS "ImmSetCompositionFontA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lplf AS LOGFONTA _                             ' __out LPLOGFONTA lplf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetCompositionFontW IMPORT "IMM32.DLL" ALIAS "ImmSetCompositionFontW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lplf AS LOGFONTW _                             ' __out LPLOGFONTW lplf
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmSetCompositionFont = ImmSetCompositionFontW
#ELSE
   MACRO ImmSetCompositionFont = ImmSetCompositionFontA
#ENDIF

#ENDIF   ' #IF NOT %DEF(%NOGDI)

DECLARE FUNCTION ImmConfigureIMEA IMPORT "IMM32.DLL" ALIAS "ImmConfigureIMEA" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwMode AS DWORD _                              ' __in DWORD dwMode
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmConfigureIMEW IMPORT "IMM32.DLL" ALIAS "ImmConfigureIMEW" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL dwMode AS DWORD _                              ' __in DWORD dwMode
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmConfigureIME = ImmConfigureIMEW
#ELSE
   MACRO ImmConfigureIME = ImmConfigureIMEA
#ENDIF

DECLARE FUNCTION ImmEscapeA IMPORT "IMM32.DLL" ALIAS "ImmEscapeA" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL uEscape AS DWORD _                             ' __in UINT uEscape
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION ImmEscapeW IMPORT "IMM32.DLL" ALIAS "ImmEscapeW" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL uEscape AS DWORD _                             ' __in UINT uEscape
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS LONG                                              ' LRESULT

#IF %DEF(%UNICODE)
   MACRO ImmEscape = ImmEscapeW
#ELSE
   MACRO ImmEscape = ImmEscapeA
#ENDIF

DECLARE FUNCTION ImmGetConversionListA IMPORT "IMM32.DLL" ALIAS "ImmGetConversionListA" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpSrc AS ASCIIZ _                              ' __in  LPCSTR lpSrc
 , BYREF lpDst AS CANDIDATELIST _                       ' __out LPCANDIDATELIST lpDst
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 , BYVAL uFlag AS DWORD _                               ' __in  UINT uFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmGetConversionListW IMPORT "IMM32.DLL" ALIAS "ImmGetConversionListW" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpSrc AS WSTRINGZ _                            ' __in  LPCWSTR lpSrc
 , BYREF lpDst AS CANDIDATELIST _                       ' __out LPCANDIDATELIST lpDst
 , BYVAL dwBufLen AS DWORD _                            ' __in  DWORD dwBufLen
 , BYVAL uFlag AS DWORD _                               ' __in  UINT uFlag
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ImmGetConversionList = ImmGetConversionListW
#ELSE
   MACRO ImmGetConversionList = ImmGetConversionListA
#ENDIF

DECLARE FUNCTION ImmNotifyIME IMPORT "IMM32.DLL" ALIAS "ImmNotifyIME" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYVAL dwAction AS DWORD _                            ' __in DWORD dwAction
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYVAL dwValue AS DWORD _                             ' __in DWORD dwValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetStatusWindowPos IMPORT "IMM32.DLL" ALIAS "ImmGetStatusWindowPos" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpptPos AS POINT _                             ' __out LPPOINT lpptPos
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetStatusWindowPos IMPORT "IMM32.DLL" ALIAS "ImmSetStatusWindowPos" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYREF lpptPos AS POINT _                             ' __in LPPOINT lpptPos
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetCompositionWindow IMPORT "IMM32.DLL" ALIAS "ImmGetCompositionWindow" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYREF lpCompForm AS COMPOSITIONFORM _                ' __out LPCOMPOSITIONFORM lpCompForm
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetCompositionWindow IMPORT "IMM32.DLL" ALIAS "ImmSetCompositionWindow" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYREF lpCompForm AS COMPOSITIONFORM _                ' __in LPCOMPOSITIONFORM lpCompForm
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetCandidateWindow IMPORT "IMM32.DLL" ALIAS "ImmGetCandidateWindow" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF lpCandidate AS CANDIDATEFORM _                 ' __out LPCANDIDATEFORM lpCandidate
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmSetCandidateWindow IMPORT "IMM32.DLL" ALIAS "ImmSetCandidateWindow" ( _
   BYVAL hIMC AS DWORD _                                ' __in HIMC hIMC
 , BYREF lpCandidate AS CANDIDATEFORM _                 ' __in LPCANDIDATEFORM lpCandidate
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmIsUIMessageA IMPORT "IMM32.DLL" ALIAS "ImmIsUIMessageA" ( _
   BYVAL hWndIME AS DWORD _                             ' __in HWND hWndIME
 , BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmIsUIMessageW IMPORT "IMM32.DLL" ALIAS "ImmIsUIMessageW" ( _
   BYVAL hWndIME AS DWORD _                             ' __in HWND hWndIME
 , BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmIsUIMessage = ImmIsUIMessageW
#ELSE
   MACRO ImmIsUIMessage = ImmIsUIMessageA
#ENDIF

DECLARE FUNCTION ImmGetVirtualKey IMPORT "IMM32.DLL" ALIAS "ImmGetVirtualKey" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 ) AS DWORD                                             ' UINT

'typedef int (CALLBACK *REGISTERWORDENUMPROCA)(LPCSTR, DWORD, LPCSTR, LPVOID);
'typedef int (CALLBACK *REGISTERWORDENUMPROCW)(LPCWSTR, DWORD, LPCWSTR, LPVOID);
'#endif // !UNICODE

DECLARE FUNCTION ImmRegisterWordA IMPORT "IMM32.DLL" ALIAS "ImmRegisterWordA" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYREF lpszReading AS ASCIIZ _                        ' __in LPCSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszRegister AS ASCIIZ _                       ' __in LPCSTR lpszRegister
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmRegisterWordW IMPORT "IMM32.DLL" ALIAS "ImmRegisterWordW" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYREF lpszReading AS WSTRINGZ _                      ' __in LPCWSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszRegister AS WSTRINGZ _                     ' __in LPCWSTR lpszRegister
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmRegisterWord = ImmRegisterWordW
#ELSE
   MACRO ImmRegisterWord = ImmRegisterWordA
#ENDIF

DECLARE FUNCTION ImmUnregisterWordA IMPORT "IMM32.DLL" ALIAS "ImmUnregisterWordA" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYREF lpszReading AS ASCIIZ _                        ' __in LPCSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszUnregister AS ASCIIZ _                     ' __in LPCSTR lpszUnregister
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmUnregisterWordW IMPORT "IMM32.DLL" ALIAS "ImmUnregisterWordW" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYREF lpszReading AS WSTRINGZ _                      ' __in LPCWSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszUnregister AS WSTRINGZ _                   ' __in LPCWSTR lpszUnregister
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ImmUnregisterWord = ImmUnregisterWordW
#ELSE
   MACRO ImmUnregisterWord = ImmUnregisterWordA
#ENDIF

DECLARE FUNCTION ImmGetRegisterWordStyleA IMPORT "IMM32.DLL" ALIAS "ImmGetRegisterWordStyleA" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYVAL nItem AS DWORD _                               ' __in  UINT nItem
 , BYREF lpStyleBuf AS STYLEBUFA _                      ' __out LPSTYLEBUFA lpStyleBuf
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ImmGetRegisterWordStyleW IMPORT "IMM32.DLL" ALIAS "ImmGetRegisterWordStyleW" ( _
   BYVAL hKL AS DWORD _                                 ' __in  HKL hKL
 , BYVAL nItem AS DWORD _                               ' __in  UINT nItem
 , BYREF lpStyleBuf AS STYLEBUFW _                      ' __out LPSTYLEBUFW lpStyleBuf
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO ImmGetRegisterWordStyle = ImmGetRegisterWordStyleW
#ELSE
   MACRO ImmGetRegisterWordStyle = ImmGetRegisterWordStyleA
#ENDIF

DECLARE FUNCTION ImmEnumRegisterWordA IMPORT "IMM32.DLL" ALIAS "ImmEnumRegisterWordA" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL lpfnEnumProc AS DWORD _                        ' __in REGISTERWORDENUMPROCA lpfnEnumProc
 , BYREF lpszReading AS ASCIIZ _                        ' __in LPCSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszRegister AS ASCIIZ _                       ' __in LPCSTR lpszRegister
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION ImmEnumRegisterWordW IMPORT "IMM32.DLL" ALIAS "ImmEnumRegisterWordW" ( _
   BYVAL hKL AS DWORD _                                 ' __in HKL hKL
 , BYVAL lpfnEnumProc AS DWORD _                        ' __in REGISTERWORDENUMPROCW lpfnEnumProc
 , BYREF lpszReading AS WSTRINGZ _                      ' __in LPCWSTR lpszReading
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF lpszRegister AS WSTRINGZ _                     ' __in LPCWSTR lpszRegister
 , BYREF lpData AS ANY _                                ' __in LPVOID lpData
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO ImmEnumRegisterWord = ImmEnumRegisterWordW
#ELSE
   MACRO ImmEnumRegisterWord = ImmEnumRegisterWordA
#ENDIF

'#if (WINVER >= 0x040A)

DECLARE FUNCTION ImmDisableIME IMPORT "IMM32.DLL" ALIAS "ImmDisableIME" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmEnumInputContext IMPORT "IMM32.DLL" ALIAS "ImmEnumInputContext" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 , BYVAL lpfn AS DWORD _                                ' __in IMCENUMPROC lpfn
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImmGetImeMenuItemsA IMPORT "IMM32.DLL" ALIAS "ImmGetImeMenuItemsA" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYVAL dwType AS DWORD _                              ' __in  DWORD dwType
 , BYREF lpImeParentMenu AS IMEMENUITEMINFOA _          ' __out LPIMEMENUITEMINFOA lpImeParentMenu
 , BYREF lpImeMenu AS IMEMENUITEMINFOA _                ' __out LPIMEMENUITEMINFOA lpImeMenu
 , BYVAL dwSize AS DWORD _                              ' __in  DWORD dwSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION ImmGetImeMenuItemsW IMPORT "IMM32.DLL" ALIAS "ImmGetImeMenuItemsW" ( _
   BYVAL hIMC AS DWORD _                                ' __in  HIMC hIMC
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYVAL dwType AS DWORD _                              ' __in  DWORD dwType
 , BYREF lpImeParentMenu AS IMEMENUITEMINFOW _          ' __out LPIMEMENUITEMINFOW lpImeParentMenu
 , BYREF lpImeMenu AS IMEMENUITEMINFOW _                ' __out LPIMEMENUITEMINFOW lpImeMenu
 , BYVAL dwSize AS DWORD _                              ' __in  DWORD dwSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO ImmGetImeMenuItems = ImmGetImeMenuItemsW
#ELSE
   MACRO ImmGetImeMenuItems = ImmGetImeMenuItemsA
#ENDIF

DECLARE FUNCTION ImmDisableTextFrameService IMPORT "IMM32.DLL" ALIAS "ImmDisableTextFrameService" ( _
   BYVAL idThread AS DWORD _                            ' __in DWORD idThread
 ) AS LONG                                              ' BOOL

'#endif /* WINVER >= 0x040A */

'// wParam for WM_IME_CONTROL
%IMC_GETCANDIDATEPOS          = &H0007???
%IMC_SETCANDIDATEPOS          = &H0008???
%IMC_GETCOMPOSITIONFONT       = &H0009???
%IMC_SETCOMPOSITIONFONT       = &H000A???
%IMC_GETCOMPOSITIONWINDOW     = &H000B???
%IMC_SETCOMPOSITIONWINDOW     = &H000C???
%IMC_GETSTATUSWINDOWPOS       = &H000F???
%IMC_SETSTATUSWINDOWPOS       = &H0010???
%IMC_CLOSESTATUSWINDOW        = &H0021???
%IMC_OPENSTATUSWINDOW         = &H0022???

'// dwAction for ImmNotifyIME
%NI_OPENCANDIDATE             = &H0010???
%NI_CLOSECANDIDATE            = &H0011???
%NI_SELECTCANDIDATESTR        = &H0012???
%NI_CHANGECANDIDATELIST       = &H0013???
%NI_FINALIZECONVERSIONRESULT  = &H0014???
%NI_COMPOSITIONSTR            = &H0015???
%NI_SETCANDIDATE_PAGESTART    = &H0016???
%NI_SETCANDIDATE_PAGESIZE     = &H0017???
%NI_IMEMENUSELECTED           = &H0018???

'// lParam for WM_IME_SETCONTEXT
%ISC_SHOWUICANDIDATEWINDOW    = &H00000001???
%ISC_SHOWUICOMPOSITIONWINDOW  = &H80000000???
%ISC_SHOWUIGUIDELINE          = &H40000000???
%ISC_SHOWUIALLCANDIDATEWINDOW = &H0000000F???
%ISC_SHOWUIALL                = &HC000000F???

'// dwIndex for ImmNotifyIME/NI_COMPOSITIONSTR
%CPS_COMPLETE                 = &H0001???
%CPS_CONVERT                  = &H0002???
%CPS_REVERT                   = &H0003???
%CPS_CANCEL                   = &H0004???

'// the modifiers of hot key
%MOD_ALT                      = &H0001???
%MOD_CONTROL                  = &H0002???
%MOD_SHIFT                    = &H0004???

%MOD_LEFT                     = &H8000???
%MOD_RIGHT                    = &H4000???

%MOD_ON_KEYUP                 = &H0800???
%MOD_IGNORE_ALL_MODIFIER      = &H0400???

'// Windows for Simplified Chinese Edition hot key ID from 0x10 - 0x2F
%IME_CHOTKEY_IME_NONIME_TOGGLE     = &H10
%IME_CHOTKEY_SHAPE_TOGGLE          = &H11
%IME_CHOTKEY_SYMBOL_TOGGLE         = &H12

'// Windows for Japanese Edition hot key ID from 0x30 - 0x4F
%IME_JHOTKEY_CLOSE_OPEN            = &H30

'// Windows for Korean Edition hot key ID from 0x50 - 0x6F
%IME_KHOTKEY_SHAPE_TOGGLE          = &H50
%IME_KHOTKEY_HANJACONVERT          = &H51
%IME_KHOTKEY_ENGLISH               = &H52

'// Windows for Traditional Chinese Edition hot key ID from 0x70 - 0x8F
%IME_THOTKEY_IME_NONIME_TOGGLE     = &H70
%IME_THOTKEY_SHAPE_TOGGLE          = &H71
%IME_THOTKEY_SYMBOL_TOGGLE         = &H72

'// direct switch hot key ID from 0x100 - 0x11F
%IME_HOTKEY_DSWITCH_FIRST          = &H100
%IME_HOTKEY_DSWITCH_LAST           = &H11F

'// IME private hot key from 0x200 - 0x21F
%IME_HOTKEY_PRIVATE_FIRST          = &H200
%IME_ITHOTKEY_RESEND_RESULTSTR     = &H200
%IME_ITHOTKEY_PREVIOUS_COMPOSITION = &H201
%IME_ITHOTKEY_UISTYLE_TOGGLE       = &H202
%IME_ITHOTKEY_RECONVERTSTRING      = &H203
%IME_HOTKEY_PRIVATE_LAST           = &H21F

'// parameter of ImmGetCompositionString
%GCS_COMPREADSTR                = &H0001???
%GCS_COMPREADATTR               = &H0002???
%GCS_COMPREADCLAUSE             = &H0004???
%GCS_COMPSTR                    = &H0008???
%GCS_COMPATTR                   = &H0010???
%GCS_COMPCLAUSE                 = &H0020???
%GCS_CURSORPOS                  = &H0080???
%GCS_DELTASTART                 = &H0100???
%GCS_RESULTREADSTR              = &H0200???
%GCS_RESULTREADCLAUSE           = &H0400???
%GCS_RESULTSTR                  = &H0800???
%GCS_RESULTCLAUSE               = &H1000???

'// style bit flags for WM_IME_COMPOSITION
%CS_INSERTCHAR                  = &H2000???
%CS_NOMOVECARET                 = &H4000???

'// IME version constants
%IMEVER_0310                    = &H0003000A???
%IMEVER_0400                    = &H00040000???

'// IME property bits
%IME_PROP_AT_CARET              = &H00010000???
%IME_PROP_SPECIAL_UI            = &H00020000???
%IME_PROP_CANDLIST_START_FROM_1 = &H00040000???
%IME_PROP_UNICODE               = &H00080000???
%IME_PROP_COMPLETE_ON_UNSELECT  = &H00100000???

'// IME UICapability bits
%UI_CAP_2700                    = &H00000001???
%UI_CAP_ROT90                   = &H00000002???
%UI_CAP_ROTANY                  = &H00000004???

'// ImmSetCompositionString Capability bits
%SCS_CAP_COMPSTR                = &H00000001???
%SCS_CAP_MAKEREAD               = &H00000002???
%SCS_CAP_SETRECONVERTSTRING     = &H00000004???

'// IME WM_IME_SELECT inheritance Capability bits
%SELECT_CAP_CONVERSION          = &H00000001???
%SELECT_CAP_SENTENCE            = &H00000002???

'// ID for dwIndex of ImmGetGuideLine
%GGL_LEVEL                      = &H00000001???
%GGL_INDEX                      = &H00000002???
%GGL_STRING                     = &H00000003???
%GGL_PRIVATE                    = &H00000004???

'// ID for dwLevel of GUIDELINE Structure
%GL_LEVEL_NOGUIDELINE           = &H00000000???
%GL_LEVEL_FATAL                 = &H00000001???
%GL_LEVEL_ERROR                 = &H00000002???
%GL_LEVEL_WARNING               = &H00000003???
%GL_LEVEL_INFORMATION           = &H00000004???

'// ID for dwIndex of GUIDELINE Structure
%GL_ID_UNKNOWN                  = &H00000000???
%GL_ID_NOMODULE                 = &H00000001???
%GL_ID_NODICTIONARY             = &H00000010???
%GL_ID_CANNOTSAVE               = &H00000011???
%GL_ID_NOCONVERT                = &H00000020???
%GL_ID_TYPINGERROR              = &H00000021???
%GL_ID_TOOMANYSTROKE            = &H00000022???
%GL_ID_READINGCONFLICT          = &H00000023???
%GL_ID_INPUTREADING             = &H00000024???
%GL_ID_INPUTRADICAL             = &H00000025???
%GL_ID_INPUTCODE                = &H00000026???
%GL_ID_INPUTSYMBOL              = &H00000027???
%GL_ID_CHOOSECANDIDATE          = &H00000028???
%GL_ID_REVERSECONVERSION        = &H00000029???
%GL_ID_PRIVATE_FIRST            = &H00008000???
%GL_ID_PRIVATE_LAST             = &H0000FFFF???

'// ID for dwIndex of ImmGetProperty
%IGP_GETIMEVERSION              = &HFFFFFFFC???   ' (DWORD)(-4)
%IGP_PROPERTY                   = &H00000004???
%IGP_CONVERSION                 = &H00000008???
%IGP_SENTENCE                   = &H0000000c???
%IGP_UI                         = &H00000010???
%IGP_SETCOMPSTR                 = &H00000014???
%IGP_SELECT                     = &H00000018???

'// dwIndex for ImmSetCompositionString API
%SCS_SETSTR               = %GCS_COMPREADSTR OR %GCS_COMPSTR
%SCS_CHANGEATTR           = %GCS_COMPREADATTR OR %GCS_COMPATTR
%SCS_CHANGECLAUSE         = %GCS_COMPREADCLAUSE OR %GCS_COMPCLAUSE
%SCS_SETRECONVERTSTRING   = &H00010000???
%SCS_QUERYRECONVERTSTRING = &H00020000???

'// attribute for COMPOSITIONSTRING Structure
%ATTR_INPUT               = &H00
%ATTR_TARGET_CONVERTED    = &H01
%ATTR_CONVERTED           = &H02
%ATTR_TARGET_NOTCONVERTED = &H03
%ATTR_INPUT_ERROR         = &H04
%ATTR_FIXEDCONVERTED      = &H05

'// bit field for IMC_SETCOMPOSITIONWINDOW, IMC_SETCANDIDATEWINDOW
%CFS_DEFAULT              = &H0000???
%CFS_RECT                 = &H0001???
%CFS_POINT                = &H0002???
%CFS_FORCE_POSITION       = &H0020???
%CFS_CANDIDATEPOS         = &H0040???
%CFS_EXCLUDE              = &H0080???

'// conversion direction for ImmGetConversionList
%GCL_CONVERSION           = &H0001???
%GCL_REVERSECONVERSION    = &H0002???
%GCL_REVERSE_LENGTH       = &H0003???

#INCLUDE ONCE "ime_cmodes.inc"

'// IME_CMODE_HANGEUL is old name of IME_CMODE_HANGUL. It will be gone eventually.
%IME_CMODE_HANGEUL        = %IME_CMODE_NATIVE
%IME_CMODE_SOFTKBD        = &H0080???
%IME_CMODE_NOCONVERSION   = &H0100???
%IME_CMODE_EUDC           = &H0200???
%IME_CMODE_SYMBOL         = &H0400???
%IME_CMODE_FIXED          = &H0800???
%IME_CMODE_RESERVED       = &HF0000000???

'// bit field for sentence mode
%IME_SMODE_NONE           = &H0000???
%IME_SMODE_PLAURALCLAUSE  = &H0001???
%IME_SMODE_SINGLECONVERT  = &H0002???
%IME_SMODE_AUTOMATIC      = &H0004???
%IME_SMODE_PHRASEPREDICT  = &H0008???
%IME_SMODE_CONVERSATION   = &H0010???
%IME_SMODE_RESERVED       = &H0000F000???

'// style of candidate
%IME_CAND_UNKNOWN         = &H0000???
%IME_CAND_READ            = &H0001???
%IME_CAND_CODE            = &H0002???
%IME_CAND_MEANING         = &H0003???
%IME_CAND_RADICAL         = &H0004???
%IME_CAND_STROKE          = &H0005???

'// wParam of report message WM_IME_NOTIFY
%IMN_CLOSESTATUSWINDOW    = &H0001???
%IMN_OPENSTATUSWINDOW     = &H0002???
%IMN_CHANGECANDIDATE      = &H0003???
%IMN_CLOSECANDIDATE       = &H0004???
%IMN_OPENCANDIDATE        = &H0005???
%IMN_SETCONVERSIONMODE    = &H0006???
%IMN_SETSENTENCEMODE      = &H0007???
%IMN_SETOPENSTATUS        = &H0008???
%IMN_SETCANDIDATEPOS      = &H0009???
%IMN_SETCOMPOSITIONFONT   = &H000A???
%IMN_SETCOMPOSITIONWINDOW = &H000B???
%IMN_SETSTATUSWINDOWPOS   = &H000C???
%IMN_GUIDELINE            = &H000D???
%IMN_PRIVATE              = &H000E???

'#if (WINVER >= 0x040A)
'// wParam of report message WM_IME_REQUEST
%IMR_COMPOSITIONWINDOW      = &H0001???
%IMR_CANDIDATEWINDOW        = &H0002???
%IMR_COMPOSITIONFONT        = &H0003???
%IMR_RECONVERTSTRING        = &H0004???
%IMR_CONFIRMRECONVERTSTRING = &H0005???
%IMR_QUERYCHARPOSITION      = &H0006???
%IMR_DOCUMENTFEED           = &H0007???
'#endif /* WINVER >= 0x040A */

'// error code of ImmGetCompositionString
%IMM_ERROR_NODATA  = -1
%IMM_ERROR_GENERAL = -2

'// dialog mode of ImmConfigureIME
%IME_CONFIG_GENERAL          = 1
%IME_CONFIG_REGISTERWORD     = 2
%IME_CONFIG_SELECTDICTIONARY = 3

'// flags for ImmEscape
%IME_ESC_QUERY_SUPPORT        = &H0003???
%IME_ESC_RESERVED_FIRST       = &H0004???
%IME_ESC_RESERVED_LAST        = &H07FF???
%IME_ESC_PRIVATE_FIRST        = &H0800???
%IME_ESC_PRIVATE_LAST         = &H0FFF???

%IME_ESC_SEQUENCE_TO_INTERNAL = &H1001???
%IME_ESC_GET_EUDC_DICTIONARY  = &H1003???
%IME_ESC_SET_EUDC_DICTIONARY  = &H1004???
%IME_ESC_MAX_KEY              = &H1005???
%IME_ESC_IME_NAME             = &H1006???
%IME_ESC_SYNC_HOTKEY          = &H1007???
%IME_ESC_HANJA_MODE           = &H1008???
%IME_ESC_AUTOMATA             = &H1009???
%IME_ESC_PRIVATE_HOTKEY       = &H100a???
%IME_ESC_GETHELPFILENAME      = &H100b???

'// style of word registration
%IME_REGWORD_STYLE_EUDC       = &H00000001???
%IME_REGWORD_STYLE_USER_FIRST = &H80000000???
%IME_REGWORD_STYLE_USER_LAST  = &HFFFFFFFF???

'#if (WINVER >= 0x040A)

'// dwFlags for ImmAssociateContextEx
%IACE_CHILDREN                = &H0001???
%IACE_DEFAULT                 = &H0010???
%IACE_IGNORENOCONTEXT         = &H0020???

'// dwFlags for ImmGetImeMenuItems
%IGIMIF_RIGHTMENU             = &H0001???

'// dwType for ImmGetImeMenuItems
%IGIMII_CMODE                 = &H0001???
%IGIMII_SMODE                 = &H0002???
%IGIMII_CONFIGURE             = &H0004???
%IGIMII_TOOLS                 = &H0008???
%IGIMII_HELP                  = &H0010???
%IGIMII_OTHER                 = &H0020???
%IGIMII_INPUTTOOLS            = &H0040???

'// fType of IMEMENUITEMINFO structure
%IMFT_RADIOCHECK              = &H00001???
%IMFT_SEPARATOR               = &H00002???
%IMFT_SUBMENU                 = &H00004???

'// fState of IMEMENUITEMINFO structure
%IMFS_GRAYED    = %MFS_GRAYED
%IMFS_DISABLED  = %MFS_DISABLED
%IMFS_CHECKED   = %MFS_CHECKED
%IMFS_HILITE    = %MFS_HILITE
%IMFS_ENABLED   = %MFS_ENABLED
%IMFS_UNCHECKED = %MFS_UNCHECKED
%IMFS_UNHILITE  = %MFS_UNHILITE
%IMFS_DEFAULT   = %MFS_DEFAULT

'#endif /* WINVER >= 0x040A */

'// type of soft keyboard
'// for Windows Tranditional Chinese Edition
%SOFTKEYBOARD_TYPE_T1 = &H0001???
'// for Windows Simplified Chinese Edition
%SOFTKEYBOARD_TYPE_C1 = &H0002???
