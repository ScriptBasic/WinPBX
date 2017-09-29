' ########################################################################################
' Microsoft Windows
' File: ipmsp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IPMSP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "tapi3if.inc"

%MAX_PARTICIPANT_TYPED_INFO_LENGTH = 256
%MAX_QOS_ID_LEN = 128

' enum PARTICIPANT_TYPED_INFO
%PTI_CANONICALNAME = 0
%PTI_NAME          = %PTI_CANONICALNAME + 1
%PTI_EMAILADDRESS  = %PTI_NAME          + 1
%PTI_PHONENUMBER   = %PTI_EMAILADDRESS  + 1
%PTI_LOCATION      = %PTI_PHONENUMBER   + 1
%PTI_TOOL          = %PTI_LOCATION      + 1
%PTI_NOTES         = %PTI_TOOL          + 1
%PTI_PRIVATE       = %PTI_NOTES         + 1

' enum PARTICIPANT_EVENT
%PE_NEW_PARTICIPANT       = 0
%PE_INFO_CHANGE           = %PE_NEW_PARTICIPANT       + 1
%PE_PARTICIPANT_LEAVE     = %PE_INFO_CHANGE           + 1
%PE_NEW_SUBSTREAM         = %PE_PARTICIPANT_LEAVE     + 1
%PE_SUBSTREAM_REMOVED     = %PE_NEW_SUBSTREAM         + 1
%PE_SUBSTREAM_MAPPED      = %PE_SUBSTREAM_REMOVED     + 1
%PE_SUBSTREAM_UNMAPPED    = %PE_SUBSTREAM_MAPPED      + 1
%PE_PARTICIPANT_TIMEOUT   = %PE_SUBSTREAM_UNMAPPED    + 1
%PE_PARTICIPANT_RECOVERED = %PE_PARTICIPANT_TIMEOUT   + 1
%PE_PARTICIPANT_ACTIVE    = %PE_PARTICIPANT_RECOVERED + 1
%PE_PARTICIPANT_INACTIVE  = %PE_PARTICIPANT_ACTIVE    + 1
%PE_LOCAL_TALKING         = %PE_PARTICIPANT_INACTIVE  + 1
%PE_LOCAL_SILENT          = %PE_LOCAL_TALKING         + 1


' ########################################################################################
' Interface name = ITParticipant
' IID = {5899B820-5A34-11D2-95A0-00A0244D2298}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITParticipant_INTERFACE_DEFINED)
    %ITParticipant_INTERFACE_DEFINED = 1

$IID_ITParticipant = GUID$("{5899B820-5A34-11D2-95A0-00A0244D2298}")

INTERFACE ITParticipant $IID_ITParticipant

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ParticipantTypedInfo <1> ( _            ' VTable offset = 28
     BYVAL InfoType AS LONG _                           ' __in PARTICIPANT_TYPED_INFO InfoType
   ) AS WSTRING                                         ' __retval_out BSTR *ppInfo
   ' =====================================================================================
   PROPERTY GET MediaTypes <2> ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plMediaType
   ' =====================================================================================
   PROPERTY SET Status <3> ( _                          ' VTable offset = 36
     BYVAL pITStream AS ITStream _                      ' __in ITStream *pITStream
   , BYVAL fEnable AS INTEGER _                         ' __in VARIANT_BOOL fEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Status <3> ( _                          ' VTable offset = 40
     BYVAL pITStream AS ITStream _                      ' __in ITStream *pITStream
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pStatus
  ' =====================================================================================
   PROPERTY GET Streams <4> ( _                         ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *pVariant
   ' =====================================================================================
   METHOD EnumerateStreams <6> ( _                      ' VTable offset = 48
   ) AS IEnumStream                                     ' __retval_out IEnumStream **ppEnumStream
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITParticipant_INTERFACE_DEFINED__ */


#IF NOT %DEF(%STREAM_INTERFACES_DEFINED)
    %STREAM_INTERFACES_DEFINED = 1

%MAX_DESCRIPTION_LEN = 256

' // Size = 560 bytes
TYPE TAPI_AUDIO_STREAM_CONFIG_CAPS DWORD
   Description                AS WSTRINGZ * 256   ' WCHAR Description[ 256 ]
   MinimumChannels            AS DWORD            ' ULONG
   MaximumChannels            AS DWORD            ' ULONG
   ChannelsGranularity        AS DWORD            ' ULONG
   MinimumBitsPerSample       AS DWORD            ' ULONG
   MaximumBitsPerSample       AS DWORD            ' ULONG
   BitsPerSampleGranularity   AS DWORD            ' ULONG
   MinimumSampleFrequency     AS DWORD            ' ULONG
   MaximumSampleFrequency     AS DWORD            ' ULONG
   SampleFrequencyGranularity AS DWORD            ' ULONG
   MinimumAvgBytesPerSec      AS DWORD            ' ULONG
   MaximumAvgBytesPerSec      AS DWORD            ' ULONG
   AvgBytesPerSecGranularity  AS DWORD            ' ULONG
END TYPE

' // Size = 624 bytes
TYPE TAPI_VIDEO_STREAM_CONFIG_CAPS   ' Must be 8 byte aligned
   Description        AS WSTRINGZ  * 256   ' WCHAR Description[ 256 ]
   VideoStandard      AS DWORD             ' ULONG
   alignment__        AS DWORD             ' // To keep 8 byte alignment
   InputSize          AS SIZE              ' SIZE
   MinCroppingSize    AS SIZE              ' SIZE
   MaxCroppingSize    AS SIZE              ' SIZE
   CropGranularityX   AS LONG              ' int
   CropGranularityY   AS LONG              ' int
   CropAlignX         AS LONG              ' int
   CropAlignY         AS LONG              ' int
   MinOutputSize      AS SIZE              ' SIZE
   MaxOutputSize      AS SIZE              ' SIZE
   OutputGranularityX AS LONG              ' int
   OutputGranularityY AS LONG              ' int
   StretchTapsX       AS LONG              ' int
   StretchTapsY       AS LONG              ' int
   ShrinkTapsX        AS LONG              ' int
   ShrinkTapsY        AS LONG              ' int
   MinFrameInterval   AS QUAD              ' LONGLONG
   MaxFrameInterval   AS QUAD              ' LONGLONG
   MinBitsPerSecond   AS LONG              ' LONG
   MaxBitsPerSecond   AS LONG              ' LONG
END TYPE

' enum tagStreamConfigCapsType
%AudioStreamConfigCaps   = 0
%VideoStreamConfigCaps   = %AudioStreamConfigCaps + 1

'typedef struct tagTAPI_STREAM_CONFIG_CAPS
'    {
'    StreamConfigCapsType CapsType;
'    union
'        {
'        TAPI_VIDEO_STREAM_CONFIG_CAPS VideoCap;
'        TAPI_AUDIO_STREAM_CONFIG_CAPS AudioCap;
'        }    ;
'    }    TAPI_STREAM_CONFIG_CAPS;

' // Size = 620 bytes
UNION TAPI_STREAM_CONFIG_CAPS_UNION
   VideoCap AS TAPI_VIDEO_STREAM_CONFIG_CAPS
   AudioCap AS TAPI_AUDIO_STREAM_CONFIG_CAPS
END UNION

' // Size = 632 bytes
TYPE TAPI_STREAM_CONFIG_CAPS   ' Must be 8 byte aligned
   CapsType    AS LONG     ' StreamConfigCapsType
   alignment__ AS DWORD    ' // To keep 8 byte alignment
   TAPI_STREAM_CONFIG_CAPS_UNION
END TYPE

' enum tagTAPIControlFlags
%TAPIControl_Flags_None   = 0
%TAPIControl_Flags_Auto   = &H1
%TAPIControl_Flags_Manual = &H2


' ########################################################################################
' Interface name = ITFormatControl
' IID = {6C0AB6C1-21E3-11D3-A577-00C04F8EF6E3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITFormatControl_INTERFACE_DEFINED)
    %ITFormatControl_INTERFACE_DEFINED = 1

$IID_ITFormatControl = GUID$("{6C0AB6C1-21E3-11D3-A577-00C04F8EF6E3}")

INTERFACE ITFormatControl $IID_ITFormatControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentFormat ( _                          ' VTable offset = 12
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFormat ( _                             ' VTable offset = 16
     BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in AM_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfCapabilities ( _                   ' VTable offset = 20
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamCaps ( _                             ' VTable offset = 24
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   , BYREF pStreamConfigCaps AS TAPI_STREAM_CONFIG_CAPS _ ' __out TAPI_STREAM_CONFIG_CAPS *pStreamConfigCaps
   , BYREF pfEnabled AS LONG _                          ' __out BOOL *pfEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReOrderCapabilities ( _                       ' VTable offset = 28
     BYREF pdwIndices AS DWORD _                        ' __in DWORD *pdwIndices
   , BYREF pfEnabled AS LONG _                          ' __in BOOL *pfEnabled
   , BYREF pfPublicize AS LONG _                        ' __in BOOL *pfPublicize
   , BYVAL dwNumIndices AS DWORD _                      ' __in DWORD dwNumIndices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITFormatControl_INTERFACE_DEFINED__ */


' enum tagStreamQualityProperty
%StreamQuality_MaxBitrate       = 0
%StreamQuality_CurrBitrate      = %StreamQuality_MaxBitrate       + 1
%StreamQuality_MinFrameInterval = %StreamQuality_CurrBitrate      + 1
%StreamQuality_AvgFrameInterval = %StreamQuality_MinFrameInterval + 1


' ########################################################################################
' Interface name = ITStreamQualityControl
' IID = {6C0AB6C2-21E3-11D3-A577-00C04F8EF6E3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITStreamQualityControl_INTERFACE_DEFINED)
    %ITStreamQualityControl_INTERFACE_DEFINED = 1

$IID_ITStreamQualityControl = GUID$("{6C0AB6C2-21E3-11D3-A577-00C04F8EF6E3}")

INTERFACE ITStreamQualityControl $IID_ITStreamQualityControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in StreamQualityProperty Property
   , BYREF plMin AS LONG _                              ' __out long *plMin
   , BYREF plMax AS LONG _                              ' __out long *plMax
   , BYREF plSteppingDelta AS LONG _                    ' __out long *plSteppingDelta
   , BYREF plDefault AS LONG _                          ' __out long *plDefault
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in StreamQualityProperty Property
   , BYREF plValue AS LONG _                            ' __out long *plValue
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in StreamQualityProperty Property
   , BYVAL lValue AS LONG _                             ' __in long lValue
   , BYVAL lFlags AS LONG _                             ' __in TAPIControlFlags lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITStreamQualityControl_INTERFACE_DEFINED__ */


' enum tagCallQualityProperty
%CallQuality_ControlInterval   = 0
%CallQuality_ConfBitrate       = %CallQuality_ControlInterval   + 1
%CallQuality_MaxInputBitrate   = %CallQuality_ConfBitrate       + 1
%CallQuality_CurrInputBitrate  = %CallQuality_MaxInputBitrate   + 1
%CallQuality_MaxOutputBitrate  = %CallQuality_CurrInputBitrate  + 1
%CallQuality_CurrOutputBitrate = %CallQuality_MaxOutputBitrate  + 1
%CallQuality_MaxCPULoad        = %CallQuality_CurrOutputBitrate + 1
%CallQuality_CurrCPULoad       = %CallQuality_MaxCPULoad        + 1


' ########################################################################################
' Interface name = ITCallQualityControl
' IID = {FE1D8AE0-EDC4-49B5-8F8C-4DE40F9CDFAF}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITCallQualityControl_INTERFACE_DEFINED)
    %ITCallQualityControl_INTERFACE_DEFINED = 1

$IID_ITCallQualityControl = GUID$("{FE1D8AE0-EDC4-49B5-8F8C-4DE40F9CDFAF}")

INTERFACE ITCallQualityControl $IID_ITCallQualityControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in CallQualityProperty Property
   , BYREF plMin AS LONG _                              ' __out long *plMin
   , BYREF plMax AS LONG _                              ' __out long *plMax
   , BYREF plSteppingDelta AS LONG _                    ' __out long *plSteppingDelta
   , BYREF plDefault AS LONG _                          ' __out long *plDefault
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in CallQualityProperty Property
   , BYREF plValue AS LONG _                            ' __out long *plValue
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in CallQualityProperty Property
   , BYVAL lValue AS LONG _                             ' __in long lValue
   , BYVAL lFlags AS LONG _                             ' __in TAPIControlFlags lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITCallQualityControl_INTERFACE_DEFINED__ */


' enum tagAudioDeviceProperty
%AudioDevice_DuplexMode               = 0
%AudioDevice_AutomaticGainControl     = %AudioDevice_DuplexMode           + 1
%AudioDevice_AcousticEchoCancellation = %AudioDevice_AutomaticGainControl + 1


' ########################################################################################
' Interface name = ITAudioDeviceControl
' IID = {6C0AB6C5-21E3-11D3-A577-00C04F8EF6E3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITAudioDeviceControl_INTERFACE_DEFINED)
    %ITAudioDeviceControl_INTERFACE_DEFINED = 1

$IID_ITAudioDeviceControl = GUID$("{6C0AB6C5-21E3-11D3-A577-00C04F8EF6E3}")

INTERFACE ITAudioDeviceControl $IID_ITAudioDeviceControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in AudioDeviceProperty Property
   , BYREF plMin AS LONG _                              ' __out long *plMin
   , BYREF plMax AS LONG _                              ' __out long *plMax
   , BYREF plSteppingDelta AS LONG _                    ' __out long *plSteppingDelta
   , BYREF plDefault AS LONG _                          ' __out long *plDefault
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in AudioDeviceProperty Property
   , BYREF plValue AS LONG _                            ' __out long *plValue
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in AudioDeviceProperty Property
   , BYVAL lValue AS LONG _                             ' __in long lValue
   , BYVAL lFlags AS LONG _                             ' __in TAPIControlFlags lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAudioDeviceControl_INTERFACE_DEFINED__ */


' enum tagAudioSettingsProperty
%AudioSettings_SignalLevel      = 0
%AudioSettings_SilenceThreshold = %AudioSettings_SignalLevel      + 1
%AudioSettings_Volume           = %AudioSettings_SilenceThreshold + 1
%AudioSettings_Balance          = %AudioSettings_Volume           + 1
%AudioSettings_Loudness         = %AudioSettings_Balance          + 1
%AudioSettings_Treble           = %AudioSettings_Loudness         + 1
%AudioSettings_Bass             = %AudioSettings_Treble           + 1
%AudioSettings_Mono             = %AudioSettings_Bass             + 1


' ########################################################################################
' Interface name = ITAudioSettings
' IID = {6C0AB6C6-21E3-11D3-A577-00C04F8EF6E3}
' Attributes = 16 [&H10] [Hidden]
' Inherited interface = IUnknown
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITAudioSettings_INTERFACE_DEFINED)
    %ITAudioSettings_INTERFACE_DEFINED = 1

$IID_ITAudioSettings = GUID$("{6C0AB6C6-21E3-11D3-A577-00C04F8EF6E3}")

INTERFACE ITAudioSettings $IID_ITAudioSettings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in AudioSettingsProperty Property
   , BYREF plMin AS LONG _                              ' __out long *plMin
   , BYREF plMax AS LONG _                              ' __out long *plMax
   , BYREF plSteppingDelta AS LONG _                    ' __out long *plSteppingDelta
   , BYREF plDefault AS LONG _                          ' __out long *plDefault
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in AudioSettingsProperty Property
   , BYREF plValue AS LONG _                            ' __out long *plValue
   , BYREF plFlags AS LONG _                            ' __out TAPIControlFlags *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in AudioSettingsProperty Property
   , BYVAL lValue AS LONG _                             ' __in long lValue
   , BYVAL lFlags AS LONG _                             ' __in TAPIControlFlags lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITAudioSettings_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ITQOSApplicationID
' IID = {E8C89D27-A3BD-47D5-A6FC-D2AE40CDBC6E}
' ITQOSApplicationID interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' Note: This interface is not available for use in Windows Vista, Windows Server 2008, and
' subsequent versions of the operating system. The RTC Client API provides similar functionality.
' ########################################################################################

#IF NOT %DEF(%ITQOSApplicationID_INTERFACE_DEFINED)
    %ITQOSApplicationID_INTERFACE_DEFINED = 1

$IID_ITQOSApplicationID = GUID$("{E8C89D27-A3BD-47D5-A6FC-D2AE40CDBC6E}")

INTERFACE ITQOSApplicationID $IID_ITQOSApplicationID

   INHERIT IDispatch

   ' =====================================================================================
   METHOD SetQOSApplicationID <1610743808> ( _          ' VTable offset = 28
     BYVAL pApplicationID AS WSTRING _                  ' __in BSTR pApplicationID
   , BYVAL pApplicationGUID AS WSTRING _                ' __in BSTR pApplicationGUID
   , BYVAL pSubIDs AS WSTRING _                         ' __in BSTR pSubIDs
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITQOSApplicationID_INTERFACE_DEFINED__ */


#ENDIF   ' // STREAM_INTERFACES_DEFINED

#IF NOT %DEF(%RTP_MEDIATYPE_DEFINED)
%RTP_MEDIATYPE_DEFINED = 1
$MEDIATYPE_RTP_Single_Stream = GUID$("{14099BC0-787B-11D0-9CD3-00A0C9081C19}")
#ENDIF ' //RTP_MEDIATYPE_DEFINED
