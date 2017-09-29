' ########################################################################################
' Microsoft Windows
' File: OleDlg.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEDLG_INC = 1

'Copyright (c) Microsoft Corporation. All rights reserved.

'Module Name:

'        oledlg.h

'Abstract:

'        Include file for the OLE common dialogs.
'        The following dialog implementations are provided:
'                - Insert Object Dialog
'                - Convert Object Dialog
'                - Paste Special Dialog
'                - Change Icon Dialog
'                - Edit Links Dialog
'                - Update Links Dialog
'                - Change Source Dialog
'                - Busy Dialog
'                - User Error Message Dialog
'                - Object Properties Dialog

'--*/

#INCLUDE ONCE "ole2.inc"

'#ifndef _INC_SHELLAPI
'#include <shellapi.h>
'#endif

#INCLUDE ONCE "commdlg.inc"

'#include <string.h>
'#include <tchar.h>

#INCLUDE ONCE "dlgs.inc"        ' // common dialog IDs

'//Maximum path size (not defined in any header)
%OLEUI_CCHPATHMAX                = 256

'// Help Button Identifier
%IDC_OLEUIHELP                   = 99

'// Insert Object Dialog identifiers
%IDC_IO_CREATENEW                = 2100
%IDC_IO_CREATEFROMFILE           = 2101
%IDC_IO_LINKFILE                 = 2102
%IDC_IO_OBJECTTYPELIST           = 2103
%IDC_IO_DISPLAYASICON            = 2104
%IDC_IO_CHANGEICON               = 2105
%IDC_IO_FILE                     = 2106
%IDC_IO_FILEDISPLAY              = 2107
%IDC_IO_RESULTIMAGE              = 2108
%IDC_IO_RESULTTEXT               = 2109
%IDC_IO_ICONDISPLAY              = 2110
%IDC_IO_OBJECTTYPETEXT           = 2111    ' //{{NOHELP}}
%IDC_IO_FILETEXT                 = 2112    ' //{{NOHELP}}
%IDC_IO_FILETYPE                 = 2113
%IDC_IO_INSERTCONTROL            = 2114
%IDC_IO_ADDCONTROL               = 2115
%IDC_IO_CONTROLTYPELIST          = 2116

'// Paste Special Dialog identifiers
%IDC_PS_PASTE                    = 500
%IDC_PS_PASTELINK                = 501
%IDC_PS_SOURCETEXT               = 502
%IDC_PS_PASTELIST                = 503     ' //{{NOHELP}}
%IDC_PS_PASTELINKLIST            = 504     ' //{{NOHELP}}
%IDC_PS_DISPLAYLIST              = 505
%IDC_PS_DISPLAYASICON            = 506
%IDC_PS_ICONDISPLAY              = 507
%IDC_PS_CHANGEICON               = 508
%IDC_PS_RESULTIMAGE              = 509
%IDC_PS_RESULTTEXT               = 510

'// Change Icon Dialog identifiers
%IDC_CI_GROUP                    = 120     ' //{{NOHELP}}
%IDC_CI_CURRENT                  = 121
%IDC_CI_CURRENTICON              = 122
%IDC_CI_DEFAULT                  = 123
%IDC_CI_DEFAULTICON              = 124
%IDC_CI_FROMFILE                 = 125
%IDC_CI_FROMFILEEDIT             = 126
%IDC_CI_ICONLIST                 = 127
%IDC_CI_LABEL                    = 128     ' //{{NOHELP}
%IDC_CI_LABELEDIT                = 129
%IDC_CI_BROWSE                   = 130
%IDC_CI_ICONDISPLAY              = 131

'// Convert Dialog identifiers
%IDC_CV_OBJECTTYPE               = 150
%IDC_CV_DISPLAYASICON            = 152
%IDC_CV_CHANGEICON               = 153
%IDC_CV_ACTIVATELIST             = 154
%IDC_CV_CONVERTTO                = 155
%IDC_CV_ACTIVATEAS               = 156
%IDC_CV_RESULTTEXT               = 157
%IDC_CV_CONVERTLIST              = 158
%IDC_CV_ICONDISPLAY              = 165

'// Edit Links Dialog identifiers
%IDC_EL_CHANGESOURCE             = 201
%IDC_EL_AUTOMATIC                = 202
%IDC_EL_CANCELLINK               = 209
%IDC_EL_UPDATENOW                = 210
%IDC_EL_OPENSOURCE               = 211
%IDC_EL_MANUAL                   = 212
%IDC_EL_LINKSOURCE               = 216
%IDC_EL_LINKTYPE                 = 217
%IDC_EL_LINKSLISTBOX             = 206
%IDC_EL_COL1                     = 220     ' //{{NOHELP}}
%IDC_EL_COL2                     = 221     ' //{{NOHELP}}
%IDC_EL_COL3                     = 222     ' //{{NOHELP}}

'// Busy dialog identifiers
%IDC_BZ_RETRY                    = 600
%IDC_BZ_ICON                     = 601
%IDC_BZ_MESSAGE1                 = 602     ' //{{NOHELP}}
%IDC_BZ_SWITCHTO                 = 604

'// Update Links dialog identifiers
%IDC_UL_METER                    = 1029    ' //{{NOHELP}}
%IDC_UL_STOP                     = 1030    ' //{{NOHELP}}
%IDC_UL_PERCENT                  = 1031    ' //{{NOHELP}}
%IDC_UL_PROGRESS                 = 1032    ' //{{NOHELP}}

'// User Prompt dialog identifiers
%IDC_PU_LINKS                    = 900     ' //{{NOHELP}}
%IDC_PU_TEXT                     = 901     ' //{{NOHELP}}
%IDC_PU_CONVERT                  = 902     ' //{{NOHELP}}
%IDC_PU_ICON                     = 908     ' //{{NOHELP}}

'// General Properties identifiers
%IDC_GP_OBJECTNAME               = 1009
%IDC_GP_OBJECTTYPE               = 1010
%IDC_GP_OBJECTSIZE               = 1011
%IDC_GP_CONVERT                  = 1013
%IDC_GP_OBJECTICON               = 1014    ' //{{NOHELP}}
%IDC_GP_OBJECTLOCATION           = 1022

'// View Properties identifiers
%IDC_VP_PERCENT                  = 1000
%IDC_VP_CHANGEICON               = 1001
%IDC_VP_EDITABLE                 = 1002
%IDC_VP_ASICON                   = 1003
%IDC_VP_RELATIVE                 = 1005
%IDC_VP_SPIN                     = 1006
%IDC_VP_SCALETXT                 = 1034
%IDC_VP_ICONDISPLAY              = 1021
%IDC_VP_RESULTIMAGE              = 1033

'// Link Properties identifiers
%IDC_LP_OPENSOURCE               = 1006
%IDC_LP_UPDATENOW                = 1007
%IDC_LP_BREAKLINK                = 1008
%IDC_LP_LINKSOURCE               = 1012
%IDC_LP_CHANGESOURCE             = 1015
%IDC_LP_AUTOMATIC                = 1016
%IDC_LP_MANUAL                   = 1017
%IDC_LP_DATE                     = 1018
%IDC_LP_TIME                     = 1019

'// Dialog Identifiers as passed in Help messages to identify the source.
%IDD_INSERTOBJECT                = 1000
%IDD_CHANGEICON                  = 1001
%IDD_CONVERT                     = 1002
%IDD_PASTESPECIAL                = 1003
%IDD_EDITLINKS                   = 1004
%IDD_BUSY                        = 1006
%IDD_UPDATELINKS                 = 1007
%IDD_CHANGESOURCE                = 1009
%IDD_INSERTFILEBROWSE            = 1010
%IDD_CHANGEICONBROWSE            = 1011
%IDD_CONVERTONLY                 = 1012
%IDD_CHANGESOURCE4               = 1013
%IDD_GNRLPROPS                   = 1100
%IDD_VIEWPROPS                   = 1101
%IDD_LINKPROPS                   = 1102
%IDD_CONVERT4                    = 1103
%IDD_CONVERTONLY4                = 1104
%IDD_EDITLINKS4                  = 1105
%IDD_GNRLPROPS4                  = 1106
%IDD_LINKPROPS4                  = 1107
%IDD_PASTESPECIAL4               = 1108

'// The following Dialogs are message dialogs used by OleUIPromptUser API
%IDD_CANNOTUPDATELINK            = 1008
%IDD_LINKSOURCEUNAVAILABLE       = 1020
%IDD_SERVERNOTFOUND              = 1023
%IDD_OUTOFMEMORY                 = 1024
%IDD_SERVERNOTREGW               = 1021
%IDD_LINKTYPECHANGEDW            = 1022
%IDD_SERVERNOTREGA               = 1025
%IDD_LINKTYPECHANGEDA            = 1026

'#pragma pack(push, 8)

'// Delimeter used to separate ItemMoniker pieces of a composite moniker
'#ifdef _MAC
'        #define OLESTDDELIM ":"
'#else
'        #define OLESTDDELIM TEXT("\\")
'#endif
$OLESTDDELIM = "\"

'// Hook type used in all structures.
'typedef UINT (CALLBACK *LPFNOLEUIHOOK)(HWND, UINT, WPARAM, LPARAM);

'// Strings for registered messages
'#define SZOLEUI_MSG_HELP                TEXT("OLEUI_MSG_HELP")
'#define SZOLEUI_MSG_ENDDIALOG           TEXT("OLEUI_MSG_ENDDIALOG")
'#define SZOLEUI_MSG_BROWSE              TEXT("OLEUI_MSG_BROWSE")
'#define SZOLEUI_MSG_CHANGEICON          TEXT("OLEUI_MSG_CHANGEICON")
'#define SZOLEUI_MSG_CLOSEBUSYDIALOG     TEXT("OLEUI_MSG_CLOSEBUSYDIALOG")
'#define SZOLEUI_MSG_CONVERT             TEXT("OLEUI_MSG_CONVERT")
'#define SZOLEUI_MSG_CHANGESOURCE        TEXT("OLEUI_MSG_CHANGESOURCE")
'#define SZOLEUI_MSG_ADDCONTROL          TEXT("OLEUI_MSG_ADDCONTROL")
'#define SZOLEUI_MSG_BROWSE_OFN          TEXT("OLEUI_MSG_BROWSE_OFN")

$SZOLEUI_MSG_HELP                = "OLEUI_MSG_HELP"
$SZOLEUI_MSG_ENDDIALOG           = "OLEUI_MSG_ENDDIALOG"
$SZOLEUI_MSG_BROWSE              = "OLEUI_MSG_BROWSE"
$SZOLEUI_MSG_CHANGEICON          = "OLEUI_MSG_CHANGEICON"
$SZOLEUI_MSG_CLOSEBUSYDIALOG     = "OLEUI_MSG_CLOSEBUSYDIALOG"
$SZOLEUI_MSG_CONVERT             = "OLEUI_MSG_CONVERT"
$SZOLEUI_MSG_CHANGESOURCE        = "OLEUI_MSG_CHANGESOURCE"
$SZOLEUI_MSG_ADDCONTROL          = "OLEUI_MSG_ADDCONTROL"
$SZOLEUI_MSG_BROWSE_OFN          = "OLEUI_MSG_BROWSE_OFN"

'// Identifiers for SZOLEUI_MSG_BROWSE_OFN (in wParam)
%ID_BROWSE_CHANGEICON            = 1
%ID_BROWSE_INSERTFILE            = 2
%ID_BROWSE_ADDCONTROL            = 3
%ID_BROWSE_CHANGESOURCE          = 4

'// Standard success/error definitions
%OLEUI_FALSE                     = 0
%OLEUI_SUCCESS                   = 1    ' // No error, same as OLEUI_OK
%OLEUI_OK                        = 1    ' // OK button pressed
%OLEUI_CANCEL                    = 2    ' // Cancel button pressed

%OLEUI_ERR_STANDARDMIN           = 100
%OLEUI_ERR_OLEMEMALLOC           = 100
%OLEUI_ERR_STRUCTURENULL         = 101  ' // Standard field validation
%OLEUI_ERR_STRUCTUREINVALID      = 102
%OLEUI_ERR_CBSTRUCTINCORRECT     = 103
%OLEUI_ERR_HWNDOWNERINVALID      = 104
%OLEUI_ERR_LPSZCAPTIONINVALID    = 105
%OLEUI_ERR_LPFNHOOKINVALID       = 106
%OLEUI_ERR_HINSTANCEINVALID      = 107
%OLEUI_ERR_LPSZTEMPLATEINVALID   = 108
%OLEUI_ERR_HRESOURCEINVALID      = 109

%OLEUI_ERR_FINDTEMPLATEFAILURE   = 110  ' // Initialization errors
%OLEUI_ERR_LOADTEMPLATEFAILURE   = 111
%OLEUI_ERR_DIALOGFAILURE         = 112
%OLEUI_ERR_LOCALMEMALLOC         = 113
%OLEUI_ERR_GLOBALMEMALLOC        = 114
%OLEUI_ERR_LOADSTRING            = 115

%OLEUI_ERR_STANDARDMAX           = 116  ' // Start here for specific errors.

'// Miscellaneous utility functions.
DECLARE FUNCTION OleUIAddVerbMenuW IMPORT "OLEDLG.DLL" ALIAS "OleUIAddVerbMenuW" ( _
   BYVAL lpOleObj AS IOleObject _                       ' __in_opt LPOLEOBJECT *lpOleObj
 , BYREF lpszShortType AS WSTRINGZ _                    ' __in_opt LPCWSTR lpszShortType
 , BYVAL hMenu AS DWORD _                               ' __in  HMENU hMenu
 , BYVAL uPos AS DWORD _                                ' __in  UINT uPos
 , BYVAL uIDVerbMin AS DWORD _                          ' __in  UINT uIDVerbMin
 , BYVAL uIDVerbMax AS DWORD _                          ' __in  UINT uIDVerbMax
 , BYVAL bAddConvert AS LONG _                          ' __in  BOOL bAddConvert
 , BYVAL idConvert AS DWORD _                           ' __in  UINT idConvert
 , BYREF lphMenu AS DWORD _                             ' __out HMENU FAR * lphMenu
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OleUIAddVerbMenuA IMPORT "OLEDLG.DLL" ALIAS "OleUIAddVerbMenu" ( _
   BYVAL lpOleObj AS IOleObject _                       ' __in_opt LPOLEOBJECT *lpOleObj
 , BYREF lpszShortType AS ASCIIZ _                      ' __in_opt LPCSTR lpszShortType
 , BYVAL hMenu AS DWORD _                               ' __in  HMENU hMenu
 , BYVAL uPos AS DWORD _                                ' __in  UINT uPos
 , BYVAL uIDVerbMin AS DWORD _                          ' __in  UINT uIDVerbMin
 , BYVAL uIDVerbMax AS DWORD _                          ' __in  UINT uIDVerbMax
 , BYVAL bAddConvert AS LONG _                          ' __in  BOOL bAddConvert
 , BYVAL idConvert AS DWORD _                           ' __in  UINT idConvert
 , BYREF lphMenu AS DWORD _                             ' __out HMENU FAR * lphMenu
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OleUIAddVerbMenu = OleUIAddVerbMenuW
#ELSE
   MACRO OleUIAddVerbMenu = OleUIAddVerbMenuA
#ENDIF

'/////////////////////////////////////////////////////////////////////////////
'// INSERT OBJECT DIALOG

' // Size = 112 bytes
TYPE tagOLEUIINSERTOBJECTW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct         AS DWORD           ' DWORD           cbStruct;       // Structure Size
   dwFlags          AS DWORD           ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner        AS DWORD           ' HWND            hWndOwner;      // Owning window
   lpszCaption      AS WSTRINGZ PTR    ' LPCWSTR         lpszCaption;    // Dialog caption bar contents
   lpfnHook         AS DWORD           ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData        AS LONG            ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance        AS DWORD           ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate     AS WSTRINGZ PTR    ' LPCWSTR         lpszTemplate;   // Customized template name
   hResource        AS DWORD           ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUIINSERTOBJECTW.
   clsid            AS GUID            ' CLSID           clsid;          // OUT: Return space for class ID
   lpszFile         AS WSTRINGZ PTR    ' LPWSTR          lpszFile;       // IN-OUT: Filename for inserts or links
   chFile           AS DWORD           ' UINT            cchFile;        // IN: Size of lpszFile buffer: MAX_PATH
   cClsidExclude    AS DWORD           ' UINT            cClsidExclude;  // IN: CLSIDs in lpClsidExclude
   lpClsidExclude   AS GUID PTR        ' LPCLSID         lpClsidExclude; // IN: List of CLSIDs to exclude from listing.
   ' // Specific to create objects if flags say so
   iid              AS GUID            ' IID             iid;            // IN: Requested interface on creation.
   oleRender        AS DWORD           ' DWORD           oleRender;      // IN: Rendering option
   lpFormatEtc      AS FORMATETC PTR   ' LPFORMATETC     lpFormatEtc;    // IN: Desired format
   lpIOleClientSite AS DWORD PTR       ' LPOLECLIENTSITE lpIOleClientSite;   // IN: Site to be use for the object.
   lpIStorage       AS DWORD PTR       ' LPSTORAGE       lpIStorage;     // IN: Storage used for the object
   ppvObj           AS DWORD PTR       ' LPVOID          *ppvObj;        // OUT: Where the object is returned.
   sc               AS LONG            ' SCODE           sc;             // OUT: Result of creation calls.
   hMetaPict        AS DWORD           ' HGLOBAL         hMetaPict;      // OUT: metafile aspect (METAFILEPICT)
END TYPE

' // Size = 112 bytes
TYPE tagOLEUIINSERTOBJECTA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct         AS DWORD           ' DWORD           cbStruct;       // Structure Size
   dwFlags          AS DWORD           ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner        AS DWORD           ' HWND            hWndOwner;      // Owning window
   lpszCaption      AS ASCIIZ PTR      ' LPCSTR          lpszCaption;    // Dialog caption bar contents
   lpfnHook         AS DWORD           ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData        AS LONG            ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance        AS DWORD           ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate     AS ASCIIZ PTR      ' LPCSTR          lpszTemplate;   // Customized template name
   hResource        AS DWORD           ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUIINSERTOBJECTW.
   clsid            AS GUID            ' CLSID           clsid;          // OUT: Return space for class ID
   lpszFile         AS ASCIIZ PTR      ' LPSTR           lpszFile;       // IN-OUT: Filename for inserts or links
   chFile           AS DWORD           ' UINT            cchFile;        // IN: Size of lpszFile buffer: MAX_PATH
   cClsidExclude    AS DWORD           ' UINT            cClsidExclude;  // IN: CLSIDs in lpClsidExclude
   lpClsidExclude   AS GUID PTR        ' LPCLSID         lpClsidExclude; // IN: List of CLSIDs to exclude from listing.
   ' // Specific to create objects if flags say so
   iid              AS GUID            ' IID             iid;            // IN: Requested interface on creation.
   oleRender        AS DWORD           ' DWORD           oleRender;      // IN: Rendering option
   lpFormatEtc      AS FORMATETC PTR   ' LPFORMATETC     lpFormatEtc;    // IN: Desired format
   lpIOleClientSite AS DWORD PTR       ' LPOLECLIENTSITE lpIOleClientSite;   // IN: Site to be use for the object.
   lpIStorage       AS DWORD PTR       ' LPSTORAGE       lpIStorage;     // IN: Storage used for the object
   ppvObj           AS DWORD PTR       ' LPVOID          *ppvObj;        // OUT: Where the object is returned.
   sc               AS LONG            ' SCODE           sc;             // OUT: Result of creation calls.
   hMetaPict        AS DWORD           ' HGLOBAL         hMetaPict;      // OUT: metafile aspect (METAFILEPICT)
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIINSERTOBJECT = tagOLEUIINSERTOBJECTW
#ELSE
   MACRO tagOLEUIINSERTOBJECT = tagOLEUIINSERTOBJECTA
#ENDIF

DECLARE FUNCTION OleUIInsertObjectA IMPORT "OLEDLG.DLL" ALIAS "OleUIInsertObjectA" ( _
   BYREF lpIO AS tagOLEUIINSERTOBJECTA _                ' __in LPOLEUIINSERTOBJECTA lpIO
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIInsertObjectW IMPORT "OLEDLG.DLL" ALIAS "OleUIInsertObjectW" ( _
   BYREF lpIO AS tagOLEUIINSERTOBJECTW _                ' __in LPOLEUIINSERTOBJECTW lpIO
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIInsertObject = OleUIInsertObjectW
#ELSE
   MACRO OleUIInsertObject = OleUIInsertObjectA
#ENDIF

'// Insert Object flags
%IOF_SHOWHELP                    = &H00000001???
%IOF_SELECTCREATENEW             = &H00000002???
%IOF_SELECTCREATEFROMFILE        = &H00000004???
%IOF_CHECKLINK                   = &H00000008???
%IOF_CHECKDISPLAYASICON          = &H00000010???
%IOF_CREATENEWOBJECT             = &H00000020???
%IOF_CREATEFILEOBJECT            = &H00000040???
%IOF_CREATELINKOBJECT            = &H00000080???
%IOF_DISABLELINK                 = &H00000100???
%IOF_VERIFYSERVERSEXIST          = &H00000200???
%IOF_DISABLEDISPLAYASICON        = &H00000400???
%IOF_HIDECHANGEICON              = &H00000800???
%IOF_SHOWINSERTCONTROL           = &H00001000???
%IOF_SELECTCREATECONTROL         = &H00002000???

'// Insert Object specific error codes
%OLEUI_IOERR_LPSZFILEINVALID         = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_IOERR_LPSZLABELINVALID        = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_IOERR_HICONINVALID            = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_IOERR_LPFORMATETCINVALID      = %OLEUI_ERR_STANDARDMAX + 3
%OLEUI_IOERR_PPVOBJINVALID           = %OLEUI_ERR_STANDARDMAX + 4
%OLEUI_IOERR_LPIOLECLIENTSITEINVALID = %OLEUI_ERR_STANDARDMAX + 5
%OLEUI_IOERR_LPISTORAGEINVALID       = %OLEUI_ERR_STANDARDMAX + 6
%OLEUI_IOERR_SCODEHASERROR           = %OLEUI_ERR_STANDARDMAX + 7
%OLEUI_IOERR_LPCLSIDEXCLUDEINVALID   = %OLEUI_ERR_STANDARDMAX + 8
%OLEUI_IOERR_CCHFILEINVALID          = %OLEUI_ERR_STANDARDMAX + 9

'/////////////////////////////////////////////////////////////////////////////
'// PASTE SPECIAL DIALOG

'// The OLEUIPASTEFLAG enumeration is used by the OLEUIPASTEENTRY structure.
'//
'// OLEUIPASTE_ENABLEICON: If the container does not specify this flag for
'//      the entry in the OLEUIPASTEENTRY array passed as input to
'//      OleUIPasteSpecial, the DisplayAsIcon button will be unchecked and
'//      disabled when the the user selects the format that corresponds to
'//      the entry.
'//
'// OLEUIPASTE_PASTEONLY: Indicates that the entry in the OLEUIPASTEENTRY
'//      array is valid for pasting only.
'//
'// OLEUIPASTE_PASTE: Indicates that the entry in the OLEUIPASTEENTRY array
'//      is valid for pasting. It may also be valid for linking if any of
'//      the following linking flags are specified.
'//
'// If the entry in the OLEUIPASTEENTRY array is valid for linking, the
'// following flags indicate which link types are acceptable by OR'ing
'// together the appropriate OLEUIPASTE_LINKTYPE<#> values.
'//
'// These values correspond as follows to the array of link types passed to
'// OleUIPasteSpecial:
'//
'//   OLEUIPASTE_LINKTYPE1 = arrLinkTypes[0]
'//   OLEUIPASTE_LINKTYPE2 = arrLinkTypes[1]
'//   OLEUIPASTE_LINKTYPE3 = arrLinkTypes[2]
'//   OLEUIPASTE_LINKTYPE4 = arrLinkTypes[3]
'//   OLEUIPASTE_LINKTYPE5 = arrLinkTypes[4]
'//   OLEUIPASTE_LINKTYPE6 = arrLinkTypes[5]
'//   OLEUIPASTE_LINKTYPE7 = arrLinkTypes[6]
'//   OLEUIPASTE_LINKTYPE8 = arrLinkTypes[7]
'//
'// where,
'//   UINT arrLinkTypes[8] is an array of registered clipboard formats for
'//   linking. A maximium of 8 link types are allowed.

' OLEUIPASTEFLAG enum
%OLEUIPASTE_ENABLEICON  = 2048   ' // enable display as icon
%OLEUIPASTE_PASTEONLY   = 0
%OLEUIPASTE_PASTE       = 512
%OLEUIPASTE_LINKANYTYPE = 1024
%OLEUIPASTE_LINKTYPE1   = 1
%OLEUIPASTE_LINKTYPE2   = 2
%OLEUIPASTE_LINKTYPE3   = 4
%OLEUIPASTE_LINKTYPE4   = 8
%OLEUIPASTE_LINKTYPE5   = 16
%OLEUIPASTE_LINKTYPE6   = 32
%OLEUIPASTE_LINKTYPE7   = 64
%OLEUIPASTE_LINKTYPE8   = 128

'// OLEUIPASTEENTRY structure
'//
'// An array of OLEUIPASTEENTRY entries is specified for the PasteSpecial
'// dialog box. Each entry includes a FORMATETC which specifies the
'// formats that are acceptable, a string that is to represent the format
'// in the  dialog's list box, a string to customize the result text of the
'// dialog and a set of flags from the OLEUIPASTEFLAG enumeration.  The
'// flags indicate if the entry is valid for pasting only, linking only or
'// both pasting and linking.

' // Size = 36 bytes
TYPE tagOLEUIPASTEENTRYW
   fmtetc          AS FORMATETC      ' FORMATETC fmtetc;         // Format that is acceptable.
   lpstrFormatName AS WSTRINGZ PTR   ' LPCWSTR   lpstrFormatName // String that represents the format
                                     '                           // to the user. %s is replaced by the
                                     '                           // full user type name of the object.
   lpstrResultText AS WSTRINGZ PTR   ' LPCWSTR   lpstrResultText // String to customize the result text
                                     '                           // of the dialog when the user
                                     '                           // selects the format correspoding to
                                     '                           // this entry. Any %s in this string
                                     '                           // is replaced by the the application
                                     '                           // name or FullUserTypeName of the
                                     '                           // object on the clipboard.
   dwFlags         AS DWORD          ' DWORD     dwFlags;        // Values from OLEUIPASTEFLAG enum
   dwScratchSpace  AS DWORD          ' DWORD     dwScratchSpace; // Scratch space used internally.
END TYPE

' // Size = 36 bytes
TYPE tagOLEUIPASTEENTRYA
   fmtetc          AS FORMATETC   ' FORMATETC fmtetc;         // Format that is acceptable.
   lpstrFormatName AS ASCIIZ PTR  ' LPCSTR   lpstrFormatName  // String that represents the format
                                  '                           // to the user. %s is replaced by the
                                  '                           // full user type name of the object.
   lpstrResultText AS ASCIIZ PTR  ' LPCSTR   lpstrResultText  // String to customize the result text
                                  '                           // of the dialog when the user
                                  '                           // selects the format correspoding to
                                  '                           // this entry. Any %s in this string
                                  '                           // is replaced by the the application
                                  '                           // name or FullUserTypeName of the
                                  '                           // object on the clipboard.
   dwFlags         AS DWORD       ' DWORD     dwFlags;        // Values from OLEUIPASTEFLAG enum
   dwScratchSpace  AS DWORD       ' DWORD     dwScratchSpace; // Scratch space used internally.
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIPASTEENTRY = tagOLEUIPASTEENTRYW
#ELSE
   MACRO tagOLEUIPASTEENTRY = tagOLEUIPASTEENTRYA
#ENDIF

'// Maximum number of link types
%PS_MAXLINKTYPES = 8

' // Size = 84 bytes
TYPE tagOLEUIPASTESPECIALW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct        AS DWORD                    ' DWORD           cbStruct       // Structure Size
   dwFlags         AS DWORD                    ' DWORD           dwFlags        // IN-OUT:  Flags
   hWndOwner       AS DWORD                    ' HWND            hWndOwner      // Owning window
   lpszCaption     AS WSTRINGZ PTR             ' LPCWSTR         lpszCaption    // Dialog caption bar contents
   lpfnHook        AS DWORD                    ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData       AS DWORD                    ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance       AS DWORD                    ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate    AS WSTRINGZ PTR             ' LPCWSTR         lpszTemplate   // Customized template name
   hResource       AS DWORD                    ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUIPASTESPECIALW.
   lpSrcDataObj    AS DWORD PTR                ' LPDATAOBJECT    lpSrcDataObj   // IN-OUT: Source IDataObject* on the clipboard
                                               '                                // If lpSrcDataObj is NULL when OleUIPasteSpecial is called, then
                                               '                                // OleUIPasteSpecial will attempt to retrieve a pointer to an
                                               '                                // IDataObject from the clipboard.  If OleUIPasteSpecial succeeds
                                               '                                // then it is the caller's responsibility to free the IDataObject
                                               '                                // returned in lpSrcDataObj.
   arrPasteEntries AS tagOLEUIPASTEENTRYW PTR  ' LPOLEUIPASTEENTRYW arrPasteEntries // IN: Array of acceptable formats
   cPasteEntries   AS LONG                     ' int             cPasteEntries  // IN: No. of OLEUIPASTEENTRY array entries
   arrLinkTypes    AS DWORD PTR                ' UINT FAR*       arrLinkTypes   // IN: List of acceptable link types
   cLinkTypes      AS LONG                     ' int             cLinkTypes     // IN: Number of link types
   cClsidExclude   AS DWORD                    ' UINT            cClsidExclude  // IN: Number of CLSIDs in lpClsidExclude
   lpClsidExclude  AS GUID PTR                 ' LPCLSID         lpClsidExclude // IN: List of CLSIDs to exclude from list.
   nSelectedIndex  AS LONG                     ' int             nSelectedIndex // OUT: Index that the user selected
   fLink           AS LONG                     ' BOOL            fLink          // OUT: Indicates if Paste or PasteLink
   hMetaPict       AS DWORD                    ' HGLOBAL         hMetaPict      // OUT: Handle to Metafile containing icon
   sizel           AS SIZEL                    ' SIZEL           sizel          // OUT: size of object/link in its source
                                               '                                //  may be 0,0 if different display
                                               '                                //  aspect is chosen.
END TYPE

' // Size = 84 bytes
TYPE tagOLEUIPASTESPECIALA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct        AS DWORD                    ' DWORD           cbStruct       // Structure Size
   dwFlags         AS DWORD                    ' DWORD           dwFlags        // IN-OUT:  Flags
   hWndOwner       AS DWORD                    ' HWND            hWndOwner      // Owning window
   lpszCaption     AS ASCIIZ PTR               ' LPCSTR          lpszCaption    // Dialog caption bar contents
   lpfnHook        AS DWORD                    ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData       AS DWORD                    ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance       AS DWORD                    ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate    AS ASCIIZ PTR               ' LPCSTR          lpszTemplate   // Customized template name
   hResource       AS DWORD                    ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUIPASTESPECIALW.
   lpSrcDataObj    AS DWORD PTR                ' LPDATAOBJECT    lpSrcDataObj   // IN-OUT: Source IDataObject* on the clipboard
                                               '                                // If lpSrcDataObj is NULL when OleUIPasteSpecial is called, then
                                               '                                // OleUIPasteSpecial will attempt to retrieve a pointer to an
                                               '                                // IDataObject from the clipboard.  If OleUIPasteSpecial succeeds
                                               '                                // then it is the caller's responsibility to free the IDataObject
                                               '                                // returned in lpSrcDataObj.
   arrPasteEntries AS tagOLEUIPASTEENTRYA PTR  ' LPOLEUIPASTEENTRYA arrPasteEntries // IN: Array of acceptable formats
   cPasteEntries   AS LONG                     ' int             cPasteEntries  // IN: No. of OLEUIPASTEENTRY array entries
   arrLinkTypes    AS DWORD PTR                ' UINT FAR*       arrLinkTypes   // IN: List of acceptable link types
   cLinkTypes      AS LONG                     ' int             cLinkTypes     // IN: Number of link types
   cClsidExclude   AS DWORD                    ' UINT            cClsidExclude  // IN: Number of CLSIDs in lpClsidExclude
   lpClsidExclude  AS GUID PTR                 ' LPCLSID         lpClsidExclude // IN: List of CLSIDs to exclude from list.
   nSelectedIndex  AS LONG                     ' int             nSelectedIndex // OUT: Index that the user selected
   fLink           AS LONG                     ' BOOL            fLink          // OUT: Indicates if Paste or PasteLink
   hMetaPict       AS DWORD                    ' HGLOBAL         hMetaPict      // OUT: Handle to Metafile containing icon
   sizel           AS SIZEL                    ' SIZEL           sizel          // OUT: size of object/link in its source
                                               '                                //  may be 0,0 if different display
                                               '                                //  aspect is chosen.
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIPASTESPECIAL = tagOLEUIPASTESPECIALW
#ELSE
   MACRO tagOLEUIPASTESPECIAL = tagOLEUIPASTESPECIALA
#ENDIF

DECLARE FUNCTION OleUIPasteSpecialA IMPORT "OLEDLG.DLL" ALIAS "OleUIPasteSpecialA" ( _
   BYREF lpPS AS tagOLEUIPASTESPECIALA _                ' __in LPOLEUIPASTESPECIALA lpPS
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIPasteSpecialW IMPORT "OLEDLG.DLL" ALIAS "OleUIPasteSpecialW" ( _
   BYREF lpPS AS tagOLEUIPASTESPECIALW _                ' __in LPOLEUIPASTESPECIALW lpPS
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIPasteSpecial = OleUIPasteSpecialW
#ELSE
   MACRO OleUIPasteSpecial = OleUIPasteSpecialA
#ENDIF

'// Paste Special specific flags
%PSF_SHOWHELP                    = &H00000001???
%PSF_SELECTPASTE                 = &H00000002???
%PSF_SELECTPASTELINK             = &H00000004???
'// NOTE: PSF_CHECKDISPLAYASICON is strictly an output flag.
'//       It is ignored if set when calling OleUIPasteSpecial.
%PSF_CHECKDISPLAYASICON          = &H00000008???
%PSF_DISABLEDISPLAYASICON        = &H00000010???
%PSF_HIDECHANGEICON              = &H00000020???
%PSF_STAYONCLIPBOARDCHANGE       = &H00000040???
%PSF_NOREFRESHDATAOBJECT         = &H00000080???

'// Paste Special specific error codes
%OLEUI_IOERR_SRCDATAOBJECTINVALID    = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_IOERR_ARRPASTEENTRIESINVALID  = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_IOERR_ARRLINKTYPESINVALID     = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_PSERR_CLIPBOARDCHANGED        = %OLEUI_ERR_STANDARDMAX + 3
%OLEUI_PSERR_GETCLIPBOARDFAILED      = %OLEUI_ERR_STANDARDMAX + 4

'/////////////////////////////////////////////////////////////////////////////
'// EDIT LINKS DIALOG

'// IOleUILinkContainer interface
'//
'//    This interface must be implemented by container applications that
'//    want to use the EditLinks dialog. the EditLinks dialog calls back
'//    to the container app to perform the OLE functions to manipulate
'//    the links within the container.

' ########################################################################################
' IOleUILinkContainerW interface
' Inherited interface = IUnknown
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUILinkContainerW $IID_IOleUILinkContainerW

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetNextLink ( _                               ' VTable offset = 12
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkUpdateOptions ( _                      ' VTable offset = 16
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL dwUpdateOpt AS DWORD _                       ' __in DWORD dwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkUpdateOptions ( _                      ' VTable offset = 20
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpdwUpdateOpt AS DWORD _                     ' __out DWORD *lpdwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkSource ( _                             ' VTable offset = 24
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpszDisplayName AS WSTRINGZ _                ' __in LPWSTR lpszDisplayName
'   , BYVAL lenFileName AS DWORD _                       ' __in ULONG lenFileName
'   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
'   , BYVAL fValidateSource AS LONG _                    ' __in BOOL fValidateSource
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkSource ( _                             ' VTable offset = 28
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lplpszDisplayName AS DWORD _                 ' __out_opt LPWSTR *lplpszDisplayName
'   , BYREF lplenFileName AS DWORD _                     ' __out ULONG *lplenFileName
'   , BYREF lplpszFullLinkType AS DWORD _                ' __out_opt LPWSTR *lplpszFullLinkType
'   , BYREF lplpszShortLinkType AS DWORD _               ' __out_opt LPWSTR *lplpszShortLinkType
'   , BYREF lpfSourceAvailable AS LONG _                 ' __out BOOL *lpfSourceAvailable
'   , BYREF lpfIsSelected AS LONG _                      ' __out SBOOL *lpfIsSelected
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OpenLinkSource ( _                            ' VTable offset = 32
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateLink ( _                                ' VTable offset = 36
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL fErrorMessage AS LONG _                      ' __in BOOL fErrorMessage
'   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CancelLink ( _                                ' VTable offset = 40
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IOleUILinkContainerA interface
' Inherited interface = IUnknown
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUILinkContainerA $IID_IOleUILinkContainerA

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetNextLink ( _                               ' VTable offset = 12
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkUpdateOptions ( _                      ' VTable offset = 16
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL DWORD _                                      ' __in DWORD dwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkUpdateOptions ( _                      ' VTable offset = 20
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpdwUpdateOpt AS DWORD _                     ' __out DWORD *lpdwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkSource ( _                             ' VTable offset = 24
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpszDisplayName AS ASCIIZ _                  ' __in LPSTR lpszDisplayName
'   , BYVAL lenFileName AS DWORD _                       ' __in ULONG lenFileName
'   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
'   , BYVAL fValidateSource AS LONG _                    ' __in BOOL fValidateSource
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkSource ( _                             ' VTable offset = 28
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lplpszDisplayName AS ASCIIZ _                ' __out_opt LPSTR *lplpszDisplayName
'   , BYREF lplenFileName AS DWORD _                     ' __out ULONG *lplenFileName
'   , BYREF lplpszFullLinkType AS ASCIIZ _               ' __out_opt LPSTR *lplpszFullLinkType
'   , BYREF lplpszShortLinkType AS ASCIIZ _              ' __out_opt LPSTR *lplpszShortLinkType
'   , BYREF lpfSourceAvailable AS LONG _                 ' __out BOOL *lpfSourceAvailable
'   , BYREF lpfIsSelected AS LONG _                      ' __out BOOL *lpfIsSelected
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OpenLinkSource ( _                            ' VTable offset = 32
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateLink ( _                                ' VTable offset = 36
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL fErrorMessage AS LONG _                      ' __in BOOL fErrorMessage
'   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CancelLink ( _                                ' VTable offset = 40
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' // Size = 40 bytes
TYPE tagOLEUIEDITLINKSW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct             AS DWORD          ' DWORD           cbStruct       // Structure Size
   dwFlags              AS DWORD          ' DWORD           dwFlags        // IN-OUT: Flags
   hWndOwner            AS DWORD          ' HWND            hWndOwner      // Owning window
   lpszCaption          AS WSTRINGZ PTR   ' LPCWSTR         lpszCaption    // Dialog caption bar contents
   lpfnHook             AS DWORD          ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData            AS DWORD          ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance            AS DWORD          ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate         AS WSTRINGZ PTR   ' LPCWSTR         lpszTemplate   // Customized template name
   hResource            AS DWORD          ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUIEDITLINKS.
   lpOleUILinkContainer AS DWORD PTR      ' LPOLEUILINKCONTAINERW lpOleUILinkContainer  // IN: Interface to manipulate
END TYPE

' // Size = 40 bytes
TYPE tagOLEUIEDITLINKSA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct             AS DWORD       ' DWORD           cbStruct       // Structure Size
   dwFlags              AS DWORD       ' DWORD           dwFlags        // IN-OUT: Flags
   hWndOwner            AS DWORD       ' HWND            hWndOwner      // Owning window
   lpszCaption          AS ASCIIZ PTR  ' LPCSTR          lpszCaption    // Dialog caption bar contents
   lpfnHook             AS DWORD       ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData            AS DWORD       ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance            AS DWORD       ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate         AS ASCIIZ PTR  ' LPCSTR          lpszTemplate   // Customized template name
   hResource            AS DWORD       ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUIEDITLINKS.
   lpOleUILinkContainer AS DWORD PTR   ' LPOLEUILINKCONTAINERW lpOleUILinkContainer  // IN: Interface to manipulate
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIEDITLINKS = tagOLEUIEDITLINKSW
#ELSE
   MACRO tagOLEUIEDITLINKS = tagOLEUIEDITLINKSA
#ENDIF

%OLEUI_ELERR_LINKCNTRNULL        = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_ELERR_LINKCNTRINVALID     = %OLEUI_ERR_STANDARDMAX + 1

DECLARE FUNCTION OleUIEditLinksA IMPORT "OLEDLG.DLL" ALIAS "OleUIEditLinksA" ( _
   BYREF lpEL AS tagOLEUIEDITLINKSA _                   ' __in LPOLEUIEDITLINKSA lpEL
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIEditLinksW IMPORT "OLEDLG.DLL" ALIAS "OleUIEditLinksW" ( _
   BYREF lpEL AS tagOLEUIEDITLINKSW _                   ' __in LPOLEUIEDITLINKSW lpEL
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIEditLinks = OleUIEditLinksW
#ELSE
   MACRO OleUIEditLinks = OleUIEditLinksA
#ENDIF

'// Edit Links flags
%ELF_SHOWHELP                    = &H00000001???
%ELF_DISABLEUPDATENOW            = &H00000002???
%ELF_DISABLEOPENSOURCE           = &H00000004???
%ELF_DISABLECHANGESOURCE         = &H00000008???
%ELF_DISABLECANCELLINK           = &H00000010???

'/////////////////////////////////////////////////////////////////////////////
'// CHANGE ICON DIALOG

' // Size = 580 bytes
TYPE tagOLEUICHANGEICONW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct     AS DWORD                  ' DWORD           cbStruct       // Structure Size
   dwFlags      AS DWORD                  ' DWORD           dwFlags        // IN-OUT:  Flags
   hWndOwner    AS DWORD                  ' HWND            hWndOwner      // Owning window
   lpszCaption  AS WSTRINGZ PTR           ' LPCWSTR         lpszCaption    // Dialog caption bar contents
   lpfnHook     AS DWORD                  ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData    AS DWORD                  ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance    AS DWORD                  ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate AS WSTRINGZ PTR           ' LPCWSTR         lpszTemplate   // Customized template name
   hResource    AS DWORD                  ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUICHANGEICONW.
   hMetaPict    AS DWORD                  ' HGLOBAL         hMetaPict      // IN-OUT: Current and final image.
                                          '                                //  Source of the icon is embedded in
                                          '                                //  the metafile itself.
   clsid        AS GUID                   ' CLSID           clsid          // IN: class used to get Default icon
   szIconExe    AS WSTRINGZ * %MAX_PATH   ' WCHAR           szIconExe[MAX_PATH]    // IN: explicit icon source path
   cchIconExe   AS LONG                   ' int             cchIconExe     // IN: number of characters in szIconExe
END TYPE

' // Size = 320 bytes
TYPE tagOLEUICHANGEICONA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct     AS DWORD                ' DWORD           cbStruct       // Structure Size
   dwFlags      AS DWORD                ' DWORD           dwFlags        // IN-OUT:  Flags
   hWndOwner    AS DWORD                ' HWND            hWndOwner      // Owning window
   lpszCaption  AS ASCIIZ PTR           ' LPCSTR          lpszCaption    // Dialog caption bar contents
   lpfnHook     AS DWORD                ' LPFNOLEUIHOOK   lpfnHook       // Hook callback
   lCustData    AS DWORD                ' LPARAM          lCustData      // Custom data to pass to hook
   hInstance    AS DWORD                ' HINSTANCE       hInstance      // Instance for customized template name
   lpszTemplate AS ASCIIZ PTR           ' LPCSTR          lpszTemplate   // Customized template name
   hResource    AS DWORD                ' HRSRC           hResource      // Customized template handle
   ' // Specifics for tagOLEUICHANGEICONW.
   hMetaPict    AS DWORD                ' HGLOBAL         hMetaPict      // IN-OUT: Current and final image.
                                        '                                //  Source of the icon is embedded in
                                        '                                //  the metafile itself.
   clsid        AS GUID                 ' CLSID           clsid          // IN: class used to get Default icon
   szIconExe    AS ASCIIZ * %MAX_PATH   ' char    szIconExe[MAX_PATH]    // IN: explicit icon source path
   cchIconExe   AS LONG                 ' int             cchIconExe     // IN: number of characters in szIconExe
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUICHANGEICON = tagOLEUICHANGEICONW
#ELSE
   MACRO tagOLEUICHANGEICON = tagOLEUICHANGEICONA
#ENDIF

DECLARE FUNCTION OleUIChangeIconA IMPORT "OLEDLG.DLL" ALIAS "OleUIChangeIconA" ( _
   BYREF lpCI AS tagOLEUICHANGEICONA _                  ' __in LPOLEUICHANGEICONA lpCI
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIChangeIconW IMPORT "OLEDLG.DLL" ALIAS "OleUIChangeIconW" ( _
   BYREF lpCI AS tagOLEUICHANGEICONW _                  ' __in LPOLEUICHANGEICONW lpCI
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIChangeIcon = OleUIChangeIconW
#ELSE
   MACRO OleUIChangeIcon = OleUIChangeIconA
#ENDIF

'// Change Icon flags
%CIF_SHOWHELP                    = &H00000001???
%CIF_SELECTCURRENT               = &H00000002???
%CIF_SELECTDEFAULT               = &H00000004???
%CIF_SELECTFROMFILE              = &H00000008???
%CIF_USEICONEXE                  = &H00000010???

'// Change Icon specific error codes
%OLEUI_CIERR_MUSTHAVECLSID           = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_CIERR_MUSTHAVECURRENTMETAFILE = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_CIERR_SZICONEXEINVALID        = %OLEUI_ERR_STANDARDMAX + 2

'// Property used by ChangeIcon dialog to give its parent window access to
'// its hDlg. The PasteSpecial dialog may need to force the ChgIcon dialog
'// down if the clipboard contents change underneath it. if so it will send
'// a IDCANCEL command to the ChangeIcon dialog.
'#define PROP_HWND_CHGICONDLG    TEXT("HWND_CIDLG")
$PROP_HWND_CHGICONDLG    = "HWND_CIDLG"

'/////////////////////////////////////////////////////////////////////////////
'// CONVERT DIALOG

' // Size = 136 bytes
TYPE tagOLEUICONVERTW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct              AS DWORD          ' DWORD           cbStruct;       // Structure Size
   dwFlags               AS DWORD          ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner             AS DWORD          ' HWND            hWndOwner;      // Owning window
   lpszCaption           AS WSTRINGZ PTR   ' LPCWSTR         lpszCaption;    // Dialog caption bar contents
   lpfnHook              AS DWORD          ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData             AS DWORD          ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance             AS DWORD          ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate          AS WSTRINGZ PTR   ' LPCWSTR         lpszTemplate;   // Customized template name
   hResource             AS DWORD          ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUICONVERTW.
   clsid                 AS GUID           ' CLSID           clsid;          // IN: Class ID sent in to dialog: IN only
   clsidConvertDefault   AS GUID           ' CLSID           clsidConvertDefault;    // IN: use as convert default: IN only
   clsidActivateDefault  AS GUID           ' CLSID           clsidActivateDefault;   // IN: use as activate default: IN only
   clsidNew              AS GUID           ' CLSID           clsidNew;       // OUT: Selected Class ID
   dvAspect              AS DWORD          ' DWORD           dvAspect;       // IN-OUT: either DVASPECT_CONTENT or DVASPECT_ICON
   wFormat               AS WORD           ' WORD            wFormat;        // IN" Original data format
   wFiller               AS WORD
   fIsLinkedObject       AS LONG           ' BOOL            fIsLinkedObject;// IN: true if object is linked
   hMetaPict             AS DWORD          ' HGLOBAL         hMetaPict;      // IN-OUT: metafile icon image
   lpszUserType          AS WSTRINGZ PTR   ' LPWSTR          lpszUserType;   // IN-OUT: user type name of original class.
                                           '                                 //      We'll do lookup if NULL.
                                           '                                 //      This gets freed on exit.
   fObjectsIconChanged   AS LONG           ' BOOL            fObjectsIconChanged; // OUT: TRUE == ChangeIcon was called
   lpszDefLabel          AS WSTRINGZ PTR   ' LPWSTR          lpszDefLabel;   // IN-OUT: default label to use for icon.
                                           '                                 //  if NULL, the short user type name
                                           '                                 //  will be used. if the object is a
                                           '                                 //  link, the caller should pass the
                                           '                                 //  DisplayName of the link source
                                           '                                 //  This gets freed on exit.
   cClsidExclude         AS DWORD          ' UINT            cClsidExclude;  //IN: No. of CLSIDs in lpClsidExclude
   lpClsidExclude        AS GUID PTR       ' LPCLSID         lpClsidExclude; //IN: List of CLSIDs to exclude from list
END TYPE

' // Size = 136 bytes
TYPE tagOLEUICONVERTA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct              AS DWORD        ' DWORD           cbStruct;       // Structure Size
   dwFlags               AS DWORD        ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner             AS DWORD        ' HWND            hWndOwner;      // Owning window
   lpszCaption           AS ASCIIZ PTR   ' LPCSTR          lpszCaption;    // Dialog caption bar contents
   lpfnHook              AS DWORD        ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData             AS DWORD        ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance             AS DWORD        ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate          AS ASCIIZ PTR   ' LPCSTR          lpszTemplate;   // Customized template name
   hResource             AS DWORD        ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUICONVERTW.
   clsid                 AS GUID         ' CLSID           clsid;          // IN: Class ID sent in to dialog: IN only
   clsidConvertDefault   AS GUID         ' CLSID           clsidConvertDefault;    // IN: use as convert default: IN only
   clsidActivateDefault  AS GUID         ' CLSID           clsidActivateDefault;   // IN: use as activate default: IN only
   clsidNew              AS GUID         ' CLSID           clsidNew;       // OUT: Selected Class ID
   dvAspect              AS DWORD        ' DWORD           dvAspect;       // IN-OUT: either DVASPECT_CONTENT or DVASPECT_ICON
   wFormat               AS WORD         ' WORD            wFormat;        // IN" Original data format
   wFiller               AS WORD
   fIsLinkedObject       AS LONG         ' BOOL            fIsLinkedObject;// IN: true if object is linked
   hMetaPict             AS DWORD        ' HGLOBAL         hMetaPict;      // IN-OUT: metafile icon image
   lpszUserType          AS ASCIIZ PTR   ' LPSTR           lpszUserType;   // IN-OUT: user type name of original class.
                                         '                                 //      We'll do lookup if NULL.
                                         '                                 //      This gets freed on exit.
   fObjectsIconChanged   AS LONG         ' BOOL            fObjectsIconChanged; // OUT: TRUE == ChangeIcon was called
   lpszDefLabel          AS ASCIIZ PTR   ' LPSTR           lpszDefLabel;   // IN-OUT: default label to use for icon.
                                         '                                 //  if NULL, the short user type name
                                         '                                 //  will be used. if the object is a
                                         '                                 //  link, the caller should pass the
                                         '                                 //  DisplayName of the link source
                                         '                                 //  This gets freed on exit.
   cClsidExclude         AS DWORD        ' UINT            cClsidExclude;  //IN: No. of CLSIDs in lpClsidExclude
   lpClsidExclude        AS GUID PTR     ' LPCLSID         lpClsidExclude; //IN: List of CLSIDs to exclude from list
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUICONVERT = tagOLEUICONVERTW
#ELSE
   MACRO tagOLEUICONVERT = tagOLEUICONVERTA
#ENDIF

DECLARE FUNCTION OleUIConvertA IMPORT "OLEDLG.DLL" ALIAS "OleUIConvertA" ( _
   BYREF lpCV AS tagOLEUICONVERTA _                     ' __in LPOLEUICONVERTA lpCV
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIConvertW IMPORT "OLEDLG.DLL" ALIAS "OleUIConvertW" ( _
   BYREF lpCV AS tagOLEUICONVERTW _                     ' __in LPOLEUICONVERTW lpCV
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIConvert = OleUIConvertW
#ELSE
   MACRO OleUIConvert = OleUIConvertA
#ENDIF

'// Determine if there is at least one class that can Convert or ActivateAs
'// the given clsid.
DECLARE FUNCTION OleUICanConvertOrActivateAs IMPORT "OLEDLG.DLL" ALIAS "OleUICanConvertOrActivateAs" ( _
   BYREF rClsid AS GUID _                               ' __in REFCLSID rClsid
 , BYVAL fIsLinkedObject AS LONG _                      ' __in BOOL fIsLinkedObject
 , BYVAL wFormat AS WORD _                              ' __in WORD wFormat
 ) AS LONG                                              ' BOOL

'// Convert Dialog flags
%CF_SHOWHELPBUTTON               = &H00000001???
%CF_SETCONVERTDEFAULT            = &H00000002???
%CF_SETACTIVATEDEFAULT           = &H00000004???
%CF_SELECTCONVERTTO              = &H00000008???
%CF_SELECTACTIVATEAS             = &H00000010???
%CF_DISABLEDISPLAYASICON         = &H00000020???
%CF_DISABLEACTIVATEAS            = &H00000040???
%CF_HIDECHANGEICON               = &H00000080???
%CF_CONVERTONLY                  = &H00000100???

'// Convert specific error codes
%OLEUI_CTERR_CLASSIDINVALID      = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_CTERR_DVASPECTINVALID     = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_CTERR_CBFORMATINVALID     = %OLEUI_ERR_STANDARDMAX + 3
%OLEUI_CTERR_HMETAPICTINVALID    = %OLEUI_ERR_STANDARDMAX + 4
%OLEUI_CTERR_STRINGINVALID       = %OLEUI_ERR_STANDARDMAX + 5

'/////////////////////////////////////////////////////////////////////////////
'// BUSY DIALOG

' // Size = 44 bytes
TYPE tagOLEUIBUSYW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct     AS DWORD          ' DWORD           cbStruct;       // Structure Size
   dwFlags      AS DWORD          ' DWORD           dwFlags;        // IN-OUT: see below
   hWndOwner    AS DWORD          ' HWND            hWndOwner;      // Owning window
   lpszCaption  AS WSTRINGZ PTR   ' LPCWSTR         lpszCaption;    // Dialog caption bar contents
   lpfnHook     AS DWORD          ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData    AS DWORD          ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance    AS DWORD          ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate AS WSTRINGZ PTR   ' LPCWSTR         lpszTemplate;   // Customized template name
   hResource    AS DWORD          ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUIBUSY.
   hTask        AS DWORD          ' HTASK           hTask;          // IN: HTask which is blocking
   lphWndDialog AS DWORD          ' HWND *          lphWndDialog;   // OUT: Dialog's HWND is placed here
END TYPE

' // Size = 44 bytes
TYPE tagOLEUIBUSYA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct     AS DWORD        ' DWORD           cbStruct;       // Structure Size
   dwFlags      AS DWORD        ' DWORD           dwFlags;        // IN-OUT: see below
   hWndOwner    AS DWORD        ' HWND            hWndOwner;      // Owning window
   lpszCaption  AS ASCIIZ PTR   ' LPCSTR          lpszCaption;    // Dialog caption bar contents
   lpfnHook     AS DWORD        ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData    AS DWORD        ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance    AS DWORD        ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate AS ASCIIZ PTR   ' LPCSTR          lpszTemplate;   // Customized template name
   hResource    AS DWORD        ' HRSRC           hResource;      // Customized template handle
   ' // Specifics for tagOLEUIBUSY.
   hTask        AS DWORD        ' HTASK           hTask;          // IN: HTask which is blocking
   lphWndDialog AS DWORD        ' HWND *          lphWndDialog;   // OUT: Dialog's HWND is placed here
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIBUSY = tagOLEUIBUSYW
#ELSE
   MACRO tagOLEUIBUSY = tagOLEUIBUSYA
#ENDIF

DECLARE FUNCTION OleUIBusyA IMPORT "OLEDLG.DLL" ALIAS "OleUIBusyA" ( _
   BYREF lpBZ AS tagOLEUIBUSYA _                        ' __in LPOLEUIBUSYA  lpBZ
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIBusyW IMPORT "OLEDLG.DLL" ALIAS "OleUIBusyW" ( _
   BYREF lpBZ AS tagOLEUIBUSYW _                        ' __in LPOLEUIBUSYW  lpBZ
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIBusy = OleUIBusyW
#ELSE
   MACRO OleUIBusy = OleUIBusyA
#ENDIF

'// Flags for the Busy dialog
%BZ_DISABLECANCELBUTTON          = &H00000001???
%BZ_DISABLESWITCHTOBUTTON        = &H00000002???
%BZ_DISABLERETRYBUTTON           = &H00000004???

%BZ_NOTRESPONDINGDIALOG          = &H00000008???

'// Busy specific error/return codes
%OLEUI_BZERR_HTASKINVALID     = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_BZ_SWITCHTOSELECTED    = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_BZ_RETRYSELECTED       = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_BZ_CALLUNBLOCKED       = %OLEUI_ERR_STANDARDMAX + 3

'/////////////////////////////////////////////////////////////////////////////
'// CHANGE SOURCE DIALOG

'// Data to and from the ChangeSource dialog hook
' // Size = 80 bytes
TYPE tagOLEUICHANGESOURCEW
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct             AS DWORD          ' DWORD           cbStruct;       // Structure Size
   dwFlags              AS DWORD          ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner            AS DWORD          ' HWND            hWndOwner;      // Owning window
   lpszCaption          AS WSTRINGZ PTR   ' LPCWSTR         lpszCaption;    // Dialog caption bar contents
   lpfnHook             AS DWORD          ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData            AS DWORD          ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance            AS DWORD          ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate         AS WSTRINGZ PTR   ' LPCWSTR         lpszTemplate;   // Customized template name
   hResource            AS DWORD          ' HRSRC           hResource;      // Customized template handle
   ' // INTERNAL ONLY: do not modify these members
   lpOFN                AS OPENFILENAMEW PTR   ' OPENFILENAMEW*  lpOFN;          // pointer OPENFILENAME struct
   dwReserved1(3)       AS DWORD          ' DWORD           dwReserved1[4]; // (reserved for future use)
   ' // Specifics for tagOLEUICHANGESOURCE.
   lpOleUILinkContainer AS DWORD PTR      ' LPOLEUILINKCONTAINERA lpOleUILinkContainer;  // IN: used to validate link sources
   dwLink               AS DWORD          ' DWORD           dwLink;         // IN: magic# for lpOleUILinkContainer
   lpszDisplayName      AS WSTRINGZ PTR   ' LPWSTR          lpszDisplayName;// IN-OUT: complete source display name
   nFileLength          AS DWORD          ' ULONG           nFileLength;    // IN-OUT: file moniker part of lpszDisplayName
   lpszFrom             AS WSTRINGZ PTR   ' LPWSTR          lpszFrom;       // OUT: prefix of source changed from
   lpszTo               AS WSTRINGZ PTR   ' LPWSTR          lpszTo;         // OUT: prefix of source changed to
END TYPE

' // Size = 80 bytes
TYPE tagOLEUICHANGESOURCEA
   ' // These IN fields are standard across all OLEUI dialog box functions.
   cbStruct             AS DWORD        ' DWORD           cbStruct;       // Structure Size
   dwFlags              AS DWORD        ' DWORD           dwFlags;        // IN-OUT:  Flags
   hWndOwner            AS DWORD        ' HWND            hWndOwner;      // Owning window
   lpszCaption          AS ASCIIZ PTR   ' LPCSTR          lpszCaption;    // Dialog caption bar contents
   lpfnHook             AS DWORD        ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData            AS DWORD        ' LPARAM          lCustData;      // Custom data to pass to hook
   hInstance            AS DWORD        ' HINSTANCE       hInstance;      // Instance for customized template name
   lpszTemplate         AS ASCIIZ PTR   ' LPCSTR          lpszTemplate;   // Customized template name
   hResource            AS DWORD        ' HRSRC           hResource;      // Customized template handle
   ' // INTERNAL ONLY: do not modify these members
   lpOFN                AS OPENFILENAME PTR   ' OPENFILENAMEA*  lpOFN;          // pointer OPENFILENAME struct
   dwReserved1(3)       AS DWORD        ' DWORD           dwReserved1[4]; // (reserved for future use)
   ' // Specifics for tagOLEUICHANGESOURCE.
   lpOleUILinkContainer AS DWORD PTR    ' LPOLEUILINKCONTAINERA lpOleUILinkContainer;  // IN: used to validate link sources
   dwLink               AS DWORD        ' DWORD           dwLink;         // IN: magic# for lpOleUILinkContainer
   lpszDisplayName      AS ASCIIZ PTR   ' LPSTR           lpszDisplayName;// IN-OUT: complete source display name
   nFileLength          AS DWORD        ' ULONG           nFileLength;    // IN-OUT: file moniker part of lpszDisplayName
   lpszFrom             AS ASCIIZ PTR   ' LPSTR           lpszFrom;       // OUT: prefix of source changed from
   lpszTo               AS ASCIIZ PTR   ' LPSTR           lpszTo;         // OUT: prefix of source changed to
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUICHANGESOURCE = tagOLEUICHANGESOURCEW
#ELSE
   MACRO tagOLEUICHANGESOURCE = tagOLEUICHANGESOURCEA
#ENDIF

DECLARE FUNCTION OleUIChangeSourceA IMPORT "OLEDLG.DLL" ALIAS "OleUIChangeSourceA" ( _
   BYREF lpCS AS tagOLEUICHANGESOURCEA _                ' __in LPOLEUICHANGESOURCEA lpCS
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIChangeSourceW IMPORT "OLEDLG.DLL" ALIAS "OleUIChangeSourceW" ( _
   BYREF lpCS AS tagOLEUICHANGESOURCEW _                ' __in LPOLEUICHANGESOURCEW lpCS
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIChangeSource = OleUIChangeSourceW
#ELSE
   MACRO OleUIChangeSource = OleUIChangeSourceA
#ENDIF

'// Change Source Dialog flags
%CSF_SHOWHELP                    = &H00000001???  ' // IN: enable/show help button
%CSF_VALIDSOURCE                 = &H00000002???  ' // OUT: link was validated
%CSF_ONLYGETSOURCE               = &H00000004???  ' // IN: disables validation of source
%CSF_EXPLORER                    = &H00000008???  ' // IN: use new OFN_EXPLORER custom template behavior

'// Change Source Dialog errors
%OLEUI_CSERR_LINKCNTRNULL        = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_CSERR_LINKCNTRINVALID     = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_CSERR_FROMNOTNULL         = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_CSERR_TONOTNULL           = %OLEUI_ERR_STANDARDMAX + 3
%OLEUI_CSERR_SOURCENULL          = %OLEUI_ERR_STANDARDMAX + 4
%OLEUI_CSERR_SOURCEINVALID       = %OLEUI_ERR_STANDARDMAX + 5
%OLEUI_CSERR_SOURCEPARSERROR     = %OLEUI_ERR_STANDARDMAX + 6
%OLEUI_CSERR_SOURCEPARSEERROR    = %OLEUI_ERR_STANDARDMAX + 6

'/////////////////////////////////////////////////////////////////////////////
'// OBJECT PROPERTIES DIALOG

' ########################################################################################
' IOleUIObjInfoW interface
' Inherited interface = IUnknown
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUIObjInfoW $IID_IOleUIObjInfoW

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetObjectInfo ( _                             ' VTable offset = 12
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF lpdwObjSize AS DWORD _                       ' __out DWORD FAR* lpdwObjSize
'   , BYREF lplpszLabel AS WSTRINGZ _                    ' __out_opt LPWSTR FAR* lplpszLabel
'   , BYREF lplpszType AS WSTRINGZ _                     ' __out_opt LPWSTR FAR* lplpszType
'   , BYREF lplpszShortType AS WSTRINGZ _                ' __out_opt LPWSTR FAR* lplpszShortType
'   , BYREF lplpszLocation AS WSTRINGZ _                 ' __out_opt LPWSTR FAR* lplpszLocation
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetConvertInfo ( _                            ' VTable offset = 16
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF lpClassID AS GUID _                          ' __out CLSID FAR* lpClassID
'   , BYREF lpwFormat AS WORD _                          ' __out WORD FAR* lpwFormat
'   , BYREF lpConvertDefaultClassID AS GUID _            ' __out CLSID FAR* lpConvertDefaultClassID
'   , BYREF lplpClsidExclude AS GUID _                   ' __out LPCLSID FAR* lplpClsidExclude
'   , BYREF lpcClsidExclude AS DWORD _                   ' __out UINT FAR* lpcClsidExclude
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD ConvertObject ( _                             ' VTable offset = 20
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF clsidNew AS GUID _                           ' __in REFCLSID clsidNew
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetViewInfo ( _                               ' VTable offset = 24
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF phMetaPict AS DWORD _                        ' __in_opt HGLOBAL FAR* phMetaPict
'   , BYREF pdvAspect AS DWORD _                         ' __in_opt DWORD* pdvAspect
'   , BYREF pnCurrentScale AS LONG ¨_                    ' __in_opt int* pnCurrentScale
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetViewInfo ( _                               ' VTable offset = 28
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYVAL hMetaPict AS DWORD _                         ' __in HGLOBAL hMetaPict
'   , BYVAL dvAspect AS DWORD _                          ' __in DWORD dvAspect
'   , BYVAL nCurrentScale AS LONG ¨_                     ' __in int nCurrentScale
'   , BYVAL bRelativeToOrig AS LONG _                    ' __in BOOL bRelativeToOrig
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IOleUIObjInfoA interface
' Inherited interface = IUnknown
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUIObjInfoA $IID_IOleUIObjInfoA

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD GetObjectInfo ( _                             ' VTable offset = 12
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF lpdwObjSize AS DWORD _                       ' __out DWORD FAR* lpdwObjSize
'   , BYREF lplpszLabel AS ASCIIZ _                      ' __out_opt LPSTR FAR* lplpszLabel
'   , BYREF lplpszType AS ASCIIZ _                       ' __out_opt LPSTR FAR* lplpszType
'   , BYREF lplpszShortType AS ASCIIZ _                  ' __out_opt LPSTR FAR* lplpszShortType
'   , BYREF lplpszLocation ASASCIIZ _                    ' __out_opt LPSTR FAR* lplpszLocation
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetConvertInfo ( _                            ' VTable offset = 16
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF lpClassID AS GUID _                          ' __out CLSID FAR* lpClassID
'   , BYREF lpwFormat AS WORD _                          ' __out WORD FAR* lpwFormat
'   , BYREF lpConvertDefaultClassID AS GUID _            ' __out CLSID FAR* lpConvertDefaultClassID
'   , BYREF lplpClsidExclude AS GUID _                   ' __out LPCLSID FAR* lplpClsidExclude
'   , BYREF lpcClsidExclude AS DWORD _                   ' __out UINT FAR* lpcClsidExclude
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD ConvertObject ( _                             ' VTable offset = 20
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF clsidNew AS GUID _                           ' __in REFCLSID clsidNew
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetViewInfo ( _                               ' VTable offset = 24
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYREF phMetaPict AS DWORD _                        ' __in_opt HGLOBAL FAR* phMetaPict
'   , BYREF pdvAspect AS DWORD _                         ' __in_opt DWORD* pdvAspect
'   , BYREF pnCurrentScale AS LONG ¨_                    ' __in_opt int* pnCurrentScale
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetViewInfo ( _                               ' VTable offset = 28
'     BYVAL dwObject AS DWORD _                          ' __in DWORD dwObject
'   , BYVAL hMetaPict AS DWORD _                         ' __in HGLOBAL hMetaPict
'   , BYVAL dvAspect AS DWORD _                          ' __in DWORD dvAspect
'   , BYVAL nCurrentScale AS LONG ¨_                     ' __in int nCurrentScale
'   , BYVAL bRelativeToOrig AS LONG _                    ' __in BOOL bRelativeToOrig
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IOleUILinkInfoW interface
' Inherited interface = IOleUILinkContainerW
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUILinkInfoW $IID_IOleUILinkInfoW

'   INHERIT IUnknown

'   ' =====================================================================================
'   ' IOleUILinkContainerW Methods
'   ' =====================================================================================
'   METHOD GetNextLink ( _                               ' VTable offset = 12
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkUpdateOptions ( _                      ' VTable offset = 16
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL dwUpdateOpt AS DWORD _                       ' __in DWORD dwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkUpdateOptions ( _                      ' VTable offset = 20
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpdwUpdateOpt AS DWORD _                     ' __out DWORD *lpdwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkSource ( _                             ' VTable offset = 24
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpszDisplayName AS WSTRINGZ _                ' __in LPWSTR lpszDisplayName
'   , BYVAL lenFileName AS DWORD _                       ' __in ULONG lenFileName
'   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
'   , BYVAL fValidateSource AS LONG _                    ' __in BOOL fValidateSource
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkSource ( _                             ' VTable offset = 28
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lplpszDisplayName AS DWORD _                 ' __out_opt LPWSTR *lplpszDisplayName
'   , BYREF lplenFileName AS DWORD _                     ' __out ULONG *lplenFileName
'   , BYREF lplpszFullLinkType AS DWORD _                ' __out_opt LPWSTR *lplpszFullLinkType
'   , BYREF lplpszShortLinkType AS DWORD                 ' __out_opt LPWSTR *lplpszShortLinkType
'   , BYREF lpfSourceAvailable AS LONG _                 ' __out BOOL *lpfSourceAvailable
'   , BYREF lpfIsSelected AS LONG _                      ' __out SBOOL *lpfIsSelected
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OpenLinkSource ( _                            ' VTable offset = 32
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateLink ( _                                ' VTable offset = 36
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL fErrorMessage AS LONG _                      ' __in BOOL fErrorMessage
'   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CancelLink ( _                                ' VTable offset = 40
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'   ' =====================================================================================
'   ' IOleUILinkInfoW Methods
'   ' =====================================================================================
'   METHOD GetLastUpdate ( _                             ' VTable offset = 44
'     BYVAL DWORD _                                      ' __in DWORD dwLink
'   , BYREF FILETIME _                                   ' __out FILETIME FAR* lpLastUpdate
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' IOleUILinkInfoA interface
' Inherited interface = IOleUILinkContainerA
' Note: Microsoft doesn't provide a GUID for this interface.
' ########################################################################################

'INTERFACE IOleUILinkInfoA $IID_IOleUILinkInfoA

'   INHERIT IUnknown

'   ' =====================================================================================
'   ' IOleUILinkContainerA Methods
'   ' =====================================================================================
'   METHOD GetNextLink ( _                               ' VTable offset = 12
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkUpdateOptions ( _                      ' VTable offset = 16
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL DWORD _                                      ' __in DWORD dwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkUpdateOptions ( _                      ' VTable offset = 20
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpdwUpdateOpt AS DWORD _                     ' __out DWORD *lpdwUpdateOpt
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetLinkSource ( _                             ' VTable offset = 24
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lpszDisplayName AS ASCIIZ _                  ' __in LPSTR lpszDisplayName
'   , BYVAL lenFileName AS DWORD _                       ' __in ULONG lenFileName
'   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
'   , BYVAL fValidateSource AS LONG _                    ' __in BOOL fValidateSource
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetLinkSource ( _                             ' VTable offset = 28
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYREF lplpszDisplayName AS ASCIIZ _                ' __out_opt LPSTR *lplpszDisplayName
'   , BYREF lplenFileName AS DWORD _                     ' __out ULONG *lplenFileName
'   , BYREF lplpszFullLinkType AS ASCIIZ _               ' __out_opt LPSTR *lplpszFullLinkType
'   , BYREF lplpszShortLinkType AS ASCIIZ _              ' __out_opt LPSTR *lplpszShortLinkType
'   , BYREF lpfSourceAvailable AS LONG _                 ' __out BOOL *lpfSourceAvailable
'   , BYREF lpfIsSelected AS LONG _                      ' __out BOOL *lpfIsSelected
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD OpenLinkSource ( _                            ' VTable offset = 32
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateLink ( _                                ' VTable offset = 36
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   , BYVAL fErrorMessage AS LONG _                      ' __in BOOL fErrorMessage
'   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CancelLink ( _                                ' VTable offset = 40
'     BYVAL dwLink AS DWORD _                            ' __in DWORD dwLink
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'   ' =====================================================================================
'   ' IOleUILinkInfoA Methods
'   ' =====================================================================================
'   METHOD GetLastUpdate ( _                             ' VTable offset = 44
'     BYVAL DWORD _                                      ' __in DWORD dwLink
'   , BYREF FILETIME _                                   ' __out FILETIME FAR* lpLastUpdate
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE


' // Size = 40 bytes
TYPE tagOLEUIGNRLPROPSW
   ' // These IN fields are standard across all OLEUI property pages.
   cbStruct             AS DWORD       ' DWORD           cbStruct;       // Structure Size
   dwFlags              AS DWORD       ' DWORD           dwFlags;        // IN-OUT: flags specific to general page
   dwReserved1(1)       AS DWORD       ' DWORD           dwReserved1[2];
   lpfnHook             AS DWORD PTR   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData            AS LONG        ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)       AS DWORD       ' DWORD           dwReserved2[3];
   lpOP                 AS DWORD       ' struct tagOLEUIOBJECTPROPSW* lpOP;   // (used internally)
END TYPE

' // Size = 40 bytes
TYPE tagOLEUIGNRLPROPSA
   ' // These IN fields are standard across all OLEUI property pages.
   cbStruct             AS DWORD       ' DWORD           cbStruct;       // Structure Size
   dwFlags              AS DWORD       ' DWORD           dwFlags;        // IN-OUT: flags specific to general page
   dwReserved1(1)       AS DWORD       ' DWORD           dwReserved1[2];
   lpfnHook             AS DWORD PTR   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback
   lCustData            AS LONG        ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)       AS DWORD       ' DWORD           dwReserved2[3];
   lpOP                 AS DWORD       ' struct tagOLEUIOBJECTPROPSA* lpOP;   // (used internally)
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIGNRLPROPS = tagOLEUIGNRLPROPSW
#ELSE
   MACRO tagOLEUIGNRLPROPS = tagOLEUIGNRLPROPSA
#ENDIF

' // Size = 48 bytes
TYPE tagOLEUIVIEWPROPSW
   ' // These IN fields are standard across all OLEUI property pages.
   cbStruct            AS DWORD   ' DWORD           cbStruct;       // Structure Size
   dwFlags             AS DWORD   ' DWORD           dwFlags;        // IN-OUT: flags specific to view page
   dwReserved1(1)      AS DWORD   ' DWORD           dwReserved1[2];
   lpfnHook            AS DWORD   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback (not used in this dialog)
   lCustData           AS LONG    ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)      AS DWORD   ' DWORD           dwReserved2[3];
   lpOP                AS DWORD   ' struct tagOLEUIOBJECTPROPSW* lpOP; // (used internally)
   nScaleMin           AS LONG    ' int             nScaleMin;      // scale range
   nScaleMax           AS LONG    ' int             nScaleMax;
END TYPE

' // Size = 48 bytes
TYPE tagOLEUIVIEWPROPSA
   ' // These IN fields are standard across all OLEUI property pages.
   cbStruct            AS DWORD   ' DWORD           cbStruct;       // Structure Size
   dwFlags             AS DWORD   ' DWORD           dwFlags;        // IN-OUT: flags specific to view page
   dwReserved1(1)      AS DWORD   ' DWORD           dwReserved1[2];
   lpfnHook            AS DWORD   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback (not used in this dialog)
   lCustData           AS LONG    ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)      AS DWORD   ' DWORD           dwReserved2[3];
   lpOP                AS DWORD   ' struct tagOLEUIOBJECTPROPSA* lpOP; // (used internally)
   nScaleMin           AS LONG    ' int             nScaleMin;      // scale range
   nScaleMax           AS LONG    ' int             nScaleMax;
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIVIEWPROPS = tagOLEUIVIEWPROPSW
#ELSE
   MACRO tagOLEUIVIEWPROPS = tagOLEUIVIEWPROPSA
#ENDIF

'// Flags for OLEUIVIEWPROPS
%VPF_SELECTRELATIVE          = &H00000001???  ' // IN: relative to orig
%VPF_DISABLERELATIVE         = &H00000002???  ' // IN: disable relative to orig
%VPF_DISABLESCALE            = &H00000004???  ' // IN: disable scale option

' // Size = 40 bytes
TYPE tagOLEUILINKPROPSW
   ' // These IN fields are standard across all OLEUI property pages.
   cbStruct             AS DWORD       ' DWORD           cbStruct;       // Structure Size
   dwFlags              AS DWORD       ' DWORD           dwFlags;        // IN-OUT: flags specific to links page
   dwReserved1(1)       AS DWORD       ' DWORD           dwReserved1[2];
   lpfnHook             AS DWORD PTR   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback (not used in this dialog)
   lCustData            AS LONG        ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)       AS DWORD       ' DWORD           dwReserved2[3];
   lpOP                 AS DWORD       ' struct tagOLEUIOBJECTPROPSW* lpOP; // (used internally)
END TYPE

' // Size = 40 bytes
TYPE tagOLEUILINKPROPSA
   cbStruct             AS DWORD       ' DWORD           cbStruct;       // Structure Size
   ' // These IN fields are standard across all OLEUI property pages.
   dwFlags              AS DWORD       ' DWORD           dwFlags;        // IN-OUT: flags specific to links page
   dwReserved1(1)       AS DWORD       ' DWORD           dwReserved1[2];
   lpfnHook             AS DWORD PTR   ' LPFNOLEUIHOOK   lpfnHook;       // Hook callback (not used in this dialog)
   lCustData            AS LONG        ' LPARAM          lCustData;      // Custom data to pass to hook
   dwReserved2(2)       AS DWORD       ' DWORD           dwReserved2[3];
   lpOP                 AS DWORD       ' struct tagOLEUIOBJECTPROPSA* lpOP; // (used internally)
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUILINKPROPS = tagOLEUILINKPROPSW
#ELSE
   MACRO tagOLEUILINKPROPS = tagOLEUILINKPROPSA
#ENDIF

#INCLUDE ONCE "prsht.inc

' // Size = 40 bytes
TYPE tagOLEUIOBJECTPROPSW
   ' // These IN fields are standard across all OLEUI property sheets.
   cbStruct   AS DWORD                  ' DWORD           cbStruct;       // Structure Size
   dwFlags    AS DWORD                  ' DWORD           dwFlags;        // IN-OUT: global flags for the sheet
   ' // Standard PROPSHEETHEADER used for extensibility
   lpPS       AS PROPSHEETHEADERW PTR   ' LPPROPSHEETHEADERW   lpPS;         // IN: property sheet header
   ' // Data which allows manipulation of the object
   dwObject   AS DWORD                  ' DWORD           dwObject;       // IN: identifier for the object
   lpObjInfo  AS DWORD PTR              ' LPOLEUIOBJINFOW lpObjInfo;      // IN: interface to manipulate object
   ' // Data which allows manipulation of the link
   dwLink     AS DWORD                  ' DWORD           dwLink;         // IN: identifier for the link
   lpLinkInfo AS DWORD PTR              ' LPOLEUILINKINFOW lpLinkInfo;     // IN: interface to manipulate link
   ' // Data specific to each page
   lpGP       AS tagOLEUIGNRLPROPSW PTR ' LPOLEUIGNRLPROPSW lpGP;          // IN: general page
   lpVP       AS tagOLEUIVIEWPROPSW PTR ' LPOLEUIVIEWPROPSW lpVP;          // IN: view page
   lpLP       AS tagOLEUILINKPROPSW PTR ' LPOLEUILINKPROPSW lpLP;          // IN: link page
END TYPE

' // Size = 40 bytes
TYPE tagOLEUIOBJECTPROPSA
   ' // These IN fields are standard across all OLEUI property sheets.
   cbStruct   AS DWORD                  ' DWORD           cbStruct;       // Structure Size
   dwFlags    AS DWORD                  ' DWORD           dwFlags;        // IN-OUT: global flags for the sheet
   ' // Standard PROPSHEETHEADER used for extensibility
   lpPS       AS PROPSHEETHEADERA PTR   ' LPPROPSHEETHEADERA   lpPS;         // IN: property sheet header
   ' // Data which allows manipulation of the object
   dwObject   AS DWORD                  ' DWORD           dwObject;       // IN: identifier for the object
   lpObjInfo  AS DWORD PTR              ' LPOLEUIOBJINFOA lpObjInfo;      // IN: interface to manipulate object
   ' // Data which allows manipulation of the link
   dwLink     AS DWORD                  ' DWORD           dwLink;         // IN: identifier for the link
   lpLinkInfo AS DWORD PTR              ' LPOLEUILINKINFOA lpLinkInfo;     // IN: interface to manipulate link
   ' // Data specific to each page
   lpGP       AS tagOLEUIGNRLPROPSA PTR ' LPOLEUIGNRLPROPSA lpGP;          // IN: general page
   lpVP       AS tagOLEUIVIEWPROPSA PTR ' LPOLEUIVIEWPROPSA lpVP;          // IN: view page
   lpLP       AS tagOLEUILINKPROPSA PTR ' LPOLEUILINKPROPSA lpLP;          // IN: link page
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagOLEUIOBJECTPROPS = tagOLEUIOBJECTPROPSW
#ELSE
   MACRO tagOLEUIOBJECTPROPS = tagOLEUIOBJECTPROPSA
#ENDIF

DECLARE FUNCTION OleUIObjectPropertiesA IMPORT "OLEDLG.DLL" ALIAS "OleUIObjectPropertiesA" ( _
   BYREF lpOP AS tagOLEUIOBJECTPROPSA _                 ' __in LPOLEUIOBJECTPROPSA lpOP
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION OleUIObjectPropertiesW IMPORT "OLEDLG.DLL" ALIAS "OleUIObjectPropertiesW" ( _
   BYREF lpOP AS tagOLEUIOBJECTPROPSW _                 ' __in LPOLEUIOBJECTPROPSW lpOP
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO OleUIObjectProperties = OleUIObjectPropertiesW
#ELSE
   MACRO OleUIObjectProperties = OleUIObjectPropertiesA
#ENDIF

'// Flags for OLEUIOBJECTPROPS
%OPF_OBJECTISLINK                = &H00000001???
%OPF_NOFILLDEFAULT               = &H00000002???
%OPF_SHOWHELP                    = &H00000004???
%OPF_DISABLECONVERT              = &H00000008???

'' // Errors for OleUIObjectProperties
%OLEUI_OPERR_SUBPROPNULL           = %OLEUI_ERR_STANDARDMAX + 0
%OLEUI_OPERR_SUBPROPINVALID        = %OLEUI_ERR_STANDARDMAX + 1
%OLEUI_OPERR_PROPSHEETNULL         = %OLEUI_ERR_STANDARDMAX + 2
%OLEUI_OPERR_PROPSHEETINVALID      = %OLEUI_ERR_STANDARDMAX + 3
%OLEUI_OPERR_SUPPROP               = %OLEUI_ERR_STANDARDMAX + 4
%OLEUI_OPERR_PROPSINVALID          = %OLEUI_ERR_STANDARDMAX + 5
%OLEUI_OPERR_PAGESINCORRECT        = %OLEUI_ERR_STANDARDMAX + 6
%OLEUI_OPERR_INVALIDPAGES          = %OLEUI_ERR_STANDARDMAX + 7
%OLEUI_OPERR_NOTSUPPORTED          = %OLEUI_ERR_STANDARDMAX + 8
%OLEUI_OPERR_DLGPROCNOTNULL        = %OLEUI_ERR_STANDARDMAX + 9
%OLEUI_OPERR_LPARAMNOTZERO         = %OLEUI_ERR_STANDARDMAX + 10

%OLEUI_GPERR_STRINGINVALID         = %OLEUI_ERR_STANDARDMAX + 11
%OLEUI_GPERR_CLASSIDINVALID        = %OLEUI_ERR_STANDARDMAX + 12
%OLEUI_GPERR_LPCLSIDEXCLUDEINVALID = %OLEUI_ERR_STANDARDMAX + 13
%OLEUI_GPERR_CBFORMATINVALID       = %OLEUI_ERR_STANDARDMAX + 14
%OLEUI_VPERR_METAPICTINVALID       = %OLEUI_ERR_STANDARDMAX + 15
%OLEUI_VPERR_DVASPECTINVALID       = %OLEUI_ERR_STANDARDMAX + 16
%OLEUI_LPERR_LINKCNTRNULL          = %OLEUI_ERR_STANDARDMAX + 17
%OLEUI_LPERR_LINKCNTRINVALID       = %OLEUI_ERR_STANDARDMAX + 18

%OLEUI_OPERR_PROPERTYSHEET         = %OLEUI_ERR_STANDARDMAX + 19
%OLEUI_OPERR_OBJINFOINVALID        = %OLEUI_ERR_STANDARDMAX + 20
%OLEUI_OPERR_LINKINFOINVALID       = %OLEUI_ERR_STANDARDMAX + 21

'' // wParam used by PSM_QUERYSIBLINGS
%OLEUI_QUERY_GETCLASSID          = &HFF00???  ' // override class id for icon
%OLEUI_QUERY_LINKBROKEN          = &HFF01???  ' // after link broken

'/////////////////////////////////////////////////////////////////////////////
'// PROMPT USER DIALOGS

'int __cdecl OleUIPromptUserW(int nTemplate, HWND hwndParent, ...);
'int __cdecl OleUIPromptUserA(int nTemplate, HWND hwndParent, ...);

DECLARE FUNCTION OleUIPromptUserA CDECL IMPORT "OLEDLG.DLL" ALIAS "OleUIPromptUserA" ( _
   BYVAL nTemplate AS LONG _                            ' __in int nTemplate
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

DECLARE FUNCTION OleUIPromptUserW CDECL IMPORT "OLEDLG.DLL" ALIAS "OleUIPromptUserW" ( _
   BYVAL nTemplate AS LONG _                            ' __in int nTemplate
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO OleUIPromptUser = OleUIPromptUserW
#ELSE
   MACRO OleUIPromptUser = OleUIPromptUserA
#ENDIF

DECLARE FUNCTION OleUIUpdateLinksA IMPORT "OLEDLG.DLL" ALIAS "OleUIUpdateLinksA" ( _
   BYVAL lpOleUILinkCntr AS IUnknown _                  ' __in LPOLEUILINKCONTAINERA lpOleUILinkCntr
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF lpszTitle AS ASCIIZ _                          ' __in LPSTR lpszTitle
 , BYVAL cLinks AS LONG _                               ' __in int cLinks
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION OleUIUpdateLinksW IMPORT "OLEDLG.DLL" ALIAS "OleUIUpdateLinksW" ( _
   BYVAL lpOleUILinkCntr AS IUnknown _                  ' __in LPOLEUILINKCONTAINERW lpOleUILinkCntr
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF lpszTitle AS WSTRINGZ _                        ' __in LPWSTR lpszTitle
 , BYVAL cLinks AS LONG _                               ' __in int cLinks
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO OleUIUpdateLinks = OleUIUpdateLinksW
#ELSE
   MACRO OleUIUpdateLinks = OleUIUpdateLinksA
#ENDIF

'/////////////////////////////////////////////////////////////////////////////

'#pragma pack(pop)

'/////////////////////////////////////////////////////////////////////////////
