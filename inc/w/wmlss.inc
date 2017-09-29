' ########################################################################################
' Microsoft Windows
' File: wmlss.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WMLSS
' Version: 1.0, Locale ID = 0
' Documentation string: Windows Media Library Sharing Services
' Library GUID: {C21E9CE5-B317-463B-A1B1-B5E36EED59D0}
' ########################################################################################

#INCLUDE THIS ONCE
%WMLSS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

$LIBID_WMLSS = GUID$("{C21E9CE5-B317-463B-A1B1-B5E36EED59D0}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {AD581B00-7B64-4E59-A38D-D2C5BF51DDB3}
$PROGID_WindowsMediaLibrarySharingServices1 = "WMLSS.WindowsMediaLibrarySharingServices.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {AD581B00-7B64-4E59-A38D-D2C5BF51DDB3}
$PROGID_WindowsMediaLibrarySharingServices = "WMLSS.WindowsMediaLibrarySharingServices"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WindowsMediaLibrarySharingServices = GUID$("{AD581B00-7B64-4E59-A38D-D2C5BF51DDB3}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWindowsMediaLibrarySharingDevice = GUID$("{3DCCC293-4FD9-4191-A25B-8E57C5D27BD4}")
$IID_IWindowsMediaLibrarySharingDeviceProperties = GUID$("{C4623214-6B06-40C5-A623-B2FF4C076BFD}")
$IID_IWindowsMediaLibrarySharingDeviceProperty = GUID$("{81E26927-7A7D-40A7-81D4-BDDC02960E3E}")
$IID_IWindowsMediaLibrarySharingDevices = GUID$("{1803F9D6-FE6D-4546-BF5B-992FE8EC12D1}")
$IID_IWindowsMediaLibrarySharingServices = GUID$("{01F5F85E-0A81-40DA-A7C8-21EF3AF8440C}")

' ========================================================================================
' WindowsMediaLibrarySharingDeviceAuthorizationStatus enum
' Windows Media Library Sharing Device Authorization
' ========================================================================================

%DEVICE_AUTHORIZATION_UNKNOWN = 0
%DEVICE_AUTHORIZATION_ALLOWED = 1
%DEVICE_AUTHORIZATION_DENIED  = 2


' ########################################################################################
' Interface name = IWindowsMediaLibrarySharingDeviceProperty
' IID = {81E26927-7A7D-40A7-81D4-BDDC02960E3E}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWindowsMediaLibrarySharingDeviceProperty_INTERFACE_DEFINED)
    %IWindowsMediaLibrarySharingDeviceProperty_INTERFACE_DEFINED = 1

INTERFACE IWindowsMediaLibrarySharingDeviceProperty $IID_IWindowsMediaLibrarySharingDeviceProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 32
   ) AS VARIANT                                         ' __retval_out VARIANT *Value
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowsMediaLibrarySharingDeviceProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWindowsMediaLibrarySharingDeviceProperties
' IID = {C4623214-6B06-40C5-A623-B2FF4C076BFD}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWindowsMediaLibrarySharingDeviceProperties_INTERFACE_DEFINED)
    %IWindowsMediaLibrarySharingDeviceProperties_INTERFACE_DEFINED = 1

INTERFACE IWindowsMediaLibrarySharingDeviceProperties $IID_IWindowsMediaLibrarySharingDeviceProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in LONG index
   ) AS IWindowsMediaLibrarySharingDeviceProperty       ' __retval_out IWindowsMediaLibrarySharingDeviceProperty **property
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *Count
   ' =====================================================================================
   METHOD GetProperty <2> ( _                           ' VTable offset = 36
     BYVAL Name AS WSTRING _                            ' __in Name VT_BSTR
   ) AS IWindowsMediaLibrarySharingDeviceProperty       ' __retval_out IWindowsMediaLibrarySharingDeviceProperty **property
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowsMediaLibrarySharingDeviceProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWindowsMediaLibrarySharingDevice
' IID = {3DCCC293-4FD9-4191-A25B-8E57C5D27BD4}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWindowsMediaLibrarySharingDevice_INTERFACE_DEFINED)
    %IWindowsMediaLibrarySharingDevice_INTERFACE_DEFINED = 1

INTERFACE IWindowsMediaLibrarySharingDevice $IID_IWindowsMediaLibrarySharingDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceID <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *DeviceID
   ' =====================================================================================
   PROPERTY GET Authorization <2> ( _                   ' VTable offset = 32
   ) AS LONG                                            ' __retval_out WindowsMediaLibrarySharingDeviceAuthorizationStatus *Authorization
   ' =====================================================================================
   PROPERTY SET Authorization <2> ( _                   ' VTable offset = 36
     BYVAL Authorization AS LONG _                      ' __in WindowsMediaLibrarySharingDeviceAuthorizationStatus Authorization
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <3> ( _                      ' VTable offset = 40
   ) AS IWindowsMediaLibrarySharingDeviceProperties     ' __retval_out IWindowsMediaLibrarySharingDeviceProperties **deviceProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowsMediaLibrarySharingDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWindowsMediaLibrarySharingDevices
' IID = {1803F9D6-FE6D-4546-BF5B-992FE8EC12D1}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWindowsMediaLibrarySharingDevices_INTERFACE_DEFINED)
    %IWindowsMediaLibrarySharingDevices_INTERFACE_DEFINED = 1

INTERFACE IWindowsMediaLibrarySharingDevices $IID_IWindowsMediaLibrarySharingDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL index AS LONG _                              ' __in LONG index
   ) AS IWindowsMediaLibrarySharingDevice               ' __retval_out IWindowsMediaLibrarySharingDevice **device
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *Count
   ' =====================================================================================
   METHOD GetDevice <2> ( _                             ' VTable offset = 36
     BYVAL DeviceID AS WSTRING _                        ' __in BSTR DeviceID
   ) AS IWindowsMediaLibrarySharingDevice               ' __retval_out IWindowsMediaLibrarySharingDevice **device
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowsMediaLibrarySharingDevices_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWindowsMediaLibrarySharingServices
' IID = {01F5F85E-0A81-40DA-A7C8-21EF3AF8440C}
' Attributes = 4352 [&H1100] [Oleautomation] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWindowsMediaLibrarySharingServices_INTERFACE_DEFINED)
    %IWindowsMediaLibrarySharingServices_INTERFACE_DEFINED = 1

INTERFACE IWindowsMediaLibrarySharingServices $IID_IWindowsMediaLibrarySharingServices

   INHERIT IDispatch

   ' =====================================================================================
   METHOD showShareMediaCPL <1610743808> ( _            ' VTable offset = 28
     BYVAL device AS WSTRING _                          ' __in BSTR device
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET userHomeMediaSharingState <1610743809> ( _  ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *sharingEnabled
   ' =====================================================================================
   PROPERTY SET userHomeMediaSharingState <1610743809> ( _  ' VTable offset = 36
     BYVAL sharingEnabled AS INTEGER _                  ' __in VARIANT_BOOL sharingEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET userHomeMediaSharingLibraryName <1610743811> ( _  ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *libraryName
   ' =====================================================================================
   PROPERTY SET userHomeMediaSharingLibraryName <1610743811> ( _  ' VTable offset = 44
     BYVAL libraryName AS WSTRING _                     ' __in BSTR libraryName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET computerHomeMediaSharingAllowedState <1610743813> ( _  ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *sharingAllowed
   ' =====================================================================================
   PROPERTY SET computerHomeMediaSharingAllowedState <1610743813> ( _  ' VTable offset = 52
     BYVAL sharingAllowed AS INTEGER _                  ' __in VARIANT_BOOL sharingAllowed
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET userInternetMediaSharingState <1610743815> ( _  ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *sharingEnabled
   ' =====================================================================================
   PROPERTY SET userInternetMediaSharingState <1610743815> ( _  ' VTable offset = 60
     BYVAL sharingEnabled AS INTEGER _                  ' __in VARIANT_BOOL sharingEnabled
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET computerInternetMediaSharingAllowedState <1610743817> ( _  ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *sharingAllowed
   ' =====================================================================================
   PROPERTY SET computerInternetMediaSharingAllowedState <1610743817> ( _  ' VTable offset = 68
     BYVAL sharingAllowed AS INTEGER _                  ' __in VARIANT_BOOL sharingAllowed
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET internetMediaSharingSecurityGroup <1610743819> ( _  ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *securityGroup
   ' =====================================================================================
   PROPERTY SET internetMediaSharingSecurityGroup <1610743819> ( _  ' VTable offset = 76
     BYVAL securityGroup AS WSTRING _                   ' __in BSTR securityGroup
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET allowSharingToAllDevices <1610743821> ( _  ' VTable offset = 80
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *sharingEnabled
   ' =====================================================================================
   PROPERTY SET allowSharingToAllDevices <1610743821> ( _  ' VTable offset = 84
     BYVAL sharingEnabled AS INTEGER _                  ' __in VARIANT_BOOL sharingEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD setDefaultAuthorization <1610743823> ( _      ' VTable offset = 88
     BYVAL MACAddresses AS WSTRING _                    ' __in BSTR MACAddresses
   , BYVAL friendlyName AS WSTRING _                    ' __in BSTR friendlyName
   , BYVAL Authorization AS INTEGER _                   ' __in VARIANT_BOOL Authorization
   )                                                    ' void
   ' =====================================================================================
   METHOD setAuthorizationState <1610743824> ( _        ' VTable offset = 92
     BYVAL MACAddress AS WSTRING _                      ' __in BSTR MACAddress
   , BYVAL authorizationState AS INTEGER _              ' __in VARIANT_BOOL authorizationState
   )                                                    ' void
   ' =====================================================================================
   METHOD getAllDevices <1610743825> ( _                ' VTable offset = 96
   ) AS IWindowsMediaLibrarySharingDevices              ' __retval_out IWindowsMediaLibrarySharingDevices **devices
   ' =====================================================================================
   PROPERTY GET customSettingsApplied <1610743826> ( _  ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *customSettingsApplied
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWindowsMediaLibrarySharingServices_INTERFACE_DEFINED__ */
