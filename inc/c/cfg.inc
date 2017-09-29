' ########################################################################################
' Microsoft Windows
' File: cfg.inc
' Contents: Common Configuration Manager definitions for both user mode and kernel mode code.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CFG_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// The following definitions are also used by kernel mode code to
'// set up the registry.
'//
'//
'// VetoType used in
'//      CM_Disable_DevNode
'//      CM_Uninstall_DevNode
'//      CM_Query_And_Remove_SubTree
'//
' enum PNP_VETO_TYPE
%PNP_VetoTypeUnknown          = 0   ' // Name is unspecified
%PNP_VetoLegacyDevice         = 1   ' // Name is an Instance Path
%PNP_VetoPendingClose         = 2   ' // Name is an Instance Path
%PNP_VetoWindowsApp           = 3   ' // Name is a Module
%PNP_VetoWindowsService       = 4   ' // Name is a Service
%PNP_VetoOutstandingOpen      = 5   ' // Name is an Instance Path
%PNP_VetoDevice               = 6   ' // Name is an Instance Path
%PNP_VetoDriver               = 7   ' // Name is a Driver Service Name
%PNP_VetoIllegalDeviceRequest = 8   ' // Name is an Instance Path
%PNP_VetoInsufficientPower    = 9   ' // Name is unspecified
%PNP_VetoNonDisableable       = 10  ' // Name is an Instance Path
%PNP_VetoLegacyDriver         = 11  ' // Name is a Service
%PNP_VetoInsufficientRights   = 12  ' // Name is unspecified


'//
'// DevInst problem values, returned by call to CM_Get_DevInst_Status
'//
%CM_PROB_NOT_CONFIGURED             = &H00000001???   ' // no config for device
%CM_PROB_DEVLOADER_FAILED           = &H00000002???   ' // service load failed
%CM_PROB_OUT_OF_MEMORY              = &H00000003???   ' // out of memory
%CM_PROB_ENTRY_IS_WRONG_TYPE        = &H00000004???   ' //
%CM_PROB_LACKED_ARBITRATOR          = &H00000005???   ' //
%CM_PROB_BOOT_CONFIG_CONFLICT       = &H00000006???   ' // boot config conflict
%CM_PROB_FAILED_FILTER              = &H00000007???   ' //
%CM_PROB_DEVLOADER_NOT_FOUND        = &H00000008???   ' // Devloader not found
%CM_PROB_INVALID_DATA               = &H00000009???   ' // Invalid ID
%CM_PROB_FAILED_START               = &H0000000A???   ' //
%CM_PROB_LIAR                       = &H0000000B???   ' //
%CM_PROB_NORMAL_CONFLICT            = &H0000000C???   ' // config conflict
%CM_PROB_NOT_VERIFIED               = &H0000000D???   ' //
%CM_PROB_NEED_RESTART               = &H0000000E???   ' // requires restart
%CM_PROB_REENUMERATION              = &H0000000F???   ' //
%CM_PROB_PARTIAL_LOG_CONF           = &H00000010???   ' //
%CM_PROB_UNKNOWN_RESOURCE           = &H00000011???   ' // unknown res type
%CM_PROB_REINSTALL                  = &H00000012???   ' //
%CM_PROB_REGISTRY                   = &H00000013???   ' //
%CM_PROB_VXDLDR                     = &H00000014???   ' // WINDOWS 95 ONLY
%CM_PROB_WILL_BE_REMOVED            = &H00000015???   ' // devinst will remove
%CM_PROB_DISABLED                   = &H00000016???   ' // devinst is disabled
%CM_PROB_DEVLOADER_NOT_READY        = &H00000017???   ' // Devloader not ready
%CM_PROB_DEVICE_NOT_THERE           = &H00000018???   ' // device doesn't exist
%CM_PROB_MOVED                      = &H00000019???   ' //
%CM_PROB_TOO_EARLY                  = &H0000001A???   ' //
%CM_PROB_NO_VALID_LOG_CONF          = &H0000001B???   ' // no valid log config
%CM_PROB_FAILED_INSTALL             = &H0000001C???   ' // install failed
%CM_PROB_HARDWARE_DISABLED          = &H0000001D???   ' // device disabled
%CM_PROB_CANT_SHARE_IRQ             = &H0000001E???   ' // can't share IRQ
%CM_PROB_FAILED_ADD                 = &H0000001F???   ' // driver failed add
%CM_PROB_DISABLED_SERVICE           = &H00000020???   ' // service's Start = 4
%CM_PROB_TRANSLATION_FAILED         = &H00000021???   ' // resource translation failed
%CM_PROB_NO_SOFTCONFIG              = &H00000022???   ' // no soft config
%CM_PROB_BIOS_TABLE                 = &H00000023???   ' // device missing in BIOS table
%CM_PROB_IRQ_TRANSLATION_FAILED     = &H00000024???   ' // IRQ translator failed
%CM_PROB_FAILED_DRIVER_ENTRY        = &H00000025???   ' // DriverEntry(??? failed.
%CM_PROB_DRIVER_FAILED_PRIOR_UNLOAD = &H00000026???   ' // Driver should have unloaded.
%CM_PROB_DRIVER_FAILED_LOAD         = &H00000027???   ' // Driver load unsuccessful.
%CM_PROB_DRIVER_SERVICE_KEY_INVALID = &H00000028???   ' // Error accessing driver's service key
%CM_PROB_LEGACY_SERVICE_NO_DEVICES  = &H00000029???   ' // Loaded legacy service created no devices
%CM_PROB_DUPLICATE_DEVICE           = &H0000002A???   ' // Two devices were discovered with the same name
%CM_PROB_FAILED_POST_START          = &H0000002B???   ' // The drivers set the device state to failed
%CM_PROB_HALTED                     = &H0000002C???   ' // This device was failed post start via usermode
%CM_PROB_PHANTOM                    = &H0000002D???   ' // The devinst currently exists only in the registry
%CM_PROB_SYSTEM_SHUTDOWN            = &H0000002E???   ' // The system is shutting down
%CM_PROB_HELD_FOR_EJECT             = &H0000002F???   ' // The device is offline awaiting removal
%CM_PROB_DRIVER_BLOCKED             = &H00000030???   ' // One or more drivers is blocked from loading
%CM_PROB_REGISTRY_TOO_LARGE         = &H00000031???   ' // System hive has grown too large
%CM_PROB_SETPROPERTIES_FAILED       = &H00000032???   ' // Failed to apply one or more registry properties
%CM_PROB_WAITING_ON_DEPENDENCY      = &H00000033???   ' // Device is stalled waiting on a dependency to start
%CM_PROB_UNSIGNED_DRIVER            = &H00000034???   ' // Failed load driver due to unsigned image.

%NUM_CM_PROB_V1                     = &H00000025???
%NUM_CM_PROB_V2                     = &H00000032???
%NUM_CM_PROB_V3                     = &H00000033???
%NUM_CM_PROB_V4                     = &H00000034???
%NUM_CM_PROB_V5                     = &H00000035???

'#if (NTDDI_VERSION >= NTDDI_WIN7)
#IF %WINVER >= &H0601
%NUM_CM_PROB = %NUM_CM_PROB_V5
'#elif (NTDDI_VERSION >= NTDDI_WS08)
#ELSEIF %WINVER >= &H0600
%NUM_CM_PROB = %NUM_CM_PROB_V4
'#elif (NTDDI_VERSION >= NTDDI_WS03)
#ELSEIF %WINVER >= &H0502
%NUM_CM_PROB = %NUM_CM_PROB_V3
'#elif (NTDDI_VERSION >= NTDDI_WINXP)
#ELSEIF %WINVER >= &H0501
%NUM_CM_PROB = %NUM_CM_PROB_V2
'#elif (NTDDI_VERSION >= WIN2K)
#ELSEIF %WINVER >= &H0500
%NUM_CM_PROB = %NUM_CM_PROB_V1
#ENDIF

'//
'// Device Instance status flags, returned by call to CM_Get_DevInst_Status
'//
%DN_ROOT_ENUMERATED = &H00000001???   ' // Was enumerated by ROOT
%DN_DRIVER_LOADED   = &H00000002???   ' // Has Register_Device_Driver
%DN_ENUM_LOADED     = &H00000004???   ' // Has Register_Enumerator
%DN_STARTED         = &H00000008???   ' // Is currently configured
%DN_MANUAL          = &H00000010???   ' // Manually installed
%DN_NEED_TO_ENUM    = &H00000020???   ' // May need reenumeration
%DN_NOT_FIRST_TIME  = &H00000040???   ' // Has received a config
%DN_HARDWARE_ENUM   = &H00000080???   ' // Enum generates hardware ID
%DN_LIAR            = &H00000100???   ' // Lied about can reconfig once
%DN_HAS_MARK        = &H00000200???   ' // Not CM_Create_DevInst lately
%DN_HAS_PROBLEM     = &H00000400???   ' // Need device installer
%DN_FILTERED        = &H00000800???   ' // Is filtered
%DN_MOVED           = &H00001000???   ' // Has been moved
%DN_DISABLEABLE     = &H00002000???   ' // Can be disabled
%DN_REMOVABLE       = &H00004000???   ' // Can be removed
%DN_PRIVATE_PROBLEM = &H00008000???   ' // Has a private problem
%DN_MF_PARENT       = &H00010000???   ' // Multi function parent
%DN_MF_CHILD        = &H00020000???   ' // Multi function child
%DN_WILL_BE_REMOVED = &H00040000???   ' // DevInst is being removed

'//
'// Windows 4 OPK2 Flags
'//
%DN_NOT_FIRST_TIMEE  = &H00080000???   ' // S: Has received a config enumerate
%DN_STOP_FREE_RES    = &H00100000???   ' // S: When child is stopped, free resources
%DN_REBAL_CANDIDATE  = &H00200000???   ' // S: Don't skip during rebalance
%DN_BAD_PARTIAL      = &H00400000???   ' // S: This devnode's log_confs do not have same resources
%DN_NT_ENUMERATOR    = &H00800000???   ' // S: This devnode's is an NT enumerator
%DN_NT_DRIVER        = &H01000000???   ' // S: This devnode's is an NT driver
'//
'// Windows 4.1 Flags
'//
%DN_NEEDS_LOCKING    = &H02000000???   ' // S: Devnode need lock resume processing
%DN_ARM_WAKEUP       = &H04000000???   ' // S: Devnode can be the wakeup device
%DN_APM_ENUMERATOR   = &H08000000???   ' // S: APM aware enumerator
%DN_APM_DRIVER       = &H10000000???   ' // S: APM aware driver
%DN_SILENT_INSTALL   = &H20000000???   ' // S: Silent install
%DN_NO_SHOW_IN_DM    = &H40000000???   ' // S: No show in device manager
%DN_BOOT_LOG_PROB    = &H80000000???   ' // S: Had a problem during preassignment of boot log conf

'//
'// Windows NT Flags
'//
'// These are overloaded on top of unused Win 9X flags
'//
'//%DN_LIAR                       = &H00000100)            // Lied about can reconfig once

'#if (NTDDI_VERSION >= NTDDI_WINXP)

%DN_NEED_RESTART                 = %DN_LIAR                ' // System needs to be restarted for this Devnode to work properly
'// %DN_NOT_FIRST_TIME            = &H00000040)            // Has Register_Enumerator
%DN_DRIVER_BLOCKED               = %DN_NOT_FIRST_TIME      ' // One or more drivers are blocked from loading for this Devnode
'//%DN_MOVED                      = &H00001000)            // Has been moved
%DN_LEGACY_DRIVER                = %DN_MOVED               ' // This device is using a legacy driver
'//%DN_HAS_MARK                   = &H00000200)            // Not CM_Create_DevInst lately
%DN_CHILD_WITH_INVALID_ID        = %DN_HAS_MARK            ' // One or more children have invalid ID(s)

'#elif (NTDDI_VERSION >= NTDDI_WIN2K)

%DN_NEED_RESTART                 = &H00000100???           ' // System needs to be restarted for this Devnode to work properly

'#endif

%DN_CHANGEABLE_FLAGS = %DN_NOT_FIRST_TIME + _
                       %DN_HARDWARE_ENUM + _
                       %DN_HAS_MARK + _
                       %DN_DISABLEABLE + _
                       %DN_REMOVABLE + _
                       %DN_MF_CHILD + _
                       %DN_MF_PARENT + _
                       %DN_NOT_FIRST_TIMEE + _
                       %DN_STOP_FREE_RES + _
                       %DN_REBAL_CANDIDATE + _
                       %DN_NT_ENUMERATOR + _
                       %DN_NT_DRIVER + _
                       %DN_SILENT_INSTALL + _
                       %DN_NO_SHOW_IN_DM

'//
'// Logical configuration Priority values
'//
'// These priority values are used in user-mode calls to CM_Add_Empty_Log_Conf.
'// Drivers may also specify priority values for a given IO_RESOURCE_LIST
'// structure by including a ConfigData member union as the first
'// IO_RESOURCE_DESCRIPTOR in the IO_RESOURCE_LIST. In this case, the descriptor
'// type would be CmResourceTypeConfigData.
'//
%LCPRI_FORCECONFIG     = &H00000000???   ' // Coming from a forced config
%LCPRI_BOOTCONFIG      = &H00000001???   ' // Coming from a boot config
%LCPRI_DESIRED         = &H00002000???   ' // Preferable (better performance???
%LCPRI_NORMAL          = &H00003000???   ' // Workable (acceptable performance???
%LCPRI_LASTBESTCONFIG  = &H00003FFF???   ' // CM only--do not use
%LCPRI_SUBOPTIMAL      = &H00005000???   ' // Not desired, but will work
%LCPRI_LASTSOFTCONFIG  = &H00007FFF???   ' // CM only--do not use
%LCPRI_RESTART         = &H00008000???   ' // Need to restart
%LCPRI_REBOOT          = &H00009000???   ' // Need to reboot
%LCPRI_POWEROFF        = &H0000A000???   ' // Need to shutdown/power-off
%LCPRI_HARDRECONFIG    = &H0000C000???   ' // Need to change a jumper
%LCPRI_HARDWIRED       = &H0000E000???   ' // Cannot be changed
%LCPRI_IMPOSSIBLE      = &H0000F000???   ' // Impossible configuration
%LCPRI_DISABLED        = &H0000FFFF???   ' // Disabled configuration
%MAX_LCPRI             = &H0000FFFF???   ' // Maximum known LC Priority
