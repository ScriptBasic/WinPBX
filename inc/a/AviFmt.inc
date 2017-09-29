' ########################################################################################
' Microsoft Windows
' File: AviFmt.inc
' Contents: Include file for working with AVI files
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE

#IF NOT %DEF(%VFW_INC)

   ' These equates and structures are also defined in vfw.inc

#IF NOT %DEF(%AVIFMT_INC)
    %AVIFMT_INC = 100   ' /* version number * 100 + revision */

#INCLUDE ONCE "windows.inc"

'// begin_vfw32

'/* The following is a short description of the AVI file format.  Please
' * see the accompanying documentation for a full explanation.
' *
' * An AVI file is the following RIFF form:
' *
' *   RIFF('AVI'
' *         LIST('hdrl'
' *          avih(<MainAVIHeader>)
' *                  LIST ('strl'
' *                      strh(<Stream header>)
' *                      strf(<Stream format>)
' *                      ... additional header data
' *            LIST('movi'
' *           { LIST('rec'
' *                  SubChunk...
' *               )
' *               | SubChunk } ....
' *            )
' *            [ <AVIIndex> ]
' *      )
' *
' *   The main file header specifies how many streams are present.  For
' *   each one, there must be a stream header chunk and a stream format
' *   chunk, enlosed in a 'strl' LIST chunk.  The 'strf' chunk contains
' *   type-specific format information; for a video stream, this should
' *   be a BITMAPINFO structure, including palette.  For an audio stream,
' *   this should be a WAVEFORMAT (or PCMWAVEFORMAT) structure.
' *
' *   The actual data is contained in subchunks within the 'movi' LIST
' *   chunk.  The first two characters of each data chunk are the
' *   stream number with which that data is associated.
' *
' *   Some defined chunk types:
' *           Video Streams:
' *                  ##db:   RGB DIB bits
' *                  ##dc:   RLE8 compressed DIB bits
' *                  ##pc:   Palette Change
' *
' *           Audio Streams:
' *                  ##wb:   waveform audio bytes
' *
' * The grouping into LIST 'rec' chunks implies only that the contents of
' *   the chunk should be read into memory at the same time.  This
' *   grouping is used for files specifically intended to be played from
' *   CD-ROM.
' *
' * The index chunk at the end of the file should contain one entry for
' *   each data chunk in the file.
' *
' * Limitations for the current software:
' *   Only one video stream and one audio stream are allowed.
' *   The streams must start at the beginning of the file.
' *
' *
' * To register codec types please obtain a copy of the Multimedia
' * Developer Registration Kit from:
' *
' *  Microsoft Corporation
' *  Multimedia Systems Group
' *  Product Marketing
' *  One Microsoft Way
' *  Redmond, WA 98052-6399
' *
' */

'#ifndef mmioFOURCC
'#define mmioFOURCC( ch0, ch1, ch2, ch3 )            \
'      ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |   \
'      ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
'#endif

#IF NOT %DEF(%MMIOFOURCC_DEFINED)
%MMIOFOURCC_DEFINED = 1
FUNCTION mmioFOURCC (BYVAL st0 AS STRING, BYVAL st1 AS STRING, BYVAL st2 AS STRING, BYVAL st3 AS STRING) AS DWORD
   LOCAL ch0 AS DWORD, ch1 AS DWORD, ch2 AS DWORD, ch3 AS DWORD
   ch0 = ASC(st0)
   ch1 = ASC(st1)
   ch2 = ASC(st2)
   ch3 = ASC(st3)
   SHIFT LEFT ch1, 8
   SHIFT LEFT ch2, 16
   SHIFT LEFT ch3, 24
   FUNCTION = ch0 OR ch1 OR ch2 OR ch3
END FUNCTION
#ENDIF

'/* Macro to make a TWOCC out of two characters */
'#ifndef aviTWOCC
'#define aviTWOCC(ch0, ch1) ((WORD)(BYTE)(ch0) | ((WORD)(BYTE)(ch1) << 8))
'#endif

#IF NOT %DEF(%AVITWOCC_DEFINED)
%AVITWOCC_DEFINED = 1
FUNCTION aviTWOCC (BYVAL st0 AS STRING, BYVAL st1 AS STRING) AS WORD
   LOCAL ch0 AS WORD, ch1 AS WORD
   ch0 = ASC(st0)
   ch1 = ASC(st1)
   SHIFT LEFT ch1, 8
   FUNCTION = ch0 OR ch1
END FUNCTION
#ENDIF

'typedef WORD TWOCC;

'/* form types, list types, and chunk types */
%formtypeAVI                 = &H20495641???   ' // mmioFOURCC('A', 'V', 'I', ' ')
%listtypeAVIHEADER           = &H6C726468???   ' // mmioFOURCC('h', 'd', 'r', 'l')
%ckidAVIMAINHDR              = &H68697661???   ' // mmioFOURCC('a', 'v', 'i', 'h')
%listtypeSTREAMHEADER        = &H6C727473???   ' // mmioFOURCC('s', 't', 'r', 'l')
%ckidSTREAMHEADER            = &H68727473???   ' // mmioFOURCC('s', 't', 'r', 'h')
%ckidSTREAMFORMAT            = &H66727473???   ' // mmioFOURCC('s', 't', 'r', 'f')
%ckidSTREAMHANDLERDATA       = &H64727473???   ' // mmioFOURCC('s', 't', 'r', 'd')
%ckidSTREAMNAME              = &H6E727473???   ' // mmioFOURCC('s', 't', 'r', 'n')

%listtypeAVIMOVIE            = &H69766F6D???   ' // mmioFOURCC('m', 'o', 'v', 'i')
%listtypeAVIRECORD           = &H20636572???   ' // mmioFOURCC('r', 'e', 'c', ' ')

%ckidAVINEWINDEX             = &H31786469???   ' // mmioFOURCC('i', 'd', 'x', '1')

'/*
'** Stream types for the <fccType> field of the stream header.
'*/
%streamtypeVIDEO = &H73646976???   ' mmioFOURCC('v', 'i', 'd', 's')
%streamtypeAUDIO = &H73647561???   ' mmioFOURCC('a', 'u', 'd', 's')
%streamtypeMIDI  = &H7364696D???   ' mmioFOURCC('m', 'i', 'd', 's')
%streamtypeTEXT  = &H73747874???   ' mmioFOURCC('t', 'x', 't', 's')

'/* Basic chunk types */
%cktypeDIBbits               = &H6264??       ' // aviTWOCC('d', 'b')
%cktypeDIBcompressed         = &H6364??       ' // aviTWOCC('d', 'c')
%cktypePALchange             = &H6370??       ' // aviTWOCC('p', 'c')
%cktypeWAVEbytes             = &H6277??       ' // aviTWOCC('w', 'b')

'/* Chunk id to use for extra chunks for padding. */
%ckidAVIPADDING              = &H4B4E554A???   ' // mmioFOURCC('J', 'U', 'N', 'K')

'/*
'** Useful macros
'**
'** Warning: These are nasty macro, and MS C 6.0 compiles some of them
'** incorrectly if optimizations are on.  Ack.
'*/

'/* Macro to get stream number out of a FOURCC ckid */
'#define FromHex(n)   (((n) >= 'A') ? ((n) + 10 - 'A') : ((n) - '0'))
'#define StreamFromFOURCC(fcc) ((WORD) ((FromHex(LOBYTE(LOWORD(fcc))) << 4) + \
'                                             (FromHex(HIBYTE(LOWORD(fcc))))))

FUNCTION FromHex (BYVAL n AS BYTE) AS BYTE
   IF n >= ASC("A") THEN
      FUNCTION = n + 10 - ASC("A")
   ELSE
      FUNCTION = n - ASC("0")
   END IF
END FUNCTION

FUNCTION StreamFromFOURCC (BYVAL fcc AS DWORD) AS WORD
   LOCAL w AS WORD
   LOCAL b1 AS BYTE
   LOCAL b2 AS BYTE
   w = LO(WORD, fcc)
   b1 = LO(BYTE, w)
   SHIFT LEFT b1, 4
   b1 = FromHex(b1)
   b2 = HI(BYTE, w)
   b2 = FromHex(b2)
   FUNCTION = b1 + b2
END FUNCTION

'/* Macro to get TWOCC chunk type out of a FOURCC ckid */
'#define TWOCCFromFOURCC(fcc)    HIWORD(fcc)
FUNCTION TWOCCFromFOURCC (BYVAL fcc AS DWORD) AS WORD
   FUNCTION = HI(WORD, fcc)
END FUNCTION

'/* Macro to make a ckid for a chunk out of a TWOCC and a stream number
'** from 0-255.
'*/
'#define ToHex(n)   ((BYTE) (((n) > 9) ? ((n) - 10 + 'A') : ((n) + '0')))
'#define MAKEAVICKID(tcc, stream) \
'        MAKELONG((ToHex((stream) & 0x0f) << 8) | \
'             (ToHex(((stream) & 0xf0) >> 4)), tcc)

FUNCTION ToHex (BYVAL n AS BYTE) AS BYTE
   IF n > 9 THEN
      FUNCTION = n - 10 + ASC("A")
   ELSE
      FUNCTION = n + ASC("0")
   END IF
END FUNCTION

FUNCTION MAKEAVICKID (BYVAL tcc AS WORD, BYVAL stream AS BYTE) AS DWORD
   LOCAL b1 AS BYTE
   LOCAL b2 AS BYTE
   b1 = stream AND &H0F?
   SHIFT LEFT b1, 8
   b1 = ToHex(b1)
   b2 = stream AND &HF0?
   SHIFT RIGHT b2, 4
   b2 = ToHex(b2)
   FUNCTION = MAK(DWORD, b1 OR b2, tcc)
END FUNCTION

'/*
'** Main AVI File Header
'*/

'/* flags for use in <dwFlags> in AVIFileHdr */
%AVIF_HASINDEX       = &H00000010???  ' // Index at end of file?
%AVIF_MUSTUSEINDEX   = &H00000020???
%AVIF_ISINTERLEAVED  = &H00000100???
%AVIF_TRUSTCKTYPE    = &H00000800???  ' // Use CKType to find key frames
%AVIF_WASCAPTUREFILE = &H00010000???
%AVIF_COPYRIGHTED    = &H00020000???

'/* The AVI File Header LIST chunk should be padded to this size */
%AVI_HEADERSIZE      = 2048        ' // size of AVI header list

' // Size = 56 bytes
TYPE MainAVIHeader DWORD
   dwMicroSecPerFrame    AS DWORD   ' DWORD // frame display rate (or 0L)
   dwMaxBytesPerSec      AS DWORD   ' DWORD // max. transfer rate
   dwPaddingGranularity  AS DWORD   ' DWORD // pad to multiples of this size; normally 2K.
   dwFlags               AS DWORD   ' DWORD // the ever-present flags
   dwTotalFrames         AS DWORD   ' DWORD // # frames in file
   dwInitialFrames       AS DWORD   ' DWORD
   dwStreams             AS DWORD   ' DWORD
   dwSuggestedBufferSize AS DWORD   ' DWORD
   dwWidth               AS DWORD   ' DWORD
   dwHeight              AS DWORD   ' DWORD
   dwReserved(3)         AS DWORD   ' DWORD
END TYPE

'/*
'** Stream header
'*/

%AVISF_DISABLED         = &H00000001???

%AVISF_VIDEO_PALCHANGES = &H00010000???

' // Size = 64 bytes
TYPE AVIStreamHeader DWORD FILL
   fccType               AS DWORD   ' FOURCC
   fccHandler            AS DWORD   ' FOURCC
   dwFlags               AS DWORD   ' DWORD /* Contains AVITF_* flags */
   wPriority             AS WORD    ' WORD
   wLanguage             AS WORD    ' WORD
   dwInitialFrames       AS DWORD   ' DWORD
   dwScale               AS DWORD   ' DWORD
   dwRate                AS DWORD   ' DWORD /* dwRate / dwScale == samples/second */
   dwStart               AS DWORD   ' DWORD
   dwLength              AS DWORD   ' DWORD /* In units above... */
   dwSuggestedBufferSize AS DWORD   ' DWORD
   dwQuality             AS DWORD   ' DWORD
   dwSampleSize          AS DWORD   ' DWORD
   rcFrame               AS RECT    ' RECT
END TYPE

'/* Flags for index */
%AVIIF_LIST          = &H00000001??? ' // chunk is a 'LIST'
%AVIIF_KEYFRAME      = &H00000010??? ' // this frame is a key frame.

%AVIIF_NOTIME        = &H00000100??? ' // this frame doesn't take any time
%AVIIF_COMPUSE       = &H0FFF0000??? ' // these bits are for compressor use

' // Size = 16 bytes
TYPE AVIINDEXENTRY DWORD
   ckid          AS DWORD    ' DWORD
   dwFlags       AS DWORD    ' DWORD
   dwChunkOffset AS DWORD    ' DWORD // Position of chunk
   dwChunkLength AS DWORD    ' DWORD // Length of chunk
END TYPE

'/*
'** Palette change chunk
'**
'** Used in video streams.
'*/
' // Size = 4 bytes
TYPE AVIPALCHANGE DWORD FILL
   bFirstEntry AS BYTE           ' BYTE /* first entry to change */
   bNumEntries AS BYTE           ' BYTE /* # entries to change (0 if 256) */
   wFlags      AS WORD           ' WORD /* Mostly to preserve alignment... */
   'peNew()     AS PALETTEENTRY   ' PALETTEENTRY[ ] /* New color specifications */
END TYPE

'// end_vfw32

#ENDIF   ' #IF NOT %DEF(%AVIFMT_INC)

#ENDIF   ' #IF NOT %DEF(%VFW_INC)
