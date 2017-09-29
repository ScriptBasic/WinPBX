' ########################################################################################
' Microsoft Windows
' File: upnphost.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: UPnPHostLib
' Version: 1.0, Locale ID = 0
' Description: UPnP 1.0 Type Library
' Path: C:\WINDOWS\system32\upnpcont.exe
' Library GUID: {204810B3-73B2-11D4-BF42-00B0D0118B56}
' ########################################################################################

#INCLUDE THIS ONCE
%UPNPHOST_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

$LIBID_UPnPHostLib            = GUID$("{204810B3-73B2-11D4-BF42-00B0D0118B56}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_UPnPRegistrar          = GUID$("{204810B9-73B2-11D4-BF42-00B0D0118B56}")
$CLSID_UPnPRemoteEndpointInfo = GUID$("{2E5E84E9-4049-4244-B728-2D24227157C7}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IUPnPDeviceControl       = GUID$("{204810BA-73B2-11D4-BF42-00B0D0118B56}")
$IID_IUPnPDeviceProvider      = GUID$("{204810B8-73B2-11D4-BF42-00B0D0118B56}")
$IID_IUPnPEventSink           = GUID$("{204810B4-73B2-11D4-BF42-00B0D0118B56}")
$IID_IUPnPEventSource         = GUID$("{204810B5-73B2-11D4-BF42-00B0D0118B56}")
$IID_IUPnPRegistrar           = GUID$("{204810B6-73B2-11D4-BF42-00B0D0118B56}")
$IID_IUPnPRemoteEndpointInfo  = GUID$("{C92EB863-0269-4AFF-9C72-75321BBA2952}")
$IID_IUPnPReregistrar         = GUID$("{204810B7-73B2-11D4-BF42-00B0D0118B56}")

%UPNP_E_REQUIRED_ELEMENT_ERROR        = &HFFFFA020&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA020)
%UPNP_E_DUPLICATE_NOT_ALLOWED         = &HFFFFA021&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA021)
%UPNP_E_DUPLICATE_SERVICE_ID          = &HFFFFA022&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA022)
%UPNP_E_INVALID_DESCRIPTION           = &HFFFFA023&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA023)
%UPNP_E_INVALID_SERVICE               = &HFFFFA024&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA024)
%UPNP_E_INVALID_ICON                  = &HFFFFA025&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA025)
%UPNP_E_INVALID_XML                   = &HFFFFA026&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA026)
%UPNP_E_INVALID_ROOT_NAMESPACE        = &HFFFFA027&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA027)
%UPNP_E_SUFFIX_TOO_LONG               = &HFFFFA028&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA028)
%UPNP_E_URLBASE_PRESENT               = &HFFFFA029&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA029)
%UPNP_E_VALUE_TOO_LONG                = &HFFFFA030&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA030)
%UPNP_E_DEVICE_RUNNING                = &HFFFFA031&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA031)
%UPNP_E_DEVICE_NOTREGISTERED          = &HFFFFA032&   ' MAKE_HRESULT(SEVERITY_ERROR FACILITY_ITF 0xA032)

' // Remote address value is a string
' #define REMOTE_ADDRESS_VALUE_NAME L"RemoteAddress"
$REMOTE_ADDRESS_VALUE_NAME = "RemoteAddress"
' // Address family value is a DWORD
' #define ADDRESS_FAMILY_VALUE_NAME L"AddressFamily"
$ADDRESS_FAMILY_VALUE_NAME = "AddressFamily"

' ########################################################################################
' Interface name = IUPnPEventSink
' IID = {204810B4-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPEventSink_INTERFACE_DEFINED)
    %IUPnPEventSink_INTERFACE_DEFINED = 1

INTERFACE IUPnPEventSink $IID_IUPnPEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnStateChanged ( _                            ' VTable offset = 12
     BYVAL cChanges AS DWORD _                          ' __in DWORD cChanges
   , BYREF rgdispidChanges AS LONG _                    ' __in DISPID rgdispidChanges[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChangedSafe ( _                        ' VTable offset = 16
     BYVAL varsadispidChanges AS VARIANT _              ' __in VARIANT varsadispidChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPEventSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPEventSource
' IID = {204810B5-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPEventSource_INTERFACE_DEFINED)
    %IUPnPEventSource_INTERFACE_DEFINED = 1

INTERFACE IUPnPEventSource $IID_IUPnPEventSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pesSubscriber AS IUPnPEventSink _            ' __in IUPnPEventSink *pesSubscriber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL pesSubscriber AS IUPnPEventSink _            ' __in IUPnPEventSink *pesSubscriber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPEventSource_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPRegistrar
' IID = {204810B6-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPRegistrar_INTERFACE_DEFINED)
    %IUPnPRegistrar_INTERFACE_DEFINED = 1

INTERFACE IUPnPRegistrar $IID_IUPnPRegistrar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterDevice ( _                            ' VTable offset = 12
     BYVAL bstrXMLDesc AS WSTRING _                     ' __in BSTR bstrXMLDesc
   , BYVAL bstrProgIDDeviceControlClass AS WSTRING _    ' __in BSTR bstrProgIDDeviceControlClass
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   , BYVAL bstrContainerId AS WSTRING _                 ' __in BSTR bstrContainerId
   , BYVAL bstrResourcePath AS WSTRING _                ' __in BSTR bstrResourcePath
   , BYVAL nLifeTime AS LONG _                          ' __in long nLifeTime
   , BYREF pbstrDeviceIdentifier AS WSTRING _           ' __retval_out BSTR *pbstrDeviceIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterRunningDevice ( _                     ' VTable offset = 16
     BYVAL bstrXMLDesc AS WSTRING _                     ' __in BSTR bstrXMLDesc
   , BYVAL punkDeviceControl AS IUnknown _              ' __in IUnknown *punkDeviceControl
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   , BYVAL bstrResourcePath AS WSTRING _                ' __in BSTR bstrResourcePath
   , BYVAL nLifeTime AS LONG _                          ' __in long nLifeTime
   , BYREF pbstrDeviceIdentifier AS WSTRING _           ' __retval_out BSTR *pbstrDeviceIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterDeviceProvider ( _                    ' VTable offset = 20
     BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   , BYVAL bstrProgIDProviderClass AS WSTRING _         ' __in BSTR bstrProgIDProviderClass
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   , BYVAL bstrContainerId AS WSTRING _                 ' __in BSTR bstrContainerId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUniqueDeviceName ( _                       ' VTable offset = 24
     BYVAL bstrDeviceIdentifier AS WSTRING _            ' __in BSTR bstrDeviceIdentifier
   , BYVAL bstrTemplateUDN AS WSTRING _                 ' __in BSTR bstrTemplateUDN
   , BYREF pbstrUDN AS WSTRING _                        ' __retval_out BSTR *pbstrUDN
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterDevice ( _                          ' VTable offset = 28
     BYVAL bstrDeviceIdentifier AS WSTRING _            ' __in BSTR bstrDeviceIdentifier
   , BYVAL fPermanent AS LONG _                         ' __in BOOL fPermanent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterDeviceProvider ( _                  ' VTable offset = 32
     BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPRegistrar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPReregistrar
' IID = {204810B7-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPReregistrar_INTERFACE_DEFINED)
    %IUPnPReregistrar_INTERFACE_DEFINED = 1

INTERFACE IUPnPReregistrar $IID_IUPnPReregistrar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReregisterDevice ( _                          ' VTable offset = 12
     BYVAL bstrDeviceIdentifier AS WSTRING _            ' __in BSTR bstrDeviceIdentifier
   , BYVAL bstrXMLDesc AS WSTRING _                     ' __in BSTR bstrXMLDesc
   , BYVAL bstrProgIDDeviceControlClass AS WSTRING _    ' __in BSTR bstrProgIDDeviceControlClass
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   , BYVAL bstrContainerId AS WSTRING _                 ' __in BSTR bstrContainerId
   , BYVAL bstrResourcePath AS WSTRING _                ' __in BSTR bstrResourcePath
   , BYVAL nLifeTime AS LONG _                          ' __in long nLifeTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReregisterRunningDevice ( _                   ' VTable offset = 16
     BYVAL bstrDeviceIdentifier AS WSTRING _            ' __in BSTR bstrDeviceIdentifier
   , BYVAL bstrXMLDesc AS WSTRING _                     ' __in BSTR bstrXMLDesc
   , BYVAL punkDeviceControl AS IUnknown _              ' __in IUnknown *punkDeviceControl
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   , BYVAL bstrResourcePath AS WSTRING _                ' __in BSTR bstrResourcePath
   , BYVAL nLifeTime AS LONG _                          ' __in long nLifeTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPReregistrar_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceControl
' IID = {204810BA-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceControl_INTERFACE_DEFINED)
    %IUPnPDeviceControl_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceControl $IID_IUPnPDeviceControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL bstrXMLDesc AS WSTRING _                     ' __in BSTR bstrXMLDesc
   , BYVAL bstrDeviceIdentifier AS WSTRING _            ' __in BSTR bstrDeviceIdentifier
   , BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceObject ( _                          ' VTable offset = 16
     BYVAL bstrUDN AS WSTRING _                         ' __in BSTR bstrUDN
   , BYVAL bstrServiceId AS WSTRING _                   ' __in BSTR bstrServiceId
   , BYREF ppdispService AS IDispatch _                 ' __retval_out IDispatch **ppdispService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceProvider
' IID = {204810B8-73B2-11D4-BF42-00B0D0118B56}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceProvider_INTERFACE_DEFINED)
    %IUPnPDeviceProvider_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceProvider $IID_IUPnPDeviceProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYVAL bstrInitString AS WSTRING _                  ' __in BSTR bstrInitString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPRemoteEndpointInfo
' IID = {C92EB863-0269-4AFF-9C72-75321BBA2952}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPRemoteEndpointInfo_INTERFACE_DEFINED)
    %IUPnPRemoteEndpointInfo_INTERFACE_DEFINED = 1

INTERFACE IUPnPRemoteEndpointInfo $IID_IUPnPRemoteEndpointInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDwordValue ( _                             ' VTable offset = 12
     BYVAL bstrValueName AS WSTRING _                   ' __in BSTR bstrValueName
   , BYREF pdwValue AS DWORD _                          ' __out DWORD *pdwValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringValue ( _                            ' VTable offset = 16
     BYVAL bstrValueName AS WSTRING _                   ' __in BSTR bstrValueName
   , BYREF pbstrValue AS WSTRING _                      ' __out BSTR *pbstrValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGuidValue ( _                              ' VTable offset = 20
     BYVAL bstrValueName AS WSTRING _                   ' __in BSTR bstrValueName
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPRemoteEndpointInfo_INTERFACE_DEFINED__ */
