' ########################################################################################
' Microsoft Windows
' File: mfmp2dlna.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MFMP2DLNA_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "mfobjects.inc"

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' IMFDLNASinkInit interface
' IID = 0c012799-1b61-4c10-bda9-04445be5f561
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFDLNASinkInit_INTERFACE_DEFINED)
    %IMFDLNASinkInit_INTERFACE_DEFINED = 1

$IID_IMFDLNASinkInit = GUID$("{0c012799-1b61-4c10-bda9-04445be5f561}")

INTERFACE IMFDLNASinkInit $IID_IMFDLNASinkInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pByteStream AS IMFByteStream _               ' __in IMFByteStream *pByteStream
   , BYVAL fPal AS LONG _                               ' __in BOOL fPal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFDLNASinkInit_INTERFACE_DEFINED__ */

$CLSID_MPEG2DLNASink = GUID$("{fa5fe7c5-6a1d-4b11-b41f-f959d6c76500}")
$MF_MP2DLNA_USE_MMCSS = GUID$("{54f3e2ee-a2a2-497d-9834-973afde521eb}")
$MF_MP2DLNA_VIDEO_BIT_RATE = GUID$("{e88548de-73b4-42d7-9c75-adfa0a2a6e4c}")
$MF_MP2DLNA_AUDIO_BIT_RATE = GUID$("{2d1c070e-2b5f-4ab3-a7e6-8d943ba8d00a}")
$MF_MP2DLNA_ENCODE_QUALITY = GUID$("{b52379d7-1d46-4fb6-a317-a4a5f60959f8}")
$MF_MP2DLNA_STATISTICS = GUID$("{75e488a3-d5ad-4898-85e0-bcce24a722d7}")

' // Size = 88 bytes
TYPE MFMPEG2DLNASINKSTATS   ' Must be 8 byte aligned
   cBytesWritten            AS QUAD    ' DWORDLONG
   fPAL                     AS LONG    ' BOOL
   fccVideo                 AS DWORD   ' DWORD
   dwVideoWidth             AS DWORD   ' DWORD
   dwVideoHeight            AS DWORD   ' DWORD
   cVideoFramesReceived     AS QUAD    ' DWORDLONG
   cVideoFramesEncoded      AS QUAD    ' DWORDLONG
   cVideoFramesSkipped      AS QUAD    ' DWORDLONG
   cBlackVideoFramesEncoded AS QUAD    ' DWORDLONG
   cVideoFramesDuplicated   AS QUAD    ' DWORDLONG
   cAudioSamplesPerSec      AS DWORD   ' DWORD
   cAudioChannels           AS DWORD   ' DWORD
   cAudioBytesReceived      AS QUAD    ' DWORDLONG
   cAudioFramesEncoded      AS QUAD    ' DWORDLONG
END TYPE

'#endif // (WINVER >= _WIN32_WINNT_WIN7)
