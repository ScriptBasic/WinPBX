' ########################################################################################
' Microsoft Windows
' File: LMalert.inc
' Contents: Structures for communication with the Alerter service
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMALERT_INC = 1

#INCLUDE ONCE "lmcons.inc"

'//
'// Function Prototypes
'//

' This function is not supported as of Windows Vista because the alerter service is not supported.
'DECLARE FUNCTION NetAlertRaise IMPORT "NETAPI32.DLL" ALIAS "NetAlertRaise" ( _
'   BYREF AlertEventName AS WSTRINGZ _                   ' __in LPCWSTR AlertEventName
' , BYVAL Buffer AS DWORD _                              ' __in LPVOID  Buffer
' , BYVAL BufferSize AS DWORD _                          ' __in DWORD   BufferSize
' ) AS DWORD                                             ' NET_API_STATUS

' This function is not supported as of Windows Vista because the alerter service is not supported.
'DECLARE FUNCTION NetAlertRaiseEx IMPORT "NETAPI32.DLL" ALIAS "NetAlertRaiseEx" ( _
'   BYREF AlertEventName AS WSTRINGZ _                   ' __in LPCWSTR AlertEventName
' , BYVAL VariableInfo AS DWORD _                        ' __in LPVOID  VariableInfo
' , BYVAL VariableInfoSize AS DWORD _                    ' __in DWORD   VariableInfoSize
' , BYREF ServiceName AS WSTRINGZ _                      ' __in LPCWSTR ServiceName
' ) AS DWORD                                             ' NET_API_STATUS


'//
'//  Data Structures
'//

' // Size = 200 bytes
TYPE STD_ALERT BYTE
   alrt_timestamp   AS DWORD                   ' DWORD  alrt_timestamp
   alrt_eventname   AS WSTRINGZ * %EVLEN + 1   ' WCHAR  alrt_eventname[EVLEN + 1]
   alrt_servicename AS WSTRINGZ * %SNLEN + 1   ' WCHAR  alrt_servicename[SNLEN + 1]
END TYPE

' // Size = 8 bytes
TYPE ADMIN_OTHER_INFO DWORD
   alrtad_errcode    AS DWORD   ' DWORD  alrtad_errcode
   alrtad_numstrings AS DWORD   ' DWORD  alrtad_numstrings
END TYPE

' // Size = 8 bytes
TYPE ERRLOG_OTHER_INFO DWORD
   alrter_errcode AS DWORD   ' DWORD  alrter_errcode
   alrter_offset  AS DWORD   ' DWORD  alrter_offset
END TYPE

' // Size = 16 bytes
TYPE PRINT_OTHER_INFO DWORD
   alrtpr_jobid     AS DWORD   ' DWORD  alrtpr_jobid
   alrtpr_status    AS DWORD   ' DWORD  alrtpr_status
   alrtpr_submitted AS DWORD   ' DWORD  alrtpr_submitted
   alrtpr_size      AS DWORD   ' DWORD  alrtpr_size
END TYPE

' // Size = 8 bytes
TYPE USER_OTHER_INFO DWORD
   alrtus_errcode    AS DWORD   ' DWORD  alrtus_errcode
   alrtus_numstrings AS DWORD   ' DWORD  alrtus_numstrings
END TYPE

'//
'// Special Values and Constants
'//

'//
'// Name of mailslot to send alert notifications
'//
'#define ALERTER_MAILSLOT          L"\\\\.\\MAILSLOT\\Alerter"
$$ALERTER_MAILSLOT          = "\\.\MAILSLOT\Alerter"$$

'//
'// The following macro gives a pointer to the other_info data.
'// It takes an alert structure and returns a pointer to structure
'// beyond the standard portion.
'//

'#define ALERT_OTHER_INFO(x)    ((LPBYTE)(x) + sizeof(STD_ALERT))
#IF %DEF(%USEPBDECL)
FUNCTION ALERT_OTHER_INFO (BYVAL x AS BYTE PTR) AS DWORD
    FUNCTION = x + SIZEOF(STD_ALERT)
END FUNCTION
#ELSE
MACRO ALERT_OTHER_INFO(x)   = (CBYT(x) + SIZEOF(STD_ALERT))
#ENDIF

'//
'// The following macro gives a pointer to the variable-length data.
'// It takes a pointer to one of the other-info structs and returns a
'// pointer to the variable data portion.
'//

'#define ALERT_VAR_DATA(p)      ((LPBYTE)(p) + sizeof(*p))

'//
'//      Names of standard Microsoft-defined alert events.
'//

$$ALERT_PRINT_EVENT           = "PRINTING"$$
$$ALERT_MESSAGE_EVENT         = "MESSAGE"$$
$$ALERT_ERRORLOG_EVENT        = "ERRORLOG"$$
$$ALERT_ADMIN_EVENT           = "ADMIN"$$
$$ALERT_USER_EVENT            = "USER"$$

'//
'//      Bitmap masks for prjob_status field of PRINTJOB.
'//

'// 2-7 bits also used in device status

%PRJOB_QSTATUS       = &H3         ' // Bits 0,1
%PRJOB_DEVSTATUS     = &H1fc       ' // 2-8 bits
%PRJOB_COMPLETE      = &H4         ' // Bit 2
%PRJOB_INTERV        = &H8         ' // Bit 3
%PRJOB_ERROR         = &H10        ' // Bit 4
%PRJOB_DESTOFFLINE   = &H20        ' // Bit 5
%PRJOB_DESTPAUSED    = &H40        ' // Bit 6
%PRJOB_NOTIFY        = &H80?       ' // BIT 7
%PRJOB_DESTNOPAPER   = &H100       ' // BIT 8
%PRJOB_DELETED       = &H8000??    ' // BIT 15

'//
'//      Values of PRJOB_QSTATUS bits in prjob_status field of PRINTJOB.
'//

%PRJOB_QS_QUEUED                = 0
%PRJOB_QS_PAUSED                = 1
%PRJOB_QS_SPOOLING              = 2
%PRJOB_QS_PRINTING              = 3
