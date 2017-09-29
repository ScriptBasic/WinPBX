' ########################################################################################
' Microsoft Windows
' File: dhcpsapi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DHCPSAPI_INC = 1

'#ifndef _DHCP_

'typedef DWORD DHCP_IP_ADDRESS, *PDHCP_IP_ADDRESS, *LPDHCP_IP_ADDRESS;
'typedef DWORD DHCP_OPTION_ID;

' // Serie = 8 bytes
TYPE DATE_TIME DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

'#endif // _DHCP_

'typedef DWORD DHCP_IP_MASK;
'typedef DWORD DHCP_RESUME_HANDLE;

' // Serie = 8 bytes
TYPE DHCP_IP_RANGE DWORD
   StartAddress AS DWORD   ' DHCP_IP_ADDRESS
   EndAddress   AS DWORD   ' DHCP_IP_ADDRESS
END TYPE

' // Serie = 8 bytes
TYPE DHCP_BINARY_DATA DWORD
   DataLength AS DWORD      ' DWORD
   Data       AS BYTE PTR   ' BYTE*
END TYPE

'typedef DHCP_BINARY_DATA DHCP_CLIENT_UID;
MACRO DHCP_CLIENT_UID = DHCP_BINARY_DATA

' // Serie = 12 bytes
TYPE DHCP_HOST_INFO DWORD
   IpAddress   AS DWORD          ' DHCP_IP_ADDRESS // minimum information always available
   NetBiosName AS WSTRINGZ PTR   ' LPWSTR // optional information
   HostName    AS WSTRINGZ PTR   ' LPWSTR // optional information
END TYPE

' enum DHCP_FORCE_FLAG
%DhcpFullForce = 0   ' // The operation deletes all client records affected by the element, and then deletes the element.,
%DhcpNoForce   = 1   ' // The operation only deletes the subnet element, leaving intact any client records impacted by the change.

' // Serie = 8 bytes
TYPE DWORD_DWORD DWORD
   DWord1 AS DWORD   ' DWORD
   DWord2 AS DWORD   ' DWORD
END TYPE

' enum _DHCP_SUBNET_STATE
%DhcpSubnetEnabled          = 0
%DhcpSubnetDisabled         = 1
%DhcpSubnetEnabledSwitched  = 2
%DhcpSubnetDisabledSwitched = 3
%DhcpSubnetInvalidState     = 4

'//
'// Subnet related data structures.
'//

' // Serie = 32 bytes
TYPE DHCP_SUBNET_INFO DWORD
   SubnetAddress AS DWORD            ' DHCP_IP_ADDRESS
   SubnetMask    AS DWORD            ' DHCP_IP_MASK
   SubnetName    AS WSTRINGZ PTR     ' LPWSTR
   SubnetComment AS WSTRINGZ PTR     ' LPWSTR
   PrimaryHost   AS DHCP_HOST_INFO
   SubnetState   AS LONG             ' DHCP_SUBNET_STATE
END TYPE

'#define DHCP_SUBNET_INFO_VQ_FLAG_QUARANTINE    (1 << 0)        // Bit 0
%DHCP_SUBNET_INFO_VQ_FLAG_QUARANTINE = 1

' // Serie = 64 bytes
TYPE DHCP_SUBNET_INFO_VQ QWORD FILL
   SubnetAddress AS DWORD            ' DHCP_IP_ADDRESS
   SubnetMask    AS DWORD            ' DHCP_IP_MASK
   SubnetName    AS WSTRINGZ PTR     ' LPWSTR
   SubnetComment AS WSTRINGZ PTR     ' LPWSTR
   PrimaryHost   AS DHCP_HOST_INFO
   SubnetState   AS LONG             ' DHCP_SUBNET_STATE
   QuarantineOn  AS DWORD            ' DWORD
   Reserved1     AS DWORD            ' DWORD
   Reserved2     AS DWORD            ' DWORD
   Reserved3     AS QUAD             ' INT64
   Reserved4     AS QUAD             ' INT64
END TYPE

' // Serie = 8 bytes
TYPE DHCP_IP_ARRAY DWORD
   NumElements AS DWORD       ' DWORD
   Elements    AS DWORD PTR   ' LPDHCP_IP_ADDRESS //array
END TYPE

' // Serie = 8 bytes
TYPE DHCP_IP_CLUSTER DWORD
   ClusterAddress AS DWORD   ' DHCP_IP_ADDRESS
   ClusterMask    AS DWORD   ' DWORD
END TYPE

' // Serie = 8 bytes
TYPE DHCP_IP_RESERVATION DWORD
   ReservedIpAddress AS DWORD                 ' DHCP_IP_ADDRESS
   ReservedForClient AS DHCP_CLIENT_UID PTR   ' DHCP_CLIENT_UID*
END TYPE

' enum DHCP_SUBNET_ELEMENT_TYPE alias _DHCP_SUBNET_ELEMENT_TYPE_V5
%DhcpIpRanges          = 0   ' // The subnet element contains the range of DHCP-served IP addresses.
%DhcpSecondaryHosts    = 1   ' // The subnet element contains the IP addresses of secondary DHCP hosts available in the subnet.
%DhcpReservedIps       = 2   ' // The subnet element contains the individual reserved IP addresses for the subnet.,
%DhcpExcludedIpRanges  = 3   ' // The subnet element contains the IP addresses excluded from the range of DHCP-served addresses.,
%DhcpIpRangesDhcpOnly  = 4   ' // The subnet element contains the IP addresses served by DHCP to the subnet (as opposed to those served by other dynamic address services, such as BOOTP).,
%DhcpIpRangesDhcpBootp = 5   ' // The subnet element contains the IP addresses served by both DHCP and BOOTP to the subnet.,
%DhcpIpRangesBootpOnly = 6   ' // The subnet element contains the IP addresses served by BOOTP to the subnet (specifically excluding DHCP-served addresses).

'#define ELEMENT_MASK(E) ((((E) <= DhcpIpRangesBootpOnly) && (DhcpIpRangesDhcpOnly <= (E)))?(0):(E))

' // Serie = 4 bytes
UNION DHCP_SUBNET_ELEMENT_DATA_UNION DWORD
   IpRange        AS DHCP_IP_RANGE PTR   ' DHCP_IP_RANGE*
   SecondaryHost  AS DHCP_HOST_INFO PTR   ' DHCP_HOST_INFO*
   ReservedIp     AS DHCP_IP_RESERVATION PTR   ' DHCP_IP_RESERVATION*
   ExcludeIpRange AS DHCP_IP_RANGE PTR   ' DHCP_IP_RANGE*
   IpUsedCluster  AS DHCP_IP_CLUSTER PTR   ' DHCP_IP_CLUSTER*
END UNION

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_DATA DWORD
   ElementType AS LONG   ' DHCP_SUBNET_ELEMENT_TYPE
   Element     AS DHCP_SUBNET_ELEMENT_DATA_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_INFO_ARRAY DWORD
   NumElements AS DWORD                          ' DWORD
   Elements    AS DHCP_SUBNET_ELEMENT_DATA PTR   ' LPDHCP_SUBNET_ELEMENT_DATA_V5 //array
END TYPE

' // Serie = 16 bytes
TYPE DHCP_IPV6_ADDRESS QWORD
   HighOrderBits AS QUAD   ' ULONGLONG
   LowOrderBits  AS QUAD   ' ULONGLONG
END TYPE

'typedef DHCP_IPV6_ADDRESS DHCP_RESUME_IPV6_HANDLE;
MACRO DHCP_RESUME_IPV6_HANDLE = DHCP_IPV6_ADDRESS

'//
'// DHCP Filter related data structures.
'//

%MAX_PATTERN_LENGTH   = 255
%MAC_ADDRESS_LENGTH   = 6
%HWTYPE_ETHERNET_10MB = 1

' enum DHCP_FILTER_LIST_TYPE
%DHCP_FILTER_LIST_TYPE_Deny  = 0
%DHCP_FILTER_LIST_TYPE_Allow = 1

' // Serie = 268 bytes
TYPE DHCP_ADDR_PATTERN WORD
   MatchHWType AS LONG   ' BOOL
   HWType      AS BYTE   ' BYTE
   IsWildcard  AS LONG   ' BOOL
   Length      AS BYTE   ' BYTE
   Pattern(%MAX_PATTERN_LENGTH - 1) AS BYTE   ' BYTE //  Variable Length address/pattern
END TYPE

' // Serie = 276 bytes
TYPE DHCP_FILTER_ADD_INFO DWORD
   AddrPatt AS DHCP_ADDR_PATTERN   ' DHCP_ADDR_PATTERN // Contains address/pattern
   Comment  AS WSTRINGZ PTR        ' LPWSTR // Comment associated with address/pattern
   ListType AS LONG                ' DHCP_FILTER_LIST_TYPE // Enum that specifies either allow or deny
END TYPE

MACRO DHCP_FILTER_ADD_INFOV4 = DHCP_FILTER_ADD_INFO

' // Serie = 8 bytes
TYPE DHCP_FILTER_GLOBAL_INFO DWORD
   EnforceAllowList AS LONG   ' BOOL
   EnforceDenyList  AS LONG   ' BOOL
END TYPE

' // Serie = 272 bytes
TYPE DHCP_FILTER_RECORD DWORD
   AddrPatt AS DHCP_ADDR_PATTERN   ' DHCP_ADDR_PATTERN // Contains MAC address/pattern and Mask
   Comment  AS WSTRINGZ PTR        ' LPWSTR // Comment associated with MAC address/pattern
END TYPE

' // Serie = 8 bytes
TYPE DHCP_FILTER_ENUM_INFO DWORD
   NumElements  AS DWORD                    ' DWORD
   pEnumRecords AS DHCP_FILTER_RECORD PTR   ' LPDHCP_FILTER_RECORD
END TYPE

'//
'// DHCP Options related data structures.
'//

' enum DHCP_OPTION_DATA_TYPE
%DhcpByteOption             = 0
%DhcpWordOption             = 1
%DhcpDWordOption            = 2
%DhcpDWordDWordOption       = 3
%DhcpIpAddressOption        = 4
%DhcpStringDataOption       = 5
%DhcpBinaryDataOption       = 6
%DhcpEncapsulatedDataOption = 7
%DhcpIpv6AddressOption      = 8

' // Serie = 8 bytes
UNION DHCP_OPTION_ELEMENT_UNION
   ByteOption             AS BYTE               ' BYTE
   WordOption             AS WORD               ' WORD
   DWordOption            AS DWORD              ' DWORD
   DWordDWordOption       AS DWORD_DWORD
   IpAddressOption        AS DWORD              ' DHCP_IP_ADDRESS
   StringDataOption       AS WSTRINGZ PTR       ' LPWSTR
   BinaryDataOption       AS DHCP_BINARY_DATA
   EncapsulatedDataOption AS DHCP_BINARY_DATA
   Ipv6AddressDataOption  AS WSTRINGZ PTR       ' LPWSTR
      ' // for vendor specific information option.
END UNION

' // Serie = 12 bytes
TYPE DHCP_OPTION_DATA_ELEMENT DWORD
   OptionType AS LONG                        ' DHCP_OPTION_DATA_TYPE enum
   Element    AS DHCP_OPTION_ELEMENT_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_OPTION_DATA DWORD
   NumElements AS DWORD                          ' DWORD // number of option elements in the pointed array
   Elements    AS DHCP_OPTION_DATA_ELEMENT PTR   ' LPDHCP_OPTION_DATA_ELEMENT //array
END TYPE

' enum DHCP_OPTION_TYPE
%DhcpUnaryElementTypeOption = 0
%DhcpArrayTypeOption        = 1

' // Serie = 24 bytes
TYPE DHCP_OPTION DWORD
   OptionID      AS DWORD              ' DHCP_OPTION_ID
   OptionName    AS WSTRINGZ PTR       ' LPWSTR
   OptionComment AS WSTRINGZ PTR       ' LPWSTR
   DefaultValue  AS DHCP_OPTION_DATA   ' DHCP_OPTION_DATA
   OptionType    AS LONG               ' DHCP_OPTION_TYPE
END TYPE

' // Serie = 8 bytes
TYPE DHCP_OPTION_ARRAY DWORD
   NumElements AS DWORD             ' DWORD // number of options in the pointed array
   Options     AS DHCP_OPTION PTR   ' LPDHCP_OPTION // array
END TYPE

' // Serie = 12 bytes
TYPE DHCP_OPTION_VALUE DWORD
   OptionID AS DWORD              ' DHCP_OPTION_ID
   Value    AS DHCP_OPTION_DATA
END TYPE

' // Serie = 8 bytes
TYPE DHCP_OPTION_VALUE_ARRAY DWORD
   NumElements AS DWORD                   ' DWORD // number of options in the pointed array
   Values      AS DHCP_OPTION_VALUE PTR   ' LPDHCP_OPTION_VALUE // array
END TYPE

' enum DHCP_OPTION_SCOPE_TYPE
%DhcpDefaultOptions  = 0
%DhcpGlobalOptions   = 1
%DhcpSubnetOptions   = 2
%DhcpReservedOptions = 3
%DhcpMScopeOptions   = 4

' // Serie = 8 bytes
TYPE DHCP_RESERVED_SCOPE DWORD
   ReservedIpAddress       AS DWORD   ' DHCP_IP_ADDRESS
   ReservedIpSubnetAddress AS DWORD   ' DHCP_IP_ADDRESS
END TYPE

' // Serie = 8 bytes
UNION DHCP_OPTION_SCOPE_UNION
   DefaultScopeInfo  AS DWORD                 ' PVOID // must be NULL
   GlobalScopeInfo   AS DWORD                 ' PVOID // must be NULL
   SubnetScopeInfo   AS DWORD                 ' DHCP_IP_ADDRESS
   ReservedScopeInfo AS DHCP_RESERVED_SCOPE
   MScopeInfo        AS WSTRINGZ PTR          ' LPWSTR
END UNION

' // Serie = 12 bytes
TYPE DHCP_OPTION_SCOPE_INFO DWORD
   ScopeType AS LONG                       ' DHCP_OPTION_SCOPE_TYPE enum
   ScopeInfo AS DHCP_OPTION_SCOPE_UNION
END TYPE

' enum DHCP_OPTION_SCOPE_TYPE6
%DhcpDefaultOptions6  = 0
%DhcpScopeOptions6    = 1
%DhcpReservedOptions6 = 2
%DhcpGlobalOptions6   = 3

' // Serie = 32 bytes
TYPE DHCP_RESERVED_SCOPE6 QWORD
   ReservedIpAddress       AS DHCP_IPV6_ADDRESS
   ReservedIpSubnetAddress AS DHCP_IPV6_ADDRESS
END TYPE

' // Serie = 32 bytes
UNION DHCP_OPTION_SCOPE_INFO6_ScopeInfo QWORD
   DefaultScopeInfo  AS DWORD   ' PVOID // must be NULL
   SubnetScopeInfo   AS DHCP_IPV6_ADDRESS
   ReservedScopeInfo AS DHCP_RESERVED_SCOPE6
END UNION

' // Serie = 40 bytes
TYPE DHCP_OPTION_SCOPE_INFO6 QWORD
   ScopeType AS LONG   ' DHCP_OPTION_SCOPE_TYPE6
   ScopeInfo AS DHCP_OPTION_SCOPE_INFO6_ScopeInfo
END TYPE

' // Serie = 8 bytes
TYPE DHCP_OPTION_LIST DWORD
   NumOptions AS DWORD   ' DWORD
   Options    AS DHCP_OPTION_VALUE PTR   ' DHCP_OPTION_VALUE* // array
END TYPE

'//
'// DHCP Client information data structures
'//

' // Serie = 44 bytes
TYPE DHCP_CLIENT_INFO DWORD
   ClientIpAddress       AS DWORD             ' DHCP_IP_ADDRESS // currently assigned IP address.
   SubnetMask            AS DWORD             ' DHCP_IP_MASK
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR      ' LPWSTR // optional.
   ClientComment         AS WSTRINGZ PTR      ' LPWSTR
   ClientLeaseExpires    AS DATE_TIME         ' // UTC time in FILE_TIME format.
   OwnerHost             AS DHCP_HOST_INFO    ' // host that distributed this IP address.
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLIENT_INFO_ARRAY DWORD
   NumElements AS DWORD                  ' DWORD
   Clients     AS DHCP_CLIENT_INFO PTR   ' LPDHCP_CLIENT_INFO* // array of pointers
END TYPE

' enum QuarantineStatus
%QuarantineStatus_NOQUARANTINE       = 0
%QuarantineStatus_RESTRICTEDACCESS   = 1
%QuarantineStatus_DROPPACKET         = 2
%QuarantineStatus_PROBATION          = 3
%QuarantineStatus_EXEMPT             = 4
%QuarantineStatus_DEFAULTQUARSETTING = 5
%QuarantineStatus_NOQUARINFO         = 6

' // Serie = 64 bytes
TYPE DHCP_CLIENT_INFO_VQ WORD
   ClientIpAddress       AS DWORD              ' DHCP_IP_ADDRESS // currently assigned IP address.
   SubnetMask            AS DWORD              ' DHCP_IP_MASK
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR       ' LPWSTR
   ClientComment         AS WSTRINGZ PTR       ' LPWSTR
   ClientLeaseExpires    AS DATE_TIME          ' // UTC time in FILE_TIME format.
   OwnerHost             AS DHCP_HOST_INFO     ' // host that distributed this IP address.
   bClientType           AS BYTE               ' BYTE
   AddressState          AS BYTE               ' BYTE
   Status                AS LONG               ' QuarantineStatus
   ProbationEnds         AS DATE_TIME
   QuarantineCapable     AS LONG               ' BOOL
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLIENT_INFO_ARRAY_VQ DWORD
   NumElements AS DWORD                     ' DWORD
   Clients     AS DHCP_CLIENT_INFO_VQ PTR   ' LPDHCP_CLIENT_INFO_VQ* // array of pointers
END TYPE

'//When the client's MAC Address doesn't match any configured filters
%FILTER_STATUS_NONE                          = &H00000001???

'//When the client's MAC Address matches an allow filter fully
%FILTER_STATUS_FULL_MATCH_IN_ALLOW_LIST      = &H00000002???

'//When the client's MAC Address matches a deny filter fully
%FILTER_STATUS_FULL_MATCH_IN_DENY_LIST       = &H00000004???

'//When the client's MAC Address has a wildcard match in the allow list
%FILTER_STATUS_WILDCARD_MATCH_IN_ALLOW_LIST  = &H00000008???

'//When the client's MAC Address has a wildcard match in the deny list
%FILTER_STATUS_WILDCARD_MATCH_IN_DENY_LIST   = &H00000010???

' // Serie = 68 bytes
TYPE DHCP_CLIENT_FILTER_STATUS_INFO WORD
   ClientIpAddress       AS DWORD             ' DHCP_IP_ADDRESS
   SubnetMask            AS DWORD             ' DHCP_IP_MASK
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR      ' LPWSTR
   ClientComment         AS WSTRINGZ PTR      ' LPWSTR
   ClientLeaseExpires    AS DATE_TIME
   OwnerHost             AS DHCP_HOST_INFO
   bClientType           AS BYTE              ' BYTE
   AddressState          AS BYTE              ' BYTE
   Status                AS LONG              ' QuarantineStatus
   ProbationEnds         AS DATE_TIME
   QuarantineCapable     AS LONG              ' BOOL
   FilterStatus          AS DWORD             ' DWORD
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLIENT_FILTER_STATUS_INFO_ARRAY DWORD
   NumElements AS DWORD                                ' DWORD
   Clients     AS DHCP_CLIENT_FILTER_STATUS_INFO PTR   ' LPDHCP_CLIENT_FILTER_STATUS_INFO * // array of pointers
END TYPE

' enum DHCP_SEARCH_INFO_TYPE alias DHCP_CLIENT_SEARCH_TYPE
%DhcpClientIpAddress       = 0
%DhcpClientHardwareAddress = 1
%DhcpClientName            = 2

' // Serie = 8 bytes
UNION DHCP_SEARCH_INFO_UNION DWORD
   ClientIpAddress       AS DWORD             ' DHCP_IP_ADDRESS
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR      ' LPWSTR
END UNION

' // Serie = 8 bytes
TYPE DHCP_SEARCH_INFO DWORD
   SearchType AS LONG                       ' DHCP_SEARCH_INFO_TYPE enum
   SearchInfo AS DHCP_SEARCH_INFO_UNION
END TYPE

MACRO DHCP_CLIENT_SEARCH_INFO = DHCP_SEARCH_INFO

'//
'// Mib Info structures.
'//

' // Serie = 16 bytes
TYPE SCOPE_MIB_INFO DWORD
   Subnet            AS DWORD   ' DHCP_IP_ADDRESS
   NumAddressesInuse AS DWORD   ' DWORD
   NumAddressesFree  AS DWORD   ' DWORD
   NumPendingOffers  AS DWORD   ' DWORD
END TYPE

' // Serie = 44 bytes
TYPE DHCP_MIB_INFO DWORD
   Discovers       AS DWORD       ' DWORD
   Offers          AS DWORD       ' DWORD
   Requests        AS DWORD       ' DWORD
   Acks            AS DWORD       ' DWORD
   Naks            AS DWORD       ' DWORD
   Declines        AS DWORD       ' DWORD
   Releases        AS DWORD       ' DWORD
   ServerStartTime AS DATE_TIME
   Scopes          AS DWORD       ' DWORD
   ScopeInfo       AS SCOPE_MIB_INFO PTR   ' LPSCOPE_MIB_INFO // array.
END TYPE

'//
'// Quarantine version of mib structures
'//

' // Serie = 40 bytes
TYPE SCOPE_MIB_INFO_VQ DWORD
   Subnet             AS DWORD   ' DHCP_IP_ADDRESS
   NumAddressesInuse  AS DWORD   ' DWORD
   NumAddressesFree   AS DWORD   ' DWORD
   NumPendingOffers   AS DWORD   ' DWORD
   ' // Quarantine MIB info
   QtnNumLeases       AS DWORD   ' DWORD
   QtnPctQtnLeases    AS DWORD   ' DWORD
   QtnProbationLeases AS DWORD   ' DWORD
   QtnNonQtnLeases    AS DWORD   ' DWORD
   QtnExemptLeases    AS DWORD   ' DWORD
   QtnCapableClients  AS DWORD   ' DWORD
END TYPE

' // Serie = 72 bytes
TYPE DHCP_MIB_INFO_VQ DWORD
   Discovers          AS DWORD       'DWORD
   Offers             AS DWORD       'DWORD
   Requests           AS DWORD       'DWORD
   Acks               AS DWORD       'DWORD
   Naks               AS DWORD       'DWORD
   Declines           AS DWORD       'DWORD
   Releases           AS DWORD       'DWORD
   ServerStartTime    AS DATE_TIME
   ' // Quarantine MIB info
   QtnNumLeases       AS DWORD       'DWORD
   QtnPctQtnLeases    AS DWORD       'DWORD
   QtnProbationLeases AS DWORD       'DWORD
   QtnNonQtnLeases    AS DWORD       'DWORD
   QtnExemptLeases    AS DWORD       'DWORD
   QtnCapableClients  AS DWORD       'DWORD
   QtnIASErrors       AS DWORD       'DWORD
   Scopes             AS DWORD       'DWORD
   ScopeInfo          AS SCOPE_MIB_INFO_VQ PTR   ' LPSCOPE_MIB_INFO_VQ // array.
END TYPE

' // Serie = 16 bytes
TYPE SCOPE_MIB_INFO_V5 DWORD
   Subnet            AS DWORD   ' DHCP_IP_ADDRESS
   NumAddressesInuse AS DWORD   ' DWORD
   NumAddressesFree  AS DWORD   ' DWORD
   NumPendingOffers  AS DWORD   ' DWORD
END TYPE

' // Serie = 80 bytes
TYPE DHCP_MIB_INFO_V5 DWORD
   Discovers               AS DWORD   ' DWORD
   Offers                  AS DWORD   ' DWORD
   Requests                AS DWORD   ' DWORD
   Acks                    AS DWORD   ' DWORD
   Naks                    AS DWORD   ' DWORD
   Declines                AS DWORD   ' DWORD
   Releases                AS DWORD   ' DWORD
   ServerStartTime         AS DATE_TIME
   ' // Quarantine MIB info
   QtnNumLeases            AS DWORD   ' DWORD
   QtnPctQtnLeases         AS DWORD   ' DWORD
   QtnProbationLeases      AS DWORD   ' DWORD
   QtnNonQtnLeases         AS DWORD   ' DWORD
   QtnExemptLeases         AS DWORD   ' DWORD
   QtnCapableClients       AS DWORD   ' DWORD
   QtnIASErrors            AS DWORD   ' DWORD
   DelayedOffers           AS DWORD   ' DWORD
   ScopesWithDelayedOffers AS DWORD   ' DWORD
   Scopes                  AS DWORD   ' DWORD
   ScopeInfo               AS SCOPE_MIB_INFO_V5 PTR   ' LPSCOPE_MIB_INFO_V5 // array.
END TYPE

%Set_APIProtocolSupport          = &H00000001???
%Set_DatabaseName                = &H00000002???
%Set_DatabasePath                = &H00000004???
%Set_BackupPath                  = &H00000008???
%Set_BackupInterval              = &H00000010???
%Set_DatabaseLoggingFlag         = &H00000020???
%Set_RestoreFlag                 = &H00000040???
%Set_DatabaseCleanupInterval     = &H00000080???
%Set_DebugFlag                   = &H00000100???
%Set_PingRetries                 = &H00000200???
%Set_BootFileTable               = &H00000400???
%Set_AuditLogState               = &H00000800???
%Set_QuarantineON                = &H00001000???
%Set_QuarantineDefFail           = &H00002000???

' // Serie = 36 bytes
TYPE DHCP_SERVER_CONFIG_INFO DWORD
   APIProtocolSupport      AS DWORD          ' DWORD // bit map of the protocols supported.
   DatabaseName            AS WSTRINGZ PTR   ' LPWSTR // JET database name.
   DatabasePath            AS WSTRINGZ PTR   ' LPWSTR // JET database path.
   BackupPath              AS WSTRINGZ PTR   ' LPWSTR // Backup path.
   BackupInterval          AS DWORD          ' DWORD // Backup interval in mins.
   DatabaseLoggingFlag     AS DWORD          ' DWORD // Boolean database logging flag.
   RestoreFlag             AS DWORD          ' DWORD // Boolean database restore flag.
   DatabaseCleanupInterval AS DWORD          ' DWORD // Database Cleanup Interval in mins.
   DebugFlag               AS DWORD          ' DWORD // Bit map of server debug flags.
END TYPE

' enum DHCP_SCAN_FLAG
%DhcpRegistryFix = 0
%DhcpDatabaseFix = 1

' // Serie = 8 bytes
TYPE DHCP_SCAN_ITEM DWORD
   IpAddress AS DWORD   ' DHCP_IP_ADDRESS
   ScanFlag  AS LONG    ' DHCP_SCAN_FLAG
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SCAN_LIST DWORD
   NumScanItems AS DWORD   ' DWORD
   ScanItems    AS DHCP_SCAN_ITEM PTR   ' DHCP_SCAN_ITEM* // array
END TYPE

' // Serie = 24 bytes
TYPE DHCP_CLASS_INFO DWORD
   ClassName       AS WSTRINGZ PTR   ' LPWSTR
   ClassComment    AS WSTRINGZ PTR   ' LPWSTR
   ClassDataLength AS DWORD          ' DWORD
   IsVendor        AS LONG           ' BOOL
   Flags           AS DWORD          ' DWORD
   ClassData       AS BYTE PTR       ' LPBYTE
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLASS_INFO_ARRAY DWORD
   NumElements AS DWORD                 ' DWORD
   Classes     AS DHCP_CLASS_INFO PTR   ' LPDHCP_CLASS_INFO
END TYPE

' // Serie = 28 bytes
TYPE DHCP_CLASS_INFO_V6 DWORD
   ClassName        AS WSTRINGZ PTR   ' LPWSTR
   ClassComment     AS WSTRINGZ PTR   ' LPWSTR
   ClassDataLength  AS DWORD          ' DWORD
   IsVendor         AS LONG           ' BOOL
   EnterpriseNumber AS DWORD          ' DWORD
   Flags            AS DWORD          ' DWORD
   ClassData        AS BYTE PTR       ' LPBYTE
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLASS_INFO_ARRAY_V6 DWORD
   NumElements AS DWORD                    ' DWORD
   Classes     AS DHCP_CLASS_INFO_V6 PTR   ' LPDHCP_CLASS_INFO_V6
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SERVER_SPECIFIC_STRINGS DWORD
   DefaultVendorClassName AS WSTRINGZ PTR   ' LPWSTR
   DefaultUserClassName   AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Serie = 12 bytes
TYPE DHCP_IP_RESERVATION_V4 DWORD
   ReservedIpAddress   AS DWORD                 ' DHCP_IP_ADDRESS
   ReservedForClient   AS DHCP_CLIENT_UID PTR   ' DHCP_CLIENT_UID*
   bAllowedClientTypes AS BYTE                  ' BYTE
END TYPE

' // Serie = 4 bytes
UNION DHCP_SUBNET_ELEMENT_DATA_V4_UNION
   IpRange        AS DHCP_IP_RANGE PTR            ' DHCP_IP_RANGE*
   SecondaryHost  AS DHCP_HOST_INFO PTR           ' DHCP_HOST_INFO*
   ReservedIp     AS DHCP_IP_RESERVATION_V4 PTR   ' DHCP_IP_RESERVATION_V4*
   ExcludeIpRange AS DHCP_IP_RANGE PTR            ' DHCP_IP_RANGE*
   IpUsedCluster  AS DHCP_IP_CLUSTER PTR          ' DHCP_IP_CLUSTER*
END UNION

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_DATA_V4 DWORD
   ElementType AS LONG   ' DHCP_SUBNET_ELEMENT_TYPE
   Element     AS DHCP_SUBNET_ELEMENT_DATA_V4_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_INFO_ARRAY_V4 DWORD
   NumElements AS DWORD                             ' DWORD
   Elements    AS DHCP_SUBNET_ELEMENT_DATA_V4 PTR   ' LPDHCP_SUBNET_ELEMENT_DATA_V4
END TYPE

%CLIENT_TYPE_UNSPECIFIED      = &H0
%CLIENT_TYPE_DHCP             = &H1
%CLIENT_TYPE_BOOTP            = &H2
%CLIENT_TYPE_BOTH             = %CLIENT_TYPE_DHCP OR %CLIENT_TYPE_BOOTP
%CLIENT_TYPE_RESERVATION_FLAG = &H4
%CLIENT_TYPE_NONE             = &H64

' // Serie = 48 bytes
TYPE DHCP_CLIENT_INFO_V4 DWORD
   ClientIpAddress       AS DWORD             ' DHCP_IP_ADDRESS
   SubnetMask            AS DWORD             ' DHCP_IP_MASK
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR      ' LPWSTR
   ClientComment         AS WSTRINGZ PTR      ' LPWSTR
   ClientLeaseExpires    AS DATE_TIME
   OwnerHost             AS DHCP_HOST_INFO
   bClientType           AS BYTE
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLIENT_INFO_ARRAY_V4 DWORD
   NumElements AS DWORD                     ' DWORD
   Clients     AS DHCP_CLIENT_INFO_V4 PTR   ' LPDHCP_CLIENT_INFO_V4*
END TYPE

' // Serie = 52 bytes
TYPE DHCP_SERVER_CONFIG_INFO_V4 DWORD
   APIProtocolSupport      AS DWORD          ' DWORD
   DatabaseName            AS WSTRINGZ PTR   ' LPWSTR
   DatabasePath            AS WSTRINGZ PTR   ' LPWSTR
   BackupPath              AS WSTRINGZ PTR   ' LPWSTR
   BackupInterval          AS DWORD          ' DWORD
   DatabaseLoggingFlag     AS DWORD          ' DWORD
   RestoreFlag             AS DWORD          ' DWORD
   DatabaseCleanupInterval AS DWORD          ' DWORD
   DebugFlag               AS DWORD          ' DWORD
   dwPingRetries           AS DWORD          ' DWORD // valid range: 0-5 inclusive
   cbBootTableString       AS DWORD          ' DWORD
   wszBootTableString      AS WSTRINGZ PTR   ' WCHAR*
   fAuditLog               AS LONG           ' BOOL // TRUE to enable audit log
END TYPE

'//
'// Server Configuration Info with quarantine config.
'//

' // Serie = 64 bytes
TYPE DHCP_SERVER_CONFIG_INFO_VQ DWORD
   APIProtocolSupport      AS DWORD          ' DWORD // bit map of the protocols supported.
   DatabaseName            AS WSTRINGZ PTR   ' LPWSTR // JET database name.
   DatabasePath            AS WSTRINGZ PTR   ' LPWSTR // JET database path.
   BackupPath              AS WSTRINGZ PTR   ' LPWSTR // Backup path.
   BackupInterval          AS DWORD          ' DWORD // Backup interval in mins.
   DatabaseLoggingFlag     AS DWORD          ' DWORD // Boolean database logging flag.
   RestoreFlag             AS DWORD          ' DWORD // Boolean database restore flag.
   DatabaseCleanupInterval AS DWORD          ' DWORD // Database Cleanup Interval in mins.
   DebugFlag               AS DWORD          ' DWORD // Bit map of server debug flags.
   dwPingRetries           AS DWORD          ' DWORD // valid range: 0-5 inclusive
   cbBootTableString       AS DWORD          ' DWORD
   wszBootTableString      AS WSTRINGZ PTR   ' WCHAR*
   fAuditLog               AS LONG           ' BOOL // TRUE to enable audit log
   QuarantineOn            AS LONG           ' BOOL // Server global Quarantine on/off
   QuarDefFail             AS DWORD          ' DWORD // Default behavior when IAS fails
                                             '       // to be set to QUARANTINE_DEFFAIL_ACCEPT
                                             '       // or QUARANTINE_DEFFAIL_DROP
   QuarRuntimeStatus       AS LONG           ' BOOL // This tells us whether NAP is actually running
                                             '      // on the DHCP server as opposed to the the value
                                             '      // which is configured by the admin.
END TYPE

' // Serie = 36 bytes
TYPE DHCP_SERVER_CONFIG_INFO_V6 DWORD
   UnicastFlag           AS LONG    ' BOOL
   RapidCommitFlag       AS LONG    ' BOOL
   PreferredLifetime     AS DWORD   ' DWORD
   ValidLifetime         AS DWORD   ' DWORD
   T1                    AS DWORD   ' DWORD
   T2                    AS DWORD   ' DWORD
   PreferredLifetimeIATA AS DWORD   ' DWORD
   ValidLifetimeIATA     AS DWORD   ' DWORD
   fAuditLog             AS LONG    ' BOOL
END TYPE

%Set_UnicastFlag           = &H00000001???
%Set_RapidCommitFlag       = &H00000002???
%Set_PreferredLifetime     = &H00000004???
%Set_ValidLifetime         = &H00000008???
%Set_T1                    = &H00000010???
%Set_T2                    = &H00000020???
%Set_PreferredLifetimeIATA = &H00000040???
%Set_ValidLifetimeIATA     = &H00000080???

' // Serie = 16 bytes
TYPE DHCP_SUPER_SCOPE_TABLE_ENTRY DWORD
   SubnetAddress    AS DWORD          ' DHCP_IP_ADDRESS // subnet address
   SuperScopeNumber AS DWORD          ' DWORD // super scope group number
   NextInSuperScope AS DWORD          ' DWORD // index of the next subnet in the superscope
   SuperScopeName   AS WSTRINGZ PTR   ' LPWSTR // super scope name
                                      '        // NULL indicates no superscope membership.
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SUPER_SCOPE_TABLE DWORD
   cEntries AS DWORD                              ' DWORD
   pEntries AS DHCP_SUPER_SCOPE_TABLE_ENTRY PTR   ' DHCP_SUPER_SCOPE_TABLE_ENTRY*
END TYPE

' // Serie = 48 bytes
TYPE DHCP_CLIENT_INFO_V5 WORD
   ClientIpAddress       AS DWORD             ' DHCP_IP_ADDRESS // currently assigned IP address.
   SubnetMask            AS DWORD             ' DHCP_IP_MASK
   ClientHardwareAddress AS DHCP_CLIENT_UID
   ClientName            AS WSTRINGZ PTR      ' LPWSTR // optional.
   ClientComment         AS WSTRINGZ PTR      ' LPWSTR
   ClientLeaseExpires    AS DATE_TIME         ' // UTC time in FILE_TIME format.
   OwnerHost             AS DHCP_HOST_INFO    ' // host that distributed this IP address.
   bClientType           AS BYTE              ' BYTE
   AddressState          AS BYTE              ' BYTE
END TYPE

%V5_ADDRESS_STATE_OFFERED    = &H0
%V5_ADDRESS_STATE_ACTIVE     = &H1
%V5_ADDRESS_STATE_DECLINED   = &H2
%V5_ADDRESS_STATE_DOOM       = &H3

%V5_ADDRESS_BIT_DELETED      = &H80
%V5_ADDRESS_BIT_UNREGISTERED = &H40
%V5_ADDRESS_BIT_BOTH_REC     = &H20


%DNS_FLAG_ENABLED            = &H01
%DNS_FLAG_UPDATE_DOWNLEVEL   = &H02
%DNS_FLAG_CLEANUP_EXPIRED    = &H04
%DNS_FLAG_UPDATE_BOTH_ALWAYS = &H10
%DNS_FLAG_UPDATE_DHCID       = &H20

' // Serie = 8 bytes
TYPE DHCP_CLIENT_INFO_ARRAY_V5 DWORD
   NumElements AS DWORD                     ' DWORD
   Clients     AS DHCP_CLIENT_INFO_V5 PTR   ' LPDHCP_CLIENT_INFO_V5* // array of pointers
END TYPE

%DHCP_OPT_ENUM_IGNORE_VENDOR = &H01
%DHCP_OPT_ENUM_USE_CLASSNAME = &H02

' // Serie = 12 bytes
TYPE DHCP_ALL_OPTIONS_VendorOptions DWORD
   Option     AS DHCP_OPTION
   VendorName AS WSTRINGZ PTR   ' LPWSTR
   ClassName  AS WSTRINGZ PTR   ' LPWSTR // currently unused.
END TYPE

' // Serie = 16 bytes
TYPE DHCP_ALL_OPTIONS DWORD
   Flags            AS DWORD                   ' DWORD // must be zero -- not used..
   NonVendorOptions AS DHCP_OPTION_ARRAY PTR   ' LPDHCP_OPTION_ARRAY
   NumVendorOptions AS DWORD                   ' DWORD
   VendorOptions    AS DHCP_ALL_OPTIONS_VendorOptions PTR
END TYPE

' // Serie = 16 bytes
TYPE DHCP_ALL_OPTION_VALUES_Options DWORD
   ClassName    AS WSTRINGZ PTR                  ' LPWSTR // for each user class (NULL if none exists)
   VendorName   AS WSTRINGZ PTR                  ' LPWSTR // for each vendor class (NULL if none exists)
   IsVendor     AS LONG                          ' BOOL // is this set of options vendor specific?
   OptionsArray AS DHCP_OPTION_VALUE_ARRAY PTR   ' LPDHCP_OPTION_VALUE_ARRAY // list of options for the above pair: (vendor,user)
END TYPE

' // Serie = 12 bytes
TYPE DHCP_ALL_OPTION_VALUES DWORD
   Flags       AS DWORD   ' DWORD // must be zero -- not used
   NumElements AS DWORD   ' DWORD // the # of elements in array of Options below..
   Options     AS DHCP_ALL_OPTION_VALUES_Options PTR   ' // for each vendor/user class pair, one element in this array..
END TYPE

'#ifndef     _ST_SRVR_H_
'#define     _ST_SRVR_H_

' // Serie = 28 bytes
TYPE DHCPDS_SERVER DWORD
   Version       AS DWORD          ' DWORD // version of this structure -- currently zero
   ServerName    AS WSTRINGZ PTR   ' LPWSTR // [DNS?] unique name for server
   ServerAddress AS DWORD          ' DWORD // ip address of server
   Flags         AS DWORD          ' DWORD // additional info -- state
   State         AS DWORD          ' DWORD // not used ...
   DsLocation    AS WSTRINGZ PTR   ' LPWSTR // ADsPath to server object
   DsLocType     AS DWORD          ' DWORD // path relative? absolute? diff srvr?
END TYPE

MACRO DHCP_SERVER_INFO = DHCPDS_SERVER

' // Serie = 12 bytes
TYPE DHCPDS_SERVERS DWORD
   Flags       AS DWORD               ' DWORD // not used currently.
   NumElements AS DWORD               '  DWORD // # of elements in array
   Servers     AS DHCPDS_SERVER PTR   ' LPDHCPDS_SERVER // array of server info
END TYPE

MACRO DHCP_SERVER_INFO_ARRAY = DHCPDS_SERVERS

'#endif      _ST_SRVR_H_

%DHCP_FLAGS_DONT_ACCESS_DS         = &H01???
%DHCP_FLAGS_DONT_DO_RPC            = &H02???
%DHCP_FLAGS_OPTION_IS_VENDOR       = &H03???

%DHCP_ATTRIB_BOOL_IS_ROGUE         = &H01???
%DHCP_ATTRIB_BOOL_IS_DYNBOOTP      = &H02???
%DHCP_ATTRIB_BOOL_IS_PART_OF_DSDC  = &H03???
%DHCP_ATTRIB_BOOL_IS_BINDING_AWARE = &H04???
%DHCP_ATTRIB_BOOL_IS_ADMIN         = &H05???
%DHCP_ATTRIB_ULONG_RESTORE_STATUS  = &H06???

%DHCP_ATTRIB_TYPE_BOOL             = &H01???
%DHCP_ATTRIB_TYPE_ULONG            = &H02???

'typedef     ULONG                  DHCP_ATTRIB_ID, *PDHCP_ATTRIB_ID, *LPDHCP_ATTRIB_ID;

' // Serie = 8 bytes
UNION DHCP_ATTRIB_UNION DWORD
   DhcpAttribBool  AS LONG     ' BOOL
   DhcpAttribUlong AS DWORD   ' ULONG
END UNION

' // Serie = 12 bytes
TYPE DHCP_ATTRIB DWORD
   DhcpAttribId   AS DWORD   ' DHCP_ATTRIB_ID // one of the DHCP_ATTRIB_*
   DhcpAttribType AS DWORD   ' ULONG // type of attrib
   DHCP_ATTRIB_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_ATTRIB_ARRAY DWORD
   NumElements AS DWORD             ' ULONG
   DhcpAttribs AS DHCP_ATTRIB PTR   ' DHCP_ATTRIB
END TYPE

' // Serie = 16 bytes
TYPE DHCP_BOOTP_IP_RANGE DWORD
   StartAddress    AS DWORD   ' DHCP_IP_ADDRESS
   EndAddress      AS DWORD   ' DHCP_IP_ADDRESS
   BootpAllocated  AS DWORD   ' ULONG
   MaxBootpAllowed AS DWORD   ' ULONG
END TYPE

' // Serie = 4 bytes
UNION DHCP_SUBNET_ELEMENT_DATA_V5_UNION
   IpRange        AS DHCP_BOOTP_IP_RANGE PTR      ' DHCP_BOOTP_IP_RANGE*
   SecondaryHost  AS DHCP_HOST_INFO PTR           ' DHCP_HOST_INFO*
   ReservedIp     AS DHCP_IP_RESERVATION_V4 PTR   ' DHCP_IP_RESERVATION_V4*
   ExcludeIpRange AS DHCP_IP_RANGE PTR            ' DHCP_IP_RANGE*
END UNION

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_DATA_V5 DWORD
   ElementType AS LONG
   Element     AS DHCP_SUBNET_ELEMENT_DATA_V5_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_INFO_ARRAY_V5 DWORD
   NumElements AS DWORD                             ' DWORD
   Elements    AS DHCP_SUBNET_ELEMENT_DATA_V5 PTR   ' LPDHCP_SUBNET_ELEMENT_DATA_V5 //array
END TYPE

'#pragma     pack(4)

' // Serie = 76 bytes
TYPE DHCP_PERF_STATS DWORD  ' // performance statistics
   ' // DO NOT CHANGE THIS ORDER -- THIS AFFECTS THE PERF COUNTER DEFINITION
   ' // ORDER IN DHCPDATA.C (under PERF directory)
   dwNumPacketsReceived            AS DWORD   ' ULONG
   dwNumPacketsDuplicate           AS DWORD   ' ULONG
   dwNumPacketsExpired             AS DWORD   ' ULONG
   dwNumMilliSecondsProcessed      AS DWORD   ' ULONG
   dwNumPacketsInActiveQueue       AS DWORD   ' ULONG
   dwNumPacketsInPingQueue         AS DWORD   ' ULONG

   dwNumDiscoversReceived          AS DWORD   ' ULONG
   dwNumOffersSent                 AS DWORD   ' ULONG

   dwNumRequestsReceived           AS DWORD   ' ULONG
   dwNumInformsReceived            AS DWORD   ' ULONG
   dwNumAcksSent                   AS DWORD   ' ULONG
   dwNumNacksSent                  AS DWORD   ' ULONG

   dwNumDeclinesReceived           AS DWORD   ' ULONG
   dwNumReleasesReceived           AS DWORD   ' ULONG

   ' // Count of Delayed Offer sent
   dwNumDelayedOfferInQueue        AS DWORD   ' ULONG
   dwNumPacketsProcessed           AS DWORD   ' ULONG

   ' // For Quarantine
   dwNumPacketsInQuarWaitingQueue  AS DWORD   ' ULONG
   dwNumPacketsInQuarReadyQueue    AS DWORD   ' ULONG
   dwNumPacketsInQuarDecisionQueue AS DWORD   ' ULONG
END TYPE

'#pragma     pack()

%DHCP_ENDPOINT_FLAG_CANT_MODIFY = &H01???

' // Serie = 28 bytes
TYPE DHCP_BIND_ELEMENT DWORD
   Flags                 AS DWORD          ' ULONG
   fBoundToDHCPServer    AS LONG           ' BOOL
   AdapterPrimaryAddress AS DWORD          ' DHCP_IP_ADDRESS
   AdapterSubnetAddress  AS DWORD          ' DHCP_IP_ADDRESS
   IfDescription         AS WSTRINGZ PTR   ' LPWSTR
   IfIdSize              AS DWORD          ' ULONG
   IfId                  AS BYTE PTR       ' LPBYTE
END TYPE

' // Serie = 8 bytes
TYPE DHCP_BIND_ELEMENT_ARRAY DWORD
   NumElements AS DWORD                   ' DWORD
   Elements    AS DHCP_BIND_ELEMENT PTR   ' LPDHCP_BIND_ELEMENT //array
END TYPE

' // Serie = 56 bytes
TYPE DHCPV6_BIND_ELEMENT DWORD
   Flags                 AS DWORD               ' ULONG
   fBoundToDHCPServer    AS LONG                ' BOOL
   AdapterPrimaryAddress AS DHCP_IPV6_ADDRESS
   AdapterSubnetAddress  AS DHCP_IPV6_ADDRESS
   IfDescription         AS WSTRINGZ PTR        ' LPWSTR
   IpV6IfIndex           AS DWORD               ' DWORD
   IfIdSize              AS DWORD               ' ULONG
   IfId                  AS BYTE PTR            ' LPBYTE
END TYPE

' // Serie = 8 bytes
TYPE DHCPV6_BIND_ELEMENT_ARRAY DWORD
   NumElements AS DWORD                     ' DWORD
   Elements    AS DHCPV6_BIND_ELEMENT PTR   ' LPDHCPV6_BIND_ELEMENT //array
END TYPE

'//
'// For Quarantine
'//

%QUARANTIN_OPTION_BASE = 43220
%QUARANTINE_SCOPE_QUARPROFILE_OPTION = %QUARANTIN_OPTION_BASE + 1
%QUARANTINE_CONFIG_OPTION = %QUARANTIN_OPTION_BASE + 2

'// DHCP IPV6 specific Structures

' // Serie = 32 bytes
TYPE DHCP_IP_RANGE_V6 QWORD
   StartAddress AS DHCP_IPV6_ADDRESS
   EndAddress   AS DHCP_IPV6_ADDRESS
END TYPE

' // Serie = 24 bytes
TYPE DHCP_HOST_INFO_V6 DWORD
   IpAddress   AS DHCP_IPV6_ADDRESS   ' DHCP_IPV6_ADDRESS // minimum information always available
   NetBiosName AS WSTRINGZ PTR        ' LPWSTR // optional information
   HostName    AS WSTRINGZ PTR        ' LPWSTR // optional information
END TYPE

' // Serie = 40 bytes
TYPE DHCP_SUBNET_INFO_V6 DWORD
   SubnetAddress AS DHCP_IPV6_ADDRESS
   Prefix        AS DWORD          ' ULONG
   Preference    AS WORD           ' USHORT
   SubnetName    AS WSTRINGZ PTR   ' LPWSTR
   SubnetComment AS WSTRINGZ PTR   ' LPWSTR
   State         AS DWORD          ' DWORD
   ScopeId       AS DWORD          ' DWORD
END TYPE

'//
'// Mib Info structures.
'//

' // Serie = 40 bytes
TYPE SCOPE_MIB_INFO_V6 QWORD
   Subnet               AS DHCP_IPV6_ADDRESS
   NumAddressesInuse    AS QUAD   ' ULONGLONG
   NumAddressesFree     AS QUAD   ' ULONGLONG
   NumPendingAdvertises AS QUAD   ' ULONGLONG
END TYPE

' // Serie = 56 bytes
TYPE DHCP_MIB_INFO_V6 DWORD
   Solicits        AS DWORD             ' DWORD
   Advertises      AS DWORD             ' DWORD
   Requests        AS DWORD             ' DWORD
   Renews          AS DWORD             ' DWORD
   Rebinds         AS DWORD             ' DWORD
   Replies         AS DWORD             ' DWORD
   Confirms        AS DWORD             ' DWORD
   Declines        AS DWORD             ' DWORD
   Releases        AS DWORD             ' DWORD
   Informs         AS DWORD             ' DWORD
   ServerStartTime AS DATE_TIME
   Scopes          AS DWORD             ' DWORD
   ScopeInfo AS SCOPE_MIB_INFO_V6 PTR   ' LPSCOPE_MIB_INFO_V6 // array.
END TYPE

' // Serie = 24 bytes
TYPE DHCP_IP_RESERVATION_V6 DWORD
   ReservedIpAddress AS DHCP_IPV6_ADDRESS
   ReservedForClient AS DHCP_CLIENT_UID PTR   ' DHCP_CLIENT_UID*
   InterfaceId       AS DWORD                 ' DWORD
END TYPE

' enum DHCP_SUBNET_ELEMENT_TYPE_V6
%Dhcpv6IpRanges         = 0
%Dhcpv6ReservedIps      = 1
%Dhcpv6ExcludedIpRanges = 2

' // Serie = 4 bytes
UNION DHCP_SUBNET_ELEMENT_DATA_V6_UNION
   IpRange        AS DHCP_IP_RANGE_V6 PTR         ' DHCP_IP_RANGE_V6*
   ReservedIp     AS DHCP_IP_RESERVATION_V6 PTR   ' DHCP_IP_RESERVATION_V6*
   ExcludeIpRange AS DHCP_IP_RANGE_V6 PTR         ' DHCP_IP_RANGE_V6*
END UNION

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_DATA_V6 DWORD
   ElementType AS LONG   ' DHCP_SUBNET_ELEMENT_TYPE_V6
   Element AS DHCP_SUBNET_ELEMENT_DATA_V6_UNION
END TYPE

' // Serie = 8 bytes
TYPE DHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 DWORD
   NumElements AS DWORD                             ' DWORD
   Elements    AS DHCP_SUBNET_ELEMENT_DATA_V6 PTR   ' LPDHCP_SUBNET_ELEMENT_DATA_V6 //array
END TYPE

'//
'// DHCPv6 Client information data structures
'//

%ADDRESS_TYPE_IANA = 0
%ADDRESS_TYPE_IATA = 1

' // Serie = 80 bytes
TYPE DHCP_CLIENT_INFO_V6 DWORD
   ClientIpAddress         AS DHCP_IPV6_ADDRESS   ' DHCP_IPV6_ADDRESS // currently assigned IP address.
   ClientDUID              AS DHCP_CLIENT_UID     ' DHCP_CLIENT_UID
   AddressType             AS DWORD               ' DWORD // IANA or IATA
   IAID                    AS DWORD               ' DWORD // IAID Associated with the address.
   ClientName              AS WSTRINGZ PTR        ' LPWSTR // optional.
   ClientComment           AS WSTRINGZ PTR        ' LPWSTR
   ClientValidLeaseExpires AS DATE_TIME           ' DATE_TIME // UTC time in FILE_TIME format.
   ClientPrefLeaseExpires  AS DATE_TIME           ' DATE_TIME // UTC time in FILE_TIME format.
   OwnerHost               AS DHCP_HOST_INFO_V6   ' DHCP_HOST_INFO_V6 // host that distributed this IP address.
END TYPE

' // Serie = 8 bytes
TYPE DHCPV6_IP_ARRAY DWORD
   NumElements AS DWORD                   ' DWORD
   Elements    AS DHCP_IPV6_ADDRESS PTR   ' LPDHCP_IPV6_ADDRESS //array
END TYPE

' // Serie = 8 bytes
TYPE DHCP_CLIENT_INFO_ARRAY_V6 DWORD
   NumElements AS DWORD                     ' DWORD
   Clients     AS DHCP_CLIENT_INFO_V6 PTR   ' LPDHCP_CLIENT_INFO_V6* // array of pointers
END TYPE

' enum _DHCP_CLIENT_SEARCH_TYPE_V6 alias DHCP_SEARCH_INFO_TYPE_V6
%Dhcpv6ClientIpAddress = 0
%Dhcpv6ClientDUID      = 1
%Dhcpv6ClientName      = 2

' // Serie = 16 bytes
UNION DHCP_CLIENT_SEARCH_UNION_V6 QWORD
   ClientIpAddress AS DHCP_IPV6_ADDRESS
   ClientDUID      AS DHCP_CLIENT_UID
   ClientName      AS WSTRINGZ PTR   ' LPWSTR
END UNION

' // Serie = 24 bytes
TYPE DHCP_CLIENT_SEARCH_INFO_V6 QWORD
   SearchType AS LONG   ' DHCP_SEARCH_INFO_TYPE_V6
   SearchInfo AS DHCP_CLIENT_SEARCH_UNION_V6
END TYPE

MACRO DHCP_SEARCH_INFO_V6 = DHCP_CLIENT_SEARCH_INFO_V6

%SCOPE_STATE_ENABLED  = %DhcpSubnetEnabled
%SCOPE_STATE_DISABLED = %DhcpSubnetDisabled

%DHCP_MIN_DELAY = 0
%DHCP_MAX_DELAY = 1000

' // Not included in dhcpsapi.h, but should be.
%ERROR_DHCP_OPTION_NOT_PRESENT   = 20010???
%ERROR_DHCP_SUBNET_EXISTS        = 20052???
%ERROR_DDS_SERVER_ALREADY_EXISTS = 20079???
%ERROR_DDS_SERVER_DOES_NOT_EXIST = 20080???

'#ifndef  DHCPAPI_NO_PROTOTYPES

'//
'// DHCP Filter related APIs
'//

DECLARE FUNCTION DhcpAddFilterV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddFilterV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF AddFilterInfo AS DHCP_FILTER_ADD_INFO _        ' __in DHCP_FILTER_ADD_INFO *AddFilterInfo
 , BYVAL ForceFlag AS LONG _                            ' __in BOOL ForceFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteFilterV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteFilterV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF DeleteFilterInfo AS DHCP_ADDR_PATTERN _        ' __in DHCP_ADDR_PATTERN *DeleteFilterInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetFilterV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetFilterV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF GlobalFilterInfo AS DHCP_FILTER_GLOBAL_INFO _  ' __in DHCP_FILTER_GLOBAL_INFO *GlobalFilterInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetFilterV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetFilterV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF GlobalFilterInfo AS DHCP_FILTER_GLOBAL_INFO _  ' __out DHCP_FILTER_GLOBAL_INFO *GlobalFilterInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumFilterV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumFilterV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF ResumeHandle AS DHCP_ADDR_PATTERN _            ' __inout LPDHCP_ADDR_PATTERN ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ListType AS LONG _                             ' __in DHCP_FILTER_LIST_TYPE ListType
 , BYREF EnumFilterInfo AS DHCP_FILTER_ENUM_INFO _      ' __out LPDHCP_FILTER_ENUM_INFO *EnumFilterInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

'//
'// Subnet APIs
'//

DECLARE FUNCTION DhcpCreateSubnet IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateSubnet" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO _               ' __in DHCP_CONST DHCP_SUBNET_INFO * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetSubnetInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetSubnetInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO _               ' __in DHCP_CONST DHCP_SUBNET_INFO * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetSubnetInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetSubnetInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO _               ' __out LPDHCP_SUBNET_INFO * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnets IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnets" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ResumeHandle AS DWORD _                        ' __in_out DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumInfo AS DHCP_CLIENT_INFO_ARRAY _           ' __out LPDHCP_IP_ARRAY *EnumInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAddSubnetElement IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddSubnetElement" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF AddElementInfo AS DHCP_SUBNET_ELEMENT_DATA _   ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA * AddElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetElements IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetElements" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL EnumElementType AS LONG _                      ' __in DHCP_SUBNET_ELEMENT_TYPE EnumElementType
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumElementInfo AS DHCP_SUBNET_ELEMENT_INFO_ARRAY _ ' __out LPDHCP_SUBNET_ELEMENT_INFO_ARRAY *EnumElementInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveSubnetElement IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveSubnetElement" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF RemoveElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V5 _ ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V5 * RemoveElementInfo
 , BYVAL ForceFlag AS LONG _                            ' __in DHCP_FORCE_FLAG ForceFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteSubnet IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteSubnet" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL ForceFlag AS LONG _                            ' __in DHCP_FORCE_FLAG ForceFlag
 ) AS DWORD                                             ' DWORD

'//
'// Option APIs
'//

DECLARE FUNCTION DhcpCreateOption IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateOption" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in DHCP_CONST DHCP_OPTION *OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in DHCP_CONST DHCP_OPTION *OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __out LPDHCP_OPTION *OptionInfo // allocate memory using MIDL functions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptions IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptions" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle // must be zero intially and then never touched
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum // max # of bytes of info to pass along
 , BYREF Options AS DHCP_OPTION_ARRAY _                 ' __out LPDHCP_OPTION_ARRAY *Options // fill this option array
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead // fill in the # of options read
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal  // fill in the total # here
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOption IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOption" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionValue IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionValue" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in DHCP_CONST DHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF OptionValue AS DHCP_OPTION_DATA _              ' __in DHCP_CONST DHCP_OPTION_DATA OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionValues IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionValues" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in HCP_CONST WCHAR *ServerIpAddress
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in DHCP_CONST DHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF OptionValues AS DHCP_OPTION_VALUE_ARRAY _      ' __out DHCP_CONST DHCP_OPTION_VALUE_ARRAY *OptionValues
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionValue IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionValue" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo
 , BYREF OptionValue AS DHCP_OPTION_VALUE _             ' __out LPDHCP_OPTION_VALUE *OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptionValues IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptionValues" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in DHCP_CONST DHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF OptionValues AS DHCP_OPTION_VALUE_ARRAY _      ' __out LPDHCP_OPTION_VALUE_ARRAY *OptionValues
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOptionValue IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOptionValue" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in DHCP_CONST DHCP_OPTION_SCOPE_INFO *ScopeInfo
 ) AS DWORD                                             ' DWORD

'//
'// Client APIs
'//

DECLARE FUNCTION DhcpCreateClientInfoVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateClientInfoVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_VQ _            ' __in DHCP_CONST DHCP_CLIENT_INFO_VQ *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetClientInfoVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetClientInfoVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_VQ _            ' __in DHCP_CONST DHCP_CLIENT_INFO_VQ *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClientInfoVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClientInfoVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYREF SearchInfo AS DHCP_SEARCH_INFO _               ' __in DHCP_CONST DHCP_SEARCH_INFO *SearchInfo
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_VQ _            ' __in DHCP_CONST DHCP_CLIENT_INFO_VQ *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClientsVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClientsVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY_VQ _      ' __out LPDHCP_CLIENT_INFO_ARRAY_VQ *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClientsFilterStatusInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClientsFilterStatusInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY _         ' __out LPDHCP_CLIENT_INFO_ARRAY *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateClientInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateClientInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO _               ' __in DHCP_CONST DHCP_CLIENT_INFO *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetClientInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetClientInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO _               ' __in DHCP_CONST DHCP_CLIENT_INFO *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClientInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClientInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SearchInfo AS DHCP_SEARCH_INFO _               ' __in DHCP_CONST DHCP_SEARCH_INFO *SearchInfo
 , BYREF ClientInfo AS DHCP_CLIENT_INFO _               ' __out LPDHCP_CLIENT_INFO *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteClientInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteClientInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_SEARCH_INFO _               ' __in DHCP_CONST DHCP_SEARCH_INFO *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClients IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClients" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __in_out DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY _         ' __out LPDHCP_CLIENT_INFO_ARRAY *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClientOptions IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClientOptions" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL ClientIpAddress AS DWORD _                     ' __in DHCP_IP_ADDRESS ClientIpAddress
 , BYVAL ClientSubnetMask AS DWORD _                    ' __in DHCP_IP_MASK ClientSubnetMask
 , BYREF ClientOptions AS DHCP_OPTION_LIST _            ' __out LPDHCP_OPTION_LIST *ClientOptions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetMibInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetMibInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF MibInfo AS DHCP_MIB_INFO _                     ' __out LPDHCP_MIB_INFO *MibInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerSetConfig IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetConfig" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL FieldsToSet AS DWORD _                         ' __in DWORD FieldsToSet
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO _        ' __in LPDHCP_SERVER_CONFIG_INFO ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerGetConfig IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerGetConfig" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO _        ' __out LPDHCP_SERVER_CONFIG_INFO *ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpScanDatabase IMPORT "Dhcpsapi.dll" ALIAS "DhcpScanDatabase" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL FixFlag AS DWORD _                             ' __in DWORD FixFlag
 , BYREF ScanList AS DHCP_SCAN_LIST _                   ' __out LPDHCP_SCAN_LIST *ScanList
 ) AS DWORD                                             ' DWORD

DECLARE SUB DhcpRpcFreeMemory IMPORT "Dhcpsapi.dll" ALIAS "DhcpRpcFreeMemory" ( _
   BYVAL BufferPointer AS DWORD _                       ' __in PVOID BufferPointer
 )                                                      ' void

DECLARE FUNCTION DhcpGetVersion IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetVersion" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYREF MajorVersion AS DWORD _                        ' __out LPDWORD MajorVersion
 , BYREF MinorVersion AS DWORD _                        ' __out LPDWORD MinorVersion
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAddSubnetElementV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddSubnetElementV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF AddElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V4 _ ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V4 * AddElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetElementsV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetElementsV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL EnumElementType AS LONG _                      ' __in DHCP_SUBNET_ELEMENT_TYPE EnumElementType
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumElementInfo AS DHCP_SUBNET_ELEMENT_INFO_ARRAY_V4 _ ' __out LPDHCP_SUBNET_ELEMENT_INFO_ARRAY_V4 *EnumElementInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveSubnetElementV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveSubnetElementV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF RemoveElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V4 _ ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V4 * RemoveElementInfo
 , BYVAL ForceFlag AS LONG _                            ' __in DHCP_FORCE_FLAG ForceFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateClientInfoV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateClientInfoV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V4 _            ' __in DHCP_CONST DHCP_CLIENT_INFO_V4 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetClientInfoV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetClientInfoV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V4 _            ' __in DHCP_CONST DHCP_CLIENT_INFO_V4 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClientInfoV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClientInfoV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SearchInfo AS DHCP_SEARCH_INFO _               ' __in DHCP_CONST DHCP_SEARCH_INFO *SearchInfo
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V4 _            ' __out LPDHCP_CLIENT_INFO_V4 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClientsV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClientsV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __in_out DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY_V4 _      ' __out LPDHCP_CLIENT_INFO_ARRAY_V4 *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerSetConfigV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetConfigV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL FieldsToSet AS DWORD _                         ' __in DWORD FieldsToSet
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_V4 _     ' __in LPDHCP_SERVER_CONFIG_INFO_V4 ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerGetConfigV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerGetConfigV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_V4 _     ' __out LPDHCP_SERVER_CONFIG_INFO_V4 *ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetSuperScopeV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetSuperScopeV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_CONST DHCP_IP_ADDRESS SubnetAddress
 , BYREF SuperScopeName AS WSTRINGZ _                   ' __in_opt DHCP_CONST LPWSTR SuperScopeName
 , BYVAL ChangeExisting AS LONG _                       ' __in DHCP_CONST BOOL ChangeExisting
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteSuperScopeV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteSuperScopeV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SuperScopeName AS WSTRINGZ _                   ' __in_opt DHCP_CONST LPWSTR SuperScopeName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetSuperScopeInfoV4 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetSuperScopeInfoV4" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SuperScopeTable AS DHCP_SUPER_SCOPE_TABLE _    ' __out LPDHCP_SUPER_SCOPE_TABLE *SuperScopeTable
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClientsV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClientsV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __in_out DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY_V5 _      ' __out LPDHCP_CLIENT_INFO_ARRAY_V5 *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateOptionV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateOptionV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in DHCP_CONST DHCP_OPTION *OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionInfoV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionInfoV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in LPDHCP_OPTION OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionInfoV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionInfoV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __out LPDHCP_OPTION *OptionInfo // allocate memory using MIDL functions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptionsV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptionsV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF Options AS DHCP_OPTION_ARRAY _                 ' __out LPDHCP_OPTION_ARRAY *Options
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOptionV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOptionV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionValueV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionValueV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in LPDHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYVAL OptionValue AS LONG _                          ' __in LPDHCP_OPTION_DATA OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionValuesV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionValuesV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in LPDHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF OptionValues AS DHCP_OPTION_VALUE_ARRAY _      ' __in LPDHCP_OPTION_VALUE_ARRAY OptionValues
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionValueV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionValueV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in LPDHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF OptionValue AS DHCP_OPTION_VALUE _             ' __out LPDHCP_OPTION_VALUE OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionValueV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionValueV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYREF OptionValue AS DHCP_OPTION_VALUE _             ' __out LPDHCP_OPTION_VALUE OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptionValuesV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptionValuesV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in LPDHCP_OPTION_SCOPE_INFO ScopeInfo
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF OptionValues AS DHCP_OPTION_VALUE_ARRAY _      ' __out LPDHCP_OPTION_VALUE_ARRAY *OptionValues
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOptionValueV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOptionValueV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO _          ' __in LPDHCP_OPTION_SCOPE_INFO ScopeInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateClass IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateClass" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassInfo AS DHCP_CLASS_INFO _                 ' __in LPDHCP_CLASS_INFO ClassInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpModifyClass IMPORT "Dhcpsapi.dll" ALIAS "DhcpModifyClass" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassInfo AS DHCP_CLASS_INFO _                 ' __in LPDHCP_CLASS_INFO ClassInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteClass IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteClass" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassName AS WSTRINGZ _                        ' __in LPWSTR ClassName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClassInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClassInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF PartialClassInfo AS DHCP_CLASS_INFO _          ' __in LPDHCP_CLASS_INFO PartialClassInfo
 , BYREF FilledClassInfo AS DHCP_CLASS_INFO _           ' __out LPDHCP_CLASS_INFO *FilledClassInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumClasses IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumClasses" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClassInfoArray AS DHCP_CLASS_INFO_ARRAY _      ' __out LPDHCP_CLASS_INFO_ARRAY *ClassInfoArray
 , BYREF nRead AS DWORD _                               ' __out DWORD *nRead
 , BYREF nTotal AS DWORD _                              ' __out DWORD *nTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetAllOptions IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetAllOptions" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags // what do we care about vendor/classid stuff?
 , BYREF OptionStruct AS DHCP_ALL_OPTIONS _             ' __out LPDHCP_ALL_OPTIONS *OptionStruct // fill the fields of this structure
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetAllOptionsV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetAllOptionsV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags // what do we care about vendor/classid stuff?
 , BYREF OptionStruct AS DHCP_ALL_OPTIONS _             ' __out LPDHCP_ALL_OPTIONS *OptionStruct // fill the fields of this structure
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetAllOptionValues IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetAllOptionValues" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYREF Values AS DHCP_ALL_OPTION_VALUES _             ' __out LPDHCP_ALL_OPTION_VALUES *Values
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetAllOptionValuesV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetAllOptionValuesV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYREF Values AS DHCP_ALL_OPTION_VALUES _             ' __out LPDHCP_ALL_OPTION_VALUES *Values
 ) AS DWORD                                             ' DWORD

'//DOC DhcpEnumServers enumerates the list of servers found in the DS.  If the DS
'//DOC is not accessible, it returns an error. The only currently used parameter
'//DOC is the out parameter Servers.  This is a SLOW call.
DECLARE FUNCTION DhcpEnumServers IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumServers" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD Flags // must be zero
 , BYVAL IdInfo AS DWORD _                              ' __in  LPVOID IdInfo // must be NULL
 , BYREF Servers AS DHCP_SERVER_INFO_ARRAY _            ' __out LPDHCP_SERVER_INFO_ARRAY *Servers // output servers list
 , BYVAL CallbackFn AS DWORD _                          ' __in  LPVOID CallbackFn // must be NULL
 , BYVAL CallbackData AS DWORD _                        ' __in  LPVOID CallbackData // must be NULL
 ) AS DWORD                                             ' DWORD

'//DOC DhcpAddServer tries to add a new server to the existing list of servers in
'//DOC the DS. The function returns error if the Server already exists in the DS.
'//DOC The function tries to upload the server configuration to the DS..
'//DOC This is a SLOW call.  Currently, the DsLocation and DsLocType are not valid
'//DOC fields in the NewServer and they'd be ignored. Version must be zero.
DECLARE FUNCTION DhcpAddServer IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddServer" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // must be zero
 , BYVAL IdInfo AS DWORD _                              ' __in LPVOID IdInfo // must be NULL
 , BYREF NewServer AS DHCP_SERVER_INFO _                ' __in LPDHCP_SERVER_INFO NewServer // input server information
 , BYVAL CallbackFn AS DWORD _                          ' __in LPVOID CallbackFn // must be NULL
 , BYVAL CallbackData AS DWORD _                        ' __in LPVOID CallbackData // must be NULL
 ) AS DWORD                                             ' DWORD

'//DOC DhcpDeleteServer tries to delete the server from DS. It is an error if the
'//DOC server does not already exist.  This also deletes any objects related to
'//DOC this server in the DS (like subnet, reservations etc.).
DECLARE FUNCTION DhcpDeleteServer IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteServer" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // must be zero
 , BYVAL IdInfo AS DWORD _                              ' __in LPVOID IdInfo // must be NULL
 , BYREF NewServer AS DHCP_SERVER_INFO _                ' __in LPDHCP_SERVER_INFO NewServer    // input server information
 , BYVAL CallbackFn AS DWORD _                          ' __in LPVOID CallbackFn // must be NULL
 , BYVAL CallbackData AS DWORD _                        ' __in LPVOID CallbackData // must be NULL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetServerBindingInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetServerBindingInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF BindElementInfo AS DHCP_BIND_ELEMENT_ARRAY _   ' __in LPDHCP_BIND_ELEMENT_ARRAY *BindElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetServerBindingInfo IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetServerBindingInfo" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF BindElementInfo AS DHCP_BIND_ELEMENT_ARRAY _   ' __in LPDHCP_BIND_ELEMENT_ARRAY BindElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAddSubnetElementV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddSubnetElementV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF AddElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V5 _ ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V5 * AddElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetElementsV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetElementsV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL EnumElementType AS LONG _                      ' __in DHCP_SUBNET_ELEMENT_TYPE EnumElementType
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumElementInfo AS DHCP_SUBNET_ELEMENT_INFO_ARRAY_V5 _ ' __out LPDHCP_SUBNET_ELEMENT_INFO_ARRAY_V5 *EnumElementInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveSubnetElementV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveSubnetElementV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF RemoveElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V5 _ ' __in DHCP_CONST DHCP_SUBNET_ELEMENT_DATA_V5 * RemoveElementInfo
 ) AS DWORD                                             ' DWORD

'//V6 Api's

DECLARE FUNCTION DhcpCreateOptionV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateOptionV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionId AS DWORD _                            ' __in DHCP_OPTION_ID OptionId // must be between 0-255 or 256-511 (for vendor stuff)
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in LPDHCP_OPTION OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOptionV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOptionV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptionsV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptionsV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle // must be zero intially and then never touched
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum // max # of bytes of info to pass along
 , BYREF Options AS DHCP_OPTION_ARRAY _                 ' __out LPDHCP_OPTION_ARRAY *Options // fill this option array
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead // fill in the # of options read
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal  // fill in the total # here
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveOptionValueV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveOptionValueV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetOptionInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetOptionInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __out LPDHCP_OPTION *OptionInfo // allocate memory using MIDL functions
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF OptionInfo AS DHCP_OPTION _                    ' __in LPDHCP_OPTION OptionInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetOptionValueV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetOptionValueV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL OptionID AS DWORD _                            ' __in DHCP_OPTION_ID OptionID
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYVAL OptionValue AS LONG _                          ' __in LPDHCP_OPTION_DATA OptionValue
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetSubnetInfoVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetSubnetInfoVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_VQ _            ' __out LPDHCP_SUBNET_INFO_VQ * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateSubnetVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateSubnetVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_VQ _            ' __in DHCP_CONST DHCP_SUBNET_INFO_VQ * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetSubnetInfoVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetSubnetInfoVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_VQ _            ' __in DHCP_CONST DHCP_SUBNET_INFO_VQ * SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumOptionValuesV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumOptionValuesV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassName AS WSTRINGZ _                        ' __in_opt LPWSTR ClassName
 , BYREF VendorName AS WSTRINGZ _                       ' __in_opt LPWSTR VendorName
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF OptionValues AS DHCP_OPTION_VALUE_ARRAY _      ' __out LPDHCP_OPTION_VALUE_ARRAY *OptionValues
 , BYREF OptionsRead AS DWORD _                         ' __out DWORD *OptionsRead
 , BYREF OptionsTotal AS DWORD _                        ' __out DWORD *OptionsTotal
 ) AS DWORD                                             ' DWORD

'#ENDIF   ' DHCPAPI_NO_PROTOTYPES

'//DOC DhcpDsInit must be called exactly once per process.. this initializes the
'//DOC memory and other structures for this process.  This initializes some DS
'//DOC object handles (memory), and hence is slow as this has to read from DS.
DECLARE FUNCTION DhcpDsInit IMPORT "Dhcpsapi.dll" ALIAS "DhcpDsInit" ( _
 ) AS DWORD                                             ' DWORD

'//DOC DhcpDsCleanup undoes the effect of any DhcpDsInit.  This function should be
'//DOC called exactly once for each process, and only at termination.  Note that
'//DOC it is safe to call this function even if DhcpDsInit does not succeed.
DECLARE SUB DhcpDsCleanup IMPORT "Dhcpsapi.dll" ALIAS "DhcpDsCleanup" ( _
 )                                                      ' VOID

DECLARE FUNCTION DhcpSetThreadOptions IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetThreadOptions" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // options, currently 0 or DHCP_FLAGS_DONT_ACCESS_DS
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // must be NULL, reserved for future
 ) AS DWORD                                             ' DWORD

'//DOC DhcpGetThreadOptions retrieves the current thread options as set by DhcpSetThreadOptions.
'//DOC If none were set, the return value is zero.
DECLARE FUNCTION DhcpGetThreadOptions IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetThreadOptions" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // this DWORD is filled with current optiosn..
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // must be NULL, reserved for future
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerQueryAttribute IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerQueryAttribute" ( _
   BYREF ServerIpAddr AS WSTRINGZ _                     ' __in_opt LPWSTR ServerIpAddr // String form of server IP
 , BYVAL dwReserved AS DWORD _                          ' __in ULONG dwReserved // reserved for future
 , BYVAL DhcpAttribId AS DWORD _                        ' __in DHCP_ATTRIB_ID DhcpAttribId // the attrib being queried
 , BYREF pDhcpAttrib AS DWORD _                         ' __out LPDHCP_ATTRIB *pDhcpAttrib // fill in this field
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerQueryAttributes IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerQueryAttributes" ( _
   BYREF ServerIpAddr AS WSTRINGZ _                     ' __in_opt LPWSTR ServerIpAddr // String form of server IP
 , BYVAL dwReserved AS DWORD _                          ' __in ULONG dwReserved // reserved for future
 , BYVAL dwAttribCount AS DWORD _                       ' __in ULONG dwAttribCount // # of attribs being queried
 , BYREF pDhcpAttribs AS DWORD _                        ' __in DHCP_ATTRIB_ID pDhcpAttribs[] // array of attribs
 , BYREF pDhcpAttribArr AS DHCP_ATTRIB_ARRAY _          ' __out LPDHCP_ATTRIB_ARRAY *pDhcpAttribArr // Ptr is filled w/ array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerRedoAuthorization IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerRedoAuthorization" ( _
   BYREF ServerIpAddr AS WSTRINGZ _                     ' __in_opt LPWSTR ServerIpAddr // String form of server IP
 , BYVAL dwReserved AS DWORD _                          ' __in ULONG  dwReserved   // reserved for future
 ) AS DWORD                                             ' DWORD // Status code

DECLARE FUNCTION DhcpAuditLogSetParams IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerRedoAuthorization" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress // String form of server IP
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags // currently must be zero
 , BYREF AuditLogDir AS WSTRINGZ _                      ' __in_opt LPWSTR AuditLogDir // directory to log files in..
 , BYVAL DiskCheckInterval AS DWORD _                   ' __in DWORD DiskCheckInterval // how often to check disk space?
 , BYVAL MaxLogFilesSize AS DWORD _                     ' __in DWORD MaxLogFilesSize // how big can all logs files be..
 , BYVAL MinSpaceOnDisk AS DWORD _                      ' __in DWORD MinSpaceOnDisk // mininum amt of free disk space
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAuditLogGetParams IMPORT "Dhcpsapi.dll" ALIAS "DhcpAuditLogGetParams" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF AuditLogDir AS DWORD _                         ' __out_opt LPWSTR *AuditLogDir
 , BYREF DiskCheckInterval AS DWORD _                   ' __out DWORD *DiskCheckInterval
 , BYREF MaxLogFilesSize AS DWORD _                     ' __out DWORD *MaxLogFilesSize
 , BYREF MinSpaceOnDisk AS DWORD _                      ' __out DWORD *MinSpaceOnDisk
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerQueryDnsRegCredentials IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerQueryDnsRegCredentials" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL UnameSize AS DWORD _                           ' __in ULONG UnameSize //in BYTES
 , BYREF Uname AS WSTRINGZ _                            ' __out LPWSTR Uname
 , BYVAL DomainSize AS DWORD _                          ' __in ULONG DomainSize // in BYTES
 , BYREF Domain AS WSTRINGZ _                           ' __out LPWSTR Domain
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerSetDnsRegCredentials IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetDnsRegCredentials" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYREF Uname AS WSTRINGZ _                            ' __in_opt LPWSTR Uname
 , BYREF Domain AS WSTRINGZ _                           ' __in_opt LPWSTR Domain
 , BYREF Passwd AS WSTRINGZ _                           ' __in_opt LPWSTR Passwd
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerSetDnsRegCredentialsV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetDnsRegCredentialsV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYREF Uname AS WSTRINGZ _                            ' __in_opt LPWSTR Uname
 , BYREF Domain AS WSTRINGZ _                           ' __in_opt LPWSTR Domain
 , BYREF Passwd AS WSTRINGZ _                           ' __in_opt LPWSTR Passwd
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerBackupDatabase IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerBackupDatabase" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Path AS DWORD _                                ' __in LPWSTR Path
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerRestoreDatabase IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerRestoreDatabase" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL Path AS DWORD _                                ' __in LPWSTR Path
 ) AS DWORD                                             ' DWORD

'//
'//  All Quarantine related APIs
'//

DECLARE FUNCTION DhcpServerSetConfigVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetConfigVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYVAL FieldsToSet AS DWORD _                         ' __in DWORD FieldsToSet
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_VQ _     ' __in LPDHCP_SERVER_CONFIG_INFO_VQ ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerGetConfigVQ IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerGetConfigVQ" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_VQ _     ' __in LPDHCP_SERVER_CONFIG_INFO_VQ *ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetServerSpecificStrings IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetServerSpecificStrings" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR ServerIpAddress
 , BYREF ServerSpecificStrings AS DHCP_SERVER_SPECIFIC_STRINGS _ ' __in LPDHCP_SERVER_SPECIFIC_STRINGS *ServerSpecificStrings
 ) AS DWORD                                             ' DWORD

DECLARE SUB DhcpServerAuditlogParamsFree IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerAuditlogParamsFree" ( _
   BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_VQ _     ' __in DHCP_SERVER_CONFIG_INFO_VQ *ConfigInfo
 )                                                      ' void

DECLARE FUNCTION DhcpCreateSubnetV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateSubnetV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_V6 _            ' __in LPDHCP_SUBNET_INFO_V6 SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteSubnetV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteSubnetV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYVAL ForceFlag AS LONG _                            ' __in DHCP_FORCE_FLAG ForceFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetsV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetsV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumInfo AS DHCPV6_IP_ARRAY _                  ' __out LPDHCPV6_IP_ARRAY *EnumInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAddSubnetElementV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddSubnetElementV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF AddElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V6 _ ' __in LPDHCP_SUBNET_ELEMENT_DATA_V6 AddElementInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveSubnetElementV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpRemoveSubnetElementV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF RemoveElementInfo AS DHCP_SUBNET_ELEMENT_DATA_V6 _ ' __in LPDHCP_SUBNET_ELEMENT_DATA_V6 RemoveElementInfo
 , BYVAL ForceFlag AS DWORD _                           ' __in DHCP_FORCE_FLAG ForceFlag
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetElementsV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetElementsV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYVAL EnumElementType AS LONG _                      ' __in DHCP_SUBNET_ELEMENT_TYPE_V6 EnumElementType
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF EnumElementInfo AS DHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 _ ' __out LPDHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 *EnumElementInfo
 , BYREF ElementsRead AS DWORD _                        ' __out DWORD *ElementsRead
 , BYREF ElementsTotal AS DWORD _                       ' __out DWORD *ElementsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetSubnetInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetSubnetInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_V6 _            ' __out LPDHCP_SUBNET_INFO_V6 *SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumSubnetClientsV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumSubnetClientsV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_ARRAY_V6 _      ' __out LPDHCP_CLIENT_INFO_ARRAY_V6 *ClientInfo
 , BYREF ClientsRead AS DWORD _                         ' __out DWORD *ClientsRead
 , BYREF ClientsTotal AS DWORD _                        ' __out DWORD *ClientsTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerGetConfigV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerGetConfigV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_V6 _     ' __out LPDHCP_SERVER_CONFIG_INFO_V6 *ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpServerSetConfigV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpServerSetConfigV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ScopeInfo AS DHCP_OPTION_SCOPE_INFO6 _         ' __in LPDHCP_OPTION_SCOPE_INFO6 ScopeInfo
 , BYVAL FieldsToSet AS DWORD _                         ' __in DWORD FieldsToSet
 , BYREF ConfigInfo AS DHCP_SERVER_CONFIG_INFO_V6 _     ' __in LPDHCP_SERVER_CONFIG_INFO_V6 ConfigInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetSubnetInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetSubnetInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SubnetAddress AS DHCP_IPV6_ADDRESS _           ' __in DHCP_IPV6_ADDRESS SubnetAddress
 , BYREF SubnetInfo AS DHCP_SUBNET_INFO_V6 _            ' __in LPDHCP_SUBNET_INFO_V6 SubnetInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetMibInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetMibInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF MibInfo AS DHCP_MIB_INFO_V6 _                  ' __out LPDHCP_MIB_INFO_V6 *MibInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetServerBindingInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetServerBindingInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF BindElementsInfo AS DHCPV6_BIND_ELEMENT_ARRAY _ ' __out LPDHCPV6_BIND_ELEMENT_ARRAY *BindElementsInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetServerBindingInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetServerBindingInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF BindElementsInfo AS DHCPV6_BIND_ELEMENT_ARRAY _ ' __in LPDHCPV6_BIND_ELEMENT_ARRAY BindElementsInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetClientInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetClientInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V6 _            ' __in DHCP_CONST DHCP_CLIENT_INFO_V6 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetClientInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetClientInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF SearchInfo AS DHCP_SEARCH_INFO_V6 _            ' __in DHCP_CONST DHCP_SEARCH_INFO_V6 *SearchInfo
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V6 _            ' __out LPDHCP_CLIENT_INFO_V6 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteClientInfoV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteClientInfoV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF ClientInfo AS DHCP_CLIENT_INFO_V6 _            ' __in DHCP_CONST DHCP_SEARCH_INFO_V6 *ClientInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpCreateClassV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpCreateClassV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassInfo AS DHCP_CLASS_INFO_V6 _              ' __in LPDHCP_CLASS_INFO_V6 ClassInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpModifyClassV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpModifyClassV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassInfo AS DHCP_CLASS_INFO_V6 _              ' __in LPDHCP_CLASS_INFO_V6 ClassInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpDeleteClassV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpDeleteClassV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ClassName AS WSTRINGZ _                           ' __in LPWSTR ClassName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpEnumClassesV6 IMPORT "Dhcpsapi.dll" ALIAS "DhcpEnumClassesV6" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL ReservedMustBeZero AS DWORD _                  ' __in DWORD ReservedMustBeZero
 , BYREF ResumeHandle AS DWORD _                        ' __inout DHCP_RESUME_HANDLE *ResumeHandle
 , BYVAL PreferredMaximum AS DWORD _                    ' __in DWORD PreferredMaximum
 , BYREF ClassInfoArray AS DHCP_CLASS_INFO_ARRAY_V6 _   ' __out LPDHCP_CLASS_INFO_ARRAY_V6 *ClassInfoArray
 , BYREF nRead AS DWORD _                               ' __out DWORD *nRead
 , BYREF nTotal AS DWORD _                              ' __out DWORD *nTotal
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpSetSubnetDelayOffer IMPORT "Dhcpsapi.dll" ALIAS "DhcpSetSubnetDelayOffer" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYVAL TimeDelayInMilliseconds AS WORD _              ' __in USHORT TimeDelayInMilliseconds
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetSubnetDelayOffer IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetSubnetDelayOffer" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR ServerIpAddress
 , BYVAL SubnetAddress AS DWORD _                       ' __in DHCP_IP_ADDRESS SubnetAddress
 , BYREF TimeDelayInMilliseconds AS WORD _              ' __out USHORT *TimeDelayInMilliseconds
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpGetMibInfoV5 IMPORT "Dhcpsapi.dll" ALIAS "DhcpGetMibInfoV5" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt DHCP_CONST WCHAR *ServerIpAddress
 , BYREF MibInfo AS DHCP_MIB_INFO_V5 _                  ' __out LPDHCP_MIB_INFO_V5 *MibInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpAddSecurityGroup IMPORT "Dhcpsapi.dll" ALIAS "DhcpAddSecurityGroup" ( _
   BYREF ServerIpAddress AS WSTRINGZ _                  ' __in_opt LPWSTR pServer
 ) AS DWORD                                             ' DWORD
