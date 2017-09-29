' ########################################################################################
' Microsoft Windows
' File: control.inc
' Library name: QuartzTypeLib
' Version: 1.0, Locale ID = 0
' Library GUID: {56A868B0-0AD4-11CE-B03A-0020AF0BA770}
' Path: C:\WINDOWS\system32\quartz.dll
' Contents: ActiveMovie control type library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CONTROL_INC = 1

#INCLUDE ONCE "strmif.inc"   ' for the IPin interface

'typedef double REFTIME;
'typedef LONG_PTR OAEVENT;
'typedef LONG_PTR OAHWND;
'typedef long OAFilterState;

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$LIBID_QuartzTypeLib   = GUID$("{56A868B0-0AD4-11CE-B03A-0020AF0BA770}")
$CLSID_FilgraphManager = GUID$("{E436EBB3-524F-11CE-9F53-0020AF0BA770}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IAMCollection     = GUID$("{56A868B9-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IAMStats          = GUID$("{BC9BCF80-DCD2-11D2-ABF6-00A0C905F375}")
$IID_IBasicAudio       = GUID$("{56A868B3-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IBasicVideo       = GUID$("{56A868B5-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IBasicVideo2      = GUID$("{329BB360-F6EA-11D1-9038-00A0C9697298}")
$IID_IDeferredCommand  = GUID$("{56A868B8-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IFilterInfo       = GUID$("{56A868BA-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IMediaControl     = GUID$("{56A868B1-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IMediaEvent       = GUID$("{56A868B6-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IMediaEventEx     = GUID$("{56A868C0-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IMediaPosition    = GUID$("{56A868B2-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IMediaTypeInfo    = GUID$("{56A868BC-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IPinInfo          = GUID$("{56A868BD-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IQueueCommand     = GUID$("{56A868B7-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IRegFilterInfo    = GUID$("{56A868BB-0AD4-11CE-B03A-0020AF0BA770}")
$IID_IVideoWindow      = GUID$("{56A868B4-0AD4-11CE-B03A-0020AF0BA770}")

' ########################################################################################
' Interface name = IAMCollection
' IID = {56A868B9-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAMCollection_INTERFACE_DEFINED)
    %IAMCollection_INTERFACE_DEFINED = 1

INTERFACE IAMCollection $IID_IAMCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1610743808> ( _                  ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   METHOD Item <1610743809> ( _                         ' VTable offset = 32
     BYVAL lItem AS LONG _                              ' __in long lItem
   , BYREF ppUnk AS IUnknown _                          ' __out IUnknown **ppUnk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NewEnum_ <1610743810> ( _               ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMediaControl
' IID = {56A868B1-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMediaControl_INTERFACE_DEFINED)
    %IMediaControl_INTERFACE_DEFINED = 1

INTERFACE IMediaControl $IID_IMediaControl

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Run <1610743808> ( _                          ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <1610743809> ( _                        ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <1610743810> ( _                         ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetState <1610743811> ( _                     ' VTable offset = 40
     BYVAL msTimeout AS LONG _                          ' __in LONG msTimeout
   , BYREF pfs AS LONG _                                ' __out OAFilterState *pfs
   )                                                    ' void
   ' =====================================================================================
   METHOD RenderFile <1610743812> ( _                   ' VTable offset = 44
     BYVAL strFilename AS WSTRING _                     ' __in BSTR strFilename
   )                                                    ' void
   ' =====================================================================================
   METHOD AddSourceFilter <1610743813> ( _              ' VTable offset = 48
     BYVAL strFilename AS WSTRING _                     ' __in BSTR strFilename
   , BYREF ppUnk AS IDispatch _                         ' __out IDispatch **ppUnk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FilterCollection <1610743814> ( _       ' VTable offset = 52
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnk
   ' =====================================================================================
   PROPERTY GET RegFilterCollection <1610743815> ( _    ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnk
   ' =====================================================================================
   METHOD StopWhenReady <1610743816> ( _                ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMediaEvent
' IID = {56A868B6-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMediaEvent_INTERFACE_DEFINED)
    %IMediaEvent_INTERFACE_DEFINED = 1

INTERFACE IMediaEvent $IID_IMediaEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetEventHandle <1610743808> ( _               ' VTable offset = 28
     BYREF hEvent AS LONG _                             ' __out OAEVENT *hEvent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvent <1610743809> ( _                     ' VTable offset = 32
     BYREF lEventCode AS LONG _                         ' __out long *lEventCode
   , BYREF lParam1 AS LONG _                            ' __out LONG_PTR *lParam1
   , BYREF lParam2 AS LONG _                            ' __out LONG_PTR *lParam2
   , BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD WaitForCompletion <1610743810> ( _            ' VTable offset = 36
     BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   , BYREF pEvCode AS LONG _                            ' __out long *pEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelDefaultHandling <1610743811> ( _        ' VTable offset = 40
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDefaultHandling <1610743812> ( _       ' VTable offset = 44
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD FreeEventParams <1610743813> ( _              ' VTable offset = 48
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   , BYVAL lParam1 AS LONG _                            ' __in LONG_PTR lParam1
   , BYVAL lParam2 AS LONG _                            ' __in LONG_PTR lParam2
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMediaEventEx
' IID = {56A868C0-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IMediaEvent
' ########################################################################################

#IF NOT %DEF(%IMediaEventEx_INTERFACE_DEFINED)
    %IMediaEventEx_INTERFACE_DEFINED = 1

INTERFACE IMediaEventEx $IID_IMediaEventEx

   INHERIT IDispatch

   ' =====================================================================================
   ' IMediaEvent Methods
   ' =====================================================================================
   METHOD GetEventHandle <1610743808> ( _               ' VTable offset = 28
     BYREF hEvent AS LONG _                             ' __out OAEVENT *hEvent
   )                                                    ' void
   ' =====================================================================================
   METHOD GetEvent <1610743809> ( _                     ' VTable offset = 32
     BYREF lEventCode AS LONG _                         ' __out long *lEventCode
   , BYREF lParam1 AS LONG _                            ' __out LONG_PTR *lParam1
   , BYREF lParam2 AS LONG _                            ' __out LONG_PTR *lParam2
   , BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD WaitForCompletion <1610743810> ( _            ' VTable offset = 36
     BYVAL msTimeout AS LONG _                          ' __in long msTimeout
   , BYREF pEvCode AS LONG _                            ' __out long *pEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD CancelDefaultHandling <1610743811> ( _        ' VTable offset = 40
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreDefaultHandling <1610743812> ( _       ' VTable offset = 44
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   )                                                    ' void
   ' =====================================================================================
   METHOD FreeEventParams <1610743813> ( _              ' VTable offset = 48
     BYVAL lEvCode AS LONG _                            ' __in long lEvCode
   , BYVAL lParam1 AS LONG _                            ' __in LONG_PTR lParam1
   , BYVAL lParam2 AS LONG _                            ' __in LONG_PTR lParam2
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaEventEx Methods
   ' =====================================================================================
   METHOD SetNotifyWindow <1610809344> ( _              ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in OAHWND hwnd
   , BYVAL lMsg AS LONG _                               ' __in long lMsg
   , BYVAL lInstanceData AS LONG _                      ' __in LONG_PTR lInstanceData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNotifyFlags <1610809345> ( _               ' VTable offset = 56
     BYVAL lNoNotifyFlags AS LONG _                     ' __in long lNoNotifyFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNotifyFlags <1610809346> ( _               ' VTable offset = 60
     BYREF lplNoNotifyFlags AS LONG _                   ' __out long *lplNoNotifyFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaEventEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMediaPosition
' IID = {56A868B2-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMediaPosition_INTERFACE_DEFINED)
    %IMediaPosition_INTERFACE_DEFINED = 1

INTERFACE IMediaPosition $IID_IMediaPosition

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Duration <1610743808> ( _               ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out REFTIME *plength
   ' =====================================================================================
   PROPERTY SET CurrentPosition <1610743809> ( _        ' VTable offset = 32
     BYVAL llTime AS DOUBLE _                           ' __in REFTIME llTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <1610743809> ( _        ' VTable offset = 36
   ) AS DOUBLE                                          ' __retval_out REFTIME *pllTime
   ' =====================================================================================
   PROPERTY GET StopTime <1610743811> ( _               ' VTable offset = 40
   ) AS DOUBLE                                          ' __retval_out REFTIME *pllTime
   ' =====================================================================================
   PROPERTY SET StopTime <1610743811> ( _               ' VTable offset = 44
     BYVAL llTime AS DOUBLE _                           ' __in REFTIME llTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PrerollTime <1610743813> ( _            ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out REFTIME *pllTime
   ' =====================================================================================
   PROPERTY SET PrerollTime <1610743813> ( _            ' VTable offset = 52
     BYVAL llTime AS DOUBLE _                           ' __in REFTIME llTime
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <1610743815> ( _                   ' VTable offset = 56
     BYVAL dRate AS DOUBLE _                            ' __in double dRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <1610743815> ( _                   ' VTable offset = 60
   ) AS DOUBLE                                          ' __retval_out double *pdRate
   ' =====================================================================================
   METHOD CanSeekForward <1610743817> ( _               ' VTable offset = 64
   ) AS LONG                                            ' __retval_out LONG *pCanSeekForward
   ' =====================================================================================
   METHOD CanSeekBackward <1610743818> ( _              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out LONG *pCanSeekBackward
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaPosition_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBasicAudio
' IID = {56A868B3-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBasicAudio_INTERFACE_DEFINED)
    %IBasicAudio_INTERFACE_DEFINED = 1

INTERFACE IBasicAudio $IID_IBasicAudio

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Volume <1610743808> ( _                 ' VTable offset = 28
     BYVAL lVolume AS LONG _                            ' __in long lVolume
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <1610743808> ( _                 ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plVolume
   ' =====================================================================================
   PROPERTY SET Balance <1610743810> ( _                ' VTable offset = 36
     BYVAL lBalance AS LONG _                           ' __in long lBalance
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <1610743810> ( _                ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plBalance
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBasicAudio_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IVideoWindow
' IID = {56A868B4-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IVideoWindow_INTERFACE_DEFINED)
    %IVideoWindow_INTERFACE_DEFINED = 1

INTERFACE IVideoWindow $IID_IVideoWindow

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET Caption <1610743808> ( _                ' VTable offset = 28
     BYVAL strCaption AS WSTRING _                      ' __in BSTR strCaption
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Caption <1610743808> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *strCaption
   ' =====================================================================================
   PROPERTY SET WindowStyle <1610743810> ( _            ' VTable offset = 36
     BYVAL WindowStyle AS LONG _                        ' __in long WindowStyle
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WindowStyle <1610743810> ( _            ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *WindowStyle
   ' =====================================================================================
   PROPERTY SET WindowStyleEx <1610743812> ( _          ' VTable offset = 44
     BYVAL WindowStyleEx AS LONG _                      ' __in long WindowStyleEx
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WindowStyleEx <1610743812> ( _          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *WindowStyleEx
   ' =====================================================================================
   PROPERTY SET AutoShow <1610743814> ( _               ' VTable offset = 52
     BYVAL AutoShow AS LONG _                           ' __in long AutoShow
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AutoShow <1610743814> ( _               ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *AutoShow
   ' =====================================================================================
   PROPERTY SET WindowState <1610743816> ( _            ' VTable offset = 60
     BYVAL WindowState AS LONG _                        ' __in long WindowState
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET WindowState <1610743816> ( _            ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *WindowState
   ' =====================================================================================
   PROPERTY SET BackgroundPalette <1610743818> ( _      ' VTable offset = 68
     BYVAL BackgroundPalette AS LONG _                  ' __in long BackgroundPalette
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BackgroundPalette <1610743818> ( _      ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pBackgroundPalette
   ' =====================================================================================
   PROPERTY SET Visible <1610743820> ( _                ' VTable offset = 76
     BYVAL Visible AS LONG _                            ' __in long Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible <1610743820> ( _                ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *pVisible
   ' =====================================================================================
   PROPERTY SET Left <1610743822> ( _                   ' VTable offset = 84
     BYVAL Left AS LONG _                               ' __in long Left
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <1610743822> ( _                   ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *pLeft
   ' =====================================================================================
   PROPERTY SET Width <1610743824> ( _                  ' VTable offset = 92
     BYVAL Width AS LONG _                              ' __in long Width
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <1610743824> ( _                  ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *pWidth
   ' =====================================================================================
   PROPERTY SET Top <1610743826> ( _                    ' VTable offset = 100
     BYVAL Top AS LONG _                                ' __in long Top
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Top <1610743826> ( _                    ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pTop
   ' =====================================================================================
   PROPERTY SET Height <1610743828> ( _                 ' VTable offset = 108
     BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <1610743828> ( _                 ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *pHeight
   ' =====================================================================================
   PROPERTY SET Owner <1610743830> ( _                  ' VTable offset = 116
     BYVAL Owner AS DWORD _                             ' __in OAHWND Owner
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Owner <1610743830> ( _                  ' VTable offset = 120
   ) AS DWORD                                           ' __retval_out OAHWND *Owner
   ' =====================================================================================
   PROPERTY SET MessageDrain <1610743832> ( _           ' VTable offset = 124
     BYVAL Drain AS DWORD _                             ' __in OAHWND Drain
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MessageDrain <1610743832> ( _           ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out OAHWND *Drain
   ' =====================================================================================
   PROPERTY GET BorderColor <1610743834> ( _            ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *Color
   ' =====================================================================================
   PROPERTY SET BorderColor <1610743834> ( _            ' VTable offset = 136
     BYVAL Color AS LONG _                              ' __in long Color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FullScreenMode <1610743836> ( _         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out long *FullScreenMode
   ' =====================================================================================
   PROPERTY SET FullScreenMode <1610743836> ( _         ' VTable offset = 144
     BYVAL FullScreenMode AS LONG _                     ' __in long FullScreenMode
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWindowForeground <1610743838> ( _          ' VTable offset = 148
     BYVAL Focus AS LONG _                              ' __in long Focus
   )                                                    ' void
   ' =====================================================================================
   METHOD NotifyOwnerMessage <1610743839> ( _           ' VTable offset = 152
     BYVAL hwnd AS DWORD _                              ' __in OAHWND hwnd
   , BYVAL uMsg AS LONG _                               ' __in long uMsg
   , BYVAL wParam AS LONG _                             ' __in LONG_PTR wParam
   , BYVAL lParam AS LONG _                             ' __in LONG_PTR lParam
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWindowPosition <1610743840> ( _            ' VTable offset = 156
     BYVAL Left AS LONG _                               ' __in long Left
   , BYVAL Top AS LONG _                                ' __in long Top
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetWindowPosition <1610743841> ( _            ' VTable offset = 160
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMinIdealImageSize <1610743842> ( _         ' VTable offset = 164
     BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMaxIdealImageSize <1610743843> ( _         ' VTable offset = 168
     BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRestorePosition <1610743844> ( _           ' VTable offset = 172
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD HideCursor <1610743845> ( _                   ' VTable offset = 176
     BYVAL HideCursor AS LONG _                         ' __in long HideCursor
   )                                                    ' void
   ' =====================================================================================
   METHOD IsCursorHidden <1610743846> ( _               ' VTable offset = 180
     BYREF CursorHidden AS LONG _                       ' __out long *CursorHidden
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVideoWindow_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBasicVideo
' IID = {56A868B5-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IBasicVideo_INTERFACE_DEFINED)
    %IBasicVideo_INTERFACE_DEFINED = 1

INTERFACE IBasicVideo $IID_IBasicVideo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET AvgTimePerFrame <1610743808> ( _        ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out REFTIME *pAvgTimePerFrame
   ' =====================================================================================
   PROPERTY GET BitRate <1610743809> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pBitRate
   ' =====================================================================================
   PROPERTY GET BitErrorRate <1610743810> ( _           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pBitErrorRate
   ' =====================================================================================
   PROPERTY GET VideoWidth <1610743811> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pVideoWidth
   ' =====================================================================================
   PROPERTY GET VideoHeight <1610743812> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVideoHeight
   ' =====================================================================================
   PROPERTY SET SourceLeft <1610743813> ( _             ' VTable offset = 48
     BYVAL SourceLeft AS LONG _                         ' __in long SourceLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceLeft <1610743813> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pSourceLeft
   ' =====================================================================================
   PROPERTY SET SourceWidth <1610743815> ( _            ' VTable offset = 56
     BYVAL SourceWidth AS LONG _                        ' __in long SourceWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceWidth <1610743815> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pSourceWidth
   ' =====================================================================================
   PROPERTY SET SourceTop <1610743817> ( _              ' VTable offset = 64
     BYVAL SourceTop AS LONG _                          ' __in long SourceTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceTop <1610743817> ( _              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pSourceTop
   ' =====================================================================================
   PROPERTY SET SourceHeight <1610743819> ( _           ' VTable offset = 72
     BYVAL SourceHeight AS LONG _                       ' __in long SourceHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceHeight <1610743819> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pSourceHeight
   ' =====================================================================================
   PROPERTY SET DestinationLeft <1610743821> ( _        ' VTable offset = 80
     BYVAL DestinationLeft AS LONG _                    ' __in long DestinationLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationLeft <1610743821> ( _        ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pDestinationLeft
   ' =====================================================================================
   PROPERTY SET DestinationWidth <1610743823> ( _       ' VTable offset = 88
     BYVAL DestinationWidth AS LONG _                   ' __in long DestinationWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationWidth <1610743823> ( _       ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pDestinationWidth
   ' =====================================================================================
   PROPERTY SET DestinationTop <1610743825> ( _         ' VTable offset = 96
     BYVAL DestinationTop AS LONG _                     ' __in long DestinationTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationTop <1610743825> ( _         ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pDestinationTop
   ' =====================================================================================
   PROPERTY SET DestinationHeight <1610743827> ( _      ' VTable offset = 104
     BYVAL DestinationHeight AS LONG _                  ' __in long DestinationHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationHeight <1610743827> ( _      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pDestinationHeight
   ' =====================================================================================
   METHOD SetSourcePosition <1610743829> ( _            ' VTable offset = 112
     BYVAL Left AS LONG _                               ' __in long Left
   , BYVAL Top AS LONG _                                ' __in long Top
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSourcePosition <1610743830> ( _            ' VTable offset = 116
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultSourcePosition <1610743831> ( _     ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDestinationPosition <1610743832> ( _       ' VTable offset = 124
     BYVAL Left AS LONG _                               ' __in long Left
   , BYVAL Top AS LONG _                                ' __in long Top
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDestinationPosition <1610743833> ( _       ' VTable offset = 128
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultDestinationPosition <1610743834> ( _ ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVideoSize <1610743835> ( _                 ' VTable offset = 136
     BYREF pWidth AS LONG _                                       ' __out long *pWidth
   , BYREF pHeight AS LONG _                                       ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVideoPaletteEntries <1610743836> ( _       ' VTable offset = 140
     BYVAL StartIndex AS LONG _                         ' __in long StartIndex
   , BYVAL Entries AS LONG _                            ' __in long Entries
   , BYREF pRetrieved AS LONG _                         ' __out long *pRetrieved
   , BYREF pPalette AS LONG _                           ' __out long *pPalette
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentImage <1610743837> ( _              ' VTable offset = 144
     BYREF pBufferSize AS LONG _                        ' __in_out long *pBufferSize
   , BYREF pDIBImage AS LONG _                          ' __out long *pDIBImage
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUsingDefaultSource <1610743838> ( _         ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUsingDefaultDestination <1610743839> ( _    ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBasicVideo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IBasicVideo2
' IID = {329BB360-F6EA-11D1-9038-00A0C9697298}
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IBasicVideo
' ########################################################################################

#IF NOT %DEF(%IBasicVideo2_INTERFACE_DEFINED)
    %IBasicVideo2_INTERFACE_DEFINED = 1

INTERFACE IBasicVideo2 $IID_IBasicVideo2

   INHERIT IDispatch

   ' =====================================================================================
   ' IBasicVideo Methods
   ' =====================================================================================
   PROPERTY GET AvgTimePerFrame <1610743808> ( _        ' VTable offset = 28
   ) AS DOUBLE                                          ' __retval_out REFTIME *pAvgTimePerFrame
   ' =====================================================================================
   PROPERTY GET BitRate <1610743809> ( _                ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pBitRate
   ' =====================================================================================
   PROPERTY GET BitErrorRate <1610743810> ( _           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pBitErrorRate
   ' =====================================================================================
   PROPERTY GET VideoWidth <1610743811> ( _             ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pVideoWidth
   ' =====================================================================================
   PROPERTY GET VideoHeight <1610743812> ( _            ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVideoHeight
   ' =====================================================================================
   PROPERTY SET SourceLeft <1610743813> ( _             ' VTable offset = 48
     BYVAL SourceLeft AS LONG _                         ' __in long SourceLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceLeft <1610743813> ( _             ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pSourceLeft
   ' =====================================================================================
   PROPERTY SET SourceWidth <1610743815> ( _            ' VTable offset = 56
     BYVAL SourceWidth AS LONG _                        ' __in long SourceWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceWidth <1610743815> ( _            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pSourceWidth
   ' =====================================================================================
   PROPERTY SET SourceTop <1610743817> ( _              ' VTable offset = 64
     BYVAL SourceTop AS LONG _                          ' __in long SourceTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceTop <1610743817> ( _              ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pSourceTop
   ' =====================================================================================
   PROPERTY SET SourceHeight <1610743819> ( _           ' VTable offset = 72
     BYVAL SourceHeight AS LONG _                       ' __in long SourceHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceHeight <1610743819> ( _           ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pSourceHeight
   ' =====================================================================================
   PROPERTY SET DestinationLeft <1610743821> ( _        ' VTable offset = 80
     BYVAL DestinationLeft AS LONG _                    ' __in long DestinationLeft
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationLeft <1610743821> ( _        ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pDestinationLeft
   ' =====================================================================================
   PROPERTY SET DestinationWidth <1610743823> ( _       ' VTable offset = 88
     BYVAL DestinationWidth AS LONG _                   ' __in long DestinationWidth
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationWidth <1610743823> ( _       ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *pDestinationWidth
   ' =====================================================================================
   PROPERTY SET DestinationTop <1610743825> ( _         ' VTable offset = 96
     BYVAL DestinationTop AS LONG _                     ' __in long DestinationTop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationTop <1610743825> ( _         ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *pDestinationTop
   ' =====================================================================================
   PROPERTY SET DestinationHeight <1610743827> ( _      ' VTable offset = 104
     BYVAL DestinationHeight AS LONG _                  ' __in long DestinationHeight
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DestinationHeight <1610743827> ( _      ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *pDestinationHeight
   ' =====================================================================================
   METHOD SetSourcePosition <1610743829> ( _            ' VTable offset = 112
     BYVAL Left AS LONG _                               ' __in long Left
   , BYVAL Top AS LONG _                                ' __in long Top
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetSourcePosition <1610743830> ( _            ' VTable offset = 116
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultSourcePosition <1610743831> ( _     ' VTable offset = 120
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDestinationPosition <1610743832> ( _       ' VTable offset = 124
     BYVAL Left AS LONG _                               ' __in long Left
   , BYVAL Top AS LONG _                                ' __in long Top
   , BYVAL Width AS LONG _                              ' __in long Width
   , BYVAL Height AS LONG _                             ' __in long Height
   )                                                    ' void
   ' =====================================================================================
   METHOD GetDestinationPosition <1610743833> ( _       ' VTable offset = 128
     BYREF pLeft AS LONG _                              ' __out long *pLeft
   , BYREF pTop AS LONG _                               ' __out long *pTop
   , BYREF pWidth AS LONG _                             ' __out long *pWidth
   , BYREF pHeight AS LONG _                            ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDefaultDestinationPosition <1610743834> ( _ ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVideoSize <1610743835> ( _                 ' VTable offset = 136
     BYREF pWidth AS LONG _                                       ' __out long *pWidth
   , BYREF pHeight AS LONG _                                       ' __out long *pHeight
   )                                                    ' void
   ' =====================================================================================
   METHOD GetVideoPaletteEntries <1610743836> ( _       ' VTable offset = 140
     BYVAL StartIndex AS LONG _                         ' __in long StartIndex
   , BYVAL Entries AS LONG _                            ' __in long Entries
   , BYREF pRetrieved AS LONG _                         ' __out long *pRetrieved
   , BYREF pPalette AS LONG _                           ' __out long *pPalette
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCurrentImage <1610743837> ( _              ' VTable offset = 144
     BYREF pBufferSize AS LONG _                        ' __in_out long *pBufferSize
   , BYREF pDIBImage AS LONG _                          ' __out long *pDIBImage
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUsingDefaultSource <1610743838> ( _         ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD IsUsingDefaultDestination <1610743839> ( _    ' VTable offset = 152
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IBasicVideo2 Methods
   ' =====================================================================================
   METHOD GetPreferredAspectRatio <1610809344> ( _      ' VTable offset = 156
     BYREF plAspectX AS LONG _                          ' __out long *plAspectX
   , BYREF plAspectY AS LONG _                          ' __out long *plAspectY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBasicVideo2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IDeferredCommand
' IID = {56A868B8-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeferredCommand_INTERFACE_DEFINED)
    %IDeferredCommand_INTERFACE_DEFINED = 1

INTERFACE IDeferredCommand $IID_IDeferredCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Confidence ( _                                ' VTable offset = 16
     BYREF pConfidence AS LONG _                        ' __out LONG *pConfidence
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Postpone ( _                                  ' VTable offset = 20
     BYVAL newtime AS DOUBLE _                          ' __in REFTIME newtime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHResult ( _                                ' VTable offset = 24
     BYREF phrResult AS LONG _                          ' __out HRESULT *phrResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeferredCommand_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IQueueCommand
' IID = {56A868B7-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueueCommand_INTERFACE_DEFINED)
    %IQueueCommand_INTERFACE_DEFINED = 1

INTERFACE IQueueCommand $IID_IQueueCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InvokeAtStreamTime ( _                        ' VTable offset = 12
     BYREF pCmd AS IDeferredCommand _                   ' __out IDeferredCommand **pCmd
   , BYVAL time AS DOUBLE _                             ' __in REFTIME time
   , BYREF iid AS GUID _                                ' __in GUID *iid
   , BYVAL dispidMethod AS LONG _                       ' __in long dispidMethod
   , BYVAL wFlags AS INTEGER _                          ' __in short wFlags
   , BYVAL cArgs AS LONG _                              ' __in long cArgs
   , BYREF pDispParams AS VARIANT _                     ' __in VARIANT *pDispParams
   , BYREF pvarResult AS VARIANT _                      ' __in_out VARIANT *pvarResult
   , BYREF puArgErr AS INTEGER _                        ' __out short *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeAtPresentationTime ( _                  ' VTable offset = 16
     BYREF pCmd AS IDeferredCommand _                   ' __out IDeferredCommand **pCmd
   , BYVAL time AS DOUBLE _                             ' __in REFTIME time
   , BYREF iid AS GUID _                                ' __in GUID *iid
   , BYVAL dispidMethod AS LONG _                       ' __in long dispidMethod
   , BYVAL wFlags AS INTEGER _                          ' __in short wFlags
   , BYVAL cArgs AS LONG _                              ' __in long cArgs
   , BYREF pDispParams AS VARIANT _                     ' __in VARIANT *pDispParams
   , BYREF pvarResult AS VARIANT _                      ' __in_out VARIANT *pvarResult
   , BYREF puArgErr AS INTEGER _                        ' __out short *puArgErr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueueCommand_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFilterInfo
' IID = {56A868BA-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFilterInfo_INTERFACE_DEFINED)
    %IFilterInfo_INTERFACE_DEFINED = 1

INTERFACE IFilterInfo $IID_IFilterInfo

   INHERIT IDispatch

   ' =====================================================================================
   METHOD FindPin <1610743808> ( _                      ' VTable offset = 28
     BYVAL strPinID AS WSTRING _                        ' __in BSTR strPinID
   , BYREF ppUnk AS IDispatch _                         ' __out IDispatch **ppUnk
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Name <1610743809> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *strName
   ' =====================================================================================
   PROPERTY GET VendorInfo <1610743810> ( _             ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *strVendorInfo
   ' =====================================================================================
   PROPERTY GET Filter <1610743811> ( _                 ' VTable offset = 40
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET Pins <1610743812> ( _                   ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppUnk
   ' =====================================================================================
   PROPERTY GET IsFileSource <1610743813> ( _           ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *pbIsSource
   ' =====================================================================================
   PROPERTY GET Filename <1610743814> ( _               ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pstrFilename
   ' =====================================================================================
   PROPERTY SET Filename <1610743814> ( _               ' VTable offset = 56
     BYVAL strFilename AS WSTRING _                     ' __in BSTR strFilename
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IRegFilterInfo
' IID = {56A868BB-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IRegFilterInfo_INTERFACE_DEFINED)
    %IRegFilterInfo_INTERFACE_DEFINED = 1

INTERFACE IRegFilterInfo $IID_IRegFilterInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *strName
   ' =====================================================================================
   METHOD Filter <1610743809> ( _                       ' VTable offset = 32
     BYREF ppUnk AS IDispatch _                         ' __out IDispatch **ppUnk
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegFilterInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMediaTypeInfo
' IID = {56A868BC-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMediaTypeInfo_INTERFACE_DEFINED)
    %IMediaTypeInfo_INTERFACE_DEFINED = 1

INTERFACE IMediaTypeInfo $IID_IMediaTypeInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Type <1610743808> ( _                   ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *strType
   ' =====================================================================================
   PROPERTY GET Subtype <1610743809> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *strType
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaTypeInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IPinInfo
' IID = {56A868BD-0AD4-11CE-B03A-0020AF0BA770}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IPinInfo_INTERFACE_DEFINED)
    %IPinInfo_INTERFACE_DEFINED = 1

INTERFACE IPinInfo $IID_IPinInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Pin <1610743808> ( _                    ' VTable offset = 28
   ) AS IPin                                            ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET ConnectedTo <1610743809> ( _            ' VTable offset = 32
   ) AS IPinInfo                                        ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET ConnectionMediaType <1610743810> ( _    ' VTable offset = 36
   ) AS IMediaTypeInfo                                  ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET FilterInfo <1610743811> ( _             ' VTable offset = 40
   ) AS IFilterInfo                                     ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   PROPERTY GET Name <1610743812> ( _                   ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *strName
   ' =====================================================================================
   PROPERTY GET Direction <1610743813> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out LONG *ppDirection
   ' =====================================================================================
   PROPERTY GET PinID <1610743814> ( _                  ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *strPinID
   ' =====================================================================================
   PROPERTY GET MediaTypes <1610743815> ( _             ' VTable offset = 56
   ) AS IAMCollection                                   ' __retval_out IDispatch **ppDisp
   ' =====================================================================================
   METHOD Connect <1610743816> ( _                      ' VTable offset = 60
     BYVAL pPin AS IPinInfo _                           ' __in IUnknown *pPin
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectDirect <1610743817> ( _                ' VTable offset = 64
     BYVAL pPin AS IPinInfo _                           ' __in IUnknown *pPin
   )                                                    ' void
   ' =====================================================================================
   METHOD ConnectWithType <1610743818> ( _              ' VTable offset = 68
     BYVAL pPin AS IPinInfo _                           ' __in IUnknown *pPin
   , BYVAL pMediaType AS IMediaTypeInfo _               ' __in IDispatch *pMediaType
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <1610743819> ( _                   ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================
   METHOD Render <1610743820> ( _                       ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPinInfo_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAMStats
' IID = {BC9BCF80-DCD2-11D2-ABF6-00A0C905F375}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IAMStats_INTERFACE_DEFINED)
    %IAMStats_INTERFACE_DEFINED = 1

INTERFACE IAMStats $IID_IAMStats

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset <1610743808> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Count <1610743809> ( _                  ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *plCount
   ' =====================================================================================
   METHOD GetValueByIndex <1610743810> ( _              ' VTable offset = 36
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYREF szName AS WSTRING _                          ' __out BSTR *szName
   , BYREF lCount AS LONG _                             ' __out long *lCount
   , BYREF dLast AS DOUBLE _                            ' __out double *dLast
   , BYREF dAverage AS DOUBLE _                         ' __out double *dAverage
   , BYREF dStdDev AS DOUBLE _                          ' __out double *dStdDev
   , BYREF dMin AS DOUBLE _                             ' __out double *dMin
   , BYREF dMax AS DOUBLE _                             ' __out double *dMax
   )                                                    ' void
   ' =====================================================================================
   METHOD GetValueByName <1610743811> ( _               ' VTable offset = 40
     BYVAL szName AS WSTRING _                          ' __in BSTR szName
   , BYREF lIndex AS LONG _                             ' __out long *lIndex
   , BYREF lCount AS LONG _                             ' __out long *lCount
   , BYREF dLast AS DOUBLE _                            ' __out double *dLast
   , BYREF dAverage AS DOUBLE _                         ' __out double *dAverage
   , BYREF dStdDev AS DOUBLE _                          ' __out double *dStdDev
   , BYREF dMin AS DOUBLE _                             ' __out double *dMin
   , BYREF dMax AS DOUBLE _                             ' __out double *dMax
   )                                                    ' void
   ' =====================================================================================
   METHOD GetIndex <1610743812> ( _                     ' VTable offset = 44
     BYVAL szName AS WSTRING _                          ' __in BSTR szName
   , BYVAL lCreate AS LONG _                            ' __in long lCreate
   , BYREF plIndex AS LONG _                            ' __out long *plIndex
   )                                                    ' void
   ' =====================================================================================
   METHOD AddValue <1610743813> ( _                     ' VTable offset = 48
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYVAL dValue AS DOUBLE _                           ' __in double dValue
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMStats_INTERFACE_DEFINED__ */
