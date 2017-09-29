' ########################################################################################
' Microsoft Windows
' File: FreeImage.inc
' Contents: FreeImage 3.17.0 headers for PowerBASIC
' Copyright (c) 2012-2015 José Roca
' ########################################################################################

'// ==========================================================
'// FreeImage 3
'//
'// Design and implementation by
'// - Floris van den Berg (flvdberg@wxs.nl)
'// - Hervé Drolon (drolon@infonie.fr)
'//
'// Contributors:
'// - see changes log named 'Whatsnew.txt', see header of each .h and .cpp file
'//
'// This file is part of FreeImage 3
'//
'// COVERED CODE IS PROVIDED UNDER THIS LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTY
'// OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, WITHOUT LIMITATION, WARRANTIES
'// THAT THE COVERED CODE IS FREE OF DEFECTS, MERCHANTABLE, FIT FOR A PARTICULAR PURPOSE
'// OR NON-INFRINGING. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE COVERED
'// CODE IS WITH YOU. SHOULD ANY COVERED CODE PROVE DEFECTIVE IN ANY RESPECT, YOU (NOT
'// THE INITIAL DEVELOPER OR ANY OTHER CONTRIBUTOR) ASSUME THE COST OF ANY NECESSARY
'// SERVICING, REPAIR OR CORRECTION. THIS DISCLAIMER OF WARRANTY CONSTITUTES AN ESSENTIAL
'// PART OF THIS LICENSE. NO USE OF ANY COVERED CODE IS AUTHORIZED HEREUNDER EXCEPT UNDER
'// THIS DISCLAIMER.
'//
'// Use at your own risk!
'// ==========================================================

#INCLUDE THIS ONCE
%FREEIMAGE_INC = 1

#INCLUDE "windows.inc"

' Version information
%FREEIMAGE_MAJOR_VERSION  = 3
%FREEIMAGE_MINOR_VERSION  = 17
%FREEIMAGE_RELEASE_SERIAL = 0

' Memory stream pointer operation flags
#IF NOT %DEF(%SEEK_SET)
%SEEK_SET = 0
%SEEK_CUR = 1
%SEEK_END = 2
#ENDIF

'// Types used in the library (specific to FreeImage) ------------------------

' /** 48-bit RGB
TYPE FIRGB16
   red   AS WORD
   green AS WORD
   blue  AS WORD
END TYPE

' /** 64-bit RGBA
TYPE FIRGBA16
   red   AS WORD
   green AS WORD
   blue  AS WORD
   alpha AS WORD
END TYPE

' /** 96-bit RGB Float
TYPE FIRGBF
   red   AS SINGLE
   green AS SINGLE
   blue  AS SINGLE
END TYPE

' /** 128-bit RGBA Float
TYPE FIRGBAF
   red   AS SINGLE
   green AS SINGLE
   blue  AS SINGLE
   alpha AS SINGLE
END TYPE

' /** Data structure for COMPLEX type (complex number)
TYPE FICOMPLEX
   r AS DOUBLE    ' Real part
   i AS DOUBLE    ' Imaginary part
END TYPE

'// Indexes for byte arrays, masks and shifts for treating pixels as words ---
'// These coincide with the order of RGBQUAD and RGBTRIPLE -------------------
'// Little Endian (x86 / MS Windows, Linux) : BGR(A) order

%FI_RGBA_RED          = 2
%FI_RGBA_GREEN        = 1
%FI_RGBA_BLUE         = 0
%FI_RGBA_ALPHA        = 3
%FI_RGBA_RED_MASK     = &H00FF0000
%FI_RGBA_GREEN_MASK   = &H0000FF00
%FI_RGBA_BLUE_MASK    = &H000000FF
%FI_RGBA_ALPHA_MASK   = &HFF000000
%FI_RGBA_RED_SHIFT    = 16
%FI_RGBA_GREEN_SHIFT  = 8
%FI_RGBA_BLUE_SHIFT   = 0
%FI_RGBA_ALPHA_SHIFT  = 24
%FI_RGBA_RGB_MASK     = %FI_RGBA_RED_MASK OR %FI_RGBA_GREEN_MASK OR %FI_RGBA_BLUE_MASK

' // The 16 bit macros only include masks and shifts, since each color element is not byte aligned
%FI16_555_RED_MASK    = &H7C00
%FI16_555_GREEN_MASK  = &H03E0
%FI16_555_BLUE_MASK   = &H001F
%FI16_555_RED_SHIFT   = 10
%FI16_555_GREEN_SHIFT = 5
%FI16_555_BLUE_SHIFT  = 0
%FI16_565_RED_MASK    = &HF800
%FI16_565_GREEN_MASK  = &H07E0
%FI16_565_BLUE_MASK   = &H001F
%FI16_565_RED_SHIFT   = 11
%FI16_565_GREEN_SHIFT = 5
%FI16_565_BLUE_SHIFT  = 0

' / ** ICC profile support ---------------------------------------------------------------

%FIICC_DEFAULT        = &H00
%FIICC_COLOR_IS_CMYK  = &H01

TYPE FIICCPROFILE
   flags AS WORD    ' // info flag
   size  AS DWORD   ' // profile's size measured in bytes
   data  AS DWORD   ' // points to a block of contiguous memory containing the profile
END TYPE

'// Important enums ----------------------------------------------------------

' Enum FREE_IMAGE_FORMAT

%FIF_UNKNOWN = -1
%FIF_BMP     = 0
%FIF_ICO     = 1
%FIF_JPEG    = 2
%FIF_JNG     = 3
%FIF_KOALA   = 4
%FIF_LBM     = 5
%FIF_IFF     = %FIF_LBM
%FIF_MNG     = 6
%FIF_PBM     = 7
%FIF_PBMRAW  = 8
%FIF_PCD     = 9
%FIF_PCX     = 10
%FIF_PGM     = 11
%FIF_PGMRAW  = 12
%FIF_PNG     = 13
%FIF_PPM     = 14
%FIF_PPMRAW  = 15
%FIF_RAS     = 16
%FIF_TARGA   = 17
%FIF_TIFF    = 18
%FIF_WBMP    = 19
%FIF_PSD     = 20
%FIF_CUT     = 21
%FIF_XBM     = 22
%FIF_XPM     = 23
%FIF_DDS     = 24
%FIF_GIF     = 25
%FIF_HDR     = 26
%FIF_FAXG3   = 27
%FIF_SGI     = 28
%FIF_EXR     = 29
%FIF_J2K     = 30
%FIF_JP2     = 31
%FIF_PFM     = 32
%FIF_PICT    = 33
%FIF_RAW     = 34
%FIF_WEBP    = 35
%FIF_JXR     = 36

' Enum FREE_IMAGE_TYPE
' /** Image type used in FreeImage.

%FIT_UNKNOWN = 0      ' Unknown type
%FIT_BITMAP  = 1      ' Standard image           : 1-, 4-, 8-, 16-, 24-, 32-bit
%FIT_UINT16  = 2      ' Array of unsigned short  : unsigned 16-bit
%FIT_INT16   = 3      ' Array of short           : signed 16-bit
%FIT_UINT32  = 4      ' Array of unsigned long   : unsigned 32-bit
%FIT_INT32   = 5      ' Array of long            : signed 32-bit
%FIT_FLOAT   = 6      ' Array of float           : 32-bit IEEE floating point
%FIT_DOUBLE  = 7      ' Array of double          : 64-bit IEEE floating point
%FIT_COMPLEX = 8      ' Array of FICOMPLEX       : 2 x 64-bit IEEE floating point
%FIT_RGB16   = 9      ' 48-bit RGB image         : 3 x 16-bit
%FIT_RGBA16  = 10     ' 64-bit RGBA image        : 4 x 16-bit
%FIT_RGBF    = 11     ' 96-bit RGB float image   : 3 x 32-bit IEEE floating point
%FIT_RGBAF   = 12     ' 128-bit RGBA float image : 4 x 32-bit IEEE floating point

' Enum FREE_IMAGE_COLOR_TYPE
' /** Image color type used in FreeImage.

%FIC_MINISWHITE = 0   ' Minimum value is white
%FIC_MINISBLACK = 1   ' Minimum value is black
%FIC_RGB        = 2   ' RGB color model
%FIC_PALETTE    = 3   ' Color map indexed
%FIC_RGBALPHA   = 4   ' RGB color model with alpha channel
%FIC_CMYK       = 5   ' CMYK color model

' Enum FREE_IMAGE_QUANTIZE
' /** Color quantization algorithms.
' Constants used in FreeImage_ColorQuantize.

%FIQ_WUQUANT = 0      ' Xiaolin Wu color quantization algorithm
%FIQ_NNQUANT = 1      ' NeuQuant neural-net quantization algorithm by Anthony Dekker

' Enum FREE_IMAGE_DITHER
' /** Dithering algorithms.
' Constants used in FreeImage_Dither.

%FID_FS           = 0   ' Floyd & Steinberg error diffusion
%FID_BAYER4x4     = 1   ' Bayer ordered dispersed dot dithering (order 2 dithering matrix)
%FID_BAYER8x8     = 2   ' Bayer ordered dispersed dot dithering (order 3 dithering matrix)
%FID_CLUSTER6x6   = 3   ' Ordered clustered dot dithering (order 3 - 6x6 matrix)
%FID_CLUSTER8x8   = 4   ' Ordered clustered dot dithering (order 4 - 8x8 matrix)
%FID_CLUSTER16x16 = 5   ' Ordered clustered dot dithering (order 8 - 16x16 matrix)
%FID_BAYER16x16   = 6   ' Bayer ordered dispersed dot dithering (order 4 dithering matrix)

' Enum FREE_IMAGE_JPEG_OPERATION
' /** Lossless JPEG transformations
' Constants used in FreeImage_JPEGTransform

%FIJPEG_OP_NONE       = 0   ' No transformation
%FIJPEG_OP_FLIP_H     = 1   ' Horizontal flip
%FIJPEG_OP_FLIP_V     = 2   ' Vertical flip
%FIJPEG_OP_TRANSPOSE  = 3   ' Transpose across UL-to-LR axis
%FIJPEG_OP_TRANSVERSE = 4   ' Transpose across UR-to-LL axis
%FIJPEG_OP_ROTATE_90  = 5   ' 90-degree clockwise rotation
%FIJPEG_OP_ROTATE_180 = 6   ' 180-degree rotation
%FIJPEG_OP_ROTATE_270 = 7   ' 270-degree clockwise (or 90 ccw)

' Enum FREE_IMAGE_TMO
' /** Tone mapping operators.
' Constants used in FreeImage_ToneMapping.

%FITMO_DRAGO03    = 0       ' Adaptive logarithmic mapping (F. Drago, 2003)
%FITMO_REINHARD05 = 1       ' Dynamic range reduction inspired by photoreceptor physiology (E. Reinhard, 2005)
%FITMO_FATTAL02   = 2       ' Gradient domain high dynamic range compression (R. Fattal, 2002)

' Enum FREE_IMAGE_FILTER
' /** Upsampling / downsampling filters.
' Constants used in FreeImage_Rescale.

%FILTER_BOX        = 0      ' Box, pulse, Fourier window, 1st order (constant) b-spline
%FILTER_BICUBIC    = 1      ' Mitchell & Netravali's two-param cubic filter
%FILTER_BILINEAR   = 2      ' Bilinear filter
%FILTER_BSPLINE    = 3      ' 4th order (cubic) b-spline
%FILTER_CATMULLROM = 4      ' Catmull-Rom spline, Overhauser spline
%FILTER_LANCZOS3   = 5      ' Lanczos3 filter

' Enum FREE_IMAGE_COLOR_CHANNEL
' /** Color channels.
' Constants used in color manipulation routines.

%FICC_RGB   = 0    ' Use red, green and blue channels
%FICC_RED   = 1    ' Use red channel
%FICC_GREEN = 2    ' Use green channel
%FICC_BLUE  = 3    ' Use blue channel
%FICC_ALPHA = 4    ' Use alpha channel
%FICC_BLACK = 5    ' Use black channel
%FICC_REAL  = 6    ' Complex images: use real part
%FICC_IMAG  = 7    ' Complex images: use imaginary part
%FICC_MAG   = 8    ' Complex images: use magnitude
%FICC_PHASE = 9    ' Complex images: use phase

' // Metadata support --------------------------------------------------------------------

' Enum FREE_IMAGE_MDTYPE
' Tag data type information (based on TIFF specifications)
' Note: RATIONALs are the ratio of two 32-bit integer values.

%FIDT_NOTYPE    = 0     ' // placeholder
%FIDT_BYTE      = 1     ' // 8-bit unsigned integer
%FIDT_ASCII     = 2     ' // 8-bit bytes w/ last byte null
%FIDT_SHORT     = 3     ' // 16-bit unsigned integer
%FIDT_LONG      = 4     ' // 32-bit unsigned integer
%FIDT_RATIONAL  = 5     ' // 64-bit unsigned fraction
%FIDT_SBYTE     = 6     ' // 8-bit signed integer
%FIDT_UNDEFINED = 7     ' // 8-bit untyped data
%FIDT_SSHORT    = 8     ' // 16-bit signed integer
%FIDT_SLONG     = 9     ' // 32-bit signed integer
%FIDT_SRATIONAL = 10    ' // 64-bit signed fraction
%FIDT_FLOAT     = 11    ' // 32-bit IEEE floating point
%FIDT_DOUBLE    = 12    ' // 64-bit IEEE floating point
%FIDT_IFD       = 13    ' // 32-bit unsigned integer (offset)
%FIDT_PALETTE   = 14    ' // 32-bit RGBQUAD
%FIDT_LONG8     = 16    ' // 64-bit unsigned integer
%FIDT_SLONG8    = 17    ' // 64-bit signed integer
%FIDT_IFD8      = 18    ' // 64-bit unsigned integer (offset)

' Enum FREE_IMAGE_MDMODEL
' Metadata models supported by FreeImage

%FIMD_NODATA         = -1
%FIMD_COMMENTS       = 0    ' Single comment or keywords
%FIMD_EXIF_MAIN      = 1    ' Exif-TIFF metadata
%FIMD_EXIF_EXIF      = 2    ' Exif-specific metadata
%FIMD_EXIF_GPS       = 3    ' Exif GPS metadata
%FIMD_EXIF_MAKERNOTE = 4    ' Exif maker note metadata
%FIMD_EXIF_INTEROP   = 5    ' Exif interoperability metadata
%FIMD_IPTC           = 6    ' IPTC/NAA metadata
%FIMD_XMP            = 7    ' Abobe XMP metadata
%FIMD_GEOTIFF        = 8    ' GeoTIFF metadata
%FIMD_ANIMATION      = 9    ' Animation metadata
%FIMD_CUSTOM         = 10   ' Used to attach other metadata types to a dib
%FIMD_EXIF_RAW       = 11   ' Exif metadata as a raw buffer

'/**
'  Handle to a metadata model
'*/
'FI_STRUCT (FIMETADATA) { void *data; };

'/**
'  Handle to a FreeImage tag
'*/
'FI_STRUCT (FITAG) { void *data; };


' // File IO routines --------------------------------------------------------------------

'typedef void* fi_handle;
'typedef unsigned (DLL_CALLCONV *FI_ReadProc) (void *buffer, unsigned size, unsigned count, fi_handle handle);
'typedef unsigned (DLL_CALLCONV *FI_WriteProc) (void *buffer, unsigned size, unsigned count, fi_handle handle);
'typedef int (DLL_CALLCONV *FI_SeekProc) (fi_handle handle, long offset, int origin);
'typedef long (DLL_CALLCONV *FI_TellProc) (fi_handle handle);

'FUNCTION FI_ReadProc (BYVAL buffer AS DWORD, BYVAL nsize AS DWORD, BYVAL count AS DWORD, BYVAL fi_handle AS DWORD) AS DWORD
'FUNCTION FI_WriteProc (BYVAL buffer AS DWORD, BYVAL nsize AS DWORD, BYVAL count AS DWORD, BYVAL fi_handle AS DWORD) AS DWORD
'FUNCTION FI_SeekProc (BYVAL hndl AS DWORD, BYVAL offset AS LONG, BYVAL origin AS LONG) AS LONG
'FUNCTION FI_TellProc (BYVAL hndl AS DWORD) AS LONG

TYPE FreeImageIO
   read_proc  AS DWORD    ' // FI_ReadProc - pointer to the function used to read data
   write_proc AS DWORD    ' // FI_WriteProc - pointer to the function used to write data
   seek_proc  AS DWORD    ' // FI_SeekProc - pointer to the function used to seek
   tell_proc  AS DWORD    ' // FI_TellProc - pointer to the function used to aquire the current position
END TYPE

'/**
'Handle to a memory I/O stream
'*/
'FI_STRUCT (FIMEMORY) { void *data; };

' // Plugin routines ---------------------------------------------------------------------

'#ifndef PLUGINS
'#define PLUGINS

'typedef const char *(DLL_CALLCONV *FI_FormatProc) ();
'typedef const char *(DLL_CALLCONV *FI_DescriptionProc) ();
'typedef const char *(DLL_CALLCONV *FI_ExtensionListProc) ();
'typedef const char *(DLL_CALLCONV *FI_RegExprProc) ();
'typedef void *(DLL_CALLCONV *FI_OpenProc)(FreeImageIO *io, fi_handle handle, BOOL read);
'typedef void (DLL_CALLCONV *FI_CloseProc)(FreeImageIO *io, fi_handle handle, void *data);
'typedef int (DLL_CALLCONV *FI_PageCountProc)(FreeImageIO *io, fi_handle handle, void *data);
'typedef int (DLL_CALLCONV *FI_PageCapabilityProc)(FreeImageIO *io, fi_handle handle, void *data);
'typedef FIBITMAP *(DLL_CALLCONV *FI_LoadProc)(FreeImageIO *io, fi_handle handle, int page, int flags, void *data);
'typedef BOOL (DLL_CALLCONV *FI_SaveProc)(FreeImageIO *io, FIBITMAP *dib, fi_handle handle, int page, int flags, void *data);
'typedef BOOL (DLL_CALLCONV *FI_ValidateProc)(FreeImageIO *io, fi_handle handle);
'typedef const char *(DLL_CALLCONV *FI_MimeProc) ();
'typedef BOOL (DLL_CALLCONV *FI_SupportsExportBPPProc)(int bpp);
'typedef BOOL (DLL_CALLCONV *FI_SupportsExportTypeProc)(FREE_IMAGE_TYPE type);
'typedef BOOL (DLL_CALLCONV *FI_SupportsICCProfilesProc)();
'typedef BOOL (DLL_CALLCONV *FI_SupportsNoPixelsProc)(void);

'FUNCTION FI_FormatProc () AS DWORD
'FUNCTION FI_DescriptionProc () AS DWORD
'FUNCTION FI_ExtensionListProc () AS DWORD
'FUNCTION FI_RegExprProc () AS DWORD
'SUB FI_OpenProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD, BYVAL bread AS LONG)
'SUB FI_CloseProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD, BYVAL dwdata AS DWORD)
'FUNCTION FI_PageCountProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD, BYVAL dwdata AS DWORD) AS LONG
'FUNCTION FI_PageCapabilityProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD, BYVAL dwdata AS DWORD) AS LONG
'FUNCTION FI_LoadProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD, BYVAL npage AS LONG, BYVAL flags AS LONG, BYVAL dwdata AS DWORD) AS DWORD
'FUNCTION FI_SaveProc (BYREF io AS FreeImageIO, BYVAL dib AS DWORD, BYVAL hndl AS DWORD, BYVAL npage AS LONG, BYVAL flags AS LONG, BYVAL dwdata AS DWORD) AS LONG
'FUNCTION FI_ValidateProc (BYREF io AS FreeImageIO, BYVAL hndl AS DWORD) AS LONG
'FUNCTION FI_MimeProc () AS DWORD
'FUNCTION FI_SupportsExportBPPProc (BYVAL bpp AS LONG) AS LONG
'FUNCTION FI_SupportsExportTypeProc (BYVAL ntype AS LONG) AS LONG
'FUNCTION FI_SupportsICCProfilesProc () AS LONG
'FUNCTION FI_SupportsNoPixelsProc () AS LONG

TYPE Plugin
   format_proc                AS DWORD   ' // FI_FormatProc
   description_proc           AS DWORD   ' // FI_DescriptionProc
   extension_proc             AS DWORD   ' // FI_ExtensionListProc
   regexpr_proc               AS DWORD   ' // FI_RegExprProc
   open_proc                  AS DWORD   ' // FI_OpenProc
   close_proc                 AS DWORD   ' // FI_CloseProc
   pagecount_proc             AS DWORD   ' // FI_PageCountProc
   pagecapability_proc        AS DWORD   ' // FI_PageCapabilityProc
   load_proc                  AS DWORD   ' // FI_LoadProc
   save_proc                  AS DWORD   ' // FI_SaveProc
   validate_proc              AS DWORD   ' // FI_ValidateProc
   mime_proc                  AS DWORD   ' // FI_MimeProc
   supports_export_bpp_proc   AS DWORD   ' // FI_SupportsExportBPPProc
   supports_export_type_proc  AS DWORD   ' // FI_SupportsExportTypeProc
   supports_icc_profiles_proc AS DWORD   ' // FI_SupportsICCProfilesProc
   supports_no_pixels_proc    AS DWORD   ' // FI_SupportsNoPixelsProc
END TYPE

'typedef void (DLL_CALLCONV *FI_InitProc)(Plugin *plugin, int format_id);
'SUB FI_InitProc (BYREF tplugin AS Plugin, BYVAL format_id AS LONG)

'#endif // PLUGINS

'// Load / Save flag constants -----------------------------------------------

%FIF_LOAD_NOPIXELS = &H8000   ' // loading: load the image header only (not supported by all plugins, default to full loading)

%BMP_DEFAULT               = 0
%BMP_SAVE_RLE              = 1
%CUT_DEFAULT               = 0
%DDS_DEFAULT               = 0
%EXR_DEFAULT               = 0         ' // Save data as half with piz-based wavelet compression
%EXR_FLOAT                 = &H0001    ' // Save data as float instead of as half (not recommended)
%EXR_NONE                  = &H0002    ' // Save with no compression
%EXR_ZIP                   = &H0004    ' // Save with zlib compression, in blocks of 16 scan lines
%EXR_PIZ                   = &H0008    ' // Save with piz-based wavelet compression
%EXR_PXR24                 = &H0010    ' // Save with lossy 24-bit float compression
%EXR_B44                   = &H0020    ' // Save with lossy 44% float compression - goes to 22% when combined with EXR_LC
%EXR_LC                    = &H0040    ' // Save images with one luminance and two chroma channels, rather than as RGB (lossy compression)
%FAXG3_DEFAULT             = 0
%GIF_DEFAULT               = 0
%GIF_LOAD256               = 1         ' // Load the image as a 256 color image with ununsed palette entries, if it's 16 or 2 color
%GIF_PLAYBACK              = 2         ' // "Play" the GIF to generate each frame (as 32bpp) instead of returning raw frame data when loading
%HDR_DEFAULT               = 0
%ICO_DEFAULT               = 0
%ICO_MAKEALPHA             = 1         ' // Convert to 32bpp and create an alpha channel from the AND-mask when loading
%IFF_DEFAULT               = 0
%J2K_DEFAULT               = 0         ' // Save with a 16:1 rate
%JP2_DEFAULT               = 0         ' // Save with a 16:1 rate
%JPEG_DEFAULT              = 0
%JPEG_FAST                 = &H0001    ' // Load the file as fast as possible, sacrificing some quality
%JPEG_ACCURATE             = &H0002    ' // Load the file with the best quality, sacrificing some speed
%JPEG_CMYK                 = &H0004    ' // Load separated CMYK "as is" (use 'OR' //to combine with other load flags)
%JPEG_EXIFROTATE           = &H0008    ' // load and rotate according to Exif 'Orientation' tag if available
%JPEG_GREYSCALE            = &H0010    ' // load and convert to a 8-bit greyscale image
%JPEG_QUALITYSUPERB        = &H80
%JPEG_QUALITYGOOD          = &H100
%JPEG_QUALITYNORMAL        = &H200
%JPEG_QUALITYAVERAGE       = &H400
%JPEG_QUALITYBAD           = &H800
%JPEG_PROGRESSIVE          = &H2000    ' // Save as a progressive-JPEG (use 'OR' //to combine with other save flags)
%JPEG_SUBSAMPLING_411      = &H1000    ' // Save with high 4x1 chroma subsampling (4:1:1)
%JPEG_SUBSAMPLING_420      = &H4000    ' // Save with medium 2x2 medium chroma subsampling (4:2:0) - default value
%JPEG_SUBSAMPLING_422      = &H8000    ' // Save with low 2x1 chroma subsampling (4:2:2)
%JPEG_SUBSAMPLING_444      = &H10000   ' // Save with no chroma subsampling (4:4:4)
%JPEG_OPTIMIZE             = &H20000   ' // on saving, compute optimal Huffman coding tables (can reduce a few percent of file size)
%JPEG_BASELINE             = &H40000   ' // save basic JPEG, without metadata or any markers
%KOALA_DEFAULT             = 0
%LBM_DEFAULT               = 0
%MNG_DEFAULT               = 0
%PCD_DEFAULT               = 0
%PCD_BASE                  = 1         ' // Load the bitmap sized 768 x 512
%PCD_BASEDIV4              = 2         ' // Load the bitmap sized 384 x 256
%PCD_BASEDIV16             = 3         ' // Load the bitmap sized 192 x 128
%PCX_DEFAULT               = 0
%PFM_DEFAULT               = 0
%PICT_DEFAULT              = 0
%PNG_DEFAULT               = 0
%PNG_IGNOREGAMMA           = 1         ' // Avoid gamma correction
%PNG_Z_BEST_SPEED          = &H0001    ' // Save using ZLib level 1 compression flag (default value is 6)
%PNG_Z_DEFAULT_COMPRESSION = &H0006    ' // Save using ZLib level 6 compression flag (default recommended value)
%PNG_Z_BEST_COMPRESSION    = &H0009    ' // Save using ZLib level 9 compression flag (default value is 6)
%PNG_Z_NO_COMPRESSION      = &H0100    ' // Save without ZLib compression
%PNG_INTERLACED            = &H0200    ' // Save using Adam7 interlacing (use | to combine with other save flags)
%PNM_DEFAULT               = 0
%PNM_SAVE_RAW              = 0         ' // If set the writer saves in RAW format (i.e. P4, P5 or P6)
%PNM_SAVE_ASCII            = 1         ' // If set the writer saves in ASCII format (i.e. P1, P2 or P3)
%PSD_DEFAULT               = 0
%PSD_CMYK                  = 1         ' // reads tags for separated CMYK (default is conversion to RGB)
%PSD_LAB                   = 2         ' // reads tags for CIELab (default is conversion to RGB)
%RAS_DEFAULT               = 0
%RAW_DEFAULT               = 0         ' // load the file as linear RGB 48-bit
%RAW_PREVIEW               = 1         ' // try to load the embedded JPEG preview with included Exif Data or default to RGB 24-bit
%RAW_DISPLAY               = 2         ' // load the file as RGB 24-bit
%RAW_HALFSIZE              = 4         ' // output a half-size color image
%RAW_UNPROCESSED           = 8         ' // output a FIT_UINT16 raw Bayer image
%SGI_DEFAULT               = 0
%TARGA_DEFAULT             = 0
%TARGA_LOAD_RGB888         = 1         ' // If set the loader converts RGB555 and ARGB8888 -> RGB888
%TARGA_SAVE_RLE            = 2         ' // If set, the writer saves with RLE compression
%TIFF_DEFAULT              = 0
%TIFF_CMYK                 = &H0001    ' // Reads/stores tags for separated CMYK (use 'OR' //to combine with compression flags)
%TIFF_PACKBITS             = &H0100    ' // Save using PACKBITS compression
%TIFF_DEFLATE              = &H0200    ' // Save using DEFLATE compression (a.k.a. ZLIB compression)
%TIFF_ADOBE_DEFLATE        = &H0400    ' // Save using ADOBE DEFLATE compression
%TIFF_NONE                 = &H0800    ' // Save without any compression
%TIFF_CCITTFAX3            = &H1000    ' // Save using CCITT Group 3 fax encoding
%TIFF_CCITTFAX4            = &H2000    ' // Save using CCITT Group 4 fax encoding
%TIFF_LZW                  = &H4000    ' // Save using LZW compression
%TIFF_JPEG                 = &H8000    ' // Save using JPEG compression
%TIFF_LOGLUV               = &H10000   ' // save using LogLuv compression
%WBMP_DEFAULT              = 0
%XBM_DEFAULT               = 0
%XPM_DEFAULT               = 0
%WEBP_DEFAULT              = 0         ' // save with good quality (75:1)
%WEBP_LOSSLESS             = &H100     ' // save in lossless mode
%JXR_DEFAULT               = 0         ' // save with quality 80 and no chroma subsampling (4:4:4)
%JXR_LOSSLESS              = &H0064    ' // save lossless
%JXR_PROGRESSIVE           = &H2000    ' // save as a progressive-JXR (use | to combine with other save flags)

'// Background filling options ---------------------------------------------------------
'// Constants used in FreeImage_FillBackground and FreeImage_EnlargeCanvas

%FI_COLOR_IS_RGB_COLOR        = &H00   ' // RGBQUAD color is a RGB color (contains no valid alpha channel)
%FI_COLOR_IS_RGBA_COLOR       = &H01   ' // RGBQUAD color is a RGBA color (contains a valid alpha channel)
%FI_COLOR_FIND_EQUAL_COLOR    = &H02   ' // For palettized images: lookup equal RGB color from palette
%FI_COLOR_ALPHA_IS_INDEX      = &H04   ' // The color's rgbReserved member (alpha) contains the palette index to be used
%FI_COLOR_PALETTE_SEARCH_MASK = %FI_COLOR_FIND_EQUAL_COLOR OR %FI_COLOR_ALPHA_IS_INDEX   ' // No color lookup is performed

'// RescaleEx options ---------------------------------------------------------
'// Constants used in FreeImage_RescaleEx

%FI_RESCALE_DEFAULT       = &H00   ' // default options; none of the following other options apply
%FI_RESCALE_TRUE_COLOR    = &H01   ' // for non-transparent greyscale images, convert to 24-bit if src bitdepth <= 8 (default is a 8-bit greyscale image).
%FI_RESCALE_OMIT_METADATA = &H02   ' // do not copy metadata to the rescaled image

' ########################################################################################
'                                 Init / Error routines
' ########################################################################################

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_Initialise(BOOL load_local_plugins_only FI_DEFAULT(FALSE));
' ========================================================================================
DECLARE SUB FreeImage_Initialise IMPORT "FreeImage.dll" ALIAS "_FreeImage_Initialise@4" ( _
   OPTIONAL BYVAL load_local_plugins_only AS LONG _     ' BOOL load_local_plugins_only FI_DEFAULT(FALSE)
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_DeInitialise(void);
' ========================================================================================
DECLARE SUB FreeImage_DeInitialise IMPORT "FreeImage.dll" ALIAS "_FreeImage_DeInitialise@0" ( _
 )                                                      ' void
' ========================================================================================


' ########################################################################################
'                                      Version routines
' ########################################################################################

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetVersion(void);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetVersion IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetVersion@0" ( _
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetCopyrightMessage(void);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetCopyrightMessage IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetCopyrightMessage@0" ( _
 ) AS DWORD                                             ' const char *
' ========================================================================================


' ########################################################################################
'                                  Message output functions
' ########################################################################################

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_OutputMessageProc(int fif, const char *fmt, ...);
' ========================================================================================
'SUB FreeImage_OutputMessageProc _
'   IMPORT "FreeImage.dll" ALIAS "FreeImage_OutputMessageProc" ( _
'   BYVAL fif AS LONG, _
'   BYREF szFmt AS ASCIIZ, _
'   OPTIONAL BYREF param1 AS ANY, _
'   OPTIONAL BYREF param2 AS ANY, _
'   etc.
')
' ========================================================================================

'typedef void (*FreeImage_OutputMessageFunction)(FREE_IMAGE_FORMAT fif, const char *msg);
'SUB FreeImage_OutputMessageFunction CDECL (BYVAL fif AS LONG, BYREF msg AS ASCIIZ)

'typedef void (DLL_CALLCONV *FreeImage_OutputMessageFunctionStdCall)(FREE_IMAGE_FORMAT fif, const char *msg);
'SUB FreeImage_OutputMessageFunctionStdCall (BYVAL fif AS LONG, BYREF msg AS ASCIIZ)

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetOutputMessageStdCall(
' FreeImage_OutputMessageFunctionStdCall omf);
' ========================================================================================
DECLARE SUB FreeImage_SetOutputMessageStdCall IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetOutputMessageStdCall@4" ( _
   BYVAL omf AS  DWORD _                                ' FreeImage_OutputMessageFunctionStdCall omf
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetOutputMessage(FreeImage_OutputMessageFunction omf);
' ========================================================================================
DECLARE SUB FreeImage_SetOutputMessage IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetOutputMessage@4" ( _
   BYVAL omf AS DWORD _                                 ' FreeImage_OutputMessageFunction omf
 )                                                      ' void
' ========================================================================================


' ########################################################################################
'                             Allocate / Clone / Unload routines
' ########################################################################################

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Allocate(int width, int height, int bpp,
' unsigned red_mask FI_DEFAULT(0), unsigned green_mask FI_DEFAULT(0),
' unsigned blue_mask FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_Allocate IMPORT "FreeImage.dll" ALIAS "_FreeImage_Allocate@24" ( _
   BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , BYVAL bpp AS LONG _                                  ' int bpp
 , OPTIONAL BYVAL red_mask AS DWORD _                   ' unsigned red_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL green_mask AS DWORD _                 ' unsigned green_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL blue_mask AS DWORD _                  ' unsigned blue_mask FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_AllocateT(FREE_IMAGE_TYPE type, int width,
' int height, int bpp FI_DEFAULT(8), unsigned red_mask FI_DEFAULT(0),
' unsigned green_mask FI_DEFAULT(0), unsigned blue_mask FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_AllocateT IMPORT "FreeImage.dll" ALIAS "_FreeImage_AllocateT@28" ( _
   BYVAL type AS LONG _                                 ' FREE_IMAGE_TYPE type
 , BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , OPTIONAL BYVAL bpp AS LONG _                         ' int bpp FI_DEFAULT(8)
 , OPTIONAL BYVAL red_mask AS DWORD _                   ' unsigned red_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL green_mask AS DWORD _                 ' unsigned green_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL blue_mask AS DWORD _                  ' unsigned blue_mask FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP * DLL_CALLCONV FreeImage_Clone(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_Clone IMPORT "FreeImage.dll" ALIAS "_FreeImage_Clone@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_Unload(FIBITMAP *dib);
' ========================================================================================
DECLARE SUB FreeImage_Unload IMPORT "FreeImage.dll" ALIAS "_FreeImage_Unload@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 )                                                      ' void
' ========================================================================================

' ########################################################################################
'                                  Header loading routines
' ########################################################################################

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_HasPixels(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_HasPixels IMPORT "FreeImage.dll" ALIAS "_FreeImage_HasPixels@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                                  Load / Save routines
' ########################################################################################

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Load(FREE_IMAGE_FORMAT fif, const char *filename,
' int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_Load IMPORT "FreeImage.dll" ALIAS "_FreeImage_Load@12" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYREF filename AS ASCIIZ _                           ' const char *filename
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_LoadU(FREE_IMAGE_FORMAT fif,
' const wchar_t *filename, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_LoadU IMPORT "FreeImage.dll" ALIAS "_FreeImage_LoadU@12" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL filename AS DWORD _                            ' const wchar_t *filename
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_LoadFromHandle(FREE_IMAGE_FORMAT fif,
' FreeImageIO *io, fi_handle handle, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_LoadFromHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_LoadFromHandle@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYREF io AS FreeImageIO _                            ' FreeImageIO *io
 , BYVAL handle AS DWORD _                              ' fi_handle handle
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_Save(FREE_IMAGE_FORMAT fif, FIBITMAP *dib,
' const char *filename, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_Save IMPORT "FreeImage.dll" ALIAS "_FreeImage_Save@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF filename AS ASCIIZ _                           ' const char *filename
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SaveU(FREE_IMAGE_FORMAT fif, FIBITMAP *dib,
' const wchar_t *filename, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_SaveU IMPORT "FreeImage.dll" ALIAS "_FreeImage_SaveU@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL filename AS DWORD _                            ' const wchar_t *filename
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SaveToHandle(FREE_IMAGE_FORMAT fif, FIBITMAP *dib,
' FreeImageIO *io, fi_handle handle, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_SaveToHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_SaveToHandle@20" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF io AS FreeImageIO _                            ' FreeImageIO *io
 , BYVAL handle AS DWORD _                              ' fi_handle handle
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                               Memory I/O stream routines
' ########################################################################################

' ========================================================================================
' DLL_API FIMEMORY *DLL_CALLCONV FreeImage_OpenMemory(BYTE *data FI_DEFAULT(0),
' DWORD size_in_bytes FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_OpenMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_OpenMemory@8" ( _
   OPTIONAL BYREF data AS ANY _                         ' BYTE *data FI_DEFAULT(0)
 , OPTIONAL BYVAL size_in_bytes AS DWORD _              ' DWORD size_in_bytes FI_DEFAULT(0)
 ) AS DWORD                                             ' FIMEMORY *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_CloseMemory(FIMEMORY *stream);
' ========================================================================================
DECLARE SUB FreeImage_CloseMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_CloseMemory@4" ( _
   BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_LoadFromMemory(FREE_IMAGE_FORMAT fif,
' FIMEMORY *stream, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_LoadFromMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_LoadFromMemory@12" ( _
   BYVAL fif AS  LONG _                                 ' FREE_IMAGE_FORMAT fif
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SaveToMemory(FREE_IMAGE_FORMAT fif, FIBITMAP *dib,
' FIMEMORY *stream, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_SaveToMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_SaveToMemory@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API long DLL_CALLCONV FreeImage_TellMemory(FIMEMORY *stream);
' ========================================================================================
DECLARE FUNCTION FreeImage_TellMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_TellMemory@4" ( _
   BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SeekMemory(FIMEMORY *stream, long offset, int origin);
' ========================================================================================
DECLARE FUNCTION FreeImage_SeekMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_SeekMemory@12" ( _
   BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , BYVAL offset AS LONG _                               ' long offset
 , BYVAL origin AS LONG _                               ' int origin
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AcquireMemory(FIMEMORY *stream, BYTE **data,
' DWORD *size_in_bytes);
' ========================================================================================
DECLARE FUNCTION FreeImage_AcquireMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_AcquireMemory@12" ( _
   BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , BYREF data AS ANY _                                  ' BYTE **data
 , BYREF size_in_bytes AS DWORD _                       ' DWORD *size_in_bytes
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_ReadMemory(void *buffer, unsigned size,
' unsigned count, FIMEMORY *stream);
' ========================================================================================
DECLARE FUNCTION FreeImage_ReadMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_ReadMemory@16" ( _
   BYREF buffer AS ANY _                                ' void *buffer
 , BYVAL size AS DWORD _                                ' unsigned size
 , BYVAL count AS DWORD _                               ' unsigned count
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_WriteMemory(const void *buffer, unsigned size,
' unsigned count, FIMEMORY *stream);
' ========================================================================================
DECLARE FUNCTION FreeImage_WriteMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_WriteMemory@16" ( _
   BYREF buffer AS ANY _                                ' const void *buffer
 , BYVAL size AS DWORD _                                ' unsigned size
 , BYVAL count AS DWORD _                               ' unsigned count
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API FIMULTIBITMAP *DLL_CALLCONV FreeImage_LoadMultiBitmapFromMemory
' (FREE_IMAGE_FORMAT fif, FIMEMORY *stream, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_LoadMultiBitmapFromMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_LoadMultiBitmapFromMemory@12" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIMULTIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SaveMultiBitmapToMemory(FREE_IMAGE_FORMAT fif,
' FIMULTIBITMAP *bitmap, FIMEMORY *stream, int flags);
' ========================================================================================
DECLARE FUNCTION FreeImage_SaveMultiBitmapToMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_SaveMultiBitmapToMemory@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIMULTIBITMAP *
' ========================================================================================


' ########################################################################################
'                                  Plugin Interface
' ########################################################################################

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_RegisterLocalPlugin(
' FI_InitProc proc_address, const char *format FI_DEFAULT(0),
' const char *description FI_DEFAULT(0), const char *extension FI_DEFAULT(0),
' const char *regexpr FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_RegisterLocalPlugin IMPORT "FreeImage.dll" ALIAS "_FreeImage_RegisterLocalPlugin@20" ( _
   BYVAL proc_address AS DWORD _                        ' FI_InitProc proc_address
 , OPTIONAL BYREF format AS ASCIIZ _                    ' const char *format FI_DEFAULT(0)
 , OPTIONAL BYREF description AS ASCIIZ _               ' const char *description FI_DEFAULT(0)
 , OPTIONAL BYREF extension AS ASCIIZ _                 ' const char *extension FI_DEFAULT(0)
 , OPTIONAL BYREF regexpr AS ASCIIZ _                   ' const char *regexpr FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_RegisterExternalPlugin(const char *path,
' const char *format FI_DEFAULT(0), const char *description FI_DEFAULT(0),
' const char *extension FI_DEFAULT(0), const char *regexpr FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_RegisterExternalPlugin IMPORT "FreeImage.dll" ALIAS "_FreeImage_RegisterExternalPlugin@20" ( _
   BYREF path AS ASCIIZ _                              ' const char *path
 , OPTIONAL BYREF format AS ASCIIZ _                    ' const char *format FI_DEFAULT(0)
 , OPTIONAL BYREF description AS ASCIIZ _               ' const char *description FI_DEFAULT(0)
 , OPTIONAL BYREF extension AS ASCIIZ _                 ' const char *extension FI_DEFAULT(0)
 , OPTIONAL BYREF regexpr AS ASCIIZ _                   ' const char *regexpr FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API int DLL_CALLCONV FreeImage_GetFIFCount(void);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFCount@0" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' DLL_API int DLL_CALLCONV FreeImage_SetPluginEnabled(FREE_IMAGE_FORMAT fif, BOOL enable);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetPluginEnabled IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetPluginEnabled@8" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL enable AS LONG _                               ' BOOL enable
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' DLL_API int DLL_CALLCONV FreeImage_IsPluginEnabled(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_IsPluginEnabled IMPORT "FreeImage.dll" ALIAS "_FreeImage_IsPluginEnabled@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFIFFromFormat(const char *format);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFFromFormat IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFFromFormat@4" ( _
   BYREF format AS ASCIIZ _                             ' const char *format
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFIFFromMime(const char *mime);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFFromMime IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFFromMime@4" ( _
   BYREF mime AS  ASCIIZ _                              ' const char *mime
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetFormatFromFIF(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFormatFromFIF IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFormatFromFIF@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetFIFExtensionList(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFExtensionList IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFExtensionList@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetFIFDescription(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFDescription IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFDescription@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetFIFRegExpr(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFRegExpr IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFRegExpr@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetFIFMimeType(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFMimeType IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFMimeType@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFIFFromFilename(const char *filename);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFFromFilename IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFFromFilename@4" ( _
   BYREF filename AS ASCIIZ _                           ' const char *filename
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFIFFromFilenameU(const wchar_t *filename);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFIFFromFilenameU IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFIFFromFilenameU@4" ( _
   BYVAL filename AS DWORD _                            ' const wchar_t *filename
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsReading(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsReading IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsReading@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsWriting(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsWriting IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsWriting@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsExportBPP(FREE_IMAGE_FORMAT fif, int bpp);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsExportBPP IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsExportBPP@8" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL bpp AS LONG _                                  ' int bpp
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsExportType(FREE_IMAGE_FORMAT fif,
' FREE_IMAGE_TYPE type);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsExportType IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsExportType@8" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL type AS LONG _                                 ' FREE_IMAGE_TYPE type
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsICCProfiles(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsICCProfiles IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsICCProfiles@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FIFSupportsNoPixels(FREE_IMAGE_FORMAT fif);
' ========================================================================================
DECLARE FUNCTION FreeImage_FIFSupportsNoPixels IMPORT "FreeImage.dll" ALIAS "_FreeImage_FIFSupportsNoPixels@4" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                                 Multipaging interface
' ########################################################################################

' ========================================================================================
' DLL_API FIMULTIBITMAP * DLL_CALLCONV FreeImage_OpenMultiBitmap(FREE_IMAGE_FORMAT fif,
' const char *filename, BOOL create_new, BOOL read_only, BOOL keep_cache_in_memory FI_DEFAULT(FALSE),
' int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_OpenMultiBitmap IMPORT "FreeImage.dll" ALIAS "_FreeImage_OpenMultiBitmap@24" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYREF filename AS ASCIIZ _                           ' const char *filename
 , BYVAL create_new AS LONG _                           ' BOOL create_new
 , BYVAL read_only AS LONG _                            ' BOOL read_only
 , OPTIONAL BYVAL keep_cache_in_memory AS LONG _        ' BOOL keep_cache_in_memory FI_DEFAULT(FALSE)
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIMULTIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIMULTIBITMAP * DLL_CALLCONV FreeImage_OpenMultiBitmapFromHandle(FREE_IMAGE_FORMAT fif,
' FreeImageIO *io, fi_handle handle, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_OpenMultiBitmapFromHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_OpenMultiBitmapFromHandle@16" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYREF io AS FreeImageIO _                            ' FreeImageIO *io
 , BYVAL handle AS DWORD _                              ' fi_handle handle
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS DWORD                                             ' FIMULTIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SaveMultiBitmapToHandle(FREE_IMAGE_FORMAT fif,
' FIMULTIBITMAP *bitmap, FreeImageIO *io, fi_handle handle, int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_SaveMultiBitmapToHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_SaveMultiBitmapToHandle@20" ( _
   BYVAL fif AS LONG _                                  ' FREE_IMAGE_FORMAT fif
 , BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYREF io AS FreeImageIO _                            ' FreeImageIO *io
 , BYVAL handle AS DWORD _                              ' fi_handle handle
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_CloseMultiBitmap(FIMULTIBITMAP *bitmap,
' int flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_CloseMultiBitmap IMPORT "FreeImage.dll" ALIAS "_FreeImage_CloseMultiBitmap@8" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , OPTIONAL BYVAL flags AS LONG _                       ' int flags FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API int DLL_CALLCONV FreeImage_GetPageCount(FIMULTIBITMAP *bitmap);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetPageCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetPageCount@4" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_AppendPage(FIMULTIBITMAP *bitmap, FIBITMAP *data);
' ========================================================================================
DECLARE SUB FreeImage_AppendPage IMPORT "FreeImage.dll" ALIAS "_FreeImage_AppendPage@8" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL data AS DWORD _                                ' FIBITMAP *data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_InsertPage(FIMULTIBITMAP *bitmap, int page,
' FIBITMAP *data);
' ========================================================================================
DECLARE SUB FreeImage_InsertPage IMPORT "FreeImage.dll" ALIAS "_FreeImage_InsertPage@12" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL page AS LONG _                                 ' int page
 , BYVAL data AS DWORD _                                ' FIBITMAP *data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_DeletePage(FIMULTIBITMAP *bitmap, int page);
' ========================================================================================
DECLARE SUB FreeImage_DeletePage IMPORT "FreeImage.dll" ALIAS "_FreeImage_DeletePage@8" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL page AS LONG _                                 ' int page
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP * DLL_CALLCONV FreeImage_LockPage(FIMULTIBITMAP *bitmap, int page);
' ========================================================================================
DECLARE FUNCTION FreeImage_LockPage IMPORT "FreeImage.dll" ALIAS "_FreeImage_LockPage@8" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL page AS LONG _                                 ' int page
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_UnlockPage(FIMULTIBITMAP *bitmap, FIBITMAP *page,
' BOOL changed);
' ========================================================================================
DECLARE SUB FreeImage_UnlockPage IMPORT "FreeImage.dll" ALIAS "_FreeImage_UnlockPage@12" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL data AS DWORD _                                ' FIBITMAP *data
 , BYVAL changed AS LONG _                              ' BOOL changed
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_MovePage(FIMULTIBITMAP *bitmap, int target, int source);
' ========================================================================================
DECLARE FUNCTION FreeImage_MovePage IMPORT "FreeImage.dll" ALIAS "_FreeImage_MovePage@12" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYVAL target AS LONG _                               ' int target
 , BYVAL source AS LONG _                               ' int source
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetLockedPageNumbers(FIMULTIBITMAP *bitmap,
' int *pages, int *count);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetLockedPageNumbers IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetLockedPageNumbers@12" ( _
   BYVAL bitmap AS DWORD _                              ' FIMULTIBITMAP *bitmap
 , BYREF pages AS LONG _                                ' int *pages
 , BYREF count AS LONG _                                ' int *count
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                               Filetype request routines
' ########################################################################################

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFileType(const char *filename,
' int size FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFileType IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFileType@8" ( _
   BYREF filename AS ASCIIZ _                           ' const char *filename
 , OPTIONAL BYVAL size AS LONG _                        ' int size FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFileTypeU(const wchar_t *filename,
' int size FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFileTypeU IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFileTypeU@8" ( _
   BYVAL filename AS  DWORD _                           ' const wchar_t *filename
 , OPTIONAL BYVAL size AS LONG _                        ' int size FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFileTypeFromHandle(FreeImageIO *io,
' fi_handle handle, int size FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFileTypeFromHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFileTypeFromHandle@12" ( _
   BYREF io AS FreeImageIO _                            ' FreeImageIO *io
 , BYVAL handle AS DWORD _                              ' fi_handle handle
 , OPTIONAL BYVAL size AS LONG _                        ' int size FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_FORMAT DLL_CALLCONV FreeImage_GetFileTypeFromMemory(FIMEMORY *stream,
' int size FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_GetFileTypeFromMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetFileTypeFromMemory@8" ( _
   BYVAL stream AS DWORD _                              ' FIMEMORY *stream
 , OPTIONAL BYVAL size AS LONG _                        ' int size FI_DEFAULT(0)
 ) AS LONG                                              ' FREE_IMAGE_FORMAT
' ========================================================================================


' ########################################################################################
'                              Image type request routine
' ########################################################################################

' ========================================================================================
' DLL_API FREE_IMAGE_TYPE DLL_CALLCONV FreeImage_GetImageType(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetImageType IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetImageType@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' FREE_IMAGE_TYPE
' ========================================================================================


' ########################################################################################
'                              FreeImage helper routines
' ########################################################################################

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_IsLittleEndian(void);
' ========================================================================================
DECLARE FUNCTION FreeImage_IsLittleEndian IMPORT "FreeImage.dll" ALIAS "_FreeImage_IsLittleEndian@0" ( _
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_LookupX11Color(const char *szColor, BYTE *nRed,
' BYTE *nGreen, BYTE *nBlue);
' ========================================================================================
DECLARE FUNCTION FreeImage_LookupX11Color IMPORT "FreeImage.dll" ALIAS "_FreeImage_LookupX11Color@16" ( _
   BYREF szColor AS ASCIIZ _                            ' const char *szColor
 , BYREF nRed AS BYTE _                                 ' BYTE *nRed
 , BYREF nGreen AS BYTE _                               ' BYTE *nGreen
 , BYREF nBlue AS BYTE _                                ' BYTE *nBlue
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_LookupSVGColor(const char *szColor, BYTE *nRed,
' BYTE *nGreen, BYTE *nBlue);
' ========================================================================================
DECLARE FUNCTION FreeImage_LookupSVGColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_LookupSVGColor@16" ( _
   BYREF szColor AS ASCIIZ _                            ' const char *szColor
 , BYREF nRed AS BYTE _                                 ' BYTE *nRed
 , BYREF nGreen AS BYTE _                               ' BYTE *nGreen
 , BYREF nBlue AS BYTE _                                ' BYTE *nBlue
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                                Pixel access routines
' ########################################################################################

' ========================================================================================
' DLL_API BYTE *DLL_CALLCONV FreeImage_GetBits(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetBits IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetBits@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' BYTE *
' ========================================================================================

' ========================================================================================
' DLL_API BYTE *DLL_CALLCONV FreeImage_GetScanLine(FIBITMAP *dib, int scanline);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetScanLine IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetScanLine@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL scanline AS LONG _                             ' int scanline
 ) AS DWORD                                             ' BYTE *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetPixelIndex(FIBITMAP *dib, unsigned x, unsigned y,
' BYTE *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetPixelIndex IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetPixelIndex@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL x AS DWORD _                                   ' unsigned x
 , BYVAL y AS DWORD _                                   ' unsigned y
 , BYREF value AS DWORD _                               ' BYTE *value
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetPixelColor(FIBITMAP *dib, unsigned x, unsigned y,
' RGBQUAD *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetPixelColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetPixelColor@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL x AS DWORD _                                   ' unsigned x
 , BYVAL y AS DWORD _                                   ' unsigned y
 , BYREF value AS RGBQUAD _                             ' RGBQUAD *value
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetPixelIndex(FIBITMAP *dib, unsigned x, unsigned y,
' BYTE *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetPixelIndex IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetPixelIndex@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL x AS DWORD _                                   ' unsigned x
 , BYVAL y AS DWORD _                                   ' unsigned y
 , BYREF value AS ANY _                                 ' BYTE *value
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetPixelColor(FIBITMAP *dib, unsigned x, unsigned y,
' RGBQUAD *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetPixelColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetPixelColor@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL x AS DWORD _                                   ' unsigned x
 , BYVAL y AS DWORD _                                   ' unsigned y
 , BYREF value AS RGBQUAD _                             ' RGBQUAD *value
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                                 DIB info routines
' ########################################################################################

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetColorsUsed(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetColorsUsed IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetColorsUsed@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetBPP(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetBPP IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetBPP@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetWidth(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetWidth IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetWidth@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetHeight(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetHeight IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetHeight@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetLine(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetLine IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetLine@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetPitch(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetPitch IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetPitch@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetDIBSize(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetDIBSize IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetDIBSize@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetMemorySize(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetMemorySize IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetMemorySize@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API RGBQUAD *DLL_CALLCONV FreeImage_GetPalette(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetPalette IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetPalette@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' RGBQUAD *
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetDotsPerMeterX(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetDotsPerMeterX IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetDotsPerMeterX@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetDotsPerMeterY(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetDotsPerMeterY IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetDotsPerMeterY@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetDotsPerMeterX(FIBITMAP *dib, unsigned res);
' ========================================================================================
DECLARE SUB FreeImage_SetDotsPerMeterX IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetDotsPerMeterX@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL res AS DWORD _                                 ' unsigned res
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetDotsPerMeterY(FIBITMAP *dib, unsigned res);
' ========================================================================================
DECLARE SUB FreeImage_SetDotsPerMeterY IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetDotsPerMeterY@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL res AS DWORD _                                 ' unsigned res
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API BITMAPINFOHEADER *DLL_CALLCONV FreeImage_GetInfoHeader(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetInfoHeader IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetInfoHeader@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' BITMAPINFOHEADER *
' ========================================================================================

' ========================================================================================
' DLL_API BITMAPINFO *DLL_CALLCONV FreeImage_GetInfo(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetInfo IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetInfo@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' BITMAPINFO *
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_COLOR_TYPE DLL_CALLCONV FreeImage_GetColorType(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetColorType IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetColorType@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' FREE_IMAGE_COLOR_TYPE
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetRedMask(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetRedMask IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetRedMask@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetGreenMask(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetGreenMask IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetGreenMask@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetBlueMask(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetBlueMask IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetBlueMask@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetTransparencyCount(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTransparencyCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTransparencyCount@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API BYTE * DLL_CALLCONV FreeImage_GetTransparencyTable(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTransparencyTable IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTransparencyTable@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' BYTE *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetTransparent(FIBITMAP *dib, BOOL enabled);
' ========================================================================================
DECLARE SUB FreeImage_SetTransparent IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTransparent@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL enabled AS LONG _                              ' BOOL enabled
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetTransparencyTable(FIBITMAP *dib, BYTE *table,
' int count);
' ========================================================================================
DECLARE SUB FreeImage_SetTransparencyTable IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTransparencyTable@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF table AS ANY _                                 ' BYTE *table
 , BYVAL count AS LONG _                                ' int count
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_IsTransparent(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_IsTransparent IMPORT "FreeImage.dll" ALIAS "_FreeImage_IsTransparent@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_SetTransparentIndex(FIBITMAP *dib, int index);
' ========================================================================================
DECLARE SUB FreeImage_SetTransparentIndex IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTransparentIndex@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL index AS LONG _                                ' int index
 )                                                      ' void
' ========================================================================================

' ========================================================================================
'  DLL_API int DLL_CALLCONV FreeImage_GetTransparentIndex(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTransparentIndex IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTransparentIndex@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' int
' ========================================================================================


' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_HasBackgroundColor(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_HasBackgroundColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_HasBackgroundColor@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetBackgroundColor(FIBITMAP *dib, RGBQUAD *bkcolor);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetBackgroundColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetBackgroundColor@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF bkcolor AS RGBQUAD _                           ' RGBQUAD *bkcolor
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetBackgroundColor(FIBITMAP *dib, RGBQUAD *bkcolor);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetBackgroundColor IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetBackgroundColor@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF bkcolor AS RGBQUAD _                           ' RGBQUAD *bkcolor
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_GetThumbnail(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetThumbnail IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetThumbnail@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetThumbnail(FIBITMAP *dib, FIBITMAP *thumbnail);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetThumbnail IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetThumbnail@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL thumbnail AS DWORD _                           ' FIBITMAP *thumbnail
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
'                                 ICC profile routines
' ########################################################################################

' ========================================================================================
' DLL_API FIICCPROFILE *DLL_CALLCONV FreeImage_GetICCProfile(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetICCProfile IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetICCProfile@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIICCPROFILE *
' ========================================================================================

' ========================================================================================
' DLL_API FIICCPROFILE *DLL_CALLCONV FreeImage_CreateICCProfile(FIBITMAP *dib, void *data,
' long size);
' ========================================================================================
DECLARE FUNCTION FreeImage_CreateICCProfile IMPORT "FreeImage.dll" ALIAS "_FreeImage_CreateICCProfile@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF data AS DWORD _                                ' void *data
 , BYVAL size AS LONG _                                 ' long size
 ) AS DWORD                                             ' FIICCPROFILE *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_DestroyICCProfile(FIBITMAP *dib);
' ========================================================================================
DECLARE SUB FreeImage_DestroyICCProfile IMPORT "FreeImage.dll" ALIAS "_FreeImage_DestroyICCProfile@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 )                                                      ' void
' ========================================================================================


' ########################################################################################
'                                 Line conversion routines
' ########################################################################################

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To4(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To4 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To4@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine8To4(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine8To4 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine8To4@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To4_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To4_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To4_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To4_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To4_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To4_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine24To4(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine24To4 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine24To4@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine32To4(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine32To4 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine32To4@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To8(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To8 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To8@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine4To8(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine4To8 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine4To8@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To8_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To8_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To8_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To8_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To8_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To8_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine24To8(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine24To8 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine24To8@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine32To8(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine32To8 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine32To8@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To16_555(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To16_555@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine4To16_555(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine4To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine4To16_555@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine8To16_555(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine8To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine8To16_555@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16_565_To16_555(BYTE *target,
' BYTE *source, int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16_565_To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16_565_To16_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine24To16_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine24To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine24To16_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine32To16_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine32To16_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine32To16_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To16_565(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To16_565@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine4To16_565(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine4To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine4To16_565@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine8To16_565(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine8To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine8To16_565@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16_555_To16_565(BYTE *target,
' BYTE *source, int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16_555_To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16_555_To16_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine24To16_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine24To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine24To16_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine32To16_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine32To16_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine32To16_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To24(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To24 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To24@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine4To24(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine4To24 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine4To24@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine8To24(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine8To24 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine8To24@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To24_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To24_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To24_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To24_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To24_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To24_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine32To24(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine32To24 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine32To24@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine1To32(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine1To32 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine1To32@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine4To32(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine4To32 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine4To32@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine8To32(BYTE *target, BYTE *source,
' int width_in_pixels, RGBQUAD *palette);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine8To32 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine8To32@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 , BYREF palette AS RGBQUAD _                           ' RGBQUAD *palette
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To32_555(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To32_555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To32_555@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine16To32_565(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine16To32_565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine16To32_565@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertLine24To32(BYTE *target, BYTE *source,
' int width_in_pixels);
' ========================================================================================
DECLARE SUB FreeImage_ConvertLine24To32 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertLine24To32@12" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL width_in_pixels AS LONG _                      ' int width_in_pixels
 )                                                      ' void
' ========================================================================================


' ########################################################################################
'                                Smart conversion routines
' ########################################################################################

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo4Bits(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo4Bits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo4Bits@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo8Bits(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo8Bits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo8Bits@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToGreyscale(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToGreyscale IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToGreyscale@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo16Bits555(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo16Bits555 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo16Bits555@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo16Bits565(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo16Bits565 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo16Bits565@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo24Bits(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo24Bits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo24Bits@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertTo32Bits(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertTo32Bits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertTo32Bits@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ColorQuantize(FIBITMAP *dib, FREE_IMAGE_QUANTIZE quantize);
' ========================================================================================
DECLARE FUNCTION FreeImage_ColorQuantize IMPORT "FreeImage.dll" ALIAS "_FreeImage_ColorQuantize@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL quantize AS LONG _                             ' FREE_IMAGE_QUANTIZE quantize
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ColorQuantizeEx(FIBITMAP *dib,
' FREE_IMAGE_QUANTIZE quantize FI_DEFAULT(FIQ_WUQUANT), int PaletteSize FI_DEFAULT(256),
' int ReserveSize FI_DEFAULT(0), RGBQUAD *ReservePalette FI_DEFAULT(NULL));
' ========================================================================================
DECLARE FUNCTION FreeImage_ColorQuantizeEx IMPORT "FreeImage.dll" ALIAS "_FreeImage_ColorQuantizeEx@20" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , OPTIONAL BYVAL quantize AS LONG _                    ' FREE_IMAGE_QUANTIZE quantize FI_DEFAULT(FIQ_WUQUANT)
 , OPTIONAL BYVAL PaletteSize AS LONG _                 ' int PaletteSize FI_DEFAULT(256)
 , OPTIONAL BYVAL ReserveSize AS LONG _                 ' int ReserveSize FI_DEFAULT(0)
 , OPTIONAL BYVAL ReservePalette AS LONG _              ' RGBQUAD *ReservePalette FI_DEFAULT(NULL)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Threshold(FIBITMAP *dib, BYTE T);
' ========================================================================================
DECLARE FUNCTION FreeImage_Threshold IMPORT "FreeImage.dll" ALIAS "_FreeImage_Threshold@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL T AS BYTE _                                    ' BYTE T
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Dither(FIBITMAP *dib, FREE_IMAGE_DITHER algorithm);
' ========================================================================================
DECLARE FUNCTION FreeImage_Dither IMPORT "FreeImage.dll" ALIAS "_FreeImage_Dither@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL algorithm AS LONG _                            ' FREE_IMAGE_DITHER algorithm
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertFromRawBits(BYTE *bits, int width,
' int height, int pitch, unsigned bpp, unsigned red_mask, unsigned green_mask,
' unsigned blue_mask, BOOL topdown FI_DEFAULT(FALSE));
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertFromRawBits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertFromRawBits@36" ( _
   BYREF bits AS ANY _                                  ' BYTE *bits
 , BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , BYVAL pitch AS LONG _                                ' int pitch
 , BYVAL bpp AS DWORD _                                 ' unsigned bpp
 , BYVAL red_mask AS DWORD _                            ' unsigned red_mask
 , BYVAL green_mask AS DWORD _                          ' unsigned green_mask
 , BYVAL blue_mask AS DWORD _                           ' unsigned blue_mask
 , OPTIONAL BYVAL topdown AS LONG _                     ' BOOL topdown FI_DEFAULT(FALSE)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertFromRawBitsEx(BOOL copySource, BYTE *bits,
' FREE_IMAGE_TYPE type, int width, int height, int pitch, unsigned bpp, unsigned red_mask,
' unsigned green_mask, unsigned blue_mask, BOOL topdown FI_DEFAULT(FALSE));
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertFromRawBitsEx IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertFromRawBitsEx@44" ( _
   BYVAL copySource AS LONG _                           ' BOOL copySource
 , BYREF bits AS ANY _                                  ' BYTE *bits
 , BYVAL type AS LONG _                                 ' FREE_IMAGE_TYPE type
 , BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , BYVAL pitch AS LONG _                                ' int pitch
 , BYVAL bpp AS DWORD _                                 ' unsigned bpp
 , BYVAL red_mask AS DWORD _                            ' unsigned red_mask
 , BYVAL green_mask AS DWORD _                          ' unsigned green_mask
 , BYVAL blue_mask AS DWORD _                           ' unsigned blue_mask
 , OPTIONAL BYVAL topdown AS LONG _                     ' BOOL topdown FI_DEFAULT(FALSE)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_ConvertToRawBits(BYTE *bits, FIBITMAP *dib,
' int pitch, unsigned bpp, unsigned red_mask, unsigned green_mask, unsigned blue_mask,
' BOOL topdown FI_DEFAULT(FALSE));
' ========================================================================================
DECLARE SUB FreeImage_ConvertToRawBits IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToRawBits@32" ( _
   BYREF bits AS ANY _                                  ' BYTE *bits
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL pitch AS LONG _                                ' int pitch
 , BYVAL bpp AS DWORD _                                 ' unsigned bpp
 , BYVAL red_mask AS DWORD _                            ' unsigned red_mask
 , BYVAL green_mask AS DWORD _                          ' unsigned green_mask
 , BYVAL blue_mask AS DWORD _                           ' unsigned blue_mask
 , OPTIONAL BYVAL topdown AS LONG _                     ' BOOL topdown FI_DEFAULT(FALSE)
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToFloat(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToFloat IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToFloat@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToRGBF(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToRGBF IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToRGBF@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToRGBAF(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToRGBAF IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToRGBAF@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToUINT16(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToUINT16 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToUINT16@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToRGB16(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToRGB16 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToRGB16@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToRGBA16(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToRGBA16 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToRGBA16@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToStandardType(FIBITMAP *src,
' BOOL scale_linear FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToStandardType IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToStandardType@8" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , OPTIONAL BYVAL scale_linear AS LONG _                ' BOOL scale_linear FI_DEFAULT(TRUE)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ConvertToType(FIBITMAP *src,
' FREE_IMAGE_TYPE dst_type, BOOL scale_linear FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_ConvertToType IMPORT "FreeImage.dll" ALIAS "_FreeImage_ConvertToType@12" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , BYVAL dst_type AS LONG _                             ' FREE_IMAGE_TYPE dst_type
 , OPTIONAL BYVAL scale_linear AS LONG _                ' BOOL scale_linear FI_DEFAULT(TRUE)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' // Tone mapping operators

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_ToneMapping(FIBITMAP *dib, FREE_IMAGE_TMO tmo,
' double first_param FI_DEFAULT(0), double second_param FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_ToneMapping IMPORT "FreeImage.dll" ALIAS "_FreeImage_ToneMapping@24" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL tmo AS LONG _                                  ' FREE_IMAGE_TMO tmo
 , OPTIONAL BYVAL first_param AS DOUBLE _               ' double first_param FI_DEFAULT(0)
 , OPTIONAL BYVAL second_param AS DOUBLE _              ' double second_param FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP* DLL_CALLCONV FreeImage_TmoDrago03(FIBITMAP *src,
' double gamma FI_DEFAULT(2.2), double exposure FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_TmoDrago03 IMPORT "FreeImage.dll" ALIAS "_FreeImage_TmoDrago03@20" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , OPTIONAL BYVAL gamma AS DOUBLE _                     ' double gamma FI_DEFAULT(2.2)
 , OPTIONAL BYVAL exposure AS DOUBLE _                  ' double exposure FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP* DLL_CALLCONV FreeImage_TmoReinhard05(FIBITMAP *src,
' double intensity FI_DEFAULT(0), double contrast FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_TmoReinhard05 IMPORT "FreeImage.dll" ALIAS "_FreeImage_TmoReinhard05@20" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , OPTIONAL BYVAL intensity AS DOUBLE _                 ' double intensity FI_DEFAULT(0)
 , OPTIONAL BYVAL contrast AS DOUBLE _                  ' double contrast FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_TmoReinhard05Ex(FIBITMAP *src,
' double intensity FI_DEFAULT(0), double contrast FI_DEFAULT(0),
' double adaptation FI_DEFAULT(1), double color_correction FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_TmoReinhard05Ex IMPORT "FreeImage.dll" ALIAS "_FreeImage_TmoReinhard05Ex@36" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , OPTIONAL BYVAL intensity AS DOUBLE _                 ' double intensity FI_DEFAULT(0)
 , OPTIONAL BYVAL contrast AS DOUBLE _                  ' double contrast FI_DEFAULT(0)
 , OPTIONAL BYVAL adaptation AS DOUBLE _                ' double adaptation FI_DEFAULT(1)
 , OPTIONAL BYVAL color_correction AS DOUBLE _          ' double color_correction FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_TmoFattal02(FIBITMAP *src,
' double color_saturation FI_DEFAULT(0.5), double attenuation FI_DEFAULT(0.85));
' ========================================================================================
DECLARE FUNCTION FreeImage_TmoFattal02 IMPORT "FreeImage.dll" ALIAS "_FreeImage_TmoFattal02@20" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , OPTIONAL BYVAL color_saturation AS DOUBLE _          ' color_saturation FI_DEFAULT(0.5)
 , OPTIONAL BYVAL attenuation AS DOUBLE _               ' double attenuation FI_DEFAULT(0.85)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ########################################################################################
'                                     ZLib interface
' ########################################################################################

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_ZLibCompress(BYTE *target, DWORD target_size,
' BYTE *source, DWORD source_size);
' ========================================================================================
DECLARE FUNCTION FreeImage_ZLibCompress IMPORT "FreeImage.dll" ALIAS "_FreeImage_ZLibCompress@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYVAL target_size AS DWORD _                         ' DWORD target_size
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL source_size AS DWORD _                         ' DWORD source_size
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_ZLibUncompress(BYTE *target, DWORD target_size,
' BYTE *source, DWORD source_size);
' ========================================================================================
DECLARE FUNCTION FreeImage_ZLibUncompress IMPORT "FreeImage.dll" ALIAS "_FreeImage_ZLibUncompress@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYVAL target_size AS DWORD _                         ' DWORD target_size
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL source_size AS DWORD _                         ' DWORD source_size
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_ZLibGZip(BYTE *target, DWORD target_size,
' BYTE *source, DWORD source_size);
' ========================================================================================
DECLARE FUNCTION FreeImage_ZLibGZip IMPORT "FreeImage.dll" ALIAS "_FreeImage_ZLibGZip@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYVAL target_size AS DWORD _                         ' DWORD target_size
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL source_size AS DWORD _                         ' DWORD source_size
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_ZLibGUnzip(BYTE *target, DWORD target_size,
' BYTE *source, DWORD source_size);
' ========================================================================================
DECLARE FUNCTION FreeImage_ZLibGUnzip IMPORT "FreeImage.dll" ALIAS "_FreeImage_ZLibGUnzip@16" ( _
   BYREF target AS ANY _                                ' BYTE *target
 , BYVAL target_size AS DWORD _                         ' DWORD target_size
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL source_size AS DWORD _                         ' DWORD source_size
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_ZLibCRC32(DWORD crc, BYTE *source,
' DWORD source_size);
' ========================================================================================
DECLARE FUNCTION FreeImage_ZLibCRC32 IMPORT "FreeImage.dll" ALIAS "_FreeImage_ZLibCRC32@12" ( _
   BYVAL crc AS DWORD _                                 ' DWORD crc
 , BYREF source AS ANY _                                ' BYTE *source
 , BYVAL source_size AS DWORD _                         ' DWORD source_size
 ) AS DWORD                                             ' DWORD
' ========================================================================================


' ########################################################################################
'                                   Metadata routines
' ########################################################################################

' // tag creation / destruction

' ========================================================================================
' DLL_API FITAG *DLL_CALLCONV FreeImage_CreateTag();
' ========================================================================================
DECLARE FUNCTION FreeImage_CreateTag IMPORT "FreeImage.dll" ALIAS "_FreeImage_CreateTag@0" ( _
 ) AS DWORD                                             ' FITAG *
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_DeleteTag(FITAG *tag);
' ========================================================================================
DECLARE SUB FreeImage_DeleteTag IMPORT "FreeImage.dll" ALIAS "_FreeImage_DeleteTag@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' DLL_API FITAG *DLL_CALLCONV FreeImage_CloneTag(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_CloneTag IMPORT "FreeImage.dll" ALIAS "_FreeImage_CloneTag@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' FITAG *
' ========================================================================================

' // tag getters and setters

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetTagKey(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagKey IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagKey@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API const char *DLL_CALLCONV FreeImage_GetTagDescription(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagDescription IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagDescription@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ========================================================================================
' DLL_API WORD DLL_CALLCONV FreeImage_GetTagID(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagID IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagID@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS WORD                                              ' WORD
' ========================================================================================

' ========================================================================================
' DLL_API FREE_IMAGE_MDTYPE DLL_CALLCONV FreeImage_GetTagType(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagType IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagType@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS LONG                                              ' FREE_IMAGE_MDTYPE
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_GetTagCount(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagCount@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API DWORD DLL_CALLCONV FreeImage_GetTagLength(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagLength IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagLength@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' DWORD
' ========================================================================================

' ========================================================================================
' DLL_API const void *DLL_CALLCONV FreeImage_GetTagValue(FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetTagValue IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetTagValue@4" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagKey(FITAG *tag, const char *key);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagKey IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagKey@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYREF key AS ASCIIZ _                                ' const char *key
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagDescription(FITAG *tag, const char *description);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagDescription IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagDescription@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYREF description AS ASCIIZ _                        ' const char *description
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagID(FITAG *tag, WORD id);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagID IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagID@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYVAL id AS WORD _                                   ' WORD id
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagType(FITAG *tag, FREE_IMAGE_MDTYPE type);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagType IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagType@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYVAL type AS LONG _                                 ' FREE_IMAGE_MDTYPE type
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagCount(FITAG *tag, DWORD count);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagCount@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYVAL count AS DWORD _                               ' DWORD count
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagLength(FITAG *tag, DWORD length);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagLength IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagLength@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYVAL length AS DWORD _                              ' DWORD length
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetTagValue(FITAG *tag, const void *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetTagValue IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetTagValue@8" ( _
   BYVAL tag AS DWORD _                                 ' FITAG *tag
 , BYREF value AS ANY _                                 ' const void *value
 ) AS LONG                                              ' BOOL
' ========================================================================================

' // iterator

' ========================================================================================
' DLL_API FIMETADATA *DLL_CALLCONV FreeImage_FindFirstMetadata(FREE_IMAGE_MDMODEL model,
' FIBITMAP *dib, FITAG **tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_FindFirstMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_FindFirstMetadata@12" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF tag AS DWORD _                                 ' FITAG **tag
 ) AS DWORD                                             ' FIMETADATA *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FindNextMetadata(FIMETADATA *mdhandle, FITAG **tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_FindNextMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_FindNextMetadata@8" ( _
   BYVAL mdhandle AS DWORD _                            ' FIMETADATA *mdhandle
 , BYREF tag AS DWORD _                                 ' FITAG **tag
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API void DLL_CALLCONV FreeImage_FindCloseMetadata(FIMETADATA *mdhandle);
' ========================================================================================
DECLARE SUB FreeImage_FindCloseMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_FindCloseMetadata@4" ( _
   BYVAL mdhandle AS DWORD _                            ' FIMETADATA *mdhandle
 )                                                      ' void
' ========================================================================================

' // metadata setter and getter

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetMetadata(FREE_IMAGE_MDMODEL model, FIBITMAP *dib,
' const char *key, FITAG *tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetMetadata@16" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF key AS ASCIIZ _                                ' const char *key
 , BYVAL tag AS DWORD _                                 ' FITAG *tag
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetMetadata(FREE_IMAGE_MDMODEL model, FIBITMAP *dib,
' const char *key, FITAG **tag);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetMetadata@16" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF key AS ASCIIZ _                                ' const char *key
 , BYREF tag AS DWORD _                                 ' FITAG **tag
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetMetadataKeyValue(FREE_IMAGE_MDMODEL model,
' FIBITMAP *dib, const char *key, const char *value);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetMetadataKeyValue IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetMetadataKeyValue@16" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF key AS ASCIIZ _                                ' const char *key
 , BYREF value AS ASCIIZ _                              ' const char *value
 ) AS LONG                                              ' BOOL
' ========================================================================================

' // helpers

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_GetMetadataCount(FREE_IMAGE_MDMODEL model,
' FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetMetadataCount IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetMetadataCount@8" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_CloneMetadata(FIBITMAP *dst, FIBITMAP *src);
' ========================================================================================
DECLARE FUNCTION FreeImage_CloneMetadata IMPORT "FreeImage.dll" ALIAS "_FreeImage_CloneMetadata@8" ( _
   BYVAL dst AS DWORD _                                 ' FIBITMAP *dst
 , BYVAL src AS DWORD _                                 ' FIBITMAP *src
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' // tag to C string conversion

' ========================================================================================
' DLL_API const char* DLL_CALLCONV FreeImage_TagToString(FREE_IMAGE_MDMODEL model,
' FITAG *tag, char *Make FI_DEFAULT(NULL));
' ========================================================================================
DECLARE FUNCTION FreeImage_TagToString IMPORT "FreeImage.dll" ALIAS "_FreeImage_TagToString@12" ( _
   BYVAL model AS LONG _                                ' FREE_IMAGE_MDMODEL model
 , BYVAL tag AS DWORD _                                 ' FITAG *tag
 , OPTIONAL BYREF Make AS ASCIIZ _                      ' char *Make FI_DEFAULT(NULL)
 ) AS DWORD                                             ' const char *
' ========================================================================================

' ########################################################################################
'                         JPEG lossless transformation routines
' ########################################################################################

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransform(const char *src_file, const char *dst_file,
' FREE_IMAGE_JPEG_OPERATION operation, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransform IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransform@16" ( _
   BYREF src_file AS ASCIIZ _                           ' const char *src_file
 , BYREF dst_file AS ASCIIZ _                           ' const char *dst_file
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , OPTIONAL BYVAL perfect AS LONG _                     ' BOOL perfect FI_DEFAULT(FALSE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformU(const wchar_t *src_file, const wchar_t *dst_file,
' FREE_IMAGE_JPEG_OPERATION operation, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransformU IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransformU@16" ( _
   BYVAL src_file AS DWORD _                            ' const wchar_t *src_file
 , BYVAL dst_file AS DWORD _                            ' const wchar_t *dst_file
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , OPTIONAL BYVAL perfect AS LONG _                     ' BOOL perfect FI_DEFAULT(FALSE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGCrop(const char *src_file, const char *dst_file,
' int left, int top, int right, int bottom);
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGCrop IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGCrop@24" ( _
   BYREF src_file AS ASCIIZ _                           ' const char *src_file
 , BYREF dst_file AS ASCIIZ _                           ' const char *dst_file
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL right AS LONG _                                ' int right
 , BYVAL bottom AS LONG _                               ' int bottom
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGCropU(const wchar_t *src_file,
' const wchar_t *dst_file, int left, int top, int right, int bottom);
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGCropU IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGCropU@24" ( _
   BYVAL src_file AS DWORD _                            ' const wchar_t *src_file
 , BYVAL dst_file AS DWORD _                            ' const wchar_t *dst_file
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL right AS LONG _                                ' int right
 , BYVAL bottom AS LONG _                               ' int bottom
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformFromHandle(FreeImageIO* src_io, fi_handle src_handle,
' FreeImageIO* dst_io, fi_handle dst_handle, FREE_IMAGE_JPEG_OPERATION operation, int* left,
' int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransformFromHandle IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransformFromHandle@40" ( _
   BYREF src_io AS FreeImageIO _                        ' FreeImageIO* src_io
 , BYVAL src_handle AS DWORD _                          ' fi_handle src_handle
 , BYREF dst_io AS FreeImageIO _                        ' FreeImageIO* dst_io
 , BYVAL dst_handle AS DWORD _                          ' fi_handle dst_handle
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , BYREF left_ AS LONG _                                ' int* left
 , BYREF top AS LONG _                                  ' int* top
 , BYREF right_ AS LONG _                               ' int* right
 , BYREF bottom AS LONG _                               ' int* bottom
 , BYVAL perfect AS LONG _                              ' BOOL perfect FI_DEFAULT(TRUE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombined(const char *src_file, const char *dst_file,
' FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransformCombined IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransformCombined@32" ( _
   BYREF src_file AS ASCIIZ _                           ' const char *src_file
 , BYREF dst_file AS ASCIIZ _                           ' const char *dst_file
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , BYREF left_ AS LONG _                                ' int* left
 , BYREF top AS LONG _                                  ' int* top
 , BYREF right_ AS LONG _                               ' int* right
 , BYREF bottom AS LONG _                               ' int* bottom
 , BYVAL perfect AS LONG _                              ' BOOL perfect FI_DEFAULT(TRUE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombinedU(const wchar_t *src_file, const wchar_t *dst_file,
' FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransformCombinedU IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransformCombinedU@32" ( _
   BYVAL src_file AS DWORD _                            ' const wchar_t *src_file
 , BYVAL dst_file AS DWORD _                            ' const wchar_t *dst_file
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , BYREF left_ AS LONG _                                ' int* left
 , BYREF top AS LONG _                                  ' int* top
 , BYREF right_ AS LONG _                               ' int* right
 , BYREF bottom AS LONG _                               ' int* bottom
 , BYVAL perfect AS LONG _                              ' BOOL perfect FI_DEFAULT(TRUE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_JPEGTransformCombinedFromMemory(FIMEMORY* src_stream, FIMEMORY* dst_stream,
' FREE_IMAGE_JPEG_OPERATION operation, int* left, int* top, int* right, int* bottom, BOOL perfect FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_JPEGTransformCombinedFromMemory IMPORT "FreeImage.dll" ALIAS "_FreeImage_JPEGTransformCombinedFromMemory@32" ( _
   BYVAL src_stream AS DWORD _                          ' FIMEMORY* src_stream
 , BYVAL dst_stream AS DWORD _                          ' FIMEMORY* dst_stream,
 , BYVAL operation AS LONG _                            ' FREE_IMAGE_JPEG_OPERATION operation
 , BYREF left_ AS LONG _                                ' int* left
 , BYREF top AS LONG _                                  ' int* top
 , BYREF right_ AS LONG _                               ' int* right
 , BYREF bottom AS LONG _                               ' int* bottom
 , BYVAL perfect AS LONG _                              ' BOOL perfect FI_DEFAULT(TRUE)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ########################################################################################
'                               Image manipulation toolkit
' ########################################################################################

' // rotation and flipping

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_RotateClassic(FIBITMAP *dib, double angle);
' ========================================================================================
DECLARE FUNCTION FreeImage_RotateClassic IMPORT "FreeImage.dll" ALIAS "_FreeImage_RotateClassic@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL angle AS DOUBLE _                              ' double angle
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Rotate(FIBITMAP *dib,
' double angle, const void *bkcolor FI_DEFAULT(NULL));
' ========================================================================================
DECLARE FUNCTION FreeImage_Rotate IMPORT "FreeImage.dll" ALIAS "_FreeImage_Rotate@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL angle AS DOUBLE _                              ' double angle
 , OPTIONAL BYREF bkcolor AS ANY _                      ' const void *bkcolor FI_DEFAULT(NULL)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_RotateEx(FIBITMAP *dib, double angle,
' double x_shift, double y_shift, double x_origin, double y_origin, BOOL use_mask);
' ========================================================================================
DECLARE FUNCTION FreeImage_RotateEx IMPORT "FreeImage.dll" ALIAS "_FreeImage_RotateEx@48" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL angle AS DOUBLE _                              ' double angle
 , BYVAL x_shift AS DOUBLE _                            ' double x_shift
 , BYVAL y_shift AS DOUBLE _                            ' double y_shift
 , BYVAL x_origin AS DOUBLE _                           ' double x_origin
 , BYVAL y_origin AS DOUBLE _                           ' double y_origin
 , BYVAL use_mask AS LONG _                             ' BOOL use_mask
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FlipHorizontal(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_FlipHorizontal IMPORT "FreeImage.dll" ALIAS "_FreeImage_FlipHorizontal@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FlipVertical(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_FlipVertical IMPORT "FreeImage.dll" ALIAS "_FreeImage_FlipVertical@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================

' // upsampling / downsampling

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Rescale(FIBITMAP *dib, int dst_width,
' int dst_height, FREE_IMAGE_FILTER filter FI_DEFAULT(FILTER_CATMULLROM));
' ========================================================================================
DECLARE FUNCTION FreeImage_Rescale IMPORT "FreeImage.dll" ALIAS "_FreeImage_Rescale@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL dst_width AS LONG _                            ' int dst_width
 , BYVAL dst_height AS LONG _                           ' int dst_height
 , BYVAL filter AS LONG _                               ' FREE_IMAGE_FILTER filter
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_MakeThumbnail(FIBITMAP *dib, int max_pixel_size,
' BOOL convert FI_DEFAULT(TRUE));
' ========================================================================================
DECLARE FUNCTION FreeImage_MakeThumbnail IMPORT "FreeImage.dll" ALIAS "_FreeImage_MakeThumbnail@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL max_pixel_size AS LONG _                       ' int max_pixel_size
 , BYVAL convert AS LONG _                              ' BOOL convert FI_DEFAULT(TRUE)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_RescaleRect(FIBITMAP *dib, int dst_width,
' int dst_height, int left, int top, int right, int bottom,
' FREE_IMAGE_FILTER filter FI_DEFAULT(FILTER_CATMULLROM), unsigned flags FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_RescaleRect IMPORT "FreeImage.dll" ALIAS "_FreeImage_RescaleRect@36" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL dst_width AS LONG _                            ' int dst_width
 , BYVAL dst_height AS LONG _                           ' int dst_height
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL right AS LONG _                                ' int right
 , BYVAL bottom AS LONG _                               ' int bottom
 , BYVAL filter AS LONG _                               ' FREE_IMAGE_FILTER filter FI_DEFAULT(FILTER_CATMULLROM)
 , BYVAL flags AS DWORD _                               ' unsigned flags FI_DEFAULT(0))
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' // color manipulation routines (point operations)

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AdjustCurve(FIBITMAP *dib, BYTE *LUT,
' FREE_IMAGE_COLOR_CHANNEL channel);
' ========================================================================================
DECLARE FUNCTION FreeImage_AdjustCurve IMPORT "FreeImage.dll" ALIAS "_FreeImage_AdjustCurve@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF LUT AS ANY _                                   ' BYTE *LUT
 , BYVAL channel AS LONG _                              ' FREE_IMAGE_COLOR_CHANNEL channel
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AdjustGamma(FIBITMAP *dib, double gamma);
' ========================================================================================
DECLARE FUNCTION FreeImage_AdjustGamma IMPORT "FreeImage.dll" ALIAS "_FreeImage_AdjustGamma@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL gamma AS DOUBLE _                              ' double gamma
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AdjustBrightness(FIBITMAP *dib, double percentage);
' ========================================================================================
DECLARE FUNCTION FreeImage_AdjustBrightness IMPORT "FreeImage.dll" ALIAS "_FreeImage_AdjustBrightness@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL percentage AS DOUBLE _                         ' double percentage
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AdjustContrast(FIBITMAP *dib, double percentage);
' ========================================================================================
DECLARE FUNCTION FreeImage_AdjustContrast IMPORT "FreeImage.dll" ALIAS "_FreeImage_AdjustContrast@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL percentage AS DOUBLE _                         ' double percentage
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_Invert(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_Invert IMPORT "FreeImage.dll" ALIAS "_FreeImage_Invert@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_GetHistogram(FIBITMAP *dib, DWORD *histo, FREE_IMAGE_COLOR_CHANNEL channel FI_DEFAULT(FICC_BLACK));
' ========================================================================================
DECLARE FUNCTION FreeImage_GetHistogram IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetHistogram@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF histo AS DWORD _                               ' DWORD *histo
 , OPTIONAL BYVAL channel AS LONG _                     ' FREE_IMAGE_COLOR_CHANNEL channel FI_DEFAULT(FICC_BLACK)
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API int DLL_CALLCONV FreeImage_GetAdjustColorsLookupTable(BYTE *LUT,
' double brightness, double contrast, double gamma, BOOL invert);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetAdjustColorsLookupTable IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetAdjustColorsLookupTable@32" ( _
   BYREF LUT AS ANY _                                   ' BYTE *LUT
 , BYVAL brightness AS DOUBLE _                         ' double brightness
 , BYVAL contrast AS DOUBLE _                           ' double contrast
 , BYVAL gamma AS DOUBLE _                              ' double gamma
 , BYVAL invert AS LONG _                               ' BOOL invert
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_AdjustColors(FIBITMAP *dib, double brightness,
' double contrast, double gamma, BOOL invert FI_DEFAULT(FALSE));
' ========================================================================================
DECLARE FUNCTION FreeImage_AdjustColors IMPORT "FreeImage.dll" ALIAS "_FreeImage_AdjustColors@32" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL brightness AS DOUBLE _                         ' double brightness
 , BYVAL contrast AS DOUBLE _                           ' double contrast
 , BYVAL gamma AS DOUBLE _                              ' double gamma
 , OPTIONAL BYVAL invert AS LONG _                      ' BOOL invert
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_ApplyColorMapping(FIBITMAP *dib,
' RGBQUAD *srccolors, RGBQUAD *dstcolors, unsigned count, BOOL ignore_alpha, BOOL swap);
' ========================================================================================
DECLARE FUNCTION FreeImage_ApplyColorMapping IMPORT "FreeImage.dll" ALIAS "_FreeImage_ApplyColorMapping@24" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF srccolors AS RGBQUAD _                         ' RGBQUAD *srccolors
 , BYREF dstcolors AS RGBQUAD _                         ' RGBQUAD *dstcolors
 , BYVAL count AS DWORD _                               ' unsigned count
 , BYVAL ignore_alpha AS LONG _                         ' BOOL ignore_alpha
 , BYVAL swap AS LONG _                                 ' BOOL swap
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_SwapColors(FIBITMAP *dib, RGBQUAD *color_a,
' RGBQUAD *color_b, BOOL ignore_alpha);
' ========================================================================================
DECLARE FUNCTION FreeImage_SwapColors IMPORT "FreeImage.dll" ALIAS "_FreeImage_SwapColors@16" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF color_a AS RGBQUAD _                           ' RGBQUAD *color_a
 , BYREF color_b AS RGBQUAD _                           ' RGBQUAD *color_b
 , BYVAL ignore_alpha AS LONG _                         ' BOOL ignore_alpha
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_ApplyPaletteIndexMapping(FIBITMAP *dib,
' BYTE *srcindices, BYTE *dstindices, unsigned count, BOOL swap);
' ========================================================================================
DECLARE FUNCTION FreeImage_ApplyPaletteIndexMapping IMPORT "FreeImage.dll" ALIAS "_FreeImage_ApplyPaletteIndexMapping@20" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF srcindices AS ANY _                            ' BYTE *srcindices
 , BYREF dstindices AS ANY _                            ' BYTE *dstindices
 , BYVAL count AS DWORD _                               ' unsigned count
 , BYVAL swap AS LONG _                                 ' BOOL swap
 ) AS DWORD                                             ' unsigned
' ========================================================================================

' ========================================================================================
' DLL_API unsigned DLL_CALLCONV FreeImage_SwapPaletteIndices(FIBITMAP *dib, BYTE *index_a,
' BYTE *index_b);
' ========================================================================================
DECLARE FUNCTION FreeImage_SwapPaletteIndices IMPORT "FreeImage.dll" ALIAS "_FreeImage_SwapPaletteIndices@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF index_a AS ANY _                               ' BYTE *index_a
 , BYREF index_b AS ANY _                               ' BYTE *index_b
 ) AS DWORD                                             ' unsigned
' ========================================================================================


' // channel processing routines

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_GetChannel(FIBITMAP *dib, FREE_IMAGE_COLOR_CHANNEL channel);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetChannel IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetChannel@8" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL channel AS LONG _                              ' FREE_IMAGE_COLOR_CHANNEL channel
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetChannel(FIBITMAP *dst, FIBITMAP *src, FREE_IMAGE_COLOR_CHANNEL channel);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetChannel IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetChannel@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dst
 , BYVAL dib8 AS DWORD _                                ' FIBITMAP *src
 , BYVAL channel AS LONG _                              ' FREE_IMAGE_COLOR_CHANNEL channel
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_GetComplexChannel(FIBITMAP *src, FREE_IMAGE_COLOR_CHANNEL channel);
' ========================================================================================
DECLARE FUNCTION FreeImage_GetComplexChannel IMPORT "FreeImage.dll" ALIAS "_FreeImage_GetComplexChannel@8" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , BYVAL channel AS LONG _                              ' FREE_IMAGE_COLOR_CHANNEL channel
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_SetComplexChannel(FIBITMAP *dst, FIBITMAP *src, FREE_IMAGE_COLOR_CHANNEL channel);
' ========================================================================================
DECLARE FUNCTION FreeImage_SetComplexChannel IMPORT "FreeImage.dll" ALIAS "_FreeImage_SetComplexChannel@12" ( _
   BYVAL dst AS DWORD _                                 ' FIBITMAP *dst
 , BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , BYVAL channel AS LONG _                              ' FREE_IMAGE_COLOR_CHANNEL channel
 ) AS LONG                                              ' BOOL
' ========================================================================================

' // copy / paste / composite routines

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Copy(FIBITMAP *dib, int left, int top,
' int right, int bottom);
' ========================================================================================
DECLARE FUNCTION FreeImage_Copy IMPORT "FreeImage.dll" ALIAS "_FreeImage_Copy@20" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL right AS LONG _                                ' int right
 , BYVAL bottom AS LONG _                               ' int bottom
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_Paste(FIBITMAP *dst, FIBITMAP *src, int left,
' int top, int alpha);
' ========================================================================================
DECLARE FUNCTION FreeImage_Paste IMPORT "FreeImage.dll" ALIAS "_FreeImage_Paste@20" ( _
   BYVAL dst AS DWORD _                                 ' FIBITMAP *dst
 , BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL alpha AS LONG _                                ' int alpha
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_CreateView(FIBITMAP *dib, unsigned left,
' unsigned top, unsigned right, unsigned bottom);
' ========================================================================================
DECLARE FUNCTION FreeImage_CreateView IMPORT "FreeImage.dll" ALIAS "_FreeImage_CreateView@20" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYVAL left AS DWORD _                                ' unsigned left
 , BYVAL top AS DWORD _                                 ' unsigned top
 , BYVAL right AS DWORD _                               ' unsigned right
 , BYVAL bottom AS DWORD _                              ' unsigned bottom
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_Composite(FIBITMAP *fg,
' BOOL useFileBkg FI_DEFAULT(FALSE), RGBQUAD *appBkColor FI_DEFAULT(NULL),
' FIBITMAP *bg FI_DEFAULT(NULL));
' ========================================================================================
DECLARE FUNCTION FreeImage_Composite IMPORT "FreeImage.dll" ALIAS "_FreeImage_Composite@16" ( _
   BYVAL fg AS DWORD _                                  ' FIBITMAP *fg
 , OPTIONAL BYVAL useFileBkg AS LONG _                  ' BOOL useFileBkg FI_DEFAULT(FALSE)
 , OPTIONAL BYREF appBkColor AS RGBQUAD _               ' RGBQUAD *appBkColor FI_DEFAULT(NULL)
 , OPTIONAL BYVAL bg AS DWORD _                         ' FIBITMAP *bg FI_DEFAULT(NULL)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================

' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_PreMultiplyWithAlpha(FIBITMAP *dib);
' ========================================================================================
DECLARE FUNCTION FreeImage_PreMultiplyWithAlpha IMPORT "FreeImage.dll" ALIAS "_FreeImage_PreMultiplyWithAlpha@4" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 ) AS LONG                                              ' BOOL


' ========================================================================================
' DLL_API BOOL DLL_CALLCONV FreeImage_FillBackground(FIBITMAP *dib, const void *color,
' int options FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_FillBackground IMPORT "FreeImage.dll" ALIAS "_FreeImage_FillBackground@12" ( _
   BYVAL dib AS DWORD _                                 ' FIBITMAP *dib
 , BYREF color AS ANY _                                 ' const void *color
 , OPTIONAL BYVAL options AS LONG _                     ' int options FI_DEFAULT(0)
 ) AS LONG                                              ' BOOL


' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_EnlargeCanvas(FIBITMAP *src, int left, int top,
' int right, int bottom, const void *color, int options FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_EnlargeCanvas IMPORT "FreeImage.dll" ALIAS "_FreeImage_EnlargeCanvas@28" ( _
   BYVAL src AS DWORD _                                 ' FIBITMAP *src
 , BYVAL left AS LONG _                                 ' int left
 , BYVAL top AS LONG _                                  ' int top
 , BYVAL right AS LONG _                                ' int right
 , BYVAL bottom AS LONG _                               ' int bottom
 , BYREF color AS ANY _                                 ' const void *color
 , OPTIONAL BYVAL options AS LONG _                     ' int options FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *


' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_AllocateEx(int width, int height, int bpp,
' const RGBQUAD *color, int options FI_DEFAULT(0), const RGBQUAD *palette FI_DEFAULT(NULL),
' unsigned red_mask FI_DEFAULT(0), unsigned green_mask FI_DEFAULT(0), unsigned blue_mask FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_AllocateEx IMPORT "FreeImage.dll" ALIAS "_FreeImage_AllocateEx@36" ( _
   BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , BYVAL bpp AS LONG _                                  ' int bpp
 , BYREF color AS RGBQUAD _                             ' const RGBQUAD *color
 , OPTIONAL BYVAL options AS LONG _                     ' int options FI_DEFAULT(0)
 , OPTIONAL BYREF palette AS RGBQUAD _                  ' const RGBQUAD *palette FI_DEFAULT(NULL)
 , OPTIONAL BYVAL red_mask AS DWORD _                   ' unsigned red_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL green_mask AS DWORD _                 ' unsigned green_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL blue_mask AS DWORD _                  ' unsigned blue_mask FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_AllocateExT(FREE_IMAGE_TYPE type, int width,
' int height, int bpp, const void *color, int options FI_DEFAULT(0),
' const RGBQUAD *palette FI_DEFAULT(NULL), unsigned red_mask FI_DEFAULT(0),
' unsigned green_mask FI_DEFAULT(0), unsigned blue_mask FI_DEFAULT(0));
' ========================================================================================
DECLARE FUNCTION FreeImage_AllocateExT IMPORT "FreeImage.dll" ALIAS "_FreeImage_AllocateExT@40" ( _
   BYVAL type AS LONG _                                 ' FREE_IMAGE_TYPE type
 , BYVAL width AS LONG _                                ' int width
 , BYVAL height AS LONG _                               ' int height
 , BYVAL bpp AS LONG _                                  ' int bpp
 , BYREF color AS ANY _                                 ' const void *color
 , OPTIONAL BYVAL options AS LONG _                     ' int options FI_DEFAULT(0)
 , OPTIONAL BYREF palette AS RGBQUAD _                  ' const RGBQUAD *palette FI_DEFAULT(NULL)
 , OPTIONAL BYVAL red_mask AS DWORD _                   ' unsigned red_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL green_mask AS DWORD _                 ' unsigned green_mask FI_DEFAULT(0)
 , OPTIONAL BYVAL blue_mask AS DWORD _                  ' unsigned blue_mask FI_DEFAULT(0)
 ) AS DWORD                                             ' FIBITMAP *

'// miscellaneous algorithms

' ========================================================================================
' DLL_API FIBITMAP *DLL_CALLCONV FreeImage_MultigridPoissonSolver(FIBITMAP *Laplacian,
' int ncycle FI_DEFAULT(3));
' ========================================================================================
DECLARE FUNCTION FreeImage_MultigridPoissonSolver IMPORT "FreeImage.dll" ALIAS "_FreeImage_MultigridPoissonSolver@8" ( _
   BYVAL Laplacian AS DWORD _                           ' FIBITMAP *Laplacian
 , OPTIONAL BYVAL ncycle AS LONG _                      ' int ncycle FI_DEFAULT(3)
 ) AS DWORD                                             ' FIBITMAP *
' ========================================================================================
