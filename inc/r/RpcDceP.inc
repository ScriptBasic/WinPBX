' ########################################################################################
' Microsoft Windows
' File: RpcDceP.inc
' Contents: Private RPC runtime APIs for use by the stubs and by support libraries.
' Applications must not call these routines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RPCDCEP_INC = 1

' // Size = 4 bytes
TYPE RPC_VERSION WORD
   MajorVersion AS WORD   ' unsigned short
   MinorVersion AS WORD   ' unsigned short
END TYPE

' // Size = 20 bytes
TYPE RPC_SYNTAX_IDENTIFIER DWORD
   SyntaxGUID    AS GUID
   SyntaxVersion AS RPC_VERSION
END TYPE

' // Size = 44 bytes
TYPE RPC_MESSAGE DWORD
   Handle                  AS DWORD                       ' RPC_BINDING_HANDLE
   DataRepresentation      AS DWORD                       ' unsigned long
   Buffer                  AS DWORD                       ' void *
   BufferLength            AS DWORD                       ' unsigned int
   ProcNum                 AS DWORD                       ' unsigned int
   TransferSyntax          AS RPC_SYNTAX_IDENTIFIER PTR   ' PRPC_SYNTAX_IDENTIFIER
   RpcInterfaceInformation AS DWORD                       ' void *
   ReservedForRuntime      AS DWORD                       ' void *
   ManagerEpv              AS DWORD                       ' RPC_MGR_EPV *
   ImportContext           AS DWORD                       ' void *
   RpcFlags                AS DWORD                       ' unsigned long
END TYPE

'typedef RPC_STATUS
'RPC_ENTRY RPC_FORWARD_FUNCTION(
'                       IN UUID             * InterfaceId,
'                       IN RPC_VERSION      * InterfaceVersion,
'                       IN UUID             * ObjectId,
'                       IN unsigned char    * Rpcpro,
'                       IN void * * ppDestEndpoint);

' RPC_ADDRESS_CHANGE_TYPE enum
%PROTOCOL_NOT_LOADED     = 1
%PROTOCOL_LOADED         = 2
%PROTOCOL_ADDRESS_CHANGE = 3

'typedef void
'RPC_ENTRY RPC_ADDRESS_CHANGE_FN(
'                        IN void * arg
'                        );

'/*
'*  New context handle flavors.
'*/

'#define RPC_CONTEXT_HANDLE_DEFAULT_GUARD    ((void *) -4083) /* FFFFF00D */
%RPC_CONTEXT_HANDLE_DEFAULT_GUARD    = &HFFFFF00D???

%RPC_CONTEXT_HANDLE_DEFAULT_FLAGS    = &H00000000???
%RPC_CONTEXT_HANDLE_FLAGS            = &H30000000???
%RPC_CONTEXT_HANDLE_SERIALIZE        = &H10000000???
%RPC_CONTEXT_HANDLE_DONT_SERIALIZE   = &H20000000???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_TYPE_STRICT_CONTEXT_HANDLE      = &H40000000???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'/*
' * Types of function calls for datagram rpc
' */

%RPC_NCA_FLAGS_DEFAULT       = &H00000000???  ' /* 0b000...000 */
%RPC_NCA_FLAGS_IDEMPOTENT    = &H00000001???  ' /* 0b000...001 */
%RPC_NCA_FLAGS_BROADCAST     = &H00000002???  ' /* 0b000...010 */
%RPC_NCA_FLAGS_MAYBE         = &H00000004???  ' /* 0b000...100 */

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPCFLG_HAS_GUARANTEE        = &H00000010???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_BUFFER_COMPLETE         = &H00001000???  ' /* used by pipes */
%RPC_BUFFER_PARTIAL          = &H00002000???  ' /* used by pipes */
%RPC_BUFFER_EXTRA            = &H00004000???  ' /* used by pipes */
%RPC_BUFFER_ASYNC            = &H00008000???  ' /* used by async rpc */
%RPC_BUFFER_NONOTIFY         = &H00010000???  ' /* used by async pipes */

%RPCFLG_MESSAGE              = &H01000000???
%RPCFLG_AUTO_COMPLETE        = &H08000000???
%RPCFLG_LOCAL_CALL           = &H10000000???
%RPCFLG_INPUT_SYNCHRONOUS    = &H20000000???
%RPCFLG_ASYNCHRONOUS         = &H40000000???
%RPCFLG_NON_NDR              = &H80000000???

'#if (NTDDI_VERSION >= NTDDI_WINXP)
%RPCFLG_HAS_MULTI_SYNTAXES   = &H02000000???
%RPCFLG_HAS_CALLBACK         = &H04000000???
'#endif // (NTDDI_VERSION >= NTDDI_WXP)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// These two bits will hold the combination of
'// anonymous/admin/authenticate/mixed mode
%RPCFLG_ACCESSIBILITY_BIT1   = &H00100000???
%RPCFLG_ACCESSIBILITY_BIT2   = &H00200000???
%RPCFLG_ACCESS_LOCAL         = &H00400000???

'// This goes to MIDL_STUB_DESC only
%NDR_CUSTOM_OR_DEFAULT_ALLOCATOR = &H10000000???
%NDR_DEFAULT_ALLOCATOR           = &H20000000???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_FLAGS_VALID_BIT         = &H00008000???

'typedef
'void
'(__RPC_STUB * RPC_DISPATCH_FUNCTION) (
'    IN OUT PRPC_MESSAGE Message
'    );

' // Size = 12 bytes
TYPE RPC_DISPATCH_TABLE DWORD
   DispatchTableCount AS DWORD   ' unsigned int
   DispatchTable      AS DWORD   ' RPC_DISPATCH_FUNCTION *
   Reserved           AS DWORD   ' LONG_PTR
END TYPE

' // Size = 8 bytes
TYPE RPC_PROTSEQ_ENDPOINT DWORD
   RpcProtocolSequence AS DWORD   ' unsigned char *
   Endpoint            AS DWORD   ' unsigned char *
END TYPE

'/*
'Both of these types MUST start with the InterfaceId and TransferSyntax.
'Look at RpcIfInqId and I_RpcIfInqTransferSyntaxes to see why.
'*/
%NT351_INTERFACE_SIZE    = &H40
%RPC_INTERFACE_HAS_PIPES = &H0001

' // Size = 68 bytes
TYPE RPC_SERVER_INTERFACE DWORD
   Length                  AS DWORD                      ' unsigned int
   InterfaceId             AS RPC_SYNTAX_IDENTIFIER
   TransferSyntax          AS RPC_SYNTAX_IDENTIFIER
   DispatchTable           AS DWORD                      ' PRPC_DISPATCH_TABLE
   RpcProtseqEndpointCount AS DWORD                      ' unsigned int
   RpcProtseqEndpoint      AS RPC_PROTSEQ_ENDPOINT PTR   ' PRPC_PROTSEQ_ENDPOINT
   DefaultManagerEpv       AS DWORD                      ' RPC_MGR_EPV *
   InterpreterInfo         AS DWORD                      ' void const *
   Flags                   AS DWORD                      ' unsigned int
END TYPE

' // Size = 68 bytes
TYPE RPC_CLIENT_INTERFACE DWORD
   Length                  AS DWORD                      ' unsigned int
   InterfaceId             AS RPC_SYNTAX_IDENTIFIER
   TransferSyntax          AS RPC_SYNTAX_IDENTIFIER
   DispatchTable           AS DWORD                      ' PRPC_DISPATCH_TABLE
   RpcProtseqEndpointCount AS DWORD                      ' unsigned int
   RpcProtseqEndpoint      AS RPC_PROTSEQ_ENDPOINT PTR   ' PRPC_PROTSEQ_ENDPOINT
   Reserved                AS DWORD                      ' ULONG_PTR
   InterpreterInfo         AS DWORD                      ' void const *
   Flags                   AS DWORD                      ' unsigned int
END TYPE

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION I_RpcNegotiateTransferSyntax IMPORT "RPCRT4.DLL" ALIAS "I_RpcNegotiateTransferSyntax" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION I_RpcGetBuffer IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcGetBufferWithObject IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetBufferWithObject" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 , BYREF ObjectUuid AS GUID _                           ' __in UUID * ObjectUuid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcSendReceive IMPORT "RPCRT4.DLL" ALIAS "I_RpcSendReceive" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcFreeBuffer IMPORT "RPCRT4.DLL" ALIAS "I_RpcFreeBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcSend IMPORT "RPCRT4.DLL" ALIAS "I_RpcSend" ( _
   BYREF RPC_MESSAGE _                                  ' __in_out PRPC_MESSAGE Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcReceive IMPORT "RPCRT4.DLL" ALIAS "I_RpcReceive" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out PRPC_MESSAGE Message
 , BYVAL Size AS DWORD _                                ' __in unsigned int Size
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcFreePipeBuffer IMPORT "RPCRT4.DLL" ALIAS "I_RpcFreePipeBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in_out RPC_MESSAGE * Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcReallocPipeBuffer IMPORT "RPCRT4.DLL" ALIAS "I_RpcReallocPipeBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in PRPC_MESSAGE Message
 , BYVAL NewSize AS DWORD _                             ' __in unsigned int NewSize
 ) AS LONG                                              ' RPC_STATUS

'typedef void * I_RPC_MUTEX;

DECLARE SUB I_RpcRequestMutex IMPORT "RPCRT4.DLL" ALIAS "I_RpcRequestMutex" ( _
   BYREF Mutex AS DWORD _                               ' __in_out I_RPC_MUTEX * Mutex
 )                                                      ' void

DECLARE SUB I_RpcClearMutex IMPORT "RPCRT4.DLL" ALIAS "I_RpcClearMutex" ( _
   BYVAL Mutex AS DWORD _                               ' __in I_RPC_MUTEX Mutex
 )                                                      ' void

DECLARE SUB I_RpcDeleteMutex IMPORT "RPCRT4.DLL" ALIAS "I_RpcDeleteMutex" ( _
   BYVAL Mutex AS DWORD _                               ' __in I_RPC_MUTEX Mutex
 )                                                      ' void

DECLARE SUB I_RpcAllocate IMPORT "RPCRT4.DLL" ALIAS "I_RpcAllocate" ( _
   BYVAL Size AS DWORD _                                ' __in unsigned int Size
 )                                                      ' void

DECLARE SUB I_RpcFree IMPORT "RPCRT4.DLL" ALIAS "I_RpcFree" ( _
   BYVAL Object AS DWORD _                              ' __in void * Object
 )                                                      ' void

DECLARE SUB I_RpcPauseExecution IMPORT "RPCRT4.DLL" ALIAS "I_RpcPauseExecution" ( _
   BYVAL Milliseconds AS DWORD _                        ' __in unsigned long Milliseconds
 )                                                      ' void

DECLARE FUNCTION I_RpcGetExtendedError IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetExtendedError" ( _
 ) AS LONG                                              ' RPC_STATUS

'typedef
'void
'(__RPC_USER * PRPC_RUNDOWN) (
'    void * AssociationContext
'    );

' Not exported
'DECLARE SUB I_RpcMonitorAssociation IMPORT "RPCRT4.DLL" ALIAS "I_RpcMonitorAssociation" ( _
'   BYVAL Handle AS DWORD _                              ' __in RPC_BINDING_HANDLE Handle
' , BYVAL RundownRoutine AS DWORD _                      ' __in PRPC_RUNDOWN RundownRoutine
' , BYVAL Context AS DWORD _                             ' __in void * Context
' )                                                      ' void

' Not exported
'DECLARE FUNCTION I_RpcStopMonitorAssociation IMPORT "RPCRT4.DLL" ALIAS "I_RpcStopMonitorAssociation" ( _
'   BYVAL Handle AS DWORD _                              ' __in RPC_BINDING_HANDLE Handle
' ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcGetCurrentCallHandle IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetCurrentCallHandle" ( _
 ) AS DWORD                                             ' RPC_BINDING_HANDLE

' Not exported in Windows XP
DECLARE FUNCTION I_RpcGetAssociationContext IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetAssociationContext" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle
 , BYREF AssociationContext AS DWORD _                  ' __out void * * AssociationContext
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE FUNCTION I_RpcGetServerContextList IMPORT "RPCRT4.DLL" ALIAS "I_RpcGetServerContextList" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle
 ) AS DWORD                                             ' void *

' Not exported in Windows XP
DECLARE SUB I_RpcSetServerContextList IMPORT "RPCRT4.DLL" ALIAS "I_RpcSetServerContextList" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle
 , BYREF ServerContextList AS DWORD _                   ' __out void * ServerContextList
 )                                                      ' void

DECLARE FUNCTION I_RpcNsInterfaceExported IMPORT "RPCRT4.DLL" ALIAS "I_RpcNsInterfaceExported" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WORD _                            ' __in unsigned short *EntryName
 , BYREF RpcInterfaceInformation AS RPC_SERVER_INTERFACE _ ' __in RPC_SERVER_INTERFACE * RpcInterfaceInformation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcNsInterfaceUnexported IMPORT "RPCRT4.DLL" ALIAS "I_RpcNsInterfaceUnexported" ( _
   BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WORD _                            ' __in unsigned short *EntryName
 , BYREF RpcInterfaceInformation AS RPC_SERVER_INTERFACE _ ' __in RPC_SERVER_INTERFACE * RpcInterfaceInformation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingToStaticStringBindingW IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingToStaticStringBindingW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF StringBinding AS WORD _                        ' __out unsigned short **StringBinding
 ) AS LONG                                              ' RPC_STATUS

MACRO I_RpcBindingToStaticStringBinding = I_RpcBindingToStaticStringBindingW

DECLARE FUNCTION I_RpcBindingInqSecurityContext IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqSecurityContext" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF SecurityContextHandle AS DWORD _               ' __out void **SecurityContextHandle
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION I_RpcBindingInqSecurityContextKeyInfo IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqSecurityContextKeyInfo" ( _
   BYVAL Binding AS DWORD _                             ' __in_opt RPC_BINDING_HANDLE Binding
 , BYREF KeyInfo AS ANY _                               ' __inout void *KeyInfo
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

DECLARE FUNCTION I_RpcBindingInqWireIdForSnego IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqWireIdForSnego" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF WireId AS ASCIIZ _                             ' __out RPC_CSTR WireId
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_WS03)
' Not exported in Windows XP
DECLARE FUNCTION I_RpcBindingInqMarshalledTargetInfo IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqMarshalledTargetInfo" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF MarshalledTargetInfoLength AS DWORD _          ' __out unsigned long *MarshalledTargetInfoLength
 , BYREF MarshalledTargetInfo AS ASCIIZ _               ' __out RPC_CSTR *MarshalledTargetInfo
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= WINXP)
DECLARE FUNCTION I_RpcBindingInqLocalClientPID IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqLocalClientPID" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF Pid AS DWORD  _                                ' __out unsigned long *Pid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingHandleToAsyncHandle IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingHandleToAsyncHandle" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF AsyncHandle AS DWORD  _                        ' __out void **AsyncHandle
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= WINXP)

DECLARE FUNCTION I_RpcNsBindingSetEntryNameA IMPORT "RPCRT4.DLL" ALIAS "I_RpcNsBindingSetEntryNameA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS ASCIIZ _                          ' __in RPC_CSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcNsBindingSetEntryNameW IMPORT "RPCRT4.DLL" ALIAS "I_RpcNsBindingSetEntryNameW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS WSTRINGZ _                        ' __in RPC_WSTR EntryName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO I_RpcNsBindingSetEntryName = I_RpcNsBindingSetEntryNameW
#ELSE
   MACRO I_RpcNsBindingSetEntryName = I_RpcNsBindingSetEntryNameA
#ENDIF

DECLARE FUNCTION I_RpcServerUseProtseqEp2A IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerUseProtseqEp2A" ( _
   BYREF NetworkAddress AS ASCIIZ _                     ' __in RPC_CSTR NetworkAddress
 , BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS ASCIIZ _                           ' __in RPC_CSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor
 , BYVAL Policy AS DWORD _                              ' __in void *Policy
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcServerUseProtseqEp2W IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerUseProtseqEp2W" ( _
   BYREF NetworkAddress AS WSTRINGZ _                   ' __in RPC_WSTR NetworkAddress
 , BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS WSTRINGZ _                         ' __in RPC_WSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor
 , BYVAL Policy AS DWORD _                              ' __in void *Policy
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO I_RpcServerUseProtseqEp2 = I_RpcServerUseProtseqEp2W
#ELSE
   MACRO I_RpcServerUseProtseqEp2 = I_RpcServerUseProtseqEp2A
#ENDIF

DECLARE FUNCTION I_RpcServerUseProtseq2A IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerUseProtseq2A" ( _
   BYREF NetworkAddress AS ASCIIZ _                     ' __in RPC_CSTR NetworkAddress
 , BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor
 , BYVAL Policy AS DWORD _                              ' __in void *Policy
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcServerUseProtseq2W IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerUseProtseq2W" ( _
   BYREF NetworkAddress AS WSTRINGZ _                   ' __in RPC_WSTR NetworkAddress
 , BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor
 , BYVAL Policy AS DWORD _                              ' __in void *Policy
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO I_RpcServerUseProtseq2 = I_RpcServerUseProtseq2W
#ELSE
   MACRO I_RpcServerUseProtseq2 = I_RpcServerUseProtseq2A
#ENDIF

DECLARE FUNCTION I_RpcServerStartService IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerStartService" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYREF Endpoint AS WSTRINGZ _                         ' __in RPC_WSTR Endpoint
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingInqDynamicEndpointA IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqDynamicEndpointA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF DynamicEndpoint AS DWORD _                     ' __out_opt RPC_CSTR *DynamicEndpoint
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingInqDynamicEndpointW IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqDynamicEndpointW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF DynamicEndpoint AS DWORD _                     ' __out_opt RPC_WSTR *DynamicEndpoint
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO I_RpcBindingInqDynamicEndpoint = I_RpcBindingInqDynamicEndpointW
#ELSE
   MACRO I_RpcBindingInqDynamicEndpoint = I_RpcBindingInqDynamicEndpointA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION I_RpcServerCheckClientRestriction IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerCheckClientRestriction" ( _
   BYVAL Context AS DWORD _                             ' __in RPC_BINDING_HANDLE Context
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

%TRANSPORT_TYPE_CN        = &H01
%TRANSPORT_TYPE_DG        = &H02
%TRANSPORT_TYPE_LPC       = &H04
%TRANSPORT_TYPE_WMSG      = &H08

DECLARE FUNCTION I_RpcBindingInqTransportType IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqTransportType" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF Type AS DWORD _                                ' __out unsigned int * Type
 ) AS LONG                                              ' RPC_STATUS

' // Size = 20 bytes
TYPE RPC_TRANSFER_SYNTAX WORD
   Uuid      AS GUID   ' UUID
   VersMajor AS WORD   ' unsigned short
   VersMinor AS WORD   ' unsigned short
END TYPE

DECLARE FUNCTION I_RpcIfInqTransferSyntaxes IMPORT "RPCRT4.DLL" ALIAS "I_RpcIfInqTransferSyntaxes" ( _
   BYVAL RpcIfHandle AS DWORD _                         ' __in RPC_IF_HANDLE RpcIfHandle
 , BYREF TransferSyntaxes AS RPC_TRANSFER_SYNTAX _      ' __out RPC_TRANSFER_SYNTAX * TransferSyntaxes
 , BYVAL TransferSyntaxSize AS DWORD _                  ' __in unsigned int TransferSyntaxSize
 , BYREF TransferSyntaxCount AS DWORD _                 ' __out unsigned int * TransferSyntaxCount
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_UuidCreate IMPORT "RPCRT4.DLL" ALIAS "I_UuidCreate" ( _
   BYREF Uuid AS GUID _                                 ' __out UUID * Uuid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingCopy IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingCopy" ( _
   BYVAL SourceBinding AS DWORD _                       ' __in RPC_BINDING_HANDLE SourceBinding
 , BYREF DestinationBinding AS DWORD _                  ' __out RPC_BINDING_HANDLE * DestinationBinding
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingIsClientLocal IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingIsClientLocal" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle OPTIONAL
 , BYREF ClientLocalFlag AS DWORD _                     ' __out unsigned int * ClientLocalFlag
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingInqConnId IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingInqConnId" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ConnId AS DWORD _                              ' __out void **ConnId
 , BYREF pfFirstCall AS DWORD _                         ' __out int *pfFirstCall
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcBindingCreateNP IMPORT "RPCRT4.DLL" ALIAS "I_RpcBindingCreateNP" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in RPC_WSTR ServerName
 , BYREF ServiceName AS WSTRINGZ _                      ' __in RPC_WSTR ServiceName
 , BYREF NetworkOptions AS WSTRINGZ _                   ' __in RPC_WSTR NetworkOptions
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE *Binding
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE SUB I_RpcSsDontSerializeContext IMPORT "RPCRT4.DLL" ALIAS "I_RpcSsDontSerializeContext" ()   ' void

' Not exported in Windows XP
DECLARE FUNCTION I_RpcLaunchDatagramReceiveThread IMPORT "RPCRT4.DLL" ALIAS "I_RpcLaunchDatagramReceiveThread" ( _
   BYVAL pAddress AS DWORD _                            ' void * pAddress
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcServerRegisterForwardFunction IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerRegisterForwardFunction" ( _
   BYVAL pForwardFunction AS DWORD _                    ' __in RPC_FORWARD_FUNCTION * pForwardFunction
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcServerInqAddressChangeFn IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerInqAddressChangeFn" ( _
 ) AS DWORD                                             ' RPC_ADDRESS_CHANGE_FN *

DECLARE FUNCTION I_RpcServerSetAddressChangeFn IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerSetAddressChangeFn" ( _
   BYVAL pAddressChangeFn AS DWORD _                    ' __in RPC_ADDRESS_CHANGE_FN * pAddressChangeFn
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= WINXP)
'/* The return buffer will contain SOCKADDR_IN for IPv4 */
%RPC_P_ADDR_FORMAT_TCP_IPV4     = 1

'/* The return buffer will contain SOCKADDR_STORAGE for IPv6 */
%RPC_P_ADDR_FORMAT_TCP_IPV6     = 2

DECLARE FUNCTION I_RpcServerInqLocalConnAddress IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerInqLocalConnAddress" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF Buffer AS ANY _                                ' __in_out void *Buffer
 , BYREF BufferSize AS DWORD _                          ' __in_out unsigned long *BufferSize
 , BYREF AddressFormat AS DWORD _                       ' __out unsigned long *AddressFormat
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcServerInqRemoteConnAddress IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerInqRemoteConnAddress" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF Buffer AS ANY _                                ' __in_out void *Buffer
 , BYREF BufferSize AS DWORD _                          ' __in_out unsigned long *BufferSize
 , BYREF AddressFormat AS DWORD _                       ' __out unsigned long *AddressFormat
 ) AS LONG                                              ' RPC_STATUS

DECLARE SUB I_RpcSessionStrictContextHandle IMPORT "RPCRT4.DLL" ALIAS "I_RpcSessionStrictContextHandle" ()   ' void

DECLARE FUNCTION I_RpcTurnOnEEInfoPropagation IMPORT "RPCRT4.DLL" ALIAS "I_RpcTurnOnEEInfoPropagation" ( _
 ) AS LONG                                              ' RPC_STATUS

'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

DECLARE FUNCTION I_RpcConnectionInqSockBuffSize IMPORT "RPCRT4.DLL" ALIAS "I_RpcConnectionInqSockBuffSize" ( _
   BYREF RecvBuffSize AS DWORD _                        ' __out unsigned long * RecvBuffSize
 , BYREF SendBuffSize AS DWORD _                        ' __out unsigned long * SendBuffSize
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcConnectionSetSockBuffSize IMPORT "RPCRT4.DLL" ALIAS "I_RpcConnectionSetSockBuffSize" ( _
   BYVAL RecvBuffSize AS DWORD _                        ' __in unsigned long * RecvBuffSize
 , BYVAL SendBuffSize AS DWORD _                        ' __in unsigned long * SendBuffSize
 ) AS LONG                                              ' RPC_STATUS

'typedef
'void
'(*RPCLT_PDU_FILTER_FUNC) (
'    IN void *Buffer,
'    IN unsigned int BufferLength,
'    IN int fDatagram
'    );

'typedef
'void
'(__cdecl *RPC_SETFILTER_FUNC) (
'    IN RPCLT_PDU_FILTER_FUNC pfnFilter
'    );

'#ifndef WINNT
'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcServerStartListening(
'    void * hWnd
'    ) ;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcServerStopListening(
'    ) ;

'typedef RPC_STATUS (*RPC_BLOCKING_FN) (
'    IN void * hWnd,
'    IN void * Context,
'    IN OPTIONAL void * hSyncEvent
'    ) ;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcBindingSetAsync(
'    IN RPC_BINDING_HANDLE Binding,
'    IN RPC_BLOCKING_FN BlockingFn,
'    IN unsigned long ServerTid
'    ) ;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcSetThreadParams(
'    IN int fClientFree,
'    IN OPTIONAL void *Context,
'    IN OPTIONAL void * hWndClient
'    );

'RPCRTAPI
'unsigned int
'RPC_ENTRY
'I_RpcWindowProc(
'    IN void * hWnd,
'    IN unsigned int Message,
'    IN unsigned int wParam,
'    IN unsigned long lParam
'    ) ;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcServerUnregisterEndpointA (
'    __in RPC_CSTR Protseq,
'    __in RPC_CSTR Endpoint
'    );

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcServerUnregisterEndpointW (
'    __in RPC_WSTR Protseq,
'    __in RPC_WSTR Endpoint
'    );

'#endif // WINNT

DECLARE FUNCTION I_RpcServerInqTransportType IMPORT "RPCRT4.DLL" ALIAS "I_RpcServerInqTransportType" ( _
   BYREF Type AS DWORD _                                ' __out unsigned int * Type
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcMapWin32Status IMPORT "RPCRT4.DLL" ALIAS "I_RpcMapWin32Status" ( _
   BYVAL Status AS DWORD _                              ' __in RPC_STATUS Status
 ) AS LONG                                              ' long

'#if (NTDDI_VERSION >= NTDDI_WS03)
%RPC_C_OPT_SESSION_ID         = 6
%RPC_C_OPT_COOKIE_AUTH        = 7
%RPC_C_OPT_RESOURCE_TYPE_UUID = 8

' // Size = 8 bytes
TYPE RPC_C_OPT_COOKIE_AUTH_DESCRIPTOR DWORD
   BufferSize AS DWORD        ' unsigned long // Length of the buffer in bytes
   Buffer     AS ASCIIZ PTR   ' char *// Zero-terminated string
END TYPE

'typedef struct _RDR_CALLOUT_STATE
'{
'    // LastError is used for debugging only - don't use it for processing
'    RPC_STATUS LastError;
'    void *LastEEInfo;

'    RPC_HTTP_REDIRECTOR_STAGE LastCalledStage;

'    // the information accumulated throughout the stages
'    unsigned short *ServerName;   // Allocated with MemAllocate
'    unsigned short *ServerPort;   // Allocated with MemAllocate
'    unsigned short *RemoteUser;   // Allocated with MemAllocate
'    unsigned short *AuthType;     // Allocated with MemAllocate
'    unsigned char ResourceTypePresent;
'    unsigned char SessionIdPresent;
'    unsigned char InterfacePresent;
'    UUID ResourceType;
'    UUID SessionId;
'    RPC_SYNTAX_IDENTIFIER Interface;
'    void *CertContext;            // Contains PCCERT_CONTEXT if cert is used for authentication.
'                                  // NULL otherwise. If allocated, CertFreeCertificateContext
'                                  // needs to be called on it when done
'} RDR_CALLOUT_STATE;

' // Size = 88 bytes
TYPE RDR_CALLOUT_STATE DWORD FILL
   LastError           AS DWORD                           ' RPC_STATUS
   LastEEInfo          AS DWORD                           ' void *
   LastCalledStage     AS LONG                            ' RPC_HTTP_REDIRECTOR_STAGE enum
   ServerName          AS WSTRINGZ PTR                    ' unsigned short * // Allocated with MemAllocate
   ServerPort          AS WSTRINGZ PTR                    ' unsigned short * // Allocated with MemAllocate
   RemoteUser          AS WSTRINGZ PTR                    ' unsigned short * // Allocated with MemAllocate
   AuthType            AS WSTRINGZ PTR                    ' unsigned short * // Allocated with MemAllocate
   ResourceTypePresent AS BYTE                            ' unsigned char
   SessionIdPresent    AS BYTE                            ' unsigned char
   InterfacePresent    AS BYTE                            ' unsigned char
   ResourceType        AS GUID                            ' UUID
   SessionId           AS GUID                            ' UUID
   Interface           AS RPC_SYNTAX_IDENTIFIER
   CertContext         AS DWORD                           ' void * // Contains PCCERT_CONTEXT if cert is used for authentication.
END TYPE
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcProxyIsValidMachineFn)
'        (
'        __in RPC_WSTR Machine,
'        __in RPC_WSTR DotMachine,
'        __in unsigned long PortNumber
'        );

'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcProxyGetClientAddressFn)
'        (
'        IN void *Context,
'        OUT char *Buffer,
'        OUT unsigned long *BufferLength
'        );

'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcProxyGetConnectionTimeoutFn)
'        (
'        OUT unsigned long *ConnectionTimeout
'        );
'#if (NTDDI_VERSION >= NTDDI_WS03)

'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcPerformCalloutFn)
'    (
'    IN void *Context,
'    IN RDR_CALLOUT_STATE *CallOutState,
'    IN RPC_HTTP_REDIRECTOR_STAGE Stage
'    );

'typedef void
'(RPC_ENTRY *I_RpcFreeCalloutStateFn)
'    (
'    IN RDR_CALLOUT_STATE *CallOutState
'    );

'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcProxyGetClientSessionAndResourceUUID)
'        (
'        __in void *Context,
'        __out_opt int *SessionIdPresent,
'        __out_opt UUID *SessionId,
'        __out int *ResourceIdPresent,
'        __out UUID *ResourceId
'        );

'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'typedef RPC_STATUS
'(RPC_ENTRY *I_RpcProxyFilterIfFn)
'    (
'    __in void *Context,
'    __in UUID *IfUuid,
'    __in unsigned short IfMajorVersion,
'    __out int *fAllow
'    );

' enum RpcPerfCounters alias RpcProxyPerfCounters
%RpcCurrentUniqueUser         = 1    ' //Current Number of Unique Users
%RpcBackEndConnectionAttempts = 2    ' // Number of Back-End Connection Attempts per Second
%RpcBackEndConnectionFailed   = 3    ' // Number of Failed Back-End Connection Attempts per Second
%RpcRequestsPerSecond         = 4    ' // RPC/HTTP Requests per Second
%RpcIncomingConnections       = 5    ' // Current Number of Incoming RPC over HTTP Connections
%RpcIncomingBandwidth         = 6    ' // Total Incoming Bandwidth from Back-End Servers
%RpcOutgoingBandwidth         = 7    ' // Total Outgoing Bandwidth to Back-End Servers
%RpcAttemptedLbsDecisions     = 8    ' // Attempted RPC Load Balancing Decisions per Second
%RpcFailedLbsDecisions        = 9    ' // Failed RPC Load Balancing Decisions per Second
%RpcAttemptedLbsMessages      = 10   ' // Attempted RPC Load Balancing Broker Requests per Second
%RpcFailedLbsMessages         = 11   ' // Failed RPC Load Balancing Broker Requests per Second
%RpcLastCounter               = 12

'typedef void
'(RPC_ENTRY *I_RpcProxyUpdatePerfCounterFn)
'    (
'    __in RpcPerfCounters Counter,
'    __in int ModifyTrend,
'    __in unsigned long Size
'    );

' typedef void
'(RPC_ENTRY *I_RpcProxyUpdatePerfCounterBackendServerFn)
'    (
'    __in unsigned short* MachineName,
'    __in int IsConnectEvent
'    );

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_PROXY_CONNECTION_TYPE_IN_PROXY  = 0
%RPC_PROXY_CONNECTION_TYPE_OUT_PROXY = 1

'#if (NTDDI_VERSION >= NTDDI_WS03)
'typedef struct tagI_RpcProxyCallbackInterface
'{
'    I_RpcProxyIsValidMachineFn IsValidMachineFn;
'    I_RpcProxyGetClientAddressFn GetClientAddressFn;
'    I_RpcProxyGetConnectionTimeoutFn GetConnectionTimeoutFn;
'    I_RpcPerformCalloutFn PerformCalloutFn;
'    I_RpcFreeCalloutStateFn FreeCalloutStateFn;
'    I_RpcProxyGetClientSessionAndResourceUUID GetClientSessionAndResourceUUIDFn;
'#if (NTDDI_VERSION >= NTDDI_VISTA)
'    I_RpcProxyFilterIfFn ProxyFilterIfFn;
'    I_RpcProxyUpdatePerfCounterFn RpcProxyUpdatePerfCounterFn;
'    I_RpcProxyUpdatePerfCounterBackendServerFn RpcProxyUpdatePerfCounterBackendServerFn;
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'} I_RpcProxyCallbackInterface;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcProxyNewConnection (
'    IN unsigned long ConnectionType,
'    IN unsigned short *ServerAddress,
'    IN unsigned short *ServerPort,
'    IN unsigned short *MinConnTimeout,
'    IN void *ConnectionParameter,
'    IN OPTIONAL RDR_CALLOUT_STATE *CallOutState,
'    IN I_RpcProxyCallbackInterface *ProxyCallbackInterface
'    );

'#else

'typedef struct tagI_RpcProxyCallbackInterface
'{
'    I_RpcProxyIsValidMachineFn IsValidMachineFn;
'    I_RpcProxyGetClientAddressFn GetClientAddressFn;
'    I_RpcProxyGetConnectionTimeoutFn GetConnectionTimeoutFn;
'} I_RpcProxyCallbackInterface;

'RPCRTAPI
'RPC_STATUS
'RPC_ENTRY
'I_RpcProxyNewConnection (
'    IN unsigned long ConnectionType,
'    IN unsigned short *ServerAddress,
'    IN unsigned short *ServerPort,
'    IN void *ConnectionParameter,
'    IN I_RpcProxyCallbackInterface *ProxyCallbackInterface
'    );
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_WS03)
' Not exported in Windows XP
DECLARE FUNCTION I_RpcReplyToClientWithStatus IMPORT "RPCRT4.DLL" ALIAS "I_RpcReplyToClientWithStatus" ( _
   BYVAL ConnectionParameter AS DWORD _                 ' __in void *ConnectionParameter
 , BYVAL RpcStatus AS DWORD _                           ' __in RPC_STATUS RpcStatus
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE FUNCTION I_RpcRecordCalloutFailure IMPORT "RPCRT4.DLL" ALIAS "I_RpcRecordCalloutFailure" ( _
   BYVAL RpcStatus AS DWORD _                           ' __in RPC_STATUS RpcStatus
 , BYREF CallOutState AS RDR_CALLOUT_STATE _            ' __in RDR_CALLOUT_STATE *CallOutState
 , BYVAL DllName AS DWORD _                             ' __in unsigned short *DllName
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
DECLARE FUNCTION I_RpcMgmtEnableDedicatedThreadPool IMPORT "RPCRT4.DLL" ALIAS "I_RpcMgmtEnableDedicatedThreadPool" ( _
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)
