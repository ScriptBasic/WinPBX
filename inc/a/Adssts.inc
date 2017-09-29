' ########################################################################################
' Microsoft Windows
' File: Adssts.inc
' Contents: Status Codes for ADS objects
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADSSTS_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// printer status values
'//

%ADS_PRINTER_PAUSED                    = &H00000001
%ADS_PRINTER_PENDING_DELETION          = &H00000002
%ADS_PRINTER_ERROR                     = &H00000003
%ADS_PRINTER_PAPER_JAM                 = &H00000004
%ADS_PRINTER_PAPER_OUT                 = &H00000005
%ADS_PRINTER_MANUAL_FEED               = &H00000006
%ADS_PRINTER_PAPER_PROBLEM             = &H00000007
%ADS_PRINTER_OFFLINE                   = &H00000008
%ADS_PRINTER_IO_ACTIVE                 = &H00000100
%ADS_PRINTER_BUSY                      = &H00000200
%ADS_PRINTER_PRINTING                  = &H00000400
%ADS_PRINTER_OUTPUT_BIN_FULL           = &H00000800
%ADS_PRINTER_NOT_AVAILABLE             = &H00001000
%ADS_PRINTER_WAITING                   = &H00002000
%ADS_PRINTER_PROCESSING                = &H00004000
%ADS_PRINTER_INITIALIZING              = &H00008000
%ADS_PRINTER_WARMING_UP                = &H00010000
%ADS_PRINTER_TONER_LOW                 = &H00020000
%ADS_PRINTER_NO_TONER                  = &H00040000
%ADS_PRINTER_PAGE_PUNT                 = &H00080000
%ADS_PRINTER_USER_INTERVENTION         = &H00100000
%ADS_PRINTER_OUT_OF_MEMORY             = &H00200000
%ADS_PRINTER_DOOR_OPEN                 = &H00400000
%ADS_PRINTER_SERVER_UNKNOWN            = &H00800000
%ADS_PRINTER_POWER_SAVE                = &H01000000

'//
'// job status values
'//

%ADS_JOB_PAUSED                        = &H00000001
%ADS_JOB_ERROR                         = &H00000002
%ADS_JOB_DELETING                      = &H00000004
%ADS_JOB_SPOOLING                      = &H00000008
%ADS_JOB_PRINTING                      = &H00000010
%ADS_JOB_OFFLINE                       = &H00000020
%ADS_JOB_PAPEROUT                      = &H00000040
%ADS_JOB_PRINTED                       = &H00000080
%ADS_JOB_DELETED                       = &H00000100

'//
'// service status values
'//

%ADS_SERVICE_STOPPED                   = &H00000001
%ADS_SERVICE_START_PENDING             = &H00000002
%ADS_SERVICE_STOP_PENDING              = &H00000003
%ADS_SERVICE_RUNNING                   = &H00000004
%ADS_SERVICE_CONTINUE_PENDING          = &H00000005
%ADS_SERVICE_PAUSE_PENDING             = &H00000006
%ADS_SERVICE_PAUSED                    = &H00000007
%ADS_SERVICE_ERROR                     = &H00000008

'//---------------------------------------------------------------------

'//
'// Service Type Valid Values
'//

%ADS_SERVICE_OWN_PROCESS               = &H00000010
%ADS_SERVICE_SHARE_PROCESS             = &H00000020
%ADS_SERVICE_KERNEL_DRIVER             = &H00000001
%ADS_SERVICE_FILE_SYSTEM_DRIVER        = &H00000002

'//
'// Start Type Valid Values
'//

%ADS_SERVICE_BOOT_START          = %SERVICE_BOOT_START
%ADS_SERVICE_SYSTEM_START        = %SERVICE_SYSTEM_START
%ADS_SERVICE_AUTO_START          = %SERVICE_AUTO_START
%ADS_SERVICE_DEMAND_START        = %SERVICE_DEMAND_START
%ADS_SERVICE_DISABLED            = %SERVICE_DISABLED

'//
'// Error Control Values
'//

%ADS_SERVICE_ERROR_IGNORE         = 0
%ADS_SERVICE_ERROR_NORMAL         = 1
%ADS_SERVICE_ERROR_SEVERE         = 2
%ADS_SERVICE_ERROR_CRITICAL       = 3
