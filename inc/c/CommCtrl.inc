' ########################################################################################
' Microsoft Windows
' File: CommCtrl.inc
' Contents: Interface for the Windows Common Controls
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMMCTRL_INC = 1

#INCLUDE ONCE "windows.inc"

' Include support for streams
#IF NOT %DEF(%WIN32_LEAN_AND_MEAN)
#INCLUDE ONCE "objidl.inc"
#ENDIF

'#ifndef _HRESULT_DEFINED
'#define _HRESULT_DEFINED
'typedef __success(return >= 0) long HRESULT;
'#endif // !_HRESULT_DEFINED

' Wrapper functions available in individual files:
' AnimateCtrl.inc    : Animation control
' ButtonCtrl         : Button control
' ComboBoxCtrl.inc   : ComboBox control
' ComboBoxExCtrl.inc : ComboBoxEx control
' DateTimeCtrl.inc   : Date and Time Picker control
' EditCtrl           : Edit control
' HeaderCtrl         : Header control
' HotKeyCtrl         : HotKey control
' IPAddressCtrl.inc  : IP Address control
' ListBoxCtrl.inc    : ListBox control
' ListViewCtrl       : ListView control
' MonthCalCtrl       : MonthCal control
' PagerCalCtrl       : Pager control
' ProgressBarCtrl    : ProgressBar control
' RebarCtrl          : Rebar control
' ScrollbarCtrl      : Scrollbar control
' StaticCtrl         : Static control
' StatusbarCtrl      : Statusbar control
' SysLinkCtrl        : SysLink control
' TabCtrl            : Tab control
' TaskDialogCtrl     : Task Dialog control
' ToolbarCtrl        : Toolbar control
' TooltipCtrl        : ToolTip control
' TrackbarCtrl       : Trackbar control
' TreeviewCtrl       : TreeView control
' UpDownCtrl         : UpDown control

#IF NOT %DEF(%NOUSER)

'//
'// Users of this header may define any number of these constants to avoid
'// the definitions of each functional group.
'//
'//    NOTOOLBAR      Customizable bitmap-button toolbar control.
'//    NOUPDOWN       Up and Down arrow increment/decrement control.
'//    NOSTATUSBAR    Status bar control.
'//    NOMENUHELP     APIs to help manage menus, especially with a status bar.
'//    NOTRACKBAR     Customizable column-width tracking control.
'//    NODRAGLIST     APIs to make a listbox source and sink drag&drop actions.
'//    NOPROGRESS     Progress gas gauge.
'//    NOHOTKEY       HotKey control
'//    NOHEADER       Header bar control.
'//    NOIMAGEAPIS    ImageList apis.
'//    NOLISTVIEW     ListView control.
'//    NOTREEVIEW     TreeView control.
'//    NOTABCONTROL   Tab control.
'//    NOANIMATE      Animate control.
'//    NOBUTTON       Button control.
'//    NOSTATIC       Static control.
'//    NOEDIT         Edit control.
'//    NOLISTBOX      Listbox control.
'//    NOCOMBOBOX     Combobox control.
'//    NOSCROLLBAR    Scrollbar control.
'//    NOTASKDIALOG   Task Dialog.
'//    NO_COMMCTRL_DA Dynamic Array routines.
'//
'//=============================================================================

'#INCLUDE ONCE "prsht.inc"

'WINCOMMCTRLAPI void WINAPI InitCommonControls(void);
DECLARE SUB InitCommonControls IMPORT "COMCTL32.DLL" ALIAS "InitCommonControls" ( _
 )                                                      ' void

'#if (_WIN32_IE >= 0x0300)

' // Size = 8 bytes
TYPE tagINITCOMMONCONTROLSEX
   dwSize AS DWORD   ' DWORD dwSize // size of this structure
   dwICC  AS DWORD   ' DWORD dwICC  // flags indicating which classes to be initialized
END TYPE
' Note: INITCOMMONCONTROLSEX can't be used as the name because it conflicts with the function InitCommonControlsEx
#IF NOT %DEF(%PBFORMS_INC)
MACRO INIT_COMMON_CONTROLSEX = tagINITCOMMONCONTROLSEX   ' // For compatibility with PowerBASIC include files
#ENDIF

%ICC_LISTVIEW_CLASSES   = &H00000001??? ' listview, header
%ICC_TREEVIEW_CLASSES   = &H00000002??? ' treeview, tooltips
%ICC_BAR_CLASSES        = &H00000004??? ' toolbar, statusbar, trackbar, tooltips
%ICC_TAB_CLASSES        = &H00000008??? ' tab, tooltips
%ICC_UPDOWN_CLASS       = &H00000010??? ' updown
%ICC_PROGRESS_CLASS     = &H00000020??? ' progress
%ICC_HOTKEY_CLASS       = &H00000040??? ' hotkey
%ICC_ANIMATE_CLASS      = &H00000080??? ' animate
%ICC_WIN95_CLASSES      = &H000000FF???
%ICC_DATE_CLASSES       = &H00000100??? ' month picker, date picker, time picker, updown
%ICC_USEREX_CLASSES     = &H00000200??? ' comboex
%ICC_COOL_CLASSES       = &H00000400??? ' rebar (coolbar) control
'#if (_WIN32_IE >= 0x0400)
%ICC_INTERNET_CLASSES   = &H00000800???
%ICC_PAGESCROLLER_CLASS = &H00001000??? ' page scroller
%ICC_NATIVEFNTCTL_CLASS = &H00002000??? ' native font control
'#endif
'#if (_WIN32_WINNT >= 0x501)
%ICC_STANDARD_CLASSES   = &H00004000???
%ICC_LINK_CLASS         = &H00008000???
'#endif


DECLARE FUNCTION InitCommonControlsEx IMPORT "COMCTL32.DLL" ALIAS "InitCommonControlsEx" ( _
   BYREF lpInitCtrls AS INIT_COMMON_CONTROLSEX _        ' __in const LPINITCOMMONCONTROLSEX lpInitCtrls
 ) AS LONG                                              ' BOOL

'#endif      // _WIN32_IE >= 0x0300

%ODT_HEADER             = 100
%ODT_TAB                = 101
%ODT_LISTVIEW           = 102


'//====== Ranges for control message IDs =======================================

%LVM_FIRST              = &H1000      ' ListView messages
%TV_FIRST               = &H1100      ' TreeView messages
%HDM_FIRST              = &H1200      ' Header messages
%TCM_FIRST              = &H1300      ' Tab control messages

'#if (_WIN32_IE >= 0x0400)
%PGM_FIRST              = &H1400      ' Pager control messages
'#if (_WIN32_WINNT >= 0x501)
%ECM_FIRST              = &H1500      ' Edit control messages
%BCM_FIRST              = &H1600      ' Button control messages
%CBM_FIRST              = &H1700      ' Combobox control messages
'#endif
%CCM_FIRST              = &H2000      ' Common control shared messages
%CCM_LAST               = %CCM_FIRST + &H200

%CCM_SETBKCOLOR         = %CCM_FIRST + 1 ' lParam is bkColor

' // Size = 12 bytes
TYPE COLORSCHEME DWORD
   dwSize          AS DWORD   ' DWORD    dwSize
   clrBtnHighlight AS DWORD   ' COLORREF clrBtnHighlight  // highlight color
   clrBtnShadow    AS DWORD   ' COLORREF clrBtnShadow     // shadow color
END TYPE

%CCM_SETCOLORSCHEME     = %CCM_FIRST + 2 ' lParam is color scheme
%CCM_GETCOLORSCHEME     = %CCM_FIRST + 3 ' fills in COLORSCHEME pointed to by lParam
%CCM_GETDROPTARGET      = %CCM_FIRST + 4
%CCM_SETUNICODEFORMAT   = %CCM_FIRST + 5
%CCM_GETUNICODEFORMAT   = %CCM_FIRST + 6

'#if (_WIN32_IE >= 0x0500)
'#if (_WIN32_WINNT >= 0x501)
%COMCTL32_VERSION  = 6
'#else
'#define COMCTL32_VERSION  5
'#endif

%CCM_SETVERSION         = %CCM_FIRST + 7
%CCM_GETVERSION         = %CCM_FIRST + 8
%CCM_SETNOTIFYWINDOW    = %CCM_FIRST + 9 ' wParam = hwndParent.
'#if (_WIN32_WINNT >= 0x501)
%CCM_SETWINDOWTHEME     = %CCM_FIRST + &Hb
%CCM_DPISCALE           = %CCM_FIRST + &Hc ' wParam == Awareness
'#endif
'#endif // (_WIN32_IE >= 0x0500)

'#endif // (_WIN32_IE >= 0x0400)

'#if (_WIN32_IE >= 0x0400)
'// for tooltips
%INFOTIPSIZE = 1024
'#endif

'//====== WM_NOTIFY Macros =====================================================

'#define HANDLE_WM_NOTIFY(hwnd, wParam, lParam, fn) \
'    (fn)((hwnd), (int)(wParam), (NMHDR *)(lParam))
'#define FORWARD_WM_NOTIFY(hwnd, idFrom, pnmhdr, fn) \
'    (LRESULT)(fn)((hwnd), WM_NOTIFY, (WPARAM)(int)(idFrom), (LPARAM)(NMHDR *)(pnmhdr))


'//====== Generic WM_NOTIFY notification codes =================================

' // Note: The remed equates are predefined in the compiler.

%NM_FIRST = 0            ' generic to all controls
%NM_LAST  = -99&

'%NM_OUTOFMEMORY     = %NM_FIRST - 1
'%NM_CLICK           = %NM_FIRST - 2  ' uses NMCLICK type
'%NM_DBLCLK          = %NM_FIRST - 3
'%NM_RETURN          = %NM_FIRST - 4
'%NM_RCLICK          = %NM_FIRST - 5  ' uses NMCLICK type
'%NM_RDBLCLK         = %NM_FIRST - 6
'%NM_SETFOCUS        = %NM_FIRST - 7
'%NM_KILLFOCUS       = %NM_FIRST - 8
'#if (_WIN32_IE >= 0x0300)
'%NM_CUSTOMDRAW      = %NM_FIRST - 12
'%NM_HOVER           = %NM_FIRST - 13
'#endif
'#if (_WIN32_IE >= 0x0400)
'%NM_NCHITTEST       = %NM_FIRST - 14 ' uses NMMOUSE type
'%NM_KEYDOWN         = %NM_FIRST - 15 ' uses NMKEY type
'%NM_RELEASEDCAPTURE = %NM_FIRST - 16
'%NM_SETCURSOR       = %NM_FIRST - 17 ' uses NMMOUSE type
'%NM_CHAR            = %NM_FIRST - 18 ' uses NMCHAR type
'#endif
'#if (_WIN32_IE >= 0x0401)
'%NM_TOOLTIPSCREATED = %NM_FIRST - 19 ' notify of when the tooltips window is create
'#endif
'#if (_WIN32_IE >= 0x0500)
'%NM_LDOWN           = %NM_FIRST - 20
'%NM_RDOWN           = %NM_FIRST - 21
'%NM_THEMECHANGED    = %NM_FIRST - 22
'#endif

'#if _WIN32_WINNT >= 0x0600
%NM_FONTCHANGED          = %NM_FIRST - 23
%NM_CUSTOMTEXT           = %NM_FIRST - 24  ' // uses NMCUSTOMTEXT struct
%NM_TVSTATEIMAGECHANGING = %NM_FIRST - 24  ' // uses NMTVSTATEIMAGECHANGING struct, defined after HTREEITEM
'#endif

'#ifndef CCSIZEOF_STRUCT
'#define CCSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
'#endif

'//====== Generic WM_NOTIFY notification structures ============================
'#if (_WIN32_IE >= 0x0401)

' // Size = 16 bytes
' // Note: NMTOOLTIPSCREATED is built-in in PB
TYPE NMTOOLTIPSCREATED ' DWORD
   hdr          AS NMHDR   ' NMHDR hdr
   hwndToolTips AS DWORD   ' HWND  hwndToolTips
END TYPE
'#endif

'#if (_WIN32_IE >= 0x0400)

' // Size = 32 bytes
' // Note: NMMOUSE is built-in in PB
TYPE NMMOUSE ' DWORD
   hdr        AS NMHDR   ' NMHDR     hdr
   dwItemSpec AS DWORD   ' DWORD_PTR dwItemSpec
   dwItemData AS DWORD   ' DWORD_PTR dwItemData
   pt         AS POINT   ' POINT     pt
   dwHitInfo  AS DWORD   ' LPARAM    dwHitInfo  // any specifics about where on the item or control the mouse is
END TYPE

'typedef NMMOUSE NMCLICK;
MACRO NMCLICK = NMMOUSE

'// Generic structure to request an object of a specific type.

'typedef struct tagNMOBJECTNOTIFY {
'    NMHDR   hdr;
'    int     iItem;
'#ifdef __IID_DEFINED__
'    const IID *piid;
'#else
'    const void *piid;
'#endif
'    void *pObject;
'    HRESULT hResult;
'    DWORD dwFlags;    // control specific flags (hints as to where in iItem it hit)
'} NMOBJECTNOTIFY, *LPNMOBJECTNOTIFY;

' // Size = 32 bytes
TYPE NMOBJECTNOTIFY DWORD
   hdr     AS NMHDR      ' NMHDR     hdr
   iItem   AS LONG       ' int       iItem
   piid    AS GUID PTR   ' IID      *piid
   pObject AS DWORD PTR  ' IUnknown *pObject
   hResult AS LONG       ' HRESULT   hResult
   dwFlags AS DWORD      ' DWORD     dwFlags    // control specific flags (hints as to where in iItem it hit)
END TYPE

'// Generic structure for a key

' // Size = 20 bytes
' // Note: NMKEY is built-in in PB
TYPE NMKEY ' DWORD
   hdr    AS NMHDR   ' NMHDR hdr
   nVKey  AS DWORD   ' UINT  nVKey
   uFlags AS DWORD   ' UINT  uFlags
END TYPE

'// Generic structure for a character

' // Size = 24 bytes
' // Note: NMCHAR is built-in in PB
TYPE NMCHAR ' DWORD
   hdr        AS NMHDR   ' NMHDR   hdr
   ch         AS DWORD   ' UINT    ch
   dwItemPrev AS DWORD   ' DWORD   dwItemPrev  // Item previously selected
   dwItemNext AS DWORD   ' DWORD   dwItemNext  // Item to be selected
END TYPE

'#endif           // _WIN32_IE >= 0x0400

'#if (_WIN32_IE >= 0x0600)

' // Size = 36 bytes
TYPE NMCUSTOMTEXT DWORD
   hdr      AS NMHDR          ' NMHDR hdr
   hDC      AS DWORD          ' HDC hdc
   lpString AS WSTRINGZ PTR   ' LPCWSTR lpString
   nCount   AS LONG           ' int nCount
   lpRect   AS RECT PTR       ' LPRECT lpRect
   uFormat  AS DWORD          ' UINT uFormat
   fLink    AS LONG           ' BOOL fLink
END TYPE

'#endif           // _WIN32_IE >= 0x0600

'//====== WM_NOTIFY codes (NMHDR.code values) ==================================

'%NM_FIRST = 0            ' generic to all controls
'%NM_LAST  = -99&

%LVN_FIRST               = 0-100       ' listview
%LVN_LAST                = 0-199

'// Property sheet reserved      (0U-200U) -  (0U-299U) - see prsht.h

'%HDN_FIRST               = 0-300       ' header
%HDN_LAST                = 0-399

%TVN_FIRST               = 0-400       ' treeview
%TVN_LAST                = 0-499

%TTN_FIRST               = 0-520       ' tooltips
%TTN_LAST                = 0-549

%TCN_FIRST               = 0-550       ' tab control
%TCN_LAST                = 0-580

'// Shell reserved               (0U-580U) -  (0U-589U)

#IF NOT %DEF(%CDN_FIRST)
%CDN_FIRST               = 0-601       ' common dialog new
#ENDIF
#IF NOT %DEF(%CDN_LAST)
%CDN_LAST                = 0-699
#ENDIF

%TBN_FIRST               = 0-700      ' toolbar
%TBN_LAST                = 0-720

%UDN_FIRST               = 0-721       ' updown
'%UDN_LAST                = 0-740  ' prior to Vista
%UDN_LAST                = 0-729   ' Windows Vista

' Prior to Windows Vista
'%DTN_FIRST               = 0-760       ' datetimepick
'%DTN_LAST                = 0-799

' Windows Vista
%DTN_FIRST               = 0-740       ' // datetimepick
%DTN_LAST                = 0-745       ' // DTN_FIRST - 5

'#if (_WIN32_IE >= 0x0300)

' Prior to Windows Vista
'%MCN_FIRST               = 0-750       ' monthcal
'%MCN_LAST                = 0-759

' Windows Vista
%MCN_FIRST               = 0-746       ' // monthcal
%MCN_LAST                = 0-752       ' // MCN_FIRST - 6

' Windows Vista
%DTN_FIRST2              = 0-753       ' // datetimepick2
%DTN_LAST2               = 0-799

%CBEN_FIRST              = 0-800       ' combo box ex
%CBEN_LAST               = 0-830

%RBN_FIRST               = 0-831       ' rebar
%RBN_LAST                = 0-859

'#endif

'#if (_WIN32_IE >= 0x0400)

%IPN_FIRST               = 0-860       ' internet address
%IPN_LAST                = 0-879       ' internet address

%SBN_FIRST               = 0-880       ' status bar
%SBN_LAST                = 0-899

%PGN_FIRST               = 0-900       ' Pager Control
%PGN_LAST                = 0-950

'#endif

'#if (_WIN32_IE >= 0x0500)
#IF NOT %DEF(%WMN_FIRST)
%WMN_FIRST               = 0-1000
%WMN_LAST                = 0-1200
#ENDIF
'#endif

'#if (_WIN32_WINNT >= 0x0501)
%BCN_FIRST               = 0-1250
%BCN_LAST                = 0-1350
'#endif

' Windows Vista
'#if (_WIN32_WINNT >= 0x0600)
%TRBN_FIRST              = 0-1501      ' // trackbar
%TRBN_LAST               = 0-1519
'#endif

%MSGF_COMMCTRL_BEGINDRAG   = &H4200
%MSGF_COMMCTRL_SIZEHEADER  = &H4201
%MSGF_COMMCTRL_DRAGSELECT  = &H4202
%MSGF_COMMCTRL_TOOLBARCUST = &H4203

'#if (_WIN32_IE >= 0x0300)
'//==================== CUSTOM DRAW ==========================================


'// custom draw return flags
'// values under 0x00010000 are reserved for global custom draw values.
'// above that are for specific controls
%CDRF_DODEFAULT          = &H00000000
%CDRF_NEWFONT            = &H00000002
%CDRF_SKIPDEFAULT        = &H00000004
%CDRF_DOERASE            = &H00000008  ' // draw the background
%CDRF_SKIPPOSTPAINT      = &H00000100  ' // don't draw the focus rect

%CDRF_NOTIFYPOSTPAINT    = &H00000010
%CDRF_NOTIFYITEMDRAW     = &H00000020
'#if (_WIN32_IE >= 0x0400)
%CDRF_NOTIFYSUBITEMDRAW  = &H00000020  ' flags are the same, we can distinguish by context
'#endif
%CDRF_NOTIFYPOSTERASE    = &H00000040

'// drawstage flags
'// values under 0x00010000 are reserved for global custom draw values.
'// above that are for specific controls
%CDDS_PREPAINT           = &H00000001
%CDDS_POSTPAINT          = &H00000002
%CDDS_PREERASE           = &H00000003
%CDDS_POSTERASE          = &H00000004
'// the 0x000010000 bit means it's individual item specific
%CDDS_ITEM               = &H00010000
%CDDS_ITEMPREPAINT       = %CDDS_ITEM OR %CDDS_PREPAINT
%CDDS_ITEMPOSTPAINT      = %CDDS_ITEM OR %CDDS_POSTPAINT
%CDDS_ITEMPREERASE       = %CDDS_ITEM OR %CDDS_PREERASE
%CDDS_ITEMPOSTERASE      = %CDDS_ITEM OR %CDDS_POSTERASE
'#if (_WIN32_IE >= 0x0400)
%CDDS_SUBITEM            = &H00020000
'#endif

'// itemState flags
%CDIS_SELECTED         = &H0001???
%CDIS_GRAYED           = &H0002???
%CDIS_DISABLED         = &H0004???
%CDIS_CHECKED          = &H0008???
%CDIS_FOCUS            = &H0010???
%CDIS_DEFAULT          = &H0020???
%CDIS_HOT              = &H0040???
%CDIS_MARKED           = &H0080???
%CDIS_INDETERMINATE    = &H0100???
'#if (_WIN32_WINNT >= 0x501)
%CDIS_SHOWKEYBOARDCUES = &H0200???
'#endif
'#if (_WIN32_WINNT >= 0x0600)
%CDIS_NEARHOT          = &H0400???
%CDIS_OTHERSIDEHOT     = &H0800???
%CDIS_DROPHILITED      = &H1000???
'#endif

' // Size 48 bytes
TYPE NMCUSTOMDRAW DWORD
   hdr         AS NMHDR   ' NMHDR     hdr
   dwDrawStage AS DWORD   ' DWORD     dwDrawStage
   hdc         AS DWORD   ' HDC       hdc
   rc          AS RECT    ' RECT      rc
   dwItemSpec  AS DWORD   ' DWORD_PTR dwItemSpec  // this is control specific, but it's how to specify an item. valid only with CDDS_ITEM bit set
   uItemState  AS DWORD   ' UINT      uItemState
   lItemlParam AS LONG    ' LPARAM    lItemlParam
END TYPE

' // Size 52 bytes
TYPE NMTTCUSTOMDRAW DWORD
   nmcd       AS NMCUSTOMDRAW   ' NMCUSTOMDRAW nmcd
   uDrawFlags AS DWORD          ' UINT         uDrawFlags
END TYPE

' // Size 60 bytes
TYPE NMCUSTOMSPLITRECTINFO DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   rcClient AS RECT    ' RECT rcClient
   rcButton AS RECT    ' RECT rcButton
   rcSplit  AS RECT    ' RECT rcSplit
END TYPE

%NM_GETCUSTOMSPLITRECT       = %BCN_FIRST + &H0003

'#endif      // _WIN32_IE >= 0x0300


'//====== IMAGE APIS ===========================================================

#IF NOT %DEF(%NOIMAGELIST)

%CLR_NONE    = &HFFFFFFFF???
%CLR_DEFAULT = &HFF000000???

'#ifndef HIMAGELIST
'struct _IMAGELIST;
'typedef struct _IMAGELIST* HIMAGELIST;
'#endif

'#ifndef IMAGELISTDRAWPARAMS
'#if (_WIN32_IE >= 0x0300)

' Size of the structure: 68 bytes
' For Windows versions prior to XP, set the cbSize member = 56 bytes
TYPE IMAGELISTDRAWPARAMS DWORD
   cbSize   AS DWORD   ' DWORD       cbSize
   himl     AS DWORD   ' HIMAGELIST  himl
   i        AS LONG    ' int         i
   hdcDst   AS DWORD   ' HDC         hdcDst
   x        AS LONG    ' int         x
   y        AS LONG    ' int         y
   cx       AS LONG    ' int         cx
   cy       AS LONG    ' int         cy
   xBitmap  AS LONG    ' int         xBitmap  // x offest from the upperleft of bitmap
   yBitmap  AS LONG    ' int         yBitmap  // y offset from the upperleft of bitmap
   rgbBk    AS DWORD   ' COLORREF    rgbBk
   rgbFg    AS DWORD   ' COLORREF    rgbFg
   fStyle   AS DWORD   ' UINT        fStyle
   dwRop    AS DWORD   ' DWORD       dwRop
'#IF (%WIN32_IE >= &H0501)
#IF %WINVER >= &H0501
   fState   AS DWORD   ' DWORD       fState
   Frame    AS DWORD   ' DWORD       Frame
   crEffect AS DWORD   ' COLORREF    crEffect
#ENDIF
END TYPE

'#endif      // _WIN32_IE >= 0x0300
'#endif

%ILC_MASK          = &H00000001???
%ILC_COLOR         = &H00000000???
%ILC_COLORDDB      = &H000000FE???
%ILC_COLOR4        = &H00000004???
%ILC_COLOR8        = &H00000008???
%ILC_COLOR16       = &H00000010???
%ILC_COLOR24       = &H00000018???
%ILC_COLOR32       = &H00000020???
%ILC_PALETTE       = &H00000800??? ' (not implemented)
'#if (_WIN32_WINNT >= 0x501)
%ILC_MIRROR        = &H00002000??? ' Mirror the icons contained, if the process is mirrored
%ILC_PERITEMMIRROR = &H00008000??? ' Causes the mirroring code to mirror each item when inserting a set of images, verses the whole strip
'#endif
'#if _WIN32_WINNT >= 0x0600
%ILC_ORIGINALSIZE     = &H00010000???   ' // Imagelist should accept smaller than set images and apply OriginalSize based on image added
%ILC_HIGHQUALITYSCALE = &H00020000???   ' // Imagelist should enable use of the high quality scaler.
'#endif

DECLARE FUNCTION ImageList_Create IMPORT "COMCTL32.DLL" ALIAS "ImageList_Create" ( _
   BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL flags AS DWORD _                               ' __in UINT flags
 , BYVAL cInitial AS LONG _                             ' __in int cInitial
 , BYVAL cGrow AS LONG _                                ' __in int cGrow
 ) AS DWORD                                             ' HIMAGELIST

DECLARE FUNCTION ImageList_Destroy IMPORT "COMCTL32.DLL" ALIAS "ImageList_Destroy" ( _
   OPTIONAL BYVAL himl AS DWORD _                       ' __in_opt HIMAGELIST himl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_GetImageCount IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetImageCount" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 ) AS LONG                                              ' int

'#if (_WIN32_IE >= 0x0300)
DECLARE FUNCTION ImageList_SetImageCount IMPORT "COMCTL32.DLL" ALIAS "ImageList_SetImageCount" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL uNewCount AS DWORD _                           ' __in UINT uNewCount
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION ImageList_Add IMPORT "COMCTL32.DLL" ALIAS "ImageList_Add" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL hbmImage AS DWORD _                            ' __in HBITMAP hbmImage
 , OPTIONAL BYVAL hbmMask AS DWORD _                    ' __in_opt HBITMAP hbmMask
 ) AS LONG                                              ' int

DECLARE FUNCTION ImageList_ReplaceIcon IMPORT "COMCTL32.DLL" ALIAS "ImageList_ReplaceIcon" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYVAL hicon AS DWORD _                               ' __in HICON hicon
 ) AS LONG                                              ' int

DECLARE FUNCTION ImageList_SetBkColor IMPORT "COMCTL32.DLL" ALIAS "ImageList_SetBkColor" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL clrBk AS DWORD _                               ' __in COLORREF clrBk
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION ImageList_GetBkColor IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetBkColor" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 ) AS DWORD                                             ' COLORREF

DECLARE FUNCTION ImageList_SetOverlayImage IMPORT "COMCTL32.DLL" ALIAS "ImageList_SetOverlayImage" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL iImage AS LONG _                               ' __in int iImage
 , BYVAL iOverlay AS LONG _                             ' __in int iOverlay
 ) AS LONG                                              ' BOOL

'MACRO ImageList_AddIcon(hIml, hIcon) = ImageList_ReplaceIcon(hIml, -1, hIcon)
FUNCTION ImageList_AddIcon (BYVAL hIml AS DWORD, BYVAL hIcon AS DWORD) AS LONG
   FUNCTION = ImageList_ReplaceIcon(hIml, -1, hIcon)
END FUNCTION


'%ILD_NORMAL      = &H0000???
'%ILD_TRANSPARENT = &H0001???
'%ILD_MASK        = &H0010???
'%ILD_IMAGE       = &H0020???
'#if (_WIN32_IE >= 0x0300)
'%ILD_ROP         = &H0040???
'#endif
'%ILD_BLEND25     = &H0002???
'%ILD_BLEND50     = &H0004???
'%ILD_OVERLAYMASK = &H0F00???

'#define INDEXTOOVERLAYMASK(i) ((i) << 8)
FUNCTION IndexToOverlayMask (BYVAL i AS LONG) AS LONG
   SHIFT LEFT i, 8
   FUNCTION = i
END FUNCTION

%ILD_PRESERVEALPHA = &H00001000???  ' // This preserves the alpha channel in dest
%ILD_SCALE         = &H00002000???  ' // Causes the image to be scaled to cx, cy instead of clipped
%ILD_DPISCALE      = &H00004000???
'#if _WIN32_WINNT >= 0x0600
%ILD_ASYNC         = &H00008000???
'#endif

%ILD_SELECTED = %ILD_BLEND50
%ILD_FOCUS    = %ILD_BLEND25
%ILD_BLEND    = %ILD_BLEND50
%CLR_HILIGHT  = %CLR_DEFAULT

%ILS_NORMAL   = &H00000000???
%ILS_GLOW     = &H00000001???
%ILS_SHADOW   = &H00000002???
%ILS_SATURATE = &H00000004???
%ILS_ALPHA    = &H00000008???

'#if _WIN32_WINNT >= 0x0600
%ILGT_NORMAL  = &H00000000???
%ILGT_ASYNC   = &H00000001???
'#endif

DECLARE FUNCTION ImageList_Draw IMPORT "COMCTL32.DLL" ALIAS "ImageList_Draw" ( _
   BYVAL himl AS DWORD _                                ' __in IMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYVAL hdcDst AS DWORD _                              ' __in HDC hdcDst
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL fStyle AS DWORD _                              ' __in UINT fStyle
 ) AS LONG                                              ' BOOL

'#if _WIN32_WINNT >= 0x0600
%HBITMAP_CALLBACK = &HFFFFFFFF???      ' ((HBITMAP)-1)       // only for SparseImageList
'#endif

DECLARE FUNCTION ImageList_Replace IMPORT "COMCTL32.DLL" ALIAS "ImageList_Replace" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYVAL hbmImage AS DWORD _                            ' __in HBITMAP hbmImage
 , OPTIONAL BYVAL hbmMask AS DWORD _                    ' __in HBITMAP hbmMask
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_AddMasked IMPORT "COMCTL32.DLL" ALIAS "ImageList_AddMasked" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL hbmImage AS DWORD _                            ' __in HBITMAP hbmImage
 , BYVAL crMask AS DWORD _                              ' __in COLORREF crMask
 ) AS LONG                                              ' int

DECLARE FUNCTION ImageList_DrawEx IMPORT "COMCTL32.DLL" ALIAS "ImageList_DrawEx" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYVAL hdcDst AS DWORD _                              ' __in HDC hdcDst
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 , BYVAL rgbBk AS DWORD _                               ' __in COLORREF rgbBk
 , BYVAL rgbFg AS DWORD _                               ' __in COLORREF rgbFg
 , BYVAL fStyle AS DWORD _                              ' __in UINT fStyle
 ) AS LONG                                              ' BOOL

'#if (_WIN32_IE >= 0x0300)
DECLARE FUNCTION ImageList_DrawIndirect IMPORT "COMCTL32.DLL" ALIAS "ImageList_DrawIndirect" ( _
   BYREF pimldp AS IMAGELISTDRAWPARAMS _                ' __in IMAGELISTDRAWPARAMS* pimldp
 ) AS LONG                                              ' BOOL
'#endif

DECLARE FUNCTION ImageList_Remove IMPORT "COMCTL32.DLL" ALIAS "ImageList_Remove" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_GetIcon IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetIcon" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYVAL flags AS DWORD _                               ' __in UINT flags
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION ImageList_LoadImageA IMPORT "COMCTL32.DLL" ALIAS "ImageList_LoadImageA" ( _
   BYVAL hi AS DWORD _                                  ' __in HINSTANCE hi
 , BYREF lpbmp AS ASCIIZ _                              ' __in LPCSTR lpbmp
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cGrow AS LONG _                                ' __in int cGrow
 , BYVAL crMask AS DWORD _                              ' __in COLORREF crMask
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' HIMAGELIST

DECLARE FUNCTION ImageList_LoadImageW IMPORT "COMCTL32.DLL" ALIAS "ImageList_LoadImageW" ( _
   BYVAL hi AS DWORD _                                  ' __in HINSTANCE hi
 , BYREF lpbmp AS WSTRINGZ _                            ' __in LPCWSTR lpbmp
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cGrow AS LONG _                                ' __in int cGrow
 , BYVAL crMask AS DWORD _                              ' __in COLORREF crMask
 , BYVAL uType AS DWORD _                               ' __in UINT uType
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' HIMAGELIST

#IF %DEF(%UNICODE)
   MACRO ImageList_LoadImage = ImageList_LoadImageW
#ELSE
   MACRO ImageList_LoadImage = ImageList_LoadImageA
#ENDIF

'#if (_WIN32_IE >= 0x0300)

%ILCF_MOVE = &H00000000???
%ILCF_SWAP = &H00000001???

DECLARE FUNCTION ImageList_Copy IMPORT "COMCTL32.DLL" ALIAS "ImageList_Copy" ( _
   BYVAL himlDst AS DWORD _                             ' __in HIMAGELIST himlDst
 , BYVAL iDst AS LONG _                                 ' __in int iDst
 , BYVAL himlSrc AS DWORD _                             ' __in HIMAGELIST himlSrc
 , BYVAL iSrc AS LONG _                                 ' __in int iSrc
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

'#endif

DECLARE FUNCTION ImageList_BeginDrag IMPORT "COMCTL32.DLL" ALIAS "ImageList_BeginDrag" ( _
   BYVAL himlTrack AS DWORD _                           ' __in HIMAGELIST himlTrack
 , BYVAL iTrack AS LONG _                               ' __in int iTrack
 , BYVAL dxHotspot AS LONG _                            ' __in int dxHotspot
 , BYVAL dyHotspot AS LONG _                            ' __in int dyHotspot
 ) AS LONG                                              ' BOOL

DECLARE SUB ImageList_EndDrag IMPORT "COMCTL32.DLL" ALIAS "ImageList_EndDrag" ( _
 )                                                      ' void

DECLARE FUNCTION ImageList_DragEnter IMPORT "COMCTL32.DLL" ALIAS "ImageList_DragEnter" ( _
   BYVAL hWndLock AS DWORD _                            ' __in HWND hWndLock
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_DragLeave IMPORT "COMCTL32.DLL" ALIAS "ImageList_DragLeave" ( _
   BYVAL hWndLock AS DWORD _                            ' __in HWND hWndLock
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_DragMove IMPORT "COMCTL32.DLL" ALIAS "ImageList_DragMove" ( _
   BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_SetDragCursorImage IMPORT "COMCTL32.DLL" ALIAS "ImageList_SetDragCursorImage" ( _
   BYVAL himlDrag AS DWORD _                            ' __in HIMAGELIST himlDrag
 , BYVAL iDrag AS LONG _                                ' __in int iDrag
 , BYVAL dxHotSpot AS LONG _                            ' __in int dxHotSpot
 , BYVAL dyHotSpot AS LONG _                            ' __in int dyHotSpot
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_DragShowNolock IMPORT "COMCTL32.DLL" ALIAS "ImageList_DragShowNolock" ( _
   BYVAL fShow AS LONG _                                ' __in BOOL fShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_GetDragImage IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetDragImage" ( _
   BYREF ppt AS POINT _                                 ' __out POINT *ppt
 , BYREF pptHotspot AS POINT _                          ' __out POINT *pptHotspot
 ) AS DWORD                                             ' HIMAGELIST

MACRO ImageList_RemoveAll(hIml) = ImageList_Remove(hIml,-1)
' Note  The dwhi parameter is unused and must be 0.
MACRO ImageList_ExtractIcon(dwhI, hIml, i) = ImageList_GetIcon(hIml, i, 0)
MACRO ImageList_LoadBitmap(dwhi, lpBmp, cx, cGrow, crMask) = ImageList_LoadImage(dwhi, lpBmp, cx, cGrow, crMask, %IMAGE_BITMAP, 0)

'struct IStream;
#IF %DEF(%IStream_INTERFACE_DEFINED)

DECLARE FUNCTION ImageList_Read IMPORT "COMCTL32.DLL" ALIAS "ImageList_Read" ( _
   BYVAL pstm AS IStream _                              ' __in LPSTREAM pstm
 ) AS DWORD                                             ' HIMAGELIST

DECLARE FUNCTION ImageList_Write IMPORT "COMCTL32.DLL" ALIAS "ImageList_Write" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL pstm AS IStream _                              ' __in LPSTREAM pstm
 ) AS LONG                                              ' BOOL

'#if (_WIN32_WINNT >= 0x0501)
%ILP_NORMAL    = 0 ' Writes or reads the stream using new sematics for this version of comctl32
%ILP_DOWNLEVEL = 1 ' Write or reads the stream using downlevel sematics.

DECLARE FUNCTION ImageList_ReadEx IMPORT "COMCTL32.DLL" ALIAS "ImageList_ReadEx" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pstm AS IStream _                              ' __in LPSTREAM pstm
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __in PVOID* ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ImageList_WriteEx IMPORT "COMCTL32.DLL" ALIAS "ImageList_WriteEx" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pstm AS IStream _                              ' __in LPSTREAM pstm
 ) AS LONG                                              ' HRESULT

'#endif

#ENDIF   ' #IF %DEF(%IStream_INTERFACE_DEFINED)

'#ifndef IMAGEINFO
' // Size = 32 bytes
TYPE IMAGEINFO DWORD
   hbmImage AS DWORD   ' HBITMAP hbmImage
   hbmMask  AS DWORD   ' HBITMAP hbmMask
   Unused1  AS LONG    ' int     Unused1
   Unused2  AS LONG    ' int     Unused2
   rcImage  AS RECT    ' RECT    rcImage
END TYPE
'#endif

DECLARE FUNCTION ImageList_GetIconSize IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetIconSize" (_
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYREF cx AS LONG _                                   ' __out int *cx
 , BYREF cy AS LONG _                                   ' __out int *cy
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_SetIconSize IMPORT "COMCTL32.DLL" ALIAS "ImageList_SetIconSize" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_GetImageInfo IMPORT "COMCTL32.DLL" ALIAS "ImageList_GetImageInfo" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL i AS LONG _                                    ' __in int i
 , BYREF pImageInfo AS IMAGEINFO _                      ' __out IMAGEINFO *pImageInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ImageList_Merge IMPORT "COMCTL32.DLL" ALIAS "ImageList_Merge" ( _
   BYVAL himl1 AS DWORD _                               ' HIMAGELIST himl1
 , BYVAL i1 AS LONG _                                   ' __in int i1
 , BYVAL himl2 AS DWORD _                               ' __in HIMAGELIST himl2
 , BYVAL i2 AS LONG _                                   ' __in int i2
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 ) AS DWORD                                             ' HIMAGELIST

'#if (_WIN32_IE >= 0x0400)
DECLARE FUNCTION ImageList_Duplicate IMPORT "COMCTL32.DLL" ALIAS "ImageList_Duplicate" ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 ) AS DWORD                                             ' HIMAGELIST
'#endif

'#if (_WIN32_WINNT >= 0x0501)
'WINCOMMCTRLAPI HRESULT WINAPI HIMAGELIST_QueryInterface(HIMAGELIST himl, REFIID riid, void** ppv);

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION HIMAGELIST_QueryInterface LIB "ComCtl32.dll" _
    ALIAS "HIMAGELIST_QueryInterface" (BYVAL himl AS DWORD, _
    BYVAL riid AS GUID PTR, ppv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION HIMAGELIST_QueryInterface IMPORT "COMCTL32.DLL" ALIAS "HIMAGELIST_QueryInterface "( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF

' ImageList_SetColorTable is not exported by name or declared in a public header file.
' To use it, you must use GetProcAddress and request ordinal 390 from ComCtl32.dll
' to obtain a function pointer.
FUNCTION ImageList_SetColorTable ( _
   BYVAL himl AS DWORD _                                ' __in HIMAGELIST himl
 , BYVAL nStart AS LONG _                               ' __in int start
 , BYVAL nLen AS LONG _                                 ' __in int len
 , BYREF prgb AS RGBQUAD _                              ' __in RGBQUAD *prgb
 ) AS LONG                                              ' int

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 390, 0))
   IF pProc THEN CALL DWORD pProc USING ImageList_SetColorTable(himl, nStart, nLen, prgb) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'#ifdef __cplusplus
'FORCEINLINE HIMAGELIST IImageListToHIMAGELIST(struct IImageList *himl)
'{
'    return reinterpret_cast<HIMAGELIST>(himl);
'}
'#else
'#define IImageListToHIMAGELIST(himl) ((HIMAGELIST)(himl))
'#endif

' Note: This inline macro casts an interface pointer to a dword handle
' With PowerBASIC, simply use the built-in OBJPTR function.

#ENDIF   ' // NOIMAGELIST


'//====== HEADER CONTROL =======================================================

#IF NOT %DEF(%NOHEADER)

$WC_HEADERA              = "SysHeader32"
$$WC_HEADERW             = "SysHeader32"$$
#IF %DEF(%UNICODE)
   MACRO WC_HEADER = $$WC_HEADERW
#ELSE
   MACRO WC_HEADER = $WC_HEADERA
#ENDIF ' #IF %DEF(%UNICODE)

'%HDS_HORZ        = &H0000???
'%HDS_BUTTONS     = &H0002???
'#if (_WIN32_IE >= 0x0300)
'%HDS_HOTTRACK    = &H0004???
'#endif
%HDS_HIDDEN      = &H0008???

'#if (_WIN32_IE >= 0x0300)
'%HDS_DRAGDROP    = &H0040???
'%HDS_FULLDRAG    = &H0080???
'#endif
'#if (_WIN32_IE >= 0x0500)
'%HDS_FILTERBAR   = &H0100???
'#endif

'#if (_WIN32_WINNT >= 0x501)
'%HDS_FLAT        = &H0200???
'#endif

'#if _WIN32_WINNT >= 0x0600
%HDS_CHECKBOXES  = &H0400???
%HDS_NOSIZING    = &H0800???
%HDS_OVERFLOW    = &H1000???
'#endif

'#if (_WIN32_IE >= 0x0500)

%HDFT_ISSTRING   = &H0000???  ' // HD_ITEM.pvFilter points to a HD_TEXTFILTER
%HDFT_ISNUMBER   = &H0001???  ' // HD_ITEM.pvFilter points to a INT
%HDFT_ISDATE     = &H0002???  ' // HD_ITEM.pvFilter points to a DWORD (dos date)

%HDFT_HASNOVALUE = &H8000???  ' // clear the filter, by setting this bit

' // Size = 8 bytes
TYPE HD_TEXTFILTERA DWORD
   pszText    AS ASCIIZ PTR  ' LPSTR pszText  // [in] pointer to the buffer containing the filter (ANSI)
   cchTextMax AS LONG        ' INT cchTextMax // [in] max size of buffer/edit control buffer
END TYPE

' // Size = 8 bytes
TYPE HD_TEXTFILTERW DWORD
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText // [in] pointer to the buffer containing the filter (ANSI)
   cchTextMax AS LONG           ' INT cchTextMax // [in] max size of buffer/edit control buffer
END TYPE

MACRO HDTEXTFILTERA = HD_TEXTFILTERA
MACRO HDTEXTFILTERW = HD_TEXTFILTERW

#IF %DEF(%UNICODE)
   MACRO HDTEXTFILTER  = HD_TEXTFILTERW
   MACRO HD_TEXTFILTER = HD_TEXTFILTERW
#ELSE
   MACRO HDTEXTFILTER  = HD_TEXTFILTERA
   MACRO HD_TEXTFILTER = HD_TEXTFILTERA
#ENDIF

'#endif  // _WIN32_IE >= 0x0500

UNION HD_ITEM_TYPE_UNION
   type       AS DWORD        ' UINT    type      // [in] filter type (defined what pvFilter is a pointer to)
   ' // For compatibility with the PB includes
   dtype      AS DWORD        ' UINT    type      // [in] filter type (defined what pvFilter is a pointer to)
END UNION

' // Size = 48 bytes
TYPE HD_ITEMA DWORD
   Mask       AS DWORD        ' UINT    mask
   cxy        AS LONG         ' int     cxy
   pszText    AS ASCIIZ PTR   ' LPSTR   pszText
   hbm        AS DWORD        ' HBITMAP hbm
   cchTextMax AS LONG         ' int     cchTextMax
   fmt        AS LONG         ' int     fmt
   lParam     AS LONG         ' LPARAM  lParam
#IF (%WIN32_IE >= &H0300)
   iImage     AS LONG         ' int     iImage  // index of bitmap in ImageList
   iOrder     AS LONG         ' int     iOrder  // where to draw this item
#ENDIF
#IF (%WIN32_IE >= &H0500)
   HD_ITEM_TYPE_UNION
   pvFilter   AS DWORD        ' void *  pvFilter  // [in] fillter data see above
#ENDIF
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   state      AS DWORD
#ENDIF
END TYPE

TYPE HD_ITEMW DWORD
   Mask       AS DWORD           ' UINT    mask
   cxy        AS LONG            ' int     cxy
   pszText    AS WSTRINGZ PTR    ' LPWSTR   pszText
   hbm        AS DWORD           ' HBITMAP hbm
   cchTextMax AS LONG            ' int     cchTextMax
   fmt        AS LONG            ' int     fmt
   lParam     AS LONG            ' LPARAM  lParam
#IF (%WIN32_IE >= &H0300)
   iImage     AS LONG            ' int     iImage  // index of bitmap in ImageList
   iOrder     AS LONG            ' int     iOrder  // where to draw this item
#ENDIF
#IF (%WIN32_IE >= &H0500)
   HD_ITEM_TYPE_UNION
   pvFilter   AS DWORD           ' void *  pvFilter  // [in] fillter data see above
#ENDIF
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   state      AS DWORD
#ENDIF
END TYPE

MACRO HDITEMA = HD_ITEMA
MACRO HDITEMW = HD_ITEMW

#IF %DEF(%UNICODE)
   MACRO HD_ITEM = HD_ITEMW
   MACRO HDITEM  = HD_ITEMW
#ELSE
   MACRO HD_ITEM = HD_ITEMA
   MACRO HDITEM  = HD_ITEMA
#ENDIF

'%HDI_WIDTH            = &H0001???
%HDI_HEIGHT           = %HDI_WIDTH
'%HDI_TEXT             = &H0002???
'%HDI_FORMAT           = &H0004???
'%HDI_LPARAM           = &H0008???
'%HDI_BITMAP           = &H0010???
'#if (_WIN32_IE >= 0x0300)
'%HDI_IMAGE            = &H0020???
'%HDI_DI_SETITEM       = &H0040???
'%HDI_ORDER            = &H0080???
'#endif
'#if (_WIN32_IE >= 0x0500)
'%HDI_FILTER           = &H0100???
'#endif
'#if _WIN32_WINNT >= 0x0600
%HDI_STATE            = &H0200???
'#endif

'// HDF_ flags are shared with the listview control (LVCFMT_ flags)

'%HDF_LEFT             = &H0000???
'%HDF_RIGHT            = &H0001???
'%HDF_CENTER           = &H0002???
'%HDF_JUSTIFYMASK      = &H0003???
'%HDF_RTLREADING       = &H0004???

'%HDF_BITMAP           = &H2000???
'%HDF_STRING           = &H4000???
'%HDF_OWNERDRAW        = &H8000???   ' // Same as LVCFMT_COL_HAS_IMAGES
'#if (_WIN32_IE >= 0x0300)
'%HDF_IMAGE            = &H0800???   ' // Same as LVCFMT_IMAGE
'%HDF_BITMAP_ON_RIGHT  = &H1000???   ' // Same as LVCFMT_BITMAP_ON_RIGHT
'#endif

'#if (_WIN32_WINNT >= 0x501)
'%HDF_SORTUP           = &H0400???
'%HDF_SORTDOWN         = &H0200???
'#endif

'#if _WIN32_WINNT >= 0x0600
%HDF_CHECKBOX         = &H0040???
%HDF_CHECKED          = &H0080???
%HDF_FIXEDWIDTH       = &H0100???      ' // Can't resize the column; same as LVCFMT_FIXED_WIDTH
%HDF_SPLITBUTTON      = &H1000000???   ' // Column is a split button; same as LVCFMT_SPLITBUTTON
'#endif

'#if _WIN32_WINNT >= 0x0600
%HDIS_FOCUSED         = &H00000001???
'#endif

'#define HDM_GETITEMCOUNT        (HDM_FIRST + 0)
'%HDM_GETITEMCOUNT        = %HDM_FIRST + 0
'#define Header_GetItemCount(hwndHD) \
'    (int)SNDMSG((hwndHD), HDM_GETITEMCOUNT, 0, 0L)

' // HDM_INSERTITEMA and HDM_INSERTITEMW are predefined in the compiler, but
' // HDM_INSERTITEMA is called HDM_INSERTITEM, so we need to redefine it.
%HDM_INSERTITEMA         = %HDM_FIRST + 1
%HDM_INSERTITEMW         = %HDM_FIRST + 10

#IF %DEF(%UNICODE)
%HDM_INSERTITEM = %HDM_INSERTITEMW
#ELSE
%HDM_INSERTITEM = %HDM_INSERTITEMA
#ENDIF

'%HDM_DELETEITEM          = %HDM_FIRST + 2

' // HDM_GETITEMA and HDM_GETITEMW are predefined in the compile, but
' // HDM_GETITEMA is called HDM_GETITEM, so we need to redefine it.
%HDM_GETITEMA            = %HDM_FIRST + 3
%HDM_GETITEMW            = %HDM_FIRST + 11

#IF %DEF(%UNICODE)
%HDM_GETITEM = %HDM_GETITEMW
#ELSE
%HDM_GETITEM = %HDM_GETITEMA
#ENDIF

' // HDM_SETITEMA and HDM_SETITEMW are predefined in the compile, but
' // HDM_SETITEMA is called HDM_SETITEM, so we need to redefine it.
%HDM_SETITEMA            = %HDM_FIRST + 4
%HDM_SETITEMW            = %HDM_FIRST + 12

#IF %DEF(%UNICODE)
%HDM_SETITEM = %HDM_SETITEMW
#ELSE
%HDM_SETITEM = %HDM_SETITEMA
#ENDIF

' // Size = 8 bytes
TYPE HD_LAYOUT DWORD
   prc   AS RECT PTR        ' RECT *prc
   pwpos AS WINDOWPOS PTR   ' WINDOWPOS *pwpos
END TYPE

MACRO HDLAYOUT = HD_LAYOUT

'%HDM_LAYOUT              = %HDM_FIRST + 5

'%HHT_NOWHERE         = &H0001???
'%HHT_ONHEADER        = &H0002???
'%HHT_ONDIVIDER       = &H0004???
'%HHT_ONDIVOPEN       = &H0008???
'#if (_WIN32_IE >= 0x0500)
'%HHT_ONFILTER        = &H0010???
'%HHT_ONFILTERBUTTON  = &H0020???
'#endif
'%HHT_ABOVE           = &H0100???
'%HHT_BELOW           = &H0200???
'%HHT_TORIGHT         = &H0400???
'%HHT_TOLEFT          = &H0800???
'#if _WIN32_WINNT >= 0x0600
%HHT_ONITEMSTATEICON = &H1000???
%HHT_ONDROPDOWN      = &H2000???
%HHT_ONOVERFLOW      = &H4000???
'#endif

' // Size = 16 bytes
TYPE HD_HITTESTINFO
   pt    AS POINT   ' POINT pt
   flags AS DWORD   ' UINT flags
   iItem AS LONG    ' int iItem
END TYPE

MACRO HDHITTESTINFO = HD_HITTESTINFO

%HDSIL_NORMAL            = 0
%HDSIL_STATE             = 1

'%HDM_HITTEST             = %HDM_FIRST + 6

'#if (_WIN32_IE >= 0x0300)

'%HDM_GETITEMRECT         = %HDM_FIRST + 7
'%HDM_SETIMAGELIST        = %HDM_FIRST + 8
'%HDM_GETIMAGELIST        = %HDM_FIRST + 9
'%HDM_ORDERTOINDEX        = %HDM_FIRST + 15
'%HDM_CREATEDRAGIMAGE     = %HDM_FIRST + 16  ' wparam = which item (by index)
'%HDM_GETORDERARRAY       = %HDM_FIRST + 17
'%HDM_SETORDERARRAY       = %HDM_FIRST + 18

'// lparam = int array of size HDM_GETITEMCOUNT
'// the array specifies the order that all items should be displayed.
'// e.g.  { 2, 0, 1}
'// says the index 2 item should be shown in the 0ths position
'//      index 0 should be shown in the 1st position
'//      index 1 should be shown in the 2nd position

'%HDM_SETHOTDIVIDER       = %HDM_FIRST + 19

'// convenience message for external dragdrop
'// wParam = BOOL  specifying whether the lParam is a dwPos of the cursor
'//              position or the index of which divider to hotlight
'// lParam = depends on wParam  (-1 and wParm = FALSE turns off hotlight)
'#endif      // _WIN32_IE >= 0x0300

'#if (_WIN32_IE >= 0x0500)

'%HDM_SETBITMAPMARGIN     = %HDM_FIRST + 20
'%HDM_GETBITMAPMARGIN     = %HDM_FIRST + 21

'#endif


'#if (_WIN32_IE >= 0x0400)

'%HDM_SETUNICODEFORMAT    = %CCM_SETUNICODEFORMAT
'%HDM_GETUNICODEFORMAT    = %CCM_GETUNICODEFORMAT

'#endif

'#if (_WIN32_IE >= 0x0500)

'%HDM_SETFILTERCHANGETIMEOUT = %HDM_FIRST + 22
'%HDM_EDITFILTER             = %HDM_FIRST + 23

'// Clear filter takes -1 as a column value to indicate that all
'// the filter should be cleared.  When this happens you will
'// only receive a single filter changed notification.

'%HDM_CLEARFILTER            = %HDM_FIRST + 24

'#if (_WIN32_IE >= 0x0600)
' Not implemented.
'%HDM_TRANSLATEACCELERATOR    = %CCM_TRANSLATEACCELERATOR
'#endif

'#if (_WIN32_WINNT >= 0x600)

%HDM_GETITEMDROPDOWNRECT = %HDM_FIRST + 25   ' // rect of item's drop down button
%HDM_GETOVERFLOWRECT     = %HDM_FIRST + 26   ' // rect of overflow button
%HDM_GETFOCUSEDITEM      = %HDM_FIRST + 27
%HDM_SETFOCUSEDITEM      = %HDM_FIRST + 28

'#endif // _WIN32_WINNT >= 0x600

'#endif

' // HDN_ITEMCHANGINGA and HDN_ITEMCHANGINGW are predefined in the compiler, but
' // HDN_ITEMCHANGINGA is called HDN_ITEMCHANGING, so we need to redefine it.
%HDN_ITEMCHANGINGA       = %HDN_FIRST - 0
%HDN_ITEMCHANGINGW       = %HDN_FIRST - 20
#IF %DEF(%UNICODE)
%HDN_ITEMCHANGING = %HDN_ITEMCHANGINGW
#ELSE
%HDN_ITEMCHANGING = %HDN_ITEMCHANGINGA
#ENDIF
' // HDN_ITEMCHANGEDA and HDN_ITEMCHANGEDW are predefined in the compiler, but
' // HDN_ITEMCHANGEDA is called HDN_ITEMCHANGED, so we need to redefine it.
%HDN_ITEMCHANGEDA        = %HDN_FIRST - 1
%HDN_ITEMCHANGEDW        = %HDN_FIRST - 21
#IF %DEF(%UNICODE)
%HDN_ITEMCHANGED = %HDN_ITEMCHANGEDW
#ELSE
%HDN_ITEMCHANGED = %HDN_ITEMCHANGEDA
#ENDIF
' // HDN_ITEMCLICKA and HDN_ITEMCLICKW are predefined in the compiler, but
' // HDN_ITEMCLICKA is called HDN_ITEMCLICK, so we need to redefine it.
%HDN_ITEMCLICKA          = %HDN_FIRST - 2
%HDN_ITEMCLICKW          = %HDN_FIRST - 22
#IF %DEF(%UNICODE)
%HDN_ITEMCLICK = %HDN_ITEMCLICKW
#ELSE
%HDN_ITEMCLICK = %HDN_ITEMCLICKA
#ENDIF
' // HDN_ITEMDBLCLICKA and HDN_ITEMDBLCLICKW are predefined in the compiler, but
' // HDN_ITEMDBLCLICKA is called HDN_ITEMDBLCLICK, so we need to redefine it.
%HDN_ITEMDBLCLICKA       = %HDN_FIRST - 3
%HDN_ITEMDBLCLICKW       = %HDN_FIRST - 23
#IF %DEF(%UNICODE)
%HDN_ITEMDBLCLICK = %HDN_ITEMDBLCLICKW
#ELSE
%HDN_ITEMDBLCLICK = %HDN_ITEMDBLCLICKA
#ENDIF
' // HDN_DIVIDERDBLCLICKA and HDN_DIVIDERDBLCLICKW are predefined in the compiler, but
' // HDN_DIVIDERDBLCLICKA is called HDN_DIVIDERDBLCLICK, so we need to redefine it.
%HDN_DIVIDERDBLCLICKA    = %HDN_FIRST - 5
%HDN_DIVIDERDBLCLICKW    = %HDN_FIRST - 25
#IF %DEF(%UNICODE)
%HDN_DIVIDERDBLCLICK = %HDN_DIVIDERDBLCLICKW
#ELSE
%HDN_DIVIDERDBLCLICK = %HDN_DIVIDERDBLCLICKA
#ENDIF
' // HDN_BEGINTRACKA and HDN_BEGINTRACKW are predefined in the compiler, but
' // HDN_BEGINTRACKA is called HDN_BEGINTRACK, so we need to redefine it.
%HDN_BEGINTRACKA         = %HDN_FIRST - 6
%HDN_BEGINTRACKW         = %HDN_FIRST - 26
#IF %DEF(%UNICODE)
%HDN_BEGINTRACK = %HDN_BEGINTRACKW
#ELSE
%HDN_BEGINTRACK = %HDN_BEGINTRACKA
#ENDIF
' // HDN_ENDTRACKA and HDN_ENDTRACKW are predefined in the compiler, but
' // HDN_ENDTRACKA is called HDN_ENDTRACK, so we need to redefine it.
%HDN_ENDTRACKA           = %HDN_FIRST - 7
%HDN_ENDTRACKW           = %HDN_FIRST - 27
#IF %DEF(%UNICODE)
%HDN_ENDTRACK = %HDN_ENDTRACKW
#ELSE
%HDN_ENDTRACK = %HDN_ENDTRACKA
#ENDIF
' // HDN_TRACKA and HDN_TRACKW are predefined in the compiler, but
' // HDN_TRACKA is called HDN_TRACK, so we need to redefine it.
%HDN_TRACKA              = %HDN_FIRST - 8
%HDN_TRACKW              = %HDN_FIRST - 28
#IF %DEF(%UNICODE)
%HDN_TRACK = %HDN_TRACKW
#ELSE
%HDN_TRACK = %HDN_TRACKA
#ENDIF
'#if (_WIN32_IE >= 0x0300)
' // HDN_GETDISPINFOA and HDN_GETDISPINFOW are predefined in the compiler, but
' // HDN_GETDISPINFOA is called HDN_GETDISPINFO, so we need to redefine it.
%HDN_GETDISPINFOA        = %HDN_FIRST - 9
%HDN_GETDISPINFOW        = %HDN_FIRST - 29
#IF %DEF(%UNICODE)
%HDN_GETDISPINFO = %HDN_GETDISPINFOW
#ELSE
%HDN_GETDISPINFO = %HDN_GETDISPINFOA
#ENDIF
'%HDN_BEGINDRAG           = %HDN_FIRST - 10
'%HDN_ENDDRAG             = %HDN_FIRST - 11
'#endif
'#if (_WIN32_IE >= 0x0500)
'%HDN_FILTERCHANGE        = %HDN_FIRST - 12
'%HDN_FILTERBTNCLICK      = %HDN_FIRST - 13
'#endif

'#if (_WIN32_IE >= 0x0600)
%HDN_BEGINFILTEREDIT     = %HDN_FIRST - 14
%HDN_ENDFILTEREDIT       = %HDN_FIRST - 15
'#endif

'#if _WIN32_WINNT >= 0x0600
%HDN_ITEMSTATEICONCLICK  = %HDN_FIRST - 16
%HDN_ITEMKEYDOWN         = %HDN_FIRST - 17
%HDN_DROPDOWN            = %HDN_FIRST - 18
%HDN_OVERFLOWCLICK       = %HDN_FIRST - 19
'#endif

' // Size = 24 bytes
TYPE NMHEADERA DWORD
   hdr     AS NMHDR           ' NMHDR   hdr
   iItem   AS LONG            ' int     iItem
   iButton AS LONG            ' int     iButton
   pitem   AS HDITEMA PTR     ' HDITEMA *pitem
END TYPE

' // Size = 24 bytes
TYPE NMHEADERW DWORD
   hdr     AS NMHDR           ' NMHDR   hdr
   iItem   AS LONG            ' int     iItem
   iButton AS LONG            ' int     iButton
   pitem   AS HDITEMW PTR     ' HDITEMW *pitem
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMHEADER = NMHEADERW
#ELSE
   MACRO NMHEADER = NMHEADERA
#ENDIF

' // Size = 24 bytes
TYPE HD_NOTIFYA DWORD
   hdr     AS NMHDR           ' NMHDR   hdr
   iItem   AS LONG            ' int     iItem
   iButton AS LONG            ' int     iButton
   pitem   AS HDITEMA PTR     ' HDITEMA *pitem
END TYPE

' // Size = 24 bytes
TYPE HD_NOTIFYW
   hdr     AS NMHDR           ' NMHDR   hdr
   iItem   AS LONG            ' int     iItem
   iButton AS LONG            ' int     iButton
   pitem   AS HDITEMW PTR     ' HDITEMW *pitem
END TYPE

MACRO HDNOTIFYA = HD_NOTIFYA
MACRO HDNOTIFYW = HD_NOTIFYW

#IF %DEF(%UNICODE)
   MACRO HDNOTIFY  = HD_NOTIFYW
   MACRO HD_NOTIFY = HD_NOTIFYW
#ELSE
   MACRO HDNOTIFY  = HD_NOTIFYA
   MACRO HD_NOTIFY = HD_NOTIFYA
#ENDIF

' // Size = 36 bytes
TYPE NMHDDISPINFOA DWORD
   hdr        AS NMHDR        ' NMHDR   hdr
   iItem      AS LONG         ' int     iItem
   mask       AS DWORD        ' UINT    mask
   pszText    AS ASCIIZ PTR   ' LPSTR   pszText
   cchTextMax AS LONG         ' int     cchTextMax
   iImage     AS LONG         ' int     iImage
   lParam     AS LONG         ' LPARAM  lParam
END TYPE

' // Size = 36 bytes
TYPE NMHDDISPINFOW DWORD
   hdr        AS NMHDR         ' NMHDR   hdr
   iItem      AS LONG          ' int     iItem
   mask       AS DWORD         ' UINT    mask
   pszText    AS WSTRINGZ PTR  ' LPWSTR  pszText
   cchTextMax AS LONG          ' int     cchTextMax
   iImage     AS LONG          ' int     iImage
   lParam     AS LONG          ' LPARAM  lParam
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMHDDISPINFO = NMHDDISPINFOW
#ELSE
   MACRO NMHDDISPINFO = NMHDDISPINFOA
#ENDIF

'#if (_WIN32_IE >= 0x0500)
' // Size = 32 bytes
TYPE NMHDFILTERBTNCLICK DWORD
   hdr   AS NMHDR   ' NMHDR hdr
   iItem AS LONG    ' INT iItem
   rc    AS RECT    ' RECT rc
END TYPE
'#endif

#ENDIF    ' // NOHEADER


'//====== TOOLBAR CONTROL ======================================================

#IF NOT %DEF(%NOTOOLBAR)

$TOOLBARCLASSNAMEA      = "ToolbarWindow32"
$$TOOLBARCLASSNAMEW     = "ToolbarWindow32"$$
#IF %DEF(%UNICODE)
   MACRO TOOLBARCLASSNAME = $$TOOLBARCLASSNAMEW
#ELSE
   MACRO TOOLBARCLASSNAME = $TOOLBARCLASSNAMEA
#ENDIF

#IF NOT %DEF(%TBBUTTON_DEFINED)
%TBBUTTON_DEFINED = 1
' // Size = 20 bytes
TYPE TBBUTTON BYTE
   iBitmap        AS LONG         ' int iBitmap
   idCommand      AS LONG         ' int idCommand
   fsState        AS BYTE         ' BYTE fsState
   fsStyle        AS BYTE         ' BYTE fsStyle
'#ifdef _WIN64
'   bReserved (5) AS BYTE         ' BYTE bReserved[6] // padding for alignment
'#elif defined(_WIN32)
   bReserved (1)  AS BYTE         ' BYTE bReserved[2] // padding for alignment
'#endif
   dwData         AS DWORD        ' DWORD_PTR dwData
   iString        AS DWORD        ' INT_PTR iString
END TYPE
#ENDIF

#IF NOT %DEF(%COLORMAP_DEFINED)
%COLORMAP_DEFINED = 1
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_0 DWORD   ' As defined in old PB include files
   cmFrom AS DWORD   ' COLORREF from
   cmTo   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_I DWORD   ' As defined in PB include files
   nfrom AS DWORD   ' COLORREF from
   nto   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_II DWORD
   from AS DWORD   ' COLORREF from
   to   AS DWORD   ' COLORREF to
END TYPE
' // Size = 8 bytes
TYPE COLORMAP_STRUCT_III DWORD  ' For compatibility with GDI+
   oldColor AS DWORD   ' COLORREF oldColor
   newColor AS DWORD   ' COLORREF newColor
END TYPE
' // To allow to use both nfrom, nto and from, to
' // Size = 8 bytes
UNION COLORMAP DWORD
   COLORMAP_STRUCT_0
   COLORMAP_STRUCT_I
   COLORMAP_STRUCT_II
   COLORMAP_STRUCT_III
END UNION
#ENDIF

DECLARE FUNCTION CreateToolbarEx IMPORT "COMCTL32.DLL" ALIAS "CreateToolbarEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL ws AS DWORD _                                  ' __in DWORD ws
 , BYVAL wID AS WORD _                                  ' __in UINT wID
 , BYVAL nBitmaps AS LONG _                             ' __in int nBitmaps
 , BYVAL hBMInst AS DWORD _                             ' __in HINSTANCE hBMInst
 , BYVAL wBMID AS DWORD _                               ' __in UINT_PTR wBMID
 , BYREF lpButtons AS TBBUTTON _                        ' __in LPCTBBUTTON lpButtons
 , BYVAL iNumButtons AS LONG _                          ' __in int iNumButtons
 , BYVAL dxButton AS LONG _                             ' __in int dxButton
 , BYVAL dyButton AS LONG _                             ' __in int dyButton
 , BYVAL dxBitmap AS LONG _                             ' __in int dxBitmap
 , BYVAL dyBitmap AS LONG _                             ' __in int dyBitmap
 , BYVAL uStructSize AS DWORD _                         ' __in UINT uStructSize
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateMappedBitmap IMPORT "COMCTL32.DLL" ALIAS "CreateMappedBitmap" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL idBitmap AS DWORD _                            ' __in INT_PTR idBitmap
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 , BYREF lpColorMap AS COLORMAP _                       ' __in LPCOLORMAP lpColorMap
 , BYVAL iNumMaps AS LONG _                             ' __in int iNumMaps
 ) AS DWORD                                             ' HBITMAP

%CMB_MASKED             = &H02???

'%TBSTATE_CHECKED        = &H01?
'%TBSTATE_PRESSED        = &H02?
'%TBSTATE_ENABLED        = &H04?
'%TBSTATE_HIDDEN         = &H08?
'%TBSTATE_INDETERMINATE  = &H10?
'%TBSTATE_WRAP           = &H20?
'#if (_WIN32_IE >= 0x0300)
'%TBSTATE_ELLIPSES       = &H40?
'#endif
'#if (_WIN32_IE >= 0x0400)
'%TBSTATE_MARKED         = &H80?
'#endif

'%TBSTYLE_BUTTON         = &H0000?
'%TBSTYLE_SEP            = &H0001?
'%TBSTYLE_CHECK          = &H0002?
'%TBSTYLE_GROUP          = &H0004?
'%TBSTYLE_CHECKGROUP     = %TBSTYLE_GROUP OR %TBSTYLE_CHECK
'#if (_WIN32_IE >= 0x0300)
'%TBSTYLE_DROPDOWN       = &H0008?
'#if (_WIN32_IE >= 0x0400)
'#if (_WIN32_IE >= 0x0400)
'%TBSTYLE_AUTOSIZE       = &H0010? ' automatically calculate the cx of the button
'%TBSTYLE_NOPREFIX       = &H0020? ' if this button should not have accel prefix
'#endif

'%TBSTYLE_TOOLTIPS        = &H00000100???
'%TBSTYLE_WRAPABLE        = &H00000200???
'%TBSTYLE_ALTDRAG         = &H00000400???
'#if (_WIN32_IE >= 0x0300)
'%TBSTYLE_FLAT            = &H00000800???
'%TBSTYLE_LIST            = &H00001000???
'%TBSTYLE_CUSTOMERASE     = &H00002000???
'#endif
'#if (_WIN32_IE >= 0x0400)
'%TBSTYLE_REGISTERDROP    = &H00004000???
'%TBSTYLE_TRANSPARENT     = &H00008000???
'%TBSTYLE_EX_DRAWDDARROWS = &H00000001???
'#endif

'#if (_WIN32_IE >= 0x0500)
'%BTNS_BUTTON        = %TBSTYLE_BUTTON      ' &H0000
'%BTNS_SEP           = %TBSTYLE_SEP         ' &H0001
'%BTNS_CHECK         = %TBSTYLE_CHECK       ' &H0002
'%BTNS_GROUP         = %TBSTYLE_GROUP       ' &H0004
'%BTNS_CHECKGROUP    = %TBSTYLE_CHECKGROUP  ' (%TBSTYLE_GROUP OR %TBSTYLE_CHECK)
'%BTNS_DROPDOWN      = %TBSTYLE_DROPDOWN    ' &H0008
'%BTNS_AUTOSIZE      = %TBSTYLE_AUTOSIZE    ' &H0010; automatically calculate the cx of the button
'%BTNS_NOPREFIX      = %TBSTYLE_NOPREFIX    ' &H0020; this button should not have accel prefix
'#if (_WIN32_IE >= 0x0501)
'%BTNS_SHOWTEXT      = &H0040?              ' ignored unless %TBSTYLE_EX_MIXEDBUTTONS is set
'#endif  // 0x0501
'%BTNS_WHOLEDROPDOWN = &H0080?              ' draw drop-down arrow, but without split arrow section

'#if (_WIN32_IE >= 0x0501)
'%TBSTYLE_EX_MIXEDBUTTONS       = &H00000008???
'%TBSTYLE_EX_HIDECLIPPEDBUTTONS = &H00000010??? ' don't show partially obscured buttons
'#endif  // 0x0501

'#if (_WIN32_WINNT >= 0x501)
'%TBSTYLE_EX_DOUBLEBUFFER       = &H00000080??? ' Double Buffer the toolbar
'#endif

'#if (_WIN32_IE >= 0x0400)
'// Custom Draw Structure
' // Size = 112 bytes
TYPE NMTBCUSTOMDRAW
   nmcd                 AS NMCUSTOMDRAW   ' NMCUSTOMDRAW nmcd
   hbrMonoDither        AS DWORD          ' HBRUSH hbrMonoDither
   hbrLines             AS DWORD          ' HBRUSH hbrLines                // For drawing lines on buttons
   hpenLines            AS DWORD          ' HPEN hpenLines                 // For drawing lines on buttons
   clrText              AS DWORD          ' COLORREF clrText               // Color of text
   clrMark              AS DWORD          ' COLORREF clrMark               // Color of text bk when marked. (only if TBSTATE_MARKED)
   clrTextHighlight     AS DWORD          ' COLORREF clrTextHighlight      // Color of text when highlighted
   clrBtnFace           AS DWORD          ' COLORREF clrBtnFace            // Background of the button
   clrBtnHighlight      AS DWORD          ' COLORREF clrBtnHighlight       // 3D highlight
   clrHighlightHotTrack AS DWORD          ' COLORREF clrHighlightHotTrack  // In conjunction with fHighlightHotTrack
                                          '                                // will cause button to highlight like a menu
   rcText               AS RECT           ' RECT rcText                    // Rect for text
   nStringBkMode        AS LONG           ' int nStringBkMode
   nHLStringBkMode      AS LONG           ' int nHLStringBkMode
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   iListGap             AS LONG           ' int iListGap
#ENDIF
END TYPE

'// Toolbar custom draw return flags
%TBCDRF_NOEDGES        = &H00010000??? ' // Don't draw button edges
%TBCDRF_HILITEHOTTRACK = &H00020000??? ' // Use color of the button bk when hottracked
%TBCDRF_NOOFFSET       = &H00040000??? ' // Don't offset button if pressed
%TBCDRF_NOMARK         = &H00080000??? ' // Don't draw default highlight of image/text for TBSTATE_MARKED
%TBCDRF_NOETCHEDEFFECT = &H00100000??? ' // Don't draw etched effect for disabled items
'#endif

'#if (_WIN32_IE >= 0x0500)
%TBCDRF_BLENDICON      = &H00200000??? ' // Use ILD_BLEND50 on the icon image
%TBCDRF_NOBACKGROUND   = &H00400000??? ' // Use ILD_BLEND50 on the icon image
'#endif
'#if _WIN32_WINNT >= 0x0600
%TBCDRF_USECDCOLORS    = &H00800000??? ' // Use CustomDrawColors to RenderText regardless of VisualStyle
'#endif

'%TB_ENABLEBUTTON             = %WM_USER + 1
'%TB_CHECKBUTTON              = %WM_USER + 2
'%TB_PRESSBUTTON              = %WM_USER + 3
'%TB_HIDEBUTTON               = %WM_USER + 4
'%TB_INDETERMINATE            = %WM_USER + 5
'#if (_WIN32_IE >= 0x0400)
'%TB_MARKBUTTON               = %WM_USER + 6
'#endif
'%TB_ISBUTTONENABLED          = %WM_USER + 9
'%TB_ISBUTTONCHECKED          = %WM_USER + 10
'%TB_ISBUTTONPRESSED          = %WM_USER + 11
'%TB_ISBUTTONHIDDEN           = %WM_USER + 12
'%TB_ISBUTTONINDETERMINATE    = %WM_USER + 13
'#if (_WIN32_IE >= 0x0400)
%TB_ISBUTTONHIGHLIGHTED      = %WM_USER + 14
'#endif
'%TB_SETSTATE                 = %WM_USER + 17
'%TB_GETSTATE                 = %WM_USER + 18
%TB_ADDBITMAP                = %WM_USER + 19

'#ifdef _WIN32
' // Size = 8 bytes
TYPE TBADDBITMAP DWORD
   hInst AS DWORD   ' HINSTANCE       hInst
   nID   AS DWORD   ' UINT_PTR        nID
END TYPE

%HINST_COMMCTRL          = &HFFFFFFFF??? ' ((HINSTANCE)-1)
%IDB_STD_SMALL_COLOR     = 0
%IDB_STD_LARGE_COLOR     = 1
%IDB_VIEW_SMALL_COLOR    = 4
%IDB_VIEW_LARGE_COLOR    = 5
'#if (_WIN32_IE >= 0x0300)
%IDB_HIST_SMALL_COLOR    = 8
%IDB_HIST_LARGE_COLOR    = 9
'#endif
'#if (_WIN32_WINNT >= 0x600)
%IDB_HIST_NORMAL         = 12
%IDB_HIST_HOT            = 13
%IDB_HIST_DISABLED       = 14
%IDB_HIST_PRESSED        = 15
'#endif // _WIN32_WINNT >= 0x600

'// icon indexes for standard bitmap

%STD_CUT         = 0
%STD_COPY        = 1
%STD_PASTE       = 2
%STD_UNDO        = 3
%STD_REDOW       = 4
%STD_DELETE      = 5
%STD_FILENEW     = 6
%STD_FILEOPEN    = 7
%STD_FILESAVE    = 8
%STD_PRINTPRE    = 9
%STD_PROPERTIES  = 10
%STD_HELP        = 11
%STD_FIND        = 12
%STD_REPLACE     = 13
%STD_PRINT       = 14

'// icon indexes for standard view bitmap

%VIEW_LARGEICONS     = 0
%VIEW_SMALLICONS     = 1
%VIEW_LIST           = 2
%VIEW_DETAILS        = 3
%VIEW_SORTNAME       = 4
%VIEW_SORTSIZE       = 5
%VIEW_SORTDATE       = 6
%VIEW_SORTTYPE       = 7
%VIEW_PARENTFOLDER   = 8
%VIEW_NETCONNECT     = 9
%VIEW_NETDISCONNECT  = 10
%VIEW_NEWFOLDER      = 11
'#if (_WIN32_IE >= 0x0400)
%VIEW_VIEWMENU       = 12
'#endif

'#if (_WIN32_IE >= 0x0300)
%HIST_BACK           = 0
%HIST_FORWARD        = 1
%HIST_FAVORITES      = 2
%HIST_ADDTOFAVORITES = 3
%HIST_VIEWTREE       = 4
'#endif

'#endif

%TB_ADDBUTTONSA      = %WM_USER + 20
%TB_INSERTBUTTONA    = %WM_USER + 21

'%TB_DELETEBUTTON     = %WM_USER + 22
'%TB_GETBUTTON        = %WM_USER + 23
'%TB_GETBUTTON        = %WM_USER + 23
'%TB_BUTTONCOUNT      = %WM_USER + 24
'%TB_COMMANDTOINDEX   = %WM_USER + 25

'#ifdef _WIN32

' // Size = 12 bytes
TYPE TBSAVEPARAMSA DWORD
   hkr          AS DWORD        ' HKEY hkr
   pszSubKey    AS ASCIIZ PTR   ' LPCSTR pszSubKey
   pszValueName AS ASCIIZ PTR   ' LPCSTR pszValueName
END TYPE

' // Size = 12 bytes
TYPE TBSAVEPARAMSW DWORD
   hkr          AS DWORD          ' HKEY hkr
   pszSubKey    AS WSTRINGZ PTR   ' LPCWSTR pszSubKey
   pszValueName AS WSTRINGZ PTR   ' LPCWSTR pszValueName
END TYPE

#IF %DEF(%UNICODE)
   MACRO TBSAVEPARAMS = TBSAVEPARAMSW
#ELSE
   MACRO TBSAVEPARAMS = TBSAVEPARAMSA
#ENDIF

'#endif  // _WIN32

%TB_SAVERESTOREA          = %WM_USER + 26
%TB_SAVERESTOREW          = %WM_USER + 76
#IF %DEF(%UNICODE)
%TB_SAVERESTORE = %TB_SAVERESTOREW
#ELSE
%TB_SAVERESTORE = %TB_SAVERESTOREA
#ENDIF
'%TB_CUSTOMIZE             = %WM_USER + 27
%TB_ADDSTRINGA            = %WM_USER + 28
%TB_ADDSTRINGW            = %WM_USER + 77
#IF %DEF(%UNICODE)
%TB_ADDSTRING = %TB_ADDSTRINGW
#ELSE
%TB_ADDSTRING = %TB_ADDSTRINGA
#ENDIF
'%TB_GETITEMRECT           = %WM_USER + 29
'%TB_BUTTONSTRUCTSIZE      = %WM_USER + 30
'%TB_SETBUTTONSIZE         = %WM_USER + 31
'%TB_SETBITMAPSIZE         = %WM_USER + 32
'%TB_AUTOSIZE              = %WM_USER + 33
'%TB_GETTOOLTIPS           = %WM_USER + 35
'%TB_SETTOOLTIPS           = %WM_USER + 36
'%TB_SETPARENT             = %WM_USER + 37
'%TB_SETROWS               = %WM_USER + 39
'%TB_GETROWS               = %WM_USER + 40
'%TB_SETCMDID              = %WM_USER + 42
'%TB_CHANGEBITMAP          = %WM_USER + 43
'%TB_GETBITMAP             = %WM_USER + 44
%TB_GETBUTTONTEXTA        = %WM_USER + 45
%TB_GETBUTTONTEXTW        = %WM_USER + 75
#IF %DEF(%UNICODE)
%TB_GETBUTTONTEXT = %TB_GETBUTTONTEXTW
#ELSE
%TB_GETBUTTONTEXT = %TB_GETBUTTONTEXTA
#ENDIF
'%TB_REPLACEBITMAP         = %WM_USER + 46
'#if (_WIN32_IE >= 0x0300)
'%TB_SETINDENT             = %WM_USER + 47
'%TB_SETIMAGELIST          = %WM_USER + 48
'%TB_GETIMAGELIST          = %WM_USER + 49
'%TB_LOADIMAGES            = %WM_USER + 50
'%TB_GETRECT               = %WM_USER + 51  ' // wParam is the Cmd instead of index
'%TB_SETHOTIMAGELIST       = %WM_USER + 52
'%TB_GETHOTIMAGELIST       = %WM_USER + 53
'%TB_SETDISABLEDIMAGELIST  = %WM_USER + 54
'%TB_GETDISABLEDIMAGELIST  = %WM_USER + 55
'%TB_SETSTYLE              = %WM_USER + 56
'%TB_GETSTYLE              = %WM_USER + 57
'%TB_GETBUTTONSIZE         = %WM_USER + 58
'%TB_SETBUTTONWIDTH        = %WM_USER + 59
'%TB_SETMAXTEXTROWS        = %WM_USER + 60
'%TB_GETTEXTROWS           = %WM_USER + 61
'#endif      // _WIN32_IE >= 0x0300

'#if (_WIN32_IE >= 0x0400)
'%TB_GETOBJECT             = %WM_USER + 62  ' wParam == IID, lParam void **ppv
'%TB_GETHOTITEM            = %WM_USER + 71
'%TB_SETHOTITEM            = %WM_USER + 72  ' wParam == iHotItem
'%TB_SETANCHORHIGHLIGHT    = %WM_USER + 73  ' wParam == TRUE/FALSE
'%TB_GETANCHORHIGHLIGHT    = %WM_USER + 74
%TB_MAPACCELERATORA       = %WM_USER + 78  ' wParam == ch, lParam int * pidBtn
'typedef struct {

' // Size = 8 bytes
TYPE TBINSERTMARK DWORD
   iButton AS LONG    ' int
   dwFlags AS DWORD   ' DWORD
END TYPE

%TBIMHT_AFTER             = &H00000001??? ' TRUE = insert After iButton, otherwise before
%TBIMHT_BACKGROUND        = &H00000002??? ' TRUE iff missed buttons completely

'%TB_GETINSERTMARK         = %WM_USER + 79  ' lParam == LPTBINSERTMARK
'%TB_SETINSERTMARK         = %WM_USER + 80  ' lParam == LPTBINSERTMARK
'%TB_INSERTMARKHITTEST     = %WM_USER + 81  ' wParam == LPPOINT lParam == LPTBINSERTMARK
'%TB_MOVEBUTTON            = %WM_USER + 82
'%TB_GETMAXSIZE            = %WM_USER + 83  ' lParam == LPSIZE
'%TB_SETEXTENDEDSTYLE      = %WM_USER + 84  ' For TBSTYLE_EX_*
'%TB_GETEXTENDEDSTYLE      = %WM_USER + 85  ' For TBSTYLE_EX_*
'%TB_GETPADDING            = %WM_USER + 86
'%TB_SETPADDING            = %WM_USER + 87
'%TB_SETINSERTMARKCOLOR    = %WM_USER + 88
'%TB_GETINSERTMARKCOLOR    = %WM_USER + 89
%TB_SETLISTGAP            = %WM_USER + 96  ' Not included in commctrl.h, but valid

%TB_SETCOLORSCHEME        = %CCM_SETCOLORSCHEME  ' lParam is color scheme
%TB_GETCOLORSCHEME        = %CCM_GETCOLORSCHEME  ' fills in COLORSCHEME pointed to by lParam

%TB_SETUNICODEFORMAT      = %CCM_SETUNICODEFORMAT
%TB_GETUNICODEFORMAT      = %CCM_GETUNICODEFORMAT

%TB_MAPACCELERATORW       = %WM_USER + 90  ' wParam == ch, lParam int * pidBtn
#IF %DEF(%UNICODE)
%TB_MAPACCELERATOR = %TB_MAPACCELERATORW
#ELSE
%TB_MAPACCELERATOR = %TB_MAPACCELERATORA
#ENDIF

'#endif  // _WIN32_IE >= 0x0400

' // Size = 20 bytes
TYPE TBREPLACEBITMAP DWORD
   hInstOld AS DWORD   ' HINSTANCE
   nIDOld   AS DWORD   ' UINT_PTR
   hInstNew AS DWORD   ' HINSTANCE
   nIDNew   AS DWORD   ' UINT_PTR
   nButtons AS LONG    ' int
END TYPE

%TBBF_LARGE              = &H0001???

%TB_GETBITMAPFLAGS       = %WM_USER + 41

'#if (_WIN32_IE >= 0x0400)
%TBIF_IMAGE   = &H00000001???
%TBIF_TEXT    = &H00000002???
%TBIF_STATE   = &H00000004???
%TBIF_STYLE   = &H00000008???
%TBIF_LPARAM  = &H00000010???
%TBIF_COMMAND = &H00000020???
%TBIF_SIZE    = &H00000040???

'#if (_WIN32_IE >= 0x0500)
%TBIF_BYINDEX = &H80000000??? ' this specifies that the wparam in Get/SetButtonInfo is an index, not id
'#endif

' // Size = 32 bytes
TYPE TBBUTTONINFOA DWORD FILL
   cbSize    AS DWORD        ' UINT
   dwMask    AS DWORD        ' DWORD
   idCommand AS LONG         ' int
   iImage    AS LONG         ' int
   fsState   AS BYTE         ' BYTE
   fsStyle   AS BYTE         ' BYTE
   cx        AS WORD         ' WORD
   lParam    AS DWORD        ' DWORD_PTR
   pszText   AS ASCIIZ PTR   ' LPSTR
   cchText   AS LONG         ' int
END TYPE

' // Size = 32 bytes
TYPE TBBUTTONINFOW DWORD FILL
   cbSize    AS DWORD          ' UINT
   dwMask    AS DWORD          ' DWORD
   idCommand AS LONG           ' int
   iImage    AS LONG           ' int
   fsState   AS BYTE           ' BYTE
   fsStyle   AS BYTE           ' BYTE
   cx        AS WORD           ' WORD
   lParam    AS DWORD          ' DWORD_PTR
   pszText   AS WSTRINGZ PTR   ' LPWSTR
   cchText   AS LONG           ' int
END TYPE

#IF %DEF(%UNICODE)
   MACRO TBBUTTONINFO = TBBUTTONINFOW
#ELSE
   MACRO TBBUTTONINFO = TBBUTTONINFOA
#ENDIF

'// BUTTONINFO APIs do NOT support the string pool.
%TB_GETBUTTONINFOW        = %WM_USER + 63
%TB_SETBUTTONINFOW        = %WM_USER + 64
%TB_GETBUTTONINFOA        = %WM_USER + 65
%TB_SETBUTTONINFOA        = %WM_USER + 66
#IF %DEF(%UNICODE)
%TB_GETBUTTONINFO = %TB_GETBUTTONINFOW
%TB_SETBUTTONINFO = %TB_SETBUTTONINFOW
#ELSE
%TB_GETBUTTONINFO = %TB_GETBUTTONINFOA
%TB_SETBUTTONINFO = %TB_SETBUTTONINFOA
#ENDIF

%TB_INSERTBUTTONW         = %WM_USER + 67
%TB_ADDBUTTONSW           = %WM_USER + 68
#IF %DEF(%UNICODE)
%TB_INSERTBUTTON = %TB_INSERTBUTTONW
%TB_ADDBUTTONS   = %TB_ADDBUTTONSW
#ELSE
%TB_INSERTBUTTON = %TB_INSERTBUTTONA
%TB_ADDBUTTONS   = %TB_ADDBUTTONSA
#ENDIF

'%TB_HITTEST               = %WM_USER + 69

'// New post Win95/NT4 for InsertButton and AddButton.  if iString member
'// is a pointer to a string, it will be handled as a string like listview
'// (although LPSTR_TEXTCALLBACK is not supported).

'%TB_SETDRAWTEXTFLAGS      = %WM_USER + 70  ' wParam == mask lParam == bit values

'#endif  // _WIN32_IE >= 0x0400

'#if (_WIN32_IE >= 0x0500)

%TB_GETSTRINGW            = %WM_USER + 91
%TB_GETSTRINGA            = %WM_USER + 92
#IF %DEF(%UNICODE)
%TB_GETSTRING = %TB_GETSTRINGW
#ELSE
%TB_GETSTRING = %TB_GETSTRINGA
#ENDIF

'#endif  // _WIN32_IE >= 0x0500

%TB_SETHOTITEM2          = %WM_USER + 94   ' // wParam == iHotItem,  lParam = dwFlags
%TB_SETLISTGAP           = %WM_USER + 96
%TB_GETIMAGELISTCOUNT    = %WM_USER + 98
%TB_GETIDEALSIZE         = %WM_USER + 99   ' // wParam == fHeight, lParam = psize
'// before using WM_USER + 103, recycle old space above (WM_USER + 97)
'%TB_TRANSLATEACCELERATOR = %CCM_TRANSLATEACCELERATOR

'#if (_WIN32_WINNT >= 0x501)
%TBMF_PAD                 = &H00000001???
%TBMF_BARPAD              = &H00000002???
%TBMF_BUTTONSPACING       = &H00000004???

' // Size = 32 bytes
TYPE TBMETRICS DWORD
   cbSize          AS DWORD   ' UINT cbSize
   dwMask          AS DWORD   ' DWORD dwMask
   cxPad           AS LONG    ' int cxPad            // PAD
   cyPad           AS LONG    ' int cyPad
   cxBarPad        AS LONG    ' int cxBarPad         // BARPAD
   cyBarPad        AS LONG    ' int cyBarPad
   cxButtonSpacing AS LONG    ' int cxButtonSpacing  // BUTTONSPACING
   cyButtonSpacing AS LONG    ' int cyButtonSpacing
END TYPE

'%TB_GETMETRICS      = %WM_USER + 101
'%TB_SETMETRICS      = %WM_USER + 102
'#endif

'#if (_WIN32_WINNT >= 0x600)
%TB_GETITEMDROPDOWNRECT = %WM_USER + 103   ' // Rect of item's drop down button
%TB_SETPRESSEDIMAGELIST = %WM_USER + 104
%TB_GETPRESSEDIMAGELIST = %WM_USER + 105
'#endif // _WIN32_WINNT >= 0x600

'#if (_WIN32_WINNT >= 0x501)
%TB_SETWINDOWTHEME  = %CCM_SETWINDOWTHEME
'#endif

' // TBN_GETBUTTONINFOA and TBN_GETBUTTONINFOW are predefined in the compiler, but
' // TBN_GETBUTTONINFO is called TBN_GETBUTTONINFO, so we need to redefine it.
%TBN_GETBUTTONINFOA = %TBN_FIRST - 0
'%TBN_BEGINDRAG      = %TBN_FIRST - 1
'%TBN_ENDDRAG        = %TBN_FIRST - 2
'%TBN_BEGINADJUST    = %TBN_FIRST - 3
'%TBN_ENDADJUST      = %TBN_FIRST - 4
'%TBN_RESET          = %TBN_FIRST - 5
'%TBN_QUERYINSERT    = %TBN_FIRST - 6
'%TBN_QUERYDELETE    = %TBN_FIRST - 7
'%TBN_TOOLBARCHANGE  = %TBN_FIRST - 8
'%TBN_CUSTHELP       = %TBN_FIRST - 9
'#if (_WIN32_IE >= 0x0300)
%TBN_DROPDOWN       = %TBN_FIRST - 10
'#endif
'#if (_WIN32_IE >= 0x0400)
%TBN_GETOBJECT      = %TBN_FIRST - 12

'// Structure for TBN_HOTITEMCHANGE notification
'//
' // Size = 24 bytes
TYPE NMTBHOTITEM DWORD
   hdr     AS NMHDR   ' NMHDR   hdr
   idOld   AS LONG    ' int     idOld
   idNew   AS LONG    ' int     idNew
   dwFlags AS DWORD   ' DWORD   dwFlags  // HICF_*
END TYPE

'// Hot item change flags
%HICF_OTHER          = &H00000000???
%HICF_MOUSE          = &H00000001???    ' Triggered by mouse
%HICF_ARROWKEYS      = &H00000002???    ' Triggered by arrow keys
%HICF_ACCELERATOR    = &H00000004???    ' Triggered by accelerator
%HICF_DUPACCEL       = &H00000008???    ' This accelerator is not unique
%HICF_ENTERING       = &H00000010???    ' idOld is invalid
%HICF_LEAVING        = &H00000020???    ' idNew is invalid
%HICF_RESELECT       = &H00000040???    ' hot item reselected
%HICF_LMOUSE         = &H00000080???    ' left mouse button selected
%HICF_TOGGLEDROPDOWN = &H00000100???    ' Toggle button's dropdown state

%TBN_HOTITEMCHANGE   = %TBN_FIRST - 13
%TBN_DRAGOUT         = %TBN_FIRST - 14 ' this is sent when the user clicks down on a button then drags off the button
%TBN_DELETINGBUTTON  = %TBN_FIRST - 15 ' uses %TBNOTIFY
%TBN_GETDISPINFOA    = %TBN_FIRST - 16 ' This is sent when the toolbar needs some display information
%TBN_GETDISPINFOW    = %TBN_FIRST - 17 ' This is sent when the toolbar needs some display information
#IF %DEF(%UNICODE)
%TBN_GETDISPINFO = %TBN_GETDISPINFOW
#ELSE
%TBN_GETDISPINFO = %TBN_GETDISPINFOA
#ENDIF
%TBN_GETINFOTIPA     = %TBN_FIRST - 18
%TBN_GETINFOTIPW     = %TBN_FIRST - 19
#IF %DEF(%UNICODE)
%TBN_GETINFOTIP = %TBN_GETINFOTIPW
#ELSE
%TBN_GETINFOTIP = %TBN_GETINFOTIPA
#ENDIF
%TBN_GETBUTTONINFOW  = %TBN_FIRST - 20
#IF %DEF(%UNICODE)
%TBN_GETBUTTONINFO = %TBN_GETBUTTONINFOW
#ELSE
%TBN_GETBUTTONINFO = %TBN_GETBUTTONINFOA
#ENDIF
'#if (_WIN32_IE >= 0x0500)
%TBN_RESTORE         = %TBN_FIRST - 21
%TBN_SAVE            = %TBN_FIRST - 22
%TBN_INITCUSTOMIZE   = %TBN_FIRST - 23
%TBNRF_HIDEHELP      = &H00000001???
%TBNRF_ENDCUSTOMIZE  = &H00000002???
%TBN_WRAPHOTITEM     = %TBN_FIRST - 24
%TBN_DUPACCELERATOR  = %TBN_FIRST - 25
%TBN_WRAPACCELERATOR = %TBN_FIRST - 26
%TBN_DRAGOVER        = %TBN_FIRST - 27
%TBN_MAPACCELERATOR  = %TBN_FIRST - 28
'#endif // (_WIN32_IE >= 0x0500)

'#if (_WIN32_IE >= 0x0500)

UNION NMTBSAVE_TBBUTTON_UNION
   tbButton AS TBBUTTON    ' TBBUTTON tbButton
   ' // For compatibility with the PB includes
   tButton AS TBBUTTON    ' TBBUTTON tbButton
END UNION

' // Size = 24 bytes
' // Note: Must be byte aligned because the TBBUTTON structure has a different size in Win64
TYPE NMTBSAVE BYTE
   hdr      AS NMHDR       ' NMHDR hdr
   pData    AS DWORD PTR   ' DWORD* pData
   pCurrent AS DWORD PTR   ' DWORD* pCurrent
   cbData   AS DWORD       ' UINT cbData
   iItem    AS LONG        ' int iItem
   cButtons AS LONG        ' int cButtons
   NMTBSAVE_TBBUTTON_UNION
END TYPE

UNION NMTBRESTORE_TBBUTTON_UNION
   tbButton AS TBBUTTON    ' TBBUTTON tbButton
   ' // For compatibility with the PB includes
   tButton AS TBBUTTON    ' TBBUTTON tbButton
END UNION

' // Size = 56 bytes
' // Note: Must be byte aligned because the TBBUTTON structure has a different size in Win64
TYPE NMTBRESTORE BYTE
   hdr              AS NMHDR       ' NMHDR hdr
   pData            AS DWORD PTR   ' DWORD* pData
   pCurrent         AS DWORD PTR   ' DWORD* pCurrent
   cbData           AS DWORD       ' UINT cbData
   iItem            AS LONG        ' int iItem
   cButtons         AS LONG        ' int cButtons
   cbBytesPerRecord AS LONG        ' int cbBytesPerRecord
   NMTBRESTORE_TBBUTTON_UNION
END TYPE

'#endif // (_WIN32_IE >= 0x0500)

' // Size = 28 bytes
TYPE NMTBGETINFOTIPA BYTE
   hdr        AS NMHDR         ' NMHDR hdr
   pszText    AS ASCIIZ PTR    ' LPSTR pszText
   cchTextMax AS LONG          ' int cchTextMax
   iItem      AS LONG          ' int iItem
   lParam     AS LONG          ' LPARAM lParam
END TYPE

' // Size = 28 bytes
TYPE NMTBGETINFOTIPW BYTE
   hdr        AS NMHDR          ' NMHDR hdr
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax AS LONG           ' int cchTextMax
   iItem      AS LONG           ' int iItem
   lParam     AS LONG           ' LPARAM lParam
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMTBGETINFOTIP = NMTBGETINFOTIPW
#ELSE
   MACRO NMTBGETINFOTIP = NMTBGETINFOTIPA
#ENDIF

%TBNF_IMAGE       = &H00000001???
%TBNF_TEXT        = &H00000002???
%TBNF_DI_SETITEM  = &H10000000???

' // Size = 36 bytes
TYPE NMTBDISPINFOA DWORD
   hdr       AS NMHDR      ' NMHDR  hdr
   dwMask    AS DWORD      ' DWORD dwMask      // [in] Specifies the values requested .[out] Client ask the data to be set for future use
   idCommand AS LONG       ' int idCommand     // [in] id of button we're requesting info for
   lParam    AS DWORD      ' DWORD_PTR lParam  // [in] lParam of button
   iImage    AS LONG       ' int iImage        // [out] image index
   pszText   AS ASCIIZ PTR ' LPSTR pszText     // [out] new text for item
   cchText   AS LONG       ' int cchText       // [in] size of buffer pointed to by pszText
END TYPE

' // Size = 36 bytes
TYPE NMTBDISPINFOW DWORD
   hdr       AS NMHDR          ' NMHDR  hdr
   dwMask    AS DWORD          ' DWORD dwMask      // [in] Specifies the values requested .[out] Client ask the data to be set for future use
   idCommand AS LONG           ' int idCommand     // [in] id of button we're requesting info for
   lParam    AS DWORD          ' DWORD_PTR lParam  // [in] lParam of button
   iImage    AS LONG           ' int iImage        // [out] image index
   pszText   AS WSTRINGZ PTR   ' LPWSTR pszText    // [out] new text for item
   cchText   AS LONG           ' int cchText       // [in] size of buffer pointed to by pszText
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMTBDISPINFO = NMTBDISPINFOW
#ELSE
   MACRO NMTBDISPINFO = NMTBDISPINFOA
#ENDIF

'// Return codes for TBN_DROPDOWN
%TBDDRET_DEFAULT      = 0
%TBDDRET_NODEFAULT    = 1
%TBDDRET_TREATPRESSED = 2       ' Treat as a standard press button

'#endif

'#if (_WIN32_IE >= 0x0300)
' // Size = 60 bytes
' // Note: Must be byte aligned because the TBBUTTON structure has a different size in Win64
TYPE NMTOOLBARA BYTE
   hdr      AS NMHDR        ' NMHDR   hdr
   iItem    AS LONG         ' int     iItem
   tbButton AS TBBUTTON     ' TBBUTTON tbButton
   cchText  AS LONG         ' int     cchText
   pszText  AS ASCIIZ PTR   ' LPSTR   pszText
'#IF (%WIN32_IE >= &H500)
#IF %WINVER >= &H0500
   rcButton AS RECT         ' RECT    rcButton
#ENDIF
END TYPE

' // Size = 60 bytes
' // Note: Must be byte aligned because the TBBUTTON structure has a different size in Win64
TYPE NMTOOLBARW BYTE
   hdr      AS NMHDR          ' NMHDR   hdr
   iItem    AS LONG           ' int     iItem
   tbButton AS TBBUTTON       ' TBBUTTON tbButton
   cchText  AS LONG           ' int     cchText
   pszText  AS WSTRINGZ PTR   ' LPWSTR   pszText
'#IF (%WIN32_IE >= &H500)
#IF %WINVER >= &H0500
   rcButton AS RECT           ' RECT    rcButton
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMTOOLBAR = NMTOOLBARW
#ELSE
   MACRO NMTOOLBAR = NMTOOLBARA
#ENDIF

' // Size = 60 bytes
' // Note: Must be byte aligned because the TBBUTTON structure has a different size in Win64
TYPE TBNOTIFYA BYTE
   hdr      AS NMHDR        ' NMHDR   hdr
   iItem    AS LONG         ' int     iItem
   tbButton AS TBBUTTON     ' TBBUTTON tbButton
   cchText  AS LONG         ' int     cchText
   pszText  AS ASCIIZ PTR   ' LPSTR   pszText
'#IF (%WIN32_IE >= &H500)
#IF %WINVER >= &H0500
   rcButton AS RECT         ' RECT    rcButton
#ENDIF
END TYPE

TYPE TBNOTIFYW BYTE
   hdr      AS NMHDR          ' NMHDR   hdr
   iItem    AS LONG           ' int     iItem
   tbButton AS TBBUTTON       ' TBBUTTON tbButton
   cchText  AS LONG           ' int     cchText
   pszText  AS WSTRINGZ PTR   ' LPWSTR   pszText
'#IF (%WIN32_IE >= &H500)
#IF %WINVER >= &H0500
   rcButton AS RECT           ' RECT    rcButton
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO TBNOTIFY = TBNOTIFYW
#ELSE
   MACRO TBNOTIFY = TBNOTIFYA
#ENDIF

#ENDIF    ' // NOTOOLBAR


'#if (_WIN32_IE >= 0x0300)
'//====== REBAR CONTROL ========================================================

#IF NOT %DEF(%NOREBAR)

$REBARCLASSNAMEA      = "ReBarWindow32"
$$REBARCLASSNAMEW     = "ReBarWindow32"$$
#IF %DEF(%UNICODE)
   MACRO REBARCLASSNAME = $$REBARCLASSNAMEW
#ELSE
   MACRO REBARCLASSNAME = $REBARCLASSNAMEA
#ENDIF

%RBIM_IMAGELIST       = &H00000001???

%RBS_TOOLTIPS         = &H00000100???
%RBS_VARHEIGHT        = &H00000200???
%RBS_BANDBORDERS      = &H00000400???
%RBS_FIXEDORDER       = &H00000800???
'#if (_WIN32_IE >= 0x0400)
%RBS_REGISTERDROP     = &H00001000???
%RBS_AUTOSIZE         = &H00002000???
%RBS_VERTICALGRIPPER  = &H00004000???  ' // this always has the vertical gripper (default for horizontal mode)
%RBS_DBLCLKTOGGLE     = &H00008000???
'#endif      // _WIN32_IE >= 0x0400

'typedef struct tagREBARINFO
'{
'    UINT        cbSize;
'    UINT        fMask;
'#ifndef NOIMAGEAPIS
'    HIMAGELIST  himl;
'#else
'    HANDLE      himl;
'#endif
'}   REBARINFO, *LPREBARINFO;

' // Size = 12 bytes
TYPE REBARINFO DWORD
   cbSize AS DWORD   ' UINT        cbSize
   fMask  AS DWORD   ' UINT        fMask
   himl   AS DWORD   ' HIMAGELIST  himl
END TYPE

%RBBS_BREAK          = &H00000001???  ' break to new line
%RBBS_FIXEDSIZE      = &H00000002???  ' band can't be sized
%RBBS_CHILDEDGE      = &H00000004???  ' edge around top & bottom of child window
%RBBS_HIDDEN         = &H00000008???  ' don't show
%RBBS_NOVERT         = &H00000010???  ' don't show when vertical
%RBBS_FIXEDBMP       = &H00000020???  ' bitmap doesn't move during band resize
'#if (_WIN32_IE >= 0x0400)               //
%RBBS_VARIABLEHEIGHT = &H00000040???  ' allow autosizing of this child vertically
%RBBS_GRIPPERALWAYS  = &H00000080???  ' always show the gripper
%RBBS_NOGRIPPER      = &H00000100???  ' never show the gripper
'#if (_WIN32_IE >= 0x0500)               //
%RBBS_USECHEVRON     = &H00000200???  ' display drop-down button for this band if it's sized smaller than ideal width
'#if (_WIN32_IE >= 0x0501)               //
%RBBS_HIDETITLE      = &H00000400???  ' keep band title hidden
%RBBS_TOPALIGN       = &H00000800???  ' keep band in top row
'#endif // 0x0501                        //
'#endif // 0x0500                        //
'#endif // 0x0400                        //

%RBBIM_STYLE           = &H00000001???
%RBBIM_COLORS          = &H00000002???
%RBBIM_TEXT            = &H00000004???
%RBBIM_IMAGE           = &H00000008???
%RBBIM_CHILD           = &H00000010???
%RBBIM_CHILDSIZE       = &H00000020???
%RBBIM_SIZE            = &H00000040???
%RBBIM_BACKGROUND      = &H00000080???
%RBBIM_ID              = &H00000100???
'#if (_WIN32_IE >= 0x0400)
%RBBIM_IDEALSIZE       = &H00000200???
%RBBIM_LPARAM          = &H00000400???
%RBBIM_HEADERSIZE      = &H00000800???  ' control the size of the header
'#endif
'#if (_WIN32_WINNT >= 0x0600)
%RBBIM_CHEVRONLOCATION = &H00001000???
%RBBIM_CHEVRONSTATE    = &H00002000???
'#endif

' // Size = 100 bytes (80 bytes if used without themes)
TYPE REBARBANDINFOA DWORD
   cbSize            AS DWORD        ' UINT
   fMask             AS DWORD        ' UINT
   fStyle            AS DWORD        ' UINT
   clrFore           AS DWORD        ' COLORREF
   clrBack           AS DWORD        ' COLORREF
   lpText            AS ASCIIZ PTR   ' LPSTR
   cch               AS DWORD        ' UINT
   iImage            AS LONG         ' int
   hwndChild         AS DWORD        ' HWND
   cxMinChild        AS DWORD        ' UINT
   cyMinChild        AS DWORD        ' UINT
   cx                AS DWORD        ' UINT
   hbmBack           AS DWORD        ' HBITMAP
   wID               AS DWORD        ' UINT
#IF (%WIN32_IE >= &H0400)
   cyChild           AS DWORD        ' UINT
   cyMaxChild        AS DWORD        ' UINT
   cyIntegral        AS DWORD        ' UINT
   cxIdeal           AS DWORD        ' UINT
   lParam            AS LONG         ' LPARAM
   cxHeader          AS DWORD        ' UINT
#ENDIF

'#IF (%WIN32_WINNT >= &H0600)
#IF %WINVER >= &H0600
   rcChevronLocation AS RECT         ' RECT // the rect is in client co-ord wrt hwndChild
   uChevronState     AS DWORD        ' UINT // STATE_SYSTEM_*
#ENDIF
END TYPE

' // Size = 100 bytes (80 bytes if used without themes)
TYPE REBARBANDINFOW DWORD
   cbSize            AS DWORD          ' UINT
   fMask             AS DWORD          ' UINT
   fStyle            AS DWORD          ' UINT
   clrFore           AS DWORD          ' COLORREF
   clrBack           AS DWORD          ' COLORREF
   lpText            AS WSTRINGZ PTR   ' LPWSTR
   cch               AS DWORD          ' UINT
   iImage            AS LONG           ' int
   hwndChild         AS DWORD          ' HWND
   cxMinChild        AS DWORD          ' UINT
   cyMinChild        AS DWORD          ' UINT
   cx                AS DWORD          ' UINT
   hbmBack           AS DWORD          ' HBITMAP
   wID               AS DWORD          ' UINT
#IF (%WIN32_IE >= &H0400)
   cyChild           AS DWORD          ' UINT
   cyMaxChild        AS DWORD          ' UINT
   cyIntegral        AS DWORD          ' UINT
   cxIdeal           AS DWORD          ' UINT
   lParam            AS LONG           ' LPARAM
   cxHeader          AS DWORD          ' UINT
#ENDIF
'#IF (%WIN32_WINNT >= &H0600)
#IF %WINVER >= &H0600
   rcChevronLocation AS RECT           ' RECT // the rect is in client co-ord wrt hwndChild
   uChevronState     AS DWORD          ' UINT // STATE_SYSTEM_*
#ENDIF
'#endif
END TYPE

#IF %DEF(%UNICODE)
   MACRO REBARBANDINFO = REBARBANDINFOW
#ELSE
   MACRO REBARBANDINFO = REBARBANDINFOA
#ENDIF

%REBARBANDINFO_V3_SIZE = 80    ' // Size of REBARBANDINFO if used without themes (ComCtl32.dll < 6.0)
%REBARBANDINFO_V6_SIZE = 100   ' // Size of REBARBANDINFO if used with themes (ComCtl32.dll 6.0)

%RB_INSERTBANDA  = %WM_USER + 1
%RB_DELETEBAND   = %WM_USER + 2
%RB_GETBARINFO   = %WM_USER + 3
%RB_SETBARINFO   = %WM_USER + 4
'#if (_WIN32_IE < 0x0400)
'%RB_GETBANDINFO  = %WM_USER + 5    ' for _WIN32_IE < 0x0400
'#endif
%RB_SETBANDINFOA = %WM_USER + 6
%RB_SETPARENT    = %WM_USER + 7
'#if (_WIN32_IE >= 0x0400)
%RB_HITTEST      = %WM_USER + 8
%RB_GETRECT      = %WM_USER + 9
'#endif
%RB_INSERTBANDW  = %WM_USER + 10
#IF %DEF(%UNICODE)
%RB_INSERTBAND = %RB_INSERTBANDW
#ELSE
%RB_INSERTBAND = %RB_INSERTBANDA
#ENDIF
%RB_SETBANDINFOW = %WM_USER + 11
#IF %DEF(%UNICODE)
%RB_SETBANDINFO = %RB_SETBANDINFOW
#ELSE
%RB_SETBANDINFO = %RB_SETBANDINFOA
#ENDIF
%RB_GETBANDCOUNT = %WM_USER + 12
%RB_GETROWCOUNT  = %WM_USER + 13
%RB_GETROWHEIGHT = %WM_USER + 14
'#if (_WIN32_IE >= 0x0400)
%RB_IDTOINDEX    = %WM_USER + 16 ' wParam == id
%RB_GETTOOLTIPS  = %WM_USER + 17
%RB_SETTOOLTIPS  = %WM_USER + 18
%RB_SETBKCOLOR   = %WM_USER + 19 ' sets the default BK color
%RB_GETBKCOLOR   = %WM_USER + 20 ' defaults to CLR_NONE
%RB_SETTEXTCOLOR = %WM_USER + 21
%RB_GETTEXTCOLOR = %WM_USER + 22 ' defaults to &H00000000

'#if (_WIN32_WINNT >= 0x0501)
%RBSTR_CHANGERECT = &H0001 ' flags for %RB_SIZETORECT
'#endif

%RB_SIZETORECT   = %WM_USER + 23 ' resize the rebar/break bands and such to this rect (lparam)
'#endif      // _WIN32_IE >= 0x0400

%RB_SETCOLORSCHEME  = %CCM_SETCOLORSCHEME  ' lParam is color scheme
%RB_GETCOLORSCHEME  = %CCM_GETCOLORSCHEME  ' fills in COLORSCHEME pointed to by lParam

'#if (_WIN32_IE >= 0x0400)
'// for manual drag control
'// lparam == cursor pos
'        // -1 means do it yourself.
'        // -2 means use what you had saved before
%RB_BEGINDRAG        = %WM_USER + 24
%RB_ENDDRAG          = %WM_USER + 25
%RB_DRAGMOVE         = %WM_USER + 26
%RB_GETBARHEIGHT     = %WM_USER + 27
%RB_GETBANDINFOW     = %WM_USER + 28
%RB_GETBANDINFOA     = %WM_USER + 29
#IF %DEF(%UNICODE)
%RB_GETBANDINFO = %RB_GETBANDINFOW
#ELSE
%RB_GETBANDINFO = %RB_GETBANDINFOA
#ENDIF

%RB_MINIMIZEBAND     = %WM_USER + 30
%RB_MAXIMIZEBAND     = %WM_USER + 31

%RB_GETDROPTARGET    = %CCM_GETDROPTARGET

%RB_GETBANDBORDERS   = %WM_USER + 34  ' returns in lparam = lprc the amount of edges added to band wparam

%RB_SHOWBAND         = %WM_USER + 35  ' show/hide band
%RB_SETPALETTE       = %WM_USER + 37
%RB_GETPALETTE       = %WM_USER + 38
%RB_MOVEBAND         = %WM_USER + 39

%RB_SETUNICODEFORMAT = %CCM_SETUNICODEFORMAT
%RB_GETUNICODEFORMAT = %CCM_GETUNICODEFORMAT

'#endif      // _WIN32_IE >= 0x0400

'#if (_WIN32_WINNT >= 0x501)
%RB_GETBANDMARGINS   = %WM_USER + 40
%RB_SETWINDOWTHEME   = %CCM_SETWINDOWTHEME
'#endif

'#if (_WIN32_IE >= 0x0600)
%RB_SETEXTENDEDSTYLE = %WM_USER + 41
%RB_GETEXTENDEDSTYLE = %WM_USER + 42
'#endif      // _WIN32_IE >= 0x0600

'#if (_WIN32_IE >= 0x0500)
%RB_PUSHCHEVRON      = %WM_USER + 43
'#endif      // _WIN32_IE >= 0x0500

'#if (_WIN32_WINNT >= 0x0600)
%RB_SETBANDWIDTH     = %WM_USER + 44   ' // set width for docked band
'#endif      // _WIN32_WINNT >= 0x0600

%RBN_HEIGHTCHANGE    = %RBN_FIRST - 0

'#if (_WIN32_IE >= 0x0400)
%RBN_GETOBJECT       = %RBN_FIRST - 1
%RBN_LAYOUTCHANGED   = %RBN_FIRST - 2
%RBN_AUTOSIZE        = %RBN_FIRST - 3
%RBN_BEGINDRAG       = %RBN_FIRST - 4
%RBN_ENDDRAG         = %RBN_FIRST - 5
%RBN_DELETINGBAND    = %RBN_FIRST - 6     ' Uses NMREBAR
%RBN_DELETEDBAND     = %RBN_FIRST - 7     ' Uses NMREBAR
%RBN_CHILDSIZE       = %RBN_FIRST - 8

'#if (_WIN32_IE >= 0x0500)
%RBN_CHEVRONPUSHED   = %RBN_FIRST - 10
'#endif      // _WIN32_IE >= 0x0500

'#if (_WIN32_IE >= 0x0600)
%RBN_SPLITTERDRAG    = %RBN_FIRST - 11
'#endif      // _WIN32_IE >= 0x0600

'#if (_WIN32_IE >= 0x0500)
%RBN_MINMAX          = %RBN_FIRST - 21
'#endif

'#if (_WIN32_WINNT >= 0x0501)
%RBN_AUTOBREAK       = %RBN_FIRST - 22
'#endif

' // Size = 52 bytes
TYPE NMREBARCHILDSIZE DWORD
   hdr     AS NMHDR   ' NMHDR hdr
   uBand   AS DWORD   ' UINT uBand
   wID     AS DWORD   ' UINT wID
   rcChild AS RECT    ' RECT rcChild
   rcBand  AS RECT    ' RECT rcBand
END TYPE

' // Size = 32 bytes
TYPE NMREBAR DWORD
   hdr    AS NMHDR   ' NMHDR   hdr
   dwMask AS DWORD   ' DWORD   dwMask;           // RBNM_*
   uBand  AS DWORD   ' UINT    uBand
   fStyle AS DWORD   ' UINT    fStyle
   wID    AS DWORD   ' UINT    wID
   lParam AS LONG    ' LPARAM  lParam
END TYPE

'// Mask flags for NMREBAR
%RBNM_ID     = &H00000001???
%RBNM_STYLE  = &H00000002???
%RBNM_LPARAM = &H00000004???

' // Size = 48 bytes
TYPE NMRBAUTOSIZE DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   fChanged AS LONG    ' BOOL fChanged
   rcTarget AS RECT    ' RECT rcTarget
   rcActual AS RECT    ' RECT rcActual
END TYPE

'#if (_WIN32_IE >= 0x0500)
' // Size = 44 bytes
TYPE NMREBARCHEVRON DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   uBand    AS DWORD   ' UINT uBand
   wID      AS DWORD   ' UINT wID
   lParam   AS LONG    ' LPARAM lParam
   rc       AS RECT    ' RECT rc
   lParamNM AS LONG    ' LPARAM lParamNM
END TYPE
'#endif

'#if (_WIN32_IE >= 0x0600)
' // Size = 28 bytes
TYPE NMREBARSPLITTER DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   rcSizing AS RECT    ' RECT rcSizing
END TYPE
'#endif

'#if (_WIN32_WINNT >= 0x0501)
%RBAB_AUTOSIZE = &H0001??? ' These are not flags and are all mutually exclusive
%RBAB_ADDBAND  = &H0002???

' // Size = 36 bytes
TYPE NMREBARAUTOBREAK DWORD
   hdr           AS NMHDR   ' NMHDR hdr
   uBand         AS DWORD   ' UINT uBand
   wID           AS DWORD   ' UINT wID
   lParam        AS LONG    ' LPARAM lParam
   uMsg          AS DWORD   ' UINT uMsg
   fStyleCurrent AS DWORD   ' UINT fStyleCurrent
   fAutoBreak    AS LONG    ' BOOL fAutoBreak
END TYPE

'#endif

%RBHT_NOWHERE  = &H0001???
%RBHT_CAPTION  = &H0002???
%RBHT_CLIENT   = &H0003???
%RBHT_GRABBER  = &H0004???
'#if (_WIN32_IE >= 0x0500)
%RBHT_CHEVRON  = &H0008???
'#endif
'#if (_WIN32_IE >= 0x0600)
%RBHT_SPLITTER = &H0010???
'#endif

' // Size = 16 bytes
TYPE RBHITTESTINFO DWORD
   pt    AS POINT   ' POINT pt
   flags AS DWORD   ' UINT flags
   iBand AS LONG    ' int iBand
END TYPE

'#endif      // _WIN32_IE >= 0x0400

#ENDIF    ' // NOREBAR

'#endif      // _WIN32_IE >= 0x0300

'//====== TOOLTIPS CONTROL =====================================================

#IF NOT %DEF(%NOTOOLTIPS)

$TOOLTIPS_CLASSA      = "tooltips_class32"
$$TOOLTIPS_CLASSW     = "tooltips_class32"$$
#IF %DEF(%UNICODE)
   MACRO TOOLTIPS_CLASS = $$TOOLTIPS_CLASSW
#ELSE
   MACRO TOOLTIPS_CLASS = $TOOLTIPS_CLASSA
#ENDIF

' // Size = 48 bytes
TYPE TOOLINFOA DWORD
   cbSize     AS DWORD        ' UINT cbSize
   uFlags     AS DWORD        ' UINT uFlags
   hwnd       AS DWORD        ' HWND hwnd
   uId        AS DWORD        ' UINT_PTR uId
   rect       AS RECT         ' RECT rect
   hinst      AS DWORD        ' HINSTANCE hinst
   lpszText   AS ASCIIZ PTR   ' LPSTR lpszText
#IF (%WIN32_IE >= &H0300)
   lParam     AS LONG         ' LPARAM lParam
#ENDIF
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   lpReserved AS DWORD        ' void *lpReserved
#ENDIF
END TYPE

' // Size = 48 bytes
TYPE TOOLINFOW DWORD
   cbSize     AS DWORD          ' UINT cbSize
   uFlags     AS DWORD          ' UINT uFlags
   hwnd       AS DWORD          ' HWND hwnd
   uId        AS DWORD          ' UINT_PTR uId
   rect       AS RECT           ' RECT rect
   hinst      AS DWORD          ' HINSTANCE hinst
   lpszText   AS WSTRINGZ PTR   ' LPWSTR lpszText
#IF (%WIN32_IE >= &H0300)
   lParam     AS LONG           ' LPARAM lParam
#ENDIF
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   lpReserved AS DWORD          ' void *lpReserved
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO TOOLINFO = TOOLINFOW
#ELSE
   MACRO TOOLINFO = TOOLINFOA
#ENDIF

%TTS_ALWAYSTIP      = &H01???
%TTS_NOPREFIX       = &H02???
'#if (_WIN32_IE >= 0x0500)
%TTS_NOANIMATE      = &H10???
%TTS_NOFADE         = &H20???
%TTS_BALLOON        = &H40???
%TTS_CLOSE          = &H80???
'#endif
'#if _WIN32_WINNT >= 0x0600
%TTS_USEVISUALSTYLE = &H100???   '  // Use themed hyperlinks
'#endif

%TTF_IDISHWND       = &H0001???

'// Use this to center around trackpoint in trackmode
'// -OR- to center around tool in normal mode.
'// Use TTF_ABSOLUTE to place the tip exactly at the track coords when
'// in tracking mode.  TTF_ABSOLUTE can be used in conjunction with TTF_CENTERTIP
'// to center the tip absolutely about the track point.

%TTF_CENTERTIP      = &H0002???
%TTF_RTLREADING     = &H0004???
%TTF_SUBCLASS       = &H0010???
'#if (_WIN32_IE >= 0x0300)
%TTF_TRACK          = &H0020???
%TTF_ABSOLUTE       = &H0080???
%TTF_TRANSPARENT    = &H0100???
'#if (_WIN32_IE >= 0x0501)
%TTF_PARSELINKS     = &H1000???
'#endif // _WIN32_IE >= 0x0501
%TTF_DI_SETITEM     = &H8000???  ' // valid only on the TTN_NEEDTEXT callback
'#endif      // _WIN32_IE >= 0x0300

%TTDT_AUTOMATIC     = 0
%TTDT_RESHOW        = 1
%TTDT_AUTOPOP       = 2
%TTDT_INITIAL       = 3

'// ToolTip Icons possible wParam values for TTM_SETTITLE message
%TTI_NONE           = 0
%TTI_INFO           = 1
%TTI_WARNING        = 2
%TTI_ERROR          = 3
'// Prior to Windows Vista: values larger thant TTI_ERROR are assumed to be an HICON value
' Windows Vista
'#if (_WIN32_WINNT >= 0x0600)
%TTI_INFO_LARGE     = 4
%TTI_WARNING_LARGE  = 5
%TTI_ERROR_LARGE    = 6
'#endif  // (_WIN32_WINNT >= 0x0600)

'// Tool Tip Messages
%TTM_ACTIVATE        = %WM_USER + 1
%TTM_SETDELAYTIME    = %WM_USER + 3
%TTM_ADDTOOLA        = %WM_USER + 4
%TTM_ADDTOOLW        = %WM_USER + 50
#IF %DEF(%UNICODE)
%TTM_ADDTOOL = %TTM_ADDTOOLW
#ELSE
%TTM_ADDTOOL = %TTM_ADDTOOLA
#ENDIF
%TTM_DELTOOLA        = %WM_USER + 5
%TTM_DELTOOLW        = %WM_USER + 51
#IF %DEF(%UNICODE)
%TTM_DELTOOL = %TTM_DELTOOLW
#ELSE
%TTM_DELTOOL = %TTM_DELTOOLA
#ENDIF
%TTM_NEWTOOLRECTA    = %WM_USER + 6
%TTM_NEWTOOLRECTW    = %WM_USER + 52
#IF %DEF(%UNICODE)
%TTM_NEWTOOLRECT = %TTM_NEWTOOLRECTW
#ELSE
%TTM_NEWTOOLRECT = %TTM_NEWTOOLRECTA
#ENDIF
%TTM_RELAYEVENT      = %WM_USER + 7   ' // Win7: wParam = GetMessageExtraInfo() when relaying WM_MOUSEMOVE

%TTM_GETTOOLINFOA    = %WM_USER + 8
%TTM_GETTOOLINFOW    = %WM_USER + 53
#IF %DEF(%UNICODE)
%TTM_GETTOOLINFO = %TTM_GETTOOLINFOW
#ELSE
%TTM_GETTOOLINFO = %TTM_GETTOOLINFOA
#ENDIF

%TTM_SETTOOLINFOA    = %WM_USER + 9
%TTM_SETTOOLINFOW    = %WM_USER + 54
#IF %DEF(%UNICODE)
%TTM_SETTOOLINFO = %TTM_SETTOOLINFOW
#ELSE
%TTM_SETTOOLINFO = %TTM_SETTOOLINFOA
#ENDIF

%TTM_HITTESTA        = %WM_USER + 10
%TTM_HITTESTW        = %WM_USER + 55
#IF %DEF(%UNICODE)
%TTM_HITTEST = %TTM_HITTESTW
#ELSE
%TTM_HITTEST = %TTM_HITTESTA
#ENDIF
%TTM_GETTEXTA        = %WM_USER + 11
%TTM_GETTEXTW        = %WM_USER + 56
#IF %DEF(%UNICODE)
%TTM_GETTEXT = %TTM_GETTEXTW
#ELSE
%TTM_GETTEXT = %TTM_GETTEXTA
#ENDIF
%TTM_UPDATETIPTEXTA  = %WM_USER + 12
%TTM_UPDATETIPTEXTW  = %WM_USER + 57
#IF %DEF(%UNICODE)
%TTM_UPDATETIPTEXT = %TTM_UPDATETIPTEXTW
#ELSE
%TTM_UPDATETIPTEXT = %TTM_UPDATETIPTEXTA
#ENDIF
%TTM_GETTOOLCOUNT    = %WM_USER + 13
%TTM_ENUMTOOLSA      = %WM_USER + 14
%TTM_ENUMTOOLSW      = %WM_USER + 58
#IF %DEF(%UNICODE)
%TTM_ENUMTOOLS = %TTM_ENUMTOOLSW
#ELSE
%TTM_ENUMTOOLS = %TTM_ENUMTOOLSA
#ENDIF
%TTM_GETCURRENTTOOLA = %WM_USER + 15
%TTM_GETCURRENTTOOLW = %WM_USER + 59
#IF %DEF(%UNICODE)
%TTM_GETCURRENTTOOL = %TTM_GETCURRENTTOOLW
#ELSE
%TTM_GETCURRENTTOOL = %TTM_GETCURRENTTOOLA
#ENDIF
%TTM_WINDOWFROMPOINT = %WM_USER + 16
'#if (_WIN32_IE >= 0x0300)
%TTM_TRACKACTIVATE   = %WM_USER + 17
%TTM_TRACKPOSITION   = %WM_USER + 18
%TTM_SETTIPBKCOLOR   = %WM_USER + 19
%TTM_SETTIPTEXTCOLOR = %WM_USER + 20
%TTM_GETDELAYTIME    = %WM_USER + 21
%TTM_GETTIPBKCOLOR   = %WM_USER + 22
%TTM_GETTIPTEXTCOLOR = %WM_USER + 23
%TTM_SETMAXTIPWIDTH  = %WM_USER + 24
%TTM_GETMAXTIPWIDTH  = %WM_USER + 25
%TTM_SETMARGIN       = %WM_USER + 26
%TTM_GETMARGIN       = %WM_USER + 27
%TTM_POP             = %WM_USER + 28
'#endif
'#if (_WIN32_IE >= 0x0400)
%TTM_UPDATE          = %WM_USER + 29
'#endif
'#if (_WIN32_IE >= 0x0500)
%TTM_GETBUBBLESIZE   = %WM_USER + 30
%TTM_ADJUSTRECT      = %WM_USER + 31
%TTM_SETTITLEA       = %WM_USER + 32  ' wParam = TTI_*, lParam = char* szTitle
%TTM_SETTITLEW       = %WM_USER + 33  ' wParam = TTI_*, lParam = wchar* szTitle
#IF %DEF(%UNICODE)
%TTM_SETTITLE = %TTM_SETTITLEW
#ELSE
%TTM_SETTITLE = %TTM_SETTITLEA
#ENDIF
'#endif

'#if (_WIN32_WINNT >= 0x0501)
'#define TTM_POPUP               (WM_USER + 34)
'#define TTM_GETTITLE            (WM_USER + 35) // wParam = 0, lParam = TTGETTITLE*

%TTM_POPUP           = %WM_USER + 34
%TTM_GETTITLE        = %WM_USER + 35  ' wParam = 0, lParam = TTGETTITLE*

' // Size = 16 bytes
TYPE TTGETTITLE DWORD
   dwSize       AS DWORD          ' DWORD dwSize
   uTitleBitmap AS DWORD          ' UINT uTitleBitmap
   cch          AS DWORD          ' UINT cch
   pszTitle     AS WSTRINGZ PTR   ' WCHAR* pszTitle
END TYPE

'#endif

'#if (_WIN32_WINNT >= 0x501)
%TTM_SETWINDOWTHEME  = %CCM_SETWINDOWTHEME
'#endif

' // Size = 60 bytes
TYPE TTHITTESTINFOA DWORD
   hWnd  AS DWORD       ' HWND hwnd
   pt    AS POINT       ' POINT pt
   ti    AS TOOLINFOA   ' TTTOOLINFOA ti
END TYPE

' // Size = 60 bytes
TYPE TTHITTESTINFOW DWORD
   hWnd  AS DWORD       ' HWND hwnd
   pt    AS POINT       ' POINT pt
   ti    AS TOOLINFOW   ' TTTOOLINFOW ti
END TYPE

MACRO TT_HITTESTINFOA = TTHITTESTINFOA
MACRO TT_HITTESTINFOW = TTHITTESTINFOW

#IF %DEF(%UNICODE)
   MACRO TTHITTESTINFO  = TTHITTESTINFOW
   MACRO TT_HITTESTINFO = TTHITTESTINFOW
#ELSE
   MACRO TTHITTESTINFO  = TTHITTESTINFOA
   MACRO TT_HITTESTINFO = TTHITTESTINFOA
#ENDIF

%TTN_GETDISPINFOA    = %TTN_FIRST - 0
%TTN_GETDISPINFOW    = %TTN_FIRST - 10
#IF %DEF(%UNICODE)
%TTN_GETDISPINFO = %TTN_GETDISPINFOW
#ELSE
%TTN_GETDISPINFO = %TTN_GETDISPINFOA
#ENDIF
%TTN_SHOW            = %TTN_FIRST - 1
%TTN_POP             = %TTN_FIRST - 2
%TTN_LINKCLICK       = %TTN_FIRST - 3

%TTN_NEEDTEXT        = %TTN_GETDISPINFO
%TTN_NEEDTEXTA       = %TTN_GETDISPINFOA
%TTN_NEEDTEXTW       = %TTN_GETDISPINFOW

' // Size = 108 bytes
TYPE NMTTDISPINFOA DWORD
   hdr       AS NMHDR         ' NMHDR hdr
   lpszText  AS ASCIIZ PTR    ' LPSTR lpszText
   szText    AS ASCIIZ * 80   ' char szText[80]
   hInst     AS DWORD         ' HINSTANCE hinst
   uFlags    AS DWORD         ' UINT uFlags
#IF (%WIN32_IE >= &H0300)
   lParam    AS DWORD         ' LPARAM lParam
#ENDIF
END TYPE

' // Size = 188 bytes
TYPE NMTTDISPINFOW DWORD
   hdr       AS NMHDR          ' NMHDR hdr
   lpszText  AS WSTRINGZ PTR   ' LPWSTR lpszText
   szText    AS WSTRINGZ * 80  ' WCHAR szText[80]
   hInst     AS DWORD          ' HINSTANCE hinst
   uFlags    AS DWORD          ' UINT uFlags
#IF (%WIN32_IE >= &H0300)
   lParam    AS DWORD          ' LPARAM lParam
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMTTDISPINFO = NMTTDISPINFOW
#ELSE
   MACRO NMTTDISPINFO = NMTTDISPINFOA
#ENDIF

' // Size = 108 bytes
TYPE TOOLTIPTEXTA DWORD
   hdr       AS NMHDR         ' NMHDR hdr
   lpszText  AS ASCIIZ PTR    ' LPSTR lpszText
   szText    AS ASCIIZ * 80   ' char szText[80]
   hInst     AS DWORD         ' HINSTANCE hinst
   uFlags    AS DWORD         ' UINT uFlags
#IF (%WIN32_IE >= &H0300)
   lParam    AS DWORD         ' LPARAM lParam
#ENDIF
END TYPE

' // Size = 188 bytes
TYPE TOOLTIPTEXTW DWORD
   hdr       AS NMHDR           ' NMHDR hdr
   lpszText  AS WSTRINGZ PTR    ' LPWSTR lpszText
   szText    AS WSTRINGZ * 80   ' WCHAR szText[80]
   hInst     AS DWORD           ' HINSTANCE hinst
   uFlags    AS DWORD           ' UINT uFlags
#IF (%WIN32_IE >= &H0300)
   lParam    AS DWORD             ' LPARAM lParam
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO TOOLTIPTEXT = TOOLTIPTEXTW
#ELSE
   MACRO TOOLTIPTEXT = TOOLTIPTEXTA
#ENDIF

#ENDIF     ' // NOTOOLTIPS


'//====== STATUS BAR CONTROL ===================================================

#IF NOT %DEF(%NOSTATUSBAR)

'%SBARS_SIZEGRIP = &H0100???
'#if (_WIN32_IE >= 0x0500)
'%SBARS_TOOLTIPS = &H0800???
'#endif

'#if (_WIN32_IE >= 0x0400)
'// this is a status bar flag, preference to SBARS_TOOLTIPS
'%SBT_TOOLTIPS   = &H0800???
'#endif

DECLARE SUB DrawStatusTextA IMPORT "COMCTL32.DLL" ALIAS "DrawStatusTextA" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in LPRECT lprc
 , BYREF pszText AS ASCIIZ _                            ' __in LPCSTR pszText
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 )                                                      ' void

DECLARE SUB DrawStatusTextW IMPORT "COMCTL32.DLL" ALIAS "DrawStatusTextW" ( _
   BYVAL hDC AS DWORD _                                 ' __in HDC hDC
 , BYREF lprc AS RECT _                                 ' __in LPRECT lprc
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO DrawStatusText = DrawStatusTextW
#ELSE
   MACRO DrawStatusText = DrawStatusTextA
#ENDIF

DECLARE FUNCTION CreateStatusWindowA IMPORT "COMCTL32.DLL" ALIAS "CreateStatusWindowA" ( _
   BYVAL style AS LONG _                                ' __in LONG style
 , BYREF lpszText AS ASCIIZ _                           ' __in LPCSTR lpszText
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL wID AS DWORD _                                 ' __in UINT wID
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION CreateStatusWindowW IMPORT "COMCTL32.DLL" ALIAS "CreateStatusWindowW" ( _
   BYVAL style AS LONG _                                ' __in LONG style
 , BYREF lpszText AS WSTRINGZ _                         ' __in LPCWSTR lpszText
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL wID AS DWORD _                                 ' __in UINT wID
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO CreateStatusWindow = CreateStatusWindowW
#ELSE
   MACRO CreateStatusWindow = CreateStatusWindowA
#ENDIF

$STATUSCLASSNAMEA      = "msctls_statusbar32"
$$STATUSCLASSNAMEW     = "msctls_statusbar32"$$
#IF %DEF(%UNICODE)
   MACRO STATUSCLASSNAME = $$STATUSCLASSNAMEW
#ELSE
   MACRO STATUSCLASSNAME = $STATUSCLASSNAMEA
#ENDIF

%SB_SETTEXTA          = %WM_USER + 1
%SB_SETTEXTW          = %WM_USER + 11
#IF %DEF(%UNICODE)
%SB_SETTEXT = %SB_SETTEXTW
#ELSE
%SB_SETTEXT = %SB_SETTEXTA
#ENDIF
%SB_GETTEXTA          = %WM_USER + 2
%SB_GETTEXTW          = %WM_USER + 13
#IF %DEF(%UNICODE)
%SB_GETTEXT = %SB_GETTEXTW
#ELSE
%SB_GETTEXT = %SB_GETTEXTA
#ENDIF
%SB_GETTEXTLENGTHA    = %WM_USER + 3
%SB_GETTEXTLENGTHW    = %WM_USER + 12
#IF %DEF(%UNICODE)
%SB_GETTEXTLENGTH = %SB_GETTEXTLENGTHW
#ELSE
%SB_GETTEXTLENGTH = %SB_GETTEXTLENGTHA
#ENDIF

%SB_SETPARTS          = %WM_USER + 4
%SB_GETPARTS          = %WM_USER + 6
%SB_GETBORDERS        = %WM_USER + 7
%SB_SETMINHEIGHT      = %WM_USER + 8
%SB_SIMPLE            = %WM_USER + 9
%SB_GETRECT           = %WM_USER + 10
'#if (_WIN32_IE >= 0x0300)
%SB_ISSIMPLE          = %WM_USER + 14
'#endif
'#if (_WIN32_IE >= 0x0400)
%SB_SETICON           = %WM_USER + 15
%SB_SETTIPTEXTA       = %WM_USER + 16
%SB_SETTIPTEXTW       = %WM_USER + 17
#IF %DEF(%UNICODE)
%SB_SETTIPTEXT = %SB_SETTIPTEXTW
#ELSE
%SB_SETTIPTEXT = %SB_SETTIPTEXTA
#ENDIF
%SB_GETTIPTEXTA       = %WM_USER + 18
%SB_GETTIPTEXTW       = %WM_USER + 19
#IF %DEF(%UNICODE)
%SB_GETTIPTEXT = %SB_GETTIPTEXTW
#ELSE
%SB_GETTIPTEXT = %SB_GETTIPTEXTA
#ENDIF
%SB_GETICON           = %WM_USER + 20
%SB_SETUNICODEFORMAT  = %CCM_SETUNICODEFORMAT
%SB_GETUNICODEFORMAT  = %CCM_GETUNICODEFORMAT
'#endif

'%SBT_OWNERDRAW        = &H1000??
'%SBT_NOBORDERS        = &H0100??
'%SBT_POPOUT           = &H0200??
'%SBT_RTLREADING       = &H0400??
%SBT_TOOLTIPS         = &H0800??   ' Not present in the XP and Vista SDKs
'#if (_WIN32_IE >= 0x0500)
%SBT_NOTABPARSING     = &H0800??
'#endif

%SB_SETBKCOLOR        = %CCM_SETBKCOLOR  ' lParam = bkColor

'/// status bar notifications
'#if (_WIN32_IE >= 0x0400)
%SBN_SIMPLEMODECHANGE = %SBN_FIRST
'#endif

'#if (_WIN32_IE >= 0x0500)
'// refers to the data saved for simple mode
%SB_SIMPLEID = &H00FF??
'#endif

#ENDIF    ' // NOSTATUSBAR

'//====== MENU HELP ============================================================

#IF NOT %DEF(%NOMENUHELP)

DECLARE SUB MenuHelp IMPORT "COMCTL32.DLL" ALIAS "MenuHelp" ( _
   BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL hMainMenu AS DWORD _                           ' __in HMENU hMainMenu
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYVAL hwndStatus AS DWORD _                          ' __in HWND hwndStatus
 , BYREF lpwIDs AS DWORD _                              ' __out UINT *lpwIDs
 )                                                      ' void

DECLARE FUNCTION ShowHideMenuCtl IMPORT "COMCTL32.DLL" ALIAS "ShowHideMenuCtl" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL uFlags AS DWORD _                              ' __in UINT_PTR uFlags
 , BYREF lpInfo AS LONG _                               ' __out LPINT lpInfo
 ) AS LONG                                              ' BOOL

DECLARE SUB GetEffectiveClientRect IMPORT "COMCTL32.DLL" ALIAS "GetEffectiveClientRect" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF lprc AS RECT _                                 ' __in LPRECT lprc
 , BYREF lpInfo AS LONG _                               ' __in LPINT lpInfo [array]
 )                                                      ' void

%MINSYSCOMMAND  = %SC_SIZE

#ENDIF   ' // NOMENUHELP


'//====== TRACKBAR CONTROL =====================================================

#IF NOT %DEF(%NOTRACKBAR)

$TRACKBAR_CLASSA      = "msctls_trackbar32"
$$TRACKBAR_CLASSW     = "msctls_trackbar32"$$
#IF %DEF(%UNICODE)
   MACRO TRACKBAR_CLASS = $$TRACKBAR_CLASSW
#ELSE
   MACRO TRACKBAR_CLASS = $TRACKBAR_CLASSA
#ENDIF

%TBS_AUTOTICKS      = &H0001???
%TBS_VERT           = &H0002???
%TBS_HORZ           = &H0000???
%TBS_TOP            = &H0004???
%TBS_BOTTOM         = &H0000???
%TBS_LEFT           = &H0004???
%TBS_RIGHT          = &H0000???
%TBS_BOTH           = &H0008???
%TBS_NOTICKS        = &H0010???
%TBS_ENABLESELRANGE = &H0020???
%TBS_FIXEDLENGTH    = &H0040???
%TBS_NOTHUMB        = &H0080???
'#if (_WIN32_IE >= 0x0300)
%TBS_TOOLTIPS       = &H0100???
'#endif
'#if (_WIN32_IE >= 0x0500)
%TBS_REVERSED       = &H0200???  ' Accessibility hint: the smaller number (usually the min value) means "high" and the larger number (usually the max value) means "low"
'#endif

'#if (_WIN32_IE >= 0x0501)
%TBS_DOWNISLEFT     = &H0400???  ' Down=Left and Up=Right (default is Down=Right and Up=Left)
'#endif

'#if (_WIN32_IE >= 0x0600)
%TBS_NOTIFYBEFOREMOVE = &H0800???  ' // Trackbar should notify parent before repositioning the slider due to user action (enables snapping)
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%TBS_TRANSPARENTBKGND = &H1000???  ' // Background is painted by the parent via WM_PRINTCLIENT
'#endif

%TBM_GETPOS             = %WM_USER
%TBM_GETRANGEMIN        = %WM_USER + 1
%TBM_GETRANGEMAX        = %WM_USER + 2
%TBM_GETTIC             = %WM_USER + 3
%TBM_SETTIC             = %WM_USER + 4
%TBM_SETPOS             = %WM_USER + 5
%TBM_SETRANGE           = %WM_USER + 6
%TBM_SETRANGEMIN        = %WM_USER + 7
%TBM_SETRANGEMAX        = %WM_USER + 8
%TBM_CLEARTICS          = %WM_USER + 9
%TBM_SETSEL             = %WM_USER + 10
%TBM_SETSELSTART        = %WM_USER + 11
%TBM_SETSELEND          = %WM_USER + 12
%TBM_GETPTICS           = %WM_USER + 14
%TBM_GETTICPOS          = %WM_USER + 15
%TBM_GETNUMTICS         = %WM_USER + 16
%TBM_GETSELSTART        = %WM_USER + 17
%TBM_GETSELEND          = %WM_USER + 18
%TBM_CLEARSEL           = %WM_USER + 19
%TBM_SETTICFREQ         = %WM_USER + 20
%TBM_SETPAGESIZE        = %WM_USER + 21
%TBM_GETPAGESIZE        = %WM_USER + 22
%TBM_SETLINESIZE        = %WM_USER + 23
%TBM_GETLINESIZE        = %WM_USER + 24
%TBM_GETTHUMBRECT       = %WM_USER + 25
%TBM_GETCHANNELRECT     = %WM_USER + 26
%TBM_SETTHUMBLENGTH     = %WM_USER + 27
%TBM_GETTHUMBLENGTH     = %WM_USER + 28
'#if (_WIN32_IE >= 0x0300)
%TBM_SETTOOLTIPS        = %WM_USER + 29
%TBM_GETTOOLTIPS        = %WM_USER + 30
%TBM_SETTIPSIDE         = %WM_USER + 31
'// TrackBar Tip Side flags
%TBTS_TOP               = 0
%TBTS_LEFT              = 1
%TBTS_BOTTOM            = 2
%TBTS_RIGHT             = 3

%TBM_SETBUDDY           = %WM_USER + 32 ' wparam = BOOL fLeft; (or right)
%TBM_GETBUDDY           = %WM_USER + 33 ' wparam = BOOL fLeft; (or right)
%TBM_SETPOSNOTIFY       = %WM_USER + 34
'#endif
'#if (_WIN32_IE >= 0x0400)
%TBM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT
%TBM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT
'#endif

%TB_LINEUP              = 0
%TB_LINEDOWN            = 1
%TB_PAGEUP              = 2
%TB_PAGEDOWN            = 3
%TB_THUMBPOSITION       = 4
%TB_THUMBTRACK          = 5
%TB_TOP                 = 6
%TB_BOTTOM              = 7
%TB_ENDTRACK            = 8

'#if (_WIN32_IE >= 0x0300)
'// custom draw item specs
%TBCD_TICS    = &H0001???
%TBCD_THUMB   = &H0002???
%TBCD_CHANNEL = &H0003???
'#endif

'#if (_WIN32_WINNT >= 0x0600)
%TRBN_THUMBPOSCHANGING = %TRBN_FIRST - 1

'// Structure for Trackbar's TRBN_THUMBPOSCHANGING notification
' // Size = 20 bytes
TYPE tagTRBTHUMBPOSCHANGING DWORD
   hdr     AS NMHDR   ' NMHDR hdr
   dwPos   AS DWORD   ' DWORD dwPos
   nReason AS LONG    ' int nReason
END TYPE
MACRO NMTRBTHUMBPOSCHANGING = tagTRBTHUMBPOSCHANGING
'#endif

#ENDIF  ' // NOTRACKBAR

'//====== DRAG LIST CONTROL ====================================================

#IF NOT %DEF(%NODRAGLIST)

' // Size = 16 bytes
TYPE DRAGLISTINFO DWORD
   uNotification AS DWORD   ' UINT uNotification
   hWnd          AS DWORD   ' HWND hWnd
   ptCursor      AS POINT   ' POINT ptCursor
END TYPE

%DL_BEGINDRAG  = %WM_USER + 133
%DL_DRAGGING   = %WM_USER + 134
%DL_DROPPED    = %WM_USER + 135
%DL_CANCELDRAG = %WM_USER + 136

%DL_CURSORSET  = 0
%DL_STOPCURSOR = 1
%DL_COPYCURSOR = 2
%DL_MOVECURSOR = 3

'#define DRAGLISTMSGSTRING       TEXT("commctrl_DragListMsg")
$DRAGLISTMSGSTRING = "commctrl_DragListMsg"

DECLARE FUNCTION MakeDragList IMPORT "COMCTL32.DLL" ALIAS "MakeDragList" ( _
   BYVAL hLD AS DWORD _                                 ' __in HWND hLD
 ) AS LONG                                              ' BOOL

DECLARE SUB DrawInsert IMPORT "COMCTL32.DLL" ALIAS "DrawInsert" ( _
   BYVAL handParent AS DWORD _                          ' __in HWND handParent
 , BYVAL hLB AS DWORD _                                 ' __in HWND hLB
 , BYVAL nItem AS LONG _                                ' __in int nItem
 )                                                      ' void

DECLARE FUNCTION LBItemFromPt IMPORT "COMCTL32.DLL" ALIAS "LBItemFromPt" ( _
   BYVAL hLB AS DWORD _                                 ' __in HWND hLB
 , BYVAL pt AS POINT _                                  ' __in pt POINT
 , BYVAL bAutoScroll AS LONG _                          ' __in BOOL bAutoScroll
 ) AS LONG                                              ' int

' // Same as above but using x, y coordinates
DECLARE FUNCTION LBItemFromXY IMPORT "COMCTL32.DLL" ALIAS "LBItemFromPt" ( _
   BYVAL hLB AS DWORD _                                 ' __in HWND hLB
 , BYVAL x AS LONG _                                    ' __in x
 , BYVAL y AS LONG _                                    ' __in y
 , BYVAL bAutoScroll AS LONG _                          ' __in BOOL bAutoScroll
 ) AS LONG                                              ' int

#ENDIF   ' // NODRAGLIST


'//====== UPDOWN CONTROL =======================================================

#IF NOT %DEF(%NOUPDOWN)

$UPDOWN_CLASSA      = "msctls_updown32"
$$UPDOWN_CLASSW     = "msctls_updown32"$$
#IF %DEF(%UNICODE)
   MACRO UPDOWN_CLASS = $$UPDOWN_CLASSW
#ELSE
   MACRO UPDOWN_CLASS = $UPDOWN_CLASSA
#ENDIF

' // Size = 8 bytes
TYPE UDACCEL DWORD
   nSec AS DWORD   ' UINT nSec
   nInc AS DWORD   ' UINT nInc
END TYPE

%UD_MAXVAL            = &H7FFF%         ' 0x7fff
%UD_MINVAL            = - %UD_MAXVAL   ' (-UD_MAXVAL)

%UDS_WRAP             = &H0001???
%UDS_SETBUDDYINT      = &H0002???
%UDS_ALIGNRIGHT       = &H0004???
%UDS_ALIGNLEFT        = &H0008???
%UDS_AUTOBUDDY        = &H0010???
%UDS_ARROWKEYS        = &H0020???
%UDS_HORZ             = &H0040???
%UDS_NOTHOUSANDS      = &H0080???
'#if (_WIN32_IE >= 0x0300)
%UDS_HOTTRACK         = &H0100???
'#endif

%UDM_SETRANGE         = %WM_USER + 101
%UDM_GETRANGE         = %WM_USER + 102
%UDM_SETPOS           = %WM_USER + 103
%UDM_GETPOS           = %WM_USER + 104
%UDM_SETBUDDY         = %WM_USER + 105
%UDM_GETBUDDY         = %WM_USER + 106
%UDM_SETACCEL         = %WM_USER + 107
%UDM_GETACCEL         = %WM_USER + 108
%UDM_SETBASE          = %WM_USER + 109
%UDM_GETBASE          = %WM_USER + 110
'#if (_WIN32_IE >= 0x0400)
%UDM_SETRANGE32       = %WM_USER + 111
%UDM_GETRANGE32       = %WM_USER + 112 ' wParam & lParam are LPINT
%UDM_SETUNICODEFORMAT = %CCM_SETUNICODEFORMAT
%UDM_GETUNICODEFORMAT = %CCM_GETUNICODEFORMAT
'#endif
'#if (_WIN32_IE >= 0x0500)
%UDM_SETPOS32         = %WM_USER + 113
%UDM_GETPOS32         = %WM_USER + 114
'#endif

DECLARE FUNCTION CreateUpDownControl IMPORT "COMCTL32.DLL" ALIAS "CreateUpDownControl" ( _
   BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYVAL hParent AS DWORD _                             ' __in HWND hParent
 , BYVAL nID AS LONG _                                  ' __in int nID
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYVAL hBuddy AS DWORD _                              ' __in HWND hBuddy
 , BYVAL nUpper AS LONG _                               ' __in int nUpper
 , BYVAL nLower AS LONG _                               ' __in int nLower
 , BYVAL nPos AS LONG _                                 ' __in int nPos
 ) AS DWORD                                             ' HWND

' // Size = 20 bytes
TYPE NM_UPDOWN DWORD
   hdr    AS NMHDR   ' NMHDR hdr
   iPos   AS LONG    ' int iPos
   iDelta AS LONG    ' int iDelta
END TYPE

MACRO NMUPDOWN = NM_UPDOWN

%UDN_DELTAPOS = %UDN_FIRST - 1

#ENDIF  ' // NOUPDOWN


'//====== PROGRESS CONTROL =====================================================

#IF NOT %DEF(%NOPROGRESS)

$PROGRESS_CLASSA         = "msctls_progress32"
$$PROGRESS_CLASSW        = "msctls_progress32"$$
#IF %DEF(%UNICODE)
   MACRO PROGRESS_CLASS = $$PROGRESS_CLASSW
#ELSE
   MACRO PROGRESS_CLASS = $PROGRESS_CLASSA
#ENDIF

'#if (_WIN32_IE >= 0x0300)
'%PBS_SMOOTH     = &H01???
'%PBS_VERTICAL   = &H04???
'#endif

%PBM_SETRANGE    = %WM_USER + 1
%PBM_SETPOS      = %WM_USER + 2
%PBM_DELTAPOS    = %WM_USER + 3
%PBM_SETSTEP     = %WM_USER + 4
%PBM_STEPIT      = %WM_USER + 5

'#if (_WIN32_IE >= 0x0300)
%PBM_SETRANGE32  = %WM_USER + 6  ' lParam = high, wParam = low

' // Size = 8 bytes
TYPE PBRANGE DWORD
   iLow  AS LONG   ' int iLow
   iHigh AS LONG   ' int iHigh
END TYPE

%PBM_GETRANGE    = %WM_USER + 7     ' wParam = return (TRUE ? low : high). lParam = PPBRANGE or NULL
%PBM_GETPOS      = %WM_USER + 8

'#if (_WIN32_IE >= 0x0400)
%PBM_SETBARCOLOR = %WM_USER + 9     ' lParam = bar color
'#endif      // _WIN32_IE >= 0x0400

%PBM_SETBKCOLOR  = %CCM_SETBKCOLOR  ' lParam = bkColor

'#endif      // _WIN32_IE >= 0x0300

'#if (_WIN32_WINNT >= 0x0501)
%PBS_MARQUEE             = &H08???
'#endif      // _WIN32_WINNT >= 0x0501

'#if (_WIN32_WINNT >= 0x0501)
%PBM_SETMARQUEE          = %WM_USER + 10
'#endif      // _WIN32_WINNT >= 0x0501

'#if _WIN32_WINNT >= 0x0600
%PBS_SMOOTHREVERSE       = &H10???
'#endif       // _WIN32_WINNT >= 0x0600

'#if _WIN32_WINNT >= 0x0600

%PBM_GETSTEP             = %WM_USER + 13
%PBM_GETBKCOLOR          = %WM_USER + 14
%PBM_GETBARCOLOR         = %WM_USER + 15
%PBM_SETSTATE            = %WM_USER + 16  ' // wParam = PBST_[State] (NORMAL, ERROR, PAUSED)
%PBM_GETSTATE            = %WM_USER + 17

%PBST_NORMAL             = &H0001???
%PBST_ERROR              = &H0002???
%PBST_PAUSED             = &H0003???
'#endif      // _WIN32_WINNT >= 0x0600

#ENDIF  ' // NOPROGRESS


'//====== HOTKEY CONTROL =======================================================

#IF NOT %DEF(%NOHOTKEY)

%HOTKEYF_SHIFT   = &H01??
%HOTKEYF_CONTROL = &H02??
%HOTKEYF_ALT     = &H04??
%HOTKEYF_EXT     = &H08??

%HKCOMB_NONE     = &H0001???
%HKCOMB_S        = &H0002???
%HKCOMB_C        = &H0004???
%HKCOMB_A        = &H0008???
%HKCOMB_SC       = &H0010???
%HKCOMB_SA       = &H0020???
%HKCOMB_CA       = &H0040???
%HKCOMB_SCA      = &H0080???

%HKM_SETHOTKEY   = %WM_USER + 1
%HKM_GETHOTKEY   = %WM_USER + 2
%HKM_SETRULES    = %WM_USER + 3

$HOTKEY_CLASSA      = "msctls_hotkey32"
$$HOTKEY_CLASSW     = "msctls_hotkey32"$$
#IF %DEF(%UNICODE)
   MACRO HOTKEY_CLASS = $$HOTKEY_CLASSW
#ELSE
   MACRO HOTKEY_CLASS = $HOTKEY_CLASSA
#ENDIF

#ENDIF  ' // NOHOTKEY

'//====== COMMON CONTROL STYLES ================================================

'%CCS_TOP           = &H00000001???
'%CCS_NOMOVEY       = &H00000002???
'%CCS_BOTTOM        = &H00000003???
'%CCS_NORESIZE      = &H00000004???
'%CCS_NOPARENTALIGN = &H00000008???
'%CCS_ADJUSTABLE    = &H00000020???
'%CCS_NODIVIDER     = &H00000040???
'#if (_WIN32_IE >= 0x0300)
'%CCS_VERT          = &H00000080???
'%CCS_LEFT          = %CCS_VERT OR %CCS_TOP
'%CCS_RIGHT         = %CCS_VERT OR %CCS_BOTTOM
'%CCS_NOMOVEX       = %CCS_VERT OR %CCS_NOMOVEY
'#endif

'//====== SysLink control =========================================

'#if (_WIN32_WINNT >= 0x501)

'#define INVALID_LINK_INDEX  (-1)
'#define MAX_LINKID_TEXT     48
'#define L_MAX_URL_LENGTH    (2048 + 32 + sizeof("://"))

%INVALID_LINK_INDEX = -1
%MAX_LINKID_TEXT    = 48
%L_MAX_URL_LENGTH   = 2048 + 32 + 4

$$WC_LINK = "SysLink"$$
MACRO WC_LINK = $$WC_LINK

%LWS_TRANSPARENT    = &H0001???
%LWS_IGNORERETURN   = &H0002???
'#if _WIN32_WINNT >= 0x0600
%LWS_NOPREFIX       = &H0004???
%LWS_USEVISUALSTYLE = &H0008???
%LWS_USECUSTOMTEXT  = &H0010???
%LWS_RIGHT          = &H0020???
'#endif // _WIN32_WINNT >= 0x600

%LIF_ITEMINDEX      = &H00000001???
%LIF_STATE          = &H00000002???
%LIF_ITEMID         = &H00000004???
%LIF_URL            = &H00000008???

%LIS_FOCUSED        = &H00000001???
%LIS_ENABLED        = &H00000002???
%LIS_VISITED        = &H00000004???
'#if _WIN32_WINNT >= 0x0600
%LIS_HOTTRACK       = &H00000008???
%LIS_DEFAULTCOLORS  = &H00000010???   ' // Don't use any custom text colors
'#endif

' // Size = 4280 bytes
TYPE LITEM DWORD
   mask      AS DWORD                          ' UINT  mask
   iLink     AS LONG                           ' int   iLink
   state     AS DWORD                          ' UINT  state
   stateMask AS DWORD                          ' UINT  stateMask
   szID      AS WSTRINGZ * %MAX_LINKID_TEXT    ' WCHAR szID[MAX_LINKID_TEXT]
   szUrl     AS WSTRINGZ * %L_MAX_URL_LENGTH   ' WCHAR szUrl[L_MAX_URL_LENGTH]
END TYPE

' // Size = 4288 bytes
TYPE LHITTESTINFO DWORD
   pt   AS POINT   ' POINT pt
   item AS LITEM   ' LITEM item
END TYPE

' // Size = 4292 bytes
TYPE NMLINK DWORD
   hdr  AS NMHDR   ' NMHDR hdr
   item AS LITEM   ' LITEM item
END TYPE

'//  SysLink notifications
'//  NM_CLICK   // wParam: control ID, lParam: PNMLINK, ret: ignored.

'//  LinkWindow messages
' LinkWindow messages
%LM_HITTEST        = %WM_USER + &H300  ' wParam: n/a, lparam: PLHITTESTINFO, ret: BOOL
%LM_GETIDEALHEIGHT = %WM_USER + &H301  ' wParam: n/a, lparam: n/a, ret: cy
%LM_SETITEM        = %WM_USER + &H302  ' wParam: n/a, lparam: LITEM*, ret: BOOL
%LM_GETITEM        = %WM_USER + &H303  ' wParam: n/a, lparam: LITEM*, ret: BOOL
%LM_GETIDEALSIZE   = %LM_GETIDEALHEIGHT  ' // wParam: cxMaxWidth, lparam: SIZE*, ret: cy

'#endif

'//====== End SysLink control =========================================


'//====== LISTVIEW CONTROL =====================================================

#IF NOT %DEF(%NOLISTVIEW)

$WC_LISTVIEWA     = "SysListView32"
$$WC_LISTVIEWW    = "SysListView32"$$
#IF %DEF(%UNICODE)
   MACRO WC_LISTVIEW = $$WC_LISTVIEWW
#ELSE
   MACRO WC_LISTVIEW = $WC_LISTVIEWA
#ENDIF

'%LVS_ICON            = &H0000???
'%LVS_REPORT          = &H0001???
'%LVS_SMALLICON       = &H0002???
'%LVS_LIST            = &H0003???
'%LVS_TYPEMASK        = &H0003???
'%LVS_SINGLESEL       = &H0004???
'%LVS_SHOWSELALWAYS   = &H0008???
'%LVS_SORTASCENDING   = &H0010???
'%LVS_SORTDESCENDING  = &H0020???
'%LVS_SHAREIMAGELISTS = &H0040???
'%LVS_NOLABELWRAP     = &H0080???
'%LVS_AUTOARRANGE     = &H0100???
'%LVS_EDITLABELS      = &H0200???
'#if (_WIN32_IE >= 0x0300)
'%LVS_OWNERDATA       = &H1000???
'#endif
'%LVS_NOSCROLL        = &H2000???

%LVS_TYPESTYLEMASK   = &HFC00???

'%LVS_ALIGNTOP        = &H0000???
'%LVS_ALIGNLEFT       = &H0800???
'%LVS_ALIGNMASK       = &H0C00???

'%LVS_OWNERDRAWFIXED  = &H0400???
'%LVS_NOCOLUMNHEADER  = &H4000???
'%LVS_NOSORTHEADER    = &H8000???

'#if (_WIN32_IE >= 0x0400)

%LVM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT
%LVM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT
'%LVM_GETBKCOLOR         = %LVM_FIRST + 0
'%LVM_SETBKCOLOR         = %LVM_FIRST + 1
'%LVM_GETIMAGELIST       = %LVM_FIRST + 2

%LVSIL_NORMAL           = 0
%LVSIL_SMALL            = 1
%LVSIL_STATE            = 2
%LVSIL_GROUPHEADER      = 3

'%LVM_SETIMAGELIST       = %LVM_FIRST + 3
'%LVM_GETITEMCOUNT       = %LVM_FIRST + 4

%LVIF_TEXT              = &H00000001???
%LVIF_IMAGE             = &H00000002???
%LVIF_PARAM             = &H00000004???
%LVIF_STATE             = &H00000008???
'#if (_WIN32_IE >= 0x0300)
%LVIF_INDENT            = &H00000010???
%LVIF_NORECOMPUTE       = &H00000800???
'#endif
'#if (_WIN32_WINNT >= 0x501)
%LVIF_GROUPID           = &H00000100???
%LVIF_COLUMNS           = &H00000200???
'#endif

'#if _WIN32_WINNT >= 0x0600
%LVIF_COLFMT            = &H00010000???   ' // The piColFmt member is valid in addition to puColumns
'#endif

%LVIS_FOCUSED           = &H0001???
%LVIS_SELECTED          = &H0002???
%LVIS_CUT               = &H0004???
%LVIS_DROPHILITED       = &H0008???
%LVIS_GLOW              = &H0010???
%LVIS_ACTIVATING        = &H0020???

%LVIS_OVERLAYMASK       = &H0F00???
%LVIS_STATEIMAGEMASK    = &HF000???

'#define INDEXTOSTATEIMAGEMASK(i) ((i) << 12)

#IF NOT %DEF(%ITSIM)
%ITSIM = 1
FUNCTION IndexToStateImageMask (BYVAL i AS LONG) AS LONG
   SHIFT LEFT i, 12
   FUNCTION = i
END FUNCTION
#ENDIF

'#if (_WIN32_IE >= 0x0300)
%I_INDENTCALLBACK    = -1
'#endif

'#if (_WIN32_WINNT >= 0x501)
%I_GROUPIDCALLBACK   = -1
%I_GROUPIDNONE       = -2
'#endif

' // Size = 60 bytes (52 bytes in XP)
TYPE LVITEMA DWORD
   mask       AS DWORD       ' UINT mask
   iItem      AS LONG        ' int iItem
   iSubItem   AS LONG        ' int iSubItem
   state      AS DWORD       ' UINT state
   stateMask  AS DWORD       ' UINT stateMask
   pszText    AS ASCIIZ PTR  ' LPSTR pszText
   cchTextMax AS LONG        ' int cchTextMax
   iImage     AS LONG        ' int iImage
   lParam     AS LONG        ' LPARAM lParam
#IF (%WIN32_IE >= &H0300)
   iIndent    AS LONG        ' int iIndent
#ENDIF
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   iGroupId   AS LONG        ' int iGroupId
   cColumns   AS DWORD       ' UINT cColumns // tile view columns
   puColumns  AS DWORD PTR   ' PUINT puColumns
#ENDIF
'#IF %WIN32_WINNT >= &H0600 ' Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
#IF %WINVER >= &H0600
   piColFmt   AS LONG PTR    ' int *
   iGroup     AS LONG        ' int // readonly. only valid for owner data.
#ENDIF
END TYPE

' // Size = 60 bytes (52 bytes in XP)
TYPE LVITEMW DWORD
   mask       AS DWORD          ' UINT mask
   iItem      AS LONG           ' int iItem
   iSubItem   AS LONG           ' int iSubItem
   state      AS DWORD          ' UINT state
   stateMask  AS DWORD          ' UINT stateMask
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax AS LONG           ' int cchTextMax
   iImage     AS LONG           ' int iImage
   lParam     AS LONG           ' LPARAM lParam
#IF (%WIN32_IE >= &H0300)
   iIndent    AS LONG           ' int iIndent
#ENDIF
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   iGroupId   AS LONG           ' int iGroupId
   cColumns   AS DWORD          ' UINT cColumns // tile view columns
   puColumns  AS DWORD PTR      ' PUINT puColumns
#ENDIF
'#IF %WIN32_WINNT >= &H0600 ' Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
#IF %WINVER >= &H0600
   piColFmt   AS LONG PTR       ' int *
   iGroup     AS LONG           ' int // readonly. only valid for owner data.
#ENDIF
END TYPE

MACRO LV_ITEMA  = LVITEMA
MACRO LV_ITEMW  = LVITEMW

#IF %DEF(%UNICODE)
   MACRO LVITEM  = LVITEMW
   MACRO LV_ITEM = LVITEMW
#ELSE
   MACRO LVITEM  = LVITEMA
   MACRO LV_ITEM = LVITEMA
#ENDIF

%LVITEM_V1_SIZE = 52
%LVITEM_V6_SIZE = 60

%LPSTR_TEXTCALLBACKW    = -1&   ' ((LPWSTR)-1L)
%LPSTR_TEXTCALLBACK     = -1&   ' ((LPSTR)-1L)

%I_IMAGECALLBACK        = -1&
'#if (_WIN32_IE >= 0x0501)
%I_IMAGENONE            = -2&
'#endif  // 0x0501

'#if (_WIN32_WINNT >= 0x501)
'// For tileview
%I_COLUMNSCALLBACK      = &HFFFFFFFF???   ' ((UINT)-1)
'#endif

' // LVM_GETITEMA and LVM_GETITEMW are predefined in the compiler, but
' // LVM_GETITEMA is called LVM_GETITEM, so we need to redefine it.
%LVM_GETITEMA           = %LVM_FIRST + 5
%LVM_GETITEMW           = %LVM_FIRST + 75
#IF %DEF(%UNICODE)
%LVM_GETITEM = %LVM_GETITEMW
#ELSE
%LVM_GETITEM = %LVM_GETITEMA
#ENDIF
' // LVM_SETITEMA and LVM_SETITEMW are predefined in the compiler, but
' // LVM_SETITEMA is called LVM_SETITEM, so we need to redefine it.
%LVM_SETITEMA           = %LVM_FIRST + 6
%LVM_SETITEMW           = %LVM_FIRST + 76
#IF %DEF(%UNICODE)
%LVM_SETITEM = %LVM_SETITEMW
#ELSE
%LVM_SETITEM = %LVM_SETITEMA
#ENDIF
' // LVM_INSERTITEMA and LVM_INSERTITEMW are predefined in the compiler, but
' // LVM_INSERTITEMA is called LVM_INSERTITEM, so we need to redefine it.
%LVM_INSERTITEMA        = %LVM_FIRST + 7
%LVM_INSERTITEMW        = %LVM_FIRST + 77
#IF %DEF(%UNICODE)
%LVM_INSERTITEM = %LVM_INSERTITEMW
#ELSE
%LVM_INSERTITEM = %LVM_INSERTITEMA
#ENDIF
'%LVM_DELETEITEM         = %LVM_FIRST + 8
'%LVM_DELETEALLITEMS     = %LVM_FIRST + 9
'%LVM_GETCALLBACKMASK    = %LVM_FIRST + 10
'%LVM_SETCALLBACKMASK    = %LVM_FIRST + 11

'%LVNI_ALL               = &H0000???

'%LVNI_FOCUSED           = &H0001???
'%LVNI_SELECTED          = &H0002???
'%LVNI_CUT               = &H0004???
'%LVNI_DROPHILITED       = &H0008???
%LVNI_STATEMASK         = %LVNI_FOCUSED OR %LVNI_SELECTED OR %LVNI_CUT OR %LVNI_DROPHILITED

%LVNI_VISIBLEORDER      = &H0010???
%LVNI_PREVIOUS          = &H0020???
%LVNI_VISIBLEONLY       = &H0040???
%LVNI_SAMEGROUPONLY     = &H0080???

'%LVNI_ABOVE             = &H0100???
'%LVNI_BELOW             = &H0200???
'%LVNI_TOLEFT            = &H0400???
'%LVNI_TORIGHT           = &H0800???
%LVNI_DIRECTIONMASK     = %LVNI_ABOVE OR %LVNI_BELOW OR %LVNI_TOLEFT OR %LVNI_TORIGHT


'%LVM_GETNEXTITEM        = %LVM_FIRST + 12

%LVFI_PARAM             = &H0001???
%LVFI_STRING            = &H0002???
%LVFI_SUBSTRING         = &H0004???   ' // Same as LVFI_PARTIAL
%LVFI_PARTIAL           = &H0008???
%LVFI_WRAP              = &H0020???
%LVFI_NEARESTXY         = &H0040???

' // Size = 24 bytes
TYPE LVFINDINFOA DWORD
   flags       AS DWORD        ' UINT   flags
   psz         AS ASCIIZ PTR   ' LPCSTR psz
   lParam      AS LONG         ' LPARAM lParam
   pt          AS POINT        ' POINT  pt
   vkDirection AS DWORD        ' UINT   vkDirection
END TYPE

' // Size = 24 bytes
TYPE LVFINDINFOW DWORD
   flags       AS DWORD          ' UINT    flags
   psz         AS WSTRINGZ PTR   ' LPCWSTR psz
   lParam      AS LONG           ' LPARAM  lParam
   pt          AS POINT          ' POINT   pt
   vkDirection AS DWORD          ' UINT    vkDirection
END TYPE

MACRO LV_FINDINFOA = LVFINDINFOA
MACRO LV_FINDINFOW = LVFINDINFOW

#IF %DEF(%UNICODE)
   MACRO LVFINDINFO   = LVFINDINFOW
   MACRO LV_FINDINFO  = LVFINDINFOW
#ELSE
   MACRO LVFINDINFO   = LVFINDINFOW
   MACRO LV_FINDINFO  = LVFINDINFOW
#ENDIF

' // LVM_FINDITEMA and LVM_FINDITEMW are predefined in the compiler, but
' // LVM_FINDITEMA is called LVM_FINDITEM, so we need to redefine it.
%LVM_FINDITEMA          = %LVM_FIRST + 13
%LVM_FINDITEMW          = %LVM_FIRST + 83
#IF %DEF(%UNICODE)
%LVM_FINDITEM = %LVM_FINDITEMW
#ELSE
%LVM_FINDITEM = %LVM_FINDITEMA
#ENDIF

%LVIR_BOUNDS            = 0
%LVIR_ICON              = 1
%LVIR_LABEL             = 2
%LVIR_SELECTBOUNDS      = 3

'%LVM_GETITEMRECT        = %LVM_FIRST + 14
'%LVM_SETITEMPOSITION    = %LVM_FIRST + 15
'%LVM_GETITEMPOSITION    = %LVM_FIRST + 16
' // LVM_GETSTRINGWIDTHA and LVM_GETSTRINGWIDTHW are predefined in the compiler, but
' // LVM_GETSTRINGWIDTHA is called LVM_GETSTRINGWIDTH, so we need to redefine it.
%LVM_GETSTRINGWIDTHA    = %LVM_FIRST + 17
%LVM_GETSTRINGWIDTHW    = %LVM_FIRST + 87
#IF %DEF(%UNICODE)
%LVM_GETSTRINGWIDTH = %LVM_GETSTRINGWIDTHW
#ELSE
%LVM_GETSTRINGWIDTH = %LVM_GETSTRINGWIDTHA
#ENDIF

%LVHT_NOWHERE           = &H00000001???
%LVHT_ONITEMICON        = &H00000002???
%LVHT_ONITEMLABEL       = &H00000004???
%LVHT_ONITEMSTATEICON   = &H00000008???
%LVHT_ONITEM            = %LVHT_ONITEMICON OR %LVHT_ONITEMLABEL OR %LVHT_ONITEMSTATEICON

%LVHT_ABOVE             = &H00000008???
%LVHT_BELOW             = &H00000010???
%LVHT_TORIGHT           = &H00000020???
%LVHT_TOLEFT            = &H00000040???

%LVHT_EX_GROUP_HEADER       = &H10000000???
%LVHT_EX_GROUP_FOOTER       = &H20000000???
%LVHT_EX_GROUP_COLLAPSE     = &H40000000???
%LVHT_EX_GROUP_BACKGROUND   = &H80000000???
%LVHT_EX_GROUP_STATEICON    = &H01000000???
%LVHT_EX_GROUP_SUBSETLINK   = &H02000000???
%LVHT_EX_GROUP              = %LVHT_EX_GROUP_BACKGROUND OR %LVHT_EX_GROUP_COLLAPSE OR %LVHT_EX_GROUP_FOOTER OR %LVHT_EX_GROUP_HEADER OR %LVHT_EX_GROUP_STATEICON OR %LVHT_EX_GROUP_SUBSETLINK
%LVHT_EX_ONCONTENTS         = &H04000000???  ' // On item AND not on the background
%LVHT_EX_FOOTER             = &H08000000???

' // Size = 24 bytes 20 bytes in XP)
TYPE LVHITTESTINFO DWORD
   pt       AS POINT      ' POINT pt
   flags    AS DWORD      ' UINT flags
   iItem    AS LONG
#IF (%WIN32_IE >= &H0300)
   iSubItem AS LONG       ' int iSubItem  // this is was NOT in win95.  valid only for LVM_SUBITEMHITTEST
#ENDIF
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   iGroup   AS LONG       ' int // readonly. index of group. only valid for owner data.
                          '     // supports single item in multiple groups.
#ENDIF
END TYPE

MACRO LV_HITTESTINFO = LVHITTESTINFO

%LVHITTESTINFO_V1_SIZE = 20
%LVHITTESTINFO_V6_SIZE = 24

'%LVM_HITTEST            = %LVM_FIRST + 18
'%LVM_ENSUREVISIBLE      = %LVM_FIRST + 19
'%LVM_SCROLL             = %LVM_FIRST + 20
'%LVM_REDRAWITEMS        = %LVM_FIRST + 21

%LVA_DEFAULT            = &H0000
%LVA_ALIGNLEFT          = &H0001
%LVA_ALIGNTOP           = &H0002
%LVA_SNAPTOGRID         = &H0005

'%LVM_ARRANGE            = %LVM_FIRST + 22
' // LVM_EDITLABELA and LVM_EDITLABELW are predefined in the compiler, but
' // LVM_EDITLABELA is called LVM_EDITLABEL, so we need to redefine it.
%LVM_EDITLABELA         = %LVM_FIRST + 23
%LVM_EDITLABELW         = %LVM_FIRST + 118
#IF %DEF(%UNICODE)
%LVM_EDITLABEL = %LVM_EDITLABELW
#ELSE
%LVM_EDITLABEL = %LVM_EDITLABELA
#ENDIF

'%LVM_GETEDITCONTROL     = %LVM_FIRST + 24

' // Size = 44 bytes (32 bytes in XP)
TYPE LVCOLUMNA DWORD
   mask       AS DWORD        ' UINT mask
   fmt        AS LONG         ' int fmt
   cx         AS LONG         ' int cx
   pszText    AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax AS LONG         ' int cchTextMax
   iSubItem   AS LONG         ' int iSubItem
#IF (%WIN32_IE >= &H0300)
   iImage     AS LONG         ' int iImage
   iOrder     AS LONG         ' int iOrder
#ENDIF
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   cxMin      AS LONG         ' int // min snap point
   cxDefault  AS LONG         ' int // default snap point
   cxIdeal    AS LONG         ' int // read only. ideal may not eqaul current width if auto sized (LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
#ENDIF
END TYPE

' // Size = 44 bytes (32 bytes in XP)
TYPE LVCOLUMNW DWORD
   mask       AS DWORD          ' UINT mask
   fmt        AS LONG           ' int fmt
   cx         AS LONG           ' int cx
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax AS LONG           ' int cchTextMax
   iSubItem   AS LONG           ' int iSubItem
#IF (%WIN32_IE >= &H0300)
   iImage     AS LONG           ' int iImage
   iOrder     AS LONG           ' int iOrder
#ENDIF
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   cxMin      AS LONG           ' int // min snap point
   cxDefault  AS LONG           ' int // default snap point
   cxIdeal    AS LONG           ' int // read only. ideal may not eqaul current width if auto sized (LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
#ENDIF
END TYPE

MACRO LV_COLUMNA = LVCOLUMNA
MACRO LV_COLUMNW = LVCOLUMNW

#IF %DEF(%UNICODE)
   MACRO LVCOLUMN  = LVCOLUMNW
   MACRO LV_COLUMN = LVCOLUMNW
#ELSE
   MACRO LVCOLUMN  = LVCOLUMNA
   MACRO LV_COLUMN = LVCOLUMNA
#ENDIF

%LVCOLUMN_V1_SIZE = 32
%LVCOLUMN_V6_SIZE = 44

%LVCF_FMT               = &H0001???
%LVCF_WIDTH             = &H0002???
%LVCF_TEXT              = &H0004???
%LVCF_SUBITEM           = &H0008???
'#if (_WIN32_IE >= 0x0300)
%LVCF_IMAGE             = &H0010???
%LVCF_ORDER             = &H0020???
'#endif
'#if _WIN32_WINNT >= 0x0600
%LVCF_MINWIDTH          = &H0040???
%LVCF_DEFAULTWIDTH      = &H0080???
%LVCF_IDEALWIDTH        = &H0100???
'#endif

%LVCFMT_LEFT            = &H0000???
%LVCFMT_RIGHT           = &H0001???
%LVCFMT_CENTER          = &H0002???
%LVCFMT_JUSTIFYMASK     = &H0003???

'#if (_WIN32_IE >= 0x0300)
%LVCFMT_IMAGE           = &H0800???
%LVCFMT_BITMAP_ON_RIGHT = &H1000???
%LVCFMT_COL_HAS_IMAGES  = &H8000???
'#endif

'#if _WIN32_WINNT >= 0x0600
%LVCFMT_FIXED_WIDTH     = &H00100???  ' // Can't resize the column; same as HDF_FIXEDWIDTH
%LVCFMT_NO_DPI_SCALE    = &H40000???  ' // If not set, CCM_DPISCALE will govern scaling up fixed width
%LVCFMT_FIXED_RATIO     = &H80000???  ' // Width will augment with the row height

'// The following flags
%LVCFMT_LINE_BREAK         = &H100000???  ' // Move to the top of the next list of columns
%LVCFMT_FILL               = &H200000???  ' // Fill the remainder of the tile area. Might have a title.
%LVCFMT_WRAP               = &H400000???  ' // This sub-item can be wrapped.
%LVCFMT_NO_TITLE           = &H800000???  ' // This sub-item doesn't have an title.
%LVCFMT_TILE_PLACEMENTMASK = %LVCFMT_LINE_BREAK OR %LVCFMT_FILL

%LVCFMT_SPLITBUTTON        = &H1000000???  ' // Column is a split button; same as HDF_SPLITBUTTON
'#endif

' // LVM_GETCOLUMNA and LVM_GETCOLUMNW are predefined in the compiler, but
' // LVM_GETCOLUMNA is called LVM_GETCOLUMN, so we need to redefine it.
%LVM_GETCOLUMNA         = %LVM_FIRST + 25
%LVM_GETCOLUMNW         = %LVM_FIRST + 95
#IF %DEF(%UNICODE)
%LVM_GETCOLUMN = %LVM_GETCOLUMNW
#ELSE
%LVM_GETCOLUMN = %LVM_GETCOLUMNA
#ENDIF

' // LVM_SETCOLUMNA and LVM_SETCOLUMNW are predefined in the compiler, but
' // LVM_SETCOLUMNA is called LVM_SETCOLUMN, so we need to redefine it.
%LVM_SETCOLUMNA         = %LVM_FIRST + 26
%LVM_SETCOLUMNW         = %LVM_FIRST + 96
#IF %DEF(%UNICODE)
%LVM_SETCOLUMN = %LVM_SETCOLUMNW
#ELSE
%LVM_SETCOLUMN = %LVM_SETCOLUMNA
#ENDIF

' // LVM_INSERTCOLUMNA and LVM_INSERTCOLUMNW are predefined in the compiler, but
' // LVM_INSERTCOLUMNA is called LVM_INSERTCOLUMN, so we need to redefine it.
%LVM_INSERTCOLUMNA      = %LVM_FIRST + 27
%LVM_INSERTCOLUMNW      = %LVM_FIRST + 97
#IF %DEF(%UNICODE)
%LVM_INSERTCOLUMN = %LVM_INSERTCOLUMNW
#ELSE
%LVM_INSERTCOLUMN = %LVM_INSERTCOLUMNA
#ENDIF

'%LVM_DELETECOLUMN       = %LVM_FIRST + 28
'%LVM_GETCOLUMNWIDTH     = %LVM_FIRST + 29

%LVSCW_AUTOSIZE             = -1
%LVSCW_AUTOSIZE_USEHEADER   = -2
'%LVM_SETCOLUMNWIDTH         = %LVM_FIRST + 30

'#if (_WIN32_IE >= 0x0300)
'%LVM_GETHEADER          = %LVM_FIRST + 31
'#endif

'%LVM_CREATEDRAGIMAGE    = %LVM_FIRST + 33
'%LVM_GETVIEWRECT        = %LVM_FIRST + 34
'%LVM_GETTEXTCOLOR       = %LVM_FIRST + 35
'%LVM_SETTEXTCOLOR       = %LVM_FIRST + 36
'%LVM_GETTEXTBKCOLOR     = %LVM_FIRST + 37
'%LVM_SETTEXTBKCOLOR     = %LVM_FIRST + 38
'%LVM_GETTOPINDEX        = %LVM_FIRST + 39
'%LVM_GETCOUNTPERPAGE    = %LVM_FIRST + 40
'%LVM_GETORIGIN          = %LVM_FIRST + 41
'%LVM_UPDATE             = %LVM_FIRST + 42
'%LVM_SETITEMSTATE       = %LVM_FIRST + 43

'#if (_WIN32_IE >= 0x0300)
'#endif

'%LVM_GETITEMSTATE       = %LVM_FIRST + 44

'#if (_WIN32_IE >= 0x0300)
'#endif

' // LVM_GETITEMTEXTA and LVM_GETITEMTEXTW are predefined in the compiler, but
' // LVM_GETITEMTEXTA is called LVM_GETITEMTEXT, so we need to redefine it.
%LVM_GETITEMTEXTA       = %LVM_FIRST + 45
%LVM_GETITEMTEXTW       = %LVM_FIRST + 115
#IF %DEF(%UNICODE)
%LVM_GETITEMTEXT = %LVM_GETITEMTEXTW
#ELSE
%LVM_GETITEMTEXT = %LVM_GETITEMTEXTA
#ENDIF

' // LVM_SETITEMTEXTA and LVM_SETITEMTEXTW are predefined in the compiler, but
' // LVM_SETITEMTEXTA is called LVM_SETITEMTEXT, so we need to redefine it.
%LVM_SETITEMTEXTA       = %LVM_FIRST + 46
%LVM_SETITEMTEXTW       = %LVM_FIRST + 116
#IF %DEF(%UNICODE)
%LVM_SETITEMTEXT = %LVM_SETITEMTEXTW
#ELSE
%LVM_SETITEMTEXT = %LVM_SETITEMTEXTA
#ENDIF

'#if (_WIN32_IE >= 0x0300)
'// these flags only apply to LVS_OWNERDATA listviews in report or list mode
%LVSICF_NOINVALIDATEALL  = &H00000001???
%LVSICF_NOSCROLL         = &H00000002???
'#endif

'%LVM_SETITEMCOUNT       = %LVM_FIRST + 47

'#if (_WIN32_IE >= 0x0300)
'#endif

'typedef int (CALLBACK *PFNLVCOMPARE)(LPARAM, LPARAM, LPARAM);
'FUNCTION LVCOMPARE (BYVAL LONG, BYVAL LONG, BYVAL LONG) AS LONG

'%LVM_SORTITEMS          = %LVM_FIRST + 48
'%LVM_SETITEMPOSITION32  = %LVM_FIRST + 49
'%LVM_GETSELECTEDCOUNT   = %LVM_FIRST + 50
'%LVM_GETITEMSPACING     = %LVM_FIRST + 51
' // LVM_GETISEARCHSTRINGA and LVM_GETISEARCHSTRINGW are predefined in the compiler, but
' // LVM_GETISEARCHSTRINGA is called LVM_GETISEARCHSTRING, so we need to redefine it.
%LVM_GETISEARCHSTRINGA  = %LVM_FIRST + 52
%LVM_GETISEARCHSTRINGW  = %LVM_FIRST + 117
#IF %DEF(%UNICODE)
%LVM_GETISEARCHSTRING = %LVM_GETISEARCHSTRINGW
#ELSE
%LVM_GETISEARCHSTRING = %LVM_GETISEARCHSTRINGA
#ENDIF

'#if (_WIN32_IE >= 0x0300)
'%LVM_SETICONSPACING     = %LVM_FIRST + 53
'// -1 for cx and cy means we'll use the default (system settings)
'// 0 for cx or cy means use the current setting (allows you to change just one param)

'%LVM_SETEXTENDEDLISTVIEWSTYLE = %LVM_FIRST + 54  ' optional wParam == mask

'#if (_WIN32_IE >= 0x0400)
'#endif

'%LVM_GETEXTENDEDLISTVIEWSTYLE = %LVM_FIRST + 55

'%LVS_EX_GRIDLINES        = &H00000001???
'%LVS_EX_SUBITEMIMAGES    = &H00000002???
'%LVS_EX_CHECKBOXES       = &H00000004???
'%LVS_EX_TRACKSELECT      = &H00000008???
'%LVS_EX_HEADERDRAGDROP   = &H00000010???
'%LVS_EX_FULLROWSELECT    = &H00000020??? ' // applies to report mode only
'%LVS_EX_ONECLICKACTIVATE = &H00000040???
'%LVS_EX_TWOCLICKACTIVATE = &H00000080???
'#if (_WIN32_IE >= 0x0400)
'%LVS_EX_FLATSB           = &H00000100???
'%LVS_EX_REGIONAL         = &H00000200???
'%LVS_EX_INFOTIP          = &H00000400??? ' // listview does InfoTips for you
'%LVS_EX_UNDERLINEHOT     = &H00000800???
'%LVS_EX_UNDERLINECOLD    = &H00001000???
'%LVS_EX_MULTIWORKAREAS   = &H00002000???
'#endif
'#if (_WIN32_IE >= 0x0500)
'%LVS_EX_LABELTIP         = &H00004000??? ' // listview unfolds partly hidden labels if it does not have infotip text
'%LVS_EX_BORDERSELECT     = &H00008000??? ' // border selection style instead of highlight
'#endif  // End (_WIN32_IE >= 0x0500)
'#if (_WIN32_WINNT >= 0x501)
'%LVS_EX_DOUBLEBUFFER     = &H00010000???
'%LVS_EX_HIDELABELS       = &H00020000???
'%LVS_EX_SINGLEROW        = &H00040000???
'%LVS_EX_SNAPTOGRID       = &H00080000??? ' // Icons automatically snap to grid.
'%LVS_EX_SIMPLESELECT     = &H00100000??? ' // Also changes overlay rendering to top right for icon mode.
'#endif
'#if _WIN32_WINNT >= 0x0600
%LVS_EX_JUSTIFYCOLUMNS   = &H00200000???  ' // Icons are lined up in columns that use up the whole view area.
%LVS_EX_TRANSPARENTBKGND = &H00400000???  ' // Background is painted by the parent via WM_PRINTCLIENT
%LVS_EX_TRANSPARENTSHADOWTEXT = &H00800000???  ' // Enable shadow text on transparent backgrounds only (useful with bitmaps)
%LVS_EX_AUTOAUTOARRANGE  = &H01000000???  ' // Icons automatically arrange if no icon positions have been set
%LVS_EX_HEADERINALLVIEWS = &H02000000???  ' // Display column header in all view modes
%LVS_EX_AUTOCHECKSELECT  = &H08000000???
%LVS_EX_AUTOSIZECOLUMNS  = &H10000000???
%LVS_EX_COLUMNSNAPPOINTS = &H40000000???
%LVS_EX_COLUMNOVERFLOW   = &H80000000???
'#endif

'%LVM_GETSUBITEMRECT      = %LVM_FIRST + 56
'%LVM_SUBITEMHITTEST      = %LVM_FIRST + 57
'%LVM_SETCOLUMNORDERARRAY = %LVM_FIRST + 58
'%LVM_GETCOLUMNORDERARRAY = %LVM_FIRST + 59
'%LVM_SETHOTITEM          = %LVM_FIRST + 60
'%LVM_GETHOTITEM          = %LVM_FIRST + 61
'%LVM_SETHOTCURSOR        = %LVM_FIRST + 62
'%LVM_GETHOTCURSOR        = %LVM_FIRST + 63
'%LVM_APPROXIMATEVIEWRECT = %LVM_FIRST + 64

'#endif      // _WIN32_IE >= 0x0300

'#if (_WIN32_IE >= 0x0400)

%LV_MAX_WORKAREAS         = 16
%LVM_SETWORKAREAS         = %LVM_FIRST + 65
%LVM_GETWORKAREAS         = %LVM_FIRST + 70
%LVM_GETNUMBEROFWORKAREAS = %LVM_FIRST + 73
'%LVM_GETSELECTIONMARK     = %LVM_FIRST + 66
'%LVM_SETSELECTIONMARK     = %LVM_FIRST + 67
'%LVM_SETHOVERTIME         = %LVM_FIRST + 71
'%LVM_GETHOVERTIME         = %LVM_FIRST + 72
'%LVM_SETTOOLTIPS          = %LVM_FIRST + 74
'%LVM_GETTOOLTIPS          = %LVM_FIRST + 78
'%LVM_SORTITEMSEX          = %LVM_FIRST + 81

' // Size = 24 bytes
TYPE LVBKIMAGEA DWORD
   ulFlags        AS DWORD        ' ULONG ulFlags              // LVBKIF_*
   hbm            AS DWORD        ' HBITMAP hbm
   pszImage       AS ASCIIZ PTR   ' LPSTR pszImage
   cchImageMax    AS DWORD        ' UINT cchImageMax
   xOffsetPercent AS LONG         ' int xOffsetPercent
   yOffsetPercent AS LONG         ' int yOffsetPercent
END TYPE

' // Size = 24 bytes
TYPE LVBKIMAGEW DWORD
   ulFlags        AS DWORD          ' ULONG ulFlags              // LVBKIF_*
   hbm            AS DWORD          ' HBITMAP hbm
   pszImage       AS WSTRINGZ PTR   ' LPWSTR pszImage
   cchImageMax    AS DWORD          ' UINT cchImageMax
   xOffsetPercent AS LONG           ' int xOffsetPercent
   yOffsetPercent AS LONG           ' int yOffsetPercent
END TYPE

#IF %DEF(%UNICODE)
   MACRO LVBKIMAGE = LVBKIMAGEW
#ELSE
   MACRO LVBKIMAGE = LVBKIMAGEA
#ENDIF

%LVBKIF_SOURCE_NONE      = &H00000000???
%LVBKIF_SOURCE_HBITMAP   = &H00000001???
%LVBKIF_SOURCE_URL       = &H00000002???
%LVBKIF_SOURCE_MASK      = &H00000003???
%LVBKIF_STYLE_NORMAL     = &H00000000???
%LVBKIF_STYLE_TILE       = &H00000010???
%LVBKIF_STYLE_MASK       = &H00000010???
'#if (_WIN32_WINNT >= 0x501)
%LVBKIF_FLAG_TILEOFFSET  = &H00000100???
%LVBKIF_TYPE_WATERMARK   = &H10000000???
%LVBKIF_FLAG_ALPHABLEND  = &H20000000???
'#endif

' // LVM_SETBKIMAGEA and LVM_SETBKIMAGEW are predefined in the compiler, but
' // LVM_SETBKIMAGEA is called LVM_SETBKIMAGE, so we need to redefine it.
%LVM_SETBKIMAGEA         = %LVM_FIRST + 68
%LVM_SETBKIMAGEW         = %LVM_FIRST + 138
#IF %DEF(%UNICODE)
MACRO LVM_SETBKIMAGE = LVM_SETBKIMAGEW
#ELSE
MACRO LVM_SETBKIMAGE = LVM_SETBKIMAGEA
#ENDIF
' // LVM_GETBKIMAGEA and LVM_GETBKIMAGEW are predefined in the compiler, but
' // LVM_GETBKIMAGEA is called LVM_GETBKIMAGE, so we need to redefine it.
%LVM_GETBKIMAGEA         = %LVM_FIRST + 69
%LVM_GETBKIMAGEW         = %LVM_FIRST + 139
#IF %DEF(%UNICODE)
MACRO LVM_GETBKIMAGE = LVM_GETBKIMAGEW
#ELSE
MACRO LVM_GETBKIMAGE = LVM_GETBKIMAGEA
#ENDIF

'#if (_WIN32_WINNT >= 0x501)
'%LVM_SETSELECTEDCOLUMN   = %LVM_FIRST + 140

' This message is supported only through Microsoft Windows XP.
' It is not defined in the Windows Vista SDK.
'%LVM_SETTILEWIDTH        = %LVM_FIRST + 141

%LV_VIEW_ICON      = &H0000???
%LV_VIEW_DETAILS   = &H0001???
%LV_VIEW_SMALLICON = &H0002???
%LV_VIEW_LIST      = &H0003???
%LV_VIEW_TILE      = &H0004???
%LV_VIEW_MAX       = &H0004???

'%LVM_SETVIEW         = %LVM_FIRST + 142
'%LVM_GETVIEW         = %LVM_FIRST + 143

%LVGF_NONE               = &H00000000???
%LVGF_HEADER             = &H00000001???
%LVGF_FOOTER             = &H00000002???
%LVGF_STATE              = &H00000004???
%LVGF_ALIGN              = &H00000008???
%LVGF_GROUPID            = &H00000010???
'#if _WIN32_WINNT >= 0x0600
%LVGF_SUBTITLE           = &H00000100???  ' // pszSubtitle is valid
%LVGF_TASK               = &H00000200???  ' // pszTask is valid
%LVGF_DESCRIPTIONTOP     = &H00000400???  ' // pszDescriptionTop is valid
%LVGF_DESCRIPTIONBOTTOM  = &H00000800???  ' // pszDescriptionBottom is valid
%LVGF_TITLEIMAGE         = &H00001000???  ' // iTitleImage is valid
%LVGF_EXTENDEDIMAGE      = &H00002000???  ' // iExtendedImage is valid
%LVGF_ITEMS              = &H00004000???  ' // iFirstItem and cItems are valid
%LVGF_SUBSET             = &H00008000???  ' // pszSubsetTitle is valid
%LVGF_SUBSETITEMS        = &H00010000???  ' // readonly, cItems holds count of items in visible subset, iFirstItem is valid
'#endif

%LVGS_NORMAL             = &H00000000???
%LVGS_COLLAPSED          = &H00000001???
%LVGS_HIDDEN             = &H00000002???
%LVGS_NOHEADER           = &H00000004???
%LVGS_COLLAPSIBLE        = &H00000008???
%LVGS_FOCUSED            = &H00000010???
%LVGS_SELECTED           = &H00000020???
%LVGS_SUBSETED           = &H00000040???
%LVGS_SUBSETLINKFOCUSED  = &H00000080???

%LVGA_HEADER_LEFT        = &H00000001???
%LVGA_HEADER_CENTER      = &H00000002???
%LVGA_HEADER_RIGHT       = &H00000004???  ' Don't forget to validate exclusivity
%LVGA_FOOTER_LEFT        = &H00000008???
%LVGA_FOOTER_CENTER      = &H00000010???
%LVGA_FOOTER_RIGHT       = &H00000020???  ' Don't forget to validate exclusivity

UNION LVGROUP_STATE_UNION DWORD
   state                AS DWORD          ' UINT
   ' // For compatibility with the PB includes
   nState               AS DWORD          ' UINT
END UNION

' // Size = 96 bytes (40 bytes in XP)
TYPE LVGROUP DWORD
   cbSize               AS DWORD          ' UINT
   mask                 AS DWORD          ' UINT
   pszHeader            AS WSTRINGZ PTR   ' LPWSTR
   cchHeader            AS LONG           ' int
   pszFooter            AS WSTRINGZ PTR   ' LPWSTR
   cchFooter            AS LONG           ' int
   iGroupId             AS LONG           ' int
   stateMask            AS DWORD          ' UINT
   LVGROUP_STATE_UNION
   uAlign               AS DWORD          ' UINT
#IF %WIN32_WINNT >= &H0600
   pszSubtitle          AS WSTRINGZ PTR   ' LPWSTR
   cchSubtitle          AS DWORD          ' UINT
   pszTask              AS WSTRINGZ PTR   ' LPWSTR
   cchTask              AS DWORD          ' UINT
   pszDescriptionTop    AS WSTRINGZ PTR   ' LPWSTR
   cchDescriptionTop    AS DWORD          ' UINT
   pszDescriptionBottom AS WSTRINGZ PTR   ' LPWSTR
   cchDescriptionBottom AS DWORD          ' UINT
   iTitleImage          AS LONG           ' int
   iExtendedImage       AS LONG           ' int
   iFirstItem           AS LONG           ' int // Read only
   cItems               AS DWORD          ' UINT // Read only
   pszSubsetTitle       AS WSTRINGZ PTR   ' LPWSTR // NULL if group is not subset
   cchSubsetTitle       AS DWORD          ' UINT
#ENDIF
END TYPE

%LVGROUP_V1_SIZE = 40
%LVGROUP_V6_SIZE = 96

'%LVM_INSERTGROUP          = %LVM_FIRST + 145
'%LVM_SETGROUPINFO         = %LVM_FIRST + 147
'%LVM_GETGROUPINFO         = %LVM_FIRST + 149
'%LVM_REMOVEGROUP          = %LVM_FIRST + 150
'%LVM_MOVEGROUP            = %LVM_FIRST + 151
%LVM_GETGROUPCOUNT        = %LVM_FIRST + 152
%LVM_GETGROUPINFOBYINDEX  = %LVM_FIRST + 153
'%LVM_MOVEITEMTOGROUP      = %LVM_FIRST + 154

%LVGGR_GROUP       = 0  ' // Entire expanded group
%LVGGR_HEADER      = 1  ' // Header only (collapsed group)
%LVGGR_LABEL       = 2  ' // Label only
%LVGGR_SUBSETLINK  = 3  ' // subset link only

%LVM_GETGROUPRECT         = %LVM_FIRST + 98

%LVGMF_NONE        = &H00000000???
%LVGMF_BORDERSIZE  = &H00000001???
%LVGMF_BORDERCOLOR = &H00000002???
%LVGMF_TEXTCOLOR   = &H00000004???

' // Size = 48 bytes
TYPE LVGROUPMETRICS DWORD
   cbSize   AS DWORD   ' UINT cbSize
   mask     AS DWORD   ' UINT mask
   nLeft    AS DWORD   ' UINT Left
   nTop     AS DWORD   ' UINT Top
   nRight   AS DWORD   ' UINT Right
   nBottom  AS DWORD   ' UINT Bottom
   crLeft   AS DWORD   ' COLORREF crLeft
   crTop    AS DWORD   ' COLORREF crTop
   crRight  AS DWORD   ' COLORREF crRight
   crBottom AS DWORD   ' COLORREF crBottom
   crHeader AS DWORD   ' COLORREF crHeader
   crFooter AS DWORD   ' COLORREF crFooter
END TYPE

'%LVM_SETGROUPMETRICS         = %LVM_FIRST + 155
'%LVM_GETGROUPMETRICS         = %LVM_FIRST + 156
'%LVM_ENABLEGROUPVIEW         = %LVM_FIRST + 157

'typedef int (CALLBACK *PFNLVGROUPCOMPARE)(int, int, void *);
'FUNCTION LVGROUPCOMPARE (BYVAL LONG, BYVAL LONG, BYVAL DWORD) AS LONG

'%LVM_SORTGROUPS         = %LVM_FIRST + 158

' // Size = 104 bytes
TYPE LVINSERTGROUPSORTED DWORD
   pfnGroupCompare AS DWORD     ' PFNLVGROUPCOMPARE pfnGroupCompare
   pvData          AS DWORD     ' void *pvData
   lvGrp           AS LVGROUP   ' LVGROUP lvGroup
END TYPE

'%LVM_INSERTGROUPSORTED           = %LVM_FIRST + 159
'%LVM_REMOVEALLGROUPS             = %LVM_FIRST + 160
'%LVM_HASGROUP                    = %LVM_FIRST + 161

%LVM_GETGROUPSTATE               = %LVM_FIRST + 92
%LVM_GETFOCUSEDGROUP             = %LVM_FIRST + 93

%LVTVIF_AUTOSIZE    = &H00000000???
%LVTVIF_FIXEDWIDTH  = &H00000001???
%LVTVIF_FIXEDHEIGHT = &H00000002???
%LVTVIF_FIXEDSIZE   = &H00000003???
'#if _WIN32_WINNT >= 0x0600
%LVTVIF_EXTENDED    = &H00000004???
'#endif

%LVTVIM_TILESIZE    = &H00000001???
%LVTVIM_COLUMNS     = &H00000002???
%LVTVIM_LABELMARGIN = &H00000004???

' // Size = 40 bytes
TYPE LVTILEVIEWINFO DWORD
   cbSize        AS DWORD   ' UINT cbSize
   dwMask        AS DWORD   ' DWORD dwMask     //LVTVIM_*
   dwFlags       AS DWORD   ' DWORD dwFlags    //LVTVIF_*
   sizeTile      AS SIZEL   ' SIZE sizeTile
   cLines        AS LONG    ' int cLines
   rcLabelMargin AS RECT    ' RECT rcLabelMargin
END TYPE

' // Size = 20 bytes (16 bytes in XP)
TYPE LVTILEINFO DWORD
   cbSize    AS DWORD       ' UINT cbSize
   iItem     AS LONG        ' int iItem
   cColumns  AS DWORD       ' UINT cColumns
   puColumns AS DWORD PTR   ' PUINT puColumns
'#IF %WIN32_WINNT >= &H0600
#IF %WINVER >= &H0600
   piColFmt  AS LONG PTR    ' int*
#ENDIF
END TYPE

%LVTILEINFO_V1_SIZE = 16
%LVTILEINFO_V6_SIZE = 20

'%LVM_SETTILEVIEWINFO                 = %LVM_FIRST + 162
'%LVM_GETTILEVIEWINFO                 = %LVM_FIRST + 163
'%LVM_SETTILEINFO                     = %LVM_FIRST + 164
'%LVM_GETTILEINFO                     = %LVM_FIRST + 165

' // Size = 16 bytes
TYPE LVINSERTMARK DWORD
   cbSize     AS DWORD   ' UINT cbSize
   dwFlags    AS DWORD   ' DWORD dwFlags
   iItem      AS LONG    ' int iItem
   dwReserved AS DWORD   ' DWORD dwReserved
END TYPE

%LVIM_AFTER = &H00000001 ' %TRUE = insert After iItem, otherwise before

'%LVM_SETINSERTMARK                  = %LVM_FIRST + 166
'%LVM_GETINSERTMARK                  = %LVM_FIRST + 167
'%LVM_INSERTMARKHITTEST              = %LVM_FIRST + 168
'%LVM_GETINSERTMARKRECT              = %LVM_FIRST + 169
'%LVM_SETINSERTMARKCOLOR             = %LVM_FIRST + 170
'%LVM_GETINSERTMARKCOLOR             = %LVM_FIRST + 171

' // Size = 20 bytes
TYPE LVSETINFOTIP DWORD
   cbSize   AS DWORD          ' UINT cbSize
   dwFlags  AS DWORD          ' DWORD dwFlags
   pszText  AS WSTRINGZ PTR   ' LPWSTR pszText
   iItem    AS LONG           ' int iItem
   iSubItem AS LONG           ' int iSubItem
END TYPE

'%LVM_SETINFOTIP          = %LVM_FIRST + 173
'%LVM_GETSELECTEDCOLUMN   = %LVM_FIRST + 174
'%LVM_ISGROUPVIEWENABLED  = %LVM_FIRST + 175
'%LVM_GETOUTLINECOLOR     = %LVM_FIRST + 176
'%LVM_SETOUTLINECOLOR     = %LVM_FIRST + 177
'%LVM_CANCELEDITLABEL     = %LVM_FIRST + 179

'// These next to methods make it easy to identify an item that can be repositioned
'// within listview. For example: Many developers use the lParam to store an identifier that is
'// unique. Unfortunatly, in order to find this item, they have to iterate through all of the items
'// in the listview. Listview will maintain a unique identifier.  The upper bound is the size of a DWORD.
'%LVM_MAPINDEXTOID       = %LVM_FIRST + 180
'%LVM_MAPIDTOINDEX       = %LVM_FIRST + 181
%LVM_ISITEMVISIBLE      = %LVM_FIRST + 182

'#if _WIN32_WINNT >= 0x0600

%LVM_GETEMPTYTEXT       = %LVM_FIRST + 204
%LVM_GETFOOTERRECT      = %LVM_FIRST + 205

'// footer flags
%LVFF_ITEMCOUNT         = &H00000001???

' // Size = 16 bytes
TYPE LVFOOTERINFO DWORD
   mask       AS DWORD          ' UINT // LVFF_*
   pszText    AS WSTRINGZ PTR   ' LPWSTR
   cchTextMax AS LONG           ' int
   cItems     AS DWORD          ' UINT
END TYPE

%LVM_GETFOOTERINFO     = %LVM_FIRST + 206
%LVM_GETFOOTERITEMRECT = %LVM_FIRST + 207

'// footer item flags
%LVFIF_TEXT               = &H00000001???
%LVFIF_STATE              = &H00000002???

'// footer item state
%LVFIS_FOCUSED            = &H0001???

UNION LVFOOTERITEM_STATE_UNION
   state      AS DWORD          ' UINT // LVFIS_*
   ' // For compatibility with the PB includes
   nState     AS DWORD          ' UINT // LVFIS_*
END UNION

' // Size = 24 bytes
TYPE LVFOOTERITEM DWORD
   mask       AS DWORD          ' UINT // LVFIF_*
   iItem      AS LONG           ' int
   pszText    AS WSTRINGZ PTR   ' LPWSTR
   cchTextMax AS LONG           ' int
   LVFOOTERITEM_STATE_UNION
   stateMask  AS DWORD          ' UINT // LVFIS_*
END TYPE

%LVM_GETFOOTERITEM = %LVM_FIRST + 208

'// supports a single item in multiple groups.
' // Size = 8 bytes
TYPE LVITEMINDEX DWORD
   iItem AS LONG    ' int // listview item index
   iGroup AS LONG   ' int // group index (must be -1 if group view is not enabled)
END TYPE

%LVM_GETITEMINDEXRECT   = %LVM_FIRST + 209
%LVM_SETITEMINDEXSTATE  = %LVM_FIRST + 210
%LVM_GETNEXTITEMINDEX   = %LVM_FIRST + 211

'#endif

'#endif

'#endif      // _WIN32_IE >= 0x0400

' // Size = 44 bytes
TYPE NMLISTVIEW DWORD
   hdr       AS NMHDR   ' NMHDR   hdr
   iItem     AS LONG    ' int     iItem
   iSubItem  AS LONG    ' int     iSubItem
   uNewState AS DWORD   ' UINT    uNewState
   uOldState AS DWORD   ' UINT    uOldState
   uChanged  AS DWORD   ' UINT    uChanged
   ptAction  AS POINT   ' POINT   ptAction
   lParam    AS LONG    ' LPARAM  lParam
END TYPE

MACRO NM_LISTVIEW = NMLISTVIEW

'#if (_WIN32_IE >= 0x400)
'// NMITEMACTIVATE is used instead of NMLISTVIEW in IE >= 0x400
'// therefore all the fields are the same except for extra uKeyFlags
'// they are used to store key flags at the time of the single click with
'// delayed activation - because by the time the timer goes off a user may
'// not hold the keys (shift, ctrl) any more

' // Size = 48 bytes
TYPE NMITEMACTIVATE DWORD
   hdr       AS NMHDR   ' NMHDR   hdr
   iItem     AS LONG    ' int     iItem
   iSubItem  AS LONG    ' int     iSubItem
   uNewState AS DWORD   ' UINT    uNewState
   uOldState AS DWORD   ' UINT    uOldState
   uChanged  AS DWORD   ' UINT    uChanged
   ptAction  AS POINT   ' POINT   ptAction
   lParam    AS LONG    ' LPARAM  lParam
   uKeyFlags AS DWORD   ' UINT    uKeyFlags
END TYPE

'// key flags stored in uKeyFlags
%LVKF_ALT       = &H0001???
%LVKF_CONTROL   = &H0002???
%LVKF_SHIFT     = &H0004???
'#endif //(_WIN32_IE >= 0x0400)


'#if (_WIN32_IE >= 0x0300)

' // Size = 104 bytes
TYPE NMLVCUSTOMDRAW DWORD
   nmcd        AS NMCUSTOMDRAW   ' NMCUSTOMDRAW nmcd
   clrText     AS DWORD          ' COLORREF clrText
   clrTextBk   AS DWORD          ' COLORREF clrTextBk
#IF (%WIN32_IE >= &H0400)
   iSubItem    AS LONG           ' int iSubItem
#ENDIF
'#IF (%WIN32_WINNT >= &H0501)
#IF %WINVER >= &H0501
   dwItemType  AS DWORD          ' DWORD dwItemType
   ' // Item custom draw
   clrFace     AS DWORD          ' COLORREF clrFace
   iIconEffect AS LONG           ' int iIconEffect
   iIconPhase  AS LONG           ' int iIconPhase
   iPartId     AS LONG           ' int iPartId
   iStateId    AS LONG           ' int iStateId
   ' // Group Custom Draw
   rcText      AS RECT           ' RECT rcText
   uAlign      AS DWORD          ' UINT uAlign  // Alignment. Use LVGA_HEADER_CENTER, LVGA_HEADER_RIGHT, LVGA_HEADER_LEFT
#ENDIF
END TYPE

'// dwItemType
%LVCDI_ITEM          = &H00000000???
%LVCDI_GROUP         = &H00000001???
%LVCDI_ITEMSLIST     = &H00000002???

'// ListView custom draw return values
%LVCDRF_NOSELECT     = &H00010000???
%LVCDRF_NOGROUPFRAME = &H00020000???

' // Size = 20 bytes
TYPE NMLVCACHEHINT DWORD
   hdr   AS NMHDR   ' NMHDR   hdr
   iFrom AS LONG    ' int     iFrom
   iTo   AS LONG    ' int     iTo
END TYPE

MACRO NM_CACHEHINT = NMLVCACHEHINT

' // Size = 40 bytes
TYPE NMLVFINDITEMA DWORD
   hdr    AS NMHDR        ' NMHDR       hdr
   iStart AS LONG         ' int         iStart
   lvfi   AS LVFINDINFOA  ' LVFINDINFOA lvfi
END TYPE

' // Size = 40 bytes
TYPE NMLVFINDITEMW DWORD
   hdr    AS NMHDR        ' NMHDR       hdr
   iStart AS LONG         ' int         iStart
   lvfi   AS LVFINDINFOW  ' LVFINDINFOW lvfi
END TYPE

MACRO NM_FINDITEMA = NMLVFINDITEMA
MACRO NM_FINDITEMW = NMLVFINDITEMW

#IF %DEF(%UNICODE)
   MACRO NMLVFINDITEM = NMLVFINDITEMW
   MACRO NM_FINDITEM  = NMLVFINDITEMW
#ELSE
   MACRO NMLVFINDITEM = NMLVFINDITEMA
   MACRO NM_FINDITEM  = NMLVFINDITEMA
#ENDIF

' // Size = 28 bytes
TYPE NMLVODSTATECHANGE DWORD
   hdr       AS NMHDR   ' NMHDR hdr
   iFrom     AS LONG    ' int iFrom
   iTo       AS LONG    ' int iTo
   uNewState AS DWORD   ' UINT uNewState
   uOldState AS DWORD   ' UINT uOldState
END TYPE

MACRO NM_ODSTATECHANGE = NMLVODSTATECHANGE

'%LVN_ITEMCHANGING    = %LVN_FIRST
'%LVN_ITEMCHANGED     = %LVN_FIRST - 1
'%LVN_INSERTITEM      = %LVN_FIRST - 2
'%LVN_DELETEITEM      = %LVN_FIRST - 3
'%LVN_DELETEALLITEMS  = %LVN_FIRST - 4
' // LVN_BEGINLABELEDITA and LVN_BEGINLABELEDITW are predefined in the compiler, but
' // LVN_BEGINLABELEDITA is called LVN_BEGINLABELEDIT, so we need to redefine it.
%LVN_BEGINLABELEDITA = %LVN_FIRST - 5
%LVN_BEGINLABELEDITW = %LVN_FIRST - 75
#IF %DEF(%UNICODE)
%LVN_BEGINLABELEDIT = %LVN_BEGINLABELEDITW
#ELSE
%LVN_BEGINLABELEDIT = %LVN_BEGINLABELEDITA
#ENDIF
' // LVN_ENDLABELEDITA and LVN_ENDLABELEDITW are predefined in the compiler, but
' // LVN_ENDLABELEDITA is called LVN_ENDLABELEDIT, so we need to redefine it.
%LVN_ENDLABELEDITA   = %LVN_FIRST - 6
%LVN_ENDLABELEDITW   = %LVN_FIRST - 76
#IF %DEF(%UNICODE)
%LVN_ENDLABELEDIT = %LVN_ENDLABELEDITW
#ELSE
%LVN_ENDLABELEDIT = %LVN_ENDLABELEDITA
#ENDIF
'%LVN_COLUMNCLICK     = %LVN_FIRST - 8
'%LVN_BEGINDRAG       = %LVN_FIRST - 9
'%LVN_BEGINRDRAG      = %LVN_FIRST - 11

'#if (_WIN32_IE >= 0x0300)
%LVN_ODCACHEHINT     = %LVN_FIRST - 13
%LVN_ODFINDITEMA     = %LVN_FIRST - 52
%LVN_ODFINDITEMW     = %LVN_FIRST - 79
#IF %DEF(%UNICODE)
%LVN_ODFINDITEM = %LVN_ODFINDITEMW
#ELSE
%LVN_ODFINDITEM = %LVN_ODFINDITEMA
#ENDIF

%LVN_ITEMACTIVATE    = %LVN_FIRST - 14
%LVN_ODSTATECHANGED  = %LVN_FIRST - 15

'#if (_WIN32_IE >= 0x0400)
%LVN_HOTTRACK        = %LVN_FIRST - 21
'#endif

' // LVN_GETDISPINFOA and LVN_GETDISPINFOW are predefined in the compiler, but
' // LVN_GETDISPINFOA is called LVN_GETDISPINFO, so we need to redefine it.
%LVN_GETDISPINFOA    = %LVN_FIRST - 50
%LVN_GETDISPINFOW    = %LVN_FIRST - 77
#IF %DEF(%UNICODE)
%LVN_GETDISPINFO = %LVN_GETDISPINFOW
#ELSE
%LVN_GETDISPINFO = %LVN_GETDISPINFOA
#ENDIF
' // LVN_SETDISPINFOA and LVN_SETDISPINFOW are predefined in the compiler, but
' // LVN_SETDISPINFOA is called LVN_SETDISPINFO, so we need to redefine it.
%LVN_SETDISPINFOA    = %LVN_FIRST - 51
%LVN_SETDISPINFOW    = %LVN_FIRST - 78
#IF %DEF(%UNICODE)
%LVN_SETDISPINFO = %LVN_SETDISPINFOW
#ELSE
%LVN_SETDISPINFO = %LVN_SETDISPINFOA
#ENDIF

%LVIF_DI_SETITEM     = &H1000???

' // Size = 72 bytes
TYPE NMLVDISPINFOA DWORD
   hdr  AS NMHDR     ' NMHDR  hdr
   item AS LVITEMA   ' LVITEM item
END TYPE

' // Size = 72 bytes
TYPE NMLVDISPINFOW DWORD
   hdr  AS NMHDR     ' NMHDR  hdr
   item AS LVITEMW   ' LVITEMW item
END TYPE

MACRO LVDISPINFOA  = NMLVDISPINFOA
MACRO LV_DISPINFOA = NMLVDISPINFOA
MACRO LVDISPINFOW  = NMLVDISPINFOW
MACRO LV_DISPINFOW = NMLVDISPINFOW

#IF %DEF(%UNICODE)
   MACRO NMLVDISPINFO = NMLVDISPINFOW
   MACRO LV_DISPINFO  = NMLVDISPINFOW
   MACRO LVDISPINFO   = NMLVDISPINFOW
#ELSE
   MACRO NMLVDISPINFO = NMLVDISPINFOA
   MACRO LV_DISPINFO  = NMLVDISPINFOA
   MACRO LVDISPINFO   = NMLVDISPINFOA
#ENDIF

'%LVN_KEYDOWN          = %LVN_FIRST - 55

'#ifdef _WIN32
'#include <pshpack1.h>
'#endif

' // Size = 18 bytes
TYPE LV_KEYDOWN WORD
   hdr   AS NMHDR   ' NMHDR hdr
   wVKey AS WORD    ' WORD wVKey
   flags AS DWORD   ' UINT flags
END TYPE

MACRO LVKEYDOWN = LV_KEYDOWN
MACRO NMLVKEYDOWN = LV_KEYDOWN

'#ifdef _WIN32
'#include <poppack.h>
'#endif

'#if (_WIN32_IE >= 0x0300)
%LVN_MARQUEEBEGIN     = %LVN_FIRST - 56
'#endif

'#if _WIN32_WINNT >= 0x0600
' // Size = 4300 bytes
TYPE NMLVLINK DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   link     AS LITEM   ' LITEM link
   iItem    AS LONG    ' int iItem
   iSubItem AS LONG    ' int iSubItem
END TYPE
'#endif

'#if (_WIN32_IE >= 0x0400)

' // Size = 36 bytes
TYPE NMLVGETINFOTIPA DWORD
   hdr        AS NMHDR        ' NMHDR hdr
   dwFlags    AS DWORD        ' DWORD dwFlags
   pszText    AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax AS LONG         ' int cchTextMax
   iItem      AS LONG         ' int iItem
   iSubItem   AS LONG         ' int iSubItem
   lParam     AS LONG         ' LPARAM lParam
END TYPE

' // Size = 36 bytes
TYPE NMLVGETINFOTIPW DWORD
   hdr        AS NMHDR          ' NMHDR hdr
   dwFlags    AS DWORD          ' DWORD dwFlags
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax AS LONG           ' int cchTextMax
   iItem      AS LONG           ' int iItem
   iSubItem   AS LONG           ' int iSubItem
   lParam     AS LONG           ' LPARAM lParam
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMLVGETINFOTIP = NMLVGETINFOTIPW
#ELSE
   MACRO NMLVGETINFOTIP = NMLVGETINFOTIPA
#ENDIF

'// NMLVGETINFOTIPA.dwFlag values

%LVGIT_UNFOLDED  = &H0001???

%LVN_GETINFOTIPA       = %LVN_FIRST - 57
%LVN_GETINFOTIPW       = %LVN_FIRST - 58
#IF %DEF(%UNICODE)
%LVN_GETINFOTIP = %LVN_GETINFOTIPW
#ELSE
%LVN_GETINFOTIP = %LVN_GETINFOTIPA
#ENDIF

'#endif      // _WIN32_IE >= 0x0400

'#if (_WIN32_IE >= 0x0500)

'//
'//  LVN_INCREMENTALSEARCH gives the app the opportunity to customize
'//  incremental search.  For example, if the items are numeric,
'//  the app can do numerical search instead of string search.
'//
'//  ListView notifies the app with NMLVFINDITEM.
'//  The app sets pnmfi->lvfi.lParam to the result of the incremental search,
'//  or to LVNSCH_DEFAULT if ListView should do the default search,
'//  or to LVNSCH_ERROR to fail the search and just beep,
'//  or to LVNSCH_IGNORE to stop all ListView processing.
'//
'//  The return value is not used.

%LVNSCH_DEFAULT = -1
%LVNSCH_ERROR   = -2
%LVNSCH_IGNORE  = -3

%LVN_INCREMENTALSEARCHA  = %LVN_FIRST - 62
%LVN_INCREMENTALSEARCHW  = %LVN_FIRST - 63
#IF %DEF(%UNICODE)
%LVN_INCREMENTALSEARCH = %LVN_INCREMENTALSEARCHW
#ELSE
%LVN_INCREMENTALSEARCH = %LVN_INCREMENTALSEARCHA
#ENDIF

'#endif      // _WIN32_IE >= 0x0500

'#if _WIN32_WINNT >= 0x0600
%LVN_COLUMNDROPDOWN      = %LVN_FIRST - 64
%LVN_COLUMNOVERFLOWCLICK = %LVN_FIRST - 66
'#endif // _WIN32_WINNT >= 0x0600

'#if (_WIN32_WINNT >= 0x501)

' // Size = 20 bytes
TYPE NMLVSCROLL DWORD
   hdr AS NMHDR   ' NMHDR   hdr
   dx  AS LONG    ' int     dx
   dy  AS LONG    ' int     dy
END TYPE

%LVN_BEGINSCROLL       = %LVN_FIRST - 80
%LVN_ENDSCROLL         = %LVN_FIRST - 81
'#endif

'#if _WIN32_WINNT >= 0x0600
%LVN_LINKCLICK         = %LVN_FIRST - 84
%EMF_CENTERED          = &H00000001???  ' // render markup centered in the listview area

' // Size = 4184 bytes
TYPE NMLVEMPTYMARKUP DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   ' // out params from client back to listview
   dwFlags  AS DWORD   ' DWORD // EMF_*
   szMarkup AS WSTRINGZ * %L_MAX_URL_LENGTH   ' WCHAR szMarkup[L_MAX_URL_LENGTH];   // markup displayed
END TYPE

%LVN_GETEMPTYMARKUP    = %LVN_FIRST - 87

'#endif

#ENDIF ' // NOLISTVIEW

'//====== TREEVIEW CONTROL =====================================================

#IF NOT %DEF(%NOTREEVIEW)

$WC_TREEVIEWA      = "SysTreeView32"
$$WC_TREEVIEWW     = "SysTreeView32"$$
#IF %DEF(%UNICODE)
   MACRO WC_TREEVIEW = $$WC_TREEVIEWW
#ELSE
   MACRO WC_TREEVIEW = $WC_TREEVIEWA
#ENDIF

'%TVS_HASBUTTONS      = &H0001???
'%TVS_HASLINES        = &H0002???
'%TVS_LINESATROOT     = &H0004???
'%TVS_EDITLABELS      = &H0008???
'%TVS_DISABLEDRAGDROP = &H0010???
'%TVS_SHOWSELALWAYS   = &H0020???
'#if (_WIN32_IE >= 0x0300)
'%TVS_RTLREADING      = &H0040???
'%TVS_NOTOOLTIPS      = &H0080???
'%TVS_CHECKBOXES      = &H0100???
'%TVS_TRACKSELECT     = &H0200???
'#if (_WIN32_IE >= 0x0400)
'%TVS_SINGLEEXPAND    = &H0400???
'%TVS_INFOTIP         = &H0800???
'%TVS_FULLROWSELECT   = &H1000???
'%TVS_NOSCROLL        = &H2000???
'%TVS_NONEVENHEIGHT   = &H4000???
'#endif
'#if (_WIN32_IE >= 0x500)
'%TVS_NOHSCROLL       = &H8000???  ' %TVS_NOSCROLL overrides this
'#endif
'#endif

'#if (_WIN32_WINNT >= 0x0600)
%TVS_EX_MULTISELECT          = &H0002???
%TVS_EX_DOUBLEBUFFER         = &H0004???
%TVS_EX_NOINDENTSTATE        = &H0008???
%TVS_EX_RICHTOOLTIP          = &H0010???
%TVS_EX_AUTOHSCROLL          = &H0020???
%TVS_EX_FADEINOUTEXPANDOS    = &H0040???
%TVS_EX_PARTIALCHECKBOXES    = &H0080???
%TVS_EX_EXCLUSIONCHECKBOXES  = &H0100???
%TVS_EX_DIMMEDCHECKBOXES     = &H0200???
%TVS_EX_DRAWIMAGEASYNC       = &H0400???
'#endif

'typedef struct _TREEITEM *HTREEITEM;

%TVIF_TEXT           = &H0001???
%TVIF_IMAGE          = &H0002???
%TVIF_PARAM          = &H0004???
%TVIF_STATE          = &H0008???
%TVIF_HANDLE         = &H0010???
%TVIF_SELECTEDIMAGE  = &H0020???
%TVIF_CHILDREN       = &H0040???
'#if (_WIN32_IE >= 0x0400)
%TVIF_INTEGRAL       = &H0080???
'#endif
'#if (_WIN32_IE >= 0x0600)
%TVIF_STATEEX        = &H0100???
%TVIF_EXPANDEDIMAGE  = &H0200???
'#endif
%TVIS_SELECTED       = &H0002???
%TVIS_CUT            = &H0004???
%TVIS_DROPHILITED    = &H0008???
%TVIS_BOLD           = &H0010???
%TVIS_EXPANDED       = &H0020???
%TVIS_EXPANDEDONCE   = &H0040???
'#if (_WIN32_IE >= 0x0300)
%TVIS_EXPANDPARTIAL  = &H0080???
'#endif

%TVIS_OVERLAYMASK    = &H0F00???
%TVIS_STATEIMAGEMASK = &HF000???
%TVIS_USERMASK       = &HF000???

'#if (_WIN32_IE >= 0x0600)
%TVIS_EX_FLAT        = &H0001???
'#if (_WIN32_WINNT >= 0x0600)
%TVIS_EX_DISABLED    = &H0002???
'#endif
%TVIS_EX_ALL         = &H0002???

'// Structure for TreeView's NM_TVSTATEIMAGECHANGING notification
' // Size = 24 bytes
TYPE NMTVSTATEIMAGECHANGING DWORD
   hdr                 AS NMHDR   ' NMHDR hdr
   hti                 AS DWORD   ' HTREEITEM hti
   iOldStateImageIndex AS LONG    ' int iOldStateImageIndex
   iNewStateImageIndex AS LONG    ' int iNewStateImageIndex
END TYPE
'#endif

%I_CHILDRENCALLBACK  = -1&

' // Size = 40 bytes
TYPE TVITEMA DWORD
   mask           AS DWORD        ' UINT      mask
   hItem          AS DWORD        ' HTREEITEM hItem
   state          AS DWORD        ' UINT      state
   stateMask      AS DWORD        ' UINT      stateMask
   pszText        AS ASCIIZ PTR   ' LPSTR     pszText
   cchTextMax     AS LONG         ' int       cchTextMax
   iImage         AS LONG         ' int       iImage
   iSelectedImage AS LONG         ' int       iSelectedImage
   cChildren      AS LONG         ' int       cChildren
   lParam         AS LONG         ' LPARAM    lParam
END TYPE

' // Size = 40 bytes
TYPE TVITEMW DWORD
   mask           AS DWORD          ' UINT      mask
   hItem          AS DWORD          ' HTREEITEM hItem
   state          AS DWORD          ' UINT      state
   stateMask      AS DWORD          ' UINT      stateMask
   pszText        AS WSTRINGZ PTR   ' LPWSTR    pszText
   cchTextMax     AS LONG           ' int       cchTextMax
   iImage         AS LONG           ' int       iImage
   iSelectedImage AS LONG           ' int       iSelectedImage
   cChildren      AS LONG           ' int       cChildren
   lParam         AS LONG           ' LPARAM    lParam
END TYPE

MACRO TV_ITEMA = TVITEMA
MACRO TV_ITEMW = TVITEMW

#IF %DEF(%UNICODE)
   MACRO TVITEM  = TVITEMW
   MACRO TV_ITEM = TVITEMW
#ELSE
   MACRO TVITEM  = TVITEMA
   MACRO TV_ITEM = TVITEMA
#ENDIF

'#if (_WIN32_IE >= 0x0400)
'// only used for Get and Set messages.  no notifies
' // Size = 60 bytes
TYPE TVITEMEXA DWORD
   mask           AS DWORD        ' UINT      mask
   hItem          AS DWORD        ' HTREEITEM hItem
   state          AS DWORD        ' UINT      state
   stateMask      AS DWORD        ' UINT      stateMask
   pszText        AS ASCIIZ PTR   ' LPSTR     pszText
   cchTextMax     AS LONG         ' int       cchTextMax
   iImage         AS LONG         ' int       iImage
   iSelectedImage AS LONG         ' int       iSelectedImage
   cChildren      AS LONG         ' int       cChildren
   lParam         AS LONG         ' LPARAM    lParam
   iIntegral      AS LONG         ' int       iIntegral
'#IF (%WIN32_IE >= &H0600)
#IF %WINVER >= &H0600
   uStateEx       AS DWORD        ' UINT
   hwnd           AS DWORD        ' HWND
   iExpandedImage AS LONG         ' int
#ENDIF
'#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
#IF %WINVER >= &H0601
   iReserved      AS LONG         ' int
#ENDIF
END TYPE

' // Size = 60 bytes
TYPE TVITEMEXW DWORD
   mask           AS DWORD          ' UINT      mask
   hItem          AS DWORD          ' HTREEITEM hItem
   state          AS DWORD          ' UINT      state
   stateMask      AS DWORD          ' UINT      stateMask
   pszText        AS WSTRINGZ PTR   ' LPWSTR    pszText
   cchTextMax     AS LONG           ' int       cchTextMax
   iImage         AS LONG           ' int       iImage
   iSelectedImage AS LONG           ' int       iSelectedImage
   cChildren      AS LONG           ' int       cChildren
   lParam         AS LONG           ' LPARAM    lParam
   iIntegral      AS LONG           ' int       iIntegral
'#IF (%WIN32_IE >= &H0600)
#IF %WINVER >= &H0600
   uStateEx       AS DWORD          ' UINT
   hwnd           AS DWORD          ' HWND
   iExpandedImage AS LONG           ' int
#ENDIF
'#IF (%NTDDI_VERSION >= %NTDDI_WIN7)
#IF %WINVER >= &H0601
   iReserved      AS LONG           ' int
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
   MACRO TVITEMEX = TVITEMEXW
#ELSE
   MACRO TVITEMEX = TVITEMEXA
#ENDIF

'#endif

'%TVI_ROOT               = &HFFFF0000???
'%TVI_FIRST              = &HFFFF0001???
'%TVI_LAST               = &HFFFF0002???
'%TVI_SORT               = &HFFFF0003???

'typedef struct tagTVINSERTSTRUCTA {
'    HTREEITEM hParent;
'    HTREEITEM hInsertAfter;
'#if (_WIN32_IE >= 0x0400)
'    union
'    {
'        TVITEMEXA itemex;
'        TV_ITEMA  item;
'    } DUMMYUNIONNAME;
'#else
'    TV_ITEMA item;
'#endif
'} TVINSERTSTRUCTA, *LPTVINSERTSTRUCTA;

' // Size = 60 bytes
UNION TVINSERTSTRUCTA_UNION DWORD
   itemex AS TVITEMEX   ' TVITEMEX itemex
   item   AS TVITEM     ' TVITEM   item
END UNION

' // Size = 68 bytes
TYPE TVINSERTSTRUCTA DWORD
   hParent      AS DWORD           ' HTREEITEM hParent
   hInsertAfter AS DWORD           ' HTREEITEM hInsertAfter
   TVINSERTSTRUCTA_UNION
END TYPE

' // Size = 60 bytes
UNION TVINSERTSTRUCTW_UNION DWORD
   itemex AS TVITEMEXW   ' TVITEMEXW itemex
   item   AS TVITEMW     ' TVITEMW   item
END UNION

TYPE TVINSERTSTRUCTW DWORD
   hParent      AS DWORD            ' HTREEITEM hParent
   hInsertAfter AS DWORD            ' HTREEITEM hInsertAfter
   TVINSERTSTRUCTW_UNION
END TYPE

MACRO TV_INSERTSTRUCTA = TVINSERTSTRUCTA
MACRO TV_INSERTSTRUCTW = TVINSERTSTRUCTW

#IF %DEF(%UNICODE)
   MACRO TVINSERTSTRUCT  = TVINSERTSTRUCTW
   MACRO TV_INSERTSTRUCT = TVINSERTSTRUCTW
#ELSE
   MACRO TVINSERTSTRUCT  = TVINSERTSTRUCTA
   MACRO TV_INSERTSTRUCT = TVINSERTSTRUCTA
#ENDIF

%TVM_INSERTITEMA        = %TV_FIRST
%TVM_INSERTITEMW        = %TV_FIRST + 50
#IF %DEF(%UNICODE)
%TVM_INSERTITEM = %TVM_INSERTITEMW
#ELSE
%TVM_INSERTITEM = %TVM_INSERTITEMA
#ENDIF
%TVM_DELETEITEM         = %TV_FIRST + 1
%TVM_EXPAND             = %TV_FIRST + 2

'%TVE_COLLAPSE           = &H0001???
'%TVE_EXPAND             = &H0002???
'%TVE_TOGGLE             = &H0003???
'#if (_WIN32_IE >= 0x0300)
'%TVE_EXPANDPARTIAL      = &H4000???
'#endif
'%TVE_COLLAPSERESET      = &H8000???

%TVM_GETITEMRECT        = %TV_FIRST + 4
%TVM_GETCOUNT           = %TV_FIRST + 5
%TVM_GETINDENT          = %TV_FIRST + 6
%TVM_SETINDENT          = %TV_FIRST + 7
%TVM_GETIMAGELIST       = %TV_FIRST + 8

%TVSIL_NORMAL           = 0
%TVSIL_STATE            = 2

%TVM_SETIMAGELIST       = %TV_FIRST + 9
%TVM_GETNEXTITEM        = %TV_FIRST + 10

%TVGN_ROOT              = &H0000???
%TVGN_NEXT              = &H0001???
%TVGN_PREVIOUS          = &H0002???
%TVGN_PARENT            = &H0003???
%TVGN_CHILD             = &H0004???
%TVGN_FIRSTVISIBLE      = &H0005???
%TVGN_NEXTVISIBLE       = &H0006???
%TVGN_PREVIOUSVISIBLE   = &H0007???
%TVGN_DROPHILITE        = &H0008???
%TVGN_CARET             = &H0009???
'#if (_WIN32_IE >= 0x0400)
%TVGN_LASTVISIBLE       = &H000A???
'#endif      // _WIN32_IE >= 0x0400
'#if (_WIN32_IE >= 0x0600)
%TVGN_NEXTSELECTED      = &H000B???
'#endif

'#if (_WIN32_WINNT >= 0x501)
%TVSI_NOSINGLEEXPAND    = &H08000??? ' Should not conflict with %TVGN flags.
'#endif

%TVM_SELECTITEM         = %TV_FIRST + 11
%TVM_GETITEMA           = %TV_FIRST + 12
%TVM_GETITEMW           = %TV_FIRST + 62
#IF %DEF(%UNICODE)
%TVM_GETITEM = %TVM_GETITEMW
#ELSE
%TVM_GETITEM = %TVM_GETITEMA
#ENDIF
%TVM_SETITEMA           = %TV_FIRST + 13
%TVM_SETITEMW           = %TV_FIRST + 63
#IF %DEF(%UNICODE)
%TVM_SETITEM = %TVM_SETITEMW
#ELSE
%TVM_SETITEM = %TVM_SETITEMA
#ENDIF
%TVM_EDITLABELA         = %TV_FIRST + 14
%TVM_EDITLABELW         = %TV_FIRST + 65
#IF %DEF(%UNICODE)
%TVM_EDITLABEL = %TVM_EDITLABELW
#ELSE
%TVM_EDITLABEL = %TVM_EDITLABELA
#ENDIF
%TVM_GETEDITCONTROL     = %TV_FIRST + 15
%TVM_GETVISIBLECOUNT    = %TV_FIRST + 16
%TVM_HITTEST            = %TV_FIRST + 17

' // Size = 16 bytes
TYPE TVHITTESTINFO DWORD
   pt    AS POINT   ' POINT       pt
   flags AS DWORD   ' UINT        flags
   hItem AS DWORD   ' HTREEITEM   hItem
END TYPE

MACRO TV_HITTESTINFO = TVHITTESTINFO

%TVHT_NOWHERE           = &H0001???
%TVHT_ONITEMICON        = &H0002???
%TVHT_ONITEMLABEL       = &H0004???
%TVHT_ONITEMINDENT      = &H0008???
%TVHT_ONITEMBUTTON      = &H0010???
%TVHT_ONITEMRIGHT       = &H0020???
%TVHT_ONITEMSTATEICON   = &H0040???
%TVHT_ONITEM            = %TVHT_ONITEMICON OR %TVHT_ONITEMLABEL OR %TVHT_ONITEMSTATEICON

%TVHT_ABOVE             = &H0100???
%TVHT_BELOW             = &H0200???
%TVHT_TORIGHT           = &H0400???
%TVHT_TOLEFT            = &H0800???


%TVM_CREATEDRAGIMAGE    = %TV_FIRST + 18
%TVM_SORTCHILDREN       = %TV_FIRST + 19
%TVM_ENSUREVISIBLE      = %TV_FIRST + 20

' // Size = 12 bytes
TYPE TVSORTCB DWORD
   hParent     AS DWORD   ' HTREEITEM       hParent
   lpfnCompare AS DWORD   ' PFNTVCOMPARE    lpfnCompare
   lParam      AS LONG    ' LPARAM          lParam
END TYPE

MACRO TV_SORTCB = TVSORTCB

%TVM_SORTCHILDRENCB     = %TV_FIRST + 21
%TVM_ENDEDITLABELNOW    = %TV_FIRST + 22
%TVM_GETISEARCHSTRINGA  = %TV_FIRST + 23
%TVM_GETISEARCHSTRINGW  = %TV_FIRST + 64
#IF %DEF(%UNICODE)
%TVM_GETISEARCHSTRING = %TVM_GETISEARCHSTRINGW
#ELSE
%TVM_GETISEARCHSTRING = %TVM_GETISEARCHSTRINGA
#ENDIF

'#if (_WIN32_IE >= 0x0300)
%TVM_SETTOOLTIPS        = %TV_FIRST + 24
%TVM_GETTOOLTIPS        = %TV_FIRST + 25
'#endif

'#if (_WIN32_IE >= 0x0400)
%TVM_SETINSERTMARK      = %TV_FIRST + 26
%TVM_SETUNICODEFORMAT   = %CCM_SETUNICODEFORMAT
%TVM_GETUNICODEFORMAT   = %CCM_GETUNICODEFORMAT

'#endif

'#if (_WIN32_IE >= 0x0400)
%TVM_SETITEMHEIGHT      = %TV_FIRST + 27
%TVM_GETITEMHEIGHT      = %TV_FIRST + 28
%TVM_SETBKCOLOR         = %TV_FIRST + 29
%TVM_SETTEXTCOLOR       = %TV_FIRST + 30
%TVM_GETBKCOLOR         = %TV_FIRST + 31
%TVM_GETTEXTCOLOR       = %TV_FIRST + 32
%TVM_SETSCROLLTIME      = %TV_FIRST + 33
%TVM_GETSCROLLTIME      = %TV_FIRST + 34
%TVM_SETINSERTMARKCOLOR = %TV_FIRST + 37
%TVM_GETINSERTMARKCOLOR = %TV_FIRST + 38

'#endif  /* (_WIN32_IE >= 0x0400) */

'#if (_WIN32_IE >= 0x0500)

#IF NOT %DEF(%ITSIM)
%ITSIM = 1
FUNCTION IndexToStateImageMask (BYVAL i AS LONG) AS LONG
   SHIFT LEFT i, 12
   FUNCTION = i
END FUNCTION
#ENDIF

%TVM_GETITEMSTATE = %TV_FIRST + 39
%TVM_SETLINECOLOR = %TV_FIRST + 40
%TVM_GETLINECOLOR = %TV_FIRST + 41

'#endif

'#if (_WIN32_WINNT >= 0x0501)
%TVM_MAPACCIDTOHTREEITEM   = %TV_FIRST + 42
%TVM_MAPHTREEITEMTOACCID   = %TV_FIRST + 43
%TVM_SETEXTENDEDSTYLE      = %TV_FIRST + 44
%TVM_GETEXTENDEDSTYLE      = %TV_FIRST + 45
%TVM_SETAUTOSCROLLINFO     = %TV_FIRST + 59

'#endif

'#if (_WIN32_WINNT >= 0x0600)

%TVM_GETSELECTEDCOUNT      = %TV_FIRST + 70
%TVM_SHOWINFOTIP           = %TV_FIRST + 71

' enum TVITEMPART
%TVGIPR_BUTTON  = &H0001???

' // Size = 12 bytes
TYPE TVGETITEMPARTRECTINFO DWORD
   hti    AS DWORD      ' HTREEITEM
   prc    AS RECT PTR   ' RECT*
   partID AS LONG       ' TVITEMPART enum
END TYPE

%TVM_GETITEMPARTRECT        = %TV_FIRST + 72

'#endif

'typedef int (CALLBACK *PFNTVCOMPARE)(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);
'FUNCTION TVCOMPARE (BYVAL lParam1 AS LONG, BYVAL lParam2 AS LONG, BYVAL lParamSort AS LONG) AS LONG

' // Size = 104 bytes
TYPE NMTREEVIEWA DWORD
   hdr     AS NMHDR      ' NMHDR
   action  AS DWORD      ' UINT
   itemOld AS TVITEMA    ' TVITEMA
   itemNew AS TVITEMA    ' TVITEMA
   ptDrag  AS POINT      ' POINT
END TYPE

' // Size = 104 bytes
TYPE NMTREEVIEWW DWORD
   hdr     AS NMHDR      ' NMHDR
   action  AS DWORD      ' UINT
   itemOld AS TVITEMW    ' TVITEMW
   itemNew AS TVITEMW    ' TVITEMW
   ptDrag  AS POINT      ' POINT
END TYPE

MACRO NM_TREEVIEWA = NMTREEVIEWA
MACRO NM_TREEVIEWW = NMTREEVIEWW

#IF %DEF(%UNICODE)
   MACRO NM_TREEVIEW = NMTREEVIEWW
   MACRO NMTREEVIEW  = NMTREEVIEWW
#ELSE
   MACRO NM_TREEVIEW = NMTREEVIEWA
   MACRO NMTREEVIEW  = NMTREEVIEWA
#ENDIF

' // TVN_SELCHANGINGA and TVN_SELCHANGINGW are predefined in the compiler, but
' // TVN_SELCHANGINGA is called TVN_SELCHANGING, so we need to redefine it.
%TVN_SELCHANGINGA       = %TVN_FIRST - 1
%TVN_SELCHANGINGW       = %TVN_FIRST - 50
#IF %DEF(%UNICODE)
%TVN_SELCHANGING = %TVN_SELCHANGINGW
#ELSE
%TVN_SELCHANGING = %TVN_SELCHANGINGA
#ENDIF
' // TVN_SELCHANGEDA and TVN_SELCHANGEDW are predefined in the compiler, but
' // TVN_SELCHANGEDA is called TVN_SELCHANGED, so we need to redefine it.
%TVN_SELCHANGEDA        = %TVN_FIRST - 2
%TVN_SELCHANGEDW        = %TVN_FIRST - 51
#IF %DEF(%UNICODE)
%TVN_SELCHANGED = %TVN_SELCHANGEDW
#ELSE
%TVN_SELCHANGED = %TVN_SELCHANGEDA
#ENDIF

%TVC_UNKNOWN            = &H0000???
%TVC_BYMOUSE            = &H0001???
%TVC_BYKEYBOARD         = &H0002???

' // TVN_GETDISPINFOA and TVN_GETDISPINFOW are predefined in the compiler, but
' // TVN_GETDISPINFOA is called TVN_GETDISPINFO, so we need to redefine it.
%TVN_GETDISPINFOA       = %TVN_FIRST - 3
%TVN_GETDISPINFOW       = %TVN_FIRST - 52
#IF %DEF(%UNICODE)
%TVN_GETDISPINFO = %TVN_GETDISPINFOW
#ELSE
%TVN_GETDISPINFO = %TVN_GETDISPINFOA
#ENDIF
' // TVN_SETDISPINFOA and TVN_SETDISPINFOW are predefined in the compiler, but
' // TVN_SETDISPINFOA is called TVN_SETDISPINFO, so we need to redefine it.
%TVN_SETDISPINFOA       = %TVN_FIRST - 4
%TVN_SETDISPINFOW       = %TVN_FIRST - 53
#IF %DEF(%UNICODE)
%TVN_SETDISPINFO = %TVN_SETDISPINFOW
#ELSE
%TVN_SETDISPINFO = %TVN_SETDISPINFOA
#ENDIF

%TVIF_DI_SETITEM        = &H1000???

' // Size = 52 bytes
TYPE TVDISPINFOA DWORD
   hdr  AS NMHDR      ' NMHDR hdr
   item AS TVITEMA    ' TVITEMA item
END TYPE

' // Size = 52 bytes
TYPE TVDISPINFOW DWORD
   hdr  AS NMHDR      ' NMHDR hdr
   item AS TVITEMW    ' TVITEMW item
END TYPE

MACRO NMTVDISPINFOA  = TVDISPINFOA
MACRO NMTVDISPINFOW  = TVDISPINFOW
MACRO TV_DISPINFOA   = TVDISPINFOA
MACRO TV_DISPINFOW   = TVDISPINFOW

#IF %DEF(%UNICODE)
   MACRO TVDISPINFO  = TVDISPINFOW
   MACRO TV_DISPINFO = TVDISPINFOW
#ELSE
   MACRO TVDISPINFO  = TVDISPINFOA
   MACRO TV_DISPINFO = TVDISPINFOA
#ENDIF

'#if (_WIN32_IE >= 0x0600)

' // Size = 72 bytes
TYPE TVDISPINFOEXA
   hdr  AS NMHDR       ' NMHDR hdr
   item AS TVITEMEXA   ' TVITEMEXA item
END TYPE

' // Size = 72 bytes
TYPE TVDISPINFOEXW
   hdr  AS NMHDR       ' NMHDR hdr
   item AS TVITEMEXW   ' TVITEMEXW item
END TYPE

MACRO NMTVDISPINFOEXA = TVDISPINFOEXA
MACRO NMTVDISPINFOEXW = TVDISPINFOEXW

#IF %DEF(%UNICODE)
   MACRO TVDISPINFOEX   = TVDISPINFOEXW
   MACRO NMTVDISPINFOEX = TVDISPINFOEXW
#ELSE
   MACRO TVDISPINFOEX   = TVDISPINFOEXA
   MACRO NMTVDISPINFOEX = TVDISPINFOEXA
#ENDIF

'#endif

' // TVN_ITEMEXPANDINGA and TVN_ITEMEXPANDINGW are predefined in the compiler, but
' // TVN_ITEMEXPANDINGA is called TVN_ITEMEXPANDING, so we need to redefine it.
%TVN_ITEMEXPANDINGA     = %TVN_FIRST - 5
%TVN_ITEMEXPANDINGW     = %TVN_FIRST - 54
#IF %DEF(%UNICODE)
%TVN_ITEMEXPANDING = %TVN_ITEMEXPANDINGW
#ELSE
%TVN_ITEMEXPANDING = %TVN_ITEMEXPANDINGA
#ENDIF
' // TVN_ITEMEXPANDEDA and TVN_ITEMEXPANDEDW are predefined in the compiler, but
' // TVN_ITEMEXPANDEDA is called TVN_ITEMEXPANDED, so we need to redefine it.
%TVN_ITEMEXPANDEDA      = %TVN_FIRST - 6
%TVN_ITEMEXPANDEDW      = %TVN_FIRST - 55
#IF %DEF(%UNICODE)
%TVN_ITEMEXPANDED = %TVN_ITEMEXPANDEDW
#ELSE
%TVN_ITEMEXPANDED = %TVN_ITEMEXPANDEDA
#ENDIF
' // TVN_BEGINDRAGA and TVN_BEGINDRAGW are predefined in the compiler, but
' // TVN_BEGINDRAGA is called TVN_BEGINDRAG, so we need to redefine it.
%TVN_BEGINDRAGA         = %TVN_FIRST - 7
%TVN_BEGINDRAGW         = %TVN_FIRST - 56
#IF %DEF(%UNICODE)
%TVN_BEGINDRAG = %TVN_BEGINDRAGW
#ELSE
%TVN_BEGINDRAG = %TVN_BEGINDRAGA
#ENDIF
' // TVN_BEGINRDRAGA and TVN_BEGINRDRAGW are predefined in the compiler, but
' // TVN_BEGINRDRAGA is called TVN_BEGINRDRAG, so we need to redefine it.
%TVN_BEGINRDRAGA        = %TVN_FIRST - 8
%TVN_BEGINRDRAGW        = %TVN_FIRST - 57
#IF %DEF(%UNICODE)
%TVN_BEGINRDRAG = %TVN_BEGINRDRAGW
#ELSE
%TVN_BEGINRDRAG = %TVN_BEGINRDRAGA
#ENDIF
' // TVN_DELETEITEMA and TVN_DELETEITEMW are predefined in the compiler, but
' // TVN_DELETEITEMA is called TVN_DELETEITEM, so we need to redefine it.
%TVN_DELETEITEMA        = %TVN_FIRST - 9
%TVN_DELETEITEMW        = %TVN_FIRST - 58
#IF %DEF(%UNICODE)
%TVN_DELETEITEM = %TVN_DELETEITEMW
#ELSE
%TVN_DELETEITEM = %TVN_DELETEITEMA
#ENDIF
' // TVN_BEGINLABELEDITA and TVN_BEGINLABELEDITW are predefined in the compiler, but
' // TVN_BEGINLABELEDITA is called TVN_BEGINLABELEDIT, so we need to redefine it.
%TVN_BEGINLABELEDITA    = %TVN_FIRST - 10
%TVN_BEGINLABELEDITW    = %TVN_FIRST - 59
#IF %DEF(%UNICODE)
%TVN_BEGINLABELEDIT = %TVN_BEGINLABELEDITW
#ELSE
%TVN_BEGINLABELEDIT = %TVN_BEGINLABELEDITA
#ENDIF
' // TVN_ENDLABELEDITA and TVN_ENDLABELEDITW are predefined in the compiler, but
' // TVN_ENDLABELEDITA is called TVN_ENDLABELEDIT, so we need to redefine it.
%TVN_ENDLABELEDITA      = %TVN_FIRST - 11
%TVN_ENDLABELEDITW      = %TVN_FIRST - 60
#IF %DEF(%UNICODE)
%TVN_ENDLABELEDIT = %TVN_ENDLABELEDITW
#ELSE
%TVN_ENDLABELEDIT = %TVN_ENDLABELEDITA
#ENDIF
'%TVN_KEYDOWN            = %TVN_FIRST - 12

'#if (_WIN32_IE >= 0x0400)
%TVN_GETINFOTIPA        = %TVN_FIRST - 13
%TVN_GETINFOTIPW        = %TVN_FIRST - 14
#IF %DEF(%UNICODE)
%TVN_GETINFOTIP = %TVN_GETINFOTIPW
#ELSE
%TVN_GETINFOTIP = %TVN_GETINFOTIPA
#ENDIF
%TVN_SINGLEEXPAND       = %TVN_FIRST - 15

%TVNRET_DEFAULT = 0
%TVNRET_SKIPOLD = 1
%TVNRET_SKIPNEW = 2

'#endif // 0x400

'#if (_WIN32_IE >= 0x0600)
%TVN_ITEMCHANGINGA      = %TVN_FIRST - 16
%TVN_ITEMCHANGINGW      = %TVN_FIRST - 17
#IF %DEF(%UNICODE)
%TVN_ITEMCHANGING = %TVN_ITEMCHANGINGW
#ELSE
%TVN_ITEMCHANGING = %TVN_ITEMCHANGINGA
#ENDIF
%TVN_ITEMCHANGEDA       = %TVN_FIRST - 18
%TVN_ITEMCHANGEDW       = %TVN_FIRST - 19
#IF %DEF(%UNICODE)
%TVN_ITEMCHANGED = %TVN_ITEMCHANGEDW
#ELSE
%TVN_ITEMCHANGED = %TVN_ITEMCHANGEDA
#ENDIF
%TVN_ASYNCDRAW          = %TVN_FIRST - 20
'#endif

'#ifdef _WIN32
'#include <pshpack1.h>
'#endif

' // Size = 18 bytes
TYPE TVKEYDOWN WORD
   hdr   AS NMHDR   ' NMHDR hdr
   wVKey AS WORD    ' WORD wVKey
   flags AS DWORD   ' UINT flags
END TYPE

MACRO NMTVKEYDOWN = TV_KEYDOWN
MACRO TV_KEYDOWN  = TVKEYDOWN

'#ifdef _WIN32
'#include <poppack.h>
'#endif

'#if (_WIN32_IE >= 0x0300)

' // Size = 60 bytes
TYPE NMTVCUSTOMDRAW DWORD
   nmcd      AS NMCUSTOMDRAW   ' NMCUSTOMDRAW nmcd
   clrText   AS DWORD          ' COLORREF     clrText
   clrTextBk AS DWORD          ' COLORREF     clrTextBk
#IF (%WIN32_IE >= &H0400)
   iLevel    AS LONG           ' int iLevel
#ENDIF
END TYPE

'#if (_WIN32_IE >= 0x0400)

'// for tooltips

' // Size = 28 bytes
TYPE NMTVGETINFOTIPA DWORD
   hdr        AS NMHDR        ' NMHDR hdr
   pszText    AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax AS LONG         ' int cchTextMax
   hItem      AS DWORD        ' HTREEITEM hItem
   lParam     AS LONG         ' LPARAM lParam
END TYPE

' // Size = 28 bytes
TYPE NMTVGETINFOTIPW DWORD
   hdr        AS NMHDR          ' NMHDR hdr
   pszText    AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax AS LONG           ' int cchTextMax
   hItem      AS DWORD          ' HTREEITEM hItem
   lParam     AS LONG           ' LPARAM lParam
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMTVGETINFOTIP = NMTVGETINFOTIPW
#ELSE
   MACRO NMTVGETINFOTIP = NMTVGETINFOTIPA
#ENDIF

'// treeview's customdraw return meaning don't draw images.  valid on CDRF_NOTIFYITEMPREPAINT
%TVCDRF_NOIMAGES        = &H00010000???

'#endif      // _WIN32_IE >= 0x0400

'#if (_WIN32_IE > 0x0600)

' // Size = 32 bytes
TYPE TVITEMCHANGE DWORD
   hdr       AS NMHDR   ' NMHDR hdr
   uChanged  AS DWORD   ' UINT uChanged
   hItem     AS DWORD   ' HTREEITEM hItem
   uStateNew AS DWORD   ' UINT uStateNew
   uStateOld AS DWORD   ' UINT uStateOld
   lParam    AS LONG    ' LPARAM lParam
END TYPE

MACRO NMTVITEMCHANGE = TVITEMCHANGE

#IF NOT %DEF(%NOIMAGELIST)
' // Size = 36 bytes
TYPE NMTVASYNCDRAW DWORD
   hdr            AS NMHDR                     ' NMHDR hdr
   pimldp         AS IMAGELISTDRAWPARAMS PTR   ' IMAGELISTDRAWPARAMS* // the draw that failed
   hr             AS LONG                      ' HRESULT // why it failed
   hItem          AS DWORD                     ' HTREEITEM // item that failed to draw icon
   lParam         AS LONG                      ' LPARAM // its data
   ' // Out Params
   dwRetFlags     AS DWORD                     ' DWORD // What listview should do on return
   iRetImageIndex AS LONG                      ' int // used if ADRF_DRAWIMAGE is returned
END TYPE
#ENDIF

'#endif      // _WIN32_IE >= 0x0600

#ENDIF    ' // NOTREEVIEW


'#if (_WIN32_IE >= 0x0300)

'#ifndef NOUSEREXCONTROLS
#IF NOT %DEF(%NOUSEREXCONTROLS)

'////////////////////  ComboBoxEx ////////////////////////////////

$WC_COMBOBOXEXA      = "ComboBoxEx32"
$$WC_COMBOBOXEX      = "ComboBoxEx32"$$
#IF %DEF(%UNICODE)
   MACRO WC_COMBOBOXEX = $$WC_COMBOBOXEX
#ELSE
   MACRO WC_COMBOBOXEX = $WC_COMBOBOXEX
#ENDIF

%CBEIF_TEXT             = &H00000001???
%CBEIF_IMAGE            = &H00000002???
%CBEIF_SELECTEDIMAGE    = &H00000004???
%CBEIF_OVERLAY          = &H00000008???
%CBEIF_INDENT           = &H00000010???
%CBEIF_LPARAM           = &H00000020???

%CBEIF_DI_SETITEM       = &H10000000???

' // Size = 36 bytes
TYPE COMBOBOXEXITEMA DWORD
   mask           AS DWORD        ' UINT mask
   iItem          AS DWORD        ' INT_PTR iItem
   pszText        AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax     AS LONG         ' int cchTextMax
   iImage         AS LONG         ' int iImage
   iSelectedImage AS LONG         ' int iSelectedImage
   iOverlay       AS LONG         ' int iOverlay
   iIndent        AS LONG         ' int iIndent
   lParam         AS LONG         ' LPARAM lParam
END TYPE

' // Size = 36 bytes
TYPE COMBOBOXEXITEMW DWORD
   mask           AS DWORD          ' UINT mask
   iItem          AS DWORD          ' INT_PTR iItem
   pszText        AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax     AS LONG           ' int cchTextMax
   iImage         AS LONG           ' int iImage
   iSelectedImage AS LONG           ' int iSelectedImage
   iOverlay       AS LONG           ' int iOverlay
   iIndent        AS LONG           ' int iIndent
   lParam         AS LONG           ' LPARAM lParam
END TYPE

#IF %DEF(%UNICODE)
   MACRO COMBOBOXEXITEM = COMBOBOXEXITEMW
#ELSE
   MACRO COMBOBOXEXITEM = COMBOBOXEXITEMA
#ENDIF

%CBEM_INSERTITEMA       = %WM_USER + 1
%CBEM_SETIMAGELIST      = %WM_USER + 2
%CBEM_GETIMAGELIST      = %WM_USER + 3
%CBEM_GETITEMA          = %WM_USER + 4
%CBEM_SETITEMA          = %WM_USER + 5
%CBEM_DELETEITEM        = %CB_DELETESTRING
%CBEM_GETCOMBOCONTROL   = %WM_USER + 6
%CBEM_GETEDITCONTROL    = %WM_USER + 7
'#if (_WIN32_IE >= 0x0400)
%CBEM_SETEXSTYLE        = %WM_USER + 8     ' use  SETEXTENDEDSTYLE instead
%CBEM_SETEXTENDEDSTYLE  = %WM_USER + 14    ' lparam == new style, wParam (optional) == mask
%CBEM_GETEXSTYLE        = %WM_USER + 9     ' use GETEXTENDEDSTYLE instead
%CBEM_GETEXTENDEDSTYLE  = %WM_USER + 9
%CBEM_SETUNICODEFORMAT  = %CCM_SETUNICODEFORMAT
%CBEM_GETUNICODEFORMAT  = %CCM_GETUNICODEFORMAT
'#else
'#define CBEM_SETEXSTYLE         (WM_USER + 8)
'#define CBEM_GETEXSTYLE         (WM_USER + 9)
'#endif
%CBEM_HASEDITCHANGED    = %WM_USER + 10
%CBEM_INSERTITEMW       = %WM_USER + 11
#IF %DEF(%UNICODE)
%CBEM_INSERTITEM = %CBEM_INSERTITEMW
#ELSE
%CBEM_INSERTITEM = %CBEM_INSERTITEMA
#ENDIF
%CBEM_SETITEMW          = %WM_USER + 12
#IF %DEF(%UNICODE)
%CBEM_SETITEM = %CBEM_SETITEMW
#ELSE
%CBEM_SETITEM = %CBEM_SETITEMA
#ENDIF
%CBEM_GETITEMW          = %WM_USER + 13
#IF %DEF(%UNICODE)
%CBEM_GETITEM = %CBEM_GETITEMW
#ELSE
%CBEM_GETITEM = %CBEM_GETITEMA
#ENDIF

'#if (_WIN32_WINNT >= 0x501)
%CBEM_SETWINDOWTHEME     = %CCM_SETWINDOWTHEME
'#endif

%CBES_EX_NOEDITIMAGE         = &H00000001???
%CBES_EX_NOEDITIMAGEINDENT   = &H00000002???
%CBES_EX_PATHWORDBREAKPROC   = &H00000004???
'#if (_WIN32_IE >= 0x0400)
%CBES_EX_NOSIZELIMIT         = &H00000008???
%CBES_EX_CASESENSITIVE       = &H00000010???
'#if (_WIN32_WINNT >= 0x0600)
%CBES_EX_TEXTENDELLIPSIS     = &H00000020???
'#endif

' // Size = 48 bytes
TYPE NMCOMBOBOXEXA DWORD
   hdr    AS NMHDR             ' NMHDR hdr
   ceItem AS COMBOBOXEXITEMA   ' COMBOBOXEXITEMA ceItem
END TYPE

' // Size = 48 bytes
TYPE NMCOMBOBOXEXW DWORD
   hdr    AS NMHDR             ' NMHDR hdr
   ceItem AS COMBOBOXEXITEMW   ' COMBOBOXEXITEMW ceItem
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMCOMBOBOXEX = NMCOMBOBOXEXW
#ELSE
   MACRO NMCOMBOBOXEX = NMCOMBOBOXEXA
#ENDIF

'#endif      // _WIN32_IE >= 0x0400

'#if (_WIN32_IE >= 0x0400)
%CBEN_GETDISPINFOA = %CBEN_FIRST - 0
'#endif
%CBEN_INSERTITEM   = %CBEN_FIRST - 1
%CBEN_DELETEITEM   = %CBEN_FIRST - 2
%CBEN_BEGINEDIT    = %CBEN_FIRST - 4
%CBEN_ENDEDITA     = %CBEN_FIRST - 5
%CBEN_ENDEDITW     = %CBEN_FIRST - 6
#IF %DEF(%UNICODE)
%CBEN_ENDEDIT = %CBEN_ENDEDITW
#ELSE
%CBEN_ENDEDIT = %CBEN_ENDEDITA
#ENDIF

'#if (_WIN32_IE >= 0x0400)
%CBEN_GETDISPINFOW = %CBEN_FIRST - 7
#IF %DEF(%UNICODE)
%CBEN_GETDISPINFO = %CBEN_GETDISPINFOW
#ELSE
%CBEN_GETDISPINFO = %CBEN_GETDISPINFOA
#ENDIF
'#endif

'#if (_WIN32_IE >= 0x0400)
%CBEN_DRAGBEGINA   = %CBEN_FIRST - 8
%CBEN_DRAGBEGINW   = %CBEN_FIRST - 9
#IF %DEF(%UNICODE)
%CBEN_DRAGBEGIN = %CBEN_DRAGBEGINW
#ELSE
%CBEN_DRAGBEGIN = %CBEN_DRAGBEGINA
#ENDIF
'#endif  //(_WIN32_IE >= 0x0400)

'// lParam specifies why the endedit is happening

%CBENF_KILLFOCUS   = 1
%CBENF_RETURN      = 2
%CBENF_ESCAPE      = 3
%CBENF_DROPDOWN    = 4

%CBEMAXSTRLEN      = 260

'#if (_WIN32_IE >= 0x0400)
'// CBEN_DRAGBEGIN sends this information ...

' // Size = 276 bytes
TYPE NMCBEDRAGBEGINA DWORD
   hdr     AS NMHDR                      ' NMHDR hdr
   iItemid AS LONG                       ' int   iItemid
   szText  AS ASCIIZ * %CBEMAXSTRLEN     ' char szText[CBEMAXSTRLEN]
END TYPE

' // Size = 276 bytes
TYPE NMCBEDRAGBEGINW DWORD
   hdr     AS NMHDR                      ' NMHDR hdr
   iItemid AS LONG                       ' int   iItemid
   szText  AS WSTRINGZ * %CBEMAXSTRLEN   ' WCHAR szText[CBEMAXSTRLEN]
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMCBEDRAGBEGIN = NMCBEDRAGBEGINW
#ELSE
   MACRO NMCBEDRAGBEGIN = NMCBEDRAGBEGINA
#ENDIF

'// CBEN_ENDEDIT sends this information...
'// fChanged if the user actually did anything
'// iNewSelection gives what would be the new selection unless the notify is failed
'//                      iNewSelection may be CB_ERR if there's no match

' // Size = 284 bytes
TYPE NMCBEENDEDITA DWORD
   hdr           AS NMHDR                        ' NMHDR hdr
   fChanged      AS LONG                         ' BOOL fChanged
   iNewSelection AS LONG                         ' int iNewSelection
   szText        AS ASCIIZ * %CBEMAXSTRLEN       ' char szText[CBEMAXSTRLEN]
   iWhy          AS LONG                         ' int iWhy
END TYPE

' // Size = 284 bytes
TYPE NMCBEENDEDITW DWORD
   hdr           AS NMHDR                        ' NMHDR hdr
   fChanged      AS LONG                         ' BOOL fChanged
   iNewSelection AS LONG                         ' int iNewSelection
   szText        AS WSTRINGZ * %CBEMAXSTRLEN     ' WCHAR szText[CBEMAXSTRLEN]
   iWhy          AS LONG                         ' int iWhy
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMCBEENDEDIT = NMCBEENDEDITW
#ELSE
   MACRO NMCBEENDEDIT = NMCBEENDEDITA
#ENDIF

#ENDIF   ' // NOUSEREXCONTROLS

'#endif      // _WIN32_IE >= 0x0300

'//====== TAB CONTROL ==========================================================

#IF NOT %DEF(%NOTABCONTROL)

$WC_TABCONTROLA      = "SysTabControl32"
$$WC_TABCONTROLW     = "SysTabControl32"$$
#IF %DEF(%UNICODE)
   MACRO WC_TABCONTROL = $$WC_TABCONTROLW
#ELSE
   MACRO WC_TABCONTROL = $WC_TABCONTROLA
#ENDIF

'#if (_WIN32_IE >= 0x0300)
'%TCS_SCROLLOPPOSITE      = &H0001???  ' // assumes multiline tab
'%TCS_BOTTOM              = &H0002???
'%TCS_RIGHT               = &H0002???
'%TCS_MULTISELECT         = &H0004???  ' // allow multi-select in button mode
'#endif
'#if (_WIN32_IE >= 0x0400)
'%TCS_FLATBUTTONS         = &H0008???
'#endif
'%TCS_FORCEICONLEFT       = &H0010???
'%TCS_FORCELABELLEFT      = &H0020???
'#if (_WIN32_IE >= 0x0300)
'%TCS_HOTTRACK            = &H0040???
'%TCS_VERTICAL            = &H0080???
'#endif
'%TCS_TABS                = &H0000???
'%TCS_BUTTONS             = &H0100???
'%TCS_SINGLELINE          = &H0000???
%TCS_MULTILINE           = &H0200???
'%TCS_RIGHTJUSTIFY        = &H0000???
'%TCS_FIXEDWIDTH          = &H0400???
'%TCS_RAGGEDRIGHT         = &H0800???
'%TCS_FOCUSONBUTTONDOWN   = &H1000???
'%TCS_OWNERDRAWFIXED      = &H2000???
'%TCS_TOOLTIPS            = &H4000???
'%TCS_FOCUSNEVER          = &H8000???

'#if (_WIN32_IE >= 0x0400)
'// EX styles for use with TCM_SETEXTENDEDSTYLE
'%TCS_EX_FLATSEPARATORS   = &H00000001
'%TCS_EX_REGISTERDROP     = &H00000002
'#endif

%TCM_GETIMAGELIST        = %TCM_FIRST + 2
%TCM_SETIMAGELIST        = %TCM_FIRST + 3
%TCM_GETITEMCOUNT        = %TCM_FIRST + 4

'%TCIF_TEXT               = &H0001???
'%TCIF_IMAGE              = &H0002???
'%TCIF_RTLREADING         = &H0004???
'%TCIF_PARAM              = &H0008???
'#if (_WIN32_IE >= 0x0300)
'%TCIF_STATE              = &H0010???
'%TCIS_BUTTONPRESSED      = &H0001???
'#endif
'#if (_WIN32_IE >= 0x0400)
'%TCIS_HIGHLIGHTED        = &H0002???
'#endif

' // Size = 24 bytes
TYPE TCITEMHEADERA DWORD
   mask          AS DWORD        ' UINT mask
   lpReserved1   AS DWORD        ' UINT lpReserved1
   lpReserved2   AS DWORD        ' UINT lpReserved2
   pszText       AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax    AS LONG         ' int cchTextMax
   iImage        AS LONG         ' int iImage
END TYPE

' // Size = 24 bytes
TYPE TCITEMHEADERW DWORD
   mask          AS DWORD          ' UINT mask
   lpReserved1   AS DWORD          ' UINT lpReserved1
   lpReserved2   AS DWORD          ' UINT lpReserved2
   pszText       AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax    AS LONG           ' int cchTextMax
   iImage        AS LONG           ' int iImage
END TYPE

MACRO TC_ITEMHEADERA = TCITEMHEADERA
MACRO TC_ITEMHEADERW = TCITEMHEADERW

#IF %DEF(%UNICODE)
   MACRO TCITEMHEADER = TCITEMHEADERW
#ELSE
   MACRO TCITEMHEADER = TCITEMHEADERA
#ENDIF

'typedef struct tagTCITEMA
'{
'    UINT mask;
'#if (_WIN32_IE >= 0x0300)
'    DWORD dwState;
'    DWORD dwStateMask;
'#else
'    UINT lpReserved1;
'    UINT lpReserved2;
'#endif
'    LPSTR pszText;
'    int cchTextMax;
'    int iImage;

'    LPARAM lParam;
'} TCITEMA, *LPTCITEMA;

' // Size = 28 bytes
TYPE TCITEMA DWORD
   mask          AS DWORD        ' UINT mask
   dwState       AS DWORD        ' DWORD dwState
   dwStateMask   AS DWORD        ' DWORD dwStateMask
   pszText       AS ASCIIZ PTR   ' LPSTR pszText
   cchTextMax    AS LONG         ' int cchTextMax
   iImage        AS LONG         ' int iImage
   lParam        AS LONG         ' LPARAM lParam
END TYPE

'typedef struct tagTCITEMW
'{
'    UINT mask;
'#if (_WIN32_IE >= 0x0300)
'    DWORD dwState;
'    DWORD dwStateMask;
'#else
'    UINT lpReserved1;
'    UINT lpReserved2;
'#endif
'    LPWSTR pszText;
'    int cchTextMax;
'    int iImage;

'    LPARAM lParam;
'} TCITEMW, *LPTCITEMW;

' // Size = 28 bytes
TYPE TCITEMW DWORD
   mask          AS DWORD          ' UINT mask
   dwState       AS DWORD          ' DWORD dwState
   dwStateMask   AS DWORD          ' DWORD dwStateMask
   pszText       AS WSTRINGZ PTR   ' LPWSTR pszText
   cchTextMax    AS LONG           ' int cchTextMax
   iImage        AS LONG           ' int iImage
   lParam        AS LONG           ' LPARAM lParam
END TYPE

MACRO TC_ITEMA = TCITEMA
MACRO TC_ITEMW = TCITEMW

#IF %DEF(%UNICODE)
   MACRO TCITEM  = TCITEMW
   MACRO TC_ITEM = TCITEMW
#ELSE
   MACRO TCITEM  = TCITEMA
   MACRO TC_ITEM = TCITEMA
#ENDIF

%TCM_GETITEMA            = %TCM_FIRST + 5
%TCM_GETITEMW            = %TCM_FIRST + 60
#IF %DEF(%UNICODE)
%TCM_GETITEM = %TCM_GETITEMW
#ELSE
%TCM_GETITEM = %TCM_GETITEMA
#ENDIF
%TCM_SETITEMA            = %TCM_FIRST + 6
%TCM_SETITEMW            = %TCM_FIRST + 61
#IF %DEF(%UNICODE)
%TCM_SETITEM = %TCM_SETITEMW
#ELSE
%TCM_SETITEM = %TCM_SETITEMA
#ENDIF
%TCM_INSERTITEMA         = %TCM_FIRST + 7
%TCM_INSERTITEMW         = %TCM_FIRST + 62
#IF %DEF(%UNICODE)
%TCM_INSERTITEM = %TCM_INSERTITEMW
#ELSE
%TCM_INSERTITEM = %TCM_INSERTITEMA
#ENDIF
%TCM_DELETEITEM          = %TCM_FIRST + 8
%TCM_DELETEALLITEMS      = %TCM_FIRST + 9
%TCM_GETITEMRECT         = %TCM_FIRST + 10
%TCM_GETCURSEL           = %TCM_FIRST + 11
%TCM_SETCURSEL           = %TCM_FIRST + 12

'%TCHT_NOWHERE      = &H0001???
'%TCHT_ONITEMICON   = &H0002???
'%TCHT_ONITEMLABEL  = &H0004???
'%TCHT_ONITEM       = %TCHT_ONITEMICON OR %TCHT_ONITEMLABEL

' // Size = 12 bytes
TYPE TC_HITTESTINFO DWORD
   pt    AS POINT   ' POINT pt
   flags AS DWORD   ' UINT flags
END TYPE

MACRO TCHITTESTINFO = TC_HITTESTINFO

%TCM_HITTEST             = %TCM_FIRST + 13
%TCM_SETITEMEXTRA        = %TCM_FIRST + 14
%TCM_ADJUSTRECT          = %TCM_FIRST + 40
%TCM_SETITEMSIZE         = %TCM_FIRST + 41
%TCM_REMOVEIMAGE         = %TCM_FIRST + 42
%TCM_SETPADDING          = %TCM_FIRST + 43
%TCM_GETROWCOUNT         = %TCM_FIRST + 44
%TCM_GETTOOLTIPS         = %TCM_FIRST + 45
%TCM_SETTOOLTIPS         = %TCM_FIRST + 46
%TCM_GETCURFOCUS         = %TCM_FIRST + 47
%TCM_SETCURFOCUS         = %TCM_FIRST + 48

'#if (_WIN32_IE >= 0x0300)
%TCM_SETMINTABWIDTH      = %TCM_FIRST + 49
%TCM_DESELECTALL         = %TCM_FIRST + 50

'#endif

'#if (_WIN32_IE >= 0x0400)

%TCM_HIGHLIGHTITEM       = %TCM_FIRST + 51
%TCM_SETEXTENDEDSTYLE    = %TCM_FIRST + 52  ' optional wParam == mask
%TCM_GETEXTENDEDSTYLE    = %TCM_FIRST + 53
%TCM_SETUNICODEFORMAT    = %CCM_SETUNICODEFORMAT
%TCM_GETUNICODEFORMAT    = %CCM_GETUNICODEFORMAT

'#endif      // _WIN32_IE >= 0x0400

'%TCN_KEYDOWN             = %TCN_FIRST - 0

'#ifdef _WIN32
'#include <pshpack1.h>
'#endif

' // Size = 18 bytes
TYPE TCKEYDOWN WORD
   hdr    AS NMHDR   ' NMHDR hdr
   wVKey  AS WORD    ' WORD wVKey
   flags  AS DWORD   ' UINT flags
END TYPE

MACRO TC_KEYDOWN  = TCKEYDOWN
MACRO NMTCKEYDOWN = TCKEYDOWN

'#ifdef _WIN32
'#include <poppack.h>
'#endif

'%TCN_SELCHANGE   = %TCN_FIRST - 1
'%TCN_SELCHANGING = %TCN_FIRST - 2
'#if (_WIN32_IE >= 0x0400)
'%TCN_GETOBJECT   = %TCN_FIRST - 3
'#endif      // _WIN32_IE >= 0x0400
'#if (_WIN32_IE >= 0x0500)
'%TCN_FOCUSCHANGE = %TCN_FIRST - 4
'#endif      // _WIN32_IE >= 0x0500

#ENDIF   ' // NOTABCONTROL


'//====== ANIMATE CONTROL ======================================================

#IF NOT %DEF(%NOANIMATE)

$ANIMATE_CLASSA      = "SysAnimate32"
$$ANIMATE_CLASSW     = "SysAnimate32"$$
#IF %DEF(%UNICODE)
   MACRO ANIMATE_CLASS = $$ANIMATE_CLASSW
#ELSE
   MACRO ANIMATE_CLASS = $ANIMATE_CLASSA
#ENDIF

%ACS_CENTER             = &H0001???
%ACS_TRANSPARENT        = &H0002???
%ACS_AUTOPLAY           = &H0004???
'#if (_WIN32_IE >= 0x0300)
%ACS_TIMER              = &H0008???  ' don't use threads... use timers
'#endif

%ACM_OPENA              = %WM_USER + 100
%ACM_OPENW              = %WM_USER + 103
#IF %DEF(%UNICODE)
%ACM_OPEN = %ACM_OPENW
#ELSE
%ACM_OPEN = %ACM_OPENA
#ENDIF

%ACM_PLAY               = %WM_USER + 101
%ACM_STOP               = %WM_USER + 102
%ACM_ISPLAYING          = %WM_USER + 104

%ACN_START              = 1
%ACN_STOP               = 2

#ENDIF   ' // NOANIMATE

'#if (_WIN32_IE >= 0x0300)
'//====== MONTHCAL CONTROL ======================================================

#IF NOT %DEF(%NOMONTHCAL)

$MONTHCAL_CLASSA     = "SysMonthCal32"
$$MONTHCAL_CLASSW    = "SysMonthCal32"$$
#IF %DEF(%UNICODE)
   MACRO MONTHCAL_CLASS = $$MONTHCAL_CLASSW
#ELSE
   MACRO MONTHCAL_CLASS = $MONTHCAL_CLASSA
#ENDIF

'// bit-packed array of "bold" info for a month
'// if a bit is on, that day is drawn bold
'typedef DWORD MONTHDAYSTATE, *LPMONTHDAYSTATE;

%MCM_FIRST = &H1000

'// BOOL MonthCal_GetCurSel(HWND hmc, LPSYSTEMTIME pst)
'//   returns FALSE if MCS_MULTISELECT
'//   returns TRUE and sets *pst to the currently selected date otherwise
%MCM_GETCURSEL       = %MCM_FIRST + 1

'// BOOL MonthCal_SetCurSel(HWND hmc, LPSYSTEMTIME pst)
'//   returns FALSE if MCS_MULTISELECT
'//   returns TURE and sets the currently selected date to *pst otherwise
%MCM_SETCURSEL       = %MCM_FIRST + 2

'// DWORD MonthCal_GetMaxSelCount(HWND hmc)
'//   returns the maximum number of selectable days allowed
%MCM_GETMAXSELCOUNT  = %MCM_FIRST + 3

'// BOOL MonthCal_SetMaxSelCount(HWND hmc, UINT n)
'//   sets the max number days that can be selected iff MCS_MULTISELECT
%MCM_SETMAXSELCOUNT  = %MCM_FIRST + 4

'// BOOL MonthCal_GetSelRange(HWND hmc, LPSYSTEMTIME rgst)
'//   sets rgst[0] to the first day of the selection range
'//   sets rgst[1] to the last day of the selection range
%MCM_GETSELRANGE     = %MCM_FIRST + 5

'// BOOL MonthCal_SetSelRange(HWND hmc, LPSYSTEMTIME rgst)
'//   selects the range of days from rgst[0] to rgst[1]
%MCM_SETSELRANGE     = %MCM_FIRST + 6

'// DWORD MonthCal_GetMonthRange(HWND hmc, DWORD gmr, LPSYSTEMTIME rgst)
'//   if rgst specified, sets rgst[0] to the starting date and
'//      and rgst[1] to the ending date of the the selectable (non-grayed)
'//      days if GMR_VISIBLE or all the displayed days (including grayed)
'//      if GMR_DAYSTATE.
'//   returns the number of months spanned by the above range.
%MCM_GETMONTHRANGE   = %MCM_FIRST + 7

'// BOOL MonthCal_SetDayState(HWND hmc, int cbds, DAYSTATE *rgds)
'//   cbds is the count of DAYSTATE items in rgds and it must be equal
'//   to the value returned from MonthCal_GetMonthRange(hmc, GMR_DAYSTATE, NULL)
'//   This sets the DAYSTATE bits for each month (grayed and non-grayed
'//   days) displayed in the calendar. The first bit in a month's DAYSTATE
'//   corresponts to bolding day 1, the second bit affects day 2, etc.
%MCM_SETDAYSTATE     = %MCM_FIRST + 8

'// BOOL MonthCal_GetMinReqRect(HWND hmc, LPRECT prc)
'//   sets *prc the minimal size needed to display one month
'//   To display two months, undo the AdjustWindowRect calculation already done to
'//   this rect, double the width, and redo the AdjustWindowRect calculation --
'//   the monthcal control will display two calendars in this window (if you also
'//   double the vertical size, you will get 4 calendars)
'//   NOTE: if you want to gurantee that the "Today" string is not clipped,
'//   get the MCM_GETMAXTODAYWIDTH and use the max of that width and this width
%MCM_GETMINREQRECT       = %MCM_FIRST + 9

'// set colors to draw control with -- see MCSC_ bits below
%MCM_SETCOLOR            = %MCM_FIRST + 10
%MCM_GETCOLOR            = %MCM_FIRST + 11

%MCSC_BACKGROUND   = 0   ' the background color (between months)
%MCSC_TEXT         = 1   ' the dates
%MCSC_TITLEBK      = 2   ' background of the title
%MCSC_TITLETEXT    = 3
%MCSC_MONTHBK      = 4   ' background within the month cal
%MCSC_TRAILINGTEXT = 5   ' the text color of header & trailing days

'// set what day is "today"   send NULL to revert back to real date
%MCM_SETTODAY    = %MCM_FIRST + 12

'// get what day is "today"
'// returns BOOL for success/failure
%MCM_GETTODAY    = %MCM_FIRST + 13

' // Size = 60 bytes (32 bytes in XP)
TYPE MCHITTESTINFO DWORD
   cbSize AS DWORD        ' UINT
   pt     AS POINT        ' POINT
   uHit   AS DWORD        ' UINT // out param
   st     AS SYSTEMTIME   ' SYSTEMTIME
'#IF (%NTDDI_VERSION >= %NTDDI_VISTA)
#IF %WINVER >= &H0600
   rc      AS RECT        ' RECT
   iOffset AS LONG        ' int
   iRow    AS LONG        ' int
   iCol    AS LONG        ' int
#ENDIF
END TYPE

%MCHITTESTINFO_V1_SIZE = 32
%MCHITTESTINFO_V6_SIZE = 60

'// determine what pinfo->pt is over
%MCM_HITTEST        = %MCM_FIRST + 14

%MCHT_TITLE         = &H00010000???
%MCHT_CALENDAR      = &H00020000???
%MCHT_TODAYLINK     = &H00030000???

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%MCHT_CALENDARCONTROL = &H00100000???
'#endif

%MCHT_NEXT          = &H01000000???  ' these indicate that hitting
%MCHT_PREV          = &H02000000???  ' here will go to the next/prev month

%MCHT_NOWHERE       = &H00000000???

%MCHT_TITLEBK            = %MCHT_TITLE
%MCHT_TITLEMONTH         = %MCHT_TITLE OR &H0001
%MCHT_TITLEYEAR          = %MCHT_TITLE OR &H0002
%MCHT_TITLEBTNNEXT       = %MCHT_TITLE OR %MCHT_NEXT OR &H0003
%MCHT_TITLEBTNPREV       = %MCHT_TITLE OR %MCHT_PREV OR &H0003

%MCHT_CALENDARBK         = %MCHT_CALENDAR
%MCHT_CALENDARDATE       = %MCHT_CALENDAR OR &H0001
%MCHT_CALENDARDATENEXT   = %MCHT_CALENDARDATE OR %MCHT_NEXT
%MCHT_CALENDARDATEPREV   = %MCHT_CALENDARDATE OR %MCHT_PREV
%MCHT_CALENDARDAY        = %MCHT_CALENDAR OR &H0002
%MCHT_CALENDARWEEKNUM    = %MCHT_CALENDAR OR &H0003
%MCHT_CALENDARDATEMIN    = %MCHT_CALENDAR OR &H0004
%MCHT_CALENDARDATEMAX    = %MCHT_CALENDAR OR &H0005

'// set first day of week to iDay:
'// 0 for Monday, 1 for Tuesday, ..., 6 for Sunday
'// -1 for means use locale info
%MCM_SETFIRSTDAYOFWEEK = %MCM_FIRST + 15

'// DWORD result...  low word has the day.  high word is bool if this is app set
'// or not (FALSE == using locale info)
%MCM_GETFIRSTDAYOFWEEK = %MCM_FIRST + 16

'// DWORD MonthCal_GetRange(HWND hmc, LPSYSTEMTIME rgst)
'//   modifies rgst[0] to be the minimum ALLOWABLE systemtime (or 0 if no minimum)
'//   modifies rgst[1] to be the maximum ALLOWABLE systemtime (or 0 if no maximum)
'//   returns GDTR_MIN|GDTR_MAX if there is a minimum|maximum limit
%MCM_GETRANGE          = %MCM_FIRST + 17

'// BOOL MonthCal_SetRange(HWND hmc, DWORD gdtr, LPSYSTEMTIME rgst)
'//   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0], otherwise removes minimum
'//   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1], otherwise removes maximum
'//   returns TRUE on success, FALSE on error (such as invalid parameters)
%MCM_SETRANGE          = %MCM_FIRST + 18

'// int MonthCal_GetMonthDelta(HWND hmc)
'//   returns the number of months one click on a next/prev button moves by
%MCM_GETMONTHDELTA     = %MCM_FIRST + 19

'// int MonthCal_SetMonthDelta(HWND hmc, int n)
'//   sets the month delta to n. n==0 reverts to moving by a page of months
'//   returns the previous value of n.
%MCM_SETMONTHDELTA     = %MCM_FIRST + 20

'// DWORD MonthCal_GetMaxTodayWidth(HWND hmc, LPSIZE psz)
'//   sets *psz to the maximum width/height of the "Today" string displayed
'//   at the bottom of the calendar (as long as MCS_NOTODAY is not specified)
%MCM_GETMAXTODAYWIDTH  = %MCM_FIRST + 21

'#if (_WIN32_IE >= 0x0400)
%MCM_SETUNICODEFORMAT  = %CCM_SETUNICODEFORMAT
%MCM_GETUNICODEFORMAT  = %CCM_GETUNICODEFORMAT

'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// View
%MCMV_MONTH     = 0
%MCMV_YEAR      = 1
%MCMV_DECADE    = 2
%MCMV_CENTURY   = 3
%MCMV_MAX       = %MCMV_CENTURY

%MCM_GETCURRENTVIEW   = %MCM_FIRST + 22
%MCM_GETCALENDARCOUNT = %MCM_FIRST + 23

'// Part
%MCGIP_CALENDARCONTROL      = 0
%MCGIP_NEXT                 = 1
%MCGIP_PREV                 = 2
%MCGIP_FOOTER               = 3
%MCGIP_CALENDAR             = 4
%MCGIP_CALENDARHEADER       = 5
%MCGIP_CALENDARBODY         = 6
%MCGIP_CALENDARROW          = 7
%MCGIP_CALENDARCELL         = 8

%MCGIF_DATE                 = &H00000001???
%MCGIF_RECT                 = &H00000002???
%MCGIF_NAME                 = &H00000004???

'// Note: iRow of -1 refers to the row header and iCol of -1 refers to the col header.
' // Size = 84 bytes
TYPE MCGRIDINFO DWORD
   cbSize    AS DWORD          ' UNIT
   dwPart    AS DWORD          ' DWORD
   dwFlags   AS DWORD          ' DWORD
   iCalendar AS LONG           ' int
   iRow      AS LONG           ' int
   iCol      AS LONG           ' int
   bSelected AS LONG           ' BOOL
   stStart   AS SYSTEMTIME     ' SYSTEMTIME
   stEnd     AS SYSTEMTIME     ' SYSTEMTIME
   rc        AS RECT           ' RECT
   pszName   AS WSTRINGZ PTR   ' PWSTR
   cchName   AS DWORD          ' size_t
END TYPE

%MCM_GETCALENDARGRIDINFO = %MCM_FIRST + 24
%MCM_GETCALID            = %MCM_FIRST + 27
%MCM_SETCALID            = %MCM_FIRST + 28

'// Returns the min rect that will fit the max number of calendars for the passed in rect.
%MCM_SIZERECTTOMIN       = %MCM_FIRST + 29
%MCM_SETCALENDARBORDER   = %MCM_FIRST + 30
%MCM_GETCALENDARBORDER   = %MCM_FIRST + 31
%MCM_SETCURRENTVIEW      = %MCM_FIRST + 32

'#endif

'// MCN_SELCHANGE is sent whenever the currently displayed date changes
'// via month change, year change, keyboard navigation, prev/next button
'//

' // Size = 44 bytes
UNION NMSELCHANGE_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr        AS NMHDR        ' NMHDR
   nmhdr      AS NMHDR        ' NMHDR
END UNION

TYPE NMSELCHANGE DWORD
   NMSELCHANGE_UNION          ' this must be first, so we don't break WM_NOTIFY
   stSelStart AS SYSTEMTIME   ' SYSTEMTIME stSelStart
   stSelEnd   AS SYSTEMTIME   ' SYSTEMTIME stSelEnd
END TYPE

'%MCN_SELCHANGE       = %MCN_FIRST + 1   ' Prior to Windows Vista
%MCN_SELCHANGE       = %MCN_FIRST - 3   ' // -749

'// MCN_GETDAYSTATE is sent for MCS_DAYSTATE controls whenever new daystate
'// information is needed (month or year scroll) to draw bolding information.
'// The app must fill in cDayState months worth of information starting from
'// stStart date. The app may fill in the array at prgDayState or change
'// prgDayState to point to a different array out of which the information
'// will be copied. (similar to tooltips)
'//
' // Size = 36 bytes
UNION NMDAYSTATE_UNION DWORD  ' // To allow the use of both hdr and nmhdr
   hdr        AS NMHDR        ' NMHDR
   nmhdr      AS NMHDR        ' NMHDR
END UNION

TYPE NMDAYSTATE DWORD
   NMDAYSTATE_UNION            ' // this must be first, so we don't break WM_NOTIFY
   stStart     AS SYSTEMTIME   ' SYSTEMTIME      stStart
   cDayState   AS LONG         ' int             cDayState
   prgDayState AS DWORD PTR    ' LPMONTHDAYSTATE prgDayState // points to cDayState MONTHDAYSTATEs
END TYPE

'%MCN_GETDAYSTATE     = %MCN_FIRST + 3   ' Prior to Windows Vista
%MCN_GETDAYSTATE     = %MCN_FIRST - 1   ' // -747

'// MCN_SELECT is sent whenever a selection has occured (via mouse or keyboard)
'//
'typedef NMSELCHANGE NMSELECT, *LPNMSELECT;

' // Size = 44 bytes
UNION NMSELECT_UNION DWORD    ' // To allow the use of both hdr and nmhdr
   hdr        AS NMHDR        ' NMHDR
   nmhdr      AS NMHDR        ' NMHDR
END UNION

TYPE NMSELECT DWORD
   NMSELECT_UNION             ' // this must be first, so we don't break WM_NOTIFY
   stSelStart AS SYSTEMTIME   ' SYSTEMTIME stSelStart
   stSelEnd   AS SYSTEMTIME   ' SYSTEMTIME stSelEnd
END TYPE

'%MCN_SELECT          = %MCN_FIRST + 4   ' Prior to Windows Vista
%MCN_SELECT           = %MCN_FIRST   ' // -746

' // Size = 20 bytes
UNION NMVIEWCHANGE_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr       AS NMHDR   ' NMHDR
   nmhdr     AS NMHDR   ' NMHDR
END UNION

TYPE NMVIEWCHANGE DWORD
   NMVIEWCHANGE_UNION   ' NMHDR // this must be first, so we don't break WM_NOTIFY
   dwOldView AS DWORD   ' DWORD
   dwNewView AS DWORD   ' DWORD
END TYPE

%MCN_VIEWCHANGE      = %MCN_FIRST - 4  ' // -750

%MCS_DAYSTATE         = &H0001???
%MCS_MULTISELECT      = &H0002???
%MCS_WEEKNUMBERS      = &H0004???
'#if (_WIN32_IE >= 0x0400)
%MCS_NOTODAYCIRCLE    = &H0008???
%MCS_NOTODAY          = &H0010???
'#else
'#define MCS_NOTODAY         0x0008
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%MCS_NOTRAILINGDATES  = &H0040???
%MCS_SHORTDAYSOFWEEK  = &H0080???
%MCS_NOSELCHANGEONNAV = &H0100???
'#endif

%GMR_VISIBLE     = 0       ' visible portion of display
%GMR_DAYSTATE    = 1       ' above plus the grayed out parts of
                           ' partially displayed months

#ENDIF   ' // NOMONTHCAL


'//====== DATETIMEPICK CONTROL ==================================================

#IF NOT %DEF(%NODATETIMEPICK)

$DATETIMEPICK_CLASSA      = "SysDateTimePick32"
$$DATETIMEPICK_CLASSW     = "SysDateTimePick32"$$
#IF %DEF(%UNICODE)
   MACRO DATETIMEPICK_CLASS = $$DATETIMEPICK_CLASSW
#ELSE
   MACRO DATETIMEPICK_CLASS = $DATETIMEPICK_CLASSA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 56 bytes
TYPE DATETIMEPICKERINFO DWORD
   cbSize       AS DWORD   ' DWORD
   rcCheck      AS RECT    ' RECT
   stateCheck   AS DWORD   ' DWORD
   rcButton     AS RECT    ' RECT
   stateButton  AS DWORD   ' DWORD
   hwndEdit     AS DWORD   ' HWND
   hwndUD       AS DWORD   ' HWND
   hwndDropDown AS DWORD   ' HWND
END TYPE

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%DTM_FIRST        = &H1000

'// DWORD DateTimePick_GetSystemtime(HWND hdp, LPSYSTEMTIME pst)
'//   returns GDT_NONE if "none" is selected (DTS_SHOWNONE only)
'//   returns GDT_VALID and modifies *pst to be the currently selected value
%DTM_GETSYSTEMTIME   = %DTM_FIRST + 1

'// BOOL DateTime_SetSystemtime(HWND hdp, DWORD gd, LPSYSTEMTIME pst)
'//   if gd==GDT_NONE, sets datetimepick to None (DTS_SHOWNONE only)
'//   if gd==GDT_VALID, sets datetimepick to *pst
'//   returns TRUE on success, FALSE on error (such as bad params)
%DTM_SETSYSTEMTIME   = %DTM_FIRST + 2

'// DWORD DateTime_GetRange(HWND hdp, LPSYSTEMTIME rgst)
'//   modifies rgst[0] to be the minimum ALLOWABLE systemtime (or 0 if no minimum)
'//   modifies rgst[1] to be the maximum ALLOWABLE systemtime (or 0 if no maximum)
'//   returns GDTR_MIN|GDTR_MAX if there is a minimum|maximum limit
%DTM_GETRANGE = %DTM_FIRST + 3

'// BOOL DateTime_SetRange(HWND hdp, DWORD gdtr, LPSYSTEMTIME rgst)
'//   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0], otherwise removes minimum
'//   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1], otherwise removes maximum
'//   returns TRUE on success, FALSE on error (such as invalid parameters)
%DTM_SETRANGE = %DTM_FIRST + 4

'// BOOL DateTime_SetFormat(HWND hdp, LPCTSTR sz)
'//   sets the display formatting string to sz (see GetDateFormat and GetTimeFormat for valid formatting chars)
'//   NOTE: 'X' is a valid formatting character which indicates that the application
'//   will determine how to display information. Such apps must support DTN_WMKEYDOWN,
'//   DTN_FORMAT, and DTN_FORMATQUERY.
%DTM_SETFORMATA = %DTM_FIRST + 5
%DTM_SETFORMATW = %DTM_FIRST + 50
#IF %DEF(%UNICODE)
%DTM_SETFORMAT = %DTM_SETFORMATW
#ELSE
%DTM_SETFORMAT = %DTM_SETFORMATA
#ENDIF

%DTM_SETMCCOLOR    = %DTM_FIRST + 6
%DTM_GETMCCOLOR    = %DTM_FIRST + 7

'// HWND DateTime_GetMonthCal(HWND hdp)
'//   returns the HWND of the MonthCal popup window. Only valid
'// between DTN_DROPDOWN and DTN_CLOSEUP notifications.
%DTM_GETMONTHCAL   = %DTM_FIRST + 8

'#if (_WIN32_IE >= 0x0400)

%DTM_SETMCFONT     = %DTM_FIRST + 9
%DTM_GETMCFONT     = %DTM_FIRST + 10

'#endif      // _WIN32_IE >= 0x0400

'#if (NTDDI_VERSION >= NTDDI_VISTA)

%DTM_SETMCSTYLE    = %DTM_FIRST + 11
%DTM_GETMCSTYLE    = %DTM_FIRST + 12
%DTM_CLOSEMONTHCAL = %DTM_FIRST + 13

'// DateTime_GetDateTimePickerInfo(HWND hdp, DATETIMEPICKERINFO* pdtpi)
'// Retrieves information about the selected date time picker.
%DTM_GETDATETIMEPICKERINFO = %DTM_FIRST + 14

%DTM_GETIDEALSIZE = %DTM_FIRST + 15

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%DTS_UPDOWN          = &H0001??? ' use UPDOWN instead of MONTHCAL
%DTS_SHOWNONE        = &H0002??? ' allow a NONE selection
%DTS_SHORTDATEFORMAT = &H0000??? ' use the short date format (app must forward WM_WININICHANGE messages)
%DTS_LONGDATEFORMAT  = &H0004??? ' use the long date format (app must forward WM_WININICHANGE messages)
'#if (_WIN32_IE >= 0x500)
%DTS_SHORTDATECENTURYFORMAT = &H000C??? ' short date format with century (app must forward WM_WININICHANGE messages)
'#endif // (_WIN32_IE >= 0x500)
%DTS_TIMEFORMAT      = &H0009??? ' use the time format (app must forward WM_WININICHANGE messages)
%DTS_APPCANPARSE     = &H0010??? ' allow user entered strings (app MUST respond to DTN_USERSTRING)
%DTS_RIGHTALIGN      = &H0020??? ' right-align popup instead of left-align it

'%DTN_DATETIMECHANGE  = %DTN_FIRST + 1 ' Prior to Windows Vista
%DTN_DATETIMECHANGE  = %DTN_FIRST2 - 6   ' // the systemtime has changed, -759

' // Size = 32 bytes
UNION NMDATETIMECHANGE_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr     AS NMHDR        ' NMHDR
   nmhdr   AS NMHDR        ' NMHDR
END UNION

TYPE NMDATETIMECHANGE DWORD
   NMDATETIMECHANGE_UNION  ' NMHDR // this must be first, so we don't break WM_NOTIFY
   dwFlags AS DWORD        ' DWORD       dwFlags  // GDT_VALID or GDT_NONE
   st      AS SYSTEMTIME   ' SYSTEMTIME  st       // valid iff dwFlags==GDT_VALID
END TYPE

'%DTN_USERSTRINGA  = %DTN_FIRST + 2   ' Prior to Windows Vista
'%DTN_USERSTRINGW  = %DTN_FIRST + 15  ' Prior to Windows Vista

%DTN_USERSTRINGA  = %DTN_FIRST2 - 5   ' // the user has entered a string, -758
%DTN_USERSTRINGW  = %DTN_FIRST - 5    ' // -745
#IF %DEF(%UNICODE)
%DTN_USERSTRING = %DTN_USERSTRINGW
#ELSE
%DTN_USERSTRING = %DTN_USERSTRINGA
#ENDIF

' // Size = 36 bytes
UNION NMDATETIMESTRINGA_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr           AS NMHDR       ' NMHDR
   nmhdr         AS NMHDR       ' NMHDR
END UNION

TYPE NMDATETIMESTRINGA DWORD
   NMDATETIMESTRINGA_UNION      ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszUserString AS ASCIIZ PTR  ' LPCSTR     pszUserString  // string user entered
   st            AS SYSTEMTIME  ' SYSTEMTIME st             // app fills this in
   dwFlags       AS DWORD       ' DWORD      dwFlags        // GDT_VALID or GDT_NONE
END TYPE

' // Size = 36 bytes
UNION NMDATETIMESTRINGW_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr           AS NMHDR       ' NMHDR
   nmhdr         AS NMHDR       ' NMHDR
END UNION

TYPE NMDATETIMESTRINGW DWORD
   NMDATETIMESTRINGW_UNION         ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszUserString AS WSTRINGZ PTR   ' LPCWSTR    pszUserString  // string user entered
   st            AS SYSTEMTIME     ' SYSTEMTIME st             // app fills this in
   dwFlags       AS DWORD          ' DWORD      dwFlags        // GDT_VALID or GDT_NONE
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMDATETIMESTRING = NMDATETIMESTRINGW
#ELSE
   MACRO NMDATETIMESTRING = NMDATETIMESTRINGA
#ENDIF

'%DTN_WMKEYDOWNA  = %DTN_FIRST + 3   ' Prior to Windows Vista
'%DTN_WMKEYDOWNW  = %DTN_FIRST + 16  ' Prior to Windows Vista

%DTN_WMKEYDOWNA  = %DTN_FIRST2 - 4   ' // modify keydown on app format field (X), , -757
%DTN_WMKEYDOWNW  = %DTN_FIRST - 4    ' // -744
#IF %DEF(%UNICODE)
%DTN_WMKEYDOWN = %DTN_WMKEYDOWNW
#ELSE
%DTN_WMKEYDOWN = %DTN_WMKEYDOWNA
#ENDIF

' // Size = 36 bytes
UNION NMDATETIMEWMKEYDOWNA_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr       AS NMHDR        ' NMHDR
   nmhdr     AS NMHDR        ' NMHDR
END UNION

TYPE NMDATETIMEWMKEYDOWNA DWORD
   NMDATETIMEWMKEYDOWNA_UNION   ' NMHDR // this must be first, so we don't break WM_NOTIFY
   nVirtKey  AS LONG            ' int        nVirtKey  // virtual key code of WM_KEYDOWN which MODIFIES an X field
   pszFormat AS ASCIIZ PTR      ' LPCSTR     pszFormat // format substring
   st        AS SYSTEMTIME      ' SYSTEMTIME st        // current systemtime, app should modify based on key
END TYPE

' // Size = 36 bytes
UNION NMDATETIMEWMKEYDOWNW_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr       AS NMHDR        ' NMHDR
   nmhdr     AS NMHDR        ' NMHDR
END UNION

TYPE NMDATETIMEWMKEYDOWNW DWORD
   NMDATETIMEWMKEYDOWNW_UNION  ' NMHDR // this must be first, so we don't break WM_NOTIFY
   nVirtKey  AS LONG           ' int        nVirtKey  // virtual key code of WM_KEYDOWN which MODIFIES an X field
   pszFormat AS WSTRINGZ PTR   ' LPCWSTR    pszFormat // format substring
   st        AS SYSTEMTIME     ' SYSTEMTIME st        // current systemtime, app should modify based on key
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMDATETIMEWMKEYDOWN = NMDATETIMEWMKEYDOWNW
#ELSE
   MACRO NMDATETIMEWMKEYDOWN = NMDATETIMEWMKEYDOWNA
#ENDIF

'%DTN_FORMATA  = %DTN_FIRST + 4    ' Prior to Windows Vista
'%DTN_FORMATW  = %DTN_FIRST + 17   ' Prior to Windows Vista

%DTN_FORMATA  = %DTN_FIRST2 - 3   ' // query display for app format field (X), -756
%DTN_FORMATW  = %DTN_FIRST - 3    ' // -743
#IF %DEF(%UNICODE)
%DTN_FORMAT = %DTN_FORMATW
#ELSE
%DTN_FORMAT = %DTN_FORMATA
#ENDIF

' // Size = 100 bytes
UNION NMDATETIMEFORMATA_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr        AS NMHDR         ' NMHDR
   nmhdr      AS NMHDR         ' NMHDR
END UNION

TYPE NMDATETIMEFORMATA DWORD
   NMDATETIMEFORMATA_UNION     ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszFormat  AS ASCIIZ PTR    ' LPCSTR pszFormat    // format substring
   st         AS SYSTEMTIME    ' SYSTEMTIME st       // current systemtime
   pszDisplay AS ASCIIZ PTR    ' LPCSTR pszDisplay   // string to display
   szDisplay  AS ASCIIZ * 64   ' CHAR szDisplay[64]  // buffer pszDisplay originally points at
END TYPE

' // Size = 100 bytes
UNION NMDATETIMEFORMATW_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr        AS NMHDR           ' NMHDR
   nmhdr      AS NMHDR           ' NMHDR
END UNION

TYPE NMDATETIMEFORMATW DWORD
   NMDATETIMEFORMATW_UNION       ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszFormat  AS WSTRINGZ PTR    ' LPCWSTR pszFormat   // format substring
   st         AS SYSTEMTIME      ' SYSTEMTIME st       // current systemtime
   pszDisplay AS WSTRINGZ PTR    ' LPCWSTR pszDisplay  // string to display
   szDisplay  AS WSTRINGZ * 64   ' WCHAR szDisplay[64] // buffer pszDisplay originally points at
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMDATETIMEFORMAT = NMDATETIMEFORMATW
#ELSE
   MACRO NMDATETIMEFORMAT = NMDATETIMEFORMATA
#ENDIF

'%DTN_FORMATQUERYA = %DTN_FIRST + 5     ' Prior to Windows Vista
'%DTN_FORMATQUERYW = %DTN_FIRST + 18    ' Prior to Windows Vista

%DTN_FORMATQUERYA  = %DTN_FIRST2 - 2   ' // query formatting info for app format field (X), -755
%DTN_FORMATQUERYW  = %DTN_FIRST - 2    ' // -742
#IF %DEF(%UNICODE)
%DTN_FORMATQUERY = %DTN_FORMATQUERYW
#ELSE
%DTN_FORMATQUERY = %DTN_FORMATQUERYA
#ENDIF

' // Size = 24 bytes
UNION NMDATETIMEFORMATQUERYA_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr       AS NMHDR        ' NMHDR
   nmhdr     AS NMHDR        ' NMHDR
END UNION

TYPE NMDATETIMEFORMATQUERYA DWORD
   NMDATETIMEFORMATQUERYA_UNION   ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszFormat AS ASCIIZ PTR        ' LPCSTR pszFormat  // format substring
   szMax     AS SIZE              ' SIZE szMax        // max bounding rectangle app will use for this format string
END TYPE

' // Size = 24 bytes
UNION NMDATETIMEFORMATQUERYW_UNION DWORD ' // To allow the use of both hdr and nmhdr
   hdr       AS NMHDR        ' NMHDR
   nmhdr     AS NMHDR        ' NMHDR
END UNION

TYPE NMDATETIMEFORMATQUERYW DWORD
   NMDATETIMEFORMATQUERYW_UNION   ' NMHDR // this must be first, so we don't break WM_NOTIFY
   pszFormat AS WSTRINGZ PTR      ' LPCWSTR pszFormat // format substring
   szMax     AS SIZE              ' SIZE szMax        // max bounding rectangle app will use for this format string
END TYPE

#IF %DEF(%UNICODE)
   MACRO NMDATETIMEFORMATQUERY = NMDATETIMEFORMATQUERYW
#ELSE
   MACRO NMDATETIMEFORMATQUERY = NMDATETIMEFORMATQUERYA
#ENDIF

'%DTN_DROPDOWN   = %DTN_FIRST + 6   ' Prior to Windows Vista
'%DTN_CLOSEUP    = %DTN_FIRST + 7   ' Prior to Windows Vista

%DTN_DROPDOWN    = %DTN_FIRST2 - 1   ' // MonthCal has dropped down, -754
%DTN_CLOSEUP     = %DTN_FIRST2       ' // MonthCal is popping up, -753

%GDTR_MIN       = &H0001
%GDTR_MAX       = &H0002

%GDT_ERROR      = -1
%GDT_VALID      = 0
%GDT_NONE       = 1

#ENDIF  ' // NODATETIMEPICK


'#if (_WIN32_IE >= 0x0400)

#IF NOT %DEF(%NOIPADDRESS)

'///////////////////////////////////////////////
'///    IP Address edit control

'// Messages sent to IPAddress controls

%IPM_CLEARADDRESS  = %WM_USER + 100 ' no parameters
%IPM_SETADDRESS    = %WM_USER + 101 ' lparam = TCP/IP address
%IPM_GETADDRESS    = %WM_USER + 102 ' lresult = # of non black fields. lparam = LPDWORD for TCP/IP address
%IPM_SETRANGE      = %WM_USER + 103 ' wparam = field, lparam = range
%IPM_SETFOCUS      = %WM_USER + 104 ' wparam = field
%IPM_ISBLANK       = %WM_USER + 105 ' no parameters

$WC_IPADDRESSA      = "SysIPAddress32"
$$WC_IPADDRESSW     = "SysIPAddress32"$$
#IF %DEF(%UNICODE)
   MACRO WC_IPADDRESS = $$WC_IPADDRESSW
#ELSE
   MACRO WC_IPADDRESS = $WC_IPADDRESSA
#ENDIF

%IPN_FIELDCHANGED  = %IPN_FIRST - 0

' // Size = 20 bytes
TYPE NMIPADDRESS DWORD
   hdr    AS NMHDR   ' NMHDR hdr
   iField AS LONG    ' int iField
   iValue AS LONG    ' int iValue
END TYPE

'// The following is a useful macro for passing the range values in the
'// IPM_SETRANGE message.

FUNCTION MAKEIPRANGE (BYVAL low AS BYTE, BYVAL high AS BYTE) AS LONG
   LOCAL dHigh AS DWORD
   dHigh = high
   SHIFT LEFT dHigh, 8
   dHigh = dHigh OR low
   FUNCTION = dHigh
END FUNCTION

'// And this is a useful macro for making the IP Address to be passed
'// as a LPARAM.

FUNCTION MAKEIPADDRESS (BYVAL b1 AS DWORD, BYVAL b2 AS DWORD, _
   BYVAL b3 AS DWORD, BYVAL b4 AS DWORD) AS LONG
   SHIFT LEFT b1, 24
   SHIFT LEFT b2, 16
   SHIFT LEFT b3, 8
   FUNCTION = b1 + b2 + b3 + b4
END FUNCTION

'// Get individual number
FUNCTION FIRST_IPADDRESS (BYVAL x AS DWORD) AS DWORD
   SHIFT RIGHT x, 24
   FUNCTION = x AND &HFF???
END FUNCTION

FUNCTION SECOND_IPADDRESS (BYVAL x AS DWORD) AS DWORD
   SHIFT RIGHT x, 16
   FUNCTION = x AND &HFF???
END FUNCTION

FUNCTION THIRD_IPADDRESS (BYVAL x AS DWORD) AS DWORD
   SHIFT RIGHT x, 8
   FUNCTION = x AND &HFF???
END FUNCTION

FUNCTION FOURTH_IPADDRESS (BYVAL x AS DWORD) AS DWORD
   FUNCTION = x AND &HFF???
END FUNCTION

#ENDIF  ' // NOIPADDRESS


'//---------------------------------------------------------------------------------------
'//---------------------------------------------------------------------------------------
'///  ====================== Pager Control =============================
'//---------------------------------------------------------------------------------------
'//---------------------------------------------------------------------------------------

#IF NOT %DEF(%NOPAGESCROLLER)

'//Pager Class Name
$WC_PAGESCROLLERA      = "SysPager"
$$WC_PAGESCROLLERW     = "SysPager"$$
#IF %DEF(%UNICODE)
   MACRO WC_PAGESCROLLER = $$WC_PAGESCROLLERW
#ELSE
   MACRO WC_PAGESCROLLER = $WC_PAGESCROLLERA
#ENDIF

'//---------------------------------------------------------------------------------------
'// Pager Control Styles
'//---------------------------------------------------------------------------------------

%PGS_VERT                = &H00000000???
%PGS_HORZ                = &H00000001???
%PGS_AUTOSCROLL          = &H00000002???
%PGS_DRAGNDROP           = &H00000004???

'//---------------------------------------------------------------------------------------
'// Pager Button State
'//---------------------------------------------------------------------------------------
'//The scroll can be in one of the following control State
%PGF_INVISIBLE       = 0      ' Scroll button is not visible
%PGF_NORMAL          = 1      ' Scroll button is in normal state
%PGF_GRAYED          = 2      ' Scroll button is in grayed state
%PGF_DEPRESSED       = 4      ' Scroll button is in depressed state
%PGF_HOT             = 8      ' Scroll button is in hot state

'// The following identifiers specifies the button control
%PGB_TOPORLEFT       = 0
%PGB_BOTTOMORRIGHT   = 1

'//---------------------------------------------------------------------------------------
'// Pager Control  Messages
'//---------------------------------------------------------------------------------------
%PGM_SETCHILD            = %PGM_FIRST + 1  ' lParam == hwnd
%PGM_RECALCSIZE          = %PGM_FIRST + 2
%PGM_FORWARDMOUSE        = %PGM_FIRST + 3
%PGM_SETBKCOLOR          = %PGM_FIRST + 4
%PGM_GETBKCOLOR          = %PGM_FIRST + 5
%PGM_SETBORDER           = %PGM_FIRST + 6
%PGM_GETBORDER           = %PGM_FIRST + 7
%PGM_SETPOS              = %PGM_FIRST + 8
%PGM_GETPOS              = %PGM_FIRST + 9
%PGM_SETBUTTONSIZE       = %PGM_FIRST + 10
%PGM_GETBUTTONSIZE       = %PGM_FIRST + 11
%PGM_GETBUTTONSTATE      = %PGM_FIRST + 12
%PGM_GETDROPTARGET       = %CCM_GETDROPTARGET

'//---------------------------------------------------------------------------------------
'//Pager Control Notification Messages
'//---------------------------------------------------------------------------------------


'// PGN_SCROLL Notification Message

%PGN_SCROLL      = %PGN_FIRST - 1

%PGF_SCROLLUP    = 1
%PGF_SCROLLDOWN  = 2
%PGF_SCROLLLEFT  = 4
%PGF_SCROLLRIGHT = 8

'//Keys down
%PGK_SHIFT       = 1
%PGK_CONTROL     = 2
%PGK_MENU        = 4

'#ifdef _WIN32
'#include <pshpack1.h>
'#endif

'// This structure is sent along with PGN_SCROLL notifications
' // Size = 46 bytes
TYPE NMPGSCROLL WORD
   hdr      AS NMHDR   ' NMHDR hdr
   fwKeys   AS WORD    ' WORD fwKeys    // Specifies which keys are down when this notification is send
   rcParent AS RECT    ' RECT rcParent  // Contains Parent Window Rect
   iDir     AS LONG    ' int  iDir      // Scrolling Direction
   iXpos    AS LONG    ' int  iXpos     // Horizontal scroll position
   iYpos    AS LONG    ' int  iYpos     // Vertical scroll position
   iScroll  AS LONG    ' int  iScroll   // [in/out] Amount to scroll
END TYPE

'#ifdef _WIN32
'#include <poppack.h>
'#endif

'// PGN_CALCSIZE Notification Message

%PGN_CALCSIZE    = %PGN_FIRST - 2

%PGF_CALCWIDTH   = 1
%PGF_CALCHEIGHT  = 2

' // Size = 24 bytes
TYPE NMPGCALCSIZE DWORD
   hdr     AS NMHDR   ' NMHDR   hdr
   dwFlag  AS DWORD   ' DWORD   dwFlag
   iWidth  AS LONG    ' int     iWidth
   iHeight AS LONG    ' int     iHeight
END TYPE

'// PGN_HOTITEMCHANGE Notification Message

%PGN_HOTITEMCHANGE   = %PGN_FIRST - 3

'/*
'The PGN_HOTITEMCHANGE notification uses these notification
'flags defined in TOOLBAR:

'#define HICF_ENTERING       0x00000010          // idOld is invalid
'#define HICF_LEAVING        0x00000020          // idNew is invalid
'*/

'// Structure for PGN_HOTITEMCHANGE notification
'//
' // Size = 24 bytes
TYPE NMPGHOTITEM DWORD
   hdr     AS NMHDR   ' NMHDR   hdr
   idOld   AS LONG    ' int     idOld
   idNew   AS LONG    ' int     idNew
   dwFlags AS DWORD   ' DWORD   dwFlags           // HICF_*
END TYPE

#ENDIF   ' // NOPAGESCROLLER

'////======================  End Pager Control ==========================================

'//
'// === Native Font Control ===
'//

#IF NOT %DEF(%NONATIVEFONTCTL)

'//NativeFont Class Name
$WC_NATIVEFONTCTLA      = "NativeFontCtl"
$$WC_NATIVEFONTCTLW     = "NativeFontCtl"$$
#IF %DEF(%UNICODE)
   MACRO WC_NATIVEFONTCTL = $$WC_NATIVEFONTCTLW
#ELSE
   MACRO WC_NATIVEFONTCTL = $WC_NATIVEFONTCTLA
#ENDIF

'// style definition
%NFS_EDIT         = &H0001???
%NFS_STATIC       = &H0002???
%NFS_LISTCOMBO    = &H0004???
%NFS_BUTTON       = &H0008???
%NFS_ALL          = &H0010???
%NFS_USEFONTASSOC = &H0020???

#ENDIF  ' // NONATIVEFONTCTL
'// === End Native Font Control ===

'/// ====================== Button Control =============================

#IF NOT %DEF(%NOBUTTON)

'// Button Class Name
$WC_BUTTONA             = "Button"
$$WC_BUTTONW            = "Button"$$
#IF %DEF(%UNICODE)
   MACRO WC_BUTTON = $$WC_BUTTONW
#ELSE
   MACRO WC_BUTTON = $WC_BUTTONA
#ENDIF

'#if (_WIN32_WINNT >= 0x501)
%BUTTON_IMAGELIST_ALIGN_LEFT   = 0
%BUTTON_IMAGELIST_ALIGN_RIGHT  = 1
%BUTTON_IMAGELIST_ALIGN_TOP    = 2
%BUTTON_IMAGELIST_ALIGN_BOTTOM = 3
%BUTTON_IMAGELIST_ALIGN_CENTER = 4      ' // Doesn't draw text

' // Size = 24 bytes
TYPE BUTTON_IMAGELIST DWORD
   himl AS DWORD     ' HIMAGELIST  himl;   // Index: Normal, hot pushed, disabled. If count is less than 4, we use index 1
   margin AS RECT    ' RECT        margin; // Margin around icon.
   uAlign AS DWORD   ' UINT        uAlign
END TYPE

%BCM_GETIDEALSIZE        = %BCM_FIRST + &H0001
%BCM_SETIMAGELIST        = %BCM_FIRST + &H0002
%BCM_GETIMAGELIST        = %BCM_FIRST + &H0003
%BCM_SETTEXTMARGIN       = %BCM_FIRST + &H0004
%BCM_GETTEXTMARGIN       = %BCM_FIRST + &H0005

' // Size = 16 bytes
TYPE NMBCHOTITEM DWORD
   hdr     AS NMHDR   ' NMHDR   hdr
   dwFlags AS DWORD   ' DWORD   dwFlags;           // HICF_*
END TYPE

%BCN_HOTITEMCHANGE       = %BCN_FIRST + &H0001

%BST_HOT                 = &H0200???

'#if _WIN32_WINNT >= 0x0600

'// BUTTON STATE FLAGS
%BST_DROPDOWNPUSHED      = &H0400???

'// BUTTON STYLES
%BS_SPLITBUTTON          = &H0000000C&
%BS_DEFSPLITBUTTON       = &H0000000D&
%BS_COMMANDLINK          = &H0000000E&
%BS_DEFCOMMANDLINK       = &H0000000F&

'// SPLIT BUTTON INFO mask flags
%BCSIF_GLYPH             = &H0001???
%BCSIF_IMAGE             = &H0002???
%BCSIF_STYLE             = &H0004???
%BCSIF_SIZE              = &H0008???

'// SPLIT BUTTON STYLE flags
%BCSS_NOSPLIT            = &H0001???
%BCSS_STRETCH            = &H0002???
%BCSS_ALIGNLEFT          = &H0004???
%BCSS_IMAGE              = &H0008???

'// BUTTON STRUCTURES
' // Size = 20 bytes
TYPE BUTTON_SPLITINFO DWORD
   mask        AS DWORD   ' UINT
   himlGlyph   AS DWORD   ' HIMAGELIST // interpreted as WCHAR if BCSIF_GLYPH is set
   uSplitStyle AS DWORD   ' UINT
   size        AS SIZE    ' SIZE
END TYPE

'// BUTTON MESSAGES
%BCM_SETDROPDOWNSTATE    = %BCM_FIRST + &H0006
%BCM_SETSPLITINFO        = %BCM_FIRST + &H0007
%BCM_GETSPLITINFO        = %BCM_FIRST + &H0008
%BCM_SETNOTE             = %BCM_FIRST + &H0009
%BCM_GETNOTE             = %BCM_FIRST + &H000A
%BCM_GETNOTELENGTH       = %BCM_FIRST + &H000B

'#if _WIN32_WINNT >= 0x0600
'// Macro to use on a button or command link to display an elevated icon
%BCM_SETSHIELD           = %BCM_FIRST + &H000C
'#endif /* _WIN32_WINNT >= 0x0600 */

'// Value to pass to BCM_SETIMAGELIST to indicate that no glyph should be
'// displayed
'#define BCCL_NOGLYPH  (HIMAGELIST)(-1)
%BCCL_NOGLYPH = &HFFFFFFFF???

'// NOTIFICATION MESSAGES
' // Size = 28 bytes
TYPE NMBCDROPDOWN DWORD
   hdr      AS NMHDR   ' NMHDR hdr
   rcButton AS RECT    ' RECT rcButton
END TYPE

%BCN_DROPDOWN           = %BCN_FIRST + &H0002

'#endif // _WIN32_WINNT >= 0x600

#ENDIF   ' // NOBUTTON

'/// =====================  End Button Control =========================

'/// ====================== Static Control =============================

#IF NOT %DEF(%NOSTATIC)

$WC_STATICA             = "Static"
$$WC_STATICW            = "Static"$$
#IF %DEF(%UNICODE)
   MACRO WC_STATIC = $$WC_STATICW
#ELSE
   MACRO WC_STATIC = $WC_STATICA
#ENDIF

#ENDIF   ' // NOSTATIC

'/// =====================  End Static Control =========================

'/// ====================== Edit Control =============================

#IF NOT %DEF(%NOEDIT)

$WC_EDITA               = "Edit"
$$WC_EDITW              = "Edit"$$
#IF %DEF(%UNICODE)
   MACRO WC_EDIT = $$WC_EDITW
#ELSE
   MACRO WC_EDIT = $WC_EDITA
#ENDIF

'#if (_WIN32_WINNT >= 0x501)
%EM_SETCUEBANNER        = %ECM_FIRST + 1     '   // Set the cue banner with the lParm = LPCWSTR
%EM_GETCUEBANNER        = %ECM_FIRST + 2     ' // Set the cue banner with the lParm = LPCWSTR

' // Size = 16 bytes
TYPE EDITBALLOONTIP DWORD
   cbStruct AS DWORD          ' DWORD   cbStruct
   pszTitle AS WSTRINGZ PTR   ' LPCWSTR pszTitle
   pszText  AS WSTRINGZ PTR   ' LPCWSTR pszText
   ttiIcon  AS LONG           ' INT     ttiIcon; // From TTI_*
END TYPE

%EM_SHOWBALLOONTIP      = %ECM_FIRST + 3    ' // Show a balloon tip associated to the edit control
%EM_HIDEBALLOONTIP      = %ECM_FIRST + 4    ' // Hide any balloon tip associated with the edit control

'#if _WIN32_WINNT >= 0x0600

%EM_SETHILITE           = %ECM_FIRST + 5
%EM_GETHILITE           = %ECM_FIRST + 6

'#endif

'#endif

#ENDIF   ' // NOEDIT

'/// =====================  End Edit Control =========================

'/// ====================== Listbox Control =============================

#IF NOT %DEF(%NOLISTBOX)

$WC_LISTBOXA            = "ListBox"
$$WC_LISTBOXW           = "ListBox"$$
#IF %DEF(%UNICODE)
   MACRO WC_LISTBOX = $$WC_LISTBOXW
#ELSE
   MACRO WC_LISTBOX = $WC_LISTBOXA
#ENDIF

#ENDIF   ' // NOLISTBOX

'/// =====================  End Listbox Control =========================

'/// ====================== Combobox Control =============================

#IF NOT %DEF(%NOCOMBOBOX)

$WC_COMBOBOXA           = "ComboBox"
$$WC_COMBOBOXW          = "ComboBox"$$
#IF %DEF(%UNICODE)
   MACRO WC_COMBOBOX = $$WC_COMBOBOXW
#ELSE
   MACRO WC_COMBOBOX = $WC_COMBOBOXA
#ENDIF

#ENDIF   ' // NOCOMBOBOX


'#if (_WIN32_WINNT >= 0x501)

'// custom combobox control messages
%CB_SETMINVISIBLE        = %CBM_FIRST + 1
%CB_GETMINVISIBLE        = %CBM_FIRST + 2
%CB_SETCUEBANNER         = %CBM_FIRST + 3
%CB_GETCUEBANNER         = %CBM_FIRST + 4

'#endif

'/// =====================  End Combobox Control =========================

'/// ====================== Scrollbar Control ============================

#IF NOT %DEF(%NOSCROLLBAR)

$WC_SCROLLBARA           = "ScrollBar"
$$WC_SCROLLBARW          = "ScrollBar"$$
#IF %DEF(%UNICODE)
   MACRO WC_SCROLLBAR = $$WC_SCROLLBARW
#ELSE
   MACRO WC_SCROLLBAR = $WC_SCROLLBARA
#ENDIF

#ENDIF   ' // NOSCROLLBAR


'/// ===================== End Scrollbar Control =========================

'// ===================== Task Dialog =========================
#IF NOT %DEF(%NOTASKDIALOG)
'// Task Dialog is only available starting Windows Vista
'#if (NTDDI_VERSION >= NTDDI_VISTA)

'#ifdef _WIN32
'#include <pshpack1.h>
'#endif

'typedef HRESULT (CALLBACK *PFTASKDIALOGCALLBACK)(__in HWND hwnd, __in UINT msg, __in WPARAM wParam, __in LPARAM lParam, __in LONG_PTR lpRefData);
'FUNCTION TaskDialogCallback(BYVAL hwnd AS DWORD, BYVAL msg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG, BYVAL lpRefData AS DWORD) AS LONG

' enum TASKDIALOG_FLAGS
%TDF_ENABLE_HYPERLINKS               = &H0001???
%TDF_USE_HICON_MAIN                  = &H0002???
%TDF_USE_HICON_FOOTER                = &H0004???
%TDF_ALLOW_DIALOG_CANCELLATION       = &H0008???
%TDF_USE_COMMAND_LINKS               = &H0010???
%TDF_USE_COMMAND_LINKS_NO_ICON       = &H0020???
%TDF_EXPAND_FOOTER_AREA              = &H0040???
%TDF_EXPANDED_BY_DEFAULT             = &H0080???
%TDF_VERIFICATION_FLAG_CHECKED       = &H0100???
%TDF_SHOW_PROGRESS_BAR               = &H0200???
%TDF_SHOW_MARQUEE_PROGRESS_BAR       = &H0400???
%TDF_CALLBACK_TIMER                  = &H0800???
%TDF_POSITION_RELATIVE_TO_WINDOW     = &H1000???
%TDF_RTL_LAYOUT                      = &H2000???
%TDF_NO_DEFAULT_RADIO_BUTTON         = &H4000???
%TDF_CAN_BE_MINIMIZED                = &H8000???

'typedef int TASKDIALOG_FLAGS;                         // Note: _TASKDIALOG_FLAGS is an int

' enum TASKDIALOG_MESSAGES
%TDM_NAVIGATE_PAGE                   = %WM_USER+101
%TDM_CLICK_BUTTON                    = %WM_USER+102  ' // wParam = Button ID
%TDM_SET_MARQUEE_PROGRESS_BAR        = %WM_USER+103  ' // wParam = 0 (nonMarque) wParam != 0 (Marquee)
%TDM_SET_PROGRESS_BAR_STATE          = %WM_USER+104  ' // wParam = new progress state
%TDM_SET_PROGRESS_BAR_RANGE          = %WM_USER+105  ' // lParam = MAKELPARAM(nMinRange nMaxRange)
%TDM_SET_PROGRESS_BAR_POS            = %WM_USER+106  ' // wParam = new position
%TDM_SET_PROGRESS_BAR_MARQUEE        = %WM_USER+107  ' // wParam = 0 (stop marquee) wParam != 0 (start marquee) lparam = speed (milliseconds between repaints)
%TDM_SET_ELEMENT_TEXT                = %WM_USER+108  ' // wParam = element (TASKDIALOG_ELEMENTS) lParam = new element text (LPCWSTR)
%TDM_CLICK_RADIO_BUTTON              = %WM_USER+110  ' // wParam = Radio Button ID
%TDM_ENABLE_BUTTON                   = %WM_USER+111  ' // lParam = 0 (disable) lParam != 0 (enable) wParam = Button ID
%TDM_ENABLE_RADIO_BUTTON             = %WM_USER+112  ' // lParam = 0 (disable) lParam != 0 (enable) wParam = Radio Button ID
%TDM_CLICK_VERIFICATION              = %WM_USER+113  ' // wParam = 0 (unchecked) 1 (checked) lParam = 1 (set key focus)
%TDM_UPDATE_ELEMENT_TEXT             = %WM_USER+114  ' // wParam = element (TASKDIALOG_ELEMENTS) lParam = new element text (LPCWSTR)
%TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE = %WM_USER+115  ' // wParam = Button ID lParam = 0 (elevation not required) lParam != 0 (elevation required)
%TDM_UPDATE_ICON                     = %WM_USER+116   ' // wParam = icon element (TASKDIALOG_ICON_ELEMENTS) lParam = new icon (hIcon if TDF_USE_HICON_* was set PCWSTR otherwise)

' enum TASKDIALOG_NOTIFICATIONS
%TDN_CREATED                         = 0
%TDN_NAVIGATED                       = 1
%TDN_BUTTON_CLICKED                  = 2            ' // wParam = Button ID
%TDN_HYPERLINK_CLICKED               = 3            ' // lParam = (LPCWSTR)pszHREF
%TDN_TIMER                           = 4            ' // wParam = Milliseconds since dialog created or timer reset
%TDN_DESTROYED                       = 5
%TDN_RADIO_BUTTON_CLICKED            = 6            ' // wParam = Radio Button ID
%TDN_DIALOG_CONSTRUCTED              = 7
%TDN_VERIFICATION_CLICKED            = 8             ' // wParam = 1 if checkbox checked 0 if not lParam is unused and always 0
%TDN_HELP                            = 9
%TDN_EXPANDO_BUTTON_CLICKED          = 10            ' // wParam = 0 (dialog is now collapsed) wParam != 0 (dialog is now expanded)

' // Size = 8 bytes
TYPE TASKDIALOG_BUTTON DWORD
   nButtonID     AS LONG           ' int
   pszButtonText AS WSTRINGZ PTR   ' PCWSTR
END TYPE

' enum TASKDIALOG_ELEMENTS
%TDE_CONTENT              = 0
%TDE_EXPANDED_INFORMATION = 1
%TDE_FOOTER               = 2
%TDE_MAIN_INSTRUCTION     = 3

' enum TASKDIALOG_ICON_ELEMENTS
%TDIE_ICON_MAIN   = 0
%TDIE_ICON_FOOTER = 1

'#define TD_WARNING_ICON         MAKEINTRESOURCEW(-1)
'#define TD_ERROR_ICON           MAKEINTRESOURCEW(-2)
'#define TD_INFORMATION_ICON     MAKEINTRESOURCEW(-3)
'#define TD_SHIELD_ICON          MAKEINTRESOURCEW(-4)

' // Note: The following constants MUST BE WORDs
%TD_WARNING_ICON         = &HFFFF??
%TD_ERROR_ICON           = &HFFFE??
%TD_INFORMATION_ICON     = &HFFFD??
%TD_SHIELD_ICON          = &HFFFC??

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' enum TASKDIALOG_COMMON_BUTTON_FLAGS
%TDCBF_OK_BUTTON            = &H0001??? ' // selected control return value IDOK
%TDCBF_YES_BUTTON           = &H0002??? ' // selected control return value IDYES
%TDCBF_NO_BUTTON            = &H0004??? ' // selected control return value IDNO
%TDCBF_CANCEL_BUTTON        = &H0008??? ' // selected control return value IDCANCEL
%TDCBF_RETRY_BUTTON         = &H0010??? ' // selected control return value IDRETRY
%TDCBF_CLOSE_BUTTON         = &H0020???  ' // selected control return value IDCLOSE

'typedef int TASKDIALOG_COMMON_BUTTON_FLAGS;           // Note: _TASKDIALOG_COMMON_BUTTON_FLAGS is an int

'typedef struct _TASKDIALOGCONFIG
'{
'    UINT        cbSize;
'    HWND        hwndParent;
'    HINSTANCE   hInstance;                              // used for MAKEINTRESOURCE() strings
'    TASKDIALOG_FLAGS                dwFlags;            // TASKDIALOG_FLAGS (TDF_XXX) flags
'    TASKDIALOG_COMMON_BUTTON_FLAGS  dwCommonButtons;    // TASKDIALOG_COMMON_BUTTON (TDCBF_XXX) flags
'    PCWSTR      pszWindowTitle;                         // string or MAKEINTRESOURCE()
'    union
'    {
'        HICON   hMainIcon;
'        PCWSTR  pszMainIcon;
'    } DUMMYUNIONNAME;
'    PCWSTR      pszMainInstruction;
'    PCWSTR      pszContent;
'    UINT        cButtons;
'    const TASKDIALOG_BUTTON  *pButtons;
'    int         nDefaultButton;
'    UINT        cRadioButtons;
'    const TASKDIALOG_BUTTON  *pRadioButtons;
'    int         nDefaultRadioButton;
'    PCWSTR      pszVerificationText;
'    PCWSTR      pszExpandedInformation;
'    PCWSTR      pszExpandedControlText;
'    PCWSTR      pszCollapsedControlText;
'    union
'    {
'        HICON   hFooterIcon;
'        PCWSTR  pszFooterIcon;
'    } DUMMYUNIONNAME2;
'    PCWSTR      pszFooter;
'    PFTASKDIALOGCALLBACK pfCallback;
'    LONG_PTR    lpCallbackData;
'    UINT        cxWidth;                                // width of the Task Dialog's client area in DLU's. If 0, Task Dialog will calculate the ideal width.
'} TASKDIALOGCONFIG;

' // Size = 4 bytes
UNION TASKDIALOGCONFIG_UNION_1 DWORD
   hMainIcon   AS DWORD          ' HICON
   pszMainIcon AS WSTRINGZ PTR   ' PCWSTR
END UNION

' // Size = 4 bytes
UNION TASKDIALOGCONFIG_UNION_2 DWORD
   hFooterIcon   AS DWORD          ' HICON
   pszFooterIcon AS WSTRINGZ PTR   ' PCWSTR
END UNION

' // Size = 96 bytes
TYPE TASKDIALOGCONFIG DWORD
   cbSize                   AS DWORD                   ' UINT
   hwndParent               AS DWORD                   ' HWND
   hInstance                AS DWORD                   ' HINSTANCE // used for MAKEINTRESOURCE() strings
   dwFlags                  AS LONG                    ' TASKDIALOG_FLAGS // TASKDIALOG_FLAGS (TDF_XXX) flags
   dwCommonButtons          AS LONG                    ' TASKDIALOG_COMMON_BUTTON_FLAGS // TASKDIALOG_COMMON_BUTTON (TDCBF_XXX) flags
   pszWindowTitle           AS WSTRINGZ PTR            ' PCWSTR // string or MAKEINTRESOURCE()
   TASKDIALOGCONFIG_UNION_1
   pszMainInstruction       AS WSTRINGZ PTR            ' PCWSTR
   pszContent               AS WSTRINGZ PTR            ' PCWSTR
   cButtons                 AS DWORD                   ' UINT
   pButtons                 AS TASKDIALOG_BUTTON PTR   ' const TASKDIALOG_BUTTON*
   nDefaultButton           AS LONG                    ' int
   cRadioButtons            AS DWORD                   ' UINT
   pRadioButtons            AS TASKDIALOG_BUTTON PTR   ' const TASKDIALOG_BUTTON*
   nDefaultRadioButton      AS LONG                    ' int
   pszVerificationText      AS WSTRINGZ PTR            ' PCWSTR
   pszExpandedInformation   AS WSTRINGZ PTR            ' PCWSTR
   pszExpandedControlText   AS WSTRINGZ PTR            ' PCWSTR
   pszCollapsedControlText  AS WSTRINGZ PTR            ' PCWSTR
   TASKDIALOGCONFIG_UNION_2
   pszFooter                AS WSTRINGZ PTR            ' PCWSTR
   pfCallback               AS DWORD                   ' PFTASKDIALOGCALLBACK
   lpCallbackData           AS DWORD                   ' LONG_PTR
   cxWidth                  AS DWORD                   ' UINT // width of the Task Dialog's client area in DLU's. If 0, Task Dialog will calculate the ideal width.
END TYPE

DECLARE FUNCTION TaskDialogIndirect IMPORT "COMCTL32.DLL" ALIAS "TaskDialogIndirect" ( _
   BYREF pTaskConfig AS TASKDIALOGCONFIG _              ' __in  const TASKDIALOGCONFIG *pTaskConfig
 , BYREF pnButton AS LONG _                             ' __out int *pnButton
 , BYREF pnRadioButton AS LONG _                        ' __out int *pnRadioButton
 , BYREF pfVerificationFlagChecked AS LONG _            ' __out BOOL *pfVerificationFlagChecked
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TaskDialog IMPORT "COMCTL32.DLL" ALIAS "TaskDialog" ( _
   BYVAL hWndParent AS DWORD _                          ' __in  HWND hWndParent
 , BYVAL hInstance AS DWORD _                           ' __in  HINSTANCE hInstance
 , BYREF pszWindowTitle AS WSTRINGZ _                   ' __in  PCWSTR pszWindowTitle
 , BYREF pszMainInstruction AS WSTRINGZ _               ' __in  PCWSTR pszMainInstruction
 , BYREF pszContent AS WSTRINGZ _                       ' __in  PCWSTR pszContent
 , BYVAL dwCommonButtons AS LONG _                      ' __in  TASKDIALOG_COMMON_BUTTON_FLAGS dwCommonButtons
 , BYREF pszIcon AS WSTRINGZ _                          ' __in  PCWSTR pszIcon
 , BYREF pnButton AS LONG _                             ' __out int *pnButton
 ) AS LONG                                              ' HRESULT

'#ifdef _WIN32
'#include <poppack.h>
'#endif

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
#ENDIF   ' // NOTASKDIALOG

'// ==================== End TaskDialog =======================

'//
'// === MUI APIs ===
'//
#IF NOT %DEF(%NOMUI)

DECLARE SUB InitMUILanguage IMPORT "COMCTL32.DLL" ALIAS "InitMUILanguage" ( _
   BYVAL uiLang AS WORD _                               ' __in LANGID uiLang
 )                                                      ' void

DECLARE FUNCTION GetMUILanguage IMPORT "COMCTL32.DLL" ALIAS "GetMUILanguage" ( _
 ) AS WORD                                              ' LANGID

#ENDIF  ' // NOMUI

'#endif      // _WIN32_IE >= 0x0400

#IF NOT %DEF(%NO_COMMCTRL_DA)
    %COMMCTRL_DA_DEFINED = 1
'//
'//====== Dynamic Array routines ==========================================
'//
'// Note that the STL and other libraries have similar functionality.
'// The routines here are specific to Windows and may not be as convenient
'// or fully functional as those in other libraries.
'//

%DA_LAST         = &H7FFFFFFF
%DA_ERR          = -1

'// Dynamic structure array
'typedef struct _DSA *HDSA;

'typedef int (CALLBACK *PFNDAENUMCALLBACK)(__in_opt void *p, __in_opt void *pData);
'FUNCTION DPAENUMCALLBACK (BYVAL p AS DWORD, BYVAL pData AS DWORD) AS LONG
'typedef int (CALLBACK *PFNDAENUMCALLBACKCONST)(__in_opt const void *p, __in_opt void *pData);
'FUNCTION DSAENUMCALLBACK (BYVAL p AS DWORD, BYVAL pData AS DWORD) AS LONG
'typedef int (CALLBACK *PFNDACOMPARE)(__in_opt void *p1, __in_opt void *p2, __in LPARAM lParam);
'FUNCTION DACOMPARE (BYVAL p1 AS DWORD, BYVAL p2 AS DWORD, BYVAL lParam AS LONG) AS LONG
'typedef int (CALLBACK *PFNDACOMPARECONST)(__in_opt const void *p1, __in_opt const void *p2, __in LPARAM lParam);
'FUNCTION DACOMPARECONST (BYVAL p1 AS DWORD, BYVAL p2 AS DWORD, BYVAL lParam AS LONG) AS LONG

'// Dynamic structure array
'struct _DSA;
'typedef struct _DSA *HDSA;

' Ordinal 320
DECLARE FUNCTION DSA_Create IMPORT "COMCTL32.DLL" ALIAS "DSA_Create" ( _
   BYVAL cbItem AS LONG _                               ' __in int cbItem
 , BYVAL cItemGrow AS LONG _                            ' __in int cItemGrow
 ) AS DWORD                                             ' HDSA

' Ordinal 321
DECLARE FUNCTION DSA_Destroy IMPORT "COMCTL32.DLL" ALIAS "DSA_Destroy" ( _
   BYVAL hdsa AS DWORD _                                ' __inout_opt HDSA hdsa
 ) AS LONG                                              ' BOOL

' Ordinal 388
DECLARE SUB DSA_DestroyCallback IMPORT "COMCTL32.DLL" ALIAS "DSA_DestroyCallback" ( _
   BYVAL hdsa AS DWORD _                                ' __inout_opt HDSA hdsa
 , BYVAL pfnCB AS DWORD _                               ' __in PFNDSAENUMCALLBACK pfnCB
 , OPTIONAL BYREF pData AS ANY _                        ' __in_opt void *pData
 )                                                      ' void

' DSA_DeleteItem is not exported by name or declared in a public header file.
' To use it, you must use GetProcAddress and request ordinal 326 from ComCtl32.dll
' to obtain a function pointer.
FUNCTION DSA_DeleteItem (BYVAL hdsa AS DWORD, BYVAL nPosition AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 326, 0))
   IF pProc THEN CALL DWORD pProc USING DSA_DeleteItem(hdsa, nPosition) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

DECLARE FUNCTION DSA_DeleteAllItems IMPORT "COMCTL32.DLL" ALIAS "DSA_DeleteAllItems" ( _
   BYVAL hdsa AS DWORD _                                ' __inout HDSA hdsa
 ) AS LONG                                              ' BOOL

DECLARE SUB DSA_EnumCallback IMPORT "COMCTL32.DLL" ALIAS "DSA_EnumCallback" ( _
   BYVAL hdsa AS DWORD _                                ' __in HDSA hdsa
 , BYVAL pfnCB AS DWORD _                               ' __in PFNDAENUMCALLBACK *pfnCB
 , BYREF pData AS ANY _                                 ' __in void *pData
 )                                                      ' void

' Ordinal 324
DECLARE FUNCTION DSA_InsertItem IMPORT "COMCTL32.DLL" ALIAS "DSA_InsertItem" ( _
   BYVAL pdsa AS DWORD _                                ' __inout HDSA pdsa
 , BYVAL index AS LONG _                                ' __in int index
 , BYREF pItem AS ANY _                                 ' __in void *pItem
 ) AS LONG                                              ' BOOL

' Ordinal 323
DECLARE FUNCTION DSA_GetItemPtr IMPORT "COMCTL32.DLL" ALIAS "DSA_GetItemPtr" ( _
   BYVAL hdsa AS DWORD _                                ' __in HDSA hdsa
 , BYVAL i AS LONG _                                    ' __in int i
 ) AS DWORD                                             ' PVOID

' DSA_GetItem is not exported by name. To use it, you must use GetProcAddress
' and request ordinal 322 from ComCtl32.dll to obtain a function pointer.
FUNCTION DSA_GetItem (BYVAL hdsa AS DWORD, BYVAL index AS LONG, BYVAL pitem AS DWORD) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 322, 0))
   IF pProc THEN CALL DWORD pProc USING DSA_GetItem(hdsa, index, pitem) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

' DSA_SetItem is not exported by name or declared in a public header file. To use it,
' you must use GetProcAddress and request ordinal 325 from ComCtl32.dll to obtain a function pointer.
FUNCTION DSA_SetItem (BYVAL hdsa AS DWORD, BYVAL index AS LONG, BYVAL pitem AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 325, 0))
   IF pProc THEN CALL DWORD pProc USING DSA_SetItem(hdsa, index, pitem) TO hr
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

'#define DSA_GetItemCount(hdsa)      (*(int *)(hdsa))
MACRO DSA_GetItemCount(hdsa) = PEEK(LONG, hdsa)

'#define DSA_AppendItem(hdsa, pitem) DSA_InsertItem(hdsa, DA_LAST, pitem)

MACRO DSA_AppendItem(hdsa, pitem) = DSA_InsertItem(hdsa, %DA_LAST, pitem)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

DECLARE FUNCTION DSA_Clone IMPORT "COMCTL32.DLL" ALIAS "DSA_Clone" ( _
   BYVAL hdsa AS DWORD _                                ' __in HDSA hdsa
 ) AS DWORD                                             ' HDSA

DECLARE FUNCTION DSA_GetSize IMPORT "COMCTL32.DLL" ALIAS "DSA_GetSize" ( _
   OPTIONAL BYVAL hdsa AS DWORD _                       ' __in_opt HDSA hdsa
 ) AS QUAD                                              ' ULONGLONG

DECLARE FUNCTION DSA_Sort IMPORT "COMCTL32.DLL" ALIAS "DSA_Sort" ( _
   BYVAL pdsa AS DWORD _                                ' __inout HDSA pdsa
 , BYVAL pfnCompare AS DWORD _                          ' __in PFNDACOMPARE pfnCompare
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' BOOL

'#endif  // NTDDI_VISTA

%DSA_APPEND      = %DA_LAST
%DSA_ERR         = %DA_ERR

'// Dynamic pointer array
'typedef struct _DPA *HDPA;

' Ordinal 328
DECLARE FUNCTION DPA_Create IMPORT "COMCTL32.DLL" ALIAS "DPA_Create" ( _
   BYVAL cItemGrow AS LONG _                            ' __in int cItemGrow
 ) AS DWORD                                             ' HDPA

' DPA_CreateEx is not exported by name. To use it, you must use GetProcAddress
' and request ordinal 340 from ComCtl32.dll to obtain a function pointer.
FUNCTION DPA_CreateEx (BYVAL cpGrow AS DWORD, OPTIONAL BYVAL hheap AS DWORD) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 340, 0))
   IF pProc THEN CALL DWORD pProc USING DPA_CreateEx(cpGrow, hheap) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

' DPA_Clone is not exported by name or declared in a public header file. To use it,
' you must use GetProcAddress and request ordinal 331 from ComCtl32.dll to obtain a function pointer.
FUNCTION DPA_Clone (BYVAL hdpa AS DWORD, OPTIONAL BYVAL hdpaNew AS DWORD) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 331, 0))
   IF pProc THEN CALL DWORD pProc USING DPA_Clone(hdpa, hdpaNew) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

' Ordinal 329
DECLARE FUNCTION DPA_Destroy IMPORT "COMCTL32.DLL" ALIAS "DPA_Destroy" ( _
   BYVAL hdpa AS DWORD _                                ' __in HDPA hdpa
 ) AS LONG                                              ' BOOL

' Ordinal 386
DECLARE SUB DPA_DestroyCallback IMPORT "COMCTL32.DLL" ALIAS "DPA_DestroyCallback" ( _
   BYVAL hdpa AS DWORD _                                ' __in HDPA hdpa
 , BYVAL pfnCB AS DWORD _                               ' __in PFNDPAENUMCALLBACK pfnCB
 , BYREF pData AS ANY _                                 ' __in void *pData
 )                                                      ' void

' Ordinal 336
DECLARE FUNCTION DPA_DeletePtr IMPORT "COMCTL32.DLL" ALIAS "DPA_DeletePtr" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 , BYVAL i AS LONG _                                    ' __in int i
 ) AS DWORD                                             ' PVOID

' Ordinal 337
DECLARE FUNCTION DPA_DeleteAllPtrs IMPORT "COMCTL32.DLL" ALIAS "DPA_DeleteAllPtrs" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 ) AS LONG                                              ' BOOL

' Ordinal 385
DECLARE SUB DPA_EnumCallback IMPORT "COMCTL32.DLL" ALIAS "DPA_EnumCallback" ( _
   BYVAL hdpa AS DWORD _                                ' __in_opt HDPA hdpa
 , BYVAL pfnCB AS DWORD _                               ' __in PFNDPAENUMCALLBACK pfnCB
 , BYREF pData AS ANY _                                 ' __in void *pData
 )                                                      ' void

DECLARE FUNCTION DPA_Grow IMPORT "COMCTL32.DLL" ALIAS "DPA_Grow" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 , BYVAL cp AS LONG _                                   ' __in int cp
 ) AS LONG                                              ' BOOL

' Ordinal 334
DECLARE FUNCTION DPA_InsertPtr IMPORT "COMCTL32.DLL" ALIAS "DPA_InsertPtr" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 , BYVAL i AS LONG _                                    ' __in int i
 , BYREF p AS ANY _                                     ' __in void *p
 ) AS LONG                                              ' int

' Ordinal 335
DECLARE FUNCTION DPA_SetPtr IMPORT "COMCTL32.DLL" ALIAS "DPA_SetPtr" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 , BYVAL i AS LONG _                                    ' __in int i
 , BYREF p AS ANY _                                     ' __in void *p
 ) AS LONG                                              ' BOOL

' Ordinal 332
DECLARE FUNCTION DPA_GetPtr IMPORT "COMCTL32.DLL" ALIAS "DPA_GetPtr" ( _
   BYVAL hdpa AS DWORD _                                ' __in HDPA hdpa
 , BYVAL i AS LONG _                                    ' __in int i
 ) AS DWORD                                             ' PVOID

' DPA_GetPtrIndex is not exported by name or declared in a public header file. To use it,
' you must use GetProcAddress and request ordinal 333 from ComCtl32.dll to obtain a function pointer.
FUNCTION DPA_GetPtrIndex (BYVAL hdpa AS DWORD, BYVAL pvoid AS DWORD) AS LONG

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 333, 0))
   IF pProc THEN CALL DWORD pProc USING DPA_GetPtrIndex(hdpa, pvoid) TO hr
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

'#define DPA_GetPtrCount(hdpa)       (*(int *)(hdpa))
MACRO DPA_GetPtrCount(hdpa) = PEEK(LONG, hdpa)

'#define DPA_SetPtrCount(hdpa, cItems) (*(int *)(hdpa) = (cItems))
FUNCTION DPA_SetPtrCount (BYVAL hdpa AS DWORD, BYVAL cItems AS LONG) AS LONG
   POKE LONG, hdpa, cItems
   FUNCTION = cItems
END FUNCTION

'#define DPA_FastDeleteLastPtr(hdpa) (--*(int *)(hdpa))
SUB DPA_FastDeleteLastPtr (BYVAL hdpa AS LONG PTR)
   DECR @hdpa
END SUB

'#define DPA_GetPtrPtr(hdpa)         (*((void * **)((BYTE *)(hdpa) + sizeof(void *))))
'#define DPA_FastGetPtr(hdpa, i)     (DPA_GetPtrPtr(hdpa)[i])
'#define DPA_AppendPtr(hdpa, pitem)  DPA_InsertPtr(hdpa, DA_LAST, pitem)

MACRO DPA_AppendPtr(hdpa, pitem) = DPA_InsertPtr(hdpa, %DA_LAST, pitem)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION DPA_GetSize IMPORT "COMCTL32.DLL" ALIAS "DPA_GetSize" ( _
   OPTIONAL BYVAL hdpa AS DWORD _                       ' __in_opt HDPA hdpa
 ) AS QUAD                                              ' ULONGLONG
'#endif  // NTDDI_VISTA

'typedef int (CALLBACK *PFNDPACOMPARE)(void *p1, void *p2, LPARAM lParam);
'FUNCTION DPACOMPARE (BYVAL p1 AS DWORD, BYVAL p2 AS DWORD, BYVAL lParam AS LONG) AS LONG

' Ordinal 338
DECLARE FUNCTION DPA_Sort IMPORT "COMCTL32.DLL" ALIAS "DPA_Sort" ( _
   BYVAL hdpa AS DWORD _                                ' __inout HDPA hdpa
 , BYVAL pfnCompare AS DWORD _                          ' __in PFNDPACOMPARE pfnCompare
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
  ) AS LONG                                             ' BOOL

'//
'// Save to and load from a stream.  The stream callback gets a pointer to
'// a DPASTREAMINFO structure.
'//
'// For DPA_SaveStream, the callback is responsible for writing the pvItem
'// info to the stream.  (It's not necessary to write the iPos to the
'// stream.)  Return S_OK if the element was saved, S_FALSE if it wasn't
'// but continue anyway, or some failure.
'//
'// For DPA_LoadStream, the callback is responsible for allocating an
'// item and setting the pvItem field to the new pointer.  Return S_OK
'// if the element was loaded, S_FALSE it it wasn't but continue anyway,
'// or some failure.
'//

' // Size = 8 bytes
TYPE DPASTREAMINFO DWORD
   iPos   AS LONG    ' int // Index of item
   pvItem AS DWORD   ' void*
END TYPE

'struct IStream;
#IF %DEF(%IStream_INTERFACE_DEFINED)

'typedef HRESULT (CALLBACK *PFNDPASTREAM)(__in DPASTREAMINFO * pinfo, __in struct IStream * pstream, __in_opt void *pvInstData);
'FUNCTION PFNDPASTREAM (BYREF pinfo AS DPASTREAMINFO, BYVAL pstream AS IStream, BYVAL pvInstData AS DWORD) AS LONG

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DPA_LoadStream LIB "ComCtl32.dll" ALIAS "DPA_LoadStream" ( _
    phdpa AS DWORD, BYVAL pfn AS DWORD, pstream AS ANY, pvInstData AS ANY) _
    AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION DPA_LoadStream IMPORT "COMCTL32.DLL" ALIAS "DPA_LoadStream" ( _
   BYREF phdpa AS DWORD _                               ' __out HDPA * phdpa
 , BYVAL pfn AS DWORD _                                 ' __in PFNDPASTREAM pfn
 , BYVAL pstream AS IStream _                           ' __in struct IStream * pstream
 , OPTIONAL BYVAL pvInstData AS DWORD _                 ' __in_opt void *pvInstData
  ) AS LONG                                             ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DPA_SaveStream LIB "ComCtl32.dll" ALIAS "DPA_SaveStream" ( _
    BYVAL hdpa AS DWORD, BYVAL pfn AS DWORD, pstream AS ANY, _
    pvInstData AS ANY) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION DPA_SaveStream IMPORT "COMCTL32.DLL" ALIAS "DPA_SaveStream" ( _
   BYVAL hdpa AS DWORD _                                ' __in HDPA hdpa
 , BYVAL pfn AS DWORD _                                 ' __in PFNDPASTREAM pfn
 , BYVAL pstream AS IStream _                           ' __in struct IStream * pstream
 , OPTIONAL BYVAL pvInstData AS DWORD _                 ' __in_opt void *pvInstData
  ) AS LONG                                             ' HRESULT
#ENDIF

#ENDIF   ' #IF %DEF(%IStream_INTERFACE_DEFINED)

'// Merge two DPAs.  This takes two (optionally) presorted arrays and merges
'// the source array into the dest.  DPA_Merge uses the provided callbacks
'// to perform comparison and merge operations.  The merge callback is
'// called when two elements (one in each list) match according to the
'// compare function.  This allows portions of an element in one list to
'// be merged with the respective element in the second list.
'//
'// The first DPA (hdpaDest) is the output array.
'//
'// Merge options:
'//
'//    DPAM_SORTED       The arrays are already sorted; don't sort
'//    DPAM_UNION        The resulting array is the union of all elements
'//                      in both arrays (DPAMM_INSERT may be sent for
'//                      this merge option.)
'//    DPAM_INTERSECT    Only elements in the source array that intersect
'//                      with the dest array are merged.  (DPAMM_DELETE
'//                      may be sent for this merge option.)
'//    DPAM_NORMAL       Like DPAM_INTERSECT except the dest array
'//                      also maintains its original, additional elements.
'//

%DPAM_SORTED             = &H00000001???
%DPAM_NORMAL             = &H00000002???
%DPAM_UNION              = &H00000004???
%DPAM_INTERSECT          = &H00000008???

'// The merge callback should merge contents of the two items and return
'// the pointer of the merged item.  It's okay to simply use pvDest
'// as the returned pointer.
'//

'typedef void* (CALLBACK *PFNDPAMERGE)(__in UINT uMsg, __in void *pvDest, __in void *pvSrc, __in LPARAM lParam);
'FUNCTION PFNDPAMERGE (BYVAL uMsg AS DWORD, BYVAL pvDest AS DWORD, BYVAL pvSrc AS DWORD, BYVAL lParam AS LONG) AS DWORD

'typedef const void* (CALLBACK *PFNDPAMERGECONST)(__in UINT uMsg, __in const void *pvDest, __in const void *pvSrc, __in LPARAM lParam);
'FUNCTION PFNDPAMERGECONST (BYVAL uMsg AS DWORD, BYVAL pvDest AS DWORD, BYVAL pvSrc AS DWORD, BYVAL lParam AS LONG) AS DWORD

'// Messages for merge callback
%DPAMM_MERGE    = 1
%DPAMM_DELETE   = 2
%DPAMM_INSERT   = 3

' DPA_Merge is not exported by name or declared in a public header file. To use it,
' you must use GetProcAddress and request ordinal 11 from ComCtl32.dll to obtain a function pointer.
FUNCTION DPA_Merge (BYVAL hdpaDest AS DWORD, BYVAL hdpaSrc AS DWORD, BYVAL dwFlags AS DWORD, _
   BYVAL pfnCompare AS DWORD, BYVAL pfnMerge AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("COMCTL32.DLL")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 11, 0))
   IF pProc THEN CALL DWORD pProc USING DPA_Merge(hdpaDest, hdpaSrc, dwFlags, pfnCompare, pfnMerge, lParam) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'// Search array.  If DPAS_SORTED, then array is assumed to be sorted
'// according to pfnCompare, and binary search algorithm is used.
'// Otherwise, linear search is used.
'//
'// Searching starts at iStart (0 to start search at beginning).
'//
'// DPAS_INSERTBEFORE/AFTER govern what happens if an exact match is not
'// found.  If neither are specified, this function returns -1 if no exact
'// match is found.  Otherwise, the index of the item before or after the
'// closest (including exact) match is returned.
'//
'// Search option flags
'//
%DPAS_SORTED             = &H0001???
%DPAS_INSERTBEFORE       = &H0002???
%DPAS_INSERTAFTER        = &H0004???

' Ordinal 339
DECLARE FUNCTION DPA_Search IMPORT "COMCTL32.DLL" ALIAS "DPA_Search" ( _
   BYVAL hdpa AS DWORD _                                ' __in HDPA hdpa
 , BYREF pFind AS ANY _                                 ' __in void *pFind
 , BYVAL iStart AS LONG _                               ' __in int iStart
 , BYVAL pfnCompare AS DWORD _                          ' __in PFNDPACOMPARE pfnCompare
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL options AS DWORD _                             ' __in UINT options
 ) AS LONG                                              ' int

MACRO DPA_SortedInsertPtr(hdpa, pFind, iStart, pfnCompare, lParam, options, pitem) = DPA_InsertPtr(hdpa, DPA_Search(hdpa, pFind, iStart, pfnCompare, lParam, (%DPAS_SORTED OR (options))), (pitem))

%DPA_APPEND      = &H7fffffff
%DPA_ERR         = -1

#ENDIF   ' // NO_COMMCTRL_DA

DECLARE FUNCTION Str_SetPtrW IMPORT "COMCTL32.DLL" ALIAS "Str_SetPtrW" ( _
   BYREF ppszCurrent AS ANY _                           ' __inout LPWSTR *ppszCurrent
 , BYREF pszNew AS WSTRINGZ _                           ' __in LPCWSTR pszNew
 ) AS LONG                                              ' int

' The ANSI version of Str_SetPtr, Str_SetPtrA is not exported by name or declared
' in a public header file. To use it, you must use GetProcAddress and request
' ordinal 234 from ComCtl32.dll to obtain a function pointer.

'FUNCTION Str_SetPtrA (BYREF ppsz AS ASCIIZ, BYREF psz AS ASCIIZ) AS LONG

'   LOCAL hr AS LONG
'   LOCAL hLib AS DWORD
'   LOCAL pProc AS DWORD

'   hLib = LoadLibrary("COMCTL32.DLL")
'   IF hLib = %NULL THEN EXIT FUNCTION
'   pProc = GetProcAddress(hLib, BYVAL MAK(LONG, 234, 0))
'   IF pProc THEN CALL DWORD pProc USING Str_SetPtrA(ppsz, psz) TO hr
'   FreeLibrary hLib
'   FUNCTION = hr

'END FUNCTION

'#ifdef _WIN32
'//====== TrackMouseEvent  =====================================================

#IF NOT %DEF(%NOTRACKMOUSEEVENT)

'//
'// If the messages for TrackMouseEvent have not been defined then define them
'// now.
'//
#IF NOT %DEF(%WM_MOUSEHOVER)
%WM_MOUSEHOVER                 = &H02A1???
%WM_MOUSELEAVE                 = &H02A3???
#ENDIF  ' %WM_MOUSEHOVER

'//
'// If the TRACKMOUSEEVENT structure and associated flags havent been declared
'// then declare them now.
'//
'#IF NOT %DEF(%TME_HOVER)

%TME_HOVER      = &H00000001???
%TME_LEAVE      = &H00000002???
#IF (%WINVER >= &H0500)
%TME_NONCLIENT  = &H00000010???
#ENDIF   ' /* WINVER >= 0x0500 */
%TME_QUERY      = &H40000000???
%TME_CANCEL     = &H80000000???

%HOVER_DEFAULT  = &HFFFFFFFF???

#IF NOT %DEF(%TRACKMOUSEEVENT_DEFINED)
%TRACKMOUSEEVENT_DEFINED = 1
' // Size = 16 bytes
TYPE tagTRACKMOUSEEVENT DWORD
   cbSize      AS DWORD
   dwFlags     AS DWORD
   hwndTrack   AS DWORD
   dwHoverTime AS DWORD
END TYPE
' The TRACKMOUSEEVENTAPI name is used in the old PB's win32api.inc instead of tagTRACKMOUSEVENT
MACRO TRACKMOUSEEVENTAPI = tagTRACKMOUSEEVENT
' // For compatibility with the PB includes
MACRO TRACKMOUSEEVENT_type = tagTRACKMOUSEEVENT
' The EVENTTRACK name is used in the old PB's commctrl.inc instead of tagTRACKMOUSEVENT
MACRO EVENTTRACK = tagTRACKMOUSEEVENT
#ENDIF

'#ENDIF   ' // !TME_HOVER

'//
'// Declare _TrackMouseEvent.  This API tries to use the window manager's
'// implementation of TrackMouseEvent if it is present, otherwise it emulates.
'//

'DECLARE FUNCTION TrackMouseEvent _
'   IMPORT "USER32.DLL" ALIAS "TrackMouseEvent" ( _
'   BYREF ANY _                         ' LPTRACKMOUSEEVENT lpEventTrack
'   ) AS LONG                           ' BOOL

#ENDIF  ' // NOTRACKMOUSEEVENT

'#if (_WIN32_IE >= 0x0400)

'//====== Flat Scrollbar APIs=========================================
#IF NOT %DEF(%NOFLATSBAPIS)

%WSB_PROP_CYVSCROLL = &H00000001???
%WSB_PROP_CXHSCROLL = &H00000002???
%WSB_PROP_CYHSCROLL = &H00000004???
%WSB_PROP_CXVSCROLL = &H00000008???
%WSB_PROP_CXHTHUMB  = &H00000010???
%WSB_PROP_CYVTHUMB  = &H00000020???
%WSB_PROP_VBKGCOLOR = &H00000040???
%WSB_PROP_HBKGCOLOR = &H00000080???
%WSB_PROP_VSTYLE    = &H00000100???
%WSB_PROP_HSTYLE    = &H00000200???
%WSB_PROP_WINSTYLE  = &H00000400???
%WSB_PROP_PALETTE   = &H00000800???
%WSB_PROP_MASK      = &H00000FFF???

%FSB_FLAT_MODE    = 2
%FSB_ENCARTA_MODE = 1
%FSB_REGULAR_MODE = 0

DECLARE FUNCTION FlatSB_EnableScrollBar IMPORT "COMCTL32.DLL" ALIAS "FlatSB_EnableScrollBar" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wSBflags AS LONG _                             ' __in int wSBflags
 , BYVAL wArrows AS DWORD _                             ' __in UINT wArrows
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_ShowScrollBar IMPORT "COMCTL32.DLL" ALIAS "FlatSB_ShowScrollBar" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL code AS LONG _                                 ' __in int code
 , BYVAL fShow AS LONG _                                ' __in BOOL fShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_GetScrollRange IMPORT "COMCTL32.DLL" ALIAS "FlatSB_GetScrollRange" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL code AS LONG _                                 ' __in int code
 , BYREF lpMinPos AS LONG _                             ' __in int lpMinPos
 , BYREF lpMaxPos AS LONG _                             ' __in int lpMaxPos
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_GetScrollInfo IMPORT "COMCTL32.DLL" ALIAS "FlatSB_GetScrollInfo" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL fnBar AS LONG _                                ' __in  int fnBar
 , BYREF lpsi AS SCROLLINFO _                           ' __out LPSCROLLINFO lpsi
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_GetScrollPos IMPORT "COMCTL32.DLL" ALIAS "FlatSB_GetScrollPos" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL code AS LONG _                                 ' __in int code
 ) AS LONG                                              ' int

DECLARE FUNCTION FlatSB_GetScrollProp IMPORT "COMCTL32.DLL" ALIAS "FlatSB_GetScrollProp" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL propindex AS LONG _                            ' __in  int propindex
 , BYREF pValue AS LONG _                               ' __out LPINT pValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_GetScrollPropPtr IMPORT "COMCTL32.DLL" ALIAS "FlatSB_GetScrollProp" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL propindex AS LONG _                            ' __in  int propindex
 , BYREF pValue AS LONG _                               ' __out LPINT pValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION FlatSB_SetScrollPos IMPORT "COMCTL32.DLL" ALIAS "FlatSB_SetScrollPos" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL code AS LONG _                                 ' __in int code
 , BYVAL pos AS LONG _                                  ' __in int pos
 , BYVAL fRedraw As LONG _                              ' __in BOOL fRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION FlatSB_SetScrollInfo IMPORT "COMCTL32.DLL" ALIAS "FlatSB_SetScrollInfo" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL code AS LONG _                                 ' __in int code
 , BYREF lpsi AS SCROLLINFO _                           ' __in LPSCROLLINFO lpsi
 , BYVAL fRedraw AS LONG _                              ' __in BOOL fRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION FlatSB_SetScrollRange IMPORT "COMCTL32.DLL" ALIAS "FlatSB_SetScrollRange" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL code AS LONG _                                 ' __in int code
 , BYVAL min AS LONG _                                  ' __in int min
 , BYVAL max AS LONG _                                  ' __in int max
 , BYVAL fRedraw AS LONG _                              ' __in BOOL fRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION FlatSB_SetScrollProp IMPORT "COMCTL32.DLL" ALIAS "FlatSB_SetScrollProp" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL index AS DWORD _                               ' __in UINT index
 , BYVAL newValue AS DWORD _                            ' __in INT_PTR newValue
 , BYVAL fRedraw AS LONG _                              ' __in BOOL fRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION FlatSB_SetScrollPropPtr IMPORT "COMCTL32.DLL" ALIAS "FlatSB_SetScrollProp" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL index AS DWORD _                               ' __in UINT index
 , BYVAL newValue AS DWORD _                            ' __in INT_PTR newValue
 , BYVAL fRedraw AS LONG _                              ' __in BOOL fRedraw
 ) AS LONG                                              ' int

DECLARE FUNCTION InitializeFlatSB IMPORT "COMCTL32.DLL" ALIAS "InitializeFlatSB" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION UninitializeFlatSB IMPORT "COMCTL32.DLL" ALIAS "UninitializeFlatSB" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

#ENDIF   ' //  NOFLATSBAPIS

'#endif      // _WIN32_IE >= 0x0400

'#endif /* _WIN32 */

'#endif      // _WIN32_IE >= 0x0300

'#if (_WIN32_WINNT >= 0x501)
'//
'// subclassing stuff
'//
'typedef LRESULT (CALLBACK *SUBCLASSPROC)(HWND hWnd, UINT uMsg, WPARAM wParam,
'    LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
'FUNCTION SUBCLASSPROC (BYVAL hWnd AS DWORD, BYVAL uMsg AS DWORD, BYVAL wParam AS DWORD, _
'   BYVAL lParam AS LONG, BYVAL uIdSubclass AS DWORD, BYVAL dwRefData AS DWORD) AS LONG

DECLARE FUNCTION SetWindowSubclass IMPORT "COMCTL32.DLL" ALIAS "SetWindowSubclass" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pfnSubclass AS DWORD _                         ' __in SUBCLASSPROC pfnSubclass
 , BYVAL uIdSubclass AS DWORD _                         ' __in UINT_PTR uIdSubclass
 , BYVAL dwRefDat AS DWORD _                            ' __in DWORD_PTR dwRefDat
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWindowSubclass IMPORT "COMCTL32.DLL" ALIAS "GetWindowSubclass" ( _
   BYVAL hWnd AS DWORD _                                ' __in  HWND hWnd
 , BYVAL pfnSubclass AS DWORD _                         ' __in  SUBCLASSPROC pfnSubclass
 , BYVAL uIdSubclass AS DWORD _                         ' __in  UINT_PTR uIdSubclass
 , BYREF pdwRefData AS DWORD _                          ' __out DWORD_PTR *pdwRefData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RemoveWindowSubclass IMPORT "COMCTL32.DLL" ALIAS "RemoveWindowSubclass" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pfnSubclass AS DWORD _                         ' __in SUBCLASSPROC pfnSubclass
 , BYVAL uIdSubclass AS DWORD _                         ' __in UINT_PTR uIdSubclass
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DefSubclassProc IMPORT "COMCTL32.DLL" ALIAS "DefSubclassProc" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' enum LI_METRIC
%LIM_SMALL = 0   ' // corresponds to SM_CXSMICON/SM_CYSMICON
%LIM_LARGE = 1   ' // corresponds to SM_CXICON/SM_CYICON

DECLARE FUNCTION LoadIconMetric IMPORT "COMCTL32.DLL" ALIAS "LoadIconMetric" ( _
   BYVAL hinst AS DWORD _                               ' __in HINSTANCE hinst
 , BYREF pszName AS WSTRINGZ _                          ' __in PCWSTR pszName
 , BYVAL lims AS LONG _                                 ' __in int lims
 , BYREF phico AS DWORD _                               ' __out HICON *phico
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION LoadIconWithScaleDown IMPORT "COMCTL32.DLL" ALIAS "LoadIconWithScaleDown" ( _
   BYVAL hinst AS DWORD _                               ' __in HINSTANCE hinst
 , BYREF pszName AS WSTRINGZ _                          ' __in PCWSTR pszName
 , BYVAL cx AS LONG _                                   ' __in int cx
 , BYVAL cy AS LONG _                                   ' __in int cy
 , BYREF phico AS DWORD _                               ' __out HICON *phico
 ) AS LONG                                              ' HRESULT

'#endif // NTDDI_VISTA

'#if (_WIN32_WINNT >= 0x501)

DECLARE FUNCTION DrawShadowText IMPORT "COMCTL32.DLL" ALIAS "DrawShadowText" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYREF pszText AS WSTRINGZ _                          ' __in LPCWSTR pszText
 , BYVAL cch AS DWORD _                                 ' __in UINT cch
 , BYREF prc AS RECT _                                  ' __in RECT* prc
 , BYVAL dwFLags AS DWORD _                             ' __in DWORD dwFLags
 , BYVAL crText AS DWORD _                              ' __in COLORREF crText
 , BYVAL crShadow AS DWORD _                            ' __in COLORREF crShadow
 , BYVAL ixOffset AS LONG _                             ' __in int ixOffset
 , BYVAL iyOffset AS LONG _                             ' __in int iyOffset
 ) AS LONG                                              ' int

'#endif

#ENDIF   ' // NOUSER
