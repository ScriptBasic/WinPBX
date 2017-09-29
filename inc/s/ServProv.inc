' ########################################################################################
' Microsoft Windows
' File: ServProv.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SERVPROV_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"

'//---------------------------------------------------------------------------=
'// IServiceProvider Interfaces.

' ########################################################################################
' IServiceProvider interface
' IID = 6D5140C1-7436-11CE-8034-00AA006009FA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IServiceProvider_INTERFACE_DEFINED)
    %IServiceProvider_INTERFACE_DEFINED = 1

$IID_IServiceProvider = GUID$("{6D5140C1-7436-11CE-8034-00AA006009FA}")

INTERFACE IServiceProvider $IID_IServiceProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryService ( _                              ' VTable offset = 12
     BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IServiceProvider_INTERFACE_DEFINED__ */
