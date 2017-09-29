' ########################################################################################
' Microsoft Windows
' File: ctxcall.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CTXCALL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "objidl.inc"

' // Size = 12 bytes
TYPE ComCallData DWORD
   dwDispid     AS DWORD   ' DWORD dwDispid
   dwReserved   AS DWORD   ' DWORD dwReserved
   pUserDefined AS DWORD   ' void *pUserDefined
END TYPE

' ########################################################################################
' IContextCallback interface
' IID = 000001DA-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextCallback_INTERFACE_DEFINED)
    %IContextCallback_INTERFACE_DEFINED = 1

$IID_IContextCallback = GUID$("{000001DA-0000-0000-C000-000000000046}")

INTERFACE IContextCallback $IID_IContextCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ContextCallback ( _                           ' VTable offset = 12
     BYVAL pfnCallback AS DWORD _                       ' __in PFNCONTEXTCALL pfnCallback
   , BYREF pParam AS ComCallData _                      ' __in ComCallData * pParam
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL iMethod AS LONG _                            ' __in int iMethod
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown * pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextCallback_INTERFACE_DEFINED__ */
