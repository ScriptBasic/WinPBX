' ########################################################################################
' Microsoft Windows
' File: tbs.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TBS_INC = 1

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'typedef BOOL TBS_BOOL;
'typedef UINT32 TBS_RESULT;
'typedef void *TBS_HCONTEXT;
'typedef UINT32 TBS_COMMAND_PRIORITY;
'typedef UINT32 TBS_COMMAND_LOCALITY;

%TBS_CONTEXT_VERSION_ONE = 1

%TBS_COMMAND_PRIORITY_LOW       = 100???
%TBS_COMMAND_PRIORITY_NORMAL    = 200???
%TBS_COMMAND_PRIORITY_HIGH      = 300???
%TBS_COMMAND_PRIORITY_SYSTEM    = 400???
%TBS_COMMAND_PRIORITY_MAX       = &H80000000???

%TBS_COMMAND_LOCALITY_ZERO      = 0???
%TBS_COMMAND_LOCALITY_ONE       = 1???
%TBS_COMMAND_LOCALITY_TWO       = 2???
%TBS_COMMAND_LOCALITY_THREE     = 3???
%TBS_COMMAND_LOCALITY_FOUR      = 4???

%TBS_SUCCESS                    = %S_OK

%TBS_IN_OUT_BUF_SIZE_MAX        = (256*1024)

' // Size = 4 bytes
TYPE TBS_CONTEXT_PARAMS DWORD
   version AS DWORD   ' UINT32
END TYPE

DECLARE FUNCTION Tbsi_Context_Create IMPORT "Tbs.dll" ALIAS "Tbsi_Context_Create" ( _
   BYREF pContextParams AS TBS_CONTEXT_PARAMS _         ' __in const TBS_CONTEXT_PARAMS* pContextParams
 , BYREF phContext AS DWORD _                           ' __out TBS_HCONTEXT*            phContext
 ) AS DWORD                                             ' TBS_RESULT

DECLARE FUNCTION Tbsip_Context_Close IMPORT "Tbs.dll" ALIAS "Tbsip_Context_Close" ( _
   BYVAL hContext AS DWORD _                            ' __in TBS_HCONTEXT hContext
 ) AS DWORD                                             ' TBS_RESULT

DECLARE FUNCTION Tbsip_Submit_Command IMPORT "Tbs.dll" ALIAS "Tbsip_Submit_Command" ( _
   BYVAL hContext AS DWORD _                            ' __in TBS_HCONTEXT hContext
 , BYVAL Locality AS DWORD _                            ' __in TBS_COMMAND_LOCALITY Locality
 , BYVAL Priority AS DWORD _                            ' __in TBS_COMMAND_PRIORITY Priority
 , BYVAL pCommandBuf AS BYTE PTR _                      ' __in const BYTE* pCommandBuf
 , BYVAL CommandBufLen AS DWORD _                       ' __in UINT32 CommandBufLen
 , BYVAL pResultBuf AS BYTE PTR _                       ' __out BYTE* pResultBuf
 , BYREF pResultBufLen AS DWORD _                       ' __in_out UINT32* pResultBufLen
 ) AS DWORD                                             ' TBS_RESULT

DECLARE FUNCTION Tbsip_Cancel_Commands IMPORT "Tbs.dll" ALIAS "Tbsip_Cancel_Commands" ( _
   BYVAL hContext AS DWORD _                            ' __in TBS_HCONTEXT hContext
 ) AS DWORD                                             ' TBS_RESULT

DECLARE FUNCTION Tbsi_Physical_Presence_Command IMPORT "Tbs.dll" ALIAS "Tbsi_Physical_Presence_Command" ( _
   BYVAL hContext AS DWORD _                            ' __in TBS_HCONTEXT hContext
 , BYVAL pInputBuf AS BYTE PTR _                        ' __in const BYTE* pInputBuf
 , BYVAL InputBufLen AS DWORD _                         ' __in UINT32 InputBufLen
 , BYVAL pOutputBuf AS BYTE PTR _                       ' __out PBYTE pOutputBuf
 , BYVAL pOutputBufLen AS DWORD _                       ' __in_out PUINT32 pOutputBufLen
 ) AS DWORD                                             ' TBS_RESULT

'#if (NTDDI_VERSION >= NTDDI_VISTASP1)

DECLARE FUNCTION Tbsi_Get_TCG_Log IMPORT "Tbs.dll" ALIAS "Tbsi_Get_TCG_Log" ( _
   BYVAL hContext AS DWORD _                            ' __in TBS_HCONTEXT hContext
 , BYVAL pOutputBuf AS BYTE PTR _                       ' __out PBYTE pOutputBuf
 , BYVAL pOutputBufLen AS DWORD _                       ' __in_out PUINT32 pOutputBufLen
 ) AS DWORD                                             ' TBS_RESULT

'#endif // _WIN32_WINNT_VISTASP1

'#endif // _WIN32_WINNT_VISTA
