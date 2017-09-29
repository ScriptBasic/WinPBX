' ########################################################################################
' Microsoft Windows
' File: ObjSafe.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OBJSAFE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"

'//---------------------------------------------------------------------------=
'// Object Safety Interfaces.

'//+--------------------------------------------------------------------------=
'//
'//  Contents:   IObjectSafety definition
'//
'//
'//  IObjectSafety should be implemented by objects that have interfaces which
'//      support "untrusted" clients (for example, scripts). It allows the owner of
'//      the object to specify which interfaces need to be protected from untrusted
'//      use. Examples of interfaces that might be protected in this way are:
'//
'//      IID_IDispatch           - "Safe for automating with untrusted automation client or script"
'//      IID_IPersist*           - "Safe for initializing with untrusted data"
'//      IID_IActiveScript       - "Safe for running untrusted scripts"
'//
'//---------------------------------------------------------------------------=

'// Option bit definitions for IObjectSafety:
%INTERFACESAFE_FOR_UNTRUSTED_CALLER = &H00000001???  ' // Caller of interface may be untrusted
%INTERFACESAFE_FOR_UNTRUSTED_DATA   = &H00000002???  ' // Data passed into interface may be untrusted
%INTERFACE_USES_DISPEX              = &H00000004???  ' // Object knows to use IDispatchEx
%INTERFACE_USES_SECURITY_MANAGER    = &H00000008???  ' // Object knows to use IInternetHostSecurityManager

$IID_IObjectSafety         = GUID$("{CB5BDC81-93C1-11CF-8F20-00805F2CD064}")
$CATID_SafeForScripting    = GUID$("{7DD95801-9882-11CF-9FA9-00AA006C42C4}")
$CATID_SafeForInitializing = GUID$("{7DD95802-9882-11CF-9FA9-00AA006C42C4}")

' ########################################################################################
' IObjectSafety interface
' IID = CB5BDC81-93C1-11cf-8F20-00805F2CD064
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectSafety_INTERFACE_DEFINED)
    %IObjectSafety_INTERFACE_DEFINED = 1

INTERFACE IObjectSafety $IID_IObjectSafety

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInterfaceSafetyOptions ( _                 ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF pdwSupportedOptions AS DWORD _               ' __out DWORD *pdwSupportedOptions
   , BYREF pdwEnabledOptions AS DWORD _                 ' __out DWORD *pdwEnabledOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterfaceSafetyOptions ( _                 ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL dwOptionSetMask AS DWORD _                   ' __in DWORD dwOptionSetMask
   , BYVAL dwEnabledOptions AS DWORD _                  ' __in DWORD dwEnabledOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' IF NOT %DEF(%IObjectSafety_INTERFACE_DEFINED)
