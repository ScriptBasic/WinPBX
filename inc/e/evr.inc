' ########################################################################################
' Microsoft Windows
' File: evr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EVR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "mfidl.inc"
#INCLUDE ONCE "mftransform.inc"
#INCLUDE ONCE "strmif.inc"

$MR_VIDEO_RENDER_SERVICE       = GUID$("{1092A86C-AB1A-459A-A336-831FBC4D11FF}")
$MR_VIDEO_MIXER_SERVICE        = GUID$("{073CD2FC-6CF4-40B7-8859-E89552C841F8}")
$MR_VIDEO_ACCELERATION_SERVICE = GUID$("{EFEF5175-5C7D-4CE2-BBBD-34FF8BCA6554}")
$MR_BUFFER_SERVICE             = GUID$("{A562248C-9AC6-4FFC-9FBA-3AF8F8AD1A4D}")
$VIDEO_ZOOM_RECT               = GUID$("{7AAA1638-1B7F-4C93-BD89-5B9C9FB6FCF0}")

' ########################################################################################
' Interface name = IMFVideoPositionMapper
' IID = 1F6A9F17-E70B-4E24-8AE4-0B2C3BA7A4AE
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IMFVideoPositionMapper_INTERFACE_DEFINED)
    %IMFVideoPositionMapper_INTERFACE_DEFINED = 1

$IID_IMFVideoPositionMapper = GUID$("{1F6A9F17-E70B-4E24-8AE4-0B2C3BA7A4AE}")

INTERFACE IMFVideoPositionMapper $IID_IMFVideoPositionMapper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MapOutputCoordinateToInputStream ( _          ' VTable offset = 12
     BYVAL xOut AS SINGLE _                             ' __in float xOut
   , BYVAL yOut AS SINGLE _                             ' __in float yOut
   , BYVAL dwOutputStreamIndex AS DWORD _               ' __in DWORD dwOutputStreamIndex
   , BYVAL dwInputStreamIndex AS DWORD _                ' __in DWORD dwInputStreamIndex
   , BYREF pxIn AS SINGLE _                             ' __out float *pxIn
   , BYREF pyIn AS SINGLE _                             ' __out float *pyIn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoPositionMapper_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFVideoDeviceID
' IID = A38D9567-5A9C-4F3C-B293-8EB415B279BA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoDeviceID_INTERFACE_DEFINED)
    %IMFVideoDeviceID_INTERFACE_DEFINED = 1

$IID_IMFVideoDeviceID = GUID$("{A38D9567-5A9C-4F3C-B293-8EB415B279BA}")

INTERFACE IMFVideoDeviceID $IID_IMFVideoDeviceID

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDeviceID ( _                               ' VTable offset = 12
     BYREF pDeviceID AS GUID _                          ' __out IID *pDeviceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoDeviceID_INTERFACE_DEFINED__ */


' enum MFVideoAspectRatioMode
%MFVideoARMode_None             = 0
%MFVideoARMode_PreservePicture  = &H1
%MFVideoARMode_PreservePixel    = &H2
%MFVideoARMode_NonLinearStretch = &H4
%MFVideoARMode_Mask             = &H7

' enum MFVideoRenderPrefs
%MFVideoRenderPrefs_DoNotRenderBorder     = &H1
%MFVideoRenderPrefs_DoNotClipToDevice     = &H2
%MFVideoRenderPrefs_AllowOutputThrottling = &H4
%MFVideoRenderPrefs_ForceOutputThrottling = &H8
%MFVideoRenderPrefs_ForceBatching         = &H10
%MFVideoRenderPrefs_AllowBatching         = &H20
%MFVideoRenderPrefs_ForceScaling          = &H40
%MFVideoRenderPrefs_AllowScaling          = &H80
%MFVideoRenderPrefs_DoNotRepaintOnStop    = &H100
%MFVideoRenderPrefs_Mask                  = &H1ff

' // Size = 16 bytes
TYPE MFVideoNormalizedRect DWORD
   left   AS SINGLE   ' float
   top    AS SINGLE   ' float
   right  AS SINGLE   ' float
   bottom AS SINGLE   ' float
END TYPE


' ########################################################################################
' Interface name = IMFVideoDisplayControl
' IID = A490B1E4-AB84-4D31-A1B2-181E03B1077A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoDisplayControl_INTERFACE_DEFINED)
    %IMFVideoDisplayControl_INTERFACE_DEFINED = 1

$IID_IMFVideoDisplayControl = GUID$("{A490B1E4-AB84-4D31-A1B2-181E03B1077A}")

INTERFACE IMFVideoDisplayControl $IID_IMFVideoDisplayControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNativeVideoSize ( _                        ' VTable offset = 12
     BYREF pszVideo AS SIZE _                           ' __inout SIZE *pszVideo
   , BYREF pszARVideo AS SIZE _                         ' __inout SIZE *pszARVideo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIdealVideoSize ( _                         ' VTable offset = 16
     BYREF pszMin AS SIZE _                             ' __inout SIZE *pszMin
   , BYREF pszMax AS SIZE _                             ' __inout SIZE *pszMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoPosition ( _                          ' VTable offset = 20
     BYREF MFVideoNormalizedRect AS MFVideoNormalizedRect _ ' __in const MFVideoNormalizedRect *pnrcSource
   , BYREF prcDest AS RECT _                            ' __in const LPRECT prcDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPosition ( _                          ' VTable offset = 24
     BYREF pnrcSource AS MFVideoNormalizedRect _        ' __out MFVideoNormalizedRect *pnrcSource
   , BYREF prcDest AS RECT _                            ' __out LPRECT prcDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 28
     BYVAL dwAspectRatioMode AS DWORD _                 ' __in DWORD dwAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 32
     BYREF pdwAspectRatioMode AS DWORD _                ' __out DWORD *pdwAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoWindow ( _                            ' VTable offset = 36
     BYVAL hwndVideo AS DWORD _                         ' __in HWND hwndVideo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoWindow ( _                            ' VTable offset = 40
     BYREF phwndVideo AS DWORD _                        ' __out HWND *phwndVideo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RepaintVideo ( _                              ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentImage ( _                           ' VTable offset = 48
     BYREF pBih AS BITMAPINFOHEADER _                   ' __inout BITMAPINFOHEADER *pBih
   , BYREF pDib AS DWORD _                              ' __out BYTE **pDib
   , BYREF pcbDib AS DWORD _                            ' __out DWORD *pcbDib
   , BYREF pTimeStamp AS QUAD _                         ' __inout LONGLONG *pTimeStamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderColor ( _                            ' VTable offset = 52
     BYVAL Clr AS DWORD _                               ' __in COLORREF Clr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBorderColor ( _                            ' VTable offset = 56
     BYREF pClr AS DWORD _                              ' __out COLORREF *pClr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 60
     BYVAL dwRenderFlags AS DWORD _                     ' __in DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 64
     BYREF pdwRenderFlags AS DWORD _                    ' __out DWORD *pdwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFullscreen ( _                             ' VTable offset = 68
     BYVAL fFullscreen AS LONG _                        ' __in BOOL fFullscreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFullscreen ( _                             ' VTable offset = 72
     BYREF pfFullscreen AS LONG _                       ' __out BOOL *pfFullscreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoDisplayControl_INTERFACE_DEFINED__ */


' enum MFVP_MESSAGE_TYPE
%MFVP_MESSAGE_FLUSH               = 0
%MFVP_MESSAGE_INVALIDATEMEDIATYPE = &H1
%MFVP_MESSAGE_PROCESSINPUTNOTIFY  = &H2
%MFVP_MESSAGE_BEGINSTREAMING      = &H3
%MFVP_MESSAGE_ENDSTREAMING        = &H4
%MFVP_MESSAGE_ENDOFSTREAM         = &H5
%MFVP_MESSAGE_STEP                = &H6
%MFVP_MESSAGE_CANCELSTEP          = &H7


' ########################################################################################
' Interface name = IMFVideoPresenter
' IID = 29AFF080-182A-4A5D-AF3B-448F3A6346CB
' Inherited interface = IMFClockStateSink
' ########################################################################################

#IF NOT %DEF(%IMFVideoPresenter_INTERFACE_DEFINED)
    %IMFVideoPresenter_INTERFACE_DEFINED = 1

$IID_IMFVideoPresenter = GUID$("{29AFF080-182A-4A5D-AF3B-448F3A6346CB}")

INTERFACE IMFVideoPresenter $IID_IMFVideoPresenter

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFClockStateSink methods
   ' =====================================================================================
   METHOD OnClockStart ( _                              ' VTable offset = 12
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL llClockStartOffset AS QUAD _                 ' __in LONGLONG llClockStartOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockStop ( _                               ' VTable offset = 16
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockPause ( _                              ' VTable offset = 20
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockRestart ( _                            ' VTable offset = 24
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockSetRate ( _                            ' VTable offset = 28
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFVideoPresenter methods
   ' =====================================================================================
   METHOD ProcessMessage ( _                            ' VTable offset = 32
     BYVAL eMessage AS LONG _                           ' MFVP_MESSAGE_TYPE eMessage
   , BYVAL ulParam AS DWORD _                           ' ULONG_PTR ulParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentMediaType ( _                       ' VTable offset = 36
     BYREF ppMediaType AS IMFVideoMediaType _           ' __out IMFVideoMediaType **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoPresenter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFDesiredSample
' IID = 56C294D0-753E-4260-8D61-A3D8820B1D54
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFDesiredSample_INTERFACE_DEFINED)
    %IMFDesiredSample_INTERFACE_DEFINED = 1

$IID_IMFDesiredSample = GUID$("{56C294D0-753E-4260-8D61-A3D8820B1D54}")

INTERFACE IMFDesiredSample $IID_IMFDesiredSample

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDesiredSampleTimeAndDuration ( _           ' VTable offset = 12
     BYREF phnsSampleTime AS QUAD _                     ' __out LONGLONG *phnsSampleTime
   , BYREF phnsSampleDuration AS QUAD _                 ' __out LONGLONG *phnsSampleDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDesiredSampleTimeAndDuration ( _           ' VTable offset = 16
     BYVAL hnsSampleTime AS QUAD _                      ' __in LONGLONG hnsSampleTime
   , BYVAL hnsSampleDuration AS QUAD _                  ' __in LONGLONG hnsSampleDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFDesiredSample_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFTrackedSample
' IID = 245BF8E9-0755-40F7-88A5-AE0F18D55E17
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTrackedSample_INTERFACE_DEFINED)
    %IMFTrackedSample_INTERFACE_DEFINED = 1

$IID_IMFTrackedSample = GUID$("{245BF8E9-0755-40F7-88A5-AE0F18D55E17}")

INTERFACE IMFTrackedSample $IID_IMFTrackedSample

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllocator ( _                              ' VTable offset = 12
     BYVAL pSampleAllocator AS IMFAsyncCallback _       ' __in IMFAsyncCallback *pSampleAllocator
   , BYVAL pUnkState AS IUnknown _                      ' __in IUnknown *pUnkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTrackedSample_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFVideoMixerControl
' IID = A5C6C53F-C202-4AA5-9695-175BA8C508A5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoMixerControl_INTERFACE_DEFINED)
    %IMFVideoMixerControl_INTERFACE_DEFINED = 1

$IID_IMFVideoMixerControl = GUID$("{A5C6C53F-C202-4AA5-9695-175BA8C508A5}")

INTERFACE IMFVideoMixerControl $IID_IMFVideoMixerControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetStreamZOrder ( _                           ' VTable offset = 12
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL dwZ AS DWORD _                               ' __in DWORD dwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamZOrder ( _                           ' VTable offset = 16
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pdwZ AS DWORD _                              ' __out DWORD *pdwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamOutputRect ( _                       ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF MFVideoNormalizedRect AS MFVideoNormalizedRect _ ' __in const MFVideoNormalizedRect *pnrcOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamOutputRect ( _                       ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pnrcOutput AS MFVideoNormalizedRect _        ' __out MFVideoNormalizedRect *pnrcOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoMixerControl_INTERFACE_DEFINED__ */

' enum MFVideoMixPrefs
%MFVideoMixPrefs_ForceHalfInterlace       = &H1
%MFVideoMixPrefs_AllowDropToHalfInterlace = &H2
%MFVideoMixPrefs_AllowDropToBob           = &H4
%MFVideoMixPrefs_ForceBob                 = &H8
%MFVideoMixPrefs_Mask                     = &Hf

' ########################################################################################
' Interface name = IMFVideoMixerControl2
' IID = 8459616D-966E-4930-B658-54FA7E5A16D3
' Inherited interface = IMFVideoMixerControl
' ########################################################################################

#IF NOT %DEF(%IMFVideoMixerControl2_INTERFACE_DEFINED)
    %IMFVideoMixerControl2_INTERFACE_DEFINED = 1

$IID_IMFVideoMixerControl2 = GUID$("{8459616D-966E-4930-B658-54FA7E5A16D3}")

INTERFACE IMFVideoMixerControl2 $IID_IMFVideoMixerControl2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFVideoMixerControl Methods
   ' =====================================================================================
   METHOD SetStreamZOrder ( _                           ' VTable offset = 12
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYVAL dwZ AS DWORD _                               ' __in DWORD dwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamZOrder ( _                           ' VTable offset = 16
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pdwZ AS DWORD _                              ' __out DWORD *pdwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamOutputRect ( _                       ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF MFVideoNormalizedRect AS MFVideoNormalizedRect _ ' __in const MFVideoNormalizedRect *pnrcOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamOutputRect ( _                       ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF pnrcOutput AS MFVideoNormalizedRect _        ' __out MFVideoNormalizedRect *pnrcOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFVideoMixerControl2 Methods
   ' =====================================================================================
   METHOD SetMixingPrefs ( _                            ' VTable offset = 28
     BYVAL dwMixFlags AS DWORD _                        ' __in DWORD dwMixFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMixingPrefs ( _                            ' VTable offset = 32
     BYREF pdwMixFlags AS DWORD _                       ' __out DWORD *pdwMixFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoMixerControl2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFVideoRenderer
' IID = DFDFD197-A9CA-43D8-B341-6AF3503792CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoRenderer_INTERFACE_DEFINED)
    %IMFVideoRenderer_INTERFACE_DEFINED = 1

$IID_IMFVideoRenderer = GUID$("{DFDFD197-A9CA-43D8-B341-6AF3503792CD}")

INTERFACE IMFVideoRenderer $IID_IMFVideoRenderer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeRenderer ( _                        ' VTable offset = 12
     BYVAL pVideoMixer AS IMFTransform _                ' __in IMFTransform *pVideoMixer
   , BYVAL pVideoPresenter AS IMFVideoPresenter _       ' __in IMFVideoPresenter *pVideoPresenter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoRenderer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEVRFilterConfig
' IID = 83E91E85-82C1-4EA7-801D-85DC50B75086
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEVRFilterConfig_INTERFACE_DEFINED)
    %IEVRFilterConfig_INTERFACE_DEFINED = 1

$IID_IEVRFilterConfig = GUID$("{83E91E85-82C1-4EA7-801D-85DC50B75086}")

INTERFACE IEVRFilterConfig $IID_IEVRFilterConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNumberOfStreams ( _                        ' VTable offset = 12
     BYVAL dwMaxStreams AS DWORD _                      ' __in DWORD dwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfStreams ( _                        ' VTable offset = 16
     BYREF pdwMaxStreams AS DWORD _                     ' __out DWORD *pdwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEVRFilterConfig_INTERFACE_DEFINED__ */

' enum EVRFilterConfig_Prefs
%EVRFilterConfigPrefs_EnableQoS = &H1
%EVRFilterConfigPrefs_Mask      = &H1

' ########################################################################################
' Interface name = IEVRFilterConfigEx
' IID = AEA36028-796D-454F-BEEE-B48071E24304
' Inherited interface = IEVRFilterConfig
' ########################################################################################

#IF NOT %DEF(%IEVRFilterConfigEx_INTERFACE_DEFINED)
    %IEVRFilterConfigEx_INTERFACE_DEFINED = 1

$IID_IEVRFilterConfigEx = GUID$("{AEA36028-796D-454F-BEEE-B48071E24304}")

INTERFACE IEVRFilterConfigEx $IID_IEVRFilterConfigEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IEVRFilterConfig Methods
   ' =====================================================================================
   METHOD SetNumberOfStreams ( _                        ' VTable offset = 12
     BYVAL dwMaxStreams AS DWORD _                      ' __in DWORD dwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfStreams ( _                        ' VTable offset = 16
     BYREF pdwMaxStreams AS DWORD _                     ' __out DWORD *pdwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IEVRFilterConfigEx Methods
   ' =====================================================================================
   METHOD SetConfigPrefs ( _                            ' VTable offset = 20
     BYVAL dwConfigFlags AS DWORD _                     ' __in DWORD dwConfigFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConfigPrefs ( _                            ' VTable offset = 24
     BYREF pdwConfigFlags AS DWORD _                    ' __out DWORD *pdwConfigFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEVRFilterConfigEx_INTERFACE_DEFINED__ */


' enum _MF_SERVICE_LOOKUP_TYPE
%MF_SERVICE_LOOKUP_UPSTREAM          = 0
%MF_SERVICE_LOOKUP_UPSTREAM_DIRECT   = %MF_SERVICE_LOOKUP_UPSTREAM          + 1
%MF_SERVICE_LOOKUP_DOWNSTREAM        = %MF_SERVICE_LOOKUP_UPSTREAM_DIRECT   + 1
%MF_SERVICE_LOOKUP_DOWNSTREAM_DIRECT = %MF_SERVICE_LOOKUP_DOWNSTREAM        + 1
%MF_SERVICE_LOOKUP_ALL               = %MF_SERVICE_LOOKUP_DOWNSTREAM_DIRECT + 1
%MF_SERVICE_LOOKUP_GLOBAL            = %MF_SERVICE_LOOKUP_ALL               + 1


' ########################################################################################
' Interface name = IMFTopologyServiceLookup
' IID = FA993889-4383-415A-A930-DD472A8CF6F7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTopologyServiceLookup_INTERFACE_DEFINED)
    %IMFTopologyServiceLookup_INTERFACE_DEFINED = 1

$IID_IMFTopologyServiceLookup = GUID$("{FA993889-4383-415A-A930-DD472A8CF6F7}")

INTERFACE IMFTopologyServiceLookup $IID_IMFTopologyServiceLookup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LookupService ( _                             ' VTable offset = 12
     BYVAL Type AS LONG _                               ' __in MF_SERVICE_LOOKUP_TYPE Type
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObjects AS IUnknown _                     ' __out LPVOID *ppvObjects
   , BYREF pnObjects AS DWORD _                         ' __inout DWORD *pnObjects
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopologyServiceLookup_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFTopologyServiceLookupClient
' IID = FA99388A-4383-415A-A930-DD472A8CF6F7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTopologyServiceLookupClient_INTERFACE_DEFINED)
    %IMFTopologyServiceLookupClient_INTERFACE_DEFINED = 1

$IID_IMFTopologyServiceLookupClient = GUID$("{FA99388A-4383-415A-A930-DD472A8CF6F7}")

INTERFACE IMFTopologyServiceLookupClient $IID_IMFTopologyServiceLookupClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitServicePointers ( _                       ' VTable offset = 12
     BYVAL pLookup AS IMFTopologyServiceLookup _        ' __in IMFTopologyServiceLookup *pLookup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseServicePointers ( _                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopologyServiceLookupClient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEVRTrustedVideoPlugin
' IID = 83A4CE40-7710-494B-A893-A472049AF630
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEVRTrustedVideoPlugin_INTERFACE_DEFINED)
    %IEVRTrustedVideoPlugin_INTERFACE_DEFINED = 1

$IID_IEVRTrustedVideoPlugin = GUID$("{83A4CE40-7710-494B-A893-A472049AF630}")

INTERFACE IEVRTrustedVideoPlugin $IID_IEVRTrustedVideoPlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsInTrustedVideoMode ( _                      ' VTable offset = 12
     BYREF pYes AS LONG _                               ' __out BOOL *pYes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanConstrict ( _                              ' VTable offset = 16
     BYREF pYes AS LONG _                               ' __out BOOL *pYes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConstriction ( _                           ' VTable offset = 20
     BYVAL dwKPix AS DWORD _                            ' __in DWORD dwKPix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisableImageExport ( _                        ' VTable offset = 24
     BYVAL bDisable AS LONG _                           ' __in BOOL bDisable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEVRTrustedVideoPlugin_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateVideoPresenter IMPORT "evr.dll" ALIAS "MFCreateVideoPresenter" ( _
   BYVAL pOwner AS IUnknown _                           ' __in_opt IUnknown * pOwner
 , BYREF riidDevice AS GUID _                           ' __in REFIID riidDevice
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppVideoPresenter AS ANY _                      ' __deref_out_opt void ** ppVideoPresenter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateVideoMixer IMPORT "evr.dll" ALIAS "MFCreateVideoMixer" ( _
   BYVAL pOwner AS IUnknown _                           ' __in_opt IUnknown * pOwner
 , BYREF riidDevice AS GUID _                           ' __in REFIID riidDevice
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppVideoMixer AS ANY _                          ' __deref_out_opt void ** ppVideoMixer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateVideoMixerAndPresenter IMPORT "evr.dll" ALIAS "MFCreateVideoMixerAndPresenter" ( _
   BYVAL pMixerOwner AS IUnknown _                      ' __in_opt IUnknown * pMixerOwner
 , BYVAL pPresenterOwner AS IUnknown _                  ' __in_opt IUnknown * pPresenterOwner
 , BYREF riidMixer AS GUID _                            ' __in REFIID riidMixer
 , BYREF ppvVideoMixer AS ANY _                         ' __deref_out void ** ppvVideoMixer
 , BYREF riidPresenter AS GUID _                        ' __in REFIID riidPresenter
 , BYREF ppvVideoPresenter AS ANY _                     ' __deref_out void ** ppvVideoPresenter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateVideoRenderer IMPORT "mf.dll" ALIAS "MFCreateVideoRenderer" ( _
   BYREF riidRenderer AS GUID _                         ' __in REFIID riidRenderer
 , BYREF ppVideoRenderer AS ANY _                       ' __deref_out_opt void ** ppVideoRenderer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateVideoSampleFromSurface IMPORT "evr.dll" ALIAS "MFCreateVideoSampleFromSurface" ( _
   BYVAL pUnkSurface AS IUnknown _                      ' __in_opt IUnknown* pUnkSurface
 , BYREF ppSample AS IMFSample _                        ' __deref_out_opt IMFSample** ppSample
 ) AS LONG                                              ' HRESULT
