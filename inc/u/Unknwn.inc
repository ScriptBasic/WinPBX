' ########################################################################################
' Microsoft Windows
' File: Unknwn.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UNKNWN_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"  ' for the VARIANT structure

' ########################################################################################
' IUnknown interface
' IID = 00000000-0000-C000-0000000000000046
' ########################################################################################

#IF NOT %DEF(%IUnknown_INTERFACE_DEFINED)
    %IUnknown_INTERFACE_DEFINED = 1

$IID_IUnknown = GUID$("{00000000-0000-0000-C000-000000000046}")

'INTERFACE IUnknown $IID_IUnknown

'   ' =====================================================================================
'   METHOD QueryInterface ( _                            ' VTable offset = 12
'     BYREF iid AS GUID _                                ' __in  REFIID iid
'   , BYREF ppvObject AS IUnknown _                      ' __out void ** ppvObject
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD AddRef ( _                                    ' VTable offset = 14
'   ) AS DWORD                                           ' ULONG
'   ' =====================================================================================
'   METHOD Release ( _                                   ' VTable offset = 16
'   ) AS DWORD                                           ' ULONG
'   ' =====================================================================================

'END INTERFACE

#ENDIF  ' /* __IUnknown_INTERFACE_DEFINED__ */

' *** As built into the PowerBASIC compiler ***

'INTERFACE IUnknown $IID_IUnknown

'   ' =====================================================================================
'   METHOD QueryInterface ( _                            ' VTable offset = 12
'     BYREF iid AS GUID _                                ' __in REFIID iid
'   , BYVAL ppvObject AS DWORD PTR _                     ' __out void ** ppvObject
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD AddRef ( _                                    ' VTable offset = 14
'   ) AS DWORD                                           ' ULONG
'   ' =====================================================================================
'   METHOD Release ( _                                   ' VTable offset = 16
'   ) AS DWORD                                           ' ULONG
'   ' =====================================================================================

'END INTERFACE


' ########################################################################################
' AsyncIUnknown interface
' IID = 000E0000-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%AsyncIUnknown_INTERFACE_DEFINED)
    %AsyncIUnknown_INTERFACE_DEFINED = 1

$IID_AsyncIUnknown = GUID$("{000E0000-0000-0000-C000-000000000046}")

'    MIDL_INTERFACE("000e0000-0000-0000-C000-000000000046")
'    AsyncIUnknown : public IUnknown
'    {
'    public:
'        virtual HRESULT STDMETHODCALLTYPE Begin_QueryInterface(
'            __in REFIID riid) = 0;

'        virtual HRESULT STDMETHODCALLTYPE Finish_QueryInterface(
'            __out void **ppvObject) = 0;

'        virtual HRESULT STDMETHODCALLTYPE Begin_AddRef( void) = 0;

'        virtual ULONG STDMETHODCALLTYPE Finish_AddRef( void) = 0;

'        virtual HRESULT STDMETHODCALLTYPE Begin_Release( void) = 0;

'        virtual ULONG STDMETHODCALLTYPE Finish_Release( void) = 0;

'    };

#ENDIF   ' /* __AsyncIUnknown_INTERFACE_DEFINED__ */


' ########################################################################################
' IClassFactory interface
' IID = 00000001-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' NOTE: Renamed because of conflicts with the built-in PB definition.
' ########################################################################################

#IF NOT %DEF(%IClassFactory_INTERFACE_DEFINED)
    %IClassFactory_INTERFACE_DEFINED = 1

$IID_IClassFactory = GUID$("{00000001-0000-0000-C000-000000000046}")

INTERFACE COM_IClassFactory $IID_IClassFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateInstance ( _                            ' VTable offset = 12
     BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out void **ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockServer ( _                                ' VTable offset = 16
     BYVAL fLock AS LONG _                              ' __in BOOL fLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IClassFactory_INTERFACE_DEFINED__ */

' *** As built into the PowerBASIC compiler ***

'INTERFACE IClassFactory $IID_IClassFactory

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD CreateInstance ( _                            ' VTable offset = 12
'     BYVAL pUnkOuter AS DWORD _                         ' __in IUnknown *pUnkOuter
'   , BYREF riid AS GUID _                               ' __in REFIID riid
'   , BYVAL ppvObject AS DWORD PTR _                     ' __out void **ppvObject
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD LockServer ( _                                ' VTable offset = 16
'     BYVAL fLock AS LONG _                              ' __in BOOL fLock
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE
