' ########################################################################################
' Microsoft Windows
' File: PortableDeviceConnectApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PORTABLEDEVICECONNECTAPI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "PortableDeviceConnectImports.inc"

$LIBID_PortableDeviceConnectApiLib = GUID$("{8fe73967-aae2-4d77-9921-0c4962631056}")
$CLSID_EnumBthMtpConnectors = GUID$("{a1570149-e645-4f43-8b0d-409b061db2fc}")

'// Property set by the MTP Bluetooth Enumerator indicate whether the device is connected
'// DEVPKEY_MTPBTH_IsConnected, DEVPROP_TYPE_BOOLEAN
'//
'// {ea1237fa-589d-4472-84e4-0abe36fd62ef}.2
MACRO DEVPKEY_MTPBTH_IsConnected = GUID$("{ea1237fa-589d-4472-84e4-0abe36fd62ef}") & MKDWD$(2)

' ########################################################################################
' Interface name = IEnumPortableDeviceConnectors
' IID = bfdef549-9247-454f-bd82-06fe80853faa
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPortableDeviceConnectors_INTERFACE_DEFINED)
    %IEnumPortableDeviceConnectors_INTERFACE_DEFINED = 1

$IID_IEnumPortableDeviceConnectors = GUID$("{bfdef549-9247-454f-bd82-06fe80853faa}")

INTERFACE IEnumPortableDeviceConnectors $IID_IEnumPortableDeviceConnectors

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRequested AS DWORD _                        ' __in UINT32 cRequested
   , BYREF pConnectors AS IPortableDeviceConnector _    ' __out IPortableDeviceConnector **pConnectors
   , BYREF pcFetched AS DWORD _                         ' __inout UINT32 *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cConnectors AS DWORD _                       ' __in UINT32 cConnectors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumPortableDeviceConnectors _    ' __out IEnumPortableDeviceConnectors **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF  ' /* __IEnumPortableDeviceConnectors_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPortableDeviceConnector
' IID = 625e2df8-6392-4cf0-9ad1-3cfa5f17775c
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPortableDeviceConnector_INTERFACE_DEFINED)
    %IPortableDeviceConnector_INTERFACE_DEFINED = 1

$IID_IPortableDeviceConnector = GUID$("{625e2df8-6392-4cf0-9ad1-3cfa5f17775c}")

INTERFACE IPortableDeviceConnector $IID_IPortableDeviceConnector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 12
     BYVAL pCallback AS IConnectionRequestCallback _    ' __in IConnectionRequestCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 16
     BYVAL pCallback AS IConnectionRequestCallback _    ' __in IConnectionRequestCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 20
     BYVAL pCallback AS IConnectionRequestCallback _    ' __in IConnectionRequestCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 24
     BYREF pPropertyKey AS DEVPROPKEY _                 ' __in const DEVPROPKEY *pPropertyKey
   , BYREF pPropertyType AS DWORD _                     ' __out DEVPROPTYPE *pPropertyType
   , BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   , BYREF pcbData AS DWORD _                           ' __out UINT32 *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 28
     BYREF pPropertyKey AS DEVPROPKEY _                 ' __in const DEVPROPKEY *pPropertyKey
   , BYREF PropertyType AS DWORD _                      ' __in DEVPROPTYPE PropertyType
   , BYVAL pData AS BYTE PTR _                          ' __in const BYTE *pData
   , BYVAL cbData AS DWORD _                            ' __in UINT32 cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPnPID ( _                                  ' VTable offset = 32
     BYREF ppwszPnPID AS DWORD _                        ' __out LPWSTR *ppwszPnPID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPortableDeviceConnector_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IConnectionRequestCallback
' IID = 272c9ae0-7161-4ae0-91bd-9f448ee9c427
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConnectionRequestCallback_INTERFACE_DEFINED)
    %IConnectionRequestCallback_INTERFACE_DEFINED = 1

$IID_IConnectionRequestCallback = GUID$("{272c9ae0-7161-4ae0-91bd-9f448ee9c427}")

INTERFACE IConnectionRequestCallback $IID_IConnectionRequestCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnComplete ( _                                ' VTable offset = 12
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConnectionRequestCallback_INTERFACE_DEFINED__ */
