' ########################################################################################
' Microsoft Windows
' File: aviriff.inc
' Contents: Structures and defines for the RIFF AVI file format extended to handle very large/long files.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AVIRIFF_INC = 1

'#if !defined NUMELMS
'  #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
'#endif

'// all structures in this file are packed on word boundaries
'//
'#include <pshpack2.h>

'/*
' * heres the general layout of an AVI riff file (new format)
' *
' * RIFF (3F??????) AVI       <- not more than 1 GB in size
' *     LIST (size) hdrl
' *         avih (0038)
' *         LIST (size) strl
' *             strh (0038)
' *             strf (????)
' *             indx (3ff8)   <- size may vary, should be sector sized
' *         LIST (size) strl
' *             strh (0038)
' *             strf (????)
' *             indx (3ff8)   <- size may vary, should be sector sized
' *         LIST (size) odml
' *             dmlh (????)
' *         JUNK (size)       <- fill to align to sector - 12
' *     LIST (7f??????) movi  <- aligned on sector - 12
' *         00dc (size)       <- sector aligned
' *         01wb (size)       <- sector aligned
' *         ix00 (size)       <- sector aligned
' *     idx1 (00??????)       <- sector aligned
' * RIFF (7F??????) AVIX
' *     JUNK (size)           <- fill to align to sector -12
' *     LIST (size) movi
' *         00dc (size)       <- sector aligned
' * RIFF (7F??????) AVIX      <- not more than 2GB in size
' *     JUNK (size)           <- fill to align to sector - 12
' *     LIST (size) movi
' *         00dc (size)       <- sector aligned
' *
' *-===================================================================*/

'//
'// structures for manipulating RIFF headers
'//
'#define FCC(ch4) ((((DWORD)(ch4) & 0xFF) << 24) |     \
'                  (((DWORD)(ch4) & 0xFF00) << 8) |    \
'                  (((DWORD)(ch4) & 0xFF0000) >> 8) |  \
'                  (((DWORD)(ch4) & 0xFF000000) >> 24))

MACRO FCC_(ch4) = CVDWD(ch4)

' // Size = 8 bytes
TYPE RIFFCHUNK WORD
   fcc AS DWORD   ' FOURCC
   cb  AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE RIFFLIST WORD
   fcc         AS DWORD   ' FOURCC
   cb          AS DWORD   ' DWORD
   fccListType AS DWORD   ' FOURCC
END TYPE

'#define RIFFROUND(cb) ((cb) + ((cb)&1))
MACRO RIFFROUND(cb) = cb + (cb AND 1)

'#define RIFFNEXT(pChunk) (LPRIFFCHUNK)((LPBYTE)(pChunk) \
'                          + sizeof(RIFFCHUNK) \
'                          + RIFFROUND(((LPRIFFCHUNK)pChunk)->cb))

FUNCTION RIFFNEXT(BYVAL pChunk AS RIFFCHUNK PTR) AS DWORD
   IF pChunk THEN FUNCTION = pChunk + SIZEOF(RIFFCHUNK) + RIFFROUND(@pChunk.cb)
END FUNCTION

'//
'// ==================== avi header structures ===========================
'//

'// main header for the avi file (compatibility header)
'//
'#define ckidMAINAVIHEADER FCC('avih')
%ckidMAINAVIHEADER = &H68697661???

%AVIF_HASINDEX        = &H00000010???   ' // Index at end of file?
%AVIF_MUSTUSEINDEX    = &H00000020???
%AVIF_ISINTERLEAVED   = &H00000100???
%AVIF_TRUSTCKTYPE     = &H00000800???   ' // Use CKType to find key frames
%AVIF_WASCAPTUREFILE  = &H00010000???
%AVIF_COPYRIGHTED     = &H00020000???

' // Size = 64 bytes
TYPE AVIMAINHEADER WORD
   fcc                   AS DWORD   ' FOURCC // 'avih'
   cb                    AS DWORD   ' DWORD // size of this structure -8
   dwMicroSecPerFrame    AS DWORD   ' DWORD // frame display rate (or 0L)
   dwMaxBytesPerSec      AS DWORD   ' DWORD // max. transfer rate
   dwPaddingGranularity  AS DWORD   ' DWORD // pad to multiples of this size; normally 2K.
   dwFlags               AS DWORD   ' DWORD // the ever-present flags
   dwTotalFrames         AS DWORD   ' DWORD // # frames in first movi list
   dwInitialFrames       AS DWORD   ' DWORD
   dwStreams             AS DWORD   ' DWORD
   dwSuggestedBufferSize AS DWORD   ' DWORD
   dwWidth               AS DWORD   ' DWORD
   dwHeight              AS DWORD   ' DWORD
   dwReserved(3)         AS DWORD   ' DWORD
END TYPE

'#define ckidODML          FCC('odml')
'#define ckidAVIEXTHEADER  FCC('dmlh')
%ckidODML         = &H6C6D646F???
%ckidAVIEXTHEADER = &H686C6D64???

' // Size = 256 bytes
TYPE AVIEXTHEADER WORD
   fcc           AS DWORD   ' FOURCC // 'dmlh'
   cb            AS DWORD   ' DWORD // size of this structure -8
   dwGrandFrames AS DWORD   ' DWORD // total number of frames in the file
   dwFuture(60)  AS DWORD   ' DWORD // to be defined later
END TYPE

'//
'// structure of an AVI stream header riff chunk
'//
'#define ckidSTREAMLIST   FCC('strl')
%ckidSTREAMLIST = &H6C727473???

#IF NOT %DEF(%ckidSTREAMHEADER)
'#define ckidSTREAMHEADER FCC('strh')
%ckidSTREAMHEADER = &H6872747???
#ENDIF

#IF NOT %DEF(%streamtypeVIDEO)
'#define streamtypeVIDEO FCC('vids')
'#define streamtypeAUDIO FCC('auds')
'#define streamtypeMIDI  FCC('mids')
'#define streamtypeTEXT  FCC('txts')
%streamtypeVIDEO = &H73646976???
%streamtypeAUDIO = &H73647561???
%streamtypeMIDI  = &H7364696D???
%streamtypeTEXT  = &H73747874???
#ENDIF

%AVISF_DISABLED          = &H00000001???
%AVISF_VIDEO_PALCHANGES  = &H00010000???

' // Size = 8 bytes
TYPE AVISTREAMHEADER_rcFrame WORD FILL
   left   AS INTEGER   ' short int
   top    AS INTEGER   ' short int
   right  AS INTEGER   ' short int
   bottom AS INTEGER   ' short int
END TYPE

' // Size = 64 bytes
TYPE AVISTREAMHEADER WORD FILL
   fcc                   AS DWORD   ' FOURCC // 'strh'
   cb                    AS DWORD   ' DWORD // size of this structure - 8
   fccType               AS DWORD   ' FOURCC // stream type codes
   fccHandler            AS DWORD   ' FOURCC
   dwFlags               AS DWORD   ' DWORD
   wPriority             AS WORD    ' WORD
   wLanguage             AS WORD    ' WORD
   dwInitialFrames       AS DWORD   ' DWORD
   dwScale               AS DWORD   ' DWORD
   dwRate                AS DWORD   ' DWORD // dwRate/dwScale is stream tick rate in ticks/sec
   dwStart               AS DWORD   ' DWORD
   dwLength              AS DWORD   ' DWORD
   dwSuggestedBufferSize AS DWORD   ' DWORD
   dwQuality             AS DWORD   ' DWORD
   dwSampleSize          AS DWORD   ' DWORD
   rcFrame               AS AVISTREAMHEADER_rcFrame
END TYPE

'//
'// structure of an AVI stream format chunk
'//
#IF NOT %DEF(%ckidSTREAMFORMAT)
'#define ckidSTREAMFORMAT FCC('strf')
%ckidSTREAMFORMAT = &H66727473???
#ENDIF

'//
'// avi stream formats are different for each stream type
'//
'// BITMAPINFOHEADER for video streams
'// WAVEFORMATEX or PCMWAVEFORMAT for audio streams
'// nothing for text streams
'// nothing for midi streams

'//
'// structure of old style AVI index
'//
'#define ckidAVIOLDINDEX FCC('idx1')
%ckidAVIOLDINDEX = &H31786469???

#IF NOT %DEF(%AVIIF_LIST)
%AVIIF_LIST       = &H00000001???
%AVIIF_KEYFRAME   = &H00000010???
#ENDIF

%AVIIF_NO_TIME    = &H00000100???
%AVIIF_COMPRESSOR = &H0FFF0000???   ' // unused?

' // Size = 16 bytes
TYPE AVIOLDINDEX_ENTRY WORD
   dwChunkId AS DWORD   ' DWORD
   dwFlags   AS DWORD   ' DWORD
   dwOffset  AS DWORD   ' DWORD // offset of riff chunk header for the data
   dwSize    AS DWORD   ' DWORD // size of the data (excluding riff header size)
END TYPE

' This structure consists of the initial RIFF chunk (the fcc and cb members)
' followed by one index entry for each data chunk in the 'movi' list.

' // Size = 8 bytes
TYPE AVIOLDINDEX WORD
   fcc       AS DWORD               ' FOURCC // 'idx1'
   cb        AS DWORD               ' DWORD // size of this structure -8
   'aIndex() AS AVIOLDINDEX_ENTRY   ' variable-length // size of this array
END TYPE

'//
'// ============ structures for timecode in an AVI file =================
'//

' This structure is arealdy defined in strmif.inc, although the third member
' is defined as DWORD dwFrames instead of LONG cFrames.

'#ifndef TIMECODE_DEFINED
'#define TIMECODE_DEFINED

'// defined
'// timecode time structure
'//
'typedef union _timecode {
'   struct {
'      WORD   wFrameRate;
'      WORD   wFrameFract;
'      LONG   cFrames;
'      };
'   DWORDLONG  qw;
'   } TIMECODE;

'#endif // TIMECODE_DEFINED

#IF NOT %DEF(%TIMECODE_DEFINED)
%TIMECODE_DEFINED = 1

' // Size = 8 bytes
TYPE TIMECODE_STRUCT DWORD FILL
   wFrameRate  AS WORD
   wFrameFract AS WORD
   dwFrames    AS DWORD
END TYPE

' // Size = 8 bytes
UNION TIMECODE   ' Must be 8 bytes aligned
   TIMECODE_STRUCT
   qw AS QUAD
END UNION

#ENDIF

%TIMECODE_RATE_30DROP = 0   ' // this MUST be zero

'// struct for all the SMPTE timecode info
'//
' // Size = 16 bytes
TYPE TIMECODEDATA   ' Must be 8 bytes aligned
   time         AS TIMECODE
   dwSMPTEflags AS DWORD      ' DWORD
   dwUser       AS DWORD      ' DWORD
END TYPE

'// dwSMPTEflags masks/values
'//
%TIMECODE_SMPTE_BINARY_GROUP = &H07??
%TIMECODE_SMPTE_COLOR_FRAME  = &H08??

'//
'// ============ structures for new style AVI indexes =================
'//

'// index type codes
'//
%AVI_INDEX_OF_INDEXES       = &H00?
%AVI_INDEX_OF_CHUNKS        = &H01?
%AVI_INDEX_OF_TIMED_CHUNKS  = &H02?
%AVI_INDEX_OF_SUB_2FIELD    = &H03?
%AVI_INDEX_IS_DATA          = &H80?

'// index subtype codes
'//
%AVI_INDEX_SUB_DEFAULT     = &H00?

'// INDEX_OF_CHUNKS subtype codes
'//
%AVI_INDEX_SUB_2FIELD      = &H01?

'// meta structure of all avi indexes
'//
' // Size = 32 bytes
TYPE AVIMETAINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC
   cb             AS DWORD   ' UINT
   wLongsPerEntry AS WORD    ' WORD
   bIndexSubType  AS BYTE    ' BYTE
   bIndexType     AS BYTE    ' BYTE
   nEntriesInUse  AS DWORD   ' DWORD
   dwChunkId      AS DWORD   ' DWORD
   dwReserved(2)  AS DWORD   ' DWORD
   'adwIndex()    AS DWORD   ' DWORD // variable-length
END TYPE

%STDINDEXSIZE = &H4000
'#define NUMINDEX(wLongsPerEntry) ((STDINDEXSIZE-32)/4/(wLongsPerEntry))
MACRO NUMINDEX(wLongsPerEntry) = ((%STDINDEXSIZE-32)\4)\wLongsPerEntry
'#define NUMINDEXFILL(wLongsPerEntry) ((STDINDEXSIZE/4) - NUMINDEX(wLongsPerEntry))
MACRO NUMINDEXFILL(wLongsPerEntry) = ((%STDINDEXSIZE\4) - NUMINDEX(wLongsPerEntry))

'// structure of a super index (INDEX_OF_INDEXES)
'//
'#define ckidAVISUPERINDEX FCC('indx')
%ckidAVISUPERINDEX = &H78646E69???

'typedef struct _avisuperindex {
'   FOURCC   fcc;               // 'indx'
'   UINT     cb;                // size of this structure
'   WORD     wLongsPerEntry;    // ==4
'   BYTE     bIndexSubType;     // ==0 (frame index) or AVI_INDEX_SUB_2FIELD
'   BYTE     bIndexType;        // ==AVI_INDEX_OF_INDEXES
'   DWORD    nEntriesInUse;     // offset of next unused entry in aIndex
'   DWORD    dwChunkId;         // chunk ID of chunks being indexed, (i.e. RGB8)
'   DWORD    dwReserved[3];     // must be 0
'   struct _avisuperindex_entry {
'      DWORDLONG qwOffset;    // 64 bit offset to sub index chunk
'      DWORD    dwSize;       // 32 bit size of sub index chunk
'      DWORD    dwDuration;   // time span of subindex chunk (in stream ticks)
'      } aIndex[NUMINDEX(4)];
'   } AVISUPERINDEX;

' // Size = 8 bytes
TYPE AVISUPERINDEX_ENTRY WORD
   qwOffset   AS QUAD    ' DWORDLONG // 64 bit offset to sub index chunk
   dwSize     AS DWORD   ' DWORD // 32 bit size of sub index chunk
   dwDuration AS DWORD   ' DWORD // time span of subindex chunk (in stream ticks)
END TYPE

' // Size = 16384 bytes
TYPE AVISUPERINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==4
   bIndexSubType  AS BYTE    ' BYTE // ==0 (frame index) or AVI_INDEX_SUB_2FIELD
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_OF_INDEXES
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // chunk ID of chunks being indexed, (i.e. RGB8)
   dwReserved(2)  AS DWORD   ' DWORD // must be 0
   aIndex(NUMINDEX(4) - 1) AS AVISUPERINDEX_ENTRY   ' aIndex[NUMINDEX(4)]
END TYPE

' Not needed. It is valid if wLongsPerEntry = 4
'#define Valid_SUPERINDEX(pi) (*(DWORD *)(&((pi)->wLongsPerEntry)) == (4 | (AVI_INDEX_OF_INDEXES << 24)))

'// struct of a standard index (AVI_INDEX_OF_CHUNKS)
'//
' // Size = 8 bytes
TYPE AVISTDINDEX_ENTRY WORD
   dwOffset AS DWORD   ' DWORD // 32 bit offset to data (points to data, not riff header)
   dwSize   AS DWORD   ' DWORD // 31 bit size of data (does not include size of riff header), bit 31 is deltaframe bit
END TYPE

'#define AVISTDINDEX_DELTAFRAME ( 0x80000000) // Delta frames have the high bit set
'#define AVISTDINDEX_SIZEMASK   (~0x80000000)
%AVISTDINDEX_DELTAFRAME = &H80000000???   ' // Delta frames have the high bit set
%AVISTDINDEX_SIZEMASK   = NOT &H80000000???

'typedef struct _avistdindex {
'   FOURCC   fcc;               // 'indx' or '##ix'
'   UINT     cb;                // size of this structure
'   WORD     wLongsPerEntry;    // ==2
'   BYTE     bIndexSubType;     // ==0
'   BYTE     bIndexType;        // ==AVI_INDEX_OF_CHUNKS
'   DWORD    nEntriesInUse;     // offset of next unused entry in aIndex
'   DWORD    dwChunkId;         // chunk ID of chunks being indexed, (i.e. RGB8)
'   DWORDLONG qwBaseOffset;     // base offset that all index intries are relative to
'   DWORD    dwReserved_3;      // must be 0
'   AVISTDINDEX_ENTRY aIndex[NUMINDEX(2)];
'   } AVISTDINDEX;

' // Size = 16384 bytes
TYPE AVISTDINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx' or '##ix'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==2
   bIndexSubType  AS BYTE    ' BYTE // ==0
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_OF_CHUNKS
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // chunk ID of chunks being indexed, (i.e. RGB8)
   qwBaseOffset   AS QUAD    ' DWORDLONG // base offset that all index intries are relative to
   dwReserved_3   AS DWORD   ' DWORD // must be 0
   aIndex(NUMINDEX(2) - 1) AS AVISTDINDEX_ENTRY   ' AVISTDINDEX_ENTRY aIndex[NUMINDEX(2)]
END TYPE

'// struct of a time variant standard index (AVI_INDEX_OF_TIMED_CHUNKS)
'//
'typedef struct _avitimedindex_entry {
'   DWORD dwOffset;       // 32 bit offset to data (points to data, not riff header)
'   DWORD dwSize;         // 31 bit size of data (does not include size of riff header) (high bit is deltaframe bit)
'   DWORD dwDuration;     // how much time the chunk should be played (in stream ticks)
'   } AVITIMEDINDEX_ENTRY;

' // Size = 12 bytes
TYPE AVITIMEDINDEX_ENTRY WORD
   dwOffset   AS DWORD   ' DWORD // 32 bit offset to data (points to data, not riff header)
   dwSize     AS DWORD   ' DWORD // 31 bit size of data (does not include size of riff header) (high bit is deltaframe bit)
   dwDuration AS DWORD   ' DWORD // how much time the chunk should be played (in stream ticks)
END TYPE

'typedef struct _avitimedindex {
'   FOURCC   fcc;               // 'indx' or '##ix'
'   UINT     cb;                // size of this structure
'   WORD     wLongsPerEntry;    // ==3
'   BYTE     bIndexSubType;     // ==0
'   BYTE     bIndexType;        // ==AVI_INDEX_OF_TIMED_CHUNKS
'   DWORD    nEntriesInUse;     // offset of next unused entry in aIndex
'   DWORD    dwChunkId;         // chunk ID of chunks being indexed, (i.e. RGB8)
'   DWORDLONG qwBaseOffset;     // base offset that all index intries are relative to
'   DWORD    dwReserved_3;      // must be 0
'   AVITIMEDINDEX_ENTRY aIndex[NUMINDEX(3)];
'   DWORD adwTrailingFill[NUMINDEXFILL(3)]; // to align struct to correct size
'   } AVITIMEDINDEX;

' // Size = 27312 bytes
TYPE AVITIMEDINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx' or '##ix'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==3
   bIndexSubType  AS BYTE    ' BYTE // ==0
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_OF_TIMED_CHUNKS
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // chunk ID of chunks being indexed, (i.e. RGB8)
   qwBaseOffset   AS QUAD    ' DWORDLONG // base offset that all index intries are relative to
   dwReserved_3   AS DWORD   ' DWORD // must be 0
   aIndex(NUMINDEX(3) - 2) AS AVITIMEDINDEX_ENTRY  ' AVITIMEDINDEX_ENTRY aIndex[NUMINDEX(3)]
   adwTrailingFill(NUMINDEXFILL(3)) AS DWORD   ' DWORD adwTrailingFill[NUMINDEXFILL(3)] // to align struct to correct size
END TYPE

'// structure of a timecode stream
'//
'typedef struct _avitimecodeindex {
'   FOURCC   fcc;               // 'indx' or '##ix'
'   UINT     cb;                // size of this structure
'   WORD     wLongsPerEntry;    // ==4
'   BYTE     bIndexSubType;     // ==0
'   BYTE     bIndexType;        // ==AVI_INDEX_IS_DATA
'   DWORD    nEntriesInUse;     // offset of next unused entry in aIndex
'   DWORD    dwChunkId;         // 'time'
'   DWORD    dwReserved[3];     // must be 0
'   TIMECODEDATA aIndex[NUMINDEX(sizeof(TIMECODEDATA)/sizeof(LONG))];
'   } AVITIMECODEINDEX;

' // Size = 16384 bytes
TYPE AVITIMECODEINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx' or '##ix'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==4
   bIndexSubType  AS BYTE    ' BYTE // ==0
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_IS_DATA
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // 'time'
   dwReserved(2)  AS DWORD   ' DWORD // must be 0
   aIndex(NUMINDEX(4) - 1) AS TIMECODEDATA
END TYPE

'// structure of a timecode discontinuity list (when wLongsPerEntry == 7)
'//
'typedef struct _avitcdlindex_entry {
'    DWORD    dwTick;           // stream tick time that maps to this timecode value
'    TIMECODE time;
'    DWORD    dwSMPTEflags;
'    DWORD    dwUser;
'    TCHAR    szReelId[12];
'    } AVITCDLINDEX_ENTRY;

' // Size = 32 bytes
TYPE AVITCDLINDEX_ENTRY WORD FILL
   dwTick       AS DWORD         ' DWORD // stream tick time that maps to this timecode value
   time         AS TIMECODE
   dwSMPTEflags AS DWORD         ' DWORD
   dwUser       AS DWORD         ' DWORD
   szReelId     AS ASCIIZ * 12   ' TCHAR
END TYPE

' Note: This additional version is needed because TCHARs are 2 bytes in unicode
' // Size = 44 bytes
TYPE AVITCDLINDEX_ENTRYW WORD FILL
   dwTick       AS DWORD         ' DWORD // stream tick time that maps to this timecode value
   time         AS TIMECODE
   dwSMPTEflags AS DWORD           ' DWORD
   dwUser       AS DWORD           ' DWORD
   szReelId     AS WSTRINGZ * 12   ' TCHAR
END TYPE

'typedef struct _avitcdlindex {
'   FOURCC   fcc;               // 'indx' or '##ix'
'   UINT     cb;                // size of this structure
'   WORD     wLongsPerEntry;    // ==7 (must be 4 or more all 'tcdl' indexes
'   BYTE     bIndexSubType;     // ==0
'   BYTE     bIndexType;        // ==AVI_INDEX_IS_DATA
'   DWORD    nEntriesInUse;     // offset of next unused entry in aIndex
'   DWORD    dwChunkId;         // 'tcdl'
'   DWORD    dwReserved[3];     // must be 0
'   AVITCDLINDEX_ENTRY aIndex[NUMINDEX(7)];
'   DWORD adwTrailingFill[NUMINDEXFILL(7)]; // to align struct to correct size
'   } AVITCDLINDEX;

' // Size = 32768 bytes
TYPE AVITCDLINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx' or '##ix'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==7 (must be 4 or more all 'tcdl' indexes
   bIndexSubType  AS BYTE    ' BYTE // ==0
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_IS_DATA
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // 'tcdl'
   dwReserved(2)  AS DWORD   ' DWORD     // must be 0
   aIndex(NUMINDEX(7) - 1) AS AVITCDLINDEX_ENTRY
   adwTrailingFill(NUMINDEXFILL(7) - 1) AS DWORD   ' to align struct to correct size
END TYPE

' // Size = 39776 bytes
TYPE AVITCDLINDEXW WORD FILL
   fcc            AS DWORD   ' FOURCC // 'indx' or '##ix'
   cb             AS DWORD   ' UINT // size of this structure
   wLongsPerEntry AS WORD    ' WORD // ==7 (must be 4 or more all 'tcdl' indexes
   bIndexSubType  AS BYTE    ' BYTE // ==0
   bIndexType     AS BYTE    ' BYTE // ==AVI_INDEX_IS_DATA
   nEntriesInUse  AS DWORD   ' DWORD // offset of next unused entry in aIndex
   dwChunkId      AS DWORD   ' DWORD // 'tcdl'
   dwReserved(2)  AS DWORD   ' DWORD     // must be 0
   aIndex(NUMINDEX(7) - 1) AS AVITCDLINDEX_ENTRYW
   adwTrailingFill(NUMINDEXFILL(7) - 1) AS DWORD   ' to align struct to correct size
END TYPE

'typedef struct _avifieldindex_chunk {
'   FOURCC   fcc;               // 'ix##'
'   DWORD    cb;                // size of this structure
'   WORD     wLongsPerEntry;    // must be 3 (size of each entry in
'                               // aIndex array)
'   BYTE     bIndexSubType;     // AVI_INDEX_2FIELD
'   BYTE     bIndexType;        // AVI_INDEX_OF_CHUNKS
'   DWORD    nEntriesInUse;     //
'   DWORD    dwChunkId;         // '##dc' or '##db'
'   DWORDLONG qwBaseOffset;     // offsets in aIndex array are relative to this
'   DWORD    dwReserved3;       // must be 0
'   struct _avifieldindex_entry {
'      DWORD    dwOffset;
'      DWORD    dwSize;         // size of all fields
'                               // (bit 31 set for NON-keyframes)
'      DWORD    dwOffsetField2; // offset to second field
'   } aIndex[  ];
'} AVIFIELDINDEX, * PAVIFIELDINDEX;

TYPE AVIFIELDINDEX_ENTRY WORD FILL
   dwOffset       AS DWORD   ' DWORD
   dwSize         AS DWORD   ' DWORD // size of all fields
                             ' // (bit 31 set for NON-keyframes)
   dwOffsetField2 AS DWORD   ' DWORD // offset to second field
END TYPE

' // Size = 32 bytes
TYPE AVIFIELDINDEX WORD FILL
   fcc            AS DWORD   ' FOURCC // 'ix##'
   cb             AS DWORD   ' DWORD // size of this structure
   wLongsPerEntry AS WORD    ' WORD // must be 3 (size of each entry in aIndex array)
   bIndexSubType  AS BYTE    ' BYTE  // AVI_INDEX_2FIELD
   bIndexType     AS BYTE    ' BYTE  // AVI_INDEX_OF_CHUNKS
   nEntriesInUsAS AS DWORD   ' DWORD
   dwChunkId      AS DWORD   ' DWORD // '##dc' or '##db'
   qwBaseOffset   AS QUAD    ' DWORDLONG // offsets in aIndex array are relative to this
   dwReserved3    AS DWORD   ' DWORD// must be 0
   'aIndex()      AS AVIFIELDINDEX_ENTRY   ' variable-length array
END TYPE

'#include <poppack.h>
