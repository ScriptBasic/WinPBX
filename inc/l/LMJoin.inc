' ########################################################################################
' Microsoft Windows
' File: LMJoin.inc
' Contents: Definitions and prototypes for the Net setup apis, for joining/unjoinging
' domains and promoting/demoting servers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMJOIN_INC = 1

'//
'// Types of name that can be validated
'//

' NETSETUP_NAME_TYPE enum
%NetSetupUnknown           = 0
%NetSetupMachine           = 1
%NetSetupWorkgroup         = 2
%NetSetupDomain            = 3
%NetSetupNonExistentDomain = 4
'#if(_WIN32_WINNT >= 0x0500)
%NetSetupDnsMachine        = 5
'#endif

'//
'// Status of a workstation
'//

' NETSETUP_JOIN_STATUS enum
%NetSetupUnknownStatus = 0
%NetSetupUnjoined      = 1
%NetSetupWorkgroupName = 2
%NetSetupDomainName    = 3

'//
'// Flags to determine the behavior of the join/unjoin APIs
'//
%NETSETUP_JOIN_DOMAIN              = &H00000001???   ' // If not present, workgroup is joined
%NETSETUP_ACCT_CREATE              = &H00000002???   ' // Do the server side account creation/rename
%NETSETUP_ACCT_DELETE              = &H00000004???   ' // Delete the account when a domain is left
%NETSETUP_WIN9X_UPGRADE            = &H00000010???   ' // Invoked during upgrade of Windows 9x to
                                                     ' // Windows NT
%NETSETUP_DOMAIN_JOIN_IF_JOINED    = &H00000020???   ' // Allow the client to join a new domain
                                                     ' // even if it is already joined to a domain
%NETSETUP_JOIN_UNSECURE            = &H00000040???   ' // Performs an unsecure join
%NETSETUP_MACHINE_PWD_PASSED       = &H00000080???   ' // Indicates that the machine (not user) password
                                                     ' //  is passed. Valid only for unsecure joins
%NETSETUP_DEFER_SPN_SET            = &H00000100???   ' // Specifies that writting SPN and DnsHostName
                                                     ' //  attributes on the computer object should be
                                                     ' //  defered until rename that will follow join

%NETSETUP_JOIN_DC_ACCOUNT          = &H00000200???   ' // Allow join if existing account is a DC
%NETSETUP_JOIN_WITH_NEW_NAME       = &H00000400???   ' // Check for computer name change
%NETSETUP_JOIN_READONLY            = &H00000800???   ' // Perform join using a pre-created account w/o requiring a writable DC
%NETSETUP_DNS_NAME_CHANGES_ONLY    = &H00001000???   ' // When performing machine rename only update DNS based names

%NETSETUP_INSTALL_INVOCATION       = &H00040000???   ' // The APIs were invoked during install

%NETSETUP_AMBIGUOUS_DC             = &H00001000???   ' // When joiing the domain don't try to set the
                                                     ' // preferred DC in the registry.
%NETSETUP_NO_NETLOGON_CACHE        = &H00002000???   ' // Don't create the netlogon cache
%NETSETUP_DONT_CONTROL_SERVICES    = &H00004000???   ' // Don't force netlogon to start
%NETSETUP_SET_MACHINE_NAME         = &H00008000???   ' // For offline join only, set target machine hostname and NB name.
%NETSETUP_FORCE_SPN_SET            = &H00010000???   ' // Override other settings during domain join
                                                     ' // and attempt to set the SPN.
%NETSETUP_NO_ACCT_REUSE            = &H00020000???   ' // Do not reuse an existing account

%NETSETUP_IGNORE_UNSUPPORTED_FLAGS = &H10000000???   ' // If this bit is set, unrecognized flags
                                                     ' //  will be ignored by the NetJoin API and
                                                     ' //  the API will behave as if the flags
                                                     ' //  were not set.

%NETSETUP_VALID_UNJOIN_FLAGS = %NETSETUP_ACCT_DELETE OR %NETSETUP_IGNORE_UNSUPPORTED_FLAGS OR %NETSETUP_JOIN_DC_ACCOUNT

'// The following flags are used when the system is processing information left from a prior offline
'// join.  We want to force DC discovery and we don't want to create the netlogon cache.  We also
'// don't want to immediately force netlogon to start, let it start on its own.
%NETSETUP_PROCESS_OFFLINE_FLAGS = %NETSETUP_JOIN_DOMAIN OR _
                                  %NETSETUP_DOMAIN_JOIN_IF_JOINED OR _
                                  %NETSETUP_JOIN_WITH_NEW_NAME OR _
                                  %NETSETUP_DONT_CONTROL_SERVICES OR _
                                  %NETSETUP_MACHINE_PWD_PASSED

'//
'// 0x80000000 is reserved for internal use only
'//

'//
'// Joins a machine to the domain.
'//
DECLARE FUNCTION NetJoinDomain IMPORT "NETAPI32.DLL" ALIAS "NetJoinDomain" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR lpServer OPTIONAL
 , BYREF lpDomain AS WSTRINGZ _                         ' __in  LPCWSTR lpDomain
 , BYREF lpAccountOU AS WSTRINGZ _                      ' __in  LPCWSTR lpAccountOU, OPTIONAL
 , BYREF lpAccount AS WSTRINGZ _                        ' __in  LPCWSTR lpAccount OPTIONAL
 , BYREF lpPassword AS WSTRINGZ _                       ' __in  LPCWSTR lpPassword OPTIONAL
 , BYVAL fJoinOptions AS DWORD _                        ' __in  DWORD   fJoinOptions
 ) AS DWORD                                             ' NET_API_STATUS

'#if(_WIN32_WINNT >= 0x0601)

'//
'// Flags to determine the behavior of NetProvisionComputerAccount
'//

'// The caller requires account creation by privilege, this option will cause a retry
'// on failure using down level account creation APIs.
'//
%NETSETUP_PROVISION_DOWNLEVEL_PRIV_SUPPORT = &H00000001???

'// If the named account already exists an attempt will be made to reuse. Requires
'// sufficient credentials i.e. Domain Administrator or the object owner.
'//
%NETSETUP_PROVISION_REUSE_ACCOUNT          = &H00000002???

'// Use the default machine account password which is the machine name in lowercase.
'//
%NETSETUP_PROVISION_USE_DEFAULT_PASSWORD   = &H00000004???

'// Do not try to find the account on any DC in the domain. This is faster but
'// should only be used when the caller is certain that an account by the same
'// name hasn't recently been created. Only valid when specifying the target DC.
'// When the pre-requisites are met, this option allows for must faster provisioning
'// useful for scenarios such as batch processing.
'//
%NETSETUP_PROVISION_SKIP_ACCOUNT_SEARCH    = &H00000008???

'//
'// The following are reserved for internal use.
'//

'// The operation is online.
'// This is an internal option not available through the API.
'//
%NETSETUP_PROVISION_ONLINE_CALLER          = &H40000000???

'// Validate the machine password only. This is an internal option not available
'// through the API.
'//
%NETSETUP_PROVISION_CHECK_PWD_ONLY         = &H80000000???

DECLARE FUNCTION NetProvisionComputerAccount IMPORT "NETAPI32.DLL" ALIAS "NetProvisionComputerAccount" ( _
   BYREF lpDomain AS WSTRINGZ _                         ' __in      LPCWSTR lpDomain
 , BYREF lpMachineName AS WSTRINGZ _                    ' __in      LPCWSTR lpMachineName
 , BYREF lpMachineAccountOU AS WSTRINGZ _               ' __in_opt  LPCWSTR lpMachineAccountOU
 , BYREF lpDcName AS WSTRINGZ _                         ' __in_opt  LPCWSTR lpDcName
 , BYVAL dwOptions AS DWORD _                           ' __in      DWORD   dwOptions
 , BYREF pProvisionBinData AS ANY _                     ' __out_opt PBYTE  *pProvisionBinData
 , BYREF pdwProvisionBinDataSize AS DWORD _             ' __out_opt DWORD  *pdwProvisionBinDataSize
 , BYREF pProvisionTextData AS ANY _                    ' __out_opt LPWSTR *pProvisionTextData
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetRequestOfflineDomainJoin IMPORT "NETAPI32.DLL" ALIAS "NetRequestOfflineDomainJoin" ( _
   BYVAL pProvisionBinData AS BYTE PTR _                ' __in_bcount(cbProvisionBinDataSize) BYTE *pProvisionBinData
 , BYVAL cbProvisionBinDataSize AS DWORD _              ' __in DWORD   cbProvisionBinDataSize
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD   dwOptions
 , BYREF lpWindowsPath AS WSTRINGZ _                    ' __in LPCWSTR lpWindowsPath
 ) AS DWORD                                             ' NET_API_STATUS

'#endif // (_WIN32_WINNT >= 0x0601)

DECLARE FUNCTION NetUnjoinDomain IMPORT "NETAPI32.DLL" ALIAS "NetUnjoinDomain" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR lpServer OPTIONAL
 , BYREF lpAccount AS WSTRINGZ _                        ' __in  LPCWSTR lpAccount OPTIONAL
 , BYREF lpPassword AS WSTRINGZ _                       ' __in  LPCWSTR lpPassword OPTIONAL
 , BYVAL fUnjoinOptions AS DWORD _                      ' __in  DWORD   fUnjoinOptions
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetRenameMachineInDomain IMPORT "NETAPI32.DLL" ALIAS "NetRenameMachineInDomain" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR lpServer OPTIONAL
 , BYREF lpNewMachineName AS WSTRINGZ _                 ' __in  LPCWSTR lpNewMachineName OPTIONAL
 , BYREF lpAccount AS WSTRINGZ _                        ' __in  LPCWSTR lpAccount OPTIONAL
 , BYREF lpPassword AS WSTRINGZ _                       ' __in  LPCWSTR lpPassword OPTIONAL
 , BYVAL fRenameOptions AS DWORD _                      ' __in  DWORD   fRenameOptions
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Determine the validity of a name
'//

DECLARE FUNCTION NetValidateName IMPORT "NETAPI32.DLL" ALIAS "NetValidateName" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR             lpServer OPTIONAL
 , BYREF lpName AS WSTRINGZ _                           ' __in  LPCWSTR             lpName
 , BYREF lpAccount AS WSTRINGZ _                        ' __in  LPCWSTR             lpAccount OPTIONAL
 , BYREF lpPassword AS WSTRINGZ _                       ' __in  LPCWSTR             lpPassword OPTIONAL
 , BYVAL NameType AS LONG _                             ' __in  NETSETUP_NAME_TYPE  NameType
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Determines whether a workstation is joined to a domain or not
'//

DECLARE FUNCTION NetGetJoinInformation IMPORT "NETAPI32.DLL" ALIAS "NetGetJoinInformation" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in   LPCWSTR                lpServer OPTIONAL
 , BYREF lpNameBuffer AS ANY _                          ' __out  LPWSTR                *lpNameBuffer
 , BYREF BufferType AS LONG _                           ' __out  PNETSETUP_JOIN_STATUS  BufferType
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Determines the list of OUs that the client can create a machine account in
'//

DECLARE FUNCTION NetGetJoinableOUs IMPORT "NETAPI32.DLL" ALIAS "NetGetJoinableOUs" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR     lpServer OPTIONAL
 , BYREF lpDomain AS WSTRINGZ _                         ' __in  LPCWSTR     lpDomain
 , BYREF lpAccount AS WSTRINGZ _                        ' __in  LPCWSTR     lpAccount OPTIONAL
 , BYREF lpPassword AS WSTRINGZ _                       ' __in  LPCWSTR     lpPassword OPTIONAL
 , BYREF OUCount AS DWORD _                             ' __out DWORD      *OUCount
 , BYREF OUs AS ANY _                                   ' __out LPWSTR    **OUs
 ) AS DWORD                                             ' NET_API_STATUS

'#if(_WIN32_WINNT >= 0x0501)

'//
'// Computer rename preparation APIs
'//

'#define NET_IGNORE_UNSUPPORTED_FLAGS  0x01
%NET_IGNORE_UNSUPPORTED_FLAGS  = &H01

DECLARE FUNCTION NetAddAlternateComputerName IMPORT "NETAPI32.DLL" ALIAS "NetAddAlternateComputerName" ( _
   BYREF Server AS WSTRINGZ _                           ' __in  LPCWSTR Server OPTIONAL
 , BYREF AlternateName AS WSTRINGZ _                    ' __in  LPCWSTR AlternateName
 , BYREF DomainAccount AS WSTRINGZ _                    ' __in  LPCWSTR DomainAccount OPTIONAL
 , BYREF DomainAccountPassword AS WSTRINGZ _            ' __in  LPCWSTR DomainAccountPassword OPTIONAL
 , BYVAL Reserved AS DWORD _                            ' __in  ULONG Reserved
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetRemoveAlternateComputerName IMPORT "NETAPI32.DLL" ALIAS "NetRemoveAlternateComputerName" ( _
   BYREF Server AS WSTRINGZ _                           ' __in  LPCWSTR Server OPTIONAL
 , BYREF AlternateName AS WSTRINGZ _                    ' __in  LPCWSTR AlternateName
 , BYREF DomainAccount AS WSTRINGZ _                    ' __in  LPCWSTR DomainAccount OPTIONAL
 , BYREF DomainAccountPassword AS WSTRINGZ _            ' __in  LPCWSTR DomainAccountPassword OPTIONAL
 , BYVAL Reserved AS DWORD _                            ' __in  ULONG Reserved
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetSetPrimaryComputerName IMPORT "NETAPI32.DLL" ALIAS "NetSetPrimaryComputerName" ( _
   BYREF Server AS WSTRINGZ _                           ' __in  LPCWSTR Server OPTIONAL
 , BYREF PrimaryName AS WSTRINGZ _                      ' __in  LPCWSTR PrimaryName
 , BYREF DomainAccount AS WSTRINGZ _                    ' __in  LPCWSTR DomainAccount OPTIONAL
 , BYREF DomainAccountPassword AS WSTRINGZ _            ' __in  LPCWSTR DomainAccountPassword OPTIONAL
 , BYVAL Reserved AS DWORD _                            ' __in  ULONG Reserved
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// The following enumeration must be kept
'// in sync with COMPUTER_NAME_TYPE defined
'// in winbase.h
'//

' NET_COMPUTER_NAME_TYPE enum
%NetPrimaryComputerName    = 0
%NetAlternateComputerNames = 1
%NetAllComputerNames       = 2
%NetComputerNameTypeMax    = 3

DECLARE FUNCTION NetEnumerateComputerNames IMPORT "NETAPI32.DLL" ALIAS "NetEnumerateComputerNames" ( _
   BYREF Server AS WSTRINGZ _                           ' __in  LPCWSTR Server OPTIONAL
 , BYVAL NameType AS LONG _                             ' __in  NET_COMPUTER_NAME_TYPE NameType
 , BYVAL Reserved AS DWORD _                            ' __in  ULONG Reserved
 , BYREF EntryCount AS DWORD _                          ' __out PDWORD EntryCount
 , BYREF ComputerNames AS ANY _                         ' __out LPWSTR **ComputerNames
 ) AS DWORD                                             ' NET_API_STATUS

'#endif // (_WIN32_WINNT >= 0x0501)
