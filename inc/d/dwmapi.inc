' ########################################################################################
' Microsoft Windows
' File: dwmapi.inc
' Contents: DWM API declarations
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DWMAPI_INC = 1

#IF NOT %DEF(%MILCORE_KERNEL_COMPONENT)
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "uxtheme.inc"
#ENDIF

'#include <pshpack1.h>

'// Blur behind data structures
%DWM_BB_ENABLE                 = &H00000001???  ' // fEnable has been specified
%DWM_BB_BLURREGION             = &H00000002???  ' // hRgnBlur has been specified
%DWM_BB_TRANSITIONONMAXIMIZED  = &H00000004???  ' // fTransitionOnMaximized has been specified

' // Size = 16 bytes
TYPE DWM_BLURBEHIND BYTE
   dwFlags                AS DWORD   ' DWORD
   fEnable                AS LONG    ' BOOL
   hRgnBlur               AS DWORD   ' HRGN
   fTransitionOnMaximized AS LONG    ' BOOL
END TYPE

'// Window attributes
' enum DWMWINDOWATTRIBUTE
%DWMWA_NCRENDERING_ENABLED         = 1    ' // [get] Is non-client rendering enabled/disabled
%DWMWA_NCRENDERING_POLICY          = 2    ' // [set] Non-client rendering policy
%DWMWA_TRANSITIONS_FORCEDISABLED   = 3    ' // [set] Potentially enable/forcibly disable transitions
%DWMWA_ALLOW_NCPAINT               = 4    ' // [set] Allow contents rendered in the non-client area to be visible on the DWM-drawn frame.
%DWMWA_CAPTION_BUTTON_BOUNDS       = 5    ' // [get] Bounds of the caption button area in window-relative space.
%DWMWA_NONCLIENT_RTL_LAYOUT        = 6    ' // [set] Is non-client content RTL mirrored
%DWMWA_FORCE_ICONIC_REPRESENTATION = 7    ' // [set] Force this window to display iconic thumbnails.
%DWMWA_FLIP3D_POLICY               = 8    ' // [set] Designates how Flip3D will treat the window.
%DWMWA_EXTENDED_FRAME_BOUNDS       = 9    ' // [get] Gets the extended frame bounds rectangle in screen space
%DWMWA_HAS_ICONIC_BITMAP           = 10   ' // [set] Indicates an available bitmap when there is no better thumbnail representation.
%DWMWA_DISALLOW_PEEK               = 11   ' // [set] Don't invoke Peek on the window.
%DWMWA_EXCLUDED_FROM_PEEK          = 12   ' // [set] LivePreview exclusion information
%DWMWA_LAST                        = 13

' // Non-client rendering policy attribute values
' enum DWMNCRENDERINGPOLICY
%DWMNCRP_USEWINDOWSTYLE = 0   ' // Enable/disable non-client rendering based on window style
%DWMNCRP_DISABLED       = 1   ' // Disabled non-client rendering; window style is ignored
%DWMNCRP_ENABLED        = 2   ' // Enabled non-client rendering; window style is ignored
%DWMNCRP_LAST           = 3

' // Values designating how Flip3D treats a given window.
' enum DWMFLIP3DWINDOWPOLICY
%DWMFLIP3D_DEFAULT      = 0   ' // Hide or include the window in Flip3D based on window style and visibility.
%DWMFLIP3D_EXCLUDEBELOW = 1   ' // Display the window under Flip3D and disabled.
%DWMFLIP3D_EXCLUDEABOVE = 2   ' // Display the window above Flip3D and enabled.
%DWMFLIP3D_LAST         = 3

' // Thumbnails
'typedef HANDLE HTHUMBNAIL;
'typedef HTHUMBNAIL* PHTHUMBNAIL;

%DWM_TNP_RECTDESTINATION       = &H00000001???
%DWM_TNP_RECTSOURCE            = &H00000002???
%DWM_TNP_OPACITY               = &H00000004???
%DWM_TNP_VISIBLE               = &H00000008???
%DWM_TNP_SOURCECLIENTAREAONLY  = &H00000010???

' // Size = 45 bytes
TYPE DWM_THUMBNAIL_PROPERTIES BYTE
   dwFlags               AS DWORD   ' DWORD
   rcDestination         AS RECT
   rcSource              AS RECT
   opacity               AS BYTE    ' BYTE
   fVisible              AS LONG    ' BOOL
   fSourceClientAreaOnly AS LONG    ' BOOL
END TYPE

' // Video enabling apis

'typedef ULONGLONG DWM_FRAME_COUNT;
'typedef ULONGLONG QPC_TIME;

' // Size = 8 bytes
TYPE UNSIGNED_RATIO BYTE
   uiNumerator   AS DWORD   ' UINT32
   uiDenominator AS DWORD   ' UINT32
END TYPE

'typedef  struct _DWM_TIMING_INFO
'{
'    UINT32          cbSize;

'    // Data on DWM composition overall

'    // Monitor refresh rate
'    UNSIGNED_RATIO  rateRefresh;

'    // Actual period
'    QPC_TIME        qpcRefreshPeriod;

'    // composition rate
'    UNSIGNED_RATIO  rateCompose;

'    // QPC time at a VSync interupt
'    QPC_TIME        qpcVBlank;

'    // DWM refresh count of the last vsync
'    // DWM refresh count is a 64bit number where zero is
'    // the first refresh the DWM woke up to process
'    DWM_FRAME_COUNT cRefresh;

'    // DX refresh count at the last Vsync Interupt
'    // DX refresh count is a 32bit number with zero
'    // being the first refresh after the card was initialized
'    // DX increments a counter when ever a VSync ISR is processed
'    // It is possible for DX to miss VSyncs
'    //
'    // There is not a fixed mapping between DX and DWM refresh counts
'    // because the DX will rollover and may miss VSync interupts
'    UINT cDXRefresh;

'    // QPC time at a compose time.
'    QPC_TIME        qpcCompose;

'    // Frame number that was composed at qpcCompose
'    DWM_FRAME_COUNT cFrame;

'    // The present number DX uses to identify renderer frames
'    UINT            cDXPresent;

'    // Refresh count of the frame that was composed at qpcCompose
'    DWM_FRAME_COUNT cRefreshFrame;


'    // DWM frame number that was last submitted
'    DWM_FRAME_COUNT cFrameSubmitted;

'    // DX Present number that was last submitted
'    UINT cDXPresentSubmitted;

'    // DWM frame number that was last confirmed presented
'    DWM_FRAME_COUNT cFrameConfirmed;

'    // DX Present number that was last confirmed presented
'    UINT cDXPresentConfirmed;

'    // The target refresh count of the last
'    // frame confirmed completed by the GPU
'    DWM_FRAME_COUNT cRefreshConfirmed;

'    // DX refresh count when the frame was confirmed presented
'    UINT cDXRefreshConfirmed;

'    // Number of frames the DWM presented late
'    // AKA Glitches
'    DWM_FRAME_COUNT          cFramesLate;

'    // the number of composition frames that
'    // have been issued but not confirmed completed
'    UINT          cFramesOutstanding;


'    // Following fields are only relavent when an HWND is specified
'    // Display frame


'    // Last frame displayed
'    DWM_FRAME_COUNT cFrameDisplayed;

'    // QPC time of the composition pass when the frame was displayed
'    QPC_TIME        qpcFrameDisplayed;

'    // Count of the VSync when the frame should have become visible
'    DWM_FRAME_COUNT cRefreshFrameDisplayed;

'    // Complete frames: DX has notified the DWM that the frame is done rendering

'    // ID of the the last frame marked complete (starts at 0)
'    DWM_FRAME_COUNT cFrameComplete;

'    // QPC time when the last frame was marked complete
'    QPC_TIME        qpcFrameComplete;

'    // Pending frames:
'    // The application has been submitted to DX but not completed by the GPU

'    // ID of the the last frame marked pending (starts at 0)
'    DWM_FRAME_COUNT cFramePending;

'    // QPC time when the last frame was marked pending
'    QPC_TIME        qpcFramePending;

'    // number of unique frames displayed
'    DWM_FRAME_COUNT cFramesDisplayed;

'    // number of new completed frames that have been received
'    DWM_FRAME_COUNT cFramesComplete;

'     // number of new frames submitted to DX but not yet complete
'    DWM_FRAME_COUNT cFramesPending;

'    // number of frames available but not displayed, used or dropped
'    DWM_FRAME_COUNT cFramesAvailable;

'    // number of rendered frames that were never
'    // displayed because composition occured too late
'    DWM_FRAME_COUNT cFramesDropped;

'    // number of times an old frame was composed
'    // when a new frame should have been used
'    // but was not available
'    DWM_FRAME_COUNT cFramesMissed;

'    // the refresh at which the next frame is
'    // scheduled to be displayed
'    DWM_FRAME_COUNT cRefreshNextDisplayed;

'    // the refresh at which the next DX present is
'    // scheduled to be displayed
'    DWM_FRAME_COUNT cRefreshNextPresented;

'    // The total number of refreshes worth of content
'    // for this HWND that have been displayed by the DWM
'    // since DwmSetPresentParameters was called
'    DWM_FRAME_COUNT cRefreshesDisplayed;

'    // The total number of refreshes worth of content
'    // that have been presented by the application
'    // since DwmSetPresentParameters was called
'    DWM_FRAME_COUNT cRefreshesPresented;


'    // The actual refresh # when content for this
'    // window started to be displayed
'    // it may be different than that requested
'    // DwmSetPresentParameters
'    DWM_FRAME_COUNT cRefreshStarted;

'    // Total number of pixels DX redirected
'    // to the DWM.
'    // If Queueing is used the full buffer
'    // is transfered on each present.
'    // If not queuing it is possible only
'    // a dirty region is updated
'    ULONGLONG  cPixelsReceived;

'    // Total number of pixels drawn.
'    // Does not take into account if
'    // if the window is only partial drawn
'    // do to clipping or dirty rect management
'    ULONGLONG  cPixelsDrawn;

'    // The number of buffers in the flipchain
'    // that are empty.   An application can
'    // present that number of times and guarantee
'    // it won't be blocked waiting for a buffer to
'    // become empty to present to
'    DWM_FRAME_COUNT      cBuffersEmpty;

'} DWM_TIMING_INFO;

' // Size = 292 bytes
TYPE DWM_TIMING_INFO BYTE
   cbSize                 AS DWORD            ' UINT32
   rateRefresh            AS UNSIGNED_RATIO
   qpcRefreshPeriod       AS QUAD             ' QPC_TIME
   rateCompose            AS UNSIGNED_RATIO
   qpcVBlank              AS QUAD             ' QPC_TIME
   cRefresh               AS QUAD             ' DWM_FRAME_COUNT
   cDXRefresh             AS DWORD            ' UINT
   qpcCompose             AS QUAD             ' QPC_TIME
   cFrame                 AS QUAD             ' DWM_FRAME_COUNT
   cDXPresent             AS DWORD            ' UINT
   cRefreshFrame          AS QUAD             ' DWM_FRAME_COUNT
   cFrameSubmitted        AS QUAD             ' DWM_FRAME_COUNT
   cDXPresentSubmitted    AS DWORD            ' UINT
   cFrameConfirmed        AS QUAD             ' DWM_FRAME_COUNT
   cDXPresentConfirmed    AS DWORD            ' UINT
   cRefreshConfirmed      AS QUAD             ' DWM_FRAME_COUNT
   cDXRefreshConfirmed    AS DWORD            ' UINT
   cFramesLate            AS QUAD             ' DWM_FRAME_COUNT
   cFramesOutstanding     AS DWORD            ' UINT
   cFrameDisplayed        AS QUAD             ' DWM_FRAME_COUNT
   qpcFrameDisplayed      AS QUAD             ' QPC_TIME
   cRefreshFrameDisplayed AS QUAD             ' DWM_FRAME_COUNT
   cFrameComplete         AS QUAD             ' DWM_FRAME_COUNT
   qpcFrameComplete       AS QUAD             ' QPC_TIME
   cFramePending          AS QUAD             ' DWM_FRAME_COUNT
   qpcFramePending        AS QUAD             ' QPC_TIME
   cFramesDisplayed       AS QUAD             ' DWM_FRAME_COUNT
   cFramesComplete        AS QUAD             ' DWM_FRAME_COUNT
   cFramesPending         AS QUAD             ' DWM_FRAME_COUNT
   cFramesAvailable       AS QUAD             ' DWM_FRAME_COUNT
   cFramesDropped         AS QUAD             ' DWM_FRAME_COUNT
   cFramesMissed          AS QUAD             ' DWM_FRAME_COUNT
   cRefreshNextDisplayed  AS QUAD             ' DWM_FRAME_COUNT
   cRefreshNextPresented  AS QUAD             ' DWM_FRAME_COUNT
   cRefreshesDisplayed    AS QUAD             ' DWM_FRAME_COUNT
   cRefreshesPresented    AS QUAD             ' DWM_FRAME_COUNT
   cRefreshStarted        AS QUAD             ' DWM_FRAME_COUNT
   cPixelsReceived        AS QUAD             ' ULONGLONG
   cPixelsDrawn           AS QUAD             ' ULONGLONG
   cBuffersEmpty          AS QUAD             ' DWM_FRAME_COUNT
END TYPE

' enum DWM_SOURCE_FRAME_SAMPLING
'// Use the first source frame that
'// includes the first refresh of the output frame
%DWM_SOURCE_FRAME_SAMPLING_POINT = 0

'// use the source frame that includes the most
'// refreshes of out the output frame
'// in case of multiple source frames with the
'// same coverage the last will be used
%DWM_SOURCE_FRAME_SAMPLING_COVERAGE = 1

' // Sentinel value
%DWM_SOURCE_FRAME_SAMPLING_LAST = 2

'static const UINT c_DwmMaxQueuedBuffers = 8;
'static const UINT c_DwmMaxMonitors = 16;
'static const UINT c_DwmMaxAdapters = 16;

%c_DwmMaxQueuedBuffers = 8???
%c_DwmMaxMonitors      = 16???
%c_DwmMaxAdapters      = 16???

' // Size = 40 bytes
TYPE DWM_PRESENT_PARAMETERS BYTE
   cbSize             AS DWORD            ' UINT32
   fQueue             AS LONG             ' BOOL
   cRefreshStart      AS QUAD             ' DWM_FRAME_COUNT
   cBuffer            AS DWORD            ' UINT
   fUseSourceRate     AS LONG             ' BOOL
   rateSource         AS UNSIGNED_RATIO
   cRefreshesPerFrame AS DWORD            ' UINT
   eSampling          AS LONG             ' DWM_SOURCE_FRAME_SAMPLING
END TYPE

%DWM_FRAME_DURATION_DEFAULT = -1

DECLARE FUNCTION DwmDefWindowProc IMPORT "DWMAPI.DLL" ALIAS "DwmDefWindowProc" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL wParam AS DWORD _                              ' __in WPARAM wParam
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYREF plResult AS LONG _                             ' __out LRESULT *plResult
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DwmEnableBlurBehindWindow IMPORT "DWMAPI.DLL" ALIAS "DwmEnableBlurBehindWindow" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pBlurBehind AS DWM_BLURBEHIND _                ' __in const DWM_BLURBEHIND* pBlurBehind
 ) AS LONG                                              ' HRESULT

%DWM_EC_DISABLECOMPOSITION       = 0
%DWM_EC_ENABLECOMPOSITION        = 1

DECLARE FUNCTION DwmEnableComposition IMPORT "DWMAPI.DLL" ALIAS "DwmEnableComposition" ( _
   BYVAL uCompositionAction AS DWORD _                  ' __in UINT uCompositionAction
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmEnableMMCSS IMPORT "DWMAPI.DLL" ALIAS "DwmEnableMMCSS" ( _
   BYVAL fEnableMMCSS AS LONG _                         ' __in BOOL fEnableMMCSS
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmExtendFrameIntoClientArea IMPORT "DWMAPI.DLL" ALIAS "DwmExtendFrameIntoClientArea" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pMarInset AS MARGINS _                         ' __in const MARGINS* pMarInset
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmGetColorizationColor IMPORT "DWMAPI.DLL" ALIAS "DwmGetColorizationColor" ( _
   BYREF pcrColorization AS DWORD _                     ' __out DWORD* pcrColorization
 , BYREF pfOpaqueBlend AS LONG _                        ' __out BOOL* pfOpaqueBlend
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmGetCompositionTimingInfo IMPORT "DWMAPI.DLL" ALIAS "DwmGetCompositionTimingInfo" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pTimingInfo AS DWM_TIMING_INFO _               ' __out DWM_TIMING_INFO* pTimingInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmGetWindowAttribute IMPORT "DWMAPI.DLL" ALIAS "DwmGetWindowAttribute" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwAttribute AS DWORD _                         ' __in DWORD dwAttribute
 , BYREF pvAttribute AS ANY _                           ' __out_bcount(cbAttribute) PVOID pvAttribute
 , BYVAL cbAttribute AS DWORD _                         ' __in DWORD cbAttribute
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmIsCompositionEnabled IMPORT "DWMAPI.DLL" ALIAS "DwmIsCompositionEnabled" ( _
   BYREF pfEnabled AS LONG _                            ' __out BOOL* pfEnabled
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmModifyPreviousDxFrameDuration IMPORT "DWMAPI.DLL" ALIAS "DwmModifyPreviousDxFrameDuration" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL cRefreshes AS LONG _                           ' __in INT cRefreshes
 , BYVAL fRelative AS LONG _                            ' __in BOOL fRelative
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmQueryThumbnailSourceSize IMPORT "DWMAPI.DLL" ALIAS "DwmQueryThumbnailSourceSize" ( _
   BYVAL hThumbnail AS DWORD _                          ' __in HTHUMBNAIL hThumbnail
 , BYREF pSize AS SIZE _                                ' __out PSIZE pSize
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmRegisterThumbnail IMPORT "DWMAPI.DLL" ALIAS "DwmRegisterThumbnail" ( _
   BYVAL hwndDestination AS DWORD _                     ' __in HWND hwndDestination
 , BYVAL hwndSource AS DWORD _                          ' __in HWND hwndSource
 , BYREF phThumbnailId AS DWORD _                       ' __out PHTHUMBNAIL phThumbnailId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmSetDxFrameDuration IMPORT "DWMAPI.DLL" ALIAS "DwmSetDxFrameDuration" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL cRefreshes AS LONG _                           ' __in INT cRefreshes
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmSetPresentParameters IMPORT "DWMAPI.DLL" ALIAS "DwmSetPresentParameters" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pPresentParams AS DWM_PRESENT_PARAMETERS _     ' __inout DWM_PRESENT_PARAMETERS* pPresentParams
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmSetWindowAttribute IMPORT "DWMAPI.DLL" ALIAS "DwmSetWindowAttribute" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwAttribute AS DWORD _                         ' __in DWORD dwAttribute
 , BYREF pvAttribute AS ANY _                           ' __in_bcount(cbAttribute) LPCVOID pvAttribute
 , BYVAL cbAttribute AS DWORD _                         ' __in DWORD cbAttribute
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmUnregisterThumbnail IMPORT "DWMAPI.DLL" ALIAS "DwmUnregisterThumbnail" ( _
   BYVAL hThumbnailId AS DWORD _                        ' __in HTHUMBNAIL hThumbnailId
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmUpdateThumbnailProperties IMPORT "DWMAPI.DLL" ALIAS "DwmUpdateThumbnailProperties" ( _
   BYVAL hThumbnailId AS DWORD _                        ' __in HTHUMBNAIL hThumbnailId
 , BYREF ptnProperties AS DWM_THUMBNAIL_PROPERTIES _    ' __in const DWM_THUMBNAIL_PROPERTIES* ptnProperties
 ) AS LONG                                              ' HRESULT

'#if(_WIN32_WINNT >= 0x0601)
%DWM_SIT_DISPLAYFRAME = &H00000001???   ' // Display a window frame around the provided bitmap

DECLARE FUNCTION DwmSetIconicThumbnail IMPORT "DWMAPI.DLL" ALIAS "DwmSetIconicThumbnail" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hbmp AS DWORD _                                ' __in HBITMAP hbmp
 , BYVAL dwSITFlags AS DWORD _                          ' __in DWORD dwSITFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmSetIconicLivePreviewBitmap IMPORT "DWMAPI.DLL" ALIAS "DwmSetIconicLivePreviewBitmap" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hbmp AS DWORD _                                ' __in HBITMAP hbmp
 , BYREF pptClient AS POINT _                           ' __in_opt POINT *pptClient
 , BYVAL dwSITFlags AS DWORD _                          ' __in DWORD dwSITFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmInvalidateIconicBitmaps IMPORT "DWMAPI.DLL" ALIAS "DwmInvalidateIconicBitmaps" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

'#endif /* _WIN32_WINNT >= 0x0601 */

DECLARE FUNCTION DwmAttachMilContent IMPORT "DWMAPI.DLL" ALIAS "DwmAttachMilContent" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmDetachMilContent IMPORT "DWMAPI.DLL" ALIAS "DwmDetachMilContent" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmFlush IMPORT "DWMAPI.DLL" ALIAS "DwmFlush" ( _
 ) AS LONG                                              ' HRESULT

#IF NOT %DEF(%MILCORE_KERNEL_COMPONENT)
#IF NOT %DEF(%MIL_MATRIX3X2D_DEFINED)

' // Size = 48 bytes
TYPE MIL_MATRIX3X2D BYTE
   S_11 AS DOUBLE   ' DOUBLE
   S_12 AS DOUBLE   ' DOUBLE
   S_21 AS DOUBLE   ' DOUBLE
   S_22 AS DOUBLE   ' DOUBLE
   DX   AS DOUBLE   ' DOUBLE
   DY   AS DOUBLE   ' DOUBLE
END TYPE

%MIL_MATRIX3X2D_DEFINED = 1

#ENDIF ' // _MIL_MATRIX3X2D_DEFINED

'#ifndef MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
'// Compatibility for Vista dwm api.
'typedef MilMatrix3x2D MIL_MATRIX3X2D;
'#define MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
'#endif MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF

DECLARE FUNCTION DwmGetGraphicsStreamTransformHint IMPORT "DWMAPI.DLL" ALIAS "DwmGetGraphicsStreamTransformHint" ( _
   BYVAL uIndex AS DWORD _                              ' __in UINT uIndex
 , BYREF pTransform AS MIL_MATRIX3X2D _                 ' __out MIL_MATRIX3X2D *pTransform
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DwmGetGraphicsStreamClient IMPORT "DWMAPI.DLL" ALIAS "DwmGetGraphicsStreamClient" ( _
   BYVAL uIndex AS DWORD _                              ' __in UINT uIndex
 , BYREF pClientUuid AS GUID _                          ' __out UUID *pClientUuid
 ) AS LONG                                              ' HRESULT

#ENDIF ' // MILCORE_KERNEL_COMPONENT

DECLARE FUNCTION DwmGetTransportAttributes IMPORT "DWMAPI.DLL" ALIAS "DwmGetTransportAttributes" ( _
   BYREF pfIsRemoting AS LONG _                         ' __out_ecount(1) BOOL *pfIsRemoting
 , BYREF pfIsConnected AS LONG _                        ' __out_ecount(1) BOOL *pfIsConnected
 , BYREF pDwGeneration AS DWORD _                       ' __out_ecount(1) DWORD *pDwGeneration
 ) AS LONG                                              ' HRESULT

'#include <poppack.h>
