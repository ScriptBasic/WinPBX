' ########################################################################################
' Microsoft Windows
' File: StreamDescription.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STREAMDESCRIPTION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "WMSBuffer.inc"
#INCLUDE ONCE "WMSContext.inc"

$IID_IWMSStreamHeader = GUID$("{3309C903-10A4-11D2-9EEE-006097D2D7CF}")
$IID_IWMSStreamHeaderList = GUID$("{42176202-2B30-11D2-9EF7-006097D2D7CF}")
$IID_IWMSContentDescriptionList = GUID$("{105D6F73-6DF0-11D2-9F14-006097D2D7CF}")
$IID_IWMSStreamSwitchDescriptionList = GUID$("{75C3017C-6B3A-4E25-BE9F-A9927F4DD058}")
$IID_IWMSUnknownStreamFormat = GUID$("{52769631-38AA-11D2-9EFA-006097D2D7CF}")
$IID_IWMSUnknownStreamType = GUID$("{52769632-38AA-11D2-9EFA-006097D2D7CF}")
$IID_IWMSUnknownContainerFormat = GUID$("{52769631-38AA-11D2-9EFA-006097D2D7CF}")

' ########################################################################################
' Interface name = IWMSStreamHeader
' IID = {3309C903-10A4-11D2-9EEE-006097D2D7CF}
' Contains methods that describe the header for a specific stream.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSStreamHeader_INTERFACE_DEFINED)
    %IWMSStreamHeader_INTERFACE_DEFINED = 1

INTERFACE IWMSStreamHeader $IID_IWMSStreamHeader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 12
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 16
     BYVAL Format AS GUID _                             ' __in GUID Format
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamType ( _                             ' VTable offset = 20
     BYREF pStreamType AS GUID _                        ' __out GUID *pStreamType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamType ( _                             ' VTable offset = 24
     BYVAL StreamType AS GUID _                         ' __in GUID StreamType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntegerAttribute ( _                       ' VTable offset = 28
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYREF pdwAttribute AS DWORD _                      ' __out DWORD *pdwAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntegerAttribute ( _                       ' VTable offset = 32
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYVAL dwAttribute AS DWORD _                       ' __in DWORD dwAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringAttribute ( _                        ' VTable offset = 36
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYREF pszAttribute AS WSTRING _                    ' __out BSTR *pszAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringAttribute ( _                        ' VTable offset = 40
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYVAL szAttribute AS WSTRING _                     ' __in BSTR szAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedAttribute ( _                      ' VTable offset = 44
     BYVAL dwValueName AS DWORD _                       ' __in DWORD dwValueName
   , BYREF pVariantValue AS VARIANT _                   ' __out VARIANT *pVariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtendedAttribute ( _                      ' VTable offset = 48
     BYVAL dwValueName AS DWORD _                       ' __in DWORD dwValueName
   , BYVAL VariantValue AS VARIANT _                    ' __in VARIANT VariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNthExtendedAttribute ( _                   ' VTable offset = 52
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pdwValueName AS DWORD _                      ' __out DWORD *pdwValueName
   , BYREF pVariantValue AS VARIANT _                   ' __out VARIANT *pVariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumExtendedAttributes ( _                  ' VTable offset = 56
     BYREF pdwValueName AS DWORD _                      ' __out DWORD *pdwValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneStreamHeader ( _                         ' VTable offset = 60
     BYREF ppHeader AS IWMSStreamHeader _               ' __out IWMSStreamHeader **ppHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSStreamHeader_INTERFACE_DEFINED__ */

%WMS_STREAM_ID                   = 0
%WMS_STREAM_MIN_BITRATE          = 1
%WMS_STREAM_MAX_BITRATE          = 2
%WMS_STREAM_AVG_BITRATE          = 3
%WMS_STREAM_MAX_PACKET_SIZE      = 4
%WMS_STREAM_AVG_PACKET_SIZE      = 5
%WMS_STREAM_PREROLL              = 6
%WMS_STREAM_FLAGS                = 7
%WMS_STREAM_NAME                 = 8
%WMS_STREAM_SHARING_GROUP        = 9
%WMS_STREAM_SHARING_BANDWIDTH    = 10
%WMS_NUM_STREAMHEADER_ATTRIBUTES = 11
%WMS_STREAM_HAS_NON_KEY_FRAMES   = &H0001
%WMS_STREAM_RELIABLE_FLAG        = &H0002
%WMS_STREAM_CONCEALED_FLAG       = &H0004
%WMS_ASF_THRESHOLD_DURATION      = 500

' ########################################################################################
' Interface name = IWMSStreamHeaderList
' IID = {42176202-2B30-11D2-9EF7-006097D2D7CF}
' Contains a collection of IWMSStreamHeader objects and methods that describe each stream in a multimedia stream.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSStreamHeaderList_INTERFACE_DEFINED)
    %IWMSStreamHeaderList_INTERFACE_DEFINED = 1

INTERFACE IWMSStreamHeaderList $IID_IWMSStreamHeaderList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHeaderCount ( _                            ' VTable offset = 12
     BYREF pdwNumHeaders AS DWORD _                     ' __out DWORD *pdwNumHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHeader ( _                                 ' VTable offset = 16
     BYVAL dwHeaderNum AS DWORD _                       ' __in DWORD dwHeaderNum
   , BYREF ppHeader AS IWMSStreamHeader _               ' __out IWMSStreamHeader **ppHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendHeader ( _                              ' VTable offset = 20
     BYVAL pHeader AS IWMSStreamHeader _                ' __in IWMSStreamHeader *pHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllHeaders ( _                          ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerFormat ( _                        ' VTable offset = 28
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContainerFormat ( _                        ' VTable offset = 32
     BYVAL Format AS GUID _                             ' __in GUID Format
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDataVersion ( _                            ' VTable offset = 36
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataVersion ( _                            ' VTable offset = 40
     BYVAL Format AS GUID _                             ' __in GUID Format
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeContainerHeader ( _                  ' VTable offset = 44
     BYREF ppBuffer AS INSSBuffer _                     ' __out INSSBuffer **ppBuffer
   , BYREF pdwOffset AS DWORD _                         ' __out DWORD *pdwOffset
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNativeContainerHeader ( _                  ' VTable offset = 48
     BYVAL pBuffer AS INSSBuffer _                      ' __in INSSBuffer *pBuffer
   , BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwLength AS DWORD _                          ' __in DWORD dwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentDescription ( _                     ' VTable offset = 52
     BYREF ppDescription AS IWMSContentDescriptionList _ ' __out IWMSContentDescriptionList **ppDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentDescription ( _                     ' VTable offset = 56
     BYVAL pDescription AS IWMSContentDescriptionList _ ' __in IWMSContentDescriptionList *pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIntegerAttribute ( _                       ' VTable offset = 60
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYREF pdwAttribute AS DWORD _                      ' __out DWORD *pdwAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntegerAttribute ( _                       ' VTable offset = 64
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYVAL dwAttribute AS DWORD _                       ' __in DWORD dwAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringAttribute ( _                        ' VTable offset = 68
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYREF pszAttribute AS WSTRING _                    ' __out BSTR *pszAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringAttribute ( _                        ' VTable offset = 72
     BYVAL dwAttributeId AS DWORD _                     ' __in DWORD dwAttributeId
   , BYVAL szAttribute AS WSTRING _                     ' __in BSTR szAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtendedAttribute ( _                      ' VTable offset = 76
     BYVAL dwValueName AS DWORD _                       ' __in DWORD  dwValueName
   , BYREF pVariantValue AS VARIANT _                   ' __out VARIANT *pVariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtendedAttribute ( _                      ' VTable offset = 80
     BYVAL dwValueName AS DWORD _                       ' __in DWORD dwValueName
   , BYVAL VariantValue AS VARIANT _                    ' __in VARIANT VariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNthExtendedAttribute ( _                   ' VTable offset = 84
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pdwValueName AS DWORD _                      ' __out DWORD *pdwValueName
   , BYREF pVariantValue AS VARIANT _                   ' __out VARIANT *pVariantValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumExtendedAttributes ( _                  ' VTable offset = 88
     BYREF pdwValueName AS DWORD _                      ' __out DWORD *pdwValueName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneStreamHeaderList ( _                     ' VTable offset = 92
     BYVAL pBufferAllocator AS IWMSBufferAllocator _    ' __in IWMSBufferAllocator *pBufferAllocator
   , BYREF ppHeader AS IWMSStreamHeaderList _           ' __out IWMSStreamHeaderList **ppHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecordPlaylistGenerationId ( _                ' VTable offset = 96
     BYVAL pCommand AS IWMSCommandContext _             ' __in IWMSCommandContext *pCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckPlaylistGenerationId ( _                 ' VTable offset = 100
     BYVAL pCommand AS IWMSCommandContext _             ' __in IWMSCommandContext *pCommand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSStreamHeaderList_INTERFACE_DEFINED__ */

%WMS_TOTAL_MIN_BITRATE                           = 0
%WMS_TOTAL_MAX_BITRATE                           = 1
%WMS_TOTAL_AVG_BITRATE                           = 2
%WMS_CONTAINER_FLAGS                             = 3
%WMS_CONTAINER_DURATION_LO                       = 4
%WMS_CONTAINER_DURATION_HI                       = 5
%WMS_CONTAINER_MAX_PACKET_SIZE                   = 6
%WMS_CONTAINER_PLAYLIST_ENTRY_NAME               = 7
%WMS_TOTAL_PACKETS_LO                            = 8
%WMS_TOTAL_PACKETS_HI                            = 9
%WMS_STREAM_PLAYLIST_GENERATION_ID               = 10
%WMS_CONTAINER_FILESIZE_LO                       = 11
%WMS_CONTAINER_FILESIZE_HI                       = 12
%WMS_STREAM_DISTRIBUTION_PLAYLIST_GENERATION_ID  = 13
%WMS_CONTAINER_LOG_PHYSICAL_URL                  = 14
%WMS_CONTAINER_IS_VBR                            = 15
%WMS_STREAM_BROADCAST_GENERATION_ID              = 16
%WMS_STREAM_DISTRIBUTION_BROADCAST_GENERATION_ID = 17
%WMS_NUM_STREAMHEADERLIST_ATTRIBUTES             = 18
%WMS_CONTAINER_BROADCAST                         = &H0001
%WMS_CONTAINER_CANSEEK                           = &H0002
%WMS_CONTAINER_CANSTRIDE                         = &H0004
%WMS_CONTAINER_LIVE                              = &H0008
%WMS_CONTAINER_RECORDABLE                        = &H0010
%WMS_CONTAINER_PART_OF_PLAYLIST                  = &H0020
%WMS_CONTAINER_ONDEMAND_PLAYLIST_EMULATING_BCAST = &H0040
%WMS_CONTAINER_PART_OF_WRAPPER_PLAYLIST          = &H0080
%WMS_CONTAINER_ALLOW_PLAYLIST_SKIP_FORWARD       = &H0100
%WMS_CONTAINER_ALLOW_PLAYLIST_SKIP_BACKWARD      = &H0200
%WMS_CONTAINER_SEEKABLE_EMULATING_BROADCAST      = &H0400
%WMS_CONTAINER_LAST_ENTRY_IN_PLAYLIST            = &H0800

' ########################################################################################
' Interface name = IWMSContentDescriptionList
' IID = {105D6F73-6DF0-11D2-9F14-006097D2D7CF}
' Contains a collection of content description contexts for different languages.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSContentDescriptionList_INTERFACE_DEFINED)
    %IWMSContentDescriptionList_INTERFACE_DEFINED = 1

INTERFACE IWMSContentDescriptionList $IID_IWMSContentDescriptionList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDescriptionCount ( _                       ' VTable offset = 12
     BYREF pdwNumDescriptions AS DWORD _                ' __out DWORD *pdwNumDescriptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexedDescription ( _                     ' VTable offset = 16
     BYVAL dwDescriptionNum AS DWORD _                  ' __in DWORD dwDescriptionNum
   , BYREF pstrLanguage AS DWORD _                      ' __out LPWSTR *pstrLanguage
   , BYREF ppDescription AS IWMSContext _               ' __out IWMSContext **ppDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescriptionInLanguage ( _                  ' VTable offset = 20
     BYREF pstrLanguage AS WSTRINGZ _                   ' __in LPWSTR pstrLanguage
   , BYREF ppDescription AS IWMSContext _               ' __out IWMSContext **ppDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendDescription ( _                         ' VTable offset = 24
     BYREF pstrLanguage AS WSTRINGZ _                   ' __in LPWSTR pstrLanguage
   , BYVAL pDescription AS IWMSContext _                ' __in IWMSContext *pDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllDescriptions ( _                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPlaylistGenid ( _                          ' VTable offset = 32
     BYREF pdwPlaylistGenerationId AS DWORD _           ' __out DWORD *pdwPlaylistGenerationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPlaylistGenid ( _                          ' VTable offset = 36
     BYVAL dwPlaylistGenerationId AS DWORD _            ' __in DWORD dwPlaylistGenerationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBroadcastid ( _                            ' VTable offset = 40
     BYREF pdwPlaylistGenerationId AS DWORD _           ' __out DWORD *pdwPlaylistGenerationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBroadcastid ( _                            ' VTable offset = 44
     BYVAL dwPlaylistGenerationId AS DWORD _            ' __in DWORD dwPlaylistGenerationId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueOnAllDescriptions ( _                 ' VTable offset = 48
     BYREF pstrName AS WSTRINGZ _                       ' __in LPWSTR pstrName
   , BYVAL lNameHint AS LONG _                          ' __in long lNameHint
   , BYVAL lNameHint AS VARIANT _                       ' __in VARIANT Value
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveValueFromAllDescriptions ( _            ' VTable offset = 52
     BYREF pstrName AS WSTRINGZ _                       ' __in LPWSTR pstrName
   , BYVAL lNameHint AS LONG _                          ' __in long lNameHint
   , BYVAL lOptions AS LONG _                           ' __in long lOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSContentDescriptionList_INTERFACE_DEFINED__ */

' enum WMS_STREAM_CONSTANTS
%WMS_DATA_STREAM_MIN           = 0
%WMS_DATA_STREAM_MAX           = &Hfffe???
%WMS_NO_STREAM                 = &Hffff???
%WMS_RETRANSMISSION_STREAM_MIN = &H10000???
%WMS_RETRANSMISSION_STREAM_MAX = &H1fffe???
%WMS_FEC_STREAM_MIN            = &H20000???
%WMS_FEC_STREAM_MAX            = &H2fffe???

'#define IS_DATA_STREAM(x)   ( ( x ) >= WMS_DATA_STREAM_MIN && ( x ) <= WMS_DATA_STREAM_MAX )
MACRO IS_DATA_STREAM(x) = ((x >= %WMS_DATA_STREAM_MIN) AND (x <= %WMS_DATA_STREAM_MAX))
'#define IS_RETRANSMISSION_STREAM(x)    ( ( x ) >= WMS_RETRANSMISSION_STREAM_MIN && ( x ) <= WMS_RETRANSMISSION_STREAM_MAX )
MACRO IS_RETRANSMISSION_STREAM(x) = ((x >= %WMS_RETRANSMISSION_STREAM_MIN) AND (x <= WMS_RETRANSMISSION_STREAM_MAX))
'#define IS_FEC_STREAM(x)    ( ( x ) >= WMS_FEC_STREAM_MIN && ( x ) <= WMS_FEC_STREAM_MAX )
MACRO IS_FEC_STREAM(x) = ((x >= %WMS_FEC_STREAM_MIN) AND (x <= %WMS_FEC_STREAM_MAX))

' WMS_STREAM_MODIFIERS enum
%WMS_NO_MODIFIER                = 0
%WMS_THINNING_MODIFIER          = 1
%WMS_REMOVE_ALL_FRAMES_MODIFIER = 2

' enum WMS_THINNING_MODIFIER_TYPES
%WMS_NO_THINNING                 = 0
%WMS_INTERMEDIATE_FRAME_THINNING = 1
%WMS_REMOVE_ALL_FRAMES           = 2

' // Size = 24 bytes
TYPE CWMSStreamSwitch DWORD
   wPlaylistSequenceNumber      AS WORD    ' WORD
   dwOldStreamNumber            AS DWORD   ' DWORD
   dwNewStreamNumber            AS DWORD   ' DWORD
   ModifierType                 AS LONG    ' WMS_STREAM_MODIFIERS
   dwModifier                   AS DWORD   ' DWORD
   dwPredictiveStreamSelections AS DWORD   ' DWORD
END TYPE

' ########################################################################################
' Interface name = IWMSStreamSwitchDescriptionList
' IID = {75C3017C-6B3A-4E25-BE9F-A9927F4DD058}
' Contains methods that control which streams are sent down a data path.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSStreamSwitchDescriptionList_INTERFACE_DEFINED)
    %IWMSStreamSwitchDescriptionList_INTERFACE_DEFINED = 1

INTERFACE IWMSStreamSwitchDescriptionList $IID_IWMSStreamSwitchDescriptionList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDescriptionCount ( _                       ' VTable offset = 12
     BYREF pdwNumDescriptions AS DWORD _                ' __out DWORD *pdwNumDescriptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexedDescription ( _                     ' VTable offset = 16
     BYVAL dwDescriptionNum AS DWORD _                  ' __in DWORD dwDescriptionNum
   , BYREF pStreamSwitchDesc AS CWMSStreamSwitch _      ' __out CWMSStreamSwitch *pStreamSwitchDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeIndexedDescription ( _                  ' VTable offset = 20
     BYVAL dwDescriptionNum AS DWORD _                  ' __in DWORD dwDescriptionNum
   , BYREF pStreamSwitchDesc AS CWMSStreamSwitch _      ' __out CWMSStreamSwitch *pStreamSwitchDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveIndexedDescription ( _                  ' VTable offset = 24
     BYVAL dwDescriptionNum AS DWORD _                  ' __in DWORD dwDescriptionNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendDescription ( _                         ' VTable offset = 28
     BYREF pStreamSwitchDesc AS CWMSStreamSwitch _      ' __in CWMSStreamSwitch *pStreamSwitchDesc  <record>
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllDescriptions ( _                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSStreamSwitchDescriptionList_INTERFACE_DEFINED__ */

' WMS_SEEK_TYPE enum
%WMS_SEEK_TO_TIME           = 1
%WMS_SEEK_TO_PACKET         = 2
%WMS_SEEK_TO_PLAYLIST_ENTRY = 3
%WMS_SEEK_TO_BYTE_OFFSET    = 4
