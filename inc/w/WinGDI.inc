' ########################################################################################
' Microsoft Windows
' File: WinGDI.inc
' Contents: GDI procedure declarations, constant definitions and macros
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Note: windows.inc must be included before this file, but can't be done here.
' You must do it in your application.

#INCLUDE THIS ONCE
%WINGDI_INC = 1

'#ifndef WINVER
'#define WINVER 0x0500   // version 5.0
'#endif /* WINVER */

'#IF NOT %DEF(%NOGDI) ' --------------------------------------------------------
'#ifndef NOGDI

#IF NOT %DEF(%NORASTEROPS) ' --------------------------------------------------
'#ifndef NORASTEROPS

'/* Binary raster ops */
%R2_BLACK       = 1  ' /*  0       */
%R2_NOTMERGEPEN = 2  ' /* DPon     */
%R2_MASKNOTPEN  = 3  ' /* DPna     */
%R2_NOTCOPYPEN  = 4  ' /* PN       */
%R2_MASKPENNOT  = 5  ' /* PDna     */
%R2_NOT         = 6  ' /* Dn       */
%R2_XORPEN      = 7  ' /* DPx      */
%R2_NOTMASKPEN  = 8  ' /* DPan     */
%R2_MASKPEN     = 9  ' /* DPa      */
%R2_NOTXORPEN   = 10 ' /* DPxn     */
%R2_NOP         = 11 ' /* D        */
%R2_MERGENOTPEN = 12 ' /* DPno     */
%R2_COPYPEN     = 13 ' /* P        */
%R2_MERGEPENNOT = 14 ' /* PDno     */
%R2_MERGEPEN    = 15 ' /* DPo      */
%R2_WHITE       = 16 ' /*  1       */
%R2_LAST        = 16

'/* Ternary raster operations */
%SRCCOPY     = &H00CC0020??? ' (DWORD) dest = source
%SRCPAINT    = &H00EE0086??? ' (DWORD) dest = source OR dest
%SRCAND      = &H008800C6??? ' (DWORD) dest = source AND dest
%SRCINVERT   = &H00660046??? ' (DWORD) dest = source XOR dest
%SRCERASE    = &H00440328??? ' (DWORD) dest = source AND (NOT dest )
%NOTSRCCOPY  = &H00330008??? ' (DWORD) dest = (NOT source)
%NOTSRCERASE = &H001100A6??? ' (DWORD) dest = (NOT src) AND (NOT dest)
%MERGECOPY   = &H00C000CA??? ' (DWORD) dest = (source AND pattern)
%MERGEPAINT  = &H00BB0226??? ' (DWORD) dest = (NOT source) OR dest
%PATCOPY     = &H00F00021??? ' (DWORD) dest = pattern
%PATPAINT    = &H00FB0A09??? ' (DWORD) dest = DPSnoo
%PATINVERT   = &H005A0049??? ' (DWORD) dest = pattern XOR dest
%DSTINVERT   = &H00550009??? ' (DWORD) dest = (NOT dest)
%BLACKNESS   = &H00000042??? ' (DWORD) dest = BLACK
%WHITENESS   = &H00FF0062??? ' (DWORD) dest = WHITE

'#if(WINVER >= 0x0500)
%NOMIRRORBITMAP = &H80000000???   ' /* Do not Mirror the bitmap in this call */
%CAPTUREBLT     = &H40000000???   ' /* Include layered windows */
'#endif /* WINVER >= 0x0500 */

'/* Quaternary raster codes */
'#define MAKEROP4(fore,back) (DWORD)((((back) << 8) & 0xFF000000) | (fore))
MACRO MAKEROP4(fore,back) = LO(DWORD,((back * 256) AND &HFF000000???) OR fore)

'#endif /* NORASTEROPS */
#ENDIF   ' #IF NOT %DEF(%NORASTEROPS) -----------------------------------------

'#define GDI_ERROR (0xFFFFFFFFL)
'#define HGDI_ERROR (LongToHandle(0xFFFFFFFFL))

%GDI_ERROR   = &HFFFFFFFF???
%HGDI_ERROR  = &HFFFFFFFF???

'/* Region Flags */
%RGN_ERROR     = 0&
%NULLREGION    = 1&
%SIMPLEREGION  = 2&
%COMPLEXREGION = 3&

'/* CombineRgn() Styles */
%RGN_AND  = 1&
%RGN_OR   = 2&
%RGN_XOR  = 3&
%RGN_DIFF = 4&
%RGN_COPY = 5&
%RGN_MIN  = %RGN_AND
%RGN_MAX  = %RGN_COPY

'/* StretchBlt() Modes */
%BLACKONWHITE      = 1&
%WHITEONBLACK      = 2&
%COLORONCOLOR      = 3&
%HALFTONE          = 4&
%MAXSTRETCHBLTMODE = 4&

'#if(WINVER >= 0x0400)
'/* New StretchBlt() Modes */
%STRETCH_ANDSCANS    = %BLACKONWHITE
%STRETCH_ORSCANS     = %WHITEONBLACK
%STRETCH_DELETESCANS = %COLORONCOLOR
%STRETCH_HALFTONE    = %HALFTONE
'#endif /* WINVER >= 0x0400 */

'/* PolyFill() Modes */
%ALTERNATE     = 1&
%WINDING       = 2&
%POLYFILL_LAST = 2&

'/* Layout Orientation Options */
'#if(WINVER >= 0x0500)
%LAYOUT_RTL                         = &H00000001???  ' // Right to left
%LAYOUT_BTT                         = &H00000002???  ' // Bottom to top
%LAYOUT_VBH                         = &H00000004???  ' // Vertical before horizontal
%LAYOUT_ORIENTATIONMASK             = (%LAYOUT_RTL OR %LAYOUT_BTT OR %LAYOUT_VBH)
%LAYOUT_BITMAPORIENTATIONPRESERVED  = &H00000008???
'#endif /* WINVER >= 0x0500 */

'/* Text Alignment Options */
%TA_NOUPDATECP = 0???
%TA_UPDATECP   = 1???

%TA_LEFT       = 0???
%TA_RIGHT      = 2???
%TA_CENTER     = 6???

'#define TA_TOP                       0
'#define TA_BOTTOM                    8
'#define TA_BASELINE                  24
'#if (WINVER >= 0x0400)
'#define TA_RTLREADING                256
'#define TA_MASK       (TA_BASELINE+TA_CENTER+TA_UPDATECP+TA_RTLREADING)
'#else
'#define TA_MASK       (TA_BASELINE+TA_CENTER+TA_UPDATECP)
'#endif

%TA_TOP        = 0???
%TA_BOTTOM     = 8???
%TA_BASELINE   = 24???
#IF (%WINVER >= &H0400)
%TA_RTLREADING = 256???
%TA_MASK       = %TA_BASELINE + %TA_CENTER + %TA_UPDATECP + %TA_RTLREADING
#ELSE
%TA_MASK       = %TA_BASELINE + %TA_CENTER + %TA_UPDATECP
#ENDIF

%VTA_BASELINE  = %TA_BASELINE
%VTA_LEFT      = %TA_BOTTOM
%VTA_RIGHT     = %TA_TOP
%VTA_CENTER    = %TA_CENTER
%VTA_BOTTOM    = %TA_RIGHT
%VTA_TOP       = %TA_LEFT

%ETO_GRAYED         = 1???
%ETO_OPAQUE         = 2???
%ETO_CLIPPED        = 4???
'#if(WINVER >= 0x0400)
%ETO_GLYPH_INDEX    = &H0010???
%ETO_RTLREADING     = &H0080???
%ETO_NUMERICSLOCAL  = &H0400???
%ETO_NUMERICSLATIN  = &H0800???
%ETO_IGNORELANGUAGE = &H1000???
'#endif /* WINVER >= 0x0400 */
'#if (_WIN32_WINNT >= 0x0500)
%ETO_PDY            = &H2000???
'#endif // (_WIN32_WINNT >= 0x0500)
'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
%ETO_REVERSE_INDEX_MAP = &H10000???
'#endif

%ASPECT_FILTERING = &H0001???

'/* Bounds Accumulation APIs */

%DCB_RESET      = &H0001???
%DCB_ACCUMULATE = &H0002???
%DCB_DIRTY      = %DCB_ACCUMULATE
%DCB_SET        = %DCB_RESET OR %DCB_ACCUMULATE
%DCB_ENABLE     = &H0004???
%DCB_DISABLE    = &H0008???

#IF NOT %DEF(%NOMETAFILE) ' ---------------------------------------------------
'#ifndef NOMETAFILE

'/* Metafile Functions */
%META_SETBKCOLOR            = &H0201
%META_SETBKMODE             = &H0102
%META_SETMAPMODE            = &H0103
%META_SETROP2               = &H0104
%META_SETRELABS             = &H0105
%META_SETPOLYFILLMODE       = &H0106
%META_SETSTRETCHBLTMODE     = &H0107
%META_SETTEXTCHAREXTRA      = &H0108
%META_SETTEXTCOLOR          = &H0209
%META_SETTEXTJUSTIFICATION  = &H020A
%META_SETWINDOWORG          = &H020B
%META_SETWINDOWEXT          = &H020C
%META_SETVIEWPORTORG        = &H020D
%META_SETVIEWPORTEXT        = &H020E
%META_OFFSETWINDOWORG       = &H020F
%META_SCALEWINDOWEXT        = &H0410
%META_OFFSETVIEWPORTORG     = &H0211
%META_SCALEVIEWPORTEXT      = &H0412
%META_LINETO                = &H0213
%META_MOVETO                = &H0214
%META_EXCLUDECLIPRECT       = &H0415
%META_INTERSECTCLIPRECT     = &H0416
%META_ARC                   = &H0817
%META_ELLIPSE               = &H0418
%META_FLOODFILL             = &H0419
%META_PIE                   = &H081A
%META_RECTANGLE             = &H041B
%META_ROUNDRECT             = &H061C
%META_PATBLT                = &H061D
%META_SAVEDC                = &H001E
%META_SETPIXEL              = &H041F
%META_OFFSETCLIPRGN         = &H0220
%META_TEXTOUT               = &H0521
%META_BITBLT                = &H0922
%META_STRETCHBLT            = &H0B23
%META_POLYGON               = &H0324
%META_POLYLINE              = &H0325
%META_ESCAPE                = &H0626
%META_RESTOREDC             = &H0127
%META_FILLREGION            = &H0228
%META_FRAMEREGION           = &H0429
%META_INVERTREGION          = &H012A
%META_PAINTREGION           = &H012B
%META_SELECTCLIPREGION      = &H012C
%META_SELECTOBJECT          = &H012D
%META_SETTEXTALIGN          = &H012E
%META_CHORD                 = &H0830
%META_SETMAPPERFLAGS        = &H0231
%META_EXTTEXTOUT            = &H0A32
%META_SETDIBTODEV           = &H0D33
%META_SELECTPALETTE         = &H0234
%META_REALIZEPALETTE        = &H0035
%META_ANIMATEPALETTE        = &H0436
%META_SETPALENTRIES         = &H0037
%META_POLYPOLYGON           = &H0538
%META_RESIZEPALETTE         = &H0139
%META_DIBBITBLT             = &H0940
%META_DIBSTRETCHBLT         = &H0B41
%META_DIBCREATEPATTERNBRUSH = &H0142
%META_STRETCHDIB            = &H0F43
%META_EXTFLOODFILL          = &H0548
'#if(WINVER >= 0x0500)
%META_SETLAYOUT             = &H0149
'#endif /* WINVER >= 0x0500 */
%META_DELETEOBJECT          = &H01F0
%META_CREATEPALETTE         = &H00F7
%META_CREATEPATTERNBRUSH    = &H01F9
%META_CREATEPENINDIRECT     = &H02FA
%META_CREATEFONTINDIRECT    = &H02FB
%META_CREATEBRUSHINDIRECT   = &H02FC
%META_CREATEREGION          = &H06FF

'#if(WINVER >= 0x0400)

' // Size = 20 bytes
TYPE DRAWPATRECT WORD
   ptPosition AS POINT   ' POINT
   ptSize     AS POINT   ' POINT
   wStyle     AS WORD    ' WORD
   wPattern   AS WORD    ' WORD
END TYPE

'#endif /* WINVER >= 0x0400 */

'#endif /* NOMETAFILE */
#ENDIF   ' #IF NOT %DEF(%NOMETAFILE) ------------------------------------------

'/* GDI Escapes */
%NEWFRAME                    = 1
%ABORTDOC                    = 2
%NEXTBAND                    = 3
%SETCOLORTABLE               = 4
%GETCOLORTABLE               = 5
%FLUSHOUTPUT                 = 6
%DRAFTMODE                   = 7
%QUERYESCSUPPORT             = 8
%SETABORTPROC                = 9
%STARTDOC                    = 10
%ENDDOC                      = 11
%GETPHYSPAGESIZE             = 12
%GETPRINTINGOFFSET           = 13
%GETSCALINGFACTOR            = 14
%MFCOMMENT                   = 15
%GETPENWIDTH                 = 16
%SETCOPYCOUNT                = 17
%SELECTPAPERSOURCE           = 18
%DEVICEDATA                  = 19
%PASSTHROUGH                 = 19
%GETTECHNOLGY                = 20
%GETTECHNOLOGY               = 20
%SETLINECAP                  = 21
%SETLINEJOIN                 = 22
%SETMITERLIMIT               = 23
%BANDINFO                    = 24
%DRAWPATTERNRECT             = 25
%GETVECTORPENSIZE            = 26
%GETVECTORBRUSHSIZE          = 27
%ENABLEDUPLEX                = 28
%GETSETPAPERBINS             = 29
%GETSETPRINTORIENT           = 30
%ENUMPAPERBINS               = 31
%SETDIBSCALING               = 32
%EPSPRINTING                 = 33
%ENUMPAPERMETRICS            = 34
%GETSETPAPERMETRICS          = 35
%POSTSCRIPT_DATA             = 37
%POSTSCRIPT_IGNORE           = 38
%MOUSETRAILS                 = 39
%GETDEVICEUNITS              = 42

%GETEXTENDEDTEXTMETRICS      = 256
%GETEXTENTTABLE              = 257
%GETPAIRKERNTABLE            = 258
%GETTRACKKERNTABLE           = 259
%EXTTEXTOUT                  = 512
%GETFACENAME                 = 513
%DOWNLOADFACE                = 514
%ENABLERELATIVEWIDTHS        = 768
%ENABLEPAIRKERNING           = 769
%SETKERNTRACK                = 770
%SETALLJUSTVALUES            = 771
%SETCHARSET                  = 772

%STRETCHBLT                  = 2048
%METAFILE_DRIVER             = 2049
%GETSETSCREENPARAMS          = 3072
%QUERYDIBSUPPORT             = 3073
%BEGIN_PATH                  = 4096
%CLIP_TO_PATH                = 4097
%END_PATH                    = 4098
%EXT_DEVICE_CAPS             = 4099
%RESTORE_CTM                 = 4100
%SAVE_CTM                    = 4101
%SET_ARC_DIRECTION           = 4102
%SET_BACKGROUND_COLOR        = 4103
%SET_POLY_MODE               = 4104
%SET_SCREEN_ANGLE            = 4105
%SET_SPREAD                  = 4106
%TRANSFORM_CTM               = 4107
%SET_CLIP_BOX                = 4108
%SET_BOUNDS                  = 4109
%SET_MIRROR_MODE             = 4110
%OPENCHANNEL                 = 4110
%DOWNLOADHEADER              = 4111
%CLOSECHANNEL                = 4112
%POSTSCRIPT_PASSTHROUGH      = 4115
%ENCAPSULATED_POSTSCRIPT     = 4116

%POSTSCRIPT_IDENTIFY         = 4117  ' /* new escape for NT5 pscript driver */
%POSTSCRIPT_INJECTION        = 4118  ' /* new escape for NT5 pscript driver */

%CHECKJPEGFORMAT             = 4119
%CHECKPNGFORMAT              = 4120

%GET_PS_FEATURESETTING       = 4121  ' /* new escape for NT5 pscript driver */

%GDIPLUS_TS_QUERYVER         = 4122  ' /* private escape */
%GDIPLUS_TS_RECORD           = 4123  ' /* private escape */

'/*
' * Return Values for MILCORE_TS_QUERYVER
' */

'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
%MILCORE_TS_QUERYVER_RESULT_FALSE = &H0
%MILCORE_TS_QUERYVER_RESULT_TRUE  = &H7FFFFFFF???
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)

%SPCLPASSTHROUGH2            = 4568  ' /* new escape for NT5 pscript driver */

'/*
' * Parameters for POSTSCRIPT_IDENTIFY escape
' */

%PSIDENT_GDICENTRIC = 0
%PSIDENT_PSCENTRIC  = 1

'/*
' * Header structure for the input buffer to POSTSCRIPT_INJECTION escape
' */

' // Size = 8 bytes
TYPE PSINJECTDATA WORD
   DataBytes      AS DWORD   ' DWORD /* number of raw data bytes (NOT including this header) */
   InjectionPoint AS WORD    ' WORD  /* injection point */
   PageNumber     AS WORD    ' WORD  /* page number to apply the injection */
   ' /* Followed by raw data to be injected */
END TYPE

'/*
' * Constants for PSINJECTDATA.InjectionPoint field
' */

%PSINJECT_BEGINSTREAM                = 1
%PSINJECT_PSADOBE                    = 2
%PSINJECT_PAGESATEND                 = 3
%PSINJECT_PAGES                      = 4

%PSINJECT_DOCNEEDEDRES               = 5
%PSINJECT_DOCSUPPLIEDRES             = 6
%PSINJECT_PAGEORDER                  = 7
%PSINJECT_ORIENTATION                = 8
%PSINJECT_BOUNDINGBOX                = 9
%PSINJECT_DOCUMENTPROCESSCOLORS      = 10

%PSINJECT_COMMENTS                   = 11
%PSINJECT_BEGINDEFAULTS              = 12
%PSINJECT_ENDDEFAULTS                = 13
%PSINJECT_BEGINPROLOG                = 14
%PSINJECT_ENDPROLOG                  = 15
%PSINJECT_BEGINSETUP                 = 16
%PSINJECT_ENDSETUP                   = 17
%PSINJECT_TRAILER                    = 18
%PSINJECT_EOF                        = 19
%PSINJECT_ENDSTREAM                  = 20
%PSINJECT_DOCUMENTPROCESSCOLORSATEND = 21

%PSINJECT_PAGENUMBER                 = 100
%PSINJECT_BEGINPAGESETUP             = 101
%PSINJECT_ENDPAGESETUP               = 102
%PSINJECT_PAGETRAILER                = 103
%PSINJECT_PLATECOLOR                 = 104

%PSINJECT_SHOWPAGE                   = 105
%PSINJECT_PAGEBBOX                   = 106
%PSINJECT_ENDPAGECOMMENTS            = 107

%PSINJECT_VMSAVE                     = 200
%PSINJECT_VMRESTORE                  = 201

'/*
' * InjectionPoint for publisher mode PScript5 OEM plugin to
' * generate DSC comment for included font resource
' */
%PSINJECT_DLFONT                     = &Hdddddddd???

'/*
' * Parameter for GET_PS_FEATURESETTING escape
' */

%FEATURESETTING_NUP                  = 0
%FEATURESETTING_OUTPUT               = 1
%FEATURESETTING_PSLEVEL              = 2
%FEATURESETTING_CUSTPAPER            = 3
%FEATURESETTING_MIRROR               = 4
%FEATURESETTING_NEGATIVE             = 5
%FEATURESETTING_PROTOCOL             = 6

'#if (_WIN32_WINNT >= _WIN32_WINNT_WINXP)
'//
'// The range of selectors between FEATURESETTING_PRIVATE_BEGIN and
'// FEATURESETTING_PRIVATE_END is reserved by Microsoft for private use
'//
%FEATURESETTING_PRIVATE_BEGIN = &H1000
%FEATURESETTING_PRIVATE_END   = &H1FFF
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WINXP)

'/*
' * Information about output options
' */

' // Size = 8 bytes
TYPE PSFEATURE_OUTPUT DWORD
   bPageIndependent AS LONG   ' BOOL
   bSetPageDevice   AS LONG   ' BOOL
END TYPE

'/*
' * Information about custom paper size
' */

' // Size = 20 bytes
TYPE PSFEATURE_CUSTPAPER DWORD
   lOrientation  AS LONG
   lWidth        AS LONG
   lHeight       AS LONG
   lWidthOffset  AS LONG
   lHeightOffset AS LONG
END TYPE

'/* Value returned for FEATURESETTING_PROTOCOL */
%PSPROTOCOL_ASCII            = 0
%PSPROTOCOL_BCP              = 1
%PSPROTOCOL_TBCP             = 2
%PSPROTOCOL_BINARY           = 3

'/* Flag returned from QUERYDIBSUPPORT */
%QDI_SETDIBITS               = 1
%QDI_GETDIBITS               = 2
%QDI_DIBTOSCREEN             = 4
%QDI_STRETCHDIB              = 8

'/* Spooler Error Codes */
%SP_NOTREPORTED = &H4000
%SP_ERROR       = -1
%SP_APPABORT    = -2
%SP_USERABORT   = -3
%SP_OUTOFDISK   = -4
%SP_OUTOFMEMORY = -5

%PR_JOBSTATUS = &H0000

'/* Object Definitions for EnumObjects() */
%OBJ_PEN         = 1
%OBJ_BRUSH       = 2
%OBJ_DC          = 3
%OBJ_METADC      = 4
%OBJ_PAL         = 5
%OBJ_FONT        = 6
%OBJ_BITMAP      = 7
%OBJ_REGION      = 8
%OBJ_METAFILE    = 9
%OBJ_MEMDC       = 10
%OBJ_EXTPEN      = 11
%OBJ_ENHMETADC   = 12
%OBJ_ENHMETAFILE = 13
%OBJ_COLORSPACE  = 14

%GDI_OBJ_LAST    = %OBJ_COLORSPACE

'/* xform stuff */
%MWT_IDENTITY      = 1
%MWT_LEFTMULTIPLY  = 2
%MWT_RIGHTMULTIPLY = 3

%MWT_MIN = %MWT_IDENTITY
%MWT_MAX = %MWT_RIGHTMULTIPLY

'#define _XFORM_
#IF NOT %DEF(%XFORM)
%XFORM = 1
' // Size = 24 bytes
TYPE XFORM DWORD
   eM11 AS SINGLE   ' FLOAT
   eM12 AS SINGLE   ' FLOAT
   eM21 AS SINGLE   ' FLOAT
   eM22 AS SINGLE   ' FLOAT
   eDx  AS SINGLE   ' FLOAT
   eDy  AS SINGLE   ' FLOAT
END TYPE
#ENDIF

'/* Bitmap Header Definition */

' // Size = 24 bytes
TYPE BITMAP DWORD FILL
   bmType       AS LONG       ' LONG
   bmWidth      AS LONG       ' LONG
   bmHeight     AS LONG       ' LONG
   bmWidthBytes AS LONG       ' LONG
   bmPlanes     AS WORD       ' WORD
   bmBitsPixel  AS WORD       ' WORD
   bmBits       AS BYTE PTR   ' LPVOID
END TYPE

'#include <pshpack1.h>
' // Size = 3 bytes
TYPE RGBTRIPLE BYTE
   rgbtBlue  AS BYTE
   rgbtGreen AS BYTE
   rgbtRed   AS BYTE
END TYPE
'#include <poppack.h>

#IF NOT %DEF(%RGBQUAD_DEFINED)
%RGBQUAD_DEFINED = 1
' // Size = 4 bytes
TYPE RGBQUAD BYTE
   rgbBlue     AS BYTE
   rgbGreen    AS BYTE
   rgbRed      AS BYTE
   rgbReserved AS BYTE
END TYPE
#ENDIF

'#if(WINVER >= 0x0400)

'/* Image Color Matching color definitions */

%CS_ENABLE           = &H00000001???
%CS_DISABLE          = &H00000002???
%CS_DELETE_TRANSFORM = &H00000003???

'/* Logcolorspace signature */

'#define LCS_SIGNATURE           'PSOC'
%LCS_SIGNATURE = &H50534f43     ' "PSOC"

'/* Logcolorspace lcsType values */

'#define LCS_sRGB                'sRGB'
'#define LCS_WINDOWS_COLOR_SPACE 'Win '  // Windows default color space

%LCS_sRGB                = &H73524742  ' "sRGB"
%LCS_WINDOWS_COLOR_SPACE = &H57696e20  ' "Win "  ' Windows default color space

'typedef LONG   LCSCSTYPE;
%LCS_CALIBRATED_RGB      = &H00000000???

'typedef LONG    LCSGAMUTMATCH;
%LCS_GM_BUSINESS         = &H00000001???
%LCS_GM_GRAPHICS         = &H00000002???
%LCS_GM_IMAGES           = &H00000004???
%LCS_GM_ABS_COLORIMETRIC = &H00000008???

'/* ICM Defines for results from CheckColorInGamut() */
%CM_OUT_OF_GAMUT = 255
%CM_IN_GAMUT     = 0

'/* UpdateICMRegKey Constants               */
%ICM_ADDPROFILE          = 1???
%ICM_DELETEPROFILE       = 2???
%ICM_QUERYPROFILE        = 3???
%ICM_SETDEFAULTPROFILE   = 4???
%ICM_REGISTERICMATCHER   = 5???
%ICM_UNREGISTERICMATCHER = 6???
%ICM_QUERYMATCH          = 7???

'/* Macros to retrieve CMYK values from a COLORREF */
'#define GetKValue(cmyk)      ((BYTE)(cmyk))
'#define GetYValue(cmyk)      ((BYTE)((cmyk)>> 8))
'#define GetMValue(cmyk)      ((BYTE)((cmyk)>>16))
'#define GetCValue(cmyk)      ((BYTE)((cmyk)>>24))

'#define CMYK(c,m,y,k)       ((COLORREF)((((BYTE)(k)|((WORD)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))

'MACRO GetKValue(dwCMYK) = LO(BYTE, dwCMYK)
'MACRO GetYValue(dwCMYK) = HI(BYTE, LO(WORD, dwCMYK)))
'MACRO GetMValue(dwCMYK) = LO(BYTE, HI(WORD, dwCMYK))
'MACRO GetCValue(dwCMYK) = HI(BYTE, HI(WORD, dwCMYK))

' // Not a macro because it conflicts with the cmyk member of the tagCOLOR union in Icm.inc
'MACRO CMYK(c,m,y,k) = (LO(BYTE, k) OR LO(BYTE, y) * 256 OR LO(BYTE, m) * 65536 OR LO(BYTE, c) * 65536 * 256)

FUNCTION GetKValue (BYVAL dwCMYK AS DWORD) AS BYTE
   FUNCTION = LO(BYTE, dwCMYK)
END FUNCTION

FUNCTION GetYValue (BYVAL dwCMYK AS DWORD) AS BYTE
   FUNCTION = (HI(BYTE, LO(WORD, dwCMYK)))
END FUNCTION

FUNCTION GetMValue (BYVAL dwCMYK AS DWORD) AS BYTE
   FUNCTION = LO(BYTE, HI(WORD, dwCMYK))
END FUNCTION

FUNCTION GetCValue (BYVAL dwCMYK AS DWORD) AS BYTE
   FUNCTION = HI(BYTE, HI(WORD, dwCMYK))
END FUNCTION

FUNCTION CMYK (BYVAL c AS BYTE, BYVAL m AS BYTE, BYVAL y AS BYTE, BYVAL k AS BYTE) AS DWORD
   FUNCTION = (LO(BYTE, k) OR LO(BYTE, y) * 256 OR LO(BYTE, m) * 65536 OR LO(BYTE, c) * 65536 * 256)
END FUNCTION

'typedef long            FXPT16DOT16, FAR *LPFXPT16DOT16;
'typedef long            FXPT2DOT30, FAR *LPFXPT2DOT30;

'/* ICM Color Definitions */
'// The following two structures are used for defining RGB's in terms of CIEXYZ.

' // Size = 12 bytes
TYPE CIEXYZ DWORD
   ciexyzX AS LONG   ' FXPT2DOT30
   ciexyzY AS LONG   ' FXPT2DOT30
   ciexyzZ AS LONG   ' FXPT2DOT30
END TYPE

' // Size = 36 bytes
TYPE CIEXYZTRIPLE DWORD
   ciexyzRed   AS CIEXYZ
   ciexyzGreen AS CIEXYZ
   ciexyBlue   AS CIEXYZ
END TYPE

'// The next structures the logical color space. Unlike pens and brushes,
'// but like palettes, there is only one way to create a LogColorSpace.
'// A pointer to it must be passed, its elements can't be pushed as
'// arguments.
' // Size = 328 bytes
TYPE LOGCOLORSPACEA DWORD
   lcsSignature  AS DWORD                   ' DWORD
   lcsVersion    AS DWORD                   ' DWORD
   lcsSize       AS DWORD                   ' DWORD
   lcsCSType     AS LONG                    ' LCSCSTYPE
   lcsIntent     AS LONG                    ' LCSGAMUTMATCH
   lcsEndPoints  AS CIEXYZTRIPLE            ' CIEXYZTRIPLE
   lcsGammaRed   AS DWORD                   ' DWORD
   lcsGammaGreen AS DWORD                   ' DWORD
   lcsGammaBlue  AS DWORD                   ' DWORD
   lcsFileName   AS ASCIIZ * %MAX_PATH      ' CHAR   lcsFilename[MAX_PATH]
END TYPE

' // Size = 588 bytes
TYPE LOGCOLORSPACEW DWORD
   lcsSignature  AS DWORD                   ' DWORD
   lcsVersion    AS DWORD                   ' DWORD
   lcsSize       AS DWORD                   ' DWORD
   lcsCSType     AS LONG                    ' LCSCSTYPE
   lcsIntent     AS LONG                    ' LCSGAMUTMATCH
   lcsEndPoints  AS CIEXYZTRIPLE            ' CIEXYZTRIPLE
   lcsGammaRed   AS DWORD                   ' DWORD
   lcsGammaGreen AS DWORD                   ' DWORD
   lcsGammaBlue  AS DWORD                   ' DWORD
   lcsFileName   AS WSTRINGZ * %MAX_PATH    ' WCHAR   lcsFilename[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO LOGCOLORSPACE = LOGCOLORSPACEW
#ELSE
   MACRO LOGCOLORSPACE = LOGCOLORSPACEA
#ENDIF

'#endif /* WINVER >= 0x0400 */

'/* structures for defining DIBs */
' // Size = 12 bytes
TYPE BITMAPCOREHEADER DWORD FILL
   bcSize     AS DWORD
   bcWidth    AS WORD
   bcHeight   AS WORD
   bcPlanes   AS WORD
   bcBitCount AS WORD
END TYPE

' // Size = 40 bytes
TYPE BITMAPINFOHEADER DWORD FILL
   biSize          AS DWORD
   biWidth         AS LONG
   biHeight        AS LONG
   biPlanes        AS WORD
   biBitCount      AS WORD
   biCompression   AS DWORD
   biSizeImage     AS DWORD
   biXPelsPerMeter AS LONG
   biYPelsPerMeter AS LONG
   biClrUsed       AS DWORD
   biClrImportant  AS DWORD
END TYPE

'#if(WINVER >= 0x0400)
' // Size = 108 bytes
TYPE BITMAPV4HEADER DWORD FILL
   bV4Size          AS DWORD
   bV4Width         AS LONG
   bV4Height        AS LONG
   bV4Planes        AS WORD
   bV4BitCount      AS WORD
   bV4Compression   AS DWORD
   bV4SizeImage     AS DWORD
   bV4XPelsPerMeter AS LONG
   bV4YPelsPerMeter AS LONG
   bV4ClrUsed       AS DWORD
   bV4ClrImportant  AS DWORD
   bV4RedMask       AS DWORD
   bV4GreenMask     AS DWORD
   bV4BlueMask      AS DWORD
   bV4AlphaMask     AS DWORD
   bV4CSType        AS DWORD
   bV4Endpoints     AS CIEXYZTRIPLE
   bV4GammaRed      AS DWORD
   bV4GammaGreen    AS DWORD
   bV4GammaBlue     AS DWORD
END TYPE
'#endif /* WINVER >= 0x0400 */

'#if (WINVER >= 0x0500)
' // Size = 124 bytes
TYPE BITMAPV5HEADER DWORD FILL
   bV5Size          AS DWORD
   bV5Width         AS LONG
   bV5Height        AS LONG
   bV5Planes        AS WORD
   bV5BitCount      AS WORD
   bV5Compression   AS DWORD
   bV5SizeImage     AS DWORD
   bV5XPelsPerMeter AS LONG
   bV5YPelsPerMeter AS LONG
   bV5ClrUsed       AS DWORD
   bV5ClrImportant  AS DWORD
   bV5RedMask       AS DWORD
   bV5GreenMask     AS DWORD
   bV5BlueMask      AS DWORD
   bV5AlphaMask     AS DWORD
   bV5CSType        AS DWORD
   bV5Endpoints     AS CIEXYZTRIPLE
   bV5GammaRed      AS DWORD
   bV5GammaGreen    AS DWORD
   bV5GammaBlue     AS DWORD
   bV5Intent        AS DWORD
   bV5ProfileData   AS DWORD
   bV5ProfileSize   AS DWORD
   bV5Reserved      AS DWORD
END TYPE

'// Values for bV5CSType
'#define PROFILE_LINKED          'LINK'
'#define PROFILE_EMBEDDED        'MBED'

%PROFILE_LINKED   = &H4c494e4b  ' "LINK"
%PROFILE_EMBEDDED = &H4d424544  ' "MBED"
'#endif

'/* constants for the biCompression field */
%BI_RGB       = 0???
%BI_RLE8      = 1???
%BI_RLE4      = 2???
%BI_BITFIELDS = 3???
%BI_JPEG      = 4???
%BI_PNG       = 5???
'#if (_WIN32_WINNT >= 0x0400)
'#endif

' // Size = 44 bytes
TYPE BITMAPINFO DWORD
   bmiHeader    AS BITMAPINFOHEADER
   bmiColors(0) AS RGBQUAD            ' RGBQUAD
END TYPE

' // Size = 16 bytes
TYPE BITMAPCOREINFO DWORD
   bmciHeader    AS BITMAPCOREHEADER
   bmciColors(0) AS RGBTRIPLE          ' RGBTRIPLE bmciColors[1]
END TYPE

'#include <pshpack2.h>
' // Size = 14 bytes
TYPE BITMAPFILEHEADER WORD
   bfType      AS WORD
   bfSize      AS DWORD
   bfReserved1 AS WORD
   bfReserved2 AS WORD
   bfOffBits   AS DWORD
END TYPE
'#include <poppack.h>

'#define MAKEPOINTS(l)       (*((POINTS FAR *)&(l)))

MACRO MAKEPOINTS(l, pt)
   pt.x = LO(INTEGER, l)
   pt.y = HI(INTEGER, l)
END MACRO

'#if(WINVER >= 0x0400)
#IF NOT %DEF(%NOFONTSIG)   ' --------------------------------------------------
'#ifndef NOFONTSIG
' // Size = 24 bytes
TYPE FONTSIGNATURE DWORD
   fsUsb(3) AS DWORD
   fsCsb(1) AS DWORD
END TYPE

' // Size = 32 bytes
TYPE CHARSETINFO DWORD
   ciCharset AS DWORD           ' UINT
   ciACP     AS DWORD           ' UINT
   fs        AS FONTSIGNATURE   ' FONTSIGNATURE
END TYPE

%TCI_SRCCHARSET  = 1???
%TCI_SRCCODEPAGE = 2???
%TCI_SRCFONTSIG  = 3???
'#if (_WIN32_WINNT >= _WIN32_WINNT_WINXP)
%TCI_SRCLOCALE   = &H1000???
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WINXP)

' // Size = 32 bytes
TYPE LOCALESIGNATURE DWORD
   lsUsb         (3) AS DWORD
   lsCsbDefault  (1) AS DWORD
   lsCsbSupported(1) AS DWORD
END TYPE

'#endif
#ENDIF   ' #IF NOT %DEF(%NOFONTSIG)   -----------------------------------------
'#endif /* WINVER >= 0x0400 */

#IF NOT %DEF(%NOMETAFILE) ' ---------------------------------------------------
'#ifndef NOMETAFILE

'/* Clipboard Metafile Picture Structure */
' // Size = 4 bytes
TYPE HANDLETABLE DWORD
   objectHandle(0) AS DWORD   ' HGDIOBJ objectHandle[1]
END TYPE

' // Size = 8 bytes
TYPE METARECORD DWORD FILL
   rdSize     AS DWORD   ' DWORD
   rdFunction AS WORD    ' WORD
   rdParm(0)  AS WORD    ' WORD  rdParm[1]
END TYPE

' // Size = 16 bytes
TYPE METAFILEPICT DWORD
   mm   AS LONG    ' LONG
   xExt AS LONG    ' LONG
   yExt AS LONG    ' LONG
   hMF  AS DWORD   ' HMETAFILE
END TYPE

'#include <pshpack2.h>
' // Size = 18 bytes
TYPE METAHEADER WORD
   mtType         AS WORD
   mtHeaderSize   AS WORD
   mtVersion      AS WORD
   mtSize         AS DWORD
   mtNoObjects    AS WORD
   mtMaxRecord    AS DWORD
   mtNoParameters AS WORD
END TYPE

'#include <poppack.h>

' // Size = 12 bytes
TYPE ENHMETARECORD DWORD
   iType    AS DWORD   ' DWORD
   nSize    AS DWORD   ' DWORD
   dParm(0) AS DWORD   ' DWORD   dParm[1]
END TYPE

' // Size = 108 bytes
TYPE ENHMETAHEADER DWORD FILL
   iType          AS DWORD   ' DWORD // Record type EMR_HEADER
   nSize          AS DWORD   ' DWORD // Record size in bytes. This may be greater
                             '       // than the sizeof(ENHMETAHEADER).
   rclBounds      AS RECTL   ' RECTL // Inclusive-inclusive bounds in device units
   rclFrame       AS RECTL   ' RECTL // Inclusive-inclusive Picture Frame of metafile in .01 mm units
   dSignature     AS DWORD   ' DWORD // Signature. Must be ENHMETA_SIGNATURE.
   nVersion       AS DWORD   ' DWORD // Version number
   nBytes         AS DWORD   ' DWORD // Size of the metafile in bytes
   nRecords       AS DWORD   ' DWORD // Number of records in the metafile
   nHandles       AS WORD    ' WORD  // Number of handles in the handle table
                             '       // Handle index zero is reserved.
   sReserved      AS WORD    ' WORD  // Reserved. Must be zero.
   nDescription   AS DWORD   ' DWORD // Number of chars in the unicode description string
                             '       // This is 0 if there is no description string
   offDescription AS DWORD   ' DWORD // Offset to the metafile description record.
                             '       // This is 0 if there is no description string
   nPalEntries    AS DWORD   ' DWORD // Number of entries in the metafile palette.
   szlDevice      AS SIZEL   ' SIZEL // Size of the reference device in pels
   szlMillimeters AS SIZEL   ' SIZEL // Size of the reference device in millimeters
#IF (%WINVER >= &H0400)
   cbPixelFormat  AS DWORD   ' DWORD // Size of PIXELFORMATDESCRIPTOR information
                             '       // This is 0 if no pixel format is set
   offPixelFormat AS DWORD   ' DWORD // Offset to PIXELFORMATDESCRIPTOR
                             '       // This is 0 if no pixel format is set
   bOpenGL        AS DWORD   ' DWORD // TRUE if OpenGL commands are present in
                             '       // the metafile, otherwise FALSE
#ENDIF   ' /* WINVER >= 0x0400 */
#IF (%WINVER >= &H0500)
   szlMicrometers AS SIZEL   ' SIZEL // Size of the reference device in micrometers
#ENDIF   ' /* WINVER >= 0x0500 */
END TYPE

'#endif /* NOMETAFILE */
#ENDIF   ' #IF NOT %DEF(%NOMETAFILE) ------------------------------------------

#IF NOT %DEF(%NOTEXTMETRIC) ' -------------------------------------------------
'#ifndef NOTEXTMETRIC

'/* tmPitchAndFamily flags */
%TMPF_FIXED_PITCH = &H01?
%TMPF_VECTOR      = &H02?
%TMPF_DEVICE      = &H08?
%TMPF_TRUETYPE    = &H04?

'//
'// BCHAR definition for APPs
'//
#IF NOT %DEF(%TEXTMETRIC_DEFINED) '--------------------------------------------
%TEXTMETRIC_DEFINED = 1
'#include <pshpack4.h>
' // Size = 56 bytes
TYPE TEXTMETRICA   ' Must be 4 byte aligned
   tmHeight           AS LONG         ' LONG
   tmAscent           AS LONG         ' LONG
   tmDescent          AS LONG         ' LONG
   tmInternalLeading  AS LONG         ' LONG
   tmExternalLeading  AS LONG         ' LONG
   tmAveCharWidth     AS LONG         ' LONG
   tmMaxCharWidth     AS LONG         ' LONG
   tmWeight           AS LONG         ' LONG
   tmOverhang         AS LONG         ' LONG
   tmDigitizedAspectX AS LONG         ' LONG
   tmDigitizedAspectY AS LONG         ' LONG
   tmFirstChar        AS STRING * 1   ' BYTE [must be char]
   tmLastChar         AS STRING * 1   ' BYTE [must be char]
   tmDefaultChar      AS STRING * 1   ' BYTE [must be char]
   tmBreakChar        AS STRING * 1   ' BYTE [must be char]
   tmItalic           AS BYTE         ' BYTE
   tmUnderlined       AS BYTE         ' BYTE
   tmStruckOut        AS BYTE         ' BYTE
   tmPitchAndFamily   AS BYTE         ' BYTE
   tmCharSet          AS BYTE         ' BYTE
   alignment__(2)     AS BYTE         ' // To keep DWORD alignment
END TYPE

%TEXTMETRICW_DEFINED = 1
' // Size = 60 bytes
TYPE TEXTMETRICW   ' Must be 4 byte aligned
   tmHeight           AS LONG          ' LONG
   tmAscent           AS LONG          ' LONG
   tmDescent          AS LONG          ' LONG
   tmInternalLeading  AS LONG          ' LONG
   tmExternalLeading  AS LONG          ' LONG
   tmAveCharWidth     AS LONG          ' LONG
   tmMaxCharWidth     AS LONG          ' LONG
   tmWeight           AS LONG          ' LONG
   tmOverhang         AS LONG          ' LONG
   tmDigitizedAspectX AS LONG          ' LONG
   tmDigitizedAspectY AS LONG          ' LONG
   tmFirstChar        AS WSTRING * 1   ' WCHAR
   tmLastChar         AS WSTRING * 1   ' WCHAR
   tmDefaultChar      AS WSTRING * 1   ' WCHAR
   tmBreakChar        AS WSTRING * 1   ' WCHAR
   tmItalic           AS BYTE          ' BYTE
   tmUnderlined       AS BYTE          ' BYTE
   tmStruckOut        AS BYTE          ' BYTE
   tmPitchAndFamily   AS BYTE          ' BYTE
   tmCharSet          AS BYTE          ' BYTE
   alignment__(2)     AS BYTE         ' // To keep DWORD alignment
END TYPE

#IF %DEF(%UNICODE)
   MACRO TEXTMETRIC = TEXTMETRICW
#ELSE
   MACRO TEXTMETRIC = TEXTMETRICA
#ENDIF

'#include <poppack.h>
#ENDIF   ' #IF NOT %DEF(%TEXTMETRIC_DEFINED) ----------------------------------

'/* ntmFlags field flags */
%NTM_REGULAR        = &H00000040???
%NTM_BOLD           = &H00000020???
%NTM_ITALIC         = &H00000001???

'/* new in NT 5.0 */

%NTM_NONNEGATIVE_AC = &H00010000???
%NTM_OPENTYPE       = &H00020000???
%NTM_MULTIPLEMASTER = &H00040000???
%NTM_MM_INSTANCE    = &H00080000???
%NTM_TYPE1          = &H00100000???
%NTM_DSIG           = &H00200000???

'#include <pshpack4.h>
' // Size = 72 bytes
TYPE NEWTEXTMETRICA DWORD FILL   ' Must be 4 byte aligned
   tmHeight           AS LONG         ' LONG
   tmAscent           AS LONG         ' LONG
   tmDescent          AS LONG         ' LONG
   tmInternalLeading  AS LONG         ' LONG
   tmExternalLeading  AS LONG         ' LONG
   tmAveCharWidth     AS LONG         ' LONG
   tmMaxCharWidth     AS LONG         ' LONG
   tmWeight           AS LONG         ' LONG
   tmOverhang         AS LONG         ' LONG
   tmDigitizedAspectX AS LONG         ' LONG
   tmDigitizedAspectY AS LONG         ' LONG
   tmFirstChar        AS STRING * 1   ' BYTE [must be char]
   tmLastChar         AS STRING * 1   ' BYTE [must be char]
   tmDefaultChar      AS STRING * 1   ' BYTE [must be char]
   tmBreakChar        AS STRING * 1   ' BYTE [must be char]
   tmItalic           AS BYTE         ' BYTE
   tmUnderlined       AS BYTE         ' BYTE
   tmStruckOut        AS BYTE         ' BYTE
   tmPitchAndFamily   AS BYTE         ' BYTE
   tmCharSet          AS BYTE         ' BYTE
   ntmFlags           AS DWORD        ' DWORD
   ntmSizeEM          AS DWORD        ' UINT
   ntmCellHeight      AS DWORD        ' UINT
   ntmAveWidth        AS DWORD        ' UINT
END TYPE

' // Size = 76 bytes
TYPE NEWTEXTMETRICW DWORD FILL
   tmHeight           AS LONG          ' LONG
   tmAscent           AS LONG          ' LONG
   tmDescent          AS LONG          ' LONG
   tmInternalLeading  AS LONG          ' LONG
   tmExternalLeading  AS LONG          ' LONG
   tmAveCharWidth     AS LONG          ' LONG
   tmMaxCharWidth     AS LONG          ' LONG
   tmWeight           AS LONG          ' LONG
   tmOverhang         AS LONG          ' LONG
   tmDigitizedAspectX AS LONG          ' LONG
   tmDigitizedAspectY AS LONG          ' LONG
   tmFirstChar        AS WSTRING * 1   ' WCHAR
   tmLastChar         AS WSTRING * 1   ' WCHAR
   tmDefaultChar      AS WSTRING * 1   ' WCHAR
   tmBreakChar        AS WSTRING * 1   ' WCHAR
   tmItalic           AS BYTE          ' BYTE
   tmUnderlined       AS BYTE          ' BYTE
   tmStruckOut        AS BYTE          ' BYTE
   tmPitchAndFamily   AS BYTE          ' BYTE
   tmCharSet          AS BYTE          ' BYTE
   ntmFlags           AS DWORD         ' DWORD
   ntmSizeEM          AS DWORD         ' UINT
   ntmCellHeight      AS DWORD         ' UINT
   ntmAveWidth        AS DWORD         ' UINT
END TYPE

#IF %DEF(%UNICODE)
   MACRO NEWTEXTMETRIC = NEWTEXTMETRICW
#ELSE
   MACRO NEWTEXTMETRIC = NEWTEXTMETRICA
#ENDIF

'#include <poppack.h>

'#if(WINVER >= 0x0400)
' // Size = 96 bytes
TYPE NEWTEXTMETRICEXA DWORD FILL
   ntmTm      AS NEWTEXTMETRIC
   ntmFontSig AS FONTSIGNATURE
END TYPE

' // Size = 100 bytes
TYPE NEWTEXTMETRICEXW DWORD FILL
   ntmTm      AS NEWTEXTMETRICW
   ntmFontSig AS FONTSIGNATURE
END TYPE

#IF %DEF(%UNICODE)
   MACRO NEWTEXTMETRICEX = NEWTEXTMETRICEXW
#ELSE
   MACRO NEWTEXTMETRICEX = NEWTEXTMETRICEXA
#ENDIF
'#endif /* WINVER >= 0x0400 */

'#endif /* NOTEXTMETRIC */
#ENDIF   ' #IF NOT %DEF(%NOTEXTMETRIC) ----------------------------------------
'/* GDI Logical Objects: */

'/* Pel Array */
' // Size = 100 bytes
TYPE PELARRAY DWORD
   paXCount AS LONG
   paYCount AS LONG
   paXExt   AS LONG
   paYExt   AS LONG
   paRGBs   AS BYTE
END TYPE

'/* Logical Brush (or Pattern) */
' // Size = 12 bytes
TYPE LOGBRUSH DWORD
   lbStyle AS DWORD   ' UINT
   lbColor AS DWORD   ' COLORREF
   lbHatch AS DWORD   ' ULONG_PTR
END TYPE

' // Size = 12 bytes
TYPE LOGBRUSH32 DWORD
   lbStyle AS DWORD   ' UINT
   lbColor AS DWORD   ' COLORREF
   lbHatch AS DWORD   ' ULONG
END TYPE

'typedef LOGBRUSH             PATTERN;
'typedef PATTERN             *PPATTERN;
'typedef PATTERN NEAR        *NPPATTERN;
'typedef PATTERN FAR         *LPPATTERN;

'/* Logical Pen */
' // Size = 16 bytes
TYPE LOGPEN DWORD
   lopnStyle AS DWORD   ' UINT
   lopnWidth AS POINT   ' POINT
   lopnColor AS DWORD   ' COLORREF
END TYPE

' // Size = 28 bytes
TYPE EXTLOGPEN DWORD
   elpPenStyle      AS DWORD   ' DWORD
   elpWidth         AS DWORD   ' DWORD
   elpBrushStyle    AS DWORD   ' UINT
   elpColor         AS DWORD   ' COLORREF
   elpHatch         AS DWORD   ' ULONG_PTR
   elpNumEntries    AS DWORD   ' DWORD
   elpStyleEntry(0) AS DWORD   ' DWORD elpStyleEntry[1]
END TYPE

' // Size = 28 bytes
TYPE EXTLOGPEN32 DWORD
   elpPenStyle      AS DWORD   ' DWORD
   elpWidth         AS DWORD   ' DWORD
   elpBrushStyle    AS DWORD   ' UINT
   elpColor         AS DWORD   ' COLORREF
   elpHatch         AS DWORD   ' ULONG
   elpNumEntries    AS DWORD   ' DWORD
   elpStyleEntry(0) AS DWORD   ' DWORD elpStyleEntry[1]
END TYPE

#IF NOT %DEF(%PALETTEENTRY_DEFINED) '------------------------------------------
%PALETTEENTRY_DEFINED = 1
' // Size = 4 bytes
TYPE PALETTEENTRY BYTE
   peRed   AS BYTE
   peGreen AS BYTE
   peBlue  AS BYTE
   peFlags AS BYTE
END TYPE
#ENDIF   ' #IF NOT %DEF(%PALETTEENTRY_DEFINED) --------------------------------

#IF NOT %DEF(%LOGPALETTE_DEFINED) '--------------------------------------------
%LOGPALETTE_DEFINED = 1
' // Size = 8 bytes
TYPE LOGPALETTE BYTE
  palVersion     AS WORD
  palNumEntries  AS WORD
  palPalEntry(0) AS PALETTEENTRY   ' PALETTEENTRY palPalEntry[1]
END TYPE

TYPE LOGPALETTE256 BYTE
  palVersion       AS WORD
  palNumEntries    AS WORD
  palPalEntry(255) AS PALETTEENTRY   ' Enough for 256 colors
END TYPE

'#endif // !_LOGPALETTE_DEFINED
#ENDIF   ' #IF NOT %DEF(%LOGPALETTE_DEFINED) ----------------------------------

'/* Logical Font */
%LF_FACESIZE     = 32

' // Size = 60 bytes
TYPE LOGFONTA DWORD FILL
   lfHeight         AS LONG
   lfWidth          AS LONG
   lfEscapement     AS LONG
   lfOrientation    AS LONG
   lfWeight         AS LONG
   lfItalic         AS BYTE
   lfUnderline      AS BYTE
   lfStrikeOut      AS BYTE
   lfCharSet        AS BYTE
   lfOutPrecision   AS BYTE
   lfClipPrecision  AS BYTE
   lfQuality        AS BYTE
   lfPitchAndFamily AS BYTE
   lfFaceName       AS ASCIIZ * %LF_FACESIZE   ' CHAR lfFaceName[LF_FACESIZE]
END TYPE

' // Size = 92 bytes
TYPE LOGFONTW DWORD FILL
   lfHeight         AS LONG
   lfWidth          AS LONG
   lfEscapement     AS LONG
   lfOrientation    AS LONG
   lfWeight         AS LONG
   lfItalic         AS BYTE
   lfUnderline      AS BYTE
   lfStrikeOut      AS BYTE
   lfCharSet        AS BYTE
   lfOutPrecision   AS BYTE
   lfClipPrecision  AS BYTE
   lfQuality        AS BYTE
   lfPitchAndFamily AS BYTE
   lfFaceName       AS WSTRINGZ * %LF_FACESIZE   ' WCHAR lfFaceName[LF_FACESIZE]
END TYPE

#IF %DEF(%UNICODE)
   MACRO LOGFONT = LOGFONTW
#ELSE
   MACRO LOGFONT = LOGFONTA
#ENDIF

%LF_FULLFACESIZE = 64

'/* Structure passed to FONTENUMPROC */
'typedef struct tagENUMLOGFONTA
'{
'    LOGFONTA elfLogFont;
'    BYTE     elfFullName[LF_FULLFACESIZE];
'    BYTE     elfStyle[LF_FACESIZE];
'} ENUMLOGFONTA, FAR* LPENUMLOGFONTA;

' // Size = 156 bytes
TYPE ENUMLOGFONTA DWORD
   elfLogFont  AS LOGFONTA
   elfFullName AS ASCIIZ * %LF_FULLFACESIZE
   elfStyle    AS ASCIIZ * %LF_FACESIZE
END TYPE

'/* Structure passed to FONTENUMPROC */
'typedef struct tagENUMLOGFONTW
'{
'    LOGFONTW elfLogFont;
'    WCHAR    elfFullName[LF_FULLFACESIZE];
'    WCHAR    elfStyle[LF_FACESIZE];
'} ENUMLOGFONTW, FAR* LPENUMLOGFONTW;

' // Size = 284 bytes
TYPE ENUMLOGFONTW DWORD
   elfLogFont  AS LOGFONTW
   elfFullName AS WSTRINGZ * %LF_FULLFACESIZE
   elfStyle    AS WSTRINGZ * %LF_FACESIZE
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUMLOGFONT = ENUMLOGFONTW
#ELSE
   MACRO ENUMLOGFONT = ENUMLOGFONTA
#ENDIF

'#if(WINVER >= 0x0400)
'typedef struct tagENUMLOGFONTEXA
'{
'    LOGFONTA    elfLogFont;
'    BYTE        elfFullName[LF_FULLFACESIZE];
'    BYTE        elfStyle[LF_FACESIZE];
'    BYTE        elfScript[LF_FACESIZE];
'} ENUMLOGFONTEXA, FAR *LPENUMLOGFONTEXA;

' // Size = 188 bytes
TYPE ENUMLOGFONTEXA DWORD
   elfLogFont  AS LOGFONTA
   elfFullName AS ASCIIZ  * %LF_FULLFACESIZE
   elfStyle    AS ASCIIZ  * %LF_FACESIZE
   elfScript   AS ASCIIZ  * %LF_FACESIZE
END TYPE

'typedef struct tagENUMLOGFONTEXW
'{
'    LOGFONTW    elfLogFont;
'    WCHAR       elfFullName[LF_FULLFACESIZE];
'    WCHAR       elfStyle[LF_FACESIZE];
'    WCHAR       elfScript[LF_FACESIZE];
'} ENUMLOGFONTEXW, FAR *LPENUMLOGFONTEXW;

' // Size = 348 bytes
TYPE ENUMLOGFONTEXW DWORD
   elfLogFont  AS LOGFONTW
   elfFullName AS WSTRINGZ  * %LF_FULLFACESIZE
   elfStyle    AS WSTRINGZ  * %LF_FACESIZE
   elfScript   AS WSTRINGZ  * %LF_FACESIZE
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUMLOGFONTEX = ENUMLOGFONTEXW
#ELSE
   MACRO ENUMLOGFONTEX = ENUMLOGFONTEXA
#ENDIF

'#endif /* WINVER >= 0x0400 */

%OUT_DEFAULT_PRECIS        = 0?
%OUT_STRING_PRECIS         = 1?
%OUT_CHARACTER_PRECIS      = 2?
%OUT_STROKE_PRECIS         = 3?
%OUT_TT_PRECIS             = 4?
%OUT_DEVICE_PRECIS         = 5?
%OUT_RASTER_PRECIS         = 6?
%OUT_TT_ONLY_PRECIS        = 7?
%OUT_OUTLINE_PRECIS        = 8?
%OUT_SCREEN_OUTLINE_PRECIS = 9?
%OUT_PS_ONLY_PRECIS        = 10?

'#define CLIP_DEFAULT_PRECIS     0
'#define CLIP_CHARACTER_PRECIS   1
'#define CLIP_STROKE_PRECIS      2
'#define CLIP_MASK               0xf
'#define CLIP_LH_ANGLES          (1<<4)
'#define CLIP_TT_ALWAYS          (2<<4)
'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
'#define CLIP_DFA_DISABLE        (4<<4)
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
'#define CLIP_EMBEDDED           (8<<4)

%CLIP_DEFAULT_PRECIS   = 0?
%CLIP_CHARACTER_PRECIS = 1?
%CLIP_STROKE_PRECIS    = 2?
%CLIP_MASK             = &HF?
%CLIP_LH_ANGLES        = &H10?   ' 16
%CLIP_TT_ALWAYS        = &H20?   ' 32
'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
%CLIP_DFA_DISABLE      = &H40?   ' 64
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
%CLIP_EMBEDDED         = &H80?   ' 128

%DEFAULT_QUALITY        = 0?
%DRAFT_QUALITY          = 1?
%PROOF_QUALITY          = 2?
'#if(WINVER >= 0x0400)
%NONANTIALIASED_QUALITY = 3?
%ANTIALIASED_QUALITY    = 4?
'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= _WIN32_WINNT_WINXP)
%CLEARTYPE_QUALITY      = 5?
%CLEARTYPE_NATURAL_QUALITY = 6?
'#endif

%DEFAULT_PITCH   = 0?
%FIXED_PITCH     = 1?
%VARIABLE_PITCH  = 2?
'#if(WINVER >= 0x0400)
%MONO_FONT       = 8?
'#endif /* WINVER >= 0x0400 */

%ANSI_CHARSET        = 0?
%DEFAULT_CHARSET     = 1?
%SYMBOL_CHARSET      = 2?
%SHIFTJIS_CHARSET    = 128?
%HANGEUL_CHARSET     = 129?
%HANGUL_CHARSET      = 129?
%GB2312_CHARSET      = 134?
%CHINESEBIG5_CHARSET = 136?
%OEM_CHARSET         = 255?
'#if(WINVER >= 0x0400)
%JOHAB_CHARSET       = 130?
%HEBREW_CHARSET      = 177?
%ARABIC_CHARSET      = 178?
%GREEK_CHARSET       = 161?
%TURKISH_CHARSET     = 162?
%VIETNAMESE_CHARSET  = 163?
%THAI_CHARSET        = 222?
%EASTEUROPE_CHARSET  = 238?
%RUSSIAN_CHARSET     = 204?

%MAC_CHARSET         = 77?
%BALTIC_CHARSET      = 186?

%FS_LATIN1      = &H00000001???
%FS_LATIN2      = &H00000002???
%FS_CYRILLIC    = &H00000004???
%FS_GREEK       = &H00000008???
%FS_TURKISH     = &H00000010???
%FS_HEBREW      = &H00000020???
%FS_ARABIC      = &H00000040???
%FS_BALTIC      = &H00000080???
%FS_VIETNAMESE  = &H00000100???
%FS_THAI        = &H00010000???
%FS_JISJAPAN    = &H00020000???
%FS_CHINESESIMP = &H00040000???
%FS_WANSUNG     = &H00080000???
%FS_CHINESETRAD = &H00100000???
%FS_JOHAB       = &H00200000???
%FS_SYMBOL      = &H80000000???
'#endif /* WINVER >= 0x0400 */

'/* Font Families */
'#define FF_DONTCARE         (0<<4)  /* Don't care or don't know. */
'#define FF_ROMAN            (1<<4)  /* Variable stroke width, serifed. */
'                                    /* Times Roman, Century Schoolbook, etc. */
'#define FF_SWISS            (2<<4)  /* Variable stroke width, sans-serifed. */
'                                    /* Helvetica, Swiss, etc. */
'#define FF_MODERN           (3<<4)  /* Constant stroke width, serifed or sans-serifed. */
'                                    /* Pica, Elite, Courier, etc. */
'#define FF_SCRIPT           (4<<4)  /* Cursive, etc. */
'#define FF_DECORATIVE       (5<<4)  /* Old English, etc. */

%FF_DONTCARE   = 0?    ' Don't care or don't know.
%FF_ROMAN      = 16?   ' Variable stroke width, serifed.
%FF_SWISS      = 32?   ' Variable stroke width, sans-serifed.
%FF_MODERN     = 48?   ' Constant stroke width, serifed or sans-serifed.
%FF_SCRIPT     = 64?   ' Cursive, etc.
%FF_DECORATIVE = 80?   ' Old English, etc.

'/* Font Weights */
%FW_DONTCARE   = 0&
%FW_THIN       = 100&
%FW_EXTRALIGHT = 200&
%FW_LIGHT      = 300&
%FW_NORMAL     = 400&
%FW_MEDIUM     = 500&
%FW_SEMIBOLD   = 600&
%FW_BOLD       = 700&
%FW_EXTRABOLD  = 800&
%FW_HEAVY      = 900&

%FW_ULTRALIGHT = %FW_EXTRALIGHT
%FW_REGULAR    = %FW_NORMAL
%FW_DEMIBOLD   = %FW_SEMIBOLD
%FW_ULTRABOLD  = %FW_EXTRABOLD
%FW_BLACK      = %FW_HEAVY

%PANOSE_COUNT               = 10
%PAN_FAMILYTYPE_INDEX       = 0
%PAN_SERIFSTYLE_INDEX       = 1
%PAN_WEIGHT_INDEX           = 2
%PAN_PROPORTION_INDEX       = 3
%PAN_CONTRAST_INDEX         = 4
%PAN_STROKEVARIATION_INDEX  = 5
%PAN_ARMSTYLE_INDEX         = 6
%PAN_LETTERFORM_INDEX       = 7
%PAN_MIDLINE_INDEX          = 8
%PAN_XHEIGHT_INDEX          = 9

%PAN_CULTURE_LATIN          = 0

' // Size = 10 bytes
TYPE PANOSE BYTE
   bFamilyType      AS BYTE
   bSerifStyle      AS BYTE
   bWeight          AS BYTE
   bProportion      AS BYTE
   bContrast        AS BYTE
   bStrokeVariation AS BYTE
   bArmStyle        AS BYTE
   bLetterform      AS BYTE
   bMidline         AS BYTE
   bXHeight         AS BYTE
END TYPE

%PAN_ANY                     = 0  ' Any
%PAN_NO_FIT                  = 1  ' No Fit

%PAN_FAMILY_TEXT_DISPLAY     = 2  ' Text and Display
%PAN_FAMILY_SCRIPT           = 3  ' Script
%PAN_FAMILY_DECORATIVE       = 4  ' Decorative
%PAN_FAMILY_PICTORIAL        = 5  ' Pictorial

%PAN_SERIF_COVE              = 2  ' Cove
%PAN_SERIF_OBTUSE_COVE       = 3  ' Obtuse Cove
%PAN_SERIF_SQUARE_COVE       = 4  ' Square Cove
%PAN_SERIF_OBTUSE_SQUARE_COVE= 5  ' Obtuse Square Cove
%PAN_SERIF_SQUARE            = 6  ' Square
%PAN_SERIF_THIN              = 7  ' Thin
%PAN_SERIF_BONE              = 8  ' Bone
%PAN_SERIF_EXAGGERATED       = 9  ' Exaggerated
%PAN_SERIF_TRIANGLE          = 10 ' Triangle
%PAN_SERIF_NORMAL_SANS       = 11 ' Normal Sans
%PAN_SERIF_OBTUSE_SANS       = 12 ' Obtuse Sans
%PAN_SERIF_PERP_SANS         = 13 ' Prep Sans
%PAN_SERIF_FLARED            = 14 ' Flared
%PAN_SERIF_ROUNDED           = 15 ' Rounded

%PAN_WEIGHT_VERY_LIGHT       = 2  ' Very Light
%PAN_WEIGHT_LIGHT            = 3  ' Light
%PAN_WEIGHT_THIN             = 4  ' Thin
%PAN_WEIGHT_BOOK             = 5  ' Book
%PAN_WEIGHT_MEDIUM           = 6  ' Medium
%PAN_WEIGHT_DEMI             = 7  ' Demi
%PAN_WEIGHT_BOLD             = 8  ' Bold
%PAN_WEIGHT_HEAVY            = 9  ' Heavy
%PAN_WEIGHT_BLACK            = 10 ' Black
%PAN_WEIGHT_NORD             = 11 ' Nord

%PAN_PROP_OLD_STYLE          = 2  ' Old Style
%PAN_PROP_MODERN             = 3  ' Modern
%PAN_PROP_EVEN_WIDTH         = 4  ' Even Width
%PAN_PROP_EXPANDED           = 5  ' Expanded
%PAN_PROP_CONDENSED          = 6  ' Condensed
%PAN_PROP_VERY_EXPANDED      = 7  ' Very Expanded
%PAN_PROP_VERY_CONDENSED     = 8  ' Very Condensed
%PAN_PROP_MONOSPACED         = 9  ' Monospaced

%PAN_CONTRAST_NONE           = 2  ' None
%PAN_CONTRAST_VERY_LOW       = 3  ' Very Low
%PAN_CONTRAST_LOW            = 4  ' Low
%PAN_CONTRAST_MEDIUM_LOW     = 5  ' Medium Low
%PAN_CONTRAST_MEDIUM         = 6  ' Medium
%PAN_CONTRAST_MEDIUM_HIGH    = 7  ' Mediim High
%PAN_CONTRAST_HIGH           = 8  ' High
%PAN_CONTRAST_VERY_HIGH      = 9  ' Very High

%PAN_STROKE_GRADUAL_DIAG     = 2  ' Gradual/Diagonal
%PAN_STROKE_GRADUAL_TRAN     = 3  ' Gradual/Transitional
%PAN_STROKE_GRADUAL_VERT     = 4  ' Gradual/Vertical
%PAN_STROKE_GRADUAL_HORZ     = 5  ' Gradual/Horizontal
%PAN_STROKE_RAPID_VERT       = 6  ' Rapid/Vertical
%PAN_STROKE_RAPID_HORZ       = 7  ' Rapid/Horizontal
%PAN_STROKE_INSTANT_VERT     = 8  ' Instant/Vertical

%PAN_STRAIGHT_ARMS_HORZ          = 2  ' Straight Arms/Horizontal
%PAN_STRAIGHT_ARMS_WEDGE         = 3  ' Straight Arms/Wedge
%PAN_STRAIGHT_ARMS_VERT          = 4  ' Straight Arms/Vertical
%PAN_STRAIGHT_ARMS_SINGLE_SERIF  = 5  ' Straight Arms/Single-Serif
%PAN_STRAIGHT_ARMS_DOUBLE_SERIF  = 6  ' Straight Arms/Double-Serif
%PAN_BENT_ARMS_HORZ              = 7  ' Non-Straight Arms/Horizontal
%PAN_BENT_ARMS_WEDGE             = 8  ' Non-Straight Arms/Wedge
%PAN_BENT_ARMS_VERT              = 9  ' Non-Straight Arms/Vertical
%PAN_BENT_ARMS_SINGLE_SERIF      = 10 ' Non-Straight Arms/Single-Serif
%PAN_BENT_ARMS_DOUBLE_SERIF      = 11 ' Non-Straight Arms/Double-Serif

%PAN_LETT_NORMAL_CONTACT     = 2  ' Normal/Contact
%PAN_LETT_NORMAL_WEIGHTED    = 3  ' Normal/Weighted
%PAN_LETT_NORMAL_BOXED       = 4  ' Normal/Boxed
%PAN_LETT_NORMAL_FLATTENED   = 5  ' Normal/Flattened
%PAN_LETT_NORMAL_ROUNDED     = 6  ' Normal/Rounded
%PAN_LETT_NORMAL_OFF_CENTER  = 7  ' Normal/Off Center
%PAN_LETT_NORMAL_SQUARE      = 8  ' Normal/Square
%PAN_LETT_OBLIQUE_CONTACT    = 9  ' Oblique/Contact
%PAN_LETT_OBLIQUE_WEIGHTED   = 10 ' Oblique/Weighted
%PAN_LETT_OBLIQUE_BOXED      = 11 ' Oblique/Boxed
%PAN_LETT_OBLIQUE_FLATTENED  = 12 ' Oblique/Flattened
%PAN_LETT_OBLIQUE_ROUNDED    = 13 ' Oblique/Rounded
%PAN_LETT_OBLIQUE_OFF_CENTER = 14 ' Oblique/Off Center
%PAN_LETT_OBLIQUE_SQUARE     = 15 ' Oblique/Square

%PAN_MIDLINE_STANDARD_TRIMMED = 2  ' Standard/Trimmed
%PAN_MIDLINE_STANDARD_POINTED = 3  ' Standard/Pointed
%PAN_MIDLINE_STANDARD_SERIFED = 4  ' Standard/Serifed
%PAN_MIDLINE_HIGH_TRIMMED     = 5  ' High/Trimmed
%PAN_MIDLINE_HIGH_POINTED     = 6  ' High/Pointed
%PAN_MIDLINE_HIGH_SERIFED     = 7  ' High/Serifed
%PAN_MIDLINE_CONSTANT_TRIMMED = 8  ' Constant/Trimmed
%PAN_MIDLINE_CONSTANT_POINTED = 9  ' Constant/Pointed
%PAN_MIDLINE_CONSTANT_SERIFED = 10 ' Constant/Serifed
%PAN_MIDLINE_LOW_TRIMMED      = 11 ' Low/Trimmed
%PAN_MIDLINE_LOW_POINTED      = 12 ' Low/Pointed
%PAN_MIDLINE_LOW_SERIFED      = 13 ' Low/Serifed

%PAN_XHEIGHT_CONSTANT_SMALL  = 2  ' Constant/Small
%PAN_XHEIGHT_CONSTANT_STD    = 3  ' Constant/Standard
%PAN_XHEIGHT_CONSTANT_LARGE  = 4  ' Constant/Large
%PAN_XHEIGHT_DUCKING_SMALL   = 5  ' Ducking/Small
%PAN_XHEIGHT_DUCKING_STD     = 6  ' Ducking/Standard
%PAN_XHEIGHT_DUCKING_LARGE   = 7  ' Ducking/Large

%ELF_VENDOR_SIZE   = 4

'/* The extended logical font       */
'/* An extension of the ENUMLOGFONT */

' // Size = 192 bytes
TYPE EXTLOGFONTA DWORD
   elfLogFont   AS LOGFONTA
   elfFullName  AS ASCIIZ * %LF_FULLFACESIZE   ' BYTE [must be char]
   elfStyle     AS ASCIIZ * %LF_FACESIZE       ' BYTE [must be char]
   elfVersion   AS DWORD   ' DWORD /* 0 for the first release of NT */
   elfStyleSize AS DWORD   ' DWORD
   elfMatch     AS DWORD   ' DWORD
   elfReserved  AS DWORD   ' DWORD
   elfVendorId  AS STRING * %ELF_VENDOR_SIZE   ' BYTE
   elfCulture   AS DWORD   ' DWORD /* 0 for Latin                   */
   elfPanose    AS PANOSE
END TYPE

' // Size = 320 bytes
TYPE EXTLOGFONTW DWORD
   elfLogFont   AS LOGFONTW
   elfFullName  AS WSTRINGZ * %LF_FULLFACESIZE   ' WCHAR
   elfStyle     AS WSTRINGZ * %LF_FACESIZE       ' WCHAR
   elfVersion   AS DWORD   ' DWORD /* 0 for the first release of NT */
   elfStyleSize AS DWORD   ' DWORD
   elfMatch     AS DWORD   ' DWORD
   elfReserved  AS DWORD   ' DWORD
   elfVendorId  AS STRING * %ELF_VENDOR_SIZE     ' BYTE
   elfCulture   AS DWORD   ' DWORD /* 0 for Latin                   */
   elfPanose    AS PANOSE
END TYPE

#IF %DEF(%UNICODE)
   MACRO EXTLOGFONT = EXTLOGFONTW
#ELSE
   MACRO EXTLOGFONT = EXTLOGFONTA
#ENDIF

%ELF_VERSION       = 0
%ELF_CULTURE_LATIN = 0

'/* EnumFonts Masks */
%RASTER_FONTTYPE   = &H0001???
%DEVICE_FONTTYPE   = &H0002???
%TRUETYPE_FONTTYPE = &H0004???

'#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
'#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))
'#define PALETTEINDEX(i)     ((COLORREF)(0x01000000 | (DWORD)(WORD)(i)))

'MACRO PALETTERGB(r,g,b) = (&H02000000 OR RGB(r,g,b))
'MACRO PALETTEINDEX(i) = (&H01000000 OR CDWD(i))
FUNCTION PALETTERGB (BYVAL bRed AS BYTE, BYVAL bGreen AS BYTE, BYVAL bBlue AS BYTE) AS DWORD
   FUNCTION = (&H02000000??? OR RGB(bRed, bGreen, bBlue))
END FUNCTION

' // Not a macro because it conflicts with the PaletteIndex member of the COLORKEY struture.
FUNCTION PALETTEINDEX (BYVAL ix AS WORD) AS DWORD
   FUNCTION = (&H01000000??? OR CDWD(ix))
END FUNCTION

'/* palette entry flags */

%PC_RESERVED   = &H01?  ' palette index used for animation
%PC_EXPLICIT   = &H02?  ' palette index is explicit to device
%PC_NOCOLLAPSE = &H04?  ' do not match color to system palette

'#define GetRValue(rgb)      (LOBYTE(rgb))
'#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
'#define GetBValue(rgb)      (LOBYTE((rgb)>>16))

'MACRO GetRValue(nRGB) = LO(BYTE, nRGB)
'MACRO GetGValue(nRGB) = LO(BYTE, nRGB \ 256)
'MACRO GetBValue(nRGB) = LO(BYTE, nRGB \ 65536)

' // There is a bug in the LO(BYTE) function in PBWIN 10.
FUNCTION GetRValue(BYVAL clrRGB AS DWORD) AS BYTE
   FUNCTION = (clrRGB AND &H000000FF???)
END FUNCTION

FUNCTION GetGValue(BYVAL clrRGB AS DWORD) AS BYTE
   SHIFT RIGHT clrRGB, 8
   FUNCTION = (clrRGB AND &H000000FF???)
END FUNCTION

FUNCTION GetBValue(BYVAL clrRGB AS DWORD) AS BYTE
   SHIFT RIGHT clrRGB, 16
   FUNCTION = (clrRGB AND &H000000FF???)
END FUNCTION

'/* Background Modes */
%TRANSPARENT = 1
%OPAQUE      = 2
%BKMODE_LAST = 2

'/* Graphics Modes */
%GM_COMPATIBLE = 1
%GM_ADVANCED   = 2
%GM_LAST       = 2

'/* PolyDraw and GetPath point types */
%PT_CLOSEFIGURE = &H01?
%PT_LINETO      = &H02?
%PT_BEZIERTO    = &H04?
%PT_MOVETO      = &H06?

'/* Mapping Modes */
%MM_TEXT         = 1
%MM_LOMETRIC     = 2
%MM_HIMETRIC     = 3
%MM_LOENGLISH    = 4
%MM_HIENGLISH    = 5
%MM_TWIPS        = 6
%MM_ISOTROPIC    = 7
%MM_ANISOTROPIC  = 8

'/* Min and Max Mapping Mode values */
%MM_MIN            = %MM_TEXT
%MM_MAX            = %MM_ANISOTROPIC
%MM_MAX_FIXEDSCALE = %MM_TWIPS

'/* Coordinate Modes */
%ABSOLUTE = 1
%RELATIVE = 2

'/* Stock Logical Objects */
%WHITE_BRUSH         = 0
%LTGRAY_BRUSH        = 1
%GRAY_BRUSH          = 2
%DKGRAY_BRUSH        = 3
%BLACK_BRUSH         = 4
%NULL_BRUSH          = 5
%HOLLOW_BRUSH        = %NULL_BRUSH
%WHITE_PEN           = 6
%BLACK_PEN           = 7
%NULL_PEN            = 8
%OEM_FIXED_FONT      = 10
%ANSI_FIXED_FONT     = 11
%ANSI_VAR_FONT       = 12
%SYSTEM_FONT         = 13
%DEVICE_DEFAULT_FONT = 14
%DEFAULT_PALETTE     = 15
%SYSTEM_FIXED_FONT   = 16

'#if(WINVER >= 0x0400)
%DEFAULT_GUI_FONT    = 17
'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0500)
%DC_BRUSH            = 18
%DC_PEN              = 19
'#endif

'#if (_WIN32_WINNT >= 0x0500)
'#define STOCK_LAST          19
%STOCK_LAST          = 19  ' depending on Windows version, may be 16, 17 or 19
'#elif (WINVER >= 0x0400)
'#define STOCK_LAST          17
'#else
'#define STOCK_LAST          16
'#endif

%CLR_INVALID         = &HFFFFFFFF???  ' some Microsoft docs claim this is &HFFFF, but it's not

'/* Brush Styles */
%BS_SOLID            = 0
%BS_NULL             = 1
%BS_HOLLOW           = %BS_NULL
%BS_HATCHED          = 2
%BS_PATTERN          = 3
%BS_INDEXED          = 4
%BS_DIBPATTERN       = 5
%BS_DIBPATTERNPT     = 6
%BS_PATTERN8X8       = 7
%BS_DIBPATTERN8X8    = 8
%BS_MONOPATTERN      = 9

'/* Hatch Styles */
%HS_HORIZONTAL       = 0     ' -----
%HS_VERTICAL         = 1     ' |||||
%HS_FDIAGONAL        = 2     ' \\\\\
%HS_BDIAGONAL        = 3     ' -----
%HS_CROSS            = 4     ' +++++
%HS_DIAGCROSS        = 5     ' xxxxx
%HS_API_MAX          = 12

'/* Pen Styles */
%PS_SOLID            = 0
%PS_DASH             = 1     ' -------
%PS_DOT              = 2     ' .......
%PS_DASHDOT          = 3     ' _._._._
%PS_DASHDOTDOT       = 4     ' _.._.._
%PS_NULL             = 5
%PS_INSIDEFRAME      = 6
%PS_USERSTYLE        = 7
%PS_ALTERNATE        = 8
%PS_STYLE_MASK       = &H0000000F???

%PS_ENDCAP_ROUND     = &H00000000???
%PS_ENDCAP_SQUARE    = &H00000100???
%PS_ENDCAP_FLAT      = &H00000200???
%PS_ENDCAP_MASK      = &H00000F00???

%PS_JOIN_ROUND       = &H00000000???
%PS_JOIN_BEVEL       = &H00001000???
%PS_JOIN_MITER       = &H00002000???
%PS_JOIN_MASK        = &H0000F000???

%PS_COSMETIC         = &H00000000???
%PS_GEOMETRIC        = &H00010000???
%PS_TYPE_MASK        = &H000F0000???

%AD_COUNTERCLOCKWISE = 1
%AD_CLOCKWISE        = 2

'/* Device Parameters for GetDeviceCaps() */
%DRIVERVERSION  = 0    ' Device driver version
%TECHNOLOGY     = 2    ' Device classification
%HORZSIZE       = 4    ' Horizontal size in millimeters
%VERTSIZE       = 6    ' Vertical size in millimeters
%HORZRES        = 8    ' Horizontal width in pixels
%VERTRES        = 10   ' Vertical width in pixels
%BITSPIXEL      = 12   ' Number of bits per pixel
%PLANES         = 14   ' Number of planes
%NUMBRUSHES     = 16   ' Number of brushes the device has
%NUMPENS        = 18   ' Number of pens the device has
%NUMMARKERS     = 20   ' Number of markers the device has
%NUMFONTS       = 22   ' Number of fonts the device has
%NUMCOLORS      = 24   ' Number of colors the device supports
%PDEVICESIZE    = 26   ' Size required for device descriptor
%CURVECAPS      = 28   ' Curve capabilities
%LINECAPS       = 30   ' Line capabilities
%POLYGONALCAPS  = 32   ' Polygonal capabilities
%TEXTCAPS       = 34   ' Text capabilities
%CLIPCAPS       = 36   ' Clipping capabilities
%RASTERCAPS     = 38   ' Bitblt capabilities
%ASPECTX        = 40   ' Length of the X leg
%ASPECTY        = 42   ' Length of the Y leg
%ASPECTXY       = 44   ' Length of the hypotenuse

%LOGPIXELSX     = 88   ' Logical pixels/inch in X
%LOGPIXELSY     = 90   ' Logical pixels/inch in Y

%SIZEPALETTE    = 104  ' Number of entries in physical palette
%NUMRESERVED    = 106  ' Number of reserved entries in palette
%COLORRES       = 108  ' Actual color resolution

'// Printing related DeviceCaps. These replace the appropriate Escapes

%PHYSICALWIDTH   = 110  ' Physical Width in device units
%PHYSICALHEIGHT  = 111  ' Physical Height in device units
%PHYSICALOFFSETX = 112  ' Physical Printable Area x margin
%PHYSICALOFFSETY = 113  ' Physical Printable Area y margin
%SCALINGFACTORX  = 114  ' Scaling factor x
%SCALINGFACTORY  = 115  ' Scaling factor y

'// Display driver specific

%VREFRESH       = 116  ' Current vertical refresh rate of the
                       ' display device (for displays only) in Hz
%DESKTOPVERTRES = 117  ' Horizontal width of entire desktop in pixels
%DESKTOPHORZRES = 118  ' Vertical height of entire desktop in pixels
%BLTALIGNMENT   = 119  ' Preferred blt alignment

'#if(WINVER >= 0x0500)
%SHADEBLENDCAPS = 120   ' Shading and blending caps
%COLORMGMTCAPS  = 121   ' Color Management caps
'#endif /* WINVER >= 0x0500 */

#IF NOT %DEF(%NOGDICAPMASKS) ' ------------------------------------------------
'#ifndef NOGDICAPMASKS

'/* Device Capability Masks: */

'/* Device Technologies */
%DT_PLOTTER    = 0     ' Vector plotter
%DT_RASDISPLAY = 1     ' Raster display
%DT_RASPRINTER = 2     ' Raster printer
%DT_RASCAMERA  = 3     ' Raster camera
%DT_CHARSTREAM = 4     ' Character-stream, PLP
%DT_METAFILE   = 5     ' Metafile, VDM
%DT_DISPFILE   = 6     ' Display-file

'/* Curve Capabilities */
%CC_NONE       = 0     ' Curves not supported
%CC_CIRCLES    = 1     ' Can do circles
%CC_PIE        = 2     ' Can do pie wedges
%CC_CHORD      = 4     ' Can do chord arcs
%CC_ELLIPSES   = 8     ' Can do ellipese
%CC_WIDE       = 16    ' Can do wide lines
%CC_STYLED     = 32    ' Can do styled lines
%CC_WIDESTYLED = 64    ' Can do wide styled lines
%CC_INTERIORS  = 128   ' Can do interiors
%CC_ROUNDRECT  = 256   '

'/* Line Capabilities */
%LC_NONE       = 0     ' Lines not supported
%LC_POLYLINE   = 2     ' Can do polylines
%LC_MARKER     = 4     ' Can do markers
%LC_POLYMARKER = 8     ' Can do polymarkers
%LC_WIDE       = 16    ' Can do wide lines
%LC_STYLED     = 32    ' Can do styled lines
%LC_WIDESTYLED = 64    ' Can do wide styled lines
%LC_INTERIORS  = 128   ' Can do interiors

'/* Polygonal Capabilities */
%PC_NONE         = 0     ' Polygonals not supported
%PC_POLYGON      = 1     ' Can do polygons
%PC_RECTANGLE    = 2     ' Can do rectangles
%PC_WINDPOLYGON  = 4     ' Can do winding polygons
%PC_TRAPEZOID    = 4     ' Can do trapezoids
%PC_SCANLINE     = 8     ' Can do scanlines
%PC_WIDE         = 16    ' Can do wide borders
%PC_STYLED       = 32    ' Can do styled borders
%PC_WIDESTYLED   = 64    ' Can do wide styled borders
%PC_INTERIORS    = 128   ' Can do interiors
%PC_POLYPOLYGON  = 256   ' Can do polypolygons
%PC_PATHS        = 512   ' Can do paths

'/* Clipping Capabilities */
%CP_NONE         = 0     ' No clipping of output
%CP_RECTANGLE    = 1     ' Output clipped to rects
%CP_REGION       = 2     ' obsolete

'/* Text Capabilities */
%TC_OP_CHARACTER = &H00000001&  ' Can do OutputPrecision   CHARACTER
%TC_OP_STROKE    = &H00000002&  ' Can do OutputPrecision   STROKE
%TC_CP_STROKE    = &H00000004&  ' Can do ClipPrecision     STROKE
%TC_CR_90        = &H00000008&  ' Can do CharRotAbility    90
%TC_CR_ANY       = &H00000010&  ' Can do CharRotAbility    ANY
%TC_SF_X_YINDEP  = &H00000020&  ' Can do ScaleFreedom      X_YINDEPENDENT
%TC_SA_DOUBLE    = &H00000040&  ' Can do ScaleAbility      DOUBLE
%TC_SA_INTEGER   = &H00000080&  ' Can do ScaleAbility      INTEGER
%TC_SA_CONTIN    = &H00000100&  ' Can do ScaleAbility      CONTINUOUS
%TC_EA_DOUBLE    = &H00000200&  ' Can do EmboldenAbility   DOUBLE
%TC_IA_ABLE      = &H00000400&  ' Can do ItalisizeAbility  ABLE
%TC_UA_ABLE      = &H00000800&  ' Can do UnderlineAbility  ABLE
%TC_SO_ABLE      = &H00001000&  ' Can do StrikeOutAbility  ABLE
%TC_RA_ABLE      = &H00002000&  ' Can do RasterFontAble    ABLE
%TC_VA_ABLE      = &H00004000&  ' Can do VectorFontAble    ABLE
%TC_RESERVED     = &H00008000&
%TC_SCROLLBLT    = &H00010000&  ' Don't do text scroll with blt

'#endif /* NOGDICAPMASKS */
#ENDIF   ' #IF NOT %DEF(%NOGDICAPMASKS) ---------------------------------------

'/* Raster Capabilities */
%RC_NONE         = 0&
%RC_BITBLT       = 1&           ' Can do standard BLT.
%RC_BANDING      = 2&           ' Device requires banding support
%RC_SCALING      = 4&           ' Device requires scaling support
%RC_BITMAP64     = 8&           ' Device can support >64K bitmap
%RC_GDI20_OUTPUT = &H00000010&  ' has 2.0 output calls
%RC_GDI20_STATE  = &H00000020&
%RC_SAVEBITMAP   = &H00000040&
%RC_DI_BITMAP    = &H00000080&  ' supports DIB to memory
%RC_PALETTE      = &H00000100&  ' supports a palette
%RC_DIBTODEV     = &H00000200&  ' supports DIBitsToDevice
%RC_BIGFONT      = &H00000400&  ' supports >64K fonts
%RC_STRETCHBLT   = &H00000800&  ' supports StretchBlt
%RC_FLOODFILL    = &H00001000&  ' supports FloodFill
%RC_STRETCHDIB   = &H00002000&  ' supports StretchDIBits
%RC_OP_DX_OUTPUT = &H00004000&
%RC_DEVBITS      = &H00008000&

'#if(WINVER >= 0x0500)

'/* Shading and blending caps */
%SB_NONE          = &H00000000&
%SB_CONST_ALPHA   = &H00000001&
%SB_PIXEL_ALPHA   = &H00000002&
%SB_PREMULT_ALPHA = &H00000004&

%SB_GRAD_RECT     = &H00000010&
%SB_GRAD_TRI      = &H00000020&

'/* Color Management caps */
%CM_NONE          = &H00000000&
%CM_DEVICE_ICM    = &H00000001&
%CM_GAMMA_RAMP    = &H00000002&
%CM_CMYK_COLOR    = &H00000004&

'#endif /* WINVER >= 0x0500 */


'/* DIB color table identifiers */

%DIB_RGB_COLORS      = 0 ' color table in RGBs
%DIB_PAL_COLORS      = 1 ' color table in palette indices

'/* constants for Get/SetSystemPaletteUse() */

%SYSPAL_ERROR       = 0
%SYSPAL_STATIC      = 1
%SYSPAL_NOSTATIC    = 2
%SYSPAL_NOSTATIC256 = 3

'/* constants for CreateDIBitmap */
%CBM_INIT           = 4     ' initialize bitmap

'/* ExtFloodFill style flags */
%FLOODFILLBORDER    = 0
%FLOODFILLSURFACE   = 1

'/* size of a device name string */
'#define CCHDEVICENAME 32
%CCHDEVICENAME = 32

'/* size of a form name string */
'#define CCHFORMNAME 32
%CCHFORMNAME = 32

'typedef struct _devicemodeA {
'    BYTE   dmDeviceName[CCHDEVICENAME];
'    WORD dmSpecVersion;
'    WORD dmDriverVersion;
'    WORD dmSize;
'    WORD dmDriverExtra;
'    DWORD dmFields;
'    union {
'      /* printer only fields */
'      struct {
'        short dmOrientation;
'        short dmPaperSize;
'        short dmPaperLength;
'        short dmPaperWidth;
'        short dmScale;
'        short dmCopies;
'        short dmDefaultSource;
'        short dmPrintQuality;
'      } DUMMYSTRUCTNAME;
'      /* display only fields */
'      struct {
'        POINTL dmPosition;
'        DWORD  dmDisplayOrientation;
'        DWORD  dmDisplayFixedOutput;
'      } DUMMYSTRUCTNAME2;
'    } DUMMYUNIONNAME;
'    short dmColor;
'    short dmDuplex;
'    short dmYResolution;
'    short dmTTOption;
'    short dmCollate;
'    BYTE   dmFormName[CCHFORMNAME];
'    WORD   dmLogPixels;
'    DWORD  dmBitsPerPel;
'    DWORD  dmPelsWidth;
'    DWORD  dmPelsHeight;
'    union {
'        DWORD  dmDisplayFlags;
'        DWORD  dmNup;
'    } DUMMYUNIONNAME2;
'    DWORD  dmDisplayFrequency;
'#if(WINVER >= 0x0400)
'    DWORD  dmICMMethod;
'    DWORD  dmICMIntent;
'    DWORD  dmMediaType;
'    DWORD  dmDitherType;
'    DWORD  dmReserved1;
'    DWORD  dmReserved2;
'#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
'    DWORD  dmPanningWidth;
'    DWORD  dmPanningHeight;
'#endif
'#endif /* WINVER >= 0x0400 */
'} DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;

' // Size = 16 bytes
TYPE DEVMODE_UNION1_STRUCT_1 WORD
   dmOrientation   AS INTEGER   ' short dmOrientation
   dmPaperSize     AS INTEGER   ' short dmPaperSize
   dmPaperLength   AS INTEGER   ' short dmPaperLength
   dmPaperWidth    AS INTEGER   ' short dmPaperWidth
   dmScale         AS INTEGER   ' short dmScale
   dmCopies        AS INTEGER   ' short dmCopies
   dmDefaultSource AS INTEGER   ' short dmDefaultSource
   dmPrintQuality  AS INTEGER   ' short dmPrintQuality
END TYPE

' // Size = 16 bytes
TYPE DEVMODE_UNION1_STRUCT_2 DWORD
   dmPosition           AS POINTL   ' POINTL dmPosition
   dmDisplayOrientation AS DWORD    ' DWORD  dmDisplayOrientation
   dmDisplayFixedOutput AS DWORD    ' DWORD  dmDisplayFixedOutput
END TYPE

' // Size = 16 bytes
UNION DEVMODE_UNION_1 DWORD
   DEVMODE_UNION1_STRUCT_1
   DEVMODE_UNION1_STRUCT_2
END UNION

' // Size = 4 bytes
UNION DEVMODE_UNION_2 DWORD
   dmDisplayFlags AS DWORD   ' DWORD
   dmNup          AS DWORD   ' DWORD
END UNION

' // Size = 156 bytes
TYPE DEVMODEA DWORD FILL
   dmDeviceName       AS ASCIIZ * %CCHDEVICENAME   ' BYTE dmDeviceName[CCHDEVICENAME]
   dmSpecVersion      AS WORD                      ' WORD dmSpecVersion
   dmDriverVersion    AS WORD                      ' WORD dmDriverVersion
   dmSize             AS WORD                      ' WORD dmSize
   dmDriverExtra      AS WORD                      ' WORD dmDriverExtra
   dmFields           AS DWORD                     ' DWORD dmFields
   DEVMODE_UNION_1
   dmColor            AS INTEGER                   ' short
   dmDuplex           AS INTEGER                   ' short
   dmYResolution      AS INTEGER                   ' short
   dmTTOption         AS INTEGER                   ' short
   dmCollate          AS INTEGER                   ' short
   dmFormName         AS ASCIIZ * %CCHFORMNAME     ' BYTE dmFormName[CCHFORMNAME]
   dmLogPixels        AS WORD                      ' WORD   dmLogPixels
   dmBitsPerPel       AS DWORD                     ' DWORD  dmBitsPerPel
   dmPelsWidth        AS DWORD                     ' DWORD  dmPelsWidth
   dmPelsHeight       AS DWORD                     ' DWORD  dmPelsHeight
   DEVMODE_UNION_2
   dmDisplayFrequency AS DWORD                     ' DWORD  dmDisplayFrequency
#IF (%WINVER >= &H0400)
   dmICMMethod        AS DWORD                     ' DWORD  dmICMMethod
   dmICMIntent        AS DWORD                     ' DWORD  dmICMIntent
   dmMediaType        AS DWORD                     ' DWORD  dmMediaType
   dmDitherType       AS DWORD                     ' DWORD  dmDitherType
   dmReserved1        AS DWORD                     ' DWORD  dmReserved1
   dmReserved2        AS DWORD                     ' DWORD  dmReserved2
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
   dmPanningWidth     AS DWORD                     ' DWORD  dmPanningWidth
   dmPanningHeight    AS DWORD                     ' DWORD  dmPanningHeight
#ENDIF
#ENDIF ' WINVER >= &H0400
END TYPE

'typedef struct _devicemodeW {
'    WCHAR  dmDeviceName[CCHDEVICENAME];
'    WORD dmSpecVersion;
'    WORD dmDriverVersion;
'    WORD dmSize;
'    WORD dmDriverExtra;
'    DWORD dmFields;
'    union {
'      /* printer only fields */
'      struct {
'        short dmOrientation;
'        short dmPaperSize;
'        short dmPaperLength;
'        short dmPaperWidth;
'        short dmScale;
'        short dmCopies;
'        short dmDefaultSource;
'        short dmPrintQuality;
'      } DUMMYSTRUCTNAME;
'      /* display only fields */
'      struct {
'        POINTL dmPosition;
'        DWORD  dmDisplayOrientation;
'        DWORD  dmDisplayFixedOutput;
'      } DUMMYSTRUCTNAME2;
'    } DUMMYUNIONNAME;
'    short dmColor;
'    short dmDuplex;
'    short dmYResolution;
'    short dmTTOption;
'    short dmCollate;
'    WCHAR  dmFormName[CCHFORMNAME];
'    WORD   dmLogPixels;
'    DWORD  dmBitsPerPel;
'    DWORD  dmPelsWidth;
'    DWORD  dmPelsHeight;
'    union {
'        DWORD  dmDisplayFlags;
'        DWORD  dmNup;
'    } DUMMYUNIONNAME2;
'    DWORD  dmDisplayFrequency;
'#if(WINVER >= 0x0400)
'    DWORD  dmICMMethod;
'    DWORD  dmICMIntent;
'    DWORD  dmMediaType;
'    DWORD  dmDitherType;
'    DWORD  dmReserved1;
'    DWORD  dmReserved2;
'#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
'    DWORD  dmPanningWidth;
'    DWORD  dmPanningHeight;
'#endif

' // Size = 220 bytes
TYPE DEVMODEW DWORD FILL
   dmDeviceName       AS WSTRINGZ * %CCHDEVICENAME   ' WCHAR dmDeviceName[CCHDEVICENAME]
   dmSpecVersion      AS WORD                        ' WORD dmSpecVersion
   dmDriverVersion    AS WORD                        ' WORD dmDriverVersion
   dmSize             AS WORD                        ' WORD dmSize
   dmDriverExtra      AS WORD                        ' WORD dmDriverExtra
   dmFields           AS DWORD                       ' DWORD dmFields
   DEVMODE_UNION_1
   dmColor            AS INTEGER                     ' short dmColor
   dmDuplex           AS INTEGER                     ' short dmDuplex
   dmYResolution      AS INTEGER                     ' short dmYResolution
   dmTTOption         AS INTEGER                     ' short dmTTOption
   dmCollate          AS INTEGER                     ' short dmCollate
   dmFormName         AS WSTRINGZ * %CCHFORMNAME     ' WCHAR  dmFormName[CCHFORMNAME]
   dmLogPixels        AS WORD                        ' WORD   dmLogPixels
   dmBitsPerPel       AS DWORD                       ' DWORD  dmBitsPerPel
   dmPelsWidth        AS DWORD                       ' DWORD  dmPelsWidth
   dmPelsHeight       AS DWORD                       ' DWORD  dmPelsHeight
   DEVMODE_UNION_2
   dmDisplayFrequency AS DWORD                       ' DWORD  dmDisplayFrequency
   dmICMMethod        AS DWORD                       ' DWORD  dmICMMethod
#IF (%WINVER >= &H0400)
   dmICMIntent        AS DWORD                       ' DWORD  dmICMIntent
   dmMediaType        AS DWORD                       ' DWORD  dmMediaType
   dmDitherType       AS DWORD                       ' DWORD  dmDitherType
   dmReserved1        AS DWORD                       ' DWORD  dmReserved1
   dmReserved2        AS DWORD                       ' DWORD  dmReserved2
#IF (%WINVER >= &H0500) OR (%WIN32_WINNT >= %WIN32_WINNT_NT4)
   dmPanningWidth     AS DWORD                       ' DWORD  dmPanningWidth
   dmPanningHeight    AS DWORD                       ' DWORD  dmPanningHeight
#ENDIF
#ENDIF ' WINVER >= &H0400
END TYPE

#IF %DEF(%UNICODE)
   MACRO DEVMODE = DEVMODEW
#ELSE
   MACRO DEVMODE = DEVMODEA
#ENDIF

'#endif /* WINVER >= 0x0400 */

'/* current version of specification */
'#if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0400)
'#define DM_SPECVERSION 0x0401
%DM_SPECVERSION = &H0401
'#elif (WINVER >= 0x0400)
'#define DM_SPECVERSION 0x0400
'#else
'#define DM_SPECVERSION 0x0320
'#endif /* WINVER */

'/* field selection bits */
%DM_ORIENTATION        = &H00000001???
%DM_PAPERSIZE          = &H00000002???
%DM_PAPERLENGTH        = &H00000004???
%DM_PAPERWIDTH         = &H00000008???
%DM_SCALE              = &H00000010???
'#if(WINVER >= 0x0500)
%DM_POSITION           = &H00000020???
%DM_NUP                = &H00000040???
'#endif /* WINVER >= 0x0500 */
'#if(WINVER >= 0x0501)
%DM_DISPLAYORIENTATION = &H00000080???
'#endif /* WINVER >= 0x0501 */
%DM_COPIES             = &H00000100???
%DM_DEFAULTSOURCE      = &H00000200???
%DM_PRINTQUALITY       = &H00000400???
%DM_COLOR              = &H00000800???
%DM_DUPLEX             = &H00001000???
%DM_YRESOLUTION        = &H00002000???
%DM_TTOPTION           = &H00004000???
%DM_COLLATE            = &H00008000???
%DM_FORMNAME           = &H00010000???
%DM_LOGPIXELS          = &H00020000???
%DM_BITSPERPEL         = &H00040000???
%DM_PELSWIDTH          = &H00080000???
%DM_PELSHEIGHT         = &H00100000???
%DM_DISPLAYFLAGS       = &H00200000???
%DM_DISPLAYFREQUENCY   = &H00400000???
'#if(WINVER >= 0x0400)
%DM_ICMMETHOD          = &H00800000???  ' *** MSDN claims a different value here!
%DM_ICMINTENT          = &H01000000???  ' *** MSDN claims a different value here!
%DM_MEDIATYPE          = &H02000000???  ' *** MSDN claims a different value here!
%DM_DITHERTYPE         = &H04000000???  ' *** MSDN claims a different value here!
%DM_PANNINGWIDTH       = &H08000000???
%DM_PANNINGHEIGHT      = &H10000000???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0501)
%DM_DISPLAYFIXEDOUTPUT = &H20000000???
'#endif /* WINVER >= 0x0501 */

'/* orientation selections */
%DMORIENT_PORTRAIT  = 1
%DMORIENT_LANDSCAPE = 2

'/* paper selections */
%DMPAPER_LETTER              = 1
%DMPAPER_FIRST               = %DMPAPER_LETTER  ' Letter 8 1/2 x 11 in
%DMPAPER_LETTERSMALL         = 2    ' Letter Small 8 1/2 x 11 in
%DMPAPER_TABLOID             = 3    ' Tabloid 11 x 17 in
%DMPAPER_LEDGER              = 4    ' Ledger 17 x 11 in
%DMPAPER_LEGAL               = 5    ' Legal 8 1/2 x 14 in
%DMPAPER_STATEMENT           = 6    ' Statement 5 1/2 x 8 1/2 in
%DMPAPER_EXECUTIVE           = 7    ' Executive 7 1/4 x 10 1/2 in
%DMPAPER_A3                  = 8    ' A3 297 x 420 mm
%DMPAPER_A4                  = 9    ' A4 210 x 297 mm
%DMPAPER_A4SMALL             = 10   ' A4 Small 210 x 297 mm
%DMPAPER_A5                  = 11   ' A5 148 x 210 mm
%DMPAPER_B4                  = 12   ' B4 250 x 354
%DMPAPER_B5                  = 13   ' B5 182 x 257 mm
%DMPAPER_FOLIO               = 14   ' Folio 8 1/2 x 13 in
%DMPAPER_QUARTO              = 15   ' Quarto 215 x 275 mm
%DMPAPER_10X14               = 16   ' 1&H14 in
%DMPAPER_11X17               = 17   ' 11x17 in
%DMPAPER_NOTE                = 18   ' Note 8 1/2 x 11 in
%DMPAPER_ENV_9               = 19   ' Envelope #9 3 7/8 x 8 7/8
%DMPAPER_ENV_10              = 20   ' Envelope #10 4 1/8 x 9 1/2
%DMPAPER_ENV_11              = 21   ' Envelope #11 4 1/2 x 10 3/8
%DMPAPER_ENV_12              = 22   ' Envelope #12 4 \276 x 11
%DMPAPER_ENV_14              = 23   ' Envelope #14 5 x 11 1/2
%DMPAPER_CSHEET              = 24   ' C size sheet
%DMPAPER_DSHEET              = 25   ' D size sheet
%DMPAPER_ESHEET              = 26   ' E size sheet
%DMPAPER_ENV_DL              = 27   ' Envelope DL 110 x 220mm
%DMPAPER_ENV_C5              = 28   ' Envelope C5 162 x 229 mm
%DMPAPER_ENV_C3              = 29   ' Envelope C3  324 x 458 mm
%DMPAPER_ENV_C4              = 30   ' Envelope C4  229 x 324 mm
%DMPAPER_ENV_C6              = 31   ' Envelope C6  114 x 162 mm
%DMPAPER_ENV_C65             = 32   ' Envelope C65 114 x 229 mm
%DMPAPER_ENV_B4              = 33   ' Envelope B4  250 x 353 mm
%DMPAPER_ENV_B5              = 34   ' Envelope B5  176 x 250 mm
%DMPAPER_ENV_B6              = 35   ' Envelope B6  176 x 125 mm
%DMPAPER_ENV_ITALY           = 36   ' Envelope 110 x 230 mm
%DMPAPER_ENV_MONARCH         = 37   ' Envelope Monarch 3.875 x 7.5 in
%DMPAPER_ENV_PERSONAL        = 38   ' 6 3/4 Envelope 3 5/8 x 6 1/2 in
%DMPAPER_FANFOLD_US          = 39   ' US Std Fanfold 14 7/8 x 11 in
%DMPAPER_FANFOLD_STD_GERMAN  = 40   ' German Std Fanfold 8 1/2 x 12 in
%DMPAPER_FANFOLD_LGL_GERMAN  = 41   ' German Legal Fanfold 8 1/2 x 13 in
'#if(WINVER >= 0x0400)
%DMPAPER_ISO_B4              = 42   ' B4 (ISO) 250 x 353 mm
%DMPAPER_JAPANESE_POSTCARD   = 43   ' Japanese Postcard 100 x 148 mm
%DMPAPER_9X11                = 44   ' 9 x 11 in
%DMPAPER_10X11               = 45   ' 10 x 11 in
%DMPAPER_15X11               = 46   ' 15 x 11 in
%DMPAPER_ENV_INVITE          = 47   ' Envelope Invite 220 x 220 mm
%DMPAPER_RESERVED_48         = 48   ' RESERVED--DO NOT USE
%DMPAPER_RESERVED_49         = 49   ' RESERVED--DO NOT USE
%DMPAPER_LETTER_EXTRA        = 50   ' Letter Extra 9 \275 x 12 in
%DMPAPER_LEGAL_EXTRA         = 51   ' Legal Extra 9 \275 x 15 in
%DMPAPER_TABLOID_EXTRA       = 52   ' Tabloid Extra 11.69 x 18 in
%DMPAPER_A4_EXTRA            = 53   ' A4 Extra 9.27 x 12.69 in
%DMPAPER_LETTER_TRANSVERSE   = 54   ' Letter Transverse 8 \275 x 11 in
%DMPAPER_A4_TRANSVERSE       = 55   ' A4 Transverse 210 x 297 mm
%DMPAPER_LETTER_EXTRA_TRANSVERSE = 56 ' Letter Extra Transverse 9\275 x 12 in
%DMPAPER_A_PLUS              = 57   ' SuperA/SuperA/A4 227 x 356 mm
%DMPAPER_B_PLUS              = 58   ' SuperB/SuperB/A3 305 x 487 mm
%DMPAPER_LETTER_PLUS         = 59   ' Letter Plus 8.5 x 12.69 in
%DMPAPER_A4_PLUS             = 60   ' A4 Plus 210 x 330 mm
%DMPAPER_A5_TRANSVERSE       = 61   ' A5 Transverse 148 x 210 mm
%DMPAPER_B5_TRANSVERSE       = 62   ' B5 (JIS) Transverse 182 x 257 mm
%DMPAPER_A3_EXTRA            = 63   ' A3 Extra 322 x 445 mm
%DMPAPER_A5_EXTRA            = 64   ' A5 Extra 174 x 235 mm
%DMPAPER_B5_EXTRA            = 65   ' B5 (ISO) Extra 201 x 276 mm
%DMPAPER_A2                  = 66   ' A2 420 x 594 mm
%DMPAPER_A3_TRANSVERSE       = 67   ' A3 Transverse 297 x 420 mm
%DMPAPER_A3_EXTRA_TRANSVERSE = 68   ' A3 Extra Transverse 322 x 445 mm
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%DMPAPER_DBL_JAPANESE_POSTCARD = 69 ' Japanese Double Postcard 200 x 148 mm
%DMPAPER_A6                  = 70  ' A6 105 x 148 mm
%DMPAPER_JENV_KAKU2          = 71  ' Japanese Envelope Kaku #2
%DMPAPER_JENV_KAKU3          = 72  ' Japanese Envelope Kaku #3
%DMPAPER_JENV_CHOU3          = 73  ' Japanese Envelope Chou #3
%DMPAPER_JENV_CHOU4          = 74  ' Japanese Envelope Chou #4
%DMPAPER_LETTER_ROTATED      = 75  ' Letter Rotated 11 x 8 1/2 11 in
%DMPAPER_A3_ROTATED          = 76  ' A3 Rotated 420 x 297 mm
%DMPAPER_A4_ROTATED          = 77  ' A4 Rotated 297 x 210 mm
%DMPAPER_A5_ROTATED          = 78  ' A5 Rotated 210 x 148 mm
%DMPAPER_B4_JIS_ROTATED      = 79  ' B4 (JIS) Rotated 364 x 257 mm
%DMPAPER_B5_JIS_ROTATED      = 80  ' B5 (JIS) Rotated 257 x 182 mm
%DMPAPER_JAPANESE_POSTCARD_ROTATED = 81 ' Japanese Postcard Rotated 148 x 100 mm
%DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED = 82 ' Double Japanese Postcard Rotated 148 x 200 mm
%DMPAPER_A6_ROTATED          = 83  ' A6 Rotated 148 x 105 mm
%DMPAPER_JENV_KAKU2_ROTATED  = 84  ' Japanese Envelope Kaku #2 Rotated
%DMPAPER_JENV_KAKU3_ROTATED  = 85  ' Japanese Envelope Kaku #3 Rotated
%DMPAPER_JENV_CHOU3_ROTATED  = 86  ' Japanese Envelope Chou #3 Rotated
%DMPAPER_JENV_CHOU4_ROTATED  = 87  ' Japanese Envelope Chou #4 Rotated
%DMPAPER_B6_JIS              = 88  ' B6 (JIS) 128 x 182 mm
%DMPAPER_B6_JIS_ROTATED      = 89  ' B6 (JIS) Rotated 182 x 128 mm
%DMPAPER_12X11               = 90  ' 12 x 11 in
%DMPAPER_JENV_YOU4           = 91  ' Japanese Envelope You #4
%DMPAPER_JENV_YOU4_ROTATED   = 92  ' Japanese Envelope You #4 Rotated
%DMPAPER_P16K                = 93  ' PRC 16K 146 x 215 mm
%DMPAPER_P32K                = 94  ' PRC 32K 97 x 151 mm
%DMPAPER_P32KBIG             = 95  ' PRC 32K(Big) 97 x 151 mm
%DMPAPER_PENV_1              = 96  ' PRC Envelope #1 102 x 165 mm
%DMPAPER_PENV_2              = 97  ' PRC Envelope #2 102 x 176 mm
%DMPAPER_PENV_3              = 98  ' PRC Envelope #3 125 x 176 mm
%DMPAPER_PENV_4              = 99  ' PRC Envelope #4 110 x 208 mm
%DMPAPER_PENV_5              = 100 ' PRC Envelope #5 110 x 220 mm
%DMPAPER_PENV_6              = 101 ' PRC Envelope #6 120 x 230 mm
%DMPAPER_PENV_7              = 102 ' PRC Envelope #7 160 x 230 mm
%DMPAPER_PENV_8              = 103 ' PRC Envelope #8 120 x 309 mm
%DMPAPER_PENV_9              = 104 ' PRC Envelope #9 229 x 324 mm
%DMPAPER_PENV_10             = 105 ' PRC Envelope #10 324 x 458 mm
%DMPAPER_P16K_ROTATED        = 106 ' PRC 16K Rotated
%DMPAPER_P32K_ROTATED        = 107 ' PRC 32K Rotated
%DMPAPER_P32KBIG_ROTATED     = 108 ' PRC 32K(Big) Rotated
%DMPAPER_PENV_1_ROTATED      = 109 ' PRC Envelope #1 Rotated 165 x 102 mm
%DMPAPER_PENV_2_ROTATED      = 110 ' PRC Envelope #2 Rotated 176 x 102 mm
%DMPAPER_PENV_3_ROTATED      = 111 ' PRC Envelope #3 Rotated 176 x 125 mm
%DMPAPER_PENV_4_ROTATED      = 112 ' PRC Envelope #4 Rotated 208 x 110 mm
%DMPAPER_PENV_5_ROTATED      = 113 ' PRC Envelope #5 Rotated 220 x 110 mm
%DMPAPER_PENV_6_ROTATED      = 114 ' PRC Envelope #6 Rotated 230 x 120 mm
%DMPAPER_PENV_7_ROTATED      = 115 ' PRC Envelope #7 Rotated 230 x 160 mm
%DMPAPER_PENV_8_ROTATED      = 116 ' PRC Envelope #8 Rotated 309 x 120 mm
%DMPAPER_PENV_9_ROTATED      = 117 ' PRC Envelope #9 Rotated 324 x 229 mm
%DMPAPER_PENV_10_ROTATED     = 118 ' PRC Envelope #10 Rotated 458 x 324 mm
'#endif /* WINVER >= 0x0500 */

'#if (WINVER >= 0x0500)
'#define DMPAPER_LAST                DMPAPER_PENV_10_ROTATED
%DMPAPER_LAST = %DMPAPER_PENV_10_ROTATED
'#elif (WINVER >= 0x0400)
'#define DMPAPER_LAST                DMPAPER_A3_EXTRA_TRANSVERSE
'#else
'#define DMPAPER_LAST                DMPAPER_FANFOLD_LGL_GERMAN
'#endif

%DMPAPER_USER                = 256

'/* bin selections */
%DMBIN_UPPER         = 1
%DMBIN_FIRST         = %DMBIN_UPPER
%DMBIN_ONLYONE       = 1
%DMBIN_LOWER         = 2
%DMBIN_MIDDLE        = 3
%DMBIN_MANUAL        = 4
%DMBIN_ENVELOPE      = 5
%DMBIN_ENVMANUAL     = 6
%DMBIN_AUTO          = 7
%DMBIN_TRACTOR       = 8
%DMBIN_SMALLFMT      = 9
%DMBIN_LARGEFMT      = 10
%DMBIN_LARGECAPACITY = 11
%DMBIN_CASSETTE      = 14
%DMBIN_FORMSOURCE    = 15
%DMBIN_LAST          = %DMBIN_FORMSOURCE

%DMBIN_USER          = 256  ' device specific bins start here

'/* print qualities */
%DMRES_DRAFT  = -1
%DMRES_LOW    = -2
%DMRES_MEDIUM = -3
%DMRES_HIGH   = -4

'/* color enable/disable for color printers */
%DMCOLOR_MONOCHROME = 1
%DMCOLOR_COLOR      = 2

'/* duplex enable */
%DMDUP_SIMPLEX    = 1
%DMDUP_VERTICAL   = 2
%DMDUP_HORIZONTAL = 3

%DMTT_BITMAP           = 1  ' print TT fonts as graphics
%DMTT_DOWNLOAD         = 2  ' download TT fonts as soft fonts
%DMTT_SUBDEV           = 3  ' substitute device fonts for TT fonts
'#if(WINVER >= 0x0400)
%DMTT_DOWNLOAD_OUTLINE = 4  ' download TT fonts as outline soft fonts
'#endif /* WINVER >= 0x0400 */

'/* Collation selections */
%DMCOLLATE_FALSE = 0
%DMCOLLATE_TRUE  = 1

'#if(WINVER >= 0x0501)
'/* DEVMODE dmDisplayOrientation specifiations */
%DMDO_DEFAULT   = 0
%DMDO_90        = 1
%DMDO_180       = 2
%DMDO_270       = 3

'/* DEVMODE dmDisplayFixedOutput specifiations */
%DMDFO_DEFAULT  = 0
%DMDFO_STRETCH  = 1
%DMDFO_CENTER   = 2
'#endif /* WINVER >= 0x0501 */

'/* DEVMODE dmDisplayFlags flags */

'// #define DM_GRAYSCALE            0x00000001 /* This flag is no longer valid */
'// #define DM_INTERLACED           0x00000002 /* This flag is no longer valid */
'%DM_GRAYSCALE            = &H00000001???   ' /* This flag is no longer valid */
%DM_INTERLACED           = &H00000002???
%DMDISPLAYFLAGS_TEXTMODE = 4

'/* dmNup , multiple logical page per physical page options */
%DMNUP_SYSTEM       = 1
%DMNUP_ONEUP        = 2

'#if(WINVER >= 0x0400)
'/* ICM methods */
%DMICMMETHOD_NONE   = 1     ' ICM disabled
%DMICMMETHOD_SYSTEM = 2     ' ICM handled by system
%DMICMMETHOD_DRIVER = 3     ' ICM handled by driver
%DMICMMETHOD_DEVICE = 4     ' ICM handled by device

'#define DMICMMETHOD_USER  256   /* Device-specific methods start here */
%DMICMMETHOD_USER   = 256   ' Device-specific methods start here

'/* ICM Intents */
%DMICM_SATURATE         = 1   ' Maximize color saturation
%DMICM_CONTRAST         = 2   ' Maximize color contrast
%DMICM_COLORIMETRIC     = 3   ' Use specific color metric
%DMICM_ABS_COLORIMETRIC = 4   ' Use specific color metric

%DMICM_USER             = 256 ' Device-specific intents start here

'/* Media types */

%DMMEDIA_STANDARD     = 1   ' Standard paper
%DMMEDIA_TRANSPARENCY = 2   ' Transparency
%DMMEDIA_GLOSSY       = 3   ' Glossy paper

%DMMEDIA_USER         = 256 ' Device-specific media start here

'/* Dither types */
%DMDITHER_NONE           = 1   ' No dithering
%DMDITHER_COARSE         = 2   ' Dither with a coarse brush
%DMDITHER_FINE           = 3   ' Dither with a fine brush
%DMDITHER_LINEART        = 4   ' LineArt dithering
%DMDITHER_ERRORDIFFUSION = 5   ' LineArt dithering
%DMDITHER_RESERVED6      = 6   ' LineArt dithering
%DMDITHER_RESERVED7      = 7   ' LineArt dithering
%DMDITHER_RESERVED8      = 8   ' LineArt dithering
%DMDITHER_RESERVED9      = 9   ' LineArt dithering
%DMDITHER_GRAYSCALE      = 10  ' Device does grayscaling

'#define DMDITHER_USER     256   /* Device-specific dithers start here */
%DMDITHER_USER           = 256 ' Device-specific dithers start here
'#endif /* WINVER >= 0x0400 */

' // Size = 424 bytes
TYPE DISPLAY_DEVICEA DWORD
   cb           AS DWORD              ' DWORD  cb
   DeviceName   AS ASCIIZ * 32        ' CHAR   DeviceName[32]
   DeviceString AS ASCIIZ * 128       ' CHAR   DeviceString[128]
   StateFlags   AS DWORD              ' DWORD  StateFlags
   DeviceID     AS ASCIIZ * 128       ' CHAR   DeviceID[128]
   DeviceKey    AS ASCIIZ * 128       ' CHAR   DeviceKey[128]
END TYPE

' // Size = 840 bytes
TYPE DISPLAY_DEVICEW DWORD
   cb           AS DWORD            ' DWORD  cb
   DeviceName   AS WSTRINGZ * 32    ' WCHAR  DeviceName[32]
   DeviceString AS WSTRINGZ * 128   ' WCHAR  DeviceString[128]
   StateFlags   AS DWORD            ' DWORD  StateFlags
   DeviceID     AS WSTRINGZ * 128   ' WCHAR  DeviceID[128]
   DeviceKey    AS WSTRINGZ * 128   ' WCHAR  DeviceKey[128]
END TYPE

#IF %DEF(%UNICODE)
   MACRO DISPLAY_DEVICE = DISPLAY_DEVICEW
#ELSE
   MACRO DISPLAY_DEVICE = DISPLAY_DEVICEA
#ENDIF

%DISPLAY_DEVICE_ATTACHED_TO_DESKTOP = &H00000001???
%DISPLAY_DEVICE_MULTI_DRIVER        = &H00000002???
%DISPLAY_DEVICE_PRIMARY_DEVICE      = &H00000004???
%DISPLAY_DEVICE_MIRRORING_DRIVER    = &H00000008???
%DISPLAY_DEVICE_VGA_COMPATIBLE      = &H00000010???
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_REMOVABLE           = &H00000020???
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_MODESPRUNED         = &H08000000???
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_REMOTE              = &H04000000???
%DISPLAY_DEVICE_DISCONNECT          = &H02000000???
'#endif
%DISPLAY_DEVICE_TS_COMPATIBLE       = &H00200000???
'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
%DISPLAY_DEVICE_UNSAFE_MODES_ON     = &H00080000???
'#endif

'/* Child device state */
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%DISPLAY_DEVICE_ACTIVE              = &H00000001???
%DISPLAY_DEVICE_ATTACHED            = &H00000002???
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)

'#if(WINVER >= 0x0601)

%DISPLAYCONFIG_MAXPATH = 1024       ' // Maximum display path in system.
                                    ' // Max adapter (16) * Max source (16) *
                                    ' // Max clone pre source (4)

' // Size = 8 bytes
TYPE DISPLAYCONFIG_RATIONAL DWORD
   Numerator   AS DWORD   ' UINT32
   Denominator AS DWORD   ' UINT32
END TYPE

' enum DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER                   = -1
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15                    =  0
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO                  =  1
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO         =  2
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO         =  3
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI                     =  4
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI                    =  5
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS                    =  6
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN                   =  8
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI                     =  9
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL    = 10
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED    = 11
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL            = 12
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED            = 13
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE              = 14
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL                = &H80000000???
%DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32            = &HFFFFFFFF???

' enum DISPLAYCONFIG_SCANLINE_ORDERING
%DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED                 = 0???
%DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE                 = 1???
%DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED                  = 2???
%DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST  = %DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
%DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST  = 3???
%DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32                = &HFFFFFFFF???

' // Size = 8 bytes
TYPE DISPLAYCONFIG_2DREGION DWORD
   cx AS DWORD   ' UINT32
   cy AS DWORD   ' UINT32
END TYPE

' // Size = 48 bytes
TYPE DISPLAYCONFIG_VIDEO_SIGNAL_INFO   ' Must be 8 byte aligned
   pixelRate        AS QUAD                     ' UINT64
   hSyncFreq        AS DISPLAYCONFIG_RATIONAL
   vSyncFreq        AS DISPLAYCONFIG_RATIONAL
   activeSize       AS DISPLAYCONFIG_2DREGION
   totalSize        AS DISPLAYCONFIG_2DREGION
   videoStandard    AS DWORD                    ' UINT32
   scanLineOrdering AS DWORD                    ' DISPLAYCONFIG_SCANLINE_ORDERING
END TYPE

' enum DISPLAYCONFIG_SCALING
%DISPLAYCONFIG_SCALING_IDENTITY                  = 1???
%DISPLAYCONFIG_SCALING_CENTERED                  = 2???
%DISPLAYCONFIG_SCALING_STRETCHED                 = 3???
%DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX    = 4???
%DISPLAYCONFIG_SCALING_CUSTOM                    = 5???
%DISPLAYCONFIG_SCALING_PREFERRED                 = 128???
%DISPLAYCONFIG_SCALING_FORCE_UINT32              = &HFFFFFFFF???

' enum DISPLAYCONFIG_ROTATION
%DISPLAYCONFIG_ROTATION_IDENTITY     = 1???
%DISPLAYCONFIG_ROTATION_ROTATE90     = 2???
%DISPLAYCONFIG_ROTATION_ROTATE180    = 3???
%DISPLAYCONFIG_ROTATION_ROTATE270    = 4???
%DISPLAYCONFIG_ROTATION_FORCE_UINT32 = &HFFFFFFFF???

' enum DISPLAYCONFIG_MODE_INFO_TYPE
%DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE = 1???
%DISPLAYCONFIG_MODE_INFO_TYPE_TARGET = 2???
%DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32 = &HFFFFFFFF???

' enum DISPLAYCONFIG_PIXELFORMAT
%DISPLAYCONFIG_PIXELFORMAT_8BPP          = 1???
%DISPLAYCONFIG_PIXELFORMAT_16BPP         = 2???
%DISPLAYCONFIG_PIXELFORMAT_24BPP         = 3???
%DISPLAYCONFIG_PIXELFORMAT_32BPP         = 4???
%DISPLAYCONFIG_PIXELFORMAT_NONGDI        = 5???
%DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32  = &Hffffffff???

' // Size = 20 bytes
TYPE DISPLAYCONFIG_SOURCE_MODE DWORD
   width       AS DWORD    ' UINT32
   height      AS DWORD    ' UINT32
   pixelFormat AS DWORD    ' DISPLAYCONFIG_PIXELFORMAT
   position    AS POINTL
END TYPE

' // Size = 48 bytes
TYPE DISPLAYCONFIG_TARGET_MODE   ' Must be 9 byte aligned
   targetVideoSignalInfo AS DISPLAYCONFIG_VIDEO_SIGNAL_INFO
END TYPE

' // Size = 48 bytes
UNION DISPLAYCONFIG_MODE_INFO_UNION DWORD
   targetMode AS DISPLAYCONFIG_TARGET_MODE
   sourceMode AS DISPLAYCONFIG_SOURCE_MODE
END UNION

' // Size = 64 bytes
TYPE DISPLAYCONFIG_MODE_INFO DWORD
   infoType  AS LONG    ' DISPLAYCONFIG_MODE_INFO_TYPE
   id        AS DWORD   ' UINT32
   adapterId AS QUAD    ' LUID
   DISPLAYCONFIG_MODE_INFO_UNION
END TYPE

%DISPLAYCONFIG_PATH_MODE_IDX_INVALID = &Hffffffff???

' // Size = 20 bytes
TYPE DISPLAYCONFIG_PATH_SOURCE_INFO DWORD
   adapterId   AS QUAD    ' LUID
   id          AS DWORD   ' UINT32
   modeInfoIdx AS DWORD   ' UINT32
   statusFlags AS DWORD   ' UINT32
END TYPE

'//
'// Flags for source info structure (from OS to application through QDC)
'//

%DISPLAYCONFIG_SOURCE_IN_USE = &H00000001???

' // Size = 48 bytes
TYPE DISPLAYCONFIG_PATH_TARGET_INFO DWORD
   adapterId        AS QUAD                     ' LUID
   id               AS DWORD                    ' UINT32
   modeInfoIdx      AS DWORD                    ' UINT32
   outputTechnology AS LONG                     ' DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY
   rotation         AS DWORD                    ' DISPLAYCONFIG_ROTATION
   scaling          AS DWORD                    ' DISPLAYCONFIG_SCALING
   refreshRate      AS DISPLAYCONFIG_RATIONAL
   scanLineOrdering AS DWORD                    ' DISPLAYCONFIG_SCANLINE_ORDERING
   targetAvailable  AS LONG                     ' BOOL
   statusFlags      AS DWORD                    ' UINT32
END TYPE

'//
'// Status flags for target info structure (from OS to application through QDC)
'//
%DISPLAYCONFIG_TARGET_IN_USE                         = &H00000001???
%DISPLAYCONFIG_TARGET_FORCIBLE                       = &H00000002???
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT       = &H00000004???
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH       = &H00000008???
%DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM     = &H00000010???

' // Size = 72 bytes
TYPE DISPLAYCONFIG_PATH_INFO DWORD
   sourceInfo AS DISPLAYCONFIG_PATH_SOURCE_INFO
   targetInfo AS DISPLAYCONFIG_PATH_TARGET_INFO
   flags      AS DWORD   ' UINT32
END TYPE

'//
'// Flags for path info structure (from OS to application through QDC)
'//

%DISPLAYCONFIG_PATH_ACTIVE = &H00000001???

' enum DISPLAYCONFIG_TOPOLOGY_ID
%DISPLAYCONFIG_TOPOLOGY_INTERNAL       = &H00000001???
%DISPLAYCONFIG_TOPOLOGY_CLONE          = &H00000002???
%DISPLAYCONFIG_TOPOLOGY_EXTEND         = &H00000004???
%DISPLAYCONFIG_TOPOLOGY_EXTERNAL       = &H00000008???
%DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32   = &HFFFFFFFF???

' enum DISPLAYCONFIG_DEVICE_INFO_TYPE
%DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME             = 1???
%DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME             = 2???
%DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE   = 3???
%DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME            = 4???
%DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE      = 5???
%DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32                = &HFFFFFFFF???

UNION DISPLAYCONFIG_DEVICE_INFO_HEADER_TYPE_UNION
   type      AS DWORD   ' DISPLAYCONFIG_DEVICE_INFO_TYPE
   ' // For compatibility with PB declares
   dtype     AS DWORD   ' DISPLAYCONFIG_DEVICE_INFO_TYPE
END UNION

UNION DISPLAYCONFIG_DEVICE_INFO_HEADER_SIZE_UNION
   size      AS DWORD   ' UINT32
   ' // For compatibility with PB declares
   dsize     AS DWORD   ' UINT32
END UNION

' // Size = 20 bytes
TYPE DISPLAYCONFIG_DEVICE_INFO_HEADER DWORD
   DISPLAYCONFIG_DEVICE_INFO_HEADER_TYPE_UNION
   DISPLAYCONFIG_DEVICE_INFO_HEADER_SIZE_UNION
   adapterId AS QUAD    ' LUID
   id        AS DWORD   ' UINT32
END TYPE

' // Size = 84 bytes
TYPE DISPLAYCONFIG_SOURCE_DEVICE_NAME DWORD
   header            AS DISPLAYCONFIG_DEVICE_INFO_HEADER
   viewGdiDeviceName AS WSTRINGZ * %CCHDEVICENAME   ' WCHAR
END TYPE

' // Size = 4 bytes
TYPE DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_STRUCT DWORD
   friendlyNameFromEdid AS BIT * 1 IN DWORD   ' UINT32
   friendlyNameForced   AS BIT * 1
   edidIdsValid         AS BIT * 1
   reserved             AS BIT * 29
END TYPE

' // Size = 4 bytes
UNION DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_UNION
   DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_STRUCT
   value AS DWORD   ' UINT32
END UNION

' // Size = 4 bytes
TYPE DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS DWORD
   DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS_UNION
END TYPE

' // Size = 420 bytes
TYPE DISPLAYCONFIG_TARGET_DEVICE_NAME DWORD FILL
   header                    AS DISPLAYCONFIG_DEVICE_INFO_HEADER
   flags                     AS DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
   outputTechnology          AS LONG            ' DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY
   edidManufactureId         AS WORD            ' UINT16
   edidProductCodeId         AS WORD            ' UINT16
   connectorInstance         AS DWORD           ' UINT32
   monitorFriendlyDeviceName AS WSTRINGZ * 64   ' WCHAR
   monitorDevicePath         AS WSTRINGZ * 128  ' WCHAR
END TYPE

' // Size = 80 bytes
TYPE DISPLAYCONFIG_TARGET_PREFERRED_MODE QWORD FILL  ' Must be 8 byte aligned
   header     AS DISPLAYCONFIG_DEVICE_INFO_HEADER
   width      AS DWORD   ' UINT32
   height     AS DWORD   ' UINT32
   targetMode AS DISPLAYCONFIG_TARGET_MODE
END TYPE

' // Size = 276 bytes
TYPE DISPLAYCONFIG_ADAPTER_NAME   ' Must be 8 byte aligned
   header AS DISPLAYCONFIG_DEVICE_INFO_HEADER
   adapterDevicePath AS WSTRINGZ * 128   ' WCHAR
END TYPE

' // Size = 4 bytes
TYPE DISPLAYCONFIG_SET_TARGET_PERSISTENCE_STRUCT DWORD
   bootPersistenceOn AS BIT * 1 IN DWORD   ' UINT32
   reserved          AS BIT * 31
END TYPE

' // Size = 4 bytes
UNION DISPLAYCONFIG_SET_TARGET_PERSISTENCE_UNION
   DISPLAYCONFIG_SET_TARGET_PERSISTENCE_STRUCT
   value AS DWORD   ' UINT32
END UNION

' // Size = 24 bytes
TYPE DISPLAYCONFIG_SET_TARGET_PERSISTENCE   ' Must be 8 byte aligned
   header AS DISPLAYCONFIG_DEVICE_INFO_HEADER
   DISPLAYCONFIG_SET_TARGET_PERSISTENCE_UNION
END TYPE

'//
'// Definitions to be used by GetDisplayConfigBufferSizes and QueryDisplayConfig.
'//

%QDC_ALL_PATHS                   = &H00000001???
%QDC_ONLY_ACTIVE_PATHS           = &H00000002???
%QDC_DATABASE_CURRENT            = &H00000004???

'//
'// Definitions used by SetDisplayConfig.
'//

%SDC_TOPOLOGY_INTERNAL           = &H00000001???
%SDC_TOPOLOGY_CLONE              = &H00000002???
%SDC_TOPOLOGY_EXTEND             = &H00000004???
%SDC_TOPOLOGY_EXTERNAL           = &H00000008???
%SDC_TOPOLOGY_SUPPLIED           = &H00000010???
%SDC_USE_DATABASE_CURRENT        = %SDC_TOPOLOGY_INTERNAL OR %SDC_TOPOLOGY_CLONE OR %SDC_TOPOLOGY_EXTEND OR %SDC_TOPOLOGY_EXTERNAL

%SDC_USE_SUPPLIED_DISPLAY_CONFIG = &H00000020???
%SDC_VALIDATE                    = &H00000040???
%SDC_APPLY                       = &H00000080???
%SDC_NO_OPTIMIZATION             = &H00000100???
%SDC_SAVE_TO_DATABASE            = &H00000200???
%SDC_ALLOW_CHANGES               = &H00000400???
%SDC_PATH_PERSIST_IF_REQUIRED    = &H00000800???
%SDC_FORCE_MODE_ENUMERATION      = &H00001000???
%SDC_ALLOW_PATH_ORDER_CHANGES    = &H00002000???

'#endif /* WINVER >= 0x0601 */

'/* GetRegionData/ExtCreateRegion */

%RDH_RECTANGLES = 1

#IF NOT %DEF(%RGNDATAHEADER_DEFINED)
%RGNDATAHEADER_DEFINED = 1
' // Size = 32 bytes
TYPE RGNDATAHEADER DWORD
   dwSize   AS DWORD
   iType    AS DWORD
   nCount   AS DWORD
   nRgnSize AS DWORD
   rcBound  AS RECT
END TYPE
#ENDIF

#IF NOT %DEF(%RGNDATA_DEFINED)
%RGNDATA_DEFINED = 1
' // Size = 36 bytes
TYPE RGNDATA DWORD
   rdh       AS RGNDATAHEADER   ' RGNDATAHEADER rdh
   Buffer(0) AS BYTE            ' char Buffer[ 1 ] - arbitrary-size buffer
END TYPE
#ENDIF

'/* for GetRandomRgn */
%SYSRGN = 4

' // Size = 12 bytes
TYPE ABC DWORD
   abcA AS LONG    ' int
   abcB AS DWORD   ' UINT
   abcC AS LONG    ' int
END TYPE

' // Size = 12 bytes
TYPE ABCFLOAT DWORD
   abcfA AS SINGLE   ' FLOAT
   abcfB AS SINGLE   ' FLOAT
   abcfC AS SINGLE   ' FLOAT
END TYPE

#IF NOT %DEF(%NOTEXTMETRIC) ' -------------------------------------------------
'#ifndef NOTEXTMETRIC

'#ifdef _MAC
'#include "pshpack4.h"
'#endif

' // Size = 212 bytes
TYPE OUTLINETEXTMETRICA BYTE
   otmSize                AS DWORD         ' UINT
   otmTextMetrics         AS TEXTMETRICA   ' TEXTMETRICA
   otmFiller              AS BYTE          ' BYTE
   otmPanoseNumber        AS PANOSE        ' PANOSE
   alignment__            AS BYTE
   otmfsSelection         AS DWORD         ' UINT
   otmfsType              AS DWORD         ' UINT
   otmsCharSlopeRise      AS LONG          ' int
   otmsCharSlopeRun       AS LONG          ' int
   otmItalicAngle         AS LONG          ' int
   otmEMSquare            AS DWORD         ' UINT
   otmAscent              AS LONG          ' int
   otmDescent             AS LONG          ' int
   otmLineGap             AS DWORD         ' UINT
   otmsCapEmHeight        AS DWORD         ' UINT
   otmsXHeight            AS DWORD         ' UINT
   otmrcFontBox           AS RECT          ' RECT
   otmMacAscent           AS LONG          ' int
   otmMacDescent          AS LONG          ' int
   otmMacLineGap          AS DWORD         ' UINT
   otmusMinimumPPEM       AS DWORD         ' UINT
   otmptSubscriptSize     AS POINT         ' POINT
   otmptSubscriptOffset   AS POINT         ' POINT
   otmptSuperscriptSize   AS POINT         ' POINT
   otmptSuperscriptOffset AS POINT         ' POINT
   otmsStrikeoutSize      AS DWORD         ' UINT
   otmsStrikeoutPosition  AS LONG          ' int
   otmsUnderscorePosition AS LONG          ' int
   otmsUnderscoreSize     AS LONG          ' int
   otmpFamilyName         AS ASCIIZ PTR    ' PSTR
   otmpFaceName           AS ASCIIZ PTR    ' PSTR
   otmpStyleName          AS ASCIIZ PTR    ' PSTR
   otmpFullName           AS ASCIIZ PTR    ' PSTR
END TYPE

' // Size = 216 bytes
TYPE OUTLINETEXTMETRICW BYTE
   otmSize                AS DWORD         ' UINT
   otmTextMetrics         AS TEXTMETRICW
   otmFiller              AS BYTE          ' BYTE
   otmPanoseNumber        AS PANOSE        ' PANOSE
   alignment__            AS BYTE
   otmfsSelection         AS DWORD         ' UINT
   otmfsType              AS DWORD         ' UINT
   otmsCharSlopeRise      AS LONG          ' int
   otmsCharSlopeRun       AS LONG          ' int
   otmItalicAngle         AS LONG          ' int
   otmEMSquare            AS DWORD         ' UINT
   otmAscent              AS LONG          ' int
   otmDescent             AS LONG          ' int
   otmLineGap             AS DWORD         ' UINT
   otmsCapEmHeight        AS DWORD         ' UINT
   otmsXHeight            AS DWORD         ' UINT
   otmrcFontBox           AS RECT          ' RECT
   otmMacAscent           AS LONG          ' int
   otmMacDescent          AS LONG          ' int
   otmMacLineGap          AS DWORD         ' UINT
   otmusMinimumPPEM       AS DWORD         ' UINT
   otmptSubscriptSize     AS POINT         ' POINT
   otmptSubscriptOffset   AS POINT         ' POINT
   otmptSuperscriptSize   AS POINT         ' POINT
   otmptSuperscriptOffset AS POINT         ' POINT
   otmsStrikeoutSize      AS DWORD         ' UINT
   otmsStrikeoutPosition  AS LONG          ' int
   otmsUnderscorePosition AS LONG          ' int
   otmsUnderscoreSize     AS LONG          ' int
   otmpFamilyName         AS ASCIIZ PTR    ' PSTR
   otmpFaceName           AS ASCIIZ PTR    ' PSTR
   otmpStyleName          AS ASCIIZ PTR    ' PSTR
   otmpFullName           AS ASCIIZ PTR    ' PSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO OUTLINETEXTMETRIC = OUTLINETEXTMETRICW
#ELSE
   MACRO OUTLINETEXTMETRIC = OUTLINETEXTMETRICA
#ENDIF

'#endif /* NOTEXTMETRIC */
#ENDIF   ' #IF NOT %DEF(%NOTEXTMETRIC) ----------------------------------------

' // Size = 40 bytes
TYPE POLYTEXTA DWORD
   x       AS LONG         ' int
   y       AS LONG         ' int
   n       AS DWORD        ' UINT
   lpStr   AS ASCIIZ PTR   ' LPCSTR
   uiFlags AS DWORD        ' UINT
   rcl     AS RECT         ' RECT
   pdx     AS LONG PTR     ' INT*
END TYPE

' // Size = 40 bytes
TYPE POLYTEXTW DWORD
   x       AS LONG           ' int
   y       AS LONG           ' int
   n       AS DWORD          ' UINT
   lpStr   AS WSTRINGZ PTR   ' LPCWSTR
   uiFlags AS DWORD          ' UINT
   rcl     AS RECT           ' RECT
   pdx     AS LONG PTR       ' int*
END TYPE

#IF %DEF(%UNICODE)
   MACRO POLYTEXT = POLYTEXTW
#ELSE
   MACRO POLYTEXT = POLYTEXTA
#ENDIF

' // Size = 4 bytes
TYPE FIXED WORD
   fract AS WORD      ' WORD
   value AS INTEGER   ' short
END TYPE

' // Size = 16 bytes
TYPE MAT2 DWORD
  eM11 AS FIXED
  eM12 AS FIXED
  eM21 AS FIXED
  eM22 AS FIXED
END TYPE

' // Size = 20 bytes
TYPE GLYPHMETRICS DWORD FILL
  gmBlackBoxX     AS DWORD     ' UINT
  gmBlackBoxY     AS DWORD     ' UINT
  gmptGlyphOrigin AS POINT     ' POINT
  gmCellIncX      AS INTEGER   ' short
  gmCellIncY      AS INTEGER   ' short
END TYPE

'//  GetGlyphOutline constants

%GGO_METRICS      = 0???
%GGO_BITMAP       = 1???
%GGO_NATIVE       = 2???
%GGO_BEZIER       = 3???

'#if(WINVER >= 0x0400)
%GGO_GRAY2_BITMAP = 4???
%GGO_GRAY4_BITMAP = 5???
%GGO_GRAY8_BITMAP = 6???
%GGO_GLYPH_INDEX  = &H0080???
'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0500)
%GGO_UNHINTED     = &H0100???
'#endif // (_WIN32_WINNT >= 0x0500)

%TT_POLYGON_TYPE = 24

%TT_PRIM_LINE    = 1
%TT_PRIM_QSPLINE = 2
%TT_PRIM_CSPLINE = 3

' // Size = 8 bytes
TYPE POINTFX DWORD
   x AS FIXED
   y AS FIXED
END TYPE

' // Size = 12 bytes
TYPE TTPOLYCURVE DWORD FILL
   wType   AS WORD      ' WORD
   cpfx    AS WORD      ' WORD
   apfx(0) AS POINTFX   ' POINTFX apfx[1]
END TYPE

' // Size = 16 bytes
TYPE TTPOLYGONHEADER DWORD
   cb       AS DWORD
   dwType   AS DWORD
   pfxStart AS POINTFX
END TYPE

'#if(WINVER >= 0x0400)
%GCP_DBCS            = &H00000001???
%GCP_REORDER         = &H00000002???
%GCP_USEKERNING      = &H00000008???
%GCP_GLYPHSHAPE      = &H00000010???
%GCP_LIGATE          = &H00000020???
%GCP_DIACRITIC       = &H00000100???
%GCP_KASHIDA         = &H00000400???
%GCP_ERROR           = &H00008000???
%FLI_MASK            = &H0000103B???

%GCP_JUSTIFY         = &H00010000???
'%GCP_NODIACRITICS    = &H00020000???
%FLI_GLYPHS          = &H00040000???
%GCP_CLASSIN         = &H00080000???
%GCP_MAXEXTENT       = &H00100000???
%GCP_JUSTIFYIN       = &H00200000???
%GCP_DISPLAYZWG      = &H00400000???
%GCP_SYMSWAPOFF      = &H00800000???
%GCP_NUMERICOVERRIDE = &H01000000???
%GCP_NEUTRALOVERRIDE = &H02000000???
%GCP_NUMERICSLATIN   = &H04000000???
%GCP_NUMERICSLOCAL   = &H08000000???

%GCPCLASS_LATIN                  = 1
%GCPCLASS_HEBREW                 = 2
%GCPCLASS_ARABIC                 = 2
%GCPCLASS_NEUTRAL                = 3
%GCPCLASS_LOCALNUMBER            = 4
%GCPCLASS_LATINNUMBER            = 5
%GCPCLASS_LATINNUMERICTERMINATOR = 6
%GCPCLASS_LATINNUMERICSEPARATOR  = 7
%GCPCLASS_NUMERICSEPARATOR       = 8
%GCPCLASS_PREBOUNDLTR            = &H80
%GCPCLASS_PREBOUNDRTL            = &H40
%GCPCLASS_POSTBOUNDLTR           = &H20
%GCPCLASS_POSTBOUNDRTL           = &H10

%GCPGLYPH_LINKBEFORE = &H8000???
%GCPGLYPH_LINKAFTER  = &H4000???

' // Size = 36 bytes
TYPE GCP_RESULTSA DWORD
   lStructSize AS DWORD            ' DWORD
   lpOutString AS ASCIIZ PTR       ' LPSTR
   lpOrder     AS DWORD PTR        ' UINT FAR*
   lpDx        AS LONG PTR         ' int FAR*
   lpCaretPos  AS LONG PTR         ' int FAR*
   lpClass     AS ASCIIZ PTR       ' LPSTR
   lpGlyphs    AS WSTRINGZ PTR     ' LPWSTR
   nGlyphs     AS DWORD            ' UINT
   nMaxFit     AS LONG             ' int
END TYPE

' // Size = 36 bytes
TYPE GCP_RESULTSW DWORD
   lStructSize AS DWORD            ' DWORD
   lpOutString AS WSTRINGZ PTR     ' LPWSTR
   lpOrder     AS DWORD PTR        ' UINT FAR*
   lpDx        AS LONG PTR         ' int FAR*
   lpCaretPos  AS LONG PTR         ' int FAR*
   lpClass     AS WSTRINGZ PTR     ' LPWSTR
   lpGlyphs    AS WSTRINGZ PTR     ' LPWSTR
   nGlyphs     AS DWORD            ' UINT
   nMaxFit     AS LONG             ' int
END TYPE

#IF %DEF(%UNICODE)
   MACRO GCP_RESULTS = GCP_RESULTSW
#ELSE
   MACRO GCP_RESULTS = GCP_RESULTSA
#ENDIF

' // Size = 6 bytes
TYPE RASTERIZER_STATUS WORD
   nSize       AS INTEGER   ' short
   wFlags      AS INTEGER   ' short
   nLanguageID AS INTEGER   ' short
END TYPE

'/* bits defined in wFlags of RASTERIZER_STATUS */
%TT_AVAILABLE    = &H0001%
%TT_ENABLED      = &H0002%

'/* Pixel format descriptor */
' // Size = 40 bytes
TYPE PIXELFORMATDESCRIPTOR DWORD FILL
   nSize           AS WORD
   nVersion        AS WORD
   dwFlags         AS DWORD
   iPixelType      AS BYTE
   cColorBits      AS BYTE
   cRedBits        AS BYTE
   cRedShift       AS BYTE
   cGreenBits      AS BYTE
   cGreenShift     AS BYTE
   cBlueBits       AS BYTE
   cBlueShift      AS BYTE
   cAlphaBits      AS BYTE
   cAlphaShift     AS BYTE
   cAccumBits      AS BYTE
   cAccumRedBits   AS BYTE
   cAccumGreenBits AS BYTE
   cAccumBlueBits  AS BYTE
   cAccumAlphaBits AS BYTE
   cDepthBits      AS BYTE
   cStencilBits    AS BYTE
   cAuxBuffers     AS BYTE
   iLayerType      AS BYTE
   bReserved       AS BYTE
   dwLayerMask     AS DWORD
   dwVisibleMask   AS DWORD
   dwDamageMask    AS DWORD
END TYPE

'/* pixel types */
%PFD_TYPE_RGBA       = 0
%PFD_TYPE_COLORINDEX = 1

'/* layer types */
%PFD_MAIN_PLANE     = 0
%PFD_OVERLAY_PLANE  = 1
%PFD_UNDERLAY_PLANE = -1

'/* PIXELFORMATDESCRIPTOR flags */
%PFD_DOUBLEBUFFER          = &H00000001???
%PFD_STEREO                = &H00000002???
%PFD_DRAW_TO_WINDOW        = &H00000004???
%PFD_DRAW_TO_BITMAP        = &H00000008???
%PFD_SUPPORT_GDI           = &H00000010???
%PFD_SUPPORT_OPENGL        = &H00000020???
%PFD_GENERIC_FORMAT        = &H00000040???
%PFD_NEED_PALETTE          = &H00000080???
%PFD_NEED_SYSTEM_PALETTE   = &H00000100???
%PFD_SWAP_EXCHANGE         = &H00000200???
%PFD_SWAP_COPY             = &H00000400???
%PFD_SWAP_LAYER_BUFFERS    = &H00000800???
%PFD_GENERIC_ACCELERATED   = &H00001000???
%PFD_SUPPORT_DIRECTDRAW    = &H00002000???
%PFD_DIRECT3D_ACCELERATED  = &H00004000???
%PFD_SUPPORT_COMPOSITION   = &H00008000???

'/* PIXELFORMATDESCRIPTOR flags for use in ChoosePixelFormat only */
%PFD_DEPTH_DONTCARE        = &H20000000???
%PFD_DOUBLEBUFFER_DONTCARE = &H40000000???
%PFD_STEREO_DONTCARE       = &H80000000???

'#ifdef STRICT
'#if !defined(NOTEXTMETRIC)
'typedef int (CALLBACK* OLDFONTENUMPROCA)(CONST LOGFONTA *, CONST TEXTMETRICA *, DWORD, LPARAM);
'typedef int (CALLBACK* OLDFONTENUMPROCW)(CONST LOGFONTW *, CONST TEXTMETRICW *, DWORD, LPARAM);

'typedef int (CALLBACK* GOBJENUMPROC)(LPVOID, LPARAM);
'typedef VOID (CALLBACK* LINEDDAPROC)(int, int, LPARAM);
'#else
'typedef FARPROC OLDFONTENUMPROC;
'typedef FARPROC FONTENUMPROCA;
'typedef FARPROC FONTENUMPROCW;
'typedef FARPROC GOBJENUMPROC;
'typedef FARPROC LINEDDAPROC;
'#endif


DECLARE FUNCTION AddFontResourceA IMPORT "GDI32.DLL" ALIAS "AddFontResourceA" ( _
   BYREF lpszFilename AS ASCIIZ _                       ' __in LPCSTR lpszFilename
 ) AS LONG                                              ' int

DECLARE FUNCTION AddFontResourceW IMPORT "GDI32.DLL" ALIAS "AddFontResourceW" ( _
   BYREF lpszFilename AS WSTRINGZ _                     ' __in LPCWSTR lpszFilename
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO AddFontResource = AddFontResourceW
#ELSE
   MACRO AddFontResource = AddFontResourceA
#ENDIF

DECLARE FUNCTION AnimatePalette IMPORT "GDI32.DLL" ALIAS "AnimatePalette" ( _
   BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL iStartIndex AS DWORD _                         ' __in UINT iStartIndex
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF ppe AS PALETTEENTRY _                          ' __in CONST PALETTEENTRY * ppe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Arc IMPORT "GDI32.DLL" ALIAS "Arc" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL x2 AS LONG _                                   ' __in int x2
 , BYVAL y2 AS LONG _                                   ' __in int y2
 , BYVAL x3 AS LONG _                                   ' __in int x3
 , BYVAL y3 AS LONG _                                   ' __in int y3
 , BYVAL x4 AS LONG _                                   ' __in int x4
 , BYVAL y4 AS LONG _                                   ' __in int y4
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BitBlt IMPORT "GDI32.DLL" ALIAS "BitBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL hdcSrc AS DWORD _                              ' __in_opt HDC hdcSrc
 , BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL rop AS DWORD _                                 ' __in DWORD rop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CancelDC IMPORT "GDI32.DLL" ALIAS "CancelDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Chord IMPORT "GDI32.DLL" ALIAS "Chord" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL x2 AS LONG _                                   ' __in int x2
 , BYVAL y2 AS LONG _                                   ' __in int y2
 , BYVAL x3 AS LONG _                                   ' __in int x3
 , BYVAL y3 AS LONG _                                   ' __in int y3
 , BYVAL x4 AS LONG _                                   ' __in int x4
 , BYVAL y4 AS LONG _                                   ' __in int y4
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChoosePixelFormat IMPORT "GDI32.DLL" ALIAS "ChoosePixelFormat" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF ppfd AS PIXELFORMATDESCRIPTOR _                ' __in CONST PIXELFORMATDESCRIPTOR *ppfd
 ) AS LONG                                              ' int

DECLARE FUNCTION CloseMetaFile IMPORT "GDI32.DLL" ALIAS "CloseMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' HMETAFILE

DECLARE FUNCTION CombineRgn IMPORT "GDI32.DLL" ALIAS "CombineRgn" ( _
   BYVAL hrgnDst AS DWORD _                             ' __in_opt HRGN hrgnDst
 , BYVAL hrgnSrc1 AS DWORD _                            ' __in_opt HRGN hrgnSrc1
 , BYVAL hrgnSrc2 AS DWORD _                            ' __in_opt HRGN hrgnSrc2
 , BYVAL iMode AS LONG _                                ' __in int iMode
 ) AS LONG                                              ' int

DECLARE FUNCTION CopyMetaFileA IMPORT "GDI32.DLL" ALIAS "CopyMetaFileA" ( _
   BYVAL hmfSrc AS DWORD _                              ' __in HMETAFILE hmfSrc
 , OPTIONAL BYREF lpszFile AS ASCIIZ _                  ' __in_opt LPCSTR lpszFile
 ) AS DWORD                                             ' HMETAFILE

DECLARE FUNCTION CopyMetaFileW IMPORT "GDI32.DLL" ALIAS "CopyMetaFileW" ( _
   BYVAL hmfSrc AS DWORD _                              ' __in HMETAFILE hmfSrc
 , OPTIONAL BYREF lpszFile AS WSTRINGZ _                ' __in_opt LPCWSTR lpszFile
 ) AS DWORD                                             ' HMETAFILE

#IF %DEF(%UNICODE)
   MACRO CopyMetaFile = CopyMetaFileW
#ELSE
   MACRO CopyMetaFile = CopyMetaFileA
#ENDIF

DECLARE FUNCTION CreateBitmap IMPORT "GDI32.DLL" ALIAS "CreateBitmap" ( _
   BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL nPlanes AS DWORD _                             ' __in UINT nPlanes
 , BYVAL nBitCount AS DWORD _                           ' __in UINT nBitCount
 , OPTIONAL BYREF lpBits AS ANY _                       ' __in_opt CONST VOID *lpBits
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION CreateBitmapIndirect IMPORT "GDI32.DLL" ALIAS "CreateBitmapIndirect" ( _
   BYREF pbm AS BITMAP _                                ' __in CONST BITMAP *pbm
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION CreateBrushIndirect IMPORT "GDI32.DLL" ALIAS "CreateBrushIndirect" ( _
   BYREF plbrush AS LOGBRUSH _                          ' __in CONST LOGBRUSH *plbrush
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION CreateCompatibleBitmap IMPORT "GDI32.DLL" ALIAS "CreateCompatibleBitmap" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION CreateDiscardableBitmap IMPORT "GDI32.DLL" ALIAS "CreateDiscardableBitmap" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION CreateCompatibleDC IMPORT "GDI32.DLL" ALIAS "CreateCompatibleDC" ( _
   OPTIONAL BYVAL hdc AS DWORD _                        ' __in_opt HDC hdc
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION CreateDCA IMPORT "GDI32.DLL" ALIAS "CreateDCA" ( _
   OPTIONAL BYREF pwszDriver AS ASCIIZ _                ' __in_opt LPCSTR pwszDriver
 , OPTIONAL BYREF pwszDevice AS ASCIIZ _                ' __in_opt LPCSTR pwszDevice
 , OPTIONAL BYREF pszPort AS ASCIIZ _                   ' __in_opt LPCSTR pszPort
 , OPTIONAL BYREF pdm AS DEVMODEA _                     ' __in_opt CONST DEVMODEA * pdm
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION CreateDCW IMPORT "GDI32.DLL" ALIAS "CreateDCW" ( _
   OPTIONAL BYREF pwszDriver AS WSTRINGZ _              ' __in_opt LPCWSTR pwszDriver
 , OPTIONAL BYREF pwszDevice AS WSTRINGZ _              ' __in_opt LPCWSTR pwszDevice
 , OPTIONAL BYREF pszPort AS WSTRINGZ _                 ' __in_opt LPCWSTR pszPort
 , OPTIONAL BYREF pdm AS DEVMODEW _                     ' __in_opt CONST DEVMODEW * pdm
 ) AS DWORD                                             ' HDC

#IF %DEF(%UNICODE)
   MACRO CreateDC = CreateDCW
#ELSE
   MACRO CreateDC = CreateDCA
#ENDIF

DECLARE FUNCTION CreateDIBitmap IMPORT "GDI32.DLL" ALIAS "CreateDIBitmap" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pbmih AS BITMAPINFOHEADER _                    ' __in_opt CONST BITMAPINFOHEADER *pbmih
 , BYVAL flInit AS DWORD _                              ' __in DWORD flInit
 , BYREF pjBits AS ANY _                                ' __in_opt CONST VOID *pjBits
 , BYREF pbmi AS BITMAPINFO _                           ' __in_opt CONST BITMAPINFO *pbmi
 , BYVAL iUsage AS DWORD _                              ' __in UINT iUsage
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION CreateDIBPatternBrush IMPORT "GDI32.DLL" ALIAS "CreateDIBPatternBrush" ( _
   BYVAL h AS DWORD _                                   ' __in HGLOBAL h
 , BYVAL iUsage AS DWORD _                              ' __in UINT iUsage
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION CreateDIBPatternBrushPt IMPORT "GDI32.DLL" ALIAS "CreateDIBPatternBrushPt" ( _
   BYREF lpPackedDIB AS ANY _                           ' __in CONST VOID *lpPackedDIB
 , BYVAL iUsage AS DWORD _                              ' __in UINT iUsage
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION CreateEllipticRgn IMPORT "GDI32.DLL" ALIAS "CreateEllipticRgn" ( _
   BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL x2 AS LONG _                                   ' __in int x2
 , BYVAL y2 AS LONG _                                   ' __in int y2
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreateEllipticRgnIndirect IMPORT "GDI32.DLL" ALIAS "CreateEllipticRgnIndirect" ( _
   BYREF lprect AS RECT _                               ' __in CONST RECT *lprect
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreateFontIndirectA IMPORT "GDI32.DLL" ALIAS "CreateFontIndirectA" ( _
   BYREF lplf AS LOGFONTA _                             ' __in CONST LOGFONTA *lplf
 ) AS DWORD                                             ' HFONT

DECLARE FUNCTION CreateFontIndirectW IMPORT "GDI32.DLL" ALIAS "CreateFontIndirectW" ( _
   BYREF lplf AS LOGFONTW _                             ' __in CONST LOGFONTW *lplf
 ) AS DWORD                                             ' HFONT

#IF %DEF(%UNICODE)
   MACRO CreateFontIndirect = CreateFontIndirectW
#ELSE
   MACRO CreateFontIndirect = CreateFontIndirectA
#ENDIF

DECLARE FUNCTION CreateFontA IMPORT "GDI32.DLL" ALIAS "CreateFontA" ( _
   BYVAL cHeight AS LONG _                              ' __in int cHeight
 , BYVAL cWidth AS LONG _                               ' __in int cWidth
 , BYVAL cEscapement AS LONG _                          ' __in int cEscapement
 , BYVAL cOrientation AS LONG _                         ' __in int cOrientation
 , BYVAL cWeight AS LONG _                              ' __in int cWeight
 , BYVAL bItalic AS DWORD _                             ' __in DWORD bItalic
 , BYVAL bUnderline AS DWORD _                          ' __in DWORD bUnderline
 , BYVAL bStrikeOut AS DWORD _                          ' __in DWORD bStrikeOut
 , BYVAL iCharSet AS DWORD _                            ' __in DWORD iCharSet
 , BYVAL iOutPrecision AS DWORD _                       ' __in DWORD iOutPrecision
 , BYVAL iClipPrecision AS DWORD _                      ' __in DWORD iClipPrecision
 , BYVAL iQuality AS DWORD _                            ' __in DWORD iQuality
 , BYVAL iPitchAndFamily AS DWORD _                     ' __in DWORD iPitchAndFamily
 , OPTIONAL BYREF pszFaceName AS ASCIIZ _               ' __in_opt LPCSTR pszFaceName
 ) AS DWORD                                             ' HFONT

DECLARE FUNCTION CreateFontW IMPORT "GDI32.DLL" ALIAS "CreateFontW" ( _
   BYVAL cHeight AS LONG _                              ' __in int cHeight
 , BYVAL cWidth AS LONG _                               ' __in int cWidth
 , BYVAL cEscapement AS LONG _                          ' __in int cEscapement
 , BYVAL cOrientation AS LONG _                         ' __in int cOrientation
 , BYVAL cWeight AS LONG _                              ' __in int cWeight
 , BYVAL bItalic AS DWORD _                             ' __in DWORD bItalic
 , BYVAL bUnderline AS DWORD _                          ' __in DWORD bUnderline
 , BYVAL bStrikeOut AS DWORD _                          ' __in DWORD bStrikeOut
 , BYVAL iCharSet AS DWORD _                            ' __in DWORD iCharSet
 , BYVAL iOutPrecision AS DWORD _                       ' __in DWORD iOutPrecision
 , BYVAL iClipPrecision AS DWORD _                      ' __in DWORD iClipPrecision
 , BYVAL iQuality AS DWORD _                            ' __in DWORD iQuality
 , BYVAL iPitchAndFamily AS DWORD _                     ' __in DWORD iPitchAndFamily
 , OPTIONAL BYREF pszFaceName AS WSTRINGZ _             ' __in_opt LPCWSTR pszFaceName
 ) AS DWORD                                             ' HFONT

#IF %DEF(%UNICODE)
   MACRO CreateFont = CreateFontW
#ELSE
   MACRO CreateFont = CreateFontA
#ENDIF

DECLARE FUNCTION CreateHatchBrush IMPORT "GDI32.DLL" ALIAS "CreateHatchBrush" ( _
   BYVAL iHatch AS LONG _                               ' __in int iHatch
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION CreateICA IMPORT "GDI32.DLL" ALIAS "CreateICA" ( _
   OPTIONAL BYREF pszDriver AS ASCIIZ _                 ' __in_opt LPCSTR pszDriver
 , OPTIONAL BYREF pszDevice AS ASCIIZ _                 ' __in_opt LPCSTR pszDevice
 , OPTIONAL BYREF pszPort AS ASCIIZ _                   ' __in_opt LPCSTR pszPort
 , OPTIONAL BYREF pdm AS DEVMODEA _                     ' __in_opt CONST DEVMODEA * pdm
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION CreateICW IMPORT "GDI32.DLL" ALIAS "CreateICW" ( _
   OPTIONAL BYREF pszDriver AS WSTRINGZ _               ' __in_opt LPCWSTR pszDriver
 , OPTIONAL BYREF pszDevice AS WSTRINGZ _               ' __in_opt LPCWSTR pszDevice
 , OPTIONAL BYREF pszPort AS WSTRINGZ _                 ' __in_opt LPCWSTR pszPort
 , OPTIONAL BYREF pdm AS DEVMODEW _                     ' __in_opt CONST DEVMODEW * pdm
 ) AS DWORD                                             ' HDC

#IF %DEF(%UNICODE)
   MACRO CreateIC = CreateICW
#ELSE
   MACRO CreateIC = CreateICA
#ENDIF

DECLARE FUNCTION CreateMetaFileA IMPORT "GDI32.DLL" ALIAS "CreateMetaFileA" ( _
   OPTIONAL BYREF pszFile AS ASCIIZ _                   ' __in_opt LPCSTR pszFile
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION CreateMetaFileW IMPORT "GDI32.DLL" ALIAS "CreateMetaFileW" ( _
   OPTIONAL BYREF pszFile AS WSTRINGZ _                 ' __in_opt LPCWSTR pszFile
 ) AS DWORD                                             ' HDC

#IF %DEF(%UNICODE)
   MACRO CreateMetaFile = CreateMetaFileW
#ELSE
   MACRO CreateMetaFile = CreateMetaFileA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CreatePalette LIB "GDI32.DLL" ALIAS "CreatePalette" _
    (BYVAL lpLogPalette AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION CreatePalette IMPORT "GDI32.DLL" ALIAS "CreatePalette" ( _
   BYREF plpal AS ANY _                                 ' __in CONST LOGPALETTE * plpal (variable-length structure)
 ) AS DWORD                                             ' HPALETTE
#ENDIF

DECLARE FUNCTION CreatePen IMPORT "GDI32.DLL" ALIAS "CreatePen" ( _
   BYVAL iStyle AS LONG _                               ' __in int iStyle
 , BYVAL cWidth AS LONG _                               ' __in int cWidth
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' HPEN

DECLARE FUNCTION CreatePenIndirect IMPORT "GDI32.DLL" ALIAS "CreatePenIndirect" ( _
   BYREF plpen AS LOGPEN _                              ' __in CONST LOGPEN *plpen
 ) AS DWORD                                             ' HPEN

DECLARE FUNCTION CreatePolyPolygonRgn IMPORT "GDI32.DLL" ALIAS "CreatePolyPolygonRgn" ( _
   BYREF pptl AS POINT _                                ' __in CONST POINT *pptl
 , BYREF pc AS LONG _                                   ' __in CONST INT  *pc
 , BYVAL cPoly AS LONG _                                ' __in int cPoly
 , BYVAL iMode AS LONG _                                ' __in int iMode
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreatePatternBrush IMPORT "GDI32.DLL" ALIAS "CreatePatternBrush" ( _
   BYVAL hbm AS DWORD _                                 ' __in HBITMAP hbm
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION CreateRectRgn IMPORT "GDI32.DLL" ALIAS "CreateRectRgn" ( _
   BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL x2 AS LONG _                                   ' __in int x2
 , BYVAL y2 AS LONG _                                   ' __in int y2
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreateRectRgnIndirect IMPORT "GDI32.DLL" ALIAS "CreateRectRgnIndirect" ( _
   BYREF lprect AS RECT _                               ' __in CONST RECT *lprect
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreateRoundRectRgn IMPORT "GDI32.DLL" ALIAS "CreateRoundRectRgn" ( _
   BYVAL x1 AS LONG _                                   ' __in int x1
 , BYVAL y1 AS LONG _                                   ' __in int y1
 , BYVAL x2 AS LONG _                                   ' __in int x2
 , BYVAL y2 AS LONG _                                   ' __in int y2
 , BYVAL w AS LONG _                                    ' __in int w
 , BYVAL h AS LONG _                                    ' __in int h
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION CreateScalableFontResourceA IMPORT "GDI32.DLL" ALIAS "CreateScalableFontResourceA" ( _
   BYVAL fdwHidden AS DWORD _                           ' __in DWORD fdwHidden
 , BYREF lpszFont AS ASCIIZ _                           ' __in LPCSTR lpszFont
 , BYREF lpszFile AS ASCIIZ _                           ' __in LPCSTR lpszFile
 , OPTIONAL BYREF lpszPath AS ASCIIZ _                  ' __in_opt LPCSTR lpszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateScalableFontResourceW IMPORT "GDI32.DLL" ALIAS "CreateScalableFontResourceW" ( _
   BYVAL fdwHidden AS DWORD _                           ' __in DWORD fdwHidden
 , BYREF lpszFont AS WSTRINGZ _                         ' __in LPCWSTR lpszFont
 , BYREF lpszFile AS WSTRINGZ _                         ' __in LPCWSTR lpszFile
 , OPTIONAL BYREF lpszPath AS WSTRINGZ _                ' __in_opt LPCWSTR lpszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateScalableFontResource = CreateScalableFontResourceW
#ELSE
   MACRO CreateScalableFontResource = CreateScalableFontResourceA
#ENDIF

DECLARE FUNCTION CreateSolidBrush IMPORT "GDI32.DLL" ALIAS "CreateSolidBrush" ( _
   BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' HBRUSH

DECLARE FUNCTION DeleteDC IMPORT "GDI32.DLL" ALIAS "DeleteDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteMetaFile IMPORT "GDI32.DLL" ALIAS "DeleteMetaFile" ( _
   BYVAL hmf AS DWORD _                                 ' __in HMETAFILE hmf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DeleteObject IMPORT "GDI32.DLL" ALIAS "DeleteObject" ( _
   BYVAL ho AS DWORD _                                  ' __in HGDIOBJ ho
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DescribePixelFormat IMPORT "GDI32.DLL" ALIAS "DescribePixelFormat" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYVAL iPixelFormat AS LONG _                         ' __in  int iPixelFormat
 , BYVAL nBytes AS DWORD _                              ' __in  UINT nBytes
 , BYREF ppfd AS PIXELFORMATDESCRIPTOR _                ' __out LPPIXELFORMATDESCRIPTOR ppfd
 ) AS LONG                                              ' int

'/* define types of pointers to ExtDeviceMode() and DeviceCapabilities()
' * functions for Win 3.1 compatibility
' */

'typedef UINT   (CALLBACK* LPFNDEVMODE)(HWND, HMODULE, LPDEVMODE, LPSTR, LPSTR, LPDEVMODE, LPSTR, UINT);

'typedef DWORD  (CALLBACK* LPFNDEVCAPS)(LPSTR, LPSTR, UINT, LPSTR, LPDEVMODE);

'/* mode selections for the device mode function */
%DM_UPDATE            = 1
%DM_COPY              = 2
%DM_PROMPT            = 4
%DM_MODIFY            = 8

%DM_IN_BUFFER         = %DM_MODIFY
%DM_IN_PROMPT         = %DM_PROMPT
%DM_OUT_BUFFER        = %DM_COPY
%DM_OUT_DEFAULT       = %DM_UPDATE

'/* device capabilities indices */
%DC_FIELDS            = 1
%DC_PAPERS            = 2
%DC_PAPERSIZE         = 3
%DC_MINEXTENT         = 4
%DC_MAXEXTENT         = 5
%DC_BINS              = 6
%DC_DUPLEX            = 7
%DC_SIZE              = 8
%DC_EXTRA             = 9
%DC_VERSION           = 10
%DC_DRIVER            = 11
%DC_BINNAMES          = 12
%DC_ENUMRESOLUTIONS   = 13
%DC_FILEDEPENDENCIES  = 14
%DC_TRUETYPE          = 15
%DC_PAPERNAMES        = 16
%DC_ORIENTATION       = 17
%DC_COPIES            = 18
'#if(WINVER >= 0x0400)
%DC_BINADJUST         = 19
%DC_EMF_COMPLIANT     = 20
%DC_DATATYPE_PRODUCED = 21
%DC_COLLATE           = 22
%DC_MANUFACTURER      = 23
%DC_MODEL             = 24
'#endif  /*  WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%DC_PERSONALITY         = 25
%DC_PRINTRATE           = 26
%DC_PRINTRATEUNIT       = 27
%PRINTRATEUNIT_PPM      = 1
%PRINTRATEUNIT_CPS      = 2
%PRINTRATEUNIT_LPM      = 3
%PRINTRATEUNIT_IPM      = 4
%DC_PRINTERMEM          = 28
%DC_MEDIAREADY          = 29
%DC_STAPLE              = 30
%DC_PRINTRATEPPM        = 31
%DC_COLORDEVICE         = 32
%DC_NUP                 = 33
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%DC_MEDIATYPENAMES      = 34
%DC_MEDIATYPES          = 35
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
'#endif /* WINVER >= 0x0500 */

'/* bit fields of the return value (DWORD) for DC_TRUETYPE */
%DCTT_BITMAP             = &H0000001???
%DCTT_DOWNLOAD           = &H0000002???
%DCTT_SUBDEV             = &H0000004???
'#if(WINVER >= = &H0400)
%DCTT_DOWNLOAD_OUTLINE   = &H0000008???

'/* return values for DC_BINADJUST */
%DCBA_FACEUPNONE       = &H0000??
%DCBA_FACEUPCENTER     = &H0001??
%DCBA_FACEUPLEFT       = &H0002??
%DCBA_FACEUPRIGHT      = &H0003??
%DCBA_FACEDOWNNONE     = &H0100??
%DCBA_FACEDOWNCENTER   = &H0101??
%DCBA_FACEDOWNLEFT     = &H0102??
%DCBA_FACEDOWNRIGHT    = &H0103??
'#endif /* WINVER >= 0x0400 */

' // Note: The pOutput parameter has been declared AS ANY because the type depends on the
' // fwCapability flag.
DECLARE FUNCTION DeviceCapabilitiesA IMPORT "WINSPOOL.DRV" ALIAS "DeviceCapabilitiesA" ( _
   BYREF pDevice AS ASCIIZ _                            ' __in LPCSTR pDevice
 , BYREF pPort AS ASCIIZ _                              ' __in_opt LPCSTR pPort
 , BYVAL fwCapability AS WORD _                         ' __in WORD fwCapability
 , OPTIONAL BYREF pOutput AS ANY _                      ' __out_opt LPSTR pOutput
 , OPTIONAL BYREF pDevMode AS DEVMODEA _                ' __in_opt CONST DEVMODEA * pDevMode
 ) AS LONG                                              ' int

' // Note: The pOutput parameter has been declared AS ANY because the type depends on the
' // fwCapability flag.
DECLARE FUNCTION DeviceCapabilitiesW IMPORT "WINSPOOL.DRV" ALIAS "DeviceCapabilitiesW" ( _
   BYREF pDevice AS WSTRINGZ _                          ' __in LPCWSTR pDevice
 , BYREF pPort AS WSTRINGZ _                            ' __in_opt LPCWSTR pPort
 , BYVAL fwCapability AS WORD _                         ' __in WORD fwCapability
 , OPTIONAL BYREF pOutput AS ANY _                      ' __out_opt LPWSTR pOutput
 , OPTIONAL BYREF pDevMode AS DEVMODEW _                ' __in_opt CONST DEVMODEW * pDevMode
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO DeviceCapabilities = DeviceCapabilitiesW
#ELSE
   MACRO DeviceCapabilities = DeviceCapabilitiesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DrawEscape LIB "GDI32.DLL" ALIAS "DrawEscape" _
    (BYVAL hdc AS DWORD, BYVAL nEscape AS LONG, BYVAL cbInput AS LONG, _
    BYVAL lpszInData AS BYTE PTR) AS LONG
#ELSE
DECLARE FUNCTION DrawEscape IMPORT "GDI32.DLL" ALIAS "DrawEscape" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC    hdc
 , BYVAL iEscape AS LONG _                              ' __in int    iEscape
 , BYVAL cjIn AS LONG _                                 ' __in int    cjIn
 , BYREF lpIn AS ASCIIZ _                               ' __in LPCSTR lpIn
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION Ellipse IMPORT "GDI32.DLL" ALIAS "Ellipse" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 ) AS LONG                                              ' BOOL

'#if(WINVER >= 0x0400)
DECLARE FUNCTION EnumFontFamiliesExA IMPORT "GDI32.DLL" ALIAS "EnumFontFamiliesExA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS LOGFONTA _                        ' __in LPLOGFONTA lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCA lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumFontFamiliesExW IMPORT "GDI32.DLL" ALIAS "EnumFontFamiliesExW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS LOGFONTW  _                       ' __in LPLOGFONTW lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCW lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumFontFamiliesEx = EnumFontFamiliesExW
#ELSE
   MACRO EnumFontFamiliesEx = EnumFontFamiliesExA
#ENDIF

DECLARE FUNCTION EnumFontFamiliesA IMPORT "GDI32.DLL" ALIAS "EnumFontFamiliesA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS ASCIIZ _                          ' __in_opt LPCSTR lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCA lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumFontFamiliesW IMPORT "GDI32.DLL" ALIAS "EnumFontFamiliesW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS WSTRINGZ _                        ' __in_opt LPCWSTR lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCW lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumFontFamilies = EnumFontFamiliesW
#ELSE
   MACRO EnumFontFamilies = EnumFontFamiliesA
#ENDIF

DECLARE FUNCTION EnumFontsA IMPORT "GDI32.DLL" ALIAS "EnumFontsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS ASCIIZ _                          ' __in_opt LPCSTR lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCA lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumFontsW IMPORT "GDI32.DLL" ALIAS "EnumFontsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpLogfont AS WSTRINGZ _                        ' __in_opt LPCWSTR lpLogfont
 , BYVAL lpProc AS DWORD _                              ' __in FONTENUMPROCW lpProc
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumFonts = EnumFontsW
#ELSE
   MACRO EnumFonts = EnumFontsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumObjects LIB "GDI32.DLL" ALIAS "EnumObjects" _
    (BYVAL hDC AS DWORD, BYVAL n AS LONG, BYVAL lpGOBJEnumProc AS DWORD, _
    BYVAL lpVoid AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION EnumObjects IMPORT "GDI32.DLL" ALIAS "EnumObjects" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL nType AS LONG _                                ' __in int nType
 , BYVAL lpFunc AS DWORD _                              ' __in GOBJENUMPROC lpFunc
 , BYREF lParam AS ANY _                                ' __in LPVOID lParam
 ) AS LONG                                              ' int
#ENDIF

DECLARE FUNCTION EqualRgn IMPORT "GDI32.DLL" ALIAS "EqualRgn" ( _
   BYVAL hrgn1 AS DWORD _                               ' __in HRGN hrgn1
 , BYVAL hrgn2 AS DWORD _                               ' __in HRGN hrgn2
 ) AS LONG                                              ' BOOL

' Note The pvIn parameter has been declared as ANY because it can be
' a pointer to different data types and structures.
DECLARE FUNCTION Escape IMPORT "GDI32.DLL" ALIAS "Escape" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iEscape AS LONG _                              ' __in int iEscape
 , BYVAL cjIn AS LONG _                                 ' __in int cjIn
 , BYREF pvIn AS ANY _                                  ' __in LPCSTR pvIn
 , OPTIONAL BYREF pvOut AS ANY _                        ' __out_opt LPVOID pvOut
 ) AS LONG                                              ' int

' Note The lpInData and lpOutData parameters have been declared as ANY because
' can be pointers to different data types and structures.
DECLARE FUNCTION ExtEscape IMPORT "GDI32.DLL" ALIAS "ExtEscape" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iEscape AS LONG _                              ' __in int iEscape
 , BYVAL cjInput AS LONG _                              ' __in int cjInput
 , BYREF lpInData AS ANY _                              ' __in LPCSTR lpInData
 , BYVAL cjOutput AS LONG _                             ' __in int cjOutput
 , BYREF lpOutData AS ANY _                             ' __out LPSTR lpOutData
 ) AS LONG                                              ' int

DECLARE FUNCTION ExcludeClipRect IMPORT "GDI32.DLL" ALIAS "ExcludeClipRect" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 ) AS LONG                                              ' int

DECLARE FUNCTION ExtCreateRegion IMPORT "GDI32.DLL" ALIAS "ExtCreateRegion" ( _
   BYREF lpx AS XFORM _                                 ' __in_opt CONST XFORM * lpx
 , BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF lpData AS RGNDATA _                            ' __in CONST RGNDATA * lpData
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION ExtFloodFill IMPORT "GDI32.DLL" ALIAS "ExtFloodFill" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 , BYVAL type AS DWORD _                                ' __in UINT type
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FillRgn IMPORT "GDI32.DLL" ALIAS "FillRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL hbr AS DWORD _                                 ' __in HBRUSH hbr
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FloodFill IMPORT "GDI32.DLL" ALIAS "FloodFill" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FrameRgn IMPORT "GDI32.DLL" ALIAS "FrameRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL hbr AS DWORD _                                 ' __in HBRUSH hbr
 , BYVAL w AS LONG _                                    ' __in int w
 , BYVAL h AS LONG _                                    ' __in int h
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetROP2 IMPORT "GDI32.DLL" ALIAS "GetROP2" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetAspectRatioFilterEx IMPORT "GDI32.DLL" ALIAS "GetAspectRatioFilterEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpsize AS SIZE _                               ' __out LPSIZE lpsize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetBkColor IMPORT "GDI32.DLL" ALIAS "GetBkColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' COLORREF

'#if (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION GetDCBrushColor IMPORT "GDI32.DLL" ALIAS "GetDCBrushColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION GetDCPenColor IMPORT "GDI32.DLL" ALIAS "GetDCPenColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' COLORREF

'#endif

DECLARE FUNCTION GetBkMode IMPORT "GDI32.DLL" ALIAS "GetBkMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetBitmapBits IMPORT "GDI32.DLL" ALIAS "GetBitmapBits" ( _
   BYVAL hbit AS DWORD _                                ' __in HBITMAP hbit
 , BYVAL cb AS LONG _                                   ' __in LONG cb
 , BYREF lpvBits AS ANY _                               ' __out LPVOID lpvBits
 ) AS LONG                                              ' LONG

DECLARE FUNCTION GetBitmapDimensionEx IMPORT "GDI32.DLL" ALIAS "GetBitmapDimensionEx" ( _
   BYVAL hbit AS DWORD _                                ' __in HBITMAP hbit
 , BYREF lpsize AS SIZE _                               ' __out LPSIZE lpsize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetBoundsRect IMPORT "GDI32.DLL" ALIAS "GetBoundsRect" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprect AS RECT _                               ' __out LPRECT lprect
 , BYVAL flags AS DWORD _                               ' __in UINT flags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetBrushOrgEx IMPORT "GDI32.DLL" ALIAS "GetBrushOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppt AS POINT _                                ' __out LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharWidthA IMPORT "GDI32.DLL" ALIAS "GetCharWidthA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS LONG _                             ' __out LPINT lpBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharWidthW IMPORT "GDI32.DLL" ALIAS "GetCharWidthW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS LONG _                             ' __out LPINT lpBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCharWidth = GetCharWidthW
#ELSE
   MACRO GetCharWidth = GetCharWidthA
#ENDIF

DECLARE FUNCTION GetCharWidth32A IMPORT "GDI32.DLL" ALIAS "GetCharWidth32A" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS LONG _                             ' __out LPINT lpBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharWidth32W IMPORT "GDI32.DLL" ALIAS "GetCharWidth32W" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS LONG _                             ' __out LPINT lpBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCharWidth32 = GetCharWidth32W
#ELSE
   MACRO GetCharWidth32 = GetCharWidth32A
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetCharWidthFloatA LIB "GDI32.DLL" _
    ALIAS "GetCharWidthFloatA" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    BYVAL pxBuffer AS SINGLE PTR) AS LONG
#ELSE
DECLARE FUNCTION GetCharWidthFloatA IMPORT "GDI32.DLL" ALIAS "GetCharWidthFloatA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS SINGLE _                           ' __out PFLOAT lpBuffer
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetCharWidthFloatW LIB "GDI32.DLL" _
    ALIAS "GetCharWidthFloatW" (BYVAL hdc AS DWORD, _
    BYVAL dFirstChar AS DWORD, BYVAL dLastChar AS DWORD, _
    BYVAL pxBuffer AS SINGLE PTR) AS LONG
#ELSE
DECLARE FUNCTION GetCharWidthFloatW IMPORT "GDI32.DLL" ALIAS "GetCharWidthFloatW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpBuffer AS SINGLE _                           ' __out PFLOAT lpBuffer
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO GetCharWidthFloat = GetCharWidthFloatW
#ELSE
   MACRO GetCharWidthFloat = GetCharWidthFloatW
#ENDIF

DECLARE FUNCTION GetCharABCWidthsA IMPORT "GDI32.DLL" ALIAS "GetCharABCWidthsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL wFirst AS DWORD _                              ' __in UINT wFirst
 , BYVAL wLast AS DWORD _                               ' __in UINT wLast
 , BYREF lpABC AS ABC _                                 ' __out LPABC lpABC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharABCWidthsW IMPORT "GDI32.DLL" ALIAS "GetCharABCWidthsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL wFirst AS DWORD _                              ' __in UINT wFirst
 , BYVAL wLast AS DWORD _                               ' __in UINT wLast
 , BYREF lpABC AS ABC _                                 ' __out LPABC lpABC
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCharABCWidths = GetCharABCWidthsW
#ELSE
   MACRO GetCharABCWidths = GetCharABCWidthsA
#ENDIF

DECLARE FUNCTION GetCharABCWidthsFloatA IMPORT "GDI32.DLL" ALIAS "GetCharABCWidthsFloatA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpABC AS ABCFLOAT _                            ' __out LPABCFLOAT lpABC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharABCWidthsFloatW IMPORT "GDI32.DLL" ALIAS "GetCharABCWidthsFloatW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iFirst AS DWORD _                              ' __in UINT iFirst
 , BYVAL iLast AS DWORD _                               ' __in UINT iLast
 , BYREF lpABC AS ABCFLOAT _                            ' __out LPABCFLOAT lpABC
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetCharABCWidthsFloat = GetCharABCWidthsFloatW
#ELSE
   MACRO GetCharABCWidthsFloat = GetCharABCWidthsFloatW
#ENDIF

DECLARE FUNCTION GetClipBox IMPORT "GDI32.DLL" ALIAS "GetClipBox" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprect AS RECT _                               ' __out LPRECT lprect
 ) AS LONG                                              ' int

DECLARE FUNCTION GetClipRgn IMPORT "GDI32.DLL" ALIAS "GetClipRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 ) AS LONG                                              ' int

DECLARE FUNCTION GetMetaRgn IMPORT "GDI32.DLL" ALIAS "GetMetaRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 ) AS LONG                                              ' int

DECLARE FUNCTION GetCurrentObject IMPORT "GDI32.DLL" ALIAS "GetCurrentObject" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL type AS DWORD _                                ' __in UINT type
 ) AS DWORD                                             ' HGDIOBJ

DECLARE FUNCTION GetCurrentPositionEx IMPORT "GDI32.DLL" ALIAS "GetCurrentPositionEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppt AS POINT _                                ' __out LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDeviceCaps IMPORT "GDI32.DLL" ALIAS "GetDeviceCaps" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC hdc
 , BYVAL index AS LONG _                                ' __in int index
 ) AS LONG                                              ' int

DECLARE FUNCTION GetDIBits IMPORT "GDI32.DLL" ALIAS "GetDIBits" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hbm AS DWORD _                                 ' __in HBITMAP hbm
 , BYVAL start AS DWORD _                               ' __in UINT start
 , BYVAL cLines AS DWORD _                              ' __in UINT cLines
 , BYREF lpvBits AS ANY _                               ' __out_opt LPVOID lpvBits
 , BYREF lpbmi AS BITMAPINFO _                          ' __in_out LPBITMAPINFO lpbmi
 , BYVAL usage AS DWORD _                               ' __in UINT usage
 ) AS LONG                                              ' int

DECLARE FUNCTION GetFontData IMPORT "GDI32.DLL" ALIAS "GetFontData" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC     hdc
 , BYVAL dwTable AS DWORD _                             ' __in DWORD   dwTable
 , BYVAL dwOffset AS DWORD _                            ' __in DWORD   dwOffset
 , BYREF pvBuffer AS ANY _                              ' __out PVOID  pvBuffer
 , BYVAL cjBuffer AS DWORD _                            ' __in DWORD   cjBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetGlyphOutlineA IMPORT "GDI32.DLL" ALIAS "GetGlyphOutlineA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL uChar AS DWORD _                               ' __in UINT uChar
 , BYVAL fuFormat AS DWORD _                            ' __in UINT fuFormat
 , BYREF lpgm AS GLYPHMETRICS _                         ' __out LPGLYPHMETRICS lpgm
 , BYVAL cjBuffer AS DWORD _                            ' __in DWORD cjBuffer
 , BYREF pvBuffer AS ANY _                              ' __out LPVOID pvBuffer
 , BYREF lpmat2 AS MAT2 _                               ' __in CONST MAT2 *lpmat2
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetGlyphOutlineW IMPORT "GDI32.DLL" ALIAS "GetGlyphOutlineW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL uChar AS DWORD _                               ' __in UINT uChar
 , BYVAL fuFormat AS DWORD _                            ' __in UINT fuFormat
 , BYREF lpgm AS GLYPHMETRICS _                         ' __out LPGLYPHMETRICS lpgm
 , BYVAL cjBuffer AS DWORD _                            ' __in DWORD cjBuffer
 , BYREF pvBuffer AS ANY _                              ' __out LPVOID pvBuffer
 , BYREF lpmat2 AS MAT2 _                               ' __in CONST MAT2 *lpmat2
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetGlyphOutline = GetGlyphOutlineW
#ELSE
   MACRO GetGlyphOutline = GetGlyphOutlineA
#ENDIF

DECLARE FUNCTION GetGraphicsMode IMPORT "GDI32.DLL" ALIAS "GetGraphicsMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetMapMode IMPORT "GDI32.DLL" ALIAS "GetMapMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetMetaFileBitsEx IMPORT "GDI32.DLL" ALIAS "GetMetaFileBitsEx" ( _
   BYVAL hmf AS DWORD _                                 ' __in HMETAFILE hmf
 , BYVAL cbBuffer AS DWORD _                            ' __in UINT cbBuffer
 , BYREF lpData AS ANY _                                ' __out LPVOID lpData
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetMetaFileA IMPORT "GDI32.DLL" ALIAS "GetMetaFileA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HMETAFILE

DECLARE FUNCTION GetMetaFileW IMPORT "GDI32.DLL" ALIAS "GetMetaFileW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HMETAFILE

#IF %DEF(%UNICODE)
   MACRO GetMetaFile = GetMetaFileW
#ELSE
   MACRO GetMetaFile = GetMetaFileA
#ENDIF

DECLARE FUNCTION GetNearestColor IMPORT "GDI32.DLL" ALIAS "GetNearestColor" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION GetNearestPaletteIndex IMPORT "GDI32.DLL" ALIAS "GetNearestPaletteIndex" ( _
   BYVAL h AS DWORD _                                   ' __in HPALETTE h
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetObjectType IMPORT "GDI32.DLL" ALIAS "GetObjectType" ( _
   BYVAL h AS DWORD _                                   ' __in HGDIOBJ h
 ) AS DWORD                                             ' DWORD

#IF NOT %DEF(%NOTEXTMETRIC) ' -------------------------------------------------
'#ifndef NOTEXTMETRIC

DECLARE FUNCTION GetOutlineTextMetricsA IMPORT "GDI32.DLL" ALIAS "GetOutlineTextMetricsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL cjCopy AS DWORD _                              ' __in UINT cjCopy
 , BYREF potm AS OUTLINETEXTMETRICA _                   ' __out LPOUTLINETEXTMETRICA potm
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetOutlineTextMetricsW IMPORT "GDI32.DLL" ALIAS "GetOutlineTextMetricsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL cjCopy AS DWORD _                              ' __in UINT cjCopy
 , BYREF potm AS OUTLINETEXTMETRICW _                   ' __out LPOUTLINETEXTMETRICW potm
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetOutlineTextMetrics = GetOutlineTextMetricsW
#ELSE
   MACRO GetOutlineTextMetrics = GetOutlineTextMetricsA
#ENDIF

'#endif /* NOTEXTMETRIC */
#ENDIF   ' #IF NOT %DEF(%NOTEXTMETRIC) ----------------------------------------

DECLARE FUNCTION GetPaletteEntries IMPORT "GDI32.DLL" ALIAS "GetPaletteEntries" ( _
   BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL iStart AS DWORD _                              ' __in UINT iStart
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF pPalEntries AS PALETTEENTRY _                  ' __out LPPALETTEENTRY pPalEntries
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetPixel IMPORT "GDI32.DLL" ALIAS "GetPixel" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION GetPixelFormat IMPORT "GDI32.DLL" ALIAS "GetPixelFormat" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetPolyFillMode IMPORT "GDI32.DLL" ALIAS "GetPolyFillMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetRasterizerCaps IMPORT "GDI32.DLL" ALIAS "GetRasterizerCaps" ( _
   BYREF lpraststat AS RASTERIZER_STATUS _              ' __out LPRASTERIZER_STATUS lpraststat
 , BYVAL cjBytes AS DWORD _                             ' __in UINT cjBytes
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetRandomRgn IMPORT "GDI32.DLL" ALIAS "GetRandomRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL i AS LONG _                                    ' __in INT i
 ) AS LONG                                              ' int

DECLARE FUNCTION GetRegionData IMPORT "GDI32.DLL" ALIAS "GetRegionData" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 , BYREF lpRgnData AS RGNDATA _                         ' __out LPRGNDATA lpRgnData
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetRgnBox IMPORT "GDI32.DLL" ALIAS "GetRgnBox" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYREF lprc AS RECT _                                 ' __out LPRECT lprc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetStockObject IMPORT "GDI32.DLL" ALIAS "GetStockObject" ( _
   BYVAL i AS LONG _                                    ' __in int i
 ) AS DWORD                                             ' HGDIOBJ

DECLARE FUNCTION GetStretchBltMode IMPORT "GDI32.DLL" ALIAS "GetStretchBltMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetSystemPaletteEntries IMPORT "GDI32.DLL" ALIAS "GetSystemPaletteEntries" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC  hdc
 , BYVAL iStart AS DWORD _                              ' __in UINT iStart
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF pPalEntries AS PALETTEENTRY _                  ' __out LPPALETTEENTRY pPalEntries
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetSystemPaletteUse IMPORT "GDI32.DLL" ALIAS "GetSystemPaletteUse" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetTextCharacterExtra IMPORT "GDI32.DLL" ALIAS "GetTextCharacterExtra" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetTextAlign IMPORT "GDI32.DLL" ALIAS "GetTextAlign" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetTextColor IMPORT "GDI32.DLL" ALIAS "GetTextColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION GetTextExtentPointA IMPORT "GDI32.DLL" ALIAS "GetTextExtentPointA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS ASCIIZ _                           ' __in_ecount(c) LPCSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF lpsz AS SIZE _                                 ' __out LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextExtentPointW IMPORT "GDI32.DLL" ALIAS "GetTextExtentPointW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF lpsz AS SIZE _                                 ' __out LPSIZE lpsz
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetTextExtentPoint = GetTextExtentPointW
#ELSE
   MACRO GetTextExtentPoint = GetTextExtentPointA
#ENDIF

DECLARE FUNCTION GetTextExtentPoint32A IMPORT "GDI32.DLL" ALIAS "GetTextExtentPoint32A" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF psizl AS SIZE _                                ' __out LPSIZE psizl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextExtentPoint32W IMPORT "GDI32.DLL" ALIAS "GetTextExtentPoint32W" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF psizl AS SIZE _                                ' __out LPSIZE psizl
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetTextExtentPoint32 = GetTextExtentPoint32W
#ELSE
   MACRO GetTextExtentPoint32 = GetTextExtentPoint32A
#ENDIF

DECLARE FUNCTION GetTextExtentExPointA IMPORT "GDI32.DLL" ALIAS "GetTextExtentExPointA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpszString AS ASCIIZ _                         ' __in LPCSTR lpszString
 , BYVAL cchString AS LONG _                            ' __in int cchString
 , BYVAL nMaxExtent AS LONG _                           ' __in int nMaxExtent
 , BYREF lpnFit AS LONG _                               ' __out_opt LPINT lpnFit
 , BYREF lpnDx AS LONG _                                ' __out LPINT lpnDx
 , BYREF lpSize AS SIZE _                               ' __out LPSIZE lpSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextExtentExPointW IMPORT "GDI32.DLL" ALIAS "GetTextExtentExPointW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpszString AS WSTRINGZ _                       ' __in LPCWSTR lpszString
 , BYVAL cchString AS LONG _                            ' __in int cchString
 , BYVAL nMaxExtent AS LONG _                           ' __in int nMaxExtent
 , BYREF lpnFit AS LONG _                               ' __out_opt LPINT lpnFit
 , BYREF lpnDx AS LONG _                                ' __out LPINT lpnDx
 , BYREF lpSize AS SIZE _                               ' __out LPSIZE lpSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetTextExtentExPoint = GetTextExtentExPointW
#ELSE
   MACRO GetTextExtentExPoint = GetTextExtentExPointA
#ENDIF

'#if(WINVER >= 0x0400)
DECLARE FUNCTION GetTextCharset IMPORT "GDI32.DLL" ALIAS "GetTextCharset" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetTextCharsetInfo IMPORT "GDI32.DLL" ALIAS "GetTextCharsetInfo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpSig AS FONTSIGNATURE _                       ' __out_opt LPFONTSIGNATURE lpSig
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION TranslateCharsetInfo IMPORT "GDI32.DLL" ALIAS "TranslateCharsetInfo" ( _
   BYREF lpSrc AS DWORD _                               ' __in_out DWORD FAR *lpSrc
 , BYREF lpCs AS CHARSETINFO _                          ' __out LPCHARSETINFO lpCs
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFontLanguageInfo IMPORT "GDI32.DLL" ALIAS "GetFontLanguageInfo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCharacterPlacementA IMPORT "GDI32.DLL" ALIAS "GetCharacterPlacementA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYVAL nCount AS LONG _                               ' __in int nCount
 , BYVAL nMexExtent AS LONG _                           ' __in int nMexExtent
 , BYREF lpResults AS GCP_RESULTSA _                    ' __in_out LPGCP_RESULTSA lpResults
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetCharacterPlacementW IMPORT "GDI32.DLL" ALIAS "GetCharacterPlacementW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL nCount AS LONG _                               ' __in int nCount
 , BYVAL nMexExtent AS LONG _                           ' __in int nMexExtent
 , BYREF lpResults AS GCP_RESULTSW _                    ' __in_out LPGCP_RESULTSW lpResults
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetCharacterPlacement = GetCharacterPlacementW
#ELSE
   MACRO GetCharacterPlacement = GetCharacterPlacementA
#ENDIF

'#if (_WIN32_WINNT >= 0x0500)

' // Size = 4 bytes
TYPE WCRANGE WORD
   wcLow   AS WORD   ' WCHAR
   cGlyphs AS WORD   ' USHORT
END TYPE

' // Size = 20 bytes
TYPE GLYPHSET DWORD
   cbThis           AS DWORD     ' DWORD
   flAccel          AS DWORD     ' DWORD
   cGlyphsSupported AS DWORD     ' DWORD
   cRanges          AS DWORD     ' DWORD
   ranges(0)        AS WCRANGE   ' WCRANGE  ranges[1]
END TYPE

'/* flAccel flags for the GLYPHSET structure above */

%GS_8BIT_INDICES     = &H00000001???

'/* flags for GetGlyphIndices */

%GGI_MARK_NONEXISTING_GLYPHS  = &H0001???

DECLARE FUNCTION GetFontUnicodeRanges IMPORT "GDI32.DLL" ALIAS "GetFontUnicodeRanges" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , OPTIONAL BYREF lpgs AS ANY _                         ' __out_opt LPGLYPHSET lpgs
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetGlyphIndicesA IMPORT "GDI32.DLL" ALIAS "GetGlyphIndicesA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpstr AS ASCIIZ _                              ' __in LPCSTR lpstr
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF pgi AS WORD _                                  ' __out LPWORD pgi
 , BYVAL fl AS DWORD  _                                 ' __in DWORD fl
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetGlyphIndicesW IMPORT "GDI32.DLL" ALIAS "GetGlyphIndicesW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpstr AS WSTRINGZ _                            ' __in LPCWSTR lpstr
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF pgi AS WORD _                                  ' __out LPWORD pgi
 , BYVAL fl AS DWORD _                                  ' __in DWORD fl
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetGlyphIndices = GetGlyphIndicesW
#ELSE
   MACRO GetGlyphIndices = GetGlyphIndicesA
#ENDIF

DECLARE FUNCTION GetTextExtentPointI IMPORT "GDI32.DLL" ALIAS "GetTextExtentPointI" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pgiIn AS WORD _                                ' __in LPWORD pgiIn
 , BYVAL cgi AS LONG _                                  ' __in int cgi
 , BYREF psize AS SIZEL _                               ' __out LPSIZE psize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextExtentExPointI IMPORT "GDI32.DLL" ALIAS "GetTextExtentExPointI" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pgiIn AS WORD _                                ' __in LPWORD lpwszString [wrong, must be pgiIn]
 , BYVAL cgi AS LONG _                                  ' __in int cwchString [wrong, must be cgi]
 , BYVAL nMaxExtent AS LONG _                           ' __in int nMaxExtent
 , BYREF lpnFit AS LONG _                               ' __out_opt LPINT lpnFit
 , BYREF lpnDx AS LONG _                                ' __out LPINT lpnDx
 , BYREF lpSize AS SIZE _                               ' __out LPSIZE lpSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharWidthI IMPORT "GDI32.DLL" ALIAS "GetCharWidthI" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL giFirst AS DWORD _                             ' __in UINT giFirst
 , BYVAL cgi AS DWORD _                                 ' __in UINT cgi
 , BYREF pgi AS WORD _                                  ' __in LPWORD pgi
 , BYREF piWidths AS LONG _                             ' __out LPINT piWidths
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCharABCWidthsI IMPORT "GDI32.DLL" ALIAS "GetCharABCWidthsI" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC    hdc
 , BYVAL giFirst AS DWORD _                             ' __in UINT   giFirst
 , BYVAL cgi AS DWORD _                                 ' __in UINT   cgi
 , BYREF pgi AS WORD _                                  ' __in LPWORD pgi
 , BYREF pabc AS ABC _                                  ' __out LPABC  pabc
 ) AS LONG                                              ' BOOL

'#define STAMP_DESIGNVECTOR  (0x8000000 + 'd' + ('v' << 8))
'#define STAMP_AXESLIST      (0x8000000 + 'a' + ('l' << 8))
'#define MM_MAX_NUMAXES      16

%STAMP_DESIGNVECTOR = &H08007664   ' (0x8000000 + 'd' + ('v' << 8))
%STAMP_AXESLIST     = &H08006C61   ' (0x8000000 + 'a' + ('l' << 8))
%MM_MAX_NUMAXES     = 16

' // Size = 72 bytes
TYPE DESIGNVECTOR DWORD
  dvReserved AS DWORD                     ' DWORD
  dvNumAxes  AS DWORD                     ' DWORD
  dvValues(%MM_MAX_NUMAXES - 1) AS LONG   ' LONG   dvValues[MM_MAX_NUMAXES]
END TYPE

DECLARE FUNCTION AddFontResourceExA IMPORT "GDI32.DLL" ALIAS "AddFontResourceExA" ( _
   BYREF name AS ASCIIZ _                               ' __in LPCSTR name
 , BYVAL fl AS DWORD _                                  ' __in DWORD fl
 , BYVAL res AS DWORD _                                 ' __in PVOID res
 ) AS LONG                                              ' int

DECLARE FUNCTION AddFontResourceExW IMPORT "GDI32.DLL" ALIAS "AddFontResourceExW" ( _
   BYREF name AS WSTRINGZ _                             ' __in LPCWSTR name
 , BYVAL fl AS DWORD _                                  ' __in DWORD fl
 , BYVAL res AS DWORD _                                 ' __in PVOID res
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO AddFontResourceEx = AddFontResourceExW
#ELSE
   MACRO AddFontResourceEx = AddFontResourceExA
#ENDIF

DECLARE FUNCTION RemoveFontResourceExA IMPORT "GDI32.DLL" ALIAS "RemoveFontResourceExA" ( _
   BYREF name AS ASCIIZ _                               ' __in LPCSTR name
 , BYVAL fl AS DWORD _                                  ' __in DWORD fl
 , BYVAL pdv AS DWORD _                                 ' __in PVOID pdv
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveFontResourceExW IMPORT "GDI32.DLL" ALIAS "RemoveFontResourceExW" ( _
   BYREF name AS WSTRINGZ _                             ' __in LPCWSTR name
 , BYVAL fl AS DWORD _                                  ' __in DWORD fl
 , BYVAL pdv AS DWORD _                                 ' __in PVOID pdv
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RemoveFontResourceEx = RemoveFontResourceExW
#ELSE
   MACRO RemoveFontResourceEx = RemoveFontResourceExA
#ENDIF

DECLARE FUNCTION AddFontMemResourceEx IMPORT "GDI32.DLL" ALIAS "AddFontMemResourceEx" ( _
   BYVAL pFileView AS DWORD _                           ' __in PVOID pFileView
 , BYVAL cjSize AS DWORD _                              ' __in DWORD cjSize
 , BYVAL pvResrved AS DWORD _                           ' __in PVOID pvResrved
 , BYREF pNumFonts AS DWORD _                           ' __in DWORD* pNumFonts
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION RemoveFontMemResourceEx IMPORT "GDI32.DLL" ALIAS "RemoveFontMemResourceEx" ( _
   BYVAL h AS DWORD _                                   ' __in HANDLE h
 ) AS LONG                                              ' BOOL

%FR_PRIVATE  = &H10
%FR_NOT_ENUM = &H20

'// The actual size of the DESIGNVECTOR and ENUMLOGFONTEXDV structures
'// is determined by dvNumAxes,
'// MM_MAX_NUMAXES only detemines the maximal size allowed

%MM_MAX_AXES_NAMELEN = 16

' // Size = 24 bytes
TYPE AXISINFOA DWORD
   axMinValue AS LONG                            ' LONG
   axMaxValue AS LONG                            ' LONG
   axAxisName AS STRING * %MM_MAX_AXES_NAMELEN   ' BYTE   axAxisName[MM_MAX_AXES_NAMELEN]
END TYPE

' // Size = 40 bytes
TYPE AXISINFOW DWORD
   axMinValue AS LONG                             ' LONG
   axMaxValue AS LONG                             ' LONG
   axAxisName AS WSTRING * %MM_MAX_AXES_NAMELEN   ' WCHAR  axAxisName[MM_MAX_AXES_NAMELEN]
END TYPE

#IF %DEF(%UNICODE)
   MACRO AXISINFO = AXISINFOW
#ELSE
   MACRO AXISINFO = AXISINFOA
#ENDIF

' // Size = 392 bytes
TYPE AXESLISTA DWORD
   axlReserved AS DWORD                            ' DWORD
   axlNumAxes  AS DWORD                            ' DWORD
   axlAxisInfo (%MM_MAX_NUMAXES - 1) AS AXISINFOA  ' AXISINFOA axlAxisInfo[MM_MAX_NUMAXES]
END TYPE

' // Size = 648 bytes
TYPE AXESLISTW DWORD
   axlReserved AS DWORD                             ' DWORD
   axlNumAxes  AS DWORD                             ' DWORD
   axlAxisInfo (%MM_MAX_NUMAXES - 1) AS AXISINFOW   ' AXISINFOW axlAxisInfo[MM_MAX_NUMAXES]
END TYPE

#IF %DEF(%UNICODE)
   MACRO AXESLIST = AXESLISTW
#ELSE
   MACRO AXESLIST = AXESLISTA
#ENDIF

'// The actual size of the AXESLIST and ENUMTEXTMETRIC structure is
'// determined by axlNumAxes,
'// MM_MAX_NUMAXES only detemines the maximal size allowed

' // Size = 260 bytes
TYPE ENUMLOGFONTEXDVA DWORD
   elfEnumLogfontEx AS ENUMLOGFONTEX
   elfDesignVector  AS DESIGNVECTOR
END TYPE

' // Size = 420 bytes
TYPE ENUMLOGFONTEXDVW DWORD
   elfEnumLogfontEx AS ENUMLOGFONTEXW
   elfDesignVector  AS DESIGNVECTOR
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUMLOGFONTEXDV = ENUMLOGFONTEXDVW
#ELSE
   MACRO ENUMLOGFONTEXDV = ENUMLOGFONTEXDVA
#ENDIF

DECLARE FUNCTION CreateFontIndirectExA IMPORT "GDI32.DLL" ALIAS "CreateFontIndirectExA" ( _
   BYREF penumlfex AS ENUMLOGFONTEXDVA _                ' __in CONST ENUMLOGFONTEXDVA *penumlfex
 ) AS DWORD                                             ' HFONT

DECLARE FUNCTION CreateFontIndirectExW IMPORT "GDI32.DLL" ALIAS "CreateFontIndirectExW" ( _
   BYREF penumlfex AS ENUMLOGFONTEXDVW _                ' __in CONST ENUMLOGFONTEXDVW *penumlfex
 ) AS DWORD                                             ' HFONT

#IF %DEF(%UNICODE)
   MACRO CreateFontIndirectEx = CreateFontIndirectExW
#ELSE
   MACRO CreateFontIndirectEx = CreateFontIndirectExW
#ENDIF

#IF NOT %DEF(%NOTEXTMETRIC) ' -------------------------------------------------
'#ifndef NOTEXTMETRIC

' // Size = 488 bytes
TYPE ENUMTEXTMETRICA DWORD
   etmNewTextMetricEx AS NEWTEXTMETRICEX
   etmAxesList        AS AXESLIST
END TYPE

' // Size = 748 bytes
TYPE ENUMTEXTMETRICW DWORD
   etmNewTextMetricEx AS NEWTEXTMETRICEXW
   etmAxesList        AS AXESLISTW
END TYPE

#IF %DEF(%UNICODE)
   MACRO ENUMTEXTMETRIC = ENUMTEXTMETRICW
#ELSE
   MACRO ENUMTEXTMETRIC = ENUMTEXTMETRICA
#ENDIF

'#endif /* NOTEXTMETRIC */
#ENDIF   ' #IF NOT %DEF(%NOTEXTMETRIC) ----------------------------------------

'#endif // (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION GetViewportExtEx IMPORT "GDI32.DLL" ALIAS "GetViewportExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpsize AS SIZE _                               ' __out LPSIZE lpsize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetViewportOrgEx IMPORT "GDI32.DLL" ALIAS "GetViewportOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppoint AS POINT _                             ' __out LPPOINT lppoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowExtEx IMPORT "GDI32.DLL" ALIAS "GetWindowExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpsize AS SIZE _                               ' __out LPSIZE lpsize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowOrgEx IMPORT "GDI32.DLL" ALIAS "GetWindowOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppoint AS POINT _                             ' __out LPPOINT lppoint
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IntersectClipRect IMPORT "GDI32.DLL" ALIAS "IntersectClipRect" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 ) AS LONG                                              ' int

DECLARE FUNCTION InvertRgn IMPORT "GDI32.DLL" ALIAS "InvertRgn" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LineDDA IMPORT "GDI32.DLL" ALIAS "LineDDA" ( _
   BYVAL xStart AS LONG _                               ' __in int xStart
 , BYVAL yStart AS LONG _                               ' __in int yStart
 , BYVAL xEnd AS LONG _                                 ' __in int xEnd
 , BYVAL yEnd AS LONG _                                 ' __in int yEnd
 , BYVAL lpProc AS DWORD _                              ' __in LINEDDAPROC lpProc
 , OPTIONAL BYVAL data AS LONG _                        ' __in_opt LPARAM data
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LineTo IMPORT "GDI32.DLL" ALIAS "LineTo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION MaskBlt IMPORT "GDI32.DLL" ALIAS "MaskBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xDest AS LONG _                                ' __in int xDest
 , BYVAL yDest AS LONG _                                ' __in int yDest
 , BYVAL width AS LONG _                                ' __in int width
 , BYVAL height AS LONG _                               ' __in int height
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL hbmMask AS DWORD _                             ' __in HBITMAP hbmMask
 , BYVAL xMask AS LONG _                                ' __in int xMask
 , BYVAL yMask AS LONG _                                ' __in int yMask
 , BYVAL rop AS DWORD _                                 ' __in DWORD rop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PlgBlt IMPORT "GDI32.DLL" ALIAS "PlgBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYREF lpPoint AS POINT _                             ' __in_ecount(3) CONST POINT * lpPoint
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL width AS LONG _                                ' __in int width
 , BYVAL height AS LONG _                               ' __in int height
 , BYVAL hbmMask AS DWORD _                             ' __in_opt HBITMAP hbmMask
 , BYVAL xMask AS LONG _                                ' __in int xMask
 , BYVAL yMask AS LONG _                                ' __in int yMask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OffsetClipRgn IMPORT "GDI32.DLL" ALIAS "OffsetClipRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' int

DECLARE FUNCTION OffsetRgn IMPORT "GDI32.DLL" ALIAS "OffsetRgn" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' int

DECLARE FUNCTION PatBlt IMPORT "GDI32.DLL" ALIAS "PatBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL w AS LONG _                                    ' __in int w
 , BYVAL h AS LONG _                                    ' __in int h
 , BYVAL rop AS DWORD _                                 ' __in DWORD rop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Pie IMPORT "GDI32.DLL" ALIAS "Pie" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 , BYVAL xr1 AS LONG _                                  ' __in int xr1
 , BYVAL yr1 AS LONG _                                  ' __in int yr1
 , BYVAL xr2 AS LONG _                                  ' __in int xr2
 , BYVAL yr2 AS LONG _                                  ' __in int yr2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PlayMetaFile IMPORT "GDI32.DLL" ALIAS "PlayMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hmf AS DWORD _                                 ' __in HMETAFILE hmf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PaintRgn IMPORT "GDI32.DLL" ALIAS "PaintRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolyPolygon IMPORT "GDI32.DLL" ALIAS "PolyPolygon" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT *apt
 , BYREF asz AS LONG _                                  ' __in CONST INT *asz
 , BYVAL csz AS LONG _                                  ' __in int csz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PtInRegion IMPORT "GDI32.DLL" ALIAS "PtInRegion" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PtVisible IMPORT "GDI32.DLL" ALIAS "PtVisible" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RectInRegion IMPORT "GDI32.DLL" ALIAS "RectInRegion" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYREF lprect AS RECT _                               ' __in CONST RECT * lprect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RectVisible IMPORT "GDI32.DLL" ALIAS "RectVisible" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprect AS RECT _                               ' __in CONST RECT * lprect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Rectangle IMPORT "GDI32.DLL" ALIAS "Rectangle" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RestoreDC IMPORT "GDI32.DLL" ALIAS "RestoreDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL nSavedDC AS LONG _                             ' __in int nSavedDC
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ResetDCA IMPORT "GDI32.DLL" ALIAS "ResetDCA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpdm AS DEVMODEA _                             ' __in CONST DEVMODEA * lpdm
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION ResetDCW IMPORT "GDI32.DLL" ALIAS "ResetDCW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpdm AS DEVMODEW _                             ' __in CONST DEVMODEW * lpdm
 ) AS DWORD                                             ' HDC

#IF %DEF(%UNICODE)
   MACRO ResetDC = ResetDCW
#ELSE
   MACRO ResetDC = ResetDCA
#ENDIF

DECLARE FUNCTION RealizePalette IMPORT "GDI32.DLL" ALIAS "RealizePalette" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION RemoveFontResourceA IMPORT "GDI32.DLL" ALIAS "RemoveFontResourceA" ( _
   BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveFontResourceW IMPORT "GDI32.DLL" ALIAS "RemoveFontResourceW" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RemoveFontResource = RemoveFontResourceW
#ELSE
   MACRO RemoveFontResource = RemoveFontResourceA
#ENDIF

DECLARE FUNCTION RoundRect IMPORT "GDI32.DLL" ALIAS "RoundRect" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 , BYVAL width AS LONG _                                ' __in int width
 , BYVAL height AS LONG _                               ' __in int height
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ResizePalette IMPORT "GDI32.DLL" ALIAS "ResizePalette" ( _
   BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL n AS DWORD _                                   ' __in UINT n
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaveDC IMPORT "GDI32.DLL" ALIAS "SaveDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION SelectClipRgn IMPORT "GDI32.DLL" ALIAS "SelectClipRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , OPTIONAL BYVAL hrgn AS DWORD _                       ' __in_opt HRGN hrgn
 ) AS LONG                                              ' int

DECLARE FUNCTION ExtSelectClipRgn IMPORT "GDI32.DLL" ALIAS "ExtSelectClipRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hrgn AS DWORD _                                ' __in_opt HRGN hrgn
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int

DECLARE FUNCTION SetMetaRgn IMPORT "GDI32.DLL" ALIAS "SetMetaRgn" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION SelectObject IMPORT "GDI32.DLL" ALIAS "SelectObject" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL h AS DWORD _                                   ' __in HGDIOBJ h
 ) AS DWORD                                             ' HGDIOBJ

DECLARE FUNCTION SelectPalette IMPORT "GDI32.DLL" ALIAS "SelectPalette" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL bForceBkgd AS LONG _                           ' __in BOOL bForceBkgd
 ) AS DWORD                                             ' HPALETTE

DECLARE FUNCTION SetBkColor IMPORT "GDI32.DLL" ALIAS "SetBkColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF

'#if (_WIN32_WINNT >= 0x0500)
DECLARE FUNCTION SetDCBrushColor IMPORT "GDI32.DLL" ALIAS "SetDCBrushColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION SetDCPenColor IMPORT "GDI32.DLL" ALIAS "SetDCPenColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF
'#endif

DECLARE FUNCTION SetBkMode IMPORT "GDI32.DLL" ALIAS "SetBkMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int

DECLARE FUNCTION SetBitmapBits IMPORT "GDI32.DLL" ALIAS "SetBitmapBits" ( _
   BYVAL hbm AS DWORD _                                 ' __in HBITMAP hbm
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 , BYREF pvBits AS ANY _                                ' __in CONST VOID *pvBits
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SetBoundsRect IMPORT "GDI32.DLL" ALIAS "SetBoundsRect" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lprect AS RECT _                               ' __in_opt CONST RECT * lprect
 , BYVAL flags AS DWORD _                               ' __in UINT flags
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetDIBits IMPORT "GDI32.DLL" ALIAS "SetDIBits" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hbm AS DWORD _                                 ' __in HBITMAP hbm
 , BYVAL start AS DWORD _                               ' __in UINT start
 , BYVAL cLines AS DWORD _                              ' __in UINT cLines
 , BYREF lpBits AS ANY _                                ' __in CONST VOID *lpBits
 , BYREF lpbmi AS BITMAPINFO _                          ' __in CONST BITMAPINFO * lpbmi
 , BYVAL ColorUse AS DWORD _                            ' __in UINT ColorUse
 ) AS LONG                                              ' int

DECLARE FUNCTION SetDIBitsToDevice IMPORT "GDI32.DLL" ALIAS "SetDIBitsToDevice" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL xDest AS LONG _                                ' __in int xDest
 , BYVAL yDest AS LONG _                                ' __in int yDest
 , BYVAL w AS DWORD _                                   ' __in DWORD w
 , BYVAL h AS DWORD _                                   ' __in DWORD h
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL StartScan AS DWORD _                           ' __in UINT StartScan
 , BYVAL cLines AS DWORD _                              ' __in UINT cLines
 , BYREF lpvBits AS ANY _                               ' __in CONST VOID * lpvBits
 , BYREF lpbmi AS BITMAPINFO _                          ' __in CONST BITMAPINFO * lpbmi
 , BYVAL ColorUse AS DWORD _                            ' __in UINT ColorUse
 ) AS LONG                                              ' int

DECLARE FUNCTION SetMapperFlags IMPORT "GDI32.DLL" ALIAS "SetMapperFlags" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL flags AS DWORD _                               ' __in DWORD flags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetGraphicsMode IMPORT "GDI32.DLL" ALIAS "SetGraphicsMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iMode AS LONG _                                ' __in int iMode
 ) AS LONG                                              ' int

DECLARE FUNCTION SetMapMode IMPORT "GDI32.DLL" ALIAS "SetMapMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iMode AS LONG _                                ' __in int iMode
 ) AS LONG                                              ' int

'#if(WINVER >= 0x0500)
DECLARE FUNCTION SetLayout IMPORT "GDI32.DLL" ALIAS "SetLayout" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL l AS DWORD _                                   ' __in DWORD l
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLayout IMPORT "GDI32.DLL" ALIAS "GetLayout" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' DWORD
'#endif /* WINVER >= 0x0500 */

DECLARE FUNCTION SetMetaFileBitsEx IMPORT "GDI32.DLL" ALIAS "SetMetaFileBitsEx" ( _
   BYVAL cbBuffer AS DWORD _                            ' __in UINT cbBuffer
 , BYREF lpData AS BYTE _                               ' __in CONST BYTE *lpData
 ) AS DWORD                                             ' HMETAFILE

DECLARE FUNCTION SetPaletteEntries IMPORT "GDI32.DLL" ALIAS "SetPaletteEntries" ( _
   BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL iStart AS DWORD _                              ' __in UINT iStart
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF pPalEntries AS PALETTEENTRY _                  ' __in_ecount(cEntries) CONST PALETTEENTRY *pPalEntries)
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetPixel IMPORT "GDI32.DLL" ALIAS "SetPixel" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION SetPixelV IMPORT "GDI32.DLL" ALIAS "SetPixelV" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetPixelFormat IMPORT "GDI32.DLL" ALIAS "SetPixelFormat" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL format AS LONG _                               ' __in int format
 , BYREF ppfd AS PIXELFORMATDESCRIPTOR _                ' __in CONST PIXELFORMATDESCRIPTOR * ppfd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetPolyFillMode IMPORT "GDI32.DLL" ALIAS "SetPolyFillMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int

DECLARE FUNCTION StretchBlt IMPORT "GDI32.DLL" ALIAS "StretchBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xDest AS LONG _                                ' __in int xDest
 , BYVAL yDest AS LONG _                                ' __in int yDest
 , BYVAL wDest AS LONG _                                ' __in int wDest
 , BYVAL hDest AS LONG _                                ' __in int hDest
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL wSrc AS LONG _                                 ' __in int wSrc
 , BYVAL hSrc AS LONG _                                 ' __in int hSrc
 , BYVAL rop AS DWORD _                                 ' __in DWORD rop
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetRectRgn IMPORT "GDI32.DLL" ALIAS "SetRectRgn" ( _
   BYVAL hrgn AS DWORD _                                ' __in HRGN hrgn
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StretchDIBits IMPORT "GDI32.DLL" ALIAS "StretchDIBits" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL xDest AS LONG _                                ' __in int xDest
 , BYVAL yDest AS LONG _                                ' __in int yDest
 , BYVAL DestWidth AS LONG _                            ' __in int DestWidth
 , BYVAL DestHeight AS LONG _                           ' __in int DestHeight
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL SrcWidth AS LONG _                             ' __in int SrcWidth
 , BYVAL SrcHeight AS LONG _                            ' __in int SrcHeight
 , BYREF lpBits AS ANY _                                ' __in CONST VOID * lpBits
 , BYREF lpbmi AS BITMAPINFO _                          ' __in CONST BITMAPINFO * lpbmi
 , BYVAL iUsage AS DWORD _                              ' __in UINT iUsage
 , BYVAL rop AS DWORD _                                 ' __in DWORD rop
 ) AS LONG                                              ' int

DECLARE FUNCTION SetROP2 IMPORT "GDI32.DLL" ALIAS "SetROP2" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL rop2 AS LONG _                                 ' __in int rop2
 ) AS LONG                                              ' int

DECLARE FUNCTION SetStretchBltMode IMPORT "GDI32.DLL" ALIAS "SetStretchBltMode" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int

DECLARE FUNCTION SetSystemPaletteUse IMPORT "GDI32.DLL" ALIAS "SetSystemPaletteUse" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL use AS DWORD _                                 ' __in UINT use
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetTextCharacterExtra IMPORT "GDI32.DLL" ALIAS "SetTextCharacterExtra" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL extra AS LONG _                                ' __in int extra
 ) AS LONG                                              ' int

DECLARE FUNCTION SetTextColor IMPORT "GDI32.DLL" ALIAS "SetTextColor" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL color AS DWORD _                               ' __in COLORREF color
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION SetTextAlign IMPORT "GDI32.DLL" ALIAS "SetTextAlign" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL align AS DWORD _                               ' __in UINT align
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetTextJustification IMPORT "GDI32.DLL" ALIAS "SetTextJustification" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL extra AS LONG _                                ' __in int extra
 , BYVAL count AS LONG _                                ' __in int count
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UpdateColors IMPORT "GDI32.DLL" ALIAS "UpdateColors" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

'#if (WINVER >= 0x0400)

'#ifdef  COMBOX_SANDBOX

'#if (_WIN32_WINNT >= 0x0600)

'typedef PVOID   (WINAPI *GDIMARSHALLOC)(DWORD dwSize, __in LPVOID pGdiRef);

'typedef HRESULT (WINAPI *DDRAWMARSHCALLBACKMARSHAL)(__in HGDIOBJ hGdiObj, __in LPVOID pGdiRef, __out LPVOID *ppDDrawRef);
'typedef HRESULT (WINAPI *DDRAWMARSHCALLBACKUNMARSHAL)(__in LPVOID pData, __out HDC *phdc, __out LPVOID *ppDDrawRef);
'typedef HRESULT (WINAPI *DDRAWMARSHCALLBACKRELEASE)(__in LPVOID pDDrawRef);

%GDIREGISTERDDRAWPACKETVERSION   = &H1

' // Size = 20 bytes
TYPE GDIREGISTERDDRAWPACKET DWORD
   dwSize         AS DWORD   ' DWORD
   dwVersion      AS DWORD   ' DWORD
   pfnDdMarshal   AS DWORD   ' DDRAWMARSHCALLBACKMARSHAL
   pfnDdUnmarshal AS DWORD   ' DDRAWMARSHCALLBACKUNMARSHAL
   pfnDdRelease   AS DWORD   ' DDRAWMARSHCALLBACKRELEASE
END TYPE

'WINGDIAPI BOOL    WINAPI   GdiRegisterDdraw(__in PGDIREGISTERDDRAWPACKET pPacket, __out GDIMARSHALLOC *ppfnGdiAlloc);

'WINGDIAPI ULONG   WINAPI   GdiMarshalSize(VOID);
'WINGDIAPI VOID    WINAPI   GdiMarshal(DWORD dwProcessIdTo, __in HGDIOBJ hGdiObj, __in_out PVOID pData, ULONG ulFlags);
'WINGDIAPI HGDIOBJ WINAPI   GdiUnmarshal(__in PVOID pData, ULONG ulFlags);

'#endif // (_WIN32_WINNT >= 0x0600)

'#endif  // COMBOX_SANDBOX

'#if (WINVER >= 0x0400)

'//
'// image blt
'//

'typedef USHORT COLOR16;

' // Size = 16 bytes
TYPE TRIVERTEX WORD
   x     AS LONG   ' LONG
   y     AS LONG   ' LONG
   Red   AS WORD   ' COLOR16
   Green AS WORD   ' COLOR16
   Blue  AS WORD   ' COLOR16
   Alpha AS WORD   ' COLOR16
END TYPE

' // Size = 12 bytes
TYPE GRADIENT_TRIANGLE DWORD
   Vertex1 AS DWORD   ' ULONG
   Vertex2 AS DWORD   ' ULONG
   Vertex3 AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE GRADIENT_RECT DWORD
   UpperLeft  AS DWORD   ' ULONG
   LowerRight AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE BLENDFUNCTION BYTE
   BlendOp             AS BYTE
   BlendFlags          AS BYTE
   SourceConstantAlpha AS BYTE
   AlphaFormat         AS BYTE
END TYPE

'//
'// currentlly defined blend function
'//

%AC_SRC_OVER             = &H00

'//
'// alpha format flags
'//

%AC_SRC_ALPHA            = &H01

' Note: The last parameter was declared as DWORD in old versions of PB's WIN32API.INC
' because earlier versions of PB couldn't pass an structure by value.
' This forced the use of CVDWD to convert the four byte structure into a DWORD.
DECLARE FUNCTION AlphaBlend IMPORT "MSIMG32.DLL" ALIAS "AlphaBlend" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xoriginDest AS LONG _                          ' __in int xoriginDest
 , BYVAL yoriginDest AS LONG _                          ' __in int yoriginDest
 , BYVAL wDest AS LONG _                                ' __in int wDest
 , BYVAL hDest AS LONG _                                ' __in int hDest
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xoriginSrc AS LONG _                           ' __in int xoriginSrc
 , BYVAL yoriginSrc AS LONG _                           ' __in int yoriginSrc
 , BYVAL wSrc AS LONG _                                 ' __in int wSrc
 , BYVAL hSrc AS LONG _                                 ' __in int hSrc
 , BYVAL ftn AS BLENDFUNCTION _                         ' __in BLENDFUNCTION ftn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TransparentBlt IMPORT "MSIMG32.DLL" ALIAS "TransparentBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xoriginDest AS LONG _                          ' __in int xoriginDest
 , BYVAL yoriginDest AS LONG _                          ' __in int yoriginDest
 , BYVAL wDest AS LONG _                                ' __in int wDest
 , BYVAL hDest AS LONG _                                ' __in int hDest
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xoriginSrc AS LONG _                           ' __in int xoriginSrc
 , BYVAL yoriginSrc AS LONG _                           ' __in int yoriginSrc
 , BYVAL wSrc AS LONG _                                 ' __in int wSrc
 , BYVAL hSrc AS LONG _                                 ' __in int hSrc
 , BYVAL crTransparent AS DWORD _                       ' __in UINT crTransparent
 ) AS LONG                                              ' BOOL

'//
'// gradient drawing modes
'//

%GRADIENT_FILL_RECT_H   = &H00000000???
%GRADIENT_FILL_RECT_V   = &H00000001???
%GRADIENT_FILL_TRIANGLE = &H00000002???
%GRADIENT_FILL_OP_FLAG  = &H000000ff???

DECLARE FUNCTION GradientFill IMPORT "MSIMG32.DLL" ALIAS "GradientFill" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pVertex AS TRIVERTEX _                         ' __in PTRIVERTEX pVertex
 , BYVAL nVertex AS DWORD _                             ' __in ULONG nVertex
 , BYREF pMesh AS ANY _                                 ' __in PVOID pMesh
 , BYVAL nMesh AS DWORD _                               ' __in ULONG nMesh
 , BYVAL ulMode AS DWORD _                              ' __in ULONG ulMode
 ) AS LONG                                              ' BOOL

'#endif

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)


'WINGDIAPI BOOL  WINAPI GdiAlphaBlend(__in HDC hdcDest, __in int xoriginDest, __in int yoriginDest, __in int wDest, __in int hDest, __in HDC hdcSrc, __in int xoriginSrc, __in int yoriginSrc, __in int wSrc, __in int hSrc, __in BLENDFUNCTION ftn);
DECLARE FUNCTION GdiAlphaBlend IMPORT "GDI32.DLL" ALIAS "GdiAlphaBlend" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xoriginDest AS LONG _                          ' __in int xoriginDest
 , BYVAL yoriginDest AS LONG _                          ' __in int yoriginDest
 , BYVAL wDest AS LONG _                                ' __in int wDest
 , BYVAL hDest AS LONG _                                ' __in int hDest
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xoriginSrc AS LONG _                           ' __in int xoriginSrc
 , BYVAL yoriginSrc AS LONG _                           ' __in int yoriginSrc
 , BYVAL wSrc AS LONG _                                 ' __in int wSrc
 , BYVAL hSrc AS LONG _                                 ' __in int hSrc
 , BYVAL ftn AS BLENDFUNCTION _                         ' __in BLENDFUNCTION ftn
 ) AS LONG                                              ' BOOL

'WINGDIAPI BOOL  WINAPI GdiTransparentBlt(__in HDC hdcDest,__in int xoriginDest, __in int yoriginDest, __in int wDest, __in int hDest, __in HDC hdcSrc,
'                                           __in int xoriginSrc, __in int yoriginSrc, __in int wSrc, __in int hSrc, __in UINT crTransparent);
DECLARE FUNCTION GdiTransparentBlt IMPORT "GDI32.DLL" ALIAS "GdiTransparentBlt" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdcDest
 , BYVAL xoriginDest AS LONG _                          ' __in int xoriginDest
 , BYVAL yoriginDest AS LONG _                          ' __in int yoriginDest
 , BYVAL wDest AS LONG _                                ' __in int wDest
 , BYVAL hDest AS LONG _                                ' __in int hDest
 , BYVAL hdcSrc AS DWORD _                              ' __in HDC hdcSrc
 , BYVAL xoriginSrc AS LONG _                           ' __in int xoriginSrc
 , BYVAL yoriginSrc AS LONG _                           ' __in int yoriginSrc
 , BYVAL wSrc AS LONG _                                 ' __in int wSrc
 , BYVAL hSrc AS LONG _                                 ' __in int hSrc
 , BYVAL crTransparent AS DWORD _                       ' __in UINT crTransparent
 ) AS LONG                                              ' BOOL

'WINGDIAPI BOOL  WINAPI GdiGradientFill( __in HDC hdc,
'                                        __in PTRIVERTEX pVertex,
'                                        __in ULONG nVertex,
'                                        __in PVOID pMesh,
'                                        __in ULONG nCount,
'                                        __in ULONG ulMode);
DECLARE FUNCTION GdiGradientFill IMPORT "GDI32.DLL" ALIAS "GdiGradientFill" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pVertex AS TRIVERTEX _                         ' __in PTRIVERTEX pVertex
 , BYVAL nVertex AS DWORD _                             ' __in ULONG nVertex
 , BYREF pMesh AS ANY _                                 ' __in PVOID pMesh
 , BYVAL nMesh AS DWORD _                               ' __in ULONG nMesh
 , BYVAL ulMode AS DWORD _                              ' __in ULONG ulMode
 ) AS LONG                                              ' BOOL

'#endif

#IF NOT %DEF(%NOMETAFILE) ' ---------------------------------------------------
'#ifndef NOMETAFILE

DECLARE FUNCTION PlayMetaFileRecord IMPORT "GDI32.DLL" ALIAS "PlayMetaFileRecord" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpHandleTable AS HANDLETABLE _                 ' __in LPHANDLETABLE lpHandleTable
 , BYREF lpMR AS METARECORD _                           ' __in LPMETARECORD lpMR
 , BYVAL noObjs AS DWORD _                              ' __in UINT noObjs
 ) AS LONG                                              ' BOOL

'typedef int (CALLBACK* MFENUMPROC)( __in HDC hdc, __in_ecount(nObj) HANDLETABLE FAR* lpht, __in METARECORD FAR* lpMR, __in int nObj, __in_opt LPARAM param);

DECLARE FUNCTION EnumMetaFile IMPORT "GDI32.DLL" ALIAS "EnumMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hmf AS DWORD _                                 ' __in HMETAFILE hmf
 , BYVAL proc AS DWORD _                                ' __in MFENUMPROC proc
 , OPTIONAL BYVAL param AS LONG _                       ' __in_opt LPARAM param
 ) AS LONG                                              ' BOOL

'typedef int (CALLBACK* ENHMFENUMPROC)(__in HDC hdc, __in_ecount(nHandles) HANDLETABLE FAR* lpht, __in CONST ENHMETARECORD * lpmr, __in int nHandles, __in_opt LPARAM data);

'// Enhanced Metafile Function Declarations

DECLARE FUNCTION CloseEnhMetaFile IMPORT "GDI32.DLL" ALIAS "CloseEnhMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' HENHMETAFILE

DECLARE FUNCTION CopyEnhMetaFileA IMPORT "GDI32.DLL" ALIAS "CopyEnhMetaFileA" ( _
   BYVAL hEnh AS DWORD _                                ' __in HENHMETAFILE hEnh
 , OPTIONAL BYREF lpFileName AS ASCIIZ _                ' __in_opt LPCSTR lpFileName
 ) AS DWORD                                             ' HENHMETAFILE

DECLARE FUNCTION CopyEnhMetaFileW IMPORT "GDI32.DLL" ALIAS "CopyEnhMetaFileW" ( _
   BYVAL hEnh AS DWORD _                                ' __in HENHMETAFILE hEnh
 , OPTIONAL BYREF lpFileName AS WSTRINGZ _              ' __in_opt LPCWSTR lpFileName
 ) AS DWORD                                             ' HENHMETAFILE

#IF %DEF(%UNICODE)
   MACRO CopyEnhMetaFile = CopyEnhMetaFileW
#ELSE
   MACRO CopyEnhMetaFile = CopyEnhMetaFileA
#ENDIF

DECLARE FUNCTION CreateEnhMetaFileA IMPORT "GDI32.DLL" ALIAS "CreateEnhMetaFileA" ( _
   OPTIONAL BYVAL hdc AS DWORD _                        ' __in_opt HDC hdc
 , OPTIONAL BYREF lpFilename AS ASCIIZ _                ' __in_opt LPCSTR lpFilename
 , OPTIONAL BYREF lprc AS RECT _                        ' __in_opt CONST RECT *lprc
 , OPTIONAL BYREF lpDesc AS ASCIIZ _                    ' __in_opt LPCSTR lpDesc
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION CreateEnhMetaFileW IMPORT "GDI32.DLL" ALIAS "CreateEnhMetaFileW" ( _
   OPTIONAL BYVAL hdc AS DWORD _                        ' __in_opt HDC hdc
 , OPTIONAL BYREF lpFilename AS WSTRINGZ _              ' __in_opt LPCWSTR lpFilename
 , OPTIONAL BYREF lprc AS RECT _                        ' __in_opt CONST RECT *lprc
 , OPTIONAL BYREF lpDesc AS WSTRINGZ _                  ' __in_opt LPCWSTR lpDesc
 ) AS DWORD                                             ' HDC

#IF %DEF(%UNICODE)
   MACRO CreateEnhMetaFile = CreateEnhMetaFileW
#ELSE
   MACRO CreateEnhMetaFile = CreateEnhMetaFileA
#ENDIF

DECLARE FUNCTION DeleteEnhMetaFile IMPORT "GDI32.DLL" ALIAS "DeleteEnhMetaFile" ( _
   BYVAL hmf AS DWORD _                                 ' __in HENHMETAFILE hmf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumEnhMetaFile IMPORT "GDI32.DLL" ALIAS "EnumEnhMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC hdc
 , BYVAL hmf AS DWORD _                                 ' __in HENHMETAFILE hmf
 , BYVAL proc AS DWORD _                                ' __in ENHMFENUMPROC proc
 , OPTIONAL BYREF param AS ANY _                        ' __in_opt LPVOID param
 , OPTIONAL BYREF lpRect AS RECT _                      ' __in_opt CONST RECT * lpRect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetEnhMetaFileA IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 ) AS DWORD                                             ' HENHMETAFILE

DECLARE FUNCTION GetEnhMetaFileW IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 ) AS DWORD                                             ' HENHMETAFILE

#IF %DEF(%UNICODE)
   MACRO GetEnhMetaFile = GetEnhMetaFileW
#ELSE
   MACRO GetEnhMetaFile = GetEnhMetaFileA
#ENDIF

DECLARE FUNCTION GetEnhMetaFileBits IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileBits" ( _
   BYVAL hEMF AS DWORD _                                ' __in HENHMETAFILE hEMF
 , BYVAL nSize AS DWORD _                               ' __in UINT nSize
 , BYREF lpData AS BYTE _                               ' __out_bcount_opt(nSize) LPBYTE lpData
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetEnhMetaFileDescriptionA IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileDescriptionA" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL cchBuffer AS DWORD _                           ' __in UINT cchBuffer
 , BYREF lpszDescription AS ASCIIZ _                    ' __out LPCSTR lpszDescription
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetEnhMetaFileDescriptionW IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileDescriptionW" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL cchBuffer AS DWORD _                           ' __in UINT cchBuffer
 , BYREF lpszDescription AS WSTRINGZ _                  ' __out LPWSTR lpszDescription
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetEnhMetaFileDescription = GetEnhMetaFileDescriptionW
#ELSE
   MACRO GetEnhMetaFileDescription = GetEnhMetaFileDescriptionA
#ENDIF

DECLARE FUNCTION GetEnhMetaFileHeader IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFileHeader" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL nSize AS DWORD _                               ' __in UINT nSize
 , BYREF lpEnhMetaHeader AS ENHMETAHEADER _             ' __out LPENHMETAHEADER lpEnhMetaHeader
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetEnhMetaFilePaletteEntries IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFilePaletteEntries" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL nNumEntries AS DWORD _                         ' __in UINT nNumEntries
 , BYREF lpPaletteEntries AS PALETTEENTRY _             ' __out LPPALETTEENTRY lpPaletteEntries
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetEnhMetaFilePixelFormat IMPORT "GDI32.DLL" ALIAS "GetEnhMetaFilePixelFormat" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL cbBuffer AS DWORD _                            ' __in UINT cbBuffer
 , BYREF ppfd AS PIXELFORMATDESCRIPTOR _                ' __out_bcount_opt(cbBuffer) PIXELFORMATDESCRIPTOR *ppfd
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetWinMetaFileBits IMPORT "GDI32.DLL" ALIAS "GetWinMetaFileBits" ( _
   BYVAL hemf AS DWORD _                                ' __in HENHMETAFILE hemf
 , BYVAL cbData16 AS DWORD _                            ' __in UINT cbData16
 , BYREF pData16 AS BYTE _                              ' __out LPBYTE pData16
 , BYVAL iMapMode AS LONG _                             ' __in INT iMapMode
 , BYVAL hdcRef AS DWORD _                              ' __in HDC hdcRef
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION PlayEnhMetaFile IMPORT "GDI32.DLL" ALIAS "PlayEnhMetaFile" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hmf AS DWORD _                                 ' __in HENHMETAFILE hmf
 , BYREF lprect AS RECT _                               ' __in CONST RECT * lprect
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PlayEnhMetaFileRecord IMPORT "GDI32.DLL" ALIAS "PlayEnhMetaFileRecord" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pht AS HANDLETABLE _                           ' __in LPHANDLETABLE pht
 , BYREF pmr AS ENHMETARECORD _                         ' __in CONST ENHMETARECORD *pmr
 , BYVAL cht AS DWORD _                                 ' __in UINT cht
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetEnhMetaFileBits IMPORT "GDI32.DLL" ALIAS "SetEnhMetaFileBits" ( _
   BYVAL nSize AS DWORD _                               ' __in UINT nSize
 , BYREF pb AS BYTE _                                   ' __in CONST BYTE * pb
 ) AS DWORD                                             ' HENHMETAFILE

DECLARE FUNCTION SetWinMetaFileBits IMPORT "GDI32.DLL" ALIAS "SetWinMetaFileBits" ( _
   BYVAL nSize AS DWORD _                               ' __in UINT nSize
 , BYREF lpMeta16Data AS BYTE _                         ' __in CONST BYTE *lpMeta16Data
 , OPTIONAL BYVAL hdcRef AS DWORD _                     ' __in_opt HDC hdcRef
 , OPTIONAL BYREF lpMFP AS METAFILEPICT _               ' __in_opt CONST METAFILEPICT *lpMFP
 ) AS DWORD                                             ' HENHMETAFILE

DECLARE FUNCTION GdiComment IMPORT "GDI32.DLL" ALIAS "GdiComment" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL nSize AS DWORD _                               ' __in UINT nSize
 , BYVAL lpData AS BYTE PTR _                           ' __in CONST BYTE *lpData
 ) AS LONG                                              ' BOOL

'#endif  /* NOMETAFILE */
#ENDIF   ' #IF NOT %DEF(%NOMETAFILE) ------------------------------------------

#IF NOT %DEF(%NOTEXTMETRIC) ' -------------------------------------------------
'#ifndef NOTEXTMETRIC

DECLARE FUNCTION GetTextMetricsA IMPORT "GDI32.DLL" ALIAS "GetTextMetricsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpMetrics AS TEXTMETRICA _                     ' __out LPTEXTMETRICA lptm
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextMetricsW IMPORT "GDI32.DLL" ALIAS "GetTextMetricsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lptm AS TEXTMETRICW _                          ' __out LPTEXTMETRICW lptm
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetTextMetrics = GetTextMetricsW
#ELSE
   MACRO GetTextMetrics = GetTextMetricsA
#ENDIF

#ENDIF   ' #IF NOT %DEF(%NOTEXTMETRIC) ' --------------------------------------

'/* new GDI */

' // Size = 84 bytes
TYPE DIBSECTION DWORD
  dsBm           AS BITMAP
  dsBmih         AS BITMAPINFOHEADER
  dsBitfields(2) AS DWORD   ' DWORD  dsBitfields[3]
  dshSection     AS DWORD   ' HANDLE
  dsOffset       AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION AngleArc IMPORT "GDI32.DLL" ALIAS "AngleArc" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL r AS DWORD _                                   ' __in DWORD r
 , BYVAL StartAngle AS SINGLE _                         ' __in FLOAT StartAngle
 , BYVAL SweepAngle AS SINGLE _                         ' __in FLOAT SweepAngle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolyPolyline IMPORT "GDI32.DLL" ALIAS "PolyPolyline" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT *apt
 , BYREF asz AS DWORD _                                 ' __in CONST DWORD *asz
 , BYVAL csz AS DWORD _                                 ' __in DWORD csz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWorldTransform IMPORT "GDI32.DLL" ALIAS "GetWorldTransform" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpxf AS XFORM _                                ' __out LPXFORM lpxf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWorldTransform IMPORT "GDI32.DLL" ALIAS "SetWorldTransform" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpxf AS XFORM _                                ' __in CONST XFORM * lpxf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ModifyWorldTransform IMPORT "GDI32.DLL" ALIAS "ModifyWorldTransform" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpxf AS XFORM _                                ' __in_opt CONST XFORM * lpxf
 , BYVAL mode AS DWORD _                                ' __in DWORD mode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CombineTransform IMPORT "GDI32.DLL" ALIAS "CombineTransform" ( _
   BYREF lpxfOut AS XFORM _                             ' __out LPXFORM lpxfOut
 , BYREF lpxf1 AS XFORM _                               ' __in CONST XFORM *lpxf1
 , BYREF lpxf2 AS XFORM _                               ' __in CONST XFORM *lpxf2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateDIBSection IMPORT "GDI32.DLL" ALIAS "CreateDIBSection" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC hdc
 , BYREF lpbmi AS BITMAPINFO _                          ' __in CONST BITMAPINFO *lpbmi
 , BYVAL usage AS DWORD _                               ' __in UINT usage
 , BYVAL ppvBits AS DWORD _                             ' __out VOID **ppvBits
 , BYVAL hSection AS DWORD _                            ' __in_opt HANDLE hSection
 , BYVAL offset AS DWORD _                              ' __in DWORD offset
 ) AS DWORD                                             ' HBITMAP

DECLARE FUNCTION GetDIBColorTable IMPORT "GDI32.DLL" ALIAS "GetDIBColorTable" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC  hdc
 , BYVAL iStart AS DWORD _                              ' __in UINT iStart
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF prgbq AS RGBQUAD _                             ' __out RGBQUAD *prgbq
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetDIBColorTable IMPORT "GDI32.DLL" ALIAS "SetDIBColorTable" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC  hdc
 , BYVAL iStart AS DWORD _                              ' __in UINT iStart
 , BYVAL cEntries AS DWORD _                            ' __in UINT cEntries
 , BYREF prgbq AS RGBQUAD _                             ' __in CONST RGBQUAD *prgbq
 ) AS DWORD                                             ' UINT

'/* Flags value for COLORADJUSTMENT */
%CA_NEGATIVE   = &H0001??
%CA_LOG_FILTER = &H0002??

'/* IlluminantIndex values */
%ILLUMINANT_DEVICE_DEFAULT = 0
%ILLUMINANT_A              = 1
%ILLUMINANT_B              = 2
%ILLUMINANT_C              = 3
%ILLUMINANT_D50            = 4
%ILLUMINANT_D55            = 5
%ILLUMINANT_D65            = 6
%ILLUMINANT_D75            = 7
%ILLUMINANT_F2             = 8
%ILLUMINANT_MAX_INDEX      = %ILLUMINANT_F2

%ILLUMINANT_TUNGSTEN       = %ILLUMINANT_A
%ILLUMINANT_DAYLIGHT       = %ILLUMINANT_C
%ILLUMINANT_FLUORESCENT    = %ILLUMINANT_F2
%ILLUMINANT_NTSC           = %ILLUMINANT_C

'/* Min and max for RedGamma, GreenGamma, BlueGamma */
'#define RGB_GAMMA_MIN               (WORD)02500
'#define RGB_GAMMA_MAX               (WORD)65000

%RGB_GAMMA_MIN = 2500??
%RGB_GAMMA_MAX = 65000??

'/* Min and max for ReferenceBlack and ReferenceWhite */
'#define REFERENCE_WHITE_MIN         (WORD)6000
'#define REFERENCE_WHITE_MAX         (WORD)10000
'#define REFERENCE_BLACK_MIN         (WORD)0
'#define REFERENCE_BLACK_MAX         (WORD)4000

%REFERENCE_WHITE_MIN = 6000??
%REFERENCE_WHITE_MAX = 10000??
%REFERENCE_BLACK_MIN = 0??
%REFERENCE_BLACK_MAX = 4000??

'/* Min and max for Contrast, Brightness, Colorfulness, RedGreenTint */
'#define COLOR_ADJ_MIN               (SHORT)-100
'#define COLOR_ADJ_MAX               (SHORT)100

%COLOR_ADJ_MIN = -100%
%COLOR_ADJ_MAX = 100%

' // Size = 24 bytes
TYPE COLORADJUSTMENT WORD
   caSize            AS WORD
   caFlags           AS WORD
   caIlluminantIndex AS WORD
   caRedGamma        AS WORD
   caGreenGamma      AS WORD
   caBlueGamma       AS WORD
   caReferenceBlack  AS WORD
   caReferenceWhite  AS WORD
   caContrast        AS INTEGER   ' SHORT
   caBrightness      AS INTEGER   ' SHORT
   caColorfulness    AS INTEGER   ' SHORT
   caRedGreenTint    AS INTEGER   ' SHORT
END TYPE

DECLARE FUNCTION SetColorAdjustment IMPORT "GDI32.DLL" ALIAS "SetColorAdjustment" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpca AS COLORADJUSTMENT _                      ' __in CONST COLORADJUSTMENT *lpca
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorAdjustment IMPORT "GDI32.DLL" ALIAS "GetColorAdjustment" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpca AS COLORADJUSTMENT _                      ' __out LPCOLORADJUSTMENT lpca
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateHalftonePalette IMPORT "GDI32.DLL" ALIAS "CreateHalftonePalette" ( _
   BYVAL hdc AS DWORD _                                 ' __in_opt HDC hdc
 ) AS DWORD                                             ' HPALETTE

'#ifdef STRICT
'typedef BOOL (CALLBACK* ABORTPROC)( __in HDC, __in int);
'#else
'typedef FARPROC ABORTPROC;
'#endif

' // Size = 20 bytes
TYPE DOCINFOA DWORD
   cbSize       AS LONG         ' int
   lpszDocName  AS ASCIIZ PTR   ' LPCSTR
   lpszOutput   AS ASCIIZ PTR   ' LPCSTR
'#if (WINVER >= 0x0400)
   lpszDataType AS ASCIIZ PTR   ' LPCSTR
   fwType       AS DWORD        ' DWORD
'#endif /* WINVER */
END TYPE

' // Size = 20 bytes
TYPE DOCINFOW DWORD
   cbSize       AS LONG           ' int
   lpszDocName  AS WSTRINGZ PTR   ' LPCWSTR
   lpszOutput   AS WSTRINGZ PTR   ' LPCWSTR
'#if (WINVER >= 0x0400)
   lpszDataType AS WSTRINGZ PTR   ' LPCWSTR
   fwType       AS DWORD          ' DWORD
'#endif /* WINVER */
END TYPE

#IF %DEF(%UNICODE)
   MACRO DOCINFO = DOCINFOW
#ELSE
   MACRO DOCINFO = DOCINFOA
#ENDIF

'#if(WINVER >= 0x0400)
%DI_APPBANDING            = &H00000001???
%DI_ROPS_READ_DESTINATION = &H00000002???
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION StartDocA IMPORT "GDI32.DLL" ALIAS "StartDocA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpdi AS DOCINFOA _                             ' __in CONST DOCINFOA *lpdi
 ) AS LONG                                              ' int

DECLARE FUNCTION StartDocW IMPORT "GDI32.DLL" ALIAS "StartDocW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc,
 , BYREF lpdi AS DOCINFOW _                             ' __in CONST DOCINFOW *lpdi
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO StartDoc = StartDocW
#ELSE
   MACRO StartDoc = StartDocA
#ENDIF

DECLARE FUNCTION EndDoc IMPORT "GDI32.DLL" ALIAS "EndDoc" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION StartPage IMPORT "GDI32.DLL" ALIAS "StartPage" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION EndPage IMPORT "GDI32.DLL" ALIAS "EndPage" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION AbortDoc IMPORT "GDI32.DLL" ALIAS "AbortDoc" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION SetAbortProc IMPORT "GDI32.DLL" ALIAS "SetAbortProc" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL proc AS DWORD _                                ' __in ABORTPROC proc
 ) AS LONG                                              ' int

DECLARE FUNCTION AbortPath IMPORT "GDI32.DLL" ALIAS "AbortPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ArcTo IMPORT "GDI32.DLL" ALIAS "ArcTo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL left AS LONG _                                 ' __in int left
 , BYVAL top AS LONG _                                  ' __in int top
 , BYVAL right AS LONG _                                ' __in int right
 , BYVAL bottom AS LONG _                               ' __in int bottom
 , BYVAL xr1 AS LONG _                                  ' __in int xr1
 , BYVAL yr1 AS LONG _                                  ' __in int yr1
 , BYVAL xr2 AS LONG _                                  ' __in int xr2
 , BYVAL yr2 AS LONG _                                  ' __in int yr2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION BeginPath IMPORT "GDI32.DLL" ALIAS "BeginPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CloseFigure IMPORT "GDI32.DLL" ALIAS "CloseFigure" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EndPath IMPORT "GDI32.DLL" ALIAS "EndPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FillPath IMPORT "GDI32.DLL" ALIAS "FillPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlattenPath IMPORT "GDI32.DLL" ALIAS "FlattenPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPath IMPORT "GDI32.DLL" ALIAS "GetPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __out LPPOINT apt
 , BYREF aj AS BYTE _                                   ' __out LPBYTE aj
 , BYVAL cpt AS DWORD _                                 ' int cpt
 ) AS LONG                                              ' int

DECLARE FUNCTION PathToRegion IMPORT "GDI32.DLL" ALIAS "PathToRegion" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION PolyDraw IMPORT "GDI32.DLL" ALIAS "PolyDraw" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT * apt
 , BYREF aj AS BYTE _                                   ' __in CONST BYTE * aj
 , BYVAL cpt AS LONG _                                  ' __in int cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SelectClipPath IMPORT "GDI32.DLL" ALIAS "SelectClipPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetArcDirection IMPORT "GDI32.DLL" ALIAS "SetArcDirection" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dir AS LONG _                                  ' __in int dir
 ) AS LONG                                              ' int

DECLARE FUNCTION SetMiterLimit IMPORT "GDI32.DLL" ALIAS "SetMiterLimit" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL limit AS SINGLE  _                             ' __in FLOAT limit
 , OPTIONAL BYREF old AS SINGLE _                       ' __out_opt PFLOAT old
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrokeAndFillPath IMPORT "GDI32.DLL" ALIAS "StrokeAndFillPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION StrokePath IMPORT "GDI32.DLL" ALIAS "StrokePath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WidenPath IMPORT "GDI32.DLL" ALIAS "WidenPath" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExtCreatePen IMPORT "GDI32.DLL" ALIAS "ExtCreatePen" ( _
   BYVAL iPenStyle AS DWORD _                           ' __in DWORD iPenStyle
 , BYVAL cWidth AS DWORD _                              ' __in DWORD cWidth
 , BYREF plbrush AS LOGBRUSH _                          ' __in CONST LOGBRUSH *plbrush
 , BYVAL cStyle AS DWORD _                              ' __in DWORD cStyle
 , BYREF pstyle AS DWORD _                              ' __in CONST DWORD *pstyle
 ) AS DWORD                                             ' HPEN

DECLARE FUNCTION GetMiterLimit IMPORT "GDI32.DLL" ALIAS "GetMiterLimit" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYREF plimit AS SINGLE _                             ' __out PFLOAT plimit
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetArcDirection IMPORT "GDI32.DLL" ALIAS "GetArcDirection" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' int

DECLARE FUNCTION GetObjectA IMPORT "GDI32.DLL" ALIAS "GetObjectA" ( _
   BYVAL h AS DWORD _                                   ' __in HANDLE h
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF pv AS ANY _                                    ' __out LPVOID pv
 ) AS LONG                                              ' int

DECLARE FUNCTION GetObjectW IMPORT "GDI32.DLL" ALIAS "GetObjectW" ( _
   BYVAL h AS DWORD _                                   ' __in HANDLE h
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF pv AS ANY _                                    ' __out LPVOID pv
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetObject = GetObjectW
#ELSE
   MACRO GetObject = GetObjectA
#ENDIF

DECLARE FUNCTION MoveToEx IMPORT "GDI32.DLL" ALIAS "MoveToEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

FUNCTION MoveTo (BYVAL hDC AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
   FUNCTION = MoveToEx(hDC, x, y, BYVAL %NULL)
END FUNCTION

DECLARE FUNCTION TextOutA IMPORT "GDI32.DLL" ALIAS "TextOutA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYREF lpString AS ASCIIZ  _                          ' __in LPCSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TextOutW IMPORT "GDI32.DLL" ALIAS "TextOutW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO TextOut = TextOutW
#ELSE
   MACRO TextOut = TextOutA
#ENDIF

DECLARE FUNCTION ExtTextOutA IMPORT "GDI32.DLL" ALIAS "ExtTextOutA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL options AS DWORD _                             ' __in UINT options
 , BYREF lprect AS RECT _                               ' __in_opt CONST RECT * lprect
 , BYREF lpString AS ASCIIZ _                           ' __in LPCSTR lpString
 , BYVAL c AS DWORD _                                   ' __in UINT c
 , BYREF lpDx AS LONG _                                 ' __in CONST INT * lpDx
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ExtTextOutW IMPORT "GDI32.DLL" ALIAS "ExtTextOutW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL options AS DWORD _                             ' __in UINT options
 , BYREF lprect AS RECT _                               ' __in_opt CONST RECT * lprect
 , BYREF lpString AS WSTRINGZ _                         ' __in LPCWSTR lpString
 , BYVAL c AS DWORD _                                   ' __in UINT c
 , BYREF lpDx AS LONG _                                 ' __in CONST INT * lpDx
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ExtTextOut = ExtTextOutW
#ELSE
   MACRO ExtTextOut = ExtTextOutA
#ENDIF

DECLARE FUNCTION PolyTextOutA IMPORT "GDI32.DLL" ALIAS "PolyTextOutA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF ppt AS POLYTEXTA _                             ' __in CONST POLYTEXTA * ppt
 , BYVAL nstrings AS LONG _                             ' __in int nstrings
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolyTextOutW IMPORT "GDI32.DLL" ALIAS "PolyTextOutW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF ppt AS POLYTEXTW _                             ' __in CONST POLYTEXTW * ppt
 , BYVAL nstrings AS LONG _                             ' __in int nstrings
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PolyTextOut = PolyTextOutW
#ELSE
   MACRO PolyTextOut = PolyTextOutA
#ENDIF

DECLARE FUNCTION CreatePolygonRgn IMPORT "GDI32.DLL" ALIAS "CreatePolygonRgn" ( _
   BYREF pptl AS POINT _                                ' __in CONST POINT *pptl
 , BYVAL cPoint AS LONG _                               ' __in int cPoint
 , BYVAL iMode AS LONG _                                ' __in int iMode
 ) AS DWORD                                             ' HRGN

DECLARE FUNCTION DPtoLP IMPORT "GDI32.DLL" ALIAS "DPtoLP" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppt AS POINT _                                ' __in LPPOINT lppt
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION LPtoDP IMPORT "GDI32.DLL" ALIAS "LPtoDP" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppt AS POINT _                                ' __in LPPOINT lppt
 , BYVAL c AS LONG _                                    ' __in int c
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Polygon IMPORT "GDI32.DLL" ALIAS "Polygon" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT *apt
 , BYVAL cpt AS LONG _                                  ' __in int cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Polyline IMPORT "GDI32.DLL" ALIAS "Polyline" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT *apt
 , BYVAL cpt AS LONG _                                  ' __in int cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolyBezier IMPORT "GDI32.DLL" ALIAS "PolyBezier" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT * apt
 , BYVAL cpt AS DWORD _                                 ' __in DWORD cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolyBezierTo IMPORT "GDI32.DLL" ALIAS "PolyBezierTo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT * apt
 , BYVAL cpt AS DWORD _                                 ' __in DWORD cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PolylineTo IMPORT "GDI32.DLL" ALIAS "PolylineTo" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF apt AS POINT _                                 ' __in CONST POINT * apt
 , BYVAL cpt AS DWORD _                                 ' __in DWORD cpt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetViewportExtEx IMPORT "GDI32.DLL" ALIAS "SetViewportExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lpsz AS SIZE _                        ' __out_opt LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetViewportOrgEx IMPORT "GDI32.DLL" ALIAS "SetViewportOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowExtEx IMPORT "GDI32.DLL" ALIAS "SetWindowExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lpsz AS SIZE _                        ' __out_opt LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetWindowOrgEx IMPORT "GDI32.DLL" ALIAS "SetWindowOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OffsetViewportOrgEx IMPORT "GDI32.DLL" ALIAS "OffsetViewportOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OffsetWindowOrgEx IMPORT "GDI32.DLL" ALIAS "OffsetWindowOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScaleViewportExtEx IMPORT "GDI32.DLL" ALIAS "ScaleViewportExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL xn AS LONG _                                   ' __in int xn
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL yn AS LONG _                                   ' __in int yn
 , BYVAL yd AS LONG _                                   ' __in int yd
 , OPTIONAL BYREF lpsz AS SIZE _                        ' __out_opt LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ScaleWindowExtEx IMPORT "GDI32.DLL" ALIAS "ScaleWindowExtEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL xn AS LONG _                                   ' __in int xn
 , BYVAL xd AS LONG _                                   ' __in int xd
 , BYVAL yn AS LONG _                                   ' __in int yn
 , BYVAL yd AS LONG _                                   ' __in int yd
 , OPTIONAL BYREF lpsz AS SIZE _                        ' __out_opt LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetBitmapDimensionEx IMPORT "GDI32.DLL" ALIAS "SetBitmapDimensionEx" ( _
   BYVAL hbm AS DWORD _                                 ' __in HBITMAP hbm
 , BYVAL w AS LONG _                                    ' __in int w
 , BYVAL h AS LONG _                                    ' __in int h
 , OPTIONAL BYREF lpsz AS SIZE _                        ' __out_opt LPSIZE lpsz
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetBrushOrgEx IMPORT "GDI32.DLL" ALIAS "SetBrushOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF lppt AS POINT _                       ' __out_opt LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetTextFaceA IMPORT "GDI32.DLL" ALIAS "GetTextFaceA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF lpName AS ASCIIZ _                             ' __out LPSTR lpName
 ) AS LONG                                              ' int

DECLARE FUNCTION GetTextFaceW IMPORT "GDI32.DLL" ALIAS "GetTextFaceW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL c AS LONG _                                    ' __in int c
 , BYREF lpName AS WSTRINGZ _                           ' __out LPWSTR lpName
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO GetTextFace = GetTextFaceW
#ELSE
   MACRO GetTextFace = GetTextFaceA
#ENDIF

%FONTMAPPER_MAX = 10

' // Size = 8 bytes
TYPE KERNINGPAIR DWORD FILL
   wFirst      AS WORD   ' WORD
   wSecond     AS WORD   ' WORD
   iKernAmount AS LONG   ' int
END TYPE

DECLARE FUNCTION GetKerningPairsA IMPORT "GDI32.DLL" ALIAS "GetKerningPairsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL nPairs AS DWORD _                              ' __in DWORD nPairs
 , BYREF lpKernPair AS KERNINGPAIR _                    ' __out LPKERNINGPAIR   lpKernPair
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetKerningPairsW IMPORT "GDI32.DLL" ALIAS "GetKerningPairsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL nPairs AS DWORD _                              ' __in DWORD nPairs
 , BYREF lpKernPair AS KERNINGPAIR _                    ' __out LPKERNINGPAIR   lpKernPair
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetKerningPairs = GetKerningPairsW
#ELSE
   MACRO GetKerningPairs = GetKerningPairsA
#ENDIF

DECLARE FUNCTION GetDCOrgEx IMPORT "GDI32.DLL" ALIAS "GetDCOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lppt AS POINT _                                ' __out LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FixBrushOrgEx IMPORT "GDI32.DLL" ALIAS "FixBrushOrgEx" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , OPTIONAL BYREF ptl AS POINT _                        ' __in_opt LPPOINT ptl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnrealizeObject IMPORT "GDI32.DLL" ALIAS "UnrealizeObject" ( _
   BYVAL h AS DWORD _                                   ' __in HGDIOBJ h
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GdiFlush IMPORT "GDI32.DLL" ALIAS "GdiFlush" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GdiSetBatchLimit IMPORT "GDI32.DLL" ALIAS "GdiSetBatchLimit" ( _
   BYVAL dw AS DWORD _                                  ' __in DWORD dw
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GdiGetBatchLimit IMPORT "GDI32.DLL" ALIAS "GdiGetBatchLimit" ( _
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0400)

%ICM_OFF            = 1
%ICM_ON             = 2
%ICM_QUERY          = 3
%ICM_DONE_OUTSIDEDC = 4

'typedef int (CALLBACK* ICMENUMPROCA)(LPSTR, LPARAM);
'typedef int (CALLBACK* ICMENUMPROCW)(LPWSTR, LPARAM);

DECLARE FUNCTION SetICMMode IMPORT "GDI32.DLL" ALIAS "SetICMMode" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYVAL mode AS LONG _                                 ' __in int mode
 ) AS LONG                                              ' int

DECLARE FUNCTION CheckColorsInGamut IMPORT "GDI32.DLL" ALIAS "CheckColorsInGamut" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpRGBTriple AS ANY _                           ' __in LPVOID lpRGBTriple
 , BYREF dlpBuffer AS ANY _                             ' __out LPVOID dlpBuffer
 , BYVAL nCount AS DWORD _                              ' __in DWORD nCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorSpace IMPORT "GDI32.DLL" ALIAS "GetColorSpace" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' HCOLORSPACE

DECLARE FUNCTION GetLogColorSpaceA IMPORT "GDI32.DLL" ALIAS "GetLogColorSpaceA" ( _
   BYVAL hColorSpace AS DWORD _                         ' __in HCOLORSPACE hColorSpace
 , BYREF lpBuffer AS LOGCOLORSPACEA _                   ' __out LPLOGCOLORSPACEA lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetLogColorSpaceW IMPORT "GDI32.DLL" ALIAS "GetLogColorSpaceW" ( _
   BYVAL hColorSpace AS DWORD _                         ' __in HCOLORSPACE hColorSpace
 , BYREF lpBuffer AS LOGCOLORSPACEW _                   ' __out LPLOGCOLORSPACEW lpBuffer
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetLogColorSpace = GetLogColorSpaceW
#ELSE
   MACRO GetLogColorSpace = GetLogColorSpaceA
#ENDIF

DECLARE FUNCTION CreateColorSpaceA IMPORT "GDI32.DLL" ALIAS "CreateColorSpaceA" ( _
   BYREF lplcs AS LOGCOLORSPACEA _                      ' __in LPLOGCOLORSPACEA lplcs
 ) AS DWORD                                             ' HCOLORSPACE

DECLARE FUNCTION CreateColorSpaceW IMPORT "GDI32.DLL" ALIAS "CreateColorSpaceW" ( _
   BYREF lplcs AS LOGCOLORSPACEW _                      ' __in LPLOGCOLORSPACEW lplcs
 ) AS DWORD                                             ' HCOLORSPACE

#IF %DEF(%UNICODE)
   MACRO CreateColorSpace = CreateColorSpaceW
#ELSE
   MACRO CreateColorSpace = CreateColorSpaceA
#ENDIF

DECLARE FUNCTION SetColorSpace IMPORT "GDI32.DLL" ALIAS "SetColorSpace" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hcs AS DWORD _                                 ' __in HCOLORSPACE hcs
 ) AS DWORD                                             ' HCOLORSPACE

DECLARE FUNCTION DeleteColorSpace IMPORT "GDI32.DLL" ALIAS "DeleteColorSpace" ( _
   BYVAL hcs AS DWORD _                                 ' __in HCOLORSPACE hcs
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetICMProfileA IMPORT "GDI32.DLL" ALIAS "GetICMProfileA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pBufSize AS DWORD _                            ' __in_out LPDWORD pBufSize
 , BYREF pszFilename AS ASCIIZ _                        ' __out LPSTR pszFilename
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetICMProfileW IMPORT "GDI32.DLL" ALIAS "GetICMProfileW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pBufSize AS DWORD _                            ' __in_out LPDWORD pBufSize
 , BYREF pszFilename AS WSTRINGZ _                      ' __out LPWSTR pszFilename
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetICMProfile = GetICMProfileW
#ELSE
   MACRO GetICMProfile = GetICMProfileA
#ENDIF

DECLARE FUNCTION SetICMProfileA IMPORT "GDI32.DLL" ALIAS "SetICMProfileA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpFileName AS ASCIIZ _                         ' __in LPSTR lpFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetICMProfileW IMPORT "GDI32.DLL" ALIAS "SetICMProfileW" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPWSTR lpFileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetICMProfile = SetICMProfileW
#ELSE
   MACRO SetICMProfile = SetICMProfileA
#ENDIF

DECLARE FUNCTION GetDeviceGammaRamp IMPORT "GDI32.DLL" ALIAS "GetDeviceGammaRamp" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpRamp AS ANY _                                ' __out_bcount(3*256*2) LPVOID lpRamp
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetDeviceGammaRamp IMPORT "GDI32.DLL" ALIAS "SetDeviceGammaRamp" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF lpRamp AS ANY _                                ' __in_bcount(3*256*2)  LPVOID lpRamp
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ColorMatchToTarget IMPORT "GDI32.DLL" ALIAS "ColorMatchToTarget" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hdcTarget AS DWORD  _                          ' __in HDC hdcTarget
 , BYVAL action AS DWORD _                              ' __in DWORD action
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumICMProfilesA IMPORT "GDI32.DLL" ALIAS "EnumICMProfilesA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL proc AS DWORD _                                ' __in ICMENUMPROCA proc
 , OPTIONAL BYVAL param AS LONG _                       ' __in_opt LPARAM param
 ) AS LONG                                              ' int

DECLARE FUNCTION EnumICMProfilesW IMPORT "GDI32.DLL" ALIAS "EnumICMProfilesW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL proc AS DWORD _                                ' __in ICMENUMPROCW proc
 , OPTIONAL BYVAL param AS LONG _                       ' __in_opt LPARAM param
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO EnumICMProfiles = EnumICMProfilesW
#ELSE
   MACRO EnumICMProfiles = EnumICMProfilesA
#ENDIF

DECLARE FUNCTION UpdateICMRegKeyA IMPORT "GDI32.DLL" ALIAS "UpdateICMRegKeyA" ( _
   BYVAL reserved AS DWORD _                            ' __reserved DWORD reserved
 , BYREF lpszCMID AS ASCIIZ _                           ' __in LPSTR lpszCMID
 , BYREF lpszFileName AS ASCIIZ _                       ' __in LPSTR lpszFileName
 , BYVAL command AS DWORD _                             ' __in UINT command
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UpdateICMRegKeyW IMPORT "GDI32.DLL" ALIAS "UpdateICMRegKeyW" ( _
   BYVAL reserved AS DWORD _                            ' __reserved DWORD reserved
 , BYREF lpszCMID AS WSTRINGZ _                         ' __in LPSTR lpszCMID
 , BYREF lpszFileName AS WSTRINGZ _                     ' __in LPSTR lpszFileName
 , BYVAL command AS DWORD _                             ' __in UINT command
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UpdateICMRegKey = UpdateICMRegKeyW
#ELSE
   MACRO UpdateICMRegKey = UpdateICMRegKeyA
#ENDIF

'#endif /* WINVER >= 0x0400 */

'#if (WINVER >= 0x0500)
DECLARE FUNCTION ColorCorrectPalette IMPORT "GDI32.DLL" ALIAS "ColorCorrectPalette" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hPal AS DWORD _                                ' __in HPALETTE hPal
 , BYVAL deFirst AS DWORD _                             ' __in DWORD deFirst
 , BYVAL num AS DWORD _                                 ' __in DWORD num
 ) AS LONG                                              ' LONG
'#endif

#IF NOT %DEF(%NOMETAFILE) ' ---------------------------------------------------
'#ifndef NOMETAFILE

'// Enhanced metafile constants.

'#ifndef _MAC
'#define ENHMETA_SIGNATURE       0x464D4520
%ENHMETA_SIGNATURE = &H464D4520
'#else
'#define ENHMETA_SIGNATURE       0x20454D46
'#endif

'// Stock object flag used in the object handle index in the enhanced
'// metafile records.
'// E.g. The object handle index (META_STOCK_OBJECT | BLACK_BRUSH)
'// represents the stock object BLACK_BRUSH.

%ENHMETA_STOCK_OBJECT = &H80000000???

'// Enhanced metafile record types.

%EMR_HEADER                  = 1
%EMR_POLYBEZIER              = 2
%EMR_POLYGON                 = 3
%EMR_POLYLINE                = 4
%EMR_POLYBEZIERTO            = 5
%EMR_POLYLINETO              = 6
%EMR_POLYPOLYLINE            = 7
%EMR_POLYPOLYGON             = 8
%EMR_SETWINDOWEXTEX          = 9
%EMR_SETWINDOWORGEX          = 10
%EMR_SETVIEWPORTEXTEX        = 11
%EMR_SETVIEWPORTORGEX        = 12
%EMR_SETBRUSHORGEX           = 13
%EMR_EOF                     = 14
%EMR_SETPIXELV               = 15
%EMR_SETMAPPERFLAGS          = 16
%EMR_SETMAPMODE              = 17
%EMR_SETBKMODE               = 18
%EMR_SETPOLYFILLMODE         = 19
%EMR_SETROP2                 = 20
%EMR_SETSTRETCHBLTMODE       = 21
%EMR_SETTEXTALIGN            = 22
%EMR_SETCOLORADJUSTMENT      = 23
%EMR_SETTEXTCOLOR            = 24
%EMR_SETBKCOLOR              = 25
%EMR_OFFSETCLIPRGN           = 26
%EMR_MOVETOEX                = 27
%EMR_SETMETARGN              = 28
%EMR_EXCLUDECLIPRECT         = 29
%EMR_INTERSECTCLIPRECT       = 30
%EMR_SCALEVIEWPORTEXTEX      = 31
%EMR_SCALEWINDOWEXTEX        = 32
%EMR_SAVEDC                  = 33
%EMR_RESTOREDC               = 34
%EMR_SETWORLDTRANSFORM       = 35
%EMR_MODIFYWORLDTRANSFORM    = 36
%EMR_SELECTOBJECT            = 37
%EMR_CREATEPEN               = 38
%EMR_CREATEBRUSHINDIRECT     = 39
%EMR_DELETEOBJECT            = 40
%EMR_ANGLEARC                = 41
%EMR_ELLIPSE                 = 42
%EMR_RECTANGLE               = 43
%EMR_ROUNDRECT               = 44
%EMR_ARC                     = 45
%EMR_CHORD                   = 46
%EMR_PIE                     = 47
%EMR_SELECTPALETTE           = 48
%EMR_CREATEPALETTE           = 49
%EMR_SETPALETTEENTRIES       = 50
%EMR_RESIZEPALETTE           = 51
%EMR_REALIZEPALETTE          = 52
%EMR_EXTFLOODFILL            = 53
%EMR_LINETO                  = 54
%EMR_ARCTO                   = 55
%EMR_POLYDRAW                = 56
%EMR_SETARCDIRECTION         = 57
%EMR_SETMITERLIMIT           = 58
%EMR_BEGINPATH               = 59
%EMR_ENDPATH                 = 60
%EMR_CLOSEFIGURE             = 61
%EMR_FILLPATH                = 62
%EMR_STROKEANDFILLPATH       = 63
%EMR_STROKEPATH              = 64
%EMR_FLATTENPATH             = 65
%EMR_WIDENPATH               = 66
%EMR_SELECTCLIPPATH          = 67
%EMR_ABORTPATH               = 68

%EMR_GDICOMMENT              = 70
%EMR_FILLRGN                 = 71
%EMR_FRAMERGN                = 72
%EMR_INVERTRGN               = 73
%EMR_PAINTRGN                = 74
%EMR_EXTSELECTCLIPRGN        = 75
%EMR_BITBLT                  = 76
%EMR_STRETCHBLT              = 77
%EMR_MASKBLT                 = 78
%EMR_PLGBLT                  = 79
%EMR_SETDIBITSTODEVICE       = 80
%EMR_STRETCHDIBITS           = 81
%EMR_EXTCREATEFONTINDIRECTW  = 82
%EMR_EXTTEXTOUTA             = 83
%EMR_EXTTEXTOUTW             = 84
%EMR_POLYBEZIER16            = 85
%EMR_POLYGON16               = 86
%EMR_POLYLINE16              = 87
%EMR_POLYBEZIERTO16          = 88
%EMR_POLYLINETO16            = 89
%EMR_POLYPOLYLINE16          = 90
%EMR_POLYPOLYGON16           = 91
%EMR_POLYDRAW16              = 92
%EMR_CREATEMONOBRUSH         = 93
%EMR_CREATEDIBPATTERNBRUSHPT = 94
%EMR_EXTCREATEPEN            = 95
%EMR_POLYTEXTOUTA            = 96
%EMR_POLYTEXTOUTW            = 97

'#if(WINVER >= 0x0400)
%EMR_SETICMMODE              = 98
%EMR_CREATECOLORSPACE        = 99
%EMR_SETCOLORSPACE           = 100
%EMR_DELETECOLORSPACE        = 101
%EMR_GLSRECORD               = 102
%EMR_GLSBOUNDEDRECORD        = 103
%EMR_PIXELFORMAT             = 104
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)
%EMR_DRAWESCAPE              = 105
%EMR_EXTESCAPE               = 106
%EMR_STARTDOC                = 107
%EMR_SMALLTEXTOUT            = 108
%EMR_FORCEUFIMAPPING         = 109
%EMR_NAMEDESCAPE             = 110
%EMR_COLORCORRECTPALETTE     = 111
%EMR_SETICMPROFILEA          = 112
%EMR_SETICMPROFILEW          = 113
%EMR_ALPHABLEND              = 114
%EMR_ALPHADIBBLEND           = 115
%EMR_TRANSPARENTBLT          = 116
'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%EMR_TRANSPARENTDIB          = 117
'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN2K)
%EMR_GRADIENTFILL            = 118
%EMR_SETLINKEDUFIS           = 119
%EMR_SETTEXTJUSTIFICATION    = 120
%EMR_COLORMATCHTOTARGETW     = 121
%EMR_CREATECOLORSPACEW       = 122
'#endif /* WINVER >= 0x0500 */

%EMR_MIN                     = 1

'#if (WINVER >= 0x0500)
'#define EMR_MAX                        122
'#elif (WINVER >= 0x0400)
'#define EMR_MAX                        104
'#else
'#define EMR_MAX                         97
'#endif

%EMR_MAX                     = 122 ' depending on Windows version, may be 97, 104, or 120 (so far)

'// Base record type for the enhanced metafile.

' // Size = 8 bytes
TYPE EMR DWORD
   iType AS DWORD  ' DWORD // Enhanced metafile record type
   nSize AS DWORD  ' DWORD // Length of the record in bytes. Must be a multiple of 4.
END TYPE

'// Base text record type for the enhanced metafile.

' // Size = 40 bytes
TYPE EMRTEXT DWORD
   ptlReference AS POINTL
   nChars       AS DWORD
   offString    AS DWORD
   fOptions     AS DWORD
   rcl          AS RECTL
   offDx        AS DWORD
END TYPE

'// Record structures for the enhanced metafile.

' // Size = 8 bytes
TYPE EMRABORTPATH DWORD
   emr AS EMR
END TYPE

MACRO EMRBEGINPATH = EMRABORTPATH
MACRO EMRENDPATH = EMRABORTPATH
MACRO EMRCLOSEFIGURE = EMRABORTPATH
MACRO EMRFLATTENPATH = EMRABORTPATH
MACRO EMRWIDENPATH = EMRABORTPATH
MACRO EMRSETMETARGN = EMRABORTPATH
MACRO EMREMRSAVEDC = EMRABORTPATH
MACRO EMRREALIZEPALETTE = EMRABORTPATH

' // Size = 12 bytes
TYPE EMRSELECTCLIPPATH DWORD
   emr   AS EMR
   iMode AS DWORD
END TYPE

MACRO EMRSETBKMODE = EMRSELECTCLIPPATH
MACRO EMRSETMAPMODE = EMRSELECTCLIPPATH
MACRO EMRSETPOLYFILLMODE = EMRSELECTCLIPPATH
MACRO EMRSETROP2 = EMRSELECTCLIPPATH
MACRO EMRSETSTRETCHBLTMODE = EMRSELECTCLIPPATH
MACRO EMRSETICMMODE = EMRSELECTCLIPPATH
MACRO EMRSETTEXTALIGN = EMRSELECTCLIPPATH

' // Size = 12 bytes
TYPE EMRSETMITERLIMIT DWORD
   emr         AS EMR
   eMiterLimit AS SINGLE
END TYPE

' // Size = 12 bytes
TYPE EMRRESTOREDC DWORD
   emr       AS EMR
   iRelative AS LONG   ' Specifies a relative instance
END TYPE

' // Size = 12 bytes
TYPE EMRSETARCDIRECTION DWORD
   emr           AS EMR
   iArcDirection AS DWORD ' Specifies the arc direction in the advanced graphics mode
END TYPE

' // Size = 12 bytes
TYPE EMRSETMAPPERFLAGS DWORD
   emr     AS EMR
   dwFlags AS DWORD
END TYPE

' // Size = 12 bytes
TYPE EMRSETTEXTCOLOR DWORD
   emr     AS EMR
   crColor AS DWORD
END TYPE

MACRO EMRSETBKCOLOR = EMRSETTEXTCOLOR

' // Size = 12 bytes
TYPE EMRSELECTOBJECT DWORD
   emr      AS EMR
   ihObject AS DWORD  ' Object handle index
END TYPE

MACRO EMRDELETEOBJECT = EMRSELECTOBJECT

' // Size = 12 bytes
TYPE EMRSELECTPALETTE DWORD
   emr   AS EMR
   ihPal AS DWORD    ' Palette handle index, background mode only
END TYPE

' // Size = 16 bytes
TYPE EMRRESIZEPALETTE DWORD
   emr      AS EMR
   ihPal    AS DWORD    ' Palette handle index
   cEntries AS DWORD
END TYPE

' // Size = 24 bytes
TYPE EMRSETPALETTEENTRIES DWORD
   emr            AS EMR
   ihPal          AS DWORD         ' // Palette handle index
   iStart         AS DWORD
   cEntries       AS DWORD
   aPalEntries(0) AS PALETTEENTRY  ' PALETTEENTRY aPalEntries[1];// The peFlags fields do not contain any flags
END TYPE

' // Size = 32 bytes
TYPE EMRSETCOLORADJUSTMENT DWORD
   emr             AS EMR
   ColorAdjustment AS ColorAdjustment
END TYPE

' // Size = 16 bytes
TYPE EMRGDICOMMENT DWORD
   emr     AS EMR
   cbData  AS DWORD   ' // Size of data in bytes
   Data(0) AS BYTE    ' BYTE    Data[1]
END TYPE

' // Size = 20 bytes
TYPE EMREOF DWORD
   emr           AS EMR
   nPalEntries   AS DWORD   ' Number of palette entries
   offPalEntries AS DWORD   ' Offset to the palette entries
   nSizeLast     AS DWORD   ' Same as nSize and must be the last DWORD
                            ' of the record. The palette entries, if they
                            ' exist, precede this field.
END TYPE

' // Size = 16 bytes
TYPE EMRLINETO DWORD
   emr AS EMR
   ptl AS POINTL
END TYPE

MACRO EMRMOVETOEX = EMRLINETO

' // Size = 16 bytes
TYPE EMROFFSETCLIPRGN DWORD
   emr       AS EMR
   ptlOffset AS POINTL
END TYPE

' // Size = 24 bytes
TYPE EMRFILLPATH DWORD
   emr       AS EMR
   rclBounds AS RECTL    ' inclusive-inclusive bounds in device units
END TYPE

MACRO EMRSTROKEANDFILLPATH = EMRFILLPATH
MACRO EMRSTROKEPATH = EMRFILLPATH

' // Size = 24 bytes
TYPE EMREXCLUDECLIPRECT DWORD
   emr     AS EMR
   rclClip AS RECTL
END TYPE

MACRO EMRINTERSECTCLIPRECT = EMREXCLUDECLIPRECT

' // Size = 16 bytes
TYPE EMRSETVIEWPORTORGEX DWORD
   emr       AS EMR
   ptlOrigin AS POINTL
END TYPE

MACRO EMRSETWINDOWORGEX = EMRSETVIEWPORTORGEX
MACRO EMRSETBRUSHORGEX = EMRSETVIEWPORTORGEX

' // Size = 16 bytes
TYPE EMRSETVIEWPORTEXTEX DWORD
   emr       AS EMR
   szlExtent AS SIZEL
END TYPE

MACRO EMRSETWINDOWEXTEX = EMRSETVIEWPORTEXTEX

' // Size = 24 bytes
TYPE EMRSCALEVIEWPORTEXTEX DWORD
   emr    AS EMR
   xNum   AS LONG
   xDenom AS LONG
   yNum   AS LONG
   yDemon AS LONG
END TYPE

MACRO EMRSCALEWINDOWEXTEX = EMRSCALEVIEWPORTEXTEX

' // Size = 32 bytes
TYPE EMRSETWORLDTRANSFORM DWORD
   emr   AS EMR
   xform AS XFORM
END TYPE

' // Size = 36 bytes
TYPE EMRMODIFYWORLDTRANSFORM DWORD
   emr   AS EMR
   xform AS XFORM
   iMode AS DWORD
END TYPE

' // Size = 20 bytes
TYPE EMRSETPIXELV DWORD
   emr      AS EMR
   ptlPixel AS POINTL
   crColor  AS DWORD
END TYPE

' // Size = 24 bytes
TYPE EMREXTFLOODFILL DWORD
   emr      AS EMR
   ptlStart AS POINTL
   crColor  AS DWORD
   iMode    AS DWORD
END TYPE

' // Size = 24 bytes
TYPE EMRELLIPSE DWORD
   emr    AS EMR
   rclBox AS RECTL    ' Inclusive-inclusive bounding rectangle
END TYPE

MACRO EMRRECTANGLE = EMRELLIPSE

' // Size = 32 bytes
TYPE EMRROUNDRECT DWORD
   emr       AS EMR
   rclBox    AS RECTL    ' Inclusive-inclusive bounding rectangle
   szlCorner AS SIZEL
END TYPE

' // Size = 40 bytes
TYPE EMRARC DWORD
   emr      AS EMR
   rclBox   AS RECTL    ' Inclusive-inclusive bounding rectangle
   ptlStart AS POINTL
   ptlEnd   AS POINTL
END TYPE

MACRO EMRARCTO = EMRARC
MACRO EMRCHORD = EMRARC
MACRO EMRPIE   = EMRARC

' // Size = 28 bytes
TYPE EMRANGLEARC DWORD
   emr         AS EMR
   ptlCenter   AS POINTL
   nRadius     AS LONG
   eStartAngle AS SINGLE
   eSweepAngle AS SINGLE
END TYPE

' // Size = 36 bytes
TYPE EMRPOLYLINE DWORD
   emr       AS EMR
   rclBounds AS RECTL   ' Inclusive-inclusive bounds in device units
   cptl      AS DWORD
   aptl(0)   AS POINTL  ' POINTL  aptl[1]
END TYPE

MACRO EMRPOLYBEZIER   = EMRPOLYLINE
MACRO EMRPOLYGON      = EMRPOLYLINE
MACRO EMRPOLYBEZIERTO = EMRPOLYLINE
MACRO EMRPOLYLINETO   = EMRPOLYLINE

' // Size = 32 bytes
TYPE EMRPOLYLINE16 DWORD
   emr       AS emr
   rclBounds AS RECTL    ' // Inclusive-inclusive bounds in device units
   cpts      AS DWORD
   aptl(0)   AS POINTS   ' POINTS  apts[1]
END TYPE

MACRO EMRPOLYBEZIER16 = EMRPOLYLINE16
MACRO EMRPOLYGON16 = EMRPOLYLINE16
MACRO EMRPOLYBEZIERTO16 = EMRPOLYLINE16
MACRO EMRPOLYLINETO16 = EMRPOLYLINE16

' // Size = 40 bytes
TYPE EMRPOLYDRAW DWORD
   emr        AS EMR
   rclBounds  AS RECTL    ' Inclusive-inclusive bounds in device units
   cptl       AS DWORD    ' Number of points
   aptl(0)    AS POINTL   ' POINTL  aptl[1]     // Array of points
   abTypes(0) AS BYTE     ' BYTE    abTypes[1]  // Array of point types
END TYPE

' // Size = 36 bytes
TYPE EMRPOLYDRAW16 DWORD
   emr        AS EMR
   rclBounds  AS RECTL    ' Inclusive-inclusive bounds in device units
   cpts       AS DWORD    ' Number of points
   apts(0)    AS POINTS   ' POINTS  apts[1]     // Array of points
   abTypes(0) AS BYTE     ' BYTE    abTypes[1]  // Array of point types
END TYPE

' // Size = 44 bytes
TYPE EMRPOLYPOLYLINE DWORD
   emr            AS EMR
   rclBounds      AS RECTL    ' Inclusive-inclusive bounds in device units
   nPolys         AS DWORD    ' Number of polys
   cptl           AS DWORD    ' Total number of points in all polys
   aPolyCounts(0) AS DWORD    ' DWORD   aPolyCounts[1] // Array of point counts for each poly
   aptl(0)        AS POINTL   ' POINTL  aptl[1];       // Array of points
END TYPE

MACRO EMRPOLYPOLYGON = EMRPOLYPOLYLINE

' // Size = 40 bytes
TYPE EMRPOLYPOLYLINE16 DWORD
   emr            AS EMR
   rclBounds      AS RECTL    ' Inclusive-inclusive bounds in device units
   nPolys         AS DWORD    ' Number of polys
   cpts           AS DWORD    ' Total number of points in all polys
   aPolyCounts(0) AS DWORD    ' DWORD   aPolyCounts[1] // Array of point counts for each poly
   apts(0)        AS POINTS   ' POINTS  apts[1]        // Array of points
END TYPE

MACRO EMRPOLYPOLYGON16 = EMRPOLYPOLYLINE16

' // Size = 32 bytes
TYPE EMRINVERTRGN DWORD
   emr        AS EMR
   rclBounds  AS RECTL   ' Inclusive-inclusive bounds in device units
   cbRgnData  AS DWORD   ' Size of region data in bytes
   RgnData(0) AS BYTE    ' BYTE    RgnData[1]
END TYPE

MACRO EMRPAINTRGN = EMRINVERTRGN

' // Size = 36 bytes
TYPE EMRFILLRGN DWORD
   emr        AS EMR
   rclBounds  AS RECTL    ' Inclusive-inclusive bounds in device units
   cbRgnData  AS DWORD    ' Size of region data in bytes
   ihBrush    AS DWORD    ' Brush handle index
   RgnData(0) AS BYTE     ' BYTE    RgnData[1]
END TYPE

' // Size = 44 bytes
TYPE EMRFRAMERGN DWORD
   emr        AS EMR
   rclBounds  AS RECTL   ' Inclusive-inclusive bounds in device units
   cbRgnData  AS DWORD   ' Size of region data in bytes
   ihBrush    AS DWORD   ' Brush handle index
   szlStroke  AS SIZEL
   RgnData(0) AS BYTE    ' BYTE    RgnData[1]
END TYPE

' // Size = 20 bytes
TYPE EMREXTSELECTCLIPRGN DWORD
   emr        AS EMR
   cbRgnData  AS DWORD   ' Size of region data in bytes
   iMode      AS DWORD
   RgnData(0) AS BYTE    ' BYTE    RgnData[1];
END TYPE

' // Size = 76 bytes
TYPE EMREXTTEXTOUTA DWORD
   emr           AS EMR
   rclBounds     AS RECTL     ' Inclusive-inclusive bounds in device units
   iGraphicsMode AS DWORD     ' Current graphics mode
   exScale       AS SINGLE    ' X and Y scales from Page units to .01mm units
   eyScale       AS SINGLE    '  if graphics mode is %GM_COMPATIBLE.
   pemrtext      AS EMRTEXT   ' This is followed by the string and spacing array
END TYPE

MACRO EMREXTTEXTOUTW = EMREXTTEXTOUTA
MACRO EMREXTTEXTOUT = EMREXTTEXTOUTA

' // Size = 80 bytes
TYPE EMRPOLYTEXTOUTA DWORD
   emr           AS EMR
   rclBounds     AS RECTL     ' Inclusive-inclusive bounds in device units
   iGraphicsMode AS DWORD     ' Current graphics mode
   exScale       AS SINGLE    ' X and Y scales from Page units to .01mm units
   eyScale       AS SINGLE    '  if graphics mode is %GM_COMPATIBLE.
   cStrings      AS LONG
   aemrtext(0)   AS EMRTEXT   ' EMRTEXT aemrtext[1]  // Array of EMRTEXT structures.  This is
                              '                      // followed by the strings and spacing arrays.
END TYPE

MACRO EMRPOLYTEXTOUTW = EMRPOLYTEXTOUTA
MACRO EMRPOLYTEXTOUT = EMRPOLYTEXTOUTA

' // Size = 100 bytes
TYPE EMRBITBLT DWORD
   emr          AS EMR
   rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest        AS LONG
   yDest        AS LONG
   cxDest       AS LONG
   cyDest       AS LONG
   dwRop        AS DWORD
   xSrc         AS LONG
   ySrc         AS LONG
   xformSrc     AS XFORM   ' Source DC transform
   crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
   iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
END TYPE

' // Size = 108 bytes
TYPE EMRSTRETCHBLT DWORD
   emr          AS EMR
   rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest        AS LONG
   yDest        AS LONG
   cxDest       AS LONG
   cyDest       AS LONG
   dwRop        AS DWORD
   xSrc         AS LONG
   ySrc         AS LONG
   xformSrc     AS XFORM   ' Source DC transform
   crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
   iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
   cxSrc        AS LONG
   cySrc        AS LONG
END TYPE

' // Size = 128 bytes
TYPE EMRMASKBLT DWORD
   emr          AS EMR
   rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest        AS LONG
   yDest        AS LONG
   cxDest       AS LONG
   cyDest       AS LONG
   dwRop        AS DWORD
   xSrc         AS LONG
   ySrc         AS LONG
   xformSrc     AS XFORM   ' Source DC transform
   crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
   iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
   xMask        AS LONG
   yMask        AS LONG
   iUsageMask   AS DWORD   ' Mask bitmap info color table usage
   offBmiMask   AS DWORD   ' Offset to the mask BITMAPINFO structure if any
   cbBmiMask    AS DWORD   ' Size of the mask BITMAPINFO structure if any
   offBitsMask  AS DWORD   ' Offset to the mask bitmap bits if any
   cbBitsMask   AS DWORD   ' Size of the mask bitmap bits if any
END TYPE

' // Size = 140 bytes
TYPE EMRPLGBLT DWORD
   emr          AS EMR
   rclBounds    AS RECTL            ' Inclusive-inclusive bounds in device units
   aptlDest(2)  AS POINTL
   xSrc         AS LONG
   ySrc         AS LONG
   cxSrc        AS LONG
   cySrc        AS LONG
   xformSrc     AS XFORM            ' Source DC transform
   crBkColorSrc AS DWORD            ' Source DC BkColor in RGB
   iUsageSrc    AS DWORD            ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD            ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD            ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD            ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD            ' Size of the source bitmap bits
   xMask        AS LONG
   yMask        AS LONG
   iUsageMask   AS DWORD            ' Mask bitmap info color table usage
   offBmiMask   AS DWORD            ' Offset to the mask BITMAPINFO structure if any
   cbBmiMask    AS DWORD            ' Size of the mask BITMAPINFO structure if any
   offBitsMask  AS DWORD            ' Offset to the mask bitmap bits if any
   cbBitsMask   AS DWORD            ' Size of the mask bitmap bits if any
END TYPE

' // Size = 76 bytes
TYPE EMRSETDIBITSTODEVICE DWORD
   emr        AS EMR
   rclBounds  AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest      AS LONG
   yDest      AS LONG
   xSrc       AS LONG
   ySrc       AS LONG
   cxSrc      AS LONG
   cySrc      AS LONG
   offBmiSrc  AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc   AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc  AS DWORD   ' Size of the source bitmap bits
   iUsageSrc  AS DWORD   ' Source bitmap info color table usage
   iStartScan AS DWORD
   cScans     AS DWORD
END TYPE

' // Size = 80 bytes
TYPE EMRSTRETCHDIBITS DWORD
   emr        AS EMR
   rclBounds  AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest      AS LONG
   yDest      AS LONG
   xSrc       AS LONG
   ySrc       AS LONG
   cxSrc      AS LONG
   cySrc      AS LONG
   offBmiSrc  AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc   AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc  AS DWORD   ' Size of the source bitmap bits
   iUsageSrc  AS DWORD   ' Source bitmap info color table usage
   dwRop      AS DWORD
   cxDest     AS LONG
   cyDest     AS LONG
END TYPE

' // Size = 332 bytes
TYPE EMREXTCREATEFONTINDIRECTW
   emr    AS emr
   ihFont AS DWORD
   elfw   AS EXTLOGFONTW
END TYPE

MACRO EMREXTCREATEFONTINDIRECT = EMREXTCREATEFONTINDIRECTW

' // Size = 20 bytes
TYPE EMRCREATEPALETTE DWORD   ' fake type
   emr   AS EMR
   ihPal AS DWORD        ' Palette handle index
   lgpl  AS LOGPALETTE   ' The peFlags fields in the palette entries
                         ' do not contain any flags
END TYPE

' // Size = 28 bytes
TYPE EMRCREATEPEN DWORD
   emr   AS EMR
   ihPen AS DWORD    ' Pen handle index
   lopn  AS LOGPEN
END TYPE

' // Size = 56 bytes
TYPE EMREXTCREATEPEN DWORD
   emr     AS EMR
   ihPen   AS DWORD         ' Pen handle index
   offBmi  AS DWORD         ' Offset to the BITMAPINFO structure if any
   cbBmi   AS DWORD         ' Size of the BITMAPINFO structure if any
                            ' The bitmap info is followed by the bitmap bits
                            ' to form a packed DIB.
   offBits AS DWORD         ' Offset to the brush bitmap bits if any
   cbBits  AS DWORD         ' Size of the brush bitmap bits if any
   elp     AS EXTLOGPEN32   ' The extended pen with the style array
END TYPE

' // Size = 24 bytes
TYPE EMRCREATEBRUSHINDIRECT DWORD
   emr     AS EMR
   ihBrush AS DWORD        ' Brush handle index
   lb      AS LOGBRUSH32   ' The style must be %BS_SOLID, %BS_HOLLOW, %BS_NULL or
                           ' %BS_HATCHED.
END TYPE

' // Size = 32 bytes
TYPE EMRCREATEMONOBRUSH DWORD
   emr     AS EMR
   ihBrush AS DWORD   ' Brush handle index
   iUsage  AS DWORD   ' Bitmap info color table usage
   offBmi  AS DWORD   ' Offset to the BITMAPINFO structure
   cbBmi   AS DWORD   ' Size of the BITMAPINFO structure
   offBits AS DWORD   ' Offset to the bitmap bits
   cbBits  AS DWORD   ' Size of the bitmap bits
END TYPE

' // Size = 32 bytes
TYPE EMRCREATEDIBPATTERNBRUSHPT DWORD
   emr     AS EMR
   ihBursh AS DWORD   ' Brush handle index
   iUsage  AS DWORD   ' Bitmap info color table usage
   offBmi  AS DWORD   ' Offset to the BITMAPINFO structure
   cbBmi   AS DWORD   ' Size of the BITMAPINFO structure
                      ' The bitmap info is followed by the bitmap bits
                      ' to form a packed DIB.
   offBits AS DWORD   ' Offset to the bitmap bits
   cbBits  AS DWORD   ' Size of the bitmap bits
END TYPE

' // Size = 16 bytes
TYPE EMRFORMAT DWORD
   dSignature AS DWORD   ' Format signature, e.g. %ENHMETA_SIGNATURE.
   nVersion   AS DWORD   ' Format version number.
   cbData     AS DWORD   ' Size of data in bytes.
   offData    AS DWORD   ' Offset to data from %GDICOMMENT_IDENTIFIER.
                         ' It must begin at a DWORD offset.
END TYPE

'#if(WINVER >= 0x0400)

' // Size = 16 bytes
TYPE EMRGLSRECORD DWORD
   emr     AS EMR
   cbData  AS DWORD   ' // Size of data in bytes
   Data(0) AS BYTE    ' BYTE    Data[1]
END TYPE

' // Size = 32 bytes
TYPE EMRGLSBOUNDEDRECORD DWORD
   emr       AS EMR
   rclBounds AS RECTL   ' Bounds in recording coordinates
   cbData    AS DWORD   ' Size of data in bytes
   Data(0)   AS BYTE    ' BYTE    Data[1]
END TYPE

' // Size = 48 bytes
TYPE EMRPIXELFORMAT DWORD
   emr  AS EMR
   pfd  AS PIXELFORMATDESCRIPTOR
END TYPE

' // Size = 340 bytes
TYPE EMRCREATECOLORSPACE DWORD
   emr  AS EMR
   ihCS AS DWORD        ' ColorSpace handle index
   lcs  AS LOGCOLORSPACE
END TYPE

' // Size = 12 bytes
TYPE EMRSETCOLORSPACE DWORD
   emr  AS EMR
   ihCS AS DWORD    ' ColorSpace handle index
END TYPE

MACRO EMRSELECTCOLORSPACE = EMRSETCOLORSPACE
MACRO EMRDELETECOLORSPACE = EMRSETCOLORSPACE

'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0500)

' // Size = 20 bytes
TYPE EMREXTESCAPE DWORD
   emr        AS EMR
   iEscape    AS LONG           ' // Escape code
   cbEscData  AS LONG           ' // Size of escape data
   EscData(0) AS BYTE           ' // Escape data
END TYPE

' // Size = 20 bytes
TYPE EMRDRAWESCAPE DWORD
   emr        AS EMR
   iEscape    AS LONG           ' // Escape code
   cbEscData  AS LONG           ' // Size of escape data
   EscData(0) AS BYTE           ' // Escape data
END TYPE

' // Size = 24 bytes
TYPE EMRNAMEDESCAPE DWORD
   emr        AS EMR
   iEscape    AS LONG  ' // Escape code
   cbDriver   AS LONG  ' // Size   of   driver name
   cbEscData  AS LONG  ' // Size   of   escape data
   EscData(0) AS BYTE  ' // Driver name and    Escape data
END TYPE

%SETICMPROFILE_EMBEDED = &H00000001???

' // Size = 24 bytes
TYPE EMRSETICMPROFILEA DWORD
   emr     AS EMR
   dwFlags AS DWORD   ' flags
   cbName  AS DWORD   ' Size of desired profile name
   cbData  AS DWORD   ' Size of raw profile data if attached
   Data(0) AS BYTE    ' BYTE Data[1] // Array size is cbName + cbData
END TYPE

MACRO EMRSETICMPROFILEW = EMRSETICMPROFILEA
MACRO EMRSETICMPROFILE  = EMRSETICMPROFILEA

%CREATECOLORSPACE_EMBEDED        = &H00000001???

' // Size = 612 bytes
TYPE EMRCREATECOLORSPACEW DWORD
   emr     AS EMR
   ihCS    AS DWORD            ' // ColorSpace handle index
   lcs     AS LOGCOLORSPACEW   ' // Unicode version of logical color space structure
   dwFlags AS DWORD            ' // flags
   cbData  AS DWORD            ' // size of raw source profile data if attached
   Data(0) AS BYTE             ' BYTE Data[1] // Array size is cbData
END TYPE

%COLORMATCHTOTARGET_EMBEDED      = &H00000001???

' // Size = 28 bytes
TYPE EMRCOLORMATCHTOTARGET DWORD
   emr      AS EMR
   dwAction AS DWORD   ' // CS_ENABLE, CS_DISABLE or CS_DELETE_TRANSFORM
   dwFlags  AS DWORD   ' // flags
   cbName   AS DWORD   ' // Size of desired target profile name
   cbData   AS DWORD   ' // Size of raw target profile data if attached
   Data(0)  AS BYTE    ' BYTE Data[1] // Array size is cbName + cbData
END TYPE

' // Size = 24 bytes
TYPE EMRCOLORCORRECTPALETTE DWORD
   emr         AS EMR
   ihPalette   AS DWORD   ' // Palette handle index
   nFirstEntry AS DWORD   ' // Index of first entry to correct
   nPalEntries AS DWORD   ' // Number of palette entries to correct
   nReserved   AS DWORD   ' // Reserved
END TYPE

' // Size = 108 bytes
TYPE EMRALPHABLEND DWORD
   emr          AS EMR
   rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest        AS LONG
   yDest        AS LONG
   cxDest       AS LONG
   cyDest       AS LONG
   dwRop        AS DWORD
   xSrc         AS LONG
   ySrc         AS LONG
   xformSrc     AS XFORM   ' Source DC transform
   crBkColorSrc AS DWORD   ' Source DC BkColor in RGB
   iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
   cxSrc        AS LONG
   cySrc        AS LONG
END TYPE

' // Size = 52 bytes
TYPE EMRGRADIENTFILL DWORD
   emr       AS EMR
   rclBounds AS RECTL       ' Inclusive-inclusive bounds in device units
   nVer      AS DWORD
   nTri      AS DWORD
   ulMode    AS DWORD
   Ver(0)    AS TRIVERTEX   ' TRIVERTEX Ver[1]
END TYPE

' // Size = 108 bytes
TYPE EMRTRANSPARENTBLT DWORD
   emr          AS EMR
   rclBounds    AS RECTL   ' Inclusive-inclusive bounds in device units
   xDest        AS LONG
   yDest        AS LONG
   cxDest       AS LONG
   cyDest       AS LONG
   dwRop        AS DWORD
   xSrc         AS LONG
   ySrc         AS LONG
   xformSrc     AS XFORM   ' Source DC transform
   crBkColorSrc AS DWORD   ' COLORREF // Source DC BkColor in RGB
   iUsageSrc    AS DWORD   ' Source bitmap info color table usage (%DIB_RGB_COLORS)
   offBmiSrc    AS DWORD   ' Offset to the source BITMAPINFO structure
   cbBmiSrc     AS DWORD   ' Size of the source BITMAPINFO structure
   offBitsSrc   AS DWORD   ' Offset to the source bitmap bits
   cbBitsSrc    AS DWORD   ' Size of the source bitmap bits
   cxSrc        AS LONG
   cySrc        AS LONG
END TYPE


'#endif /* WINVER >= 0x0500 */

%GDICOMMENT_IDENTIFIER       = &H43494447???
%GDICOMMENT_WINDOWS_METAFILE = &H80000001???
%GDICOMMENT_BEGINGROUP       = &H00000002???
%GDICOMMENT_ENDGROUP         = &H00000003???
%GDICOMMENT_MULTIFORMATS     = &H40000004???
%EPS_SIGNATURE               = &H46535045???
%GDICOMMENT_UNICODE_STRING   = &H00000040???
%GDICOMMENT_UNICODE_END      = &H00000080???

'#endif  /* NOMETAFILE */
#ENDIF   ' #IF NOT %DEF(%NOMETAFILE) ------------------------------------------


'// OpenGL wgl prototypes

DECLARE FUNCTION wglCopyContext IMPORT "OPENGL32.DLL" ALIAS "wglCopyContext" ( _
   BYVAL hglrcSrc AS DWORD _                            ' __in HGLRC hglrcSrc
 , BYVAL hglrcDst AS DWORD _                            ' __in HGLRC hglrcDst
 , BYVAL mask AS DWORD _                                ' __in UINT  mask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglCreateContext IMPORT "OPENGL32.DLL" ALIAS "wglCreateContext" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS DWORD                                             ' HGLRC

DECLARE FUNCTION wglCreateLayerContext IMPORT "OPENGL32.DLL" ALIAS "wglCreateLayerContext" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iLayerPlane AS LONG _                          ' __in int iLayerPlane
 ) AS DWORD                                             ' HGLRC

DECLARE FUNCTION wglDeleteContext IMPORT "OPENGL32.DLL" ALIAS "wglDeleteContext" ( _
   BYVAL hglrc AS DWORD _                               ' __in HGLRC hglrc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglGetCurrentContext IMPORT "OPENGL32.DLL" ALIAS "wglGetCurrentContext" ( _
 ) AS DWORD                                             ' HGLRC

DECLARE FUNCTION wglGetCurrentDC IMPORT "OPENGL32.DLL" ALIAS "wglGetCurrentDC" ( _
 ) AS DWORD                                             ' HDC

DECLARE FUNCTION wglGetProcAddress IMPORT "OPENGL32.DLL" ALIAS "wglGetProcAddress" ( _
   BYREF lpszProc AS ASCIIZ _                           ' __in LPCSTR lpszProc
 ) AS DWORD                                             ' PROC

DECLARE FUNCTION wglMakeCurrent IMPORT "OPENGL32.DLL" ALIAS "wglMakeCurrent" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL hglrc AS DWORD _                               ' __in HGLRC hglrc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglShareLists IMPORT "OPENGL32.DLL" ALIAS "wglShareLists" ( _
   BYVAL hglrc1 AS DWORD  _                             ' HGLRC hglrc1
 , BYVAL hglrc2 AS DWORD _                              ' HGLRC hglrc2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglUseFontBitmapsA IMPORT "OPENGL32.DLL" ALIAS "wglUseFontBitmapsA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dFirst AS DWORD _                              ' __in DWORD dFirst
 , BYVAL dCount AS DWORD _                              ' __in DWORD dCount
 , BYVAL dListBase AS DWORD _                           ' __in DWORD dListBase
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglUseFontBitmapsW IMPORT "OPENGL32.DLL" ALIAS "wglUseFontBitmapsW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dFirst AS DWORD _                              ' __in DWORD dFirst
 , BYVAL dCount AS DWORD _                              ' __in DWORD dCount
 , BYVAL dListBase AS DWORD _                           ' __in DWORD dListBase
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO wglUseFontBitmaps = wglUseFontBitmapsW
#ELSE
   MACRO wglUseFontBitmaps = wglUseFontBitmapsA
#ENDIF

' ** NOTE ** Microsoft incorrectly documents SwapBuffers as being in OPENGL32.DLL
DECLARE FUNCTION SwapBuffers IMPORT "GDI32.DLL" ALIAS "SwapBuffers" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 ) AS LONG                                              ' BOOL

' // Size = 8 bytes
TYPE POINTFLOAT DWORD
   x AS SINGLE
   y AS SINGLE
END TYPE

' // Size = 24 bytes
TYPE GLYPHMETRICSFLOAT DWORD
   gmfBlackBoxX     AS SINGLE
   gmfBlackBoxY     AS SINGLE
   gmfptGlyphOrigin AS POINTFLOAT
   gmfCellIncX      AS SINGLE
   gmfCellIncY      AS SINGLE
END TYPE

%WGL_FONT_LINES    = 0
%WGL_FONT_POLYGONS = 1

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION wglUseFontOutlinesA LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontOutlinesA" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD, _
    BYVAL deviation AS SINGLE, BYVAL extrusion AS SINGLE, _
    BYVAL iFormat AS LONG, BYVAL lpgmf AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION wglUseFontOutlinesA IMPORT "OPENGL32.DLL" ALIAS "wglUseFontOutlinesA" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dFirst AS DWORD _                              ' __in DWORD dFirst
 , BYVAL dCount AS DWORD _                              ' __in DWORD dCount
 , BYVAL dListBase AS DWORD _                           ' __in DWORD dListBase
 , BYVAL deviation AS SINGLE _                          ' __in FLOAT deviation
 , BYVAL extrusion AS SINGLE  _                         ' __in FLOAT extrusion
 , BYVAL iFormat AS LONG _                              ' __in int iFormat
 , BYREF lpgmf AS GLYPHMETRICSFLOAT _                   ' __out LPGLYPHMETRICSFLOAT lpgmf
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION wglUseFontOutlinesW LIB "OPENGL32.DLL" _
    ALIAS "wglUseFontOutlinesW" (BYVAL hdc AS DWORD, BYVAL dFirst AS DWORD, _
    BYVAL dCount AS DWORD, BYVAL dListBase AS DWORD, _
    BYVAL deviation AS SINGLE, BYVAL extrusion AS SINGLE, _
    BYVAL iFormat AS LONG, BYVAL lpgmf AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION wglUseFontOutlinesW IMPORT "OPENGL32.DLL" ALIAS "wglUseFontOutlinesW" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dFirst AS DWORD _                              ' __in DWORD dFirst
 , BYVAL dCount AS DWORD _                              ' __in DWORD dCount
 , BYVAL dListBase AS DWORD _                           ' __in DWORD dListBase
 , BYVAL deviation AS SINGLE _                          ' __in FLOAT deviation
 , BYVAL extrusion AS SINGLE _                          ' __in FLOAT extrusion
 , BYVAL iFormat AS LONG _                              ' __in int iFormat
 , BYREF lpgmf AS GLYPHMETRICSFLOAT _                   ' __out LPGLYPHMETRICSFLOAT lpgmf
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO wglUseFontOutlines = wglUseFontOutlinesW
#ELSE
   MACRO wglUseFontOutlines = wglUseFontOutlinesA
#ENDIF

'/* Layer plane descriptor */
' // Size = 32 bytes
TYPE LAYERPLANEDESCRIPTOR DWORD FILL
   nSize           AS WORD
   nVersion        AS WORD
   dwFlags         AS DWORD
   iPixelType      AS BYTE
   cColorBits      AS BYTE
   cRedBits        AS BYTE
   cRedShift       AS BYTE
   cGreenBits      AS BYTE
   cGreenShift     AS BYTE
   cBlueBits       AS BYTE
   cBlueShift      AS BYTE
   cAlphaBits      AS BYTE
   cAlphaShift     AS BYTE
   cAccumBits      AS BYTE
   cAccumRedBits   AS BYTE
   cAccumGreenBits AS BYTE
   cAccumBlueBits  AS BYTE
   cAccumAlphaBits AS BYTE
   cDepthBits      AS BYTE
   cStencilBits    AS BYTE
   cAuxBuffers     AS BYTE
   iLayerPlane     AS BYTE
   bReserved       AS BYTE
   crTransparent   AS DWORD
END TYPE

'/* LAYERPLANEDESCRIPTOR flags */
%LPD_DOUBLEBUFFER   = &H00000001???
%LPD_STEREO         = &H00000002???
%LPD_SUPPORT_GDI    = &H00000010???
%LPD_SUPPORT_OPENGL = &H00000020???
%LPD_SHARE_DEPTH    = &H00000040???
%LPD_SHARE_STENCIL  = &H00000080???
%LPD_SHARE_ACCUM    = &H00000100???
%LPD_SWAP_EXCHANGE  = &H00000200???
%LPD_SWAP_COPY      = &H00000400???
%LPD_TRANSPARENT    = &H00001000???

'#define LPD_TYPE_RGBA        0
'#define LPD_TYPE_COLORINDEX  1

%LPD_TYPE_RGBA       = 0
%LPD_TYPE_COLORINDEX = 1

'/* wglSwapLayerBuffers flags */
%WGL_SWAP_MAIN_PLANE = &H00000001???
%WGL_SWAP_OVERLAY1   = &H00000002???
%WGL_SWAP_OVERLAY2   = &H00000004???
%WGL_SWAP_OVERLAY3   = &H00000008???
%WGL_SWAP_OVERLAY4   = &H00000010???
%WGL_SWAP_OVERLAY5   = &H00000020???
%WGL_SWAP_OVERLAY6   = &H00000040???
%WGL_SWAP_OVERLAY7   = &H00000080???
%WGL_SWAP_OVERLAY8   = &H00000100???
%WGL_SWAP_OVERLAY9   = &H00000200???
%WGL_SWAP_OVERLAY10  = &H00000400???
%WGL_SWAP_OVERLAY11  = &H00000800???
%WGL_SWAP_OVERLAY12  = &H00001000???
%WGL_SWAP_OVERLAY13  = &H00002000???
%WGL_SWAP_OVERLAY14  = &H00004000???
%WGL_SWAP_OVERLAY15  = &H00008000???
%WGL_SWAP_UNDERLAY1  = &H00010000???
%WGL_SWAP_UNDERLAY2  = &H00020000???
%WGL_SWAP_UNDERLAY3  = &H00040000???
%WGL_SWAP_UNDERLAY4  = &H00080000???
%WGL_SWAP_UNDERLAY5  = &H00100000???
%WGL_SWAP_UNDERLAY6  = &H00200000???
%WGL_SWAP_UNDERLAY7  = &H00400000???
%WGL_SWAP_UNDERLAY8  = &H00800000???
%WGL_SWAP_UNDERLAY9  = &H01000000???
%WGL_SWAP_UNDERLAY10 = &H02000000???
%WGL_SWAP_UNDERLAY11 = &H04000000???
%WGL_SWAP_UNDERLAY12 = &H08000000???
%WGL_SWAP_UNDERLAY13 = &H10000000???
%WGL_SWAP_UNDERLAY14 = &H20000000???
%WGL_SWAP_UNDERLAY15 = &H40000000???

DECLARE FUNCTION wglDescribeLayerPlane IMPORT "OPENGL32.DLL" ALIAS "wglDescribeLayerPlane" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iPixelFormat AS LONG _                         ' __in int iPixelFormat
 , BYVAL iLayerPlane AS LONG _                          ' __in int iLayerPlane
 , BYVAL nBytes AS DWORD _                              ' __in UINT nBytes
 , BYREF plpd As LAYERPLANEDESCRIPTOR _                 ' __out LPLAYERPLANEDESCRIPTOR plpd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglSetLayerPaletteEntries IMPORT "OPENGL32.DLL" ALIAS "wglSetLayerPaletteEntries" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iLayerPlane AS LONG _                          ' __in int iLayerPlane
 , BYVAL iStart AS LONG _                               ' __in int iStart
 , BYVAL cEntries AS LONG _                             ' __in int cEntries
 , BYREF pcr AS DWORD _                                 ' __in CONST COLORREF * pcr
 ) AS LONG                                              ' int

DECLARE FUNCTION wglGetLayerPaletteEntries IMPORT "OPENGL32.DLL" ALIAS "wglGetLayerPaletteEntries" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iLayerPlane AS LONG _                          ' __in int iLayerPlane
 , BYVAL iStart AS LONG _                               ' __in int iStart
 , BYVAL cEntries AS LONG _                             ' __in int cEntries
 , BYREF pcr AS DWORD _                                 ' __out COLORREF * pcr
 ) AS LONG                                              ' int

DECLARE FUNCTION wglRealizeLayerPalette IMPORT "OPENGL32.DLL" ALIAS "wglRealizeLayerPalette" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL iLayerPlane AS LONG _                          ' __in int iLayerPlane
 , BYVAL fRealize AS LONG _                             ' __in BOOL fRealize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION wglSwapLayerBuffers IMPORT "OPENGL32.DLL" ALIAS "wglSwapLayerBuffers" ( _
   BYVAL hdc AS DWORD  _                                ' __in HDC hdc
 , BYVAL dfPlanes AS DWORD _                            ' __in UINT dfPlanes
 ) AS LONG                                              ' BOOL

'#if (WINVER >= 0x0500)

' // Size = 8 bytes
TYPE WGLSWAP DWORD
   hdc     AS DWORD   ' HDC
   uiFlags AS DWORD   ' UINT
END TYPE

%WGL_SWAPMULTIPLE_MAX = 16

' Undocumented.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION wglSwapMultipleBuffers LIB "OPENGL32.DLL" _
    ALIAS "wglSwapMultipleBuffers" (BYVAL u AS DWORD, _
    BYVAL wglswapptr AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION wglSwapMultipleBuffers IMPORT "OPENGL32.DLL" ALIAS "wglSwapMultipleBuffers" ( _
   BYVAL DWORD _                                        ' __in UINT
 , BYREF WGLSWAP _                                      ' __in CONST WGLSWAP *
 ) AS DWORD                                             ' DWORD
#ENDIF

'#endif // (WINVER >= 0x0500)

'#endif /* NOGDI */
'#ENDIF   ' #IF NOT %DEF(%NOGDI) -----------------------------------------------
