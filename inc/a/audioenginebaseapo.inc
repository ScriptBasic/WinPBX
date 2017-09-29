' ########################################################################################
' Microsoft Windows (Vista only; removed as of Windows 7)
' File: audioenginebaseapo.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOENGINEBASEAPO_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mmdeviceapi.inc"
#INCLUDE ONCE "audiomediatype.inc"

'//
'// Error Codes for APO
'// The facility code for APOs is 0x87D.
'//
'// The object has already been initialized.
%APOERR_ALREADY_INITIALIZED               = &H887D0001&
'// Object/structure is not initialized.
%APOERR_NOT_INITIALIZED                   = &H887D0002&
'// a pin supporting the format cannot be found.
%APOERR_FORMAT_NOT_SUPPORTED              = &H887D0003&
'// Invalid CLSID in an APO Initialization structure
%APOERR_INVALID_APO_CLSID                 = &H887D0004&
'// Buffers overlap on an APO that does not accept in-place buffers.
%APOERR_BUFFERS_OVERLAP                   = &H887D0005&
'// APO is already in an unlocked state
%APOERR_ALREADY_UNLOCKED                  = &H887D0006&
'// number of input or output connections not valid on this APO
%APOERR_NUM_CONNECTIONS_INVALID           = &H887D0007&
'// Output maxFrameCount not large enough.
%APOERR_INVALID_OUTPUT_MAXFRAMECOUNT      = &H887D0008&
'// Invalid connection format for this operation
%APOERR_INVALID_CONNECTION_FORMAT         = &H887D0009&
'// APO is locked ready to process and can not be changed
%APOERR_APO_LOCKED                        = &H887D000A&
'// Invalid coefficient count
%APOERR_INVALID_COEFFCOUNT                = &H887D000B&
'// Invalid coefficient
%APOERR_INVALID_COEFFICIENT               = &H887D000C&
'// an invalid curve parameter was specified
%APOERR_INVALID_CURVE_PARAM               = &H887D000D&
'//
'// Signatures for data structures.
'//
$APO_CONNECTION_DESCRIPTOR_SIGNATURE   = "ACDS"
$APO_CONNECTION_PROPERTY_SIGNATURE     = "ACPS"

'// Min and max framerates for the engine
%AUDIO_MIN_FRAMERATE                   = 10     ' 10.0      ' // Minimum frame rate for APOs
%AUDIO_MAX_FRAMERATE                   = 384000 ' 384000.0  ' // Maximum frame rate for APOs

'// Min and max # of channels (samples per frame) for the APOs
%AUDIO_MIN_CHANNELS                    = 1      ' // Current minimum number of channels for APOs
%AUDIO_MAX_CHANNELS                    = 4096   ' // Current maximum number of channels for APOs

'//-----------------------------------------------------------------------------

'typedef LONGLONG HNSTIME;
'typedef LONGLONG MFTIME;
'typedef float FLOAT32;
'typedef double FLOAT64;

' APO_CONNECTION_BUFFER_TYPE enum
%APO_CONNECTION_BUFFER_TYPE_ALLOCATED = 0
%APO_CONNECTION_BUFFER_TYPE_EXTERNAL  = 1
%APO_CONNECTION_BUFFER_TYPE_DEPENDANT = 2

' // Size = 20 bytes
TYPE APO_CONNECTION_DESCRIPTOR DWORD
   Type             AS LONG        ' APO_CONNECTION_BUFFER_TYPE
   pBuffer          AS DWORD       ' UINT_PTR
   u32MaxFrameCount AS DWORD       ' UINT32
   pFormat          AS DWORD PTR   ' IAudioMediaType *
   u32Signature     AS DWORD       ' UINT32
END TYPE

' APO_BUFFER_FLAGS enum
%BUFFER_INVALID = 0
%BUFFER_VALID   = 1
%BUFFER_SILENT  = 2

' // Size = 16 bytes
TYPE APO_CONNECTION_PROPERTY DWORD
   pBuffer            AS DWORD   ' UINT_PTR
   u32ValidFrameCount AS DWORD   ' UINT32
   u32BufferFlags     AS LONG    ' APO_BUFFER_FLAGS
   u32Signature       AS DWORD   ' UINT32
END TYPE

'APO_FLAG enum
%APO_FLAG_NONE = 0
%APO_FLAG_INPLACE = &H1
%APO_FLAG_SAMPLESPERFRAME_MUST_MATCH = &H2
%APO_FLAG_FRAMESPERSECOND_MUST_MATCH = &H4
%APO_FLAG_BITSPERSAMPLE_MUST_MATCH = &H8
%APO_FLAG_DEFAULT = ((%APO_FLAG_SAMPLESPERFRAME_MUST_MATCH OR %APO_FLAG_FRAMESPERSECOND_MUST_MATCH) OR %APO_FLAG_BITSPERSAMPLE_MUST_MATCH)

' // Size = 1092 bytes
TYPE APO_REG_PROPERTIES DWORD
   clsid                   AS GUID             ' CLSID
   Flags                   AS LONG             ' APO_FLAG
   szFriendlyName          AS WSTRINGZ * 256   ' WCHAR
   szCopyrightInfo         AS WSTRINGZ * 256   ' WCHAR
   u32MajorVersion         AS DWORD            ' UINT32
   u32MinorVersion         AS DWORD            ' UINT32
   u32MinInputConnections  AS DWORD            ' UINT32
   u32MaxInputConnections  AS DWORD            ' UINT32
   u32MinOutputConnections AS DWORD            ' UINT32
   u32MaxOutputConnections AS DWORD            ' UINT32
   u32MaxInstances         AS DWORD            ' UINT32
   u32NumAPOInterfaces     AS DWORD            ' UINT32
   iidAPOInterfaceList(0)  AS GUID             ' IID
END TYPE

' // Size = 20 bytes
TYPE APOInitBaseStruct DWORD
   cbSize AS DWORD   ' UINT32
   clsid  AS GUID    ' CLSID
END TYPE

' AUDIO_FLOW_TYPE enum
%AUDIO_FLOW_PULL   = 0
%AUDIO_FLOW_PUSH   = %AUDIO_FLOW_PULL + 1


' ########################################################################################
' Interface name = IAudioProcessingObjectRT
' IID = 9E1D6A6D-DDBC-4E95-A4C7-AD64BA37846C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioProcessingObjectRT_INTERFACE_DEFINED)
    %IAudioProcessingObjectRT_INTERFACE_DEFINED = 1

$IID_IAudioProcessingObjectRT = GUID$("{9E1D6A6D-DDBC-4E95-A4C7-AD64BA37846C}")

INTERFACE IAudioProcessingObjectRT $IID_IAudioProcessingObjectRT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD APOProcess ( _                                     ' VTable offset = 12
     BYVAL u32NumInputConnections AS DWORD _                 ' __in UINT32 u32NumInputConnections
   , BYREF ppInputConnections AS APO_CONNECTION_PROPERTY _   ' __in APO_CONNECTION_PROPERTY **ppInputConnections
   , BYVAL u32NumOutputConnections AS DWORD _                ' __in UINT32 u32NumOutputConnections
   , BYREF ppOutputConnections AS APO_CONNECTION_PROPERTY _  ' __in_out APO_CONNECTION_PROPERTY **ppOutputConnections
   )                                                         ' void
   ' =====================================================================================
   METHOD CalcInputFrames ( _                                ' VTable offset = 16
     BYVAL u32OutputFrameCount AS DWORD _                    ' __in UINT32 u32OutputFrameCount
   ) AS DWORD                                                ' UINT32
   ' =====================================================================================
   METHOD CalcOutputFrames ( _                               ' VTable offset = 20
     BYVAL u32InputFrameCount AS DWORD _                     ' __in UINT32 u32InputFrameCount
   ) AS DWORD                                                ' UINT32
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioProcessingObjectRT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioProcessingObjectVBR
' IID = 7BA1DB8F-78AD-49CD-9591-F79D80A17C81
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioProcessingObjectVBR_INTERFACE_DEFINED)
    %IAudioProcessingObjectVBR_INTERFACE_DEFINED = 1

$IID_IAudioProcessingObjectVBR = GUID$("{7BA1DB8F-78AD-49CD-9591-F79D80A17C81}")

INTERFACE IAudioProcessingObjectVBR $IID_IAudioProcessingObjectVBR

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CalcMaxInputFrames ( _                        ' VTable offset = 12
     BYVAL u32MaxOutputFrameCount AS DWORD _            ' __in UINT32 u32MaxOutputFrameCount
   , BYREF pu32InputFrameCount AS DWORD _               ' __out UINT32 *pu32InputFrameCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcMaxOutputFrames ( _                       ' VTable offset = 16
     BYVAL u32MaxInputFrameCount AS DWORD _             ' __in UINT32 u32MaxInputFrameCount
   , BYREF pu32OutputFrameCount AS DWORD _              ' __out UINT32 *pu32OutputFrameCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioProcessingObjectVBR_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioProcessingObjectConfiguration
' IID = 0E5ED805-ABA6-49C3-8F9A-2B8C889C4FA8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioProcessingObjectConfiguration_INTERFACE_DEFINED)
    %IAudioProcessingObjectConfiguration_INTERFACE_DEFINED = 1

$IID_IAudioProcessingObjectConfiguration = GUID$("{0E5ED805-ABA6-49C3-8F9A-2B8C889C4FA8}")

INTERFACE IAudioProcessingObjectConfiguration $IID_IAudioProcessingObjectConfiguration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LockForProcess ( _                                  ' VTable offset = 12
     BYVAL u32NumInputConnections AS DWORD _                  ' __in UINT32 u32NumInputConnections
   , BYREF ppInputConnections AS APO_CONNECTION_DESCRIPTOR _  ' __in APO_CONNECTION_DESCRIPTOR **ppInputConnections
   , BYVAL u32NumOutputConnections AS DWORD _                 ' __in UINT32 u32NumOutputConnections
   , BYREF ppOutputConnections AS APO_CONNECTION_DESCRIPTOR _ ' __in APO_CONNECTION_DESCRIPTOR **ppOutputConnections
   ) AS LONG                                                  ' HRESULT
   ' =====================================================================================
   METHOD UnlockForProcess ( _                                ' VTable offset = 16
   ) AS LONG                                                  ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioProcessingObjectConfiguration_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioProcessingObject
' IID = FD7F2B29-24D0-4B5C-B177-592C39F9CA10
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioProcessingObject_INTERFACE_DEFINED)
    %IAudioProcessingObject_INTERFACE_DEFINED = 1

$IID_IAudioProcessingObject = GUID$("{FD7F2B29-24D0-4B5C-B177-592C39F9CA10}")

INTERFACE IAudioProcessingObject $IID_IAudioProcessingObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLatency ( _                                ' VTable offset = 16
     BYREF pTime AS QUAD _                              ' __out MFTIME *pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegistrationProperties ( _                 ' VTable offset = 20
     BYREF ppRegProps AS APO_REG_PROPERTIES _           ' __out APO_REG_PROPERTIES **ppRegProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 24
     BYVAL cbDataSize AS DWORD _                        ' __in UINT32 cbDataSize
   , BYVAL pbyData AS BYTE PTR _                        ' __in BYTE *pbyData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInputFormatSupported ( _                    ' VTable offset = 28
     BYVAL pOppositeFormat AS IAudioMediaType _         ' __in IAudioMediaType *pOppositeFormat
   , BYVAL pRequestedInputFormat AS IAudioMediaType _   ' __in IAudioMediaType *pRequestedInputFormat
   , BYREF ppSupportedInputFormat AS IAudioMediaType _  ' __out IAudioMediaType **ppSupportedInputFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsOutputFormatSupported ( _                   ' VTable offset = 32
     BYVAL pOppositeFormat AS IAudioMediaType _         ' __in IAudioMediaType *pOppositeFormat
   , BYVAL pRequestedOutputFormat AS IAudioMediaType _  ' __in IAudioMediaType *pRequestedOutputFormat
   , BYREF ppSupportedOutputFormat AS IAudioMediaType _ ' __outIAudioMediaType **ppSupportedOutputFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputChannelCount ( _                      ' VTable offset = 36
     BYREF pu32ChannelCount AS DWORD _                  ' __out UINT32 *pu32ChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioProcessingObject_INTERFACE_DEFINED__ */


'//
'// APO registration functions
'//
'typedef HRESULT (WINAPI FNAPONOTIFICATIONCALLBACK)(APO_REG_PROPERTIES* pProperties, VOID* pvRefData);
'extern HRESULT WINAPI RegisterAPO(APO_REG_PROPERTIES const* pProperties);
'extern HRESULT WINAPI UnregisterAPO(REFCLSID clsid);
'extern HRESULT WINAPI RegisterAPONotification(HANDLE hEvent);
'extern HRESULT WINAPI UnregisterAPONotification(HANDLE hEvent);
'extern HRESULT WINAPI EnumerateAPOs(FNAPONOTIFICATIONCALLBACK pfnCallback, PVOID pvRefData);
'extern HRESULT WINAPI GetAPOProperties(REFCLSID clsid, APO_REG_PROPERTIES* pProperties);


' ########################################################################################
' Interface name = IAudioSystemEffects
' IID = 5FA00F27-ADD6-499A-8A9D-6B98521FA75B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSystemEffects_INTERFACE_DEFINED)
    %IAudioSystemEffects_INTERFACE_DEFINED = 1

$IID_IAudioSystemEffects = GUID$("{5FA00F27-ADD6-499A-8A9D-6B98521FA75B}")

INTERFACE IAudioSystemEffects $IID_IAudioSystemEffects

   INHERIT IUnknown

END INTERFACE

#ENDIF   ' /* __IAudioSystemEffects_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSystemEffectsCustomFormats
' IID = B1176E34-BB7F-4F05-BEBD-1B18A534E097
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED)
    %IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED = 1

$IID_IAudioSystemEffectsCustomFormats = GUID$("{B1176E34-BB7F-4F05-BEBD-1B18A534E097}")

INTERFACE IAudioSystemEffectsCustomFormats $IID_IAudioSystemEffectsCustomFormats

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFormatCount ( _                            ' VTable offset = 12
     BYREF pcFormats AS DWORD _                         ' __out UINT *pcFormats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 16
     BYVAL nFormat AS DWORD _                           ' __in UINT nFormat
   , BYREF ppFormat AS IAudioMediaType _                ' __out IAudioMediaType **ppFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormatRepresentation ( _                   ' VTable offset = 20
     BYVAL nFormat AS DWORD _                           ' __in UINT nFormat
   , BYREF ppwstrFormatRep AS DWORD _                   ' __out LPWSTR *ppwstrFormatRep
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSystemEffectsCustomFormats_INTERFACE_DEFINED__ */


' // Size = 36 bytes
TYPE APOInitSystemEffects DWORD
   APOInit                     AS APOInitBaseStruct
   pAPOEndpointProperties      AS DWORD PTR   ' IPropertyStore*
   pAPOSystemEffectsProperties AS DWORD PTR   ' IPropertyStore*
   pReserved                   AS DWORD       ' void*
   pDeviceCollection           AS DWORD PTR   ' IMMDeviceCollection
END TYPE

' // Size = 12 bytes
TYPE AudioFXExtensionParams DWORD
   AddPageParam    AS LONG           ' LPARAM
   pwstrEndpointID AS WSTRINGZ PTR   ' LPWSTR
   pFxProperties   AS DWORD PTR      ' IPropertyStore*
END TYPE

'DEFINE_PROPERTYKEY(PKEY_FX_Association, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 0);
'DEFINE_PROPERTYKEY(PKEY_FX_PreMixEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 1);
'DEFINE_PROPERTYKEY(PKEY_FX_PostMixEffectClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 2);
'DEFINE_PROPERTYKEY(PKEY_FX_UserInterfaceClsid, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 3);
'DEFINE_PROPERTYKEY(PKEY_FX_FriendlyName, 0xD04E05A6, 0x594B, 0x4fb6, 0xA8, 0x0D, 0x01, 0xAF, 0x5E, 0xED, 0x7D, 0x1D, 4);

MACRO PKEY_FX_Association        = GUID$("{D04E05A6-594B-4FB6-A80D-01AF5EED7D1D}") & MKDWD$(0)
MACRO PKEY_FX_PreMixEffectClsid  = GUID$("{D04E05A6-594B-4FB6-A80D-01AF5EED7D1D}") & MKDWD$(1)
MACRO PKEY_FX_PostMixEffectClsid = GUID$("{D04E05A6-594B-4FB6-A80D-01AF5EED7D1D}") & MKDWD$(2)
MACRO PKEY_FX_UserInterfaceClsid = GUID$("{D04E05A6-594B-4FB6-A80D-01AF5EED7D1D}") & MKDWD$(3)
MACRO PKEY_FX_FriendlyName       = GUID$("{D04E05A6-594B-4FB6-A80D-01AF5EED7D1D}") & MKDWD$(4)
