' ########################################################################################
' Microsoft Windows
' File: DocObj.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DOCOBJ_INC = 1

%DOCOBJ_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"

'//--------------------------------------------------------------------------
'// OLE Document Object Interfaces.

'////////////////////////////////////////////////////////////////////////////
'//  Interface Definitions

' ########################################################################################
' IOleDocument interface
' IID = b722bcc5-4e68-101b-a2bc-00aa00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleDocument_INTERFACE_DEFINED)
    %IOleDocument_INTERFACE_DEFINED = 1

' DOCMISC enum
%DOCMISC_CANCREATEMULTIPLEVIEWS   = 1
%DOCMISC_SUPPORTCOMPLEXRECTANGLES = 2
%DOCMISC_CANTOPENEDIT             = 4
%DOCMISC_NOFILESUPPORT            = 8

$IID_IOleDocument = GUID$("{B722BCC5-4E68-101B-A2BC-00AA00404770}")
$IID_IMsoDocument = $IID_IOleDocument

INTERFACE IOleDocument $IID_IOleDocument

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateView ( _                                ' VTable offset = 12
     BYVAL pIPSite AS IOleInPlaceSite _                 ' __in IOleInPlaceSite *pIPSite
   , BYVAL pstm AS IStream _                            ' __in IStream *pstm
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF ppView AS IOleDocumentView _                 ' __out IOleDocumentView **ppView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocMiscStatus ( _                          ' VTable offset = 16
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumViews ( _                                 ' VTable offset = 20
     BYREF ppEnum AS IEnumOleDocumentViews _            ' __out IEnumOleDocumentViews **ppEnum
   , BYREF ppView AS IOleDocumentView _                 ' __out IOleDocumentView **ppView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleDocument_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleDocumentSite interface
' IID = b722bcc7-4e68-101b-a2bc-00aa00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleDocumentSite_INTERFACE_DEFINED)
    %IOleDocumentSite_INTERFACE_DEFINED = 1

$IID_IOleDocumentSite = GUID$("{B722BCC7-4E68-101B-A2BC-00AA00404770}")
$IID_IMsoDocumentSite = $IID_IOleDocumentSite

INTERFACE IOleDocumentSite $IID_IOleDocumentSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ActivateMe ( _                                ' VTable offset = 12
     BYVAL pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleDocumentSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleDocumentView interface
' IID = b722bcc6-4e68-101b-a2bc-00aa00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleDocumentView_INTERFACE_DEFINED)
    %IOleDocumentView_INTERFACE_DEFINED = 1

$IID_IOleDocumentView = GUID$("{B722BCC6-4E68-101B-A2BC-00AA00404770}")
$IID_IMsoView = $IID_IOleDocumentView

INTERFACE IOleDocumentView $IID_IOleDocumentView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetInPlaceSite ( _                            ' VTable offset = 12
     BYVAL pIPSite AS IOleInPlaceSite _                 ' __in IOleInPlaceSite *pIPSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInPlaceSite ( _                            ' VTable offset = 16
     BYREF ppIPSite AS IOleInPlaceSite _                ' __out IOleInPlaceSite **ppIPSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocument ( _                               ' VTable offset = 20
     BYREF ppunk AS IUnknown _                          ' __out IUnknown **ppunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRect ( _                                   ' VTable offset = 24
     BYREF prcView AS RECT _                            ' __in LPRECT prcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRect ( _                                   ' VTable offset = 28
     BYREF prcView AS RECT _                            ' __out LPRECT prcView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRectComplex ( _                            ' VTable offset = 32
     BYREF prcView AS RECT _                            ' __in LPRECT prcView
   , BYREF prcHScroll AS RECT _                         ' __in LPRECT prcHScroll
   , BYREF prcVScroll AS RECT _                         ' __in LPRECT prcVScroll
   , BYREF prcSizeBox AS RECT _                         ' __in LPRECT prcSizeBox
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 36
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIActivate ( _                                ' VTable offset = 40
     BYVAL fUIActivate AS LONG _                        ' __in BOOL fUIActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseView ( _                                 ' VTable offset = 48
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveViewState ( _                             ' VTable offset = 52
     BYVAL pstm AS IStream _                            ' __in LPSTREAM pstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyViewState ( _                            ' VTable offset = 56
     BYVAL pstm AS IStream _                            ' __in LPSTREAM pstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 60
     BYVAL pIPSiteNew AS IOleInPlaceSite _              ' __in IOleInPlaceSite *pIPSiteNew
   , BYREF ppViewNew AS IOleDocumentView _              ' __out IOleDocumentView **ppViewNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleDocumentView_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumOleDocumentViews interface
' IID = B722BCC8-4E68-101B-A2BC-00AA00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumOleDocumentViews_INTERFACE_DEFINED)
    %IEnumOleDocumentViews_INTERFACE_DEFINED = 1

$IID_IEnumOleDocumentViews = GUID$("{B722BCC8-4E68-101B-A2BC-00AA00404770}")
$IID_IEnumMsoView = $IID_IEnumOleDocumentViews

INTERFACE IEnumOleDocumentViews $IID_IEnumOleDocumentViews

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cViews AS DWORD _                            ' __in ULONG cViews
   , BYREF rgelt AS IOleDocumentView _                  ' __out IOleDocumentView * rgelt
   , BYREF pcFetched AS DWORD _                         ' __out ULONG * pcFetched
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
     BYREF ppenum AS IEnumOleDocumentViews _            ' __out IEnumOleDocumentViews** ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumOleDocumentViews_INTERFACE_DEFINED__ */


' ########################################################################################
' IContinueCallback interface
' IID = B722BCCA-4E68-101B-A2BC-00AA00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContinueCallback_INTERFACE_DEFINED)
    %IContinueCallback_INTERFACE_DEFINED = 1

$IID_IContinueCallback = GUID$("{B722BCCA-4E68-101B-A2BC-00AA00404770}")

INTERFACE IContinueCallback $IID_IContinueCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FContinue ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FContinuePrinting ( _                         ' VTable offset = 16
     BYVAL nCntPrinted AS LONG _                        ' __in LONG nCntPrinted
   , BYVAL nCurPage AS LONG _                           ' __in LONG nCurPage
   , BYREF pwszPrintStatus AS WSTRINGZ _                ' __in wchar_t *pwszPrintStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContinueCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' IPrint interface
' IID = b722bcc9-4e68-101b-a2bc-00aa00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPrint_INTERFACE_DEFINED)
    %IPrint_INTERFACE_DEFINED = 1

' PRINTFLAG enum
%PRINTFLAG_MAYBOTHERUSER        = 1
%PRINTFLAG_PROMPTUSER           = 2
%PRINTFLAG_USERMAYCHANGEPRINTER = 4
%PRINTFLAG_RECOMPOSETODEVICE    = 8
%PRINTFLAG_DONTACTUALLYPRINT    = 16
%PRINTFLAG_FORCEPROPERTIES      = 32
%PRINTFLAG_PRINTTOFILE          = 64

' // Size = 8 bytes
TYPE PAGERANGE DWORD
   nFromPage AS LONG   ' LONG nFromPage
   nToPage   AS LONG   ' LONG nToPage
END TYPE

' // Size = 24 bytes
TYPE PAGESET DWORD
   cbStruct   AS DWORD           ' ULONG cbStruct
   fOddPages  AS LONG            ' BOOL fOddPages
   fEvenPages AS LONG            ' BOOL fEvenPages
   cPageRange AS DWORD           ' ULONG cPageRange
   rgPages    AS PAGERANGE PTR   ' /* [size_is] */ PAGERANGE rgPages[ 1 ]
END TYPE

%PAGESET_TOLASTPAGE   = &HFFFF??  ' ((WORD)(-1L))

$IID_IPrint = GUID$("{B722BCC9-4E68-101B-A2BC-00AA00404770}")

INTERFACE IPrint $IID_IPrint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetInitialPageNum ( _                         ' VTable offset = 12
     BYVAL nFirstPage AS LONG _                         ' __in LONG nFirstPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPageInfo ( _                               ' VTable offset = 16
     BYREF pnFirstPage AS LONG _                        ' __out LONG *pnFirstPage
   , BYREF pcPages AS LONG _                            ' __out LONG *pcPages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Print ( _                                     ' VTable offset = 20
     BYVAL pnFirstPage AS DWORD _                       ' __out LONG *pnFirstPage
   , BYREF pptd AS DVTARGETDEVICE _                     ' __inout DVTARGETDEVICE **pptd
   , BYREF ppPageSet AS PAGESET _                       ' __inout PAGESET **ppPageSet
   , BYREF pstgmOptions AS STGMEDIUM _                  ' __inout STGMEDIUM *pstgmOptions
   , BYVAL pcallback AS IContinueCallback _             ' __in IContinueCallback *pcallback
   , BYVAL nFirstPage AS LONG _                         ' __in LONG nFirstPage
   , BYREF pcPagesPrinted AS LONG _                     ' __out LONG *pcPagesPrinted
   , BYREF pnLastPage AS LONG _                         ' __out LONG *pnLastPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPrint_INTERFACE_DEFINED__ */


' ########################################################################################
' IOleCommandTarget interface
' IID = B722BCCB-4E68-101B-A2BC-00AA00404770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOleCommandTarget_INTERFACE_DEFINED)
    %IOleCommandTarget_INTERFACE_DEFINED = 1

' OLECMDF enum
%OLECMDF_SUPPORTED         = &H1
%OLECMDF_ENABLED           = &H2
%OLECMDF_LATCHED           = &H4
%OLECMDF_NINCHED           = &H8
%OLECMDF_INVISIBLE         = &H10
%OLECMDF_DEFHIDEONCTXTMENU = &H20

%MSOCMDF_SUPPORTED = %OLECMDF_SUPPORTED
%MSOCMDF_ENABLED   = %OLECMDF_ENABLED
%MSOCMDF_LATCHED   = %OLECMDF_LATCHED
%MSOCMDF_NINCHED   = %OLECMDF_NINCHED

' // Size = 8 bytes
TYPE OLECMD DWORD
   cmdID AS DWORD   ' ULONG cmdID
   cmdf  AS DWORD   ' DWORD cmdf
END TYPE

' // Size = 8 bytes
TYPE MSOCMD DWORD
   cmdID AS DWORD   ' ULONG cmdID
   cmdf  AS DWORD   ' DWORD cmdf
END TYPE

' // Size = 16 bytes
TYPE OLECMDTEXT DWORD
   cmdtextf AS DWORD          ' DWORD cmdtextf
   cwActual AS DWORD          ' ULONG cwActual
   cwBuf    AS DWORD          ' ULONG cwBuf
   rgwz     AS WSTRINGZ PTR   ' /* [size_is] */ wchar_t rgwz[ 1 ]
END TYPE

' // Size = 16 bytes
TYPE MSOCMDTEXT DWORD
   cmdtextf AS DWORD          ' DWORD cmdtextf
   cwActual AS DWORD          ' ULONG cwActual
   cwBuf    AS DWORD          ' ULONG cwBuf
   rgwz     AS WSTRINGZ PTR   ' /* [size_is] */ wchar_t rgwz[ 1 ]
END TYPE

' OLECMDTEXTF enum
%OLECMDTEXTF_NONE   = 0
%OLECMDTEXTF_NAME   = 1
%OLECMDTEXTF_STATUS = 2

%MSOCMDTEXTF_NONE   = %OLECMDTEXTF_NONE
%MSOCMDTEXTF_NAME   = %OLECMDTEXTF_NAME
%MSOCMDTEXTF_STATUS = %OLECMDTEXTF_STATUS

' OLECMDEXECOPT enum
%OLECMDEXECOPT_DODEFAULT      = 0
%OLECMDEXECOPT_PROMPTUSER     = 1
%OLECMDEXECOPT_DONTPROMPTUSER = 2
%OLECMDEXECOPT_SHOWHELP       = 3

%MSOCMDEXECOPT_DODEFAULT      = %OLECMDEXECOPT_DODEFAULT
%MSOCMDEXECOPT_PROMPTUSER     = %OLECMDEXECOPT_PROMPTUSER
%MSOCMDEXECOPT_DONTPROMPTUSER = %OLECMDEXECOPT_DONTPROMPTUSER
%MSOCMDEXECOPT_SHOWHELP       = %OLECMDEXECOPT_SHOWHELP

'/* OLECMDID_STOPDOWNLOAD and OLECMDID_ALLOWUILESSSAVEAS are supported for QueryStatus Only */
' OLECMDID enum
%OLECMDID_OPEN                   = 1
%OLECMDID_NEW                    = 2
%OLECMDID_SAVE                   = 3
%OLECMDID_SAVEAS                 = 4
%OLECMDID_SAVECOPYAS             = 5
%OLECMDID_PRINT                  = 6
%OLECMDID_PRINTPREVIEW           = 7
%OLECMDID_PAGESETUP              = 8
%OLECMDID_SPELL                  = 9
%OLECMDID_PROPERTIES             = 10
%OLECMDID_CUT                    = 11
%OLECMDID_COPY                   = 12
%OLECMDID_PASTE                  = 13
%OLECMDID_PASTESPECIAL           = 14
%OLECMDID_UNDO                   = 15
%OLECMDID_REDO                   = 16
%OLECMDID_SELECTALL              = 17
%OLECMDID_CLEARSELECTION         = 18
%OLECMDID_ZOOM                   = 19
%OLECMDID_GETZOOMRANGE           = 20
%OLECMDID_UPDATECOMMANDS         = 21
%OLECMDID_REFRESH                = 22
%OLECMDID_STOP                   = 23
%OLECMDID_HIDETOOLBARS           = 24
%OLECMDID_SETPROGRESSMAX         = 25
%OLECMDID_SETPROGRESSPOS         = 26
%OLECMDID_SETPROGRESSTEXT        = 27
%OLECMDID_SETTITLE               = 28
%OLECMDID_SETDOWNLOADSTATE       = 29
%OLECMDID_STOPDOWNLOAD           = 30
%OLECMDID_ONTOOLBARACTIVATED     = 31
%OLECMDID_FIND                   = 32
%OLECMDID_DELETE                 = 33
%OLECMDID_HTTPEQUIV              = 34
%OLECMDID_HTTPEQUIV_DONE         = 35
%OLECMDID_ENABLE_INTERACTION     = 36
%OLECMDID_ONUNLOAD               = 37
%OLECMDID_PROPERTYBAG2           = 38
%OLECMDID_PREREFRESH             = 39
%OLECMDID_SHOWSCRIPTERROR        = 40
%OLECMDID_SHOWMESSAGE            = 41
%OLECMDID_SHOWFIND               = 42
%OLECMDID_SHOWPAGESETUP          = 43
%OLECMDID_SHOWPRINT              = 44
%OLECMDID_CLOSE                  = 45
%OLECMDID_ALLOWUILESSSAVEAS      = 46
%OLECMDID_DONTDOWNLOADCSS        = 47
%OLECMDID_UPDATEPAGESTATUS       = 48
%OLECMDID_PRINT2                 = 49
%OLECMDID_PRINTPREVIEW2          = 50
%OLECMDID_SETPRINTTEMPLATE       = 51
%OLECMDID_GETPRINTTEMPLATE       = 52
%OLECMDID_PAGEACTIONBLOCKED      = 55
%OLECMDID_PAGEACTIONUIQUERY      = 56
%OLECMDID_FOCUSVIEWCONTROLS      = 57
%OLECMDID_FOCUSVIEWCONTROLSQUERY = 58
%OLECMDID_SHOWPAGEACTIONMENU     = 59
' Added for IE7
%OLECMDID_ADDTRAVELENTRY         = 60
%OLECMDID_UPDATETRAVELENTRY      = 61
%OLECMDID_UPDATEBACKFORWARDSTATE = 62
%OLECMDID_OPTICAL_ZOOM           = 63
%OLECMDID_OPTICAL_GETZOOMRANGE   = 64
%OLECMDID_WINDOWSTATECHANGED     = 65
' Added for IE8
%OLECMDID_ACTIVEXINSTALLSCOPE    = 66
%OLECMDID_UPDATETRAVELENTRY_DATARECOVERY = 67

%MSOCMDID_OPEN                   = %OLECMDID_OPEN
%MSOCMDID_NEW                    = %OLECMDID_NEW
%MSOCMDID_SAVE                   = %OLECMDID_SAVE
%MSOCMDID_SAVEAS                 = %OLECMDID_SAVEAS
%MSOCMDID_SAVECOPYAS             = %OLECMDID_SAVECOPYAS
%MSOCMDID_PRINT                  = %OLECMDID_PRINT
%MSOCMDID_PRINTPREVIEW           = %OLECMDID_PRINTPREVIEW
%MSOCMDID_PAGESETUP              = %OLECMDID_PAGESETUP
%MSOCMDID_SPELL                  = %OLECMDID_SPELL
%MSOCMDID_PROPERTIES             = %OLECMDID_PROPERTIES
%MSOCMDID_CUT                    = %OLECMDID_CUT
%MSOCMDID_COPY                   = %OLECMDID_COPY
%MSOCMDID_PASTE                  = %OLECMDID_PASTE
%MSOCMDID_PASTESPECIAL           = %OLECMDID_PASTESPECIAL
%MSOCMDID_UNDO                   = %OLECMDID_UNDO
%MSOCMDID_REDO                   = %OLECMDID_REDO
%MSOCMDID_SELECTALL              = %OLECMDID_SELECTALL
%MSOCMDID_CLEARSELECTION         = %OLECMDID_CLEARSELECTION
%MSOCMDID_ZOOM                   = %OLECMDID_ZOOM
%MSOCMDID_GETZOOMRANGE           = %OLECMDID_GETZOOMRANGE

%OLECMDERR_E_FIRST               = %OLE_E_LAST + 1
%OLECMDERR_E_NOTSUPPORTED        = %OLECMDERR_E_FIRST
%OLECMDERR_E_DISABLED            = %OLECMDERR_E_FIRST + 1
%OLECMDERR_E_NOHELP              = %OLECMDERR_E_FIRST + 2
%OLECMDERR_E_CANCELED            = %OLECMDERR_E_FIRST + 3
%OLECMDERR_E_UNKNOWNGROUP        = %OLECMDERR_E_FIRST + 4

%MSOCMDERR_E_FIRST               = %OLECMDERR_E_FIRST
%MSOCMDERR_E_NOTSUPPORTED        = %OLECMDERR_E_NOTSUPPORTED
%MSOCMDERR_E_DISABLED            = %OLECMDERR_E_DISABLED
%MSOCMDERR_E_NOHELP              = %OLECMDERR_E_NOHELP
%MSOCMDERR_E_CANCELED            = %OLECMDERR_E_CANCELED
%MSOCMDERR_E_UNKNOWNGROUP        = %OLECMDERR_E_UNKNOWNGROUP

'#if(NTDDI_VERSION >= NTDDI_WINXPSP2)

%OLECMDARGINDEX_SHOWPAGEACTIONMENU_HWND     = 0
%OLECMDARGINDEX_SHOWPAGEACTIONMENU_X        = 1
%OLECMDARGINDEX_SHOWPAGEACTIONMENU_Y        = 2
%OLECMDARGINDEX_ACTIVEXINSTALL_PUBLISHER    = 0
%OLECMDARGINDEX_ACTIVEXINSTALL_DISPLAYNAME  = 1
%OLECMDARGINDEX_ACTIVEXINSTALL_CLSID        = 2
%OLECMDARGINDEX_ACTIVEXINSTALL_INSTALLSCOPE = 3

%INSTALL_SCOPE_INVALID = 0
%INSTALL_SCOPE_MACHINE = 1
%INSTALL_SCOPE_USER    = 2

' IGNOREMIME enum
%IGNOREMIME_PROMPT = &H1
%IGNOREMIME_TEXT   = &H2

' WPCSETTING enum
%WPCSETTING_LOGGING_ENABLED      = &H1
%WPCSETTING_FILEDOWNLOAD_BLOCKED = &H2

'#endif

$IID_IOleCommandTarget = GUID$("{B722BCCB-4E68-101B-A2BC-00AA00404770}")
$IID_IMsoCommandTarget = $IID_IOleCommandTarget

INTERFACE IOleCommandTarget $IID_IOleCommandTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryStatus ( _                               ' VTable offset = 12
     BYREF pguidCmdGroup AS GUID _                      ' __in const GUID *pguidCmdGroup
   , BYVAL cCmds AS DWORD _                             ' __in ULONG cCmds
   , BYREF prgCmds AS OLECMD _                          ' __out OLECMD *prgCmds
   , BYREF pCmdText AS OLECMDTEXT _                     ' __out OLECMDTEXT *pCmdText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Exec ( _                                      ' VTable offset = 16
     BYREF pguidCmdGroup AS GUID _                      ' __in const GUID *pguidCmdGroup
   , BYVAL nCmdID AS DWORD _                            ' __in DWORD nCmdID
   , BYVAL nCmdExecOpt AS DWORD _                       ' __in DWORD nCmdExecOpt
   , BYREF pvaIn AS VARIANT _                           ' __in VARIANTARG *pvaIn
   , BYREF pvaOut AS VARIANT _                          ' __out * VARIANTARG *pvaOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOleCommandTarget_INTERFACE_DEFINED__ */


' OLECMDID_REFRESHFLAG enum
%OLECMDIDF_REFRESH_NORMAL                                = 0???
%OLECMDIDF_REFRESH_IFEXPIRED                             = 1???
%OLECMDIDF_REFRESH_CONTINUE                              = 2???
%OLECMDIDF_REFRESH_COMPLETELY                            = 3???
%OLECMDIDF_REFRESH_NO_CACHE                              = 4???
%OLECMDIDF_REFRESH_RELOAD                                = 5???
%OLECMDIDF_REFRESH_LEVELMASK                             = &H00FF???
%OLECMDIDF_REFRESH_CLEARUSERINPUT                        = &H1000???
'#if(NTDDI_VERSION >= NTDDI_WINXPSP2)
%OLECMDIDF_REFRESH_PROMPTIFOFFLINE                       = &H2000???
%OLECMDIDF_REFRESH_THROUGHSCRIPT                         = &H4000???
%OLECMDIDF_REFRESH_PAGEACTION_ACTIVEXINSTALL             = &H00010000???
%OLECMDIDF_REFRESH_PAGEACTION_FILEDOWNLOAD               = &H00020000???
%OLECMDIDF_REFRESH_PAGEACTION_LOCALMACHINE               = &H00040000???
%OLECMDIDF_REFRESH_PAGEACTION_POPUPWINDOW                = &H00080000???
%OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNLOCALMACHINE   = &H00100000???
%OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNTRUSTED        = &H00200000???
%OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTRANET       = &H00400000???
%OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNINTERNET       = &H00800000???
%OLECMDIDF_REFRESH_PAGEACTION_PROTLOCKDOWNRESTRICTED     = &H01000000???
'#elif(NTDDI_VERSION >= NTDDI_WINXP)
'      OLECMDIDF_REFRESH_PROMPTIFOFFLINE = 0x2000,
'      OLECMDIDF_REFRESH_THROUGHSCRIPT   = 0x4000,
'#else
'      OLECMDIDF_REFRESH_PROMPTIFOFFLINE = 0x2000,
'#endif
%OLECMDIDF_REFRESH_PAGEACTION_MIXEDCONTENT               = &H02000000???
%OLECMDIDF_REFRESH_PAGEACTION_INVALID_CERT               = &H04000000???

' OLECMDID_PAGEACTIONFLAG enum
'#if(NTDDI_VERSION >= NTDDI_WINXPSP2)
%OLECMDIDF_PAGEACTION_FILEDOWNLOAD                       = &H00000001???
%OLECMDIDF_PAGEACTION_ACTIVEXINSTALL                     = &H00000002???
%OLECMDIDF_PAGEACTION_ACTIVEXTRUSTFAIL                   = &H00000004???
%OLECMDIDF_PAGEACTION_ACTIVEXUSERDISABLE                 = &H00000008???
%OLECMDIDF_PAGEACTION_ACTIVEXDISALLOW                    = &H00000010???
%OLECMDIDF_PAGEACTION_ACTIVEXUNSAFE                      = &H00000020???
%OLECMDIDF_PAGEACTION_POPUPWINDOW                        = &H00000040???
%OLECMDIDF_PAGEACTION_LOCALMACHINE                       = &H00000080???
%OLECMDIDF_PAGEACTION_MIMETEXTPLAIN                      = &H00000100???
%OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE                     = &H00000200???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNLOCALMACHINE           = &H00000400???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNTRUSTED                = &H00000800???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTRANET               = &H00001000???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNINTERNET               = &H00002000???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNRESTRICTED             = &H00004000???
%OLECMDIDF_PAGEACTION_PROTLOCKDOWNDENY                   = &H00008000???
%OLECMDIDF_PAGEACTION_POPUPALLOWED                       = &H00010000???
%OLECMDIDF_PAGEACTION_SCRIPTPROMPT                       = &H00020000???
%OLECMDIDF_PAGEACTION_ACTIVEXUSERAPPROVAL                = &H00040000???
%OLECMDIDF_PAGEACTION_MIXEDCONTENT                       = &H00080000???
%OLECMDIDF_PAGEACTION_INVALID_CERT                       = &H00100000???
%OLECMDIDF_PAGEACTION_INTRANETZONEREQUEST                = &H00200000???
%OLECMDIDF_PAGEACTION_XSSFILTERED                        = &H00400000???
%OLECMDIDF_PAGEACTION_SPOOFABLEIDNHOST                   = &H00800000???
'%OLECMDIDF_PAGEACTION_LOWRIGHTSIE                        = &H01000000???   ' // Removed in the Windows 7 SDK
%OLECMDIDF_PAGEACTION_SCRIPTNAVIGATE_ACTIVEXUSERAPPROVAL = &H02000000???
%OLECMDIDF_PAGEACTION_WPCBLOCKED                         = &H04000000???
%OLECMDIDF_PAGEACTION_WPCBLOCKED_ACTIVEX                 = &H08000000???
%OLECMDIDF_PAGEACTION_EXTENSION_COMPAT_BLOCKED           = &H10000000???
%OLECMDIDF_PAGEACTION_NORESETACTIVEX                     = &H20000000???
%OLECMDIDF_PAGEACTION_GENERIC_STATE                      = &H40000000???
%OLECMDIDF_PAGEACTION_RESET                              = &H80000000&   ' Internet Explorer 8. OLECMDIDF_PAGEACTION_RESET is cast to an int.

' OLECMDID_BROWSERSTATEFLAG enum
%OLECMDIDF_BROWSERSTATE_EXTENSIONSOFF                    = &H00000001???
%OLECMDIDF_BROWSERSTATE_IESECURITY                       = &H00000002???
%OLECMDIDF_BROWSERSTATE_PROTECTEDMODE_OFF                = &H00000004???
%OLECMDIDF_BROWSERSTATE_RESET                            = &H00000008???

' enum OLECMDID_OPTICAL_ZOOMFLAG
%OLECMDIDF_OPTICAL_ZOOM_NOPERSIST                        = &H00000001???

' PAGEACTION_UI enum
%PAGEACTION_UI_DEFAULT  = 0
%PAGEACTION_UI_MODAL    = 1
%PAGEACTION_UI_MODELESS = 2
%PAGEACTION_UI_SILENT   = 3
'#endif

' OLECMDID_WINDOWSTATE_FLAG enum
%OLECMDIDF_WINDOWSTATE_USERVISIBLE        = &H00000001???
%OLECMDIDF_WINDOWSTATE_ENABLED            = &H00000002???
%OLECMDIDF_WINDOWSTATE_USERVISIBLE_VALID  = &H00010000???
%OLECMDIDF_WINDOWSTATE_ENABLED_VALID      = &H00020000???

$SID_SContainerDispatch = GUID$("{B722BE00-4E68-101B-A2BC-00AA00404770}")


' ########################################################################################
' IZoomEvents interface
' IID = 41B68150-904C-4E17-A0BA-A438182E359D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IZoomEvents_INTERFACE_DEFINED)
    %IZoomEvents_INTERFACE_DEFINED = 1

$IID_IZoomEvents = GUID$("{41B68150-904C-4E17-A0BA-A438182E359D}")

INTERFACE IZoomEvents $IID_IZoomEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnZoomPercentChanged ( _                      ' VTable offset = 12
     BYVAL ulZoomPercent AS DWORD _                     ' __in ULONG ulZoomPercent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IZoomEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' IProtectFocus interface
' IID = D81F90A3-8156-44F7-AD28-5ABB87003274
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProtectFocus_INTERFACE_DEFINED)
    %IProtectFocus_INTERFACE_DEFINED = 1

$IID_IProtectFocus = GUID$("{D81F90A3-8156-44F7-AD28-5ABB87003274}")
$SID_SProtectFocus = $IID_IProtectFocus

INTERFACE IProtectFocus $IID_IProtectFocus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AllowFocusChange ( _                          ' VTable offset = 12
     BYREF pfAllow AS LONG _                            ' __out BOOL *pfAllow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProtectFocus_INTERFACE_DEFINED__ */


' ########################################################################################
' IProtectedModeMenuServices interface
' IID = 73C105EE-9DFF-4A07-B83C-7EFF290C266E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProtectedModeMenuServices_INTERFACE_DEFINED)
    %IProtectedModeMenuServices_INTERFACE_DEFINED = 1

$IID_IProtectedModeMenuServices = GUID$("{73C105EE-9DFF-4A07-B83C-7EFF290C266E}")

INTERFACE IProtectedModeMenuServices $IID_IProtectedModeMenuServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateMenu ( _                                ' VTable offset = 12
     BYREF phMenu AS DWORD _                            ' __out HMENU *phMenu
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadMenu ( _                                  ' VTable offset = 16
     BYREF pszModuleName AS WSTRINGZ _                  ' __in LPCWSTR pszModuleName
   , BYREF pszMenuName AS WSTRINGZ _                    ' __in LPCWSTR pszMenuName
   , BYREF phMenu AS DWORD _                            ' __out HMENU *phMenu
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadMenuID ( _                                ' VTable offset = 20
     BYREF pszModuleName AS WSTRINGZ _                  ' __in LPCWSTR pszModuleName
   , BYVAL wResourceID AS WORD _                        ' __in WORD wResourceID
   , BYREF phMenu AS DWORD _                            ' __out HMENU *phMenu
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProtectedModeMenuServices_INTERFACE_DEFINED__ */
