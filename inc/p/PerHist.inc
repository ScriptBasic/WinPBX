' ########################################################################################
' Microsoft Windows
' File: Perhist.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PERHIST_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"

'//---------------------------------------------------------------------------=
'// IPersistHistory Interface.

' ########################################################################################
' IPersistHistory interface
' IID = 91A565C1-E38F-11d0-94BF-00A0C9055CBF
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistHistory_INTERFACE_DEFINED)
    %IPersistHistory_INTERFACE_DEFINED = 1

$IID_IPersistHistory = GUID$("{91A565C1-E38F-11d0-94BF-00A0C9055CBF}")

INTERFACE IPersistHistory $IID_IPersistHistory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadHistory ( _                               ' VTable offset = 16
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveHistory ( _                               ' VTable offset = 20
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPositionCookie ( _                         ' VTable offset = 24
     BYVAL dwPositioncookie AS DWORD _                  ' __in DWORD dwPositioncookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositionCookie ( _                         ' VTable offset = 24
     BYREF pdwPositioncookie AS DWORD _                 ' __out DWORD *pdwPositioncookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistHistory_INTERFACE_DEFINED__ */
