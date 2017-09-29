' ########################################################################################
' Microsoft Windows
' File: commoncontrols.inc
' Library name: CommonControlObjects
' Version: 0.0, Locale ID = 0
' Library GUID: {BCADA15B-B428-420C-8D28-023590924C9F}
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%COMMONCONTROLS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

'typedef DWORD RGBQUAD;
'typedef IUnknown *HIMAGELIST;

' // Size = 68 bytes
TYPE IMAGELISTDRAWPARAMS DWORD
   cbSize   AS DWORD   ' DWORD
   himl     AS DWORD   ' HIMAGELIST
   i        AS LONG    ' int
   hdcDst   AS DWORD   ' HDC
   x        AS LONG    ' int
   y        AS LONG    ' int
   cx       AS LONG    ' int
   cy       AS LONG    ' int
   xBitmap  AS LONG    ' int
   yBitmap  AS LONG    ' int
   rgbBk    AS DWORD   ' COLORREF
   rgbFg    AS DWORD   ' COLORREF
   fStyle   AS DWORD   ' UINT
   dwRop    AS DWORD   ' DWORD
   fState   AS DWORD   ' DWORD
   Frame    AS DWORD   ' DWORD
   crEffect AS DWORD   ' DWORD
END TYPE

' // Size = 32 bytes
TYPE IMAGEINFO DWORD
   hbmImage AS DWORD   ' HBITMAP
   hbmMask  AS DWORD   ' HBITMAP
   Unused1  AS LONG    ' int
   Unused2  AS LONG    ' int
   rcImage  AS RECT    ' RECT
END TYPE

'#if _WIN32_WINNT >= 0x0600
DECLARE FUNCTION ImageList_CoCreateInstance IMPORT "COMCTL32.DLL" ALIAS "ImageList_CoCreateInstance" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL punkOuter AS IUnknown _                        ' __in_opt  const IUnknown *punkOuter
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
'#endif

%ILIF_ALPHA               = &H00000001???
%ILIF_LOWQUALITY          = &H00000002???
%ILDRF_IMAGELOWQUALITY    = &H00000001???
%ILDRF_OVERLAYLOWQUALITY  = &H00000010???


$CLSID_ImageList = GUID$("{7C476BA2-02B1-48F4-8048-B24619DDC058}")

' ########################################################################################
' Interface name = IImageList
' IID = 46EB5926-582E-4017-9FDF-E8998DAA0950
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IImageList_INTERFACE_DEFINED)
    %IImageList_INTERFACE_DEFINED = 1

$IID_IImageList = GUID$("{46EB5926-582E-4017-9FDF-E8998DAA0950}")

INTERFACE IImageList $IID_IImageList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , BYVAL hbmMask AS DWORD _                           ' __in_opt HBITMAP hbmMask
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceIcon ( _                               ' VTable offset = 16
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL hicon AS DWORD _                             ' __in  HICON hicon
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayImage ( _                           ' VTable offset = 20
     BYVAL image AS LONG _                              ' __in  int image
   , BYVAL iOverlay AS LONG _                           ' __in  int iOverlay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Replace ( _                                   ' VTable offset = 24
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , OPTIONAL BYVAL hbmMask AS DWORD _                  ' __in_opt HBITMAP hbmMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddMasked ( _                                 ' VTable offset = 28
     BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , BYVAL crMask AS DWORD _                            ' __in  COLORREF crMask
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 32
     BYREF pimldp AS IMAGELISTDRAWPARAMS _              ' __in IMAGELISTDRAWPARAMS *pimldp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 36
     BYVAL i AS LONG _                                  ' __in int i
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 40
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL flags AS DWORD _                             ' __in  UINT flags
   , BYREF picon AS DWORD _                             ' __out HICON *picon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageInfo ( _                              ' VTable offset = 44
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF pImageInfo AS IMAGEINFO _                    ' __out IMAGEINFO *pImageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 48
     BYVAL iDst AS LONG _                               ' __in  int iDst
   , BYVAL punkSrc AS IUnknown _                        ' __in  IUnknown *punkSrc
   , BYVAL iSrc AS LONG _                               ' __in  int iSrc
   , BYVAL uFlags AS DWORD _                            ' __in  UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Merge ( _                                     ' VTable offset = 52
     BYVAL i1 AS LONG _                                 ' __in  int i1
   , BYVAL punk2 AS IUnknown _                          ' __in  IUnknown *punk2
   , BYVAL i2 AS LONG _                                 ' __in  int i2
   , BYVAL dx AS LONG _                                 ' __in  int dx
   , BYVAL dy AS LONG _                                 ' __in  int dy
   , BYREF riid AS GUID _                               ' __out REFIID riid
   , BYREF ppv As IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 56
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageRect ( _                              ' VTable offset = 60
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF prc AS RECT _                                ' __out RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconSize ( _                               ' VTable offset = 64
     BYREF cx AS LONG _                                 ' __out int *cx
   , BYREF cy AS LONG _                                 ' __out int *cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconSize ( _                               ' VTable offset = 68
     BYVAL cx AS LONG _                                 ' __in int cx
   , BYVAL cy AS LONG _                                 ' __in int cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageCount ( _                             ' VTable offset = 72
     BYREF pi AS LONG _                                 ' __in *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImageCount ( _                             ' VTable offset = 76
     BYVAL uNewCount AS DWORD _                         ' __in UINT uNewCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBkColor ( _                                ' VTable offset = 80
     BYVAL clrBk AS DWORD _                             ' __in  COLORREF clrBk
   , BYREF pclr AS DWORD _                              ' __out COLORREF *pclr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBkColor ( _                                ' VTable offset = 84
     BYREF pclr AS DWORD _                              ' __out COLORREF *pclr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginDrag ( _                                 ' VTable offset = 88
     BYVAL iTrack AS LONG _                             ' __in int iTrack
   , BYVAL dxHotspot AS LONG _                          ' __in int dxHotspot
   , BYVAL dyHotspot AS LONG _                          ' __in int dyHotspot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndDrag ( _                                   ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragEnter ( _                                 ' VTable offset = 96
     BYVAL hwndLock AS DWORD _                          ' __in_opt HWND hwndLock
   , BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragLeave ( _                                 ' VTable offset = 100
     OPTIONAL BYVAL hwndLock AS DWORD _                 ' __in_opt HWND hwndLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragMove ( _                                  ' VTable offset = 104
     BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDragCursorImage ( _                        ' VTable offset = 108
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL iDrag AS LONG _                              ' __in int iDrag
   , BYVAL dxHotspot AS LONG _                          ' __in int dxHotspot
   , BYVAL dyHotspot AS LONG _                          ' __in int dyHotspot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragShowNolock ( _                            ' VTable offset = 112
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDragImage ( _                              ' VTable offset = 116
     BYREF ppt AS POINT _                               ' __out_opt POINT *ppt
   , BYREF pptHotspot AS POINT _                        ' __out_opt POINT *pptHotspot
   , BYREF riid AS GUID _                               ' __out REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemFlags ( _                              ' VTable offset = 120
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF dwFlags AS DWORD _                           ' __out DWORD *dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayImage ( _                           ' VTable offset = 124
     BYVAL iOverlay AS LONG _                           ' __in  int iOverlay
   , BYREF piIndex AS LONG _                            ' __out int *piIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageList_INTERFACE_DEFINED__ */

%ILR_DEFAULT                  = &H0000
%ILR_HORIZONTAL_LEFT          = &H0000
%ILR_HORIZONTAL_CENTER        = &H0001
%ILR_HORIZONTAL_RIGHT         = &H0002
%ILR_VERTICAL_TOP             = &H0000
%ILR_VERTICAL_CENTER          = &H0010
%ILR_VERTICAL_BOTTOM          = &H0020
%ILR_SCALE_CLIP               = &H0000
%ILR_SCALE_ASPECTRATIO        = &H0100

' ########################################################################################
' Interface name = IImageList2
' IID = 192B9D83-50FC-457B-90A0-2B82A8B5DAE1
' Inherited interface = IImageList
' ########################################################################################

#IF NOT %DEF(%IImageList2_INTERFACE_DEFINED)
    %IImageList2_INTERFACE_DEFINED = 1

%ILGOS_ALWAYS      = &H00000000???
%ILGOS_FROMSTANDBY = &H00000001???
%ILFIP_ALWAYS      = &H00000000???
%ILFIP_FROMSTANDBY = &H00000001???

%ILDI_PURGE        = &H00000001???
%ILDI_STANDBY      = &H00000002???
%ILDI_RESETACCESS  = &H00000004???
%ILDI_QUERYACCESS  = &H00000008???

' // Size = 16 bytes
TYPE IMAGELISTSTATS DWORD
   cbSize   AS DWORD
   cAlloc   AS LONG
   cUsed    AS LONG
   cStandby AS LONG
END TYPE

$IID_IImageList2 = GUID$("{192B9D83-50FC-457B-90A0-2B82A8B5DAE1}")

INTERFACE IImageList2 $IID_IImageList2

   INHERIT IUnknown

   ' =====================================================================================
   ' IImageList methods
   ' =====================================================================================
   METHOD Add ( _                                       ' VTable offset = 12
     BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , BYVAL hbmMask AS DWORD _                           ' __in  HBITMAP hbmMask
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceIcon ( _                               ' VTable offset = 16
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL hicon AS DWORD _                             ' __in  HICON hicon
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayImage ( _                           ' VTable offset = 20
     BYVAL image AS LONG _                              ' __in  int image
   , BYVAL iOverlay AS LONG _                           ' __in  int iOverlay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Replace ( _                                   ' VTable offset = 24
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , BYVAL hbmMask AS DWORD _                           ' __in  HBITMAP hbmMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddMasked ( _                                 ' VTable offset = 28
     BYVAL hbmImage AS DWORD _                          ' __in  HBITMAP hbmImage
   , BYVAL crMask AS DWORD _                            ' __in  COLORREF crMask
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Draw ( _                                      ' VTable offset = 32
     BYREF pimldp AS IMAGELISTDRAWPARAMS _              ' __in IMAGELISTDRAWPARAMS *pimldp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 36
     BYVAL i AS LONG _                                  ' __in int i
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 40
     BYVAL i AS LONG _                                  ' __in  int i
   , BYVAL flags AS DWORD _                             ' __in  UINT flags
   , BYREF picon AS DWORD _                             ' __out HICON *picon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageInfo ( _                              ' VTable offset = 44
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF pImageInfo AS IMAGEINFO _                    ' __out IMAGEINFO *pImageInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 48
     BYVAL iDst AS LONG _                               ' __in  int iDst
   , BYVAL punkSrc AS IUnknown _                        ' __in  IUnknown *punkSrc
   , BYVAL iSrc AS LONG _                               ' __in  int iSrc
   , BYVAL uFlags AS DWORD _                            ' __in  UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Merge ( _                                     ' VTable offset = 52
     BYVAL i1 AS LONG _                                 ' __in  int i1
   , BYVAL punk2 AS IUnknown _                          ' __in  IUnknown *punk2
   , BYVAL i2 AS LONG _                                 ' __in  int i2
   , BYVAL dx AS LONG _                                 ' __in  int dx
   , BYVAL dy AS LONG _                                 ' __in  int dy
   , BYREF riid AS GUID _                               ' __out REFIID riid
   , BYREF ppv As IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 56
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageRect ( _                              ' VTable offset = 60
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF prc AS RECT _                                ' __out RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconSize ( _                               ' VTable offset = 64
     BYREF cx AS LONG _                                 ' __out int *cx
   , BYREF cy AS LONG _                                 ' __out int *cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconSize ( _                               ' VTable offset = 68
     BYVAL cx AS LONG _                                 ' __in int cx
   , BYVAL cy AS LONG _                                 ' __in int cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageCount ( _                             ' VTable offset = 72
     BYREF pi AS LONG _                                 ' __in *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetImageCount ( _                             ' VTable offset = 76
     BYVAL uNewCount AS DWORD _                         ' __in UINT uNewCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBkColor ( _                                ' VTable offset = 80
     BYVAL clrBk AS DWORD _                             ' __in  COLORREF clrBk
   , BYREF pclr AS DWORD _                              ' __out COLORREF *pclr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBkColor ( _                                ' VTable offset = 84
     BYREF pclr AS DWORD _                              ' __out COLORREF *pclr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginDrag ( _                                 ' VTable offset = 88
     BYVAL iTrack AS LONG _                             ' __in int iTrack
   , BYVAL dxHotspot AS LONG _                          ' __in int dxHotspot
   , BYVAL dyHotspot AS LONG _                          ' __in int dyHotspot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndDrag ( _                                   ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragEnter ( _                                 ' VTable offset = 96
     BYVAL hwndLock AS DWORD _                          ' __in HWND hwndLock
   , BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragLeave ( _                                 ' VTable offset = 100
     BYVAL hwndLock AS DWORD _                          ' __in HWND hwndLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragMove ( _                                  ' VTable offset = 104
     BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDragCursorImage ( _                        ' VTable offset = 108
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL iDrag AS LONG _                              ' __in int iDrag
   , BYVAL dxHotspot AS LONG _                          ' __in int dxHotspot
   , BYVAL dyHotspot AS LONG _                          ' __in int dyHotspot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragShowNolock ( _                            ' VTable offset = 112
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDragImage ( _                              ' VTable offset = 116
     BYREF ppt AS POINT _                               ' __out POINT *ppt
   , BYREF pptHotspot AS POINT _                        ' __out POINT *pptHotspot
   , BYREF riid AS GUID _                               ' __out REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out PVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemFlags ( _                              ' VTable offset = 120
     BYVAL i AS LONG _                                  ' __in  int i
   , BYREF dwFlags AS DWORD _                           ' __out DWORD *dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayImage ( _                           ' VTable offset = 124
     BYVAL iOverlay AS LONG _                           ' __in  int iOverlay
   , BYREF piIndex AS LONG _                            ' __out int *piIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ImageList2 methods
   ' =====================================================================================
   METHOD Resize ( _                                    ' VTable offset = 128
     BYVAL cxNewIconSize AS LONG _                      ' __in int cxNewIconSize
   , BYVAL cyNewIconSize AS LONG _                      ' __in int cyNewIconSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginalSize ( _                           ' VTable offset = 132
     BYVAL iImage AS LONG _                             ' __in  int iImage
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF pcx AS LONG _                                ' __out int *pcx
   , BYREF pcy AS LONG _                                ' __out int *pcy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOriginalSize ( _                           ' VTable offset = 136
     BYVAL iImage AS LONG _                             ' __in int iImage
   , BYVAL cx AS LONG _                                 ' __in int cx
   , BYVAL cy AS LONG _                                 ' __in int cy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallback ( _                               ' VTable offset = 140
     OPTIONAL BYVAL punk AS IUnknown _                  ' __in_opt IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallback ( _                               ' VTable offset = 144
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ForceImagePresent ( _                         ' VTable offset = 148
     BYVAL iImage AS LONG _                             ' __in int iImage
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DiscardImages ( _                             ' VTable offset = 152
     BYVAL iFirstImage AS LONG _                        ' __in int iFirstImage
   , BYVAL iLastImage AS LONG _                         ' __in int iLastImage
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreloadImages ( _                             ' VTable offset = 156
     BYREF pimldp AS IMAGELISTDRAWPARAMS _              ' __in IMAGELISTDRAWPARAMS *pimldp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 160
     BYREF pils AS IMAGELISTSTATS _                     ' __inout IMAGELISTSTATS *pils
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 164
     BYVAL cx AS LONG _                                 ' __in int cx
   , BYVAL cy AS LONG _                                 ' __in int cy
   , BYVAL flags AS DWORD _                             ' __in UINT flags
   , BYVAL cInitial AS LONG _                           ' __in int cInitial
   , BYVAL cGrow AS LONG _                              ' __in int cGrow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Replace2 ( _                                  ' VTable offset = 168
     BYVAL i AS LONG _                                  ' __in int i
   , BYVAL hbmImage AS DWORD _                          ' __in HBITMAP hbmImage
   , BYVAL hbmMask AS DWORD _                           ' __in_opt HBITMAP hbmMask
   , BYVAL punk AS IUnknown _                           ' __in_opt IUnknown *punk
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplaceFromImageList ( _                      ' VTable offset = 172
     BYVAL i AS LONG _                                  ' __in int i
   , BYVAL pil AS IImageList _                          ' __in IImageList *pil
   , BYVAL iSrc AS LONG _                               ' __in int iSrc
   , BYVAL punk AS IUnknown _                           ' __in_opt IUnknown *punk
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageList2_INTERFACE_DEFINED__ */
