' ########################################################################################
' Microsoft Windows
' File: dhcpcsdk.inc
' Contents: Exported dhcpv6 client api function definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DHCPCSDK_INC = 1

#IF NOT %DEF(%DHCP_OPTIONS_DEFINED)
%DHCP_OPTIONS_DEFINED = 1

'//
'// DHCP Standard Options.
'//

%OPTION_PAD                      = 0
%OPTION_SUBNET_MASK              = 1
%OPTION_TIME_OFFSET              = 2
%OPTION_ROUTER_ADDRESS           = 3
%OPTION_TIME_SERVERS             = 4
%OPTION_IEN116_NAME_SERVERS      = 5
%OPTION_DOMAIN_NAME_SERVERS      = 6
%OPTION_LOG_SERVERS              = 7
%OPTION_COOKIE_SERVERS           = 8
%OPTION_LPR_SERVERS              = 9
%OPTION_IMPRESS_SERVERS          = 10
%OPTION_RLP_SERVERS              = 11
%OPTION_HOST_NAME                = 12
%OPTION_BOOT_FILE_SIZE           = 13
%OPTION_MERIT_DUMP_FILE          = 14
%OPTION_DOMAIN_NAME              = 15
%OPTION_SWAP_SERVER              = 16
%OPTION_ROOT_DISK                = 17
%OPTION_EXTENSIONS_PATH          = 18

'//
'// IP layer parameters - per host
'//

%OPTION_BE_A_ROUTER              = 19
%OPTION_NON_LOCAL_SOURCE_ROUTING = 20
%OPTION_POLICY_FILTER_FOR_NLSR   = 21
%OPTION_MAX_REASSEMBLY_SIZE      = 22
%OPTION_DEFAULT_TTL              = 23
%OPTION_PMTU_AGING_TIMEOUT       = 24
%OPTION_PMTU_PLATEAU_TABLE       = 25

'//
'// Link layer parameters - per interface.
'//

%OPTION_MTU                      = 26
%OPTION_ALL_SUBNETS_MTU          = 27
%OPTION_BROADCAST_ADDRESS        = 28
%OPTION_PERFORM_MASK_DISCOVERY   = 29
%OPTION_BE_A_MASK_SUPPLIER       = 30
%OPTION_PERFORM_ROUTER_DISCOVERY = 31
%OPTION_ROUTER_SOLICITATION_ADDR = 32
%OPTION_STATIC_ROUTES            = 33
%OPTION_TRAILERS                 = 34
%OPTION_ARP_CACHE_TIMEOUT        = 35
%OPTION_ETHERNET_ENCAPSULATION   = 36

'//
'// TCP Paramters - per host
'//

%OPTION_TTL                      = 37
%OPTION_KEEP_ALIVE_INTERVAL      = 38
%OPTION_KEEP_ALIVE_DATA_SIZE     = 39

'//
'// Application Layer Parameters
'//

%OPTION_NETWORK_INFO_SERVICE_DOM = 40
%OPTION_NETWORK_INFO_SERVERS     = 41
%OPTION_NETWORK_TIME_SERVERS     = 42

'//
'// Vender specific information option
'//

%OPTION_VENDOR_SPEC_INFO         = 43

'//
'// NetBIOS over TCP/IP Name server option
'//

%OPTION_NETBIOS_NAME_SERVER      = 44
%OPTION_NETBIOS_DATAGRAM_SERVER  = 45
%OPTION_NETBIOS_NODE_TYPE        = 46
%OPTION_NETBIOS_SCOPE_OPTION     = 47

'//
'// X Window System Options.
'//

%OPTION_XWINDOW_FONT_SERVER      = 48
%OPTION_XWINDOW_DISPLAY_MANAGER  = 49

'//
'// Other extensions
'//

%OPTION_REQUESTED_ADDRESS        = 50
%OPTION_LEASE_TIME               = 51
%OPTION_OK_TO_OVERLAY            = 52
%OPTION_MESSAGE_TYPE             = 53
%OPTION_SERVER_IDENTIFIER        = 54
%OPTION_PARAMETER_REQUEST_LIST   = 55
%OPTION_MESSAGE                  = 56
%OPTION_MESSAGE_LENGTH           = 57
%OPTION_RENEWAL_TIME             = 58     ' // T1
%OPTION_REBIND_TIME              = 59     ' // T2
%OPTION_CLIENT_CLASS_INFO        = 60
%OPTION_CLIENT_ID                = 61

%OPTION_TFTP_SERVER_NAME         = 66
%OPTION_BOOTFILE_NAME            = 67


%OPTION_END                      = 255

#ENDIF   '  DHCP_OPTIONS_DEFINED

#IF NOT %DEF(%DHCPAPI_PARAMS_DEFINED)
%DHCPAPI_PARAMS_DEFINED = 1
' // Serie = 20 bytes
TYPE DHCPAPI_PARAMS DWORD   ' // use this structure to request params
   Flags      AS DWORD      ' ULONG // for future use
   OptionId   AS DWORD      ' ULONG // what option is this?
   IsVendor   AS LONG       ' BOOL // is this vendor specific?
   Data       AS BYTE PTR   ' LPBYTE // the actual data
   nBytesData AS DWORD      ' DWORD // how many bytes of data are there in Data?
END TYPE
#ENDIF   ' DHCPAPI_PARAMS_DEFINED

' // Serie = 8 bytes
TYPE DHCPCAPI_PARAMS_ARRAY DWORD   ' // array of params..
   nParams AS DWORD                ' ULONG // size of array
   Params  AS DHCPAPI_PARAMS PTR   ' LPDHCPCAPI_PARAMS // actual array
END TYPE

' // Serie = 12 bytes
TYPE DHCPCAPI_CLASSID DWORD ' // defines a client class id.
   Flags      AS DWORD      ' ULONG // must be zero currently.
   Data       AS BYTE PTR   ' LPBYTE // classid binary data.
   nBytesData AS DWORD      ' ULONG // how many bytes of data are there?
END TYPE


%DHCPCAPI_REQUEST_PERSISTENT   = &H01   ' // request this options "permanently"
%DHCPCAPI_REQUEST_SYNCHRONOUS  = &H02   ' // request and block on it
%DHCPCAPI_REQUEST_ASYNCHRONOUS = &H04   ' // request and return, set event on completion
%DHCPCAPI_REQUEST_CANCEL       = &H08   ' // cancel request
%DHCPCAPI_REQUEST_MASK         = &H0F   ' // allowed flags..

DECLARE FUNCTION DhcpCApiInitialize IMPORT "Dhcpcsvc.dll" ALIAS "DhcpCApiInitialize" ( _
   BYREF Version AS DWORD _                             ' __out LPDWORD Version
 ) AS DWORD                                             ' DWORD

DECLARE SUB DhcpCApiCleanup IMPORT "Dhcpcsvc.dll" ALIAS "DhcpCApiCleanup" ( _
 )                                                      ' void

' // request parameters of client
DECLARE FUNCTION DhcpRequestParams IMPORT "Dhcpcsvc.dll" ALIAS "DhcpRequestParams" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // must be DHCPCAPI_REQUEST_SYNCHRONOUS
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // this parameter is reserved
 , BYREF AdapterName AS WSTRINGZ _                      ' __in LPWSTR AdapterName // adapter name to request for
 , BYREF ClassId AS DHCPCAPI_CLASSID _                  ' __in LPDHCPCAPI_CLASSID ClassId // reserved must be NULL
 , BYREF SendParams AS DHCPCAPI_PARAMS_ARRAY _          ' __in DHCPCAPI_PARAMS_ARRAY SendParams // parameters to send.
 , BYREF RecdParams AS DHCPCAPI_PARAMS_ARRAY _          ' __inout DHCPCAPI_PARAMS_ARRAY RecdParams // parameters that are to be requested..
 , BYVAL Buffer AS BYTE PTR _                           ' __in LPBYTE Buffer // a buffer to hold data for RecdParams
 , BYREF pSize AS DWORD _                               ' __inout LPDWORD pSize // i/p: size of above in BYTES, o/p required bytes..
 , BYREF RequestIdStr AS WSTRINGZ _                     ' __in LPWSTR RequestIdStr // needed for persistent requests
 ) AS DWORD                                             ' DWORD // win32 status
' // returns ERROR_MORE_DATA if o/p buffer is of insufficient size, and fills in reqd size in # of bytes

' // undo the effect of a persistent request -- currently undo from registry
DECLARE FUNCTION DhcpUndoRequestParams IMPORT "Dhcpcsvc.dll" ALIAS "DhcpUndoRequestParams" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // must be zero, reserved
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // this parameter is reserved
 , BYREF AdapterName AS WSTRINGZ _                      ' __in LPWSTR AdapterName // the name of the adpater to delete for
 , BYREF RequestIdStr AS WSTRINGZ _                     ' __in LPWSTR RequestIdStr // needed for persistent requests..
 ) AS DWORD                                             ' DWORD // win32 status
' // returns ERROR_MORE_DATA if o/p buffer is of insufficient size, and fills in reqd size in # of bytes

%DHCPCAPI_REGISTER_HANDLE_EVENT = &H01???    ' // handle returned is to an event

' // notify if a parameter has changed
DECLARE FUNCTION DhcpRegisterParamChange IMPORT "Dhcpcsvc.dll" ALIAS "DhcpRegisterParamChange" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // must be zero, reserved
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // this parameter is reserved
 , BYREF AdapterName AS WSTRINGZ _                      ' __in LPWSTR AdapterName // adapter of interest
 , BYREF ClassId AS DHCPCAPI_CLASSID _                  ' __in LPDHCPCAPI_CLASSID ClassId // reserved must be NULL
 , BYREF Params AS DHCPCAPI_PARAMS_ARRAY _              ' __in DHCPCAPI_PARAMS_ARRAY Params // parameters of interest
 , BYREF Handle AS DWORD _                              ' __inout LPVOID Handle // handle to event that will be SetEvent'ed in case of param change
 ) AS DWORD                                             ' DWORD // win32 status

%DHCPCAPI_DEREGISTER_HANDLE_EVENT = &H01???   ' // de-register handle that is an event

' // undo the registration
DECLARE FUNCTION DhcpDeRegisterParamChange IMPORT "Dhcpcsvc.dll" ALIAS "DhcpDeRegisterParamChange" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags // MUST BE ZERO --> No flags yet.
 , BYVAL Reserved AS DWORD _                            ' __in LPVOID Reserved // MUST BE NULL --> Reserved
 , BYVAL Event AS DWORD _                               ' __in LPVOID Event // handle to event returned by DhcpRegisterParamChange.
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DhcpRemoveDNSRegistrations IMPORT "Dhcpcsvc.dll" ALIAS "DhcpRemoveDNSRegistrations" ( _
 ) AS DWORD                                             ' DWORD

' *** Removed from the Windows 7 SDK ***
'DECLARE FUNCTION DhcpGetOriginalSubnetMask IMPORT "Dhcpcsvc.dll" ALIAS "DhcpGetOriginalSubnetMask" ( _
'   BYREF AdapterName AS WSTRINGZ _                      ' __in LPCWSTR AdapterName
' , BYREF pSubnetMask AS DWORD _                         ' __out DWORD* pSubnetMask
' ) AS DWORD                                             ' DWORD
