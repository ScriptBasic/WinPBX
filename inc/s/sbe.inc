' ########################################################################################
' Microsoft Windows
' File: sbe.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SBE_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "strmif.inc"

' ########################################################################################
' IStreamBufferInitialize interface
' IID = 9CE50F2D-6BA7-40FB-A034-50B1A674EC78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferInitialize_INTERFACE_DEFINED)
    %IStreamBufferInitialize_INTERFACE_DEFINED = 1

$IID_IStreamBufferInitialize = GUID$("{9CE50F2D-6BA7-40FB-A034-50B1A674EC78}")

INTERFACE IStreamBufferInitialize $IID_IStreamBufferInitialize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHKEY ( _                                   ' VTable offset = 12
     BYVAL hkeyRoot AS DWORD _                          ' __in HKEY hkeyRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSIDs ( _                                   ' VTable offset = 16
     BYVAL cSIDs AS DWORD _                             ' __in DWORD cSIDs
   , BYVAL ppSID AS SID PTR _                           ' __in PSID *ppSID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferInitialize_INTERFACE_DEFINED__ */


' enum __MIDL___MIDL_itf_sbe_0000_0001_0001
%RECORDING_TYPE_CONTENT   = 0
%RECORDING_TYPE_REFERENCE = %RECORDING_TYPE_CONTENT + 1


' ########################################################################################
' IStreamBufferSink interface
' IID = AFD1F242-7EFD-45EE-BA4E-407A25C9A77A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferSink_INTERFACE_DEFINED)
    %IStreamBufferSink_INTERFACE_DEFINED = 1

$IID_IStreamBufferSink = GUID$("{AFD1F242-7EFD-45EE-BA4E-407A25C9A77A}")

INTERFACE IStreamBufferSink $IID_IStreamBufferSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LockProfile ( _                               ' VTable offset = 12
     BYREF pszStreamBufferFilename AS WSTRINGZ _        ' __in LPCWSTR pszStreamBufferFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRecorder ( _                            ' VTable offset = 16
     BYREF pszFilename AS WSTRINGZ _                    ' __in LPCWSTR pszFilename
   , BYVAL dwRecordType AS DWORD _                      ' __in DWORD dwRecordType
   , BYREF pRecordingIUnknown AS IUnknown _             ' __out IUnknown **pRecordingIUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsProfileLocked ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferSink_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferSink2 interface
' IID = DB94A660-F4FB-4bfa-BCC6-FE159A4EEA93
' Inherited interface = IStreamBufferSink
' ########################################################################################

#IF NOT %DEF(%IStreamBufferSink2_INTERFACE_DEFINED)
    %IStreamBufferSink2_INTERFACE_DEFINED = 1

$IID_IStreamBufferSink2 = GUID$("{DB94A660-F4FB-4bfa-BCC6-FE159A4EEA93}")

INTERFACE IStreamBufferSink2 $IID_IStreamBufferSink2

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamBufferSink Methods
   ' =====================================================================================
   METHOD LockProfile ( _                               ' VTable offset = 12
     BYREF pszStreamBufferFilename AS WSTRINGZ _        ' __in LPCWSTR pszStreamBufferFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRecorder ( _                            ' VTable offset = 16
     BYREF pszFilename AS WSTRINGZ _                    ' __in LPCWSTR pszFilename
   , BYVAL dwRecordType AS DWORD _                      ' __in DWORD dwRecordType
   , BYREF pRecordingIUnknown AS IUnknown _             ' __out IUnknown **pRecordingIUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsProfileLocked ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferSink2 Methods
   ' =====================================================================================
   METHOD UnlockProfile ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferSink2_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferSink3 interface
' IID = 974723F2-887A-4452-9366-2CFF3057BC8F
' Inherited interface = IStreamBufferSink2
' ########################################################################################

#IF NOT %DEF(%IStreamBufferSink3_INTERFACE_DEFINED)
    %IStreamBufferSink3_INTERFACE_DEFINED = 1

$IID_IStreamBufferSink3 = GUID$("{974723F2-887A-4452-9366-2CFF3057BC8F}")

INTERFACE IStreamBufferSink3 $IID_IStreamBufferSink3

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamBufferSink Methods
   ' =====================================================================================
   METHOD LockProfile ( _                               ' VTable offset = 12
     BYREF pszStreamBufferFilename AS WSTRINGZ _        ' __in LPCWSTR pszStreamBufferFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRecorder ( _                            ' VTable offset = 16
     BYREF pszFilename AS WSTRINGZ _                    ' __in LPCWSTR pszFilename
   , BYVAL dwRecordType AS DWORD _                      ' __in DWORD dwRecordType
   , BYREF pRecordingIUnknown AS IUnknown _             ' __out IUnknown **pRecordingIUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsProfileLocked ( _                           ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferSink2 Methods
   ' =====================================================================================
   METHOD UnlockProfile ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferSink3 Methods
   ' =====================================================================================
   METHOD SetAvailableFilter ( _                        ' VTable offset = 28
     BYREF prtMin AS QUAD _                             ' __inout REFERENCE_TIME *prtMin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferSink3_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferSource interface
' IID = 1C5BD776-6CED-4F44-8164-5EAB0E98DB12
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferSource_INTERFACE_DEFINED)
    %IStreamBufferSource_INTERFACE_DEFINED = 1

$IID_IStreamBufferSource = GUID$("{1C5BD776-6CED-4F44-8164-5EAB0E98DB12}")

INTERFACE IStreamBufferSource $IID_IStreamBufferSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetStreamSink ( _                             ' VTable offset = 12
     BYVAL pIStreamBufferSink AS IStreamBufferSink _    ' __in IStreamBufferSink *pIStreamBufferSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferSource_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferRecordControl interface
' IID = BA9B6C99-F3C7-4FF2-92DB-CFDD4851BF31
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferRecordControl_INTERFACE_DEFINED)
    %IStreamBufferRecordControl_INTERFACE_DEFINED = 1

$IID_IStreamBufferRecordControl = GUID$("{BA9B6C99-F3C7-4FF2-92DB-CFDD4851BF31}")

INTERFACE IStreamBufferRecordControl $IID_IStreamBufferRecordControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
     BYREF prtStart AS QUAD _                           ' __inout REFERENCE_TIME *prtStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
     BYVAL rtStop AS QUAD _                             ' __in REFERENCE_TIME rtStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordingStatus ( _                        ' VTable offset = 20
     BYREF phResult AS LONG _                           ' __out HRESULT *phResult
   , BYREF pbStarted AS LONG _                          ' __out BOOL *pbStarted
   , BYREF pbStopped AS LONG _                          ' __out BOOL *pbStopped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferRecordControl_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferRecComp interface
' IID = 9E259A9B-8815-42AE-B09F-221970B154FD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferRecComp_INTERFACE_DEFINED)
    %IStreamBufferRecComp_INTERFACE_DEFINED = 1

$IID_IStreamBufferRecComp = GUID$("{9E259A9B-8815-42AE-B09F-221970B154FD}")

INTERFACE IStreamBufferRecComp $IID_IStreamBufferRecComp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszTargetFilename AS WSTRINGZ _              ' __in LPCWSTR pszTargetFilename
   , BYREF pszSBRecProfileRef AS WSTRINGZ _             ' __in LPCWSTR pszSBRecProfileRef
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 16
     BYREF pszSBRecording AS WSTRINGZ _                 ' __in LPCWSTR pszSBRecording
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendEx ( _                                  ' VTable offset = 20
     BYREF pszSBRecording AS WSTRINGZ _                 ' __in LPCWSTR pszSBRecording
   , BYVAL rtStart AS QUAD _                            ' __in REFERENCE_TIME rtStart
   , BYVAL rtStop AS QUAD _                             ' __in REFERENCE_TIME rtStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLength ( _                          ' VTable offset = 24
     BYREF pcSeconds AS DWORD _                         ' __out DWORD *pcSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferRecComp_INTERFACE_DEFINED__ */


'////////////////////////////////////////////////////////////////
'//
'// List of pre-defined attributes
'//

$$g_wszStreamBufferRecordingDuration = "Duration"$$
$$g_wszStreamBufferRecordingBitrate = "Bitrate"$$
$$g_wszStreamBufferRecordingSeekable = "Seekable"$$
$$g_wszStreamBufferRecordingStridable = "Stridable"$$
$$g_wszStreamBufferRecordingBroadcast = "Broadcast"$$
$$g_wszStreamBufferRecordingProtected = "Is_Protected"$$
$$g_wszStreamBufferRecordingTrusted = "Is_Trusted"$$
$$g_wszStreamBufferRecordingSignature_Name = "Signature_Name"$$
$$g_wszStreamBufferRecordingHasAudio = "HasAudio"$$
$$g_wszStreamBufferRecordingHasImage = "HasImage"$$
$$g_wszStreamBufferRecordingHasScript = "HasScript"$$
$$g_wszStreamBufferRecordingHasVideo = "HasVideo"$$
$$g_wszStreamBufferRecordingCurrentBitrate = "CurrentBitrate"$$
$$g_wszStreamBufferRecordingOptimalBitrate = "OptimalBitrate"$$
$$g_wszStreamBufferRecordingHasAttachedImages = "HasAttachedImages"$$
$$g_wszStreamBufferRecordingSkipBackward = "Can_Skip_Backward"$$
$$g_wszStreamBufferRecordingSkipForward = "Can_Skip_Forward"$$
$$g_wszStreamBufferRecordingNumberOfFrames = "NumberOfFrames"$$
$$g_wszStreamBufferRecordingFileSize = "FileSize"$$
$$g_wszStreamBufferRecordingHasArbitraryDataStream = "HasArbitraryDataStream"$$
$$g_wszStreamBufferRecordingHasFileTransferStream = "HasFileTransferStream"$$

'////////////////////////////////////////////////////////////////
'//
'// The content description object supports 5 basic attributes.
'//

$$g_wszStreamBufferRecordingTitle = "Title"$$
$$g_wszStreamBufferRecordingAuthor = "Author"$$
$$g_wszStreamBufferRecordingDescription = "Description"$$
$$g_wszStreamBufferRecordingRating = "Rating"$$
$$g_wszStreamBufferRecordingCopyright = "Copyright"$$

'////////////////////////////////////////////////////////////////
'//
'// These attributes are used to configure DRM using IWMDRMWriter::SetDRMAttribute.
'//

$$g_wszStreamBufferRecordingUse_DRM = "Use_DRM"$$
$$g_wszStreamBufferRecordingDRM_Flags = "DRM_Flags"$$
$$g_wszStreamBufferRecordingDRM_Level = "DRM_Level"$$

'////////////////////////////////////////////////////////////////
'//
'// These are the additional attributes defined in the WM attribute
'// namespace that give information about the content.
'//

$$g_wszStreamBufferRecordingAlbumTitle = "WM/AlbumTitle"$$
$$g_wszStreamBufferRecordingTrack = "WM/Track"$$
$$g_wszStreamBufferRecordingPromotionURL = "WM/PromotionURL"$$
$$g_wszStreamBufferRecordingAlbumCoverURL = "WM/AlbumCoverURL"$$
$$g_wszStreamBufferRecordingGenre = "WM/Genre"$$
$$g_wszStreamBufferRecordingYear = "WM/Year"$$
$$g_wszStreamBufferRecordingGenreID = "WM/GenreID"$$
$$g_wszStreamBufferRecordingMCDI = "WM/MCDI"$$
$$g_wszStreamBufferRecordingComposer = "WM/Composer"$$
$$g_wszStreamBufferRecordingLyrics = "WM/Lyrics"$$
$$g_wszStreamBufferRecordingTrackNumber = "WM/TrackNumber"$$
$$g_wszStreamBufferRecordingToolName = "WM/ToolName"$$
$$g_wszStreamBufferRecordingToolVersion = "WM/ToolVersion"$$
$$g_wszStreamBufferRecordingIsVBR = "IsVBR"$$
$$g_wszStreamBufferRecordingAlbumArtist = "WM/AlbumArtist"$$

'////////////////////////////////////////////////////////////////
'//
'// These optional attributes may be used to give information
'// about the branding of the content.
'//

$$g_wszStreamBufferRecordingBannerImageType = "BannerImageType"$$
$$g_wszStreamBufferRecordingBannerImageData = "BannerImageData"$$
$$g_wszStreamBufferRecordingBannerImageURL = "BannerImageURL"$$
$$g_wszStreamBufferRecordingCopyrightURL = "CopyrightURL"$$

'////////////////////////////////////////////////////////////////
'//
'// Optional attributes, used to give information
'// about video stream properties.
'//

$$g_wszStreamBufferRecordingAspectRatioX = "AspectRatioX"$$
$$g_wszStreamBufferRecordingAspectRatioY = "AspectRatioY"$$

'////////////////////////////////////////////////////////////////
'//
'// The NSC file supports the following attributes.
'//

$$g_wszStreamBufferRecordingNSCName = "NSC_Name"$$
$$g_wszStreamBufferRecordingNSCAddress = "NSC_Address"$$
$$g_wszStreamBufferRecordingNSCPhone = "NSC_Phone"$$
$$g_wszStreamBufferRecordingNSCEmail = "NSC_Email"$$
$$g_wszStreamBufferRecordingNSCDescription = "NSC_Description"$$

' DECLSPEC_UUID("99038221-f409-4d44-8313-bff73269a85e")
' enum STREAMBUFFER_ATTR_DATATYPE
%STREAMBUFFER_TYPE_DWORD  = 0
%STREAMBUFFER_TYPE_STRING = 1
%STREAMBUFFER_TYPE_BINARY = 2
%STREAMBUFFER_TYPE_BOOL   = 3
%STREAMBUFFER_TYPE_QWORD  = 4
%STREAMBUFFER_TYPE_WORD   = 5
%STREAMBUFFER_TYPE_GUID   = 6


' ########################################################################################
' IStreamBufferRecordingAttribute interface
' IID = 16CA4E03-FE69-4705-BD41-5B7DFC0C95F3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferRecordingAttribute_INTERFACE_DEFINED)
    %IStreamBufferRecordingAttribute_INTERFACE_DEFINED = 1

$IID_IStreamBufferRecordingAttribute = GUID$("{16CA4E03-FE69-4705-BD41-5B7DFC0C95F3}")

INTERFACE IStreamBufferRecordingAttribute $IID_IStreamBufferRecordingAttribute

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAttribute ( _                              ' VTable offset = 12
     BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   , BYREF pszAttributeName AS WSTRINGZ _               ' __in LPCWSTR pszAttributeName
   , BYVAL StreamBufferAttributeType AS LONG _          ' __in STREAMBUFFER_ATTR_DATATYPE StreamBufferAttributeType
   , BYVAL pbAttribute AS BYTE PTR _                    ' __in BYTE *pbAttribute
   , BYVAL cbAttributeLength AS WORD _                  ' __in WORD cbAttributeLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeCount ( _                         ' VTable offset = 16
     BYVAL ulReserved AS DWORD _                        ' __in ULONG ulReserved
   , BYREF pcAttributes AS WORD _                       ' __out WORD *pcAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeByName ( _                        ' VTable offset = 20
     BYREF pszAttributeName AS WSTRINGZ _               ' __in LPCWSTR pszAttributeName
   , BYREF pulReserved AS DWORD _                       ' __in ULONG *pulReserved
   , BYREF pStreamBufferAttributeType AS LONG _         ' __out STREAMBUFFER_ATTR_DATATYPE *pStreamBufferAttributeType
   , BYREF pbAttribute AS DWORD _                       ' __out BYTE *pbAttribute
   , BYREF pcbLength AS WORD _                          ' __inout WORD *pcbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributeByIndex ( _                       ' VTable offset = 24
     BYVAL wIndex AS WORD _                             ' __in WORD wIndex
   , BYREF pulReserved AS DWORD _                       ' __in ULONG *pulReserved
   , BYREF pszAttributeName AS WSTRINGZ _               ' __out WCHAR *pszAttributeName
   , BYREF pcchNameLength AS WORD _                     ' __inout *pcchNameLength
   , BYREF pStreamBufferAttributeType AS LONG _         ' __out STREAMBUFFER_ATTR_DATATYPE *pStreamBufferAttributeType
   , BYREF pbAttribute AS DWORD _                       ' __out BYTE *pbAttribute
   , BYREF pcbLength AS WORD _                          ' __inout WORD *pcbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumAttributes ( _                            ' VTable offset = 28
     BYREF ppIEnumStreamBufferAttrib AS IEnumStreamBufferRecordingAttrib _ ' __out IEnumStreamBufferRecordingAttrib **ppIEnumStreamBufferAttrib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferRecordingAttribute_INTERFACE_DEFINED__ */


' // Size = 16 bytes
TYPE STREAMBUFFER_ATTRIBUTE DWORD
   pszName                   AS WSTRINGZ PTR   ' LPWSTR
   StreamBufferAttributeType AS LONG           ' STREAMBUFFER_ATTR_DATATYPE
   pbAttribute               AS BYTE PTR       ' BYTE*
   cbLength                  AS WORD           ' WORD
END TYPE


' ########################################################################################
' IEnumStreamBufferRecordingAttrib interface
' IID = C18A9162-1E82-4142-8C73-5690FA62FE33
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumStreamBufferRecordingAttrib_INTERFACE_DEFINED)
    %IEnumStreamBufferRecordingAttrib_INTERFACE_DEFINED = 1

$IID_IEnumStreamBufferRecordingAttrib = GUID$("{C18A9162-1E82-4142-8C73-5690FA62FE33}")

INTERFACE IEnumStreamBufferRecordingAttrib $IID_IEnumStreamBufferRecordingAttrib

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pStreamBufferAttribute AS STREAMBUFFER_ATTRIBUTE _ ' __inout STREAMBUFFER_ATTRIBUTE *pStreamBufferAttribute
   , BYREF pcReceived AS DWORD _                        ' __out ULONG *pcReceived
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cRecords AS DWORD _                          ' __in ULONG cRecords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumStreamBufferAttrib AS IEnumStreamBufferRecordingAttrib _ ' __out IEnumStreamBufferRecordingAttrib **ppIEnumStreamBufferAttrib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumStreamBufferRecordingAttrib_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferConfigure interface
' IID = CE14DFAE-4098-4AF7-BBF7-D6511F835414
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferConfigure_INTERFACE_DEFINED)
    %IStreamBufferConfigure_INTERFACE_DEFINED = 1

$IID_IStreamBufferConfigure = GUID$("{CE14DFAE-4098-4AF7-BBF7-D6511F835414}")

INTERFACE IStreamBufferConfigure $IID_IStreamBufferConfigure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDirectory ( _                              ' VTable offset = 12
     BYREF pszDirectoryName AS WSTRINGZ _               ' __in LPCWSTR pszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectory ( _                              ' VTable offset = 16
     BYREF ppszDirectoryName AS DWORD _                 ' __out LPWSTR *ppszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileCount ( _                       ' VTable offset = 20
     BYVAL dwMin AS DWORD _                             ' __in DWORD dwMin
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileCount ( _                       ' VTable offset = 24
     BYREF pdwMin AS DWORD _                            ' __out DWORD *pdwMin
   , BYREF pdwMax AS DWORD _                            ' __out DWORD *pdwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileDuration ( _                    ' VTable offset = 28
     BYVAL dwSeconds AS DWORD _                         ' __in DWORD dwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileDuration ( _                    ' VTable offset = 32
     BYREF pdwSeconds AS DWORD _                        ' __out DWORD *pdwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferConfigure_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferConfigure2 interface
' IID = 53E037BF-3992-4282-AE34-2487B4DAE06B
' Inherited interface = IStreamBufferConfigure
' ########################################################################################

#IF NOT %DEF(%IStreamBufferConfigure2_INTERFACE_DEFINED)
    %IStreamBufferConfigure2_INTERFACE_DEFINED = 1

$IID_IStreamBufferConfigure2 = GUID$("{53E037BF-3992-4282-AE34-2487B4DAE06B}")

INTERFACE IStreamBufferConfigure2 $IID_IStreamBufferConfigure2

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamBufferConfigure Methods
   ' =====================================================================================
   METHOD SetDirectory ( _                              ' VTable offset = 12
     BYREF pszDirectoryName AS WSTRINGZ _               ' __in LPCWSTR pszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectory ( _                              ' VTable offset = 16
     BYREF ppszDirectoryName AS DWORD _                 ' __out LPWSTR *ppszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileCount ( _                       ' VTable offset = 20
     BYVAL dwMin AS DWORD _                             ' __in DWORD dwMin
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileCount ( _                       ' VTable offset = 24
     BYREF pdwMin AS DWORD _                            ' __out DWORD *pdwMin
   , BYREF pdwMax AS DWORD _                            ' __out DWORD *pdwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileDuration ( _                    ' VTable offset = 28
     BYVAL dwSeconds AS DWORD _                         ' __in DWORD dwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileDuration ( _                    ' VTable offset = 32
     BYREF pdwSeconds AS DWORD _                        ' __out DWORD *pdwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferConfigure2 Methods
   ' =====================================================================================
   METHOD SetMultiplexedPacketSize ( _                  ' VTable offset = 36
     BYVAL cbBytesPerPacket AS DWORD _                  ' __in DWORD cbBytesPerPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMultiplexedPacketSize ( _                  ' VTable offset = 40
     BYREF pcbBytesPerPacket AS DWORD _                 ' __out DWORD *pcbBytesPerPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFFTransitionRates ( _                      ' VTable offset = 44
     BYVAL dwMaxFullFrameRate AS DWORD _                ' __in DWORD dwMaxFullFrameRate
   , BYVAL dwMaxNonSkippingRate AS DWORD _              ' __in DWORD dwMaxNonSkippingRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFFTransitionRates ( _                      ' VTable offset = 48
     BYREF pdwMaxFullFrameRate AS DWORD _               ' __out DWORD *pdwMaxFullFrameRate
   , BYREF pdwMaxNonSkippingRate AS DWORD _             ' __out DWORD *pdwMaxNonSkippingRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferConfigure2_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferConfigure3 interface
' IID = 7E2D2A1E-7192-4BD7-80C1-061FD1D10402
' Inherited interface = IStreamBufferConfigure2
' ########################################################################################

#IF NOT %DEF(%IStreamBufferConfigure3_INTERFACE_DEFINED)
    %IStreamBufferConfigure3_INTERFACE_DEFINED = 1

$IID_IStreamBufferConfigure3 = GUID$("{7E2D2A1E-7192-4BD7-80C1-061FD1D10402}")

INTERFACE IStreamBufferConfigure3 $IID_IStreamBufferConfigure3

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamBufferConfigure Methods
   ' =====================================================================================
   METHOD SetDirectory ( _                              ' VTable offset = 12
     BYREF pszDirectoryName AS WSTRINGZ _               ' __in LPCWSTR pszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDirectory ( _                              ' VTable offset = 16
     BYREF ppszDirectoryName AS DWORD _                 ' __out LPWSTR *ppszDirectoryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileCount ( _                       ' VTable offset = 20
     BYVAL dwMin AS DWORD _                             ' __in DWORD dwMin
   , BYVAL dwMax AS DWORD _                             ' __in DWORD dwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileCount ( _                       ' VTable offset = 24
     BYREF pdwMin AS DWORD _                            ' __out DWORD *pdwMin
   , BYREF pdwMax AS DWORD _                            ' __out DWORD *pdwMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackingFileDuration ( _                    ' VTable offset = 28
     BYVAL dwSeconds AS DWORD _                         ' __in DWORD dwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackingFileDuration ( _                    ' VTable offset = 32
     BYREF pdwSeconds AS DWORD _                        ' __out DWORD *pdwSeconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferConfigure2 Methods
   ' =====================================================================================
   METHOD SetMultiplexedPacketSize ( _                  ' VTable offset = 36
     BYVAL cbBytesPerPacket AS DWORD _                  ' __in DWORD cbBytesPerPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMultiplexedPacketSize ( _                  ' VTable offset = 40
     BYREF pcbBytesPerPacket AS DWORD _                 ' __out DWORD *pcbBytesPerPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFFTransitionRates ( _                      ' VTable offset = 44
     BYVAL dwMaxFullFrameRate AS DWORD _                ' __in DWORD dwMaxFullFrameRate
   , BYVAL dwMaxNonSkippingRate AS DWORD _              ' __in DWORD dwMaxNonSkippingRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFFTransitionRates ( _                      ' VTable offset = 48
     BYREF pdwMaxFullFrameRate AS DWORD _               ' __out DWORD *pdwMaxFullFrameRate
   , BYREF pdwMaxNonSkippingRate AS DWORD _             ' __out DWORD *pdwMaxNonSkippingRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferConfigure3 Methods
   ' =====================================================================================
   METHOD SetStartRecConfig ( _                         ' VTable offset = 52
     BYVAL fStartStopsCur AS LONG _                     ' __in BOOL fStartStopsCur
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartRecConfig ( _                         ' VTable offset = 56
     BYREF pfStartStopsCur AS LONG _                    ' __out BOOL *pfStartStopsCur
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNamespace ( _                              ' VTable offset = 60
     BYREF pszNamespace AS WSTRINGZ _                   ' __in LPWSTR pszNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNamespace ( _                              ' VTable offset = 64
     BYREF ppszNamespace AS DWORD _                     ' __out LPWSTR *ppszNamespace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferConfigure3_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferMediaSeeking interface
' IID = F61F5C26-863D-4AFA-B0BA-2F81DC978596
' Inherited interface = IMediaSeeking
' ########################################################################################

#IF NOT %DEF(%IStreamBufferMediaSeeking_INTERFACE_DEFINED)
    %IStreamBufferMediaSeeking_INTERFACE_DEFINED = 1

$IID_IStreamBufferMediaSeeking = GUID$("{F61F5C26-863D-4AFA-B0BA-2F81DC978596}")

INTERFACE IStreamBufferMediaSeeking $IID_IStreamBufferMediaSeeking

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF pCapabilities AS DWORD _                     ' __out DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckCapabilities ( _                         ' VTable offset = 16
     BYREF pCapabilities AS DWORD _                     ' __inout DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFormatSupported ( _                         ' VTable offset = 20
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPreferredFormat ( _                      ' VTable offset = 24
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeFormat ( _                             ' VTable offset = 28
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUsingTimeFormat ( _                         ' VTable offset = 32
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeFormat ( _                             ' VTable offset = 36
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 40
     BYREF pDuration AS QUAD _                          ' __out LONGLONG *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStopPosition ( _                           ' VTable offset = 44
     BYREF pStop AS QUAD _                              ' __out LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 48
     BYREF pCurrent AS QUAD _                           ' __out LONGLONG *pCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertTimeFormat ( _                         ' VTable offset = 52
     BYREF pTarget AS QUAD _                            ' __out LONGLONG *pTarget
   , BYREF pTargetFormat AS GUID _                      ' __in const GUID *pTargetFormat
   , BYVAL Source AS QUAD _                             ' __in LONGLONG Source
   , BYREF pSourceFormat AS GUID _                      ' __in const GUID *pSourceFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPositions ( _                              ' VTable offset = 56
     BYREF pCurrent AS QUAD _                           ' __inout LONGLONG *pCurrent
   , BYVAL dwCurrentFlags AS DWORD _                    ' __in DWORD dwCurrentFlags
   , BYREF pStop AS QUAD _                              ' __inout LONGLONG *pStop
   , BYVAL dwStopFlags AS DWORD _                       ' __in DWORD dwStopFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositions ( _                              ' VTable offset = 60
     BYREF pCurrent AS QUAD _                           ' __out LONGLONG *pCurrent
   , BYREF pStop AS QUAD _                              ' __out LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailable ( _                              ' VTable offset = 64
     BYREF pEarliest AS QUAD _                          ' __out LONGLONG *pEarliest
   , BYREF pLatest AS QUAD _                            ' __out LONGLONG *pLatest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRate ( _                                   ' VTable offset = 68
     BYVAL dRate AS DOUBLE _                            ' __in double dRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 72
     BYREF pdRate AS DOUBLE _                           ' __out double *pdRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreroll ( _                                ' VTable offset = 76
     BYREF pllPreroll AS QUAD _                         ' __out LONGLONG *pllPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferMediaSeeking_INTERFACE_DEFINED__ */

' ########################################################################################
' IStreamBufferMediaSeeking2 interface
' IID = 3A439AB0-155F-470A-86A6-9EA54AFD6EAF
' Inherited interface = IStreamBufferMediaSeeking
' ########################################################################################

#IF NOT %DEF(%IStreamBufferMediaSeeking2_INTERFACE_DEFINED)
    %IStreamBufferMediaSeeking2_INTERFACE_DEFINED = 1

$IID_IStreamBufferMediaSeeking2 = GUID$("{3A439AB0-155F-470A-86A6-9EA54AFD6EAF}")

INTERFACE IStreamBufferMediaSeeking2 $IID_IStreamBufferMediaSeeking2

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamBufferMediaSeeking Methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF pCapabilities AS DWORD _                     ' __out DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckCapabilities ( _                         ' VTable offset = 16
     BYREF pCapabilities AS DWORD _                     ' __inout DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFormatSupported ( _                         ' VTable offset = 20
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPreferredFormat ( _                      ' VTable offset = 24
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeFormat ( _                             ' VTable offset = 28
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUsingTimeFormat ( _                         ' VTable offset = 32
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeFormat ( _                             ' VTable offset = 36
     BYREF pFormat AS GUID _                            ' __in const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 40
     BYREF pDuration AS QUAD _                          ' __out LONGLONG *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStopPosition ( _                           ' VTable offset = 44
     BYREF pStop AS QUAD _                              ' __out LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 48
     BYREF pCurrent AS QUAD _                           ' __out LONGLONG *pCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertTimeFormat ( _                         ' VTable offset = 52
     BYREF pTarget AS QUAD _                            ' __out LONGLONG *pTarget
   , BYREF pTargetFormat AS GUID _                      ' __in const GUID *pTargetFormat
   , BYVAL Source AS QUAD _                             ' __in LONGLONG Source
   , BYREF pSourceFormat AS GUID _                      ' __in const GUID *pSourceFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPositions ( _                              ' VTable offset = 56
     BYREF pCurrent AS QUAD _                           ' __inout LONGLONG *pCurrent
   , BYVAL dwCurrentFlags AS DWORD _                    ' __in DWORD dwCurrentFlags
   , BYREF pStop AS QUAD _                              ' __inout LONGLONG *pStop
   , BYVAL dwStopFlags AS DWORD _                       ' __in DWORD dwStopFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositions ( _                              ' VTable offset = 60
     BYREF pCurrent AS QUAD _                           ' __out LONGLONG *pCurrent
   , BYREF pStop AS QUAD _                              ' __out LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailable ( _                              ' VTable offset = 64
     BYREF pEarliest AS QUAD _                          ' __out LONGLONG *pEarliest
   , BYREF pLatest AS QUAD _                            ' __out LONGLONG *pLatest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRate ( _                                   ' VTable offset = 68
     BYVAL dRate AS DOUBLE _                            ' __in double dRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 72
     BYREF pdRate AS DOUBLE _                           ' __out double *pdRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreroll ( _                                ' VTable offset = 76
     BYREF pllPreroll AS QUAD _                         ' __out LONGLONG *pllPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamBufferMediaSeeking2 Methods
   ' =====================================================================================
   METHOD SetRateEx ( _                                 ' VTable offset = 80
     BYVAL dRate AS DOUBLE _                            ' __in double dRate
   , BYVAL dwFramesPerSec AS DWORD _                    ' __in DWORD dwFramesPerSec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferMediaSeeking2_INTERFACE_DEFINED__ */


' // Size = 40 bytes
TYPE SBE_PIN_DATA QWORD
   cDataBytes        AS QUAD   ' ULONGLONG
   cSamplesProcessed AS QUAD   ' ULONGLONG
   cDiscontinuities  AS QUAD   ' ULONGLONG
   cSyncPoints       AS QUAD   ' ULONGLONG
   cTimestamps       AS QUAD   ' ULONGLONG
END TYPE


' ########################################################################################
' IStreamBufferDataCounters interface
' IID = 9D2A2563-31AB-402E-9A6B-ADB903489440
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBufferDataCounters_INTERFACE_DEFINED)
    %IStreamBufferDataCounters_INTERFACE_DEFINED = 1

$IID_IStreamBufferDataCounters = GUID$("{9D2A2563-31AB-402E-9A6B-ADB903489440}")

INTERFACE IStreamBufferDataCounters $IID_IStreamBufferDataCounters

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetData ( _                                   ' VTable offset = 12
     BYREF pPinData AS SBE_PIN_DATA _                   ' __out SBE_PIN_DATA *pPinData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetData ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamBufferDataCounters_INTERFACE_DEFINED__ */


%STREAMBUFFER_EC_BASE = &H0326

' enum
' //  timehole event
' //      param1 = timehole stream offset ms
' //      param1 = timehole size ms
%STREAMBUFFER_EC_TIMEHOLE               = &H0326   ' %STREAMBUFFER_EC_BASE

%STREAMBUFFER_EC_STALE_DATA_READ        = &H0327

%STREAMBUFFER_EC_STALE_FILE_DELETED     = &H0328
%STREAMBUFFER_EC_CONTENT_BECOMING_STALE = &H0329
%STREAMBUFFER_EC_WRITE_FAILURE          = &H032A
%STREAMBUFFER_EC_WRITE_FAILURE_CLEAR    = &H032B
'//
'//  unexpected read failure
'//      param1 = HRESULT failure
'//      param2 = undefined
%STREAMBUFFER_EC_READ_FAILURE           = &H032B
'//
'//  playback rate change
'//      param1 = old_playback_rate * 10000 e.g. 2x is 20000
'//      param2 = new_playback_rate * 10000
%STREAMBUFFER_EC_RATE_CHANGED           = &H032C
'//
'//  index frame insertion notification
'//
%STREAMBUFFER_EC_PRIMARY_AUDIO          = &H032D
'//
'//  about to send playback rate change that is due to IMediaSeeking::SetPositions() call
'//      param1 = old_playback_rate * 10000 e.g. 2x is 20000
'//      param2 = new_playback_rate * 10000
%STREAMBUFFER_EC_RATE_CHANGING_FOR_SETPOSITIONS = &H032E
'//
'//  the work of a SetPositions() call has finished
'//      param1 = unused (set to 0 -- if uses are defined, they will be non-0)
'//      param2 = unused (set to 0 -- if uses are defined later, they will be non-0)
%STREAMBUFFER_EC_SETPOSITIONS_EVENTS_DONE = &H032F

$EVENTID_SBE2RecControlStarted = GUID$("{8966A89E-F83E-4c0e-BC3B-BFA7649E04CB}")
$EVENTID_SBE2RecControlStopped = GUID$("{454B1EC8-0C9B-4caa-B1A1-1E7A2666F6C3}")
$SBE2_STREAM_DESC_EVENT = GUID$("{2313a4ed-bf2d-454f-ad8a-d95ba7f91fee}")
$SBE2_V1_STREAMS_CREATION_EVENT = GUID$("{000FCF09-97F5-46ac-9769-7A83B35384FB}")
$SBE2_V2_STREAMS_CREATION_EVENT = GUID$("{A72530A3-0344-4cab-A2D0-FE937DBDCAB3}")

' enum CROSSBAR_DEFAULT_FLAGS
%DEF_MODE_PROFILE = &H0000001???
%DEF_MODE_STREAMS = &H0000002???

'typedef DWORD SBE2_STREAM_ID;

%SBE2_STREAM_DESC_VERSION = 1

' // Size = 16 bytes
TYPE SBE2_STREAM_DESC DWORD
   Version  AS DWORD   ' DWORD
   StreamId AS DWORD   ' SBE2_STREAM_ID
   Default  AS DWORD   ' DWORD
   Reserved AS DWORD   ' DWORD
END TYPE

' // Size = 124 bytes
TYPE DVR_STREAM_DESC DWORD
   Version          AS DWORD   ' DWORD
   StreamId         AS DWORD   ' DWORD
   Default          AS LONG    ' BOOL
   Creation         AS LONG    ' BOOL
   Reserved         AS DWORD   ' DWORD
   guidSubMediaType AS GUID    ' GUID
   guidFormatType   AS GUID    ' GUID
   MediaType        AS AM_MEDIA_TYPE
END TYPE

' ########################################################################################
' ISBE2GlobalEvent interface
' IID = caede759-b6b1-11db-a578-0018f3fa24c6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2GlobalEvent_INTERFACE_DEFINED)
    %ISBE2GlobalEvent_INTERFACE_DEFINED = 1

$IID_ISBE2GlobalEvent = GUID$("{caede759-b6b1-11db-a578-0018f3fa24c6}")

INTERFACE ISBE2GlobalEvent $IID_ISBE2GlobalEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYREF idEvt AS GUID _                              ' __in REFGUID idEvt
   , BYVAL param1 AS DWORD _                            ' __in ULONG param1
   , BYVAL param2 AS DWORD _                            ' __in ULONG param2
   , BYVAL param3 AS DWORD _                            ' __in ULONG param3
   , BYVAL param4 AS DWORD _                            ' __in ULONG param4
   , BYREF pSpanning AS LONG _                          ' __out BOOL *pSpanning
   , BYREF pcb AS DWORD _                               ' __inout DWORD *pcb
   , BYVAL pb AS BYTE PTR _                             ' __out BYTE *pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2GlobalEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2GlobalEvent2 interface
' IID = 6D8309BF-00FE-4506-8B03-F8C65B5C9B39
' Inherited interface = ISBE2GlobalEvent
' ########################################################################################

#IF NOT %DEF(%ISBE2GlobalEvent2_INTERFACE_DEFINED)
    %ISBE2GlobalEvent2_INTERFACE_DEFINED = 1

$IID_ISBE2GlobalEvent2 = GUID$("{6D8309BF-00FE-4506-8B03-F8C65B5C9B39}")

INTERFACE ISBE2GlobalEvent2 $IID_ISBE2GlobalEvent2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISBE2GlobalEvent method
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYREF idEvt AS GUID _                              ' __in REFGUID idEvt
   , BYVAL param1 AS DWORD _                            ' __in ULONG param1
   , BYVAL param2 AS DWORD _                            ' __in ULONG param2
   , BYVAL param3 AS DWORD _                            ' __in ULONG param3
   , BYVAL param4 AS DWORD _                            ' __in ULONG param4
   , BYREF pSpanning AS LONG _                          ' __out BOOL *pSpanning
   , BYREF pcb AS DWORD _                               ' __inout DWORD *pcb
   , BYVAL pb AS BYTE PTR _                             ' __out BYTE *pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISBE2GlobalEvent2 method
   ' =====================================================================================
   METHOD GetEventEx ( _                                ' VTable offset = 16
     BYREF idEvt AS GUID _                              ' __in REFGUID idEvt
   , BYVAL param1 AS DWORD _                            ' __in ULONG param1
   , BYVAL param2 AS DWORD _                            ' __in ULONG param2
   , BYVAL param3 AS DWORD _                            ' __in ULONG param3
   , BYVAL param4 AS DWORD _                            ' __in ULONG param4
   , BYREF pSpanning AS LONG _                          ' __out BOOL *pSpanning
   , BYREF pcb AS DWORD _                               ' __inout DWORD *pcb
   , BYVAL pb AS BYTE PTR _                             ' __out BYTE *pb
   , BYREF pStreamTime AS QUAD _                        ' __out REFERENCE_TIME *pStreamTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2GlobalEvent2_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2SpanningEvent interface
' IID = caede760-b6b1-11db-a578-0018f3fa24c6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2SpanningEvent_INTERFACE_DEFINED)
    %ISBE2SpanningEvent_INTERFACE_DEFINED = 1

$IID_ISBE2SpanningEvent = GUID$("{caede760-b6b1-11db-a578-0018f3fa24c6}")

INTERFACE ISBE2SpanningEvent $IID_ISBE2SpanningEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYREF idEvt AS GUID _                              ' __in REFGUID idEvt
   , BYVAL streamId AS DWORD _                          ' __in SBE2_STREAM_ID streamId
   , BYREF pcb AS DWORD _                               ' __inout DWORD *pcb
   , BYVAL pb AS BYTE PTR _                             ' __out BYTE *pb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2SpanningEvent_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2Crossbar interface
' IID = 547b6d26-3226-487e-8253-8aa168749434
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2Crossbar_INTERFACE_DEFINED)
    %ISBE2Crossbar_INTERFACE_DEFINED = 1

$IID_ISBE2Crossbar = GUID$("{547b6d26-3226-487e-8253-8aa168749434}")

INTERFACE ISBE2Crossbar $IID_ISBE2Crossbar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnableDefaultMode ( _                         ' VTable offset = 12
     BYVAL DefaultFlags AS DWORD _                      ' __in DWORD DefaultFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInitialProfile ( _                         ' VTable offset = 16
     BYREF ppProfile AS ISBE2MediaTypeProfile _         ' __out ISBE2MediaTypeProfile **ppProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputProfile ( _                          ' VTable offset = 20
     BYVAL pProfile AS ISBE2MediaTypeProfile _          ' __in ISBE2MediaTypeProfile *pProfile
   , BYREF pcOutputPins AS DWORD _                      ' __out DWORD *pcOutputPins
   , BYREF ppOutputPins AS IPin _                       ' __out IPin **ppOutputPins
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumStreams ( _                               ' VTable offset = 24
     BYREF ppStreams AS ISBE2EnumStream _               ' __out ISBE2EnumStream **ppStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2Crossbar_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2StreamMap interface
' IID = 667c7745-85b1-4c55-ae55-4e25056159fc
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2StreamMap_INTERFACE_DEFINED)
    %ISBE2StreamMap_INTERFACE_DEFINED = 1

$IID_ISBE2StreamMap = GUID$("{667c7745-85b1-4c55-ae55-4e25056159fc}")

INTERFACE ISBE2StreamMap $IID_ISBE2StreamMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MapStream ( _                                 ' VTable offset = 12
     BYVAL Stream AS DWORD _                            ' __in SBE2_STREAM_ID Stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmapStream ( _                               ' VTable offset = 16
     BYVAL Stream AS DWORD _                            ' __in SBE2_STREAM_ID Stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMappedStreams ( _                         ' VTable offset = 20
     BYREF ppStreams AS ISBE2EnumStream _               ' __out ISBE2EnumStream **ppStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2StreamMap_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2EnumStream interface
' IID = f7611092-9fbc-46ec-a7c7-548ea78b71a4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2EnumStream_INTERFACE_DEFINED)
    %ISBE2EnumStream_INTERFACE_DEFINED = 1

$IID_ISBE2EnumStream = GUID$("{f7611092-9fbc-46ec-a7c7-548ea78b71a4}")

INTERFACE ISBE2EnumStream $IID_ISBE2EnumStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in ULONG cRequest
   , BYREF pStreamDesc AS SBE2_STREAM_DESC _            ' __inout SBE2_STREAM_DESC *pStreamDesc
   , BYREF pcReceived AS DWORD _                        ' __out ULONG *pcReceived
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cRecords AS DWORD _                          ' __in ULONG cRecords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumStream AS ISBE2EnumStream _           ' __out ISBE2EnumStream **ppIEnumStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2EnumStream_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2MediaTypeProfile interface
' IID = f238267d-4671-40d7-997e-25dc32cfed2a
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2MediaTypeProfile_INTERFACE_DEFINED)
    %ISBE2MediaTypeProfile_INTERFACE_DEFINED = 1

$IID_ISBE2MediaTypeProfile = GUID$("{f238267d-4671-40d7-997e-25dc32cfed2a}")

INTERFACE ISBE2MediaTypeProfile $IID_ISBE2MediaTypeProfile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 12
     BYREF pCount AS DWORD _                            ' __out DWORD *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 16
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   , BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStream ( _                                 ' VTable offset = 20
     BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in AM_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteStream ( _                              ' VTable offset = 24
     BYVAL Index AS DWORD _                             ' __in DWORD Index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2MediaTypeProfile_INTERFACE_DEFINED__ */

' ########################################################################################
' ISBE2FileScan interface
' IID = 3E2BF5A5-4F96-4899-A1A3-75E8BE9A5AC0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISBE2FileScan_INTERFACE_DEFINED)
    %ISBE2FileScan_INTERFACE_DEFINED = 1

$IID_ISBE2FileScan = GUID$("{3E2BF5A5-4F96-4899-A1A3-75E8BE9A5AC0}")

INTERFACE ISBE2FileScan $IID_ISBE2FileScan

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RepairFile ( _                                ' VTable offset = 12
     BYREF filename AS WSTRINGZ _                       ' __in LPCWSTR filename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISBE2FileScan_INTERFACE_DEFINED__ */
