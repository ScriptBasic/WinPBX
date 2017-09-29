' ########################################################################################
' Microsoft Windows
' File: LMRemUtl.inc
' Contents: Structures, function prototypes, and definitions for the NetRemote API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMREMUTL_INC = 1

'//
'// Type Definitions
'//

'#ifndef DESC_CHAR_UNICODE
'typedef CHAR DESC_CHAR;
'#else // DESC_CHAR_UNICODE is defined
'typedef WCHAR DESC_CHAR;
'#endif // DESC_CHAR_UNICODE is defined
'typedef DESC_CHAR * LPDESC;

'//
'// Function Prototypes
'//

DECLARE FUNCTION NetRemoteTOD IMPORT "NETAPI32.DLL" ALIAS "NetRemoteTOD" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in  LPCWSTR UncServerName
 , BYREF BufferPtr AS ANY _                             ' __out LPBYTE *BufferPtr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetRemoteComputerSupports IMPORT "NETAPI32.DLL" ALIAS "NetRemoteComputerSupports" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in  LPCWSTR UncServerName OPTIONAL
 , BYVAL OptionsWanted AS DWORD _                       ' __in  DWORD OptionsWanted
 , BYREF OptionsSupported AS DWORD _                    ' __out LPDWORD OptionsSupported
 ) AS DWORD                                             ' NET_API_STATUS

'NET_API_STATUS
'__cdecl
'RxRemoteApi(
'    IN DWORD ApiNumber,
'    IN LPCWSTR UncServerName,                    // Required, with \\name.
'    IN LPDESC ParmDescString,
'    IN LPDESC DataDesc16 OPTIONAL,
'    IN LPDESC DataDesc32 OPTIONAL,
'    IN LPDESC DataDescSmb OPTIONAL,
'    IN LPDESC AuxDesc16 OPTIONAL,
'    IN LPDESC AuxDesc32 OPTIONAL,
'    IN LPDESC AuxDescSmb OPTIONAL,
'    IN DWORD  Flags,
'    ...                                         // rest of API's arguments
'    );

DECLARE FUNCTION RxRemoteApi CDECL IMPORT "NETAPI32.DLL" ALIAS "RxRemoteApi" ( _
   BYVAL ApiNumber AS DWORD _                           ' __in DWORD ApiNumber
 , BYREF UncServerName AS WSTRINGZ _                    ' __in LPCWSTR UncServerName // Required, with \\name.
 , BYVAL ParmDescString AS DWORD _                      ' __in LPDESC ParmDescString
 , BYVAL DataDesc16 AS DWORD _                          ' __in LPDESC DataDesc16 OPTIONAL
 , BYVAL DataDesc32 AS DWORD _                          ' __in LPDESC DataDesc32 OPTIONAL
 , BYVAL DataDescSmb AS DWORD _                         ' __in LPDESC DataDescSmb OPTIONAL
 , BYVAL AuxDesc16 AS DWORD _                           ' __in LPDESC AuxDesc16 OPTIONAL
 , BYVAL AuxDesc32 AS DWORD _                           ' __in LPDESC AuxDesc32 OPTIONAL
 , BYVAL AuxDescSmb AS DWORD _                          ' __in LPDESC AuxDescSmb OPTIONAL
 , BYVAL Flags AS DWORD _                               ' __in DWORD  Flags
 , OPTIONAL BYVAL DWORD _                               ' Optional parameters
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 , BYVAL DWORD _
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Data Structures
'//

' // Size = 48 bytes
TYPE TIME_OF_DAY_INFO DWORD
   tod_elapsedt  AS DWORD   ' DWORD      tod_elapsedt
   tod_msecs     AS DWORD   ' DWORD      tod_msecs
   tod_hours     AS DWORD   ' DWORD      tod_hours
   tod_mins      AS DWORD   ' DWORD      tod_mins
   tod_secs      AS DWORD   ' DWORD      tod_secs
   tod_hunds     AS DWORD   ' DWORD      tod_hunds
   tod_timezone  AS LONG    ' LONG       tod_timezone
   tod_tinterval AS DWORD   ' DWORD      tod_tinterval
   tod_day       AS DWORD   ' DWORD      tod_day
   tod_month     AS DWORD   ' DWORD      tod_month
   tod_year      AS DWORD   ' DWORD      tod_year
   tod_weekday   AS DWORD   ' DWORD      tod_weekday
END TYPE

'//
'// Special Values and Constants
'//

'//
'// Mask bits for use with NetRemoteComputerSupports:
'//

%SUPPORTS_REMOTE_ADMIN_PROTOCOL  = &H00000002???
%SUPPORTS_RPC                    = &H00000004???
%SUPPORTS_SAM_PROTOCOL           = &H00000008???
%SUPPORTS_UNICODE                = &H00000010???
%SUPPORTS_LOCAL                  = &H00000020???
%SUPPORTS_ANY                    = &HFFFFFFFF???

'//
'// Flag bits for RxRemoteApi:
'//

%NO_PERMISSION_REQUIRED  = &H00000001???     ' // set if use NULL session
%ALLOCATE_RESPONSE       = &H00000002???     ' // set if RxRemoteApi allocates response buffer
%USE_SPECIFIC_TRANSPORT  = &H80000000???
