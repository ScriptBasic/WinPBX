' ########################################################################################
' Microsoft Windows
' File: WinSvc.inc
' Contents: Header file for the Service Control Manager
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSVC_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// Constants
'//

'//
'// Service database names
'//

$$SERVICES_ACTIVE_DATABASEW   = "ServicesActive"$$
$$SERVICES_FAILED_DATABASEW   = "ServicesFailed"$$
$SERVICES_ACTIVE_DATABASEA    = "ServicesActive"
$SERVICES_FAILED_DATABASEA    = "ServicesFailed"

'//
'// Character to designate that a name is a group
'//

$$SC_GROUP_IDENTIFIERW               = "+"$$
$SC_GROUP_IDENTIFIERA                = "+"

' // For compatibility with the PB declares
%SC_GROUP_IDENTIFIERW        = &H002b  ' "+"$$
%SC_GROUP_IDENTIFIERA        = &H2b    ' "+"

#IF %DEF(%UNICODE)
   MACRO SERVICES_ACTIVE_DATABASE = $$SERVICES_ACTIVE_DATABASEW
   MACRO SERVICES_FAILED_DATABASE = $$SERVICES_FAILED_DATABASEW
   %SC_GROUP_IDENTIFIER = %SC_GROUP_IDENTIFIERW
#ELSE ' NOT %DEF UNICODE
   MACRO SERVICES_ACTIVE_DATABASE = $SERVICES_ACTIVE_DATABASEA
   MACRO SERVICES_FAILED_DATABASE = $SERVICES_FAILED_DATABASEA
   %SC_GROUP_IDENTIFIER = %SC_GROUP_IDENTIFIERA
#ENDIF ' NOT %DEF UNICODE

'//
'// Value to indicate no change to an optional parameter
'//
%SERVICE_NO_CHANGE = &HFFFFFFFF???

'//
'// Service State -- for Enum Requests (Bit Mask)
'//
%SERVICE_ACTIVE    = &H00000001???
%SERVICE_INACTIVE  = &H00000002???
%SERVICE_STATE_ALL = %SERVICE_ACTIVE OR %SERVICE_INACTIVE

'//
'// Controls
'//
%SERVICE_CONTROL_STOP                  = &H00000001???
%SERVICE_CONTROL_PAUSE                 = &H00000002???
%SERVICE_CONTROL_CONTINUE              = &H00000003???
%SERVICE_CONTROL_INTERROGATE           = &H00000004???
%SERVICE_CONTROL_SHUTDOWN              = &H00000005???
%SERVICE_CONTROL_PARAMCHANGE           = &H00000006???
%SERVICE_CONTROL_NETBINDADD            = &H00000007???
%SERVICE_CONTROL_NETBINDREMOVE         = &H00000008???
%SERVICE_CONTROL_NETBINDENABLE         = &H00000009???
%SERVICE_CONTROL_NETBINDDISABLE        = &H0000000A???
%SERVICE_CONTROL_DEVICEEVENT           = &H0000000B???
%SERVICE_CONTROL_HARDWAREPROFILECHANGE = &H0000000C???
%SERVICE_CONTROL_POWEREVENT            = &H0000000D???
%SERVICE_CONTROL_SESSIONCHANGE         = &H0000000E???
%SERVICE_CONTROL_PRESHUTDOWN           = &H0000000F???
%SERVICE_CONTROL_TIMECHANGE            = &H00000010???
%SERVICE_CONTROL_TRIGGEREVENT          = &H00000020???

'//
'// Service State -- for CurrentState
'//
%SERVICE_STOPPED                       = &H00000001???
%SERVICE_START_PENDING                 = &H00000002???
%SERVICE_STOP_PENDING                  = &H00000003???
%SERVICE_RUNNING                       = &H00000004???
%SERVICE_CONTINUE_PENDING              = &H00000005???
%SERVICE_PAUSE_PENDING                 = &H00000006???
%SERVICE_PAUSED                        = &H00000007???

'//
'// Controls Accepted  (Bit Mask)
'//
%SERVICE_ACCEPT_STOP                   = &H00000001???
%SERVICE_ACCEPT_PAUSE_CONTINUE         = &H00000002???
%SERVICE_ACCEPT_SHUTDOWN               = &H00000004???
%SERVICE_ACCEPT_PARAMCHANGE            = &H00000008???
%SERVICE_ACCEPT_NETBINDCHANGE          = &H00000010???
%SERVICE_ACCEPT_HARDWAREPROFILECHANGE  = &H00000020???
%SERVICE_ACCEPT_POWEREVENT             = &H00000040???
%SERVICE_ACCEPT_SESSIONCHANGE          = &H00000080???
%SERVICE_ACCEPT_PRESHUTDOWN            = &H00000100???
%SERVICE_ACCEPT_TIMECHANGE             = &H00000200???
%SERVICE_ACCEPT_TRIGGEREVENT           = &H00000400???

'//
'// Service Control Manager object specific access types
'//
%SC_MANAGER_CONNECT            = &H0001???
%SC_MANAGER_CREATE_SERVICE     = &H0002???
%SC_MANAGER_ENUMERATE_SERVICE  = &H0004???
%SC_MANAGER_LOCK               = &H0008???
%SC_MANAGER_QUERY_LOCK_STATUS  = &H0010???
%SC_MANAGER_MODIFY_BOOT_CONFIG = &H0020???

%SC_MANAGER_ALL_ACCESS         = %STANDARD_RIGHTS_REQUIRED OR %SC_MANAGER_CONNECT OR %SC_MANAGER_CREATE_SERVICE OR %SC_MANAGER_ENUMERATE_SERVICE OR %SC_MANAGER_LOCK _
                                 OR %SC_MANAGER_QUERY_LOCK_STATUS OR %SC_MANAGER_MODIFY_BOOT_CONFIG


'//
'// Service object specific access type
'//
%SERVICE_QUERY_CONFIG          = &H0001???
%SERVICE_CHANGE_CONFIG         = &H0002???
%SERVICE_QUERY_STATUS          = &H0004???
%SERVICE_ENUMERATE_DEPENDENTS  = &H0008???
%SERVICE_START                 = &H0010???
%SERVICE_STOP                  = &H0020???
%SERVICE_PAUSE_CONTINUE        = &H0040???
%SERVICE_INTERROGATE           = &H0080???
%SERVICE_USER_DEFINED_CONTROL  = &H0100???

%SERVICE_ALL_ACCESS            = %STANDARD_RIGHTS_REQUIRED OR %SERVICE_QUERY_CONFIG OR %SERVICE_CHANGE_CONFIG OR %SERVICE_QUERY_STATUS _
                                 OR %SERVICE_ENUMERATE_DEPENDENTS OR %SERVICE_START OR %SERVICE_STOP OR %SERVICE_PAUSE_CONTINUE OR %SERVICE_INTERROGATE OR %SERVICE_USER_DEFINED_CONTROL

'//
'// Service flags for QueryServiceStatusEx
'//
%SERVICE_RUNS_IN_SYSTEM_PROCESS = &H00000001???

'//
'// Info levels for ChangeServiceConfig2 and QueryServiceConfig2
'//
%SERVICE_CONFIG_DESCRIPTION              = 1???
%SERVICE_CONFIG_FAILURE_ACTIONS          = 2???
%SERVICE_CONFIG_DELAYED_AUTO_START_INFO  = 3???
%SERVICE_CONFIG_FAILURE_ACTIONS_FLAG     = 4???
%SERVICE_CONFIG_SERVICE_SID_INFO         = 5???
%SERVICE_CONFIG_REQUIRED_PRIVILEGES_INFO = 6???
%SERVICE_CONFIG_PRESHUTDOWN_INFO         = 7???
%SERVICE_CONFIG_TRIGGER_INFO             = 8???
%SERVICE_CONFIG_PREFERRED_NODE           = 9???

'// Info levels for NotifyServiceStatusChange
'//
%SERVICE_NOTIFY_STATUS_CHANGE_1          = 1
%SERVICE_NOTIFY_STATUS_CHANGE_2          = 2

%SERVICE_NOTIFY_STATUS_CHANGE            = %SERVICE_NOTIFY_STATUS_CHANGE_2

'//
'// Service notification masks
'//
%SERVICE_NOTIFY_STOPPED                  = &H00000001???
%SERVICE_NOTIFY_START_PENDING            = &H00000002???
%SERVICE_NOTIFY_STOP_PENDING             = &H00000004???
%SERVICE_NOTIFY_RUNNING                  = &H00000008???
%SERVICE_NOTIFY_CONTINUE_PENDING         = &H00000010???
%SERVICE_NOTIFY_PAUSE_PENDING            = &H00000020???
%SERVICE_NOTIFY_PAUSED                   = &H00000040???
%SERVICE_NOTIFY_CREATED                  = &H00000080???
%SERVICE_NOTIFY_DELETED                  = &H00000100???
%SERVICE_NOTIFY_DELETE_PENDING           = &H00000200???

'//
'// The following defines are for service stop reason codes
'//

'//
'// Stop reason flags. Update SERVICE_STOP_REASON_FLAG_MAX when
'// new flags are added.
'//
%SERVICE_STOP_REASON_FLAG_MIN            = &H00000000???
%SERVICE_STOP_REASON_FLAG_UNPLANNED      = &H10000000???
%SERVICE_STOP_REASON_FLAG_CUSTOM         = &H20000000???
%SERVICE_STOP_REASON_FLAG_PLANNED        = &H40000000???
%SERVICE_STOP_REASON_FLAG_MAX            = &H80000000???

'//
'// Microsoft major reasons. Update SERVICE_STOP_REASON_MAJOR_MAX when
'// new codes are added.
'//
%SERVICE_STOP_REASON_MAJOR_MIN             = &H00000000???
%SERVICE_STOP_REASON_MAJOR_OTHER           = &H00010000???
%SERVICE_STOP_REASON_MAJOR_HARDWARE        = &H00020000???
%SERVICE_STOP_REASON_MAJOR_OPERATINGSYSTEM = &H00030000???
%SERVICE_STOP_REASON_MAJOR_SOFTWARE        = &H00040000???
%SERVICE_STOP_REASON_MAJOR_APPLICATION     = &H00050000???
%SERVICE_STOP_REASON_MAJOR_NONE            = &H00060000???
%SERVICE_STOP_REASON_MAJOR_MAX             = &H00070000???
%SERVICE_STOP_REASON_MAJOR_MIN_CUSTOM      = &H00400000???
%SERVICE_STOP_REASON_MAJOR_MAX_CUSTOM      = &H00ff0000???

'//
'// Microsoft minor reasons. Update SERVICE_STOP_REASON_MINOR_MAX when
'// new codes are added.
'//
%SERVICE_STOP_REASON_MINOR_MIN                           = &H00000000???
%SERVICE_STOP_REASON_MINOR_OTHER                         = &H00000001???
%SERVICE_STOP_REASON_MINOR_MAINTENANCE                   = &H00000002???
%SERVICE_STOP_REASON_MINOR_INSTALLATION                  = &H00000003???
%SERVICE_STOP_REASON_MINOR_UPGRADE                       = &H00000004???
%SERVICE_STOP_REASON_MINOR_RECONFIG                      = &H00000005???
%SERVICE_STOP_REASON_MINOR_HUNG                          = &H00000006???
%SERVICE_STOP_REASON_MINOR_UNSTABLE                      = &H00000007???
%SERVICE_STOP_REASON_MINOR_DISK                          = &H00000008???
%SERVICE_STOP_REASON_MINOR_NETWORKCARD                   = &H00000009???
%SERVICE_STOP_REASON_MINOR_ENVIRONMENT                   = &H0000000a???
%SERVICE_STOP_REASON_MINOR_HARDWARE_DRIVER               = &H0000000b???
%SERVICE_STOP_REASON_MINOR_OTHERDRIVER                   = &H0000000c???
%SERVICE_STOP_REASON_MINOR_SERVICEPACK                   = &H0000000d???
%SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE               = &H0000000e???
%SERVICE_STOP_REASON_MINOR_SECURITYFIX                   = &H0000000f???
%SERVICE_STOP_REASON_MINOR_SECURITY                      = &H00000010???
%SERVICE_STOP_REASON_MINOR_NETWORK_CONNECTIVITY          = &H00000011???
%SERVICE_STOP_REASON_MINOR_WMI                           = &H00000012???
%SERVICE_STOP_REASON_MINOR_SERVICEPACK_UNINSTALL         = &H00000013???
%SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE_UNINSTALL     = &H00000014???
%SERVICE_STOP_REASON_MINOR_SECURITYFIX_UNINSTALL         = &H00000015???
%SERVICE_STOP_REASON_MINOR_MMC                           = &H00000016???
%SERVICE_STOP_REASON_MINOR_NONE                          = &H00000017???
%SERVICE_STOP_REASON_MINOR_MAX                           = &H00000018???
%SERVICE_STOP_REASON_MINOR_MIN_CUSTOM                    = &H00000100???
%SERVICE_STOP_REASON_MINOR_MAX_CUSTOM                    = &H0000FFFF???

'//
'// Info levels for ControlServiceEx
'//
%SERVICE_CONTROL_STATUS_REASON_INFO = 1

'//
'// Service SID types supported
'//
%SERVICE_SID_TYPE_NONE              = &H00000000???
%SERVICE_SID_TYPE_UNRESTRICTED      = &H00000001???
%SERVICE_SID_TYPE_RESTRICTED        = &H00000002??? OR %SERVICE_SID_TYPE_UNRESTRICTED

'//
'// Service trigger types
'//
%SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL              = 1
%SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY               = 2
%SERVICE_TRIGGER_TYPE_DOMAIN_JOIN                           = 3
%SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT                   = 4
%SERVICE_TRIGGER_TYPE_GROUP_POLICY                          = 5
%SERVICE_TRIGGER_TYPE_CUSTOM                                = 20

'//
'// Service trigger data types
'//
%SERVICE_TRIGGER_DATA_TYPE_BINARY                           = 1
%SERVICE_TRIGGER_DATA_TYPE_STRING                           = 2

'//
'//  NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID & NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID are used with
'//  SERVICE_TRIGGER_TYPE_IP_ADDRESS_AVAILABILITY trigger.
'//
$NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID = GUID$("{4f27f2de-14e2-430b-a549-7cd48cbc8245}")

$NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID = GUID$("{cc4ba62a-162e-4648-847a-b6bdf993e335}")

'//
'//  DOMAIN_JOIN_GUID & DOMAIN_LEAVE_GUID are used with SERVICE_TRIGGER_TYPE_DOMAIN_JOIN trigger.
'//
$DOMAIN_JOIN_GUID = GUID$("{1ce20aba-9851-4421-9430-1ddeb766e809}")

$DOMAIN_LEAVE_GUID = GUID$("{ddaf516e-58c2-4866-9574-c3b615d42ea1}")

'//
'//  FIREWALL_PORT_OPEN_GUID & FIREWALL_PORT_CLOSE_GUID are used with
'//  SERVICE_TRIGGER_TYPE_FIREWALL_PORT_EVENT trigger.
'//
$FIREWALL_PORT_OPEN_GUID = GUID$("{b7569e07-8421-4ee0-ad10-86915afdad09}")

$FIREWALL_PORT_CLOSE_GUID = GUID$("{a144ed38-8e12-4de4-9d96-e64740b1a524}")

'//
'//  MACHINE_POLICY_PRESENT_GUID & USER_POLICY_PRESENT_GUID are used with
'//  SERVICE_TRIGGER_TYPE_GROUP_POLICY trigger.
'//
$MACHINE_POLICY_PRESENT_GUID = GUID$("{659FCAE6-5BDB-4DA9-B1FF-CA2A178D46E0}")

$USER_POLICY_PRESENT_GUID = GUID$("{54FB46C8-F089-464C-B1FD-59D1B62C3B50}")

'//
'// Service trigger actions
'//
%SERVICE_TRIGGER_ACTION_SERVICE_START                       = 1
%SERVICE_TRIGGER_ACTION_SERVICE_STOP                        = 2

'//
'// argv[1] passed into ServiceMain of trigger started services
'//
$$SERVICE_TRIGGER_STARTED_ARGUMENT                = "TriggerStarted"$$

'//
'// Service description string
'//
' // Size = 4 bytes
TYPE SERVICE_DESCRIPTIONA DWORD
   lpDescription AS ASCIIZ PTR   ' LPSTR
END TYPE

'//
'// Service description string
'//
' // Size = 4 bytes
TYPE SERVICE_DESCRIPTIONW DWORD
   lpDescription AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_DESCRIPTION = SERVICE_DESCRIPTIONW
#ELSE
   MACRO SERVICE_DESCRIPTION = SERVICE_DESCRIPTIONA
#ENDIF

'//
'// Actions to take on service failure
'//
' SC_ACTION_TYPE enum
%SC_ACTION_NONE          = 0
%SC_ACTION_RESTART       = 1
%SC_ACTION_REBOOT        = 2
%SC_ACTION_RUN_COMMAND   = 3

UNION SC_ACTION_TYPE_UNION DWORD
   Type  AS LONG    ' SC_ACTION_TYPE
   ' // For compatibility with the PB declares
   aType AS LONG    ' SC_ACTION_TYPE
END UNION

' // Size = 8 bytes
TYPE SC_ACTION DWORD
   SC_ACTION_TYPE_UNION
   Delay AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE SERVICE_FAILURE_ACTIONSA DWORD
   dwResetPeriod AS DWORD           ' DWORD
   lpRebootMsg   AS ASCIIZ PTR      ' LPSTR
   lpCommand     AS ASCIIZ PTR      ' LPSTR
   cActions      AS DWORD           ' DWORD
   lpsaActions   AS SC_ACTION PTR   ' SC_ACTION*
END TYPE

' // Size = 20 bytes
TYPE SERVICE_FAILURE_ACTIONSW DWORD
   dwResetPeriod AS DWORD           ' DWORD
   lpRebootMsg   AS WSTRINGZ PTR    ' LPWSTR
   lpCommand     AS WSTRINGZ PTR    ' LPWSTR
   cActions      AS DWORD           ' DWORD
   lpsaActions   AS SC_ACTION PTR   ' SC_ACTION*
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_FAILURE_ACTIONS = SERVICE_FAILURE_ACTIONSW
#ELSE
   MACRO SERVICE_FAILURE_ACTIONS = SERVICE_FAILURE_ACTIONSA
#ENDIF

'//
'// Service delayed autostart info setting
'//
' // Size = 4 bytes
TYPE SERVICE_DELAYED_AUTO_START_INFO DWORD
   fDelayedAutostart AS LONG    ' BOOL // Delayed autostart flag
END TYPE

'//
'// Service failure actions flag setting
'//
' // Size = 4 bytes
TYPE SERVICE_FAILURE_ACTIONS_FLAG DWORD
   fFailureActionsOnNonCrashFailures AS LONG   ' BOOL // Failure actions flag
END TYPE

'//
'// Service SID info setting
'//
' // Size = 4 bytes
TYPE SERVICE_SID_INFO DWORD
   dwServiceSidType AS DWORD   ' DWORD // Service SID type
END TYPE

'//
'// Service required privileges information
'//
' // Size = 4 bytes
TYPE SERVICE_REQUIRED_PRIVILEGES_INFOA DWORD
   pmszRequiredPrivileges AS ASCIIZ PTR   ' LPSTR // Required privileges multi-sz
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_REQUIRED_PRIVILEGES_INFO = SERVICE_REQUIRED_PRIVILEGES_INFOW
#ELSE
   MACRO SERVICE_REQUIRED_PRIVILEGES_INFO = SERVICE_REQUIRED_PRIVILEGES_INFOA
#ENDIF

'//
'// Service required privileges information
'//
' // Size = 4 bytes
TYPE SERVICE_REQUIRED_PRIVILEGES_INFOW DWORD
   pmszRequiredPrivileges AS WSTRINGZ PTR   ' LPWSTR // Required privileges multi-sz
END TYPE

'//
'// Service preshutdown timeout setting
'//
' // Size = 4 bytes
TYPE SERVICE_PRESHUTDOWN_INFO DWORD
   dwPreshutdownTimeout AS DWORD   ' DWORD // Timeout in msecs
END TYPE

'//
'//  Service trigger data item
'//
' // Size = 12 bytes
TYPE SERVICE_TRIGGER_SPECIFIC_DATA_ITEM DWORD
   dwDataType AS DWORD      ' DWORD // Data type -- one of SERVICE_TRIGGER_DATA_TYPE_* constants
   cbData     AS DWORD      ' DWORD // Size of trigger specific data
   pData      AS BYTE PTR   ' PBYTE // Trigger specific data
END TYPE

'//
'//  Trigger-specific information
'//
' // Size = 20 bytes
TYPE SERVICE_TRIGGER DWORD
   dwTriggerType   AS DWORD      ' DWORD  // One of SERVICE_TRIGGER_TYPE_* constants
   dwAction        AS DWORD      ' DWORD  // One of SERVICE_TRIGGER_ACTION_* constants
   pTriggerSubtype AS GUID PTR   ' GUID*  // Provider GUID if the trigger type is SERVICE_TRIGGER_TYPE_CUSTOM
                                 '        // Device class interface GUID if the trigger type is
                                 '        // SERVICE_TRIGGER_TYPE_DEVICE_INTERFACE_ARRIVAL
   cDataItems      AS DWORD      ' DWORD  // Number of data items in pDataItems array
   pDataItems      AS SERVICE_TRIGGER_SPECIFIC_DATA_ITEM PTR   ' PSERVICE_TRIGGER_SPECIFIC_DATA_ITEM // Trigger specific data
END TYPE

'//
'// Service trigger information
'//
' // Size = 12 bytes
TYPE SERVICE_TRIGGER_INFO DWORD
   cTriggers AS DWORD                 ' DWORD // Number of triggers in the pTriggers array
   pTriggers AS SERVICE_TRIGGER PTR   ' PSERVICE_TRIGGER // Array of triggers
   pReserved AS BYTE PTR              ' PBYTE // Reserved, must be NULL
END TYPE

'//
'// Preferred node information
'//
' // Size = 4 bytes
TYPE SERVICE_PREFERRED_NODE_INFO WORD
   usPreferredNode AS WORD   ' USHORT // Preferred node
   fDelete         AS BYTE   ' BOOLEAN // Delete the preferred node setting
END TYPE

'//
'// Time change information
'//
' // Size = 16 bytes
TYPE SERVICE_TIMECHANGE_INFO QWORD
   liNewTime AS QUAD   ' LARGE_INTEGER // New time
   liOldTime AS QUAD   ' LARGE_INTEGER // Old time
END TYPE

'//
'// Handle Types
'//

'DECLARE_HANDLE(SC_HANDLE);
'typedef SC_HANDLE   *LPSC_HANDLE;

'DECLARE_HANDLE(SERVICE_STATUS_HANDLE);

'//
'// Info levels for QueryServiceStatusEx
'//

' SC_STATUS_TYPE enum
%SC_STATUS_PROCESS_INFO      = 0

'//
'// Info levels for EnumServicesStatusEx
'//
' SC_ENUM_TYPE enum
%SC_ENUM_PROCESS_INFO        = 0

'//
'// Service Status Structures
'//

' // Size = 28 bytes
TYPE SERVICE_STATUS DWORD
   dwServiceType             AS DWORD
   dwCurrentState            AS DWORD
   dwControlsAccepted        AS DWORD
   dwWin32ExitCode           AS DWORD
   dwServiceSpecificExitCode AS DWORD
   dwCheckPoint              AS DWORD
   dwWaitHint                AS DWORD
END TYPE

' // For compatibility with the PB declares
MACRO SERVICE_STATUS_TYPE = SERVICE_STATUS

' // Size = 36 bytes
TYPE SERVICE_STATUS_PROCESS DWORD
   dwServiceType             AS DWORD
   dwCurrentState            AS DWORD
   dwControlsAccepted        AS DWORD
   dwWin32ExitCode           AS DWORD
   dwServiceSpecificExitCode AS DWORD
   dwCheckPoint              AS DWORD
   dwWaitHint                AS DWORD
   dwProcessId               AS DWORD
   dwServiceFlags            AS DWORD
END TYPE

' // For compatibility with the PB declares
MACRO SERVICE_STATUS_PROCESS_TYPE = SERVICE_STATUS_PROCESS

'//
'// Service Status Enumeration Structure
'//

' // Size = 36 bytes
TYPE ENUM_SERVICE_STATUSA DWORD
   lpServiceName AS ASCIIZ PTR       ' LPSTR
   lpDisplayName AS ASCIIZ PTR       ' LPSTR
   ServiceStatus AS SERVICE_STATUS   ' SERVICE_STATUS
END TYPE

' // Size = 36 bytes
TYPE ENUM_SERVICE_STATUSW DWORD
   lpServiceName AS WSTRINGZ PTR     ' LPWSTR
   lpDisplayName AS WSTRINGZ PTR     ' LPWSTR
   ServiceStatus AS SERVICE_STATUS   ' SERVICE_STATUS
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUM_SERVICE_STATUS = ENUM_SERVICE_STATUSW
#ELSE
   MACRO ENUM_SERVICE_STATUS = ENUM_SERVICE_STATUSA
#ENDIF

' // Size = 44 bytes
TYPE ENUM_SERVICE_STATUS_PROCESSA DWORD
   lpServiceName        AS ASCIIZ PTR               ' LPSTR
   lpDisplayName        AS ASCIIZ PTR               ' LPSTR
   ServiceStatusProcess AS SERVICE_STATUS_PROCESS   ' SERVICE_STATUS_PROCESS
END TYPE

' // Size = 44 bytes
TYPE ENUM_SERVICE_STATUS_PROCESSW DWORD
   lpServiceName        AS WSTRINGZ PTR             ' LPWSTR
   lpDisplayName        AS WSTRINGZ PTR             ' LPWSTR
   ServiceStatusProcess AS SERVICE_STATUS_PROCESS   ' SERVICE_STATUS_PROCESS
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUM_SERVICE_STATUS_PROCESS = ENUM_SERVICE_STATUS_PROCESSW
#ELSE
   MACRO ENUM_SERVICE_STATUS_PROCESS = ENUM_SERVICE_STATUS_PROCESSA
#ENDIF

'//
'// Structures for the Lock API functions
'//

'typedef LPVOID  SC_LOCK;

' // Size = 12 bytes
TYPE QUERY_SERVICE_LOCK_STATUSA DWORD
   fIsLocked      AS DWORD        ' DWORD
   lpLockOwner    AS ASCIIZ PTR   ' LPSTR
   dwLockDuration AS DWORD        ' DWORD
END TYPE

' // Size = 12 bytes
TYPE QUERY_SERVICE_LOCK_STATUSW DWORD
   fIsLocked      AS DWORD          ' DWORD
   lpLockOwner    AS WSTRINGZ PTR   ' LPWSTR
   dwLockDuration AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO QUERY_SERVICE_LOCK_STATUS = QUERY_SERVICE_LOCK_STATUSW
#ELSE
   MACRO QUERY_SERVICE_LOCK_STATUS = QUERY_SERVICE_LOCK_STATUSA
#ENDIF

'//
'// Query Service Configuration Structure
'//

' // Size = 36 bytes
TYPE QUERY_SERVICE_CONFIGA DWORD
   dwServiceType      AS DWORD        ' DWORD
   dwStartType        AS DWORD        ' DWORD
   dwErrorControl     AS DWORD        ' DWORD
   lpBinaryPathName   AS ASCIIZ PTR   ' LPSTR
   lpLoadOrderGroup   AS ASCIIZ PTR   ' LPSTR
   dwTagId            AS DWORD        ' DWORD
   lpDependencies     AS ASCIIZ PTR   ' LPSTR
   lpServiceStartName AS ASCIIZ PTR   ' LPSTR
   lpDisplayName      AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 36 bytes
TYPE QUERY_SERVICE_CONFIGW DWORD
   dwServiceType      AS DWORD          ' DWORD
   dwStartType        AS DWORD          ' DWORD
   dwErrorControl     AS DWORD          ' DWORD
   lpBinaryPathName   AS WSTRINGZ PTR   ' LPWSTR
   lpLoadOrderGroup   AS WSTRINGZ PTR   ' LPWSTR
   dwTagId            AS DWORD          ' DWORD
   lpDependencies     AS WSTRINGZ PTR   ' LPWSTR
   lpServiceStartName AS WSTRINGZ PTR   ' LPWSTR
   lpDisplayName      AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO QUERY_SERVICE_CONFIG = QUERY_SERVICE_CONFIGW
#ELSE
   MACRO QUERY_SERVICE_CONFIG = QUERY_SERVICE_CONFIGA
#ENDIF

'//
'// Function Prototype for the Service Main Function
'//

'typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONW)(
'    DWORD   dwNumServicesArgs,
'    LPWSTR  *lpServiceArgVectors
'    );

'typedef VOID (WINAPI *LPSERVICE_MAIN_FUNCTIONA)(
'    DWORD   dwNumServicesArgs,
'    LPSTR   *lpServiceArgVectors
'    );

'//
'// Service Start Table
'//

' // Size = 8 bytes
TYPE SERVICE_TABLE_ENTRYA DWORD
   lpServiceName AS ASCIIZ PTR   ' LPSTR
   lpServiceProc AS LONG         ' LPSERVICE_MAIN_FUNCTIONA
END TYPE

' // Size = 8 bytes
TYPE SERVICE_TABLE_ENTRYW DWORD
   lpServiceName AS WSTRINGZ PTR   ' LPWSTR
   lpServiceProc AS LONG           ' LPSERVICE_MAIN_FUNCTIONW
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_TABLE_ENTRY = SERVICE_TABLE_ENTRYW
#ELSE
   MACRO SERVICE_TABLE_ENTRY = SERVICE_TABLE_ENTRYA
#ENDIF

'//
'// Prototype for the Service Control Handler Function
'//

'typedef VOID (WINAPI *LPHANDLER_FUNCTION)(
'    DWORD    dwControl
'    );

'typedef DWORD (WINAPI *LPHANDLER_FUNCTION_EX)(
'    DWORD    dwControl,
'    DWORD    dwEventType,
'    LPVOID   lpEventData,
'    LPVOID   lpContext
'    );

'//
'// Service notification parameters
'//
'typedef
'VOID
'( CALLBACK * PFN_SC_NOTIFY_CALLBACK ) (
'    IN PVOID pParameter
'    );

'//
'//  Each new notify structure is a superset of the older version
'//
' // Size = 52 bytes
TYPE SERVICE_NOTIFY_1 DWORD
   dwVersion            AS DWORD   ' DWORD
   pfnNotifyCallback    AS DWORD   ' PFN_SC_NOTIFY_CALLBACK
   pContext             AS DWORD   ' PVOID
   dwNotificationStatus AS DWORD   ' DWORD
   ServiceStatus        AS SERVICE_STATUS_PROCESS
END TYPE

' // Size = 60 bytes
TYPE SERVICE_NOTIFY_2A DWORD
   dwVersion               AS DWORD        ' DWORD
   pfnNotifyCallback       AS DWORD        ' PFN_SC_NOTIFY_CALLBACK
   pContext                AS DWORD        ' PVOID
   dwNotificationStatus    AS DWORD        ' DWORD
   ServiceStatus           AS SERVICE_STATUS_PROCESS
   dwNotificationTriggered AS DWORD        ' DWORD
   pszServiceNames         AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 60 bytes
TYPE SERVICE_NOTIFY_2W DWORD
   dwVersion               AS DWORD          ' DWORD
   pfnNotifyCallback       AS DWORD          ' PFN_SC_NOTIFY_CALLBACK
   pContext                AS DWORD          ' PVOID
   dwNotificationStatus    AS DWORD          ' DWORD
   ServiceStatus           AS SERVICE_STATUS_PROCESS
   dwNotificationTriggered AS DWORD          ' DWORD
   pszServiceNames         AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO SERVICE_NOTIFYA = SERVICE_NOTIFY_2A
MACRO SERVICE_NOTIFYW = SERVICE_NOTIFY_2W

#IF %DEF(%UNICODE)
   MACRO SERVICE_NOTIFY_2 = SERVICE_NOTIFY_2W
#ELSE
   MACRO SERVICE_NOTIFY_2 = SERVICE_NOTIFY_2A
#ENDIF

'//
'// Service control status reason parameters
'//
' // Size = 44 bytes
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMSA DWORD
   dwReason      AS DWORD        ' DWORD
   pszComment    AS ASCIIZ PTR   ' LPSTR
   ServiceStatus AS SERVICE_STATUS_PROCESS
END TYPE

'//
'// Service control status reason parameters
'//
' // Size = 44 bytes
TYPE SERVICE_CONTROL_STATUS_REASON_PARAMSW DWORD
   dwReason      AS DWORD          ' DWORD
   pszComment    AS WSTRINGZ PTR   ' LPWSTR
   ServiceStatus AS SERVICE_STATUS_PROCESS
END TYPE

#IF %DEF(%UNICODE)
   MACRO SERVICE_CONTROL_STATUS_REASON_PARAMS = SERVICE_CONTROL_STATUS_REASON_PARAMSW
#ELSE
   MACRO SERVICE_CONTROL_STATUS_REASON_PARAMS = SERVICE_CONTROL_STATUS_REASON_PARAMSA
#ENDIF

'///////////////////////////////////////////////////////////////////////////
'// API Function Prototypes
'///////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION ChangeServiceConfigA IMPORT "ADVAPI32.DLL" ALIAS "ChangeServiceConfigA" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE  hService
 , BYVAL dwServiceType AS DWORD _                       ' __in        DWORD      dwServiceType
 , BYVAL dwStartType AS DWORD _                         ' __in        DWORD      dwStartType
 , BYVAL dwErrorControl AS DWORD _                      ' __in        DWORD      dwErrorControl
 , OPTIONAL BYREF lpBinaryPathName AS ASCIIZ _          ' __in_opt    LPCSTR     lpBinaryPathName
 , OPTIONAL BYREF lpLoadOrderGroup AS ASCIIZ _          ' __in_opt    LPCSTR     lpLoadOrderGroup
 , OPTIONAL BYREF lpdwTagId AS DWORD _                  ' __out_opt   LPDWORD    lpdwTagId
 , OPTIONAL BYREF lpDependencies AS ASCIIZ _            ' __in_opt    LPCSTR     lpDependencies
 , OPTIONAL BYREF lpServiceStartName AS ASCIIZ _        ' __in_opt    LPCSTR     lpServiceStartName
 , OPTIONAL BYREF lpPassword AS ASCIIZ  _               ' __in_opt    LPCSTR     lpPassword
 , OPTIONAL BYREF lpDisplayName AS ASCIIZ _             ' __in_opt    LPCSTR     lpDisplayName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChangeServiceConfigW IMPORT "ADVAPI32.DLL" ALIAS "ChangeServiceConfigW" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE  hService
 , BYVAL dwServiceType AS DWORD _                       ' __in        DWORD      dwServiceType
 , BYVAL dwStartType AS DWORD _                         ' __in        DWORD      dwStartType
 , BYVAL dwErrorControl AS DWORD _                      ' __in        DWORD      dwErrorControl
 , OPTIONAL BYREF lpBinaryPathName AS WSTRINGZ _        ' __in_opt    LPCWSTR    lpBinaryPathName
 , OPTIONAL BYREF lpLoadOrderGroup AS WSTRINGZ _        ' __in_opt    LPCWSTR    lpLoadOrderGroup
 , OPTIONAL BYREF lpdwTagId AS DWORD _                  ' __out_opt   LPDWORD    lpdwTagId
 , OPTIONAL BYREF lpDependencies AS WSTRINGZ _          ' __in_opt    LPCWSTR    lpDependencies
 , OPTIONAL BYREF lpServiceStartName AS WSTRINGZ _      ' __in_opt    LPCWSTR    lpServiceStartName
 , OPTIONAL BYREF lpPassword AS WSTRINGZ _              ' __in_opt    LPCWSTR    lpPassword
 , OPTIONAL BYREF lpDisplayName AS WSTRINGZ _           ' __in_opt    LPCWSTR    lpDisplayName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ChangeServiceConfig = ChangeServiceConfigW
#ELSE
   MACRO ChangeServiceConfig = ChangeServiceConfigA
#ENDIF

DECLARE FUNCTION ChangeServiceConfig2A IMPORT "ADVAPI32.DLL" ALIAS "ChangeServiceConfig2A" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE    hService
 , BYVAL dwInfoLevel AS DWORD _                         ' __in        DWORD        dwInfoLevel
 , OPTIONAL BYVAL lpInfo AS DWORD _                     ' __in_opt    LPVOID       lpInfo
 ) AS LONG                                              ' LONG

DECLARE FUNCTION ChangeServiceConfig2W IMPORT "ADVAPI32.DLL" ALIAS "ChangeServiceConfig2W" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE    hService
 , BYVAL dwInfoLevel AS DWORD _                         ' __in        DWORD        dwInfoLevel
 , OPTIONAL BYVAL lpInfo AS DWORD _                     ' __in_opt    LPVOID       lpInfo
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO ChangeServiceConfig2 = ChangeServiceConfig2W
#ELSE
   MACRO ChangeServiceConfig2 = ChangeServiceConfig2A
#ENDIF

DECLARE FUNCTION CloseServiceHandle IMPORT "ADVAPI32.DLL" ALIAS "CloseServiceHandle" ( _
   BYVAL hSCObject AS DWORD _                           ' __in        SC_HANDLE   hSCObject
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ControlService IMPORT "ADVAPI32.DLL" ALIAS "ControlService" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE           hService
 , BYVAL dwControl AS DWORD _                           ' __in        DWORD               dwControl
 , BYREF lpServiceStatus AS SERVICE_STATUS _            ' __out       LPSERVICE_STATUS    lpServiceStatus
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateServiceA IMPORT "ADVAPI32.DLL" ALIAS "CreateServiceA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in        SC_HANDLE  hSCManager
 , BYREF lpServiceName AS ASCIIZ _                      ' __in        LPCSTR     lpServiceName
 , BYREF lpDisplayName AS ASCIIZ _                      ' __in_opt    LPCSTR     lpDisplayName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in        DWORD      dwDesiredAccess
 , BYVAL dwServiceType AS DWORD _                       ' __in        DWORD      dwServiceType
 , BYVAL dwStartType AS DWORD _                         ' __in        DWORD      dwStartType
 , BYVAL dwErrorControl AS DWORD _                      ' __in        DWORD      dwErrorControl
 , OPTIONAL BYREF lpBinaryPathName AS ASCIIZ _          ' __in_opt    LPCSTR     lpBinaryPathName
 , OPTIONAL BYREF lpLoadOrderGroup AS ASCIIZ _          ' __in_opt    LPCSTR     lpLoadOrderGroup
 , OPTIONAL BYREF lpdwTagId AS DWORD _                  ' __out_opt   LPDWORD    lpdwTagId
 , OPTIONAL BYREF lpDependencies AS ASCIIZ _            ' __in_opt    LPCSTR     lpDependencies
 , OPTIONAL BYREF lpServiceStartName AS ASCIIZ _        ' __in_opt    LPCSTR     lpServiceStartName
 , OPTIONAL BYREF lpPassword AS ASCIIZ _                ' __in_opt    LPCSTR     lpPassword
 ) AS DWORD                                             ' SC_HANDLE

DECLARE FUNCTION CreateServiceW IMPORT "ADVAPI32.DLL" ALIAS "CreateServiceW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in        SC_HANDLE  hSCManager
 , BYREF lpServiceName AS WSTRINGZ _                    ' __in        LPCWSTR    lpServiceName
 , BYREF lpDisplayName AS WSTRINGZ _                    ' __in_opt    LPCWSTR    lpDisplayName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in        DWORD      dwDesiredAccess
 , BYVAL dwServiceType AS DWORD _                       ' __in        DWORD      dwServiceType
 , BYVAL dwStartType AS DWORD _                         ' __in        DWORD      dwStartType
 , BYVAL dwErrorControl AS DWORD _                      ' __in        DWORD      dwErrorControl
 , OPTIONAL BYREF lpBinaryPathName AS WSTRINGZ _        ' __in_opt    LPCWSTR    lpBinaryPathName
 , OPTIONAL BYREF lpLoadOrderGroup AS WSTRINGZ _        ' __in_opt    LPCWSTR    lpLoadOrderGroup
 , OPTIONAL BYREF lpdwTagId AS DWORD _                  ' __out_opt   LPDWORD    lpdwTagId
 , OPTIONAL BYREF lpDependencies AS WSTRINGZ _          ' __in_opt    LPCWSTR    lpDependencies
 , OPTIONAL BYREF lpServiceStartName AS WSTRINGZ _      ' __in_opt    LPCWSTR    lpServiceStartName
 , OPTIONAL BYREF lpPassword AS WSTRINGZ _              ' __in_opt    LPCWSTR    lpPassword
 ) AS DWORD                                             ' SC_HANDLE

#IF %DEF(%UNICODE)
   MACRO CreateService = CreateServiceW
#ELSE
   MACRO CreateService = CreateServiceA
#ENDIF

DECLARE FUNCTION DeleteService IMPORT "ADVAPI32.DLL" ALIAS "DeleteService" ( _
   BYVAL hService AS DWORD _                            ' __in        SC_HANDLE   hService
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDependentServicesA IMPORT "ADVAPI32.DLL" ALIAS "EnumDependentServicesA" ( _
   BYVAL hService AS DWORD _                            ' __in  SC_HANDLE hService
 , BYVAL dwServiceState AS DWORD _                      ' __in  DWORD     dwServiceState
 , BYREF lpServices AS ANY _                            ' __out LPENUM_SERVICE_STATUSA lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in  DWORD     cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD   pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out LPDWORD   lpServicesReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumDependentServicesW IMPORT "ADVAPI32.DLL" ALIAS "EnumDependentServicesW" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwServiceState AS DWORD _                      ' __in DWORD     dwServiceState
 , BYREF lpServices AS ANY _                            ' __out LPENUM_SERVICE_STATUSW lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD     cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD  pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out LPDWORD  lpServicesReturned
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumDependentServices = EnumDependentServicesW
#ELSE
   MACRO EnumDependentServices = EnumDependentServicesA
#ENDIF

DECLARE FUNCTION EnumServicesStatusA IMPORT "ADVAPI32.DLL" ALIAS "EnumServicesStatusA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in         SC_HANDLE  hSCManager
 , BYVAL dwServiceType AS DWORD _                       ' __in         DWORD      dwServiceType
 , BYVAL dwServiceState AS DWORD _                      ' __in         DWORD      dwServiceState
 , BYREF lpServices AS ANY _                            ' __out        LPENUM_SERVICE_STATUSA  lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in         DWORD      cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out        LPDWORD    pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out        LPDWORD    lpServicesReturned
 , OPTIONAL BYREF lpResumeHandle AS DWORD _             ' __in_out_opt LPDWORD    lpResumeHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumServicesStatusW IMPORT "ADVAPI32.DLL" ALIAS "EnumServicesStatusW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in         SC_HANDLE  hSCManager
 , BYVAL dwServiceType AS DWORD _                       ' __in         DWORD      dwServiceType
 , BYVAL dwServiceState AS DWORD _                      ' __in         DWORD      dwServiceState
 , BYREF lpServices AS ANY _                            ' __out        LPENUM_SERVICE_STATUSW  lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in         DWORD      cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out        LPDWORD    pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out        LPDWORD    lpServicesReturned
 , OPTIONAL BYREF lpResumeHandle AS DWORD _             ' __in_out_opt LPDWORD    lpResumeHandle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumServicesStatus = EnumServicesStatusW
#ELSE
   MACRO EnumServicesStatus = EnumServicesStatusA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumServicesStatusExA LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExA" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS ASCIIZ _
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumServicesStatusExA IMPORT "ADVAPI32.DLL" ALIAS "EnumServicesStatusExA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in         SC_HANDLE    hSCManager
 , BYVAL InfoLevel AS LONG _                            ' __in         SC_ENUM_TYPE InfoLevel
 , BYVAL dwServiceType AS DWORD _                       ' __in         DWORD        dwServiceType
 , BYVAL dwServiceState AS DWORD _                      ' __in         DWORD        dwServiceState
 , BYREF lpServices AS ANY _                            ' __out        LPBYTE       lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in         DWORD        cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out        LPDWORD      pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out        LPDWORD      lpServicesReturned
 , OPTIONAL BYREF lpResumeHandle AS DWORD _             ' __in_out_opt LPDWORD      lpResumeHandle
 , OPTIONAL BYREF pszGroupName AS ASCIIZ _              ' __in_opt     LPCSTR       pszGroupName
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumServicesStatusExW LIB "AdvApi32.dll" _
    ALIAS "EnumServicesStatusExW" ( _
    BYVAL hSCManager     AS DWORD, _
    BYVAL InfoLevel      AS LONG, _      ' SC_ENUM_TYPE
    BYVAL dwServiceType  AS DWORD, _
    BYVAL dwServiceState AS DWORD, _
    BYVAL lpServices     AS BYTE PTR, _
    BYVAL cbBufSize      AS DWORD, _
    pcbBytesNeeded       AS DWORD, _
    lpServicesReturned   AS DWORD, _
    lpResumeHandle       AS DWORD, _
    pszGroupName         AS WSTRINGZ _
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumServicesStatusExW IMPORT "ADVAPI32.DLL" ALIAS "EnumServicesStatusExW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in         SC_HANDLE    hSCManager
 , BYVAL InfoLevel AS LONG _                            ' __in         SC_ENUM_TYPE InfoLevel
 , BYVAL dwServiceType AS DWORD _                       ' __in         DWORD        dwServiceType
 , BYVAL dwServiceState AS DWORD _                      ' __in         DWORD        dwServiceState
 , BYREF lpServices AS ANY _                            ' __out        LPBYTE       lpServices
 , BYVAL cbBufSize AS DWORD _                           ' __in         DWORD        cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out        LPDWORD      pcbBytesNeeded
 , BYREF lpServicesReturned AS DWORD _                  ' __out        LPDWORD      lpServicesReturned
 , OPTIONAL BYREF lpResumeHandle AS DWORD _             ' __in_out_opt LPDWORD      lpResumeHandle
 , OPTIONAL BYREF pszGroupName AS WSTRINGZ _            ' __in_opt     LPCWSTR      pszGroupName
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumServicesStatusEx = EnumServicesStatusExW
#ELSE
   MACRO EnumServicesStatusEx = EnumServicesStatusExA
#ENDIF

DECLARE FUNCTION GetServiceKeyNameA IMPORT "ADVAPI32.DLL" ALIAS "GetServiceKeyNameA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpDisplayName AS ASCIIZ _                      ' __in LPCSTR lpDisplayName
 , BYREF lpServiceName AS ASCIIZ _                      ' __out LPSTR lpServiceName
 , BYREF lpcchBuffer AS DWORD _                         ' __in_out LPDWORD lpcchBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetServiceKeyNameW IMPORT "ADVAPI32.DLL" ALIAS "GetServiceKeyNameW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpDisplayName AS WSTRINGZ _                    ' __in LPCWSTR lpDisplayName
 , BYREF lpServiceName AS WSTRINGZ _                    ' __out LPWSTR lpServiceName
 , BYREF lpcchBuffer AS DWORD _                         ' __in_out LPDWORD lpcchBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetServiceKeyName = GetServiceKeyNameW
#ELSE
   MACRO GetServiceKeyName = GetServiceKeyNameA
#ENDIF

DECLARE FUNCTION GetServiceDisplayNameA IMPORT "ADVAPI32.DLL" ALIAS "GetServiceDisplayNameA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpServiceName AS ASCIIZ _                      ' __in LPCSTR lpServiceName
 , BYREF lpDisplayName AS ASCIIZ _                      ' __out LPSTR lpDisplayName
 , BYREF lpcchBuffer AS DWORD _                         ' __in_out LPDWORD lpcchBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetServiceDisplayNameW IMPORT "ADVAPI32.DLL" ALIAS "GetServiceDisplayNameW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpServiceName AS WSTRINGZ _                    ' __in LPCWSTR lpServiceName
 , BYREF lpDisplayName AS WSTRINGZ _                    ' __out LPWSTR lpDisplayName
 , BYREF lpcchBuffer AS DWORD _                         ' __in_out LPDWORD lpcchBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetServiceDisplayName = GetServiceDisplayNameW
#ELSE
   MACRO GetServiceDisplayName = GetServiceDisplayNameA
#ENDIF

DECLARE FUNCTION LockServiceDatabase IMPORT "ADVAPI32.DLL" ALIAS "LockServiceDatabase" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 ) AS DWORD                                             ' SC_LOCK

DECLARE FUNCTION NotifyBootConfigStatus IMPORT "ADVAPI32.DLL" ALIAS "NotifyBootConfigStatus" ( _
   BYVAL BootAcceptable AS LONG _                       ' __in BOOL BootAcceptable
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenSCManagerA IMPORT "ADVAPI32.DLL" ALIAS "OpenSCManagerA" ( _
   BYREF lpMachineName AS ASCIIZ _                      ' __in_opt LPCSTR lpMachineName
 , BYREF lpDatabaseName AS ASCIIZ _                     ' __in_opt LPCSTR lpDatabaseName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' SC_HANDLE

DECLARE FUNCTION OpenSCManagerW IMPORT "ADVAPI32.DLL" ALIAS "OpenSCManagerW" ( _
   BYREF lpMachineName AS WSTRINGZ _                    ' __in_opt LPCWSTR lpMachineName
 , BYREF lpDatabaseName AS WSTRINGZ _                   ' __in_opt LPCWSTR lpDatabaseName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' SC_HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenSCManager = OpenSCManagerW
#ELSE
   MACRO OpenSCManager = OpenSCManagerA
#ENDIF

DECLARE FUNCTION OpenServiceA IMPORT "ADVAPI32.DLL" ALIAS "OpenServiceA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpServiceName AS ASCIIZ _                      ' __in LPCSTR lpServiceName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' SC_HANDLE

DECLARE FUNCTION OpenServiceW IMPORT "ADVAPI32.DLL" ALIAS "OpenServiceW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpServiceName AS WSTRINGZ _                    ' __in LPCWSTR lpServiceName
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 ) AS DWORD                                             ' SC_HANDLE

#IF %DEF(%UNICODE)
   MACRO OpenService = OpenServiceW
#ELSE
   MACRO OpenService = OpenServiceA
#ENDIF

DECLARE FUNCTION QueryServiceConfigA IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceConfigA" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYREF lpServiceConfig AS ANY _                       ' __out LPQUERY_SERVICE_CONFIGA lpServiceConfig
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryServiceConfigW IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceConfigW" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYREF lpServiceConfig AS ANY _                       ' __out LPQUERY_SERVICE_CONFIGW lpServiceConfig
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO QueryServiceConfig = QueryServiceConfigW
#ELSE
   MACRO QueryServiceConfig = QueryServiceConfigA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryServiceConfig2A LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2A" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceConfig2A IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceConfig2A" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPBYTE lpBuffer
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryServiceConfig2W LIB "AdvApi32.dll" _
    ALIAS "QueryServiceConfig2W" ( _
    BYVAL hService    AS DWORD, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS BYTE PTR, _
    BYVAL cbBufSize   AS DWORD, _
    pcbBytesNeeded    AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceConfig2W IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceConfig2W" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPBYTE lpBuffer
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO QueryServiceConfig2 = QueryServiceConfig2W
#ELSE
   MACRO QueryServiceConfig2 = QueryServiceConfig2A
#ENDIF

DECLARE FUNCTION QueryServiceLockStatusA IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceLockStatusA" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpLockStatus AS ANY _                          ' __out LPQUERY_SERVICE_LOCK_STATUSA lpLockStatus
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryServiceLockStatusW IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceLockStatusW" ( _
   BYVAL hSCManager AS DWORD _                          ' __in SC_HANDLE hSCManager
 , BYREF lpLockStatus AS ANY _                          ' __out LPQUERY_SERVICE_LOCK_STATUSW lpLockStatus
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO QueryServiceLockStatus = QueryServiceLockStatusW
#ELSE
   MACRO QueryServiceLockStatus = QueryServiceLockStatusA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryServiceObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "QueryServiceObjectSecurity" ( _
    BYVAL hService              AS DWORD, _
    BYVAL dwSecurityInformation AS DWORD, _   ' SECURITY_INFORMATION
    lpSecurityDescriptor        AS DWORD, _   ' PSECURITY_DESCRIPTOR
    BYVAL cbBufSize             AS DWORD, _
    pcbBytesNeeded              AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceObjectSecurity" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwSecurityInformation AS SECURITY_INFORMATION _ ' __in SECURITY_INFORMATION dwSecurityInformation
 , BYREF lpSecurityDescriptor AS ANY _                  ' __out PSECURITY_DESCRIPTOR lpSecurityDescriptor
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION QueryServiceStatus IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceStatus" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYREF lpServiceStatus AS SERVICE_STATUS _            ' __out LPSERVICE_STATUS lpServiceStatus
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QueryServiceStatusEx LIB "AdvApi32.dll" _
    ALIAS "QueryServiceStatusEx" ( _
    BYVAL hService  AS DWORD, _
    BYVAL InfoLevel AS LONG, _
    BYVAL lpBuffer  AS BYTE PTR, _
    BYVAL cbBufSize AS DWORD, _
    pcbBytesNeeded  AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION QueryServiceStatusEx IMPORT "ADVAPI32.DLL" ALIAS "QueryServiceStatusEx" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL InfoLevel AS LONG _                            ' __in SC_STATUS_TYPE InfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPBYTE lpBuffer
 , BYVAL cbBufSize AS DWORD _                           ' __in DWORD cbBufSize
 , BYREF pcbBytesNeeded AS DWORD _                      ' __out LPDWORD pcbBytesNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION RegisterServiceCtrlHandlerA IMPORT "ADVAPI32.DLL" ALIAS "RegisterServiceCtrlHandlerA" ( _
   BYREF lpServiceName AS ASCIIZ _                      ' __in LPCSTR lpServiceName
 , BYVAL lpHandlerProc AS DWORD _                       ' __in __callback LPHANDLER_FUNCTION lpHandlerProc
 ) AS DWORD                                             ' SERVICE_STATUS_HANDLE

DECLARE FUNCTION RegisterServiceCtrlHandlerW IMPORT "ADVAPI32.DLL" ALIAS "RegisterServiceCtrlHandlerW" ( _
   BYREF lpServiceName AS WSTRINGZ _                    ' __in LPCWSTR lpServiceName
 , BYVAL lpHandlerProc AS DWORD _                       ' __in __callback LPHANDLER_FUNCTION lpHandlerProc
 ) AS DWORD                                             ' SERVICE_STATUS_HANDLE

#IF %DEF(%UNICODE)
   MACRO RegisterServiceCtrlHandler = RegisterServiceCtrlHandlerW
#ELSE
   MACRO RegisterServiceCtrlHandler = RegisterServiceCtrlHandlerA
#ENDIF

DECLARE FUNCTION RegisterServiceCtrlHandlerExA IMPORT "ADVAPI32.DLL" ALIAS "RegisterServiceCtrlHandlerExA" ( _
   BYREF lpServiceName AS ASCIIZ _                      ' __in LPCSTR lpServiceName
 , BYVAL lpHandlerProc AS DWORD _                       ' __in __callback LPHANDLER_FUNCTION_EX lpHandlerProc
 , OPTIONAL BYREF lpContext AS ANY _                    ' __in_opt LPVOID lpContext
 ) AS DWORD                                             ' SERVICE_STATUS_HANDLE

DECLARE FUNCTION RegisterServiceCtrlHandlerExW IMPORT "ADVAPI32.DLL" ALIAS "RegisterServiceCtrlHandlerExW" ( _
   BYREF lpServiceName AS WSTRINGZ _                    ' __in LPCWSTR lpServiceName
 , BYVAL lpHandlerProc AS DWORD _                       ' __in __callback LPHANDLER_FUNCTION_EX lpHandlerProc
 , OPTIONAL BYREF lpContext AS ANY _                    ' __in_opt LPVOID lpContext
 ) AS DWORD                                             ' SERVICE_STATUS_HANDLE

#IF %DEF(%UNICODE)
   MACRO RegisterServiceCtrlHandlerEx = RegisterServiceCtrlHandlerExW
#ELSE
   MACRO RegisterServiceCtrlHandlerEx = RegisterServiceCtrlHandlerExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetServiceObjectSecurity LIB "AdvApi32.dll" _
    ALIAS "SetServiceObjectSecurity" ( _
    BYVAL hService              AS DWORD, _
    BYVAL dwSecurityInformation AS DWORD, _   ' SECURITY_INFORMATION
    BYVAL lpSecurityDescriptor  AS DWORD _    ' PSECURITY_DESCRIPTOR
    ) AS LONG
#ELSE
DECLARE FUNCTION SetServiceObjectSecurity IMPORT "ADVAPI32.DLL" ALIAS "SetServiceObjectSecurity" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwSecurityInformation AS SECURITY_INFORMATION _ ' __in SECURITY_INFORMATION dwSecurityInformation
 , BYREF lpSecurityDescriptor AS ANY _                  ' __in PSECURITY_DESCRIPTOR lpSecurityDescriptor
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetServiceStatus LIB "AdvApi32.dll" _
    ALIAS "SetServiceStatus" ( _
    BYVAL hServiceStatus AS DWORD, _  ' SERVICE_STATUS_HANDLE
    lpServiceStatus      AS DWORD _   ' LPSERVICE_STATUS
    ) AS LONG
#ELSE
DECLARE FUNCTION SetServiceStatus IMPORT "ADVAPI32.DLL" ALIAS "SetServiceStatus" ( _
   BYVAL hServiceStatus AS DWORD _                      ' __in SERVICE_STATUS_HANDLE hServiceStatus
 , BYREF lpServiceStatus AS SERVICE_STATUS _            ' __in LPSERVICE_STATUS lpServiceStatus
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartServiceCtrlDispatcherA LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherA" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYA PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartServiceCtrlDispatcherA IMPORT "ADVAPI32.DLL" ALIAS "StartServiceCtrlDispatcherA" ( _
   BYREF lpServiceStartTable AS SERVICE_TABLE_ENTRYA _  ' __in CONST SERVICE_TABLE_ENTRYA *lpServiceStartTable
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartServiceCtrlDispatcherW LIB "AdvApi32.dll" _
    ALIAS "StartServiceCtrlDispatcherW" ( _
    BYVAL lpServiceStartTable AS SERVICE_TABLE_ENTRYW PTR _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartServiceCtrlDispatcherW IMPORT "ADVAPI32.DLL" ALIAS "StartServiceCtrlDispatcherW" ( _
   BYREF lpServiceStartTable AS SERVICE_TABLE_ENTRYW _  ' __in CONST SERVICE_TABLE_ENTRYW *lpServiceStartTable
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO StartServiceCtrlDispatcher = StartServiceCtrlDispatcherW
#ELSE
   MACRO StartServiceCtrlDispatcher = StartServiceCtrlDispatcherA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartServiceA LIB "AdvApi32.dll" _
    ALIAS "StartServiceA" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartServiceA IMPORT "ADVAPI32.DLL" ALIAS "StartServiceA" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwNumServiceArgs AS DWORD _                    ' __in DWORD dwNumServiceArgs
 , BYVAL lpServiceArgVectors AS DWORD _                 ' __in LPCSTR * lpServiceArgVectors
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartServiceW LIB "AdvApi32.dll" _
    ALIAS "StartServiceW" ( _
    BYVAL hService            AS DWORD, _
    BYVAL dwNumServiceArgs    AS DWORD, _
    lpServiceArgVectors       AS ANY _
    ) AS LONG
#ELSE
DECLARE FUNCTION StartServiceW IMPORT "ADVAPI32.DLL" ALIAS "StartServiceW" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE hService
 , BYVAL dwNumServiceArgs AS DWORD _                    ' __in DWORD dwNumServiceArgs
 , BYREF lpServiceArgVectors AS WSTRINGZ _              ' __in LPCWSTR * lpServiceArgVectors
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO StartService = StartServiceW
#ELSE
   MACRO StartService = StartServiceA
#ENDIF

DECLARE FUNCTION UnlockServiceDatabase IMPORT "ADVAPI32.DLL" ALIAS "UnlockServiceDatabase" ( _
   BYVAL ScLock AS DWORD _                              ' __in SC_LOCK ScLock
 ) AS LONG                                              ' BOOL

'#if (NTDDI_VERSION >= NTDDI_VISTA)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NotifyServiceStatusChangeA LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeA" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYA PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NotifyServiceStatusChangeA IMPORT "ADVAPI32.DLL" ALIAS "NotifyServiceStatusChangeA" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE        hService
 , BYVAL dwNotifyMask AS DWORD _                        ' __in DWORD            dwNotifyMask
 , BYREF pNotifyBuffer AS SERVICE_NOTIFYA _             ' __in PSERVICE_NOTIFYA pNotifyBuffer
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NotifyServiceStatusChangeW LIB "AdvApi32.dll" _
    ALIAS "NotifyServiceStatusChangeW" ( _
    BYVAL hService      AS DWORD, _
    BYVAL dwNotifyMask  AS DWORD, _
    BYVAL pNotifyBuffer AS SERVICE_NOTIFYW PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NotifyServiceStatusChangeW IMPORT "ADVAPI32.DLL" ALIAS "NotifyServiceStatusChangeW" ( _
   BYVAL hService AS DWORD _                            ' __in SC_HANDLE        hService
 , BYVAL dwNotifyMask AS DWORD _                        ' __in DWORD            dwNotifyMask
 , BYREF pNotifyBuffer AS SERVICE_NOTIFYW _             ' __in PSERVICE_NOTIFYW pNotifyBuffer
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO NotifyServiceStatusChange = NotifyServiceStatusChangeW
#ELSE
   MACRO NotifyServiceStatusChange = NotifyServiceStatusChangeA
#ENDIF

DECLARE FUNCTION ControlServiceExA IMPORT "ADVAPI32.DLL" ALIAS "ControlServiceExA" ( _
   BYVAL hService AS DWORD _                            ' __in     SC_HANDLE hService
 , BYVAL dwControl AS DWORD _                           ' __in     DWORD     dwControl
 , BYVAL dwInfoLevel AS DWORD _                         ' __in     DWORD     dwInfoLevel
 , BYREF pControlParams AS ANY _                        ' __in_out PVOID     pControlParams
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ControlServiceExW IMPORT "ADVAPI32.DLL" ALIAS "ControlServiceExW" ( _
   BYVAL hService AS DWORD _                            ' __in     SC_HANDLE hService
 , BYVAL dwControl AS DWORD _                           ' __in     DWORD     dwControl
 , BYVAL dwInfoLevel AS DWORD _                         ' __in     DWORD     dwInfoLevel
 , BYREF pControlParams AS ANY _                        ' __in_out PVOID     pControlParams
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ControlServiceEx = ControlServiceExW
#ELSE
   MACRO ControlServiceEx = ControlServiceExA
#ENDIF

'#endif // NTDDI_VERSION >= NTDDI_VISTA
