' ########################################################################################
' Microsoft Windows
' File: MMC.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MMC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "basetsd.inc"
#INCLUDE ONCE "oaidl.inc"

#IF NOT %DEF(%MMC_VER)
%MMC_VER = &H0210
#ENDIF

$CLSID_MMCVersionInfo = GUID$("{D6FEDB1D-CF21-4BD9-AF3B-C5468E9C6684}")
$CLSID_ConsolePower = GUID$("{F0285374-DFF1-11D3-B433-00C04F8ECD78}")

%MMCLV_AUTO                   = -1
%MMCLV_NOPARAM                = -2
%MMCLV_NOICON                 = -1
%MMCLV_VIEWSTYLE_ICON         = 0
%MMCLV_VIEWSTYLE_SMALLICON    = &H2
%MMCLV_VIEWSTYLE_LIST         = &H3
%MMCLV_VIEWSTYLE_REPORT       = &H1
%MMCLV_VIEWSTYLE_FILTERED     = &H4
%MMCLV_NOPTR                  = 0
%MMCLV_UPDATE_NOINVALIDATEALL = &H1
%MMCLV_UPDATE_NOSCROLL        = &H2

'static LPOLESTR MMC_CALLBACK   =   ( LPOLESTR  )-1;

%MMC_IMAGECALLBACK = -1
'#define MMC_TEXTCALLBACK  MMC_CALLBACK

'typedef LONG_PTR HSCOPEITEM;
'typedef long COMPONENTID;
'typedef LONG_PTR HRESULTITEM;

%RDI_STR    = &H2
%RDI_IMAGE  = &H4
%RDI_STATE  = &H8
%RDI_PARAM  = &H10
%RDI_INDEX  = &H20
%RDI_INDENT = &H40

' enum MMC_RESULT_VIEW_STYLE
%MMC_SINGLESEL          = &H0001???
%MMC_SHOWSELALWAYS      = &H0002???
%MMC_NOSORTHEADER       = &H0004???
%MMC_ENSUREFOCUSVISIBLE = &H0008???

%MMC_VIEW_OPTIONS_NONE                          = 0
%MMC_VIEW_OPTIONS_NOLISTVIEWS                   = &H1
%MMC_VIEW_OPTIONS_MULTISELECT                   = &H2
%MMC_VIEW_OPTIONS_OWNERDATALIST                 = &H4
%MMC_VIEW_OPTIONS_FILTERED                      = &H8
%MMC_VIEW_OPTIONS_CREATENEW                     = &H10
%MMC_VIEW_OPTIONS_USEFONTLINKING                = &H20
%MMC_VIEW_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST = &H40
%MMC_VIEW_OPTIONS_LEXICAL_SORT                  = &H80
%MMC_PSO_NOAPPLYNOW                             = &H1
%MMC_PSO_HASHELP                                = &H2
%MMC_PSO_NEWWIZARDTYPE                          = &H4
%MMC_PSO_NO_PROPTITLE                           = &H8

' enum MMC_CONTROL_TYPE
%MMC_CONTROL_TYPE_TOOLBAR    = 0
%MMC_CONTROL_TYPE_MENUBUTTON = %MMC_CONTROL_TYPE_TOOLBAR    + 1
%MMC_CONTROL_TYPE_OMBOBOXBAR = %MMC_CONTROL_TYPE_MENUBUTTON + 1

' enum MMC_CONSOLE_VERB
%MMC_VERB_NONE            = &H0000???
%MMC_VERB_OPEN            = &H8000???
%MMC_VERB_COPY            = &H8001???
%MMC_VERB_PASTE           = &H8002???
%MMC_VERB_DELETE          = &H8003???
%MMC_VERB_PROPERTIES      = &H8004???
%MMC_VERB_RENAME          = &H8005???
%MMC_VERB_REFRESH         = &H8006???
%MMC_VERB_PRINT           = &H8007???
%MMC_VERB_CUT             = &H8008???   ' // Used only to explicitly disable/hide
                                        ' // the cut verb, when copy & paste are enabled.

' // must be last
%MMC_VERB_MAX             = &H8009???
%MMC_VERB_FIRST           = %MMC_VERB_OPEN
%MMC_VERB_LAST            = %MMC_VERB_MAX - 1

'#include <pshpack8.h>
' // Size = 20 bytes
TYPE MMCBUTTON DWORD FILL
   nBitmap       AS LONG           ' int
   idCommand     AS LONG           ' int
   fsState       AS BYTE           ' BYTE
   fsType        AS BYTE           ' BYTE
   lpButtonText  AS WSTRINGZ PTR   ' LPOLESTR
   lpTooltipText AS WSTRINGZ PTR   ' LPOLESTR
END TYPE
'#include <poppack.h>

' enum MMC_BUTTON_STATE
%MMC_BUTTON_STATE_ENABLED       = &H1
%MMC_BUTTON_STATE_CHECKED       = &H2
%MMC_BUTTON_STATE_HIDDEN        = &H4
%MMC_BUTTON_STATE_INDETERMINATE = &H8
%MMC_BUTTON_STATE_BUTTONPRESSED = &H10

' // Size = 40 bytes
TYPE RESULTDATAITEM DWORD
   mask       AS DWORD          ' DWORD
   bScopeItem AS LONG           ' BOOL
   itemID     AS LONG           ' HRESULTITEM
   nIndex     AS LONG           ' int
   nCol       AS LONG           ' int
   str        AS WSTRINGZ PTR   ' LPOLESTR
   nImage     AS LONG           ' int
   nState     AS DWORD          ' UINT
   lParam     AS LONG           ' LPARAM
   iIndent    AS LONG           ' int
END TYPE

%RFI_PARTIAL = &H1
%RFI_WRAP    = &H2

' // Size = 12 bytes
TYPE RESULTFINDINFO DWORD
   psz       AS WSTRINGZ PTR   ' LPOLESTR
   nStart    AS LONG           ' int
   dwOptions AS DWORD          ' DWORD
END TYPE

%RSI_DESCENDING = &H1
%RSI_NOSORTICON = &H2

%SDI_STR        = &H2
%SDI_IMAGE      = &H4
%SDI_OPENIMAGE  = &H8
%SDI_STATE      = &H10
%SDI_PARAM      = &H20
%SDI_CHILDREN   = &H40
%SDI_PARENT     = 0
%SDI_PREVIOUS   = &H10000000???
%SDI_NEXT       = &H20000000???
%SDI_FIRST      = &H8000000???

' // Size = 36 bytes
TYPE SCOPEDATAITEM DWORD
   mask        AS DWORD          ' DWORD
   displayname AS WSTRINGZ PTR   ' LPOLESTR
   nImage      AS LONG           ' int
   nOpenImage  AS LONG           ' int
   nState      AS DWORD          ' UINT
   cChildren   AS LONG           ' int
   lParam      AS LONG           ' LPARAM
   relativeID  AS LONG           ' HSCOPEITEM
   ID          AS LONG           ' HSCOPEITEM
END TYPE

' enum MMC_SCOPE_ITEM_STATE
%MMC_SCOPE_ITEM_STATE_NORMAL       = &H1
%MMC_SCOPE_ITEM_STATE_BOLD         = &H2
%MMC_SCOPE_ITEM_STATE_EXPANDEDONCE = &H3

' // Size = 24 bytes
TYPE CONTEXTMENUITEM DWORD
   strName           AS WSTRINGZ PTR   ' LPWSTR
   strStatusBarText  AS WSTRINGZ PTR   ' LPWSTR
   lCommandID        AS LONG           ' LONG
   lInsertionPointID AS LONG           ' LONG
   fFlags            AS LONG           ' LONG
   fSpecialFlags     AS LONG           ' LONG
END TYPE

' enum MMC_MENU_COMMAND_IDS
%MMCC_STANDARD_VIEW_SELECT   = -1

' // Size = 12 bytes
TYPE MENUBUTTONDATA DWORD
   idCommand AS LONG   ' int
   x         AS LONG   ' int
   y         AS LONG   ' int
END TYPE

'typedef LONG_PTR MMC_COOKIE;

%MMC_MULTI_SELECT_COOKIE = -2
%MMC_WINDOW_COOKIE       = -3
%SPECIAL_COOKIE_MIN      = -10
%SPECIAL_COOKIE_MAX      = -1

' enum MMC_FILTER_TYPE
%MMC_STRING_FILTER  = 0
%MMC_INT_FILTER     = &H1???
%MMC_FILTER_NOVALUE = &H8000???

' // Size = 12 bytes
TYPE MMC_FILTERDATA DWORD
   pszText    AS WSTRINGZ PTR   ' LPOLESTR
   cchTextMax AS LONG           ' INT
   lValue     AS LONG           ' LONG
END TYPE

' enum MMC_FILTER_CHANGE_CODE
%MFCC_DISABLE      = 0
%MFCC_ENABLE       = 1
%MFCC_VALUE_CHANGE = 2

' // Size = 16 bytes
TYPE MMC_RESTORE_VIEW DWORD
   dwSize       AS DWORD          ' DWORD
   cookie       AS LONG           ' MMC_COOKIE
   pViewType    AS WSTRINGZ PTR   ' LPOLESTR
   lViewOptions AS LONG           ' long
END TYPE

' // Size = 12 bytes
TYPE MMC_EXPANDSYNC_STRUCT DWORD
   bHandled   AS LONG   ' BOOL
   bExpanding AS LONG   ' BOOL
   hItem      AS LONG   ' HSCOPEITEM
END TYPE

' // Size = 8 bytes
TYPE MMC_VISIBLE_COLUMNS DWORD
   nVisibleColumns  AS LONG   ' INT
   rgVisibleCols(0) AS LONG   ' INT
END TYPE

' enum MMC_NOTIFY_TYPE
%MMCN_ACTIVATE           = &H8001???
%MMCN_ADD_IMAGES         = &H8002???
%MMCN_BTN_CLICK          = &H8003???
%MMCN_CLICK              = &H8004???   ' // NOT USED
%MMCN_COLUMN_CLICK       = &H8005???
%MMCN_CONTEXTMENU        = &H8006???   ' // NOT USED
%MMCN_CUTORMOVE          = &H8007???
%MMCN_DBLCLICK           = &H8008???
%MMCN_DELETE             = &H8009???
%MMCN_DESELECT_ALL       = &H800A???
%MMCN_EXPAND             = &H800B???
%MMCN_HELP               = &H800C???   ' // NOT USED
%MMCN_MENU_BTNCLICK      = &H800D???
%MMCN_MINIMIZED          = &H800E???
%MMCN_PASTE              = &H800F???
%MMCN_PROPERTY_CHANGE    = &H8010???
%MMCN_QUERY_PASTE        = &H8011???
%MMCN_REFRESH            = &H8012???
%MMCN_REMOVE_CHILDREN    = &H8013???
%MMCN_RENAME             = &H8014???
%MMCN_SELECT             = &H8015???
%MMCN_SHOW               = &H8016???
%MMCN_VIEW_CHANGE        = &H8017???
%MMCN_SNAPINHELP         = &H8018???
%MMCN_CONTEXTHELP        = &H8019???
%MMCN_INITOCX            = &H801A???
%MMCN_FILTER_CHANGE      = &H801B???
%MMCN_FILTERBTN_CLICK    = &H801C???
%MMCN_RESTORE_VIEW       = &H801D???
%MMCN_PRINT              = &H801E???
%MMCN_PRELOAD            = &H801F???
%MMCN_LISTPAD            = &H8020???
%MMCN_EXPANDSYNC         = &H8021???
%MMCN_COLUMNS_CHANGED    = &H8022???
%MMCN_CANPASTE_OUTOFPROC = &H8023???

' enum DATA_OBJECT_TYPES
%CCT_SCOPE          = &H8000???
%CCT_RESULT         = &H8001???
%CCT_SNAPIN_MANAGER = &H8002???
%CCT_UNINITIALIZED  = &Hffff???

%MMC_NW_OPTION_NONE         = 0
%MMC_NW_OPTION_NOSCOPEPANE  = &H1
%MMC_NW_OPTION_NOTOOLBARS   = &H2
%MMC_NW_OPTION_SHORTTITLE   = &H4
%MMC_NW_OPTION_CUSTOMTITLE  = &H8
%MMC_NW_OPTION_NOPERSIST    = &H10
%MMC_NW_OPTION_NOACTIONPANE = &H20

'#define   CCF_NODETYPE         ( L"CCF_NODETYPE" )
'#define   CCF_SZNODETYPE       ( L"CCF_SZNODETYPE" )
'#define   CCF_DISPLAY_NAME     ( L"CCF_DISPLAY_NAME" )
'#define   CCF_SNAPIN_CLASSID   ( L"CCF_SNAPIN_CLASSID" )
'#define   CCF_SNAPIN_CLASS     ( L"CCF_SNAPIN_CLASS" )
'#define   CCF_WINDOW_TITLE     ( L"CCF_WINDOW_TITLE" )
'#define   CCF_MMC_MULTISELECT_DATAOBJECT   ( L"CCF_MMC_MULTISELECT_DATAOBJECT" )

$CCF_NODETYPE                   = "CCF_NODETYPE"
$CCF_SZNODETYPE                 = "CCF_SZNODETYPE"
$CCF_DISPLAY_NAME               = "CCF_DISPLAY_NAME"
$CCF_SNAPIN_CLASSID             = "CCF_SNAPIN_CLASSID"
$CCF_SNAPIN_CLASS               = "CCF_SNAPIN_CLASS"
$CCF_WINDOW_TITLE               = "CCF_WINDOW_TITLE"
$CCF_MMC_MULTISELECT_DATAOBJECT = "CCF_MMC_MULTISELECT_DATAOBJECT"

' // Size = 8 bytes
TYPE SMMCDataObjects DWORD
   count           AS DWORD       ' DWORD
   lpDataObject(0) AS DWORD PTR   ' LPDATAOBJECT - IDataObject interface
END TYPE

'#define   CCF_MULTI_SELECT_SNAPINS   ( L"CCF_MULTI_SELECT_SNAPINS" )
$CCF_MULTI_SELECT_SNAPINS = "CCF_MULTI_SELECT_SNAPINS"

' // Size = 20 bytes
TYPE SMMCObjectTypes DWORD
   count   AS DWORD   ' DWORD
   guid(0) AS GUID    ' GUID
END TYPE

'#define   CCF_OBJECT_TYPES_IN_MULTI_SELECT   ( L"CCF_OBJECT_TYPES_IN_MULTI_SELECT" )
$CCF_OBJECT_TYPES_IN_MULTI_SELECT = "CCF_OBJECT_TYPES_IN_MULTI_SELECT"

'typedef SMMCObjectTypes SMMCDynamicExtensions;

'#define   CCF_MMC_DYNAMIC_EXTENSIONS   ( L"CCF_MMC_DYNAMIC_EXTENSIONS" )
'#define   CCF_SNAPIN_PRELOADS   ( L"CCF_SNAPIN_PRELOADS" )

$CCF_MMC_DYNAMIC_EXTENSIONS = "CCF_MMC_DYNAMIC_EXTENSIONS"
$CCF_SNAPIN_PRELOADS        = "CCF_SNAPIN_PRELOADS"

' // Size = 8 bytes
TYPE SNodeID DWORD
   cBytes AS DWORD   ' DWORD
   id(0)  AS BYTE
END TYPE

' // Size = 12 bytes
TYPE SNodeID2 DWORD
   dwFlags AS DWORD   ' DWORD
   cBytes  AS DWORD   ' DWORD
   id(0)   AS BYTE
END TYPE

%MMC_NODEID_SLOW_RETRIEVAL = &H1

'#define   CCF_NODEID2   ( L"CCF_NODEID2" )
'#define   CCF_NODEID   ( L"CCF_NODEID" )
$CCF_NODEID2 = "CCF_NODEID2"
$CCF_NODEID  = "CCF_NODEID"

' // Size = 12 bytes
TYPE SColumnSetID DWORD
   dwFlags AS DWORD   ' DWORD
   cBytes  AS DWORD   ' DWORD
   id(0)   AS BYTE
END TYPE

'#define   CCF_COLUMN_SET_ID   ( L"CCF_COLUMN_SET_ID" )
$CCF_COLUMN_SET_ID = "CCF_COLUMN_SET_ID"

'STDAPI MMCPropertyChangeNotify(LONG_PTR lNotifyHandle, LPARAM param);

'#include <specstrings.h>
'STDAPI MMCPropertyHelp(__in LPOLESTR pszHelpTopic);
DECLARE FUNCTION MMCPropertyHelp IMPORT "mssnapr.dll" ALIAS "MMCPropertyHelp" ( _
   BYREF pszHelpTopic AS WSTRINGZ _                     ' __in LPOLESTR pszHelpTopic
 ) AS LONG                                              ' HRESULT

'STDAPI MMCFreeNotifyHandle(LONG_PTR lNotifyHandle);

'// MMCPropPageCallback is only available in mmc.lib. See MMCAfxPropPageCallback if linking against mmcutil.lib.
'STDAPI MMCPropPageCallback(void* vpsp);

'EXTERN_C const CLSID CLSID_NodeManager;
'EXTERN_C const CLSID CLSID_MessageView;

'// Snap-in implemented callback responsible for calling AFX_MANAGE_STATE() for the snapin-in's module.
'typedef void (STDAPICALLTYPE *PFNAfxManageStateCallback)();

'// Sets up a PROPSHEETPAGE structure for calling the snap-in's PFNAfxManageStateCallback.
'// MMCAfxPropPageCallback is available in both mmc.lib and mmcutil.lib.
'// Returns:
'// S_OK - success
'// E_POINTER - vpsp or pfnCallback is null
'// E_INVALIDARG - vpsp->pfnCallback must be the same for all property pages
'// E_INVALIDARG - pfnManageStateCallback must be the same for all property pages
'// E_UNEXPECTED - vpsp has already been passed to MMCAfxPropPageCallback
'STDAPI MMCAfxPropPageCallback(void* vpsp, PFNAfxManageStateCallback pfnManageStateCallback);

'#define DOBJ_NULL        (LPDATAOBJECT)   0
'#define DOBJ_CUSTOMOCX   (LPDATAOBJECT)  -1
'#define DOBJ_CUSTOMWEB   (LPDATAOBJECT)  -2
'#define DOBJ_NOCONSOLE   (LPDATAOBJECT)  -3
'#define SPECIAL_DOBJ_MIN                -10
'#define SPECIAL_DOBJ_MAX                  0

%DOBJ_NULL        = 0
%DOBJ_CUSTOMOCX   = -1
%DOBJ_CUSTOMWEB   = -2
%DOBJ_NOCONSOLE   = -3
%SPECIAL_DOBJ_MIN = -10
%SPECIAL_DOBJ_MAX = 0

'#define IS_SPECIAL_DATAOBJECT(d) (((LONG_PTR)(d) >= SPECIAL_DOBJ_MIN)   && ((LONG_PTR)(d) <= SPECIAL_DOBJ_MAX))
MACRO IS_SPECIAL_DATAOBJECT(d) = (d >= %SPECIAL_DOBJ_MIN AND d <= %SPECIAL_DOBJ_MAX)
'#define IS_SPECIAL_COOKIE(c)     (((c)          >= SPECIAL_COOKIE_MIN) && ((c)          <= SPECIAL_COOKIE_MAX))
MACRO IS_SPECIAL_COOKIE(c) = (c >= %SPECIAL_COOKIE_MIN AND c <= %SPECIAL_COOKIE_MAX)


' ########################################################################################
' IComponentData interface
' IID = 955AB28A-5218-11D0-A985-00C04FD8D565
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IComponentData_INTERFACE_DEFINED)
    %MMC_IComponentData_INTERFACE_DEFINED = 1

$IID_MMC_IComponentData = GUID$("{955AB28A-5218-11D0-A985-00C04FD8D565}")

INTERFACE MMC_IComponentData $IID_MMC_IComponentData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pUnknown AS IUnknown _                       ' __in LPUNKNOWN pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponent ( _                           ' VTable offset = 16
     BYREF ppComponent AS MMC_IComponent _              ' LPCOMPONENT *ppComponent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 20
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL event AS DWORD _                             ' __in MMC_NOTIFY_TYPE event
   , BYVAL arg AS LONG _                                ' __in LPARAM arg
   , BYVAL param AS LONG _                              ' __in LPARAM param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDataObject ( _                           ' VTable offset = 28
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS LONG _                               ' __in DATA_OBJECT_TYPES type
   , BYREF ppDataObject AS IDataObject _                ' __out LPDATAOBJECT *ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayInfo ( _                            ' VTable offset = 32
      BYREF pScopeDataItem AS SCOPEDATAITEM _           ' __in_out SCOPEDATAITEM *pScopeDataItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareObjects ( _                            ' VTable offset = 36
     BYVAL lpDataObjectA AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectA
   , BYVAL lpDataObjectB AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IComponentData_INTERFACE_DEFINED__ */


' ########################################################################################
' IComponent interface
' IID = 43136EB2-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IComponent_INTERFACE_DEFINED)
    %MMC_IComponent_INTERFACE_DEFINED = 1

$IID_MMC_IComponent = GUID$("{43136EB2-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IComponent $IID_MMC_IComponent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL lpConsole AS MMC_IConsole _                  ' __in LPCONSOLE lpConsole
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 16
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL event AS DWORD _                             ' __in MMC_NOTIFY_TYPE event
   , BYVAL arg AS LONG _                                ' __in LPARAM arg
   , BYVAL param AS LONG _                              ' __in LPARAM param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 20
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDataObject ( _                           ' VTable offset = 24
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS LONG _                               ' __in DATA_OBJECT_TYPES type
   , BYREF ppDataObject AS IDataObject _                ' __out LPDATAOBJECT *ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultViewType ( _                         ' VTable offset = 28
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYREF ppViewType AS DWORD _                        ' __out LPOLESTR *ppViewType
   , BYREF pViewOptions AS LONG _                       ' __out long *pViewOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayInfo ( _                            ' VTable offset = 32
     BYREF pResultDataItem AS RESULTDATAITEM _          ' __in_out RESULTDATAITEM *pResultDataItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareObjects ( _                            ' VTable offset = 36
     BYVAL lpDataObjectA AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectA
   , BYVAL lpDataObjectB AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IComponent_INTERFACE_DEFINED__ */

' ########################################################################################
' IResultDataCompare interface
' IID = E8315A52-7A1A-11D0-A2D2-00C04FD909DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IResultDataCompare_INTERFACE_DEFINED)
    %MMC_IResultDataCompare_INTERFACE_DEFINED = 1

$IID_MMC_IResultDataCompare = GUID$("{E8315A52-7A1A-11D0-A2D2-00C04FD909DD}")

INTERFACE MMC_IResultDataCompare $IID_MMC_IResultDataCompare

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 12
     BYVAL lUserParam AS LONG _                         ' __in LPARAM lUserParam
   , BYVAL cookieA AS LONG _                            ' __in MMC_COOKIE cookieA
   , BYVAL cookieB AS LONG _                            ' __in MMC_COOKIE cookieB
   , BYREF pnResult AS LONG _                           ' __in_out int *pnResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IResultDataCompare_INTERFACE_DEFINED__ */

' ########################################################################################
' IResultOwnerData interface
' IID = 9CB396D8-EA83-11D0-AEF1-00C04FB6DD2C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IResultOwnerData_INTERFACE_DEFINED)
    %MMC_IResultOwnerData_INTERFACE_DEFINED = 1

$IID_MMC_IResultOwnerData = GUID$("{9CB396D8-EA83-11D0-AEF1-00C04FB6DD2C}")

INTERFACE MMC_IResultOwnerData $IID_MMC_IResultOwnerData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindItem ( _                                  ' VTable offset = 12
     BYREF pFindInfo AS RESULTFINDINFO _                ' __in LPRESULTFINDINFO pFindInfo
   , BYREF pnFoundIndex AS LONG _                       ' __out int *pnFoundIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CacheHint ( _                                 ' VTable offset = 16
     BYVAL nStartIndex AS LONG _                        ' __in int nStartIndex
   , BYVAL nEndIndex AS LONG _                          ' __in int nEndIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SortItems ( _                                 ' VTable offset = 20
     BYVAL nColumn AS LONG _                            ' __in int nColumn
   , BYVAL dwSortOptions AS DWORD _                     ' __in DWORD dwSortOptions
   , BYVAL lUserParam AS LONG _                         ' __in LPARAM lUserParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IResultOwnerData_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsole interface
' IID = 43136EB1-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IConsole_INTERFACE_DEFINED)
    %MMC_IConsole_INTERFACE_DEFINED = 1

$IID_MMC_IConsole = GUID$("{43136EB1-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IConsole $IID_MMC_IConsole

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHeader ( _                                 ' VTable offset = 12
     BYVAL pHeader AS MMC_IHeaderCtrl _                 ' __in LPHEADERCTRL pHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetToolbar ( _                                ' VTable offset = 16
     BYVAL pToolbar AS MMC_IToolbar _                   ' __in LPTOOLBAR pToolbar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultView ( _                           ' VTable offset = 20
     BYREF pUnknown AS IUnknown _                       ' __out LPUNKNOWN *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryScopeImageList ( _                       ' VTable offset = 24
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultImageList ( _                      ' VTable offset = 28
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAllViews ( _                            ' VTable offset = 32
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL data AS LONG _                               ' __in LPARAM data
   , BYVAL hint AS LONG _                               ' __in LONG_PTR hint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MessageBox ( _                                ' VTable offset = 36
     BYREF lpszText AS WSTRINGZ _                       ' __in LPCWSTR lpszText
   , BYREF lpszTitle AS WSTRINGZ _                      ' __in LPCWSTR lpszTitle
   , BYVAL fuStyle AS DWORD _                           ' __in UINT fuStyle
   , BYREF piRetval AS LONG _                           ' __out int *piRetval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryConsoleVerb ( _                          ' VTable offset = 40
     BYREF ppConsoleVerb AS MMC_IConsoleVerb _          ' __out LPCONSOLEVERB *ppConsoleVerb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectScopeItem ( _                           ' VTable offset = 44
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMainWindow ( _                             ' VTable offset = 48
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewWindow ( _                                 ' VTable offset = 52
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   , BYVAL lOptions AS LONG _                           ' __in unsigned long lOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsole_INTERFACE_DEFINED__ */

' ########################################################################################
' IHeaderCtrl interface
' IID = 43136EB3-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IHeaderCtrl_INTERFACE_DEFINED)
    %MMC_IHeaderCtrl_INTERFACE_DEFINED = 1

%AUTO_WIDTH  = -1
%HIDE_COLUMN = -4

$IID_MMC_IHeaderCtrl = GUID$("{43136EB3-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IHeaderCtrl $IID_MMC_IHeaderCtrl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertColumn ( _                              ' VTable offset = 12
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   , BYVAL nFormat AS LONG _                            ' __in int nFormat
   , BYVAL nWidth AS LONG _                             ' __in int nWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteColumn ( _                              ' VTable offset = 16
     BYVAL nCol AS LONG _                               ' __in int nCol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnText ( _                             ' VTable offset = 20
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnText ( _                             ' VTable offset = 24
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF pText AS DWORD _                             ' __out LPOLESTR *pText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnWidth ( _                            ' VTable offset = 28
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYVAL nWidth AS LONG _                             ' __in int nWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnWidth ( _                            ' VTable offset = 32
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF pWidth AS LONG _                             ' __out int *pWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IHeaderCtrl_INTERFACE_DEFINED__ */

' enum __MIDL___MIDL_itf_mmc_0000_0006_0001
%CCM_INSERTIONPOINTID_MASK_SPECIAL        = &Hffff0000???
%CCM_INSERTIONPOINTID_MASK_SHARED         = &H80000000???
%CCM_INSERTIONPOINTID_MASK_CREATE_PRIMARY = &H40000000???
%CCM_INSERTIONPOINTID_MASK_ADD_PRIMARY    = &H20000000???
%CCM_INSERTIONPOINTID_MASK_ADD_3RDPARTY   = &H10000000???
%CCM_INSERTIONPOINTID_MASK_RESERVED       = &Hfff0000???
%CCM_INSERTIONPOINTID_MASK_FLAGINDEX      = &H1f???
%CCM_INSERTIONPOINTID_PRIMARY_TOP         = &Ha0000000???
%CCM_INSERTIONPOINTID_PRIMARY_NEW         = &Ha0000001???
%CCM_INSERTIONPOINTID_PRIMARY_TASK        = &Ha0000002???
%CCM_INSERTIONPOINTID_PRIMARY_VIEW        = &Ha0000003???
%CCM_INSERTIONPOINTID_PRIMARY_HELP        = &Ha0000004???
%CCM_INSERTIONPOINTID_3RDPARTY_NEW        = &H90000001???
%CCM_INSERTIONPOINTID_3RDPARTY_TASK       = &H90000002???
%CCM_INSERTIONPOINTID_ROOT_MENU           = &H80000000???

' enum __MIDL___MIDL_itf_mmc_0000_0006_0002
'    {   CCM_INSERTIONALLOWED_TOP   = ( 1L << (( CCM_INSERTIONPOINTID_PRIMARY_TOP & CCM_INSERTIONPOINTID_MASK_FLAGINDEX ) ) ) ,
'   CCM_INSERTIONALLOWED_NEW   = ( 1L << (( CCM_INSERTIONPOINTID_PRIMARY_NEW & CCM_INSERTIONPOINTID_MASK_FLAGINDEX ) ) ) ,
'   CCM_INSERTIONALLOWED_TASK   = ( 1L << (( CCM_INSERTIONPOINTID_PRIMARY_TASK & CCM_INSERTIONPOINTID_MASK_FLAGINDEX ) ) ) ,
'   CCM_INSERTIONALLOWED_VIEW   = ( 1L << (( CCM_INSERTIONPOINTID_PRIMARY_VIEW & CCM_INSERTIONPOINTID_MASK_FLAGINDEX ) ) )
'    } ;

%CCM_INSERTIONALLOWED_TOP  = &H00000001???
%CCM_INSERTIONALLOWED_NEW  = &H00000002???
%CCM_INSERTIONALLOWED_TASK = &H00000004???
%CCM_INSERTIONALLOWED_VIEW = &H00000008???

' enum __MIDL___MIDL_itf_mmc_0000_0006_0003
%CCM_COMMANDID_MASK_RESERVED   = &Hffff0000???

' enum __MIDL___MIDL_itf_mmc_0000_0006_0004
%CCM_SPECIAL_SEPARATOR       = &H1
%CCM_SPECIAL_SUBMENU         = &H2
%CCM_SPECIAL_DEFAULT_ITEM    = &H4
%CCM_SPECIAL_INSERTION_POINT = &H8
%CCM_SPECIAL_TESTONLY        = &H10

' ########################################################################################
' IContextMenuCallback interface
' IID = 43136EB7-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IContextMenuCallback_INTERFACE_DEFINED)
    %MMC_IContextMenuCallback_INTERFACE_DEFINED = 1

$IID_MMC_IContextMenuCallback = GUID$("{43136EB7-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IContextMenuCallback $IID_MMC_IContextMenuCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddItem ( _                                   ' VTable offset = 12
     BYREF pItem AS CONTEXTMENUITEM _                   ' __in CONTEXTMENUITEM *pItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IContextMenuCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IContextMenuProvider interface
' IID = 9A93B3FB-4E75-4C74-871A-2CDA667F39A5
' Inherited interface = IContextMenuCallback
' ########################################################################################

#IF NOT %DEF(%MMC_IContextMenuProvider_INTERFACE_DEFINED)
    %MMC_IContextMenuProvider_INTERFACE_DEFINED = 1

$IID_MMC_IContextMenuProvider = GUID$("{9A93B3FB-4E75-4C74-871A-2CDA667F39A5}")

INTERFACE MMC_IContextMenuProvider $IID_MMC_IContextMenuProvider

   INHERIT IUnknown

   ' =====================================================================================
   ' IContextMenuCallback Method
   ' =====================================================================================
   METHOD AddItem ( _                                   ' VTable offset = 12
     BYREF pItem AS CONTEXTMENUITEM _                   ' __in CONTEXTMENUITEM *pItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IContextMenuCallback Method
   ' =====================================================================================
   METHOD EmptyMenuList ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPrimaryExtensionItems ( _                  ' VTable offset = 20
     BYVAL piExtension AS IUnknown _                    ' __in LPUNKNOWN piExtension
   , BYVAL piDataObject AS IDataObject _                ' __in LPDATAOBJECT piDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddThirdPartyExtensionItems ( _               ' VTable offset = 24
     BYVAL piDataObject AS IDataObject _                ' __in LPDATAOBJECT piDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowContextMenu ( _                           ' VTable offset = 28
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   , BYREF plSelected AS LONG _                         ' __retval_out long *plSelected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IContextMenuProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendContextMenu interface
' IID = 4F3B7A4F-CFAC-11CF-B8E3-00C04FD8D5B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendContextMenu_INTERFACE_DEFINED)
    %MMC_IExtendContextMenu_INTERFACE_DEFINED = 1

$IID_MMC_IExtendContextMenu = GUID$("{4F3B7A4F-CFAC-11CF-B8E3-00C04FD8D5B0}")

INTERFACE MMC_IExtendContextMenu $IID_MMC_IExtendContextMenu

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddMenuItems ( _                              ' VTable offset = 12
     BYVAL piDataObject AS IDataObject _                ' __in LPDATAOBJECT piDataObject
   , BYVAL piCallback AS MMC_IContextMenuCallback _     ' __in LPCONTEXTMENUCALLBACK piCallback
   , BYREF pInsertionAllowed AS LONG _                  ' __in_out long *pInsertionAllowed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Command ( _                                   ' VTable offset = 16
     BYVAL lCommandID AS LONG _                         ' __in long lCommandID
   , BYVAL piDataObject AS IDataObject _                ' __in LPDATAOBJECT piDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendContextMenu_INTERFACE_DEFINED__ */


%ILSIF_LEAVE_LARGE_ICON  = &H40000000???
%ILSIF_LEAVE_SMALL_ICON  = &H20000000???
%ILSIF_LEAVE_MASK        = %ILSIF_LEAVE_LARGE_ICON OR %ILSIF_LEAVE_SMALL_ICON
MACRO ILSI_LARGE_ICON(nLoc) = (nLoc OR %ILSIF_LEAVE_SMALL_ICON)
MACRO ILSI_SMALL_ICON(nLoc) = (nLoc OR %ILSIF_LEAVE_LARGE_ICON)


' ########################################################################################
' IImageList interface
' IID = 43136EB8-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IImageList_INTERFACE_DEFINED)
    %MMC_IImageList_INTERFACE_DEFINED = 1

$IID_MMC_IImageList = GUID$("{43136EB8-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IImageList $IID_MMC_IImageList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ImageListSetIcon ( _                          ' VTable offset = 12
     BYVAL pIcon AS LONG _                              ' __in LONG_PTR *pIcon
   , BYVAL nLoc AS LONG _                               ' __in long nLoc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ImageListSetStrip ( _                         ' VTable offset = 16
     BYVAL pBMapSm AS LONG _                            ' __in LONG_PTR *pBMapSm
   , BYVAL pBMapLg AS LONG _                            ' __in LONG_PTR *pBMapLg
   , BYVAL nStartLoc AS LONG _                          ' __in long nStartLoc
   , BYVAL cMask AS DWORD _                             ' __in COLORREF cMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IImageList_INTERFACE_DEFINED__ */

' ########################################################################################
' IResultData interface
' IID = 31DA5FA0-E0EB-11CF-9F21-00AA003CA9F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IResultData_INTERFACE_DEFINED)
    %MMC_IResultData_INTERFACE_DEFINED = 1

$IID_MMC_IResultData = GUID$("{31DA5FA0-E0EB-11CF-9F21-00AA003CA9F6}")

INTERFACE MMC_IResultData $IID_MMC_IResultData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertItem ( _                                ' VTable offset = 12
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 16
     BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   , BYVAL nCol AS LONG _                               ' __in int nCol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindItemByLParam ( _                          ' VTable offset = 20
     BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF pItemID AS LONG _                            ' __out HRESULTITEM *pItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllRsltItems ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 28
     BYREF item AS RESULTDATAITEM _                     ' __in LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 32
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 36
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyItemState ( _                           ' VTable offset = 40
     BYVAL nIndex AS LONG _                             ' __in int nIndex
   , BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   , BYVAL uAdd AS DWORD _                              ' __in UINT uAdd
   , BYVAL uRemove AS DWORD _                           ' __in UINT uRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyViewStyle ( _                           ' VTable offset = 44
     BYVAL add AS DWORD _                               ' __in MMC_RESULT_VIEW_STYLE add
   , BYVAL remove AS DWORD _                            ' __in MMC_RESULT_VIEW_STYLE remove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewMode ( _                               ' VTable offset = 48
     BYVAL lViewMode AS LONG _                          ' __in long lViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewMode ( _                               ' VTable offset = 52
     BYREF lViewMode AS LONG _                          ' __out long *lViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateItem ( _                                ' VTable offset = 56
     BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sort ( _                                      ' VTable offset = 60
     BYVAL nColumn AS LONG _                            ' __in int nColumn
   , BYVAL dwSortOptions AS DWORD _                     ' __in DWORD dwSortOptions
   , BYVAL lUserParam AS LONG _                         ' __in LPARAM lUserParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescBarText ( _                            ' VTable offset = 64
     BYREF DescText AS WSTRINGZ _                       ' __in LPOLESTR DescText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemCount ( _                              ' VTable offset = 68
     BYVAL nItemCount AS LONG _                         ' __in int nItemCount
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IResultData_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsoleNameSpace interface
' IID = BEDEB620-F24D-11CF-8AFC-00AA003CA9F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IConsoleNameSpace_INTERFACE_DEFINED)
    %MMC_IConsoleNameSpace_INTERFACE_DEFINED = 1

$IID_MMC_IConsoleNameSpace = GUID$("{BEDEB620-F24D-11CF-8AFC-00AA003CA9F6}")

INTERFACE MMC_IConsoleNameSpace $IID_MMC_IConsoleNameSpace

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertItem ( _                                ' VTable offset = 12
     BYREF item AS SCOPEDATAITEM _                      ' __in_out LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 16
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYVAL fDeleteThis AS LONG _                        ' __in long fDeleteThis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 20
     BYREF item AS SCOPEDATAITEM _                      ' __in LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 24
     BYREF item AS SCOPEDATAITEM _                      ' __in_out LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChildItem ( _                              ' VTable offset = 28
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemChild AS LONG _                         ' __out HSCOPEITEM *pItemChild
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 32
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemNext AS LONG _                          ' __out HSCOPEITEM *pItemNext
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentItem ( _                             ' VTable offset = 36
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemParent AS LONG _                        ' __out HSCOPEITEM *pItemParent
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsoleNameSpace_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsoleNameSpace2 interface
' IID = 255F18CC-65DB-11D1-A7DC-00C04FD8D565
' Inherited interface = IConsoleNameSpace
' ########################################################################################

#IF NOT %DEF(%MMC_IConsoleNameSpace2_INTERFACE_DEFINED)
    %MMC_IConsoleNameSpace2_INTERFACE_DEFINED = 1

$IID_MMC_IConsoleNameSpace2 = GUID$("{255F18CC-65DB-11D1-A7DC-00C04FD8D565}")

INTERFACE MMC_IConsoleNameSpace2 $IID_MMC_IConsoleNameSpace2

   INHERIT IUnknown

   ' =====================================================================================
   ' IConsoleNameSpace Methods
   ' =====================================================================================
   METHOD InsertItem ( _                                ' VTable offset = 12
     BYREF item AS SCOPEDATAITEM _                      ' __in_out LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 16
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYVAL fDeleteThis AS LONG _                        ' __in long fDeleteThis
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 20
     BYREF item AS SCOPEDATAITEM _                      ' __in LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 24
     BYREF item AS SCOPEDATAITEM _                      ' __in_out LPSCOPEDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChildItem ( _                              ' VTable offset = 28
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemChild AS LONG _                         ' __out HSCOPEITEM *pItemChild
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 32
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemNext AS LONG _                          ' __out HSCOPEITEM *pItemNext
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentItem ( _                             ' VTable offset = 36
     BYVAL item AS LONG _                               ' __in HSCOPEITEM item
   , BYREF pItemParent AS LONG _                        ' __out HSCOPEITEM *pItemParent
   , BYREF pCookie AS LONG _                            ' __out MMC_COOKIE *pCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConsoleNameSpace2 Methods
   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 40
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtension ( _                              ' VTable offset = 44
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYREF lpClsid AS GUID _                            ' __in LPCLSID lpClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsoleNameSpace2_INTERFACE_DEFINED__ */


'typedef struct _PSP *HPROPSHEETPAGE;

' ########################################################################################
' IPropertySheetCallback interface
' IID = 85DE64DD-EF21-11CF-A285-00C04FD8DBE6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IPropertySheetCallback_INTERFACE_DEFINED)
    %MMC_IPropertySheetCallback_INTERFACE_DEFINED = 1

$IID_MMC_IPropertySheetCallback = GUID$("{85DE64DD-EF21-11CF-A285-00C04FD8DBE6}")

INTERFACE MMC_IPropertySheetCallback $IID_MMC_IPropertySheetCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddPage ( _                                   ' VTable offset = 12
     BYVAL hPage AS DWORD _                             ' __in HPROPSHEETPAGE hPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePage ( _                                ' VTable offset = 16
     BYVAL hPage AS DWORD _                             ' __in HPROPSHEETPAGE hPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IPropertySheetCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IPropertySheetProvider interface
' IID = 85DE64DE-EF21-11CF-A285-00C04FD8DBE6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IPropertySheetProvider_INTERFACE_DEFINED)
    %MMC_IPropertySheetProvider_INTERFACE_DEFINED = 1

$IID_MMC_IPropertySheetProvider = GUID$("{85DE64DE-EF21-11CF-A285-00C04FD8DBE6}")

INTERFACE MMC_IPropertySheetProvider $IID_MMC_IPropertySheetProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePropertySheet ( _                       ' VTable offset = 12
     BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   , BYVAL type AS BYTE _                               ' __in boolean type
   , BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL pIDataObjectm AS IDataObject _               ' __in LPDATAOBJECT pIDataObjectm
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindPropertySheet ( _                         ' VTable offset = 16
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYVAL lpComponent AS MMC_IComponent _              ' __in LPCOMPONENT lpComponent
   , BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPrimaryPages ( _                           ' VTable offset = 20
     BYVAL lpUnknown AS IUnknown _                      ' __in LPUNKNOWN lpUnknown
   , BYVAL bCreateHandle AS LONG _                      ' __in BOOL bCreateHandle
   , BYVAL hNotifyWindow AS DWORD _                     ' __in HWND hNotifyWindow
   , BYVAL bScopePane AS LONG _                         ' __in BOOL bScopePane
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddExtensionPages ( _                         ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 28
     BYVAL window AS LONG _                             ' __in LONG_PTR window
   , BYVAL page AS LONG _                               ' __in int page
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IPropertySheetProvider_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendPropertySheet interface
' IID = 85DE64DC-EF21-11CF-A285-00C04FD8DBE6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendPropertySheet_INTERFACE_DEFINED)
    %MMC_IExtendPropertySheet_INTERFACE_DEFINED = 1

$IID_MMC_IExtendPropertySheet = GUID$("{85DE64DC-EF21-11CF-A285-00C04FD8DBE6}")

INTERFACE MMC_IExtendPropertySheet $IID_MMC_IExtendPropertySheet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreatePropertyPages ( _                       ' VTable offset = 12
     BYVAL lpProvider AS MMC_IPropertySheetCallback _   ' __in LPPROPERTYSHEETCALLBACK lpProvider
   , BYVAL handle AS LONG _                             ' __in LONG_PTR handle
   , BYVAL lpIDataObject AS IDataObject _               ' __in LPDATAOBJECT lpIDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPagesFor ( _                             ' VTable offset = 16
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendPropertySheet_INTERFACE_DEFINED__ */

' ########################################################################################
' IControlbar interface
' IID = 69FB811E-6C1C-11D0-A2CB-00C04FD909DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IControlbar_INTERFACE_DEFINED)
    %MMC_IControlbar_INTERFACE_DEFINED = 1

$IID_MMC_IControlbar = GUID$("{69FB811E-6C1C-11D0-A2CB-00C04FD909DD}")

INTERFACE MMC_IControlbar $IID_MMC_IControlbar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL nType AS LONG _                              ' __in MMC_CONTROL_TYPE nType
   , BYVAL pExtendControlbar AS MMC_IExtendControlbar _ ' __in LPEXTENDCONTROLBAR pExtendControlbar
   , BYREF ppUnknown AS IUnknown _                      ' __out LPUNKNOWN *ppUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Attach ( _                                    ' VTable offset = 16
     BYVAL nType AS LONG _                              ' __in MMC_CONTROL_TYPE nType
   , BYVAL lpUnknown AS IUnknown _                      ' __in LPUNKNOWN lpUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 20
     BYVAL lpUnknown AS IUnknown _                      ' __in LPUNKNOWN lpUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IControlbar_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendControlbar interface
' IID = 49506520-6F40-11D0-A98B-00C04FD8D565
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendControlbar_INTERFACE_DEFINED)
    %MMC_IExtendControlbar_INTERFACE_DEFINED = 1

$IID_MMC_IExtendControlbar = GUID$("{49506520-6F40-11D0-A98B-00C04FD8D565}")

INTERFACE MMC_IExtendControlbar $IID_MMC_IExtendControlbar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetControlbar ( _                             ' VTable offset = 12
     BYVAL pControlbar AS MMC_IControlBar _             ' __in LPCONTROLBAR pControlbar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ControlbarNotify ( _                          ' VTable offset = 16
     BYVAL event AS LONG _                              ' __in MMC_NOTIFY_TYPE event
   , BYVAL arg AS LONG _                                ' __in LPARAM arg
   , BYVAL param AS LONG _                              ' __in LPARAM param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendControlbar_INTERFACE_DEFINED__ */

' ########################################################################################
' IToolbar interface
' IID = 43136EB9-D36C-11CF-ADBC-00AA00A80033
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IToolbar_INTERFACE_DEFINED)
    %MMC_IToolbar_INTERFACE_DEFINED = 1

$IID_MMC_IToolbar = GUID$("{43136EB9-D36C-11CF-ADBC-00AA00A80033}")

INTERFACE MMC_IToolbar $IID_MMC_IToolbar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddBitmap ( _                                 ' VTable offset = 12
     BYVAL nImages AS LONG _                            ' __in int nImages
   , BYVAL hbmp AS DWORD _                              ' __in HBITMAP hbmp
   , BYVAL cxSize AS LONG _                             ' __in int cxSize
   , BYVAL cySize AS LONG _                             ' __in int cySize
   , BYVAL crMask AS DWORD _                            ' __in COLORREF crMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddButtons ( _                                ' VTable offset = 16
     BYVAL nButtons AS LONG _                           ' __in int nButtons
   , BYREF lpButtons AS MMCBUTTON _                     ' __in LPMMCBUTTON lpButtons
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertButton ( _                              ' VTable offset = 20
     BYVAL nIndex AS LONG _                             ' __in int nIndex
   , BYREF lpButtons AS MMCBUTTON _                     ' __in LPMMCBUTTON lpButtons
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteButton ( _                              ' VTable offset = 24
     BYVAL nIndex AS LONG _                             ' __in int nIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetButtonState ( _                            ' VTable offset = 28
     BYVAL idCommand AS LONG _                          ' __in int idCommand
   , BYVAL nState AS LONG _                             ' __in MMC_BUTTON_STATE nState
   , BYREF pState AS LONG _                             ' __out BOOL *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetButtonState ( _                            ' VTable offset = 32
     BYVAL idCommand AS LONG _                          ' __in int idCommand
   , BYVAL nState AS LONG _                             ' __in MMC_BUTTON_STATE nState
   , BYVAL bState AS LONG _                             ' __in BOOL bState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IToolbar_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsoleVerb interface
' IID = E49F7A60-74AF-11D0-A286-00C04FD8FE93
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IConsoleVerb_INTERFACE_DEFINED)
    %MMC_IConsoleVerb_INTERFACE_DEFINED = 1

$IID_MMC_IConsoleVerb = GUID$("{E49F7A60-74AF-11D0-A286-00C04FD8FE93}")

INTERFACE MMC_IConsoleVerb $IID_MMC_IConsoleVerb

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVerbState ( _                              ' VTable offset = 12
     BYVAL eCmdID AS DWORD _                            ' __in MMC_CONSOLE_VERB eCmdID
   , BYVAL nState AS LONG _                             ' __in MMC_BUTTON_STATE nState
   , BYREF pState AS LONG _                             ' __out BOOL *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVerbState ( _                              ' VTable offset = 16
     BYVAL eCmdID AS DWORD _                            ' __in MMC_CONSOLE_VERB eCmdID
   , BYVAL nState AS LONG _                             ' __in MMC_BUTTON_STATE nState
   , BYVAL bState AS LONG _                             ' __in BOOL bState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultVerb ( _                            ' VTable offset = 20
     BYVAL eCmdID AS DWORD _                            ' __in MMC_CONSOLE_VERB eCmdID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultVerb ( _                            ' VTable offset = 24
     BYREF peCmdID AS DWORD _                           ' __out MMC_CONSOLE_VERB *peCmdID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsoleVerb_INTERFACE_DEFINED__ */

' ########################################################################################
' ISnapinAbout interface
' IID = 1245208C-A151-11D0-A7D7-00C04FD909DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_ISnapinAbout_INTERFACE_DEFINED)
    %MMC_ISnapinAbout_INTERFACE_DEFINED = 1

$IID_MMC_ISnapinAbout = GUID$("{1245208C-A151-11D0-A7D7-00C04FD909DD}")

INTERFACE MMC_ISnapinAbout $IID_MMC_ISnapinAbout

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSnapinDescription ( _                      ' VTable offset = 12
     BYREF lpDescription AS DWORD _                     ' __out LPOLESTR *lpDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProvider ( _                               ' VTable offset = 16
     BYREF lpName AS DWORD _                            ' __out LPOLESTR *lpName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSnapinVersion ( _                          ' VTable offset = 20
     BYREF lpVersion AS DWORD _                         ' __out LPOLESTR *lpVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSnapinImage ( _                            ' VTable offset = 24
     BYREF hAppIcon AS DWORD _                          ' __out HICON *hAppIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStaticFolderImage ( _                      ' VTable offset = 28
     BYREF hSmallImage AS DWORD _                       ' __out HBITMAP *hSmallImage
   , BYREF hSmallImageOpen AS DWORD _                   ' __out HBITMAP *hSmallImageOpen
   , BYREF hLargeImage AS DWORD _                       ' __out HBITMAP *hLargeImage
   , BYREF cMask AS DWORD _                             ' __out COLORREF *cMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ISnapinAbout_INTERFACE_DEFINED__ */

' ########################################################################################
' IMenuButton interface
' IID = 951ED750-D080-11D0-B197-000000000000
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IMenuButton_INTERFACE_DEFINED)
    %MMC_IMenuButton_INTERFACE_DEFINED = 1

$IID_MMC_IMenuButton = GUID$("{951ED750-D080-11D0-B197-000000000000}")

INTERFACE MMC_IMenuButton $IID_MMC_IMenuButton

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddButton ( _                                 ' VTable offset = 12
     BYVAL idCommand AS LONG _                          ' __in int idCommand
   , BYREF lpButtonText AS WSTRINGZ _                   ' __in LPOLESTR lpButtonText
   , BYREF lpTooltipText AS WSTRINGZ _                  ' __in LPOLESTR lpTooltipText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetButton ( _                                 ' VTable offset = 16
     BYVAL idCommand AS LONG _                          ' __in int idCommand
   , BYREF lpButtonText AS WSTRINGZ _                   ' __in LPOLESTR lpButtonText
   , BYREF lpTooltipText AS WSTRINGZ _                  ' __in LPOLESTR lpTooltipText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetButtonState ( _                            ' VTable offset = 20
     BYVAL idCommand AS LONG _                          ' __in int idCommand
   , BYVAL nState AS LONG _                             ' __in MMC_BUTTON_STATE nState
   , BYVAL bState AS LONG _                             ' __in BOOL bState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IMenuButton_INTERFACE_DEFINED__ */

' ########################################################################################
' ISnapinHelp interface
' IID = A6B15ACE-DF59-11D0-A7DD-00C04FD909DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_ISnapinHelp_INTERFACE_DEFINED)
    %MMC_ISnapinHelp_INTERFACE_DEFINED = 1

$IID_MMC_ISnapinHelp = GUID$("{A6B15ACE-DF59-11D0-A7DD-00C04FD909DD}")

INTERFACE MMC_ISnapinHelp $IID_MMC_ISnapinHelp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHelpTopic ( _                              ' VTable offset = 12
     BYREF lpCompiledHelpFile AS DWORD _                ' __out LPOLESTR *lpCompiledHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ISnapinHelp_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendPropertySheet2 interface
' IID = B7A87232-4A51-11D1-A7EA-00C04FD909DD
' Inherited interface = IExtendPropertySheet
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendPropertySheet2_INTERFACE_DEFINED)
    %MMC_IExtendPropertySheet2_INTERFACE_DEFINED = 1

$IID_MMC_IExtendPropertySheet2 = GUID$("{B7A87232-4A51-11D1-A7EA-00C04FD909DD}")

INTERFACE MMC_IExtendPropertySheet2 $IID_MMC_IExtendPropertySheet2

   INHERIT IUnknown

   ' =====================================================================================
   ' IExtendPropertySheet Methods
   ' =====================================================================================
   METHOD CreatePropertyPages ( _                       ' VTable offset = 12
     BYVAL lpProvider AS MMC_IPropertySheetCallback _   ' __in LPPROPERTYSHEETCALLBACK lpProvider
   , BYVAL handle AS LONG _                             ' __in LONG_PTR handle
   , BYVAL lpIDataObject AS IDataObject _               ' __in LPDATAOBJECT lpIDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPagesFor ( _                             ' VTable offset = 16
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IExtendPropertySheet2 Method
   ' =====================================================================================
   METHOD GetWatermarks ( _                             ' VTable offset = 20
     BYVAL lpIDataObject AS IDataObject _               ' __in LPDATAOBJECT lpIDataObject
   , BYREF lphWatermark AS DWORD _                      ' __out HBITMAP *lphWatermark
   , BYREF lphHeader AS DWORD _                         ' __out HBITMAP *lphHeader
   , BYREF lphPalette AS DWORD _                        ' __out HPALETTE *lphPalette
   , BYREF bStretch AS LONG _                           ' __out BOOL *bStretch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendPropertySheet2_INTERFACE_DEFINED__ */

' ########################################################################################
' IHeaderCtrl2 interface
' IID = 9757ABB8-1B32-11D1-A7CE-00C04FD8D565
' Inherited interface = IHeaderCtrl
' ########################################################################################

#IF NOT %DEF(%MMC_IHeaderCtrl2_INTERFACE_DEFINED)
    %MMC_IHeaderCtrl2_INTERFACE_DEFINED = 1

$IID_MMC_IHeaderCtrl2 = GUID$("{9757ABB8-1B32-11D1-A7CE-00C04FD8D565}")

INTERFACE MMC_IHeaderCtrl2 $IID_MMC_IHeaderCtrl2

   INHERIT IUnknown

   ' =====================================================================================
   ' IHeaderCtrl Methods
   ' =====================================================================================
   METHOD InsertColumn ( _                              ' VTable offset = 12
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   , BYVAL nFormat AS LONG _                            ' __in int nFormat
   , BYVAL nWidth AS LONG _                             ' __in int nWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteColumn ( _                              ' VTable offset = 16
     BYVAL nCol AS LONG _                               ' __in int nCol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnText ( _                             ' VTable offset = 20
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnText ( _                             ' VTable offset = 24
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF pText AS DWORD _                             ' __out LPOLESTR *pText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnWidth ( _                            ' VTable offset = 28
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYVAL nWidth AS LONG _                             ' __in int nWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnWidth ( _                            ' VTable offset = 32
     BYVAL nCol AS LONG _                               ' __in int nCol
   , BYREF pWidth AS LONG _                             ' __out int *pWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IHeaderCtrl2 Methods
   ' =====================================================================================
   METHOD SetChangeTimeOut ( _                          ' VTable offset = 36
     BYVAL uTimeout AS DWORD _                          ' __in unsigned long uTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnFilter ( _                           ' VTable offset = 40
     BYVAL nColumn AS DWORD _                           ' __in UINT nColumn
   , BYVAL dwType AS DWORD _                            ' __in DWORD dwType
   , BYREF pFilterData AS MMC_FILTERDATA _              ' __in MMC_FILTERDATA *pFilterData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnFilter ( _                           ' VTable offset = 44
     BYVAL nColumn AS DWORD _                           ' __in UINT nColumn
   , BYREF pdwType AS DWORD _                           ' __in_out LPDWORD pdwType
   , BYREF pFilterData AS MMC_FILTERDATA _              ' __in_out MMC_FILTERDATA *pFilterData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IHeaderCtrl2_INTERFACE_DEFINED__ */

' ########################################################################################
' ISnapinHelp2 interface
' IID = 4861A010-20F9-11D2-A510-00C04FB6DD2C
' Inherited interface = ISnapinHelp
' ########################################################################################

#IF NOT %DEF(%MMC_ISnapinHelp2_INTERFACE_DEFINED)
    %MMC_ISnapinHelp2_INTERFACE_DEFINED = 1

$IID_MMC_ISnapinHelp2 = GUID$("{4861A010-20F9-11D2-A510-00C04FB6DD2C}")

INTERFACE MMC_ISnapinHelp2 $IID_MMC_ISnapinHelp2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISnapinHelp Method
   ' =====================================================================================
   METHOD GetHelpTopic ( _                              ' VTable offset = 12
     BYREF lpCompiledHelpFile AS DWORD _                ' __out LPOLESTR *lpCompiledHelpFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISnapinHelp2 Method
   ' =====================================================================================
   METHOD GetLinkedTopics ( _                           ' VTable offset = 16
     BYREF lpCompiledHelpFiles AS DWORD _               ' __out LPOLESTR *lpCompiledHelpFiles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_ISnapinHelp2_INTERFACE_DEFINED__ */


' enum MMC_TASK_DISPLAY_TYPE
%MMC_TASK_DISPLAY_UNINITIALIZED      = 0
%MMC_TASK_DISPLAY_TYPE_SYMBOL        = %MMC_TASK_DISPLAY_UNINITIALIZED      + 1
%MMC_TASK_DISPLAY_TYPE_VANILLA_GIF   = %MMC_TASK_DISPLAY_TYPE_SYMBOL        + 1
%MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF = %MMC_TASK_DISPLAY_TYPE_VANILLA_GIF   + 1
%MMC_TASK_DISPLAY_TYPE_BITMAP        = %MMC_TASK_DISPLAY_TYPE_CHOCOLATE_GIF + 1

' // Size = 12 bytes
TYPE MMC_TASK_DISPLAY_SYMBOL DWORD
   szFontFamilyName AS WSTRINGZ PTR   ' LPOLESTR
   szURLtoEOT       AS WSTRINGZ PTR   ' LPOLESTR
   szSymbolString   AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

' // Size = 8 bytes
TYPE MMC_TASK_DISPLAY_BITMAP DWORD
   szMouseOverBitmap AS WSTRINGZ PTR   ' LPOLESTR
   szMouseOffBitmap  AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

' // Size = 12 bytes
UNION MMC_TASK_DISPLAY_OBJECT_UNION DWORD
   uBitmap AS MMC_TASK_DISPLAY_BITMAP
   uSymbol AS MMC_TASK_DISPLAY_SYMBOL
END UNION

' // Size = 16 bytes
TYPE MMC_TASK_DISPLAY_OBJECT
   eDisplayType AS LONG   ' MMC_TASK_DISPLAY_TYPE
   MMC_TASK_DISPLAY_OBJECT_UNION
END TYPE

' enum MMC_ACTION_TYPE
%MMC_ACTION_UNINITIALIZED = -1
%MMC_ACTION_ID            = %MMC_ACTION_UNINITIALIZED + 1
%MMC_ACTION_LINK          = %MMC_ACTION_ID            + 1
%MMC_ACTION_SCRIPT        = %MMC_ACTION_LINK          + 1

' // Size = 4 bytes
UNION MMC_TASK_UNION DWORD
   nCommandID  AS LONG           ' LONG_PTR
   szActionURL AS WSTRINGZ PTR   ' LPOLESTR
   szScript    AS WSTRINGZ PTR   ' LPOLESTR
END UNION

' // Size = 32 bytes
TYPE MMC_TASK DWORD
   sDisplayObject AS MMC_TASK_DISPLAY_OBJECT
   szText       AS WSTRINGZ PTR   ' LPOLESTR
   szHelpString AS WSTRINGZ PTR   ' LPOLESTR
   eActionType  AS LONG           ' MMC_ACTION_TYPE
   MMC_TASK_UNION
END TYPE

' // Size = 12 bytes
TYPE MMC_LISTPAD_INFO DWORD
   szTitle      AS WSTRINGZ PTR   ' LPOLESTR
   szButtonText AS WSTRINGZ PTR   ' LPOLESTR
   nCommandID   AS LONG           ' LONG_PTR
END TYPE

'typedef DWORD MMC_STRING_ID;

' ########################################################################################
' IEnumTASK interface
' IID = 338698B1-5A02-11D1-9FEC-00600832DB4A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IEnumTASK_INTERFACE_DEFINED)
    %MMC_IEnumTASK_INTERFACE_DEFINED = 1

$IID_MMC_IEnumTASK = GUID$("{338698B1-5A02-11D1-9FEC-00600832DB4A}")

INTERFACE MMC_IEnumTASK $IID_MMC_IEnumTASK

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS MMC_TASK _                          ' __out MMC_TASK *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppenum AS MMC_IEnumTask _                    ' __out IEnumTASK **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IEnumTASK_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendTaskPad interface
' IID = 8DEE6511-554D-11D1-9FEA-00600832DB4A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendTaskPad_INTERFACE_DEFINED)
    %MMC_IExtendTaskPad_INTERFACE_DEFINED = 1

$IID_MMC_IExtendTaskPad = GUID$("{8DEE6511-554D-11D1-9FEA-00600832DB4A}")

INTERFACE MMC_IExtendTaskPad $IID_MMC_IExtendTaskPad

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TaskNotify ( _                                ' VTable offset = 12
     BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   , BYREF arg AS VARIANT _                             ' __in VARIANT *arg
   , BYREF param AS VARIANT _                           ' __in VARIANT *param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumTasks ( _                                 ' VTable offset = 16
     BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   , BYREF szTaskGroup AS WSTRINGZ _                    ' __in LPOLESTR szTaskGroup
   , BYREF ppEnumTASK AS MMC_IEnumTask _                ' __out IEnumTASK **ppEnumTASK
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 20
     BYREF pszGroup AS WSTRINGZ _                       ' __in LPOLESTR pszGroup
   , BYREF pszTitle AS DWORD _                          ' __out LPOLESTR *pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptiveText ( _                        ' VTable offset = 24
     BYREF pszGroup AS WSTRINGZ _                       ' __in LPOLESTR pszGroup
   , BYREF pszDescriptiveText AS DWORD _                ' __out LPOLESTR *pszDescriptiveText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackground ( _                             ' VTable offset = 28
     BYREF pszGroup AS WSTRINGZ _                       ' __in LPOLESTR pszGroup
   , BYREF pTDO AS MMC_TASK_DISPLAY_OBJECT _            ' __out MMC_TASK_DISPLAY_OBJECT *pTDO
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetListPadInfo ( _                            ' VTable offset = 32
     BYREF pszGroup AS WSTRINGZ _                       ' __in LPOLESTR pszGroup
   , BYREF lpListPadInfo AS MMC_LISTPAD_INFO _          ' __out MMC_LISTPAD_INFO *lpListPadInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendTaskPad_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsole2 interface
' IID = 103D842A-AA63-11D1-A7E1-00C04FD8D565
' Inherited interface = IConsole
' ########################################################################################

#IF NOT %DEF(%MMC_IConsole2_INTERFACE_DEFINED)
    %MMC_IConsole2_INTERFACE_DEFINED = 1

$IID_MMC_IConsole2 = GUID$("{103D842A-AA63-11D1-A7E1-00C04FD8D565}")

INTERFACE MMC_IConsole2 $IID_MMC_IConsole2

   INHERIT IUnknown

   ' =====================================================================================
   ' IConsole Methods
   ' =====================================================================================
   METHOD SetHeader ( _                                 ' VTable offset = 12
     BYVAL pHeader AS MMC_IHeaderCtrl _                 ' __in LPHEADERCTRL pHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetToolbar ( _                                ' VTable offset = 16
     BYVAL pToolbar AS MMC_IToolbar _                   ' __in LPTOOLBAR pToolbar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultView ( _                           ' VTable offset = 20
     BYREF pUnknown AS IUnknown _                       ' __out LPUNKNOWN *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryScopeImageList ( _                       ' VTable offset = 24
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultImageList ( _                      ' VTable offset = 28
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAllViews ( _                            ' VTable offset = 32
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL data AS LONG _                               ' __in LPARAM data
   , BYVAL hint AS LONG _                               ' __in LONG_PTR hint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MessageBox ( _                                ' VTable offset = 36
     BYREF lpszText AS WSTRINGZ _                       ' __in LPCWSTR lpszText
   , BYREF lpszTitle AS WSTRINGZ _                      ' __in LPCWSTR lpszTitle
   , BYVAL fuStyle AS DWORD _                           ' __in UINT fuStyle
   , BYREF piRetval AS LONG _                           ' __out int *piRetval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryConsoleVerb ( _                          ' VTable offset = 40
     BYREF ppConsoleVerb AS MMC_IConsoleVerb _          ' __out LPCONSOLEVERB *ppConsoleVerb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectScopeItem ( _                           ' VTable offset = 44
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMainWindow ( _                             ' VTable offset = 48
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewWindow ( _                                 ' VTable offset = 52
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   , BYVAL lOptions AS LONG _                           ' __in unsigned long lOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConsole2 Methods
   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 56
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYVAL bExpand AS LONG _                            ' __in BOOL bExpand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTaskpadViewPreferred ( _                    ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusText ( _                             ' VTable offset = 64
     BYREF pszStatusText AS WSTRINGZ _                  ' __in LPOLESTR pszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsole2_INTERFACE_DEFINED__ */

' ########################################################################################
' IDisplayHelp interface
' IID = CC593830-B926-11D1-8063-0000F875A9CE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IDisplayHelp_INTERFACE_DEFINED)
    %MMC_IDisplayHelp_INTERFACE_DEFINED = 1

$IID_MCM_IDisplayHelp = GUID$("{CC593830-B926-11D1-8063-0000F875A9CE}")

INTERFACE MCM_IDisplayHelp $IID_MCM_IDisplayHelp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowTopic ( _                                 ' VTable offset = 12
     BYREF pszHelpTopic AS WSTRINGZ _                   ' __in LPOLESTR pszHelpTopic
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IDisplayHelp_INTERFACE_DEFINED__ */

' ########################################################################################
' IRequiredExtensions interface
' IID = 72782D7A-A4A0-11D1-AF0F-00C04FB6DD2C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MCM_IRequiredExtensions_INTERFACE_DEFINED)
   %MCM_IRequiredExtensions_INTERFACE_DEFINED = 1

$IID_MCM_IRequiredExtensions = GUID$("{72782D7A-A4A0-11D1-AF0F-00C04FB6DD2C}")

INTERFACE MCM_IRequiredExtensions $IID_MCM_IRequiredExtensions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnableAllExtensions ( _                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstExtension ( _                         ' VTable offset = 16
     BYREF pExtCLSID AS GUID _                          ' __out LPCLSID pExtCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextExtension ( _                          ' VTable offset = 20
     BYREF pExtCLSID AS GUID _                          ' __out LPCLSID pExtCLSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MCM_IRequiredExtensions_INTERFACE_DEFINED__ */

' ########################################################################################
' IStringTable interface
' IID = DE40B7A4-0F65-11D2-8E25-00C04F8ECD78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MCM_IStringTable_INTERFACE_DEFINED)
    %MCM_IStringTable_INTERFACE_DEFINED = 1

$IID_MCM_IStringTable = GUID$("{DE40B7A4-0F65-11D2-8E25-00C04F8ECD78}")

INTERFACE MCM_IStringTable $IID_MCM_IStringTable

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddString ( _                                 ' VTable offset = 12
     BYREF pszAdd AS WSTRINGZ _                         ' __in LPCOLESTR pszAdd
   , BYREF pStringID AS DWORD _                         ' __out MMC_STRING_ID *pStringID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 16
     BYVAL StringID AS DWORD _                          ' __in MMC_STRING_ID StringID
   , BYVAL cchBuffer AS DWORD _                         ' __in ULONG cchBuffer
   , BYREF lpBuffer AS WSTRINGZ _                       ' __out LPOLESTR lpBuffer
   , BYREF pcchOut AS DWORD _                           ' __out ULONG *pcchOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 20
     BYVAL StringID AS DWORD _                          ' __in MMC_STRING_ID StringID
   , BYREF pcchString AS DWORD _                        ' __out ULONG *pcchString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteString ( _                              ' VTable offset = 24
     BYVAL StringID AS DWORD _                          ' __in MMC_STRING_ID StringID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllStrings ( _                          ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindString ( _                                ' VTable offset = 32
     BYREF pszFind AS WSTRINGZ _                        ' __in LPCOLESTR pszFind
   , BYREF pStringID AS DWORD _                         ' __out MMC_STRING_ID *pStringID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enumerate ( _                                 ' VTable offset = 36
     BYREF ppEnum AS IEnumString _                      ' __out IEnumString **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MCM_IStringTable_INTERFACE_DEFINED__ */


%HDI_HIDDEN   = &H1

' // Size = 16 bytes
TYPE MMC_COLUMN_DATA DWORD
   nColIndex  AS LONG    ' int
   dwFlags    AS DWORD   ' DWORD
   nWidth     AS LONG    ' int
   ulReserved AS DWORD   ' ULONG_PTR
END TYPE

' // Size = 12 bytes
TYPE MMC_COLUMN_SET_DATA DWORD
   cbSize   AS LONG   ' int
   nNumCols AS LONG   ' int
   pColData AS MMC_COLUMN_DATA PTR
END TYPE

' // Size = 12 bytes
TYPE MMC_SORT_DATA DWORD
   nColIndex     AS LONG    ' int
   dwSortOptions AS DWORD   ' DWORD
   ulReserved    AS DWORD   ' ULONG_PTR
END TYPE

' // Size = 12 bytes
TYPE MMC_SORT_SET_DATA DWORD
   cbSize    AS LONG   ' int
   nNumItems AS LONG   ' int
   pSortData AS MMC_SORT_DATA PTR
END TYPE

' ########################################################################################
' IColumnData interface
' IID = 547C1354-024D-11D3-A707-00C04F8EF4CB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IColumnData_INTERFACE_DEFINED)
    %MMC_IColumnData_INTERFACE_DEFINED = 1

$IID_MMC_IColumnData = GUID$("{547C1354-024D-11D3-A707-00C04F8EF4CB}")

INTERFACE MMC_IColumnData $IID_MMC_IColumnData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetColumnConfigData ( _                       ' VTable offset = 12
     BYREF pColID AS SColumnSetID _                     ' __in SColumnSetID *pColID
   , BYREF pColSetData AS MMC_COLUMN_SET_DATA _         ' __in MMC_COLUMN_SET_DATA *pColSetData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnConfigData ( _                       ' VTable offset = 16
     BYREF pColID AS SColumnSetID _                     ' __in SColumnSetID *pColID
   , BYREF ppColSetData AS MMC_COLUMN_SET_DATA _        ' __out MMC_COLUMN_SET_DATA **ppColSetData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumnSortData ( _                         ' VTable offset = 20
     BYREF pColID AS SColumnSetID _                     ' __in SColumnSetID *pColID
   , BYREF pColSortData AS MMC_SORT_SET_DATA _          ' __in MMC_SORT_SET_DATA *pColSortData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnSortData ( _                         ' VTable offset = 24
     BYREF pColID AS SColumnSetID _                     ' __in SColumnSetID *pColID
   , BYREF ppColSortData AS MMC_SORT_SET_DATA _         ' __out MMC_SORT_SET_DATA **ppColSortData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IColumnData_INTERFACE_DEFINED__ */

' ########################################################################################
' IMessageView interface
' IID = 80F94174-FCCC-11D2-B991-00C04F8ECD78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IMessageView_INTERFACE_DEFINED)
    %MMC_IMessageView_INTERFACE_DEFINED = 1

' enum tagIconIdentifier
%Icon_None        = 0
%Icon_Error       = 32513
%Icon_Question    = 32514
%Icon_Warning     = 32515
%Icon_Information = 32516
%Icon_First       = %Icon_Error
%Icon_Last        = %Icon_Information

$IID_MMC_IMessageView = GUID$("{80F94174-FCCC-11D2-B991-00C04F8ECD78}")

INTERFACE MMC_IMessageView $IID_MMC_IMessageView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTitleText ( _                              ' VTable offset = 12
     BYREF pszTitleText AS WSTRINGZ _                   ' __in LPCOLESTR pszTitleText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBodyText ( _                               ' VTable offset = 16
     BYREF pszBodyText AS WSTRINGZ _                    ' __in LPCOLESTR pszBodyText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIcon ( _                                   ' VTable offset = 20
     BYVAL id AS LONG _                                 ' __in IconIdentifier id
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IMessageView_INTERFACE_DEFINED__ */


' // Size = 12 bytes
TYPE RDITEMHDR DWORD
   dwFlags    AS DWORD   ' DWORD
   cookie     AS LONG    ' MMC_COOKIE
   lpReserved AS LONG    ' LPARAM
END TYPE

MACRO RDCITEMHDR = RDITEMHDR

%RDCI_ScopeItem   = &H80000000???

' // Size = 24 bytes
TYPE RDCOMPARE DWORD
   cbSize     AS DWORD          ' DWORD
   dwFlags    AS DWORD          ' DWORD
   nColumn    AS LONG           ' int
   lUserParam AS LONG           ' LPARAM
   prdch1     AS RDITEMHDR PTR
   prdch2     AS RDITEMHDR PTR
END TYPE

' ########################################################################################
' IResultDataCompareEx interface
' IID = 96933476-0251-11D3-AEB0-00C04F8ECD78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IResultDataCompareEx_INTERFACE_DEFINED)
    %MMC_IResultDataCompareEx_INTERFACE_DEFINED = 1

$IID_MMC_IResultDataCompareEx = GUID$("{96933476-0251-11D3-AEB0-00C04F8ECD78}")

INTERFACE MMC_IResultDataCompareEx $IID_MMC_IResultDataCompareEx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 12
     BYREF prdc AS RDCOMPARE _                          ' __in RDCOMPARE *prdc
   , BYREF pnResult AS LONG _                           ' __out int *pnResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IResultDataCompareEx_INTERFACE_DEFINED__ */

' enum MMC_VIEW_TYPE
%MMC_VIEW_TYPE_LIST = 0
%MMC_VIEW_TYPE_HTML = %MMC_VIEW_TYPE_LIST + 1
%MMC_VIEW_TYPE_OCX  = %MMC_VIEW_TYPE_HTML + 1

%RVTI_MISC_OPTIONS_NOLISTVIEWS                   = &H1
%RVTI_LIST_OPTIONS_NONE                          = &H0
%RVTI_LIST_OPTIONS_OWNERDATALIST                 = &H2
%RVTI_LIST_OPTIONS_MULTISELECT                   = &H4
%RVTI_LIST_OPTIONS_FILTERED                      = &H8
%RVTI_LIST_OPTIONS_USEFONTLINKING                = &H20
%RVTI_LIST_OPTIONS_EXCLUDE_SCOPE_ITEMS_FROM_LIST = &H40
%RVTI_LIST_OPTIONS_LEXICAL_SORT                  = &H80
%RVTI_LIST_OPTIONS_ALLOWPASTE                    = &H100
%RVTI_HTML_OPTIONS_NONE                          = &H0
%RVTI_HTML_OPTIONS_NOLISTVIEW                    = &H1
%RVTI_OCX_OPTIONS_NONE                           = &H0
%RVTI_OCX_OPTIONS_NOLISTVIEW                     = &H1
%RVTI_OCX_OPTIONS_CACHE_OCX                      = &H2

' // Size = 8 bytes
TYPE RESULT_VIEW_TYPE_INFO_UNION_STRUCT_1 DWORD
   dwHTMLOptions AS DWORD          ' DWORD
   pstrURL       AS WSTRINGZ PTR   ' LPOLESTR
END TYPE

' // Size = 8 bytes
TYPE RESULT_VIEW_TYPE_INFO_UNION_STRUCT_2 DWORD
   dwOCXOptions AS DWORD       ' DWORD
   pUnkControl  AS DWORD PTR   ' LPUNKNOWN
END TYPE

' // Size = 8 bytes
UNION RESULT_VIEW_TYPE_INFO_UNION DWORD
   dwListOptions AS DWORD   ' DWORD
   RESULT_VIEW_TYPE_INFO_UNION_STRUCT_1
   RESULT_VIEW_TYPE_INFO_UNION_STRUCT_2
END UNION

' // Size = 20 bytes
TYPE RESULT_VIEW_TYPE_INFO DWORD
   pstrPersistableViewDescription AS WSTRINGZ PTR   ' LPOLESTR
   eViewType                      AS LONG           ' MMC_VIEW_TYPE
   dwMiscOptions                  AS DWORD          ' DWORD
   RESULT_VIEW_TYPE_INFO_UNION
END TYPE

'#define   CCF_DESCRIPTION   ( L"CCF_DESCRIPTION" )
'#define   CCF_HTML_DETAILS   ( L"CCF_HTML_DETAILS" )
$$CCF_DESCRIPTION  = "CCF_DESCRIPTION"$$
$$CCF_HTML_DETAILS = "CCF_HTML_DETAILS"$$

' // Size = 28 bytes
TYPE CONTEXTMENUITEM2 DWORD
   strName                    AS WSTRINGZ PTR   ' LPWSTR
   strStatusBarText           AS WSTRINGZ PTR   ' LPWSTR
   lCommandID                 AS LONG           ' LONG
   lInsertionPointID          AS LONG           ' LONG
   fFlags                     AS LONG           ' LONG
   fSpecialFlags              AS LONG           ' LONG
   strLanguageIndependentName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 32 bytes
TYPE MMC_EXT_VIEW_DATA DWORD
   viewID               AS GUID           ' GUID
   pszURL               AS WSTRINGZ PTR   ' LPCOLESTR
   pszViewTitle         AS WSTRINGZ PTR   ' LPCOLESTR
   pszTooltipText       AS WSTRINGZ PTR   ' LPCOLESTR
   bReplacesDefaultView AS LONG           ' BOOL
END TYPE

%MMC_DEFAULT_OPERATION_COPY = &H1


' ########################################################################################
' IComponentData2 interface
' IID = CCA0F2D2-82DE-41B5-BF47-3B2076273D5C
' Inherited interface = IComponentData
' ########################################################################################

#IF NOT %DEF(%MMC_IComponentData2_INTERFACE_DEFINED)
    %MMC_IComponentData2_INTERFACE_DEFINED = 1

$IID_MMC_IComponentData2 = GUID$("{CCA0F2D2-82DE-41B5-BF47-3B2076273D5C}")

INTERFACE MMC_IComponentData2 $IID_MMC_IComponentData2

   INHERIT IUnknown

   ' =====================================================================================
   ' IComponentData Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pUnknown AS IUnknown _                       ' __in LPUNKNOWN pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateComponent ( _                           ' VTable offset = 16
     BYREF ppComponent AS MMC_IComponent _              ' LPCOMPONENT *ppComponent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 20
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL event AS DWORD _                             ' __in MMC_NOTIFY_TYPE event
   , BYVAL arg AS LONG _                                ' __in LPARAM arg
   , BYVAL param AS LONG _                              ' __in LPARAM param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDataObject ( _                           ' VTable offset = 28
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS LONG _                               ' __in DATA_OBJECT_TYPES type
   , BYREF ppDataObject AS IDataObject _                ' __out LPDATAOBJECT *ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayInfo ( _                            ' VTable offset = 32
      BYREF pScopeDataItem AS SCOPEDATAITEM _           ' __in_out SCOPEDATAITEM *pScopeDataItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareObjects ( _                            ' VTable offset = 36
     BYVAL lpDataObjectA AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectA
   , BYVAL lpDataObjectB AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IComponentData2 Methods
   ' =====================================================================================
   METHOD QueryDispatch ( _                             ' VTable offset = 40
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS DWORD _                              ' __in DATA_OBJECT_TYPES type
   , BYREF ppDispatch AS IDispatch _                    ' __out LPDISPATCH *ppDispatch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IComponentData2_INTERFACE_DEFINED__ */


' ########################################################################################
' IComponent2 interface
' IID = 79A2D615-4A10-4ED4-8C65-8633F9335095
' Inherited interface = IComponent
' ########################################################################################

#IF NOT %DEF(%MMC_IComponent2_INTERFACE_DEFINED)
    %MMC_IComponent2_INTERFACE_DEFINED = 1

$IID_MMC_IComponent2 = GUID$("{79A2D615-4A10-4ED4-8C65-8633F9335095}")

INTERFACE MMC_IComponent2 $IID_MMC_IComponent2

   INHERIT IUnknown

   ' =====================================================================================
   ' IComponent Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL lpConsole AS MMC_IConsole _                  ' __in LPCONSOLE lpConsole
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 16
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL event AS DWORD _                             ' __in MMC_NOTIFY_TYPE event
   , BYVAL arg AS LONG _                                ' __in LPARAM arg
   , BYVAL param AS LONG _                              ' __in LPARAM param
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 20
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDataObject ( _                           ' VTable offset = 24
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS LONG _                               ' __in DATA_OBJECT_TYPES type
   , BYREF ppDataObject AS IDataObject _                ' __out LPDATAOBJECT *ppDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultViewType ( _                         ' VTable offset = 28
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYREF ppViewType AS DWORD _                        ' __out LPOLESTR *ppViewType
   , BYREF pViewOptions AS LONG _                       ' __out long *pViewOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayInfo ( _                            ' VTable offset = 32
     BYREF pResultDataItem AS RESULTDATAITEM _          ' __in_out RESULTDATAITEM *pResultDataItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareObjects ( _                            ' VTable offset = 36
     BYVAL lpDataObjectA AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectA
   , BYVAL lpDataObjectB AS IDataObject _               ' __in LPDATAOBJECT lpDataObjectB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IComponent2 Methods
   ' =====================================================================================
   METHOD QueryDispatch ( _                             ' VTable offset = 40
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYVAL type AS DWORD _                              ' __in DATA_OBJECT_TYPES type
   , BYREF ppDispatch AS IDispatch _                    ' __out LPDISPATCH *ppDispatch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResultViewType2 ( _                        ' VTable offset = 44
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYREF pResultViewType AS RESULT_VIEW_TYPE_INFO _   ' __in_out PRESULT_VIEW_TYPE_INFO pResultViewType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreResultView ( _                         ' VTable offset = 48
     BYVAL cookie AS LONG _                             ' __in MMC_COOKIE cookie
   , BYREF pResultViewType AS RESULT_VIEW_TYPE_INFO _   ' __in PRESULT_VIEW_TYPE_INFO pResultViewType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IComponent2_INTERFACE_DEFINED__ */

' ########################################################################################
' IContextMenuCallback2 interface
' IID = E178BC0E-2ED0-4B5E-8097-42C9087E8B33
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IContextMenuCallback2_INTERFACE_DEFINED)
    %MMC_IContextMenuCallback2_INTERFACE_DEFINED = 1

$IID_MMC_IContextMenuCallback2 = GUID$("{E178BC0E-2ED0-4B5E-8097-42C9087E8B33}")

INTERFACE MMC_IContextMenuCallback2 $IID_MMC_IContextMenuCallback2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddItem ( _                                   ' VTable offset = 12
     BYREF pItem AS CONTEXTMENUITEM2 _                  ' __in CONTEXTMENUITEM2 *pItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IContextMenuCallback2_INTERFACE_DEFINED__ */

' ########################################################################################
' IMMCVersionInfo interface
' IID = A8D2C5FE-CDCB-4B9D-BDE5-A27343FF54BC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IMMCVersionInfo_INTERFACE_DEFINED)
    %MMC_IMMCVersionInfo_INTERFACE_DEFINED = 1

$IID_MMC_IMMCVersionInfo = GUID$("{A8D2C5FE-CDCB-4B9D-BDE5-A27343FF54BC}")

INTERFACE MMC_IMMCVersionInfo $IID_MMC_IMMCVersionInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMMCVersion ( _                             ' VTable offset = 12
     BYREF pVersionMajor AS LONG _                      ' __out long *pVersionMajor
   , BYREF pVersionMinor AS LONG _                      ' __out long *pVersionMinor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IMMCVersionInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtendView interface
' IID = 89995CEE-D2ED-4C0E-AE5E-DF7E76F3FA53
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IExtendView_INTERFACE_DEFINED)
    %MMC_IExtendView_INTERFACE_DEFINED = 1

$IID_MMC_IExtendView = GUID$("{89995CEE-D2ED-4C0E-AE5E-DF7E76F3FA53}")

INTERFACE MMC_IExtendView $IID_MMC_IExtendView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetViews ( _                                  ' VTable offset = 12
     BYVAL pDataObject AS IDataObject _                 ' __in LPDATAOBJECT pDataObject
   , BYVAL pViewExtensionCallback AS MMC_IViewExtensionCallback _ ' __in LPVIEWEXTENSIONCALLBACK pViewExtensionCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IExtendView_INTERFACE_DEFINED__ */

' ########################################################################################
' IViewExtensionCallback interface
' IID = 34DD928A-7599-41E5-9F5E-D6BC3062C2DA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IViewExtensionCallback_INTERFACE_DEFINED)
    %MMC_IViewExtensionCallback_INTERFACE_DEFINED = 1

$IID_MMC_IViewExtensionCallback = GUID$("{34DD928A-7599-41E5-9F5E-D6BC3062C2DA}")

INTERFACE MMC_IViewExtensionCallback $IID_MMC_IViewExtensionCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddView ( _                                   ' VTable offset = 12
     BYREF pExtViewData AS MMC_EXT_VIEW_DATA _          ' __in PMMC_EXT_VIEW_DATA pExtViewData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IViewExtensionCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsolePower interface
' IID = 1CFBDD0E-62CA-49CE-A3AF-DBB2DE61B068
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IConsolePower_INTERFACE_DEFINED)
    %MMC_IConsolePower_INTERFACE_DEFINED = 1

$IID_MMC_IConsolePower = GUID$("{1CFBDD0E-62CA-49CE-A3AF-DBB2DE61B068}")

INTERFACE MMC_IConsolePower $IID_MMC_IConsolePower

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetExecutionState ( _                         ' VTable offset = 12
     BYVAL dwAdd AS DWORD _                             ' __in DWORD dwAdd
   , BYVAL dwRemove AS DWORD _                          ' __in DWORD dwRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetIdleTimer ( _                            ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsolePower_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsolePowerSink interface
' IID = 3333759F-FE4F-4975-B143-FEC0A5DD6D65
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_IConsolePowerSink_INTERFACE_DEFINED)
    %MMC_IConsolePowerSink_INTERFACE_DEFINED = 1

$IID_MMC_IConsolePowerSink = GUID$("{3333759F-FE4F-4975-B143-FEC0A5DD6D65}")

INTERFACE MMC_IConsolePowerSink $IID_MMC_IConsolePowerSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnPowerBroadcast ( _                          ' VTable offset = 12
     BYVAL nEvent AS DWORD _                            ' __in UINT nEvent
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plReturn AS LONG _                           ' __out LRESULT *plReturn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConsolePowerSink_INTERFACE_DEFINED__ */

' ########################################################################################
' INodeProperties interface
' IID = 15BC4D24-A522-4406-AA55-0749537A6865
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%MMC_INodeProperties_INTERFACE_DEFINED)
    %MMC_INodeProperties_INTERFACE_DEFINED = 1

$IID_MMC_INodeProperties = GUID$("{15BC4D24-A522-4406-AA55-0749537A6865}")

INTERFACE MMC_INodeProperties $IID_MMC_INodeProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 12
     BYVAL pDataObject AS IDataObject _                 ' __in LPDATAOBJECT pDataObject
   , BYVAL szPropertyName AS WSTRING _                  ' __in BSTR szPropertyName
   , BYREF pbstrProperty AS WSTRING _                   ' __out PBSTR pbstrProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_INodeProperties_INTERFACE_DEFINED__ */

' ########################################################################################
' IConsole3 interface
' IID = 4F85EFDB-D0E1-498C-8D4A-D010DFDD404F
' Inherited interface = IConsole2
' ########################################################################################

#IF NOT %DEF(%MMC_IConsole3_INTERFACE_DEFINED)
    %MMC_IConsole3_INTERFACE_DEFINED = 1

$IID_MMC_IConsole3 = GUID$("{4F85EFDB-D0E1-498C-8D4A-D010DFDD404F}")

INTERFACE MMC_IConsole3 $IID_MMC_IConsole3

   INHERIT IUnknown

   ' =====================================================================================
   ' IConsole Methods
   ' =====================================================================================
   METHOD SetHeader ( _                                 ' VTable offset = 12
     BYVAL pHeader AS MMC_IHeaderCtrl _                 ' __in LPHEADERCTRL pHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetToolbar ( _                                ' VTable offset = 16
     BYVAL pToolbar AS MMC_IToolbar _                   ' __in LPTOOLBAR pToolbar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultView ( _                           ' VTable offset = 20
     BYREF pUnknown AS IUnknown _                       ' __out LPUNKNOWN *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryScopeImageList ( _                       ' VTable offset = 24
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryResultImageList ( _                      ' VTable offset = 28
     BYREF ppImageList AS MMC_IImageList _              ' __out LPIMAGELIST *ppImageList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAllViews ( _                            ' VTable offset = 32
     BYVAL lpDataObject AS IDataObject _                ' __in LPDATAOBJECT lpDataObject
   , BYVAL data AS LONG _                               ' __in LPARAM data
   , BYVAL hint AS LONG _                               ' __in LONG_PTR hint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MessageBox ( _                                ' VTable offset = 36
     BYREF lpszText AS WSTRINGZ _                       ' __in LPCWSTR lpszText
   , BYREF lpszTitle AS WSTRINGZ _                      ' __in LPCWSTR lpszTitle
   , BYVAL fuStyle AS DWORD _                           ' __in UINT fuStyle
   , BYREF piRetval AS LONG _                           ' __out int *piRetval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryConsoleVerb ( _                          ' VTable offset = 40
     BYREF ppConsoleVerb AS MMC_IConsoleVerb _          ' __out LPCONSOLEVERB *ppConsoleVerb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectScopeItem ( _                           ' VTable offset = 44
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMainWindow ( _                             ' VTable offset = 48
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewWindow ( _                                 ' VTable offset = 52
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   , BYVAL lOptions AS LONG _                           ' __in unsigned long lOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConsole2 Methods
   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 56
     BYVAL hItem AS LONG _                              ' __in HSCOPEITEM hItem
   , BYVAL bExpand AS LONG _                            ' __in BOOL bExpand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTaskpadViewPreferred ( _                    ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusText ( _                             ' VTable offset = 64
     BYREF pszStatusText AS WSTRINGZ _                  ' __in LPOLESTR pszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IConsole3 Methods
   ' =====================================================================================
   METHOD RenameScopeItem ( _                           ' VTable offset = 68
     BYVAL hScopeItem AS LONG _                         ' __in HSCOPEITEM hScopeItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IConsole3_INTERFACE_DEFINED__ */

' ########################################################################################
' IResultData2 interface
' IID = 0F36E0EB-A7F1-4A81-BE5A-9247F7DE4B1B
' Inherited interface = IResultData
' ########################################################################################

#IF NOT %DEF(%MMC_IResultData2_INTERFACE_DEFINED)
    %MMC_IResultData2_INTERFACE_DEFINED = 1

$IID_MMC_IResultData2 = GUID$("{0F36E0EB-A7F1-4A81-BE5A-9247F7DE4B1B}")

INTERFACE MMC_IResultData2 $IID_MMC_IResultData2

   INHERIT IUnknown

   ' =====================================================================================
   ' IResultData Methods
   ' =====================================================================================
   METHOD InsertItem ( _                                ' VTable offset = 12
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 16
     BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   , BYVAL nCol AS LONG _                               ' __in int nCol
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindItemByLParam ( _                          ' VTable offset = 20
     BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF pItemID AS LONG _                            ' __out HRESULTITEM *pItemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllRsltItems ( _                        ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 28
     BYREF item AS RESULTDATAITEM _                     ' __in LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 32
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 36
     BYREF item AS RESULTDATAITEM _                     ' __in_out LPRESULTDATAITEM item
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyItemState ( _                           ' VTable offset = 40
     BYVAL nIndex AS LONG _                             ' __in int nIndex
   , BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   , BYVAL uAdd AS DWORD _                              ' __in UINT uAdd
   , BYVAL uRemove AS DWORD _                           ' __in UINT uRemove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyViewStyle ( _                           ' VTable offset = 44
     BYVAL add AS DWORD _                               ' __in MMC_RESULT_VIEW_STYLE add
   , BYVAL remove AS DWORD _                            ' __in MMC_RESULT_VIEW_STYLE remove
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewMode ( _                               ' VTable offset = 48
     BYVAL lViewMode AS LONG _                          ' __in long lViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewMode ( _                               ' VTable offset = 52
     BYREF lViewMode AS LONG _                          ' __out long *lViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateItem ( _                                ' VTable offset = 56
     BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sort ( _                                      ' VTable offset = 60
     BYVAL nColumn AS LONG _                            ' __in int nColumn
   , BYVAL dwSortOptions AS DWORD _                     ' __in DWORD dwSortOptions
   , BYVAL lUserParam AS LONG _                         ' __in LPARAM lUserParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescBarText ( _                            ' VTable offset = 64
     BYREF DescText AS WSTRINGZ _                       ' __in LPOLESTR DescText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemCount ( _                              ' VTable offset = 68
     BYVAL nItemCount AS LONG _                         ' __in int nItemCount
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IResultData2 Methods
   ' =====================================================================================
   METHOD RenameResultItem ( _                          ' VTable offset = 72
     BYVAL itemID AS LONG _                             ' __in HRESULTITEM itemID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __MMC_IResultData2_INTERFACE_DEFINED__ */

' enum MMC_ITEM_OVERLAY
%MMC_ITEM_OVERLAY_NONE        = 0
%MMC_ITEM_OVERLAY_ERROR       = 1
%MMC_ITEM_OVERLAY_WARNING     = 2
%MMC_ITEM_OVERLAY_INFO        = 3
%MMC_ITEM_OVERLAY_BUSY        = 4
%MMC_ITEM_OVERLAY_UNAVAILABLE = 5
%MMC_ITEM_OVERLAY_SHORTCUT    = 6
%MMC_ITEM_OVERLAY_RUNNING     = 7
%MMC_ITEM_OVERLAY_PAUSED      = 8
%MMC_ITEM_OVERLAY_STOPPED     = 9
%MMC_ITEM_OVERLAY_COMPLETE    = 10

%MMC_ITEM_OVERLAY_STATE_MASK  = &Hf00???
%MMC_ITEM_OVERLAY_STATE_SHIFT = 8

'#define MMC_OVERLAY_ITEM_INDEX_TO_ITEM_STATE(i) (((i) << MMC_ITEM_OVERLAY_STATE_SHIFT) & MMC_ITEM_OVERLAY_STATE_MASK)
FUNCTION MMC_OVERLAY_ITEM_INDEX_TO_ITEM_STATE (BYVAL i AS DWORD) AS DWORD
   SHIFT LEFT i, %MMC_ITEM_OVERLAY_STATE_SHIFT
   FUNCTION = (i AND %MMC_ITEM_OVERLAY_STATE_MASK)
END FUNCTION

'#define MMC_OVERLAY_ITEM_INDEX_FROM_ITEM_STATE(state) (((state) & MMC_ITEM_OVERLAY_STATE_MASK) >> MMC_ITEM_OVERLAY_STATE_SHIFT)
FUNCTION MMC_OVERLAY_ITEM_INDEX_FROM_ITEM_STATE (BYVAL dwstate AS DWORD) AS DWORD
   dwstate = dwstate AND %MMC_ITEM_OVERLAY_STATE_MASK
   SHIFT RIGHT dwstate, %MMC_ITEM_OVERLAY_STATE_SHIFT
   FUNCTION = dwstate
END FUNCTION

%MMC_ITEM_STATE_MASK = &Hff???
