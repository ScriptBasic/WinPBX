' ########################################################################################
' Microsoft Windows
' File: ImageTranscode.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Exposes a method that allows conversion to JPEG or bitmap (BMP) image formats from any
' image type supported by Microsoft Windows.
' Minimum DLL Version: photometadatahandler.dll
' Minimum operating systems: Windows Vista
' ########################################################################################

#INCLUDE THIS ONCE
%IMAGETRANSCODE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "shobjidl.inc"

$CLSID_ImageTranscode = GUID$("{17B75166-928F-417D-9685-64AA135565C1}")
$IID_ITranscodeImage  = GUID$("{BAE86DDD-DC11-421C-B7AB-CC55D1D65C44}")

' enum TI_FLAGS
%TI_BITMAP = 1
%TI_JPEG   = 2

' ########################################################################################
' Interface name = ITranscodeImage
' IID = BAE86DDD-DC11-421C-B7AB-CC55D1D65C44
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITranscodeImage_INTERFACE_DEFINED)
    %ITranscodeImage_INTERFACE_DEFINED = 1

INTERFACE ITranscodeImage $IID_ITranscodeImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TranscodeImage ( _                            ' VTable offset = 12
     BYVAL pShellItem AS IShellItem _                   ' __in IShellItem *pShellItem
   , BYVAL uiMaxWidth AS DWORD _                        ' __in UINT uiMaxWidth
   , BYVAL uiMaxHeight AS DWORD _                       ' __in UINT uiMaxHeight
   , BYVAL flags AS DWORD _                             ' __in DWORD flags
   , BYVAL pvImage AS IStream _                         ' __in IStream *pvImage
   , BYREF puiWidth AS DWORD _                          ' __out UINT *puiWidth
   , BYREF puiHeight AS DWORD _                         ' __out UINT *puiHeight
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITranscodeImage_INTERFACE_DEFINED__ */
