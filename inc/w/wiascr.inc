' ########################################################################################
' Microsoft Windows
' File: wiascr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WIALib
' Version: 1.0
' Documentation string: Microsoft Windows Image Acquisition 1.01 Type Library
' Path: C:\WINDOWS\system32\wiascr.dll
' Library GUID: {95CEDD63-2E34-4B84-9FB3-F86AF1D4BF7A}
' ########################################################################################

#INCLUDE THIS ONCE
%WIASCR_INC = 1

#INCLUDE ONCE "ole2.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0DAD5531-BF31-43AC-A513-1F8926BBF5EC}
$PROGID_SafeWiaScript1 = "SafeWia.Script.1"
' CLSID = {4EC4272E-2E6F-4EEB-91D0-EBC4D58E8DEE}
$PROGID_WiaScript1 = "Wia.Script.1"
' CLSID = {13F3EA8B-91D7-4F0A-AD76-D2853AC8BECE}
$PROGID_WiaWiaProtocol1 = "Wia.WiaProtocol.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {0DAD5531-BF31-43AC-A513-1F8926BBF5EC}
$PROGID_SafeWiaScript = "SafeWia.Script"
' CLSID = {4EC4272E-2E6F-4EEB-91D0-EBC4D58E8DEE}
$PROGID_WiaScript = "Wia.Script"
' CLSID = {13F3EA8B-91D7-4F0A-AD76-D2853AC8BECE}
$PROGID_WiaWiaProtocol = "Wia.WiaProtocol"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WiaCollection = GUID$("{6E27C0E7-1D45-4CA7-9BF7-BD6CDDAA1ADC}")
$CLSID_WiaDeviceInfo = GUID$("{34E1C006-99D2-4335-B0B1-CE7B9FE5396C}")
$CLSID_WiaDispatchItem = GUID$("{E6C45109-442C-4585-BE44-F5D2884E544A}")
$CLSID_SafeWia = GUID$("{0DAD5531-BF31-43AC-A513-1F8926BBF5EC}")
$CLSID_Wia = GUID$("{4EC4272E-2E6F-4EEB-91D0-EBC4D58E8DEE}")
$CLSID_WiaProtocol = GUID$("{13F3EA8B-91D7-4F0A-AD76-D2853AC8BECE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IWiaCollection = GUID$("{C34C8CE7-B253-4F89-AA25-8A24AD71D0C0}")
$IID_IWia = GUID$("{B10BA1BC-3713-4EC0-8EEA-690EBD2CED8A}")
$IID_IWiaDeviceInfo = GUID$("{5267FF5E-7CAF-4769-865D-17A25968525E}")
$IID_IWiaDispatchItem = GUID$("{D06D503F-4B71-40F3-94A7-66478F732BC9}")
$IID__IWiaEvents = GUID$("{E5F04D72-6C16-42E2-BCCA-F8D0DB4ADE06}")

' ========================================================================================
' WiaIntent enum
' IID: {E9F173A4-EF5C-4553-9F80-87ECFB636D9B}
' WiaIntents
' ========================================================================================

%ImageTypeColor                                         = 1
%ImageTypeGrayscale                                     = 2
%ImageTypeText                                          = 4
%MinimizeSize                                           = &H00010000
%MaximizeQuality                                        = &H00020000
%BestPreview                                            = &H00040000

' ========================================================================================
' WiaFlag enum
' IID: {56385E6A-12C5-419D-8516-062B9613E042}
' WiaFlags
' ========================================================================================

%SingleImage                                            = 2
%UseCommonUI                                            = 4

' ========================================================================================
' WiaDeviceInfoPropertyId enum
' IID: {9EED984D-AAC3-43CB-A993-98403F5ADC55}
' WiaDeviceInfoPropertyIds
' ========================================================================================

%DeviceInfoDevId                                        = 2
%DeviceInfoVendDesc                                     = 3
%DeviceInfoDevDesc                                      = 4
%DeviceInfoDevType                                      = 5
%DeviceInfoPortName                                     = 6
%DeviceInfoDevName                                      = 7
%DeviceInfoServerName                                   = 8
%DeviceInfoRemoteDevId                                  = 9
%DeviceInfoUIClsid                                      = 10
%DeviceInfoHwConfig                                     = 11
%DeviceInfoBaudRate                                     = 12
%DeviceInfoStiGenCapabilities                           = 13
%DeviceInfoWiaVersion                                   = 14
%DeviceInfoDriverVersion                                = 15

' ========================================================================================
' WiaItemPropertyId enum
' IID: {A0115E47-C46A-4C1D-A3B5-5ADB9F2FCD04}
' WiaDeviceItemPropertyIds
' ========================================================================================

%DeviceFirmwareVersion                                  = 1026
%DeviceConnectStatus                                    = 1027
%DeviceDeviceTime                                       = 1028
%CameraDevicePicturesTaken                              = 2050
%CameraDevicePicturesRemaining                          = 2051
%CameraDeviceExposureMode                               = 2052
%CameraDeviceExposureComp                               = 2053
%CameraDeviceExposureTime                               = 2054
%CameraDeviceFNumber                                    = 2055
%CameraDeviceFlashMode                                  = 2056
%CameraDeviceFocusMode                                  = 2057
%CameraDevicePanPosition                                = 2060
%CameraDeviceTiltPosition                               = 2061
%CameraDeviceTimerMode                                  = 2062
%CameraDeviceTimerValue                                 = 2063
%CameraDevicePowerMode                                  = 2064
%CameraDeviceBatteryStatus                              = 2065
%CameraDeviceThumbWidth                                 = 2066
%CameraDeviceThumbHeight                                = 2067
%CameraDevicePictWidth                                  = 2068
%CameraDevicePictHeight                                 = 2069
%CameraDeviceCompressionSetting                         = 2071
%CameraDeviceTimelapseInterval                          = 2073
%CameraDeviceTimelapseNumber                            = 2074
%CameraDeviceBurstInterval                              = 2075
%CameraDeviceBurstNumber                                = 2076
%CameraDeviceEffectMode                                 = 2077
%CameraDeviceDigitalZoom                                = 2078
%CameraDeviceSharpness                                  = 2079
%CameraDeviceContrast                                   = 2080
%CameraDeviceCaptureMode                                = 2081
%CameraDeviceCaptureDelay                               = 2082
%CameraDeviceExposureIndex                              = 2083
%CameraDeviceExposureMeteringMode                       = 2084
%CameraDeviceFocusMeteringMode                          = 2085
%CameraDeviceFocusDistance                              = 2086
%CameraDeviceFocalLength                                = 2087
%CameraDeviceRGBGain                                    = 2088
%CameraDeviceWhiteBalance                               = 2089
%CameraDeviceUploadURL                                  = 2090
%CameraDeviceArtist                                     = 2091
%CameraDeviceCopyrightInfo                              = 2092
%ScannerDeviceHorizontalBedSize                         = 3074
%ScannerDeviceVerticalBedSize                           = 3075
%ScannerDeviceHorizontalSheetFeedSize                   = 3076
%ScannerDeviceVerticalSheetFeedSize                     = 3077
%ScannerDeviceSheetFeederRegistration                   = 3078
%ScannerDeviceHorizontalBedRegistration                 = 3079
%ScannerDeviceVerticalBedRegistration                   = 3080
%ScannerDevicePlatenColor                               = 3081
%ScannerDevicePadColor                                  = 3082
%ScannerDeviceDocumentHandlingCapabilities              = 3086
%ScannerDeviceDocumentHandlingStatus                    = 3087
%ScannerDeviceDocumentHandlingSelect                    = 3088
%ScannerDeviceDocumentHandlingCapacity                  = 3089
%ScannerDeviceOpticalXres                               = 3090
%ScannerDeviceOpticalYres                               = 3091
%ScannerDeviceEndorserCharacters                        = 3092
%ScannerDeviceEndorserString                            = 3093
%ScannerDeviceScanAheadPages                            = 3094
%ScannerDeviceMaxScanTime                               = 3095
%ScannerDevicePages                                     = 3096
%ScannerDevicePageSize                                  = 3097
%ScannerDevicePageWidth                                 = 3098
%ScannerDevicePageHeight                                = 3099
%ScannerDevicePreview                                   = 3100
%ScannerDeviceTransparency                              = 3101
%ScannerDeviceTransparencySelect                        = 3102
%ScannerDeviceShowPreviewControl                        = 3103
%ScannerDeviceMinHorizontalSheetFeedSize                = 3104
%ScannerDeviceMinVerticalSheetFeedSize                  = 3105
%FileDeviceMountPoint                                   = 3330
%VideoDeviceLastPictureTaken                            = 3586
%VideoDeviceImagesDirectory                             = 3587
%VideoDeviceDShowDevicePath                             = 3588
%PictureItemName                                        = 4098
%PictureFullItemName                                    = 4099
%PictureItemTime                                        = 4100
%PictureItemFlags                                       = 4101
%PictureAccessRights                                    = 4102
%PictureDatatype                                        = 4103
%PictureDepth                                           = 4104
%PicturePreferredFormat                                 = 4105
%PictureFormat                                          = 4106
%PictureCompression                                     = 4107
%PictureTymed                                           = 4108
%PictureChannelsPerPixel                                = 4109
%PictureBitsPerChannel                                  = 4110
%PicturePlanar                                          = 4111
%PicturePixelsPerLine                                   = 4112
%PictureBytesPerLine                                    = 4113
%PictureNumberOfLines                                   = 4114
%PictureGammaCurves                                     = 4115
%PictureItemSize                                        = 4116
%PictureColorProfile                                    = 4117
%PictureMinBufferSize                                   = 4118
%PictureBufferSize                                      = 4118
%PictureRegionType                                      = 4119
%PictureIcmProfileName                                  = 4120
%PictureAppColorMapping                                 = 4121
%PicturePropStreamCompatId                              = 4122
%PictureFilenameExtension                               = 4123
%PictureSuppressPropertyPage                            = 4124
%CameraPictureThumbnail                                 = 5122
%CameraPictureThumbWidth                                = 5123
%CameraPictureThumbHeight                               = 5124
%CameraPictureAudioAvailable                            = 5125
%CameraPictureAudioDataFormat                           = 5126
%CameraPictureAudioData                                 = 5127
%CameraPictureNumPictPerRow                             = 5128
%CameraPictureSequence                                  = 5129
%CameraPictureTimedelay                                 = 5130
%ScannerPictureCurIntent                                = 6146
%ScannerPictureXres                                     = 6147
%ScannerPictureYres                                     = 6148
%ScannerPictureXpos                                     = 6149
%ScannerPictureYpos                                     = 6150
%ScannerPictureXextent                                  = 6151
%ScannerPictureYextent                                  = 6152
%ScannerPicturePhotometricInterp                        = 6153
%ScannerPictureBrightness                               = 6154
%ScannerPictureContrast                                 = 6155
%ScannerPictureOrientation                              = 6156
%ScannerPictureRotation                                 = 6157
%ScannerPictureMirror                                   = 6158
%ScannerPictureThreshold                                = 6159
%ScannerPictureInvert                                   = 6160
%ScannerPictureWarmUpTime                               = 6161

' ########################################################################################
' Interface name = ICollection
' IID = {C34C8CE7-B253-4F89-AA25-8A24AD71D0C0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWiaCollection_INTERFACE_DEFINED)
    %IWiaCollection_INTERFACE_DEFINED = 1

INTERFACE IWiaCollection $IID_IWiaCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS IDispatch                                       ' __retval_out IDispatch** ppDispItem
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long* pCount
   ' =====================================================================================
   PROPERTY GET Length <2> ( _                          ' VTable offset = 36
   ) AS DWORD                                           ' __retval_out unsigned long* plLength
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown** ppEnum
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWiaDispatchItem
' IID = {D06D503F-4B71-40F3-94A7-66478F732BC9}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWiaDispatchItem_INTERFACE_DEFINED)
    %IWiaDispatchItem_INTERFACE_DEFINED = 1

INTERFACE IWiaDispatchItem $IID_IWiaDispatchItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ConnectStatus <1> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrStatus
   ' =====================================================================================
   PROPERTY GET Time <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrTime
   ' =====================================================================================
   PROPERTY GET FirmwareVersion <3> ( _                 ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrVersion
   ' =====================================================================================
   METHOD GetItemsFromUI <4> ( _                        ' VTable offset = 40
     OPTIONAL BYVAL Flags AS LONG _                     ' __opt_in WiaFlag Flags = 0
   , OPTIONAL BYVAL Intent AS LONG _                    ' __opt_in WiaIntent Intent = 0
   ) AS IWiaCollection                                  ' __retval_out ICollection** ppCollection
   ' =====================================================================================
   METHOD Transfer <5> ( _                              ' VTable offset = 44
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   , OPTIONAL BYVAL AsyncTransfer AS INTEGER _          ' __opt_in VARIANT_BOOL AsyncTransfer = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD TakePicture <6> ( _                           ' VTable offset = 48
   ) AS IWiaDispatchItem                                ' __retval_out IWiaDispatchItem** ppDispItem
   ' =====================================================================================
   PROPERTY GET Name <20> ( _                           ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY GET FullName <21> ( _                       ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrFullName
   ' =====================================================================================
   PROPERTY GET ItemType <22> ( _                       ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrType
   ' =====================================================================================
   PROPERTY GET Width <23> ( _                          ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long* plWidth
   ' =====================================================================================
   PROPERTY GET Height <24> ( _                         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long* plHeight
   ' =====================================================================================
   PROPERTY GET ThumbWidth <50> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long* plWidth
   ' =====================================================================================
   PROPERTY GET ThumbHeight <51> ( _                    ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long* plHeight
   ' =====================================================================================
   PROPERTY GET Thumbnail <52> ( _                      ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPath
   ' =====================================================================================
   PROPERTY GET PictureHeight <53> ( _                  ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long* plHeight
   ' =====================================================================================
   PROPERTY GET PictureWidth <54> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long* plWidth
   ' =====================================================================================
   PROPERTY GET Children <500> ( _                      ' VTable offset = 92
   ) AS IWiaCollection                                  ' __retval_out ICollection** ppCollection
   ' =====================================================================================
   METHOD GetPropById <1000> ( _                        ' VTable offset = 96
     BYVAL Id AS LONG _                                 ' __in WiaItemPropertyId Id
   ) AS VARIANT                                         ' __retval_out VARIANT* pvaOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDispatchItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWiaDeviceInfo
' IID = {5267FF5E-7CAF-4769-865D-17A25968525E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWiaDeviceInfo_INTERFACE_DEFINED)
    %IWiaDeviceInfo_INTERFACE_DEFINED = 1

INTERFACE IWiaDeviceInfo $IID_IWiaDeviceInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Create <1> ( _                                ' VTable offset = 28
   ) AS IWiaDispatchItem                                ' __retval_out IWiaDispatchItem** ppDevice
   ' =====================================================================================
   PROPERTY GET Id <2> ( _                              ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrDeviceId
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   PROPERTY GET Type <4> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrType
   ' =====================================================================================
   PROPERTY GET Port <5> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrPort
   ' =====================================================================================
   PROPERTY GET UIClsid <6> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrGuidUI
   ' =====================================================================================
   PROPERTY GET Manufacturer <7> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrVendor
   ' =====================================================================================
   METHOD GetPropById <1000> ( _                        ' VTable offset = 56
     BYVAL Id AS LONG _                                 ' __in WiaDeviceInfoPropertyId Id
   ) AS VARIANT                                         ' __retval_out VARIANT* pvaOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWiaDeviceInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWia
' IID = {B10BA1BC-3713-4EC0-8EEA-690EBD2CED8A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWia_INTERFACE_DEFINED)
    %IWia_INTERFACE_DEFINED = 1

INTERFACE IWia $IID_IWia

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Devices <1> ( _                         ' VTable offset = 28
   ) AS IWiaCollection                                  ' __retval_out ICollection** ppCol
   ' =====================================================================================
   METHOD Create <2> ( _                                ' VTable offset = 32
     BYREF Device AS VARIANT _                          ' __in VARIANT* Device
   ) AS IWiaDispatchItem                                ' __retval_out IWiaDispatchItem** ppDevice
   ' =====================================================================================
   METHOD DebugDialog_ <10010> ( _                      ' VTable offset = 36
     BYVAL fWait AS LONG _                              ' __in long fWait
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWia_INTERFACE_DEFINED__ */
