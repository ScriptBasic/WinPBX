' ########################################################################################
' Microsoft Windows
' File: atl.inc
' Library name: ATLLib
' Version: 1.0
' Contents: ATL 2.0 Type Library
' Library GUID: {44EC0535-400F-11D0-9DCD-00A0C90391D3}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ATL_INC = 1

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAxWinAmbientDispatch     = GUID$("{B6EA2051-048A-11D1-82B9-00C04FB9942E}")
$IID_IAxWinAmbientDispatchEx   = GUID$("{B2D0778B-AC99-4C58-A5C8-E7724E5316B5}")
$IID_IDocHostUIHandlerDispatch = GUID$("{425B5AF0-65F1-11D1-9611-0000F81E0D0D}")

#IF NOT %DEF($ATL_DLLNAME)
$ATL_DLLNAME = "ATL.DLL"   ' --> change as needed
#ENDIF

#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' Creates a connection between an object's connection point and a client's sink.
' ========================================================================================
DECLARE FUNCTION AtlAdvise IMPORT $ATL_DLLNAME ALIAS "AtlAdvise" ( _
   BYVAL pUnkCP AS IUnknown _                           ' __in IUnknown* pUnkCP
 , BYVAL pUnk AS IUnknown _                             ' __in IUnknown* pUnk
 , BYREF iid AS GUID _                                  ' __in const IID& iid
 , BYREF pdw AS DWORD _                                 ' __out LPDWORD pdw
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Attaches a previously created control to the specified window.
' ========================================================================================
DECLARE FUNCTION AtlAxAttachControl IMPORT $ATL_DLLNAME ALIAS "AtlAxAttachControl" ( _
   BYVAL pControl AS IUnknown _                         ' __in IUnknown* pControl
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF ppUnkContainer AS IUnknown _                   ' __out IUnknown** ppUnkContainer
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates an ActiveX control, initializes it, and hosts it in the specified window.
' ========================================================================================
DECLARE FUNCTION AtlAxCreateControl IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateControl" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCOLESTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYREF ppUnkContainer AS IUnknown _                   ' __out IUnknown** ppUnkContainer
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates an ActiveX control, initializes it, and hosts it in the specified window. An
' interface pointer and event sink for the new control can also be created.
' ========================================================================================
DECLARE FUNCTION AtlAxCreateControlEx IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateControlEx" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCOLESTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYREF ppUnkContainer AS IUnknown _                   ' __out IUnknown** ppUnkContainer
 , BYREF ppUnkControl AS IUnknown _                     ' __out IUnknown** ppUnkControl
 , BYREF iidSink AS GUID _                              ' __in REFIID iidSink = IID_NULL
 , BYVAL punkSink AS IUnknown _                         ' __in IUnknown* punkSink = NULL
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a licensed ActiveX control, initializes it, and hosts it in the specified window.
' ========================================================================================
DECLARE FUNCTION AtlAxCreateControlLic IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateControlLic" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCOLESTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYREF ppUnkContainer AS IUnknown _                   ' __out IUnknown** ppUnkContainer
 , BYVAL bstrLic AS WSTRING _                           ' __in BSTR bstrLic = NULL
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a licensed ActiveX control, initializes it, and hosts it in the specified window.
' An interface pointer and event sink for the new control can also be created.
' ========================================================================================
DECLARE FUNCTION AtlAxCreateControlLicEx IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateControlLicEx" ( _
   BYREF lpszName AS WSTRINGZ _                         ' __in LPCOLESTR lpszName
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYREF ppUnkContainer AS IUnknown _                   ' __out IUnknown** ppUnkContainer
 , BYREF ppUnkControl AS IUnknown _                     ' __out IUnknown** ppUnkControl
 , BYREF iidSink AS GUID _                              ' __in REFIID iidSink = IID_NULL
 , BYVAL punkSink AS IUnknown _                         ' __in IUnknown* punkSink = NULL
 , BYVAL bstrLic AS WSTRING _                           ' __in BSTR bstrLic = NULL
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a modeless dialog box from a dialog template provided by the user.
' ========================================================================================
DECLARE FUNCTION AtlAxCreateDialogA IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateDialogA" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , BYVAL hWndParent AS DWORD _                          ' __in HWND hWndParent
 , BYVAL lpDialogProc AS DWORD _                        ' __in DLGPROC lpDialogProc
 , BYVAL dwInitParam AS LONG _                          ' __in LPARAM dwInitParam
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AtlAxCreateDialogW IMPORT $ATL_DLLNAME ALIAS "AtlAxCreateDialogW" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , BYVAL hWndParent AS DWORD _                          ' __in HWND hWndParent
 , BYVAL lpDialogProc AS DWORD _                        ' __in DLGPROC lpDialogProc
 , BYVAL dwInitParam AS LONG _                          ' __in LPARAM dwInitParam
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO AtlAxCreateDialog = AtlAxCreateDialogW
#ELSE
MACRO AtlAxCreateDialog = AtlAxCreateDialogA
#ENDIF

' ========================================================================================
' Creates a modal dialog box from a dialog template provided by the user.
' ========================================================================================
DECLARE FUNCTION AtlAxDialogBoxA IMPORT $ATL_DLLNAME ALIAS "AtlAxDialogBoxA" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF lpTemplateName AS ASCIIZ _                     ' __in LPCSTR lpTemplateName
 , BYVAL hWndParent AS DWORD _                          ' __in HWND hWndParent
 , BYVAL lpDialogProc AS DWORD _                        ' __in DLGPROC lpDialogProc
 , BYVAL dwInitParam AS LONG _                          ' __in LPARAM dwInitParam
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AtlAxDialogBoxW IMPORT $ATL_DLLNAME ALIAS "AtlAxDialogBoxW" ( _
   BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF lpTemplateName AS WSTRINGZ _                   ' __in LPCWSTR lpTemplateName
 , BYVAL hWndParent AS DWORD _                          ' __in HWND hWndParent
 , BYVAL lpDialogProc AS DWORD _                        ' __in DLGPROC lpDialogProc
 , BYVAL dwInitParam AS LONG _                          ' __in LPARAM dwInitParam
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO AtlAxDialogBox = AtlAxDialogBoxW
#ELSE
MACRO AtlAxDialogBox = AtlAxDialogBoxA
#ENDIF

' ========================================================================================
' Obtains a direct interface pointer to the control contained inside a specified window
' given its handle.
' ========================================================================================
DECLARE FUNCTION AtlAxGetControl IMPORT $ATL_DLLNAME ALIAS "AtlAxGetControl" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pp AS IUnknown _                               ' __out IUnknown** pp
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Obtains a direct interface pointer to the container for a specified window (if any),
' given its handle.
' ========================================================================================
DECLARE FUNCTION AtlAxGetHost IMPORT $ATL_DLLNAME ALIAS "AtlAxGetHost" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pp AS IUnknown _                               ' __out IUnknown** pp
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' This function initializes ATL's control hosting code by registering the "AtlAxWin" and
' "AtlAxWinLic" window classes plus a couple of custom window messages.
' ========================================================================================
DECLARE FUNCTION AtlAxWinInit IMPORT $ATL_DLLNAME ALIAS "AtlAxWinInit" ( _
 ) AS LONG                                              ' BOOL

' ========================================================================================
' Assigns an interface pointer to another interface pointer of the same type.
' ========================================================================================
DECLARE FUNCTION AtlComPtrAssign IMPORT $ATL_DLLNAME ALIAS "AtlComPtrAssign" ( _
   BYREF pp AS IUnknown _                               ' __out IUnknown** pp
 , BYVAL lp AS IUnknown _                               ' __in  IUnknown* lp
 ) AS IUnknown                                          ' IUnknown

' ========================================================================================
' Assigns an interface pointer to another interface pointer of a different type.
' ========================================================================================
DECLARE FUNCTION AtlComQIPtrAssign IMPORT $ATL_DLLNAME ALIAS "AtlComQIPtrAssign" ( _
   BYREF pp AS IUnknown _                               ' __out IUnknown** pp
 , BYVAL lp AS IUnknown _                               ' __in  IUnknown* lp
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 ) AS IUnknown                                          ' IUnknown

' ========================================================================================
' Creates a device context for the device specified in the DVTARGETDEVICE structure.
' ========================================================================================
DECLARE FUNCTION AtlCreateTargetDC IMPORT $ATL_DLLNAME ALIAS "AtlCreateTargetDC" ( _
   BYVAL hdc AS DWORD _                                 ' __in  HDC hdc
 , BYREF ptd AS DVTARGETDEVICE _                        ' __out DVTARGETDEVICE* ptd
 ) AS DWORD                                             ' HDC

' ========================================================================================
' Releases the marshal data in the stream, then releases the stream pointer.
' ========================================================================================
DECLARE SUB AtlFreeMarshalStream IMPORT $ATL_DLLNAME ALIAS "AtlFreeMarshalStream" ( _
   BYVAL pStream AS IStream _                           ' __in IStream* pStream
 )                                                      ' void

' ========================================================================================
' Converts a DEVMODEW (unicode) structure to a DEVMODEA (ansi) structure.
' ========================================================================================
DECLARE FUNCTION AtlDevModeW2A IMPORT $ATL_DLLNAME ALIAS "AtlDevModeW2A" ( _
   BYREF lpDevModeA AS DEVMODEA _                       ' __out LPDEVMODEA lpDevModeA
 , BYREF lpDevModeW AS DEVMODEW _                       ' __in  LPDEVMODEW lpDevModeW
 ) AS DWORD                                             ' LPDEVMODEA

' ========================================================================================
' Call this function to get the version of the ATL library that you are using.
' DIM ver AS DWORD
' ver = AtlGetVersion(%NULL)
' ========================================================================================
DECLARE FUNCTION AtlGetVersion IMPORT $ATL_DLLNAME ALIAS "AtlGetVersion" ( _
   BYVAL pReserved AS DWORD _                           ' __in void* pReserved
 ) AS DWORD                                             ' DWORD

' ========================================================================================
' Converts an object's size in HIMETRIC units (each unit is 0.01 millimeter) to a size in
' pixels on the screen device.
' ========================================================================================
DECLARE SUB AtlHiMetricToPixel IMPORT $ATL_DLLNAME ALIAS "AtlHiMetricToPixel" ( _
   BYREF lpSizeInHiMetric AS SIZEL _                    ' __in  const SIZEL* lpSizeInHiMetric
 , BYREF lpSizeInPix AS SIZEL _                         ' __out LPSIZEL lpSizeInPix
 )                                                      ' void

' ========================================================================================
' This function is called to load a type library.
' ========================================================================================
DECLARE FUNCTION AtlLoadTypeLib IMPORT $ATL_DLLNAME ALIAS "AtlLoadTypeLib" ( _
   BYVAL hInstTypeLib AS DWORD _                        ' __in  HINSTANCE hInstTypeLib
 , BYREF lpszIndex AS WSTRINGZ _                        ' __in  LPCOLESTR lpszIndex
 , BYREF pbstrPath AS WSTRING _                         ' __out BSTR* pbstrPath
 , BYREF ppTypeLib AS ITypeLib _                        ' __out ITypeLib** ppTypeLib
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates a new stream object, writes the CLSID of the proxy to the stream, and marshals
' the specified interface pointer by writing the data needed to initialize the proxy into
' the stream.
' ========================================================================================
DECLARE FUNCTION AtlMarshalPtrInProc IMPORT $ATL_DLLNAME ALIAS "AtlMarshalPtrInProc" ( _
   BYVAL pUnk AS IUnknown _                             ' __in  IUnknown* pUnk
 , BYREF iid AS GUID _                                  ' __in  const IID* iid
 , BYREF ppStream AS IStream _                          ' __out IStream** ppStream
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Converts an object's size in pixels on the screen device to a size in HIMETRIC units
' (each unit is 0.01 millimeter).
' ========================================================================================
DECLARE SUB AtlPixelToHiMetric IMPORT $ATL_DLLNAME ALIAS "AtlPixelToHiMetric" ( _
   BYREF lpSizeInHiMetric AS SIZEL _                    ' __in  const SIZEL* lpSizeInHiMetric
 , BYREF lpSizeInHiMetric AS SIZEL _                    ' __out LPSIZEL lpSizeInHiMetric
 )                                                      ' void

' ========================================================================================
' This function is called to register a type library.
' ========================================================================================
DECLARE FUNCTION AtlRegisterTypeLib IMPORT $ATL_DLLNAME ALIAS "AtlRegisterTypeLib" ( _
   BYVAL hInstTypeLib AS DWORD _                        ' __in HINSTANCE hInstTypeLib
 , BYREF lpszIndex AS WSTRINGZ _                        ' __in LPCOLESTR lpszIndex
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Sets error information.
' ========================================================================================
DECLARE FUNCTION AtlSetErrorInfo IMPORT $ATL_DLLNAME ALIAS "AtlSetErrorInfo" ( _
   BYREF clsid AS GUID _                                ' __in const CLSID* clsid
 , BYREF lpszDesc AS WSTRINGZ _                         ' __in LPCOLESTR lpszDesc
 , BYVAL dwHelpID AS DWORD _                            ' __in DWORD dwHelpID
 , BYREF lpszHelpFile AS WSTRINGZ _                     ' __in LPCOLESTR lpszHelpFile
 , BYREF iid AS GUID _                                  ' __in const IID* iid
 , BYVAL hRes AS LONG _                                 ' __in HRESULT hRes
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Terminates the connection established through AtlAdvise.
' ========================================================================================
DECLARE FUNCTION AtlUnadvise IMPORT $ATL_DLLNAME ALIAS "AtlUnadvise" ( _
   BYVAL pUnkCP AS IUnknown _                           ' __in IUnknown* pUnkCP
 , BYREF iid AS GUID _                                  ' __in const IID* iid
 , BYVAL dw AS DWORD _                                  ' __in DWORD dw
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Converts the stream's marshaling data into an interface pointer that can be used by
' the client.
' ========================================================================================
DECLARE FUNCTION AtlUnmarshalPtr IMPORT $ATL_DLLNAME ALIAS "AtlUnmarshalPtr" ( _
   BYVAL pStream AS IStream _                           ' __in  IStream* pStream
 , BYREF iid AS GUID _                                  ' __in  const IID* iid
 , BYREF ppUnk AS IUnknown _                            ' __out IUnknown** ppUnk
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' This function is called to unregister a type library.
' ========================================================================================
DECLARE FUNCTION AtlUnRegisterTypeLib IMPORT $ATL_DLLNAME ALIAS "AtlUnRegisterTypeLib" ( _
   BYVAL hInstTypeLib AS DWORD _                        ' __in HINSTANCE hInstTypeLib
 , BYREF lpszIndex AS WSTRINGZ _                        ' __in LPCOLESTR lpszIndex
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Waits for the object to be signaled, meanwhile dispatching window messages as needed.
' ========================================================================================
DECLARE FUNCTION AtlWaitWithMessageLoop IMPORT $ATL_DLLNAME ALIAS "AtlWaitWithMessageLoop" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' BOOL

' ========================================================================================
' Retrieves the interface of the ActiveX control given the handle of its ATL container
' ========================================================================================
'FUNCTION AtlAxGetDispatch (BYVAL hWndControl AS DWORD, BYREF ppvObj AS IDispatch) AS LONG

'   LOCAL hr AS LONG
'   LOCAL pUnk AS IUnknown
'   LOCAL IID_IDispatch AS GUID

'   IF VARPTR(ppvObj) = 0 THEN
'      FUNCTION = %E_POINTER
'      EXIT FUNCTION
'   END IF
'   ppvObj = NOTHING

'   ' Get the IUnknown of the OCX hosted in the control
'   hr = AtlAxGetControl(hWndControl, pUnk)
'   IF hr <> 0 THEN
'      FUNCTION = hr
'      EXIT FUNCTION
'   END IF

'   ' Query for the IDispatch interface
'   IID_IDispatch = GUID$("{00020400-0000-0000-C000-000000000046}")
'   hr = pUnk.QueryInterface(IID_IDispatch, BYVAL VARPTR(ppvObj))

'   FUNCTION = hr
'   pUnk = NOTHING

'END FUNCTION
'' ========================================================================================

' ========================================================================================
FUNCTION AtlAxGetDispatch (BYVAL hWndControl AS DWORD) AS IDispatch

   LOCAL hr AS LONG
   LOCAL pUnk AS IUnknown
   LOCAL pDispatch AS IDispatch
   LOCAL IID_IDispatch AS GUID

   ' Get the IUnknown of the OCX hosted in the control
   hr = AtlAxGetControl(hWndControl, pUnk)
   IF hr <> 0 THEN EXIT FUNCTION

   ' Query for the IDispatch interface
   IID_IDispatch = GUID$("{00020400-0000-0000-C000-000000000046}")
   hr = pUnk.QueryInterface(IID_IDispatch, BYVAL VARPTR(pDispatch))
   IF hr = %S_OK THEN FUNCTION = pDispatch

END FUNCTION
' ========================================================================================


' ########################################################################################
' Interface name = IAxWinAmbientDispatch
' IID = {B6EA2051-048A-11D1-82B9-00C04FB9942E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' This interface provides methods for specifying characteristics of the hosted control
' or container.
' This interface is exposed by ATL's ActiveX control hosting objects. Call the methods on
' this interface to set the ambient properties available to the hosted control or to
' specify other aspects of the container's behavior. To supplement the properties provided
' by IAxWinAmbientDispatch, use IAxWinAmbientDispatchEx.
' ########################################################################################

INTERFACE IAxWinAmbientDispatch $IID_IAxWinAmbientDispatch

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET AllowWindowlessActivation <1610743808> ( _ ' VTable offset = 28
     BYVAL bCanWindowlessActivate AS INTEGER _          ' __in VARIANT_BOOL bCanWindowlessActivate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowWindowlessActivation <1610743808> ( _ ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbCanWindowlessActivate
   ' =====================================================================================
   PROPERTY SET BackColor <-701> ( _                    ' VTable offset = 36
     BYVAL clrBackground AS DWORD _                     ' __in OLE_COLOR clrBackground
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-701> ( _                    ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrBackground
   ' =====================================================================================
   PROPERTY SET ForeColor <-704> ( _                    ' VTable offset = 44
     BYVAL clrForeground AS DWORD _                     ' __in OLE_COLOR clrForeground
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-704> ( _                    ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrForeground
   ' =====================================================================================
   PROPERTY SET LocaleID <-705> ( _                     ' VTable offset = 52
     BYVAL lcidLocaleID AS DWORD _                      ' __in LCID lcidLocaleID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocaleID <-705> ( _                     ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out LCID *plcidLocaleID
   ' =====================================================================================
   PROPERTY SET UserMode <-709> ( _                     ' VTable offset = 60
     BYVAL bUserMode AS INTEGER _                       ' __in VARIANT_BOOL bUserMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserMode <-709> ( _                     ' VTable offset = 64
   ) AS INTEGER                                         ' __in VARIANT_BOOL bDisplayAsDefault
   ' =====================================================================================
   PROPERTY SET DisplayAsDefault <-713> ( _             ' VTable offset = 68
     BYVAL bDisplayAsDefault AS INTEGER _               ' __in VARIANT_BOOL bDisplayAsDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayAsDefault <-713> ( _             ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDisplayAsDefault
   ' =====================================================================================
   PROPERTY SET Font <-703> ( _                         ' VTable offset = 76
     BYVAL pFont AS IFontDisp _                         ' __in IFontDisp *pFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-703> ( _                         ' VTable offset = 80
   ) AS IFontDisp                                       ' __retval_out IFontDisp **pFont
   ' =====================================================================================
   PROPERTY SET MessageReflect <-706> ( _               ' VTable offset = 84
     BYVAL bMsgReflect AS INTEGER _                     ' __in VARIANT_BOOL bMsgReflect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageReflect <-706> ( _               ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMsgReflect
   ' =====================================================================================
   PROPERTY GET ShowGrabHandles <-711> ( _              ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowGrabHandles
   ' =====================================================================================
   PROPERTY GET ShowHatching <-712> ( _                 ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowHatching
   ' =====================================================================================
   PROPERTY SET DocHostFlags <1610743826> ( _           ' VTable offset = 100
     BYVAL dwDocHostFlags AS DWORD _                    ' __in DWORD dwDocHostFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocHostFlags <1610743826> ( _           ' VTable offset = 104
   ) AS DWORD                                           ' __retval_out DWORD *pdwDocHostFlags
   ' =====================================================================================
   PROPERTY SET DocHostDoubleClickFlags <1610743828> ( _ ' VTable offset = 108
     BYVAL dwDocHostDoubleClickFlags AS DWORD _         ' __in DWORD dwDocHostDoubleClickFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocHostDoubleClickFlags <1610743828> ( _ ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out DWORD *pdwDocHostDoubleClickFlags
   ' =====================================================================================
   PROPERTY SET AllowContextMenu <1610743830> ( _       ' VTable offset = 116
     BYVAL bAllowContextMenu AS INTEGER _               ' __in VARIANT_BOOL bAllowContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowContextMenu <1610743830> ( _       ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowContextMenu
   ' =====================================================================================
   PROPERTY SET AllowShowUI <1610743832> ( _            ' VTable offset = 124
     BYVAL bAllowShowUI AS INTEGER _                    ' __in VARIANT_BOOL bAllowShowUI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowShowUI <1610743832> ( _            ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowShowUI
   ' =====================================================================================
   PROPERTY SET OptionKeyPath <1610743834> ( _          ' VTable offset = 132
     BYVAL bstrOptionKeyPath AS WSTRING _               ' __in BSTR bstrOptionKeyPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OptionKeyPath <1610743834> ( _          ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOptionKeyPath
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' Interface name = IAxWinAmbientDispatchEx
' IID = {B2D0778B-AC99-4C58-A5C8-E7724E5316B5}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IAxWinAmbientDispatch
' NOTE: Not available in ATL.DLL (needs at least ATL70.DLL).
' ########################################################################################

INTERFACE IAxWinAmbientDispatchEx $IID_IAxWinAmbientDispatchEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IAxWinAmbientDispatch Methods
   ' =====================================================================================
   PROPERTY SET AllowWindowlessActivation <1610743808> ( _ ' VTable offset = 28
     BYVAL bCanWindowlessActivate AS INTEGER _          ' __in VARIANT_BOOL bCanWindowlessActivate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowWindowlessActivation <1610743808> ( _ ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbCanWindowlessActivate
   ' =====================================================================================
   PROPERTY SET BackColor <-701> ( _                    ' VTable offset = 36
     BYVAL clrBackground AS DWORD _                     ' __in OLE_COLOR clrBackground
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackColor <-701> ( _                    ' VTable offset = 40
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrBackground
   ' =====================================================================================
   PROPERTY SET ForeColor <-704> ( _                    ' VTable offset = 44
     BYVAL clrForeground AS DWORD _                     ' __in OLE_COLOR clrForeground
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ForeColor <-704> ( _                    ' VTable offset = 48
   ) AS DWORD                                           ' __retval_out OLE_COLOR *pclrForeground
   ' =====================================================================================
   PROPERTY SET LocaleID <-705> ( _                     ' VTable offset = 52
     BYVAL lcidLocaleID AS DWORD _                      ' __in LCID lcidLocaleID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET LocaleID <-705> ( _                     ' VTable offset = 56
   ) AS DWORD                                           ' __retval_out LCID *plcidLocaleID
   ' =====================================================================================
   PROPERTY SET UserMode <-709> ( _                     ' VTable offset = 60
     BYVAL bUserMode AS INTEGER _                       ' __in VARIANT_BOOL bUserMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UserMode <-709> ( _                     ' VTable offset = 64
   ) AS INTEGER                                         ' __in VARIANT_BOOL bDisplayAsDefault
   ' =====================================================================================
   PROPERTY SET DisplayAsDefault <-713> ( _             ' VTable offset = 68
     BYVAL bDisplayAsDefault AS INTEGER _               ' __in VARIANT_BOOL bDisplayAsDefault
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayAsDefault <-713> ( _             ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbDisplayAsDefault
   ' =====================================================================================
   PROPERTY SET Font <-703> ( _                         ' VTable offset = 76
     BYVAL pFont AS IFontDisp _                         ' __in IFontDisp *pFont
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Font <-703> ( _                         ' VTable offset = 80
   ) AS IFontDisp                                       ' __retval_out IFontDisp **pFont
   ' =====================================================================================
   PROPERTY SET MessageReflect <-706> ( _               ' VTable offset = 84
     BYVAL bMsgReflect AS INTEGER _                     ' __in VARIANT_BOOL bMsgReflect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageReflect <-706> ( _               ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbMsgReflect
   ' =====================================================================================
   PROPERTY GET ShowGrabHandles <-711> ( _              ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowGrabHandles
   ' =====================================================================================
   PROPERTY GET ShowHatching <-712> ( _                 ' VTable offset = 96
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbShowHatching
   ' =====================================================================================
   PROPERTY SET DocHostFlags <1610743826> ( _           ' VTable offset = 100
     BYVAL dwDocHostFlags AS DWORD _                    ' __in DWORD dwDocHostFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocHostFlags <1610743826> ( _           ' VTable offset = 104
   ) AS DWORD                                           ' __retval_out DWORD *pdwDocHostFlags
   ' =====================================================================================
   PROPERTY SET DocHostDoubleClickFlags <1610743828> ( _ ' VTable offset = 108
     BYVAL dwDocHostDoubleClickFlags AS DWORD _         ' __in DWORD dwDocHostDoubleClickFlags
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DocHostDoubleClickFlags <1610743828> ( _ ' VTable offset = 112
   ) AS DWORD                                           ' __retval_out DWORD *pdwDocHostDoubleClickFlags
   ' =====================================================================================
   PROPERTY SET AllowContextMenu <1610743830> ( _       ' VTable offset = 116
     BYVAL bAllowContextMenu AS INTEGER _               ' __in VARIANT_BOOL bAllowContextMenu
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowContextMenu <1610743830> ( _       ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowContextMenu
   ' =====================================================================================
   PROPERTY SET AllowShowUI <1610743832> ( _            ' VTable offset = 124
     BYVAL bAllowShowUI AS INTEGER _                    ' __in VARIANT_BOOL bAllowShowUI
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AllowShowUI <1610743832> ( _            ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbAllowShowUI
   ' =====================================================================================
   PROPERTY SET OptionKeyPath <1610743834> ( _          ' VTable offset = 132
     BYVAL bstrOptionKeyPath AS WSTRING _               ' __in BSTR bstrOptionKeyPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OptionKeyPath <1610743834> ( _          ' VTable offset = 136
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrOptionKeyPath
   ' =====================================================================================

   ' =====================================================================================
   ' IAxWinAmbientDispatchEx Methods
   ' =====================================================================================
   METHOD SetAmbientDispatch <100> ( _                 ' VTable offset = 140
     BYVAL pDispatch AS IDispatch _                    ' __in IDispatch* pDispatch
   )                                                   ' void
   ' =====================================================================================

END INTERFACE
