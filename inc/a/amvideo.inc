' ########################################################################################
' Microsoft Windows
' File: AMVideo.inc
' Contents: Video related definitions and interfaces for ActiveMovie.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMVIDEO_INC = 1

#INCLUDE ONCE "ddraw.inc"

'// This is an interface on the video renderer that provides information about
'// DirectDraw with respect to its use by the renderer. For example it allows
'// an application to get details of the surface and any hardware capabilities
'// that are available. It also allows someone to adjust the surfaces that the
'// renderer should use and furthermore even set the DirectDraw instance. We
'// allow someone to set the DirectDraw instance because DirectDraw can only
'// be opened once per process so it helps resolve conflicts. There is some
'// duplication in this interface as the hardware/emulated/FOURCCs available
'// can all be found through the IDirectDraw interface, this interface allows
'// simple access to that information without calling the DirectDraw provider
'// itself. The AMDDS prefix is ActiveMovie DirectDraw Switches abbreviated.

%AMDDS_NONE    = &H00          ' // No use for DCI/DirectDraw
%AMDDS_DCIPS   = &H01          ' // Use DCI primary surface
%AMDDS_PS      = &H02          ' // Use DirectDraw primary
%AMDDS_RGBOVR  = &H04          ' // RGB overlay surfaces
%AMDDS_YUVOVR  = &H08          ' // YUV overlay surfaces
%AMDDS_RGBOFF  = &H10          ' // RGB offscreen surfaces
%AMDDS_YUVOFF  = &H20          ' // YUV offscreen surfaces
%AMDDS_RGBFLP  = &H40          ' // RGB flipping surfaces
%AMDDS_YUVFLP  = &H80          ' // YUV flipping surfaces
%AMDDS_ALL     = &HFF          ' // ALL the previous flags
%AMDDS_DEFAULT = %AMDDS_ALL    ' // Use all available surfaces

%AMDDS_YUV     = %AMDDS_YUVOFF OR %AMDDS_YUVOVR OR %AMDDS_YUVFLP
%AMDDS_RGB     = %AMDDS_RGBOFF OR %AMDDS_RGBOVR OR %AMDDS_RGBFLP
%AMDDS_PRIMARY = %AMDDS_DCIPS OR %AMDDS_PS

' ########################################################################################
' Interface name = IDirectDrawVideo
' IID = {36D39EB0-DD75-11CE-BF0E-00AA0055595A}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IDirectDrawVideo = GUID$("{36D39EB0-DD75-11CE-BF0E-00AA0055595A}")

INTERFACE IDirectDrawVideo $IID_IDirectDrawVideo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSwitches ( _                               ' VTable offset = 12
     BYREF pSwitches AS DWORD _                         ' __out DWORD *pSwitches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSwitches ( _                               ' VTable offset = 16
     BYVAL Switches AS DWORD _                          ' __in DWORD Switches
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 20
     BYREF pCaps AS DDCAPS _                            ' __out DDCAPS *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEmulatedCaps ( _                           ' VTable offset = 24
     BYREF pCaps AS DDCAPS _                            ' __out DDCAPS *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceDesc ( _                            ' VTable offset = 28
     BYREF pSurfaceDesc AS DDSURFACEDESC _              ' __out DDSURFACEDESC *pSurfaceDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFourCCCodes ( _                            ' VTable offset = 32
     BYREF pCount AS DWORD _                            ' __out DWORD *pCount
   , BYREF pCodes AS DWORD _                            ' __out DWORD *pCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirectDraw ( _                             ' VTable offset = 36
     BYVAL pDirectDraw AS IDirectDraw _                 ' __in LPDIRECTDRAW pDirectDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 40
     BYREF ppDirectDraw AS IDirectDraw _                ' __out LPDIRECTDRAW *ppDirectDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurfaceType ( _                            ' VTable offset = 44
     BYREF pSurfaceType AS DWORD _                      ' __out DWORD *pSurfaceType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefault ( _                                ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UseScanLine ( _                               ' VTable offset = 52
     BYVAL UseScanLine AS LONG _                        ' __in long UseScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanUseScanLine ( _                            ' VTable offset = 56
     BYREF UseScanLine AS LONG _                        ' __out long *UseScanLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UseOverlayStretch ( _                         ' VTable offset = 60
     BYVAL UseOverlayStretch AS LONG _                  ' __in long UseOverlayStretch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanUseOverlayStretch ( _                      ' VTable offset = 64
     BYREF UseOverlayStretch AS LONG _                  ' __out long *UseOverlayStretch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UseWhenFullScreen ( _                         ' VTable offset = 68
     BYVAL UseWhenFullScreen AS LONG _                  ' __in long UseWhenFullScreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WillUseFullScreen ( _                         ' VTable offset = 72
     BYREF UseWhenFullScreen AS LONG _                  ' __out long *UseWhenFullScreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' Interface name = IQualProp
' IID = {1BD0ECB0-F8E2-11CE-AAC6-0020AF0B99A3}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IQualProp = GUID$("{1BD0ECB0-F8E2-11CE-AAC6-0020AF0B99A3}")

INTERFACE IQualProp $IID_IQualProp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_FramesDroppedInRenderer ( _               ' VTable offset = 12
     BYREF pcFrames AS LONG _                           ' __out int *pcFrames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FramesDrawn ( _                           ' VTable offset = 16
     BYREF pcFramesDrawn AS LONG _                      ' __out int *pcFramesDrawn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AvgFrameRate ( _                          ' VTable offset = 20
     BYREF piAvgFrameRate AS LONG _                     ' __out int *piAvgFrameRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Jitter ( _                                ' VTable offset = 24
     BYREF piJitter AS LONG _                           ' __out int *piJitter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AvgSyncOffset ( _                         ' VTable offset = 28
     BYREF piAvg AS LONG _                              ' __out int *piAvg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DevSyncOffset ( _                         ' VTable offset = 32
     BYREF piDev AS LONG _                              ' __out int *piDev
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'// This interface allows an application or plug in distributor to control a
'// full screen renderer. The Modex renderer supports this interface. When
'// connected a renderer should load the display modes it has available
'// The number of modes available can be obtained through CountModes. Then
'// information on each individual mode is available by calling GetModeInfo
'// and IsModeAvailable. An application may enable and disable any modes
'// by calling the SetEnabled flag with OATRUE or OAFALSE (not C/C++ TRUE
'// and FALSE values) - the current value may be queried by IsModeEnabled

'// A more generic way of setting the modes enabled that is easier to use
'// when writing applications is the clip loss factor. This defines the
'// amount of video that can be lost when deciding which display mode to
'// use. Assuming the decoder cannot compress the video then playing an
'// MPEG file (say 352x288) into a 320x200 display will lose about 25% of
'// the image. The clip loss factor specifies the upper range permissible.
'// To allow typical MPEG video to be played in 320x200 it defaults to 25%


' ########################################################################################
' Interface name = IFullScreenVideo
' IID = {DD1D7110-7836-11CF-BF47-00AA0055595A}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IFullScreenVideo = GUID$("{DD1D7110-7836-11CF-BF47-00AA0055595A}")

INTERFACE IFullScreenVideo $IID_IFullScreenVideo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CountModes ( _                                ' VTable offset = 12
     BYREF pModes AS LONG _                             ' __out long *pModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModeInfo ( _                               ' VTable offset = 16
     BYVAL Mode AS LONG _                               ' __in long Mode
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   , BYREF pDepth AS LONG _                             ' __out long *pDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentMode ( _                            ' VTable offset = 20
     BYREF pMode AS LONG _                              ' __out long *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsModeAvailable ( _                           ' VTable offset = 24
     BYVAL Mode AS LONG _                               ' __in long Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnabled ( _                                ' VTable offset = 28
     BYVAL Mode AS LONG _                               ' __in long Mode
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipFactor ( _                             ' VTable offset = 32
     BYREF pClipFactor AS LONG _                        ' __out long *pClipFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipFactor ( _                             ' VTable offset = 36
     BYVAL ClipFactor AS LONG _                         ' __in long ClipFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMessageDrain ( _                           ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageDrain ( _                           ' VTable offset = 44
     BYREF hwnd AS DWORD _                              ' __out HWND *hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMonitor ( _                                ' VTable offset = 48
     BYVAL Monitor AS LONG _                            ' __in long Monitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitor ( _                                ' VTable offset = 52
     BYREF Monitor AS LONG _                            ' __out long *Monitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HideOnDeactivate ( _                          ' VTable offset = 56
     BYVAL Hide AS LONG _                               ' __in long Hide
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsHideOnDeactivate ( _                        ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCaption ( _                                ' VTable offset = 64
     BYVAL strCaption AS WSTRING _                      ' __in BSTR strCaption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaption ( _                                ' VTable offset = 68
     BYREF pstrCaption AS WSTRING _                     ' __out BSTR *pstrCaption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefault ( _                                ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'// This adds the accelerator table capabilities in fullscreen. This is being
'// added between the original runtime release and the full SDK release. We
'// cannot just add the method to IFullScreenVideo as we don't want to force
'// applications to have to ship the ActiveMovie support DLLs - this is very
'// important to applications that plan on being downloaded over the Internet

' ########################################################################################
' Interface name = IFullScreenVideoEx
' IID = {53479470-F1DD-11CF-BC42-00AA00AC74F6}
' Inherited interface = IFullScreenVideo
' ########################################################################################

$IID_IFullScreenVideoEx = GUID$("{53479470-F1DD-11CF-BC42-00AA00AC74F6}")

INTERFACE IFullScreenVideoEx $IID_IFullScreenVideoEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IFullScreenVideo Methods
   ' =====================================================================================
   METHOD CountModes ( _                                ' VTable offset = 12
     BYREF pModes AS LONG _                             ' __out long *pModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetModeInfo ( _                               ' VTable offset = 16
     BYVAL Mode AS LONG _                               ' __in long Mode
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   , BYREF pDepth AS LONG _                             ' __out long *pDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentMode ( _                            ' VTable offset = 20
     BYREF pMode AS LONG _                              ' __out long *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsModeAvailable ( _                           ' VTable offset = 24
     BYVAL Mode AS LONG _                               ' __in long Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEnabled ( _                                ' VTable offset = 28
     BYVAL Mode AS LONG _                               ' __in long Mode
   , BYVAL bEnabled AS LONG _                           ' __in long bEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipFactor ( _                             ' VTable offset = 32
     BYREF pClipFactor AS LONG _                        ' __out long *pClipFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClipFactor ( _                             ' VTable offset = 36
     BYVAL ClipFactor AS LONG _                         ' __in long ClipFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMessageDrain ( _                           ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMessageDrain ( _                           ' VTable offset = 44
     BYREF hwnd AS DWORD _                              ' __out HWND *hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMonitor ( _                                ' VTable offset = 48
     BYVAL Monitor AS LONG _                            ' __in long Monitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitor ( _                                ' VTable offset = 52
     BYREF Monitor AS LONG _                            ' __out long *Monitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HideOnDeactivate ( _                          ' VTable offset = 56
     BYVAL Hide AS LONG _                               ' __in long Hide
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsHideOnDeactivate ( _                        ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCaption ( _                                ' VTable offset = 64
     BYVAL strCaption AS WSTRING _                      ' __in BSTR strCaption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaption ( _                                ' VTable offset = 68
     BYREF pstrCaption AS WSTRING _                     ' __out BSTR *pstrCaption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefault ( _                                ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFullScreenVideoEx Methods
   ' =====================================================================================
   METHOD SetAcceleratorTable ( _                       ' VTable offset = 76
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL hAccel AS DWORD _                            ' __in HACCEL hAccel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAcceleratorTable ( _                       ' VTable offset = 80
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF phAccel AS DWORD _                           ' __out HACCEL *phAccel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeepPixelAspectRatio ( _                      ' VTable offset = 84
     BYVAL KeepAspect AS LONG _                         ' __in long KeepAspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsKeepPixelAspectRatio ( _                    ' VTable offset = 88
     BYREF pKeepAspect AS LONG _                        ' __out long *pKeepAspect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'// The SDK base classes contain a base video mixer class. Video mixing in a
'// software environment is tricky because we typically have multiple streams
'// each sending data at unpredictable times. To work with this we defined a
'// pin that is the lead pin, when data arrives on this pin we do a mix. As
'// an alternative we may not want to have a lead pin but output samples at
'// predefined spaces, like one every 1/15 of a second, this interfaces also
'// supports that mode of operations (there is a working video mixer sample)

' ########################################################################################
' Interface name = IBaseVideoMixer
' IID = {61DED640-E912-11CE-A099-00AA00479A58}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IBaseVideoMixer = GUID$("{61DED640-E912-11CE-A099-00AA00479A58}")

INTERFACE IBaseVideoMixer $IID_IBaseVideoMixer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetLeadPin ( _                                ' VTable offset = 12
     BYVAL iPin AS LONG _                               ' __in int iPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLeadPin ( _                                ' VTable offset = 88
     BYREF piPin AS LONG _                              ' __out int *piPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputPinCount ( _                          ' VTable offset = 88
     BYREF piPinCount AS LONG _                         ' __out int *piPinCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUsingClock ( _                              ' VTable offset = 88
     BYREF pbValue AS LONG _                            ' __out int *pbValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUsingClock ( _                             ' VTable offset = 88
     BYVAL bValue AS LONG _                             ' __in int bValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClockPeriod ( _                            ' VTable offset = 88
     BYREF pbValue AS LONG _                            ' __out int *pbValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClockPeriod ( _                            ' VTable offset = 88
     BYVAL bValue AS LONG _                             ' __in int bValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


%iPALETTE_COLORS = 256    ' // Maximum colours in palette
%iEGA_COLORS     = 16     ' // Number colours in EGA palette
%iMASK_COLORS    = 3      ' // Maximum three components
%iTRUECOLOR      = 16     ' // Minimum true colour device
%iRED            = 0      ' // Index position for RED mask
%iGREEN          = 1      ' // Index position for GREEN mask
%iBLUE           = 2      ' // Index position for BLUE mask
%iPALETTE        = 8      ' // Maximum colour depth using a palette
%iMAXBITS        = 8      ' // Maximum bits per colour component


'// Used for true colour images that also have a palette

' // Size = 1036 bytes
TYPE TRUECOLORINFO DWORD
   dwBitMasks (%iMASK_COLORS - 1)    AS DWORD      ' DWORD[iMASK_COLORS]
   bmiColors  (%iPALETTE_COLORS -1 ) AS RGBQUAD    ' RGBQUAD[iPALETTE_COLORS]
END TYPE


'// The BITMAPINFOHEADER contains all the details about the video stream such
'// as the actual image dimensions and their pixel depth. A source filter may
'// also request that the sink take only a section of the video by providing a
'// clipping rectangle in rcSource. In the worst case where the sink filter
'// forgets to check this on connection it will simply render the whole thing
'// which isn't a disaster. Ideally a sink filter will check the rcSource and
'// if it doesn't support image extraction and the rectangle is not empty then
'// it will reject the connection. A filter should use SetRectEmpty to reset a
'// rectangle to all zeroes (and IsRectEmpty to later check the rectangle).
'// The rcTarget specifies the destination rectangle for the video, for most
'// source filters they will set this to all zeroes, a downstream filter may
'// request that the video be placed in a particular area of the buffers it
'// supplies in which case it will call QueryAccept with a non empty target

' // Size = 88 bytes
TYPE VIDEOINFOHEADER QWORD FILL
   rcSource        AS RECT              ' RECT // The bit we really want to use
   rcTarget        AS RECT              ' RECT // Where the video should go
   dwBitRate       AS DWORD             ' DWORD // Approximate bit data rate
   dwBitErrorRate  AS DWORD             ' DWORD // Bit error rate for this stream
   AvgTimePerFrame AS QUAD              ' REFERENCE_TIME // Average time per frame (100ns units)
   bmiHeader       AS BITMAPINFOHEADER  ' BITMAPINFOHEADER
END TYPE

'// make sure the pbmi is initialized before using these macros
'#define TRUECOLOR(pbmi)  ((TRUECOLORINFO *)(((LPBYTE)&((pbmi)->bmiHeader)) \
'               + (pbmi)->bmiHeader.biSize))
'#define COLORS(pbmi)   ((RGBQUAD *)(((LPBYTE)&((pbmi)->bmiHeader))    \
'               + (pbmi)->bmiHeader.biSize))
'#define BITMASKS(pbmi)   ((DWORD *)(((LPBYTE)&((pbmi)->bmiHeader))    \
'               + (pbmi)->bmiHeader.biSize))

'// All the image based filters use this to communicate their media types. It's
'// centred principally around the BITMAPINFO. This structure always contains a
'// BITMAPINFOHEADER followed by a number of other fields depending on what the
'// BITMAPINFOHEADER contains. If it contains details of a palettised format it
'// will be followed by one or more RGBQUADs defining the palette. If it holds
'// details of a true colour format then it may be followed by a set of three
'// DWORD bit masks that specify where the RGB data can be found in the image
'// (For more information regarding BITMAPINFOs see the Win32 documentation)

'// The rcSource and rcTarget fields are not for use by filters supplying the
'// data. The destination (target) rectangle should be set to all zeroes. The
'// source may also be zero filled or set with the dimensions of the video. So
'// if the video is 352x288 pixels then set it to (0,0,352,288). These fields
'// are mainly used by downstream filters that want to ask the source filter
'// to place the image in a different position in an output buffer. So when
'// using for example the primary surface the video renderer may ask a filter
'// to place the video images in a destination position of (100,100,452,388)
'// on the display since that's where the window is positioned on the display

'// !!! WARNING !!!
'// DO NOT use this structure unless you are sure that the BITMAPINFOHEADER
'// has a normal biSize == sizeof(BITMAPINFOHEADER) !
'// !!! WARNING !!!

UNION VIDEOINFO_UNION QWORD FILL
   bmiColors  (%iPALETTE_COLORS - 1) AS RGBQUAD         ' RGBQUAD[iPALETTE_COLORS] // Colour palette
   dwBitMasks (%iMASK_COLORS - 1)    AS DWORD           ' DWORD[iMASK_COLORS] // True colour masks
   TrueColorInfo                     AS TRUECOLORINFO   ' TRUECOLORINFO // Both of the above
END UNION

' // Size : 1128 bytes
TYPE VIDEOINFO QWORD FILL
   rcSource        AS RECT               ' RECT // The bit we really want to use
   rcTarget        AS RECT               ' RECT // Where the video should go
   dwBitRate       AS DWORD              ' DWORD // Approximate bit data rate
   dwBitErrorRate  AS DWORD              ' DWORD // Bit error rate for this stream
   AvgTimePerFrame AS QUAD               ' REFERENCE_TIME // Average time per frame (100ns units)
   bmiHeader       AS BITMAPINFOHEADER   ' BITMAPINFOHEADER
   VIDEOINFO_UNION
END TYPE

'// These macros define some standard bitmap format sizes

'#define SIZE_EGA_PALETTE (iEGA_COLORS * sizeof(RGBQUAD))
'#define SIZE_PALETTE (iPALETTE_COLORS * sizeof(RGBQUAD))
'#define SIZE_MASKS (iMASK_COLORS * sizeof(DWORD))
'#define SIZE_PREHEADER (FIELD_OFFSET(VIDEOINFOHEADER,bmiHeader))
'#define SIZE_VIDEOHEADER (sizeof(BITMAPINFOHEADER) + SIZE_PREHEADER)
'// !!! for abnormal biSizes
'// #define SIZE_VIDEOHEADER(pbmi) ((pbmi)->bmiHeader.biSize + SIZE_PREHEADER)

'// DIBSIZE calculates the number of bytes required by an image

'#define WIDTHBYTES(bits) ((DWORD)(((bits)+31) & (~31)) / 8)
'#define DIBWIDTHBYTES(bi) (DWORD)WIDTHBYTES((DWORD)(bi).biWidth * (DWORD)(bi).biBitCount)
'#define _DIBSIZE(bi) (DIBWIDTHBYTES(bi) * (DWORD)(bi).biHeight)
'#define DIBSIZE(bi) ((bi).biHeight < 0 ? (-1)*(_DIBSIZE(bi)) : _DIBSIZE(bi))

'// This compares the bit masks between two VIDEOINFOHEADERs

'#define BIT_MASKS_MATCH(pbmi1,pbmi2)                                \
'    (((pbmi1)->dwBitMasks[iRED] == (pbmi2)->dwBitMasks[iRED]) &&        \
'     ((pbmi1)->dwBitMasks[iGREEN] == (pbmi2)->dwBitMasks[iGREEN]) &&    \
'     ((pbmi1)->dwBitMasks[iBLUE] == (pbmi2)->dwBitMasks[iBLUE]))

'// These zero fill different parts of the VIDEOINFOHEADER structure

'// Only use these macros for pbmi's with a normal BITMAPINFOHEADER biSize
'#define RESET_MASKS(pbmi) (ZeroMemory((PVOID)(pbmi)->dwBitFields,SIZE_MASKS))
'#define RESET_HEADER(pbmi) (ZeroMemory((PVOID)(pbmi),SIZE_VIDEOHEADER))
'#define RESET_PALETTE(pbmi) (ZeroMemory((PVOID)(pbmi)->bmiColors,SIZE_PALETTE));

'#if 0
'// !!! This is the right way to do it, but may break existing code
'#define RESET_MASKS(pbmi) (ZeroMemory((PVOID)(((LPBYTE)(pbmi)->bmiHeader) + \
'         (pbmi)->bmiHeader.biSize,SIZE_MASKS)))
'#define RESET_HEADER(pbmi) (ZeroMemory((PVOID)(pbmi), SIZE_PREHEADER +       \
'         sizeof(BITMAPINFOHEADER)))
'#define RESET_PALETTE(pbmi) (ZeroMemory((PVOID)(((LPBYTE)(pbmi)->bmiHeader) + \
'         (pbmi)->bmiHeader.biSize,SIZE_PALETTE))
'#endif

'// Other (hopefully) useful bits and bobs

'#define PALETTISED(pbmi) ((pbmi)->bmiHeader.biBitCount <= iPALETTE)
'#define PALETTE_ENTRIES(pbmi) ((DWORD) 1 << (pbmi)->bmiHeader.biBitCount)

'// Returns the address of the BITMAPINFOHEADER from the VIDEOINFOHEADER
'#define HEADER(pVideoInfo) (&(((VIDEOINFOHEADER *) (pVideoInfo))->bmiHeader))


'// MPEG variant - includes a DWORD length followed by the
'// video sequence header after the video header.
'//
'// The sequence header includes the sequence header start code and the
'// quantization matrices associated with the first sequence header in the
'// stream so is a maximum of 140 bytes long.

' // Size: 104 bytes
TYPE MPEG1VIDEOINFO QWORD FILL
   hdr                AS VIDEOINFOHEADER   ' VIDEOINFOHEADER // Compatible with VIDEOINFO
   dwStartTimeCode    AS DWORD             ' DWORD // 25-bit Group of pictures time code
                                           '       // at start of data
   cbSequenceHeader   AS DWORD             ' DWORD // Length in bytes of bSequenceHeader
   bSequenceHeader(7) AS BYTE              ' BYTE[1] // Sequence header including
                                           '       // quantization matrices if any
   ' // Note: We are using bSequenceHeader(7) instead of bSequenceHeader(0) to keep 8 bytes alignment
END TYPE

%MAX_SIZE_MPEG1_SEQUENCE_INFO = 140
'#define SIZE_MPEG1VIDEOINFO(pv) (FIELD_OFFSET(MPEG1VIDEOINFO, bSequenceHeader[0]) + (pv)->cbSequenceHeader)
'#define MPEG1_SEQUENCE_INFO(pv) ((const BYTE *)(pv)->bSequenceHeader)


'// Analog video variant - Use this when the format is FORMAT_AnalogVideo
'//
'// rcSource defines the portion of the active video signal to use
'// rcTarget defines the destination rectangle
'//    both of the above are relative to the dwActiveWidth and dwActiveHeight fields
'// dwActiveWidth is currently set to 720 for all formats (but could change for HDTV)
'// dwActiveHeight is 483 for NTSC and 575 for PAL/SECAM  (but could change for HDTV)

' // Size = 48 bytes
TYPE ANALOGVIDEOINFO QWORD FILL
   rcSource        AS RECT    ' RECT // Width max is 720, height varies w/ TransmissionStd
   rcTarget        AS RECT    ' RECT // Where the video should go
   dwActiveWidth   AS DWORD   ' DWORD // Always 720 (CCIR-601 active samples per line)
   dwActiveHeight  AS DWORD   ' DWORD // 483 for NTSC, 575 for PAL/SECAM
   AvgTimePerFrame AS QUAD    ' REFERENCE_TIME // Normal ActiveMovie units (100 nS)
END TYPE

'//
'// AM_KSPROPSETID_FrameStep property set definitions
'//
' enum AM_PROPERTY_FRAMESTEP
' //  Step
%AM_PROPERTY_FRAMESTEP_STEP            = &H01
%AM_PROPERTY_FRAMESTEP_CANCEL          = &H02
' //  S_OK for these 2 means we can - S_FALSE if we can't
%AM_PROPERTY_FRAMESTEP_CANSTEP         = &H03
%AM_PROPERTY_FRAMESTEP_CANSTEPMULTIPLE = &H04

' // Size: 4 bytes
TYPE AM_FRAMESTEP_STEP DWORD
   ' //  1 means step 1 frame forward
   ' //  0 is invalid
   ' //  n (n > 1) means skip n - 1 frames and show the nth
   dwFramesToStep AS DWORD   ' DWORD
END TYPE
