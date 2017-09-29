' ########################################################################################
' Microsoft Windows
' File: DShow.inc
' Contents: DirectShow
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSHOW_INC = 1

'///////////////////////////////////////////////////////////////////////////
'// Include standard Windows files
'///////////////////////////////////////////////////////////////////////////

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "olectl.inc"
#INCLUDE ONCE "ddraw.inc"
#INCLUDE ONCE "mmsystem.inc"

'#ifndef NUMELMS
'   #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
'#endif

'///////////////////////////////////////////////////////////////////////////
'// Include DirectShow include files
'///////////////////////////////////////////////////////////////////////////

#INCLUDE ONCE "strmif.inc"     ' // Generated IDL header file for streams interfaces
#INCLUDE ONCE "uuids.inc"      ' // declaration of type GUIDs and well-known clsids
#INCLUDE ONCE "amvideo.inc"    ' // ActiveMovie video interfaces and definitions
#INCLUDE ONCE "amaudio.inc"    ' // ActiveMovie audio interfaces and definitions
#INCLUDE ONCE "control.inc"    ' // generated from control.odl
#INCLUDE ONCE "evcode.inc"     ' // event code definitions
#INCLUDE ONCE "errors.inc"     ' // HRESULT status and error definitions
#INCLUDE ONCE "edevdefs.inc"   ' // External device control interface defines
#INCLUDE ONCE "audevcod.inc"   ' // audio filter device error event codes
#INCLUDE ONCE "dvdevcod.inc"   ' // DVD error event codes


'///////////////////////////////////////////////////////////////////////////
'// Define OLE Automation constants
'///////////////////////////////////////////////////////////////////////////

%OATRUE = -1
%OAFALSE = 0

'///////////////////////////////////////////////////////////////////////////
'// Define Win64 interfaces if not already defined
'///////////////////////////////////////////////////////////////////////////

'// InterlockedExchangePointer
'#ifndef InterlockedExchangePointer
'#define InterlockedExchangePointer(Target, Value) \
'   (PVOID)InterlockedExchange((PLONG)(Target), (LONG)(Value))
'#endif

' ========================================================================================
' Interfaces for Building Filter Graphs
' ========================================================================================

'IAMFilterGraphCallback                (strmif.inc)
'IAMGraphBuilderCallback               (strmif.inc)
'ICaptureGraphBuilder2                 (strmif.inc)
'ICreateDevEnum                        (strmif.inc)
'IDvdGraphBuilder                      (strmif.inc)
'IEnumFilters                          (strmif.inc)
'IFilterGraph2                         (strmif.inc)
'IFilterMapper2                        (strmif.inc)
'IGraphBuilder                         (strmif.inc)
'IGraphConfig                          (strmif.inc)
'IGraphVersion                         (strmif.inc)

' ========================================================================================
' Interfaces for Controlling a Filter Graph
' ========================================================================================

'IAMClockAdjust                        (strmif.inc)
'IAMGraphStreams                       (strmif.inc)
'IFilterChain                          (strmif.inc)
'IMediaControl                         (control.inc)
'IMediaEventEx                         (control.inc)
'IMediaSeeking                         (strmif.inc)
'IQueueCommand                         (control.inc)
'IVideoFrameStep                       (strmif.inc)

' ========================================================================================
' Audio Capture and Rendering Interfaces
' ========================================================================================

'IAMAudioInputMixer                    (strmif.inc)
'IAMAudioRendererStats                 (strmif.inc)
'IAMBufferNegotiation                  (strmif.inc)
'IAMClockSlave                         (strmif.inc)
'IAMDirectSound                        (amaudio.inc)
'IAMResourceControl                    (strmif.inc)
'IAMStreamConfig                       (strmif.inc)
'IBasicAudio                           (control.inc)

' ========================================================================================
' DVD Interfaces
' ========================================================================================

'IAMDecoderCaps                        (strmif.inc)
'IDvdCmd                               (strmif.inc)
'IDvdControl2                          (strmif.inc)
'IDvdGraphBuilder                      (strmif.inc)
'IDvdInfo2                             (strmif.inc)
'IDvdState                             (strmif.inc)

' ========================================================================================
' Video Capture Interfaces
' ========================================================================================

'IAMAnalogVideoDecoder                 (strmif.inc)
'IAMBufferNegotiation                  (strmif.inc)
'IAMCopyCaptureFileProgress            (strmif.inc)
'IAMCrossbar                           (strmif.inc)
'IAMDroppedFrames                      (strmif.inc)
'IAMStreamControl                      (strmif.inc)
'IAMStreamConfig                       (strmif.inc)
'IAMVfwCaptureDialogs                  (strmif.inc)
'IAMVideoControl                       (strmif.inc)
'IAMVideoProcAmp                       (strmif.inc)
'ICaptureGraphBuilder2                 (strmif.inc)
'IFileSinkFilter2                      (strmif.inc)

' ========================================================================================
' File Encoding and Decoding Interfaces
' ========================================================================================

'*IAMMediaContent
'IAMOpenProgress                       (strmif.inc)
'*IAMParse                             (amparse.inc)
'IAMStreamSelect                       (strmif.inc)
'IAMVfwCompressDialogs                 (strmif.inc)
'IAMVideoCompression                   (strmif.inc)
'*IConfigAsfWriter                     (dshowasf.inc)
'IConfigAviMux                         (strmif.inc)
'IConfigInterleaving                   (strmif.inc)
'IDVEnc                                (strmif.inc)
'IDVSplitter                           (strmif.inc)
'IIPDVDec                              (strmif.inc)
'*IPersistMediaPropertyBag             (strmif.inc)

' ========================================================================================
' Interfaces for Video Rendering and Overlay
' ========================================================================================

'IAMLine21Decoder                      (IL21Dec.inc)
'IAMOverlayFX                          (strmif.inc)
'IAMVideoDecimationProperties          (strmif.inc)
'IBasicVideo2                          (control.inc)
'IDDrawExclModeVideo                   (strmif.inc)
'IDDrawExclModeVideoCallback           (strmif.inc)
'IDirectDrawVideo                      (amivideo.inc)
'IDirectDrawMediaSample                (amstream.inc)
'IMixerOCX                             (mixerocx.inc)
'IMixerOCXNotify                       (mixerocx.inc)
'IMixerPinConfig2                      (MPConfig.inc)
'IQualProp                             (amivideo.inc)
'IVideoWindow                          (control.inc)

'Video Mixing Renderer 9 interfaces (wmr9.h)
'-----------------------------------
'IVMRAspectRatioControl9               (vmr9.inc)
'IVMRDeinterlaceControl9               (vmr9.inc)
'IVMRFilterConfig9                     (vmr9.inc)
'IVMRImageCompositor9                  (vmr9.inc)
'IVMRImagePresenter9                   (vmr9.inc)
'IVMRImagePresenterConfig9             (vmr9.inc)
'IVMRMixerBitmap9                      (vmr9.inc)
'IVMRMixerControl9                     (vmr9.inc)
'IVMRMonitorConfig9                    (vmr9.inc)
'IVMRSurface9                          (vmr9.inc)
'IVMRSurfaceAllocator9                 (vmr9.inc)
'IVMRSurfaceAllocatorEx9               (vmr9.inc)
'IVMRSurfaceAllocatorNotify9           (vmr9.inc)
'IVMRWindowlessControl9                (vmr9.inc)

'Video Mixing Renderer 7 interfaces.
'-----------------------------------
'IVMRAspectRatioControl                (strmif.inc)
'IVMRDeinterlaceControl                (strmif.inc)
'IVMRFilterConfig                      (strmif.inc)
'IVMRImageCompositor                   (strmif.inc)
'IVMRImagePresenter                    (strmif.inc)
'IVMRImagePresenterConfig              (strmif.inc)
'IVMRMixerBitmap                       (strmif.inc)
'IVMRMixerControl                      (strmif.inc)
'IVMRSurfaceAllocator                  (strmif.inc)
'IVMRSurfaceAllocatorNotify            (strmif.inc)
'IVMRWindowlessControl                 (strmif.inc)

' ========================================================================================
' Analog TV Tuning Interfaces
' ========================================================================================

'IAMTVTuner                            (strmif.inc)
'IAMTVAudio                            (strmif.inc)
'IAMAnalogVideoDecoder                 (strmif.inc)
'IAMLine21Decoder                      (IL21Dec.inc)
'IAMWstDecoder                         (iwstdec.inc)

' ========================================================================================
' External Device Control Interfaces
' ========================================================================================

'IAMCameraControl                      (strmif.inc)
'IAMExtDevice                          (strmif.inc)
'IAMExtTransport                       (strmif.inc)
'IAMTimecodeDisplay                    (strmif.inc)
'IAMTimecodeGenerator                  (strmif.inc)
'IAMTimecodeReader                     (strmif.inc)

' ========================================================================================
' Alphabetical List of DirectShow Interfaces
' The following is an alphabetical list of the core DirectShow interfaces.
' ========================================================================================

'IAMAnalogVideoDecoder                 (strimf.inc)
'IAMAudioInputMixer                    (strimf.inc)
'IAMAudioRendererStats                 (strimf.inc)
'IAMBufferNegotiation                  (strimf.inc)
'IAMCameraControl                      (strimf.inc)
'IAMCertifiedOutputProtection          (strimf.inc)
'IAMChannelInfo                        (qnetwork.inc)
'IAMClockAdjust                        (strimf.inc)
'IAMClockSlave                         (strimf.inc)
'IAMCopyCaptureFileProgress            (strimf.inc)
'IAMCrossbar                           (strimf.inc)
'IAMDecoderCaps                        (strimf.inc)
'IAMDirectSound                        (amaudio.inc)
'IAMDroppedFrames                      (strimf.inc)
'IAMExtDevice                          (strimf.inc)
'IAMExtTransport                       (strimf.inc)
'IAMExtendedErrorInfo                  (qnetwork.inc)
'IAMExtendedSeeking                    (qnetwork.inc)
'IAMFilterGraphCallback                (strimf.inc)
'IAMFilterMiscFlags                    (strimf.inc)
'IAMGraphBuilderCallback               (strimf.inc)
'IAMGraphStreams                       (strimf.inc)
'IAMLatency                            (strimf.inc)
'IAMLine21Decoder                      (IL21Dec.inc)
'IAMMediaContent                       (qnetwork.inc)
'IAMMediaContent2                      (qnetwork.inc)
'IAMNetShowConfig                      (qnetwork.inc)
'IAMNetShowExProps                     (qnetwork.inc)
'IAMNetShowPreroll                     (qnetwork.inc)
'IAMNetworkStatus                      (qnetwork.inc)
'IAMOpenProgress                       (strimf.inc)
'IAMOverlayFX                          (strimf.inc)
'IAMParse                              (amparse.inc)
'IAMPushSource                         (strimf.inc)
'IAMResourceControl                    (strimf.inc)
'IAMStats                              (control.inc)
'IAMStreamConfig                       (strimf.inc)
'IAMStreamControl                      (strimf.inc)
'IAMStreamSelect                       (strimf.inc)
'IAMTimecodeDisplay                    (strimf.inc)
'IAMTimecodeGenerator                  (strimf.inc)
'IAMTimecodeReader                     (strimf.inc)
'IAMTuner                              (strimf.inc)
'IAMTVAudio                            (strimf.inc)
'IAMTVTuner                            (strimf.inc)
'IAMVfwCaptureDialogs                  (strimf.inc)
'IAMVfwCompressDialogs                 (strimf.inc)
'IAMVideoAccelerator                   (videoacc.inc)
'IAMVideoAcceleratorNotify             (videoacc.inc)
'IAMVideoCompression                   (strimf.inc)
'IAMVideoControl                       (strimf.inc)
'IAMVideoDecimationProperties          (strimf.inc)
'IAMVideoProcAmp                       (strimf.inc)
'IAMWstDecoder                         (iwstdec.inc)
'IAsyncReader                          (strimf.inc)
'IBaseFilter                           (strimf.inc)
'IBasicAudio                           (control.inc)
'IBasicVideo                           (control.inc)
'IBasicVideo2                          (control.inc)
'ICaptureGraphBuilder2                 (strimf.inc)
'ICodecAPI                             (strimf.inc)
'IConfigAsfWriter                      ((dshowasf.inc))
'IConfigAviMux                         (strimf.inc)
'IConfigInterleaving                   (strimf.inc)
'ICreateDevEnum                        (strimf.inc)
'IDDrawExclModeVideo                   (strimf.inc)
'IDDrawExclModeVideoCallback           (strimf.inc)
'IDecimateVideoImage                   (strimf.inc)
'IDeferredCommand                      (control.inc)
'IDirectDrawVideo                      (amvideo.inc)
'IDirectDrawMediaSample                (amstream.inc)
'IDirectDrawMediaSampleAllocator       (amstream.inc)
'IDistributorNotify                    (strimf.inc)
'IDMOWrapperFilter                     (dmodshow.inc)
'IDShowPlugin                          (qnetwork.inc)
'IDvdCmd                               (strimf.inc)
'IDvdControl2                          (strimf.inc)
'IDvdGraphBuilder                      (strimf.inc)
'IDvdInfo2                             (strimf.inc)
'IDvdState                             (strimf.inc)
'IDVEnc                                (strimf.inc)
'IDVRGB219                             (strimf.inc)
'IDVSplitter                           (strimf.inc)
'IEncoderAPI                           (strimf.inc)
'IEnumFilters                          (strimf.inc)
'IEnumMediaTypes                       (strimf.inc)
'IEnumPIDMap                           (bdaiface.inc)
'IEnumPins                             (strimf.inc)
'IEnumStreamIdMap                      (strimf.inc)
'IFileSinkFilter                       (strimf.inc)
'IFileSinkFilter2                      (strimf.inc)
'IFileSourceFilter                     (strimf.inc)
'IFilterChain                          (strimf.inc)
'IFilterGraph                          (strimf.inc)
'IFilterGraph2                         (strimf.inc)
'IFilterMapper2                        (strimf.inc)
'IFullScreenVideoEx                    (amvideo.inc)
'IGetCapabilitiesKey                   (strimf.inc)
'IGraphBuilder                         (strimf.inc)
'IGraphConfig                          (strimf.inc)
'IGraphConfigCallback                  (strimf.inc)
'IGraphVersion                         (strimf.inc)
'IIPDVDec                              (strimf.inc)
'IKsPin
'IKsPropertySet                        (strimf.inc)
'IKsTopologyInfo                       (vidcap.inc)
'IMediaControl                         (control.inc)
'IMediaEvent                           (control.inc)
'IMediaEventEx                         (control.inc)
'IMediaEventSink                       (strimf.inc)
'IMediaFilter                          (strimf.inc)
'IMediaPosition                        (control.inc)
'IMediaPropertyBag                     (strimf.inc)
'IMediaSample                          (strimf.inc)
'IMediaSample2                         (strimf.inc)
'IMediaSeeking                         (strimf.inc)
'IMemAllocator                         (strimf.inc)
'IMemAllocatorCallbackTemp             (strimf.inc)
'IMemAllocatorNotifyCallbackTemp       (strimf.inc)
'IMemInputPin                          (strimf.inc)
'IMixerOCX                             (mixerocx.inc)
'IMixerOCXNotify                       (mixerocx.inc)
'IMixerPinConfig                       (mpconfig.inc)
'IMixerPinConfig2                      (mpconfig.inc)
'IMpeg2Demultiplexer                   (strimf.inc)
'IMPEG2PIDMap                          (bdaiface.inc)
'IMPEG2StreamIdMap                     (strimf.inc)
'IMpegAudioDecoder                     (mpegtype.inc)
'IOverlay                              (strimf.inc)
'IOverlayNotify                        (strimf.inc)
'IOverlayNotify2                       (strimf.inc)
'IPersistMediaPropertyBag              (strmif.inc)
'IPin                                  (strimf.inc)
'IPinConnection                        (strimf.inc)
'IPinFlowControl                       (strimf.inc)
'IQualityControl                       (strimf.inc)
'IQualProp                             (amvideo.inc)
'IQueueCommand                         (control.inc)
'IReferenceClock                       (strimf.inc)
'IRegisterServiceProvider              (strimf.inc)
'IResourceConsumer                     (strimf.inc)
'IResourceManager                      (strimf.inc)
'ISampleGrabber                        (qedit.inc)
'ISampleGrabberCB                      (qedit.inc)
'ISeekingPassThru                      (strimf.inc)
'ISelector                             (vidcap.inc)
'IStreamBuilder                        (strimf.inc)
'IVideoFrameStep                       (strimf.inc)
'IVideoWindow                          (control.inc)
'IVMRAspectRatioControl                (strimf.inc)
'IVMRAspectRatioControl9               (vmr9.inc)
'IVMRDeinterlaceControl                (strimf.inc)
'IVMRDeinterlaceControl9               (vmr9.inc)
'IVMRFilterConfig                      (strimf.inc)
'IVMRFilterConfig9                     (vmr9.inc)
'IVMRImageCompositor                   (strimf.inc)
'IVMRImageCompositor9                  (vmr9.inc)
'IVMRImagePresenter                    (strimf.inc)
'IVMRImagePresenter9                   (vmr9.inc)
'IVMRImagePresenterConfig              (strimf.inc)
'IVMRImagePresenterConfig9             (vmr9.inc)
'IVMRImagePresenterExclModeConfig      (strimf.inc)
'IVMRMixerBitmap                       (strimf.inc)
'IVMRMixerBitmap9                      (vmr9.inc)
'IVMRMixerControl                      (strimf.inc)
'IVMRMixerControl9                     (vmr9.inc)
'IVMRMonitorConfig                     (strimf.inc)
'IVMRMonitorConfig9                    (vmr9.inc)
'IVMRSurface                           (strimf.inc)
'IVMRSurface9                          (vmr9.inc)
'IVMRSurfaceAllocator                  (strimf.inc)
'IVMRSurfaceAllocator9                 (vmr9.inc)
'IVMRSurfaceAllocatorEx9               (vmr9.inc)
'IVMRSurfaceAllocatorNotify            (strimf.inc)
'IVMRSurfaceAllocatorNotify9           (vmr9.inc)
'IVMRVideoStreamControl                (strimf.inc)
'IVMRVideoStreamControl9               (vmr9.inc)
'IVMRWindowlessControl                 (strimf.inc)
'IVMRWindowlessControl9                (vmr9.inc)
'IVPBaseConfig [Windows CE]
'IVPBaseNotify [Windows CE]
'IVPConfig [Windows CE]
'IVPManager                            (strimf.inc)
'IVPNotify [Windows CE]
'IVPNotify2 [Windows CE]

' ========================================================================================
' Deprecated Interfaces
' The following interfaces have been deprecated. They will continue to be supported for
' backward compatibility with existing applications, but new applications should not use
' them.
' ========================================================================================

'IAMAnalogVideoEncoder                 (strimf.inc)
'IAMDevMemoryAllocator                 (strimf.inc)
'IAMDevMemoryControl                   (strimf.inc)
'IAMFilterData [deprecated]
'IAMovieSetup                          (strimf.inc)
'IAMPhysicalPinInfo                    (strimf.inc)
'IAMTunerNotification                  (strimf.inc)
'IAMTVAudioNotification                (strimf.inc)
'ICaptureGraphBuilder                  (strimf.inc)
'IDirectDraw3
'IDirectDrawFactory
'IDrawVideoImage                       (strimf.inc)
'IDvdControl                           (strimf.inc)
'IDvdInfo                              (strimf.inc)
'IEnumRegFilters                       (strimf.inc)
'IFilterMapper                         (strimf.inc)
'IFullScreenVideo -- See IFullScreenVideoEx (amvideo.inc)
