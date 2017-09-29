' ########################################################################################
' Microsoft Windows
' File: ThumbCache.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: ThumbCacheLib
' Version: 0.0, Locale ID = 0
' Library GUID: {4C857096-0514-4D4D-ABD5-DFAAA3C326D2}
' ########################################################################################

#INCLUDE THIS ONCE
%THUMBCACHE_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "shtypes.inc"
#INCLUDE ONCE "shobjidl.inc"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_LocalThumbnailCache = GUID$("{50EF4544-AC9F-4A8E-B21B-8A26180DB13F}")
$CLSID_SharedBitmap = GUID$("{4DB26476-6787-4046-B836-E8412A9E8A27}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ISharedBitmap = GUID$("{091162A4-BC96-411F-AAE8-C5122CD03363}")
$IID_IThumbnailCache = GUID$("{F676C15D-596A-4CE2-8234-33996F445DB1}")
$IID_IThumbnailProvider = GUID$("{E357FCCD-A995-4576-B01F-234630154E96}")

' ========================================================================================
' WTS_FLAGS enum
' ========================================================================================

%WTS_EXTRACT              = 0???
%WTS_INCACHEONLY          = &H1???
%WTS_FASTEXTRACT          = &H2???
%WTS_FORCEEXTRACTION      = &H4???
%WTS_SLOWRECLAIM          = &H8???
%WTS_EXTRACTDONOTCACHE    = &H20???
%WTS_SCALETOREQUESTEDSIZE = &H40???
%WTS_SKIPFASTEXTRACT      = &H80???
%WTS_EXTRACTINPROC        = &H100???

' ========================================================================================
' WTS_CACHEFLAGS enum
' ========================================================================================

%WTS_DEFAULT              = 0???
%WTS_LOWQUALITY           = &H1???
%WTS_CACHED               = &H2???

' ========================================================================================
' WTS_ALPHATYPE enum
' ========================================================================================

%WTSAT_UNKNOWN            = 0???
%WTSAT_RGB                = &H1???
%WTSAT_ARGB               = &H2???

' ========================================================================================
' WTS_THUMBNAILID record
' ========================================================================================

' // Size = 16 bytes
TYPE WTS_THUMBNAILID BYTE
   rgbKey AS GUID   ' BYTE rgbKey[ 16 ]
END TYPE

'#define WTS_E_FAILEDEXTRACTION MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0xB200)
%WTS_E_FAILEDEXTRACTION = &HFFFFb200&


' ########################################################################################
' ISharedBitmap interface
' IID = 091162A4-BC96-411F-AAE8-C5122CD03363
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISharedBitmap_INTERFACE_DEFINED)
    %ISharedBitmap_INTERFACE_DEFINED = 1

INTERFACE ISharedBitmap $IID_ISharedBitmap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSharedBitmap ( _                           ' VTable offset = 12
     BYREF phbm AS DWORD _                              ' __out HBITMAP *phbm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pSize AS SIZE _                              ' __out SIZE *pSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 20
     BYREF pat AS DWORD _                               ' __out WTS_ALPHATYPE *pat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeBitmap ( _                          ' VTable offset = 24
     BYVAL hbm AS DWORD _                               ' __in HBITMAP hbm
   , BYVAL wtsAT AS DWORD _                             ' __in WTS_ALPHATYPE wtsAT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Detach ( _                                    ' VTable offset = 28
     BYREF phbm AS DWORD _                              ' __out HBITMAP *phbm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISharedBitmap_INTERFACE_DEFINED__ */

' ########################################################################################
' IThumbnailCache interface
' IID = F676C15D-596A-4CE2-8234-33996F445DB1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThumbnailCache_INTERFACE_DEFINED)
    %IThumbnailCache_INTERFACE_DEFINED = 1

$IID_IThumbnailCache = GUID$("{F676C15D-596A-4CE2-8234-33996F445DB1}")

INTERFACE IThumbnailCache $IID_IThumbnailCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 12
     BYVAL pShellItem AS IShellItem _                   ' __in IShellItem *pShellItem
   , BYVAL cxyRequestedThumbSize AS DWORD _             ' __in UINT cxyRequestedThumbSize
   , BYVAL flags AS DWORD _                             ' __in WTS_FLAGS flags
   , BYREF ppvThumb AS ISharedBitmap _                  ' __out ISharedBitmap **ppvThumb
   , BYREF pOutFlags AS DWORD _                         ' __out_opt WTS_CACHEFLAGS *pOutFlags
   , BYREF pThumbnailID AS GUID _                       ' __out_opt WTS_THUMBNAILID *pThumbnailID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetThumbnailByID ( _                          ' VTable offset = 16
     BYREF thumbnailID AS GUID _                        ' __in WTS_THUMBNAILID thumbnailID
   , BYVAL cxyRequestedThumbSize AS DWORD _             ' __in UINT cxyRequestedThumbSize
   , BYREF ppvThumb AS ISharedBitmap _                  ' __out ISharedBitmap **ppvThumb
   , BYREF pOutFlags AS DWORD _                         ' __out_opt WTS_CACHEFLAGS *pOutFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThumbnailCache_INTERFACE_DEFINED__ */

' ########################################################################################
' IThumbnailProvider interface
' IID = E357FCCD-A995-4576-B01F-234630154E96
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThumbnailProvider_INTERFACE_DEFINED)
    %IThumbnailProvider_INTERFACE_DEFINED = 1

$IID_IThumbnailProvider = GUID$("{E357FCCD-A995-4576-B01F-234630154E96}")

INTERFACE IThumbnailProvider $IID_IThumbnailProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThumbnail ( _                              ' VTable offset = 12
     BYVAL cx AS DWORD _                                ' __in UINT cx
   , BYREF phbmp AS DWORD _                             ' __out HBITMAP *phbmp
   , BYREF pdwAlpha AS DWORD _                          ' __out WTS_ALPHATYPE *pdwAlpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThumbnailProvider_INTERFACE_DEFINED__ */
