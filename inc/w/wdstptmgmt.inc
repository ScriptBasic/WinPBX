' ########################################################################################
' Microsoft Windows
' File: WdsTptMgmt.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WdsTptMgmtLib
' Version: 1.0, Locale ID = 0
' Documentation string: WdsTptMgmt 1.0 Type Library
' Library GUID: {9212887F-F5BC-45DD-A510-265413A18ED7}
' ########################################################################################

#INCLUDE THIS ONCE
%WDSTPTMGMT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WdsTransportCacheable = GUID$("{70590B16-F146-46BD-BD9D-4AAA90084BF5}")
$CLSID_WdsTransportClient = GUID$("{66D2C5E9-0FF6-49EC-9733-DAFB1E01DF1C}")
$CLSID_WdsTransportCollection = GUID$("{C7F18B09-391E-436E-B10B-C3EF46F2C34F}")
$CLSID_WdsTransportConfigurationManager = GUID$("{8743F674-904C-47CA-8512-35FE98F6B0AC}")
$CLSID_WdsTransportContent = GUID$("{0A891FE7-4A3F-4C65-B6F2-1467619679EA}")
$CLSID_WdsTransportDiagnosticsPolicy = GUID$("{EB3333E1-A7AD-46F5-80D6-6B740204E509}")
$CLSID_WdsTransportManager = GUID$("{F21523F6-837C-4A58-AF99-8A7E27F8FF59}")
$CLSID_WdsTransportMulticastSessionPolicy = GUID$("{3C6BC3F4-6418-472A-B6F1-52D457195437}")
$CLSID_WdsTransportNamespace = GUID$("{D8385768-0732-4EC1-95EA-16DA581908A1}")
$CLSID_WdsTransportNamespaceAutoCast = GUID$("{B091F5A8-6A99-478D-B23B-09E8FEE04574}")
$CLSID_WdsTransportNamespaceManager = GUID$("{F08CDB63-85DE-4A28-A1A9-5CA3E7EFDA73}")
$CLSID_WdsTransportNamespaceScheduledCast = GUID$("{BADC1897-7025-44EB-9108-FB61C4055792}")
$CLSID_WdsTransportNamespaceScheduledCastAutoStart = GUID$("{A1107052-122C-4B81-9B7C-386E6855383F}")
$CLSID_WdsTransportNamespaceScheduledCastManualStart = GUID$("{D3E1A2AA-CAAC-460E-B98A-47F9F318A1FA}")
$CLSID_WdsTransportServer = GUID$("{EA19B643-4ADF-4413-942C-14F379118760}")
$CLSID_WdsTransportServicePolicy = GUID$("{65ACEADC-2F0B-4F43-9F4D-811865D8CEAD}")
$CLSID_WdsTransportSession = GUID$("{749AC4E0-67BC-4743-BFE5-CACB1F26F57F}")
$CLSID_WdsTransportSetupManager = GUID$("{C7BEEAAD-9F04-4923-9F0C-FBF52BC7590F}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWdsTransportCacheable = GUID$("{46AD894B-0BAB-47DC-84B2-7B553F1D8F80}")
$IID_IWdsTransportClient = GUID$("{B5DBC93A-CABE-46CA-837F-3E44E93C6545}")
$IID_IWdsTransportCollection = GUID$("{B8BA4B1A-2FF4-43AB-996C-B2B10A91A6EB}")
$IID_IWdsTransportConfigurationManager = GUID$("{84CC4779-42DD-4792-891E-1321D6D74B44}")
$IID_IWdsTransportConfigurationManager2 = GUID$("{D0D85CAF-A153-4F1D-A9DD-96F431C50717}")
$IID_IWdsTransportContent = GUID$("{D405D711-0296-4AB4-A860-AC7D32E65798}")
$IID_IWdsTransportDiagnosticsPolicy = GUID$("{13B33EFC-7856-4F61-9A59-8DE67B6B87B6}")
$IID_IWdsTransportManager = GUID$("{5B0D35F5-1B13-4AFD-B878-6526DC340B5D}")
$IID_IWdsTransportMulticastSessionPolicy = GUID$("{4E5753CF-68EC-4504-A951-4A003266606B}")
$IID_IWdsTransportNamespace = GUID$("{FA561F57-FBEF-4ED3-B056-127CB1B33B84}")
$IID_IWdsTransportNamespaceAutoCast = GUID$("{AD931A72-C4BD-4C41-8FBC-59C9C748DF9E}")
$IID_IWdsTransportNamespaceManager = GUID$("{3E22D9F6-3777-4D98-83E1-F98696717BA3}")
$IID_IWdsTransportNamespaceScheduledCast = GUID$("{3840CECF-D76C-416E-A4CC-31C741D2874B}")
$IID_IWdsTransportNamespaceScheduledCastAutoStart = GUID$("{D606AF3D-EA9C-4219-961E-7491D618D9B9}")
$IID_IWdsTransportNamespaceScheduledCastManualStart = GUID$("{013E6E4C-E6A7-4FB5-B7FF-D9F5DA805C31}")
$IID_IWdsTransportServer = GUID$("{09CCD093-830D-4344-A30A-73AE8E8FCA90}")
$IID_IWdsTransportServicePolicy = GUID$("{B9468578-9F2B-48CC-B27A-A60799C2750C}")
$IID_IWdsTransportSession = GUID$("{F4EFEA88-65B1-4F30-A4B9-2793987796FB}")
$IID_IWdsTransportSetupManager = GUID$("{F7238425-EFA8-40A4-AEF9-C98D969C0B75}")

' enum WDSTRANSPORT_FEATURE_FLAGS
%WdsTptFeatureAdminPack                      = &H1???
%WdsTptFeatureTransportServer                = &H2???
%WdsTptFeatureDeploymentServer               = &H4???

%WDSTRANSPORT_FEATURE_FLAGS_ALL              = %WdsTptFeatureAdminPack OR %WdsTptFeatureTransportServer OR %WdsTptFeatureDeploymentServer

' enum WDSTRANSPORT_PROTOCOL_FLAGS
%WdsTptProtocolUnicast                       = &H1???
%WdsTptProtocolMulticast                     = &H2???

' enum WDSTRANSPORT_NAMESPACE_TYPE
%WdsTptNamespaceTypeUnknown                  = 0
%WdsTptNamespaceTypeAutoCast                 = 1
%WdsTptNamespaceTypeScheduledCastManualStart = 2
%WdsTptNamespaceTypeScheduledCastAutoStart   = 3

' enum WDSTRANSPORT_DISCONNECT_TYPE
%WdsTptDisconnectUnknown                     = 0
%WdsTptDisconnectFallback                    = 1
%WdsTptDisconnectAbort                       = 2

' enum WDSTRANSPORT_SERVICE_NOTIFICATION
%WdsTptServiceNotifyUnknown                  = 0
%WdsTptServiceNotifyReadSettings             = 1

' enum WDSTRANSPORT_IP_ADDRESS_TYPE
%WdsTptIpAddressUnknown                      = 0
%WdsTptIpAddressIpv4                         = 1
%WdsTptIpAddressIpv6                         = 2

' enum WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE
%WdsTptIpAddressSourceUnknown                = 0
%WdsTptIpAddressSourceDhcp                   = 1
%WdsTptIpAddressSourceRange                  = 2

' enum WDSTRANSPORT_NETWORK_PROFILE_TYPE
%WdsTptNetworkProfileUnknown                 = 0
%WdsTptNetworkProfileCustom                  = 1
%WdsTptNetworkProfile10Mbps                  = 2
%WdsTptNetworkProfile100Mbps                 = 3
%WdsTptNetworkProfile1Gbps                   = 4

' enum WDSTRANSPORT_DIAGNOSTICS_COMPONENT_FLAGS
%WdsTptDiagnosticsComponentPxe               = &H1???
%WdsTptDiagnosticsComponentTftp              = &H2???
%WdsTptDiagnosticsComponentImageServer       = &H4???
%WdsTptDiagnosticsComponentMulticast         = &H8???

%WDSTRANSPORT_DIAGNOSTICS_COMPONENT_FLAGS_ALL = %WdsTptDiagnosticsComponentPxe OR %WdsTptDiagnosticsComponentTftp OR %WdsTptDiagnosticsComponentImageServer OR %WdsTptDiagnosticsComponentMulticast
%WDSTRANSPORT_RESOURCE_UTILIZATION_UNKNOWN = &HFF

' enum WDSTRANSPORT_SLOW_CLIENT_HANDLING_TYPE
%WdsTptSlowClientHandlingUnknown             = 0
%WdsTptSlowClientHandlingNone                = 1
%WdsTptSlowClientHandlingAutoDisconnect      = 2
%WdsTptSlowClientHandlingMultistream         = 3

' ########################################################################################
' Interface name = IWdsTransportCacheable
' IID = {46AD894B-0BAB-47DC-84B2-7B553F1D8F80}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportCacheable_INTERFACE_DEFINED)
    %IWdsTransportCacheable_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportCacheable $IID_IWdsTransportCacheable

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Dirty <101> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDirty
   ' =====================================================================================
   METHOD Discard <102> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <103> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <104> ( _                              ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportCacheable_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportCollection
' IID = {B8BA4B1A-2FF4-43AB-996C-B2B10A91A6EB}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportCollection_INTERFACE_DEFINED)
    %IWdsTransportCollection_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportCollection $IID_IWdsTransportCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS DWORD                                           ' __retval_out ULONG *pulCount
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 32
     BYVAL ulIndex AS DWORD _                           ' __in ulIndex ULONG
   ) AS IDispatch                                       ' __retval_out IDispatch **ppVal
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportManager
' IID = {5B0D35F5-1B13-4AFD-B878-6526DC340B5D}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportManager_INTERFACE_DEFINED)
    %IWdsTransportManager_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportManager $IID_IWdsTransportManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetWdsTransportServer <1> ( _                 ' VTable offset = 28
     BYVAL bszServerName AS WSTRING _                   ' __in BSTR bszServerName VT_BSTR
   ) AS IWdsTransportServer                             ' __retval_out IWdsTransportServer **ppWdsTransportServer
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportServer
' IID = {09CCD093-830D-4344-A30A-73AE8E8FCA90}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportServer_INTERFACE_DEFINED)
    %IWdsTransportServer_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportServer $IID_IWdsTransportServer

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbszName
   ' =====================================================================================
   PROPERTY GET SetupManager <2> ( _                    ' VTable offset = 32
   ) AS IWdsTransportSetupManager                       ' __retval_out IWdsTransportSetupManager **ppWdsTransportSetupManager
   ' =====================================================================================
   PROPERTY GET ConfigurationManager <3> ( _            ' VTable offset = 36
   ) AS IWdsTransportConfigurationManager               ' __retval_out IWdsTransportConfigurationManager **ppWdsTransportConfigurationManager
   ' =====================================================================================
   PROPERTY GET NamespaceManager <4> ( _                ' VTable offset = 40
   ) AS IWdsTransportNamespaceManager                   ' __retval_out IWdsTransportNamespaceManager **ppWdsTransportNamespaceManager
   ' =====================================================================================
   METHOD DisconnectClient <5> ( _                      ' VTable offset = 44
     BYVAL ulClientId AS DWORD _                        ' __in ulClientId ULONG
   , BYVAL DisconnectionType AS LONG _                  ' __out DisconnectionType WDSTRANSPORT_DISCONNECT_TYPE <alias> __MIDL___MIDL_itf_wdstptmgmt_0000_0000_0004
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportSetupManager
' IID = {F7238425-EFA8-40A4-AEF9-C98D969C0B75}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportSetupManager_INTERFACE_DEFINED)
    %IWdsTransportSetupManager_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportSetupManager $IID_IWdsTransportSetupManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Version <1> ( _                         ' VTable offset = 28
   ) AS QUAD                                            ' __retval_out ULONGLONG *pullVersion
   ' =====================================================================================
   PROPERTY GET InstalledFeatures <2> ( _               ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *pulInstalledFeatures
   ' =====================================================================================
   PROPERTY GET Protocols <3> ( _                       ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out ULONG *pulProtocols
   ' =====================================================================================
   METHOD RegisterContentProvider <4> ( _               ' VTable offset = 40
     BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   , BYVAL bszDescription AS WSTRING _                  ' __in BSTR bszDescription
   , BYVAL bszFilePath AS WSTRING _                     ' __in BSTR bszFilePath
   , BYVAL bszInitializationRoutine AS WSTRING _        ' __in BSTR bszInitializationRoutine
   )                                                    ' void
   ' =====================================================================================
   METHOD DeregisterContentProvider <5> ( _             ' VTable offset = 44
     BYVAL bszName AS WSTRING _                         ' __in BSTR bszName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportSetupManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportConfigurationManager
' IID = {84CC4779-42DD-4792-891E-1321D6D74B44}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportConfigurationManager_INTERFACE_DEFINED)
    %IWdsTransportConfigurationManager_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportConfigurationManager $IID_IWdsTransportConfigurationManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ServicePolicy <1> ( _                   ' VTable offset = 28
   ) AS IWdsTransportServicePolicy                      ' __retval_out IWdsTransportServicePolicy **ppWdsTransportServicePolicy
   ' =====================================================================================
   PROPERTY GET DiagnosticsPolicy <2> ( _               ' VTable offset = 32
   ) AS IWdsTransportDiagnosticsPolicy                  ' __retval_out IWdsTransportDiagnosticsPolicy **ppWdsTransportDiagnosticsPolicy
   ' =====================================================================================
   PROPERTY GET WdsTransportServicesRunning <3> ( _     ' VTable offset = 36
     BYVAL bRealtimeStatus AS INTEGER _                 ' __in VARIANT_BOOL bRealtimeStatus
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbServicesRunning
   ' =====================================================================================
   METHOD EnableWdsTransportServices <4> ( _            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableWdsTransportServices <5> ( _           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD StartWdsTransportServices <6> ( _             ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD StopWdsTransportServices <7> ( _              ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD RestartWdsTransportServices <8> ( _           ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD NotifyWdsTransportServices <9> ( _            ' VTable offset = 60
     BYVAL ServiceNotification AS LONG _                ' __in WDSTRANSPORT_SERVICE_NOTIFICATION ServiceNotification
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportConfigurationManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportConfigurationManager2
' IID = {D0D85CAF-A153-4F1D-A9DD-96F431C50717}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportConfigurationManager
' ########################################################################################

#IF NOT %DEF(%IWdsTransportConfigurationManager2_INTERFACE_DEFINED)
    %IWdsTransportConfigurationManager2_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportConfigurationManager2 $IID_IWdsTransportConfigurationManager2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportConfigurationManager methods
   ' =====================================================================================
   PROPERTY GET ServicePolicy <1> ( _                   ' VTable offset = 28
   ) AS IWdsTransportServicePolicy                      ' __retval_out IWdsTransportServicePolicy **ppWdsTransportServicePolicy
   ' =====================================================================================
   PROPERTY GET DiagnosticsPolicy <2> ( _               ' VTable offset = 32
   ) AS IWdsTransportDiagnosticsPolicy                  ' __retval_out IWdsTransportDiagnosticsPolicy **ppWdsTransportDiagnosticsPolicy
   ' =====================================================================================
   PROPERTY GET WdsTransportServicesRunning <3> ( _     ' VTable offset = 36
     BYVAL bRealtimeStatus AS INTEGER _                 ' __in VARIANT_BOOL bRealtimeStatus
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbServicesRunning
   ' =====================================================================================
   METHOD EnableWdsTransportServices <4> ( _            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD DisableWdsTransportServices <5> ( _           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD StartWdsTransportServices <6> ( _             ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD StopWdsTransportServices <7> ( _              ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD RestartWdsTransportServices <8> ( _           ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD NotifyWdsTransportServices <9> ( _            ' VTable offset = 60
     BYVAL ServiceNotification AS LONG _                ' __in WDSTRANSPORT_SERVICE_NOTIFICATION ServiceNotification
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportConfigurationManager2 methods
   ' =====================================================================================
   PROPERTY GET MulticastSessionPolicy <10> ( _         ' VTable offset = 64
   ) AS IWdsTransportMulticastSessionPolicy             ' __retval_out IWdsTransportMulticastSessionPolicy **ppWdsTransportMulticastSessionPolicy
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportConfigurationManager2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespaceManager
' IID = {3E22D9F6-3777-4D98-83E1-F98696717BA3}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespaceManager_INTERFACE_DEFINED)
    %IWdsTransportNamespaceManager_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespaceManager $IID_IWdsTransportNamespaceManager

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CreateNamespace <1> ( _                       ' VTable offset = 28
     BYVAL NamespaceType AS LONG _                      ' __in WDSTRANSPORT_NAMESPACE_TYPE NamespaceType
   , BYVAL bszNamespaceName AS WSTRING _                ' __in BSTR bszNamespaceName
   , BYVAL bszContentProvider AS WSTRING _              ' __in BSTR bszContentProvider
   , BYVAL bszConfiguration AS WSTRING _                ' __in BSTR bszConfiguration
   ) AS IWdsTransportNamespace                          ' __retval_out IWdsTransportNamespace **ppWdsTransportNamespace
   ' =====================================================================================
   METHOD RetrieveNamespace <2> ( _                     ' VTable offset = 32
     BYVAL bszNamespaceName AS WSTRING _                ' __BSTR in bszNamespaceName
   ) AS IWdsTransportNamespace                          ' __retval_out IWdsTransportNamespace **ppWdsTransportNamespace
   ' =====================================================================================
   METHOD RetrieveNamespaces <3> ( _                    ' VTable offset = 36
     BYVAL bszContentProvider AS WSTRING _              ' __in BSTR bszContentProvider
   , BYVAL bszNamespaceName AS WSTRING _                ' __in BSTR bszNamespaceName
   , BYVAL bIncludeTombstones AS INTEGER _              ' __in VARIANT_BOOL bIncludeTombstones
   ) AS IWdsTransportCollection                         ' __retval_out IWdsTransportCollection **ppWdsTransportNamespaces
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespaceManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportServicePolicy
' IID = {B9468578-9F2B-48CC-B27A-A60799C2750C}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportCacheable
' ########################################################################################

#IF NOT %DEF(%IWdsTransportServicePolicy_INTERFACE_DEFINED)
    %IWdsTransportServicePolicy_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportServicePolicy $IID_IWdsTransportServicePolicy

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportCacheable methods
   ' =====================================================================================
   PROPERTY GET Dirty <101> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDirty
   ' =====================================================================================
   METHOD Discard <102> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <103> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <104> ( _                              ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportServicePolicy methods
   ' =====================================================================================
   PROPERTY GET IpAddressSource <1> ( _                 ' VTable offset = 44
     BYVAL AddressType AS LONG _                        ' __in WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   ) AS LONG                                            ' __retval_out WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE *pSourceType
   ' =====================================================================================
   PROPERTY SET IpAddressSource <1> ( _                 ' VTable offset = 48
     BYVAL AddressType AS LONG _                        ' __in WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   , BYVAL prm2 AS LONG _                               ' __in WDSTRANSPORT_IP_ADDRESS_SOURCE_TYPE SourceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartIpAddress <2> ( _                  ' VTable offset = 52
     BYVAL AddressType AS LONG _                        ' __in AddressType WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   ) AS WSTRING                                         ' __retval_out BSTR *pbszStartIpAddress
   ' =====================================================================================
   PROPERTY SET StartIpAddress <2> ( _                  ' VTable offset = 56
     BYVAL AddressType AS LONG _                        ' __in WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   , BYVAL prm2 AS WSTRING _                            ' __in BSTR bszStartIpAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndIpAddress <3> ( _                    ' VTable offset = 60
     BYVAL AddressType AS LONG _                        ' __in WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   ) AS WSTRING                                         ' __retval_out BSTR *pbszEndIpAddress
   ' =====================================================================================
   PROPERTY SET EndIpAddress <3> ( _                    ' VTable offset = 64
     BYVAL AddressType AS LONG _                        ' __in WDSTRANSPORT_IP_ADDRESS_TYPE AddressType
   , BYVAL prm2 AS WSTRING _                            ' __in BSTR bszEndIpAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartPort <4> ( _                       ' VTable offset = 68
   ) AS DWORD                                           ' __retval_out ULONG *pulStartPort
   ' =====================================================================================
   PROPERTY SET StartPort <4> ( _                       ' VTable offset = 72
     BYVAL prm1 AS DWORD _                              ' __in ULONG ulStartPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EndPort <5> ( _                         ' VTable offset = 76
   ) AS DWORD                                           ' __retval_out ULONG *pulEndPort
   ' =====================================================================================
   PROPERTY SET EndPort <5> ( _                         ' VTable offset = 80
     BYVAL prm1 AS DWORD _                              ' __in ULONG ulEndPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NetworkProfile <6> ( _                  ' VTable offset = 84
   ) AS LONG                                            ' __retval_out WDSTRANSPORT_NETWORK_PROFILE_TYPE *pProfileType
   ' =====================================================================================
   PROPERTY SET NetworkProfile <6> ( _                  ' VTable offset = 88
     BYVAL prm1 AS LONG _                               ' __in WDSTRANSPORT_NETWORK_PROFILE_TYPE ProfileType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportServicePolicy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportDiagnosticsPolicy
' IID = {13B33EFC-7856-4F61-9A59-8DE67B6B87B6}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportCacheable
' ########################################################################################

#IF NOT %DEF(%IWdsTransportDiagnosticsPolicy_INTERFACE_DEFINED)
    %IWdsTransportDiagnosticsPolicy_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportDiagnosticsPolicy $IID_IWdsTransportDiagnosticsPolicy

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportCacheable methods
   ' =====================================================================================
   PROPERTY GET Dirty <101> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDirty
   ' =====================================================================================
   METHOD Discard <102> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <103> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <104> ( _                              ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportDiagnosticsPolicy methods
   ' =====================================================================================
   PROPERTY GET Enabled <1> ( _                         ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
   ' =====================================================================================
   PROPERTY SET Enabled <1> ( _                         ' VTable offset = 48
     BYVAL prm1 AS INTEGER _                            ' __in bEnabled VARIANT_BOOL
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Components <2> ( _                      ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out ULONG *pulComponents
   ' =====================================================================================
   PROPERTY SET Components <2> ( _                      ' VTable offset = 56
     BYVAL prm1 AS DWORD _                              ' __in ulComponents ULONG
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportDiagnosticsPolicy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportMulticastSessionPolicy
' IID = {4E5753CF-68EC-4504-A951-4A003266606B}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportCacheable
' ########################################################################################

#IF NOT %DEF(%IWdsTransportMulticastSessionPolicy_INTERFACE_DEFINED)
    %IWdsTransportMulticastSessionPolicy_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportMulticastSessionPolicy $IID_IWdsTransportMulticastSessionPolicy

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportCacheable methods
   ' =====================================================================================
   PROPERTY GET Dirty <101> ( _                         ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDirty
   ' =====================================================================================
   METHOD Discard <102> ( _                             ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <103> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD Commit <104> ( _                              ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportMulticastSessionPolicy methods
   ' =====================================================================================
   PROPERTY GET SlowClientHandling <1> ( _              ' VTable offset = 44
   ) AS LONG                                            ' __retval_out WDSTRANSPORT_SLOW_CLIENT_HANDLING_TYPE *pSlowClientHandling
   ' =====================================================================================
   PROPERTY SET SlowClientHandling <1> ( _              ' VTable offset = 48
     BYVAL prm1 AS LONG _                               ' __in WDSTRANSPORT_SLOW_CLIENT_HANDLING_TYPE SlowClientHandling
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoDisconnectThreshold <2> ( _         ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out ULONG *pulThreshold
   ' =====================================================================================
   PROPERTY SET AutoDisconnectThreshold <2> ( _         ' VTable offset = 56
     BYVAL prm1 AS DWORD _                              ' __in ULONG ulThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MultistreamStreamCount <3> ( _          ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out ULONG *pulStreamCount
   ' =====================================================================================
   PROPERTY SET MultistreamStreamCount <3> ( _          ' VTable offset = 64
     BYVAL prm1 AS DWORD _                              ' __in ULONG ulStreamCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SlowClientFallback <4> ( _              ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbClientFallback
   ' =====================================================================================
   PROPERTY SET SlowClientFallback <4> ( _              ' VTable offset = 72
     BYVAL prm1 AS INTEGER _                            ' __in VARIANT_BOOL bClientFallback
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportMulticastSessionPolicy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespace
' IID = {FA561F57-FBEF-4ED3-B056-127CB1B33B84}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespace_INTERFACE_DEFINED)
    %IWdsTransportNamespace_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespace $IID_IWdsTransportNamespace

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out WDSTRANSPORT_NAMESPACE_TYPE *pType
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *pulId
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbszName
   ' =====================================================================================
   PROPERTY SET Name <3> ( _                            ' VTable offset = 40
     BYVAL pbszName AS WSTRING _                        ' __in BSTR pbszName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbszFriendlyName
   ' =====================================================================================
   PROPERTY SET FriendlyName <4> ( _                    ' VTable offset = 48
     BYVAL pbszFriendlyName AS WSTRING _                ' __in BSTR pbszFriendlyName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbszDescription
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 56
     BYVAL pbszDescription AS WSTRING _                 ' __in BSTR pbszDescription
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentProvider <6> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbszContentProvider
   ' =====================================================================================
   PROPERTY SET ContentProvider <6> ( _                 ' VTable offset = 64
     BYVAL pbszContentProvider AS WSTRING _             ' __in BSTR pbszContentProvider
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbszConfiguration
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 72
     BYVAL pbszConfiguration AS WSTRING _               ' __in BSTR pbszConfiguration
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Registered <8> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRegistered
   ' =====================================================================================
   PROPERTY GET Tombstoned <9> ( _                      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbTombstoned
   ' =====================================================================================
   PROPERTY GET TombstoneTime <10> ( _                  ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out DATE *pTombstoneTime
   ' =====================================================================================
   PROPERTY GET TransmissionStarted <11> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbTransmissionStarted
   ' =====================================================================================
   METHOD Register <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Deregister <13> ( _                           ' VTable offset = 96
     BYVAL bTerminateSessions AS INTEGER _              ' __in VARIANT_BOOL bTerminateSessions
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <14> ( _                                ' VTable offset = 100
   ) AS IWdsTransportNamespace                          ' __retval_out IWdsTransportNamespace **ppWdsTransportNamespaceClone
   ' =====================================================================================
   METHOD Refresh <15> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD RetrieveContents <16> ( _                     ' VTable offset = 108
   ) AS IWdsTransportCollection                         ' __retval_out IWdsTransportCollection **ppWdsTransportContents
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespace_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespaceAutoCast
' IID = {AD931A72-C4BD-4C41-8FBC-59C9C748DF9E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportNamespace
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespaceAutoCast_INTERFACE_DEFINED)
    %IWdsTransportNamespaceAutoCast_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespaceAutoCast $IID_IWdsTransportNamespaceAutoCast

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportNamespace Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *pType WDSTRANSPORT_NAMESPACE_TYPE <alias> __MIDL___MIDL_itf_wdstptmgmt_0000_0000_0003
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out *pulId VT_UI4 <Dword>
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out *pbszName VT_BSTR
   ' =====================================================================================
   PROPERTY SET Name <3> ( _                            ' VTable offset = 40
     BYVAL pbszName AS WSTRING _                        ' __in pbszName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *pbszFriendlyName VT_BSTR
   ' =====================================================================================
   PROPERTY SET FriendlyName <4> ( _                    ' VTable offset = 48
     BYVAL pbszFriendlyName AS WSTRING _                ' __in pbszFriendlyName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out *pbszDescription VT_BSTR
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 56
     BYVAL pbszDescription AS WSTRING _                 ' __in pbszDescription VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentProvider <6> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out *pbszContentProvider VT_BSTR
   ' =====================================================================================
   PROPERTY SET ContentProvider <6> ( _                 ' VTable offset = 64
     BYVAL pbszContentProvider AS WSTRING _             ' __in pbszContentProvider VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out *pbszConfiguration VT_BSTR
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 72
     BYVAL pbszConfiguration AS WSTRING _               ' __in pbszConfiguration VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Registered <8> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out *pbRegistered VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET Tombstoned <9> ( _                      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out *pbTombstoned VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET TombstoneTime <10> ( _                  ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out *pTombstoneTime VT_DATE <Double>
   ' =====================================================================================
   PROPERTY GET TransmissionStarted <11> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out *pbTransmissionStarted VT_BOOL <Integer>
   ' =====================================================================================
   METHOD Register <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Deregister <13> ( _                           ' VTable offset = 96
     BYVAL bTerminateSessions AS INTEGER _              ' __in bTerminateSessions VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <14> ( _                                ' VTable offset = 100
   ) AS IWdsTransportNamespace                          ' __retval_out **ppWdsTransportNamespaceClone IWdsTransportNamespace <dispinterface>
   ' =====================================================================================
   METHOD Refresh <15> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD RetrieveContents <16> ( _                     ' VTable offset = 108
   ) AS IWdsTransportCollection                         ' __retval_out **ppWdsTransportContents IWdsTransportCollection <dispinterface>
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceAutoCast Methods
   ' =====================================================================================

   ' This interface has not additional methods

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespaceAutoCast_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespaceScheduledCast
' IID = {3840CECF-D76C-416E-A4CC-31C741D2874B}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportNamespace
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespaceScheduledCast_INTERFACE_DEFINED)
    %IWdsTransportNamespaceScheduledCast_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespaceScheduledCast $IID_IWdsTransportNamespaceScheduledCast

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportNamespace Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *pType WDSTRANSPORT_NAMESPACE_TYPE <alias> __MIDL___MIDL_itf_wdstptmgmt_0000_0000_0003
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out *pulId VT_UI4 <Dword>
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out *pbszName VT_BSTR
   ' =====================================================================================
   PROPERTY SET Name <3> ( _                            ' VTable offset = 40
     BYVAL pbszName AS WSTRING _                        ' __in pbszName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *pbszFriendlyName VT_BSTR
   ' =====================================================================================
   PROPERTY SET FriendlyName <4> ( _                    ' VTable offset = 48
     BYVAL pbszFriendlyName AS WSTRING _                ' __in pbszFriendlyName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out *pbszDescription VT_BSTR
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 56
     BYVAL pbszDescription AS WSTRING _                 ' __in pbszDescription VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentProvider <6> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out *pbszContentProvider VT_BSTR
   ' =====================================================================================
   PROPERTY SET ContentProvider <6> ( _                 ' VTable offset = 64
     BYVAL pbszContentProvider AS WSTRING _             ' __in pbszContentProvider VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out *pbszConfiguration VT_BSTR
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 72
     BYVAL pbszConfiguration AS WSTRING _               ' __in pbszConfiguration VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Registered <8> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out *pbRegistered VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET Tombstoned <9> ( _                      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out *pbTombstoned VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET TombstoneTime <10> ( _                  ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out *pTombstoneTime VT_DATE <Double>
   ' =====================================================================================
   PROPERTY GET TransmissionStarted <11> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out *pbTransmissionStarted VT_BOOL <Integer>
   ' =====================================================================================
   METHOD Register <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Deregister <13> ( _                           ' VTable offset = 96
     BYVAL bTerminateSessions AS INTEGER _              ' __in bTerminateSessions VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <14> ( _                                ' VTable offset = 100
   ) AS IWdsTransportNamespace                          ' __retval_out **ppWdsTransportNamespaceClone IWdsTransportNamespace <dispinterface>
   ' =====================================================================================
   METHOD Refresh <15> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD RetrieveContents <16> ( _                     ' VTable offset = 108
   ) AS IWdsTransportCollection                         ' __retval_out **ppWdsTransportContents IWdsTransportCollection <dispinterface>
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceScheduledCast Methods
   ' =====================================================================================
   METHOD StartTransmission <101> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespaceScheduledCast_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespaceScheduledCastManualStart
' IID = {013E6E4C-E6A7-4FB5-B7FF-D9F5DA805C31}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportNamespaceScheduledCast
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespaceScheduledCastManualStart_INTERFACE_DEFINED)
    %IWdsTransportNamespaceScheduledCastManualStart_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespaceScheduledCastManualStart $IID_IWdsTransportNamespaceScheduledCastManualStart

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportNamespace Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *pType WDSTRANSPORT_NAMESPACE_TYPE <alias> __MIDL___MIDL_itf_wdstptmgmt_0000_0000_0003
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out *pulId VT_UI4 <Dword>
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out *pbszName VT_BSTR
   ' =====================================================================================
   PROPERTY SET Name <3> ( _                            ' VTable offset = 40
     BYVAL pbszName AS WSTRING _                        ' __in pbszName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *pbszFriendlyName VT_BSTR
   ' =====================================================================================
   PROPERTY SET FriendlyName <4> ( _                    ' VTable offset = 48
     BYVAL pbszFriendlyName AS WSTRING _                ' __in pbszFriendlyName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out *pbszDescription VT_BSTR
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 56
     BYVAL pbszDescription AS WSTRING _                 ' __in pbszDescription VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentProvider <6> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out *pbszContentProvider VT_BSTR
   ' =====================================================================================
   PROPERTY SET ContentProvider <6> ( _                 ' VTable offset = 64
     BYVAL pbszContentProvider AS WSTRING _             ' __in pbszContentProvider VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out *pbszConfiguration VT_BSTR
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 72
     BYVAL pbszConfiguration AS WSTRING _               ' __in pbszConfiguration VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Registered <8> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out *pbRegistered VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET Tombstoned <9> ( _                      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out *pbTombstoned VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET TombstoneTime <10> ( _                  ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out *pTombstoneTime VT_DATE <Double>
   ' =====================================================================================
   PROPERTY GET TransmissionStarted <11> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out *pbTransmissionStarted VT_BOOL <Integer>
   ' =====================================================================================
   METHOD Register <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Deregister <13> ( _                           ' VTable offset = 96
     BYVAL bTerminateSessions AS INTEGER _              ' __in bTerminateSessions VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <14> ( _                                ' VTable offset = 100
   ) AS IWdsTransportNamespace                          ' __retval_out **ppWdsTransportNamespaceClone IWdsTransportNamespace <dispinterface>
   ' =====================================================================================
   METHOD Refresh <15> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD RetrieveContents <16> ( _                     ' VTable offset = 108
   ) AS IWdsTransportCollection                         ' __retval_out **ppWdsTransportContents IWdsTransportCollection <dispinterface>
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceScheduledCast Methods
   ' =====================================================================================
   METHOD StartTransmission <101> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceScheduledCast Methods
   ' =====================================================================================

   ' This interface has not additional methods

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespaceScheduledCastManualStart_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportNamespaceScheduledCastAutoStart
' IID = {D606AF3D-EA9C-4219-961E-7491D618D9B9}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IWdsTransportNamespaceScheduledCast
' ########################################################################################

#IF NOT %DEF(%IWdsTransportNamespaceScheduledCastAutoStart_INTERFACE_DEFINED)
    %IWdsTransportNamespaceScheduledCastAutoStart_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportNamespaceScheduledCastAutoStart $IID_IWdsTransportNamespaceScheduledCastAutoStart

   INHERIT IDispatch

   ' =====================================================================================
   ' IWdsTransportNamespace Methods
   ' =====================================================================================
   PROPERTY GET Type <1> ( _                            ' VTable offset = 28
   ) AS LONG                                            ' __retval_out *pType WDSTRANSPORT_NAMESPACE_TYPE <alias> __MIDL___MIDL_itf_wdstptmgmt_0000_0000_0003
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out *pulId VT_UI4 <Dword>
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out *pbszName VT_BSTR
   ' =====================================================================================
   PROPERTY SET Name <3> ( _                            ' VTable offset = 40
     BYVAL pbszName AS WSTRING _                        ' __in pbszName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FriendlyName <4> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out *pbszFriendlyName VT_BSTR
   ' =====================================================================================
   PROPERTY SET FriendlyName <4> ( _                    ' VTable offset = 48
     BYVAL pbszFriendlyName AS WSTRING _                ' __in pbszFriendlyName VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Description <5> ( _                     ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out *pbszDescription VT_BSTR
   ' =====================================================================================
   PROPERTY SET Description <5> ( _                     ' VTable offset = 56
     BYVAL pbszDescription AS WSTRING _                 ' __in pbszDescription VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContentProvider <6> ( _                 ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out *pbszContentProvider VT_BSTR
   ' =====================================================================================
   PROPERTY SET ContentProvider <6> ( _                 ' VTable offset = 64
     BYVAL pbszContentProvider AS WSTRING _             ' __in pbszContentProvider VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Configuration <7> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out *pbszConfiguration VT_BSTR
   ' =====================================================================================
   PROPERTY SET Configuration <7> ( _                   ' VTable offset = 72
     BYVAL pbszConfiguration AS WSTRING _               ' __in pbszConfiguration VT_BSTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Registered <8> ( _                      ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out *pbRegistered VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET Tombstoned <9> ( _                      ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out *pbTombstoned VT_BOOL <Integer>
   ' =====================================================================================
   PROPERTY GET TombstoneTime <10> ( _                  ' VTable offset = 84
   ) AS DOUBLE                                          ' __retval_out *pTombstoneTime VT_DATE <Double>
   ' =====================================================================================
   PROPERTY GET TransmissionStarted <11> ( _            ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out *pbTransmissionStarted VT_BOOL <Integer>
   ' =====================================================================================
   METHOD Register <12> ( _                             ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Deregister <13> ( _                           ' VTable offset = 96
     BYVAL bTerminateSessions AS INTEGER _              ' __in bTerminateSessions VT_BOOL <Integer>
   )                                                    ' void
   ' =====================================================================================
   METHOD Clone <14> ( _                                ' VTable offset = 100
   ) AS IWdsTransportNamespace                          ' __retval_out **ppWdsTransportNamespaceClone IWdsTransportNamespace <dispinterface>
   ' =====================================================================================
   METHOD Refresh <15> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================
   METHOD RetrieveContents <16> ( _                     ' VTable offset = 108
   ) AS IWdsTransportCollection                         ' __retval_out **ppWdsTransportContents IWdsTransportCollection <dispinterface>
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceScheduledCast Methods
   ' =====================================================================================
   METHOD StartTransmission <101> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWdsTransportNamespaceScheduledCastAutoStart Methods
   ' =====================================================================================
   PROPERTY GET MinimumClients <201> ( _                ' VTable offset = 116
   ) AS DWORD                                           ' __retval_out ULONG *pulMinimumClients
   ' =====================================================================================
   PROPERTY SET MinimumClients <201> ( _                ' VTable offset = 120
     BYVAL pulMinimumClients AS DWORD _                 ' __in ULONG pulMinimumClients
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StartTime <202> ( _                     ' VTable offset = 124
   ) AS DOUBLE                                          ' __retval_out DATE *pStartTime
   ' =====================================================================================
   PROPERTY SET StartTime <202> ( _                     ' VTable offset = 128
     BYVAL pStartTime AS DOUBLE _                       ' __in DATE pStartTime
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportNamespaceScheduledCastAutoStart_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportContent
' IID = {D405D711-0296-4AB4-A860-AC7D32E65798}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportContent_INTERFACE_DEFINED)
    %IWdsTransportContent_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportContent $IID_IWdsTransportContent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Namespace <1> ( _                       ' VTable offset = 28
   ) AS IWdsTransportNamespace                          ' __retval_out IWdsTransportNamespace **ppWdsTransportNamespace
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *pulId
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbszName
   ' =====================================================================================
   METHOD RetrieveSessions <4> ( _                      ' VTable offset = 40
   ) AS IWdsTransportCollection                         ' __retval_out IWdsTransportCollection **ppWdsTransportSessions
   ' =====================================================================================
   METHOD Terminate <5> ( _                             ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportContent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportSession
' IID = {F4EFEA88-65B1-4F30-A4B9-2793987796FB}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportSession_INTERFACE_DEFINED)
    %IWdsTransportSession_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportSession $IID_IWdsTransportSession

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Content <1> ( _                         ' VTable offset = 28
   ) AS IWdsTransportContent                            ' __retval_out IWdsTransportContent **ppWdsTransportContent
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *pulId
   ' =====================================================================================
   PROPERTY GET NetworkInterfaceName <3> ( _            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbszNetworkInterfaceName
   ' =====================================================================================
   PROPERTY GET NetworkInterfaceAddress <4> ( _         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbszNetworkInterfaceAddress
   ' =====================================================================================
   PROPERTY GET TransferRate <5> ( _                    ' VTable offset = 44
   ) AS DWORD                                           ' __retval_out ULONG *pulTransferRate
   ' =====================================================================================
   PROPERTY GET MasterClientId <6> ( _                  ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG *pulMasterClientId
   ' =====================================================================================
   METHOD RetrieveClients <7> ( _                       ' VTable offset = 52
   ) AS IWdsTransportCollection                         ' __retval_out IWdsTransportCollection **ppWdsTransportClients
   ' =====================================================================================
   METHOD Terminate <8> ( _                             ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportSession_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWdsTransportClient
' IID = {B5DBC93A-CABE-46CA-837F-3E44E93C6545}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWdsTransportClient_INTERFACE_DEFINED)
    %IWdsTransportClient_INTERFACE_DEFINED = 1

INTERFACE IWdsTransportClient $IID_IWdsTransportClient

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Session <1> ( _                         ' VTable offset = 28
   ) AS IWdsTransportSession                            ' __retval_out IWdsTransportSession **ppWdsTransportSession
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS DWORD                                           ' __retval_out ULONG *pulId
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbszName
   ' =====================================================================================
   PROPERTY GET MacAddress <4> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbszMacAddress
   ' =====================================================================================
   PROPERTY GET IpAddress <5> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbszIpAddress
   ' =====================================================================================
   PROPERTY GET PercentCompletion <6> ( _               ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out ULONG *pulPercentCompletion
   ' =====================================================================================
   PROPERTY GET JoinDuration <7> ( _                    ' VTable offset = 52
   ) AS DWORD                                           ' __retval_out ULONG *pulJoinDuration
   ' =====================================================================================
   PROPERTY GET CpuUtilization <8> ( _                  ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out ULONG *pulCpuUtilization
   ' =====================================================================================
   PROPERTY GET MemoryUtilization <9> ( _               ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out ULONG *pulMemoryUtilization
   ' =====================================================================================
   PROPERTY GET NetworkUtilization <10> ( _             ' VTable offset = 64
   ) AS DWORD                                           ' __retval_out ULONG *pulNetworkUtilization
   ' =====================================================================================
   PROPERTY GET UserIdentity <11> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbszUserIdentity
   ' =====================================================================================
   METHOD Disconnect <12> ( _                           ' VTable offset = 72
     BYVAL DisconnectionType AS LONG _                  ' __in WDSTRANSPORT_DISCONNECT_TYPE DisconnectionType
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWdsTransportClient_INTERFACE_DEFINED__ */
