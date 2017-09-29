' ########################################################################################
' Microsoft Windows
' File: WinSpool.inc
' Contents: Header file for Print APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSPOOL_INC = 1

#INCLUDE ONCE "windows.inc"

'#IF %DEF(%WINUSER)
'   #INCLUDE ONCE "prsht.inc"
'#ENDIF

#IF NOT %DEF(%OSVERSION_MASK)

%OSVERSION_MASK      = &HFFFF0000???
%SPVERSION_MASK      = &H0000FF00???
%SUBVERSION_MASK     = &H000000FF???

'//
'// macros to extract various version fields from the NTDDI version
'//
'//
'// macros to extract various version fields from the NTDDI version
'//
'#define OSVER(Version) ((Version) & OSVERSION_MASK)
MACRO OSVER(Version) = Version AND %OSVERSION_MASK
'#define SPVER(Version) ( ((Version) & SPVERSION_MASK) >> 8)
MACRO SPVER(Version) = (Version AND %SPVERSION_MASK) \ &H100
'#define SUBVER(Version) ( ((Version) & SUBVERSION_MASK) )
MACRO SUBVER(Version) = Version AND %SUBVERSION_MASK

#ENDIF   ' // OSVERSION_MASK

' // Size = 16 bytes
TYPE PRINTER_INFO_1A DWORD
   flags        AS DWORD        ' DWORD
   pDescription AS ASCIIZ PTR   ' LPSTR
   pName        AS ASCIIZ PTR   ' LPSTR
   pComment     AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 16 bytes
TYPE PRINTER_INFO_1W DWORD
   flags        AS DWORD          ' DWORD
   pDescription AS WSTRINGZ PTR   ' LPWSTR
   pName        AS WSTRINGZ PTR   ' LPWSTR
   pComment     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_1 = PRINTER_INFO_1W
#ELSE
   MACRO PRINTER_INFO_1 = PRINTER_INFO_1A
#ENDIF

' // Size = 84 bytes
TYPE PRINTER_INFO_2A DWORD
   pServerName         AS ASCIIZ PTR                ' LPSTR
   pPrinterName        AS ASCIIZ PTR                ' LPSTR
   pShareName          AS ASCIIZ PTR                ' LPSTR
   pPortName           AS ASCIIZ PTR                ' LPSTR
   pDriverName         AS ASCIIZ PTR                ' LPSTR
   pComment            AS ASCIIZ PTR                ' LPSTR
   pLocation           AS ASCIIZ PTR                ' LPSTR
   pDevMode            AS DEVMODE PTR               ' LPDEVMODEA
   pSepFile            AS ASCIIZ PTR                ' LPSTR
   pPrintProcessor     AS ASCIIZ PTR                ' LPSTR
   pDatatype           AS ASCIIZ PTR                ' LPSTR
   pParameters         AS ASCIIZ PTR                ' LPSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Attributes          AS DWORD                     ' DWORD
   Priority            AS DWORD                     ' DWORD
   DefaultPriority     AS DWORD                     ' DWORD
   StartTime           AS DWORD                     ' DWORD
   UntilTime           AS DWORD                     ' DWORD
   Status              AS DWORD                     ' DWORD
   cJobs               AS DWORD                     ' DWORD
   AveragePPM          AS DWORD                     ' DWORD
END TYPE

' // Size = 84 bytes
TYPE PRINTER_INFO_2W DWORD
   pServerName         AS WSTRINGZ PTR              ' LPWSTR
   pPrinterName        AS WSTRINGZ PTR              ' LPWSTR
   pShareName          AS WSTRINGZ PTR              ' LPWSTR
   pPortName           AS WSTRINGZ PTR              ' LPWSTR
   pDriverName         AS WSTRINGZ PTR              ' LPWSTR
   pComment            AS WSTRINGZ PTR              ' LPWSTR
   pLocation           AS WSTRINGZ PTR              ' LPWSTR
   pDevMode            AS DEVMODEW PTR              ' LPDEVMODEW
   pSepFile            AS WSTRINGZ PTR              ' LPWSTR
   pPrintProcessor     AS WSTRINGZ PTR              ' LPWSTR
   pDatatype           AS WSTRINGZ PTR              ' LPWSTR
   pParameters         AS WSTRINGZ PTR              ' LPWSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Attributes          AS DWORD                     ' DWORD
   Priority            AS DWORD                     ' DWORD
   DefaultPriority     AS DWORD                     ' DWORD
   StartTime           AS DWORD                     ' DWORD
   UntilTime           AS DWORD                     ' DWORD
   Status              AS DWORD                     ' DWORD
   cJobs               AS DWORD                     ' DWORD
   AveragePPM          AS DWORD                     ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_2 = PRINTER_INFO_2W
#ELSE
   MACRO PRINTER_INFO_2 = PRINTER_INFO_2A
#ENDIF

' // Size = 4 bytes
TYPE PRINTER_INFO_3 DWORD
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR
END TYPE

' // Size = 12 bytes
TYPE PRINTER_INFO_4A DWORD
   pPrinterName AS ASCIIZ PTR   ' LPSTR
   pServerName  AS ASCIIZ PTR   ' LPSTR
   Attributes   AS DWORD        ' DWORD
END TYPE

' // Size = 12 bytes
TYPE PRINTER_INFO_4W DWORD
   pPrinterName AS WSTRINGZ PTR   ' LPWSTR
   pServerName  AS WSTRINGZ PTR   ' LPWSTR
   Attributes   AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_4 = PRINTER_INFO_4W
#ELSE
   MACRO PRINTER_INFO_4 = PRINTER_INFO_4A
#ENDIF

' // Size = 20 bytes
TYPE PRINTER_INFO_5A DWORD
   pPrinterName             AS ASCIIZ PTR   ' LPSTR
   pPortName                AS ASCIIZ PTR   ' LPSTR
   Attributes               AS DWORD        ' DWORD
   DeviceNotSelectedTimeout AS DWORD        ' DWORD
   TransmissionRetryTimeout AS DWORD        ' DWORD
END TYPE

' // Size = 20 bytes
TYPE PRINTER_INFO_5W DWORD
   pPrinterName             AS WSTRINGZ PTR   ' LPWSTR
   pPortName                AS WSTRINGZ PTR   ' LPWSTR
   Attributes               AS DWORD          ' DWORD
   DeviceNotSelectedTimeout AS DWORD          ' DWORD
   TransmissionRetryTimeout AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_5 = PRINTER_INFO_5W
#ELSE
   MACRO PRINTER_INFO_5 = PRINTER_INFO_5A
#ENDIF

' // Size = 4 bytes
TYPE PRINTER_INFO_6 DWORD
   dwStatus AS DWORD
END TYPE

' // Size = 8 bytes
TYPE PRINTER_INFO_7A DWORD
   pszObjectGUID AS ASCIIZ PTR   ' LPSTR
   dwAction      AS DWORD        ' DWORD
END TYPE

' // Size = 8 bytes
TYPE PRINTER_INFO_7W DWORD
   pszObjectGUID AS WSTRINGZ PTR   ' LPWSTR
   dwAction      AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_7 = PRINTER_INFO_7W
#ELSE
   MACRO PRINTER_INFO_7 = PRINTER_INFO_7A
#ENDIF

%DSPRINT_PUBLISH         = &H00000001???
%DSPRINT_UPDATE          = &H00000002???
%DSPRINT_UNPUBLISH       = &H00000004???
%DSPRINT_REPUBLISH       = &H00000008???
%DSPRINT_PENDING         = &H80000000???

' // Size = 4 bytes
TYPE PRINTER_INFO_8A DWORD
   pDevMode AS DEVMODE PTR
END TYPE

' // Size = 4 bytes
TYPE PRINTER_INFO_8W DWORD
   pDevMode AS DEVMODEW PTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_8 = PRINTER_INFO_8W
#ELSE
   MACRO PRINTER_INFO_8 = PRINTER_INFO_8A
#ENDIF

' // Size = 4 bytes
TYPE PRINTER_INFO_9A DWORD
   pDevMode AS DEVMODE PTR
END TYPE

' // Size = 4 bytes
TYPE PRINTER_INFO_9W DWORD
   pDevMode AS DEVMODEW PTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_INFO_9 = PRINTER_INFO_9W
#ELSE
   MACRO PRINTER_INFO_9 = PRINTER_INFO_9A
#ENDIF

%PRINTER_CONTROL_PAUSE               = 1???
%PRINTER_CONTROL_RESUME              = 2???
%PRINTER_CONTROL_PURGE               = 3???
%PRINTER_CONTROL_SET_STATUS          = 4???

%PRINTER_STATUS_PAUSED               = &H00000001???
%PRINTER_STATUS_ERROR                = &H00000002???
%PRINTER_STATUS_PENDING_DELETION     = &H00000004???
%PRINTER_STATUS_PAPER_JAM            = &H00000008???
%PRINTER_STATUS_PAPER_OUT            = &H00000010???
%PRINTER_STATUS_MANUAL_FEED          = &H00000020???
%PRINTER_STATUS_PAPER_PROBLEM        = &H00000040???
%PRINTER_STATUS_OFFLINE              = &H00000080???
%PRINTER_STATUS_IO_ACTIVE            = &H00000100???
%PRINTER_STATUS_BUSY                 = &H00000200???
%PRINTER_STATUS_PRINTING             = &H00000400???
%PRINTER_STATUS_OUTPUT_BIN_FULL      = &H00000800???
%PRINTER_STATUS_NOT_AVAILABLE        = &H00001000???
%PRINTER_STATUS_WAITING              = &H00002000???
%PRINTER_STATUS_PROCESSING           = &H00004000???
%PRINTER_STATUS_INITIALIZING         = &H00008000???
%PRINTER_STATUS_WARMING_UP           = &H00010000???
%PRINTER_STATUS_TONER_LOW            = &H00020000???
%PRINTER_STATUS_NO_TONER             = &H00040000???
%PRINTER_STATUS_PAGE_PUNT            = &H00080000???
%PRINTER_STATUS_USER_INTERVENTION    = &H00100000???
%PRINTER_STATUS_OUT_OF_MEMORY        = &H00200000???
%PRINTER_STATUS_DOOR_OPEN            = &H00400000???
%PRINTER_STATUS_SERVER_UNKNOWN       = &H00800000???
%PRINTER_STATUS_POWER_SAVE           = &H01000000???
%PRINTER_STATUS_SERVER_OFFLINE       = &H02000000???
%PRINTER_STATUS_DRIVER_UPDATE_NEEDED = &H04000000???

%PRINTER_ATTRIBUTE_QUEUED            = &H00000001???
%PRINTER_ATTRIBUTE_DIRECT            = &H00000002???
%PRINTER_ATTRIBUTE_DEFAULT           = &H00000004???
%PRINTER_ATTRIBUTE_SHARED            = &H00000008???
%PRINTER_ATTRIBUTE_NETWORK           = &H00000010???
%PRINTER_ATTRIBUTE_HIDDEN            = &H00000020???
%PRINTER_ATTRIBUTE_LOCAL             = &H00000040???

%PRINTER_ATTRIBUTE_ENABLE_DEVQ       = &H00000080???
%PRINTER_ATTRIBUTE_KEEPPRINTEDJOBS   = &H00000100???
%PRINTER_ATTRIBUTE_DO_COMPLETE_FIRST = &H00000200???

%PRINTER_ATTRIBUTE_WORK_OFFLINE      = &H00000400???
%PRINTER_ATTRIBUTE_ENABLE_BIDI       = &H00000800???
%PRINTER_ATTRIBUTE_RAW_ONLY          = &H00001000???
%PRINTER_ATTRIBUTE_PUBLISHED         = &H00002000???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%PRINTER_ATTRIBUTE_FAX               = &H00004000???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)
'#if ((NTDDI_VERSION >= NTDDI_WS03) ||\
'     ((OSVER(NTDDI_VERSION) == NTDDI_WIN2K) && (SPVER(NTDDI_VERSION) >= 4)))
%PRINTER_ATTRIBUTE_TS                = &H00008000???
'#endif // ((NTDDI_VERSION >= NTDDI_WS03) ||\ ...

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' //
' // The printer attribute pushed xxx bits below are used by the
' // pushing printer connection code to keep track of the type
' // of printer connection.  These bits are per user resources
' // hence the local print provider has no knowledge about these
' // bit and will not accepts them.  The remote print provider
' // is responsible for storeing and persisting these bits.
' //
%PRINTER_ATTRIBUTE_PUSHED_USER       = &H00020000???
%PRINTER_ATTRIBUTE_PUSHED_MACHINE    = &H00040000???
%PRINTER_ATTRIBUTE_MACHINE           = &H00080000???

%PRINTER_ATTRIBUTE_FRIENDLY_NAME     = &H00100000???

' //
' // If the redirected TS printer is installed with generic
' // TS printer driver (TSPRINT.dll) then this attribute is set
' // by the UMRDP service and passed on to the spooler
' //
%PRINTER_ATTRIBUTE_TS_GENERIC_DRIVER = &H00200000???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%NO_PRIORITY                         = 0
%MAX_PRIORITY                        = 99
%MIN_PRIORITY                        = 1
%DEF_PRIORITY                        = 1

' // Size = 64 bytes
TYPE JOB_INFO_1A DWORD
   JobId        AS DWORD        ' DWORD
   pPrinterName AS ASCIIZ PTR   ' LPSTR
   pMachineName AS ASCIIZ PTR   ' LPSTR
   pUserName    AS ASCIIZ PTR   ' LPSTR
   pDocument    AS ASCIIZ PTR   ' LPSTR
   pDatatype    AS ASCIIZ PTR   ' LPSTR
   pStatus      AS ASCIIZ PTR   ' LPSTR
   Status       AS DWORD        ' DWORD
   Priority     AS DWORD        ' DWORD
   Position     AS DWORD        ' DWORD
   TotalPages   AS DWORD        ' DWORD
   PagesPrinted AS DWORD        ' DWORD
   Submitted    AS SYSTEMTIME   ' SYSTEMTIME
END TYPE

' // Size = 64 bytes
TYPE JOB_INFO_1W DWORD
   JobId        AS DWORD          ' DWORD
   pPrinterName AS WSTRINGZ PTR   ' LPWSTR
   pMachineName AS WSTRINGZ PTR   ' LPWSTR
   pUserName    AS WSTRINGZ PTR   ' LPWSTR
   pDocument    AS WSTRINGZ PTR   ' LPWSTR
   pDatatype    AS WSTRINGZ PTR   ' LPWSTR
   pStatus      AS WSTRINGZ PTR   ' LPWSTR
   Status       AS DWORD          ' DWORD
   Priority     AS DWORD          ' DWORD
   Position     AS DWORD          ' DWORD
   TotalPages   AS DWORD          ' DWORD
   PagesPrinted AS DWORD          ' DWORD
   Submitted    AS SYSTEMTIME     ' SYSTEMTIME
END TYPE

#IF %DEF(%UNICODE)
   MACRO JOB_INFO_1 = JOB_INFO_1W
#ELSE
   MACRO JOB_INFO_1 = JOB_INFO_1A
#ENDIF

' // Size = 104 bytes
TYPE JOB_INFO_2A DWORD
   JobId               AS DWORD                     ' DWORD
   pPrinterName        AS ASCIIZ PTR                ' LPSTR
   pMachineName        AS ASCIIZ PTR                ' LPSTR
   pUserName           AS ASCIIZ PTR                ' LPSTR
   pDocument           AS ASCIIZ PTR                ' LPSTR
   pNotifyName         AS ASCIIZ PTR                ' LPSTR
   pDatatype           AS ASCIIZ PTR                ' LPSTR
   pPrintProcessor     AS ASCIIZ PTR                ' LPSTR
   pParameters         AS ASCIIZ PTR                ' LPSTR
   pDriverName         AS ASCIIZ PTR                ' LPSTR
   pDevMode            AS DEVMODE PTR               ' LPDEVMODEA
   pStatus             AS ASCIIZ PTR                ' LPSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Status              AS DWORD                     ' DWORD
   Priority            AS DWORD                     ' DWORD
   Position            AS DWORD                     ' DWORD
   StartTime           AS DWORD                     ' DWORD
   UntilTime           AS DWORD                     ' DWORD
   TotalPages          AS DWORD                     ' DWORD
   Size                AS DWORD                     ' DWORD
   Submitted           AS SYSTEMTIME                ' SYSTEMTIME
   Time                AS DWORD                     ' DWORD
   PagesPrinted        AS DWORD                     ' DWORD
END TYPE

' // Size = 104 bytes
TYPE JOB_INFO_2W DWORD
   JobId               AS DWORD                     ' DWORD
   pPrinterName        AS WSTRINGZ PTR              ' LPWSTR
   pMachineName        AS WSTRINGZ PTR              ' LPWSTR
   pUserName           AS WSTRINGZ PTR              ' LPWSTR
   pDocument           AS WSTRINGZ PTR              ' LPWSTR
   pNotifyName         AS WSTRINGZ PTR              ' LPWSTR
   pDatatype           AS WSTRINGZ PTR              ' LPWSTR
   pPrintProcessor     AS WSTRINGZ PTR              ' LPWSTR
   pParameters         AS WSTRINGZ PTR              ' LPWSTR
   pDriverName         AS WSTRINGZ PTR              ' LPWSTR
   pDevMode            AS DEVMODEW PTR              ' LPDEVMODEW
   pStatus             AS WSTRINGZ PTR              ' LPWSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Status              AS DWORD                     ' DWORD
   Priority            AS DWORD                     ' DWORD
   Position            AS DWORD                     ' DWORD
   StartTime           AS DWORD                     ' DWORD
   UntilTime           AS DWORD                     ' DWORD
   TotalPages          AS DWORD                     ' DWORD
   Size                AS DWORD                     ' DWORD
   Submitted           AS SYSTEMTIME                ' SYSTEMTIME
   Time                AS DWORD                     ' DWORD
   PagesPrinted        AS DWORD                     ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO JOB_INFO_2 = JOB_INFO_2W
#ELSE
   MACRO JOB_INFO_2 = JOB_INFO_2A
#ENDIF

' // Size = 12 bytes
TYPE JOB_INFO_3 DWORD
   JobId     AS DWORD
   NextJobId AS DWORD
   Reserved  AS DWORD
END TYPE

' // Size = 108 bytes
TYPE JOB_INFO_4A DWORD
   JobId               AS DWORD         ' DWORD
   pPrinterName        AS ASCIIZ PTR    ' LPSTR
   pMachineName        AS ASCIIZ PTR    ' LPSTR
   pUserName           AS ASCIIZ PTR    ' LPSTR
   pDocument           AS ASCIIZ PTR    ' LPSTR
   pNotifyName         AS ASCIIZ PTR    ' LPSTR
   pDatatype           AS ASCIIZ PTR    ' LPSTR
   pPrintProcessor     AS ASCIIZ PTR    ' LPSTR
   pParameters         AS ASCIIZ PTR    ' LPSTR
   pDriverName         AS ASCIIZ PTR    ' LPSTR
   pDevMode            AS DEVMODE PTR   ' LPDEVMODEA
   pStatus             AS ASCIIZ PTR    ' LPSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Status              AS DWORD         ' DWORD
   Priority            AS DWORD         ' DWORD
   Position            AS DWORD         ' DWORD
   StartTime           AS DWORD         ' DWORD
   UntilTime           AS DWORD         ' DWORD
   TotalPages          AS DWORD         ' DWORD
   Size                AS DWORD         ' DWORD
   Submitted           AS SYSTEMTIME    ' SYSTEMTIME
   Time                AS DWORD         ' DWORD
   PagesPrinted        AS DWORD         ' DWORD
   SizeHigh            AS LONG          ' LONG
END TYPE

' // Size = 108 bytes
TYPE JOB_INFO_4W DWORD
   JobId               AS DWORD         ' DWORD
   pPrinterName        AS WSTRINGZ PTR  ' LPWSTR
   pMachineName        AS WSTRINGZ PTR  ' LPWSTR
   pUserName           AS WSTRINGZ PTR  ' LPWSTR
   pDocument           AS WSTRINGZ PTR  ' LPWSTR
   pNotifyName         AS WSTRINGZ PTR  ' LPWSTR
   pDatatype           AS WSTRINGZ PTR  ' LPWSTR
   pPrintProcessor     AS WSTRINGZ PTR  ' LPWSTR
   pParameters         AS WSTRINGZ PTR  ' LPWSTR
   pDriverName         AS WSTRINGZ PTR  ' LPWSTR
   pDevMode            AS DEVMODEW PTR  ' LPDEVMODEW
   pStatus             AS WSTRINGZ PTR  ' LPWSTR
   pSecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
   Status              AS DWORD         ' DWORD
   Priority            AS DWORD         ' DWORD
   Position            AS DWORD         ' DWORD
   StartTime           AS DWORD         ' DWORD
   UntilTime           AS DWORD         ' DWORD
   TotalPages          AS DWORD         ' DWORD
   Size                AS DWORD         ' DWORD
   Submitted           AS SYSTEMTIME    ' SYSTEMTIME
   Time                AS DWORD         ' DWORD
   PagesPrinted        AS DWORD         ' DWORD
   SizeHigh            AS LONG          ' LONG
END TYPE

#IF %DEF(%UNICODE)
   MACRO JOB_INFO_4 = JOB_INFO_4W
#ELSE
   MACRO JOB_INFO_4 = JOB_INFO_4A
#ENDIF

%JOB_CONTROL_PAUSE             = 1???
%JOB_CONTROL_RESUME            = 2???
%JOB_CONTROL_CANCEL            = 3???
%JOB_CONTROL_RESTART           = 4???
%JOB_CONTROL_DELETE            = 5???
%JOB_CONTROL_SENT_TO_PRINTER   = 6???
%JOB_CONTROL_LAST_PAGE_EJECTED = 7???

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%JOB_CONTROL_RETAIN            = 8???
%JOB_CONTROL_RELEASE           = 9???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%JOB_STATUS_PAUSED             = &H00000001???
%JOB_STATUS_ERROR              = &H00000002???
%JOB_STATUS_DELETING           = &H00000004???
%JOB_STATUS_SPOOLING           = &H00000008???
%JOB_STATUS_PRINTING           = &H00000010???
%JOB_STATUS_OFFLINE            = &H00000020???
%JOB_STATUS_PAPEROUT           = &H00000040???
%JOB_STATUS_PRINTED            = &H00000080???
%JOB_STATUS_DELETED            = &H00000100???
%JOB_STATUS_BLOCKED_DEVQ       = &H00000200???
%JOB_STATUS_USER_INTERVENTION  = &H00000400???
%JOB_STATUS_RESTART            = &H00000800???

'#if (NTDDI_VERSION >= NTDDI_WINXP)
%JOB_STATUS_COMPLETE           = &H00001000???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%JOB_STATUS_RETAINED           = &H00002000???
%JOB_STATUS_RENDERING_LOCALLY  = &H00004000???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%JOB_POSITION_UNSPECIFIED      = 0

' // Size = 8 bytes
TYPE ADDJOB_INFO_1A DWORD
   Path  AS ASCIIZ PTR   ' LPSTR
   JobId AS DWORD        ' DWORD
END TYPE

' // Size = 8 bytes
TYPE ADDJOB_INFO_1W DWORD
   Path  AS WSTRINGZ PTR   ' LPWSTR
   JobId AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO ADDJOB_INFO_1 = ADDJOB_INFO_1W
#ELSE
   MACRO ADDJOB_INFO_1 = ADDJOB_INFO_1A
#ENDIF

'typedef struct _DRIVER_INFO_1A {
'    LPSTR     pName;              // QMS 810
'} DRIVER_INFO_1A, *PDRIVER_INFO_1A, *LPDRIVER_INFO_1A;

' // Size = 4 bytes
TYPE DRIVER_INFO_1A DWORD
   pName AS ASCIIZ PTR
END TYPE

' // Size = 4 bytes
TYPE DRIVER_INFO_1W DWORD
   pName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_1 = DRIVER_INFO_1W
#ELSE
   MACRO DRIVER_INFO_1 = DRIVER_INFO_1A
#ENDIF

' // Size = 24 bytes
TYPE DRIVER_INFO_2A DWORD
   cVersion     AS DWORD        ' DWORD
   pName        AS ASCIIZ PTR   ' LPSTR
   pEnvironment AS ASCIIZ PTR   ' LPSTR
   pDriverPath  AS ASCIIZ PTR   ' LPSTR
   pDataFile    AS ASCIIZ PTR   ' LPSTR
   pConfigFile  AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 24 bytes
TYPE DRIVER_INFO_2W DWORD
   cVersion     AS DWORD          ' DWORD
   pName        AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment AS WSTRINGZ PTR   ' LPWSTR
   pDriverPath  AS WSTRINGZ PTR   ' LPWSTR
   pDataFile    AS WSTRINGZ PTR   ' LPWSTR
   pConfigFile  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_2 = DRIVER_INFO_2W
#ELSE
   MACRO DRIVER_INFO_2 = DRIVER_INFO_2A
#ENDIF

' // Size = 40 bytes
TYPE DRIVER_INFO_3A DWORD
   cVersion         AS DWORD        ' DWORD
   pName            AS ASCIIZ PTR   ' LPSTR
   pEnvironment     AS ASCIIZ PTR   ' LPSTR
   pDriverPath      AS ASCIIZ PTR   ' LPSTR
   pDataFile        AS ASCIIZ PTR   ' LPSTR
   pConfigFile      AS ASCIIZ PTR   ' LPSTR
   pHelpFile        AS ASCIIZ PTR   ' LPSTR
   pDependentFiles  AS ASCIIZ PTR   ' LPSTR
   pMonitorName     AS ASCIIZ PTR   ' LPSTR
   pDefaultDataType AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 40 bytes
TYPE DRIVER_INFO_3W DWORD
   cVersion         AS DWORD          ' DWORD
   pName            AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment     AS WSTRINGZ PTR   ' LPWSTR
   pDriverPath      AS WSTRINGZ PTR   ' LPWSTR
   pDataFile        AS WSTRINGZ PTR   ' LPWSTR
   pConfigFile      AS WSTRINGZ PTR   ' LPWSTR
   pHelpFile        AS WSTRINGZ PTR   ' LPWSTR
   pDependentFiles  AS WSTRINGZ PTR   ' LPWSTR
   pMonitorName     AS WSTRINGZ PTR   ' LPWSTR
   pDefaultDataType AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_3 = DRIVER_INFO_3W
#ELSE
   MACRO DRIVER_INFO_3 = DRIVER_INFO_3A
#ENDIF

' // Size = 44 bytes
TYPE DRIVER_INFO_4A DWORD
   cVersion          AS DWORD        ' DWORD
   pName             AS ASCIIZ PTR   ' LPSTR
   pEnvironment      AS ASCIIZ PTR   ' LPSTR
   pDriverPath       AS ASCIIZ PTR   ' LPSTR
   pDataFile         AS ASCIIZ PTR   ' LPSTR
   pConfigFile       AS ASCIIZ PTR   ' LPSTR
   pHelpFile         AS ASCIIZ PTR   ' LPSTR
   pDependentFiles   AS ASCIIZ PTR   ' LPSTR
   pMonitorName      AS ASCIIZ PTR   ' LPSTR
   pDefaultDataType  AS ASCIIZ PTR   ' LPSTR
   pszzPreviousNames AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 44 bytes
TYPE DRIVER_INFO_4W DWORD
   cVersion          AS DWORD          ' DWORD
   pName             AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment      AS WSTRINGZ PTR   ' LPWSTR
   pDriverPath       AS WSTRINGZ PTR   ' LPWSTR
   pDataFile         AS WSTRINGZ PTR   ' LPWSTR
   pConfigFile       AS WSTRINGZ PTR   ' LPWSTR
   pHelpFile         AS WSTRINGZ PTR   ' LPWSTR
   pDependentFiles   AS WSTRINGZ PTR   ' LPWSTR
   pMonitorName      AS WSTRINGZ PTR   ' LPWSTR
   pDefaultDataType  AS WSTRINGZ PTR   ' LPWSTR
   pszzPreviousNames AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_4 = DRIVER_INFO_4W
#ELSE
   MACRO DRIVER_INFO_4 = DRIVER_INFO_4A
#ENDIF

' // Size = 36 bytes
TYPE DRIVER_INFO_5A DWORD
   cVersion           AS DWORD        ' DWORD
   pName              AS ASCIIZ PTR   ' LPSTR
   pEnvironment       AS ASCIIZ PTR   ' LPSTR
   pDriverPath        AS ASCIIZ PTR   ' LPSTR
   pDataFile          AS ASCIIZ PTR   ' LPSTR
   pConfigFile        AS ASCIIZ PTR   ' LPSTR
   dwDriverAttributes AS DWORD        ' DWORD
   dwConfigVersion    AS DWORD        ' DWORD
   dwDriverVersion    AS DWORD        ' DWORD
END TYPE

' // Size = 36 bytes
TYPE DRIVER_INFO_5W DWORD
   cVersion           AS DWORD          ' DWORD
   pName              AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment       AS WSTRINGZ PTR   ' LPWSTR
   pDriverPath        AS WSTRINGZ PTR   ' LPWSTR
   pDataFile          AS WSTRINGZ PTR   ' LPWSTR
   pConfigFile        AS WSTRINGZ PTR   ' LPWSTR
   dwDriverAttributes AS DWORD          ' DWORD
   dwConfigVersion    AS DWORD          ' DWORD
   dwDriverVersion    AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_5 = DRIVER_INFO_5W
#ELSE
   MACRO DRIVER_INFO_5 = DRIVER_INFO_5A
#ENDIF

' // Size = 80 bytes
TYPE DRIVER_INFO_6A QWORD FILL   ' Must be 8 byte aligned
   cVersion          AS DWORD        ' DWORD
   pName             AS ASCIIZ PTR   ' LPSTR
   pEnvironment      AS ASCIIZ PTR   ' LPSTR
   pDriverPath       AS ASCIIZ PTR   ' LPSTR
   pDataFile         AS ASCIIZ PTR   ' LPSTR
   pConfigFile       AS ASCIIZ PTR   ' LPSTR
   pHelpFile         AS ASCIIZ PTR   ' LPSTR
   pDependentFiles   AS ASCIIZ PTR   ' LPSTR
   pMonitorName      AS ASCIIZ PTR   ' LPSTR
   pDefaultDataType  AS ASCIIZ PTR   ' LPSTR
   pszzPreviousNames AS ASCIIZ PTR   ' LPSTR
   ftDriverDate      AS FILETIME     ' FILETIME
   dwlDriverVersion  AS QUAD         ' DWORDLONG
   pszMfgName        AS ASCIIZ PTR   ' LPSTR
   pszOEMUrl         AS ASCIIZ PTR   ' LPSTR
   pszHardwareID     AS ASCIIZ PTR   ' LPSTR
   pszProvider       AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 80 bytes
TYPE DRIVER_INFO_6W QWORD FILL   ' Must be 8 byte aligned
   cVersion          AS DWORD          ' DWORD
   pName             AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment      AS WSTRINGZ PTR   ' LPWSTR
   pDriverPath       AS WSTRINGZ PTR   ' LPWSTR
   pDataFile         AS WSTRINGZ PTR   ' LPWSTR
   pConfigFile       AS WSTRINGZ PTR   ' LPWSTR
   pHelpFile         AS WSTRINGZ PTR   ' LPWSTR
   pDependentFiles   AS WSTRINGZ PTR   ' LPWSTR
   pMonitorName      AS WSTRINGZ PTR   ' LPWSTR
   pDefaultDataType  AS WSTRINGZ PTR   ' LPWSTR
   pszzPreviousNames AS WSTRINGZ PTR   ' LPWSTR
   ftDriverDate      AS FILETIME       ' FILETIME
   dwlDriverVersion  AS QUAD           ' DWORDLONG
   pszMfgName        AS WSTRINGZ PTR   ' LPWSTR
   pszOEMUrl         AS WSTRINGZ PTR   ' LPWSTR
   pszHardwareID     AS WSTRINGZ PTR   ' LPWSTR
   pszProvider       AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_6 = DRIVER_INFO_6W
#ELSE
   MACRO DRIVER_INFO_6 = DRIVER_INFO_6A
#ENDIF

%PRINTER_DRIVER_PACKAGE_AWARE   = &H00000001???
%PRINTER_DRIVER_SANDBOX_ENABLED = &H00000004???

' // Size = 120 bytes
TYPE DRIVER_INFO_8A QWORD FILL   ' Must be 8 byte aligned
   cVersion                    AS DWORD          ' DWORD
   pName                       AS ASCIIZ PTR     ' LPSTR // QMS 810
   pEnvironment                AS ASCIIZ PTR     ' LPSTR // Win32 x86
   pDriverPath                 AS ASCIIZ PTR     ' LPSTR // c:\drivers\pscript.dll
   pDataFile                   AS ASCIIZ PTR     ' LPSTR // c:\drivers\QMS810.PPD
   pConfigFile                 AS ASCIIZ PTR     ' LPSTR // c:\drivers\PSCRPTUI.DLL
   pHelpFile                   AS ASCIIZ PTR     ' LPSTR // c:\drivers\PSCRPTUI.HLP
   pDependentFiles             AS ASCIIZ PTR     ' LPSTR // PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
   pMonitorName                AS ASCIIZ PTR     ' LPSTR // "PJL monitor"
   pDefaultDataType            AS ASCIIZ PTR     ' LPSTR // "EMF"
   pszzPreviousNames           AS ASCIIZ PTR     ' LPSTR  // "OldName1\0OldName2\0\0
   ftDriverDate                AS FILETIME       ' FILETIME
   dwlDriverVersion            AS QUAD           ' DWORDLONG
   pszMfgName                  AS ASCIIZ PTR     ' LPSTR
   pszOEMUrl                   AS ASCIIZ PTR     ' LPSTR
   pszHardwareID               AS ASCIIZ PTR     ' LPSTR
   pszProvider                 AS ASCIIZ PTR     ' LPSTR
   pszPrintProcessor           AS ASCIIZ PTR     ' LPSTR
   pszVendorSetup              AS ASCIIZ PTR     ' LPSTR
   pszzColorProfiles           AS ASCIIZ PTR     ' LPSTR
   pszInfPath                  AS ASCIIZ PTR     ' LPSTR
   dwPrinterDriverAttributes   AS DWORD          ' DWORD
   pszzCoreDriverDependencies  AS ASCIIZ PTR     ' LPSTR
   ftMinInboxDriverVerDate     AS FILETIME       ' FILETIME
   dwlMinInboxDriverVerVersion AS QUAD           ' DWORDLONG
END TYPE

' // Size = 120 bytes
TYPE DRIVER_INFO_8W QWORD FILL   ' Must be 8 byte aligned
   cVersion                    AS DWORD          ' DWORD
   pName                       AS WSTRINGZ PTR   ' LPWSTR // QMS 810
   pEnvironment                AS WSTRINGZ PTR   ' LPWSTR // Win32 x86
   pDriverPath                 AS WSTRINGZ PTR   ' LPWSTR // c:\drivers\pscript.dll
   pDataFile                   AS WSTRINGZ PTR   ' LPWSTR // c:\drivers\QMS810.PPD
   pConfigFile                 AS WSTRINGZ PTR   ' LPWSTR // c:\drivers\PSCRPTUI.DLL
   pHelpFile                   AS WSTRINGZ PTR   ' LPWSTR // c:\drivers\PSCRPTUI.HLP
   pDependentFiles             AS WSTRINGZ PTR   ' LPWSTR // PSCRIPT.DLL\0QMS810.PPD\0PSCRIPTUI.DLL\0PSCRIPTUI.HLP\0PSTEST.TXT\0\0
   pMonitorName                AS WSTRINGZ PTR   ' LPWSTR // "PJL monitor"
   pDefaultDataType            AS WSTRINGZ PTR   ' LPWSTR // "EMF"
   pszzPreviousNames           AS WSTRINGZ PTR   ' LPWSTR  // "OldName1\0OldName2\0\0
   ftDriverDate                AS FILETIME       ' FILETIME
   dwlDriverVersion            AS QUAD           ' DWORDLONG
   pszMfgName                  AS WSTRINGZ PTR   ' LPWSTR
   pszOEMUrl                   AS WSTRINGZ PTR   ' LPWSTR
   pszHardwareID               AS WSTRINGZ PTR   ' LPWSTR
   pszProvider                 AS WSTRINGZ PTR   ' LPWSTR
   pszPrintProcessor           AS WSTRINGZ PTR   ' LPWSTR
   pszVendorSetup              AS WSTRINGZ PTR   ' LPWSTR
   pszzColorProfiles           AS WSTRINGZ PTR   ' LPWSTR
   pszInfPath                  AS WSTRINGZ PTR   ' LPWSTR
   dwPrinterDriverAttributes   AS DWORD          ' DWORD
   pszzCoreDriverDependencies  AS WSTRINGZ PTR   ' LPWSTR
   ftMinInboxDriverVerDate     AS FILETIME       ' FILETIME
   dwlMinInboxDriverVerVersion AS QUAD           ' DWORDLONG
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRIVER_INFO_8 = DRIVER_INFO_8W
#ELSE
   MACRO DRIVER_INFO_8 = DRIVER_INFO_8A
#ENDIF

'// FLAGS for dwDriverAttributes
%DRIVER_KERNELMODE                = &H00000001???
%DRIVER_USERMODE                  = &H00000002???

'// FLAGS for DeletePrinterDriverEx.
%DPD_DELETE_UNUSED_FILES          = &H00000001???
%DPD_DELETE_SPECIFIC_VERSION      = &H00000002???
%DPD_DELETE_ALL_FILES             = &H00000004???

'// FLAGS for AddPrinterDriverEx.
%APD_STRICT_UPGRADE               = &H00000001???
%APD_STRICT_DOWNGRADE             = &H00000002???
%APD_COPY_ALL_FILES               = &H00000004???
%APD_COPY_NEW_FILES               = &H00000008???

'#if (NTDDI_VERSION >= NTDDI_WINXP)
%APD_COPY_FROM_DIRECTORY          = &H00000010???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'// String for EnumPrinterDrivers. Used by Windows Update

' // Size = 12 bytes
TYPE DOC_INFO_1A DWORD
   pDocName    AS ASCIIZ PTR   ' LPSTR
   pOutputFile AS ASCIIZ PTR   ' LPSTR
   pDatatype   AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE DOC_INFO_1W DWORD
   pDocName    AS WSTRINGZ PTR   ' LPWSTR
   pOutputFile AS WSTRINGZ PTR   ' LPWSTR
   pDatatype   AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DOC_INFO_1 = DOC_INFO_1W
#ELSE
   MACRO DOC_INFO_1 = DOC_INFO_1A
#ENDIF

' // Size = 32 bytes
TYPE FORM_INFO_1A DWORD
   Flags         AS DWORD        ' DWORD
   pName         AS ASCIIZ PTR   ' LPSTR
   Size          AS SIZEL        ' SIZEL
   ImageableArea AS RECTL        ' RECTL
END TYPE

' // Size = 32 bytes
TYPE FORM_INFO_1W DWORD
   Flags         AS DWORD          ' DWORD
   pName         AS WSTRINGZ PTR   ' LPWSTR
   Size          AS SIZEL          ' SIZEL
   ImageableArea AS RECTL          ' RECTL
END TYPE

#IF %DEF(%UNICODE)
   MACRO FORM_INFO_1 = FORM_INFO_1W
#ELSE
   MACRO FORM_INFO_1 = FORM_INFO_1A
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%STRING_NONE     = &H00000001???
%STRING_MUIDLL   = &H00000002???
%STRING_LANGPAIR = &H00000004???

%MAX_FORM_KEYWORD_LENGTH = 63+1

' // Size = 56 bytes
TYPE FORM_INFO_2A DWORD
   Flags         AS DWORD        ' DWORD
   pName         AS ASCIIZ PTR   ' LPCSTR
   Size          AS SIZEL        ' SIZEL
   ImageableArea AS RECTL        ' RECTL
   pKeyword      AS ASCIIZ PTR   ' LPCSTR
   StringType    AS DWORD        ' DWORD
   pMuiDll       AS ASCIIZ PTR   ' LPCSTR
   dwResourceId  AS DWORD        ' DWORD
   pDisplayName  AS ASCIIZ PTR   ' LPCSTR
   wLangId       AS WORD
END TYPE

' // Size = 56 bytes
TYPE FORM_INFO_2W DWORD
   Flags         AS DWORD          ' DWORD
   pName         AS WSTRINGZ PTR   ' LPCWSTR
   Size          AS SIZEL          ' SIZEL
   ImageableArea AS RECTL          ' RECTL
   pKeyword      AS WSTRINGZ PTR   ' LPCWSTR
   StringType    AS DWORD          ' DWORD
   pMuiDll       AS WSTRINGZ PTR   ' LPCWSTR
   dwResourceId  AS DWORD          ' DWORD
   pDisplayName  AS WSTRINGZ PTR   ' LPCWSTR
   wLangId       AS WORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO FORM_INFO_2 = FORM_INFO_2W
#ELSE
   MACRO FORM_INFO_2 = FORM_INFO_2A
#ENDIF

' // Size = 20 bytes
TYPE DOC_INFO_2A DWORD
   pDocName    AS ASCIIZ PTR   ' LPSTR
   pOutputFile AS ASCIIZ PTR   ' LPSTR
   pDatatype   AS ASCIIZ PTR   ' LPSTR
   dwMode      AS DWORD        ' DWORD
   JobId       AS DWORD        ' DWORD
END TYPE

' // Size = 20 bytes
TYPE DOC_INFO_2W DWORD
   pDocName    AS WSTRINGZ PTR   ' LPWSTR
   pOutputFile AS WSTRINGZ PTR   ' LPWSTR
   pDatatype   AS WSTRINGZ PTR   ' LPWSTR
   dwMode      AS DWORD          ' DWORD
   JobId       AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DOC_INFO_2 = DOC_INFO_2W
#ELSE
   MACRO DOC_INFO_2 = DOC_INFO_2A
#ENDIF

%DI_CHANNEL        = 1                  ' start direct read/write channel,

%DI_READ_SPOOL_JOB = 3

' // Size = 16 bytes
TYPE DOC_INFO_3A DWORD
   pDocName    AS ASCIIZ PTR   ' LPSTR
   pOutputFile AS ASCIIZ PTR   ' LPSTR
   pDataType   AS ASCIIZ PTR   ' LPSTR
   dwFlags     AS DWORD        ' DWORD
END TYPE

' // Size = 16 bytes
TYPE DOC_INFO_3W DWORD
   pDocName    AS WSTRINGZ PTR   ' LPWSTR
   pOutputFile AS WSTRINGZ PTR   ' LPWSTR
   pDataType   AS WSTRINGZ PTR   ' LPWSTR
   dwFlags     AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DOC_INFO_3 = DOC_INFO_3W
#ELSE
   MACRO DOC_INFO_3 = DOC_INFO_3A
#ENDIF

%DI_MEMORYMAP_WRITE = &H00000001???

%FORM_USER          = &H00000000???
%FORM_BUILTIN       = &H00000001???
%FORM_PRINTER       = &H00000002???

' // Size = 4 bytes
TYPE PRINTPROCESSOR_INFO_1A DWORD
   pName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE PRINTPROCESSOR_INFO_1W DWORD
   pName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTPROCESSOR_INFO_1 = PRINTPROCESSOR_INFO_1W
#ELSE
   MACRO PRINTPROCESSOR_INFO_1 = PRINTPROCESSOR_INFO_1A
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXP)
' // Size = 16 bytes
TYPE PRINTPROCESSOR_CAPS_1 DWORD
   dwLevel          AS DWORD
   dwNupOptions     AS DWORD
   dwPageOrderFlags AS DWORD
   dwNumberOfCopies AS DWORD
END TYPE

%NORMAL_PRINT  = &H00000000???
%REVERSE_PRINT = &H00000001???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 36 bytes
TYPE PRINTPROCESSOR_CAPS_2 DWORD
   dwLevel               AS DWORD   ' DWORD
   dwNupOptions          AS DWORD   ' DWORD
   dwPageOrderFlags      AS DWORD   ' DWORD
   dwNumberOfCopies      AS DWORD   ' DWORD
   '// _PRINTPROCESSOR_CAPS_2 specific fields.
   dwDuplexHandlingCaps  AS DWORD   ' DWORD
   dwNupDirectionCaps    AS DWORD   ' DWORD
   dwNupBorderCaps       AS DWORD   ' DWORD
   dwBookletHandlingCaps AS DWORD   ' DWORD
   dwScalingCaps         AS DWORD   ' DWORD
END TYPE

'//Flags for dwNupDirectionCaps.
%PPCAPS_RIGHT_THEN_DOWN = &H00000001   ' ( 0x00000001      ) // 0x00000001
%PPCAPS_DOWN_THEN_RIGHT = &H00000002   ' ( 0x00000001 << 1 ) // 0x00000002
%PPCAPS_LEFT_THEN_DOWN  = &H00000004   ' ( 0x00000001 << 2 ) // 0x00000004
%PPCAPS_DOWN_THEN_LEFT  = &H00000008   ' ( 0x00000001 << 3 ) // 0x00000008

'//dwNupBorderCaps
%PPCAPS_BORDER_PRINT    = &H00000001???

'//dwBookletHandlingCaps
%PPCAPS_BOOKLET_EDGE    = &H00000001???

'//dwDuplexHandlingCaps
'// The below flag tells that print processor can flip page order within sheet
'// while printing reverse duplex.
'// e.g. Instead of playing pages in order 4,3,2,1, print processor can play them 3,4,1,2
%PPCAPS_REVERSE_PAGES_FOR_REVERSE_DUPLEX = &H00000001???
%PPCAPS_DONT_SEND_EXTRA_PAGES_FOR_DUPLEX = &H00000002???   ' ( 0x00000001 << 1 )

'//dwScalingCaps
%PPCAPS_SQUARE_SCALING                   = &H00000001???

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 4 bytes
TYPE PORT_INFO_1A DWORD
   pName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE PORT_INFO_1W DWORD
   pName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PORT_INFO_1 = PORT_INFO_1W
#ELSE
   MACRO PORT_INFO_1 = PORT_INFO_1A
#ENDIF

' // Size = 20 bytes
TYPE PORT_INFO_2A DWORD
   pPortName    AS ASCIIZ PTR   ' LPSTR
   pMonitorName AS ASCIIZ PTR   ' LPSTR
   pDescription AS ASCIIZ PTR   ' LPSTR
   fPortType    AS DWORD        ' DWORD
   Reserved     AS DWORD        ' DWORD
END TYPE

' // Size = 20 bytes
TYPE PORT_INFO_2W DWORD
   pPortName    AS WSTRINGZ PTR   ' LPWSTR
   pMonitorName AS WSTRINGZ PTR   ' LPWSTR
   pDescription AS WSTRINGZ PTR   ' LPWSTR
   fPortType    AS DWORD          ' DWORD
   Reserved     AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PORT_INFO_2 = PORT_INFO_2W
#ELSE
   MACRO PORT_INFO_2 = PORT_INFO_2A
#ENDIF

%PORT_TYPE_WRITE        = &H0001???
%PORT_TYPE_READ         = &H0002???
%PORT_TYPE_REDIRECTED   = &H0004???
%PORT_TYPE_NET_ATTACHED = &H0008???

' // Size = 12 bytes
TYPE PORT_INFO_3A DWORD
   dwStatus   AS DWORD        ' DWORD
   pszStatus  AS ASCIIZ PTR   ' LPSTR
   dwSeverity AS DWORD        ' DWORD
END TYPE

' // Size = 12 bytes
TYPE PORT_INFO_3W DWORD
   dwStatus   AS DWORD          ' DWORD
   pszStatus  AS WSTRINGZ PTR   ' LPWSTR
   dwSeverity AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PORT_INFO_3 = PORT_INFO_3W
#ELSE
   MACRO PORT_INFO_3 = PORT_INFO_3A
#ENDIF

%PORT_STATUS_TYPE_ERROR        = 1
%PORT_STATUS_TYPE_WARNING      = 2
%PORT_STATUS_TYPE_INFO         = 3

%PORT_STATUS_OFFLINE           = 1
%PORT_STATUS_PAPER_JAM         = 2
%PORT_STATUS_PAPER_OUT         = 3
%PORT_STATUS_OUTPUT_BIN_FULL   = 4
%PORT_STATUS_PAPER_PROBLEM     = 5
%PORT_STATUS_NO_TONER          = 6
%PORT_STATUS_DOOR_OPEN         = 7
%PORT_STATUS_USER_INTERVENTION = 8
%PORT_STATUS_OUT_OF_MEMORY     = 9

%PORT_STATUS_TONER_LOW         = 10

%PORT_STATUS_WARMING_UP        = 11
%PORT_STATUS_POWER_SAVE        = 12

' // Size = 4 bytes
TYPE MONITOR_INFO_1A DWORD
   pName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE MONITOR_INFO_1W DWORD
   pName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO MONITOR_INFO_1 = MONITOR_INFO_1W
#ELSE
   MACRO MONITOR_INFO_1 = MONITOR_INFO_1A
#ENDIF

' // Size = 12 bytes
TYPE MONITOR_INFO_2A DWORD
   pName        AS ASCIIZ PTR   ' LPSTR
   pEnvironment AS ASCIIZ PTR   ' LPSTR
   pDLLName     AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE MONITOR_INFO_2W DWORD
   pName        AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment AS WSTRINGZ PTR   ' LPWSTR
   pDLLName     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO MONITOR_INFO_2 = MONITOR_INFO_2W
#ELSE
   MACRO MONITOR_INFO_2 = MONITOR_INFO_2A
#ENDIF

' // Size = 4 bytes
TYPE DATATYPES_INFO_1A DWORD
   pName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE DATATYPES_INFO_1W DWORD
   pName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DATATYPES_INFO_1 = DATATYPES_INFO_1W
#ELSE
   MACRO DATATYPES_INFO_1 = DATATYPES_INFO_1A
#ENDIF

' // Size = 12 bytes
TYPE PRINTER_DEFAULTSA DWORD
   pDatatype     AS ASCIIZ PTR    ' LPSTR
   pDevMode      AS DEVMODE PTR   ' LPDEVMODEA
   DesiredAccess AS DWORD         ' ACCESS_MASK
END TYPE

' // Size = 12 bytes
TYPE PRINTER_DEFAULTSW DWORD
   pDatatype     AS WSTRINGZ PTR   ' LPWSTR
   pDevMode      AS DEVMODEW PTR   ' LPDEVMODEW
   DesiredAccess AS DWORD          ' ACCESS_MASK
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_DEFAULTS = PRINTER_DEFAULTSW
#ELSE
   MACRO PRINTER_DEFAULTS = PRINTER_DEFAULTSA
#ENDIF

' // Size = 20 bytes
TYPE PRINTER_ENUM_VALUESA DWORD
   pValueName  AS ASCIIZ PTR   ' LPSTR
   cbValueName AS DWORD        ' DWORD
   dwType      AS DWORD        ' DWORD
   pData       AS BYTE PTR     ' LPBYTE
   cbData      AS DWORD        ' DWORD
END TYPE

' // Size = 20 bytes
TYPE PRINTER_ENUM_VALUESW DWORD
   pValueName  AS WSTRINGZ PTR   ' LPWSTR
   cbValueName AS DWORD          ' DWORD
   dwType      AS DWORD          ' DWORD
   pData       AS BYTE PTR       ' LPBYTE
   cbData      AS DWORD          ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_ENUM_VALUES = PRINTER_ENUM_VALUESW
#ELSE
   MACRO PRINTER_ENUM_VALUES = PRINTER_ENUM_VALUESA
#ENDIF

' Undocumented - Not in Vista SDK
DECLARE FUNCTION EnumPrinterPropertySheets IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterPropertySheets" ( _
   BYREF phPrinter AS DWORD _                           ' phPrinter
 , BYREF hWnd AS DWORD _                                ' hWnd
 , BYREF lpfnAdd AS DWORD _                             ' lpfnAdd
 , BYVAL lParam AS LONG _                               ' lParam
 ) AS DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintersA LIB "WinSpool.drv" ALIAS "EnumPrintersA" ( _
    BYVAL Flags        AS DWORD, _
    sName              AS ASCIIZ, _
    BYVAL Level        AS DWORD, _
    BYVAL pPrinterEnum AS BYTE PTR, _
    BYVAL cbBuf        AS DWORD, _
    pcbNeeded          AS DWORD, _
    pcReturned         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintersA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintersA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Name AS ASCIIZ _                               ' __in LPSTR Name
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinterEnum AS ANY _                          ' __out LPBYTE pPrinterEnum
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintersW LIB "WinSpool.drv" ALIAS "EnumPrintersW" ( _
    BYVAL Flags        AS DWORD, _
    sName              AS WSTRINGZ, _
    BYVAL Level        AS DWORD, _
    BYVAL pPrinterEnum AS BYTE PTR, _
    BYVAL cbBuf        AS DWORD, _
    pcbNeeded          AS DWORD, _
    pcReturned         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintersW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintersW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Name AS WSTRINGZ _                             ' __in LPWSTR Name
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinterEnum AS ANY _                          ' __out LPBYTE pPrinterEnum
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrinters = EnumPrintersW
#ELSE
   MACRO EnumPrinters = EnumPrintersA
#ENDIF

%PRINTER_ENUM_DEFAULT     = &H00000001???
%PRINTER_ENUM_LOCAL       = &H00000002???
%PRINTER_ENUM_CONNECTIONS = &H00000004???
%PRINTER_ENUM_FAVORITE    = &H00000004???
%PRINTER_ENUM_NAME        = &H00000008???
%PRINTER_ENUM_REMOTE      = &H00000010???
%PRINTER_ENUM_SHARED      = &H00000020???
%PRINTER_ENUM_NETWORK     = &H00000040???

%PRINTER_ENUM_EXPAND      = &H00004000???
%PRINTER_ENUM_CONTAINER   = &H00008000???

%PRINTER_ENUM_ICONMASK    = &H00ff0000???
%PRINTER_ENUM_ICON1       = &H00010000???
%PRINTER_ENUM_ICON2       = &H00020000???
%PRINTER_ENUM_ICON3       = &H00040000???
%PRINTER_ENUM_ICON4       = &H00080000???
%PRINTER_ENUM_ICON5       = &H00100000???
%PRINTER_ENUM_ICON6       = &H00200000???
%PRINTER_ENUM_ICON7       = &H00400000???
%PRINTER_ENUM_ICON8       = &H00800000???
%PRINTER_ENUM_HIDE        = &H01000000???

%SPOOL_FILE_PERSISTENT    = &H00000001???
%SPOOL_FILE_TEMPORARY     = &H00000002???

DECLARE FUNCTION GetSpoolFileHandle IMPORT "WINSPOOL.DRV" ALIAS "GetSpoolFileHandle" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CommitSpoolData IMPORT "WINSPOOL.DRV" ALIAS "CommitSpoolData" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL hSpoolFile AS DWORD _                          ' __in HANDLE hSpoolFile
 , BYVAL cbCommit AS DWORD _                            ' __in DWORD cbCommit
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION CloseSpoolFileHandle IMPORT "WINSPOOL.DRV" ALIAS "CloseSpoolFileHandle" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL hSpoolFile AS DWORD _                          ' __in HANDLE hSpoolFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenPrinterA IMPORT "WINSPOOL.DRV" ALIAS "OpenPrinterA" ( _
   BYREF pPrinterName AS ASCIIZ _                       ' __in LPSTR pPrinterName
 , BYREF phPrinter AS DWORD _                           ' __out LPHANDLE phPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSA _       ' __in_opt LPPRINTER_DEFAULTSA pDefault
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenPrinterW IMPORT "WINSPOOL.DRV" ALIAS "OpenPrinterW" ( _
   BYREF pPrinterName AS WSTRINGZ _                     ' __in LPWSTR pPrinterName
 , BYREF phPrinter AS DWORD _                           ' __out LPHANDLE phPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSW _       ' __in_opt LPPRINTER_DEFAULTSW pDefault
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OpenPrinter = OpenPrinterW
#ELSE
   MACRO OpenPrinter = OpenPrinterA
#ENDIF

DECLARE FUNCTION ResetPrinterA IMPORT "WINSPOOL.DRV" ALIAS "ResetPrinterA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE   hPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSA _       ' __in_opt LPPRINTER_DEFAULTSA pDefault
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ResetPrinterW IMPORT "WINSPOOL.DRV" ALIAS "ResetPrinterW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE   hPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSW _       ' __in_opt LPPRINTER_DEFAULTSW pDefault
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ResetPrinter = ResetPrinterW
#ELSE
   MACRO ResetPrinter = ResetPrinterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetJobA LIB "WinSpool.drv" ALIAS "SetJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetJobA IMPORT "WINSPOOL.DRV" ALIAS "SetJobA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __in_opt LPBYTE pJob
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetJobW LIB "WinSpool.drv" ALIAS "SetJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetJobW IMPORT "WINSPOOL.DRV" ALIAS "SetJobW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __in_opt LPBYTE pJob
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetJob = SetJobW
#ELSE
   MACRO SetJob = SetJobA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetJobA LIB "WinSpool.drv" ALIAS "GetJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetJobA IMPORT "WINSPOOL.DRV" ALIAS "GetJobA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __out LPBYTE pJob
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetJobW LIB "WinSpool.drv" ALIAS "GetJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL JobId    AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetJobW IMPORT "WINSPOOL.DRV" ALIAS "GetJobW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __out LPBYTE pJob
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetJob = GetJobW
#ELSE
   MACRO GetJob = GetJobA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumJobsA LIB "WinSpool.drv" ALIAS "EnumJobsA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL FirstJob AS DWORD, _
    BYVAL NoJobs   AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD  _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumJobsA IMPORT "WINSPOOL.DRV" ALIAS "EnumJobsA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL FirstJob AS DWORD _                            ' __in DWORD FirstJob
 , BYVAL NoJobs AS DWORD _                              ' __in DWORD NoJobs
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __out LPBYTE pJob
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumJobsW LIB "WinSpool.drv" ALIAS "EnumJobsW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL FirstJob AS DWORD, _
    BYVAL NoJobs   AS DWORD, _
    BYVAL Level    AS DWORD, _
    BYVAL pJob     AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD  _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumJobsW IMPORT "WINSPOOL.DRV" ALIAS "EnumJobsW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL FirstJob AS DWORD _                            ' __in DWORD FirstJob
 , BYVAL NoJobs AS DWORD _                              ' __in DWORD NoJobs
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pJob AS ANY _                                  ' __out LPBYTE pJob
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumJobs = EnumJobsW
#ELSE
   MACRO EnumJobs = EnumJobsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterA LIB "WinSpool.drv" ALIAS "AddPrinterA" ( _
    pName          AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION AddPrinterA IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __in LPBYTE pPrinter
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterW LIB "WinSpool.drv" ALIAS "AddPrinterW" ( _
    pName          AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR _
    ) AS DWORD  ' HANDLE
#ELSE
DECLARE FUNCTION AddPrinterW IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __in LPBYTE pPrinter
 ) AS DWORD                                             ' HANDLE
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddPrinter = AddPrinterW
#ELSE
   MACRO AddPrinter = AddPrinterA
#ENDIF

DECLARE FUNCTION DeletePrinter IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterA LIB "WinSpool.drv" ALIAS "SetPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetPrinterA IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __in LPBYTE pPrinter
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterW LIB "WinSpool.drv" ALIAS "SetPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL COMMAND  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetPrinterW IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __in LPBYTE pPrinter
 , BYVAL Command AS DWORD _                             ' __in DWORD Command
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetPrinter = SetPrinterW
#ELSE
   MACRO SetPrinter = SetPrinterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterA LIB "WinSpool.drv" ALIAS "GetPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __out LPBYTE pPrinter
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterW LIB "WinSpool.drv" ALIAS "GetPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pPrinter AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrinter AS ANY _                              ' __out LPBYTE pPrinter
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinter = GetPrinterW
#ELSE
   MACRO GetPrinter = GetPrinterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterDriverA LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverA" ( _
    pName             AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrinterDriverA IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterDriverA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __inout LPBYTE pDriverInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterDriverW LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverW" ( _
    pName             AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrinterDriverW IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterDriverW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __inout LPBYTE pDriverInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddPrinterDriver = AddPrinterDriverW
#ELSE
   MACRO AddPrinterDriver = AddPrinterDriverA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterDriverExA LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverExA" ( _
    pName                 AS ASCIIZ, _
    BYVAL Level           AS DWORD, _
    BYVAL pDriverInfo     AS BYTE PTR, _
    BYVAL dwFileCopyFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrinterDriverExA IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterDriverExA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __inout LPBYTE pDriverInfo
 , BYVAL dwFileCopyFlags AS DWORD _                     ' __in DWORD dwFileCopyFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrinterDriverExW LIB "WinSpool.drv" _
    ALIAS "AddPrinterDriverExW" ( _
    pName                 AS WSTRINGZ, _
    BYVAL Level           AS DWORD, _
    BYVAL pDriverInfo     AS BYTE PTR, _
    BYVAL dwFileCopyFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrinterDriverExW IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterDriverExW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __inout LPBYTE pDriverInfo
 , BYVAL dwFileCopyFlags AS DWORD _                     ' __in DWORD dwFileCopyFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddPrinterDriverEx = AddPrinterDriverExW
#ELSE
   MACRO AddPrinterDriverEx = AddPrinterDriverExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDriversA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDriversA" ( _
    pName             AS ASCIIZ, _
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD, _
    pcReturned        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrinterDriversA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDriversA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __out LPBYTE pDriverInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDriversW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDriversW" ( _
    pName             AS WSTRINGZ, _
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD, _
    pcReturned        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrinterDriversW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDriversW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL pEnvironment AS DWORD _                        ' __in_opt LPWSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __out LPBYTE pDriverInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrinterDrivers = EnumPrinterDriversW
#ELSE
   MACRO EnumPrinterDrivers = EnumPrinterDriversA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriverA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverA" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterDriverA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __out LPBYTE pDriverInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriverW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverW" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterDriverW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverInfo AS ANY _                           ' __out LPBYTE pDriverInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinterDriver = GetPrinterDriverW
#ELSE
   MACRO GetPrinterDriver = GetPrinterDriverA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriverDirectoryA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverDirectoryA" ( _
    pName                  AS ASCIIZ, _
    pEnvironment           AS ASCIIZ, _
    BYVAL Level            AS DWORD, _
    BYVAL pDriverDirectory AS BYTE PTR, _
    BYVAL cbBuf            AS DWORD, _
    pcbNeeded              AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterDriverDirectoryA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverDirectoryA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverDirectory AS ANY _                      ' __out LPBYTE pDriverDirectory
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriverDirectoryW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriverDirectoryW" ( _
    pName                  AS WSTRINGZ, _
    pEnvironment           AS WSTRINGZ, _
    BYVAL Level            AS DWORD, _
    BYVAL pDriverDirectory AS BYTE PTR, _
    BYVAL cbBuf            AS DWORD, _
    pcbNeeded              AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterDriverDirectoryW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverDirectoryW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDriverDirectory AS ANY _                      ' __out LPBYTE pDriverDirectory
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinterDriverDirectory = GetPrinterDriverDirectoryW
#ELSE
   MACRO GetPrinterDriverDirectory = GetPrinterDriverDirectoryA
#ENDIF

DECLARE FUNCTION DeletePrinterDriverA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pDriverName AS ASCIIZ _                        ' __in LPSTR pDriverName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePrinterDriverW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pDriverName AS WSTRINGZ _                      ' __in LPWSTR pDriverName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePrinterDriver = DeletePrinterDriverW
#ELSE
   MACRO DeletePrinterDriver = DeletePrinterDriverA
#ENDIF

DECLARE FUNCTION DeletePrinterDriverExA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverExA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pDriverName AS ASCIIZ _                        ' __in LPSTR pDriverName
 , BYVAL dwDeleteFlag AS DWORD _                        ' __in DWORD dwDeleteFlag
 , BYVAL dwVersionFlag AS DWORD _                       ' __in DWORD dwVersionFlag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePrinterDriverExW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverExW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pDriverName AS WSTRINGZ _                      ' __in LPWSTR pDriverName
 , BYVAL dwDeleteFlag AS DWORD _                        ' __in DWORD dwDeleteFlag
 , BYVAL dwVersionFlag AS DWORD _                       ' __in DWORD dwVersionFlag
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePrinterDriverEx = DeletePrinterDriverExW
#ELSE
   MACRO DeletePrinterDriverEx = DeletePrinterDriverExA
#ENDIF

DECLARE FUNCTION AddPrintProcessorA IMPORT "WINSPOOL.DRV" ALIAS "AddPrintProcessorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pPathName AS ASCIIZ _                          ' __in LPSTR pPathName
 , BYREF pPrintProcessorName AS ASCIIZ _                ' __in LPSTR pPrintProcessorName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddPrintProcessorW IMPORT "WINSPOOL.DRV" ALIAS "AddPrintProcessorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pPathName AS WSTRINGZ _                        ' __in LPWSTR pPathName
 , BYREF pPrintProcessorName AS WSTRINGZ _              ' __in LPWSTR pPrintProcessorName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AddPrintProcessor = AddPrintProcessorW
#ELSE
   MACRO AddPrintProcessor = AddPrintProcessorA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintProcessorsA LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorsA" ( _
    pName                     AS ASCIIZ, _
    pEnvironment              AS ASCIIZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD, _
    pcReturned                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintProcessorsA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintProcessorsA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrintProcessorInfo AS ANY _                   ' __out LPBYTE pPrintProcessorInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintProcessorsW LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorsW" ( _
    pName                     AS WSTRINGZ, _
    pEnvironment              AS WSTRINGZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD, _
    pcReturned                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintProcessorsW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintProcessorsW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrintProcessorInfo AS ANY _                   ' __out LPBYTE pPrintProcessorInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrintProcessors = EnumPrintProcessorsW
#ELSE
   MACRO EnumPrintProcessors = EnumPrintProcessorsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrintProcessorDirectoryA LIB "WinSpool.drv" _
    ALIAS "GetPrintProcessorDirectoryA" ( _
    pName                     AS ASCIIZ, _
    pEnvironment              AS ASCIIZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrintProcessorDirectoryA IMPORT "WINSPOOL.DRV" ALIAS "GetPrintProcessorDirectoryA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrintProcessorInfo AS ANY _                   ' __out LPBYTE pPrintProcessorInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrintProcessorDirectoryW LIB "WinSpool.drv" _
    ALIAS "GetPrintProcessorDirectoryW" ( _
    pName                     AS WSTRINGZ, _
    pEnvironment              AS WSTRINGZ, _
    BYVAL Level               AS DWORD, _
    BYVAL pPrintProcessorInfo AS BYTE PTR, _
    BYVAL cbBuf               AS DWORD, _
    pcbNeeded                 AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrintProcessorDirectoryW IMPORT "WINSPOOL.DRV" ALIAS "GetPrintProcessorDirectoryW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPrintProcessorInfo AS ANY _                   ' __out LPBYTE pPrintProcessorInfo
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrintProcessorDirectory = GetPrintProcessorDirectoryW
#ELSE
   MACRO GetPrintProcessorDirectory = GetPrintProcessorDirectoryA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintProcessorDatatypesA LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorDatatypesA" ( _
    pName               AS ASCIIZ, _
    pPrintProcessorName AS ASCIIZ, _
    BYVAL Level         AS DWORD, _
    BYVAL pDatatypes    AS BYTE PTR, _
    BYVAL cbBuf         AS DWORD, _
    pcbNeeded           AS DWORD, _
    pcReturned          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintProcessorDatatypesA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintProcessorDatatypesA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pPrintProcessorName AS ASCIIZ _                ' __in LPSTR pPrintProcessorName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDatatypes AS ANY _                            ' __out LPBYTE pDatatypes
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrintProcessorDatatypesW LIB "WinSpool.drv" _
    ALIAS "EnumPrintProcessorDatatypesW" ( _
    pName               AS WSTRINGZ, _
    pPrintProcessorName AS WSTRINGZ, _
    BYVAL Level         AS DWORD, _
    BYVAL pDatatypes    AS BYTE PTR, _
    BYVAL cbBuf         AS DWORD, _
    pcbNeeded           AS DWORD, _
    pcReturned          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPrintProcessorDatatypesW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrintProcessorDatatypesW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pPrintProcessorName AS WSTRINGZ _              ' __in LPWSTR pPrintProcessorName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDatatypes AS ANY _                            ' __out LPBYTE pDatatypes
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrintProcessorDatatypes = EnumPrintProcessorDatatypesW
#ELSE
   MACRO EnumPrintProcessorDatatypes = EnumPrintProcessorDatatypesA
#ENDIF

DECLARE FUNCTION DeletePrintProcessorA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrintProcessorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pPrintProcessorName AS ASCIIZ _                ' __in LPSTR pPrintProcessorName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePrintProcessorW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrintProcessorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pPrintProcessorName AS WSTRINGZ _              ' __in LPWSTR pPrintProcessorName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePrintProcessor = DeletePrintProcessorW
#ELSE
   MACRO DeletePrintProcessor = DeletePrintProcessorA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartDocPrinterA LIB "WinSpool.drv" _
    ALIAS "StartDocPrinterA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pDocInfo AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION StartDocPrinterA IMPORT "WINSPOOL.DRV" ALIAS "StartDocPrinterA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDocInfo AS ANY _                              ' __in LPBYTE pDocInfo
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StartDocPrinterW LIB "WinSpool.drv" _
    ALIAS "StartDocPrinterW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pDocInfo AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION StartDocPrinterW IMPORT "WINSPOOL.DRV" ALIAS "StartDocPrinterW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pDocInfo AS ANY _                              ' __in LPBYTE pDocInfo
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO StartDocPrinter = StartDocPrinterW
#ELSE
   MACRO StartDocPrinter = StartDocPrinterA
#ENDIF

DECLARE FUNCTION StartPagePrinter IMPORT "WINSPOOL.DRV" ALIAS "StartPagePrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WritePrinter IMPORT "WINSPOOL.DRV" ALIAS "WritePrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pBuf AS ANY _                                  ' __in LPVOID pBuf
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcWritten AS DWORD _                           ' __out LPDWORD pcWritten
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlushPrinter IMPORT "WINSPOOL.DRV" ALIAS "FlushPrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pBuf AS ANY _                                  ' __in LPVOID pBuf
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcWritten AS DWORD _                           ' __out LPDWORD pcWritten
 , BYVAL cSleep AS DWORD _                              ' __in DWORD cSleep
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EndPagePrinter IMPORT "WINSPOOL.DRV" ALIAS "EndPagePrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AbortPrinter IMPORT "WINSPOOL.DRV" ALIAS "AbortPrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ReadPrinter IMPORT "WINSPOOL.DRV" ALIAS "ReadPrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE  hPrinter
 , BYREF pBuf AS ANY _                                  ' __out LPVOID pBuf
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pNoBytesRead AS DWORD _                        ' __out LPDWORD pNoBytesRead
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EndDocPrinter IMPORT "WINSPOOL.DRV" ALIAS "EndDocPrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddJobA LIB "WinSpool.drv" ALIAS "AddJobA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddJobA IMPORT "WINSPOOL.DRV" ALIAS "AddJobA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pData AS ANY _                                 ' __out LPBYTE pData
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddJobW LIB "WinSpool.drv" ALIAS "AddJobW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddJobW IMPORT "WINSPOOL.DRV" ALIAS "AddJobW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pData AS ANY _                                 ' __out LPBYTE pData
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddJob = AddJobW
#ELSE
   MACRO AddJob = AddJobA
#ENDIF

DECLARE FUNCTION ScheduleJob IMPORT "WINSPOOL.DRV" ALIAS "ScheduleJob" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL JobId AS DWORD _                               ' __in DWORD JobId
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PrinterProperties IMPORT "WINSPOOL.DRV" ALIAS "PrinterProperties" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DocumentPropertiesA IMPORT "WINSPOOL.DRV" ALIAS "DocumentPropertiesA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hPrinter AS DWORD _                            ' __in_opt HANDLE hPrinter
 , BYREF pDeviceName AS ASCIIZ _                        ' __in LPSTR pDeviceName
 , BYREF pDevModeOutput AS DEVMODEA _                   ' __out_opt PDEVMODEA pDevModeOutput
 , BYREF pDevModeInput AS DEVMODEA _                    ' __in_opt PDEVMODEA pDevModeInput
 , BYVAL fMode AS DWORD _                               ' __in DWORD fMode
 ) AS LONG                                              ' LONG

DECLARE FUNCTION DocumentPropertiesW IMPORT "WINSPOOL.DRV" ALIAS "DocumentPropertiesW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hPrinter AS DWORD _                            ' __in_opt HANDLE hPrinter
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in LPWSTR pDeviceName
 , BYREF pDevModeOutput AS DEVMODEW _                   ' __out_opt PDEVMODEW pDevModeOutput
 , BYREF pDevModeInput AS DEVMODEW _                    ' __in_opt PDEVMODEW pDevModeInput
 , BYVAL fMode AS DWORD _                               ' __in DWORD fMode
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO DocumentProperties = DocumentPropertiesW
#ELSE
   MACRO DocumentProperties = DocumentPropertiesA
#ENDIF

DECLARE FUNCTION AdvancedDocumentPropertiesA IMPORT "WINSPOOL.DRV" ALIAS "AdvancedDocumentPropertiesA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hPrinter AS DWORD _                            ' __in_opt HANDLE hPrinter
 , BYREF pDeviceName AS ASCIIZ _                        ' __in LPSTR pDeviceName
 , OPTIONAL BYREF pDevModeOutput AS DEVMODEA _          ' __out_opt PDEVMODEA pDevModeOutput
 , OPTIONAL BYREF pDevModeInput AS DEVMODEA _           ' __in_opt PDEVMODEA pDevModeInput
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AdvancedDocumentPropertiesW IMPORT "WINSPOOL.DRV" ALIAS "AdvancedDocumentPropertiesW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL hPrinter AS DWORD _                            ' __in_opt HANDLE hPrinter
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in LPWSTR pDeviceName
 , OPTIONAL BYREF pDevModeOutput AS DEVMODEW _          ' __out_opt PDEVMODEW pDevModeOutput
 , OPTIONAL BYREF pDevModeInput AS DEVMODEW _           ' __in_opt PDEVMODEW pDevModeInput
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AdvancedDocumentProperties = AdvancedDocumentPropertiesW
#ELSE
   MACRO AdvancedDocumentProperties = AdvancedDocumentPropertiesA
#ENDIF

' The ExtDeviceMode function is provided only for compatibility with 16-bit
' applications. Printer drivers without this requirement should instead use the
' DocumentProperties function, which is described in the Microsoft Windows SDK
' documentation.

'#if (NTDDI_VERSION >= NTDDI_WINXPSP1)
'LONG
'ExtDeviceMode (
'    __in HWND hWnd,
'    __in_opt HANDLE hInst,
'    __out_opt LPDEVMODEA pDevModeOutput,
'    __in LPSTR pDeviceName,
'    __in_opt LPSTR pPort,
'    __in_opt LPDEVMODEA pDevModeInput,
'    __in_opt LPSTR pProfile,
'    __in DWORD fMode
');
'#endif // (NTDDI_VERSION >= NTDDI_WINXPSP1)


#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDataA LIB "WinSpool.drv" ALIAS "GetPrinterDataA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS ASCIIZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrinterDataA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDataA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pValueName AS ASCIIZ _                         ' __in_opt LPSTR pValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out_opt LPBYTE pData
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDataW LIB "WinSpool.drv" ALIAS "GetPrinterDataW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS WSTRINGZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrinterDataW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDataW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pValueName AS WSTRINGZ _                       ' __in_opt LPWSTR pValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out_opt LPBYTE pData
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinterData = GetPrinterDataW
#ELSE
   MACRO GetPrinterData = GetPrinterDataA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "GetPrinterDataExA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pValueName     AS ASCIIZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrinterDataExA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDataExA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in_opt LPCSTR pKeyName
 , BYREF pValueName AS ASCIIZ _                         ' __in_opt LPCSTR pValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out_opt LPBYTE pData
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "GetPrinterDataExW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pValueName     AS WSTRINGZ, _
    pType          AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL nSize    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetPrinterDataExW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDataExW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in_opt LPCWSTR pKeyName
 , BYREF pValueName AS WSTRINGZ _                       ' __in_opt LPCWSTR pValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out_opt LPBYTE pData
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinterDataEx = GetPrinterDataExW
#ELSE
   MACRO GetPrinterDataEx = GetPrinterDataExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDataA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataA" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    BYVAL dwIndex     AS DWORD, _
    pValueName        AS ASCIIZ, _
    BYVAL cbValueName AS DWORD, _
    pcbValueName      AS DWORD, _
    pType             AS DWORD, _
    BYVAL pData       AS BYTE PTR, _
    BYVAL cbData      AS DWORD, _
    pcbData           AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION EnumPrinterDataA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDataA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pValueName AS ASCIIZ _                         ' __out LPSTR pValueName
 , BYVAL cbValueName AS DWORD _                         ' __in DWORD cbValueName
 , BYREF pcbValueName AS DWORD _                        ' __out LPDWORD pcbValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDataW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataW" ( _
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    BYVAL dwIndex     AS DWORD, _
    pValueName        AS WSTRINGZ, _
    BYVAL cbValueName AS DWORD, _
    pcbValueName      AS DWORD, _
    pType             AS DWORD, _
    BYVAL pData       AS BYTE PTR, _
    BYVAL cbData      AS DWORD, _
    pcbData           AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION EnumPrinterDataW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDataW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pValueName AS WSTRINGZ _                       ' __out LPWSTR pValueName
 , BYVAL cbValueName AS DWORD _                         ' __in DWORD cbValueName
 , BYREF pcbValueName AS DWORD _                        ' __out LPDWORD pcbValueName
 , BYREF pType AS DWORD _                               ' __out_opt LPDWORD pType
 , BYREF pData AS ANY _                                 ' __out LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF pcbData AS DWORD _                             ' __out LPDWORD pcbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrinterData = EnumPrinterDataW
#ELSE
   MACRO EnumPrinterData = EnumPrinterDataA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataExA" ( _
    BYVAL hPrinter     AS DWORD, _  ' HANDLE
    pKeyName           AS ASCIIZ, _
    BYVAL pEnumValues  AS BYTE PTR, _
    BYVAL cbEnumValues AS DWORD, _
    pcbEnumValues      AS DWORD, _
    pnEnumValues       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION EnumPrinterDataExA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDataExA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in LPCSTR pKeyName
 , BYREF pEnumValues AS ANY _                           ' __out LPBYTE pEnumValues
 , BYVAL cbEnumValues AS DWORD _                        ' __in DWORD cbEnumValues
 , BYREF pcbEnumValues AS DWORD _                       ' __out LPDWORD pcbEnumValues
 , BYREF pnEnumValues AS DWORD _                        ' __out LPDWORD pnEnumValues
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "EnumPrinterDataExW" ( _
    BYVAL hPrinter     AS DWORD, _  ' HANDLE
    pKeyName           AS WSTRINGZ, _
    BYVAL pEnumValues  AS BYTE PTR, _
    BYVAL cbEnumValues AS DWORD, _
    pcbEnumValues      AS DWORD, _
    pnEnumValues       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION EnumPrinterDataExW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterDataExW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in LPCWSTR pKeyName
 , BYREF pEnumValues AS ANY _                           ' __out LPBYTE pEnumValues
 , BYVAL cbEnumValues AS DWORD _                        ' __in DWORD cbEnumValues
 , BYREF pcbEnumValues AS DWORD _                       ' __out LPDWORD pcbEnumValues
 , BYREF pnEnumValues AS DWORD _                        ' __out LPDWORD pnEnumValues
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPrinterDataEx = EnumPrinterDataExW
#ELSE
   MACRO EnumPrinterDataEx = EnumPrinterDataExA
#ENDIF

DECLARE FUNCTION EnumPrinterKeyA IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterKeyA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in LPCSTR pKeyName
 , BYREF pSubkey AS ASCIIZ _                            ' __out LPSTR pSubkey
 , BYVAL cbSubkey AS DWORD _                            ' __in DWORD cbSubkey
 , BYREF pcbSubkey AS DWORD _                           ' __out LPDWORD pcbSubkey
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION EnumPrinterKeyW IMPORT "WINSPOOL.DRV" ALIAS "EnumPrinterKeyW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in LPCWSTR pKeyName
 , BYREF pSubkey AS WSTRINGZ _                          ' __out LPWSTR pSubkey
 , BYVAL cbSubkey AS DWORD _                            ' __in DWORD cbSubkey
 , BYREF pcbSubkey AS DWORD _                           ' __out LPDWORD pcbSubkey
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO EnumPrinterKey = EnumPrinterKeyW
#ELSE
   MACRO EnumPrinterKey = EnumPrinterKeyA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterDataA LIB "WinSpool.drv" ALIAS "SetPrinterDataA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS ASCIIZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetPrinterDataA IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterDataA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pValueName AS ASCIIZ _                         ' __in LPSTR pValueName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYREF pData AS ANY _                                 ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterDataW LIB "WinSpool.drv" ALIAS "SetPrinterDataW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pValueName     AS WSTRINGZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetPrinterDataW IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterDataW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pValueName AS WSTRINGZ _                       ' __in LPWSTR pValueName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYREF pData AS ANY _                                 ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetPrinterData = SetPrinterDataW
#ELSE
   MACRO SetPrinterData = SetPrinterDataA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterDataExA LIB "WinSpool.drv" _
    ALIAS "SetPrinterDataExA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS ASCIIZ, _
    pValueName     AS ASCIIZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetPrinterDataExA IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterDataExA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in_opt LPCSTR pKeyName
 , BYREF pValueName AS ASCIIZ _                         ' __in LPCSTR pValueName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYREF pData AS ANY _                                 ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPrinterDataExW LIB "WinSpool.drv" _
    ALIAS "SetPrinterDataExW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pKeyName       AS WSTRINGZ, _
    pValueName     AS WSTRINGZ, _
    BYVAL TYPE     AS DWORD, _
    BYVAL pData    AS BYTE PTR, _
    BYVAL cbData   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetPrinterDataExW IMPORT "WINSPOOL.DRV" ALIAS "SetPrinterDataExW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in_opt LPCWSTR pKeyName
 , BYREF pValueName AS WSTRINGZ _                       ' __in LPCWSTR pValueName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYREF pData AS ANY _                                 ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetPrinterDataEx = SetPrinterDataExW
#ELSE
   MACRO SetPrinterDataEx = SetPrinterDataExA
#ENDIF

DECLARE FUNCTION DeletePrinterDataA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDataA" ( _
   BYVAL hPrinter AS DWORD  _                           ' __in HANDLE hPrinter
 , BYREF pValueName AS ASCIIZ _                         ' __in LPSTR pValueName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeletePrinterDataW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDataW" ( _
   BYVAL hPrinter AS DWORD  _                           ' __in HANDLE hPrinter
 , BYREF pValueName AS WSTRINGZ _                       ' __in LPWSTR pValueName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DeletePrinterData = DeletePrinterDataW
#ELSE
   MACRO DeletePrinterData = DeletePrinterDataA
#ENDIF

DECLARE FUNCTION DeletePrinterDataExA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDataExA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in LPCSTR pKeyName
 , BYREF pValueName AS ASCIIZ _                         ' __in LPCSTR pValueName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeletePrinterDataExW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDataExW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in LPCWSTR pKeyName
 , BYREF pValueName AS WSTRINGZ _                       ' __in LPCWSTR pValueName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DeletePrinterDataEx = DeletePrinterDataExW
#ELSE
   MACRO DeletePrinterDataEx = DeletePrinterDataExA
#ENDIF

DECLARE FUNCTION DeletePrinterKeyA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterKeyA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS ASCIIZ _                           ' __in LPCSTR pKeyName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DeletePrinterKeyW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterKeyW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pKeyName AS WSTRINGZ _                         ' __in LPCWSTR pKeyName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DeletePrinterKey = DeletePrinterKeyW
#ELSE
   MACRO DeletePrinterKey = DeletePrinterKeyA
#ENDIF

%PRINTER_NOTIFY_TYPE                         = &H00??
%JOB_NOTIFY_TYPE                             = &H01??
%SERVER_NOTIFY_TYPE                          = &H02??

%PRINTER_NOTIFY_FIELD_SERVER_NAME            = &H00??
%PRINTER_NOTIFY_FIELD_PRINTER_NAME           = &H01??
%PRINTER_NOTIFY_FIELD_SHARE_NAME             = &H02??
%PRINTER_NOTIFY_FIELD_PORT_NAME              = &H03??
%PRINTER_NOTIFY_FIELD_DRIVER_NAME            = &H04??
%PRINTER_NOTIFY_FIELD_COMMENT                = &H05??
%PRINTER_NOTIFY_FIELD_LOCATION               = &H06??
%PRINTER_NOTIFY_FIELD_DEVMODE                = &H07??
%PRINTER_NOTIFY_FIELD_SEPFILE                = &H08??
%PRINTER_NOTIFY_FIELD_PRINT_PROCESSOR        = &H09??
%PRINTER_NOTIFY_FIELD_PARAMETERS             = &H0A??
%PRINTER_NOTIFY_FIELD_DATATYPE               = &H0B??
%PRINTER_NOTIFY_FIELD_SECURITY_DESCRIPTOR    = &H0C??
%PRINTER_NOTIFY_FIELD_ATTRIBUTES             = &H0D??
%PRINTER_NOTIFY_FIELD_PRIORITY               = &H0E??
%PRINTER_NOTIFY_FIELD_DEFAULT_PRIORITY       = &H0F??
%PRINTER_NOTIFY_FIELD_START_TIME             = &H10??
%PRINTER_NOTIFY_FIELD_UNTIL_TIME             = &H11??
%PRINTER_NOTIFY_FIELD_STATUS                 = &H12??
%PRINTER_NOTIFY_FIELD_STATUS_STRING          = &H13??
%PRINTER_NOTIFY_FIELD_CJOBS                  = &H14??
%PRINTER_NOTIFY_FIELD_AVERAGE_PPM            = &H15??
%PRINTER_NOTIFY_FIELD_TOTAL_PAGES            = &H16??
%PRINTER_NOTIFY_FIELD_PAGES_PRINTED          = &H17??
%PRINTER_NOTIFY_FIELD_TOTAL_BYTES            = &H18??
%PRINTER_NOTIFY_FIELD_BYTES_PRINTED          = &H19??
%PRINTER_NOTIFY_FIELD_OBJECT_GUID            = &H1A??

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%PRINTER_NOTIFY_FIELD_FRIENDLY_NAME          = &H1B??
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%JOB_NOTIFY_FIELD_PRINTER_NAME               = &H00??
%JOB_NOTIFY_FIELD_MACHINE_NAME               = &H01??
%JOB_NOTIFY_FIELD_PORT_NAME                  = &H02??
%JOB_NOTIFY_FIELD_USER_NAME                  = &H03??
%JOB_NOTIFY_FIELD_NOTIFY_NAME                = &H04??
%JOB_NOTIFY_FIELD_DATATYPE                   = &H05??
%JOB_NOTIFY_FIELD_PRINT_PROCESSOR            = &H06??
%JOB_NOTIFY_FIELD_PARAMETERS                 = &H07??
%JOB_NOTIFY_FIELD_DRIVER_NAME                = &H08??
%JOB_NOTIFY_FIELD_DEVMODE                    = &H09??
%JOB_NOTIFY_FIELD_STATUS                     = &H0A??
%JOB_NOTIFY_FIELD_STATUS_STRING              = &H0B??
%JOB_NOTIFY_FIELD_SECURITY_DESCRIPTOR        = &H0C??
%JOB_NOTIFY_FIELD_DOCUMENT                   = &H0D??
%JOB_NOTIFY_FIELD_PRIORITY                   = &H0E??
%JOB_NOTIFY_FIELD_POSITION                   = &H0F??
%JOB_NOTIFY_FIELD_SUBMITTED                  = &H10??
%JOB_NOTIFY_FIELD_START_TIME                 = &H11??
%JOB_NOTIFY_FIELD_UNTIL_TIME                 = &H12??
%JOB_NOTIFY_FIELD_TIME                       = &H13??
%JOB_NOTIFY_FIELD_TOTAL_PAGES                = &H14??
%JOB_NOTIFY_FIELD_PAGES_PRINTED              = &H15??
%JOB_NOTIFY_FIELD_TOTAL_BYTES                = &H16??
%JOB_NOTIFY_FIELD_BYTES_PRINTED              = &H17??
%JOB_NOTIFY_FIELD_REMOTE_JOB_ID              = &H18??

'#if (NTDDI_VERSION >= NTDDI_WIN7)
%SERVER_NOTIFY_FIELD_PRINT_DRIVER_ISOLATION_GROUP = &H00??
'#endif

' // Size = 20 bytes
TYPE PRINTER_NOTIFY_OPTIONS_TYPE DWORD FILL
   Type      AS WORD       ' WORD
   Reserved0 AS WORD       ' WORD
   Reserved1 AS DWORD      ' DWORD
   Reserved2 AS DWORD      ' DWORD
   Count     AS DWORD      ' DWORD
   pFields   AS WORD PTR   ' PWORD
END TYPE

%PRINTER_NOTIFY_OPTIONS_REFRESH = &H01???

' // Size = 16 bytes
TYPE PRINTER_NOTIFY_OPTIONS DWORD
   Version AS DWORD                             ' DWORD
   Flags   AS DWORD                             ' DWORD
   Count   AS DWORD                             ' DWORD
   pTypes  AS PRINTER_NOTIFY_OPTIONS_TYPE PTR   ' PPRINTER_NOTIFY_OPTIONS_TYPE
END TYPE

%PRINTER_NOTIFY_INFO_DISCARDED     = &H01???

'typedef struct _PRINTER_NOTIFY_INFO_DATA {
'    WORD Type;
'    WORD Field;
'    DWORD Reserved;
'    DWORD Id;
'    union {
'        DWORD adwData[2];
'        struct {
'            DWORD  cbBuf;
'            LPVOID pBuf;
'        } Data;
'    } NotifyData;
'} PRINTER_NOTIFY_INFO_DATA, *PPRINTER_NOTIFY_INFO_DATA, *LPPRINTER_NOTIFY_INFO_DATA;

' // Size = 8 bytes
TYPE PRINTER_NOTIFY_INFO_DATA_UNION_DataStruct DWORD
   cbBuf AS DWORD
   pBuf  AS DWORD
END TYPE

' // Size = 8 bytes
UNION PRINTER_NOTIFY_INFO_DATA_UNION DWORD
   adwData(1) AS DWORD
   Data AS PRINTER_NOTIFY_INFO_DATA_UNION_DataStruct
END UNION

' // Size = 20 bytes
TYPE PRINTER_NOTIFY_INFO_DATA DWORD FILL
   Type       AS WORD
   Field      AS WORD
   Reserved   AS DWORD
   Id         AS DWORD
   NotifyData AS PRINTER_NOTIFY_INFO_DATA_UNION
END TYPE

' // Size = 32 bytes
TYPE PRINTER_NOTIFY_INFO DWORD
   Version  AS DWORD                      ' DWORD
   Flags    AS DWORD                      ' DWORD
   Count    AS DWORD                      ' DWORD
   aData(0) AS PRINTER_NOTIFY_INFO_DATA   ' PRINTER_NOTIFY_INFO_DATA aData[1]
END TYPE

'#if (NTDDI_VERSION >= NTDDI_WINXP)
' // Size = 8 bytes
TYPE BINARY_CONTAINER DWORD
   cbBuf AS DWORD      ' DWORD
   pData AS BYTE PTR   ' LPBYTE
END TYPE

' // Size = 8 bytes
UNION BIDI_DATA_UNION DWORD
   bData  AS LONG               ' BOOL
   iData  AS LONG               ' LONG
   sData  AS WSTRINGZ PTR       ' LPWSTR
   fData  AS SINGLE             ' FLOAT
   biData AS BINARY_CONTAINER   ' BINARY_CONTAINER
END UNION

UNION BIDI_DATA_U_UNION DWORD
   BIDI_DATA_UNION
   u AS BIDI_DATA_UNION
END UNION

' // Size = 12 bytes
TYPE BIDI_DATA DWORD
   dwBidiType AS DWORD
   BIDI_DATA_U_UNION
END TYPE

' // Size = 20 bytes
TYPE BIDI_REQUEST_DATA DWORD
   dwReqNumber AS DWORD         ' DWORD
   pSchema     AS WSTRINGZ PTR  ' LPWSTR
   data        AS BIDI_DATA     ' BIDI_DATA
END TYPE

' // Size = 32 bytes
TYPE BIDI_REQUEST_CONTAINER DWORD
   Version  AS DWORD               ' DWORD
   Flags    AS DWORD               ' DWORD
   Count    AS DWORD               ' DWORD
   aData(0) AS BIDI_REQUEST_DATA   ' BIDI_REQUEST_DATA aData[ 1 ]
END TYPE

' // Size = 24 bytes
TYPE BIDI_RESPONSE_DATA DWORD
   dwResult    AS DWORD         ' DWORD
   dwReqNumber AS DWORD         ' DWORD
   pSchema     AS WSTRINGZ PTR  ' LPWSTR
   data        AS BIDI_DATA     ' BIDI_DATA
END TYPE

' // Size = 36 bytes
TYPE BIDI_RESPONSE_CONTAINER DWORD
   Version  AS DWORD                ' DWORD
   Flags    AS DWORD                ' DWORD
   Count    AS DWORD                ' DWORD
   aData(0) AS BIDI_RESPONSE_DATA   ' BIDI_RESPONSE_DATA aData[ 1 ]
END TYPE

$$BIDI_ACTION_ENUM_SCHEMA                 = "EnumSchema"$$
$$BIDI_ACTION_GET                         = "Get"$$
$$BIDI_ACTION_SET                         = "Set"$$
$$BIDI_ACTION_GET_ALL                     = "GetAll"$$

' BIDI_TYPE enum
%BIDI_NULL   = 0
%BIDI_INT    = 1
%BIDI_FLOAT  = 2
%BIDI_BOOL   = 3
%BIDI_STRING = 4
%BIDI_TEXT   = 5
%BIDI_ENUM   = 6
%BIDI_BLOB   = 7

%BIDI_ACCESS_ADMINISTRATOR  = &H1???
%BIDI_ACCESS_USER           = &H2???

'/*
'    Error code for bidi apis
'*/

%ERROR_BIDI_STATUS_OK               = 0
%ERROR_BIDI_NOT_SUPPORTED           = %ERROR_NOT_SUPPORTED

%ERROR_BIDI_ERROR_BASE              = 13000
%ERROR_BIDI_STATUS_WARNING          = %ERROR_BIDI_ERROR_BASE + 1
%ERROR_BIDI_SCHEMA_READ_ONLY        = %ERROR_BIDI_ERROR_BASE + 2
%ERROR_BIDI_SERVER_OFFLINE          = %ERROR_BIDI_ERROR_BASE + 3
%ERROR_BIDI_DEVICE_OFFLINE          = %ERROR_BIDI_ERROR_BASE + 4
%ERROR_BIDI_SCHEMA_NOT_SUPPORTED    = %ERROR_BIDI_ERROR_BASE + 5
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION WaitForPrinterChange IMPORT "WINSPOOL.DRV" ALIAS "WaitForPrinterChange" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION FindFirstPrinterChangeNotification IMPORT "WINSPOOL.DRV" ALIAS "FindFirstPrinterChangeNotification" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL fdwFlags AS DWORD _                            ' __in DWORD fdwFlags
 , BYVAL fdwOptions AS DWORD _                          ' __in DWORD fdwOptions
 , OPTIONAL BYREF pPrinterNotifyOptions AS ANY _        ' __in_opt LPVOID pPrinterNotifyOptions
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION FindNextPrinterChangeNotification IMPORT "WINSPOOL.DRV" ALIAS "FindNextPrinterChangeNotification" ( _
   BYVAL hChange AS DWORD _                             ' __in HANDLE hChange
 , BYREF pdwChange AS DWORD _                           ' __out_opt PDWORD pdwChange
 , BYREF pPrinterNotifyOptions AS ANY _                 ' __in_opt LPVOID pPrinterNotifyOptions
 , OPTIONAL BYREF ppPrinterNotifyInfo AS ANY _          ' __out_opt LPVOID *ppPrinterNotifyInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FreePrinterNotifyInfo IMPORT "WINSPOOL.DRV" ALIAS "FreePrinterNotifyInfo" ( _
   BYREF pPrinterNotifyInfo AS PRINTER_NOTIFY_INFO _    ' __in PPRINTER_NOTIFY_INFO pPrinterNotifyInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FindClosePrinterChangeNotification IMPORT "WINSPOOL.DRV" ALIAS "FindClosePrinterChangeNotification" ( _
   BYVAL hChange AS DWORD _                             ' __in HANDLE hChange
 ) AS LONG                                              ' BOOL

%PRINTER_CHANGE_ADD_PRINTER             = &H00000001???
%PRINTER_CHANGE_SET_PRINTER             = &H00000002???
%PRINTER_CHANGE_DELETE_PRINTER          = &H00000004???
%PRINTER_CHANGE_PRINTER                 = &H000000FF???
%PRINTER_CHANGE_ADD_JOB                 = &H00000100???
%PRINTER_CHANGE_SET_JOB                 = &H00000200???
%PRINTER_CHANGE_DELETE_JOB              = &H00000400???
%PRINTER_CHANGE_WRITE_JOB               = &H00000800???
%PRINTER_CHANGE_JOB                     = &H0000FF00???
%PRINTER_CHANGE_ADD_FORM                = &H00010000???
%PRINTER_CHANGE_SET_FORM                = &H00020000???
%PRINTER_CHANGE_DELETE_FORM             = &H00040000???
%PRINTER_CHANGE_FORM                    = &H00070000???
%PRINTER_CHANGE_ADD_PORT                = &H00100000???
%PRINTER_CHANGE_CONFIGURE_PORT          = &H00200000???
%PRINTER_CHANGE_DELETE_PORT             = &H00400000???
%PRINTER_CHANGE_PORT                    = &H00700000???
%PRINTER_CHANGE_ADD_PRINT_PROCESSOR     = &H01000000???
%PRINTER_CHANGE_DELETE_PRINT_PROCESSOR  = &H04000000???
%PRINTER_CHANGE_PRINT_PROCESSOR         = &H07000000???
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%PRINTER_CHANGE_SERVER                  = &H08000000???
'#endif
%PRINTER_CHANGE_ADD_PRINTER_DRIVER      = &H10000000???
%PRINTER_CHANGE_DELETE_PRINTER_DRIVER   = &H40000000???
%PRINTER_CHANGE_PRINTER_DRIVER          = &H70000000???
%PRINTER_CHANGE_TIMEOUT                 = &H80000000???
%PRINTER_CHANGE_ALL                     = &H7777FFFF???

DECLARE FUNCTION PrinterMessageBoxA IMPORT "WINSPOOL.DRV" ALIAS "PrinterMessageBoxA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Error AS DWORD _                               ' __in DWORD Error
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pText AS ASCIIZ _                              ' __in_opt LPSTR pText
 , BYREF pCaption AS ASCIIZ _                           ' __in_opt LPSTR pCaption
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PrinterMessageBoxW IMPORT "WINSPOOL.DRV" ALIAS "PrinterMessageBoxW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Error AS DWORD _                               ' __in DWORD Error
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pText AS WSTRINGZ _                            ' __in_opt LPWSTR pText
 , BYREF pCaption AS WSTRINGZ _                         ' __in_opt LPWSTR pCaption
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO PrinterMessageBox = PrinterMessageBoxW
#ELSE
   MACRO PrinterMessageBox = PrinterMessageBoxA
#ENDIF

%PRINTER_ERROR_INFORMATION = &H80000000???
%PRINTER_ERROR_WARNING     = &H40000000???
%PRINTER_ERROR_SEVERE      = &H20000000???

%PRINTER_ERROR_OUTOFPAPER  = &H00000001???
%PRINTER_ERROR_JAM         = &H00000002???
%PRINTER_ERROR_OUTOFTONER  = &H00000004???

DECLARE FUNCTION ClosePrinter IMPORT "WINSPOOL.DRV" ALIAS "ClosePrinter" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddFormA LIB "WinSpool.drv" ALIAS "AddFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddFormA IMPORT "WINSPOOL.DRV" ALIAS "AddFormA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __in LPBYTE pForm
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddFormW LIB "WinSpool.drv" ALIAS "AddFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddFormW IMPORT "WINSPOOL.DRV" ALIAS "AddFormW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __in LPBYTE pForm
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddForm = AddFormW
#ELSE
   MACRO AddForm = AddFormA
#ENDIF

DECLARE FUNCTION DeleteFormA IMPORT "WINSPOOL.DRV" ALIAS "DeleteFormA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS ASCIIZ _                          ' __in LPSTR pFormName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteFormW IMPORT "WINSPOOL.DRV" ALIAS "DeleteFormW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS WSTRINGZ _                        ' __in LPWSTR pFormName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteForm = DeleteFormW
#ELSE
   MACRO DeleteForm = DeleteFormA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFormA LIB "WinSpool.drv" ALIAS "GetFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetFormA IMPORT "WINSPOOL.DRV" ALIAS "GetFormA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS ASCIIZ _                          ' __in LPSTR pFormName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __out LPBYTE pForm
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetFormW LIB "WinSpool.drv" ALIAS "GetFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetFormW IMPORT "WINSPOOL.DRV" ALIAS "GetFormW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS WSTRINGZ  _                       ' __in LPWSTR pFormName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __out LPBYTE pForm
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetForm = GetFormW
#ELSE
   MACRO GetForm = GetFormA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetFormA LIB "WinSpool.drv" ALIAS "SetFormA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetFormA IMPORT "WINSPOOL.DRV" ALIAS "SetFormA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS ASCIIZ _                          ' __in LPSTR pFormName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __in LPBYTE pForm
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetFormW LIB "WinSpool.drv" ALIAS "SetFormW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    pFormName      AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetFormW IMPORT "WINSPOOL.DRV" ALIAS "SetFormW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYREF pFormName AS WSTRINGZ _                        ' __in LPWSTR pFormName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __in LPBYTE pForm
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetForm = SetFormW
#ELSE
   MACRO SetForm = SetFormA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumFormsA LIB "WinSpool.drv" ALIAS "EnumFormsA" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumFormsA IMPORT "WINSPOOL.DRV" ALIAS "EnumFormsA" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __out LPBYTE pForm
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumFormsW LIB "WinSpool.drv" ALIAS "EnumFormsW" ( _
    BYVAL hPrinter AS DWORD, _  ' HANDLE
    BYVAL Level    AS DWORD, _
    BYVAL pForm    AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumFormsW IMPORT "WINSPOOL.DRV" ALIAS "EnumFormsW" ( _
   BYVAL hPrinter AS DWORD _                            ' __in HANDLE hPrinter
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pForm AS ANY _                                 ' __out LPBYTE pForm
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumForms = EnumFormsW
#ELSE
   MACRO EnumForms = EnumFormsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumMonitorsA LIB "WinSpool.drv" ALIAS "EnumMonitorsA" ( _
    pName          AS ASCIIZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pMonitor AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumMonitorsA IMPORT "WINSPOOL.DRV" ALIAS "EnumMonitorsA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pMonitor AS ANY  _                             ' __out LPBYTE pMonitor
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumMonitorsW LIB "WinSpool.drv" ALIAS "EnumMonitorsW" ( _
    pName          AS WSTRINGZ, _
    BYVAL Level    AS DWORD, _
    BYVAL pMonitor AS BYTE PTR, _
    BYVAL cbBuf    AS DWORD, _
    pcbNeeded      AS DWORD, _
    pcReturned     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumMonitorsW IMPORT "WINSPOOL.DRV" ALIAS "EnumMonitorsW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pMonitor AS ANY _                              ' __out LPBYTE pMonitor
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumMonitors = EnumMonitorsW
#ELSE
   MACRO EnumMonitors = EnumMonitorsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddMonitorA LIB "WinSpool.drv" ALIAS "AddMonitorA" ( _
    pName           AS ASCIIZ, _
    BYVAL Level     AS DWORD, _
    BYVAL pMonitors AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddMonitorA IMPORT "WINSPOOL.DRV" ALIAS "AddMonitorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , OPTIONAL BYREF pMonitorInfo AS ANY _                 ' __in_opt LPBYTE pMonitorInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddMonitorW LIB "WinSpool.drv" ALIAS "AddMonitorW" ( _
    pName           AS WSTRINGZ, _
    BYVAL Level     AS DWORD, _
    BYVAL pMonitors AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddMonitorW IMPORT "WINSPOOL.DRV" ALIAS "AddMonitorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , OPTIONAL BYREF pMonitorInfo AS ANY _                 ' __in_opt LPBYTE pMonitorInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddMonitor = AddMonitorW
#ELSE
   MACRO AddMonitor = AddMonitorA
#ENDIF

DECLARE FUNCTION DeleteMonitorA IMPORT "WINSPOOL.DRV" ALIAS "DeleteMonitorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pMonitorName AS ASCIIZ _                       ' __in LPSTR pMonitorName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteMonitorW IMPORT "WINSPOOL.DRV" ALIAS "DeleteMonitorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pMonitorName AS WSTRINGZ _                     ' __in LPWSTR pMonitorName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeleteMonitor = DeleteMonitorW
#ELSE
   MACRO DeleteMonitor = DeleteMonitorA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPortsA LIB "WinSpool.drv" ALIAS "EnumPortsA" ( _
    pName       AS ASCIIZ, _
    BYVAL Level AS DWORD, _
    BYVAL pPort AS BYTE PTR, _
    BYVAL cbBuf AS DWORD, _
    pcbNeeded   AS DWORD, _
    pcReturned  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPortsA IMPORT "WINSPOOL.DRV" ALIAS "EnumPortsA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPorts AS ANY _                                ' __out LPBYTE  pPorts
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumPortsW LIB "WinSpool.drv" ALIAS "EnumPortsW" ( _
    pName       AS WSTRINGZ, _
    BYVAL Level AS DWORD, _
    BYVAL pPort AS BYTE PTR, _
    BYVAL cbBuf AS DWORD, _
    pcbNeeded   AS DWORD, _
    pcReturned  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION EnumPortsW IMPORT "WINSPOOL.DRV" ALIAS "EnumPortsW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pPorts AS ANY _                                ' __out LPBYTE  pPorts
 , BYVAL cbBuf AS DWORD _                               ' __in DWORD cbBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out LPDWORD pcbNeeded
 , BYREF pcReturned AS DWORD _                          ' __out LPDWORD pcReturned
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumPorts = EnumPortsW
#ELSE
   MACRO EnumPorts = EnumPortsA
#ENDIF

DECLARE FUNCTION AddPortA IMPORT "WINSPOOL.DRV" ALIAS "AddPortA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pMonitorName AS ASCIIZ _                       ' __in LPSTR pMonitorName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddPortW IMPORT "WINSPOOL.DRV" ALIAS "AddPortW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pMonitorName AS WSTRINGZ _                     ' __in LPWSTR pMonitorName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AddPort = AddPortW
#ELSE
   MACRO AddPort = AddPortA
#ENDIF

DECLARE FUNCTION ConfigurePortA IMPORT "WINSPOOL.DRV" ALIAS "ConfigurePortA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pPortName AS ASCIIZ _                          ' __in LPSTR pPortName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConfigurePortW IMPORT "WINSPOOL.DRV" ALIAS "ConfigurePortW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pPortName AS WSTRINGZ _                        ' __in LPWSTR pPortName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ConfigurePort = ConfigurePortW
#ELSE
   MACRO ConfigurePort = ConfigurePortA
#ENDIF

DECLARE FUNCTION DeletePortA IMPORT "WINSPOOL.DRV" ALIAS "DeletePortA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pPortName AS ASCIIZ _                          ' __in LPSTR pPortName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePortW IMPORT "WINSPOOL.DRV" ALIAS "DeletePortW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pPortName AS WSTRINGZ _                        ' __in LPWSTR pPortName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePort = DeletePortW
#ELSE
   MACRO DeletePort = DeletePortA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION XcvDataW LIB "WinSpool.drv" ALIAS "XcvDataW" ( _
    BYVAL hXcv         AS DWORD, _  ' HANDLE
    pszDataName        AS WSTRINGZ, _
    BYVAL pInputData   AS BYTE PTR, _
    BYVAL cbInputData  AS DWORD, _
    BYVAL pOutputData  AS BYTE PTR, _
    BYVAL cbOutputData AS DWORD, _
    pcbOutputNeeded    AS DWORD, _
    pdwStatus          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION XcvDataW IMPORT "WINSPOOL.DRV" ALIAS "XcvDataW" ( _
   BYVAL hXcv AS DWORD _                                ' __in HANDLE hXcv
 , BYREF pszDataName AS WSTRINGZ _                      ' __in PCWSTR pszDataName
 , BYVAL pInputData AS BYTE PTR _                       ' __in PBYTE pInputData
 , BYVAL cbInputData AS DWORD _                         ' __in DWORD cbInputData
 , BYREF pOutputData AS ANY _                           ' __out PBYTE pOutputData
 , BYVAL cbOutputData AS DWORD _                        ' __in DWORD cbOutputData
 , BYREF pcbOutputNeeded AS DWORD _                     ' __out PDWORD pcbOutputNeeded
 , BYREF pdwStatus AS DWORD _                           ' __out PDWORD  pdwStatus
 ) AS LONG                                              ' BOOL
#ENDIF

'#define XcvData  XcvDataW
MACRO XcvData = XcvDataW

DECLARE FUNCTION GetDefaultPrinterA IMPORT "WINSPOOL.DRV" ALIAS "GetDefaultPrinterA" ( _
   BYREF pszBuffer AS ASCIIZ _                          ' __out LPSTR pszBuffer
 , BYREF pcchBuffer AS DWORD _                          ' __inout LPDWORD pcchBuffer
 ) AS LONG                                              ' LONG

DECLARE FUNCTION GetDefaultPrinterW IMPORT "WINSPOOL.DRV" ALIAS "GetDefaultPrinterW" ( _
   BYREF pszBuffer AS WSTRINGZ _                        ' __out LPWSTR pszBuffer
 , BYREF pcchBuffer AS DWORD _                          ' __inout LPDWORD pcchBuffer
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO GetDefaultPrinter = GetDefaultPrinterW
#ELSE
   MACRO GetDefaultPrinter = GetDefaultPrinterA
#ENDIF

DECLARE FUNCTION SetDefaultPrinterA IMPORT "WINSPOOL.DRV" ALIAS "SetDefaultPrinterA" ( _
   BYREF pszPrinter AS ASCIIZ _                         ' __in LPCSTR pszPrinter
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetDefaultPrinterW IMPORT "WINSPOOL.DRV" ALIAS "SetDefaultPrinterW" ( _
   BYREF pszPrinter AS WSTRINGZ _                       ' __in LPCWSTR pszPrinter
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetDefaultPrinter = SetDefaultPrinterW
#ELSE
   MACRO SetDefaultPrinter = SetDefaultPrinterA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPortA LIB "WinSpool.drv" ALIAS "SetPortA" ( _
    pName           AS ASCIIZ, _
    pPortName       AS ASCIIZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL pPortInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetPortA IMPORT "WINSPOOL.DRV" ALIAS "SetPortA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pPortName AS ASCIIZ _                          ' __in LPSTR pPortName
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYREF pPortInfo AS ANY _                             ' __in LPBYTE pPortInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetPortW LIB "WinSpool.drv" ALIAS "SetPortW" ( _
    pName           AS WSTRINGZ, _
    pPortName       AS WSTRINGZ, _
    BYVAL dwLevel   AS DWORD, _
    BYVAL pPortInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetPortW IMPORT "WINSPOOL.DRV" ALIAS "SetPortW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pPortName AS WSTRINGZ _                        ' __in LPWSTR pPortName
 , BYVAL dwLevel AS DWORD _                             ' __in DWORD dwLevel
 , BYREF pPortInfo AS ANY _                             ' __in LPBYTE pPortInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetPort = SetPortW
#ELSE
   MACRO SetPort = SetPortA
#ENDIF

DECLARE FUNCTION AddPrinterConnectionA IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterConnectionA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddPrinterConnectionW IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterConnectionW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AddPrinterConnection = AddPrinterConnectionW
#ELSE
   MACRO AddPrinterConnection = AddPrinterConnectionA
#ENDIF

DECLARE FUNCTION DeletePrinterConnectionA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterConnectionA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePrinterConnectionW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterConnectionW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePrinterConnection = DeletePrinterConnectionW
#ELSE
   MACRO DeletePrinterConnection = DeletePrinterConnectionA
#ENDIF

DECLARE FUNCTION ConnectToPrinterDlg IMPORT "WINSPOOL.DRV" ALIAS "ConnectToPrinterDlg" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HANDLE

' // Size = 12 bytes
TYPE PROVIDOR_INFO_1A DWORD
   pName        AS ASCIIZ PTR   ' LPSTR
   pEnvironment AS ASCIIZ PTR   ' LPSTR
   pDLLName     AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE PROVIDOR_INFO_1W DWORD
   pName        AS WSTRINGZ PTR   ' LPWSTR
   pEnvironment AS WSTRINGZ PTR   ' LPWSTR
   pDLLName     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PROVIDOR_INFO_1 = PROVIDOR_INFO_1W
#ELSE
   MACRO PROVIDOR_INFO_1 = PROVIDOR_INFO_1A
#ENDIF

' // Size = 4 bytes
TYPE PROVIDOR_INFO_2A DWORD
   pOrder AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE PROVIDOR_INFO_2W DWORD
   pOrder AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PROVIDOR_INFO_2 = PROVIDOR_INFO_2W
#ELSE
   MACRO PROVIDOR_INFO_2 = PROVIDOR_INFO_2A
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrintProvidorA LIB "WinSpool.drv" _
    ALIAS "AddPrintProvidorA" ( _
    pName               AS ASCIIZ, _
    BYVAL level         AS DWORD, _
    BYVAL pProvidorInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrintProvidorA IMPORT "WINSPOOL.DRV" ALIAS "AddPrintProvidorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pProvidorInfo AS ANY _                         ' __in LPBYTE pProvidorInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddPrintProvidorW LIB "WinSpool.drv" _
    ALIAS "AddPrintProvidorW" ( _
    pName               AS WSTRINGZ, _
    BYVAL level         AS DWORD, _
    BYVAL pProvidorInfo AS BYTE PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION AddPrintProvidorW IMPORT "WINSPOOL.DRV" ALIAS "AddPrintProvidorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF pProvidorInfo AS ANY _                         ' __in LPBYTE pProvidorInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AddPrintProvidor = AddPrintProvidorW
#ELSE
   MACRO AddPrintProvidor = AddPrintProvidorA
#ENDIF

DECLARE FUNCTION DeletePrintProvidorA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrintProvidorA" ( _
   BYREF pName AS ASCIIZ _                              ' __in LPSTR pName
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR pEnvironment
 , BYREF pPrintProvidorName AS ASCIIZ _                 ' __in LPSTR pPrintProvidorName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeletePrintProvidorW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrintProvidorW" ( _
   BYREF pName AS WSTRINGZ _                            ' __in LPWSTR pName
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR pEnvironment
 , BYREF pPrintProvidorName AS WSTRINGZ _               ' __in LPWSTR pPrintProvidorName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DeletePrintProvidor = DeletePrintProvidorW
#ELSE
   MACRO DeletePrintProvidor = DeletePrintProvidorA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
DECLARE FUNCTION IsValidDevmodeA IMPORT "WINSPOOL.DRV" ALIAS "IsValidDevmodeA" ( _
   BYREF pDevmode AS DEVMODEA _                         ' __in PDEVMODEA pDevmode
 , BYVAL DevmodeSize AS DWORD _                         ' __in size_t DevmodeSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsValidDevmodeW IMPORT "WINSPOOL.DRV" ALIAS "IsValidDevmodeW" ( _
   BYREF pDevmode AS DEVMODEW  _                        ' __in PDEVMODEW pDevmode
 , BYVAL DevmodeSize AS DWORD _                         ' __in size_t DevmodeSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsValidDevmode = IsValidDevmodeW
#ELSE
   MACRO IsValidDevmode = IsValidDevmodeA
#ENDIF
'#endif // (NTDDI_VERSION >= NTDDI_WINXPSP2)

'/*
' * SetPrinterData and GetPrinterData Server Handle Key values
' */

'#define    SPLREG_DEFAULT_SPOOL_DIRECTORY             TEXT("DefaultSpoolDirectory")
'#define    SPLREG_PORT_THREAD_PRIORITY_DEFAULT        TEXT("PortThreadPriorityDefault")
'#define    SPLREG_PORT_THREAD_PRIORITY                TEXT("PortThreadPriority")
'#define    SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT   TEXT("SchedulerThreadPriorityDefault")
'#define    SPLREG_SCHEDULER_THREAD_PRIORITY           TEXT("SchedulerThreadPriority")
'#define    SPLREG_BEEP_ENABLED                        TEXT("BeepEnabled")
'#define    SPLREG_NET_POPUP                           TEXT("NetPopup")
'#define    SPLREG_RETRY_POPUP                         TEXT("RetryPopup")
'#define    SPLREG_NET_POPUP_TO_COMPUTER               TEXT("NetPopupToComputer")
'#define    SPLREG_EVENT_LOG                           TEXT("EventLog")
'#define    SPLREG_MAJOR_VERSION                       TEXT("MajorVersion")
'#define    SPLREG_MINOR_VERSION                       TEXT("MinorVersion")
'#define    SPLREG_ARCHITECTURE                        TEXT("Architecture")

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'    #define    SPLREG_OS_VERSION                      TEXT("OSVersion")
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#define    SPLREG_OS_VERSIONEX                        TEXT("OSVersionEx")
'#define    SPLREG_DS_PRESENT                          TEXT("DsPresent")
'#define    SPLREG_DS_PRESENT_FOR_USER                 TEXT("DsPresentForUser")
'#define    SPLREG_REMOTE_FAX                          TEXT("RemoteFax")
'#define    SPLREG_RESTART_JOB_ON_POOL_ERROR           TEXT("RestartJobOnPoolError")
'#define    SPLREG_RESTART_JOB_ON_POOL_ENABLED         TEXT("RestartJobOnPoolEnabled")
'#define    SPLREG_DNS_MACHINE_NAME                    TEXT("DNSMachineName")

'#if ((OSVER(NTDDI_VERSION) == NTDDI_WINXP) && (SPVER(NTDDI_VERSION) >= 2) || \
'     (NTDDI_VERSION >= NTDDI_WS03SP1))
'    #define    SPLREG_ALLOW_USER_MANAGEFORMS          TEXT("AllowUserManageForms")
'#endif // ((OSVER(NTDDI_VERSION) == NTDDI_WINXP) ...

'#if (NTDDI_VERSION >= NTDDI_WS03)
'    #define    SPLREG_WEBSHAREMGMT                    TEXT("WebShareMgmt")
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

$SPLREG_DEFAULT_SPOOL_DIRECTORY             = "DefaultSpoolDirectory"
$$SPLREG_DEFAULT_SPOOL_DIRECTORY            = "DefaultSpoolDirectory"$$
$SPLREG_PORT_THREAD_PRIORITY_DEFAULT        = "PortThreadPriorityDefault"
$$SPLREG_PORT_THREAD_PRIORITY_DEFAULT       = "PortThreadPriorityDefault"$$
$SPLREG_PORT_THREAD_PRIORITY                = "PortThreadPriority"
$$SPLREG_PORT_THREAD_PRIORITY               = "PortThreadPriority"$$
$SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT   = "SchedulerThreadPriorityDefault"
$$SPLREG_SCHEDULER_THREAD_PRIORITY_DEFAULT  = "SchedulerThreadPriorityDefault"$$
$SPLREG_SCHEDULER_THREAD_PRIORITY           = "SchedulerThreadPriority"
$$SPLREG_SCHEDULER_THREAD_PRIORITY          = "SchedulerThreadPriority"$$
$SPLREG_BEEP_ENABLED                        = "BeepEnabled"
$$SPLREG_BEEP_ENABLED                       = "BeepEnabled"$$
$SPLREG_NET_POPUP                           = "NetPopup"
$$SPLREG_NET_POPUP                          = "NetPopup"$$
$SPLREG_RETRY_POPUP                         = "RetryPopup"
$$SPLREG_RETRY_POPUP                        = "RetryPopup"$$
$SPLREG_NET_POPUP_TO_COMPUTER               = "NetPopupToComputer"
$$SPLREG_NET_POPUP_TO_COMPUTER              = "NetPopupToComputer"$$
$SPLREG_EVENT_LOG                           = "EventLog"
$$SPLREG_EVENT_LOG                          = "EventLog"$$
$SPLREG_MAJOR_VERSION                       = "MajorVersion"
$$SPLREG_MAJOR_VERSION                      = "MajorVersion"$$
$SPLREG_MINOR_VERSION                       = "MinorVersion"
$$SPLREG_MINOR_VERSION                      = "MinorVersion"$$
$SPLREG_ARCHITECTURE                        = "Architecture"
$$SPLREG_ARCHITECTURE                       = "Architecture"$$
'#if (NTDDI_VERSION >= NTDDI_WINXP)
$SPLREG_OS_VERSION                          = "OSVersion"
$$SPLREG_OS_VERSION                         = "OSVersion"$$
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)
$SPLREG_OS_VERSIONEX                        = "OSVersionEx"
$$SPLREG_OS_VERSIONEX                       = "OSVersionEx"$$
$SPLREG_DS_PRESENT                          = "DsPresent"
$$SPLREG_DS_PRESENT                         = "DsPresent"$$
$SPLREG_DS_PRESENT_FOR_USER                 = "DsPresentForUser"
$$SPLREG_DS_PRESENT_FOR_USER                = "DsPresentForUser"$$
$SPLREG_REMOTE_FAX                          = "RemoteFax"
$$SPLREG_REMOTE_FAX                         = "RemoteFax"$$
$SPLREG_RESTART_JOB_ON_POOL_ERROR           = "RestartJobOnPoolError"
$$SPLREG_RESTART_JOB_ON_POOL_ERROR          = "RestartJobOnPoolError"$$
$SPLREG_RESTART_JOB_ON_POOL_ENABLED         = "RestartJobOnPoolEnabled"
$$SPLREG_RESTART_JOB_ON_POOL_ENABLED        = "RestartJobOnPoolEnabled"$$
$SPLREG_DNS_MACHINE_NAME                    = "DNSMachineName"
$$SPLREG_DNS_MACHINE_NAME                   = "DNSMachineName"$$
'#if ((OSVER(NTDDI_VERSION) == NTDDI_WINXP) && (SPVER(NTDDI_VERSION) >= 2) || \
'     (NTDDI_VERSION >= NTDDI_WS03SP1))
$SPLREG_ALLOW_USER_MANAGEFORMS              = "AllowUserManageForms"
$$SPLREG_ALLOW_USER_MANAGEFORMS             = "AllowUserManageForms"$$
'#endif // ((OSVER(NTDDI_VERSION) == NTDDI_WINXP) ...
'#if (NTDDI_VERSION >= NTDDI_WS03)
$SPLREG_WEBSHAREMGMT                        = "WebShareMgmt"
$$SPLREG_WEBSHAREMGMT                       = "WebShareMgmt"$$
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'#define    SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR           L'\\'
'#define    SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                     TEXT("PrintDriverIsolationGroups")
'#define    SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE        TEXT("PrintDriverIsolationTimeBeforeRecycle")
'#define    SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE TEXT("PrintDriverIsolationMaxobjsBeforeRecycle")
'#define    SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT               TEXT("PrintDriverIsolationIdleTimeout")
'#define    SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY           TEXT("PrintDriverIsolationExecutionPolicy")
'#define    SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY            TEXT("PrintDriverIsolationOverrideCompat")
$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR            = "\"
$$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS_SEPARATOR           = "\"$$
$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                      = "PrintDriverIsolationGroups"
$$SPLREG_PRINT_DRIVER_ISOLATION_GROUPS                     = "PrintDriverIsolationGroups"$$
$SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE         = "PrintDriverIsolationTimeBeforeRecycle"
$$SPLREG_PRINT_DRIVER_ISOLATION_TIME_BEFORE_RECYCLE        = "PrintDriverIsolationTimeBeforeRecycle"$$
$SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE  = "PrintDriverIsolationMaxobjsBeforeRecycle"
$$SPLREG_PRINT_DRIVER_ISOLATION_MAX_OBJECTS_BEFORE_RECYCLE = "PrintDriverIsolationMaxobjsBeforeRecycle"$$
$SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT                = "PrintDriverIsolationIdleTimeout"
$$SPLREG_PRINT_DRIVER_ISOLATION_IDLE_TIMEOUT               = "PrintDriverIsolationIdleTimeout"$$
$SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY            = "PrintDriverIsolationExecutionPolicy"
$$SPLREG_PRINT_DRIVER_ISOLATION_EXECUTION_POLICY           = "PrintDriverIsolationExecutionPolicy"$$
$SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY             = "PrintDriverIsolationOverrideCompat"
$$SPLREG_PRINT_DRIVER_ISOLATION_OVERRIDE_POLICY            = "PrintDriverIsolationOverrideCompat"$$
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

%SERVER_ACCESS_ADMINISTER  = &H00000001???
%SERVER_ACCESS_ENUMERATE   = &H00000002???

%PRINTER_ACCESS_ADMINISTER = &H00000004???
%PRINTER_ACCESS_USE        = &H00000008???

%JOB_ACCESS_ADMINISTER     = &H00000010???
'#if ((NTDDI_VERSION >= NTDDI_WINXPSP1) || \
'     ((OSVER(NTDDI_VERSION) == NTDDI_WIN2K) && (SPVER(NTDDI_VERSION) >= 3)))
%JOB_ACCESS_READ           = &H00000020???
'#endif // ((NTDDI_VERSION >= NTDDI_WINXPSP1) ...

'/*
' * Access rights for print servers
' */

%SERVER_READ       = %STANDARD_RIGHTS_READ OR _
                     %SERVER_ACCESS_ENUMERATE

%SERVER_WRITE      = %STANDARD_RIGHTS_WRITE OR _
                     %SERVER_ACCESS_ADMINISTER OR _
                     %SERVER_ACCESS_ENUMERATE

%SERVER_EXECUTE    = %STANDARD_RIGHTS_EXECUTE OR _
                     %SERVER_ACCESS_ENUMERATE

%SERVER_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR _
                     %SERVER_ACCESS_ADMINISTER OR _
                     %SERVER_ACCESS_ENUMERATE

'/*
' * Access rights for printers
' */

%PRINTER_READ       = %STANDARD_RIGHTS_READ OR _
                      %PRINTER_ACCESS_USE

%PRINTER_WRITE      = %STANDARD_RIGHTS_WRITE OR _
                      %PRINTER_ACCESS_USE

%PRINTER_EXECUTE    = %STANDARD_RIGHTS_EXECUTE OR _
                      %PRINTER_ACCESS_USE

%PRINTER_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR _
                      %PRINTER_ACCESS_ADMINISTER OR _
                      %PRINTER_ACCESS_USE

'/*
' * Access rights for jobs
' */

'#if ((NTDDI_VERSION >= NTDDI_WINXPSP1) || \
'     ((OSVER(NTDDI_VERSION) == NTDDI_WIN2K) && (SPVER(NTDDI_VERSION) >= 3)))
'    #define JOB_READ               (STANDARD_RIGHTS_READ        |\
'                                    JOB_ACCESS_READ)
'#else
'    #define JOB_READ               (STANDARD_RIGHTS_READ        |\
'                                    JOB_ACCESS_ADMINISTER)

'#endif
%JOB_READ          = %STANDARD_RIGHTS_READ OR _
                     %JOB_ACCESS_READ

%JOB_WRITE         = %STANDARD_RIGHTS_WRITE OR _
                     %JOB_ACCESS_ADMINISTER

%JOB_EXECUTE       = %STANDARD_RIGHTS_EXECUTE OR _
                     %JOB_ACCESS_ADMINISTER

'#if ((NTDDI_VERSION >= NTDDI_WINXPSP1) || \
'     ((OSVER(NTDDI_VERSION) == NTDDI_WIN2K) && (SPVER(NTDDI_VERSION) >= 3)))
'    #define JOB_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED    |\
'                                    JOB_ACCESS_ADMINISTER       |\
'                                    JOB_ACCESS_READ)
'#else
'    #define JOB_ALL_ACCESS         (STANDARD_RIGHTS_REQUIRED    |\
'                                    JOB_ACCESS_ADMINISTER)
'#endif

%JOB_ALL_ACCESS    = %STANDARD_RIGHTS_REQUIRED OR _
                     %JOB_ACCESS_ADMINISTER OR _
                     %JOB_ACCESS_READ

'/*
' * DS Print-Queue property tables
' */

'// Predefined Registry Keys used by Set/GetPrinterDataEx
'#define SPLDS_SPOOLER_KEY                       TEXT("DsSpooler")
'#define SPLDS_DRIVER_KEY                        TEXT("DsDriver")
'#define SPLDS_USER_KEY                          TEXT("DsUser")

$SPLDS_SPOOLER_KEY                       = "DsSpooler"
$$SPLDS_SPOOLER_KEY                      = "DsSpooler"$$
$SPLDS_DRIVER_KEY                        = "DsDriver"
$$SPLDS_DRIVER_KEY                       = "DsDriver"$$
$SPLDS_USER_KEY                          = "DsUser"
$$SPLDS_USER_KEY                         = "DsUser"$$

'// DS Print-Queue properties

'#define SPLDS_ASSET_NUMBER                      TEXT("assetNumber")
'#define SPLDS_BYTES_PER_MINUTE                  TEXT("bytesPerMinute")
'#define SPLDS_DESCRIPTION                       TEXT("description")
'#define SPLDS_DRIVER_NAME                       TEXT("driverName")
'#define SPLDS_DRIVER_VERSION                    TEXT("driverVersion")
'#define SPLDS_LOCATION                          TEXT("location")
'#define SPLDS_PORT_NAME                         TEXT("portName")
'#define SPLDS_PRINT_ATTRIBUTES                  TEXT("printAttributes")
'#define SPLDS_PRINT_BIN_NAMES                   TEXT("printBinNames")
'#define SPLDS_PRINT_COLLATE                     TEXT("printCollate")
'#define SPLDS_PRINT_COLOR                       TEXT("printColor")
'#define SPLDS_PRINT_DUPLEX_SUPPORTED            TEXT("printDuplexSupported")
'#define SPLDS_PRINT_END_TIME                    TEXT("printEndTime")
'#define SPLDS_PRINTER_CLASS                     TEXT("printQueue")
'#define SPLDS_PRINTER_NAME                      TEXT("printerName")
'#define SPLDS_PRINT_KEEP_PRINTED_JOBS           TEXT("printKeepPrintedJobs")
'#define SPLDS_PRINT_LANGUAGE                    TEXT("printLanguage")
'#define SPLDS_PRINT_MAC_ADDRESS                 TEXT("printMACAddress")
'#define SPLDS_PRINT_MAX_X_EXTENT                TEXT("printMaxXExtent")
'#define SPLDS_PRINT_MAX_Y_EXTENT                TEXT("printMaxYExtent")
'#define SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    TEXT("printMaxResolutionSupported")
'#define SPLDS_PRINT_MEDIA_READY                 TEXT("printMediaReady")
'#define SPLDS_PRINT_MEDIA_SUPPORTED             TEXT("printMediaSupported")
'#define SPLDS_PRINT_MEMORY                      TEXT("printMemory")
'#define SPLDS_PRINT_MIN_X_EXTENT                TEXT("printMinXExtent")
'#define SPLDS_PRINT_MIN_Y_EXTENT                TEXT("printMinYExtent")
'#define SPLDS_PRINT_NETWORK_ADDRESS             TEXT("printNetworkAddress")
'#define SPLDS_PRINT_NOTIFY                      TEXT("printNotify")
'#define SPLDS_PRINT_NUMBER_UP                   TEXT("printNumberUp")
'#define SPLDS_PRINT_ORIENTATIONS_SUPPORTED      TEXT("printOrientationsSupported")
'#define SPLDS_PRINT_OWNER                       TEXT("printOwner")
'#define SPLDS_PRINT_PAGES_PER_MINUTE            TEXT("printPagesPerMinute")
'#define SPLDS_PRINT_RATE                        TEXT("printRate")
'#define SPLDS_PRINT_RATE_UNIT                   TEXT("printRateUnit")
'#define SPLDS_PRINT_SEPARATOR_FILE              TEXT("printSeparatorFile")
'#define SPLDS_PRINT_SHARE_NAME                  TEXT("printShareName")
'#define SPLDS_PRINT_SPOOLING                    TEXT("printSpooling")
'#define SPLDS_PRINT_STAPLING_SUPPORTED          TEXT("printStaplingSupported")
'#define SPLDS_PRINT_START_TIME                  TEXT("printStartTime")
'#define SPLDS_PRINT_STATUS                      TEXT("printStatus")
'#define SPLDS_PRIORITY                          TEXT("priority")
'#define SPLDS_SERVER_NAME                       TEXT("serverName")
'#define SPLDS_SHORT_SERVER_NAME                 TEXT("shortServerName")
'#define SPLDS_UNC_NAME                          TEXT("uNCName")
'#define SPLDS_URL                               TEXT("url")
'#define SPLDS_FLAGS                             TEXT("flags")
'#define SPLDS_VERSION_NUMBER                    TEXT("versionNumber")

$SPLDS_ASSET_NUMBER                      = "assetNumber"
$SPLDS_BYTES_PER_MINUTE                  = "bytesPerMinute"
$SPLDS_DESCRIPTION                       = "description"
$SPLDS_DRIVER_NAME                       = "driverName"
$SPLDS_DRIVER_VERSION                    = "driverVersion"
$SPLDS_LOCATION                          = "location"
$SPLDS_PORT_NAME                         = "portName"
$SPLDS_PRINT_ATTRIBUTES                  = "printAttributes"
$SPLDS_PRINT_BIN_NAMES                   = "printBinNames"
$SPLDS_PRINT_COLLATE                     = "printCollate"
$SPLDS_PRINT_COLOR                       = "printColor"
$SPLDS_PRINT_DUPLEX_SUPPORTED            = "printDuplexSupported"
$SPLDS_PRINT_END_TIME                    = "printEndTime"
$SPLDS_PRINTER_CLASS                     = "printQueue"
$SPLDS_PRINTER_NAME                      = "printerName"
$SPLDS_PRINT_KEEP_PRINTED_JOBS           = "printKeepPrintedJobs"
$SPLDS_PRINT_LANGUAGE                    = "printLanguage"
$SPLDS_PRINT_MAC_ADDRESS                 = "printMACAddress"
$SPLDS_PRINT_MAX_X_EXTENT                = "printMaxXExtent"
$SPLDS_PRINT_MAX_Y_EXTENT                = "printMaxYExtent"
$SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED    = "printMaxResolutionSupported"
$SPLDS_PRINT_MEDIA_READY                 = "printMediaReady"
$SPLDS_PRINT_MEDIA_SUPPORTED             = "printMediaSupported"
$SPLDS_PRINT_MEMORY                      = "printMemory"
$SPLDS_PRINT_MIN_X_EXTENT                = "printMinXExtent"
$SPLDS_PRINT_MIN_Y_EXTENT                = "printMinYExtent"
$SPLDS_PRINT_NETWORK_ADDRESS             = "printNetworkAddress"
$SPLDS_PRINT_NOTIFY                      = "printNotify"
$SPLDS_PRINT_NUMBER_UP                   = "printNumberUp"
$SPLDS_PRINT_ORIENTATIONS_SUPPORTED      = "printOrientationsSupported"
$SPLDS_PRINT_OWNER                       = "printOwner"
$SPLDS_PRINT_PAGES_PER_MINUTE            = "printPagesPerMinute"
$SPLDS_PRINT_RATE                        = "printRate"
$SPLDS_PRINT_RATE_UNIT                   = "printRateUnit"
$SPLDS_PRINT_SEPARATOR_FILE              = "printSeparatorFile"
$SPLDS_PRINT_SHARE_NAME                  = "printShareName"
$SPLDS_PRINT_SPOOLING                    = "printSpooling"
$SPLDS_PRINT_STAPLING_SUPPORTED          = "printStaplingSupported"
$SPLDS_PRINT_START_TIME                  = "printStartTime"
$SPLDS_PRINT_STATUS                      = "printStatus"
$SPLDS_PRIORITY                          = "priority"
$SPLDS_SERVER_NAME                       = "serverName"
$SPLDS_SHORT_SERVER_NAME                 = "shortServerName"
$SPLDS_UNC_NAME                          = "uNCName"
$SPLDS_URL                               = "url"
$SPLDS_FLAGS                             = "flags"
$SPLDS_VERSION_NUMBER                    = "versionNumber"

$$SPLDS_ASSET_NUMBER                     = "assetNumber"$$
$$SPLDS_BYTES_PER_MINUTE                 = "bytesPerMinute"$$
$$SPLDS_DESCRIPTION                      = "description"$$
$$SPLDS_DRIVER_NAME                      = "driverName"$$
$$SPLDS_DRIVER_VERSION                   = "driverVersion"$$
$$SPLDS_LOCATION                         = "location"$$
$$SPLDS_PORT_NAME                        = "portName"$$
$$SPLDS_PRINT_ATTRIBUTES                 = "printAttributes"$$
$$SPLDS_PRINT_BIN_NAMES                  = "printBinNames"$$
$$SPLDS_PRINT_COLLATE                    = "printCollate"$$
$$SPLDS_PRINT_COLOR                      = "printColor"$$
$$SPLDS_PRINT_DUPLEX_SUPPORTED           = "printDuplexSupported"$$
$$SPLDS_PRINT_END_TIME                   = "printEndTime"$$
$$SPLDS_PRINTER_CLASS                    = "printQueue"$$
$$SPLDS_PRINTER_NAME                     = "printerName"$$
$$SPLDS_PRINT_KEEP_PRINTED_JOBS          = "printKeepPrintedJobs"$$
$$SPLDS_PRINT_LANGUAGE                   = "printLanguage"$$
$$SPLDS_PRINT_MAC_ADDRESS                = "printMACAddress"$$
$$SPLDS_PRINT_MAX_X_EXTENT               = "printMaxXExtent"$$
$$SPLDS_PRINT_MAX_Y_EXTENT               = "printMaxYExtent"$$
$$SPLDS_PRINT_MAX_RESOLUTION_SUPPORTED   = "printMaxResolutionSupported"$$
$$SPLDS_PRINT_MEDIA_READY                = "printMediaReady"$$
$$SPLDS_PRINT_MEDIA_SUPPORTED            = "printMediaSupported"$$
$$SPLDS_PRINT_MEMORY                     = "printMemory"$$
$$SPLDS_PRINT_MIN_X_EXTENT               = "printMinXExtent"$$
$$SPLDS_PRINT_MIN_Y_EXTENT               = "printMinYExtent"$$
$$SPLDS_PRINT_NETWORK_ADDRESS            = "printNetworkAddress"$$
$$SPLDS_PRINT_NOTIFY                     = "printNotify"$$
$$SPLDS_PRINT_NUMBER_UP                  = "printNumberUp"$$
$$SPLDS_PRINT_ORIENTATIONS_SUPPORTED     = "printOrientationsSupported"$$
$$SPLDS_PRINT_OWNER                      = "printOwner"$$
$$SPLDS_PRINT_PAGES_PER_MINUTE           = "printPagesPerMinute"$$
$$SPLDS_PRINT_RATE                       = "printRate"$$
$$SPLDS_PRINT_RATE_UNIT                  = "printRateUnit"$$
$$SPLDS_PRINT_SEPARATOR_FILE             = "printSeparatorFile"$$
$$SPLDS_PRINT_SHARE_NAME                 = "printShareName"$$
$$SPLDS_PRINT_SPOOLING                   = "printSpooling"$$
$$SPLDS_PRINT_STAPLING_SUPPORTED         = "printStaplingSupported"$$
$$SPLDS_PRINT_START_TIME                 = "printStartTime"$$
$$SPLDS_PRINT_STATUS                     = "printStatus"$$
$$SPLDS_PRIORITY                         = "priority"$$
$$SPLDS_SERVER_NAME                      = "serverName"$$
$$SPLDS_SHORT_SERVER_NAME                = "shortServerName"$$
$$SPLDS_UNC_NAME                         = "uNCName"$$
$$SPLDS_URL                              = "url"$$
$$SPLDS_FLAGS                            = "flags"$$
$$SPLDS_VERSION_NUMBER                   = "versionNumber"$$

'/*
'    -- Additional Print-Queue properties --

'    These properties are not defined in the default Directory Services Schema,
'    but should be used when extending the Schema so a consistent interface is maintained.

'*/

'#define SPLDS_PRINTER_NAME_ALIASES              TEXT("printerNameAliases")      // MULTI_SZ
'#define SPLDS_PRINTER_LOCATIONS                 TEXT("printerLocations")        // MULTI_SZ
'#define SPLDS_PRINTER_MODEL                     TEXT("printerModel")            // SZ

$SPLDS_PRINTER_NAME_ALIASES              = "printerNameAliases"      ' MULTI_SZ
$SPLDS_PRINTER_LOCATIONS                 = "printerLocations"        ' MULTI_SZ
$SPLDS_PRINTER_MODEL                     = "printerModel"            ' SZ

$$SPLDS_PRINTER_NAME_ALIASES             = "printerNameAliases"$$      ' MULTI_SZ
$$SPLDS_PRINTER_LOCATIONS                = "printerLocations"$$        ' MULTI_SZ
$$SPLDS_PRINTER_MODEL                    = "printerModel"$$            ' SZ

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'//
'// Printer option flags that can be passed to OpenPrinter2 for
'// controlling whether the cached or non cached handle is used.
'//
' enum _PRINTER_OPTION_FLAGS
%PRINTER_OPTION_NO_CACHE       =  1   ' 1 << 0
%PRINTER_OPTION_CACHE          =  2   ' 1 << 1
%PRINTER_OPTION_CLIENT_CHANGE  =  4   ' 1 << 2
%PRINTER_OPTION_NO_CLIENT_DATA =  8   ' 1 << 3

' // Size = 8 bytes
TYPE PRINTER_OPTIONSA DWORD
   cbSize  AS DWORD   ' UINT
   dwFlags AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE PRINTER_OPTIONSW DWORD
   cbSize  AS DWORD   ' UINT
   dwFlags AS DWORD   ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_OPTIONS = PRINTER_OPTIONSW
#ELSE
   MACRO PRINTER_OPTIONS = PRINTER_OPTIONSA
#ENDIF

DECLARE FUNCTION OpenPrinter2A IMPORT "WINSPOOL.DRV" ALIAS "OpenPrinter2A" ( _
   BYREF pPrinterName AS ASCIIZ _                       ' __in_opt LPCSTR             pPrinterName
 , BYREF phPrinter AS DWORD _                           ' __out    LPHANDLE           phPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSA _       ' __in_opt PPRINTER_DEFAULTSA pDefault
 , OPTIONAL BYREF pOptions AS PRINTER_OPTIONSA _        ' __in_opt PPRINTER_OPTIONSA  pOptions
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OpenPrinter2W IMPORT "WINSPOOL.DRV" ALIAS "OpenPrinter2W" ( _
   BYREF pPrinterName AS WSTRINGZ _                     ' __in_opt LPCWSTR            pPrinterName
 , BYREF phPrinter AS DWORD _                           ' __out    LPHANDLE           phPrinter
 , OPTIONAL BYREF pDefault AS PRINTER_DEFAULTSW _       ' __in_opt PPRINTER_DEFAULTSW pDefault
 , OPTIONAL BYREF pOptions AS PRINTER_OPTIONSW _        ' __in_opt PPRINTER_OPTIONSW  pOptions
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OpenPrinter2 = OpenPrinter2W
#ELSE
   MACRO OpenPrinter2 = OpenPrinter2A
#ENDIF

%PRINTER_CONNECTION_MISMATCH             = &H00000020???     ' // printer should be mismatched
%PRINTER_CONNECTION_NO_UI                = &H00000040???     ' // Fail call if UI is needed in order to install printer driver

' // Size = 8 bytes
TYPE PRINTER_CONNECTION_INFO_1A DWORD
   dwFlags       AS DWORD        ' DWORD
   pszDriverName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 8 bytes
TYPE PRINTER_CONNECTION_INFO_1W DWORD
   dwFlags       AS DWORD          ' DWORD
   pszDriverName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO PRINTER_CONNECTION_INFO_1 = PRINTER_CONNECTION_INFO_1W
#ELSE
   MACRO PRINTER_CONNECTION_INFO_1 = PRINTER_CONNECTION_INFO_1A
#ENDIF

DECLARE FUNCTION AddPrinterConnection2A IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterConnection2A" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND    hWnd
 , BYREF pszName AS ASCIIZ _                            ' __in     LPCSTR  pszName
 , BYVAL dwLevel AS DWORD _                             ' __in     DWORD   dwLevel
 , BYREF pConnectionInfo AS ANY _                       ' __in     PVOID   pConnectionInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AddPrinterConnection2W IMPORT "WINSPOOL.DRV" ALIAS "AddPrinterConnection2W" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND    hWnd
 , BYREF pszName AS WSTRINGZ _                          ' __in     LPCWSTR pszName
 , BYVAL dwLevel AS DWORD _                             ' __in     DWORD   dwLevel
 , BYREF pConnectionInfo AS ANY _                       ' __in     PVOID   pConnectionInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AddPrinterConnection2 = AddPrinterConnection2W
#ELSE
   MACRO AddPrinterConnection2 = AddPrinterConnection2A
#ENDIF

'//
'// Unless IPDFP_COPY_ALL_FILES is specified it is always
'// assumed that we use the latest files (APD_COPY_NEW_FILES)
'//
%IPDFP_COPY_ALL_FILES         = &H00000001???

DECLARE FUNCTION InstallPrinterDriverFromPackageA IMPORT "WINSPOOL.DRV" ALIAS "InstallPrinterDriverFromPackageA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt   LPCSTR    pszServer
 , BYREF pszInfPath AS ASCIIZ _                         ' __in_opt   LPCSTR    pszInfPath
 , BYREF pszDriverName AS ASCIIZ _                      ' __in       LPCSTR    pszDriverName
 , BYREF pszEnvironment AS ASCIIZ _                     ' __in_opt   LPCSTR    pszEnvironment
 , BYVAL dwFlags AS DWORD _                             ' __in       DWORD     dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION InstallPrinterDriverFromPackageW IMPORT "WINSPOOL.DRV" ALIAS "InstallPrinterDriverFromPackageW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt   LPCWSTR   pszServer
 , BYREF pszInfPath AS WSTRINGZ _                       ' __in_opt   LPCWSTR   pszInfPath
 , BYREF pszDriverName AS WSTRINGZ _                    ' __in       LPCWSTR   pszDriverName
 , BYREF pszEnvironment AS WSTRINGZ _                   ' __in_opt   LPCWSTR   pszEnvironment
 , BYVAL dwFlags AS DWORD _                             ' __in       DWORD     dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO InstallPrinterDriverFromPackage = InstallPrinterDriverFromPackageW
#ELSE
   MACRO InstallPrinterDriverFromPackage = InstallPrinterDriverFromPackageA
#ENDIF

%UPDP_SILENT_UPLOAD      = &H00000001???  ' // If specified we will not show UI during UploadPrinterDriverPackage API.
%UPDP_UPLOAD_ALWAYS      = &H00000002???  ' // Will not do the optimization of not uploading the files if the
                                          ' // driver package is already present on remote machine.
%UPDP_CHECK_DRIVERSTORE  = &H00000004???  ' // Check whether the given package exists in driver store or not.

DECLARE FUNCTION UploadPrinterDriverPackageA IMPORT "WINSPOOL.DRV" ALIAS "UploadPrinterDriverPackageA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt LPCSTR  pszServer
 , BYREF pszInfPath AS ASCIIZ _                         ' __in     LPCSTR  pszInfPath
 , BYREF pszEnvironment AS ASCIIZ _                     ' __in_opt LPCSTR  pszEnvironment
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 , BYVAL hwnd AS DWORD _                                ' __in     HWND    hwnd
 , BYREF pszDestInfPath AS ASCIIZ _                     ' __out    LPSTR   pszDestInfPath
 , BYREF pcchDestInfPath AS DWORD _                     ' __inout  PULONG  pcchDestInfPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UploadPrinterDriverPackageW IMPORT "WINSPOOL.DRV" ALIAS "UploadPrinterDriverPackageW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt LPCWSTR pszServer
 , BYREF pszInfPath AS WSTRINGZ _                       ' __in     LPCWSTR pszInfPath
 , BYREF pszEnvironment AS WSTRINGZ _                   ' __in_opt LPCWSTR pszEnvironment
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 , BYVAL hwnd AS DWORD _                                ' __in     HWND    hwnd
 , BYREF pszDestInfPath AS WSTRINGZ _                   ' __out    LPWSTR  pszDestInfPath
 , BYREF pcchDestInfPath AS DWORD _                     ' __inout  PULONG  pcchDestInfPath
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO UploadPrinterDriverPackage = UploadPrinterDriverPackageW
#ELSE
   MACRO UploadPrinterDriverPackage = UploadPrinterDriverPackageA
#ENDIF

TYPE CORE_PRINTER_DRIVERA
   CoreDriverGUID   AS GUID                 ' GUID
   ftDriverDate     AS FILETIME             ' FILETIME
   dwlDriverVersion AS QUAD                 ' DWORDLONG
   szPackageID      AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 552 bytes
TYPE CORE_PRINTER_DRIVERW   ' Must be 8 byte aligned
   CoreDriverGUID   AS GUID                   ' GUID
   ftDriverDate     AS FILETIME               ' FILETIME
   dwlDriverVersion AS QUAD                   ' DWORDLONG
   szPackageID      AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO CORE_PRINTER_DRIVER = CORE_PRINTER_DRIVERW
#ELSE
   MACRO CORE_PRINTER_DRIVER = CORE_PRINTER_DRIVERA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetCorePrinterDriversA LIB "WinSpool.drv" _
    ALIAS "GetCorePrinterDriversA" ( _
    pszServer                  AS ASCIIZ, _
    pszEnvironment             AS ASCIIZ, _
    pszzCoreDriverDependencies AS ASCIIZ, _
    BYVAL cCorePrinterDrivers  AS DWORD, _
    BYVAL pCorePrinterDrivers  AS CORE_PRINTER_DRIVERA PTR _
    ) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION GetCorePrinterDriversA IMPORT "WINSPOOL.DRV" ALIAS "GetCorePrinterDriversA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt LPCSTR                 pszServer
 , BYREF pszEnvironment AS ASCIIZ _                     ' __in_opt LPCSTR                 pszEnvironment
 , BYREF pszzCoreDriverDependencies AS ASCIIZ _         ' __in     LPCSTR                 pszzCoreDriverDependencies
 , BYVAL cCorePrinterDrivers AS DWORD _                 ' __in     DWORD                  cCorePrinterDrivers
 , BYREF pCorePrinterDrivers AS CORE_PRINTER_DRIVERA _  ' __out    PCORE_PRINTER_DRIVERA  pCorePrinterDrivers
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetCorePrinterDriversW LIB "WinSpool.drv" _
    ALIAS "GetCorePrinterDriversW" ( _
    pszServer                  AS WSTRINGZ, _
    pszEnvironment             AS WSTRINGZ, _
    pszzCoreDriverDependencies AS WSTRINGZ, _
    BYVAL cCorePrinterDrivers  AS DWORD, _
    BYVAL pCorePrinterDrivers  AS CORE_PRINTER_DRIVERW PTR _
    ) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION GetCorePrinterDriversW IMPORT "WINSPOOL.DRV" ALIAS "GetCorePrinterDriversW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt LPCWSTR                pszServer
 , BYREF pszEnvironment AS WSTRINGZ _                   ' __in_opt LPCWSTR                pszEnvironment
 , BYREF pszzCoreDriverDependencies AS WSTRINGZ _       ' __in     LPCWSTR                pszzCoreDriverDependencies
 , BYVAL cCorePrinterDrivers AS DWORD _                 ' __in     DWORD                  cCorePrinterDrivers
 , BYREF pCorePrinterDrivers AS CORE_PRINTER_DRIVERW _  ' __out    PCORE_PRINTER_DRIVERW  pCorePrinterDrivers
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetCorePrinterDrivers = GetCorePrinterDriversW
#ELSE
   MACRO GetCorePrinterDrivers = GetCorePrinterDriversA
#ENDIF

DECLARE FUNCTION CorePrinterDriverInstalledA IMPORT "WINSPOOL.DRV" ALIAS "CorePrinterDriverInstalledA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt LPCSTR     pszServer
 , BYREF pszEnvironment AS ASCIIZ _                     ' __in_opt LPCSTR     pszEnvironment
 , BYVAL CoreDriverGUID AS GUID _                       ' __in     GUID       CoreDriverGUID
 , BYVAL ftDriverDate AS FILETIME _                     ' __in     FILETIME   ftDriverDate
 , BYVAL dwlDriverVersion AS QUAD _                     ' __in     DWORDLONG  dwlDriverVersion
 , BYREF pbDriverInstalled AS LONG _                    ' __out    BOOL       *pbDriverInstalled
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CorePrinterDriverInstalledW IMPORT "WINSPOOL.DRV" ALIAS "CorePrinterDriverInstalledW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt LPCWSTR    pszServer
 , BYREF pszEnvironment AS WSTRINGZ _                   ' __in_opt LPCWSTR    pszEnvironment
 , BYVAL CoreDriverGUID AS GUID _                       ' __in     GUID       CoreDriverGUID
 , BYVAL ftDriverDate AS FILETIME _                     ' __in     FILETIME   ftDriverDate
 , BYVAL dwlDriverVersion AS QUAD _                     ' __in     DWORDLONG  dwlDriverVersion
 , BYREF pbDriverInstalled AS LONG _                    ' __out    BOOL       *pbDriverInstalled
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO CorePrinterDriverInstalled = CorePrinterDriverInstalledW
#ELSE
   MACRO CorePrinterDriverInstalled = CorePrinterDriverInstalledA
#ENDIF

DECLARE FUNCTION GetPrinterDriverPackagePathA IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverPackagePathA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt    LPCSTR  pszServer
 , BYREF pszEnvironment AS ASCIIZ _                     ' __in_opt    LPCSTR  pszEnvironment
 , BYREF pszLanguage AS ASCIIZ _                        ' __in_opt    LPCSTR  pszLanguage
 , BYREF pszPackageID AS ASCIIZ _                       ' __in        LPCSTR  pszPackageID
 , BYREF pszDriverPackageCab AS ASCIIZ _                ' __inout_opt LPSTR   pszDriverPackageCab
 , BYVAL cchDriverPackageCab AS DWORD _                 ' __in_opt    DWORD   cchDriverPackageCab
 , BYREF pcchRequiredSize AS DWORD _                    ' __out       LPDWORD pcchRequiredSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetPrinterDriverPackagePathW IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriverPackagePathW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt    LPCWSTR pszServer
 , BYREF pszEnvironment AS WSTRINGZ _                   ' __in_opt    LPCWSTR pszEnvironment
 , BYREF pszLanguage AS WSTRINGZ _                      ' __in_opt    LPCWSTR pszLanguage
 , BYREF pszPackageID AS WSTRINGZ _                     ' __in        LPCWSTR pszPackageID
 , BYREF pszDriverPackageCab AS WSTRINGZ _              ' __inout_opt LPWSTR  pszDriverPackageCab
 , BYVAL cchDriverPackageCab AS DWORD _                 ' __in_opt    DWORD   cchDriverPackageCab
 , BYREF pcchRequiredSize AS DWORD _                    ' __out       LPDWORD pcchRequiredSize
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO GetPrinterDriverPackagePath = GetPrinterDriverPackagePathW
#ELSE
   MACRO GetPrinterDriverPackagePath = GetPrinterDriverPackagePathA
#ENDIF

DECLARE FUNCTION DeletePrinterDriverPackageA IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverPackageA" ( _
   BYREF pszServer AS ASCIIZ _                          ' __in_opt LPCSTR pszServer
 , BYREF pszInfPath AS ASCIIZ _                         ' __in     LPCSTR pszInfPath
 , OPTIONAL BYREF pszEnvironment AS ASCIIZ _            ' __in_opt LPCSTR pszEnvironment
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DeletePrinterDriverPackageW IMPORT "WINSPOOL.DRV" ALIAS "DeletePrinterDriverPackageW" ( _
   BYREF pszServer AS WSTRINGZ _                        ' __in_opt LPCWSTR pszServer
 , BYREF pszInfPath AS WSTRINGZ _                       ' __in     LPCWSTR pszInfPath
 , OPTIONAL BYREF pszEnvironment AS WSTRINGZ _          ' __in_opt LPWCSTR pszEnvironment
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO DeletePrinterDriverPackage = DeletePrinterDriverPackageW
#ELSE
   MACRO DeletePrinterDriverPackage = DeletePrinterDriverPackageA
#ENDIF

' enum EPrintPropertyType
%kPropertyTypeString              = 1
%kPropertyTypeInt32               = 2
%kPropertyTypeInt64               = 3
%kPropertyTypeByte                = 4
%kPropertyTypeTime                = 5
%kPropertyTypeDevMode             = 6
%kPropertyTypeSD                  = 7
%kPropertyTypeNotificationReply   = 8
%kPropertyTypeNotificationOptions = 9
%kPropertyTypeBuffer              = 10

' enum EPrintXPSJobProgress
%kAddingDocumentSequence = 0
%kDocumentSequenceAdded  = 1
%kAddingFixedDocument    = 2
%kFixedDocumentAdded     = 3
%kAddingFixedPage        = 4
%kFixedPageAdded         = 5
%kResourceAdded          = 6
%kFontAdded              = 7
%kImageAdded             = 8
%kXpsDocumentCommitted   = 9

' enum EPrintXPSJobOperation
%kJobProduction  = 1
%kJobConsumption = 2

' // Size = 8 bytes
TYPE PrintPropertyValue_UNION_STRUCT DWORD
   cbBuf AS DWORD   ' DWORD
   pBuf  AS DWORD   ' LPVOID
END TYPE

' // Size = 8 bytes
UNION PrintPropertyValue_UNION   ' Must be 8 byte aligned
   propertyByte   AS BYTE           ' BYTE
   propertyString AS WSTRINGZ PTR   ' PWSTR
   propertyInt32  AS LONG           ' LONG
   propertyInt64  AS QUAD           ' LONGLONG
   propertyBlob   AS PrintPropertyValue_UNION_STRUCT
END UNION

' // Size = 16 bytes
TYPE PrintPropertyValue QWORD FILL   ' Must be 8 byte aligned
   ePropertyType AS DWORD   ' EPrintPropertyType enum
   value         AS PrintPropertyValue_UNION
END TYPE

' // Size = 24 bytes
TYPE PrintNamedProperty QWORD FILL   ' Must be 8 byte aligned
   propertyName  AS WSTRINGZ PTR   ' WCHAR*
   propertyValue AS PrintPropertyValue
END TYPE

' // Size = 8 bytes
TYPE PrintPropertiesCollection DWORD
   numberOfProperties   AS DWORD   ' ULONG
   propertiesCollection AS PrintNamedProperty PTR   ' PrintNamedProperty*
END TYPE

DECLARE FUNCTION ReportJobProcessingProgress IMPORT "WINSPOOL.DRV" ALIAS "ReportJobProcessingProgress" ( _
   BYVAL printerHandle AS DWORD _                       ' __in HANDLE printerHandle
 , BYVAL jobId AS DWORD _                               ' __in ULONG  jobId
 , BYVAL jobOperation AS DWORD _                        ' __in EPrintXPSJobOperation jobOperation
 , BYVAL jobProgress AS DWORD _                         ' __in EPrintXPSJobProgress jobProgress
 ) AS LONG                                              ' HRESULT

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriver2A LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriver2A" ( _
    BYVAL hWnd        AS DWORD, _  ' HWND
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS ASCIIZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION GetPrinterDriver2A IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriver2A" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND    hwnd
 , BYVAL hPrinter AS DWORD _                            ' __in     HANDLE  hPrinter
 , BYREF pEnvironment AS ASCIIZ _                       ' __in_opt LPSTR   pEnvironment
 , BYVAL Level AS DWORD _                               ' __in     DWORD   Level
 , BYREF pDriverInfo AS ANY _                           ' __out    LPBYTE  pDriverInfo
 , BYVAL cBuf AS DWORD _                                ' __in     DWORD   cBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out    LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetPrinterDriver2W LIB "WinSpool.drv" _
    ALIAS "GetPrinterDriver2W" ( _
    BYVAL hWnd        AS DWORD, _  ' HWND
    BYVAL hPrinter    AS DWORD, _  ' HANDLE
    pEnvironment      AS WSTRINGZ, _
    BYVAL Level       AS DWORD, _
    BYVAL pDriverInfo AS BYTE PTR, _
    BYVAL cbBuf       AS DWORD, _
    pcbNeeded         AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
2DECLARE FUNCTION GetPrinterDriver2W IMPORT "WINSPOOL.DRV" ALIAS "GetPrinterDriver2W" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND    hwnd
 , BYVAL hPrinter AS DWORD _                            ' __in     HANDLE  hPrinter
 , BYREF pEnvironment AS WSTRINGZ _                     ' __in_opt LPWSTR  pEnvironment
 , BYVAL Level AS DWORD _                               ' __in     DWORD   Level
 , BYREF pDriverInfo AS ANY _                           ' __out    LPBYTE  pDriverInfo
 , BYVAL cBuf AS DWORD _                                ' __in     DWORD   cBuf
 , BYREF pcbNeeded AS DWORD _                           ' __out    LPDWORD pcbNeeded
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetPrinterDriver2 = GetPrinterDriver2W
#ELSE
   MACRO GetPrinterDriver2 = GetPrinterDriver2A
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' enum PRINT_EXECUTION_CONTEXT
%PRINT_EXECUTION_CONTEXT_APPLICATION            = 0
%PRINT_EXECUTION_CONTEXT_SPOOLER_SERVICE        = 1
%PRINT_EXECUTION_CONTEXT_SPOOLER_ISOLATION_HOST = 2
%PRINT_EXECUTION_CONTEXT_FILTER_PIPELINE        = 3
%PRINT_EXECUTION_CONTEXT_WOW64                  = 4

' // Size = 8 bytes
TYPE PRINT_EXECUTION_DATA DWORD
   context      AS LONG    ' PRINT_EXECUTION_CONTEXT
   clientAppPID AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION GetPrintExecutionData IMPORT "WINSPOOL.DRV" ALIAS "GetPrintExecutionData" ( _
   BYREF pData AS PRINT_EXECUTION_DATA _                ' __out PRINT_EXECUTION_DATA *pData
 ) AS LONG                                              ' BOOL

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
