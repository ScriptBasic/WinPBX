' ########################################################################################
' Microsoft Windows
' File: Mprapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPRAPI_INC = 1

'/*++

'Copyright (c) Microsoft Corporation. All rights reserved.

'Module Name:

'    mpradmin.h

'Abstract:

'    This file contains the structures, defines and function prototypes for the
'    following APIs:

'        MprAdminIsServiceRunning
'        MprAdminServerConnect
'        MprAdminServerDisconnect
'        MprAdminBufferFree
'        MprAdminPortEnum
'        MprAdminConnectionEnum
'        MprAdminPortGetInfo
'        MprAdminConnectionGetInfo
'        MprAdminPortClearStats
'        MprAdminPortReset
'        MprAdminConnectionClearStats
'        MprAdminPortDisconnect
'        MprAdminGetErrorString

'        MprAdminAcceptNewConnection
'        MprAdminAcceptNewLink
'        MprAdminConnectionHangupNotification
'        MprAdminLinkHangupNotification
'        MprAdminGetIpAddressForUser
'        MprAdminReleaseIpAddress
'        MprAdminInitializeDll
'        MprAdminTerminateDll
'        MprAdminAcceptNewConnection2
'        MprAdminConnectionHangupNotification2
'        MprAdminAcceptReauthentication

'        MprAdminUserGetInfo
'        MprAdminUserSetInfo
'        MprAdminSendUserMessage
'        MprAdminGetPDCServer

'        MprAdminRegisterConnectionNotification
'        MprAdminDeregisterConnectionNotification

'        MprAdminIsServiceRunning
'        MprAdminServerConnect
'        MprAdminServerDisconnect
'        MprAdminBufferFree
'        MprAdminServerSetInfo
'        MprAdminServerGetInfo
'        MprAdminGetErrorString
'        MprAdminTransportCreate
'        MprAdminTransportSetInfo
'        MprAdminTransportGetInfo
'        MprAdminInterfaceCreate
'        MprAdminInterfaceDelete
'        MprAdminInterfaceGetInfo
'        MprAdminInterfaceTransportAdd
'        MprAdminInterfaceTransportGetInfo
'        MprAdminInterfaceTransportSetInfo
'        MprAdminInterfaceTransportRemove
'        MprAdminInterfaceGetHandle
'        MprAdminInterfaceSetCredentials
'        MprAdminInterfaceGetCredentials
'        MprAdminInterfaceEnum
'        MprAdminInterfaceConnect
'        MprAdminInterfaceDisconnect
'        MprAdminInterfaceUpdateRoutes
'        MprAdminInterfaceQueryUpdateResult
'        MprAdminInterfaceUpdatePhonebookInfo
'        MprAdminEstablishDomainRasServer
'        MprAdminIsDomainRasServer

'        MprAdminMIBServerConnect
'        MprAdminMIBServerDisconnect
'        MprAdminMIBBufferFree
'        MprAdminMIBEntryCreate
'        MprAdminMIBEntryDelete
'        MprAdminMIBEntryGet
'        MprAdminMIBEntrySet
'        MprAdminMIBEntryGetFirst
'        MprAdminMIBEntryGetNext
'        MprAdminMIBSetTrapInfo
'        MprAdminMIBGetTrapInfo

'    All MIB APIs operate with the conceptual MIB row.

'        MprConfigServerConnect
'        MprConfigServerDisconnect
'        MprConfigBufferFree
'        MprConfigServerSetInfo
'        MprConfigServerGetInfo
'        MprConfigServerBackup
'        MprConfigServerRestore
'        MprConfigTransportCreate
'        MprConfigTransportDelete
'        MprConfigTransportGetHandle
'        MprConfigTransportSetInfo
'        MprConfigTransportGetInfo
'        MprConfigTransportEnum
'        MprConfigInterfaceCreate
'        MprConfigInterfaceDelete
'        MprConfigInterfaceGetHandle
'        MprConfigInterfaceGetInfo
'        MprConfigInterfaceEnum
'        MprConfigInterfaceTransportAdd
'        MprConfigInterfaceTransportRemove
'        MprConfigInterfaceTransportGetHandle
'        MprConfigInterfaceTransportGetInfo
'        MprConfigInterfaceTransportSetInfo
'        MprConfigInterfaceTransportEnum
'        MprConfigFilterGetInfo
'        MprConfigFilterSetInfo

'        MprSetupIpInIpInterfaceFriendlyNameEnum
'        MprSetupIpInIpInterfaceFriendlyNameFree
'        MprSetupIpInIpInterfaceFriendlyNameCreate
'        MprSetupIpInIpInterfaceFriendlyNameDelete

'--*/

#INCLUDE ONCE "lmcons.inc"
#INCLUDE ONCE "ras.inc"
#INCLUDE ONCE "in6addr.inc"
#INCLUDE ONCE "mprerror.inc"
#INCLUDE ONCE "wincrypt.inc"

'//
'// Name of the Routing and RemoteAccess Service
'//

$RRAS_SERVICE_NAME       = "RemoteAccess"

'//
'// Protocol IDs
'//

%PID_IPX                 = &H0000002B
%PID_IP                  = &H00000021
%PID_IPV6                = &H00000057
%PID_NBF                 = &H0000003F
%PID_ATALK               = &H00000029

%MAX_INTERFACE_NAME_LEN  = 256
%MAX_TRANSPORT_NAME_LEN  = 40
%MAX_MEDIA_NAME          = 16
%MAX_PORT_NAME           = 16
%MAX_DEVICE_NAME         = 128
%MAX_PHONE_NUMBER_LEN    = 128
%MAX_DEVICETYPE_NAME     = 16

'//
'// MPR Interface structures and definitions.
'//

'//
'// MPR Interface types
'//

' ROUTER_INTERFACE_TYPE enum
%ROUTER_IF_TYPE_CLIENT      = 0
%ROUTER_IF_TYPE_HOME_ROUTER = 1
%ROUTER_IF_TYPE_FULL_ROUTER = 2
%ROUTER_IF_TYPE_DEDICATED   = 3
%ROUTER_IF_TYPE_INTERNAL    = 4
%ROUTER_IF_TYPE_LOOPBACK    = 5
%ROUTER_IF_TYPE_TUNNEL1     = 6
%ROUTER_IF_TYPE_DIALOUT     = 7
'%ROUTER_IF_TYPE_MAX         = 7   ' // do not use.Illegal

' ROUTER_CONNECTION_STATE enum
%ROUTER_IF_STATE_UNREACHABLE  = 0
%ROUTER_IF_STATE_DISCONNECTED = 1
%ROUTER_IF_STATE_CONNECTING   = 2
%ROUTER_IF_STATE_CONNECTED    = 3

%MPR_INTERFACE_OUT_OF_RESOURCES              = &H00000001
%MPR_INTERFACE_ADMIN_DISABLED                = &H00000002
%MPR_INTERFACE_CONNECTION_FAILURE            = &H00000004
%MPR_INTERFACE_SERVICE_PAUSED                = &H00000008
%MPR_INTERFACE_DIALOUT_HOURS_RESTRICTION     = &H00000010
%MPR_INTERFACE_NO_MEDIA_SENSE                = &H00000020
%MPR_INTERFACE_NO_DEVICE                     = &H00000040

' // Size = 540 bytes
TYPE MPR_INTERFACE_0 DWORD FILL
   wszInterfaceName       AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' __in_out  WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1]
   hInterface             AS DWORD   ' __out HANDLE                  hInterface
   fEnabled               AS LONG    ' __in_out  BOOL                    fEnabled
   dwIfType               AS DWORD   ' __in_out  ROUTER_INTERFACE_TYPE   dwIfType
   dwConnectionState      AS DWORD   ' __out ROUTER_CONNECTION_STATE dwConnectionState
   fUnReachabilityReasons AS DWORD   ' __out DWORD                   fUnReachabilityReasons
   dwLastError            AS DWORD   ' __out DWORD                   dwLastError
END TYPE

' // Size = 532 bytes
UNION MPR_IPINIP_INTERFACE_0_UNION   ' // For compability with PN includes
   guidX           AS GUID   ' GUID    Guid
   Guid            AS GUID   ' GUID    Guid
END UNION
TYPE MPR_IPINIP_INTERFACE_0 DWORD FILL
   wszFriendlyName AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' WCHAR wszFriendlyName[MAX_INTERFACE_NAME_LEN+1]
   MPR_IPINIP_INTERFACE_0_UNION
END TYPE

'#if(WINVER >= 0x0500)

' // Size = 544 bytes
TYPE MPR_INTERFACE_1 DWORD FILL
   wszInterfaceName            AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' __in_out  WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1];
   hInterface                  AS DWORD          ' __out HANDLE                  hInterface
   fEnabled                    AS LONG           ' __in_out  BOOL                    fEnabled
   dwIfType                    AS DWORD          ' __in_out  ROUTER_INTERFACE_TYPE   dwIfType
   dwConnectionState           AS DWORD          ' __out ROUTER_CONNECTION_STATE dwConnectionState
   fUnReachabilityReasons      AS DWORD          ' __out DWORD                   fUnReachabilityReasons
   dwLastError                 AS DWORD          ' __out DWORD                   dwLastError
   lpwsDialoutHoursRestriction AS WSTRINGZ PTR   ' __out LPWSTR                  lpwsDialoutHoursRestriction
END TYPE

'//
'// MPR_INTERFACE_2 definitions
'//

%MPR_MaxDeviceType           = %RAS_MaxDeviceType
%MPR_MaxPhoneNumber          = %RAS_MaxPhoneNumber
%MPR_MaxIpAddress            = %RAS_MaxIpAddress
%MPR_MaxIpxAddress           = %RAS_MaxIpxAddress

%MPR_MaxEntryName            = %RAS_MaxEntryName
%MPR_MaxDeviceName           = %RAS_MaxDeviceName
%MPR_MaxCallbackNumber       = %RAS_MaxCallbackNumber

%MPR_MaxAreaCode             = %RAS_MaxAreaCode
%MPR_MaxPadType              = %RAS_MaxPadType
%MPR_MaxX25Address           = %RAS_MaxX25Address
%MPR_MaxFacilities           = %RAS_MaxFacilities
%MPR_MaxUserData             = %RAS_MaxUserData

'//
'// MPR_INTERFACE_2 'dwfOptions' bit flags.
'//

%MPRIO_SpecificIpAddr        = %RASEO_SpecificIpAddr
%MPRIO_SpecificNameServers   = %RASEO_SpecificNameServers
%MPRIO_IpHeaderCompression   = %RASEO_IpHeaderCompression
%MPRIO_RemoteDefaultGateway  = %RASEO_RemoteDefaultGateway
%MPRIO_DisableLcpExtensions  = %RASEO_DisableLcpExtensions
%MPRIO_SwCompression         = %RASEO_SwCompression
%MPRIO_RequireEncryptedPw    = %RASEO_RequireEncryptedPw
%MPRIO_RequireMsEncryptedPw  = %RASEO_RequireMsEncryptedPw
%MPRIO_RequireDataEncryption = %RASEO_RequireDataEncryption
%MPRIO_NetworkLogon          = %RASEO_NetworkLogon
%MPRIO_PromoteAlternates     = %RASEO_PromoteAlternates
%MPRIO_SecureLocalFiles      = %RASEO_SecureLocalFiles
%MPRIO_RequireEAP            = %RASEO_RequireEAP
%MPRIO_RequirePAP            = %RASEO_RequirePAP
%MPRIO_RequireSPAP           = %RASEO_RequireSPAP
%MPRIO_SharedPhoneNumbers    = %RASEO_SharedPhoneNumbers
%MPRIO_RequireCHAP           = %RASEO_RequireCHAP
%MPRIO_RequireMsCHAP         = %RASEO_RequireMsCHAP
%MPRIO_RequireMsCHAP2        = %RASEO_RequireMsCHAP2

'#if (WINVER >= 0x501)
%MPRIO_IpSecPreSharedKey     = &H80000000???
'#endif

'//
'// MPR_INTERFACE_2 'dwProtocols' bit flags.
'//

%MPRNP_Ipx                   = %RASNP_Ipx
%MPRNP_Ip                    = %RASNP_Ip
'#if (WINVER >= 0x600)
%MPRNP_Ipv6                  = %RASNP_Ipv6
'#endif

'//
'// MPR_INTERFACE_2 'szDeviceType' default strings.
'//

$MPRDT_Modem                 = $RASDT_Modem
$MPRDT_Isdn                  = $RASDT_Isdn
$MPRDT_X25                   = $RASDT_X25
$MPRDT_Vpn                   = $RASDT_Vpn
$MPRDT_Pad                   = $RASDT_Pad
$MPRDT_Generic               = $RASDT_Generic
$MPRDT_Serial                = $RASDT_Serial
$MPRDT_FrameRelay            = $RASDT_FrameRelay
$MPRDT_Atm                   = $RASDT_Atm
$MPRDT_Sonet                 = $RASDT_Sonet
$MPRDT_SW56                  = $RASDT_SW56
$MPRDT_Irda                  = $RASDT_Irda
$MPRDT_Parallel              = $RASDT_Parallel

$$MPRDT_Modem                = $$RASDT_Modem
$$MPRDT_Isdn                 = $$RASDT_Isdn
$$MPRDT_X25                  = $$RASDT_X25
$$MPRDT_Vpn                  = $$RASDT_Vpn
$$MPRDT_Pad                  = $$RASDT_Pad
$$MPRDT_Generic              = $$RASDT_Generic
$$MPRDT_Serial               = $$RASDT_Serial
$$MPRDT_FrameRelay           = $$RASDT_FrameRelay
$$MPRDT_Atm                  = $$RASDT_Atm
$$MPRDT_Sonet                = $$RASDT_Sonet
$$MPRDT_SW56                 = $$RASDT_SW56
$$MPRDT_Irda                 = $$RASDT_Irda
$$MPRDT_Parallel             = $$RASDT_Parallel

'//
'// MPR_INTERFACE_2   'dwType' settings
'//

%MPRET_Phone                 = %RASET_Phone
%MPRET_Vpn                   = %RASET_Vpn
%MPRET_Direct                = %RASET_Direct

'//
'// MPR_INTERFACE_2 'dwDialMode' values.
'//

%MPRDM_DialFirst             = 0
%MPRDM_DialAll               = %RASEDM_DialAll
%MPRDM_DialAsNeeded          = %RASEDM_DialAsNeeded

'//
'// MPR_INTERFACE_2 'dwIdleDisconnectSeconds' constants.
'//

%MPRIDS_Disabled             = %RASIDS_Disabled
%MPRIDS_UseGlobalValue       = %RASIDS_UseGlobalValue

'//
'// MPR_INTERFACE_2 encryption types.
'//

%MPR_ET_None                 = %ET_None
%MPR_ET_Require              = %ET_Require
%MPR_ET_RequireMax           = %ET_RequireMax
%MPR_ET_Optional             = %ET_Optional

'//
'// MPR_INTERFACE_2 Vpn strategies
'//

%MPR_VS_Default              = %VS_Default
%MPR_VS_PptpOnly             = %VS_PptpOnly
%MPR_VS_PptpFirst            = %VS_PptpFirst
%MPR_VS_L2tpOnly             = %VS_L2tpOnly
%MPR_VS_L2tpFirst            = %VS_L2tpFirst

'//
'// Used to create/get/set a demand dial interface plus its
'// ras configuration.
'//

' // Size = 2468 bytes
TYPE MPR_INTERFACE_2 DWORD FILL
   wszInterfaceName           AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' __in_out  WCHAR wszInterfaceName[MAX_INTERFACE_NAME_LEN+1]
   hInterface                 AS DWORD          ' __out    HANDLE                  hInterface
   fEnabled                   AS LONG           ' __in_out BOOL                    fEnabled
   dwIfType                   AS DWORD          ' __in_out ROUTER_INTERFACE_TYPE   dwIfType
   dwConnectionState          AS DWORD          ' __out    ROUTER_CONNECTION_STATE dwConnectionState
   fUnReachabilityReasons     AS DWORD          ' __out    DWORD                   fUnReachabilityReasons;
   dwLastError                AS DWORD          ' __out    DWORD                   dwLastError
   dwfOptions                 AS DWORD          ' DWORD  dwfOptions
   szLocalPhoneNumber         AS WSTRINGZ * %RAS_MaxPhoneNumber + 1  ' WCHAR szLocalPhoneNumber[ RAS_MaxPhoneNumber + 1 ]
   szAlternates               AS WSTRINGZ PTR   ' PWCHAR szAlternates
   ipaddr                     AS DWORD          ' DWORD  ipaddr
   ipaddrDns                  AS DWORD          ' DWORD  ipaddrDns
   ipaddrDnsAlt               AS DWORD          ' DWORD  ipaddrDnsAlt
   ipaddrWins                 AS DWORD          ' DWORD  ipaddrWins
   ipaddrWinsAlt              AS DWORD          ' DWORD  ipaddrWinsAlt
   dwfNetProtocols            AS DWORD          ' DWORD  dwfNetProtocols
   szDeviceType               AS WSTRINGZ * %MPR_MaxDeviceType + 1   ' WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ]
   szDeviceName               AS WSTRINGZ * %MPR_MaxDeviceName + 1   ' WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ]
   szX25PadType               AS WSTRINGZ * %MPR_MaxPadType + 1      ' WCHAR szX25PadType[ MPR_MaxPadType + 1 ]
   szX25Address               AS WSTRINGZ * %MPR_MaxX25Address + 1   ' WCHAR szX25Address[ MPR_MaxX25Address + 1 ]
   szX25Facilities            AS WSTRINGZ * %MPR_MaxFacilities + 1   ' WCHAR szX25Facilities[ MPR_MaxFacilities + 1 ]
   szX25UserData              AS WSTRINGZ * %MPR_MaxUserData + 1     ' WCHAR szX25UserData[ MPR_MaxUserData + 1 ]
   dwChannels                 AS DWORD          ' DWORD  dwChannels
   dwSubEntries               AS DWORD          ' DWORD  dwSubEntries
   dwDialMode                 AS DWORD          ' DWORD  dwDialMode
   dwDialExtraPercent         AS DWORD          ' DWORD  dwDialExtraPercent
   dwDialExtraSampleSeconds   AS DWORD          ' DWORD  dwDialExtraSampleSeconds
   dwHangUpExtraPercent       AS DWORD          ' DWORD  dwHangUpExtraPercent
   dwHangUpExtraSampleSeconds AS DWORD          ' DWORD  dwHangUpExtraSampleSeconds
   dwIdleDisconnectSeconds    AS DWORD          ' DWORD  dwIdleDisconnectSeconds
   dwType                     AS DWORD          ' DWORD  dwType
   dwEncryptionType           AS DWORD          ' DWORD  dwEncryptionType
   dwCustomAuthKey            AS DWORD          ' DWORD  dwCustomAuthKey
   dwCustomAuthDataSize       AS DWORD          ' DWORD  dwCustomAuthDataSize
   lpbCustomAuthData          AS BYTE PTR       ' LPBYTE lpbCustomAuthData
   guidId                     AS GUID           ' GUID   guidId
   dwVpnStrategy              AS DWORD          ' DWORD  dwVpnStrategy
END TYPE

'#if(WINVER >= 0x0600)

' // Size = 2508 bytes
TYPE MPR_INTERFACE_3 DWORD FILL
   wszInterfaceName           AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' WCHAR[MAX_INTERFACE_NAME_LEN+1]
   hInterface                 AS DWORD   ' HANDLE
   fEnabled                   AS LONG    ' BOOL
   dwIfType                   AS LONG    ' ROUTER_INTERFACE_TYPE
   dwConnectionState          AS LONG    ' ROUTER_CONNECTION_STATE
   fUnReachabilityReasons     AS DWORD   ' DWORD
   dwLastError                AS DWORD   ' DWORD
   ' // Demand dial-specific properties
   dwfOptions                 AS DWORD   ' DWORD
   ' // Location/phone number
   szLocalPhoneNumber         AS WSTRINGZ * %RAS_MaxPhoneNumber + 1   ' WCHAR[RAS_MaxPhoneNumber + 1]
   szAlternates               AS WSTRINGZ PTR   ' PWCHAR
   ' // PPP/Ip
   ipaddr                     AS DWORD   ' DWORD
   ipaddrDns                  AS DWORD   ' DWORD
   ipaddrDnsAlt               AS DWORD   ' DWORD
   ipaddrWins                 AS DWORD   ' DWORD
   ipaddrWinsAlt              AS DWORD   ' DWORD
   ' // NetProtocols
   dwfNetProtocols            AS DWORD   ' DWORD
   ' // Device
   szDeviceType               AS WSTRINGZ * %MPR_MaxDeviceType + 1   ' WCHAR[MPR_MaxDeviceType + 1]
   szDeviceName               AS WSTRINGZ * %MPR_MaxDeviceName + 1   ' WCHAR[MPR_MaxDeviceName + 1]
   ' // X.25
   szX25PadType               AS WSTRINGZ * %MPR_MaxPadType + 1      ' WCHAR[MPR_MaxPadType + 1]
   szX25Address               AS WSTRINGZ * %MPR_MaxX25Address + 1   ' WCHAR[MPR_MaxX25Address + 1]
   szX25Facilities            AS WSTRINGZ * %MPR_MaxFacilities + 1   ' WCHAR[MPR_MaxFacilities + 1]
   szX25UserData              AS WSTRINGZ * %MPR_MaxUserData + 1     ' WCHAR[MPR_MaxUserData + 1]
   dwChannels                 AS DWORD          ' DWORD
   ' // Multilink
   dwSubEntries               AS DWORD          ' DWORD
   dwDialMode                 AS DWORD          ' DWORD
   dwDialExtraPercent         AS DWORD          ' DWORD
   dwDialExtraSampleSeconds   AS DWORD          ' DWORD
   dwHangUpExtraPercent       AS DWORD          ' DWORD
   dwHangUpExtraSampleSeconds AS DWORD          ' DWORD
   ' // Idle timeout
   dwIdleDisconnectSeconds    AS DWORD          ' DWORD
   ' // Entry Type
   dwType                     AS DWORD          ' DWORD
   ' // EncryptionType
   dwEncryptionType           AS DWORD          ' DWORD
   ' // EAP information
   dwCustomAuthKey            AS DWORD          ' DWORD
   dwCustomAuthDataSize       AS DWORD          ' DWORD
   lpbCustomAuthData          AS BYTE PTR       ' LPBYTE
   ' // Guid of the connection
   guidId                     AS GUID           ' GUID
   ' // Vpn Strategy
   dwVpnStrategy              AS DWORD          ' DWORD
   AddressCount               AS DWORD          ' ULONG
   ipv6addrDns                AS IN6_ADDR       ' IN6_ADDR *
   ipv6addrDnsAlt             AS IN6_ADDR       ' IN6_ADDR *
   ipv6addr                   AS IN6_ADDR PTR   ' IN6_ADDR *
END TYPE

'#endif /* WINVER >= 0x0600 */

'//
'// Used to set/get per-link information for multilinked demand
'// dial interfaces.
'//

' // Size = 292 bytes
TYPE MPR_DEVICE_0 DWORD FILL
   szDeviceType AS WSTRINGZ * %MPR_MaxDeviceType + 1   ' WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ]
   szDeviceName AS WSTRINGZ * %MPR_MaxDeviceName + 1   ' WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ]
END TYPE

' // Size = 556 bytes
TYPE MPR_DEVICE_1 DWORD FILL
   szDeviceType       AS WSTRINGZ * %MPR_MaxDeviceType + 1    ' WCHAR szDeviceType[ MPR_MaxDeviceType + 1 ]
   szDeviceName       AS WSTRINGZ * %MPR_MaxDeviceName + 1    ' WCHAR szDeviceName[ MPR_MaxDeviceName + 1 ]
   szLocalPhoneNumber AS WSTRINGZ * %MPR_MaxPhoneNumber + 1   ' WCHAR szLocalPhoneNumber[ MPR_MaxPhoneNumber + 1 ]
   szAlternates       AS WSTRINGZ PTR   ' PWCHAR      szAlternates
END TYPE

'//
'// Used to get/set extended credentials information such as
'// eap credentials info.
'//

' // Size = 8 bytes
TYPE MPR_CREDENTIALSEX_0 DWORD FILL
   dwSize             AS DWORD      ' DWORD  dwSize
   lpbCredentialsInfo AS BYTE PTR   ' LPBYTE lpbCredentialsInfo
END TYPE

' // Size = 8 bytes
TYPE MPR_CREDENTIALSEX_1 DWORD FILL
   dwSize             AS DWORD      ' DWORD  dwSize
   lpbCredentialsInfo AS BYTE PTR   ' LPBYTE lpbCredentialsInfo
END TYPE

'#endif /* WINVER >= 0x0500 */

' // Size = 92 bytes
TYPE MPR_TRANSPORT_0 DWORD
   dwTransportId    AS DWORD   ' __out DWORD  dwTransportId
   hTransport       AS DWORD   ' __out HANDLE hTransport
   wszTransportName AS WSTRINGZ * %MAX_TRANSPORT_NAME_LEN + 1   ' __out WCHAR  wszTransportName[MAX_TRANSPORT_NAME_LEN+1]
END TYPE

' // Size = 92 bytes
TYPE MPR_IFTRANSPORT_0 DWORD
   dwTransportId      AS DWORD   ' __out DWORD  dwTransportId
   hIfTransport       AS DWORD   ' __out HANDLE hIfTransport
   wszIfTransportName AS WSTRINGZ * %MAX_TRANSPORT_NAME_LEN + 1   ' __out WCHAR  wszIfTransportName[MAX_TRANSPORT_NAME_LEN+1]
END TYPE

' // Size = 16 bytes
TYPE MPR_SERVER_0 DWORD
   fLanOnlyMode AS LONG    ' __out BOOL  fLanOnlyMode
   dwUpTime     AS DWORD   ' __out DWORD dwUpTime // In seconds
   dwTotalPorts AS DWORD   ' __out DWORD dwTotalPorts
   dwPortsInUse AS DWORD   ' __out DWORD dwPortsInUse
END TYPE

'#if (WINVER >= 0x501)

'//
'// values for dwFlags in MPR_SERVER_1. This enables the ports for Ras or Routing.
'//

%MPR_ENABLE_RAS_ON_DEVICE            = &H00000001???
%MPR_ENABLE_ROUTING_ON_DEVICE        = &H00000002???

' // Size = 16 bytes
TYPE MPR_SERVER_1 DWORD
   dwNumPptpPorts  AS DWORD   ' __in_out DWORD dwNumPptpPorts
   dwPptpPortFlags AS DWORD   ' __in_out DWORD dwPptpPortFlags
   dwNumL2tpPorts  AS DWORD   ' __in_out DWORD dwNumL2tpPorts
   dwL2tpPortFlags AS DWORD   ' __in_out DWORD dwL2tpPortFlags
END TYPE

'#endif

'#if (WINVER >= 0x600)

'//
'// MPR_SERVER_2 structure.
'//

' // Size = 24 bytes
TYPE MPR_SERVER_2 DWORD
   dwNumPptpPorts  AS DWORD   ' __in_out DWORD
   dwPptpPortFlags AS DWORD   ' __in_out DWORD
   dwNumL2tpPorts  AS DWORD   ' __in_out DWORD
   dwL2tpPortFlags AS DWORD   ' __in_out DWORD
   dwNumSstpPorts  AS DWORD   ' __in_out DWORD
   dwSstpPortFlags AS DWORD   ' __in_out DWORD
END TYPE

'#endif

'//
'// Port condition codes
'//

' RAS_PORT_CONDITION enum
%RAS_PORT_NON_OPERATIONAL = 0
%RAS_PORT_DISCONNECTED    = 1
%RAS_PORT_CALLING_BACK    = 2
%RAS_PORT_LISTENING       = 3
%RAS_PORT_AUTHENTICATING  = 4
%RAS_PORT_AUTHENTICATED   = 5
%RAS_PORT_INITIALIZING    = 6

'//
'// Hardware condition codes
'//

' RAS_HARDWARE_CONDITION enum
%RAS_HARDWARE_OPERATIONAL = 0
%RAS_HARDWARE_FAILURE     = 1

' // Size = 380 bytes
TYPE RAS_PORT_0 DWORD FILL
   hPort                AS DWORD   ' __out HANDLE             hPort
   hConnection          AS DWORD   ' __out HANDLE             hConnection
   dwPortCondition      AS DWORD   ' __out RAS_PORT_CONDITION dwPortCondition
   dwTotalNumberOfCalls AS DWORD   ' __out DWORD              dwTotalNumberOfCalls
   dwConnectDuration    AS DWORD   ' __out DWORD              dwConnectDuration  // In seconds
   wszPortName          AS WSTRINGZ * %MAX_PORT_NAME + 1         ' __out WCHAR wszPortName[ MAX_PORT_NAME + 1 ]
   wszMediaName         AS WSTRINGZ * %MAX_MEDIA_NAME + 1        ' __out WCHAR wszMediaName[ MAX_MEDIA_NAME + 1 ]
   wszDeviceName        AS WSTRINGZ * %MAX_DEVICE_NAME + 1       ' __out WCHAR wszDeviceName[ MAX_DEVICE_NAME + 1 ]
   wszDeviceType        AS WSTRINGZ * %MAX_DEVICETYPE_NAME + 1   ' __out WCHAR wszDeviceType[ MAX_DEVICETYPE_NAME + 1 ]
END TYPE

' // Size = 64 bytes
TYPE RAS_PORT_1 DWORD
   hPort                 AS DWORD   ' __out HANDLE                  hPort
   hConnection           AS DWORD   ' __out HANDLE                  hConnection
   dwHardwareCondition   AS DWORD   ' __out RAS_HARDWARE_CONDITION  dwHardwareCondition
   dwLineSpeed           AS DWORD   ' __out DWORD                   dwLineSpeed  // in bits/second
   dwBytesXmited         AS DWORD   ' __out DWORD                   dwBytesXmited
   dwBytesRcved          AS DWORD   ' __out DWORD                   dwBytesRcved
   dwFramesXmited        AS DWORD   ' __out DWORD                   dwFramesXmited
   dwFramesRcved         AS DWORD   ' __out DWORD                   dwFramesRcved
   dwCrcErr              AS DWORD   ' __out DWORD                   dwCrcErr
   dwTimeoutErr          AS DWORD   ' __out DWORD                   dwTimeoutErr
   dwAlignmentErr        AS DWORD   ' __out DWORD                   dwAlignmentErr
   dwHardwareOverrunErr  AS DWORD   ' __out DWORD                   dwHardwareOverrunErr
   dwFramingErr          AS DWORD   ' __out DWORD                   dwFramingErr
   dwBufferOverrunErr    AS DWORD   ' __out DWORD                   dwBufferOverrunErr
   dwCompressionRatioIn  AS DWORD   ' __out DWORD                   dwCompressionRatioIn
   dwCompressionRatioOut AS DWORD   ' __out DWORD                   dwCompressionRatioOut
END TYPE

'//
'// Maximum length of address string, e.g. "255.255.255.255" for IP.
'//

%IPADDRESSLEN   = 15
%IPXADDRESSLEN  = 22
%ATADDRESSLEN   = 32
%MAXIPADRESSLEN = 64

' // Size = 40 bytes
TYPE PPP_NBFCP_INFO DWORD
   dwError  AS DWORD   ' __out DWORD dwError
   wszWksta AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' __out WCHAR wszWksta[ NETBIOS_NAME_LEN + 1 ]
END TYPE

' // Size = 68 bytes
TYPE PPP_IPCP_INFO DWORD
   dwError          AS DWORD                          ' __out DWORD dwError
   wszAddress       AS WSTRINGZ * %IPADDRESSLEN + 1   ' __out WCHAR wszAddress[ IPADDRESSLEN + 1 ]
   wszRemoteAddress AS WSTRINGZ * %IPADDRESSLEN + 1   ' __out WCHAR wszRemoteAddress[ IPADDRESSLEN + 1 ]
END TYPE

'//
'// PPP_IPCP_INFO2 dwOptions values.
'//

%PPP_IPCP_VJ            = &H00000001???

' // Size = 76 bytes
TYPE PPP_IPCP_INFO2 DWORD FILL
   dwError          AS DWORD   ' __out DWORD dwError
   wszAddress       AS WSTRINGZ * %IPADDRESSLEN + 1   ' __out WCHAR wszAddress[ IPADDRESSLEN + 1 ]
   wszRemoteAddress AS WSTRINGZ * %IPADDRESSLEN + 1   ' __out WCHAR wszRemoteAddress[ IPADDRESSLEN + 1 ]
   dwOptions        AS DWORD   ' __out DWORD dwOptions
   dwRemoteOptions  AS DWORD   ' __out DWORD dwRemoteOptions
END TYPE

' // Size = 52 bytes
TYPE PPP_IPXCP_INFO DWORD
   dwError    AS DWORD   ' __out DWORD dwError
   wszAddress AS WSTRINGZ * %IPXADDRESSLEN + 1   ' __out WCHAR wszAddress[ IPXADDRESSLEN + 1 ]
END TYPE

' // Size = 72 bytes
TYPE PPP_ATCP_INFO DWORD
   dwError    AS DWORD   ' __out DWORD dwError
   wszAddress AS WSTRINGZ * %ATADDRESSLEN + 1   ' __out WCHAR wszAddress[ ATADDRESSLEN + 1 ]
END TYPE

'#if(WINVER >= 0x0600)
' // Size = 48 bytes
TYPE PPP_IPV6_CP_INFO DWORD
   dwVersion                     AS DWORD   ' DWORD
   dwSize                        AS DWORD   ' DWORD
   dwError                       AS DWORD   ' DWORD
   bInterfaceIdentifier(7)       AS BYTE    ' BYTE[8]
   bRemoteInterfaceIdentifier(7) AS BYTE    ' BYTE[8]
   dwOptions                     AS DWORD   ' DWORD
   dwRemoteOptions               AS DWORD   ' DWORD
   bPrefix(7)                    AS BYTE    ' BYTE[8]
   dwPrefixLength                AS DWORD   ' DWORD
END TYPE
'#endif /* WINVER >= 0x0600 */

' // Size = 232 bytes
TYPE PPP_INFO DWORD
   nbf AS PPP_NBFCP_INFO   ' __out PPP_NBFCP_INFO  nbf
   ip  AS PPP_IPCP_INFO    ' __out PPP_IPCP_INFO   ip
   ipx AS PPP_IPXCP_INFO   ' __out PPP_IPXCP_INFO  ipx
   at  AS PPP_ATCP_INFO    ' __out PPP_ATCP_INFO   at
END TYPE

'#if(WINVER >= 0x0500)

'//
'// PPP_CCP dwCompressionAlgorithm values.
'//

%RASCCPCA_MPPC               = &H00000006???
%RASCCPCA_STAC               = &H00000005???

'//
'// PPP_CCP dwOptions values.
'//

%PPP_CCP_COMPRESSION         = &H00000001???
%PPP_CCP_ENCRYPTION40BITOLD  = &H00000010???
%PPP_CCP_ENCRYPTION40BIT     = &H00000020???
%PPP_CCP_ENCRYPTION128BIT    = &H00000040???
%PPP_CCP_ENCRYPTION56BIT     = &H00000080???
%PPP_CCP_HISTORYLESS         = &H01000000???

' // Size = 20 bytes
TYPE PPP_CCP_INFO DWORD
   dwError                      AS DWORD   ' __out DWORD dwError
   dwCompressionAlgorithm       AS DWORD   ' __out DWORD dwCompressionAlgorithm
   dwOptions                    AS DWORD   ' __out DWORD dwOptions
   dwRemoteCompressionAlgorithm AS DWORD   ' __out DWORD dwRemoteCompressionAlgorithm
   dwRemoteOptions              AS DWORD   ' __out DWORD dwRemoteOptions
END TYPE

'//
'// PPP_LCP dwAuthenticatonProtocol values.
'//

%PPP_LCP_PAP                 = &HC023???
%PPP_LCP_SPAP                = &HC027???
%PPP_LCP_CHAP                = &HC223???
%PPP_LCP_EAP                 = &HC227???

'//
'// PPP_LCP dwAuthenticatonData values.
'//

%PPP_LCP_CHAP_MD5            = &H05???
%PPP_LCP_CHAP_MS             = &H80???
%PPP_LCP_CHAP_MSV2           = &H81???

'//
'// PPP_LCP dwOption values
'//

%PPP_LCP_MULTILINK_FRAMING   = &H00000001???
%PPP_LCP_PFC                 = &H00000002???
%PPP_LCP_ACFC                = &H00000004???
%PPP_LCP_SSHF                = &H00000008???
%PPP_LCP_DES_56              = &H00000010???
%PPP_LCP_3_DES               = &H00000020???

'#if(WINVER >= 0x0600)
%PPP_LCP_AES_128             = &H00000040???
%PPP_LCP_AES_256             = &H00000080???
'#endif /* WINVER >= 0x0600 */

' // Size = 44 bytes
TYPE PPP_LCP_INFO DWORD
   dwError                        AS DWORD   ' __out DWORD dwError
   dwAuthenticationProtocol       AS DWORD   ' __out DWORD dwAuthenticationProtocol
   dwAuthenticationData           AS DWORD   ' __out DWORD dwAuthenticationData
   dwRemoteAuthenticationProtocol AS DWORD   ' __out DWORD dwRemoteAuthenticationProtocol
   dwRemoteAuthenticationData     AS DWORD   ' __out DWORD dwRemoteAuthenticationData
   dwTerminateReason              AS DWORD   ' __out DWORD dwTerminateReason
   dwRemoteTerminateReason        AS DWORD   ' __out DWORD dwRemoteTerminateReason
   dwOptions                      AS DWORD   ' __out DWORD dwOptions
   dwRemoteOptions                AS DWORD   ' __out DWORD dwRemoteOptions
   dwEapTypeId                    AS DWORD   ' __out DWORD dwEapTypeId
   dwRemoteEapTypeId              AS DWORD   ' __out DWORD dwRemoteEapTypeId
END TYPE

' // Size = 304 bytes
TYPE PPP_INFO_2 DWORD
   nbf AS PPP_NBFCP_INFO   ' __out PPP_NBFCP_INFO  nbf
   ip  AS PPP_IPCP_INFO2   ' __out PPP_IPCP_INFO2  ip
   ipx AS PPP_IPXCP_INFO   ' __out PPP_IPXCP_INFO  ipx
   at  AS PPP_ATCP_INFO    ' __out PPP_ATCP_INFO   at
   ccp AS PPP_CCP_INFO     ' __out PPP_CCP_INFO    ccp
   lcp AS PPP_LCP_INFO     ' __out PPP_LCP_INFO    lcp
END TYPE

'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0600)
' // Size = 228 bytes
TYPE PPP_INFO_3 DWORD
   nbf  AS PPP_NBFCP_INFO
   ip   AS PPP_IPCP_INFO2
   ipv6 AS PPP_IPV6_CP_INFO
   ccp  AS PPP_CCP_INFO
   lcp  AS PPP_LCP_INFO
END TYPE
'#endif /* WINVER >= 0x0600 */

'//
'// Possible bits set in Connection Flags field
'//

%RAS_FLAGS_PPP_CONNECTION        = &H00000001???
%RAS_FLAGS_MESSENGER_PRESENT     = &H00000002???

'#if(WINVER < = &H0501)
%RAS_FLAGS_RAS_CONNECTION        = &H00000004???
'#endif

%RAS_FLAGS_QUARANTINE_PRESENT    = &H00000008???

'#if(WINVER >= 0x0601)
%RAS_FLAGS_DORMANT               = &H00000020???
'#endif

' // Size = 1116 bytes
TYPE RAS_CONNECTION_0 BYTE
   hConnection       AS DWORD   ' __out HANDLE                hConnection
   hInterface        AS DWORD   ' __out HANDLE                hInterface
   dwConnectDuration AS DWORD   ' __out DWORD                 dwConnectDuration // In seconds
   dwInterfaceType   AS DWORD   ' __out ROUTER_INTERFACE_TYPE dwInterfaceType
   dwConnectionFlags AS DWORD   ' __out DWORD                 dwConnectionFlags
   wszInterfaceName  AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' __out WCHAR wszInterfaceName[ MAX_INTERFACE_NAME_LEN + 1 ]
   wszUserName       AS WSTRINGZ * %UNLEN + 1   ' __out WCHAR wszUserName[ UNLEN + 1 ]
   wszLogonDomain    AS WSTRINGZ * %DNLEN + 1   ' __out WCHAR wszLogonDomain[ DNLEN + 1 ]
   wszRemoteComputer AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' __out WCHAR wszRemoteComputer[ NETBIOS_NAME_LEN + 1 ]
   alignment__       AS WORD
END TYPE

' // Size = 288 bytes
TYPE RAS_CONNECTION_1 DWORD
   hConnection           AS DWORD      ' __out HANDLE   hConnection
   hInterface            AS DWORD      ' __out HANDLE   hInterface
   PppInfo               AS PPP_INFO   ' __out PPP_INFO PppInfo
   dwBytesXmited         AS DWORD      ' __out DWORD    dwBytesXmited
   dwBytesRcved          AS DWORD      ' __out DWORD    dwBytesRcved
   dwFramesXmited        AS DWORD      ' __out DWORD    dwFramesXmited
   dwFramesRcved         AS DWORD      ' __out DWORD    dwFramesRcved
   dwCrcErr              AS DWORD      ' __out DWORD    dwCrcErr
   dwTimeoutErr          AS DWORD      ' __out DWORD    dwTimeoutErr
   dwAlignmentErr        AS DWORD      ' __out DWORD    dwAlignmentErr
   dwHardwareOverrunErr  AS DWORD      ' __out DWORD    dwHardwareOverrunErr
   dwFramingErr          AS DWORD      ' __out DWORD    dwFramingErr
   dwBufferOverrunErr    AS DWORD      ' __out DWORD    dwBufferOverrunErr
   dwCompressionRatioIn  AS DWORD      ' __out DWORD    dwCompressionRatioIn
   dwCompressionRatioOut AS DWORD      ' __out DWORD    dwCompressionRatioOut
END TYPE

'#if(WINVER >= 0x0500)

' // Size = 844 bytes
UNION RAS_CONNECTION_2_UNION   ' // For compability with PN includes
   guidX           AS GUID   ' GUID    Guid
   Guid            AS GUID   ' GUID    Guid
END UNION
TYPE RAS_CONNECTION_2 DWORD
   hConnection     AS DWORD        ' __out HANDLE hConnection
   wszUserName     AS WSTRINGZ * %UNLEN + 1   ' __out WCHAR wszUserName[ UNLEN + 1 ]
   dwInterfaceType AS DWORD        ' __out ROUTER_INTERFACE_TYPE dwInterfaceType
   RAS_CONNECTION_2_UNION
   PppInfo2        AS PPP_INFO_2   ' __out PPP_INFO_2 PppInfo2
END TYPE

'// indicates quarantine state of a client connection
' enum RAS_QUARANTINE_STATE
%RAS_QUAR_STATE_NORMAL      = 0
%RAS_QUAR_STATE_QUARANTINE  = 1
%RAS_QUAR_STATE_PROBATION   = 2
%RAS_QUAR_STATE_NOT_CAPABLE = 3
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0600)
' // Size = 788 bytes
UNION RAS_CONNECTION_3_UNION   ' // For compability with PN includes
   guidX           AS GUID   ' GUID    Guid
   Guid            AS GUID   ' GUID    Guid
END UNION
TYPE RAS_CONNECTION_3 DWORD FILL
   dwVersion       AS DWORD        ' DWORD
   dwSize          AS DWORD        ' DWORD
   hConnection     AS DWORD        ' HANDLE //connection handle
   wszUserName     AS WSTRINGZ * %UNLEN + 1   ' WCHAR[UNLEN + 1]
   dwInterfaceType AS LONG         ' ROUTER_INTERFACE_TYPE
   RAS_CONNECTION_3_UNION
   PppInfo3        AS PPP_INFO_3
   rasQuarState    AS LONG         ' RAS_QUARANTINE_STATE //Quarantine state of the connection
   timer           AS FILETIME     '  //Probation timer in UTC
END TYPE
'#endif /* WINVER >= 0x0600 */

'//
'// Structures used by the MPRADMIN USER APIs. Use level 0 to get/set this
'// structure.
'//
'//
'// Bits indicating user's Remote Access privileges and mask to isolate
'// call back privilege.
'//
'// Note: Bit 0 MUST represent NoCallback due to a quirk of the "userparms"
'//       storage method.  When a new LAN Manager user is created, bit 0 of the
'//       userparms field is set to 1 and all other bits are 0.  These bits are
'//       arranged so this "no Dial-In info" state maps to the "default Dial-In
'//       privilege" state.

%RASPRIV_NoCallback        = &H01?
%RASPRIV_AdminSetCallback  = &H02?
%RASPRIV_CallerSetCallback = &H04?
%RASPRIV_DialinPrivilege   = &H08?

'//
'// The following are flags for the bfPrivilege2 member of RAS_USER_1
'// structure
'//
%RASPRIV2_DialinPolicy     = &H1?

%RASPRIV_CallbackType = %RASPRIV_AdminSetCallback OR %RASPRIV_CallerSetCallback OR %RASPRIV_NoCallback

' // Size = 260 bytes
TYPE RAS_USER_0 BYTE
   bfPrivilege    AS BYTE   ' __out BYTE bfPrivilege
   wszPhoneNumber AS WSTRINGZ * %MAX_PHONE_NUMBER_LEN + 1   ' __out WCHAR wszPhoneNumber[ MAX_PHONE_NUMBER_LEN + 1]
   alignment__    AS BYTE
END TYPE

' // Size = 262 bytes
TYPE RAS_USER_1 BYTE
   bfPrivilege    AS BYTE   ' __out BYTE bfPrivilege
   wszPhoneNumber AS WSTRINGZ * %MAX_PHONE_NUMBER_LEN + 1   ' __out WCHAR wszPhoneNumber[ MAX_PHONE_NUMBER_LEN + 1]
   bfPrivilege2   AS BYTE   ' __out BYTE bfPrivilege2
   alignment__(1) AS BYTE
END TYPE

'#if(WINVER >= 0x0600)
' // Size = 4 bytes
TYPE MPR_FILTER_0 BYTE
   fEnable AS LONG   ' BOOL
END TYPE
'#endif /* WINVER >= 0x0600 */

'//
'// Used as RPC binding handle to server
'//

'typedef HANDLE RAS_SERVER_HANDLE;
'typedef HANDLE MPR_SERVER_HANDLE;
'typedef HANDLE MIB_SERVER_HANDLE;

'#if(WINVER >= 0x0601)

' // Size = 4 bytes
TYPE MPRAPI_OBJECT_HEADER BYTE
   revision AS BYTE   ' UCHAR
   type     AS BYTE   ' UCHAR
   size     AS WORD   ' USHORT
END TYPE

' enum MPRAPI_OBJECT_TYPE
%MPRAPI_OBJECT_TYPE_RAS_CONNECTION_OBJECT        = 1
%MPRAPI_OBJECT_TYPE_MPR_SERVER_OBJECT            = 2
%MPRAPI_OBJECT_TYPE_MPR_SERVER_SET_CONFIG_OBJECT = 3
%MPRAPI_OBJECT_TYPE_AUTH_VALIDATION_OBJECT       = 4
%MPRAPI_OBJECT_TYPE_UPDATE_CONNECTION_OBJECT     = 5

' // Size = 192 bytes
TYPE PPP_PROJECTION_INFO   ' Must be 8 byte aligned
   ' // IPv4 Projection Parameters
   dwIPv4NegotiationError         AS DWORD   ' DWORD
   wszAddress                     AS WSTRINGZ * %IPADDRESSLEN + 1   ' WCHAR(IPADDRESSLEN + 1]
   wszRemoteAddress               AS WSTRINGZ * %IPADDRESSLEN + 1   ' WCHAR(IPADDRESSLEN + 1]
   dwIPv4Options                  AS DWORD   ' DWORD
   dwIPv4RemoteOptions            AS DWORD   ' DWORD
   IPv4SubInterfaceIndex          AS QUAD    ' ULONG64
   ' // IPv6 Projection Parameters
   dwIPv6NegotiationError         AS DWORD   ' DWORD
   bInterfaceIdentifier(7)        AS BYTE    ' BYTE[8]
   bRemoteInterfaceIdentifier(7)  AS BYTE    ' BYTE[8]
   bPrefix(7)                     AS BYTE    ' BYTE[8]
   dwPrefixLength                 AS DWORD   ' DWORD
   alignment__                    AS DWORD   ' To keep 8 byte alignment
   IPv6SubInterfaceIndex          AS QUAD    ' ULONG64
   ' // LCP Options
   dwLcpError                     AS DWORD   ' DWORD
   dwAuthenticationProtocol       AS DWORD   ' DWORD
   dwAuthenticationData           AS DWORD   ' DWORD
   dwRemoteAuthenticationProtocol AS DWORD   ' DWORD
   dwRemoteAuthenticationData     AS DWORD   ' DWORD
   dwLcpTerminateReason           AS DWORD   ' DWORD
   dwLcpRemoteTerminateReason     AS DWORD   ' DWORD
   dwLcpOptions                   AS DWORD   ' DWORD
   dwLcpRemoteOptions             AS DWORD   ' DWORD
   dwEapTypeId                    AS DWORD   ' DWORD
   dwRemoteEapTypeId              AS DWORD   ' DWORD
   ' // CCP options:
   dwCcpError                     AS DWORD   ' DWORD
   dwCompressionAlgorithm         AS DWORD   ' DWORD
   dwCcpOptions                   AS DWORD   ' DWORD
   dwRemoteCompressionAlgorithm   AS DWORD   ' DWORD
   dwCcpRemoteOptions             AS DWORD   ' DWORD
END TYPE

%MPRAPI_IKEV2_AUTH_USING_CERT = 1
%MPRAPI_IKEV2_AUTH_USING_EAP  = 2

' // Size = 144 bytes
TYPE IKEV2_PROJECTION_INFO   ' Must be 8 byte aligned
   dwIPv4NegotiationError        AS DWORD   ' DWORD
   wszAddress                    AS WSTRINGZ * %IPADDRESSLEN + 1   ' WCHAR[IPADDRESSLEN + 1]
   wszRemoteAddress              AS WSTRINGZ * %IPADDRESSLEN + 1   ' WCHAR[IPADDRESSLEN + 1]
   IPv4SubInterfaceIndex         AS QUAD    ' ULONG64
   dwIPv6NegotiationError        AS DWORD   ' DWORD
   bInterfaceIdentifier(7)       AS BYTE    ' BYTE[8]
   bRemoteInterfaceIdentifier(7) AS BYTE    ' BYTE[8]
   bPrefix(7)                    AS BYTE    ' BYTE[8]
   dwPrefixLength                AS DWORD   ' DWORD
   alignment1__                  AS DWORD   ' To keep 8 byte alignment
   IPv6SubInterfaceIndex         AS QUAD    ' ULONG64
   dwOptions                     AS DWORD   ' DWORD
   dwAuthenticationProtocol      AS DWORD   ' DWORD
   dwEapTypeId                   AS DWORD   ' DWORD
   dwCompressionAlgorithm        AS DWORD   ' DWORD
   dwEncryptionMethod            AS DWORD   ' DWORD
   alignment2__                  AS DWORD   ' To keep 8 byte alignment
END TYPE

%MPRAPI_PPP_PROJECTION_INFO_TYPE   = 1
%MPRAPI_IKEV2_PROJECTION_INFO_TYPE = 2

' // Size = 192 bytes
UNION PROJECTION_INFO_UNION   ' Must be 8 byte aligned
   PppProjectionInfo   AS PPP_PROJECTION_INFO
   Ikev2ProjectionInfo AS IKEV2_PROJECTION_INFO
END UNION

' // Size = 200 bytes
TYPE PROJECTION_INFO QWORD FILL   ' Must be 8 byte aligned
   projectionInfoType AS BYTE   ' UCHAR
   ' // Based on the connectionFlags, it should use appropriate projection info
   PROJECTION_INFO_UNION
END TYPE

%MPRAPI_RAS_CONNECTION_OBJECT_REVISION_1 = &H1

' // Size = 1664 bytes
UNION RAS_CONNECTION_EX_UNION   ' // For compability with PN includes
   guidX           AS GUID   ' GUID    Guid
   Guid            AS GUID   ' GUID    Guid
END UNION
TYPE RAS_CONNECTION_EX QWORD FILL   ' Must be 8 byte aligned
   Header                   AS MPRAPI_OBJECT_HEADER
   dwConnectDuration        AS DWORD   ' DWORD
   dwInterfaceType          AS LONG    ' ROUTER_INTERFACE_TYPE
   dwConnectionFlags        AS DWORD   ' DWORD
   wszInterfaceName         AS WSTRINGZ * %MAX_INTERFACE_NAME_LEN + 1   ' WCHAR[MAX_INTERFACE_NAME_LEN + 1]
   wszUserName              AS WSTRINGZ * %UNLEN + 1   ' WCHAR[UNLEN + 1]
   wszLogonDomain           AS WSTRINGZ * %DNLEN + 1   ' WCHAR[DNLEN + 1]
   wszRemoteComputer        AS WSTRINGZ * %NETBIOS_NAME_LEN + 1   ' WCHAR[NETBIOS_NAME_LEN + 1]
   RAS_CONNECTION_EX_UNION
   rasQuarState             AS LONG    ' RAS_QUARANTINE_STATE
   probationTime            AS FILETIME
   ' // Statistics:
   dwBytesXmited            AS DWORD   ' DWORD
   dwBytesRcved             AS DWORD   ' DWORD
   dwFramesXmited           AS DWORD   ' DWORD
   dwFramesRcved            AS DWORD   ' DWORD
   dwCrcErr                 AS DWORD   ' DWORD
   dwTimeoutErr             AS DWORD   ' DWORD
   dwAlignmentErr           AS DWORD   ' DWORD
   dwHardwareOverrunErr     AS DWORD   ' DWORD
   dwFramingErr             AS DWORD   ' DWORD
   dwBufferOverrunErr       AS DWORD   ' DWORD
   dwCompressionRatioIn     AS DWORD   ' DWORD
   dwCompressionRatioOut    AS DWORD   ' DWORD
   ' // Currently valid only for IKEV2:
   dwNumSwitchOvers         AS DWORD   ' DWORD
   ' // Endpoint Information:
   wszRemoteEndpointAddress AS WSTRINGZ * %MAXIPADRESSLEN + 1   ' WCHAR[MAXIPADRESSLEN+1]
   wszLocalEndpointAddress  AS WSTRINGZ * %MAXIPADRESSLEN + 1   ' WCHAR[MAXIPADRESSLEN+1]
   ' //Projection result:
   ProjectionInfo           AS PROJECTION_INFO
   hConnection              AS DWORD   ' HANDLE
   hInterface               AS DWORD   ' HANDLE
END TYPE

'//----------- MPR_SERVER_EX object

' // Size = 28 bytes
TYPE IKEV2_TUNNEL_CONFIG_PARAMS DWORD
   dwIdleTimeout                AS DWORD                ' DWORD
   dwNetworkBlackoutTime        AS DWORD                ' DWORD
   dwSaLifeTime                 AS DWORD                ' DWORD
   dwSaDataSizeForRenegotiation AS DWORD                ' DWORD
   dwConfigOptions              AS DWORD                ' DWORD
   dwTotalCertificates          AS DWORD                ' DWORD
   certificateNames             AS CERT_NAME_BLOB PTR   ' CERT_NAME_BLOB *
END TYPE

%MPRAPI_IKEV2_SET_TUNNEL_CONFIG_PARAMS = &H1

' // Size = 40 bytes
TYPE IKEV2_CONFIG_PARAMS DWORD
   dwNumPorts               AS DWORD   ' DWORD
   dwPortFlags              AS DWORD   ' DWORD
   dwTunnelConfigParamFlags AS DWORD   ' DWORD
   TunnelConfigParams       AS IKEV2_TUNNEL_CONFIG_PARAMS
END TYPE

' // Size = 8 bytes
TYPE PPTP_CONFIG_PARAMS DWORD
   dwNumPorts  AS DWORD   ' DWORD
   dwPortFlags AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE L2TP_CONFIG_PARAMS DWORD
   dwNumPorts  AS DWORD   ' DWORD
   dwPortFlags AS DWORD   ' DWORD
END TYPE

%MAX_SSTP_HASH_SIZE = 32   ' // SHA-256 Certificate hash size

' // Size = 12 bytes
TYPE SSTP_CERT_INFO DWORD
   ' // Whether it is the default node [no cert config]
   isDefault AS LONG   ' BOOL
   certBlob  AS CRYPT_HASH_BLOB
END TYPE

' // Size = 28 bytes
TYPE SSTP_CONFIG_PARAMS DWORD
   dwNumPorts      AS DWORD   ' DWORD
   dwPortFlags     AS DWORD   ' DWORD
   isUseHttps      AS LONG    ' BOOL
   certAlgorithm   AS DWORD   ' DWORD // Should always be CALG_SHA_256
   sstpCertDetails AS SSTP_CERT_INFO
END TYPE

' // Size = 84 bytes
TYPE MPRAPI_TUNNEL_CONFIG_PARAMS DWORD
   IkeConfigParams  AS IKEV2_CONFIG_PARAMS
   PptpConfigParams AS PPTP_CONFIG_PARAMS
   L2tpConfigParams AS L2TP_CONFIG_PARAMS
   SstpConfigParams AS SSTP_CONFIG_PARAMS
END TYPE

%MPRAPI_MPR_SERVER_OBJECT_REVISION_1 = &H1

' // Size = 108 bytes
TYPE MPR_SERVER_EX DWORD
   Header       AS MPRAPI_OBJECT_HEADER
   fLanOnlyMode AS DWORD   ' DWORD
   dwUpTime     AS DWORD   ' DWORD
   dwTotalPorts AS DWORD   ' DWORD
   dwPortsInUse AS DWORD   ' DWORD
   Reserved     AS DWORD   ' DWORD // Added so that the structure is 8 byte aligned
   ConfigParams AS MPRAPI_TUNNEL_CONFIG_PARAMS
END TYPE

%MPRAPI_MPR_SERVER_SET_CONFIG_OBJECT_REVISION_1 = &H1

%MPRAPI_SET_CONFIG_PROTOCOL_FOR_PPTP            = &H1
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_L2TP            = &H2
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_SSTP            = &H4
%MPRAPI_SET_CONFIG_PROTOCOL_FOR_IKEV2           = &H8

' // Size = 92 bytes
TYPE MPR_SERVER_SET_CONFIG_EX DWORD
   Header                AS MPRAPI_OBJECT_HEADER
   setConfigForProtocols AS DWORD   ' DWORD
   ConfigParams          AS MPRAPI_TUNNEL_CONFIG_PARAMS
END TYPE

%ALLOW_NO_AUTH        = 1
%DO_NOT_ALLOW_NO_AUTH = 0

' // Size = 564 bytes
TYPE AUTH_VALIDATION_EX DWORD
   Header         AS MPRAPI_OBJECT_HEADER
   hRasConnection AS DWORD                   ' HANDLE
   wszUserName    AS WSTRINGZ * %UNLEN + 1   ' [UNLEN + 1]
   wszLogonDomain AS WSTRINGZ * %DNLEN + 1   ' [DNLEN + 1]
   AuthInfoSize   AS DWORD                   ' DWORD
   AuthInfo(0)    AS BYTE                    ' BYTE[1]
END TYPE

%MPRAPI_RAS_UPDATE_CONNECTION_OBJECT_REVISION_1 = &H1

' // Size = 268 bytes
TYPE RAS_UPDATE_CONNECTION BYTE
   Header                   AS MPRAPI_OBJECT_HEADER
   dwIfIndex                AS DWORD                            ' DWORD
   wszLocalEndpointAddress  AS WSTRINGZ * %MAXIPADRESSLEN + 1   ' WCHAR[MAXIPADRESSLEN+1]
   wszRemoteEndpointAddress AS WSTRINGZ * %MAXIPADRESSLEN + 1   ' WCHAR[MAXIPADRESSLEN+1]
END TYPE

'// RAS Admin Functions:
DECLARE FUNCTION MprAdminConnectionEnumEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionEnumEx" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE     hRasServer
 , BYREF pObjectHeader AS MPRAPI_OBJECT_HEADER _        ' __in  PMPRAPI_OBJECT_HEADER pObjectHeader
 , BYVAL dwPreferedMaxLen AS DWORD _                    ' __in  DWORD                 dwPreferedMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD               lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD               lpdwTotalEntries
 , BYREF ppRasConn AS ANY _                             ' __out PRAS_CONNECTION_EX *  ppRasConn
 , BYREF MprAdminConnectionEnumEx AS DWORD _            ' __in  LPDWORD               lpdwResumeHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminConnectionGetInfoEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionGetInfoEx" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE  hRasServer
 , BYVAL hRasConnection AS DWORD _                      ' __in  HANDLE             hRasConnection
 , BYREF pRasConnection AS RAS_CONNECTION_EX _          ' __out PRAS_CONNECTION_EX pRasConnection
 ) AS DWORD                                             ' DWORD
' // Use MprAdminBufferFree for freeing pRASCONN

'// Router Admin Functions:
DECLARE FUNCTION MprAdminServerGetInfoEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerGetInfoEx" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYREF pServerInfo AS MPR_SERVER_EX _                 ' __out MPR_SERVER_EX*    pServerInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminServerSetInfoEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerSetInfoEx" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE         hMprServer
 , BYREF pServerInfo AS MPR_SERVER_SET_CONFIG_EX _      ' __out MPR_SERVER_SET_CONFIG_EX* pServerInfo
 ) AS DWORD                                             ' DWORD

'// Router Config Functions:

DECLARE FUNCTION MprConfigServerGetInfoEx IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerGetInfoEx" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE         hMprConfig
 , BYREF pServerInfo AS MPR_SERVER_EX _                 ' __out MPR_SERVER_EX* pServerInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigServerSetInfoEx IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerSetInfoEx" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE         hMprConfig
 , BYREF pSetServerConfig AS MPR_SERVER_SET_CONFIG_EX _ ' __out MPR_SERVER_SET_CONFIG_EX* pSetServerConfig
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminUpdateConnection IMPORT "MPRAPI.DLL" ALIAS "MprAdminUpdateConnection" ( _
   BYVAL hRasServer AS DWORD _                          ' __in RAS_SERVER_HANDLE       hRasServer
 , BYVAL hRasConnection AS DWORD _                      ' __in HANDLE                  hRasConnection
 , BYREF pRasUpdateConnection AS RAS_UPDATE_CONNECTION _ ' __in PRAS_UPDATE_CONNECTION  pRasUpdateConnection
 ) AS DWORD                                             ' DWORD

'// Admin DLL's:
%MPRAPI_ADMIN_DLL_VERSION_1 = &H1
%MPRAPI_ADMIN_DLL_VERSION_2 = &H2   ' // If the version is 2: it can use RAS_CONNECTION_EX supported in Windows 7.0

'typedef DWORD (APIENTRY * PMPRADMINGETIPADDRESSFORUSER)(WCHAR *, WCHAR *, DWORD *, BOOL *);
'typedef VOID  (APIENTRY * PMPRADMINRELEASEIPADRESS)(WCHAR *, WCHAR *, DWORD *);
'typedef DWORD (APIENTRY * PMPRADMINGETIPV6ADDRESSFORUSER)(WCHAR *, WCHAR *, IN6_ADDR *, BOOL *);
'typedef VOID  (APIENTRY * PMPRADMINRELEASEIPV6ADDRESSFORUSER)(WCHAR *, WCHAR *, IN6_ADDR *);
'typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWCONNECTION)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *);
'typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWCONNECTION2)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *, RAS_CONNECTION_2 *);
'typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWCONNECTION3)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *, RAS_CONNECTION_2 *, RAS_CONNECTION_3 *);
'typedef BOOL  (APIENTRY * PMPRADMINACCEPTNEWLINK)(RAS_PORT_0 *, RAS_PORT_1 *);
'typedef VOID  (APIENTRY * PMPRADMINCONNECTIONHANGUPNOTIFICATION)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *);
'typedef VOID  (APIENTRY * PMPRADMINCONNECTIONHANGUPNOTIFICATION2)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *, RAS_CONNECTION_2 *);
'typedef VOID  (APIENTRY * PMPRADMINCONNECTIONHANGUPNOTIFICATION3)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *, RAS_CONNECTION_2 *, RAS_CONNECTION_3);
'typedef VOID  (APIENTRY * PMPRADMINLINKHANGUPNOTIFICATION)(RAS_PORT_0 *, RAS_PORT_1 *);
'typedef DWORD (APIENTRY * PMPRADMINTERMINATEDLL)();
'typedef BOOL  (APIENTRY * PMPRADMINACCEPTREAUTHENTICATION)(RAS_CONNECTION_0 *, RAS_CONNECTION_1 *, RAS_CONNECTION_2 *, RAS_CONNECTION_3 *);
'typedef BOOL  (APIENTRY *PMPRADMINACCEPTNEWCONNECTIONEX)(RAS_CONNECTION_EX*);
'typedef BOOL  (APIENTRY *PMPRADMINACCEPTREAUTHENTICATIONEX)(RAS_CONNECTION_EX*);
'typedef BOOL  (APIENTRY *PMPRADMINACCEPTTUNNELENDPOINTCHANGEEX)(RAS_CONNECTION_EX*);
'typedef VOID  (APIENTRY *PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX)(RAS_CONNECTION_EX*);
'typedef DWORD (APIENTRY *PMPRADMINRASVALIDATEPREAUTHENTICATEDCONNECTIONEX) (AUTH_VALIDATION_EX *);

' // Size = 52 bytes
TYPE MPRAPI_ADMIN_DLL_CALLBACKS DWORD FILL
   revision                                    AS BYTE    ' UCHAR
   lpfnMprAdminGetIpAddressForUser             AS DWORD   ' PMPRADMINGETIPADDRESSFORUSER
   lpfnMprAdminReleaseIpAddress                AS DWORD   ' PMPRADMINRELEASEIPADRESS
   lpfnMprAdminGetIpv6AddressForUser           AS DWORD   ' PMPRADMINGETIPV6ADDRESSFORUSER
   lpfnMprAdminReleaseIpV6AddressForUser       AS DWORD   ' PMPRADMINRELEASEIPV6ADDRESSFORUSER
   lpfnRasAdminAcceptNewLink                   AS DWORD   ' PMPRADMINACCEPTNEWLINK
   lpfnRasAdminLinkHangupNotification          AS DWORD   ' PMPRADMINLINKHANGUPNOTIFICATION
   lpfnRasAdminTerminateDll                    AS DWORD   ' PMPRADMINTERMINATEDLL
   lpfnRasAdminAcceptNewConnectionEx           AS DWORD   ' PMPRADMINACCEPTNEWCONNECTIONEX
   lpfnRasAdminAcceptEndpointChangeEx          AS DWORD   ' PMPRADMINACCEPTTUNNELENDPOINTCHANGEEX
   lpfnRasAdminAcceptReauthenticationEx        AS DWORD   ' PMPRADMINACCEPTREAUTHENTICATIONEX
   lpfnRasAdminConnectionHangupNotificationEx  AS DWORD   ' PMPRADMINCONNECTIONHANGUPNOTIFICATIONEX
   lpfnRASValidatePreAuthenticatedConnectionEx AS DWORD   ' PMPRADMINRASVALIDATEPREAUTHENTICATEDCONNECTIONEX
END TYPE

DECLARE FUNCTION MprAdminAcceptNewConnectionEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptNewConnectionEx" ( _
   BYREF pRasConn AS RAS_CONNECTION_EX _                ' __in RAS_CONNECTION_EX* pRasConn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MprAdminAcceptReauthenticationEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptReauthenticationEx" ( _
   BYREF pRasConn AS RAS_CONNECTION_EX _                ' __in RAS_CONNECTION_EX* pRasConn
 ) AS LONG                                              ' BOOL

DECLARE SUB MprAdminConnectionHangupNotificationEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionHangupNotificationEx" ( _
   BYREF pRasConn AS RAS_CONNECTION_EX _                ' __in RAS_CONNECTION_EX* pRasConn
 )                                                      ' void

DECLARE FUNCTION MprAdminInitializeDllEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminInitializeDllEx" ( _
   BYREF pAdminCallbacks AS MPRAPI_ADMIN_DLL_CALLBACKS _ ' __in PMPRAPI_ADMIN_DLL_CALLBACKS pAdminCallbacks
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminIsServiceInitialized IMPORT "MPRAPI.DLL" ALIAS "MprAdminIsServiceInitialized" ( _
   BYREF lpwsServerName AS WSTRINGZ _                   ' __in LPWSTR lpwsServerName
 , BYREF fIsServiceInitialized AS LONG _                ' __in BOOL   *fIsServiceInitialized
 ) AS DWORD                                             ' DWORD

'#endif /* WINVER >= 0x0601 */

'//
'//  RAS ADMIN APIs
'//

DECLARE FUNCTION MprAdminConnectionEnum IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionEnum" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE hRasServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in  DWORD             dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD           lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD           lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in  LPDWORD           lpdwResumeHandle OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminPortEnum IMPORT "MPRAPI.DLL" ALIAS "MprAdminPortEnum" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE hRasServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYVAL hConnection AS DWORD _                         ' __in  HANDLE            hConnection
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in  DWORD             dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD           lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD           lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in  LPDWORD           lpdwResumeHandle OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminConnectionGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionGetInfo" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE hRasServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYVAL hConnection AS DWORD _                         ' __in  HANDLE            hConnection
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminPortGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminPortGetInfo" ( _
   BYVAL hRasServer AS DWORD _                          ' __in  RAS_SERVER_HANDLE hRasServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYVAL hPort AS DWORD _                               ' __in  HANDLE            hPort
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminConnectionClearStats IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionClearStats" ( _
   BYVAL hRasServer AS DWORD _                          ' __in RAS_SERVER_HANDLE hRasServer
 , BYVAL hConnection AS DWORD _                         ' __in HANDLE            hConnection
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminPortClearStats IMPORT "MPRAPI.DLL" ALIAS "MprAdminPortClearStats" ( _
   BYVAL hRasServer AS DWORD _                          ' __in RAS_SERVER_HANDLE hRasServer
 , BYVAL hPort AS DWORD _                               ' __in HANDLE            hPort
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminPortReset IMPORT "MPRAPI.DLL" ALIAS "MprAdminPortReset" ( _
   BYVAL hRasServer AS DWORD _                          ' __in RAS_SERVER_HANDLE hRasServer
 , BYVAL hPort AS DWORD _                               ' __in HANDLE            hPort
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminPortDisconnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminPortDisconnect" ( _
   BYVAL hRasServer AS DWORD _                          ' __in RAS_SERVER_HANDLE hRasServer
 , BYVAL hPort AS DWORD _                               ' __in HANDLE            hPort
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminAcceptNewConnection IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptNewConnection" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminAcceptNewConnection2 IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptNewConnection2" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 , BYREF pRasConnection2 AS RAS_CONNECTION_2 _          ' __in RAS_CONNECTION_2 * pRasConnection2
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0600)
DECLARE FUNCTION MprAdminAcceptNewConnection3 IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptNewConnection3" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 , BYREF pRasConnection2 AS RAS_CONNECTION_2 _          ' __in RAS_CONNECTION_2 * pRasConnection2
 , BYREF pRasConnection3 AS RAS_CONNECTION_3 _          ' __in RAS_CONNECTION_3 * pRasConnection3
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MprAdminAcceptReauthentication IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptReauthentication" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 , BYREF pRasConnection2 AS RAS_CONNECTION_2 _          ' __in RAS_CONNECTION_2 * pRasConnection2
 , BYREF pRasConnection3 AS RAS_CONNECTION_3 _          ' __in RAS_CONNECTION_3 * pRasConnection3
 ) AS LONG                                              ' BOOL
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION MprAdminAcceptNewLink IMPORT "MPRAPI.DLL" ALIAS "MprAdminAcceptNewLink" ( _
   BYREF pRasPort0 AS RAS_PORT_0 _                      ' __in RAS_PORT_0 * pRasPort0
 , BYREF pRasPort1 AS RAS_PORT_1 _                      ' __in RAS_PORT_1 * pRasPort1
 ) AS LONG                                              ' BOOL

DECLARE SUB MprAdminConnectionHangupNotification IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionHangupNotification" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 )                                                      ' void

'#if(WINVER >= 0x0500)
DECLARE SUB MprAdminConnectionHangupNotification2 IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionHangupNotification2" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 , BYREF pRasConnection2 AS RAS_CONNECTION_2 _          ' __in RAS_CONNECTION_2 * pRasConnection2
 )                                                      ' void
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0600)
DECLARE SUB MprAdminConnectionHangupNotification3 IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionHangupNotification3" ( _
   BYREF pRasConnection0 AS RAS_CONNECTION_0 _          ' __in RAS_CONNECTION_0 * pRasConnection0
 , BYREF pRasConnection1 AS RAS_CONNECTION_1 _          ' __in RAS_CONNECTION_1 * pRasConnection1
 , BYREF pRasConnection2 AS RAS_CONNECTION_2 _          ' __in RAS_CONNECTION_2 * pRasConnection2
 , BYREF pRasConnection3 AS RAS_CONNECTION_3 _          ' __in RAS_CONNECTION_3 * pRasConnection3
 )                                                      ' void
'#endif /* WINVER >= 0x0600 */

'#if (WINVER >= 0x501)
DECLARE FUNCTION MprAdminConnectionRemoveQuarantine IMPORT "MPRAPI.DLL" ALIAS "MprAdminConnectionRemoveQuarantine" ( _
   BYVAL hRasServer AS DWORD _                          ' __in HANDLE hRasServer
 , BYVAL hRasConnection AS DWORD _                      ' __in HANDLE hRasConnection
 , BYVAL fIsIpAddress AS LONG _                         ' __in BOOL   fIsIpAddress
 ) AS DWORD                                             ' DWORD
'#endif

DECLARE SUB MprAdminLinkHangupNotification IMPORT "MPRAPI.DLL" ALIAS "MprAdminLinkHangupNotification" ( _
   BYREF pRasPort0 AS RAS_PORT_0 _                      ' __in RAS_PORT_0 * pRasPort0
 , BYREF pRasPort1 AS RAS_PORT_1 _                      ' __in RAS_PORT_1 * pRasPort1
 )                                                      ' void

DECLARE FUNCTION MprAdminGetIpAddressForUser IMPORT "MPRAPI.DLL" ALIAS "MprAdminGetIpAddressForUser" ( _
   BYREF lpwszUserName AS WSTRINGZ _                    ' __in     WCHAR * lpwszUserName
 , BYREF lpwszPortName AS WSTRINGZ _                    ' __in     WCHAR * lpwszPortName
 , BYREF lpdwIpAddress AS DWORD _                       ' __in_out DWORD * lpdwIpAddress
 , BYREF bNotifyRelease AS LONG _                       ' __out    BOOL *  bNotifyRelease
 ) AS DWORD                                             ' DWORD

DECLARE SUB MprAdminReleaseIpAddress IMPORT "MPRAPI.DLL" ALIAS "MprAdminReleaseIpAddress" ( _
   BYREF lpszUserName AS WSTRINGZ _                     ' __in WCHAR * lpszUserName
 , BYREF lpszPortName AS WSTRINGZ _                     ' __in WCHAR * lpszPortName
 , BYREF lpdwIpAddress AS DWORD _                       ' __in DWORD * lpdwIpAddress
 )                                                      ' void

'#if(WINVER >= 0x0600)

DECLARE FUNCTION MprAdminGetIpv6AddressForUser IMPORT "MPRAPI.DLL" ALIAS "MprAdminGetIpv6AddressForUser" ( _
   BYREF lpwszUserName AS WSTRINGZ _                    ' __in     WCHAR * lpwszUserName
 , BYREF lpwszPortName AS WSTRINGZ _                    ' __in     WCHAR * lpwszPortName
 , BYREF lpdwIpv6Address AS IN6_ADDR _                  ' __in_out IN6_ADDR * lpdwIpv6Address   ' /* Currently Only 64 Bit Identifier is supported */
 , BYREF bNotifyRelease AS LONG _                       ' __out    BOOL *  bNotifyRelease
 ) AS DWORD                                             ' DWORD

DECLARE SUB MprAdminReleaseIpv6AddressForUser IMPORT "MPRAPI.DLL" ALIAS "MprAdminReleaseIpv6AddressForUser" ( _
   BYREF lpszUserName AS WSTRINGZ _                     ' __in WCHAR * lpszUserName
 , BYREF lpszPortName AS WSTRINGZ _                     ' __in WCHAR * lpszPortName
 , BYREF lpdwIpv6Address AS IN6_ADDR _                  ' __in IN6_ADDR * lpdwIpv6Address
 )                                                      ' void

'#endif /* WINVER >= 0x0600 */

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminInitializeDll IMPORT "MPRAPI.DLL" ALIAS "MprAdminInitializeDll" ( _
 ) AS DWORD                                             ' DWORD
DECLARE FUNCTION MprAdminTerminateDll IMPORT "MPRAPI.DLL" ALIAS "MprAdminTerminateDll" ( _
 ) AS DWORD                                             ' DWORD
'#endif

'//
'// MprAdminUser APIs
'//

DECLARE FUNCTION MprAdminUserGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminUserGetInfo" ( _
   BYREF lpszServer AS WSTRINGZ _                       ' __in  const WCHAR * lpszServer
 , BYREF lpszUser AS WSTRINGZ _                         ' __in  const WCHAR * lpszUser
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD         dwLevel
 , BYREF lpbBuffer AS ANY _                             ' __out LPBYTE        lpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminUserSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminUserSetInfo" ( _
   BYREF lpszServer AS WSTRINGZ _                       ' __in const WCHAR * lpszServer
 , BYREF lpszUser AS WSTRINGZ _                         ' __in const WCHAR * lpszUser
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD         dwLevel
 , BYREF lpbBuffer AS ANY _                             ' __in const LPBYTE  lpbBuffer
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminSendUserMessage IMPORT "MPRAPI.DLL" ALIAS "MprAdminSendUserMessage" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hConnection AS DWORD _                         ' __in HANDLE            hConnection
 , BYREF lpwszMessage AS WSTRINGZ _                     ' __in LPWSTR            lpwszMessage
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION MprAdminGetPDCServer IMPORT "MPRAPI.DLL" ALIAS "MprAdminGetPDCServer" ( _
   BYREF lpszDomain AS WSTRINGZ _                       ' __in  const WCHAR * lpszDomain
 , BYREF lpszServer AS WSTRINGZ _                       ' __in  const WCHAR * lpszServer
 , BYREF lpszPDCServer AS WSTRINGZ _                    ' __out LPWSTR        lpszPDCServer
 ) AS DWORD                                             ' DWORD

'//
'// Router APIs
'//

DECLARE FUNCTION MprAdminIsServiceRunning IMPORT "MPRAPI.DLL" ALIAS "MprAdminIsServiceRunning" ( _
   BYREF lpwsServerName AS WSTRINGZ _                   ' __in  LPWSTR lpwsServerName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MprAdminServerConnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerConnect" ( _
   BYREF lpwsServerName AS WSTRINGZ _                   ' __in  LPWSTR lpwsServerName OPTIONAL
 , BYREF phMprServer AS DWORD _                         ' __out MPR_SERVER_HANDLE * phMprServer
 ) AS DWORD                                             ' DWORD

DECLARE SUB MprAdminServerDisconnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerDisconnect" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 )                                                      ' void

'#if (WINVER >= 0x501)
DECLARE FUNCTION MprAdminServerGetCredentials IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerGetCredentials" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF lplpbBuffer AS ANY _                           ' __in  LPBYTE *          lplpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminServerSetCredentials IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerSetCredentials" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYVAL lplpbBuffer AS BYTE PTR _                      ' __in  LPBYTE            lplpbBuffer
 ) AS DWORD                                             ' DWORD
'#endif

DECLARE FUNCTION MprAdminBufferFree IMPORT "MPRAPI.DLL" ALIAS "MprAdminBufferFree" ( _
   BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminGetErrorString IMPORT "MPRAPI.DLL" ALIAS "MprAdminGetErrorString" ( _
   BYVAL dwError AS DWORD _                             ' __in DWORD dwError
 , BYREF lpwsErrorString AS ANY _                       ' __out LPWSTR * lpwsErrorString
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminServerGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerGetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 ) AS DWORD                                             ' DWORD

'#if (WINVER >= 0x501)
DECLARE FUNCTION MprAdminServerSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminServerSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in LPBYTE            lpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminEstablishDomainRasServer IMPORT "MPRAPI.DLL" ALIAS "MprAdminEstablishDomainRasServer" ( _
   BYREF pszDomain AS WSTRINGZ _                        ' __in PWCHAR pszDomain
 , BYREF pszMachine AS WSTRINGZ _                       ' __in PWCHAR pszMachine
 , BYVAL bEnable AS LONG _                              ' __in BOOL   bEnable
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminIsDomainRasServer IMPORT "MPRAPI.DLL" ALIAS "MprAdminIsDomainRasServer" ( _
   BYREF pszDomain AS WSTRINGZ _                        ' __in  PWCHAR pszDomain
 , BYREF pszMachine AS WSTRINGZ _                       ' __in  PWCHAR pszMachine
 , BYREF pbIsRasServer AS LONG _                        ' __out PBOOL  pbIsRasServer
 ) AS DWORD                                             ' DWORD
'#endif

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminTransportCreate IMPORT "MPRAPI.DLL" ALIAS "MprAdminTransportCreate" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD             dwTransportId
 , BYREF lpwsTransportName AS WSTRINGZ _                ' __in LPWSTR            lpwsTransportName           OPTIONAL
 , BYVAL pGlobalInfo AS BYTE PTR _                      ' __in LPBYTE            pGlobalInfo
 , BYVAL dwGlobalInfoSize AS DWORD _                    ' __in DWORD             dwGlobalInfoSize
 , BYVAL pClientInterfaceInfo AS BYTE PTR _             ' __in LPBYTE            pClientInterfaceInfo        OPTIONAL
 , BYVAL dwClientInterfaceInfoSize AS DWORD _           ' __in DWORD             dwClientInterfaceInfoSize   OPTIONAL
 , BYREF lpwsDLLPath AS WSTRINGZ _                      ' __in LPWSTR            lpwsDLLPath
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION MprAdminTransportSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminTransportSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD             dwTransportId
 , BYVAL pGlobalInfo AS BYTE PTR _                      ' __in LPBYTE            pGlobalInfo                 OPTIONAL
 , BYVAL dwGlobalInfoSize AS DWORD _                    ' __in DWORD             dwGlobalInfoSize
 , BYVAL pClientInterfaceInfo AS BYTE PTR _             ' __in LPBYTE            pClientInterfaceInfo        OPTIONAL
 , BYVAL dwClientInterfaceInfoSize AS DWORD _           ' __in DWORD             dwClientInterfaceInfoSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminTransportGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminTransportGetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD             dwTransportId
 , OPTIONAL BYREF ppGlobalInfo AS ANY _                 ' __out LPBYTE *          ppGlobalInfo                OPTIONAL
 , OPTIONAL BYREF lpdwGlobalInfoSize AS DWORD _         ' __out LPDWORD           lpdwGlobalInfoSize          OPTIONAL
 , OPTIONAL BYREF ppClientInterfaceInfo AS ANY _        ' __out LPBYTE *          ppClientInterfaceInfo       OPTIONAL
 , OPTIONAL BYREF lpdwClientInterfaceInfoSize AS DWORD _ ' __out LPDWORD          lpdwClientInterfaceInfoSize OPTIONAL
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminDeviceEnum IMPORT "MPRAPI.DLL" ALIAS "MprAdminDeviceEnum" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF lplpbBuffer AS ANY _                           ' __out LPBYTE*           lplpbBuffer
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD           lpdwTotalEntries
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION MprAdminInterfaceGetHandle IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceGetHandle" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYREF lpwsInterfaceName AS WSTRINGZ _                ' __in  LPWSTR            lpwsInterfaceName
 , BYREF phInterface AS DWORD _                         ' __out HANDLE *          phInterface
 , BYVAL fIncludeClientInterfaces AS LONG _             ' __in  BOOL              fIncludeClientInterfaces
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceCreate IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceCreate" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in  LPBYTE            lpbBuffer
 , BYREF phInterface AS DWORD _                         ' __out HANDLE *          phInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceGetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYREF lplpbBuffer AS ANY _                           ' __in LPBYTE *          lplpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in LPBYTE            lpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceDelete IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceDelete" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminInterfaceDeviceGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceDeviceGetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in  HANDLE            hInterface
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD             dwIndex
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF lplpBuffer AS ANY _                            ' __out LPBYTE*           lplpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceDeviceSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceDeviceSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD             dwIndex
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYVAL lplpBuffer AS BYTE PTR _                       ' __in LPBYTE            lplpBuffer
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION MprAdminInterfaceTransportRemove IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceTransportRemove" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD             dwTransportId
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceTransportAdd IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceTransportAdd" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD             dwTransportId
 , BYVAL pInterfaceInfo AS BYTE PTR _                   ' __in LPBYTE            pInterfaceInfo
 , BYVAL dwInterfaceInfoSize AS DWORD _                 ' __in DWORD             dwInterfaceInfoSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceTransportGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceTransportGetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in  HANDLE            hInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD             dwTransportId
 , BYREF ppInterfaceInfo AS ANY _                       ' __out LPBYTE *          ppInterfaceInfo
 , OPTIONAL BYREF lpdwpInterfaceInfoSize AS DWORD _     ' __out LPDWORD           lpdwpInterfaceInfoSize  OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceTransportSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceTransportSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD             dwTransportId
 , BYVAL pInterfaceInfo AS BYTE PTR _                   ' __in LPBYTE            pInterfaceInfo
 , BYVAL dwInterfaceInfoSize AS DWORD _                 ' __in DWORD             dwInterfaceInfoSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceEnum IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceEnum" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD             dwLevel
 , BYREF plpbBuffer AS ANY _                            ' __out LPBYTE *          lplpbBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in  DWORD             dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD           lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD           lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in  LPDWORD           lpdwResumeHandle        OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameEnum IMPORT "MPRAPI.DLL" ALIAS "MprSetupIpInIpInterfaceFriendlyNameEnum" ( _
   BYREF pwszMachineName AS WSTRINGZ _                  ' __in  PWCHAR  pwszMachineName
 , BYREF lplpBuffer AS ANY _                            ' __out LPBYTE* lplpBuffer
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD lpdwEntriesRead
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameFree IMPORT "MPRAPI.DLL" ALIAS "MprSetupIpInIpInterfaceFriendlyNameFree" ( _
   BYVAL lpBuffer AS DWORD _                            ' __in LPVOID lpBuffer
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameCreate LIB "MprApi.dll" _
    ALIAS "MprSetupIpInIpInterfaceFriendlyNameCreate" ( _
    pwszMachineName        AS WSTRINGZ, _
    BYVAL pNameInformation AS MPR_IPINIP_INTERFACE_0 PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameCreate IMPORT "MPRAPI.DLL" ALIAS "MprSetupIpInIpInterfaceFriendlyNameCreate" ( _
   BYREF pwszMachineName AS WSTRINGZ _                  ' __in PWCHAR                 pwszMachineName
 , BYREF pNameInformation AS MPR_IPINIP_INTERFACE_0 _   ' __in MPR_IPINIP_INTERFACE_0 pNameInformation
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION MprSetupIpInIpInterfaceFriendlyNameDelete IMPORT "MPRAPI.DLL" ALIAS "MprSetupIpInIpInterfaceFriendlyNameDelete" ( _
   BYREF pwszMachineName AS WSTRINGZ _                  ' __in PWCHAR pwszMachineName
 , BYREF pGuid AS GUID _                                ' __in GUID   *pGuid
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceSetCredentials IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceSetCredentials" ( _
   BYREF lpwsServer AS WSTRINGZ _                       ' __in LPWSTR lpwsServer        OPTIONAL
 , BYREF lpwsInterfaceName AS WSTRINGZ _                ' __in LPWSTR lpwsInterfaceName
 , OPTIONAL BYREF lpwsUserName AS WSTRINGZ _            ' __in LPWSTR lpwsUserName      OPTIONAL
 , OPTIONAL BYREF lpwsDomainName AS WSTRINGZ _          ' __in LPWSTR lpwsDomainName    OPTIONAL
 , OPTIONAL BYREF lpwsPassword AS WSTRINGZ _            ' __in LPWSTR lpwsPassword      OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceGetCredentials IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceGetCredentials" ( _
   BYREF lpwsServer AS WSTRINGZ _                       ' __in  LPWSTR lpwsServer        OPTIONAL
 , BYREF lpwsInterfaceName AS WSTRINGZ _                ' __in  LPWSTR lpwsInterfaceName
 , OPTIONAL BYREF lpwsUserName AS WSTRINGZ _            ' __out LPWSTR lpwsUserName      OPTIONAL
 , OPTIONAL BYREF lpwsPassword AS WSTRINGZ _            ' __out LPWSTR lpwsPassword      OPTIONAL
 , OPTIONAL BYREF lpwsDomainName AS WSTRINGZ _          ' __out LPWSTR lpwsDomainName    OPTIONAL
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminInterfaceSetCredentialsEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceSetCredentialsEx" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in LPBYTE            lpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceGetCredentialsEx IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceGetCredentialsEx" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYREF lplpbBuffer AS ANY _                           ' __out LPBYTE          *lplpbBuffer
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION MprAdminInterfaceConnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceConnect" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE            hEvent
 , BYVAL fSynchronous AS LONG _                         ' __in BOOL              fSynchronous
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceDisconnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceDisconnect" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceUpdateRoutes IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceUpdateRoutes" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 , BYVAL dwProtocolId AS DWORD _                        ' __in DWORD             dwProtocolId
 , BYVAL hEvent AS DWORD _                              ' __in HANDLE            hEvent
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceQueryUpdateResult IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceQueryUpdateResult" ( _
   BYVAL hMprServer AS DWORD _                          ' __in  MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in  HANDLE            hInterface
 , BYVAL dwProtocolId AS DWORD _                        ' __in  DWORD             dwProtocolId
 , BYREF lpdwUpdateResult AS DWORD _                    ' __out LPDWORD           lpdwUpdateResult
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminInterfaceUpdatePhonebookInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminInterfaceUpdatePhonebookInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hInterface AS DWORD _                          ' __in HANDLE            hInterface
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0500)
DECLARE FUNCTION MprAdminRegisterConnectionNotification IMPORT "MPRAPI.DLL" ALIAS "MprAdminRegisterConnectionNotification" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hEventNotification AS DWORD _                  ' __in HANDLE hEventNotification
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminDeregisterConnectionNotification IMPORT "MPRAPI.DLL" ALIAS "MprAdminDeregisterConnectionNotification" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL hEventNotification AS DWORD _                  ' __in HANDLE hEventNotification
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

'//
'// MIB APIs
'//

DECLARE FUNCTION MprAdminMIBServerConnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBServerConnect" ( _
   BYREF lpwsServerName AS WSTRINGZ _                   ' __in  LPWSTR              lpwsServerName OPTIONAL
 , BYREF phMibServer AS DWORD _                         ' __out MIB_SERVER_HANDLE * phMibServer
 ) AS DWORD                                             ' DWORD

DECLARE SUB MprAdminMIBServerDisconnect IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBServerDisconnect" ( _
   BYVAL hMibServer AS DWORD _                          ' __in MIB_SERVER_HANDLE hMibServer
 )                                                      ' void

DECLARE FUNCTION MprAdminMIBEntryCreate IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntryCreate" ( _
   BYVAL hMibServer AS DWORD _                          ' __in MIB_SERVER_HANDLE hMibServer
 , BYVAL dwPid AS DWORD _                               ' __in DWORD             dwPid
 , BYVAL dwRoutingPid AS DWORD _                        ' __in DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in DWORD             dwEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBEntryDelete IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntryDelete" ( _
   BYVAL hMibServer AS DWORD _                          ' __in MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in DWORD             dwEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBEntrySet IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntrySet" ( _
   BYVAL hMibServer AS DWORD _                          ' __in MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in DWORD             dwEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBEntryGet IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntryGet" ( _
   BYVAL hMibServer AS DWORD _                          ' __in  MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in  DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in  DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in  LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in  DWORD             dwEntrySize
 , BYREF lplpOutEntry AS ANY _                          ' __out LPVOID*           lplpOutEntry
 , BYREF lpOutEntrySize AS DWORD _                      ' __out LPDWORD           lpOutEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBEntryGetFirst IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntryGetFirst" ( _
   BYVAL hMibServer AS DWORD _                          ' __in  MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in  DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in  DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in  LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in  DWORD             dwEntrySize
 , BYREF lplpOutEntry AS ANY _                          ' __out LPVOID*           lplpOutEntry
 , BYREF lpOutEntrySize AS DWORD _                      ' __out LPDWORD           lpOutEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBEntryGetNext IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBEntryGetNext" ( _
   BYVAL hMibServer AS DWORD _                          ' __in  MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in  DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in  DWORD             dwRoutingPid
 , BYVAL lpEntry AS DWORD _                             ' __in  LPVOID            lpEntry
 , BYVAL dwEntrySize AS DWORD _                         ' __in  DWORD             dwEntrySize
 , BYREF lplpOutEntry AS ANY _                          ' __out LPVOID*           lplpOutEntry
 , BYREF lpOutEntrySize AS DWORD _                      ' __out LPDWORD           lpOutEntrySize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBGetTrapInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBGetTrapInfo" ( _
   BYVAL hMibServer AS DWORD _                          ' __in     MIB_SERVER_HANDLE hMibServer
 , BYVAL dwProtocolId AS DWORD _                        ' __in     DWORD             dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in     DWORD             dwRoutingPid
 , BYVAL lpInData AS DWORD _                            ' __in     LPVOID            lpInData
 , BYVAL dwInDataSize AS DWORD _                        ' __in     DWORD             dwInDataSize
 , BYREF lplpOutData AS ANY _                           ' __out    LPVOID*           lplpOutData
 , BYREF lpOutDataSize AS DWORD _                       ' __in_out LPDWORD           lpOutDataSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBSetTrapInfo IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBSetTrapInfo" ( _
   BYVAL dwProtocolId AS DWORD _                        ' __in     DWORD   dwProtocolId
 , BYVAL dwRoutingPid AS DWORD _                        ' __in     DWORD   dwRoutingPid
 , BYVAL hEvent AS DWORD _                              ' __in     HANDLE  hEvent
 , BYVAL lpInData AS DWORD _                            ' __in     LPVOID  lpInData
 , BYVAL dwInDataSize AS DWORD _                        ' __in     DWORD   dwInDataSize
 , BYREF lplpOutData AS ANY _                           ' __out    LPVOID* lplpOutData
 , BYREF lpOutDataSize AS DWORD _                       ' __in_out LPDWORD lpOutDataSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprAdminMIBBufferFree IMPORT "MPRAPI.DLL" ALIAS "MprAdminMIBBufferFree" ( _
   BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 ) AS DWORD                                             ' DWORD

'//
'// Configuration APIs
'//

DECLARE FUNCTION MprConfigServerInstall IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerInstall" ( _
   BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYVAL pBuffer AS DWORD _                             ' __in Pvoid pBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigServerConnect IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerConnect" ( _
   BYREF lpwsServerName AS WSTRINGZ _                   ' __in  LPWSTR  lpwsServerName
 , BYREF phMprConfig AS DWORD _                         ' __out HANDLE* phMprConfig
 ) AS DWORD                                             ' DWORD

DECLARE SUB MprConfigServerDisconnect IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerDisconnect" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 )                                                      ' void

DECLARE FUNCTION MprConfigServerRefresh IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerRefresh" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigBufferFree IMPORT "MPRAPI.DLL" ALIAS "MprConfigBufferFree" ( _
   BYVAL pBuffer AS DWORD _                             ' __in LPVOID pBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigServerGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerGetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE   hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD    dwLevel
 , BYREF lplpbBuffer AS ANY _                           ' __out LPBYTE * lplpbBuffer
 ) AS DWORD                                             ' DWORD

'#if (WINVER >= 0x501)
DECLARE FUNCTION MprConfigServerSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerSetInfo" ( _
   BYVAL hMprServer AS DWORD _                          ' __in MPR_SERVER_HANDLE hMprServer
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD             dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in LPBYTE            lpbBuffer
 ) AS DWORD                                             ' DWORD
'#endif

DECLARE FUNCTION MprConfigServerBackup IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerBackup" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYREF lpwsPath AS WSTRINGZ _                         ' __in LPWSTR lpwsPath
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigServerRestore IMPORT "MPRAPI.DLL" ALIAS "MprConfigServerRestore" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYREF lpwsPath AS WSTRINGZ _                         ' __in LPWSTR lpwsPath
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportCreate IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportCreate" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD   dwTransportId
 , BYREF lpwsTransportName AS WSTRINGZ _                ' __in  LPWSTR  lpwsTransportName           OPTIONAL
 , BYVAL pGlobalInfo AS BYTE PTR _                      ' __in  LPBYTE  pGlobalInfo
 , BYVAL dwGlobalInfoSize AS DWORD _                    ' __in  DWORD   dwGlobalInfoSize
 , BYVAL pClientInterfaceInfo AS BYTE PTR _             ' __in  LPBYTE  pClientInterfaceInfo        OPTIONAL
 , BYVAL dwClientInterfaceInfoSize AS DWORD _           ' __in  DWORD   dwClientInterfaceInfoSize   OPTIONAL
 , BYREF lpwsDLLPath AS WSTRINGZ _                      ' __in  LPWSTR  lpwsDLLPath
 , BYREF phRouterTransport AS DWORD _                   ' __out HANDLE* phRouterTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportDelete IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportDelete" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterTransport AS DWORD _                    ' __in HANDLE hRouterTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportGetHandle IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportGetHandle" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD   dwTransportId
 , BYREF phRouterTransport AS DWORD _                   ' __out HANDLE* phRouterTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportSetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterTransport AS DWORD _                    ' __in HANDLE hRouterTransport
 , OPTIONAL BYVAL pGlobalInfo AS BYTE PTR _             ' __in LPBYTE pGlobalInfo                 OPTIONAL
 , OPTIONAL BYVAL dwGlobalInfoSize AS DWORD _           ' __in DWORD  dwGlobalInfoSize            OPTIONAL
 , OPTIONAL BYVAL pClientInterfaceInfo AS BYTE PTR _    ' __in LPBYTE pClientInterfaceInfo        OPTIONAL
 , OPTIONAL BYVAL dwClientInterfaceInfoSize AS DWORD _  ' __in DWORD  dwClientInterfaceInfoSize   OPTIONAL
 , OPTIONAL BYREF lpwsDLLPath AS WSTRINGZ _             ' __in LPWSTR lpwsDLLPath                 OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportGetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE  hMprConfig
 , BYVAL hRouterTransport AS DWORD _                    ' __in HANDLE  hRouterTransport
 , OPTIONAL BYREF ppGlobalInfo AS ANY _                 ' __in_out LPBYTE* ppGlobalInfo             OPTIONAL
 , OPTIONAL BYREF lpdwGlobalInfoSize AS DWORD _         ' __out LPDWORD lpdwGlobalInfoSize          OPTIONAL
 , OPTIONAL BYREF ppClientInterfaceInfo AS ANY _        ' __in_out LPBYTE* ppClientInterfaceInfo    OPTIONAL
 , OPTIONAL BYREF lpdwClientInterfaceInfoSize AS DWORD _ ' __out LPDWORD lpdwClientInterfaceInfoSize OPTIONAL
 , OPTIONAL BYREF lplpwsDLLPath AS ANY _                ' __in_out LPWSTR* lplpwsDLLPath            OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigTransportEnum IMPORT "MPRAPI.DLL" ALIAS "MprConfigTransportEnum" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE  hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD   dwLevel
 , BYREF lplpBuffer AS ANY _                            ' __in_out LPBYTE* lplpBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in DWORD   dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in_out LPDWORD lpdwResumeHandle            OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceCreate IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceCreate" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD   dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in  LPBYTE  lpbBuffer
 , BYREF phRouterInterface AS DWORD _                   ' __out HANDLE* phRouterInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceDelete IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceDelete" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE hRouterInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceGetHandle IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceGetHandle" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE hMprConfig
 , BYREF lpwsInterfaceName AS WSTRINGZ _                ' __in  LPWSTR  lpwsInterfaceName
 , BYREF phRouterInterface AS DWORD _                   ' __out HANDLE* phRouterInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceGetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in  HANDLE  hRouterInterface
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD   dwLevel
 , BYREF lplpBuffer AS ANY _                            ' __in_out LPBYTE* lplpBuffer
 , BYREF lpdwBufferSize AS DWORD _                      ' __out LPDWORD lpdwBufferSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceSetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE hRouterInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD  dwLevel
 , BYVAL lpbBuffer AS BYTE PTR _                        ' __in LPBYTE lpbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceEnum IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceEnum" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD   dwLevel
 , BYREF lplpBuffer AS ANY _                            ' __in_out LPBYTE* lplpBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in  DWORD   dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in_out LPDWORD lpdwResumeHandle            OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportAdd IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportAdd" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in  HANDLE  hRouterInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD   dwTransportId
 , BYREF lpwsTransportName AS WSTRINGZ _                ' __in  LPWSTR  lpwsTransportName OPTIONAL
 , BYVAL pInterfaceInfo AS BYTE PTR _                   ' __in  LPBYTE  pInterfaceInfo
 , BYVAL dwInterfaceInfoSize AS DWORD _                 ' __in  DWORD   dwInterfaceInfoSize
 , BYREF phRouterIfTransport AS DWORD _                 ' __out HANDLE* phRouterIfTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportRemove IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportRemove" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE hRouterInterface
 , BYVAL hRouterIfTransport AS DWORD _                  ' __in HANDLE hRouterIfTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportGetHandle IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportGetHandle" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in  HANDLE  hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in  HANDLE  hRouterInterface
 , BYVAL dwTransportId AS DWORD _                       ' __in  DWORD   dwTransportId
 , BYREF phRouterIfTransport AS DWORD _                 ' __out HANDLE* phRouterIfTransport
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportGetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE  hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE  hRouterInterface
 , BYVAL hRouterIfTransport AS DWORD _                  ' __in HANDLE  hRouterIfTransport
 , OPTIONAL BYREF ppInterfaceInfo AS ANY _              ' __in_out LPBYTE* ppInterfaceInfo          OPTIONAL
 , OPTIONAL BYREF lpdwInterfaceInfoSize AS DWORD _      ' __out LPDWORD lpdwInterfaceInfoSize       OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportSetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE hRouterInterface
 , BYVAL hRouterIfTransport AS DWORD _                  ' __in HANDLE hRouterIfTransport
 , OPTIONAL BYVAL pInterfaceInfo AS BYTE PTR _          ' __in LPBYTE pInterfaceInfo      OPTIONAL
 , OPTIONAL BYVAL dwInterfaceInfoSize AS DWORD _        ' __in DWORD  dwInterfaceInfoSize OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigInterfaceTransportEnum IMPORT "MPRAPI.DLL" ALIAS "MprConfigInterfaceTransportEnum" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE  hMprConfig
 , BYVAL hRouterInterface AS DWORD _                    ' __in HANDLE  hRouterInterface
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD   dwLevel
 , BYREF lplpBuffer AS ANY _                            ' __in_out LPBYTE* lplpBuffer
 , BYVAL dwPrefMaxLen AS DWORD _                        ' __in DWORD   dwPrefMaxLen
 , BYREF lpdwEntriesRead AS DWORD _                     ' __out LPDWORD lpdwEntriesRead
 , BYREF lpdwTotalEntries AS DWORD _                    ' __out LPDWORD lpdwTotalEntries
 , OPTIONAL BYREF lpdwResumeHandle AS DWORD _           ' __in_out LPDWORD lpdwResumeHandle OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigGetFriendlyName IMPORT "MPRAPI.DLL" ALIAS "MprConfigGetFriendlyName" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYREF pszGuidName AS WSTRINGZ _                      ' __in PWCHAR pszGuidName
 , BYREF pszBuffer AS WSTRINGZ _                        ' __out PWCHAR pszBuffer
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD  dwBufferSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigGetGuidName IMPORT "MPRAPI.DLL" ALIAS "MprConfigGetGuidName" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYREF pszFriendlyName AS WSTRINGZ _                  ' __in PWCHAR pszFriendlyName
 , BYREF pszBuffer AS WSTRINGZ _                        ' __out PWCHAR pszBuffer
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD  dwBufferSize
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0600)
DECLARE FUNCTION MprConfigFilterGetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigFilterGetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD dwTransportId
 , BYVAL lpBuffer AS BYTE PTR _                         ' __out LPBYTE  lpBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprConfigFilterSetInfo IMPORT "MPRAPI.DLL" ALIAS "MprConfigFilterSetInfo" ( _
   BYVAL hMprConfig AS DWORD _                          ' __in HANDLE hMprConfig
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYVAL dwTransportId AS DWORD _                       ' __in DWORD dwTransportId
 , BYVAL lpBuffer AS BYTE PTR _                         ' __in LPBYTE  lpBuffer
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0600 */

'//
'// Information block APIs
'//

DECLARE FUNCTION MprInfoCreate IMPORT "MPRAPI.DLL" ALIAS "MprInfoCreate" ( _
   BYVAL dwVersion AS DWORD _                           ' __in  DWORD   dwVersion
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoDelete IMPORT "MPRAPI.DLL" ALIAS "MprInfoDelete" ( _
   BYVAL lpHeader AS DWORD _                            ' __in LPVOID lpHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoRemoveAll IMPORT "MPRAPI.DLL" ALIAS "MprInfoRemoveAll" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID lpHeader
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoDuplicate IMPORT "MPRAPI.DLL" ALIAS "MprInfoDuplicate" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID lpHeader
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoBlockAdd IMPORT "MPRAPI.DLL" ALIAS "MprInfoBlockAdd" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID  lpHeader
 , BYVAL dwInfoType AS DWORD _                          ' __in  DWORD   dwInfoType
 , BYVAL dwItemSize AS DWORD _                          ' __in  DWORD   dwItemSize
 , BYVAL dwItemCount AS DWORD _                         ' __in  DWORD   dwItemCount
 , BYVAL lpItemData AS BYTE PTR _                       ' __in  LPBYTE  lpItemData
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoBlockRemove IMPORT "MPRAPI.DLL" ALIAS "MprInfoBlockRemove" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID  lpHeader
 , BYVAL dwInfoType AS DWORD _                          ' __in  DWORD   dwInfoType
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoBlockSet IMPORT "MPRAPI.DLL" ALIAS "MprInfoBlockSet" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID  lpHeader
 , BYVAL dwInfoType AS DWORD _                          ' __in  DWORD   dwInfoType
 , BYVAL dwItemSize AS DWORD _                          ' __in  DWORD   dwItemSize
 , BYVAL dwItemCount AS DWORD _                         ' __in  DWORD   dwItemCount
 , BYVAL lpItemData AS BYTE PTR _                       ' __in  LPBYTE  lpItemData
 , BYREF lplpNewHeader AS ANY _                         ' __out LPVOID* lplpNewHeader
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoBlockFind IMPORT "MPRAPI.DLL" ALIAS "MprInfoBlockFind" ( _
   BYVAL lpHeader AS DWORD _                            ' __in  LPVOID  lpHeader
 , BYVAL dwInfoType AS DWORD _                          ' __in  DWORD   dwInfoType
 , OPTIONAL BYREF lpdwItemSize AS DWORD _               ' __out LPDWORD lpdwItemSize  // OPTIONAL
 , OPTIONAL BYREF lpdwItemCount AS DWORD _              ' __out LPDWORD lpdwItemCount // OPTIONAL
 , OPTIONAL BYREF lplpItemData AS ANY _                 ' __out LPBYTE* lplpItemData  // OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MprInfoBlockQuerySize IMPORT "MPRAPI.DLL" ALIAS "MprInfoBlockQuerySize" ( _
   BYVAL lpHeader AS DWORD _                            ' __in LPVOID lpHeader
 ) AS DWORD                                             ' DWORD

'//
'// BOOL APIENTRY
'// MprInfoBlockExists(
'//     __in      LPVOID                  lpHeader,
'//     __in      DWORD                   dwInfoType
'// );
'//

'#define MprInfoBlockExists(h,t) \
'    (MprInfoBlockFind((h),(t),NULL,NULL,NULL) == NO_ERROR)

FUNCTION MprInfoBlockExists (BYVAL lpHeader AS DWORD, BYVAL dwInfoType AS DWORD) AS DWORD
   FUNCTION = (MprInfoBlockFind(lpHeader, dwInfoType, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL) = %NOERROR)
END FUNCTION
