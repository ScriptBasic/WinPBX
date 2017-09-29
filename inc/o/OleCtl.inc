' ########################################################################################
' Microsoft Windows
' File: OleCtl.inc
' Contents: OLE Version 2.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLECTL_INC = 1

#INCLUDE ONCE "ocidl.inc"

'#if !defined(INITGUID)

'DEFINE_GUID(IID_IPropertyFrame,
'   0xB196B28A,0xBAB4,0x101A,0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07);
$IID_IPropertyFrame               = GUID$("{B196B28A-BAB4-101A-B69C-00AA00341D07}")

'//
'//  Class IDs for property sheet implementations
'//

'DEFINE_GUID(CLSID_CFontPropPage,
'   0x0be35200,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
'DEFINE_GUID(CLSID_CColorPropPage,
'   0x0be35201,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
'DEFINE_GUID(CLSID_CPicturePropPage,
'   0x0be35202,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

$CLSID_CFontPropPage              = GUID$("{0BE35200-8F91-11CE-9DE3-00AA004BB851}")
$CLSID_CColorPropPage             = GUID$("{0BE35201-8F91-11CE-9DE3-00AA004BB851}")
$CLSID_CPicturePropPage           = GUID$("{0BE35202-8F91-11CE-9DE3-00AA004BB851}")

'//
'//  Class IDs for persistent property set formats
'//

'DEFINE_GUID(CLSID_PersistPropset,
'   0xfb8f0821,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);
'DEFINE_GUID(CLSID_ConvertVBX,
'   0xfb8f0822,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);

$CLSID_PersistPropset             = GUID$("{FB8F0821-0164-101B-84ED-08002B2EC713}")
$CLSID_ConvertVBX                 = GUID$("{FB8F0822-0164-101B-84ED-08002B2EC713}")

'//
'//  Class ID for standard implementations of IFont and IPicture

'DEFINE_GUID(CLSID_StdFont,
'   0x0be35203,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);
'DEFINE_GUID(CLSID_StdPicture,
'   0x0be35204,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

$CLSID_StdFont                    = GUID$("{0BE35203-8F91-11CE-9DE3-00AA004BB851}")
$CLSID_StdPicture                 = GUID$("{0BE35204-8F91-11CE-9DE3-00AA004BB851}")

' ========================================================================================
' CoClass name = StdFont
' Interface name = Font
' IID = {BEF6E003-A874-101A-8BBA-00AA00300CAB}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ========================================================================================

#IF NOT %DEF(%StdFont_DISPINTERFACE_DEFINED)
    %StdFont_DISPINTERFACE_DEFINED = 1

INTERFACE IDBIND StdFont
   MEMBER GET  Name <0> () AS WSTRING
   MEMBER LET  Name <0> ()   ' Parameter Type AS STRING
   MEMBER GET  Size <2> () AS CUR
   MEMBER LET  Size <2> ()   ' Parameter Type AS CUR
   MEMBER GET  Bold <3> () AS INTEGER
   MEMBER LET  Bold <3> ()   ' Parameter Type AS INTEGER
   MEMBER GET  Italic <4> () AS INTEGER
   MEMBER LET  Italic <4> ()   ' Parameter Type AS INTEGER
   MEMBER GET  Underline <5> () AS INTEGER
   MEMBER LET  Underline <5> ()   ' Parameter Type AS INTEGER
   MEMBER GET  Strikethrough <6> () AS INTEGER
   MEMBER LET  Strikethrough <6> ()   ' Parameter Type AS INTEGER
   MEMBER GET  Weight <7> () AS INTEGER
   MEMBER LET  Weight <7> ()   ' Parameter Type AS INTEGER
   MEMBER GET  Charset <8> () AS INTEGER
   MEMBER LET  Charset <8> ()   ' Parameter Type AS INTEGER
END INTERFACE

#ENDIF   ' /* __StdFont_DISPINTERFACE_DEFINED__ */

' ========================================================================================
' CoClass name = StdPicture
' Interface name = Picture
' IID = {7BF80981-BF32-101A-8BBB-00AA00300CAB}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ========================================================================================

#IF NOT %DEF(%StdPicture_DISPINTERFACE_DEFINED)
    %StdPicture_DISPINTERFACE_DEFINED = 1

INTERFACE IDBIND StdPicture
   MEMBER CALL Render <6> (prm_hdc AS LONG<0>, _
               prm_x AS LONG<1>, _
               prm_y AS LONG<2>, _
               prm_cx AS LONG<3>, _
               prm_cy AS LONG<4>, _
               prm_xSrc AS LONG<5>, _
               prm_ySrc AS LONG<6>, _
               prm_cxSrc AS LONG<7>, _
               prm_cySrc AS LONG<8>, _
               prm_prcWBounds AS DWORD<9>)
   MEMBER GET  Handle <0> () AS LONG   ' OLE_HANDLE
   MEMBER GET  hPal <2> () AS LONG   ' OLE_HANDLE
   MEMBER LET  hPal <2> ()   ' Parameter Type AS LONG <OLE_HANDLE>
   MEMBER GET  Type <3> () AS INTEGER
   MEMBER GET  Width <4> () AS LONG   ' OLE_XSIZE_HIMETRIC
   MEMBER GET  Height <5> () AS LONG   ' OLE_YSIZE_HIMETRIC
END INTERFACE

#ENDIF   ' /* __Picture_DISPINTERFACE_DEFINED__ */

'//
'//  GUIDs for standard types
'//

'DEFINE_GUID(GUID_HIMETRIC,
'   0x66504300,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_COLOR,
'   0x66504301,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_XPOSPIXEL,
'   0x66504302,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_YPOSPIXEL,
'   0x66504303,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_XSIZEPIXEL,
'   0x66504304,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_YSIZEPIXEL,
'   0x66504305,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_XPOS,
'   0x66504306,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_YPOS,
'   0x66504307,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_XSIZE,
'   0x66504308,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_YSIZE,
'   0x66504309,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

$GUID_HIMETRIC                   = GUID$("{66504300-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_COLOR                      = GUID$("{66504301-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_XPOSPIXEL                  = GUID$("{66504302-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_YPOSPIXEL                  = GUID$("{66504303-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_XSIZEPIXEL                 = GUID$("{66504304-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_YSIZEPIXEL                 = GUID$("{66504305-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_XPOS                       = GUID$("{66504306-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_YPOS                       = GUID$("{66504307-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_XSIZE                      = GUID$("{66504308-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_YSIZE                      = GUID$("{66504309-BE0F-101A-8BBB-00AA00300CAB}")

#IF NOT %DEF(%CGUID)
'DEFINE_GUID(GUID_TRISTATE,
'   0x6650430A,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
$GUID_TRISTATE                   = GUID$("{6650430A-BE0F-101A-8BBB-00AA00300CAB}")
#ENDIF

'DEFINE_GUID(GUID_OPTIONVALUEEXCLUSIVE,
'   0x6650430B,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_CHECKVALUEEXCLUSIVE,
'   0x6650430C,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTNAME,
'   0x6650430D,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTSIZE,
'   0x6650430E,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTBOLD,
'   0x6650430F,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTITALIC,
'   0x66504310,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTUNDERSCORE,
'   0x66504311,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_FONTSTRIKETHROUGH,
'   0x66504312,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);
'DEFINE_GUID(GUID_HANDLE,
'   0x66504313,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

$GUID_OPTIONVALUEEXCLUSIVE       = GUID$("{6650430B-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_CHECKVALUEEXCLUSIVE        = GUID$("{6650430C-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTNAME                   = GUID$("{6650430D-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTSIZE                   = GUID$("{6650430E-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTBOLD                   = GUID$("{6650430F-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTITALIC                 = GUID$("{66504310-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTUNDERSCORE             = GUID$("{66504311-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_FONTSTRIKETHROUGH          = GUID$("{66504312-BE0F-101A-8BBB-00AA00300CAB}")
$GUID_HANDLE                     = GUID$("{66504313-BE0F-101A-8BBB-00AA00300CAB}")

'#endif // INITGUID


'/////////////////////////////////////////////////////////////////////////////
'// OCPFIPARAMS structure - parameters for OleCreatePropertyFrameIndirect

' // Size = 44 bytes
TYPE OCPFIPARAMS DWORD
   cbStructSize          AS DWORD          ' ULONG cbStructSize
   hWndOwner             AS DWORD          ' HWND hWndOwner
   x                     AS LONG           ' int x
   y                     AS LONG           ' int y
   lpszCaption           AS WSTRINGZ PTR   ' LPCOLESTR lpszCaption
   cObjects              AS DWORD          ' ULONG cObjects
   lplpUnk               AS DWORD          ' LPUNKNOWN FAR* lplpUnk
   cPages                AS DWORD          ' ULONG cPages
   lpPages               AS GUID PTR       ' CLSID FAR* lpPages
   lcid                  AS LONG           ' LCID lcid
   dispIDInitialProperty AS LONG           ' DISPID dispidInitialProperty
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// FONTDESC structure

'#define FONTSIZE(n) { n##0000, 0 }

' // Size = 32 bytes
TYPE FONTDESC DWORD FILL
   cbSizeofstruct AS DWORD          ' UINT cbSizeofstruct
   lpstrName      AS WSTRINGZ PTR   ' LPOLESTR lpstrName
   cySize         AS CUR            ' CY cySize
   sWeight        AS INTEGER        ' SHORT sWeight
   sCharset       AS INTEGER        ' SHORT sCharset
   fItalic        AS LONG           ' BOOL fItalic
   fUnderline     AS LONG           ' BOOL fUnderline
   fStrikethrough AS LONG           ' BOOL fStrikethrough
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// PICTDESC structure

%PICTYPE_UNINITIALIZED = -1
%PICTYPE_NONE          = 0
%PICTYPE_BITMAP        = 1
%PICTYPE_METAFILE      = 2
%PICTYPE_ICON          = 3
'#ifdef _WIN32
%PICTYPE_ENHMETAFILE   = 4
'#endif

'typedef struct tagPICTDESC
'{
'    UINT cbSizeofstruct;
'    UINT picType;
'    union
'    {
'        struct
'        {
'            HBITMAP   hbitmap;        // Bitmap
'            HPALETTE  hpal;           // Accompanying palette
'        } bmp;

'        struct
'        {
'            HMETAFILE hmeta;          // Metafile
'            int       xExt;
'            int       yExt;           // Extent
'        } wmf;

'        struct
'        {
'            HICON hicon;              // Icon
'        } icon;

'#ifdef _WIN32
'        struct
'        {
'            HENHMETAFILE hemf;        // Enhanced Metafile
'        } emf;
'#endif
'    };

'} PICTDESC, FAR* LPPICTDESC;

' // Size = 8 bytes
TYPE BMP_STRUCT DWORD
   hbitmap AS DWORD          ' HBITMAP     hbitmap // Bitmap
   hpal    AS DWORD          ' HPALETTE    hpal    // Accompanying palette
END TYPE

' // Size = 12 bytes
TYPE WMF_STRUCT DWORD
   hmeta AS DWORD            ' HMETAFILE   hmeta   // Metafile
   xExt  AS WORD             ' int         xExt
   yExt  AS WORD             ' int         yExt    // Extent
END TYPE

' // Size = 12 bytes
UNION PICTDESCDATA DWORD
   BMP_STRUCT
   WMF_STRUCT
   hicon AS DWORD            ' HICON        hicon  // Icon
   hemf  AS DWORD            ' HENHMETAFILE hemf   // Enhanced Metafile
END UNION

' // Size = 20 bytes
TYPE PICTDESC DWORD
   cbSizeOfStruct AS DWORD   ' UINT cbSizeofstruct
   picType        AS DWORD   ' UINT picType
   PICTDESCDATA
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'// Typedefs for standard scalar types

'typedef long OLE_XPOS_PIXELS;
'typedef long OLE_YPOS_PIXELS;
'typedef long OLE_XSIZE_PIXELS;
'typedef long OLE_YSIZE_PIXELS;
'typedef float OLE_XPOS_CONTAINER;
'typedef float OLE_YPOS_CONTAINER;
'typedef float OLE_XSIZE_CONTAINER;
'typedef float OLE_YSIZE_CONTAINER;
'typedef enum { triUnchecked = 0, triChecked = 1, triGray = 2 } OLE_TRISTATE;
'typedef VARIANT_BOOL OLE_OPTEXCLUSIVE;
'typedef VARIANT_BOOL OLE_CANCELBOOL;
'typedef VARIANT_BOOL OLE_ENABLEDEFAULTBOOL;

' OLE_TRISTATE enum
%triUnchecked = 0
%triChecked   = 1
%triGray      = 2

'/////////////////////////////////////////////////////////////////////////////
'// FACILITY_CONTROL status codes

#IF NOT %DEF(%FACILITY_CONTROL)
   %FACILITY_CONTROL = &HA
#ENDIF

'#define STD_CTL_SCODE(n) MAKE_SCODE(SEVERITY_ERROR, FACILITY_CONTROL, n)
MACRO STD_CTL_SCODE(n) = MAKE_SCODE(%SEVERITY_ERROR, %FACILITY_CONTROL, n)

'#define CTL_E_ILLEGALFUNCTIONCALL       STD_CTL_SCODE(5)
'#define CTL_E_OVERFLOW                  STD_CTL_SCODE(6)
'#define CTL_E_OUTOFMEMORY               STD_CTL_SCODE(7)
'#define CTL_E_DIVISIONBYZERO            STD_CTL_SCODE(11)
'#define CTL_E_OUTOFSTRINGSPACE          STD_CTL_SCODE(14)
'#define CTL_E_OUTOFSTACKSPACE           STD_CTL_SCODE(28)
'#define CTL_E_BADFILENAMEORNUMBER       STD_CTL_SCODE(52)
'#define CTL_E_FILENOTFOUND              STD_CTL_SCODE(53)
'#define CTL_E_BADFILEMODE               STD_CTL_SCODE(54)
'#define CTL_E_FILEALREADYOPEN           STD_CTL_SCODE(55)
'#define CTL_E_DEVICEIOERROR             STD_CTL_SCODE(57)
'#define CTL_E_FILEALREADYEXISTS         STD_CTL_SCODE(58)
'#define CTL_E_BADRECORDLENGTH           STD_CTL_SCODE(59)
'#define CTL_E_DISKFULL                  STD_CTL_SCODE(61)
'#define CTL_E_BADRECORDNUMBER           STD_CTL_SCODE(63)
'#define CTL_E_BADFILENAME               STD_CTL_SCODE(64)
'#define CTL_E_TOOMANYFILES              STD_CTL_SCODE(67)
'#define CTL_E_DEVICEUNAVAILABLE         STD_CTL_SCODE(68)
'#define CTL_E_PERMISSIONDENIED          STD_CTL_SCODE(70)
'#define CTL_E_DISKNOTREADY              STD_CTL_SCODE(71)
'#define CTL_E_PATHFILEACCESSERROR       STD_CTL_SCODE(75)
'#define CTL_E_PATHNOTFOUND              STD_CTL_SCODE(76)
'#define CTL_E_INVALIDPATTERNSTRING      STD_CTL_SCODE(93)
'#define CTL_E_INVALIDUSEOFNULL          STD_CTL_SCODE(94)
'#define CTL_E_INVALIDFILEFORMAT         STD_CTL_SCODE(321)
'#define CTL_E_INVALIDPROPERTYVALUE      STD_CTL_SCODE(380)
'#define CTL_E_INVALIDPROPERTYARRAYINDEX STD_CTL_SCODE(381)
'#define CTL_E_SETNOTSUPPORTEDATRUNTIME  STD_CTL_SCODE(382)
'#define CTL_E_SETNOTSUPPORTED           STD_CTL_SCODE(383)
'#define CTL_E_NEEDPROPERTYARRAYINDEX    STD_CTL_SCODE(385)
'#define CTL_E_SETNOTPERMITTED           STD_CTL_SCODE(387)
'#define CTL_E_GETNOTSUPPORTEDATRUNTIME  STD_CTL_SCODE(393)
'#define CTL_E_GETNOTSUPPORTED           STD_CTL_SCODE(394)
'#define CTL_E_PROPERTYNOTFOUND          STD_CTL_SCODE(422)
'#define CTL_E_INVALIDCLIPBOARDFORMAT    STD_CTL_SCODE(460)
'#define CTL_E_INVALIDPICTURE            STD_CTL_SCODE(481)
'#define CTL_E_PRINTERERROR              STD_CTL_SCODE(482)
'#define CTL_E_CANTSAVEFILETOTEMP        STD_CTL_SCODE(735)
'#define CTL_E_SEARCHTEXTNOTFOUND        STD_CTL_SCODE(744)
'#define CTL_E_REPLACEMENTSTOOLONG       STD_CTL_SCODE(746)

%CTL_E_ILLEGALFUNCTIONCALL       = &H800A0005
%CTL_E_OVERFLOW                  = &H800A0006
%CTL_E_OUTOFMEMORY               = &H800A0007
%CTL_E_DIVISIONBYZERO            = &H800A000B
%CTL_E_OUTOFSTRINGSPACE          = &H800A000E
%CTL_E_OUTOFSTACKSPACE           = &H800A001C
%CTL_E_BADFILENAMEORNUMBER       = &H800A0034
%CTL_E_FILENOTFOUND              = &H800A0035
%CTL_E_BADFILEMODE               = &H800A0036
%CTL_E_FILEALREADYOPEN           = &H800A0037
%CTL_E_DEVICEIOERROR             = &H800A0039
%CTL_E_FILEALREADYEXISTS         = &H800A003A
%CTL_E_BADRECORDLENGTH           = &H800A003B
%CTL_E_DISKFULL                  = &H800A003D
%CTL_E_BADRECORDNUMBER           = &H800A003F
%CTL_E_BADFILENAME               = &H800A0040
%CTL_E_TOOMANYFILES              = &H800A0043
%CTL_E_DEVICEUNAVAILABLE         = &H800A0044
%CTL_E_PERMISSIONDENIED          = &H800A0046
%CTL_E_DISKNOTREADY              = &H800A0047
%CTL_E_PATHFILEACCESSERROR       = &H800A004B
%CTL_E_PATHNOTFOUND              = &H800A004C
%CTL_E_INVALIDPATTERNSTRING      = &H800A005D
%CTL_E_INVALIDUSEOFNULL          = &H800A005E
%CTL_E_INVALIDFILEFORMAT         = &H800A0141
%CTL_E_INVALIDPROPERTYVALUE      = &H800A017C
%CTL_E_INVALIDPROPERTYARRAYINDEX = &H800A017D
%CTL_E_SETNOTSUPPORTEDATRUNTIME  = &H800A017E
%CTL_E_SETNOTSUPPORTED           = &H800A017F
%CTL_E_NEEDPROPERTYARRAYINDEX    = &H800A0181
%CTL_E_SETNOTPERMITTED           = &H800A0183
%CTL_E_GETNOTSUPPORTEDATRUNTIME  = &H800A0189
%CTL_E_GETNOTSUPPORTED           = &H800A018A
%CTL_E_PROPERTYNOTFOUND          = &H800A01A6
%CTL_E_INVALIDCLIPBOARDFORMAT    = &H800A01CC
%CTL_E_INVALIDPICTURE            = &H800A01E1
%CTL_E_PRINTERERROR              = &H800A01E2
%CTL_E_CANTSAVEFILETOTEMP        = &H800A02DF
%CTL_E_SEARCHTEXTNOTFOUND        = &H800A02E8
%CTL_E_REPLACEMENTSTOOLONG       = &H800A02EA

'#define CUSTOM_CTL_SCODE(n) MAKE_SCODE(SEVERITY_ERROR, FACILITY_CONTROL, n)
'#define CTL_E_CUSTOM_FIRST              CUSTOM_CTL_SCODE(600)

MACRO CUSTOM_CTL_SCODE(n) = MAKE_SCODE(%SEVERITY_ERROR, %FACILITY_CONTROL, n)
%CTL_E_CUSTOM_FIRST              = &H800A0258


'/////////////////////////////////////////////////////////////////////////////
'// IConnectionPoint status codes

'#define CONNECT_E_FIRST    MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x0200)
'#define CONNECT_E_LAST     MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x020F)
'#define CONNECT_S_FIRST    MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x0200)
'#define CONNECT_S_LAST     MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x020F)

%CONNECT_E_FIRST         = &H80040200
%CONNECT_E_LAST          = &H8004020F
%CONNECT_S_FIRST         = &H00040200
%CONNECT_S_LAST          = &H0004020F

'#define CONNECT_E_NOCONNECTION      (CONNECT_E_FIRST+0)
%CONNECT_E_NOCONNECTION  = %CONNECT_E_FIRST + 0
'// there is no connection for this connection id

'#define CONNECT_E_ADVISELIMIT       (CONNECT_E_FIRST+1)
%CONNECT_E_ADVISELIMIT   = %CONNECT_E_FIRST + 1
'// this implementation's limit for advisory connections has been reached

'#define CONNECT_E_CANNOTCONNECT     (CONNECT_E_FIRST+2)
%CONNECT_E_CANNOTCONNECT = %CONNECT_E_FIRST + 2
'// connection attempt failed

'#define CONNECT_E_OVERRIDDEN        (CONNECT_E_FIRST+3)
%CONNECT_E_OVERRIDDEN    = %CONNECT_E_FIRST + 3
'// must use a derived interface to connect


'/////////////////////////////////////////////////////////////////////////////
'// DllRegisterServer/DllUnregisterServer status codes

'#define SELFREG_E_FIRST    MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x0200)
'#define SELFREG_E_LAST     MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x020F)
'#define SELFREG_S_FIRST    MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x0200)
'#define SELFREG_S_LAST     MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x020F)

%SELFREG_E_FIRST         = &H80040200
%SELFREG_E_LAST          = &H8004020F
%SELFREG_S_FIRST         = &H00040200
%SELFREG_S_LAST          = &H0004020F

'#define SELFREG_E_TYPELIB           (SELFREG_E_FIRST+0)
%SELFREG_E_TYPELIB       = %SELFREG_E_FIRST + 0
'// failed to register/unregister type library

'#define SELFREG_E_CLASS             (SELFREG_E_FIRST+1)
%SELFREG_E_CLASS         = %SELFREG_E_FIRST + 1
'// failed to register/unregister class

%CONNECT_E_CANNOTCONNECT = %CONNECT_E_FIRST + 2
'// connection attempt failed

%CONNECT_E_OVERRIDDEN    = %CONNECT_E_FIRST + 3
'// must use a derived interface to connect


'/////////////////////////////////////////////////////////////////////////////
'// IPerPropertyBrowsing status codes

'#define PERPROP_E_FIRST    MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x0200)
'#define PERPROP_E_LAST     MAKE_SCODE(SEVERITY_ERROR,   FACILITY_ITF, 0x020F)
'#define PERPROP_S_FIRST    MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x0200)
'#define PERPROP_S_LAST     MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_ITF, 0x020F)

%PERPROP_E_FIRST         = &H80040200
%PERPROP_E_LAST          = &H8004020F
%PERPROP_S_FIRST         = &H00040200
%PERPROP_S_LAST          = &H0004020F

'#define PERPROP_E_NOPAGEAVAILABLE   (PERPROP_E_FIRST+0)
%PERPROP_E_NOPAGEAVAILABLE = %PERPROP_E_FIRST + 0
'// no page available for requested property

%SELFREG_E_CLASS           = %SELFREG_E_FIRST + 1
'// failed to register/unregister class


'/////////////////////////////////////////////////////////////////////////////
'// OLEMISC_ constants (they are also defined in the latest oleidl.h)

#IF NOT %DEF(%IOleObject_INTERFACE_DEFINED)
%OLEMISC_INVISIBLEATRUNTIME           = &H400???
%OLEMISC_ALWAYSRUN                    = &H800???
%OLEMISC_ACTSLIKEBUTTON               = &H1000???
%OLEMISC_ACTSLIKELABEL                = &H2000???
%OLEMISC_NOUIACTIVATE                 = &H4000???
%OLEMISC_ALIGNABLE                    = &H8000???
%OLEMISC_SIMPLEFRAME                  = &H10000???
%OLEMISC_SETCLIENTSITEFIRST           = &H20000???
%OLEMISC_IMEMODE                      = &H40000???
#ENDIF

'/////////////////////////////////////////////////////////////////////////////
'// OLEIVERB_ constants

#IF NOT %DEF(%OLEIVERB_PROPERTIES)
   %OLEIVERB_PROPERTIES = -7&
#ENDIF


'/////////////////////////////////////////////////////////////////////////////
'// Variant type (VT_) tags for property sets

%VT_STREAMED_PROPSET      = 73        ' [P]  Stream contains a property set
%VT_STORED_PROPSET        = 74        ' [P]  Storage contains a property set
%VT_BLOB_PROPSET          = 75        ' [P]  Blob contains a property set
%VT_VERBOSE_ENUM          = 76        ' [P]  Enum value with text string


'/////////////////////////////////////////////////////////////////////////////
'// Variant type (VT_) tags that are just aliases for others

%VT_COLOR                 = %VT_I4
%VT_XPOS_PIXELS           = %VT_I4
%VT_YPOS_PIXELS           = %VT_I4
%VT_XSIZE_PIXELS          = %VT_I4
%VT_YSIZE_PIXELS          = %VT_I4
%VT_XPOS_HIMETRIC         = %VT_I4
%VT_YPOS_HIMETRIC         = %VT_I4
%VT_XSIZE_HIMETRIC        = %VT_I4
%VT_YSIZE_HIMETRIC        = %VT_I4
%VT_TRISTATE              = %VT_I2
%VT_OPTEXCLUSIVE          = %VT_BOOL
%VT_FONT                  = %VT_DISPATCH
%VT_PICTURE               = %VT_DISPATCH
%VT_HANDLE                = %VT_I4


'/////////////////////////////////////////////////////////////////////////////
'// Reflected Window Message IDs

%OCM__BASE             = %WM_USER   + &H1C00
%OCM_COMMAND           = %OCM__BASE + %WM_COMMAND

%OCM_CTLCOLORBTN       = %OCM__BASE + %WM_CTLCOLORBTN
%OCM_CTLCOLOREDIT      = %OCM__BASE + %WM_CTLCOLOREDIT
%OCM_CTLCOLORDLG       = %OCM__BASE + %WM_CTLCOLORDLG
%OCM_CTLCOLORLISTBOX   = %OCM__BASE + %WM_CTLCOLORLISTBOX
%OCM_CTLCOLORMSGBOX    = %OCM__BASE + %WM_CTLCOLORMSGBOX
%OCM_CTLCOLORSCROLLBAR = %OCM__BASE + %WM_CTLCOLORSCROLLBAR
%OCM_CTLCOLORSTATIC    = %OCM__BASE + %WM_CTLCOLORSTATIC

%OCM_DRAWITEM          = %OCM__BASE + %WM_DRAWITEM
%OCM_MEASUREITEM       = %OCM__BASE + %WM_MEASUREITEM
%OCM_DELETEITEM        = %OCM__BASE + %WM_DELETEITEM
%OCM_VKEYTOITEM        = %OCM__BASE + %WM_VKEYTOITEM
%OCM_CHARTOITEM        = %OCM__BASE + %WM_CHARTOITEM
%OCM_COMPAREITEM       = %OCM__BASE + %WM_COMPAREITEM
%OCM_HSCROLL           = %OCM__BASE + %WM_HSCROLL
%OCM_VSCROLL           = %OCM__BASE + %WM_VSCROLL
%OCM_PARENTNOTIFY      = %OCM__BASE + %WM_PARENTNOTIFY

'#if (WINVER >= 0x0400)
%OCM_NOTIFY            = %OCM__BASE + %WM_NOTIFY
'#endif


'/////////////////////////////////////////////////////////////////////////////
'// Self-registration APIs (to be implemented by server DLL)

'FUNCTION DllRegisterServer () AS LONG
'FUNCTION DllUnregisterServer () AS LONG


'/////////////////////////////////////////////////////////////////////////////
'// Property frame APIs

DECLARE FUNCTION OleCreatePropertyFrame IMPORT "OLEAUT32.DLL" ALIAS "OleCreatePropertyFrame" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL x AS DWORD _                                   ' __in UINT x
 , BYVAL y AS DWORD _                                   ' __in UINT y
 , BYREF lpszCaption AS WSTRINGZ _                      ' __in LPCOLESTR lpszCaption
 , BYVAL cObjects AS DWORD _                            ' __in ULONG cObjects
 , BYREF lplpUnk AS IUnknown _                          ' __in LPUNKNOWN FAR* lplpUnk
 , BYVAL cPages AS DWORD _                              ' __in ULONG cPages
 , BYVAL lpPageClsID AS GUID PTR _                      ' __in LPCLSID lpPageClsID [array]
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL lpvReserved AS DWORD _                         ' __in LPVOID lpvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreatePropertyFrameIndirect IMPORT "OLEAUT32.DLL" ALIAS "OleCreatePropertyFrameIndirect" ( _
   BYREF pParams AS OCPFIPARAMS _                       ' __in OCPFIPARAMS* pParams
 ) AS LONG                                              ' HRESULT


'/////////////////////////////////////////////////////////////////////////////
'// Standard type APIs

DECLARE FUNCTION OleTranslateColor IMPORT "OLEAUT32.DLL" ALIAS "OleTranslateColor" ( _
   BYVAL clr AS DWORD _                                 ' __in  OLE_COLOR clr
 , BYVAL hpal AS DWORD _                                ' __in  HPALETTE hpal
 , BYREF pcolorref AS DWORD _                           ' __out COLORREF *pcolorref
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreateFontIndirect IMPORT "OLEAUT32.DLL" ALIAS "OleCreateFontIndirect" ( _
   BYREF pFontDesc AS FONTDESC _                        ' __in  FONTDESC* pFontDesc
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out VOID** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleCreatePictureIndirect IMPORT "OLEAUT32.DLL" ALIAS "OleCreatePictureIndirect" ( _
   BYREF pPictDesc AS PICTDESC _                        ' __in  PICTDESC* pPictDesc
 , BYREF riid AS GUID _                                 ' __in  REFIID  riid
 , BYVAL fOwn AS LONG _                                 ' __in  BOOL fOwn
 , BYREF ppvObj AS ANY _                                ' __out VOID** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadPicture IMPORT "OLEAUT32.DLL" ALIAS "OleLoadPicture" ( _
   BYVAL pStream AS IStream _                           ' __in  IStream * pStream
 , BYVAL lSize AS LONG _                                ' __in  LONG lSize
 , BYVAL fRunmode AS LONG _                             ' __in  BOOL fRunmode
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadPictureEx IMPORT "OLEAUT32.DLL" ALIAS "OleLoadPictureEx" ( _
   BYVAL pStream AS IStream _                           ' __in  IStream * pStream
 , BYVAL lSize AS LONG _                                ' __in  LONG lSize
 , BYVAL fRunmode AS LONG _                             ' __in  BOOL fRunmode
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYVAL xSizeDesired AS DWORD _                        ' __in  DWORD xSizeDesired
 , BYVAL ySizeDesired AS DWORD _                        ' __in  DWORD ySizeDesired
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadPicturePath IMPORT "OLEAUT32.DLL" ALIAS "OleLoadPicturePath" ( _
   BYREF szURLorPath AS WSTRINGZ _                      ' __in  LPOLESTR szURLorPath
 , BYVAL punkCaller AS IUnknown _                       ' __in  LPUNKNOWN punkCaller
 , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
 , BYVAL clrReserved AS DWORD _                         ' __in  OLE_COLOR clrReserved
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvRet AS ANY _                                ' __out LPVOID *ppvRet
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadPictureFile IMPORT "OLEAUT32.DLL" ALIAS "OleLoadPictureFile" ( _
   BYVAL varFileName AS VARIANT _                       ' __in  VARIANT varFileName
 , BYREF lplpdispPicture AS IDispatch _                 ' __out LPDISPATCH *lplpdispPicture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleLoadPictureFileEx IMPORT "OLEAUT32.DLL" ALIAS "OleLoadPictureFileEx" ( _
   BYVAL varFileName AS VARIANT _                       ' __in  VARIANT varFileName
 , BYVAL xSizeDesired AS DWORD _                        ' __in  DWORD xSizeDesired
 , BYVAL ySizeDesired AS DWORD _                        ' __in  DWORD ySizeDesired
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF lplpdispPicture AS IDispatch _                 ' __out LPDISPATCH  *lplpdispPicture
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleSavePictureFile IMPORT "OLEAUT32.DLL" ALIAS "OleSavePictureFile" ( _
   BYVAL lpdispPicture AS IDispatch _                   ' __in LPDISPATCH lpdispPicture
 , BYVAL bstrFileName AS WSTRING _                      ' __in BSTR bstrFileName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OleIconToCursor IMPORT "OLEAUT32.DLL" ALIAS "OleIconToCursor" ( _
   BYVAL hinstExe AS DWORD _                            ' __in HINSTANCE hinstExe
 , BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 ) AS LONG                                              ' HRESULT

%LP_DEFAULT    = &H00
%LP_MONOCHROME = &H01
%LP_VGACOLOR   = &H02
%LP_COLOR      = &H04

'#if !defined(_MAC) && !defined(RC_INVOKED)
'#include <poppack.h>
'#endif


'/////////////////////////////////////////////////////////////////////////////
'//  Standard dispatch ID constants

%DISPID_AUTOSIZE                          = -500
%DISPID_BACKCOLOR                         = -501
%DISPID_BACKSTYLE                         = -502
%DISPID_BORDERCOLOR                       = -503
%DISPID_BORDERSTYLE                       = -504
%DISPID_BORDERWIDTH                       = -505
%DISPID_DRAWMODE                          = -507
%DISPID_DRAWSTYLE                         = -508
%DISPID_DRAWWIDTH                         = -509
%DISPID_FILLCOLOR                         = -510
%DISPID_FILLSTYLE                         = -511
%DISPID_FONT                              = -512
%DISPID_FORECOLOR                         = -513
%DISPID_ENABLED                           = -514
%DISPID_HWND                              = -515
%DISPID_TABSTOP                           = -516
%DISPID_TEXT                              = -517
%DISPID_CAPTION                           = -518
%DISPID_BORDERVISIBLE                     = -519
%DISPID_APPEARANCE                        = -520
%DISPID_MOUSEPOINTER                      = -521
%DISPID_MOUSEICON                         = -522
%DISPID_PICTURE                           = -523
%DISPID_VALID                             = -524
%DISPID_READYSTATE                        = -525
%DISPID_LISTINDEX                         = -526
%DISPID_SELECTED                          = -527
%DISPID_LIST                              = -528
%DISPID_COLUMN                            = -529
%DISPID_LISTCOUNT                         = -531
%DISPID_MULTISELECT                       = -532
%DISPID_MAXLENGTH                         = -533
%DISPID_PASSWORDCHAR                      = -534
%DISPID_SCROLLBARS                        = -535
%DISPID_WORDWRAP                          = -536
%DISPID_MULTILINE                         = -537
%DISPID_NUMBEROFROWS                      = -538
%DISPID_NUMBEROFCOLUMNS                   = -539
%DISPID_DISPLAYSTYLE                      = -540
%DISPID_GROUPNAME                         = -541
%DISPID_IMEMODE                           = -542
%DISPID_ACCELERATOR                       = -543
%DISPID_ENTERKEYBEHAVIOR                  = -544
%DISPID_TABKEYBEHAVIOR                    = -545
%DISPID_SELTEXT                           = -546
%DISPID_SELSTART                          = -547
%DISPID_SELLENGTH                         = -548

%DISPID_REFRESH                           = -550
%DISPID_DOCLICK                           = -551
%DISPID_ABOUTBOX                          = -552
%DISPID_ADDITEM                           = -553
%DISPID_CLEAR                             = -554
%DISPID_REMOVEITEM                        = -555

%DISPID_CLICK                             = -600
%DISPID_DBLCLICK                          = -601
%DISPID_KEYDOWN                           = -602
%DISPID_KEYPRESS                          = -603
%DISPID_KEYUP                             = -604
%DISPID_MOUSEDOWN                         = -605
%DISPID_MOUSEMOVE                         = -606
%DISPID_MOUSEUP                           = -607
%DISPID_ERROREVENT                        = -608
%DISPID_READYSTATECHANGE                  = -609
%DISPID_CLICK_VALUE                       = -610
%DISPID_RIGHTTOLEFT                       = -611
%DISPID_TOPTOBOTTOM                       = -612
%DISPID_THIS                              = -613

%DISPID_AMBIENT_BACKCOLOR                 = -701
%DISPID_AMBIENT_DISPLAYNAME               = -702
%DISPID_AMBIENT_FONT                      = -703
%DISPID_AMBIENT_FORECOLOR                 = -704
%DISPID_AMBIENT_LOCALEID                  = -705
%DISPID_AMBIENT_MESSAGEREFLECT            = -706
%DISPID_AMBIENT_SCALEUNITS                = -707
%DISPID_AMBIENT_TEXTALIGN                 = -708
%DISPID_AMBIENT_USERMODE                  = -709
%DISPID_AMBIENT_UIDEAD                    = -710
%DISPID_AMBIENT_SHOWGRABHANDLES           = -711
%DISPID_AMBIENT_SHOWHATCHING              = -712
%DISPID_AMBIENT_DISPLAYASDEFAULT          = -713
%DISPID_AMBIENT_SUPPORTSMNEMONICS         = -714
%DISPID_AMBIENT_AUTOCLIP                  = -715
%DISPID_AMBIENT_APPEARANCE                = -716

%DISPID_AMBIENT_CODEPAGE                  = -725
%DISPID_AMBIENT_PALETTE                   = -726
%DISPID_AMBIENT_CHARSET                   = -727
%DISPID_AMBIENT_TRANSFERPRIORITY          = -728

%DISPID_AMBIENT_RIGHTTOLEFT               = -732
%DISPID_AMBIENT_TOPTOBOTTOM               = -733

%DISPID_NAME                              = -800
%DISPID_DELETE                            = -801
%DISPID_OBJECT                            = -802
%DISPID_PARENT                            = -803

'/////////////////////////////////////////////////////////////////////////////
'// Dispatch ID constants for font and picture types

%DISPID_FONT_NAME                         = 0
%DISPID_FONT_SIZE                         = 2
%DISPID_FONT_BOLD                         = 3
%DISPID_FONT_ITALIC                       = 4
%DISPID_FONT_UNDER                        = 5
%DISPID_FONT_STRIKE                       = 6
%DISPID_FONT_WEIGHT                       = 7
%DISPID_FONT_CHARSET                      = 8
%DISPID_FONT_CHANGED                      = 9

%DISPID_PICT_HANDLE                       = 0
%DISPID_PICT_HPAL                         = 2
%DISPID_PICT_TYPE                         = 3
%DISPID_PICT_WIDTH                        = 4
%DISPID_PICT_HEIGHT                       = 5
%DISPID_PICT_RENDER                       = 6
