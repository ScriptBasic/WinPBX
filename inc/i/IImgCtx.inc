' ########################################################################################
' Microsoft Windows
' File: IImgCtx.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IIMGCTX_INC = 1

#INCLUDE ONCE "windows.inc"

$CLSID_IImgCtx = GUID$("{3050F3D6-98B5-11CF-BB82-00AA00BDCE0B}")
$IID_IImgCtx   = GUID$("{3050F3D7-98B5-11CF-BB82-00AA00BDCE0B}")

%IMGCHG_SIZE       = &H0001???
%IMGCHG_VIEW       = &H0002???
%IMGCHG_COMPLETE   = &H0004???
%IMGCHG_ANIMATE    = &H0008???
%IMGCHG_MASK       = &H000F???

%IMGLOAD_NOTLOADED = &H00100000???  ' // Image has not yet been loaded
%IMGLOAD_LOADING   = &H00200000???  ' // Image in the process of being loaded
%IMGLOAD_STOPPED   = &H00400000???  ' // Imaged aborted
%IMGLOAD_ERROR     = &H00800000???  ' // Error loading image
%IMGLOAD_COMPLETE  = &H01000000???  ' // Image loaded
%IMGLOAD_MASK      = &H01F00000???

%IMGBITS_NONE      = &H02000000???
%IMGBITS_PARTIAL   = &H04000000???
%IMGBITS_TOTAL     = &H08000000???
%IMGBITS_MASK      = &H0E000000???

%IMGANIM_ANIMATED  = &H10000000???
%IMGANIM_MASK      = &H10000000???

%IMGTRANS_OPAQUE   = &H20000000???
%IMGTRANS_MASK     = &H20000000???

%DWN_COLORMODE     = &H0000003F???  ' // Explicit color mode requested
%DWN_DOWNLOADONLY  = &H00000040???  ' // Download data only, don't decode
%DWN_FORCEDITHER   = &H00000080???  ' // Override automatic dithering
%DWN_RAWIMAGE      = &H00000100???  ' // Disable dithering
%DWN_MIRRORIMAGE   = &H00000200???  ' // Mirror the image


' ========================================================================================
' Callback function prototype
' ========================================================================================
'typedef void (CALLBACK *PFNIMGCTXCALLBACK)(void *, void *);

'SUB FNIMGCTXCALLBACK (BYVAL AS DWORD, BYVAL AS DWORD)

' ########################################################################################
' Interface name = IImgCtx
' IID = {3050F3D7-98B5-11CF-BB82-00AA00BDCE0B}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IImgCtx $IID_IImgCtx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 12
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectChanges ( _                             ' VTable offset = 16
     BYVAL ulChgOn AS DWORD _                           ' __in ULONG ulChgOn
   , BYVAL ulChgOff AS DWORD _                          ' __in ULONG ulChgOff
   , BYVAL fSignal AS LONG _                            ' __in BOOL fSignal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallback ( _                               ' VTable offset = 20
     BYVAL pfn AS DWORD _                               ' __in PFNIMGCTXCALLBACK pfn
   , BYVAL pvPrivateData AS DWORD _                     ' __in void * pvPrivateData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUpdateRects ( _                            ' VTable offset = 28
     BYREF prc AS RECT _                                ' __out struct tagRECT FAR* prc
   , BYREF prcImg AS RECT _                             ' __out struct tagRECT FAR* prcImg
   , BYREF pcrc AS LONG _                               ' __out long FAR* pcrc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStateInfo ( _                              ' VTable offset = 32
     BYREF pulState AS DWORD _                          ' __out ULONG FAR* pulState
   , BYREF psize AS SIZE _                              ' __out struct tagSIZE FAR* psize
   , BYVAL fClearChanges AS LONG _                      ' __in BOOL fClearChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 36
     BYREF phpa AS DWORD _                              ' __out HPALETTE FAR* phpa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 40
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prcBounds AS RECT _                          ' __in struct tagRECT FAR* prcBounds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Tile ( _                                      ' VTable offset = 44
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF pptBackOrg AS POINT _                        ' __in struct tagPOINT FAR* pptBackOrg
   , BYREF prcClip AS RECT _                            ' __in struct tagRECT FAR* prcClip
   , BYREF psize AS SIZE _                              ' __in struct tagSIZE FAR* psize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StretchBlt ( _                                ' VTable offset = 48
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYVAL dstX AS LONG _                               ' __in int dstX
   , BYVAL dstY AS LONG _                               ' __in int dstY
   , BYVAL dstXE AS LONG _                              ' __in int dstXE
   , BYVAL dstYE AS LONG _                              ' __in int dstYE
   , BYVAL srcX AS LONG _                               ' __in int srcX
   , BYVAL srcY AS LONG _                               ' __in int srcY
   , BYVAL srcXE AS LONG _                              ' __in int srcXE
   , BYVAL srcYE AS LONG _                              ' __in int srcYE
   , BYVAL dwROP AS DWORD _                             ' __in int dwROP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
