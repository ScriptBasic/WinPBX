' ########################################################################################
' Microsoft Windows
' File: dmodshow.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DMODSHOW_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "mediaobj.inc"

$CLSID_DMOWrapperFilter  = GUID$("{94297043-BD82-4DFD-B0DE-8177739C6D20}")
$CLSID_DMOFilterCategory = GUID$("{BCD5796C-BD52-4D30-AB76-70F975B89199}")

' ########################################################################################
' Interface name = IDMOWrapperFilter
' IID = {52D6F586-9F0F-4824-8FC8-E32CA04930C2}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDMOWrapperFilter = GUID$("{52D6F586-9F0F-4824-8FC8-E32CA04930C2}")

INTERFACE IDMOWrapperFilter $IID_IDMOWrapperFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYREF clsidDMO AS GUID _                           ' __in REFCLSID clsidDMO
   , BYREF catDMO AS GUID _                             ' __in REFCLSID catDMO
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
