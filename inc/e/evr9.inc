' ########################################################################################
' Microsoft Windows
' File: evr9.inc
' Copyright (c) 201q José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVR9_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "mfobjects.inc"
#INCLUDE ONCE "mftransform.inc"
#INCLUDE ONCE "evr.inc"
#INCLUDE ONCE "dxva2api.inc"

' ########################################################################################
' Interface name = IEVRVideoStreamControl
' IID = D0CFE38B-93E7-4772-8957-0400C49A4485
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEVRVideoStreamControl_INTERFACE_DEFINED)
    %IEVRVideoStreamControl_INTERFACE_DEFINED = 1

$IID_IEVRVideoStreamControl = GUID$("{D0CFE38B-93E7-4772-8957-0400C49A4485}")

INTERFACE IEVRVideoStreamControl $IID_IEVRVideoStreamControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetStreamActiveState ( _                      ' VTable offset = 12
     BYVAL fActive AS LONG _                            ' __in BOOL fActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamActiveState ( _                      ' VTable offset = 16
     BYREF lpfActive AS LONG _                          ' __out BOOL *lpfActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEVRVideoStreamControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFVideoProcessor
' IID = 6AB0000C-FECE-4D1F-A2AC-A9573530656E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoProcessor_INTERFACE_DEFINED)
    %IMFVideoProcessor_INTERFACE_DEFINED = 1

$IID_IMFVideoProcessor = GUID$("{6AB0000C-FECE-4D1F-A2AC-A9573530656E}")

INTERFACE IMFVideoProcessor $IID_IMFVideoProcessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAvailableVideoProcessorModes ( _           ' VTable offset = 12
     BYREF lpdwNumProcessingModes AS DWORD _            ' __in UINT *lpdwNumProcessingModes
   , BYREF ppVideoProcessingModes AS GUID _             ' __out GUID **ppVideoProcessingModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorCaps ( _                     ' VTable offset = 16
     BYREF lpVideoProcessorMode AS GUID _               ' __in LPGUID lpVideoProcessorMode
   , BYREF lpVideoProcessorCaps AS DXVA2_VideoProcessorCaps _ ' __out DXVA2_VideoProcessorCaps *lpVideoProcessorCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoProcessorMode ( _                     ' VTable offset = 20
     BYREF lpMode AS GUID _                             ' __out LPGUID lpMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoProcessorMode ( _                     ' VTable offset = 24
     BYREF lpMode AS GUID _                             ' __in LPGUID lpMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpRange ( _                           ' VTable offset = 28
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pPropRange AS DXVA2_ValueRange _             ' __out DXVA2_ValueRange *pPropRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcAmpValues ( _                          ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF Values AS DXVA2_ProcAmpValues _              ' __out DXVA2_ProcAmpValues *Values
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProcAmpValues ( _                          ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pValues AS DXVA2_ProcAmpValues _             ' __in DXVA2_ProcAmpValues *pValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilteringRange ( _                         ' VTable offset = 40
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pPropRange AS DXVA2_ValueRange _             ' __out DXVA2_ValueRange *pPropRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilteringValue ( _                         ' VTable offset = 44
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pValue AS DXVA2_Fixed32 _                    ' __out DXVA2_Fixed32 *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilteringValue ( _                         ' VTable offset = 48
     BYVAL dwProperty AS DWORD _                        ' __in DWORD dwProperty
   , BYREF pValue AS DXVA2_Fixed32 _                    ' __in DXVA2_Fixed32 *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundColor ( _                        ' VTable offset = 52
     BYREF lpClrBkg AS DWORD _                          ' __out COLORREF *lpClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackgroundColor ( _                        ' VTable offset = 56
     BYVAL ClrBkg AS DWORD _                            ' __in COLORREF ClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoProcessor_INTERFACE_DEFINED__ */


' // Size = 48 bytes
TYPE MFVideoAlphaBitmapParams DWORD
   dwFlags      AS DWORD                   ' DWORD
   clrSrcKey    AS DWORD                   ' COLORREF
   rcSrc        AS RECT
   nrcDest      AS MFVideoNormalizedRect
   fAlpha       AS SINGLE                  ' FLOAT
   dwFilterMode AS DWORD                   ' DWORD
END TYPE

' // Size = 4 bytes
UNION MFVideoAlphaBitmap_UNION DWORD
   hdc  AS DWORD       ' HDC
   pDDS AS DWORD PTR   ' IDirect3DSurface9*
END UNION

' // Size = 56 bytes
TYPE MFVideoAlphaBitmap DWORD
   GetBitmapFromDC AS LONG   ' BOOL
   bitmap AS MFVideoAlphaBitmap_UNION
   params AS MFVideoAlphaBitmapParams
END TYPE

' enum MFVideoAlphaBitmapFlags
%MFVideoAlphaBitmap_EntireDDS   = &H1
%MFVideoAlphaBitmap_SrcColorKey = &H2
%MFVideoAlphaBitmap_SrcRect     = &H4
%MFVideoAlphaBitmap_DestRect    = &H8
%MFVideoAlphaBitmap_FilterMode  = &H10
%MFVideoAlphaBitmap_Alpha       = &H20
%MFVideoAlphaBitmap_BitMask     = &H3f


' ########################################################################################
' Interface name = IMFVideoMixerBitmap
' IID = 814C7B20-0FDB-4EEC-AF8F-F957C8F69EDC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoMixerBitmap_INTERFACE_DEFINED)
    %IMFVideoMixerBitmap_INTERFACE_DEFINED = 1

$IID_IMFVideoMixerBitmap = GUID$("{814C7B20-0FDB-4EEC-AF8F-F957C8F69EDC}")

INTERFACE IMFVideoMixerBitmap $IID_IMFVideoMixerBitmap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAlphaBitmap ( _                            ' VTable offset = 12
     BYREF pBmpParms AS MFVideoAlphaBitmap _            ' __in const MFVideoAlphaBitmap *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearAlphaBitmap ( _                          ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAlphaBitmapParameters ( _               ' VTable offset = 20
     BYREF pBmpParms AS MFVideoAlphaBitmapParams _      ' __in const MFVideoAlphaBitmapParams *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlphaBitmapParameters ( _                  ' VTable offset = 24
     BYREF pBmpParms AS MFVideoAlphaBitmapParams _      ' __out MFVideoAlphaBitmapParams *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoMixerBitmap_INTERFACE_DEFINED__ */
