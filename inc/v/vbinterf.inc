' ########################################################################################
' Microsoft Windows
' File: vbinterf.inc
' Contents: Visual Basic interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VBINTERF_INC = 1

' The class name for all Visual Basic intrinsic controls
$IID_IVBControlClass = GUID$("{FCFB3D25-A0FA-1068-A738-08002B3371B5}")

' ########################################################################################
' IVBGetControl interface
' IID = 40A050A0-3C31-101B-A82E-08002B2B2337
' Inherited interface = IUnknown
' This interface lives on the Extender Object
' ########################################################################################

'// Constants for dwWhich parameter:
%GC_WCH_SIBLING          = &H00000001???
%GC_WCH_CONTAINER        = &H00000002???  ' // no FONLYAFTER/BEFORE
%GC_WCH_CONTAINED        = &H00000003???  ' // no FONLYAFTER/BEFORE
%GC_WCH_ALL              = &H00000004???
%GC_WCH_FREVERSEDIR      = &H08000000???  ' // OR'd with others
%GC_WCH_FONLYAFTER       = &H10000000???  ' // OR'd with others
%GC_WCH_FONLYBEFORE      = &H20000000???  ' // OR'd with others
%GC_WCH_FSELECTED        = &H40000000???  ' // OR'd with others

$IID_IVBGetControl  = GUID$("{40A050A0-3C31-101B-A82E-08002B2B2337}")
$CATID_VBGetControl = GUID$("{02496841-3AC4-11CF-87B9-00AA006C8166}")

INTERFACE IVBGetControl $IID_IVBGetControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumControls ( _                              ' VTable offset = 12
     BYVAL dwOleContF AS DWORD _                        ' __in  DWORD dwOleContF
   , BYVAL dwWhich AS DWORD _                           ' __in  DWORD dwWhich
   , BYREF ppenumUnk AS IUnknown _                      ' __out LPENUMUNKNOWN *ppenumUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IGetOleObject interface
' IID = 8A701DA0-4FEB-101B-A82E-08002B2B2337
' Inherited interface = IUnknown
' This interface lives on the Extender Object (X-Object / hctl)
' ########################################################################################

$IID_IGetOleObject = GUID$("{8A701DA0-4FEB-101B-A82E-08002B2B2337}")

INTERFACE IGetOleObject $IID_IGetOleObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOleObject ( _                              ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out LPVOID *ppvObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IVBFormat interface
' IID = 9849FD60-3768-101B-8D72-AE6164FFE3CF
' Inherited interface = IUnknown
' ########################################################################################

$IID_IVBFormat  = GUID$("{9849FD60-3768-101B-8D72-AE6164FFE3CF}")
$CATID_VBFormat = GUID$("{02496840-3AC4-11CF-87B9-00AA006C8166}")

INTERFACE IVBFormat $IID_IVBFormat

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Format ( _                                    ' VTable offset = 12
     BYREF vData AS VARIANT _                           ' __in  VARIANT *vData
   , BYVAL bstrFormat AS WSTRING _                      ' __in  BSTR bstrFormat
   , BYVAL lpBuffer AS DWORD _                          ' __in  LPVOID lpBuffer
   , BYVAL cb AS WORD _                                 ' __in  USHORT cb
   , BYVAL lcid AS DWORD _                              ' __in  LONG lcid
   , BYVAL sFirstDayOfWeek AS INTEGER _                 ' __in  SHORT sFirstDayOfWeek
   , BYVAL sFirstWeekOfYear AS WORD _                   ' __in  USHORT sFirstWeekOfYear
   , BYREF rcb AS WORD _                                ' __out USHORT *rcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IGetVBAObject interface
' IID = 91733A60-3F4C-101B-A3F6-00AA0034E4E9
' Inherited interface = IUnknown
' ########################################################################################

$IID_IGetVBAObject = GUID$("{91733A60-3F4C-101B-A3F6-00AA0034E4E9}")

INTERFACE IGetVBAObject $IID_IGetVBAObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppvObj AS IUnknown _                         ' __out void **ppvObj
   , BYVAL dwReserved AS DWORD _                        ' __in  DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' Note: IVBDataObjectFiles and IVBDataObject aren't included in vbinterf.h, but
' are often used in VB ActiveX controls. The DataObject and DataObjectFiles classes
' aren't creatable.

$CLSID_DataObject = GUID$("{2334D2B2-713E-11CF-8AE5-00AA00C00905}")
$CLSID_DataObjectFiles = GUID$("{2334D2B4-713E-11CF-8AE5-00AA00C00905}")

' ########################################################################################
' Interface name = IVBDataObjectFiles
' IID = {2334D2B3-713E-11CF-8AE5-00AA00C00905}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IVBDataObjectFiles_INTERFACE_DEFINED)
    %IVBDataObjectFiles_INTERFACE_DEFINED = 1

$IID_IVBDataObjectFiles = GUID$("{2334D2B3-713E-11CF-8AE5-00AA00C00905}")

INTERFACE IVBDataObjectFiles $IID_IVBDataObjectFiles

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 28
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS WSTRING                                         ' __retval_out BSTR *bstrItem
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plCount
   ' =====================================================================================
   METHOD Add <2> ( _                                   ' VTable offset = 36
     BYVAL bstrFilename AS WSTRING _                    ' __in BSTR bstrFilename
   , OPTIONAL BYVAL vIndex AS VARIANT _                 ' __opt_in VARIANT vIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD Clear <3> ( _                                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <4> ( _                                ' VTable offset = 44
     BYVAL vIndex AS VARIANT _                          ' __in VARIANT vIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 48
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVBDataObjectFiles_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVBDataObject
' IID = {2334D2B1-713E-11CF-8AE5-00AA00C00905}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' Note; VB implementation of IDataObject.
' ########################################################################################

#IF NOT %DEF(%IVBDataObject_INTERFACE_DEFINED)
    %IVBDataObject_INTERFACE_DEFINED = 1

$IID_IVBDataObject = GUID$("{2334D2B1-713E-11CF-8AE5-00AA00C00905}")

INTERFACE IVBDataObject $IID_IVBDataObject

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Clear <1> ( _                                 ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD GetData <2> ( _                               ' VTable offset = 32
     BYVAL sFormat AS INTEGER _                         ' __in short sFormat
   ) AS VARIANT                                         ' __retval_out VARIANT *pvData
   ' =====================================================================================
   METHOD GetFormat <3> ( _                             ' VTable offset = 36
     BYVAL sFormat AS INTEGER _                         ' __in long sFormat
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbFormatSupported
   ' =====================================================================================
   METHOD SetData <4> ( _                               ' VTable offset = 40
     OPTIONAL BYVAL vValue AS VARIANT _                 ' __opt_in VARIANT vValue
   , OPTIONAL BYVAL vFormat AS VARIANT _                ' __opt_in VARIANT vFormat
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Files <5> ( _                           ' VTable offset = 44
   ) AS IVBDataObjectFiles                              ' __retval_out IVBDataObjectFiles **pFiles
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVBDataObject_INTERFACE_DEFINED__ */
