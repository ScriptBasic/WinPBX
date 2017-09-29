' ########################################################################################
' Microsoft Windows
' File: pnrpns.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PNRPNS_INC = 1

'/*++

'Copyright (c) Microsoft Corporation.  All rights reserved.

'Module Name:

'    pnrpns.h

'Abstract:
'    The PNRP interface participates as a WinSock 2.0 Name Space Provider (NSP)
'    The actual functions are defined in winsock2.h of the platform SDK

'    This header file defines the specific structures and data used for PNRP.

'--*/

#INCLUDE ONCE "pnrpdef.inc"
#INCLUDE ONCE "winsock2.inc"

'// Namespaces
#IF NOT %DEF(%NS_PNRPNAME)
%NS_PNRPNAME = 38
#ENDIF

#IF NOT %DEF(%NS_PNRPCLOUD)
%NS_PNRPCLOUD = 39
#ENDIF

'//
'// Bit values used for dwFlags in PNRPINFO
'//

%PNRPINFO_HINT           = &H00000001???     ' // set if Hint valid

'//
'// PNRP specific data that is referenced by the lpBlob pointer of WSAQUERYSET
'//

' // Size = 40 bytes
TYPE PNRPINFO_V1 DWORD
   dwSize            AS DWORD            ' DWORD // size of this struct
   lpwszIdentity     AS WSTRINGZ PTR     ' LPWSTR // identity name string
   nMaxResolve       AS DWORD            ' DWORD // number of desired resolutions
   dwTimeout         AS DWORD            ' DWORD // time in seconds to wait for responses
   dwLifetime        AS DWORD            ' DWORD // time in seconds for validity
   enResolveCriteria AS LONG             ' PNRP_RESOLVE_CRITERIA // type of matching for resolves
   dwFlags           AS DWORD            ' DWORD // set of flags
   saHint            AS SOCKET_ADDRESS   ' SOCKET_ADDRESS // service location part of an ID
   enNameState       AS LONG             ' PNRP_REGISTERED_ID_STATE // state of registered name
END TYPE

' // Size = 8 bytes
UNION PNRPINFO_V2_UNION
   blobPayload AS BLOB
   pwszPayload AS WSTRINGZ PTR
END UNION

' // Size = 52 bytes
TYPE PNRPINFO_V2 DWORD
   dwSize                AS DWORD            ' DWORD // size of this struct
   lpwszIdentity         AS WSTRINGZ PTR     ' LPWSTR // identity name string
   nMaxResolve           AS DWORD            ' DWORD // number of desired resolutions
   dwTimeout             AS DWORD            ' DWORD // time in seconds to wait for responses
   dwLifetime            AS DWORD            ' DWORD // time in seconds for validity
   enResolveCriteria     AS LONG             ' PNRP_RESOLVE_CRITERIA // type of matching for resolves
   dwFlags               AS DWORD            ' DWORD // set of flags
   saHint                AS SOCKET_ADDRESS   ' SOCKET_ADDRESS // service location part of an ID
   enNameState           AS LONG             ' PNRP_REGISTERED_ID_STATE // state of registered name
   enExtendedPayloadType AS LONG             ' PNRP_EXTENDED_PAYLOAD_TYPE
   PNRPINFO_V2_UNION
END TYPE


'#if defined(PNRP_USE_V1_API)

'typedef  PNRPINFO_V1 PNRPINFO;
'typedef  PPNRPINFO_V1 PPNRPINFO;


'#else
'typedef  PNRPINFO_V2 PNRPINFO;
'typedef  PPNRPINFO_V2 PPNRPINFO;

'#endif
'//
'// Cloud specific data that is referenced by the lpBlob pointer of WSAQUERYSET
'//

' // Size = 24 bytes
TYPE PNRPCLOUDINFO DWORD
   dwSize       AS DWORD            ' DWORD // size of this struct
   Cloud        AS PNRP_CLOUD_ID    ' PNRP_CLOUD_ID // network cloud information
   enCloudState AS LONG             ' PNRP_CLOUD_STATE // state of cloud
   enCloudFlags AS LONG             ' PNRP_CLOUD_FLAGS // flags for cloud
                                    ' //   PNRP_CLOUD_NAME_LOCAL - not a network name
END TYPE


'#pragma warning(pop)


'/////////////////////////////////////////////////////////////////////////////
'//
'// These GUIDs are outside conditional includes so you can
'//   #include <pnrpns.h>   in precompiled header
'// then
'//   #include <initguid.h>  in a single source file
'//   #include <pnrpns.h>   in that source file a second time to instantiate the GUIDs

'#ifdef DEFINE_GUID

'// NSP Provider GUID
$NS_PROVIDER_PNRPNAME = GUID$("{03fe89cd-766d-4976-b9c1-bb9bc42c7b4d}")
$NS_PROVIDER_PNRPCLOUD = GUID$("{03fe89ce-766d-4976-b9c1-bb9bc42c7b4d}")

'// Service Class GUID (specific to PNRP)
$SVCID_PNRPCLOUD = GUID$("{c2239ce6-00c0-4fbf-bad6-18139385a49a}")
$SVCID_PNRPNAME_V1 = GUID$("{c2239ce5-00c0-4fbf-bad6-18139385a49a}")
$SVCID_PNRPNAME_V2 = GUID$("{c2239ce7-00c0-4fbf-bad6-18139385a49a}")

'#if defined(PNRP_USE_V2_API)

'#define SVCID_PNRPNAME SVCID_PNRPNAME_V2

'#else

'#define SVCID_PNRPNAME SVCID_PNRPNAME_V1

'#endif

'#endif // DEFINE_GUID
