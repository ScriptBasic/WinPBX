' ########################################################################################
' Microsoft Windows
' File: ScanProfileUI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: ScanProfilesLib
' Version: 1.0, Locale ID = 0
' Description: scanprofiles 1.0 type library
' Documentation string: ScanProfiles 1.0 Type Library
' Path: C:\Windows\system32\wiascanprofiles.dll
' Library GUID: {77A6BD8A-AB60-49FF-853C-B6EE7BABAF96}
' ########################################################################################

#INCLUDE THIS ONCE
%SCANPROFILEUI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {CB0FC8E5-686A-478B-A252-FDECF8E167B7}
$PROGID_ScanProfileMgr1 = "scanprofiles.scanprofilemgr.1"
' CLSID = {19603261-6059-43DF-B9E1-8B4352825A90}
$PROGID_ScanProfileUI1 = "scanprofiles.scanprofileui.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {CB0FC8E5-686A-478B-A252-FDECF8E167B7}
$PROGID_ScanProfileMgr = "scanprofiles.scanprofilemgr"
' CLSID = {19603261-6059-43DF-B9E1-8B4352825A90}
$PROGID_ScanProfileUI = "scanprofiles.scanprofileui"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_ScanProfileMgr = GUID$("{CB0FC8E5-686A-478B-A252-FDECF8E167B7}")
$CLSID_ScanProfileUI = GUID$("{19603261-6059-43DF-B9E1-8B4352825A90}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IScanProfile = GUID$("{D68A6C07-9FF8-47D1-9A2A-429D28FBC6A4}")
$IID_IScanProfileMgr = GUID$("{34EAAE27-2D89-4278-84EF-61DEFA323FC1}")
$IID_IScanProfileUI = GUID$("{B67CDDB7-2B20-473E-8D6C-3F1BD202E78D}")

' ########################################################################################
' Interface name = IScanProfileMgr
' IID = {34EAAE27-2D89-4278-84EF-61DEFA323FC1}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IScanProfileMgr_INTERFACE_DEFINED)
    %IScanProfileMgr_INTERFACE_DEFINED = 1

INTERFACE IScanProfileMgr $IID_IScanProfileMgr

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetNumProfiles <1610743808> ( _               ' VTable offset = 28
     BYREF pulNumProfiles AS DWORD _                    ' __out ULONG * pulNumProfiles
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumProfilesforDeviceID <1610743809> ( _    ' VTable offset = 32
     BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pulNumProfiles AS DWORD _                    ' __out ULONG * pulNumProfiles
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProfiles <1610743810> ( _                  ' VTable offset = 36
     BYREF pulNumProfiles AS DWORD _                    ' __out ULONG * pulNumProfiles
   , BYREF ppScanProfile AS IScanProfile _              ' __out IScanProfile ** ppScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProfilesforDeviceID <1610743811> ( _       ' VTable offset = 40
     BYVAL bstrDeviceID AS WSTRING _                    ' __in BSTR bstrDeviceID
   , BYREF pulNumProfiles AS DWORD _                    ' __in_out ULONG * pulNumProfiles
   , BYREF ppScanProfile AS IScanProfile _              ' __out IScanProfile ** ppScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDefaultProfile <1610743812> ( _            ' VTable offset = 44
     BYVAL bstrDeviceID AS WSTRING _                    ' __in  BSTR bstrDeviceID
   , BYREF ppScanProfile AS IScanProfile _              ' __out IScanProfile ** ppScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateProfile <1610743813> ( _                ' VTable offset = 48
     BYVAL bstrDeviceID AS WSTRING _                    ' __in  BSTR bstrDeviceID
   , BYVAL bstrName AS WSTRING _                        ' __in  BSTR bstrName
   , BYVAL guidCategory AS GUID _                       ' __in  GUID guidCategory
   , BYREF ppScanProfile AS IScanProfile _              ' __out IScanProfile ** ppScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD OpenProfile <1610743814> ( _                  ' VTable offset = 52
     BYVAL guid AS GUID _                               ' __in  GUID guid
   , BYREF ppScanProfile AS IScanProfile _              ' __out IScanProfile ** ppScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefault <1610743815> ( _                   ' VTable offset = 56
     BYVAL pScanProfile AS IScanProfile _               ' __in  IScanProfile * pScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteProfile <1610743816> ( _                ' VTable offset = 60
     BYVAL pScanProfile AS IScanProfile _               ' __in  IScanProfile * pScanProfile
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAllProfiles <1610743817> ( _            ' VTable offset = 64
     BYVAL bstrDeviceID AS WSTRING _                    ' __in  BSTR bstrDeviceID
   )                                                    ' void
   ' =====================================================================================
   METHOD DeleteAllProfilesForUser <1610743818> ( _     ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <1610743819> ( _                      ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScanProfileMgr_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScanProfile
' IID = {D68A6C07-9FF8-47D1-9A2A-429D28FBC6A4}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IScanProfile_INTERFACE_DEFINED)
    %IScanProfile_INTERFACE_DEFINED = 1

INTERFACE IScanProfile $IID_IScanProfile

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetGUID <1610743808> ( _                      ' VTable offset = 28
     BYREF pGUID AS GUID _                              ' __out GUID * pGUID
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDeviceID <1610743809> ( _                  ' VTable offset = 32
     BYREF pbstrDeviceID AS WSTRING _                   ' __out BSTR *pbstrDeviceID
   )                                                    ' void
   ' =====================================================================================
   METHOD IsDefault <1610743810> ( _                    ' VTable offset = 36
     BYREF pbDefault AS LONG _                          ' __out BOOL * pbDefault
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <1610743811> ( _                  ' VTable offset = 40
     BYVAL num AS DWORD _                               ' __in  ULONG num
   , BYREF pid AS DWORD _                               ' __in  PROPID * pid
   , BYREF pvar AS PROPVARIANT _                        ' __out PROPVARIANT * pvar
   )                                                    ' void
   ' =====================================================================================
   METHOD SetProperty <1610743812> ( _                  ' VTable offset = 44
     BYVAL num AS DWORD _                               ' __in  ULONG num
   , BYREF pid AS DWORD _                               ' __in  PROPID * pid
   , BYREF pvar AS PROPVARIANT _                        ' __in  PROPVARIANT * pvar
   )                                                    ' void
   ' =====================================================================================
   METHOD GetAllPropIDs <1610743813> ( _                ' VTable offset = 48
     BYREF num AS DWORD _                               ' __in_out ULONG * num
   , BYREF ppid AS DWORD _                              ' __out PROPID * ppid
   )                                                    ' void
   ' =====================================================================================
   METHOD GetNumPropIDS <1610743814> ( _                ' VTable offset = 52
     BYREF num AS DWORD _                               ' __put ULONG * num
   )                                                    ' void
   ' =====================================================================================
   METHOD GetName <1610743815> ( _                      ' VTable offset = 56
     BYREF pbstrName AS WSTRING _                       ' __out BSTR * pbstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD SetName <1610743816> ( _                      ' VTable offset = 60
     BYVAL pbstrName AS WSTRING _                       ' __in  BSTR pbstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD GetItem <1610743817> ( _                      ' VTable offset = 64
     BYREF pguidCategory AS GUID _                      ' __out GUID * pguidCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD SetItem <1610743818> ( _                      ' VTable offset = 68
     BYVAL guidCategory AS GUID _                       ' __in  GUID guidCategory
   )                                                    ' void
   ' =====================================================================================
   METHOD Save <1610743819> ( _                         ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD RemoveProperty <1610743820> ( _               ' VTable offset = 76
     BYVAL num AS DWORD _                               ' __in  ULONG num
   , BYREF pid AS DWORD _                               ' __in  PROPID * pid
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScanProfile_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IScanProfileUI
' IID = {B67CDDB7-2B20-473E-8D6C-3F1BD202E78D}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IScanProfileUI_INTERFACE_DEFINED)
    %IScanProfileUI_INTERFACE_DEFINED = 1

INTERFACE IScanProfileUI $IID_IScanProfileUI

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ScanProfileDialog <1610743808> ( _            ' VTable offset = 28
     BYVAL hwndParent AS DWORD _                        ' __in  HWND hwndParent
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IScanProfileUI_INTERFACE_DEFINED__ */
