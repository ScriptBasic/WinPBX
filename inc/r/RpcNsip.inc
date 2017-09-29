' ########################################################################################
' Microsoft Windows
' File: RpcNsip.inc
' Contents: Types and function definitions to use the to implement the autohandle features of the runtime
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%RPCNSIP_INC = 1

#INCLUDE ONCE "rpcdce.inc"

' // Size = 12 bytes
TYPE RPC_IMPORT_CONTEXT_P DWORD
   LookupContext  AS DWORD                    ' RPC_NS_HANDLE
   ProposedHandle AS DWORD                    ' RPC_NS_HANDLE
   Bindings       AS RPC_BINDING_VECTOR PTR   ' RPC_BINDING_VECTOR *
END TYPE


'/* Stub Auto Binding routines. */

DECLARE FUNCTION I_RpcNsGetBuffer IMPORT "RPCNS4.DLL" ALIAS "I_RpcNsGetBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in PRPC_MESSAGE Message
 ) AS LONG                                              ' RPC_STATUS

DECLARE FUNCTION I_RpcNsSendReceive IMPORT "RPCNS4.DLL" ALIAS "I_RpcNsSendReceive" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in PRPC_MESSAGE Message
 , BYREF Handle AS DWORD _                              ' __out RPC_BINDING_HANDLE * Handle
 ) AS LONG                                              ' RPC_STATUS

DECLARE SUB I_RpcNsRaiseException IMPORT "RPCNS4.DLL" ALIAS "I_RpcNsRaiseException" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in PRPC_MESSAGE Message
 , BYVAL Status AS DWORD _                              ' __in RPC_STATUS Status
 )                                                      ' void

DECLARE FUNCTION I_RpcReBindBuffer IMPORT "RPCNS4.DLL" ALIAS "I_RpcReBindBuffer" ( _
   BYREF Message AS RPC_MESSAGE _                       ' __in PRPC_MESSAGE Message
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE FUNCTION I_NsServerBindSearch IMPORT "RPCNS4.DLL" ALIAS "I_NsServerBindSearch" ( _
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE FUNCTION I_NsClientBindSearch IMPORT "RPCNS4.DLL" ALIAS "I_NsClientBindSearch" ( _
 ) AS LONG                                              ' RPC_STATUS

' Not exported in Windows XP
DECLARE SUB I_NsClientBindDone IMPORT "RPCNS4.DLL" ALIAS "I_NsClientBindDone" ()   ' void
