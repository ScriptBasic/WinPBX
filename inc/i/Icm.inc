' ########################################################################################
' Microsoft Windows
' File: Icm.inc
' Contents: Public header file for Image Color Management
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ICM_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// Support for named color profiles
'//

'typedef char COLOR_NAME[32];

' // Size = 76 bytes
TYPE NAMED_PROFILE_INFO DWORD
   dwFlags               AS DWORD         ' DWORD
   dwCount               AS DWORD         ' DWORD
   dwCountDevCoordinates AS DWORD         ' DWORD
   szPrefix              AS ASCIIZ * 32   ' COLOR_NAME
   szSuffix              AS ASCIIZ * 32   ' COLOR_NAME
END TYPE

'//
'// Color spaces
'//
'// The following color spaces are supported.
'// Gray, RGB, CMYK, XYZ, Yxy, Lab, generic 3 channel color spaces where
'// the profiles defines how to interpret the 3 channels, named color spaces
'// which can either be indices into the space or have color names, and
'// multichannel spaces with 1 byte per channel upto MAX_COLOR_CHANNELS.
'//

%MAX_COLOR_CHANNELS = 8   ' // maximum number of HiFi color channels

' // Size = 2 bytes
TYPE GRAYCOLOR WORD
   gray AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE RGBCOLOR WORD
   red   AS WORD   ' WORD
   green AS WORD   ' WORD
   blue  AS WORD   ' WORD
END TYPE

' // Size = 8 bytes
TYPE CMYKCOLOR WORD
   cyan    AS WORD   ' WORD
   magenta AS WORD   ' WORD
   yellow  AS WORD   ' WORD
   black   AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE XYZCOLOR WORD
   X AS WORD   ' WORD
   Y AS WORD   ' WORD
   Z AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE YxyCOLOR WORD
   YCap   AS WORD   ' WORD
   x      AS WORD   ' WORD
   ySmall AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE LabCOLOR WORD
   L AS WORD   ' WORD
   a AS WORD   ' WORD
   b AS WORD   ' WORD
END TYPE

' // Size = 6 bytes
TYPE GENERIC3CHANNEL WORD
   ch1 AS WORD   ' WORD
   ch2 AS WORD   ' WORD
   ch3 AS WORD   ' WORD
END TYPE

' // Size = 4 bytes
TYPE NAMEDCOLOR DWORD
   dwIndex AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE HiFiCOLOR BYTE
   channel(%MAX_COLOR_CHANNELS - 1) AS BYTE
END TYPE

'typedef union tagCOLOR {
'    struct GRAYCOLOR        gray;
'    struct RGBCOLOR         rgb;
'    struct CMYKCOLOR        cmyk;
'    struct XYZCOLOR         XYZ;
'    struct YxyCOLOR         Yxy;
'    struct LabCOLOR         Lab;
'    struct GENERIC3CHANNEL  gen3ch;
'    struct NAMEDCOLOR       named;
'    struct HiFiCOLOR        hifi;

'    struct {                // alignment padding.
'        DWORD reserved1;
'        VOID *reserved2;
'    };

'} COLOR;

' // Size = 8 bytes
UNION tagCOLOR
   gray      AS GRAYCOLOR
   rgb       AS RGBCOLOR
   cmyk      AS CMYKCOLOR
   XYZ       AS XYZCOLOR
   Yxy       AS YxyCOLOR
   Lab       AS LabCOLOR
   gen3ch    AS GENERIC3CHANNEL
   named     AS NAMEDCOLOR
   hifi      AS HiFiCOLOR
   ' // alignment padding.
   reserved1 AS DWORD       ' DWORD
   reserved2 AS DWORD PTR   ' VOID *
END UNION

' COLORTYPE enum
%COLOR_GRAY      = 1
%COLOR_RGB       = 2
%COLOR_XYZ       = 3
%COLOR_Yxy       = 4
%COLOR_Lab       = 4
%COLOR_3_CHANNEL = 6    ' // WORD per channel
%COLOR_CMYK      = 7
%COLOR_5_CHANNEL = 8    ' // BYTE per channel
%COLOR_6_CHANNEL = 9    ' //      - do -
%COLOR_7_CHANNEL = 10   ' //      - do -
%COLOR_8_CHANNEL = 11   ' //      - do -
%COLOR_NAMED     = 12

'//
'// Rendering Intents
'//
'// + INTENT_PERCEPTUAL            = LCS_GM_IMAGES for LOGCOLORSPACE
'//                                = DMICM_CONTRAST for DEVMODE
'//                                = "Pictures" for SetupColorMathing/Printer UI
'//
'// + INTENT_RELATIVE_COLORIMETRIC = LCS_GM_GRAPHICS for LOGCOLORSPACE
'//                                = DMICM_COLORIMETRIC for DEVMODE
'//                                = "Proof" for SetupColorMatching/Printer UI
'//
'// + INTENT_SATURATION            = LCS_GM_BUSINESS for LOGCOLORSPACE
'//                                = DMICM_SATURATE for DEVMODE
'//                                = "Graphics" for SetupColorMatching/Printer UI
'//
'// + INTENT_ABSOLUTE_COLORIMETRIC = LCS_GM_ABS_COLORIMETRIC for LOGCOLORSPACE
'//                                = DMICM_ABS_COLORIMETRIC for DEVMODE
'//                                = "Match" for SetupColorMatching/Printer UI
'//

%INTENT_PERCEPTUAL              = 0
%INTENT_RELATIVE_COLORIMETRIC   = 1
%INTENT_SATURATION              = 2
%INTENT_ABSOLUTE_COLORIMETRIC   = 3

'#if NTDDI_VERSION >= NTDDI_VISTA

' enum COLORPROFILETYPE
%CPT_ICC  = 0
%CPT_DMP  = 1
%CPT_CAMP = 2
%CPT_GMMP = 3

' enum COLORPROFILESUBTYPE

'// intent
%CPST_PERCEPTUAL             = %INTENT_PERCEPTUAL
%CPST_RELATIVE_COLORIMETRIC  = %INTENT_RELATIVE_COLORIMETRIC
%CPST_SATURATION             = %INTENT_SATURATION
%CPST_ABSOLUTE_COLORIMETRIC  = %INTENT_ABSOLUTE_COLORIMETRIC

'// working space
%CPST_NONE                 = 0
%CPST_RGB_WORKING_SPACE    = 1
%CPST_CUSTOM_WORKING_SPACE = 2

'//
'// Device color data type
'//
' enum COLORDATATYPE
%COLOR_BYTE               = 1   ' // BYTE per channel. data range [0, 255]
%COLOR_WORD               = 2   ' // WORD per channel. data range [0, 65535]
%COLOR_FLOAT              = 3   ' // FLOAT per channel. IEEE 32-bit floating point
%COLOR_S2DOT13FIXED       = 4   ' // WORD per channel. data range [-4, +4] using s2.13
'//#if NTDDI_VERSION >= NTDDI_WIN7
%COLOR_10b_R10G10B10A2    = 5   ' // Packed WORD per channel.  data range [0, 1]
%COLOR_10b_R10G10B10A2_XR = 6   ' // Packed extended range WORD per channel.  data range [-1, 3]
                                ' // using 4.0 scale and -1.0 bias.
%COLOR_FLOAT16            = 7   ' // FLOAT16 per channel.
'//#endif //NTDDI_VERSION >= NTDDI_WIN7

'#endif // NTDDI_VERSION >= NTDDI_VISTA

'//
'// Bitmap formats supported
'//

' BMFORMAT enum

'  //
'  // 16bpp - 5 bits per channel. The most significant bit is ignored.
'  //

%BM_x555RGB      = &H0000
%BM_x555XYZ      = &H0101
%BM_x555Yxy      = &H0102
%BM_x555Lab      = &H0103
%BM_x555G3CH     = &H0104

'  //
'  // Packed 8 bits per channel => 8bpp for GRAY and
'  // 24bpp for the 3 channel colors, more for hifi channels
'  //

%BM_RGBTRIPLETS  = &H0002
%BM_BGRTRIPLETS  = &H0004
%BM_XYZTRIPLETS  = &H0201
%BM_YxyTRIPLETS  = &H0202
%BM_LabTRIPLETS  = &H0203
%BM_G3CHTRIPLETS = &H0204
%BM_5CHANNEL     = &H0205
%BM_6CHANNEL     = &H0206
%BM_7CHANNEL     = &H0207
%BM_8CHANNEL     = &H0208
%BM_GRAY         = &H0209

'  //
'  // 32bpp - 8 bits per channel. The most significant byte is ignored
'  // for the 3 channel colors.
'  //

%BM_xRGBQUADS    = &H0008
%BM_xBGRQUADS    = &H0010
%BM_xG3CHQUADS   = &H0304
%BM_KYMCQUADS    = &H0305
%BM_CMYKQUADS    = &H0020

'  //
'  // 32bpp - 10 bits per channel. The 2 most significant bits are ignored.
'  //

%BM_10b_RGB      = &H0009
%BM_10b_XYZ      = &H0401
%BM_10b_Yxy      = &H0402
%BM_10b_Lab      = &H0403
%BM_10b_G3CH     = &H0404

'  //
'  // 32bpp - named color indices (1-based)
'  //

%BM_NAMED_INDEX  = &H0405

'  //
'  // Packed 16 bits per channel => 16bpp for GRAY and
'  // 48bpp for the 3 channel colors.
'  //

%BM_16b_RGB      = &H000A
%BM_16b_XYZ      = &H0501
%BM_16b_Yxy      = &H0502
%BM_16b_Lab      = &H0503
%BM_16b_G3CH     = &H0504
%BM_16b_GRAY     = &H0505

'  //
'  // 16 bpp - 5 bits for Red & Blue, 6 bits for Green
'  //

%BM_565RGB       = &H0001

'//#if NTDDI_VERSION >= NTDDI_VISTA

'    //
'    // scRGB - 32 bits per channel floating point
'    //         16 bits per channel floating point
'    //

%BM_32b_scRGB            = &H0601
%BM_32b_scARGB           = &H0602
%BM_S2DOT13FIXED_scRGB   = &H0603
%BM_S2DOT13FIXED_scARGB  = &H0604
'//#endif // NTDDI_VERSION >= NTDDI_VISTA

'//#if NTDDI_VERSION >= NTDDI_WIN7
%BM_R10G10B10A2          = &H0701
%BM_R10G10B10A2_XR       = &H0702
%BM_R16G16B16A16_FLOAT   = &H0703
'//#endif // NTDDI_VERSION >= NTDDI_WIN7


'//
'// Callback function definition
'//

'typedef BOOL (WINAPI *PBMCALLBACKFN)(ULONG, ULONG, LPARAM);

'//
'// ICC profile header
'//

' // Size = 128 bytes
TYPE PROFILEHEADER DWORD
   phSize            AS DWORD    ' DWORD  // profile size in bytes
   phCMMType         AS DWORD    ' DWORD  // CMM for this profile
   phVersion         AS DWORD    ' DWORD  // profile format version number
   phClass           AS DWORD    ' DWORD  // type of profile
   phDataColorSpace  AS DWORD    ' DWORD  // color space of data
   phConnectionSpace AS DWORD    ' DWORD  // PCS
   phDateTime(2)     AS DWORD    ' DWORD[3]  // date profile was created
   phSignature       AS DWORD    ' DWORD  // magic number
   phPlatform        AS DWORD    ' DWORD  // primary platform
   phProfileFlags    AS DWORD    ' DWORD  // various bit settings
   phManufacturer    AS DWORD    ' DWORD  // device manufacturer
   phModel           AS DWORD    ' DWORD  // device model number
   phAttributes(1)   AS DWORD    ' DWORD[2]  // device attributes
   phRenderingIntent AS DWORD    ' DWORD  // rendering intent
   phIlluminant      AS CIEXYZ   ' CIEXYZ // profile illuminant
   phCreator         AS DWORD    ' DWORD  // profile creator
   phReserved(43)    AS BYTE     ' BYTE[44]   // reserved for future use
END TYPE

'//
'// Profile class values
'//

$CLASS_MONITOR           = "mntr"
$CLASS_PRINTER           = "prtr"
$CLASS_SCANNER           = "scnr"
$CLASS_LINK              = "link"
$CLASS_ABSTRACT          = "abst"
$CLASS_COLORSPACE        = "spac"
$CLASS_NAMED             = "nmcl"
'#if NTDDI_VERSION >= NTDDI_VISTA
$CLASS_CAMP              = "camp"
$CLASS_GMMP              = "gmmp"
'#endif // NTDDI_VERSION >= NTDDI_VISTA

'//
'// Color space values
'//

$SPACE_XYZ               = "XYZ "
$SPACE_Lab               = "Lab "
$SPACE_Luv               = "Luv "
$SPACE_YCbCr             = "YCbr"
$SPACE_Yxy               = "Yxy "
$SPACE_RGB               = "RGB "
$SPACE_GRAY              = "GRAY"
$SPACE_HSV               = "HSV "
$SPACE_HLS               = "HLS "
$SPACE_CMYK              = "CMYK"
$SPACE_CMY               = "CMY "
$SPACE_2_CHANNEL         = "2CLR"
$SPACE_3_CHANNEL         = "3CLR"
$SPACE_4_CHANNEL         = "4CLR"
$SPACE_5_CHANNEL         = "5CLR"
$SPACE_6_CHANNEL         = "6CLR"
$SPACE_7_CHANNEL         = "7CLR"
$SPACE_8_CHANNEL         = "8CLR"

'//
'// Profile flag bitfield values
'//

%FLAG_EMBEDDEDPROFILE    = &H00000001???
%FLAG_DEPENDENTONDATA    = &H00000002???

'//
'// Profile flag bits for vendor extensions (bytes 44..45 of the ICC profile header).
'//

'#if NTDDI_VERSION >= NTDDI_VISTA

'//
'// Enable support for chromatic adaptation.
'//
%FLAG_ENABLE_CHROMATIC_ADAPTATION = &H02000000???

'#endif // NTDDI_VERSION >= NTDDI_VISTA


'//
'// Profile attributes bitfield values
'//

%ATTRIB_TRANSPARENCY     = &H00000001???
%ATTRIB_MATTE            = &H00000002???

'//
'// Profile data structure
'//

' // Size = 12 bytes
TYPE tagPROFILE DWORD
   dwType       AS DWORD   ' DWORD // profile type
   pProfileData AS DWORD   ' PVOID // filename or buffer containing profile
   cbDataSize   AS DWORD   ' DWORD // size of profile data
END TYPE


'//
'// Profile types to be used in the PROFILE structure
'//

%PROFILE_FILENAME  = 1  ' // profile data is NULL terminated filename
%PROFILE_MEMBUFFER = 2  ' // profile data is a buffer containing the profile

'//
'// Desired access mode for opening profiles
'//

%PROFILE_READ      = 1  ' // opened for read access
%PROFILE_READWRITE = 2  ' // opened for read and write access

'//
'// Handles returned to applications
'//

'typedef HANDLE HPROFILE;        // handle to profile object
'typedef HPROFILE *PHPROFILE;
'typedef HANDLE HTRANSFORM;      // handle to color transform object

'//
'// CMM selection for CreateMultiProfileTransform and SelectCMM.
'//

%INDEX_DONT_CARE   = 0

%CMM_FROM_PROFILE    = %INDEX_DONT_CARE   ' // Use CMM specified in profile.
$CMM_WINDOWS_DEFAULT = "Win "             ' // Use Windows default CMM always.

'//
'// Tags found in ICC profiles
'//

'typedef DWORD      TAGTYPE;
'typedef TAGTYPE   *PTAGTYPE, *LPTAGTYPE;

'//
'// Profile enumeration data structure
'//

%ENUM_TYPE_VERSION    = &H0300

' // Size = 88 bytes
TYPE ENUMTYPEA DWORD
   dwSize            AS DWORD        ' DWORD // structure size
   dwVersion         AS DWORD        ' DWORD // structure version
   dwFields          AS DWORD        ' DWORD // bit fields
   pDeviceName       AS ASCIIZ PTR   ' PCSTR // device friendly name
   dwMediaType       AS DWORD        ' DWORD // media type
   dwDitheringMode   AS DWORD        ' DWORD // dithering mode
   dwResolution(1)   AS DWORD        ' DWORD[2] // x and y resolutions
   dwCMMType         AS DWORD        ' DWORD // cmm ID
   dwClass           AS DWORD        ' DWORD // profile class
   dwDataColorSpace  AS DWORD        ' DWORD // color space of data
   dwConnectionSpace AS DWORD        ' DWORD // pcs
   dwSignature       AS DWORD        ' DWORD // magic number
   dwPlatform        AS DWORD        ' DWORD // primary platform
   dwProfileFlags    AS DWORD        ' DWORD // various bit settings in profile
   dwManufacturer    AS DWORD        ' DWORD // manufacturer ID
   dwModel           AS DWORD        ' DWORD // model ID
   dwAttributes(1)   AS DWORD        ' DWORD[2] // device attributes
   dwRenderingIntent AS DWORD        ' DWORD // rendering intent
   dwCreator         AS DWORD        ' DWORD // profile creator
   dwDeviceClass     AS DWORD        ' DWORD // device class
END TYPE

' // Size = 88 bytes
TYPE ENUMTYPEW DWORD
   dwSize            AS DWORD        ' DWORD  // structure size
   dwVersion         AS DWORD        ' DWORD  // structure version
   dwFields          AS DWORD        ' DWORD  // bit fields
   pDeviceName       AS WSTRINGZ PTR ' PCWSTR // device friendly name
   dwMediaType       AS DWORD        ' DWORD  // media type
   dwDitheringMode   AS DWORD        ' DWORD[2]  // dithering mode
   dwResolution(1)   AS DWORD        ' DWORD  // x and y resolutions
   dwCMMType         AS DWORD        ' DWORD  // cmm ID
   dwClass           AS DWORD        ' DWORD  // profile class
   dwDataColorSpace  AS DWORD        ' DWORD  // color space of data
   dwConnectionSpace AS DWORD        ' DWORD  // pcs
   dwSignature       AS DWORD        ' DWORD  // magic number
   dwPlatform        AS DWORD        ' DWORD  // primary platform
   dwProfileFlags    AS DWORD        ' DWORD  // various bit settings in profile
   dwManufacturer    AS DWORD        ' DWORD  // manufacturer ID
   dwModel           AS DWORD        ' DWORD  // model ID
   dwAttributes(1)   AS DWORD        ' DWORD[2]  // device attributes
   dwRenderingIntent AS DWORD        ' DWORD  // rendering intent
   dwCreator         AS DWORD        ' DWORD  // profile creator
   dwDeviceClass     AS DWORD        ' DWORD  // device class
END TYPE

MACRO ENUMTYPE = ENUMTYPEA

'//
'// Bitfields for enumeration record above
'//

%ET_DEVICENAME           = &H00000001???
%ET_MEDIATYPE            = &H00000002???
%ET_DITHERMODE           = &H00000004???
%ET_RESOLUTION           = &H00000008???
%ET_CMMTYPE              = &H00000010???
%ET_CLASS                = &H00000020???
%ET_DATACOLORSPACE       = &H00000040???
%ET_CONNECTIONSPACE      = &H00000080???
%ET_SIGNATURE            = &H00000100???
%ET_PLATFORM             = &H00000200???
%ET_PROFILEFLAGS         = &H00000400???
%ET_MANUFACTURER         = &H00000800???
%ET_MODEL                = &H00001000???
%ET_ATTRIBUTES           = &H00002000???
%ET_RENDERINGINTENT      = &H00004000???
%ET_CREATOR              = &H00008000???
%ET_DEVICECLASS          = &H00010000???

'#if NTDDI_VERSION >= NTDDI_VISTA

'//
'// WCS profile management scope - system-wide and current-user
'//

' enum WCS_PROFILE_MANAGEMENT_SCOPE
%WCS_PROFILE_MANAGEMENT_SCOPE_SYSTEM_WIDE  = 0
%WCS_PROFILE_MANAGEMENT_SCOPE_CURRENT_USER = 1

'#endif // NTDDI_VERSION >= NTDDI_VISTA

'//
'// Flags for creating color transforms
'//

%PROOF_MODE                  = &H00000001???
%NORMAL_MODE                 = &H00000002???
%BEST_MODE                   = &H00000003???
%ENABLE_GAMUT_CHECKING       = &H00010000???
%USE_RELATIVE_COLORIMETRIC   = &H00020000???
%FAST_TRANSLATE              = &H00040000???
'#if NTDDI_VERSION >= NTDDI_VISTA
%PRESERVEBLACK               = &H00100000???
%WCS_ALWAYS                  = &H00200000???
%SEQUENTIAL_TRANSFORM        = &H80800000???
'#endif // NTDDI_VERSION >= NTDDI_VISTA
%RESERVED                    = &H80000000???

'//
'// Paremeter for GetPS2ColorSpaceArray
'//

%CSA_A              = 1
%CSA_ABC            = 2
%CSA_DEF            = 3
%CSA_DEFG           = 4
%CSA_GRAY           = 5
%CSA_RGB            = 6
%CSA_CMYK           = 7
%CSA_Lab            = 8

'//
'// Parameter for CMGetInfo()
'//

%CMM_WIN_VERSION    = 0
%CMM_IDENT          = 1
%CMM_DRIVER_VERSION = 2
%CMM_DLL_VERSION    = 3
%CMM_VERSION        = 4
%CMM_DESCRIPTION    = 5
%CMM_LOGOICON       = 6

'//
'// Parameter for CMTranslateRGBs()
'//

%CMS_FORWARD        = 0
%CMS_BACKWARD       = 1

'//
'//  Constants for SetupColorMatching()
'//

%COLOR_MATCH_VERSION  = &H0200

'//
'//  Constants for flags
'//

%CMS_DISABLEICM          = 1     ' // Disable color matching
%CMS_ENABLEPROOFING      = 2     ' // Enable proofing

%CMS_SETRENDERINTENT     = 4     ' // Use passed in value
%CMS_SETPROOFINTENT      = 8
%CMS_SETMONITORPROFILE   = &H10  ' // Use passed in profile name initially
%CMS_SETPRINTERPROFILE   = &H20
%CMS_SETTARGETPROFILE    = &H40

%CMS_USEHOOK             = &H80  ' // Use hook procedure in lpfnHook
%CMS_USEAPPLYCALLBACK    = &H100 ' // Use callback procedure when applied
%CMS_USEDESCRIPTION      = &H200 ' // Use profile description in UI
                                 ' //   (default is filename)

%CMS_DISABLEINTENT       = &H400 ' // Disable intent selection (render & proofing) always
%CMS_DISABLERENDERINTENT = &H800 ' // Disable rendering intent selection while in proofing mode
                                 ' // Only proofing intent selection is enabled.

'//
'//  Used to denote too-small buffers (output only)
'//

%CMS_MONITOROVERFLOW     = &H80000000???
%CMS_PRINTEROVERFLOW     = &H40000000???
%CMS_TARGETOVERFLOW      = &H20000000???

'//
'//  Structures (both ANSI and Unicode)
'//
'struct _tagCOLORMATCHSETUPW;
'struct _tagCOLORMATCHSETUPA;

'typedef BOOL (WINAPI *PCMSCALLBACKW)(struct _tagCOLORMATCHSETUPW *,LPARAM);
'typedef BOOL (WINAPI *PCMSCALLBACKA)(struct _tagCOLORMATCHSETUPA *,LPARAM);

' // Size = 76 bytes
TYPE COLORMATCHSETUPW DWORD
   dwSize              AS DWORD          ' DWORD   //  Size of structure in bytes
   dwVersion           AS DWORD          ' DWORD   //  Set to COLOR_MATCH_VERSION
   dwFlags             AS DWORD          ' DWORD   //  See constants listed previously
   hwndOwner           AS DWORD          ' HWND    //  Window handle of owner
   pSourceName         AS WSTRINGZ PTR   ' PCWSTR  //  Name of Image Source, defaults to "sRGB Color Space"
   pDisplayName        AS WSTRINGZ PTR   ' PCWSTR  //  If null, defaults to first enumerated monitor
   pPrinterName        AS WSTRINGZ PTR   ' PCWSTR  //  If null, defaults to default printer.
   dwRenderIntent      AS DWORD          ' DWORD   //  Rendering Intent
   dwProofingIntent    AS DWORD          ' DWORD   //  Rendering Intent for Proofing
   pMonitorProfile     AS WSTRINGZ PTR   ' PWSTR   //  Monitor profile name
   ccMonitorProfile    AS DWORD          ' DWORD   //  Size of above in characters
   pPrinterProfile     AS WSTRINGZ PTR   ' PWSTR   //  Printer profile name
   ccPrinterProfile    AS DWORD          ' DWORD   //  Size of above in characters
   pTargetProfile      AS WSTRINGZ PTR   ' PWSTR   //  Target profile name
   ccTargetProfile     AS DWORD          ' DWORD   //  Size of above in characters
   lpfnHook            AS DWORD          ' DLGPROC //  Hook Procedure address
   lParam              AS DWORD          ' LPARAM  //  Given to hook procedure at WM_INITDIALOG
   lpfnApplyCallback   AS DWORD          ' PCMSCALLBACKW //  Callback Procedure address when apply is pushed
   lParamApplyCallback AS DWORD          ' LPARAM  //  Given to callback Procedure for apply
END TYPE

' // Size = 76 bytes
TYPE COLORMATCHSETUPA DWORD
   dwSize              AS DWORD        ' DWORD   //  Size of structure in bytes
   dwVersion           AS DWORD        ' DWORD   //  Set to COLOR_MATCH_VERSION
   dwFlags             AS DWORD        ' DWORD   //  See constants listed previously
   hwndOwner           AS DWORD        ' HWND    //  Window handle of owner
   pSourceName         AS ASCIIZ PTR   ' PCSTR   //  Name of Image Source, defaults to "sRGB Color Space"
   pDisplayName        AS ASCIIZ PTR   ' PCSTR   //  If null, defaults to first enumerated monitor
   pPrinterName        AS ASCIIZ PTR   ' PCSTR   //  If null, defaults to default printer.
   dwRenderIntent      AS DWORD        ' DWORD   //  Rendering Intent
   dwProofingIntent    AS DWORD        ' DWORD   //  Rendering Intent for Proofing
   pMonitorProfile     AS ASCIIZ PTR   ' PSTR    //  Monitor profile name
   ccMonitorProfile    AS DWORD        ' DWORD   //  Size of above in characters
   pPrinterProfile     AS ASCIIZ PTR   ' PSTR    //  Printer profile name
   ccPrinterProfile    AS DWORD        ' DWORD   //  Size of above in characters
   pTargetProfile      AS ASCIIZ PTR   ' PSTR    //  Target profile name
   ccTargetProfile     AS DWORD        ' DWORD   //  Size of above in characters
   lpfnHook            AS DWORD        ' DLGPROC //  Hook Procedure address
   lParam              AS DWORD        ' LPARAM  //  Given to hook procedure at WM_INITDIALOG
   lpfnApplyCallback   AS DWORD        ' PCMSCALLBACKW //  Callback Procedure address when apply is pushed
   lParamApplyCallback AS DWORD        ' LPARAM  //  Given to callback Procedure for apply
END TYPE

MACRO COLORMATCHSETUP = COLORMATCHSETUPA

'//
'// Windows API definitions
'//

DECLARE FUNCTION OpenColorProfileA IMPORT "MSCMS.DLL" ALIAS "OpenColorProfileA" ( _
   BYREF pProfile AS tagPROFILE _                       ' __in PPROFILE pProfile
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYVAL dwCreationMode AS DWORD _                      ' __in DWORD dwCreationMode
 ) AS DWORD                                             ' HPROFILE

DECLARE FUNCTION OpenColorProfileW IMPORT "MSCMS.DLL" ALIAS "OpenColorProfileW" ( _
   BYREF pProfile AS tagPROFILE _                       ' __in PPROFILE pProfile
 , BYVAL dwDesiredAccess AS DWORD _                     ' __in DWORD dwDesiredAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in DWORD dwShareMode
 , BYVAL dwCreationMode AS DWORD _                      ' __in DWORD dwCreationMode
 ) AS DWORD                                             ' HPROFILE

#IF %DEF(%UNICODE)
   MACRO OpenColorProfile = OpenColorProfileW
#ELSE
   MACRO OpenColorProfile = OpenColorProfileA
#ENDIF

DECLARE FUNCTION CloseColorProfile IMPORT "MSCMS.DLL" ALIAS "CloseColorProfile" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorProfileFromHandle IMPORT "MSCMS.DLL" ALIAS "GetColorProfileFromHandle" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pcbSize AS DWORD _                             ' __out PDWORD pcbSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsColorProfileValid IMPORT "MSCMS.DLL" ALIAS "IsColorProfileValid" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pbValid AS LONG _                              ' __out PBOOL pbValid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateProfileFromLogColorSpaceA IMPORT "MSCMS.DLL" ALIAS "CreateProfileFromLogColorSpaceA" ( _
   BYREF pLogColorSpace AS LOGCOLORSPACEA _             ' __in LPLOGCOLORSPACE pLogColorSpace
 , BYREF pBuffer AS DWORD _                             ' __out PBYTE *pBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateProfileFromLogColorSpaceW IMPORT "MSCMS.DLL" ALIAS "CreateProfileFromLogColorSpaceW" ( _
   BYREF pLogColorSpace AS LOGCOLORSPACEW _             ' __in  LPLOGCOLORSPACEW pLogColorSpace
 , BYREF pBuffer AS DWORD _                             ' __out PBYTE *pBuffer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CreateProfileFromLogColorSpace = CreateProfileFromLogColorSpaceW
#ELSE
   MACRO CreateProfileFromLogColorSpace = CreateProfileFromLogColorSpaceA
#ENDIF

DECLARE FUNCTION GetCountColorProfileElements IMPORT "MSCMS.DLL" ALIAS "GetCountColorProfileElements" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pnCount AS DWORD _                             ' __out PDWORD pnCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorProfileHeader IMPORT "MSCMS.DLL" ALIAS "GetColorProfileHeader" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pHeader AS PROFILEHEADER _                     ' __out PPROFILEHEADER pHeader
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorProfileElementTag IMPORT "MSCMS.DLL" ALIAS "GetColorProfileElementTag" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD dwIndex
 , BYREF pTag AS DWORD _                                ' __out PTAGTYPE pTag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsColorProfileTagPresent IMPORT "MSCMS.DLL" ALIAS "IsColorProfileTagPresent" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYVAL tag AS DWORD _                                 ' __in  TAGTYPE tag
 , BYREF pbPresent AS LONG _                            ' __out PBOOL pbPresent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorProfileElement IMPORT "MSCMS.DLL" ALIAS "GetColorProfileElement" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL tag AS DWORD _                                 ' __in TAGTYPE tag
 , BYVAL dwOffset AS DWORD _                            ' __in DWORD dwOffset
 , BYREF pcbSize AS DWORD _                             ' __in_out PDWORD pcbSize
 , BYVAL pBuffer AS DWORD _                             ' __in_out PVOID pBuffer
 , BYREF pbReference AS LONG _                          ' __out PBOOL pbReference
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetColorProfileHeader IMPORT "MSCMS.DLL" ALIAS "SetColorProfileHeader" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pHeader AS PROFILEHEADER _                     ' __out PPROFILEHEADER pHeader
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetColorProfileElementSize IMPORT "MSCMS.DLL" ALIAS "SetColorProfileElementSize" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL tag AS DWORD _                                 ' __in TAGTYPE tag
 , BYVAL cbSize AS DWORD _                              ' __in DWORD cbSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetColorProfileElement IMPORT "MSCMS.DLL" ALIAS "SetColorProfileElement" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL tag AS DWORD _                                 ' __in TAGTYPE tag
 , BYVAL dwOffset AS DWORD _                            ' __in DWORD dwOffset
 , BYREF pcbSize AS DWORD _                             ' __in PDWORD pcbSize
 , BYVAL pBuffer AS DWORD _                             ' __in PVOID pBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetColorProfileElementReference IMPORT "MSCMS.DLL" ALIAS "SetColorProfileElementReference" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL newTag AS DWORD _                              ' __in TAGTYPE newTag
 , BYVAL refTag AS DWORD _                              ' __in TAGTYPE refTag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPS2ColorSpaceArray IMPORT "MSCMS.DLL" ALIAS "GetPS2ColorSpaceArray" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL dwCSAType AS DWORD _                           ' __in DWORD dwCSAType
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pcbSize AS DWORD _                             ' __out PDWORD pcbSize
 , BYREF pbBinary AS LONG _                             ' __out PBOOL pbBinary
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPS2ColorRenderingIntent IMPORT "MSCMS.DLL" ALIAS "GetPS2ColorRenderingIntent" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pcbSize AS DWORD _                             ' __in PDWORD pcbSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPS2ColorRenderingDictionary IMPORT "MSCMS.DLL" ALIAS "GetPS2ColorRenderingDictionary" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pcbSize AS DWORD _                             ' __out PDWORD pcbSize
 , BYREF pbBinary AS LONG _                             ' __out PBOOL pbBinary
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNamedProfileInfo IMPORT "MSCMS.DLL" ALIAS "GetNamedProfileInfo" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pNamedProfileInfo AS NAMED_PROFILE_INFO _      ' __out PNAMED_PROFILE_INFO pNamedProfileInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertColorNameToIndex IMPORT "MSCMS.DLL" ALIAS "ConvertColorNameToIndex" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYREF paColorName AS ANY _                           ' __in PCOLOR_NAME paColorName
 , BYREF paIndex AS DWORD _                             ' __in_out PDWORD paIndex
 , BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertIndexToColorName IMPORT "MSCMS.DLL" ALIAS "ConvertIndexToColorName" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF paIndex AS DWORD _                             ' __out PDWORD paIndex
 , BYREF paColorName AS ANY _                           ' __out PCOLOR_NAME paColorName
 , BYVAL dwCount AS DWORD _                             ' __in  DWORD dwCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateDeviceLinkProfile IMPORT "MSCMS.DLL" ALIAS "CreateDeviceLinkProfile" ( _
   BYREF pahProfiles AS DWORD _                         ' __in  PHPROFILE pahProfiles
 , BYVAL nProfiles AS DWORD _                           ' __in  DWORD nProfiles
 , BYREF padwIntent AS DWORD _                          ' __in  PDWORD padwIntent
 , BYVAL nIntents AS DWORD _                            ' __in  DWORD nIntents
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF pProfileData AS DWORD _                        ' __out PBYTE *pProfileData
 , BYVAL indexPreferredCMM AS DWORD _                   ' __in  DWORD indexPreferredCMM
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CreateColorTransformA IMPORT "MSCMS.DLL" ALIAS "CreateColorTransformA" ( _
   BYREF pahProfiles AS DWORD _                         ' __in PHPROFILE pahProfiles
 , BYREF pLogColorSpace AS LOGCOLORSPACEA _             ' __in LPLOGCOLORSPACE pLogColorSpace
 , BYVAL hDestProfile AS DWORD _                        ' __in HPROFILE hDestProfile
 , BYVAL hTargetProfile AS DWORD _                      ' __in HPROFILE hTargetProfile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HTRANSFORM

DECLARE FUNCTION CreateColorTransformW IMPORT "MSCMS.DLL" ALIAS "CreateColorTransformW" ( _
   BYREF pahProfiles AS DWORD _                         ' __in PHPROFILE pahProfiles
 , BYREF pLogColorSpace AS LOGCOLORSPACEW _             ' __in LPLOGCOLORSPACEW pLogColorSpace
 , BYVAL hDestProfile AS DWORD _                        ' __in HPROFILE hDestProfile
 , BYVAL hTargetProfile AS DWORD _                      ' __in HPROFILE hTargetProfile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HTRANSFORM

#IF %DEF(%UNICODE)
   MACRO CreateColorTransform = CreateColorTransformW
#ELSE
   MACRO CreateColorTransform = CreateColorTransformA
#ENDIF

DECLARE FUNCTION CreateMultiProfileTransform IMPORT "MSCMS.DLL" ALIAS "CreateMultiProfileTransform" ( _
   BYREF pahProfiles AS DWORD _                         ' __in PHPROFILE pahProfiles
 , BYVAL nProfiles AS DWORD _                           ' __in DWORD nProfiles
 , BYREF padwIntent AS DWORD _                          ' __in PDWORD padwIntent
 , BYVAL nIntents AS DWORD _                            ' __in DWORD nIntents
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL indexPreferredCMM AS DWORD _                   '__in  DWORD indexPreferredCMM
 ) AS DWORD                                             ' HTRANSFORM

DECLARE FUNCTION DeleteColorTransform IMPORT "MSCMS.DLL" ALIAS "DeleteColorTransform" ( _
   BYVAL hColorTransform AS DWORD _                     ' HTRANSFORM hColorTransform
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TranslateBitmapBits IMPORT "MSCMS.DLL" ALIAS "TranslateBitmapBits" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYREF pSrcBits AS ANY _                              ' __in PVOID pSrcBits
 , BYVAL bmInput AS LONG _                              ' __in BMFORMAT bmInput
 , BYVAL dwWidth AS DWORD _                             ' __in DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in DWORD dwHeight
 , BYVAL dwInputStride AS DWORD _                       ' __in DWORD dwInputStride
 , BYREF pDestBits AS ANY _                             ' __in_out PVOID pDestBits
 , BYVAL bmOutput AS LONG _                             ' __in BMFORMAT bmOutput
 , BYVAL dwOutputStride AS DWORD _                      ' __in DWORD dwOutputStride
 , BYVAL pfnCallback AS DWORD _                         ' __in PBMCALLBACKFN pfnCallback
 , BYVAL ulCallbackData AS DWORD _                      ' __in LPARAM ulCallbackData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CheckBitmapBits IMPORT "MSCMS.DLL" ALIAS "CheckBitmapBits" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYREF pSrcBits AS ANY _                              ' __in PVOID pSrcBits
 , BYVAL bmInput AS LONG _                              ' __in BMFORMAT bmInput
 , BYVAL dwWidth AS DWORD _                             ' __in DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in DWORD dwHeight
 , BYVAL dwStride AS DWORD _                            ' __in DWORD dwStride
 , BYREF paResult AS BYTE _                             ' __in_out PBYTE paResult
 , BYVAL pfnCallback AS DWORD _                         ' __in PBMCALLBACKFN pfnCallback
 , BYVAL lpCallbackData AS DWORD _                      ' __in LPARAM lpCallbackData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION TranslateColors IMPORT "MSCMS.DLL" ALIAS "TranslateColors" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYREF paInputColors AS tagCOLOR _                    ' __in PCOLOR paInputColors
 , BYVAL nColors AS DWORD _                             ' __in DWORD nColors
 , BYVAL ctInput AS LONG _                              ' __in COLORTYPE ctInput
 , BYREF paOutputColors AS tagCOLOR _                   ' __in_out PCOLOR paOutputColors
 , BYVAL ctOutput AS LONG _                             ' __in COLORTYPE ctOutput
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CheckColors IMPORT "MSCMS.DLL" ALIAS "CheckColors" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYREF paInputColors AS tagCOLOR _                    ' __in PCOLOR paInputColors
 , BYVAL nColors AS DWORD _                             ' __in DWORD nColors
 , BYVAL ctInput AS LONG _                              ' __in COLORTYPE ctInput
 , BYREF paResult AS BYTE _                             ' __in_out PBYTE paResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCMMInfo IMPORT "MSCMS.DLL" ALIAS "GetCMMInfo" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYVAL dwInfo AS DWORD _                              ' __in DWORD dwInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RegisterCMMA IMPORT "MSCMS.DLL" ALIAS "RegisterCMMA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYVAL cmmID AS DWORD _                               ' __in DWORD cmmID
 , BYREF pCMMdll AS ASCIIZ _                            ' __in PCSTR pCMMdll
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RegisterCMMW IMPORT "MSCMS.DLL" ALIAS "RegisterCMMW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYVAL cmmID AS DWORD _                               ' __in DWORD cmmID
 , BYREF pCMMdll AS WSTRINGZ _                          ' __in PCWSTR pCMMdll
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO RegisterCMM = RegisterCMMW
#ELSE
   MACRO RegisterCMM = RegisterCMMA
#ENDIF

DECLARE FUNCTION UnregisterCMMA IMPORT "MSCMS.DLL" ALIAS "UnregisterCMMA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYVAL cmmID AS DWORD _                               ' __in DWORD cmmID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UnregisterCMMW IMPORT "MSCMS.DLL" ALIAS "UnregisterCMMW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYVAL cmmID AS DWORD _                               ' __in DWORD cmmID
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UnregisterCMM = UnregisterCMMW
#ELSE
   MACRO UnregisterCMM = UnregisterCMMA
#ENDIF

DECLARE FUNCTION SelectCMM IMPORT "MSCMS.DLL" ALIAS "SelectCMM" ( _
   BYVAL cmmID AS DWORD _                               ' __in DWORD cmmID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorDirectoryA IMPORT "MSCMS.DLL" ALIAS "GetColorDirectoryA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in  PCSTR pMachineName
 , BYREF pBuffer AS ASCIIZ _                            ' __out_bcount_part(*pdwSize, *pdwSize) PSTR pBuffer
 , BYREF pdwSize AS DWORD _                             ' __out PDWORD pdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetColorDirectoryW IMPORT "MSCMS.DLL" ALIAS "GetColorDirectoryW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in  PCWSTR pMachineName
 , BYVAL pBuffer AS DWORD _                             ' __out_bcount_part(*pdwSize, *pdwSize) PWSTR pBuffer
 , BYREF pdwSize AS DWORD _                             ' __out PDWORD pdwSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetColorDirectory = GetColorDirectoryW
#ELSE
   MACRO GetColorDirectory = GetColorDirectoryA
#ENDIF

DECLARE FUNCTION InstallColorProfileA IMPORT "MSCMS.DLL" ALIAS "InstallColorProfileA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYREF pProfileName AS ASCIIZ _                       ' __in PCSTR pProfileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InstallColorProfileW IMPORT "MSCMS.DLL" ALIAS "InstallColorProfileW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO InstallColorProfile = InstallColorProfileW
#ELSE
   MACRO InstallColorProfile = InstallColorProfileA
#ENDIF

DECLARE FUNCTION UninstallColorProfileA IMPORT "MSCMS.DLL" ALIAS "UninstallColorProfileA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYREF pProfileName AS ASCIIZ _                       ' __in PCSTR pProfileName
 , BYVAL bDelete AS LONG _                              ' __in BOOL bDelete
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UninstallColorProfileW IMPORT "MSCMS.DLL" ALIAS "UninstallColorProfileW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 , BYVAL bDelete AS LONG _                              ' __in BOOL bDelete
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO UninstallColorProfile = UninstallColorProfileW
#ELSE
   MACRO UninstallColorProfile = UninstallColorProfileA
#ENDIF

DECLARE FUNCTION EnumColorProfilesA IMPORT "MSCMS.DLL" ALIAS "EnumColorProfilesA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYREF pEnumRecord AS ENUMTYPEA _                     ' __in PENUMTYPE pEnumRecord
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pdwSize AS DWORD _                             ' __out PDWORD pdwSize
 , BYREF pnProfiles AS DWORD _                          ' __out PDWORD pnProfiles
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumColorProfilesW IMPORT "MSCMS.DLL" ALIAS "EnumColorProfilesW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYREF pEnumRecord AS ENUMTYPEW _                     ' __in PENUMTYPEW pEnumRecord
 , BYVAL pBuffer AS BYTE PTR _                          ' __in_out PBYTE pBuffer
 , BYREF pdwSize AS DWORD _                             ' __out PDWORD pdwSize
 , BYREF pnProfiles AS DWORD _                          ' __out PDWORD pnProfiles
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumColorProfiles = EnumColorProfilesW
#ELSE
   MACRO EnumColorProfiles = EnumColorProfilesA
#ENDIF

DECLARE FUNCTION SetStandardColorSpaceProfileA IMPORT "MSCMS.DLL" ALIAS "SetStandardColorSpaceProfileA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYVAL dwProfileID AS DWORD _                         ' __in DWORD dwProfileID
 , BYREF pProfilename AS ASCIIZ _                       ' __in PCSTR pProfilename
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetStandardColorSpaceProfileW IMPORT "MSCMS.DLL" ALIAS "SetStandardColorSpaceProfileW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYVAL dwProfileID AS DWORD _                         ' __in DWORD dwProfileID
 , BYREF pProfilename AS WSTRINGZ _                     ' __in PCSWTR pProfilename
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetStandardColorSpaceProfile = SetStandardColorSpaceProfileW
#ELSE
   MACRO SetStandardColorSpaceProfile = SetStandardColorSpaceProfileA
#ENDIF

DECLARE FUNCTION GetStandardColorSpaceProfileA IMPORT "MSCMS.DLL" ALIAS "GetStandardColorSpaceProfileA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYVAL dwSCS AS DWORD _                               ' __in DWORD dwSCS
 , BYREF pBuffer AS ASCIIZ _                            ' __out_bcount_part(*pcbSize, *pcbSize) PSTR pBuffer
 , BYREF pcbSize AS DWORD _                             ' __in_out PDWORD pcbSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetStandardColorSpaceProfileW IMPORT "MSCMS.DLL" ALIAS "GetStandardColorSpaceProfileW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYVAL dwSCS AS DWORD _                               ' __in DWORD dwSCS
 , BYVAL pBuffer AS DWORD _                             ' __out_bcount_part(*pcbSize, *pcbSize) PWSTR pBuffer
 , BYREF pcbSize AS DWORD _                             ' __in_out PDWORD pcbSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetStandardColorSpaceProfile = GetStandardColorSpaceProfileW
#ELSE
   MACRO GetStandardColorSpaceProfile = GetStandardColorSpaceProfileA
#ENDIF

DECLARE FUNCTION AssociateColorProfileWithDeviceA IMPORT "MSCMS.DLL" ALIAS "AssociateColorProfileWithDeviceA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYREF pProfileName AS ASCIIZ _                       ' __in PCSTR pProfileName
 , BYREF pDeviceName AS ASCIIZ _                        ' __in PCSTR pDeviceName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AssociateColorProfileWithDeviceW IMPORT "MSCMS.DLL" ALIAS "AssociateColorProfileWithDeviceW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in PCWSTR pDeviceName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO AssociateColorProfileWithDevice = AssociateColorProfileWithDeviceW
#ELSE
   MACRO AssociateColorProfileWithDevice = AssociateColorProfileWithDeviceA
#ENDIF

DECLARE FUNCTION DisassociateColorProfileFromDeviceA IMPORT "MSCMS.DLL" ALIAS "DisassociateColorProfileFromDeviceA" ( _
   BYREF pMachineName AS ASCIIZ _                       ' __in PCSTR pMachineName
 , BYREF pProfileName AS ASCIIZ _                       ' __in PCSTR pProfileName
 , BYREF pDeviceName AS ASCIIZ _                        ' __in PCSTR pDeviceName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DisassociateColorProfileFromDeviceW IMPORT "MSCMS.DLL" ALIAS "DisassociateColorProfileFromDeviceW" ( _
   BYREF pMachineName AS WSTRINGZ _                     ' __in PCWSTR pMachineName
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in PCWSTR pDeviceName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DisassociateColorProfileFromDevice = DisassociateColorProfileFromDeviceW
#ELSE
   MACRO DisassociateColorProfileFromDevice = DisassociateColorProfileFromDeviceA
#ENDIF

'//
'// The APIs SetupColorMatchingA and SetupColorMatchingW are
'// deprecated as of Windows Vista. The implementations in icmui.dll
'// now SetLastError to ERROR_NOT_SUPPORTED, and return FALSE.
'//

DECLARE FUNCTION SetupColorMatchingW IMPORT "ICMUI.DLL" ALIAS "SetupColorMatchingW" ( _
   BYREF pcms AS COLORMATCHSETUPW _                     ' __in PCOLORMATCHSETUPW pcms
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupColorMatchingA IMPORT "ICMUI.DLL" ALIAS "SetupColorMatchingA" ( _
   BYREF pcms AS COLORMATCHSETUPA _                     ' __in PCOLORMATCHSETUPA pcms
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupColorMatching = SetupColorMatchingW
#ELSE
   MACRO SetupColorMatching = SetupColorMatchingA
#ENDIF

'#if NTDDI_VERSION >= NTDDI_VISTA

DECLARE FUNCTION WcsAssociateColorProfileWithDevice IMPORT "MSCMS.DLL" ALIAS "WcsAssociateColorProfileWithDevice" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in PCWSTR pDeviceName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsDisassociateColorProfileFromDevice IMPORT "MSCMS.DLL" ALIAS "WcsDisassociateColorProfileFromDevice" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pProfileName AS WSTRINGZ _                     ' __in PCWSTR pProfileName
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in PCWSTR pDeviceName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsEnumColorProfilesSize IMPORT "MSCMS.DLL" ALIAS "WcsEnumColorProfilesSize" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pEnumRecord AS ENUMTYPEW _                     ' __in PENUMTYPEW pEnumRecord
 , BYREF pdwSize AS DWORD _                             ' __out PDWORD pdwSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsEnumColorProfiles IMPORT "MSCMS.DLL" ALIAS "WcsEnumColorProfiles" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pEnumRecord AS ENUMTYPEW _                     ' __in PENUMTYPEW pEnumRecord
 , BYVAL pBuffer AS DWORD _                             ' __out_bcount(dwSize) PBYTE pBuffer
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYREF pnProfiles AS DWORD _                          ' __out_opt PDWORD pnProfiles
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsGetDefaultColorProfileSize IMPORT "MSCMS.DLL" ALIAS "WcsGetDefaultColorProfileSize" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in_opt PCWSTR pDeviceName
 , BYVAL cptColorProfileType AS LONG _                  ' __in COLORPROFILETYPE cptColorProfileType
 , BYVAL cpstColorProfileSubType AS LONG _              ' __in COLORPROFILESUBTYPE cpstColorProfileSubType
 , BYVAL dwProfileID AS DWORD _                         ' __in DWORD dwProfileID
 , BYREF pcbProfileName AS DWORD _                      ' __out PDWORD pcbProfileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsGetDefaultColorProfile IMPORT "MSCMS.DLL" ALIAS "WcsGetDefaultColorProfile" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in_opt PCWSTR pDeviceName
 , BYVAL cptColorProfileType AS LONG _                  ' __in COLORPROFILETYPE cptColorProfileType
 , BYVAL cpstColorProfileSubType AS LONG _              ' __in COLORPROFILESUBTYPE cpstColorProfileSubType
 , BYVAL dwProfileID AS DWORD _                         ' __in DWORD dwProfileID
 , BYVAL cbProfileName AS DWORD _                       ' __in DWORD cbProfileName
 , BYREF pProfileName AS WSTRINGZ _                     ' __out_bcount(cbProfileName) LPWSTR pProfileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsSetDefaultColorProfile IMPORT "MSCMS.DLL" ALIAS "WcsSetDefaultColorProfile" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pDeviceName AS WSTRINGZ _                      ' __in_opt PCWSTR pDeviceName
 , BYVAL cptColorProfileType AS LONG _                  ' __in COLORPROFILETYPE cptColorProfileType
 , BYVAL cpstColorProfileSubType AS LONG _              ' __in COLORPROFILESUBTYPE cpstColorProfileSubType
 , BYVAL dwProfileID AS DWORD _                         ' __in DWORD dwProfileID
 , BYREF pProfileName AS WSTRINGZ _                     ' __in_opt LPCWSTR pProfileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsSetDefaultRenderingIntent IMPORT "MSCMS.DLL" ALIAS "WcsSetDefaultRenderingIntent" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYVAL dwRenderingIntent AS DWORD _                   ' __in DWORD dwRenderingIntent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsGetDefaultRenderingIntent IMPORT "MSCMS.DLL" ALIAS "WcsGetDefaultRenderingIntent" ( _
   BYVAL scope AS LONG _                                ' __in WCS_PROFILE_MANAGEMENT_SCOPE scope
 , BYREF pdwRenderingIntent AS DWORD _                  ' __out PDWORD pdwRenderingIntent
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsGetUsePerUserProfiles IMPORT "MSCMS.DLL" ALIAS "WcsGetUsePerUserProfiles" ( _
   BYREF pDeviceName AS WSTRINGZ _                      ' __in LPCWSTR pDeviceName
 , BYVAL dwDeviceClass AS DWORD _                       ' __in DWORD dwDeviceClass
 , BYREF pUsePerUserProfiles AS LONG _                  ' __out PBOOL pUsePerUserProfiles
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsSetUsePerUserProfiles IMPORT "MSCMS.DLL" ALIAS "WcsSetUsePerUserProfiles" ( _
   BYREF pDeviceName AS WSTRINGZ _                      ' __in LPCWSTR pDeviceName
 , BYVAL dwDeviceClass AS DWORD _                       ' __in DWORD dwDeviceClass
 , BYVAL usePerUserProfiles AS LONG _                   ' __in BOOL usePerUserProfiles
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsTranslateColors IMPORT "MSCMS.DLL" ALIAS "WcsTranslateColors" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYVAL nColors AS DWORD _                             ' __in DWORD nColors
 , BYVAL nInputChannels AS DWORD _                      ' __in DWORD nInputChannels
 , BYVAL cdtInput AS LONG _                             ' __in COLORDATATYPE cdtInput
 , BYVAL cbInput AS DWORD _                             ' __in DWORD cbInput
 , BYREF pInputData AS ANY _                            ' __in_bcount(cbInput) PVOID pInputData
 , BYVAL nOutputChannels AS DWORD _                     ' __in DWORD nOutputChannels
 , BYVAL cdtOutput AS LONG _                            ' __in COLORDATATYPE cdtOutput
 , BYVAL cbOutput AS DWORD _                            ' __in DWORD cbOutput
 , BYREF pOutputData AS ANY _                           ' __out_bcount(cbOutput) PVOID pOutputData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsCheckColors IMPORT "MSCMS.DLL" ALIAS "WcsCheckColors" ( _
   BYVAL hColorTransform AS DWORD _                     ' __in HTRANSFORM hColorTransform
 , BYVAL nColors AS DWORD _                             ' __in DWORD nColors
 , BYVAL nInputChannels AS DWORD _                      ' __in DWORD nInputChannels
 , BYVAL cdtInput AS LONG _                             ' __in COLORDATATYPE cdtInput
 , BYVAL cbInput AS DWORD _                             ' __in DWORD cbInput
 , BYREF pInputData AS ANY _                            ' __in_bcount(cbInput) PVOID pInputData
 , BYREF paResult AS BYTE _                             ' __out_ecount(nColors) PBYTE paResult
 ) AS LONG                                              ' BOOL

'#endif // NTDDI_VERSION >= NTDDI_VISTA


'//
'// Transform returned by CMM
'//

'typedef HANDLE  HCMTRANSFORM;

'//
'// Pointer to ICC color profile data.
'//

'typedef PVOID   LPDEVCHARACTER;

'//
'// CMM API definition
'//

DECLARE FUNCTION CMCheckColors IMPORT "ICM32.DLL" ALIAS "CMCheckColors" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in  HCMTRANSFORM hcmTransform
 , BYREF lpaInputColors AS tagCOLOR _                   ' __in  LPCOLOR lpaInputColors
 , BYVAL nColors AS DWORD _                             ' __in  DWORD nColors
 , BYVAL ctInput AS LONG _                              ' __in  COLORTYPE ctInput
 , BYREF lpaResult AS BYTE _                            ' __out LPBYTE lpaResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMCheckRGBs IMPORT "ICM32.DLL" ALIAS "CMCheckRGBs" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in  HCMTRANSFORM hcmTransform
 , BYREF lpSrcBits AS ANY _                             ' __in  LPVOID lpSrcBits
 , BYVAL bmInput AS LONG _                              ' __in  BMFORMAT bmInput
 , BYVAL dwWidth AS DWORD _                             ' __in  DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in  DWORD dwHeight
 , BYVAL dwStride AS DWORD _                            ' __in  DWORD dwStride
 , BYREF lpaResult AS BYTE _                            ' __out LPBYTE lpaResult
 , BYVAL pfnCallback AS DWORD _                         ' __in  PBMCALLBACKFN pfnCallback
 , BYVAL ulCallbackData AS DWORD _                      ' __in  LPARAM ulCallbackData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMConvertColorNameToIndex IMPORT "ICM32.DLL" ALIAS "CMConvertColorNameToIndex" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYREF paColorName AS ANY _                           ' __in PCOLOR_NAME paColorName
 , BYREF paIndex AS DWORD _                             ' __in PDWORD paIndex
 , BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMConvertIndexToColorName IMPORT "ICM32.DLL" ALIAS "CMConvertIndexToColorName" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYREF paIndex AS DWORD _                             ' __in PDWORD paIndex
 , BYREF paColorName AS ANY _                           ' __in PCOLOR_NAME paColorName
 , BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMCreateDeviceLinkProfile IMPORT "ICM32.DLL" ALIAS "CMCreateDeviceLinkProfile" ( _
   BYREF pahProfiles AS DWORD _                         ' __in  PHPROFILE pahProfiles
 , BYVAL nProfiles AS DWORD _                           ' __in  DWORD nProfiles
 , BYREF padwIntents AS DWORD _                         ' __in  PDWORD padwIntents
 , BYVAL nIntents AS DWORD _                            ' __in  DWORD nIntents
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lpProfileData AS DWORD _                       ' __out LPBYTE *lpProfileData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMCreateMultiProfileTransform IMPORT "ICM32.DLL" ALIAS "CMCreateMultiProfileTransform" ( _
   BYREF pahProfiles AS DWORD _                         ' __in PHPROFILE pahProfiles
 , BYVAL nProfiles AS DWORD _                           ' __in DWORD nProfiles
 , BYREF padwIntents AS DWORD _                         ' __in PDWORD padwIntents
 , BYVAL nIntents AS DWORD _                            ' __in DWORD nIntents
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

' // See CMCreateProfile below
DECLARE FUNCTION CMCreateProfileW IMPORT "ICM32.DLL" ALIAS "CMCreateProfileW" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEW _               ' __in  LPLOGCOLORSPACEW lpColorSpace
 , BYREF lpProfileData AS DWORD _                       ' __out LPDEVCHARACTER *lpProfileData
 ) AS LONG                                              ' BOOL

'//
'// The CMM APIs CMCreateTransform, CMCreateTransformW, and CMCreateTransformExt are
'// deprecated as of Windows Vista, and CMM implementors are no longer required to
'// implement them. The implementations in the default CMM (icm32.dll) in Windows Vista
'// now SetLastError to ERROR_NOT_SUPPORTED, and return an invalid transform handle
'// (a value < 256).
'//

DECLARE FUNCTION CMCreateTransformA IMPORT "ICM32.DLL" ALIAS "CMCreateTransform" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEA _               ' __in LPLOGCOLORSPACEA lpColorSpace
 , BYREF lpDevCharacter AS ANY _                        ' __in LPDEVCHARACTER lpDevCharacter
 , BYREF lpTargetDevCharacter AS ANY _                  ' __in LPDEVCHARACTER lpTargetDevCharacter
 ) AS DWORD                                             ' HCMTRANSFORM

DECLARE FUNCTION CMCreateTransformW IMPORT "ICM32.DLL" ALIAS "CMCreateTransformW" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEW _               ' __in LPLOGCOLORSPACEW lpColorSpace
 , BYREF lpDevCharacter AS ANY _                        ' __in LPDEVCHARACTER lpDevCharacter
 , BYREF lpTargetDevCharacter AS ANY _                  ' __in LPDEVCHARACTER lpTargetDevCharacter
 ) AS DWORD                                             ' HCMTRANSFORM

#IF %DEF(%UNICODE)
   MACRO CMCreateTransform = CMCreateTransformW
#ELSE
   MACRO CMCreateTransform = CMCreateTransformA
#ENDIF

' // See CMCreateTransformExtW below
DECLARE FUNCTION CMCreateTransformExtA IMPORT "ICM32.DLL" ALIAS "CMCreateTransformExt" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEA _               ' __in LPLOGCOLORSPACEA lpColorSpace
 , BYREF lpDevCharacter AS ANY _                        ' __in LPDEVCHARACTER lpDevCharacter
 , BYREF lpTargetDevCharacter AS ANY _                  ' __in LPDEVCHARACTER lpTargetDevCharacter
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HCMTRANSFORM

'//
'// The CMM APIs CMCheckColorsInGamut, CMCreateProfile, CMTranslateRGB and CMTranslateRGBs are
'// deprecated as of Windows 7, and CMM implementors are no longer required to
'// implement them. The implementations in the default CMM (icm32.dll) in Windows 7
'// now SetLastError to ERROR_NOT_SUPPORTED, and return FALSE.
'//

DECLARE FUNCTION CMCheckColorsInGamut IMPORT "ICM32.DLL" ALIAS "CMCheckColorsInGamut" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in  HCMTRANSFORM hcmTransform
 , BYREF lpaRGBTriple AS RGBTRIPLE _                    ' __in  RGBTRIPLE *lpaRGBTriple
 , BYREF lpaResult AS BYTE _                            ' __out LPBYTE lpaResult
 , BYVAL nCount AS DWORD _                              ' __in  UINT nCount
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMCreateProfileA IMPORT "ICM32.DLL" ALIAS "CMCreateProfile" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEA _               ' __in  LPLOGCOLORSPACEA lpColorSpace
 , BYREF lpProfileData AS DWORD _                       ' __out LPDEVCHARACTER *lpProfileData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CMCreateProfile = CMCreateProfileW
#ELSE
   MACRO CMCreateProfile = CMCreateProfileA
#ENDIF

DECLARE FUNCTION CMTranslateRGB IMPORT "ICM32.DLL" ALIAS "CMTranslateRGB" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in  HCMTRANSFORM hcmTransform
 , BYVAL ColorRef AS DWORD _                            ' __in  COLORREF ColorRef
 , BYREF lpColorRef AS DWORD _                          ' __out LPCOLORREF lpColorRef
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMTranslateRGBs IMPORT "ICM32.DLL" ALIAS "CMTranslateRGBs" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in HCMTRANSFORM hcmTransform
 , BYREF lpSrcBits AS ANY _                             ' __in LPVOID lpSrcBits
 , BYVAL bmInput AS LONG _                              ' __in BMFORMAT bmInput
 , BYVAL dwWidth AS DWORD _                             ' __in DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in DWORD dwHeight
 , BYVAL dwStride AS DWORD _                            ' __in DWORD dwStride
 , BYREF lpDestBits AS ANY _                            ' __in_out LPVOID lpDestBits
 , BYVAL bmOutput AS LONG _                             ' __in BMFORMAT bmOutput
 , BYVAL dwTranslateDirection AS DWORD _                ' __in DWORD dwTranslateDirection
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMCreateTransformExtW IMPORT "ICM32.DLL" ALIAS "CMCreateTransformExtW" ( _
   BYREF lpColorSpace AS LOGCOLORSPACEW _               ' __in LPLOGCOLORSPACEW lpColorSpace
 , BYREF lpDevCharacter AS ANY _                        ' __in LPDEVCHARACTER lpDevCharacter
 , BYREF lpTargetDevCharacter AS ANY _                  ' __in LPDEVCHARACTER lpTargetDevCharacter
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HCMTRANSFORM

#IF %DEF(%UNICODE)
   MACRO CMCreateTransformExt = CMCreateTransformExtW
#ELSE
   MACRO CMCreateTransformExt = CMCreateTransformExtA
#ENDIF

DECLARE FUNCTION CMDeleteTransform IMPORT "ICM32.DLL" ALIAS "CMDeleteTransform" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in HCMTRANSFORM hcmTransform
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMGetInfo IMPORT "ICM32.DLL" ALIAS "CMGetInfo" ( _
   BYVAL dwInfo AS DWORD _                              ' __in DWORD dwInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMGetNamedProfileInfo IMPORT "ICM32.DLL" ALIAS "CMGetNamedProfileInfo" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF pNamedProfileInfo AS NAMED_PROFILE_INFO _      ' __out PNAMED_PROFILE_INFO pNamedProfileInfo
 ) AS LONG                                              ' BOOL

' This function is optional for all CMMs.
DECLARE FUNCTION CMGetPS2ColorRenderingDictionary IMPORT "ICM32.DLL" ALIAS "CMGetPS2ColorRenderingDictionary" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL lpBuffer AS BYTE PTR _                         ' __in_out LPBYTE lpBuffer
 , BYREF lpcbSize AS DWORD _                            ' __out LPDWORD lpcbSize
 , BYREF lpbBinary AS LONG _                            ' __out LPBOOL lpbBinary
 ) AS LONG                                              ' BOOL

' This function is optional for all CMMs.
DECLARE FUNCTION CMGetPS2ColorRenderingIntent IMPORT "ICM32.DLL" ALIAS "CMGetPS2ColorRenderingIntent" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL lpBuffer AS BYTE PTR _                         ' __in_out LPBYTE lpBuffer
 , BYREF lpcbSize AS DWORD _                            ' __out LPDWORD lpcbSize
 ) AS LONG                                              ' BOOL

' This function is optional for all CMMs.
DECLARE FUNCTION CMGetPS2ColorSpaceArray IMPORT "ICM32.DLL" ALIAS "CMGetPS2ColorSpaceArray" ( _
   BYVAL hProfile AS DWORD _                            ' __in HPROFILE hProfile
 , BYVAL dwIntent AS DWORD _                            ' __in DWORD dwIntent
 , BYVAL dwCSAType AS DWORD _                           ' __in DWORD dwCSAType
 , BYVAL lpBuffer AS BYTE PTR _                         ' __in_out LPBYTE lpBuffer
 , BYREF lpcbSize AS DWORD _                            ' __out LPDWORD lpcbSize
 , BYREF lpbBinary AS LONG _                            ' __out LPBOOL lpbBinary
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMIsProfileValid IMPORT "ICM32.DLL" ALIAS "CMIsProfileValid" ( _
   BYVAL hProfile AS DWORD _                            ' __in  HPROFILE hProfile
 , BYREF lpbValid AS LONG _                             ' __out LPBOOL lpbValid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMTranslateColors IMPORT "ICM32.DLL" ALIAS "CMTranslateColors" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in HCMTRANSFORM hcmTransform
 , BYREF lpaInputColors AS tagCOLOR _                   ' __in LPCOLOR lpaInputColors
 , BYVAL nColors AS DWORD _                             ' __in DWORD nColors
 , BYVAL ctInput AS LONG _                              ' __in COLORTYPE ctInput
 , BYREF lpaOutputColors AS tagCOLOR _                  ' __in_out LPCOLOR lpaOutputColors
 , BYVAL ctOutput AS LONG _                             ' __in COLORTYPE ctOutput
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CMTranslateRGBsExt IMPORT "ICM32.DLL" ALIAS "CMTranslateRGBsExt" ( _
   BYVAL hcmTransform AS DWORD _                        ' __in HCMTRANSFORM hcmTransform
 , BYREF lpSrcBits AS ANY _                             ' __in LPVOID lpSrcBits
 , BYVAL bmInput AS LONG _                              ' __in BMFORMAT bmInput
 , BYVAL dwWidth AS DWORD _                             ' __in DWORD dwWidth
 , BYVAL dwHeight AS DWORD _                            ' __in DWORD dwHeight
 , BYVAL dwInputStride AS DWORD _                       ' __in DWORD dwInputStride
 , BYREF lpDestBits AS ANY _                            ' __in_out LPVOID lpDestBits
 , BYVAL bmOutput AS LONG _                             ' __in BMFORMAT bmOutput
 , BYVAL dwOutputStride AS DWORD _                      ' __in DWORD dwOutputStride
 , BYVAL lpfnCallback AS DWORD _                        ' __in LPBMCALLBACKFN lpfnCallback
 , BYVAL ulCallbackData AS DWORD _                      ' __in LPARAM ulCallbackData
 ) AS LONG                                              ' BOOL

'#if NTDDI_VERSION >= NTDDI_VISTA

'//
'//    Windows Color System APIs
'//


'//
'// Passed in as a bit-flag for dwFlags, this instructs WcsOpenColorProfile
'// to ignore any embedded Wcs information in the WcsProfiles tag if the input
'// profile is an ICC one.
'//

%DONT_USE_EMBEDDED_WCS_PROFILES = &H00000001???

DECLARE FUNCTION WcsOpenColorProfileA IMPORT "MSCMS.DLL" ALIAS "WcsOpenColorProfileA" ( _
   BYREF pCDMPProfile AS tagPROFILE _                   ' __in        PPROFILE pCDMPProfile
 , BYREF pCAMPProfile AS tagPROFILE _                   ' __in_opt    PPROFILE pCAMPProfile
 , BYREF pGMMPProfile AS tagPROFILE _                   ' __in_opt    PPROFILE pGMMPProfile
 , BYVAL dwDesireAccess AS DWORD _                      ' __in        DWORD    dwDesireAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in        DWORD    dwShareMode
 , BYVAL dwCreationMode AS DWORD _                      ' __in        DWORD    dwCreationMode
 , BYVAL dwFlags AS DWORD _                             ' __in        DWORD    dwFlags
 ) AS DWORD                                             ' HPROFILE

DECLARE FUNCTION WcsOpenColorProfileW IMPORT "MSCMS.DLL" ALIAS "WcsOpenColorProfileW" ( _
   BYREF pCDMPProfile AS tagPROFILE _                   ' __in        PPROFILE pCDMPProfile
 , BYREF pCAMPProfile AS tagPROFILE _                   ' __in_opt    PPROFILE pCAMPProfile
 , BYREF pGMMPProfile AS tagPROFILE _                   ' __in_opt    PPROFILE pGMMPProfile
 , BYVAL dwDesireAccess AS DWORD _                      ' __in        DWORD    dwDesireAccess
 , BYVAL dwShareMode AS DWORD _                         ' __in        DWORD    dwShareMode
 , BYVAL dwCreationMode AS DWORD _                      ' __in        DWORD    dwCreationMode
 , BYVAL dwFlags AS DWORD _                             ' __in        DWORD    dwFlags
 ) AS DWORD                                             ' HPROFILE

#IF %DEF(%UNICODE)
   MACRO WcsOpenColorProfile = WcsOpenColorProfileW
#ELSE
   MACRO WcsOpenColorProfile = WcsOpenColorProfileA
#ENDIF

'//
'// Flags for WcsCreateIccProfile.
'//
'// By default, the original WCS profiles used for the conversion are embedded
'// in the output ICC profile in a WcsProfilesTag, resulting in an ICC profile
'// which is compatible with ICC software, yet still has the original WCS
'// profile data available to code which is designed to parse it.
'//
'// This flag is set to produce an ICC profile without any of the original
'// WCS profile data embedded. The WcsProfilesTag will not be present in the
'// output profile. This will result in a smaller output profile, however the
'// original WCS profile data will not be available to code that would be able
'// to parse it instead of the ICC data.
'//
'//
'// These flags should be ORed in with one of the four ICC INTENT_ flags
'// Thus, they must use different bits from the INTENT_ flags. Currrently, the INTENT_ flags
'// use the values 0-3, or the low order two bits. Hence we use the third lowest bit.
'//


%WCS_DEFAULT = &H00000000???
%WCS_ICCONLY = &H00010000???

DECLARE FUNCTION WcsCreateIccProfile IMPORT "MSCMS.DLL" ALIAS "WcsCreateIccProfile" ( _
   BYVAL hWcsProfile AS DWORD _                         ' __in HPROFILE hWcsProfile
 , BYVAL dwOptions AS DWORD _                           ' __in DWORD dwOptions
 ) AS DWORD                                             ' HPROFILE

'//
'// ICC TAGTYPE for the embedded Wcs information.
'//

$WCS_EMBEDDED_TAG_SIGNATURE      = "MS00"
$WCS_EMBEDDED_TAG_TYPE_SIGNATURE = "MS10"

'#endif // NTDDI_VERSION >= NTDDI_VISTA

'#if NTDDI_VERSION >= NTDDI_WIN7

DECLARE FUNCTION WcsGetCalibrationManagementState IMPORT "MSCMS.DLL" ALIAS "WcsGetCalibrationManagementState" ( _
   BYREF pbIsEnabled AS LONG _                          ' __out BOOL *pbIsEnabled
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WcsSetCalibrationManagementState IMPORT "MSCMS.DLL" ALIAS "WcsSetCalibrationManagementState" ( _
   BYVAL bIsEnabled AS LONG _                           ' __in BOOL bIsEnabled
 ) AS LONG                                              ' BOOL
'#endif // NTDDI_VERSION >= NTDDI_WIN7
