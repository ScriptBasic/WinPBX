' ########################################################################################
' Microsoft Windows
' File: alg.inc
' Library name: ALGLib
' Version: 1.0, Locale ID = 0
' Contents: MyICS 1.0 Type Library
' Library GUID: {B6D1D098-E235-4B99-BA98-7C624FD875DB}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ALG_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_ALGLib = GUID$("{B6D1D098-E235-4B99-BA98-7C624FD875DB}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_AdapterInfo = GUID$("{6F9942C9-C1B1-4AB5-93DA-6058991DC8F3}")
$CLSID_ApplicationGatewayServices = GUID$("{F8ADE1D3-49DF-4B75-9005-EF9508E6A337}")
$CLSID_DataChannel = GUID$("{BBB36F15-408D-4056-8C27-920843D40BE5}")
$CLSID_EnumAdapterInfo = GUID$("{6F9942CA-C1B1-4AB5-93DA-6058991DC8F3}")
$CLSID_PendingProxyConnection = GUID$("{D8A68E5E-2B37-426C-A329-C117C14C429E}")
$CLSID_PersistentDataChannel = GUID$("{BC9B54AB-7883-4C13-909F-033D03267990}")
$CLSID_PrimaryControlChannel = GUID$("{3CEB5509-C1CD-432F-9D8F-65D1E286AA80}")
$CLSID_SecondaryControlChannel = GUID$("{7B3181A0-C92F-4567-B0FA-CD9A10ECD7D1}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAdapterInfo = GUID$("{480BF94A-09FD-4F8A-A3E0-B0700282D84D}")
$IID_IAdapterNotificationSink = GUID$("{44AB2DC3-23B2-47DE-8228-2E1CCEEB9911}")
$IID_IApplicationGateway = GUID$("{5134842B-FDCE-485D-93CD-DE1640643BBE}")
$IID_IApplicationGatewayServices = GUID$("{5134842A-FDCE-485D-93CD-DE1640643BBE}")
$IID_IDataChannel = GUID$("{AD42D12A-4AD0-4856-919E-E854C91D1856}")
$IID_IEnumAdapterInfo = GUID$("{A23F9D11-714C-41FE-8471-FFB19BC28454}")
$IID_IPendingProxyConnection = GUID$("{B68E5043-3E3D-4CC2-B9C1-5F8F88FEE81C}")
$IID_IPersistentDataChannel = GUID$("{A180E934-D92A-415D-9144-759F8054E8F6}")
$IID_IPrimaryControlChannel = GUID$("{1A2E8B62-9012-4BE6-84AE-32BD66BA657A}")
$IID_ISecondaryControlChannel = GUID$("{A23F9D10-714C-41FE-8471-FFB19BC28454}")

' ========================================================================================

%ALG_MAXIMUM_PORT_RANGE_SIZE = 10

' ========================================================================================
' ALG_PROTOCOL enum
' ========================================================================================

MACRO ALG_PROTOCOL_ENUM = LONG
%eALG_TCP                                               = &H1
%eALG_UDP                                               = &H2

' ========================================================================================
' ALG_CAPTURE enum
' ========================================================================================

MACRO ALG_CAPTURE_ENUM = LONG
%eALG_SOURCE_CAPTURE                                    = &H1
%eALG_DESTINATION_CAPTURE                               = &H2

' ========================================================================================
' ALG_DIRECTION enum
' ========================================================================================

MACRO ALG_DIRECTION_ENUM = LONG
%eALG_INBOUND                                           = &H1
%eALG_OUTBOUND                                          = &H2
%eALG_BOTH                                              = &H3

' ========================================================================================
' ALG_ADAPTER_TYPE enum
' ========================================================================================

MACRO ALG_ADAPTER_TYPE_ENUM = LONG
%eALG_PRIVATE                                           = &H1
%eALG_BOUNDARY                                          = &H2
%eALG_FIREWALLED                                        = &H4

' ========================================================================================
' ALG_NOTIFICATION enum
' ========================================================================================

MACRO ALG_NOTIFICATION_ENUM = LONG
%eALG_NONE                                              = 0
%eALG_SESSION_CREATION                                  = &H1
%eALG_SESSION_DELETION                                  = &H2
%eALG_SESSION_BOTH                                      = &H3

' ========================================================================================
' ALG_PRIMARY_CHANNEL_PROPERTIES record
' ========================================================================================
' // Size = 28 bytes
TYPE ALG_PRIMARY_CHANNEL_PROPERTIES DWORD
   eProtocol          AS ALG_PROTOCOL_ENUM    ' ALG_PROTOCOL
   usCapturePort      AS WORD                 ' USHORT
   eCaptureType       AS ALG_CAPTURE_ENUM     ' ALG_CAPTURE
   fCaptureInbound    AS LONG                 ' BOOL
   ulListeningAddress AS DWORD                ' ULONG
   usListeningPort    AS WORD                 ' USHORT
   ulAdapterIndex     AS DWORD                ' ULONG
END TYPE

' ========================================================================================
' ALG_SECONDARY_CHANNEL_PROPERTIES record
' ========================================================================================
' // Size = 44 bytes
TYPE ALG_SECONDARY_CHANNEL_PROPERTIES DWORD
   eProtocol        AS ALG_PROTOCOL_ENUM    ' ALG_PROTOCOL
   ulPrivateAddress AS DWORD                ' ULONG
   usPrivatePort    AS WORD                 ' USHORT
   ulPublicAddress  AS DWORD                ' ULONG
   usPublicPort     AS WORD                 ' USHORT
   ulRemoteAddress  AS DWORD                ' ULONG
   usRemotePort     AS WORD                 ' USHORT
   ulListenAddress  AS DWORD                ' ULONG
   usListenPort     AS WORD                 ' USHORT
   eDirection       AS ALG_DIRECTION_ENUM   ' ALG_DIRECTION
   fPersistent      AS LONG                 ' BOOL
END TYPE

' ========================================================================================
' ALG_DATA_CHANNEL_PROPERTIES record
' ========================================================================================
' // Size = 36 bytes
TYPE ALG_DATA_CHANNEL_PROPERTIES DWORD
   eProtocol            AS ALG_PROTOCOL_ENUM       ' ALG_PROTOCOL
   ulPrivateAddress     AS DWORD                   ' ULONG
   usPrivatePort        AS WORD                    ' USHORT
   ulPublicAddress      AS DWORD                   ' ULONG
   usPublicPort         AS WORD                    ' USHORT
   ulRemoteAddress      AS DWORD                   ' ULONG
   usRemotePort         AS WORD                    ' USHORT
   eDirection           AS ALG_DIRECTION_ENUM      ' ALG_DIRECTION
   eDesiredNotification AS ALG_NOTIFICATION_ENUM   ' ALG_NOTIFICATION
END TYPE

' ========================================================================================
' ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES record
' ========================================================================================
' // Size = 32 bytes
TYPE ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES DWORD
   eProtocol        AS ALG_PROTOCOL_ENUM    ' ALG_PROTOCOL
   ulPrivateAddress AS DWORD                ' ULONG
   usPrivatePort    AS WORD                 ' USHORT
   ulPublicAddress  AS DWORD                ' ULONG
   usPublicPort     AS WORD                 ' USHORT
   ulRemoteAddress  AS DWORD                ' ULONG
   usRemotePort     AS WORD                 ' USHORT
   eDirection       AS ALG_DIRECTION_ENUM   ' ALG_DIRECTION
END TYPE

' ########################################################################################
' Interface name = IAdapterInfo
' IID = {480BF94A-09FD-4F8A-A3E0-B0700282D84D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAdapterInfo_INTERFACE_DEFINED)
    %IAdapterInfo_INTERFACE_DEFINED = 1

INTERFACE IAdapterInfo $IID_IAdapterInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAdapterIndex ( _                           ' VTable offset = 12
     BYREF pulIndex AS DWORD _                          ' __out ULONG *pulIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterType ( _                            ' VTable offset = 16
     BYREF pAdapterType AS ALG_ADAPTER_TYPE_ENUM _      ' __out ALG_ADAPTER_TYPE *pAdapterType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdapterAddresses ( _                       ' VTable offset = 20
     BYREF pulAddressCount AS DWORD _                   ' __out ULONG *pulAddressCount
   , BYREF prgAddresses AS DWORD _                      ' __out ULONG **prgAddresses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdapterInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPendingProxyConnection
' IID = {B68E5043-3E3D-4CC2-B9C1-5F8F88FEE81C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPendingProxyConnection_INTERFACE_DEFINED)
    %IPendingProxyConnection_INTERFACE_DEFINED = 1

INTERFACE IPendingProxyConnection $IID_IPendingProxyConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPendingProxyConnection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDataChannel
' IID = {AD42D12A-4AD0-4856-919E-E854C91D1856}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDataChannel_INTERFACE_DEFINED)
    %IDataChannel_INTERFACE_DEFINED = 1

INTERFACE IDataChannel $IID_IDataChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelProperties ( _                      ' VTable offset = 16
     BYREF ppProperties AS ALG_DATA_CHANNEL_PROPERTIES _ ' __out ALG_DATA_CHANNEL_PROPERTIES **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSessionCreationEventHandle ( _             ' VTable offset = 20
     BYREF pHandle AS DWORD _                           ' __out HANDLE **pHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSessionDeletionEventHandle ( _             ' VTable offset = 24
     BYREF pHandle AS DWORD _                           ' __out HANDLE **pHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDataChannel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPersistentDataChannel
' IID = {A180E934-D92A-415D-9144-759F8054E8F6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPersistentDataChannel_INTERFACE_DEFINED)
    %IPersistentDataChannel_INTERFACE_DEFINED = 1

INTERFACE IPersistentDataChannel $IID_IPersistentDataChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelProperties ( _                      ' VTable offset = 16
     BYREF ppProperties AS ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES _ ' __out ALG_PERSISTENT_DATA_CHANNEL_PROPERTIES **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistentDataChannel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPrimaryControlChannel
' IID = {1A2E8B62-9012-4BE6-84AE-32BD66BA657A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrimaryControlChannel_INTERFACE_DEFINED)
    %IPrimaryControlChannel_INTERFACE_DEFINED = 1

INTERFACE IPrimaryControlChannel $IID_IPrimaryControlChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelProperties ( _                      ' VTable offset = 16
     BYREF ppProperties AS ALG_PRIMARY_CHANNEL_PROPERTIES _ ' __out ALG_PRIMARY_CHANNEL_PROPERTIES **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalDestinationInformation ( _         ' VTable offset = 20
     BYVAL ulSourceAddress AS DWORD _                   ' __in ULONG ulSourceAddress
   , BYVAL usSourcePort AS WORD _                       ' __in USHORT usSourcePort
   , BYREF pulOriginalDestinationAddress AS DWORD _     ' __out ULONG *pulOriginalDestinationAddress
   , BYREF pusOriginalDestinationPort AS WORD _         ' __out USHORT *pusOriginalDestinationPort
   , BYREF pulRemapDestinationAddress AS DWORD _        ' __out ULONG *pulRemapDestinationAddress
   , BYREF pulRemapDestinationPort AS WORD _            ' __out USHORT *pulRemapDestinationPort
   , BYREF ppReceiveAdapter AS IAdapterInfo _           ' __out IAdapterInfo **ppReceiveAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrimaryControlChannel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISecondaryControlChannel
' IID = {A23F9D10-714C-41FE-8471-FFB19BC28454}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISecondaryControlChannel_INTERFACE_DEFINED)
    %ISecondaryControlChannel_INTERFACE_DEFINED = 1

INTERFACE ISecondaryControlChannel $IID_ISecondaryControlChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelProperties ( _                      ' VTable offset = 16
     BYREF ppProperties AS ALG_SECONDARY_CHANNEL_PROPERTIES _ ' __out ALG_SECONDARY_CHANNEL_PROPERTIES **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalDestinationInformation ( _         ' VTable offset = 20
     BYVAL ulSourceAddress AS DWORD _                   ' __in ULONG ulSourceAddress
   , BYVAL usSourcePort AS WORD _                       ' __in USHORT usSourcePort
   , BYREF pulOriginalDestinationAddress AS DWORD _     ' __out ULONG *pulOriginalDestinationAddress
   , BYREF pusOriginalDestinationPort AS WORD _         ' __out USHORT *pusOriginalDestinationPort
   , BYREF ppReceiveAdapter AS IAdapterInfo _           ' __out IAdapterInfo **ppReceiveAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISecondaryControlChannel_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IEnumAdapterInfo
' IID = {A23F9D11-714C-41FE-8471-FFB19BC28454}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAdapterInfo_INTERFACE_DEFINED)
    %IEnumAdapterInfo_INTERFACE_DEFINED = 1

INTERFACE IEnumAdapterInfo $IID_IEnumAdapterInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgAI AS IAdapterInfo _                       ' __out IAdapterInfo **rgAI
   , BYREF pCeltFetched AS DWORD _                      ' __out ULONG *pCeltFetched
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
     BYREF ppEnum AS IEnumAdapterInfo _                 ' __out IEnumAdapterInfo **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAdapterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAdapterNotificationSink
' IID = {44AB2DC3-23B2-47DE-8228-2E1CCEEB9911}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAdapterNotificationSink_INTERFACE_DEFINED)
    %IAdapterNotificationSink_INTERFACE_DEFINED = 1

INTERFACE IAdapterNotificationSink $IID_IAdapterNotificationSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdapterAdded ( _                              ' VTable offset = 12
     BYVAL pAdapter AS IAdapterInfo _                   ' __in IAdapterInfo *pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdapterRemoved ( _                            ' VTable offset = 16
     BYVAL pAdapter AS IAdapterInfo _                   ' __in IAdapterInfo *pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdapterModified ( _                           ' VTable offset = 20
     BYVAL pAdapter AS IAdapterInfo _                   ' __in IAdapterInfo *pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdapterUpdatePortMapping ( _                  ' VTable offset = 24
     BYVAL pAdapter AS IAdapterInfo _                   ' __in IAdapterInfo *pAdapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAdapterNotificationSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApplicationGatewayServices
' IID = {5134842A-FDCE-485D-93CD-DE1640643BBE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationGatewayServices_INTERFACE_DEFINED)
    %IApplicationGatewayServices_INTERFACE_DEFINED = 1

INTERFACE IApplicationGatewayServices $IID_IApplicationGatewayServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePrimaryControlChannel ( _               ' VTable offset = 12
     BYVAL uAdapterIndex AS DWORD _                     ' __in ULONG uAdapterIndex
   , BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL usPortToCapture AS WORD _                    ' __in USHORT usPortToCapture
   , BYVAL eCaptureType AS ALG_CAPTURE_ENUM _           ' __in ALG_CAPTURE eCaptureType
   , BYVAL fCaptureInbound AS LONG _                    ' __in BOOL fCaptureInbound
   , BYVAL ulListenAddress AS DWORD _                   ' __in ULONG ulListenAddress
   , BYVAL usListenPort AS WORD _                       ' __in USHORT usListenPort
   , BYREF ppIControlChannel AS IPrimaryControlChannel _ ' __out IPrimaryControlChannel **ppIControlChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSecondaryControlChannel ( _             ' VTable offset = 16
     BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL ulPrivateAddress AS DWORD _                  ' __in ULONG ulPrivateAddress
   , BYVAL usPrivatePort AS WORD _                      ' __in USHORT usPrivatePort
   , BYVAL ulPublicAddress AS DWORD _                   ' __in ULONG ulPublicAddress
   , BYVAL usPublicPort AS WORD _                       ' __in USHORT usPublicPort
   , BYVAL ulRemoteAddress AS DWORD _                   ' __in ULONG ulRemoteAddress
   , BYVAL usRemotePort AS WORD _                       ' __in USHORT usRemotePort
   , BYVAL ulListenAddress AS DWORD _                   ' __in ULONG ulListenAddress
   , BYVAL usListenPort AS WORD _                       ' __in USHORT usListenPort
   , BYVAL eDirection AS ALG_DIRECTION_ENUM _           ' __in ALG_DIRECTION eDirection
   , BYVAL fPersistent AS LONG _                        ' __in BOOL fPersistent
   , BYREF ppControlChannel AS ISecondaryControlChannel _ ' __out ISecondaryControlChannel **ppControlChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBestSourceAddressForDestinationAddress ( _  ' VTable offset = 20
     BYVAL ulDstAddress AS DWORD _                      ' __in ULONG ulDstAddress
   , BYVAL fDemandDial AS LONG _                        ' __in BOOL fDemandDial
   , BYREF pulBestSrcAddress AS DWORD _                 ' __out ULONG *pulBestSrcAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareProxyConnection ( _                    ' VTable offset = 24
     BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL ulSrcAddress AS DWORD _                      ' __in ULONG ulSrcAddress
   , BYVAL usSrcPort AS WORD _                          ' __in USHORT usSrcPort
   , BYVAL ulDstAddress AS DWORD _                      ' __in ULONG ulDstAddress
   , BYVAL usDstPort AS WORD _                          ' __in USHORT usDstPort
   , BYVAL fNoTimeout AS LONG _                         ' __in BOOL fNoTimeout
   , BYREF ppPendingConnection AS IPendingProxyConnection _ ' __out IPendingProxyConnection **ppPendingConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareSourceModifiedProxyConnection ( _      ' VTable offset = 28
     BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL ulSrcAddress AS DWORD _                      ' __in ULONG ulSrcAddress
   , BYVAL usSrcPort AS WORD _                          ' __in USHORT usSrcPort
   , BYVAL ulDstAddress AS DWORD _                      ' __in ULONG ulDstAddress
   , BYVAL usDstPort AS WORD _                          ' __in USHORT usDstPort
   , BYVAL ulNewSrcAddress AS DWORD _                   ' __in ULONG ulNewSrcAddress
   , BYVAL usNewSourcePort AS WORD _                    ' __in USHORT usNewSourcePort
   , BYREF ppPendingConnection AS IPendingProxyConnection _ ' __out IPendingProxyConnection **ppPendingConnection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDataChannel ( _                         ' VTable offset = 32
     BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL ulPrivateAddress AS DWORD _                  ' __in ULONG ulPrivateAddress
   , BYVAL usPrivatePort AS WORD _                      ' __in USHORT usPrivatePort
   , BYVAL ulPublicAddress AS DWORD _                   ' __in ULONG ulPublicAddress
   , BYVAL usPublicPort AS WORD _                       ' __in USHORT usPublicPort
   , BYVAL ulRemoteAddress AS DWORD _                   ' __in ULONG ulRemoteAddress
   , BYVAL usRemotePort AS WORD _                       ' __in USHORT usRemotePort
   , BYVAL eDirection AS ALG_DIRECTION_ENUM _           ' __in ALG_DIRECTION eDirection
   , BYVAL eDesiredNotification AS ALG_NOTIFICATION_ENUM _ ' __in ALG_NOTIFICATION eDesiredNotification
   , BYVAL fNoTimeout AS LONG _                         ' __in BOOL fNoTimeout
   , BYREF ppDataChannel AS IDataChannel _              ' __out IDataChannel **ppDataChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePersistentDataChannel ( _               ' VTable offset = 36
     BYVAL eProtocol AS ALG_PROTOCOL_ENUM _             ' __in ALG_PROTOCOL eProtocol
   , BYVAL ulPrivateAddress AS DWORD _                  ' __in ULONG ulPrivateAddress
   , BYVAL usPrivatePort AS WORD _                      ' __in USHORT usPrivatePort
   , BYVAL ulPublicAddress AS DWORD _                   ' __in ULONG ulPublicAddress
   , BYVAL usPublicPort AS WORD _                       ' __in USHORT usPublicPort
   , BYVAL ulRemoteAddress AS DWORD _                   ' __in ULONG ulRemoteAddress
   , BYVAL usRemotePort AS WORD _                       ' __in USHORT usRemotePort
   , BYVAL eDirection AS ALG_DIRECTION_ENUM _           ' __in ALG_DIRECTION eDirection
   , BYREF ppIPersistentDataChannel AS IPersistentDataChannel _ ' __out IPersistentDataChannel **ppIPersistentDataChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReservePort ( _                               ' VTable offset = 40
     BYVAL usPortCount AS WORD _                        ' __in USHORT usPortCount
   , BYREF pusReservedPort AS WORD _                    ' __out USHORT *pusReservedPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseReservedPort ( _                       ' VTable offset = 44
     BYVAL usReservedPortBase AS WORD _                 ' __in USHORT usReservedPortBase
   , BYVAL usPortCount AS WORD _                        ' __in USHORT usPortCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateAdapters ( _                         ' VTable offset = 48
     BYREF ppIEnumAdapterInfo AS IEnumAdapterInfo _     ' __out IEnumAdapterInfo **ppIEnumAdapterInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartAdapterNotifications ( _                 ' VTable offset = 52
     BYVAL pSink AS IAdapterNotificationSink _          ' __in IAdapterNotificationSink *pSink
   , BYREF pdwCookie AS DWORD _                         ' __in DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopAdapterNotifications ( _                  ' VTable offset = 56
     BYVAL dwCookieOfSink AS DWORD _                    ' __in DWORD dwCookieOfSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LookupAdapterPortMapping ( _                  ' VTable offset = 60
     BYVAL ulAdapterIndex AS DWORD _                    ' __in ULONG ulAdapterIndex
   , BYVAL Protocol AS BYTE _                           ' __in UCHAR Protocol
   , BYVAL ulDestinationAddress AS DWORD _              ' __in ULONG ulDestinationAddress
   , BYVAL usDestinationPort AS WORD _                  ' __in USHORT usDestinationPort
   , BYREF pulRemapAddress AS DWORD _                   ' __out ULONG *pulRemapAddress
   , BYREF pusRemapPort AS WORD _                       ' __out USHORT *pusRemapPort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationGatewayServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IApplicationGateway
' IID = 5134842B-FDCE-485D-93CD-DE1640643BBE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationGateway_INTERFACE_DEFINED)
    %IApplicationGateway_INTERFACE_DEFINED = 1

INTERFACE IApplicationGateway $IID_IApplicationGateway

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pAlgServices AS IApplicationGatewayServices _ ' __in IApplicationGatewayServices *pAlgServices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationGateway_INTERFACE_DEFINED__ */
