' ########################################################################################
' Microsoft Windows
' File: wmdxva.inc
' Contents: Microsoft Windows Media Technologies
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMDXVA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "mediaobj.inc"
#INCLUDE ONCE "videoacc.inc"

$IID_IWMPlayerTimestampHook = GUID$("{28580DDA-D98E-48D0-B7AE-69E473A02825}")
$IID_IWMCodecVideoAccelerator = GUID$("{990641B0-739F-4E94-A808-9888DA8F75AF}")
$IID_IWMCodecAMVideoAccelerator = GUID$("{D98EE251-34E0-4A2D-9312-9B4C788D9FA1}")

' ########################################################################################
' Interface name = IWMPlayerTimestampHook
' IID = 28580DDA-D98E-48D0-B7AE-69E473A02825
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPlayerTimestampHook_INTERFACE_DEFINED)
    %IWMPlayerTimestampHook_INTERFACE_DEFINED = 1

INTERFACE IWMPlayerTimestampHook $IID_IWMPlayerTimestampHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MapTimestamp ( _                              ' VTable offset = 12
     BYVAL rtIn AS QUAD _                               ' __in REFERENCE_TIME rtIn
   , BYREF prtOut AS QUAD _                             ' __out REFERENCE_TIME *prtOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPlayerTimestampHook_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMCodecAMVideoAccelerator
' IID = D98EE251-34E0-4A2D-9312-9B4C788D9FA1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMCodecAMVideoAccelerator_INTERFACE_DEFINED)
    %IWMCodecAMVideoAccelerator_INTERFACE_DEFINED = 1

INTERFACE IWMCodecAMVideoAccelerator $IID_IWMCodecAMVideoAccelerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAcceleratorInterface ( _                   ' VTable offset = 12
     BYVAL pIAMVA AS IAMVideoAccelerator _              ' __in IAMVideoAccelerator *pIAMVA
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NegotiateConnection ( _                       ' VTable offset = 16
     BYREF pMediaType AS DMO_MEDIA_TYPE _               ' __in DMO_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPlayerNotify ( _                           ' VTable offset = 20
     BYVAL pHook AS IWMPlayerTimestampHook _            ' __in IWMPlayerTimestampHook *pHook
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMCodecAMVideoAccelerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMCodecVideoAccelerator
' IID = 990641B0-739F-4E94-A808-9888DA8F75AF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMCodecVideoAccelerator_INTERFACE_DEFINED)
    %IWMCodecVideoAccelerator_INTERFACE_DEFINED = 1

INTERFACE IWMCodecVideoAccelerator $IID_IWMCodecVideoAccelerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NegotiateConnection ( _                       ' VTable offset = 12
     BYVAL pIAMVA AS IAMVideoAccelerator _              ' __in IAMVideoAccelerator *pIAMVA
   , BYREF pMediaType AS DMO_MEDIA_TYPE _               ' __in DMO_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPlayerNotify ( _                           ' VTable offset = 16
     BYVAL pHook AS IWMPlayerTimestampHook _            ' __in IWMPlayerTimestampHook *pHook
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMCodecVideoAccelerator_INTERFACE_DEFINED__ */
