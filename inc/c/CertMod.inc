' ########################################################################################
' Microsoft Windows
' File: CertMod.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTMOD_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"

%CMM_REFRESHONLY = &H1
%CMM_READONLY    = &H2

$$wszCMM_PROP_NAME = "Name"$$
$$wszCMM_PROP_DESCRIPTION = "Description"$$
$$wszCMM_PROP_COPYRIGHT = "Copyright"$$
$$wszCMM_PROP_FILEVER = "File Version"$$
$$wszCMM_PROP_PRODUCTVER = "Product Version"$$
$$wszCMM_PROP_DISPLAY_HWND = "HWND"$$
$$wszCMM_PROP_ISMULTITHREADED = "IsMultiThreaded"$$

' ########################################################################################
' Interface name = ICertManageModule
' IID = E7D7AD42-BD3D-11D1-9A4D-00C04FC297EB
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertManageModule_INTERFACE_DEFINED)
    %ICertManageModule_INTERFACE_DEFINED = 1

$IID_ICertManageModule = GUID$("{E7D7AD42-BD3D-11D1-9A4D-00C04FC297EB}")

INTERFACE ICertManageModule $IID_ICertManageModule

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 28
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strStorageLocation AS WSTRING _              ' __in BSTR strStorageLocation
   , BYVAL strPropertyName AS WSTRING _                 ' __in BSTR strPropertyName
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarProperty
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 32
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strStorageLocation AS WSTRING _              ' __in BSTR strStorageLocation
   , BYVAL strPropertyName AS WSTRING _                 ' __in BSTR strPropertyName
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYREF pvarProperty AS VARIANT _                    ' __in const VARIANT *pvarProperty
   )                                                    ' void
   ' =====================================================================================
   METHOD Configure ( _                                 ' VTable offset = 36
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL strStorageLocation AS WSTRING _              ' __in BSTR strStorageLocation
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertManageModule_INTERFACE_DEFINED__ */
