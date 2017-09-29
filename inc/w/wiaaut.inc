' ########################################################################################
' Microsoft Windows
' File: wiaaut.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WIA
' Version: 1.0, Locale ID = 0
' Description: Microsoft Windows Image Acquisition Library v2.0
' Path: C:\Windows\System32\wiaaut.dll
' Library GUID: {94A0E92D-43C0-494E-AC29-FD45948A5221}
' Help file: C:\Windows\System32\wiaaut.chm
' ########################################################################################

#INCLUDE THIS ONCE
%WIAAUT_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {850D1D11-70F3-4BE5-9A11-77AA6B2BB201}
$PROGID_WIA_CommonDialog1 = "WIA.CommonDialog.1"
' CLSID = {E1C5D730-7E97-4D8A-9E42-BBAE87C2059F}
$PROGID_WIA_DeviceManager1 = "WIA.DeviceManager.1"
' CLSID = {A2E6DDA0-06EF-4DF3-B7BD-5AA224BB06E8}
$PROGID_WIA_ImageFile1 = "WIA.ImageFile.1"
' CLSID = {BD0D38E4-74C8-4904-9B5A-269F8E9994E9}
$PROGID_WIA_ImageProcess1 = "WIA.ImageProcess.1"
' CLSID = {0C5672F9-3EDC-4B24-95B5-A6C54C0B79AD}
$PROGID_WIA_Rational1 = "WIA.Rational.1"
' CLSID = {4DD1D1C3-B36A-4EB4-AAEF-815891A58A30}
$PROGID_WIA_Vector1 = "WIA.Vector.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {850D1D11-70F3-4BE5-9A11-77AA6B2BB201}
$PROGID_WIA_CommonDialog = "WIA.CommonDialog"
' CLSID = {E1C5D730-7E97-4D8A-9E42-BBAE87C2059F}
$PROGID_WIA_DeviceManager = "WIA.DeviceManager"
' CLSID = {A2E6DDA0-06EF-4DF3-B7BD-5AA224BB06E8}
$PROGID_WIA_ImageFile = "WIA.ImageFile"
' CLSID = {BD0D38E4-74C8-4904-9B5A-269F8E9994E9}
$PROGID_WIA_ImageProcess = "WIA.ImageProcess"
' CLSID = {0C5672F9-3EDC-4B24-95B5-A6C54C0B79AD}
$PROGID_WIA_Rational = "WIA.Rational"
' CLSID = {4DD1D1C3-B36A-4EB4-AAEF-815891A58A30}
$PROGID_WIA_Vector = "WIA.Vector"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_WIA_Device = GUID$("{DBAA8843-B1C4-4EDC-B7E0-D6F61162BE58}")
$CLSID_WIA_DeviceCommand = GUID$("{72226184-AFBB-4059-BF55-0F6C076E669D}")
$CLSID_WIA_DeviceCommands = GUID$("{25B047DB-4AAD-4FC2-A0BE-31DDA687FF32}")
$CLSID_WIA_DeviceEvent = GUID$("{617CF892-783C-43D3-B04B-F0F1DE3B326D}")
$CLSID_WIA_DeviceEvents = GUID$("{3563A59A-BBCD-4C86-94A0-92136C80A8B4}")
$CLSID_WIA_DeviceInfo = GUID$("{F09CFB7A-E561-4625-9BB5-208BCA0DE09F}")
$CLSID_WIA_DeviceInfos = GUID$("{2DFEE16B-E4AC-4A19-B660-AE71A745D34F}")
$CLSID_WIA_Filter = GUID$("{52AD8A74-F064-4F4C-8544-FF494D349F7B}")
$CLSID_WIA_FilterInfo = GUID$("{318D6B52-9B1C-4E3B-8D90-1F0E857FA9B0}")
$CLSID_WIA_FilterInfos = GUID$("{56FA88D3-F3DA-4DE3-94E8-811040C3CCD4}")
$CLSID_WIA_Filters = GUID$("{31CDD60C-C04C-424D-95FC-36A52646D71C}")
$CLSID_WIA_Formats = GUID$("{6F62E261-0FE6-476B-A244-50CF7440DDEB}")
$CLSID_WIA_Item = GUID$("{36F479F3-C258-426E-B5FA-2793DCFDA881}")
$CLSID_WIA_Items = GUID$("{B243B765-CA9C-4F30-A457-C8B2B57A585E}")
$CLSID_WIA_Properties = GUID$("{96F887FC-08B1-4F97-A69C-75280C6A9CF8}")
$CLSID_WIA_Property = GUID$("{2014DE3F-3723-4178-8643-3317A32D4A2B}")
$CLSID_WIA_CommonDialog = GUID$("{850D1D11-70F3-4BE5-9A11-77AA6B2BB201}")
$CLSID_WIA_DeviceManager = GUID$("{E1C5D730-7E97-4D8A-9E42-BBAE87C2059F}")
$CLSID_WIA_ImageFile = GUID$("{A2E6DDA0-06EF-4DF3-B7BD-5AA224BB06E8}")
$CLSID_WIA_ImageProcess = GUID$("{BD0D38E4-74C8-4904-9B5A-269F8E9994E9}")
$CLSID_WIA_Rational = GUID$("{0C5672F9-3EDC-4B24-95B5-A6C54C0B79AD}")
$CLSID_WIA_Vector = GUID$("{4DD1D1C3-B36A-4EB4-AAEF-815891A58A30}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_WIA_ICommonDialog = GUID$("{B4760F13-D9F3-4DF8-94B5-D225F86EE9A1}")
$IID_WIA_IDevice = GUID$("{3714EAC4-F413-426B-B1E8-DEF2BE99EA55}")
$IID_WIA_IDeviceCommand = GUID$("{7CF694C0-F589-451C-B56E-398B5855B05E}")
$IID_WIA_IDeviceCommands = GUID$("{C53AE9D5-6D91-4815-AF93-5F1E1B3B08BD}")
$IID_WIA_IDeviceEvent = GUID$("{80D0880A-BB10-4722-82D1-07DC8DA157E2}")
$IID_WIA_IDeviceEvents = GUID$("{03985C95-581B-44D1-9403-8488B347538B}")
$IID_WIA_IDeviceInfo = GUID$("{2A99020A-E325-4454-95E0-136726ED4818}")
$IID_WIA_IDeviceInfos = GUID$("{FE076B64-8406-4E92-9CAC-9093F378E05F}")
$IID_WIA_IDeviceManager = GUID$("{73856D9A-2720-487A-A584-21D5774E9D0F}")
$IID_WIA_IFilter = GUID$("{851E9802-B338-4AB3-BB6B-6AA57CC699D0}")
$IID_WIA_IFilterInfo = GUID$("{EFD1219F-8229-4B30-809D-8F6D83341569}")
$IID_WIA_IFilterInfos = GUID$("{AF49723A-499C-411C-B19A-1B8244D67E44}")
$IID_WIA_IFilters = GUID$("{C82FFED4-0A8D-4F85-B90A-AC8E720D39C1}")
$IID_WIA_IFormats = GUID$("{882A274F-DF2F-4F6D-9F5A-AF4FD484530D}")
$IID_WIA_IImageFile = GUID$("{F4243B65-3F63-4D99-93CD-86B6D62C5EB2}")
$IID_WIA_IImageProcess = GUID$("{41506929-7855-4392-9E6F-98D88513E55D}")
$IID_WIA_IItem = GUID$("{68F2BF12-A755-4E2B-9BCD-37A22587D078}")
$IID_WIA_IItems = GUID$("{46102071-60B4-4E58-8620-397D17B0BB5B}")
$IID_WIA_IProperties = GUID$("{40571E58-A308-470A-80AA-FA10F88793A0}")
$IID_WIA_IProperty = GUID$("{706038DC-9F4B-4E45-88E2-5EB7D665B815}")
$IID_WIA_IRational = GUID$("{3BF1B24A-01A5-4AA3-91F9-25A60B50E49B}")
$IID_WIA_IVector = GUID$("{696F2367-6619-49BD-BA96-904DC2609990}")
$IID__WIA_IDeviceManagerEvents = GUID$("{2E9A5206-2360-49DF-9D9B-1762B4BEAE77}")

' ========================================================================================
' WiaSubType enum
' IID: {A5EDDA89-E79A-44A7-BBE1-42397D62FE79}
' The WiaSubType enumeration specifies more detail about the property value. Use the SubType property on the Property object to obtain these values for the property.
' ========================================================================================

%WIA_UnspecifiedSubType                                     = 0            ' &H0
%WIA_RangeSubType                                           = 1            ' &H1
%WIA_ListSubType                                            = 2            ' &H2
%WIA_FlagSubType                                            = 3            ' &H3

' ========================================================================================
' WiaDeviceType enum
' IID: {E1FCB780-C848-4076-9637-7609156F47A2}
' The WiaDeviceType enumeration specifies the type of device attached to a user's computer. Use the Type property on the DeviceInfo object or the Device object to obtain these values from the device.
' ========================================================================================

%WIA_UnspecifiedDeviceType                                  = 0            ' &H0
%WIA_ScannerDeviceType                                      = 1            ' &H1
%WIA_CameraDeviceType                                       = 2            ' &H2
%WIA_VideoDeviceType                                        = 3            ' &H3

' ========================================================================================
' WiaItemFlag enum
' IID: {7F17D8AE-01D7-4C01-B341-096607BE3ECF}
' An Item's type is composed of bits from the WiaItemFlags enumeration. You can test an Item's type by using the AND operation with Item.Properties("Item Flags") and a member from the WiaItemFlags enumeration.
' ========================================================================================

%WIA_FreeItemFlag                                           = 0            ' &H0
%WIA_ImageItemFlag                                          = 1            ' &H1
%WIA_FileItemFlag                                           = 2            ' &H2
%WIA_FolderItemFlag                                         = 4            ' &H4
%WIA_RootItemFlag                                           = 8            ' &H8
%WIA_AnalyzeItemFlag                                        = 16           ' &H10
%WIA_AudioItemFlag                                          = 32           ' &H20
%WIA_DeviceItemFlag                                         = 64           ' &H40
%WIA_DeletedItemFlag                                        = 128          ' &H80
%WIA_DisconnectedItemFlag                                   = 256          ' &H100
%WIA_HPanoramaItemFlag                                      = 512          ' &H200
%WIA_VPanoramaItemFlag                                      = 1024         ' &H400
%WIA_BurstItemFlag                                          = 2048         ' &H800
%WIA_StorageItemFlag                                        = 4096         ' &H1000
%WIA_TransferItemFlag                                       = 8192         ' &H2000
%WIA_GeneratedItemFlag                                      = 16384        ' &H4000
%WIA_HasAttachmentsItemFlag                                 = 32768        ' &H8000
%WIA_VideoItemFlag                                          = 65536        ' &H10000
%WIA_RemovedItemFlag                                        = -2147483648  ' &H80000000

' ========================================================================================
' WiaPropertyType enum
' IID: {652C190A-EEFA-4B91-B0FF-632139BE9BBA}
' The WiaPropertyType enumeration specifies the type of the value of an item property. Item properties can be found in the Properties collection of a Device or Item object.
' ========================================================================================

%WIA_UnsupportedPropertyType                                = 0            ' &H0
%WIA_BooleanPropertyType                                    = 1            ' &H1
%WIA_BytePropertyType                                       = 2            ' &H2
%WIA_IntegerPropertyType                                    = 3            ' &H3
%WIA_UnsignedIntegerPropertyType                            = 4            ' &H4
%WIA_LongPropertyType                                       = 5            ' &H5
%WIA_UnsignedLongPropertyType                               = 6            ' &H6
%WIA_ErrorCodePropertyType                                  = 7            ' &H7
%WIA_LargeIntegerPropertyType                               = 8            ' &H8
%WIA_UnsignedLargeIntegerPropertyType                       = 9            ' &H9
%WIA_SinglePropertyType                                     = 10           ' &HA
%WIA_DoublePropertyType                                     = 11           ' &HB
%WIA_CurrencyPropertyType                                   = 12           ' &HC
%WIA_DatePropertyType                                       = 13           ' &HD
%WIA_FileTimePropertyType                                   = 14           ' &HE
%WIA_ClassIDPropertyType                                    = 15           ' &HF
%WIA_StringPropertyType                                     = 16           ' &H10
%WIA_ObjectPropertyType                                     = 17           ' &H11
%WIA_HandlePropertyType                                     = 18           ' &H12
%WIA_VariantPropertyType                                    = 19           ' &H13
%WIA_VectorOfBooleansPropertyType                           = 101          ' &H65
%WIA_VectorOfBytesPropertyType                              = 102          ' &H66
%WIA_VectorOfIntegersPropertyType                           = 103          ' &H67
%WIA_VectorOfUnsignedIntegersPropertyType                   = 104          ' &H68
%WIA_VectorOfLongsPropertyType                              = 105          ' &H69
%WIA_VectorOfUnsignedLongsPropertyType                      = 106          ' &H6A
%WIA_VectorOfErrorCodesPropertyType                         = 107          ' &H6B
%WIA_VectorOfLargeIntegersPropertyType                      = 108          ' &H6C
%WIA_VectorOfUnsignedLargeIntegersPropertyType              = 109          ' &H6D
%WIA_VectorOfSinglesPropertyType                            = 110          ' &H6E
%WIA_VectorOfDoublesPropertyType                            = 111          ' &H6F
%WIA_VectorOfCurrenciesPropertyType                         = 112          ' &H70
%WIA_VectorOfDatesPropertyType                              = 113          ' &H71
%WIA_VectorOfFileTimesPropertyType                          = 114          ' &H72
%WIA_VectorOfClassIDsPropertyType                           = 115          ' &H73
%WIA_VectorOfStringsPropertyType                            = 116          ' &H74
%WIA_VectorOfVariantsPropertyType                           = 119          ' &H77

' ========================================================================================
' WiaImagePropertyType enum
' IID: {9E6A0011-6F26-4904-BF25-0D6760DBFB58}
' The WiaImagePropertyType enumeration specifies the type of the value of an image property. Image properties can be found in the Properties collection of an ImageFile object.
' ========================================================================================

%WIA_UndefinedImagePropertyType                             = 1000         ' &H3E8
%WIA_ByteImagePropertyType                                  = 1001         ' &H3E9
%WIA_StringImagePropertyType                                = 1002         ' &H3EA
%WIA_UnsignedIntegerImagePropertyType                       = 1003         ' &H3EB
%WIA_LongImagePropertyType                                  = 1004         ' &H3EC
%WIA_UnsignedLongImagePropertyType                          = 1005         ' &H3ED
%WIA_RationalImagePropertyType                              = 1006         ' &H3EE
%WIA_UnsignedRationalImagePropertyType                      = 1007         ' &H3EF
%WIA_VectorOfUndefinedImagePropertyType                     = 1100         ' &H44C
%WIA_VectorOfBytesImagePropertyType                         = 1101         ' &H44D
%WIA_VectorOfUnsignedIntegersImagePropertyType              = 1102         ' &H44E
%WIA_VectorOfLongsImagePropertyType                         = 1103         ' &H44F
%WIA_VectorOfUnsignedLongsImagePropertyType                 = 1104         ' &H450
%WIA_VectorOfRationalsImagePropertyType                     = 1105         ' &H451
%WIA_VectorOfUnsignedRationalsImagePropertyType             = 1106         ' &H452

' ========================================================================================
' WiaEventFlag enum
' IID: {D346BBB7-9EDC-4FC9-AB79-A65E2F204ED3}
' A DeviceEvent's type is composed of bits from the WiaEventFlags enumeration. You can test a DeviceEvent's type by using the AND operation with DeviceEvent.Type and a member from the WiaEventFlags enumeration.
' ========================================================================================

%WIA_NotificationEvent                                      = 1            ' &H1
%WIA_ActionEvent                                            = 2            ' &H2

' ========================================================================================
' WiaImageIntent enum
' IID: {6165F914-C665-442C-B90B-D73DE216BE77}
' The WiaImageIntent enumeration helps specify what type of data the image is intended to represent.
' ========================================================================================

%WIA_UnspecifiedIntent                                      = 0            ' &H0
%WIA_ColorIntent                                            = 1            ' &H1
%WIA_GrayscaleIntent                                        = 2            ' &H2
%WIA_TextIntent                                             = 4            ' &H4

' ========================================================================================
' WiaImageBias enum
' IID: {19E509B8-519E-48DE-90DC-D732144F7B9A}
' The WiaImageBias enumeration helps specify what type of data the image is intended to represent.
' ========================================================================================

%WIA_MinimizeSize                                           = 65536        ' &H10000
%WIA_MaximizeQuality                                        = 131072       ' &H20000

' ########################################################################################
' Interface name = IRational
' IID = {3BF1B24A-01A5-4AA3-91F9-25A60B50E49B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IRational_INTERFACE_DEFINED)
    %WIA_IRational_INTERFACE_DEFINED = 1

INTERFACE WIA_IRational $IID_WIA_IRational

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out double *pResult
   ' =====================================================================================
   PROPERTY GET Numerator <1> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY SET Numerator <1> ( _                       ' VTable offset = 36
     BYVAL plResult AS LONG _                           ' __in long plResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Denominator <2> ( _                     ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY SET Denominator <2> ( _                     ' VTable offset = 44
     BYVAL plResult AS LONG _                           ' __in long plResult
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IRational_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImageFile
' IID = {F4243B65-3F63-4D99-93CD-86B6D62C5EB2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IImageFile_INTERFACE_DEFINED)
    %WIA_IImageFile_INTERFACE_DEFINED = 1

INTERFACE WIA_IImageFile $IID_WIA_IImageFile

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FormatID <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET FileExtension <2> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET FileData <3> ( _                        ' VTable offset = 36
   ) AS WIA_IVector                                     ' __retval_out IVector **ppResult
   ' =====================================================================================
   PROPERTY GET ARGBData <4> ( _                        ' VTable offset = 40
   ) AS WIA_IVector                                     ' __retval_out IVector **ppResult
   ' =====================================================================================
   PROPERTY GET Height <5> ( _                          ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET Width <6> ( _                           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET HorizontalResolution <7> ( _            ' VTable offset = 52
   ) AS DOUBLE                                          ' __retval_out double *plfResult
   ' =====================================================================================
   PROPERTY GET VerticalResolution <8> ( _              ' VTable offset = 56
   ) AS DOUBLE                                          ' __retval_out double *plfResult
   ' =====================================================================================
   PROPERTY GET PixelDepth <9> ( _                      ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET IsIndexedPixelFormat <10> ( _           ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET IsAlphaPixelFormat <11> ( _             ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET IsExtendedPixelFormat <12> ( _          ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET IsAnimated <13> ( _                     ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET FrameCount <14> ( _                     ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET ActiveFrame <15> ( _                    ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY SET ActiveFrame <15> ( _                    ' VTable offset = 88
     BYVAL plResult AS LONG _                           ' __in long plResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <16> ( _                     ' VTable offset = 92
   ) AS WIA_IProperties                                 ' __retval_out IProperties **ppResult
   ' =====================================================================================
   METHOD LoadFile <17> ( _                             ' VTable offset = 96
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveFile <18> ( _                             ' VTable offset = 100
     BYVAL Filename AS WSTRING _                        ' __in BSTR Filename
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IImageFile_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVector
' IID = {696F2367-6619-49BD-BA96-904DC2609990}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IVector_INTERFACE_DEFINED)
    %WIA_IVector_INTERFACE_DEFINED = 1

INTERFACE WIA_IVector $IID_WIA_IVector

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pResult
   ' =====================================================================================
   PROPERTY SET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   , BYREF IN VARIANT _                                 ' __in VARIANT *pResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Item <0> ( _                     ' VTable offset = 36
     BYVAL Index AS LONG _                              ' __in long Index
   , BYREF IN VARIANT _                                 ' __in VARIANT *pResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET Picture <2> ( _                         ' VTable offset = 44
     OPTIONAL BYVAL Width AS LONG _                     ' __opt_in long Width = 0
   , OPTIONAL BYVAL Height AS LONG _                    ' __opt_in long Height = 0
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   PROPERTY GET ImageFile <3> ( _                       ' VTable offset = 48
     OPTIONAL BYVAL Width AS LONG _                     ' __opt_in long Width = 0
   , OPTIONAL BYVAL Height AS LONG _                    ' __opt_in long Height = 0
   ) AS WIA_IImageFile                                  ' __retval_out IImageFile **ppResult
   ' =====================================================================================
   PROPERTY GET BinaryData <4> ( _                      ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   PROPERTY SET BinaryData <4> ( _                      ' VTable offset = 56
     BYREF IN pvResult AS VARIANT _                     ' __in VARIANT *pvResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET String <5> ( _                          ' VTable offset = 60
     OPTIONAL BYVAL Unicode AS INTEGER _                ' __opt_in VARIANT_BOOL Unicode = -1
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Date <6> ( _                            ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE *pdResult
   ' =====================================================================================
   PROPERTY SET Date <6> ( _                            ' VTable offset = 68
     BYVAL pdResult AS DOUBLE _                         ' __in DATE pdResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 72
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================
   METHOD Add <7> ( _                                   ' VTable offset = 76
     BYREF Value AS VARIANT _                           ' __in VARIANT *Value
   , OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <8> ( _                                ' VTable offset = 80
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   METHOD Clear <9> ( _                                 ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD SetFromString <10> ( _                        ' VTable offset = 88
     BYVAL Value AS WSTRING _                           ' __in BSTR Value
   , OPTIONAL BYVAL Resizable AS INTEGER _              ' __opt_in VARIANT_BOOL Resizable -1
   , OPTIONAL BYVAL Unicode AS INTEGER _                ' __opt_in VARIANT_BOOL Unicode -1
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IVector_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProperties
' IID = {40571E58-A308-470A-80AA-FA10F88793A0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IProperties_INTERFACE_DEFINED)
    %WIA_IProperties_INTERFACE_DEFINED = 1

INTERFACE WIA_IProperties $IID_WIA_IProperties

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN VARIANT _                                 ' __in VARIANT *Index
   ) AS WIA_IProperty                                   ' __retval_out IProperty **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   METHOD Exists <2> ( _                                ' VTable offset = 36
     BYREF VARIANT _                                    ' __in VARIANT *Index
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IProperty
' IID = {706038DC-9F4B-4E45-88E2-5EB7D665B815}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IProperty_INTERFACE_DEFINED)
    %WIA_IProperty_INTERFACE_DEFINED = 1

INTERFACE WIA_IProperty $IID_WIA_IProperty

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Value <0> ( _                           ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   PROPERTY SET Value <0> ( _                           ' VTable offset = 32
     BYREF IN pvResult AS VARIANT _                     ' __in VARIANT *pvResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_Value <0> ( _                    ' VTable offset = 36
     BYREF IN pvResult AS VARIANT _                     ' __in VARIANT *pvResult
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET PropertyID <2> ( _                      ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET Type <3> ( _                            ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET IsReadOnly <4> ( _                      ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET IsVector <5> ( _                        ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pboolResult
   ' =====================================================================================
   PROPERTY GET SubType <6> ( _                         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out WiaSubType *pResult
   ' =====================================================================================
   PROPERTY GET SubTypeDefault <7> ( _                  ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   PROPERTY GET SubTypeValues <8> ( _                   ' VTable offset = 68
   ) AS WIA_IVector                                     ' __retval_out IVector **ppResult
   ' =====================================================================================
   PROPERTY GET SubTypeMin <9> ( _                      ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET SubTypeMax <10> ( _                     ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================
   PROPERTY GET SubTypeStep <11> ( _                    ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *plResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IProperty_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFilterInfo
' IID = {EFD1219F-8229-4B30-809D-8F6D83341569}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IFilterInfo_INTERFACE_DEFINED)
    %WIA_IFilterInfo_INTERFACE_DEFINED = 1

INTERFACE WIA_IFilterInfo $IID_WIA_IFilterInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET FilterID <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IFilterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFilterInfos
' IID = {AF49723A-499C-411C-B19A-1B8244D67E44}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IFilterInfos_INTERFACE_DEFINED)
    %WIA_IFilterInfos_INTERFACE_DEFINED = 1

INTERFACE WIA_IFilterInfos $IID_WIA_IFilterInfos

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS WIA_IFilterInfo                                 ' __retval_out IFilterInfo **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IFilterInfos_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFilter
' IID = {851E9802-B338-4AB3-BB6B-6AA57CC699D0}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IFilter_INTERFACE_DEFINED)
    %WIA_IFilter_INTERFACE_DEFINED = 1

INTERFACE WIA_IFilter $IID_WIA_IFilter

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Description <2> ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET FilterID <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Properties <4> ( _                      ' VTable offset = 40
   ) AS WIA_IProperties                                 ' __retval_out IProperties **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IFilter_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFilters
' IID = {C82FFED4-0A8D-4F85-B90A-AC8E720D39C1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFilters_INTERFACE_DEFINED)
    %IFilters_INTERFACE_DEFINED = 1

INTERFACE WIA_IFilters $IID_WIA_IFilters

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WIA_IFilter                                     ' __retval_out IFilter **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL FilterID AS WSTRING _                        ' __in BSTR FilterID
   , OPTIONAL BYVAL Index AS LONG _                     ' __opt_in long Index = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IFilters_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IImageProcess
' IID = {41506929-7855-4392-9E6F-98D88513E55D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IImageProcess_INTERFACE_DEFINED)
    %WIA_IImageProcess_INTERFACE_DEFINED = 1

INTERFACE WIA_IImageProcess $IID_WIA_IImageProcess

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FilterInfos <1> ( _                     ' VTable offset = 28
   ) AS WIA_IFilterInfos                                ' __retval_out IFilterInfos **ppResult
   ' =====================================================================================
   PROPERTY GET Filters <2> ( _                         ' VTable offset = 32
   ) AS WIA_IFilters                                    ' __retval_out IFilters **ppResult
   ' =====================================================================================
   METHOD Apply <4> ( _                                 ' VTable offset = 36
     BYVAL Source AS WIA_IImageFile _                   ' __in IImageFile *Source
   ) AS WIA_IImageFile                                  ' __retval_out IImageFile **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IImageProcess_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFormats
' IID = {882A274F-DF2F-4F6D-9F5A-AF4FD484530D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IFormats_INTERFACE_DEFINED)
    %WIA_IFormats_INTERFACE_DEFINED = 1

INTERFACE WIA_IFormats $IID_WIA_IFormats

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IFormats_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceCommand
' IID = {7CF694C0-F589-451C-B56E-398B5855B05E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceCommand_INTERFACE_DEFINED)
    %WIA_IDeviceCommand_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceCommand $IID_WIA_IDeviceCommand

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CommandID <1> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Name <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Description <3> ( _                     ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceCommand_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceCommands
' IID = {C53AE9D5-6D91-4815-AF93-5F1E1B3B08BD}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceCommands_INTERFACE_DEFINED)
    %WIA_IDeviceCommands_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceCommands $IID_WIA_IDeviceCommands

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WIA_IDeviceCommand                              ' __retval_out IDeviceCommand **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceCommands_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IItems
' IID = {46102071-60B4-4E58-8620-397D17B0BB5B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IItems_INTERFACE_DEFINED)
    %WIA_IItems_INTERFACE_DEFINED = 1

INTERFACE WIA_IItems $IID_WIA_IItems

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WIA_IItem                                       ' __retval_out IItem **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 40
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Flags AS LONG _                              ' __in long Flags
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <3> ( _                                ' VTable offset = 44
     BYVAL Index AS LONG _                              ' __in long Index
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IItems_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IItem
' IID = {68F2BF12-A755-4E2B-9BCD-37A22587D078}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IItem_INTERFACE_DEFINED)
    %WIA_IItem_INTERFACE_DEFINED = 1

INTERFACE WIA_IItem $IID_WIA_IItem

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ItemID <1> ( _                          ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Properties <2> ( _                      ' VTable offset = 32
   ) AS WIA_IProperties                                 ' __retval_out IProperties **ppResult
   ' =====================================================================================
   PROPERTY GET Items <3> ( _                           ' VTable offset = 36
   ) AS WIA_IItems                                      ' __retval_out IItems **ppResult
   ' =====================================================================================
   PROPERTY GET Formats <4> ( _                         ' VTable offset = 40
   ) AS WIA_IFormats                                    ' __retval_out IFormats **ppResult
   ' =====================================================================================
   PROPERTY GET Commands <5> ( _                        ' VTable offset = 44
   ) AS WIA_IDeviceCommands                             ' __retval_out IDeviceCommands **ppResult
   ' =====================================================================================
   PROPERTY GET WiaItem <6> ( _                         ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================
   METHOD Transfer <7> ( _                              ' VTable offset = 52
     OPTIONAL BYVAL FormatID AS WSTRING _               ' __opt_in BSTR FormatID = "{00000000-0000-0000-0000-000000000000}"
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   METHOD ExecuteCommand <8> ( _                        ' VTable offset = 56
     BYVAL CommandID AS WSTRING _                       ' __in BSTR CommandID
   ) AS WIA_IItem                                       ' __retval_out IItem **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceEvent
' IID = {80D0880A-BB10-4722-82D1-07DC8DA157E2}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceEvent_INTERFACE_DEFINED)
    %WIA_IDeviceEvent_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceEvent $IID_WIA_IDeviceEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET EventID <1> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out WiaEventFlag *pResult
   ' =====================================================================================
   PROPERTY GET Name <3> ( _                            ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Description <4> ( _                     ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceEvents
' IID = {03985C95-581B-44D1-9403-8488B347538B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceEvents_INTERFACE_DEFINED)
    %WIA_IDeviceEvents_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceEvents $IID_WIA_IDeviceEvents

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS WIA_IDeviceEvent                                ' __retval_out IDeviceEvent **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDevice
' IID = {3714EAC4-F413-426B-B1E8-DEF2BE99EA55}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDevice_INTERFACE_DEFINED)
    %WIA_IDevice_INTERFACE_DEFINED = 1

INTERFACE WIA_IDevice $IID_WIA_IDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceID <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out WiaDeviceType *pResult
   ' =====================================================================================
   PROPERTY GET Properties <3> ( _                      ' VTable offset = 36
   ) AS WIA_IProperties                                 ' __retval_out IProperties **ppResult
   ' =====================================================================================
   PROPERTY GET Items <4> ( _                           ' VTable offset = 40
   ) AS WIA_IItems                                      ' __retval_out IItems **ppResult
   ' =====================================================================================
   PROPERTY GET Commands <5> ( _                        ' VTable offset = 44
   ) AS WIA_IDeviceCommands                             ' __retval_out IDeviceCommands **ppResult
   ' =====================================================================================
   PROPERTY GET Events <6> ( _                          ' VTable offset = 48
   ) AS WIA_IDeviceEvents                               ' __retval_out IDeviceEvents **ppResult
   ' =====================================================================================
   PROPERTY GET WiaItem <7> ( _                         ' VTable offset = 52
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================
   METHOD GetItem <8> ( _                               ' VTable offset = 56
     BYVAL ItemID AS WSTRING _                          ' __in BSTR ItemID
   ) AS WIA_IItem                                       ' __retval_out IItem **ppResult
   ' =====================================================================================
   METHOD ExecuteCommand <9> ( _                        ' VTable offset = 60
     BYVAL CommandID AS WSTRING _                       ' __in BSTR CommandID
   ) AS WIA_IItem                                       ' __retval_out IItem **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDevice_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceInfo
' IID = {2A99020A-E325-4454-95E0-136726ED4818}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceInfo_INTERFACE_DEFINED)
    %WIA_IDeviceInfo_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceInfo $IID_WIA_IDeviceInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceID <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrResult
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out WiaDeviceType *pResult
   ' =====================================================================================
   PROPERTY GET Properties <3> ( _                      ' VTable offset = 36
   ) AS WIA_IProperties                                 ' __retval_out IProperties **ppResult
   ' =====================================================================================
   METHOD Connect <4> ( _                               ' VTable offset = 40
   ) AS WIA_IDevice                                     ' __retval_out IDevice **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceInfos
' IID = {FE076B64-8406-4E92-9CAC-9093F378E05F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceInfos_INTERFACE_DEFINED)
    %WIA_IDeviceInfos_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceInfos $IID_WIA_IDeviceInfos

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYREF IN Index AS VARIANT _                        ' __in VARIANT *Index
   ) AS WIA_IDeviceInfo                                 ' __retval_out IDeviceInfo **ppResult
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pResult
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppResult
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceInfos_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICommonDialog
' IID = {B4760F13-D9F3-4DF8-94B5-D225F86EE9A1}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_ICommonDialog_INTERFACE_DEFINED)
    %WIA_ICommonDialog_INTERFACE_DEFINED = 1

INTERFACE WIA_ICommonDialog $IID_WIA_ICommonDialog

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ShowAcquisitionWizard <1> ( _                 ' VTable offset = 28
     BYVAL Device AS WIA_IDevice _                      ' __in IDevice *Device
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   METHOD ShowAcquireImage <2> ( _                      ' VTable offset = 32
     OPTIONAL BYVAL DeviceType AS LONG _                ' __opt_in WiaDeviceType DeviceType = 0
   , OPTIONAL BYVAL Intent AS LONG _                    ' __opt_in WiaImageIntent Intent = 0
   , OPTIONAL BYVAL Bias AS LONG _                      ' __opt_in WiaImageBias Bias = 131072
   , OPTIONAL BYVAL FormatID AS WSTRING _               ' __opt_in BSTR FormatID = "{00000000-0000-0000-0000-000000000000}"
   , OPTIONAL BYVAL AlwaysSelectDevice AS INTEGER _     ' __opt_in VARIANT_BOOL AlwaysSelectDevice = 0
   , OPTIONAL BYVAL UseCommonUI AS INTEGER _            ' __opt_in VARIANT_BOOL UseCommonUI = -1
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   ) AS WIA_IImageFile                                  ' __retval_out IImageFile **ppResult
   ' =====================================================================================
   METHOD ShowSelectDevice <3> ( _                      ' VTable offset = 36
     OPTIONAL BYVAL DeviceType AS LONG _                ' __opt_in WiaDeviceType DeviceType = 0
   , OPTIONAL BYVAL AlwaysSelectDevice AS INTEGER _     ' __opt_in VARIANT_BOOL AlwaysSelectDevice = 0
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   ) AS WIA_IDevice                                     ' __retval_out IDevice **ppResult
   ' =====================================================================================
   METHOD ShowSelectItems <4> ( _                       ' VTable offset = 40
     BYVAL Device AS WIA_IDevice _                      ' __in IDevice *Device
   , OPTIONAL BYVAL Intent AS LONG _                    ' __opt_in WiaImageIntent Intent = 0
   , OPTIONAL BYVAL Bias AS LONG _                      ' __opt_in WiaImageBias Bias = 131072
   , OPTIONAL BYVAL SingleSelect AS INTEGER _           ' __opt_in VARIANT_BOOL SingleSelect = -1
   , OPTIONAL BYVAL UseCommonUI AS INTEGER _            ' __opt_in VARIANT_BOOL UseCommonUI = -1
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   ) AS WIA_IItems                                      ' __retval_out IItems **ppResult
   ' =====================================================================================
   METHOD ShowDeviceProperties <5> ( _                  ' VTable offset = 44
     BYVAL Device AS WIA_IDevice _                      ' __in IDevice *Device
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowItemProperties <6> ( _                    ' VTable offset = 48
     BYVAL Item AS WIA_IItem _                          ' __in IItem *Item
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowTransfer <7> ( _                          ' VTable offset = 52
     BYVAL Item AS WIA_IItem _                          ' __in IItem *Item
   , OPTIONAL BYVAL FormatID AS WSTRING _               ' __opt_in BSTR FormatID = "{00000000-0000-0000-0000-000000000000}"
   , OPTIONAL BYVAL CancelError AS INTEGER _            ' __opt_in VARIANT_BOOL CancelError = 0
   ) AS VARIANT                                         ' __retval_out VARIANT *pvResult
   ' =====================================================================================
   METHOD ShowPhotoPrintingWizard <8> ( _               ' VTable offset = 56
     BYREF Files AS VARIANT _                           ' __in VARIANT *Files
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_ICommonDialog_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeviceManager
' IID = {73856D9A-2720-487A-A584-21D5774E9D0F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%WIA_IDeviceManager_INTERFACE_DEFINED)
    %WIA_IDeviceManager_INTERFACE_DEFINED = 1

INTERFACE WIA_IDeviceManager $IID_WIA_IDeviceManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceInfos <1> ( _                     ' VTable offset = 28
   ) AS WIA_IDeviceInfos                                ' __retval_out IDeviceInfos **ppResult
   ' =====================================================================================
   METHOD RegisterEvent <2> ( _                         ' VTable offset = 32
     BYVAL EventID AS WSTRING _                         ' __in BSTR EventID
   , OPTIONAL BYVAL DeviceID AS WSTRING _               ' __opt_in BSTR DeviceID = "*"
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterEvent <3> ( _                       ' VTable offset = 36
     BYVAL EventID AS WSTRING _                         ' __in BSTR EventID
   , OPTIONAL BYVAL DeviceID AS WSTRING _               ' __opt_in BSTR DeviceID
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterPersistentEvent <4> ( _               ' VTable offset = 40
     BYVAL Command AS WSTRING _                         ' __in BSTR Command
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL Icon AS WSTRING _                            ' __in BSTR Icon
   , BYVAL EventID AS WSTRING _                         ' __in BSTR EventID
   , OPTIONAL BYVAL DeviceID AS WSTRING _               ' __opt_in BSTR DeviceID = "*"
   )                                                    ' void
   ' =====================================================================================
   METHOD UnregisterPersistentEvent <5> ( _             ' VTable offset = 44
     BYVAL Command AS WSTRING _                         ' __in BSTR Command
   , BYVAL Name AS WSTRING _                            ' __in BSTR Name
   , BYVAL Description AS WSTRING _                     ' __in BSTR Description
   , BYVAL Icon AS WSTRING _                            ' __in BSTR Icon
   , BYVAL EventID AS WSTRING _                         ' __in BSTR EventID
   , OPTIONAL BYVAL DeviceID AS WSTRING _               ' __opt_in BSTR DeviceID = "*"
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __WIA_IDeviceManager_INTERFACE_DEFINED__ */
