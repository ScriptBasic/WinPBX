' ########################################################################################
' Microsoft Windows (Vista only; removed as of Windows 7)
' File: audiomediatype.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOMEDIATYPE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "mmreg.inc"

' // Size = 36 bytes
#IF NOT %DEF(%UNCOMPRESSEDAUDIOFORMAT)
%UNCOMPRESSEDAUDIOFORMAT = 1
TYPE UNCOMPRESSEDAUDIOFORMAT DWORD
   guidFormatType            AS GUID     ' GUID
   dwSamplesPerFrame         AS DWORD    ' DWORD
   dwBytesPerSampleContainer AS DWORD    ' DWORD
   dwValidBitsPerSample      AS DWORD    ' DWORD
   fFramesPerSecond          AS SINGLE   ' FLOAT
   dwChannelMask             AS DWORD    ' DWORD
END TYPE
#ENDIF

' ########################################################################################
' Interface name = IAudioMediaType
' IID = 4E997F73-B71F-4798-873B-ED7DFCF15B4D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioMediaType_INTERFACE_DEFINED)
    %IAudioMediaType_INTERFACE_DEFINED = 1

$IID_IAudioMediaType = GUID$("{4E997F73-B71F-4798-873B-ED7DFCF15B4D}")

INTERFACE IAudioMediaType $IID_IAudioMediaType

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsCompressedFormat ( _                        ' VTable offset = 12
     BYREF pfCompressed AS LONG _                       ' __out BOOL *pfCompressed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEqual ( _                                   ' VTable offset = 16
     BYVAL pIAudioType AS IAudioMediaType _             ' __in  IAudioMediaType *pIAudioType
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioFormat ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUncompressedAudioFormat ( _                ' VTable offset = 24
     BYREF pUncompressedAudioFormat AS UNCOMPRESSEDAUDIOFORMAT _ ' __out UNCOMPRESSEDAUDIOFORMAT *pUncompressedAudioFormat
   ) AS DWORD                                           ' const WAVEFORMATEX *
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioMediaType_INTERFACE_DEFINED__ */


'//
'// CreateAudioMediaType
'//
'STDAPI CreateAudioMediaType(
'    const WAVEFORMATEX* pAudioFormat,
'    UINT32 cbAudioFormatSize,
'    IAudioMediaType** ppIAudioMediaType
'    );

'//
'// CreateAudioMediaTypeFromUncompressedAudioFormat
'//
'STDAPI CreateAudioMediaTypeFromUncompressedAudioFormat(
'    const UNCOMPRESSEDAUDIOFORMAT* pUncompressedAudioFormat,
'    IAudioMediaType** ppIAudioMediaType
'    );

%AUDIOMEDIATYPE_EQUAL_FORMAT_TYPES     = &H00000002???
%AUDIOMEDIATYPE_EQUAL_FORMAT_DATA      = &H00000004???
%AUDIOMEDIATYPE_EQUAL_FORMAT_USER_DATA = &H00000008???
