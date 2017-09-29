' ########################################################################################
' Microsoft Windows
' File: MPEGType.inc
' Contents: MPEG system stream compound type definition
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MPEGTYPE_INC = 1

#INCLUDE ONCE "uuids.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "mmreg.inc"

'//
'//  AM_MPEGSYSTEMTYPE defines the format block contents for
'//  data of type MEDIATYPE_MPEG1System when the format
'//  block GUID is FORMAT_MPEG1System
'//
'//  The format block consists of elements of type
'//  AM_MPEGSYSTEMTYPE up to the length of the format block
'//  Each format block is 8-byte aligned from the start of
'//  the format block
'//

' // Size = 84 bytes
TYPE AM_MPEGSTREAMTYPE DWORD
   dwStreamId AS DWORD           ' DWORD // Stream id of stream to process
   dwReserved AS DWORD           ' DWORD // 8-byte alignment
   mt         AS AM_MEDIA_TYPE   ' // Type for substream - pbFormat is NULL
   bFormat(0) AS BYTE            ' BYTE // Format data
END TYPE

' // Size = 92 bytes
TYPE AM_MPEGSYSTEMTYPE DWORD
   dwBitRate  AS DWORD               ' DWORD // Bits per second
   cStreams   AS DWORD               ' DWORD // Number of streams
   Streams(0) AS AM_MPEGSTREAMTYPE
END TYPE

'//
'//  Helper macros for AM_MPEGSTREAMTYPE
'//
'#define AM_MPEGSTREAMTYPE_ELEMENTLENGTH(pStreamType)  \
'    FIELD_OFFSET(AM_MPEGSTREAMTYPE, bFormat[(pStreamType)->mt.cbFormat])
'#define AM_MPEGSTREAMTYPE_NEXT(pStreamType)           \
'    ((AM_MPEGSTREAMTYPE *)((PBYTE)(pStreamType) +     \
'     ((AM_MPEGSTREAMTYPE_ELEMENTLENGTH(pStreamType) + 7) & ~7)))

'//
'// IMpegAudioDecoder
'//

'// Values for DualMode
%AM_MPEG_AUDIO_DUAL_MERGE = 0
%AM_MPEG_AUDIO_DUAL_LEFT  = 1
%AM_MPEG_AUDIO_DUAL_RIGHT = 2

' ########################################################################################
' Interface name = IMpegAudioDecoder
' IID = B45DD570-3C77-11D1-ABE1-00A0C905F375
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMpegAudioDecoder_INTERFACE_DEFINED)
    %IMpegAudioDecoder_INTERFACE_DEFINED = 1

INTERFACE IMpegAudioDecoder $IID_IMpegAudioDecoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_FrequencyDivider ( _                      ' VTable offset = 12
     BYREF pDivider AS DWORD _                          ' __out unsigned long *pDivider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_FrequencyDivider ( _                      ' VTable offset = 16
     BYVAL Divider AS DWORD _                           ' __in unsigned long Divider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DecoderAccuracy ( _                       ' VTable offset = 20
     BYREF pAccuracy AS DWORD _                         ' __out unsigned long *pAccuracy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DecoderAccuracy ( _                       ' VTable offset = 24
     BYVAL Accuracy AS DWORD _                          ' __in unsigned long Accuracy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Stereo ( _                                ' VTable offset = 28
     BYREF pStereo AS DWORD _                           ' __out unsigned long *pStereo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Stereo ( _                                ' VTable offset = 32
     BYVAL Stereo AS DWORD _                            ' __in unsigned long Stereo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DecoderWordSize ( _                       ' VTable offset = 36
     BYREF pWordSize AS DWORD _                         ' __out unsigned long *pWordSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DecoderWordSize ( _                       ' VTable offset = 40
     BYVAL WordSize AS DWORD _                          ' __in unsigned long WordSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IntegerDecode ( _                         ' VTable offset = 44
     BYREF pIntDecode AS DWORD _                        ' __out unsigned long *pIntDecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IntegerDecode ( _                         ' VTable offset = 48
     BYVAL IntDecode AS DWORD _                         ' __in unsigned long IntDecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DualMode ( _                              ' VTable offset = 52
     BYREF pIntDecode AS DWORD _                        ' __out unsigned long *pIntDecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DualMode ( _                              ' VTable offset = 56
     BYVAL IntDecode AS DWORD _                         ' __in unsigned long IntDecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AudioFormat ( _                           ' VTable offset = 60
     BYREF lpFmt AS MPEG1WAVEFORMAT _                   ' __out MPEG1WAVEFORMAT *lpFmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMpegAudioDecoder_INTERFACE_DEFINED__ */
