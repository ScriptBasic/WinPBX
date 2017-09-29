' ########################################################################################
' Microsoft Windows
' File: RpcDce.inc
' Contents: DCE RPC runtime APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RPCDCE_INC = 1

#INCLUDE ONCE "basetsd.inc"   ' for MAXUINT_PTR

'/*typedef char small;*/
'/*typedef unsigned char byte;*/
'/*typedef unsigned char boolean;*/

'#include <specstrings.h>

'typedef __nullterminated unsigned char __RPC_FAR * RPC_CSTR;

'#if defined(RPC_USE_NATIVE_WCHAR) && defined(_NATIVE_WCHAR_T_DEFINED)
'typedef __nullterminated wchar_t __RPC_FAR * RPC_WSTR;
'typedef __nullterminated const wchar_t * RPC_CWSTR;
'#else
'typedef __nullterminated unsigned short __RPC_FAR * RPC_WSTR;
'typedef __nullterminated const unsigned short * RPC_CWSTR;
'#endif

'typedef I_RPC_HANDLE RPC_BINDING_HANDLE;
'typedef RPC_BINDING_HANDLE handle_t;
'#define rpc_binding_handle_t RPC_BINDING_HANDLE

#IF NOT %DEF(%GUIDDEF_INC)
%GUIDDEF_INC = 1
#INCLUDE ONCE "guiddef.inc"
#ENDIF ' /* GUID_DEFINED */

'#ifndef UUID_DEFINED
'#define UUID_DEFINED
'typedef GUID UUID;
'#ifndef uuid_t
'#define uuid_t UUID
'#endif
'#endif

' // Size = 8 bytes
TYPE RPC_BINDING_VECTOR DWORD
   Count       AS DWORD   ' unsigned long
   BindingH(0) AS DWORD   ' RPC_BINDING_HANDLE
END TYPE

' // Size = 8 bytes
TYPE UUID_VECTOR DWORD
  Count    AS DWORD       ' unsigned long
  Uuind(0) AS GUID PTR    ' UUID *Uuid[1];
END TYPE

'typedef void * RPC_IF_HANDLE;

#IF NOT %DEF(%IFID_DEFINED)
%IFID_DEFINED = 1
' // Size = 20 bytes
TYPE RPC_IF_ID WORD
   Uuid      AS GUID   ' UUID
   VersMajor AS WORD   ' unsigned short
   VersMinor AS WORD   ' unsigned short
END TYPE
#ENDIF

%RPC_C_BINDING_INFINITE_TIMEOUT     = 10
%RPC_C_BINDING_MIN_TIMEOUT          = 0
%RPC_C_BINDING_DEFAULT_TIMEOUT      = 5
%RPC_C_BINDING_MAX_TIMEOUT          = 9

%RPC_C_CANCEL_INFINITE_TIMEOUT      = -1

%RPC_C_LISTEN_MAX_CALLS_DEFAULT     = 1234
%RPC_C_PROTSEQ_MAX_REQS_DEFAULT     = 10

'// RPC_POLICY EndpointFlags.
%RPC_C_BIND_TO_ALL_NICS             = 1
%RPC_C_USE_INTERNET_PORT            = &H1
%RPC_C_USE_INTRANET_PORT            = &H2
%RPC_C_DONT_FAIL                    = &H4

'#if (NTDDI_VERSION < NTDDI_VISTA)
'// RPC_POLICY EndpointFlags specific to the Falcon/RPC transport (deprecated for Vista)
%RPC_C_MQ_TEMPORARY                 = &H0000
%RPC_C_MQ_PERMANENT                 = &H0001
%RPC_C_MQ_CLEAR_ON_OPEN             = &H0002
%RPC_C_MQ_USE_EXISTING_SECURITY     = &H0004
%RPC_C_MQ_AUTHN_LEVEL_NONE          = &H0000
%RPC_C_MQ_AUTHN_LEVEL_PKT_INTEGRITY = &H0008
%RPC_C_MQ_AUTHN_LEVEL_PKT_PRIVACY   = &H0010

'// Falcon/Rpc options are deprecated from Vista
%RPC_C_MQ_EXPRESS                   = 0   ' // Client: RPC_C_MQ_DELIVERY.
%RPC_C_MQ_RECOVERABLE               = 1

%RPC_C_MQ_JOURNAL_NONE              = 0   ' // Client: RPC_C_MQ_JOURNAL.
%RPC_C_MQ_JOURNAL_DEADLETTER        = 1
%RPC_C_MQ_JOURNAL_ALWAYS            = 2

'// Client: RpcBindingSetOption() values for the Falcon/RPC transport:
%RPC_C_OPT_MQ_DELIVERY              = 1
%RPC_C_OPT_MQ_PRIORITY              = 2
%RPC_C_OPT_MQ_JOURNAL               = 3
%RPC_C_OPT_MQ_ACKNOWLEDGE           = 4
%RPC_C_OPT_MQ_AUTHN_SERVICE         = 5
%RPC_C_OPT_MQ_AUTHN_LEVEL           = 6
%RPC_C_OPT_MQ_TIME_TO_REACH_QUEUE   = 7
%RPC_C_OPT_MQ_TIME_TO_BE_RECEIVED   = 8
'#endif // (NTDDI_VERSION < NTDDI_VISTA)
%RPC_C_OPT_BINDING_NONCAUSAL        = 9
%RPC_C_OPT_SECURITY_CALLBACK        = 10
%RPC_C_OPT_UNIQUE_BINDING           = 11
'#if (NTDDI_VERSION <= NTDDI_WIN2K)
'#define RPC_C_OPT_MAX_OPTIONS            12
'#elif (NTDDI_VERSION <= NTDDI_WS03)
%RPC_C_OPT_CALL_TIMEOUT             = 12
%RPC_C_OPT_DONT_LINGER              = 13
'%RPC_C_OPT_MAX_OPTIONS              = 14
'#else
%RPC_C_OPT_TRANS_SEND_BUFFER_SIZE   = 5
%RPC_C_OPT_CALL_TIMEOUT             = 12
%RPC_C_OPT_DONT_LINGER              = 13
%RPC_C_OPT_TRUST_PEER               = 14
%RPC_C_OPT_ASYNC_BLOCK              = 15
%RPC_C_OPT_OPTIMIZE_TIME            = 16
'%RPC_C_OPT_MAX_OPTIONS              = 17
'#endif // (NTDDI_VERSION <= NTDDI_WIN2K)

'// flags for RpcServerInqAuthClientEx
'//
%RPC_C_FULL_CERT_CHAIN              = &H0001

' // Size = 8 bytes
TYPE RPC_PROTSEQ_VECTORA DWORD
   Count      AS DWORD      ' unsigned int
   Protseq(0) AS BYTE PTR   ' unsigned char *
END TYPE

' // Size = 8 bytes
TYPE RPC_PROTSEQ_VECTORW DWORD
   Count      AS DWORD      ' unsigned int
   Protseq(0) AS WORD PTR   ' unsigned short *
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_PROTSEQ_VECTOR = RPC_PROTSEQ_VECTORW
#ELSE
   MACRO RPC_PROTSEQ_VECTOR = RPC_PROTSEQ_VECTORA
#ENDIF


' // Size = 12 bytes
TYPE RPC_POLICY DWORD
   Length        AS DWORD   ' unsigned int
   EndpointFlags AS DWORD   ' unsigned long
   NICFlags      AS DWORD   ' unsigned long
END TYPE

'typedef void __RPC_USER
'RPC_OBJECT_INQ_FN (
'    IN UUID * ObjectUuid,
'    OUT UUID * TypeUuid,
'    OUT RPC_STATUS * Status
'    );

'typedef RPC_STATUS RPC_ENTRY
'RPC_IF_CALLBACK_FN (
'    IN RPC_IF_HANDLE  InterfaceUuid,
'    IN void *Context
'    ) ;

'typedef void RPC_ENTRY
'RPC_SECURITY_CALLBACK_FN (
'    IN void *Context
'    ) ;

'#define RPC_MGR_EPV void

' // Size = 8 bytes
TYPE RPC_STATS_VECTOR DWORD
   Count    AS DWORD   ' unsigned int
   Stats(0) AS DWORD   ' unsigned long
END TYPE

%RPC_C_STATS_CALLS_IN  = 0
%RPC_C_STATS_CALLS_OUT = 1
%RPC_C_STATS_PKTS_IN   = 2
%RPC_C_STATS_PKTS_OUT  = 3

' // Size = 8 bytes
TYPE RPC_IF_ID_VECTOR DWORD
  Count   AS DWORD           ' unsigned long
  IfId(0) AS RPC_IF_ID PTR   ' RPC_IF_ID *
END TYPE

'/* client */
DECLARE FUNCTION RpcBindingCopy IMPORT "RPCRT4.DLL" ALIAS "RpcBindingCopy" ( _
   BYVAL SourceBinding AS DWORD _                       ' __in RPC_BINDING_HANDLE SourceBinding
 , BYREF DestinationBinding AS DWORD _                  ' __out RPC_BINDING_HANDLE * DestinationBinding
 ) AS LONG                                              ' RPC_STATUS

'/* client */
DECLARE FUNCTION RpcBindingFree IMPORT "RPCRT4.DLL" ALIAS "RpcBindingFree" ( _
   BYREF Binding AS DWORD _                             ' __inout RPC_BINDING_HANDLE * Binding
 ) AS LONG                                              ' RPC_STATUS

'/* client */
DECLARE FUNCTION RpcBindingSetOption IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetOption" ( _
   BYVAL hBinding AS DWORD _                            ' __in RPC_BINDING_HANDLE hBinding
 , BYVAL option AS DWORD _                              ' __in unsigned long      option
 , BYVAL optionValue AS DWORD _                         ' __in ULONG_PTR          optionValue
 ) AS LONG                                              ' RPC_STATUS

'/* client */
DECLARE FUNCTION RpcBindingInqOption IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqOption" ( _
   BYVAL hBinding AS DWORD _                            ' __in  RPC_BINDING_HANDLE hBinding
 , BYVAL option AS DWORD _                              ' __in  unsigned long      option
 , BYREF pOptionValue AS DWORD _                        ' __out ULONG_PTR          *pOptionValue
 ) AS LONG                                              ' RPC_STATUS

'/* client */

'#if !defined(_KRPCENV_)

DECLARE FUNCTION RpcBindingFromStringBindingA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingFromStringBindingA" ( _
   BYREF StringBinding AS ASCIIZ _                      ' __in RPC_CSTR StringBinding
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE *Binding
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingFromStringBindingW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingFromStringBindingW" ( _
   BYREF StringBinding AS WSTRINGZ _                    ' __in RPC_WSTR StringBinding
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE *Binding
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingFromStringBinding = RpcBindingFromStringBindingW
#ELSE
   MACRO RpcBindingFromStringBinding = RpcBindingFromStringBindingA
#ENDIF

'#endif /* _KRPCENV_ */

'/* client */

DECLARE FUNCTION RpcSsGetContextBinding IMPORT "RPCRT4.DLL" ALIAS "RpcSsGetContextBinding" ( _
   BYVAL ContextHandle AS DWORD _                       ' __in  void *ContextHandle
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE *Binding
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION RpcBindingInqObject IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqObject" ( _
   BYVAL Binding AS DWORD _                             ' __in  RPC_BINDING_HANDLE Binding
 , BYREF ObjectUuid AS GUID _                           ' __out UUID * ObjectUuid
 ) AS LONG                                              ' RPC_STATUS

'/* client */

DECLARE FUNCTION RpcBindingReset IMPORT "RPCRT4.DLL" ALIAS "RpcBindingReset" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 ) AS LONG                                              ' RPC_STATUS

'/* RpcBindingServerFromClient : UNSUPPORTED */
'/* RpcBindingSetAuthInfo */

'/* client */

DECLARE FUNCTION RpcBindingSetObject IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetObject" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ObjectUuid AS GUID _                           ' __in UUID * ObjectUuid
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION RpcMgmtInqDefaultProtectLevel IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqDefaultProtectLevel" ( _
   BYVAL AuthnSvc AS DWORD _                            ' __in  unsigned long AuthnSvc
 , BYREF AuthnLevel AS DWORD _                          ' __out unsigned long *AuthnLevel
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION RpcBindingToStringBindingA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingToStringBindingA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF StringBinding AS DWORD _                       ' __out RPC_CSTR *StringBinding
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingToStringBindingW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingToStringBindingW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF StringBinding AS DWORD _                       ' __out RPC_WSTR *StringBinding
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingToStringBinding = RpcBindingToStringBindingW
#ELSE
   MACRO RpcBindingToStringBinding = RpcBindingToStringBindingA
#ENDIF

'/* client/server */

DECLARE FUNCTION RpcBindingVectorFree IMPORT "RPCRT4.DLL" ALIAS "RpcBindingVectorFree" ( _
   BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __inout RPC_BINDING_VECTOR * BindingVector
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

'#if !defined(_KRPCENV_)

DECLARE FUNCTION RpcStringBindingComposeA IMPORT "RPCRT4.DLL" ALIAS "RpcStringBindingComposeA" ( _
   BYREF ObjUuid AS ASCIIZ _                            ' __in_opt RPC_CSTR ObjUuid
 , BYREF Protseq AS ASCIIZ _                            ' __in_opt RPC_CSTR Protseq
 , BYREF NetworkAddr AS ASCIIZ _                        ' __in_opt RPC_CSTR NetworkAddr
 , BYREF Endpoint AS ASCIIZ _                           ' __in_opt RPC_CSTR Endpoint
 , BYREF Options AS ASCIIZ _                            ' __in_opt RPC_CSTR Options
 , BYREF StringBinding AS DWORD _                       ' __opt_out RPC_CSTR *StringBinding
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcStringBindingComposeW IMPORT "RPCRT4.DLL" ALIAS "RpcStringBindingComposeW" ( _
   BYREF ObjUuid AS WSTRINGZ _                          ' __in_opt RPC_WSTR ObjUuid
 , BYREF Protseq AS WSTRINGZ _                          ' __in_opt RPC_WSTR Protseq
 , BYREF NetworkAddr AS WSTRINGZ _                      ' __in_opt RPC_WSTR NetworkAddr
 , BYREF Endpoint AS WSTRINGZ _                         ' __in_opt RPC_WSTR Endpoint
 , BYREF Options AS WSTRINGZ _                          ' __in_opt RPC_WSTR Options
 , BYREF StringBinding AS DWORD _                       ' __opt_out RPC_WSTR *StringBinding
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcStringBindingCompose = RpcStringBindingComposeW
#ELSE
   MACRO RpcStringBindingCompose = RpcStringBindingComposeA
#ENDIF

'/* client/server */

DECLARE FUNCTION RpcStringBindingParseA IMPORT "RPCRT4.DLL" ALIAS "RpcStringBindingParseA" ( _
   BYREF StringBinding AS ASCIIZ _                      ' __in RPC_CSTR StringBinding
 , BYREF ObjUuid AS DWORD _                             ' __opt_out RPC_CSTR *ObjUuid
 , BYREF Protseq AS DWORD _                             ' __opt_out RPC_CSTR *Protseq
 , BYREF NetworkAddr AS DWORD _                         ' __opt_out RPC_CSTR *NetworkAddr
 , BYREF Endpoint AS DWORD _                            ' __opt_out RPC_CSTR *Endpoint
 , BYREF NetworkOptions AS DWORD _                      ' __opt_out RPC_CSTR *NetworkOptions
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcStringBindingParseW IMPORT "RPCRT4.DLL" ALIAS "RpcStringBindingParseW" ( _
   BYREF StringBinding AS WSTRINGZ _                    ' __in RPC_WSTR StringBinding
 , BYREF ObjUuid AS DWORD _                             ' __opt_out RPC_WSTR *ObjUuid
 , BYREF Protseq AS DWORD _                             ' __opt_out RPC_WSTR *Protseq
 , BYREF NetworkAddr AS DWORD _                         ' __opt_out RPC_WSTR *NetworkAddr
 , BYREF Endpoint AS DWORD _                            ' __opt_out RPC_WSTR *Endpoint
 , BYREF NetworkOptions AS DWORD _                      ' __opt_out RPC_WSTR *NetworkOptions
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcStringBindingParse = RpcStringBindingParseW
#ELSE
   MACRO RpcStringBindingParse = RpcStringBindingParseA
#ENDIF

'#endif /* _KRPCENV_ */

'/* client/server */

DECLARE FUNCTION RpcStringFreeA IMPORT "RPCRT4.DLL" ALIAS "RpcStringFreeA" ( _
   BYREF String AS DWORD _                              ' __inout RPC_CSTR __RPC_FAR * String
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcStringFreeW IMPORT "RPCRT4.DLL" ALIAS "RpcStringFreeW" ( _
   BYREF String AS DWORD _                              ' __inout RPC_WSTR __RPC_FAR * String
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcStringFree = RpcStringFreeW
#ELSE
   MACRO RpcStringFree = RpcStringFreeA
#ENDIF

'/* client/server */

DECLARE FUNCTION RpcIfInqId IMPORT "RPCRT4.DLL" ALIAS "RpcIfInqId" ( _
   BYVAL RpcIfHandle AS DWORD _                         ' __in RPC_IF_HANDLE RpcIfHandle
 , BYREF RpcIfId AS RPC_IF_ID _                         ' __out RPC_IF_ID * RpcIfId
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION RpcNetworkIsProtseqValidA IMPORT "RPCRT4.DLL" ALIAS "RpcNetworkIsProtseqValidA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNetworkIsProtseqValidW IMPORT "RPCRT4.DLL" ALIAS "RpcNetworkIsProtseqValidW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNetworkIsProtseqValid = RpcNetworkIsProtseqValidW
#ELSE
   MACRO RpcNetworkIsProtseqValid = RpcNetworkIsProtseqValidA
#ENDIF

'/* client */

DECLARE FUNCTION RpcMgmtInqComTimeout IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqComTimeout" ( _
   BYVAL Binding AS DWORD _                             ' __in  RPC_BINDING_HANDLE Binding
 , BYREF Timeout AS DWORD _                             ' __out unsigned int * Timeout
 ) AS LONG                                              ' RPC_STATUS

'/* client */

DECLARE FUNCTION RpcMgmtSetComTimeout IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtSetComTimeout" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL Timeout AS DWORD _                             ' __in unsigned int Timeout
 ) AS LONG                                              ' RPC_STATUS

'/* client */

DECLARE FUNCTION RpcMgmtSetCancelTimeout IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtSetCancelTimeout" ( _
   BYVAL Timeout AS LONG _                              ' long Timeout
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcNetworkInqProtseqsA IMPORT "RPCRT4.DLL" ALIAS "RpcNetworkInqProtseqsA" ( _
   BYREF ProtseqVector AS RPC_PROTSEQ_VECTORA _         ' __out RPC_PROTSEQ_VECTORA * ProtseqVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNetworkInqProtseqsW IMPORT "RPCRT4.DLL" ALIAS "RpcNetworkInqProtseqsW" ( _
   BYREF ProtseqVector AS RPC_PROTSEQ_VECTORW _         ' __out RPC_PROTSEQ_VECTORW * ProtseqVector
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNetworkInqProtseqs = RpcNetworkInqProtseqsW
#ELSE
   MACRO RpcNetworkInqProtseqs = RpcNetworkInqProtseqsA
#ENDIF

'/* server */

DECLARE FUNCTION RpcObjectInqType IMPORT "RPCRT4.DLL" ALIAS "RpcObjectInqType" ( _
   BYREF ObjUuid AS GUID _                              ' __in UUID * ObjUuid
 , BYREF TypeUuid AS GUID _                             ' __out UUID * TypeUuid OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcObjectSetInqFn IMPORT "RPCRT4.DLL" ALIAS "RpcObjectSetInqFn" ( _
   BYVAL InquiryFn AS DWORD _                           ' __in RPC_OBJECT_INQ_FN * InquiryFn
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcObjectSetType IMPORT "RPCRT4.DLL" ALIAS "RpcObjectSetType" ( _
   BYREF ObjUuid AS GUID _                              ' __in UUID * ObjUuid
 , BYREF TypeUuid AS GUID _                             ' __in UUID * TypeUuid OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcProtseqVectorFreeA IMPORT "RPCRT4.DLL" ALIAS "RpcProtseqVectorFreeA" ( _
   BYREF ProtseqVector AS RPC_PROTSEQ_VECTORA _         ' __inout RPC_PROTSEQ_VECTORA * ProtseqVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcProtseqVectorFreeW IMPORT "RPCRT4.DLL" ALIAS "RpcProtseqVectorFreeW" ( _
   BYREF ProtseqVector AS RPC_PROTSEQ_VECTORW _         ' __inout RPC_PROTSEQ_VECTORW * ProtseqVector
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcProtseqVectorFree = RpcProtseqVectorFreeW
#ELSE
   MACRO RpcProtseqVectorFree = RpcProtseqVectorFreeA
#ENDIF

'/* server */

DECLARE FUNCTION RpcServerInqBindings IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqBindings" ( _
   BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __out RPC_BINDING_VECTOR * BindingVector
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerInqIf IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqIf" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid OPTIONAL
 , BYREF MgrEpv AS DWORD _                              ' __out RPC_MGR_EPV * MgrEpv
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerListen IMPORT "RPCRT4.DLL" ALIAS "RpcServerListen" ( _
   BYVAL MinimumCallThreads AS DWORD _                  ' __in unsigned int MinimumCallThreads
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL DontWait AS DWORD _                            ' __in unsigned int DontWait
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerRegisterIf IMPORT "RPCRT4.DLL" ALIAS "RpcServerRegisterIf" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid OPTIONAL
 , BYVAL MgrEpv AS DWORD _                              ' __in RPC_MGR_EPV * MgrEpv OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerRegisterIfEx IMPORT "RPCRT4.DLL" ALIAS "RpcServerRegisterIfEx" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid
 , BYVAL MgrEpv AS DWORD _                              ' __in RPC_MGR_EPV * MgrEpv
 , BYVAL Flags AS DWORD _                               ' __in unsigned int Flags
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfCallback AS DWORD _                          ' __in RPC_IF_CALLBACK_FN *IfCallback
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerRegisterIf2 IMPORT "RPCRT4.DLL" ALIAS "RpcServerRegisterIf2" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid
 , BYVAL MgrEpv AS DWORD _                              ' __in RPC_MGR_EPV * MgrEpv
 , BYVAL Flags AS DWORD _                               ' __in unsigned int Flags
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL MaxRpcSize AS DWORD _                          ' __in unsigned int MaxRpcSize
 , BYVAL IfCallback AS DWORD _                          ' __in RPC_IF_CALLBACK_FN *IfCallback
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerUnregisterIf IMPORT "RPCRT4.DLL" ALIAS "RpcServerUnregisterIf" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid OPTIONAL
 , BYVAL WaitForCallsToComplete AS DWORD _              ' __in unsigned int WaitForCallsToComplete
 ) AS LONG                                              ' RPC_STATUS

'/* server */

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION RpcServerUnregisterIfEx IMPORT "RPCRT4.DLL" ALIAS "RpcServerUnregisterIfEx" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF MgrTypeUuid AS GUID _                          ' __in UUID * MgrTypeUuid OPTIONAL
 , BYVAL RundownContextHandles AS DWORD _               ' __in int RundownContextHandles
 ) AS LONG                                              ' RPC_STATUS
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'/* server */

DECLARE FUNCTION RpcServerUseAllProtseqs IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseAllProtseqs" ( _
   BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerUseAllProtseqsEx IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseAllProtseqsEx" ( _
   BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor OPTIONAL
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerUseAllProtseqsIf IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseAllProtseqsIf" ( _
   BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerUseAllProtseqsIfEx IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseAllProtseqsIfEx" ( _
   BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in void * SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcServerUseProtseqA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqW" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseq = RpcServerUseProtseqW
#ELSE
   MACRO RpcServerUseProtseq = RpcServerUseProtseqA
#ENDIF

DECLARE FUNCTION RpcServerUseProtseqExA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqExA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqExW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqExW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseqEx = RpcServerUseProtseqExW
#ELSE
   MACRO RpcServerUseProtseqEx = RpcServerUseProtseqExA
#ENDIF

'/* server */

DECLARE FUNCTION RpcServerUseProtseqEpA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqEpA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS ASCIIZ _                           ' __in RPC_CSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqEpW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqEpW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS WSTRINGZ _                         ' __in RPC_WSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseqEp = RpcServerUseProtseqEpW
#ELSE
   MACRO RpcServerUseProtseqEp = RpcServerUseProtseqEpA
#ENDIF

DECLARE FUNCTION RpcServerUseProtseqEpExA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqEpExA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS ASCIIZ _                           ' __in RPC_CSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqEpExW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqEpExW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYREF Endpoint AS WSTRINGZ _                         ' __in RPC_WSTR Endpoint
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseqEpEx = RpcServerUseProtseqEpExW
#ELSE
   MACRO RpcServerUseProtseqEpEx = RpcServerUseProtseqEpExA
#ENDIF

'/* server */

DECLARE FUNCTION RpcServerUseProtseqIfA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqIfA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqIfW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqIfW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseqIf = RpcServerUseProtseqIfW
#ELSE
   MACRO RpcServerUseProtseqIf = RpcServerUseProtseqIfA
#ENDIF

DECLARE FUNCTION RpcServerUseProtseqIfExA IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqIfExA" ( _
   BYREF Protseq AS ASCIIZ _                            ' __in RPC_CSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerUseProtseqIfExW IMPORT "RPCRT4.DLL" ALIAS "RpcServerUseProtseqIfExW" ( _
   BYREF Protseq AS WSTRINGZ _                          ' __in RPC_WSTR Protseq
 , BYVAL MaxCalls AS DWORD _                            ' __in unsigned int MaxCalls
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYVAL SecurityDescriptor AS DWORD _                  ' __in_opt void *SecurityDescriptor
 , BYREF Policy AS RPC_POLICY _                         ' __in PRPC_POLICY Policy
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerUseProtseqIfEx = RpcServerUseProtseqIfExW
#ELSE
   MACRO RpcServerUseProtseqIfEx = RpcServerUseProtseqIfExA
#ENDIF

DECLARE SUB RpcServerYield IMPORT "RPCRT4.DLL" ALIAS "RpcServerYield" ()   ' void

'/* server */

DECLARE FUNCTION RpcMgmtStatsVectorFree IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtStatsVectorFree" ( _
   BYREF StatsVector AS RPC_STATS_VECTOR _              ' __in RPC_STATS_VECTOR ** StatsVector
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcMgmtInqStats IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqStats" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF Statistics AS RPC_STATS_VECTOR _               ' __out RPC_STATS_VECTOR ** Statistics
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcMgmtIsServerListening IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtIsServerListening" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE FUNCTION RpcMgmtStopServerListening IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtStopServerListening" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE SUB RpcMgmtWaitServerListen IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtWaitServerListen" ()   ' void

'/* server */

DECLARE FUNCTION RpcMgmtSetServerStackSize IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtSetServerStackSize" ( _
   BYVAL ThreadStackSize AS DWORD _                     ' __in unsigned long ThreadStackSize
 ) AS LONG                                              ' RPC_STATUS

'/* server */

DECLARE SUB RpcSsDontSerializeContext IMPORT "RPCRT4.DLL" ALIAS "RpcSsDontSerializeContext" ()   ' void

'/* client */

DECLARE FUNCTION RpcMgmtEnableIdleCleanup IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEnableIdleCleanup" ( _
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtInqIfIds IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqIfIds" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF IfIdVector AS RPC_IF_ID_VECTOR _               ' __out RPC_IF_ID_VECTOR * IfIdVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcIfIdVectorFree IMPORT "RPCRT4.DLL" ALIAS "RpcIfIdVectorFree" ( _
   BYREF IfIdVector AS RPC_IF_ID_VECTOR _               ' __inout RPC_IF_ID_VECTOR * IfIdVector
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtInqServerPrincNameA IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqServerPrincNameA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYREF ServerPrincName AS DWORD _                     ' __out  RPC_CSTR *ServerPrincName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtInqServerPrincNameW IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtInqServerPrincNameW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYREF ServerPrincName AS DWORD _                     ' __out RPC_WSTR *ServerPrincName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcMgmtInqServerPrincName = RpcMgmtInqServerPrincNameW
#ELSE
   MACRO RpcMgmtInqServerPrincName = RpcMgmtInqServerPrincNameA
#ENDIF

DECLARE FUNCTION RpcServerInqDefaultPrincNameA IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqDefaultPrincNameA" ( _
   BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYREF PrincName AS DWORD _                           ' __out RPC_CSTR *PrincName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerInqDefaultPrincNameW IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqDefaultPrincNameW" ( _
   BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYREF PrincName AS DWORD _                           ' __out RPC_WSTR *PrincName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerInqDefaultPrincName = RpcServerInqDefaultPrincNameW
#ELSE
   MACRO RpcServerInqDefaultPrincName = RpcServerInqDefaultPrincNameA
#ENDIF

'/* client */

DECLARE FUNCTION RpcEpResolveBinding IMPORT "RPCRT4.DLL" ALIAS "RpcEpResolveBinding" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 ) AS LONG                                              ' RPC_STATUS

'/* client */

DECLARE FUNCTION RpcNsBindingInqEntryNameA IMPORT "RPCRT4.DLL" ALIAS "RpcNsBindingInqEntryNameA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS DWORD _                           ' __out  RPC_CSTR *EntryName
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcNsBindingInqEntryNameW IMPORT "RPCRT4.DLL" ALIAS "RpcNsBindingInqEntryNameW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYVAL EntryNameSyntax AS DWORD _                     ' __in unsigned long EntryNameSyntax
 , BYREF EntryName AS DWORD _                           ' __out RPC_WSTR *EntryName
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcNsBindingInqEntryName = RpcNsBindingInqEntryNameW
#ELSE
   MACRO RpcNsBindingInqEntryName = RpcNsBindingInqEntryNameA
#ENDIF

%RPC_C_AUTHN_LEVEL_DEFAULT       = 0
%RPC_C_AUTHN_LEVEL_NONE          = 1
%RPC_C_AUTHN_LEVEL_CONNECT       = 2
%RPC_C_AUTHN_LEVEL_CALL          = 3
%RPC_C_AUTHN_LEVEL_PKT           = 4
%RPC_C_AUTHN_LEVEL_PKT_INTEGRITY = 5
%RPC_C_AUTHN_LEVEL_PKT_PRIVACY   = 6

%RPC_C_IMP_LEVEL_DEFAULT         = 0
%RPC_C_IMP_LEVEL_ANONYMOUS       = 1
%RPC_C_IMP_LEVEL_IDENTIFY        = 2
%RPC_C_IMP_LEVEL_IMPERSONATE     = 3
%RPC_C_IMP_LEVEL_DELEGATE        = 4

%RPC_C_QOS_IDENTITY_STATIC       = 0
%RPC_C_QOS_IDENTITY_DYNAMIC      = 1

%RPC_C_QOS_CAPABILITIES_DEFAULT                 = &H0
%RPC_C_QOS_CAPABILITIES_MUTUAL_AUTH             = &H1
%RPC_C_QOS_CAPABILITIES_MAKE_FULLSIC            = &H2
%RPC_C_QOS_CAPABILITIES_ANY_AUTHORITY           = &H4

'#if (NTDDI_VERSION >= NTDDI_WS03)
%RPC_C_QOS_CAPABILITIES_IGNORE_DELEGATE_FAILURE = &H8
%RPC_C_QOS_CAPABILITIES_LOCAL_MA_HINT           = &H10
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_C_QOS_CAPABILITIES_SCHANNEL_FULL_AUTH_IDENTITY = &H20
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_C_PROTECT_LEVEL_DEFAULT       = %RPC_C_AUTHN_LEVEL_DEFAULT
%RPC_C_PROTECT_LEVEL_NONE          = %RPC_C_AUTHN_LEVEL_NONE
%RPC_C_PROTECT_LEVEL_CONNECT       = %RPC_C_AUTHN_LEVEL_CONNECT
%RPC_C_PROTECT_LEVEL_CALL          = %RPC_C_AUTHN_LEVEL_CALL
%RPC_C_PROTECT_LEVEL_PKT           = %RPC_C_AUTHN_LEVEL_PKT
%RPC_C_PROTECT_LEVEL_PKT_INTEGRITY = %RPC_C_AUTHN_LEVEL_PKT_INTEGRITY
%RPC_C_PROTECT_LEVEL_PKT_PRIVACY   = %RPC_C_AUTHN_LEVEL_PKT_PRIVACY

%RPC_C_AUTHN_NONE          = 0
%RPC_C_AUTHN_DCE_PRIVATE   = 1
%RPC_C_AUTHN_DCE_PUBLIC    = 2
%RPC_C_AUTHN_DEC_PUBLIC    = 4
%RPC_C_AUTHN_GSS_NEGOTIATE = 9
%RPC_C_AUTHN_WINNT         = 10
%RPC_C_AUTHN_GSS_SCHANNEL  = 14
%RPC_C_AUTHN_GSS_KERBEROS  = 16
%RPC_C_AUTHN_DPA           = 17
%RPC_C_AUTHN_MSN           = 18
'#if (NTDDI_VERSION >= WINXP)
%RPC_C_AUTHN_DIGEST        = 21
'#endif // (NTDDI_VERSION >= WINXP)
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%RPC_C_AUTHN_KERNEL        = 20
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

%RPC_C_AUTHN_NEGO_EXTENDER = 30
%RPC_C_AUTHN_PKU2U         = 31

%RPC_C_AUTHN_MQ            = 100
%RPC_C_AUTHN_DEFAULT       = &HFFFFFFFF???

%RPC_C_NO_CREDENTIALS = %MAXUINT_PTR

%RPC_C_SECURITY_QOS_VERSION   = 1???
%RPC_C_SECURITY_QOS_VERSION_1 = 1???

' // Size = 16 bytes
TYPE RPC_SECURITY_QOS DWORD
   Version           AS DWORD   ' unsigned long
   Capabilities      AS DWORD   ' unsigned long
   IdentityTracking  AS DWORD   ' unsigned long
   ImpersonationType AS DWORD   ' unsigned long
END TYPE

#IF NOT %DEF(%AUTH_IDENTITY_DEFINED)
%AUTH_IDENTITY_DEFINED = 1

%SEC_WINNT_AUTH_IDENTITY_ANSI    = &H1
%SEC_WINNT_AUTH_IDENTITY_UNICODE = &H2

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_W DWORD
   User           AS WSTRINGZ PTR   ' unsigned short *
   UserLength     AS DWORD          ' unsigned long
   Domain         AS WSTRINGZ PTR   ' unsigned short *
   DomainLength   AS DWORD          ' unsigned long
   Password       AS WSTRINGZ PTR   ' unsigned short *
   PasswordLength AS DWORD          ' unsigned long
   Flags          AS DWORD          ' unsigned long
END TYPE

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_A DWORD
   User           AS BYTE PTR   ' unsigned char *
   UserLength     AS DWORD      ' unsigned long
   Domain         AS BYTE PTR   ' unsigned char *
   DomainLength   AS DWORD      ' unsigned long
   Password       AS BYTE PTR   ' unsigned char *
   PasswordLength AS DWORD      ' unsigned long
   Flags          AS DWORD      ' unsigned long
END TYPE

#IF %DEF(%UNICODE)
   MACRO SEC_WINNT_AUTH_IDENTITY = SEC_WINNT_AUTH_IDENTITY_W
#ELSE
   MACRO SEC_WINNT_AUTH_IDENTITY = SEC_WINNT_AUTH_IDENTITY_A
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXP)

%RPC_C_SECURITY_QOS_VERSION_2      = 2???

%RPC_C_AUTHN_INFO_TYPE_HTTP        = 1???

%RPC_C_HTTP_AUTHN_TARGET_SERVER    = 1???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_C_HTTP_AUTHN_TARGET_PROXY     = 2???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_C_HTTP_AUTHN_SCHEME_BASIC     = &H00000001???
%RPC_C_HTTP_AUTHN_SCHEME_NTLM      = &H00000002???
%RPC_C_HTTP_AUTHN_SCHEME_PASSPORT  = &H00000004???
%RPC_C_HTTP_AUTHN_SCHEME_DIGEST    = &H00000008???
%RPC_C_HTTP_AUTHN_SCHEME_NEGOTIATE = &H00000010???
'#if (NTDDI_VERSION >= NTDDI_WS03)
%RPC_C_HTTP_AUTHN_SCHEME_CERT      = &H00010000???
'// &H00020000 and &H00040000 are reserved
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

%RPC_C_HTTP_FLAG_USE_SSL                = 1
%RPC_C_HTTP_FLAG_USE_FIRST_AUTH_SCHEME  = 2
'#if (NTDDI_VERSION >= NTDDI_WS03)
%RPC_C_HTTP_FLAG_IGNORE_CERT_CN_INVALID = 8
'#endif // (NTDDI_VERSION >= NTDDI_WS03)
'#if (NTDDI_VERSION >= NTDDI_VISTASP1)
%RPC_C_HTTP_FLAG_ENABLE_CERT_REVOCATION_CHECK = 16
'#endif // (NTDDI_VERSION >= NTDDI_VISTASP1)

' // Size = 24 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_W DWORD
   TransportCredentials     AS SEC_WINNT_AUTH_IDENTITY_W PTR   ' SEC_WINNT_AUTH_IDENTITY_W *
   Flags                    AS DWORD                           ' unsigned long
   AuthenticationTarget     AS DWORD                           ' unsigned long
   NumberOfAuthnSchemes     AS DWORD                           ' unsigned long
   AuthnSchemes             AS DWORD PTR                       ' unsigned long *
   ServerCertificateSubject AS WSTRINGZ PTR                    ' unsigned short *
END TYPE

' // Size = 24 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_A DWORD
   TransportCredentials     AS SEC_WINNT_AUTH_IDENTITY_A PTR   ' SEC_WINNT_AUTH_IDENTITY_A *
   Flags                    AS DWORD                           ' unsigned long
   AuthenticationTarget     AS DWORD                           ' unsigned long
   NumberOfAuthnSchemes     AS DWORD                           ' unsigned long
   AuthnSchemes             AS DWORD PTR                       ' unsigned long *
   ServerCertificateSubject AS WSTRINGZ PTR                    ' unsigned short *
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS = RPC_HTTP_TRANSPORT_CREDENTIALS_W
#ELSE
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS = RPC_HTTP_TRANSPORT_CREDENTIALS_A
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 36 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W DWORD
   TransportCredentials      AS SEC_WINNT_AUTH_IDENTITY_W PTR   ' SEC_WINNT_AUTH_IDENTITY_W*
   Flags                     AS DWORD                           ' unsigned long
   AuthenticationTarget      AS DWORD                           ' unsigned long
   NumberOfAuthnSchemes      AS DWORD                           ' unsigned long
   AuthnSchemes              AS DWORD PTR                       ' unsigned long *
   ServerCertificateSubject  AS WSTRINGZ PTR                    ' unsigned short*
   ProxyCredentials          AS SEC_WINNT_AUTH_IDENTITY_W PTR   ' SEC_WINNT_AUTH_IDENTITY_W * *
   NumberOfProxyAuthnSchemes AS DWORD                           ' unsigned long
   ProxyAuthnSchemes         AS DWORD PTR                       ' unsigned long *
END TYPE

' // Size = 36 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A DWORD
   TransportCredentials      AS SEC_WINNT_AUTH_IDENTITY_A PTR   ' SEC_WINNT_AUTH_IDENTITY_A*
   Flags                     AS DWORD                           ' unsigned long
   AuthenticationTarget      AS DWORD                           ' unsigned long
   NumberOfAuthnSchemes      AS DWORD                           ' unsigned long
   AuthnSchemes              AS DWORD PTR                       ' unsigned long *
   ServerCertificateSubject  AS WSTRINGZ PTR                    ' unsigned short*
   ProxyCredentials          AS SEC_WINNT_AUTH_IDENTITY_A PTR   ' SEC_WINNT_AUTH_IDENTITY_A * *
   NumberOfProxyAuthnSchemes AS DWORD                           ' unsigned long
   ProxyAuthnSchemes         AS DWORD PTR                       ' unsigned long *
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS_V2 = RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
#ELSE
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS_V2 = RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' // Size = 36 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W DWORD
   TransportCredentials      AS DWORD           ' RPC_AUTH_IDENTITY_HANDLE
   Flags                     AS DWORD           ' unsigned long
   AuthenticationTarget      AS DWORD           ' unsigned long
   NumberOfAuthnSchemes      AS DWORD           ' unsigned long
   AuthnSchemes              AS DWORD PTR       ' __field_ecount(NumberOfAuthnSchemes) unsigned long*
   ServerCertificateSubject  AS WSTRINGZ PTR    ' unsigned short __RPC_FAR *
   ProxyCredentials          AS DWORD           ' RPC_AUTH_IDENTITY_HANDLE
   NumberOfProxyAuthnSchemes AS DWORD           ' unsigned long
   ProxyAuthnSchemes         AS DWORD PTR       ' __field_ecount(NumberOfProxyAuthnSchemes) unsigned long*
END TYPE

' // Size = 36 bytes
TYPE RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A DWORD
   TransportCredentials      AS DWORD       ' RPC_AUTH_IDENTITY_HANDLE
   Flags                     AS DWORD       ' unsigned long
   AuthenticationTarget      AS DWORD       ' unsigned long
   NumberOfAuthnSchemes      AS DWORD       ' unsigned long
   AuthnSchemes              AS DWORD PTR   ' __field_ecount(NumberOfAuthnSchemes) unsigned long*
   ServerCertificateSubject  AS ASCIIZ PTR  ' unsigned char __RPC_FAR *
   ProxyCredentials          AS DWORD       ' RPC_AUTH_IDENTITY_HANDLE
   NumberOfProxyAuthnSchemes AS DWORD       ' unsigned long
   ProxyAuthnSchemes         AS DWORD PTR   ' __field_ecount(NumberOfProxyAuthnSchemes) unsigned long*
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS_V3 = RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
#ELSE
   MACRO RPC_HTTP_TRANSPORT_CREDENTIALS_V3 = RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'typedef struct _RPC_SECURITY_QOS_V2_W {
'  unsigned long Version;
'  unsigned long Capabilities;
'  unsigned long IdentityTracking;
'  unsigned long ImpersonationType;
'  unsigned long AdditionalSecurityInfoType;
'  union
'      {
'      RPC_HTTP_TRANSPORT_CREDENTIALS_W *HttpCredentials;
'      } u;
'} RPC_SECURITY_QOS_V2_W, *PRPC_SECURITY_QOS_V2_W;

' // Size = 24 bytes
TYPE RPC_SECURITY_QOS_V2_W DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_W PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_W *
END TYPE

' // Size = 24 bytes
TYPE RPC_SECURITY_QOS_V2_A DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_A PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_A *
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_SECURITY_QOS_V2 = RPC_SECURITY_QOS_V2_W
#ELSE
   MACRO RPC_SECURITY_QOS_V2 = RPC_SECURITY_QOS_V2_A
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WS03)
%RPC_C_SECURITY_QOS_VERSION_3 = 3???

' // Size = 28 bytes
TYPE RPC_SECURITY_QOS_V3_W DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_W PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_W *
   Sid                        AS DWORD                                  ' void *Sid
END TYPE

' // Size = 28 bytes
TYPE RPC_SECURITY_QOS_V3_A DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_A PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_A *
   Sid                        AS DWORD                                  ' void *Sid
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_SECURITY_QOS_V3 = RPC_SECURITY_QOS_V3_W
#ELSE
   MACRO RPC_SECURITY_QOS_V3 = RPC_SECURITY_QOS_V3_A
#ENDIF
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_C_SECURITY_QOS_VERSION_4 = 4???

' // Size = 32 bytes
TYPE RPC_SECURITY_QOS_V4_W DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_W PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_W *
   Sid                        AS DWORD                                  ' void *Sid
   EffectiveOnly              AS DWORD                                  ' unsigned int
END TYPE

' // Size = 32 bytes
TYPE RPC_SECURITY_QOS_V4_A DWORD
   Version                    AS DWORD                                  ' unsigned long
   Capabilities               AS DWORD                                  ' unsigned long
   IdentityTracking           AS DWORD                                  ' unsigned long
   ImpersonationType          AS DWORD                                  ' unsigned long
   AdditionalSecurityInfoType AS DWORD                                  ' unsigned long
   HttpCredentials            AS RPC_HTTP_TRANSPORT_CREDENTIALS_A PTR   ' RPC_HTTP_TRANSPORT_CREDENTIALS_A *
   Sid                        AS DWORD                                  ' void *Sid
   EffectiveOnly              AS DWORD                                  ' unsigned int
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_SECURITY_QOS_V4 = RPC_SECURITY_QOS_V4_W
#ELSE
   MACRO RPC_SECURITY_QOS_V4 = RPC_SECURITY_QOS_V4_A
#ENDIF

'#endif // NTDDI_WINXP
#ENDIF   ' //_AUTH_IDENTITY_DEFINED
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= WINXP)

'#ifdef UNICODE

'#define RPC_SECURITY_QOS_V2 RPC_SECURITY_QOS_V2_W
'#define PRPC_SECURITY_QOS_V2 PRPC_SECURITY_QOS_V2_W
'#define _RPC_SECURITY_QOS_V2 _RPC_SECURITY_QOS_V2_W

'#define RPC_HTTP_TRANSPORT_CREDENTIALS RPC_HTTP_TRANSPORT_CREDENTIALS_W
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS PRPC_HTTP_TRANSPORT_CREDENTIALS_W
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS _RPC_HTTP_TRANSPORT_CREDENTIALS_W

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#define RPC_HTTP_TRANSPORT_CREDENTIALS_V2 RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS_V2 PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS_V2 _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'#define RPC_HTTP_TRANSPORT_CREDENTIALS_V3 RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS_V3 PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS_V3 _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'#if (NTDDI_VERSION >= NTDDI_WS03)
'#define RPC_SECURITY_QOS_V3 RPC_SECURITY_QOS_V3_W
'#define PRPC_SECURITY_QOS_V3 PRPC_SECURITY_QOS_V3_W
'#define _RPC_SECURITY_QOS_V3 _RPC_SECURITY_QOS_V3_W
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#define RPC_SECURITY_QOS_V4 RPC_SECURITY_QOS_V4_W
'#define PRPC_SECURITY_QOS_V4 PRPC_SECURITY_QOS_V4_W
'#define _RPC_SECURITY_QOS_V4 _RPC_SECURITY_QOS_V4_W
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#else // UNICODE

'#define RPC_SECURITY_QOS_V2 RPC_SECURITY_QOS_V2_A
'#define PRPC_SECURITY_QOS_V2 PRPC_SECURITY_QOS_V2_A
'#define _RPC_SECURITY_QOS_V2 _RPC_SECURITY_QOS_V2_A

'#define RPC_HTTP_TRANSPORT_CREDENTIALS RPC_HTTP_TRANSPORT_CREDENTIALS_A
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS PRPC_HTTP_TRANSPORT_CREDENTIALS_A
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS _RPC_HTTP_TRANSPORT_CREDENTIALS_A

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#define RPC_HTTP_TRANSPORT_CREDENTIALS_V2 RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS_V2 PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS_V2 _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_A
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'#define RPC_HTTP_TRANSPORT_CREDENTIALS_V3 RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
'#define PRPC_HTTP_TRANSPORT_CREDENTIALS_V3 PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
'#define _RPC_HTTP_TRANSPORT_CREDENTIALS_V3 _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_A
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'#if (NTDDI_VERSION >= NTDDI_WS03)
'#define RPC_SECURITY_QOS_V3 RPC_SECURITY_QOS_V3_A
'#define PRPC_SECURITY_QOS_V3 PRPC_SECURITY_QOS_V3_A
'#define _RPC_SECURITY_QOS_V3 _RPC_SECURITY_QOS_V3_A
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#define RPC_SECURITY_QOS_V4 RPC_SECURITY_QOS_V4_A
'#define PRPC_SECURITY_QOS_V4 PRPC_SECURITY_QOS_V4_A
'#define _RPC_SECURITY_QOS_V4 _RPC_SECURITY_QOS_V4_A
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#endif // UNICODE

'#if (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_PROTSEQ_TCP                             = &H1
%RPC_PROTSEQ_NMP                             = &H2
%RPC_PROTSEQ_LRPC                            = &H3
%RPC_PROTSEQ_HTTP                            = &H4

%RPC_BHT_OBJECT_UUID_VALID                   = &H1

%RPC_BHO_NONCAUSAL                           = &H1
%RPC_BHO_DONTLINGER                          = &H2
%RPC_BHO_EXCLUSIVE_AND_GUARANTEED            = &H4

' // Size = 4 bytes
UNION RPC_BINDING_HANDLE_TEMPLATE_V1_W_UNION DWORD
   Reserved AS WORD PTR   ' unsigned short *
END UNION

' // Size = 40 bytes
TYPE RPC_BINDING_HANDLE_TEMPLATE_V1_W DWORD
   Version          AS DWORD           ' unsigned long
   Flags            AS DWORD           ' unsigned long
   ProtocolSequence AS DWORD           ' unsigned long
   NetworkAddress   AS WSTRINGZ PTR    ' unsigned short *
   StringEndpoint   AS WSTRINGZ PTR    ' unsigned short *
   u1               AS RPC_BINDING_HANDLE_TEMPLATE_V1_W_UNION
   ObjectUuid       AS GUID            ' UUID
END TYPE

' // Size = 4 bytes
UNION RPC_BINDING_HANDLE_TEMPLATE_V1_A_UNION DWORD
   Reserved AS BYTE PTR   ' unsigned char *
END UNION

' // Size = 40 bytes
TYPE RPC_BINDING_HANDLE_TEMPLATE_V1_A DWORD
   Version          AS DWORD          ' unsigned long
   Flags            AS DWORD         ' unsigned long
   ProtocolSequence AS DWORD          ' unsigned long
   NetworkAddress   AS WSTRINGZ PTR   ' unsigned short *
   StringEndpoint   AS WSTRINGZ PTR   ' unsigned short *
   u1               AS RPC_BINDING_HANDLE_TEMPLATE_V1_A_UNION
   ObjectUuid       AS GUID           ' UUID
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_BINDING_HANDLE_TEMPLATE_V1 = RPC_BINDING_HANDLE_TEMPLATE_V1_W
#ELSE
   MACRO RPC_BINDING_HANDLE_TEMPLATE_V1 = RPC_BINDING_HANDLE_TEMPLATE_V1_A
#ENDIF

' // Size = 24 bytes
TYPE RPC_BINDING_HANDLE_SECURITY_V1_W DWORD
   Version         AS DWORD                           ' unsigned long
   ServerPrincName AS WSTRINGZ PTR                    ' unsigned short *
   AuthnLevel      AS DWORD                           ' unsigned long
   AuthnSvc        AS DWORD                           ' unsigned long
   AuthIdentity    AS SEC_WINNT_AUTH_IDENTITY_W PTR   '  SEC_WINNT_AUTH_IDENTITY_W *
   SecurityQos     AS RPC_SECURITY_QOS PTR            ' RPC_SECURITY_QOS *
END TYPE

'#ifdef _AUTH_IDENTITY_A_DEFINED

' // Size = 24 bytes
TYPE RPC_BINDING_HANDLE_SECURITY_V1_A DWORD
   Version         AS DWORD                           ' unsigned long
   ServerPrincName AS WSTRINGZ PTR                    ' unsigned char *
   AuthnLevel      AS DWORD                           ' unsigned long
   AuthnSvc        AS DWORD                           ' unsigned long
   AuthIdentity    AS SEC_WINNT_AUTH_IDENTITY_A PTR   ' SEC_WINNT_AUTH_IDENTITY_A
   SecurityQos     AS RPC_SECURITY_QOS PTR            ' RPC_SECURITY_QOS *
END TYPE

#IF %DEF(%UNICODE)
   MACRO RPC_BINDING_HANDLE_SECURITY_V1 = RPC_BINDING_HANDLE_SECURITY_V1_W
#ELSE
   MACRO RPC_BINDING_HANDLE_SECURITY_V1 = RPC_BINDING_HANDLE_SECURITY_V1_A
#ENDIF

'#endif // _AUTH_IDENTITY_A_DEFINED

' // Size = 16 bytes
TYPE RPC_BINDING_HANDLE_OPTIONS_V1 DWORD
   Version     AS DWORD   ' unsigned long
   Flags       AS DWORD   ' unsigned long
   ComTimeout  AS DWORD   ' unsigned long
   CallTimeout AS DWORD   ' unsigned long
END TYPE

'#ifdef _AUTH_IDENTITY_A_DEFINED

DECLARE FUNCTION RpcBindingCreateA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingCreateA" ( _
   BYREF Template AS RPC_BINDING_HANDLE_TEMPLATE_V1_A _ ' __in RPC_BINDING_HANDLE_TEMPLATE_V1_A * Template
 , BYREF Security AS RPC_BINDING_HANDLE_SECURITY_V1_A _ ' __in_opt RPC_BINDING_HANDLE_SECURITY_V1_A * Security
 , BYREF Options AS RPC_BINDING_HANDLE_OPTIONS_V1 _     ' __in_opt RPC_BINDING_HANDLE_OPTIONS_V1 * Options
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE * Binding
 ) AS LONG                                              ' RPC_STATUS

'#endif // _AUTH_IDENTITY_A_DEFINED

DECLARE FUNCTION RpcBindingCreateW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingCreateW" ( _
   BYREF Template AS RPC_BINDING_HANDLE_TEMPLATE_V1_W _ ' __in RPC_BINDING_HANDLE_TEMPLATE_V1_W * Template
 , BYREF Security AS RPC_BINDING_HANDLE_SECURITY_V1_W _ ' __in_opt RPC_BINDING_HANDLE_SECURITY_V1_W * Security
 , BYREF Options AS RPC_BINDING_HANDLE_OPTIONS_V1 _     ' __in_opt RPC_BINDING_HANDLE_OPTIONS_V1 * Options
 , BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE * Binding
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingCreate = RpcBindingCreateW
#ELSE
   MACRO RpcBindingCreate = RpcBindingCreateA
#ENDIF

DECLARE FUNCTION RpcBindingGetTrainingContextHandle IMPORT "RPCRT4.DLL" ALIAS "RpcBindingGetTrainingContextHandle" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ContextHandle AS DWORD _                       ' __out  void ** ContextHandle
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerInqBindingHandle IMPORT "RPCRT4.DLL" ALIAS "RpcServerInqBindingHandle" ( _
   BYREF Binding AS DWORD _                             ' __out RPC_BINDING_HANDLE * Binding
 ) AS LONG                                              ' RPC_STATUS

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)


'#if (NTDDI_VERSION >= NTDDI_WS03)
' RPC_HTTP_REDIRECTOR_STAGE enum
%RPCHTTP_RS_REDIRECT  = 1
%RPCHTTP_RS_ACCESS_1  = 2
%RPCHTTP_RS_SESSION   = 3
%RPCHTTP_RS_ACCESS_2  = 4
%RPCHTTP_RS_INTERFACE = 5
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_WS03)
'typedef RPC_STATUS
'(__RPC_USER * RPC_NEW_HTTP_PROXY_CHANNEL) (
'    __in RPC_HTTP_REDIRECTOR_STAGE RedirectorStage,
'    __in RPC_WSTR ServerName,
'    __in RPC_WSTR ServerPort,
'    __in_opt RPC_WSTR RemoteUser,
'    __in_opt RPC_WSTR AuthType,
'    __inout void __RPC_FAR * ResourceUuid,
'    __inout void __RPC_FAR * SessionId,
'    __in_opt void __RPC_FAR * Interface,
'    __in_opt void __RPC_FAR * Reserved,
'    __in unsigned long Flags,
'    __deref_opt_out RPC_WSTR __RPC_FAR * NewServerName,
'    __deref_opt_out RPC_WSTR __RPC_FAR * NewServerPort
'    );

'#else

'typedef RPC_STATUS
'(__RPC_USER * RPC_NEW_HTTP_PROXY_CHANNEL) (
'    __in unsigned short __RPC_FAR *ServerName,
'    __in unsigned short __RPC_FAR *ServerPort,
'    __in unsigned char __RPC_FAR *RemoteUser,
'    __out unsigned short __RPC_FAR **NewServerName
'    );
'#endif // (NTDDI_VERSION >= NTDDI_WS03)

'typedef void
'(__RPC_USER * RPC_HTTP_PROXY_FREE_STRING) (
'    __in RPC_WSTR String
'    );
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

%RPC_C_AUTHZ_NONE    = 0
%RPC_C_AUTHZ_NAME    = 1
%RPC_C_AUTHZ_DCE     = 2
%RPC_C_AUTHZ_DEFAULT = &Hffffffff???

DECLARE FUNCTION RpcImpersonateClient IMPORT "RPCRT4.DLL" ALIAS "RpcImpersonateClient" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcRevertToSelfEx IMPORT "RPCRT4.DLL" ALIAS "RpcRevertToSelfEx" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcRevertToSelf IMPORT "RPCRT4.DLL" ALIAS "RpcRevertToSelf" ( _
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingInqAuthClientA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthClientA" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in_opt RPC_BINDING_HANDLE ClientBinding
 , BYREF Privs AS DWORD _                               ' __out RPC_AUTHZ_HANDLE *Privs
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_CSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long *AuthnSvc
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long *AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingInqAuthClientW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthClientW" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in_opt RPC_BINDING_HANDLE ClientBinding
 , BYREF Privs AS DWORD _                               ' __out RPC_AUTHZ_HANDLE *Privs
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_WSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long *AuthnSvc
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long *AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingInqAuthClient = RpcBindingInqAuthClientW
#ELSE
   MACRO RpcBindingInqAuthClient = RpcBindingInqAuthClientA
#ENDIF

DECLARE FUNCTION RpcBindingInqAuthClientExA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthClientExA" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in_opt RPC_BINDING_HANDLE ClientBinding
 , BYREF Privs AS DWORD _                               ' __out RPC_AUTHZ_HANDLE   *Privs
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_CSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long  *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long  *AuthnSvc
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long  *AuthzSvc
 , BYVAL Flags AS DWORD _                               ' __in      unsigned long   Flags
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingInqAuthClientExW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthClientExW" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in_opt RPC_BINDING_HANDLE ClientBinding
 , BYREF Privs AS DWORD _                               ' __out RPC_AUTHZ_HANDLE   *Privs
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_WSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long  *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long  *AuthnSvc
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long  *AuthzSvc
 , BYVAL Flags AS DWORD _                               ' __in      unsigned long   Flags
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingInqAuthClientEx = RpcBindingInqAuthClientExW
#ELSE
   MACRO RpcBindingInqAuthClientEx = RpcBindingInqAuthClientExA
#ENDIF

DECLARE FUNCTION RpcBindingInqAuthInfoA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthInfoA" ( _
   BYVAL Binding AS DWORD _                             ' __in_opt RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_CSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long  *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long  *AuthnSvc
 , BYREF AuthIdentity AS DWORD _                        ' __out_opt RPC_AUTH_IDENTITY_HANDLE *AuthIdentity
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long  *AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingInqAuthInfoW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthInfoW" ( _
   BYVAL Binding AS DWORD _                             ' __in_opt RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_WSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long  *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long  *AuthnSvc
 , BYREF AuthIdentity AS DWORD _                        ' __out_opt RPC_AUTH_IDENTITY_HANDLE *AuthIdentity
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long  *AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingInqAuthInfo = RpcBindingInqAuthInfoW
#ELSE
   MACRO RpcBindingInqAuthInfo = RpcBindingInqAuthInfoA
#ENDIF

DECLARE FUNCTION RpcBindingSetAuthInfoA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetAuthInfoA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS ASCIIZ _                    ' __in RPC_CSTR ServerPrincName
 , BYVAL AuthnLevel AS DWORD _                          ' __in unsigned long AuthnLevel
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL AuthIdentity AS DWORD _                        ' __in_opt RPC_AUTH_IDENTITY_HANDLE AuthIdentity
 , BYVAL AuthzSvc AS DWORD _                            ' __in unsigned long AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingSetAuthInfoW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetAuthInfoW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS WSTRINGZ _                  ' __in RPC_WSTR ServerPrincName
 , BYVAL AuthnLevel AS DWORD _                          ' __in unsigned long AuthnLevel
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL AuthIdentity AS DWORD _                        ' __in_opt RPC_AUTH_IDENTITY_HANDLE AuthIdentity
 , BYVAL AuthzSvc AS DWORD _                            ' __in unsigned long AuthzSvc
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingSetAuthInfo = RpcBindingSetAuthInfoW
#ELSE
   MACRO RpcBindingSetAuthInfo = RpcBindingSetAuthInfoA
#ENDIF

DECLARE FUNCTION RpcBindingSetAuthInfoExA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetAuthInfoExA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS ASCIIZ _                    ' __in RPC_CSTR ServerPrincName
 , BYVAL AuthnLevel AS DWORD _                          ' __in unsigned long AuthnLevel
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL AuthIdentity AS DWORD _                        ' __in_opt RPC_AUTH_IDENTITY_HANDLE AuthIdentity
 , BYVAL AuthzSvc AS DWORD _                            ' __in unsigned long AuthzSvc
 , BYREF SecurityQos AS RPC_SECURITY_QOS _              ' __in_opt RPC_SECURITY_QOS *SecurityQos
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingSetAuthInfoExW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingSetAuthInfoExW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS WSTRINGZ _                  ' __in RPC_WSTR ServerPrincName
 , BYVAL AuthnLevel AS DWORD _                          ' __in unsigned long AuthnLevel
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL AuthIdentity AS DWORD _                        ' __in_opt RPC_AUTH_IDENTITY_HANDLE AuthIdentity
 , BYVAL AuthzSvc AS DWORD _                            ' __in unsigned long AuthzSvc
 , BYREF SecurityQos AS RPC_SECURITY_QOS _              ' __in_opt RPC_SECURITY_QOS *SecurityQos
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingSetAuthInfoEx = RpcBindingSetAuthInfoExW
#ELSE
   MACRO RpcBindingSetAuthInfoEx = RpcBindingSetAuthInfoExA
#ENDIF

DECLARE FUNCTION RpcBindingInqAuthInfoExA IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthInfoExA" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_CSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long *AuthnSvc
 , BYREF AuthIdentity AS DWORD _                        ' __out_opt RPC_AUTH_IDENTITY_HANDLE *AuthIdentity
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long *AuthzSvc
 , BYVAL RpcQosVersion AS DWORD _                       ' __in unsigned long RpcQosVersion
 , BYREF SecurityQos AS RPC_SECURITY_QOS _              ' __in_opt RPC_SECURITY_QOS *SecurityQos
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcBindingInqAuthInfoExW IMPORT "RPCRT4.DLL" ALIAS "RpcBindingInqAuthInfoExW" ( _
   BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ServerPrincName AS DWORD _                     ' __opt_out RPC_WSTR *ServerPrincName
 , BYREF AuthnLevel AS DWORD _                          ' __out_opt unsigned long *AuthnLevel
 , BYREF AuthnSvc AS DWORD _                            ' __out_opt unsigned long *AuthnSvc
 , BYREF AuthIdentity AS DWORD _                        ' __out_opt RPC_AUTH_IDENTITY_HANDLE *AuthIdentity
 , BYREF AuthzSvc AS DWORD _                            ' __out_opt unsigned long *AuthzSvc
 , BYVAL RpcQosVersion AS DWORD _                       ' __in unsigned long RpcQosVersion
 , BYREF SecurityQos AS RPC_SECURITY_QOS _              ' __in_opt RPC_SECURITY_QOS *SecurityQos
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcBindingInqAuthInfoEx = RpcBindingInqAuthInfoExW
#ELSE
   MACRO RpcBindingInqAuthInfoEx = RpcBindingInqAuthInfoExA
#ENDIF

'typedef void
'(__RPC_USER * RPC_AUTH_KEY_RETRIEVAL_FN) (
'    __in void __RPC_FAR * Arg,
'    __in RPC_WSTR ServerPrincName,
'    __in unsigned long KeyVer,
'    __deref_out void __RPC_FAR * __RPC_FAR * Key,
'    __out RPC_STATUS __RPC_FAR * Status
'    );

'DECLARE FUNCTION RpcServerCompleteSecurityCallback IMPORT "RPCRT4.DLL" ALIAS "RpcServerCompleteSecurityCallback" ( _
'   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle
' , BYVAL Status AS DWORD _                              ' __in RPC_STATUS Status
' ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerRegisterAuthInfoA IMPORT "RPCRT4.DLL" ALIAS "RpcServerRegisterAuthInfoA" ( _
   BYREF ServerPrincName AS ASCIIZ _                    ' __in RPC_CSTR ServerPrincName
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL GetKeyFn AS DWORD _                            ' __in_opt RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn
 , BYVAL Arg AS DWORD _                                 ' __in_opt void *Arg
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerRegisterAuthInfoW IMPORT "RPCRT4.DLL" ALIAS "RpcServerRegisterAuthInfoW" ( _
   BYREF ServerPrincName AS WSTRINGZ _                  ' __in RPC_WSTR ServerPrincName
 , BYVAL AuthnSvc AS DWORD _                            ' __in unsigned long AuthnSvc
 , BYVAL GetKeyFn AS DWORD _                            ' __in_opt RPC_AUTH_KEY_RETRIEVAL_FN GetKeyFn
 , BYVAL Arg AS DWORD _                                 ' __in_opt void *Arg
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcServerRegisterAuthInfo = RpcServerRegisterAuthInfoW
#ELSE
   MACRO RpcServerRegisterAuthInfo = RpcServerRegisterAuthInfoA
#ENDIF

'#if !defined(_M_IA64)
'typedef struct {
'    unsigned char * UserName;
'    unsigned char * ComputerName;
'    unsigned short Privilege;
'    unsigned long AuthFlags;
'} RPC_CLIENT_INFORMATION1, * PRPC_CLIENT_INFORMATION1;
'#endif

DECLARE FUNCTION RpcBindingServerFromClient IMPORT "RPCRT4.DLL" ALIAS "RpcBindingServerFromClient" ( _
   BYVAL ClientBinding AS DWORD _                       ' __in RPC_BINDING_HANDLE ClientBinding
 , BYREF ServerBinding AS DWORD _                       ' __out RPC_BINDING_HANDLE * ServerBinding
 ) AS LONG                                              ' RPC_STATUS

DECLARE SUB RpcRaiseException IMPORT "RPCRT4.DLL" ALIAS "RpcRaiseException" ( _
   BYVAL exception AS DWORD _                           ' __in RPC_STATUS exception
 )                                                      ' void

DECLARE FUNCTION RpcTestCancel IMPORT "RPCRT4.DLL" ALIAS "RpcTestCancel" ( _
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcServerTestCancel IMPORT "RPCRT4.DLL" ALIAS "RpcServerTestCancel" ( _
   BYVAL BindingHandle AS DWORD _                       ' __in RPC_BINDING_HANDLE BindingHandle OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcCancelThread IMPORT "RPCRT4.DLL" ALIAS "RpcCancelThread" ( _
   BYVAL Thread AS DWORD _                              ' __in void * Thread
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcCancelThreadEx IMPORT "RPCRT4.DLL" ALIAS "RpcCancelThreadEx" ( _
   BYVAL Thread AS DWORD _                              ' __in void * Thread
 , BYVAL Timeout AS LONG _                              ' __in long Timeout
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION UuidCreate IMPORT "RPCRT4.DLL" ALIAS "UuidCreate" ( _
   BYREF Uuid AS GUID _                                 ' __out UUID * Uuid
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION UuidCreateSequential IMPORT "RPCRT4.DLL" ALIAS "UuidCreateSequential" ( _
   BYREF Uuid AS GUID _                                 ' __out UUID * Uuid
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION UuidToStringA IMPORT "RPCRT4.DLL" ALIAS "UuidToStringA" ( _
   BYREF Uuid AS GUID _                                 ' __in UUID *Uuid
 , BYREF StringUuid AS DWORD _                          ' __out RPC_CSTR *StringUuid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION UuidToStringW IMPORT "RPCRT4.DLL" ALIAS "UuidToStringW" ( _
   BYREF Uuid AS GUID _                                 ' __in UUID *Uuid
 , BYREF StringUuid AS DWORD _                          ' __out RPC_WSTR *StringUuid
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO UuidToString = UuidToStringW
#ELSE
   MACRO UuidToString = UuidToStringA
#ENDIF

'/* client/server */

DECLARE FUNCTION UuidFromStringA IMPORT "RPCRT4.DLL" ALIAS "UuidFromStringA" ( _
   BYREF StringUuid AS ASCIIZ _                         ' __in RPC_CSTR StringUuid
 , BYREF Uuid AS GUID _                                 ' __out UUID *Uuid
 ) AS LONG                                              ' RPC_STATUS

'/* client/server */

DECLARE FUNCTION UuidFromStringW IMPORT "RPCRT4.DLL" ALIAS "UuidFromStringW" ( _
   BYREF StringUuid AS WSTRINGZ _                       ' __in RPC_WSTR StringUuid
 , BYREF Uuid AS GUID _                                 ' __out UUID *Uuid
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO UuidFromString = UuidFromStringW
#ELSE
   MACRO UuidFromString = UuidFromStringA
#ENDIF

DECLARE FUNCTION UuidCompare IMPORT "RPCRT4.DLL" ALIAS "UuidCompare" ( _
   BYREF Uuid1 AS GUID _                                ' __in UUID * Uuid1
 , BYREF Uuid2 AS GUID _                                ' __in UUID * Uuid2
 , BYREF Status AS DWORD _                              ' __out RPC_STATUS * Status
 ) AS LONG                                              ' signed int

DECLARE FUNCTION UuidCreateNil IMPORT "RPCRT4.DLL" ALIAS "UuidCreateNil" ( _
   BYREF NilUuid AS GUID _                              ' __out UUID * NilUuid
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION UuidEqual IMPORT "RPCRT4.DLL" ALIAS "UuidEqual" ( _
   BYREF Uuid1 AS GUID _                                ' __in UUID * Uuid1
 , BYREF Uuid2 AS GUID _                                ' __in UUID * Uuid2
 , BYREF Status AS DWORD _                              ' __out RPC_STATUS * Status
 ) AS LONG                                              ' int

DECLARE FUNCTION UuidHash IMPORT "RPCRT4.DLL" ALIAS "UuidHash" ( _
   BYREF Uuid AS GUID _                                 ' __in UUID * Uuid
 , BYREF Status AS DWORD _                              ' __out RPC_STATUS * Status
 ) AS WORD                                              ' unsigned short

DECLARE FUNCTION UuidIsNil IMPORT "RPCRT4.DLL" ALIAS "UuidIsNil" ( _
   BYREF Uuid1 AS GUID _                                ' __in UUID * Uuid1
 , BYREF Status AS DWORD _                              ' __out RPC_STATUS * Status
 ) AS LONG                                              ' int

DECLARE FUNCTION RpcEpRegisterNoReplaceA IMPORT "RPCRT4.DLL" ALIAS "RpcEpRegisterNoReplaceA" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __in RPC_BINDING_VECTOR *BindingVector
 , BYREF UuidVector AS UUID_VECTOR _                    ' __in_opt UUID_VECTOR *UuidVector
 , BYREF Annotation AS ASCIIZ _                         ' __in_opt RPC_CSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcEpRegisterNoReplaceW IMPORT "RPCRT4.DLL" ALIAS "RpcEpRegisterNoReplaceW" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __in RPC_BINDING_VECTOR *BindingVector
 , BYREF UuidVector AS UUID_VECTOR _                    ' __in_opt UUID_VECTOR *UuidVector
 , BYREF Annotation AS WSTRINGZ _                       ' __in_opt RPC_WSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcEpRegisterNoReplace = RpcEpRegisterNoReplaceW
#ELSE
   MACRO RpcEpRegisterNoReplace = RpcEpRegisterNoReplaceA
#ENDIF

DECLARE FUNCTION RpcEpRegisterA IMPORT "RPCRT4.DLL" ALIAS "RpcEpRegisterA" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __in RPC_BINDING_VECTOR *BindingVector
 , BYREF UuidVector AS UUID_VECTOR _                    ' __in_opt UUID_VECTOR *UuidVector
 , BYREF Annotation AS ASCIIZ _                         ' __in_opt RPC_CSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcEpRegisterW IMPORT "RPCRT4.DLL" ALIAS "RpcEpRegisterW" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __in RPC_BINDING_VECTOR *BindingVector
 , BYREF UuidVector AS UUID_VECTOR _                    ' __in_opt UUID_VECTOR *UuidVector
 , BYREF Annotation AS WSTRINGZ _                       ' __in_opt RPC_WSTR Annotation
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcEpRegister = RpcEpRegisterW
#ELSE
   MACRO RpcEpRegister = RpcEpRegisterA
#ENDIF

DECLARE FUNCTION RpcEpUnregister IMPORT "RPCRT4.DLL" ALIAS "RpcEpUnregister" ( _
   BYVAL IfSpec AS DWORD _                              ' __in RPC_IF_HANDLE IfSpec
 , BYREF BindingVector AS RPC_BINDING_VECTOR _          ' __in RPC_BINDING_VECTOR *BindingVector
 , BYREF UuidVector AS UUID_VECTOR _                    ' __in UUID_VECTOR *UuidVector
 ) AS LONG                                              ' RPC_STATUS

%DCE_C_ERROR_STRING_LEN = 256

DECLARE FUNCTION DceErrorInqTextA IMPORT "RPCRT4.DLL" ALIAS "DceErrorInqTextA" ( _
   BYVAL RpcStatus AS DWORD _                           ' __in RPC_STATUS RpcStatus
 , BYREF ErrorText AS ASCIIZ _                          ' __out_ecount(DCE_C_ERROR_STRING_LEN) RPC_CSTR ErrorText
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION DceErrorInqTextW IMPORT "RPCRT4.DLL" ALIAS "DceErrorInqTextW" ( _
   BYVAL RpcStatus AS DWORD _                           ' __in RPC_STATUS RpcStatus
 , BYREF ErrorText AS WSTRINGZ _                        ' __out_ecount(DCE_C_ERROR_STRING_LEN) RPC_WSTR ErrorText
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO DceErrorInqText = DceErrorInqTextW
#ELSE
   MACRO DceErrorInqText = DceErrorInqTextA
#ENDIF

'typedef I_RPC_HANDLE * RPC_EP_INQ_HANDLE;

%RPC_C_EP_ALL_ELTS       = 0
%RPC_C_EP_MATCH_BY_IF    = 1
%RPC_C_EP_MATCH_BY_OBJ   = 2
%RPC_C_EP_MATCH_BY_BOTH  = 3

%RPC_C_VERS_ALL          = 1
%RPC_C_VERS_COMPATIBLE   = 2
%RPC_C_VERS_EXACT        = 3
%RPC_C_VERS_MAJOR_ONLY   = 4
%RPC_C_VERS_UPTO         = 5

DECLARE FUNCTION RpcMgmtEpEltInqBegin IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEpEltInqBegin" ( _
   BYVAL EpBinding AS DWORD _                           ' __in RPC_BINDING_HANDLE EpBinding OPTIONAL
 , BYVAL InquiryType AS DWORD _                         ' __in unsigned long InquiryType
 , BYREF IfId AS RPC_IF_ID _                            ' __in RPC_IF_ID * IfId OPTIONAL
 , BYVAL VersOption AS DWORD _                          ' __in unsigned long VersOption OPTIONAL
 , BYREF ObjectUuid AS GUID _                           ' __in UUID * ObjectUuid OPTIONAL
 , BYREF InquiryContext AS DWORD _                      ' __out RPC_EP_INQ_HANDLE * InquiryContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtEpEltInqDone IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEpEltInqDone" ( _
  BYREF InquiryContext AS DWORD _                       ' __inout RPC_EP_INQ_HANDLE * InquiryContext
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtEpEltInqNextA IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEpEltInqNextA" ( _
   BYVAL InquiryContext AS DWORD _                      ' __in RPC_EP_INQ_HANDLE InquiryContext
 , BYREF IfId AS DWORD _                                ' __out RPC_IF_ID *IfId
 , BYREF Binding AS DWORD _                             ' __out_opt RPC_BINDING_HANDLE *Binding
 , BYREF ObjectUuid AS GUID _                           ' __out_opt UUID *ObjectUuid
 , BYREF Annotation AS DWORD _                          ' __opt_out RPC_CSTR *Annotation
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION RpcMgmtEpEltInqNextW IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEpEltInqNextW" ( _
   BYVAL InquiryContext AS DWORD _                      ' __in RPC_EP_INQ_HANDLE InquiryContext
 , BYREF IfId AS DWORD _                                ' __out RPC_IF_ID *IfId
 , BYREF Binding AS DWORD _                             ' __out_opt RPC_BINDING_HANDLE *Binding
 , BYREF ObjectUuid AS GUID _                           ' __out_opt UUID *ObjectUuid
 , BYREF Annotation AS DWORD _                          ' __opt_out RPC_WSTR *Annotation
 ) AS LONG                                              ' RPC_STATUS

#IF %DEF(%UNICODE)
   MACRO RpcMgmtEpEltInqNext = RpcMgmtEpEltInqNextW
#ELSE
   MACRO RpcMgmtEpEltInqNext = RpcMgmtEpEltInqNextA
#ENDIF

DECLARE FUNCTION RpcMgmtEpUnregister IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtEpUnregister" ( _
   BYVAL EpBinding AS DWORD _                           ' __in RPC_BINDING_HANDLE EpBinding OPTIONAL
 , BYREF IfId AS RPC_IF_ID _                            ' __in RPC_IF_ID * IfId
 , BYVAL Binding AS DWORD _                             ' __in RPC_BINDING_HANDLE Binding
 , BYREF ObjectUuid AS GUID _                           ' __in UUID * ObjectUuid OPTIONAL
 ) AS LONG                                              ' RPC_STATUS

'typedef int
'(__RPC_API * RPC_MGMT_AUTHORIZATION_FN) (
'    IN RPC_BINDING_HANDLE ClientBinding,
'    IN unsigned long RequestedMgmtOperation,
'    OUT RPC_STATUS __RPC_FAR * Status
'    );

%RPC_C_MGMT_INQ_IF_IDS         = 0
%RPC_C_MGMT_INQ_PRINC_NAME     = 1
%RPC_C_MGMT_INQ_STATS          = 2
%RPC_C_MGMT_IS_SERVER_LISTEN   = 3
%RPC_C_MGMT_STOP_SERVER_LISTEN = 4

DECLARE FUNCTION RpcMgmtSetAuthorizationFn IMPORT "RPCRT4.DLL" ALIAS "RpcMgmtSetAuthorizationFn" ( _
   BYVAL AuthorizationFn AS DWORD _                     ' __in RPC_MGMT_AUTHORIZATION_FN AuthorizationFn
 ) AS LONG                                              ' RPC_STATUS

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION RpcExceptionFilter IMPORT "RPCRT4.DLL" ALIAS "RpcExceptionFilter" ( _
   BYVAL ExceptionCode AS DWORD _                       ' __in unsigned long ExceptionCode
 ) AS LONG                                              ' int
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%RPC_C_PARM_MAX_PACKET_LENGTH   = 1
%RPC_C_PARM_BUFFER_LENGTH       = 2

%RPC_IF_AUTOLISTEN                   = &H0001
%RPC_IF_OLE                          = &H0002
%RPC_IF_ALLOW_UNKNOWN_AUTHORITY      = &H0004
%RPC_IF_ALLOW_SECURE_ONLY            = &H0008
%RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH = &H0010
%RPC_IF_ALLOW_LOCAL_ONLY             = &H0020
%RPC_IF_SEC_NO_CACHE                 = &H0040
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_IF_SEC_CACHE_PER_PROC           = &H0080
%RPC_IF_ASYNC_CALLBACK               = &H0100
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%RPC_FW_IF_FLAG_DCOM                 = &H0001
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#INCLUDE ONCE "rpcdcep.inc"
