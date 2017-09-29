' ########################################################################################
' Microsoft Windows
' File: prsht.inc
' Contents: Interface for the Windows Property Sheet Pages
' Version 1.0
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PRSHT_INC = 1

#INCLUDE ONCE "windows.inc"

'#ifdef _WIN64
'#include <pshpack8.h>
'#else
'#include <pshpack4.h>
'#endif

%MAXPROPPAGES = 100

'struct _PSP;
'typedef struct _PSP * HPROPSHEETPAGE;

'typedef UINT (CALLBACK *LPFNPSPCALLBACKA)(HWND hwnd, UINT uMsg, struct _PROPSHEETPAGEA *ppsp);
'typedef UINT (CALLBACK *LPFNPSPCALLBACKW)(HWND hwnd, UINT uMsg, struct _PROPSHEETPAGEW *ppsp);

%PSP_DEFAULT             = &H00000000???
%PSP_DLGINDIRECT         = &H00000001???
%PSP_USEHICON            = &H00000002???
%PSP_USEICONID           = &H00000004???
%PSP_USETITLE            = &H00000008???
%PSP_RTLREADING          = &H00000010???

%PSP_HASHELP             = &H00000020???
%PSP_USEREFPARENT        = &H00000040???
%PSP_USECALLBACK         = &H00000080???
%PSP_PREMATURE           = &H00000400???

'#if (_WIN32_IE >= 0x0400)
'//----- New flags for wizard97 --------------
%PSP_HIDEHEADER          = &H00000800???
%PSP_USEHEADERTITLE      = &H00001000???
%PSP_USEHEADERSUBTITLE   = &H00002000???
'//-------------------------------------------
'#endif
'#if (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
'#define PSP_USEFUSIONCONTEXT       0x00004000
%PSP_USEFUSIONCONTEXT    = &H00004000???
'#endif

'#if (_WIN32_IE >= 0x0500)
%PSPCB_ADDREF  = 0
'#endif
%PSPCB_RELEASE = 1
%PSPCB_CREATE  = 2

'#define PROPSHEETPAGEA_V1_FIELDS   \
'    DWORD           dwSize;        \
'    DWORD           dwFlags;       \
'    HINSTANCE       hInstance;     \
'    union                          \
'    {                              \
'        LPCSTR      pszTemplate;   \
'        PROPSHEETPAGE_RESOURCE pResource; \
'    } DUMMYUNIONNAME;              \
'    union                          \
'    {                              \
'        HICON        hIcon;        \
'        LPCSTR       pszIcon;      \
'    } DUMMYUNIONNAME2;             \
'    LPCSTR           pszTitle;     \
'    DLGPROC          pfnDlgProc;   \
'    LPARAM           lParam;       \
'    LPFNPSPCALLBACKA pfnCallback;  \
'    UINT             *pcRefParent; \

'#define PROPSHEETPAGEW_V1_FIELDS   \
'    DWORD           dwSize;        \
'    DWORD           dwFlags;       \
'    HINSTANCE       hInstance;     \
'    union                          \
'    {                              \
'        LPCWSTR     pszTemplate;   \
'        PROPSHEETPAGE_RESOURCE pResource; \
'    } DUMMYUNIONNAME;              \
'    union                          \
'    {                              \
'        HICON        hIcon;        \
'        LPCWSTR      pszIcon;      \
'    } DUMMYUNIONNAME2;             \
'    LPCWSTR          pszTitle;     \
'    DLGPROC          pfnDlgProc;   \
'    LPARAM           lParam;       \
'    LPFNPSPCALLBACKW pfnCallback;  \
'    UINT             *pcRefParent; \

'#if (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
'#define  _PROPSHEETPAGEA_V3 _PROPSHEETPAGEA
'#define  _PROPSHEETPAGEW_V3 _PROPSHEETPAGEW
'#elif (_WIN32_IE >= 0x0400)
'#define  _PROPSHEETPAGEA_V2 _PROPSHEETPAGEA
'#define  _PROPSHEETPAGEW_V2 _PROPSHEETPAGEW
'#else
'#define  _PROPSHEETPAGEA_V1 _PROPSHEETPAGEA
'#define  _PROPSHEETPAGEW_V1 _PROPSHEETPAGEW
'#endif

'typedef struct _PROPSHEETPAGEA_V1
'{
'    PROPSHEETPAGEA_V1_FIELDS
'} PROPSHEETPAGEA_V1, *LPPROPSHEETPAGEA_V1;
'typedef const PROPSHEETPAGEA_V1 *LPCPROPSHEETPAGEA_V1;

'typedef struct _PROPSHEETPAGEA_V2
'{
'    PROPSHEETPAGEA_V1_FIELDS

'    LPCSTR           pszHeaderTitle;    // this is displayed in the header
'    LPCSTR           pszHeaderSubTitle; //
'} PROPSHEETPAGEA_V2, *LPPROPSHEETPAGEA_V2;
'typedef const PROPSHEETPAGEA_V2 *LPCPROPSHEETPAGEA_V2;

'typedef struct _PROPSHEETPAGEA_V3
'{
'    PROPSHEETPAGEA_V1_FIELDS

'    LPCSTR           pszHeaderTitle;    // this is displayed in the header
'    LPCSTR           pszHeaderSubTitle; //

'    HANDLE           hActCtx;
'} PROPSHEETPAGEA_V3, *LPPROPSHEETPAGEA_V3;
'typedef const PROPSHEETPAGEA_V3 *LPCPROPSHEETPAGEA_V3;


'typedef struct _PROPSHEETPAGEW_V1
'{
'    PROPSHEETPAGEW_V1_FIELDS
'} PROPSHEETPAGEW_V1, *LPPROPSHEETPAGEW_V1;
'typedef const PROPSHEETPAGEW_V1 *LPCPROPSHEETPAGEW_V1;

'typedef struct _PROPSHEETPAGEW_V2
'{
'    PROPSHEETPAGEW_V1_FIELDS

'    LPCWSTR           pszHeaderTitle;    // this is displayed in the header
'    LPCWSTR           pszHeaderSubTitle; //
'} PROPSHEETPAGEW_V2, *LPPROPSHEETPAGEW_V2;
'typedef const PROPSHEETPAGEW_V2 *LPCPROPSHEETPAGEW_V2;

'typedef struct _PROPSHEETPAGEW_V3
'{
'    PROPSHEETPAGEW_V1_FIELDS

'    LPCWSTR           pszHeaderTitle;    // this is displayed in the header
'    LPCWSTR           pszHeaderSubTitle; //

'    HANDLE           hActCtx;
'} PROPSHEETPAGEW_V3, *LPPROPSHEETPAGEW_V3;
'typedef const PROPSHEETPAGEW_V3 *LPCPROPSHEETPAGEW_V3;

'typedef PROPSHEETPAGEA_V3    PROPSHEETPAGEA_LATEST;
'typedef PROPSHEETPAGEW_V3    PROPSHEETPAGEW_LATEST;
'typedef LPPROPSHEETPAGEA_V3  LPPROPSHEETPAGEA_LATEST;
'typedef LPPROPSHEETPAGEW_V3  LPPROPSHEETPAGEW_LATEST;
'typedef LPCPROPSHEETPAGEA_V3 LPCPROPSHEETPAGEA_LATEST;
'typedef LPCPROPSHEETPAGEW_V3 LPCPROPSHEETPAGEW_LATEST;

'#if (_WIN32_WINNT >= 0x0501) || ISOLATION_AWARE_ENABLED
'typedef PROPSHEETPAGEA_V3    PROPSHEETPAGEA;
'typedef PROPSHEETPAGEW_V3    PROPSHEETPAGEW;
'typedef LPPROPSHEETPAGEA_V3  LPPROPSHEETPAGEA;
'typedef LPPROPSHEETPAGEW_V3  LPPROPSHEETPAGEW;
'typedef LPCPROPSHEETPAGEA_V3 LPCPROPSHEETPAGEA;
'typedef LPCPROPSHEETPAGEW_V3 LPCPROPSHEETPAGEW;
'#elif (_WIN32_IE >= 0x0400)
'typedef PROPSHEETPAGEA_V2    PROPSHEETPAGEA;
'typedef PROPSHEETPAGEW_V2    PROPSHEETPAGEW;
'typedef LPPROPSHEETPAGEA_V2  LPPROPSHEETPAGEA;
'typedef LPPROPSHEETPAGEW_V2  LPPROPSHEETPAGEW;
'typedef LPCPROPSHEETPAGEA_V2 LPCPROPSHEETPAGEA;
'typedef LPCPROPSHEETPAGEW_V2 LPCPROPSHEETPAGEW;
'#else
'typedef PROPSHEETPAGEA_V1    PROPSHEETPAGEA;
'typedef PROPSHEETPAGEW_V1    PROPSHEETPAGEW;
'typedef LPPROPSHEETPAGEA_V1  LPPROPSHEETPAGEA;
'typedef LPPROPSHEETPAGEW_V1  LPPROPSHEETPAGEW;
'typedef LPCPROPSHEETPAGEA_V1 LPCPROPSHEETPAGEA;
'typedef LPCPROPSHEETPAGEW_V1 LPCPROPSHEETPAGEW;
'#endif

'#ifdef UNICODE
'#define PROPSHEETPAGE           PROPSHEETPAGEW
'#define LPPROPSHEETPAGE         LPPROPSHEETPAGEW
'#define LPCPROPSHEETPAGE        LPCPROPSHEETPAGEW
'#define PROPSHEETPAGE_V1_SIZE   PROPSHEETPAGEW_V1_SIZE
'#define PROPSHEETPAGE_V2_SIZE   PROPSHEETPAGEW_V2_SIZE
'#define PROPSHEETPAGE_V1        PROPSHEETPAGEW_V1
'#define LPPROPSHEETPAGE_V1      LPPROPSHEETPAGEW_V1
'#define LPCPROPSHEETPAGE_V1     LPCPROPSHEETPAGEW_V1
'#define PROPSHEETPAGE_V2        PROPSHEETPAGEW_V2
'#define LPPROPSHEETPAGE_V2      LPPROPSHEETPAGEW_V2
'#define LPCPROPSHEETPAGE_V2     LPCPROPSHEETPAGEW_V2
'#define PROPSHEETPAGE_V3        PROPSHEETPAGEW_V3
'#define LPPROPSHEETPAGE_V3      LPPROPSHEETPAGEW_V3
'#define LPCPROPSHEETPAGE_V3     LPCPROPSHEETPAGEW_V3
'#define PROPSHEETPAGE_LATEST    PROPSHEETPAGEW_LATEST
'#define LPPROPSHEETPAGE_LATEST  LPPROPSHEETPAGEW_LATEST
'#define LPCPROPSHEETPAGE_LATEST LPCPROPSHEETPAGEW_LATEST
'#else
'#define PROPSHEETPAGE           PROPSHEETPAGEA
'#define LPPROPSHEETPAGE         LPPROPSHEETPAGEA
'#define LPCPROPSHEETPAGE        LPCPROPSHEETPAGEA
'#define PROPSHEETPAGE_V1_SIZE   PROPSHEETPAGEA_V1_SIZE
'#define PROPSHEETPAGE_V2_SIZE   PROPSHEETPAGEA_V2_SIZE
'#define PROPSHEETPAGE_V1        PROPSHEETPAGEA_V1
'#define LPPROPSHEETPAGE_V1      LPPROPSHEETPAGEA_V1
'#define LPCPROPSHEETPAGE_V1     LPCPROPSHEETPAGEA_V1
'#define PROPSHEETPAGE_V2        PROPSHEETPAGEA_V2
'#define LPPROPSHEETPAGE_V2      LPPROPSHEETPAGEA_V2
'#define LPCPROPSHEETPAGE_V2     LPCPROPSHEETPAGEA_V2
'#define PROPSHEETPAGE_V3        PROPSHEETPAGEA_V3
'#define LPPROPSHEETPAGE_V3      LPPROPSHEETPAGEA_V3
'#define LPCPROPSHEETPAGE_V3     LPCPROPSHEETPAGEA_V3
'#define PROPSHEETPAGE_LATEST    PROPSHEETPAGEA_LATEST
'#define LPPROPSHEETPAGE_LATEST  LPPROPSHEETPAGEA_LATEST
'#define LPCPROPSHEETPAGE_LATEST LPCPROPSHEETPAGEA_LATEST
'#endif

' // Size = 4 bytes
UNION PROPSHEETPAGE_DUMMYUNIONNAME DWORD
   pszTemplate AS ASCIIZ PTR         ' LPCSTR
   pResource   AS DWORD              ' PROPSHEETPAGE_RESOURCE
END UNION

' // Size = 4 bytes
UNION PROPSHEETPAGE_DUMMYUNIONNAME2 DWORD
   hIcon   AS DWORD                  ' HICON
   pszIcon AS ASCIIZ PTR             ' LPCSTR
END UNION

' // Size = 40 bytes
TYPE PROPSHEETPAGEA_V1_FIELDS DWORD
   dwSize            AS DWORD        ' DWORD
   dwFlags           AS DWORD        ' DWORD
   hInstance         AS DWORD        ' HINSTANCE
   PROPSHEETPAGE_DUMMYUNIONNAME
   PROPSHEETPAGE_DUMMYUNIONNAME2
   pszTitle          AS ASCIIZ PTR   ' LPCSTR
   pfnDlgProc        AS DWORD        ' DLGPROC
   lParam            AS LONG         ' LPARAM
   pfnCallback       AS DWORD        ' LPFNPSPCALLBACKA
   pcRefParent       AS DWORD PTR    ' UINT *
END TYPE

' // Size = 40 bytes
TYPE PROPSHEETPAGE_V1 DWORD
   PROPSHEETPAGEA_V1_FIELDS
END TYPE

' // Size = 48 bytes
TYPE PROPSHEETPAGE_V2 DWORD
   PROPSHEETPAGEA_V1_FIELDS
   pszHeaderTitle    AS ASCIIZ PTR   ' LPCSTR
   pszHeaderSubTitle AS ASCIIZ PTR   ' LPCSTR
END TYPE

' // Size = 52 bytes
TYPE PROPSHEETPAGE_V3 DWORD
   PROPSHEETPAGEA_V1_FIELDS
   pszHeaderTitle    AS ASCIIZ PTR   ' LPCSTR
   pszHeaderSubTitle AS ASCIIZ PTR   ' LPCSTR
   hActCtx           AS DWORD        ' HANDLE
END TYPE

'#if _WIN32_WINNT >= 0x0600
' // Size = 4 bytes
UNION PROPSHEETPAGEA_V4_DUMMYUNIONNAME3 DWORD
   hbmHeader   AS DWORD        ' HBITMAP
   pszbmHeader AS ASCIIZ PTR   ' LPCSTR
END UNION

' // Size = 56 bytes
TYPE PROPSHEETPAGEA_V4 DWORD
   PROPSHEETPAGEA_V1_FIELDS
   pszHeaderTitle    AS ASCIIZ PTR   ' LPCSTR    // this is displayed in the header
   pszHeaderSubTitle AS ASCIIZ PTR   ' LPCSTR
   hActCtx           AS DWORD        ' HANDLE
   PROPSHEETPAGEA_V4_DUMMYUNIONNAME3
END TYPE
'#endif

' // Size = 4 bytes
UNION PROPSHEETPAGEW_DUMMYUNIONNAME DWORD
   pszTemplate AS WSTRINGZ PTR       ' LPCWSTR
   pResource   AS WSTRINGZ PTR       ' LPCWSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETPAGEW_DUMMYUNIONNAME2 DWORD
   hIcon   AS DWORD                  ' HICON
   pszIcon AS WSTRINGZ PTR           ' LPCWSTR
END UNION

' // Size = 40 bytes
TYPE PROPSHEETPAGEW_V1_FIELDS DWORD
   dwSize            AS DWORD          ' DWORD
   dwFlags           AS DWORD          ' DWORD
   hInstance         AS DWORD          ' HINSTANCE
   PROPSHEETPAGEW_DUMMYUNIONNAME
   PROPSHEETPAGEW_DUMMYUNIONNAME2
   pszTitle          AS WSTRINGZ PTR   ' LPCWSTR
   pfnDlgProc        AS DWORD          ' DLGPROC
   lParam            AS LONG           ' LPARAM
   pfnCallback       AS DWORD          ' LPFNPSPCALLBACKW
   pcRefParent       AS DWORD PTR      ' UINT*
END TYPE

' // Size = 40 bytes
TYPE PROPSHEETPAGEW_V1 DWORD
   PROPSHEETPAGEW_V1_FIELDS
END TYPE

' // Size = 48 bytes
TYPE PROPSHEETPAGEW_V2 DWORD
   PROPSHEETPAGEW_V1_FIELDS
   pszHeaderTitle    AS WSTRINGZ PTR   ' LPCWSTR
   pszHeaderSubTitle AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 52 bytes
TYPE PROPSHEETPAGEW_V3
   PROPSHEETPAGEW_V1_FIELDS
   pszHeaderTitle    AS WSTRINGZ PTR   ' LPCWSTR
   pszHeaderSubTitle AS WSTRINGZ PTR   ' LPCWSTR
   hActCtx           AS DWORD          ' HANDLE
END TYPE

'#if _WIN32_WINNT >= 0x0600
' // Size = 4 bytes
UNION PROPSHEETPAGEW_V4_DUMMYUNIONNAME3 DWORD
   hbmHeader   AS DWORD          ' HBITMAP
   pszbmHeader AS WSTRINGZ PTR   ' LPCWSTR
END UNION

' // Size = 56 bytes
TYPE PROPSHEETPAGEW_V4 DWORD
   PROPSHEETPAGEW_V1_FIELDS
   pszHeaderTitle    AS WSTRINGZ PTR   ' LPCWSTR    // this is displayed in the header
   pszHeaderSubTitle AS WSTRINGZ PTR   ' LPCWSTR
   hActCtx           AS DWORD          ' HANDLE
   PROPSHEETPAGEW_V4_DUMMYUNIONNAME3
END TYPE
'#endif

' // Size = 56 bytes
TYPE PROPSHEETPAGEA DWORD
   PROPSHEETPAGEA_V1_FIELDS
   pszHeaderTitle    AS ASCIIZ PTR   ' LPCSTR
   pszHeaderSubTitle AS ASCIIZ PTR   ' LPCSTR
   hActCtx           AS DWORD        ' HANDLE
END TYPE

' // Size = 56 bytes
TYPE PROPSHEETPAGEW DWORD
   PROPSHEETPAGEW_V1_FIELDS
   pszHeaderTitle    AS WSTRINGZ PTR   ' LPCWSTR
   pszHeaderSubTitle AS WSTRINGZ PTR   ' LPCWSTR
   hActCtx           AS DWORD          ' HANDLE
END TYPE

#IF %DEF(%UNICODE)
MACRO PROPSHEETPAGE = PROPSHEETPAGEW
#ELSE
MACRO PROPSHEETPAGE = PROPSHEETPAGEA
#ENDIF



'//----- PropSheet Header related ---------

%PSH_DEFAULT            = &H00000000???
%PSH_PROPTITLE          = &H00000001???
%PSH_USEHICON           = &H00000002???
%PSH_USEICONID          = &H00000004???
%PSH_PROPSHEETPAGE      = &H00000008???

%PSH_WIZARDHASFINISH    = &H00000010???
%PSH_WIZARD             = &H00000020???
%PSH_USEPSTARTPAGE      = &H00000040???
%PSH_NOAPPLYNOW         = &H00000080???

%PSH_USECALLBACK        = &H00000100???
%PSH_HASHELP            = &H00000200???
%PSH_MODELESS           = &H00000400???
%PSH_RTLREADING         = &H00000800???

%PSH_WIZARDCONTEXTHELP  = &H00001000???

'#if (_WIN32_IE >= 0x0400)
'//----- New flags for wizard97 -----------
'#if (_WIN32_IE < 0x0500)
'#define PSH_WIZARD97            0x00002000
'#else
'#define PSH_WIZARD97            0x01000000
'#endif
%PSH_WIZARD97          = &H01000000???
'// 0x00004000 was not used by any previous release
%PSH_WATERMARK         = &H00008000???
%PSH_USEHBMWATERMARK   = &H00010000???  ' user pass in a hbmWatermark instead of pszbmWatermark
%PSH_USEHPLWATERMARK   = &H00020000???  '
%PSH_STRETCHWATERMARK  = &H00040000???  ' stretchwatermark also applies for the header
%PSH_HEADER            = &H00080000???
%PSH_USEHBMHEADER      = &H00100000???
%PSH_USEPAGELANG       = &H00200000???  ' use frame dialog template matched to page
'//----------------------------------------
'#endif

'#if (_WIN32_IE >= 0x0500)
'//----- New flags for wizard-lite --------
'#define PSH_WIZARD_LITE         0x00400000
'#define PSH_NOCONTEXTHELP       0x02000000
%PSH_WIZARD_LITE       = &H00400000???
%PSH_NOCONTEXTHELP     = &H02000000???
'//----------------------------------------
'#endif

'#if _WIN32_WINNT >= 0x0600
%PSH_AEROWIZARD                          = &H00004000???
%PSH_RESIZABLE                           = &H04000000???
%PSH_HEADERBITMAP                        = &H08000000???
%PSH_NOMARGIN                            = &H10000000???
'#endif

'typedef int (CALLBACK *PFNPROPSHEETCALLBACK)(HWND, UINT, LPARAM);

'#define PROPSHEETHEADERA_V1_FIELDS      \
'        DWORD           dwSize;         \
'        DWORD           dwFlags;        \
'        HWND            hwndParent;     \
'        HINSTANCE       hInstance;      \
'        union                           \
'        {                               \
'            HICON       hIcon;          \
'            LPCSTR      pszIcon;        \
'        } DUMMYUNIONNAME;               \
'        LPCSTR          pszCaption;     \
'        UINT            nPages;         \
'        union                           \
'        {                               \
'            UINT        nStartPage;     \
'            LPCSTR      pStartPage;     \
'        } DUMMYUNIONNAME2;              \
'        union                           \
'        {                               \
'            LPCPROPSHEETPAGEA ppsp;     \
'            HPROPSHEETPAGE *phpage;     \
'        } DUMMYUNIONNAME3;              \
'        PFNPROPSHEETCALLBACK pfnCallback;

'typedef struct _PROPSHEETHEADERA_V1
'{
'    PROPSHEETHEADERA_V1_FIELDS
'} PROPSHEETHEADERA_V1, *LPPROPSHEETHEADERA_V1;
'typedef const PROPSHEETHEADERA_V1 *LPCPROPSHEETHEADERA_V1;

' // Size = 4 bytes
UNION PROPSHEETHEADER_DUMMYUNIONNAME DWORD
   hIcon   AS DWORD                  ' HICON
   pszIcon AS ASCIIZ PTR             ' LPCSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADER_DUMMYUNIONNAME2 DWORD
   nStartPage AS DWORD               ' UINT
   pStartPage AS ASCIIZ PTR          ' LPCSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADER_DUMMYUNIONNAME3 DWORD
   ppsp   AS PROPSHEETPAGEA PTR      ' LPCPROPSHEETPAGEA
   phpage AS DWORD                   ' HPROPSHEETPAGE*
END UNION

' // Size = 40 bytes
TYPE PROPSHEETHEADERA_V1_FIELDS DWORD
   dwSize       AS DWORD             ' DWORD
   dwFlags      AS DWORD             ' DWORD
   hwndParent   AS DWORD             ' HWND
   hInstance    AS DWORD             ' HINSTANCE
   PROPSHEETHEADER_DUMMYUNIONNAME
   pszCaption   AS ASCIIZ PTR        ' LPCSTR
   nPages       AS DWORD             ' UINT
   PROPSHEETHEADER_DUMMYUNIONNAME2
   PROPSHEETHEADER_DUMMYUNIONNAME3
   pfnCallback  AS DWORD             ' PFNPROPSHEETCALLBACK
END TYPE

' // Size = 40 bytes
TYPE PROPSHEETHEADERA_V1 DWORD
   PROPSHEETHEADERA_V1_FIELDS
END TYPE

'#if (_WIN32_IE >= 0x0400)
'typedef struct _PROPSHEETHEADERA_V2
'{
'    PROPSHEETHEADERA_V1_FIELDS
'    union
'    {
'        HBITMAP hbmWatermark;
'        LPCSTR pszbmWatermark;
'    } DUMMYUNIONNAME4;
'    HPALETTE hplWatermark;
'    union
'    {
'        HBITMAP hbmHeader;     // Header  bitmap shares the palette with watermark
'        LPCSTR pszbmHeader;
'    } DUMMYUNIONNAME5;
'} PROPSHEETHEADERA_V2, *LPPROPSHEETHEADERA_V2;
'typedef const PROPSHEETHEADERA_V2 *LPCPROPSHEETHEADERA_V2;
'#endif

' // Size = 4 bytes
UNION PROPSHEETHEADER_DUMMYUNIONNAME4 DWORD
   hbmWatermark   AS DWORD           ' HBITMAP
   pszbmWatermark AS ASCIIZ PTR      ' LPCSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADER_DUMMYUNIONNAME5 DWORD
   hbmHeader   AS DWORD              ' HBITMAP
   pszbmHeader AS ASCIIZ PTR         ' LPCSTR
END UNION

' // Size = 52 bytes
TYPE PROPSHEETHEADERA_V2 DWORD
   PROPSHEETHEADERA_V1_FIELDS
   PROPSHEETHEADER_DUMMYUNIONNAME4
   hplWatermark AS DWORD             ' HPALETTE
   PROPSHEETHEADER_DUMMYUNIONNAME5
END TYPE


'#define PROPSHEETHEADERW_V1_FIELDS      \
'        DWORD           dwSize;         \
'        DWORD           dwFlags;        \
'        HWND            hwndParent;     \
'        HINSTANCE       hInstance;      \
'        union                           \
'        {                               \
'            HICON       hIcon;          \
'            LPCWSTR     pszIcon;        \
'        } DUMMYUNIONNAME;               \
'        LPCWSTR         pszCaption;     \
'        UINT            nPages;         \
'        union                           \
'        {                               \
'            UINT        nStartPage;     \
'            LPCWSTR     pStartPage;     \
'        } DUMMYUNIONNAME2;              \
'        union                           \
'        {                               \
'            LPCPROPSHEETPAGEW ppsp;     \
'            HPROPSHEETPAGE *phpage;     \
'        } DUMMYUNIONNAME3;              \
'        PFNPROPSHEETCALLBACK pfnCallback;

'typedef struct _PROPSHEETHEADERW_V1
'{
'    PROPSHEETHEADERW_V1_FIELDS
'} PROPSHEETHEADERW_V1, *LPPROPSHEETHEADERW_V1;
'typedef const PROPSHEETHEADERW_V1 *LPCPROPSHEETHEADERW_V1;


' // Size = 4 bytes
UNION PROPSHEETHEADERW_DUMMYUNIONNAME DWORD
   hIcon   AS DWORD                  ' HICON
   pszIcon AS WSTRINGZ PTR           ' LPCWSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADERW_DUMMYUNIONNAME2 DWORD
   nStartPage AS DWORD               ' UINT
   pStartPage AS WSTRINGZ PTR        ' LPCWSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADERW_DUMMYUNIONNAME3 DWORD
   ppsp   AS PROPSHEETPAGEW PTR      ' LPCPROPSHEETPAGEW
   phpage AS DWORD                   ' HPROPSHEETPAGE*
END UNION

' // Size = 40 bytes
TYPE PROPSHEETHEADERW_V1_FIELDS DWORD
   dwSize       AS DWORD             ' DWORD
   dwFlags      AS DWORD             ' DWORD
   hwndParent   AS DWORD             ' HWND
   hInstance    AS DWORD             ' HINSTANCE
   PROPSHEETHEADERW_DUMMYUNIONNAME
   pszCaption   AS WSTRINGZ PTR      ' LPCWSTR
   nPages       AS DWORD             ' UINT
   PROPSHEETHEADERW_DUMMYUNIONNAME2
   PROPSHEETHEADERW_DUMMYUNIONNAME3
   pfnCallback  AS DWORD             ' PFNPROPSHEETCALLBACK
END TYPE

' // Size = 40 bytes
TYPE PROPSHEETHEADERW_V1 DWORD
   PROPSHEETHEADERW_V1_FIELDS
END TYPE

' // Size = 4 bytes
UNION PROPSHEETHEADERW_DUMMYUNIONNAME4 DWORD
   hbmWatermark   AS DWORD           ' HBITMAP
   pszbmWatermark AS WSTRINGZ PTR    ' LPCWSTR
END UNION

' // Size = 4 bytes
UNION PROPSHEETHEADERW_DUMMYUNIONNAME5 DWORD
   hbmHeader   AS DWORD              ' HBITMAP
   pszbmHeader AS WSTRINGZ PTR       ' LPCWSTR
END UNION

'#if (_WIN32_IE >= 0x0400)
'typedef struct _PROPSHEETHEADERW_V2
'{
'    PROPSHEETHEADERW_V1_FIELDS
'    union
'    {
'        HBITMAP hbmWatermark;
'        LPCWSTR pszbmWatermark;
'    } DUMMYUNIONNAME4;
'    HPALETTE hplWatermark;
'    union
'    {
'        HBITMAP hbmHeader;     // Header  bitmap shares the palette with watermark
'        LPCWSTR pszbmHeader;
'    } DUMMYUNIONNAME5;
'} PROPSHEETHEADERW_V2, *LPPROPSHEETHEADERW_V2;
'typedef const PROPSHEETHEADERW_V2 *LPCPROPSHEETHEADERW_V2;
'#endif

' // Size = 52 bytes
TYPE PROPSHEETHEADERW_V2 DWORD
   PROPSHEETHEADERW_V1_FIELDS
   PROPSHEETHEADERW_DUMMYUNIONNAME4
   hplWatermark AS DWORD             ' HPALETTE
   PROPSHEETHEADERW_DUMMYUNIONNAME5
END TYPE

'#define PROPSHEETHEADERA_V1_SIZE sizeof(PROPSHEETHEADERA_V1)
'#define PROPSHEETHEADERW_V1_SIZE sizeof(PROPSHEETHEADERW_V1)

'#if (_WIN32_IE >= 0x400)
'#define PROPSHEETHEADERA_V2_SIZE sizeof(PROPSHEETHEADERA_V2)
'#define PROPSHEETHEADERW_V2_SIZE sizeof(PROPSHEETHEADERW_V2)
'#endif

'#if (_WIN32_IE >= 0x400)
'#define    _PROPSHEETHEADERA        PROPSHEETHEADERA_V2;
'#define    _PROPSHEETHEADERW        PROPSHEETHEADERW_V2;
'typedef    PROPSHEETHEADERA_V2      PROPSHEETHEADERA;
'typedef    PROPSHEETHEADERW_V2      PROPSHEETHEADERW;
'typedef  LPPROPSHEETHEADERA_V2      LPPROPSHEETHEADERA;
'typedef  LPPROPSHEETHEADERW_V2      LPPROPSHEETHEADERW;
'typedef LPCPROPSHEETHEADERA_V2      LPCPROPSHEETHEADERA;
'typedef LPCPROPSHEETHEADERW_V2      LPCPROPSHEETHEADERW;
'#else
'#define    _PROPSHEETHEADERA        PROPSHEETHEADERA_V1;
'#define    _PROPSHEETHEADERW        PROPSHEETHEADERW_V1;
'typedef    PROPSHEETHEADERA_V1      PROPSHEETHEADERA;
'typedef    PROPSHEETHEADERW_V1      PROPSHEETHEADERW;
'typedef  LPPROPSHEETHEADERA_V1      LPPROPSHEETHEADERA;
'typedef  LPPROPSHEETHEADERW_V1      LPPROPSHEETHEADERW;
'typedef LPCPROPSHEETHEADERA_V1      LPCPROPSHEETHEADERA;
'typedef LPCPROPSHEETHEADERW_V1      LPCPROPSHEETHEADERW;
'#endif

'#ifdef UNICODE
'#define PROPSHEETHEADER         PROPSHEETHEADERW
'#define LPPROPSHEETHEADER       LPPROPSHEETHEADERW
'#define LPCPROPSHEETHEADER      LPCPROPSHEETHEADERW
'#define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERW_V1_SIZE
'#if (_WIN32_IE >= 0x400)
'#define PROPSHEETHEADER_V2_SIZE PROPSHEETHEADERW_V2_SIZE
'#endif
'#else
'#define PROPSHEETHEADER         PROPSHEETHEADERA
'#define LPPROPSHEETHEADER       LPPROPSHEETHEADERA
'#define LPCPROPSHEETHEADER      LPCPROPSHEETHEADERA
'#define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERA_V1_SIZE
'#if (_WIN32_IE >= 0x400)
'#define PROPSHEETHEADER_V2_SIZE PROPSHEETHEADERA_V2_SIZE
'#endif
'#endif

MACRO PROPSHEETHEADERA = PROPSHEETHEADERA_V2
MACRO PROPSHEETHEADERW = PROPSHEETHEADERW_V2
MACRO PROPSHEETHEADER = PROPSHEETHEADERA_V2

%PSCB_INITIALIZED = 1
%PSCB_PRECREATE   = 2

'#if (_WIN32_IE >= 0x560)
'// PSCB_BUTTONPRESSED will be sent when the user clicks a button in the
'// property dialog (OK, Cancel, Apply, or Close).  The message will be sent
'// to PROPSHEETHEADER's pfnCallback if the PSH_USECALLBACK flag was specified.
'// The LPARAM will be equal to one of the following based on the button pressed:
'// This message is only supported on comctl32 v6.
'// PSBTN_FINISH (Close), PSBTN_OK, PSBTN_APPLYNOW, or PSBTN_CANCEL

'#define PSCB_BUTTONPRESSED 3
%PSCB_BUTTONPRESSED = 3
'#endif  // _WIN32_IE >= 0x560


DECLARE FUNCTION CreatePropertySheetPageA IMPORT "COMCTL32.DLL" ALIAS "CreatePropertySheetPageA" ( _
   BYREF constPropSheetPagePointer AS PROPSHEETPAGEA _  ' __in LPCPROPSHEETPAGEA constPropSheetPagePointer
 ) AS DWORD                                             ' HPROPSHEETPAGE

DECLARE FUNCTION CreatePropertySheetPageW IMPORT "COMCTL32.DLL" ALIAS "CreatePropertySheetPageW" ( _
   BYREF constPropSheetPagePointer AS PROPSHEETPAGEW _  ' __in LPCPROPSHEETPAGEW constPropSheetPagePointer
 ) AS DWORD                                             ' HPROPSHEETPAGE

#IF %DEF(%UNICODE)
   MACRO CreatePropertySheetPage = CreatePropertySheetPageW
#ELSE
   MACRO CreatePropertySheetPage = CreatePropertySheetPageA
#ENDIF

DECLARE FUNCTION DestroyPropertySheetPage IMPORT "COMCTL32.DLL" ALIAS "DestroyPropertySheetPage" ( _
   BYVAL hPSPage AS DWORD _                             ' __in HPROPSHEETPAGE hPSPage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PropertySheetA IMPORT "COMCTL32.DLL" ALIAS "PropertySheetA" ( _
   BYREF lppsph AS PROPSHEETHEADERA _                   ' __in LPCPROPSHEETHEADERA lppsph
 ) AS LONG                                              ' INT_PTR

DECLARE FUNCTION PropertySheetW IMPORT "COMCTL32.DLL" ALIAS "PropertySheetW" ( _
   BYREF lppsph AS PROPSHEETHEADERW _                   ' __in LPCPROPSHEETHEADERW lppsph
 ) AS LONG                                              ' INT_PTR

#IF %DEF(%UNICODE)
   MACRO PropertySheet = PropertySheetW
#ELSE
   MACRO PropertySheet = PropertySheetA
#ENDIF

'typedef BOOL (CALLBACK *LPFNADDPROPSHEETPAGE)(HPROPSHEETPAGE, LPARAM);
'typedef BOOL (CALLBACK *LPFNADDPROPSHEETPAGES)(LPVOID, LPFNADDPROPSHEETPAGE, LPARAM);

' // Size = 16 bytes
TYPE PSHNOTIFY DWORD
   hdr    AS NMHDR   ' NMHDR
   lParam AS LONG    ' LPARAM
END TYPE

'#define PSN_FIRST               (0U-200U)
'#define PSN_LAST                (0U-299U)

%PSN_FIRST                = -200&
%PSN_LAST                 = -299&

%PSN_SETACTIVE            = %PSN_FIRST - 0
%PSN_KILLACTIVE           = %PSN_FIRST - 1
' %PSN_VALIDATE           = %PSN_FIRST - 1
%PSN_APPLY                = %PSN_FIRST - 2
%PSN_RESET                = %PSN_FIRST - 3
' %PSN_CANCEL             = %PSN_FIRST - 3
%PSN_HELP                 = %PSN_FIRST - 5
%PSN_WIZBACK              = %PSN_FIRST - 6
%PSN_WIZNEXT              = %PSN_FIRST - 7
%PSN_WIZFINISH            = %PSN_FIRST - 8
%PSN_QUERYCANCEL          = %PSN_FIRST - 9
'#if (_WIN32_IE >= 0x0400)
%PSN_GETOBJECT            = %PSN_FIRST - 10
'#endif // 0x0400
'#if (_WIN32_IE >= 0x0500)
%PSN_TRANSLATEACCELERATOR = %PSN_FIRST - 12
%PSN_QUERYINITIALFOCUS    = %PSN_FIRST - 13
'#endif // 0x0500

%PSNRET_NOERROR              = 0
%PSNRET_INVALID              = 1
%PSNRET_INVALID_NOCHANGEPAGE = 2
%PSNRET_MESSAGEHANDLED       = 3

'#define PropSheet_SetCurSel(hDlg, hpage, index) \
'        SNDMSG(hDlg, PSM_SETCURSEL, (WPARAM)index, (LPARAM)hpage)

%PSM_SETCURSEL = %WM_USER + 101

FUNCTION PropSheet_SetCurSel (BYVAL hDlg AS DWORD, BYVAL hpage AS DWORD, BYVAL index AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_SETCURSEL, index, hpage)
END FUNCTION

'#define PropSheet_RemovePage(hDlg, index, hpage) \
'        SNDMSG(hDlg, PSM_REMOVEPAGE, index, (LPARAM)hpage)

%PSM_REMOVEPAGE = %WM_USER + 102

SUB PropSheet_RemovePage (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYVAL hpage AS DWORD)
   SendMessage hDlg, %PSM_REMOVEPAGE, index, hpage
END SUB

'#define PropSheet_AddPage(hDlg, hpage) \
'        SNDMSG(hDlg, PSM_ADDPAGE, 0, (LPARAM)hpage)

%PSM_ADDPAGE = %WM_USER + 103

FUNCTION PropSheet_AddPage (BYVAL hDlg AS DWORD, BYVAL hpage AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_ADDPAGE, 0, hpage)
END FUNCTION

'#define PropSheet_Changed(hDlg, hwnd) \
'        SNDMSG(hDlg, PSM_CHANGED, (WPARAM)hwnd, 0L)

%PSM_CHANGED = %WM_USER + 104

FUNCTION PropSheet_Changed (BYVAL hDlg AS DWORD, BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_CHANGED, hwnd, 0)
END FUNCTION

'#define PropSheet_RestartWindows(hDlg) \
'        SNDMSG(hDlg, PSM_RESTARTWINDOWS, 0, 0L)

%PSM_RESTARTWINDOWS = %WM_USER + 105

SUB PropSheet_RestartWindows (BYVAL hDlg AS DWORD)
   SendMessage hDlg, %PSM_RESTARTWINDOWS, 0, 0
END SUB

'#define PropSheet_RebootSystem(hDlg) \
'        SNDMSG(hDlg, PSM_REBOOTSYSTEM, 0, 0L)

%PSM_REBOOTSYSTEM = %WM_USER + 106

SUB PropSheet_RebootSystem (BYVAL hDlg AS DWORD)
   SendMessage hDlg, %PSM_REBOOTSYSTEM, 0, 0
END SUB

'#define PropSheet_CancelToClose(hDlg) \
'        PostMessage(hDlg, PSM_CANCELTOCLOSE, 0, 0L)

%PSM_CANCELTOCLOSE = %WM_USER + 107

SUB PropSheet_CancelToClose (BYVAL hDlg AS DWORD)
   PostMessage hDlg, %PSM_CANCELTOCLOSE, 0, 0
END SUB

'#define PropSheet_QuerySiblings(hDlg, wParam, lParam) \
'        SNDMSG(hDlg, PSM_QUERYSIBLINGS, wParam, lParam)

%PSM_QUERYSIBLINGS = %WM_USER + 108

FUNCTION PropSheet_QuerySiblings (BYVAL hDlg AS DWORD, BYVAL param1 AS LONG, BYVAL param2 AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_QUERYSIBLINGS, param1, param2)
END FUNCTION

'#define PropSheet_UnChanged(hDlg, hwnd) \
'        SNDMSG(hDlg, PSM_UNCHANGED, (WPARAM)hwnd, 0L)

%PSM_UNCHANGED = %WM_USER + 109

SUB PropSheet_UnChanged (BYVAL hDlg AS DWORD, BYVAL hwndPage AS DWORD)
   SendMessage hDlg, %PSM_UNCHANGED, hwndPage, 0
END SUB

'#define PropSheet_Apply(hDlg) \
'        SNDMSG(hDlg, PSM_APPLY, 0, 0L)

%PSM_APPLY = %WM_USER + 110

FUNCTION PropSheet_Apply (BYVAL hDlg AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_APPLY, 0, 0)
END FUNCTION

%PSM_SETTITLEA = %WM_USER + 111
%PSM_SETTITLEW = %WM_USER + 120

'#define PropSheet_SetTitle(hDlg, wStyle, lpszText)\
'        SNDMSG(hDlg, PSM_SETTITLE, wStyle, (LPARAM)(LPCTSTR)(lpszText))

#IF %DEF(%UNICODE)
   %PSM_SETTITLE  = %PSM_SETTITLEW
#ELSE
   %PSM_SETTITLE  = %PSM_SETTITLEA
#ENDIF

SUB PropSheet_SetTitleA (BYVAL hDlg AS DWORD, BYVAL dwStyle AS DWORD, BYVAL lpszText AS DWORD)
   ' lpszText may be an ASCIIZ string or a string resource number
   SendMessage hDlg, %PSM_SETTITLEA, dwStyle, lpszText
END SUB

SUB PropSheet_SetTitleW (BYVAL hDlg AS DWORD, BYVAL dwStyle AS DWORD, BYVAL lpwszText AS DWORD)
   ' lpwszText may be an unicode string or a string resource number
   SendMessage hDlg, %PSM_SETTITLEW, dwStyle, lpwszText
END SUB

#IF %DEF(%UNICODE)
   MACRO PropSheet_SetTitle = PropSheet_SetTitleW
#ELSE
   MACRO PropSheet_SetTitle = PropSheet_SetTitleA
#ENDIF


'#define PropSheet_SetWizButtons(hDlg, dwFlags) \
'        PostMessage(hDlg, PSM_SETWIZBUTTONS, 0, (LPARAM)dwFlags)

%PSM_SETWIZBUTTONS = %WM_USER + 112

SUB PropSheet_SetWizButtons (BYVAL hDlg AS DWORD, BYVAL dwFlags AS DWORD)
   PostMessage hDlg, %PSM_SETWIZBUTTONS, 0, dwFlags
END SUB

%PSWIZB_BACK           = &H00000001???
%PSWIZB_NEXT           = &H00000002???
%PSWIZB_FINISH         = &H00000004???
%PSWIZB_DISABLEDFINISH = &H00000008???

%PSWIZBF_ELEVATIONREQUIRED = &H00000001???

'#if _WIN32_WINNT >= 0x0600
'// Only for PSH_AEROWIZARD - used in PSM_SHOWWIZBUTTONS
%PSWIZB_CANCEL         = &H00000010???
'#endif // 0x0600

'#define PropSheet_PressButton(hDlg, iButton) \
'        PostMessage(hDlg, PSM_PRESSBUTTON, (WPARAM)iButton, 0)

%PSM_PRESSBUTTON = %WM_USER + 113

' Microsoft shows this returning a BOOL, but it doesn't.
SUB PropSheet_PressButton (BYVAL hDlg AS DWORD, BYVAL iButton AS LONG)
   PostMessage hDlg, %PSM_PRESSBUTTON, iButton, 0
END SUB

%PSBTN_BACK     = 0
%PSBTN_NEXT     = 1
%PSBTN_FINISH   = 2
%PSBTN_OK       = 3
%PSBTN_APPLYNOW = 4
%PSBTN_CANCEL   = 5
%PSBTN_HELP     = 6
%PSBTN_MAX      = 6

'#define PropSheet_SetCurSelByID(hDlg, id) \
'        SNDMSG(hDlg, PSM_SETCURSELID, 0, (LPARAM)id)

%PSM_SETCURSELID = %WM_USER + 114

FUNCTION PropSheet_SetCurSelByID (BYVAL hDlg AS DWORD, BYVAL id AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_SETCURSELID, 0, id)
END FUNCTION

%PSM_SETFINISHTEXTA = %WM_USER + 115
%PSM_SETFINISHTEXTW = %WM_USER + 121

#IF %DEF(%UNICODE)
   %PSM_SETFINISHTEXT  = %PSM_SETFINISHTEXTW
#ELSE
   %PSM_SETFINISHTEXT  = %PSM_SETFINISHTEXTA
#ENDIF

'#define PropSheet_SetFinishText(hDlg, lpszText) \
'        SNDMSG(hDlg, PSM_SETFINISHTEXT, 0, (LPARAM)lpszText)

SUB PropSheet_SetFinishTextA (BYVAL hDlg AS DWORD, BYREF szText AS ASCIIZ)
   SendMessage hDlg, %PSM_SETFINISHTEXTA, 0, VARPTR(szText)
END SUB

SUB PropSheet_SetFinishTextW (BYVAL hDlg AS DWORD, BYREF wszText AS WSTRINGZ)
   SendMessage hDlg, %PSM_SETFINISHTEXTW, 0, VARPTR(wszText)
END SUB

#IF %DEF(%UNICODE)
   MACRO PropSheet_SetFinishText = PropSheet_SetFinishTextW
#ELSE
   MACRO PropSheet_SetFinishText = PropSheet_SetFinishTextA
#ENDIF

'#define PropSheet_GetTabControl(hDlg) \
'        (HWND)SNDMSG(hDlg, PSM_GETTABCONTROL, 0, 0)

%PSM_GETTABCONTROL = %WM_USER + 116

FUNCTION PropSheet_GetTabControl (BYVAL hDlg AS DWORD) AS DWORD
   FUNCTION = SendMessage(hDlg, %PSM_GETTABCONTROL, 0, 0)
END FUNCTION

'#define PropSheet_IsDialogMessage(hDlg, pMsg) \
'        (BOOL)SNDMSG(hDlg, PSM_ISDIALOGMESSAGE, 0, (LPARAM)pMsg)

%PSM_ISDIALOGMESSAGE = %WM_USER + 117

FUNCTION PropSheet_IsDialogMessage (BYVAL hDlg AS DWORD, BYREF pMsg AS tagMSG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_ISDIALOGMESSAGE, 0, VARPTR(pMsg))
END FUNCTION

'#define PropSheet_GetCurrentPageHwnd(hDlg) \
'        (HWND)SNDMSG(hDlg, PSM_GETCURRENTPAGEHWND, 0, 0L)

%PSM_GETCURRENTPAGEHWND = %WM_USER + 118

FUNCTION PropSheet_GetCurrentPageHwnd (BYVAL hDlg AS DWORD) AS DWORD
   FUNCTION = SendMessage(hDlg, %PSM_GETCURRENTPAGEHWND, 0, 0)
END FUNCTION

'#define PropSheet_InsertPage(hDlg, index, hpage) \
'        SNDMSG(hDlg, PSM_INSERTPAGE, (WPARAM)(index), (LPARAM)(hpage))

%PSM_INSERTPAGE = %WM_USER + 119

FUNCTION PropSheet_InsertPage (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYVAL hpage AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_INSERTPAGE, index, hpage)
END FUNCTION

'#if _WIN32_WINNT >= 0x0600
'// Only for PSH_AEROWIZARD - used in PSM_SETHEADERTITLE
%PSWIZF_SETCOLOR        = &HFFFFFFFF???   ' ((UINT)(-1))
'#endif

'#if (_WIN32_IE >= 0x0500)

%PSM_SETHEADERTITLEA = %WM_USER + 125
%PSM_SETHEADERTITLEW = %WM_USER + 126

#IF %DEF(%UNICODE)
   %PSM_SETHEADERTITLE  = %PSM_SETHEADERTITLEW
#ELSE
   %PSM_SETHEADERTITLE  = %PSM_SETHEADERTITLEA
#ENDIF

'#define PropSheet_SetHeaderTitle(hDlg, index, lpszText) \
'        SNDMSG(hDlg, PSM_SETHEADERTITLE, (WPARAM)(index), (LPARAM)(lpszText))

SUB PropSheet_SetHeaderTitleA (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYREF szText AS ASCIIZ)
   ' Microsoft shows this returning an "int", but it doesn't.
   SendMessage hDlg, %PSM_SETHEADERTITLEA, index, VARPTR(szText)
END SUB

SUB PropSheet_SetHeaderTitleW (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYREF wszText AS WSTRINGZ)
   SendMessage hDlg, %PSM_SETHEADERTITLEW, index, VARPTR(wszText)
END SUB

#IF %DEF(%UNICODE)
   MACRO PropSheet_SetHeaderTitle = PropSheet_SetHeaderTitleW
#ELSE
   MACRO PropSheet_SetHeaderTitle = PropSheet_SetHeaderTitleA
#ENDIF

%PSM_SETHEADERSUBTITLEA = %WM_USER + 127
%PSM_SETHEADERSUBTITLEW = %WM_USER + 128

#IF %DEF(%UNICODE)
   %PSM_SETHEADERSUBTITLE  = %PSM_SETHEADERSUBTITLEW
#ELSE
   %PSM_SETHEADERSUBTITLE  = %PSM_SETHEADERSUBTITLEA
#ENDIF

'#define PropSheet_SetHeaderSubTitle(hDlg, index, lpszText) \
'        SNDMSG(hDlg, PSM_SETHEADERSUBTITLE, (WPARAM)(index), (LPARAM)(lpszText))

SUB PropSheet_SetHeaderSubTitleA (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYREF szText AS ASCIIZ)
   SendMessage hDlg, %PSM_SETHEADERSUBTITLEA, index, VARPTR(szText)
END SUB

SUB PropSheet_SetHeaderSubTitleW (BYVAL hDlg AS DWORD, BYVAL index AS LONG, BYREF wszText AS WSTRINGZ)
   SendMessage hDlg, %PSM_SETHEADERSUBTITLEW, index, VARPTR(wszText)
END SUB

#IF %DEF(%UNICODE)
   MACRO PropSheet_SetHeaderSubTitle  = PropSheet_SetHeaderSubTitleW
#ELSE
   MACRO PropSheet_SetHeaderSubTitle  = PropSheet_SetHeaderSubTitleA
#ENDIF

'#define PropSheet_HwndToIndex(hDlg, hwnd) \
'        (int)SNDMSG(hDlg, PSM_HWNDTOINDEX, (WPARAM)(hwnd), 0)

%PSM_HWNDTOINDEX = %WM_USER + 129

FUNCTION PropSheet_HwndToIndex (BYVAL hDlg AS DWORD, BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_HWNDTOINDEX, hwnd, 0)
END FUNCTION

'#define PropSheet_IndexToHwnd(hDlg, i) \
'        (HWND)SNDMSG(hDlg, PSM_INDEXTOHWND, (WPARAM)(i), 0)

%PSM_INDEXTOHWND = %WM_USER + 130

FUNCTION PropSheet_IndexToHwnd (BYVAL hDlg AS DWORD, BYVAL iPageIndex AS LONG) AS DWORD
   FUNCTION = SendMessage(hDlg, %PSM_INDEXTOHWND, iPageIndex, 0)
END FUNCTION

'#define PropSheet_PageToIndex(hDlg, hpage) \
'        (int)SNDMSG(hDlg, PSM_PAGETOINDEX, 0, (LPARAM)(hpage))

%PSM_PAGETOINDEX = %WM_USER + 131

FUNCTION PropSheet_PageToIndex (BYVAL hDlg AS DWORD, BYVAL hpage AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_PAGETOINDEX, 0, hpage)
END FUNCTION

'#define PropSheet_IndexToPage(hDlg, i) \
'        (HPROPSHEETPAGE)SNDMSG(hDlg, PSM_INDEXTOPAGE, (WPARAM)(i), 0)

%PSM_INDEXTOPAGE = %WM_USER + 132

FUNCTION PropSheet_IndexToPage (BYVAL hDlg AS DWORD, BYVAL iPageIndex AS LONG) AS DWORD
   FUNCTION = SendMessage(hDlg, %PSM_INDEXTOPAGE, iPageIndex, 0)
END FUNCTION

'#define PropSheet_IdToIndex(hDlg, id) \
'        (int)SNDMSG(hDlg, PSM_IDTOINDEX, 0, (LPARAM)(id))

%PSM_IDTOINDEX = %WM_USER + 133

FUNCTION PropSheet_IdToIndex (BYVAL hDlg AS DWORD, BYVAL iPageID AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_IDTOINDEX, 0, iPageID)
END FUNCTION

'#define PropSheet_IndexToId(hDlg, i) \
'        SNDMSG(hDlg, PSM_INDEXTOID, (WPARAM)(i), 0)

%PSM_INDEXTOID = %WM_USER + 134

FUNCTION PropSheet_IndexToId (BYVAL hDlg AS DWORD, BYVAL iPageIndex AS LONG) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_INDEXTOID, iPageIndex, 0)
END FUNCTION

'#define PropSheet_GetResult(hDlg) \
'        SNDMSG(hDlg, PSM_GETRESULT, 0, 0)

%PSM_GETRESULT = %WM_USER + 135

FUNCTION PropSheet_GetResult (BYVAL hDlg AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_GETRESULT, 0, 0)
END FUNCTION

'#define PropSheet_RecalcPageSizes(hDlg) \
'        SNDMSG(hDlg, PSM_RECALCPAGESIZES, 0, 0)

%PSM_RECALCPAGESIZES = %WM_USER + 136

FUNCTION PropSheet_RecalcPageSizes (BYVAL hDlg AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_RECALCPAGESIZES, 0, 0)
END FUNCTION

'#endif // 0x0500

'#if _WIN32_WINNT >= 0x0600
'// Only UNICODE
'// These messages are only for Aero Wizard style wizards. The Wizard author
'// needs to specify the PSH_AEROWIZARD flag in the dwFlags member of the PROPSHEETHEADER
'// structure to get this behavior.

%PSM_SETNEXTTEXTW         = (%WM_USER + 137)
%PSM_SETNEXTTEXT          = %PSM_SETNEXTTEXTW

FUNCTION PropSheet_SetNextText (BYVAL hDlg AS DWORD, BYREF wszText AS WSTRINGZ) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_SETNEXTTEXT, 0, VARPTR(wszText))
END FUNCTION

%PSWIZB_SHOW                    = 0
%PSWIZB_RESTORE                 = 1

%PSM_SHOWWIZBUTTONS             = (%WM_USER + 138)

FUNCTION PropSheet_ShowWizButtons (BYVAL hDlg AS DWORD, BYVAL dwFlag AS DWORD, BYVAL dwButton AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_SHOWWIZBUTTONS, dwFlag, dwButton)
END FUNCTION

%PSM_ENABLEWIZBUTTONS           = (%WM_USER + 139)

FUNCTION PropSheet_EnableWizButtons (BYVAL hDlg AS DWORD, BYVAL dwState AS DWORD, BYVAL dwMask AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_ENABLEWIZBUTTONS, dwState, dwMask)
END FUNCTION

%PSM_SETBUTTONTEXTW         = (%WM_USER + 140)
%PSM_SETBUTTONTEXT          = %PSM_SETBUTTONTEXTW

FUNCTION PropSheet_SetButtonText (BYVAL hDlg AS DWORD, BYVAL dwButton AS DWORD, BYREF wszText AS WSTRINGZ) AS LONG
   FUNCTION = SendMessage(hDlg, %PSM_SETBUTTONTEXTW, dwButton, VARPTR(wszText))
END FUNCTION

'#endif // 0x0600

%ID_PSRESTARTWINDOWS = 2
%ID_PSREBOOTSYSTEM   = %ID_PSRESTARTWINDOWS OR &H1

%WIZ_CXDLG      = 276
%WIZ_CYDLG      = 140

%WIZ_CXBMP      = 80

%WIZ_BODYX      = 92
%WIZ_BODYCX     = 184

%PROP_SM_CXDLG  = 212
%PROP_SM_CYDLG  = 188

%PROP_MED_CXDLG = 227
%PROP_MED_CYDLG = 215

%PROP_LG_CXDLG  = 252
%PROP_LG_CYDLG  = 218
