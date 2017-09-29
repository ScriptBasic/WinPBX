' ########################################################################################
' Microsoft Windows
' File: DSGetDC.inc
' Contents: Structures, function prototypes, and definitions for the DsGetDcName API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSGETDC_INC = 1

#INCLUDE ONCE "ws2def.inc"
#INCLUDE ONCE "ntsecapi.inc"

'//
'// Structure definitions
'//

'//
'// Flags to passed to DsGetDcName
'//

%DS_FORCE_REDISCOVERY            = &H00000001???

%DS_DIRECTORY_SERVICE_REQUIRED   = &H00000010???
%DS_DIRECTORY_SERVICE_PREFERRED  = &H00000020???
%DS_GC_SERVER_REQUIRED           = &H00000040???
%DS_PDC_REQUIRED                 = &H00000080???
%DS_BACKGROUND_ONLY              = &H00000100???
%DS_IP_REQUIRED                  = &H00000200???
%DS_KDC_REQUIRED                 = &H00000400???
%DS_TIMESERV_REQUIRED            = &H00000800???
%DS_WRITABLE_REQUIRED            = &H00001000???
%DS_GOOD_TIMESERV_PREFERRED      = &H00002000???
%DS_Avoid_SELF                   = &H00004000???
%DS_ONLY_LDAP_NEEDED             = &H00008000???


%DS_IS_FLAT_NAME                 = &H00010000???
%DS_IS_DNS_NAME                  = &H00020000???

%DS_TRY_NEXTCLOSEST_SITE         = &H00040000???

%DS_DIRECTORY_SERVICE_6_REQUIRED = &H00080000???

%DS_WEB_SERVICE_REQUIRED         = &H00100000???

%DS_RETURN_DNS_NAME              = &H40000000???
%DS_RETURN_FLAT_NAME             = &H80000000???

%DSGETDC_VALID_FLAGS = %DS_FORCE_REDISCOVERY OR _
                       %DS_DIRECTORY_SERVICE_REQUIRED OR _
                       %DS_DIRECTORY_SERVICE_PREFERRED OR _
                       %DS_GC_SERVER_REQUIRED OR _
                       %DS_PDC_REQUIRED OR _
                       %DS_BACKGROUND_ONLY OR _
                       %DS_IP_REQUIRED OR _
                       %DS_KDC_REQUIRED OR _
                       %DS_TIMESERV_REQUIRED OR _
                       %DS_WRITABLE_REQUIRED OR _
                       %DS_GOOD_TIMESERV_PREFERRED OR _
                       %DS_Avoid_SELF OR _
                       %DS_ONLY_LDAP_NEEDED OR _
                       %DS_IS_FLAT_NAME OR _
                       %DS_IS_DNS_NAME OR _
                       %DS_TRY_NEXTCLOSEST_SITE OR _
                       %DS_DIRECTORY_SERVICE_6_REQUIRED OR _
                       %DS_WEB_SERVICE_REQUIRED OR _
                       %DS_RETURN_FLAT_NAME  OR _
                       %DS_RETURN_DNS_NAME


'//
'// Structure returned from DsGetDcName
'//

' // Size = 48 bytes
TYPE DOMAIN_CONTROLLER_INFOA DWORD
   DomainControllerName        AS ASCIIZ PTR   ' LPSTR
   DomainControllerAddress     AS ASCIIZ PTR   ' LPSTR
   DomainControllerAddressType AS DWORD        ' ULONG
   DomainGuid                  AS GUID         ' GUID
   DomainName                  AS ASCIIZ PTR   ' LPSTR
   DnsForestName               AS ASCIIZ PTR   ' LPSTR
   Flags                       AS DWORD        ' ULONG
   DcSiteName                  AS ASCIIZ PTR   ' LPSTR
   ClientSiteName              AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 48 bytes
TYPE DOMAIN_CONTROLLER_INFOW DWORD
   DomainControllerName        AS WSTRINGZ PTR   ' LPWSTR
   DomainControllerAddress     AS WSTRINGZ PTR   ' LPWSTR
   DomainControllerAddressType AS DWORD          ' ULONG
   DomainGuid                  AS GUID           ' GUID
   DomainName                  AS WSTRINGZ PTR   ' LPWSTR
   DnsForestName               AS WSTRINGZ PTR   ' LPWSTR
   Flags                       AS DWORD          ' ULONG
   DcSiteName                  AS WSTRINGZ PTR   ' LPWSTR
   ClientSiteName              AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DOMAIN_CONTROLLER_INFO = DOMAIN_CONTROLLER_INFOW
#ELSE
   MACRO DOMAIN_CONTROLLER_INFO = DOMAIN_CONTROLLER_INFOA
#ENDIF

'//
'// Values for DomainControllerAddressType
'//

%DS_INET_ADDRESS    = 1
%DS_NETBIOS_ADDRESS = 2

'//
'// Values for returned Flags
'//

%DS_PDC_FLAG            = &H00000001???    ' // DC is PDC of Domain
%DS_GC_FLAG             = &H00000004???    ' // DC is a GC of forest
%DS_LDAP_FLAG           = &H00000008???    ' // Server supports an LDAP server
%DS_DS_FLAG             = &H00000010???    ' // DC supports a DS and is a Domain Controller
%DS_KDC_FLAG            = &H00000020???    ' // DC is running KDC service
%DS_TIMESERV_FLAG       = &H00000040???    ' // DC is running time service
%DS_CLOSEST_FLAG        = &H00000080???    ' // DC is in closest site to client
%DS_WRITABLE_FLAG       = &H00000100???    ' // DC has a writable DS
%DS_GOOD_TIMESERV_FLAG  = &H00000200???    ' // DC is running time service (and has clock hardware)
%DS_NDNC_FLAG           = &H00000400???    ' // DomainName is non-domain NC serviced by the LDAP server
%DS_SELECT_SECRET_DOMAIN_6_FLAG = &H00000800???  ' // DC has some secrets
%DS_FULL_SECRET_DOMAIN_6_FLAG   = &H00001000???  ' // DC has all secrets
%DS_WS_FLAG             = &H00002000???    ' // DC is running web service
%DS_PING_FLAGS          = &H0000FFFF???    ' // Flags returned on ping

%DS_DNS_CONTROLLER_FLAG = &H20000000???    ' // DomainControllerName is a DNS name
%DS_DNS_DOMAIN_FLAG     = &H40000000???    ' // DomainName is a DNS name
%DS_DNS_FOREST_FLAG     = &H80000000???    ' // DnsForestName is a DNS name


'//
'// Function Prototypes
'//

DECLARE FUNCTION DsGetDcNameA IMPORT "NETAPI32.DLL" ALIAS "DsGetDcNameA" ( _
   BYREF ComputerName AS ASCIIZ _                       ' __in  LPCSTR ComputerName OPTIONAL
 , BYREF DomainName AS ASCIIZ _                         ' __in  LPCSTR DomainName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in  GUID *DomainGuid OPTIONAL
 , BYREF SiteName AS ASCIIZ _                           ' __in  LPCSTR SiteName OPTIONAL
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF DomainControllerInfo AS DOMAIN_CONTROLLER_INFOA _ ' __out PDOMAIN_CONTROLLER_INFOA *DomainControllerInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsGetDcNameW IMPORT "NETAPI32.DLL" ALIAS "DsGetDcNameW" ( _
   BYREF ComputerName AS WSTRINGZ _                     ' __in  LPCWSTR ComputerName OPTIONAL
 , BYREF DomainName AS WSTRINGZ _                       ' __in  LPCWSTR DomainName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in  GUID *DomainGuid OPTIONAL
 , BYREF SiteName AS WSTRINGZ _                         ' __in  LPCWSTR SiteName OPTIONAL
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF DomainControllerInfo AS DOMAIN_CONTROLLER_INFOW _ ' __out PDOMAIN_CONTROLLER_INFOW *DomainControllerInfo
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsGetDcName = DsGetDcNameW
#ELSE
   MACRO DsGetDcName = DsGetDcNameA
#ENDIF

DECLARE FUNCTION DsGetSiteNameA IMPORT "NETAPI32.DLL" ALIAS "DsGetSiteNameA" ( _
   BYREF ComputerName AS ASCIIZ _                       ' __in  LPCSTR ComputerName OPTIONAL
 , BYREF SiteName AS ASCIIZ _                           ' __out LPSTR *SiteName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsGetSiteNameW IMPORT "NETAPI32.DLL" ALIAS "DsGetSiteNameW" ( _
   BYREF ComputerName AS WSTRINGZ _                     ' __in  LPCWSTR ComputerName OPTIONAL
 , BYREF SiteName AS DWORD _                            ' __out LPWSTR *SiteName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsGetSiteName = DsGetSiteNameW
#ELSE
   MACRO DsGetSiteName = DsGetSiteNameA
#ENDIF

DECLARE FUNCTION DsValidateSubnetNameA IMPORT "NETAPI32.DLL" ALIAS "DsValidateSubnetNameA" ( _
   BYREF SubnetName AS ASCIIZ _                         ' __in LPCSTR SubnetName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsValidateSubnetNameW IMPORT "NETAPI32.DLL" ALIAS "DsValidateSubnetNameW" ( _
   BYREF SubnetName AS WSTRINGZ _                       ' __in LPCWSTR SubnetName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsValidateSubnetName = DsValidateSubnetNameW
#ELSE
   MACRO DsValidateSubnetName = DsValidateSubnetNameA
#ENDIF

'//
'// Only include if winsock2.h has been included
'//

#IF NOT %DEF(%SOCKET_ADDRESS_DEFINED)
%SOCKET_ADDRESS_DEFINED = 1
' // Size = 8 bytes
TYPE SOCKET_ADDRESS DWORD
   lpSocaddr       AS SOCKADDR PTR
   iSockaddrLength AS LONG
END TYPE
#ENDIF

#IF %DEF(%WINSOCK2API)

DECLARE FUNCTION DsAddressToSiteNamesA IMPORT "NETAPI32.DLL" ALIAS "DsAddressToSiteNamesA" ( _
   BYREF ComputerName AS ASCIIZ _                       ' __in  LPCSTR ComputerName OPTIONAL
 , BYVAL EntryCount AS DWORD _                          ' __in  DWORD EntryCount
 , BYREF SocketAddresses AS SOCKET_ADDRESS _            ' __in  PSOCKET_ADDRESS SocketAddresses
 , BYREF SiteNames AS ASCIIZ _                          ' __out LPSTR **SiteNames
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsAddressToSiteNamesW IMPORT "NETAPI32.DLL" ALIAS "DsAddressToSiteNamesW" ( _
   BYREF ComputerName AS WSTRINGZ _                     ' __in  LPCWSTR ComputerName OPTIONAL
 , BYVAL EntryCount AS DWORD _                          ' __in  DWORD EntryCount
 , BYREF SocketAddresses AS SOCKET_ADDRESS _            ' __in  PSOCKET_ADDRESS SocketAddresses
 , BYREF SiteNames AS DWORD _                           ' __out LPWSTR **SiteNames
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsAddressToSiteNames = DsAddressToSiteNamesW
#ELSE
   MACRO DsAddressToSiteNames = DsAddressToSiteNamesA
#ENDIF

DECLARE FUNCTION DsAddressToSiteNamesExA IMPORT "NETAPI32.DLL" ALIAS "DsAddressToSiteNamesExA" ( _
   BYREF ComputerName AS ASCIIZ _                       ' __in  LPCSTR ComputerName OPTIONAL
 , BYVAL EntryCount AS DWORD _                          ' __in  DWORD EntryCount
 , BYREF SocketAddresses AS SOCKET_ADDRESS _            ' __in  PSOCKET_ADDRESS SocketAddresses
 , BYREF SiteNames AS ASCIIZ _                          ' __out LPSTR **SiteNames
 , BYREF SubnetNames AS ASCIIZ _                        ' __out LPSTR **SubnetNames
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsAddressToSiteNamesExW IMPORT "NETAPI32.DLL" ALIAS "DsAddressToSiteNamesExW" ( _
   BYREF ComputerName AS WSTRINGZ _                     ' __in  LPCWSTR ComputerName OPTIONAL
 , BYVAL EntryCount AS DWORD _                          ' __in  DWORD EntryCount
 , BYREF SocketAddresses AS SOCKET_ADDRESS _            ' __in  PSOCKET_ADDRESS SocketAddresses
 , BYREF SiteNames AS DWORD _                           ' __out LPWSTR **SiteNames
 , BYREF SubnetNames AS DWORD _                         ' __out LPWSTR **SubnetNames
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsAddressToSiteNamesEx = DsAddressToSiteNamesExW
#ELSE
   MACRO DsAddressToSiteNamesEx = DsAddressToSiteNamesExA
#ENDIF

#ENDIF   ' #IF %DEF(%WINSOCK2API)

'//
'// API to enumerate trusted domains
'//

%DS_DOMAIN_IN_FOREST           = &H0001  ' // Domain is a member of the forest
%DS_DOMAIN_DIRECT_OUTBOUND     = &H0002  ' // Domain is directly trusted
%DS_DOMAIN_TREE_ROOT           = &H0004  ' // Domain is root of a tree in the forest
%DS_DOMAIN_PRIMARY             = &H0008  ' // Domain is the primary domain of queried server
%DS_DOMAIN_NATIVE_MODE         = &H0010  ' // Primary domain is running in native mode
%DS_DOMAIN_DIRECT_INBOUND      = &H0020  ' // Domain is directly trusting
%DS_DOMAIN_VALID_FLAGS = %DS_DOMAIN_IN_FOREST       OR _
                         %DS_DOMAIN_DIRECT_OUTBOUND OR _
                         %DS_DOMAIN_TREE_ROOT       OR _
                         %DS_DOMAIN_PRIMARY         OR _
                         %DS_DOMAIN_NATIVE_MODE     OR _
                         %DS_DOMAIN_DIRECT_INBOUND

' // Size = 44 bytes
TYPE DS_DOMAIN_TRUSTSW DWORD
   NetbiosDomainName AS WSTRINGZ PTR   ' LPWSTR
   DnsDomainName     AS WSTRINGZ PTR   ' LPWSTR
   Flags             AS DWORD          ' ULONG
   ParentIndex       AS DWORD          ' ULONG
   TrustType         AS DWORD          ' ULONG
   TrustAttributes   AS DWORD          ' ULONG
   DomainSid         AS SID PTR        ' PSID
   DomainGuid        AS GUID           ' GUID
END TYPE

' // Size = 44 bytes
TYPE DS_DOMAIN_TRUSTSA DWORD
   NetbiosDomainName AS ASCIIZ PTR   ' LPSTR
   DnsDomainName     AS ASCIIZ PTR   ' LPSTR
   Flags             AS DWORD        ' ULONG
   ParentIndex       AS DWORD        ' ULONG
   TrustType         AS DWORD        ' ULONG
   TrustAttributes   AS DWORD        ' ULONG
   DomainSid         AS SID PTR      ' PSID
   DomainGuid        AS GUID         ' GUID
END TYPE

MACRO DS_DOMAIN_TRUSTS = DS_DOMAIN_TRUSTSA


DECLARE FUNCTION DsEnumerateDomainTrustsA IMPORT "NETAPI32.DLL" ALIAS "DsEnumerateDomainTrustsA" ( _
   BYREF ServerName AS ASCIIZ _                         ' __in  LPSTR ServerName OPTIONAL
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF Domains AS DS_DOMAIN_TRUSTSA _                 ' __out PDS_DOMAIN_TRUSTSA *Domains
 , BYREF DomainCount AS DWORD _                         ' __out PULONG DomainCount
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsEnumerateDomainTrustsW IMPORT "NETAPI32.DLL" ALIAS "DsEnumerateDomainTrustsW" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName OPTIONAL
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF Domains AS DS_DOMAIN_TRUSTSW _                 ' __out PDS_DOMAIN_TRUSTSW *Domains
 , BYREF DomainCount AS DWORD _                         ' __out PULONG DomainCount
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsEnumerateDomainTrusts = DsEnumerateDomainTrustsW
#ELSE
   MACRO DsEnumerateDomainTrusts = DsEnumerateDomainTrustsA
#ENDIF

'//
'// Only define this API if the caller has #included the pre-requisite
'// ntlsa.h or ntsecapi.h
'//

'#if defined(_NTLSA_) || defined(_NTSECAPI_)
#IF %DEF(%NTSECAPI)

' // There is not ansi version
DECLARE FUNCTION DsGetForestTrustInformationW IMPORT "NETAPI32.DLL" ALIAS "DsGetForestTrustInformationW" ( _
   BYREF ServerName AS WSTRINGZ _                           ' __in  LPCWSTR ServerName OPTIONAL
 , BYREF TrustedDomainName AS WSTRINGZ _                    ' __in  LPCWSTR TrustedDomainName OPTIONAL
 , BYVAL Flags AS DWORD _                                   ' __in  DWORD Flags
 , BYREF ForestTrustInfo AS LSA_FOREST_TRUST_INFORMATION _  ' __out PLSA_FOREST_TRUST_INFORMATION *ForestTrustInfo
 ) AS DWORD                                                 ' DWORD

MACRO DsGetForestTrustInformation = DsGetForestTrustInformationW

%DS_GFTI_UPDATE_TDO     = &H1    ' // Update TDO with information returned
%DS_GFTI_VALID_FLAGS    = &H1    ' // All valid flags to DsGetForestTrustInformation

' // There is not ansi version
DECLARE FUNCTION DsMergeForestTrustInformationW IMPORT "NETAPI32.DLL" ALIAS "DsMergeForestTrustInformationW" ( _
   BYREF DomainName AS WSTRINGZ _                                 ' __in  LPCWSTR DomainName
 , BYREF NewForestTrustInfo AS LSA_FOREST_TRUST_INFORMATION _     ' __in  PLSA_FOREST_TRUST_INFORMATION NewForestTrustInfo
 , BYREF OldForestTrustInfo AS LSA_FOREST_TRUST_INFORMATION _     ' __in  PLSA_FOREST_TRUST_INFORMATION OldForestTrustInfo OPTIONAL
 , BYREF MergedForestTrustInfo AS LSA_FOREST_TRUST_INFORMATION _  ' __out PLSA_FOREST_TRUST_INFORMATION *MergedForestTrustInfo
 ) AS DWORD                                                       ' DWORD

MACRO DsMergeForestTrustInformation = DsMergeForestTrustInformationW

'#endif // _NTLSA_ || _NTSECAPI_
#ENDIF   ' #IF %DEF(%NTSECAPI)

DECLARE FUNCTION DsGetDcSiteCoverageA IMPORT "NETAPI32.DLL" ALIAS "DsGetDcSiteCoverageA" ( _
   BYREF ServerName AS ASCIIZ _                         ' __in  LPCSTR ServerName OPTIONAL
 , BYREF EntryCount AS DWORD _                          ' __out PULONG EntryCount
 , BYREF SiteNames AS ASCIIZ _                          ' __out LPSTR **SiteNames
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsGetDcSiteCoverageW IMPORT "NETAPI32.DLL" ALIAS "DsGetDcSiteCoverageW" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName OPTIONAL
 , BYREF EntryCount AS DWORD _                          ' __out PULONG EntryCount
 , BYREF SiteNames AS DWORD _                           ' __out LPWSTR **SiteNames
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsGetDcSiteCoverage = DsGetDcSiteCoverageW
#ELSE
   MACRO DsGetDcSiteCoverage = DsGetDcSiteCoverageA
#ENDIF

DECLARE FUNCTION DsDeregisterDnsHostRecordsA IMPORT "NETAPI32.DLL" ALIAS "DsDeregisterDnsHostRecordsA" ( _
   BYREF ServerName AS ASCIIZ _                         ' __in LPSTR ServerName OPTIONAL
 , BYREF DnsDomainName AS ASCIIZ _                      ' __in LPSTR DnsDomainName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in GUID  *DomainGuid OPTIONAL
 , BYREF DsaGuid AS GUID _                              ' __in GUID  *DsaGuid OPTIONAL
 , BYREF DnsHostName AS ASCIIZ _                        ' __in LPSTR DnsHostName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsDeregisterDnsHostRecordsW IMPORT "NETAPI32.DLL" ALIAS "DsDeregisterDnsHostRecordsW" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in LPWSTR ServerName OPTIONAL
 , BYREF DnsDomainName AS WSTRINGZ _                    ' __in LPWSTR DnsDomainName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in GUID  *DomainGuid OPTIONAL
 , BYREF DsaGuid AS GUID _                              ' __in GUID  *DsaGuid OPTIONAL
 , BYREF DnsHostName AS WSTRINGZ _                      ' __in LPWSTR DnsHostName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsDeregisterDnsHostRecords = DsDeregisterDnsHostRecordsW
#ELSE
   MACRO DsDeregisterDnsHostRecords = DsDeregisterDnsHostRecordsA
#ENDIF

#IF %DEF(%WINSOCK2API)  ' // DsGetDcOpen/Next/Close depend on winsock2.h be included

'//
'// Option flags passed to DsGetDcOpen
'//

%DS_ONLY_DO_SITE_NAME         = &H01  ' // Non-site specific names should be avoided.
%DS_NOTIFY_AFTER_SITE_RECORDS = &H02  ' // Return ERROR_FILEMARK_DETECTED after all
                                      ' //  site specific records have been processed.

%DS_OPEN_VALID_OPTION_FLAGS = %DS_ONLY_DO_SITE_NAME OR %DS_NOTIFY_AFTER_SITE_RECORDS

'//
'// Valid DcFlags for DsGetDcOpen
'//

%DS_OPEN_VALID_FLAGS = %DS_FORCE_REDISCOVERY  OR _
                       %DS_ONLY_LDAP_NEEDED   OR _
                       %DS_KDC_REQUIRED       OR _
                       %DS_PDC_REQUIRED       OR _
                       %DS_GC_SERVER_REQUIRED OR _
                       %DS_WRITABLE_REQUIRED


DECLARE FUNCTION DsGetDcOpenA IMPORT "NETAPI32.DLL" ALIAS "DsGetDcOpenA" ( _
   BYREF DnsName AS ASCIIZ _                            ' __in  LPCSTR DnsName
 , BYVAL OptionFlags AS DWORD _                         ' __in  ULONG OptionFlags
 , BYREF SiteName AS ASCIIZ _                           ' __in  LPCSTR SiteName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in  GUID *DomainGuid OPTIONAL
 , BYREF DnsForestName AS ASCIIZ _                      ' __in  LPCSTR DnsForestName OPTIONAL
 , BYVAL DcFlags AS DWORD _                             ' __in  ULONG DcFlags
 , BYREF RetGetDcContext AS DWORD _                     ' __out PHANDLE RetGetDcContext
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsGetDcOpenW IMPORT "NETAPI32.DLL" ALIAS "DsGetDcOpenW" ( _
   BYREF DnsName AS WSTRINGZ _                          ' __in  LPCWSTR DnsName
 , BYVAL OptionFlags AS DWORD _                         ' __in  ULONG OptionFlags
 , BYREF SiteName AS WSTRINGZ _                         ' __in  LPCWSTR SiteName OPTIONAL
 , BYREF DomainGuid AS GUID _                           ' __in  GUID *DomainGuid OPTIONAL
 , BYREF DnsForestName AS WSTRINGZ _                    ' __in  LPCWSTR DnsForestName OPTIONAL
 , BYVAL DcFlags AS DWORD _                             ' __in  ULONG DcFlags
 , BYREF RetGetDcContext AS DWORD _                     ' __out PHANDLE RetGetDcContext
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsGetDcOpen = DsGetDcOpenW
#ELSE
   MACRO DsGetDcOpen = DsGetDcOpenA
#ENDIF

DECLARE FUNCTION DsGetDcNextA IMPORT "NETAPI32.DLL" ALIAS "DsGetDcNextA" ( _
   BYVAL GetDcContextHandle AS DWORD _                  ' __in  HANDLE GetDcContextHandle
 , BYREF SockAddressCount AS DWORD _                    ' __out PULONG SockAddressCount OPTIONAL
 , BYREF SockAddresses AS SOCKET_ADDRESS _              ' __out LPSOCKET_ADDRESS *SockAddresses OPTIONAL
 , BYREF DnsHostName AS ASCIIZ _                        ' __out LPSTR *DnsHostName OPTIONAL
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DsGetDcNextW IMPORT "NETAPI32.DLL" ALIAS "DsGetDcNextW" ( _
   BYVAL GetDcContextHandle AS DWORD _                  ' __in  HANDLE GetDcContextHandle
 , BYREF SockAddressCount AS DWORD _                    ' __out PULONG SockAddressCount OPTIONAL
 , BYREF SockAddresses AS SOCKET_ADDRESS _              ' __out LPSOCKET_ADDRESS *SockAddresses OPTIONAL
 , BYREF DnsHostName AS DWORD _                         ' __out LPWSTR *DnsHostName OPTIONAL
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DsGetDcNext = DsGetDcNextW
#ELSE
   MACRO DsGetDcNext = DsGetDcNextA
#ENDIF

' // There is not ansi version
DECLARE SUB DsGetDcCloseW IMPORT "NETAPI32.DLL" ALIAS "DsGetDcCloseW" ( _
   BYVAL GetDcContextHandle AS DWORD _                  ' __in HANDLE GetDcContextHandle
 )                                                      ' void

MACRO DsGetDcClose = DsGetDcNextW

#ENDIF   ' #IF %DEF(%WINSOCK2API)
