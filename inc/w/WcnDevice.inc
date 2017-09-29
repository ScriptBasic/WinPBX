' ########################################################################################
' Microsoft Windows
' File: WcnDevice.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCNDEVICE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "WcnTypes.inc"

'#if NTDDI_VERSION >= NTDDI_WIN7

'EXTERN_C const IID LIBID_WCNDeviceObjectLibrary;
$CLSID_WCNDeviceObject = GUID$("{C100BEA7-D33A-4a4b-BF23-BBEF4663D017}")

%WCN_API_MAX_BUFFER_SIZE = 2096

' enum WCN_PASSWORD_TYPE
%WCN_PASSWORD_TYPE_PUSH_BUTTON = 0
%WCN_PASSWORD_TYPE_PIN         = %WCN_PASSWORD_TYPE_PUSH_BUTTON + 1

' enum WCN_SESSION_STATUS
%WCN_SESSION_STATUS_SUCCESS         = 0
%WCN_SESSION_STATUS_FAILURE_GENERIC = %WCN_SESSION_STATUS_SUCCESS         + 1
%WCN_SESSION_STATUS_FAILURE_TIMEOUT = %WCN_SESSION_STATUS_FAILURE_GENERIC + 1

TYPE WCN_VENDOR_EXTENSION_SPEC DWORD
   VendorId AS DWORD   ' DWORD
   SubType  AS DWORD   ' DWORD
   Index    AS DWORD   ' DWORD
   Flags    AS DWORD   ' DWORD
END TYPE

%WCN_MICROSOFT_VENDOR_ID   = 311&
%WCN_NO_SUBTYPE            = &Hfffffffe???
%WCN_FLAG_DISCOVERY_VE     = &H1???
%WCN_FLAG_AUTHENTICATED_VE = &H2???
%WCN_FLAG_ENCRYPTED_VE     = &H4???

' ########################################################################################
' IWCNDevice interface
' IID = C100BE9C-D33A-4a4b-BF23-BBEF4663D017
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWCNDevice_INTERFACE_DEFINED)
    %IWCNDevice_INTERFACE_DEFINED = 1

$IID_IWCNDevice = GUID$("{C100BE9C-D33A-4a4b-BF23-BBEF4663D017}")

INTERFACE IWCNDevice $IID_IWCNDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPassword ( _                               ' VTable offset = 12
     BYVAL Type AS LONG _                               ' __in WCN_PASSWORD_TYPE Type
   , BYVAL dwPasswordLength AS DWORD _                  ' __in DWORD dwPasswordLength
   , BYVAL pbPassword AS BYTE PTR _                     ' __in const BYTE pbPassword[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 16
     BYVAL pNotify AS IWCNConnectNotify _               ' __in IWCNConnectNotify *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttribute ( _                              ' VTable offset = 20
     BYVAL AttributeType AS LONG _                      ' __in WCN_ATTRIBUTE_TYPE AttributeType
   , BYVAL dwMaxBufferSize AS DWORD _                   ' __in DWORD dwMaxBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE pbBuffer[  ]
   , BYREF pdwBufferUsed AS DWORD _                     ' __out DWORD *pdwBufferUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntegerAttribute ( _                       ' VTable offset = 24
     BYVAL AttributeType AS LONG _                      ' __in WCN_ATTRIBUTE_TYPE AttributeType
   , BYREF puInteger AS DWORD _                         ' __out UINT *puInteger
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringAttribute ( _                        ' VTable offset = 28
     BYVAL AttributeType AS LONG _                      ' __in WCN_ATTRIBUTE_TYPE AttributeType
   , BYVAL cchMaxString AS DWORD _                      ' __in DWORD cchMaxString
   , BYREF wszString AS WSTRINGZ _                      ' __out WCHAR wszString[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNetworkProfile ( _                         ' VTable offset = 32
     BYVAL cchMaxStringLength AS DWORD _                ' __in DWORD cchMaxStringLength
   , BYREF wszProfile AS WSTRINGZ _                     ' __out LPWSTR wszProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNetworkProfile ( _                         ' VTable offset = 36
     BYREF pszProfileXml AS WSTRINGZ _                  ' __in LPCWSTR pszProfileXml
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorExtension ( _                        ' VTable offset = 40
     BYREF pVendorExtSpec AS WCN_VENDOR_EXTENSION_SPEC _ ' __in const WCN_VENDOR_EXTENSION_SPEC *pVendorExtSpec
   , BYVAL dwMaxBufferSize AS DWORD _                   ' __in DWORD dwMaxBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE pbBuffer[  ]
   , BYREF pdwBufferUsed AS DWORD _                     ' __out DWORD *pdwBufferUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVendorExtension ( _                        ' VTable offset = 44
     BYREF pVendorExtSpec AS WCN_VENDOR_EXTENSION_SPEC _ ' __in const WCN_VENDOR_EXTENSION_SPEC *pVendorExtSpec
   , BYVAL cbBuffer AS DWORD _                          ' __in DWORD cbBuffer
   , BYVAL pbBuffer AS BYTE PTR _                       ' __in const BYTE pbBuffer[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWCNDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' IWCNConnectNotify interface
' IID = C100BE9F-D33A-4a4b-BF23-BBEF4663D017
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWCNConnectNotify_INTERFACE_DEFINED)
    %IWCNConnectNotify_INTERFACE_DEFINED = 1

$IID_IWCNConnectNotify = GUID$("{C100BE9F-D33A-4a4b-BF23-BBEF4663D017}")

INTERFACE IWCNConnectNotify $IID_IWCNConnectNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConnectSucceeded ( _                          ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectFailed ( _                             ' VTable offset = 16
     BYVAL hrFailure AS LONG _                          ' __in HRESULT hrFailure
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWCNConnectNotify_INTERFACE_DEFINED__ */

'#endif // NTDDI_VERSION >= NTDDI_WIN7
