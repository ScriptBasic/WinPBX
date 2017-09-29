' ########################################################################################
' Microsoft Windows
' File: Rpc.inc
' Contents: Master include file for RPC applications
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#if !defined( RPC_NO_WINDOWS_H ) && !defined( MAC ) && !defined( _MAC ) && !defined(_KRPCENV_)
'/*
' * Pull in WINDOWS.H if necessary
' */
'#ifndef _INC_WINDOWS
'#include <windows.h>
'#endif /* _INC_WINDOWS */
'#endif // RPC_NO_WINDOWS_H

#INCLUDE THIS ONCE
%RPC_INC = 1

'#if _MSC_VER > 1000
'#pragma once
'#endif

'#ifdef __cplusplus
'extern "C" {
'#endif

'//-------------------------------------------------------------
'// platform specific defines
'//-------------------------------------------------------------

'//-------------------  MAC ---------------------------
'#if defined( MAC ) || defined( _MAC )

'#define __RPC_MAC__
'// Set the packing level for RPC structures.

'#include <pshpack2.h>

'//-------------------  WIN32 ---------------------------
'#else // win32 platforms

#INCLUDE ONCE "basetsd.inc"

'#if defined(_M_IA64) || defined(_M_AMD64)
'#define __RPC_WIN64__
'#else
'#define __RPC_WIN32__
'#endif

'#endif

'#if defined(__RPC_WIN64__)
'#include <pshpack8.h>
'#endif

'#ifndef __MIDL_USER_DEFINED
'#define midl_user_allocate MIDL_user_allocate
'#define midl_user_free     MIDL_user_free
'#define __MIDL_USER_DEFINED
'#endif

'typedef void * I_RPC_HANDLE;
'typedef long RPC_STATUS;

'#if defined(__RPC_WIN32__) || defined(__RPC_WIN64__)
'#define RPC_UNICODE_SUPPORTED
'#endif

'#if !defined(__RPC_MAC__) && ( (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED) )
'#	define __RPC_API  __stdcall
'#	define __RPC_USER __stdcall
'#	define __RPC_STUB __stdcall
'#	define  RPC_ENTRY __stdcall
'#else // Not Win32/Win64
'#	define __RPC_API
'#	define __RPC_USER
'#	define __RPC_STUB
'#	define RPC_ENTRY
'#endif

'#define __RPC_FAR

'// Some RPC platforms don't define DECLSPEC_IMPORT
'#if !defined(DECLSPEC_IMPORT)
'#if (defined(_M_MRX000) || defined(_M_IX86) || defined(_M_IA64) || defined(_M_AMD64)) && !defined(MIDL_PASS)
'#define DECLSPEC_IMPORT __declspec(dllimport)
'#else
'#define DECLSPEC_IMPORT
'#endif
'#endif

'#if !defined(_RPCRT4_)
'#define RPCRTAPI DECLSPEC_IMPORT
'#else
'#define RPCRTAPI
'#endif

'#if !defined(_RPCNS4_)
'#define RPCNSAPI DECLSPEC_IMPORT
'#else
'#define RPCNSAPI
'#endif

'#ifdef __RPC_MAC__

'#include <setjmp.h>

'#define RPCXCWORD (sizeof(jmp_buf)/sizeof(int))

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning( disable: 4005 )
'#include <rpcdce.h>
'#include <rpcnsi.h>
'#include <rpcerr.h>
'#include <rpcmac.h>
'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning( default :  4005 )
'#endif

'typedef void  (RPC_ENTRY *MACYIELDCALLBACK)(/*OSErr*/ short *) ;
'RPC_STATUS RPC_ENTRY
'RpcMacSetYieldInfo(
'	MACYIELDCALLBACK pfnCallback) ;

'#if !defined(UNALIGNED)
'#define UNALIGNED
'#endif

'#include <poppack.h>

'#else // __RPC_MAC__

#INCLUDE ONCE "rpcdce.inc"
#INCLUDE ONCE "rpcnsi.inc"
'#include <rpcnterr.h>
'#include <excpt.h>
'#include <winerror.h>

'#define RpcTryExcept \
'    __try \
'        {

'// trystmts

'#define RpcExcept(expr) \
'        } \
'    __except (expr) \
'        {

'// exceptstmts

'#define RpcEndExcept \
'        }

'#define RpcTryFinally \
'    __try \
'        {

'// trystmts

'#define RpcFinally \
'        } \
'    __finally \
'        {

'// finallystmts

'#define RpcEndFinally \
'        }

'#define RpcExceptionCode() GetExceptionCode()
'#define RpcAbnormalTermination() AbnormalTermination()

''#endif // __RPC_MAC__

'// rpcasync.h is now RPC_NO_WINDOWS_H aware, but we can't start including it always
'// as it does still require windef.h which could clash with another header.
'//
'// Parsing of the below test:
'// don't include rpcasync.h if either RPC_NO_WINDOWS_H or __RPC_MAC__ is set, except that setting
'// RPC_NEED_RPCASYNC_H overrides RPC_NO_WINDOWS_H.
'// In any case, if _KRPCENV_ is set, include rpcasync.h regardless of any of the above being set.
'#if ((!defined( RPC_NO_WINDOWS_H ) || defined(RPC_NEED_RPCASYNC_H)) && !defined(__RPC_MAC__)) || defined(_KRPCENV_)

#INCLUDE ONCE "rpcasync.inc"

'#endif // RPC_NO_WINDOWS_H et al.

'#if defined(__RPC_WIN64__)
'#include <poppack.h>
'#endif

'#ifdef __cplusplus
'}
'#endif

