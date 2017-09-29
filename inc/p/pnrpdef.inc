' ########################################################################################
' Microsoft Windows
' File: pnrpdef.inc
' Contents: Common PNRP related types
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PNRDEF_INC = 1

'//
'// Versioning macros
'//

'#if defined(PNRP_USE_V1_API) && defined(PNRP_USE_V2_API)
'#error Conflicting versioning macros are defined
'#endif

'#if(_WIN32_WINNT >= 0x0600)

'#if !defined(PNRP_USE_V1_API)
'#if !defined(PNRP_USE_V2_API)
'#define PNRP_USE_V2_API
'#endif
'#endif

'#else

'#if !defined(PNRP_USE_V2_API)
'#if !defined(PNRP_USE_V1_API)
'#define PNRP_USE_V1_API
'#endif
'#endif

'#endif /* _WIN32_WINNT >= 0x0600 */


%PNRP_MAX_ENDPOINT_ADDRESSES = 10

'//
'// Scope
'//
$$WSZ_SCOPE_GLOBAL            = "GLOBAL"$$
$$WSZ_SCOPE_SITELOCAL         = "SITELOCAL"$$
$$WSZ_SCOPE_LINKLOCAL         = "LINKLOCAL"$$

' enum PNRP_SCOPE
%PNRP_SCOPE_ANY                  = 0   ' //  Any
%PNRP_GLOBAL_SCOPE               = 1   ' //  global
%PNRP_SITE_LOCAL_SCOPE           = 2   ' //  site local
%PNRP_LINK_LOCAL_SCOPE           = 3   ' //  link local

'//
'// Cloud state
'//

' enum PNRP_CLOUD_STATE
%PNRP_CLOUD_STATE_VIRTUAL       = 0   ' //  Not initialized
%PNRP_CLOUD_STATE_SYNCHRONISING = 1   ' //  The cache is initializing
%PNRP_CLOUD_STATE_ACTIVE        = 2   ' //  Cloud is active
%PNRP_CLOUD_STATE_DEAD          = 3   ' //  Initialized but has had a problem
%PNRP_CLOUD_STATE_DISABLED      = 4   ' //  Cloud is not disbaled in registery
%PNRP_CLOUD_STATE_NO_NET        = 5   ' //  Was active, but now has lost access to net
%PNRP_CLOUD_STATE_ALONE         = 6   ' //  Cloud is in standalone mode

'//
'// Cloud Flags values
'//  These should be powers of 2 so they can be ORed together
'//

' enum PNRP_CLOUD_FLAGS
%PNRP_CLOUD_NO_FLAGS            = 0
%PNRP_CLOUD_NAME_LOCAL          = 1   ' //  Name not valid on other computers
%PNRP_CLOUD_RESOLVE_ONLY        = 2
%PNRP_CLOUD_FULL_PARTICIPANT    = 4

'//
'// Registered name state
'//

' enum PNRP_REGISTERED_ID_STATE
%PNRP_REGISTERED_ID_STATE_OK      = 1   ' //  Id is active in cloud
%PNRP_REGISTERED_ID_STATE_PROBLEM = 2   ' //  Id is no longer registered in cloud

'//
'// Resolve criteria
'//

' enum PNRP_RESOLVE_CRITERIA
%PNRP_RESOLVE_CRITERIA_DEFAULT           = 0           ' // Default = PNRP_RESOLVE_CRITERIA_NON_CURRENT_PROCESS_PEER_NAME
%PNRP_RESOLVE_CRITERIA_REMOTE_PEER_NAME  = 1           ' // match first 128 bits (remote node)
%PNRP_RESOLVE_CRITERIA_NEAREST_REMOTE_PEER_NAME = 2    ' // match first 128 bits, and close to top 64 bits
                                                       ' // of the second 128 bits (remote node)
%PNRP_RESOLVE_CRITERIA_NON_CURRENT_PROCESS_PEER_NAME = 3   ' //  match first 128 bits (not in the current process)
%PNRP_RESOLVE_CRITERIA_NEAREST_NON_CURRENT_PROCESS_PEER_NAME = 4   ' // match first 128 bits, and close to top 64 bits
                                                                   ' // of the second 128 bits (not in the current process)
%PNRP_RESOLVE_CRITERIA_ANY_PEER_NAME     = 5           ' // match first 128 bits (any node)
%PNRP_RESOLVE_CRITERIA_NEAREST_PEER_NAME = 6           '  // match first 128 bits, and close to top 64 bits
                                                       ' // of the second 128 bits (any node)

'//
'// PNRP Cloud identification
'//

' // Size = 12 bytes
TYPE PNRP_CLOUD_ID DWORD
   AddressFamily AS LONG    ' INT // should be AF_INET6
   Scope         AS LONG    ' PNRP_SCOPE // Global, site, or link
   ScopeId       AS DWORD   ' ULONG // specifies interface
END TYPE


'//
'// Extended payload type
'//

' enum PNRP_EXTENDED_PAYLOAD_TYPE
%PNRP_EXTENDED_PAYLOAD_TYPE_NONE   = 0
%PNRP_EXTENDED_PAYLOAD_TYPE_BINARY = 1
%PNRP_EXTENDED_PAYLOAD_TYPE_STRING = 2

%PNRP_MAX_EXTENDED_PAYLOAD_BYTES = &H1000
