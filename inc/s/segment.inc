' ########################################################################################
' Microsoft Windows
' File: segment.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SEGMENT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "tuner.inc"
#INCLUDE ONCE "tvratings.inc"
#INCLUDE ONCE "evr.inc"

#INCLUDE ONCE "olectl.inc"

' ========================================================================================
' enum SegdispidList
' ========================================================================================

%dispidName                             = 0
%dispidStatus                           = %dispidName                             + 1
%dispidDevImageSourceWidth              = %dispidStatus                           + 1
%dispidDevImageSourceHeight             = %dispidDevImageSourceWidth              + 1
%dispidDevCountryCode                   = %dispidDevImageSourceHeight             + 1
%dispidDevOverScan                      = %dispidDevCountryCode                   + 1
%dispidSegment                          = %dispidDevOverScan                      + 1
%dispidDevVolume                        = %dispidSegment                          + 1
%dispidDevBalance                       = %dispidDevVolume                        + 1
%dispidDevPower                         = %dispidDevBalance                       + 1
%dispidTuneChan                         = %dispidDevPower                         + 1
%dispidDevVideoSubchannel               = %dispidTuneChan                         + 1
%dispidDevAudioSubchannel               = %dispidDevVideoSubchannel               + 1
%dispidChannelAvailable                 = %dispidDevAudioSubchannel               + 1
%dispidDevVideoFrequency                = %dispidChannelAvailable                 + 1
%dispidDevAudioFrequency                = %dispidDevVideoFrequency                + 1
%dispidCount                            = %dispidDevAudioFrequency                + 1
%dispidDevFileName                      = %dispidCount                            + 1
%dispidVisible                          = %dispidDevFileName                      + 1
%dispidOwner                            = %dispidVisible                          + 1
%dispidMessageDrain                     = %dispidOwner                            + 1
%dispidViewable                         = %dispidMessageDrain                     + 1
%dispidDevView                          = %dispidViewable                         + 1
%dispidKSCat                            = %dispidDevView                          + 1
%dispidCLSID                            = %dispidKSCat                            + 1
%dispid_KSCat                           = %dispidCLSID                            + 1
%dispid_CLSID                           = %dispid_KSCat                           + 1
%dispidTune                             = %dispid_CLSID                           + 1
%dispidTS                               = %dispidTune                             + 1
%dispidDevSAP                           = %dispidTS                               + 1
%dispidClip                             = %dispidDevSAP                           + 1
%dispidRequestedClipRect                = %dispidClip                             + 1
%dispidClippedSourceRect                = %dispidRequestedClipRect                + 1
%dispidAvailableSourceRect              = %dispidClippedSourceRect                + 1
%dispidMediaPosition                    = %dispidAvailableSourceRect              + 1
%dispidDevRun                           = %dispidMediaPosition                    + 1
%dispidDevPause                         = %dispidDevRun                           + 1
%dispidDevStop                          = %dispidDevPause                         + 1
%dispidCCEnable                         = %dispidDevStop                          + 1
%dispidDevStep                          = %dispidCCEnable                         + 1
%dispidDevCanStep                       = %dispidDevStep                          + 1
%dispidSourceSize                       = %dispidDevCanStep                       + 1
%dispid_playtitle                       = %dispidSourceSize                       + 1
%dispid_playchapterintitle              = %dispid_playtitle                       + 1
%dispid_playchapter                     = %dispid_playchapterintitle              + 1
%dispid_playchaptersautostop            = %dispid_playchapter                     + 1
%dispid_playattime                      = %dispid_playchaptersautostop            + 1
%dispid_playattimeintitle               = %dispid_playattime                      + 1
%dispid_playperiodintitleautostop       = %dispid_playattimeintitle               + 1
%dispid_replaychapter                   = %dispid_playperiodintitleautostop       + 1
%dispid_playprevchapter                 = %dispid_replaychapter                   + 1
%dispid_playnextchapter                 = %dispid_playprevchapter                 + 1
%dispid_playforwards                    = %dispid_playnextchapter                 + 1
%dispid_playbackwards                   = %dispid_playforwards                    + 1
%dispid_stilloff                        = %dispid_playbackwards                   + 1
%dispid_audiolanguage                   = %dispid_stilloff                        + 1
%dispid_showmenu                        = %dispid_audiolanguage                   + 1
%dispid_resume                          = %dispid_showmenu                        + 1
%dispid_returnfromsubmenu               = %dispid_resume                          + 1
%dispid_buttonsavailable                = %dispid_returnfromsubmenu               + 1
%dispid_currentbutton                   = %dispid_buttonsavailable                + 1
%dispid_SelectAndActivateButton         = %dispid_currentbutton                   + 1
%dispid_ActivateButton                  = %dispid_SelectAndActivateButton         + 1
%dispid_SelectRightButton               = %dispid_ActivateButton                  + 1
%dispid_SelectLeftButton                = %dispid_SelectRightButton               + 1
%dispid_SelectLowerButton               = %dispid_SelectLeftButton                + 1
%dispid_SelectUpperButton               = %dispid_SelectLowerButton               + 1
%dispid_ActivateAtPosition              = %dispid_SelectUpperButton               + 1
%dispid_SelectAtPosition                = %dispid_ActivateAtPosition              + 1
%dispid_ButtonAtPosition                = %dispid_SelectAtPosition                + 1
%dispid_NumberOfChapters                = %dispid_ButtonAtPosition                + 1
%dispid_TotalTitleTime                  = %dispid_NumberOfChapters                + 1
%dispid_TitlesAvailable                 = %dispid_TotalTitleTime                  + 1
%dispid_VolumesAvailable                = %dispid_TitlesAvailable                 + 1
%dispid_CurrentVolume                   = %dispid_VolumesAvailable                + 1
%dispid_CurrentDiscSide                 = %dispid_CurrentVolume                   + 1
%dispid_CurrentDomain                   = %dispid_CurrentDiscSide                 + 1
%dispid_CurrentChapter                  = %dispid_CurrentDomain                   + 1
%dispid_CurrentTitle                    = %dispid_CurrentChapter                  + 1
%dispid_CurrentTime                     = %dispid_CurrentTitle                    + 1
%dispid_FramesPerSecond                 = %dispid_CurrentTime                     + 1
%dispid_DVDTimeCode2bstr                = %dispid_FramesPerSecond                 + 1
%dispid_DVDDirectory                    = %dispid_DVDTimeCode2bstr                + 1
%dispid_IsSubpictureStreamEnabled       = %dispid_DVDDirectory                    + 1
%dispid_IsAudioStreamEnabled            = %dispid_IsSubpictureStreamEnabled       + 1
%dispid_CurrentSubpictureStream         = %dispid_IsAudioStreamEnabled            + 1
%dispid_SubpictureLanguage              = %dispid_CurrentSubpictureStream         + 1
%dispid_CurrentAudioStream              = %dispid_SubpictureLanguage              + 1
%dispid_AudioStreamsAvailable           = %dispid_CurrentAudioStream              + 1
%dispid_AnglesAvailable                 = %dispid_AudioStreamsAvailable           + 1
%dispid_CurrentAngle                    = %dispid_AnglesAvailable                 + 1
%dispid_CCActive                        = %dispid_CurrentAngle                    + 1
%dispid_CurrentCCService                = %dispid_CCActive                        + 1
%dispid_SubpictureStreamsAvailable      = %dispid_CurrentCCService                + 1
%dispid_SubpictureOn                    = %dispid_SubpictureStreamsAvailable      + 1
%dispid_DVDUniqueID                     = %dispid_SubpictureOn                    + 1
%dispid_EnableResetOnStop               = %dispid_DVDUniqueID                     + 1
%dispid_AcceptParentalLevelChange       = %dispid_EnableResetOnStop               + 1
%dispid_NotifyParentalLevelChange       = %dispid_AcceptParentalLevelChange       + 1
%dispid_SelectParentalCountry           = %dispid_NotifyParentalLevelChange       + 1
%dispid_SelectParentalLevel             = %dispid_SelectParentalCountry           + 1
%dispid_TitleParentalLevels             = %dispid_SelectParentalLevel             + 1
%dispid_PlayerParentalCountry           = %dispid_TitleParentalLevels             + 1
%dispid_PlayerParentalLevel             = %dispid_PlayerParentalCountry           + 1
%dispid_Eject                           = %dispid_PlayerParentalLevel             + 1
%dispid_UOPValid                        = %dispid_Eject                           + 1
%dispid_SPRM                            = %dispid_UOPValid                        + 1
%dispid_GPRM                            = %dispid_SPRM                            + 1
%dispid_DVDTextStringType               = %dispid_GPRM                            + 1
%dispid_DVDTextString                   = %dispid_DVDTextStringType               + 1
%dispid_DVDTextNumberOfStrings          = %dispid_DVDTextString                   + 1
%dispid_DVDTextNumberOfLanguages        = %dispid_DVDTextNumberOfStrings          + 1
%dispid_DVDTextLanguageLCID             = %dispid_DVDTextNumberOfLanguages        + 1
%dispid_RegionChange                    = %dispid_DVDTextLanguageLCID             + 1
%dispid_DVDAdm                          = %dispid_RegionChange                    + 1
%dispid_DeleteBookmark                  = %dispid_DVDAdm                          + 1
%dispid_RestoreBookmark                 = %dispid_DeleteBookmark                  + 1
%dispid_SaveBookmark                    = %dispid_RestoreBookmark                 + 1
%dispid_SelectDefaultAudioLanguage      = %dispid_SaveBookmark                    + 1
%dispid_SelectDefaultSubpictureLanguage = %dispid_SelectDefaultAudioLanguage      + 1
%dispid_PreferredSubpictureStream       = %dispid_SelectDefaultSubpictureLanguage + 1
%dispid_DefaultMenuLanguage             = %dispid_PreferredSubpictureStream       + 1
%dispid_DefaultSubpictureLanguage       = %dispid_DefaultMenuLanguage             + 1
%dispid_DefaultAudioLanguage            = %dispid_DefaultSubpictureLanguage       + 1
%dispid_DefaultSubpictureLanguageExt    = %dispid_DefaultAudioLanguage            + 1
%dispid_DefaultAudioLanguageExt         = %dispid_DefaultSubpictureLanguageExt    + 1
%dispid_LanguageFromLCID                = %dispid_DefaultAudioLanguageExt         + 1
%dispid_KaraokeAudioPresentationMode    = %dispid_LanguageFromLCID                + 1
%dispid_KaraokeChannelContent           = %dispid_KaraokeAudioPresentationMode    + 1
%dispid_KaraokeChannelAssignment        = %dispid_KaraokeChannelContent           + 1
%dispid_RestorePreferredSettings        = %dispid_KaraokeChannelAssignment        + 1
%dispid_ButtonRect                      = %dispid_RestorePreferredSettings        + 1
%dispid_DVDScreenInMouseCoordinates     = %dispid_ButtonRect                      + 1
%dispid_CustomCompositorClass           = %dispid_DVDScreenInMouseCoordinates     + 1
%dispidCustomCompositorClass            = %dispid_CustomCompositorClass           + 1
%dispid_CustomCompositor                = %dispidCustomCompositorClass            + 1
%dispidMixerBitmap                      = %dispid_CustomCompositor                + 1
%dispid_MixerBitmap                     = %dispidMixerBitmap                      + 1
%dispidMixerBitmapOpacity               = %dispid_MixerBitmap                     + 1
%dispidMixerBitmapRect                  = %dispidMixerBitmapOpacity               + 1
%dispidSetupMixerBitmap                 = %dispidMixerBitmapRect                  + 1
%dispidUsingOverlay                     = %dispidSetupMixerBitmap                 + 1
%dispidDisplayChange                    = %dispidUsingOverlay                     + 1
%dispidRePaint                          = %dispidDisplayChange                    + 1
%dispid_IsEqualDevice                   = %dispidRePaint                          + 1
%dispidrate                             = %dispid_IsEqualDevice                   + 1
%dispidposition                         = %dispidrate                             + 1
%dispidpositionmode                     = %dispidposition                         + 1
%dispidlength                           = %dispidpositionmode                     + 1
%dispidChangePassword                   = %dispidlength                           + 1
%dispidSaveParentalLevel                = %dispidChangePassword                   + 1
%dispidSaveParentalCountry              = %dispidSaveParentalLevel                + 1
%dispidConfirmPassword                  = %dispidSaveParentalCountry              + 1
%dispidGetParentalLevel                 = %dispidConfirmPassword                  + 1
%dispidGetParentalCountry               = %dispidGetParentalLevel                 + 1
%dispidDefaultAudioLCID                 = %dispidGetParentalCountry               + 1
%dispidDefaultSubpictureLCID            = %dispidDefaultAudioLCID                 + 1
%dispidDefaultMenuLCID                  = %dispidDefaultSubpictureLCID            + 1
%dispidBookmarkOnStop                   = %dispidDefaultMenuLCID                  + 1
%dispidMaxVidRect                       = %dispidBookmarkOnStop                   + 1
%dispidMinVidRect                       = %dispidMaxVidRect                       + 1
%dispidCapture                          = %dispidMinVidRect                       + 1
%dispid_DecimateInput                   = %dispidCapture                          + 1
%dispidAlloctor                         = %dispid_DecimateInput                   + 1
%dispid_Allocator                       = %dispidAlloctor                         + 1
%dispidAllocPresentID                   = %dispid_Allocator                       + 1
%dispidSetAllocator                     = %dispidAllocPresentID                   + 1
%dispid_SetAllocator                    = %dispidSetAllocator                     + 1
%dispidStreamBufferSinkName             = %dispid_SetAllocator                    + 1
%dispidStreamBufferSourceName           = %dispidStreamBufferSinkName             + 1
%dispidStreamBufferContentRecording     = %dispidStreamBufferSourceName           + 1
%dispidStreamBufferReferenceRecording   = %dispidStreamBufferContentRecording     + 1
%dispidstarttime                        = %dispidStreamBufferReferenceRecording   + 1
%dispidstoptime                         = %dispidstarttime                        + 1
%dispidrecordingstopped                 = %dispidstoptime                         + 1
%dispidrecordingstarted                 = %dispidrecordingstopped                 + 1
%dispidNameSetLock                      = %dispidrecordingstarted                 + 1
%dispidrecordingtype                    = %dispidNameSetLock                      + 1
%dispidstart                            = %dispidrecordingtype                    + 1
%dispidRecordingAttribute               = %dispidstart                            + 1
%dispid_RecordingAttribute              = %dispidRecordingAttribute               + 1
%dispidSBEConfigure                     = %dispid_RecordingAttribute              + 1
%dispid_CurrentRatings                  = %dispidSBEConfigure                     + 1
%dispid_MaxRatingsLevel                 = %dispid_CurrentRatings                  + 1
%dispid_audioencoderint                 = %dispid_MaxRatingsLevel                 + 1
%dispid_videoencoderint                 = %dispid_audioencoderint                 + 1
%dispidService                          = %dispid_videoencoderint                 + 1
%dispid_BlockUnrated                    = %dispidService                          + 1
%dispid_UnratedDelay                    = %dispid_BlockUnrated                    + 1
%dispid_SuppressEffects                 = %dispid_UnratedDelay                    + 1
%dispidsbesource                        = %dispid_SuppressEffects                 + 1
%dispidSetSinkFilter                    = %dispidsbesource                        + 1
%dispid_SinkStreams                     = %dispidSetSinkFilter                    + 1
%dispidTVFormats                        = %dispid_SinkStreams                     + 1
%dispidModes                            = %dispidTVFormats                        + 1
%dispidAuxInputs                        = %dispidModes                            + 1
%dispidTeleTextFilter                   = %dispidAuxInputs                        + 1
%dispid_channelchangeint                = %dispidTeleTextFilter                   + 1
%dispidUnlockProfile                    = %dispid_channelchangeint                + 1
%dispid_AddFilter                       = %dispidUnlockProfile                    + 1
%dispidSetMinSeek                       = %dispid_AddFilter                       + 1
%dispidRateEx                           = %dispidSetMinSeek                       + 1
%dispidaudiocounter                     = %dispidRateEx                           + 1
%dispidvideocounter                     = %dispidaudiocounter                     + 1
%dispidcccounter                        = %dispidvideocounter                     + 1
%dispidwstcounter                       = %dispidcccounter                        + 1
%dispid_audiocounter                    = %dispidwstcounter                       + 1
%dispid_videocounter                    = %dispid_audiocounter                    + 1
%dispid_cccounter                       = %dispid_videocounter                    + 1
%dispid_wstcounter                      = %dispid_cccounter                       + 1
%dispidaudioanalysis                    = %dispid_wstcounter                      + 1
%dispidvideoanalysis                    = %dispidaudioanalysis                    + 1
%dispiddataanalysis                     = %dispidvideoanalysis                    + 1
%dispidaudio_analysis                   = %dispiddataanalysis                     + 1
%dispidvideo_analysis                   = %dispidaudio_analysis                   + 1
%dispiddata_analysis                    = %dispidvideo_analysis                   + 1
%dispid_resetFilterList                 = %dispiddata_analysis                    + 1
%dispidDevicePath                       = %dispid_resetFilterList                 + 1
%dispid_SourceFilter                    = %dispidDevicePath                       + 1
%dispid__SourceFilter                   = %dispid_SourceFilter                    + 1
%dispidUserEvent                        = %dispid__SourceFilter                   + 1
%dispid_Bookmark	                      = %dispidUserEvent                        + 1
%LastReservedDevicedispid               = &H3FFF

' ========================================================================================
' enum SegEventidList
' ========================================================================================

%eventidStateChange                   = 0
%eventidOnTuneChanged                 = %eventidStateChange                   + 1
%eventidEndOfMedia                    = %eventidOnTuneChanged                 + 1
%eventidDVDNotify                     = %eventidEndOfMedia                    + 1
%eventidPlayForwards                  = %eventidDVDNotify                     + 1
%eventidPlayBackwards                 = %eventidPlayForwards                  + 1
%eventidShowMenu                      = %eventidPlayBackwards                 + 1
%eventidResume                        = %eventidShowMenu                      + 1
%eventidSelectOrActivateButton        = %eventidResume                        + 1
%eventidStillOff                      = %eventidSelectOrActivateButton        + 1
%eventidPauseOn                       = %eventidStillOff                      + 1
%eventidChangeCurrentAudioStream      = %eventidPauseOn                       + 1
%eventidChangeCurrentSubpictureStream = %eventidChangeCurrentAudioStream      + 1
%eventidChangeCurrentAngle            = %eventidChangeCurrentSubpictureStream + 1
%eventidPlayAtTimeInTitle             = %eventidChangeCurrentAngle            + 1
%eventidPlayAtTime                    = %eventidPlayAtTimeInTitle             + 1
%eventidPlayChapterInTitle            = %eventidPlayAtTime                    + 1
%eventidPlayChapter                   = %eventidPlayChapterInTitle            + 1
%eventidReplayChapter                 = %eventidPlayChapter                   + 1
%eventidPlayNextChapter               = %eventidReplayChapter                 + 1
%eventidStop                          = %eventidPlayNextChapter               + 1
%eventidReturnFromSubmenu             = %eventidStop                          + 1
%eventidPlayTitle                     = %eventidReturnFromSubmenu             + 1
%eventidPlayPrevChapter               = %eventidPlayTitle                     + 1
%eventidChangeKaraokePresMode         = %eventidPlayPrevChapter               + 1
%eventidChangeVideoPresMode           = %eventidChangeKaraokePresMode         + 1
%eventidOverlayUnavailable            = %eventidChangeVideoPresMode           + 1
%eventidSinkCertificateFailure        = %eventidOverlayUnavailable            + 1
%eventidSinkCertificateSuccess        = %eventidSinkCertificateFailure        + 1
%eventidSourceCertificateFailure      = %eventidSinkCertificateSuccess        + 1
%eventidSourceCertificateSuccess      = %eventidSourceCertificateFailure      + 1
%eventidRatingsBlocked                = %eventidSourceCertificateSuccess      + 1
%eventidRatingsUnlocked               = %eventidRatingsBlocked                + 1
%eventidRatingsChanged                = %eventidRatingsUnlocked               + 1
%eventidWriteFailure                  = %eventidRatingsChanged                + 1
%eventidTimeHole                      = %eventidWriteFailure                  + 1
%eventidStaleDataRead                 = %eventidTimeHole                      + 1
%eventidContentBecomingStale          = %eventidStaleDataRead                 + 1
%eventidStaleFileDeleted              = %eventidContentBecomingStale          + 1
%eventidEncryptionOn                  = %eventidStaleFileDeleted              + 1
%eventidEncryptionOff                 = %eventidEncryptionOn                  + 1
%eventidRateChange                    = %eventidEncryptionOff                 + 1
%eventidLicenseChange                 = %eventidRateChange                    + 1
%eventidCOPPBlocked                   = %eventidLicenseChange                 + 1
%eventidCOPPUnblocked                 = %eventidCOPPBlocked                   + 1
%dispidlicenseerrorcode               = %eventidCOPPUnblocked                 + 1
%eventidBroadcastEvent                = %dispidlicenseerrorcode               + 1
%eventidBroadcastEventEx              = %eventidBroadcastEvent                + 1
%eventidContentPrimarilyAudio         = %eventidBroadcastEventEx              + 1
%dispidAVDecAudioDualMonoEvent        = %eventidContentPrimarilyAudio         + 1
%dispidAVAudioSampleRateEvent         = %dispidAVDecAudioDualMonoEvent        + 1
%dispidAVAudioChannelConfigEvent      = %dispidAVAudioSampleRateEvent         + 1
%dispidAVAudioChannelCountEvent       = %dispidAVAudioChannelConfigEvent      + 1
%dispidAVDecCommonMeanBitRateEvent    = %dispidAVAudioChannelCountEvent       + 1
%dispidAVDDSurroundModeEvent          = %dispidAVDecCommonMeanBitRateEvent    + 1
%dispidAVDecCommonInputFormatEvent    = %dispidAVDDSurroundModeEvent          + 1
%dispidAVDecCommonOutputFormatEvent   = %dispidAVDecCommonInputFormatEvent    + 1
%eventidWriteFailureClear             = %dispidAVDecCommonOutputFormatEvent   + 1
%LastReservedDeviceEvent              = &H3FFF

' ========================================================================================
' PositionModeList enum
' ========================================================================================

%PositionModeList_FrameMode         = 0
%PositionModeList_TenthsSecondsMode = %PositionModeList_FrameMode + 1

' ========================================================================================
' RecordingType enum
' ========================================================================================

%RecordingType_CONTENT   = 0
%RecordingType_REFERENCE = 1

' ========================================================================================
' MSVidCCService enum
' ========================================================================================

%MSVidCCService_None     = 0
%MSVidCCService_Caption1 = %MSVidCCService_None + 1
%MSVidCCService_Caption2 = %MSVidCCService_Caption1 + 1
%MSVidCCService_Text1    = %MSVidCCService_Caption2 + 1
%MSVidCCService_Text2    = %MSVidCCService_Text1 + 1
%MSVidCCService_XDS      = %MSVidCCService_Text2 + 1

' ========================================================================================
' MSVidSinkStreams enum
' ========================================================================================

%MSVidSinkStreams_Video = 1
%MSVidSinkStreams_Audio = 2
%MSVidSinkStreams_Other = 4


' ########################################################################################
' Interface name = IMSVidRect
' IID = {7F5000A6-A440-47CA-8ACC-C0E75531A2C2}
' Automation Compliant GDI Rect with Automatic HWND Scaling
' Attributes = 4096 [&H1000] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidRect_INTERFACE_DEFINED)
    %IMSVidRect_INTERFACE_DEFINED = 1

$IID_IMSVidRect = GUID$("{7F5000A6-A440-47CA-8ACC-C0E75531A2C2}")

INTERFACE IMSVidRect $IID_IMSVidRect

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Top <1610743808> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *TopVal
   ' =====================================================================================
   PROPERTY SET Top <1610743808> ( _                    ' VTable offset = 32
     BYVAL TopVal AS LONG _                             ' __in LONG TopVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Left <1610743810> ( _                   ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *LeftVal
   ' =====================================================================================
   PROPERTY SET Left <1610743810> ( _                   ' VTable offset = 40
     BYVAL LeftVal AS LONG _                            ' __in LONG LeftVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Width <1610743812> ( _                  ' VTable offset = 44
   ) AS LONG                                            ' __retval_out LONG *WidthVal
   ' =====================================================================================
   PROPERTY SET Width <1610743812> ( _                  ' VTable offset = 48
     BYVAL WidthVal AS LONG _                           ' __in LONG WidthVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Height <1610743814> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out LONG *HeightVal
   ' =====================================================================================
   PROPERTY SET Height <1610743814> ( _                 ' VTable offset = 56
     BYVAL HeightVal AS LONG _                          ' __in LONG HeightVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HWnd <1610743816> ( _                   ' VTable offset = 60
   ) AS DWORD                                           ' __retval_out HWND *HWndVal
   ' =====================================================================================
   PROPERTY SET HWnd <1610743816> ( _                   ' VTable offset = 64
     BYVAL HWndVal AS DWORD _                           ' __in HWND HWndVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rect <1610743818> ( _                   ' VTable offset = 68
     BYVAL RectVal AS IMSVidRect _                      ' __in IMSVidRect *RectVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidRect_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidGraphSegmentContainer
' IID = {3DD2903D-E0AA-11D2-B63A-00C04F79498E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMSVidGraphSegmentContainer_INTERFACE_DEFINED)
    %IMSVidGraphSegmentContainer_INTERFACE_DEFINED = 1

$IID_IMSVidGraphSegmentContainer = GUID$("{3DD2903D-E0AA-11D2-B63A-00C04F79498E}")

INTERFACE IMSVidGraphSegmentContainer $IID_IMSVidGraphSegmentContainer

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET Graph ( _                               ' VTable offset = 12
   ) AS IGraphBuilder                                   ' __out IGraphBuilder **ppGraph
   ' =====================================================================================
   PROPERTY GET Input ( _                               ' VTable offset = 16
   ) AS IMSVidGraphSegment                              ' __out IMSVidGraphSegment **pInput
   ' =====================================================================================
   PROPERTY GET Outputs ( _                             ' VTable offset = 20
   ) AS IEnumMSVidGraphSegment                          ' __out IEnumMSVidGraphSegment **pOutputs
   ' =====================================================================================
   PROPERTY GET VideoRenderer ( _                       ' VTable offset = 24
   ) AS IMSVidGraphSegment                              ' __out IMSVidGraphSegment **pVR
   ' =====================================================================================
   PROPERTY GET AudioRenderer ( _                       ' VTable offset = 28
   ) AS IMSVidGraphSegment                              ' __out IMSVidGraphSegment **pAR
   ' =====================================================================================
   PROPERTY GET Features ( _                            ' VTable offset = 32
   ) AS IEnumMSVidGraphSegment                          ' __out IEnumMSVidGraphSegment **pOutputs
   ' =====================================================================================
   PROPERTY GET Composites ( _                          ' VTable offset = 36
   ) AS IEnumMSVidGraphSegment                          ' __out IEnumMSVidGraphSegment **pComposites
   ' =====================================================================================
   PROPERTY GET ParentContainer ( _                     ' VTable offset = 40
   ) AS IUnknown                                        ' __out IUnknown **ppContainer
   ' =====================================================================================
   METHOD Decompose ( _                                 ' VTable offset = 44
     BYVAL pSegment AS IMSVidGraphSegment _             ' __in IMSVidGraphSegment *pSegment
   )                                                    ' void
   ' =====================================================================================
   METHOD IsWindowless ( _                              ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD GetFocus ( _                                  ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidGraphSegmentContainer_INTERFACE_DEFINED__ */


' ========================================================================================
' MSVidSegmentType enum
' ========================================================================================

%MSVidSEG_SOURCE = 0
%MSVidSEG_XFORM  = %MSVidSEG_SOURCE + 1
%MSVidSEG_DEST   = %MSVidSEG_XFORM  + 1


' ########################################################################################
' Interface name = IMSVidGraphSegment
' IID = {1C15D482-911D-11D2-B632-00C04F79498E}
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IMSVidGraphSegment_INTERFACE_DEFINED)
    %IMSVidGraphSegment_INTERFACE_DEFINED = 1

$IID_IMSVidGraphSegment = GUID$("{1C15D482-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidGraphSegment $IID_IMSVidGraphSegment

   INHERIT IAutomation

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGraphSegment Methods
   ' =====================================================================================
   PROPERTY GET Init ( _                                ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out IUnknown **pInit
   ' =====================================================================================
   PROPERTY SET Init ( _                                ' VTable offset = 20
     BYVAL pInit AS IUnknown _                          ' __in IUnknown *pInit
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 24
     BYREF pNewEnum AS IEnumFilters _                   ' __out IEnumFilters **pNewEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Container ( _                           ' VTable offset = 28
   ) AS IMSVidGraphSegmentContainer                     ' __retval_out IMSVidGraphSegmentContainer **ppCtl
   ' =====================================================================================
   PROPERTY SET Container ( _                           ' VTable offset = 32
     BYVAL pCtl AS IMSVidGraphSegmentContainer _        ' __in IMSVidGraphSegmentContainer *pCtl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET type ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out MSVidSegmentType *pType
   ' =====================================================================================
   PROPERTY GET Category ( _                            ' VTable offset = 40
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   METHOD Build ( _                                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD PreRun ( _                                    ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD PostRun ( _                                   ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD PreStop ( _                                   ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD PostStop ( _                                  ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD OnEventNotify ( _                             ' VTable offset = 64
     BYVAL lEventCode AS LONG _                         ' __in LONG lEventCode
   , BYVAL lEventParm1 AS LONG _                        ' __in LONG_PTR lEventParm1
   , BYVAL lEventParm2 AS LONG _                        ' __in LONG_PTR lEventParm2
   )                                                    ' void
   ' =====================================================================================
   METHOD Decompose ( _                                 ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidGraphSegment_INTERFACE_DEFINED__ */


' enum __MIDL___MIDL_itf_segment_0480_0001
%MSVIDCTL_LEFT_BUTTON   = &H1
%MSVIDCTL_RIGHT_BUTTON  = &H2
%MSVIDCTL_MIDDLE_BUTTON = &H4
%MSVIDCTL_X_BUTTON1     = &H8
%MSVIDCTL_X_BUTTON2     = &H10
%MSVIDCTL_SHIFT         = &H1
%MSVIDCTL_CTRL          = &H2
%MSVIDCTL_ALT           = &H4


' ########################################################################################
' Interface name = IMSVidGraphSegmentUserInput
' IID = {301C060E-20D9-4587-9B03-F82ED9A9943C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMSVidGraphSegmentUserInput_INTERFACE_DEFINED)
    %IMSVidGraphSegmentUserInput_INTERFACE_DEFINED = 1

$IID_IMSVidGraphSegmentUserInput = GUID$("{301C060E-20D9-4587-9B03-F82ED9A9943C}")

INTERFACE IMSVidGraphSegmentUserInput $IID_IMSVidGraphSegmentUserInput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Click ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DblClick ( _                                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyDown ( _                                   ' VTable offset = 20
     BYREF KeyCode AS INTEGER _                         ' __in_out short *KeyCode
   , BYVAL ShiftState AS INTEGER _                      ' __in short ShiftState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyPress ( _                                  ' VTable offset = 24
     BYREF KeyAscii AS INTEGER _                        ' __in short *KeyAscii
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KeyUp ( _                                     ' VTable offset = 28
     BYREF KeyCode AS INTEGER _                         ' __in_out short *KeyCode
   , BYVAL ShiftState AS INTEGER _                      ' __in short ShiftState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MouseDown ( _                                 ' VTable offset = 32
     BYVAL ButtonState AS INTEGER _                     ' __in short ButtonState
   , BYVAL ShiftState AS INTEGER _                      ' __in short ShiftState
   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MouseMove ( _                                 ' VTable offset = 36
     BYVAL ButtonState AS INTEGER _                     ' __in short ButtonState
   , BYVAL ShiftState AS INTEGER _                      ' __in short ShiftState
   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MouseUp ( _                                   ' VTable offset = 40
     BYVAL ButtonState AS INTEGER _                     ' __in short ButtonState
   , BYVAL ShiftState AS INTEGER _                      ' __in short ShiftState
   , BYVAL x AS LONG _                                  ' __in OLE_XPOS_PIXELS x
   , BYVAL y AS LONG _                                  ' __in OLE_YPOS_PIXELS y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


#ENDIF   ' /* __IMSVidGraphSegmentUserInput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidCompositionSegment
' IID = {1C15D483-911D-11D2-B632-00C04F79498E}
' Inherited interface = IMSVidGraphSegment
' ########################################################################################

#IF NOT %DEF(%IMSVidCompositionSegment_INTERFACE_DEFINED)
    %IMSVidCompositionSegment_INTERFACE_DEFINED = 1

$IID_IMSVidCompositionSegment = GUID$("{1C15D483-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidCompositionSegment $IID_IMSVidCompositionSegment

   INHERIT IAutomation

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGraphSegment Methods
   ' =====================================================================================
   PROPERTY GET Init ( _                                ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out IUnknown **pInit
   ' =====================================================================================
   PROPERTY SET Init ( _                                ' VTable offset = 20
     BYVAL pInit AS IUnknown _                          ' __in IUnknown *pInit
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 24
     BYREF pNewEnum AS IEnumFilters _                   ' __out IEnumFilters **pNewEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Container ( _                           ' VTable offset = 28
   ) AS IMSVidGraphSegmentContainer                     ' __retval_out IMSVidGraphSegmentContainer **ppCtl
   ' =====================================================================================
   PROPERTY SET Container ( _                           ' VTable offset = 32
     BYVAL pCtl AS IMSVidGraphSegmentContainer _        ' __in IMSVidGraphSegmentContainer *pCtl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET type ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out MSVidSegmentType *pType
   ' =====================================================================================
   PROPERTY GET Category ( _                            ' VTable offset = 40
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   METHOD Build ( _                                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD PreRun ( _                                    ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD PostRun ( _                                   ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD PreStop ( _                                   ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD PostStop ( _                                  ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD OnEventNotify ( _                             ' VTable offset = 64
     BYVAL lEventCode AS LONG _                         ' __in LONG lEventCode
   , BYVAL lEventParm1 AS LONG _                        ' __in LONG_PTR lEventParm1
   , BYVAL lEventParm2 AS LONG _                        ' __in LONG_PTR lEventParm2
   )                                                    ' void
   ' =====================================================================================
   METHOD Decompose ( _                                 ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidCompositionSegment Methods
   ' =====================================================================================
   METHOD Compose ( _                                   ' VTable offset = 72
     BYVAL upstream AS IMSVidGraphSegment _             ' __in IMSVidGraphSegment *upstream
   , BYVAL downstream AS IMSVidGraphSegment _           ' __in IMSVidGraphSegment *downstream
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Up ( _                                  ' VTable offset = 76
   ) AS IMSVidGraphSegment                              ' __out IMSVidGraphSegment **upstream
   ' =====================================================================================
   PROPERTY GET Down ( _                                ' VTable offset = 80
   ) AS IMSVidGraphSegment                              ' __out IMSVidGraphSegment **downstream
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidCompositionSegment_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumMSVidGraphSegment
' IID = {3DD2903E-E0AA-11D2-B63A-00C04F79498E}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMSVidGraphSegment_INTERFACE_DEFINED)
    %IEnumMSVidGraphSegment_INTERFACE_DEFINED = 1

$IID_IEnumMSVidGraphSegment = GUID$("{3DD2903E-E0AA-11D2-B63A-00C04F79498E}")

INTERFACE IEnumMSVidGraphSegment $IID_IEnumMSVidGraphSegment

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IMSVidGraphSegment _                ' __out IMSVidGraphSegment **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumMSVidGraphSegment _           ' __out IEnumMSVidGraphSegment **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMSVidGraphSegment_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVRGraphSegment
' IID = {DD47DE3F-9874-4F7B-8B22-7CB2688461E7}
' Inherited interface = IMSVidGraphSegment
' ########################################################################################

#IF NOT %DEF(%IMSVidVRGraphSegment_INTERFACE_DEFINED)
    %IMSVidVRGraphSegment_INTERFACE_DEFINED = 1

$IID_IMSVidVRGraphSegment = GUID$("{DD47DE3F-9874-4F7B-8B22-7CB2688461E7}")

INTERFACE IMSVidVRGraphSegment $IID_IMSVidVRGraphSegment

   INHERIT IAutomation

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGraphSegment Methods
   ' =====================================================================================
   PROPERTY GET Init ( _                                ' VTable offset = 16
   ) AS IUnknown                                        ' __retval_out IUnknown **pInit
   ' =====================================================================================
   PROPERTY SET Init ( _                                ' VTable offset = 20
     BYVAL pInit AS IUnknown _                          ' __in IUnknown *pInit
   )                                                    ' void
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 24
     BYREF pNewEnum AS IEnumFilters _                   ' __out IEnumFilters **pNewEnum
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Container ( _                           ' VTable offset = 28
   ) AS IMSVidGraphSegmentContainer                     ' __retval_out IMSVidGraphSegmentContainer **ppCtl
   ' =====================================================================================
   PROPERTY SET Container ( _                           ' VTable offset = 32
     BYVAL pCtl AS IMSVidGraphSegmentContainer _        ' __in IMSVidGraphSegmentContainer *pCtl
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET type ( _                                ' VTable offset = 36
   ) AS LONG                                            ' __retval_out MSVidSegmentType *pType
   ' =====================================================================================
   PROPERTY GET Category ( _                            ' VTable offset = 40
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   METHOD Build ( _                                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD PreRun ( _                                    ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD PostRun ( _                                   ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD PreStop ( _                                   ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD PostStop ( _                                  ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD OnEventNotify ( _                             ' VTable offset = 64
     BYVAL lEventCode AS LONG _                         ' __in LONG lEventCode
   , BYVAL lEventParm1 AS LONG _                        ' __in LONG_PTR lEventParm1
   , BYVAL lEventParm2 AS LONG _                        ' __in LONG_PTR lEventParm2
   )                                                    ' void
   ' =====================================================================================
   METHOD Decompose ( _                                 ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVRGraphSegment Methods
   ' =====================================================================================
   PROPERTY SET VMRendererMode_ ( _                     ' VTable offset = 72
     BYVAL dwMode AS LONG _                             ' __in LONG dwMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Owner ( _                               ' VTable offset = 76
     BYVAL Window AS DWORD _                            ' __in HWND Window
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Owner ( _                               ' VTable offset = 80
   ) AS DWORD                                           ' __retval_out HWND *Window
   ' =====================================================================================
   PROPERTY GET UseOverlay ( _                          ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *UseOverlayVal
   ' =====================================================================================
   PROPERTY SET UseOverlay ( _                          ' VTable offset = 88
     BYVAL UseOverlayVal AS INTEGER _                   ' __in VARIANT_BOOL UseOverlayVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Visible ( _                             ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Visible
   ' =====================================================================================
   PROPERTY SET Visible ( _                             ' VTable offset = 96
     BYVAL Visible AS INTEGER _                         ' __in VARIANT_BOOL Visible
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ColorKey ( _                            ' VTable offset = 100
   ) AS DWORD                                           ' __retval_out OLE_COLOR *ColorKey
   ' =====================================================================================
   PROPERTY SET ColorKey ( _                            ' VTable offset = 104
     BYVAL ColorKey AS DWORD _                          ' __in OLE_COLOR ColorKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Source ( _                              ' VTable offset = 108
   ) AS RECT                                            ' __retval_out LPRECT r
   ' =====================================================================================
   PROPERTY SET Source ( _                              ' VTable offset = 112
     BYVAL r AS RECT _                                  ' __in RECT r
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Destination ( _                         ' VTable offset = 116
   ) AS RECT                                            ' __retval_out LPRECT r
   ' =====================================================================================
   PROPERTY SET Destination ( _                         ' VTable offset = 120
     BYVAL r AS RECT _                                  ' __in RECT r
   )                                                    ' void
   ' =====================================================================================
   METHOD NativeSize ( _                                ' VTable offset = 124
     BYREF sizeval AS SIZE _                            ' __out LPSIZE sizeval
   , BYREF aspectratio AS SIZE _                        ' __out LPSIZE aspectratio
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BorderColor ( _                         ' VTable offset = 128
   ) AS DWORD                                           ' __retval_out OLE_COLOR *color
   ' =====================================================================================
   PROPERTY SET BorderColor ( _                         ' VTable offset = 132
     BYVAL color AS DWORD _                             ' __in OLE_COLOR color
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaintainAspectRatio ( _                 ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fMaintain
   ' =====================================================================================
   PROPERTY SET MaintainAspectRatio ( _                 ' VTable offset = 140
     BYVAL fMaintain AS INTEGER _                       ' __in VARIANT_BOOL fMaintain
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   METHOD DisplayChange ( _                             ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   METHOD RePaint ( _                                   ' VTable offset = 152
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVRGraphSegment_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidDevice
' IID = {1C15D47C-911D-11D2-B632-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidDevice_INTERFACE_DEFINED)
    %IMSVidDevice_INTERFACE_DEFINED = 1

$IID_IMSVidDevice = GUID$("{1C15D47C-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidDevice $IID_IMSVidDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidDevice2
' IID = {87BD2783-EBC0-478C-B4A0-E8E7F43AB78E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMSVidDevice2_INTERFACE_DEFINED)
    %IMSVidDevice2_INTERFACE_DEFINED = 1

$IID_IMSVidDevice2 = GUID$("{87BD2783-EBC0-478C-B4A0-E8E7F43AB78E}")

INTERFACE IMSVidDevice2 $IID_IMSVidDevice2

   INHERIT IAutomation

   ' =====================================================================================
   PROPERTY GET DevicePath ( _                          ' VTable offset = 12
   ) AS WSTRING                                         ' __retval_out BSTR *DevPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidDevice2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidInputDevice
' IID = {37B0353D-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidInputDevice_INTERFACE_DEFINED)
    %IMSVidInputDevice_INTERFACE_DEFINED = 1

$IID_IMSVidInputDevice = GUID$("{37B0353D-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidInputDevice $IID_IMSVidInputDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidInputDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidDeviceEvent
' IID = {1C15D480-911D-11D2-B632-00C04F79498E}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidDeviceEvent_INTERFACE_DEFINED)
    %IMSVidDeviceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidDeviceEvent = GUID$("{1C15D480-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidDeviceEvent $IID_IMSVidDeviceEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidDeviceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidInputDeviceEvent
' IID = {37B0353E-A4C8-11D2-B634-00C04F79498E}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidInputDeviceEvent_INTERFACE_DEFINED)
    %IMSVidInputDeviceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidInputDeviceEvent = GUID$("{37B0353E-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidInputDeviceEvent $IID_IMSVidInputDeviceEvent

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IMSVidInputDeviceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVideoInputDevice
' IID = {1C15D47F-911D-11D2-B632-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidInputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoInputDevice_INTERFACE_DEFINED)
    %IMSVidVideoInputDevice_INTERFACE_DEFINED = 1

$IID_IMSVidVideoInputDevice = GUID$("{1C15D47F-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidVideoInputDevice $IID_IMSVidVideoInputDevice

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoInputDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidPlayback
' IID = {37B03538-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidInputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidPlayback_INTERFACE_DEFINED)
    %IMSVidPlayback_INTERFACE_DEFINED = 1

$IID_IMSVidPlayback = GUID$("{37B03538-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidPlayback $IID_IMSVidPlayback

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidPlayback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidPlaybackEvent
' IID = {37B03538-A4C8-11D2-B634-00C04F79498E}
' Inherited interface = IMSVidInputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidPlaybackEvent_INTERFACE_DEFINED)
    %IMSVidPlaybackEvent_INTERFACE_DEFINED = 1

$IID_IMSVidPlaybackEvent = GUID$("{37B0353B-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidPlaybackEvent $IID_IMSVidPlaybackEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidPlaybackEvent Methods
   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL lpd AS IMSVidPlayback _                     ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidPlaybackEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidTuner
' IID = {1C15D47D-911D-11D2-B632-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidVideoInputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidTuner_INTERFACE_DEFINED)
    %IMSVidTuner_INTERFACE_DEFINED = 1

$IID_IMSVidTuner = GUID$("{1C15D47D-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidTuner $IID_IMSVidTuner

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tune <27> ( _                           ' VTable offset = 72
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **ppTR
   ' =====================================================================================
   PROPERTY SET Tune <27> ( _                           ' VTable offset = 76
     BYVAL pTR AS ITuneRequest _                        ' __in ITuneRequest *pTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TuningSpace <28> ( _                    ' VTable offset = 80
   ) AS ITuneRequest                                    ' __retval_out ITuningSpace **plTS
   ' =====================================================================================
   PROPERTY SET TuningSpace <28> ( _                    ' VTable offset = 84
     BYVAL plTS AS ITuningSpace _                       ' __in ITuningSpace *plTS
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidTuner_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidTunerEvent
' IID = {1C15D485-911D-11D2-B632-00C04F79498E}
' Inherited interface = IMSVidInputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidTunerEvent_INTERFACE_DEFINED)
    %IMSVidTunerEvent_INTERFACE_DEFINED = 1

$IID_IMSVidTunerEvent = GUID$("{1C15D485-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidTunerEvent $IID_IMSVidTunerEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD TuneChanged <1> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidTuner _                         ' __in IMSVidTuner *lpd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidTunerEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAnalogTuner
' IID = {1C15D47E-911D-11D2-B632-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidTuner
' ########################################################################################

#IF NOT %DEF(%IMSVidAnalogTuner_INTERFACE_DEFINED)
    %IMSVidAnalogTuner_INTERFACE_DEFINED = 1

$IID_IMSVidAnalogTuner = GUID$("{1C15D47E-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidAnalogTuner $IID_IMSVidAnalogTuner

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tune <27> ( _                           ' VTable offset = 72
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **ppTR
   ' =====================================================================================
   PROPERTY SET Tune <27> ( _                           ' VTable offset = 76
     BYVAL pTR AS ITuneRequest _                        ' __in ITuneRequest *pTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TuningSpace <28> ( _                    ' VTable offset = 80
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **plTS
   ' =====================================================================================
   PROPERTY SET TuningSpace <28> ( _                    ' VTable offset = 84
     BYVAL plTS AS ITuningSpace _                       ' __in ITuningSpace *plTS
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Channel <10> ( _                        ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *Channel
   ' =====================================================================================
   PROPERTY SET Channel <10> ( _                        ' VTable offset = 92
     BYVAL Channel AS LONG _                            ' __in long Channel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VideoFrequency <14> ( _                 ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY GET AudioFrequency <15> ( _                 ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY GET CountryCode <4> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY SET CountryCode <4> ( _                     ' VTable offset = 108
     BYVAL lcc AS LONG _                                ' __in long lcc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAP <29> ( _                            ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSapOn
   ' =====================================================================================
   PROPERTY SET SAP <29> ( _                            ' VTable offset = 116
     BYVAL fSapOn AS INTEGER _                          ' __in VARIANT_BOOL fSapOn
   )                                                    ' void
   ' =====================================================================================
   METHOD ChannelAvailable <13> ( _                     ' VTable offset = 120
     BYVAL nChannel AS LONG _                           ' __in long nChannel
   , BYREF SignalStrength AS LONG _                     ' __out long *SignalStrength
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fSignalPresent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAnalogTuner_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAnalogTuner2
' IID = {37647BF7-3DDE-4CC8-A4DC-0D534D3D0037}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidAnalogTuner
' ########################################################################################

#IF NOT %DEF(%IMSVidAnalogTuner2_INTERFACE_DEFINED)
    %IMSVidAnalogTuner2_INTERFACE_DEFINED = 1

$IID_IMSVidAnalogTuner2 = GUID$("{37647BF7-3DDE-4CC8-A4DC-0D534D3D0037}")

INTERFACE IMSVidAnalogTuner2 $IID_IMSVidAnalogTuner2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tune <27> ( _                           ' VTable offset = 72
   ) AS ITuneRequest                                    ' __retval_out ITuneRequest **ppTR
   ' =====================================================================================
   PROPERTY SET Tune <27> ( _                           ' VTable offset = 76
     BYVAL pTR AS ITuneRequest _                        ' __in ITuneRequest *pTR
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TuningSpace <28> ( _                    ' VTable offset = 80
   ) AS ITuningSpace                                    ' __retval_out ITuningSpace **plTS
   ' =====================================================================================
   PROPERTY SET TuningSpace <28> ( _                    ' VTable offset = 84
     BYVAL plTS AS ITuningSpace _                       ' __in ITuningSpace *plTS
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Channel <10> ( _                        ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *Channel
   ' =====================================================================================
   PROPERTY SET Channel <10> ( _                        ' VTable offset = 92
     BYVAL Channel AS LONG _                            ' __in long Channel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VideoFrequency <14> ( _                 ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY GET AudioFrequency <15> ( _                 ' VTable offset = 100
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY GET CountryCode <4> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *lcc
   ' =====================================================================================
   PROPERTY SET CountryCode <4> ( _                     ' VTable offset = 108
     BYVAL lcc AS LONG _                                ' __in long lcc
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SAP <29> ( _                            ' VTable offset = 112
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfSapOn
   ' =====================================================================================
   PROPERTY SET SAP <29> ( _                            ' VTable offset = 116
     BYVAL fSapOn AS INTEGER _                          ' __in VARIANT_BOOL fSapOn
   )                                                    ' void
   ' =====================================================================================
   METHOD ChannelAvailable <13> ( _                     ' VTable offset = 120
     BYVAL nChannel AS LONG _                           ' __in long nChannel
   , BYREF SignalStrength AS LONG _                     ' __out long *SignalStrength
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fSignalPresent
   ' =====================================================================================
   PROPERTY GET TVFormats <193> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long*  Formats
   ' =====================================================================================
   PROPERTY GET TunerModes <194> ( _                    ' VTable offset = 128
   ) AS LONG                                            ' __retval_out long*  Modes
   ' =====================================================================================
   PROPERTY GET NumAuxInputs <195> ( _                  ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long*  Inputs
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAnalogTuner2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAnalogTunerEvent
' IID = {1C15D486-911D-11d2-B632-00C04F79498E}
' Inherited interface = IMSVidTunerEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidAnalogTunerEvent_INTERFACE_DEFINED)
    %IMSVidAnalogTunerEvent_INTERFACE_DEFINED = 1

$IID_IMSVidAnalogTunerEvent = GUID$("{1C15D486-911D-11D2-B632-00C04F79498E}")

INTERFACE IMSVidAnalogTunerEvent $IID_IMSVidAnalogTunerEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD TuneChanged <1> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidTuner _                         ' __in IMSVidTuner *lpd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAnalogTunerEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFilePlayback
' IID = {37B03539-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidPlayback
' ########################################################################################

#IF NOT %DEF(%IMSVidFilePlayback_INTERFACE_DEFINED)
    %IMSVidFilePlayback_INTERFACE_DEFINED = 1

$IID_IMSVidFilePlayback = GUID$("{37B03539-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidFilePlayback $IID_IMSVidFilePlayback

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidFilePlayback Methods
   ' =====================================================================================
   PROPERTY GET FileName <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *FileName
   ' =====================================================================================
   PROPERTY SET FileName <17> ( _                       ' VTable offset = 132
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFilePlayback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFilePlayback2
' IID = {2F7E44AF-6E52-4660-BC08-D8D542587D72}
' Inherited interface = IMSVidFilePlayback
' ########################################################################################

#IF NOT %DEF(%IMSVidFilePlayback2_INTERFACE_DEFINED)
    %IMSVidFilePlayback2_INTERFACE_DEFINED = 1

$IID_IMSVidFilePlayback2 = GUID$("{2F7E44AF-6E52-4660-BC08-D8D542587D72}")

INTERFACE IMSVidFilePlayback2 $IID_IMSVidFilePlayback2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidFilePlayback Methods
   ' =====================================================================================
   PROPERTY GET FileName <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *FileName
   ' =====================================================================================
   PROPERTY SET FileName <17> ( _                       ' VTable offset = 132
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidFilePlayback2 Methods
   ' =====================================================================================
   PROPERTY SET SourceFilter_ <218> ( _                 ' VTable offset = 136
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SourceFilter__ <219> ( _                ' VTable offset = 140
     BYVAL FileName AS GUID _                           ' __in GUID FileName
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFilePlayback2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFilePlaybackEvent
' IID = {37B0353A-A4C8-11D2-B634-00C04F79498E}
' Inherited interface = IMSVidPlaybackEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidFilePlaybackEvent_INTERFACE_DEFINED)
    %IMSVidFilePlaybackEvent_INTERFACE_DEFINED = 1

$IID_IMSVidFilePlaybackEvent = GUID$("{37B0353A-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidFilePlaybackEvent $IID_IMSVidFilePlaybackEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL lpd AS IMSVidPlayback _                     ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFilePlaybackEvent_INTERFACE_DEFINED__ */


' ========================================================================================
' DVDMenuIDConstants enum
' ========================================================================================

%dvdMenu_Title      = 2
%dvdMenu_Root       = %dvdMenu_Title      + 1
%dvdMenu_Subpicture = %dvdMenu_Root       + 1
%dvdMenu_Audio      = %dvdMenu_Subpicture + 1
%dvdMenu_Angle      = %dvdMenu_Audio      + 1
%dvdMenu_Chapter    = %dvdMenu_Angle      + 1


' ========================================================================================
' enum DVDFilterState
' ========================================================================================

%dvdState_Undefined   = -2
%dvdState_Unitialized = %dvdState_Undefined   + 1
%dvdState_Stopped     = %dvdState_Unitialized + 1
%dvdState_Paused      = %dvdState_Stopped     + 1
%dvdState_Running     = %dvdState_Paused      + 1

' ========================================================================================
' DVDTextStringType enum
' ========================================================================================

%dvdStruct_Volume      = &H1
%dvdStruct_Title       = &H2
%dvdStruct_ParentalID  = &H3
%dvdStruct_PartOfTitle = &H4
%dvdStruct_Cell        = &H5
%dvdStream_Audio       = &H10
%dvdStream_Subpicture  = &H11
%dvdStream_Angle       = &H12
%dvdChannel_Audio      = &H20
%dvdGeneral_Name       = &H30
%dvdGeneral_Comments   = &H31
%dvdTitle_Series       = &H38
%dvdTitle_Movie        = &H39
%dvdTitle_Video        = &H3a
%dvdTitle_Album        = &H3b
%dvdTitle_Song         = &H3c
%dvdTitle_Other        = &H3f
%dvdTitle_Sub_Series   = &H40
%dvdTitle_Sub_Movie    = &H41
%dvdTitle_Sub_Video    = &H42
%dvdTitle_Sub_Album    = &H43
%dvdTitle_Sub_Song     = &H44
%dvdTitle_Sub_Other    = &H47
%dvdTitle_Orig_Series  = &H48
%dvdTitle_Orig_Movie   = &H49
%dvdTitle_Orig_Video   = &H4a
%dvdTitle_Orig_Album   = &H4b
%dvdTitle_Orig_Song    = &H4c
%dvdTitle_Orig_Other   = &H4f
%dvdOther_Scene        = &H50
%dvdOther_Cut          = &H51
%dvdOther_Take         = &H52

' ========================================================================================
' DVDSPExt enum
' ========================================================================================

%dvdSPExt_NotSpecified              = 0
%dvdSPExt_Caption_Normal            = 1
%dvdSPExt_Caption_Big               = 2
%dvdSPExt_Caption_Children          = 3
%dvdSPExt_CC_Normal                 = 5
%dvdSPExt_CC_Big                    = 6
%dvdSPExt_CC_Children               = 7
%dvdSPExt_Forced                    = 9
%dvdSPExt_DirectorComments_Normal   = 13
%dvdSPExt_DirectorComments_Big      = 14
%dvdSPExt_DirectorComments_Children = 15


' ########################################################################################
' Interface name = IMSVidWebDVD
' IID = {CF45F88B-AC56-4EE2-A73A-ED04E2885D3C}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidPlayback
' ########################################################################################

#IF NOT %DEF(%IMSVidWebDVD_INTERFACE_DEFINED)
    %IMSVidWebDVD_INTERFACE_DEFINED = 1

$IID_IMSVidWebDVD = GUID$("{CF45F88B-AC56-4EE2-A73A-ED04E2885D3C}")

INTERFACE IMSVidWebDVD $IID_IMSVidWebDVD

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidWebDVD Methods
   ' =====================================================================================
   METHOD OnDVDEvent <1610940416> ( _                   ' VTable offset = 128
     BYVAL lEvent AS LONG _                             ' __in long lEvent
   , BYVAL lParam1 AS LONG _                            ' __in LONG_PTR lParam1
   , BYVAL lParam2 AS LONG _                            ' __in LONG_PTR lParam2
   )                                                    '
   ' =====================================================================================
   METHOD PlayTitle <42> ( _                            ' VTable offset = 132
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapterInTitle <43> ( _                   ' VTable offset = 136
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL lChapter AS LONG _                           ' __in long lChapter
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapter <44> ( _                          ' VTable offset = 140
     BYVAL lChapter AS LONG _                           ' __in long lChapter
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChaptersAutoStop <45> ( _                 ' VTable offset = 144
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL lstrChapter AS LONG _                        ' __in long lstrChapter
   , BYVAL lChapterCount AS LONG _                      ' __in long lChapterCount
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTime <46> ( _                           ' VTable offset = 148
     BYVAL strTime AS WSTRING _                         ' __in BSTR strTime
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTimeInTitle <47> ( _                    ' VTable offset = 152
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL strTime AS WSTRING _                         ' __in BSTR strTime
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayPeriodInTitleAutoStop <48> ( _            ' VTable offset = 156
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL strStartTime AS WSTRING _                    ' __in BSTR strStartTime
   , BYVAL strEndTime AS WSTRING _                      ' __in BSTR strEndTime
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplayChapter <49> ( _                        ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayPrevChapter <50> ( _                      ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayNextChapter <51> ( _                      ' VTable offset = 168
   )                                                    ' void
   ' =====================================================================================
   METHOD StillOff <54> ( _                             ' VTable offset = 172
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioLanguage <55> ( _                  ' VTable offset = 176
     BYVAL lStream AS LONG _                            ' __in long lStream
   , OPTIONAL BYVAL fFormat AS INTEGER _                ' __opt_in VARIANT_BOOL fFormat
   ) AS WSTRING                                         ' __retval_out BSTR *strAudioLang
   ' =====================================================================================
   METHOD ShowMenu <56> ( _                             ' VTable offset = 180
     BYVAL MenuID AS LONG _                             ' __in DVDMenuIDConstants MenuID
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <57> ( _                               ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD ReturnFromSubmenu <58> ( _                    ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonsAvailable <59> ( _               ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentButton <60> ( _                  ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD SelectAndActivateButton <61> ( _              ' VTable offset = 200
     BYVAL lButton AS LONG _                            ' __in long lButton
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateButton <62> ( _                       ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectRightButton <63> ( _                    ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectLeftButton <64> ( _                     ' VTable offset = 212
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectLowerButton <65> ( _                    ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectUpperButton <66> ( _                    ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateAtPosition <67> ( _                   ' VTable offset = 224
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectAtPosition <68> ( _                     ' VTable offset = 228
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonAtPosition <69> ( _               ' VTable offset = 232
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   ) AS LONG                                            ' __retval_out long *plButton
   ' =====================================================================================
   PROPERTY GET NumberOfChapters <70> ( _               ' VTable offset = 236
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET TotalTitleTime <71> ( _                 ' VTable offset = 240
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET TitlesAvailable <72> ( _                ' VTable offset = 244
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET VolumesAvailable <73> ( _               ' VTable offset = 248
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentVolume <74> ( _                  ' VTable offset = 252
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDiscSide <75> ( _                ' VTable offset = 256
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDomain <76> ( _                  ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentChapter <77> ( _                 ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentTitle <78> ( _                   ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentTime <79> ( _                    ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD DVDTimeCode2bstr <81> ( _                     ' VTable offset = 276
     BYVAL timeCode AS LONG _                           ' __in long timeCode
   ) AS WSTRING                                         ' __retval_out BSTR *pTimeStr
   ' =====================================================================================
   PROPERTY GET DVDDirectory <82> ( _                   ' VTable offset = 280
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DVDDirectory <82> ( _                   ' VTable offset = 284
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSubpictureStreamEnabled <83> ( _            ' VTable offset = 288
     BYVAL lstream AS LONG _                            ' __in long lstream
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fEnabled
   ' =====================================================================================
   METHOD IsAudioStreamEnabled <84> ( _                 ' VTable offset = 292
     BYVAL lstream AS LONG _                            ' __in long lstream
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fEnabled
   ' =====================================================================================
   PROPERTY GET CurrentSubpictureStream <85> ( _        ' VTable offset = 296
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentSubpictureStream <85> ( _        ' VTable offset = 300
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubpictureLanguage <86> ( _             ' VTable offset = 304
     BYVAL lStream AS LONG _                            ' __in long lStream
   ) AS WSTRING                                         ' __retval_out BSTR *strLanguage
   ' =====================================================================================
   PROPERTY GET CurrentAudioStream <87> ( _             ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentAudioStream <87> ( _             ' VTable offset = 312
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioStreamsAvailable <88> ( _          ' VTable offset = 316
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET AnglesAvailable <89> ( _                ' VTable offset = 320
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentAngle <90> ( _                   ' VTable offset = 324
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentAngle <90> ( _                   ' VTable offset = 328
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubpictureStreamsAvailable <93> ( _     ' VTable offset = 332
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET SubpictureOn <94> ( _                   ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SubpictureOn <94> ( _                   ' VTable offset = 340
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDUniqueID <95> ( _                    ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD AcceptParentalLevelChange <97> ( _            ' VTable offset = 348
     BYVAL fAccept AS INTEGER _                         ' __in VARIANT_BOOL fAccept
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD NotifyParentalLevelChange <98> ( _            ' VTable offset = 352
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectParentalCountry <99> ( _                ' VTable offset = 356
     BYVAL lCountry AS LONG _                           ' __in long lCountry
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectParentalLevel <100> ( _                 ' VTable offset = 360
     BYVAL lParentalLevel AS LONG _                     ' __in long lParentalLevel
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleParentalLevels <101> ( _           ' VTable offset = 364
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   ) AS LONG                                            ' __retval_out long *plParentalLevels
   ' =====================================================================================
   PROPERTY GET PlayerParentalCountry <102> ( _         ' VTable offset = 368
   ) AS LONG                                            ' __retval_out long *plCountryCode
   ' =====================================================================================
   PROPERTY GET PlayerParentalLevel <103> ( _           ' VTable offset = 372
   ) AS LONG                                            ' __retval_out long *plParentalLevel
   ' =====================================================================================
   METHOD Eject <104> ( _                               ' VTable offset = 376
   )                                                    ' void
   ' =====================================================================================
   METHOD UOPValid <105> ( _                            ' VTable offset = 380
     BYVAL lUOP AS LONG _                               ' __in long lUOP
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfValid
   ' =====================================================================================
   PROPERTY GET SPRM <106> ( _                          ' VTable offset = 384
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS INTEGER                                         ' __retval_out short *psSPRM
   ' =====================================================================================
   PROPERTY GET GPRM <107> ( _                          ' VTable offset = 388
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS INTEGER                                         ' __retval_out short *psSPRM
   ' =====================================================================================
   PROPERTY SET GPRM <107> ( _                          ' VTable offset = 392
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYVAL sValue AS INTEGER _                          ' __in short sValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDTextStringType <108> ( _             ' VTable offset = 396
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   , BYVAL lStringIndex AS LONG _                       ' __in long lStringIndex
   ) AS LONG                                            ' __retval_out DVDTextStringType *pType
   ' =====================================================================================
   PROPERTY GET DVDTextString <109> ( _                 ' VTable offset = 400
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   , BYVAL lStringIndex AS LONG _                       ' __in long lStringIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrText
   ' =====================================================================================
   PROPERTY GET DVDTextNumberOfStrings <110> ( _        ' VTable offset = 404
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   ) AS LONG                                            ' __retval_out long *plNumOfStrings
   ' =====================================================================================
   PROPERTY GET DVDTextNumberOfLanguages <111> ( _      ' VTable offset = 408
   ) AS LONG                                            ' __retval_out long *plNumOfLangs
   ' =====================================================================================
   PROPERTY GET DVDTextLanguageLCID <112> ( _           ' VTable offset = 412
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   ) AS LONG                                            ' __retval_out long *lcid
   ' =====================================================================================
   METHOD RegionChange <113> ( _                        ' VTable offset = 416
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDAdm <114> ( _                        ' VTable offset = 420
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   METHOD DeleteBookmark <115> ( _                      ' VTable offset = 424
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreBookmark <116> ( _                     ' VTable offset = 428
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveBookmark <117> ( _                        ' VTable offset = 432
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectDefaultAudioLanguage <118> ( _          ' VTable offset = 436
     BYVAL lang AS LONG _                               ' __in long lang
   , BYVAL ext AS LONG _                                ' __in long ext
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectDefaultSubpictureLanguage <119> ( _     ' VTable offset = 440
     BYVAL lang AS LONG _                               ' __in long lang
   , BYVAL ext AS LONG _                                ' __in DVDSPExt ext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredSubpictureStream <120> ( _     ' VTable offset = 444
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DefaultMenuLanguage <121> ( _           ' VTable offset = 448
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY SET DefaultMenuLanguage <121> ( _           ' VTable offset = 452
     BYVAL lang AS LONG _                               ' __in long lang
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultSubpictureLanguage <122> ( _     ' VTable offset = 456
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY GET DefaultAudioLanguage <123> ( _          ' VTable offset = 460
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY GET DefaultSubpictureLanguageExt <124> ( _  ' VTable offset = 464
   ) AS LONG                                            ' __retval_out DVDSPExt *ext
   ' =====================================================================================
   PROPERTY GET DefaultAudioLanguageExt <125> ( _       ' VTable offset = 468
   ) AS LONG                                            ' __retval_out long *ext
   ' =====================================================================================
   PROPERTY GET LanguageFromLCID <126> ( _              ' VTable offset = 472
     BYVAL lcid AS LONG _                               ' __in long lcid
   ) AS WSTRING                                         ' __retval_out BSTR *lang
   ' =====================================================================================
   PROPERTY GET KaraokeAudioPresentationMode <127> ( _  ' VTable offset = 476
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET KaraokeAudioPresentationMode <127> ( _  ' VTable offset = 480
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KaraokeChannelContent <128> ( _         ' VTable offset = 484
     BYVAL lStream AS LONG _                            ' __in long lStream
   , BYVAL lChan AS LONG _                              ' __in long lChan
   ) AS LONG                                            ' __retval_out long *lContent
   ' =====================================================================================
   PROPERTY GET KaraokeChannelAssignment <129> ( _      ' VTable offset = 488
     BYVAL lStream AS LONG _                            ' __in long lStream
   ) AS LONG                                            ' __retval_out long *lChannelAssignment
   ' =====================================================================================
   METHOD RestorePreferredSettings <130> ( _            ' VTable offset = 492
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonRect <131> ( _                    ' VTable offset = 496
     BYVAL lButton AS LONG _                            ' __in long lButton
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET DVDScreenInMouseCoordinates <132> ( _   ' VTable offset = 500
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppRect
   ' =====================================================================================
   PROPERTY SET DVDScreenInMouseCoordinates <132> ( _   ' VTable offset = 504
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidWebDVD_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidWebDVD2
' IID = {7027212F-EE9A-4A7C-8B67-F023714CDAFF}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidWebDVD
' ########################################################################################

#IF NOT %DEF(%IMSVidWebDVD2_INTERFACE_DEFINED)
    %IMSVidWebDVD2_INTERFACE_DEFINED = 1

$IID_IMSVidWebDVD2 = GUID$("{7027212F-EE9A-4A7C-8B67-F023714CDAFF}")

INTERFACE IMSVidWebDVD2 $IID_IMSVidWebDVD2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidWebDVD Methods
   ' =====================================================================================
   METHOD OnDVDEvent <1610940416> ( _                   ' VTable offset = 128
     BYVAL lEvent AS LONG _                             ' __in long lEvent
   , BYVAL lParam1 AS LONG _                            ' __in LONG_PTR lParam1
   , BYVAL lParam2 AS LONG _                            ' __in LONG_PTR lParam2
   )                                                    '
   ' =====================================================================================
   METHOD PlayTitle <42> ( _                            ' VTable offset = 132
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapterInTitle <43> ( _                   ' VTable offset = 136
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL lChapter AS LONG _                           ' __in long lChapter
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapter <44> ( _                          ' VTable offset = 140
     BYVAL lChapter AS LONG _                           ' __in long lChapter
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChaptersAutoStop <45> ( _                 ' VTable offset = 144
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL lstrChapter AS LONG _                        ' __in long lstrChapter
   , BYVAL lChapterCount AS LONG _                      ' __in long lChapterCount
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTime <46> ( _                           ' VTable offset = 148
     BYVAL strTime AS WSTRING _                         ' __in BSTR strTime
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTimeInTitle <47> ( _                    ' VTable offset = 152
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL strTime AS WSTRING _                         ' __in BSTR strTime
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayPeriodInTitleAutoStop <48> ( _            ' VTable offset = 156
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   , BYVAL strStartTime AS WSTRING _                    ' __in BSTR strStartTime
   , BYVAL strEndTime AS WSTRING _                      ' __in BSTR strEndTime
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplayChapter <49> ( _                        ' VTable offset = 160
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayPrevChapter <50> ( _                      ' VTable offset = 164
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayNextChapter <51> ( _                      ' VTable offset = 168
   )                                                    ' void
   ' =====================================================================================
   METHOD StillOff <54> ( _                             ' VTable offset = 172
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioLanguage <55> ( _                  ' VTable offset = 176
     BYVAL lStream AS LONG _                            ' __in long lStream
   , OPTIONAL BYVAL fFormat AS INTEGER _                ' __opt_in VARIANT_BOOL fFormat
   ) AS WSTRING                                         ' __retval_out BSTR *strAudioLang
   ' =====================================================================================
   METHOD ShowMenu <56> ( _                             ' VTable offset = 180
     BYVAL MenuID AS LONG _                             ' __in DVDMenuIDConstants MenuID
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <57> ( _                               ' VTable offset = 184
   )                                                    ' void
   ' =====================================================================================
   METHOD ReturnFromSubmenu <58> ( _                    ' VTable offset = 188
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonsAvailable <59> ( _               ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentButton <60> ( _                  ' VTable offset = 196
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD SelectAndActivateButton <61> ( _              ' VTable offset = 200
     BYVAL lButton AS LONG _                            ' __in long lButton
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateButton <62> ( _                       ' VTable offset = 204
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectRightButton <63> ( _                    ' VTable offset = 208
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectLeftButton <64> ( _                     ' VTable offset = 212
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectLowerButton <65> ( _                    ' VTable offset = 216
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectUpperButton <66> ( _                    ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   METHOD ActivateAtPosition <67> ( _                   ' VTable offset = 224
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectAtPosition <68> ( _                     ' VTable offset = 228
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonAtPosition <69> ( _               ' VTable offset = 232
     BYVAL xPos AS LONG _                               ' __in long xPos
   , BYVAL yPos AS LONG _                               ' __in long yPos
   ) AS LONG                                            ' __retval_out long *plButton
   ' =====================================================================================
   PROPERTY GET NumberOfChapters <70> ( _               ' VTable offset = 236
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET TotalTitleTime <71> ( _                 ' VTable offset = 240
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET TitlesAvailable <72> ( _                ' VTable offset = 244
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET VolumesAvailable <73> ( _               ' VTable offset = 248
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentVolume <74> ( _                  ' VTable offset = 252
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDiscSide <75> ( _                ' VTable offset = 256
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentDomain <76> ( _                  ' VTable offset = 260
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentChapter <77> ( _                 ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentTitle <78> ( _                   ' VTable offset = 268
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentTime <79> ( _                    ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD DVDTimeCode2bstr <81> ( _                     ' VTable offset = 276
     BYVAL timeCode AS LONG _                           ' __in long timeCode
   ) AS WSTRING                                         ' __retval_out BSTR *pTimeStr
   ' =====================================================================================
   PROPERTY GET DVDDirectory <82> ( _                   ' VTable offset = 280
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DVDDirectory <82> ( _                   ' VTable offset = 284
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD IsSubpictureStreamEnabled <83> ( _            ' VTable offset = 288
     BYVAL lstream AS LONG _                            ' __in long lstream
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fEnabled
   ' =====================================================================================
   METHOD IsAudioStreamEnabled <84> ( _                 ' VTable offset = 292
     BYVAL lstream AS LONG _                            ' __in long lstream
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *fEnabled
   ' =====================================================================================
   PROPERTY GET CurrentSubpictureStream <85> ( _        ' VTable offset = 296
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentSubpictureStream <85> ( _        ' VTable offset = 300
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubpictureLanguage <86> ( _             ' VTable offset = 304
     BYVAL lStream AS LONG _                            ' __in long lStream
   ) AS WSTRING                                         ' __retval_out BSTR *strLanguage
   ' =====================================================================================
   PROPERTY GET CurrentAudioStream <87> ( _             ' VTable offset = 308
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentAudioStream <87> ( _             ' VTable offset = 312
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioStreamsAvailable <88> ( _          ' VTable offset = 316
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET AnglesAvailable <89> ( _                ' VTable offset = 320
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET CurrentAngle <90> ( _                   ' VTable offset = 324
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CurrentAngle <90> ( _                   ' VTable offset = 328
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SubpictureStreamsAvailable <93> ( _     ' VTable offset = 332
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET SubpictureOn <94> ( _                   ' VTable offset = 336
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET SubpictureOn <94> ( _                   ' VTable offset = 340
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDUniqueID <95> ( _                    ' VTable offset = 344
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD AcceptParentalLevelChange <97> ( _            ' VTable offset = 348
     BYVAL fAccept AS INTEGER _                         ' __in VARIANT_BOOL fAccept
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD NotifyParentalLevelChange <98> ( _            ' VTable offset = 352
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectParentalCountry <99> ( _                ' VTable offset = 356
     BYVAL lCountry AS LONG _                           ' __in long lCountry
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectParentalLevel <100> ( _                 ' VTable offset = 360
     BYVAL lParentalLevel AS LONG _                     ' __in long lParentalLevel
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TitleParentalLevels <101> ( _           ' VTable offset = 364
     BYVAL lTitle AS LONG _                             ' __in long lTitle
   ) AS LONG                                            ' __retval_out long *plParentalLevels
   ' =====================================================================================
   PROPERTY GET PlayerParentalCountry <102> ( _         ' VTable offset = 368
   ) AS LONG                                            ' __retval_out long *plCountryCode
   ' =====================================================================================
   PROPERTY GET PlayerParentalLevel <103> ( _           ' VTable offset = 372
   ) AS LONG                                            ' __retval_out long *plParentalLevel
   ' =====================================================================================
   METHOD Eject <104> ( _                               ' VTable offset = 376
   )                                                    ' void
   ' =====================================================================================
   METHOD UOPValid <105> ( _                            ' VTable offset = 380
     BYVAL lUOP AS LONG _                               ' __in long lUOP
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfValid
   ' =====================================================================================
   PROPERTY GET SPRM <106> ( _                          ' VTable offset = 384
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS INTEGER                                         ' __retval_out short *psSPRM
   ' =====================================================================================
   PROPERTY GET GPRM <107> ( _                          ' VTable offset = 388
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   ) AS INTEGER                                         ' __retval_out short *psSPRM
   ' =====================================================================================
   PROPERTY SET GPRM <107> ( _                          ' VTable offset = 392
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYVAL sValue AS INTEGER _                          ' __in short sValue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDTextStringType <108> ( _             ' VTable offset = 396
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   , BYVAL lStringIndex AS LONG _                       ' __in long lStringIndex
   ) AS LONG                                            ' __retval_out DVDTextStringType *pType
   ' =====================================================================================
   PROPERTY GET DVDTextString <109> ( _                 ' VTable offset = 400
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   , BYVAL lStringIndex AS LONG _                       ' __in long lStringIndex
   ) AS WSTRING                                         ' __retval_out BSTR *pstrText
   ' =====================================================================================
   PROPERTY GET DVDTextNumberOfStrings <110> ( _        ' VTable offset = 404
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   ) AS LONG                                            ' __retval_out long *plNumOfStrings
   ' =====================================================================================
   PROPERTY GET DVDTextNumberOfLanguages <111> ( _      ' VTable offset = 408
   ) AS LONG                                            ' __retval_out long *plNumOfLangs
   ' =====================================================================================
   PROPERTY GET DVDTextLanguageLCID <112> ( _           ' VTable offset = 412
     BYVAL lLangIndex AS LONG _                         ' __in long lLangIndex
   ) AS LONG                                            ' __retval_out long *lcid
   ' =====================================================================================
   METHOD RegionChange <113> ( _                        ' VTable offset = 416
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DVDAdm <114> ( _                        ' VTable offset = 420
   ) AS IDispatch                                       ' __retval_out IDispatch **pVal
   ' =====================================================================================
   METHOD DeleteBookmark <115> ( _                      ' VTable offset = 424
   )                                                    ' void
   ' =====================================================================================
   METHOD RestoreBookmark <116> ( _                     ' VTable offset = 428
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveBookmark <117> ( _                        ' VTable offset = 432
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectDefaultAudioLanguage <118> ( _          ' VTable offset = 436
     BYVAL lang AS LONG _                               ' __in long lang
   , BYVAL ext AS LONG _                                ' __in long ext
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectDefaultSubpictureLanguage <119> ( _     ' VTable offset = 440
     BYVAL lang AS LONG _                               ' __in long lang
   , BYVAL ext AS LONG _                                ' __in DVDSPExt ext
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PreferredSubpictureStream <120> ( _     ' VTable offset = 444
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DefaultMenuLanguage <121> ( _           ' VTable offset = 448
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY SET DefaultMenuLanguage <121> ( _           ' VTable offset = 452
     BYVAL lang AS LONG _                               ' __in long lang
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultSubpictureLanguage <122> ( _     ' VTable offset = 456
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY GET DefaultAudioLanguage <123> ( _          ' VTable offset = 460
   ) AS LONG                                            ' __retval_out long *lang
   ' =====================================================================================
   PROPERTY GET DefaultSubpictureLanguageExt <124> ( _  ' VTable offset = 464
   ) AS LONG                                            ' __retval_out DVDSPExt *ext
   ' =====================================================================================
   PROPERTY GET DefaultAudioLanguageExt <125> ( _       ' VTable offset = 468
   ) AS LONG                                            ' __retval_out long *ext
   ' =====================================================================================
   PROPERTY GET LanguageFromLCID <126> ( _              ' VTable offset = 472
     BYVAL lcid AS LONG _                               ' __in long lcid
   ) AS WSTRING                                         ' __retval_out BSTR *lang
   ' =====================================================================================
   PROPERTY GET KaraokeAudioPresentationMode <127> ( _  ' VTable offset = 476
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET KaraokeAudioPresentationMode <127> ( _  ' VTable offset = 480
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET KaraokeChannelContent <128> ( _         ' VTable offset = 484
     BYVAL lStream AS LONG _                            ' __in long lStream
   , BYVAL lChan AS LONG _                              ' __in long lChan
   ) AS LONG                                            ' __retval_out long *lContent
   ' =====================================================================================
   PROPERTY GET KaraokeChannelAssignment <129> ( _      ' VTable offset = 488
     BYVAL lStream AS LONG _                            ' __in long lStream
   ) AS LONG                                            ' __retval_out long *lChannelAssignment
   ' =====================================================================================
   METHOD RestorePreferredSettings <130> ( _            ' VTable offset = 492
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ButtonRect <131> ( _                    ' VTable offset = 496
     BYVAL lButton AS LONG _                            ' __in long lButton
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET DVDScreenInMouseCoordinates <132> ( _   ' VTable offset = 500
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppRect
   ' =====================================================================================
   PROPERTY SET DVDScreenInMouseCoordinates <132> ( _   ' VTable offset = 504
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidWebDVD2 Methods
   ' =====================================================================================
   PROPERTY GET Bookmark <221> ( _                      ' VTable offset = 508
     BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   ) AS DWORD                                           ' __out DWORD *pDataLength
   ' =====================================================================================
   PROPERTY SET Bookmark <221> ( _                      ' VTable offset = 512
     BYVAL pData AS BYTE PTR _                          ' __in BYTE *pData
   , BYVAL dwDataLength AS DWORD _                      ' __in DWORD dwDataLength
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidWebDVD2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidWebDVDEvent
' IID = {B4F7A674-9B83-49CB-A357-C63B871BE958}
' Inherited interface = IMSVidPlaybackEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidWebDVDEvent_INTERFACE_DEFINED)
    %IMSVidWebDVDEvent_INTERFACE_DEFINED = 1

$IID_IMSVidWebDVDEvent = GUID$("{B4F7A674-9B83-49CB-A357-C63B871BE958}")

INTERFACE IMSVidWebDVDEvent $IID_IMSVidWebDVDEvent

   INHERIT IDispatch

   ' =====================================================================================
   METHOD DVDNotify <3> ( _                             ' VTable offset = 28
     BYVAL lEventCode AS LONG _                         ' __in long lEventCode
   , BYVAL lParam1 AS VARIANT _                         ' __in VARIANT lParam1
   , BYVAL lParam2 AS VARIANT _                         ' __in VARIANT lParam2
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayForwards <4> ( _                          ' VTable offset = 32
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayBackwards <5> ( _                         ' VTable offset = 36
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ShowMenu <6> ( _                              ' VTable offset = 40
     BYVAL MenuID AS LONG _                             ' __in DVDMenuIDConstants MenuID
   , BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD Resume <7> ( _                                ' VTable offset = 44
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD SelectOrActivateButton <8> ( _                ' VTable offset = 48
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD StillOff <9> ( _                              ' VTable offset = 52
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PauseOn <10> ( _                              ' VTable offset = 56
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeCurrentAudioStream <11> ( _             ' VTable offset = 56
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeCurrentSubpictureStream <12> ( _        ' VTable offset = 60
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeCurrentAngle <13> ( _                   ' VTable offset = 64
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTimeInTitle <14> ( _                    ' VTable offset = 68
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayAtTime <15> ( _                           ' VTable offset = 72
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapterInTitle <16> ( _                   ' VTable offset = 76
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayChapter <17> ( _                          ' VTable offset = 80
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ReplayChapter <18> ( _                        ' VTable offset = 84
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayNextChapter <19> ( _                      ' VTable offset = 88
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <20> ( _                                 ' VTable offset = 92
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ReturnFromSubmenu <21> ( _                    ' VTable offset = 96
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayTitle <22> ( _                            ' VTable offset = 100
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD PlayPrevChapter <23> ( _                      ' VTable offset = 104
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeKaraokePresMode <24> ( _                ' VTable offset = 108
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================
   METHOD ChangeVideoPresMode <25> ( _                  ' VTable offset = 112
     BYVAL bEnabled AS INTEGER _                        ' __in VARIANT_BOOL bEnabled
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidWebDVDEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidWebDVDAdm
' IID = {B8BE681A-EB2C-47F0-B415-94D5452F0E05}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidWebDVDAdm_INTERFACE_DEFINED)
    %IMSVidWebDVDAdm_INTERFACE_DEFINED = 1

$IID_IMSVidWebDVDAdm = GUID$("{B8BE681A-EB2C-47F0-B415-94D5452F0E05}")

INTERFACE IMSVidWebDVDAdm $IID_IMSVidWebDVDAdm

   INHERIT IDispatch

   ' =====================================================================================
   METHOD ChangePassword <149> ( _                      ' VTable offset = 28
     BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strOld AS WSTRING _                          ' __in BSTR strOld
   , BYVAL strNew AS WSTRING _                          ' __in BSTR strNew
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveParentalLevel <150> ( _                   ' VTable offset = 32
     BYVAL level AS LONG _                              ' __in long level
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD SaveParentalCountry <151> ( _                 ' VTable offset = 36
     BYVAL country AS LONG _                            ' __in long country
   , BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD ConfirmPassword <152> ( _                     ' VTable offset = 40
     BYVAL strUserName AS WSTRING _                     ' __in BSTR strUserName
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   METHOD GetParentalLevel <153> ( _                    ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *lLevel
   ' =====================================================================================
   METHOD GetParentalCountry <154> ( _                  ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *lCountry
   ' =====================================================================================
   PROPERTY GET DefaultAudioLCID <155> ( _              ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DefaultAudioLCID <155> ( _              ' VTable offset = 56
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultSubpictureLCID <156> ( _         ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DefaultSubpictureLCID <156> ( _         ' VTable offset = 64
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DefaultMenuLCID <157> ( _               ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DefaultMenuLCID <157> ( _               ' VTable offset = 72
     BYVAL newVal AS LONG _                             ' __in long newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BookmarkOnStop <158> ( _                ' VTable offset = 76
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET BookmarkOnStop <158> ( _                ' VTable offset = 80
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidWebDVDAdm_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidOutputDevice
' IID = {37B03546-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidOutputDevice_INTERFACE_DEFINED)
    %IMSVidOutputDevice_INTERFACE_DEFINED = 1

$IID_IMSVidOutputDevice = GUID$("{37B03546-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidOutputDevice $IID_IMSVidOutputDevice

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

END INTERFACE

#ENDIF  '  /* __IMSVidOutputDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidOutputDeviceEvent
' IID = {2E6A14E2-571C-11D3-B652-00C04F79498E}
' Inherited interface = IMSVidDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidOutputDeviceEvent_INTERFACE_DEFINED)
    %IMSVidOutputDeviceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidOutputDeviceEvent = GUID$("{2E6A14E2-571C-11D3-B652-00C04F79498E}")

INTERFACE IMSVidOutputDeviceEvent $IID_IMSVidOutputDeviceEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidOutputDeviceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFeature
' IID = {37B03547-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidFeature_INTERFACE_DEFINED)
    %IMSVidFeature_INTERFACE_DEFINED = 1

$IID_IMSVidFeature = GUID$("{37B03547-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidFeature $IID_IMSVidFeature

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFeature_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFeatureEvent
' IID = {3DD2903C-E0AA-11D2-B63A-00C04F79498E}
' Inherited interface = IMSVidDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidFeatureEvent_INTERFACE_DEFINED)
    %IMSVidFeatureEvent_INTERFACE_DEFINED = 1

$IID_IMSVidFeatureEvent = GUID$("{3DD2903C-E0AA-11D2-B63A-00C04F79498E}")

INTERFACE IMSVidFeatureEvent $IID_IMSVidFeatureEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFeatureEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidEncoder
' IID = {C0020FD4-BEE7-43D9-A495-9F213117103D}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidFeature
' ########################################################################################

#IF NOT %DEF(%IMSVidEncoder_INTERFACE_DEFINED)
    %IMSVidEncoder_INTERFACE_DEFINED = 1

$IID_IMSVidEncoder = GUID$("{C0020FD4-BEE7-43D9-A495-9F213117103D}")

INTERFACE IMSVidEncoder $IID_IMSVidEncoder

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidEncoder Methods
   ' =====================================================================================
   PROPERTY GET VideoEncoderInterface <185> ( _         ' VTable offset = 64
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEncInt
   ' =====================================================================================
   PROPERTY GET AudioEncoderInterface <184> ( _         ' VTable offset = 68
   ) AS IUnknown                                        ' __retval_out IUnknown **ppEncInt
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidEncoder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMSVidClosedCaptioning
' IID = {99652EA1-C1F7-414F-BB7B-1C967DE75983}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidFeature
' ########################################################################################

#IF NOT %DEF(%IMSVidClosedCaptioning_INTERFACE_DEFINED)
    %IMSVidClosedCaptioning_INTERFACE_DEFINED = 1

$IID_IMSVidClosedCaptioning = GUID$("{99652EA1-C1F7-414F-BB7B-1C967DE75983}")

INTERFACE IMSVidClosedCaptioning $IID_IMSVidClosedCaptioning

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning Methods
   ' =====================================================================================
   PROPERTY GET Enable <38> ( _                         ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET Enable <38> ( _                         ' VTable offset = 68
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidClosedCaptioning_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidClosedCaptioning2
' IID = {E00CB864-A029-4310-9987-A873F5887D97}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidClosedCaptioning
' ########################################################################################

#IF NOT %DEF(%IMSVidClosedCaptioning2_INTERFACE_DEFINED)
    %IMSVidClosedCaptioning2_INTERFACE_DEFINED = 1

$IID_IMSVidClosedCaptioning2 = GUID$("{E00CB864-A029-4310-9987-A873F5887D97}")

INTERFACE IMSVidClosedCaptioning2 $IID_IMSVidClosedCaptioning2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning Methods
   ' =====================================================================================
   PROPERTY GET Enable <38> ( _                         ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET Enable <38> ( _                         ' VTable offset = 68
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning2 Methods
   ' =====================================================================================
   PROPERTY GET Service <186> ( _                       ' VTable offset = 72
   ) AS LONG                                            ' __retval_out MSVidCCService *On
   ' =====================================================================================
   PROPERTY SET Service <186> ( _                       ' VTable offset = 76
     BYVAL On AS LONG _                                 ' __in MSVidCCService On
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidClosedCaptioning2_INTERFACE_DEFINED__ */



' ########################################################################################
' Interface name = IMSVidClosedCaptioning3
' IID = {C8638E8A-7625-4C51-9366-2F40A9831FC0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidClosedCaptioning2
' ########################################################################################

#IF NOT %DEF(%IMSVidClosedCaptioning3_INTERFACE_DEFINED)
    %IMSVidClosedCaptioning3_INTERFACE_DEFINED = 1

$IID_IMSVidClosedCaptioning3 = GUID$("{C8638E8A-7625-4C51-9366-2F40A9831FC0}")

INTERFACE IMSVidClosedCaptioning3 $IID_IMSVidClosedCaptioning3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning Methods
   ' =====================================================================================
   PROPERTY GET Enable <38> ( _                         ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *On
   ' =====================================================================================
   PROPERTY SET Enable <38> ( _                         ' VTable offset = 68
     BYVAL On AS INTEGER _                              ' __in VARIANT_BOOL On
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning2 Methods
   ' =====================================================================================
   PROPERTY GET Service <186> ( _                       ' VTable offset = 72
   ) AS LONG                                            ' __retval_out MSVidCCService *On
   ' =====================================================================================
   PROPERTY SET Service <186> ( _                       ' VTable offset = 76
     BYVAL On AS LONG _                                 ' __in MSVidCCService On
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidClosedCaptioning3 Methods
   ' =====================================================================================
   PROPERTY GET TeleTextFilter <196> ( _                ' VTable offset = 80
   ) AS IUnknown                                        ' __retval_out IUnknown** punkTTFilter
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidClosedCaptioning3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidXDS
' IID = {11EBC158-E712-4D1F-8BB3-01ED5274C4CE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSVidFeature
' ########################################################################################

#IF NOT %DEF(%IMSVidXDS_INTERFACE_DEFINED)
    %IMSVidXDS_INTERFACE_DEFINED = 1

$IID_IMSVidXDS = GUID$("{11EBC158-E712-4D1F-8BB3-01ED5274C4CE}")

INTERFACE IMSVidXDS $IID_IMSVidXDS

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidXDS Methods
   ' =====================================================================================
   PROPERTY GET ChannelChangeInterface <197> ( _        ' VTable offset = 64
   ) AS IUnknown                                        ' __retval_out IUnknown **punkCC
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidXDS_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidXDSEvent
' IID = {6DB2317D-3B23-41EC-BA4B-701F407EAF3A}
' Inherited interface = IMSVidFeatureEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidXDSEvent_INTERFACE_DEFINED)
    %IMSVidXDSEvent_INTERFACE_DEFINED = 1

$IID_IMSVidXDSEvent = GUID$("{6DB2317D-3B23-41EC-BA4B-701F407EAF3A}")

INTERFACE IMSVidXDSEvent $IID_IMSVidXDSEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidXDSEvent Methods
   ' =====================================================================================
   METHOD RatingChange <33> ( _                         ' VTable offset = 32
     BYVAL PrevRatingSystem AS LONG _                   ' __in EnTvRat_System PrevRatingSystem
   , BYVAL PrevLevel AS LONG _                          ' __in EnTvRat_GenericLevel PrevLevel
   , BYVAL PrevAttributes AS LONG _                     ' __in BfEnTvRat_GenericAttributes PrevAttributes
   , BYVAL NewRatingSystem AS LONG _                    ' __in EnTvRat_System NewRatingSystem
   , BYVAL NewLevel AS LONG _                           ' __in EnTvRat_GenericLevel NewLevel
   , BYVAL NewAttributes AS LONG _                      ' __in BfEnTvRat_GenericAttributes NewAttributes
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidXDSEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidDataServices
' IID = {334125C1-77E5-11D3-B653-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidFeature
' ########################################################################################

#IF NOT %DEF(%IMSVidDataServices_INTERFACE_DEFINED)
    %IMSVidDataServices_INTERFACE_DEFINED = 1

$IID_IMSVidDataServices = GUID$("{334125C1-77E5-11D3-B653-00C04F79498E}")

INTERFACE IMSVidDataServices $IID_IMSVidDataServices

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidDataServices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidDataServicesEvent
' IID = {334125C2-77E5-11d3-B653-00C04F79498E}
' Inherited interface = IMSVidDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidDataServicesEvent_INTERFACE_DEFINED)
    %IMSVidDataServicesEvent_INTERFACE_DEFINED = 1

$IID_IMSVidDataServicesEvent = GUID$("{334125C2-77E5-11D3-B653-00C04F79498E}")

INTERFACE IMSVidDataServicesEvent $IID_IMSVidDataServicesEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidDataServicesEvent_INTERFACE_DEFINED__ */


' ========================================================================================
' SourceSizeList enum
' ========================================================================================

%sslFullSize       = 0
%sslClipByOverScan = %sslFullSize       + 1
%sslClipByClipRect = %sslClipByOverScan + 1

' ########################################################################################
' Interface name = IMSVidVideoRenderer
' IID = {37B03540-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidOutputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoRenderer_INTERFACE_DEFINED)
    %IMSVidVideoRenderer_INTERFACE_DEFINED = 1

$IID_IMSVidVideoRenderer = GUID$("{37B03540-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidVideoRenderer $IID_IMSVidVideoRenderer

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRenderer Methods
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass <134> ( _         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass <134> ( _         ' VTable offset = 68
     BYVAL CompositorCLSID AS WSTRING _                 ' __in BSTR CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass_ <133> ( _        ' VTable offset = 72
   ) AS GUID                                            ' __retval_out GUID *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass_ <133> ( _        ' VTable offset = 76
     BYREF IN CompositorCLSID AS GUID _                 ' __in REFCLSID CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositor_ <135> ( _             ' VTable offset = 80
   ) AS IVMRImageCompositor                             ' __retval_out IVMRImageCompositor **Compositor
   ' =====================================================================================
   PROPERTY SET CustomCompositor_ <135> ( _             ' VTable offset = 84
     BYVAL Compositor AS IVMRImageCompositor _          ' __in IVMRImageCompositor *Compositor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmap <136> ( _                   ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out IPictureDisp **MixerPictureDisp
   ' =====================================================================================
   PROPERTY GET MixerBitmap_ <137> ( _                  ' VTable offset = 92
   ) AS IVMRMixerBitmap                                 ' __retval_out IVMRMixerBitmap **MixerPicture
   ' =====================================================================================
   PROPERTY SET MixerBitmap <136> ( _                   ' VTable offset = 96
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET MixerBitmap_ <137> ( _                  ' VTable offset = 100
     BYREF IN MixerPicture AS VMRALPHABITMAP _          ' __in VMRALPHABITMAP *MixerPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapPositionRect <139> ( _       ' VTable offset = 104
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **rDest
   ' =====================================================================================
   PROPERTY SET MixerBitmapPositionRect <139> ( _       ' VTable offset = 108
     BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapOpacity <138> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out int *opacity
   ' =====================================================================================
   PROPERTY SET MixerBitmapOpacity <138> ( _            ' VTable offset = 116
     BYVAL opacity AS LONG _                            ' __in int opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetupMixerBitmap <140> ( _                    ' VTable offset = 120
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   , BYVAL Opacity AS  LONG _                           ' __in long Opacity
   , BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceSize <41> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out SourceSizeList *CurrentSize
   ' =====================================================================================
   PROPERTY SET SourceSize <41> ( _                     ' VTable offset = 128
     BYVAL NewSize AS LONG _                            ' __in SourceSizeList NewSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverScan <5> ( _                        ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plPercent
   ' =====================================================================================
   PROPERTY SET OverScan <5> ( _                        ' VTable offset = 136
     BYVAL lPercent AS LONG _                           ' __in long lPercent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvailableSourceRect <33> ( _            ' VTable offset = 140
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET MaxVidRect <159> ( _                    ' VTable offset = 144
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET MinVidRect <160> ( _                    ' VTable offset = 148
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET ClippedSourceRect <32> ( _              ' VTable offset = 152
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY SET ClippedSourceRect <32> ( _              ' VTable offset = 156
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsingOverlay <141> ( _                  ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *UseOverlayVal
   ' =====================================================================================
   PROPERTY SET UsingOverlay <141> ( _                  ' VTable offset = 164
     BYVAL UseOverlayVal AS INTEGER _                   ' __in VARIANT_BOOL UseOverlayVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Capture <161> ( _                             ' VTable offset = 168
   ) AS IDispatch                                       ' __retval_out IPictureDisp **currentImage
   ' =====================================================================================
   PROPERTY GET FramesPerSecond <80> ( _                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DecimateInput <162> ( _                 ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pDeci
   ' =====================================================================================
   PROPERTY SET DecimateInput <162> ( _                 ' VTable offset = 180
     BYVAL pDeci AS INTEGER _                           ' __in VARIANT_BOOL pDeci
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoRenderer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVideoRendererEvent
' IID = {37B03545-A4C8-11D2-B634-00C04F79498E}
' Inherited interface = IMSVidOutputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoRendererEvent_INTERFACE_DEFINED)
    %IMSVidVideoRendererEvent_INTERFACE_DEFINED = 1

$IID_IMSVidVideoRendererEvent = GUID$("{37B03545-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidVideoRendererEvent $IID_IMSVidVideoRendererEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRendererEvent Methods
   ' =====================================================================================
   METHOD OverlayUnavailable <26> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoRendererEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidGenericSink
' IID = {6C29B41D-455B-4C33-963A-0D28E5E555EA}
' Attributes = 4368 [&H1110] [Hidden] [Oleautomation] [Dispatchable]
' Inherited interface = IMSVidOutputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidGenericSink_INTERFACE_DEFINED)
    %IMSVidGenericSink_INTERFACE_DEFINED = 1

$IID_IMSVidGenericSink = GUID$("{6C29B41D-455B-4C33-963A-0D28E5E555EA}")

INTERFACE IMSVidGenericSink $IID_IMSVidGenericSink

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGenericSink Methods
   ' =====================================================================================
   METHOD SetSinkFilter <191> ( _                       ' VTable offset = 64
     BYVAL bstrCLSID AS WSTRING _                       ' __in BSTR bstrCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SinkStreams <192> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __out MSVidSinkStreams *pStreams/
   ' =====================================================================================
   PROPERTY SET SinkStreams <192> ( _                   ' VTable offset = 72
     BYVAL Streams AS LONG _                            ' __in MSVidSinkStreams Streams
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidGenericSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidGenericSink2
' IID = {6B5A28F3-47F1-4092-B168-60CABEC08F1C}
' Inherited interface = IMSVidGenericSink
' ########################################################################################

#IF NOT %DEF(%IMSVidGenericSink2_INTERFACE_DEFINED)
    %IMSVidGenericSink2_INTERFACE_DEFINED = 1

$IID_IMSVidGenericSink2 = GUID$("{6B5A28F3-47F1-4092-B168-60CABEC08F1C}")

INTERFACE IMSVidGenericSink2 $IID_IMSVidGenericSink2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGenericSink Methods
   ' =====================================================================================
   METHOD SetSinkFilter <191> ( _                       ' VTable offset = 64
     BYVAL bstrCLSID AS WSTRING _                       ' __in BSTR bstrCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SinkStreams <192> ( _                   ' VTable offset = 68
   ) AS LONG                                            ' __out MSVidSinkStreams *pStreams
   ' =====================================================================================
   PROPERTY SET SinkStreams <192> ( _                   ' VTable offset = 72
     BYVAL Streams AS LONG _                            ' __in MSVidSinkStreams Streams
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidGenericSink2 Methods
   ' =====================================================================================
   METHOD AddFilter <199> ( _                           ' VTable offset = 76
     BYVAL bstrName AS WSTRING _                        ' __in BSTR bstrName
   )                                                    ' void
   ' =====================================================================================
   METHOD ResetFilterList <216> ( _                     ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidGenericSink2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferRecordingControl
' IID = {160621AA-BBBC-4326-A824-C395AEBC6E74}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED)
    %IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferRecordingControl = GUID$("{160621AA-BBBC-4326-A824-C395AEBC6E74}")

INTERFACE IMSVidStreamBufferRecordingControl $IID_IMSVidStreamBufferRecordingControl

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET startTime <172> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *rtStart
   ' =====================================================================================
   PROPERTY SET startTime <172> ( _                     ' VTable offset = 32
     BYVAL rtStart AS LONG _                            ' __in long rtStart
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET StopTime <173> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *rtStop
   ' =====================================================================================
   PROPERTY SET StopTime <173> ( _                      ' VTable offset = 40
     BYVAL rtStop AS LONG _                             ' __in long rtStop
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecordingStopped <174> ( _              ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *phResult
   ' =====================================================================================
   PROPERTY GET RecordingStarted <175> ( _              ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *phResult
   ' =====================================================================================
   PROPERTY GET RecordingType <177> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out RecordingType *dwType
   ' =====================================================================================
   PROPERTY GET RecordingAttribute <179> ( _            ' VTable offset = 56
   ) AS IUnknown                                        ' __retval_out IUnknown **pRecordingAttribute
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferRecordingControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSink
' IID = {159DBB45-CD1B-4DAB-83EA-5CB1F4F21D07}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidOutputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSink_INTERFACE_DEFINED)
    %IMSVidStreamBufferSink_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSink = GUID$("{159DBB45-CD1B-4DAB-83EA-5CB1F4F21D07}")

INTERFACE IMSVidStreamBufferSink $IID_IMSVidStreamBufferSink

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink Methods
   ' =====================================================================================
   PROPERTY GET ContentRecorder <170> ( _               ' VTable offset = 64
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET ReferenceRecorder <171> ( _             ' VTable offset = 68
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET SinkName <168> ( _                      ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET SinkName <168> ( _                      ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD NameSetLock <176> ( _                         ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SBESink <181> ( _                       ' VTable offset = 84
   ) AS IUnknown                                        ' __retval_out IUnknown **sbeConfig
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSink2
' IID = {2CA9FC63-C131-4E5A-955A-544A47C67146}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidStreamBufferSink
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSink2_INTERFACE_DEFINED)
    %IMSVidStreamBufferSink2_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSink2 = GUID$("{2CA9FC63-C131-4E5A-955A-544A47C67146}")

INTERFACE IMSVidStreamBufferSink2 $IID_IMSVidStreamBufferSink2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink Methods
   ' =====================================================================================
   PROPERTY GET ContentRecorder <170> ( _               ' VTable offset = 64
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET ReferenceRecorder <171> ( _             ' VTable offset = 68
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET SinkName <168> ( _                      ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET SinkName <168> ( _                      ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD NameSetLock <176> ( _                         ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SBESink <181> ( _                       ' VTable offset = 84
   ) AS IUnknown                                        ' __retval_out IUnknown **sbeConfig
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink2 Methods
   ' =====================================================================================
   METHOD UnlockProfile <198> ( _                       ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSink2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSink3
' IID = {4F8721D7-7D59-4D8B-99F5-A77775586BD5}
' Inherited interface = IMSVidStreamBufferSink2
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSink3_INTERFACE_DEFINED)
    %IMSVidStreamBufferSink3_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSink3 = GUID$("{4F8721D7-7D59-4D8B-99F5-A77775586BD5}")

INTERFACE IMSVidStreamBufferSink3 $IID_IMSVidStreamBufferSink3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink Methods
   ' =====================================================================================
   PROPERTY GET ContentRecorder <170> ( _               ' VTable offset = 64
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET ReferenceRecorder <171> ( _             ' VTable offset = 68
     BYVAL pszFilename AS WSTRING _                     ' __in BSTR pszFilename
   ) AS IMSVidStreamBufferRecordingControl              ' __retval_out IMSVidStreamBufferRecordingControl **pRecordingIUnknown
   ' =====================================================================================
   PROPERTY GET SinkName <168> ( _                      ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pName
   ' =====================================================================================
   PROPERTY SET SinkName <168> ( _                      ' VTable offset = 76
     BYVAL Name AS WSTRING _                            ' __in BSTR Name
   )                                                    ' void
   ' =====================================================================================
   METHOD NameSetLock <176> ( _                         ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SBESink <181> ( _                       ' VTable offset = 84
   ) AS IUnknown                                        ' __retval_out IUnknown **sbeConfig
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink2 Methods
   ' =====================================================================================
   METHOD UnlockProfile <198> ( _                       ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSink3 Methods
   ' =====================================================================================
   METHOD SetMinSeek <200> ( _                          ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *pdwMin
   ' =====================================================================================
   PROPERTY GET AudioCounter <202> ( _                  ' VTable offset = 96
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET VideoCounter <203> ( _                  ' VTable offset = 100
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET CCCounter <204> ( _                     ' VTable offset = 104
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET WSTCounter <205> ( _                    ' VTable offset = 108
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY SET AudioAnalysisFilter <210> ( _           ' VTable offset = 112
     BYVAL szCLSID AS WSTRING _                         ' __in BSTR szCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioAnalysisFilter <210> ( _           ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pszCLSID
   ' =====================================================================================
   PROPERTY SET AudioAnalysisFilter_ <213> ( _          ' VTable offset = 120
     BYVAL guid AS GUID _                               ' __in GUID guid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioAnalysisFilter_ <213> ( _          ' VTable offset = 124
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   PROPERTY SET VideoAnalysisFilter <211> (  _          ' VTable offset = 128
     BYVAL szCLSID AS WSTRING _                         ' __in BSTR szCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VideoAnalysisFilter <211> ( _           ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pszCLSID
   ' =====================================================================================
   PROPERTY SET VideoAnalysisFilter_ <214> (  _         ' VTable offset = 136
     BYVAL guid AS WSTRING _                            ' __in BSTR guid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET VideoAnalysisFilter_ <214> ( _          ' VTable offset = 140
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   PROPERTY SET DataAnalysisFilter <212> ( _            ' VTable offset = 144
     BYVAL szCLSID AS WSTRING _                         ' __in BSTR szCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataAnalysisFilter <212> ( _            ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pszCLSID
   ' =====================================================================================
   PROPERTY SET DataAnalysisFilter_ <215> (  _          ' VTable offset = 152
     BYVAL guid AS WSTRING _                            ' __in BSTR guid
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DataAnalysisFilter_ <215> ( _           ' VTable offset = 156
   ) AS GUID                                            ' __retval_out GUID *pGuid
   ' =====================================================================================
   PROPERTY GET LicenseErrorCode <45> ( _               ' VTable offset = 160
   ) AS LONG                                            ' __retval_out HRESULT *hres
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSink3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSinkEvent
' IID = {F798A36B-B05B-4BBE-9703-EAEA7D61CD51}
' Inherited interface = IMSVidOutputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED)
    %IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSinkEvent = GUID$("{F798A36B-B05B-4BBE-9703-EAEA7D61CD51}")

INTERFACE IMSVidStreamBufferSinkEvent $IID_IMSVidStreamBufferSinkEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <27> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <28> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteFailure <34> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSinkEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSinkEvent2
' IID = {3D7A5166-72D7-484B-A06F-286187B80CA1}
' Inherited interface = IMSVidStreamBufferSinkEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED)
    %IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSinkEvent2 = GUID$("{3D7A5166-72D7-484B-A06F-286187B80CA1}")

INTERFACE IMSVidStreamBufferSinkEvent2 $IID_IMSVidStreamBufferSinkEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <27> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <28> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteFailure <34> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent2 Methods
   ' =====================================================================================
   METHOD EncryptionOn <39> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD EncryptionOff <40> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSinkEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSinkEvent3
' IID = {735AD8D5-C259-48E9-81E7-D27953665B23}
' Inherited interface = IMSVidStreamBufferSinkEvent2
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED)
    %IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSinkEvent3 = GUID$("{735AD8D5-C259-48E9-81E7-D27953665B23}")

INTERFACE IMSVidStreamBufferSinkEvent3 $IID_IMSVidStreamBufferSinkEvent3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <27> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <28> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteFailure <34> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent2 Methods
   ' =====================================================================================
   METHOD EncryptionOn <39> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD EncryptionOff <40> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent3 Methods
   ' =====================================================================================
   METHOD LicenseChange <42> ( _                        ' VTable offset = 52
     BYVAL dwProt AS LONG _                             ' __in long dwProt
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSinkEvent3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSinkEvent4
' IID = {1B01DCB0-DAF0-412C-A5D1-590C7F62E2B8}
' Inherited interface = IMSVidStreamBufferSinkEvent3
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSinkEvent4_INTERFACE_DEFINED)
    %IMSVidStreamBufferSinkEvent4_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSinkEvent4 = GUID$("{1B01DCB0-DAF0-412C-A5D1-590C7F62E2B8}")

INTERFACE IMSVidStreamBufferSinkEvent4 $IID_IMSVidStreamBufferSinkEvent4

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <27> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <28> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD WriteFailure <34> ( _                         ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent2 Methods
   ' =====================================================================================
   METHOD EncryptionOn <39> ( _                         ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD EncryptionOff <40> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent3 Methods
   ' =====================================================================================
   METHOD LicenseChange <42> ( _                        ' VTable offset = 52
     BYVAL dwProt AS LONG _                             ' __in long dwProt
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSinkEvent4 Methods
   ' =====================================================================================
   METHOD WriteFailureClear <57> ( _                    ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSinkEvent4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSource
' IID = {EB0C8CF9-6950-4772-87B1-47D11CF3A02F}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidFilePlayback
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSource_INTERFACE_DEFINED)
    %IMSVidStreamBufferSource_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSource = GUID$("{EB0C8CF9-6950-4772-87B1-47D11CF3A02F}")

INTERFACE IMSVidStreamBufferSource $IID_IMSVidStreamBufferSource

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidInputDevice Methods
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidFilePlayback Methods
   ' =====================================================================================
   PROPERTY GET FileName <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *FileName
   ' =====================================================================================
   PROPERTY SET FileName <17> ( _                       ' VTable offset = 132
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSource Methods
   ' =====================================================================================
   PROPERTY GET Start <178> ( _                         ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *lStart
   ' =====================================================================================
   PROPERTY GET RecordingAttribute <180> ( _            ' VTable offset = 140
   ) AS IUnknown                                        ' __retval_out IUnknown **pRecordingAttribute
   ' =====================================================================================
   METHOD CurrentRatings <182> ( _                      ' VTable offset = 144
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF pBfEnAttr AS LONG _                          ' __out LONG *pBfEnAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD MaxRatingsLevel <183> ( _                     ' VTable offset = 148
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enRating AS LONG _                           ' __in EnTvRat_GenericLevel enRating
   , BYVAL lbfEnAttr AS LONG _                          ' __in LONG lbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BlockUnrated <187> ( _                  ' VTable offset = 152
     BYVAL bBlock AS INTEGER _                          ' __in VARIANT_BOOL bBlock
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET UnratedDelay <188> ( _                  ' VTable offset = 156
     BYVAL dwDelay AS LONG _                            ' __in long dwDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SBESource <190> ( _                     ' VTable offset = 160
   ) AS IUnknown                                        ' __retval_out IUnknown **sbeFilter
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSource2
' IID = {E4BA9059-B1CE-40D8-B9A0-D4EA4A9989D3}
' Inherited interface = IMSVidStreamBufferSource
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSource2_INTERFACE_DEFINED)
    %IMSVidStreamBufferSource2_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSource2 = GUID$("{E4BA9059-B1CE-40D8-B9A0-D4EA4A9989D3}")

INTERFACE IMSVidStreamBufferSource2 $IID_IMSVidStreamBufferSource2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidInputDevice Methods
   ' =====================================================================================
   METHOD IsViewable <21> ( _                           ' VTable offset = 64
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfViewable
   ' =====================================================================================
   METHOD View <22> ( _                                 ' VTable offset = 68
     BYREF v AS VARIANT _                               ' __in VARIANT *v
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidPlayback Methods
   ' =====================================================================================
   PROPERTY GET EnableResetOnStop <96> ( _              ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET EnableResetOnStop <96> ( _              ' VTable offset = 76
     BYVAL newVal AS INTEGER _                          ' __in VARIANT_BOOL newVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Run <35> ( _                                  ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <36> ( _                                ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD Stop <37> ( _                                 ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CanStep <40> ( _                        ' VTable offset = 92
     BYVAL fBackwards AS INTEGER _                      ' __in VARIANT_BOOL fBackwards
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfCan
   ' =====================================================================================
   METHOD Step <39> ( _                                 ' VTable offset = 96
     BYVAL lStep AS LONG _                              '  __in long lStep
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET Rate <145> ( _                          ' VTable offset = 100
     BYVAL plRate AS DOUBLE _                           ' __in double plRate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Rate <145> ( _                          ' VTable offset = 104
   ) AS DOUBLE                                          ' __retval_out double *plRate
   ' =====================================================================================
   PROPERTY SET CurrentPosition <146> ( _               ' VTable offset = 108
     BYVAL lPosition AS LONG _                          ' __in long lPosition
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CurrentPosition <146> ( _               ' VTable offset = 112
   ) AS LONG                                            ' __retval_out long *lPosition
   ' =====================================================================================
   PROPERTY SET PositionMode <147> ( _                  ' VTable offset = 116
     BYVAL lPositionMode AS LONG _                      ' __in PositionModeList lPositionMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PositionMode <147> ( _                  ' VTable offset = 120
   ) AS LONG                                            ' __retval_out PositionModeList *lPositionMode
   ' =====================================================================================
   PROPERTY GET Length <148> ( _                        ' VTable offset = 124
   ) AS LONG                                            ' __retval_out long *lLength
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidFilePlayback Methods
   ' =====================================================================================
   PROPERTY GET FileName <17> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *FileName
   ' =====================================================================================
   PROPERTY SET FileName <17> ( _                       ' VTable offset = 132
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSource Methods
   ' =====================================================================================
   PROPERTY GET Start <178> ( _                         ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *lStart
   ' =====================================================================================
   PROPERTY GET RecordingAttribute <180> ( _            ' VTable offset = 140
   ) AS IUnknown                                        ' __retval_out IUnknown **pRecordingAttribute
   ' =====================================================================================
   METHOD CurrentRatings <182> ( _                      ' VTable offset = 144
     BYREF pEnSystem AS LONG _                          ' __out EnTvRat_System *pEnSystem
   , BYREF pEnRating AS LONG _                          ' __out EnTvRat_GenericLevel *pEnRating
   , BYREF pBfEnAttr AS LONG _                          ' __out LONG *pBfEnAttr
   )                                                    ' void
   ' =====================================================================================
   METHOD MaxRatingsLevel <183> ( _                     ' VTable offset = 148
     BYVAL enSystem AS LONG _                           ' __in EnTvRat_System enSystem
   , BYVAL enRating AS LONG _                           ' __in EnTvRat_GenericLevel enRating
   , BYVAL lbfEnAttr AS LONG _                          ' __in LONG lbfEnAttr
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET BlockUnrated <187> ( _                  ' VTable offset = 152
     BYVAL bBlock AS INTEGER _                          ' __in VARIANT_BOOL bBlock
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET UnratedDelay <188> ( _                  ' VTable offset = 156
     BYVAL dwDelay AS LONG _                            ' __in long dwDelay
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SBESource <190> ( _                     ' VTable offset = 160
   ) AS IUnknown                                        ' __retval_out IUnknown **sbeFilter
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSource2 Methods
   ' =====================================================================================
   PROPERTY SET RateEx <201> ( _                        ' VTable offset = 164
     BYVAL dwRate AS DOUBLE _                           ' __in double dwRate
   , BYVAL dwFramesPerSecond AS DWORD _                 ' __in DWORD dwFramesPerSecond
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AudioCounter <206> ( _                  ' VTable offset = 164
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET VideoCounter <207> ( _                  ' VTable offset = 168
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET CCCounter <208> ( _                     ' VTable offset = 172
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================
   PROPERTY GET WSTCounter <209> ( _                    ' VTable offset = 176
   ) AS IUnknown                                        ' __retval_out IUnknown **ppUnk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSource2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSourceEvent
' IID = {50CE8A7D-9C28-4DA8-9042-CDFA7116F979}
' Inherited interface = IMSVidFilePlaybackEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED)
    %IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSourceEvent = GUID$("{50CE8A7D-9C28-4DA8-9042-CDFA7116F979}")

INTERFACE IMSVidStreamBufferSourceEvent $IID_IMSVidStreamBufferSourceEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidFilePlaybackEvent Methods
   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL lpd AS IMSVidPlayback _                     ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <29> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <30> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsBlocked <31> ( _                       ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsUnblocked <32> ( _                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsChanged <33> ( _                       ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD TimeHole <35> ( _                             ' VTable offset = 52
     BYVAL StreamOffsetMS AS LONG _                     ' __in long StreamOffsetMS
   , BYVAL SizeMS AS LONG _                             ' __in long SizeMS
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleDataRead <36> ( _                        ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentBecomingStale <37> ( _                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleFileDeleted <38> ( _                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSourceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSourceEvent2
' IID = {7AEF50CE-8E22-4BA8-BC06-A92A458B4EF2}
' Inherited interface = IMSVidStreamBufferSourceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED)
    %IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSourceEvent2 = GUID$("{7AEF50CE-8E22-4BA8-BC06-A92A458B4EF2}")

INTERFACE IMSVidStreamBufferSourceEvent2 $IID_IMSVidStreamBufferSourceEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidFilePlaybackEvent Methods
   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL IMSVidPlayback _                            ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <29> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <30> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsBlocked <31> ( _                       ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsUnblocked <32> ( _                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsChanged <33> ( _                       ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD TimeHole <35> ( _                             ' VTable offset = 52
     BYVAL StreamOffsetMS AS LONG _                     ' __in long StreamOffsetMS
   , BYVAL SizeMS AS LONG _                             ' __in long SizeMS
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleDataRead <36> ( _                        ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentBecomingStale <37> ( _                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleFileDeleted <38> ( _                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent2 Methods
   ' =====================================================================================
   METHOD RateChange <41> ( _                           ' VTable offset = 68
     BYVAL qwNewRate AS DOUBLE _                        ' __in double qwNewRate
   , BYVAL qwOldRate AS DOUBLE _                        ' __in double qwOldRate
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSourceEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferSourceEvent3
' IID = {CEABD6AB-9B90-4570-ADF1-3CE76E00A763}
' Inherited interface = IMSVidStreamBufferSourceEvent2
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED)
    %IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferSourceEvent3 = GUID$("{CEABD6AB-9B90-4570-ADF1-3CE76E00A763}")

INTERFACE IMSVidStreamBufferSourceEvent3 $IID_IMSVidStreamBufferSourceEvent3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidFilePlaybackEvent Methods
   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL IMSVidPlayback _                            ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent Methods
   ' =====================================================================================
   METHOD CertificateFailure <29> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD CertificateSuccess <30> ( _                   ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsBlocked <31> ( _                       ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsUnblocked <32> ( _                     ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD RatingsChanged <33> ( _                       ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD TimeHole <35> ( _                             ' VTable offset = 52
     BYVAL StreamOffsetMS AS LONG _                     ' __in long StreamOffsetMS
   , BYVAL SizeMS AS LONG _                             ' __in long SizeMS
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleDataRead <36> ( _                        ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentBecomingStale <37> ( _                 ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleFileDeleted <38> ( _                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent2 Methods
   ' =====================================================================================
   METHOD RateChange <41> ( _                           ' VTable offset = 68
     BYVAL qwNewRate AS DOUBLE _                        ' __in double qwNewRate
   , BYVAL qwOldRate AS DOUBLE _                        ' __in double qwOldRate
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferSourceEvent3 Methods
   ' =====================================================================================
   METHOD BroadcastEvent ( _                            ' VTable offset = 72
     BYVAL Guid AS WSTRING _                            ' __in BSTR Guid
   )                                                    ' void
   ' =====================================================================================
   METHOD BroadcastEventEx ( _                          ' VTable offset = 76
     BYVAL Guid AS WSTRING _                            ' __in BSTR Guid
   , BYVAL Param1 AS DWORD _                            ' __in ULONG Param1
   , BYVAL Param2 AS DWORD _                            ' __in ULONG Param2
   , BYVAL Param3 AS DWORD _                            ' __in ULONG Param3
   , BYVAL Param4 AS DWORD _                            ' __in ULONG Param4
   )                                                    ' void
   ' =====================================================================================
   METHOD COPPBlocked ( _                               ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD COPPUnblocked ( _                             ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentPrimarilyAudio ( _                     ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferSourceEvent3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidStreamBufferV2SourceEvent
' IID = {49C771F9-41B2-4CF7-9F9A-A313A8F6027E}
' Inherited interface = IMSVidFilePlaybackEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidStreamBufferV2SourceEvent_INTERFACE_DEFINED)
    %IMSVidStreamBufferV2SourceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidStreamBufferV2SourceEvent = GUID$("{49C771F9-41B2-4CF7-9F9A-A313A8F6027E}")

INTERFACE IMSVidStreamBufferV2SourceEvent $IID_IMSVidStreamBufferV2SourceEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidFilePlaybackEvent Methods
   ' =====================================================================================
   METHOD EndOfMedia <2> ( _                            ' VTable offset = 28
      BYVAL lpd AS IMSVidPlayback _                     ' __in IMSVidPlayback *lpd
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidStreamBufferV2SourceEvent Methods
   ' =====================================================================================
   METHOD RatingsChanged <33> ( _                       ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD TimeHole <35> ( _                             ' VTable offset = 36
     BYVAL StreamOffsetMS AS LONG _                     ' __in long StreamOffsetMS
   , BYVAL SizeMS AS LONG _                             ' __in long SizeMS
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleDataRead <36> ( _                        ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentBecomingStale <37> ( _                 ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD StaleFileDeleted <38> ( _                     ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD RateChange <41> ( _                           ' VTable offset = 52
     BYVAL qwNewRate AS DOUBLE _                        ' __in double qwNewRate
   , BYVAL qwOldRate AS DOUBLE _                        ' __in double qwOldRate
   )                                                    ' void
   ' =====================================================================================
   METHOD BroadcastEvent <46> ( _                       ' VTable offset = 56
     BYVAL Guid AS WSTRING _                            ' __in BSTR Guid
   )                                                    ' void
   ' =====================================================================================
   METHOD BroadcastEventEx <47> ( _                     ' VTable offset = 60
     BYVAL Guid AS WSTRING _                            ' __in BSTR Guid
   , BYVAL Param1 AS DWORD _                            ' __in ULONG Param1
   , BYVAL Param2 AS DWORD _                            ' __in ULONG Param2
   , BYVAL Param3 AS DWORD _                            ' __in ULONG Param3
   , BYVAL Param4 AS DWORD _                            ' __in ULONG Param4
   )                                                    ' void
   ' =====================================================================================
   METHOD ContentPrimarilyAudio <48> ( _                ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidStreamBufferV2SourceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVideoRenderer2
' IID = {6BDD5C1E-2810-4159-94BC-05511AE8549B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidVideoRenderer
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoRenderer2_INTERFACE_DEFINED)
    %IMSVidVideoRenderer2_INTERFACE_DEFINED = 1

$IID_IMSVidVideoRenderer2 = GUID$("{6BDD5C1E-2810-4159-94BC-05511AE8549B}")

INTERFACE IMSVidVideoRenderer2 $IID_IMSVidVideoRenderer2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRenderer Methods
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass <134> ( _         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass <134> ( _         ' VTable offset = 68
     BYVAL CompositorCLSID AS WSTRING _                 ' __in BSTR CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass_ <133> ( _        ' VTable offset = 72
   ) AS GUID                                            ' __retval_out GUID *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass_ <133> ( _        ' VTable offset = 76
     BYREF IN CompositorCLSID AS GUID _                 ' __in REFCLSID CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositor_ <135> ( _             ' VTable offset = 80
   ) AS IVMRImageCompositor                             ' __retval_out IVMRImageCompositor **Compositor
   ' =====================================================================================
   PROPERTY SET CustomCompositor_ <135> ( _             ' VTable offset = 84
     BYVAL Compositor AS IVMRImageCompositor _          ' __in IVMRImageCompositor *Compositor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmap <136> ( _                   ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out IPictureDisp **MixerPictureDisp
   ' =====================================================================================
   PROPERTY GET MixerBitmap_ <137> ( _                  ' VTable offset = 92
   ) AS IVMRMixerBitmap                                 ' __retval_out IVMRMixerBitmap **MixerPicture
   ' =====================================================================================
   PROPERTY SET MixerBitmap <136> ( _                   ' VTable offset = 96
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET MixerBitmap_ <137> ( _                  ' VTable offset = 100
     BYREF IN MixerPicture AS VMRALPHABITMAP _          ' __in VMRALPHABITMAP *MixerPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapPositionRect <139> ( _       ' VTable offset = 104
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **rDest
   ' =====================================================================================
   PROPERTY SET MixerBitmapPositionRect <139> ( _       ' VTable offset = 108
     BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapOpacity <138> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out int *opacity
   ' =====================================================================================
   PROPERTY SET MixerBitmapOpacity <138> ( _            ' VTable offset = 116
     BYVAL opacity AS LONG _                            ' __in int opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetupMixerBitmap <140> ( _                    ' VTable offset = 120
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   , BYVAL Opacity AS  LONG _                           ' __in long Opacity
   , BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceSize <41> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out SourceSizeList *CurrentSize
   ' =====================================================================================
   PROPERTY SET SourceSize <41> ( _                     ' VTable offset = 128
     BYVAL NewSize AS LONG _                            ' __in SourceSizeList NewSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverScan <5> ( _                        ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plPercent
   ' =====================================================================================
   PROPERTY SET OverScan <5> ( _                        ' VTable offset = 136
     BYVAL lPercent AS LONG _                           ' __in long lPercent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvailableSourceRect <33> ( _            ' VTable offset = 140
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET MaxVidRect <159> ( _                    ' VTable offset = 144
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET MinVidRect <160> ( _                    ' VTable offset = 148
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET ClippedSourceRect <32> ( _              ' VTable offset = 152
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY SET ClippedSourceRect <32> ( _              ' VTable offset = 156
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsingOverlay <141> ( _                  ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *UseOverlayVal
   ' =====================================================================================
   PROPERTY SET UsingOverlay <141> ( _                  ' VTable offset = 164
     BYVAL UseOverlayVal AS INTEGER _                   ' __in VARIANT_BOOL UseOverlayVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Capture <161> ( _                             ' VTable offset = 168
   ) AS IDispatch                                       ' __retval_out IPictureDisp **currentImage
   ' =====================================================================================
   PROPERTY GET FramesPerSecond <80> ( _                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DecimateInput <162> ( _                 ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pDeci
   ' =====================================================================================
   PROPERTY SET DecimateInput <162> ( _                 ' VTable offset = 180
     BYVAL pDeci AS INTEGER _                           ' __in VARIANT_BOOL pDeci
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRenderer2 Methods
   ' =====================================================================================
   PROPERTY GET Allocator <163> ( _                     ' VTable offset = 184
   ) AS IUnknown                                        ' __retval_out IUnknown **AllocPresent
   ' =====================================================================================
   PROPERTY GET Allocator_ <164> ( _                    ' VTable offset = 188
   ) AS IVMRSurfaceAllocator                            ' __retval_out IVMRSurfaceAllocator **AllocPresent
   ' =====================================================================================
   PROPERTY GET Allocator_ID <165> ( _                  ' VTable offset = 192
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   METHOD SetAllocator <166> ( _                        ' VTable offset = 196
     BYVAL AllocPresent AS IUnknown _                   ' __in IUnknown *AllocPresent
   , OPTIONAL BYVAL LONG _                              ' __opt_in long ID = -1
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAllocator_ <167> ( _                       ' VTable offset = 200
     BYVAL AllocPresent AS IVMRSurfaceAllocator _       ' __in IVMRSurfaceAllocator *AllocPresent
   , OPTIONAL BYVAL ID AS LONG _                        ' __opt_in long ID = -1
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SuppressEffects <189> ( _               ' VTable offset = 204
     BYVAL bSuppress AS INTEGER _                       ' __in VARIANT_BOOL bSuppress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressEffects <189> ( _               ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bSuppress
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoRenderer2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVideoRendererEvent2
' IID = {7145ED66-4730-4FDB-8A53-FDE7508D3E5E}
' Inherited interface = IMSVidOutputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoRendererEvent2_INTERFACE_DEFINED)
    %IMSVidVideoRendererEvent2_INTERFACE_DEFINED = 1

$IID_IMSVidVideoRendererEvent2 = GUID$("{7145ED66-4730-4FDB-8A53-FDE7508D3E5E}")

INTERFACE IMSVidVideoRendererEvent2 $IID_IMSVidVideoRendererEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRendererEvent2 Methods
   ' =====================================================================================
   METHOD OverlayUnavailable <26> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoRendererEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVMR9
' IID = {D58B0015-EBEF-44BB-BBDD-3F3699D76EA1}
' Inherited interface = IMSVidVideoRenderer
' ########################################################################################

#IF NOT %DEF(%IMSVidVMR9_INTERFACE_DEFINED)
    %IMSVidVMR9_INTERFACE_DEFINED = 1

$IID_IMSVidVMR9 = GUID$("{D58B0015-EBEF-44BB-BBDD-3F3699D76EA1}")

INTERFACE IMSVidVMR9 $IID_IMSVidVMR9

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRenderer Methods
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass <134> ( _         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass <134> ( _         ' VTable offset = 68
     BYVAL CompositorCLSID AS WSTRING _                 ' __in BSTR CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass_ <133> ( _        ' VTable offset = 72
   ) AS GUID                                            ' __retval_out GUID *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass_ <133> ( _        ' VTable offset = 76
     BYREF IN CompositorCLSID AS GUID _                 ' __in REFCLSID CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositor_ <135> ( _             ' VTable offset = 80
   ) AS IVMRImageCompositor                             ' __retval_out IVMRImageCompositor **Compositor
   ' =====================================================================================
   PROPERTY SET CustomCompositor_ <135> ( _             ' VTable offset = 84
     BYVAL Compositor AS IVMRImageCompositor _          ' __in IVMRImageCompositor *Compositor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmap <136> ( _                   ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out IPictureDisp **MixerPictureDisp
   ' =====================================================================================
   PROPERTY GET MixerBitmap_ <137> ( _                  ' VTable offset = 92
   ) AS IVMRMixerBitmap                                 ' __retval_out IVMRMixerBitmap **MixerPicture
   ' =====================================================================================
   PROPERTY SET MixerBitmap <136> ( _                   ' VTable offset = 96
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET MixerBitmap_ <137> ( _                  ' VTable offset = 100
     BYREF IN MixerPicture AS VMRALPHABITMAP _          ' __in VMRALPHABITMAP *MixerPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapPositionRect <139> ( _       ' VTable offset = 104
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **rDest
   ' =====================================================================================
   PROPERTY SET MixerBitmapPositionRect <139> ( _       ' VTable offset = 108
     BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapOpacity <138> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out int *opacity
   ' =====================================================================================
   PROPERTY SET MixerBitmapOpacity <138> ( _            ' VTable offset = 116
     BYVAL opacity AS LONG _                            ' __in int opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetupMixerBitmap <140> ( _                    ' VTable offset = 120
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   , BYVAL Opacity AS  LONG _                           ' __in long Opacity
   , BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceSize <41> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out SourceSizeList *CurrentSize
   ' =====================================================================================
   PROPERTY SET SourceSize <41> ( _                     ' VTable offset = 128
     BYVAL NewSize AS LONG _                            ' __in SourceSizeList NewSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverScan <5> ( _                        ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plPercent
   ' =====================================================================================
   PROPERTY SET OverScan <5> ( _                        ' VTable offset = 136
     BYVAL lPercent AS LONG _                           ' __in long lPercent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvailableSourceRect <33> ( _            ' VTable offset = 140
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET MaxVidRect <159> ( _                    ' VTable offset = 144
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET MinVidRect <160> ( _                    ' VTable offset = 148
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET ClippedSourceRect <32> ( _              ' VTable offset = 152
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY SET ClippedSourceRect <32> ( _              ' VTable offset = 156
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsingOverlay <141> ( _                  ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *UseOverlayVal
   ' =====================================================================================
   PROPERTY SET UsingOverlay <141> ( _                  ' VTable offset = 164
     BYVAL UseOverlayVal AS INTEGER _                   ' __in VARIANT_BOOL UseOverlayVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Capture <161> ( _                             ' VTable offset = 168
   ) AS IDispatch                                       ' __retval_out IPictureDisp **currentImage
   ' =====================================================================================
   PROPERTY GET FramesPerSecond <80> ( _                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DecimateInput <162> ( _                 ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pDeci
   ' =====================================================================================
   PROPERTY SET DecimateInput <162> ( _                 ' VTable offset = 180
     BYVAL pDeci AS INTEGER _                           ' __in VARIANT_BOOL pDeci
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVMR9 Methods
   ' =====================================================================================
   PROPERTY GET Allocator_ID <165> ( _                  ' VTable offset = 184
   ) AS LONG                                            ' __retval_out long *ID
   ' =====================================================================================
   METHOD SetAllocator <166> ( _                        ' VTable offset = 188
     BYVAL AllocPresent AS IUnknown _                   ' __in IUnknown *AllocPresent
   , BYVAL ID AS LONG _                                 ' __opt_in long ID = -1
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SuppressEffects <189> ( _               ' VTable offset = 192
     BYVAL bSuppress AS INTEGER _                       ' __in VARIANT_BOOL bSuppress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressEffects <189> ( _               ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bSuppress
   ' =====================================================================================
   PROPERTY GET Allocator <163> ( _                     ' VTable offset = 200
   ) AS IUnknown                                        ' __retval_out IUnknown **AllocPresent
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVMR9_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidEVR
' IID = {15E496AE-82A8-4CF9-A6B6-C561DC60398F}
' Inherited interface = IMSVidVideoRenderer
' ########################################################################################

#IF NOT %DEF(%IMSVidEVR_INTERFACE_DEFINED)
    %IMSVidEVR_INTERFACE_DEFINED = 1

$IID_IMSVidEVR = GUID$("{15E496AE-82A8-4CF9-A6B6-C561DC60398F}")

INTERFACE IMSVidEVR $IID_IMSVidEVR

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidVideoRenderer Methods
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass <134> ( _         ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass <134> ( _         ' VTable offset = 68
     BYVAL CompositorCLSID AS WSTRING _                 ' __in BSTR CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositorClass_ <133> ( _        ' VTable offset = 72
   ) AS GUID                                            ' __retval_out GUID *CompositorCLSID
   ' =====================================================================================
   PROPERTY SET CustomCompositorClass_ <133> ( _        ' VTable offset = 76
     BYREF IN CompositorCLSID AS GUID _                 ' __in REFCLSID CompositorCLSID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CustomCompositor_ <135> ( _             ' VTable offset = 80
   ) AS IVMRImageCompositor                             ' __retval_out IVMRImageCompositor **Compositor
   ' =====================================================================================
   PROPERTY SET CustomCompositor_ <135> ( _             ' VTable offset = 84
     BYVAL Compositor AS IVMRImageCompositor _          ' __in IVMRImageCompositor *Compositor
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmap <136> ( _                   ' VTable offset = 88
   ) AS IDispatch                                       ' __retval_out IPictureDisp **MixerPictureDisp
   ' =====================================================================================
   PROPERTY GET MixerBitmap_ <137> ( _                  ' VTable offset = 92
   ) AS IVMRMixerBitmap                                 ' __retval_out IVMRMixerBitmap **MixerPicture
   ' =====================================================================================
   PROPERTY SET MixerBitmap <136> ( _                   ' VTable offset = 96
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET MixerBitmap_ <137> ( _                  ' VTable offset = 100
     BYREF IN MixerPicture AS VMRALPHABITMAP _          ' __in VMRALPHABITMAP *MixerPicture
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapPositionRect <139> ( _       ' VTable offset = 104
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **rDest
   ' =====================================================================================
   PROPERTY SET MixerBitmapPositionRect <139> ( _       ' VTable offset = 108
     BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MixerBitmapOpacity <138> ( _            ' VTable offset = 112
   ) AS LONG                                            ' __retval_out int *opacity
   ' =====================================================================================
   PROPERTY SET MixerBitmapOpacity <138> ( _            ' VTable offset = 116
     BYVAL opacity AS LONG _                            ' __in int opacity
   )                                                    ' void
   ' =====================================================================================
   METHOD SetupMixerBitmap <140> ( _                    ' VTable offset = 120
     BYVAL MixerPictureDisp AS IDispatch _              ' __in IPictureDisp *MixerPictureDisp
   , BYVAL Opacity AS  LONG _                           ' __in long Opacity
   , BYVAL rDest AS IMSVidRect _                        ' __in IMSVidRect *rDest
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceSize <41> ( _                     ' VTable offset = 124
   ) AS LONG                                            ' __retval_out SourceSizeList *CurrentSize
   ' =====================================================================================
   PROPERTY SET SourceSize <41> ( _                     ' VTable offset = 128
     BYVAL NewSize AS LONG _                            ' __in SourceSizeList NewSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OverScan <5> ( _                        ' VTable offset = 132
   ) AS LONG                                            ' __retval_out long *plPercent
   ' =====================================================================================
   PROPERTY SET OverScan <5> ( _                        ' VTable offset = 136
     BYVAL lPercent AS LONG _                           ' __in long lPercent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AvailableSourceRect <33> ( _            ' VTable offset = 140
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY GET MaxVidRect <159> ( _                    ' VTable offset = 144
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET MinVidRect <160> ( _                    ' VTable offset = 148
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **ppVidRect
   ' =====================================================================================
   PROPERTY GET ClippedSourceRect <32> ( _              ' VTable offset = 152
   ) AS IMSVidRect                                      ' __retval_out IMSVidRect **pRect
   ' =====================================================================================
   PROPERTY SET ClippedSourceRect <32> ( _              ' VTable offset = 156
     BYVAL pRect AS IMSVidRect _                        ' __in IMSVidRect *pRect
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UsingOverlay <141> ( _                  ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *UseOverlayVal
   ' =====================================================================================
   PROPERTY SET UsingOverlay <141> ( _                  ' VTable offset = 164
     BYVAL UseOverlayVal AS INTEGER _                   ' __in VARIANT_BOOL UseOverlayVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Capture <161> ( _                             ' VTable offset = 168
   ) AS IDispatch                                       ' __retval_out IPictureDisp **currentImage
   ' =====================================================================================
   PROPERTY GET FramesPerSecond <80> ( _                ' VTable offset = 172
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DecimateInput <162> ( _                 ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pDeci
   ' =====================================================================================
   PROPERTY SET DecimateInput <162> ( _                 ' VTable offset = 180
     BYVAL pDeci AS INTEGER _                           ' __in VARIANT_BOOL pDeci
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidEVR Methods
   ' =====================================================================================
   PROPERTY GET Presenter ( _                           ' VTable offset = 184
   ) AS IMFVideoPresenter                               ' __retval_out IMFVideoPresenter **ppAllocPresent
   ' =====================================================================================
   PROPERTY SET Presenter ( _                           ' VTable offset = 188
     BYVAL pAllocPresent AS IMFVideoPresenter _         ' __in IMFVideoPresenter *pAllocPresent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SuppressEffects ( _                     ' VTable offset = 192
     BYVAL bSuppress AS INTEGER _                       ' __in VARIANT_BOOL bSuppress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SuppressEffects ( _                     ' VTable offset = 196
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *bSuppress
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidEVR_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidEVREvent
' IID = {349ABB10-883C-4F22-8714-CECAEEE45D62}
' Inherited interface = IMSVidOutputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidOutputDeviceEvent_INTERFACE_DEFINED)
    %IMSVidOutputDeviceEvent_INTERFACE_DEFINED = 1

$IID_IMSVidEVREvent = GUID$("{349ABB10-883C-4F22-8714-CECAEEE45D62}")

INTERFACE IMSVidEVREvent $IID_IMSVidEVREvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidEVREvent Methods
   ' =====================================================================================
   METHOD OnUserEvent ( _                               ' VTable offset = 32
     BYVAL lEventCode AS LONG _                         ' __in long lEventCode
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidOutputDeviceEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAudioRenderer
' IID = {37B0353F-A4C8-11D2-B634-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSVidOutputDevice
' ########################################################################################

#IF NOT %DEF(%IMSVidAudioRenderer_INTERFACE_DEFINED)
    %IMSVidAudioRenderer_INTERFACE_DEFINED = 1

$IID_IMSVidAudioRenderer = GUID$("{37B0353F-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidAudioRenderer $IID_IMSVidAudioRenderer

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDevice Methods
   ' =====================================================================================
   PROPERTY GET Name <0> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *Name
   ' =====================================================================================
   PROPERTY GET Status <1> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *Status
   ' =====================================================================================
   PROPERTY SET Power <9> ( _                           ' VTable offset = 36
     BYVAL Power AS INTEGER _                           ' __in VARIANT_BOOL Power
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Power <9> ( _                           ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *Power
   ' =====================================================================================
   PROPERTY GET Category <23> ( _                       ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *Guid
   ' =====================================================================================
   PROPERTY GET ClassID <24> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *Clsid
   ' =====================================================================================
   PROPERTY GET Category_ <25> ( _                      ' VTable offset = 52
   ) AS GUID                                            ' __retval_out GUID *Guid
   ' =====================================================================================
   PROPERTY GET ClassID_ <26> ( _                       ' VTable offset = 56
   ) AS GUID                                            ' __retval_out GUID *Clsid
   ' =====================================================================================
   METHOD IsEqualDevice <144> ( _                       ' VTable offset = 60
     BYVAL Device AS IMSVidDevice _                     ' __in IMSVidDevice *Device
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *IsEqual
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidOutputDevice Methods
   ' =====================================================================================

   ' No additional methods

   ' =====================================================================================
   ' IMSVidAudioRenderer Methods
   ' =====================================================================================
   PROPERTY SET Volume <7> ( _                          ' VTable offset = 64
     BYVAL lVol AS LONG _                               ' __in long lVol
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Volume <7> ( _                          ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *lVol
   ' =====================================================================================
   PROPERTY SET Balance <8> ( _                         ' VTable offset = 72
     BYVAL lBal AS LONG _                               ' __in long lBal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Balance <8> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *lBal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAudioRenderer_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAudioRendererEvent
' IID = {37B03541-A4C8-11D2-B634-00C04F79498E}
' Inherited interface = IMSVidOutputDeviceEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidAudioRendererEvent_INTERFACE_DEFINED)
    %IMSVidAudioRendererEvent_INTERFACE_DEFINED = 1

$IID_IMSVidAudioRendererEvent = GUID$("{37B03541-A4C8-11D2-B634-00C04F79498E}")

INTERFACE IMSVidAudioRendererEvent $IID_IMSVidAudioRendererEvent

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidOutputDeviceEvent Methods
   ' =====================================================================================

   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IMSVidAudioRendererEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAudioRendererEvent2
' IID = {E3F55729-353B-4C43-A028-50F79AA9A907}
' Inherited interface = IMSVidAudioRendererEvent
' ########################################################################################

#IF NOT %DEF(%IMSVidAudioRendererEvent2_INTERFACE_DEFINED)
    %IMSVidAudioRendererEvent2_INTERFACE_DEFINED = 1

$IID_IMSVidAudioRendererEvent2 = GUID$("{E3F55729-353B-4C43-A028-50F79AA9A907}")

INTERFACE IMSVidAudioRendererEvent2 $IID_IMSVidAudioRendererEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSVidDeviceEvent Methods
   ' =====================================================================================
   METHOD StateChange <0> ( _                           ' VTable offset = 28
     BYVAL lpd AS IMSVidDevice _                        ' __in IMSVidDevice *lpd
   , BYVAL oldState AS LONG _                           ' __in long oldState
   , BYVAL newState AS LONG _                           ' __in long newState
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSVidOutputDeviceEvent Methods
   ' =====================================================================================

   ' No additional methods

   ' =====================================================================================
   ' IMSVidAudioRendererEvent Methods
   ' =====================================================================================

   ' No additional methods

   ' =====================================================================================
   ' IMSVidAudioRendererEvent2 Methods
   ' =====================================================================================
   METHOD AVDecAudioDualMono <49> ( _                   ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD AVAudioSampleRate <50> ( _                    ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD AVAudioChannelConfig <51> ( _                 ' VTable offset = 40
   )                                                    ' void
   ' =====================================================================================
   METHOD AVAudioChannelCount <52> ( _                  ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD AVDecCommonMeanBitRate <53> ( _               ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD AVDDSurroundMode <54> ( _                     ' VTable offset = 52
   )                                                    ' void
   ' =====================================================================================
   METHOD AVDecCommonInputFormat <55> ( _               ' VTable offset = 56
   )                                                    ' void
   ' =====================================================================================
   METHOD AVDecCommonOutputFormat <56> ( _              ' VTable offset = 60
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAudioRendererEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidInputDevices
' IID = {C5702CD1-9B79-11D3-B654-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidInputDevices_INTERFACE_DEFINED)
    %IMSVidInputDevices_INTERFACE_DEFINED = 1

$IID_IMSVidInputDevices = GUID$("{C5702CD1-9B79-11D3-B654-00C04F79498E}")

INTERFACE IMSVidInputDevices $IID_IMSVidInputDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <16> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pD
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   ) AS IMSVidInputDevice                               ' __retval_out IMSVidInputDevice **pDB
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 40
     BYVAL pDB AS IMSVidInputDevice _                   ' __in IMSVidInputDevice *pDB
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 44
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidInputDevices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidOutputDevices
' IID = {C5702CD2-9B79-11D3-B654-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidOutputDevices_INTERFACE_DEFINED)
    %IMSVidOutputDevices_INTERFACE_DEFINED = 1

$IID_IMSVidOutputDevices = GUID$("{C5702CD2-9B79-11D3-B654-00C04F79498E}")

INTERFACE IMSVidOutputDevices $IID_IMSVidOutputDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <16> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pD
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   ) AS IMSVidOutputDevice                              ' __retval_out IMSVidOutputDevice **pDB
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 40
     BYVAL pDB AS IMSVidOutputDevice _                  ' __in IMSVidOutputDevice *pDB
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 44
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidOutputDevices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidVideoRendererDevices
' IID = {C5702CD3-9B79-11D3-B654-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidVideoRendererDevices_INTERFACE_DEFINED)
    %IMSVidVideoRendererDevices_INTERFACE_DEFINED = 1

$IID_IMSVidVideoRendererDevices = GUID$("{C5702CD3-9B79-11D3-B654-00C04F79498E}")

INTERFACE IMSVidVideoRendererDevices $IID_IMSVidVideoRendererDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <16> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pD
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   ) AS IMSVidVideoRenderer                             ' __retval_out IMSVidVideoRenderer **pDB
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 40
     BYVAL IMSVidVideoRenderer _                        ' __in IMSVidVideoRenderer *pDB
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 44
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidVideoRendererDevices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidAudioRendererDevices
' IID = {C5702CD4-9B79-11D3-B654-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidAudioRendererDevices_INTERFACE_DEFINED)
    %IMSVidAudioRendererDevices_INTERFACE_DEFINED = 1

$IID_IMSVidAudioRendererDevices = GUID$("{C5702CD4-9B79-11D3-B654-00C04F79498E}")

INTERFACE IMSVidAudioRendererDevices $IID_IMSVidAudioRendererDevices

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <16> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pD
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   ) AS IMSVidAudioRenderer                             ' __retval_out IMSVidAudioRenderer **pDB
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 40
     BYVAL pDB AS IMSVidAudioRenderer _                 ' __in IMSVidAudioRenderer *pDB
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 44
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidAudioRendererDevices_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSVidFeatures
' IID = {C5702CD5-9B79-11D3-B654-00C04F79498E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSVidFeatures_INTERFACE_DEFINED)
    %IMSVidFeatures_INTERFACE_DEFINED = 1

$IID_IMSVidFeatures = GUID$("{C5702CD5-9B79-11D3-B654-00C04F79498E}")

INTERFACE IMSVidFeatures $IID_IMSVidFeatures

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <16> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *lCount
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 32
   ) AS IEnumVARIANT                                    ' __retval_out IEnumVARIANT **pD
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 36
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   ) AS IMSVidFeature                                   ' __retval_out IMSVidFeature **pDB
   ' =====================================================================================
   METHOD Add <-553> ( _                                ' VTable offset = 40
     BYVAL IMSVidFeature _                              ' __in IMSVidFeature *pDB)
   )                                                    ' void
   ' =====================================================================================
   METHOD Remove <-555> ( _                             ' VTable offset = 44
     BYVAL v AS VARIANT _                               ' __in VARIANT v
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSVidFeatures_INTERFACE_DEFINED__ */
