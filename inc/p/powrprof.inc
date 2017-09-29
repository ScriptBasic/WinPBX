' ########################################################################################
' Microsoft Windows
' File: powrprof.inc
' Contents: Interface for powrprof.dll, the power policy applicator
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%POWRPROF_INC = 1

#INCLUDE ONCE "windows.inc"

'// Registry storage structures for the GLOBAL_POWER_POLICY data. There are two
'// structures, GLOBAL_MACHINE_POWER_POLICY and GLOBAL_USER_POWER_POLICY. the
'// GLOBAL_MACHINE_POWER_POLICY stores per machine data for which there is no UI.
'// GLOBAL_USER_POWER_POLICY stores the per user data.

' // Size = 16 bytes
TYPE GLOBAL_MACHINE_POWER_POLICY DWORD
   Revision      AS DWORD                 ' ULONG
   LidOpenWakeAc AS LONG                  ' SYSTEM_POWER_STATE
   LidOpenWakeDc AS LONG                  ' SYSTEM_POWER_STATE
   BroadcastCapacityResolution AS DWORD   ' ULONG
END TYPE

' // Size = 176 bytes
TYPE GLOBAL_USER_POWER_POLICY DWORD
   Revision      AS DWORD   ' ULONG
   PowerButtonAc AS POWER_ACTION_POLICY
   PowerButtonDc AS POWER_ACTION_POLICY
   SleepButtonAc AS POWER_ACTION_POLICY
   SleepButtonDc AS POWER_ACTION_POLICY
   LidCloseAc    AS POWER_ACTION_POLICY
   LidCloseDc    AS POWER_ACTION_POLICY
   DischargePolicy(%NUM_DISCHARGE_POLICIES - 1) AS SYSTEM_POWER_LEVEL
   GlobalFlags   AS DWORD   ' ULONG
END TYPE

'// Structure to manage global power policies at the user level. This structure
'// contains data which is common across all power policy profiles.

' // Size = 192 bytes
TYPE GLOBAL_POWER_POLICY DWORD
   user AS GLOBAL_USER_POWER_POLICY
   mach AS GLOBAL_MACHINE_POWER_POLICY
END TYPE

'// Registry storage structures for the POWER_POLICY data. There are three
'// structures, MACHINE_POWER_POLICY, MACHINE_PROCESSOR_POWER_POLICY and USER_POWER_POLICY. the
'// MACHINE_POWER_POLICY stores per machine data for which there is no UI.
'// USER_POWER_POLICY stores the per user data.

' // Size = 64 bytes
TYPE MACHINE_POWER_POLICY DWORD FILL
   Revision              AS DWORD   ' ULONG
   ' meaning of power action "sleep"
   MinSleepAc            AS LONG    ' SYSTEM_POWER_STATE
   MinSleepDc            AS LONG    ' SYSTEM_POWER_STATE
   ReducedLatencySleepAc AS LONG    ' SYSTEM_POWER_STATE
   ReducedLatencySleepDc AS LONG    ' SYSTEM_POWER_STATE
   ' parameters for dozing
   DozeTimeoutAc         AS DWORD   ' ULONG
   DozeTimeoutDc         AS DWORD   ' ULONG
   DozeS4TimeoutAc       AS DWORD   ' ULONG
   DozeS4TimeoutDc       AS DWORD   ' ULONG
   ' processor policies
   MinThrottleAc         AS BYTE    ' UCHAR
   MinThrottleDc         AS BYTE    ' UCHAR
   pad1(1)               AS BYTE    ' UCHAR
   OverThrottledAc       AS POWER_ACTION_POLICY
   OverThrottledDc       AS POWER_ACTION_POLICY
END TYPE

'//
'// deprecated
'//
' // Size = 156 bytes
TYPE MACHINE_PROCESSOR_POWER_POLICY DWORD
   Revision          AS DWORD   ' ULONG
   ProcessorPolicyAc AS PROCESSOR_POWER_POLICY
   ProcessorPolicyDc AS PROCESSOR_POWER_POLICY
END TYPE

' // Size = 80 bytes
TYPE USER_POWER_POLICY
   Revision               AS DWORD   ' ULONG
   ' "system idle" detection
   IdleAc                 AS POWER_ACTION_POLICY
   IdleDc                 AS POWER_ACTION_POLICY
   IdleTimeoutAc          AS DWORD   ' ULONG
   IdleTimeoutDc          AS DWORD   ' ULONG
   IdleSensitivityAc      AS BYTE    ' UCHAR
   IdleSensitivityDc      AS BYTE    ' UCHAR
   ' Throttling Policy
   ThrottlePolicyAc       AS BYTE    ' UCHAR
   ThrottlePolicyDc       AS BYTE    ' UCHAR
   ' meaning of power action "sleep"
   MaxSleepAc             AS LONG    ' SYSTEM_POWER_STATE
   MaxSleepDc             AS LONG    ' SYSTEM_POWER_STATE
   ' For future use
   Reserved(1)            AS DWORD   ' ULONG[2]
   ' video policies
   VideoTimeoutAc         AS DWORD   ' ULONG
   VideoTimeoutDc         AS DWORD   ' ULONG
   ' hard disk policies
   SpindownTimeoutAc      AS DWORD   ' ULONG
   SpindownTimeoutDc      AS DWORD   ' ULONG
   ' processor policies
   OptimizeForPowerAc     AS BYTE    ' BOOLEAN
   OptimizeForPowerDc     AS BYTE    ' BOOLEAN
   FanThrottleToleranceAc AS BYTE    ' UCHAR
   FanThrottleToleranceDc AS BYTE    ' UCHAR
   ForcedThrottleAc       AS BYTE    ' UCHAR
   ForcedThrottleDc       AS BYTE    ' UCHAR
   alignment__            AS WORD    ' // To keep DWORD alignment
END TYPE

'// Structure to manage power policies at the user level. This structure
'// contains data which is unique across power policy profiles.

' // Size = 144 bytes
TYPE POWER_POLICY DWORD
   user AS USER_POWER_POLICY
   mach AS MACHINE_POWER_POLICY
END TYPE


'// Constants for GlobalFlags

%EnableSysTrayBatteryMeter = &H01
%EnableMultiBatteryDisplay = &H02
%EnablePasswordLogon       = &H04
%EnableWakeOnRing          = &H08
%EnableVideoDimDisplay     = &H10

'//
'// Power setting attribute flags
'//

%POWER_ATTRIBUTE_HIDE       = &H00000001???

'// This constant is passed as a uiID to WritePwrScheme.
%NEWSCHEME = &HFFFFFFFF???  ' (UINT)-1

'// Prototype for EnumPwrSchemes callback proceedures.

'typedef
'BOOLEAN
'CALLBACK
'PWRSCHEMESENUMPROC_V1 (
'    __in UINT Index,
'    __in DWORD NameSize,
'    __in_bcount(NameSize) LPTSTR Name,
'    __in DWORD DescriptionSize,
'    __in_bcount(DescriptionSize) LPTSTR Description,
'    __in PPOWER_POLICY Policy,
'    __inout_opt LPARAM Context
'    );

'FUNCTION PWRSCHEMESENUMPROC_V1 ( _
'   BYVAL Index AS DWORD _                               ' __in UINT Index
' , BYVAL NameSize AS DWORD _                            ' __in DWORD NameSize
' , BYREF strName AS ASCIIZ _                            ' __in_bcount(NameSize) LPTSTR Name
' , BYVAL DescriptionSize AS DWORD _                     ' __in DWORD DescriptionSize
' , BYREF Description AS ASCIIZ _                        ' __in_bcount(DescriptionSize) LPTSTR Description
' , BYREF Policy AS POWER_POLICY _                       ' __in PPOWER_POLICY Policy
' , BYVAL Context AS LONG _                              ' __inout_opt LPARAM Context
' ) AS LONG                                              ' BOOLEAN

'typedef
'BOOLEAN
'CALLBACK
'PWRSCHEMESENUMPROC_V2 (
'    __in UINT Index,
'    __in DWORD NameSize,
'    __in_bcount(NameSize) LPWSTR Name,
'    __in DWORD DescriptionSize,
'    __in_bcount(DescriptionSize) LPWSTR Description,
'    __in PPOWER_POLICY Policy,
'    __inout_opt LPARAM Context
'    );

'FUNCTION PWRSCHEMESENUMPROC_V2 ( _
'   BYVAL Index AS DWORD _                               ' __in UINT Index
' , BYVAL NameSize AS DWORD _                            ' __in DWORD NameSize
' , BYREF bstrName AS WSTRINGZ _                         ' __in_bcount(NameSize) LPWSTR Name
' , BYVAL DescriptionSize AS DWORD _                     ' __in DWORD DescriptionSize
' , BYREF Description AS WSTRINGZ _                      ' __in_bcount(DescriptionSize) LPWSTR Description
' , BYREF Policy AS POWER_POLICY _                       ' __in PPOWER_POLICY Policy
' , BYVAL Context AS LONG _                              ' __inout_opt LPARAM Context
' ) AS LONG                                              ' BOOLEAN

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef PWRSCHEMESENUMPROC_V2 *PWRSCHEMESENUMPROC;
'#else
'typedef PWRSCHEMESENUMPROC_V1 *PWRSCHEMESENUMPROC;
'#endif

'// Public function prototypes

DECLARE FUNCTION GetPwrDiskSpindownRange IMPORT "PowrProf.dll" ALIAS "GetPwrDiskSpindownRange" ( _
   BYREF RangeMax AS DWORD _                            ' __out PUINT RangeMax
 , BYREF RangeMin AS DWORD _                            ' __out PUINT RangeMin
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION EnumPwrSchemes IMPORT "PowrProf.dll" ALIAS "EnumPwrSchemes" ( _
   BYVAL lpfnPwrSchemesEnumProc AS DWORD _              ' __in PWRSCHEMESENUMPROC lpfnPwrSchemesEnumProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION ReadGlobalPwrPolicy IMPORT "PowrProf.dll" ALIAS "ReadGlobalPwrPolicy" ( _
   BYREF pGlobalPowerPolicy AS GLOBAL_POWER_POLICY _    ' __out PGLOBAL_POWER_POLICY pGlobalPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION ReadPwrScheme IMPORT "PowrProf.dll" ALIAS "ReadPwrScheme" ( _
   BYVAL uiID AS DWORD _                                ' __in  UINT uiID
 , BYREF pPowerPolicy AS POWER_POLICY _                 ' __out PPOWER_POLICY pPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

' WritePwrScheme is no longer available for use as of Windows Vista. Instead, use the PowerEnumerate function
' to enumerate power settings for a specified scheme, and the power write functions to write individual settings.]
DECLARE FUNCTION WritePwrScheme IMPORT "PowrProf.dll" ALIAS "WritePwrScheme" ( _
   BYREF puiID AS DWORD _                               ' __in PUINT puiID
 , BYREF lpszName AS WSTRINGZ _                         ' __in LPWSTR lpszName
 , BYREF lpszDescription AS WSTRINGZ _                  ' __in LPWSTR lpszDescription
 , BYREF pPowerPolicy AS POWER_POLICY _                 ' __in PPOWER_POLICY pPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION WriteGlobalPwrPolicy IMPORT "PowrProf.dll" ALIAS "WriteGlobalPwrPolicy" ( _
   BYREF pGlobalPowerPolicy AS GLOBAL_POWER_POLICY _    ' __in PGLOBAL_POWER_POLICY pGlobalPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION DeletePwrScheme IMPORT "PowrProf.dll" ALIAS "DeletePwrScheme" ( _
   BYVAL uiIndex AS DWORD _                             ' __in UINT uiIndex
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetActivePwrScheme IMPORT "PowrProf.dll" ALIAS "GetActivePwrScheme" ( _
   BYREF puiID AS DWORD _                               ' __out PUINT puiID
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION SetActivePwrScheme IMPORT "PowrProf.dll" ALIAS "SetActivePwrScheme" ( _
   BYVAL uiID AS DWORD _                                ' __in UINT uiID
 , BYREF pGlobalPowerPolicy AS GLOBAL_POWER_POLICY _    ' __in PGLOBAL_POWER_POLICY pGlobalPowerPolicy
 , BYREF pPowerPolicy AS POWER_POLICY _                 ' __in POWER_POLICY pPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetPwrCapabilities IMPORT "PowrProf.dll" ALIAS "GetPwrCapabilities" ( _
   BYREF pSystemPowerCapabilities AS SYSTEM_POWER_CAPABILITIES _ ' __out PSYSTEM_POWER_CAPABILITIES pSystemPowerCapabilities
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION IsPwrSuspendAllowed IMPORT "PowrProf.dll" ALIAS "IsPwrSuspendAllowed" ( _
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION IsPwrHibernateAllowed IMPORT "PowrProf.dll" ALIAS "IsPwrHibernateAllowed" ( _
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION IsPwrShutdownAllowed IMPORT "PowrProf.dll" ALIAS "IsPwrShutdownAllowed" ( _
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION IsAdminOverrideActive IMPORT "PowrProf.dll" ALIAS "IsAdminOverrideActive" ( _
   BYREF pAdministratorPowerPolicy AS ADMINISTRATOR_POWER_POLICY _ ' __in PADMINISTRATOR_POWER_POLICY pAdministratorPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION SetSuspendState IMPORT "PowrProf.dll" ALIAS "SetSuspendState" ( _
   BYVAL Hibernate AS BYTE _                            ' __in BOOLEAN Hibernate
 , BYVAL ForceCritical AS BYTE _                        ' __in BOOLEAN ForceCritical
 , BYVAL DisableWakeEvent AS BYTE _                     ' __in BOOLEAN DisableWakeEvent
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetCurrentPowerPolicies IMPORT "PowrProf.dll" ALIAS "GetCurrentPowerPolicies" ( _
   BYREF pGlobalPowerPolicy AS GLOBAL_POWER_POLICY _    ' __out PGLOBAL_POWER_POLICY pGlobalPowerPolicy
 , BYREF pPowerPolicy AS POWER_POLICY _                 ' __out PPOWER_POLICY pPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION CanUserWritePwrScheme IMPORT "PowrProf.dll" ALIAS "CanUserWritePwrScheme" ( _
 ) AS BYTE                                              ' BOOLEAN

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'//
'// deprecated.
'//
DECLARE FUNCTION ReadProcessorPwrScheme IMPORT "PowrProf.dll" ALIAS "ReadProcessorPwrScheme" ( _
   BYVAL uiID AS DWORD _                                ' __in  UINT uiID
 , BYREF pMachineProcessorPowerPolicy AS MACHINE_PROCESSOR_POWER_POLICY _ ' __out PMACHINE_PROCESSOR_POWER_POLICY pMachineProcessorPowerPolicy
 ) AS BYTE                                              ' BOOLEAN
'#endif

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'//
'// deprecated.
'//
DECLARE FUNCTION WriteProcessorPwrScheme IMPORT "PowrProf.dll" ALIAS "WriteProcessorPwrScheme" ( _
   BYVAL uiID AS DWORD _                                ' __in UINT uiID
 , BYREF pMachineProcessorPowerPolicy AS MACHINE_PROCESSOR_POWER_POLICY _ ' __in PMACHINE_PROCESSOR_POWER_POLICY pMachineProcessorPowerPolicy
 ) AS BYTE                                              ' BOOLEAN
'#endif

DECLARE FUNCTION ValidatePowerPolicies IMPORT "PowrProf.dll" ALIAS "ValidatePowerPolicies" ( _
   BYREF pGlobalPowerPolicy AS GLOBAL_POWER_POLICY _    ' __in PGLOBAL_POWER_POLICY pGlobalPowerPolicy
 , OPTIONAL BYREF pPowerPolicy AS POWER_POLICY _        ' __inout_opt PPOWER_POLICY pPowerPolicy
 ) AS BYTE                                              ' BOOLEAN

'#ifndef NT_SUCCESS
'#define NTSTATUS LONG
'#define _OVERRIDE_NTSTATUS_
'#endif

DECLARE FUNCTION CallNtPowerInformation IMPORT "PowrProf.dll" ALIAS "CallNtPowerInformation" ( _
   BYVAL InformationLevel AS LONG _                     ' __in  POWER_INFORMATION_LEVEL InformationLevel
 , BYVAL lpInputBuffer AS DWORD _                       ' __in  PVOID lpInputBuffer
 , BYVAL nInputBufferSize AS DWORD _                    ' __in  ULONG nInputBufferSize
 , BYVAL lpOutputBuffer AS DWORD _                      ' __out PVOID lpOutputBuffer
 , BYVAL nOutputBufferSize AS DWORD _                   ' __in  ULONG nOutputBufferSize
 ) AS LONG                                              ' NTSTATUS

'#ifdef _OVERRIDE_NTSTATUS_
'#undef NTSTATUS
'#endif

'//
'// Enum which defines which field inside of a
'// power setting is being accessed.
'//
' enum _POWER_DATA_ACCESSOR
'// Used by read/write and enumeration engines
%ACCESS_AC_POWER_SETTING_INDEX = 0
%ACCESS_DC_POWER_SETTING_INDEX = 1
%ACCESS_FRIENDLY_NAME = 2
%ACCESS_DESCRIPTION = 3
%ACCESS_POSSIBLE_POWER_SETTING = 4
%ACCESS_POSSIBLE_POWER_SETTING_FRIENDLY_NAME = 5
%ACCESS_POSSIBLE_POWER_SETTING_DESCRIPTION = 6
%ACCESS_DEFAULT_AC_POWER_SETTING = 7
%ACCESS_DEFAULT_DC_POWER_SETTING = 8
%ACCESS_POSSIBLE_VALUE_MIN = 9
%ACCESS_POSSIBLE_VALUE_MAX = 10
%ACCESS_POSSIBLE_VALUE_INCREMENT = 11
%ACCESS_POSSIBLE_VALUE_UNITS = 12
%ACCESS_ICON_RESOURCE = 13
%ACCESS_DEFAULT_SECURITY_DESCRIPTOR = 14
%ACCESS_ATTRIBUTES = 15
'// Used by enumeration engine.
%ACCESS_SCHEME = 16
%ACCESS_SUBGROUP = 17
%ACCESS_INDIVIDUAL_SETTING = 18
'// Used by access check
%ACCESS_ACTIVE_SCHEME = 19
%ACCESS_CREATE_SCHEME = 20
'// Used by override ranges.
%ACCESS_AC_POWER_SETTING_MAX = 21
%ACCESS_DC_POWER_SETTING_MAX = 22
%ACCESS_AC_POWER_SETTING_MIN = 23
%ACCESS_DC_POWER_SETTING_MIN = 24

'//
'// =========================================
'// Power Scheme APIs
'// =========================================
'//

'#if !defined(_HPOWERNOTIFY_DEF_)

'#define _HPOWERNOTIFY_DEF_

'typedef  PVOID           HPOWERNOTIFY;
'typedef  HPOWERNOTIFY   *PHPOWERNOTIFY;

'#endif

'#if (NTDDI_VERSION >= NTDDI_WIN7)
DECLARE FUNCTION PowerSettingRegisterNotification IMPORT "PowrProf.dll" ALIAS "PowerSettingRegisterNotification" ( _
   BYREF SettingGuid AS GUID _                          ' __in LPCGUID SettingGuid
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Recipient AS DWORD _                           ' __in HANDLE Recipient
 , BYREF RegistrationHandle AS ANY _                    ' __out PHPOWERNOTIFY RegistrationHandle
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_WIN7)
DECLARE FUNCTION PowerSettingUnregisterNotification IMPORT "PowrProf.dll" ALIAS "PowerSettingUnregisterNotification" ( _
   BYREF RegistrationHandle AS ANY _                    ' __inout HPOWERNOTIFY RegistrationHandle
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerSettingAccessCheck IMPORT "PowrProf.dll" ALIAS "PowerSettingAccessCheck" ( _
   BYVAL AccessFlags AS DWORD _                         ' __in POWER_DATA_ACCESSOR AccessFlags
 , OPTIONAL BYREF PowerGuid AS GUID _                   ' __in_opt CONST GUID *PowerGuid
 ) AS DWORD                                             ' DWORD
'#endif

'//
'// Read functions.
'//

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadACValueIndex IMPORT "PowrProf.dll" ALIAS "PowerReadACValueIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF AcValueIndex AS DWORD _                        ' __out LPDWORD AcValueIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadDCValueIndex IMPORT "PowrProf.dll" ALIAS "PowerReadDCValueIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF DcValueIndex AS DWORD _                        ' __out LPDWORD DcValueIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadACValue LIB "PowrProf.dll" ALIAS "PowerReadACValue" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadACValue IMPORT "PowrProf.dll" ALIAS "PowerReadACValue" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF Type AS DWORD _                                ' __out_opt PULONG Type
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) LPBYTE Buffer
 , OPTIONAL BYREF BufferSize AS DWORD _                 ' __inout_opt LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadDCValue LIB "PowrProf.dll" ALIAS "PowerReadDCValue" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadDCValue IMPORT "PowrProf.dll" ALIAS "PowerReadDCValue" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF Type AS DWORD _                                ' __out_opt PULONG Type
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerReadFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadFriendlyName IMPORT "PowrProf.dll" ALIAS "PowerReadFriendlyName" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadDescription LIB "PowrProf.dll" _
    ALIAS "PowerReadDescription" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadDescription IMPORT "PowrProf.dll" ALIAS "PowerReadDescription" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadPossibleValue LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleValue" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadPossibleValue IMPORT "PowrProf.dll" ALIAS "PowerReadPossibleValue" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF Type AS DWORD _                                ' __out_opt PULONG Type
 , BYREF PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadPossibleFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadPossibleFriendlyName IMPORT "PowrProf.dll" ALIAS "PowerReadPossibleFriendlyName" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadPossibleDescription LIB "PowrProf.dll" _
    ALIAS "PowerReadPossibleDescription" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadPossibleDescription IMPORT "PowrProf.dll" ALIAS "PowerReadPossibleDescription" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadValueMin IMPORT "PowrProf.dll" ALIAS "PowerReadValueMin" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF ValueMinimum AS DWORD _                        ' __out LPDWORD ValueMinimum
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadValueMax IMPORT "PowrProf.dll" ALIAS "PowerReadValueMax" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF ValueMaximum AS DWORD _                        ' __out LPDWORD ValueMaximum
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadValueIncrement IMPORT "PowrProf.dll" ALIAS "PowerReadValueIncrement" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYREF ValueIncrement AS DWORD _                      ' __out LPDWORD ValueIncrement
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadValueUnitsSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerReadValueUnitsSpecifier" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadValueUnitsSpecifier IMPORT "PowrProf.dll" ALIAS "PowerReadValueUnitsSpecifier" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) UCHAR *Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadACDefaultIndex IMPORT "PowrProf.dll" ALIAS "PowerReadACDefaultIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemePersonalityGuid AS GUID _                ' __in CONST GUID *SchemePersonalityGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid OPTIONAL
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 , BYREF AcDefaultIndex AS DWORD _                      ' __out LPDWORD AcDefaultIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadDCDefaultIndex IMPORT "PowrProf.dll" ALIAS "PowerReadDCDefaultIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemePersonalityGuid AS GUID _                ' __in CONST GUID *SchemePersonalityGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 , BYREF DcDefaultIndex AS DWORD _                      ' __out LPDWORD DcDefaultIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerReadIconResourceSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerReadIconResourceSpecifier" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, _
    bBuffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerReadIconResourceSpecifier IMPORT "PowrProf.dll" ALIAS "PowerReadIconResourceSpecifier" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) PUCHAR Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout LPDWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReadSettingAttributes IMPORT "PowrProf.dll" ALIAS "PowerReadSettingAttributes" ( _
   OPTIONAL BYREF SubGroupGuid AS GUID _                ' __in_opt CONST GUID *SubGroupGuid
 , OPTIONAL BYREF PowerSettingGuid AS GUID _            ' __in_opt CONST GUID *PowerSettingGuid
 ) AS DWORD                                             ' DWORD
'#endif

'//
'// Write functions.
'//

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteACValueIndex IMPORT "PowrProf.dll" ALIAS "PowerWriteACValueIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL AcValueIndex AS DWORD _                        ' __in DWORD AcValueIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteDCValueIndex IMPORT "PowrProf.dll" ALIAS "PowerWriteDCValueIndex" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL DcValueIndex AS DWORD _                        ' __in DWORD DcValueIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWriteFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerWriteFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION PowerWriteFriendlyName IMPORT "PowrProf.dll" ALIAS "PowerWriteFriendlyName" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __in UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWriteDescription LIB "PowrProf.dll" _
    ALIAS "PowerWriteDescription" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION PowerWriteDescription IMPORT "PowrProf.dll" ALIAS "PowerWriteDescription" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWritePossibleValue LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleValue" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    dType AS DWORD, BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerWritePossibleValue IMPORT "PowrProf.dll" ALIAS "PowerWritePossibleValue" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Type AS DWORD _                                ' __in ULONG Type
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWritePossibleFriendlyName LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleFriendlyName" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerWritePossibleFriendlyName IMPORT "PowrProf.dll" ALIAS "PowerWritePossibleFriendlyName" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWritePossibleDescription LIB "PowrProf.dll" _
    ALIAS "PowerWritePossibleDescription" (BYVAL RootPowerKey AS DWORD, _
    SubGroupOfPowerSettingsGuid AS GUID, PowerSettingGuid AS GUID, _
    BYVAL PossibleSettingIndex AS DWORD, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerWritePossibleDescription IMPORT "PowrProf.dll" ALIAS "PowerWritePossibleDescription" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteValueMin IMPORT "PowrProf.dll" ALIAS "PowerWriteValueMin" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL ValueMinimum AS DWORD _                        ' __in DWORD ValueMinimum
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteValueMax IMPORT "PowrProf.dll" ALIAS "PowerWriteValueMax" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL ValueMaximum AS DWORD _                        ' __in DWORD ValueMaximum
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteValueIncrement IMPORT "PowrProf.dll" ALIAS "PowerWriteValueIncrement" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL ValueIncrement AS DWORD _                      ' __in DWORD ValueIncrement
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWriteValueUnitsSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerWriteValueUnitsSpecifier" _
    (BYVAL RootPowerKey AS DWORD, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, bBuffer AS DWORD, BYVAL BufferSize AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION PowerWriteValueUnitsSpecifier IMPORT "PowrProf.dll" ALIAS "PowerWriteValueUnitsSpecifier" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteACDefaultIndex IMPORT "PowrProf.dll" ALIAS "PowerWriteACDefaultIndex" ( _
   BYVAL RootSystemPowerKey AS DWORD _                  ' __in_opt HKEY RootSystemPowerKey
 , BYREF SchemePersonalityGuid AS GUID _                ' __in CONST GUID *SchemePersonalityGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 , BYVAL DefaultAcIndex AS DWORD _                      ' __in DWORD DefaultAcIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteDCDefaultIndex IMPORT "PowrProf.dll" ALIAS "PowerWriteDCDefaultIndex" ( _
   BYVAL RootSystemPowerKey AS DWORD _                  ' __in_opt HKEY RootSystemPowerKey
 , BYREF SchemePersonalityGuid AS GUID _                ' __in CONST GUID *SchemePersonalityGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 , BYVAL DefaultDcIndex AS DWORD _                      ' __in DWORD DefaultDcIndex
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerWriteIconResourceSpecifier LIB "PowrProf.dll" _
    ALIAS "PowerWriteIconResourceSpecifier" (BYVAL RootPowerKey AS DWORD, _
    SchemeGuid AS GUID, SubGroupOfPowerSettingsGuid AS GUID, _
    PowerSettingGuid AS GUID, _
    bBuffer AS DWORD, BYVAL BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerWriteIconResourceSpecifier IMPORT "PowrProf.dll" ALIAS "PowerWriteIconResourceSpecifier" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Buffer AS BYTE PTR _                           ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerWriteSettingAttributes IMPORT "PowrProf.dll" ALIAS "PowerWriteSettingAttributes" ( _
   BYREF SubGroupGuid AS GUID _                         ' __in_opt CONST GUID *SubGroupGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL Attributes AS DWORD _                          ' __in DWORD Attributes
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerDuplicateScheme IMPORT "PowrProf.dll" ALIAS "PowerDuplicateScheme" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SourceSchemeGuid AS GUID _                     ' __in CONST GUID *SourceSchemeGuid
 , BYREF DestinationSchemeGuid AS DWORD _                ' __in GUID **DestinationSchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerImportPowerScheme IMPORT "PowrProf.dll" ALIAS "PowerImportPowerScheme" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF ImportFileNamePath AS WSTRINGZ _               ' __in LPCWSTR ImportFileNamePath
 , BYREF DestinationSchemeGuid AS DWORD _               ' __inout GUID **DestinationSchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerDeleteScheme IMPORT "PowrProf.dll" ALIAS "PowerDeleteScheme" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerRemovePowerSetting IMPORT "PowrProf.dll" ALIAS "PowerRemovePowerSetting" ( _
   BYREF PowerSettingSubKeyGuid AS GUID _               ' __in CONST GUID *PowerSettingSubKeyGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerCreateSetting IMPORT "PowrProf.dll" ALIAS "PowerCreateSetting" ( _
   BYVAL RootSystemPowerKey AS DWORD _                  ' __in_opt HKEY RootSystemPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerCreatePossibleSetting IMPORT "PowrProf.dll" ALIAS "PowerCreatePossibleSetting" ( _
   BYVAL RootSystemPowerKey AS DWORD _                  ' __in_opt HKEY RootSystemPowerKey
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in CONST GUID *PowerSettingGuid
 , BYVAL PossibleSettingIndex AS DWORD _                ' __in ULONG PossibleSettingIndex
 ) AS DWORD                                             ' DWORD
'#endif

'//
'// Enumerate Functions.
'//

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PowerEnumerate LIB "PowrProf.dll" ALIAS "PowerEnumerate" _
    (BYVAL RootPowerKey AS DWORD, SchemeGuid AS GUID, _
    SubGroupOfPowerSettingsGuid AS GUID, _
    BYVAL AccessFlags AS DWORD, _
    BYVAL nIndex AS DWORD, Buffer AS DWORD, BufferSize AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION PowerEnumerate IMPORT "PowrProf.dll" ALIAS "PowerEnumerate" ( _
   BYVAL RootPowerKey AS DWORD _                        ' __in_opt HKEY RootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYVAL AccessFlags AS DWORD _                         ' __in POWER_DATA_ACCESSOR AccessFlags
 , BYVAL Index AS DWORD _                               ' __in ULONG Index
 , BYVAL Buffer AS BYTE PTR _                           ' __out_bcount_opt(*BufferSize) UCHAR *Buffer
 , BYREF BufferSize AS DWORD _                          ' __inout DWORD *BufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif

'//
'// Activate Functions.
'//

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerSetActiveScheme IMPORT "PowrProf.dll" ALIAS "PowerSetActiveScheme" ( _
   BYVAL UserRootPowerKey AS DWORD _                    ' __in_opt HKEY UserRootPowerKey
 , BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerGetActiveScheme IMPORT "PowrProf.dll" ALIAS "PowerGetActiveScheme" ( _
   BYVAL UserRootPowerKey AS DWORD _                    ' __in_opt HKEY UserRootPowerKey
 , BYREF ActivePolicyGuid AS DWORD _                    ' __out GUID **ActivePolicyGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerOpenUserPowerKey IMPORT "PowrProf.dll" ALIAS "PowerOpenUserPowerKey" ( _
   BYREF phUserPowerKey AS DWORD _                      ' __out HKEY *phUserPowerKey
 , BYVAL Access AS REGSAM _                             ' __in REGSAM Access
 , BYVAL OpenExisting AS DWORD _                        ' __in BOOL OpenExisting
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerOpenSystemPowerKey IMPORT "PowrProf.dll" ALIAS "PowerOpenSystemPowerKey" ( _
   BYREF phSystemPowerKey AS DWORD _                    ' __out HKEY *phSystemPowerKey
 , BYVAL Access AS REGSAM _                             ' __in REGSAM Access
 , BYVAL OpenExisting AS LONG _                         ' __in BOOL OpenExisting
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerCanRestoreIndividualDefaultPowerScheme IMPORT "PowrProf.dll" ALIAS "PowerCanRestoreIndividualDefaultPowerScheme" ( _
   BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerRestoreIndividualDefaultPowerScheme IMPORT "PowrProf.dll" ALIAS "PowerRestoreIndividualDefaultPowerScheme" ( _
   BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerRestoreDefaultPowerSchemes IMPORT "PowrProf.dll" ALIAS "PowerRestoreDefaultPowerSchemes" ( _
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerReplaceDefaultPowerSchemes IMPORT "PowrProf.dll" ALIAS "PowerReplaceDefaultPowerSchemes" ( _
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION PowerDeterminePlatformRole IMPORT "PowrProf.dll" ALIAS "PowerDeterminePlatformRole" ( _
 ) AS LONG                                              ' POWER_PLATFORM_ROLE enum
'#endif

'//
'// =========================================
'// Device Power APIs
'// =========================================
'//
'//
'// ========================================================
'// These flags tell us how to interpret a query of
'// device power.  Use these (or a combination of these)
'// for the QueryInterpretationFlags parameter sent into
'// DevicePowerEnumDevices().
'//
'// They'll ask us for some devices that supports some
'// D state.  These flags help us determine what the
'// user really wants.  I.e. does he want the device
'// name, or the hardware ID.  Does he want some device
'// that supports some D state, or does he want us to
'// go see if that devices supports some S state? ...
'// ========================================================
'//

'//
'// Return HardwareID instead of the friendly device name, which
'// is the default.
'//
%DEVICEPOWER_HARDWAREID             = &H80000000???

'//
'//
'// 'and' the requested power states.  I.e. if the user requested
'// that we query devices supporting D1 and D3, this flag says
'// "give me devices that support D1 *and* D3".  Without this
'// flag, the query would be interpreted as "give me devices
'// that support D1 *or* D3".
'//
%DEVICEPOWER_AND_OPERATION          = &H40000000???

'// Only preform the query on devices that are present in the system.
'//
%DEVICEPOWER_FILTER_DEVICES_PRESENT = &H20000000???

'//
'// Only preform the query on devices that are actual hardware.
'//
%DEVICEPOWER_FILTER_HARDWARE        = &H10000000???

'//
'// Only preform the query on devices that are armed to wake the
'// system from a sleep state.
'//
%DEVICEPOWER_FILTER_WAKEENABLED     = &H08000000???

'//
'// Only preform the query on devices that are capable of being programmed
'// to wake the system from a sleep state.
'//
%DEVICEPOWER_FILTER_WAKEPROGRAMMABLE = &H04000000???

'//
'// Go find the device who's name is specifed by an input
'// parameter, then see if it's got the capabilities specified
'// in QueryFlags.
'//
%DEVICEPOWER_FILTER_ON_NAME         = &H02000000???

'//
'// Define flags to set/clear capabilities in the devices.
'//

'//
'// Enable the device to wake the system from a sleep state.
'//
%DEVICEPOWER_SET_WAKEENABLED = &H00000001???

'//
'// Disable the device from waking the system from a sleep
'// state.
'//
%DEVICEPOWER_CLEAR_WAKEENABLED = &H00000002???

'//
'// For the QueryFlags parameter, the user should send in
'// one of the PDCAP_D*_SUPPORTED flags found in ntpoapi.h.
'//
'// #define PDCAP_D0_SUPPORTED              0x00000001
'// #define PDCAP_D1_SUPPORTED              0x00000002
'// #define PDCAP_D2_SUPPORTED              0x00000004
'// #define PDCAP_D3_SUPPORTED              0x00000008
'// #define PDCAP_WAKE_FROM_D0_SUPPORTED    0x00000010
'// #define PDCAP_WAKE_FROM_D1_SUPPORTED    0x00000020
'// #define PDCAP_WAKE_FROM_D2_SUPPORTED    0x00000040
'// #define PDCAP_WAKE_FROM_D3_SUPPORTED    0x00000080
'// #define PDCAP_WARM_EJECT_SUPPORTED      0x00000100
'//
'// The user can also send in a combination of these values
'// to do queries that match either or both of the specified
'// flags.  E.g. if the user used (PDCAP_D1_SUPPORTED | PDCAP_D3_SUPPORTED),
'// then the query would return a device that supported *either*
'// D1 or D3.  The user could specify QUERY_AND_OPERATION in
'// QueryInterpretationFlags to get a device that supported
'// D1 *and* D3.
'//

'//
'// We also support querying on S states.  Although devices don't
'// really understand system states, we can use the D-to-S state
'// mappings to derive this.  For example, if we ask a device if
'// he supports S2, we can derive that by looking at his D-to-S
'// mappings.  Suppose the device has a D-to-S state mapping
'// that looks like this:
'// S0 -> D0
'// S1 -> D3
'// S2 -> D3
'// S3 -> D3
'// S4 -> D3
'// S5 -> D3
'//
'// We see that S2 maps to D3 on this device.  Does this device
'// actually support D3?  We can find that out.  If so, then we
'// say that this device supports S2.
'//
'// We have to make up the S-state vectors because there's no
'// existing values like the PDCAP_D* values.
'//
%PDCAP_S0_SUPPORTED              = &H00010000???
%PDCAP_S1_SUPPORTED              = &H00020000???
%PDCAP_S2_SUPPORTED              = &H00040000???
%PDCAP_S3_SUPPORTED              = &H00080000???
%PDCAP_WAKE_FROM_S0_SUPPORTED    = &H00100000???
%PDCAP_WAKE_FROM_S1_SUPPORTED    = &H00200000???
%PDCAP_WAKE_FROM_S2_SUPPORTED    = &H00400000???
%PDCAP_WAKE_FROM_S3_SUPPORTED    = &H00800000???
%PDCAP_S4_SUPPORTED              = &H01000000???
%PDCAP_S5_SUPPORTED              = &H02000000???

'//
'// Function prototypes
'//

'#if (NTDDI_VERSION >= NTDDI_WS03)
DECLARE FUNCTION DevicePowerEnumDevices IMPORT "PowrProf.dll" ALIAS "DevicePowerEnumDevices" ( _
   BYVAL QueryIndex AS DWORD _                          ' __in ULONG  QueryIndex
 , BYVAL QueryInterpretationFlags AS DWORD _            ' __in ULONG  QueryInterpretationFlags
 , BYVAL QueryFlags AS DWORD _                          ' __in ULONG  QueryFlags
 , BYVAL pReturnBuffer AS BYTE PTR _                    ' __out_bcount_opt(*pBufferSize) PBYTE  pReturnBuffer
 , BYREF pBufferSize AS DWORD _                         ' __inout PULONG pBufferSize
 ) AS BYTE                                              ' BOOLEAN
'#endif

'#if (NTDDI_VERSION >= NTDDI_WS03)
DECLARE FUNCTION DevicePowerSetDeviceState IMPORT "PowrProf.dll" ALIAS "DevicePowerSetDeviceState" ( _
   BYREF DeviceDescription AS WSTRINGZ _                ' __in LPCWSTR DeviceDescription
 , BYREF SetFlags AS DWORD _                            ' __in ULONG SetFlags
 , OPTIONAL BYVAL SetData AS DWORD _                    ' __in_opt PVOID SetData
 ) AS DWORD                                             ' DWORD
'#endif

'#if (NTDDI_VERSION >= NTDDI_WS03)
DECLARE FUNCTION DevicePowerOpen IMPORT "PowrProf.dll" ALIAS "DevicePowerOpen" ( _
   OPTIONAL BYVAL DebugMask AS DWORD _                  ' __in_opt ULONG DebugMask
 ) AS BYTE                                              ' BOOLEAN
'#endif

'#if (NTDDI_VERSION >= NTDDI_WS03)
DECLARE FUNCTION DevicePowerClose IMPORT "PowrProf.dll" ALIAS "DevicePowerClose" ( _
 ) AS BYTE                                              ' BOOLEAN
'#endif
