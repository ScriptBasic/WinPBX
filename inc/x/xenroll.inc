' ########################################################################################
' Microsoft Windows
' File: xenroll.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: XENROLLLib
' Version: 1.0
' Documentation string: xenroll 1.0 Type Library
' Path: C:\WINDOWS\system32\xenroll.dll
' Library GUID: {5B9169C0-DB65-42AA-A38A-0726846AAEB3}
' ########################################################################################

#INCLUDE THIS ONCE
%XENROLL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "wincrypt.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {127698E4-E730-4E5C-A2B1-21490A70C8A1}
$PROGID_CEnroll1 = "CEnroll.CEnroll.1"
' CLSID = {127698E4-E730-4E5C-A2B1-21490A70C8A1}
$PROGID_CEnroll2 = "CEnroll.CEnroll.2"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {43F8F289-7A20-11D0-8F06-00C04FC295E1}
$PROGID_CEnroll = "CEnroll.CEnroll"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CEnroll  = GUID$("{43F8F289-7A20-11D0-8F06-00C04FC295E1}")
$CLSID_CEnroll2 = GUID$("{127698E4-E730-4E5C-A2B1-21490A70C8A1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICEnroll   = GUID$("{43F8F288-7A20-11D0-8F06-00C04FC295E1}")
$IID_ICEnroll2  = GUID$("{704CA730-C90B-11D1-9BEC-00C04FC295E1}")
$IID_ICEnroll3  = GUID$("{C28C2D95-B7DE-11D2-A421-00C04F79FE8E}")
$IID_ICEnroll4  = GUID$("{C1F1188A-2EB5-4A80-841B-7E729A356D90}")

$IID_IEnroll    = GUID$("{ACAA7838-4585-11D1-AB57-00C04FC295E1}")
$IID_IEnroll2   = GUID$("{C080E199-B7DF-11D2-A421-00C04F79FE8E}")
$IID_IEnroll4   = GUID$("{F8053FE5-78F4-448F-A0DB-41D61B73446B}")


' ########################################################################################
' Interface name = ICEnroll
' IID = {43F8F288-7A20-11D0-8F06-00C04FC295E1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICEnroll_INTERFACE_DEFINED)
    %ICEnroll_INTERFACE_DEFINED = 1

INTERFACE ICEnroll $IID_ICEnroll

   INHERIT IDispatch

   ' =====================================================================================
   METHOD createFilePKCS10 <1610743808> ( _             ' VTable offset = 28
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   , BYVAL wszPKCS10FileName AS WSTRING _               ' __in BSTR wszPKCS10FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptFilePKCS7 <1610743809> ( _              ' VTable offset = 32
     BYVAL wszPKCS7FileName AS WSTRING _                ' __in BSTR wszPKCS7FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD createPKCS10 <1610743810> ( _                 ' VTable offset = 36
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   ) AS WSTRING                                         ' __retval_out BSTR *pPKCS10
   ' =====================================================================================
   METHOD acceptPKCS7 <1610743811> ( _                  ' VTable offset = 40
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD getCertFromPKCS7 <1610743812> ( _             ' VTable offset = 44
     BYVAL wszPKCS7 AS WSTRING _                        ' __in BSTR wszPKCS7
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCert
   ' =====================================================================================
   METHOD enumProviders <1610743813> ( _                ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvName
   ' =====================================================================================
   METHOD enumContainers <1610743814> ( _               ' VTable offset = 52
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD freeRequestInfo <1610743815> ( _              ' VTable offset = 56
     BYVAL PKCS7OrPKCS10 AS WSTRING _                   ' __in BSTR PKCS7OrPKCS10
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreName <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET MyStoreName <1610743816> ( _            ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreType <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET MyStoreType <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreFlags <1610743820> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET MyStoreFlags <1610743820> ( _           ' VTable offset = 80
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreName <1610743822> ( _            ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET CAStoreName <1610743822> ( _            ' VTable offset = 88
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreType <1610743824> ( _            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET CAStoreType <1610743824> ( _            ' VTable offset = 96
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreFlags <1610743826> ( _           ' VTable offset = 100
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET CAStoreFlags <1610743826> ( _           ' VTable offset = 104
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreName <1610743828> ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RootStoreName <1610743828> ( _          ' VTable offset = 112
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreType <1610743830> ( _          ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RootStoreType <1610743830> ( _          ' VTable offset = 120
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreFlags <1610743832> ( _         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RootStoreFlags <1610743832> ( _         ' VTable offset = 128
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreName <1610743834> ( _       ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RequestStoreName <1610743834> ( _       ' VTable offset = 136
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreType <1610743836> ( _       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RequestStoreType <1610743836> ( _       ' VTable offset = 144
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreFlags <1610743838> ( _      ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RequestStoreFlags <1610743838> ( _      ' VTable offset = 152
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerName <1610743840> ( _          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContainer
   ' =====================================================================================
   PROPERTY SET ContainerName <1610743840> ( _          ' VTable offset = 160
     BYVAL bstrContainer AS WSTRING _                   ' __in BSTR bstrContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderName <1610743842> ( _           ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvider
   ' =====================================================================================
   PROPERTY SET ProviderName <1610743842> ( _           ' VTable offset = 168
     BYVAL bstrProvider AS WSTRING _                    ' __in BSTR bstrProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderType <1610743844> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out LONG *pdwType
   ' =====================================================================================
   PROPERTY SET ProviderType <1610743844> ( _           ' VTable offset = 176
     BYVAL dwType AS LONG _                             ' __in LONG dwType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743846> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out LONG *pdw
   ' =====================================================================================
   PROPERTY SET KeySpec <1610743846> ( _                ' VTable offset = 184
     BYVAL dw AS LONG _                                 ' __in LONG dw
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderFlags <1610743848> ( _          ' VTable offset = 188
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET ProviderFlags <1610743848> ( _          ' VTable offset = 192
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseExistingKeySet <1610743850> ( _      ' VTable offset = 196
   ) AS LONG                                            ' __retval_out BOOL *fUseExistingKeys
   ' =====================================================================================
   PROPERTY SET UseExistingKeySet <1610743850> ( _      ' VTable offset = 200
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenKeyFlags <1610743852> ( _            ' VTable offset = 204
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET GenKeyFlags <1610743852> ( _            ' VTable offset = 208
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteRequestCert <1610743854> ( _      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out BOOL *fDelete
   ' =====================================================================================
   PROPERTY SET DeleteRequestCert <1610743854> ( _      ' VTable offset = 216
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToCSP <1610743856> ( _         ' VTable offset = 220
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToCSP <1610743856> ( _         ' VTable offset = 224
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SPCFileName <1610743858> ( _            ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET SPCFileName <1610743858> ( _            ' VTable offset = 232
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PVKFileName <1610743860> ( _            ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET PVKFileName <1610743860> ( _            ' VTable offset = 240
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743862> ( _          ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743862> ( _          ' VTable offset = 248
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICEnroll_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICEnroll2
' IID = {704CA730-C90B-11D1-9BEC-00C04FC295E1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICEnroll
' ########################################################################################

#IF NOT %DEF(%ICEnroll2_INTERFACE_DEFINED)
    %ICEnroll2_INTERFACE_DEFINED = 1

INTERFACE ICEnroll2 $IID_ICEnroll2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICEnroll Methods
   ' =====================================================================================
   METHOD createFilePKCS10 <1610743808> ( _             ' VTable offset = 28
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   , BYVAL wszPKCS10FileName AS WSTRING _               ' __in BSTR wszPKCS10FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptFilePKCS7 <1610743809> ( _              ' VTable offset = 32
     BYVAL wszPKCS7FileName AS WSTRING _                ' __in BSTR wszPKCS7FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD createPKCS10 <1610743810> ( _                 ' VTable offset = 36
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   ) AS WSTRING                                         ' __retval_out BSTR *pPKCS10
   ' =====================================================================================
   METHOD acceptPKCS7 <1610743811> ( _                  ' VTable offset = 40
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD getCertFromPKCS7 <1610743812> ( _             ' VTable offset = 44
     BYVAL wszPKCS7 AS WSTRING _                        ' __in BSTR wszPKCS7
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCert
   ' =====================================================================================
   METHOD enumProviders <1610743813> ( _                ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvName
   ' =====================================================================================
   METHOD enumContainers <1610743814> ( _               ' VTable offset = 52
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD freeRequestInfo <1610743815> ( _              ' VTable offset = 56
     BYVAL PKCS7OrPKCS10 AS WSTRING _                   ' __in BSTR PKCS7OrPKCS10
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreName <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET MyStoreName <1610743816> ( _            ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreType <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET MyStoreType <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreFlags <1610743820> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET MyStoreFlags <1610743820> ( _           ' VTable offset = 80
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreName <1610743822> ( _            ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET CAStoreName <1610743822> ( _            ' VTable offset = 88
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreType <1610743824> ( _            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET CAStoreType <1610743824> ( _            ' VTable offset = 96
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreFlags <1610743826> ( _           ' VTable offset = 100
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET CAStoreFlags <1610743826> ( _           ' VTable offset = 104
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreName <1610743828> ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RootStoreName <1610743828> ( _          ' VTable offset = 112
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreType <1610743830> ( _          ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RootStoreType <1610743830> ( _          ' VTable offset = 120
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreFlags <1610743832> ( _         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RootStoreFlags <1610743832> ( _         ' VTable offset = 128
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreName <1610743834> ( _       ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RequestStoreName <1610743834> ( _       ' VTable offset = 136
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreType <1610743836> ( _       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RequestStoreType <1610743836> ( _       ' VTable offset = 144
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreFlags <1610743838> ( _      ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RequestStoreFlags <1610743838> ( _      ' VTable offset = 152
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerName <1610743840> ( _          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContainer
   ' =====================================================================================
   PROPERTY SET ContainerName <1610743840> ( _          ' VTable offset = 160
     BYVAL bstrContainer AS WSTRING _                   ' __in BSTR bstrContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderName <1610743842> ( _           ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvider
   ' =====================================================================================
   PROPERTY SET ProviderName <1610743842> ( _           ' VTable offset = 168
     BYVAL bstrProvider AS WSTRING _                    ' __in BSTR bstrProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderType <1610743844> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out LONG *pdwType
   ' =====================================================================================
   PROPERTY SET ProviderType <1610743844> ( _           ' VTable offset = 176
     BYVAL dwType AS LONG _                             ' __in LONG dwType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743846> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out LONG *pdw
   ' =====================================================================================
   PROPERTY SET KeySpec <1610743846> ( _                ' VTable offset = 184
     BYVAL dw AS LONG _                                 ' __in LONG dw
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderFlags <1610743848> ( _          ' VTable offset = 188
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET ProviderFlags <1610743848> ( _          ' VTable offset = 192
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseExistingKeySet <1610743850> ( _      ' VTable offset = 196
   ) AS LONG                                            ' __retval_out BOOL *fUseExistingKeys
   ' =====================================================================================
   PROPERTY SET UseExistingKeySet <1610743850> ( _      ' VTable offset = 200
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenKeyFlags <1610743852> ( _            ' VTable offset = 204
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET GenKeyFlags <1610743852> ( _            ' VTable offset = 208
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteRequestCert <1610743854> ( _      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out BOOL *fDelete
   ' =====================================================================================
   PROPERTY SET DeleteRequestCert <1610743854> ( _      ' VTable offset = 216
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToCSP <1610743856> ( _         ' VTable offset = 220
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToCSP <1610743856> ( _         ' VTable offset = 224
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SPCFileName <1610743858> ( _            ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET SPCFileName <1610743858> ( _            ' VTable offset = 232
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PVKFileName <1610743860> ( _            ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET PVKFileName <1610743860> ( _            ' VTable offset = 240
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743862> ( _          ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743862> ( _          ' VTable offset = 248
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll2 Methods
   ' =====================================================================================
   METHOD addCertTypeToRequest <1610809344> ( _         ' VTable offset = 252
     BYVAL CertType AS WSTRING _                        ' __in BSTR CertType
   )                                                    ' void
   ' =====================================================================================
   METHOD addNameValuePairToSignature <1610809345> ( _  ' VTable offset = 256
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 260
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 264
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 268
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 272
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICEnroll2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICEnroll3
' IID = {C28C2D95-B7DE-11D2-A421-00C04F79FE8E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICEnroll2
' ########################################################################################

#IF NOT %DEF(%ICEnroll3_INTERFACE_DEFINED)
    %ICEnroll3_INTERFACE_DEFINED = 1

INTERFACE ICEnroll3 $IID_ICEnroll3

   INHERIT IDispatch

   ' =====================================================================================
   ' ICEnroll Methods
   ' =====================================================================================
   METHOD createFilePKCS10 <1610743808> ( _             ' VTable offset = 28
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   , BYVAL wszPKCS10FileName AS WSTRING _               ' __in BSTR wszPKCS10FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptFilePKCS7 <1610743809> ( _              ' VTable offset = 32
     BYVAL wszPKCS7FileName AS WSTRING _                ' __in BSTR wszPKCS7FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD createPKCS10 <1610743810> ( _                 ' VTable offset = 36
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   ) AS WSTRING                                         ' __retval_out BSTR *pPKCS10
   ' =====================================================================================
   METHOD acceptPKCS7 <1610743811> ( _                  ' VTable offset = 40
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD getCertFromPKCS7 <1610743812> ( _             ' VTable offset = 44
     BYVAL wszPKCS7 AS WSTRING _                        ' __in BSTR wszPKCS7
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCert
   ' =====================================================================================
   METHOD enumProviders <1610743813> ( _                ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvName
   ' =====================================================================================
   METHOD enumContainers <1610743814> ( _               ' VTable offset = 52
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD freeRequestInfo <1610743815> ( _              ' VTable offset = 56
     BYVAL PKCS7OrPKCS10 AS WSTRING _                   ' __in BSTR PKCS7OrPKCS10
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreName <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET MyStoreName <1610743816> ( _            ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreType <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET MyStoreType <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreFlags <1610743820> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET MyStoreFlags <1610743820> ( _           ' VTable offset = 80
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreName <1610743822> ( _            ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET CAStoreName <1610743822> ( _            ' VTable offset = 88
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreType <1610743824> ( _            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET CAStoreType <1610743824> ( _            ' VTable offset = 96
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreFlags <1610743826> ( _           ' VTable offset = 100
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET CAStoreFlags <1610743826> ( _           ' VTable offset = 104
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreName <1610743828> ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RootStoreName <1610743828> ( _          ' VTable offset = 112
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreType <1610743830> ( _          ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RootStoreType <1610743830> ( _          ' VTable offset = 120
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreFlags <1610743832> ( _         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RootStoreFlags <1610743832> ( _         ' VTable offset = 128
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreName <1610743834> ( _       ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RequestStoreName <1610743834> ( _       ' VTable offset = 136
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreType <1610743836> ( _       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RequestStoreType <1610743836> ( _       ' VTable offset = 144
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreFlags <1610743838> ( _      ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RequestStoreFlags <1610743838> ( _      ' VTable offset = 152
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerName <1610743840> ( _          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContainer
   ' =====================================================================================
   PROPERTY SET ContainerName <1610743840> ( _          ' VTable offset = 160
     BYVAL bstrContainer AS WSTRING _                   ' __in BSTR bstrContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderName <1610743842> ( _           ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvider
   ' =====================================================================================
   PROPERTY SET ProviderName <1610743842> ( _           ' VTable offset = 168
     BYVAL bstrProvider AS WSTRING _                    ' __in BSTR bstrProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderType <1610743844> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out LONG *pdwType
   ' =====================================================================================
   PROPERTY SET ProviderType <1610743844> ( _           ' VTable offset = 176
     BYVAL dwType AS LONG _                             ' __in LONG dwType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743846> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out LONG *pdw
   ' =====================================================================================
   PROPERTY SET KeySpec <1610743846> ( _                ' VTable offset = 184
     BYVAL dw AS LONG _                                 ' __in LONG dw
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderFlags <1610743848> ( _          ' VTable offset = 188
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET ProviderFlags <1610743848> ( _          ' VTable offset = 192
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseExistingKeySet <1610743850> ( _      ' VTable offset = 196
   ) AS LONG                                            ' __retval_out BOOL *fUseExistingKeys
   ' =====================================================================================
   PROPERTY SET UseExistingKeySet <1610743850> ( _      ' VTable offset = 200
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenKeyFlags <1610743852> ( _            ' VTable offset = 204
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET GenKeyFlags <1610743852> ( _            ' VTable offset = 208
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteRequestCert <1610743854> ( _      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out BOOL *fDelete
   ' =====================================================================================
   PROPERTY SET DeleteRequestCert <1610743854> ( _      ' VTable offset = 216
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToCSP <1610743856> ( _         ' VTable offset = 220
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToCSP <1610743856> ( _         ' VTable offset = 224
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SPCFileName <1610743858> ( _            ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET SPCFileName <1610743858> ( _            ' VTable offset = 232
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PVKFileName <1610743860> ( _            ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET PVKFileName <1610743860> ( _            ' VTable offset = 240
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743862> ( _          ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743862> ( _          ' VTable offset = 248
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll2 Methods
   ' =====================================================================================
   METHOD addCertTypeToRequest <1610809344> ( _         ' VTable offset = 252
     BYVAL CertType AS WSTRING _                        ' __in BSTR CertType
   )                                                    ' void
   ' =====================================================================================
   METHOD addNameValuePairToSignature <1610809345> ( _  ' VTable offset = 256
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 260
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 264
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 268
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 272
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll3 Methods
   ' =====================================================================================
   METHOD InstallPKCS7 <1610874880> ( _                 ' VTable offset = 276
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610874881> ( _                        ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSupportedKeySpec <1610874882> ( _          ' VTable offset = 284
   ) AS LONG                                            ' __retval_out LONG *pdwKeySpec
   ' =====================================================================================
   METHOD GetKeyLen <1610874883> ( _                    ' VTable offset = 288
     BYVAL fMin AS LONG _                               ' __in BOOL fMin
   , BYVAL fExchange AS LONG _                          ' __in BOOL fExchange
   ) AS LONG                                            ' __retval_out LONG *pdwKeySize
   ' =====================================================================================
   METHOD EnumAlgs <1610874884> ( _                     ' VTable offset = 292
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL algClass AS LONG _                           ' __in LONG algClass
   ) AS LONG                                            ' __retval_out LONG *pdwAlgID
   ' =====================================================================================
   METHOD GetAlgName <1610874885> ( _                   ' VTable offset = 296
     BYVAL algID AS LONG _                              ' __in LONG algID
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET ReuseHardwareKeyIfUnableToGenNew <1610874886> ( _ ' VTable offset = 300
     BYVAL fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __in BOOL fReuseHardwareKeyIfUnableToGenNew
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReuseHardwareKeyIfUnableToGenNew <1610874886> ( _ ' VTable offset = 304
   ) AS LONG                                            ' __retval_out BOOL *fReuseHardwareKeyIfUnableToGenNew
   ' =====================================================================================
   PROPERTY SET HashAlgID <1610874888> ( _              ' VTable offset = 308
     BYVAL hashAlgID AS LONG _                          ' __in LONG hashAlgID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgID <1610874888> ( _              ' VTable offset = 312
   ) AS LONG                                            ' __retval_out LONG *hashAlgID
   ' =====================================================================================
   PROPERTY SET LimitExchangeKeyToEncipherment <1610874890> ( _ ' VTable offset = 316
     BYVAL fLimitExchangeKeyToEncipherment AS LONG _    ' __in BOOL fLimitExchangeKeyToEncipherment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LimitExchangeKeyToEncipherment <1610874890> ( _ ' VTable offset = 320
   ) AS LONG                                            ' __retval_out BOOL *fLimitExchangeKeyToEncipherment
   ' =====================================================================================
   PROPERTY SET EnableSMIMECapabilities <1610874892> ( _ ' VTable offset = 324
     BYVAL fEnableSMIMECapabilities AS LONG _           ' __in BOOL fEnableSMIMECapabilities
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableSMIMECapabilities <1610874892> ( _ ' VTable offset = 328
   ) AS LONG                                            ' __retval_out BOOL *fEnableSMIMECapabilities
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICEnroll3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICEnroll4
' IID = {C1F1188A-2EB5-4A80-841B-7E729A356D90}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICEnroll3
' ########################################################################################

#IF NOT %DEF(%ICEnroll4_INTERFACE_DEFINED)
    %ICEnroll4_INTERFACE_DEFINED = 1

INTERFACE ICEnroll4 $IID_ICEnroll4

   INHERIT IDispatch

   ' =====================================================================================
   ' ICEnroll Methods
   ' =====================================================================================
   METHOD createFilePKCS10 <1610743808> ( _             ' VTable offset = 28
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   , BYVAL wszPKCS10FileName AS WSTRING _               ' __in BSTR wszPKCS10FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptFilePKCS7 <1610743809> ( _              ' VTable offset = 32
     BYVAL wszPKCS7FileName AS WSTRING _                ' __in BSTR wszPKCS7FileName
   )                                                    ' void
   ' =====================================================================================
   METHOD createPKCS10 <1610743810> ( _                 ' VTable offset = 36
     BYVAL DNName AS WSTRING _                          ' __in BSTR DNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   ) AS WSTRING                                         ' __retval_out BSTR *pPKCS10
   ' =====================================================================================
   METHOD acceptPKCS7 <1610743811> ( _                  ' VTable offset = 40
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD getCertFromPKCS7 <1610743812> ( _             ' VTable offset = 44
     BYVAL wszPKCS7 AS WSTRING _                        ' __in BSTR wszPKCS7
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCert
   ' =====================================================================================
   METHOD enumProviders <1610743813> ( _                ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvName
   ' =====================================================================================
   METHOD enumContainers <1610743814> ( _               ' VTable offset = 52
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD freeRequestInfo <1610743815> ( _              ' VTable offset = 56
     BYVAL PKCS7OrPKCS10 AS WSTRING _                   ' __in BSTR PKCS7OrPKCS10
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreName <1610743816> ( _            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET MyStoreName <1610743816> ( _            ' VTable offset = 64
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreType <1610743818> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET MyStoreType <1610743818> ( _            ' VTable offset = 72
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MyStoreFlags <1610743820> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET MyStoreFlags <1610743820> ( _           ' VTable offset = 80
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreName <1610743822> ( _            ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET CAStoreName <1610743822> ( _            ' VTable offset = 88
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreType <1610743824> ( _            ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET CAStoreType <1610743824> ( _            ' VTable offset = 96
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CAStoreFlags <1610743826> ( _           ' VTable offset = 100
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET CAStoreFlags <1610743826> ( _           ' VTable offset = 104
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreName <1610743828> ( _          ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RootStoreName <1610743828> ( _          ' VTable offset = 112
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreType <1610743830> ( _          ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RootStoreType <1610743830> ( _          ' VTable offset = 120
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RootStoreFlags <1610743832> ( _         ' VTable offset = 124
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RootStoreFlags <1610743832> ( _         ' VTable offset = 128
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreName <1610743834> ( _       ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrName
   ' =====================================================================================
   PROPERTY SET RequestStoreName <1610743834> ( _       ' VTable offset = 136
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreType <1610743836> ( _       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrType
   ' =====================================================================================
   PROPERTY SET RequestStoreType <1610743836> ( _       ' VTable offset = 144
     BYVAL bstrType AS WSTRING _                        ' __in BSTR bstrType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RequestStoreFlags <1610743838> ( _      ' VTable offset = 148
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET RequestStoreFlags <1610743838> ( _      ' VTable offset = 152
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerName <1610743840> ( _          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrContainer
   ' =====================================================================================
   PROPERTY SET ContainerName <1610743840> ( _          ' VTable offset = 160
     BYVAL bstrContainer AS WSTRING _                   ' __in BSTR bstrContainer
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderName <1610743842> ( _           ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrProvider
   ' =====================================================================================
   PROPERTY SET ProviderName <1610743842> ( _           ' VTable offset = 168
     BYVAL bstrProvider AS WSTRING _                    ' __in BSTR bstrProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderType <1610743844> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out LONG *pdwType
   ' =====================================================================================
   PROPERTY SET ProviderType <1610743844> ( _           ' VTable offset = 176
     BYVAL dwType AS LONG _                             ' __in LONG dwType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KeySpec <1610743846> ( _                ' VTable offset = 180
   ) AS LONG                                            ' __retval_out LONG *pdw
   ' =====================================================================================
   PROPERTY SET KeySpec <1610743846> ( _                ' VTable offset = 184
     BYVAL dw AS LONG _                                 ' __in LONG dw
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ProviderFlags <1610743848> ( _          ' VTable offset = 188
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET ProviderFlags <1610743848> ( _          ' VTable offset = 192
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseExistingKeySet <1610743850> ( _      ' VTable offset = 196
   ) AS LONG                                            ' __retval_out BOOL *fUseExistingKeys
   ' =====================================================================================
   PROPERTY SET UseExistingKeySet <1610743850> ( _      ' VTable offset = 200
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET GenKeyFlags <1610743852> ( _            ' VTable offset = 204
   ) AS LONG                                            ' __retval_out LONG *pdwFlags
   ' =====================================================================================
   PROPERTY SET GenKeyFlags <1610743852> ( _            ' VTable offset = 208
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeleteRequestCert <1610743854> ( _      ' VTable offset = 212
   ) AS LONG                                            ' __retval_out BOOL *fDelete
   ' =====================================================================================
   PROPERTY SET DeleteRequestCert <1610743854> ( _      ' VTable offset = 216
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToCSP <1610743856> ( _         ' VTable offset = 220
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToCSP <1610743856> ( _         ' VTable offset = 224
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SPCFileName <1610743858> ( _            ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET SPCFileName <1610743858> ( _            ' VTable offset = 232
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PVKFileName <1610743860> ( _            ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET PVKFileName <1610743860> ( _            ' VTable offset = 240
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <1610743862> ( _          ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <1610743862> ( _          ' VTable offset = 248
     BYVAL bstr AS WSTRING _                            ' __in BSTR bstr
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll2 Methods
   ' =====================================================================================
   METHOD addCertTypeToRequest <1610809344> ( _         ' VTable offset = 252
     BYVAL CertType AS WSTRING _                        ' __in BSTR CertType
   )                                                    ' void
   ' =====================================================================================
   METHOD addNameValuePairToSignature <1610809345> ( _  ' VTable offset = 256
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Value AS WSTRING _                           ' __in BSTR Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 260
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET WriteCertToUserDS <1610809346> ( _      ' VTable offset = 264
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 268
   ) AS LONG                                            ' __retval_out BOOL *fBool
   ' =====================================================================================
   PROPERTY SET EnableT61DNEncoding <1610809348> ( _    ' VTable offset = 272
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll3 Methods
   ' =====================================================================================
   METHOD InstallPKCS7 <1610874880> ( _                 ' VTable offset = 276
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610874881> ( _                        ' VTable offset = 280
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSupportedKeySpec <1610874882> ( _          ' VTable offset = 284
   ) AS LONG                                            ' __retval_out LONG *pdwKeySpec
   ' =====================================================================================
   METHOD GetKeyLen <1610874883> ( _                    ' VTable offset = 288
     BYVAL fMin AS LONG _                               ' __in BOOL fMin
   , BYVAL fExchange AS LONG _                          ' __in BOOL fExchange
   ) AS LONG                                            ' __retval_out LONG *pdwKeySize
   ' =====================================================================================
   METHOD EnumAlgs <1610874884> ( _                     ' VTable offset = 292
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL algClass AS LONG _                           ' __in LONG algClass
   ) AS LONG                                            ' __retval_out LONG *pdwAlgID
   ' =====================================================================================
   METHOD GetAlgName <1610874885> ( _                   ' VTable offset = 296
     BYVAL algID AS LONG _                              ' __in LONG algID
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY SET ReuseHardwareKeyIfUnableToGenNew <1610874886> ( _ ' VTable offset = 300
     BYVAL fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __in BOOL fReuseHardwareKeyIfUnableToGenNew
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReuseHardwareKeyIfUnableToGenNew <1610874886> ( _ ' VTable offset = 304
   ) AS LONG                                            ' __retval_out BOOL *fReuseHardwareKeyIfUnableToGenNew
   ' =====================================================================================
   PROPERTY SET HashAlgID <1610874888> ( _              ' VTable offset = 308
     BYVAL hashAlgID AS LONG _                          ' __in LONG hashAlgID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgID <1610874888> ( _              ' VTable offset = 312
   ) AS LONG                                            ' __retval_out LONG *hashAlgID
   ' =====================================================================================
   PROPERTY SET LimitExchangeKeyToEncipherment <1610874890> ( _ ' VTable offset = 316
     BYVAL fLimitExchangeKeyToEncipherment AS LONG _    ' __in BOOL fLimitExchangeKeyToEncipherment
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LimitExchangeKeyToEncipherment <1610874890> ( _ ' VTable offset = 320
   ) AS LONG                                            ' __retval_out BOOL *fLimitExchangeKeyToEncipherment
   ' =====================================================================================
   PROPERTY SET EnableSMIMECapabilities <1610874892> ( _ ' VTable offset = 324
     BYVAL fEnableSMIMECapabilities AS LONG _           ' __in BOOL fEnableSMIMECapabilities
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableSMIMECapabilities <1610874892> ( _ ' VTable offset = 328
   ) AS LONG                                            ' __retval_out BOOL *fEnableSMIMECapabilities
   ' =====================================================================================

   ' =====================================================================================
   ' ICEnroll4 Methods
   ' =====================================================================================
   PROPERTY SET PrivateKeyArchiveCertificate <1610940416> ( _ ' VTable offset = 332
     BYVAL bstrCert AS WSTRING _                        ' __in BSTR bstrCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrivateKeyArchiveCertificate <1610940416> ( _ ' VTable offset = 336
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrCert
   ' =====================================================================================
   PROPERTY SET ThumbPrint <1610940418> ( _             ' VTable offset = 340
     BYVAL bstrThumbPrint AS WSTRING _                  ' __in BSTR bstrThumbPrint
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ThumbPrint <1610940418> ( _             ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrThumbPrint
   ' =====================================================================================
   METHOD binaryToString <1610940420> ( _               ' VTable offset = 348
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strBinary AS WSTRING _                       ' __in BSTR strBinary
   ) AS WSTRING                                         ' __retval_out BSTR *pstrEncoded
   ' =====================================================================================
   METHOD stringToBinary <1610940421> ( _               ' VTable offset = 352
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strEncoded AS WSTRING _                      ' __in BSTR strEncoded
   ) AS WSTRING                                         ' __retval_out BSTR *pstrBinary
   ' =====================================================================================
   METHOD addExtensionToRequest <1610940422> ( _        ' VTable offset = 356
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   METHOD addAttributeToRequest <1610940423> ( _        ' VTable offset = 360
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   METHOD addNameValuePairToRequest <1610940424> ( _    ' VTable offset = 364
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strName AS WSTRING _                         ' __in BSTR strName
   , BYVAL strValue AS WSTRING _                        ' __in BSTR strValue
   )                                                    ' void
   ' =====================================================================================
   METHOD resetExtensions <1610940425> ( _              ' VTable offset = 368
   )                                                    ' void
   ' =====================================================================================
   METHOD resetAttributes <1610940426> ( _              ' VTable offset = 372
   )                                                    ' void
   ' =====================================================================================
   METHOD createRequest <1610940427> ( _                ' VTable offset = 376
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strDNName AS WSTRING _                       ' __in BSTR strDNName
   , BYVAL Usage AS WSTRING _                           ' __in BSTR Usage
   ) AS WSTRING                                         ' __retval_out BSTR *pstrRequest
   ' =====================================================================================
   METHOD createFileRequest <1610940428> ( _            ' VTable offset = 380
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strDNName AS WSTRING _                       ' __in BSTR strDNName
   , BYVAL strUsage AS WSTRING _                        ' __in BSTR strUsage
   , BYVAL strRequestFileName AS WSTRING _              ' __in BSTR strRequestFileName
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptResponse <1610940429> ( _               ' VTable offset = 384
     BYVAL strResponse AS WSTRING _                     ' __in BSTR strResponse
   )                                                    ' void
   ' =====================================================================================
   METHOD acceptFileResponse <1610940430> ( _           ' VTable offset = 388
     BYVAL strResponseFileName AS WSTRING _             ' __in BSTR strResponseFileName
   )                                                    ' void
   ' =====================================================================================
   METHOD getCertFromResponse <1610940431> ( _          ' VTable offset = 392
     BYVAL strResponse AS WSTRING _                     ' __in BSTR strResponse
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCert
   ' =====================================================================================
   METHOD getCertFromFileResponse <1610940432> ( _      ' VTable offset = 396
     BYVAL strResponseFileName AS WSTRING _             ' __in BSTR strResponseFileName
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCert
   ' =====================================================================================
   METHOD createPFX <1610940433> ( _                    ' VTable offset = 400
     BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   ) AS WSTRING                                         ' __retval_out BSTR *pstrPFX
   ' =====================================================================================
   METHOD createFilePFX <1610940434> ( _                ' VTable offset = 404
     BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   , BYVAL strPFXFileName AS WSTRING _                  ' __in BSTR strPFXFileName
   )                                                    ' void
   ' =====================================================================================
   METHOD setPendingRequestInfo <1610940435> ( _        ' VTable offset = 408
     BYVAL lRequestID AS LONG _                         ' __in LONG lRequestID
   , BYVAL strCADNS AS WSTRING _                        ' __in BSTR strCADNS
   , BYVAL strCAName AS WSTRING _                       ' __in BSTR strCAName
   , BYVAL strFriendlyName AS WSTRING _                 ' __in BSTR strFriendlyName
   )                                                    ' void
   ' =====================================================================================
   METHOD enumPendingRequest <1610940436> ( _           ' VTable offset = 412
     BYVAL lIndex AS LONG _                             ' __in LONG lIndex
   , BYVAL lDesiredProperty AS LONG _                   ' __in LONG lDesiredProperty
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProperty
   ' =====================================================================================
   METHOD removePendingRequest <1610940437> ( _         ' VTable offset = 416
     BYVAL strThumbprint AS WSTRING _                   ' __in BSTR strThumbprint
   )                                                    ' void
   ' =====================================================================================
   METHOD GetKeyLenEx <1610940438> ( _                  ' VTable offset = 420
     BYVAL lSizeSpec AS LONG _                          ' __in LONG lSizeSpec
   , BYVAL lKeySpec AS LONG _                           ' __in LONG lKeySpec
   ) AS LONG                                            ' __retval_out LONG *pdwKeySize
   ' =====================================================================================
   METHOD InstallPKCS7Ex <1610940439> ( _               ' VTable offset = 424
     BYVAL PKCS7 AS WSTRING _                           ' __in BSTR PKCS7
   ) AS LONG                                            ' __retval_out LONG *plCertInstalled
   ' =====================================================================================
   METHOD addCertTypeToRequestEx <1610940440> ( _       ' VTable offset = 428
     BYVAL lType AS LONG _                              ' __in LONG lType
   , BYVAL bstrOIDOrName AS WSTRING _                   ' __in BSTR bstrOIDOrName
   , BYVAL lMajorVersion AS LONG _                      ' __in LONG lMajorVersion
   , BYVAL fMinorVersion AS LONG _                      ' __in BOOL fMinorVersion
   , BYVAL lMinorVersion AS LONG _                      ' __in LONG lMinorVersion
   )                                                    ' void
   ' =====================================================================================
   METHOD getProviderType <1610940441> ( _              ' VTable offset = 432
     BYVAL strProvName AS WSTRING _                     ' __in BSTR strProvName
   ) AS LONG                                            ' __retval_out LONG *plProvType
   ' =====================================================================================
   PROPERTY SET SignerCertificate <1610940442> ( _      ' VTable offset = 436
     BYVAL bstrCert AS WSTRING _                        ' __in BSTR bstrCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET ClientId <1610940443> ( _               ' VTable offset = 440
     BYVAL lClientId AS LONG _                          ' __in LONG lClientId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ClientId <1610940443> ( _               ' VTable offset = 444
   ) AS LONG                                            ' __retval_out LONG *plClientId
   ' =====================================================================================
   METHOD addBlobPropertyToCertificate <1610940445> ( _ ' VTable offset = 448
     BYVAL lPropertyId AS LONG _                        ' __in LONG lPropertyId
   , BYVAL lReserved AS LONG _                          ' __in LONG lReserved
   , BYVAL bstrProperty AS WSTRING _                    ' __in BSTR bstrProperty
   )                                                    ' void
   ' =====================================================================================
   METHOD resetBlobProperties <1610940446> ( _          ' VTable offset = 452
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET IncludeSubjectKeyID <1610940447> ( _    ' VTable offset = 456
     BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IncludeSubjectKeyID <1610940447> ( _    ' VTable offset = 460
   ) AS LONG                                            ' __retval_out BOOL *pfInclude
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICEnroll4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnroll
' IID = {ACAA7838-4585-11D1-AB57-00C04FC295E1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnroll_INTERFACE_DEFINED)
    %IEnroll_INTERFACE_DEFINED = 1

INTERFACE IEnroll $IID_IEnroll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD createFilePKCS10WStr ( _                      ' VTable offset = 12
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF wszPKCS10FileName AS WSTRINGZ _              ' __in LPCWSTR wszPKCS10FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptFilePKCS7WStr ( _                       ' VTable offset = 16
     BYREF wszPKCS7FileName AS WSTRINGZ _               ' __in LPCWSTR wszPKCS7FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createPKCS10WStr ( _                          ' VTable offset = 20
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF pPkcs10Blob AS CRYPT_DATA_BLOB _             ' __out PCRYPT_DATA_BLOB pPkcs10Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptPKCS7Blob ( _                           ' VTable offset = 24
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getCertContextFromPKCS7 ( _                   ' VTable offset = 28
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS DWORD                                           ' PCCERT_CONTEXT
   ' =====================================================================================
   METHOD getMyStore ( _                                ' VTable offset = 32
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getCAStore ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getROOTHStore ( _                             ' VTable offset = 40
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD enumProvidersWStr ( _                         ' VTable offset = 44
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   , BYREF pbstrProvName AS DWORD _                     ' __out LPWSTR *pbstrProvName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD enumContainersWStr ( _                        ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYREF pbstr AS DWORD _                             ' __out LPWSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD freeRequestInfoBlob ( _                       ' VTable offset = 52
     BYREF pkcs7OrPkcs10 AS CRYPT_DATA_BLOB _           ' __in CRYPT_DATA_BLOB pkcs7OrPkcs10
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreNameWStr ( _                       ' VTable offset = 56
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreNameWStr ( _                       ' VTable offset = 60
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreTypeWStr ( _                       ' VTable offset = 64
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreTypeWStr ( _                       ' VTable offset = 68
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreFlags ( _                          ' VTable offset = 72
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreFlags ( _                          ' VTable offset = 76
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreNameWStr ( _                       ' VTable offset = 80
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreNameWStr ( _                       ' VTable offset = 84
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreTypeWStr ( _                       ' VTable offset = 88
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreTypeWStr ( _                       ' VTable offset = 92
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreFlags ( _                          ' VTable offset = 96
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreFlags ( _                          ' VTable offset = 100
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreNameWStr ( _                     ' VTable offset = 104
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreNameWStr ( _                     ' VTable offset = 108
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreTypeWStr ( _                     ' VTable offset = 112
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreTypeWStr ( _                     ' VTable offset = 116
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreFlags ( _                        ' VTable offset = 120
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreFlags ( _                        ' VTable offset = 124
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreNameWStr ( _                  ' VTable offset = 128
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreNameWStr ( _                  ' VTable offset = 132
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreTypeWStr ( _                  ' VTable offset = 136
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreTypeWStr ( _                  ' VTable offset = 140
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreFlags ( _                     ' VTable offset = 144
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreFlags ( _                     ' VTable offset = 148
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ContainerNameWStr ( _                     ' VTable offset = 152
     BYREF szwContainer AS DWORD _                      ' __out LPWSTR *szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ContainerNameWStr ( _                     ' VTable offset = 156
     BYREF szwContainer AS WSTRINGZ _                   ' __in LPWSTR szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderNameWStr ( _                      ' VTable offset = 160
     BYREF szwProvider AS DWORD _                       ' __out LPWSTR *szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderNameWStr ( _                      ' VTable offset = 164
     BYREF szwProvider AS WSTRINGZ _                    ' __in LPWSTR szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderType ( _                          ' VTable offset = 168
     BYREF pdwType AS LONG _                            ' __out LONG *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderType ( _                          ' VTable offset = 172
     BYVAL pdwType AS LONG _                            ' __in LONG pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeySpec ( _                               ' VTable offset = 176
     BYREF pdw AS LONG _                                ' __out LONG *pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KeySpec ( _                               ' VTable offset = 180
     BYVAL pdw AS LONG _                                ' __in LONG pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderFlags ( _                         ' VTable offset = 184
     BYREF pdwFlags AS  LONG _                          ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderFlags ( _                         ' VTable offset = 188
     BYVALpdwFlags AS  LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UseExistingKeySet ( _                     ' VTable offset = 192
     BYREF fUseExistingKeys AS LONG _                   ' __out BOOL *fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_UseExistingKeySet ( _                     ' VTable offset = 196
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GenKeyFlags ( _                           ' VTable offset = 200
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_GenKeyFlags ( _                           ' VTable offset = 204
     BYVAL pdwFlags AS LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DeleteRequestCert ( _                     ' VTable offset = 208
     BYREF fDelete AS LONG _                            ' __out BOOL *fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DeleteRequestCert ( _                     ' VTable offset = 212
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToUserDS ( _                     ' VTable offset = 216
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToUserDS ( _                     ' VTable offset = 220
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnableT61DNEncoding ( _                   ' VTable offset = 224
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnableT61DNEncoding ( _                   ' VTable offset = 228
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToCSP ( _                        ' VTable offset = 232
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToCSP ( _                        ' VTable offset = 236
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SPCFileNameWStr ( _                       ' VTable offset = 240
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SPCFileNameWStr ( _                       ' VTable offset = 244
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PVKFileNameWStr ( _                       ' VTable offset = 248
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PVKFileNameWStr ( _                       ' VTable offset = 252
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HashAlgorithmWStr ( _                     ' VTable offset = 256
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HashAlgorithmWStr ( _                     ' VTable offset = 260
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RenewalCertificate ( _                    ' VTable offset = 264
     BYREF ppCertContext AS CERT_CONTEXT _              ' __out PCCERT_CONTEXT *ppCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RenewalCertificate ( _                    ' VTable offset = 268
     BYREF pCertContext AS CERT_CONTEXT _               ' __in PCCERT_CONTEXT pCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCertTypeToRequestWStr ( _                  ' VTable offset = 272
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddNameValuePairToSignatureWStr ( _           ' VTable offset = 276
     BYREF Name AS WSTRINGZ _                           ' __in LPWSTR Name
   , BYREF Value AS WSTRINGZ _                          ' __in LPWSTR Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtensionsToRequest ( _                    ' VTable offset = 280
     BYREF pCertExtensions AS CERT_EXTENSIONS _         ' __in PCERT_EXTENSIONS pCertExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddAuthenticatedAttributesToPKCS7Request ( _  ' VTable offset = 284
     BYREF pAttributes AS CRYPT_ATTRIBUTES _            ' __in PCRYPT_ATTRIBUTES pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePKCS7RequestFromRequest ( _             ' VTable offset = 288
     BYREF pRequest AS CRYPT_DATA_BLOB _                ' __in PCRYPT_DATA_BLOB pRequest
   , BYREF pSigningCertContext AS CERT_CONTEXT _        ' __in PCCERT_CONTEXT pSigningCertContext
   , BYREF pPkcs7Blob AS CRYPT_DATA_BLOB _              ' __out PCRYPT_DATA_BLOB pPkcs7Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnroll_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnroll2
' IID = {C080E199-B7DF-11D2-A421-00C04F79FE8E}
' Inherited interface = IEnroll
' ########################################################################################

#IF NOT %DEF(%IEnroll2_INTERFACE_DEFINED)
    %IEnroll2_INTERFACE_DEFINED = 1

INTERFACE IEnroll2 $IID_IEnroll2

   INHERIT IUnknown

   ' =====================================================================================
   ' IEnroll Methods
   ' =====================================================================================
   METHOD createFilePKCS10WStr ( _                      ' VTable offset = 12
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF wszPKCS10FileName AS WSTRINGZ _              ' __in LPCWSTR wszPKCS10FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptFilePKCS7WStr ( _                       ' VTable offset = 16
     BYREF wszPKCS7FileName AS WSTRINGZ _               ' __in LPCWSTR wszPKCS7FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createPKCS10WStr ( _                          ' VTable offset = 20
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF pPkcs10Blob AS CRYPT_DATA_BLOB _             ' __out PCRYPT_DATA_BLOB pPkcs10Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptPKCS7Blob ( _                           ' VTable offset = 24
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getCertContextFromPKCS7 ( _                   ' VTable offset = 28
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS DWORD                                           ' PCCERT_CONTEXT
   ' =====================================================================================
   METHOD getMyStore ( _                                ' VTable offset = 32
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getCAStore ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getROOTHStore ( _                             ' VTable offset = 40
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD enumProvidersWStr ( _                         ' VTable offset = 44
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   , BYREF pbstrProvName AS DWORD _                     ' __out LPWSTR *pbstrProvName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD enumContainersWStr ( _                        ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYREF pbstr AS DWORD _                             ' __out LPWSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD freeRequestInfoBlob ( _                       ' VTable offset = 52
     BYREF pkcs7OrPkcs10 AS CRYPT_DATA_BLOB _           ' __in CRYPT_DATA_BLOB pkcs7OrPkcs10
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreNameWStr ( _                       ' VTable offset = 56
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreNameWStr ( _                       ' VTable offset = 60
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreTypeWStr ( _                       ' VTable offset = 64
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreTypeWStr ( _                       ' VTable offset = 68
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreFlags ( _                          ' VTable offset = 72
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreFlags ( _                          ' VTable offset = 76
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreNameWStr ( _                       ' VTable offset = 80
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreNameWStr ( _                       ' VTable offset = 84
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreTypeWStr ( _                       ' VTable offset = 88
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreTypeWStr ( _                       ' VTable offset = 92
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreFlags ( _                          ' VTable offset = 96
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreFlags ( _                          ' VTable offset = 100
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreNameWStr ( _                     ' VTable offset = 104
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreNameWStr ( _                     ' VTable offset = 108
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreTypeWStr ( _                     ' VTable offset = 112
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreTypeWStr ( _                     ' VTable offset = 116
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreFlags ( _                        ' VTable offset = 120
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreFlags ( _                        ' VTable offset = 124
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreNameWStr ( _                  ' VTable offset = 128
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreNameWStr ( _                  ' VTable offset = 132
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreTypeWStr ( _                  ' VTable offset = 136
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreTypeWStr ( _                  ' VTable offset = 140
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreFlags ( _                     ' VTable offset = 144
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreFlags ( _                     ' VTable offset = 148
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ContainerNameWStr ( _                     ' VTable offset = 152
     BYREF szwContainer AS DWORD _                      ' __out LPWSTR *szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ContainerNameWStr ( _                     ' VTable offset = 156
     BYREF szwContainer AS WSTRINGZ _                   ' __in LPWSTR szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderNameWStr ( _                      ' VTable offset = 160
     BYREF szwProvider AS DWORD _                       ' __out LPWSTR *szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderNameWStr ( _                      ' VTable offset = 164
     BYREF szwProvider AS WSTRINGZ _                    ' __in LPWSTR szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderType ( _                          ' VTable offset = 168
     BYREF pdwType AS LONG _                            ' __out LONG *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderType ( _                          ' VTable offset = 172
     BYVAL pdwType AS LONG _                            ' __in LONG pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeySpec ( _                               ' VTable offset = 176
     BYREF pdw AS LONG _                                ' __out LONG *pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KeySpec ( _                               ' VTable offset = 180
     BYVAL pdw AS LONG _                                ' __in LONG pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderFlags ( _                         ' VTable offset = 184
     BYREF pdwFlags AS  LONG _                          ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderFlags ( _                         ' VTable offset = 188
     BYVALpdwFlags AS  LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UseExistingKeySet ( _                     ' VTable offset = 192
     BYREF fUseExistingKeys AS LONG _                   ' __out BOOL *fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_UseExistingKeySet ( _                     ' VTable offset = 196
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GenKeyFlags ( _                           ' VTable offset = 200
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_GenKeyFlags ( _                           ' VTable offset = 204
     BYVAL pdwFlags AS LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DeleteRequestCert ( _                     ' VTable offset = 208
     BYREF fDelete AS LONG _                            ' __out BOOL *fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DeleteRequestCert ( _                     ' VTable offset = 212
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToUserDS ( _                     ' VTable offset = 216
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToUserDS ( _                     ' VTable offset = 220
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnableT61DNEncoding ( _                   ' VTable offset = 224
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnableT61DNEncoding ( _                   ' VTable offset = 228
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToCSP ( _                        ' VTable offset = 232
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToCSP ( _                        ' VTable offset = 236
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SPCFileNameWStr ( _                       ' VTable offset = 240
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SPCFileNameWStr ( _                       ' VTable offset = 244
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PVKFileNameWStr ( _                       ' VTable offset = 248
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PVKFileNameWStr ( _                       ' VTable offset = 252
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HashAlgorithmWStr ( _                     ' VTable offset = 256
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HashAlgorithmWStr ( _                     ' VTable offset = 260
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RenewalCertificate ( _                    ' VTable offset = 264
     BYREF ppCertContext AS CERT_CONTEXT _              ' __out PCCERT_CONTEXT *ppCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RenewalCertificate ( _                    ' VTable offset = 268
     BYREF pCertContext AS CERT_CONTEXT _               ' __in PCCERT_CONTEXT pCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCertTypeToRequestWStr ( _                  ' VTable offset = 272
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddNameValuePairToSignatureWStr ( _           ' VTable offset = 276
     BYREF Name AS WSTRINGZ _                           ' __in LPWSTR Name
   , BYREF Value AS WSTRINGZ _                          ' __in LPWSTR Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtensionsToRequest ( _                    ' VTable offset = 280
     BYREF pCertExtensions AS CERT_EXTENSIONS _         ' __in PCERT_EXTENSIONS pCertExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddAuthenticatedAttributesToPKCS7Request ( _  ' VTable offset = 284
     BYREF pAttributes AS CRYPT_ATTRIBUTES _            ' __in PCRYPT_ATTRIBUTES pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePKCS7RequestFromRequest ( _             ' VTable offset = 288
     BYREF pRequest AS CRYPT_DATA_BLOB _                ' __in PCRYPT_DATA_BLOB pRequest
   , BYREF pSigningCertContext AS CERT_CONTEXT _        ' __in PCCERT_CONTEXT pSigningCertContext
   , BYREF pPkcs7Blob AS CRYPT_DATA_BLOB _              ' __out PCRYPT_DATA_BLOB pPkcs7Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEnroll2 Methods
   ' =====================================================================================
   METHOD InstallPKCS7Blob ( _                          ' VTable offset = 292
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 296
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedKeySpec ( _                       ' VTable offset = 300
     BYREF pdwKeySpec AS LONG _                         ' __out LONG *pdwKeySpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyLen ( _                                 ' VTable offset = 304
     BYVAL fMin AS LONG _                               ' __in BOOL fMin
   , BYVAL fExchange AS LONG _                          ' __in BOOL fExchange
   , BYREF pdwKeySize AS LONG _                         ' __out LONG *pdwKeySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAlgs ( _                                  ' VTable offset = 308
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL algClass AS LONG _                           ' __in LONG algClass
   , BYREF pdwAlgID AS LONG _                           ' __out LONG *pdwAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlgNameWStr ( _                            ' VTable offset = 312
     BYVAL algID AS LONG _                              ' __in LONG algID
   , BYREF ppwsz AS DWORD _                             ' __out LPWSTR *ppwsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ReuseHardwareKeyIfUnableToGenNew ( _      ' VTable offset = 316
     BYVAL fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __in BOOL fReuseHardwareKeyIfUnableToGenNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ReuseHardwareKeyIfUnableToGenNew ( _      ' VTable offset = 320
     BYREF fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __out BOOL *fReuseHardwareKeyIfUnableToGenNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HashAlgID ( _                             ' VTable offset = 324
     BYVAL hashAlgID AS LONG _                          ' __in LONG hashAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HashAlgID ( _                             ' VTable offset = 328
     BYREF hashAlgID AS LONG _                          ' __retval_out LONG *hashAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreMy ( _                               ' VTable offset = 332
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreCA ( _                               ' VTable offset = 336
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreROOT ( _                             ' VTable offset = 340
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreRequest ( _                          ' VTable offset = 344
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_LimitExchangeKeyToEncipherment ( _        ' VTable offset = 348
     BYVAL fLimitExchangeKeyToEncipherment AS LONG _    ' __in BOOL fLimitExchangeKeyToEncipherment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LimitExchangeKeyToEncipherment ( _        ' VTable offset = 352
     BYREF fLimitExchangeKeyToEncipherment AS LONG _    ' __retval_out BOOL *fLimitExchangeKeyToEncipherment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnableSMIMECapabilities ( _               ' VTable offset = 356
     BYVAL fEnableSMIMECapabilities AS LONG _           ' __in BOOL fEnableSMIMECapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnableSMIMECapabilities ( _               ' VTable offset = 360
     BYREFfEnableSMIMECapabilities AS  LONG _           ' __retval_out BOOL *fEnableSMIMECapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnroll2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnroll4
' IID = {F8053FE5-78F4-448F-A0DB-41D61B73446B}
' Inherited interface = IEnroll2
' ########################################################################################

#IF NOT %DEF(%IEnroll4_INTERFACE_DEFINED)
    %IEnroll4_INTERFACE_DEFINED = 1

INTERFACE IEnroll4 $IID_IEnroll4

   INHERIT IUnknown

   ' =====================================================================================
   ' IEnroll Methods
   ' =====================================================================================
   METHOD createFilePKCS10WStr ( _                      ' VTable offset = 12
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF wszPKCS10FileName AS WSTRINGZ _              ' __in LPCWSTR wszPKCS10FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptFilePKCS7WStr ( _                       ' VTable offset = 16
     BYREF wszPKCS7FileName AS WSTRINGZ _               ' __in LPCWSTR wszPKCS7FileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createPKCS10WStr ( _                          ' VTable offset = 20
     BYREF DNName AS WSTRINGZ _                         ' __in LPCWSTR DNName
   , BYREF Usage AS WSTRINGZ _                          ' __in LPCWSTR Usage
   , BYREF pPkcs10Blob AS CRYPT_DATA_BLOB _             ' __out PCRYPT_DATA_BLOB pPkcs10Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptPKCS7Blob ( _                           ' VTable offset = 24
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getCertContextFromPKCS7 ( _                   ' VTable offset = 28
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS DWORD                                           ' PCCERT_CONTEXT
   ' =====================================================================================
   METHOD getMyStore ( _                                ' VTable offset = 32
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getCAStore ( _                                ' VTable offset = 36
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD getROOTHStore ( _                             ' VTable offset = 40
   ) AS DWORD                                           ' HCERTSTORE
   ' =====================================================================================
   METHOD enumProvidersWStr ( _                         ' VTable offset = 44
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   , BYREF pbstrProvName AS DWORD _                     ' __out LPWSTR *pbstrProvName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD enumContainersWStr ( _                        ' VTable offset = 48
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYREF pbstr AS DWORD _                             ' __out LPWSTR *pbstr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD freeRequestInfoBlob ( _                       ' VTable offset = 52
     BYREF pkcs7OrPkcs10 AS CRYPT_DATA_BLOB _           ' __in CRYPT_DATA_BLOB pkcs7OrPkcs10
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreNameWStr ( _                       ' VTable offset = 56
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreNameWStr ( _                       ' VTable offset = 60
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreTypeWStr ( _                       ' VTable offset = 64
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreTypeWStr ( _                       ' VTable offset = 68
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MyStoreFlags ( _                          ' VTable offset = 72
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MyStoreFlags ( _                          ' VTable offset = 76
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreNameWStr ( _                       ' VTable offset = 80
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreNameWStr ( _                       ' VTable offset = 84
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreTypeWStr ( _                       ' VTable offset = 88
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreTypeWStr ( _                       ' VTable offset = 92
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CAStoreFlags ( _                          ' VTable offset = 96
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CAStoreFlags ( _                          ' VTable offset = 100
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreNameWStr ( _                     ' VTable offset = 104
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreNameWStr ( _                     ' VTable offset = 108
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreTypeWStr ( _                     ' VTable offset = 112
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreTypeWStr ( _                     ' VTable offset = 116
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootStoreFlags ( _                        ' VTable offset = 120
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootStoreFlags ( _                        ' VTable offset = 124
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreNameWStr ( _                  ' VTable offset = 128
     BYREF szwName AS DWORD _                           ' __out LPWSTR *szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreNameWStr ( _                  ' VTable offset = 132
     BYREF szwName AS WSTRINGZ _                        ' __in LPWSTR szwName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreTypeWStr ( _                  ' VTable offset = 136
     BYREF szwType AS DWORD _                           ' __out LPWSTR *szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreTypeWStr ( _                  ' VTable offset = 140
     BYREF szwType AS WSTRINGZ _                        ' __in LPWSTR szwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RequestStoreFlags ( _                     ' VTable offset = 144
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RequestStoreFlags ( _                     ' VTable offset = 148
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ContainerNameWStr ( _                     ' VTable offset = 152
     BYREF szwContainer AS DWORD _                      ' __out LPWSTR *szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ContainerNameWStr ( _                     ' VTable offset = 156
     BYREF szwContainer AS WSTRINGZ _                   ' __in LPWSTR szwContainer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderNameWStr ( _                      ' VTable offset = 160
     BYREF szwProvider AS DWORD _                       ' __out LPWSTR *szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderNameWStr ( _                      ' VTable offset = 164
     BYREF szwProvider AS WSTRINGZ _                    ' __in LPWSTR szwProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderType ( _                          ' VTable offset = 168
     BYREF pdwType AS LONG _                            ' __out LONG *pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderType ( _                          ' VTable offset = 172
     BYVAL pdwType AS LONG _                            ' __in LONG pdwType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeySpec ( _                               ' VTable offset = 176
     BYREF pdw AS LONG _                                ' __out LONG *pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_KeySpec ( _                               ' VTable offset = 180
     BYVAL pdw AS LONG _                                ' __in LONG pdw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProviderFlags ( _                         ' VTable offset = 184
     BYREF pdwFlags AS  LONG _                          ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProviderFlags ( _                         ' VTable offset = 188
     BYVALpdwFlags AS  LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UseExistingKeySet ( _                     ' VTable offset = 192
     BYREF fUseExistingKeys AS LONG _                   ' __out BOOL *fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_UseExistingKeySet ( _                     ' VTable offset = 196
     BYVAL fUseExistingKeys AS LONG _                   ' __in BOOL fUseExistingKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_GenKeyFlags ( _                           ' VTable offset = 200
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_GenKeyFlags ( _                           ' VTable offset = 204
     BYVAL pdwFlags AS LONG _                           ' __in LONG pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DeleteRequestCert ( _                     ' VTable offset = 208
     BYREF fDelete AS LONG _                            ' __out BOOL *fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DeleteRequestCert ( _                     ' VTable offset = 212
     BYVAL fDelete AS LONG _                            ' __in BOOL fDelete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToUserDS ( _                     ' VTable offset = 216
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToUserDS ( _                     ' VTable offset = 220
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnableT61DNEncoding ( _                   ' VTable offset = 224
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnableT61DNEncoding ( _                   ' VTable offset = 228
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WriteCertToCSP ( _                        ' VTable offset = 232
     BYREF fBool AS LONG _                              ' __out BOOL *fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WriteCertToCSP ( _                        ' VTable offset = 236
     BYVAL fBool AS LONG _                              ' __in BOOL fBool
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_SPCFileNameWStr ( _                       ' VTable offset = 240
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_SPCFileNameWStr ( _                       ' VTable offset = 244
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PVKFileNameWStr ( _                       ' VTable offset = 248
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PVKFileNameWStr ( _                       ' VTable offset = 252
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HashAlgorithmWStr ( _                     ' VTable offset = 256
     BYREF szw AS DWORD _                               ' __out LPWSTR *szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HashAlgorithmWStr ( _                     ' VTable offset = 260
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RenewalCertificate ( _                    ' VTable offset = 264
     BYREF ppCertContext AS CERT_CONTEXT _              ' __out PCCERT_CONTEXT *ppCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RenewalCertificate ( _                    ' VTable offset = 268
     BYREF pCertContext AS CERT_CONTEXT _               ' __in PCCERT_CONTEXT pCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCertTypeToRequestWStr ( _                  ' VTable offset = 272
     BYREF szw AS WSTRINGZ _                            ' __in LPWSTR szw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddNameValuePairToSignatureWStr ( _           ' VTable offset = 276
     BYREF Name AS WSTRINGZ _                           ' __in LPWSTR Name
   , BYREF Value AS WSTRINGZ _                          ' __in LPWSTR Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtensionsToRequest ( _                    ' VTable offset = 280
     BYREF pCertExtensions AS CERT_EXTENSIONS _         ' __in PCERT_EXTENSIONS pCertExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddAuthenticatedAttributesToPKCS7Request ( _  ' VTable offset = 284
     BYREF pAttributes AS CRYPT_ATTRIBUTES _            ' __in PCRYPT_ATTRIBUTES pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePKCS7RequestFromRequest ( _             ' VTable offset = 288
     BYREF pRequest AS CRYPT_DATA_BLOB _                ' __in PCRYPT_DATA_BLOB pRequest
   , BYREF pSigningCertContext AS CERT_CONTEXT _        ' __in PCCERT_CONTEXT pSigningCertContext
   , BYREF pPkcs7Blob AS CRYPT_DATA_BLOB _              ' __out PCRYPT_DATA_BLOB pPkcs7Blob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEnroll2 Methods
   ' =====================================================================================
   METHOD InstallPKCS7Blob ( _                          ' VTable offset = 292
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 296
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedKeySpec ( _                       ' VTable offset = 300
     BYREF pdwKeySpec AS LONG _                         ' __out LONG *pdwKeySpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyLen ( _                                 ' VTable offset = 304
     BYVAL fMin AS LONG _                               ' __in BOOL fMin
   , BYVAL fExchange AS LONG _                          ' __in BOOL fExchange
   , BYREF pdwKeySize AS LONG _                         ' __out LONG *pdwKeySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAlgs ( _                                  ' VTable offset = 308
     BYVAL dwIndex AS LONG _                            ' __in LONG dwIndex
   , BYVAL algClass AS LONG _                           ' __in LONG algClass
   , BYREF pdwAlgID AS LONG _                           ' __out LONG *pdwAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlgNameWStr ( _                            ' VTable offset = 312
     BYVAL algID AS LONG _                              ' __in LONG algID
   , BYREF ppwsz AS DWORD _                             ' __out LPWSTR *ppwsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ReuseHardwareKeyIfUnableToGenNew ( _      ' VTable offset = 316
     BYVAL fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __in BOOL fReuseHardwareKeyIfUnableToGenNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ReuseHardwareKeyIfUnableToGenNew ( _      ' VTable offset = 320
     BYREF fReuseHardwareKeyIfUnableToGenNew AS LONG _  ' __out BOOL *fReuseHardwareKeyIfUnableToGenNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HashAlgID ( _                             ' VTable offset = 324
     BYVAL hashAlgID AS LONG _                          ' __in LONG hashAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HashAlgID ( _                             ' VTable offset = 328
     BYREF hashAlgID AS LONG _                          ' __retval_out LONG *hashAlgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreMy ( _                               ' VTable offset = 332
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreCA ( _                               ' VTable offset = 336
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreROOT ( _                             ' VTable offset = 340
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHStoreRequest ( _                          ' VTable offset = 344
     BYVAL hStore AS DWORD _                            ' __in HCERTSTORE hStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_LimitExchangeKeyToEncipherment ( _        ' VTable offset = 348
     BYVAL fLimitExchangeKeyToEncipherment AS LONG _    ' __in BOOL fLimitExchangeKeyToEncipherment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LimitExchangeKeyToEncipherment ( _        ' VTable offset = 352
     BYREF fLimitExchangeKeyToEncipherment AS LONG _    ' __retval_out BOOL *fLimitExchangeKeyToEncipherment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnableSMIMECapabilities ( _               ' VTable offset = 356
     BYVAL fEnableSMIMECapabilities AS LONG _           ' __in BOOL fEnableSMIMECapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnableSMIMECapabilities ( _               ' VTable offset = 360
     BYREFfEnableSMIMECapabilities AS  LONG _           ' __retval_out BOOL *fEnableSMIMECapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEnroll4 Methods
   ' =====================================================================================
   METHOD put_ThumbPrintWStr ( _                        ' VTable offset = 364
     BYREF thumbPrintBlob AS CRYPT_DATA_BLOB _          ' __in CRYPT_DATA_BLOB thumbPrintBlob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ThumbPrintWStr ( _                        ' VTable offset = 368
     BYREF thumbPrintBlob AS CRYPT_DATA_BLOB _          ' __retval_out PCRYPT_DATA_BLOB thumbPrintBlob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPrivateKeyArchiveCertificate ( _           ' VTable offset = 372
     BYREF pPrivateKeyArchiveCert AS CERT_CONTEXT _     ' __in PCCERT_CONTEXT pPrivateKeyArchiveCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrivateKeyArchiveCertificate ( _           ' VTable offset = 376
   ) AS DWORD                                           ' PCCERT_CONTEXT
   ' =====================================================================================
   METHOD binaryBlobToString ( _                        ' VTable offset = 380
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pblobBinary AS CRYPT_DATA_BLOB _             ' __in PCRYPT_DATA_BLOB pblobBinary
   , BYREF ppwszString AS DWORD _                       ' __out LPWSTR *ppwszString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD stringToBinaryBlob ( _                        ' VTable offset = 384
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszString AS WSTRINGZ _                     ' __in LPCWSTR pwszString
   , BYREF pblobBinary AS CRYPT_DATA_BLOB _             ' __out PCRYPT_DATA_BLOB pblobBinary
   , BYREF pdwSkip AS LONG _                            ' __out LONG *pdwSkip
   , BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD addExtensionToRequestWStr ( _                 ' VTable offset = 388
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , BYREF pblobValue AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pblobValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD addAttributeToRequestWStr ( _                 ' VTable offset = 392
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , BYREF pblobValue AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pblobValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD addNameValuePairToRequestWStr ( _             ' VTable offset = 396
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , BYREF pwszValue AS WSTRINGZ _                      ' __in LPCWSTR pwszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD resetExtensions ( _                           ' VTable offset = 400
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD resetAttributes ( _                           ' VTable offset = 404
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createRequestWStr ( _                         ' VTable offset = 408
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszDNName AS WSTRINGZ _                     ' __in LPCWSTR pwszDNName
   , BYREF pwszUsage AS WSTRINGZ _                      ' __in LPCWSTR pwszUsage
   , BYREF pblobRequest AS CRYPT_DATA_BLOB _            ' __out PCRYPT_DATA_BLOB pblobRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createFileRequestWStr ( _                     ' VTable offset = 412
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pwszDNName AS WSTRINGZ _                     ' __in LPCWSTR pwszDNName
   , BYREF pwszUsage AS WSTRINGZ _                      ' __in LPCWSTR pwszUsage
   , BYREF pwszRequestFileName AS WSTRINGZ _            ' __in LPCWSTR pwszRequestFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptResponseBlob ( _                        ' VTable offset = 416
     BYREF pblobResponse AS CRYPT_DATA_BLOB _           ' __in PCRYPT_DATA_BLOB pblobResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD acceptFileResponseWStr ( _                    ' VTable offset = 420
     BYREF pwszResponseFileName AS WSTRINGZ _           ' __in LPCWSTR pwszResponseFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getCertContextFromResponseBlob ( _            ' VTable offset = 424
     BYREF pblobResponse AS CRYPT_DATA_BLOB _           ' __in PCRYPT_DATA_BLOB pblobResponse
   , BYREF ppCertContext AS CERT_CONTEXT _              ' __out PCCERT_CONTEXT *ppCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getCertContextFromFileResponseWStr ( _        ' VTable offset = 428
     BYREF pwszResponseFileName AS WSTRINGZ _           ' __in LPCWSTR pwszResponseFileName
   , BYREF ppCertContext AS CERT_CONTEXT _              ' __out PCCERT_CONTEXT *ppCertContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createPFXWStr ( _                             ' VTable offset = 432
     BYREF pwszPassword AS WSTRINGZ _                   ' __in LPCWSTR pwszPassword
   , BYREF pblobPFX AS CRYPT_DATA_BLOB _                ' __out PCRYPT_DATA_BLOB pblobPFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD createFilePFXWStr ( _                         ' VTable offset = 436
     BYREF pwszPassword AS WSTRINGZ _                   ' __in LPCWSTR pwszPassword
   , BYREF pwszPFXFileName AS WSTRINGZ _                ' __in LPCWSTR pwszPFXFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD setPendingRequestInfoWStr ( _                 ' VTable offset = 440
     BYVAL lRequestID AS LONG _                         ' __in LONG lRequestID
   , BYREF pwszCADNS AS WSTRINGZ _                      ' __in LPCWSTR pwszCADNS
   , BYREF pwszCAName AS WSTRINGZ _                     ' __in LPCWSTR pwszCAName
   , BYREF pwszFriendlyName AS WSTRINGZ _               ' __in LPCWSTR pwszFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD enumPendingRequestWStr ( _                    ' VTable offset = 444
     BYVAL lIndex AS LONG _                             ' __in LONG lIndex
   , BYVAL lDesiredProperty AS LONG _                   ' __in LONG lDesiredProperty
   , BYREF ppProperty AS DWORD _                        ' __out LPVOID ppProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD removePendingRequestWStr ( _                  ' VTable offset = 448
     BYREF thumbPrintBlob AS CRYPT_DATA_BLOB _          ' __in CRYPT_DATA_BLOB thumbPrintBlob
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKeyLenEx ( _                               ' VTable offset = 452
     BYVAL lSizeSpec AS LONG _                          ' __in LONG lSizeSpec
   , BYVAL lKeySpec AS LONG _                           ' __in LONG lKeySpec
   , BYREF pdwKeySize AS LONG _                         ' __retval_out LONG *pdwKeySize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InstallPKCS7BlobEx ( _                        ' VTable offset = 456
     BYREF pBlobPKCS7 AS CRYPT_DATA_BLOB _              ' __in PCRYPT_DATA_BLOB pBlobPKCS7
   , BYREF plCertInstalled AS LONG _                    ' __retval_out LONG *plCertInstalled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCertTypeToRequestWStrEx ( _                ' VTable offset = 460
     BYVAL lType AS LONG _                              ' __in LONG lType
   , BYREF pwszOIDOrName AS WSTRINGZ _                  ' __in LPCWSTR pwszOIDOrName
   , BYVAL lMajorVersion AS LONG _                      ' __in LONG lMajorVersion
   , BYVAL fMinorVersion AS LONG _                      ' __in BOOL fMinorVersion
   , BYVAL lMinorVersion AS LONG _                      ' __in LONG lMinorVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD getProviderTypeWStr ( _                       ' VTable offset = 464
     BYREF pwszProvName AS WSTRINGZ _                   ' __in LPCWSTR pwszProvName
   , BYREF plProvType AS LONG _                         ' __retval_out LONG *plProvType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD addBlobPropertyToCertificateWStr ( _          ' VTable offset = 468
     BYVAL lPropertyId AS LONG _                        ' __in LONG lPropertyId
   , BYVAL lReserved AS LONG _                          ' __in LONG lReserved
   , BYREF pBlobProperty AS CRYPT_DATA_BLOB _           ' __in PCRYPT_DATA_BLOB pBlobProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignerCertificate ( _                      ' VTable offset = 472
     BYREF pSignerCert AS CERT_CONTEXT _                ' __in PCCERT_CONTEXT pSignerCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ClientId ( _                              ' VTable offset = 476
     BYVAL lClientId AS LONG _                          ' __in LONG lClientId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ClientId ( _                              ' VTable offset = 480
     BYREF plClientId AS LONG _                         ' __retval_out LONG *plClientId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IncludeSubjectKeyID ( _                   ' VTable offset = 484
     BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IncludeSubjectKeyID ( _                   ' VTable offset = 488
     BYREF pfInclude AS LONG _                          ' __retval_out BOOL *pfInclude
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnroll4_INTERFACE_DEFINED__ */

'extern "C" IEnroll * WINAPI PIEnrollGetNoCOM(void);
'extern "C" IEnroll2 * WINAPI PIEnroll2GetNoCOM(void);
'extern "C" IEnroll4 * WINAPI PIEnroll4GetNoCOM(void);

DECLARE FUNCTION PIEnrollGetNoCOM CDECL IMPORT "XENROLL.DLL" ALIAS "PIEnrollGetNoCOM" () AS DWORD
DECLARE FUNCTION PIEnroll2GetNoCOM CDECL IMPORT "XENROLL.DLL" ALIAS "PIEnroll2GetNoCOM" () AS DWORD
DECLARE FUNCTION PIEnroll4GetNoCOM CDECL IMPORT "XENROLL.DLL" ALIAS "PIEnroll4GetNoCOM" () AS DWORD


%CRYPT_ENUM_ALL_PROVIDERS = &H1
%XEPR_ENUM_FIRST          = -1
%XEPR_CADNS               = &H01
%XEPR_CANAME              = &H02
%XEPR_CAFRIENDLYNAME      = &H03
%XEPR_REQUESTID           = &H04
%XEPR_DATE                = &H05
%XEPR_TEMPLATENAME        = &H06
%XEPR_VERSION             = &H07
%XEPR_HASH                = &H08
%XEPR_V1TEMPLATENAME      = &H09
%XEPR_V2TEMPLATEOID       = &H10
%XECR_PKCS10_V2_0         = &H1
%XECR_PKCS7               = &H2
%XECR_CMC                 = &H3
%XECR_PKCS10_V1_5         = &H4
%XEKL_KEYSIZE_MIN         = &H1
%XEKL_KEYSIZE_MAX         = &H2
%XEKL_KEYSIZE_INC         = &H3
%XEKL_KEYSIZE_DEFAULT     = &H4
%XEKL_KEYSPEC_KEYX        = &H1
%XEKL_KEYSPEC_SIG         = &H2
%XECT_EXTENSION_V1        = &H1
%XECT_EXTENSION_V2        = &H2
%XECP_STRING_PROPERTY     = &H1
%XECI_DISABLE             = &H0
%XECI_XENROLL             = &H1
%XECI_AUTOENROLL          = &H2
%XECI_REQWIZARD           = &H3
%XECI_CERTREQ             = &H4
