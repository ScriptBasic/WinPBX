' ########################################################################################
' Microsoft Windows
' File: VideoAcc.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BIDEOACC_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "ddraw.inc"
#INCLUDE ONCE "amva.inc"
#INCLUDE ONCE "strmif.inc"

' ########################################################################################
' Interface name = IAMVideoAcceleratorNotify
' IID = {256A6A21-FBAD-11D1-82BF-00A0C9696C8F}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IAMVideoAcceleratorNotify = GUID$("{256A6A21-FBAD-11D1-82BF-00A0C9696C8F}")

INTERFACE IAMVideoAcceleratorNotify $IID_IAMVideoAcceleratorNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetUncompSurfacesInfo ( _                     ' VTable offset = 12
     BYREF pGuid AS GUID _                              ' __in const GUID *pGuid
   , BYREF pUncompBufferInfo AS AMVAUncompBufferInfo _  ' __out LPAMVAUncompBufferInfo pUncompBufferInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUncompSurfacesInfo ( _                     ' VTable offset = 16
     BYVAL dwActualUncompSurfacesAllocated AS DWORD _   ' __in DWORD dwActualUncompSurfacesAllocated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCreateVideoAcceleratorData ( _             ' VTable offset = 20
     BYREF pGuid AS GUID _                              ' __in const GUID *pGuid
   , BYREF pdwSizeMiscData AS DWORD _                   ' __out LPDWORD pdwSizeMiscData
   , BYREF ppMiscData AS DWORD _                        ' __out LPVOID *ppMiscData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IAMVideoAccelerator
' IID = {256A6A22-FBAD-11D1-82BF-00A0C9696C8F}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IAMVideoAccelerator = GUID$("{256A6A22-FBAD-11D1-82BF-00A0C9696C8F}")

INTERFACE IAMVideoAccelerator $IID_IAMVideoAccelerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetVideoAcceleratorGUIDs ( _                  ' VTable offset = 12
     BYREF pdwNumGuidsSupported AS DWORD _              ' __out LPDWORD pdwNumGuidsSupported
   , BYREF pGuidsSupported AS GUID _                    ' __out LPGUID pGuidsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUncompFormatsSupported ( _                 ' VTable offset = 16
     BYREF pGuid AS GUID _                              ' __in const GUID *pGuid
   , BYREF pdwNumFormatsSupported AS DWORD _            ' __out LPDWORD pdwNumFormatsSupported
   , BYREF pFormatsSupported AS DDPIXELFORMAT _         ' __out LPDDPIXELFORMAT pFormatsSupported
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInternalMemInfo ( _                        ' VTable offset = 20
     BYREF pGuid AS GUID _                              ' __in const GUID *pGuid
   , BYREF pamvaUncompDataInfo AS AMVAUncompDataInfo _  ' __in const AMVAUncompDataInfo *pamvaUncompDataInfo
   , BYREF pamvaInternalMemInfo AS AMVAInternalMemInfo _ ' __out LPAMVAInternalMemInfo pamvaInternalMemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompBufferInfo ( _                         ' VTable offset = 24
     BYREF pGuid AS GUID _                              ' __in const GUID *pGuid
   , BYREF pamvaUncompDataInfo AS AMVAUncompDataInfo _  ' __in const AMVAUncompDataInfo *pamvaUncompDataInfo
   , BYREF pdwNumTypesCompBuffers AS DWORD _            ' __out LPDWORD pdwNumTypesCompBuffers
   , BYREF pamvaCompBufferInfo AS AMVACompBufferInfo _  ' __out LPAMVACompBufferInfo pamvaCompBufferInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInternalCompBufferInfo ( _                 ' VTable offset = 28
     BYREF pdwNumTypesCompBuffers AS DWORD _            ' __out LPDWORD pdwNumTypesCompBuffers
   , BYREF pamvaCompBufferInfo AS AMVACompBufferInfo _  ' __out LPAMVACompBufferInfo pamvaCompBufferInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginFrame ( _                                ' VTable offset = 32
     BYREF pamvaBeginFrameInfo AS AMVABeginFrameInfo _  ' __in const AMVABeginFrameInfo *amvaBeginFrameInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndFrame ( _                                  ' VTable offset = 36
     BYREF pEndFrameInfo AS AMVAEndFrameInfo _          ' __in const AMVAEndFrameInfo *pEndFrameInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 40
     BYVAL dwTypeIndex AS DWORD _                       ' __in DWORD dwTypeIndex
   , BYVAL dwBufferIndex AS DWORD _                     ' __in DWORD dwBufferIndex
   , BYVAL bReadOnly AS LONG _                          ' __in BOOL bReadOnly
   , BYREF ppBuffer AS DWORD _                          ' __out LPVOID *ppBuffer
   , BYREF lpStride AS LONG _                           ' __out LONG *lpStride
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 44
     BYVAL dwTypeIndex AS DWORD _                       ' __in DWORD dwTypeIndex
   , BYVAL dwBufferIndex AS DWORD _                     ' __in DWORD dwBufferIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 48
     BYVAL dwFunction AS DWORD _                        ' __in DWORD dwFunction
   , BYVAL lpPrivateInputData AS DWORD _                ' __in LPVOID lpPrivateInputData
   , BYVAL cbPrivateInputData AS DWORD _                ' __in DWORD cbPrivateInputData
   , BYVAL lpPrivateOutputDat AS DWORD _                ' __in LPVOID lpPrivateOutputDat
   , BYVAL cbPrivateOutputData AS DWORD _               ' __in DWORD cbPrivateOutputData
   , BYVAL dwNumBuffers AS DWORD _                      ' __in DWORD dwNumBuffers
   , BYREF pamvaBufferInfo AS AMVABUFFERINFO _          ' __in const AMVABUFFERINFO *pamvaBufferInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryRenderStatus ( _                         ' VTable offset = 52
     BYVAL dwTypeIndex AS DWORD _                       ' __in DWORD dwTypeIndex
   , BYVAL dwBufferIndex AS DWORD _                     ' __in DWORD dwBufferIndex
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayFrame ( _                              ' VTable offset = 56
     BYVAL dwFlipToIndex AS DWORD _                     ' __in DWORD dwFlipToIndex
   , BYVAL pMediaSample AS IMediaSample _               ' __in IMediaSample *pMediaSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
