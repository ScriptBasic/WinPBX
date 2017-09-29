' ########################################################################################
' Microsoft Windows
' File: RpcAsync.inc
' Contents: RPC runtime APIs needed to use [async] RPC features
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RPCASYNC_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "rpcdce.inc"

'#if defined(_KRPCENV_)

'#include <ntddk.h>

'#endif // _KRPCENV_

'#if defined(RPC_NO_WINDOWS_H) || defined(_KRPCENV_)

'// We've gotta have windef.h--can't live without it.

'#include <windef.h>

'#endif // RPC_NO_WINDOWS_H || _KRPCENV_

'#define RPC_ASYNC_VERSION_1_0     sizeof(RPC_ASYNC_STATE)

' RPC_NOTIFICATION_TYPES enum
%RpcNotificationTypeNone     = 0
%RpcNotificationTypeEvent    = 1
'#if !defined(_KRPCENV_)
%RpcNotificationTypeApc      = 2
%RpcNotificationTypeIoc      = 3
%RpcNotificationTypeHwnd     = 4
'#endif
%RpcNotificationTypeCallback = 5

' RPC_ASYNC_EVENT enum
%RpcCallComplete    = 0
%RpcSendComplete    = 1
%RpcReceiveComplete = 2

'struct _RPC_ASYNC_STATE;

'typedef void RPC_ENTRY

'RPCNOTIFICATION_ROUTINE (
'                  struct _RPC_ASYNC_STATE *pAsync,
'                  void *Context,
'                  RPC_ASYNC_EVENT Event);
'typedef RPCNOTIFICATION_ROUTINE *PFN_RPCNOTIFICATION_ROUTINE;

'typedef union _RPC_ASYNC_NOTIFICATION_INFO {
'#if !defined(_KRPCENV_)
'    //
'    // Notification by APC
'    //
'    struct {
'        PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
'        HANDLE hThread;
'        } APC;

'#if !defined(RPC_NO_WINDOWS_H) || defined (_WINBASE_)

'    //
'    // Notification by IO completion port
'    //
'    struct {
'        HANDLE hIOPort;
'        DWORD dwNumberOfBytesTransferred;
'        DWORD_PTR dwCompletionKey;
'        LPOVERLAPPED lpOverlapped;
'        } IOC;

'#endif // !RPC_NO_WINDOWS_H || _WINBASE_

'#if !defined(RPC_NO_WINDOWS_H)

'    //
'    // Notification by window message
'    //
'    struct {
'        HWND hWnd;
'        UINT Msg;
'        } HWND;

'#endif // RPC_NO_WINDOWS_H
'#endif // _KRPCENV_


'    #if !defined(_KRPCENV_)
'    //
'    // Notification by event
'    //
'    HANDLE hEvent;
'    #else   // _KRPCENV_
'    //
'    // Notification by event
'    //
'    PKEVENT Event;
'    #endif  // _KRPCENV_

'    //
'    // Notification by callback function
'    //
'    // This option is available only to OLE
'    //
'    PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
'} RPC_ASYNC_NOTIFICATION_INFO, *PRPC_ASYNC_NOTIFICATION_INFO;

' // Size = 8 bytes
TYPE RPC_ASYNC_NOTIFICATION_INFO_APC DWORD
   NotificationRoutine AS DWORD   ' PFN_RPCNOTIFICATION_ROUTINE
   hThread             AS DWORD   ' HANDLE
END TYPE

' // Size = 16 bytes
TYPE RPC_ASYNC_NOTIFICATION_INFO_IOC DWORD
   hIOPort                    AS DWORD            ' HANDLE
   dwNumberOfBytesTransferred AS DWORD            ' DWORD
   dwCompletionKey            AS DWORD            ' DWORD_PTR
   lpOverlapped               AS OVERLAPPED PTR   ' LPOVERLAPPED
END TYPE

' // Size = 8 bytes
TYPE RPC_ASYNC_NOTIFICATION_INFO_HWND DWORD
   hWnd AS DWORD   ' HWND
   Msg  AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
UNION RPC_ASYNC_NOTIFICATION_INFO DWORD
'#if !defined(_KRPCENV_)
   ' // Notification by APC
   APC AS RPC_ASYNC_NOTIFICATION_INFO_APC
   ' // Notification by IO completion port
   IOC AS RPC_ASYNC_NOTIFICATION_INFO_IOC
   ' // Notification by window message
   HWND AS RPC_ASYNC_NOTIFICATION_INFO_HWND
'#endif // _KRPCENV_
'#if !defined(_KRPCENV_)
   ' // Notification by event
   ' HANDLE hEvent;
'#else   // _KRPCENV_
   ' // Notification by event
   ' PKEVENT Event;
'#endif  // _KRPCENV_
   hEvent AS DWORD   ' HANDLE
   ' // Notification by callback function
   ' // This option is available only to OLE
   NotificationRoutine AS DWORD   ' PFN_RPCNOTIFICATION_ROUTINE
END UNION

'typedef struct _RPC_ASYNC_STATE {
'    unsigned int    Size; // size of this structure
'    unsigned long   Signature;
'    long   Lock;
'    unsigned long   Flags;
'    void           *StubInfo;
'    void           *UserInfo;
'    void           *RuntimeInfo;
'    RPC_ASYNC_EVENT Event;

'    RPC_NOTIFICATION_TYPES NotificationType;
'    union {
'        //
'        // Notification by APC
'        //
'        struct {
'            PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
'            HANDLE hThread;
'            } APC;

'        //
'        // Notification by IO completion port
'        //
'        struct {
'            HANDLE hIOPort;
'            DWORD dwNumberOfBytesTransferred;
'            DWORD_PTR dwCompletionKey;
'            LPOVERLAPPED lpOverlapped;
'            } IOC;

'        //
'        // Notification by window message
'        //
'        struct {
'            HWND hWnd;
'            UINT Msg;
'            } HWND;


'        //
'        // Notification by event
'        //
'        HANDLE hEvent;

'        //
'        // Notification by callback function
'        //
'        // This option is available only to OLE
'        //
'        PFN_RPCNOTIFICATION_ROUTINE NotificationRoutine;
'        } u;

'    LONG_PTR Reserved[4];
'    } RPC_ASYNC_STATE, *PRPC_ASYNC_STATE;

' // Size = 8 bytes
TYPE RPC_ASYNC_STATE_APC DWORD
   NotificationRoutine AS DWORD   ' PFN_RPCNOTIFICATION_ROUTINE
   hThread             AS DWORD   ' HANDLE
END TYPE

' // Size = 16 bytes
TYPE RPC_ASYNC_STATE_IOC DWORD
   hIOPort                    AS DWORD            ' HANDLE
   dwNumberOfBytesTransferred AS DWORD            ' DWORD
   dwCompletionKey            AS DWORD            ' DWORD_PTR
   lpOverlapped               AS OVERLAPPED PTR   ' LPOVERLAPPED
END TYPE

' // Size = 8 bytes
TYPE RPC_ASYNC_STATE_HWND DWORD
   hWnd AS DWORD   ' HWND
   Msg  AS DWORD   ' UINT
END TYPE

' // Size = 16 bytes
UNION RPC_ASYNC_STATE_UNION DWORD
   APC                 AS RPC_ASYNC_STATE_APC
   IOC                 AS RPC_ASYNC_STATE_IOC
   HWND                AS RPC_ASYNC_STATE_HWND
   hEvent              AS DWORD                  ' HANDLE
   NotificationRoutine AS DWORD                  ' PFN_RPCNOTIFICATION_ROUTINE
END UNION

' // Size = 68 bytes
TYPE RPC_ASYNC_STATE DWORD
   Size             AS DWORD   ' unsigned int // size of this structure
   Signature        AS DWORD   ' unsigned long
   Lock             AS LONG    ' long
   Flags            AS DWORD   ' unsigned long
   StubInfo         AS DWORD   ' void *
   UserInfo         AS DWORD   ' void *
   RuntimeInfo      AS DWORD   ' void *
   Event            AS LONG    ' RPC_ASYNC_EVENT enum
   NotificationType AS LONG    ' RPC_NOTIFICATION_TYPES enum
   RPC_ASYNC_STATE_UNION
   Reserved(3)      AS DWORD   ' LONG_PTR[4]
END TYPE

'// Possible values for Flags
%RPC_C_NOTIFY_ON_SEND_COMPLETE     = &H1
%RPC_C_INFINITE_TIMEOUT            = &HFFFFFFFF???  ' %INFINITE

'#define RpcAsyncGetCallHandle(pAsync) (((PRPC_ASYNC_STATE) pAsync)->RuntimeInfo)

DECLARE FUNCTION RpcAsyncInitializeHandle IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncInitializeHandle" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 , BYVAL Size AS DWORD _                                ' __in unsigned int     Size
 ) AS LONG                                              ' RPC_STATUS

'#if !defined(_KRPCENV_)

DECLARE FUNCTION RpcAsyncRegisterInfo IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncRegisterInfo" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcAsyncGetCallStatus IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncGetCallStatus" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcAsyncCompleteCall IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncCompleteCall" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in  PRPC_ASYNC_STATE pAsync
 , BYVAL Reply AS DWORD _                               ' __out void *Reply
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcAsyncAbortCall IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncAbortCall" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 , BYVAL ExceptionCode AS DWORD _                       ' __in unsigned long ExceptionCode
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcAsyncCancelCall IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncCancelCall" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 , BYVAL fAbort AS LONG _                               ' __in BOOL fAbort
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_WINXP)

'// EEINFO needs k-mode or needs winbase.h
'#if !defined(RPC_NO_WINDOWS_H) || defined(_KRPCENV_) || defined(_WINBASE_)

' ExtendedErrorParamTypes enum
%eeptAnsiString    = 1
%eeptUnicodeString = 2
%eeptLongVal       = 3
%eeptShortVal      = 4
%eeptPointerVal    = 5
%eeptNone          = 6
%eeptBinary        = 7

%MaxNumberOfEEInfoParams   = 4
%RPC_EEINFO_VERSION        = 1

' // Size = 8 bytes
TYPE BinaryParam DWORD
   Buffer AS DWORD     ' void *
   Size   AS INTEGER   ' short
END TYPE

' // Size = 8 bytes
UNION RPC_EE_INFO_PARAM_UNION
   AnsiString    AS ASCIIZ PTR     ' LPSTR
   UnicodeString AS WSTRINGZ PTR   ' LPWSTR
   LVal          AS LONG           ' long
   SVal          AS INTEGER        ' short
   PVal          AS QUAD           ' ULONGLONG
   BVal          AS BinaryParam    ' BinaryParam
END UNION

' // Size = 16 bytes
TYPE RPC_EE_INFO_PARAM   ' Must be 8 byte aligned
   ParameterType AS LONG   ' ExtendedErrorParamTypes enum
   alignment__   AS DWORD
   RPC_EE_INFO_PARAM_UNION
END TYPE

%EEInfoPreviousRecordsMissing   =  1
%EEInfoNextRecordsMissing       =  2
%EEInfoUseFileTime              =  4

%EEInfoGCCOM                    = 11
'#if (NTDDI_VERSION >= NTDDI_WS03)
%EEInfoGCFRS                    = 12
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

' // Size = 16 bytes
UNION RPC_EXTENDED_ERROR_INFO_UNION
'#if !defined(_KRPCENV_)
'        SYSTEMTIME SystemTime;
'        FILETIME FileTime;
'#else    // _KRPCENV_
'        LARGE_INTEGER KernelTime;
'#endif   // _KRPCENV_
   SystemTime AS SYSTEMTIME
   FileTime   AS FILETIME
END UNION

' // Size = 112 bytes
TYPE RPC_EXTENDED_ERROR_INFO   ' Must be 8 byte aligned
   Version             AS DWORD          ' ULONG
   ComputerName        AS WSTRINGZ PTR   ' LPWSTR
   ProcessID           AS DWORD          ' ULONG
   RPC_EXTENDED_ERROR_INFO_UNION
   GeneratingComponent AS DWORD          ' ULONG
   Status              AS DWORD          ' ULONG
   DetectionLocation   AS WORD           ' USHORT
   Flags               AS WORD           ' USHORT
   NumberOfParameters  AS LONG           ' int
   alignment__         AS DWORD
   Parameters(%MaxNumberOfEEInfoParams - 1) AS RPC_EE_INFO_PARAM
END TYPE

' // Size = 12 bytes
TYPE RPC_ERROR_ENUM_HANDLE DWORD
   Signature  AS DWORD   ' ULONG
   CurrentPos AS DWORD   ' void *
   Head       AS DWORD   ' void *
END TYPE

DECLARE FUNCTION RpcErrorStartEnumeration IMPORT "RPCRT4.DLL" ALIAS "RpcErrorStartEnumeration" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __out RPC_ERROR_ENUM_HANDLE *EnumHandle
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorGetNextRecord IMPORT "RPCRT4.DLL" ALIAS "RpcErrorGetNextRecord" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in  RPC_ERROR_ENUM_HANDLE *EnumHandle
 , BYVAL CopyStrings AS LONG _                          ' __in  BOOL CopyStrings
 , BYREF ErrorInfo AS RPC_EXTENDED_ERROR_INFO _         ' __out RPC_EXTENDED_ERROR_INFO *ErrorInfo
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorEndEnumeration IMPORT "RPCRT4.DLL" ALIAS "RpcErrorEndEnumeration" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in RPC_ERROR_ENUM_HANDLE *EnumHandle
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorResetEnumeration IMPORT "RPCRT4.DLL" ALIAS "RpcErrorResetEnumeration" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in RPC_ERROR_ENUM_HANDLE *EnumHandle
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorGetNumberOfRecords IMPORT "RPCRT4.DLL" ALIAS "RpcErrorGetNumberOfRecords" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in  RPC_ERROR_ENUM_HANDLE *EnumHandle
 , BYREF Records AS LONG _                              ' __out int *Records
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorSaveErrorInfo IMPORT "RPCRT4.DLL" ALIAS "RpcErrorSaveErrorInfo" ( _
   BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in  RPC_ERROR_ENUM_HANDLE *EnumHandle
 , BYREF ErrorBlob AS ANY _                             ' __out PVOID *ErrorBlob
 , BYREF BlobSize AS DWORD _                            ' __out size_t *BlobSize
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorLoadErrorInfo IMPORT "RPCRT4.DLL" ALIAS "RpcErrorLoadErrorInfo" ( _
   BYVAL ErrorBlob AS DWORD _                           ' __in  PVOID ErrorBlob
 , BYVAL BlobSize AS DWORD _                            ' __in  size_t BlobSize
 , BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __out RPC_ERROR_ENUM_HANDLE *EnumHandle
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcErrorAddRecord IMPORT "RPCRT4.DLL" ALIAS "RpcErrorAddRecord" ( _
   BYREF ErrorInfo AS RPC_ERROR_ENUM_HANDLE _           ' __in RPC_EXTENDED_ERROR_INFO *ErrorInfo
 ) AS LONG                                              ' RPC_STATUS

DECLARE SUB RpcErrorClearInformation IMPORT "RPCRT4.DLL" ALIAS "RpcErrorClearInformation" ()   ' void

'#endif // !RPC_NO_WINDOWS_H || _KRPCENV_ || _WINBASE_

'#if !defined(_KRPCENV_)

DECLARE FUNCTION RpcAsyncCleanupThread IMPORT "RPCRT4.DLL" ALIAS "RpcAsyncCleanupThread" ( _
   BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcGetAuthorizationContextForClient IMPORT "RPCRT4.DLL" ALIAS "RpcGetAuthorizationContextForClient" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in  RPC_BINDING_HANDLE ClientBinding OPTIONAL
 , BYVAL ImpersonateOnReturn AS LONG _                  ' __in  BOOL ImpersonateOnReturn
 , BYVAL Reserved1 AS DWORD _                           ' __in  PVOID Reserved1
 , BYREF pExpirationTime AS ANY _                       ' __in  PLARGE_INTEGER pExpirationTime OPTIONAL
 , BYVAL Reserved2 AS QUAD _                            ' __in  LUID Reserved2
 , BYVAL Reserved3 AS DWORD _                           ' __in  DWORD Reserved3
 , BYVAL Reserved4 AS DWORD _                           ' __in  PVOID Reserved4
 , BYREF pAuthzClientContext AS ANY _                   ' __out PVOID *pAuthzClientContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcFreeAuthorizationContext IMPORT "RPCRT4.DLL" ALIAS "RpcFreeAuthorizationContext" ( _
   BYVAL pAuthzClientContext AS DWORD _                 ' __in PVOID *pAuthzClientContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcSsContextLockExclusive IMPORT "RPCRT4.DLL" ALIAS "RpcSsContextLockExclusive" ( _
   BYVAL ServerBindingHandle AS DWORD _                 ' __in RPC_BINDING_HANDLE ServerBindingHandle
 , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcSsContextLockShared IMPORT "RPCRT4.DLL" ALIAS "RpcSsContextLockShared" ( _
   BYVAL ServerBindingHandle AS DWORD _                 ' __in RPC_BINDING_HANDLE ServerBindingHandle
 , BYVAL UserContext AS DWORD _                         ' __in PVOID UserContext
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' enum tagRpcLocalAddressFormat
%rlafInvalid = 0
%rlafIPv4    = 1
%rlafIPv6    = 2

' // Size = 16 bytes
TYPE RPC_CALL_LOCAL_ADDRESS_V1 DWORD
   Version       AS DWORD   ' unsigned int
   Buffer        AS DWORD   ' void *
   BufferSize    AS DWORD   ' unsigned long
   AddressFormat AS LONG    ' RpcLocalAddressFormat enum
END TYPE

'%RPC_CALL_ATTRIBUTES_VERSION                        = 2

%RPC_QUERY_SERVER_PRINCIPAL_NAME                    = &H02
%RPC_QUERY_CLIENT_PRINCIPAL_NAME                    = &H04
%RPC_QUERY_CALL_LOCAL_ADDRESS                       = &H08
%RPC_QUERY_CLIENT_PID                               = &H10
%RPC_QUERY_IS_CLIENT_LOCAL                          = &H20
%RPC_QUERY_NO_AUTH_REQUIRED                         = &H40
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if ( (NTDDI_VERSION >= NTDDI_WINXP) && (NTDDI_VERSION < NTDDI_VISTA) )
'%RPC_CALL_ATTRIBUTES_VERSION     = 1
'%RPC_QUERY_SERVER_PRINCIPAL_NAME = 2
'%RPC_QUERY_CLIENT_PRINCIPAL_NAME = 4
%RPC_CALL_ATTRIBUTES_VERSION     = 1
%RPC_QUERY_SERVER_PRINCIPAL_NAME = 2
%RPC_QUERY_CLIENT_PRINCIPAL_NAME = 4
'#endif // ( (NTDDI_VERSION >= NTDDI_WINXP) && (NTDDI_VERSION < NTDDI_VISTA) )

' // Size = 36 bytes
TYPE RPC_CALL_ATTRIBUTES_V1_W DWORD
   Version                         AS DWORD          ' unsigned int
   Flags                           AS DWORD          ' unsigned long
   ServerPrincipalNameBufferLength AS DWORD          ' unsigned long
   ServerPrincipalName             AS WSTRINGZ PTR   ' unsigned short *
   ClientPrincipalNameBufferLength AS DWORD          ' unsigned long
   ClientPrincipalName             AS WSTRINGZ PTR   ' unsigned short *
   AuthenticationLevel             AS DWORD      ' unsigned long
   AuthenticationService           AS DWORD      ' unsigned long
   NullSession                     AS LONG       ' BOOL
END TYPE

' // Size = 36 bytes
TYPE RPC_CALL_ATTRIBUTES_V1_A DWORD
   Version                         AS DWORD        ' unsigned int
   Flags                           AS DWORD        ' unsigned long
   ServerPrincipalNameBufferLength AS DWORD        ' unsigned long
   ServerPrincipalName             AS ASCIIZ PTR   ' unsigned short *
   ClientPrincipalNameBufferLength AS DWORD        ' unsigned long
   ClientPrincipalName             AS ASCIIZ PTR   ' unsigned short *
   AuthenticationLevel             AS DWORD        ' unsigned long
   AuthenticationService           AS DWORD        ' unsigned long
   NullSession                     AS LONG         ' BOOL
END TYPE

MACRO RPC_CALL_ATTRIBUTES_V1 = RPC_CALL_ATTRIBUTES_V1_A

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// CallStatus bit fields
%RPC_CALL_STATUS_CANCELLED         = &H01
%RPC_CALL_STATUS_DISCONNECTED      = &H02

' enum RpcCallType
%rctInvalid    = 0
%rctNormal     = 1
%rctTraining   = 2
%rctGuaranteed = 3

' enum RpcCallClientLocality
%rcclInvalid               = 0
%rcclLocal                 = 1
%rcclRemote                = 2
%rcclClientUnknownLocality = 3

' // Size = 84 bytes
TYPE RPC_CALL_ATTRIBUTES_V2_W DWORD
   Version                         AS DWORD                           ' unsigned int
   Flags                           AS DWORD                           ' unsigned long
   ServerPrincipalNameBufferLength AS DWORD                           ' unsigned long
   ServerPrincipalName             AS WSTRINGZ PTR                    ' unsigned short *
   ClientPrincipalNameBufferLength AS DWORD                           ' unsigned long
   ClientPrincipalName             AS WSTRINGZ PTR                    ' unsigned short *
   AuthenticationLevel             AS DWORD                           ' unsigned long
   AuthenticationService           AS DWORD                           ' unsigned long
   NullSession                     AS LONG                            ' BOOL
   KernelModeCaller                AS LONG                            ' BOOL
   ProtocolSequence                AS DWORD                           ' unsigned long
   IsClientLocal                   AS LONG                            ' RpcCallClientLocality enum
   ClientPID                       AS DWORD                           ' HANDLE
   CallStatus                      AS DWORD                           ' unsigned long
   CallType                        AS LONG                            ' RpcCallType
   CallLocalAddress                AS RPC_CALL_LOCAL_ADDRESS_V1 PTR   ' RPC_CALL_LOCAL_ADDRESS_V1*  // one of the CallLocalAddress flavors
   OpNum                           AS WORD                            ' unsigned short
   InterfaceUuid                   AS GUID                            ' UUID
END TYPE

' // Size = 84 bytes
TYPE RPC_CALL_ATTRIBUTES_V2_A DWORD
   Version                         AS DWORD                           ' unsigned int
   Flags                           AS DWORD                           ' unsigned long
   ServerPrincipalNameBufferLength AS DWORD                           ' unsigned long
   ServerPrincipalName             AS ASCIIZ PTR                      ' unsigned char *
   ClientPrincipalNameBufferLength AS DWORD                           ' unsigned long
   ClientPrincipalName             AS ASCIIZ PTR                      ' unsigned char *
   AuthenticationLevel             AS DWORD                           ' unsigned long
   AuthenticationService           AS DWORD                           ' unsigned long
   NullSession                     AS LONG                            ' BOOL
   KernelModeCaller                AS LONG                            ' BOOL
   ProtocolSequence                AS DWORD                           ' unsigned long
   IsClientLocal                   AS DWORD                           ' unsigned long
   ClientPID                       AS DWORD                           ' HANDLE
   CallStatus                      AS DWORD                           ' unsigned long
   CallType                        AS LONG                            ' RpcCallType
   CallLocalAddress                AS RPC_CALL_LOCAL_ADDRESS_V1 PTR   ' RPC_CALL_LOCAL_ADDRESS_V1* // one of the CallLocalAddress flavors
   OpNum                           AS WORD                            ' unsigned short
   InterfaceUuid                   AS GUID                            ' UUID
END TYPE
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef RPC_CALL_ATTRIBUTES_V2 RPC_CALL_ATTRIBUTES;
'#else
'typedef RPC_CALL_ATTRIBUTES_V1 RPC_CALL_ATTRIBUTES;
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#IF %WINVER >= &H0600
MACRO RPC_CALL_ATTRIBUTES = RPC_CALL_ATTRIBUTES_V2_A
#ELSE
MACRO RPC_CALL_ATTRIBUTES = RPC_CALL_ATTRIBUTES_V1_A
#ENDIF

DECLARE FUNCTION RpcServerInqCallAttributesW IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqCallAttributesW" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in RPC_BINDING_HANDLE ClientBinding OPTIONAL
 , BYREF RpcCallAttributes AS DWORD _                   ' __in_out void *RpcCallAttributes
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerInqCallAttributesA IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqCallAttributesA" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in RPC_BINDING_HANDLE ClientBinding OPTIONAL
 , BYREF RpcCallAttributes AS DWORD _                   ' __in_out void *RpcCallAttributes
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerInqCallAttributes = RpcServerInqCallAttributesW
#ELSE
   MACRO RpcServerInqCallAttributes = RpcServerInqCallAttributesA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// can be used as flags in a bitmask too
' enum RPC_NOTIFICATIONS
%RpcNotificationCallNone         = 0
%RpcNotificationClientDisconnect = 1
%RpcNotificationCallCancel       = 2   ' // internal for Windows

%RpcNotificationCallStatusChange = %RpcNotificationClientDisconnect

DECLARE FUNCTION RpcServerSubscribeForNotification IMPORT "RPCRT4.DLL" ALIAS "RpcServerSubscribeForNotification" ( _
   BYVAL Binding AS DWORD _                             ' __in_opt RPC_BINDING_HANDLE Binding
 , BYVAL Notification AS LONG _                         ' __in RPC_NOTIFICATIONS Notification
 , BYVAL NotificationType AS LONG _                     ' __in RPC_NOTIFICATION_TYPES NotificationType
 , BYREF NotificationInfo AS RPC_ASYNC_NOTIFICATION_INFO _ ' __in RPC_ASYNC_NOTIFICATION_INFO *NotificationInfo
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUnsubscribeForNotification IMPORT "RPCRT4.DLL" ALIAS "RpcServerUnsubscribeForNotification" ( _
   BYVAL Binding AS DWORD _                             ' __in_opt RPC_BINDING_HANDLE Binding
 , BYVAL Notification AS LONG _                         ' __in RPC_NOTIFICATIONS Notification
 , BYREF NotificationsQueued AS DWORD _                 ' __out unsigned long *NotificationsQueued
 ) AS LONG                                              ' RPC_STATUS

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#endif // _KRPCENV_

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION RpcBindingBind IMPORT "RPCRT4.DLL" ALIAS "RpcBindingBind" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in_opt PRPC_ASYNC_STATE pAsync
 , BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingUnbind IMPORT "RPCRT4.DLL" ALIAS "RpcBindingUnbind" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 ) AS LONG                                              ' RPC_STATUS

'#if !defined(RPC_NO_WINDOWS_H) || defined(_KRPCENV_) || defined(_WINBASE_)

%RPC_DE_USE_CURRENT_EEINFO             = 1

DECLARE FUNCTION RpcDiagnoseError IMPORT "RPCRT4.DLL" ALIAS "RpcDiagnoseError" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL RpcStatus AS DWORD _                           ' __in RPC_STATUS RpcStatus
 , BYREF EnumHandle AS RPC_ERROR_ENUM_HANDLE _          ' __in_opt RPC_ERROR_ENUM_HANDLE *EnumHandle
 , BYVAL Options AS DWORD _                             ' __in ULONG Options
 , BYVAL ParentWindow AS DWORD _                        ' __in_opt HWND ParentWindow
 ) AS LONG                                              ' RPC_STATUS

'#endif // !RPC_NO_WINDOWS_H || _KRPCENV_ || _WINBASE_

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'//
'// Internal APIs
'//

DECLARE FUNCTION I_RpcAsyncSetHandle IMPORT "RPCRT4.DLL" ALIAS "I_RpcAsyncSetHandle" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in  PRPC_MESSAGE Message
 , BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in  PRPC_ASYNC_STATE pAsync
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcAsyncAbortCall IMPORT "RPCRT4.DLL" ALIAS "I_RpcAsyncAbortCall" ( _
   BYREF pAsync AS RPC_ASYNC_STATE _                    ' __in PRPC_ASYNC_STATE pAsync
 , BYVAL ExceptionCode AS DWORD _                       ' __in unsigned long ExceptionCode
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_WXP)
DECLARE FUNCTION I_RpcExceptionFilter IMPORT "RPCRT4.DLL" ALIAS "I_RpcExceptionFilter" ( _
   BYVAL ExceptionCode AS DWORD _                        ' unsigned long ExceptionCode
 ) AS LONG                                               ' int
'#endif // (NTDDI_VERSION >= NTDDI_WXP)

'#if defined(__RPC_WIN64__)
'#include <poppack.h>
'#endif
