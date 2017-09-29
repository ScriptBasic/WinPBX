' ########################################################################################
' Microsoft Windows
' File: BridgeDeviceService.inc
' Contents: Contains declaration of Services PKEYs to support classic MTP-style
' formats and generic/media object properties.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BRIDGEDEVICESERVICE_INC = 1

'/*****************************************************************************/
'/*  MTP Format Codes for Generic and Media Types                             */
'/*****************************************************************************/


'/*  FORMAT_Undefined
' *
' *  MTP Format: Undefined (0x3000)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_Undefined,
'    0x30000000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_Undefined = GUID$("{30000000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_Undefined = "Undefined"$$


'/*  FORMAT_Association
' *
' *  MTP Format: Association (0x3001)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_Association,
'    0x30010000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_Association = GUID$("{30010000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_Association = "Association"$$


'/*  FORMAT_DeviceScript
' *
' *  MTP Format: Device model-specific script (0x3002)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_DeviceScript,
'    0x30020000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_DeviceScript = GUID$("{30020000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_DeviceScript = "DeviceScript"$$


'/*  FORMAT_DeviceExecutable
' *
' *  MTP Format: Device model-specific executable (0x3003)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_DeviceExecutable,
'    0x30030000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_DeviceExecutable = GUID$("{30030000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_DeviceExecutable = "DeviceExecutable"$$

'/*  FORMAT_TextDocument
' *
' *  MTP Format: Text file (0x3004)
' *  Suggested MIME Type: text/plain
' */

'DEFINE_DEVSVCGUID(FORMAT_TextDocument,
'    0x30040000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_TextDocument = GUID$("{30040000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_TextDocument = "TextDocument"$$


'/*  FORMAT_HTMLDocument
' *
' *  MTP Format: HTML file (0x3005)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_HTMLDocument,
'    0x30050000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_HTMLDocument = GUID$("{30050000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_HTMLDocument = "HTMLDocument"$$


'/*  FORMAT_DPOFDocument
' *
' *  MTP Format: Digital Print Order Format file (0x3006)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_DPOFDocument,
'    0x30060000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_DPOFDocument = GUID$("{30060000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_DPOFDocument = "DPOFDocument"$$


'/*  FORMAT_AIFFFile
' *
' *  MTP Format: AIFF file (0x3007)
' *  Suggested MIME Type: audio/aiff
' */

'DEFINE_DEVSVCGUID(FORMAT_AIFFFile,
'    0x30070000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AIFFFile = GUID$("{30070000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_AIFFFile = "AIFFFile"


'/*  FORMAT_WAVFile
' *
' *  MTP Format: WAV file (0x3008)
' *  Suggested MIME Type: audio/wav
' */

'DEFINE_DEVSVCGUID(FORMAT_WAVFile,
'    0x30080000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_WAVFile = GUID$("{30080000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_WAVFile = "WAVFile"


'/*  FORMAT_MP3File
' *
' *  MTP Format: MP3 file (0x3009)
' *  Suggested MIME Type: audio/mpeg
' */

'DEFINE_DEVSVCGUID(FORMAT_MP3File,
'    0x30090000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MP3File = GUID$("{30090000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_MP3File = "MP3File"


'/*  FORMAT_AVIFile
' *
' *  MTP Format: AVI file (0x300A)
' *  Suggested MIME Type: video/avi
' */

'DEFINE_DEVSVCGUID(FORMAT_AVIFile,
'    0x300A0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AVIFile = GUID$("{300A0000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_AVIFile = "AVIFile"


'/*  FORMAT_MPEGFile
' *
' *  MTP Format: MPEG file (0x300B)
' *  Suggested MIME Type: video/mpeg
' */

'DEFINE_DEVSVCGUID(FORMAT_MPEGFile,
'    0x300B0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MPEGFile = GUID$("{300B0000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_MPEGFile = "MPEGFile"


'/*  FORMAT_ASFFile
' *
' *  MTP Format: ASF File (0x300C)
' *  Suggested MIME Type: audio/asf
' */

'DEFINE_DEVSVCGUID(FORMAT_ASFFile,
'    0x300C0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_ASFFile = GUID$("{300C0000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_ASFFile = "ASFFile"


'/*  FORMAT_UnknownImage
' *
' *  MTP Format: Unknown Image (0x3800)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_UnknownImage,
'    0x38000000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_UnknownImage = GUID$("{38000000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_UnknownImage = "UnknownImage"


'/*  FORMAT_EXIFImage
' *
' *  MTP Format: EXIF/JPEG file (0x3801)
' *  Suggested MIME Type: image/jpeg
' */

'DEFINE_DEVSVCGUID(FORMAT_EXIFImage,
'    0x38010000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_EXIFImage = GUID$("{38010000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_EXIFImage = "EXIFImage"


'/*  FORMAT_TIFFEPImage
' *
' *  MTP Format: TIFF/EP (Electronic Photography) file (0x3802)
' *  Suggested MIME Type: image/tif
' */

'DEFINE_DEVSVCGUID(FORMAT_TIFFEPImage,
'    0x38020000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_TIFFEPImage = GUID$("{38020000-AE6C-4804-98BA-C57B46965FE7}")

$NAME_TIFFEPImage = "TIFFEPImage"


'/*  FORMAT_FlashPixImage
' *
' *  MTP Format: Structured Storage Image Format (0x3803)
' *  Suggested MIME Type: image/fpx
' */

'DEFINE_DEVSVCGUID(FORMAT_FlashPixImage,
'    0x38030000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_FlashPixImage = GUID$("{38030000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_FlashPixImage = "FlashPixImage"$$


'/*  FORMAT_BMPImage
' *
' *  MTP Format: Microsoft Windows Bitmap file (0x3804)
' *  Suggested MIME Type: image/bmp
' */

'DEFINE_DEVSVCGUID(FORMAT_BMPImage,
'    0x38040000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_BMPImage = GUID$("{38040000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_BMPImage = "BMPImage"$$


'/*  FORMAT_CIFFImage
' *
' *  MTP Format: Canon Camera Image File format (0x3805)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_CIFFImage,
'    0x38050000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_CIFFImage = GUID$("{38050000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_CIFFImage = "CIFFImage"$$


'/*  FORMAT_GIFImage
' *
' *  MTP Format: Graphics Interchange Format (0x3807)
' *  Suggested MIME Type: image/gif
' */

'DEFINE_DEVSVCGUID(FORMAT_GIFImage,
'    0x38070000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_GIFImage = GUID$("{38070000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_GIFImage = "GIFImage"$$


'/*  FORMAT_JFIFImage
' *
' *  MTP Format: JPEF File Interchange Format (0x3808)
' *  Suggested MIME Type: image/jfif
' */

'DEFINE_DEVSVCGUID(FORMAT_JFIFImage,
'    0x38080000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_JFIFImage = GUID$("{38080000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_JFIFImage = "JFIFImage"$$


'/*  FORMAT_PCDImage
' *
' *  MTP Format: PhotoCD Image Pac (0x3809)
' *  Suggested MIME Type: image/pcd
' */

'DEFINE_DEVSVCGUID(FORMAT_PCDImage,
'    0x38090000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_PCDImage = GUID$("{38090000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_PCDImage = "PCDImage"$$


'/*  FORMAT_PICTImage
' *
' *  MTP Format: Quickdraw Image Format (0x380A)
' *  Suggested MIME Type: image/pict
' */

'DEFINE_DEVSVCGUID(FORMAT_PICTImage,
'    0x380A0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_PICTImage = GUID$("{380A0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_PICTImage = "PICTImage"$$


'/*  FORMAT_PNGImage
' *
' *  MTP Format: Portable Network Graphics (0x380B)
' *  Suggested MIME Type: image/png
' */

'DEFINE_DEVSVCGUID(FORMAT_PNGImage,
'    0x380B0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_PNGImage = GUID$("{380B0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_PNGImage = "PNGImage"$$


'/*  FORMAT_TIFFImage
' *
' *  MTP Format: TIFF File (0x380D)
' *  Suggested MIME Type: image/tif
' */

'DEFINE_DEVSVCGUID(FORMAT_TIFFImage,
'    0x380D0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_TIFFImage = GUID$("{380D0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_TIFFImage = "TIFFImage"$$


'/*  FORMAT_TIFFITImage
' *
' *  MTP Format: TIFF/IT (Graphics Arts) file (0x380E)
' *  Suggested MIME Type: image/tif
' */

'DEFINE_DEVSVCGUID(FORMAT_TIFFITImage,
'    0x380E0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_TIFFITImage = GUID$("{380E0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_TIFFITImage = "TIFFITImage"$$


'/*  FORMAT_JP2Image
' *
' *  MTP Format: JPEG2000 Baseline File Format (0x380F)
' *  Suggested MIME Type: image/jp2
' */

'DEFINE_DEVSVCGUID(FORMAT_JP2Image,
'    0x380F0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_JP2Image = GUID$("{380F0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_JP2Image = "JP2Image"$$


'/*  FORMAT_JPXImage
' *
' *  MTP Format: JPEG2000 Extended File Format (0x3810)
' *  Suggested MIME Type: image/jp2
' */

'DEFINE_DEVSVCGUID(FORMAT_JPXImage,
'    0x38100000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_JPXImage = GUID$("{38100000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_JPXImage = "JPXImage"$$


'/*  FORMAT_FirmwareFile
' *
' *  MTP Format: Firmware (0xB802)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_FirmwareFile,
'    0xB8020000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_FirmwareFile = GUID$("{B8020000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_FirmwareFile = "FirmwareFile"$$


'/*  FORMAT_HDPhotoImage
' *
' *  MTP Format: HD Photo (Windows Media Photo) file (0xB881)
' *  Suggested MIME Type: image/vnd.ms-photo
' */

'DEFINE_DEVSVCGUID(FORMAT_HDPhotoImage,
'    0xB8810000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_HDPhotoImage = GUID$("{B8810000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_HDPhotoImage = "HDPhotoImage"$$


'/*  FORMAT_UndefinedAudio
' *
' *  MTP Format: Undefined Audio (0xB900)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_UndefinedAudio,
'    0xB9000000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_UndefinedAudio = GUID$("{B9000000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_UndefinedAudio = "UndefinedAudio"$$


'/*  FORMAT_WMAFile
' *
' *  MTP Format: WMA file (0xB901)
' *  Suggested MIME Type: audio/x-ms-wma
' */

'DEFINE_DEVSVCGUID(FORMAT_WMAFile,
'    0xB9010000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_WMAFile = GUID$("{B9010000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_WMAFile = "WMAFile"$$


'/*  FORMAT_OGGFile
' *
' *  MTP Format: OGG file (0xB902)
' *  Suggested MIME Type: audio/x-ogg
' */

'DEFINE_DEVSVCGUID(FORMAT_OGGFile,
'    0xB9020000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_OGGFile = GUID$("{B9020000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_OGGFile = "OGGFile"$$


'/*  FORMAT_AACFile
' *
' *  MTP Format: AAC file (0xB903)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AACFile,
'    0xB9030000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AACFile = GUID$("{B9030000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AACFile = "AACFile"$$


'/*  FORMAT_AudibleFile
' *
' *  MTP Format: Audible file (0xB904)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AudibleFile,
'    0xB9040000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AudibleFile = GUID$("{B9040000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AudibleFile = "AudibleFile"$$


'/*  FORMAT_FLACFile
' *
' *  MTP Format: FLAC file (0xB906)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_FLACFile,
'    0xB9060000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_FLACFile = GUID$("{B9060000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_FLACFile = "FLACFile"$$


'/*  FORMAT_UndefinedVideo
' *
' *  MTP Format: Undefined Video (0xB980)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_UndefinedVideo,
'    0xB9890000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_UndefinedVideo = GUID$("{B9890000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_UndefinedVideo = "UndefinedVideo"$$


'/*  FORMAT_WMVFile
' *
' *  MTP Format: WMV file (0xB981)
' *  Suggested MIME Type: video/x-ms-wmv
' */

'DEFINE_DEVSVCGUID(FORMAT_WMVFile,
'    0xB9810000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_WMVFile = GUID$("{B9810000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_WMVFile = "WMVFile"$$


'/*  FORMAT_MPEG4File
' *
' *  MTP Format: MPEG-4 Video file (0xB982)
' *  Suggested MIME Type: video/mp4v-es
' */

'DEFINE_DEVSVCGUID(FORMAT_MPEG4File,
'    0xB9820000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MPEG4File = GUID$("{B9820000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_MPEG4File = "MPEG4File"$$


'/*  FORMAT_MPEG2File
' *
' *  MTP Format: MPEG-2 Video file (0xB983)
' *  Suggested MIME Type: video/mpeg
' */

'DEFINE_DEVSVCGUID(FORMAT_MPEG2File,
'    0xB9830000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MPEG2File = GUID$("{B9830000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_MPEG2File = "MPEG2File"$$


'/*  FORMAT_3GPPFile
' *
' *  MTP Format: 3GPP Video file (0xB984)
' *  Suggested MIME Type: video/3gpp
' */

'DEFINE_DEVSVCGUID(FORMAT_3GPPFile,
'    0xB9840000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_3GPPFile = GUID$("{B9840000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_3GPPFile = "3GPPFile"$$


'/*  FORMAT_UndefinedCollection
' *
' *  MTP Format: Undefined Collection (0xBA00)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_UndefinedCollection,
'    0xBA060000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_UndefinedCollection = GUID$("{BA060000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_UndefinedCollection = "UndefinedCollection"$$


'/*  FORMAT_AbstractMultimediaAlbum
' *
' *  MTP Format: Abstract Multimedia Album (0xBA01)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractMultimediaAlbum,
'    0xBA010000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractMultimediaAlbum = GUID$("{BA010000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractMultimediaAlbum = "AbstractMultimediaAlbum"$$


'/*  FORMAT_AbstractImageAlbum
' *
' *  MTP Format: Abstract Image Album (0xBA02)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractImageAlbum,
'    0xBA020000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractImageAlbum = GUID$("{BA020000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractImageAlbum = "AbstractImageAlbum"$$


'/*  FORMAT_AbstractAudioAlbum
' *
' *  MTP Format: Abstract Audio Album (0xBA03)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractAudioAlbum,
'    0xBA030000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractAudioAlbum = GUID$("{BA030000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractAudioAlbum = "AbstractAudioAlbum"$$


'/*  FORMAT_AbstractVideoAlbum
' *
' *  MTP Format: Abstract Video Album (0xBA04)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractVideoAlbum,
'    0xBA040000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractVideoAlbum = GUID$("{BA040000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractVideoAlbum = "AbstractVideoAlbum"$$


'/*  FORMAT_AbstractAudioVideoAlbum
' *
' *  MTP Format: Abstract Audio & Video Playlist (0xBA05)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractAudioVideoAlbum,
'    0xBA050000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractAudioVideoAlbum = GUID$("{BA050000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractAudioVideoAlbum = "AbstractAudioVideoAlbum"$$


'/*  FORMAT_AbstractChapteredProduction
' *
' *  MTP Format: Abstract Chaptered Production (0xBA08)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractChapteredProduction,
'    0xBA080000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractChapteredProduction = GUID$("{BA080000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractChapteredProduction = "AbstractChapteredProduction"$$


'/*  FORMAT_AbstractAudioPlaylist
' *
' *  MTP Format: Abstract Audio Playlist (0xBA09)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractAudioPlaylist,
'    0xBA090000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractAudioPlaylist = GUID$("{BA090000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractAudioPlaylist = "AbstractAudioPlaylist"$$


'/*  FORMAT_AbstractVideoPlaylist
' *
' *  MTP Format: Abstract Video Playlist (0xBA0A)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractVideoPlaylist,
'    0xBA0A0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractVideoPlaylist = GUID$("{BA0A0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractVideoPlaylist = "AbstractVideoPlaylist"$$


'/*  FORMAT_AbstractMediacast
' *
' *  MTP Format: Abstract Mediacast (0xBA0B)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractMediacast,
'    0xBA0B0000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractMediacast = GUID$("{BA0B0000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractMediacast = "AbstractMediacast"$$


'/*  FORMAT_WPLPlaylist
' *
' *  MTP Format: WPL Playlist (0xBA10)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_WPLPlaylist,
'    0xBA100000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_WPLPlaylist = GUID$("{BA100000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_WPLPlaylist = "WPLPlaylist"$$


'/*  FORMAT_M3UPlaylist
' *
' *  MTP Format: M3U Playlist (0xBA11)
' *  Suggested MIME Type: audio/mpeg-url
' */

'DEFINE_DEVSVCGUID(FORMAT_M3UPlaylist,
'    0xBA110000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_M3UPlaylist = GUID$("{BA110000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_M3UPlaylist = "M3UPlaylist"$$


'/*  FORMAT_MPLPlaylist
' *
' *  MTP Format: MPL Playlist (0xBA12)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_MPLPlaylist,
'    0xBA120000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MPLPlaylist = GUID$("{BA120000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_MPLPlaylist = "MPLPlaylist"$$


'/*  FORMAT_ASXPlaylist
' *
' *  MTP Format: ASX Playlist (0xBA13)
' *  Suggested MIME Type: video/x-ms-asf
' */

'DEFINE_DEVSVCGUID(FORMAT_ASXPlaylist,
'    0xBA130000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_ASXPlaylist = GUID$("{BA130000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_ASXPlaylist = "ASXPlaylist"$$


'/*  FORMAT_PSLPlaylist
' *
' *  MTP Format: PLS Playlist (0xBA14)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_PSLPlaylist,
'    0xBA140000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_PSLPlaylist = GUID$("{BA140000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_PSLPlaylist = "PSLPlaylist"$$


'/*  FORMAT_UndefinedDocument
' *
' *  MTP Format: Undefined Document (0xBA80)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_UndefinedDocument,
'    0xBA800000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_UndefinedDocument = GUID$("{BA800000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_UndefinedDocument = "UndefinedDocument"$$


'/*  FORMAT_AbstractDocument
' *
' *  MTP Format: Abstract Document (0xBA81)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractDocument,
'    0xBA810000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractDocument = GUID$("{BA810000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractDocument = "AbstractDocument"$$


'/*  FORMAT_XMLDocument
' *
' *  MTP Format: XML Document (0xBA82)
' *  Suggested MIME Type: text/xml
' */

'DEFINE_DEVSVCGUID(FORMAT_XMLDocument,
'    0xBA820000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_XMLDocument = GUID$("{BA820000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_XMLDocument = "XMLDocument"$$


'/*  FORMAT_WordDocument
' *
' *  MTP Format: Microsoft Word Document (0xBA83)
' *  Suggested MIME Type: application/msword
' */

'DEFINE_DEVSVCGUID(FORMAT_WordDocument,
'    0xBA830000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_WordDocument = GUID$("{BA830000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_WordDocument = "WordDocument"$$


'/*  FORMAT_MHTDocument
' *
' *  MTP Format: MHT Compiled HTML Document (0xBA84)
' *  Suggested MIME Type: message/rfc822
' */

'DEFINE_DEVSVCGUID(FORMAT_MHTDocument,
'    0xBA840000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_MHTDocument = GUID$("{BA840000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_MHTDocument = "MHTDocument"$$


'/*  FORMAT_ExcelDocument
' *
' *  MTP Format: Microsoft Excel Document (0xBA85)
' *  Suggested MIME Type: application/msexcel
' */

'DEFINE_DEVSVCGUID(FORMAT_ExcelDocument,
'    0xBA850000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_ExcelDocument = GUID$("{BA850000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_ExcelDocument = "ExcelDocument"$$


'/*  FORMAT_PowerPointDocument
' *
' *  MTP Format: Microsoft PowerPoint Document (0xBA86)
' *  Suggested MIME Type: application/mspowerpoint
' */

'DEFINE_DEVSVCGUID(FORMAT_PowerPointDocument,
'    0xBA860000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_PowerPointDocument = GUID$("{BA860000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_PowerPointDocument = "PowerPointDocument"$$


'/*****************************************************************************/
'/*  MTP Object Property Codes for Generic and Media Types                    */
'/*****************************************************************************/

'/*  GenericObj.ObjectID
' *
' *  MTP Property: ()
' *  Type: UInt128
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ObjectID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    2);
MACRO PKEY_GenericObj_ObjectID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(2)

$$NAME_GenericObj_ObjectID = "ObjectID"$$


'/*  GenericObj.StorageID
' *
' *  MTP Property: Storage ID (0xDC01)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_StorageID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    23);
MACRO PKEY_GenericObj_StorageID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(23)

$$NAME_GenericObj_StorageID = "StorageID"$$


'/*  GenericObj.ObjectFormat
' *
' *  MTP Property: Object Format (0xDC02)
' *  Type: UInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ObjectFormat,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    6);
MACRO PKEY_GenericObj_ObjectFormat = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(6)

$$NAME_GenericObj_ObjectFormat = "ObjectFormat"$$


'/*  GenericObj.ProtectionStatus
' *
' *  MTP Property: Protection Status (0xDC03)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ProtectionStatus,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    26);
MACRO PKEY_GenericObj_ProtectionStatus = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(26)

'#define NAME_GenericObj_ProtectionStatus    L"ProtectionStatus"
$$NAME_GenericObj_ProtectionStatus = "ProtectionStatus"$$


'/*  GenericObj.ObjectSize
' *
' *  MTP Property: Object Size (0xDC04)
' *  Type: UInt64
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ObjectSize,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    11);
MACRO PKEY_GenericObj_ObjectSize = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(11)

$$NAME_GenericObj_ObjectSize = "ObjectSize"$$


'/*  GenericObj.AssociationType
' *
' *  MTP Property: Association Type (0xDC05)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_AssociationType,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    32);
MACRO PKEY_GenericObj_AssociationType = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(32)

$$NAME_GenericObj_AssociationType = "AssociationType"$$


'/*  GenericObj.AssociationDesc
' *
' *  MTP Property: Association Desc (0xDC06)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_AssociationDesc,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    33);
MACRO PKEY_GenericObj_AssociationDesc = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(33)

$$NAME_GenericObj_AssociationDesc = "AssociationDesc"$$

'/*  GenericObj.ObjectFileName
' *
' *  MTP Property: Object File Name (0xDC07)
' *  Type: String
' *  Form: None/RegEx
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ObjectFileName,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    12);
MACRO PKEY_GenericObj_ObjectFileName = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(12)

$$NAME_GenericObj_ObjectFileName = "ObjectFileName"$$


'/*  GenericObj.DateCreated
' *
' *  MTP Property: Date Created (0xDC08)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateCreated,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    39);
MACRO PKEY_GenericObj_DateCreated = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(39)

$$NAME_GenericObj_DateCreated = "DateCreated"$$


'/*  GenericObj.DateModified
' *
' *  MTP Property: Date Modified (0xDC09)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateModified,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    40);
MACRO PKEY_GenericObj_DateModified = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(40)

$$NAME_GenericObj_DateModified = "DateModified"$$


'/*  GenericObj.Keywords
' *
' *  MTP Property: Keywords (0xDC0A)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Keywords,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    15);
MACRO PKEY_GenericObj_Keywords = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(15)

$$NAME_GenericObj_Keywords = "Keywords"$$


'/*  GenericObj.ParentID
' *
' *  MTP Property: Parent Object (0xDC0B)
' *  Type: UInt32
' *  Form: ObjectID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ParentID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    3);
MACRO PKEY_GenericObj_ParentID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(3)

$$NAME_GenericObj_ParentID = "ParentID"$$


'/*  GenericObj.AllowedFolderContents
' *
' *  MTP Property: Allowed Folder Contents (0xDC0C)
' *  Type: AUInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_AllowedFolderContents,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    34);
MACRO PKEY_GenericObj_AllowedFolderContents = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(34)

$$NAME_GenericObj_AllowedFolderContents = "AllowedFolderContents"$$


'/*  GenericObj.Hidden
' *
' *  MTP Property: Hidden (0xDC0D)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Hidden,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    28);
MACRO PKEY_GenericObj_Hidden = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(28)

$$NAME_GenericObj_Hidden = "Hidden"$$


'/*  GenericObj.SystemObject
' *
' *  MTP Property: System Object (0xDC0E)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_SystemObject,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    29);
MACRO PKEY_GenericObj_SystemObject = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(29)

$$NAME_GenericObj_SystemObject = "SystemObject"$$


'/*  GenericObj.PersistentUID
' *
' *  MTP Property: Persistent Unique Object ID (0xDC41)
' *  Type: UInt128
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_PersistentUID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    5);
MACRO PKEY_GenericObj_PersistentUID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(5)

$$NAME_GenericObj_PersistentUID = "PersistentUID"$$


'/*  GenericObj.SyncID
' *
' *  MTP Property: Sync ID (0xDC42)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_SyncID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    16);
MACRO PKEY_GenericObj_SyncID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(16)

$$NAME_GenericObj_SyncID = "SyncID"$$


'/*  GenericObj.PropertyBag
' *
' *  MTP Property: Property Bag (0xDC43)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_PropertyBag,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    35);
MACRO PKEY_GenericObj_PropertyBag = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(35)

$$NAME_GenericObj_PropertyBag = "PropertyBag"$$


'/*  GenericObj.Name
' *
' *  MTP Property: Name (0xDC44)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Name,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    4);
MACRO PKEY_GenericObj_Name = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(4)

$$NAME_GenericObj_Name = "Name"$$


'/*  MediaObj.Artist
' *
' *  MTP Property: Artist (0xDC46)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Artist,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    24);
MACRO PKEY_MediaObj_Artist = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(24)

$$NAME_MediaObj_Artist = "Artist"$$


'/*  GenericObj.DateAuthored
' *
' *  MTP Property: Date Authored (0xDC47)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateAuthored,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    41);
MACRO PKEY_GenericObj_DateAuthored = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(41)

$$NAME_GenericObj_DateAuthored = "DateAuthored"$$


'/*  GenericObj.Description
' *
' *  MTP Property: Description (0xDC48)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Description,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    45);
MACRO PKEY_GenericObj_Description = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(45)

$$NAME_GenericObj_Description = "Description"$$


'/*  GenericObj.LanguageLocale
' *
' *  MTP Property: Language Locale (0xDC4A)
' *  Type: String
' *  Form: RegEx
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_LanguageLocale,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    27);
MACRO PKEY_GenericObj_LanguageLocale = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(27)

$$NAME_GenericObj_LanguageLocale = "LanguageLocale"$$


'/*  GenericObj.Copyright
' *
' *  MTP Property: Copyright Information (0xDC4B)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Copyright,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    38);
MACRO PKEY_GenericObj_Copyright = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(38)

$$NAME_GenericObj_Copyright = "Copyright"$$


'/*  VideoObj.Source
' *
' *  MTP Property: Source (0xDC4C)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_Source,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    4);
MACRO PKEY_VideoObj_Source = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(4)

$$NAME_VideoObj_Source = "Source"$$


'/*  MediaObj.GeographicOrigin
' *
' *  MTP Property: Origin Location (0xDC4D)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_GeographicOrigin,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    40);
MACRO PKEY_MediaObj_GeographicOrigin = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(40)

$$NAME_MediaObj_GeographicOrigin = "GeographicOrigin"$$


'/*  GenericObj.DateAdded
' *
' *  MTP Property: Date Added (0xDC4E)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateAdded,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    36);
MACRO PKEY_GenericObj_DateAdded = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(36)

$$NAME_GenericObj_DateAdded = "DateAdded"$$


'/*  GenericObj.NonConsumable
' *
' *  MTP Property: Non-Consumable (0xDC4F)
' *  Type: UInt8
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_NonConsumable,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    30);
MACRO PKEY_GenericObj_NonConsumable = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(30)

$$NAME_GenericObj_NonConsumable = "NonConsumable"$$


'/*  GenericObj.Corrupt
' *
' *  MTP Property: Corrupt (0xDC50)
' *  Type: UInt8
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_Corrupt,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    37);
MACRO PKEY_GenericObj_Corrupt = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(37)

$$NAME_GenericObj_Corrupt = "Corrupt"$$


'/*  MediaObj.Width
' *
' *  MTP Property: Width (0xDC87)
' *  Type: UInt32
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Width,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    22);
MACRO PKEY_MediaObj_Width = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(22)

$$NAME_MediaObj_Width = "Width"$$


'/*  MediaObj.Height
' *
' *  MTP Property: Height (0xDC88)
' *  Type: UInt32
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Height,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    23);
MACRO PKEY_MediaObj_Height = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(23)

$$NAME_MediaObj_Height = "Height"$$


'/*  MediaObj.Duration
' *
' *  MTP Property: Duration (0xDC89)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Duration,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    19);
MACRO PKEY_MediaObj_Duration = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(19)

$$NAME_MediaObj_Duration = "Duration"$$


'/*  MediaObj.UserRating
' *
' *  MTP Property: Rating (0xDC8A)
' *  Type: UInt16
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_UserRating,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    17);
MACRO PKEY_MediaObj_UserRating = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(17)

$$NAME_MediaObj_UserRating = "UserRating"$$


'/*  MediaObj.Track
' *
' *  MTP Property: Track (0xDC8B)
' *  Type: UInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Track,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    43);
MACRO PKEY_MediaObj_Track = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(43)

$$NAME_MediaObj_Track = "Track"$$


'/*  MediaObj.Genre
' *
' *  MTP Property: Genre (0xDC8C)
' *  Type: String
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Genre,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    32);
MACRO PKEY_MediaObj_Genre = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(32)

$$NAME_MediaObj_Genre = "Genre"$$


'/*  MediaObj.Credits
' *
' *  MTP Property: Credits (0xDC8D)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Credits,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    47);
MACRO PKEY_MediaObj_Credits = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(47)

$$NAME_MediaObj_Credits = "Credits"$$


'/*  AudioObj.Lyrics
' *
' *  MTP Property: Lyrics (0xDC8E)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_Lyrics,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    6);
MACRO PKEY_AudioObj_Lyrics = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(6)

$$NAME_AudioObj_Lyrics = "Lyrics"$$


'/*  MediaObj.SubscriptionContentID
' *
' *  MTP Property: Subscription Content ID (0xDC8F)
' *  Type: String
' *  Form: RegEx
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_SubscriptionContentID,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    5);
MACRO PKEY_MediaObj_SubscriptionContentID = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(5)

$$NAME_MediaObj_SubscriptionContentID = "SubscriptionContentID"$$


'/*  MediaObj.Producer
' *
' *  MTP Property: Produced By (0xDC90)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Producer,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    45);
MACRO PKEY_MediaObj_Producer = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(45)

$$NAME_MediaObj_Producer = "Producer"$$


'/*  MediaObj.UseCount
' *
' *  MTP Property: Use Count (0xDC91)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_UseCount,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    6);
MACRO PKEY_MediaObj_UseCount = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(6)

$$NAME_MediaObj_UseCount = "UseCount"$$


'/*  MediaObj.SkipCount
' *
' *  MTP Property: Skip Count (0xDC92)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_SkipCount,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    7);
MACRO PKEY_MediaObj_SkipCount = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(7)

$$NAME_MediaObj_SkipCount = "SkipCount"$$


'/*  GenericObj.DateAccessed
' *
' *  MTP Property: Last Accessed (0xDC93)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateAccessed,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    42);
MACRO PKEY_GenericObj_DateAccessed = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(42)

$$NAME_GenericObj_DateAccessed = "DateAccessed"$$


'/*  MediaObj.ParentalRating
' *
' *  MTP Property: Parental Rating (0xDC94)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_ParentalRating,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    9);
MACRO PKEY_MediaObj_ParentalRating = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(9)

$$NAME_MediaObj_ParentalRating = "ParentalRating"$$


'/*  MediaObj.MediaType
' *
' *  MTP Property: Meta Genre (0xDC95)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_MediaType,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    10);
MACRO PKEY_MediaObj_MediaType = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(10)

$$NAME_MediaObj_MediaType = "MediaType"$$


'/*  MediaObj.Composer
' *
' *  MTP Property: Composer (0xDC96)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Composer,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    11);
MACRO PKEY_MediaObj_Composer = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(11)

$$NAME_MediaObj_Composer = "Composer"$$


'/*  MediaObj.EffectiveRating
' *
' *  MTP Property: Effective Rating (0xDC97)
' *  Type: UInt16
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_EffectiveRating,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    12);
MACRO PKEY_MediaObj_EffectiveRating = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(12)

$$NAME_MediaObj_EffectiveRating = "EffectiveRating"$$


'/*  MediaObj.Subtitle
' *
' *  MTP Property: Subtitle (0xDC98)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Subtitle,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    13);
MACRO PKEY_MediaObj_Subtitle = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(13)

$$NAME_MediaObj_Subtitle = "Subtitle"$$


'/*  MediaObj.DateOriginalRelease
' *
' *  MTP Property: Original Release Date (0xDC99)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_DateOriginalRelease,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    41);
MACRO PKEY_MediaObj_DateOriginalRelease = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(41)

$$NAME_MediaObj_DateOriginalRelease = "DateOriginalRelease"$$


'/*  MediaObj.AlbumName
' *
' *  MTP Property: Album Name (0xDC9A)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_AlbumName,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    42);
MACRO PKEY_MediaObj_AlbumName = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(42)

$$NAME_MediaObj_AlbumName = "AlbumName"$$


'/*  MediaObj.AlbumArtist
' *
' *  MTP Property: Album Artist (0xDC9B)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_AlbumArtist,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    25);
MACRO PKEY_MediaObj_AlbumArtist = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(25)

$$NAME_MediaObj_AlbumArtist = "AlbumArtist"$$


'/*  MediaObj.Mood
' *
' *  MTP Property: Mood (0xDC9C)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Mood,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    44);
MACRO PKEY_MediaObj_Mood = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(44)

$$NAME_MediaObj_Mood = "Mood"$$


'/*  GenericObj.DRMStatus
' *
' *  MTP Property: DRM Status (0xDC9D)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DRMStatus,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    31);
MACRO PKEY_GenericObj_DRMStatus = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(31)

$$NAME_GenericObj_DRMStatus = "DRMStatus"$$


'/*  GenericObj.SubDescription
' *
' *  MTP Property: Sub Description (0xDC9E)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_SubDescription,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    46);
MACRO PKEY_GenericObj_SubDescription = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(46)

$$NAME_GenericObj_SubDescription = "SubDescription"$$


'/*  ImageObj.IsCropped
' *
' *  MTP Property: Is Cropped (0xDCD1)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_IsCropped,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    4);
MACRO PKEY_ImageObj_IsCropped = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(4)

$$NAME_ImageObj_IsCropped = "IsCropped"$$


'/*  ImageObj.IsColorCorrected
' *
' *  MTP Property: Is Colour Corrected (0xDCD2)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_IsColorCorrected,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    5);
MACRO PKEY_ImageObj_IsColorCorrected = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(5)

$$NAME_ImageObj_IsColorCorrected = "IsColorCorrected"$$


'/*  ImageObj.ImageBitDepth
' *
' *  MTP Property: Image Bit Depth (0xDCD3)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_ImageBitDepth,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    3);
MACRO PKEY_ImageObj_ImageBitDepth = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(3)

$$NAME_ImageObj_ImageBitDepth = "ImageBitDepth"$$


'/*  ImageObj.Aperature
' *
' *  MTP Property: Fnumber (0xDCD4)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_Aperature,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    6);
MACRO PKEY_ImageObj_Aperature = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(6)

$$NAME_ImageObj_Aperature = "Aperature"$$


'/*  ImageObj.Exposure
' *
' *  MTP Property: Exposure Time (0xDCD5)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_Exposure,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    7);
MACRO PKEY_ImageObj_Exposure = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(7)

$$NAME_ImageObj_Exposure = "Exposure"$$


'/*  ImageObj.ISOSpeed
' *
' *  MTP Property: Exposure Index (0xDCD6)
' *  Type: UInt16
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_ImageObj_ISOSpeed,
'    0x63D64908, 0x9FA1, 0x479F, 0x85, 0xBA, 0x99, 0x52, 0x21, 0x64, 0x47, 0xDB,
'    8);
MACRO PKEY_ImageObj_ISOSpeed = GUID$("{63D64908-9FA1-479F-85BA-9952216447DB}") & MKDWD$(8)

$$NAME_ImageObj_ISOSpeed = "ISOSpeed"$$


'/*  MediaObj.Owner
' *
' *  MTP Property: Owner (0xDD5D)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Owner,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    26);
MACRO PKEY_MediaObj_Owner = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(26)

$$NAME_MediaObj_Owner = "Owner"$$


'/*  MediaObj.Editor
' *
' *  MTP Property: Editor (0xDD5E)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_Editor,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    27);
MACRO PKEY_MediaObj_Editor = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(27)

$$NAME_MediaObj_Editor = "Editor"$$


'/*  MediaObj.WebMaster
' *
' *  MTP Property: WebMaster (0xDD5F)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_WebMaster,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    28);
MACRO PKEY_MediaObj_WebMaster = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(28)

$$NAME_MediaObj_WebMaster = "WebMaster"$$


'/*  MediaObj.URLSource
' *
' *  MTP Property: URL Source (0xDD60)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_URLSource,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    29);
MACRO PKEY_MediaObj_URLSource = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(29)

$$NAME_MediaObj_URLSource = "URLSource"$$


'/*  MediaObj.URLLink
' *
' *  MTP Property: URL Destination (0xDD61)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_URLLink,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    30);
MACRO PKEY_MediaObj_URLLink = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(30)

$$NAME_MediaObj_URLLink = "URLLink"$$


'/*  MediaObj.BookmarkTime
' *
' *  MTP Property: Time Bookmark (0xDD62)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_BookmarkTime,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    33);
MACRO PKEY_MediaObj_BookmarkTime = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(33)

$$NAME_MediaObj_BookmarkTime = "BookmarkTime"$$


'/*  MediaObj.BookmarkObject
' *
' *  MTP Property: Object Bookmark (0xDD63)
' *  Type: UInt32
' *  Form: ObjectID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_BookmarkObject,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    34);
MACRO PKEY_MediaObj_BookmarkObject = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(34)

$$NAME_MediaObj_BookmarkObject = "BookmarkObject"$$


'/*  MediaObj.BookmarkByte
' *
' *  MTP Property: Byte Bookmark (0xDD64)
' *  Type: UInt64
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_BookmarkByte,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    36);
MACRO PKEY_MediaObj_BookmarkByte = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(36)

$$NAME_MediaObj_BookmarkByte = "BookmarkByte"$$


'/*  GenericObj.DateRevised
' *
' *  MTP Property: Last Build Date (0xDD70)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_DateRevised,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    43);
MACRO PKEY_GenericObj_DateRevised = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(43)

$$NAME_GenericObj_DateRevised = "DateRevised"$$


'/*  GenericObj.TimeToLive
' *
' *  MTP Property: Time To Live (0xDD71)
' *  Type: UInt64
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_TimeToLive,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    44);
MACRO PKEY_GenericObj_TimeToLive = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(44)

$$NAME_GenericObj_TimeToLive = "TimeToLive"$$


'/*  MediaObj.MediaUID
' *
' *  MTP Property: Media GUID (0xDD72)
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_MediaUID,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    38);
MACRO PKEY_MediaObj_MediaUID = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(38)

$$NAME_MediaObj_MediaUID = "MediaUID"$$


'/*  MediaObj.TotalBitRate
' *
' *  MTP Property: Total Bit Rate (0xDE91)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_TotalBitRate,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    2);
MACRO PKEY_MediaObj_TotalBitRate = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(2)

$$NAME_MediaObj_TotalBitRate = "TotalBitRate"$$


'/*  MediaObj.BitRateType
' *
' *  MTP Property: Bit Rate Type (0xDE92)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_BitRateType,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    3);
MACRO PKEY_MediaObj_BitRateType = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(3)

$$NAME_MediaObj_BitRateType = "BitRateType"$$


'/*  MediaObj.SampleRate
' *
' *  MTP Property: Sample Rate (0xDE93)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_SampleRate,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    15);
MACRO PKEY_MediaObj_SampleRate = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(15)

$$NAME_MediaObj_SampleRate = "SampleRate"$$


'/*  AudioObj.Channels
' *
' *  MTP Property: Number of Channels (0xDE94)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_Channels,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    10);
MACRO PKEY_AudioObj_Channels = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(10)

$$NAME_AudioObj_Channels = "Channels"$$


'/*  AudioObj.AudioBitDepth
' *
' *  MTP Property: Audio Bit Depth (0xDE95)
' *  Type: UInt32
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_AudioBitDepth,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    12);
MACRO PKEY_AudioObj_AudioBitDepth = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(12)

$$NAME_AudioObj_AudioBitDepth = "AudioBitDepth"$$


'/*  AudioObj.AudioBlockAlignment
' *
' *  MTP Property: Audio Block Alignment (0xDE96)
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_AudioBlockAlignment,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    13);
MACRO PKEY_AudioObj_AudioBlockAlignment = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(13)

$$NAME_AudioObj_AudioBlockAlignment = "AudioBlockAlignment"$$


'/*  VideoObj.ScanType
' *
' *  MTP Property: Video Scan Type (0xDE97)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_ScanType,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    12);
MACRO PKEY_VideoObj_ScanType = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(12)

$$NAME_AudioObj_AudioBlockAlignment = "AudioBlockAlignment"$$


'/*  AudioObj.AudioFormatCode
' *
' *  MTP Property: Audio WAVE Codec (0xDE99)
' *  Type: UInt32
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_AudioFormatCode,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    11);
MACRO PKEY_AudioObj_AudioFormatCode = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(11)

$$NAME_AudioObj_AudioFormatCode = "AudioFormatCode"$$


'/*  AudioObj.AudioBitRate
' *
' *  MTP Property: Audio Bit Rate (0xDE9A)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_AudioObj_AudioBitRate,
'    0xB324F56A, 0xDC5D, 0x46E5, 0xB6, 0xDF, 0xD2, 0xEA, 0x41, 0x48, 0x88, 0xC6,
'    9);
MACRO PKEY_AudioObj_AudioBitRate = GUID$("{B324F56A-DC5D-46E5-B6DF-D2EA414888C6}") & MKDWD$(9)

$$NAME_AudioObj_AudioBitRate = "AudioBitRate"$$


'/*  VideoObj.VideoFormatCode
' *
' *  MTP Property: Video FourCC Codec (0xDE9B)
' *  Type: UInt32
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_VideoFormatCode,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    14);
MACRO PKEY_VideoObj_VideoFormatCode = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(14)

$$NAME_VideoObj_VideoFormatCode = "VideoFormatCode"$$


'/*  VideoObj.VideoBitRate
' *
' *  MTP Property: Video Bit Rate (0xDE9C)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_VideoBitRate,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    13);
MACRO PKEY_VideoObj_VideoBitRate = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(13)

$$NAME_VideoObj_VideoBitRate = "VideoBitRate"$$


'/*  VideoObj.VideoFrameRate
' *
' *  MTP Property: Frames Per Thousand Seconds (0xDE9D)
' *  Type: UInt32
' *  Form: Range/Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_VideoFrameRate,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    15);
MACRO PKEY_VideoObj_VideoFrameRate = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(15)

$$NAME_VideoObj_VideoFrameRate = "VideoFrameRate"$$


'/*  VideoObj.KeyFrameDistance
' *
' *  MTP Property: Key Frame Distance (0xDE9E)
' *  Type: UInt32
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_VideoObj_KeyFrameDistance,
'    0x346F2163, 0xF998, 0x4146, 0x8B, 0x01, 0xD1, 0x9B, 0x4C, 0x00, 0xDE, 0x9A,
'    10);
MACRO PKEY_VideoObj_KeyFrameDistance = GUID$("{346F2163-F998-4146-8B01-D19B4C00DE9A}") & MKDWD$(10)

$$NAME_VideoObj_KeyFrameDistance = "KeyFrameDistance"$$


'/*  MediaObj.BufferSize
' *
' *  MTP Property: Buffer Size (0xDE9F)
' *  Type: UInt32
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_BufferSize,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    46);
MACRO PKEY_MediaObj_BufferSize = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(46)

$$NAME_MediaObj_BufferSize = "BufferSize"$$


'/*  MediaObj.EncodingQuality
' *
' *  MTP Property: Encoding Quality (0xDEA0)
' *  Type: UInt32
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_EncodingQuality,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    48);
MACRO PKEY_MediaObj_EncodingQuality = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(48)

$$NAME_MediaObj_EncodingQuality = "EncodingQuality"$$


'/*  MediaObj.EncodingProfile
' *
' *  MTP Property: Encoding Profile (0xDEA1)
' *  Type: String
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MediaObj_EncodingProfile,
'    0x2ED8BA05, 0x0AD3, 0x42DC, 0xB0, 0xD0, 0xBC, 0x95, 0xAC, 0x39, 0x6A, 0xC8,
'    21);
MACRO PKEY_MediaObj_EncodingProfile = GUID$("{2ED8BA05-0AD3-42DC-B0D0-BC95AC396AC8}") & MKDWD$(21)

$$NAME_MediaObj_EncodingProfile = "EncodingProfile"$$


'/*  GenericObj.ReferenceParentID
' *
' *  This write only property is used when creating object references to help
' *  hint the responder implementation to the parent item that this object will
' *  be associated with.
' *
' *  Type: UInt32
' *  Form: ObjectID
' */

'DEFINE_DEVSVCPROPKEY(PKEY_GenericObj_ReferenceParentID,
'    0xEF6B490D, 0x5CD8, 0x437A, 0xAF, 0xFC, 0xDA, 0x8B, 0x60, 0xEE, 0x4A, 0x3C,
'    47);
MACRO PKEY_GenericObj_ReferenceParentID = GUID$("{EF6B490D-5CD8-437A-AFFC-DA8B60EE4A3C}") & MKDWD$(47)

$$NAME_GenericObj_ReferenceParentID = "ReferenceParentID"$$
