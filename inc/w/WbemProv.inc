' ########################################################################################
' Microsoft Windows
' File: WbemProv.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WbemProviders_v1
' Version: 0.0, Locale ID = 0
' Library GUID: {092DF710-7010-11D1-AD90-00C04FD8FDFF}
' ########################################################################################

#INCLUDE THIS ONCE
%WBEMPROV_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "wbemcli.inc"

'typedef VARIANT WBEM_VARIANT;
'typedef /* [string] */ WCHAR *WBEM_WSTR;
'typedef /* [string] */ const WCHAR *WBEM_CWSTR;

' WBEM_PROVIDER_REQUIREMENTS_TYPE enum
%WBEM_REQUIREMENTS_START_POSTFILTER      = 0
%WBEM_REQUIREMENTS_STOP_POSTFILTER       = 1
%WBEM_REQUIREMENTS_RECHECK_SUBSCRIPTIONS = 2

#IF NOT %DEF(%WbemProviders_v1_LIBRARY_DEFINED)
    %WbemProviders_v1_LIBRARY_DEFINED = 1

$CLSID_WbemAdministrativeLocator = GUID$("{CB8555CC-9128-11D1-AD9B-00C04FD8FDFF}")
$CLSID_WbemAuthenticatedLocator = GUID$("{CD184336-9128-11D1-AD9B-00C04FD8FDFF}")
$CLSID_WbemUnauthenticatedLocator = GUID$("{443E7B79-DE31-11D2-B340-00104BCC4B4A}")
$CLSID_WbemDecoupledRegistrar = GUID$("{4CFC7932-0F9D-4BEF-9C32-8EA2A6B56FCB}")
$CLSID_WbemDecoupledBasicEventProvider = GUID$("{F5F75737-2843-4F22-933D-C76A97CDA62F}")

$IID_IWbemPropertyProvider = GUID$("{CE61E841-65BC-11D0-B6BD-00AA003240C7}")
$IID_IWbemUnboundObjectSink = GUID$("{E246107B-B06E-11D0-AD61-00C04FD8FDFF}")
$IID_IWbemEventProvider = GUID$("{E245105B-B06E-11D0-AD61-00C04FD8FDFF}")
$IID_IWbemEventProviderQuerySink = GUID$("{580ACAF8-FA1C-11D0-AD72-00C04FD8FDFF}")
$IID_IWbemEventProviderSecurity = GUID$("{631F7D96-D993-11D2-B339-00105A1F4AAF}")
$IID_IWbemEventConsumerProvider = GUID$("{E246107A-B06E-11D0-AD61-00C04FD8FDFF}")
$IID_IWbemProviderInitSink = GUID$("{1BE41571-91DD-11D1-AEB2-00C04FB68820}")
$IID_IWbemProviderInit = GUID$("{1BE41572-91DD-11D1-AEB2-00C04FB68820}")
$IID_IWbemHiPerfProvider = GUID$("{49353C93-516B-11D1-AEA6-00C04FB68820}")
$IID_IWbemDecoupledRegistrar = GUID$("{1005CBCF-E64F-4646-BCD3-3A089D8A84B4}")
$IID_IWbemProviderIdentity = GUID$("{631F7D97-D993-11D2-B339-00105A1F4AAF}")
$IID_IWbemDecoupledBasicEventProvider = GUID$("{86336D20-CA11-4786-9EF1-BC8A946B42FC}")
$IID_IWbemEventSink = GUID$("{3AE0080A-7E3A-4366-BF89-0FEEDC931659}")

' ========================================================================================
' Interface name = IWbemPropertyProvider
' IID = {CE61E841-65BC-11D0-B6BD-00AA003240C7}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ========================================================================================

#IF NOT %DEF(%IWbemPropertyProvider_INTERFACE_DEFINED)
    %IWbemPropertyProvider_INTERFACE_DEFINED = 1

INTERFACE IWbemPropertyProvider $IID_IWbemPropertyProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL strLocale AS WSTRING _                       ' __in const BSTR strLocale
   , BYVAL strClassMapping AS WSTRING _                 ' __in const BSTR strClassMapping
   , BYVAL strInstMapping AS WSTRING _                  ' __in const BSTR strInstMapping
   , BYVAL strPropMapping AS WSTRING _                  ' __in const BSTR strPropMapping
   , BYREF pvValue AS VARIANT _                         ' __out VARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PutProperty ( _                               ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL strLocale AS WSTRING _                       ' __in const BSTR strLocale
   , BYVAL strClassMapping AS WSTRING _                 ' __in const BSTR strClassMapping
   , BYVAL strInstMapping AS WSTRING _                  ' __in const BSTR strInstMapping
   , BYVAL strPropMapping AS WSTRING _                  ' __in const BSTR strPropMapping
   , BYREF pvValue AS VARIANT _                         ' __in const VARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemPropertyProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemUnboundObjectSink
' IID = {E246107B-B06E-11D0-AD61-00C04FD8FDFF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemUnboundObjectSink_INTERFACE_DEFINED)
    %IWbemUnboundObjectSink_INTERFACE_DEFINED = 1

INTERFACE IWbemUnboundObjectSink $IID_IWbemUnboundObjectSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IndicateToConsumer ( _                        ' VTable offset = 12
     BYVAL pLogicalConsumer AS IWbemClassObject _       ' __in IWbemClassObject *pLogicalConsumer
   , BYVAL lNumObjects AS LONG _                        ' __in long lNumObjects
   , BYREF apObjects AS IWbemClassObject _              ' __in IWbemClassObject **apObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemUnboundObjectSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemEventProvider
' IID = {E245105B-B06E-11D0-AD61-00C04FD8FDFF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemEventProvider_INTERFACE_DEFINED)
    %IWbemEventProvider_INTERFACE_DEFINED = 1

INTERFACE IWbemEventProvider $IID_IWbemEventProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProvideEvents ( _                             ' VTable offset = 12
     BYVAL pSink AS IWbemObjectSink _                   ' __in IWbemObjectSink *pSink
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemEventProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemEventProviderQuerySink
' IID = {580ACAF8-FA1C-11D0-AD72-00C04FD8FDFF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemEventProviderQuerySink_INTERFACE_DEFINED)
    %IWbemEventProviderQuerySink_INTERFACE_DEFINED = 1

INTERFACE IWbemEventProviderQuerySink $IID_IWbemEventProviderQuerySink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NewQuery ( _                                  ' VTable offset = 12
     BYVAL dwId AS DWORD _                              ' __in unsigned long dwId
   , BYREF wszQueryLanguage AS WSTRINGZ _               ' __in WBEM_WSTR wszQueryLanguage
   , BYREF wszQuery AS WSTRINGZ _                       ' __in WBEM_WSTR wszQuery
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelQuery ( _                               ' VTable offset = 16
     BYVAL dwId AS LONG _                               ' __in unsigned long dwId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemEventProviderQuerySink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemEventProviderSecurity
' IID = {631F7D96-D993-11D2-B339-00105A1F4AAF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemEventProviderSecurity_INTERFACE_DEFINED)
    %IWbemEventProviderSecurity_INTERFACE_DEFINED = 1

INTERFACE IWbemEventProviderSecurity $IID_IWbemEventProviderSecurity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AccessCheck ( _                               ' VTable offset = 12
     BYREF wszQueryLanguage AS WSTRINGZ _               ' __in WBEM_CWSTR wszQueryLanguage
   , BYREF wszQuery AS WSTRINGZ _                       ' __in WBEM_CWSTR wszQuery
   , BYVAL lSidLength AS LONG _                         ' __in long lSidLength
   , BYVAL pSid AS BYTE PTR _                           ' __in const BYTE *pSid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemEventProviderSecurity_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemEventConsumerProvider
' IID = {E246107A-B06E-11D0-AD61-00C04FD8FDFF}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemEventConsumerProvider_INTERFACE_DEFINED)
    %IWbemEventConsumerProvider_INTERFACE_DEFINED = 1

INTERFACE IWbemEventConsumerProvider $IID_IWbemEventConsumerProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindConsumer ( _                              ' VTable offset = 12
     BYVAL pLogicalConsumer AS IWbemClassObject _       ' __in IWbemClassObject *pLogicalConsumer
   , BYREF ppConsumer AS IWbemUnboundObjectSink _       ' __out IWbemUnboundObjectSink **ppConsumer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemEventConsumerProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemProviderInitSink
' IID = {1BE41571-91DD-11D1-AEB2-00C04FB68820}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemProviderInitSink_INTERFACE_DEFINED)
    %IWbemProviderInitSink_INTERFACE_DEFINED = 1

INTERFACE IWbemProviderInitSink $IID_IWbemProviderInitSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 12
     BYVAL lStatus AS LONG _                            ' __in LONG lStatus
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemProviderInitSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemProviderInit
' IID = {1BE41572-91DD-11D1-AEB2-00C04FB68820}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemProviderInit_INTERFACE_DEFINED)
    %IWbemProviderInit_INTERFACE_DEFINED = 1

INTERFACE IWbemProviderInit $IID_IWbemProviderInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF wszUser AS WSTRINGZ _                        ' __in LPWSTR wszUser
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYREF wszNamespace AS WSTRINGZ _                   ' __in LPWSTR wszNamespace
   , BYREF wszLocale AS WSTRINGZ _                      ' __in LPWSTR wszLocale
   , BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pInitSink AS IWbemProviderInitSink _         ' __in IWbemProviderInitSink *pInitSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemProviderInit_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemHiPerfProvider
' IID = {49353C93-516B-11D1-AEA6-00C04FB68820}
' Attributes = 512 [&H200] [Restricted]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemHiPerfProvider_INTERFACE_DEFINED)
    %IWbemHiPerfProvider_INTERFACE_DEFINED = 1

INTERFACE IWbemHiPerfProvider $IID_IWbemHiPerfProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryInstances ( _                            ' VTable offset = 12
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL wszClass AS DWORD _                          ' __in WCHAR *wszClass
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pCtx AS IWbemContext _                       ' __in IWbemContext *pCtx
   , BYVAL pSink AS IWbemObjectSink _                   ' __in IWbemObjectSink *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRefresher ( _                           ' VTable offset = 16
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYREF ppRefresher AS IWbemRefresher _              ' __out IWbemRefresher **ppRefresher
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRefreshableObject ( _                   ' VTable offset = 20
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL pTemplate AS IWbemObjectAccess _             ' __in IWbemObjectAccess *pTemplate
   , BYVAL pRefresher AS IWbemRefresher _               ' __in IWbemRefresher *pRefresher
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   , BYREF ppRefreshable AS IWbemObjectAccess _         ' __out IWbemObjectAccess **ppRefreshable
   , BYREF plId AS LONG _                               ' __out long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopRefreshing ( _                            ' VTable offset = 24
     BYVAL pRefresher AS IWbemRefresher _               ' __in IWbemRefresher *pRefresher
   , BYVAL lId AS LONG _                                ' __in long lId
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRefreshableEnum ( _                     ' VTable offset = 28
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYREF wszClass AS WSTRINGZ _                       ' __in LPCWSTR wszClass
   , BYVAL pRefresher AS IWbemRefresher _               ' __in IWbemRefresher *pRefresher
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   , BYVAL pHiPerfEnum AS IWbemHiPerfEnum _             ' __in IWbemHiPerfEnum *pHiPerfEnum
   , BYREF plId AS LONG _                               ' __out long *plId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjects ( _                                ' VTable offset = 32
     BYVAL pNamespace AS IWbemServices _                ' __in IWbemServices *pNamespace
   , BYVAL lNumObjects AS LONG _                        ' __in long lNumObjects
   , BYREF apObj AS IWbemObjectAccess _                 ' __in_out IWbemObjectAccess **apObj
   , BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pContext AS IWbemContext _                   ' __in IWbemContext *pContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemHiPerfProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWbemDecoupledRegistrar
' IID = {1005CBCF-E64F-4646-BCD3-3A089D8A84B4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWbemDecoupledRegistrar_INTERFACE_DEFINED)
    %IWbemDecoupledRegistrar_INTERFACE_DEFINED = 1

INTERFACE IWbemDecoupledRegistrar $IID_IWbemDecoupledRegistrar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL a_Flags AS LONG _                            ' __in long a_Flags
   , BYVAL a_Context AS IWbemContext _                  ' __in IWbemContext *a_Context
   , BYREF a_User AS WSTRINGZ _                         ' __in LPCWSTR a_User
   , BYREF a_Locale AS WSTRINGZ _                       ' __in LPCWSTR a_Locale
   , BYREF a_Scope AS WSTRINGZ _                        ' __in LPCWSTR a_Scope
   , BYREF a_Registration AS WSTRINGZ _                 ' __in LPCWSTR a_Registration
   , BYVAL a_Unknown AS IUnknown _                      ' __in IUnknown *a_Unknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegister ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemDecoupledRegistrar_INTERFACE_DEFINED__ */

#ENDIF   ' /* __WbemProviders_v1_LIBRARY_DEFINED__ */

' ========================================================================================
' Interface name = IWbemProviderIdentity
' IID = 631F7D97-D993-11D2-B339-00105A1F4AAF
' Inherited interface = IUnknown
' ========================================================================================

#IF NOT %DEF(%IWbemProviderIdentity_INTERFACE_DEFINED)
    %IWbemProviderIdentity_INTERFACE_DEFINED = 1

INTERFACE IWbemProviderIdentity $IID_IWbemProviderIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRegistrationObject ( _                     ' VTable offset = 12
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL pProvReg AS IWbemClassObject _               ' __in IWbemClassObject *pProvReg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemProviderIdentity_INTERFACE_DEFINED__ */

' WBEM_EXTRA_RETURN_CODES enum
%WBEM_S_INITIALIZED         = 0
%WBEM_S_LIMITED_SERVICE     = &H43001
%WBEM_S_INDIRECTLY_UPDATED  = %WBEM_S_LIMITED_SERVICE    + 1
%WBEM_S_SUBJECT_TO_SDS      = %WBEM_S_INDIRECTLY_UPDATED + 1
%WBEM_E_RETRY_LATER         = &H80043001
%WBEM_E_RESOURCE_CONTENTION = %WBEM_E_RETRY_LATER        + 1

' WBEM_PROVIDER_FLAGS enum
%WBEM_FLAG_OWNER_UPDATE     = &H10000

' ########################################################################################
' Interface name = IWbemDecoupledBasicEventProvider
' IID = {86336D20-CA11-4786-9EF1-BC8A946B42FC}
' Inherited interface = IWbemDecoupledRegistrar
' ########################################################################################

#IF NOT %DEF(%IWbemDecoupledBasicEventProvider_INTERFACE_DEFINED)
    %IWbemDecoupledBasicEventProvider_INTERFACE_DEFINED = 1

INTERFACE IWbemDecoupledBasicEventProvider $IID_IWbemDecoupledBasicEventProvider

   INHERIT IUnknown

   ' =====================================================================================
   ' IWbemDecoupledRegistrar methods
   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL a_Flags AS LONG _                            ' __in long a_Flags
   , BYVAL a_Context AS IWbemContext _                  ' __in IWbemContext *a_Context
   , BYREF a_User AS WSTRINGZ _                         ' __in LPCWSTR a_User
   , BYREF a_Locale AS WSTRINGZ _                       ' __in LPCWSTR a_Locale
   , BYREF a_Scope AS WSTRINGZ _                        ' __in LPCWSTR a_Scope
   , BYREF a_Registration AS WSTRINGZ _                 ' __in LPCWSTR a_Registration
   , BYVAL a_Unknown AS IUnknown _                      ' __in IUnknown *a_Unknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegister ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWbemDecoupledBasicEventProvider methods
   ' =====================================================================================
   METHOD GetSink ( _                                   ' VTable offset = 20
     BYVAL a_Flags AS LONG _                            ' __in long a_Flags
   , BYVAL a_Context AS IWbemContext _                  ' __in IWbemContext *a_Context
   , BYREF a_Sink AS IWbemObjectSink _                  ' __out IWbemObjectSink **a_Sink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetService ( _                                ' VTable offset = 24
     BYVAL a_Flags AS LONG _                            ' __in long a_Flags
   , BYVAL a_Context AS IWbemContext _                  ' __in IWbemContext *a_Context
   , BYREF a_Service AS IWbemServices _                 ' __out IWbemServices **a_Service
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemDecoupledBasicEventProvider_INTERFACE_DEFINED__ */

' WBEM_BATCH_TYPE enum
%WBEM_FLAG_BATCH_IF_NEEDED = 0
%WBEM_FLAG_MUST_BATCH      = &H1
%WBEM_FLAG_MUST_NOT_BATCH  = &H2

' ========================================================================================
' Interface name = IWbemEventSink
' IID = 3AE0080A-7E3A-4366-BF89-0FEEDC931659
' Inherited interface = IWbemObjectSink
' ========================================================================================

#IF NOT %DEF(%IWbemEventSink_INTERFACE_DEFINED)
    %IWbemEventSink_INTERFACE_DEFINED = 1

INTERFACE IWbemEventSink $IID_IWbemEventSink

   INHERIT IUnknown

   ' =====================================================================================
   ' IWbemObjectSink methods
   ' =====================================================================================
   METHOD Indicate ( _                                  ' VTable offset = 12
     BYVAL lObjectCount AS LONG _                       ' __in long lObjectCount
   , BYREF apObjArray AS IWbemClassObject _             ' __in IWbemClassObject **apObjArray [array]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 16
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   , BYVAL hResult AS LONG _                            ' __in HRESULT hResult
   , BYVAL strParam AS WSTRING _                        ' __in BSTR strParam
   , BYVAL pObjParam AS IWbemClassObject _              ' __in IWbemClassObject *pObjParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWbemEventSink methods
   ' =====================================================================================
   METHOD SetSinkSecurity ( _                           ' VTable offset = 20
     BYVAL lSDLength AS LONG _                          ' __in long lSDLength
   , BYVAL pSD AS BYTE PTR _                            ' __in BYTE *pSD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsActive ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRestrictedSink ( _                         ' VTable offset = 28
     BYVAL lNumQueries AS LONG _                        ' __in long lNumQueries
   , BYREF awszQueries AS WSTRINGZ _                    ' __in const LPCWSTR *awszQueries
   , BYVAL pCallback AS IUnknown _                      ' __in IUnknown *pCallback
   , BYREF ppSink AS IWbemEventSink _                   ' __out IWbemEventSink **ppSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBatchingParameters ( _                     ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   , BYVAL dwMaxBufferSize AS DWORD _                   ' __in DWORD dwMaxBufferSize
   , BYVAL dwMaxSendLatency AS DWORD _                  ' __in DWORD dwMaxSendLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWbemEventSink_INTERFACE_DEFINED__ */
