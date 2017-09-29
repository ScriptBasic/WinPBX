' ########################################################################################
' Microsoft Windows
' File: wmcontainer.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMCONTAINER_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "mfidl.inc"

' ########################################################################################
' Interface name = IMFASFContentInfo
' IID = B1DCA5CD-D5DA-4451-8E9E-DB5C59914EAD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFContentInfo_INTERFACE_DEFINED)
    %IMFASFContentInfo_INTERFACE_DEFINED = 1

$IID_IMFASFContentInfo = GUID$("{B1DCA5CD-D5DA-4451-8E9E-DB5C59914EAD}")

INTERFACE IMFASFContentInfo $IID_IMFASFContentInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHeaderSize ( _                             ' VTable offset = 12
     BYVAL pIStartOfContent AS IMFMediaBuffer _         ' __in IMFMediaBuffer *pIStartOfContent
   , BYREF cbHeaderSize AS QUAD _                       ' __out QWORD *cbHeaderSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseHeader ( _                               ' VTable offset = 16
     BYVAL pIHeaderBuffer AS IMFMediaBuffer _           ' __in IMFMediaBuffer *pIHeaderBuffer
   , BYVAL cbOffsetWithinHeader AS QUAD _               ' __in QWORD cbOffsetWithinHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateHeader ( _                            ' VTable offset = 20
     BYREF pIHeader AS IMFMediaBuffer _                 ' __in_out IMFMediaBuffer *pIHeader
   , BYREF pcbHeader AS DWORD _                         ' __out DWORD *pcbHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProfile ( _                                ' VTable offset = 24
     BYREF ppIProfile AS IMFASFProfile _                ' __out IMFASFProfile **ppIProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProfile ( _                                ' VTable offset = 28
     BYVAL pIProfile AS IMFASFProfile _                 ' __in IMFASFProfile *pIProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GeneratePresentationDescriptor ( _            ' VTable offset = 32
     BYREF ppIPresentationDescriptor AS IMFPresentationDescriptor _ ' __out IMFPresentationDescriptor **ppIPresentationDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEncodingConfigurationPropertyStore ( _     ' VTable offset = 36
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   , BYREF ppIStore AS IPropertyStore _                 ' __out IPropertyStore **ppIStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFContentInfo_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateASFContentInfo IMPORT "mf.dll" ALIAS "MFCreateASFContentInfo" ( _
   BYREF ppIContentInfo AS IMFASFContentInfo _          ' __out IMFASFContentInfo **ppIContentInfo
 ) AS LONG                                              ' HRESULT

'#define MFASF_MIN_HEADER_BYTES ( sizeof( GUID ) + sizeof( QWORD ) )
%MFASF_MIN_HEADER_BYTES = 24

$MF_PD_ASF_FILEPROPERTIES_FILE_ID = GUID$("{3DE649B4-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_CREATION_TIME = GUID$("{3DE649B6-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_PACKETS = GUID$("{3DE649B7-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_PLAY_DURATION = GUID$("{3DE649B8-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_SEND_DURATION = GUID$("{3DE649B9-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_PREROLL = GUID$("{3DE649BA-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_FLAGS = GUID$("{3DE649BB-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_MIN_PACKET_SIZE = GUID$("{3DE649BC-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_MAX_PACKET_SIZE = GUID$("{3DE649BD-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_FILEPROPERTIES_MAX_BITRATE = GUID$("{3DE649BE-D76D-4E66-9EC9-78120FB4C7E3}")
$MF_PD_ASF_CONTENTENCRYPTION_TYPE = GUID$("{8520FE3D-277E-46EA-99E4-E30A86DB12BE}")
$MF_PD_ASF_CONTENTENCRYPTION_KEYID = GUID$("{8520FE3E-277E-46EA-99E4-E30A86DB12BE}")
$MF_PD_ASF_CONTENTENCRYPTION_SECRET_DATA = GUID$("{8520FE3F-277E-46EA-99E4-E30A86DB12BE}")
$MF_PD_ASF_CONTENTENCRYPTION_LICENSE_URL = GUID$("{8520FE40-277E-46EA-99E4-E30A86DB12BE}")
$MF_PD_ASF_CONTENTENCRYPTIONEX_ENCRYPTION_DATA = GUID$("{62508BE5-ECDF-4924-A359-72BAB3397B9D}")
$MF_PD_ASF_LANGLIST = GUID$("{F23DE43C-9977-460D-A6EC-32937F160F7D}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_PD_ASF_LANGLIST_LEGACYORDER = GUID$("{f23de43d-9977-460d-a6ec-32937f160f7d}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
$MF_PD_ASF_MARKER = GUID$("{5134330E-83A6-475E-A9D5-4FB875FB2E31}")
$MF_PD_ASF_SCRIPT = GUID$("{E29CD0D7-D602-4923-A7FE-73FD97ECC650}")
$MF_PD_ASF_CODECLIST = GUID$("{E4BB3509-C18D-4DF1-BB99-7A36B3CC4119}")
$MF_PD_ASF_METADATA_IS_VBR = GUID$("{5FC6947A-EF60-445D-B449-442ECC78B4C1}")
$MF_PD_ASF_METADATA_V8_VBRPEAK = GUID$("{5FC6947B-EF60-445D-B449-442ECC78B4C1}")
$MF_PD_ASF_METADATA_V8_BUFFERAVERAGE = GUID$("{5FC6947C-EF60-445D-B449-442ECC78B4C1}")
$MF_PD_ASF_METADATA_LEAKY_BUCKET_PAIRS = GUID$("{5FC6947D-EF60-445D-B449-442ECC78B4C1}")
$MF_PD_ASF_DATA_START_OFFSET = GUID$("{E7D5B3E7-1F29-45D3-8822-3E78FAE272ED}")
$MF_PD_ASF_DATA_LENGTH = GUID$("{E7D5B3E8-1F29-45D3-8822-3E78FAE272ED}")
$MF_SD_ASF_EXTSTRMPROP_LANGUAGE_ID_INDEX = GUID$("{48F8A522-305D-422D-8524-2502DDA33680}")
$MF_SD_ASF_EXTSTRMPROP_AVG_DATA_BITRATE = GUID$("{48F8A523-305D-422D-8524-2502DDA33680}")
$MF_SD_ASF_EXTSTRMPROP_AVG_BUFFERSIZE = GUID$("{48F8A524-305D-422D-8524-2502DDA33680}")
$MF_SD_ASF_EXTSTRMPROP_MAX_DATA_BITRATE = GUID$("{48F8A525-305D-422D-8524-2502DDA33680}")
$MF_SD_ASF_EXTSTRMPROP_MAX_BUFFERSIZE = GUID$("{48F8A526-305D-422D-8524-2502DDA33680}")
$MF_SD_ASF_STREAMBITRATES_BITRATE = GUID$("{A8E182ED-AFC8-43D0-B0D1-F65BAD9DA558}")
$MF_SD_ASF_METADATA_DEVICE_CONFORMANCE_TEMPLATE = GUID$("{245E929D-C44E-4F7E-BB3C-77D4DFD27F8A}")
$MF_PD_ASF_INFO_HAS_AUDIO = GUID$("{80E62295-2296-4A44-B31C-D103C6FED23C}")
$MF_PD_ASF_INFO_HAS_VIDEO = GUID$("{80E62296-2296-4A44-B31C-D103C6FED23C}")
$MF_PD_ASF_INFO_HAS_NON_AUDIO_VIDEO = GUID$("{80E62297-2296-4A44-B31C-D103C6FED23C}")


' ########################################################################################
' Interface name = IMFASFProfile
' IID = D267BF6A-028B-4E0D-903D-43F0EF82D0D4
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFASFProfile_INTERFACE_DEFINED)
    %IMFASFProfile_INTERFACE_DEFINED = 1

$IID_IMFASFProfile = GUID$("{D267BF6A-028B-4E0D-903D-43F0EF82D0D4}")

INTERFACE IMFASFProfile $IID_IMFASFProfile

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFASFProfile methods
   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 132
     BYREF pcStreams AS DWORD _                         ' __out DWORD *pcStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 136
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF pwStreamNumber AS WORD _                     ' __out WORD *pwStreamNumber
   , BYREF ppIStream AS IMFASFStreamConfig _            ' __out IMFASFStreamConfig **ppIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamByNumber ( _                         ' VTable offset = 140
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   , BYREF ppIStream AS IMFASFStreamConfig _            ' __out IMFASFStreamConfig **ppIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStream ( _                                 ' VTable offset = 144
     BYVAL pIStream AS IMFASFStreamConfig _             ' __in IMFASFStreamConfig *pIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStream ( _                              ' VTable offset = 148
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 152
     BYVAL pIMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMediaType
   , BYREF ppIStream AS IMFASFStreamConfig _            ' __out IMFASFStreamConfig **ppIStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMutualExclusionCount ( _                   ' VTable offset = 156
     BYREF pcMutexs AS DWORD _                          ' __out DWORD *pcMutexs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMutualExclusion ( _                        ' VTable offset = 160
     BYVAL dwMutexIndex AS DWORD _                      ' __in DWORD dwMutexIndex
   , BYREF ppIMutex AS IMFASFMutualExclusion _          ' __out IMFASFMutualExclusion **ppIMutex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddMutualExclusion ( _                        ' VTable offset = 164
     BYVAL pIMutex AS IMFASFMutualExclusion _           ' __in IMFASFMutualExclusion *pIMutex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveMutualExclusion ( _                     ' VTable offset = 168
     BYVAL dwMutexIndex AS DWORD _                      ' __in DWORD dwMutexIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateMutualExclusion ( _                     ' VTable offset = 172
     BYREF ppIMutex AS IMFASFMutualExclusion _          ' __out IMFASFMutualExclusion **ppIMutex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamPrioritization ( _                   ' VTable offset = 176
     BYREF ppIStreamPrioritization AS IMFASFStreamPrioritization _ ' __out IMFASFStreamPrioritization **ppIStreamPrioritization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStreamPrioritization ( _                   ' VTable offset = 180
     BYVAL pIStreamPrioritization AS IMFASFStreamPrioritization _ ' __in IMFASFStreamPrioritization *pIStreamPrioritization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStreamPrioritization ( _                ' VTable offset = 184
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStreamPrioritization ( _                ' VTable offset = 188
     BYREF ppIStreamPrioritization AS IMFASFStreamPrioritization _ ' __out IMFASFStreamPrioritization **ppIStreamPrioritization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 192
     BYREF ppIProfile AS IMFASFProfile _                ' __out IMFASFProfile **ppIProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFProfile_INTERFACE_DEFINED__ */


$MF_ASFPROFILE_MINPACKETSIZE = GUID$("{22587626-47DE-4168-87F5-B5AA9B12A8F0}")
$MF_ASFPROFILE_MAXPACKETSIZE = GUID$("{22587627-47DE-4168-87F5-B5AA9B12A8F0}")

DECLARE FUNCTION MFCreateASFProfile IMPORT "mf.dll" ALIAS "MFCreateASFProfile" ( _
   BYREF ppIProfile AS IMFASFProfile _                  ' __out IMFASFProfile **ppIProfile
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFProfileFromPresentationDescriptor IMPORT "mf.dll" ALIAS "MFCreateASFProfileFromPresentationDescriptor" ( _
   BYVAL pIPD AS IMFPresentationDescriptor _            ' __in IMFPresentationDescriptor   *pIPD
 , BYREF ppIProfile AS IMFASFProfile _                  ' __out IMFASFProfile             **ppIProfile
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreatePresentationDescriptorFromASFProfile IMPORT "mf.dll" ALIAS "MFCreatePresentationDescriptorFromASFProfile" ( _
   BYVAL pIProfile AS IMFASFProfile _                   ' __in IMFASFProfile               *pIProfile
 , BYREF ppIPD AS IMFPresentationDescriptor _           ' __out IMFPresentationDescriptor **ppIPD
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFASFStreamConfig
' IID = 9E8AE8D2-DBBD-4200-9ACA-06E6DF484913
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFASFStreamConfig_INTERFACE_DEFINED)
    %IMFASFStreamConfig_INTERFACE_DEFINED = 1

$IID_IMFASFStreamConfig = GUID$("{9E8AE8D2-DBBD-4200-9ACA-06E6DF484913}")

INTERFACE IMFASFStreamConfig $IID_IMFASFStreamConfig

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFASFStreamConfig methods
   ' =====================================================================================
   METHOD GetStreamType ( _                             ' VTable offset = 132
     BYREF pguidStreamType AS GUID _                    ' __out GUID *pguidStreamType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamNumber ( _                           ' VTable offset = 136
   ) AS WORD                                            ' WORD
   ' =====================================================================================
   METHOD SetStreamNumber ( _                           ' VTable offset = 140
     BYVAL wStreamNum AS WORD _                         ' __in WORD wStreamNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaType ( _                              ' VTable offset = 144
     BYREF ppIMediaType AS IMFMediaType _               ' __out IMFMediaType **ppIMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 148
     BYVAL pIMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPayloadExtensionCount ( _                  ' VTable offset = 152
     BYREF pcPayloadExtensions AS WORD _                ' __out WORD *pcPayloadExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPayloadExtension ( _                       ' VTable offset = 156
     BYVAL wPayloadExtensionNumber AS WORD _            ' __in WORD wPayloadExtensionNumber
   , BYREF pguidExtensionSystemID AS GUID _             ' __out GUID *pguidExtensionSystemID
   , BYREF pcbExtensionDataSize AS WORD _               ' __out WORD *pcbExtensionDataSize
   , BYVAL pbExtensionSystemInfo AS BYTE PTR _          ' __opt_out BYTE *pbExtensionSystemInfo
   , BYREF pcbExtensionSystemInfo AS DWORD _            ' __opt_in_out DWORD *pcbExtensionSystemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPayloadExtension ( _                       ' VTable offset = 160
     BYREF guidExtensionSystemID AS GUID _              ' __in GUID guidExtensionSystemID
   , BYVAL cbExtensionDataSize AS WORD _                ' __in WORD cbExtensionDataSize
   , BYVAL pbExtensionSystemInfo AS BYTE PTR _          ' __in BYTE *pbExtensionSystemInfo
   , BYVAL cbExtensionSystemInfo AS DWORD _             ' __in DWORD cbExtensionSystemInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllPayloadExtensions ( _                ' VTable offset = 164
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 168
     BYREF ppIStreamConfig AS IMFASFStreamConfig _      ' __out IMFASFStreamConfig **ppIStreamConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFStreamConfig_INTERFACE_DEFINED__ */


$MF_ASFSTREAMCONFIG_LEAKYBUCKET1 = GUID$("{C69B5901-EA1A-4C9B-B692-E2A0D29A8ADD}")
$MF_ASFSTREAMCONFIG_LEAKYBUCKET2 = GUID$("{C69B5902-EA1A-4C9B-B692-E2A0D29A8ADD}")
$MFASFSampleExtension_SampleDuration = GUID$("{C6BD9450-867F-4907-83A3-C77921B733AD}")
$MFASFSampleExtension_OutputCleanPoint = GUID$("{F72A3C6F-6EB4-4EBC-B192-09AD9759E828}")
$MFASFSampleExtension_SMPTE = GUID$("{399595EC-8667-4E2D-8FDB-98814CE76C1E}")
$MFASFSampleExtension_FileName = GUID$("{E165EC0E-19ED-45D7-B4A7-25CBD1E28E9B}")
$MFASFSampleExtension_ContentType = GUID$("{D590DC20-07BC-436C-9CF7-F3BBFBF1A4DC}")
$MFASFSampleExtension_PixelAspectRatio = GUID$("{1B1EE554-F9EA-4BC8-821A-376B74E4C4B8}")
$MFASFSampleExtension_Encryption_SampleID = GUID$("{6698B84E-0AFA-4330-AEB2-1C0A98D7A44D}")
$MFASFSampleExtension_Encryption_KeyID = GUID$("{76376591-795F-4DA1-86ED-9D46ECA109A9}")


' ########################################################################################
' Interface name = IMFASFMutualExclusion
' IID = 12558291-E399-11D5-BC2A-00B0D0F3F4AB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFMutualExclusion_INTERFACE_DEFINED)
    %IMFASFMutualExclusion_INTERFACE_DEFINED = 1

$IID_IMFASFMutualExclusion = GUID$("{12558291-E399-11D5-BC2A-00B0D0F3F4AB}")

INTERFACE IMFASFMutualExclusion $IID_IMFASFMutualExclusion

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 12
     BYREF pguidType AS GUID _                          ' __out GUID *pguidType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRecordCount ( _                            ' VTable offset = 16
     BYREF pdwRecordCount AS DWORD _                    ' __out DWORD *pdwRecordCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamsForRecord ( _                       ' VTable offset = 20
     BYVAL dwRecordNumber AS DWORD _                    ' __in DWORD dwRecordNumber
   , BYREF pwStreamNumArray AS WORD _                   ' __out WORD *pwStreamNumArray
   , BYREF pcStreams AS DWORD _                         ' __in_out DWORD *pcStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStreamForRecord ( _                        ' VTable offset = 24
     BYVAL dwRecordNumber AS DWORD _                    ' __in DWORD dwRecordNumber
   , BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStreamFromRecord ( _                    ' VTable offset = 28
     BYVAL dwRecordNumber AS DWORD _                    ' __in DWORD dwRecordNumber
   , BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveRecord ( _                              ' VTable offset = 32
     BYVAL dwRecordNumber AS DWORD _                    ' __in DWORD dwRecordNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRecord ( _                                 ' VTable offset = 36
     BYREF pdwRecordNumber AS DWORD _                   ' __out DWORD *pdwRecordNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 40
     BYREF ppIMutex AS IMFASFMutualExclusion _          ' __out IMFASFMutualExclusion **ppIMutex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFMutualExclusion_INTERFACE_DEFINED__ */

$MFASFMutexType_Language = GUID$("{72178C2B-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFASFMutexType_Bitrate = GUID$("{72178C2C-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFASFMutexType_Presentation = GUID$("{72178C2D-E45B-11D5-BC2A-00B0D0F3F4AB}")
$MFASFMutexType_Unknown = GUID$("{72178C2E-E45B-11D5-BC2A-00B0D0F3F4AB}")


' ########################################################################################
' Interface name = IMFASFStreamPrioritization
' IID = 699BDC27-BBAF-49FF-8E38-9C39C9B5E088
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFStreamPrioritization_INTERFACE_DEFINED)
    %IMFASFStreamPrioritization_INTERFACE_DEFINED = 1

$IID_IMFASFStreamPrioritization = GUID$("{699BDC27-BBAF-49FF-8E38-9C39C9B5E088}")

INTERFACE IMFASFStreamPrioritization $IID_IMFASFStreamPrioritization

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 12
     BYREF pdwStreamCount AS DWORD _                    ' __out DWORD *pdwStreamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 16
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF pwStreamNumber AS WORD _                     ' __out WORD *pwStreamNumber
   , BYREF pwStreamFlags AS WORD _                      ' __out WORD *pwStreamFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStream ( _                                 ' VTable offset = 20
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   , BYVAL wStreamFlags AS WORD _                       ' __in WORD wStreamFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStream ( _                              ' VTable offset = 24
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 28
     BYREF ppIStreamPrioritization AS IMFASFStreamPrioritization _ ' __out IMFASFStreamPrioritization **ppIStreamPrioritization
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFStreamPrioritization_INTERFACE_DEFINED__ */


' enum MFASF_SPLITTERFLAGS
%MFASF_SPLITTER_REVERSE = &H1
%MFASF_SPLITTER_WMDRM   = &H2


' ########################################################################################
' Interface name = IMFASFSplitter
' IID = 12558295-E399-11D5-BC2A-00B0D0F3F4AB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFSplitter_INTERFACE_DEFINED)
    %IMFASFSplitter_INTERFACE_DEFINED = 1

$IID_IMFASFSplitter = GUID$("{12558295-E399-11D5-BC2A-00B0D0F3F4AB}")

INTERFACE IMFASFSplitter $IID_IMFASFSplitter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIContentInfo AS IMFASFContentInfo _         ' __in IMFASFContentInfo *pIContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 20
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectStreams ( _                             ' VTable offset = 24
     BYVAL pwStreamNumbers AS WORD _                    ' __in WORD *pwStreamNumbers
   , BYVAL wNumStreams AS WORD _                        ' __in WORD wNumStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedStreams ( _                        ' VTable offset = 28
     BYREF pwStreamNumbers AS WORD _                    ' __out WORD *pwStreamNumbers
   , BYREF pwNumStreams AS WORD _                       ' __in_out WORD *pwNumStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParseData ( _                                 ' VTable offset = 32
     BYVAL pIBuffer AS IMFMediaBuffer _                 ' __in IMFMediaBuffer *pIBuffer
   , BYVAL cbBufferOffset AS DWORD _                    ' __in DWORD cbBufferOffset
   , BYVAL cbLength AS DWORD _                          ' __in DWORD cbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextSample ( _                             ' VTable offset = 36
     BYREF pdwStatusFlags AS DWORD _                    ' __out DWORD *pdwStatusFlags
   , BYREF pwStreamNumber AS WORD _                     ' __out WORD *pwStreamNumber
   , BYREF ppISample AS IMFSample _                     ' __out IMFSample **ppISample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastSendTime ( _                           ' VTable offset = 44
     BYREF pdwLastSendTime AS DWORD _                   ' __out DWORD *pdwLastSendTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFSplitter_INTERFACE_DEFINED__ */


' enum ASF_STATUSFLAGS
%ASF_STATUSFLAGS_INCOMPLETE     = &H1
%ASF_STATUSFLAGS_NONFATAL_ERROR = &H2

$MFASFSPLITTER_PACKET_BOUNDARY = GUID$("{FE584A05-E8D6-42E3-B176-F1211705FB6F}")

DECLARE FUNCTION MFCreateASFSplitter IMPORT "mf.dll" ALIAS "MFCreateASFSplitter" ( _
   BYREF ppISplitter AS IMFASFSplitter _                ' __out IMFASFSplitter **ppISplitter
 ) AS LONG                                              ' HRESULT

' enum MFASF_MULTIPLEXERFLAGS
%MFASF_MULTIPLEXER_AUTOADJUST_BITRATE = &H1

' // Size = 8 bytes
TYPE ASF_MUX_STATISTICS DWORD
   cFramesWritten AS DWORD   ' DWORD
   cFramesDropped AS DWORD   ' DWORD
END TYPE


' ########################################################################################
' Interface name = IMFASFMultiplexer
' IID = 57BDD80A-9B38-4838-B737-C58F670D7D4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFMultiplexer_INTERFACE_DEFINED)
    %IMFASFMultiplexer_INTERFACE_DEFINED = 1

$IID_IMFASFMultiplexer = GUID$("{57BDD80A-9B38-4838-B737-C58F670D7D4F}")

INTERFACE IMFASFMultiplexer $IID_IMFASFMultiplexer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pIContentInfo AS IMFASFContentInfo _         ' __in IMFASFContentInfo *pIContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 20
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessSample ( _                             ' VTable offset = 24
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   , BYVAL pISample AS IMFSample _                      ' __in IMFSample *pISample
   , BYVAL hnsTimestampAdjust AS QUAD _                 ' __in LONGLONG hnsTimestampAdjust
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextPacket ( _                             ' VTable offset = 28
     BYVAL pdwStatusFlags AS DWORD _                    ' __out DWORD *pdwStatusFlags
   , BYREF ppIPacket AS IMFSample _                     ' __out IMFSample **ppIPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 36
     BYREF pIContentInfo AS IMFASFContentInfo _         ' __in_out IMFASFContentInfo *pIContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 40
     BYVAL wStreamNumber AS WORD _                      ' __in WORD wStreamNumber
   , BYREF pMuxStats AS ASF_MUX_STATISTICS _            ' __out ASF_MUX_STATISTICS *pMuxStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncTolerance ( _                          ' VTable offset = 44
     BYVAL msSyncTolerance AS DWORD _                   ' __in DWORD msSyncTolerance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFMultiplexer_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateASFMultiplexer IMPORT "mf.dll" ALIAS "MFCreateASFMultiplexer" ( _
   BYREF ppIMultiplexer AS IMFASFMultiplexer _          ' __out IMFASFMultiplexer **ppIMultiplexer);
 ) AS LONG                                              ' HRESULT

' enum MFASF_INDEXERFLAGS
%MFASF_INDEXER_WRITE_NEW_INDEX          = &H1
%MFASF_INDEXER_READ_FOR_REVERSEPLAYBACK = &H2
%MFASF_INDEXER_WRITE_FOR_LIVEREAD       = &H4

' // Size = 20 bytes
TYPE ASF_INDEX_IDENTIFIER DWORD
   guidIndexType AS GUID   ' GUID
   wStreamNumber AS WORD   ' WORD
END TYPE

' // Size = 92 bytes
TYPE ASF_INDEX_DESCRIPTOR DWORD
   Identifier     AS ASF_INDEX_IDENTIFIER   ' ASF_INDEX_IDENTIFIER
   cPerEntryBytes AS WORD                   ' WORD
   szDescription  AS WSTRINGZ * 32          ' WCHAR
   dwInterval     AS DWORD                  ' DWORD
END TYPE


' ########################################################################################
' Interface name = IMFASFIndexer
' IID = 53590F48-DC3B-4297-813F-787761AD7B3E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFIndexer_INTERFACE_DEFINED)
    %IMFASFIndexer_INTERFACE_DEFINED = 1

$IID_IMFASFIndexer = GUID$("{53590F48-DC3B-4297-813F-787761AD7B3E}")

INTERFACE IMFASFIndexer $IID_IMFASFIndexer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 16
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYVAL pIContentInfo AS IMFASFContentInfo _         ' __in IMFASFContentInfo *pIContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexPosition ( _                          ' VTable offset = 24
     BYVAL pIContentInfo AS IMFASFContentInfo _         ' __in IMFASFContentInfo *pIContentInfo
   , BYREF pcbIndexOffset AS QUAD _                     ' __out QWORD *pcbIndexOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndexByteStreams ( _                       ' VTable offset = 28
     BYVAL ppIByteStreams AS IMFByteStream _            ' __in IMFByteStream **ppIByteStreams
   , BYVAL cByteStreams AS DWORD _                      ' __in DWORD cByteStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexByteStreamCount ( _                   ' VTable offset = 32
     BYREF pcByteStreams AS DWORD _                     ' __out DWORD *pcByteStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexStatus ( _                            ' VTable offset = 36
     BYREF pIndexIdentifier AS ASF_INDEX_IDENTIFIER _   ' __in ASF_INDEX_IDENTIFIER *pIndexIdentifier
   , BYREF pfIsIndexed AS LONG _                        ' __out BOOL *pfIsIndexed
   , BYVAL pbIndexDescriptor AS BYTE PTR _              ' __out BYTE *pbIndexDescriptor
   , BYREF pcbIndexDescriptor AS DWORD _                ' __in_out DWORD *pcbIndexDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIndexStatus ( _                            ' VTable offset = 40
     BYVAL pbIndexDescriptor AS BYTE PTR _              ' __in BYTE *pbIndexDescriptor
   , BYVAL cbIndexDescriptor AS DWORD _                 ' __in DWORD cbIndexDescriptor
   , BYVAL fGenerateIndex AS LONG _                     ' __in BOOL fGenerateIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSeekPositionForValue ( _                   ' VTable offset = 44
     BYREF pvarValue AS PROPVARIANT _                   ' __in const PROPVARIANT *pvarValue
   , BYREF pIndexIdentifier AS ASF_INDEX_IDENTIFIER _   ' __in ASF_INDEX_IDENTIFIER *pIndexIdentifier
   , BYREF pcbOffsetWithinData AS QUAD _                ' __out QWORD *pcbOffsetWithinData
   , BYREF phnsApproxTime AS QUAD _                     ' __opt_out MFTIME *phnsApproxTime
   , BYREF pdwPayloadNumberOfStreamWithinPacket AS DWORD _ ' __opt_out DWORD *pdwPayloadNumberOfStreamWithinPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateIndexEntries ( _                      ' VTable offset = 48
     BYVAL pIASFPacketSample AS IMFSample _             ' __in IMFSample *pIASFPacketSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitIndex ( _                               ' VTable offset = 52
     BYVAL pIContentInfo AS IMFASFContentInfo _         ' __in IMFASFContentInfo *pIContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexWriteSpace ( _                        ' VTable offset = 56
     BYREF pcbIndexWriteSpace AS QUAD _                 ' __out QWORD *pcbIndexWriteSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompletedIndex ( _                         ' VTable offset = 60
     BYVAL pIIndexBuffer AS IMFMediaBuffer _            ' __in IMFMediaBuffer *pIIndexBuffer
   , BYVAL cbOffsetWithinIndex AS QUAD _                ' __in QWORD cbOffsetWithinIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFIndexer_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)
$MFASFINDEXER_TYPE_TIMECODE = GUID$("{49815231-6bad-44fd-810a-3f60984ec7fd}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
%MFASFINDEXER_PER_ENTRY_BYTES_DYNAMIC        = &Hffff??
%MFASFINDEXER_NO_FIXED_INTERVAL              = &Hffffffff???
%MFASFINDEXER_READ_FOR_REVERSEPLAYBACK_OUTOFDATASEGMENT = &Hffffffffffffffff&&
%MFASFINDEXER_APPROX_SEEK_TIME_UNKNOWN = &Hffffffffffffffff&&

DECLARE FUNCTION MFCreateASFIndexer IMPORT "mf.dll" ALIAS "MFCreateASFIndexer" ( _
   BYREF ppIIndexer AS IMFASFIndexer _                  ' __out IMFASFIndexer **ppIIndexer
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFIndexerByteStream IMPORT "mf.dll" ALIAS "MFCreateASFIndexerByteStream" ( _
   BYVAL pIContentByteStream AS IMFByteStream _         ' __in  IMFByteStream  *pIContentByteStream
 , BYVAL cbIndexStartOffset AS QUAD _                   ' __in  QWORD           cbIndexStartOffset
 , BYREF pIIndexByteStream AS IMFByteStream _           ' __out IMFByteStream **pIIndexByteStream
 ) AS LONG                                              ' HRESULT

' enum MFASF_STREAMSELECTORFLAGS
%MFASF_STREAMSELECTOR_DISABLE_THINNING    = &H1
%MFASF_STREAMSELECTOR_USE_AVERAGE_BITRATE = &H2

' enum ASF_SELECTION_STATUS
%ASF_STATUS_NOTSELECTED     = 0
%ASF_STATUS_CLEANPOINTSONLY = 1
%ASF_STATUS_ALLDATAUNITS    = 2


' ########################################################################################
' Interface name = IMFASFStreamSelector
' IID = D01BAD4A-4FA0-4A60-9349-C27E62DA9D41
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFASFStreamSelector_INTERFACE_DEFINED)
    %IMFASFStreamSelector_INTERFACE_DEFINED = 1

$IID_IMFASFStreamSelector = GUID$("{D01BAD4A-4FA0-4A60-9349-C27E62DA9D41}")

INTERFACE IMFASFStreamSelector $IID_IMFASFStreamSelector

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 12
     BYREF pcStreams AS DWORD _                         ' __out DWORD *pcStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputCount ( _                            ' VTable offset = 16
     BYREF pcOutputs AS DWORD _                         ' __out DWORD *pcOutputs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStreamCount ( _                      ' VTable offset = 20
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYREF pcStreams AS DWORD _                         ' __out DWORD *pcStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStreamNumbers ( _                    ' VTable offset = 24
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYREF rgwStreamNumbers AS WORD _                   ' __out WORD *rgwStreamNumbers
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFromStream ( _                       ' VTable offset = 28
     BYVAL wStreamNum AS WORD _                         ' __in WORD wStreamNum
   , BYREF pdwOutput AS DWORD _                         ' __out DWORD *pdwOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputOverride ( _                         ' VTable offset = 32
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYREF pSelection AS LONG _                         ' __out ASF_SELECTION_STATUS *pSelection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputOverride ( _                         ' VTable offset = 36
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYVAL Selection AS LONG _                          ' __in ASF_SELECTION_STATUS Selection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputMutexCount ( _                       ' VTable offset = 40
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYREF pcMutexes AS DWORD _                         ' __out DWORD *pcMutexes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputMutex ( _                            ' VTable offset = 44
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYVAL dwMutexNum AS DWORD _                        ' __in DWORD dwMutexNum
   , BYREF ppMutex AS IUnknown _                        ' __out IUnknown **ppMutex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputMutexSelection ( _                   ' VTable offset = 48
     BYVAL dwOutputNum AS DWORD _                       ' __in DWORD dwOutputNum
   , BYVAL dwMutexNum AS DWORD _                        ' __in DWORD dwMutexNum
   , BYVAL wSelectedRecord AS WORD _                    ' __in WORD wSelectedRecord
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandwidthStepCount ( _                     ' VTable offset = 52
     BYREF pcStepCount AS DWORD _                       ' __out DWORD *pcStepCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandwidthStep ( _                          ' VTable offset = 56
     BYVAL dwStepNum AS DWORD _                         ' __in DWORD dwStepNum
   , BYREF pdwBitrate AS DWORD _                        ' __out DWORD *pdwBitrate
   , BYREF rgwStreamNumbers AS WORD _                   ' __out WORD *rgwStreamNumbers
   , BYREF rgSelections AS LONG _                       ' __out ASF_SELECTION_STATUS *rgSelections
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BitrateToStepNumber ( _                       ' VTable offset = 57
     BYVAL dwBitrate AS DWORD _                         ' __in DWORD dwBitrate
   , BYREF pdwStepNum AS DWORD _                        ' __out DWORD *pdwStepNum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSelectorFlags ( _                    ' VTable offset = 58
     BYVAL dwStreamSelectorFlags AS DWORD _             ' __in DWORD dwStreamSelectorFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFASFStreamSelector_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateASFStreamSelector IMPORT "mf.dll" ALIAS "MFCreateASFStreamSelector" ( _
   BYVAL pIASFProfile AS IMFASFProfile _                ' __in IMFASFProfile *pIASFProfile
 , BYREF ppSelector AS IMFASFStreamSelector _           ' __out IMFASFStreamSelector **ppSelector
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFMediaSink IMPORT "mf.dll" ALIAS "MFCreateASFMediaSink" ( _
   BYVAL pIByteStream AS IMFByteStream _                ' __in IMFByteStream *pIByteStream
 , BYREF ppIMediaSink AS IMFMediaSink _                 ' __out IMFMediaSink** ppIMediaSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFMediaSinkActivate IMPORT "mf.dll" ALIAS "MFCreateASFMediaSinkActivate" ( _
   BYREF pwszFileName AS WSTRINGZ _                     ' __in LPCWSTR pwszFileName
 , BYVAL pContentInfo AS IMFASFContentInfo _            ' __in IMFASFContentInfo *pContentInfo
 , BYREF ppIActivate AS IMFActivate _                   ' __out IMFActivate** ppIActivate
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateWMVEncoderActivate IMPORT "mf.dll" ALIAS "MFCreateWMVEncoderActivate" ( _
   BYVAL pMediaType AS IMFMediaType _                   ' __in IMFMediaType * pMediaType
 , BYVAL pEncodingConfigurationProperties AS IPropertyStore _ ' __in IPropertyStore * pEncodingConfigurationProperties
 , BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate ** ppActivate
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFStreamingMediaSink IMPORT "mf.dll" ALIAS "MFCreateASFStreamingMediaSink" ( _
   BYVAL pIByteStream AS IMFByteStream _                ' __in IMFByteStream *pIByteStream
 , BYREF ppIMediaSink AS IMFMediaSink _                 ' __out IMFMediaSink** ppIMediaSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateASFStreamingMediaSinkActivate IMPORT "mf.dll" ALIAS "MFCreateASFStreamingMediaSinkActivate" ( _
   BYVAL pByteStreamActivate AS IMFActivate _           ' __in IMFActivate *pByteStreamActivate
 , BYVAL pContentInfo AS IMFASFContentInfo _            ' __in IMFASFContentInfo *pContentInfo
 , BYREF ppIActivate AS IMFActivate _                   ' __out IMFActivate** ppIActivate
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateWMAEncoderActivate IMPORT "mf.dll" ALIAS "MFCreateWMAEncoderActivate" ( _
   BYVAL pMediaType AS IMFMediaType _                   ' __in IMFMediaType * pMediaType
 , BYVAL pEncodingConfigurationProperties AS IPropertyStore _ ' __in IPropertyStore * pEncodingConfigurationProperties
 , BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate ** ppActivate
 ) AS LONG                                              ' HRESULT

'EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MFPKEY_ASFMEDIASINK_BASE_SENDTIME = { { 0xcddcbc82, 0x3411, 0x4119, 0x91, 0x35, 0x84, 0x23, 0xc4, 0x1b, 0x39, 0x57}, 3  };
'EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MFPKEY_ASFMEDIASINK_AUTOADJUST_BITRATE = { { 0xcddcbc82, 0x3411, 0x4119, 0x91, 0x35, 0x84, 0x23, 0xc4, 0x1b, 0x39, 0x57}, 4  };
'EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MFPKEY_ASFMEDIASINK_DRMACTION = { { 0xa1db6f6c, 0x1d0a, 0x4cb6, 0x82, 0x54, 0xcb, 0x36, 0xbe, 0xed, 0xbc, 0x48}, 5  };

MACRO MFPKEY_ASFMEDIASINK_BASE_SENDTIME = GUID$("{CDDCBC82-3411-4119-9135-8423C41B3957}") & MKDWD$(3)
MACRO MFPKEY_ASFMEDIASINK_AUTOADJUST_BITRATE = GUID$("{CDDCBC82-3411-4119-9135-8423C41B3957}") & MKDWD$(4)
MACRO MFPKEY_ASFMEDIASINK_DRMACTION = GUID$("{A1DB6F6C-1D0A-4CB6-8254-CB36BEEDBC48}") & MKDWD$(5)

' enum MFSINK_WMDRMACTION
%MFSINK_WMDRMACTION_UNDEFINED  = 0
%MFSINK_WMDRMACTION_ENCODE     = 1
%MFSINK_WMDRMACTION_TRANSCODE  = 2
%MFSINK_WMDRMACTION_TRANSCRYPT = 3
%MFSINK_WMDRMACTION_LAST       = 3

'EXTERN_C const DECLSPEC_SELECTANY PROPERTYKEY MFPKEY_ASFSTREAMSINK_CORRECTED_LEAKYBUCKET = { { 0xa2f152fb, 0x8ad9, 0x4a11, 0xb3, 0x45, 0x2c, 0xe2, 0xfa, 0xd8, 0x72, 0x3d}, 1  };
MACRO MFPKEY_ASFSTREAMSINK_CORRECTED_LEAKYBUCKET = GUID$("{A2F152FB-8AD9-4A11-B345-2CE2FAD8723D}") & MKDWD$(1)

'//
'// Define WMContainer constants
'//

%MFASF_MAX_STREAM_NUMBER              = 127
%MFASF_INVALID_STREAM_NUMBER          = %MFASF_MAX_STREAM_NUMBER + 1
%MFASF_PAYLOADEXTENSION_MAX_SIZE      = &Hff
%MFASF_PAYLOADEXTENSION_VARIABLE_SIZE = &Hffff
%MFASF_DEFAULT_BUFFER_WINDOW_MS       = 3000
'//

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFDRMNetHelper
' IID = 3D1FF0EA-679A-4190-8D46-7FA69E8C7E15
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFDRMNetHelper_INTERFACE_DEFINED)
    %IMFDRMNetHelper_INTERFACE_DEFINED = 1

$IID_IMFDRMNetHelper = GUID$("{3D1FF0EA-679A-4190-8D46-7FA69E8C7E15}")

INTERFACE IMFDRMNetHelper $IID_IMFDRMNetHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProcessLicenseRequest ( _                     ' VTable offset = 12
     BYVAL pLicenseRequest AS BYTE PTR _                ' __ BYTE *pLicenseRequest
   , BYVAL cbLicenseRequest AS DWORD _                  ' __in DWORD cbLicenseRequest
   , BYREF ppLicenseResponse AS DWORD _                 ' __out BYTE **ppLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   , BYREF pbstrKID AS WSTRING _                        ' __out BSTR *pbstrKID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChainedLicenseResponse ( _                 ' VTable offset = 16
     BYREF ppLicenseResponse AS DWORD _                 ' __out BYTE **ppLicenseResponse
   , BYREF pcbLicenseResponse AS DWORD _                ' __out DWORD *pcbLicenseResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFDRMNetHelper_INTERFACE_DEFINED__ */
