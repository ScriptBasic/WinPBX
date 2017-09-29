' ########################################################################################
' Microsoft Windows
' File: WiaVideo.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: WIAVIDEOLib
' Version: 1.0
' Documentation string: WiaVideo 1.0 Type Library
' Path: C:\WINDOWS\system32\wiavideo.dll
' Library GUID: {1320AD9E-A50F-4ED0-B1A4-4E45EC25005E}
' ########################################################################################

#INCLUDE THIS ONCE
%WIAVIDEO_INC = 1

$PROGID_WiaVideo = "WiaVideo.WiaVideo.1"

$CLSID_WiaVideo = GUID$("{3908C3CD-4478-4536-AF2F-10C25D4EF89A}")
$IID_IWiaVideo  = GUID$("{D52920AA-DB88-41F0-946C-E00DC0A19CFA}")

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' WIAVIDEO_STATE Enumerated Type
' ========================================================================================

%WIAVIDEO_NO_VIDEO         = 1
%WIAVIDEO_CREATING_VIDEO   = 2
%WIAVIDEO_VIDEO_CREATED    = 3
%WIAVIDEO_VIDEO_PLAYING    = 4
%WIAVIDEO_VIDEO_PAUSED     = 5
%WIAVIDEO_DESTROYING_VIDEO = 6

' ########################################################################################
' Interface name = IWiaVideo
' IID = {D52920AA-DB88-41F0-946C-E00DC0A19CFA}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IWiaVideo $IID_IWiaVideo

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET PreviewVisible ( _                      ' VTable offset = 12
   ) AS LONG                                            ' __retval_out BOOL *pbPreviewVisible
   ' =====================================================================================
   PROPERTY SET PreviewVisible ( _                      ' VTable offset = 16
     BYVAL bPreviewVisible AS LONG _                    ' __in BOOL bPreviewVisible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ImagesDirectory ( _                     ' VTable offset = 20
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrImageDirectory
   ' =====================================================================================
   PROPERTY SET ImagesDirectory ( _                     ' VTable offset = 24
     BYVAL bstrImageDirectory AS WSTRING _              ' __in BSTR bstrImageDirectory
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateVideoByWiaDevID ( _                     ' VTable offset = 28
     BYVAL bstrWiaDeviceID AS WSTRING _                 ' __in BSTR bstrWiaDeviceID
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL bStretchToFitParent AS LONG _                ' __in BOOL bStretchToFitParent
   , BYVAL bAutoBeginPlayback AS LONG _                 ' __in BOOL bAutoBeginPlayback
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateVideoByDevNum ( _                       ' VTable offset = 32
     BYVAL uiDeviceNumber AS DWORD _                    ' __in UINT uiDeviceNumber
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL bStretchToFitParent AS LONG _                ' __in BOOL bStretchToFitParent
   , BYVAL bAutoBeginPlayback AS LONG _                 ' __in BOOL bAutoBeginPlayback
   )                                                    ' void
   ' =====================================================================================
   METHOD CreateVideoByName ( _                         ' VTable offset = 36
     BYVAL bstrFriendlyName AS WSTRING _                ' __in BSTR bstrFriendlyName
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL bStretchToFitParent AS LONG _                ' __in BOOL bStretchToFitParent
   , BYVAL bAutoBeginPlayback AS LONG _                 ' __in BOOL bAutoBeginPlayback
   )                                                    ' void
   ' =====================================================================================
   METHOD DestroyVideo ( _                              ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD Play ( _                                      ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD TakePicture ( _                               ' VTable offset = 52
     BYREF pbstrNewImageFilename AS WSTRING _           ' __out BSTR *pbstrNewImageFilename
   )                                                    ' void
   ' =====================================================================================
   METHOD ResizeVideo ( _                               ' VTable offset = 56
     BYVAL bStretchToFitParent AS LONG _                ' __in BOOL bStretchToFitParent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentState ( _                           ' VTable offset = 60
   ) AS LONG                                            ' __retval_out WIAVIDEO_STATE *pState
   ' =====================================================================================

END INTERFACE
