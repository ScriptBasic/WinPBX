' ########################################################################################
' Microsoft Windows
' File: NSSCore.inc
' Contents: Microsoft Windows Media
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NSSCORE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "wmscontext.inc"

$IID_IWMSClassObject = GUID$("{F54E23A4-1B1A-11D1-9E90-006097D2D7CF}")

' ########################################################################################
' Interface name = IWMSClassObject
' IID = {F54E23A4-1B1A-11D1-9E90-006097D2D7CF}
' Provides methods to allocate data structures commonly used by plug-ins.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSClassObject_INTERFACE_DEFINED)
    %IWMSClassObject_INTERFACE_DEFINED = 1

INTERFACE IWMSClassObject $IID_IWMSClassObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocIWMSPacket ( _                           ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocIWMSPacketList ( _                       ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocIWMSContext ( _                          ' VTable offset = 24
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYVAL ContextType AS LONG _                        ' __in WMS_CONTEXT_TYPE ContextType
   , BYVAL pRelatedContext AS IUnknown _                ' __in IUnknown *pRelatedContext
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocIWMSCommandContext ( _                   ' VTable offset = 28
     BYREF riid AS GUID _                               ' __in REFIID *riid
   , BYVAL pRelatedContext AS IUnknown _                ' __in IUnknown *pRelatedContext
   , BYREF ppunk AS IUnknown _                          ' __out void **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSClassObject_INTERFACE_DEFINED__ */
