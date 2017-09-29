' ########################################################################################
' Microsoft Windows
' File: OpenService.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: IEOpenServiceObjects
' Version: 0.0, Locale ID = 0
' Library GUID: {41A67FBC-3179-4FDF-9E9A-1B62B908BFEC}
' ########################################################################################

#INCLUDE THIS ONCE
%OPENSERVICE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "mshtml.inc"
#INCLUDE ONCE "exdisp.inc"

$LIBID_IEOpenServiceObjects = GUID$("{41a67fbc-3179-4fdf-9e9a-1b62b908bfec}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_OpenServiceActivityManager = GUID$("{C5EFD803-50F8-43CD-9AB8-AAFC1394C9E0}")
$CLSID_OpenServiceManager = GUID$("{098870B6-39EA-480B-B8B5-DD0167C4DB59}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IEnumOpenServiceActivity = GUID$("{A436D7D2-17C3-4EF4-A1E8-5C86FAFF26C0}")
$IID_IEnumOpenServiceActivityCategory = GUID$("{33627A56-8C9A-4430-8FD1-B5F5C771AFB6}")
$IID_IOpenService = GUID$("{C2952ED1-6A89-4606-925F-1ED8B4BE0630}")
$IID_IOpenServiceActivity = GUID$("{13645C88-221A-4905-8ED1-4F5112CFC108}")
$IID_IOpenServiceActivityCategory = GUID$("{850AF9D6-7309-40B5-BDB8-786C106B2153}")
$IID_IOpenServiceActivityInput = GUID$("{75CB4DB9-6DA0-4DA3-83CE-422B6A433346}")
$IID_IOpenServiceActivityManager = GUID$("{8A2D0A9D-E920-4BDC-A291-D30F650BC4F1}")
$IID_IOpenServiceActivityOutputContext = GUID$("{E289DEAB-F709-49A9-B99E-282364074571}")
$IID_IOpenServiceManager = GUID$("{5664125F-4E10-4E90-98E4-E4513D955A14}")

' enum OpenServiceErrors
%OS_E_NOTFOUND     = &H80030002&
%OS_E_NOTSUPPORTED = &H80004021&
%OS_E_CANCELLED    = &H80002ef1&
%OS_E_GPDISABLED   = &Hc00d0bdc&

' enum OpenServiceActivityContentType
%ActivityContentNone      = -1
%ActivityContentDocument  = %ActivityContentNone      + 1
%ActivityContentSelection = %ActivityContentDocument  + 1
%ActivityContentLink      = %ActivityContentSelection + 1
%ActivityContentCount     = %ActivityContentLink      + 1

' ########################################################################################
' IOpenServiceActivityInput interface
' IID = 75cb4db9-6da0-4da3-83ce-422b6a433346
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenServiceActivityInput_INTERFACE_DEFINED)
    %IOpenServiceActivityInput_INTERFACE_DEFINED = 1

INTERFACE IOpenServiceActivityInput $IID_IOpenServiceActivityInput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVariable ( _                               ' VTable offset = 12
     BYREF pwzVariableName AS WSTRINGZ _                ' __in LPCWSTR pwzVariableName
   , BYREF pwzVariableType AS WSTRINGZ _                ' __in LPCWSTR pwzVariableType
   , BYREF pbstrVariableContent AS WSTRING _            ' __out BSTR *pbstrVariableContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasVariable ( _                               ' VTable offset = 16
     BYREF pwzVariableName AS WSTRINGZ _                ' __in LPCWSTR pwzVariableName
   , BYREF pwzVariableType AS WSTRINGZ _                ' __in LPCWSTR pwzVariableType
   , BYREF pfHasVariable AS LONG _                      ' __out BOOL *pfHasVariable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 20
     BYREF pType AS LONG _                              ' __out OpenServiceActivityContentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceActivityInput_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenServiceActivityOutputContext interface
' IID = e289deab-f709-49a9-b99e-282364074571
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenServiceActivityOutputContext_INTERFACE_DEFINED)
    %IOpenServiceActivityOutputContext_INTERFACE_DEFINED = 1

INTERFACE IOpenServiceActivityOutputContext $IID_IOpenServiceActivityOutputContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Navigate ( _                                  ' VTable offset = 12
     BYREF pwzUri AS WSTRINGZ _                         ' __in LPCWSTR pwzUri
   , BYREF pwzMethod AS WSTRINGZ _                      ' __in LPCWSTR pwzMethod
   , BYREF pwzHeaders AS WSTRINGZ _                     ' __in LPCWSTR pwzHeaders
   , BYVAL pPostData AS IStream _                       ' __in IStream *pPostData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanNavigate ( _                               ' VTable offset = 16
     BYREF pwzUri AS WSTRINGZ _                         ' __in LPCWSTR pwzUri
   , BYREF pwzMethod AS WSTRINGZ _                      ' __in LPCWSTR pwzMethod
   , BYREF pwzHeaders AS WSTRINGZ _                     ' __in LPCWSTR pwzHeaders
   , BYVAL pPostData AS IStream _                       ' __in IStream *pPostData
   , BYREF pfCanNavigate AS LONG _                      ' __out BOOL *pfCanNavigate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceActivityOutputContext_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenService interface
' IID = C2952ED1-6A89-4606-925F-1ED8B4BE0630
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenService_INTERFACE_DEFINED)
    %IOpenService_INTERFACE_DEFINED = 1

INTERFACE IOpenService $IID_IOpenService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsDefault ( _                                 ' VTable offset = 12
     BYREF pfIsDefault AS LONG _                        ' __out BOOL *pfIsDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefault ( _                                ' VTable offset = 16
     BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 20
     BYREF pbstrID AS WSTRING _                         ' __out BSTR *pbstrID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenService_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenServiceManager interface
' IID = 5664125f-4e10-4e90-98e4-e4513d955a14
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenServiceManager_INTERFACE_DEFINED)
    %IOpenServiceManager_INTERFACE_DEFINED = 1

INTERFACE IOpenServiceManager $IID_IOpenServiceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InstallService ( _                            ' VTable offset = 12
     BYREF pwzServiceUrl AS WSTRINGZ _                  ' __in LPCWSTR pwzServiceUrl
   , BYREF ppService AS IOpenService _                  ' __out IOpenService **ppService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UninstallService ( _                          ' VTable offset = 16
     BYVAL pService AS IOpenService _                   ' __in IOpenService *pService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceByID ( _                            ' VTable offset = 20
     BYREF pwzID AS WSTRINGZ _                          ' __in LPCWSTR pwzID
   , BYREF ppService AS IOpenService _                  ' __out IOpenService **ppService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceManager_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenServiceActivity interface
' IID = 13645c88-221a-4905-8ed1-4f5112cfc108
' Inherited interface = IOpenService
' ########################################################################################

#IF NOT %DEF(%IOpenServiceActivity_INTERFACE_DEFINED)
    %IOpenServiceActivity_INTERFACE_DEFINED = 1


INTERFACE IOpenServiceActivity $IID_IOpenServiceActivity

   INHERIT IUnknown

   ' =====================================================================================
   ' IOpenService methods
   ' =====================================================================================
   METHOD IsDefault ( _                                 ' VTable offset = 12
     BYREF pfIsDefault AS LONG _                        ' __out BOOL *pfIsDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefault ( _                                ' VTable offset = 16
     BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetID ( _                                     ' VTable offset = 20
     BYREF pbstrID AS WSTRING _                         ' __out BSTR *pbstrID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOpenService methods
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 24
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYVAL pOutput AS IOpenServiceActivityOutputContext _ ' __in IOpenServiceActivityOutputContext *pOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanExecute ( _                                ' VTable offset = 28
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYVAL pOutput AS IOpenServiceActivityOutputContext _ ' __in IOpenServiceActivityOutputContext *pOutput
   , BYREF pfCanExecute AS LONG _                       ' __out BOOL *pfCanExecute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanExecuteType ( _                            ' VTable offset = 32
     BYVAL type AS LONG _                               ' __in OpenServiceActivityContentType type
   , BYREF pfCanExecute AS LONG _                       ' __out BOOL *pfCanExecute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Preview ( _                                   ' VTable offset = 36
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYVAL pOutput AS IOpenServiceActivityOutputContext _ ' __in IOpenServiceActivityOutputContext *pOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanPreview ( _                                ' VTable offset = 40
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYVAL pOutput AS IOpenServiceActivityOutputContext _ ' __in IOpenServiceActivityOutputContext *pOutput
   , BYREF pfCanPreview AS LONG _                       ' __out BOOL *pfCanPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanPreviewType ( _                            ' VTable offset = 44
     BYVAL type AS LONG _                               ' __in OpenServiceActivityContentType type
   , BYREF pfCanPreview AS LONG _                       ' __out BOOL *pfCanPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatusText ( _                             ' VTable offset = 48
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYREF pbstrStatusText AS WSTRING _                 ' __out BSTR *pbstrStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHomepageUrl ( _                            ' VTable offset = 52
     BYREF pbstrHomepageUrl AS WSTRING _                ' __out BSTR *pbstrHomepageUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 56
     BYREF pbstrDisplayName AS WSTRING _                ' __out BSTR *pbstrDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 60
     BYREF pbstrDescription AS WSTRING _                ' __out BSTR *pbstrDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryName ( _                           ' VTable offset = 64
     BYREF pbstrCategoryName AS WSTRING _               ' __out BSTR *pbstrCategoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconPath ( _                               ' VTable offset = 68
     BYREF pbstrIconPath AS WSTRING _                   ' __out BSTR *pbstrIconPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 72
     BYVAL fSmallIcon AS LONG _                         ' __in BOOL fSmallIcon
   , BYREF phIcon AS DWORD _                            ' __out HICON *phIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionFilePath ( _                    ' VTable offset = 76
     BYREF pbstrXmlPath AS WSTRING _                    ' __out BSTR *pbstrXmlPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDownloadUrl ( _                            ' VTable offset = 80
     BYREF pbstrXmlUri AS WSTRING _                     ' __out BSTR *pbstrXmlUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInstallUrl ( _                             ' VTable offset = 84
     BYREF pbstrInstallUri AS WSTRING _                 ' __out BSTR *pbstrInstallUri
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEnabled ( _                                 ' VTable offset = 88
     BYREF pfIsEnabled AS LONG _                        ' __out BOOL *pfIsEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnabled ( _                                ' VTable offset = 92
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceActivity_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumOpenServiceActivity interface
' IID = a436d7d2-17c3-4ef4-a1e8-5c86faff26c0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumOpenServiceActivity_INTERFACE_DEFINED)
    %IEnumOpenServiceActivity_INTERFACE_DEFINED = 1

'typedef IOpenServiceActivity *EnumActivityType;

INTERFACE IEnumOpenServiceActivity $IID_IEnumOpenServiceActivity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IOpenServiceActivity _              ' __out EnumActivityType *rgelt
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
   METHOD Clone  ( _                                    ' VTable offset = 24
     BYREF ppenum AS IEnumOpenServiceActivity _         ' __out IEnumOpenServiceActivity **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumOpenServiceActivity_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenServiceActivityCategory interface
' IID = 850AF9D6-7309-40b5-BDB8-786C106B2153
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenServiceActivityCategory_INTERFACE_DEFINED)
    %IOpenServiceActivityCategory_INTERFACE_DEFINED = 1

INTERFACE IOpenServiceActivityCategory $IID_IOpenServiceActivityCategory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HasDefaultActivity ( _                        ' VTable offset = 12
     BYVAL pfHasDefaultActivity AS LONG _               ' __out BOOL *pfHasDefaultActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultActivity ( _                        ' VTable offset = 16
     BYREF ppDefaultActivity AS IOpenServiceActivity _  ' __out IOpenServiceActivity **ppDefaultActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultActivity ( _                        ' VTable offset = 20
     BYVAL pActivity AS IOpenServiceActivity _          ' __in_opt IOpenServiceActivity *pActivity
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 24
     BYREF pbstrName AS WSTRING _                       ' __out BSTR *pbstrName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityEnumerator ( _                     ' VTable offset = 28
     BYVAL pInput AS IOpenServiceActivityInput _        ' __in IOpenServiceActivityInput *pInput
   , BYVAL pOutput AS IOpenServiceActivityOutputContext _ ' __in IOpenServiceActivityOutputContext *pOutput
   , BYREF ppEnumActivity AS IEnumOpenServiceActivity _ ' __out IEnumOpenServiceActivity **ppEnumActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceActivityCategory_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumOpenServiceActivityCategory interface
' IID = 33627a56-8c9a-4430-8fd1-b5f5c771afb6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumOpenServiceActivityCategory_INTERFACE_DEFINED)
    %IEnumOpenServiceActivityCategory_INTERFACE_DEFINED = 1

'typedef IOpenServiceActivityCategory *EnumActivityVerbType;

INTERFACE IEnumOpenServiceActivityCategory $IID_IEnumOpenServiceActivityCategory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IOpenServiceActivityCategory _      ' __out EnumActivityVerbType *rgelt
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
     BYREF ppenum AS IEnumOpenServiceActivityCategory _ ' __out IEnumOpenServiceActivityCategory **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumOpenServiceActivityCategory_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpenServiceActivityManager interface
' IID = 8a2d0a9d-e920-4bdc-a291-d30f650bc4f1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenServiceActivityManager_INTERFACE_DEFINED)
    %IOpenServiceActivityManager_INTERFACE_DEFINED = 1

INTERFACE IOpenServiceActivityManager $IID_IOpenServiceActivityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCategoryEnumerator ( _                     ' VTable offset = 12
     BYVAL eType AS LONG _                              ' __in OpenServiceActivityContentType eType
   , BYREF ppEnum AS IEnumOpenServiceActivityCategory _ ' __out IEnumOpenServiceActivityCategory **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityByID ( _                           ' VTable offset = 16
     BYREF pwzActivityID AS WSTRINGZ _                  ' __in LPCWSTR pwzActivityID
   , BYREF ppActivity AS IOpenServiceActivity _         ' __out IOpenServiceActivity **ppActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActivityByHomepageAndCategory ( _          ' VTable offset = 20
     BYREF pwzHomepage AS WSTRINGZ _                    ' __in LPCWSTR pwzHomepage
   , BYREF pwzCategory AS WSTRINGZ _                    ' __in LPCWSTR pwzCategory
   , BYREF ppActivity AS IOpenServiceActivity _         ' __out IOpenServiceActivity **ppActivity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersionCookie ( _                          ' VTable offset = 24
     BYREF pdwVersionCookie AS DWORD _                  ' __out DWORD *pdwVersionCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenServiceActivityManager_INTERFACE_DEFINED__ */
