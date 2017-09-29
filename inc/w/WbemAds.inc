' ########################################################################################
' Microsoft Windows
' File: WbemAds.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WMIEXTENSIONLib
' Version: 1.0, Locale ID = 0
' Documentation string: WMI Extension to DS 1.0 Type Library
' Path: C:\WINDOWS\system32\wbem\wbemads.tlb
' Library GUID: {E503D000-5C7F-11D2-8B74-00104B2AFB41}
' ########################################################################################

#INCLUDE THIS ONCE
%WBEMADS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "wbemdisp.inc"

$CLSID_WMIExtension = GUID$("{F0975AFE-5C7F-11D2-8B74-00104B2AFB41}")
$IID_IWMIExtension  = GUID$("{ADC1F06E-5C7E-11D2-8B74-00104B2AFB41}")

' ########################################################################################
' Interface name = IWMIExtension
' IID = {ADC1F06E-5C7E-11D2-8B74-00104B2AFB41}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IWMIExtension_INTERFACE_DEFINED)
    %IWMIExtension_INTERFACE_DEFINED = 1

INTERFACE IWMIExtension $IID_IWMIExtension

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET WMIObjectPath <1> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *strWMIObjectPath
   ' =====================================================================================
   METHOD GetWMIObject <2> ( _                          ' VTable offset = 32
   ) AS ISWbemObject                                    ' __retval_out ISWbemObject **objWMIObject
   ' =====================================================================================
   METHOD GetWMIServices <3> ( _                        ' VTable offset = 36
   ) AS ISWbemServices                                  ' __retval_out ISWbemServices **objWMIServices
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMIExtension_INTERFACE_DEFINED__ */
