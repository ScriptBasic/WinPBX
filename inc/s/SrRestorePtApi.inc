' ########################################################################################
' Microsoft Windows
' File: SRRestorePtAPI.inc
' Contents: This file contains the declarations for the SRRESTOREPT_API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SRRESTOREPTAPI_INC = 1

'//
'// Type of Event
'//

%MIN_EVENT                       = 100
%BEGIN_SYSTEM_CHANGE             = 100
%END_SYSTEM_CHANGE               = 101
%BEGIN_NESTED_SYSTEM_CHANGE      = 102   ' // for Whistler only - use this to prevent nested restore pts
%END_NESTED_SYSTEM_CHANGE        = 103   ' // for Whistler only - use this to prevent nested restore pts
%BEGIN_NESTED_SYSTEM_CHANGE_NORP = 104
%END_NESTED_SYSTEM_CHANGE_NORP   = %END_NESTED_SYSTEM_CHANGE
%MAX_EVENT                       = 104

'//
'// Type of Restore Points
'//

%MIN_RPT                = 0
%APPLICATION_INSTALL    = 0
%APPLICATION_UNINSTALL  = 1
%DESKTOP_SETTING        = 2    ' /* Not implemented */
%ACCESSIBILITY_SETTING  = 3    ' /* Not implemented */
%OE_SETTING             = 4    ' /* Not implemented */
%APPLICATION_RUN        = 5    ' /* Not implemented */
%RESTORE                = 6
%CHECKPOINT             = 7
%WINDOWS_SHUTDOWN       = 8    ' /* Not implemented */
%WINDOWS_BOOT           = 9    ' /* Not implemented */
%DEVICE_DRIVER_INSTALL  = 10
%FIRSTRUN               = 11
%MODIFY_SETTINGS        = 12
%CANCELLED_OPERATION    = 13   ' /* Only valid for END_SYSTEM_CHANGE */
%BACKUP_RECOVERY        = 14
%BACKUP                 = 15
%MANUAL_CHECKPOINT      = 16
%WINDOWS_UPDATE         = 17
%CRITICAL_UPDATE        = 18
%MAX_RPT                = 18


%MAX_DESC               = 64
%MAX_DESC_W             = 256  ' // longer for Whistler

'//
'// for Millennium compatibility
'//

'#pragma pack(push, srrestoreptapi_include)
'#pragma pack(1)

'//
'// Restore point information
'//

' // Size = 80 bytes
TYPE RESTOREPOINTINFOA BYTE
   dwEventType      AS DWORD                ' DWORD // Type of Event - Begin or End
   dwRestorePtType  AS DWORD                ' DWORD // Type of Restore Point - App install/uninstall
   llSequenceNumber AS QUAD                 ' INT64 // Sequence Number - 0 for begin
   szDescription    AS ASCIIZ * %MAX_DESC   ' CHAR  // Description - Name of Application / Operation
END TYPE

' // Size = 528 bytes
TYPE RESTOREPOINTINFOW BYTE
   dwEventType      AS DWORD                    ' DWORD // Type of Event - Begin or End
   dwRestorePtType  AS DWORD                    ' DWORD // Type of Restore Point - App install/uninstall
   llSequenceNumber AS QUAD                     ' INT64 // Sequence Number - 0 for begin
   szDescription    AS WSTRINGZ * %MAX_DESC_W   ' WCHAR  // Description - Name of Application / Operation
END TYPE

MACRO RESTOREPOINTINFO = RESTOREPOINTINFOA

'//
'// Status returned by System Restore
'//

' // Size = 12 bytes
TYPE STATEMGRSTATUS BYTE
   nStatus          AS DWORD   ' DWORD // Status returned by State Manager Process
   llSequenceNumber AS QUAD    ' INT64 // Sequence Number for the restore point
END TYPE

'#pragma pack(pop, srrestoreptapi_include)


'//
'// RPC call to set a restore point
'//
'// Return value  TRUE if the call was a success
'//               FALSE if the call failed
'//
'// If pSmgrStatus nStatus field is set as follows
'//
'// ERROR_SUCCESS              If the call succeeded (return value will be TRUE)
'//
'// ERROR_TIMEOUT              If the call timed out due to a wait on a mutex for
'//                            for setting restore points.
'//
'// ERROR_INVALID_DATA         If the cancel restore point is called with an invalid
'//                            sequence number
'//
'// ERROR_INTERNAL_ERROR       If there are internal failures.
'//
'// ERROR_BAD_ENVIRONMENT      If the API is called in SafeMode
'//
'// ERROR_SERVICE_DISABLED     If SystemRestore is Disabled.
'//
'// ERROR_DISK_FULL            If System Restore is frozen (Windows Whistler only)
'//
'// ERROR_ALREADY_EXISTS       If this is a nested restore point

DECLARE FUNCTION SRSetRestorePointA IMPORT "SRCLIENT.DLL" ALIAS "SRSetRestorePointA" ( _
   BYREF pRestorePtSpec AS RESTOREPOINTINFOA _          ' __in  PRESTOREPOINTINFOA  pRestorePtSpec // [in] Restore Point specification
 , BYREF pSMgrStatus AS STATEMGRSTATUS _                ' __out PSTATEMGRSTATUS     pSMgrStatus      // [out] Status returned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SRSetRestorePointW IMPORT "SRCLIENT.DLL" ALIAS "SRSetRestorePointW" ( _
   BYREF pRestorePtSpec AS RESTOREPOINTINFOW _          ' __in  PRESTOREPOINTINFOW  pRestorePtSpec // [in] Restore Point specification
 , BYREF pSMgrStatus AS STATEMGRSTATUS _                ' __out PSTATEMGRSTATUS     pSMgrStatus      // [out] Status returned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SRSetRestorePoint = SRSetRestorePointW
#ELSE
   MACRO SRSetRestorePoint = SRSetRestorePointA
#ENDIF

DECLARE FUNCTION SRRemoveRestorePoint IMPORT "SRCLIENT.DLL" ALIAS "SRRemoveRestorePoint" ( _
   BYVAL dwRPNum AS DWORD _                             ' __in DWORD dwRPNum
 ) AS DWORD                                             ' DWORD
