' ########################################################################################
' Microsoft Windows
' File: ObjectArray.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OBJECTARRAY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ########################################################################################
' Interface name = IObjectArray
' IID = 92CA9DCD-5622-4BBA-A805-5E9F541BD8C9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectArray_INTERFACE_DEFINED)
    %IObjectArray_INTERFACE_DEFINED = 1

$IID_IObjectArray = GUID$("{92CA9DCD-5622-4BBA-A805-5E9F541BD8C9}")

INTERFACE IObjectArray $IID_IObjectArray

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcObjects AS DWORD _                         ' __out UINT *pcObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL uiIndex AS DWORD _                           ' __in UINT uiIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectArray_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IObjectCollection
' IID = 5632B1A4-E38A-400A-928A-D4CD63230295
' Inherited interface = IObjectArray
' ########################################################################################

#IF NOT %DEF(%IObjectCollection_INTERFACE_DEFINED)
    %IObjectCollection_INTERFACE_DEFINED = 1

$IID_IObjectCollection = GUID$("{5632B1A4-E38A-400A-928A-D4CD63230295}")

INTERFACE IObjectCollection $IID_IObjectCollection

   INHERIT IUnknown

   ' =====================================================================================
   ' IObjectArray methods
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF pcObjects AS DWORD _                         ' __out UINT *pcObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL uiIndex AS DWORD _                           ' __in UINT uiIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IObjectCollection methods
   ' =====================================================================================
   METHOD AddObject ( _                                 ' VTable offset = 20
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFromArray ( _                              ' VTable offset = 24
     BYVAL poaSource AS IObjectArray _                  ' __in IObjectArray *poaSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveObjectAt ( _                            ' VTable offset = 28
     BYVAL uiIndex AS DWORD _                           ' __in UINT uiIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectCollection_INTERFACE_DEFINED__ */
