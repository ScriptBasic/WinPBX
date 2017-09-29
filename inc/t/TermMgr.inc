' ########################################################################################
' Microsoft Windows
' File: termmgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: TERMMGRLib
' Version: 1.0
' Documentation string: TAPI3 Terminal Manager 1.0 Type Library
' Path: C:\WINDOWS\system32\termmgr.dll
' Library GUID: {28DCD85B-ACA4-11D0-A028-00AA00B605A4}
' ########################################################################################

#INCLUDE THIS ONCE
%TERMMGR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "Objsafe.inc"
#INCLUDE ONCE "tapi3if.inc"
'#include "tapi3ds.h"    ' tapi3ds.h contents are included in tapi3.inc
'#include "msp.h"        ' msp.h contents are included in tapi3.inc


' TMGR_DIRECTION enum
%TMGR_TD_CAPTURE = 1
%TMGR_TD_RENDER  = 2
%TMGR_TD_BOTH    = 3

'#define   CLSID_String_VideoSuperclass   ( L"{714C6F8C-6244-4685-87B3-B91F3F9EADA7}" )
'#define   CLSID_String_StreamingSuperclass   ( L"{214F4ACC-AE0B-4464-8405-07029003F8E2}" )
'#define   CLSID_String_FileSuperclass   ( L"{B4790031-56DB-4d3e-88C8-6FFAAFA08A91}" )

$CLSID_String_VideoSuperclass     = "{714C6F8C-6244-4685-87B3-B91F3F9EADA7}"
$CLSID_String_StreamingSuperclass = "{214F4ACC-AE0B-4464-8405-07029003F8E2}"
$CLSID_String_FileSuperclass      = "{B4790031-56DB-4d3e-88C8-6FFAAFA08A91}"


' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_termmgrPTRegTerminalClass = "termmgr.PTRegTerminalClass"
$PROGID_termmgrTerminalManager = "termmgr.TerminalManager"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {45234E3E-61CC-4311-A3AB-248082554482}
$PROGID_termmgrPTRegTerminal = "termmgr.PTRegTerminal"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_PluggableTerminalRegistration = GUID$("{45234E3E-61CC-4311-A3AB-248082554482}")
$CLSID_PluggableSuperclassRegistration = GUID$("{BB918E32-2A5C-4986-AB40-1686A034390A}")
$CLSID_TerminalManager = GUID$("{7170F2E0-9BE3-11D0-A009-00AA00B605A4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ITPluggableTerminalClassRegistration = GUID$("{924A3723-A00B-4F5F-9FEE-8E9AEB9E82AA}")
$IID_ITPluggableTerminalSuperclassRegistration = GUID$("{60D3C08A-C13E-4195-9AB0-8DE768090F25}")
$IID_ITTerminalManager = GUID$("{7170F2DE-9BE3-11D0-A009-00AA00B605A4}")
$IID_ITTerminalControl = GUID$("{AED6483B-3304-11D2-86F1-006008B0E5D2}")
$IID_ITPluggableTerminalInitialization = GUID$("{AED6483C-3304-11D2-86F1-006008B0E5D2}")
$IID_ITTerminalManager2 = GUID$("{BB33DEC6-B2C7-46E6-9ED1-498B91FA85AC}")


' ########################################################################################
' Interface name = ITTerminalControl
' IID = {AED6483B-3304-11D2-86F1-006008B0E5D2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITTerminalControl_INTERFACE_DEFINED)
    %ITTerminalControl_INTERFACE_DEFINED = 1

INTERFACE ITTerminalControl $IID_ITTerminalControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_AddressHandle ( _                         ' VTable offset = 12
     BYREF phtAddress AS DWORD _                        ' __out MSP_HANDLE *phtAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectTerminal ( _                           ' VTable offset = 16
     BYVAL pGraph AS IGraphBuilder _                    ' __in IGraphBuilder *pGraph
   , BYVAL dwTerminalDirection AS DWORD _               ' __in DWORD dwTerminalDirection
   , BYREF pdwNumPins AS DWORD _                        ' __inout DWORD *pdwNumPins
   , BYREF ppPins AS IPin _                             ' __out IPin **ppPins
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompleteConnectTerminal ( _                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectTerminal ( _                        ' VTable offset = 24
     BYVAL pGraph AS IGraphBuilder _                    ' __in IGraphBuilder *pGraph
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunRenderFilter ( _                           ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopRenderFilter ( _                          ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminalControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalInitialization
' IID = {AED6483C-3304-11D2-86F1-006008B0E5D2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalInitialization_INTERFACE_DEFINED)
    %ITPluggableTerminalInitialization_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalInitialization $IID_ITPluggableTerminalInitialization

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeDynamic ( _                         ' VTable offset = 12
     BYREF iidTerminalClass AS GUID _                   ' __in IID iidTerminalClass
   , BYVAL dwMediaType AS DWORD _                       ' __in DWORD dwMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   , BYVAL htAddress AS DWORD _                         ' __in MSP_HANDLE htAddress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalInitialization_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTerminalManager
' IID = {7170F2DE-9BE3-11D0-A009-00AA00B605A4}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITTerminalManager_INTERFACE_DEFINED)
    %ITTerminalManager_INTERFACE_DEFINED = 1

INTERFACE ITTerminalManager $IID_ITTerminalManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDynamicTerminalClasses ( _                 ' VTable offset = 12
     BYVAL dwMediaTypes AS DWORD _                      ' __in DWORD dwMediaTypes
   , BYREF pdwNumClasses AS DWORD _                     ' __inout DWORD *pdwNumClasses
   , BYREF pTerminalClasses AS GUID _                   ' __out IID *pTerminalClasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDynamicTerminal ( _                     ' VTable offset = 16
     BYVAL pOuterUnknown AS IUnknown _                  ' __in IUnknown *pOuterUnknown
   , BYREF iidTerminalClass AS GUID _                   ' __in IID iidTerminalClass
   , BYVAL dwMediaType AS DWORD _                       ' __in DWORD dwMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   , BYREF htAddress AS LONG _                          ' __in MSP_HANDLE htAddress
   , BYREF ppTerminal AS ITTerminal _                   ' __out ITTerminal **ppTerminal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminalManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITTerminalManager2
' IID = {BB33DEC6-B2C7-46E6-9ED1-498B91FA85AC}
' Inherited interface = ITTerminalManager
' ########################################################################################

#IF NOT %DEF(%ITTerminalManager2_INTERFACE_DEFINED)
    %ITTerminalManager2_INTERFACE_DEFINED = 1

INTERFACE ITTerminalManager2 $IID_ITTerminalManager2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDynamicTerminalClasses ( _                 ' VTable offset = 12
     BYVAL dwMediaTypes AS DWORD _                      ' __in DWORD dwMediaTypes
   , BYREF pdwNumClasses AS DWORD _                     ' __inout DWORD *pdwNumClasses
   , BYREF pTerminalClasses AS GUID _                   ' __out IID *pTerminalClasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateDynamicTerminal ( _                     ' VTable offset = 16
     BYVAL pOuterUnknown AS IUnknown _                  ' __in IUnknown *pOuterUnknown
   , BYREF iidTerminalClass AS GUID _                   ' __in IID iidTerminalClass
   , BYVAL dwMediaType AS DWORD _                       ' __in DWORD dwMediaType
   , BYVAL Direction AS LONG _                          ' __in TERMINAL_DIRECTION Direction
   , BYREF htAddress AS LONG _                          ' __in MSP_HANDLE htAddress
   , BYREF ppTerminal AS ITTerminal _                   ' __out ITTerminal **ppTerminal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPluggableSuperclasses ( _                  ' VTable offset = 20
     BYREF pdwNumSuperclasses AS DWORD _                ' __inout DWORD *pdwNumSuperclasses
   , BYREF pSuperclasses AS GUID _                      ' __out IID *pSuperclasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPluggableTerminalClasses ( _               ' VTable offset = 24
     BYREF iidSuperclass AS GUID _                      ' __in IID iidSuperclass
   , BYVAL dwMediaTypes AS DWORD _                      ' __in DWORD dwMediaTypes
   , BYREF pdwNumClasses AS DWORD _                     ' __inout DWORD *pdwNumClasses
   , BYREF pTerminalClasses AS GUID _                   ' __out IID *pTerminalClasses
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITTerminalManager2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalClassRegistration
' IID = {924A3723-A00B-4F5F-9FEE-8E9AEB9E82AA}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalClassRegistration_INTERFACE_DEFINED)
    %ITPluggableTerminalClassRegistration_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalClassRegistration $IID_ITPluggableTerminalClassRegistration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Company <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pCompany
   ' =====================================================================================
   PROPERTY SET Company <2> ( _                         ' VTable offset = 40
     BYVAL bstrCompany AS WSTRING _                     ' __in BSTR bstrCompany
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Version <3> ( _                         ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVersion
   ' =====================================================================================
   PROPERTY SET Version <3> ( _                         ' VTable offset = 48
     BYVAL bstrVersion AS WSTRING _                     ' __in BSTR bstrVersion
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalClass <4> ( _                   ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pTerminalClass
   ' =====================================================================================
   PROPERTY SET TerminalClass <4> ( _                   ' VTable offset = 56
     BYVAL bstrTerminalClass AS WSTRING _               ' __in BSTR bstrTerminalClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <5> ( _                           ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pCLSID
   ' =====================================================================================
   PROPERTY SET CLSID <5> ( _                           ' VTable offset = 64
     BYVAL bstrCLSID AS WSTRING _                       ' __in BSTR bstrCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Direction <6> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out TMGR_DIRECTION *pDirection
   ' =====================================================================================
   PROPERTY SET Direction <6> ( _                       ' VTable offset = 72
     BYVAL nDirection AS LONG _                         ' __in TMGR_DIRECTION nDirection
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MediaTypes <7> ( _                      ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pMediaTypes
   ' =====================================================================================
   PROPERTY SET MediaTypes <7> ( _                      ' VTable offset = 80
     BYVAL nMediaTypes AS LONG _                        ' __in long nMediaTypes
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <8> ( _                                   ' VTable offset = 84
     BYVAL bstrSuperclass AS WSTRING _                  ' __in BSTR bstrSuperclass
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <9> ( _                                ' VTable offset = 88
     BYVAL bstrSuperclass AS WSTRING _                  ' __in BSTR bstrSuperclass
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTerminalClassInfo <10> ( _                 ' VTable offset = 92
     BYVAL bstrSuperclass AS WSTRING _                  ' __in BSTR bstrSuperclass
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalClassRegistration_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITPluggableTerminalSuperclassRegistration
' IID = {60D3C08A-C13E-4195-9AB0-8DE768090F25}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED)
    %ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED = 1

INTERFACE ITPluggableTerminalSuperclassRegistration $IID_ITPluggableTerminalSuperclassRegistration

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET Name <1> ( _                            ' VTable offset = 32
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CLSID <2> ( _                           ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pCLSID
   ' =====================================================================================
   PROPERTY SET CLSID <2> ( _                           ' VTable offset = 40
     BYVAL bstrCLSID AS WSTRING _                       ' __in BSTR bstrCLSID
   )                                                    ' void
   ' =====================================================================================
   METHOD Add <3> ( _                                   ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <4> ( _                                ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD GetTerminalSuperclassInfo <5> ( _             ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TerminalClasses <6> ( _                 ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pTerminals
   ' =====================================================================================
   METHOD EnumerateTerminalClasses <7> ( _              ' VTable offset = 60
   ) AS IEnumTerminalClass                              ' __retval_out IEnumTerminalClass **ppTerminals
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITPluggableTerminalSuperclassRegistration_INTERFACE_DEFINED__ */
