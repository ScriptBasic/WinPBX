' ########################################################################################
' Microsoft Windows
' File: AppAvCap.inc
' Contents: Network audio/video application capability interface.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%APPAVCAP_INC = 1

#INCLUDE ONCE "mmreg.inc"
#INCLUDE ONCE "msacm.inc"

'#include <pshpack8.h> /* Assume 8 byte packing throughout */

'// For use as dimension for variable size arrays
%VARIABLE_DIM = 1

'// CPU utilization numbers for NetMeeting-provided codecs
%LNH_48_CPU  = 97
%LNH_8_CPU   = 47
%LNH_12_CPU  = 48
%LNH_16_CPU  = 49
%MS_G723_CPU = 70
%CCITT_A_CPU = 24
%CCITT_U_CPU = 25

'// AUDIO_FORMAT_ID is an index into an array of AUDCAPS structures
'typedef DWORD AUDIO_FORMAT_ID;
%INVALID_AUDIO_FORMAT = &Hffffffff???
'typedef DWORD MEDIA_FORMAT_ID;
%INVALID_MEDIA_FORMAT = &Hffffffff???
'// VIDEO_FORMAT_ID is an index into an array of VIDCAPS structures
'typedef DWORD VIDEO_FORMAT_ID;
%INVALID_VIDEO_FORMAT = &Hffffffff???

'/*
' *  @doc  EXTERNAL DATASTRUC
' *
' *   AUDIO capabilities info structure
' *
' *   @struct AUDCAP_INFO | AUDIO capabilities info structure.
' *   Use for both input and output when calling capabilties APIs.
' *   The fields are input-only, output-only or input/output depending on the API used.
' *   Behavior is undefined if these are altered.
' */

'// basic audcap structure
' // Size = 160 bytes
TYPE BASIC_AUDCAP_INFO  ' Must be 8 bytes aligned
   wFormatTag            AS WORD    ' WORD // @field The ACM format tag
   filler1_              AS WORD    ' // To keep 8 byte alignment
   Id                    AS DWORD   ' AUDIO_FORMAT_ID// @field (OUTPUT only) The local id (a.k.a. *Handle*) of this capability entry
   szFormat              AS ASCIIZ * %ACMFORMATDETAILS_FORMAT_CHARS   ' char // @field (OUTPUT only) Descriptive string of
                                    ' // the format, e.g. "Microsoft GSM 6.10"
   uMaxBitrate           AS DWORD   ' UINT // @field (OUTPUT only) Worst case bitrate
   uAvgBitrate           AS DWORD   ' UINT // @field The average bitrate for this codec
   wCPUUtilizationEncode AS WORD    ' WORD // @field % of Pentium 90Mhz needed for compress
   wCPUUtilizationDecode AS WORD    ' WORD // @field % of Pentium 90Mhz needed for decompress
   bSendEnabled          AS LONG    ' BOOL // @field OK to use this format for sending
   bRecvEnabled          AS LONG    ' BOOL // @field OK to use this format for receiving
   wSortIndex            AS WORD    ' WORD // @field The ordered position of this entry in the
                                    ' // capability table. Can be used as input only in ReorderFormats
   filler2_              AS WORD    ' // To keep 8 byte alignment
END TYPE

MACRO AUDCAP_INFO = BASIC_AUDCAP_INFO

'/*
' *   @struct AUDCAP_INFO_LIST | List of AUDCAP_INFO structures
' */
' // Size = 164 bytes
TYPE AUDCAP_INFO_LIST   ' Must be 8 bytes aligned
   cFormats    AS DWORD         ' ULONG // @field Number of AUDCAP_INFO structures in this list
   aFormats(0) AS AUDCAP_INFO   ' variable size array // @field cFormats AUDCAP_INFO structures
END TYPE

'/*
' *   @enum VIDEO_SIZES | Enumeration values for the three video sizes supported by NetMeeting
' */
' enum VIDEO_SIZES
'%VIDEO_SIZES_Small  = 0   ' // @emem Small size video
'%VIDEO_SIZES_Medium = 1   ' // @emem Medium size video
'%VIDEO_SIZES_Large  = 2   ' // @emem Large size video

' enum VIDEO_SIZES
MACRO VIDEO_SIZES_ENUM = LONG
%VIDEO_SIZES_Small  = 0   ' // @emem Small size video
%VIDEO_SIZES_Medium = 1   ' // @emem Medium size video
%VIDEO_SIZES_Large  = 2   ' // @emem Large size video

'/*
' *   VIDEO capabilities info structure
' *
' *   @struct VIDCAP_INFO | VIDEO capabilities info structure.
' *   Use for both input and output when calling capabilties APIs.
' *   The fields are input-only, output-only or input/output depending on the API used.
' *   Behavior is undefined if these are altered.
' */

'// VIDCAP_INFO structure
' // Size = 212 bytes - Must be 8 bytes aligned
TYPE BASIC_VIDCAP_INFO DWORD FILL
   ' // format identification
   dwFormatTag           AS DWORD               ' DWORD // @field The format tag of this format
   Id                    AS DWORD               ' VIDEO_FORMAT_ID // @field (OUTPUT only) The local id (a.k.a. *Handle*) of this capability entry
   szFormat              AS ASCIIZ * %ACMFORMATDETAILS_FORMAT_CHARS   ' char // @field (OUTPUT only) Descriptive string of the format e.g. "Microsoft H.263"
   ' // NetMeeting specific info
   wCPUUtilizationEncode AS WORD               ' WORD // @field % of Pentium 90Mhz needed for compress
   wCPUUtilizationDecode AS WORD               ' WORD // @field % of Pentium 90Mhz needed for decompress
   bSendEnabled          AS LONG               ' BOOL // @field OK to use this format for sending
   bRecvEnabled          AS LONG               ' BOOL // @field OK to use this format for receiving
   wSortIndex            AS WORD               ' WORD // @field (OUTPUT only) The ordered position of this entry in the capability table.
   ' // video format details
   enumVideoSize         AS VIDEO_SIZES_ENUM   ' VIDEO_SIZES // @field The video size for this format. Different video sizes for
                                               '             // the same formats must be added as separate formats
   bih                   AS BITMAPINFOHEADER   ' BITMAPINFOHEADER // @field The BITMAPINFOHEADER sturcture for the video size in enumVideosize
   uFrameRate            AS DWORD              ' UINT  // @field Number of frames per second
   dwBitsPerSample       AS DWORD              ' DWORD // @field number of bits per sample for this format. Must match the value in bih.biBitCount
   uAvgBitrate           AS DWORD              ' UINT  // @field The average bitrate for this codec
   uMaxBitrate           AS DWORD              ' UINT  // (OUTPUT only) Worst case bitrate
END TYPE

MACRO VIDCAP_INFO = BASIC_VIDCAP_INFO

'/*
' *   @struct VIDCAP_INFO_LIST | List of VIDCAP_INFO structures
' */
' // Size = 216 bytes
TYPE VIDCAP_INFO_LIST   ' Must be 8 bytes aligned
   cFormats    AS DWORD         ' ULONG // @field Number of VIDCAP_INFO structures in this list
   aFormats(0) AS VIDCAP_INFO   ' variable size array // @field cFormats VIDCAP_INFO structures
END TYPE

'#include <poppack.h> /* End byte packing */
