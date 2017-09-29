' ########################################################################################
' Microsoft Windows
' File: dhcpv6csdk.inc
' Contents: Exported dhcpv6 client api function definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DHCPV6CSDK_INC = 1

#IF NOT %DEF(%DHCPV6_OPTIONS_DEFINED)
%DHCPV6_OPTIONS_DEFINED = 1

'//
'// DHCPv6 Standard Options(non-encapsulated).
'//

%DHCPV6_OPTION_CLIENTID          = 1
%DHCPV6_OPTION_SERVERID          = 2
%DHCPV6_OPTION_IA_NA             = 3
%DHCPV6_OPTION_IA_TA             = 4
%DHCPV6_OPTION_ORO               = 6
%DHCPV6_OPTION_PREFERENCE        = 7
%DHCPV6_OPTION_UNICAST           = 12
%DHCPV6_OPTION_RAPID_COMMIT      = 14
%DHCPV6_OPTION_USER_CLASS        = 15
%DHCPV6_OPTION_VENDOR_CLASS      = 16
%DHCPV6_OPTION_VENDOR_OPTS       = 17
%DHCPV6_OPTION_RECONF_MSG        = 19

%DHCPV6_OPTION_SIP_SERVERS_NAMES = 21
%DHCPV6_OPTION_SIP_SERVERS_ADDRS = 22
%DHCPV6_OPTION_DNS_SERVERS       = 23
%DHCPV6_OPTION_DOMAIN_LIST       = 24
%DHCPV6_OPTION_IA_PD             = 25
%DHCPV6_OPTION_NIS_SERVERS       = 27
%DHCPV6_OPTION_NISP_SERVERS      = 28
%DHCPV6_OPTION_NIS_DOMAIN_NAME   = 29
%DHCPV6_OPTION_NISP_DOMAIN_NAME  = 30

#ENDIF   '  DHCPV6_OPTIONS_DEFINED

#IF NOT %DEF(%DHCPV6API_PARAMS_DEFINED)
%DHCPV6API_PARAMS_DEFINED = 1

' // Size = 20 bytes
TYPE DHCPV6CAPI_PARAMS DWORD   ' // use this structure to request params
   Flags      AS DWORD         ' ULONG // for future use
   OptionId   AS DWORD         ' ULONG // what option is this?
   IsVendor   AS LONG          ' BOOL // is this vendor specific?
   Data       AS BYTE PTR      ' LPBYTE // the actual data
   nBytesData AS DWORD         ' DWORD // how many bytes of data are there in Data?
END TYPE

#ENDIF   ' DHCPV6API_PARAMS_DEFINED

' // Size = 8 bytes
TYPE DHCPV6CAPI_PARAMS_ARRAY DWORD    ' // array of params..
   nParams AS DWORD                   ' ULONG // size of array
   Params  AS DHCPV6CAPI_PARAMS PTR   ' LPDHCPV6CAPI_PARAMS // actual array
END TYPE

' // Size = 12 bytes
TYPE DHCPV6CAPI_CLASSID DWORD   ' // defines a client class id.
   Flags      AS DWORD          ' ULONG // must be zero currently.
   Data       AS BYTE PTR       ' LPBYTE // classid binary data.
   nBytesData AS DWORD          ' ULONG // how many bytes of data are there?
END TYPE

' enum StatusCode
%STATUS_NO_ERROR            = 0   ' // Prefix successfully leased, renewed.
%STATUS_UNSPECIFIED_FAILURE = 1   ' // Some unspecified failure occurred  while trying to process the prefix.
%STATUS_NO_BINDING          = 3   ' // The server doesn't have binding for the prefix.
%STATUS_NOPREFIX_AVAIL      = 6   ' // The server doesn't have prefix to offer to the requesting client.

' // Size = 32 bytes
TYPE DHCPV6Prefix DWORD
   prefix            AS STRING * 16   ' // UCHAR 128 bit prefix
   prefixLength      AS DWORD         ' DWORD // (48-64 bits)
   preferredLifeTime AS DWORD         ' DWORD // The Preferred Lifetime of the Prefix returned or requested in seconds
   validLifeTime     AS DWORD         ' DWORD // The Valid Lifetime of the Prefix returned or requested in seconds
   status            AS LONG          ' StatusCode // The status code returned by the server for the prefix
END TYPE

' // Size = 40 bytes
TYPE DHCPV6PrefixLeaseInformation DWORD
   nPrefixes              AS DWORD              ' DWORD //  number of prefixes.
   prefixArray            AS DHCPV6Prefix PTR   ' LPDHCPV6Prefix //  Array of prefixes
   iaid                   AS DWORD              ' DWORD // The 32 bit Identity Association identifier for the prefix option.
   T1                     AS LONG               ' time_t // The absolute renewal time for the prefixes in seconds
   T2                     AS LONG               ' time_t // The absolute rebind time for the prefixes in seconds
   MaxLeaseExpirationTime AS LONG               ' time_t // The absolute maximum lease expiration time of all the prefix leases in this structure.
   LastRenewalTime        AS LONG               ' time_t // The absolute time at which the last renewal for the prefixes happened.
   status                 AS LONG               ' StatusCode // The status code returned by the server for the IAPD
   ServerId               AS BYTE PTR           ' LPBYTE // The server DUID from which the prefix is received. This is used in subsequent Renews.
   ServerIdLen            AS DWORD              ' DWORD // The length of the above DUID data.
END TYPE

DECLARE SUB Dhcpv6CApiInitialize IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6CApiInitialize" ( _
   BYREF Version AS DWORD _                             ' __out LPDWORD Version
 )                                                      ' void

DECLARE SUB Dhcpv6CApiCleanup IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6CApiCleanup" ( _
 )                                                      ' void

DECLARE FUNCTION Dhcpv6RequestParams IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6RequestParams" ( _
   BYVAL forceNewInform AS LONG _                       ' __in BOOL forceNewInform
 , BYVAL reserved AS DWORD _                            ' __in LPVOID reserved
 , BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
 , BYREF classId AS DHCPV6CAPI_CLASSID _                ' __in_out LPDHCPV6CAPI_CLASSID classId
 , BYREF recdParams AS DHCPV6CAPI_PARAMS_ARRAY _        ' __in_out DHCPV6CAPI_PARAMS_ARRAY recdParams
 , BYVAL buffer AS BYTE PTR _                           ' __in LPBYTE buffer
 , BYREF pSize AS DWORD _                               ' __in_out LPDWORD pSize
 ) AS DWORD                                             ' DWORD

' *** Removed in the Windows 7 SDK ***
'DECLARE FUNCTION DHCPv6RegisterPersistentRequestParams IMPORT "Dhcpcsvc6.dll" ALIAS "DHCPv6RegisterPersistentRequestParams" ( _
'   BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
' , BYREF classId AS DHCPV6CAPI_CLASSID _                ' __in LPDHCPV6CAPI_CLASSID classId
' , BYREF requestedParams AS DHCPV6CAPI_PARAMS_ARRAY _   ' __in DHCPV6CAPI_PARAMS_ARRAY requestedParams
' , BYREF registryNameString AS WSTRINGZ _               ' __in LPWSTR registryNameString
' ) AS DWORD                                             ' DWORD

' *** Removed in the Windows 7 SDK ***
'DECLARE FUNCTION DHCPv6DeRegisterPersistentRequestParams IMPORT "Dhcpcsvc6.dll" ALIAS "DHCPv6DeRegisterPersistentRequestParams" ( _
'   BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
' , BYREF registryNameString AS WSTRINGZ _               ' __in LPWSTR registryNameString
' ) AS DWORD                                             ' DWORD

DECLARE FUNCTION Dhcpv6RequestPrefix IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6RequestPrefix" ( _
   BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
 , BYREF pclassId AS DHCPV6CAPI_CLASSID _               ' __in LPDHCPV6CAPI_CLASSID pclassId
 , BYREF prefixleaseInfo AS DHCPV6PrefixLeaseInformation _ ' __in_out LPDHCPV6PrefixLeaseInformation prefixleaseInfo
 , BYREF pdwTimeToWait AS DWORD _                       ' __out DWORD* pdwTimeToWait
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION Dhcpv6RenewPrefix IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6RenewPrefix" ( _
   BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
 , BYREF pclassId AS DHCPV6CAPI_CLASSID _               ' __in LPDHCPV6CAPI_CLASSID pclassId
 , BYREF prefixleaseInfo AS DHCPV6PrefixLeaseInformation _ ' __in_out LPDHCPV6PrefixLeaseInformation prefixleaseInfo
 , BYREF pdwTimeToWait AS DWORD _                       ' __out DWORD* pdwTimeToWait
 , BYVAL bValidatePrefix AS DWORD _                     ' __in DWORD bValidatePrefix
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION Dhcpv6ReleasePrefix IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6ReleasePrefix" ( _
   BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
 , BYREF classId AS DHCPV6CAPI_CLASSID _                ' __in LPDHCPV6CAPI_CLASSID classId
 , BYREF leaseInfo AS DHCPV6PrefixLeaseInformation _    ' __in_out LPDHCPV6PrefixLeaseInformation leaseInfo
 ) AS DWORD                                             ' DWORD

' *** Removed in the Windows 7 SDK ***
'%DHCPV6CAPI_REGISTER_HANDLE_EVENT = &H01???   ' // handle returned is to an event

' *** Removed in the Windows 7 SDK ***
'DECLARE FUNCTION Dhcpv6RegisterParamChange IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6RegisterParamChange" ( _
'   BYVAL flags AS DWORD _                               ' __in DWORD flags
' , BYVAL reserved AS DWORD _                            ' __in LPVOID reserved
' , BYREF adapterName AS WSTRINGZ _                      ' __in LPWSTR adapterName
' , BYREF classId AS DHCPV6CAPI_CLASSID _                ' __in LPDHCPV6CAPI_CLASSID classId
' , BYREF params AS DHCPV6CAPI_PARAMS_ARRAY _            ' __in DHCPV6CAPI_PARAMS_ARRAY params
' , BYREF handle AS DWORD _                              ' __out LPVOID handle
' , BYREF eventName AS WSTRINGZ _                        ' __out LPWSTR eventName
' ) AS DWORD                                             ' DWORD

' *** Removed in the Windows 7 SDK ***
'%DHCPV6CAPI_DEREGISTER_HANDLE_EVENT = &H01   ' // de-register handle that is an event

' *** Removed in the Windows 7 SDK ***
'DECLARE FUNCTION Dhcpv6DeRegisterParamChange IMPORT "Dhcpcsvc6.dll" ALIAS "Dhcpv6DeRegisterParamChange" ( _
'   BYVAL flags AS DWORD _                               ' __in DWORD flags
' , BYVAL reserved AS DWORD _                            ' __in LPVOID reserved
' , BYREF eventName AS WSTRINGZ _                        ' __in LPWSTR eventName
' ) AS DWORD                                             ' DWORD
