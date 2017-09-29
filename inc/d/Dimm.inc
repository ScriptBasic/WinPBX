' ########################################################################################
' Microsoft Windows
' File: Dimm.inc
' Library name: ActiveIMM
' Version: 0.1, Locale ID = 0
' Library GUID: {4955DD30-B159-11D0-8FCF-00AA006BCC59}
' Contents: ActiveIMM
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DIMM_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

'//--------------------------------------------------------------------------
'// IActiveIMM Interfaces.

#INCLUDE ONCE "imm.inc"

'typedef WORD LANGID;
'typedef DWORD HIMC;
'typedef DWORD HIMCC;
'typedef WORD ATOM;

' // Size = 82 bytes
UNION INPUTCONTEXT_UNION DWORD
   A AS LOGFONTA
   W AS LOGFONTW
END UNION

' // Size = 320 bytes
TYPE INPUTCONTEXT DWORD
   hWnd           AS DWORD                  ' HWND hWnd
   fOpen          AS LONG                   ' BOOL fOpen
   ptStatusWndPos AS POINT                  ' POINT ptStatusWndPos
   ptSoftKbdPos   AS POINT                  ' POINT ptSoftKbdPos
   fdwConversion  AS DWORD                  ' DWORD fdwConversion
   fdwSentence    AS DWORD                  ' DWORD fdwSentence
   lfFont         AS INPUTCONTEXT_UNION
   cfCompForm     AS COMPOSITIONFORM        ' COMPOSITIONFORM cfCompForm
   cfCandForm(3)  AS CANDIDATEFORM          ' CANDIDATEFORM cfCandForm[ 4 ]
   hCompStr       AS DWORD                  ' HIMCC hCompStr
   hCandInfo      AS DWORD                  ' HIMCC hCandInfo
   hGuideLine     AS DWORD                  ' HIMCC hGuideLine
   hPrivate       AS DWORD                  ' HIMCC hPrivate
   dwNumMsgBuf    AS DWORD                  ' DWORD dwNumMsgBuf
   hMsgBuf        AS DWORD                  ' HIMCC hMsgBuf
   fdwInit        AS DWORD                  ' DWORD fdwInit
   dwReserve(2)   AS DWORD                  ' DWORD dwReserve[ 3 ]
END TYPE

' // Size = 28 bytes
TYPE IMEINFO DWORD
   dwPrivateDataSize AS DWORD                    ' DWORD dwPrivateDataSize
   fdwProperty       AS DWORD                    ' DWORD fdwProperty
   fdwConversionCaps AS DWORD                    ' DWORD fdwConversionCaps
   fdwSentenceCaps   AS DWORD                    ' DWORD fdwSentenceCaps
   fdwUICaps         AS DWORD                    ' DWORD fdwUICaps
   fdwSCSCaps        AS DWORD                    ' DWORD fdwSCSCaps
   fdwSelectCaps     AS DWORD                    ' DWORD fdwSelectCaps
END TYPE

$LIBID_ActiveIMM = GUID$("{4955DD30-B159-11D0-8FCF-00AA006BCC59}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CActiveIMM = GUID$("{4955DD33-B159-11D0-8FCF-00AA006BCC59}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumRegisterWord  = GUID$("{08C03412-F96B-11D0-A475-00AA006BCC59}")
$IID_IEnumRegisterWordA = GUID$("{08C03412-F96B-11D0-A475-00AA006BCC59}")
$IID_IEnumRegisterWordW = GUID$("{4955DD31-B159-11D0-8FCF-00AA006BCC59}")
$IID_IEnumInputContext = GUID$("{09B5EAB0-F997-11D1-93D4-0060B067B86E}")
$IID_IActiveIMMRegistrar = GUID$("{B3458082-BD00-11D1-939B-0060B067B86E}")
$IID_IActiveIMMMessagePumpOwner = GUID$("{B5CF2CFA-8AEB-11D1-9364-0060B067B86E}")
$IID_IActiveIMMApp = GUID$("{08C0E040-62D1-11D1-9326-0060B067B86E}")
$IID_IActiveIMMIME = GUID$("{08C03411-F96B-11D0-A475-00AA006BCC59}")
$IID_IActiveIME = GUID$("{6FE20962-D077-11D0-8FE7-00AA006BCC59}")
$IID_IActiveIME2 = GUID$("{E1C4BF0E-2D53-11D2-93E1-0060B067B86E}")

' ########################################################################################
' Interface name = IEnumRegisterWordA
' IID = {08C03412-F96B-11D0-A475-00AA006BCC59}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRegisterWordA_INTERFACE_DEFINED)
    %IEnumRegisterWordA_INTERFACE_DEFINED = 1

INTERFACE IEnumRegisterWord $IID_IEnumRegisterWord

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumRegisterWord _                ' __out IEnumRegisterWordA **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF rgRegisterWord AS REGISTERWORDA _            ' __out REGISTERWORDA *rgRegisterWord
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRegisterWordA_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumRegisterWordW
' IID = {4955DD31-B159-11D0-8FCF-00AA006BCC59}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRegisterWordW_INTERFACE_DEFINED)
    %IEnumRegisterWordW_INTERFACE_DEFINED = 1

INTERFACE IEnumRegisterWordW $IID_IEnumRegisterWordW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumRegisterWordW _               ' __out IEnumRegisterWordW **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF rgRegisterWord AS REGISTERWORDW _            ' __out REGISTERWORDW *rgRegisterWord
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRegisterWordW_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumInputContext
' IID = {09B5EAB0-F997-11D1-93D4-0060B067B86E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumInputContext_INTERFACE_DEFINED)
    %IEnumInputContext_INTERFACE_DEFINED = 1

INTERFACE IEnumInputContext $IID_IEnumInputContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumInputContext _                ' __out IEnumInputContext **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYREF rgInputContext AS DWORD _                    ' __out HIMC *rgInputContext
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumInputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIMMRegistrar
' IID = {b3458082-bd00-11d1-939b-0060b067b86e}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveIMMRegistrar_INTERFACE_DEFINED)
    %IActiveIMMRegistrar_INTERFACE_DEFINED = 1

INTERFACE IActiveIMMRegistrar $IID_IActiveIMMRegistrar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterIME ( _                               ' VTable offset = 12
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   , BYVAL lgid AS WORD _                               ' __in LANGID lgid
   , BYREF pszIconFile AS WSTRINGZ _                    ' __in LPCWSTR pszIconFile
   , BYREF pszDesc AS WSTRINGZ _                        ' __in LPCWSTR pszDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterIME ( _                             ' VTable offset = 16
     BYREF rclsid AS GUID _                             ' __in REFCLSID rclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIMMRegistrar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIMMMessagePumpOwner
' IID = {b5cf2cfa-8aeb-11d1-9364-0060b067b86e}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveIMMMessagePumpOwner_INTERFACE_DEFINED)
    %IActiveIMMMessagePumpOwner_INTERFACE_DEFINED = 1

INTERFACE IActiveIMMMessagePumpOwner $IID_IActiveIMMMessagePumpOwner

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTranslateMessage ( _                        ' VTable offset = 20
     BYREF pMsg AS tagMSG _                             ' __in const MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 24
     BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 28
     BYREF dwCookie AS DWORD _                          ' __out DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIMMApp
' IID = {08C0E040-62D1-11D1-9326-0060B067B86E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveIMMApp_INTERFACE_DEFINED)
    %IActiveIMMApp_INTERFACE_DEFINED = 1

INTERFACE IActiveIMMApp $IID_IActiveIMMApp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AssociateContext ( _                          ' VTable offset = 12
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIME AS DWORD _                              ' __in HIMC hIME
   , BYREF phPrev AS DWORD _                            ' __out HIMC *phPrev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureIMEA ( _                             ' VTable offset = 16
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pData AS REGISTERWORDA _                     ' __in REGISTERWORDA *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureIMEW ( _                             ' VTable offset = 20
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF REGISTERWORDW _                              ' __in REGISTERWORDW *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateContext ( _                             ' VTable offset = 24
     BYREF phIMC AS DWORD _                             ' __out HIMC *phIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyContext ( _                            ' VTable offset = 28
     BYVAL hIME AS DWORD _                              ' __in HIMC hIME
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWordA ( _                         ' VTable offset = 32
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS ASCIIZ _                       ' __in LPSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF pEnum AS IEnumRegisterWord _                 ' __out IEnumRegisterWordA **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWordW ( _                         ' VTable offset = 36
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF pEnum AS IEnumRegisterWordW _                ' __out IEnumRegisterWordW **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EscapeA ( _                                   ' VTable offset = 40
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYVAL pData AS DWORD _                             ' __inout LPVOID pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EscapeW ( _                                   ' VTable offset = 44
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYVAL pData AS DWORD _                             ' __inout LPVOID pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListA ( _                         ' VTable offset = 48
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pCandList AS CANDIDATELIST _                 ' __out CANDIDATELIST *pCandList
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListW ( _                         ' VTable offset = 52
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pCandList AS CANDIDATELIST _                 ' __out CANDIDATELIST *pCandList
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListCountA ( _                    ' VTable offset = 56
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwListSize AS DWORD _                       ' __out DWORD *pdwListSize
   , BYREF pdwBufLen AS DWORD _                         ' __out DWORD *pdwBufLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListCountW ( _                    ' VTable offset = 60
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwListSize AS DWORD _                       ' __out DWORD *pdwListSize
   , BYREF pdwBufLen AS DWORD _                         ' __out DWORD *pdwBufLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateWindow ( _                        ' VTable offset = 64
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pCandidate AS CANDIDATEFORM _                ' __out CANDIDATEFORM *pCandidate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionFontA ( _                       ' VTable offset = 68
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTA _                            ' __out LOGFONTA *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionFontW ( _                       ' VTable offset = 72
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTW _                            ' __out LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionStringA ( _                     ' VTable offset = 76
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF plCopied AS LONG _                           ' __out LONG *plCopied
   , BYVAL pBuf AS DWORD _                              ' __out LPVOID pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionStringW ( _                     ' VTable offset = 80
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF plCopied AS LONG _                           ' __out LONG *plCopied
   , BYVAL pBuf AS DWORD _                              ' __out LPVOID pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionWindow ( _                      ' VTable offset = 84
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCompForm AS COMPOSITIONFORM _               ' __out COMPOSITIONFORM *pCompForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 88
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF phIMC AS DWORD _                             ' __out HIMC *phIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionListA ( _                        ' VTable offset = 92
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pSrc AS ASCIIZ _                             ' __in LPSTR pSrc
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYREF pDst AS CANDIDATELIST _                      ' __out CANDIDATELIST *pDst
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionListW ( _                        ' VTable offset = 96
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pSrc AS WSTRINGZ _                           ' __in LPWSTR pSrc
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYREF pDst AS CANDIDATELIST _                      ' __out CANDIDATELIST *pDst
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionStatus ( _                       ' VTable offset = 100
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pfdwConversion AS DWORD _                    ' __out DWORD *pfdwConversion
   , BYREF pfdwSentence AS DWORD _                      ' __out DWORD *pfdwSentence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultIMEWnd ( _                          ' VTable offset = 104
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF phDefWnd AS DWORD _                          ' __out HWND *phDefWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionA ( _                           ' VTable offset = 108
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szDescription AS ASCIIZ _                    ' __out LPSTR szDescription
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionW ( _                           ' VTable offset = 112
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szDescription AS WSTRINGZ _                  ' __out LPWSTR szDescription
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideLineA ( _                             ' VTable offset = 116
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF pBuf AS ASCIIZ _                             ' __out LPSTR pBuf
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideLineW ( _                             ' VTable offset = 120
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF pBuf AS WSTRINGZ _                           ' __out LPWSTR pBuf
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMEFileNameA ( _                           ' VTable offset = 124
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szFileName AS ASCIIZ _                       ' __out LPSTR szFileName
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMEFileNameW ( _                           ' VTable offset = 128
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szFileName AS WSTRINGZ _                     ' __out LPWSTR szFileName
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpenStatus ( _                             ' VTable offset = 132
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 136
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL fdwIndex AS DWORD _                          ' __in DWORD fdwIndex
   , BYREF pdwProperty AS DWORD _                       ' __out DWORD *pdwProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyleA ( _                     ' VTable offset = 140
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFA _                     ' __out STYLEBUFA *pStyleBuf
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyleW ( _                     ' VTable offset = 144
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFW _                     ' __out STYLEBUFW *pStyleBuf
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusWindowPos ( _                        ' VTable offset = 148
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pptPos AS POINT _                            ' __out POINT *pptPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVirtualKey ( _                             ' VTable offset = 152
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF puVirtualKey AS DWORD _                      ' __out UINT *puVirtualKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallIMEA ( _                               ' VTable offset = 156
     BYREF szIMEFileName AS ASCIIZ _                    ' __in LPSTR szIMEFileName
   , BYREF szLayoutText AS ASCIIZ _                     ' __in LPSTR szLayoutText
   , BYREF phKL AS DWORD _                              ' __out HKL *phKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallIMEW ( _                               ' VTable offset = 160
     BYREF szIMEFileName AS WSTRINGZ _                  ' __in LPWSTR szIMEFileName
   , BYREF szLayoutText AS WSTRINGZ _                   ' __in LPWSTR szLayoutText
   , BYREF phKL AS DWORD _                              ' __out HKL *phKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsIME ( _                                     ' VTable offset = 164
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUIMessageA ( _                              ' VTable offset = 168
     BYVAL hWnd AS DWORD _                              ' __in HWND hWndIME
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUIMessageW ( _                              ' VTable offset = 172
     BYVAL hWnd AS DWORD _                              ' __in HWND hWndIME
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyIME ( _                                 ' VTable offset = 176
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWordA ( _                             ' VTable offset = 180
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS ASCIIZ _                       ' __in LPSTR szRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWordW ( _                             ' VTable offset = 184
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseContext ( _                            ' VTable offset = 188
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCandidateWindow ( _                        ' VTable offset = 192
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCandidate AS CANDIDATEFORM _                ' __in CANDIDATEFORM *pCandidate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionFontA ( _                       ' VTable offset = 196
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTA _                            ' __in LOGFONTA *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionFontW ( _                       ' VTable offset = 200
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTW _                            ' __in LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionStringA ( _                     ' VTable offset = 204
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in LPVOID pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in LPVOID pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionStringW ( _                     ' VTable offset = 208
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in LPVOID pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in LPVOID pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionWindow ( _                      ' VTable offset = 212
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCompForm AS COMPOSITIONFORM _               ' __in COMPOSITIONFORM *pCompForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConversionStatus ( _                       ' VTable offset = 216
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fdwConversion AS DWORD _                     ' __in DWORD fdwConversion
   , BYVAL fdwSentence AS DWORD _                       ' __in DWORD fdwSentence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpenStatus ( _                             ' VTable offset = 220
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fOpen AS LONG _                              ' __in BOOL fOpen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusWindowPos ( _                        ' VTable offset = 224
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pptPos AS POINT _                            ' __in POINT *pptPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SimulateHotKey ( _                            ' VTable offset = 228
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwHotKeyID AS DWORD _                        ' __in DWORD dwHotKeyID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWordA ( _                           ' VTable offset = 232
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szUnregister AS ASCIIZ _                     ' __in LPSTR szUnregister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWordW ( _                           ' VTable offset = 236
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szUnregister AS WSTRINGZ _                   ' __in LPWSTR szUnregister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 240
     BYVAL fRestoreLayout AS LONG _                     ' __in BOOL fRestoreLayout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Deactivate ( _                                ' VTable offset = 244
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDefWindowProc ( _                           ' VTable offset = 248
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FilterClientWindows ( _                       ' VTable offset = 252
     BYREF aaClassList AS WORD _                        ' __in ATOM *aaClassList
   , BYVAL uSize AS DWORD _                             ' __in UINT uSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageA ( _                              ' VTable offset = 256
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF uCodePage AS DWORD _                         ' __out UINT *uCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLangId ( _                                 ' VTable offset = 260
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF plid AS WORD _                               ' __out LANGID *plid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AssociateContextEx ( _                        ' VTable offset = 264
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableIME ( _                                ' VTable offset = 268
     BYVAL idThread AS DWORD _                          ' __in DWORD idThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImeMenuItemsA ( _                          ' VTable offset = 272
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwType AS DWORD _                            ' __in DWORD dwType
   , BYREF pImeParentMenu AS IMEMENUITEMINFOA _         ' __in IMEMENUITEMINFOA *pImeParentMenu
   , BYREF pImeMenu AS IMEMENUITEMINFOA _               ' __out IMEMENUITEMINFOA *pImeMenu
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImeMenuItemsW ( _                          ' VTable offset = 276
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwType AS DWORD _                            ' __in DWORD dwType
   , BYREF pImeParentMenu AS IMEMENUITEMINFOW _         ' __in IMEMENUITEMINFOW *pImeParentMenu
   , BYREF pImeMenu AS IMEMENUITEMINFOW _               ' __out IMEMENUITEMINFOW *pImeMenu
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumInputContext ( _                          ' VTable offset = 280
     BYVAL idThread AS DWORD _                          ' __in DWORD idThread
   , BYREF ppEnum AS IEnumInputContext _                ' __out IEnumInputContext **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIMMApp_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIMMIME
' IID = {08C03411-F96B-11d0-A475-00AA006BCC59}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveIMMIME_INTERFACE_DEFINED)
    %IActiveIMMIME_INTERFACE_DEFINED = 1

INTERFACE IActiveIMMIME $IID_IActiveIMMIME

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AssociateContext ( _                          ' VTable offset = 12
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIME AS DWORD _                              ' __in HIMC hIME
   , BYREF phPrev AS DWORD _                            ' __out HIMC *phPrev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureIMEA ( _                             ' VTable offset = 16
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pData AS REGISTERWORDA _                     ' __in REGISTERWORDA *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureIMEW ( _                             ' VTable offset = 20
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pData AS REGISTERWORDW _                     ' __in REGISTERWORDW *pData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateContext ( _                             ' VTable offset = 24
     BYREF phIMC AS DWORD _                             ' __out HIMC *phIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyContext ( _                            ' VTable offset = 28
     BYVAL hIME AS DWORD _                              ' __in HIMC hIME
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWordA ( _                         ' VTable offset = 32
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS ASCIIZ _                       ' __in LPSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF pEnum AS IEnumRegisterWord _                 ' __out IEnumRegisterWordA **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWordW ( _                         ' VTable offset = 36
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF pEnum AS IEnumRegisterWordW _                ' __out IEnumRegisterWordW **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EscapeA ( _                                   ' VTable offset = 40
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYVAL pData AS DWORD _                             ' __inout LPVOID pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EscapeW ( _                                   ' VTable offset = 44
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYVAL pData AS DWORD _                             ' __inout LPVOID pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListA ( _                         ' VTable offset = 48
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pCandList AS CANDIDATELIST _                 ' __out CANDIDATELIST *pCandList
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListW ( _                         ' VTable offset = 52
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pCandList AS CANDIDATELIST _                 ' __out CANDIDATELIST *pCandList
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListCountA ( _                    ' VTable offset = 56
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwListSize AS DWORD _                       ' __out DWORD *pdwListSize
   , BYREF pdwBufLen AS DWORD _                         ' __out DWORD *pdwBufLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateListCountW ( _                    ' VTable offset = 60
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwListSize AS DWORD _                       ' __out DWORD *pdwListSize
   , BYREF pdwBufLen AS DWORD _                         ' __out DWORD *pdwBufLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCandidateWindow ( _                        ' VTable offset = 64
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pCandidate AS CANDIDATEFORM _                ' __out CANDIDATEFORM *pCandidate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionFontA ( _                       ' VTable offset = 68
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTA _                            ' __out LOGFONTA *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionFontW ( _                       ' VTable offset = 72
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTW _                            ' __out LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionStringA ( _                     ' VTable offset = 76
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF plCopied AS LONG _                           ' __out LONG *plCopied
   , BYVAL pBuf AS DWORD _                              ' __out LPVOID pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionStringW ( _                     ' VTable offset = 80
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF plCopied AS LONG _                           ' __out LONG *plCopied
   , BYVAL pBuf AS DWORD _                              ' __out LPVOID pBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionWindow ( _                      ' VTable offset = 84
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCompForm AS COMPOSITIONFORM _               ' __out COMPOSITIONFORM *pCompForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContext ( _                                ' VTable offset = 88
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF phIMC AS DWORD _                             ' __out HIMC *phIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionListA ( _                        ' VTable offset = 92
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pSrc AS ASCIIZ _                             ' __in LPSTR pSrc
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYREF pDst AS CANDIDATELIST _                      ' __out CANDIDATELIST *pDst
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionListW ( _                        ' VTable offset = 96
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pSrc AS WSTRINGZ _                           ' __in LPWSTR pSrc
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYREF pDst AS CANDIDATELIST _                      ' __out CANDIDATELIST *pDst
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConversionStatus ( _                       ' VTable offset = 100
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pfdwConversion AS DWORD _                    ' __out DWORD *pfdwConversion
   , BYREF pfdwSentence AS DWORD _                      ' __out DWORD *pfdwSentence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultIMEWnd ( _                          ' VTable offset = 104
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF phDefWnd AS DWORD _                          ' __out HWND *phDefWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionA ( _                           ' VTable offset = 108
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szDescription AS ASCIIZ _                    ' __out LPSTR szDescription
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionW ( _                           ' VTable offset = 112
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szDescription AS WSTRINGZ _                  ' __out LPWSTR szDescription
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideLineA ( _                             ' VTable offset = 116
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF pBuf AS ASCIIZ _                             ' __out LPSTR pBuf
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuideLineW ( _                             ' VTable offset = 120
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwBufLen AS DWORD _                          ' __in DWORD dwBufLen
   , BYREF pBuf AS WSTRINGZ _                           ' __out LPWSTR pBuf
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMEFileNameA ( _                           ' VTable offset = 124
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szFileName AS ASCIIZ _                       ' __out LPSTR szFileName
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMEFileNameW ( _                           ' VTable offset = 128
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF szFileName AS WSTRINGZ _                     ' __out LPWSTR szFileName
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOpenStatus ( _                             ' VTable offset = 132
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 136
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL fdwIndex AS DWORD _                          ' __in DWORD fdwIndex
   , BYREF pdwProperty AS DWORD _                       ' __out DWORD *pdwProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyleA ( _                     ' VTable offset = 140
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFA _                     ' __out STYLEBUFA *pStyleBuf
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyleW ( _                     ' VTable offset = 144
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFW _                     ' __out STYLEBUFW *pStyleBuf
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusWindowPos ( _                        ' VTable offset = 148
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pptPos AS POINT _                            ' __out POINT *pptPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVirtualKey ( _                             ' VTable offset = 152
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYREF puVirtualKey AS DWORD _                      ' __out UINT *puVirtualKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallIMEA ( _                               ' VTable offset = 156
     BYREF szIMEFileName AS ASCIIZ _                    ' __in LPSTR szIMEFileName
   , BYREF szLayoutText AS ASCIIZ _                     ' __in LPSTR szLayoutText
   , BYREF phKL AS DWORD _                              ' __out HKL *phKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallIMEW ( _                               ' VTable offset = 160
     BYREF szIMEFileName AS WSTRINGZ _                  ' __in LPWSTR szIMEFileName
   , BYREF szLayoutText AS WSTRINGZ _                   ' __in LPWSTR szLayoutText
   , BYREF phKL AS DWORD _                              ' __out HKL *phKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsIME ( _                                     ' VTable offset = 164
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUIMessageA ( _                              ' VTable offset = 168
     BYVAL hWnd AS DWORD _                              ' __in HWND hWndIME
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUIMessageW ( _                              ' VTable offset = 172
     BYVAL hWnd AS DWORD _                              ' __in HWND hWndIME
   , BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyIME ( _                                 ' VTable offset = 176
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWordA ( _                             ' VTable offset = 180
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS ASCIIZ _                       ' __in LPSTR szRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWordW ( _                             ' VTable offset = 184
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseContext ( _                            ' VTable offset = 188
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCandidateWindow ( _                        ' VTable offset = 192
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCandidate AS CANDIDATEFORM _                ' __in CANDIDATEFORM *pCandidate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionFontA ( _                       ' VTable offset = 196
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTA _                            ' __in LOGFONTA *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionFontW ( _                       ' VTable offset = 200
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF plf AS LOGFONTW _                            ' __in LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionStringA ( _                     ' VTable offset = 204
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in LPVOID pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in LPVOID pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionStringW ( _                     ' VTable offset = 208
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in LPVOID pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in LPVOID pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionWindow ( _                      ' VTable offset = 212
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pCompForm AS COMPOSITIONFORM _               ' __in COMPOSITIONFORM *pCompForm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConversionStatus ( _                       ' VTable offset = 216
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fdwConversion AS DWORD _                     ' __in DWORD fdwConversion
   , BYVAL fdwSentence AS DWORD _                       ' __in DWORD fdwSentence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpenStatus ( _                             ' VTable offset = 220
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fOpen AS LONG _                              ' __in BOOL fOpen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusWindowPos ( _                        ' VTable offset = 224
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pptPos AS POINT _                            ' __in POINT *pptPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SimulateHotKey ( _                            ' VTable offset = 228
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwHotKeyID AS DWORD _                        ' __in DWORD dwHotKeyID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWordA ( _                           ' VTable offset = 232
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS ASCIIZ _                        ' __in LPSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szUnregister AS ASCIIZ _                     ' __in LPSTR szUnregister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWordW ( _                           ' VTable offset = 236
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szUnregister AS WSTRINGZ _                   ' __in LPWSTR szUnregister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateMessage ( _                           ' VTable offset = 240
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIMC ( _                                   ' VTable offset = 244
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF ppIMC AS INPUTCONTEXT _                      ' __out INPUTCONTEXT **ppIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIMC ( _                                 ' VTable offset = 248
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMCLockCount ( _                           ' VTable offset = 252
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwLockCount AS DWORD _                      ' __out DWORD *pdwLockCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateIMCC ( _                                ' VTable offset = 256
     BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF phIMCC AS DWORD _                            ' __out HIMCC *phIMCC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyIMCC ( _                               ' VTable offset = 260
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockIMCC ( _                                  ' VTable offset = 264
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   , BYREF ppv AS DWORD _                               ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockIMCC ( _                                ' VTable offset = 268
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReSizeIMCC ( _                                ' VTable offset = 272
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF phIMCC AS DWORD _                            ' __out HIMCC *phIMCC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMCCSize ( _                               ' VTable offset = 276
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   , BYREF pdwSize AS DWORD _                           ' __out DWORD *pdwSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIMCCLockCount ( _                          ' VTable offset = 280
     BYVAL hIMCC AS DWORD _                             ' __in HIMCC hIMCC
   , BYREF pdwLockCount AS DWORD _                      ' __out DWORD *pdwLockCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHotKey ( _                                 ' VTable offset = 284
     BYVAL dwHotKeyID AS DWORD _                        ' __in DWORD dwHotKeyID
   , BYREF puModifiers AS DWORD _                       ' __out UINT *puModifiers
   , BYREF puVKey AS DWORD _                            ' __out UINT *puVKey
   , BYREF phKL AS DWORD _                              ' __out HKL *phKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHotKey ( _                                 ' VTable offset = 288
     BYVAL dwHotKeyID AS DWORD _                        ' __in DWORD dwHotKeyID
   , BYVAL uModifiers AS DWORD _                        ' __out UINT uModifiers
   , BYVAL uVKey AS DWORD _                             ' __out UINT uVKey
   , BYVAL hKL AS DWORD _                               ' __out HKL hKL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSoftKeyboard ( _                        ' VTable offset = 292
     BYVAL uType AS DWORD _                             ' __in UINT uType
   , BYVAL hOwner AS DWORD _                            ' __in HWND hOwner
   , BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   , BYREF phSoftKbdWnd AS DWORD _                      ' __out HWND *phSoftKbdWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroySoftKeyboard ( _                       ' VTable offset = 296
     BYVAL hSoftKbdWnd AS DWORD _                       ' __in HWND hSoftKbdWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowSoftKeyboard ( _                          ' VTable offset = 300
     BYVAL hSoftKbdWnd AS DWORD _                       ' __in HWND hSoftKbdWnd
   , BYVAL nCmdShow AS LONG _                           ' __in int nCmdShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageA ( _                              ' VTable offset = 304
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL uCodePage AS DWORD _                         ' __out UINT *uCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLangId ( _                                 ' VTable offset = 308
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYREF plid AS WORD _                               ' __out LANGID *plid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeybdEvent ( _                                ' VTable offset = 312
     BYVAL lgidIME AS WORD _                            ' __in LANGID lgidIME
   , BYVAL bVk AS BYTE _                                ' __in BYTE bVk
   , BYVAL bScan AS BYTE _                              ' __in BYTE bScan
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwExtraInfo AS DWORD _                       ' __in DWORD dwExtraInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockModal ( _                                 ' VTable offset = 316
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockModal ( _                               ' VTable offset = 320
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AssociateContextEx ( _                        ' VTable offset = 324
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableIME ( _                                ' VTable offset = 328
     BYVAL idThread AS DWORD _                          ' __in DWORD idThread
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImeMenuItemsA ( _                          ' VTable offset = 332
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwType AS DWORD _                            ' __in DWORD dwType
   , BYREF pImeParentMenu AS IMEMENUITEMINFOA _         ' __in IMEMENUITEMINFOA *pImeParentMenu
   , BYREF pImeMenu AS IMEMENUITEMINFOA _               ' __out IMEMENUITEMINFOA *pImeMenu
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImeMenuItemsW ( _                          ' VTable offset = 336
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwType AS DWORD _                            ' __in DWORD dwType
   , BYREF pImeParentMenu AS IMEMENUITEMINFOW _         ' __in IMEMENUITEMINFOW *pImeParentMenu
   , BYREF pImeMenu AS IMEMENUITEMINFOW _               ' __out IMEMENUITEMINFOW *pImeMenu
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwResult AS DWORD _                         ' __out DWORD *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumInputContext ( _                          ' VTable offset = 340
     BYVAL idThread AS DWORD _                          ' __in DWORD idThread
   , BYREF ppEnum AS IEnumInputContext _                ' __out IEnumInputContext **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestMessageA ( _                           ' VTable offset = 344
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestMessageW ( _                           ' VTable offset = 348
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendIMCA ( _                                  ' VTable offset = 352
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendIMCW ( _                                  ' VTable offset = 356
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSleeping ( _                                ' VTable offset = 360
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIMMIME_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIME
' IID = {6FE20962-D077-11d0-8FE7-00AA006BCC59}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveIME_INTERFACE_DEFINED)
    %IActiveIME_INTERFACE_DEFINED = 1

INTERFACE IActiveIME $IID_IActiveIME

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Inquire ( _                                   ' VTable offset = 12
     BYVAL dwSystemInfoFlags AS DWORD _                 ' __in DWORD dwSystemInfoFlags
   , BYREF pIMEInfo AS IMEINFO _                        ' __out IMEINFO *pIMEInfo
   , BYREF szWndClass AS WSTRINGZ _                     ' __out LPWSTR szWndClass
   , BYREF pdwPrivate AS DWORD _                        ' __out DWORD *pdwPrivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConversionList ( _                            ' VTable offset = 16
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF szSource AS WSTRINGZ _                       ' __in LPWSTR szSource
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pDest AS CANDIDATELIST _                     ' __out CANDIDATELIST *pDest
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 20
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYVAL pRegisterWord AS REGISTERWORDW _             ' __in REGISTERWORDW *pRegisterWord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 24
     BYVAL uReserved AS DWORD _                         ' __in UINT uReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 28
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYREF pData AS DWORD _                             ' __inout void *pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveContext ( _                          ' VTable offset = 32
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fFlag AS LONG _                              ' __in BOOL fFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessKey ( _                                ' VTable offset = 36
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uVirKey AS DWORD _                           ' __in UINT uVirKey
   , BYVAL lParam AS DWORD _                            ' __in DWORD lParam
   , BYREF pbKeyState AS BYTE _                         ' __in BYTE *pbKeyState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 40
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Select ( _                                    ' VTable offset = 44
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fSelect AS LONG _                            ' __in BOOL fSelect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionString ( _                      ' VTable offset = 48
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in void *pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in void *pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ToAsciiEx ( _                                 ' VTable offset = 52
     BYVAL uVirKey AS DWORD _                           ' __in UINT uVirKey
   , BYVAL uScanCode AS DWORD _                         ' __in UINT uScanCode
   , BYREF pbKeyState AS BYTE _                         ' __in BYTE *pbKeyState
   , BYVAL fuState AS DWORD _                           ' __in UINT fuState
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwTransBuf AS DWORD _                       ' __out DWORD *pdwTransBuf
   , BYREF puSize AS DWORD _                            ' __out UINT *puSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWord ( _                              ' VTable offset = 56
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYVAL szString AS DWORD _                          ' __in LPWSTR szString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWord ( _                            ' VTable offset = 60
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szString AS WSTRINGZ _                       ' __in LPWSTR szString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyle ( _                      ' VTable offset = 64
     BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFW _                     ' __out STYLEBUFW *pStyleBuf
   , BYREF puBufSize AS DWORD _                         ' __out UINT *puBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWord ( _                          ' VTable offset = 68
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF ppEnum AS IEnumRegisterWordW _               ' __out IEnumRegisterWordW **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageA ( _                              ' VTable offset = 72
     BYREF uCodePage AS DWORD _                         ' __out UINT *uCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLangId ( _                                 ' VTable offset = 76
     BYREF plid AS WORD _                               ' __out LANGID *plid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIME_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IActiveIME2
' IID = {e1c4bf0e-2d53-11d2-93e1-0060b067b86e}
' Inherited interface = IActiveIME
' ########################################################################################

#IF NOT %DEF(%IActiveIME2_INTERFACE_DEFINED)
    %IActiveIME2_INTERFACE_DEFINED = 1

INTERFACE IActiveIME2 $IID_IActiveIME2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Inquire ( _                                   ' VTable offset = 12
     BYVAL dwSystemInfoFlags AS DWORD _                 ' __in DWORD dwSystemInfoFlags
   , BYREF pIMEInfo AS IMEINFO _                        ' __out IMEINFO *pIMEInfo
   , BYREF szWndClass AS WSTRINGZ _                     ' __out LPWSTR szWndClass
   , BYREF pdwPrivate AS DWORD _                        ' __out DWORD *pdwPrivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConversionList ( _                            ' VTable offset = 16
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF szSource AS WSTRINGZ _                       ' __in LPWSTR szSource
   , BYVAL uFlag AS DWORD _                             ' __in UINT uFlag
   , BYVAL uBufLen AS DWORD _                           ' __in UINT uBufLen
   , BYREF pDest AS CANDIDATELIST _                     ' __out CANDIDATELIST *pDest
   , BYREF puCopied AS DWORD _                          ' __out UINT *puCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 20
     BYVAL hKL AS DWORD _                               ' __in HKL hKL
   , BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYVAL pRegisterWord AS REGISTERWORDW _             ' __in REGISTERWORDW *pRegisterWord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 24
     BYVAL uReserved AS DWORD _                         ' __in UINT uReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 28
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uEscape AS DWORD _                           ' __in UINT uEscape
   , BYREF pData AS DWORD _                             ' __inout void *pData
   , BYREF plResult AS LONG _                           ' __out LRESULT *plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveContext ( _                          ' VTable offset = 32
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fFlag AS LONG _                              ' __in BOOL fFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessKey ( _                                ' VTable offset = 36
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL uVirKey AS DWORD _                           ' __in UINT uVirKey
   , BYVAL lParam AS DWORD _                            ' __in DWORD lParam
   , BYREF pbKeyState AS BYTE _                         ' __in BYTE *pbKeyState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 40
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwAction AS DWORD _                          ' __in DWORD dwAction
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL dwValue AS DWORD _                           ' __in DWORD dwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Select ( _                                    ' VTable offset = 44
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL fSelect AS LONG _                            ' __in BOOL fSelect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionString ( _                      ' VTable offset = 48
     BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYVAL pComp AS DWORD _                             ' __in void *pComp
   , BYVAL dwCompLen AS DWORD _                         ' __in DWORD dwCompLen
   , BYVAL pRead AS DWORD _                             ' __in void *pRead
   , BYVAL dwReadLen AS DWORD _                         ' __in DWORD dwReadLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ToAsciiEx ( _                                 ' VTable offset = 52
     BYVAL uVirKey AS DWORD _                           ' __in UINT uVirKey
   , BYVAL uScanCode AS DWORD _                         ' __in UINT uScanCode
   , BYREF pbKeyState AS BYTE _                         ' __in BYTE *pbKeyState
   , BYVAL fuState AS DWORD _                           ' __in UINT fuState
   , BYVAL hIMC AS DWORD _                              ' __in HIMC hIMC
   , BYREF pdwTransBuf AS DWORD _                       ' __out DWORD *pdwTransBuf
   , BYREF puSize AS DWORD _                            ' __out UINT *puSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterWord ( _                              ' VTable offset = 56
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szString AS WSTRINGZ _                       ' __in LPWSTR szString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterWord ( _                            ' VTable offset = 60
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szString AS WSTRINGZ _                       ' __in LPWSTR szString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegisterWordStyle ( _                      ' VTable offset = 64
     BYVAL nItem AS DWORD _                             ' __in UINT nItem
   , BYREF pStyleBuf AS STYLEBUFW _                     ' __out STYLEBUFW *pStyleBuf
   , BYREF puBufSize AS DWORD _                         ' __out UINT *puBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRegisterWord ( _                          ' VTable offset = 68
     BYREF szReading AS WSTRINGZ _                      ' __in LPWSTR szReading
   , BYVAL dwStyle AS DWORD _                           ' __in DWORD dwStyle
   , BYREF szRegister AS WSTRINGZ _                     ' __in LPWSTR szRegister
   , BYVAL pData AS DWORD _                             ' __in LPVOID pData
   , BYREF ppEnum AS IEnumRegisterWordW _               ' __out IEnumRegisterWordW **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageA ( _                              ' VTable offset = 72
     BYREF uCodePage AS DWORD _                         ' __out UINT *uCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLangId ( _                                 ' VTable offset = 76
     BYREF plid AS WORD _                               ' __out LANGID *plid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sleep ( _                                     ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unsleep ( _                                   ' VTable offset = 84
     BYVAL fDead AS LONG _                              ' __in BOOL fDead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveIME2_INTERFACE_DEFINED__ */
