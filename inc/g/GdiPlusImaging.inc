' ########################################################################################
' Microsoft Windows
' File: GdiPlusImaging.inc
' Contents: GDI+ Imaging GUIDs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSIMAGING_INC = 1

'//---------------------------------------------------------------------------
'// Image file format identifiers
'//---------------------------------------------------------------------------

$ImageFormatUndefined     = GUID$("{B96B3CA9-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatMemoryBMP     = GUID$("{B96B3CAA-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatBMP           = GUID$("{B96B3CAB-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatEMF           = GUID$("{B96B3CAC-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatWMF           = GUID$("{B96B3CAD-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatJPEG          = GUID$("{B96B3CAE-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatPNG           = GUID$("{B96B3CAF-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatGIF           = GUID$("{B96B3CB0-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatTIFF          = GUID$("{B96B3CB1-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatEXIF          = GUID$("{B96B3CB2-0728-11D3-9D7B-0000F81EF32E}")
$ImageFormatIcon          = GUID$("{B96B3CB5-0728-11D3-9D7B-0000F81EF32E}")

'//---------------------------------------------------------------------------
'// Predefined multi-frame dimension IDs
'//---------------------------------------------------------------------------

$FrameDimensionTime       = GUID$("{6AEDBD6D-3FB5-418A-83A6-7F45229DC872}")
$FrameDimensionResolution = GUID$("{84236F7B-3BD3-428F-8DAB-4EA1439CA315}")
$FrameDimensionPage       = GUID$("{7462DC86-6180-4C7E-8E3F-EE7333A7A483}")

'//---------------------------------------------------------------------------
'// Property sets
'//---------------------------------------------------------------------------

$FormatIDImageInformation = GUID$("{E5836CBE-5EEF-0F1D-ACDE-AE4C43B608CE}")
$FormatIDJpegAppHeaders   = GUID$("{1C4AFDCD-6177-43CF-ABC7-5F51AF39EE85}")

'//---------------------------------------------------------------------------
'// Encoder parameter sets
'//---------------------------------------------------------------------------

$EncoderCompression       = GUID$("{E09D739D-CCD4-44EE-8EBA-3FBF8BE4FC58}")
$EncoderColorDepth        = GUID$("{66087055-AD66-4C7C-9A18-38A2310B8337}")
$EncoderScanMethod        = GUID$("{3A4E2661-3109-4E56-8536-42C156E7DCFA}")
$EncoderVersion           = GUID$("{24D18C76-814A-41A4-BF53-1C219CCCF797}")
$EncoderRenderMethod      = GUID$("{6D42C53A-229A-4825-8BB7-5C99E2B9A8B8}")
$EncoderQuality           = GUID$("{1D5BE4B5-FA4A-452D-9CDD-5DB35105E7EB}")
$EncoderTransformation    = GUID$("{8D0EB2D1-A58E-4EA8-AA14-108074B7B6F9}")
$EncoderLuminanceTable    = GUID$("{EDB33BCE-0266-4A77-B904-27216099E717}")
$EncoderChrominanceTable  = GUID$("{F2E455DC-09B3-4316-8260-676ADA32481C}")
$EncoderSaveFlag          = GUID$("{292266FC-AC40-47BF-8CFC-A85B89A655DE}")

#IF (%GDIPVER >= &H0110)
$EncoderColorSpace        = GUID$("{AE7A62A0-EE2C-49D8-9D07-1BA8A927596E}")
$EncoderImageItems        = GUID$("{63875E13-1F1D-45AB-9195-A29B6066A650}")
$EncoderSaveAsCMYK        = GUID$("{A219BBC9-0A9D-4005-A3EE-3A421B8BB06C}")
#ENDIF   ' //(%GDIPVER >= &H0110)

$CodecIImageBytes         = GUID$("{025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC}")


' ########################################################################################
' Interface name = IImageBytes
' IID = 025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC
' Inherited interface = IUnknown
' ########################################################################################

$IID_IImageBytes = GUID$("{025D1823-6C7D-447B-BBDB-A3CBC3DFA2FC}")

INTERFACE IImageBytes $IID_IImageBytes

   INHERIT IDispatch

   ' =====================================================================================
   METHOD CountBytes ( _                                ' VTable offset = 12
     BYREF pcb AS DWORD _                               ' __out UINT *pcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockBytes ( _                                 ' VTable offset = 16
     BYVAL cb AS DWORD _                                ' __in  UINT cb
   , BYVAL ulOffset AS DWORD _                          ' __in  ULONG ulOffset
   , BYREF ppvBytes AS DWORD _                          ' __out const VOID ** ppvBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockBytes ( _                               ' VTable offset = 20
     BYVAL pvBytes AS DWORD _                           ' __in  const VOID *pvBytes
   , BYVAL cb AS DWORD _                                ' __in  UINT cb
   , BYVAL ulOffset AS DWORD _                          ' __in  ULONG ulOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'//--------------------------------------------------------------------------
'// ImageCodecInfo structure
'//--------------------------------------------------------------------------

' // Size = 76 bytes
TYPE ImageCodecInfo DWORD
   Clsid             AS GUID           ' CLSID
   FormatID          AS GUID           ' GUID
   CodecName         AS WSTRINGZ PTR   ' const WCHAR*
   DllName           AS WSTRINGZ PTR   ' const WCHAR*
   FormatDescription AS WSTRINGZ PTR   ' const WCHAR*
   FilenameExtension AS WSTRINGZ PTR   ' const WCHAR*
   MimeType          AS WSTRINGZ PTR   ' const WCHAR*
   Flags             AS DWORD          ' DWORD
   Version           AS DWORD          ' DWORD
   SigCount          AS DWORD          ' DWORD
   SigSize           AS DWORD          ' DWORD
   SigPattern        AS BYTE PTR       ' const BYTE*
   SigMask           AS BYTE PTR       ' const BYTE*
END TYPE

'//--------------------------------------------------------------------------
'// Information flags about image codecs
'//--------------------------------------------------------------------------

' enum ImageCodecFlags
%ImageCodecFlagsEncoder            = &H00000001???
%ImageCodecFlagsDecoder            = &H00000002???
%ImageCodecFlagsSupportBitmap      = &H00000004???
%ImageCodecFlagsSupportVector      = &H00000008???
%ImageCodecFlagsSeekableEncode     = &H00000010???
%ImageCodecFlagsBlockingDecode     = &H00000020???

%ImageCodecFlagsBuiltin            = &H00010000???
%ImageCodecFlagsSystem             = &H00020000???
%ImageCodecFlagsUser               = &H00040000???

'//---------------------------------------------------------------------------
'// Access modes used when calling Image::LockBits
'//---------------------------------------------------------------------------

' enum ImageLockMode
%ImageLockModeRead         = &H0001???
%ImageLockModeWrite        = &H0002???
%ImageLockModeUserInputBuf = &H0004???

'//---------------------------------------------------------------------------
'// Information about image pixel data
'//---------------------------------------------------------------------------

' // Size = 24 bytes
TYPE BitmapData DWORD
   Width       AS DWORD   ' UINT
   Height      AS DWORD   ' UINT
   Stride      AS LONG    ' INT
   PixelFormat AS LONG    ' PixelFormat
   Scan0       AS DWORD   ' VOID*
   Reserved    AS DWORD   ' UINT_PTR
END TYPE

'//---------------------------------------------------------------------------
'// Image flags
'//---------------------------------------------------------------------------

' enum ImageFlags

%ImageFlagsNone                = 0

'// Low-word: shared with SINKFLAG_x

%ImageFlagsScalable            = &H0001???
%ImageFlagsHasAlpha            = &H0002???
%ImageFlagsHasTranslucent      = &H0004???
%ImageFlagsPartiallyScalable   = &H0008???

'// Low-word: color space definition

%ImageFlagsColorSpaceRGB       = &H0010???
%ImageFlagsColorSpaceCMYK      = &H0020???
%ImageFlagsColorSpaceGRAY      = &H0040???
%ImageFlagsColorSpaceYCBCR     = &H0080???
%ImageFlagsColorSpaceYCCK      = &H0100???

'// Low-word: image size info

%ImageFlagsHasRealDPI          = &H1000???
%ImageFlagsHasRealPixelSize    = &H2000???

'// High-word

%ImageFlagsReadOnly            = &H00010000???
%ImageFlagsCaching             = &H00020000???


' enum RotateFlipType

%RotateNoneFlipNone = 0
%Rotate90FlipNone   = 1
%Rotate180FlipNone  = 2
%Rotate270FlipNone  = 3

%RotateNoneFlipX    = 4
%Rotate90FlipX      = 5
%Rotate180FlipX     = 6
%Rotate270FlipX     = 7

%RotateNoneFlipY    = %Rotate180FlipX
%Rotate90FlipY      = %Rotate270FlipX
%Rotate180FlipY     = %RotateNoneFlipX
%Rotate270FlipY     = %Rotate90FlipX

%RotateNoneFlipXY   = %Rotate180FlipNone
%Rotate90FlipXY     = %Rotate270FlipNone
%Rotate180FlipXY    = %RotateNoneFlipNone
%Rotate270FlipXY    = %Rotate90FlipNone

'//---------------------------------------------------------------------------
'// Encoder Parameter structure
'//---------------------------------------------------------------------------

' // Size = 28 bytes
TYPE EncoderParameter DWORD
   pGuid          AS GUID    '  // GUID of the parameter
   NumberOfValues AS DWORD   '  // Number of the parameter values
   dwType         AS DWORD   '  // Value type, like ValueTypeLONG  etc.
   Value          AS DWORD   '  // A pointer to the parameter values
END TYPE

'//---------------------------------------------------------------------------
'// Encoder Parameters structure
'//---------------------------------------------------------------------------

' // Size = 32 bytes
TYPE EncoderParameters   DWORD
   Count        AS DWORD             ' // Number of parameters in this structure
   Parameter(0) AS EncoderParameter  ' // Parameter values - variable-length array
END TYPE

#IF (%GDIPVER >= &H0110)
' enum ItemDataPosition
%ItemDataPositionAfterHeader    = &H0???
%ItemDataPositionAfterPalette   = &H1???
%ItemDataPositionAfterBits      = &H2???

'//---------------------------------------------------------------------------
'// External Data Item
'//---------------------------------------------------------------------------
' // Size = 28 bytes
TYPE ImageItemData DWORD
   Size     AS DWORD      ' UINT  // size of the structure
   Position AS DWORD      ' UINT  // flags describing how the data is to be used.
   Desc     AS DWORD      ' VOID* // description on how the data is to be saved.
                          '       // it is different for every codec type.
   DescSize AS DWORD      ' UINT  // size memory pointed by Desc
   Data     AS DWORD      ' VOID* // pointer to the data that is to be saved in the
                          '       // file, could be anything saved directly.
   DataSize AS DWORD      ' UINT  // size memory pointed by Data
   Cookie   AS DWORD      ' UINT  // opaque for the apps data member used during
                          '       // enumeration of image data items.
END TYPE
#ENDIF   ' //(%GDIPVER >= &H0110)

'//---------------------------------------------------------------------------
'// Property Item
'//---------------------------------------------------------------------------

' // Size = 16 bytes
TYPE PropertyItem DWORD       '  // Must be DWORD aligned
   id     AS DWORD            '  // ID of this property
   length AS DWORD            '  // Length of the property value, in bytes
   type   AS WORD             '  // Type of the value, as one of PropertyTagxxx defined below
   value  AS DWORD            '  // property value
END TYPE

'//---------------------------------------------------------------------------
'// Image property types
'//---------------------------------------------------------------------------

%PropertyTagTypeByte       = 1
%PropertyTagTypeASCII      = 2
%PropertyTagTypeShort      = 3
%PropertyTagTypeLong       = 4
%PropertyTagTypeRational   = 5
%PropertyTagTypeUndefined  = 7
%PropertyTagTypeSLONG      = 9
%PropertyTagTypeSRational  = 10

'//---------------------------------------------------------------------------
'// Image property ID tags
'//---------------------------------------------------------------------------

%PropertyTagExifIFD                = &H8769???
%PropertyTagGpsIFD                 = &H8825???

%PropertyTagNewSubfileType         = &H00FE???
%PropertyTagSubfileType            = &H00FF???
%PropertyTagImageWidth             = &H0100???
%PropertyTagImageHeight            = &H0101???
%PropertyTagBitsPerSample          = &H0102???
%PropertyTagCompression            = &H0103???
%PropertyTagPhotometricInterp      = &H0106???
%PropertyTagThreshHolding          = &H0107???
%PropertyTagCellWidth              = &H0108???
%PropertyTagCellHeight             = &H0109???
%PropertyTagFillOrder              = &H010A???
%PropertyTagDocumentName           = &H010D???
%PropertyTagImageDescription       = &H010E???
%PropertyTagEquipMake              = &H010F???
%PropertyTagEquipModel             = &H0110???
%PropertyTagStripOffsets           = &H0111???
%PropertyTagOrientation            = &H0112???
%PropertyTagSamplesPerPixel        = &H0115???
%PropertyTagRowsPerStrip           = &H0116???
%PropertyTagStripBytesCount        = &H0117???
%PropertyTagMinSampleValue         = &H0118???
%PropertyTagMaxSampleValue         = &H0119???
%PropertyTagXResolution            = &H011A???  ' // Image resolution in width direction
%PropertyTagYResolution            = &H011B???  ' // Image resolution in height direction
%PropertyTagPlanarConfig           = &H011C???  ' // Image data arrangement
%PropertyTagPageName               = &H011D???
%PropertyTagXPosition              = &H011E???
%PropertyTagYPosition              = &H011F???
%PropertyTagFreeOffset             = &H0120???
%PropertyTagFreeByteCounts         = &H0121???
%PropertyTagGrayResponseUnit       = &H0122???
%PropertyTagGrayResponseCurve      = &H0123???
%PropertyTagT4Option               = &H0124???
%PropertyTagT6Option               = &H0125???
%PropertyTagResolutionUnit         = &H0128???  ' // Unit of and Y resolution
%PropertyTagPageNumber             = &H0129???
%PropertyTagTransferFunction       = &H012D???
%PropertyTagSoftwareUsed           = &H0131???
%PropertyTagDateTime               = &H0132???
%PropertyTagArtist                 = &H013B???
%PropertyTagHostComputer           = &H013C???
%PropertyTagPredictor              = &H013D???
%PropertyTagWhitePoint             = &H013E???
%PropertyTagPrimaryChromaticities  = &H013F???
%PropertyTagColorMap               = &H0140???
%PropertyTagHalftoneHints          = &H0141???
%PropertyTagTileWidth              = &H0142???
%PropertyTagTileLength             = &H0143???
%PropertyTagTileOffset             = &H0144???
%PropertyTagTileByteCounts         = &H0145???
%PropertyTagInkSet                 = &H014C???
%PropertyTagInkNames               = &H014D???
%PropertyTagNumberOfInks           = &H014E???
%PropertyTagDotRange               = &H0150???
%PropertyTagTargetPrinter          = &H0151???
%PropertyTagExtraSamples           = &H0152???
%PropertyTagSampleFormat           = &H0153???
%PropertyTagSMinSampleValue        = &H0154???
%PropertyTagSMaxSampleValue        = &H0155???
%PropertyTagTransferRange          = &H0156???

%PropertyTagJPEGProc               = &H0200???
%PropertyTagJPEGInterFormat        = &H0201???
%PropertyTagJPEGInterLength        = &H0202???
%PropertyTagJPEGRestartInterval    = &H0203???
%PropertyTagJPEGLosslessPredictors = &H0205???
%PropertyTagJPEGPointTransforms    = &H0206???
%PropertyTagJPEGQTables            = &H0207???
%PropertyTagJPEGDCTables           = &H0208???
%PropertyTagJPEGACTables           = &H0209???

%PropertyTagYCbCrCoefficients      = &H0211???
%PropertyTagYCbCrSubsampling       = &H0212???
%PropertyTagYCbCrPositioning       = &H0213???
%PropertyTagREFBlackWhite          = &H0214???

%PropertyTagICCProfile             = &H8773???  ' // This TAG is defined by ICC for embedded ICC in TIFF
%PropertyTagGamma                  = &H0301???
%PropertyTagICCProfileDescriptor   = &H0302???
%PropertyTagSRGBRenderingIntent    = &H0303???

%PropertyTagImageTitle             = &H0320???
%PropertyTagCopyright              = &H8298???

'// Extra TAGs (Like Adobe Image Information tags etc.)

%PropertyTagResolutionXUnit           = &H5001???
%PropertyTagResolutionYUnit           = &H5002???
%PropertyTagResolutionXLengthUnit     = &H5003???
%PropertyTagResolutionYLengthUnit     = &H5004???
%PropertyTagPrintFlags                = &H5005???
%PropertyTagPrintFlagsVersion         = &H5006???
%PropertyTagPrintFlagsCrop            = &H5007???
%PropertyTagPrintFlagsBleedWidth      = &H5008???
%PropertyTagPrintFlagsBleedWidthScale = &H5009???
%PropertyTagHalftoneLPI               = &H500A???
%PropertyTagHalftoneLPIUnit           = &H500B???
%PropertyTagHalftoneDegree            = &H500C???
%PropertyTagHalftoneShape             = &H500D???
%PropertyTagHalftoneMisc              = &H500E???
%PropertyTagHalftoneScreen            = &H500F???
%PropertyTagJPEGQuality               = &H5010???
%PropertyTagGridSize                  = &H5011???
%PropertyTagThumbnailFormat           = &H5012??? ' // 1 = JPEG, 0 = RAW RGB
%PropertyTagThumbnailWidth            = &H5013???
%PropertyTagThumbnailHeight           = &H5014???
%PropertyTagThumbnailColorDepth       = &H5015???
%PropertyTagThumbnailPlanes           = &H5016???
%PropertyTagThumbnailRawBytes         = &H5017???
%PropertyTagThumbnailSize             = &H5018???
%PropertyTagThumbnailCompressedSize   = &H5019???
%PropertyTagColorTransferFunction     = &H501A???
%PropertyTagThumbnailData             = &H501B???  '   // RAW thumbnail bits in
                                                '   // JPEG format or RGB format
                                                '   // depends on
                                                '   // PropertyTagThumbnailFormat

'// Thumbnail related TAGs

%PropertyTagThumbnailImageWidth        = &H5020??? ' // Thumbnail width
%PropertyTagThumbnailImageHeight       = &H5021??? ' // Thumbnail height
%PropertyTagThumbnailBitsPerSample     = &H5022??? ' // Number of bits per component
%PropertyTagThumbnailCompression       = &H5023??? ' // Compression Scheme
%PropertyTagThumbnailPhotometricInterp = &H5024??? ' // Pixel composition
%PropertyTagThumbnailImageDescription  = &H5025??? ' // Image Tile
%PropertyTagThumbnailEquipMake         = &H5026??? ' // Manufacturer of Image Input equipment
%PropertyTagThumbnailEquipModel        = &H5027??? ' // Model of Image input equipment
%PropertyTagThumbnailStripOffsets      = &H5028??? ' // Image data location
%PropertyTagThumbnailOrientation       = &H5029??? ' // Orientation of image
%PropertyTagThumbnailSamplesPerPixel   = &H502A??? ' // Number of components
%PropertyTagThumbnailRowsPerStrip      = &H502B??? ' // Number of rows per strip
%PropertyTagThumbnailStripBytesCount   = &H502C??? ' // Bytes per compressed strip
%PropertyTagThumbnailResolutionX       = &H502D??? ' // Resolution in width direction
%PropertyTagThumbnailResolutionY       = &H502E??? ' // Resolution in height direction
%PropertyTagThumbnailPlanarConfig      = &H502F??? ' // Image data arrangement
%PropertyTagThumbnailResolutionUnit    = &H5030??? ' // Unit of and Y Resolution
%PropertyTagThumbnailTransferFunction  = &H5031??? ' // Transfer function
%PropertyTagThumbnailSoftwareUsed      = &H5032??? ' // Software used
%PropertyTagThumbnailDateTime          = &H5033??? ' // File change date and time
%PropertyTagThumbnailArtist            = &H5034??? ' // Person who created the image
%PropertyTagThumbnailWhitePoint        = &H5035??? ' // White point chromaticity
%PropertyTagThumbnailPrimaryChromaticities = &H5036???
                                               '      // Chromaticities of primaries
%PropertyTagThumbnailYCbCrCoefficients = &H5037??? ' // Color space transformation coefficients
%PropertyTagThumbnailYCbCrSubsampling  = &H5038??? ' // Subsampling ratio of Y to C
%PropertyTagThumbnailYCbCrPositioning  = &H5039??? ' // Y and C position
%PropertyTagThumbnailRefBlackWhite     = &H503A??? ' // Pair of black and white reference values
%PropertyTagThumbnailCopyRight         = &H503B??? ' // CopyRight holder

%PropertyTagLuminanceTable             = &H5090???
%PropertyTagChrominanceTable           = &H5091???

%PropertyTagFrameDelay                 = &H5100???
%PropertyTagLoopCount                  = &H5101???

#IF (%GDIPVER >= &H0110)
%PropertyTagGlobalPalette              = &H5102???
%PropertyTagIndexBackground            = &H5103???
%PropertyTagIndexTransparent           = &H5104???
#ENDIF   ' //(%GDIPVER >= &H0110)

%PropertyTagPixelUnit          = &H5110??? ' // Unit specifier for pixel/unit
%PropertyTagPixelPerUnitX      = &H5111??? ' // Pixels per unit in X
%PropertyTagPixelPerUnitY      = &H5112??? ' // Pixels per unit in Y
%PropertyTagPaletteHistogram   = &H5113??? ' // Palette histogram

'// EXIF specific tag

%PropertyTagExifExposureTime   = &H829A???
%PropertyTagExifFNumber        = &H829D???

%PropertyTagExifExposureProg   = &H8822???
%PropertyTagExifSpectralSense  = &H8824???
%PropertyTagExifISOSpeed       = &H8827???
%PropertyTagExifOECF           = &H8828???

%PropertyTagExifVer            = &H9000???
%PropertyTagExifDTOrig         = &H9003??? ' // Date & time of original
%PropertyTagExifDTDigitized    = &H9004??? ' // Date & time of digital data generation

%PropertyTagExifCompConfig     = &H9101???
%PropertyTagExifCompBPP        = &H9102???

%PropertyTagExifShutterSpeed   = &H9201???
%PropertyTagExifAperture       = &H9202???
%PropertyTagExifBrightness     = &H9203???
%PropertyTagExifExposureBias   = &H9204???
%PropertyTagExifMaxAperture    = &H9205???
%PropertyTagExifSubjectDist    = &H9206???
%PropertyTagExifMeteringMode   = &H9207???
%PropertyTagExifLightSource    = &H9208???
%PropertyTagExifFlash          = &H9209???
%PropertyTagExifFocalLength    = &H920A???
%PropertyTagExifMakerNote      = &H927C???
%PropertyTagExifUserComment    = &H9286???
%PropertyTagExifDTSubsec       = &H9290??? ' // Date & Time subseconds
%PropertyTagExifDTOrigSS       = &H9291??? ' // Date & Time original subseconds
%PropertyTagExifDTDigSS        = &H9292??? ' // Date & TIme digitized subseconds

%PropertyTagExifFPXVer         = &HA000???
%PropertyTagExifColorSpace     = &HA001???
%PropertyTagExifPixXDim        = &HA002???
%PropertyTagExifPixYDim        = &HA003???
%PropertyTagExifRelatedWav     = &HA004??? ' // related sound file
%PropertyTagExifInterop        = &HA005???
%PropertyTagExifFlashEnergy    = &HA20B???
%PropertyTagExifSpatialFR      = &HA20C??? ' // Spatial Frequency Response
%PropertyTagExifFocalXRes      = &HA20E??? ' // Focal Plane Resolution
%PropertyTagExifFocalYRes      = &HA20F??? ' // Focal Plane Y Resolution
%PropertyTagExifFocalResUnit   = &HA210??? ' // Focal Plane Resolution Unit
%PropertyTagExifSubjectLoc     = &HA214???
%PropertyTagExifExposureIndex  = &HA215???
%PropertyTagExifSensingMethod  = &HA217???
%PropertyTagExifFileSource     = &HA300???
%PropertyTagExifSceneType      = &HA301???
%PropertyTagExifCfaPattern     = &HA302???

'// New EXIF 2.2 properties

%PropertyTagExifCustomRendered        = &HA401???
%PropertyTagExifExposureMode          = &HA402???
%PropertyTagExifWhiteBalance          = &HA403???
%PropertyTagExifDigitalZoomRatio      = &HA404???
%PropertyTagExifFocalLengthIn35mmFilm = &HA405???
%PropertyTagExifSceneCaptureType      = &HA406???
%PropertyTagExifGainControl           = &HA407???
%PropertyTagExifContrast              = &HA408???
%PropertyTagExifSaturation            = &HA409???
%PropertyTagExifSharpness             = &HA40A???
%PropertyTagExifDeviceSettingDesc     = &HA40B???
%PropertyTagExifSubjectDistanceRange  = &HA40C???
%PropertyTagExifUniqueImageID         = &HA420???

%PropertyTagGpsVer              = &H0000???
%PropertyTagGpsLatitudeRef      = &H0001???
%PropertyTagGpsLatitude         = &H0002???
%PropertyTagGpsLongitudeRef     = &H0003???
%PropertyTagGpsLongitude        = &H0004???
%PropertyTagGpsAltitudeRef      = &H0005???
%PropertyTagGpsAltitude         = &H0006???
%PropertyTagGpsGpsTime          = &H0007???
%PropertyTagGpsGpsSatellites    = &H0008???
%PropertyTagGpsGpsStatus        = &H0009???
%PropertyTagGpsGpsMeasureMode   = &H000A???
%PropertyTagGpsGpsDop           = &H000B??? ' // Measurement precision
%PropertyTagGpsSpeedRef         = &H000C???
%PropertyTagGpsSpeed            = &H000D???
%PropertyTagGpsTrackRef         = &H000E???
%PropertyTagGpsTrack            = &H000F???
%PropertyTagGpsImgDirRef        = &H0010???
%PropertyTagGpsImgDir           = &H0011???
%PropertyTagGpsMapDatum         = &H0012???
%PropertyTagGpsDestLatRef       = &H0013???
%PropertyTagGpsDestLat          = &H0014???
%PropertyTagGpsDestLongRef      = &H0015???
%PropertyTagGpsDestLong         = &H0016???
%PropertyTagGpsDestBearRef      = &H0017???
%PropertyTagGpsDestBear         = &H0018???
%PropertyTagGpsDestDistRef      = &H0019???
%PropertyTagGpsDestDist         = &H001A???
%PropertyTagGpsProcessingMethod = &H001B???
%PropertyTagGpsAreaInformation  = &H001C???
%PropertyTagGpsDate             = &H001D???
%PropertyTagGpsDifferential     = &H001E???
