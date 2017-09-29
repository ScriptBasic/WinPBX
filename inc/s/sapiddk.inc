' ########################################################################################
' Microsoft Windows
' File: sapiddk.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SpeechDDKLib
' Version: 5.4, Locale ID = 0
' Documentation string: Microsoft Speech Object DDK Library
' Library GUID: {9903F14C-12CE-4C99-9986-2EE3D7D588A8}
' ########################################################################################

#INCLUDE THIS ONCE
%SAPIDDK_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "sapi.inc"

'#ifndef _SAPI_VER
'// Use SAPI 5.4 by default if target Windows 7
'#if _WIN32_WINNT >= 0x0601
'#define _SAPI_VER 0x054
'#elif _WIN32_WINNT >= 0x0600
'#define _SAPI_VER 0x053
'#else // _WIN32_WINNT < 0x0600
'#define _SAPI_VER 0x051
'#endif // _WIN32_WINNT >= 0x0601
'#endif // _SAPI_VER
'// The following definitions are for SAPI 5.3 and newer
'#if  _SAPI_VER >= 0x053

$$SPRECOEXTENSION          = "RecoExtension"$$
$$SPALTERNATESCLSID        = "AlternatesCLSID"$$
$$SR_LOCALIZED_DESCRIPTION = "Description"$$

$LIBID_SpeechDDKLib = GUID$("{9903F14C-12CE-4C99-9986-2EE3D7D588A8}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D9F6EE60-58C9-458B-88E1-2F908FD7F87C}
$PROGID_SpDataKey1 = "SAPI.SpDataKey.1"
' CLSID = {DA93E903-C843-11D2-A084-00C04F8EF9B5}
$PROGID_SpGramCompBackend1 = "SAPI.SpGramCompBackEnd.1"
' CLSID = {B1E29D59-A675-11D2-8302-00C04F8EE6C0}
$PROGID_SpGrammarCompiler1 = "SAPI.SpGrammarCompiler.1"
' CLSID = {12D73610-A1C9-11D3-BC90-00C04F72DF9F}
$PROGID_SpITNProcessor1 = "SAPI.SpITNProcessor.1"
' CLSID = {3918D75F-0ACB-41F2-B733-92AA15BCECF6}
$PROGID_SpObjectTokenEnum1 = "SAPI.SpObjectTokenEnum.1"
' CLSID = {777B6BBD-2FF2-11D3-88FE-00C04F8EF9B5}
$PROGID_SpPhraseBuilder1 = "SAPI.SpPhraseBuilder.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D9F6EE60-58C9-458B-88E1-2F908FD7F87C}
$PROGID_SpDataKey = "SAPI.SpDataKey"
' CLSID = {DA93E903-C843-11D2-A084-00C04F8EF9B5}
$PROGID_SpGramCompBackend = "SAPI.SpGramCompBackEnd"
' CLSID = {B1E29D59-A675-11D2-8302-00C04F8EE6C0}
$PROGID_SpGrammarCompiler = "SAPI.SpGrammarCompiler"
' CLSID = {12D73610-A1C9-11D3-BC90-00C04F72DF9F}
$PROGID_SpITNProcessor = "SAPI.SpITNProcessor"
' CLSID = {3918D75F-0ACB-41F2-B733-92AA15BCECF6}
$PROGID_SpObjectTokenEnum = "SAPI.SpObjectTokenEnum"
' CLSID = {777B6BBD-2FF2-11D3-88FE-00C04F8EF9B5}
$PROGID_SpPhraseBuilder = "SAPI.SpPhraseBuilder"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SpW3CGrammarCompiler = GUID$("{D2C13906-51EF-454E-BC67-A52475FF074C}")
$CLSID_SpDataKey = GUID$("{D9F6EE60-58C9-458B-88E1-2F908FD7F87C}")
$CLSID_SpGramCompBackend = GUID$("{DA93E903-C843-11D2-A084-00C04F8EF9B5}")
$CLSID_SpGrammarCompiler = GUID$("{B1E29D59-A675-11D2-8302-00C04F8EE6C0}")
$CLSID_SpITNProcessor = GUID$("{12D73610-A1C9-11D3-BC90-00C04F72DF9F}")
$CLSID_SpObjectTokenEnum = GUID$("{3918D75F-0ACB-41F2-B733-92AA15BCECF6}")
$CLSID_SpPhraseBuilder = GUID$("{777B6BBD-2FF2-11D3-88FE-00C04F8EF9B5}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISpErrorLog = GUID$("{F4711347-E608-11D2-A086-00C04F8EF9B5}")
$IID_ISpGramCompBackend = GUID$("{3DDCA27C-665C-4786-9F97-8C90C3488B61}")
$IID_ISpGrammarCompiler = GUID$("{B1E29D58-A675-11D2-8302-00C04F8EE6C0}")
$IID_ISpITNProcessor = GUID$("{12D7360F-A1C9-11D3-BC90-00C04F72DF9F}")
$IID_ISpObjectTokenEnumBuilder = GUID$("{06B64F9F-7FDA-11D2-B4F2-00C04F797396}")
$IID_ISpPhraseBuilder = GUID$("{88A3342A-0BED-4834-922B-88D43173162F}")
$IID_ISpTokenUI = GUID$("{F8E690F0-39CB-4843-B8D7-C84696E1119D}")
$IID_ISpThreadControl = GUID$("{A6BE4D73-4403-4358-B22D-0346E23B1764}")
$IID_ISpTaskManager = GUID$("{2BAEEF81-2CA3-4331-98F3-26EC5ABEFB03}")
$IID_ISpTTSEngineSite = GUID$("{9880499B-CCE9-11D2-B503-00C04F797396}")
$IID_ISpTTSEngine = GUID$("{A74D7C8E-4CC5-4F2F-A6EB-804DEE18500E}")
$IID_ISpCFGInterpreterSite = GUID$("{6A6FFAD8-78B6-473D-B844-98152E4FB16B}")
$IID_ISpCFGInterpreter = GUID$("{F3D3F926-11FC-11D3-BB97-00C04F8EE6C0}")
$IID_ISpSREngineSite = GUID$("{3B414AEC-720C-4883-B9EF-178CD394FB3A}")
$IID_ISpSREngineSite2 = GUID$("{7BC6E012-684A-493E-BDD4-2BF5FBF48CFE}")
$IID_ISpSREngine = GUID$("{2F472991-854B-4465-B613-FBAFB3AD8ED8}")
$IID_ISpSREngine2 = GUID$("{7BA627D8-33F9-4375-90C5-9985AEE5EDE5}")
$IID_ISpSRAlternates = GUID$("{FECE8294-2BE1-408F-8E68-2DE377092F0E}")
$IID_ISpSRAlternates2 = GUID$("{F338F437-CB33-4020-9CAB-C71FF9CE12D3}")
$IID__ISpPrivateEngineCall = GUID$("{8E7C791E-4467-11D3-9723-00C04F72DB08}")
$IID_ISpPrivateEngineCallEx = GUID$("{DEFD682A-FE0A-42B9-BFA1-56D3D6CECFAF}")
$IID_ISpTaskManager = GUID$("{2BAEEF81-2CA3-4331-98F3-26EC5ABEFB03}")
$IID_ISpTTSEngineSite = GUID$("{9880499B-CCE9-11D2-B503-00C04F797396}")
$IID_ISpTTSEngine = GUID$("{A74D7C8E-4CC5-4F2F-A6EB-804DEE18500E}")
$IID_ISpCFGInterpreterSite = GUID$("{6A6FFAD8-78B6-473D-B844-98152E4FB16B}")
$IID_ISpCFGInterpreterSite = GUID$("{6A6FFAD8-78B6-473D-B844-98152E4FB16B}")
$IID_ISpCFGInterpreter = GUID$("{F3D3F926-11FC-11D3-BB97-00C04F8EE6C0}")
$IID_ISpSREngineSite = GUID$("{3B414AEC-720C-4883-B9EF-178CD394FB3A}")
$IID_ISpSREngineSite2 = GUID$("{7BC6E012-684A-493E-BDD4-2BF5FBF48CFE}")
$IID_ISpSREngine = GUID$("{2F472991-854B-4465-B613-FBAFB3AD8ED8}")
$IID_ISpSREngine2 = GUID$("{7BA627D8-33F9-4375-90C5-9985AEE5EDE5}")
$IID_ISpSRAlternates = GUID$("{FECE8294-2BE1-408F-8E68-2DE377092F0E}")
$IID_ISpSRAlternates2 = GUID$("{F338F437-CB33-4020-9CAB-C71FF9CE12D3}")
$IID__ISpPrivateEngineCall = GUID$("{8E7C791E-4467-11D3-9723-00C04F72DB08}")
$IID__ISpPrivateEngineCallEx = GUID$("{DEFD682A-FE0A-42B9-BFA1-56D3D6CECFAF}")


' ########################################################################################
' Interface name = ISpTokenUI
' IID = {F8E690F0-39CB-4843-B8D7-C84696E1119D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpTokenUI_INTERFACE_DEFINED)
    %ISpTokenUI_INTERFACE_DEFINED = 1

INTERFACE ISpTokenUI $IID_ISpTokenUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsUISupported ( _                             ' VTable offset = 12
     BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in LPCWSTR pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   , BYREF pfSupported AS LONG _                        ' __out BOOL *pfSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayUI ( _                                 ' VTable offset = 16
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF pszTitle AS WSTRINGZ _                       ' __in_opt LPCWSTR pszTitle
   , BYREF pszTypeOfUI AS WSTRINGZ _                    ' __in LPCWSTR pszTypeOfUI
   , BYVAL pvExtraData AS DWORD _                       ' __in void *pvExtraData
   , BYVAL cbExtraData AS DWORD _                       ' __in ULONG cbExtraData
   , BYVAL pToken AS ISpObjectToken _                   ' __in ISpObjectToken *pToken
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpTokenUI_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpObjectTokenEnumBuilder
' IID = {06B64F9F-7FDA-11D2-B4F2-00C04F797396}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IEnumSpObjectTokens
' ########################################################################################

#IF NOT %DEF(%ISpObjectTokenEnumBuilder_INTERFACE_DEFINED)
    %ISpObjectTokenEnumBuilder_INTERFACE_DEFINED = 1

INTERFACE ISpObjectTokenEnumBuilder $IID_ISpObjectTokenEnumBuilder

   INHERIT IUnknown

   ' =====================================================================================
   ' IEnumSpObjectTokens Methods
   ' =====================================================================================
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pelt AS ISpObjectToken _                     ' __out ISpObjectToken **pelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumSpObjectTokens _              ' __out IEnumSpObjectTokens **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 28
     BYVAL Index AS DWORD _                             ' __in ULONG Index
   , BYREF ppToken AS ISpObjectToken _                  ' __out ISpObjectToken **ppToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 32
     BYREF pCount AS DWORD _                            ' __out ULONG *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpObjectTokenEnumBuilder Methods
   ' =====================================================================================
   METHOD SetAttribs ( _                                ' VTable offset = 36
     BYREF pszReqAttribs AS WSTRINGZ _                  ' __in LPCWSTR pszReqAttribs
   , BYREF pszOptAttribs AS WSTRINGZ _                  ' __in LPCWSTR pszOptAttribs VT_LPWSTR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTokens ( _                                 ' VTable offset = 40
     BYVAL cTokens AS DWORD _                           ' __in ULONG cTokens
   , BYREF pToken AS ISpObjectToken _                   ' __out ISpObjectToken **pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTokensFromDataKey ( _                      ' VTable offset = 44
     BYVAL pDataKey AS ISpDataKey _                     ' __in ISpDataKey *pDataKey
   , BYREF pszSubKey AS WSTRINGZ _                      ' __in LPCWSTR pszSubKey
   , BYREF pszCategoryId AS WSTRINGZ _                  ' __in LPCWSTR pszCategoryId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTokensFromTokenEnum ( _                    ' VTable offset = 48
     BYVAL pTokenEnum AS IEnumSpObjectTokens _          ' __in IEnumSpObjectTokens *pTokenEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sort ( _                                      ' VTable offset = 52
     BYREF pszTokenIdToListFirst AS WSTRINGZ _          ' __in LPCWSTR pszTokenIdToListFirst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpObjectTokenEnumBuilder_INTERFACE_DEFINED__ */

'typedef void *SPWORDHANDLE;
'typedef void *SPRULEHANDLE;
'typedef void *SPGRAMMARHANDLE;
'typedef void *SPRECOCONTEXTHANDLE;
'typedef void *SPPHRASERULEHANDLE;
'typedef void *SPPHRASEPROPERTYHANDLE;
'typedef void *SPTRANSITIONID;

' ########################################################################################
' Interface name = ISpErrorLog
' IID = {F4711347-E608-11D2-A086-00C04F8EF9B5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpErrorLog_INTERFACE_DEFINED)
    %ISpErrorLog_INTERFACE_DEFINED = 1

INTERFACE ISpErrorLog $IID_ISpErrorLog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddError ( _                                  ' VTable offset = 12
     BYVAL lLineNumber AS LONG _                        ' __in const long lLineNumber
   , BYVAL hr AS LONG _                                 ' __in HRESULT hr
   , BYREF pszDescription AS WSTRINGZ _                 ' __in LPCWSTR pszDescription
   , BYREF pszHelpFile AS WSTRINGZ _                    ' __in_opt LPCWSTR pszHelpFile
   , BYVAL dwHelpContext AS DWORD _                     ' __in DWORD dwHelpContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpErrorLog_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpGrammarCompiler
' IID = {B1E29D58-A675-11D2-8302-00C04F8EE6C0}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpGrammarCompiler_INTERFACE_DEFINED)
    %ISpGrammarCompiler_INTERFACE_DEFINED = 1

INTERFACE ISpGrammarCompiler $IID_ISpGrammarCompiler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CompileStream ( _                             ' VTable offset = 12
     BYVAL pSource AS IStream _                         ' __in IStream *pSource
   , BYVAL pDest AS IStream _                           ' __in IStream *pDest
   , BYVAL pHeader AS IStream _                         ' __in IStream *pHeader
   , BYVAL pReserved AS IUnknown _                      ' __in IUnknown *pReserved
   , BYVAL pErrorLog AS ISpErrorLog _                   ' __in ISpErrorLog *pErrorLog
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpGrammarCompiler_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpGramCompBackend
' IID = {3DDCA27C-665C-4786-9F97-8C90C3488B61}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpGrammarBuilder
' ########################################################################################

#IF NOT %DEF(%ISpGramCompBackend_INTERFACE_DEFINED)
    %ISpGramCompBackend_INTERFACE_DEFINED = 1

INTERFACE ISpGramCompBackend $IID_ISpGramCompBackend

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpGrammarBuilder Methods
   ' =====================================================================================
   METHOD ResetGrammar ( _                              ' VTable offset = 12
     BYVAL NewLanguage AS WORD _                        ' __in WORD NewLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRule ( _                                   ' VTable offset = 16
     BYREF pszRuleName AS WSTRINGZ _                    ' __in const WCHAR *pszRuleName
   , BYVAL dwRuleId AS DWORD _                          ' __in DWORD dwRuleId
   , BYVAL dwAttributes AS DWORD _                      ' __in DWORD dwAttributes
   , BYVAL fCreateIfNotExist AS LONG _                  ' __in BOOL fCreateIfNotExist
   , BYREF phInitialState AS DWORD _                    ' __out SPSTATEHANDLE *phInitialState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearRule ( _                                 ' VTable offset = 20
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNewState ( _                            ' VTable offset = 24
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   , BYREF phState AS DWORD _                           ' __out SPSTATEHANDLE *phState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddWordTransition ( _                         ' VTable offset = 28
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYREF psz AS WSTRINGZ _                            ' __in const WCHAR *psz
   , BYREF pszSeparators AS WSTRINGZ _                  ' __in const WCHAR *pszSeparators
   , BYVAL eWordType AS LONG _                          ' __in SPGRAMMARWORDTYPE eWordType
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRuleTransition ( _                         ' VTable offset = 32
     BYVAL hFromState AS DWORD _                        ' __in SPSTATEHANDLE hFromState
   , BYVAL hToState AS DWORD _                          ' __in SPSTATEHANDLE hToState
   , BYVAL hRule AS DWORD _                             ' __in SPSTATEHANDLE hRule
   , BYVAL Weight AS SINGLE _                           ' __in float Weight
   , BYREF pPropInfo AS SPPROPERTYINFO _                ' __in const SPPROPERTYINFO *pPropInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddResource ( _                               ' VTable offset = 36
     BYVAL hRuleState AS DWORD _                        ' __in SPSTATEHANDLE hRuleState
   , BYREF pszResourceName AS WSTRINGZ _                ' __in const WCHAR *pszResourceName
   , BYREF pszResourceValue AS WSTRINGZ _               ' __in const WCHAR *pszResourceValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 40
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpGramCompBackend Methods
   ' =====================================================================================
   METHOD SetSaveObjects ( _                            ' VTable offset = 44
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL pErrorLog AS ISpErrorLog _                   ' __in ISpErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitFromBinaryGrammar ( _                     ' VTable offset = 48
     BYREF pBinaryData AS SPBINARYGRAMMAR _             ' __in const SPBINARYGRAMMAR *pBinaryData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpGramCompBackend_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpITNProcessor
' IID = {12D7360F-A1C9-11D3-BC90-00C04F72DF9F}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpITNProcessor_INTERFACE_DEFINED)
    %ISpITNProcessor_INTERFACE_DEFINED = 1

INTERFACE ISpITNProcessor $IID_ISpITNProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadITNGrammar ( _                            ' VTable offset = 12
     BYREF pszCLSID AS WSTRINGZ _                       ' __in LPWSTR pszCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ITNPhrase ( _                                 ' VTable offset = 16
     BYVAL pPhrase AS ISpPhraseBuilder _                ' __in ISpPhraseBuilder *pPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpITNProcessor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpPhraseBuilder
' IID = {88A3342A-0BED-4834-922B-88D43173162F}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = ISpPhrase
' ########################################################################################

#IF NOT %DEF(%ISpPhraseBuilder_INTERFACE_DEFINED)
    %ISpPhraseBuilder_INTERFACE_DEFINED = 1

INTERFACE ISpPhraseBuilder $IID_ISpPhraseBuilder

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpPhrase Methods
   ' =====================================================================================
   METHOD GetPhrase ( _                                 ' VTable offset = 12
     BYREF ppCoMemPhrase AS SPPHRASE _                  ' __out SPPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSerializedPhrase ( _                       ' VTable offset = 16
     BYREF ppCoMemPhrase AS SPSERIALIZEDPHRASE _        ' __out SPSERIALIZEDPHRASE **ppCoMemPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 20
     BYVAL ulStart AS DWORD _                           ' __in ULONG ulStart
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   , BYVAL fUseTextReplacements AS LONG _               ' __in BOOL fUseTextReplacements
   , BYREF ppszCoMemText AS DWORD _                     ' __out WCHAR **ppszCoMemText
   , BYREF pbDisplayAttributes AS BYTE _                ' __out BYTE *pbDisplayAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discard ( _                                   ' VTable offset = 24
     BYVAL dwValueTypes AS DWORD _                      ' __in DWORD dwValueTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpPhraseBuilder Methods
   ' =====================================================================================
   METHOD InitFromPhrase ( _                            ' VTable offset = 28
     BYREF pPhrase AS SPPHRASE _                        ' __in const SPPHRASE *pPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitFromSerializedPhrase ( _                  ' VTable offset = 32
     BYREF pPhrase AS SPSERIALIZEDPHRASE _              ' __in const SPSERIALIZEDPHRASE *pPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddElements ( _                               ' VTable offset = 36
     BYVAL cElements AS DWORD _                         ' __in ULONG cElements
   , BYREF pElement AS SPPHRASEELEMENT _                ' __in const SPPHRASEELEMENT *pElement
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRules ( _                                  ' VTable offset = 40
     BYVAL hParent AS DWORD _                           ' __in const SPPHRASERULEHANDLE hParent
   , BYREF pRule AS SPPHRASERULE _                      ' __in const SPPHRASERULE *pRule
   , BYREF phNewRule AS DWORD _                         ' __out SPPHRASERULEHANDLE *phNewRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddProperties ( _                             ' VTable offset = 44
     BYVAL hParent AS DWORD _                           ' __in const SPPHRASEPROPERTYHANDLE hParent
   , BYREF pProperty AS SPPHRASEPROPERTY _              ' __in const SPPHRASEPROPERTY *pProperty
   , BYREF phNewProperty AS DWORD _                     ' __out SPPHRASEPROPERTYHANDLE *phNewProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddReplacements ( _                           ' VTable offset = 48
     BYVAL cReplacements AS DWORD _                     ' __in ULONG cReplacements
   , BYREF pReplacements AS SPPHRASEREPLACEMENT _       ' __in const SPPHRASEREPLACEMENT *pReplacements
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpPhraseBuilder_INTERFACE_DEFINED__ */

'#if defined(__cplusplus)
'interface ISpTask
'{
'virtual HRESULT STDMETHODCALLTYPE Execute(
'                 void *pvTaskData,
'                 volatile const BOOL* pfContinueProcessing) = 0;
'};
'#else
'typedef void *ISpTask;
'#endif

'#if defined(__cplusplus)
'interface ISpThreadTask
'{
'virtual HRESULT STDMETHODCALLTYPE InitThread(
'                 void * pvTaskData,
'                 HWND hwnd) = 0;
'virtual HRESULT STDMETHODCALLTYPE ThreadProc(
'                 void *pvTaskData,
'                 HANDLE hExitThreadEvent,
'                 HANDLE hNotifyEvent,
'                 HWND hwndWorker,
'                 volatile const BOOL * pfContinueProcessing) = 0;
'virtual LRESULT STDMETHODCALLTYPE WindowMessage(
'                 void *pvTaskData,
'                 HWND hWnd,
'                 UINT Msg,
'                 WPARAM wParam,
'                 LPARAM lParam) = 0;
'};
'#else
'typedef void *ISpThreadTask;
'#endif

' ########################################################################################
' Interface name = ISpThreadControl
' IID = {A6BE4D73-4403-4358-B22D-0346E23B1764}
' Inherited interface = ISpNotifySink
' ########################################################################################

#IF NOT %DEF(%ISpThreadControl_INTERFACE_DEFINED)
    %ISpThreadControl_INTERFACE_DEFINED = 1

INTERFACE ISpThreadControl $IID_ISpThreadControl

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpNotifySink method
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpThreadControl methods
   ' =====================================================================================
   METHOD StartThread ( _                               ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForThreadDone ( _                         ' VTable offset = 20
     BYVAL fForceStop AS LONG _                         ' __in BOOL fForceStop
   , BYREF phrThreadResult AS LONG _                    ' __out HRESULT *phrThreadResult
   , BYVAL msTimeOut AS DWORD _                         ' __in ULONG msTimeOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TerminateThread ( _                           ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThreadHandle ( _                              ' VTable offset = 28
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================
   METHOD ThreadId ( _                                  ' VTable offset = 32
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD NotifyEvent ( _                               ' VTable offset = 36
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================
   METHOD WindowHandle ( _                              ' VTable offset = 40
   ) AS DWORD                                           ' HWND
   ' =====================================================================================
   METHOD ThreadCompleteEvent ( _                       ' VTable offset = 44
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================
   METHOD ExitThreadEvent ( _                           ' VTable offset = 48
   ) AS DWORD                                           ' HANDLE
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpThreadControl_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE SPTMTHREADINFO DWORD
   lPoolSize              AS LONG    ' long
   lPriority              AS LONG    ' long
   ulConcurrencyLimit     AS DWORD   ' ULONG
   ulMaxQuickAllocThreads AS DWORD   ' ULONG
END TYPE

' ########################################################################################
' Interface name = ISpTaskManager
' IID = {2BAEEF81-2CA3-4331-98F3-26EC5ABEFB03}
' Inherited interface = IUnknown
' ########################################################################################

'#IF NOT %DEF(%ISpTaskManager_INTERFACE_DEFINED)
'    %ISpTaskManager_INTERFACE_DEFINED = 1

'INTERFACE ISpTaskManager $IID_ISpTaskManager

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD SetThreadPoolInfo ( _                         ' VTable offset = 12
'     BYREF pPoolInfo AS SPTMTHREADINFO _                ' __in const SPTMTHREADINFO *pPoolInfo
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetThreadPoolInfo ( _                         ' VTable offset = 16
'     BYREF pPoolInfo AS SPTMTHREADINFO _                ' __out SPTMTHREADINFO *pPoolInfo
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD QueueTask ( _                                 ' VTable offset = 20
'     BYVAL pTask AS ISpTask _                           ' __in ISpTask *pTask
'   , BYVAL pvTaskData AS DWORD _                        ' __in void *pvTaskData
'   , BYVAL hCompEvent AS DWORD _                        ' __in HANDLE hCompEvent
'   , BYREF pdwGroupId AS DWORD _                        ' __inout DWORD *pdwGroupId
'   , BYREF pTaskID AS DWORD _                           ' __out DWORD *pTaskID
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CreateReoccurringTask ( _                     ' VTable offset = 24
'     BYVAL pTask AS ISpTask _                           ' __in ISpTask *pTask
'   , BYVAL pvTaskData AS DWORD _                        ' __in void *pvTaskData
'   , BYVAL hCompEvent AS DWORD _                        ' __in HANDLE hCompEvent
'   , BYREF ppTaskCtrl AS ISpNotifySink _                ' __out ISpNotifySink **ppTaskCtrl
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CreateThreadControl ( _                       ' VTable offset = 28
'     BYVAL pTask AS ISpThreadTask _                     ' __in ISpThreadTask *pTask
'   , BYVAL pvTaskData AS DWORD _                        ' __in void *pvTaskData
'   , BYVAL nPriority AS LONG _                          ' __in long nPriority
'   , BYREF ppTaskCtrl AS ISpThreadControl _             ' __out ISpThreadControl **ppTaskCtrl
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TerminateTask ( _                             ' VTable offset = 32
'     BYVAL dwTaskId AS DWORD _                          ' __in DWORD dwTaskId
'   , BYVAL ulWaitPeriod AS DWORD _                      ' __in ULONG ulWaitPeriod
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD TerminateTaskGroup ( _                        ' VTable offset = 36
'     BYVAL dwGroupId AS DWORD _                         ' __in DWORD dwGroupId
'   , BYVAL ulWaitPeriod AS DWORD _                      ' __in ULONG ulWaitPeriod
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __ISpTaskManager_INTERFACE_DEFINED__ */


' enum SPVSKIPTYPE
%SPVST_SENTENCE   = 1   ' ( 1L << 0 )

' enum SPVESACTIONS
%SPVES_CONTINUE = 0
%SPVES_ABORT    = 1   ' ( 1L << 0 )
%SPVES_SKIP     = 2   ' ( 1L << 1 )
%SPVES_RATE     = 4   ' ( 1L << 2 )
%SPVES_VOLUME   = 8   ' ( 1L << 3 )

' ########################################################################################
' Interface name = ISpTTSEngineSite
' IID = {9880499B-CCE9-11D2-B503-00C04F797396}
' Inherited interface = ISpEventSink
' ########################################################################################

#IF NOT %DEF(%ISpTTSEngineSite_INTERFACE_DEFINED)
    %ISpTTSEngineSite_INTERFACE_DEFINED = 1

INTERFACE ISpTTSEngineSite $IID_ISpTTSEngineSite

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpEventSink methods
   ' =====================================================================================
   METHOD AddEvents ( _                                 ' VTable offset = 12
     BYREF pEventArray AS SPEVENT _                     ' __in const SPEVENT *pEventArray
   , BYVAL ulCount AS DWORD _                           ' __in ULONG ulCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventInterest ( _                          ' VTable offset = 16
     BYREF pullEventInterest AS QUAD _                  ' __out ULONGLONG *pullEventInterest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpTTSEngineSite methods
   ' =====================================================================================
   METHOD GetActions ( _                                ' VTable offset = 20
   ) AS DWORD                                           ' DWORD
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 24
     BYVAL pBuff AS DWORD _                             ' __in const void *pBuff
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 28
     BYREF pRateAdjust AS LONG _                        ' __out long *pRateAdjust
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolume ( _                                 ' VTable offset = 32
     BYREF pusVolume AS WORD _                          ' __out USHORT *pusVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSkipInfo ( _                               ' VTable offset = 36
     BYREF peType AS LONG _                             ' __out SPVSKIPTYPE *peType
   , BYREF plNumItems AS LONG _                         ' __out long *plNumItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompleteSkip ( _                              ' VTable offset = 40
     BYVAL ulNumSkipped AS LONG _                       ' __in long ulNumSkipped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpTTSEngineSite_INTERFACE_DEFINED__ */

' // Size = 68 bytes
TYPE SPVTEXTFRAG DWORD
   pNext           AS SPVTEXTFRAG PTR   ' struct SPVTEXTFRAG *
   State           AS SPVSTATE          ' SPVSTATE
   pTextStart      AS WSTRINGZ PTR      ' LPCWSTR
   ulTextLen       AS DWORD             ' ULONG
   ulTextSrcOffset AS DWORD             ' ULONG
END TYPE

' ########################################################################################
' Interface name = ISpTTSEngine
' IID = {A74D7C8E-4CC5-4F2F-A6EB-804DEE18500E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpTTSEngine_INTERFACE_DEFINED)
    %ISpTTSEngine_INTERFACE_DEFINED = 1

INTERFACE ISpTTSEngine $IID_ISpTTSEngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Speak ( _                                     ' VTable offset = 12
     BYVAL dwSpeakFlags AS DWORD _                      ' __in DWORD dwSpeakFlags
   , BYREF rguidFormatId AS GUID _                      ' __in REFGUID rguidFormatId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   , BYREF pTextFragList AS SPVTEXTFRAG _               ' __in const SPVTEXTFRAG *pTextFragList
   , BYVAL pOutputSite AS ISpTTSEngineSite _            ' __in ISpTTSEngineSite *pOutputSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFormat ( _                           ' VTable offset = 16
     BYREF pTargetFmtId AS GUID _                       ' __in const GUID *pTargetFmtId
   , BYREF pTargetWaveFormatEx AS WAVEFORMATEX _        ' __in const WAVEFORMATEX *pTargetWaveFormatEx
   , BYREF pOutputFormatId AS GUID _                    ' __out GUID *pOutputFormatId
   , BYREF ppCoMemOutputWaveFormatEx AS WAVEFORMATEX _  ' __out WAVEFORMATEX **ppCoMemOutputWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpTTSEngine_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE SPWORDENTRY DWORD FILL
   hWord           AS DWORD          ' SPWORDHANDLE
   LangID          AS WORD           ' WORD
   pszDisplayText  AS WSTRINGZ PTR   ' WCHAR *
   pszLexicalForm  AS WSTRINGZ PTR   ' WCHAR *
   aPhoneId        AS WSTRINGZ PTR   ' SPPHONEID *
   pvClientContext AS DWORD          ' void *
END TYPE

' // Size = 20 bytes
TYPE SPRULEENTRY DWORD
   hRule                  AS DWORD   ' SPRULEHANDLE
   hInitialState          AS DWORD   ' SPSTATEHANDLE
   Attributes             AS DWORD   ' DWORD
   pvClientRuleContext    AS DWORD   ' void *
   pvClientGrammarContext AS DWORD   ' void *
END TYPE

' enum SPTRANSITIONTYPE
%SPTRANSEPSILON   = 0
%SPTRANSWORD      = %SPTRANSEPSILON  + 1
%SPTRANSRULE      = %SPTRANSWORD     + 1
%SPTRANSTEXTBUF   = %SPTRANSRULE     + 1
%SPTRANSWILDCARD  = %SPTRANSTEXTBUF  + 1
%SPTRANSDICTATION = %SPTRANSWILDCARD + 1

' // Size = 4 bytes
TYPE SPTRANSITIONENTRY_STRUCT_1 DWORD
   fHasProperty AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE SPTRANSITIONENTRY_UNION_STRUCT_1 DWORD
   hRuleInitialState   AS DWORD   ' SPSTATEHANDLE
   hRule               AS DWORD   ' SPSTATEHANDLE
   pvClientRuleContext AS DWORD   ' void *
END TYPE

' // Size = 8 bytes
TYPE SPTRANSITIONENTRY_UNION_STRUCT_2 DWORD
   hWord               AS DWORD   ' SPWORDHANDLE
   pvClientWordContext AS DWORD   ' void *
END TYPE

' // Size = 4 bytes
TYPE SPTRANSITIONENTRY_UNION_STRUCT_3 DWORD
   pvGrammarCookie AS DWORD   ' void *
END TYPE

' // Size = 12 bytes
UNION SPTRANSITIONENTRY_UNION DWORD
   SPTRANSITIONENTRY_UNION_STRUCT_1
   SPTRANSITIONENTRY_UNION_STRUCT_2
   SPTRANSITIONENTRY_UNION_STRUCT_3
END UNION

' // Size = 32 bytes
TYPE SPTRANSITIONENTRY BYTE
   ID                 AS DWORD    ' SPTRANSITIONID
   hNextState         AS DWORD    ' SPSTATEHANDLE
   Type               AS BYTE     ' BYTE
   RequiredConfidence AS BYTE     ' char
   SPTRANSITIONENTRY_STRUCT_1
   Weight             AS SINGLE   ' float
   SPTRANSITIONENTRY_UNION
END TYPE

' // Size = 32 bytes
TYPE SPTRANSITIONPROPERTY QWORD FILL   ' Must be 8 byte aligned
   pszName  AS WSTRINGZ PTR   ' LPCWSTR
   ulId     AS DWORD          ' ULONG
   pszValue AS WSTRINGZ PTR   ' LPCWSTR
   vValue   AS tagVARIANT     ' VARIANT
END TYPE

' // Size = 24 bytes
TYPE SPSTATEINFO DWORD
   cAllocatedEntries   AS DWORD                   ' ULONG
   pTransitions        AS SPTRANSITIONENTRY PTR   ' SPTRANSITIONENTRY *
   cEpsilons           AS DWORD                   ' ULONG
   cRules              AS DWORD                   ' ULONG
   cWords              AS DWORD                   ' ULONG
   cSpecialTransitions AS DWORD                   ' ULONG
END TYPE

' // Size = 48 bytes
TYPE SPPATHENTRY DWORD
   hTransition AS DWORD             ' SPTRANSITIONID
   elem        AS SPPHRASEELEMENT   ' SPPHRASEELEMENT
END TYPE

' ########################################################################################
' Interface name = ISpCFGInterpreterSite
' IID = {F8E690F0-39CB-4843-B8D7-C84696E1119D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpCFGInterpreterSite_INTERFACE_DEFINED)
    %ISpCFGInterpreterSite_INTERFACE_DEFINED = 1

INTERFACE ISpCFGInterpreterSite $IID_ISpCFGInterpreterSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddTextReplacement ( _                        ' VTable offset = 12
     BYREF pReplace AS SPPHRASEREPLACEMENT _            ' __in SPPHRASEREPLACEMENT *pReplace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddProperty ( _                               ' VTable offset = 16
     BYREF pProperty AS SPPHRASEPROPERTY _              ' __in const SPPHRASEPROPERTY *pProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResourceValue ( _                          ' VTable offset = 20
     BYREF pszResourceName AS WSTRINGZ _                ' __in LPCWSTR pszResourceName
   , BYREF ppCoMemResource AS DWORD _                   ' __out LPWSTR *ppCoMemResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpCFGInterpreterSite_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpCFGInterpreter
' IID = {F3D3F926-11FC-11D3-BB97-00C04F8EE6C0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpCFGInterpreter_INTERFACE_DEFINED)
    %ISpCFGInterpreter_INTERFACE_DEFINED = 1

INTERFACE ISpCFGInterpreter $IID_ISpCFGInterpreter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitGrammar ( _                               ' VTable offset = 12
     BYREF pszGrammarName AS WSTRINGZ _                 ' __in LPCWSTR pszGrammarName
   , BYREF pvGrammarData AS DWORD _                     ' __in const void **pvGrammarData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Interpret ( _                                 ' VTable offset = 16
     BYVAL pPhrase AS ISpPhraseBuilder _                ' __in ISpPhraseBuilder *pPhrase
   , BYVAL ulFirstElement AS DWORD _                    ' __in const ULONG ulFirstElement
   , BYVAL ulCountOfElements AS DWORD _                 ' __in const ULONG ulCountOfElements
   , BYVAL pSite AS ISpCFGInterpreterSite _             ' __in ISpCFGInterpreterSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpCFGInterpreter_INTERFACE_DEFINED__ */

' enum SPCFGNOTIFY
%SPCFGN_ADD        = 0
%SPCFGN_REMOVE     = %SPCFGN_ADD        + 1
%SPCFGN_INVALIDATE = %SPCFGN_REMOVE     + 1
%SPCFGN_ACTIVATE   = %SPCFGN_INVALIDATE + 1
%SPCFGN_DEACTIVATE = %SPCFGN_ACTIVATE   + 1

' enum SPRESULTTYPE
%SPRT_CFG               = 0
%SPRT_SLM               = 1
%SPRT_PROPRIETARY       = 2
%SPRT_FALSE_RECOGNITION = 5    ' ( 1L << 2 )
%SPRT_TYPE_MASK         = 3
%SPRT_EMULATED          = 8    ' ( 1L << 3 )
%SPRT_EXTENDABLE_PARSE  = 16   ' ( 1L << 4 )

' // Size = 24 bytes
TYPE SPPHRASEALT DWORD
   pPhrase                AS DWORD PTR   ' ISpPhraseBuilder *
   ulStartElementInParent AS DWORD       ' ULONG
   cElementsInParent      AS DWORD       ' ULONG
   cElementsInAlternate   AS DWORD       ' ULONG
   pvAltExtra             AS DWORD       ' void *
   cbAltExtra             AS DWORD       ' ULONG
END TYPE

' // Size = 56 bytes
TYPE SPRECORESULTINFO QWORD FILL
   cbSize                AS DWORD             ' ULONG
   eResultType           AS LONG              ' SPRESULTTYPE
   fHypothesis           AS LONG              ' BOOL
   fProprietaryAutoPause AS LONG              ' BOOL
   ullStreamPosStart     AS QUAD              ' ULONGLONG
   ullStreamPosEnd       AS QUAD              ' ULONGLONG
   hGrammar              AS DWORD             ' SPGRAMMARHANDLE
   ulSizeEngineData      AS DWORD             ' ULONG
   pvEngineData          AS DWORD             ' void *
   pPhrase               AS DWORD PTR         ' ISpPhraseBuilder *
   aPhraseAlts           AS SPPHRASEALT PTR   ' SPPHRASEALT *
   ulNumAlts             AS DWORD             ' ULONG
END TYPE

' // Size = 72 bytes
TYPE SPRECORESULTINFOEX QWORD FILL
   SPRECORESULTINFO
   ullStreamTimeStart AS QUAD   ' ULONGLONG
   ullStreamTimeEnd   AS QUAD   ' ULONGLONG
END TYPE

' enum SPWORDINFOOPT
%SPWIO_NONE      = 0
%SPWIO_WANT_TEXT = 1

' enum SPRULEINFOOPT
%SPRIO_NONE = 0

' // Size = 56 bytes
TYPE SPPARSEINFO DWORD
   cbSize                    AS DWORD             ' ULONG
   hRule                     AS DWORD             ' SPRULEHANDLE
   ullAudioStreamPosition    AS QUAD              ' ULONGLONG
   ulAudioSize               AS DWORD             ' ULONG
   cTransitions              AS DWORD             ' ULONG
   pPath                     AS SPPATHENTRY PTR   ' SPPATHENTRY *
   SREngineID                AS GUID              ' GUID
   ulSREnginePrivateDataSize AS DWORD             ' ULONG
   pSREnginePrivateData      AS BYTE PTR          ' const BYTE *
   fHypothesis               AS LONG              ' BOOL
END TYPE

' ########################################################################################
' Interface name = ISpSREngineSite
' IID = {3B414AEC-720C-4883-B9EF-178CD394FB3A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpSREngineSite_INTERFACE_DEFINED)
    %ISpSREngineSite_INTERFACE_DEFINED = 1

INTERFACE ISpSREngineSite $IID_ISpSREngineSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __in void *pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DataAvailable ( _                             ' VTable offset = 16
      BYREF pcb AS DWORD _                              ' __out ULONG *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferNotifySize ( _                       ' VTable offset = 20
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseFromTransitions ( _                      ' VTable offset = 24
     BYREF pParseInfo AS SPPARSEINFO _                  ' __in const SPPARSEINFO *pParseInfo
   , BYREF ppNewPhrase AS ISpPhraseBuilder _            ' __out ISpPhraseBuilder **ppNewPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Recognition ( _                               ' VTable offset = 28
     BYREF pResultInfo AS SPRECORESULTINFO _            ' __in const SPRECORESULTINFO *pResultInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEvent ( _                                  ' VTable offset = 32
     BYREF pEvent AS SPEVENT _                          ' __in const SPEVENT *pEvent
   , BYVAL hSAPIRecoContext AS DWORD _                  ' __in SPRECOCONTEXTHANDLE hSAPIRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Synchronize ( _                               ' VTable offset = 36
     BYVAL ullProcessedThruPos AS QUAD _                ' __in ULONGLONG ullProcessedThruPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWordInfo ( _                               ' VTable offset = 40
     BYREF pWordEntry AS SPWORDENTRY _                  ' __inout SPWORDENTRY *pWordEntry
   , BYVAL Options AS LONG _                            ' __in SPWORDINFOOPT Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordClientContext ( _                      ' VTable offset = 44
     BYVAL hWord AS DWORD _                             ' __in SPWORDHANDLE hWord
   , BYVAL pvClientContext AS DWORD _                   ' __in void *pvClientContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRuleInfo ( _                               ' VTable offset = 48
     BYREF pRuleEntry AS SPRULEENTRY _                  ' __inout SPRULEENTRY *pRuleEntry
   , BYVAL Options AS LONG _                            ' __in SPRULEINFOOPT Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleClientContext ( _                      ' VTable offset = 52
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL pvClientContext AS DWORD _                   ' __in void *pvClientContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStateInfo ( _                              ' VTable offset = 56
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   , BYREF pStateInfo AS SPSTATEINFO _                  ' __out SPSTATEINFO *pStateInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 60
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYREF pszResourceName AS WSTRINGZ _                ' __in LPCWSTR pszResourceName
   , BYREF ppCoMemResource AS DWORD _                   ' __out LPWSTR *ppCoMemResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransitionProperty ( _                     ' VTable offset = 64
     BYVAL ID AS LONG _                                 ' __in SPTRANSITIONID ID
   , BYREF ppCoMemProperty AS SPTRANSITIONPROPERTY _    ' __out SPTRANSITIONPROPERTY **ppCoMemProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAlternate ( _                               ' VTable offset = 68
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL hAltRule AS DWORD _                          ' __in SPRULEHANDLE hAltRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxAlternates ( _                          ' VTable offset = 72
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYREF pulNumAlts AS DWORD _                        ' __out ULONG *pulNumAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextMaxAlternates ( _                   ' VTable offset = 76
     BYVAL hContext AS DWORD _                          ' __in SPRECOCONTEXTHANDLE hContext
   , BYREF pulNumAlts AS DWORD _                        ' __out ULONG *pulNumAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateRecoPos ( _                             ' VTable offset = 80
     BYVAL ullCurrentRecoPos AS QUAD _                  ' __in ULONGLONG ullCurrentRecoPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSREngineSite_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpSREngineSite2
' IID = {7BC6E012-684A-493E-BDD4-2BF5FBF48CFE}
' Inherited interface = ISpSREngineSite
' ########################################################################################

#IF NOT %DEF(%ISpSREngineSite2_INTERFACE_DEFINED)
    %ISpSREngineSite2_INTERFACE_DEFINED = 1

INTERFACE ISpSREngineSite2 $IID_ISpSREngineSite2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpSREngineSite methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __in void *pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DataAvailable ( _                             ' VTable offset = 16
      BYREF pcb AS DWORD _                              ' __out ULONG *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBufferNotifySize ( _                       ' VTable offset = 20
     BYVAL cbSize AS DWORD _                            ' __in ULONG cbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseFromTransitions ( _                      ' VTable offset = 24
     BYREF pParseInfo AS SPPARSEINFO _                  ' __in const SPPARSEINFO *pParseInfo
   , BYREF ppNewPhrase AS ISpPhraseBuilder _            ' __out ISpPhraseBuilder **ppNewPhrase
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Recognition ( _                               ' VTable offset = 28
     BYREF pResultInfo AS SPRECORESULTINFO _            ' __in const SPRECORESULTINFO *pResultInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEvent ( _                                  ' VTable offset = 32
     BYREF pEvent AS SPEVENT _                          ' __in const SPEVENT *pEvent
   , BYVAL hSAPIRecoContext AS DWORD _                  ' __in SPRECOCONTEXTHANDLE hSAPIRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Synchronize ( _                               ' VTable offset = 36
     BYVAL ullProcessedThruPos AS QUAD _                ' __in ULONGLONG ullProcessedThruPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWordInfo ( _                               ' VTable offset = 40
     BYREF pWordEntry AS SPWORDENTRY _                  ' __inout SPWORDENTRY *pWordEntry
   , BYVAL Options AS LONG _                            ' __in SPWORDINFOOPT Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordClientContext ( _                      ' VTable offset = 44
     BYVAL hWord AS DWORD _                             ' __in SPWORDHANDLE hWord
   , BYVAL pvClientContext AS DWORD _                   ' __in void *pvClientContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRuleInfo ( _                               ' VTable offset = 48
     BYREF pRuleEntry AS SPRULEENTRY _                  ' __inout SPRULEENTRY *pRuleEntry
   , BYVAL Options AS LONG _                            ' __in SPRULEINFOOPT Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleClientContext ( _                      ' VTable offset = 52
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL pvClientContext AS DWORD _                   ' __in void *pvClientContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStateInfo ( _                              ' VTable offset = 56
     BYVAL hState AS DWORD _                            ' __in SPSTATEHANDLE hState
   , BYREF pStateInfo AS SPSTATEINFO _                  ' __out SPSTATEINFO *pStateInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResource ( _                               ' VTable offset = 60
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYREF pszResourceName AS WSTRINGZ _                ' __in LPCWSTR pszResourceName
   , BYREF ppCoMemResource AS DWORD _                   ' __out LPWSTR *ppCoMemResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransitionProperty ( _                     ' VTable offset = 64
     BYVAL ID AS LONG _                                 ' __in SPTRANSITIONID ID
   , BYREF ppCoMemProperty AS SPTRANSITIONPROPERTY _    ' __out SPTRANSITIONPROPERTY **ppCoMemProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAlternate ( _                               ' VTable offset = 68
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL hAltRule AS DWORD _                          ' __in SPRULEHANDLE hAltRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxAlternates ( _                          ' VTable offset = 72
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYREF pulNumAlts AS DWORD _                        ' __out ULONG *pulNumAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContextMaxAlternates ( _                   ' VTable offset = 76
     BYVAL hContext AS DWORD _                          ' __in SPRECOCONTEXTHANDLE hContext
   , BYREF pulNumAlts AS DWORD _                        ' __out ULONG *pulNumAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateRecoPos ( _                             ' VTable offset = 80
     BYVAL ullCurrentRecoPos AS QUAD _                  ' __in ULONGLONG ullCurrentRecoPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpSREngineSite2 methods
   ' =====================================================================================
   METHOD AddEventEx ( _                                ' VTable offset = 84
     BYREF pEvent AS SPEVENTEX _                        ' __in const SPEVENTEX *pEvent
   , BYVAL hSAPIRecoContext AS DWORD _                  ' __in SPRECOCONTEXTHANDLE hSAPIRecoContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateRecoPosEx ( _                           ' VTable offset = 88
     BYVAL ullCurrentRecoPos AS QUAD _                  ' __in ULONGLONG ullCurrentRecoPos
   , BYVAL ullCurrentRecoTime AS QUAD _                 ' __in ULONGLONG ullCurrentRecoTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRuleTransition ( _                         ' VTable offset = 92
     BYVAL ulGrammarID AS DWORD _                       ' __in ULONG ulGrammarID
   , BYVAL RuleIndex AS DWORD _                         ' __in ULONG RuleIndex
   , BYREF pTrans AS SPTRANSITIONENTRY _                ' __out SPTRANSITIONENTRY *pTrans
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecognitionEx ( _                             ' VTable offset = 96
     BYREF pResultInfo AS SPRECORESULTINFOEX _          ' __in const SPRECORESULTINFOEX *pResultInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSREngineSite2_INTERFACE_DEFINED__ */

' enum SPPROPSRC
%SPPROPSRC_RECO_INST    = 0
%SPPROPSRC_RECO_CTX     = %SPPROPSRC_RECO_INST + 1
%SPPROPSRC_RECO_GRAMMAR = %SPPROPSRC_RECO_CTX + 1

' ########################################################################################
' Interface name = ISpSREngine
' IID = {2F472991-854B-4465-B613-FBAFB3AD8ED8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpSREngine_INTERFACE_DEFINED)
    %ISpSREngine_INTERFACE_DEFINED = 1

INTERFACE ISpSREngine $IID_ISpSREngine

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSite ( _                                   ' VTable offset = 12
     BYVAL pSite AS ISpSREngineSite _                   ' __in ISpSREngineSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputAudioFormat ( _                       ' VTable offset = 16
     BYREF pguidSourceFormatId AS GUID _                ' __in const GUID *pguidSourceFormatId
   , BYREF pSourceWaveFormatEx AS WAVEFORMATEX _        ' __in const WAVEFORMATEX *pSourceWaveFormatEx
   , BYREF pguidDesiredFormatId AS GUID _               ' __out GUID *pguidDesiredFormatId
   , BYREF ppCoMemDesiredWaveFormatEx AS WAVEFORMATEX _ ' __out WAVEFORMATEX **ppCoMemDesiredWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecognizeStream ( _                           ' VTable offset = 20
     BYREF rguidFmtId AS GUID _                         ' __in REFGUID rguidFmtId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   , BYVAL hRequestSync AS DWORD _                      ' __in HANDLE hRequestSync
   , BYVAL hDataAvailable AS DWORD _                    ' __in HANDLE hDataAvailable
   , BYVAL hExit AS DWORD _                             ' __in HANDLE hExit
   , BYVAL fNewAudioStream AS LONG _                    ' __in BOOL fNewAudioStream
   , BYVAL fRealTimeAudio AS LONG _                     ' __in BOOL fRealTimeAudio
   , BYVAL pAudioObjectToken AS ISpObjectToken _        ' __in ISpObjectToken *pAudioObjectToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecoProfile ( _                            ' VTable offset = 24
     BYVAL pProfile AS ISpObjectToken _                 ' __in ISpObjectToken *pProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateGrammar ( _                           ' VTable offset = 28
     BYVAL pvEngineRecoContext AS DWORD _               ' __in void *pvEngineRecoContext
   , BYVAL hSAPIGrammar AS DWORD _                      ' __in SPGRAMMARHANDLE hSAPIGrammar
   , BYREF ppvEngineGrammarContext AS DWORD _           ' __out void **ppvEngineGrammarContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteGrammar ( _                           ' VTable offset = 32
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadProprietaryGrammar ( _                    ' VTable offset = 36
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF rguidParam AS GUID _                         ' __in REFGUID rguidParam
   , BYREF pszStringParam AS WSTRINGZ _                 ' __in LPCWSTR pszStringParam
   , BYVAL pvDataParam AS DWORD _                       ' __in const void *pvDataParam
   , BYVAL ulDataSize AS DWORD _                        ' __in ULONG ulDataSize
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadProprietaryGrammar ( _                  ' VTable offset = 40
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProprietaryRuleState ( _                   ' VTable offset = 44
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL pReserved AS DWORD _                         ' __in void *pReserved
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   , BYREF pcRulesChanged AS DWORD _                    ' __out ULONG *pcRulesChanged
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProprietaryRuleIdState ( _                 ' VTable offset = 48
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL dwRuleId AS DWORD _                          ' __in DWORD dwRuleId
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadSLM ( _                                   ' VTable offset = 52
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszTopicName AS WSTRINGZ _                   ' __in LPCWSTR pszTopicName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadSLM ( _                                 ' VTable offset = 56
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSLMState ( _                               ' VTable offset = 60
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordSequenceData ( _                       ' VTable offset = 64
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pText AS WSTRINGZ _                          ' __in const WCHAR *pText
   , BYVAL cchText AS DWORD _                           ' __in ULONG cchText
   , BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextSelection ( _                          ' VTable offset = 68
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPronounceable ( _                           ' VTable offset = 72
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszWord AS WSTRINGZ _                        ' __in LPCWSTR pszWord
   , BYREF pWordPronounceable AS LONG _                 ' __out SPWORDPRONOUNCEABLE *pWordPronounceable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateRecoContext ( _                       ' VTable offset = 76
     BYVAL hSAPIRecoContext AS DWORD _                  ' __in SPRECOCONTEXTHANDLE hSAPIRecoContext
   , BYREF ppvEngineContext AS DWORD _                  ' __out void **ppvEngineContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteRecoContext ( _                       ' VTable offset = 80
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateCall ( _                               ' VTable offset = 84
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL pCallFrame AS DWORD _                        ' __inout PVOID pCallFrame
   , BYVAL ulCallFrameSize AS DWORD _                   ' __in ULONG ulCallFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdaptationData ( _                         ' VTable offset = 88
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYREF pAdaptationData AS WSTRINGZ _                ' __in WCHAR *pAdaptationData
   , BYVAL cch AS DWORD _                               ' __in const ULONG cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyNum ( _                            ' VTable offset = 92
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYVAL lValue AS LONG _                             ' __in LONG lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyNum ( _                            ' VTable offset = 96
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF lValue AS LONG _                             ' __out LONG *lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyString ( _                         ' VTable offset = 100
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   , BYREF pValue AS WSTRINGZ _                         ' __in LPCWSTR pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyString ( _                         ' VTable offset = 104
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName,
   , BYREF ppCoMemValue AS DWORD _                      ' __out LPWSTR *ppCoMemValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGrammarState ( _                           ' VTable offset = 108
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL eGrammarState AS LONG _                      ' __in SPGRAMMARSTATE eGrammarState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WordNotify ( _                                ' VTable offset = 112
     BYVAL Action AS LONG _                             ' __in SPCFGNOTIFY Action
   , BYVAL cWords AS DWORD _                            ' __in ULONG cWords
   , BYREF pWords AS SPWORDENTRY _                      ' __in const SPWORDENTRY *pWords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RuleNotify ( _                                ' VTable offset = 116
     BYVAL Action AS LONG _                             ' __in SPCFGNOTIFY Action
   , BYVAL cRules AS DWORD _                            ' __in ULONG cRules
   , BYREF pRules AS SPRULEENTRY _                      ' __in const SPRULEENTRY *pRules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateCallEx ( _                             ' VTable offset = 120
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL pInCallFrame AS DWORD _                      ' __in const void *pInCallFrame
   , BYVAL ulInCallFrameSize AS DWORD _                 ' __in ULONG ulInCallFrameSize
   , BYREF ppvCoMemResponse AS DWORD _                  ' __out void **ppvCoMemResponse
   , BYREF pulResponseSize AS DWORD _                   ' __out ULONG *pulResponseSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContextState ( _                           ' VTable offset = 124
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL eContextState AS LONG _                      ' __in SPCONTEXTSTATE eContextState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSREngine_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpSREngine2
' IID = {7BA627D8-33F9-4375-90C5-9985AEE5EDE5}
' Inherited interface = ISpSREngine
' ########################################################################################

#IF NOT %DEF(%ISpSREngine2_INTERFACE_DEFINED)
    %ISpSREngine2_INTERFACE_DEFINED = 1

INTERFACE ISpSREngine2 $IID_ISpSREngine2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpSREngine methods
   ' =====================================================================================
   METHOD SetSite ( _                                   ' VTable offset = 12
     BYVAL pSite AS ISpSREngineSite _                   ' __in ISpSREngineSite *pSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputAudioFormat ( _                       ' VTable offset = 16
     BYREF pguidSourceFormatId AS GUID _                ' __in const GUID *pguidSourceFormatId
   , BYREF pSourceWaveFormatEx AS WAVEFORMATEX _        ' __in const WAVEFORMATEX *pSourceWaveFormatEx
   , BYREF pguidDesiredFormatId AS GUID _               ' __out GUID *pguidDesiredFormatId
   , BYREF ppCoMemDesiredWaveFormatEx AS WAVEFORMATEX _ ' __out WAVEFORMATEX **ppCoMemDesiredWaveFormatEx
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecognizeStream ( _                           ' VTable offset = 20
     BYREF rguidFmtId AS GUID _                         ' __in REFGUID rguidFmtId
   , BYREF pWaveFormatEx AS WAVEFORMATEX _              ' __in const WAVEFORMATEX *pWaveFormatEx
   , BYVAL hRequestSync AS DWORD _                      ' __in HANDLE hRequestSync
   , BYVAL hDataAvailable AS DWORD _                    ' __in HANDLE hDataAvailable
   , BYVAL hExit AS DWORD _                             ' __in HANDLE hExit
   , BYVAL fNewAudioStream AS LONG _                    ' __in BOOL fNewAudioStream
   , BYVAL fRealTimeAudio AS LONG _                     ' __in BOOL fRealTimeAudio
   , BYVAL pAudioObjectToken AS ISpObjectToken _        ' __in ISpObjectToken *pAudioObjectToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRecoProfile ( _                            ' VTable offset = 24
     BYVAL pProfile AS ISpObjectToken _                 ' __in ISpObjectToken *pProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateGrammar ( _                           ' VTable offset = 28
     BYVAL pvEngineRecoContext AS DWORD _               ' __in void *pvEngineRecoContext
   , BYVAL hSAPIGrammar AS DWORD _                      ' __in SPGRAMMARHANDLE hSAPIGrammar
   , BYREF ppvEngineGrammarContext AS DWORD _           ' __out void **ppvEngineGrammarContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteGrammar ( _                           ' VTable offset = 32
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadProprietaryGrammar ( _                    ' VTable offset = 36
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF rguidParam AS GUID _                         ' __in REFGUID rguidParam
   , BYREF pszStringParam AS WSTRINGZ _                 ' __in LPCWSTR pszStringParam
   , BYVAL pvDataParam AS DWORD _                       ' __in const void *pvDataParam
   , BYVAL ulDataSize AS DWORD _                        ' __in ULONG ulDataSize
   , BYVAL Options AS LONG _                            ' __in SPLOADOPTIONS Options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadProprietaryGrammar ( _                  ' VTable offset = 40
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProprietaryRuleState ( _                   ' VTable offset = 44
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL pReserved AS DWORD _                         ' __in void *pReserved
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   , BYREF pcRulesChanged AS DWORD _                    ' __out ULONG *pcRulesChanged
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProprietaryRuleIdState ( _                 ' VTable offset = 48
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL dwRuleId AS DWORD _                          ' __in DWORD dwRuleId
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadSLM ( _                                   ' VTable offset = 52
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszTopicName AS WSTRINGZ _                   ' __in LPCWSTR pszTopicName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnloadSLM ( _                                 ' VTable offset = 56
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSLMState ( _                               ' VTable offset = 60
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL NewState AS LONG _                           ' __in SPRULESTATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWordSequenceData ( _                       ' VTable offset = 64
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pText AS WSTRINGZ _                          ' __in const WCHAR *pText
   , BYVAL cchText AS DWORD _                           ' __in ULONG cchText
   , BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextSelection ( _                          ' VTable offset = 68
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pInfo AS SPTEXTSELECTIONINFO _               ' __in const SPTEXTSELECTIONINFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPronounceable ( _                           ' VTable offset = 72
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszWord AS WSTRINGZ _                        ' __in LPCWSTR pszWord
   , BYREF pWordPronounceable AS LONG _                 ' __out SPWORDPRONOUNCEABLE *pWordPronounceable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCreateRecoContext ( _                       ' VTable offset = 76
     BYVAL hSAPIRecoContext AS DWORD _                  ' __in SPRECOCONTEXTHANDLE hSAPIRecoContext
   , BYREF ppvEngineContext AS DWORD _                  ' __out void **ppvEngineContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeleteRecoContext ( _                       ' VTable offset = 80
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateCall ( _                               ' VTable offset = 84
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL pCallFrame AS DWORD _                        ' __inout PVOID pCallFrame
   , BYVAL ulCallFrameSize AS DWORD _                   ' __in ULONG ulCallFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdaptationData ( _                         ' VTable offset = 88
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYREF pAdaptationData AS WSTRINGZ _                ' __in WCHAR *pAdaptationData
   , BYVAL cch AS DWORD _                               ' __in const ULONG cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyNum ( _                            ' VTable offset = 92
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYVAL lValue AS LONG _                             ' __in LONG lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyNum ( _                            ' VTable offset = 96
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in const WCHAR *pName
   , BYREF lValue AS LONG _                             ' __out LONG *lValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyString ( _                         ' VTable offset = 100
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   , BYREF pValue AS WSTRINGZ _                         ' __in LPCWSTR pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyString ( _                         ' VTable offset = 104
     BYVAL eSrc AS LONG _                               ' __in SPPROPSRC eSrc
   , BYVAL pvSrcObj AS DWORD _                          ' __in void *pvSrcObj
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName,
   , BYREF ppCoMemValue AS DWORD _                      ' __out LPWSTR *ppCoMemValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGrammarState ( _                           ' VTable offset = 108
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL eGrammarState AS LONG _                      ' __in SPGRAMMARSTATE eGrammarState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WordNotify ( _                                ' VTable offset = 112
     BYVAL Action AS LONG _                             ' __in SPCFGNOTIFY Action
   , BYVAL cWords AS DWORD _                            ' __in ULONG cWords
   , BYREF pWords AS SPWORDENTRY _                      ' __in const SPWORDENTRY *pWords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RuleNotify ( _                                ' VTable offset = 116
     BYVAL Action AS LONG _                             ' __in SPCFGNOTIFY Action
   , BYVAL cRules AS DWORD _                            ' __in ULONG cRules
   , BYREF pRules AS SPRULEENTRY _                      ' __in const SPRULEENTRY *pRules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrivateCallEx ( _                             ' VTable offset = 120
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL pInCallFrame AS DWORD _                      ' __in const void *pInCallFrame
   , BYVAL ulInCallFrameSize AS DWORD _                 ' __in ULONG ulInCallFrameSize
   , BYREF ppvCoMemResponse AS DWORD _                  ' __out void **ppvCoMemResponse
   , BYREF pulResponseSize AS DWORD _                   ' __out ULONG *pulResponseSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContextState ( _                           ' VTable offset = 124
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL eContextState AS LONG _                      ' __in SPCONTEXTSTATE eContextState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpSREngine2 methods
   ' =====================================================================================
   METHOD PrivateCallImmediate ( _                      ' VTable offset = 128
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYVAL pInCallFrame AS DWORD _                      ' __in const void *pInCallFrame
   , BYVAL v AS DWORD _                                 ' __in ULONG ulInCallFrameSize
   , BYREF ppvCoMemResponse AS DWORD _                  ' __out void **ppvCoMemResponse
   , BYREF pulResponseSize AS DWORD _                   ' __out ULONG *pulResponseSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdaptationData2 ( _                        ' VTable offset = 132
     BYVAL pvEngineContext AS DWORD _                   ' __in void *pvEngineContext
   , BYREF pAdaptationData AS WSTRINGZ _                ' __in const WCHAR *pAdaptationData
   , BYVAL cch AS DWORD _                               ' __in const ULONG cch
   , BYREF pTopicName AS WSTRINGZ _                     ' __in LPCWSTR pTopicName
   , BYVAL eSettings AS LONG _                          ' __in SPADAPTATIONSETTINGS eSettings
   , BYVAL eRelevance AS LONG _                         ' __in SPADAPTATIONRELEVANCE eRelevance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGrammarPrefix ( _                          ' VTable offset = 136
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pszPrefix AS WSTRINGZ _                      ' __in_opt LPCWSTR pszPrefix
   , BYVAL fIsPrefixRequired AS LONG _                  ' __in BOOL fIsPrefixRequired
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRulePriority ( _                           ' VTable offset = 140
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL pvClientRuleContext AS DWORD _               ' __in void *pvClientRuleContext
   , BYVAL nRulePriority AS LONG _                      ' __in int nRulePriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EmulateRecognition ( _                        ' VTable offset = 144
     BYVAL pPhrase AS ISpPhrase _                       ' __in ISpPhrase *pPhrase
   , BYVAL dwCompareFlags AS DWORD _                    ' __in DWORD dwCompareFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSLMWeight ( _                              ' VTable offset = 148
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL flWeight AS SINGLE _                         ' __in float flWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRuleWeight ( _                             ' VTable offset = 152
     BYVAL hRule AS DWORD _                             ' __in SPRULEHANDLE hRule
   , BYVAL pvClientRuleContext AS DWORD _               ' __in void *pvClientRuleContext
   , BYVAL flWeight AS SINGLE _                         ' __in float flWeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTrainingState ( _                          ' VTable offset = 156
     BYVAL fDoingTraining AS LONG _                     ' __in BOOL fDoingTraining
   , BYVAL fAdaptFromTrainingData AS LONG _             ' __in BOOL fAdaptFromTrainingData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetAcousticModelAdaptation ( _              ' VTable offset = 160
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLoadCFG ( _                                 ' VTable offset = 164
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYREF pGrammarData AS SPBINARYGRAMMAR _            ' __in const SPBINARYGRAMMAR *pGrammarData
   , BYVAL ulGrammarID AS DWORD _                       ' __in ULONG ulGrammarID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUnloadCFG ( _                               ' VTable offset = 168
     BYVAL pvEngineGrammar AS DWORD _                   ' __in void *pvEngineGrammar
   , BYVAL ulGrammarID AS DWORD _                       ' __in ULONG ulGrammarID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSREngine2_INTERFACE_DEFINED__ */

' // Size = 28 bytes
TYPE SPPHRASEALTREQUEST DWORD
   ulStartElement    AS DWORD       ' ULONG
   cElements         AS DWORD       ' ULONG
   ulRequestAltCount AS DWORD       ' ULONG
   pvResultExtra     AS DWORD       ' void *
   cbResultExtra     AS DWORD       ' ULONG
   pPhrase           AS DWORD PTR   ' ISpPhrase *
   pRecoContext      AS DWORD PTR   ' ISpRecoContext *
END TYPE

' ########################################################################################
' Interface name = ISpSRAlternates
' IID = {FECE8294-2BE1-408F-8E68-2DE377092F0E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpSRAlternates_INTERFACE_DEFINED)
    %ISpSRAlternates_INTERFACE_DEFINED = 1

INTERFACE ISpSRAlternates $IID_ISpSRAlternates

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 12
     BYREF pAltRequest AS SPPHRASEALTREQUEST _          ' __in SPPHRASEALTREQUEST *pAltRequest
   , BYREF ppAlts AS SPPHRASEALT _                      ' __out SPPHRASEALT **ppAlts
   , BYREF pcAlts AS DWORD _                            ' __out ULONG *pcAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
     BYREF pAltRequest AS SPPHRASEALTREQUEST _          ' __in SPPHRASEALTREQUEST *pAltRequest
   , BYREF pAlt AS SPPHRASEALT _                        ' __in SPPHRASEALT *pAlt
   , BYREF ppvResultExtra AS DWORD _                    ' __out void **ppvResultExtra
   , BYREF pcbResultExtra AS DWORD _                    ' __out ULONG *pcbResultExtra
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSRAlternates_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISpSRAlternates2
' IID = {F338F437-CB33-4020-9CAB-C71FF9CE12D3}
' Inherited interface = ISpSRAlternates
' ########################################################################################

#IF NOT %DEF(%ISpSRAlternates2_INTERFACE_DEFINED)
    %ISpSRAlternates2_INTERFACE_DEFINED = 1

INTERFACE ISpSRAlternates2 $IID_ISpSRAlternates2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISpSRAlternates methods
   ' =====================================================================================
   METHOD GetAlternates ( _                             ' VTable offset = 12
     BYREF pAltRequest AS SPPHRASEALTREQUEST _          ' __in SPPHRASEALTREQUEST *pAltRequest
   , BYREF ppAlts AS SPPHRASEALT _                      ' __out SPPHRASEALT **ppAlts
   , BYREF pcAlts AS DWORD _                            ' __out ULONG *pcAlts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 16
     BYREF pAltRequest AS SPPHRASEALTREQUEST _          ' __in SPPHRASEALTREQUEST *pAltRequest
   , BYREF pAlt AS SPPHRASEALT _                        ' __in SPPHRASEALT *pAlt
   , BYREF ppvResultExtra AS DWORD _                    ' __out void **ppvResultExtra
   , BYREF pcbResultExtra AS DWORD _                    ' __out ULONG *pcbResultExtra
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISpSRAlternates2 methods
   ' =====================================================================================
   METHOD CommitText ( _                                ' VTable offset = 20
     BYREF pAltRequest AS SPPHRASEALTREQUEST _          ' __in SPPHRASEALTREQUEST *pAltRequest
   , BYREF pcszNewText AS WSTRINGZ _                    ' __in_opt LPCWSTR pcszNewText
   , BYVAL commitFlags AS LONG _                        ' __in SPCOMMITFLAGS commitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISpSRAlternates2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _ISpPrivateEngineCall
' IID = {8E7C791E-4467-11D3-9723-00C04F72DB08}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpPrivateEngineCall_INTERFACE_DEFINED)
    %ISpPrivateEngineCall_INTERFACE_DEFINED = 1

INTERFACE ISpPrivateEngineCall $IID__ISpPrivateEngineCall

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallEngine ( _                                ' VTable offset = 12
     BYVAL pCallFrame AS DWORD _                        ' __inout_void *pCallFrame
   , BYVAL ulCallFrameSize AS DWORD _                   ' __in ULONG ulCallFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CallEngineEx ( _                              ' VTable offset = 16
     BYVAL pInFrame AS DWORD _                          ' __in const void *pInFrame
   , BYVAL ulInFrameSize AS DWORD _                     ' __in ULONG ulInFrameSize
   , BYREF ppCoMemOutFrame AS DWORD _                   ' __out void **ppCoMemOutFrame
   , BYREF pulOutFrameSize AS DWORD _                   ' __out ULONG *pulOutFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___ISpPrivateEngineCall_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = _ISpPrivateEngineCallEx
' IID = {DEFD682A-FE0A-42B9-BFA1-56D3D6CECFAF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISpPrivateEngineCallEx_INTERFACE_DEFINED)
    %ISpPrivateEngineCallEx_INTERFACE_DEFINED = 1

INTERFACE ISpPrivateEngineCallEx $IID__ISpPrivateEngineCallEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallEngineSynchronize ( _                     ' VTable offset = 12
     BYVAL pInFrame AS DWORD _                          ' __in const void *pInFrame
   , BYVAL ulInFrameSize AS DWORD _                     ' __in ULONG ulInFrameSize
   , BYREF ppCoMemOutFrame AS DWORD _                   ' __out void **ppCoMemOutFrame
   , BYREF pulOutFrameSize AS DWORD _                   ' __out ULONG *pulOutFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CallEngineImmediate ( _                       ' VTable offset = 16
     BYVAL pInFrame AS DWORD _                          ' __in const void *pInFrame
   , BYVAL ulInFrameSize AS DWORD _                     ' __in ULONG ulInFrameSize
   , BYREF ppCoMemOutFrame AS DWORD _                   ' __out void **ppCoMemOutFrame
   , BYREF pulOutFrameSize AS DWORD _                   ' __out ULONG *pulOutFrameSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* ___ISpPrivateEngineCallEx_INTERFACE_DEFINED__ */

'#include "sapiddk51.h"
