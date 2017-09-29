' ########################################################################################
' Microsoft Windows
' File: RestartManager.inc
' Contents: Header for RestartManager API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RESTARTMANAGER_INC = 1

#INCLUDE ONCE "windows.inc"

'// Macros and Types

'// RM_SESSION_KEY_LEN - size in bytes of binary session key
'#define RM_SESSION_KEY_LEN  sizeof(GUID)
%RM_SESSION_KEY_LEN = 16
'// CCH_RM_SESSION_KEY - character count of text-encoded session key
%CCH_RM_SESSION_KEY = %RM_SESSION_KEY_LEN * 2
'// CCH_RM_MAX_APP_NAME - maximum character count of application friendly name
%CCH_RM_MAX_APP_NAME = 255
'// CCH_RM_MAX_SVC_NAME - maximum character count of service short name
%CCH_RM_MAX_SVC_NAME = 63
'// Uninitialized value for TS Session ID
%RM_INVALID_TS_SESSION = -1
'// Uninitialized value for Process ID
%RM_INVALID_PROCESS = -1

' enum RM_APP_TYPE
%RmUnknownApp  = 0      ' // Application type cannot be classified in
                        ' // known categories
%RmMainWindow  = 1      ' // Application is a windows application that
                        ' // displays a top-level window
%RmOtherWindow = 2      ' // Application is a windows app but does not
                        ' // display a top-level window
%RmService     = 3      ' // Application is an NT service
%RmExplorer    = 4      ' // Application is Explorer
%RmConsole     = 5      ' // Application is Console application
%RmCritical    = 1000   ' // Application is critical system process
                        ' // where a reboot is required to restart

' enum RM_SHUTDOWN_TYPE
%RmForceShutdown = &H1             ' // Force app shutdown
%RmShutdownOnlyRegistered = &H10   ' // Only shudown apps if all apps
                                   ' // registered for restart

' enum RM_APP_STATUS
%RmStatusUnknown        = &H0    ' // Application in unknown state
                                 ' // or state not important
%RmStatusRunning        = &H1    ' // Application is currently running
%RmStatusStopped        = &H2    ' // Application stopped by Restart Manager
%RmStatusStoppedOther   = &H4    ' // Application detected stopped
                                 ' // by outside action
%RmStatusRestarted      = &H8    ' // Application restarted by Restart Manager
%RmStatusErrorOnStop    = &H10   ' // An error occurred when stopping
                                 ' // this application
%RmStatusErrorOnRestart = &H20   ' // An error occurred when restarting
                                 ' // this application
%RmStatusShutdownMasked = &H40   ' // Shutdown action masked by filer
%RmStatusRestartMasked  = &H80   ' // Restart action masked by filter

' enum RM_REBOOT_REASON
%RmRebootReasonNone             = &H0    ' // Reboot not required
%RmRebootReasonPermissionDenied = &H1    ' // Current user does not have
                                         ' // permission to shut down
                                         ' // one or more detected processes
%RmRebootReasonSessionMismatch  = &H2    ' // One or more processes are
                                         ' // running in another TS session.
%RmRebootReasonCriticalProcess  = &H4    ' // A critical process has been
                                         ' // detected
%RmRebootReasonCriticalService  = &H8    ' // A critical service has been
                                         ' // detected
%RmRebootReasonDetectedSelf     = &H10   ' // The current process has been
                                         ' // detected

' // Size = 12 bytes
TYPE RM_UNIQUE_PROCESS DWORD
   dwProcessId      AS DWORD      ' DWORD // PID
   ProcessStartTime AS FILETIME   ' FILETIME // Process creation time
END TYPE

' // Size = 668 bytes
TYPE RM_PROCESS_INFO DWORD
   Process             AS RM_UNIQUE_PROCESS     ' // Unique process identification
   strAppName          AS WSTRINGZ * %CCH_RM_MAX_APP_NAME + 1  ' WCHAR // Application friendly name
   strServiceShortName AS WSTRINGZ * %CCH_RM_MAX_SVC_NAME + 1  ' WCHAR // Service short name,
                                                                 ' // if applicable
   ApplicationType     AS LONG                  ' RM_APP_TYPE // Application type
   AppStatus           AS DWORD                 ' ULONG // Bit mask of application status
   TSSessionId         AS DWORD                 ' DWORD // Terminal Service session ID of
                                                ' // process (-1 if n/a)
   bRestartable        AS LONG                  ' BOOL // Is application restartable?
END TYPE

' enum RM_FILTER_TRIGGER
%RmFilterTriggerInvalid = 0   ' // Invalid value
%RmFilterTriggerFile    = 1   ' // Filter is triggered by EXE name
%RmFilterTriggerProcess = 2   ' // Filter is triggered by PID/create time
%RmFilterTriggerService = 3   ' // Filter is triggered by service short name

' enum _RM_FILTER_ACTION {
%RmInvalidFilterAction  = 0   ' // Invalid value
%RmNoRestart            = 1   ' // Prevent restart of application
%RmNoShutdown           = 2   ' // Prevent shutdown and restart of
                              ' // application

' // Size = 12 bytes
UNION RM_FILTER_INFO_UNION DWORD
   strFilename         AS WSTRINGZ PTR        ' LPWSTR // When RmFilterTrigger == RmFilterTriggerFile,
                                              ' // this contains the filename this filter applies to
   Process             AS RM_UNIQUE_PROCESS   ' // When RmFilterTrigger == RmFilterTriggerProcess,
                                              ' // this contains the process this filter applies to
   strServiceShortName AS WSTRINGZ PTR        ' LPWSTR // When RmFilterTrigger == RmFilterTriggerService,
                                              ' // this contians the service name this filter applies to
END UNION

' // Size = 24 bytes
TYPE RM_FILTER_INFO DWORD
   FilterAction  AS LONG    ' RM_FILTER_ACTION // Filter action
   FilterTrigger AS LONG    ' RM_FILTER_TRIGGER // Filter trigger
   cbNextOffset  AS DWORD   ' DWORD // Bytes to next structure
   RM_FILTER_INFO_UNION
END TYPE

'typedef void (*RM_WRITE_STATUS_CALLBACK)( __in UINT nPercentComplete );
'SUB RM_WRITE_STATUS_CALLBACK (BYVAL nPercentComplete AS DWORD)


'// Functions

'// Function: RmStartSession
'// Purpose: Begins a Restart Manager session as the Conductor
'// Error Codes:
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.

DECLARE FUNCTION RmStartSession IMPORT "Rstrtmgr.dll" ALIAS "RmStartSession" ( _
   BYREF pSessionHandle AS DWORD _                      ' __out DWORD *pSessionHandle
 , BYVAL dwSessionFlags AS DWORD _                      ' __reserved DWORD dwSessionFlags
 , BYREF strSessionKey AS WSTRINGZ _                    ' __out_ecount(CCH_RM_SESSION_KEY+1) WCHAR strSessionKey[])
 ) AS DWORD                                             ' DWORD

'// Function: RmJoinSession
'// Purpose: Joins an existing Restart Manager session as a Subordinate
'// Error Codes:
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.

DECLARE FUNCTION RmJoinSession IMPORT "Rstrtmgr.dll" ALIAS "RmJoinSession" ( _
   BYREF pSessionHandle AS DWORD _                      ' __out DWORD *pSessionHandle
 , BYREF strSessionKey AS WSTRINGZ _                    ' __out_ecount(CCH_RM_SESSION_KEY+1) WCHAR strSessionKey[])
 ) AS DWORD                                             ' DWORD

'// Function: RmEndSession
'// Purpose: Terminates and cleans up an existing session.
'// Error Codes:
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmEndSession IMPORT "Rstrtmgr.dll" ALIAS "RmEndSession" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 ) AS DWORD                                             ' DWORD

'// Function: RmRegisterResources
'// Purpose: Called if error is encountered. Installer
'//          must pass in all files to be updated
'//          that may prevent the install from completing. Processes
'//          passed in array are forced to stop/start. Services short
'//          names passed in array are stopped (along with dependencies
'//          and restarted.
'// Error Codes:
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmRegisterResources IMPORT "Rstrtmgr.dll" ALIAS "RmRegisterResources" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYVAL nFiles AS DWORD _                              ' __in UINT nFiles
 , BYREF rgsFileNames AS WSTRINGZ _                     ' __in_opt LPCWSTR rgsFileNames[]
 , BYVAL nApplications AS DWORD _                       ' __in UINT nApplications
 , BYREF rgApplications AS RM_UNIQUE_PROCESS _          ' __in_opt RM_UNIQUE_PROCESS rgApplications[]
 , BYVAL nServices AS DWORD _                           ' __in UINT nServices
 , OPTIONAL BYREF rgsServiceNames AS WSTRINGZ _         ' __in_opt LPCWSTR rgsServiceNames[]
 ) AS DWORD                                             ' DWORD

'// Function: RmGetList
'// Purpose: Gets the list of applications affected by registered
'//          resources and their current status.
'// Returns: An array of RM_PROCESS_INFO structs containing a list of
'//          all applications affected by registered items, the number
'//          of structs needed to retreive all application information,
'//          the number of structs that were populated, and a series
'//          of flags describing why a reboot will be necessary.
'// Error Codes:
'//        ERROR_MORE_DATA
'//            Buffer is not large enough for all information.
'//        ERROR_CANCELLED
'//            Operation was cancelled by user.
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmGetList IMPORT "Rstrtmgr.dll" ALIAS "RmGetList" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYREF pnProcInfoNeeded AS DWORD _                    ' __out UINT pnProcInfoNeeded
 , BYREF pnProcInfo AS DWORD _                          ' __in_out DWORD pnProcInfo
 , BYREF rgAffectedApps AS RM_PROCESS_INFO _            ' __in_out RM_PROCESS_INFO rgAffectedApps[]
 , BYREF lpdwRebootReasons AS DWORD _                   ' __out LPDWORD lpdwRebootReasons
 ) AS DWORD                                             ' DWORD

'// Function: RmShutdown
'// Purpose: Initiates application shutdown sequence.
'// Error Codes:
'//        ERROR_FAIL_NOACTION_REBOOT
'//            One or more of the affected applications requires a reboot
'//            to be shut down.
'//        ERROR_FAIL_SHUTDOWN
'//            There was an error shuting down some application(s).
'//        ERROR_CANCELLED
'//            Operation was cancelled by user.
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmShutdown IMPORT "Rstrtmgr.dll" ALIAS "RmShutdown" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYVAL lActionFlags AS DWORD _                        ' __in ULONG lActionFlags
 , OPTIONAL BYVAL fnStatus AS DWORD _                   ' __in_opt RM_WRITE_STATUS_CALLBACK fnStatus
 ) AS DWORD                                             ' DWORD

'// Function: RmRestart
'// Purpose: Applications automatically shutdown by RmShutdown()
'//          and are registered for restart or are services are restarted.
'// Error Codes:
'//        ERROR_FAIL_NOACTION_REBOOT
'//            One or more of the affected applications requires a reboot
'//            to be shut down.
'//        ERROR_FAIL_SHUTDOWN
'//            There was an error shuting down some application(s).
'//        ERROR_CANCELLED
'//            Operation was cancelled by user.
'//        ERROR_SEM_TIMEOUT
'//            Failed to obtain semaphore lock in allotted time.
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_WRITE_FAULT
'//            Read/write operation failed.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmRestart IMPORT "Rstrtmgr.dll" ALIAS "RmRestart" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYVAL dwRestartFlags AS DWORD _                      ' __reserved DWORD dwRestartFlags
 , OPTIONAL BYVAL fnStatus AS DWORD _                   ' __in_opt RM_WRITE_STATUS_CALLBACK fnStatus
 ) AS DWORD                                             ' DWORD

'// Function: RmCancelCurrentTask()
'// Purpose: Notifies Restart Manager to cancel the task it is performing
'//          as soon as possible.
'// Error Codes:
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_OUTOFMEMORY
'//            Could not allocate memory or instantiate class object.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmCancelCurrentTask IMPORT "Rstrtmgr.dll" ALIAS "RmCancelCurrentTask" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 ) AS DWORD                                             ' DWORD

'// Function: RmAddFilter()
'// Purpose: Adds a filter for process module (ie. executable name), process ID,
'//          or service short name to prevent Restart Manager from performing
'//          the specified action on the process(es) or service noted.
'// Error Codes:
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmAddFilter IMPORT "Rstrtmgr.dll" ALIAS "RmAddFilter" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYREF strModuleName AS WSTRINGZ _                    ' __in_opt LPCWSTR strModuleName
 , BYREF pProcess AS RM_UNIQUE_PROCESS _                ' __in_opt RM_UNIQUE_PROCESS *pProcess
 , BYREF strServiceShortName AS WSTRINGZ _              ' __in_opt LPCWSTR strServiceShortName
 , BYVAL FilterAction AS LONG _                         ' __in RM_FILTER_ACTION FilterAction
 ) AS DWORD                                             ' DWORD

'// Function: RmRemoveFilter()
'// Purpose: Removes a previously added filter for process module
'//          (ie. executable name), process ID, or service short name
'//          enabling all Restart Manager actions on the process(es)
'//          or service noted.
'// Error Codes:
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmRemoveFilter IMPORT "Rstrtmgr.dll" ALIAS "RmRemoveFilter" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYREF strModuleName AS WSTRINGZ _                    ' __in_opt LPCWSTR strModuleName
 , BYREF pProcess AS RM_UNIQUE_PROCESS _                ' __in_opt RM_UNIQUE_PROCESS *pProcess
 , OPTIONAL BYREF strServiceShortName AS WSTRINGZ _     ' __in_opt LPCWSTR strServiceShortName
 ) AS DWORD                                             ' DWORD

'// Function: RmGetFilterList()
'// Purpose: Writes a set of currenly applied filters
'//          to a caller-allocated buffer.
'// Error Codes:
'//        ERROR_BAD_ARGUMENTS
'//            An invalid argument was supplied to the function.
'//        ERROR_INVALID_HANDLE
'//            No session exists for the supplied handle.

DECLARE FUNCTION RmGetFilterList IMPORT "Rstrtmgr.dll" ALIAS "RmGetFilterList" ( _
   BYVAL dwSessionHandle AS DWORD _                     ' __in DWORD dwSessionHandle
 , BYVAL pbFilterBuf AS BYTE PTR _                      ' __out_opt PBYTE pbFilterBuf
 , BYVAL cbFilterBuf AS DWORD _                         ' __in DWORD cbFilterBuf
 , BYREF cbFilterBufNeeded AS DWORD _                   ' __out LPDWORD cbFilterBufNeeded
 ) AS DWORD                                             ' DWORD
