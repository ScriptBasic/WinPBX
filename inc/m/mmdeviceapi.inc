' ########################################################################################
' Microsoft Windows
' File: MMDeviceApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MMDeviceAPILib
' Version: 1.0, Locale ID = 0
' Documentation string: MM Device API 1.0 Type Library
' Library GUID: {2FDAAFA3-7523-4F66-9957-9D5E7FE698F6}
' ########################################################################################

#INCLUDE THIS ONCE
%MMDEVICEAPI_INC = 1

$CLSID_MMDeviceEnumerator = GUID$("{BCDE0395-E52F-467C-8E3D-C4579291692E}")

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "propsys.inc"

'#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)
'#define E_UNSUPPORTED_TYPE HRESULT_FROM_WIN32(ERROR_UNSUPPORTED_TYPE)
%E_NOTFOUND         = -2147023728&
%E_UNSUPPORTED_TYPE = -2147023266&

%DEVICE_STATE_ACTIVE      = &H00000001???
%DEVICE_STATE_DISABLED    = &H00000002???
%DEVICE_STATE_NOTPRESENT  = &H00000004???
%DEVICE_STATE_UNPLUGGED   = &H00000008???
%DEVICE_STATEMASK_ALL     = &H0000000f???

'#ifdef DEFINE_PROPERTYKEY
'#undef DEFINE_PROPERTYKEY
'#endif
'#ifdef INITGUID
'#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const PROPERTYKEY name = { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
'#else
'#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const PROPERTYKEY name
'#endif // INITGUID

#IF NOT %DEF(%DEFINE_PROPERTYKEY)
%DEFINE_PROPERTYKEY = 1
MACRO DEFINE_PROPERTYKEY(propName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid)
   propName.Data1    = l
   propName.Data2    = w1
   propName.Data3    = w2
   propName.Data4(0) = b1
   propName.Data4(1) = b2
   propName.Data4(2) = b3
   propName.Data4(3) = b4
   propName.Data4(4) = b5
   propName.Data4(5) = b6
   propName.Data4(6) = b7
   propName.Data4(7) = b8
   propName.pid      = pid
END MACRO
#ENDIF

'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_FormFactor, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 0);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_ControlPanelPageProvider, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 1);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_Association, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 2);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_PhysicalSpeakers, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 3);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_GUID, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 4);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_Disable_SysFx, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 5);

MACRO PKEY_AudioEndpoint_FormFactor = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(0)
MACRO PKEY_AudioEndpoint_ControlPanelPageProvider = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(1)
MACRO PKEY_AudioEndpoint_Association = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(2)
MACRO PKEY_AudioEndpoint_PhysicalSpeakers = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(3)
MACRO PKEY_AudioEndpoint_GUID = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(4)
MACRO PKEY_AudioEndpoint_Disable_SysFx = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(5)

%ENDPOINT_SYSFX_ENABLED  = &H00000000???  ' // System Effects are enabled.
%ENDPOINT_SYSFX_DISABLED = &H00000001???  ' // System Effects are disabled.

'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_FullRangeSpeakers, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 6);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_Supports_EventDriven_Mode, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 7);
'DEFINE_PROPERTYKEY(PKEY_AudioEndpoint_JackSubType, 0x1da5d803, 0xd492, 0x4edd, 0x8c, 0x23, 0xe0, 0xc0, 0xff, 0xee, 0x7f, 0x0e, 8);
'DEFINE_PROPERTYKEY(PKEY_AudioEngine_DeviceFormat, 0xf19f064d, 0x82c, 0x4e27, 0xbc, 0x73, 0x68, 0x82, 0xa1, 0xbb, 0x8e, 0x4c, 0);
'DEFINE_PROPERTYKEY(PKEY_AudioEngine_OEMFormat, 0xe4870e26, 0x3cc5, 0x4cd2, 0xba, 0x46, 0xca, 0xa, 0x9a, 0x70, 0xed, 0x4, 3);

MACRO PKEY_AudioEndpoint_FullRangeSpeakers = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(6)
MACRO PKEY_AudioEndpoint_Supports_EventDriven_Mode = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(7)
MACRO PKEY_AudioEndpoint_JackSubType = GUID$("{1DA5D803-D492-4EDD-8C23-E0C0FFEE7F0E}") & MKDWD$(8)
MACRO PKEY_AudioEngine_DeviceFormat = GUID$("{F19F064D-082C-4E27-BC73-6882A1BB8E4C}") & MKDWD$(0)
MACRO PKEY_AudioEngine_OEMFormat = GUID$("{E4870E26-3CC5-4CD2-BA46-CA0A9A70ED04}") & MKDWD$(3)

' // Size = 24 bytes
TYPE DIRECTX_AUDIO_ACTIVATION_PARAMS DWORD
   cbDirectXAudioActivationParams AS DWORD
   guidAudioSession               AS GUID
   dwAudioStreamFlags             AS DWORD
END TYPE

' EDataFlow enum
%EDataFlow_eRender              = 0
%EDataFlow_eCapture             = %EDataFlow_eRender  + 1
%EDataFlow_eAll                 = %EDataFlow_eCapture + 1
%EDataFlow_enum_count           = %EDataFlow_eAll     + 1

' ERole enum
%ERole_eConsole         = 0
%ERole_eMultimedia      = %ERole_eConsole        + 1
%ERole_eCommunications  = %ERole_eMultimedia     + 1
%ERole_enum_count       = %ERole_eCommunications + 1

' EndpointFormFactor enum
%EndpointFormFactor_RemoteNetworkDevice           = 0
%EndpointFormFactor_Speakers                      = %EndpointFormFactor_RemoteNetworkDevice       + 1
%EndpointFormFactor_LineLevel                     = %EndpointFormFactor_Speakers                  + 1
%EndpointFormFactor_Headphones                    = %EndpointFormFactor_LineLevel                 + 1
%EndpointFormFactor_Microphone                    = %EndpointFormFactor_Headphones                + 1
%EndpointFormFactor_Headset                       = %EndpointFormFactor_Microphone                + 1
%EndpointFormFactor_Handset                       = %EndpointFormFactor_Headset                   + 1
%EndpointFormFactor_UnknownDigitalPassthrough     = %EndpointFormFactor_Handset                   + 1
%EndpointFormFactor_SPDIF                         = %EndpointFormFactor_UnknownDigitalPassthrough + 1
%EndpointFormFactor_DigitalAudioDisplayDevice     = %EndpointFormFactor_SPDIF                     + 1
%EndpointFormFactor_UnknownFormFactor             = %EndpointFormFactor_DigitalAudioDisplayDevice + 1
%EndpointFormFactor_EndpointFormFactor_enum_count = %EndpointFormFactor_UnknownFormFactor         + 1

%EndpointFormFactor_HDMI = %EndpointFormFactor_DigitalAudioDisplayDevice

' ########################################################################################
' Interface name = IMMNotificationClient
' IID = 7991EEC9-7E89-4D85-8390-6C703CEC60C0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMMNotificationClient_INTERFACE_DEFINED)
    %IMMNotificationClient_INTERFACE_DEFINED = 1

$IID_IMMNotificationClient = GUID$("{7991EEC9-7E89-4D85-8390-6C703CEC60C0}")

INTERFACE IMMNotificationClient $IID_IMMNotificationClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDeviceStateChanged ( _                      ' VTable offset = 12
     BYREF pwstrDeviceId AS WSTRINGZ _                  ' __in LPCWSTR pwstrDeviceId
   , BYVAL dwNewState AS DWORD _                        ' __in DWORD dwNewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeviceAdded ( _                             ' VTable offset = 16
     BYREF pwstrDeviceId AS WSTRINGZ _                  ' __in LPCWSTR pwstrDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeviceRemoved ( _                           ' VTable offset = 20
     BYREF pwstrDeviceId AS WSTRINGZ _                  ' __in LPCWSTR pwstrDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDefaultDeviceChanged ( _                    ' VTable offset = 24
     BYVAL flow AS LONG _                               ' __in EDataFlow flow
   , BYVAL role AS LONG _                               ' __in ERole role
   , BYREF pwstrDefaultDeviceId AS WSTRINGZ _           ' __in LPCWSTR pwstrDefaultDeviceId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPropertyValueChanged ( _                    ' VTable offset = 28
     BYREF pwstrDeviceId AS WSTRINGZ _                  ' __in LPCWSTR pwstrDeviceId
   , BYREF key AS PROPERTYKEY _                         ' __in const PROPERTYKEY key
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMNotificationClient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMMDevice
' IID = D666063F-1587-4E43-81F1-B948E807363F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMMDevice_INTERFACE_DEFINED)
    %IMMDevice_INTERFACE_DEFINED = 1

$IID_IMMDevice = GUID$("{D666063F-1587-4E43-81F1-B948E807363F}")

INTERFACE IMMDevice $IID_IMMDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYVAL dwClsCtx AS DWORD _                          ' __in DWORD dwClsCtx
   , BYREF pActivationParams AS PROPVARIANT _           ' __in PROPVARIANT *pActivationParams
   , BYREF ppInterface AS IUnknown _                    ' __out void **ppInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenPropertyStore ( _                         ' VTable offset = 16
     BYVAL stgmAccess AS DWORD _                        ' __in DWORD stgmAccess
   , BYREF ppProperties AS IPropertyStore _             ' __out IPropertyStore **ppProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 20
     BYREF ppstrId AS DWORD _                           ' __out LPWSTR *ppstrId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 24
     BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMMDeviceCollection
' IID = 0BD7A1BE-7A1A-44DB-8397-CC5392387B5E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMMDeviceCollection_INTERFACE_DEFINED)
    %IMMDeviceCollection_INTERFACE_DEFINED = 1

$IID_IMMDeviceCollection = GUID$("{0BD7A1BE-7A1A-44DB-8397-CC5392387B5E}")

INTERFACE IMMDeviceCollection $IID_IMMDeviceCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcDevices AS DWORD _                         ' __out UINT *pcDevices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 16
     BYVAL nDevice AS DWORD _                           ' __in UINT nDevice
   , BYREF ppDevice AS IMMDevice _                      ' __out IMMDevice **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMDeviceCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMMEndpoint
' IID = 1BE09788-6894-4089-8586-9A2A6C265AC5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMMEndpoint_INTERFACE_DEFINED)
    %IMMEndpoint_INTERFACE_DEFINED = 1

$IID_IMMEndpoint = GUID$("{1BE09788-6894-4089-8586-9A2A6C265AC5}")

INTERFACE IMMEndpoint $IID_IMMEndpoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDataFlow ( _                               ' VTable offset = 12
     BYREF pDataFlow AS LONG _                          ' __out EDataFlow *pDataFlow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMEndpoint_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMMDeviceEnumerator
' IID = A95664D2-9614-4F35-A746-DE8DB63617E6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMMDeviceEnumerator_INTERFACE_DEFINED)
    %IMMDeviceEnumerator_INTERFACE_DEFINED = 1

$IID_IMMDeviceEnumerator = GUID$("{A95664D2-9614-4F35-A746-DE8DB63617E6}")

INTERFACE IMMDeviceEnumerator $IID_IMMDeviceEnumerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumAudioEndpoints ( _                        ' VTable offset = 12
     BYVAL dataFlow AS LONG _                           ' __in EDataFlow dataFlow
   , BYVAL dwStateMask AS DWORD _                       ' __in DWORD dwStateMask
   , BYREF ppDevices AS IMMDeviceCollection _           ' __out IMMDeviceCollection **ppDevices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultAudioEndpoint ( _                   ' VTable offset = 16
     BYVAL dataFlow AS LONG _                           ' __in EDataFlow dataFlow
   , BYVAL role AS LONG _                               ' __in ERole role
   , BYREF ppEndpoint AS IMMDevice _                    ' __out IMMDevice **ppEndpoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevice ( _                                 ' VTable offset = 20
     BYREF pwstrId AS WSTRINGZ _                        ' __in LPCWSTR pwstrId
   , BYREF ppDevice AS IMMDevice _                      ' __out IMMDevice **ppDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterEndpointNotificationCallback ( _      ' VTable offset = 24
     BYVAL pClient AS IMMNotificationClient _           ' __in IMMNotificationClient *pClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterEndpointNotificationCallback ( _    ' VTable offset = 28
     BYVAL pClient AS IMMNotificationClient _           ' __in IMMNotificationClient *pClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMDeviceEnumerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMMDeviceActivator
' IID = 3B0D0EA4-D0A9-4B0E-935B-09516746FAC0
' Inherited interface = IUnknown
' /* IMMDeviceActivator is reserved for system use */
' ########################################################################################

#IF NOT %DEF(%IMMDeviceActivator_INTERFACE_DEFINED)
    %IMMDeviceActivator_INTERFACE_DEFINED = 1

$IID_IMMDeviceActivator = GUID$("{3B0D0EA4-D0A9-4B0E-935B-09516746FAC0}")

INTERFACE IMMDeviceActivator $IID_IMMDeviceActivator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Activate ( _                                  ' VTable offset = 12
     BYREF iid AS GUID _                                ' __in REFIID iid
   , BYVAL pDevice AS IMMDevice _                       ' __in IMMDevice *pDevice
   , BYREF pActivationParams AS PROPVARIANT _           ' __in PROPVARIANT *pActivationParams
   , BYREF ppInterface AS IUnknown _                    ' __out void **ppInterface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMMDeviceActivator_INTERFACE_DEFINED__ */

' // Size = 16 bytes
TYPE AudioExtensionParams DWORD
   AddPageParam  AS LONG        ' LPARAM
   pEndpoint     AS DWORD PTR   ' IMMDevice *
   pPnpInterface AS DWORD PTR   ' IMMDevice *
   pPnpDevnode   AS DWORD PTR   ' IMMDevice *
END TYPE
