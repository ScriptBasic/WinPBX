' ########################################################################################
' Microsoft Windows
' File: ExDisp.inc
' Library name: SHDocVw
' Version: 1.1, Locale ID = 0
' Library GUID: {EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}
' Path: C:\Windows\System32\ieframe.dll
' Contents: Microsoft Internet Controls
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EXDISP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "docobj.inc"

$LIBID_SHDocVw = GUID$("{EAB22AC0-30C1-11CF-A7EB-0000C05BAE0B}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {0002DF01-0000-0000-C000-000000000046}
$PROGID_InternetExplorer1 = "InternetExplorer.Application.1"
' CLSID = {EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}
$PROGID_WebBrowser_V11 = "Shell.Explorer.1"
' CLSID = {8856F961-340A-11D0-A96B-00C04FD705A2}
$PROGID_WebBrowser2 = "Shell.Explorer.2"
' CLSID = {64AB4BB7-111E-11D1-8F79-00C04FC2FBE1}
$PROGID_ShellUIHelper1 = "Shell.UIHelper.1"
' CLSID = {55136805-B2DE-11D1-B9F2-00A0C98BC547}
$PROGID_ShellNameSpace1 = "ShellNameSpace.ShellNameSpace.1"

' ========================================================================================
' Version Independent ProgIDs
' ========================================================================================

' CLSID = {0002DF01-0000-0000-C000-000000000046}
$PROGID_InternetExplorer = "InternetExplorer.Application"
' CLSID = {EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}
$PROGID_WebBrowser_V1 = "Shell.Explorer"
' CLSID = {55136805-B2DE-11D1-B9F2-00A0C98BC547}
$PROGID_ShellNameSpace = "ShellNameSpace.ShellNameSpace"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CScriptErrorList = GUID$("{EFD01300-160F-11D2-BB2E-00805FF7EFCA}")
$CLSID_InternetExplorerMedium = GUID$("{D5E8041D-920F-45E9-B8FB-B1DEB82C6E5E}")
$CLSID_ShellBrowserWindow = GUID$("{C08AFD90-F2A1-11D1-8455-00A0C91F3880}")
$CLSID_ShellWindows = GUID$("{9BA05972-F6A8-11CF-A442-00A0C90A8F39}")
$CLSID_InternetExplorer = GUID$("{0002DF01-0000-0000-C000-000000000046}")
$CLSID_WebBrowser_V1 = GUID$("{EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}")
$CLSID_WebBrowser = GUID$("{8856F961-340A-11D0-A96B-00C04FD705A2}")
$CLSID_ShellUIHelper = GUID$("{64AB4BB7-111E-11D1-8F79-00C04FC2FBE1}")
$CLSID_ShellNameSpace = GUID$("{55136805-B2DE-11D1-B9F2-00A0C98BC547}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DShellNameSpaceEvents = GUID$("{55136806-B2DE-11D1-B9F2-00A0C98BC547}")
$IID_DShellWindowsEvents = GUID$("{FE4106E0-399A-11D0-A48C-00A0C90A8F39}")
$IID_DWebBrowserEvents = GUID$("{EAB22AC2-30C1-11CF-A7EB-0000C05BAE0B}")
$IID_DWebBrowserEvents2 = GUID$("{34A715A0-6587-11D0-924A-0020AFC7AC4D}")
$IID_IScriptErrorList = GUID$("{F3470F24-15FD-11D2-BB2E-00805FF7EFCA}")
$IID_IShellFavoritesNameSpace = GUID$("{55136804-B2DE-11D1-B9F2-00A0C98BC547}")
$IID_IShellNameSpace = GUID$("{E572D3C9-37BE-4AE2-825D-D521763E3108}")
$IID_IShellUIHelper = GUID$("{729FE2F8-1EA8-11D1-8F85-00C04FC2FBE1}")
$IID_IShellUIHelper2 = GUID$("{A7FE6EDA-1932-4281-B881-87B31B8BC52C}")
$IID_IShellUIHelper3 = GUID$("{528DF2EC-D419-40BC-9B6D-DCDBF9C1B25D}")
$IID_IShellWindows = GUID$("{85CB6900-4D95-11CF-960C-0080C7F4EE85}")
$IID_IWebBrowser = GUID$("{EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B}")
$IID_IWebBrowser2 = GUID$("{D30C1661-CDAF-11D0-8A3E-00C04FC9E26E}")
$IID_IWebBrowserApp = GUID$("{0002DF05-0000-0000-C000-000000000046}")

' ========================================================================================
' CommandStateChangeConstants enum
' IID: {34A226E0-DF30-11CF-89A9-00A0C9054129}
' Constants for WebBrowser CommandStateChange
' ========================================================================================

%CSC_UPDATECOMMANDS                           = &HFFFFFFFF&   ' (-1)
%CSC_NAVIGATEFORWARD                          = &H01&
%CSC_NAVIGATEBACK                             = &H02&

' ========================================================================================
' SecureLockIconConstants enum
' IID: {65507BE0-91A8-11D3-A845-009027220E6D}
' Constants for WebBrowser security icon notification
' ========================================================================================

%secureLockIconUnsecure                       = &H0
%secureLockIconMixed                          = &H1
%secureLockIconSecureUnknownBits              = &H2
%secureLockIconSecure40Bit                    = &H3
%secureLockIconSecure56Bit                    = &H4
%secureLockIconSecureFortezza                 = &H5
%secureLockIconSecure128Bit                   = &H6

' ========================================================================================
' NewProcessCauseConstants enum
' IID: {A8317D46-03CB-4975-AE94-85E9F2E1D020}
' Constants for WebBrowser NewProcess notification
' ========================================================================================

%ProtectedModeRedirect                        = &H1

' ========================================================================================
' ShellWindowTypeConstants enum
' IID: {F41E6981-28E5-11D0-82B4-00A0C90C29C5}
' Constants for ShellWindows registration
' ========================================================================================

%SWC_EXPLORER                                 = 0
%SWC_BROWSER                                  = &H1
%SWC_3RDPARTY                                 = &H2
%SWC_CALLBACK                                 = &H4
%SWC_DESKTOP                                  = &H8

' ========================================================================================
' ShellWindowFindWindowOptions enum
' IID: {7716A370-38CA-11D0-A48B-00A0C90A8F39}
' Options for ShellWindows FindWindow
' ========================================================================================

%SWFO_NEEDDISPATCH                            = &H1
%SWFO_INCLUDEPENDING                          = &H2
%SWFO_COOKIEPASSED                            = &H4


' ########################################################################################
' Interface name = IWebBrowser
' IID = {EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B}
' Inherited interface = IDispatch
' Deprecated. Use IWebBrowser2.
' ########################################################################################

#IF NOT %DEF(%IWebBrowser_INTERFACE_DEFINED)
    %IWebBrowser_INTERFACE_DEFINED = 1

' BrowserNavConstants enum
' GUID: 14EE5380-A378-11cf-A731-00A0C9082637
%navOpenInNewWindow       = &H1
%navNoHistory             = &H2
%navNoReadFromCache       = &H4
%navNoWriteToCache        = &H8
%navAllowAutosearch       = &H10
%navBrowserBar            = &H20
%navHyperlink             = &H40
%navEnforceRestricted     = &H80
%navNewWindowsManaged     = &H100
%navUntrustedForDownload  = &H200
%navTrustedForActiveX     = &H400
%navOpenInNewTab          = &H800
%navOpenInBackgroundTab   = &H1000
%navKeepWordWheelText     = &H2000
%navVirtualTab            = &H4000
%navBlockRedirectsXDomain = &H8000
%navOpenNewForegroundTab  = &H10000

' RefreshConstants enum
' GUID: C317C261-A991-11cf-A731-00A0C9082637
%REFRESH_NORMAL     = 0
%REFRESH_IFEXPIRED  = 1
%REFRESH_COMPLETELY = 3

INTERFACE IWebBrowser $IID_IWebBrowser

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GoBack <100> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD GoForward <101> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GoHome <102> ( _                              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GoSearch <103> ( _                            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Navigate <104> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Flags AS VARIANT _                  ' __opt_in VARIANT *Flags
   , OPTIONAL BYREF TargetFrameName AS VARIANT _        ' __opt_in VARIANT *TargetFrameName
   , OPTIONAL BYREF PostData AS VARIANT _               ' __opt_in VARIANT *PostData
   , OPTIONAL BYREF Headers AS VARIANT _                ' __opt_in VARIANT *Headers
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh2 <105> ( _                            ' VTable offset = 52
     OPTIONAL BYREF Level AS VARIANT _                  ' __opt_in VARIANT *Level
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <106> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Application <200> ( _                   ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Parent <201> ( _                        ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Container <202> ( _                     ' VTable offset = 68
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Document <203> ( _                      ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET TopLevelContainer <204> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY GET Type <205> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *Type
   ' =====================================================================================
   PROPERTY GET Left <206> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Left <206> ( _                          ' VTable offset = 88
     BYVAL Left AS LONG _                               ' __in long Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <207> ( _                           ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Top <207> ( _                           ' VTable offset = 96
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <208> ( _                         ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Width <208> ( _                         ' VTable offset = 104
     BYVAL Width AS LONG _                              ' __in long Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <209> ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Height <209> ( _                        ' VTable offset = 112
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationName <210> ( _                  ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *LocationName
   ' =====================================================================================
   PROPERTY GET LocationURL <211> ( _                   ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *LocationURL
   ' =====================================================================================
   PROPERTY GET Busy <212> ( _                          ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebBrowser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWebBrowserApp
' IID = {0002DF05-0000-0000-C000-000000000046}
' Inherited interface = IWebBrowser
' Deprecated. Use IWebBrowser2.
' ########################################################################################

#IF NOT %DEF(%IWebBrowserApp_INTERFACE_DEFINED)
    %IWebBrowserApp_INTERFACE_DEFINED =1

INTERFACE IWebBrowserApp $IID_IWebBrowserApp

   INHERIT IDispatch

   ' =====================================================================================
   ' IWebBrowser Methods
   ' =====================================================================================
   METHOD GoBack <100> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD GoForward <101> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GoHome <102> ( _                              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GoSearch <103> ( _                            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Navigate <104> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Flags AS VARIANT _                  ' __opt_in VARIANT *Flags
   , OPTIONAL BYREF TargetFrameName AS VARIANT _        ' __opt_in VARIANT *TargetFrameName
   , OPTIONAL BYREF PostData AS VARIANT _               ' __opt_in VARIANT *PostData
   , OPTIONAL BYREF Headers AS VARIANT _                ' __opt_in VARIANT *Headers
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh2 <105> ( _                            ' VTable offset = 52
     OPTIONAL BYREF Level AS VARIANT _                  ' __opt_in VARIANT *Level
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <106> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Application <200> ( _                   ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Parent <201> ( _                        ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Container <202> ( _                     ' VTable offset = 68
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Document <203> ( _                      ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET TopLevelContainer <204> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY GET Type <205> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *Type
   ' =====================================================================================
   PROPERTY GET Left <206> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Left <206> ( _                          ' VTable offset = 88
     BYVAL Left AS LONG _                               ' __in long Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <207> ( _                           ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Top <207> ( _                           ' VTable offset = 96
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <208> ( _                         ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Width <208> ( _                         ' VTable offset = 104
     BYVAL Width AS LONG _                              ' __in long Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <209> ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Height <209> ( _                        ' VTable offset = 112
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationName <210> ( _                  ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *LocationName
   ' =====================================================================================
   PROPERTY GET LocationURL <211> ( _                   ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *LocationURL
   ' =====================================================================================
   PROPERTY GET Busy <212> ( _                          ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================

   ' =====================================================================================
   ' IWebBrowserApp Methods
   ' =====================================================================================
   METHOD Quit <300> ( _                                ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD ClientToWindow <301> ( _                      ' VTable offset = 132
     BYREF pcx AS LONG _                                ' __inout int *pcx
   , BYREF pcy AS LONG _                                ' __inout int *pcy
   )                                                    ' void
   ' =====================================================================================
   METHOD PutProperty <302> ( _                         ' VTable offset = 136
     BYVAL Property AS WSTRING _                        ' __in BSTR Property
   , BYVAL vtValue AS VARIANT _                         ' __in VARIANT vtValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <303> ( _                         ' VTable offset = 140
     BYVAL Property AS WSTRING _                        ' __in BSTR Property
   ) AS VARIANT                                         ' __retval_out VARIANT *pvtValue
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET HWND <-515> ( _                         ' VTable offset = 148
   ) AS LONG                                            ' __retval_out SHANDLE_PTR *pHWND
   ' =====================================================================================
   PROPERTY GET FullName <400> ( _                      ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *FullName
   ' =====================================================================================
   PROPERTY GET Path <401> ( _                          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *Path
   ' =====================================================================================
   PROPERTY GET Visible <402> ( _                       ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY SET Visible <402> ( _                       ' VTable offset = 164
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StatusBar <403> ( _                     ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY SET StatusBar <403> ( _                     ' VTable offset = 172
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StatusText <404> ( _                    ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *StatusText
   ' =====================================================================================
   PROPERTY SET StatusText <404> ( _                    ' VTable offset = 180
     BYVAL StatusText AS WSTRING _                      ' __in BSTR StatusText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolBar <405> ( _                       ' VTable offset = 184
   ) AS LONG                                            ' __retval_out int *Value
   ' =====================================================================================
   PROPERTY SET ToolBar <405> ( _                       ' VTable offset = 188
     BYVAL Value AS LONG _                              ' __in int Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MenuBar <406> ( _                       ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Value
   ' =====================================================================================
   PROPERTY SET MenuBar <406> ( _                       ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreen <407> ( _                    ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET FullScreen <407> ( _                    ' VTable offset = 204
     BYVAL bFullScreen AS INTEGER _                     ' __in VARIANT_BOOL bFullScreen
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebBrowserApp_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWebBrowser2
' IID = {D30C1661-CDAF-11D0-8A3E-00C04FC9E26E}
' Inherited interface = IWebBrowserApp
' This interface enables applications to implement an instance of the WebBrowser control
' (Microsoft ActiveX control) or control an instance of the InternetExplorer application
' (OLE Automation). Note that not all of the methods listed below are supported by the
' WebBrowser control.
' The IWebBrowser2 interface derives from IDispatch indirectly. IWebBrowser2 derives from
' IWebBrowserApp, which in turn derives from IWebBrowser, which finally derives from
' IDispatch. The IWebBrowser and IWebBrowserApp interfaces are deprecated.
' ########################################################################################

#IF NOT %DEF(%IWebBrowser2_INTERFACE_DEFINED)
    %IWebBrowser2_INTERFACE_DEFINED = 1

INTERFACE IWebBrowser2 $IID_IWebBrowser2

   INHERIT IDispatch

   ' =====================================================================================
   ' IWebBrowser Methods
   ' =====================================================================================
   METHOD GoBack <100> ( _                              ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD GoForward <101> ( _                           ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GoHome <102> ( _                              ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GoSearch <103> ( _                            ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Navigate <104> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Flags AS VARIANT _                  ' __opt_in VARIANT *Flags
   , OPTIONAL BYREF TargetFrameName AS VARIANT _        ' __opt_in VARIANT *TargetFrameName
   , OPTIONAL BYREF PostData AS VARIANT _               ' __opt_in VARIANT *PostData
   , OPTIONAL BYREF Headers AS VARIANT _                ' __opt_in VARIANT *Headers
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <-550> ( _                            ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh2 <105> ( _                            ' VTable offset = 52
     OPTIONAL BYREF Level AS VARIANT _                  ' __opt_in VARIANT *Level
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <106> ( _                                ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Application <200> ( _                   ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Parent <201> ( _                        ' VTable offset = 64
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Container <202> ( _                     ' VTable offset = 68
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Document <203> ( _                      ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET TopLevelContainer <204> ( _             ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY GET Type <205> ( _                          ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *Type
   ' =====================================================================================
   PROPERTY GET Left <206> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Left <206> ( _                          ' VTable offset = 88
     BYVAL Left AS LONG _                               ' __in long Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <207> ( _                           ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Top <207> ( _                           ' VTable offset = 96
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <208> ( _                         ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Width <208> ( _                         ' VTable offset = 104
     BYVAL Width AS LONG _                              ' __in long Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <209> ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pl
   ' =====================================================================================
   PROPERTY SET Height <209> ( _                        ' VTable offset = 112
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocationName <210> ( _                  ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *LocationName
   ' =====================================================================================
   PROPERTY GET LocationURL <211> ( _                   ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *LocationURL
   ' =====================================================================================
   PROPERTY GET Busy <212> ( _                          ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================

   ' =====================================================================================
   ' IWebBrowserApp Methods
   ' =====================================================================================
   METHOD Quit <300> ( _                                ' VTable offset = 128
   )                                                    ' void
   ' =====================================================================================
   METHOD ClientToWindow <301> ( _                      ' VTable offset = 132
     BYREF pcx AS LONG _                                ' __inout int *pcx
   , BYREF pcy AS LONG _                                ' __inout int *pcy
   )                                                    ' void
   ' =====================================================================================
   METHOD PutProperty <302> ( _                         ' VTable offset = 136
     BYVAL Property AS WSTRING _                        ' __in BSTR Property
   , BYVAL vtValue AS VARIANT _                         ' __in VARIANT vtValue
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <303> ( _                         ' VTable offset = 140
     BYVAL Property AS WSTRING _                        ' __in BSTR Property
   ) AS VARIANT                                         ' __retval_out VARIANT *pvtValue
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET HWND <-515> ( _                         ' VTable offset = 148
   ) AS LONG                                            ' __retval_out SHANDLE_PTR *pHWND
   ' =====================================================================================
   PROPERTY GET FullName <400> ( _                      ' VTable offset = 152
   ) AS WSTRING                                         ' __retval_out BSTR *FullName
   ' =====================================================================================
   PROPERTY GET Path <401> ( _                          ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *Path
   ' =====================================================================================
   PROPERTY GET Visible <402> ( _                       ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY SET Visible <402> ( _                       ' VTable offset = 164
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StatusBar <403> ( _                     ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   PROPERTY SET StatusBar <403> ( _                     ' VTable offset = 172
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StatusText <404> ( _                    ' VTable offset = 176
   ) AS WSTRING                                         ' __retval_out BSTR *StatusText
   ' =====================================================================================
   PROPERTY SET StatusText <404> ( _                    ' VTable offset = 180
     BYVAL StatusText AS WSTRING _                      ' __in BSTR StatusText
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ToolBar <405> ( _                       ' VTable offset = 184
   ) AS LONG                                            ' __retval_out int *Value
   ' =====================================================================================
   PROPERTY SET ToolBar <405> ( _                       ' VTable offset = 188
     BYVAL Value AS LONG _                              ' __in int Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MenuBar <406> ( _                       ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Value
   ' =====================================================================================
   PROPERTY SET MenuBar <406> ( _                       ' VTable offset = 196
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreen <407> ( _                    ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbFullScreen
   ' =====================================================================================
   PROPERTY SET FullScreen <407> ( _                    ' VTable offset = 204
     BYVAL bFullScreen AS INTEGER _                     ' __in VARIANT_BOOL bFullScreen
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IWebBrowser2 Methods
   ' =====================================================================================
   METHOD Navigate2 <500> ( _                           ' VTable offset = 208
     BYREF URL AS VARIANT _                             ' __in VARIANT *URL
   , OPTIONAL BYREF Flags AS VARIANT _                  ' __opt_in VARIANT *Flags
   , OPTIONAL BYREF TargetFrameName AS VARIANT _        ' __opt_in VARIANT *TargetFrameName
   , OPTIONAL BYREF PostData AS VARIANT _               ' __opt_in VARIANT *PostData
   , OPTIONAL BYREF Headers AS VARIANT _                ' __opt_in VARIANT *Headers
   )                                                    ' void
   ' =====================================================================================
   METHOD QueryStatusWB <501> ( _                       ' VTable offset = 212
     BYVAL cmdID AS LONG _                              ' __in OLECMDID cmdID
   ) AS DWORD                                           ' __retval_out OLECMDF *pcmdf
   ' =====================================================================================
   METHOD ExecWB <502> ( _                              ' VTable offset = 216
     BYVAL cmdID AS LONG _                              ' __in OLECMDID cmdID
   , BYVAL cmdexecopt AS LONG _                         ' __in OLECMDEXECOPT cmdexecopt
   , OPTIONAL BYREF pvaIn AS VARIANT _                  ' __opt_in VARIANT *pvaIn
   , OPTIONAL BYREF pvaOut AS VARIANT _                 ' __opt_inout VARIANT *pvaOut
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowBrowserBar <503> ( _                      ' VTable offset = 220
     BYREF pvaClsid AS VARIANT _                        ' __in VARIANT *pvaClsid
   , OPTIONAL BYREF pvarShow AS VARIANT _               ' __opt_in VARIANT *pvarShow
   , OPTIONAL BYREF pvarSize AS VARIANT _               ' __opt_in VARIANT *pvarSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReadyState <-525> ( _                   ' VTable offset = 224
   ) AS LONG                                            ' __retval_out READYSTATE *plReadyState
   ' =====================================================================================
   PROPERTY GET Offline <550> ( _                       ' VTable offset = 228
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbOffline
   ' =====================================================================================
   PROPERTY SET Offline <550> ( _                       ' VTable offset = 232
     BYVAL bOffline AS INTEGER _                        ' __in VARIANT_BOOL bOffline
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Silent <551> ( _                        ' VTable offset = 236
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbSilent
   ' =====================================================================================
   PROPERTY SET Silent <551> ( _                        ' VTable offset = 240
     BYVAL bSilent AS INTEGER _                         ' __in VARIANT_BOOL bSilent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegisterAsBrowser <552> ( _             ' VTable offset = 244
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRegister
   ' =====================================================================================
   PROPERTY SET RegisterAsBrowser <552> ( _             ' VTable offset = 248
     BYVAL bRegister AS INTEGER _                       ' __in VARIANT_BOOL bRegister
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RegisterAsDropTarget <553> ( _          ' VTable offset = 252
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRegister
   ' =====================================================================================
   PROPERTY SET RegisterAsDropTarget <553> ( _          ' VTable offset = 256
     BYVAL bRegister AS INTEGER _                       ' __in VARIANT_BOOL bRegister
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TheaterMode <554> ( _                   ' VTable offset = 260
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbRegister
   ' =====================================================================================
   PROPERTY SET TheaterMode <554> ( _                   ' VTable offset = 264
     BYVAL bRegister AS INTEGER _                       ' __in VARIANT_BOOL bRegister
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AddressBar <555> ( _                    ' VTable offset = 268
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Value
   ' =====================================================================================
   PROPERTY SET AddressBar <555> ( _                    ' VTable offset = 272
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Resizable <556> ( _                     ' VTable offset = 276
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Value
   ' =====================================================================================
   PROPERTY SET Resizable <556> ( _                     ' VTable offset = 280
     BYVAL Value AS INTEGER _                           ' __in VARIANT_BOOL Value
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebBrowser2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellWindows
' IID = {85CB6900-4D95-11CF-960C-0080C7F4EE85}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShellWindows_INTERFACE_DEFINED)
    %IShellWindows_INTERFACE_DEFINED = 1

INTERFACE IShellWindows $IID_IShellWindows

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *Count
   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 32
     OPTIONAL BYVAL index AS VARIANT _                  ' __opt_in VARIANT index
   ) AS IDispatch                                       ' __retval_out IDispatch **Folder
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================
   METHOD Register <1610743811> ( _                     ' VTable offset = 40
     BYVAL pid AS IDispatch _                           ' __in IDispatch *pid
   , BYVAL hwnd AS LONG _                               ' __in long hwnd
   , BYVAL swClass AS LONG _                            ' __in int swClass
   , BYREF plCookie AS LONG _                           ' __out long *plCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD RegisterPending <1610743812> ( _              ' VTable offset = 44
     BYVAL lThreadId AS LONG _                          ' __in long lThreadId
   , BYREF pvarloc AS VARIANT _                         ' __in VARIANT *pvarloc
   , BYREF pvarlocRoot AS VARIANT _                     ' __in VARIANT *pvarlocRoot
   , BYVAL swClass AS LONG _                            ' __in int swClass
   , BYREF plCookie AS LONG _                           ' __out long *plCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD Revoke <1610743813> ( _                       ' VTable offset = 48
     BYVAL lCookie AS LONG _                            ' __in long lCookie
   )                                                    ' void
   ' =====================================================================================
   METHOD OnNavigate <1610743814> ( _                   ' VTable offset = 52
     BYVAL lCookie AS LONG _                            ' __in long lCookie
   , BYREF pvarLoc AS VARIANT _                         ' __in VARIANT *pvarLoc
   )                                                    ' void
   ' =====================================================================================
   METHOD OnActivated <1610743815> ( _                  ' VTable offset = 56
     BYVAL lCookie AS LONG _                            ' __in long lCookie
   , BYVAL fActive AS INTEGER _                         ' __in VARIANT_BOOL fActive
   )                                                    ' void
   ' =====================================================================================
   METHOD FindWindowSW <1610743816> ( _                 ' VTable offset = 60
     BYREF pvarLoc AS VARIANT _                         ' __in VARIANT *pvarLoc
   , BYREF pvarLocRoot AS VARIANT _                     ' __in VARIANT *pvarLocRoot
   , BYVAL swClass AS LONG _                            ' __in int swClass
   , BYREF phwnd AS LONG _                              ' __out long *phwnd
   , BYVAL swfwOptions AS LONG _                        ' __in int swfwOptions
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdispOut
   ' =====================================================================================
   METHOD OnCreated <1610743817> ( _                    ' VTable offset = 64
     BYVAL lCookie AS LONG _                            ' __in long lCookie
   , BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   )                                                    ' void
   ' =====================================================================================
   METHOD ProcessAttachDetach <1610743818> ( _          ' VTable offset = 68
     BYVAL fAttach AS INTEGER _                         ' __in VARIANT_BOOL fAttach
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellWindows_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellUIHelper
' IID = 729FE2F8-1EA8-11D1-8F85-00C04FC2FBE1
' Inherited interface = IDispatch
' This interface provides access to features available in the Microsoft Windows Shell API.
' ########################################################################################

#IF NOT %DEF(%IShellUIHelper_INTERFACE_DEFINED)
    %IShellUIHelper_INTERFACE_DEFINED = 1

INTERFACE IShellUIHelper $IID_IShellUIHelper

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ResetFirstBootMode <1> ( _                    ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetSafeMode <2> ( _                         ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshOfflineDesktop <3> ( _                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFavorite <4> ( _                           ' VTable offset = 40
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Title AS VARIANT _                  ' __opt_in VARIANT *Title
   )                                                    ' void
   ' =====================================================================================
   METHOD AddChannel <5> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD AddDesktopComponent <6> ( _                   ' VTable offset = 48
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , OPTIONAL BYREF Left AS VARIANT _                   ' __opt_in VARIANT *Left
   , OPTIONAL BYREF Top AS VARIANT _                    ' __opt_in VARIANT *Top
   , OPTIONAL BYREF Width AS VARIANT _                  ' __opt_in VARIANT *Width
   , OPTIONAL BYREF Height AS VARIANT _                 ' __opt_in VARIANT *Height
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSubscribed <7> ( _                          ' VTable offset = 52
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD NavigateAndFind <8> ( _                       ' VTable offset = 56
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , BYREF varTargetFrame AS VARIANT _                  ' __in VARIANT *varTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportExportFavorites <9> ( _                 ' VTable offset = 60
     BYVAL fImport AS INTEGER _                         ' __in VARIANT_BOOL fImport
   , BYVAL strImpExpPath AS WSTRING _                   ' __in BSTR strImpExpPath
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteSaveForm <10> ( _                 ' VTable offset = 64
     OPTIONAL BYREF Form AS VARIANT _                   ' __opt_in VARIANT *Form
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoScan <11> ( _                             ' VTable offset = 68
     BYVAL strSearch AS WSTRING _                       ' __in BSTR strSearch
   , BYVAL strFailureUrl AS WSTRING _                   ' __in BSTR strFailureUrl
   , OPTIONAL BYREF pvarTargetFrame AS VARIANT _        ' __opt_in VARIANT *pvarTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteAttach <12> ( _                   ' VTable offset = 72
     OPTIONAL BYREF Reserved AS VARIANT _               ' __opt_in VARIANT *Reserved
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowBrowserUI <13> ( _                        ' VTable offset = 76
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF pvarIn AS VARIANT _                          ' __in VARIANT *pvarIn
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellUIHelper_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellUIHelper2 [IE7]
' IID = {A7FE6EDA-1932-4281-B881-87B31B8BC52C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IShellUIHelper
' ########################################################################################

#IF NOT %DEF(%IShellUIHelper2_INTERFACE_DEFINED)
    %IShellUIHelper2_INTERFACE_DEFINED = 1

INTERFACE IShellUIHelper2 $IID_IShellUIHelper2

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellUIHelper Methods
   ' =====================================================================================
   METHOD ResetFirstBootMode <1> ( _                    ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetSafeMode <2> ( _                         ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshOfflineDesktop <3> ( _                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFavorite <4> ( _                           ' VTable offset = 40
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Title AS VARIANT _                  ' __opt_in VARIANT *Title
   )                                                    ' void
   ' =====================================================================================
   METHOD AddChannel <5> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD AddDesktopComponent <6> ( _                   ' VTable offset = 48
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , OPTIONAL BYREF Left AS VARIANT _                   ' __opt_in VARIANT *Left
   , OPTIONAL BYREF Top AS VARIANT _                    ' __opt_in VARIANT *Top
   , OPTIONAL BYREF Width AS VARIANT _                  ' __opt_in VARIANT *Width
   , OPTIONAL BYREF Height AS VARIANT _                 ' __opt_in VARIANT *Height
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSubscribed <7> ( _                          ' VTable offset = 52
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD NavigateAndFind <8> ( _                       ' VTable offset = 56
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , BYREF varTargetFrame AS VARIANT _                  ' __in VARIANT *varTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportExportFavorites <9> ( _                 ' VTable offset = 60
     BYVAL fImport AS INTEGER _                         ' __in VARIANT_BOOL fImport
   , BYVAL strImpExpPath AS WSTRING _                   ' __in BSTR strImpExpPath
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteSaveForm <10> ( _                 ' VTable offset = 64
     OPTIONAL BYREF Form AS VARIANT _                   ' __opt_in VARIANT *Form
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoScan <11> ( _                             ' VTable offset = 68
     BYVAL strSearch AS WSTRING _                       ' __in BSTR strSearch
   , BYVAL strFailureUrl AS WSTRING _                   ' __in BSTR strFailureUrl
   , OPTIONAL BYREF pvarTargetFrame AS VARIANT _        ' __opt_in VARIANT *pvarTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteAttach <12> ( _                   ' VTable offset = 72
     OPTIONAL BYREF Reserved AS VARIANT _               ' __opt_in VARIANT *Reserved
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowBrowserUI <13> ( _                        ' VTable offset = 76
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF pvarIn AS VARIANT _                          ' __in VARIANT *pvarIn
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarOut
   ' =====================================================================================

   ' =====================================================================================
   ' IShellUIHelper2 Methods
   ' =====================================================================================
   METHOD AddSearchProvider <14> ( _                    ' VTable offset = 80
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD RunOnceShown <15> ( _                         ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD SkipRunOnce <16> ( _                          ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD CustomizeSettings <17> ( _                    ' VTable offset = 92
     BYVAL fSQM AS INTEGER _                            ' __in VARIANT_BOOL fSQM
   , BYVAL fPhishing AS INTEGER _                       ' __in VARIANT_BOOL fPhishing
   , BYVAL bstrLocale AS WSTRING _                      ' __in BSTR bstrLocale
   )                                                    ' void
   ' =====================================================================================
   METHOD SqmEnabled <18> ( _                           ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD PhishingEnabled <19> ( _                      ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD BrandImageUri <20> ( _                        ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUri
   ' =====================================================================================
   METHOD SkipTabsWelcome <21> ( _                      ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD DiagnoseConnection <22> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD CustomizeClearType <23> ( _                   ' VTable offset = 116
     BYVAL fSet AS INTEGER _                            ' __in VARIANT_BOOL fSet
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSearchProviderInstalled <24> ( _            ' VTable offset = 120
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   ) AS DWORD                                           ' __retval_out unsigned long *pdwResult
   ' =====================================================================================
   METHOD IsSearchMigrated <25> ( _                     ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMigrated
   ' =====================================================================================
   METHOD DefaultSearchProvider <26> ( _                ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   METHOD RunOnceRequiredSettingsComplete <27> ( _      ' VTable offset = 132
     BYVAL fComplete AS INTEGER _                       ' __in VARIANT_BOOL fComplete
   )                                                    ' void
   ' =====================================================================================
   METHOD RunOnceHasShown <28> ( _                      ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShown
   ' =====================================================================================
   METHOD SearchGuideUrl <29> ( _                       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrUrl
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellUIHelper2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellUIHelper3 [IE8]
' IID = {528DF2EC-D419-40BC-9B6D-DCDBF9C1B25D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IShellUIHelper2
' ########################################################################################

#IF NOT %DEF(%IShellUIHelper3_INTERFACE_DEFINED)
    %IShellUIHelper3_INTERFACE_DEFINED = 1

INTERFACE IShellUIHelper3 $IID_IShellUIHelper3

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellUIHelper Methods
   ' =====================================================================================
   METHOD ResetFirstBootMode <1> ( _                    ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetSafeMode <2> ( _                         ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD RefreshOfflineDesktop <3> ( _                 ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD AddFavorite <4> ( _                           ' VTable offset = 40
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , OPTIONAL BYREF Title AS VARIANT _                  ' __opt_in VARIANT *Title
   )                                                    ' void
   ' =====================================================================================
   METHOD AddChannel <5> ( _                            ' VTable offset = 44
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD AddDesktopComponent <6> ( _                   ' VTable offset = 48
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Type AS WSTRING _                            ' __in BSTR Type
   , OPTIONAL BYREF Left AS VARIANT _                   ' __opt_in VARIANT *Left
   , OPTIONAL BYREF Top AS VARIANT _                    ' __opt_in VARIANT *Top
   , OPTIONAL BYREF Width AS VARIANT _                  ' __opt_in VARIANT *Width
   , OPTIONAL BYREF Height AS VARIANT _                 ' __opt_in VARIANT *Height
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSubscribed <7> ( _                          ' VTable offset = 52
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD NavigateAndFind <8> ( _                       ' VTable offset = 56
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL strQuery AS WSTRING _                        ' __in BSTR strQuery
   , BYREF varTargetFrame AS VARIANT _                  ' __in VARIANT *varTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD ImportExportFavorites <9> ( _                 ' VTable offset = 60
     BYVAL fImport AS INTEGER _                         ' __in VARIANT_BOOL fImport
   , BYVAL strImpExpPath AS WSTRING _                   ' __in BSTR strImpExpPath
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteSaveForm <10> ( _                 ' VTable offset = 64
     OPTIONAL BYREF Form AS VARIANT _                   ' __opt_in VARIANT *Form
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoScan <11> ( _                             ' VTable offset = 68
     BYVAL strSearch AS WSTRING _                       ' __in BSTR strSearch
   , BYVAL strFailureUrl AS WSTRING _                   ' __in BSTR strFailureUrl
   , OPTIONAL BYREF pvarTargetFrame AS VARIANT _        ' __opt_in VARIANT *pvarTargetFrame
   )                                                    ' void
   ' =====================================================================================
   METHOD AutoCompleteAttach <12> ( _                   ' VTable offset = 72
     OPTIONAL BYREF Reserved AS VARIANT _               ' __opt_in VARIANT *Reserved
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowBrowserUI <13> ( _                        ' VTable offset = 76
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   , BYREF pvarIn AS VARIANT _                          ' __in VARIANT *pvarIn
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarOut
   ' =====================================================================================

   ' =====================================================================================
   ' IShellUIHelper2 Methods
   ' =====================================================================================
   METHOD AddSearchProvider <14> ( _                    ' VTable offset = 80
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD RunOnceShown <15> ( _                         ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD SkipRunOnce <16> ( _                          ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD CustomizeSettings <17> ( _                    ' VTable offset = 92
     BYVAL fSQM AS INTEGER _                            ' __in VARIANT_BOOL fSQM
   , BYVAL fPhishing AS INTEGER _                       ' __in VARIANT_BOOL fPhishing
   , BYVAL bstrLocale AS WSTRING _                      ' __in BSTR bstrLocale
   )                                                    ' void
   ' =====================================================================================
   METHOD SqmEnabled <18> ( _                           ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD PhishingEnabled <19> ( _                      ' VTable offset = 100
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD BrandImageUri <20> ( _                        ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrUri
   ' =====================================================================================
   METHOD SkipTabsWelcome <21> ( _                      ' VTable offset = 108
   )                                                    ' void
   ' =====================================================================================
   METHOD DiagnoseConnection <22> ( _                   ' VTable offset = 112
   )                                                    ' void
   ' =====================================================================================
   METHOD CustomizeClearType <23> ( _                   ' VTable offset = 116
     BYVAL fSet AS INTEGER _                            ' __in VARIANT_BOOL fSet
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSearchProviderInstalled <24> ( _            ' VTable offset = 120
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   ) AS DWORD                                           ' __retval_out unsigned long *pdwResult
   ' =====================================================================================
   METHOD IsSearchMigrated <25> ( _                     ' VTable offset = 124
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfMigrated
   ' =====================================================================================
   METHOD DefaultSearchProvider <26> ( _                ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrName
   ' =====================================================================================
   METHOD RunOnceRequiredSettingsComplete <27> ( _      ' VTable offset = 132
     BYVAL fComplete AS INTEGER _                       ' __in VARIANT_BOOL fComplete
   )                                                    ' void
   ' =====================================================================================
   METHOD RunOnceHasShown <28> ( _                      ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfShown
   ' =====================================================================================
   METHOD SearchGuideUrl <29> ( _                       ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrUrl
   ' =====================================================================================

   ' =====================================================================================
   ' IShellUIHelper3 Methods
   ' =====================================================================================
   METHOD AddService <30> ( _                           ' VTable offset = 144
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   )                                                    ' void
   ' =====================================================================================
   METHOD IsServiceInstalled <31> ( _                   ' VTable offset = 148
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Verb AS WSTRING _                            ' __in BSTR Verb
   ) AS DWORD                                           ' __retval_out DWORD *pdwResult
   ' =====================================================================================
   METHOD InPrivateFilteringEnabled <37> ( _            ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD AddToFavoritesBar <32> ( _                    ' VTable offset = 156
     BYVAL URL AS WSTRING _                             ' __in BSTR URL
   , BYVAL Title AS WSTRING _                           ' __in BSTR Title
   , OPTIONAL BYREF Type AS VARIANT _                   ' __in_opt VARIANT *Type
   )                                                    ' void
   ' =====================================================================================
   METHOD BuildNewTabPage <33> ( _                      ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD SetRecentlyClosedVisible <34> ( _             ' VTable offset = 164
     BYVAL fVisible AS INTEGER _                        ' __in VARIANT_BOOL fVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD SetActivitiesVisible <35> ( _                 ' VTable offset = 168
     BYVAL fVisible AS INTEGER _                        ' __in VARIANT_BOOL fVisible
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentDiscoveryReset <36> ( _                ' VTable offset = 172
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSuggestedSitesEnabled <38> ( _              ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfEnabled
   ' =====================================================================================
   METHOD EnableSuggestedSites <39> ( _                 ' VTable offset = 180
     BYVAL fEnable AS INTEGER _                         ' __in VARIANT_BOOL fEnable
   )                                                    ' void
   ' =====================================================================================
   METHOD NavigateToSuggestedSites <40> ( _             ' VTable offset = 184
     BYVAL bstrRelativeUrl AS WSTRING _                 ' __in BSTR bstrRelativeUrl
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowTabsHelp <41> ( _                         ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowInPrivateHelp <42> ( _                    ' VTable offset = 192
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellUIHelper3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellFavoritesNameSpace
' IID = {55136804-B2DE-11D1-B9F2-00A0C98BC547}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IShellFavoritesNameSpace_INTERFACE_DEFINED)
    %IShellFavoritesNameSpace_INTERFACE_DEFINED = 1

INTERFACE IShellFavoritesNameSpace $IID_IShellFavoritesNameSpace

   INHERIT IDispatch

   ' =====================================================================================
   METHOD MoveSelectionUp <1> ( _                       ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveSelectionDown <2> ( _                     ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetSort <3> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD NewFolder <4> ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Synchronize <5> ( _                           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Import <6> ( _                                ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <7> ( _                                ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeContextMenuCommand <8> ( _              ' VTable offset = 56
     BYVAL strCommand AS WSTRING _                      ' __in BSTR strCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveSelectionTo <9> ( _                       ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriptionsEnabled <10> ( _           ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD CreateSubscriptionForSelection <11> ( _       ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD DeleteSubscriptionForSelection <12> ( _       ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD SetRoot <13> ( _                              ' VTable offset = 76
     BYVAL bstrFullPath AS WSTRING _                    ' __in BSTR bstrFullPath
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFavoritesNameSpace_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IShellNameSpace
' IID = {E572D3C9-37BE-4AE2-825D-D521763E3108}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IShellFavoritesNameSpace
' ########################################################################################

#IF NOT %DEF(%IShellNameSpace_INTERFACE_DEFINED)
    %IShellNameSpace_INTERFACE_DEFINED = 1

INTERFACE IShellNameSpace $IID_IShellNameSpace

   INHERIT IDispatch

   ' =====================================================================================
   ' IShellFavoritesNameSpace Methods
   ' =====================================================================================
   METHOD MoveSelectionUp <1> ( _                       ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveSelectionDown <2> ( _                     ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetSort <3> ( _                             ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD NewFolder <4> ( _                             ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Synchronize <5> ( _                           ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Import <6> ( _                                ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Export <7> ( _                                ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD InvokeContextMenuCommand <8> ( _              ' VTable offset = 56
     BYVAL strCommand AS WSTRING _                      ' __in BSTR strCommand
   )                                                    ' void
   ' =====================================================================================
   METHOD MoveSelectionTo <9> ( _                       ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubscriptionsEnabled <10> ( _           ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD CreateSubscriptionForSelection <11> ( _       ' VTable offset = 68
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD DeleteSubscriptionForSelection <12> ( _       ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pBool
   ' =====================================================================================
   METHOD SetRoot <13> ( _                              ' VTable offset = 76
     BYVAL bstrFullPath AS WSTRING _                    ' __in BSTR bstrFullPath
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IShellNameSpace Methods
   ' =====================================================================================
   PROPERTY GET EnumOptions <14> ( _                    ' VTable offset = 80
   ) AS LONG                                            ' __retval_out LONG *pgrfEnumFlags
   ' =====================================================================================
   PROPERTY SET EnumOptions <14> ( _                    ' VTable offset = 84
     BYVAL lVal AS LONG _                               ' __in LONG lVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SelectedItem <15> ( _                   ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out IDispatch **pItem
   ' =====================================================================================
   PROPERTY SET SelectedItem <15> ( _                   ' VTable offset = 92
     BYVAL pItem AS IDispatch _                         ' __in IDispatch *pItem
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Root <16> ( _                           ' VTable offset = 96
   ) AS VARIANT                                         ' __retval_out VARIANT *pvar
   ' =====================================================================================
   PROPERTY SET Root <16> ( _                           ' VTable offset = 100
     BYVAL var AS VARIANT _                             ' __in VARIANT var
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Depth <17> ( _                          ' VTable offset = 104
   ) AS LONG                                            ' __retval_out int *piDepth
   ' =====================================================================================
   PROPERTY SET Depth <17> ( _                          ' VTable offset = 108
     BYVAL iDepth AS LONG _                             ' __in int iDepth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Mode <18> ( _                           ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out UINT *puMode
   ' =====================================================================================
   PROPERTY SET Mode <18> ( _                           ' VTable offset = 116
     BYVAL uMode AS DWORD _                             ' __in UINT uMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Flags <19> ( _                          ' VTable offset = 120
   ) AS DWORD                                           ' __retval_out DWORD *pdwFlags
   ' =====================================================================================
   PROPERTY SET Flags <19> ( _                          ' VTable offset = 124
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET TVFlags <20> ( _                        ' VTable offset = 128
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TVFlags <20> ( _                        ' VTable offset = 132
   ) AS DWORD                                           ' __retval_out DWORD *dwFlags
   ' =====================================================================================
   PROPERTY GET Columns <21> ( _                        ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *bstrColumns
   ' =====================================================================================
   PROPERTY SET Columns <21> ( _                        ' VTable offset = 140
     BYVAL bstrColumns AS WSTRING _                     ' __in BSTR bstrColumns
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CountViewTypes <22> ( _                 ' VTable offset = 144
   ) AS LONG                                            ' __retval_out int *piTypes
   ' =====================================================================================
   METHOD SetViewType <23> ( _                          ' VTable offset = 148
     BYVAL iType AS LONG _                              ' __in int iType
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectedItems <24> ( _                        ' VTable offset = 152
   ) AS IDispatch                                       ' __retval_out IDispatch **ppid
   ' =====================================================================================
   METHOD Expand <25> ( _                               ' VTable offset = 156
     BYVAL var AS VARIANT _                             ' __in VARIANT var
   , BYVAL iDepth AS LONG _                             ' __in int iDepth
   )                                                    ' void
   ' =====================================================================================
   METHOD UnselectAll <26> ( _                          ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellNameSpace_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IScriptErrorList
' IID = {F3470F24-15FD-11D2-BB2E-00805FF7EFCA}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IScriptErrorList_INTERFACE_DEFINED)
    %IScriptErrorList_INTERFACE_DEFINED = 1

INTERFACE IScriptErrorList $IID_IScriptErrorList

   INHERIT IDispatch

   ' =====================================================================================
   METHOD advanceError <10> ( _                         ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD retreatError <11> ( _                         ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD canAdvanceError <12> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out BOOL *pfCanAdvance
   ' =====================================================================================
   METHOD canRetreatError <13> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out BOOL *pfCanRetreat
   ' =====================================================================================
   METHOD getErrorLine <14> ( _                         ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *plLine
   ' =====================================================================================
   METHOD getErrorChar <15> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *plChar
   ' =====================================================================================
   METHOD getErrorCode <16> ( _                         ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *plCode
   ' =====================================================================================
   METHOD getErrorMsg <17> ( _                          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pstr
   ' =====================================================================================
   METHOD getErrorUrl <18> ( _                          ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pstr
   ' =====================================================================================
   METHOD getAlwaysShowLockState <23> ( _               ' VTable offset = 64
   ) AS LONG                                            ' __retval_out BOOL *pfAlwaysShowLocked
   ' =====================================================================================
   METHOD getDetailsPaneOpen <19> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __retval_out BOOL *pfDetailsPaneOpen
   ' =====================================================================================
   METHOD setDetailsPaneOpen <20> ( _                   ' VTable offset = 72
     BYVAL fDetailsPaneOpen AS LONG _                   ' __in BOOL fDetailsPaneOpen
   )                                                    ' void
   ' =====================================================================================
   METHOD getPerErrorDisplay <21> ( _                   ' VTable offset = 76
   ) AS LONG                                            ' __retval_out BOOL *pfPerErrorDisplay
   ' =====================================================================================
   METHOD setPerErrorDisplay <22> ( _                   ' VTable offset = 80
     BYVAL fPerErrorDisplay AS LONG _                   ' __in BOOL fPerErrorDisplay
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScriptErrorList_INTERFACE_DEFINED__ */


' ========================================================================================
' Adds a favorite. Use for backward compatibility only.
' ========================================================================================
DECLARE FUNCTION AddUrlToFavorites IMPORT "SHDOCVW.DLL" ALIAS "AddUrlToFavorites" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszUrlW AS WSTRINGZ _                          ' __in LPCWSTR pszUrlW
 , BYREF pszTitleW AS WSTRINGZ _                        ' __in LPCWSTR pszTitleW
 , BYVAL fDisplayUI AS LONG _                           ' __in BOOL fDisplayUI
 ) AS LONG                                              ' HRESULT
' ========================================================================================

' ========================================================================================
' Displays the standard Microsoft Internet Explorer Add Favorite dialog box.
' ========================================================================================
DECLARE FUNCTION DoAddToFavDlg IMPORT "SHDOCVW.DLL" ALIAS "DoAddToFavDlg" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszInitDir AS ASCIIZ _                         ' __in CHAR *pszInitDir
 , BYVAL cchInitDir AS DWORD _                          ' __in UINT cchInitDir
 , BYREF pszFile AS ASCIIZ _                            ' __in CHAR *pszFile
 , BYVAL cchInitDir AS DWORD _                          ' __in UINT cchInitDir
 , BYVAL pidlBrowse AS DWORD _                          ' __in LPITEMIDLIST pidlBrowse
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' Displays the standard Microsoft Internet Explorer Organize Favorites dialog box.
' ========================================================================================
DECLARE FUNCTION DoOrganizeFavDlg IMPORT "SHDOCVW.DLL" ALIAS "DoOrganizeFavDlg" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszInitDir AS ASCIIZ _                         ' __in CHAR *pszInitDir
 ) AS LONG                                              ' BOOL
' ========================================================================================


' ########################################################################################
' Associated Browser Functions
' ########################################################################################

' ========================================================================================
' Launches the Internet Properties dialog box with the Connections tab displayed.
' ========================================================================================
DECLARE FUNCTION LaunchConnectionDialog IMPORT "inetcpl.cpl" ALIAS "LaunchConnectionDialog" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' Launches the Internet Properties dialog box with the General tab displayed.
' ========================================================================================
DECLARE FUNCTION LaunchInternetControlPanel IMPORT "inetcpl.cpl" ALIAS "LaunchInternetControlPanel" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' Launches the Internet Properties dialog box with the Privacy tab displayed.
' ========================================================================================
DECLARE FUNCTION LaunchPrivacyDialog IMPORT "inetcpl.cpl" ALIAS "LaunchPrivacyDialog" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 ) AS LONG                                              ' BOOL
' ========================================================================================

' ========================================================================================
' Launches the Internet Properties dialog box with the Security tab displayed.
' ========================================================================================
DECLARE FUNCTION LaunchSecurityDialog IMPORT "inetcpl.cpl" ALIAS "LaunchSecurityDialog" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 ) AS LONG                                              ' BOOL
' ========================================================================================
