' ########################################################################################
' Microsoft Windows
' File: MLang.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MultiLanguage
' Version: 0.2, Locale ID = 0
' Documentation string: MultiLanguage Object Model
' Library GUID: {275C23E0-3747-11D0-9FEA-00AA003F8646}
' ########################################################################################

#INCLUDE THIS ONCE
%MLANG_INC = 1

#INCLUDE ONCE "unknwn.inc"

#IF NOT %DEF(%MultiLanguage_LIBRARY_DEFINED)
%MultiLanguage_LIBRARY_DEFINED = 1

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CMLangConvertCharset = GUID$("{D66D6F99-CDAA-11D0-B822-00C04FC9B31F}")
$CLSID_CMLangString = GUID$("{C04D65CF-B70D-11D0-B188-00AA0038C969}")
$CLSID_CMultiLanguage = GUID$("{275C23E2-3747-11D0-9FEA-00AA003F8646}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumCodePage = GUID$("{275C23E3-3747-11D0-9FEA-00AA003F8646}")
$IID_IEnumRfc1766 = GUID$("{3DC39D1D-C030-11D0-B81B-00C04FC9B31F}")
$IID_IEnumScript = GUID$("{AE5F1430-388B-11D2-8380-00C04F8F5DA1}")
$IID_IMLangCodePages = GUID$("{359F3443-BD4A-11D0-B188-00AA0038C969}")
$IID_IMLangConvertCharset = GUID$("{D66D6F98-CDAA-11D0-B822-00C04FC9B31F}")
$IID_IMLangFontLink = GUID$("{359F3441-BD4A-11D0-B188-00AA0038C969}")
$IID_IMLangFontLink2 = GUID$("{DCCFC162-2B38-11D2-B7EC-00C04F8F5D9A}")
$IID_IMLangLineBreakConsole = GUID$("{F5BE2EE1-BFD7-11D0-B188-00AA0038C969}")
$IID_IMLangString = GUID$("{C04D65CE-B70D-11D0-B188-00AA0038C969}")
$IID_IMLangStringAStr = GUID$("{C04D65D2-B70D-11D0-B188-00AA0038C969}")
$IID_IMLangStringBufA = GUID$("{D24ACD23-BA72-11D0-B188-00AA0038C969}")
$IID_IMLangStringBufW = GUID$("{D24ACD21-BA72-11D0-B188-00AA0038C969}")
$IID_IMLangStringWStr = GUID$("{C04D65D0-B70D-11D0-B188-00AA0038C969}")
$IID_IMultiLanguage = GUID$("{275C23E1-3747-11D0-9FEA-00AA003F8646}")
$IID_IMultiLanguage2 = GUID$("{DCCFC164-2B38-11D2-B7EC-00C04F8F5D9A}")
$IID_IMultiLanguage3 = GUID$("{4E5868AB-B157-4623-9ACC-6A1D9CAEBE04}")

'typedef WORD LANGID;

' MLSTR_FLAGS enum
%MLSTR_READ  = 1
%MLSTR_WRITE = 2

'// dwfIODControl definitions for ValidateCodePageEx()
%CPIOD_PEEK          = &H40000000???
%CPIOD_FORCE_PROMPT  = &H80000000???

' ########################################################################################
' Interface name = IMLangStringBufW
' IID = {D24ACD21-BA72-11D0-B188-00AA0038C969}
' Inherited interface = IUnknown
' Note: Not implemented.
' ########################################################################################

#IF NOT %DEF(%IMLangStringBufW_INTERFACE_DEFINED)
%IMLangStringBufW_INTERFACE_DEFINED = 1

INTERFACE IMLangStringBufW $IID_IMLangStringBufW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF plFlags AS LONG _                            ' __out long *plFlags
   , BYREF pcchBuf AS LONG _                            ' __out long *pcchBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockBuf ( _                                   ' VTable offset = 16
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchMaxLock AS LONG _                         ' __in long cchMaxLock
   , BYREF ppszBuf AS DWORD _                           ' __out WCHAR **ppszBuf
   , BYREF pcchBuf AS LONG _                            ' __out long *pcchBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBuf ( _                                 ' VTable offset = 20
     BYREF pszBuf AS WSTRINGZ _                         ' __in const WCHAR *pszBuf
   , BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchWrite AS LONG _                           ' __in long cchWrite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 24
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchMaxInsert AS LONG _                       ' __in long cchMaxInsert
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 28
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchDelete AS LONG _                          ' __in long cchDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangStringBufW_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangStringBufA
' IID = {D24ACD23-BA72-11D0-B188-00AA0038C969}
' Inherited interface = IUnknown
' Note: Not implemented.
' ########################################################################################

#IF NOT %DEF(%IMLangStringBufA_INTERFACE_DEFINED)
%IMLangStringBufA_INTERFACE_DEFINED = 1

INTERFACE IMLangStringBufA $IID_IMLangStringBufA

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 12
     BYREF plFlags AS LONG _                            ' __out long *plFlags
   , BYREF pcchBuf AS LONG _                            ' __out long *pcchBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockBuf ( _                                   ' VTable offset = 16
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchMaxLock AS LONG _                         ' __in long cchMaxLock
   , BYREF ppszBuf AS DWORD _                           ' __out CHAR **ppszBuf
   , BYREF pcchBuf AS LONG _                            ' __out long *pcchBuf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBuf ( _                                 ' VTable offset = 20
     BYREF pszBuf AS ASCIIZ _                           ' __in const CHAR *pszBuf
   , BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchWrite AS LONG _                           ' __in long cchWrite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Insert ( _                                    ' VTable offset = 24
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchMaxInsert AS LONG _                       ' __in long cchMaxInsert
   , BYREF pcchActua AS LONG _                          ' __out long *pcchActua
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 28
     BYVAL cchOffset AS LONG _                          ' __in long cchOffset
   , BYVAL cchDelete AS LONG _                          ' __in long cchDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangStringBufA_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangString
' IID = {C04D65CE-B70D-11D0-B188-00AA0038C969}
' Inherited interface = IUnknown
' Note: Not implemented.
' ########################################################################################

#IF NOT %DEF(%IMLangString_INTERFACE_DEFINED)
%IMLangString_INTERFACE_DEFINED = 1

INTERFACE IMLangString $IID_IMLangString

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Sync ( _                                      ' VTable offset = 12
     BYVAL fNoAccess AS LONG _                          ' __in BOOL fNoAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF plLen AS LONG _                              ' __retval_out long *plLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMLStr ( _                                  ' VTable offset = 20
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL pSrcMLStr AS IUnknown _                      ' __in IUnknown *pSrcMLStr
   , BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMLStr ( _                                  ' VTable offset = 24
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF piid AS GUID _                               ' __in const IID *piid
   , BYREF ppDestMLStr AS IUnknown _                    ' __out IUnknown **ppDestMLStr
   , BYREF plDestPos AS LONG _                          ' __out long *plDestPos
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangString_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangStringWStr
' IID = {C04D65D0-B70D-11D0-B188-00AA0038C969}
' Inherited interface = IMLangString
' Note: Not implemented.
' ########################################################################################

#IF NOT %DEF(%IMLangStringWStr_INTERFACE_DEFINED)
%IMLangStringWStr_INTERFACE_DEFINED = 1

INTERFACE IMLangStringWStr $IID_IMLangStringWStr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Sync ( _                                      ' VTable offset = 12
     BYVAL fNoAccess AS LONG _                          ' __in BOOL fNoAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF plLen AS LONG _                              ' __retval_out long *plLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMLStr ( _                                  ' VTable offset = 20
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL pSrcMLStr AS IUnknown _                      ' __in IUnknown *pSrcMLStr
   , BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMLStr ( _                                  ' VTable offset = 24
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF piid AS GUID _                               ' __in const IID *piid
   , BYREF ppDestMLStr AS IUnknown _                    ' __out IUnknown **ppDestMLStr
   , BYREF plDestPos AS LONG _                          ' __out long *plDestPos
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWStr ( _                                   ' VTable offset = 28
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrBufW ( _                                ' VTable offset = 32
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL pSrcBuf AS IMLangStringBufW _                ' __in IMLangStringBufW *pSrcBuf
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWStr ( _                                   ' VTable offset = 36
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYREF pszDest AS WSTRINGZ _                        ' __out WCHAR *pszDest
   , BYVAL cchDest AS LONG _                            ' __in long cchDest
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrBufW ( _                                ' VTable offset = 40
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcMaxLen AS LONG _                         ' __in long lSrcMaxLen
   , BYREF ppDestBuf AS IMLangStringBufW _              ' __out IMLangStringBufW **ppDestBuf
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockWStr ( _                                  ' VTable offset = 44
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL cchRequest AS LONG _                         ' __in long cchRequest
   , BYREF ppszDest AS DWORD _                          ' __out WCHAR **ppszDest
   , BYREF pcchDest AS LONG _                           ' __out long *pcchDest
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockWStr ( _                                ' VTable offset = 48
     BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocale ( _                                 ' VTable offset = 52
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL locale AS DWORD _                            ' __in LCID locale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocale ( _                                 ' VTable offset = 56
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcMaxLen AS LONG _                         ' __in long lSrcMaxLen
   , BYREF plocale AS DWORD _                           ' __out LCID *plocale
   , BYREF plLocalePos AS LONG _                        ' __out long *plLocalePos
   , BYREF plLocaleLen AS LONG _                        ' __out long *plLocaleLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangStringWStr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangStringAStr
' IID = {C04D65D2-B70D-11D0-B188-00AA0038C969}
' Inherited interface = IMLangString
' Note: Not implemented.
' ########################################################################################

#IF NOT %DEF(%IMLangStringAStr_INTERFACE_DEFINED)
%IMLangStringAStr_INTERFACE_DEFINED = 1

INTERFACE IMLangStringAStr $IID_IMLangStringAStr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Sync ( _                                      ' VTable offset = 12
     BYVAL fNoAccess AS LONG _                          ' __in BOOL fNoAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLength ( _                                 ' VTable offset = 16
     BYREF plLen AS LONG _                              ' __retval_out long *plLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMLStr ( _                                  ' VTable offset = 20
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL pSrcMLStr AS IUnknown _                      ' __in IUnknown *pSrcMLStr
   , BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMLStr ( _                                  ' VTable offset = 24
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYVAL dwClsContext AS DWORD _                      ' __in DWORD dwClsContext
   , BYREF piid AS GUID _                               ' __in const IID *piid
   , BYREF ppDestMLStr AS IUnknown _                    ' __out IUnknown **ppDestMLStr
   , BYREF plDestPos AS LONG _                          ' __out long *plDestPos
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAStr ( _                                   ' VTable offset = 28
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYREF pszSrc AS ASCIIZ _                           ' __in const CHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStrBufA ( _                                ' VTable offset = 32
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYVAL pSrcBuf AS IMLangStringBufA _                ' __in IMLangStringBufA *pSrcBuf
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAStr ( _                                   ' VTable offset = 36
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL uCodePageIn AS DWORD _                       ' __in UINT uCodePageIn
   , BYREF puCodePageOut AS DWORD _                     ' __out UINT *puCodePageOut
   , BYREF pszDest AS ASCIIZ _                          ' __out CHAR *pszDest
   , BYVAL cchDest AS LONG _                            ' __in long cchDest
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrBufA ( _                                ' VTable offset = 40
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcMaxLen AS LONG _                         ' __in long lSrcMaxLen
   , BYREF puDestCodePage AS DWORD _                    ' __out UINT *puDestCodePage
   , BYREF ppDestBuf AS IMLangStringBufA _              ' __out IMLangStringBufA **ppDestBuf
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockAStr ( _                                  ' VTable offset = 44
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL uCodePageIn AS DWORD _                       ' __in UINT uCodePageIn
   , BYVAL cchRequest AS LONG _                         ' __in long cchRequest
   , BYREF puCodePageOut AS DWORD _                     ' __out UINT *puCodePageOut
   , BYREF ppszDest AS DWORD _                          ' __out CHAR **ppszDest
   , BYREF pcchDest AS LONG _                           ' __out long *pcchDest
   , BYREF plDestLen AS LONG _                          ' __out long *plDestLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockAStr ( _                                ' VTable offset = 48
     BYREF pszSrc AS ASCIIZ _                           ' __in const CHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYREF pcchActual AS LONG _                         ' __out long *pcchActual
   , BYREF plActualLen AS LONG _                        ' __out long *plActualLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocale ( _                                 ' VTable offset = 52
     BYVAL lDestPos AS LONG _                           ' __in long lDestPos
   , BYVAL lDestLen AS LONG _                           ' __in long lDestLen
   , BYVAL locale AS DWORD _                            ' __in LCID locale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocale ( _                                 ' VTable offset = 56
     BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcMaxLen AS LONG _                         ' __in long lSrcMaxLen
   , BYREF plocale AS DWORD _                           ' __out LCID *plocale
   , BYREF plLocalePos AS LONG _                        ' __out long *plLocalePos
   , BYREF plLocaleLen AS LONG _                        ' __out long *plLocaleLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangStringAStr_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangLineBreakConsole
' IID = {F5BE2EE1-BFD7-11D0-B188-00AA0038C969}
' IMLangLineBreakConsole Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMLangLineBreakConsole_INTERFACE_DEFINED)
%IMLangLineBreakConsole_INTERFACE_DEFINED = 1

INTERFACE IMLangLineBreakConsole $IID_IMLangLineBreakConsole

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BreakLineML ( _                               ' VTable offset = 12
     BYVAL pSrcMLStr AS IMLangString _                  ' __in IMLangString *pSrcMLStr
   , BYVAL lSrcPos AS LONG _                            ' __in long lSrcPos
   , BYVAL lSrcLen AS LONG _                            ' __in long lSrcLen
   , BYVAL cMinColumns AS LONG _                        ' __in long cMinColumns
   , BYVAL cMaxColumns AS LONG _                        ' __in long cMaxColumns
   , BYREF plLineLen AS LONG _                          ' __out long *plLineLen
   , BYREF plSkipLen AS LONG _                          ' __out long *plSkipLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BreakLineW ( _                                ' VTable offset = 16
     BYVAL locale AS DWORD _                            ' __in LCID locale
   , BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYVAL cMaxColumns AS LONG _                        ' __in long cMaxColumns
   , BYREF pcchLine AS LONG _                           ' __out long *pcchLine
   , BYREF pcchSkip AS LONG _                           ' __out long *pcchSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BreakLineA ( _                                ' VTable offset = 20
     BYVAL locale AS DWORD _                            ' __in LCID locale
   , BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYREF pszSrc AS ASCIIZ _                           ' __in const CHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYVAL cMaxColumns AS LONG _                        ' __in long cMaxColumns
   , BYREF pcchLine AS LONG _                           ' __out long *pcchLine
   , BYREF pcchSkip AS LONG _                           ' __out long *pcchSkip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangLineBreakConsole_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumCodePage
' IID = {275C23E3-3747-11D0-9FEA-00AA003F8646}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumCodePage_INTERFACE_DEFINED)
%IEnumCodePage_INTERFACE_DEFINED = 1

%MAX_MIMECP_NAME   = 64
%MAX_MIMECSET_NAME = 50
%MAX_MIMEFACE_NAME = 32

' MIMECONTF enum
%MIMECONTF_MAILNEWS         = &H1
%MIMECONTF_BROWSER          = &H2
%MIMECONTF_MINIMAL          = &H4
%MIMECONTF_IMPORT           = &H8
%MIMECONTF_SAVABLE_MAILNEWS = &H100
%MIMECONTF_SAVABLE_BROWSER  = &H200
%MIMECONTF_EXPORT           = &H400
%MIMECONTF_PRIVCONVERTER    = &H10000
%MIMECONTF_VALID            = &H20000
%MIMECONTF_VALID_NLS        = &H40000
%MIMECONTF_MIME_IE4         = &H10000000
%MIMECONTF_MIME_LATEST      = &H20000000
%MIMECONTF_MIME_REGISTRY    = &H40000000

' // Size = 572 bytes
TYPE MIMECPINFO DWORD
   dwFlags             AS DWORD           ' DWORD
   uiCodePage          AS DWORD           ' UINT
   uiFamilyCodePage    AS DWORD           ' UINT
   wszDescription      AS WSTRINGZ * 64   ' WCHAR
   wszWebCharset       AS WSTRINGZ * 50   ' WCHAR
   wszHeaderCharset    AS WSTRINGZ * 50   ' WCHAR
   wszBodyCharset      AS WSTRINGZ * 50   ' WCHAR
   wszFixedWidthFont   AS WSTRINGZ * 32   ' WCHAR
   wszProportionalFont AS WSTRINGZ * 32   ' WCHAR
   bGDICharset         AS BYTE            ' BYTE
END TYPE

' // Size = 108 bytes
TYPE MIMECSETINFO DWORD
   uiCodePage          AS DWORD           ' UINT
   uiInternetEncoding  AS DWORD           ' UINT
   wszCharset          AS WSTRINGZ * 50   ' WCHAR
END TYPE

INTERFACE IEnumCodePage $IID_IEnumCodePage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumCodePage _                    ' __out IEnumCodePage **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS MIMECPINFO _                        ' __out PMIMECPINFO rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumCodePage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumRfc1766
' IID = {3DC39D1D-C030-11D0-B81B-00C04FC9B31F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRfc1766_INTERFACE_DEFINED)
%IEnumRfc1766_INTERFACE_DEFINED = 1

%MAX_RFC1766_NAME = 6
%MAX_LOCALE_NAME  = 32

' // Size = 80 bytes
TYPE RFC1766INFO DWORD
   lcid          AS DWORD           ' LCID
   wszRfc1766    AS WSTRINGZ * 6    ' WCHAR
   wszLocaleName AS WSTRINGZ * 32   ' WCHAR
END TYPE

INTERFACE IEnumRfc1766 $IID_IEnumRfc1766

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumRfc1766 _                     ' __out IEnumRfc1766 **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS RFC1766INFO _                       ' __out PRFC1766INFO rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRfc1766_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumScript
' IID = {AE5F1430-388B-11D2-8380-00C04F8F5DA1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumScript_INTERFACE_DEFINED)
%IEnumScript_INTERFACE_DEFINED = 1

%MAX_SCRIPT_NAME   = 48

'typedef BYTE SCRIPT_ID;
'typedef __int64 SCRIPT_IDS;

' SCRIPTCONTF enum
%sidDefault     = 0
%sidMerge       = %sidDefault     + 1
%sidAsciiSym    = %sidMerge       + 1
%sidAsciiLatin  = %sidAsciiSym    + 1
%sidLatin       = %sidAsciiLatin  + 1
%sidGreek       = %sidLatin       + 1
%sidCyrillic    = %sidGreek       + 1
%sidArmenian    = %sidCyrillic    + 1
%sidHebrew      = %sidArmenian    + 1
%sidArabic      = %sidHebrew      + 1
%sidDevanagari  = %sidArabic      + 1
%sidBengali     = %sidDevanagari  + 1
%sidGurmukhi    = %sidBengali     + 1
%sidGujarati    = %sidGurmukhi    + 1
%sidOriya       = %sidGujarati    + 1
%sidTamil       = %sidOriya       + 1
%sidTelugu      = %sidTamil       + 1
%sidKannada     = %sidTelugu      + 1
%sidMalayalam   = %sidKannada     + 1
%sidThai        = %sidMalayalam   + 1
%sidLao         = %sidThai        + 1
%sidTibetan     = %sidLao         + 1
%sidGeorgian    = %sidTibetan     + 1
%sidHangul      = %sidGeorgian    + 1
%sidKana        = %sidHangul      + 1
%sidBopomofo    = %sidKana        + 1
%sidHan         = %sidBopomofo    + 1
%sidEthiopic    = %sidHan         + 1
%sidCanSyllabic = %sidEthiopic    + 1
%sidCherokee    = %sidCanSyllabic + 1
%sidYi          = %sidCherokee    + 1
%sidBraille     = %sidYi          + 1
%sidRunic       = %sidBraille     + 1
%sidOgham       = %sidRunic       + 1
%sidSinhala     = %sidOgham       + 1
%sidSyriac      = %sidSinhala     + 1
%sidBurmese     = %sidSyriac      + 1
%sidKhmer       = %sidBurmese     + 1
%sidThaana      = %sidKhmer       + 1
%sidMongolian   = %sidThaana      + 1
%sidUserDefined = %sidMongolian   + 1
%sidLim         = %sidUserDefined + 1
%sidFEFirst     = %sidHangul
%sidFELast      = %sidHan

' // Size = 232 bytes
TYPE SCRIPTINFO DWORD
   ScriptId            AS BYTE            ' SCRIPT_ID
   uiCodePage          AS DWORD           ' UINT
   wszDescription      AS WSTRINGZ * 48   ' WCHAR
   wszFixedWidthFont   AS WSTRINGZ * 32   ' WCHAR
   wszProportionalFont AS WSTRINGZ * 32   ' WCHAR
END TYPE

INTERFACE IEnumScript $IID_IEnumScript

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 12
     BYREF ppEnum AS IEnumScript _                      ' __out IEnumScript **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS SCRIPTINFO _                        ' __out PSCRIPTINFO rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 24
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumScript_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangConvertCharset
' IID = {D66D6F98-CDAA-11D0-B822-00C04FC9B31F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMLangConvertCharset_INTERFACE_DEFINED)
%IMLangConvertCharset_INTERFACE_DEFINED = 1

' MLCONVCHAR enum
%MLCONVCHARF_AUTODETECT     = 1
%MLCONVCHARF_ENTITIZE       = 2
%MLCONVCHARF_NCR_ENTITIZE   = 2
%MLCONVCHARF_NAME_ENTITIZE  = 4
%MLCONVCHARF_USEDEFCHAR     = 8
%MLCONVCHARF_NOBESTFITCHARS = 16
%MLCONVCHARF_DETECTJPN      = 32

' MLCP enum
%MLDETECTF_MAILNEWS           = &H1
%MLDETECTF_BROWSER            = &H2
%MLDETECTF_VALID              = &H4
%MLDETECTF_VALID_NLS          = &H8
%MLDETECTF_PRESERVE_ORDER     = &H10
%MLDETECTF_PREFERRED_ONLY     = &H20
%MLDETECTF_FILTER_SPECIALCHAR = &H40
%MLDETECTF_EURO_UTF8          = &H80

INTERFACE IMLangConvertCharset $IID_IMLangConvertCharset

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL uiSrcCodePage AS DWORD _                     ' __in UINT uiSrcCodePage
   , BYVAL uiDstCodePage AS DWORD _                     ' __in UINT uiDstCodePage
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceCodePage ( _                         ' VTable offset = 16
     BYREF puiSrcCodePage AS DWORD _                    ' __out UINT *puiSrcCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDestinationCodePage ( _                    ' VTable offset = 20
     BYREF puiDstCodePage AS DWORD _                    ' __out UINT *puiDstCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 24
     BYREF pdwProperty AS DWORD _                       ' __out DWORD *pdwProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoConversion ( _                              ' VTable offset = 28
     BYREF pSrcStr AS BYTE _                            ' __in BYTE *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS BYTE _                            ' __in BYTE *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoConversionToUnicode ( _                     ' VTable offset = 32
     BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoConversionFromUnicode ( _                   ' VTable offset = 36
     BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangConvertCharset_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMultiLanguage
' IID = {275C23E1-3747-11D0-9FEA-00AA003F8646}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiLanguage_INTERFACE_DEFINED)
%IMultiLanguage_INTERFACE_DEFINED = 1

INTERFACE IMultiLanguage $IID_IMultiLanguage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfCodePageInfo ( _                   ' VTable offset = 12
     BYREF pcCodePage AS DWORD _                        ' __out UINT *pcCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageInfo ( _                           ' VTable offset = 16
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYREF pCodePageInfo AS MIMECPINFO _                ' __out PMIMECPINFO pCodePageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFamilyCodePage ( _                         ' VTable offset = 20
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYREF puiFamilyCodePage AS DWORD _                 ' __out UINT *puiFamilyCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodePages ( _                             ' VTable offset = 24
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYREF ppEnumCodePage AS IEnumCodePage _            ' __out IEnumCodePage **ppEnumCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharsetInfo ( _                            ' VTable offset = 28
     BYVAL Charset AS WSTRING _                         ' __in BSTR Charset
   , BYREF pCharsetInfo AS MIMECSETINFO _               ' __out PMIMECSETINFO pCharsetInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConvertible ( _                             ' VTable offset = 32
     BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertString ( _                             ' VTable offset = 36
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   , BYREF pSrcStr AS BYTE _                            ' __in BYTE *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS BYTE _                            ' __in BYTE *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringToUnicode ( _                    ' VTable offset = 40
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringFromUnicode ( _                  ' VTable offset = 44
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringReset ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766FromLcid ( _                        ' VTable offset = 52
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYREF pbstrRfc1766 AS WSTRING _                    ' __out BSTR *pbstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLcidFromRfc1766 ( _                        ' VTable offset = 56
     BYREF pLocale AS DWORD _                           ' __out LCID *pLocale
   , BYVAL bstrRfc1766 AS WSTRING _                     ' __in BSTR bstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRfc1766 ( _                               ' VTable offset = 60
     BYREF ppEnumRfc1766 AS IEnumRfc1766 _              ' __out IEnumRfc1766 **ppEnumRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766Info ( _                            ' VTable offset = 64
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYREF pRfc1766Info AS RFC1766INFO _                ' __out PRFC1766INFO pRfc1766Info
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateConvertCharset ( _                      ' VTable offset = 68
     BYVAL uiSrcCodePage AS DWORD _                     ' __in UINT uiSrcCodePage
   , BYVAL uiDstCodePage AS DWORD _                     ' __in UINT uiDstCodePage
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF ppMLangConvertCharset AS IMLangConvertCharset _ ' __out IMLangConvertCharset **ppMLangConvertCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiLanguage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMultiLanguage2
' IID = {DCCFC164-2B38-11D2-B7EC-00C04F8F5D9A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiLanguage2_INTERFACE_DEFINED)
%IMultiLanguage2_INTERFACE_DEFINED = 1

' MLDETECTCP enum
%MLDETECTCP_NONE   = 0
%MLDETECTCP_7BIT   = 1
%MLDETECTCP_8BIT   = 2
%MLDETECTCP_DBCS   = 4
%MLDETECTCP_HTML   = 8
%MLDETECTCP_NUMBER = 16

' // Size = 16 bytes
TYPE DetectEncodingInfo DWORD
   nLangID     AS DWORD   ' UINT
   nCodePage   AS DWORD   ' UINT
   nDocPercent AS LONG    ' INT
   nConfidence AS LONG    ' INT
END TYPE

' SCRIPTFONTCONTF enum
%SCRIPTCONTF_FIXED_FONT        = &H1
%SCRIPTCONTF_PROPORTIONAL_FONT = &H2
%SCRIPTCONTF_SCRIPT_USER       = &H10000
%SCRIPTCONTF_SCRIPT_HIDE       = &H20000
%SCRIPTCONTF_SCRIPT_SYSTEM     = &H40000

' // Size = 72 bytes
TYPE SCRIPTFONTINFO QWORD
   scripts AS QUAD            ' SCRIPT_IDS
   wszFont AS WSTRINGZ * 32   ' WCHAR
END TYPE

INTERFACE IMultiLanguage2 $IID_IMultiLanguage2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfCodePageInfo ( _                   ' VTable offset = 12
     BYREF pcCodePage AS DWORD _                        ' __out UINT *pcCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageInfo ( _                           ' VTable offset = 16
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF pCodePageInfo AS MIMECPINFO _                ' __out PMIMECPINFO pCodePageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFamilyCodePage ( _                         ' VTable offset = 20
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYREF puiFamilyCodePage AS DWORD _                 ' __out UINT *puiFamilyCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodePages ( _                             ' VTable offset = 24
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumCodePage AS IEnumCodePage _            ' __out IEnumCodePage **ppEnumCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharsetInfo ( _                            ' VTable offset = 28
     BYVAL Charset AS WSTRING _                         ' __in BSTR Charset
   , BYREF pCharsetInfo AS MIMECSETINFO _               ' __out PMIMECSETINFO pCharsetInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConvertible ( _                             ' VTable offset = 32
     BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertString ( _                             ' VTable offset = 36
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   , BYREF pSrcStr AS BYTE _                            ' __in BYTE *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS BYTE _                            ' __in BYTE *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringToUnicode ( _                    ' VTable offset = 40
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringFromUnicode ( _                  ' VTable offset = 44
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringReset ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766FromLcid ( _                        ' VTable offset = 52
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYREF pbstrRfc1766 AS WSTRING _                    ' __out BSTR *pbstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLcidFromRfc1766 ( _                        ' VTable offset = 56
     BYREF pLocale AS DWORD _                           ' __out LCID *pLocale
   , BYVAL bstrRfc1766 AS WSTRING _                     ' __in BSTR bstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRfc1766 ( _                               ' VTable offset = 60
     BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumRfc1766 AS IEnumRfc1766 _              ' __out IEnumRfc1766 **ppEnumRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766Info ( _                            ' VTable offset = 64
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF pRfc1766Info AS RFC1766INFO _                ' __out PRFC1766INFO pRfc1766Info
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateConvertCharset ( _                      ' VTable offset = 68
     BYVAL uiSrcCodePage AS DWORD _                     ' __in UINT uiSrcCodePage
   , BYVAL uiDstCodePage AS DWORD _                     ' __in UINT uiDstCodePage
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF ppMLangConvertCharset AS IMLangConvertCharset _ ' __out IMLangConvertCharset **ppMLangConvertCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringInIStream ( _                    ' VTable offset = 72
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   , BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   , BYVAL pstmIn AS IStream _                          ' __in IStream *pstmIn
   , BYVAL pstmOut AS IStream _                         ' __in IStream *pstmOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringToUnicodeEx ( _                  ' VTable offset = 76
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringFromUnicodeEx ( _                ' VTable offset = 80
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectCodepageInIStream ( _                   ' VTable offset = 84
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYVAL dwPrefWinCodePage AS DWORD _                 ' __in DWORD dwPrefWinCodePage
   , BYVAL pstmIn AS IStream _                          ' __in IStream *pstmIn
   , BYREF lpEncoding AS DetectEncodingInfo _           ' __inout DetectEncodingInfo *lpEncoding
   , BYREF pnScores AS LONG _                           ' __inout INT *pnScores
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectInputCodepage ( _                       ' VTable offset = 88
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYVAL dwPrefWinCodePage AS DWORD _                 ' __in DWORD dwPrefWinCodePage
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS LONG _                          ' __inout INT *pcSrcSize
   , BYREF lpEncoding AS DetectEncodingInfo _           ' __inout DetectEncodingInfo *lpEncoding
   , BYREF pnScores AS LONG _                           ' __inout INT *pnScores
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateCodePage ( _                          ' VTable offset = 92
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageDescription ( _                    ' VTable offset = 96
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF lpWideCharStr AS WSTRINGZ _                  ' __inout LPWSTR lpWideCharStr
   , BYVAL cchWideChar AS LONG _                        ' __in int cchWideChar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCodePageInstallable ( _                     ' VTable offset = 100
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMimeDBSource ( _                           ' VTable offset = 104
     BYVAL dwSource AS LONG _                           ' __in MIMECONTF dwSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfScripts ( _                        ' VTable offset = 108
     BYREF pnScripts AS DWORD _                         ' __out UINT *pnScripts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumScripts ( _                               ' VTable offset = 112
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumScript AS IEnumScript _                ' __out IEnumScript **ppEnumScript
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateCodePageEx ( _                        ' VTable offset = 116
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwfIODControl AS DWORD _                     ' __in DWORD dwfIODControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiLanguage2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangCodePages
' IID = {359F3443-BD4A-11D0-B188-00AA0038C969}
' IMLangCodePages Interface
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMLangCodePages_INTERFACE_DEFINED)
%IMLangCodePages_INTERFACE_DEFINED = 1

INTERFACE IMLangCodePages $IID_IMLangCodePages

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCharCodePages ( _                          ' VTable offset = 12
     BYVAL chSrc AS WORD _                              ' __in WCHAR chSrc
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrCodePages ( _                           ' VTable offset = 16
     BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYVAL dwPriorityCodePages AS DWORD _               ' __in DWORD dwPriorityCodePages
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   , BYREF pcchCodePages AS LONG _                      ' __out long *pcchCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePageToCodePages ( _                       ' VTable offset = 20
     BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePagesToCodePage ( _                       ' VTable offset = 24
     BYVAL dwCodePages AS DWORD _                       ' __in DWORD dwCodePages
   , BYVAL uDefaultCodePage AS DWORD _                  ' __in UINT uDefaultCodePage
   , BYREF puCodePage AS DWORD _                        ' __out UINT *puCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangCodePages_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangFontLink
' IID = {359F3441-BD4A-11D0-B188-00AA0038C969}
' IMLangFontLink Interface
' Inherited interface = IMLangCodePages
' ########################################################################################

#IF NOT %DEF(%IMLangFontLink_INTERFACE_DEFINED)
%IMLangFontLink_INTERFACE_DEFINED = 1

INTERFACE IMLangFontLink $IID_IMLangFontLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCharCodePages ( _                          ' VTable offset = 12
     BYVAL chSrc AS WORD _                              ' __in WCHAR chSrc
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrCodePages ( _                           ' VTable offset = 16
     BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYVAL dwPriorityCodePages AS DWORD _               ' __in DWORD dwPriorityCodePages
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   , BYREF pcchCodePages AS LONG _                      ' __out long *pcchCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePageToCodePages ( _                       ' VTable offset = 20
     BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePagesToCodePage ( _                       ' VTable offset = 24
     BYVAL dwCodePages AS DWORD _                       ' __in DWORD dwCodePages
   , BYVAL uDefaultCodePage AS DWORD _                  ' __in UINT uDefaultCodePage
   , BYREF puCodePage AS DWORD _                        ' __out UINT *puCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCodePages ( _                          ' VTable offset = 28
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   , BYVAL hFont AS DWORD _                             ' __in HFONT hFont
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapFont ( _                                   ' VTable offset = 32
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   , BYVAL dwCodePages AS DWORD _                       ' __in DWORD dwCodePages
   , BYVAL hSrcFont AS DWORD _                          ' __in HFONT hSrcFont
   , BYREF phDestFont AS DWORD _                        ' __out HFONT *phDestFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFont ( _                               ' VTable offset = 36
     BYVAL hFont AS DWORD _                             ' __in HFONT hFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetFontMapping ( _                          ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangFontLink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMLangFontLink2
' IID = {DCCFC162-2B38-11D2-B7EC-00C04F8F5D9A}
' Inherited interface = IMLangCodePages
' ########################################################################################

#IF NOT %DEF(%IMLangFontLink2_INTERFACE_DEFINED)
%IMLangFontLink2_INTERFACE_DEFINED = 1

' // Size = 4 bytes
TYPE UNICODERANGE WORD
   wcFrom AS WORD   ' WCHAR
   wcTo   AS WORD   ' WCHAR
END TYPE

INTERFACE IMLangFontLink2 $IID_IMLangFontLink2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCharCodePages ( _                          ' VTable offset = 12
     BYVAL chSrc AS WORD _                              ' __in WCHAR chSrc
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStrCodePages ( _                           ' VTable offset = 16
     BYREF pszSrc AS WSTRINGZ _                         ' __in const WCHAR *pszSrc
   , BYVAL cchSrc AS LONG _                             ' __in long cchSrc
   , BYVAL dwPriorityCodePages AS DWORD _               ' __in DWORD dwPriorityCodePages
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   , BYREF pcchCodePages AS LONG _                      ' __out long *pcchCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePageToCodePages ( _                       ' VTable offset = 20
     BYVAL uCodePage AS DWORD _                         ' __in UINT uCodePage
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePagesToCodePage ( _                       ' VTable offset = 24
     BYVAL dwCodePages AS DWORD _                       ' __in DWORD dwCodePages
   , BYVAL uDefaultCodePage AS DWORD _                  ' __in UINT uDefaultCodePage
   , BYREF puCodePage AS DWORD _                        ' __out UINT *puCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontCodePages ( _                          ' VTable offset = 28
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   , BYVAL hFont AS DWORD _                             ' __in HFONT hFont
   , BYREF pdwCodePages AS DWORD _                      ' __out DWORD *pdwCodePages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFont ( _                               ' VTable offset = 32
     BYVAL hFont AS DWORD _                             ' __in HFONT hFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetFontMapping ( _                          ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapFont ( _                                   ' VTable offset = 40
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   , BYVAL dwCodePages AS DWORD _                       ' __in DWORD dwCodePages
   , BYVAL chSrc AS WORD _                              ' __in WCHAR chSrc
   , BYREF pFont AS DWORD _                             ' __out HFONT *pFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFontUnicodeRanges ( _                      ' VTable offset = 44
     BYVAL hDC AS DWORD _                               ' __in HDC hDC
   , BYREF puiRanges AS DWORD _                         ' __inout UINT *puiRanges
   , BYREF pUranges AS UNICODERANGE _                   ' __out UNICODERANGE *pUranges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScriptFontInfo ( _                         ' VTable offset = 48
     BYVAL sid AS BYTE _                                ' __in SCRIPT_ID sid
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF puiFonts AS DWORD _                          ' __inout UINT *puiFonts
   , BYREF pScriptFont AS SCRIPTFONTINFO _              ' __out SCRIPTFONTINFO *pScriptFont
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CodePageToScriptID ( _                        ' VTable offset = 52
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYREF pSid AS BYTE _                               ' __out SCRIPT_ID *pSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMLangFontLink2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMultiLanguage3
' IID = {4E5868AB-B157-4623-9ACC-6A1D9CAEBE04}
' Inherited interface = IMultiLanguage2
' ########################################################################################

#IF NOT %DEF(%IMultiLanguage3_INTERFACE_DEFINED)
%IMultiLanguage3_INTERFACE_DEFINED = 1

INTERFACE IMultiLanguage3 $IID_IMultiLanguage3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfCodePageInfo ( _                   ' VTable offset = 12
     BYREF pcCodePage AS DWORD _                        ' __out UINT *pcCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageInfo ( _                           ' VTable offset = 16
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF pCodePageInfo AS MIMECPINFO _                ' __out PMIMECPINFO pCodePageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFamilyCodePage ( _                         ' VTable offset = 20
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYREF puiFamilyCodePage AS DWORD _                 ' __out UINT *puiFamilyCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCodePages ( _                             ' VTable offset = 24
     BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumCodePage AS IEnumCodePage _            ' __out IEnumCodePage **ppEnumCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharsetInfo ( _                            ' VTable offset = 28
     BYVAL Charset AS WSTRING _                         ' __in BSTR Charset
   , BYREF pCharsetInfo AS MIMECSETINFO _               ' __out PMIMECSETINFO pCharsetInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsConvertible ( _                             ' VTable offset = 32
     BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertString ( _                             ' VTable offset = 36
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   , BYREF pSrcStr AS BYTE _                            ' __in BYTE *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS BYTE _                            ' __in BYTE *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringToUnicode ( _                    ' VTable offset = 40
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringFromUnicode ( _                  ' VTable offset = 44
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringReset ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766FromLcid ( _                        ' VTable offset = 52
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYREF pbstrRfc1766 AS WSTRING _                    ' __out BSTR *pbstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLcidFromRfc1766 ( _                        ' VTable offset = 56
     BYREF pLocale AS DWORD _                           ' __out LCID *pLocale
   , BYVAL bstrRfc1766 AS WSTRING _                     ' __in BSTR bstrRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumRfc1766 ( _                               ' VTable offset = 60
     BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumRfc1766 AS IEnumRfc1766 _              ' __out IEnumRfc1766 **ppEnumRfc1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRfc1766Info ( _                            ' VTable offset = 64
     BYVAL Locale AS DWORD _                            ' __in LCID Locale
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF pRfc1766Info AS RFC1766INFO _                ' __out PRFC1766INFO pRfc1766Info
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateConvertCharset ( _                      ' VTable offset = 68
     BYVAL uiSrcCodePage AS DWORD _                     ' __in UINT uiSrcCodePage
   , BYVAL uiDstCodePage AS DWORD _                     ' __in UINT uiDstCodePage
   , BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF ppMLangConvertCharset AS IMLangConvertCharset _ ' __out IMLangConvertCharset **ppMLangConvertCharset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringInIStream ( _                    ' VTable offset = 72
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   , BYVAL dwSrcEncoding AS DWORD _                     ' __in DWORD dwSrcEncoding
   , BYVAL dwDstEncoding AS DWORD _                     ' __in DWORD dwDstEncoding
   , BYVAL pstmIn AS IStream _                          ' __in IStream *pstmIn
   , BYVAL pstmOut AS IStream _                         ' __in IStream *pstmOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringToUnicodeEx ( _                  ' VTable offset = 76
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS WSTRINGZ _                        ' __in WCHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertStringFromUnicodeEx ( _                ' VTable offset = 80
     BYREF pdwMode AS DWORD _                           ' __inout DWORD *pdwMode
   , BYVAL dwEncoding AS DWORD _                        ' __in DWORD dwEncoding
   , BYREF pSrcStr AS WSTRINGZ _                        ' __in WCHAR *pSrcStr
   , BYREF pcSrcSize AS DWORD _                         ' __inout UINT *pcSrcSize
   , BYREF pDstStr AS ASCIIZ _                          ' __in CHAR *pDstStr
   , BYREF pcDstSize AS DWORD _                         ' __inout UINT *pcDstSize
   , BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYREF lpFallBack AS WSTRINGZ _                     ' __in WCHAR *lpFallBack
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectCodepageInIStream ( _                   ' VTable offset = 84
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYVAL dwPrefWinCodePage AS DWORD _                 ' __in DWORD dwPrefWinCodePage
   , BYVAL pstmIn AS IStream _                          ' __in IStream *pstmIn
   , BYREF lpEncoding AS DetectEncodingInfo _           ' __inout DetectEncodingInfo *lpEncoding
   , BYREF pnScores AS LONG _                           ' __inout INT *pnScores
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectInputCodepage ( _                       ' VTable offset = 88
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   , BYVAL dwPrefWinCodePage AS DWORD _                 ' __in DWORD dwPrefWinCodePage
   , BYREF pSrcStr AS ASCIIZ _                          ' __in CHAR *pSrcStr
   , BYREF pcSrcSize AS LONG _                          ' __inout INT *pcSrcSize
   , BYREF lpEncoding AS DetectEncodingInfo _           ' __inout DetectEncodingInfo *lpEncoding
   , BYREF pnScores AS LONG _                           ' __inout INT *pnScores
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateCodePage ( _                          ' VTable offset = 92
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePageDescription ( _                    ' VTable offset = 96
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF lpWideCharStr AS WSTRINGZ _                  ' __inout LPWSTR lpWideCharStr
   , BYVAL cchWideChar AS LONG _                        ' __in int cchWideChar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsCodePageInstallable ( _                     ' VTable offset = 100
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMimeDBSource ( _                           ' VTable offset = 104
     BYVAL dwSource AS LONG _                           ' __in MIMECONTF dwSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfScripts ( _                        ' VTable offset = 108
     BYREF pnScripts AS DWORD _                         ' __out UINT *pnScripts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumScripts ( _                               ' VTable offset = 112
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL LangId AS WORD _                             ' __in LANGID LangId
   , BYREF ppEnumScript AS IEnumScript _                ' __out IEnumScript **ppEnumScript
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ValidateCodePageEx ( _                        ' VTable offset = 116
     BYVAL uiCodePage AS DWORD _                        ' __in UINT uiCodePage
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwfIODControl AS DWORD _                     ' __in DWORD dwfIODControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectOutboundCodePage ( _                    ' VTable offset = 120
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpWideCharStr AS WSTRINGZ _                  ' __in LPCWSTR lpWideCharStr
   , BYVAL cchWideChar AS DWORD _                       ' __in UINT cchWideChar
   , BYREF puiPreferredCodePages AS DWORD _             ' __in UINT *puiPreferredCodePages
   , BYVAL nPreferredCodePages AS DWORD _               ' __in UINT nPreferredCodePages
   , BYREF puiDetectedCodePages AS DWORD _              ' __in UINT *puiDetectedCodePages
   , BYREF pnDetectedCodePages AS DWORD _               ' __inout UINT *pnDetectedCodePages
   , BYREF lpSpecialChar AS WSTRINGZ _                  ' __in WCHAR *lpSpecialChar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DetectOutboundCodePageInIStream ( _           ' VTable offset = 124
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pStrIn AS IStream _                          ' __in IStream *pStrIn
   , BYREF puiPreferredCodePages AS DWORD _             ' __in UINT *puiPreferredCodePages
   , BYVAL nPreferredCodePages AS DWORD _               ' __in UINT nPreferredCodePages
   , BYREF puiDetectedCodePages AS DWORD _              ' __in UINT *puiDetectedCodePages
   , BYREF pnDetectedCodePages AS DWORD _               ' __inout UINT *pnDetectedCodePages
   , BYREF lpSpecialChar AS WSTRINGZ _                  ' __in WCHAR *lpSpecialChar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiLanguage3_INTERFACE_DEFINED__ */


#ENDIF   ' /* __MultiLanguage_LIBRARY_DEFINED__ */

#IF NOT %DEF(%MLANG_H_API_DEF)
%MLANG_H_API_DEF = 1

'// APIs prototypes

DECLARE FUNCTION LcidToRfc1766 IMPORT "MLANG.DLL" ALIAS "LcidToRfc1766A" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID Locale
 , BYREF pszRfc1766 AS ASCIIZ _                         ' __in_out LPSTR pszRfc1766
 , BYREF iMaxLength AS LONG _                           ' __in     int iMaxLength
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION LcidToRfc1766W IMPORT "MLANG.DLL" ALIAS "LcidToRfc1766W" ( _
   BYVAL Locale AS DWORD _                              ' __in     LCID Locale
 , BYREF pszRfc1766 AS WSTRINGZ _                       ' __in_out LPWSTR pszRfc1766
 , BYREF nChar AS LONG _                                ' __in     int nChar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION Rfc1766ToLcid IMPORT "MLANG.DLL" ALIAS "Rfc1766ToLcidA" ( _
   BYREF pLocale AS DWORD _                             ' __out LCID *pLocale
 , BYREF pszRfc1766 AS ASCIIZ _                         ' __in  LPCSTR pszRfc1766
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION Rfc1766ToLcidW IMPORT "MLANG.DLL" ALIAS "Rfc1766ToLcidW" ( _
   BYREF pLocale AS DWORD _                             ' __out LCID *pLocale
 , BYREF pszRfc1766 AS WSTRINGZ _                       ' __in  LPCWSTR pszRfc1766
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION IsConvertINetStringAvailable IMPORT "MLANG.DLL" ALIAS "IsConvertINetStringAvailable" ( _
   BYVAL dwSrcEncoding AS DWORD _                       ' __in DWORD dwSrcEncoding
 , BYVAL dwDstEncoding AS DWORD _                       ' __in DWORD dwDstEncoding
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ConvertINetString IMPORT "MLANG.DLL" ALIAS "ConvertINetString" ( _
   BYREF lpdwMode AS DWORD _                            ' __out    LPDWORD lpdwMode
 , BYVAL dwSrcEncoding AS DWORD _                       ' __in     DWORD dwSrcEncoding
 , BYVAL dwDstEncoding AS DWORD _                       ' __in     DWORD dwDstEncoding
 , BYREF lpSrcStr AS ASCIIZ _                           ' __in     LPCSTR lpSrcStr
 , BYREF lpnSrcSize AS LONG _                           ' __in_out LPINT lpnSrcSize
 , BYREF lpDstStr AS ASCIIZ _                           ' __in_out LPSTR lpDstStr
 , BYREF lpnDstSize AS LONG _                           ' __in_out LPINT lpnDstSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ConvertINetMultiByteToUnicode IMPORT "MLANG.DLL" ALIAS "ConvertINetMultiByteToUnicode" ( _
   BYREF lpdwMode AS DWORD _                            ' __out    LPDWORD lpdwMode
 , BYVAL dwEncoding AS DWORD _                          ' __in     DWORD dwEncoding
 , BYREF lpSrcStr AS ASCIIZ _                           ' __in     LPCSTR lpSrcStr
 , BYREF lpnMultiCharCount AS LONG _                    ' __in_out LPINT lpnMultiCharCount
 , BYREF lpDstStr AS WSTRINGZ _                         ' __in_out LPWSTR lpDstStr
 , BYREF lpnWideCharCount AS LONG _                     ' __in_out LPINT lpnWideCharCount
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ConvertINetUnicodeToMultiByte IMPORT "MLANG.DLL" ALIAS "ConvertINetUnicodeToMultiByte" ( _
   BYREF lpdwMode AS DWORD _                            ' __out    LPDWORD lpdwMode
 , BYVAL dwEncoding AS DWORD _                          ' __in     DWORD dwEncoding
 , BYREF lpSrcStr AS WSTRINGZ _                         ' __in     LPCWSTR lpSrcStr
 , BYREF lpnWideCharCount AS LONG _                     ' __in_out LPINT lpnWideCharCount
 , BYREF lpDstStr AS ASCIIZ _                           ' __in_out LPSTR lpDstStr
 , BYREF lpnMultiCharCount AS LONG _                    ' __in_out LPINT lpnMultiCharCount
 ) AS LONG                                              ' HRESULT

#ENDIF   ' // _MLANG_H_API_DEF_
