' ########################################################################################
' Microsoft Windows
' File: wct.inc
' Contents: Private interfaces for thread wait chain traversal.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCT_INC = 1

' enum WCT_OBJECT_TYPE
%WctCriticalSectionType = 1
%WctSendMessageType     = 2
%WctMutexType           = 3
%WctAlpcType            = 4
%WctComType             = 5
%WctThreadWaitType      = 6
%WctProcessWaitType     = 7
%WctThreadType          = 8
%WctComActivationType   = 9
%WctUnknownType         = 10
%WctSocketIoType        = 11
%WctSmbIoType           = 12
%WctMaxType             = 13

' enum WCT_OBJECT_STATUS
%WctStatusNoAccess     = 1    ' // ACCESS_DENIED for this object
%WctStatusRunning      = 2    ' // Thread status
%WctStatusBlocked      = 3    ' // Thread status
%WctStatusPidOnly      = 4    ' // Thread status
%WctStatusPidOnlyRpcss = 5    ' // Thread status
%WctStatusOwned        = 6    ' // Dispatcher object status
%WctStatusNotOwned     = 7    ' // Dispatcher object status
%WctStatusAbandoned    = 8    ' // Dispatcher object status
%WctStatusUnknown      = 9    ' // All objects
%WctStatusError        = 10   ' // All objects
%WctStatusMax          = 11

'// Max. number of nodes in the wait chain
%WCT_MAX_NODE_COUNT = 16

%WCT_OBJNAME_LENGTH = 128

' // Size = 272 bytes   ' Must be 8 byte aligned
TYPE WAITCHAIN_NODE_INFO_LockObject
   ObjectName  AS WSTRINGZ * %WCT_OBJNAME_LENGTH   ' WCHAR
   Timeout     AS QUAD    ' LARGE_INTEGER // Not implemented in v1
   Alertable   AS LONG    ' BOOL // Not implemented in v1
   alignment__ AS DWORD   ' // To keep 8 byte alignment
END TYPE

' // Size = 16 bytes
TYPE WAITCHAIN_NODE_INFO_ThreadObject
   ProcessId       AS DWORD   ' DWORD
   ThreadId        AS DWORD   ' DWORD
   WaitTime        AS DWORD   ' DWORD
   ContextSwitches AS DWORD   ' DWORD
END TYPE

' // Size = 268 bytes
UNION WAITCHAIN_NODE_INFO_UNION
   LockObject   AS WAITCHAIN_NODE_INFO_LockObject
   ThreadObject AS WAITCHAIN_NODE_INFO_ThreadObject
END UNION

' // Size = 280 bytes
TYPE WAITCHAIN_NODE_INFO
   ObjectType   AS LONG   ' WCT_OBJECT_TYPE
   ObjectStatus AS LONG   ' WCT_OBJECT_STATUS
   WAITCHAIN_NODE_INFO_UNION
END TYPE

'typedef LPVOID HWCT;

'typedef VOID (CALLBACK *PWAITCHAINCALLBACK) (
'    HWCT WctHandle,
'    DWORD_PTR Context,
'    DWORD CallbackStatus,
'    LPDWORD NodeCount,
'    PWAITCHAIN_NODE_INFO NodeInfoArray,
'    LPBOOL IsCycle
'    );

'SUB WAITCHAINCALLBACK ( _
'   BYVAL WctHandle AS DWORD _
' , BYVAL Context AS DWORD _
' , BYVAL CallbackStatus AS DWORD _
' , BYREF NodeCount AS DWORD _
' , BYREF NodeInfoArray AS PWAITCHAIN_NODE_INFO _
' , BYREF IsCycle AS LONG _
' )

%WCT_ASYNC_OPEN_FLAG = &H1
%WCTP_OPEN_ALL_FLAGS = %WCT_ASYNC_OPEN_FLAG

DECLARE FUNCTION OpenThreadWaitChainSession IMPORT "Advapi32.dll" ALIAS "OpenThreadWaitChainSession" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL callback AS DWORD _                            ' __in_opt PWAITCHAINCALLBACK callback
 ) AS DWORD                                             ' HWCT

DECLARE SUB CloseThreadWaitChainSession IMPORT "Advapi32.dll" ALIAS "CloseThreadWaitChainSession" ( _
   BYVAL WctHandle AS DWORD _                           ' __in HWCT WctHandle
 )                                                      ' void

%WCT_OUT_OF_PROC_FLAG     = &H1???
%WCT_OUT_OF_PROC_COM_FLAG = &H2???
%WCT_OUT_OF_PROC_CS_FLAG  = &H4???
%WCT_NETWORK_IO_FLAG      = &H8???
%WCTP_GETINFO_ALL_FLAGS = %WCT_OUT_OF_PROC_FLAG OR %WCT_OUT_OF_PROC_COM_FLAG OR %WCT_OUT_OF_PROC_CS_FLAG

DECLARE FUNCTION GetThreadWaitChain IMPORT "Advapi32.dll" ALIAS "GetThreadWaitChain" ( _
   BYVAL WctHandle AS DWORD _                           ' __in HWCT WctHandle
 , BYVAL Context AS DWORD _                             ' __in_opt DWORD_PTR Context
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL ThreadId AS DWORD _                            ' __in DWORD ThreadId
 , BYREF NodeCount AS DWORD _                           ' __inout LPDWORD NodeCount
 , BYREF NodeInfoArray AS WAITCHAIN_NODE_INFO _         ' __out PWAITCHAIN_NODE_INFO NodeInfoArray
 , BYREF IsCycle AS LONG _                              ' __out LPBOOL IsCycle
 ) AS LONG                                              ' BOOL

'typedef HRESULT (*PCOGETCALLSTATE)(int, PULONG);
'typedef HRESULT (*PCOGETACTIVATIONSTATE)(GUID, DWORD, DWORD*);

DECLARE SUB RegisterWaitChainCOMCallback IMPORT "Advapi32.dll" ALIAS "RegisterWaitChainCOMCallback" ( _
   BYVAL CallStateCallback AS DWORD _                   ' __in PCOGETCALLSTATE CallStateCallback
 , BYVAL ActivationStateCallback AS DWORD _             ' __in PCOGETACTIVATIONSTATE ActivationStateCallback
 )                                                      ' void
