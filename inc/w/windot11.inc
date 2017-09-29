' ########################################################################################
' Microsoft Windows
' File: windot11.inc
' Contents: Definitions for native 802.11 miniport driver specifications
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINDOT11_INC = 1

#IF NOT %DEF(%NTDDNDIS_INC)
#INCLUDE ONCE "ntddndis.inc"
#ENDIF

#INCLUDE ONCE "WlanTypes.inc"

'// These are needed for wlanapi.h for pre-longhorn targets
'#ifdef __midl
'    typedef struct _DOT11_MAC_ADDRESS {
'        UCHAR ucDot11MacAddress[6];
'    } DOT11_MAC_ADDRESS, * PDOT11_MAC_ADDRESS;
'#else
'    typedef UCHAR DOT11_MAC_ADDRESS[6];
'    typedef DOT11_MAC_ADDRESS * PDOT11_MAC_ADDRESS;
'#endif

' // Size = 6 bytes
TYPE DOT11_MAC_ADDRESS
   ucDot11MacAddress(5) AS BYTE   ' UCHAR[6]
END TYPE

'// A list of DOT11_MAC_ADDRESS
%DOT11_BSSID_LIST_REVISION_1 = 1
' // Size = 20 bytes
TYPE DOT11_BSSID_LIST DWORD
   Header AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   BSSIDs(0)          AS DOT11_MAC_ADDRESS
END TYPE

' enum _DOT11_PHY_TYPE
%dot11_phy_type_unknown    = 0???
%dot11_phy_type_any        = %dot11_phy_type_unknown
%dot11_phy_type_fhss       = 1???
%dot11_phy_type_dsss       = 2???
%dot11_phy_type_irbaseband = 3???
%dot11_phy_type_ofdm       = 4???
%dot11_phy_type_hrdsss     = 5???
%dot11_phy_type_erp        = 6???
%dot11_phy_type_ht         = 7???
%dot11_phy_type_IHV_start  = &H80000000???
%dot11_phy_type_IHV_end    = &Hffffffff???

%DOT11_RATE_SET_MAX_LENGTH = 126  ' // 126 bytes

' // Size = 132 bytes
TYPE DOT11_RATE_SET DWORD
   uRateSetLength AS DWORD   ' ULONG
   ucRateSet(%DOT11_RATE_SET_MAX_LENGTH - 1) AS BYTE   ' __field_ecount_part(DOT11_RATE_SET_MAX_LENGTH, uRateSetLength) UCHAR ucRateSet[DOT11_RATE_SET_MAX_LENGTH];
END TYPE

'typedef UCHAR DOT11_COUNTRY_OR_REGION_STRING[3];
'typedef DOT11_COUNTRY_OR_REGION_STRING * PDOT11_COUNTRY_OR_REGION_STRING;

' // Size = 3 bytes
TYPE DOT11_COUNTRY_OR_REGION_STRING BYTE
   Domain AS STRING * 3
END TYPE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600

'// ntddndis.h: new Flags for OID_GEN_CURRENT_PACKET_FILTER
%NDIS_PACKET_TYPE_MEDIA_SPECIFIC_MASK        = &H0fff0000???
'    // Mask for media specific packet filters
%NDIS_PACKET_TYPE_802_11_DIRECTED_DATA       = %NDIS_PACKET_TYPE_DIRECTED
%NDIS_PACKET_TYPE_802_11_BROADCAST_DATA      = %NDIS_PACKET_TYPE_BROADCAST
%NDIS_PACKET_TYPE_802_11_MULTICAST_DATA      = %NDIS_PACKET_TYPE_MULTICAST
%NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_DATA  = %NDIS_PACKET_TYPE_ALL_MULTICAST
%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_DATA    = %NDIS_PACKET_TYPE_PROMISCUOUS
%NDIS_PACKET_TYPE_802_11_RAW_DATA            = &H00010000???
'    // Raw 802.11 data packets (MPDU)
%NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT       = &H00020000???
'    // Directed management packet
%NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT      = &H00040000???
'    // Broadcast management packet
%NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT      = &H00080000???
'    // Multicast management packet
%NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT  = &H00100000???
'    // All-multicast management packet
%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT    = &H00200000???
'    // Promiscuous management packet
%NDIS_PACKET_TYPE_802_11_RAW_MGMT            = &H00400000???
'    // Raw management packet
%NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL       = &H00800000???
'    // Directed CTRL packet
%NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL      = &H01000000???
'    // Broadcast CTRL packet
%NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL    = &H02000000???
'    // Promiscuous CTRL packet
%NDIS_PACKET_TYPE_ALL_802_11_FILTERS = _
     %NDIS_PACKET_TYPE_DIRECTED OR _
     %NDIS_PACKET_TYPE_MULTICAST OR _
     %NDIS_PACKET_TYPE_ALL_MULTICAST OR _
     %NDIS_PACKET_TYPE_BROADCAST OR _
     %NDIS_PACKET_TYPE_PROMISCUOUS OR _
     %NDIS_PACKET_TYPE_802_11_RAW_DATA OR _
     %NDIS_PACKET_TYPE_802_11_DIRECTED_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_BROADCAST_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_MULTICAST_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_ALL_MULTICAST_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_PROMISCUOUS_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_RAW_MGMT OR _
     %NDIS_PACKET_TYPE_802_11_DIRECTED_CTRL OR _
     %NDIS_PACKET_TYPE_802_11_BROADCAST_CTRL OR _
     %NDIS_PACKET_TYPE_802_11_PROMISCUOUS_CTRL

'//
'// Max size of an 802.11 PDU, including the MAC header, frame body and FCS.
'//
%DOT11_MAX_PDU_SIZE                         = 2346

'//
'// Min size of an 802.11 PDU, including the MAC header, frame body and FCS.
'//
%DOT11_MIN_PDU_SIZE                         = (256)

%DOT11_MAX_NUM_DEFAULT_KEY                  = 4

'// Macros for defining native 802.11 OIDs
%OID_DOT11_NDIS_START                       = &H0D010300???

%NWF_MANDATORY_OID       = &H01???
%NWF_OPTIONAL_OID        = &H02???

%NWF_OPERATIONAL_OID     = &H01???
%NWF_STATISTICS_OID      = &H02???

'#define NWF_DEFINE_OID(Seq,o,m)     ((0x0E000000U) | ((o) << 16) | ((m) << 8) | (Seq))
FUNCTION NWF_DEFINE_OID (BYVAL Seq AS DWORD, BYVAL o AS DWORD, BYVAL m AS DWORD) AS DWORD
   SHIFT LEFT o, 16
   SHIFT LEFT m, 8
   FUNCTION = &H0E000000??? OR o OR m OR Seq
END FUNCTION

'//
'// Offload Capability OIDs
'//

%OID_DOT11_OFFLOAD_CAPABILITY            = (%OID_DOT11_NDIS_START + 0)
'// Capability flags
%DOT11_HW_WEP_SUPPORTED_TX               = &H00000001
%DOT11_HW_WEP_SUPPORTED_RX               = &H00000002
%DOT11_HW_FRAGMENTATION_SUPPORTED        = &H00000004
%DOT11_HW_DEFRAGMENTATION_SUPPORTED      = &H00000008
%DOT11_HW_MSDU_AUTH_SUPPORTED_TX         = &H00000010
%DOT11_HW_MSDU_AUTH_SUPPORTED_RX         = &H00000020
'// WEP Algorithm flags
%DOT11_CONF_ALGO_WEP_RC4                 = &H00000001  ' // WEP RC4
%DOT11_CONF_ALGO_TKIP                    = &H00000002
'// Integrity Algorithm flags
%DOT11_AUTH_ALGO_MICHAEL                 = &H00000001  ' // Michael

' // Size = 28 bytes
TYPE DOT11_OFFLOAD_CAPABILITY DWORD
   uReserved                AS DWORD   ' ULONG
   uFlags                   AS DWORD   ' ULONG
   uSupportedWEPAlgorithms  AS DWORD   ' ULONG
   uNumOfReplayWindows      AS DWORD   ' ULONG
   uMaxWEPKeyMappingLength  AS DWORD   ' ULONG
   uSupportedAuthAlgorithms AS DWORD   ' ULONG
   uMaxAuthKeyMappingLength AS DWORD   ' ULONG
END TYPE

%OID_DOT11_CURRENT_OFFLOAD_CAPABILITY = (%OID_DOT11_NDIS_START + 1)

' // Size = 8 bytes
TYPE DOT11_CURRENT_OFFLOAD_CAPABILITY DWORD
   uReserved AS DWORD   ' ULONG
   uFlags    AS DWORD   ' ULONG
END TYPE

'//
'// WEP Offload
'//

%OID_DOT11_WEP_OFFLOAD = (%OID_DOT11_NDIS_START + 2)

' enum _DOT11_OFFLOAD_TYPE
%dot11_offload_type_wep  = 1
%dot11_offload_type_auth = 2

' // Size = 8 bytes
TYPE DOT11_IV48_COUNTER DWORD
   uIV32Counter  AS DWORD   ' ULONG
   usIV16Counter AS WORD    ' USHORT
END TYPE

' // Size = 208 bytes
TYPE DOT11_WEP_OFFLOAD DWORD FILL
   uReserved             AS DWORD   ' ULONG
   hOffloadContext       AS DWORD   ' HANDLE
   hOffload              AS DWORD   ' HANDLE
   dot11OffloadType      AS LONG    ' DOT11_OFFLOAD_TYPE enum
   dwAlgorithm           AS DWORD   ' ULONG
   bRowIsOutbound        AS BYTE    ' BOOLEAN
   bUseDefault           AS BYTE    ' BOOLEAN
   uFlags                AS DWORD   ' ULONG
   ucMacAddress(5)       AS BYTE    ' UCHAR[6]
   uNumOfRWsOnPeer       AS DWORD   ' ULONG
   uNumOfRWsOnMe         AS DWORD   ' ULONG
   dot11IV48Counters(15) AS DOT11_IV48_COUNTER
   usDot11RWBitMaps(15)  AS WORD    ' USHORT[16]
   usKeyLength           AS WORD    ' USHORT
   ucKey(1)              AS BYTE    ' UCHAR // Must be the last field.
   ' Note: We are using ucKey(1) instead of ucKey(0) to keep DWORD alignment
END TYPE

%OID_DOT11_WEP_UPLOAD = (%OID_DOT11_NDIS_START + 3)

' // Size = 176 bytes
TYPE DOT11_WEP_UPLOAD DWORD
   uReserved             AS DWORD   ' ULONG
   dot11OffloadType      AS LONG    ' DOT11_OFFLOAD_TYPE enum
   hOffload              AS DWORD   ' HANDLE
   uNumOfRWsUsed         AS DWORD   ' ULONG
   dot11IV48Counters(15) AS DOT11_IV48_COUNTER
   usDot11RWBitMaps(15)  AS WORD    ' USHORT[16]
END TYPE

%OID_DOT11_DEFAULT_WEP_OFFLOAD = (%OID_DOT11_NDIS_START + 4)

' enum DOT11_KEY_DIRECTION
%dot11_key_direction_both     = 1
%dot11_key_direction_inbound  = 2
%dot11_key_direction_outbound = 3

' // Size = 208 bytes
TYPE DOT11_DEFAULT_WEP_OFFLOAD DWORD FILL
   uReserved             AS DWORD   ' ULONG
   hOffloadContext       AS DWORD   ' HANDLE
   hOffload              AS DWORD   ' HANDLE
   dwIndex               AS DWORD   ' ULONG
   dot11OffloadType      AS LONG    ' DOT11_OFFLOAD_TYPE
   dwAlgorithm           AS DWORD   ' ULONG
   uFlags                AS DWORD   ' ULONG
   dot11KeyDirection     AS LONG    ' DOT11_KEY_DIRECTION enum
   ucMacAddress(5)       AS BYTE    ' UCHAR[6]
   uNumOfRWsOnMe         AS DWORD   ' ULONG
   dot11IV48Counters(15) AS DOT11_IV48_COUNTER
   usDot11RWBitMaps(15)  AS WORD    ' USHORT[16]
   usKeyLength           AS WORD    ' USHORT
   ucKey(1)              AS BYTE    ' UCHAR // Must be the last field.
   ' Note: We are using ucKey(1) instead of ucKey(0) to keep DWORD alignment
END TYPE

%OID_DOT11_DEFAULT_WEP_UPLOAD = (%OID_DOT11_NDIS_START + 5)

' // Size = 176 bytes
TYPE DOT11_DEFAULT_WEP_UPLOAD DWORD
   uReserved             AS DWORD   ' ULONG
   dot11OffloadType      AS LONG    ' DOT11_OFFLOAD_TYPE
   hOffload              AS DWORD   ' HANDLE
   uNumOfRWsUsed         AS DWORD   ' ULONG
   dot11IV48Counters(15) AS DOT11_IV48_COUNTER
   usDot11RWBitMaps(15)  AS WORD    ' USHORT[16]
END TYPE

'//
'// Fragmentation/Defragmentation Offload
'//

%OID_DOT11_MPDU_MAX_LENGTH = (%OID_DOT11_NDIS_START + 6)
' // ULONG (in bytes)

'//
'// 802.11 Configuration OIDs
'//

'//
'// OIDs for Mandatory Functions
'//

%OID_DOT11_OPERATION_MODE_CAPABILITY = (%OID_DOT11_NDIS_START + 7)

%DOT11_OPERATION_MODE_UNKNOWN            = &H00000000???
%DOT11_OPERATION_MODE_STATION            = &H00000001???
%DOT11_OPERATION_MODE_AP                 = &H00000002???
%DOT11_OPERATION_MODE_EXTENSIBLE_STATION = &H00000004???
%DOT11_OPERATION_MODE_NETWORK_MONITOR    = &H80000000???

' // Size = 24 bytes
TYPE DOT11_OPERATION_MODE_CAPABILITY DWORD
   uReserved         AS DWORD   ' ULONG
   uMajorVersion     AS DWORD   ' ULONG
   uMinorVersion     AS DWORD   ' ULONG
   uNumOfTXBuffers   AS DWORD   ' ULONG
   uNumOfRXBuffers   AS DWORD   ' ULONG
   uOpModeCapability AS DWORD   ' ULONG
END TYPE

%OID_DOT11_CURRENT_OPERATION_MODE = (%OID_DOT11_NDIS_START + 8)

' // Size = 8 bytes
TYPE DOT11_CURRENT_OPERATION_MODE DWORD
   uReserved      AS DWORD   ' ULONG
   uCurrentOpMode AS DWORD   ' ULONG
END TYPE

%OID_DOT11_CURRENT_PACKET_FILTER = (%OID_DOT11_NDIS_START + 9)

%DOT11_PACKET_TYPE_DIRECTED_CTRL         = &H00000001???
'// Indicate all 802.11 unicast control packets.
%DOT11_PACKET_TYPE_DIRECTED_MGMT         = &H00000002???
'// Indicate all 802.11 unicast management packets.
%DOT11_PACKET_TYPE_DIRECTED_DATA         = &H00000004???
'// Indicate all 802.11 unicast data packets.
%DOT11_PACKET_TYPE_MULTICAST_CTRL        = &H00000008???
'// Indicate all 802.11 multicast control packets.
%DOT11_PACKET_TYPE_MULTICAST_MGMT        = &H00000010???
'// Indicate all 802.11 multicast management packets.
%DOT11_PACKET_TYPE_MULTICAST_DATA        = &H00000020???
'// Indicate all 802.11 multicast data packets.
%DOT11_PACKET_TYPE_BROADCAST_CTRL        = &H00000040???
'// Indicate all 802.11 broadcast control packets.
%DOT11_PACKET_TYPE_BROADCAST_MGMT        = &H00000080???
'// Indicate all 802.11 broadcast management packets.
%DOT11_PACKET_TYPE_BROADCAST_DATA        = &H00000100???
'// Indicate all 802.11 broadcast data packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_CTRL      = &H00000200???
'// Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_MGMT      = &H00000400???
'// Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_PROMISCUOUS_DATA      = &H00000800???
'// Move into promiscuous mode and indicate all 802.11 control packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_CTRL    = &H00001000???
'// Indicate all 802.11 multicast control packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_MGMT    = &H00002000???
'// Indicate all 802.11 multicast management packets.
%DOT11_PACKET_TYPE_ALL_MULTICAST_DATA    = &H00004000???
'// Indicate all 802.11 multicast data packets.

%DOT11_PACKET_TYPE_RESERVED = (NOT( _
    %DOT11_PACKET_TYPE_DIRECTED_CTRL OR _
    %DOT11_PACKET_TYPE_DIRECTED_MGMT OR _
    %DOT11_PACKET_TYPE_DIRECTED_DATA OR _
    %DOT11_PACKET_TYPE_MULTICAST_CTRL OR _
    %DOT11_PACKET_TYPE_MULTICAST_MGMT OR _
    %DOT11_PACKET_TYPE_MULTICAST_DATA OR _
    %DOT11_PACKET_TYPE_BROADCAST_CTRL OR _
    %DOT11_PACKET_TYPE_BROADCAST_MGMT OR _
    %DOT11_PACKET_TYPE_BROADCAST_DATA OR _
    %DOT11_PACKET_TYPE_PROMISCUOUS_CTRL OR _
    %DOT11_PACKET_TYPE_PROMISCUOUS_MGMT OR _
    %DOT11_PACKET_TYPE_PROMISCUOUS_DATA OR _
    %DOT11_PACKET_TYPE_ALL_MULTICAST_CTRL OR _
    %DOT11_PACKET_TYPE_ALL_MULTICAST_MGMT OR _
    %DOT11_PACKET_TYPE_ALL_MULTICAST_DATA OR _
    0 _
    ))
'    // All the reserved bits

%OID_DOT11_ATIM_WINDOW = (%OID_DOT11_NDIS_START + 10)
' // ULONG (in TUs)

%OID_DOT11_SCAN_REQUEST = (%OID_DOT11_NDIS_START + 11)

' enum _DOT11_SCAN_TYPE
%dot11_scan_type_active  = 1???
%dot11_scan_type_passive = 2???
%dot11_scan_type_auto    = 3???
%dot11_scan_type_forced  = &H80000000???

' // Size = 84 bytes
TYPE DOT11_SCAN_REQUEST DWORD FILL
   dot11BSSType      AS LONG    ' DOT11_BSS_TYPE enum
   dot11BSSID        AS DOT11_MAC_ADDRESS
   dot11SSID         AS DOT11_SSID
   dot11ScanType     AS LONG    ' DOT11_SCAN_TYPE
   bRestrictedScan   AS BYTE    ' BOOLEAN
   bUseRequestIE     AS BYTE    ' BOOLEAN
   uRequestIDsOffset AS DWORD   ' ULONG
   uNumOfRequestIDs  AS DWORD   ' ULONG
   uPhyTypesOffset   AS DWORD   ' ULONG
   uNumOfPhyTypes    AS DWORD   ' ULONG
   uIEsOffset        AS DWORD   ' ULONG
   uIEsLength        AS DWORD   ' ULONG
   ucBuffer(3)       AS BYTE    ' UCHAR
   ' Note: We are using ucBuffer(3) instead of ucBuffer(0) to keep DWORD alignment
END TYPE

'// V2 SCAN REQUEST
' enum _CH_DESCRIPTION_TYPE
%ch_description_type_logical          = 1
%ch_description_type_center_frequency = 2
%ch_description_type_phy_specific     = 3

' // Size = 32 bytes
TYPE DOT11_PHY_TYPE_INFO DWORD
   dot11PhyType           AS DWORD   ' DOT11_PHY_TYPE enum
   bUseParameters         AS BYTE    ' BOOLEAN
   uProbeDelay            AS DWORD   ' ULONG
   uMinChannelTime        AS DWORD   ' ULONG
   uMaxChannelTime        AS DWORD   ' ULONG
   ChDescriptionType      AS LONG    ' CH_DESCRIPTION_TYPE
   uChannelListSize       AS DWORD   ' ULONG
   ucChannelListBuffer(0) AS BYTE    ' UCHAR
END TYPE

' // Size = 60 bytes
TYPE DOT11_SCAN_REQUEST_V2 DWORD
   dot11BSSType        AS LONG    ' DOT11_BSS_TYPE
   dot11BSSID          AS DOT11_MAC_ADDRESS
   dot11ScanType       AS LONG    ' DOT11_SCAN_TYPE
   bRestrictedScan     AS BYTE    ' BOOLEAN
   udot11SSIDsOffset   AS DWORD   ' ULONG
   uNumOfdot11SSIDs    AS DWORD   ' ULONG
   bUseRequestIE       AS BYTE    ' BOOLEAN
   uRequestIDsOffset   AS DWORD   ' ULONG
   uNumOfRequestIDs    AS DWORD   ' ULONG
   uPhyTypeInfosOffset AS DWORD   ' ULONG
   uNumOfPhyTypeInfos  AS DWORD   ' ULONG
   uIEsOffset          AS DWORD   ' ULONG
   uIEsLength          AS DWORD   ' ULONG
   ucBuffer(0)         AS BYTE    ' UCHAR
END TYPE

%OID_DOT11_CURRENT_PHY_TYPE = (%OID_DOT11_NDIS_START + 12)

%DOT11_PHY_TYPE_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_PHY_TYPE_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   dot11PhyType(0)    AS DWORD   ' DOT11_PHY_TYPE enum
END TYPE

%OID_DOT11_JOIN_REQUEST = (%OID_DOT11_NDIS_START + 13)

'// Capability Information Flags - Exactly maps to the bit positions
'// in the Capability Information field of the beacon and probe response frames.
%DOT11_CAPABILITY_INFO_ESS               = &H0001???
%DOT11_CAPABILITY_INFO_IBSS              = &H0002???
%DOT11_CAPABILITY_INFO_CF_POLLABLE       = &H0004???
%DOT11_CAPABILITY_INFO_CF_POLL_REQ       = &H0008???
%DOT11_CAPABILITY_INFO_PRIVACY           = &H0010???
%DOT11_CAPABILITY_SHORT_PREAMBLE         = &H0020???
%DOT11_CAPABILITY_PBCC                   = &H0040???
%DOT11_CAPABILITY_CHANNEL_AGILITY        = &H0080???
%DOT11_CAPABILITY_SHORT_SLOT_TIME        = &H0400???
%DOT11_CAPABILITY_DSSSOFDM               = &H2000???

' // Size = 48 bytes
TYPE DOT11_BSS_DESCRIPTION   ' Must be 8 byte aligned
   uReserved               AS DWORD   ' ULONG // Passed-in as 0 and must be ignored for now.
   dot11BSSID              AS DOT11_MAC_ADDRESS
   alignment1__            AS WORD
   dot11BSSType            AS LONG    ' DOT11_BSS_TYPE enum
   usBeaconPeriod          AS WORD    ' USHORT
   alignment2__(5)         AS BYTE
   ullTimestamp            AS QUAD    ' ULONGLONG
   usCapabilityInformation AS WORD    ' USHORT
   alignment3__            AS WORD
   uBufferLength           AS DWORD   ' ULONG
   ucBuffer(7)             AS BYTE    ' UCHAR // Must be the last field.
   ' Note: We are using ucBuffer(7) instead of ucBuffer(0) to keep 8 byte alignment
END TYPE

' // Size = 192 bytes
TYPE DOT11_JOIN_REQUEST   ' Must be 8 byte aligned
   uJoinFailureTimeout AS DWORD                   ' ULONG
   OperationalRateSet  AS DOT11_RATE_SET
   uChCenterFrequency  AS DWORD                   ' ULONG
   alignment1__        AS DWORD
   dot11BSSDescription AS DOT11_BSS_DESCRIPTION   ' // Must be the last field.
END TYPE

%OID_DOT11_START_REQUEST = (%OID_DOT11_NDIS_START + 14)

' // Size = 192 bytes
TYPE DOT11_START_REQUEST   ' Must be 8 byte aligned
   uStartFailureTimeout AS DWORD                   ' ULONG
   OperationalRateSet   AS DOT11_RATE_SET
   uChCenterFrequency   AS DWORD                   ' ULONG
   alignment1__         AS DWORD
   dot11BSSDescription  AS DOT11_BSS_DESCRIPTION   ' // Must be the last field.
END TYPE

%OID_DOT11_UPDATE_IE = (%OID_DOT11_NDIS_START + 15)

' enum _DOT11_UPDATE_IE_OP
%dot11_update_ie_op_create_replace = 1
%dot11_update_ie_op_delete         = 2

' // Size = 12 bytes
TYPE DOT11_UPDATE_IE DWORD
   dot11UpdateIEOp AS LONG    ' DOT11_UPDATE_IE_OP enum
   uBufferLength   AS DWORD   ' ULONG
   ucBuffer(0)     AS BYTE    ' UCHAR // Must be the last field.
END TYPE

%OID_DOT11_RESET_REQUEST = (%OID_DOT11_NDIS_START + 16)

' enum _DOT11_RESET_TYPE
%dot11_reset_type_phy         = 1
%dot11_reset_type_mac         = 2
%dot11_reset_type_phy_and_mac = 3

' // Size = 12 bytes
TYPE DOT11_RESET_REQUEST BYTE
   dot11ResetType  AS LONG   ' DOT11_RESET_TYPE enum
   dot11MacAddress AS DOT11_MAC_ADDRESS
   bSetDefaultMIB  AS BYTE   ' BOOLEAN
   alignment__     AS BYTE
END TYPE

%OID_DOT11_NIC_POWER_STATE = (%OID_DOT11_NDIS_START + 17)
' // BOOL

'//
'// OIDs for Optional Functions
'//

%OID_DOT11_OPTIONAL_CAPABILITY = (%OID_DOT11_NDIS_START + 18)

' // Size = 8 bytes
TYPE DOT11_OPTIONAL_CAPABILITY BYTE
   uReserved                    AS DWORD   ' ULONG
   bDot11PCF                    AS BYTE    ' BOOLEAN
   bDot11PCFMPDUTransferToPC    AS BYTE    ' BOOLEAN
   bStrictlyOrderedServiceClass AS BYTE    ' BOOLEAN
   alignment__     AS BYTE
END TYPE

%OID_DOT11_CURRENT_OPTIONAL_CAPABILITY = (%OID_DOT11_NDIS_START + 19)

' // Size = 8 bytes
TYPE DOT11_CURRENT_OPTIONAL_CAPABILITY BYTE
   uReserved                    AS DWORD   ' ULONG
   bDot11CFPollable             AS BYTE    ' BOOLEAN
   bDot11PCF                    AS BYTE    ' BOOLEAN
   bDot11PCFMPDUTransferToPC    AS BYTE    ' BOOLEAN
   bStrictlyOrderedServiceClass AS BYTE    ' BOOLEAN
END TYPE

'//
'// 802.11 MIB OIDs
'//

'//
'// OIDs for dot11StationConfigEntry
'//

%OID_DOT11_STATION_ID = (%OID_DOT11_NDIS_START + 20)
'    // DOT11_MAC_ADDRESS

%OID_DOT11_MEDIUM_OCCUPANCY_LIMIT = (%OID_DOT11_NDIS_START + 21)
'    // ULONG (in TUs)

%OID_DOT11_CF_POLLABLE = (%OID_DOT11_NDIS_START + 22)
'    // BOOL

%OID_DOT11_CFP_PERIOD = (%OID_DOT11_NDIS_START + 23)
'    // ULONG (in DTIM intervals)

%OID_DOT11_CFP_MAX_DURATION = (%OID_DOT11_NDIS_START + 24)
'    // ULONG (in TUs)

%OID_DOT11_POWER_MGMT_MODE = (%OID_DOT11_NDIS_START + 25)

' enum _DOT11_POWER_MODE
%dot11_power_mode_unknown   = 0
%dot11_power_mode_active    = 1
%dot11_power_mode_powersave = 2

%DOT11_POWER_SAVE_LEVEL_MAX_PSP  = 1
'// Maximum power save polling.
%DOT11_POWER_SAVE_LEVEL_FAST_PSP = 2
'// Fast power save polling.

' // Size = 16 bytes
TYPE DOT11_POWER_MGMT_MODE BYTE
   dot11PowerMode   AS LONG    ' DOT11_POWER_MODE enum
   uPowerSaveLevel  AS DWORD   ' ULONG
   usListenInterval AS WORD    ' USHORT
   usAID            AS WORD    ' USHORT
   bReceiveDTIMs    AS BYTE    ' BOOLEAN
   alignment__(2)   AS BYTE
END TYPE

%OID_DOT11_OPERATIONAL_RATE_SET = (%OID_DOT11_NDIS_START + 26)
'    // DOT11_RATE_SET

%OID_DOT11_BEACON_PERIOD = (%OID_DOT11_NDIS_START + 27)
'    // ULONG (in TUs)

%OID_DOT11_DTIM_PERIOD = (%OID_DOT11_NDIS_START + 28)
'    // ULONG (in beacon intervals)

'//
'// OIDs for Dot11PrivacyEntry
'//

%OID_DOT11_WEP_ICV_ERROR_COUNT = (%OID_DOT11_NDIS_START + 29)
'    // ULONG

'//
'// OIDs for dot11OperationEntry
'//

%OID_DOT11_MAC_ADDRESS = (%OID_DOT11_NDIS_START + 30)
'    // DOT11_MAC_ADDRESS

%OID_DOT11_RTS_THRESHOLD = (%OID_DOT11_NDIS_START + 31)
'    // ULONG (in number of octets)

%OID_DOT11_SHORT_RETRY_LIMIT = (%OID_DOT11_NDIS_START + 32)
'    // ULONG

%OID_DOT11_LONG_RETRY_LIMIT = (%OID_DOT11_NDIS_START + 33)
'    // ULONG

%OID_DOT11_FRAGMENTATION_THRESHOLD = (%OID_DOT11_NDIS_START + 34)
'    // ULONG (in number of octets)

%OID_DOT11_MAX_TRANSMIT_MSDU_LIFETIME = (%OID_DOT11_NDIS_START + 35)
'    // ULONG (in TUs)

%OID_DOT11_MAX_RECEIVE_LIFETIME = (%OID_DOT11_NDIS_START + 36)
'    // ULONG (in TUs)

'//
'// OIDs for dot11CountersEntry
'//

%OID_DOT11_COUNTERS_ENTRY = (%OID_DOT11_NDIS_START + 37)

' // Size = 52 bytes
TYPE DOT11_COUNTERS_ENTRY DWORD
   uTransmittedFragmentCount       AS DWORD   ' ULONG
   uMulticastTransmittedFrameCount AS DWORD   ' ULONG
   uFailedCount                    AS DWORD   ' ULONG
   uRetryCount                     AS DWORD   ' ULONG
   uMultipleRetryCount             AS DWORD   ' ULONG
   uFrameDuplicateCount            AS DWORD   ' ULONG
   uRTSSuccessCount                AS DWORD   ' ULONG
   uRTSFailureCount                AS DWORD   ' ULONG
   uACKFailureCount                AS DWORD   ' ULONG
   uReceivedFragmentCount          AS DWORD   ' ULONG
   uMulticastReceivedFrameCount    AS DWORD   ' ULONG
   uFCSErrorCount                  AS DWORD   ' ULONG
   uTransmittedFrameCount          AS DWORD   ' ULONG
END TYPE

'//
'// OIDs for dot11PhyOperationEntry
'//

%OID_DOT11_SUPPORTED_PHY_TYPES = (%OID_DOT11_NDIS_START + 38)

' // Size = 12 bytes
TYPE DOT11_SUPPORTED_PHY_TYPES DWORD
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   dot11PHYType(0)    AS DWORD   ' DOT11_PHY_TYPE enum
END TYPE

%OID_DOT11_CURRENT_REG_DOMAIN = (%OID_DOT11_NDIS_START + 39)

%DOT11_REG_DOMAIN_OTHER                  = &H00000000???
%DOT11_REG_DOMAIN_FCC                    = &H00000010???
%DOT11_REG_DOMAIN_DOC                    = &H00000020???
%DOT11_REG_DOMAIN_ETSI                   = &H00000030???
%DOT11_REG_DOMAIN_SPAIN                  = &H00000031???
%DOT11_REG_DOMAIN_FRANCE                 = &H00000032???
%DOT11_REG_DOMAIN_MKK                    = &H00000040???
'// ULONG

%OID_DOT11_TEMP_TYPE = (%OID_DOT11_NDIS_START + 40)

' enum _DOT11_TEMP_TYPE {
%dot11_temp_type_unknown = 0
%dot11_temp_type_1       = 1
%dot11_temp_type_2       = 2

'//
'// OIDs for dot11PhyAntennaEntry
'//

%OID_DOT11_CURRENT_TX_ANTENNA = (%OID_DOT11_NDIS_START + 41)
'    // ULONG

%OID_DOT11_DIVERSITY_SUPPORT = (%OID_DOT11_NDIS_START + 42)

' enum _DOT11_DIVERSITY_SUPPORT
%dot11_diversity_support_unknown      = 0
%dot11_diversity_support_fixedlist    = 1
%dot11_diversity_support_notsupported = 2
%dot11_diversity_support_dynamic      = 3

%OID_DOT11_CURRENT_RX_ANTENNA = (%OID_DOT11_NDIS_START + 43)
'    // ULONG

'//
'// OIDs for dot11PhyTxPowerEntry
'//

%OID_DOT11_SUPPORTED_POWER_LEVELS = (%OID_DOT11_NDIS_START + 44)

' // Size = 36 bytes
TYPE DOT11_SUPPORTED_POWER_LEVELS DWORD
   uNumOfSupportedPowerLevels AS DWORD   ' ULONG
   uTxPowerLevelValues(7)     AS DWORD   ' __field_ecount_part(8, uNumOfSupportedPowerLevels) ULONG uTxPowerLevelValues[8];
END TYPE

%OID_DOT11_CURRENT_TX_POWER_LEVEL = (%OID_DOT11_NDIS_START + 45)
'    // ULONG

'//
'// OIDs for dot11PhyFHSSEntry
'//

%OID_DOT11_HOP_TIME = (%OID_DOT11_NDIS_START + 46)
'    // ULONG (in microseconds)

%OID_DOT11_CURRENT_CHANNEL_NUMBER = (%OID_DOT11_NDIS_START + 47)
'    // ULONG

%OID_DOT11_MAX_DWELL_TIME = (%OID_DOT11_NDIS_START + 48)
'    // ULONG (in TUs)

%OID_DOT11_CURRENT_DWELL_TIME = (%OID_DOT11_NDIS_START + 49)
'    // ULONG (in TUs)

%OID_DOT11_CURRENT_SET = (%OID_DOT11_NDIS_START + 50)
'    // ULONG

%OID_DOT11_CURRENT_PATTERN = (%OID_DOT11_NDIS_START + 51)
'    // ULONG

%OID_DOT11_CURRENT_INDEX = (%OID_DOT11_NDIS_START + 52)
'    // ULONG

'//
'// OIDs for dot11PhyDSSSEntry
'//

%OID_DOT11_CURRENT_CHANNEL = (%OID_DOT11_NDIS_START + 53)
'    // ULONG

%OID_DOT11_CCA_MODE_SUPPORTED = (%OID_DOT11_NDIS_START + 54)

%DOT11_CCA_MODE_ED_ONLY                  = &H00000001???
%DOT11_CCA_MODE_CS_ONLY                  = &H00000002???
%DOT11_CCA_MODE_ED_and_CS                = &H00000004???
%DOT11_CCA_MODE_CS_WITH_TIMER            = &H00000008???
%DOT11_CCA_MODE_HRCS_AND_ED              = &H00000010???

'    // ULONG

%OID_DOT11_CURRENT_CCA_MODE = (%OID_DOT11_NDIS_START + 55)
'    // ULONG

%OID_DOT11_ED_THRESHOLD = (%OID_DOT11_NDIS_START + 56)
'    // LONG (in "dBm"s)

'//
'// OIDs for dot11PhyIREntry
'//

%OID_DOT11_CCA_WATCHDOG_TIMER_MAX = (%OID_DOT11_NDIS_START + 57)
'    // ULONG (in nanoseconds)

%OID_DOT11_CCA_WATCHDOG_COUNT_MAX = (%OID_DOT11_NDIS_START + 58)
'    // ULONG

%OID_DOT11_CCA_WATCHDOG_TIMER_MIN = (%OID_DOT11_NDIS_START + 59)
'    // ULONG (in nanoseconds)

%OID_DOT11_CCA_WATCHDOG_COUNT_MIN = (%OID_DOT11_NDIS_START + 60)
'    // ULONG

'//
'// OIDs for dot11RegDomainsSupportEntry
'//

%OID_DOT11_REG_DOMAINS_SUPPORT_VALUE = (%OID_DOT11_NDIS_START + 61)

' // Size = 8 bytes
TYPE DOT11_REG_DOMAIN_VALUE DWORD
   uRegDomainsSupportIndex AS DWORD   ' ULONG
   uRegDomainsSupportValue AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE DOT11_REG_DOMAINS_SUPPORT_VALUE DWORD
   uNumOfEntries          AS DWORD   ' ULONG
   uTotalNumOfEntries     AS DWORD   ' ULONG
   dot11RegDomainValue(0) AS DOT11_REG_DOMAIN_VALUE
END TYPE

'//
'// OIDs for dot11AntennaListEntry
'//

%OID_DOT11_SUPPORTED_TX_ANTENNA = (%OID_DOT11_NDIS_START + 62)

' // Size = 8 bytes
TYPE DOT11_SUPPORTED_ANTENNA DWORD
   uAntennaListIndex AS DWORD   ' ULONG // Between 1 and 255.
   bSupportedAntenna AS BYTE    ' BOOLEAN
END TYPE

' // Size = 16 bytes
TYPE DOT11_SUPPORTED_ANTENNA_LIST DWORD
   uNumOfEntries            AS DWORD   ' ULONG
   uTotalNumOfEntries       AS DWORD   ' ULONG
   dot11SupportedAntenna(0) AS DOT11_SUPPORTED_ANTENNA
END TYPE

%OID_DOT11_SUPPORTED_RX_ANTENNA = (%OID_DOT11_NDIS_START + 63)
'    // DOT11_SUPPORTED_ANTENNA_LIST

%OID_DOT11_DIVERSITY_SELECTION_RX = (%OID_DOT11_NDIS_START + 64)

' // Size = 8 bytes
TYPE DOT11_DIVERSITY_SELECTION_RX DWORD
   uAntennaListIndex     AS DWORD   ' ULONG // Between 1 and 255.
   bDiversitySelectionRX AS BYTE    ' BOOLEAN
END TYPE

' // Size = 16 bytes
TYPE DOT11_DIVERSITY_SELECTION_RX_LIST DWORD
   uNumOfEntries                AS DWORD   ' ULONG
   uTotalNumOfEntries           AS DWORD   ' ULONG
   dot11DiversitySelectionRx(0) AS DOT11_DIVERSITY_SELECTION_RX
END TYPE

'//
'// OIDs for dot11SupportedDataRatesTxEntry and dot11SupportedDataRatesRxEntry
'//

%OID_DOT11_SUPPORTED_DATA_RATES_VALUE = (%OID_DOT11_NDIS_START + 65)

%MAX_NUM_SUPPORTED_RATES                = 8      ' // 8 data rates
%MAX_NUM_SUPPORTED_RATES_V2             = 255    ' // 255 data rates

' // Size = 16 bytes
TYPE DOT11_SUPPORTED_DATA_RATES_VALUE BYTE
   ucSupportedTxDataRatesValue(%MAX_NUM_SUPPORTED_RATES - 1) AS BYTE   ' UCHAR
   ucSupportedRxDataRatesValue(%MAX_NUM_SUPPORTED_RATES - 1) AS BYTE   ' UCHAR
END TYPE

' // Size = 510 bytes
TYPE DOT11_SUPPORTED_DATA_RATES_VALUE_V2 BYTE
   ucSupportedTxDataRatesValue(%MAX_NUM_SUPPORTED_RATES_V2 - 1) AS BYTE   ' UCHAR
   ucSupportedRxDataRatesValue(%MAX_NUM_SUPPORTED_RATES_V2 - 1) AS BYTE   ' UCHAR
END TYPE

'// keep the incorrect struct name to avoid build break
'typedef DOT11_SUPPORTED_DATA_RATES_VALUE_V2
'  DOT11_SUPPORTED_DATA_RATES_VALUE_V1, * PDOT11_SUPPORTED_DATA_RATES_VALUE_V1;

'//
'// OIDs for dot11PhyOFDMEntry
'//

%OID_DOT11_CURRENT_FREQUENCY = (%OID_DOT11_NDIS_START + 66)
'    // ULONG

%OID_DOT11_TI_THRESHOLD = (%OID_DOT11_NDIS_START + 67)
'    // LONG

%OID_DOT11_FREQUENCY_BANDS_SUPPORTED = (%OID_DOT11_NDIS_START + 68)

%DOT11_FREQUENCY_BANDS_LOWER    = &H00000001???
%DOT11_FREQUENCY_BANDS_MIDDLE   = &H00000002???
%DOT11_FREQUENCY_BANDS_UPPER    = &H00000004???
'    // ULONG

'//
'// OIDs for dot11PhyHRDSSSEntry
'//

%OID_DOT11_SHORT_PREAMBLE_OPTION_IMPLEMENTED = (%OID_DOT11_NDIS_START + 69)
'    // BOOL

%OID_DOT11_PBCC_OPTION_IMPLEMENTED = (%OID_DOT11_NDIS_START + 70)
'    // BOOL

%OID_DOT11_CHANNEL_AGILITY_PRESENT = (%OID_DOT11_NDIS_START + 71)
'    // BOOL

%OID_DOT11_CHANNEL_AGILITY_ENABLED = (%OID_DOT11_NDIS_START + 72)
'    // BOOL

%OID_DOT11_HR_CCA_MODE_SUPPORTED = (%OID_DOT11_NDIS_START + 73)
'    // HR-CCA mode bits

%DOT11_HR_CCA_MODE_ED_ONLY        = &H00000001???
%DOT11_HR_CCA_MODE_CS_ONLY        = &H00000002???
%DOT11_HR_CCA_MODE_CS_AND_ED      = &H00000004???
%DOT11_HR_CCA_MODE_CS_WITH_TIMER  = &H00000008???
%DOT11_HR_CCA_MODE_HRCS_AND_ED    = &H00000010???
'    // ULONG


'//
'// OIDs for dot11StationConfigEntry (Cont)
'//

%OID_DOT11_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED = (%OID_DOT11_NDIS_START + 74)
'    // BOOL

%OID_DOT11_MULTI_DOMAIN_CAPABILITY_ENABLED = (%OID_DOT11_NDIS_START + 75)
'    // BOOL

%OID_DOT11_COUNTRY_STRING = (%OID_DOT11_NDIS_START + 76)
'    // UCHAR[3]

'//
'// OIDs for dot11MultiDomainCapabilityEntry
'//

' // Size = 16 bytes
TYPE DOT11_MULTI_DOMAIN_CAPABILITY_ENTRY DWORD
   uMultiDomainCapabilityIndex AS DWORD   ' ULONG
   uFirstChannelNumber         AS DWORD   ' ULONG
   uNumberOfChannels           AS DWORD   ' ULONG
   lMaximumTransmitPowerLevel  AS LONG    ' ULONG
END TYPE

' // Size = 24 bytes
TYPE DOT11_MD_CAPABILITY_ENTRY_LIST DWORD
   uNumOfEntries             AS DWORD                                  ' ULONG
   uTotalNumOfEntries        AS DWORD                                  ' ULONG
   dot11MDCapabilityEntry(0) AS DOT11_MULTI_DOMAIN_CAPABILITY_ENTRY    ' DOT11_MULTI_DOMAIN_CAPABILITY_ENTRY enum
END TYPE


%OID_DOT11_MULTI_DOMAIN_CAPABILITY = (%OID_DOT11_NDIS_START + 77)
'    // DOT11_MD_CAPABILITY_ENTRY_LIST

'//
'// OIDs for dot11PhyFHSSEntry
'//

%OID_DOT11_EHCC_PRIME_RADIX = (%OID_DOT11_NDIS_START + 78)
'    // ULONG

%OID_DOT11_EHCC_NUMBER_OF_CHANNELS_FAMILY_INDEX = (%OID_DOT11_NDIS_START + 79)
'    // ULONG

%OID_DOT11_EHCC_CAPABILITY_IMPLEMENTED = (%OID_DOT11_NDIS_START + 80)
'    // BOOL

%OID_DOT11_EHCC_CAPABILITY_ENABLED = (%OID_DOT11_NDIS_START + 81)
'    // BOOL

%OID_DOT11_HOP_ALGORITHM_ADOPTED = (%OID_DOT11_NDIS_START + 82)

' enum _DOT11_HOP_ALGO_ADOPTED
%dot11_hop_algo_current   = 0
%dot11_hop_algo_hop_index = 1
%dot11_hop_algo_hcc       = 2

%OID_DOT11_RANDOM_TABLE_FLAG = (%OID_DOT11_NDIS_START + 83)
'    // BOOL

%OID_DOT11_NUMBER_OF_HOPPING_SETS = (%OID_DOT11_NDIS_START + 84)
'    // ULONG

%OID_DOT11_HOP_MODULUS = (%OID_DOT11_NDIS_START + 85)
'    // ULONG

%OID_DOT11_HOP_OFFSET = (%OID_DOT11_NDIS_START + 86)
'    // ULONG


'//
'// OIDs for dot11HoppingPatternEntry
'//
%OID_DOT11_HOPPING_PATTERN = (%OID_DOT11_NDIS_START + 87)

' // Size = 8 bytes
TYPE DOT11_HOPPING_PATTERN_ENTRY DWORD
   uHoppingPatternIndex    AS DWORD   ' ULONG
   uRandomTableFieldNumber AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE DOT11_HOPPING_PATTERN_ENTRY_LIST DWORD
   uNumOfEntries               AS DWORD                          ' ULONG
   uTotalNumOfEntries          AS DWORD                          ' ULONG
   dot11HoppingPatternEntry(0) AS DOT11_HOPPING_PATTERN_ENTRY    ' DOT11_HOPPING_PATTERN_ENTRY
END TYPE


%OID_DOT11_RANDOM_TABLE_FIELD_NUMBER = (%OID_DOT11_NDIS_START + 88)
'    // ULONG

'//
'// WPA Extensions
'//

%OID_DOT11_WPA_TSC = (%OID_DOT11_NDIS_START + 89)

' // Size = 20 bytes
TYPE DOT11_WPA_TSC DWORD
   uReserved        AS DWORD   ' ULONG
   dot11OffloadType AS LONG    ' DOT11_OFFLOAD_TYPE enum
   hOffload         AS DWORD   ' HANDLE
   dot11IV48Counter AS DOT11_IV48_COUNTER
END TYPE

'//
'// dot11.
'//

%OID_DOT11_RSSI_RANGE = (%OID_DOT11_NDIS_START + 90)

' // Size = 12 bytes
TYPE DOT11_RSSI_RANGE DWORD
   dot11PhyType AS DWORD   ' DOT11_PHY_TYPE
   uRSSIMin     AS DWORD   ' ULONG // Minimum caliberation value of RSSI in the NIC.
   uRSSIMax     AS DWORD   ' ULONG // Maximum caliberation value of RSSI in the NIC.
END TYPE

%OID_DOT11_RF_USAGE = (%OID_DOT11_NDIS_START + 91)
'//ULONG

%OID_DOT11_NIC_SPECIFIC_EXTENSION = (%OID_DOT11_NDIS_START + 92)

' // Size = 12 bytes
TYPE DOT11_NIC_SPECIFIC_EXTENSION DWORD
   uBufferLength      AS DWORD   ' ULONG
   uTotalBufferLength AS DWORD   ' ULONG
   ucBuffer(0)        AS BYTE    ' UCHAR
END TYPE

'//
'// AP join request
'//

%OID_DOT11_AP_JOIN_REQUEST = (%OID_DOT11_NDIS_START + 93)

' // Size = 192 bytes
TYPE DOT11_AP_JOIN_REQUEST   ' Must be 8 byte aligned
   uJoinFailureTimeout AS DWORD                   ' ULONG
   OperationalRateSet  AS DOT11_RATE_SET
   uChCenterFrequency  AS DWORD                   ' ULONG
   alignment__         AS DWORD
   dot11BSSDescription AS DOT11_BSS_DESCRIPTION   ' // Must be the last field.
END TYPE

'//
'// dot11PhyERPEntry
'//
'#define OID_DOT11_ERP_PBCC_OPTION_IMPLEMENTED       (OID_DOT11_NDIS_START + 94)
'    // BOOL

%OID_DOT11_ERP_PBCC_OPTION_ENABLED = (%OID_DOT11_NDIS_START + 95)
'    // BOOL

%OID_DOT11_DSSS_OFDM_OPTION_IMPLEMENTED = (%OID_DOT11_NDIS_START + 96)
'    // BOOL

%OID_DOT11_DSSS_OFDM_OPTION_ENABLED = (%OID_DOT11_NDIS_START + 97)
'    // BOOL

%OID_DOT11_SHORT_SLOT_TIME_OPTION_IMPLEMENTED = (%OID_DOT11_NDIS_START + 98)
'    // BOOL

%OID_DOT11_SHORT_SLOT_TIME_OPTION_ENABLED = (%OID_DOT11_NDIS_START + 99)
'    // BOOL

%OID_DOT11_MAX_MAC_ADDRESS_STATES = (%OID_DOT11_NDIS_START + 100)
'    // ULONG

%OID_DOT11_RECV_SENSITIVITY_LIST = (%OID_DOT11_NDIS_START + 101)
'    // DOT11_RECV_SENSITIVITY_LIST

' // Size = 192 bytes
TYPE DOT11_RECV_SENSITIVITY DWORD
   ucDataRate AS BYTE   ' UCHAR
   lRSSIMin   AS LONG   ' LONG
   lRSSIMax   AS LONG   ' LONG
END TYPE

' // Size = 4 bytes
UNION DOT11_RECV_SENSITIVITY_LIST_UNION DWORD
   dot11PhyType AS DWORD   ' DOT11_PHY_TYPE enum
   uPhyId       AS DWORD   ' ULONG
END UNION

' // Size = 24 bytes
TYPE DOT11_RECV_SENSITIVITY_LIST DWORD
   DOT11_RECV_SENSITIVITY_LIST_UNION
   uNumOfEntries           AS DWORD   ' ULONG
   uTotalNumOfEntries      AS DWORD   ' ULONG
   dot11RecvSensitivity(0) AS DOT11_RECV_SENSITIVITY
END TYPE


'//
'// WME
'//

%OID_DOT11_WME_IMPLEMENTED = (%OID_DOT11_NDIS_START + 102)
'    // BOOL

%OID_DOT11_WME_ENABLED = (%OID_DOT11_NDIS_START + 103)
'    // BOOL

%OID_DOT11_WME_AC_PARAMETERS = (%OID_DOT11_NDIS_START + 104)

' enum _DOT11_AC_PARAM
%dot11_AC_param_BE  = 0     ' // Best Effort
%dot11_AC_param_BK  = 1     ' // Background
%dot11_AC_param_VI  = 2     ' // Video
%dot11_AC_param_VO  = 3     ' // Voice
%dot11_AC_param_max = 4

' // Size = 6 bytes
TYPE DOT11_WME_AC_PARAMETERS BYTE
   ucAccessCategoryIndex AS BYTE   ' UCHAR
   ucAIFSN               AS BYTE   ' UCHAR
   ucECWmin              AS BYTE   ' UCHAR
   ucECWmax              AS BYTE   ' UCHAR
   usTXOPLimit           AS WORD   ' USHORT
END TYPE

' // Size = 16 bytes
TYPE DOT11_WME_AC_PARAMETERS_LIST DWORD
   uNumOfEntries           AS DWORD   ' ULONG
   uTotalNumOfEntries      AS DWORD   ' ULONG
   dot11WMEACParameters(0) AS DOT11_WME_AC_PARAMETERS
END TYPE

%OID_DOT11_WME_UPDATE_IE = (%OID_DOT11_NDIS_START + 105)

' // Size = 24 bytes
TYPE DOT11_WME_UPDATE_IE DWORD
   uParamElemMinBeaconIntervals AS DWORD   ' ULONG
   uWMEInfoElemOffset           AS DWORD   ' ULONG
   uWMEInfoElemLength           AS DWORD   ' ULONG
   uWMEParamElemOffset          AS DWORD   ' ULONG
   uWMEParamElemLength          AS DWORD   ' ULONG
   ucBuffer(0)                  AS BYTE    ' UCHAR // Must be the last field.
END TYPE

'//
'// QoS
'//
%OID_DOT11_QOS_TX_QUEUES_SUPPORTED = (%OID_DOT11_NDIS_START + 106)
'    // ULONG

%OID_DOT11_QOS_TX_DURATION = (%OID_DOT11_NDIS_START + 107)

' // Size = 12 bytes
TYPE DOT11_QOS_TX_DURATION DWORD
   uNominalMSDUSize AS DWORD   ' ULONG
   uMinPHYRate      AS DWORD   ' ULONG
   uDuration        AS DWORD   ' ULONG
END TYPE

%OID_DOT11_QOS_TX_MEDIUM_TIME = (%OID_DOT11_NDIS_START + 108)

' // Size = 12 bytes
TYPE DOT11_QOS_TX_MEDIUM_TIME DWORD FILL
   dot11PeerAddress   AS DOT11_MAC_ADDRESS
   ucQoSPriority      AS BYTE    ' UCHAR
   uMediumTimeAdmited AS DWORD   ' ULONG
END TYPE

'//
'// NIC supported channel/center frequency list
'//
%OID_DOT11_SUPPORTED_OFDM_FREQUENCY_LIST = (%OID_DOT11_NDIS_START + 109)

' // Size = 4 bytes
TYPE DOT11_SUPPORTED_OFDM_FREQUENCY DWORD
   uCenterFrequency AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE DOT11_SUPPORTED_OFDM_FREQUENCY_LIST DWORD
   uNumOfEntries                  AS DWORD   ' ULONG
   uTotalNumOfEntries             AS DWORD   ' ULONG
   dot11SupportedOFDMFrequency(0) AS DOT11_SUPPORTED_OFDM_FREQUENCY
END TYPE

%OID_DOT11_SUPPORTED_DSSS_CHANNEL_LIST = (%OID_DOT11_NDIS_START + 110)

' // Size = 4 bytes
TYPE DOT11_SUPPORTED_DSSS_CHANNEL DWORD
   uChannel AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
TYPE DOT11_SUPPORTED_DSSS_CHANNEL_LIST DWORD
   uNumOfEntries                AS DWORD   ' ULONG
   uTotalNumOfEntries           AS DWORD   ' ULONG
   dot11SupportedDSSSChannel(0) AS DOT11_SUPPORTED_DSSS_CHANNEL
END TYPE


'//
'// Extensible STA
'//

' // Size = 16 bytes
TYPE DOT11_BYTE_ARRAY DWORD
   Header           AS NDIS_OBJECT_HEADER
   uNumOfBytes      AS DWORD   ' ULONG
   uTotalNumOfBytes AS DWORD   ' ULONG
   ucBuffer(0)      AS BYTE    ' UCHAR
END TYPE

'#define OID_DOT11_AUTO_CONFIG_ENABLED               NWF_DEFINE_OID(120,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // ULONG
%OID_DOT11_AUTO_CONFIG_ENABLED = &H0E010178???


%DOT11_PHY_AUTO_CONFIG_ENABLED_FLAG = &H00000001???
%DOT11_MAC_AUTO_CONFIG_ENABLED_FLAG = &H00000002???

'#define OID_DOT11_ENUM_BSS_LIST                     NWF_DEFINE_OID(121,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_ENUM_BSS_LIST = &H0E010178???

'// DOT11_BYTE_ARRAY with DOT11_BSS_ENTRY
%DOT11_BSS_ENTRY_BYTE_ARRAY_REVISION_1 = 1

'// This structure is not supposed to be midl compliant because of
'// DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO. The selection of union is
'// *indirectly* determined from uPhyId. MIDL will not work here.

' // Size = 12 bytes
TYPE DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO_FHSS DWORD
   uHopPattern AS DWORD   ' ULONG
   uHopSet     AS DWORD   ' ULONG
   uDwellTime  AS DWORD   ' ULONG
END TYPE

' // Size = 12 bytes
UNION DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO DWORD
   uChCenterFrequency AS DWORD   ' ULONG
   FHSS AS DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO_FHSS
END UNION

' // Size = 72 bytes
TYPE DOT11_BSS_ENTRY QWORD FILL  ' Must be 8 byte aligned
   uPhyId                  AS DWORD   ' ULONG
   PhySpecificInfo         AS DOT11_BSS_ENTRY_PHY_SPECIFIC_INFO
   dot11BSSID              AS DOT11_MAC_ADDRESS
   dot11BSSType            AS LONG    ' DOT11_BSS_TYPE enum
   lRSSI                   AS LONG    ' LONG
   uLinkQuality            AS DWORD   ' ULONG
   bInRegDomain            AS BYTE    ' BOOLEAN
   usBeaconPeriod          AS WORD    ' USHORT
   ullTimestamp            AS QUAD    ' ULONGLONG
   ullHostTimestamp        AS QUAD    ' ULONGLONG
   usCapabilityInformation AS WORD    ' USHORT
   uBufferLength           AS DWORD   ' ULONG
   ucBuffer(1)             AS BYTE    ' UCHAR // Must be the last field.
   ' Nite: We are using ucBuffer(1) instead of ucBuffer(0) to keep 8 byte alignment
END TYPE

'#define OID_DOT11_FLUSH_BSS_LIST                    NWF_DEFINE_OID(122,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // VOID
%OID_DOT11_FLUSH_BSS_LIST = &H0E01017A???

'#define OID_DOT11_POWER_MGMT_REQUEST                NWF_DEFINE_OID(123,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // ULONG
%OID_DOT11_POWER_MGMT_REQUEST = &H0E01017B???

%DOT11_POWER_SAVING_NO_POWER_SAVING = 0
%DOT11_POWER_SAVING_FAST_PSP        = 8
%DOT11_POWER_SAVING_MAX_PSP         = 16
%DOT11_POWER_SAVING_MAXIMUM_LEVEL   = 24

'#define OID_DOT11_DESIRED_SSID_LIST                 NWF_DEFINE_OID(124,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // A list of DOT11_SSID
%OID_DOT11_DESIRED_SSID_LIST = &H0E01017C???

%DOT11_SSID_LIST_REVISION_1 = 1

' // Size = 48 bytes
TYPE DOT11_SSID_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   SSIDs(0)           AS DOT11_SSID
END TYPE

'#define OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST         NWF_DEFINE_OID(125,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // A list of DOT11_MAC_ADDRESS
%OID_DOT11_EXCLUDED_MAC_ADDRESS_LIST = &H0E01017D???

%DOT11_MAC_ADDRESS_LIST_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_MAC_ADDRESS_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   MacAddrs(0)        AS DOT11_MAC_ADDRESS
END TYPE

'#define OID_DOT11_DESIRED_BSSID_LIST                NWF_DEFINE_OID(126,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_DESIRED_BSSID_LIST = &H0E01017E???

'#define OID_DOT11_DESIRED_BSS_TYPE                  NWF_DEFINE_OID(127,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // DOT11_BSS_TYPE
%OID_DOT11_DESIRED_BSS_TYPE = &H0E01017F???

'#define OID_DOT11_PMKID_LIST                        NWF_DEFINE_OID(128,NWF_OPERATIONAL_OID,NWF_OPTIONAL_OID)
'    // A list of DOT11_PMKID_ENTRY
%OID_DOT11_PMKID_LIST = &H0E010180???

' typedef UCHAR DOT11_PMKID_VALUE[16];

UNION DOT11_PMKID_ENTRY_UNION
   PMKID(15) AS BYTE                ' DOT11_PMKID_VALUE[16]
   PMKID AS STRING * 16
END UNION

' // Size = 28 bytes
TYPE DOT11_PMKID_ENTRY DWORD
   BSSID     AS DOT11_MAC_ADDRESS
   DOT11_PMKID_ENTRY_UNION
   uFlags    AS DWORD               ' ULONG
END TYPE

%DOT11_PMKID_LIST_REVISION_1 = 1

' // Size = 40 bytes
TYPE DOT11_PMKID_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   PMKIDs(0)          AS DOT11_PMKID_ENTRY
END TYPE

'#define OID_DOT11_CONNECT_REQUEST                   NWF_DEFINE_OID(129,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // no data type
%OID_DOT11_CONNECT_REQUEST = &H0E010181???

'#define OID_DOT11_EXCLUDE_UNENCRYPTED               NWF_DEFINE_OID(130,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // BOOLEAN
%OID_DOT11_EXCLUDE_UNENCRYPTED = &H0E010182???

'#define OID_DOT11_STATISTICS                        NWF_DEFINE_OID(131,NWF_STATISTICS_OID,NWF_MANDATORY_OID)
'    // DOT11_STATISTICS structure
%OID_DOT11_STATISTICS = &H0E020183???

%DOT11_STATISTICS_UNKNOWN = -1&&   ' (ULONGLONG)(-1LL)

' // Size = 144 bytes
TYPE DOT11_PHY_FRAME_STATISTICS QWORD
   ' // TX counters (MSDU/MMPDU)
   ullTransmittedFrameCount            AS QUAD   ' ULONGLONG
   ullMulticastTransmittedFrameCount   AS QUAD   ' ULONGLONG
   ullFailedCount                      AS QUAD   ' ULONGLONG
   ullRetryCount                       AS QUAD   ' ULONGLONG
   ullMultipleRetryCount               AS QUAD   ' ULONGLONG
   ullMaxTXLifetimeExceededCount       AS QUAD   ' ULONGLONG
   ' // TX counters (MPDU)
   ullTransmittedFragmentCount         AS QUAD   ' ULONGLONG
   ullRTSSuccessCount                  AS QUAD   ' ULONGLONG
   ullRTSFailureCount                  AS QUAD   ' ULONGLONG
   ullACKFailureCount                  AS QUAD   ' ULONGLONG
   ' // RX counters (MSDU/MMPDU)
   ullReceivedFrameCount               AS QUAD   ' ULONGLONG
   ullMulticastReceivedFrameCount      AS QUAD   ' ULONGLONG
   ullPromiscuousReceivedFrameCount    AS QUAD   ' ULONGLONG
   ullMaxRXLifetimeExceededCount       AS QUAD   ' ULONGLONG
   ' // RX counters (MPDU)
   ullFrameDuplicateCount              AS QUAD   ' ULONGLONG
   ullReceivedFragmentCount            AS QUAD   ' ULONGLONG
   ullPromiscuousReceivedFragmentCount AS QUAD   ' ULONGLONG
   ullFCSErrorCount                    AS QUAD   ' ULONGLONG
END TYPE

' // Size = 112 bytes
TYPE DOT11_MAC_FRAME_STATISTICS QWORD
   ullTransmittedFrameCount        AS QUAD   ' ULONGLONG
   ullReceivedFrameCount           AS QUAD   ' ULONGLONG
   ullTransmittedFailureFrameCount AS QUAD   ' ULONGLONG
   ullReceivedFailureFrameCount    AS QUAD   ' ULONGLONG
   ullWEPExcludedCount             AS QUAD   ' ULONGLONG
   ullTKIPLocalMICFailures         AS QUAD   ' ULONGLONG
   ullTKIPReplays                  AS QUAD   ' ULONGLONG
   ullTKIPICVErrorCount            AS QUAD   ' ULONGLONG
   ullCCMPReplays                  AS QUAD   ' ULONGLONG
   ullCCMPDecryptErrors            AS QUAD   ' ULONGLONG
   ullWEPUndecryptableCount        AS QUAD   ' ULONGLONG
   ullWEPICVErrorCount             AS QUAD   ' ULONGLONG
   ullDecryptSuccessCount          AS QUAD   ' ULONGLONG
   ullDecryptFailureCount          AS QUAD   ' ULONGLONG
END TYPE

%DOT11_STATISTICS_REVISION_1 = 1

' // Size = 400 bytes
TYPE DOT11_STATISTICS  ' Must be 8 byte aligned
   Header                        AS NDIS_OBJECT_HEADER
   alignment__                   AS DWORD
   ullFourWayHandshakeFailures   AS QUAD                         ' ULONGLONG
   ullTKIPCounterMeasuresInvoked AS QUAD                         ' ULONGLONG
   ullReserved                   AS QUAD                         ' ULONGLONG
   MacUcastCounters              AS DOT11_MAC_FRAME_STATISTICS
   MacMcastCounters              AS DOT11_MAC_FRAME_STATISTICS
   PhyCounters(0)                AS DOT11_PHY_FRAME_STATISTICS
END TYPE

'#define OID_DOT11_PRIVACY_EXEMPTION_LIST            NWF_DEFINE_OID(132,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'    // A list of DOT11_PRIVACY_EXEMPTION
%OID_DOT11_PRIVACY_EXEMPTION_LIST = &H0E010184???

%DOT11_EXEMPT_NO_EXEMPTION      = 0   ' // used only in DOT11_EXTSTA_SEND_CONTEXT
%DOT11_EXEMPT_ALWAYS            = 1
%DOT11_EXEMPT_ON_KEY_MAPPING_KEY_UNAVAILABLE = 2

%DOT11_EXEMPT_UNICAST   = 1
%DOT11_EXEMPT_MULTICAST = 2
%DOT11_EXEMPT_BOTH      = 3

' // Size = 6 bytes
TYPE DOT11_PRIVACY_EXEMPTION WORD
   usEtherType           AS WORD   ' USHORT
   usExemptionActionType AS WORD   ' USHORT
   usExemptionPacketType AS WORD   ' USHORT
END TYPE

%DOT11_PRIVACY_EXEMPTION_LIST_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_PRIVACY_EXEMPTION_LIST DWORD
   Header                     AS NDIS_OBJECT_HEADER
   uNumOfEntries              AS DWORD                     ' ULONG
   uTotalNumOfEntries         AS DWORD                     ' ULONG
   PrivacyExemptionEntries(0) AS DOT11_PRIVACY_EXEMPTION
END TYPE

'#define OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHM  NWF_DEFINE_OID(133,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_ENABLED_AUTHENTICATION_ALGORITHM = &H0E010185???

%DOT11_AUTH_ALGORITHM_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_AUTH_ALGORITHM_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   AlgorithmIds(0)    AS LONG    ' DOT11_AUTH_ALGORITHM enum
END TYPE

'#define OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR  NWF_DEFINE_OID(134,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_SUPPORTED_UNICAST_ALGORITHM_PAIR = &H0E010186???

%DOT11_AUTH_CIPHER_PAIR_LIST_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_AUTH_CIPHER_PAIR_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   AuthCipherPairs(0) AS DOT11_AUTH_CIPHER_PAIR   ' __field_ecount(uNumOfEntries) DOT11_AUTH_CIPHER_PAIR AuthCipherPairs[1];
END TYPE

'#define OID_DOT11_ENABLED_UNICAST_CIPHER_ALGORITHM  NWF_DEFINE_OID(135,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_ENABLED_UNICAST_CIPHER_ALGORITHM = &H0E010187???
'// DOT11_CIPHER_ALGO_LIST

%DOT11_CIPHER_ALGORITHM_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_CIPHER_ALGORITHM_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   AlgorithmIds(0)    AS LONG                 ' DOT11_CIPHER_ALGORITHM
END TYPE

'#define OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR    NWF_DEFINE_OID(136,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_SUPPORTED_MULTICAST_ALGORITHM_PAIR = &H0E010188???

'#define OID_DOT11_ENABLED_MULTICAST_CIPHER_ALGORITHM    NWF_DEFINE_OID(137,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_CIPHER_ALGORITHM_LIST
%OID_DOT11_ENABLED_MULTICAST_CIPHER_ALGORITHM = &H0E010189???

'#define OID_DOT11_CIPHER_DEFAULT_KEY_ID             NWF_DEFINE_OID(138,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// ULONG
%OID_DOT11_CIPHER_DEFAULT_KEY_ID = &H0E01018A???

'#define OID_DOT11_CIPHER_DEFAULT_KEY                NWF_DEFINE_OID(139,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_CIPHER_DEFAULT_KEY = &H0E01018B???

%DOT11_CIPHER_DEFAULT_KEY_VALUE_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_CIPHER_DEFAULT_KEY_VALUE
   Header      AS NDIS_OBJECT_HEADER
   uKeyIndex   AS DWORD                ' ULONG
   AlgorithmId AS LONG                 ' DOT11_CIPHER_ALGORITHM enum
   MacAddr     AS DOT11_MAC_ADDRESS
   bDelete     AS BYTE                 ' BOOLEAN
   bStatic     AS BYTE                 ' BOOLEAN
   usKeyLength AS WORD                 ' USHORT
   ucKey(1)    AS BYTE                 ' UCHAR // Must be the last field
   ' Note: We are using ucKey(1) instead of ucKey(0) to keep DWORD alignment
END TYPE

' // Size = 20 bytes
TYPE DOT11_KEY_ALGO_TKIP_MIC
   ucIV48Counter(5) AS BYTE    ' UCHAR[6]
   alignment__      AS WORD
   ulTKIPKeyLength  AS DWORD   ' ULONG
   ulMICKeyLength   AS DWORD   ' ULONG
   ucTKIPMICKeys(3) AS BYTE    ' UCHAR // Must be the last field.
   ' Note: We are using ucTKIPMICKeys(3) instead of ucTKIPMICKeys(0) to keep DWORD alignment
END TYPE

' // Size = 16 bytes
TYPE DOT11_KEY_ALGO_CCMP DWORD
   ucIV48Counter(5) AS BYTE    ' UCHAR[6]
   ulCCMPKeyLength  AS DWORD   ' ULONG
   ucCCMPKey(0)     AS BYTE    ' UCHAR
END TYPE

'#define OID_DOT11_CIPHER_KEY_MAPPING_KEY            NWF_DEFINE_OID(140,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_BYTE_ARRAY
%OID_DOT11_CIPHER_KEY_MAPPING_KEY = &H0E01018C???

' enum DOT11_DIRECTION
%DOT11_DIR_INBOUND  = 1
%DOT11_DIR_OUTBOUND = 2
%DOT11_DIR_BOTH     = 3

%DOT11_CIPHER_KEY_MAPPING_KEY_VALUE_BYTE_ARRAY_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_CIPHER_KEY_MAPPING_KEY_VALUE DWORD FILL
   PeerMacAddr AS DOT11_MAC_ADDRESS
   AlgorithmId AS LONG                ' DOT11_CIPHER_ALGORITHM
   Direction   AS LONG                ' DOT11_DIRECTION enum
   bDelete     AS BYTE                ' BOOLEAN
   bStatic     AS BYTE                ' BOOLEAN
   usKeyLength AS WORD                ' USHORT
   ucKey(3)    AS BYTE                ' UCHAR // Must be the last field
   ' Note: We are using ucKey(3) instead of ucKey(0) to keep DWORD alignment
END TYPE

'#define OID_DOT11_ENUM_ASSOCIATION_INFO             NWF_DEFINE_OID(141,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// a list of DOT11_ASSOCIATION_INFO
%OID_DOT11_ENUM_ASSOCIATION_INFO = &H0E01018D???

' enum _DOT11_ASSOCIATION_STATE
%dot11_assoc_state_zero           = 0
%dot11_assoc_state_unauth_unassoc = 1
%dot11_assoc_state_auth_unassoc   = 2
%dot11_assoc_state_auth_assoc     = 3

' // Size = 328 bytes
TYPE DOT11_ASSOCIATION_INFO_EX   ' Must be 8 byte aligned
   PeerMacAddress            AS DOT11_MAC_ADDRESS
   BSSID                     AS DOT11_MAC_ADDRESS
   usCapabilityInformation   AS WORD   ' USHORT
   usListenInterval          AS WORD   ' USHORT
   ucPeerSupportedRates(%MAX_NUM_SUPPORTED_RATES_V2 - 1) AS BYTE   ' UCHAR
   alignment1__              AS BYTE
   usAssociationID           AS WORD   ' USHORT
   alignment2__              AS WORD
   dot11AssociationState     AS LONG   ' DOT11_ASSOCIATION_STATE
   dot11PowerMode            AS LONG   ' DOT11_POWER_MODE
   alignment3__              AS DWORD
   liAssociationUpTime       AS QUAD   ' LARGE_INTEGER
   ullNumOfTxPacketSuccesses AS QUAD   ' ULONGLONG
   ullNumOfTxPacketFailures  AS QUAD   ' ULONGLONG
   ullNumOfRxPacketSuccesses AS QUAD   ' ULONGLONG
   ullNumOfRxPacketFailures  AS QUAD   ' ULONGLONG
END TYPE

%DOT11_ASSOCIATION_INFO_LIST_REVISION_1 = 1

' // Size = 344 bytes
TYPE DOT11_ASSOCIATION_INFO_LIST   ' Must be 8 byte aligned
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                       ' ULONG
   uTotalNumOfEntries AS DWORD                       ' ULONG
   alignment__        AS DWORD
   dot11AssocInfo(0)  AS DOT11_ASSOCIATION_INFO_EX
END TYPE

'#define OID_DOT11_DISCONNECT_REQUEST                NWF_DEFINE_OID(142,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_DISCONNECT_REQUEST = &H0E01018E???

'#define OID_DOT11_UNICAST_USE_GROUP_ENABLED         NWF_DEFINE_OID(143,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// BOOLEAN
%OID_DOT11_UNICAST_USE_GROUP_ENABLED = &H0E01018F???

'#define OID_DOT11_HARDWARE_PHY_STATE                NWF_DEFINE_OID(144,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// BOOLEAN
%OID_DOT11_HARDWARE_PHY_STATE = &H0E010190???

'#define OID_DOT11_DESIRED_PHY_LIST                  NWF_DEFINE_OID(145,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_PHY_ID_LIST
%OID_DOT11_DESIRED_PHY_LIST = &H0E010191???

%DOT11_PHY_ID_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_PHY_ID_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   dot11PhyId(0)      AS DWORD                ' ULONG
END TYPE

%DOT11_PHY_ID_ANY = &Hffffffff???

'#define OID_DOT11_CURRENT_PHY_ID                    NWF_DEFINE_OID(146,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// ULONG
%OID_DOT11_CURRENT_PHY_ID = &H0E010192???

'#define OID_DOT11_MEDIA_STREAMING_ENABLED           NWF_DEFINE_OID(147,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// BOOLEAN
%OID_DOT11_MEDIA_STREAMING_ENABLED = &H0E010193???

'#define OID_DOT11_UNREACHABLE_DETECTION_THRESHOLD   NWF_DEFINE_OID(148,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// ULONG
%OID_DOT11_UNREACHABLE_DETECTION_THRESHOLD = &H0E010194???

'#define OID_DOT11_ACTIVE_PHY_LIST                   NWF_DEFINE_OID(149,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_PHY_ID_LIST
%OID_DOT11_ACTIVE_PHY_LIST = &H0E010195???

'#define OID_DOT11_EXTSTA_CAPABILITY                 NWF_DEFINE_OID(150,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_EXTSTA_CAPABILITY
%OID_DOT11_EXTSTA_CAPABILITY = &H0E010196???

%DOT11_EXTSTA_CAPABILITY_REVISION_1 = 1

' // Size = 44 bytes
TYPE DOT11_EXTSTA_CAPABILITY DWORD
   Header                        AS NDIS_OBJECT_HEADER
   uScanSSIDListSize             AS DWORD                ' ULONG
   uDesiredBSSIDListSize         AS DWORD                ' ULONG
   uDesiredSSIDListSize          AS DWORD                ' ULONG
   uExcludedMacAddressListSize   AS DWORD                ' ULONG
   uPrivacyExemptionListSize     AS DWORD                ' ULONG
   uKeyMappingTableSize          AS DWORD                ' ULONG
   uDefaultKeyTableSize          AS DWORD                ' ULONG
   uWEPKeyValueMaxLength         AS DWORD                ' ULONG
   uPMKIDCacheSize               AS DWORD                ' ULONG
   uMaxNumPerSTADefaultKeyTables AS DWORD                ' ULONG
END TYPE

'#define OID_DOT11_DATA_RATE_MAPPING_TABLE           NWF_DEFINE_OID(151,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_DATA_RATE_MAPPING_ENTRY
%OID_DOT11_DATA_RATE_MAPPING_TABLE = &H0E010197???

' // Size = 4 bytes
TYPE DOT11_DATA_RATE_MAPPING_ENTRY BYTE
   ucDataRateIndex AS BYTE   ' UCHAR
   ucDataRateFlag  AS BYTE   ' UCHAR
   usDataRateValue AS WORD   ' USHORT
END TYPE

%DOT11_DATA_RATE_MAPPING_TABLE_REVISION_1 = 1

' // Size = 512 bytes
TYPE DOT11_DATA_RATE_MAPPING_TABLE BYTE
   Header AS NDIS_OBJECT_HEADER
   uDataRateMappingLength AS DWORD   ' ULONG
   DataRateMappingEntries(%DOT11_RATE_SET_MAX_LENGTH - 1) AS DOT11_DATA_RATE_MAPPING_ENTRY
END TYPE

%DOT11_DATA_RATE_NON_STANDARD = &H01???
%DOT11_DATA_RATE_INDEX_MASK   = &H7f???

'#define OID_DOT11_SUPPORTED_COUNTRY_OR_REGION_STRING    NWF_DEFINE_OID(152,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
%OID_DOT11_SUPPORTED_COUNTRY_OR_REGION_STRING = &H0E010198???

%DOT11_COUNTRY_OR_REGION_STRING_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_COUNTRY_OR_REGION_STRING_LIST DWORD
   Header                    AS NDIS_OBJECT_HEADER
   uNumOfEntries             AS DWORD        ' ULONG
   uTotalNumOfEntries        AS DWORD        ' ULONG
   CountryOrRegionStrings(0) AS DOT11_COUNTRY_OR_REGION_STRING
END TYPE

'#define OID_DOT11_DESIRED_COUNTRY_OR_REGION_STRING      NWF_DEFINE_OID(153,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_COUNTRY_OR_REGION_STRING
%OID_DOT11_DESIRED_COUNTRY_OR_REGION_STRING = &H0E010199???

'#define OID_DOT11_PORT_STATE_NOTIFICATION           NWF_DEFINE_OID(154,NWF_OPERATIONAL_OID,NWF_OPTIONAL_OID)
'// DOT11_PORT_STATE_NOTIFICATION
%OID_DOT11_PORT_STATE_NOTIFICATION = &H0E01019A???

%DOT11_PORT_STATE_NOTIFICATION_REVISION_1 = 1

' // Size = 12 bytes
TYPE DOT11_PORT_STATE_NOTIFICATION WORD
   Header      AS NDIS_OBJECT_HEADER
   PeerMac     AS DOT11_MAC_ADDRESS
   bOpen       AS BYTE                 ' BOOLEAN
END TYPE

'#define OID_DOT11_IBSS_PARAMS                       NWF_DEFINE_OID(155,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// DOT11_IBSS_PARAMS
%OID_DOT11_IBSS_PARAMS = &H0E01019B???

%DOT11_IBSS_PARAMS_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_IBSS_PARAMS DWORD
   Header     AS NDIS_OBJECT_HEADER
   bJoinOnly  AS BYTE                 ' BOOLEAN
   uIEsOffset AS DWORD                ' ULONG
   uIEsLength AS DWORD                ' ULONG
END TYPE

'#define OID_DOT11_QOS_PARAMS                        NWF_DEFINE_OID(156,NWF_OPERATIONAL_OID,NWF_OPTIONAL_OID)
%OID_DOT11_QOS_PARAMS = &H0E01019C???

%DOT11_QOS_PROTOCOL_FLAG_WMM     = &H01???        ' // WMM QoS protocol
%DOT11_QOS_PROTOCOL_FLAG_11E     = &H02???        ' // 802.11e QoS protocol

%DOT11_QOS_PARAMS_REVISION_1 = 1

' // Size = 6 bytes
TYPE DOT11_QOS_PARAMS WORD
   Header AS NDIS_OBJECT_HEADER
   ' // Flags of the enabled QoS protocols.
   ' // It is either 0 or combination of DOT11_QOS_PROTOCOL_FLAG_WMM
   ' // and/or DOT11_QOS_PROTOCOL_FLAG_11E
   ucEnabledQoSProtocolFlags AS BYTE   ' UCHAR
END TYPE

'#define OID_DOT11_SAFE_MODE_ENABLED                 NWF_DEFINE_OID(157,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// BOOLEAN
%OID_DOT11_SAFE_MODE_ENABLED = &H0E01019D???

'#define OID_DOT11_HIDDEN_NETWORK_ENABLED            NWF_DEFINE_OID(158,NWF_OPERATIONAL_OID,NWF_MANDATORY_OID)
'// BOOLEAN
%OID_DOT11_HIDDEN_NETWORK_ENABLED = &H0E01019E???

'//
'// 802.11 Extensions to Standard NDIS Functions
'//

'//
'// Miniport Send Path Extension
'//

'// Only 4 bits are present in the 802.11 header to track fragments.
%DOT11_MAX_NUM_OF_FRAGMENTS                 = 16
'// Priority Classes.
%DOT11_PRIORITY_CONTENTION                  = 0
%DOT11_PRIORITY_CONTENTION_FREE             = 1

'// Service Classes.
%DOT11_SERVICE_CLASS_REORDERABLE_MULTICAST   = 0
%DOT11_SERVICE_CLASS_STRICTLY_ORDERED        = 1
'// Flags.
%DOT11_FLAGS_80211B_SHORT_PREAMBLE           = &H00000001???
%DOT11_FLAGS_80211B_PBCC                     = &H00000002???
%DOT11_FLAGS_80211B_CHANNEL_AGILITY          = &H00000004???
%DOT11_FLAGS_PS_ON                           = &H00000008???
%DOT11_FLAGS_80211G_DSSS_OFDM                = &H00000010???
%DOT11_FLAGS_80211G_USE_PROTECTION           = &H00000020???
%DOT11_FLAGS_80211G_NON_ERP_PRESENT          = &H00000040???
%DOT11_FLAGS_80211G_BARKER_PREAMBLE_MODE     = &H00000080???
%DOT11_WME_PACKET                            = &H00000100???

' // Size = 8 bytes
TYPE DOT11_FRAGMENT_DESCRIPTOR DWORD
   uOffset AS DWORD   ' ULONG
   uLength AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE DOT11_PER_MSDU_COUNTERS DWORD
   uTransmittedFragmentCount AS DWORD   ' ULONG
   uRetryCount               AS DWORD   ' ULONG
   uRTSSuccessCount          AS DWORD   ' ULONG
   uRTSFailureCount          AS DWORD   ' ULONG
   uACKFailureCount          AS DWORD   ' ULONG
END TYPE

'typedef struct DOT11_PHY_ATTRIBUTES DOT11_PHY_ATTRIBUTES, * PDOT11_PHY_ATTRIBUTES;

' // Size = 8 bytes
TYPE DOT11_HRDSSS_PHY_ATTRIBUTES DWORD FILL
   bShortPreambleOptionImplemented AS BYTE    ' BOOLEAN
   bPBCCOptionImplemented          AS BYTE    ' BOOLEAN
   bChannelAgilityPresent          AS BYTE    ' BOOLEAN
   uHRCCAModeSupported             AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE DOT11_OFDM_PHY_ATTRIBUTES DWORD
   uFrequencyBandsSupported AS DWORD   ' ULONG
END TYPE

UNION DOT11_ERP_PHY_ATTRIBUTES_UNION
   HRDSSSAttributes                AS DOT11_HRDSSS_PHY_ATTRIBUTES
   ' // For vompatibility with the PB headers
   DOT11_HRDSSS_PHY_ATTRIBUTES
END UNION

' // Size = 12 bytes
TYPE DOT11_ERP_PHY_ATTRIBUTES
   DOT11_ERP_PHY_ATTRIBUTES_UNION
   bERPPBCCOptionImplemented       AS BYTE   ' BOOLEAN
   bDSSSOFDMOptionImplemented      AS BYTE   ' BOOLEAN
   bShortSlotTimeOptionImplemented AS BYTE   ' BOOLEAN
   alignment__                     AS BYTE
END TYPE

%DOT11_PHY_ATTRIBUTES_REVISION_1 = 1

' // Size = 12 bytes
UNION DOT11_PHY_ATTRIBUTES_PhySpecificAttributes DWORD
   HRDSSSAttributes AS DOT11_HRDSSS_PHY_ATTRIBUTES
   OFDMAttributes   AS DOT11_OFDM_PHY_ATTRIBUTES
   ERPAttributes    AS DOT11_ERP_PHY_ATTRIBUTES
END UNION

' // Size = 1092 bytes
TYPE DOT11_PHY_ATTRIBUTES DWORD FILL
   Header                      AS NDIS_OBJECT_HEADER
   PhyType                     AS DWORD   ' DOT11_PHY_TYPE enum
   bHardwarePhyState           AS BYTE    ' BOOLEAN
   bSoftwarePhyState           AS BYTE    ' BOOLEAN
   bCFPollable                 AS BYTE    ' BOOLEAN
   uMPDUMaxLength              AS DWORD   ' ULONG
   TempType                    AS LONG    ' DOT11_TEMP_TYPE enum
   DiversitySupport            AS LONG    ' DOT11_DIVERSITY_SUPPORT
   DOT11_PHY_ATTRIBUTES_PhySpecificAttributes
   uNumberSupportedPowerLevels AS DWORD   ' ULONG
   TxPowerLevels(7)            AS DWORD   ' ULONG
   uNumDataRateMappingEntries  AS DWORD   ' ULONG
   DataRateMappingEntries(%DOT11_RATE_SET_MAX_LENGTH - 1) AS DOT11_DATA_RATE_MAPPING_ENTRY
   SupportedDataRatesValue     AS DOT11_SUPPORTED_DATA_RATES_VALUE_V2
   alignment__                 AS WORD
END TYPE

%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_OID_SUPPORTED  = &H1
%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_CERTIFIED      = &H2
%DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_RESERVED       = &HC

#IF %DEF(%NDIS_SUPPORT_NDIS6)
'typedef struct DOT11_EXTSTA_ATTRIBUTES DOT11_EXTSTA_ATTRIBUTES, * PDOT11_EXTSTA_ATTRIBUTES;
%DOT11_EXTSTA_ATTRIBUTES_REVISION_1 = 1
%DOT11_EXTSTA_ATTRIBUTES_REVISION_2 = 2

' // Size = 88 bytes
TYPE DOT11_EXTSTA_ATTRIBUTES DWORD FILL
   Header                                  AS NDIS_OBJECT_HEADER
   uScanSSIDListSize                       AS DWORD   ' ULONG
   uDesiredBSSIDListSize                   AS DWORD   ' ULONG
   uDesiredSSIDListSize                    AS DWORD   ' ULONG
   uExcludedMacAddressListSize             AS DWORD   ' ULONG
   uPrivacyExemptionListSize               AS DWORD   ' ULONG
   uKeyMappingTableSize                    AS DWORD   ' ULONG
   uDefaultKeyTableSize                    AS DWORD   ' ULONG
   uWEPKeyValueMaxLength                   AS DWORD   ' ULONG
   uPMKIDCacheSize                         AS DWORD   ' ULONG
   uMaxNumPerSTADefaultKeyTables           AS DWORD   ' ULONG
   bStrictlyOrderedServiceClassImplemented AS BYTE    ' BOOLEAN
   ' // Flags of the supported QoS protocols.
   ' // It is either 0 or combination of DOT11_QOS_PROTOCOL_FLAG_WMM
   ' // and/or DOT11_QOS_PROTOCOL_FLAG_11E
   ucSupportedQoSProtocolFlags             AS BYTE    ' UCHAR
   bSafeModeImplemented                    AS BYTE    ' BOOLEAN
   ' // Supported Country Strings
   uNumSupportedCountryOrRegionStrings     AS DWORD   ' ULONG
   pSupportedCountryOrRegionStrings        AS DOT11_COUNTRY_OR_REGION_STRING PTR   ' PDOT11_COUNTRY_OR_REGION_STRING
   ' // Infra Capabilities
   uInfraNumSupportedUcastAlgoPairs        AS DWORD   ' ULONG
   pInfraSupportedUcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR   ' PDOT11_AUTH_CIPHER_PAIR
   uInfraNumSupportedMcastAlgoPairs        AS DWORD   ' ULONG
   pInfraSupportedMcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR   ' PDOT11_AUTH_CIPHER_PAIR
   ' // Ad hoc Capabilities
   uAdhocNumSupportedUcastAlgoPairs        AS DWORD   ' ULONG
   pAdhocSupportedUcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR   ' PDOT11_AUTH_CIPHER_PAIR
   uAdhocNumSupportedMcastAlgoPairs        AS DWORD   ' ULONG
   pAdhocSupportedMcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR   ' PDOT11_AUTH_CIPHER_PAIR
END TYPE

#ENDIF ' // NDIS_SUPPORT_NDIS6

'#if (defined(_NDIS_) || defined(NDIS_WRAPPER)) // To avoid build break since NDIS_PACKET isn't defined for user mode app.

%DOT11_SEND_CONTEXT_REVISION_1 = 1

#IF %DEF(%NDIS_SUPPORT_NDIS6)

'// Send path extension for NativeWiFi NDIS 6.0 miniport driver
' // Size = 52 bytes
TYPE DOT11_SEND_CONTEXT DWORD FILL
   Header                  AS NDIS_OBJECT_HEADER
   pvReserved              AS DWORD   ' PVOID
   uFlags                  AS DWORD   ' ULONG
   uPSLifetime             AS DWORD   ' ULONG
   uDelayedSleepValue      AS DWORD   ' ULONG
   ucTXDataRates(7)        AS BYTE    ' UCHAR
   bIndicateAssociatedACKs AS BYTE    ' BOOLEAN
   bIndicateTXStatus       AS BYTE    ' BOOLEAN
   ucPriority              AS BYTE    ' UCHAR
   bDontFragment           AS BYTE    ' BOOLEAN
   dwExtendedStatus        AS DWORD   ' ULONG
   hIntegrityOffload       AS DWORD   ' HANDLE
   hWEPOffload             AS DWORD   ' HANDLE
   ucWPAMSDUPriority       AS BYTE    ' UCHAR
   ucNumOfRWsOnPeer        AS BYTE    ' UCHAR
   usAID                   AS BYTE    ' USHORT
   pDot11PerMSDUCounters   AS DOT11_PER_MSDU_COUNTERS PTR   ' PDOT11_PER_MSDU_COUNTERS
END TYPE

'#define DOT11_SEND_CONTEXT_SIZE             \
'       ((sizeof(DOT11_SEND_CONTEXT) +      \
'         MEMORY_ALLOCATION_ALIGNMENT - 1) &  \
'        ~(MEMORY_ALLOCATION_ALIGNMENT-1))

' // Send path extension for NativeWiFi NDIS 5.1 miniport driver
' // Size = 68 bytes
TYPE DOT11_SEND_EXTENSION_INFO DWORD FILL
   uVersion                AS DWORD   ' ULONG
   Header                  AS NDIS_OBJECT_HEADER
   pvReserved              AS DWORD   ' PVOID
   uFlags                  AS DWORD   ' ULONG
   uPSLifetime             AS DWORD   ' ULONG
   uDelayedSleepValue      AS DWORD   ' ULONG
   ucTXDataRates(7)        AS BYTE    ' UCHAR
   bIndicateAssociatedACKs AS BYTE    ' BOOLEAN
   bIndicateTXStatus       AS BYTE    ' BOOLEAN
   ucPriority              AS BYTE    ' UCHAR
   bDontFragment           AS BYTE    ' BOOLEAN
   dwExtendedStatus        AS DWORD   ' ULONG
   hIntegrityOffload       AS DWORD   ' HANDLE
   hWEPOffload             AS DWORD   ' HANDLE
   ucWPAMSDUPriority       AS BYTE    ' UCHAR
   ucNumOfRWsOnPeer        AS BYTE    ' UCHAR
   usAID                   AS WORD    ' USHORT
   pDot11PerMSDUCounters   AS DOT11_PER_MSDU_COUNTERS PTR   ' PDOT11_PER_MSDU_COUNTERS
   usNumberOfFragments     AS WORD    ' USHORT
   Dot11FragmentDescriptors(0) AS DOT11_FRAGMENT_DESCRIPTOR
END TYPE

' enum _DOT11_ACK_POLICY
%dot11_ack_policy_none               = 0
%dot11_ack_policy_acknowledge        = 1
%dot11_ack_policy_do_not_acknowledge = 2

' // Send path extension for NativeWiFi NDIS 5.1 miniport driver
' // Size = 6 bytes
TYPE DOT11_SEND_EXTENSION_INFO_V2 WORD FILL
   ucQoSPriority               AS BIT  * 4 IN BYTE   ' UCHAR
   ucAckPolicy                 AS BIT  * 4
   usExtendedTXDataRatesOffset AS WORD               ' USHORT
   ucNumOfExtendedTXDataRates  AS BYTE               ' UCHAR
   ucBuffer(0)                 AS BYTE               ' UCHAR
END TYPE

'//
'// Miniport Receive Path Extension
'//

'// Recv path extension for NativeWiFi NDIS 6.0 miniport driver
%DOT11_RECV_CONTEXT_REVISION_1 = 1

' // Size = 72 bytes
TYPE DOT11_RECV_CONTEXT BYTE
   Header                  AS NDIS_OBJECT_HEADER
   pvReserved              AS DWORD                ' PVOID
   dot11PhyType            AS DWORD                ' DOT11_PHY_TYPE
   uChCenterFrequency      AS DWORD                ' ULONG
   lRSSI                   AS LONG                 ' LONG
   uRSSI                   AS DWORD                ' ULONG
   ucPriority              AS BYTE                 ' UCHAR
   ucDataRate              AS BYTE                 ' UCHAR
   ucPeerMacAddress(5)     AS BYTE                 ' UCHAR[6]
   dwExtendedStatus        AS DWORD                ' ULONG
   hWEPOffloadContext      AS DWORD                ' HANDLE
   hAuthOffloadContext     AS DWORD                ' HANDLE
   usWEPAppliedMask        AS WORD                 ' USHORT
   usWPAMSDUPriority       AS WORD                 ' USHORT
   dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
   usDot11LeftRWBitMap     AS WORD                 ' USHORT
   alignment__             AS WORD
   dot11HighestIV48Counter AS DOT11_IV48_COUNTER
   usDot11RightRWBitMap    AS WORD                 ' USHORT
   usNumberOfMPDUsReceived AS WORD                 ' USHORT
END TYPE

'#define DOT11_RECV_CONTEXT_SIZE             \
'       ((sizeof(DOT11_RECV_CONTEXT) + \
'         MEMORY_ALLOCATION_ALIGNMENT - 1) &  \
'        ~(MEMORY_ALLOCATION_ALIGNMENT-1))

#ELSE

'// Recv path extension for NativeWiFi NDIS 5.1 miniport driver
' // Size = 88 bytes
TYPE DOT11_RECV_EXTENSION_INFO BYTE
   uVersion                AS DWORD   ' ULONG
   pvReserved              AS DWORD   ' PVOID
   dot11PhyType            AS DWORD   ' DOT11_PHY_TYPE
   uChCenterFrequency      AS DWORD   ' ULONG
   lRSSI                   AS LONG    ' LONG
   lRSSIMin                AS LONG    ' LONG
   lRSSIMax                AS LONG    ' LONG
   uRSSI                   AS DWORD   ' ULONG
   ucPriority              AS BYTE    ' UCHAR
   ucDataRate              AS BYTE    ' UCHAR
   ucPeerMacAddress(5)     AS BYTE    ' UCHAR
   dwExtendedStatus        AS DWORD   ' ULONG
   hWEPOffloadContext      AS DWORD   ' HANDLE
   hAuthOffloadContext     AS DWORD   ' HANDLE
   usWEPAppliedMask        AS WORD    ' USHORT
   usWPAMSDUPriority       AS WORD    ' USHORT
   dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
   usDot11LeftRWBitMap     AS WORD    ' USHORT
   alignment1__            AS WORD
   dot11HighestIV48Counter AS DOT11_IV48_COUNTER
   usDot11RightRWBitMap    AS WORD    ' USHORT
   usNumberOfMPDUsReceived AS WORD    ' USHORT
   usNumberOfFragments     AS WORD    ' USHORT
   alignment2__            AS WORD
   ' // PNDIS_PACKET pNdisPackets[1]; // Must be the last field.
   pNdisPackets(0)         AS DWORD   ' PVOID // Must be the last field.
END TYPE

' // Size = 80 bytes
TYPE DOT11_RECV_EXTENSION_INFO_V2 BYTE
   uVersion                AS DWORD   ' ULONG
   pvReserved              AS DWORD   ' PVOID
   dot11PhyType            AS DWORD   ' DOT11_PHY_TYPE enum
   uChCenterFrequency      AS DWORD   ' ULONG
   lRSSI                   AS LONG    ' LONG
   uRSSI                   AS DWORD   ' ULONG
   ucPriority              AS BYTE    ' UCHAR
   ucDataRate              AS BYTE    ' UCHAR
   ucPeerMacAddress(5)     AS BYTE    ' UCHAR
   dwExtendedStatus        AS DWORD   ' ULONG
   hWEPOffloadContext      AS DWORD   ' HANDLE
   hAuthOffloadContext     AS DWORD   ' HANDLE
   usWEPAppliedMask        AS WORD    ' USHORT
   usWPAMSDUPriority       AS WORD    ' USHORT
   dot11LowestIV48Counter  AS DOT11_IV48_COUNTER
   usDot11LeftRWBitMap     AS WORD    ' USHORT
   alignment1__            AS WORD
   dot11HighestIV48Counter AS DOT11_IV48_COUNTER
   usDot11RightRWBitMap    AS WORD    ' USHORT
   usNumberOfMPDUsReceived AS WORD    ' USHORT
   usNumberOfFragments     AS WORD    ' USHORT
   alignment2__            AS WORD
   ' // PNDIS_PACKET pNdisPackets[1]; // Must be the last field.
   pNdisPackets(0)         AS DWORD    ' PVOID // Must be the last field.
END TYPE

#ENDIF   '  // NDIS_SUPPORT_NDIS6
'#endif // NDIS_MINIPORT_DRIVER

'//
'// 802.11 Status Codes
'//

%DOT11_STATUS_SUCCESS                        = &H00000001???
%DOT11_STATUS_RETRY_LIMIT_EXCEEDED           = &H00000002???
%DOT11_STATUS_UNSUPPORTED_PRIORITY           = &H00000004???
%DOT11_STATUS_UNSUPPORTED_SERVICE_CLASS      = &H00000008???
%DOT11_STATUS_UNAVAILABLE_PRIORITY           = &H00000010???
%DOT11_STATUS_UNAVAILABLE_SERVICE_CLASS      = &H00000020???
%DOT11_STATUS_XMIT_MSDU_TIMER_EXPIRED        = &H00000040???
%DOT11_STATUS_UNAVAILABLE_BSS                = &H00000080???
%DOT11_STATUS_EXCESSIVE_DATA_LENGTH          = &H00000100???
%DOT11_STATUS_ENCRYPTION_FAILED              = &H00000200???
%DOT11_STATUS_WEP_KEY_UNAVAILABLE            = &H00000400???
%DOT11_STATUS_ICV_VERIFIED                   = &H00000800???
%DOT11_STATUS_PACKET_REASSEMBLED             = &H00001000???
%DOT11_STATUS_PACKET_NOT_REASSEMBLED         = &H00002000???
%DOT11_STATUS_GENERATE_AUTH_FAILED           = &H00004000???
%DOT11_STATUS_AUTH_NOT_VERIFIED              = &H00008000???
%DOT11_STATUS_AUTH_VERIFIED                  = &H00010000???
%DOT11_STATUS_AUTH_FAILED                    = &H00020000???
%DOT11_STATUS_PS_LIFETIME_EXPIRED            = &H00040000???

'//
'// Flags for NDIS_STATUS_MEDIA_SPECIFIC_INDICATION
'//
' // Size = 8 bytes
TYPE DOT11_STATUS_INDICATION DWORD
   uStatusType AS DWORD  ' ULONG
   ndisStatus  AS LONG   ' NDIS_STATUS
END TYPE

%DOT11_STATUS_RESET_CONFIRM           = 4

'// #ifndef NDIS_SUPPORT_NDIS6
%DOT11_STATUS_SCAN_CONFIRM            = 1
%DOT11_STATUS_JOIN_CONFIRM            = 2
%DOT11_STATUS_START_CONFIRM           = 3
%DOT11_STATUS_AP_JOIN_CONFIRM         = 5
%DOT11_STATUS_MPDU_MAX_LENGTH_CHANGED = 6
'// #endif  // NDIS_SUPPORT_NDIS6

#IF %DEF(%NDIS_SUPPORT_NDIS6)
%DOT11_MPDU_MAX_LENGTH_INDICATION_REVISION_1 = 1
' // Size = 16 bytes
TYPE DOT11_MPDU_MAX_LENGTH_INDICATION DWORD
   Header         AS NDIS_OBJECT_HEADER
   uPhyId         AS DWORD   ' ULONG
   uMPDUMaxLength AS DWORD   ' ULONG
END TYPE
#ELSE
' // Size = 16 bytes
TYPE DOT11_MPDU_MAX_LENGTH_INDICATION DWORD
   uStatusType    AS DWORD   ' ULONG
   uVersion       AS DWORD   ' ULONG
   uPhyId         AS DWORD   ' ULONG
   uMPDUMaxLength AS DWORD   ' ULONG
END TYPE
#ENDIF '  // NDIS_SUPPORT_NDIS6

%DOT11_ASSOCIATION_START_PARAMETERS_REVISION_1 = 1

' // Size = 56 bytes
TYPE DOT11_ASSOCIATION_START_PARAMETERS DWORD
   Header         AS NDIS_OBJECT_HEADER
   MacAddr        AS DOT11_MAC_ADDRESS
   SSID           AS DOT11_SSID
   uIHVDataOffset AS DWORD                ' ULONG
   uIHVDataSize   AS DWORD                ' ULONG
END TYPE

%DOT11_ENCAP_RFC_1042    = 1
%DOT11_ENCAP_802_1H      = 2

' // Size = 4 bytes
TYPE DOT11_ENCAP_ENTRY WORD
   usEtherType AS WORD   ' USHORT
   usEncapType AS WORD   ' USHORT // either DOT11_ENCAP_RFC_1042 or DOT11_ENCAP_802_1H
END TYPE

' enum DOT11_DS_INFO
%DOT11_DS_CHANGED   = 0
%DOT11_DS_UNCHANGED = 1
%DOT11_DS_UNKNOWN   = 2

'/////////////////////////////////////////////
'// Definitions of association status codes
'//
'typedef ULONG DOT11_ASSOC_STATUS;

'// The association is successful
%DOT11_ASSOC_STATUS_SUCCESS                          = 0

'// Generic association failure
%DOT11_ASSOC_STATUS_FAILURE                          = &H00000001???

'// The association fails because the peer is not responding.
'// Scenarios:
'//    1. the peer doesn't respond to 802.11 authentication frames or
'//       802.11 association request frames or probe request frames.
'//    2. the NIC hasn't received beacon from the peer for substantial
'//       amount of time. The timeout value here is NIC specific.
'//    3. any other cases in which NIC determines that the peer is not
'//       responsive.
%DOT11_ASSOC_STATUS_UNREACHABLE                      = &H00000002???

'// The association fails because the radio is turned off
%DOT11_ASSOC_STATUS_RADIO_OFF                        = &H00000003???

'// The association fails because the PHY is disabled. Here the PHY
'// entity becomes unavailable to the OS. But the radio itself is not
'// necessarily turned off.
%DOT11_ASSOC_STATUS_PHY_DISABLED                     = &H00000004???

'// The association is cancelled (for example, the NIC is reset)
%DOT11_ASSOC_STATUS_CANCELLED                        = &H00000005???

'// The connection fails because all the candidate AP has been tried
'// and none of the attempts succeeds.
%DOT11_ASSOC_STATUS_CANDIDATE_LIST_EXHAUSTED         = &H00000006???

'// The current association is disassociated as requested by the OS
'// (through either a OID_DOT11_RESET_REQUEST or OID_DOT11_DISCONNECT request)
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_OS              = &H00000007???

'// The current association is disassociated because the NIC roams
'// to new AP.
'// This error code is used for indicating the implicit dissassociation
'// done by the nwifi.sys. Miniport driver usually doesn't generate
'// this error code (since the disassociation is automatically done
'// by the nwifi.sys).
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_ROAMING         = &H00000008???

'// The current association is disassocated because the NIC is reset
%DOT11_ASSOC_STATUS_DISASSOCIATED_BY_RESET           = &H00000009???

'// The current association is disassocated because the NIC is reset
%DOT11_ASSOC_STATUS_SYSTEM_ERROR                     = &H0000000A???

'// Roaming reason: find a better AP
%DOT11_ASSOC_STATUS_ROAMING_BETTER_AP_FOUND          = &H0000000B???

'// Roaming reason: the association to the current BSS is lost
%DOT11_ASSOC_STATUS_ROAMING_ASSOCIATION_LOST         = &H0000000C???

'// Roaming reason: adhoc roaming (network Coalescing)
%DOT11_ASSOC_STATUS_ROAMING_ADHOC                    = &H0000000D???

'// The new association fails or the current association is disassocated
'// because the NIC receives an 802.11 de-authentication frame from the
'// peer. The lowest 16-bits are the reason code (2-byte) copied from
'// the 802.11 DeAuthentication frame.
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED             = &H00010000???
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED_START       = %DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED
%DOT11_ASSOC_STATUS_PEER_DEAUTHENTICATED_END         = &H0001ffff???

'// The new association fails or the current association is disassocated
'// because the NIC receives an 802.11 disassociation frame from the
'// peer. The lowest 16-bits are the reason code (2-byte) copied from
'// the 802.11 DisAssociation frame.
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED               = &H00020000???
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED_START         = %DOT11_ASSOC_STATUS_PEER_DISASSOCIATED
%DOT11_ASSOC_STATUS_PEER_DISASSOCIATED_END           = &H0002ffff???

%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE             = &H00030000???
%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE_START       = %DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE
%DOT11_ASSOC_STATUS_ASSOCIATION_RESPONSE_END         = &H0003ffff???

'// The mask for extracting 802.11 deauthentication and disassociation
'// reason code.
%DOT11_ASSOC_STATUS_REASON_CODE_MASK                 = &Hffff???

'// Define the range of IHV specific association status codes
%DOT11_ASSOC_STATUS_IHV_START                        = &H80000000???
%DOT11_ASSOC_STATUS_IHV_END                          = &Hffffffff???

%DOT11_ASSOCIATION_COMPLETION_PARAMETERS_REVISION_1 = 1

' // Size = 88 bytes
TYPE DOT11_ASSOCIATION_COMPLETION_PARAMETERS DWORD FILL
   Header                AS    NDIS_OBJECT_HEADER
   MacAddr               AS    DOT11_MAC_ADDRESS
   uStatus               AS    DWORD   ' DOT11_ASSOC_STATUS
   bReAssocReq           AS    BYTE    ' BOOLEAN
   bReAssocResp          AS    BYTE    ' BOOLEAN
   uAssocReqOffset       AS    DWORD   ' ULONG
   uAssocReqSize         AS    DWORD   ' ULONG
   uAssocRespOffset      AS    DWORD   ' ULONG
   uAssocRespSize        AS    DWORD   ' ULONG
   uBeaconOffset         AS    DWORD   ' ULONG
   uBeaconSize           AS    DWORD   ' ULONG
   uIHVDataOffset        AS    DWORD   ' ULONG
   uIHVDataSize          AS    DWORD   ' ULONG
   ' // The following fields are applicable for successful association.
   ' // For association failure, they must be zero-ed out.
   AuthAlgo              AS    LONG    ' DOT11_AUTH_ALGORITHM
   UnicastCipher         AS    LONG    ' DOT11_CIPHER_ALGORITHM
   MulticastCipher       AS    LONG    ' DOT11_CIPHER_ALGORITHM
   uActivePhyListOffset  AS    DWORD   ' ULONG
   uActivePhyListSize    AS    DWORD   ' ULONG
   bFourAddressSupported AS    BYTE    ' BOOLEAN
   bPortAuthorized       AS    BYTE    ' BOOLEAN
   ' // The QoS protocol which is used in this association.
   ' // It is zero or combination of DOT11_QOS_PROTOCOL_FLAG_WMM and/or DOT11_QOS_PROTOCOL_FLAG_11E
   ucActiveQoSProtocol   AS    BYTE    ' UCHAR
   DSInfo                AS    LONG    ' DOT11_DS_INFO
   uEncapTableOffset     AS    DWORD   ' ULONG
   uEncapTableSize       AS    DWORD   ' ULONG
END TYPE

%DOT11_CONNECTION_START_PARAMETERS_REVISION_1 = 1

' // Size = 52 bytes
TYPE DOT11_CONNECTION_START_PARAMETERS DWORD FILL
   Header     AS NDIS_OBJECT_HEADER
   BSSType    AS LONG                 ' DOT11_BSS_TYPE
   AdhocBSSID AS DOT11_MAC_ADDRESS    ' // applicable to adhoc mode only
   AdhocSSID  AS DOT11_SSID           ' // applicable to adhoc mode only
END TYPE

'// For uStatus in DOT11_CONNECTION_COMPLETION_PARAMETERS and DOT11_ROAMING_COMPLETION_PARAMETERS
%DOT11_CONNECTION_STATUS_SUCCESS                  = %DOT11_ASSOC_STATUS_SUCCESS
%DOT11_CONNECTION_STATUS_FAILURE                  = %DOT11_ASSOC_STATUS_FAILURE
%DOT11_CONNECTION_STATUS_CANDIDATE_LIST_EXHAUSTED = %DOT11_ASSOC_STATUS_CANDIDATE_LIST_EXHAUSTED
%DOT11_CONNECTION_STATUS_PHY_POWER_DOWN           = %DOT11_ASSOC_STATUS_RADIO_OFF
%DOT11_CONNECTION_STATUS_CANCELLED                = %DOT11_ASSOC_STATUS_CANCELLED
%DOT11_CONNECTION_STATUS_IHV_START                = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_CONNECTION_STATUS_IHV_END                  = %DOT11_ASSOC_STATUS_IHV_END

%DOT11_CONNECTION_COMPLETION_PARAMETERS_REVISION_1 = 1

' // Size = 8 bytes
TYPE DOT11_CONNECTION_COMPLETION_PARAMETERS DWORD
   Header  AS NDIS_OBJECT_HEADER
   uStatus AS LONG   ' DOT11_ASSOC_STATUS enum // DOT11_CONNECTION_STATUS_XXXX
END TYPE

%DOT11_ROAMING_REASON_BETTER_AP_FOUND  = %DOT11_ASSOC_STATUS_ROAMING_BETTER_AP_FOUND
%DOT11_ROAMING_REASON_ASSOCIATION_LOST = %DOT11_ASSOC_STATUS_ROAMING_ASSOCIATION_LOST
%DOT11_ROAMING_REASON_ADHOC            = %DOT11_ASSOC_STATUS_ROAMING_ADHOC
%DOT11_ROAMING_REASON_IHV_START        = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_ROAMING_REASON_IHV_END          = %DOT11_ASSOC_STATUS_IHV_END

%DOT11_ROAMING_START_PARAMETERS_REVISION_1 = 1

' // Size = 8 bytes
TYPE DOT11_ROAMING_START_PARAMETERS DWORD FILL
   Header         AS NDIS_OBJECT_HEADER
   AdhocBSSID     AS DOT11_MAC_ADDRESS    ' // applicable to adhoc mode only
   AdhocSSID      AS DOT11_SSID           ' // applicable to adhoc mode only
   uRoamingReason AS DWORD                ' DOT11_ASSOC_STATUS
END TYPE

%DOT11_ROAMING_COMPLETION_PARAMETERS_REVISION_1 = 1

' // Size = 8 bytes
TYPE DOT11_ROAMING_COMPLETION_PARAMETERS DWORD FILL
   Header  AS NDIS_OBJECT_HEADER
   uStatus AS LONG   ' DOT11_ASSOC_STATUS  // DOT11_CONNECTION_STATUS_XXXX
END TYPE

'// Disassociation Reason Code
%DOT11_DISASSOC_REASON_OS               = %DOT11_ASSOC_STATUS_DISASSOCIATED_BY_OS
%DOT11_DISASSOC_REASON_PEER_UNREACHABLE = %DOT11_ASSOC_STATUS_UNREACHABLE
%DOT11_DISASSOC_REASON_RADIO_OFF        = %DOT11_ASSOC_STATUS_RADIO_OFF
%DOT11_DISASSOC_REASON_PHY_DISABLED     = %DOT11_ASSOC_STATUS_PHY_DISABLED
%DOT11_DISASSOC_REASON_IHV_START        = %DOT11_ASSOC_STATUS_IHV_START
%DOT11_DISASSOC_REASON_IHV_END          = %DOT11_ASSOC_STATUS_IHV_END

%DOT11_DISASSOCIATION_PARAMETERS_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_DISASSOCIATION_PARAMETERS DWORD FILL
   Header         AS NDIS_OBJECT_HEADER
   MacAddr        AS DOT11_MAC_ADDRESS
   uReason        AS DWORD   ' DOT11_ASSOC_STATUS
   uIHVDataOffset AS DWORD   ' ULONG
   uIHVDataSize   AS DWORD   ' ULONG
END TYPE

%DOT11_TKIPMIC_FAILURE_PARAMETERS_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_TKIPMIC_FAILURE_PARAMETERS DWORD FILL
   Header             AS NDIS_OBJECT_HEADER
   bDefaultKeyFailure AS BYTE                 ' BOOLEAN
   uKeyIndex          AS DWORD                ' ULONG
   PeerMac            AS DOT11_MAC_ADDRESS
   alignment__        AS WORD
END TYPE

%DOT11_PMKID_CANDIDATE_LIST_PARAMETERS_REVISION_1 = 1

' // Size = 12 bytes
TYPE DOT11_PMKID_CANDIDATE_LIST_PARAMETERS DWORD
   Header               AS NDIS_OBJECT_HEADER
   uCandidateListSize   AS DWORD   ' ULONG
   uCandidateListOffset AS DWORD   ' ULONG
END TYPE

%DOT11_PMKID_CANDIDATE_PREAUTH_ENABLED = &H00000001???

' // Size = 12 bytes
TYPE DOT11_BSSID_CANDIDATE DWORD FILL
   BSSID  AS DOT11_MAC_ADDRESS
   uFlags AS DWORD   ' ULONG
END TYPE

%DOT11_PHY_STATE_PARAMETERS_REVISION_1 = 1

' // Size = 12 bytes
TYPE DOT11_PHY_STATE_PARAMETERS BYTE
   Header            AS NDIS_OBJECT_HEADER
   uPhyId            AS DWORD   ' ULONG
   bHardwarePhyState AS BYTE    ' BOOLEAN
   bSoftwarePhyState AS BYTE    ' BOOLEAN
   alignment__       AS WORD
END TYPE

' // Size = 7 bytes
TYPE DOT11_LINK_QUALITY_ENTRY BYTE
   PeerMacAddr   AS DOT11_MAC_ADDRESS
   ucLinkQuality AS BYTE   ' UCHAR
END TYPE

%DOT11_LINK_QUALITY_PARAMETERS_REVISION_1 = 1

' // Size = 12 bytes
TYPE DOT11_LINK_QUALITY_PARAMETERS DWORD
   Header                 AS NDIS_OBJECT_HEADER
   uLinkQualityListSize   AS DWORD   ' ULONG
   uLinkQualityListOffset AS DWORD   ' ULONG
END TYPE


'// Send OOB data for ExtSTA mode
%DOT11_EXTSTA_SEND_CONTEXT_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_EXTSTA_SEND_CONTEXT DWORD
   Header                AS NDIS_OBJECT_HEADER
   usExemptionActionType AS WORD    ' USHORT
   uPhyId                AS DWORD   ' ULONG
   uDelayedSleepValue    AS DWORD   ' ULONG
   pvMediaSpecificInfo   AS DWORD   ' PVOID
   uSendFlags            AS DWORD   ' ULONG // reserved field for safe mode wireless
END TYPE

'// Recv OOB data for ExtSTA mode
%DOT11_RECV_FLAG_RAW_PACKET             = &H00000001???
%DOT11_RECV_FLAG_RAW_PACKET_FCS_FAILURE = &H00000002???
%DOT11_RECV_FLAG_RAW_PACKET_TIMESTAMP   = &H00000004???

%DOT11_EXTSTA_RECV_CONTEXT_REVISION_1 = 1

' // Size = 48 bytes
TYPE DOT11_EXTSTA_RECV_CONTEXT   ' Must be 8 byte aligned
   Header                  AS NDIS_OBJECT_HEADER
   uReceiveFlags           AS DWORD   ' ULONG
   uPhyId                  AS DWORD   ' ULONG
   uChCenterFrequency      AS DWORD   ' ULONG
   usNumberOfMPDUsReceived AS WORD    ' USHORT
   alignment1__            AS WORD
   lRSSI                   AS LONG    ' LONG
   ucDataRate              AS BYTE    ' UCHAR
   alignment2__(2)         AS BYTE
   uSizeMediaSpecificInfo  AS DWORD   ' ULONG
   pvMediaSpecificInfo     AS DWORD   ' PVOID
   alignment3__            AS DWORD
   ullTimestamp            AS QUAD    ' ULONGLONG
END TYPE

'//
'// Private 802.11 OIDs: this should be the last section
'//
'// We reserve 1024 entries for real DOT11 OIDs
'//

%OID_DOT11_PRIVATE_OIDS_START = (%OID_DOT11_NDIS_START + 1024)
%OID_DOT11_CURRENT_ADDRESS    = (%OID_DOT11_PRIVATE_OIDS_START + 2)
' // DOT11_MAC_ADDRESS
%OID_DOT11_PERMANENT_ADDRESS  = (%OID_DOT11_PRIVATE_OIDS_START + 3)
' // DOT11_MAC_ADDRESS
%OID_DOT11_MULTICAST_LIST     = (%OID_DOT11_PRIVATE_OIDS_START + 4)
' // OID_802_3_MULTICAST_LIST
%OID_DOT11_MAXIMUM_LIST_SIZE  = (%OID_DOT11_PRIVATE_OIDS_START + 5)


'// GUIDs for WMI

'#define DEFINE_NWF_GUID(name,ord)   \
'    DEFINE_GUID(name, 0x6cb9a43e+(ord), 0xc45f, 0x4039, 0x9f, 0xe6, 0xd0, 0x8c, 0xb0, 0x57, 0x18, 0x4c)

$GUID_NWF_OFFLOAD_CAPABILITY = GUID$("{6CB9A43E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_OFFLOAD_CAPABILITY = GUID$("{6CB9A43F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WEP_OFFLOAD = GUID$("{6CB9A440-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WEP_UPLOAD = GUID$("{6CB9A441-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DEFAULT_WEP_OFFLOAD = GUID$("{6CB9A442-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DEFAULT_WEP_UPLOAD = GUID$("{6CB9A443-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MPDU_MAX_LENGTH = GUID$("{6CB9A444-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_OPERATION_MODE_CAPABILITY = GUID$("{6CB9A445-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_OPERATION_MODE = GUID$("{6CB9A446-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_PACKET_FILTER = GUID$("{6CB9A447-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ATIM_WINDOW = GUID$("{6CB9A448-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SCAN_REQUEST = GUID$("{6CB9A449-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_PHY_TYPE = GUID$("{6CB9A44A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_JOIN_REQUEST = GUID$("{6CB9A44B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_START_REQUEST = GUID$("{6CB9A44C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_UPDATE_IE = GUID$("{6CB9A44D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RESET_REQUEST = GUID$("{6CB9A44E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_NIC_POWER_STATE = GUID$("{6CB9A44F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_OPTIONAL_CAPABILITY = GUID$("{6CB9A450-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_OPTIONAL_CAPABILITY = GUID$("{6CB9A451-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_STATION_ID = GUID$("{6CB9A452-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MEDIUM_OCCUPANCY_LIMIT = GUID$("{6CB9A453-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CF_POLLABLE = GUID$("{6CB9A454-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CFP_PERIOD = GUID$("{6CB9A455-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CFP_MAX_DURATION = GUID$("{6CB9A456-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_POWER_MGMT_MODE = GUID$("{6CB9A457-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_OPERATIONAL_RATE_SET = GUID$("{6CB9A458-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_BEACON_PERIOD = GUID$("{6CB9A459-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DTIM_PERIOD = GUID$("{6CB9A45A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WEP_ICV_ERROR_COUNT = GUID$("{6CB9A45B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAC_ADDRESS = GUID$("{6CB9A45C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RTS_THRESHOLD = GUID$("{6CB9A45D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SHORT_RETRY_LIMIT = GUID$("{6CB9A45E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_LONG_RETRY_LIMIT = GUID$("{6CB9A45F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_FRAGMENTATION_THRESHOLD = GUID$("{6CB9A460-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAX_TRANSMIT_MSDU_LIFETIME = GUID$("{6CB9A461-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAX_RECEIVE_LIFETIME = GUID$("{6CB9A462-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_COUNTERS_ENTRY = GUID$("{6CB9A463-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_PHY_TYPES = GUID$("{6CB9A464-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_REG_DOMAIN = GUID$("{6CB9A465-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_TEMP_TYPE = GUID$("{6CB9A466-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_TX_ANTENNA = GUID$("{6CB9A467-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DIVERSITY_SUPPORT = GUID$("{6CB9A468-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_RX_ANTENNA = GUID$("{6CB9A469-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_POWER_LEVELS = GUID$("{6CB9A46A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_TX_POWER_LEVEL = GUID$("{6CB9A46B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HOP_TIME = GUID$("{6CB9A46C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_CHANNEL_NUMBER = GUID$("{6CB9A46D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAX_DWELL_TIME = GUID$("{6CB9A46E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_DWELL_TIME = GUID$("{6CB9A46F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_SET = GUID$("{6CB9A470-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_PATTERN = GUID$("{6CB9A471-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_INDEX = GUID$("{6CB9A472-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_CHANNEL = GUID$("{6CB9A473-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CCA_MODE_SUPPORTED = GUID$("{6CB9A474-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_CCA_MODE = GUID$("{6CB9A475-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ED_THRESHOLD = GUID$("{6CB9A476-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CCA_WATCHDOG_TIMER_MAX = GUID$("{6CB9A477-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CCA_WATCHDOG_COUNT_MAX = GUID$("{6CB9A478-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CCA_WATCHDOG_TIMER_MIN = GUID$("{6CB9A479-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CCA_WATCHDOG_COUNT_MIN = GUID$("{6CB9A47A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_REG_DOMAINS_SUPPORT_VALUE = GUID$("{6CB9A47B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_TX_ANTENNA = GUID$("{6CB9A47C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_RX_ANTENNA = GUID$("{6CB9A47D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DIVERSITY_SELECTION_RX = GUID$("{6CB9A47E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_DATA_RATES_VALUE = GUID$("{6CB9A47F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_FREQUENCY = GUID$("{6CB9A480-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_TI_THRESHOLD = GUID$("{6CB9A481-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_FREQUENCY_BANDS_SUPPORTED = GUID$("{6CB9A482-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SHORT_PREAMBLE_OPTION_IMPLEMENTED = GUID$("{6CB9A483-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PBCC_OPTION_IMPLEMENTED = GUID$("{6CB9A484-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CHANNEL_AGILITY_PRESENT = GUID$("{6CB9A485-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CHANNEL_AGILITY_ENABLED = GUID$("{6CB9A486-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HR_CCA_MODE_SUPPORTED = GUID$("{6CB9A487-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED = GUID$("{6CB9A488-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MULTI_DOMAIN_CAPABILITY_ENABLED = GUID$("{6CB9A489-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_COUNTRY_STRING = GUID$("{6CB9A48A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MULTI_DOMAIN_CAPABILITY = GUID$("{6CB9A48B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EHCC_PRIME_RADIX = GUID$("{6CB9A48C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EHCC_NUMBER_OF_CHANNELS_FAMILY_INDEX = GUID$("{6CB9A48D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EHCC_CAPABILITY_IMPLEMENTED = GUID$("{6CB9A48E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EHCC_CAPABILITY_ENABLED = GUID$("{6CB9A48F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HOP_ALGORITHM_ADOPTED = GUID$("{6CB9A490-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RANDOM_TABLE_FLAG = GUID$("{6CB9A491-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_NUMBER_OF_HOPPING_SETS = GUID$("{6CB9A492-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HOP_MODULUS = GUID$("{6CB9A493-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HOP_OFFSET = GUID$("{6CB9A494-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HOPPING_PATTERN = GUID$("{6CB9A495-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RANDOM_TABLE_FIELD_NUMBER = GUID$("{6CB9A496-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WPA_TSC = GUID$("{6CB9A497-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RSSI_RANGE = GUID$("{6CB9A498-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RF_USAGE = GUID$("{6CB9A499-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_NIC_SPECIFIC_EXTENSION = GUID$("{6CB9A49A-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_AP_JOIN_REQUEST = GUID$("{6CB9A49B-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ERP_PBCC_OPTION_IMPLEMENTED = GUID$("{6CB9A49C-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ERP_PBCC_OPTION_ENABLED = GUID$("{6CB9A49D-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DSSS_OFDM_OPTION_IMPLEMENTED = GUID$("{6CB9A49E-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DSSS_OFDM_OPTION_ENABLED = GUID$("{6CB9A49F-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SHORT_SLOT_TIME_OPTION_IMPLEMENTED = GUID$("{6CB9A4A0-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SHORT_SLOT_TIME_OPTION_ENABLED = GUID$("{6CB9A4A1-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAX_MAC_ADDRESS_STATES = GUID$("{6CB9A4A2-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_RECV_SENSITIVITY_LIST = GUID$("{6CB9A4A3-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WME_IMPLEMENTED = GUID$("{6CB9A4A4-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WME_ENABLED = GUID$("{6CB9A4A5-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WME_AC_PARAMETERS = GUID$("{6CB9A4A6-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_WME_UPDATE_IE = GUID$("{6CB9A4A7-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_QOS_TX_QUEUES_SUPPORTED = GUID$("{6CB9A4A8-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_QOS_TX_DURATION = GUID$("{6CB9A4A9-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_QOS_TX_MEDIUM_TIME = GUID$("{6CB9A4AA-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_OFDM_FREQUENCY_LIST = GUID$("{6CB9A4AB-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_DSSS_CHANNEL_LIST = GUID$("{6CB9A4AC-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_AUTO_CONFIG_ENABLED = GUID$("{6CB9A4B6-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ENUM_BSS_LIST = GUID$("{6CB9A4B7-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_FLUSH_BSS_LIST = GUID$("{6CB9A4B8-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_POWER_MGMT_REQUEST = GUID$("{6CB9A4B9-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DESIRED_SSID_LIST = GUID$("{6CB9A4BA-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EXCLUDED_MAC_ADDRESS_LIST = GUID$("{6CB9A4BB-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DESIRED_BSSID_LIST = GUID$("{6CB9A4BC-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DESIRED_BSS_TYPE = GUID$("{6CB9A4BD-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PMKID_LIST = GUID$("{6CB9A4BE-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CONNECT_REQUEST = GUID$("{6CB9A4BF-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EXCLUDE_UNENCRYPTED = GUID$("{6CB9A4C0-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_STATISTICS = GUID$("{6CB9A4C1-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PRIVACY_EXEMPTION_LIST = GUID$("{6CB9A4C2-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ENABLED_AUTHENTICATION_ALGORITHM = GUID$("{6CB9A4C3-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_UNICAST_ALGORITHM_PAIR = GUID$("{6CB9A4C4-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ENABLED_UNICAST_CIPHER_ALGORITHM = GUID$("{6CB9A4C5-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_MULTICAST_ALGORITHM_PAIR = GUID$("{6CB9A4C6-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ENABLED_MULTICAST_CIPHER_ALGORITHM = GUID$("{6CB9A4C7-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CIPHER_DEFAULT_KEY_ID = GUID$("{6CB9A4C8-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CIPHER_DEFAULT_KEY = GUID$("{6CB9A4C9-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CIPHER_KEY_MAPPING_KEY = GUID$("{6CB9A4CA-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ENUM_ASSOCIATION_INFO = GUID$("{6CB9A4CB-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DISCONNECT_REQUEST = GUID$("{6CB9A4CC-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_UNICAST_USE_GROUP_ENABLED = GUID$("{6CB9A4CD-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PHY_STATE = GUID$("{6CB9A4CE-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DESIRED_PHY_LIST = GUID$("{6CB9A4CF-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_CURRENT_PHY_ID = GUID$("{6CB9A4D0-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MEDIA_STREAMING_ENABLED = GUID$("{6CB9A4D1-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_UNREACHABLE_DETECTION_THRESHOLD = GUID$("{6CB9A4D2-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ACTIVE_PHY_LIST = GUID$("{6CB9A4D3-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_EXTSTA_CAPABILITY = GUID$("{6CB9A4D4-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DATA_RATE_MAPPING_TABLE = GUID$("{6CB9A4D5-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SUPPORTED_COUNTRY_OR_REGION_STRING = GUID$("{6CB9A4D6-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_DESIRED_COUNTRY_OR_REGION_STRING = GUID$("{6CB9A4D7-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PORT_STATE_NOTIFICATION = GUID$("{6CB9A4D8-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_IBSS_PARAMS = GUID$("{6CB9A4D9-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_QOS_PARAMS = GUID$("{6CB9A4DA-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_SAFE_MODE_ENABLED = GUID$("{6CB9A4DB-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_HIDDEN_NETWORK_ENABLED = GUID$("{6CB9A4DC-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_ASSOCIATION_PARAMS = GUID$("{6CB9A4DD-C45F-4039-9FE6-D08CB057184C}")

$GUID_NWF_CURRENT_ADDRESS = GUID$("{6CB9A840-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_PERMANENT_ADDRESS = GUID$("{6CB9A841-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MULTICAST_LIST = GUID$("{6CB9A842-C45F-4039-9FE6-D08CB057184C}")
$GUID_NWF_MAXIMUM_LIST_SIZE = GUID$("{6CB9A843-C45F-4039-9FE6-D08CB057184C}")


'#ifdef NWF_EXTAP_SUPPORTED

%DOT11_EXTAP_ATTRIBUTES_REVISION_1  = 1
'++++++++++++++
' // Size = 56 bytes
TYPE DOT11_EXTAP_ATTRIBUTES DWORD FILL
   Header                                  AS NDIS_OBJECT_HEADER                   ' NDIS_OBJECT_HEADER Header;
   uScanSSIDListSize                       AS DWORD                                ' ULONG
   uDesiredSSIDListSize                    AS DWORD                                ' ULONG
   uPrivacyExemptionListSize               AS DWORD                                ' ULONG
   uAssociationTableSize                   AS DWORD                                ' ULONG
   uDefaultKeyTableSize                    AS DWORD                                ' ULONG
   uWEPKeyValueMaxLength                   AS DWORD                                ' ULONG
   bStrictlyOrderedServiceClassImplemented AS BYTE                                 ' BOOLEAN
   ' // Supported Country Strings
   uNumSupportedCountryOrRegionStrings     AS DWORD                                ' ULONG
   pSupportedCountryOrRegionStrings        AS DOT11_COUNTRY_OR_REGION_STRING PTR   ' PDOT11_COUNTRY_OR_REGION_STRING
   ' // Unicast algorithm capabilities
   uInfraNumSupportedUcastAlgoPairs        AS DWORD                                ' ULONG
   pInfraSupportedUcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR           ' PDOT11_AUTH_CIPHER_PAIR
   ' // Multicast algorithm capabilities
   uInfraNumSupportedMcastAlgoPairs        AS DWORD                                ' ULONG
   pInfraSupportedMcastAlgoPairs           AS DOT11_AUTH_CIPHER_PAIR PTR           ' PDOT11_AUTH_CIPHER_PAIR
END TYPE

'#define NDIS_SIZEOF_DOT11_EXTAP_ATTRIBUTES_REVISION_1 sizeof(DOT11_EXTAP_ATTRIBUTES)

'// NDIS indications for Ext AP mode.

'// Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_STARTED

%DOT11_INCOMING_ASSOC_STARTED_PARAMETERS_REVISION_1 = 1

' // Size = 10 bytes
TYPE DOT11_INCOMING_ASSOC_STARTED_PARAMETERS BYTE
   Header      AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   PeerMacAddr AS DOT11_MAC_ADDRESS    ' DOT11_MAC_ADDRESS
END TYPE

'// Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_REQUEST_RECEIVED

%DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS DWORD FILL
   Header          AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   PeerMacAddr     AS DOT11_MAC_ADDRESS    ' DOT11_MAC_ADDRESS
   bReAssocReq     AS BYTE                 ' BOOLEAN
   uAssocReqOffset AS DWORD                ' ULONG
   uAssocReqSize   AS DWORD                ' ULONG
END TYPE

'// Data type for NDIS_STATUS_DOT11_INCOMING_ASSOC_COMPLETION

%DOT11_ASSOC_ERROR_SOURCE_OS	   = &H0
%DOT11_ASSOC_ERROR_SOURCE_REMOTE	= &H01
%DOT11_ASSOC_ERROR_SOURCE_OTHER	= &HFF

%DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS_REVISION_1 = 1

' // Size = 64 bytes
TYPE DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS DWORD FILL
   Header               AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   PeerMacAddr          AS DOT11_MAC_ADDRESS    ' DOT11_MAC_ADDRESS
   uStatus              AS DWORD                ' ULONG
   ucErrorSource        AS BYTE                 ' UCHAR
   bReAssocReq          AS BYTE                 ' BOOLEAN
   bReAssocResp         AS BYTE                 ' BOOLEAN
   uAssocReqOffset      AS DWORD                ' ULONG
   uAssocReqSize        AS DWORD                ' ULONG
   uAssocRespOffset     AS DWORD                ' ULONG
   uAssocRespSize       AS DWORD                ' ULONG
   ' // The following fields are applicable for successful association.
   ' // For association failure, they must be zero-ed out.
   AuthAlgo             AS LONG                 ' DOT11_AUTH_ALGORITHM
   UnicastCipher        AS LONG                 ' DOT11_CIPHER_ALGORITHM
   MulticastCipher      AS LONG                 ' DOT11_CIPHER_ALGORITHM
   uActivePhyListOffset AS DWORD                ' ULONG
   uActivePhyListSize   AS DWORD                ' ULONG
   uBeaconOffset        AS DWORD                ' ULONG
   uBeaconSize          AS DWORD                ' ULONG
END TYPE

'// Data type for NDIS_STATUS_DOT11_STOP_AP

%DOT11_STOP_AP_PARAMETERS_REVISION_1 = 1

' // Size = 8 bytes
TYPE DOT11_STOP_AP_PARAMETERS DWORD
   Header   AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   ulReason AS DWORD                ' ULONG
END TYPE

%DOT11_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE = &H1
%DOT11_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE   = &H2
%DOT11_STOP_AP_REASON_AP_ACTIVE               = &H3


%DOT11_STOP_AP_REASON_IHV_START = &HFF000000???
%DOT11_STOP_AP_REASON_IHV_END   = &HFFFFFFFF???

'// Data type for NDIS_STATUS_DOT11_PHY_FREQUENCY_ADOPTED

%DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_REVISION_1 = 1

UNION DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_UNION DWORD
   ulChannel   AS DWORD   ' ULONG
   ulFrequency AS DWORD   ' ULONG
END UNION

' // Size = 12 bytes
TYPE DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS DWORD
   Header  AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   ulPhyId AS DWORD                ' ULONG
   DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_UNION
END TYPE

'// Data type for NDIS_STATUS_DOT11_CAN_SUSTAIN_AP

%DOT11_CAN_SUSTAIN_AP_PARAMETERS_REVISION_1 = 1

' // Size = 8 bytes
TYPE DOT11_CAN_SUSTAIN_AP_PARAMETERS DWORD
   Header   AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   ulReason AS DWORD                ' ULONG
END TYPE

%DOT11_CAN_SUSTAIN_AP_REASON_IHV_START = &HFF000000???
%DOT11_CAN_SUSTAIN_AP_REASON_IHV_END   = &HFFFFFFFF???

'// TAG for Ext AP specific OIDs.
%NWF_EXTAP_OID = &H03???   ' (0x03U)

'#define OID_DOT11_WPS_ENABLED                       NWF_DEFINE_OID(0x01,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // BOOLEAN
%OID_DOT11_WPS_ENABLED = &H0E030101???

'#define OID_DOT11_START_AP_REQUEST                  NWF_DEFINE_OID(0x02,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // VOID
%OID_DOT11_START_AP_REQUEST = &H0E030102???

'#define OID_DOT11_AVAILABLE_CHANNEL_LIST            NWF_DEFINE_OID(0x03,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_AVAILABLE_CHANNEL_LIST
%OID_DOT11_AVAILABLE_CHANNEL_LIST = &H0E030103???

%DOT11_AVAILABLE_CHANNEL_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_AVAILABLE_CHANNEL_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   uChannelNumber(0)  AS DWORD                ' ULONG uChannelNumber[1];
END TYPE

'#define OID_DOT11_AVAILABLE_FREQUENCY_LIST          NWF_DEFINE_OID(0x04,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_AVAILABLE_FREQUENCY_LIST
%OID_DOT11_AVAILABLE_FREQUENCY_LIST = &H0E030104???

%DOT11_AVAILABLE_FREQUENCY_LIST_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_AVAILABLE_FREQUENCY_LIST DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD                ' ULONG
   uTotalNumOfEntries AS DWORD                ' ULONG
   uFrequencyValue(0) AS DWORD                ' ULONG uFrequencyValue[1]
END TYPE

'#define OID_DOT11_DISASSOCIATE_PEER_REQUEST         NWF_DEFINE_OID(0x05,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_DISASSOCIATE_PEER_REQUEST
%OID_DOT11_DISASSOCIATE_PEER_REQUEST = &H0E030105???

%DOT11_DISASSOCIATE_PEER_REQUEST_REVISION_1 = 1

' // Size = 12 bytes
TYPE DOT11_DISASSOCIATE_PEER_REQUEST BYTE
   Header      AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   PeerMacAddr AS DOT11_MAC_ADDRESS    ' DOT11_MAC_ADDRESS
   usReason    AS WORD                 ' USHORT
END TYPE

'#define OID_DOT11_INCOMING_ASSOCIATION_DECISION     NWF_DEFINE_OID(0x06,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_INCOMING_ASSOC_DECISION
%OID_DOT11_INCOMING_ASSOCIATION_DECISION = &H0E030106???

%DOT11_INCOMING_ASSOC_DECISION_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_INCOMING_ASSOC_DECISION DWORD FILL
   Header                  AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   PeerMacAddr             AS DOT11_MAC_ADDRESS    ' DOT11_MAC_ADDRESS
   bAccept                 AS BYTE                 ' BOOLEAN
   usReasonCode            AS WORD                 ' USHORT
   uAssocResponseIEsOffset AS DWORD                ' ULONG
   uAssocResponseIEsLength AS DWORD                ' ULONG
END TYPE

'#define OID_DOT11_ADDITIONAL_IE                     NWF_DEFINE_OID(0x07,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_ADDITIONAL_IE
%OID_DOT11_ADDITIONAL_IE = &H0E030107???

%DOT11_ADDITIONAL_IE_REVISION_1 = 1

' // Size = 20 bytes
TYPE DOT11_ADDITIONAL_IE DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uBeaconIEsOffset   AS DWORD                ' ULONG
   uBeaconIEsLength   AS DWORD                ' ULONG
   uResponseIEsOffset AS DWORD                ' ULONG
   uResponseIEsLength AS DWORD                ' ULONG
END TYPE

'//
'// Ext AP Send context
'//
%DOT11_EXTAP_SEND_CONTEXT_REVISION_1 = 1

'typedef
'struct DOT11_EXTSTA_SEND_CONTEXT
'DOT11_EXTAP_SEND_CONTEXT, *PDOT11_EXTAP_SEND_CONTEXT;

'//
'// Ext AP Receive context
'//
%DOT11_EXTAP_RECV_CONTEXT_REVISION_1 = 1

'struct DOT11_EXTSTA_RECV_CONTEXT
'DOT11_EXTAP_RECV_CONTEXT, *PDOT11_EXTAP_RECV_CONTEXT;

'#define OID_DOT11_ENUM_PEER_INFO                    NWF_DEFINE_OID(0x08,NWF_EXTAP_OID,NWF_MANDATORY_OID)
'    // DOT11_PEER_INFO_LIST
%OID_DOT11_ENUM_PEER_INFO = &H0E030108???

' // Size = 48 bytes
TYPE DOT11_PEER_STATISTICS QWORD
   ullDecryptSuccessCount  AS QUAD   ' ULONGLONG
   ullDecryptFailureCount  AS QUAD   ' ULONGLONG
   ullTxPacketSuccessCount AS QUAD   ' ULONGLONG
   ullTxPacketFailureCount AS QUAD   ' ULONGLONG
   ullRxPacketSuccessCount AS QUAD   ' ULONGLONG
   ullRxPacketFailureCount AS QUAD   ' ULONGLONG
END TYPE

' // Size = 352 bytes
TYPE DOT11_PEER_INFO QWORD FILL
   MacAddress              AS DOT11_MAC_ADDRESS      ' DOT11_MAC_ADDRESS
   usCapabilityInformation AS WORD                   ' USHORT
   AuthAlgo                AS LONG                   ' DOT11_AUTH_ALGORITHM
   UnicastCipherAlgo       AS LONG                   ' DOT11_CIPHER_ALGORITHM
   MulticastCipherAlgo     AS LONG                   ' DOT11_CIPHER_ALGORITHM
   bWpsEnabled             AS BYTE                   ' BOOLEAN
   usListenInterval        AS WORD                   ' USHORT
   ucSupportedRates(%MAX_NUM_SUPPORTED_RATES_V2 -  1) AS BYTE   ' UCHAR ucSupportedRates[MAX_NUM_SUPPORTED_RATES_V2]
   usAssociationID         AS WORD                    ' USHORT
   AssociationState        AS LONG                    ' DOT11_ASSOCIATION_STATE
   PowerMode               AS LONG                    ' DOT11_POWER_MODE
   liAssociationUpTime     AS QUAD                    ' LARGE_INTEGER
   Statistics              AS DOT11_PEER_STATISTICS   ' DOT11_PEER_STATISTICS
END TYPE

%DOT11_PEER_INFO_LIST_REVISION_1 = 1

' // Size = 368 bytes
TYPE DOT11_PEER_INFO_LIST QWORD FILL
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uNumOfEntries      AS DWORD   ' ULONG
   uTotalNumOfEntries AS DWORD   ' ULONG
   PeerInfo(0)        AS DOT11_PEER_INFO   ' DOT11_PEER_INFO PeerInfo[1];
END TYPE

'#endif // NWF_EXTAP_SUPPORTED

'#ifdef NWF_VWIFI_SUPPORTED

%DOT11_VWIFI_COMBINATION_REVISION_1 = 1

' // Size = 16 bytes
TYPE DOT11_VWIFI_COMBINATION DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uNumInfrastructure AS DWORD                ' ULONG
   uNumAdhoc          AS DWORD                ' ULONG
   uNumSoftAP         AS DWORD                ' ULONG
END TYPE

'#define DOT11_SIZEOF_VWIFI_COMBINATION_REVISION_1   sizeof(DOT11_VWIFI_COMBINATION)

%DOT11_VWIFI_COMBINATION_REVISION_2 = 2

' // Size = 20 bytes
TYPE DOT11_VWIFI_COMBINATION_V2 DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   uNumInfrastructure AS DWORD                ' ULONG
   uNumAdhoc          AS DWORD                ' ULONG uNumAdhoc
   uNumSoftAP         AS DWORD                ' ULONG
   uNumVirtualStation AS DWORD                ' ULONG
END TYPE

'#define DOT11_SIZEOF_VWIFI_COMBINATION_REVISION_2   sizeof(DOT11_VWIFI_COMBINATION_V2)

%DOT11_VWIFI_ATTRIBUTES_REVISION_1 = 1

' // Size = 24 bytes
TYPE DOT11_VWIFI_ATTRIBUTES DWORD
   Header             AS NDIS_OBJECT_HEADER        ' NDIS_OBJECT_HEADER
   uTotalNumOfEntries AS DWORD                     ' ULONG
   Combinations(0)    AS DOT11_VWIFI_COMBINATION   ' DOT11_VWIFI_COMBINATION Combinations[1]
END TYPE

'// TAG for Virtual WiFi specific OIDs.
%NWF_VWIFI_OID = &H04???   ' (0x04U)

'#define OID_DOT11_CREATE_MAC                        NWF_DEFINE_OID(0x01,NWF_VWIFI_OID,NWF_MANDATORY_OID)
%OID_DOT11_CREATE_MAC = &H0E040101???

' // Size = 16 bytes
TYPE DOT11_MAC_INFO DWORD
   uReserved       AS DWORD               ' ULONG
   uNdisPortNumber AS DWORD               ' ULONG
   MacAddr         AS DOT11_MAC_ADDRESS   ' DOT11_MAC_ADDRESS
END TYPE

'#define OID_DOT11_DELETE_MAC                        NWF_DEFINE_OID(0x02,NWF_VWIFI_OID,NWF_MANDATORY_OID)
%OID_DOT11_DELETE_MAC = &H0E040102???

'#define OID_DOT11_PREFERRED_MAC                     NWF_DEFINE_OID(0x03,NWF_VWIFI_OID,NWF_MANDATORY_OID)
%OID_DOT11_PREFERRED_MAC = &H0E040103???

'#define OID_DOT11_VIRTUAL_STATION_CAPABILITY        NWF_DEFINE_OID(0x04,NWF_VWIFI_OID,NWF_OPTIONAL_OID)
%OID_DOT11_VIRTUAL_STATION_CAPABILITY = &H0E040104???

'#endif // NWF_VWIFI_SUPPORTED

#ENDIF   ' // (NTDDI_VERSION > NTDDI_VISTA)
