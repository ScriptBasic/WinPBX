' ########################################################################################
' Microsoft Windows
' File: WinCodec.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINCODEC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "ocidl.inc"

'#include <intsafe.h>

%WINCODEC_SDK_VERSION = &H0236

$CLSID_WICImagingFactory           = GUID$("{CACAF262-9370-4615-A13B-9F5539DA4C0A}")
$GUID_VendorMicrosoft              = GUID$("{F0E749CA-EDEF-4589-A73A-EE0E626A2A2B}")
$GUID_VendorMicrosoftBuiltIn       = GUID$("{257A30FD-06B6-462B-AEA4-63F70B86E533}")
$CLSID_WICBmpDecoder               = GUID$("{6B462062-7CBF-400D-9FDB-813DD10F2778}")
$CLSID_WICPngDecoder               = GUID$("{389EA17B-5078-4CDE-B6EF-25C15175C751}")
$CLSID_WICIcoDecoder               = GUID$("{C61BFCDF-2E0F-4AAD-A8D7-E06BAFEBCDFE}")
$CLSID_WICJpegDecoder              = GUID$("{9456A480-E88B-43EA-9E73-0B2D9B71B1CA}")
$CLSID_WICGifDecoder               = GUID$("{381DDA3C-9CE9-4834-A23E-1F98F8FC52BE}")
$CLSID_WICTiffDecoder              = GUID$("{B54E85D9-FE23-499F-8B88-6ACEA713752B}")
$CLSID_WICWmpDecoder               = GUID$("{A26CEC36-234C-4950-AE16-E34AACE71D0D}")
$CLSID_WICBmpEncoder               = GUID$("{69BE8BB4-D66D-47C8-865A-ED1589433782}")
$CLSID_WICPngEncoder               = GUID$("{27949969-876A-41D7-9447-568F6A35A4DC}")
$CLSID_WICJpegEncoder              = GUID$("{1A34F5C1-4A5A-46DC-B644-1F4567E7A676}")
$CLSID_WICGifEncoder               = GUID$("{114F5598-0B22-40A0-86A1-C83EA495ADBD}")
$CLSID_WICTiffEncoder              = GUID$("{0131BE10-2001-4C5F-A9B0-CC88FAB64CE8}")
$CLSID_WICWmpEncoder               = GUID$("{AC4CE3CB-E1C1-44CD-8215-5A1665509EC2}")
$GUID_ContainerFormatBmp           = GUID$("{0AF1D87E-FCFE-4188-BDEB-A7906471CBE3}")
$GUID_ContainerFormatPng           = GUID$("{1B7CFAF4-713F-473C-BBCD-6137425FAEAF}")
$GUID_ContainerFormatIco           = GUID$("{A3A860C4-338F-4C17-919A-FBA4B5628F21}")
$GUID_ContainerFormatJpeg          = GUID$("{19E4A5AA-5662-4FC5-A0C0-1758028E1057}")
$GUID_ContainerFormatTiff          = GUID$("{163BCC30-E2E9-4F0B-961D-A3E9FDB788A3}")
$GUID_ContainerFormatGif           = GUID$("{1F8A5601-7D4D-4CBD-9C82-1BC8D4EEB9A5}")
$GUID_ContainerFormatWmp           = GUID$("{57A37CAA-367A-4540-916B-F183C5093A4B}")
$CLSID_WICImagingCategories        = GUID$("{FAE3D380-FEA4-4623-8C75-C6B61110B681}")
$CATID_WICBitmapDecoders           = GUID$("{7ED96837-96F0-4812-B211-F13C24117ED3}")
$CATID_WICBitmapEncoders           = GUID$("{AC757296-3522-4E11-9862-C17BE5A1767E}")
$CATID_WICPixelFormats             = GUID$("{2B46E70F-CDA7-473E-89F6-DC9630A2390B}")
$CATID_WICFormatConverters         = GUID$("{7835EAE8-BF14-49D1-93CE-533A407B2248}")
$CATID_WICMetadataReader           = GUID$("{05AF94D8-7174-4CD2-BE4A-4124B80EE4B8}")
$CATID_WICMetadataWriter           = GUID$("{ABE3B9A4-257D-4B97-BD1A-294AF496222E}")
$CLSID_WICDefaultFormatConverter   = GUID$("{1A3F11DC-B514-4B17-8C5F-2154513852F1}")
$CLSID_WICFormatConverterHighColor = GUID$("{AC75D454-9F37-48F8-B972-4E19BC856011}")
$CLSID_WICFormatConverterNChannel  = GUID$("{C17CABB2-D4A3-47D7-A557-339B2EFBD4F1}")
$CLSID_WICFormatConverterWMPhoto   = GUID$("{9CB5172B-D600-46BA-AB77-77BB7E3A00D9}")

'typedef UINT32 WICColor;

' // Size = 16 bytes
TYPE WICRect DWORD
   X      AS LONG   ' INT X
   Y      AS LONG   ' INT Y
   Width  AS LONG   ' INT Width
   Height AS LONG   ' INT Height
END TYPE

'typedef BYTE* WICInProcPointer;

' enum WICColorContextType
%WICColorContextUninitialized  = 0???
%WICColorContextProfile        = &H1???
%WICColorContextExifColorSpace = &H2???

'typedef /* [public] */ REFGUID REFWICPixelFormatGUID;

'typedef /* [public] */ GUID WICPixelFormatGUID;

$GUID_WICPixelFormatDontCare             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc900}")
$GUID_WICPixelFormatUndefined            = $GUID_WICPixelFormatDontCare
$GUID_WICPixelFormat1bppIndexed          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc901}")
$GUID_WICPixelFormat2bppIndexed          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc902}")
$GUID_WICPixelFormat4bppIndexed          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc903}")
$GUID_WICPixelFormat8bppIndexed          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc904}")
$GUID_WICPixelFormatBlackWhite           = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc905}")
$GUID_WICPixelFormat2bppGray             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc906}")
$GUID_WICPixelFormat4bppGray             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc907}")
$GUID_WICPixelFormat8bppGray             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc908}")
$GUID_WICPixelFormat8bppAlpha            = GUID$("{e6cd0116-eeba-4161-aa85-27dd-9fb3a895}")
$GUID_WICPixelFormat16bppBGR555          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc909}")
$GUID_WICPixelFormat16bppBGR565          = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90a}")
$GUID_WICPixelFormat16bppBGRA5551        = GUID$("{05ec7c2b-f1e6-4961-ad46-e1cc-810a87d2}")
$GUID_WICPixelFormat16bppGray            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90b}")
$GUID_WICPixelFormat24bppBGR             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90c}")
$GUID_WICPixelFormat24bppRGB             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90d}")
$GUID_WICPixelFormat32bppBGR             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90e}")
$GUID_WICPixelFormat32bppBGRA            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc90f}")
$GUID_WICPixelFormat32bppPBGRA           = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc910}")
$GUID_WICPixelFormat32bppGrayFloat       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc911}")
$GUID_WICPixelFormat32bppRGBA            = GUID$("{f5c7ad2d-6a8d-43dd-a7a8-a299-35261ae9}")
$GUID_WICPixelFormat32bppPRGBA           = GUID$("{3cc4a650-a527-4d37-a916-3142-c7ebedba}")
$GUID_WICPixelFormat48bppRGB             = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc915}")
$GUID_WICPixelFormat48bppBGR             = GUID$("{e605a384-b468-46ce-bb2e-36f1-80e64313}")
$GUID_WICPixelFormat64bppRGBA            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc916}")
$GUID_WICPixelFormat64bppBGRA            = GUID$("{1562ff7c-d352-46f9-979e-4297-6b792246}")
$GUID_WICPixelFormat64bppPRGBA           = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc917}")
$GUID_WICPixelFormat64bppPBGRA           = GUID$("{8c518e8e-a4ec-468b-ae70-c9a3-5a9c5530}")
$GUID_WICPixelFormat16bppGrayFixedPoint  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc913}")
$GUID_WICPixelFormat32bppBGR101010       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc914}")
$GUID_WICPixelFormat48bppRGBFixedPoint   = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc912}")
$GUID_WICPixelFormat48bppBGRFixedPoint   = GUID$("{49ca140e-cab6-493b-9ddf-6018-7c37532a}")
$GUID_WICPixelFormat96bppRGBFixedPoint   = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc918}")
$GUID_WICPixelFormat128bppRGBAFloat      = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc919}")
$GUID_WICPixelFormat128bppPRGBAFloat     = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91a}")
$GUID_WICPixelFormat128bppRGBFloat       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91b}")
$GUID_WICPixelFormat32bppCMYK            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91c}")
$GUID_WICPixelFormat64bppRGBAFixedPoint  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91d}")
$GUID_WICPixelFormat64bppBGRAFixedPoint  = GUID$("{356de33c-54d2-4a23-bb04-9b7b-f9b1d42d}")
$GUID_WICPixelFormat64bppRGBFixedPoint   = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc940}")
$GUID_WICPixelFormat128bppRGBAFixedPoint = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91e}")
$GUID_WICPixelFormat128bppRGBFixedPoint  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc941}")
$GUID_WICPixelFormat64bppRGBAHalf        = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc93a}")
$GUID_WICPixelFormat64bppRGBHalf         = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc942}")
$GUID_WICPixelFormat48bppRGBHalf         = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc93b}")
$GUID_WICPixelFormat32bppRGBE            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc93d}")
$GUID_WICPixelFormat16bppGrayHalf        = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc93e}")
$GUID_WICPixelFormat32bppGrayFixedPoint  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc93f}")
$GUID_WICPixelFormat32bppRGBA1010102     = GUID$("{25238D72-FCF9-4522-b514-5578-e5ad55e0}")
$GUID_WICPixelFormat32bppRGBA1010102XR   = GUID$("{00DE6B9A-C101-434b-b502-d016-5ee1122c}")
$GUID_WICPixelFormat64bppCMYK            = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc91f}")
$GUID_WICPixelFormat24bpp3Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc920}")
$GUID_WICPixelFormat32bpp4Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc921}")
$GUID_WICPixelFormat40bpp5Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc922}")
$GUID_WICPixelFormat48bpp6Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc923}")
$GUID_WICPixelFormat56bpp7Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc924}")
$GUID_WICPixelFormat64bpp8Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc925}")
$GUID_WICPixelFormat48bpp3Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc926}")
$GUID_WICPixelFormat64bpp4Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc927}")
$GUID_WICPixelFormat80bpp5Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc928}")
$GUID_WICPixelFormat96bpp6Channels       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc929}")
$GUID_WICPixelFormat112bpp7Channels      = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92a}")
$GUID_WICPixelFormat128bpp8Channels      = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92b}")
$GUID_WICPixelFormat40bppCMYKAlpha       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92c}")
$GUID_WICPixelFormat80bppCMYKAlpha       = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92d}")
$GUID_WICPixelFormat32bpp3ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92e}")
$GUID_WICPixelFormat40bpp4ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc92f}")
$GUID_WICPixelFormat48bpp5ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc930}")
$GUID_WICPixelFormat56bpp6ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc931}")
$GUID_WICPixelFormat64bpp7ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc932}")
$GUID_WICPixelFormat72bpp8ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc933}")
$GUID_WICPixelFormat64bpp3ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc934}")
$GUID_WICPixelFormat80bpp4ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc935}")
$GUID_WICPixelFormat96bpp5ChannelsAlpha  = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc936}")
$GUID_WICPixelFormat112bpp6ChannelsAlpha = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc937}")
$GUID_WICPixelFormat128bpp7ChannelsAlpha = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc938}")
$GUID_WICPixelFormat144bpp8ChannelsAlpha = GUID$("{6fddc324-4e03-4bfe-b185-3d77-768dc939}")

' enum WICBitmapCreateCacheOption
%WICBitmapNoCache       = 0???
%WICBitmapCacheOnDemand = &H1???
%WICBitmapCacheOnLoad   = &H2???
%WICBITMAPCREATECACHEOPTION_FORCE_DWORD = &H7fffffff???

' enum WICDecodeOptions
%WICDecodeMetadataCacheOnDemand = 0???
%WICDecodeMetadataCacheOnLoad   = &H1???
%WICMETADATACACHEOPTION_FORCE_DWORD = &H7fffffff???

' enum WICBitmapEncoderCacheOption
%WICBitmapEncoderCacheInMemory = 0???
%WICBitmapEncoderCacheTempFile = &H1???
%WICBitmapEncoderNoCache       = &H2???
%WICBITMAPENCODERCACHEOPTION_FORCE_DWORD = &H7fffffff???

'enum WICComponentType
%WICDecoder              = &H1???
%WICEncoder              = &H2???
%WICPixelFormatConverter = &H4???
%WICMetadataReader       = &H8???
%WICMetadataWriter       = &H10???
%WICPixelFormat          = &H20???
%WICAllComponents        = &H3f???
%WICCOMPONENTTYPE_FORCE_DWORD = &H7fffffff???

'enum WICComponentEnumerateOptions
%WICComponentEnumerateDefault     = 0???
%WICComponentEnumerateRefresh     = &H1???
%WICComponentEnumerateDisabled    = &H80000000???
%WICComponentEnumerateUnsigned    = &H40000000???
%WICComponentEnumerateBuiltInOnly = &H20000000???
%WICCOMPONENTENUMERATEOPTIONS_FORCE_DWORD = &H7fffffff???

' // Size = 24 bytes
TYPE WICBitmapPattern QWORD FILL
   Position    AS QUAD       ' ULARGE_INTEGER
   Length      AS DWORD      ' ULONG
   Pattern     AS BYTE PTR   ' BYTE *
   Mask        AS BYTE PTR   ' BYTE *
   EndOfStream AS LONG       ' BOOL
END TYPE

'enum WICBitmapInterpolationMode
%WICBitmapInterpolationModeNearestNeighbor = 0???
%WICBitmapInterpolationModeLinear          = &H1???
%WICBitmapInterpolationModeCubic           = &H2???
%WICBitmapInterpolationModeFant            = &H3???
%WICBITMAPINTERPOLATIONMODE_FORCE_DWORD = &H7fffffff???

'enum WICBitmapPaletteType
%WICBitmapPaletteTypeCustom           = 0???
%WICBitmapPaletteTypeMedianCut        = &H1???
%WICBitmapPaletteTypeFixedBW          = &H2???
%WICBitmapPaletteTypeFixedHalftone8   = &H3???
%WICBitmapPaletteTypeFixedHalftone27  = &H4???
%WICBitmapPaletteTypeFixedHalftone64  = &H5???
%WICBitmapPaletteTypeFixedHalftone125 = &H6???
%WICBitmapPaletteTypeFixedHalftone216 = &H7???
%WICBitmapPaletteTypeFixedWebPalette  = %WICBitmapPaletteTypeFixedHalftone216
%WICBitmapPaletteTypeFixedHalftone252 = &H8???
%WICBitmapPaletteTypeFixedHalftone256 = &H9???
%WICBitmapPaletteTypeFixedGray4       = &Ha???
%WICBitmapPaletteTypeFixedGray16      = &Hb???
%WICBitmapPaletteTypeFixedGray256     = &Hc???
%WICBitmapPALETTETYPE_FORCE_DWORD     = &H7fffffff???

'enum WICBitmapDitherType
%WICBitmapDitherTypeNone           = 0???
%WICBitmapDitherTypeSolid          = 0???
%WICBitmapDitherTypeOrdered4x4     = &H1???
%WICBitmapDitherTypeOrdered8x8     = &H2???
%WICBitmapDitherTypeOrdered16x16   = &H3???
%WICBitmapDitherTypeSpiral4x4      = &H4???
%WICBitmapDitherTypeSpiral8x8      = &H5???
%WICBitmapDitherTypeDualSpiral4x4  = &H6???
%WICBitmapDitherTypeDualSpiral8x8  = &H7???
%WICBitmapDitherTypeErrorDiffusion = &H8???
%WICBitmapDITHERTYPE_FORCE_DWORD   = &H7fffffff???

'enum WICBitmapAlphaChannelOption
%WICBitmapUseAlpha              = 0???
%WICBitmapUsePremultipliedAlpha = &H1???
%WICBitmapIgnoreAlpha           = &H2???
%WICBITMAPALPHACHANNELOPTIONS_FORCE_DWORD   = &H7fffffff???

'enum WICBitmapTransformOptions
%WICBitmapTransformRotate0        = 0???
%WICBitmapTransformRotate90       = &H1???
%WICBitmapTransformRotate180      = &H2???
%WICBitmapTransformRotate270      = &H3???
%WICBitmapTransformFlipHorizontal = &H8???
%WICBitmapTransformFlipVertical   = &H10???
%WICBitmapTRANSFORMOPTIONS_FORCE_DWORD = &H7fffffff???

'enum WICBitmapLockFlags
%WICBitmapLockRead  = &H1???
%WICBitmapLockWrite = &H2???
%WICBITMAPLOCKFLAGS_FORCE_DWORD = &H7fffffff???

' enum WICBitmapDecoderCapabilities
%WICBitmapDecoderCapabilitySameEncoder          = &H1???
%WICBitmapDecoderCapabilityCanDecodeAllImages   = &H2???
%WICBitmapDecoderCapabilityCanDecodeSomeImages  = &H4???
%WICBitmapDecoderCapabilityCanEnumerateMetadata = &H8???
%WICBitmapDecoderCapabilityCanDecodeThumbnail   = &H10???
%WICBitmapDECODERCAPABILITIES_FORCE_DWORD       = &H7fffffff???

'enum WICProgressOperation
%WICProgressOperationCopyPixels   = &H1???
%WICProgressOperationWritePixels  = &H2???
%WICProgressOperationAll          = &Hffff???
%WICPROGRESSOPERATION_FORCE_DWORD = &H7fffffff???

'enum WICProgressNotification
%WICProgressNotificationBegin        = &H10000???
%WICProgressNotificationEnd          = &H20000???
%WICProgressNotificationFrequent     = &H40000???
%WICProgressNotificationAll          = &Hffff0000???
%WICPROGRESSNOTIFICATION_FORCE_DWORD = &H7fffffff???

'enum WICComponentSigning
%WICComponentSigned              = &H1???
%WICComponentUnsigned            = &H2???
%WICComponentSafe                = &H4???
%WICComponentDisabled            = &H80000000???
%WICCOMPONENTSIGNING_FORCE_DWORD = &H7fffffff???

' enum WICGifLogicalScreenDescriptorProperties
%WICGifLogicalScreenSignature                      = &H1???
%WICGifLogicalScreenDescriptorWidth                = &H2???
%WICGifLogicalScreenDescriptorHeight               = &H3???
%WICGifLogicalScreenDescriptorGlobalColorTableFlag = &H4???
%WICGifLogicalScreenDescriptorColorResolution      = &H5???
%WICGifLogicalScreenDescriptorSortFlag             = &H6???
%WICGifLogicalScreenDescriptorGlobalColorTableSize = &H7???
%WICGifLogicalScreenDescriptorBackgroundColorIndex = &H8???
%WICGifLogicalScreenDescriptorPixelAspectRatio     = &H9???
%WICGifLogicalScreenDescriptorProperties_FORCE_DWORD   = &H7fffffff???

' enum WICGifImageDescriptorProperties
%WICGifImageDescriptorLeft                = &H1???
%WICGifImageDescriptorTop                 = &H2???
%WICGifImageDescriptorWidth               = &H3???
%WICGifImageDescriptorHeight              = &H4???
%WICGifImageDescriptorLocalColorTableFlag = &H5???
%WICGifImageDescriptorInterlaceFlag       = &H6???
%WICGifImageDescriptorSortFlag            = &H7???
%WICGifImageDescriptorLocalColorTableSize = &H8???
%WICGifImageDescriptorProperties_FORCE_DWORD = &H7fffffff???

' enum WICGifGraphicControlExtensionProperties
%WICGifGraphicControlExtensionDisposal              = &H1???
%WICGifGraphicControlExtensionUserInputFlag         = &H2???
%WICGifGraphicControlExtensionTransparencyFlag      = &H3???
%WICGifGraphicControlExtensionDelay                 = &H4???
%WICGifGraphicControlExtensionTransparentColorIndex = &H5???
%WICGifGraphicControlExtensionProperties_FORCE_DWORD = &H7fffffff???

' enum WICGifApplicationExtensionProperties
%WICGifApplicationExtensionApplication   = &H1???
%WICGifApplicationExtensionData          = &H2???
%WICGifApplicationExtensionProperties_FORCE_DWORD   = &H7fffffff???

' enum WICGifCommentExtensionProperties
%WICGifCommentExtensionText = &H1???
%WICGifCommentExtensionProperties_FORCE_DWORD = &H7fffffff???

' enum WICJpegCommentProperties
%WICJpegCommentText = &H1???
%WICJpegCommentProperties_FORCE_DWORD = &H7fffffff???

' enum WICJpegLuminanceProperties
%WICJpegLuminanceTable = &H1???
%WICJpegLuminanceProperties_FORCE_DWORD = &H7fffffff???

' enum WICJpegChrominanceProperties
%WICJpegChrominanceTable = &H1???
%WICJpegChrominanceProperties_FORCE_DWORD = &H7fffffff???

' enum WIC8BIMIptcProperties
%WIC8BIMIptcPString      = 0???
%WIC8BIMIptcEmbeddedIPTC = &H1???
%WIC8BIMIptcProperties_FORCE_DWORD = &H7fffffff???

' enum WIC8BIMResolutionInfoProperties
%WIC8BIMResolutionInfoPString         = &H1???
%WIC8BIMResolutionInfoHResolution     = &H2???
%WIC8BIMResolutionInfoHResolutionUnit = &H3???
%WIC8BIMResolutionInfoWidthUnit       = &H4???
%WIC8BIMResolutionInfoVResolution     = &H5???
%WIC8BIMResolutionInfoVResolutionUnit = &H6???
%WIC8BIMResolutionInfoHeightUnit      = &H7???
%WIC8BIMResolutionInfoProperties_FORCE_DWORD = &H7fffffff???

' enum WIC8BIMIptcDigestProperties
%WIC8BIMIptcDigestPString    = &H1???
%WIC8BIMIptcDigestIptcDigest = &H2???
%WIC8BIMIptcDigestProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngGamaProperties
%WICPngGamaGamma = &H1???
%WICPngGamaProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngBkgdProperties
%WICPngBkgdBackgroundColor = &H1???
%WICPngBkgdProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngItxtProperties
%WICPngItxtKeyword           = &H1???
%WICPngItxtCompressionFlag   = &H2???
%WICPngItxtLanguageTag       = &H3???
%WICPngItxtTranslatedKeyword = &H4???
%WICPngItxtText              = &H5???
%WICPngItxtProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngChrmProperties
%WICPngChrmWhitePointX = &H1???
%WICPngChrmWhitePointY = &H2???
%WICPngChrmRedX        = &H3???
%WICPngChrmRedY        = &H4???
%WICPngChrmGreenX      = &H5???
%WICPngChrmGreenY      = &H6???
%WICPngChrmBlueX       = &H7???
%WICPngChrmBlueY       = &H8???
%WICPngChrmProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngHistProperties
%WICPngHistFrequencies = &H1???
%WICPngHistProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngIccpProperties
%WICPngIccpProfileName = &H1???
%WICPngIccpProfileData = &H2???
%WICPngIccpProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngSrgbProperties
%WICPngSrgbRenderingIntent = &H1???
%WICPngSrgbProperties_FORCE_DWORD = &H7fffffff???

' enum WICPngTimeProperties
%WICPngTimeYear   = &H1???
%WICPngTimeMonth  = &H2???
%WICPngTimeDay    = &H3???
%WICPngTimeHour   = &H4???
%WICPngTimeMinute = &H5???
%WICPngTimeSecond = &H6???
%WICPngTimeProperties_FORCE_DWORD = &H7fffffff???

' enum WICSectionAccessLevel
%WICSectionAccessLevelRead      = &H1???
%WICSectionAccessLevelReadWrite = &H3???
%WICSectionAccessLevel_FORCE_DWORD = &H7fffffff???

' enum WICPixelFormatNumericRepresentation
%WICPixelFormatNumericRepresentationUnspecified     = 0???
%WICPixelFormatNumericRepresentationIndexed         = &H1???
%WICPixelFormatNumericRepresentationUnsignedInteger = &H2???
%WICPixelFormatNumericRepresentationSignedInteger   = &H3???
%WICPixelFormatNumericRepresentationFixed           = &H4???
%WICPixelFormatNumericRepresentationFloat           = &H5???
%WICPixelFormatNumericRepresentation_FORCE_DWORD = &H7fffffff???

' ########################################################################################
' IWICPalette interface
' IID = 00000040-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICPalette_INTERFACE_DEFINED)
    %IWICPalette_INTERFACE_DEFINED = 1

$IID_IWICPalette = GUID$("{00000040-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICPalette $IID_IWICPalette

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializePredefined ( _                      ' VTable offset = 12
     BYVAL ePaletteType AS DWORD _                      ' __in WICBitmapPaletteType ePaletteType
   , BYVAL fAddTransparentColor AS LONG _               ' __in BOOL fAddTransparentColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeCustom ( _                          ' VTable offset = 16
     BYREF pColors AS DWORD _                           ' __in WICColor *pColors
   , BYVAL cCount AS DWORD _                            ' __in UINT cCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromBitmap ( _                      ' VTable offset = 20
     BYVAL pISurface AS IWICBitmapSource _              ' __in IWICBitmapSource *pISurface
   , BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYVAL fAddTransparentColor AS LONG _               ' __in BOOL fAddTransparentColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromPalette ( _                     ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 28
     BYREF pePaletteType AS DWORD _                     ' __out WICBitmapPaletteType *pePaletteType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorCount ( _                             ' VTable offset = 32
     BYREF pcCount AS DWORD _                           ' __out UINT *pcCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColors ( _                                 ' VTable offset = 36
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF pColors AS DWORD _                           ' __out WICColor *pColors
   , BYREF pcActualColors AS DWORD _                    ' __out UINT *pcActualColors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsBlackWhite ( _                              ' VTable offset = 40
     BYREF pfIsBlackWhite AS LONG _                     ' __out BOOL *pfIsBlackWhite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsGrayscale ( _                               ' VTable offset = 44
     BYREF pfIsGrayscale AS LONG _                      ' __out BOOL *pfIsGrayscale
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasAlpha ( _                                  ' VTable offset = 48
     BYREF pfHasAlpha AS LONG _                         ' __out BOOL *pfHasAlpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICPalette_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapSource interface
' IID = 00000120-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapSource_INTERFACE_DEFINED)
    %IWICBitmapSource_INTERFACE_DEFINED = 1

$IID_IWICBitmapSource = GUID$("{00000120-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmapSource $IID_IWICBitmapSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapSource_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICFormatConverter interface
' IID = 00000301-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICFormatConverter_INTERFACE_DEFINED)
    %IWICFormatConverter_INTERFACE_DEFINED = 1

$IID_IWICFormatConverter = GUID$("{00000301-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICFormatConverter $IID_IWICFormatConverter

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICFormatConverter Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 32
     BYVAL pISource AS IWICBitmapSource _               ' __in IWICBitmapSource *pISource
   , BYREF dstFormat AS GUID _                          ' __in REFWICPixelFormatGUID dstFormat
   , BYVAL dither AS DWORD _                            ' __in WICBitmapDitherType dither
   , BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   , BYVAL alphaThresholdPercent AS DOUBLE _            ' __in double alphaThresholdPercent
   , BYVAL paletteTranslate AS DWORD _                  ' __in WICBitmapPaletteType paletteTranslate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanConvert ( _                                ' VTable offset = 36
     BYREF srcPixelFormat AS GUID _                     ' __in REFWICPixelFormatGUID srcPixelFormat
   , BYREF dstPixelFormat AS GUID _                     ' __in REFWICPixelFormatGUID dstPixelFormat
   , BYREF pfCanConvert AS LONG _                       ' __out BOOL *pfCanConvert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICFormatConverter_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapScaler interface
' IID = 00000302-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICBitmapScaler_INTERFACE_DEFINED)
    %IWICBitmapScaler_INTERFACE_DEFINED = 1

$IID_IWICBitmapScaler = GUID$("{00000302-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmapScaler $IID_IWICBitmapScaler

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapScaler Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 32
     BYVAL pISource AS IWICBitmapSource _               ' __in IWICBitmapSource *pISource
   , BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYVAL mode AS DWORD _                              ' __in WICBitmapInterpolationMode mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapScaler_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapClipper interface
' IID = E4FBCF03-223D-4E81-9333-D635556DD1B5
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICBitmapClipper_INTERFACE_DEFINED)
    %IWICBitmapClipper_INTERFACE_DEFINED = 1

$IID_IWICBitmapClipper = GUID$("{E4FBCF03-223D-4E81-9333-D635556DD1B5}")

INTERFACE IWICBitmapClipper $IID_IWICBitmapClipper

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapClipper Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 32
     BYVAL pISource AS IWICBitmapSource _               ' __in IWICBitmapSource *pISource
   , BYREF prc AS WICRect _                             ' __in const WICRect *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapClipper_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapFlipRotator interface
' IID = 5009834F-2D6A-41CE-9E1B-17C5AFF7A782
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICBitmapFlipRotator_INTERFACE_DEFINED)
    %IWICBitmapFlipRotator_INTERFACE_DEFINED = 1

$IID_IWICBitmapFlipRotator = GUID$("{5009834F-2D6A-41CE-9E1B-17C5AFF7A782}")

INTERFACE IWICBitmapFlipRotator $IID_IWICBitmapFlipRotator

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapFlipRotator Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 32
     BYVAL pISource AS IWICBitmapSource _               ' __in IWICBitmapSource *pISource
   , BYVAL options AS DWORD _                           ' __in WICBitmapTransformOptions options
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapFlipRotator_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapLock interface
' IID = 00000123-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapLock_INTERFACE_DEFINED)
    %IWICBitmapLock_INTERFACE_DEFINED = 1

$IID_IWICBitmapLock = GUID$("{00000123-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmapLock $IID_IWICBitmapLock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStride ( _                                 ' VTable offset = 16
     BYREF pcbStride AS DWORD _                         ' __out UINT *pcbStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataPointer ( _                            ' VTable offset = 20
     BYREF pcbBufferSize AS DWORD _                     ' __out UINT *pcbBufferSize
   , BYVAL ppbData AS BYTE PTR _                        ' __out BYTE **ppbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 24
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapLock_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmap interface
' IID = 00000121-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICBitmap_INTERFACE_DEFINED)
    %IWICBitmap_INTERFACE_DEFINED = 1

$IID_IWICBitmap = GUID$("{00000121-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmap $IID_IWICBitmap

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmap Methods
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 32
     BYREF prcLock AS WICRect _                         ' __in const WICRect *prcLock
   , BYVAL flags AS DWORD _                             ' __in DWORD flags
   , BYREF ppILock AS IWICBitmapLock _                  ' __out IWICBitmapLock **ppILock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 36
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetResolution ( _                             ' VTable offset = 40
     BYVAL dpiX AS DOUBLE _                             ' __in double dpiX
   , BYVAL dpiY AS DOUBLE _                             ' __in double dpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmap_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICColorContext interface
' IID = 3C613A02-34B2-44EA-9A7C-45AEA9C6FD6D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICColorContext_INTERFACE_DEFINED)
    %IWICColorContext_INTERFACE_DEFINED = 1

$IID_IWICColorContext = GUID$("{3C613A02-34B2-44EA-9A7C-45AEA9C6FD6D}")

INTERFACE IWICColorContext $IID_IWICColorContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeFromFilename ( _                    ' VTable offset = 12
     BYREF wzFilename AS WSTRINGZ _                     ' __in LPCWSTR wzFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromMemory ( _                      ' VTable offset = 16
     BYVAL pbBuffer AS BYTE PTR _                       ' __in const BYTE *pbBuffer
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromExifColorSpace ( _              ' VTable offset = 20
     BYVAL value AS DWORD _                             ' __in UINT value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 24
     BYREF pType AS DWORD _                             ' __out WICColorContextType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProfileBytes ( _                           ' VTable offset = 28
     BYVAL cbBuffer AS DWORD _                          ' __in UINT cbBuffer
   , BYVAL pbBuffer AS BYTE PTR _                       ' __inout BYTE *pbBuffer
   , BYREF pcbActual AS DWORD _                         ' __out UINT *pcbActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExifColorSpace ( _                         ' VTable offset = 32
     BYREF pValue AS DWORD _                            ' __out UINT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICColorContext_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICColorTransform interface
' IID = B66F034F-D0E2-40AB-B436-6DE39E321A94
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICColorTransform_INTERFACE_DEFINED)
    %IWICColorTransform_INTERFACE_DEFINED = 1

$IID_IWICColorTransform = GUID$("{B66F034F-D0E2-40AB-B436-6DE39E321A94}")

INTERFACE IWICColorTransform $IID_IWICColorTransform

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICColorTransform Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 32
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYVAL pIContextSource AS IWICColorContext _        ' __in IWICColorContext *pIContextSource
   , BYVAL pIContextDest AS IWICColorContext _          ' __in IWICColorContext *pIContextDest
   , BYREF pixelFmtDest AS GUID _                       ' __in REFWICPixelFormatGUID pixelFmtDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICColorTransform_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICFastMetadataEncoder interface
' IID = B84E2C09-78C9-4AC4-8BD3-524AE1663A2F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICFastMetadataEncoder_INTERFACE_DEFINED)
    %IWICFastMetadataEncoder_INTERFACE_DEFINED = 1

$IID_IWICFastMetadataEncoder = GUID$("{B84E2C09-78C9-4AC4-8BD3-524AE1663A2F}")

INTERFACE IWICFastMetadataEncoder $IID_IWICFastMetadataEncoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataQueryWriter ( _                    ' VTable offset = 16
     BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter _ ' __out IWICMetadataQueryWriter **ppIMetadataQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICFastMetadataEncoder_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICStream interface
' IID = 135FF860-22B7-4DDF-B0F6-218F4F299A43
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IWICStream_INTERFACE_DEFINED)
    %IWICStream_INTERFACE_DEFINED = 1

$IID_IWICStream = GUID$("{135FF860-22B7-4DDF-B0F6-218F4F299A43}")

INTERFACE IWICStream $IID_IWICStream

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICStream Methods
   ' =====================================================================================
   METHOD InitializeFromIStream ( _                     ' VTable offset = 56
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromFilename ( _                    ' VTable offset = 60
     BYREF wzFileName AS WSTRINGZ _                     ' __in LPCWSTR wzFileName
   , BYVAL dwDesiredAccess AS DWORD _                   ' __in DWORD dwDesiredAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromMemory ( _                      ' VTable offset = 64
     BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
   , BYVAL cbBufferSize AS DWORD _                      ' __in DWORD cbBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromIStreamRegion ( _               ' VTable offset = 68
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL ulOffset AS QUAD _                           ' __in ULARGE_INTEGER ulOffset
   , BYVAL ulMaxSize AS QUAD _                          ' __in ULARGE_INTEGER ulMaxSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICStream_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICEnumMetadataItem interface
' IID = DC2BB46D-3F07-481E-8625-220C4AEDBB33
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICEnumMetadataItem_INTERFACE_DEFINED)
    %IWICEnumMetadataItem_INTERFACE_DEFINED = 1

$IID_IWICEnumMetadataItem = GUID$("{DC2BB46D-3F07-481E-8625-220C4AEDBB33}")

INTERFACE IWICEnumMetadataItem $IID_IWICEnumMetadataItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgeltSchema AS PROPVARIANT _                 ' __inout PROPVARIANT *rgeltSchema
   , BYREF rgeltId AS PROPVARIANT _                     ' __inout PROPVARIANT *rgeltId
   , BYREF rgeltValue AS PROPVARIANT _                  ' __opt_inout PROPVARIANT *rgeltValue
   , BYREF pceltFetched AS DWORD _                      ' __opt_out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumMetadataItem AS IWICEnumMetadataItem _ ' __out IWICEnumMetadataItem **ppIEnumMetadataItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICEnumMetadataItem_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICMetadataQueryReader interface
' IID = 30989668-E1C9-4597-B395-458EEDB808DF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICMetadataQueryReader_INTERFACE_DEFINED)
    %IWICMetadataQueryReader_INTERFACE_DEFINED = 1

$IID_IWICMetadataQueryReader = GUID$("{30989668-E1C9-4597-B395-458EEDB808DF}")

INTERFACE IWICMetadataQueryReader $IID_IWICMetadataQueryReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 12
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocation ( _                               ' VTable offset = 16
     BYVAL cchMaxLength AS DWORD _                      ' __in UINT cchMaxLength
   , BYREF wzNamespace AS WSTRINGZ _                    ' __inout WCHAR *wzNamespace
   , BYREF pcchActualLength AS DWORD _                  ' __out UINT *pcchActualLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataByName ( _                         ' VTable offset = 20
     BYREF wzName AS WSTRINGZ _                         ' __in LPCWSTR wzName
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 24
     BYREF ppIEnumString AS IEnumString _               ' __out IEnumString **ppIEnumString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataQueryReader_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICMetadataQueryWriter interface
' IID = A721791A-0DEF-4D06-BD91-2118BF1DB10B
' Inherited interface = IWICMetadataQueryReader
' ########################################################################################

#IF NOT %DEF(%IWICMetadataQueryWriter_INTERFACE_DEFINED)
    %IWICMetadataQueryWriter_INTERFACE_DEFINED = 1

$IID_IWICMetadataQueryWriter = GUID$("{A721791A-0DEF-4D06-BD91-2118BF1DB10B}")

INTERFACE IWICMetadataQueryWriter $IID_IWICMetadataQueryWriter

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICMetadataQueryReader Methods
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 12
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLocation ( _                               ' VTable offset = 16
     BYVAL cchMaxLength AS DWORD _                      ' __in UINT cchMaxLength
   , BYREF wzNamespace AS WSTRINGZ _                    ' __inout WCHAR *wzNamespace
   , BYREF pcchActualLength AS DWORD _                  ' __out UINT *pcchActualLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataByName ( _                         ' VTable offset = 20
     BYREF wzName AS WSTRINGZ _                         ' __in LPCWSTR wzName
   , BYREF pvarValue AS PROPVARIANT _                   ' __inout PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumerator ( _                             ' VTable offset = 24
     BYREF ppIEnumString AS IEnumString _               ' __out IEnumString **ppIEnumString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICMetadataQueryReader Methods
   ' =====================================================================================
   METHOD SetMetadataByName ( _                         ' VTable offset = 28
     BYREF wzName AS WSTRINGZ _                         ' __in LPCWSTR wzName
   , BYREF pvarValue AS PROPVARIANT _                   ' __in const PROPVARIANT *pvarValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveMetadataByName ( _                      ' VTable offset = 32
     BYREF wzName AS WSTRINGZ _                         ' __in LPCWSTR wzName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICMetadataQueryWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapEncoder interface
' IID = 00000103-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapEncoder_INTERFACE_DEFINED)
    %IWICBitmapEncoder_INTERFACE_DEFINED = 1

$IID_IWICBitmapEncoder = GUID$("{00000103-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmapEncoder $IID_IWICBitmapEncoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL cacheOption AS DWORD _                       ' __in WICBitmapEncoderCacheOption cacheOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 16
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEncoderInfo ( _                            ' VTable offset = 20
     BYREF ppIEncoderInfo AS IWICBitmapEncoderInfo _    ' __out IWICBitmapEncoderInfo **ppIEncoderInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorContexts ( _                          ' VTable offset = 24
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIColorContext AS IWICColorContext _        ' __in IWICColorContext **ppIColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 28
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnail ( _                              ' VTable offset = 32
     BYVAL pIThumbnail AS IWICBitmapSource _            ' __in IWICBitmapSource *pIThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreview ( _                                ' VTable offset = 36
     BYVAL pIPreview AS IWICBitmapSource _              ' __in IWICBitmapSource *pIPreview
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateNewFrame ( _                            ' VTable offset = 40
     BYREF ppIFrameEncode AS IWICBitmapFrameEncode _    ' __out IWICBitmapFrameEncode **ppIFrameEncode
   , BYREF ppIEncoderOptions AS IPropertyBag2 _         ' __inout IPropertyBag2 **ppIEncoderOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataQueryWriter ( _                    ' VTable offset = 48
     BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter _ ' __out IWICMetadataQueryWriter **ppIMetadataQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapEncoder_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapFrameEncode interface
' IID = 00000105-A8F2-4877-BA0A-FD2B6645FB94
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapFrameEncode_INTERFACE_DEFINED)
    %IWICBitmapFrameEncode_INTERFACE_DEFINED = 1

$IID_IWICBitmapFrameEncode = GUID$("{00000105-A8F2-4877-BA0A-FD2B6645FB94}")

INTERFACE IWICBitmapFrameEncode $IID_IWICBitmapFrameEncode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIEncoderOptions AS IPropertyBag2 _          ' __in IPropertyBag2 *pIEncoderOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 16
     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetResolution ( _                             ' VTable offset = 20
     BYVAL dpiX AS DOUBLE _                             ' __in double dpiX
   , BYVAL dpiY AS DOUBLE _                             ' __in double dpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPixelFormat ( _                            ' VTable offset = 24
     BYREF pPixelFormat AS GUID _                       ' __inout WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorContexts ( _                          ' VTable offset = 28
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIColorContext AS IWICColorContext _        ' __in IWICColorContext **ppIColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 32
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnail ( _                              ' VTable offset = 36
     BYVAL pIThumbnail AS IWICBitmapSource _            ' __in IWICBitmapSource *pIThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WritePixels ( _                               ' VTable offset = 40
     BYVAL lineCount AS DWORD _                         ' __in UINT lineCount
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbPixels AS BYTE PTR _                       ' __in BYTE *pbPixels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteSource ( _                               ' VTable offset = 44
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYREF prc AS WICRect _                             ' __in WICRect *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataQueryWriter ( _                    ' VTable offset = 52
     BYREF ppIMetadataQueryWriter AS IWICMetadataQueryWriter _ ' __out IWICMetadataQueryWriter **ppIMetadataQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapFrameEncode_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapDecoder interface
' IID = 9EDDE9E7-8DEE-47EA-99DF-E6FAF2ED44BF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapDecoder_INTERFACE_DEFINED)
    %IWICBitmapDecoder_INTERFACE_DEFINED = 1

$IID_IWICBitmapDecoder = GUID$("{9EDDE9E7-8DEE-47EA-99DF-E6FAF2ED44BF}")

INTERFACE IWICBitmapDecoder $IID_IWICBitmapDecoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryCapability ( _                           ' VTable offset = 12
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pdwCapability AS DWORD _                     ' __out DWORD *pdwCapability
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 16
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYVAL cacheOptions AS DWORD _                      ' __in WICDecodeOptions cacheOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 20
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDecoderInfo ( _                            ' VTable offset = 24
     BYREF ppIDecoderInfo AS IWICBitmapDecoderInfo _    ' __out IWICBitmapDecoderInfo **ppIDecoderInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 28
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMetadataQueryReader ( _                    ' VTable offset = 32
     BYREF ppIMetadataQueryReader AS IWICMetadataQueryReader _ ' __out IWICMetadataQueryReader **ppIMetadataQueryReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreview ( _                                ' VTable offset = 36
     BYREF ppIBitmapSource AS IWICBitmapSource _        ' __out IWICBitmapSource **ppIBitmapSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorContexts ( _                          ' VTable offset = 40
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIColorContexts AS IWICColorContext _       ' __inout IWICColorContext **ppIColorContexts
   , BYREF pcActualCount AS DWORD _                     ' __out UINT *pcActualCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 44
     BYREF ppIThumbnail AS IWICBitmapSource _           ' __out IWICBitmapSource **ppIThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameCount ( _                             ' VTable offset = 48
     BYREF pCount AS DWORD _                            ' __out UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrame ( _                                  ' VTable offset = 52
     BYVAL index AS DWORD _                             ' __in UINT index
   , BYREF ppIBitmapFrame AS IWICBitmapFrameDecode _    ' __out IWICBitmapFrameDecode **ppIBitmapFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapDecoder_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapSourceTransform interface
' IID = 3B16811B-6A43-4EC9-B713-3D5A0C13B940
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapSourceTransform_INTERFACE_DEFINED)
    %IWICBitmapSourceTransform_INTERFACE_DEFINED = 1

$IID_IWICBitmapSourceTransform = GUID$("{3B16811B-6A43-4EC9-B713-3D5A0C13B940}")

INTERFACE IWICBitmapSourceTransform $IID_IWICBitmapSourceTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 12
     BYREF prcSrc AS WICRect _                          ' __in const WICRect *prcSrc
   , BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYREF pguidDstFormat AS GUID _                     ' __in WICPixelFormatGUID *pguidDstFormat
   , BYVAL dstTransform AS DWORD _                      ' __in WICBitmapTransformOptions dstTransform
   , BYVAL nStride AS DWORD _                           ' __in UINT nStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClosestSize ( _                            ' VTable offset = 16
     BYREF puiWidth AS DWORD _                          ' __inout UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __inout UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClosestPixelFormat ( _                     ' VTable offset = 20
     BYREF pguidDstFormat AS GUID _                     ' __inout WICPixelFormatGUID *pguidDstFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportTransform ( _                      ' VTable offset = 24
     BYVAL dstTransform AS DWORD _                      ' __in WICBitmapTransformOptions dstTransform
   , BYREF pfIsSupported AS LONG _                      ' __out BOOL *pfIsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapSourceTransform_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapFrameDecode interface
' IID = 3B16811B-6A43-4EC9-A813-3D930C13B940
' Inherited interface = IWICBitmapSource
' ########################################################################################

#IF NOT %DEF(%IWICBitmapFrameDecode_INTERFACE_DEFINED)
    %IWICBitmapFrameDecode_INTERFACE_DEFINED = 1

$IID_IWICBitmapFrameDecode = GUID$("{3B16811B-6A43-4EC9-A813-3D930C13B940}")

INTERFACE IWICBitmapFrameDecode $IID_IWICBitmapFrameDecode

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapFrameDecode Methods
   ' =====================================================================================
   METHOD GetMetadataQueryReader ( _                    ' VTable offset = 32
     BYREF ppIMetadataQueryReader AS IWICMetadataQueryReader _ ' __out IWICMetadataQueryReader **ppIMetadataQueryReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorContexts ( _                          ' VTable offset = 36
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIColorContexts AS IWICColorContext _       ' __inout IWICColorContext **ppIColorContexts
   , BYREF pcActualCount AS DWORD _                     ' __out UINT *pcActualCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 40
     BYREF ppIThumbnail AS IWICBitmapSource _           ' __out IWICBitmapSource **ppIThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapFrameDecode_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICProgressiveLevelControl interface
' IID = DAAC296F-7AA5-4DBF-8D15-225C5976F891
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICProgressiveLevelControl_INTERFACE_DEFINED)
    %IWICProgressiveLevelControl_INTERFACE_DEFINED = 1

$IID_IWICProgressiveLevelControl = GUID$("{DAAC296F-7AA5-4DBF-8D15-225C5976F891}")

'INTERFACE IWICProgressiveLevelControl $IID_IWICProgressiveLevelControl

'   INHERIT IAutomation

'   ' =====================================================================================
'   METHOD GetLevelCount ( _                             ' VTable offset = 12
'   ) AS DWORD                                           ' __retval_out UINT *pcLevels
'   ' =====================================================================================
'   METHOD GetCurrentLevel ( _                           ' VTable offset = 16
'   ) AS DWORD                                           ' __retval_out UINT *pnLevel
'   ' =====================================================================================
'   METHOD SetCurrentLevel ( _                           ' VTable offset = 20
'     BYVAL nLevel AS DWORD _                            ' __in UINT nLevel
'   )                                                    ' void
'   ' =====================================================================================

'END INTERFACE

' // Note: Changed to IUnknown for consistency with the other interfaces

INTERFACE IWICProgressiveLevelControl $IID_IWICProgressiveLevelControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLevelCount ( _                             ' VTable offset = 12
     BYREF pcLevels AS DWORD _                          ' __retval_out UINT *pcLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLevel ( _                           ' VTable offset = 16
     BYREF pnLevel AS DWORD _                           ' __retval_out UINT *pnLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentLevel ( _                           ' VTable offset = 20
     BYVAL nLevel AS DWORD _                            ' __in UINT nLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICProgressiveLevelControl_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICProgressCallback interface
' IID = 4776F9CD-9517-45FA-BF24-E89C5EC5C60C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICProgressCallback_INTERFACE_DEFINED)
    %IWICProgressCallback_INTERFACE_DEFINED = 1

$IID_IWICProgressCallback = GUID$("{4776F9CD-9517-45FA-BF24-E89C5EC5C60C}")

INTERFACE IWICProgressCallback $IID_IWICProgressCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
     BYVAL uFrameNum AS DWORD _                         ' __in ULONG uFrameNum
   , BYVAL operation AS DWORD _                         ' __in WICProgressOperation operation
   , BYVAL dblProgress AS DOUBLE _                      ' __in double dblProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICProgressCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapCodecProgressNotification interface
' IID = 64C1024E-C3CF-4462-8078-88C2B11C46D9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICBitmapCodecProgressNotification_INTERFACE_DEFINED)
    %IWICBitmapCodecProgressNotification_INTERFACE_DEFINED = 1

'typedef /* [ref] */ HRESULT ( __stdcall *PFNProgressNotification )(
'    LPVOID pvData,
'    ULONG uFrameNum,
'    WICProgressOperation operation,
'    double dblProgress);

'FUNCTION ProgressNotification ( _
'   BYVAL pvData AS DWORD _                    ' LPVOID pvData
' , BYVAL uFrameNum AS DWORD _                 ' ULONG uFrameNum
' , BYVAL operation AS DWORD _                 ' WICProgressOperation operation
' , BYVAL dblProgress AS DOUBLE _              ' double dblProgress
' ) AS LONG                                              ' HRESULT

$IID_IWICBitmapCodecProgressNotification = GUID$("{64C1024E-C3CF-4462-8078-88C2B11C46D9}")

INTERFACE IWICBitmapCodecProgressNotification $IID_IWICBitmapCodecProgressNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterProgressNotification ( _              ' VTable offset = 12
     BYVAL pfnProgressNotification AS DWORD _           ' __in PFNProgressNotification pfnProgressNotification
   , BYVAL pvData AS DWORD _                            ' __in LPVOID pvData
   , BYVAL dwProgressFlags AS DWORD _                   ' __in DWORD dwProgressFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapCodecProgressNotification_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICComponentInfo interface
' IID = 23BC3F0A-698B-4357-886B-F24D50671334
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICComponentInfo_INTERFACE_DEFINED)
    %IWICComponentInfo_INTERFACE_DEFINED = 1

$IID_IWICComponentInfo = GUID$("{23BC3F0A-698B-4357-886B-F24D50671334}")

INTERFACE IWICComponentInfo $IID_IWICComponentInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICComponentInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICFormatConverterInfo interface
' IID = 9F34FB65-13F4-4F15-BC57-3726B5E53D9F
' Inherited interface = IWICComponentInfo
' ########################################################################################

#IF NOT %DEF(%IWICFormatConverterInfo_INTERFACE_DEFINED)
    %IWICFormatConverterInfo_INTERFACE_DEFINED = 1

$IID_IWICFormatConverterInfo = GUID$("{9F34FB65-13F4-4F15-BC57-3726B5E53D9F}")

INTERFACE IWICFormatConverterInfo $IID_IWICFormatConverterInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICFormatConverterInfo Methods
   ' =====================================================================================
   METHOD GetPixelFormats ( _                           ' VTable offset = 44
     BYVAL cFormats AS DWORD _                          ' __in UINT cFormats
   , BYREF pPixelFormatGUIDs AS GUID _                  ' __inout WICPixelFormatGUID *pPixelFormatGUIDs
   , BYREF pcActual AS DWORD _                          ' __out UINT *pcActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 48
     BYREF ppIConverter AS IWICFormatConverter _        ' __out IWICFormatConverter **ppIConverter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICFormatConverterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapCodecInfo interface
' IID = E87A44C4-B76E-4C47-8B09-298EB12A2714
' Inherited interface = IWICComponentInfo
' ########################################################################################

#IF NOT %DEF(%IWICBitmapCodecInfo_INTERFACE_DEFINED)
    %IWICBitmapCodecInfo_INTERFACE_DEFINED = 1

$IID_IWICBitmapCodecInfo = GUID$("{E87A44C4-B76E-4C47-8B09-298EB12A2714}")

INTERFACE IWICBitmapCodecInfo $IID_IWICBitmapCodecInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapCodecInfo Methods
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 44
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormats ( _                           ' VTable offset = 48
     BYVAL cFormats AS DWORD _                          ' __in UINT cFormats
   , BYREF pguidPixelFormats AS GUID _                  ' __inout GUID *pguidPixelFormats
   , BYREF pcActual AS DWORD _                          ' __out UINT *pcActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorManagementVersion ( _                 ' VTable offset = 52
     BYVAL cchColorManagementVersion AS DWORD _         ' __in UINT cchColorManagementVersion
   , BYREF wzColorManagementVersion AS WSTRINGZ _       ' __inout WCHAR *wzColorManagementVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 56
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 60
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMimeTypes ( _                              ' VTable offset = 64
     BYVAL cchMimeTypes AS DWORD _                      ' __in UINT cchMimeTypes
   , BYREF wzMimeTypes AS WSTRINGZ _                    ' __inout WCHAR *wzMimeTypes
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileExtensions ( _                         ' VTable offset = 68
     BYVAL cchFileExtensions AS DWORD _                 ' __in UINT cchFileExtensions
   , BYREF wzFileExtensions AS WSTRINGZ _               ' __inout WCHAR *wzFileExtensions
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportAnimation ( _                      ' VTable offset = 72
     BYREF pfSupportAnimation AS LONG _                 ' __out BOOL *pfSupportAnimation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportChromakey ( _                      ' VTable offset = 76
     BYREF pfSupportChromakey AS LONG _                 ' __out BOOL *pfSupportChromakey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportLossless ( _                       ' VTable offset = 80
     BYREF pfSupportLossless AS LONG _                  ' __out BOOL *pfSupportLossless
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportMultiframe ( _                     ' VTable offset = 84
     BYREF pfSupportMultiframe AS LONG _                ' __out BOOL *pfSupportMultiframe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesMimeType ( _                           ' VTable offset = 88
     BYREF wzMimeType AS WSTRINGZ _                     ' __in LPCWSTR wzMimeType
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapCodecInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapEncoderInfo interface
' IID = 94C9B4EE-A09F-4F92-8A1E-4A9BCE7E76FB
' Inherited interface = IWICBitmapCodecInfo
' ########################################################################################

#IF NOT %DEF(%IWICBitmapEncoderInfo_INTERFACE_DEFINED)
    %IWICBitmapEncoderInfo_INTERFACE_DEFINED = 1

$IID_IWICBitmapEncoderInfo = GUID$("{94C9B4EE-A09F-4F92-8A1E-4A9BCE7E76FB}")

INTERFACE IWICBitmapEncoderInfo $IID_IWICBitmapEncoderInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapCodecInfo Methods
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 44
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormats ( _                           ' VTable offset = 48
     BYVAL cFormats AS DWORD _                          ' __in UINT cFormats
   , BYREF pguidPixelFormats AS GUID _                  ' __inout GUID *pguidPixelFormats
   , BYREF pcActual AS DWORD _                          ' __out UINT *pcActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorManagementVersion ( _                 ' VTable offset = 52
     BYVAL cchColorManagementVersion AS DWORD _         ' __in UINT cchColorManagementVersion
   , BYREF wzColorManagementVersion AS WSTRINGZ _       ' __inout WCHAR *wzColorManagementVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 56
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 60
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMimeTypes ( _                              ' VTable offset = 64
     BYVAL cchMimeTypes AS DWORD _                      ' __in UINT cchMimeTypes
   , BYREF wzMimeTypes AS WSTRINGZ _                    ' __inout WCHAR *wzMimeTypes
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileExtensions ( _                         ' VTable offset = 68
     BYVAL cchFileExtensions AS DWORD _                 ' __in UINT cchFileExtensions
   , BYREF wzFileExtensions AS WSTRINGZ _               ' __inout WCHAR *wzFileExtensions
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportAnimation ( _                      ' VTable offset = 72
     BYREF pfSupportAnimation AS LONG _                 ' __out BOOL *pfSupportAnimation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportChromakey ( _                      ' VTable offset = 76
     BYREF pfSupportChromakey AS LONG _                 ' __out BOOL *pfSupportChromakey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportLossless ( _                       ' VTable offset = 80
     BYREF pfSupportLossless AS LONG _                  ' __out BOOL *pfSupportLossless
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportMultiframe ( _                     ' VTable offset = 84
     BYREF pfSupportMultiframe AS LONG _                ' __out BOOL *pfSupportMultiframe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesMimeType ( _                           ' VTable offset = 88
     BYREF wzMimeType AS WSTRINGZ _                     ' __in LPCWSTR wzMimeType
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapEncoderInfo Methods
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 92
     BYREF ppIBitmapEncoder AS IWICBitmapEncoder _      ' __out IWICBitmapEncoder **ppIBitmapEncoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapEncoderInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICBitmapDecoderInfo interface
' IID = D8CD007F-D08F-4191-9BFC-236EA7F0E4B5
' Inherited interface = IWICBitmapCodecInfo
' ########################################################################################

#IF NOT %DEF(%IWICBitmapDecoderInfo_INTERFACE_DEFINED)
    %IWICBitmapDecoderInfo_INTERFACE_DEFINED = 1

$IID_IWICBitmapDecoderInfo = GUID$("{D8CD007F-D08F-4191-9BFC-236EA7F0E4B5}")

INTERFACE IWICBitmapDecoderInfo $IID_IWICBitmapDecoderInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapCodecInfo Methods
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 44
     BYREF pguidContainerFormat AS GUID _               ' __out GUID *pguidContainerFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormats ( _                           ' VTable offset = 48
     BYVAL cFormats AS DWORD _                          ' __in UINT cFormats
   , BYREF pguidPixelFormats AS GUID _                  ' __inout GUID *pguidPixelFormats
   , BYREF pcActual AS DWORD _                          ' __out UINT *pcActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorManagementVersion ( _                 ' VTable offset = 52
     BYVAL cchColorManagementVersion AS DWORD _         ' __in UINT cchColorManagementVersion
   , BYREF wzColorManagementVersion AS WSTRINGZ _       ' __inout WCHAR *wzColorManagementVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceManufacturer ( _                     ' VTable offset = 56
     BYVAL cchDeviceManufacturer AS DWORD _             ' __in UINT cchDeviceManufacturer
   , BYREF wzDeviceManufacturer AS WSTRINGZ _           ' __inout WCHAR *wzDeviceManufacturer
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceModels ( _                           ' VTable offset = 60
     BYVAL cchDeviceModels AS DWORD _                   ' __in UINT cchDeviceModels
   , BYREF wzDeviceModels AS WSTRINGZ _                 ' __inout WCHAR *wzDeviceModels
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMimeTypes ( _                              ' VTable offset = 64
     BYVAL cchMimeTypes AS DWORD _                      ' __in UINT cchMimeTypes
   , BYREF wzMimeTypes AS WSTRINGZ _                    ' __inout WCHAR *wzMimeTypes
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileExtensions ( _                         ' VTable offset = 68
     BYVAL cchFileExtensions AS DWORD _                 ' __in UINT cchFileExtensions
   , BYREF wzFileExtensions AS WSTRINGZ _               ' __inout WCHAR *wzFileExtensions
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportAnimation ( _                      ' VTable offset = 72
     BYREF pfSupportAnimation AS LONG _                 ' __out BOOL *pfSupportAnimation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportChromakey ( _                      ' VTable offset = 76
     BYREF pfSupportChromakey AS LONG _                 ' __out BOOL *pfSupportChromakey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportLossless ( _                       ' VTable offset = 80
     BYREF pfSupportLossless AS LONG _                  ' __out BOOL *pfSupportLossless
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoesSupportMultiframe ( _                     ' VTable offset = 84
     BYREF pfSupportMultiframe AS LONG _                ' __out BOOL *pfSupportMultiframe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesMimeType ( _                           ' VTable offset = 88
     BYREF wzMimeType AS WSTRINGZ _                     ' __in LPCWSTR wzMimeType
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapDecoderInfo Methods
   ' =====================================================================================
   METHOD GetPatterns ( _                               ' VTable offset = 92
     BYVAL cbSizePatterns AS DWORD _                    ' __in UINT cbSizePatterns
   , BYREF pPatterns AS WICBitmapPattern _              ' __inout WICBitmapPattern *pPatterns
   , BYREF pcPatterns AS DWORD _                        ' __inout UINT *pcPatterns
   , BYREF pcbPatternsActual AS DWORD _                 ' __inout UINT *pcbPatternsActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MatchesPattern ( _                            ' VTable offset = 96
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pfMatches AS LONG _                          ' __out BOOL *pfMatches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 100
     BYREF ppIBitmapDecoder AS IWICBitmapDecoder _      ' __out IWICBitmapDecoder **ppIBitmapDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICBitmapDecoderInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICPixelFormatInfo interface
' IID = E8EDA601-3D48-431A-AB44-69059BE88BBE
' Inherited interface = IWICComponentInfo
' ########################################################################################

#IF NOT %DEF(%IWICPixelFormatInfo_INTERFACE_DEFINED)
    %IWICPixelFormatInfo_INTERFACE_DEFINED = 1

$IID_IWICPixelFormatInfo = GUID$("{E8EDA601-3D48-431A-AB44-69059BE88BBE}")

INTERFACE IWICPixelFormatInfo $IID_IWICPixelFormatInfo

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICPixelFormatInfo Methods
   ' =====================================================================================
   METHOD GetFormatGUID ( _                             ' VTable offset = 44
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorContext ( _                           ' VTable offset = 48
     BYREF ppIColorContext AS IWICColorContext _        ' __out IWICColorContext **ppIColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitsPerPixel ( _                           ' VTable offset = 52
     BYREF puiBitsPerPixel AS DWORD _                   ' __out UINT *puiBitsPerPixel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 56
     BYREF puiChannelCount AS DWORD _                   ' __out UINT *puiChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelMask ( _                            ' VTable offset = 60
     BYVAL uiChannelIndex AS DWORD _                    ' __in UINT uiChannelIndex
   , BYVAL cbMaskBuffer AS DWORD _                      ' __in UINT cbMaskBuffer
   , BYVAL pbMaskBuffer AS BYTE PTR _                   ' __inout BYTE *pbMaskBuffer
   , BYREF pcbActual AS DWORD _                         ' __out UINT *pcbActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICPixelFormatInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICPixelFormatInfo2 interface
' IID = A9DB33A2-AF5F-43C7-B679-74F5984B5AA4
' Inherited interface = IWICPixelFormatInfo
' ########################################################################################

#IF NOT %DEF(%IWICPixelFormatInfo2_INTERFACE_DEFINED)
    %IWICPixelFormatInfo2_INTERFACE_DEFINED = 1

$IID_IWICPixelFormatInfo2 = GUID$("{A9DB33A2-AF5F-43C7-B679-74F5984B5AA4}")

INTERFACE IWICPixelFormatInfo2 $IID_IWICPixelFormatInfo2

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICComponentInfo Methods
   ' =====================================================================================
   METHOD GetComponentType ( _                          ' VTable offset = 12
     BYREF pType AS DWORD _                             ' __out WICComponentType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 16
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningStatus ( _                          ' VTable offset = 20
     BYREF pStatus AS DWORD _                           ' __out DWORD *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAuthor ( _                                 ' VTable offset = 24
     BYVAL cchAuthor AS DWORD _                         ' __in UINT cchAuthor
   , BYREF wzAuthor AS WSTRINGZ _                       ' __inout WCHAR *wzAuthor
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVendorGUID ( _                             ' VTable offset = 28
     BYREF pguidVendor AS GUID _                        ' __out GUID *pguidVendor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 32
     BYVAL cchVersion AS DWORD _                        ' __in UINT cchVersion
   , BYREF wzVersion AS WSTRINGZ _                      ' __inout WCHAR *wzVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpecVersion ( _                            ' VTable offset = 36
     BYVAL cchSpecVersion AS DWORD _                    ' __in UINT cchSpecVersion
   , BYREF wzSpecVersion AS WSTRINGZ _                  ' __inout WCHAR *wzSpecVersion
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL cchFriendlyName AS DWORD _                   ' __in UINT cchFriendlyName
   , BYREF wzFriendlyName AS WSTRINGZ _                 ' __inout WCHAR *wzFriendlyName
   , BYREF pcchActual AS DWORD _                        ' __out UINT *pcchActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICPixelFormatInfo Methods
   ' =====================================================================================
   METHOD GetFormatGUID ( _                             ' VTable offset = 44
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorContext ( _                           ' VTable offset = 48
     BYREF ppIColorContext AS IWICColorContext _        ' __out IWICColorContext **ppIColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitsPerPixel ( _                           ' VTable offset = 52
     BYREF puiBitsPerPixel AS DWORD _                   ' __out UINT *puiBitsPerPixel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 56
     BYREF puiChannelCount AS DWORD _                   ' __out UINT *puiChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelMask ( _                            ' VTable offset = 60
     BYVAL uiChannelIndex AS DWORD _                    ' __in UINT uiChannelIndex
   , BYVAL cbMaskBuffer AS DWORD _                      ' __in UINT cbMaskBuffer
   , BYVAL pbMaskBuffer AS BYTE PTR _                   ' __inout BYTE *pbMaskBuffer
   , BYREF pcbActual AS DWORD _                         ' __out UINT *pcbActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICPixelFormatInfo Methods
   ' =====================================================================================
   METHOD SupportsTransparency ( _                      ' VTable offset = 64
     BYREF pfSupportsTransparency AS LONG _             ' __out BOOL *pfSupportsTransparency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumericRepresentation ( _                  ' VTable offset = 68
     BYREF pNumericRepresentation AS DWORD _            ' __out WICPixelFormatNumericRepresentation *pNumericRepresentation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICPixelFormatInfo2_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICImagingFactory interface
' IID = EC5EC8A9-C395-4314-9C77-54D7A935FF70
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICImagingFactory_INTERFACE_DEFINED)
    %IWICImagingFactory_INTERFACE_DEFINED = 1

$IID_IWICImagingFactory = GUID$("{EC5EC8A9-C395-4314-9C77-54D7A935FF70}")

'INTERFACE IWICImagingFactory $IID_IWICImagingFactory

'   INHERIT IAutomation

'   ' =====================================================================================
'   METHOD CreateDecoderFromFilename ( _                 ' VTable offset = 12
'     BYREF wzFilename AS WSTRINGZ _                     ' __in LPCWSTR wzFilename
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   , BYVAL dwDesiredAccess AS DWORD _                   ' __in DWORD dwDesiredAccess
'   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
'   ) AS IWICBitmapDecoder                               ' __retval_out IWICBitmapDecoder **ppIDecoder
'   ' =====================================================================================
'   METHOD CreateDecoderFromStream ( _                   ' VTable offset = 16
'     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
'   ) AS IWICBitmapDecoder                               ' __retval_out IWICBitmapDecoder **ppIDecoder
'   ' =====================================================================================
'   METHOD CreateDecoderFromFileHandle ( _               ' VTable offset = 20
'     BYVAL hFile AS DWORD _                             ' __in ULONG_PTR hFile
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
'   ) AS IWICBitmapDecoder                               ' __retval_out IWICBitmapDecoder **ppIDecoder
'   ' =====================================================================================
'   METHOD CreateComponentInfo ( _                       ' VTable offset = 24
'     BYREF clsidComponent AS GUID _                     ' __in REFCLSID clsidComponent
'   , BYREF ppIInfo AS IWICComponentInfo _               ' __out IWICComponentInfo **ppIInfo
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateDecoder ( _                             ' VTable offset = 28
'     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   ) AS IWICBitmapDecoder                               ' __retval_out IWICBitmapDecoder **ppIDecoder
'   ' =====================================================================================
'   METHOD CreateEncoder ( _                             ' VTable offset = 32
'     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   ) AS IWICBitmapEncoder                               ' __retval_out IWICBitmapEncoder **ppIEncoder
'   ' =====================================================================================
'   METHOD CreatePalette ( _                             ' VTable offset = 28
'     BYREF ppIPalette AS IWICPalette _                  ' __out IWICPalette **ppIPalette
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateFormatConverter ( _                     ' VTable offset = 32
'     BYREF ppIFormatConverter AS IWICFormatConverter _  ' __out IWICFormatConverter **ppIFormatConverter
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapScaler ( _                        ' VTable offset = 36
'     BYREF ppIBitmapScaler AS IWICBitmapScaler _        ' __out IWICBitmapScaler **ppIBitmapScaler
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapClipper ( _                       ' VTable offset = 40
'     BYREF ppIBitmapClipper AS IWICBitmapClipper _      ' __out IWICBitmapClipper **ppIBitmapClipper
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFlipRotator ( _                   ' VTable offset = 44
'     BYREF ppIBitmapFlipRotator AS IWICBitmapFlipRotator _ ' __out IWICBitmapFlipRotator **ppIBitmapFlipRotator
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateStream ( _                              ' VTable offset = 48
'     BYREF ppIWICStream AS IWICStream _                 ' __out IWICStream **ppIWICStream
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateColorContext ( _                        ' VTable offset = 52
'     BYREF ppIWICColorContext AS IWICColorContext _     ' __out IWICColorContext **ppIWICColorContext
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateColorTransformer ( _                    ' VTable offset = 56
'     BYREF ppIWICColorTransform AS IWICColorTransform _ ' __out IWICColorTransform **ppIWICColorTransform
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmap ( _                              ' VTable offset = 60
'     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
'   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
'   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
'   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFromSource ( _                    ' VTable offset = 64
'     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
'   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFromSourceRect ( _                ' VTable offset = 68
'     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
'   , BYVAL x AS DWORD _                                 ' __in UINT x
'   , BYVAL y AS DWORD _                                 ' __in UINT y
'   , BYVAL width AS DWORD _                             ' __in UINT width
'   , BYVAL height AS DWORD _                            ' __in UINT height
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFromMemory ( _                    ' VTable offset = 72
'     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
'   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
'   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
'   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
'   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
'   , BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFromHBITMAP ( _                   ' VTable offset = 76
'     BYVAL hBitmap AS DWORD _                           ' __in HBITMAP hBitmap
'   , BYVAL hPalette AS DWORD _                          ' __in HPALETTE hPalette
'   , BYVAL options AS DWORD _                           ' __in WICBitmapAlphaChannelOption options
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateBitmapFromHICON ( _                     ' VTable offset = 80
'     BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
'   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateComponentEnumerator ( _                 ' VTable offset = 84
'     BYVAL componentTypes AS DWORD _                    ' __in DWORD componentTypes
'   , BYVAL options AS DWORD _                           ' __in DWORD options
'   , BYREF ppIEnumUnknown AS IEnumUnknown _             ' __out IEnumUnknown **ppIEnumUnknown
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateFastMetadataEncoderFromDecoder ( _      ' VTable offset = 88
'     BYVAL pIDecoder AS IWICBitmapDecoder _             ' __in IWICBitmapDecoder *pIDecoder
'   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateFastMetadataEncoderFromFrameDecode ( _  ' VTable offset = 92
'     BYVAL pIFrameDecoder AS IWICBitmapFrameDecode _    ' __in IWICBitmapFrameDecode *pIFrameDecoder
'   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateQueryWriter ( _                         ' VTable offset = 96
'     BYREF guidMetadataFormat AS GUID _                 ' __in REFGUID guidMetadataFormat
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
'   )                                                    ' void
'   ' =====================================================================================
'   METHOD CreateQueryWriterFromReader ( _               ' VTable offset = 100
'     BYVAL pIQueryReader AS IWICMetadataQueryReader _   ' __in IWICMetadataQueryReader *pIQueryReader
'   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
'   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
'   )                                                    ' void
'   ' =====================================================================================

'END INTERFACE

' // Note: Changed to IUnknown for consistency with the other interfaces

INTERFACE IWICImagingFactory $IID_IWICImagingFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateDecoderFromFilename ( _                 ' VTable offset = 12
     BYREF wzFilename AS WSTRINGZ _                     ' __in LPCWSTR wzFilename
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL dwDesiredAccess AS DWORD _                   ' __in DWORD dwDesiredAccess
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoderFromStream ( _                   ' VTable offset = 16
     BYVAL pIStream AS IStream _                        ' __in IStream *pIStream
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoderFromFileHandle ( _               ' VTable offset = 20
     BYVAL hFile AS DWORD _                             ' __in ULONG_PTR hFile
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYVAL metadataOptions AS DWORD _                   ' __in WICDecodeOptions metadataOptions
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentInfo ( _                       ' VTable offset = 24
     BYREF clsidComponent AS GUID _                     ' __in REFCLSID clsidComponent
   , BYREF ppIInfo AS IWICComponentInfo _               ' __out IWICComponentInfo **ppIInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDecoder ( _                             ' VTable offset = 28
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEncoder ( _                             ' VTable offset = 32
     BYREF guidContainerFormat AS GUID _                ' __in REFGUID guidContainerFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIDecoder AS IWICBitmapDecoder _            ' __retval_out IWICBitmapDecoder **ppIDecoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePalette ( _                             ' VTable offset = 28
     BYREF ppIPalette AS IWICPalette _                  ' __out IWICPalette **ppIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFormatConverter ( _                     ' VTable offset = 32
     BYREF ppIFormatConverter AS IWICFormatConverter _  ' __out IWICFormatConverter **ppIFormatConverter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapScaler ( _                        ' VTable offset = 36
     BYREF ppIBitmapScaler AS IWICBitmapScaler _        ' __out IWICBitmapScaler **ppIBitmapScaler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapClipper ( _                       ' VTable offset = 40
     BYREF ppIBitmapClipper AS IWICBitmapClipper _      ' __out IWICBitmapClipper **ppIBitmapClipper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFlipRotator ( _                   ' VTable offset = 44
     BYREF ppIBitmapFlipRotator AS IWICBitmapFlipRotator _ ' __out IWICBitmapFlipRotator **ppIBitmapFlipRotator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 48
     BYREF ppIWICStream AS IWICStream _                 ' __out IWICStream **ppIWICStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateColorContext ( _                        ' VTable offset = 52
     BYREF ppIWICColorContext AS IWICColorContext _     ' __out IWICColorContext **ppIWICColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateColorTransformer ( _                    ' VTable offset = 56
     BYREF ppIWICColorTransform AS IWICColorTransform _ ' __out IWICColorTransform **ppIWICColorTransform
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmap ( _                              ' VTable offset = 60
     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromSource ( _                    ' VTable offset = 64
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYVAL option AS DWORD _                            ' __in WICBitmapCreateCacheOption option
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromSourceRect ( _                ' VTable offset = 68
     BYVAL pIBitmapSource AS IWICBitmapSource _         ' __in IWICBitmapSource *pIBitmapSource
   , BYVAL x AS DWORD _                                 ' __in UINT x
   , BYVAL y AS DWORD _                                 ' __in UINT y
   , BYVAL width AS DWORD _                             ' __in UINT width
   , BYVAL height AS DWORD _                            ' __in UINT height
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromMemory ( _                    ' VTable offset = 72
     BYVAL uiWidth AS DWORD _                           ' __in UINT uiWidth
   , BYVAL uiHeight AS DWORD _                          ' __in UINT uiHeight
   , BYREF pixelFormat AS GUID _                        ' __in REFWICPixelFormatGUID pixelFormat
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromHBITMAP ( _                   ' VTable offset = 76
     BYVAL hBitmap AS DWORD _                           ' __in HBITMAP hBitmap
   , BYVAL hPalette AS DWORD _                          ' __in HPALETTE hPalette
   , BYVAL options AS DWORD _                           ' __in WICBitmapAlphaChannelOption options
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateBitmapFromHICON ( _                     ' VTable offset = 80
     BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF ppIBitmap AS IWICBitmap _                    ' __out IWICBitmap **ppIBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponentEnumerator ( _                 ' VTable offset = 84
     BYVAL componentTypes AS DWORD _                    ' __in DWORD componentTypes
   , BYVAL options AS DWORD _                           ' __in DWORD options
   , BYREF ppIEnumUnknown AS IEnumUnknown _             ' __out IEnumUnknown **ppIEnumUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFastMetadataEncoderFromDecoder ( _      ' VTable offset = 88
     BYVAL pIDecoder AS IWICBitmapDecoder _             ' __in IWICBitmapDecoder *pIDecoder
   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFastMetadataEncoderFromFrameDecode ( _  ' VTable offset = 92
     BYVAL pIFrameDecoder AS IWICBitmapFrameDecode _    ' __in IWICBitmapFrameDecode *pIFrameDecoder
   , BYREF ppIFastEncoder AS IWICFastMetadataEncoder _  ' __out IWICFastMetadataEncoder **ppIFastEncoder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryWriter ( _                         ' VTable offset = 96
     BYREF guidMetadataFormat AS GUID _                 ' __in REFGUID guidMetadataFormat
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateQueryWriterFromReader ( _               ' VTable offset = 100
     BYVAL pIQueryReader AS IWICMetadataQueryReader _   ' __in IWICMetadataQueryReader *pIQueryReader
   , BYREF pguidVendor AS GUID _                        ' __in const GUID *pguidVendor
   , BYREF ppIQueryWriter AS IWICMetadataQueryWriter _  ' __out IWICMetadataQueryWriter **ppIQueryWriter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICImagingFactory_INTERFACE_DEFINED__ */


DECLARE FUNCTION WICConvertBitmapSource IMPORT "windowscodecs.dll" ALIAS "WICConvertBitmapSource" ( _
   BYREF dstFormat AS GUID _                            ' __in REFWICPixelFormatGUID dstFormat
 , BYVAL pISrc AS IWICBitmapSource _                    ' __in IWICBitmapSource  *pISrc
 , BYREF ppIDst AS IWICBitmapSource _                   ' __out IWICBitmapSource **ppIDst
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICCreateBitmapFromSection IMPORT "windowscodecs.dll" ALIAS "WICCreateBitmapFromSection" ( _
   BYVAL width AS DWORD _                               ' __in UINT width
 , BYVAL height AS DWORD _                              ' __in UINT height
 , BYREF pixelFormat AS GUID _                          ' __in REFWICPixelFormatGUID pixelFormat
 , BYVAL hSection AS DWORD _                            ' __in HANDLE hSection
 , BYVAL stride AS DWORD _                              ' __in UINT stride
 , BYVAL offset AS DWORD _                              ' __in UINT offset
 , BYREF ppIBitmap AS IWICBitmap _                      ' __out IWICBitmap **ppIBitmap
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICCreateBitmapFromSectionEx IMPORT "windowscodecs.dll" ALIAS "WICCreateBitmapFromSectionEx" ( _
   BYVAL width AS DWORD _                               ' __in UINT width
 , BYVAL height AS DWORD _                              ' __in UINT height
 , BYREF pixelFormat AS GUID _                          ' __in REFWICPixelFormatGUID pixelFormat
 , BYVAL hSection AS DWORD _                            ' __in HANDLE hSection
 , BYVAL stride AS DWORD _                              ' __in UINT stride
 , BYVAL offset AS DWORD _                              ' __in UINT offset
 , BYVAL desiredAccessLevel AS DWORD _                  ' __in WICSectionAccessLevel desiredAccessLevel
 , BYREF ppIBitmap AS IWICBitmap _                      ' __out IWICBitmap **ppIBitmap
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICMapGuidToShortName IMPORT "windowscodecs.dll" ALIAS "WICMapGuidToShortName" ( _
   BYREF guid AS GUID _                                 ' __in REFGUID guid
 , BYVAL cchName AS DWORD _                             ' __in UINT cchName
 , BYREF wzName AS WSTRINGZ _                           ' __inout WCHAR *wzName
 , BYREF pcchActual AS DWORD _                          ' __out UINT *pcchActual
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICMapShortNameToGuid IMPORT "windowscodecs.dll" ALIAS "WICMapShortNameToGuid" ( _
   BYVAL wzName AS WSTRINGZ PTR _                       ' __in const WCHAR *wzName
 , BYREF pguid AS GUID _                                ' __out GUID *pguid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WICMapSchemaToName IMPORT "windowscodecs.dll" ALIAS "WICMapSchemaToName" ( _
   BYREF guidMetadataFormat AS GUID _                   ' __in REFGUID guidMetadataFormat
 , BYREF pwzSchema AS WSTRINGZ _                        ' __in LPWSTR pwzSchema
 , BYVAL cchName AS DWORD _                             ' __in UINT cchName
 , BYREF wzName AS WSTRINGZ _                           ' __inout WCHAR *wzName
 , BYREF pcchActual AS DWORD _                          ' __out UINT *pcchActual
 ) AS LONG                                              ' HRESULT

%FACILITY_WINCODEC_ERR = &H898&
%WINCODEC_ERR_BASE = &H2000&

'#define MAKE_WINCODECHR(sev, code) MAKE_HRESULT(sev, FACILITY_WINCODEC_ERR, (WINCODEC_ERR_BASE + code))
MACRO MAKE_WINCODECHR(sev, code) = MAKE_HRESULT(sev, %FACILITY_WINCODEC_ERR, (%WINCODEC_ERR_BASE + code))
'#define MAKE_WINCODECHR_ERR(code) MAKE_WINCODECHR(1, code)
MACRO MAKE_WINCODECHR_ERR(code) = MAKE_WINCODECHR(1, code)

%WINCODEC_ERR_GENERIC_ERROR                    = %E_FAIL
%WINCODEC_ERR_INVALIDPARAMETER                 = %E_INVALIDARG
%WINCODEC_ERR_OUTOFMEMORY                      = %E_OUTOFMEMORY
%WINCODEC_ERR_NOTIMPLEMENTED                   = %E_NOTIMPL
%WINCODEC_ERR_ABORTED                          = %E_ABORT
%WINCODEC_ERR_ACCESSDENIED                     = %E_ACCESSDENIED
%WINCODEC_ERR_VALUEOVERFLOW                    = &H80070216&   ' %INTSAFE_E_ARITHMETIC_OVERFLOW

'#define WINCODEC_ERR_WRONGSTATE                       MAKE_WINCODECHR_ERR(0xf04)
'#define WINCODEC_ERR_VALUEOUTOFRANGE                  MAKE_WINCODECHR_ERR(0xf05)
'#define WINCODEC_ERR_UNKNOWNIMAGEFORMAT               MAKE_WINCODECHR_ERR(0xf07)
'#define WINCODEC_ERR_UNSUPPORTEDVERSION               MAKE_WINCODECHR_ERR(0xf0B)
'#define WINCODEC_ERR_NOTINITIALIZED                   MAKE_WINCODECHR_ERR(0xf0C)
'#define WINCODEC_ERR_ALREADYLOCKED                    MAKE_WINCODECHR_ERR(0xf0D)
'#define WINCODEC_ERR_PROPERTYNOTFOUND                 MAKE_WINCODECHR_ERR(0xf40)
'#define WINCODEC_ERR_PROPERTYNOTSUPPORTED             MAKE_WINCODECHR_ERR(0xf41)
'#define WINCODEC_ERR_PROPERTYSIZE                     MAKE_WINCODECHR_ERR(0xf42)
'#define WINCODEC_ERR_CODECPRESENT                     MAKE_WINCODECHR_ERR(0xf43)
'#define WINCODEC_ERR_CODECNOTHUMBNAIL                 MAKE_WINCODECHR_ERR(0xf44)
'#define WINCODEC_ERR_PALETTEUNAVAILABLE               MAKE_WINCODECHR_ERR(0xf45)
'#define WINCODEC_ERR_CODECTOOMANYSCANLINES            MAKE_WINCODECHR_ERR(0xf46)
'#define WINCODEC_ERR_INTERNALERROR                    MAKE_WINCODECHR_ERR(0xf48)
'#define WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS MAKE_WINCODECHR_ERR(0xf49)
'#define WINCODEC_ERR_COMPONENTNOTFOUND                MAKE_WINCODECHR_ERR(0xf50)
'#define WINCODEC_ERR_IMAGESIZEOUTOFRANGE              MAKE_WINCODECHR_ERR(0xf51)
'#define WINCODEC_ERR_TOOMUCHMETADATA                  MAKE_WINCODECHR_ERR(0xf52)
'#define WINCODEC_ERR_BADIMAGE                         MAKE_WINCODECHR_ERR(0xf60)
'#define WINCODEC_ERR_BADHEADER                        MAKE_WINCODECHR_ERR(0xf61)
'#define WINCODEC_ERR_FRAMEMISSING                     MAKE_WINCODECHR_ERR(0xf62)
'#define WINCODEC_ERR_BADMETADATAHEADER                MAKE_WINCODECHR_ERR(0xf63)
'#define WINCODEC_ERR_BADSTREAMDATA                    MAKE_WINCODECHR_ERR(0xf70)
'#define WINCODEC_ERR_STREAMWRITE                      MAKE_WINCODECHR_ERR(0xf71)
'#define WINCODEC_ERR_STREAMREAD                       MAKE_WINCODECHR_ERR(0xf72)
'#define WINCODEC_ERR_STREAMNOTAVAILABLE               MAKE_WINCODECHR_ERR(0xf73)
'#define WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT           MAKE_WINCODECHR_ERR(0xf80)
'#define WINCODEC_ERR_UNSUPPORTEDOPERATION             MAKE_WINCODECHR_ERR(0xf81)
'#define WINCODEC_ERR_INVALIDREGISTRATION              MAKE_WINCODECHR_ERR(0xf8A)
'#define WINCODEC_ERR_COMPONENTINITIALIZEFAILURE       MAKE_WINCODECHR_ERR(0xf8B)
'#define WINCODEC_ERR_INSUFFICIENTBUFFER               MAKE_WINCODECHR_ERR(0xf8C)
'#define WINCODEC_ERR_DUPLICATEMETADATAPRESENT         MAKE_WINCODECHR_ERR(0xf8D)
'#define WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE           MAKE_WINCODECHR_ERR(0xf8E)
'#define WINCODEC_ERR_UNEXPECTEDSIZE                   MAKE_WINCODECHR_ERR(0xf8F)
'#define WINCODEC_ERR_INVALIDQUERYREQUEST              MAKE_WINCODECHR_ERR(0xf90)
'#define WINCODEC_ERR_UNEXPECTEDMETADATATYPE           MAKE_WINCODECHR_ERR(0xf91)
'#define WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT   MAKE_WINCODECHR_ERR(0xf92)
'#define WINCODEC_ERR_INVALIDQUERYCHARACTER            MAKE_WINCODECHR_ERR(0xf93)
'#define WINCODEC_ERR_WIN32ERROR                       MAKE_WINCODECHR_ERR(0xf94)
'#define WINCODEC_ERR_INVALIDPROGRESSIVELEVEL          MAKE_WINCODECHR_ERR(0xf95)

%WINCODEC_ERR_WRONGSTATE                       = &H88982F04&
%WINCODEC_ERR_VALUEOUTOFRANGE                  = &H88982F05&
%WINCODEC_ERR_UNKNOWNIMAGEFORMAT               = &H88982F07&
%WINCODEC_ERR_UNSUPPORTEDVERSION               = &H88982F0B&
%WINCODEC_ERR_NOTINITIALIZED                   = &H88982F0C&
%WINCODEC_ERR_ALREADYLOCKED                    = &H88982F0D&
%WINCODEC_ERR_PROPERTYNOTFOUND                 = &H88982F40&
%WINCODEC_ERR_PROPERTYNOTSUPPORTED             = &H88982F41&
%WINCODEC_ERR_PROPERTYSIZE                     = &H88982F42&
%WINCODEC_ERR_CODECPRESENT                     = &H88982F43&
%WINCODEC_ERR_CODECNOTHUMBNAIL                 = &H88982F44&
%WINCODEC_ERR_PALETTEUNAVAILABLE               = &H88982F45&
%WINCODEC_ERR_CODECTOOMANYSCANLINES            = &H88982F46&
%WINCODEC_ERR_INTERNALERROR                    = &H88982F48&
%WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS = &H88982F49&
%WINCODEC_ERR_COMPONENTNOTFOUND                = &H88982F50&
%WINCODEC_ERR_IMAGESIZEOUTOFRANGE              = &H88982F51&
%WINCODEC_ERR_TOOMUCHMETADATA                  = &H88982F52&
%WINCODEC_ERR_BADIMAGE                         = &H88982F60&
%WINCODEC_ERR_BADHEADER                        = &H88982F61&
%WINCODEC_ERR_FRAMEMISSING                     = &H88982F62&
%WINCODEC_ERR_BADMETADATAHEADER                = &H88982F63&
%WINCODEC_ERR_BADSTREAMDATA                    = &H88982F70&
%WINCODEC_ERR_STREAMWRITE                      = &H88982F71&
%WINCODEC_ERR_STREAMREAD                       = &H88982F72&
%WINCODEC_ERR_STREAMNOTAVAILABLE               = &H88982F73&
%WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT           = &H88982F80&
%WINCODEC_ERR_UNSUPPORTEDOPERATION             = &H88982F81&
%WINCODEC_ERR_INVALIDREGISTRATION              = &H88982F8A&
%WINCODEC_ERR_COMPONENTINITIALIZEFAILURE       = &H88982F8B&
%WINCODEC_ERR_INSUFFICIENTBUFFER               = &H88982F8C&
%WINCODEC_ERR_DUPLICATEMETADATAPRESENT         = &H88982F8D&
%WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE           = &H88982F8E&
%WINCODEC_ERR_UNEXPECTEDSIZE                   = &H88982F8F&
%WINCODEC_ERR_INVALIDQUERYREQUEST              = &H88982F90&
%WINCODEC_ERR_UNEXPECTEDMETADATATYPE           = &H88982F91&
%WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT   = &H88982F92&
%WINCODEC_ERR_INVALIDQUERYCHARACTER            = &H88982F93&
%WINCODEC_ERR_WIN32ERROR                       = &H88982F94&
%WINCODEC_ERR_INVALIDPROGRESSIVELEVEL          = &H88982F95&

' enum WICTiffCompressionOption
%WICTiffCompressionDontCare           = 0???
%WICTiffCompressionNone               = &H1???
%WICTiffCompressionCCITT3             = &H2???
%WICTiffCompressionCCITT4             = &H3???
%WICTiffCompressionLZW                = &H4???
%WICTiffCompressionRLE                = &H5???
%WICTiffCompressionZIP                = &H6???
%WICTiffCompressionLZWHDifferencing   = &H7???
%WICTiffCOMPRESSIONOPTION_FORCE_DWORD = &H7fffffff???

' enum WICJpegYCrCbSubsamplingOption
%WICJpegYCrCbSubsamplingDefault      = 0???
%WICJpegYCrCbSubsampling420          = &H1???
%WICJpegYCrCbSubsampling422          = &H2???
%WICJpegYCrCbSubsampling444          = &H3???
%WICJPEGYCRCBSUBSAMPLING_FORCE_DWORD = &H7fffffff???

' enum WICPngFilterOption
%WICPngFilterUnspecified        = 0???
%WICPngFilterNone               = &H1???
%WICPngFilterSub                = &H2???
%WICPngFilterUp                 = &H3???
%WICPngFilterAverage            = &H4???
%WICPngFilterPaeth              = &H5???
%WICPngFilterAdaptive           = &H6???
%WICPNGFILTEROPTION_FORCE_DWORD = &H7fffffff???

' enum WICNamedWhitePoint
%WICWhitePointDefault           = &H1???
%WICWhitePointDaylight          = &H2???
%WICWhitePointCloudy            = &H4???
%WICWhitePointShade             = &H8???
%WICWhitePointTungsten          = &H10???
%WICWhitePointFluorescent       = &H20???
%WICWhitePointFlash             = &H40???
%WICWhitePointUnderwater        = &H80???
%WICWhitePointCustom            = &H100???
%WICWhitePointAutoWhiteBalance  = &H200???
%WICWhitePointAsShot            = %WICWhitePointDefault
%WICNAMEDWHITEPOINT_FORCE_DWORD = &H7fffffff???

' enum WICRawCapabilities
%WICRawCapabilityNotSupported   = 0???
%WICRawCapabilityGetSupported   = &H1???
%WICRawCapabilityFullySupported = &H2???
%WICRAWCAPABILITIES_FORCE_DWORD = &H7fffffff???

' enum WICRawRotationCapabilities
%WICRawRotationCapabilityNotSupported           = 0???
%WICRawRotationCapabilityGetSupported           = &H1???
%WICRawRotationCapabilityNinetyDegreesSupported = &H2???
%WICRawRotationCapabilityFullySupported         = &H3???
%WICRAWROTATIONCAPABILITIES_FORCE_DWORD         = &H7fffffff???

' // Size = 72 bytes
TYPE WICRawCapabilitiesInfo DWORD
   cbSize                         AS DWORD   ' UINT
   CodecMajorVersion              AS DWORD   ' UINT
   CodecMinorVersion              AS DWORD   ' UINT
   ExposureCompensationSupport    AS DWORD   ' WICRawCapabilities
   ContrastSupport                AS DWORD   ' WICRawCapabilities
   RGBWhitePointSupport           AS DWORD   ' WICRawCapabilities
   NamedWhitePointSupport         AS DWORD   ' WICRawCapabilities
   NamedWhitePointSupportMask     AS DWORD   ' UINT
   KelvinWhitePointSupport        AS DWORD   ' WICRawCapabilities
   GammaSupport                   AS DWORD   ' WICRawCapabilities
   TintSupport                    AS DWORD   ' WICRawCapabilities
   SaturationSupport              AS DWORD   ' WICRawCapabilities
   SharpnessSupport               AS DWORD   ' WICRawCapabilities
   NoiseReductionSupport          AS DWORD   ' WICRawCapabilities
   DestinationColorProfileSupport AS DWORD   ' WICRawCapabilities
   ToneCurveSupport               AS DWORD   ' WICRawCapabilities
   RotationSupport                AS DWORD   ' WICRawRotationCapabilities
   RenderModeSupport              AS DWORD   ' WICRawCapabilities
END TYPE

' enum WICRawParameterSet
%WICAsShotParameterSet          = &H1???
%WICUserAdjustedParameterSet    = &H2???
%WICAutoAdjustedParameterSet    = &H3???
%WICRAWPARAMETERSET_FORCE_DWORD = &H7fffffff???

' enum WICRawRenderMode
%WICRawRenderModeDraft        = &H1???
%WICRawRenderModeNormal       = &H2???
%WICRawRenderModeBestQuality  = &H3???
%WICRAWRENDERMODE_FORCE_DWORD = &H7fffffff???

' // Size = 16 bytes
TYPE WICRawToneCurvePoint   ' Must be 8 byte aligned
   Input  AS DOUBLE
   Output AS DOUBLE
END TYPE

' // Size = 24 bytes
TYPE WICRawToneCurve   ' Must be 8 byte aligned
   cPoints     AS DWORD                  ' UINT
   alignment__ AS DWORD                  ' // To keep 8 byte alignment
   aPoints(0)  AS WICRawToneCurvePoint   ' WICRawToneCurvePoint aPoints[ 1 ]
END TYPE

%WICRawChangeNotification_ExposureCompensation    = &H00000001???
%WICRawChangeNotification_NamedWhitePoint         = &H00000002???
%WICRawChangeNotification_KelvinWhitePoint        = &H00000004???
%WICRawChangeNotification_RGBWhitePoint           = &H00000008???
%WICRawChangeNotification_Contrast                = &H00000010???
%WICRawChangeNotification_Gamma                   = &H00000020???
%WICRawChangeNotification_Sharpness               = &H00000040???
%WICRawChangeNotification_Saturation              = &H00000080???
%WICRawChangeNotification_Tint                    = &H00000100???
%WICRawChangeNotification_NoiseReduction          = &H00000200???
%WICRawChangeNotification_DestinationColorContext = &H00000400???
%WICRawChangeNotification_ToneCurve               = &H00000800???
%WICRawChangeNotification_Rotation                = &H00001000???
%WICRawChangeNotification_RenderMode              = &H00002000???


' ########################################################################################
' IWICDevelopRawNotificationCallback interface
' IID = 95C75A6E-3E8C-4EC2-85A8-AEBCC551E59B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWICDevelopRawNotificationCallback_INTERFACE_DEFINED)
    %IWICDevelopRawNotificationCallback_INTERFACE_DEFINED = 1

$IID_IWICDevelopRawNotificationCallback = GUID$("{95C75A6E-3E8C-4EC2-85A8-AEBCC551E59B}")

INTERFACE IWICDevelopRawNotificationCallback $IID_IWICDevelopRawNotificationCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
     BYVAL NotificationMask AS DWORD _                  ' __in UINT NotificationMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICDevelopRawNotificationCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IWICDevelopRaw interface
' IID = FBEC5E44-F7BE-4B65-B7F8-C0C81FEF026D
' Inherited interface = IWICBitmapFrameDecode
' ########################################################################################

#IF NOT %DEF(%IWICDevelopRaw_INTERFACE_DEFINED)
    %IWICDevelopRaw_INTERFACE_DEFINED = 1

$IID_IWICDevelopRaw = GUID$("{FBEC5E44-F7BE-4B65-B7F8-C0C81FEF026D}")

INTERFACE IWICDevelopRaw $IID_IWICDevelopRaw

   INHERIT IUnknown

   ' =====================================================================================
   ' IWICBitmapSource Methods
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 12
     BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPixelFormat ( _                            ' VTable offset = 16
     BYREF pPixelFormat AS GUID _                       ' __out WICPixelFormatGUID *pPixelFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResolution ( _                             ' VTable offset = 20
     BYREF pDpiX AS DOUBLE _                            ' __out double *pDpiX
   , BYREF pDpiY AS DOUBLE _                            ' __out double *pDpiY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPalette ( _                               ' VTable offset = 24
     BYVAL pIPalette AS IWICPalette _                   ' __in IWICPalette *pIPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyPixels ( _                                ' VTable offset = 28
     BYREF prc AS WICRect _                             ' __in const WICRect *prc
   , BYVAL cbStride AS DWORD _                          ' __in UINT cbStride
   , BYVAL cbBufferSize AS DWORD _                      ' __in UINT cbBufferSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICBitmapFrameDecode Methods
   ' =====================================================================================
   METHOD GetMetadataQueryReader ( _                    ' VTable offset = 32
     BYREF ppIMetadataQueryReader AS IWICMetadataQueryReader _ ' __out IWICMetadataQueryReader **ppIMetadataQueryReader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorContexts ( _                          ' VTable offset = 36
     BYVAL cCount AS DWORD _                            ' __in UINT cCount
   , BYREF ppIColorContexts AS IWICColorContext _       ' __inout IWICColorContext **ppIColorContexts
   , BYREF pcActualCount AS DWORD _                     ' __out UINT *pcActualCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 40
     BYREF ppIThumbnail AS IWICBitmapSource _           ' __out IWICBitmapSource **ppIThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWICDevelopRaw Methods
   ' =====================================================================================
   METHOD QueryRawCapabilitiesInfo ( _                  ' VTable offset = 44
     BYREF pInfo AS WICRawCapabilitiesInfo _            ' __out WICRawCapabilitiesInfo *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadParameterSet ( _                          ' VTable offset = 48
     BYVAL ParameterSet AS DWORD _                      ' __in WICRawParameterSet ParameterSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentParameterSet ( _                    ' VTable offset = 52
     BYREF ppCurrentParameterSet AS IPropertyBag2 _     ' __out IPropertyBag2 **ppCurrentParameterSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExposureCompensation ( _                   ' VTable offset = 56
     BYVAL ev AS DOUBLE _                               ' __in double ev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExposureCompensation ( _                   ' VTable offset = 60
     BYREF pEV AS DOUBLE _                              ' __out double *pEV
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWhitePointRGB ( _                          ' VTable offset = 64
     BYVAL Red AS DWORD _                               ' __in UINT Red
   , BYVAL Green AS DWORD _                             ' __in UINT Green
   , BYVAL Blue AS DWORD _                              ' __in UINT Blue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWhitePointRGB ( _                          ' VTable offset = 68
     BYREF pRed AS DWORD _                              ' __out UINT *pRed
   , BYREF pGreen AS DWORD _                            ' __out UINT *pGreen
   , BYREF pBlue AS DWORD _                             ' __out UINT *pBlue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNamedWhitePoint ( _                        ' VTable offset = 72
     BYVAL WhitePoint AS DWORD _                        ' __in WICNamedWhitePoint WhitePoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamedWhitePoint ( _                        ' VTable offset = 76
     BYREF pWhitePoint AS DWORD _                       ' __out WICNamedWhitePoint *pWhitePoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWhitePointKelvin ( _                       ' VTable offset = 80
     BYVAL WhitePointKelvin AS DWORD _                  ' __in UINT WhitePointKelvin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWhitePointKelvin ( _                       ' VTable offset = 84
     BYREF pWhitePointKelvin AS DWORD _                 ' __out UINT *pWhitePointKelvin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKelvinRangeInfo ( _                        ' VTable offset = 88
     BYREF pMinKelvinTemp AS DWORD _                    ' __out UINT *pMinKelvinTemp
   , BYREF pMaxKelvinTemp AS DWORD _                    ' __out UINT *pMaxKelvinTemp
   , BYREF pKelvinTempStepValue AS DWORD _              ' __out UINT *pKelvinTempStepValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContrast ( _                               ' VTable offset = 92
     BYVAL Contrast AS DOUBLE _                         ' __in double Contrast
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContrast ( _                               ' VTable offset = 96
     BYREF pContrast AS DOUBLE _                        ' __out double *pContrast
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGamma ( _                                  ' VTable offset = 100
     BYVAL Gamma AS DOUBLE _                            ' __in double Gamma
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGamma ( _                                  ' VTable offset = 104
     BYREF pGamma AS DOUBLE _                           ' __out double *pGamma
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSharpness ( _                              ' VTable offset = 108
     BYVAL Sharpness AS DOUBLE _                        ' __in double Sharpness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSharpness ( _                              ' VTable offset = 112
     BYREF pSharpness AS DOUBLE _                       ' __out double *pSharpness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSaturation ( _                             ' VTable offset = 116
     BYVAL Saturation AS DOUBLE _                       ' __in double Saturation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSaturation ( _                             ' VTable offset = 120
     BYREF pSaturation AS DOUBLE _                      ' __out double *pSaturation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTint ( _                                   ' VTable offset = 124
     BYVAL Tint AS DOUBLE _                             ' __in double Tint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTint ( _                                   ' VTable offset = 128
     BYREF pTint AS DOUBLE _                            ' __out double *pTint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNoiseReduction ( _                         ' VTable offset = 132
     BYVAL NoiseReduction AS DOUBLE _                   ' __in double NoiseReduction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNoiseReduction ( _                         ' VTable offset = 136
     BYREF pNoiseReduction AS DOUBLE _                  ' __out double *pNoiseReduction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDestinationColorContext ( _                ' VTable offset = 140
     BYVAL pColorContext AS IWICColorContext _          ' __in const IWICColorContext *pColorContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetToneCurve ( _                              ' VTable offset = 144
     BYVAL cbToneCurveSize AS DWORD _                   ' __in UINT cbToneCurveSize
   , BYREF pToneCurve AS WICRawToneCurve _              ' __in const WICRawToneCurve *pToneCurve
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToneCurve ( _                              ' VTable offset = 148
     BYVAL cbToneCurveBufferSize AS DWORD _             ' __in UINT cbToneCurveBufferSize
   , BYREF pToneCurve AS WICRawToneCurve _              ' __out WICRawToneCurve *pToneCurve
   , BYREF pcbActualToneCurveBufferSize AS DWORD _      ' __out UINT *pcbActualToneCurveBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRotation ( _                               ' VTable offset = 152
     BYVAL Rotation AS DOUBLE _                         ' __in double Rotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRotation ( _                               ' VTable offset = 156
     BYREF pRotation AS DOUBLE _                        ' __out double *pRotation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderMode ( _                             ' VTable offset = 160
     BYVAL RenderMode AS DWORD _                        ' __in WICRawRenderMode RenderMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderMode ( _                             ' VTable offset = 164
     BYREF pRenderMode AS DWORD _                       ' __out WICRawRenderMode *pRenderMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotificationCallback ( _                   ' VTable offset = 168
     BYVAL pCallback AS IWICDevelopRawNotificationCallback _ ' __in IWICDevelopRawNotificationCallback *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWICDevelopRaw_INTERFACE_DEFINED__ */
