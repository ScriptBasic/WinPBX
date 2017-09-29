' ########################################################################################
' Microsoft Windows
' File: UPnP.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: UPNPLib
' Version: 1.0, Locale ID = 0
' Description: UPnP 1.0 Type Library
' Path: C:\WINDOWS\system32\upnp.dll
' Library GUID: {DB3442A7-A2E9-4A59-9CB5-F5C1A5D901E5}
' ########################################################################################

#INCLUDE THIS ONCE
%UPNP_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_UPNPLib = GUID$("{DB3442A7-A2E9-4A59-9CB5-F5C1A5D901E5}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {1D8A9B47-3A28-4CE2-8A4B-BD34E45BCEEB}
$PROGID_UPnPDescriptionDocument1 = "UPnP.DescriptionDocument.1"
' CLSID = {A32552C5-BA61-457A-B59A-A2561E125E33}
$PROGID_UPnPDevice1 = "UPnP.UPnPDevice.1"
' CLSID = {E2085F28-FEB7-404A-B8E7-E659BDEAAA02}
$PROGID_UPnPDeviceFinder1 = "UPnP.UPnPDeviceFinder.1"
' CLSID = {B9E84FFD-AD3C-40A4-B835-0882EBCBAAA8}
$PROGID_UPnPDevices1 = "UPnP.UPnPDevices.1"
' CLSID = {C624BA95-FBCB-4409-8C03-8CCEEC533EF1}
$PROGID_UPnPService1 = "UPnP.UPnPService.1"
' CLSID = {C0BC4B4A-A406-4EFC-932F-B8546B8100CC}
$PROGID_UPnPServices1 = "UPnP.UPnPServices.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {1D8A9B47-3A28-4CE2-8A4B-BD34E45BCEEB}
$PROGID_UPnPDescriptionDocument = "UPnP.DescriptionDocument"
' CLSID = {A32552C5-BA61-457A-B59A-A2561E125E33}
$PROGID_UPnPDevice = "UPnP.UPnPDevice"
' CLSID = {E2085F28-FEB7-404A-B8E7-E659BDEAAA02}
$PROGID_UPnPDeviceFinder = "UPnP.UPnPDeviceFinder"
' CLSID = {B9E84FFD-AD3C-40A4-B835-0882EBCBAAA8}
$PROGID_UPnPDevices = "UPnP.UPnPDevices"
' CLSID = {C624BA95-FBCB-4409-8C03-8CCEEC533EF1}
$PROGID_UPnPService = "UPnP.UPnPService"
' CLSID = {C0BC4B4A-A406-4EFC-932F-B8546B8100CC}
$PROGID_UPnPServices = "UPnP.UPnPServices"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

'$CLSID_UPnPDeviceHostSetup                     = GUID$("{B4609411-C81C-4CCE-8C76-C6B50C9402C6}")
$CLSID_UPnPDescriptionDocument                 = GUID$("{1D8A9B47-3A28-4CE2-8A4B-BD34E45BCEEB}")
$CLSID_UPnPDevice                              = GUID$("{A32552C5-BA61-457A-B59A-A2561E125E33}")
$CLSID_UPnPDeviceFinder                        = GUID$("{E2085F28-FEB7-404A-B8E7-E659BDEAAA02}")
$CLSID_UPnPDevices                             = GUID$("{B9E84FFD-AD3C-40A4-B835-0882EBCBAAA8}")
$CLSID_UPnPService                             = GUID$("{C624BA95-FBCB-4409-8C03-8CCEEC533EF1}")
$CLSID_UPnPServices                            = GUID$("{C0BC4B4A-A406-4EFC-932F-B8546B8100CC}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

'$IID_IUPnPDeviceHostSetup                      = GUID$("{6BD34909-54E7-4FBF-8562-7B89709A589A}")
$IID_IUPnPAddressFamilyControl                 = GUID$("{E3BF6178-694E-459F-A5A6-191EA0FFA1C7}")
$IID_IUPnPDescriptionDocument                  = GUID$("{11D1C1B2-7DAA-4C9E-9595-7F82ED206D1E}")
$IID_IUPnPDevice                               = GUID$("{3D44D0D1-98C9-4889-ACD1-F9D674BF2221}")
$IID_IUPnPDeviceDocumentAccess                 = GUID$("{E7772804-3287-418E-9072-CF2B47238981}")
$IID_IUPnPDeviceDocumentAccessEx               = GUID$("{C4BC4050-6178-4BD1-A4B8-6398321F3247}")
$IID_IUPnPDeviceFinder                         = GUID$("{ADDA3D55-6F72-4319-BFF9-18600A539B10}")
$IID_IUPnPDeviceFinderAddCallbackWithInterface = GUID$("{983DFC0B-1796-44DF-8975-CA545B620EE5}")
$IID_IUPnPDeviceFinderCallback                 = GUID$("{415A984A-88B3-49F3-92AF-0508BEDF0D6C}")
$IID_IUPnPDevices                              = GUID$("{FDBC0C73-BDA3-4C66-AC4F-F2D96FDAD68C}")
$IID_IUPnPHttpHeaderControl                    = GUID$("{0405AF4F-8B5C-447C-80F2-B75984A31F3C}")
$IID_IUPnPService                              = GUID$("{A295019C-DC65-47DD-90DC-7FE918A1AB44}")
$IID_IUPnPServiceCallback                      = GUID$("{31FADCA9-AB73-464B-B67D-5C1D0F83C8B8}")
$IID_IUPnPServices                             = GUID$("{3F8C8E9E-9A7A-4DC8-BC41-FF31FA374956}")

$IID_IUPnPDescriptionDocumentCallback          = GUID$("{77394C69-5486-40D6-9BC3-4991983E02DA}")

%UPNP_E_ROOT_ELEMENT_EXPECTED     = &H80040200&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0200)
%UPNP_E_DEVICE_ELEMENT_EXPECTED   = &H80040201&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0201)
%UPNP_E_SERVICE_ELEMENT_EXPECTED  = &H80040202&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0202)
%UPNP_E_SERVICE_NODE_INCOMPLETE   = &H80040203&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0203)
%UPNP_E_DEVICE_NODE_INCOMPLETE    = &H80040204&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0204)
%UPNP_E_ICON_ELEMENT_EXPECTED     = &H80040205&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0205)
%UPNP_E_ICON_NODE_INCOMPLETE      = &H80040206&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0206)
%UPNP_E_INVALID_ACTION            = &H80040207&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0207)
%UPNP_E_INVALID_ARGUMENTS         = &H80040208&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0208)
%UPNP_E_OUT_OF_SYNC               = &H80040209&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0209)
%UPNP_E_ACTION_REQUEST_FAILED     = &H80040210&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0210)
%UPNP_E_TRANSPORT_ERROR           = &H80040211&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0211)
%UPNP_E_VARIABLE_VALUE_UNKNOWN    = &H80040212&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0212)
%UPNP_E_INVALID_VARIABLE          = &H80040213&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0213)
%UPNP_E_DEVICE_ERROR              = &H80040214&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0214)
%UPNP_E_PROTOCOL_ERROR            = &H80040215&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0215)
%UPNP_E_ERROR_PROCESSING_RESPONSE = &H80040216&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0216)
%UPNP_E_DEVICE_TIMEOUT            = &H80040217&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0217)
%UPNP_E_INVALID_DOCUMENT          = &H80040500&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0500)
%UPNP_E_EVENT_SUBSCRIPTION_FAILED = &H80040501&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0501)
%FAULT_INVALID_ACTION             = 401
%FAULT_INVALID_ARG                = 402
%FAULT_INVALID_SEQUENCE_NUMBER    = 403
%FAULT_INVALID_VARIABLE           = 404
%FAULT_DEVICE_INTERNAL_ERROR      = 501
%FAULT_ACTION_SPECIFIC_BASE       = 600
%FAULT_ACTION_SPECIFIC_MAX        = 899
%UPNP_E_ACTION_SPECIFIC_BASE      = &H80040300&   ' MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x0300)
%UPNP_E_ACTION_SPECIFIC_MAX       = %UPNP_E_ACTION_SPECIFIC_BASE + (%FAULT_ACTION_SPECIFIC_MAX - %FAULT_ACTION_SPECIFIC_BASE)
#IF NOT %DEF(%UPNP_ADDRESSFAMILY_IPv4)
%UPNP_ADDRESSFAMILY_IPv4          = &H1
#ENDIF
#IF NOT %DEF(%UPNP_ADDRESSFAMILY_IPv6)
%UPNP_ADDRESSFAMILY_IPv6          = &H2
#ENDIF
#IF NOT %DEF(%UPNP_ADDRESSFAMILY_BOTH)
%UPNP_ADDRESSFAMILY_BOTH          = &H3
#ENDIF

' ########################################################################################
' Interface name = IUPnPDeviceFinder
' IID = {ADDA3D55-6F72-4319-BFF9-18600A539B10}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceFinder_INTERFACE_DEFINED)
    %IUPnPDeviceFinder_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceFinder $IID_IUPnPDeviceFinder

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FindByType <1610744809> ( _                   ' VTable offset = 28
     BYVAL bstrTypeURI AS WSTRING _                     ' __in BSTR bstrTypeURI
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS IUPnPDevices                                    ' __retval_out IUPnPDevices **pDevices
   ' =====================================================================================
   METHOD CreateAsyncFind <1610744812> ( _              ' VTable offset = 32
     BYVAL bstrTypeURI AS WSTRING _                     ' __in BSTR bstrTypeURI
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL punkDeviceFinderCallback AS IUnknown _       ' __in IUnknown *punkDeviceFinderCallback
   ) AS LONG                                            ' __retval_out LONG *plFindData
   ' =====================================================================================
   METHOD StartAsyncFind <1610744813> ( _               ' VTable offset = 36
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelAsyncFind <1610744814> ( _              ' VTable offset = 40
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   )                                                    ' void
   ' =====================================================================================
   METHOD FindByUDN <1610744811> ( _                    ' VTable offset = 44
     BYVAL bstrUDN AS WSTRING _                         ' __in BSTR bstrUDN
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **pDevice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceFinder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPAddressFamilyControl
' IID = {E3BF6178-694E-459F-A5A6-191EA0FFA1C7}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPAddressFamilyControl_INTERFACE_DEFINED)
    %IUPnPAddressFamilyControl_INTERFACE_DEFINED = 1

INTERFACE IUPnPAddressFamilyControl $IID_IUPnPAddressFamilyControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD SetAddressFamily ( _                          ' VTable offset = 12
     BYVAL dwFlags AS LONG _                            ' __in LONG dwFlags
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAddressFamily ( _                          ' VTable offset = 16
     BYREF pdwFlags AS LONG _                           ' __out LONG *pdwFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPAddressFamilyControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPHttpHeaderControl
' IID = {0405AF4F-8B5C-447C-80F2-B75984A31F3C}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPHttpHeaderControl_INTERFACE_DEFINED)
    %IUPnPHttpHeaderControl_INTERFACE_DEFINED = 1

INTERFACE IUPnPHttpHeaderControl $IID_IUPnPHttpHeaderControl

   INHERIT IAutomation

   ' =====================================================================================
   METHOD AddRequestHeaders ( _                         ' VTable offset = 12
     BYVAL bstrHttpHeaders AS WSTRING _                 ' __in BSTR bstrHttpHeaders
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPHttpHeaderControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IUPnPDeviceFinderCallback
' IID = {415A984A-88B3-49F3-92AF-0508BEDF0D6C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceFinderCallback_INTERFACE_DEFINED)
    %IUPnPDeviceFinderCallback_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceFinderCallback $IID_IUPnPDeviceFinderCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeviceAdded ( _                               ' VTable offset = 12
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   , BYVAL pDevice AS IUPnPDevice _                     ' __in IUPnPDevice *pDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeviceRemoved ( _                             ' VTable offset = 16
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   , BYVAL bstrUDN AS WSTRING _                         ' __in BSTR bstrUDN
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SearchComplete ( _                            ' VTable offset = 20
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceFinderCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPServices
' IID = {3F8C8E9E-9A7A-4DC8-BC41-FF31FA374956}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPServices_INTERFACE_DEFINED)
    %IUPnPServices_INTERFACE_DEFINED = 1

INTERFACE IUPnPServices $IID_IUPnPServices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610745809> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppunk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL bstrServiceId AS WSTRING _                   ' __in BSTR bstrServiceId
   ) AS IUPnPService                                    ' __retval_out IUPnPService **ppService
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPServices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPService
' IID = {A295019C-DC65-47DD-90DC-7FE918A1AB44}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPService_INTERFACE_DEFINED)
    %IUPnPService_INTERFACE_DEFINED = 1

INTERFACE IUPnPService $IID_IUPnPService

   INHERIT IDispatch

   ' =====================================================================================
   METHOD QueryStateVariable <1610746309> ( _           ' VTable offset = 28
     BYVAL bstrVariableName AS WSTRING _                ' __in BSTR bstrVariableName
   ) AS VARIANT                                         ' __retval_out VARIANT *pValue
   ' =====================================================================================
   METHOD InvokeAction <1610746310> ( _                 ' VTable offset = 32
     BYVAL bstrActionName AS WSTRING _                  ' __in BSTR bstrActionName
   , BYVAL vInActionArgs AS VARIANT _                   ' __in VARIANT vInActionArgs
   , BYREF pvOutActionArgs AS VARIANT _                 ' __inout VARIANT *pvOutActionArgs
   ) AS VARIANT                                         ' __retval_out VARIANT *pvRetVal
   ' =====================================================================================
   PROPERTY GET ServiceTypeIdentifier <1610746311> ( _  ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD AddCallback <1610746312> ( _                  ' VTable offset = 40
     BYVAL pUnkCallback AS IUnknown _                   ' __in IUnknown *pUnkCallback
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id <1610746313> ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrId
   ' =====================================================================================
   PROPERTY GET LastTransportStatus <1610746314> ( _    ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPService_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPServiceCallback
' IID = {31FADCA9-AB73-464B-B67D-5C1D0F83C8B8}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPServiceCallback_INTERFACE_DEFINED)
    %IUPnPServiceCallback_INTERFACE_DEFINED = 1

INTERFACE IUPnPServiceCallback $IID_IUPnPServiceCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StateVariableChanged ( _                      ' VTable offset = 12
     BYVAL pus AS IUPnPService _                        ' __in IUPnPService *pus
   , BYREF pcwszStateVarName AS WSTRINGZ _              ' __in LPCWSTR pcwszStateVarName
   , BYVAL vaValue AS VARIANT _                         ' __in VARIANT vaValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ServiceInstanceDied ( _                       ' VTable offset = 16
     BYVAL pus AS IUPnPService _                        ' __in IUPnPService *pus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPServiceCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDevices
' IID = {FDBC0C73-BDA3-4C66-AC4F-F2D96FDAD68C}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPDevices_INTERFACE_DEFINED)
    %IUPnPDevices_INTERFACE_DEFINED = 1

INTERFACE IUPnPDevices $IID_IUPnPDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610747309> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IUnknown                                        ' __retval_out LPUNKNOWN *ppunk
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL bstrUDN AS WSTRING _                         ' __in BSTR bstrUDN
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **ppDevice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDevices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDevice
' IID = {3D44D0D1-98C9-4889-ACD1-F9D674BF2221}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPDevice_INTERFACE_DEFINED)
    %IUPnPDevice_INTERFACE_DEFINED = 1

INTERFACE IUPnPDevice $IID_IUPnPDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET IsRootDevice <1610747809> ( _           ' VTable offset = 28
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvarb
   ' =====================================================================================
   PROPERTY GET RootDevice <1610747810> ( _             ' VTable offset = 32
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **ppudRootDevice
   ' =====================================================================================
   PROPERTY GET ParentDevice <1610747811> ( _           ' VTable offset = 36
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **ppudDeviceParent
   ' =====================================================================================
   PROPERTY GET HasChildren <1610747812> ( _            ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pvarb
   ' =====================================================================================
   PROPERTY GET Children <1610747813> ( _               ' VTable offset = 44
   ) AS IUPnPDevices                                    ' __retval_out IUPnPDevices **ppudChildren
   ' =====================================================================================
   PROPERTY GET UniqueDeviceName <1610747814> ( _       ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET FriendlyName <1610747815> ( _           ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Type <1610747816> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET PresentationURL <1610747817> ( _        ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET ManufacturerName <1610747818> ( _       ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET ManufacturerURL <1610747819> ( _        ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET ModelName <1610747820> ( _              ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET ModelNumber <1610747821> ( _            ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET Description <1610747822> ( _            ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET ModelURL <1610747823> ( _               ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET UPC <1610747824> ( _                    ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   PROPERTY GET SerialNumber <1610747825> ( _           ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pbstr
   ' =====================================================================================
   METHOD IconURL <1610747827> ( _                      ' VTable offset = 96
     BYVAL bstrEncodingFormat AS WSTRING _              ' __in BSTR bstrEncodingFormat
   , BYVAL lSizeX AS LONG _                             ' __in LONG lSizeX
   , BYVAL lSizeY AS LONG _                             ' __in LONG lSizeY
   , BYVAL lBitDepth AS LONG _                          ' __in LONG lBitDepth
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrIconURL
   ' =====================================================================================
   PROPERTY GET Services <1610747828> ( _               ' VTable offset = 100
   ) AS IUPnPServices                                   ' __retval_out IUPnPServices **ppusServices
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceDocumentAccess
' IID = {E7772804-3287-418E-9072-CF2B47238981}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceDocumentAccess_INTERFACE_DEFINED)
    %IUPnPDeviceDocumentAccess_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceDocumentAccess $IID_IUPnPDeviceDocumentAccess

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetDocumentURL ( _                            ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocument
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceDocumentAccess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceDocumentAccessEx
' IID = {C4BC4050-6178-4BD1-A4B8-6398321F3247}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED)
    %IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceDocumentAccessEx $IID_IUPnPDeviceDocumentAccessEx

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDocument
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceDocumentAccessEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDescriptionDocument
' IID = {11D1C1B2-7DAA-4C9E-9595-7F82ED206D1E}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IUPnPDescriptionDocument_INTERFACE_DEFINED)
    %IUPnPDescriptionDocument_INTERFACE_DEFINED = 1

INTERFACE IUPnPDescriptionDocument $IID_IUPnPDescriptionDocument

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *plReadyState
   ' =====================================================================================
   METHOD Load <1610748309> ( _                         ' VTable offset = 32
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD LoadAsync <1610748310> ( _                    ' VTable offset = 36
     BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   , BYVAL punkCallback AS IUnknown _                   ' __in IUnknown *punkCallback
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LoadResult <1610748311> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *phrError
   ' =====================================================================================
   METHOD Abort <1610748312> ( _                        ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD RootDevice <1610748313> ( _                   ' VTable offset = 48
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **ppudRootDevice
   ' =====================================================================================
   METHOD DeviceByUDN <1610748314> ( _                  ' VTable offset = 52
     BYVAL bstrUDN AS WSTRING _                         ' __in BSTR bstrUDN
   ) AS IUPnPDevice                                     ' __retval_out IUPnPDevice **ppudDevice
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDescriptionDocument_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceFinderAddCallbackWithInterface
' IID = {983DFC0B-1796-44DF-8975-CA545B620EE5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED)
    %IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED = 1

INTERFACE IUPnPDeviceFinderAddCallbackWithInterface $IID_IUPnPDeviceFinderAddCallbackWithInterface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeviceAddedWithInterface ( _                  ' VTable offset = 12
     BYVAL lFindData AS LONG _                          ' __in LONG lFindData
   , BYVAL pDevice AS IUPnPDevice _                     ' __in IUPnPDevice *pDevice
   , BYREF pguidInterface AS GUID _                     ' __in GUID *pguidInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDeviceFinderAddCallbackWithInterface_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDescriptionDocumentCallback
' IID = {983DFC0B-1796-44DF-8975-CA545B620EE5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED)
    %IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED = 1

INTERFACE IUPnPDescriptionDocumentCallback $IID_IUPnPDescriptionDocumentCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadComplete ( _                              ' VTable offset = 12
     BYVAL hrLoadResult AS LONG _                       ' __in HRESULT hrLoadResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUPnPDescriptionDocumentCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IUPnPDeviceHostSetup
' IID = {6BD34909-54E7-4FBF-8562-7B89709A589A}
' Attributes = 256 [&H100] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

'#IF NOT %DEF(%IUPnPDeviceHostSetup_INTERFACE_DEFINED)
'    %IUPnPDeviceHostSetup_INTERFACE_DEFINED = 1

'INTERFACE IUPnPDeviceHostSetup $IID_IUPnPDeviceHostSetup

'   INHERIT IAutomation

'   ' =====================================================================================
'   METHOD AskIfNotAlreadyEnabled ( _                    ' VTable offset = 12
'   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEnabled
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IUPnPDeviceHostSetup_INTERFACE_DEFINED__ */
