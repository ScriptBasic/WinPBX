' ########################################################################################
' Microsoft Windows
' File: OleAcc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEACC_INC = 1

#INCLUDE ONCE "ole2.inc"

'//=--------------------------------------------------------------------------=
'// Typedefs
'//=--------------------------------------------------------------------------=

'typedef LRESULT (STDAPICALLTYPE *LPFNLRESULTFROMOBJECT)(REFIID riid, WPARAM wParam, LPUNKNOWN punk);
'typedef HRESULT (STDAPICALLTYPE *LPFNOBJECTFROMLRESULT)(LRESULT lResult, REFIID riid, WPARAM wParam, void** ppvObject);
'typedef HRESULT (STDAPICALLTYPE *LPFNACCESSIBLEOBJECTFROMWINDOW)(HWND hwnd, DWORD dwId, REFIID riid, void** ppvObject);
'typedef HRESULT (STDAPICALLTYPE *LPFNACCESSIBLEOBJECTFROMPOINT)(POINT ptScreen, IAccessible** ppacc, VARIANT* pvarChild);
'typedef HRESULT (STDAPICALLTYPE *LPFNCREATESTDACCESSIBLEOBJECT)(HWND hwnd, LONG idObject, REFIID riid, void** ppvObject);
'typedef HRESULT (STDAPICALLTYPE *LPFNACCESSIBLECHILDREN)(IAccessible* paccContainer, LONG iChildStart,LONG cChildren,VARIANT* rgvarChildren,LONG* pcObtained);

'//=--------------------------------------------------------------------------=
'// GUIDs
'//=--------------------------------------------------------------------------=

$LIBID_Accessibility     = GUID$("{1EA4DBF0-3C3B-11CF-810C-00AA00389B71}")
$IID_IAccessible         = GUID$("{618736E0-3C3D-11CF-810C-00AA00389B71}")
$IID_IAccessibleHandler  = GUID$("{03022430-ABC4-11D0-BDE2-00AA001A1953}")
$IID_IAccIdentity        = GUID$("{7852B78D-1CFD-41C1-A615-9C0C85960B5F}")
$IID_IAccPropServer      = GUID$("{76C0DBBB-15E0-4E7B-B61B-20EEEA2001E0}")
$IID_IAccPropServices    = GUID$("{6E26E776-04F0-495D-80E4-3330352E3169}")
$IID_IAccPropMgrInternal = GUID$("{2BD370A9-3E7F-4EDD-8A85-F8FED1F8E51F}")
$CLSID_CAccPropServices  = GUID$("{B5F8350B-0548-48B1-A6EE-88BD00B4A5E7}")
$IIS_IsOleaccProxy       = GUID$("{902697FA-80E4-4560-802A-A13F22A64709}")

'//=--------------------------------------------------------------------------=
'// MSAA API Prototypes
'//=--------------------------------------------------------------------------=

DECLARE FUNCTION LresultFromObject IMPORT "OLEACC.DLL" ALIAS "LresultFromObject" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL pAcc AS IUnknown _                             ' __in LPUNKNOWN pAcc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ObjectFromLresult IMPORT "OLEACC.DLL" ALIAS "ObjectFromLresult" ( _
   BYVAL lResult AS LONG _                              ' __in  LRESULT lResult
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYVAL wParam AS DWORD _                              ' __in  WPARAM wParam
 , BYREF ppvObject AS ANY _                             ' __out void** ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION WindowFromAccessibleObject IMPORT "OLEACC.DLL" ALIAS "WindowFromAccessibleObject" ( _
   BYVAL pacc AS IAccessible _                          ' __in  IAccessible* pacc
 , BYREF phwnd AS DWORD _                               ' __out HWND* phwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AccessibleObjectFromWindow IMPORT "OLEACC.DLL" ALIAS "AccessibleObjectFromWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL dwObjectID AS DWORD _                          ' __in  DWORD dwObjectID
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObject AS ANY _                             ' __out void** ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AccessibleObjectFromEvent IMPORT "OLEACC.DLL" ALIAS "AccessibleObjectFromEvent" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL dwObjectID AS DWORD _                          ' __in  DWORD dwObjectID
 , BYVAL dwChildID AS DWORD _                           ' __in  DWORD dwChildID
 , BYREF ppacc AS IAccessible _                         ' __out IAccessible** ppacc
 , BYREF pvarChild AS VARIANT _                         ' __in  VARIANT* pvarChild
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AccessibleObjectFromPoint IMPORT "OLEACC.DLL" ALIAS "AccessibleObjectFromPoint" ( _
   BYVAL ptScreen AS POINT _                            ' __in  POINT ptScreen
 , BYREF ppacc AS IAccessible _                         ' __out IAccessible** ppacc
 , BYREF pvarChild AS VARIANT _                         ' __out VARIANT* pvarChild
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AccessibleChildren IMPORT "OLEACC.DLL" ALIAS "AccessibleChildren" ( _
   BYVAL paccContainer AS IAccessible _                 ' __in  IAccessible* paccContainer
 , BYVAL iChildStart AS LONG _                          ' __in  LONG iChildStart
 , BYVAL cChildren AS LONG _                            ' __in  LONG cChildren
 , BYREF rgvarChildren AS ANY _                         ' __out VARIANT* rgvarChildren
 , BYREF pcObtained AS LONG _                           ' __out LONG* pcObtained
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetRoleTextA IMPORT "OLEACC.DLL" ALIAS "GetRoleTextA" ( _
   BYVAL dwRole AS DWORD _                              ' __in  DWORD dwRole
 , BYREF lpszRole AS ASCIIZ _                           ' __out LPSTR lpszRole
 , BYVAL cchRoleMax AS DWORD _                          ' __in  UINT cchRoleMax
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetRoleTextW IMPORT "OLEACC.DLL" ALIAS "GetRoleTextW" ( _
   BYVAL dwRole AS DWORD _                              ' __in  DWORD dwRole
 , BYREF lpszRole AS WSTRINGZ _                         ' __out LPWSTR lpszRole
 , BYVAL cchRoleMax AS DWORD _                          ' __in  UINT cchRoleMax
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetRoleText = GetRoleTextW
#ELSE
   MACRO GetRoleText = GetRoleTextA
#ENDIF

DECLARE FUNCTION GetStateTextA IMPORT "OLEACC.DLL" ALIAS "GetStateTextA" ( _
   BYVAL dwStateBit AS DWORD _                          ' __in  DWORD dwStateBit
 , BYREF lpszStateBit AS ASCIIZ _                       ' __out LPSTR lpszStateBit
 , BYVAL cchStateBitMax AS DWORD _                      ' __in  UINT cchStateBitMax
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION GetStateTextW IMPORT "OLEACC.DLL" ALIAS "GetStateTextW" ( _
   BYVAL dwStateBit AS DWORD _                          ' __in  DWORD dwStateBit
 , BYREF lpszStateBit AS WSTRINGZ _                     ' __out LPWSTR lpszStateBit
 , BYVAL cchStateBitMax AS DWORD _                      ' __in  UINT cchStateBitMax
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO GetStateText = GetStateTextW
#ELSE
   MACRO GetStateText = GetStateTextA
#ENDIF

DECLARE SUB GetOleaccVersionInfo IMPORT "OLEACC.DLL" ALIAS "GetOleaccVersionInfo" ( _
   BYREF pdwVer AS DWORD _                              ' __out DWORD* pdwVer
 , BYREF pdwBuild AS DWORD _                            ' __out DWORD* pdwBuild
 )                                                      ' void

DECLARE FUNCTION CreateStdAccessibleObject IMPORT "OLEACC.DLL" ALIAS "CreateStdAccessibleObject" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYVAL idObject AS LONG _                             ' __in  LONG idObject
 , BYREF riidInterface AS GUID _                        ' __out REFIID riidInterface
 , BYREF ppvObject AS ANY _                             ' __out void** ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateStdAccessibleProxyA IMPORT "OLEACC.DLL" ALIAS "CreateStdAccessibleProxyA" ( _
   BYVAL hwnd AS DWORD _                                ' __in  HWND hwnd
 , BYREF pszClassName AS ASCIIZ _                       ' __in  LPCSTR pszClassName
 , BYVAL idObject AS LONG _                             ' __in  LONG idObject
 , BYREF riidInterface AS GUID _                        ' __in  REFIID riidInterface
 , BYREF ppvObject AS ANY _                             ' __out void** ppvObject
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateStdAccessibleProxyW IMPORT "OLEACC.DLL" ALIAS "CreateStdAccessibleProxyW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszClassName AS WSTRINGZ _                     ' __in LPCWSTR pszClassName
 , BYVAL idObject AS LONG _                             ' __in LONG idObject
 , BYREF riidInterface AS GUID _                        ' __in REFIID riidInterface
 , BYREF ppvObject AS ANY _                             ' __out void** ppvObject
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO CreateStdAccessibleProxy = CreateStdAccessibleProxyW
#ELSE
   MACRO CreateStdAccessibleProxy = CreateStdAccessibleProxyA
#ENDIF

' // Documented, but not included in OleAcc.h
DECLARE FUNCTION GetProcessHandleFromHwnd IMPORT "OLEACC.DLL" ALIAS "GetProcessHandleFromHwnd" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' HANDLE

'// Simple Owner-Drawn Menu support...

%MSAA_MENU_SIG = &HAA0DF00D???

'// Menu's dwItemData should point to one of these structs:
'// (or can point to an app-defined struct containing this as the first member)

' // Size = 12 bytes
TYPE MSAAMENUINFO DWORD
   dwMSAASignature AS DWORD  ' // Must be MSAA_MENU_SIG
   cchWText        AS DWORD  ' // Length of text, in Unicode characters, excluding terminating NUL
   pszWText        AS DWORD  ' // NUL-terminated text, in Unicode
END TYPE


'//=--------------------------------------------------------------------------=
'// Property GUIDs (used by annotation interfaces)
'//=--------------------------------------------------------------------------=

$PROPID_ACC_NAME             = GUID$("{608D3DF8-8128-4AA7-A428-F55E49267291}")
$PROPID_ACC_VALUE            = GUID$("{123FE443-211A-4615-9527-C45A7E93717A}")
$PROPID_ACC_DESCRIPTION      = GUID$("{4D48DFE4-BD3F-491F-A648-492D6F20C588}")
$PROPID_ACC_ROLE             = GUID$("{CB905FF2-7BD1-4C05-B3C8-E6C241364D70}")
$PROPID_ACC_STATE            = GUID$("{A8D4D5B0-0A21-42D0-A5C0-514E984F457B}")
$PROPID_ACC_HELP             = GUID$("{C831E11F-44DB-4A99-9768-CB8F978B7231}")
$PROPID_ACC_KEYBOARDSHORTCUT = GUID$("{7D9BCEEE-7D1E-4979-9382-5180F4172C34}")
$PROPID_ACC_DEFAULTACTION    = GUID$("{180C072B-C27F-43C7-9922-F63562A4632B}")

$PROPID_ACC_HELPTOPIC        = GUID$("{787D1379-8EDE-440B-8AEC-11F7BF9030B3}")
$PROPID_ACC_FOCUS            = GUID$("{6EB335DF-1C29-4127-B12C-DEE9FD157F2B}")
$PROPID_ACC_SELECTION        = GUID$("{B99D073C-D731-405B-9061-D95E8F842984}")
$PROPID_ACC_PARENT           = GUID$("{474C22B6-FFC2-467A-B1B5-E958B4657330}")

$PROPID_ACC_NAV_UP           = GUID$("{016E1A2B-1A4E-4767-8612-3386F66935EC}")
$PROPID_ACC_NAV_DOWN         = GUID$("{031670ED-3CDF-48D2-9613-138F2DD8A668}")
$PROPID_ACC_NAV_LEFT         = GUID$("{228086CB-82F1-4A39-8705-DCDC0FFF92F5}")
$PROPID_ACC_NAV_RIGHT        = GUID$("{CD211D9F-E1CB-4FE5-A77C-920B884D095B}")
$PROPID_ACC_NAV_PREV         = GUID$("{776D3891-C73B-4480-B3F6-076A16A15AF6}")
$PROPID_ACC_NAV_NEXT         = GUID$("{1CDC5455-8CD9-4C92-A371-3939A2FE3EEE}")
$PROPID_ACC_NAV_FIRSTCHILD   = GUID$("{CFD02558-557B-4C67-84F9-2A09FCE40749}")
$PROPID_ACC_NAV_LASTCHILD    = GUID$("{302ECAA5-48D5-4F8D-B671-1A8D20A77832}")

'// Value map, used by sliders and other controls...
$PROPID_ACC_ROLEMAP          = GUID$("{F79ACDA2-140D-4FE6-8914-208476328269}")
$PROPID_ACC_VALUEMAP         = GUID$("{DA1C3D79-FC5C-420E-B399-9D1533549E75}")
$PROPID_ACC_STATEMAP         = GUID$("{43946C5E-0AC0-4042-B525-07BBDBE17FA7}")
$PROPID_ACC_DESCRIPTIONMAP   = GUID$("{1FF1435F-8A14-477B-B226-A0ABE279975D}")

$PROPID_ACC_DODEFAULTACTION  = GUID$("{1BA09523-2E3B-49A6-A059-59682A3C48FD}")

'//=--------------------------------------------------------------------------=
'// Interface Definitions
'//=--------------------------------------------------------------------------=

#IF NOT %DEF(%IAccessible_INTERFACE_DEFINED)
    %IAccessible_INTERFACE_DEFINED = 1

%DISPID_ACC_PARENT              = -5000
%DISPID_ACC_CHILDCOUNT          = -5001
%DISPID_ACC_CHILD               = -5002
%DISPID_ACC_NAME                = -5003
%DISPID_ACC_VALUE               = -5004
%DISPID_ACC_DESCRIPTION         = -5005
%DISPID_ACC_ROLE                = -5006
%DISPID_ACC_STATE               = -5007
%DISPID_ACC_HELP                = -5008
%DISPID_ACC_HELPTOPIC           = -5009
%DISPID_ACC_KEYBOARDSHORTCUT    = -5010
%DISPID_ACC_FOCUS               = -5011
%DISPID_ACC_SELECTION           = -5012
%DISPID_ACC_DEFAULTACTION       = -5013
%DISPID_ACC_SELECT              = -5014
%DISPID_ACC_LOCATION            = -5015
%DISPID_ACC_NAVIGATE            = -5016
%DISPID_ACC_HITTEST             = -5017
%DISPID_ACC_DODEFAULTACTION     = -5018

%NAVDIR_MIN                     = 0
%NAVDIR_UP                      = &H1
%NAVDIR_DOWN                    = &H2
%NAVDIR_LEFT                    = &H3
%NAVDIR_RIGHT                   = &H4
%NAVDIR_NEXT                    = &H5
%NAVDIR_PREVIOUS                = &H6
%NAVDIR_FIRSTCHILD              = &H7
%NAVDIR_LASTCHILD               = &H8
%NAVDIR_MAX                     = &H9

%SELFLAG_NONE                   = 0
%SELFLAG_TAKEFOCUS              = &H1
%SELFLAG_TAKESELECTION          = &H2
%SELFLAG_EXTENDSELECTION        = &H4
%SELFLAG_ADDSELECTION           = &H8
%SELFLAG_REMOVESELECTION        = &H10
%SELFLAG_VALID                  = &H1f

#IF NOT %DEF(%STATE_SYSTEM_UNAVAILABLE)
%STATE_SYSTEM_NORMAL            = 0
%STATE_SYSTEM_UNAVAILABLE       = &H00000001???  ' Disabled
%STATE_SYSTEM_SELECTED          = &H00000002???
%STATE_SYSTEM_FOCUSED           = &H00000004???
%STATE_SYSTEM_PRESSED           = &H00000008???
%STATE_SYSTEM_CHECKED           = &H00000010???
%STATE_SYSTEM_MIXED             = &H00000020???  ' 3-state checkbox or toolbar button
%STATE_SYSTEM_INDETERMINATE     = %STATE_SYSTEM_MIXED
%STATE_SYSTEM_READONLY          = &H00000040???
%STATE_SYSTEM_HOTTRACKED        = &H00000080???
%STATE_SYSTEM_DEFAULT           = &H00000100???
%STATE_SYSTEM_EXPANDED          = &H00000200???
%STATE_SYSTEM_COLLAPSED         = &H00000400???
%STATE_SYSTEM_BUSY              = &H00000800???
%STATE_SYSTEM_FLOATING          = &H00001000???  ' Children "owned" not "contained" by parent
%STATE_SYSTEM_MARQUEED          = &H00002000???
%STATE_SYSTEM_ANIMATED          = &H00004000???
%STATE_SYSTEM_INVISIBLE         = &H00008000???
%STATE_SYSTEM_OFFSCREEN         = &H00010000???
%STATE_SYSTEM_SIZEABLE          = &H00020000???
%STATE_SYSTEM_MOVEABLE          = &H00040000???
%STATE_SYSTEM_SELFVOICING       = &H00080000???
%STATE_SYSTEM_FOCUSABLE         = &H00100000???
%STATE_SYSTEM_SELECTABLE        = &H00200000???
%STATE_SYSTEM_LINKED            = &H00400000???
%STATE_SYSTEM_TRAVERSED         = &H00800000???
%STATE_SYSTEM_MULTISELECTABLE   = &H01000000???  ' Supports multiple selection
%STATE_SYSTEM_EXTSELECTABLE     = &H02000000???  ' Supports extended selection
%STATE_SYSTEM_ALERT_LOW         = &H04000000???  ' This information is of low priority
%STATE_SYSTEM_ALERT_MEDIUM      = &H08000000???  ' This information is of medium priority
%STATE_SYSTEM_ALERT_HIGH        = &H10000000???  ' This information is of high priority
%STATE_SYSTEM_PROTECTED         = &H20000000???  ' access to this is restricted
%STATE_SYSTEM_VALID             = &H7FFFFFFF???
#ENDIF   ' #IF NOT %DEF(%STATE_SYSTEM_UNAVAILABLE)

#IF NOT %DEF(%STATE_SYSTEM_HASPOPUP)
%STATE_SYSTEM_HASPOPUP          = &H40000000???
#ENDIF   ' //STATE_SYSTEM_HASPOPUP

%ROLE_SYSTEM_TITLEBAR           = &H1
%ROLE_SYSTEM_MENUBAR            = &H2
%ROLE_SYSTEM_SCROLLBAR          = &H3
%ROLE_SYSTEM_GRIP               = &H4
%ROLE_SYSTEM_SOUND              = &H5
%ROLE_SYSTEM_CURSOR             = &H6
%ROLE_SYSTEM_CARET              = &H7
%ROLE_SYSTEM_ALERT              = &H8
%ROLE_SYSTEM_WINDOW             = &H9
%ROLE_SYSTEM_CLIENT             = &Ha
%ROLE_SYSTEM_MENUPOPUP          = &Hb
%ROLE_SYSTEM_MENUITEM           = &Hc
%ROLE_SYSTEM_TOOLTIP            = &Hd
%ROLE_SYSTEM_APPLICATION        = &He
%ROLE_SYSTEM_DOCUMENT           = &Hf
%ROLE_SYSTEM_PANE               = &H10
%ROLE_SYSTEM_CHART              = &H11
%ROLE_SYSTEM_DIALOG             = &H12
%ROLE_SYSTEM_BORDER             = &H13
%ROLE_SYSTEM_GROUPING           = &H14
%ROLE_SYSTEM_SEPARATOR          = &H15
%ROLE_SYSTEM_TOOLBAR            = &H16
%ROLE_SYSTEM_STATUSBAR          = &H17
%ROLE_SYSTEM_TABLE              = &H18
%ROLE_SYSTEM_COLUMNHEADER       = &H19
%ROLE_SYSTEM_ROWHEADER          = &H1a
%ROLE_SYSTEM_COLUMN             = &H1b
%ROLE_SYSTEM_ROW                = &H1c
%ROLE_SYSTEM_CELL               = &H1d
%ROLE_SYSTEM_LINK               = &H1e
%ROLE_SYSTEM_HELPBALLOON        = &H1f
%ROLE_SYSTEM_CHARACTER          = &H20
%ROLE_SYSTEM_LIST               = &H21
%ROLE_SYSTEM_LISTITEM           = &H22
%ROLE_SYSTEM_OUTLINE            = &H23
%ROLE_SYSTEM_OUTLINEITEM        = &H24
%ROLE_SYSTEM_PAGETAB            = &H25
%ROLE_SYSTEM_PROPERTYPAGE       = &H26
%ROLE_SYSTEM_INDICATOR          = &H27
%ROLE_SYSTEM_GRAPHIC            = &H28
%ROLE_SYSTEM_STATICTEXT         = &H29
%ROLE_SYSTEM_TEXT               = &H2a
%ROLE_SYSTEM_PUSHBUTTON         = &H2b
%ROLE_SYSTEM_CHECKBUTTON        = &H2c
%ROLE_SYSTEM_RADIOBUTTON        = &H2d
%ROLE_SYSTEM_COMBOBOX           = &H2e
%ROLE_SYSTEM_DROPLIST           = &H2f
%ROLE_SYSTEM_PROGRESSBAR        = &H30
%ROLE_SYSTEM_DIAL               = &H31
%ROLE_SYSTEM_HOTKEYFIELD        = &H32
%ROLE_SYSTEM_SLIDER             = &H33
%ROLE_SYSTEM_SPINBUTTON         = &H34
%ROLE_SYSTEM_DIAGRAM            = &H35
%ROLE_SYSTEM_ANIMATION          = &H36
%ROLE_SYSTEM_EQUATION           = &H37
%ROLE_SYSTEM_BUTTONDROPDOWN     = &H38
%ROLE_SYSTEM_BUTTONMENU         = &H39
%ROLE_SYSTEM_BUTTONDROPDOWNGRID = &H3a
%ROLE_SYSTEM_WHITESPACE         = &H3b
%ROLE_SYSTEM_PAGETABLIST        = &H3c
%ROLE_SYSTEM_CLOCK              = &H3d
%ROLE_SYSTEM_SPLITBUTTON        = &H3e
%ROLE_SYSTEM_IPADDRESS          = &H3f
%ROLE_SYSTEM_OUTLINEBUTTON      = &H40

' ########################################################################################
' Interface name = IAccessible
' IID = {618736E0-3C3D-11CF-810C-00AA00389B71}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAccessible $IID_IAccessible

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET accParent <-5000> ( _                   ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdispParent
   ' =====================================================================================
   PROPERTY GET accChildCount <-5001> ( _               ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pcountChildren
   ' =====================================================================================
   PROPERTY GET accChild <-5002> ( _                    ' VTable offset = 36
     BYVAL varChild AS VARIANT _                        ' __in VARIANT varChild
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdispChild
   ' =====================================================================================
   PROPERTY GET accName <-5003> ( _                     ' VTable offset = 40
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszName
   ' =====================================================================================
   PROPERTY GET accValue <-5004> ( _                    ' VTable offset = 44
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszValue
   ' =====================================================================================
   PROPERTY GET accDescription <-5005> ( _              ' VTable offset = 48
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszDescription
   ' =====================================================================================
   PROPERTY GET accRole <-5006> ( _                     ' VTable offset = 52
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRole
   ' =====================================================================================
   PROPERTY GET accState <-5007> ( _                    ' VTable offset = 56
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarState
   ' =====================================================================================
   PROPERTY GET accHelp <-5008> ( _                     ' VTable offset = 60
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszHelp
   ' =====================================================================================
   PROPERTY GET accHelpTopic <-5009> ( _                ' VTable offset = 64
     BYREF IN pszHelpFile AS WSTRING _                  ' __out BSTR *pszHelpFile
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS LONG                                            ' __retval_out long *pidTopic
   ' =====================================================================================
   PROPERTY GET accKeyboardShortcut <-5010> ( _         ' VTable offset = 68
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszKeyboardShortcut
   ' =====================================================================================
   PROPERTY GET accFocus <-5011> ( _                    ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChild
   ' =====================================================================================
   PROPERTY GET accSelection <-5012> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChildren
   ' =====================================================================================
   PROPERTY GET accDefaultAction <-5013> ( _            ' VTable offset = 80
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   ) AS WSTRING                                         ' __retval_out BSTR *pszDefaultAction
   ' =====================================================================================
   METHOD accSelect <-5014> ( _                         ' VTable offset = 84
     BYVAL flagsSelect AS LONG _                        ' __in long flagsSelect
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   METHOD accLocation <-5015> ( _                       ' VTable offset = 88
     BYREF pxLeft AS LONG _                             ' __out long *pxLeft
   , BYREF pyTop AS LONG _                              ' __out long *pyTop
   , BYREF pcxWidth AS LONG _                           ' __out long *pcxWidth
   , BYREF pcyHeight AS LONG _                          ' __out long *pcyHeight
   , OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   METHOD accNavigate <-5016> ( _                       ' VTable offset = 92
     BYVAL navDir AS LONG _                             ' __in long navDir
   , OPTIONAL BYVAL varStart AS VARIANT _               ' __opt_in VARIANT varStart
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarEndUpAt
   ' =====================================================================================
   METHOD accHitTest <-5017> ( _                        ' VTable offset = 96
     BYVAL xLeft AS LONG _                              ' __in long xLeft
   , BYVAL yTop AS LONG _                               ' __in long yTop
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarChild
   ' =====================================================================================
   METHOD accDoDefaultAction <-5018> ( _                ' VTable offset = 100
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET accName <-5003> ( _                     ' VTable offset = 104
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   , BYVAL szName AS WSTRING _                          ' __in BSTR szName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET accValue <-5004> ( _                    ' VTable offset = 108
     OPTIONAL BYVAL varChild AS VARIANT _               ' __opt_in VARIANT varChild
   , BYVAL szValue AS WSTRING _                         ' __in BSTR szValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessible_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccessibleHandler
' IID = {03022430-ABC4-11D0-BDE2-00AA001A1953}
' Attributes = 272 [&H110] [Hidden] [Oleautomation]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccessibleHandler_INTERFACE_DEFINED)
    %IAccessibleHandler_INTERFACE_DEFINED = 1

INTERFACE IAccessibleHandler $IID_IAccessibleHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AccessibleObjectFromID ( _                    ' VTable offset = 12
     BYVAL hwnd AS LONG _                               ' __in long hwnd
   , BYVAL lObjectID AS LONG _                          ' __in long lObjectID
   , BYREF pIAccessible AS IAccessible _                ' __out LPACCESSIBLE *pIAccessible
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessibleHandler_INTERFACE_DEFINED__ */


' AnnoScope enum
%ANNO_THIS      = 0
%ANNO_CONTAINER = 1

'typedef GUID MSAAPROPID;

' ########################################################################################
' Interface name = IAccIdentity
' IID = {7852B78D-1CFD-41C1-A615-9C0C85960B5F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccIdentity_INTERFACE_DEFINED)
    %IAccIdentity_INTERFACE_DEFINED = 1

INTERFACE IAccIdentity $IID_IAccIdentity

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIdentityString ( _                         ' VTable offset = 12
     BYVAL dwIDChild AS DWORD _                         ' __in DWORD dwIDChild
   , BYREF ppIDString AS DWORD _                        ' __out BYTE **ppIDString
   , BYREF pdwIDStringLen AS DWORD _                    ' __out DWORD *pdwIDStringLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccIdentity_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccPropServer
' IID = {76C0DBBB-15E0-4E7B-B61B-20EEEA2001E0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccPropServer_INTERFACE_DEFINED)
    %IAccPropServer_INTERFACE_DEFINED = 1

INTERFACE IAccPropServer $IID_IAccPropServer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPropValue ( _                              ' VTable offset = 12
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYREF pvarValue AS VARIANT _                       ' __out VARIANT *pvarValue
   , BYREF pfHasProp AS LONG _                          ' __out BOOL *pfHasProp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccPropServer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAccPropServices
' IID = {6E26E776-04F0-495D-80E4-3330352E3169}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccPropServices_INTERFACE_DEFINED)
    %IAccPropServices_INTERFACE_DEFINED = 1

INTERFACE IAccPropServices $IID_IAccPropServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPropValue ( _                              ' VTable offset = 12
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropServer ( _                             ' VTable offset = 16
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   , BYVAL pServer AS IAccPropServer _                  ' __in IAccPropServer *pServer
   , BYVAL annoScope AS LONG _                          ' __in AnnoScope annoScope
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearProps ( _                                ' VTable offset = 20
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHwndProp ( _                               ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS DWORD _                          ' __in DWORD idObject
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHwndPropStr ( _                            ' VTable offset = 28
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS DWORD _                          ' __in DWORD idObject
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYREF str AS WSTRINGZ _                            ' __in LPCWSTR str
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHwndPropServer ( _                         ' VTable offset = 32
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS DWORD _                          ' __in DWORD idObject
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   , BYVAL pServer AS IAccPropServer _                  ' __in IAccPropServer *pServer
   , BYVAL annoScope AS LONG _                          ' __in AnnoScope annoScope
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearHwndProps ( _                            ' VTable offset = 36
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS DWORD _                          ' __in DWORD idObject
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComposeHwndIdentityString ( _                 ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL idObject AS DWORD _                          ' __in DWORD idObject
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF ppIDString AS DWORD _                        ' __out BYTE **ppIDString
   , BYREF pdwIDStringLen AS DWORD _                    ' __out DWORD *pdwIDStringLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecomposeHwndIdentityString ( _               ' VTable offset = 44
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF pidObject AS DWORD _                         ' __out DWORD *pidObject
   , BYREF pidChild AS DWORD _                          ' __out DWORD *pidChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHmenuProp ( _                              ' VTable offset = 48
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYVAL var AS VARIANT _                             ' __in VARIANT var
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHmenuPropStr ( _                           ' VTable offset = 52
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYVAL idProp AS GUID _                             ' __in MSAAPROPID idProp
   , BYREF str AS WSTRINGZ _                            ' __in LPCWSTR str
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHmenuPropServer ( _                        ' VTable offset = 56
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   , BYVAL pServer AS IAccPropServer _                  ' __in IAccPropServer *pServer
   , BYVAL annoScope AS LONG _                          ' __in AnnoScope annoScope
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearHmenuProps ( _                           ' VTable offset = 60
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF paProps AS GUID _                            ' __in const MSAAPROPID *paProps
   , BYVAL cProps AS LONG _                             ' __in int cProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ComposeHmenuIdentityString ( _                ' VTable offset = 64
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL idChild AS DWORD _                           ' __in DWORD idChild
   , BYREF ppIDString AS DWORD _                        ' __out BYTE **ppIDString
   , BYREF pdwIDStringLen AS DWORD _                    ' __out DWORD *pdwIDStringLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DecomposeHmenuIdentityString ( _              ' VTable offset = 68
     BYVAL pIDString AS BYTE PTR _                      ' __in const BYTE *pIDString
   , BYVAL dwIDStringLen AS DWORD _                     ' __in DWORD dwIDStringLen
   , BYREF phmenu AS DWORD _                            ' __out HMENU *phmenu
   , BYREF pidChild AS DWORD _                          ' __out DWORD *pidChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccPropServices_INTERFACE_DEFINED__ */
