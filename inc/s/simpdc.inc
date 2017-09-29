' ########################################################################################
' Microsoft Windows
' File: simpdc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SIMPDC_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ########################################################################################
' ISimpleDataConverter interface
' IID = 78667670-3C3D-11D2-91F9-006097C97F9B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISimpleDataConverter_INTERFACE_DEFINED)
    %ISimpleDataConverter_INTERFACE_DEFINED = 1

$IID_ISimpleDataConverter = GUID$("{78667670-3C3D-11D2-91F9-006097C97F9B}")

INTERFACE ISimpleDataConverter $IID_ISimpleDataConverter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ConvertData ( _                               ' VTable offset = 12
     BYVAL varSrc AS VARIANT _                          ' __in VARIANT varSrc
   , BYVAL vtDest AS LONG _                             ' __in long vtDest
   , BYVAL pUnknownElement AS IUnknown _                ' __in IUnknown *pUnknownElement
   , BYREF pvarDest AS VARIANT _                        ' __out VARIANT *pvarDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanConvertData ( _                            ' VTable offset = 16
     BYVAL vt1 AS LONG _                                ' __in long vt1
   , BYVAL vt2 AS LONG _                                ' __in long vt2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISimpleDataConverter_INTERFACE_DEFINED__ */
