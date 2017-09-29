' ########################################################################################
' Microsoft Windows
' File: Vfw.inc
' Contents: Video for windows include file for WIN32
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VFW_INC = 1

'/****************************************************************************
' *
' *      VfW.H - Video for windows include file for WIN32
' *
' *      Copyright (c) 1991-1995, Microsoft Corp.  All rights reserved.
' *
' *      This include files defines interfaces to the following
' *      video components
' *
' *          COMPMAN         - Installable Compression Manager.
' *          DRAWDIB         - Routines for drawing to the display.
' *          VIDEO           - Video Capture Driver Interface
' *
' *          AVIFMT          - AVI File Format structure definitions.
' *          MMREG           - FOURCC and other things
' *
' *          AVIFile         - Interface for reading AVI Files and AVI Streams
' *          MCIWND          - MCI/AVI window class
' *          AVICAP          - AVI Capture Window class
' *
' *          MSACM           - Audio compression manager.
' *
' *      The following symbols control inclusion of various parts of this file:
' *
' *          NOCOMPMAN       - dont include COMPMAN
' *          NODRAWDIB       - dont include DRAWDIB
' *          NOVIDEO         - dont include video capture interface
' *
' *          NOAVIFMT        - dont include AVI file format structs
' *          NOMMREG         - dont include MMREG
' *
' *          NOAVIFILE       - dont include AVIFile interface
' *          NOMCIWND        - dont include AVIWnd class.
' *          NOAVICAP        - dont include AVICap class.
' *
' *          NOMSACM         - dont include ACM stuff.
' *
' ****************************************************************************/

#INCLUDE ONCE "windows.inc"

'/****************************************************************************
' *
' *  types
' *
' ***************************************************************************/

'#define VFWAPI  WINAPI
'#define VFWAPIV WINAPIV
'#define VFWAPI_INLINE  WINAPI_INLINE

'/****************************************************************************
' *
' *  VideoForWindowsVersion() - returns version of VfW
' *
' ***************************************************************************/

DECLARE FUNCTION VideoForWindowsVersion IMPORT "MSVFW32.DLL" ALIAS "VideoForWindowsVersion" ( _
 ) AS DWORD                                             ' DWORD

'/****************************************************************************
' *
' *  call these to start stop using VfW from your app.
' *
' ***************************************************************************/

DECLARE FUNCTION InitVFW IMPORT "MSVFW32.DLL" ALIAS "InitVFW" () AS LONG
DECLARE FUNCTION TermVFW IMPORT "MSVFW32.DLL" ALIAS "TermVFW" () AS LONG

'/****************************************************************************
' *
' *  do we need MMSYSTEM?
' *
' ****************************************************************************/

'#if !defined(_INC_MMSYSTEM) && (!defined(NOVIDEO) || !defined(NOAVICAP))
'    #include <mmsystem.h>
'#endif

#IF NOT %DEF(%MMSYSTEM_INC)
    #IF NOT %DEF(%NOVIDEO)
        #IF NOT %DEF(%NOAVICAP)
            #INCLUDE ONCE "mmsystem.inc"
        #ENDIF
   #ENDIF
#ENDIF

'/****************************************************************************/
'/*                                                                          */
'/*        Macros                                                            */
'/*                                                                          */
'/*  should we define this??                                                 */
'/*                                                                          */
'/****************************************************************************/

'#ifndef MKFOURCC
'#define MKFOURCC( ch0, ch1, ch2, ch3 )                                    \
'      ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |   \
'      ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
'#endif

'#if !defined(_INC_MMSYSTEM)
'    #define mmioFOURCC MKFOURCC
'#endif

#IF NOT %DEF(%MAKEFOURCC_DEFINED)
%MAKEFOURCC_DEFINED = 1
FUNCTION MAKEFOURCC (BYVAL st0 AS STRING, BYVAL st1 AS STRING, BYVAL st2 AS STRING, BYVAL st3 AS STRING) AS DWORD
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

'/****************************************************************************
' *
' *  COMPMAN - Installable Compression Manager.
' *
' ****************************************************************************/

#IF NOT %DEF(%NOCOMPMAN) ' ---------------------------------------------------------------

%ICVERSION     = &H0104

'DECLARE_HANDLE(HIC);     /* Handle to a Installable Compressor */

'//
'// this code in biCompression means the DIB must be accesed via
'// 48 bit pointers! using *ONLY* the selector given.
'//
%BI_1632 = &H32333631???    ' // '1632'

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

'#ifndef ICTYPE_VIDEO
'#define ICTYPE_VIDEO    mmioFOURCC('v', 'i', 'd', 'c')
'#define ICTYPE_AUDIO    mmioFOURCC('a', 'u', 'd', 'c')
'#endif

#IF NOT %DEF(%ICTYPE_VIDEO)
%ICTYPE_VIDEO          = &H63646976???   ' mmioFOURCC('v', 'i', 'd', 'c')
%ICTYPE_AUDIO          = &H63647561???   ' mmioFOURCC('a', 'u', 'd', 'c')
#ENDIF

%ICERR_OK              = 0&
%ICERR_DONTDRAW        = 1&
%ICERR_NEWPALETTE      = 2&
%ICERR_GOTOKEYFRAME    = 3&
%ICERR_STOPDRAWING     = 4&

%ICERR_UNSUPPORTED     = -1&
%ICERR_BADFORMAT       = -2&
%ICERR_MEMORY          = -3&
%ICERR_INTERNAL        = -4&
%ICERR_BADFLAGS        = -5&
%ICERR_BADPARAM        = -6&
%ICERR_BADSIZE         = -7&
%ICERR_BADHANDLE       = -8&
%ICERR_CANTUPDATE      = -9&
%ICERR_ABORT           = -10&
%ICERR_ERROR           = -100&
%ICERR_BADBITDEPTH     = -200&
%ICERR_BADIMAGESIZE    = -201&

%ICERR_CUSTOM          = -400&   ' // errors less than ICERR_CUSTOM...
'#endif

'/* Values for dwFlags of ICOpen() */
#IF NOT %DEF(%ICMODE_COMPRESS)
%ICMODE_COMPRESS       = 1
%ICMODE_DECOMPRESS     = 2
%ICMODE_FASTDECOMPRESS = 3
%ICMODE_QUERY          = 4
%ICMODE_FASTCOMPRESS   = 5
%ICMODE_DRAW           = 8
#ENDIF
'#ifndef _WIN32               // ;Internal
'#define ICMODE_INTERNALF_FUNCTION32   0x8000   // ;Internal
'#define ICMODE_INTERNALF_MASK      0x8000   // ;Internal
'#endif                  // ;Internal

'/* Flags for AVI file index */
%AVIIF_LIST     = &H00000001???
%AVIIF_TWOCC    = &H00000002???
%AVIIF_KEYFRAME = &H00000010???

'/* quality flags */
%ICQUALITY_LOW      = 0
%ICQUALITY_HIGH     = 10000
%ICQUALITY_DEFAULT  = -1

'/************************************************************************
'************************************************************************/

%ICM_USER          = %DRV_USER + &H0000
%ICM_RESERVED_LOW  = %DRV_USER + &H1000
%ICM_RESERVED_HIGH = %DRV_USER + &H2000
%ICM_RESERVED      = %ICM_RESERVED_LOW

'/************************************************************************

'    messages.

'************************************************************************/

%ICM_GETSTATE              = %ICM_RESERVED + 0    ' // Get compressor state
%ICM_SETSTATE              = %ICM_RESERVED + 1    ' // Set compressor state
%ICM_GETINFO               = %ICM_RESERVED + 2    ' // Query info about the compressor

%ICM_CONFIGURE             = %ICM_RESERVED + 10   ' // show the configure dialog
%ICM_ABOUT                 = %ICM_RESERVED + 11   ' // show the about box

%ICM_GETERRORTEXT          = %ICM_RESERVED + 12   ' // get error text TBD ;Internal
%ICM_GETFORMATNAME         = %ICM_RESERVED + 20   ' // get a name for a format ;Internal
%ICM_ENUMFORMATS           = %ICM_RESERVED + 21   ' // cycle through formats ;Internal

%ICM_GETDEFAULTQUALITY     = %ICM_RESERVED + 30   ' // get the default value for quality
%ICM_GETQUALITY            = %ICM_RESERVED + 31   ' // get the current value for quality
%ICM_SETQUALITY            = %ICM_RESERVED + 32   ' // set the default value for quality

%ICM_SET                   = %ICM_RESERVED + 40   ' // Tell the driver something
%ICM_GET                   = %ICM_RESERVED + 41   ' // Ask the driver something

' // Constants for ICM_SET:
%ICM_FRAMERATE             = &H526D7246???   ' mmioFOURCC('F','r','m','R')
%ICM_KEYFRAMERATE          = &H5279654B???   ' mmioFOURCC('K','e','y','R')

'/************************************************************************

'    ICM specific messages.

'************************************************************************/

%ICM_COMPRESS_GET_FORMAT   = %ICM_USER + 4    ' // get compress format or size
%ICM_COMPRESS_GET_SIZE     = %ICM_USER + 5    ' // get output size
%ICM_COMPRESS_QUERY        = %ICM_USER + 6    ' // query support for compress
%ICM_COMPRESS_BEGIN        = %ICM_USER + 7    ' // begin a series of compress calls.
%ICM_COMPRESS              = %ICM_USER + 8    ' // compress a frame
%ICM_COMPRESS_END          = %ICM_USER + 9    ' // end of a series of compress calls.

%ICM_DECOMPRESS_GET_FORMAT = %ICM_USER + 10   ' // get decompress format or size
%ICM_DECOMPRESS_QUERY      = %ICM_USER + 11   ' // query support for dempress
%ICM_DECOMPRESS_BEGIN      = %ICM_USER + 12   ' // start a series of decompress calls
%ICM_DECOMPRESS            = %ICM_USER + 13   ' // decompress a frame
%ICM_DECOMPRESS_END        = %ICM_USER + 14   ' // end a series of decompress calls
%ICM_DECOMPRESS_SET_PALETTE= %ICM_USER + 29   ' // fill in the DIB color table
%ICM_DECOMPRESS_GET_PALETTE= %ICM_USER + 30   ' // fill in the DIB color table

%ICM_DRAW_QUERY            = %ICM_USER + 31   ' // query support for dempress
%ICM_DRAW_BEGIN            = %ICM_USER + 15   ' // start a series of draw calls
%ICM_DRAW_GET_PALETTE      = %ICM_USER + 16   ' // get the palette needed for drawing
%ICM_DRAW_UPDATE           = %ICM_USER + 17   ' // update screen with current frame ;Internal
%ICM_DRAW_START            = %ICM_USER + 18   ' // start decompress clock
%ICM_DRAW_STOP             = %ICM_USER + 19   ' // stop decompress clock
%ICM_DRAW_BITS             = %ICM_USER + 20   ' // decompress a frame to screen ;Internal
%ICM_DRAW_END              = %ICM_USER + 21   ' // end a series of draw calls
%ICM_DRAW_GETTIME          = %ICM_USER + 32   ' // get value of decompress clock
%ICM_DRAW                  = %ICM_USER + 33   ' // generalized "render" message
%ICM_DRAW_WINDOW           = %ICM_USER + 34   ' // drawing window has moved or hidden
%ICM_DRAW_SETTIME          = %ICM_USER + 35   ' // set correct value for decompress clock
%ICM_DRAW_REALIZE          = %ICM_USER + 36   ' // realize palette for drawing
%ICM_DRAW_FLUSH            = %ICM_USER + 37   ' // clear out buffered frames
%ICM_DRAW_RENDERBUFFER     = %ICM_USER + 38   ' // draw undrawn things in queue

%ICM_DRAW_START_PLAY       = %ICM_USER + 39   ' // start of a play
%ICM_DRAW_STOP_PLAY        = %ICM_USER + 40   ' // end of a play

%ICM_DRAW_SUGGESTFORMAT    = %ICM_USER + 50   ' // Like ICGetDisplayFormat
%ICM_DRAW_CHANGEPALETTE    = %ICM_USER + 51   ' // for animating palette

%ICM_DRAW_IDLE             = %ICM_USER + 52   ' // send each frame time ;Internal

%ICM_GETBUFFERSWANTED      = %ICM_USER + 41   ' // ask about prebuffering

%ICM_GETDEFAULTKEYFRAMERATE= %ICM_USER + 42   ' // get the default value for key frames


%ICM_DECOMPRESSEX_BEGIN    = %ICM_USER + 60   ' // start a series of decompress calls
%ICM_DECOMPRESSEX_QUERY    = %ICM_USER + 61   ' // start a series of decompress calls
%ICM_DECOMPRESSEX          = %ICM_USER + 62   ' // decompress a frame
%ICM_DECOMPRESSEX_END      = %ICM_USER + 63   ' // end a series of decompress calls

%ICM_COMPRESS_FRAMES_INFO  = %ICM_USER + 70   ' // tell about compress to come
%ICM_COMPRESS_FRAMES       = %ICM_USER + 71   ' // compress a bunch of frames ;Internal
%ICM_SET_STATUS_PROC       = %ICM_USER + 72   ' // set status callback

'/************************************************************************
'************************************************************************/

' // Size = 36 bytes
TYPE ICOPEN_STRUCT DWORD
   dwSize      AS DWORD                 ' DWORD // sizeof(ICOPEN)
   fccType     AS DWORD                 ' DWORD // 'vidc'
   fccHandler  AS DWORD                 ' DWORD
   dwVersion   AS DWORD                 ' DWORD // version of compman opening you
   dwFlags     AS DWORD                 ' DWORD // LOWORD is type specific
   dwError     AS DWORD                 ' LRESULT // error return.
   pV1Reserved AS DWORD                 ' LPVOID // Reserved
   pV2Reserved AS DWORD                 ' LPVOID // Reserved
   dnDevNode   AS DWORD                 ' DWORD // Devnode for PnP devices
END TYPE

MACRO tagICOPEN = ICOPEN_STRUCT

'/************************************************************************
'************************************************************************/

' // Size = 568 bytes
TYPE ICINFO_STRUCT DWORD
   dwSize        AS DWORD                ' DWORD // sizeof(ICINFO)
   fccType       AS DWORD                ' DWORD // compressor type     'vidc' 'audc'
   fccHandler    AS DWORD                ' DWORD // compressor sub-type 'rle ' 'jpeg' 'pcm '
   dwFlags       AS DWORD                ' DWORD // flags LOWORD is type specific
   dwVersion     AS DWORD                ' DWORD // version of the driver
   dwVersionICM  AS DWORD                ' DWORD // version of the ICM used
'    //
'    // under Win32, the driver always returns UNICODE strings.
'    //
   szName        AS WSTRINGZ * 16      ' WCHAR // short name
   szDescription AS WSTRINGZ * 128     ' WCHAR // long name
   szDriver      AS WSTRINGZ * 128     ' WCHAR // driver that contains compressor
END TYPE

MACRO tagICINFO = ICINFO_STRUCT

'/* Flags for the <dwFlags> field of the <ICINFO> structure. */
%VIDCF_QUALITY        = &H0001???  ' // supports quality
%VIDCF_CRUNCH         = &H0002???  ' // supports crunching to a frame size
%VIDCF_TEMPORAL       = &H0004???  ' // supports inter-frame compress
%VIDCF_COMPRESSFRAMES = &H0008???  ' // wants the compress all frames message
%VIDCF_DRAW           = &H0010???  ' // supports drawing
%VIDCF_FASTTEMPORALC  = &H0020???  ' // does not need prev frame on compress
%VIDCF_FASTTEMPORALD  = &H0080???  ' // does not need prev frame on decompress
'//#define VIDCF_QUALITYTIME    0x0040  // supports temporal quality

'//#define VIDCF_FASTTEMPORAL   (VIDCF_FASTTEMPORALC|VIDCF_FASTTEMPORALD)

'/************************************************************************
'************************************************************************/

%ICCOMPRESS_KEYFRAME = &H00000001???

' // Size = 48 bytes
TYPE ICCOMPRESS_STRUCT DWORD
   dwFlags     AS DWORD                    ' DWORD // flags
   lpbiOutput  AS BITMAPINFOHEADER PTR     ' LPBITMAPINFOHEADER // output format
   lpOutput    AS DWORD                    ' LPVOID // output data
   lpbiInput   AS BITMAPINFOHEADER PTR     ' LPBITMAPINFOHEADER // format of frame to compress
   lpInput     AS DWORD                    ' LPVOID // frame data to compress
   lpckid      AS DWORD PTR                ' LPDWORD // ckid for data in AVI file
   lpdwFlags   AS DWORD PTR                ' LPDWORD // flags in the AVI index.
   lFrameNum   AS LONG                     ' LONG // frame number of seq.
   dwFrameSize AS DWORD                    ' DWORD // reqested size in bytes. (if non zero)
   dwQuality   AS DWORD                    ' DWORD // quality
   ' // these are new fields
   lpbiPrev    AS BITMAPINFOHEADER PTR     ' LPBITMAPINFOHEADER // format of previous frame
   lpPrev      AS DWORD                    ' LPVOID // previous frame
END TYPE

MACRO tagICCOMPRESS = ICCOMPRESS_STRUCT

'/************************************************************************
'************************************************************************/

%ICCOMPRESSFRAMES_PADDING = &H00000001???

' // Size = 64 bytes
TYPE ICCOMPRESSFRAMES_STRUCT DWORD
   dwFlags            AS DWORD                   ' DWORD // flags
   lpbiOutput         AS BITMAPINFOHEADER PTR    ' LPBITMAPINFOHEADER // output format
   lOutput            AS LONG                    ' LPARAM // output identifier
   lpbiInput          AS BITMAPINFOHEADER PTR    ' LPBITMAPINFOHEADER // format of frame to compress
   lInput             AS LONG                    ' LPARAM // input identifier
   lStartFrame        AS LONG                    ' LONG // start frame
   lFrameCount        AS LONG                    ' LONG // # of frames
   lQuality           AS LONG                    ' LONG // quality
   lDataRate          AS LONG                    ' LONG // data rate
   lKeyRate           AS LONG                    ' LONG // key frame rate
   dwRate             AS DWORD                   ' DWORD // frame rate, as always
   dwScale            AS DWORD                   ' DWORD
   dwOverheadPerFrame AS DWORD                   ' DWORD
   dwReserved2        AS DWORD                   ' DWORD
   pGetData           AS DWORD                   ' LONG (CALLBACK *GetData)(LPARAM lInput, LONG lFrame, LPVOID lpBits, LONG len);
   pPutData           AS DWORD                   ' LONG (CALLBACK *PutData)(LPARAM lOutput, LONG lFrame, LPVOID lpBits, LONG len);
END TYPE

MACRO tagICCOMPRESSFRAMES = ICCOMPRESSFRAMES_STRUCT

' // messages for Status callback
%ICSTATUS_START     = 0
%ICSTATUS_STATUS    = 1      ' // l == % done
%ICSTATUS_END       = 2
%ICSTATUS_ERROR     = 3      ' // l == error string (LPSTR)
%ICSTATUS_YIELD     = 4
'// return nonzero means abort operation in progress

' // Size = 12 bytes
TYPE ICSETSTATUSPROC_STRUCT DWORD
   dwFlags AS DWORD   ' DWORD
   lParam  AS LONG    ' LPARAM
   Status  AS DWORD   ' LONG (CALLBACK *Status) (LPARAM lParam, UINT message, LONG l);
END TYPE

MACRO tagICSETSTATUSPROC = ICSETSTATUSPROC_STRUCT

'/************************************************************************
'************************************************************************/

%ICDECOMPRESS_HURRYUP      = &H80000000???  ' // don't draw just buffer (hurry up!)
%ICDECOMPRESS_UPDATE       = &H40000000???  ' // don't draw just update screen
%ICDECOMPRESS_PREROLL      = &H20000000???  ' // this frame is before real start
%ICDECOMPRESS_NULLFRAME    = &H10000000???  ' // repeat last frame
%ICDECOMPRESS_NOTKEYFRAME  = &H08000000???  ' // this frame is not a key frame

' // Size = 24 bytes
TYPE ICDECOMPRESS_STRUCT DWORD
   dwFlags    AS DWORD                 ' DWORD // flags (from AVI index...)
   lpbiInput  AS BITMAPINFOHEADER PTR  ' LPBITMAPINFOHEADER // BITMAPINFO of compressed data
                                       ' // biSizeImage has the chunk size
   lpInput    AS DWORD                 ' LPVOID // compressed data
   lpbiOutput AS BITMAPINFOHEADER PTR  ' LPBITMAPINFOHEADER // DIB to decompress to
   lpOutput   AS DWORD                 ' LPVOID
   ckid       AS DWORD                 ' DWORD // ckid from AVI file
END TYPE

MACRO tagICDECOMPRESS = ICDECOMPRESS_STRUCT

' // Size = 52 bytes
TYPE ICDECOMPRESSEX_STRUCT DWORD
   ' //
   ' // same as ICM_DECOMPRESS
   ' //
   dwFlags AS DWORD                  ' DWORD
   lpbiSrc AS BITMAPINFOHEADER PTR   ' LPBITMAPINFOHEADER // BITMAPINFO of compressed data
   lpSrc   AS DWORD                  ' LPVOID // compressed data
   lpbiDst AS BITMAPINFOHEADER PTR   ' LPBITMAPINFOHEADER // DIB to decompress to
   lpDst   AS DWORD                  ' LPVOID // output data
   ' //
   ' // new for ICM_DECOMPRESSEX
   ' //
   xDst    AS LONG                   ' int // destination rectangle
   yDst    AS LONG                   ' int
   dxDst   AS LONG                   ' int
   dyDst   AS LONG                   ' int
   xSrc    AS LONG                   ' int // source rectangle
   ySrc    AS LONG                   ' int
   dxSrc   AS LONG                   ' int
   dySrc   AS LONG                   ' int
END TYPE

MACRO tagICDECOMPRESSEX = ICDECOMPRESSEX_STRUCT

'/************************************************************************
'************************************************************************/

%ICDRAW_QUERY        = &H00000001???  ' // test for support
%ICDRAW_FULLSCREEN   = &H00000002???  ' // draw to full screen
%ICDRAW_HDC          = &H00000004???  ' // draw to a HDC/HWND
%ICDRAW_ANIMATE      = &H00000008???  ' // expect palette animation
%ICDRAW_CONTINUE     = &H00000010???  ' // draw is a continuation of previous draw
%ICDRAW_MEMORYDC     = &H00000020???  ' // DC is offscreen, by the way
%ICDRAW_UPDATING     = &H00000040???  ' // We're updating, as opposed to playing
%ICDRAW_RENDER       = &H00000080???  ' // used to render data not draw it
%ICDRAW_BUFFER       = &H00000100???  ' // please buffer this data offscreen, we will need to update it

' // Size = 60 bytes
TYPE ICDRAWBEGIN_STRUCT DWORD
   dwFlags AS DWORD                  ' DWORD    // flags
   hpal    AS DWORD                  ' HPALETTE // palette to draw with
   hwnd    AS DWORD                  ' HWND     // window to draw to
   hdc     AS DWORD                  ' HDC      // HDC to draw to
   xDst    AS LONG                   ' int      // destination rectangle
   yDst    AS LONG                   ' int
   dxDst   AS LONG                   ' int
   dyDst   AS LONG                   ' int
   lpbi    AS BITMAPINFOHEADER PTR   ' LPBITMAPINFOHEADER // format of frame to draw
   xSrc    AS LONG                   ' int      // source rectangle
   ySrc    AS LONG                   ' int
   dxSrc   AS LONG                   ' int
   dySrc   AS LONG                   ' int
   dwRate  AS DWORD                  ' DWORD    // frames/second = (dwRate/dwScale)
   dwScale AS DWORD                  ' DWORD
END TYPE

MACRO tagICDRAWBEGIN = ICDRAWBEGIN_STRUCT

'/************************************************************************
'************************************************************************/

%ICDRAW_HURRYUP      = &H80000000???     ' // don't draw just buffer (hurry up!)
%ICDRAW_UPDATE       = &H40000000???     ' // don't draw just update screen
%ICDRAW_PREROLL      = &H20000000???     ' // this frame is before real start
%ICDRAW_NULLFRAME    = &H10000000???     ' // repeat last frame
%ICDRAW_NOTKEYFRAME  = &H08000000???     ' // this frame is not a key frame

' // Size = 20 bytes
TYPE ICDRAW_STRUCT DWORD
   dwFlags  AS DWORD                   ' DWORD // flags
   lpFormat AS DWORD                   ' LPVOID // format of frame to decompress
   lpData   AS DWORD                   ' LPVOID // frame data to decompress
   cbData   AS DWORD                   ' DWORD
   lTime    AS LONG                    ' LONG // time in drawbegin units (see dwRate and dwScale)
END TYPE

MACRO tagICDRAW = ICDRAW_STRUCT

' // Size = 28 bytes
TYPE ICDRAWSUGGEST_STRUCT DWORD
   lpbiIn          AS DWORD            ' LPBITMAPINFOHEADER // format to be drawn
   lpbiSuggest     AS DWORD            ' LPBITMAPINFOHEADER // location for suggested format (or NULL to get size)
   dxSrc           AS LONG             ' int // source extent or 0
   dySrc           AS LONG             ' int
   dxDst           AS LONG             ' int // dest extent or 0
   dyDst           AS LONG             ' int
   hicDecompressor AS DWORD            ' HIC// decompressor you can talk to
END TYPE

MACRO tagICDRAWSUGGEST = ICDRAWSUGGEST_STRUCT

'/************************************************************************
'************************************************************************/

' // Size = 16 bytes
TYPE ICPALETTE_STRUCT DWORD
   dwFlags AS DWORD                    ' DWORD // flags (from AVI index...)
   iStart  AS LONG                     ' int // first palette to change
   iLen    AS LONG                     ' int // count of entries to change.
   lppe    AS PALETTEENTRY PTR         ' PALETTEENTRY // palette
END TYPE

MACRO tagICPALETTE = ICPALETTE_STRUCT

'/************************************************************************

'    ICM function declarations

'************************************************************************/

DECLARE FUNCTION ICInfo IMPORT "MSVFW32.DLL" ALIAS "ICInfo" ( _
   BYVAL fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYREF lpicinfo AS ICINFO_STRUCT _                    ' __out ICINFO FAR * lpicinfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ICInstall IMPORT "MSVFW32.DLL" ALIAS "ICInstall" ( _
   BYVAl fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYREF szDesc AS ASCIIZ _                             ' __in LPSTR szDesc
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ICRemove IMPORT "MSVFW32.DLL" ALIAS "ICRemove" ( _
   BYVAl fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ICGetInfo IMPORT "MSVFW32.DLL" ALIAS "ICGetInfo" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYREF picinfo AS ICINFO_STRUCT _                     ' __out ICINFO FAR *picinfo
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION ICOpen IMPORT "MSVFW32.DLL" ALIAS "ICOpen" ( _
   BYVAl fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYVAL wMode AS DWORD _                               ' __in UINT wMode
 ) AS DWORD                                             ' HIC

DECLARE FUNCTION ICOpenFunction IMPORT "MSVFW32.DLL" ALIAS "ICOpenFunction" ( _
   BYVAl fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYVAL wMode AS DWORD _                               ' __in UINT wMode
 , BYVAL lpfnHandler AS DWORD _                         ' __in FARPROC lpfnHandler
 ) AS DWORD                                             ' HIC

DECLARE FUNCTION ICClose IMPORT "MSVFW32.DLL" ALIAS "ICClose" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION ICSendMessage IMPORT "MSVFW32.DLL" ALIAS "ICSendMessage" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYVAL msg AS DWORD _                                 ' __in UINT msg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD_PTR dw1
 , BYVAL dw2 AS DWORD _                                 ' __in DWORD_PTR dw2
 ) AS LONG                                              ' LRESULT

'#ifndef _WIN32
'//this function is unsupported on Win32 as it is non-portable.
'LRESULT VFWAPIV ICMessage(HIC hic, UINT msg, UINT cb, ...);
'#endif


'/* Values for wFlags of ICInstall() */
%ICINSTALL_UNICODE        = &H8000???

%ICINSTALL_FUNCTION       = &H0001???  ' // lParam is a DriverProc (function ptr)
%ICINSTALL_DRIVER         = &H0002???  ' // lParam is a driver name (string)
%ICINSTALL_HDRV           = &H0004???  ' // lParam is a HDRVR (driver handle)

%ICINSTALL_DRIVERW        = &H8002???  ' // lParam is a unicode driver name

'/************************************************************************

'    query macros

'************************************************************************/
%ICMF_CONFIGURE_QUERY     = &H00000001???
%ICMF_ABOUT_QUERY         = &H00000001???

'#define ICQueryAbout(hic) \
'    (ICSendMessage(hic, ICM_ABOUT, (DWORD_PTR) -1, ICMF_ABOUT_QUERY) == ICERR_OK)

FUNCTION ICQueryAbout (BYVAL hic AS DWORD) AS LONG
   FUNCTION = (ICSendMessage(hic, %ICM_ABOUT, -1, %ICMF_ABOUT_QUERY) = %ICERR_OK)
END FUNCTION

'#define ICAbout(hic, hwnd) \
'    ICSendMessage(hic, ICM_ABOUT, (DWORD_PTR)(UINT_PTR)(hwnd), 0)

FUNCTION ICAbout (BYVAL hic AS DWORD, BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_ABOUT, hwnd, 0)
END FUNCTION

'#define ICQueryConfigure(hic) \
'    (ICSendMessage(hic, ICM_CONFIGURE, (DWORD_PTR) -1, ICMF_CONFIGURE_QUERY) == ICERR_OK)

FUNCTION ICQueryConfigure (BYVAL hic AS DWORD) AS LONG
   FUNCTION = (ICSendMessage(hic, %ICM_CONFIGURE, -1, %ICMF_CONFIGURE_QUERY) = %ICERR_OK)
END FUNCTION

'#define ICConfigure(hic, hwnd) \
'    ICSendMessage(hic, ICM_CONFIGURE, (DWORD_PTR)(UINT_PTR)(hwnd), 0)

FUNCTION ICConfigure (BYVAL hic AS DWORD, BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_CONFIGURE, hwnd, 0)
END FUNCTION

'/************************************************************************

'    get/set state macros

'************************************************************************/

'#define ICGetState(hic, pv, cb) \
'    ICSendMessage(hic, ICM_GETSTATE, (DWORD_PTR)(LPVOID)(pv), (DWORD_PTR)(cb))

FUNCTION ICGetState (BYVAL hic AS DWORD, BYVAL pv AS DWORD, BYVAL cb AS DWORD) AS LONG
   FUNCTION = (ICSendMessage(hic, %ICM_GETSTATE, pv, cb))
END FUNCTION

'#define ICSetState(hic, pv, cb) \
'    ICSendMessage(hic, ICM_SETSTATE, (DWORD_PTR)(LPVOID)(pv), (DWORD_PTR)(cb))

FUNCTION ICSetState (BYVAL hic AS DWORD, BYVAL pv AS DWORD, BYVAL cb AS DWORD) AS LONG
   FUNCTION = (ICSendMessage(hic, %ICM_SETSTATE, pv, cb))
END FUNCTION

'#define ICGetStateSize(hic) \
'    (DWORD) ICGetState(hic, NULL, 0)

FUNCTION ICGetStateSize (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICGetState(hic, %NULL, 0)
END FUNCTION

'/************************************************************************

'    get value macros

'************************************************************************/
'static DWORD dwICValue;

'#define ICGetDefaultQuality(hic) \
'    (ICSendMessage(hic, ICM_GETDEFAULTQUALITY, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)

FUNCTION ICGetDefaultQuality (BYVAL hic AS DWORD) AS DWORD
   LOCAL dwICValue AS DWORD
   ICSendMessage(hic, %ICM_GETDEFAULTQUALITY, VARPTR(dwICValue), 4)
   FUNCTION = dwICValue
END FUNCTION

'#define ICGetDefaultKeyFrameRate(hic) \
'    (ICSendMessage(hic, ICM_GETDEFAULTKEYFRAMERATE, (DWORD_PTR)(LPVOID)&dwICValue, sizeof(DWORD)), dwICValue)

FUNCTION ICGetDefaultKeyFrameRate (BYVAL hic AS DWORD) AS DWORD
   LOCAL dwICValue AS DWORD
   ICSendMessage(hic, %ICM_GETDEFAULTKEYFRAMERATE, VARPTR(dwICValue), 4)
   FUNCTION = dwICValue
END FUNCTION

'/************************************************************************

'    draw window macro

'************************************************************************/
'#define ICDrawWindow(hic, prc) \
'    ICSendMessage(hic, ICM_DRAW_WINDOW, (DWORD_PTR)(LPVOID)(prc), sizeof(RECT))

FUNCTION ICDrawWindow (BYVAL hic AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_WINDOW, VARPTR(prc), SIZEOF(RECT))
END FUNCTION

'/************************************************************************

'    compression functions

'************************************************************************/
'/*
' *  ICCompress()
' *
' *  compress a single frame
' *
' */

DECLARE FUNCTION ICCompress IMPORT "MSVFW32.DLL" ALIAS "ICCompress" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags // flags
 , BYREF lpbiOutput AS BITMAPINFOHEADER _               ' __in LPBITMAPINFOHEADER lpbiOutput // output format
 , BYREF lpData AS ANY _                                ' __out LPVOID lpData // output data
 , BYREF lpbiInput AS BITMAPINFOHEADER _                ' __in LPBITMAPINFOHEADER lpbiInput // // format of frame to compress
 , BYVAL lpBits AS DWORD _                              ' __in LPVOID lpBits // frame data to compress
 , BYREF lpckid AS DWORD _                              ' __out LPDWORD lpckid // ckid for data in AVI file
 , BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags // flags in the AVI index.
 , BYVAL lFrameNum AS LONG _                            ' __in LONG lFrameNum // frame number of seq.
 , BYVAL dwFrameSize AS DWORD _                         ' __in DWORD dwFrameSize // reqested size in bytes. (if non zero)
 , BYVAL dwQuality AS DWORD _                           ' __in DWORD dwQuality // quality within one frame
 , BYREF lpbiPrev AS BITMAPINFOHEADER _                 ' __in LPBITMAPINFOHEADER lpbiPrev // format of previous frame
 , BYVAL lpPrev AS DWORD _                              ' __in LPVOID lpPrev // previous frame
 ) AS DWORD                                             ' DWORD

'/*
' *  ICCompressBegin()
' *
' *  start compression from a source format (lpbiInput) to a dest
' *  format (lpbiOuput) is supported.
' *
' */
'#define ICCompressBegin(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_COMPRESS_BEGIN, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICCompressBegin (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_WINDOW, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'/*
' *  ICCompressQuery()
' *
' *  determines if compression from a source format (lpbiInput) to a dest
' *  format (lpbiOuput) is supported.
' *
' */
'#define ICCompressQuery(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_COMPRESS_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICCompressQuery (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_COMPRESS_QUERY, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'/*
' *  ICCompressGetFormat()
' *
' *  get the output format, (format of compressed data)
' *  if lpbiOutput is NULL return the size in bytes needed for format.
' *
' */
'#define ICCompressGetFormat(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_COMPRESS_GET_FORMAT, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICCompressGetFormat (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_COMPRESS_GET_FORMAT, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'#define ICCompressGetFormatSize(hic, lpbi) \
'    (DWORD) ICCompressGetFormat(hic, lpbi, NULL)

FUNCTION ICCompressGetFormatSize (BYVAL hic AS DWORD, BYREF lpbi AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_COMPRESS_GET_FORMAT, VARPTR(lpbi), %NULL)
END FUNCTION

'/*
' *  ICCompressSize()
' *
' *  return the maximal size of a compressed frame
' *
' */
'#define ICCompressGetSize(hic, lpbiInput, lpbiOutput) \
'    (DWORD) ICSendMessage(hic, ICM_COMPRESS_GET_SIZE, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICCompressGetSize (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_COMPRESS_GET_SIZE, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'#define ICCompressEnd(hic) \
'    ICSendMessage(hic, ICM_COMPRESS_END, 0, 0)

FUNCTION ICCompressEnd (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_COMPRESS_END, 0, 0)
END FUNCTION

'/************************************************************************

'    decompression functions

'************************************************************************/

'/*
' *  ICDecompress()
' *
' *  decompress a single frame
' *
' */
%ICDECOMPRESS_HURRYUP = &H80000000???    ' // don't draw just buffer (hurry up!)

DECLARE FUNCTION ICDecompress IMPORT "MSVFW32.DLL" ALIAS "ICDecompress" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags  // flags (from AVI index...)
 , BYREF lpbiFormat AS BITMAPINFOHEADER _               ' __in LPBITMAPINFOHEADER lpbiFormat  // BITMAPINFO of compressed data
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData  // data
 , BYREF lpbi AS BITMAPINFOHEADER _                     ' __in LPBITMAPINFOHEADER lpbi  // DIB to decompress to
 , BYREF lpBits AS ANY _                                ' __out lpBits LPVOID
 ) AS DWORD                                             ' DWORD

'/*
' *  ICDecompressBegin()
' *
' *  start compression from a source format (lpbiInput) to a dest
' *  format (lpbiOutput) is supported.
' *
' */
'#define ICDecompressBegin(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_DECOMPRESS_BEGIN, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICDecompressBegin (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_BEGIN, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'/*
' *  ICDecompressQuery()
' *
' *  determines if compression from a source format (lpbiInput) to a dest
' *  format (lpbiOutput) is supported.
' *
' */
'#define ICDecompressQuery(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_DECOMPRESS_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICDecompressQuery (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_QUERY, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'/*
' *  ICDecompressGetFormat()
' *
' *  get the output format, (format of un-compressed data)
' *  if lpbiOutput is NULL return the size in bytes needed for format.
' *
' */
'#define ICDecompressGetFormat(hic, lpbiInput, lpbiOutput) \
'    ((LONG) ICSendMessage(hic, ICM_DECOMPRESS_GET_FORMAT, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput)))

FUNCTION ICDecompressGetFormat (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_GET_FORMAT, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'#define ICDecompressGetFormatSize(hic, lpbi) \
'    ICDecompressGetFormat(hic, lpbi, NULL)

FUNCTION ICDecompressGetFormatSize (BYVAL hic AS DWORD, BYREF lpbi AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICDecompressGetFormat(hic, lpbi, BYVAL %NULL)
END FUNCTION

'/*
' *  ICDecompressGetPalette()
' *
' *  get the output palette
' *
' */
'#define ICDecompressGetPalette(hic, lpbiInput, lpbiOutput) \
'    ICSendMessage(hic, ICM_DECOMPRESS_GET_PALETTE, (DWORD_PTR)(LPVOID)(lpbiInput), (DWORD_PTR)(LPVOID)(lpbiOutput))

FUNCTION ICDecompressGetPalette (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER, BYREF lpbiOutput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_GET_PALETTE, VARPTR(lpbiInput), VARPTR(lpbiOutput))
END FUNCTION

'#define ICDecompressSetPalette(hic, lpbiPalette) \
'    ICSendMessage(hic, ICM_DECOMPRESS_SET_PALETTE, (DWORD_PTR)(LPVOID)(lpbiPalette), 0)

FUNCTION ICDecompressSetPalette (BYVAL hic AS DWORD, BYREF lpbiPalette AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_SET_PALETTE, VARPTR(lpbiPalette), 0)
END FUNCTION

'#define ICDecompressEnd(hic) \
'    ICSendMessage(hic, ICM_DECOMPRESS_END, 0, 0)

FUNCTION ICDecompressEnd (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESS_END, 0, 0)
END FUNCTION

'/************************************************************************

'    decompression (ex) functions

'************************************************************************/


'//
'// on Win16 these functions are macros that call ICMessage. ICMessage will
'// not work on NT. rather than add new entrypoints we have given
'// them as static inline functions
'//

'/*
' *  ICDecompressEx()
' *
' *  decompress a single frame
' *
' */
'static __inline LRESULT VFWAPI_INLINE
'ICDecompressEx(
'            HIC hic,
'            DWORD dwFlags,
'            LPBITMAPINFOHEADER lpbiSrc,
'            LPVOID lpSrc,
'            int xSrc,
'            int ySrc,
'            int dxSrc,
'            int dySrc,
'            LPBITMAPINFOHEADER lpbiDst,
'            LPVOID lpDst,
'            int xDst,
'            int yDst,
'            int dxDst,
'            int dyDst)
'{
'    ICDECOMPRESSEX ic;

'    ic.dwFlags = dwFlags;
'    ic.lpbiSrc = lpbiSrc;
'    ic.lpSrc = lpSrc;
'    ic.xSrc = xSrc;
'    ic.ySrc = ySrc;
'    ic.dxSrc = dxSrc;
'    ic.dySrc = dySrc;
'    ic.lpbiDst = lpbiDst;
'    ic.lpDst = lpDst;
'    ic.xDst = xDst;
'    ic.yDst = yDst;
'    ic.dxDst = dxDst;
'    ic.dyDst = dyDst;

'    // note that ICM swaps round the length and pointer
'    // length in lparam2, pointer in lparam1
'    return ICSendMessage(hic, ICM_DECOMPRESSEX, (DWORD_PTR)&ic, sizeof(ic));
'}

FUNCTION ICDecompressEx ( _
   BYVAL hic AS DWORD, _                         ' HIC hic
   BYVAL dwFlags AS DWORD, _                     ' DWORD dwFlags
   BYREF lpbiSrc AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiSrc,
   BYVAL lpSrc AS DWORD, _                       ' LPVOID lpSrc
   BYVAL xSrc AS LONG, _                         ' int xSrc
   BYVAL ySrc AS LONG, _                         ' int ySrc
   BYVAL dxSrc AS LONG, _                        ' int dxSrc
   BYVAL dySrc AS LONG, _                        ' int dySrc
   BYREF lpbiDst AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiDst
   BYVAL lpDst AS DWORD, _                       ' LPVOID lpDst
   BYVAL xDst AS LONG, _                         ' int xDst
   BYVAL yDst AS LONG, _                         ' int yDst
   BYVAL dxDst AS LONG, _                        ' int dxDst
   BYVAL dyDst AS LONG _                         ' int dyDst
   ) AS LONG                                     ' LRESULT

   LOCAL ic AS ICDECOMPRESSEX_STRUCT

   ic.dwFlags = dwFlags
   ic.lpbiSrc = VARPTR(lpbiSrc)
   ic.lpSrc = lpSrc
   ic.xSrc = xSrc
   ic.ySrc = ySrc
   ic.dxSrc = dxSrc
   ic.dySrc = dySrc
   ic.lpbiDst = VARPTR(lpbiDst)
   ic.lpDst = lpDst
   ic.xDst = xDst
   ic.yDst = yDst
   ic.dxDst = dxDst
   ic.dyDst = dyDst

   ' // note that ICM swaps round the length and pointer
   ' // length in lparam2, pointer in lparam1
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESSEX, VARPTR(ic), sizeof(ic))

END FUNCTION

'/*
' *  ICDecompressExBegin()
' *
' *  start compression from a source format (lpbiInput) to a dest
' *  format (lpbiOutput) is supported.
' *
' */
'static __inline LRESULT VFWAPI_INLINE
'ICDecompressExBegin(
'            HIC hic,
'            DWORD dwFlags,
'            LPBITMAPINFOHEADER lpbiSrc,
'            LPVOID lpSrc,
'            int xSrc,
'            int ySrc,
'            int dxSrc,
'            int dySrc,
'            LPBITMAPINFOHEADER lpbiDst,
'            LPVOID lpDst,
'            int xDst,
'            int yDst,
'            int dxDst,
'            int dyDst)
'{
'    ICDECOMPRESSEX ic;

'    ic.dwFlags = dwFlags;
'    ic.lpbiSrc = lpbiSrc;
'    ic.lpSrc = lpSrc;
'    ic.xSrc = xSrc;
'    ic.ySrc = ySrc;
'    ic.dxSrc = dxSrc;
'    ic.dySrc = dySrc;
'    ic.lpbiDst = lpbiDst;
'    ic.lpDst = lpDst;
'    ic.xDst = xDst;
'    ic.yDst = yDst;
'    ic.dxDst = dxDst;
'    ic.dyDst = dyDst;

'    // note that ICM swaps round the length and pointer
'    // length in lparam2, pointer in lparam1
'    return ICSendMessage(hic, ICM_DECOMPRESSEX_BEGIN, (DWORD_PTR)&ic, sizeof(ic));
'}

FUNCTION ICDecompressExBegin ( _
   BYVAL hic AS DWORD, _                         ' HIC hic
   BYVAL dwFlags AS DWORD, _                     ' DWORD dwFlags
   BYREF lpbiSrc AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiSrc
   BYVAL lpSrc AS DWORD, _                       ' LPVOID lpSrc
   BYVAL xSrc AS LONG, _                         ' int xSrc
   BYVAL ySrc AS LONG, _                         ' int ySrc
   BYVAL dxSrc AS LONG, _                        ' int dxSrc
   BYVAL dySrc AS LONG, _                        ' int dySrc
   BYREF lpbiDst AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiDst
   BYVAL lpDst AS DWORD, _                       ' LPVOID lpDst
   BYVAL xDst AS LONG, _                         ' int xDst
   BYVAL yDst AS LONG, _                         ' int yDst
   BYVAL dxDst AS LONG, _                        ' int dxDst
   BYVAL dyDst AS LONG _                         ' int dyDst
   ) AS LONG                                     ' LRESULT

   LOCAL ic AS ICDECOMPRESSEX_STRUCT

   ic.dwFlags = dwFlags
   ic.lpbiSrc = VARPTR(lpbiSrc)
   ic.lpSrc = lpSrc
   ic.xSrc = xSrc
   ic.ySrc = ySrc
   ic.dxSrc = dxSrc
   ic.dySrc = dySrc
   ic.lpbiDst = VARPTR(lpbiDst)
   ic.lpDst = lpDst
   ic.xDst = xDst
   ic.yDst = yDst
   ic.dxDst = dxDst
   ic.dyDst = dyDst

   ' // note that ICM swaps round the length and pointer
   ' // length in lparam2, pointer in lparam1
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESSEX_BEGIN, VARPTR(ic), sizeof(ic))

END FUNCTION

'/*
' *  ICDecompressExQuery()
' *
' */
'static __inline LRESULT VFWAPI_INLINE
'ICDecompressExQuery(
'            HIC hic,
'            DWORD dwFlags,
'            LPBITMAPINFOHEADER lpbiSrc,
'            LPVOID lpSrc,
'            int xSrc,
'            int ySrc,
'            int dxSrc,
'            int dySrc,
'            LPBITMAPINFOHEADER lpbiDst,
'            LPVOID lpDst,
'            int xDst,
'            int yDst,
'            int dxDst,
'            int dyDst)
'{
'    ICDECOMPRESSEX ic;

'    ic.dwFlags = dwFlags;
'    ic.lpbiSrc = lpbiSrc;
'    ic.lpSrc = lpSrc;
'    ic.xSrc = xSrc;
'    ic.ySrc = ySrc;
'    ic.dxSrc = dxSrc;
'    ic.dySrc = dySrc;
'    ic.lpbiDst = lpbiDst;
'    ic.lpDst = lpDst;
'    ic.xDst = xDst;
'    ic.yDst = yDst;
'    ic.dxDst = dxDst;
'    ic.dyDst = dyDst;

'    // note that ICM swaps round the length and pointer
'    // length in lparam2, pointer in lparam1
'    return ICSendMessage(hic, ICM_DECOMPRESSEX_QUERY, (DWORD_PTR)&ic, sizeof(ic));
'}

FUNCTION ICDecompressExQuery ( _
   BYVAL hic AS DWORD, _                         ' HIC hic
   BYVAL dwFlags AS DWORD, _                     ' DWORD dwFlags
   BYREF lpbiSrc AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiSrc
   BYVAL lpSrc AS DWORD, _                       ' LPVOID lpSrc
   BYVAL xSrc AS LONG, _                         ' int xSrc
   BYVAL ySrc AS LONG, _                         ' int ySrc
   BYVAL dxSrc AS LONG, _                        ' int dxSrc
   BYVAL dySrc AS LONG, _                        ' int dySrc
   BYREF lpbiDst AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiDst
   BYVAL lpDst AS DWORD, _                       ' LPVOID lpDst
   BYVAL xDst AS LONG, _                         ' int xDst
   BYVAL yDst AS LONG, _                         ' int yDst
   BYVAL dxDst AS LONG, _                        ' int dxDst
   BYVAL dyDst AS LONG _                         ' int dyDst
   ) AS LONG                                     ' LRESULT

   LOCAL ic AS ICDECOMPRESSEX_STRUCT

   ic.dwFlags = dwFlags
   ic.lpbiSrc = VARPTR(lpbiSrc)
   ic.lpSrc = lpSrc
   ic.xSrc = xSrc
   ic.ySrc = ySrc
   ic.dxSrc = dxSrc
   ic.dySrc = dySrc
   ic.lpbiDst = VARPTR(lpbiDst)
   ic.lpDst = lpDst
   ic.xDst = xDst
   ic.yDst = yDst
   ic.dxDst = dxDst
   ic.dyDst = dyDst

   ' // note that ICM swaps round the length and pointer
   ' // length in lparam2, pointer in lparam1
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESSEX_QUERY, VARPTR(ic), sizeof(ic))

END FUNCTION

'#define ICDecompressExEnd(hic) \
'    ICSendMessage(hic, ICM_DECOMPRESSEX_END, 0, 0)

FUNCTION ICDecompressExEnd (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DECOMPRESSEX_END, 0, 0)
END FUNCTION

'/************************************************************************

'    drawing functions

'************************************************************************/

'/*
' *  ICDrawBegin()
' *
' *  start decompressing data with format (lpbiInput) directly to the screen
' *
' *  return zero if the decompressor supports drawing.
' *
' */

%ICDRAW_QUERY      = &H00000001???  ' // test for support
%ICDRAW_FULLSCREEN = &H00000002???  ' // draw to full screen
%ICDRAW_HDC        = &H00000004???  ' // draw to a HDC/HWND

DECLARE FUNCTION ICDrawBegin IMPORT "MSVFW32.DLL" ALIAS "ICDrawBegin" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags  // flags
 , BYVAL hpal AS DWORD _                                ' __in HPALETTE hpal  // palette to draw with
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd  // window to draw to
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc  // HDC to draw to
 , BYVAL xDst AS LONG _                                 ' __in int xDst  // destination rectangle
 , BYVAL yDst AS LONG _                                 ' __in int yDst
 , BYVAL dxDst AS LONG _                                ' __in int dxDst
 , BYVAL dyDst AS LONG _                                ' __in int dyDst
 , BYREF lpbi AS BITMAPINFOHEADER _                     ' __in LPBITMAPINFOHEADER lpbi  // format of frame to draw
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc  // source rectangle
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL dxSrc AS LONG _                                ' __in int dxSrc
 , BYVAL dySrc AS LONG _                                ' __in int dySrc
 , BYVAL dwRate AS DWORD _                              ' __in DWORD dwRate  // frames/second = (dwRate/dwScale)
 , BYVAL dwScale AS DWORD _                             ' __in DWORD dwScale
 ) AS DWORD                                             ' DWORD

'/*
' *  ICDraw()
' *
' *  decompress data directly to the screen
' *
' */

%ICDRAW_HURRYUP     = &H80000000???  ' // don't draw just buffer (hurry up!)
%ICDRAW_UPDATE      = &H40000000???  ' // don't draw just update screen

DECLARE FUNCTION ICDraw IMPORT "MSVFW32.DLL" ALIAS "ICDraw" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags  // flags
 , BYVAL lpFormat AS DWORD _                            ' __in LPVOID lpFormat  // format of frame to decompress
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData  // frame data to decompress
 , BYVAL cb AS DWORD _                                  ' __in DWORD cbData  // size of data
 , BYVAL lTime AS LONG _                                ' __in LONG lTime  // time to draw this frame
 ) AS DWORD                                             ' DWORD

'// ICMessage is not supported on Win32, so provide a static inline function
'// to do the same job
'static __inline LRESULT VFWAPI_INLINE
'ICDrawSuggestFormat(
'            HIC hic,
'            LPBITMAPINFOHEADER lpbiIn,
'            LPBITMAPINFOHEADER lpbiOut,
'            int dxSrc,
'            int dySrc,
'            int dxDst,
'            int dyDst,
'            HIC hicDecomp)
'{
'    ICDRAWSUGGEST ic;

'    ic.lpbiIn = lpbiIn;
'    ic.lpbiSuggest = lpbiOut;
'    ic.dxSrc = dxSrc;
'    ic.dySrc = dySrc;
'    ic.dxDst = dxDst;
'    ic.dyDst = dyDst;
'    ic.hicDecompressor = hicDecomp;

'    // note that ICM swaps round the length and pointer
'    // length in lparam2, pointer in lparam1
'    return ICSendMessage(hic, ICM_DRAW_SUGGESTFORMAT, (DWORD_PTR)&ic, sizeof(ic));
'}

FUNCTION ICDrawSuggestFormat ( _
   BYVAL hic AS DWORD, _                         ' HIC hic
   BYREF lpbiIn AS BITMAPINFOHEADER, _           ' LPBITMAPINFOHEADER lpbiIn
   BYREF lpbiOut AS BITMAPINFOHEADER, _          ' LPBITMAPINFOHEADER lpbiOut
   BYVAL dxSrc AS LONG, _                        ' int dxSrc
   BYVAL dySrc AS LONG, _                        ' int dySrc
   BYVAL dxDst AS LONG, _                        ' int dxDst
   BYVAL dyDst AS LONG, _                        ' int dyDst
   BYVAL hicDecomp AS DWORD _                    ' HIC hicDecomp
   ) AS LONG                                     ' LRESULT

   LOCAL ic AS ICDRAWSUGGEST_STRUCT

   ic.lpbiIn = VARPTR(lpbiIn)
   ic.lpbiSuggest = VARPTR(lpbiOut)
   ic.dxSrc = dxSrc
   ic.dySrc = dySrc
   ic.dxDst = dxDst
   ic.dyDst = dyDst
   ic.hicDecompressor = hicDecomp

   ' // note that ICM swaps round the length and pointer
   ' // length in lparam2, pointer in lparam1
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_SUGGESTFORMAT, VARPTR(ic), sizeof(ic))

END FUNCTION

'/*
' *  ICDrawQuery()
' *
' *  determines if the compressor is willing to render the specified format.
' *
' */
'#define ICDrawQuery(hic, lpbiInput) \
'    ICSendMessage(hic, ICM_DRAW_QUERY, (DWORD_PTR)(LPVOID)(lpbiInput), 0L)

FUNCTION ICDrawQuery (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_QUERY, VARPTR(lpbiInput), 0)
END FUNCTION

'#define ICDrawChangePalette(hic, lpbiInput) \
'    ICSendMessage(hic, ICM_DRAW_CHANGEPALETTE, (DWORD_PTR)(LPVOID)(lpbiInput), 0L)

FUNCTION ICDrawChangePalette (BYVAL hic AS DWORD, BYREF lpbiInput AS BITMAPINFOHEADER) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_CHANGEPALETTE, VARPTR(lpbiInput), 0)
END FUNCTION

'#define ICGetBuffersWanted(hic, lpdwBuffers) \
'    ICSendMessage(hic, ICM_GETBUFFERSWANTED, (DWORD_PTR)(LPVOID)(lpdwBuffers), 0)

FUNCTION ICGetBuffersWanted (BYVAL hic AS DWORD, BYREF lpdwBuffers AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_GETBUFFERSWANTED, VARPTR(lpdwBuffers), 0)
END FUNCTION

'#define ICDrawEnd(hic) \
'    ICSendMessage(hic, ICM_DRAW_END, 0, 0)

FUNCTION ICDrawEnd (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_END, 0, 0)
END FUNCTION

'#define ICDrawStart(hic) \
'    ICSendMessage(hic, ICM_DRAW_START, 0, 0)

FUNCTION ICDrawStart (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_START, 0, 0)
END FUNCTION

'#define ICDrawStartPlay(hic, lFrom, lTo) \
'    ICSendMessage(hic, ICM_DRAW_START_PLAY, (DWORD_PTR)(lFrom), (DWORD_PTR)(lTo))

FUNCTION ICDrawStartPlay (BYVAL hic AS DWORD, BYVAL lFrom AS LONG, BYVAL lTo AS LONG) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_START_PLAY, lFrom, lTo)
END FUNCTION

'#define ICDrawStop(hic) \
'    ICSendMessage(hic, ICM_DRAW_STOP, 0, 0)

FUNCTION ICDrawStop (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_STOP, 0, 0)
END FUNCTION

'#define ICDrawStopPlay(hic) \
'    ICSendMessage(hic, ICM_DRAW_STOP_PLAY, 0, 0)

FUNCTION ICDrawStopPlay (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_STOP_PLAY, 0, 0)
END FUNCTION

'#define ICDrawGetTime(hic, lplTime) \
'    ICSendMessage(hic, ICM_DRAW_GETTIME, (DWORD_PTR)(LPVOID)(lplTime), 0)

FUNCTION ICDrawGetTime (BYVAL hic AS DWORD, BYREF lplTime AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_GETTIME, VARPTR(lplTime), 0)
END FUNCTION

'#define ICDrawSetTime(hic, lTime) \
'    ICSendMessage(hic, ICM_DRAW_SETTIME, (DWORD_PTR)lTime, 0)

FUNCTION ICDrawSetTime (BYVAL hic AS DWORD, BYVAL lTime AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_SETTIME, lTime, 0)
END FUNCTION

'#define ICDrawRealize(hic, hdc, fBackground) \
'    ICSendMessage(hic, ICM_DRAW_REALIZE, (DWORD_PTR)(UINT_PTR)(HDC)(hdc), (DWORD_PTR)(BOOL)(fBackground))

FUNCTION ICDrawRealize (BYVAL hic AS DWORD, BYVAL hdc AS DWORD, BYVAL fBackground AS LONG) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_SETTIME, hdc, fBackground)
END FUNCTION

'#define ICDrawFlush(hic) \
'    ICSendMessage(hic, ICM_DRAW_FLUSH, 0, 0)

FUNCTION ICDrawFlush (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_FLUSH, 0, 0)
END FUNCTION

'#define ICDrawRenderBuffer(hic) \
'    ICSendMessage(hic, ICM_DRAW_RENDERBUFFER, 0, 0)

FUNCTION ICDrawRenderBuffer (BYVAL hic AS DWORD) AS LONG
   FUNCTION = ICSendMessage(hic, %ICM_DRAW_RENDERBUFFER, 0, 0)
END FUNCTION

'/************************************************************************

'    Status callback functions

'************************************************************************/

'/*
' *  ICSetStatusProc()
' *
' *  Set the status callback function
' *
' */


'// ICMessage is not supported on NT
'static __inline LRESULT VFWAPI_INLINE
'ICSetStatusProc(
'            HIC hic,
'            DWORD dwFlags,
'            LRESULT lParam,
'            LONG (CALLBACK *fpfnStatus)(LPARAM, UINT, LONG) )
'{
'    ICSETSTATUSPROC ic;

'    ic.dwFlags = dwFlags;
'    ic.lParam = lParam;
'    ic.Status = fpfnStatus;

'    // note that ICM swaps round the length and pointer
'    // length in lparam2, pointer in lparam1
'    return ICSendMessage(hic, ICM_SET_STATUS_PROC, (DWORD_PTR)&ic, sizeof(ic));
'}

FUNCTION ICSetStatusProc ( _
   BYVAL hic AS DWORD, _                         ' HIC hic
   BYVAL dwFLags AS DWORD, _                     ' DWORD dwFlags
   BYVAL lParam AS LONG, _                       ' LRESULT lParam
   BYVAL fpfnStatus AS DWORD _                   ' LONG (CALLBACK *fpfnStatus)(LPARAM, UINT, LONG) )
   ) AS LONG                                     ' LRESULT

   LOCAL ic AS ICSETSTATUSPROC_STRUCT

   ic.dwFlags = dwFlags
   ic.lParam = lParam
   ic.Status = fpfnStatus

   ' // note that ICM swaps round the length and pointer
   ' // length in lparam2, pointer in lparam1
   FUNCTION = ICSendMessage(hic, %ICM_SET_STATUS_PROC, VARPTR(ic), sizeof(ic))

END FUNCTION

'/************************************************************************

'helper routines for DrawDib and MCIAVI...

'************************************************************************/

DECLARE FUNCTION ICLocate IMPORT "MSVFW32.DLL" ALIAS "ICLocate" ( _
   BYVAl fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL fccHandler AS DWORD _                          ' __in DWORD fccHandler
 , BYREF lpbiIn AS BITMAPINFOHEADER _                   ' __in LPBITMAPINFOHEADER lpbiIn
 , BYREF lpbiOut AS BITMAPINFOHEADER _                  ' __in LPBITMAPINFOHEADER lpbiOut
 , BYVAL wFlags AS WORD _                               ' __in WORD wFlags
 ) AS DWORD                                             ' HIC

'#define ICDecompressOpen(fccType, fccHandler, lpbiIn, lpbiOut) \
'    ICLocate(fccType, fccHandler, lpbiIn, lpbiOut, ICMODE_DECOMPRESS)

FUNCTION ICDecompressOpen (BYVAL fccType AS DWORD, BYVAL fccHandler AS DWORD, BYREF lpbiIn AS BITMAPINFOHEADER, BYREF lpbiOut AS BITMAPINFOHEADER) AS DWORD
   FUNCTION = ICLocate(fccType, fccHandler, lpbiIn, lpbiOut, %ICMODE_DECOMPRESS)
END FUNCTION

'#define ICDrawOpen(fccType, fccHandler, lpbiIn) \
'    ICLocate(fccType, fccHandler, lpbiIn, NULL, ICMODE_DRAW)

FUNCTION ICDrawOpen (BYVAL fccType AS DWORD, BYVAL fccHandler AS DWORD, BYREF lpbiIn AS BITMAPINFOHEADER) AS DWORD
   FUNCTION = ICLocate(fccType, fccHandler, lpbiIn, BYVAL %NULL, %ICMODE_DRAW)
END FUNCTION

DECLARE FUNCTION ICGetDisplayFormat IMPORT "MSVFW32.DLL" ALIAS "ICGetDisplayFormat" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic
 , BYREF lpbiIn AS BITMAPINFOHEADER _                   ' __in LPBITMAPINFOHEADER lpbiIn
 , BYREF lpbiOut AS BITMAPINFOHEADER _                  ' __out LPBITMAPINFOHEADER lpbiOut
 , BYVAL BitDepth AS LONG _                             ' __in int BitDepth
 , BYVAL dx AS LONG _                                   ' __in int dx
 , BYVAL dy AS LONG _                                   ' __in int dy
 ) AS DWORD                                             ' HIC

'/************************************************************************
'Higher level functions
'************************************************************************/

DECLARE FUNCTION ICImageCompress IMPORT "MSVFW32.DLL" ALIAS "ICImageCompress" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic  // compressor to use
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags  // flags (none yet)
 , BYREF lpbiIn AS BITMAPINFOHEADER _                   ' __in LPBITMAPINFOHEADER lpbiIn  // format to compress from
 , BYVAL lpBits AS DWORD  _                             ' __in LPVOID lpBits  // data to compress
 , BYREF lpbiOut AS BITMAPINFOHEADER _                  ' __in LPBITMAPINFOHEADER lpbiOut  // compress to this (NULL ==> default)
 , BYVAL lQuality AS LONG  _                            ' __in LONG lQuality  // quality to use
 , BYREF plSize AS LONG _                               ' __in__out LONG FAR * plSize  // compress to this size (0=whatever)
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION ICImageDecompress IMPORT "MSVFW32.DLL" ALIAS "ICImageDecompress" ( _
   BYVAL hic AS DWORD _                                 ' __in HIC hic  // compressor to use
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags  // flags (none yet)
 , BYREF lpbiIn AS BITMAPINFOHEADER _                   ' __in LPBITMAPINFOHEADER lpbiIn  // format to compress from
 , BYVAL lpBits AS DWORD  _                             ' __in LPVOID lpBits  // data to compress
 , BYREF lpbiOut AS BITMAPINFOHEADER _                  ' __in LPBITMAPINFOHEADER lpbiOut  // compress to this (NULL ==> default)
 ) AS DWORD                                             ' HANDLE

'//
'// Structure used by ICSeqCompressFrame and ICCompressorChoose routines
'// Make sure this matches the autodoc in icm.c!
'//

' // Size = 64 bytes
TYPE COMPVARS DWORD
   cbSize     AS LONG             ' LONG   // set to sizeof(COMPVARS) before
                                  '        // calling ICCompressorChoose
   dwFlags    AS DWORD            ' DWORD  // see below...
   hic        AS DWORD            ' HIC    // HIC of chosen compressor
   fccType    AS DWORD            ' DWORD  // basically ICTYPE_VIDEO
   fccHandler AS DWORD            ' DWORD  // handler of chosen compressor or
                                  '        // "" or "DIB "
   lpbiIn     AS BITMAPINFO PTR   ' LPBITMAPINFO // input format
   lpbiOut    AS BITMAPINFO PTR   ' LPBITMAPINFO // output format - will compress to this
   lpBitsOut  AS DWORD            ' LPVOID
   lpBitsPrev AS DWORD            ' LPVOID
   lFrame     AS LONG             ' LONG
   lKey       AS LONG             ' LONG   // key frames how often?
   lDataRate  AS LONG             ' LONG   // desired data rate KB/Sec
   lQ         AS LONG             ' LONG   // desired quality
   lKeyCount  AS LONG             ' LONG
   lpState    AS DWORD            ' LPVOID // state of compressor
   cbState    AS LONG             ' LONG   // size of the state
END TYPE

'// FLAGS for dwFlags element of COMPVARS structure:
'// set this flag if you initialize COMPVARS before calling ICCompressorChoose
%ICMF_COMPVARS_VALID = &H00000001???  ' // COMPVARS contains valid data

'//
'//  allows user to choose compressor, quality etc...
'//

DECLARE FUNCTION ICCompressorChoose IMPORT "MSVFW32.DLL" ALIAS "ICCompressorChoose" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd        // parent window for dialog
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags     // flags
 , BYVAL pvIn AS DWORD _                                ' __in LPVOID pvIn      // input format (optional)
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData    // input data (optional)
 , BYREF pc AS COMPVARS _                               ' __in__out PCOMPVARS pc // data about the compressor/dlg
 , BYREF lpszTitle AS ASCIIZ _                          ' __in LPSTR lpszTitle  // dialog title (optional)
 ) AS LONG                                              ' BOOL

'// defines for uiFlags
%ICMF_CHOOSE_KEYFRAME       = &H0001???  ' // show KeyFrame Every box
%ICMF_CHOOSE_DATARATE       = &H0002???  ' // show DataRate box
%ICMF_CHOOSE_PREVIEW        = &H0004???  ' // allow expanded preview dialog
%ICMF_CHOOSE_ALLCOMPRESSORS = &H0008???  ' // don't only show those that
                                         ' // can handle the input format
                                         ' // or input data

DECLARE FUNCTION ICSeqCompressFrameStart IMPORT "MSVFW32.DLL" ALIAS "ICSeqCompressFrameStart" ( _
   BYREF pc AS COMPVARS _                               ' __in PCOMPVARS pc
 , BYREF lpbiIn AS BITMAPINFO _                         ' __in LPBITMAPINFO lpbiIn
 ) AS LONG                                              ' BOOL

DECLARE SUB ICSeqCompressFrameEnd IMPORT "MSVFW32.DLL" ALIAS "ICSeqCompressFrameEnd" ( _
   BYREF pc AS COMPVARS _                               ' __in PCOMPVARS pc
 )                                                      ' void

DECLARE SUB ICSeqCompressFrame IMPORT "MSVFW32.DLL" ALIAS "ICSeqCompressFrame" ( _
   BYREF pc AS COMPVARS _                               ' __in PCOMPVARS pc  // set by ICCompressorChoose
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags  // flags
 , BYVAL lpBits AS DWORD _                              ' __in LPVOID  lpBits // input DIB bits
 , BYREF pfKey AS LONG _                                ' __out BOOL FAR *pfKey  // did it end up being a key frame?
 , BYREF plSize AS LONG _                               ' __in__out LONG FAR *plSize  // size to compress to/of returned image
 )                                                      ' void

DECLARE SUB ICCompressorFree IMPORT "MSVFW32.DLL" ALIAS "ICCompressorFree" ( _
   BYREF pc AS COMPVARS _                               ' __in PCOMPVARS pc
 )                                                      ' void

#ENDIF  ' /* NOCOMPMAN */  ---------------------------------------------------------------

'/**************************************************************************
' *
' *  DRAWDIB - Routines for drawing to the display.
' *
' *************************************************************************/

#IF NOT %DEF(%NODRAWDIB) ' ---------------------------------------------------------------

'typedef HANDLE HDRAWDIB; /* hdd */

'/*********************************************************************

'  DrawDib Flags

'**********************************************************************/
%DDF_0001            = &H0001???          ' /* ;Internal *' /
%DDF_UPDATE          = &H0002???          ' /* re-draw the last DIB *' /
%DDF_SAME_HDC        = &H0004???          ' /* HDC same as last call (all setup) *' /
%DDF_SAME_DRAW       = &H0008???          ' /* draw params are the same *' /
%DDF_DONTDRAW        = &H0010???          ' /* dont draw frame, just decompress *' /
%DDF_ANIMATE         = &H0020???          ' /* allow palette animation *' /
%DDF_BUFFER          = &H0040???          ' /* always buffer image *' /
%DDF_JUSTDRAWIT      = &H0080???          ' /* just draw it with GDI *' /
%DDF_FULLSCREEN      = &H0100???          ' /* use DisplayDib *' /
%DDF_BACKGROUNDPAL   = &H0200???          ' /* Realize palette in background *' /
%DDF_NOTKEYFRAME     = &H0400???          ' /* this is a partial frame update, hint *' /
%DDF_HURRYUP         = &H0800???          ' /* hurry up please! *' /
%DDF_HALFTONE        = &H1000???          ' /* always halftone *' /
%DDF_2000            = &H2000???          ' /* ;Internal *' /

%DDF_PREROLL         = %DDF_DONTDRAW   ' /* Builing up a non-keyframe *' /
%DDF_SAME_DIB        = %DDF_SAME_DRAW
%DDF_SAME_SIZE       = %DDF_SAME_DRAW

'/*********************************************************************

'    DrawDib functions

'*********************************************************************/
'/*                     // ;Internal
'**  DrawDibInit()               // ;Internal
'**                     // ;Internal
'*/                     // ;Internal
'extern BOOL VFWAPI DrawDibInit(void);         // ;Internal
'                     // ;Internal

'/*
'**  DrawDibOpen()
'**
'*/

DECLARE FUNCTION DrawDibOpen IMPORT "MSVFW32.DLL" ALIAS "DrawDibOpen"( _
 ) AS DWORD                                             ' HDRAWDIB

'/*
'**  DrawDibClose()
'**
'*/

DECLARE FUNCTION DrawDibClose IMPORT "MSVFW32.DLL" ALIAS "DrawDibClose"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 ) AS LONG                                              ' BOOL

'/*
'** DrawDibGetBuffer()
'**
'*/

DECLARE FUNCTION DrawDibGetBuffer IMPORT "MSVFW32.DLL" ALIAS "DrawDibGetBuffer"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYREF lpbi AS BITMAPINFOHEADER _                     ' __in LPBITMAPINFOHEADER lpbi
 , BYVAL dwSize AS DWORD _                              ' __in DWORD dwSize
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPVOID

'/*                     // ;Internal
'**  DrawDibError()               // ;Internal
'*/                     // ;Internal
'extern UINT VFWAPI DrawDibError(HDRAWDIB hdd);      // ;Internal
'                     // ;Internal

'/*
'**  DrawDibGetPalette()
'**
'**  get the palette used for drawing DIBs
'**
'*/

DECLARE FUNCTION DrawDibGetPalette IMPORT "MSVFW32.DLL" ALIAS "DrawDibGetPalette"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 ) AS DWORD                                             ' HPALETTE

'/*
'**  DrawDibSetPalette()
'**
'**  get the palette used for drawing DIBs
'**
'*/

DECLARE FUNCTION DrawDibSetPalette IMPORT "MSVFW32.DLL" ALIAS "DrawDibSetPalette"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL hpal AS DWORD _                                ' __in HPALETTE hpal
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibChangePalette()
'*/

DECLARE FUNCTION DrawDibChangePalette IMPORT "MSVFW32.DLL" ALIAS "DrawDibChangePalette"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL iStart AS LONG _                               ' __in int iStart
 , BYVAL iLen AS LONG _                                 ' __in int iLen
 , BYREF lppe AS PALETTEENTRY _                         ' __in PALETTEENTRY lppe
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibRealize()
'**
'**  realize the palette in a HDD
'**
'*/

DECLARE FUNCTION DrawDibRealize IMPORT "MSVFW32.DLL" ALIAS "DrawDibRealize"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL fBackground AS LONG  _                         ' __in BOOL fBackground
 ) AS DWORD                                             ' UINT

'/*
'**  DrawDibStart()
'**
'**  start of streaming playback
'**
'*/

DECLARE FUNCTION DrawDibStart IMPORT "MSVFW32.DLL" ALIAS "DrawDibStart"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL rate AS DWORD  _                               ' __in DWORD rate
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibStop()
'**
'**  start of streaming playback
'**
'*/

DECLARE FUNCTION DrawDibStop IMPORT "MSVFW32.DLL" ALIAS "DrawDibStop"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibBegin()
'**
'**  prepare to draw
'**
'*/

DECLARE FUNCTION DrawDibBegin IMPORT "MSVFW32.DLL" ALIAS "DrawDibBegin"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL dxDst AS LONG _                                ' __in int dxDst
 , BYVAL dyDst AS LONG _                                ' __in int dyDst
 , BYREF lpbi AS BITMAPINFOHEADER _                     ' __in BITMAPINFOHEADER lpbi
 , BYVAL dxSrc AS LONG _                                ' __in int dxSrc
 , BYVAL dySrc AS LONG _                                ' __in int dySrc
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibDraw()
'**
'**  actualy draw a DIB to the screen.
'**
'*/

DECLARE FUNCTION DrawDibDraw IMPORT "MSVFW32.DLL" ALIAS "DrawDibDraw"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL xDst AS LONG _                                 ' __in int xDst
 , BYVAL yDst AS LONG _                                 ' __in int yDst
 , BYVAL dxDst AS LONG _                                ' __in int dxDst
 , BYVAL dyDst AS LONG _                                ' __in int dyDst
 , BYREF lpbi AS BITMAPINFOHEADER _                     ' __in BITMAPINFOHEADER lpbi
 , BYVAL lpBits AS DWORD _                              ' __in LPVOID lpBits
 , BYVAL xSrc AS LONG _                                 ' __in int xSrc
 , BYVAL ySrc AS LONG _                                 ' __in int ySrc
 , BYVAL dxSrc AS LONG _                                ' __in int dxSrc
 , BYVAL dySrc AS LONG _                                ' __in int dySrc
 , BYVAL wFlags AS DWORD _                              ' __in UINT wFlags
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibUpdate()
'**
'**  redraw the last image (may only be valid with DDF_BUFFER)
'*/
'#define DrawDibUpdate(hdd, hdc, x, y) \
'        DrawDibDraw(hdd, hdc, x, y, 0, 0, NULL, NULL, 0, 0, 0, 0, DDF_UPDATE)

FUNCTION DrawDibUpdate ( _
   BYVAL hdd AS DWORD, _                         ' HDRAWDIB
   BYVAL hdc AS DWORD, _                         ' HDC
   BYVAL x AS LONG, _                            ' int
   BYVAL y AS LONG _                             ' int
   ) AS LONG                                     ' BOOL

   FUNCTION = DrawDibDraw(hdd, hdc, x, y, 0, 0, BYVAL %NULL, BYVAL %NULL, 0, 0, 0, 0, %DDF_UPDATE)

END FUNCTION

'/*
'**  DrawDibEnd()
'*/

DECLARE FUNCTION DrawDibEnd IMPORT "MSVFW32.DLL" ALIAS "DrawDibEnd"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 ) AS LONG                                              ' BOOL

'/*
'**  DrawDibTime()  [for debugging purposes only]
'*/

' // Size = 28 bytes
TYPE DRAWDIBTIME_STRUCT DWORD
   timeCount      AS LONG
   timeDraw       AS LONG
   timeDecompress AS LONG
   timeDither     AS LONG
   timeStretch    AS LONG
   timeBlt        AS LONG
   timeSetDIBits  AS LONG
END TYPE

MACRO tagDRAWDIBTIME = DRAWDIBTIME_STRUCT

DECLARE FUNCTION DrawDibTime IMPORT "MSVFW32.DLL" ALIAS "DrawDibTime"( _
   BYVAL hdd AS DWORD _                                 ' __in HDRAWDIB hdd
 , BYREF lpddtime AS DRAWDIBTIME_STRUCT _               ' __in LPDRAWDIBTIME lpddtime
 ) AS LONG                                              ' BOOL

'/* display profiling */
%PD_CAN_DRAW_DIB      = &H0001     ' /* if you can draw at all */
%PD_CAN_STRETCHDIB    = &H0002     ' /* basicly RC_STRETCHDIB */
%PD_STRETCHDIB_1_1_OK = &H0004     ' /* is it fast? */
%PD_STRETCHDIB_1_2_OK = &H0008     ' /* ... */
%PD_STRETCHDIB_1_N_OK = &H0010     ' /* ... */

DECLARE FUNCTION DrawDibProfileDisplay IMPORT "MSVFW32.DLL" ALIAS "DrawDibProfileDisplay"( _
   BYREF lpbi AS BITMAPINFOHEADER _                     ' __in LPBITMAPINFOHEADER lpbi
 ) AS LONG                                              ' BOOL

#IF %DEF(%DRAWDIB_INCLUDE_STRETCHDIB)
DECLARE FUNCTION StretchDIB IMPORT "MSVFW32.DLL" ALIAS "StretchDIB" ( _
   BYREF biDst AS BITMAPINFOHEADER _                    ' __in BITMAPINFOHEADER biDst
 , BYVAL lpDst AS DWORD _                               ' __in LPVOID lpDst
 , BYVAL DstX AS LONG _                                 ' __in int DstX
 , BYVAL DstY AS LONG _                                 ' __in int DstY
 , BYVAL DstXE AS LONG _                                ' __in int DstXE
 , BYVAL DstYE AS LONG _                                ' __in int DstYE
 , BYREF biSrc AS BITMAPINFOHEADER _                    ' __in BITMAPINFOHEADER biSrc
 , BYVAL lpSrc AS DWORD _                               ' __in LPVOID lpSrc
 , BYVAL SrcX AS LONG _                                 ' __in int SrcX
 , BYVAL SrcY AS LONG _                                 ' __in int SrcY
 , BYVAL SrcXE AS LONG _                                ' __in int SrcXE
 , BYVAL SrcYE AS LONG _                                ' __in int SrcYE
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF   ' /* NODRAWDIB */  --------------------------------------------------------------

'/****************************************************************************
' *
' *  AVIFMT - AVI file format definitions
' *
' ****************************************************************************/

#IF NOT %DEF(%NOAVIFMT) ' ----------------------------------------------------------------

'#ifndef NOAVIFMT
'    #ifndef _INC_MMSYSTEM
'        typedef DWORD FOURCC;
'    #endif
'#ifdef _MSC_VER
'#pragma warning(disable:4200)
'#endif

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
'#define formtypeAVI             mmioFOURCC('A', 'V', 'I', ' ')
'#define listtypeAVIHEADER       mmioFOURCC('h', 'd', 'r', 'l')
'#define ckidAVIMAINHDR          mmioFOURCC('a', 'v', 'i', 'h')
'#define listtypeSTREAMHEADER    mmioFOURCC('s', 't', 'r', 'l')
'#define ckidSTREAMHEADER        mmioFOURCC('s', 't', 'r', 'h')
'#define ckidSTREAMFORMAT        mmioFOURCC('s', 't', 'r', 'f')
'#define ckidSTREAMHANDLERDATA   mmioFOURCC('s', 't', 'r', 'd')
'#define ckidSTREAMNAME          mmioFOURCC('s', 't', 'r', 'n')

'#define listtypeAVIMOVIE        mmioFOURCC('m', 'o', 'v', 'i')
'#define listtypeAVIRECORD       mmioFOURCC('r', 'e', 'c', ' ')

'#define ckidAVINEWINDEX         mmioFOURCC('i', 'd', 'x', '1')

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
'#define streamtypeVIDEO         mmioFOURCC('v', 'i', 'd', 's')
'#define streamtypeAUDIO         mmioFOURCC('a', 'u', 'd', 's')
'#define streamtypeMIDI          mmioFOURCC('m', 'i', 'd', 's')
'#define streamtypeTEXT          mmioFOURCC('t', 'x', 't', 's')

%streamtypeVIDEO = &H73646976???   ' mmioFOURCC('v', 'i', 'd', 's')
%streamtypeAUDIO = &H73647561???   ' mmioFOURCC('a', 'u', 'd', 's')
%streamtypeMIDI  = &H7364696D???   ' mmioFOURCC('m', 'i', 'd', 's')
%streamtypeTEXT  = &H73747874???   ' mmioFOURCC('t', 'x', 't', 's')

'/* Basic chunk types */
'#define cktypeDIBbits           aviTWOCC('d', 'b')
'#define cktypeDIBcompressed     aviTWOCC('d', 'c')
'#define cktypePALchange         aviTWOCC('p', 'c')
'#define cktypeWAVEbytes         aviTWOCC('w', 'b')

%cktypeDIBbits               = &H6264??       ' // aviTWOCC('d', 'b')
%cktypeDIBcompressed         = &H6364??       ' // aviTWOCC('d', 'c')
%cktypePALchange             = &H6370??       ' // aviTWOCC('p', 'c')
%cktypeWAVEbytes             = &H6277??       ' // aviTWOCC('w', 'b')

'/* Chunk id to use for extra chunks for padding. */
'#define ckidAVIPADDING          mmioFOURCC('J', 'U', 'N', 'K')
%ckidAVIPADDING              = &H4B4E554A???   ' // mmioFOURCC('J', 'U', 'N', 'K')


'/*
'** Useful macros
'**
'** Warning: These are nasty macro, and MS C 6.0 compiles some of them
'** incorrectly if optimizations are on.  Ack.
'*/

''/* Macro to get stream number out of a FOURCC ckid */
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
   dwReserved(3)         AS DWORD   ' DWORD[4]
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
%AVIIF_FIRSTPART     = &H00000020??? ' // this frame is the start of a partial frame.
%AVIIF_LASTPART      = &H00000040??? ' // this frame is the end of a partial frame.
%AVIIF_MIDPART       = %AVIIF_LASTPART OR %AVIIF_FIRSTPART

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
TYPE AVIPALCHANGE BYTE
   bFirstEntry AS BYTE           ' /* first entry to change */
   bNumEntries AS BYTE           ' /* # entries to change (0 if 256) */
   wFlags      AS WORD           ' /* Mostly to preserve alignment... */
   'peNew()     AS PALETTEENTRY   ' /* New color specifications */
END TYPE

#ENDIF   ' /* NOAVIFMT */  ---------------------------------------------------------------

'/****************************************************************************
' *
' *  MMREG.H (standard include file for MM defines, like FOURCC and things)
' *
' ***************************************************************************/

'#ifndef RC_INVOKED
'#include "pshpack8.h"
'#endif
'#ifndef NOMMREG
'    #include <mmreg.h>
'#endif

#IF NOT %DEF(%NOMMREG) ' ----------------------------------------------------------------
    #INCLUDE ONCE "mmreg.inc"
#ENDIF

'/****************************************************************************
' *
' *  AVIFile - routines for reading/writing standard AVI files
' *
' ***************************************************************************/

#IF NOT %DEF(%NOAVIFILE) ' ---------------------------------------------------------------

'/*
' * Ansi - Unicode thunking.
' *
' * Unicode or Ansi-only apps can call the avifile APIs.
' * any Win32 app who wants to use
' * any of the AVI COM interfaces must be UNICODE - the AVISTREAMINFO and
' * AVIFILEINFO structures used in the Info methods of these interfaces are
' * the unicode variants, and no thunking to or from ansi takes place
' * except in the AVIFILE api entrypoints.
' *
' * For Ansi/Unicode thunking: for each entrypoint or structure that
' * uses chars or strings, two versions are declared in the Win32 version,
' * ApiNameW and ApiNameA. The default name ApiName is #defined to one or
' * other of these depending on whether UNICODE is defined (during
' * compilation of the app that is including this header). The source will
' * contain ApiName and ApiNameA (with ApiName being the Win16 implementation,
' * and also #defined to ApiNameW, and ApiNameA being the thunk entrypoint).
' *
' */

'#ifndef mmioFOURCC
'    #define mmioFOURCC( ch0, ch1, ch2, ch3 ) \
'   ( (DWORD)(BYTE)(ch0) | ( (DWORD)(BYTE)(ch1) << 8 ) |   \
'   ( (DWORD)(BYTE)(ch2) << 16 ) | ( (DWORD)(BYTE)(ch3) << 24 ) )
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

'#ifndef streamtypeVIDEO
'#define streamtypeVIDEO      mmioFOURCC('v', 'i', 'd', 's')
'#define streamtypeAUDIO      mmioFOURCC('a', 'u', 'd', 's')
'#define streamtypeMIDI       mmioFOURCC('m', 'i', 'd', 's')
'#define streamtypeTEXT       mmioFOURCC('t', 'x', 't', 's')
'#endif

#IF NOT %DEF(%streamtypeVIDEO)
%streamtypeVIDEO = &H73646976???   ' mmioFOURCC('v', 'i', 'd', 's')
%streamtypeAUDIO = &H73647561???   ' mmioFOURCC('a', 'u', 'd', 's')
%streamtypeMIDI  = &H7364696D???   ' mmioFOURCC('m', 'i', 'd', 's')
%streamtypeTEXT  = &H73747874???   ' mmioFOURCC('t', 'x', 't', 's')
#ENDIF

#IF NOT %DEF(%AVIIF_KEYFRAME)
%AVIIF_KEYFRAME  = &H00000010& ' // this frame is a key frame.
#ENDIF

'// For GetFrame::SetFormat - use the best format for the display
%AVIGETFRAMEF_BESTDISPLAYFMT = 1

'//
'// Structures used by AVIStreamInfo & AVIFileInfo.
'//
'// These are related to, but not identical to, the header chunks
'// in an AVI file.
'//

'/*
' *
' * --- AVISTREAMINFO ------------------------------------------------
' *
' * for Unicode/Ansi thunking we need to declare three versions of this!
' */

' // Size = 204 bytes
TYPE AVISTREAMINFOW_STRUCT DWORD FILL
   fccType               AS DWORD             ' DWORD
   fccHandler            AS DWORD             ' DWORD
   dwFlags               AS DWORD             ' DWORD /* Contains AVITF_* flags */
   dwCaps                AS DWORD             ' DWORD
   wPriority             AS WORD              ' WORD
   wLanguage             AS WORD              ' WORD
   dwScale               AS DWORD             ' DWORD
   dwRate                AS DWORD             ' DWORD /* dwRate / dwScale == samples/second */
   dwStart               AS DWORD             ' DWORD
   dwLength              AS DWORD             ' DWORD/* In units above... */
   dwInitialFrames       AS DWORD             ' DWORD
   dwSuggestedBufferSize AS DWORD             ' DWORD
   dwQuality             AS DWORD             ' DWORD
   dwSampleSize          AS DWORD             ' DWORD
   rcFrame               AS RECT              ' RECT
   dwEditCount           AS DWORD             ' DWORD
   dwFormatChangeCount   AS DWORD             ' DWORD
   szName                AS WSTRINGZ * 64     ' WCHAR
END TYPE

' // Size = 140 bytes
TYPE AVISTREAMINFOA_STRUCT DWORD FILL
   fccType               AS DWORD         ' DWORD
   fccHandler            AS DWORD         ' DWORD
   dwFlags               AS DWORD         ' DWORD /* Contains AVITF_* flags */
   dwCaps                AS DWORD         ' DWORD
   wPriority             AS WORD          ' WORD
   wLanguage             AS WORD          ' WORD
   dwScale               AS DWORD         ' DWORD
   dwRate                AS DWORD         ' DWORD /* dwRate / dwScale == samples/second */
   dwStart               AS DWORD         ' DWORD
   dwLength              AS DWORD         ' DWORD/* In units above... */
   dwInitialFrames       AS DWORD         ' DWORD
   dwSuggestedBufferSize AS DWORD         ' DWORD
   dwQuality             AS DWORD         ' DWORD
   dwSampleSize          AS DWORD         ' DWORD
   rcFrame               AS RECT          ' RECT
   dwEditCount           AS DWORD         ' DWORD
   dwFormatChangeCount   AS DWORD         ' DWORD
   szName                AS ASCIIZ * 64   ' char
END TYPE

MACRO tagAVISTREAMINFOW = AVISTREAMINFOW_STRUCT
MACRO tagAVISTREAMINFOA = AVISTREAMINFOA_STRUCT
MACRO AVISTREAMINFO_STRUCT = AVISTREAMINFOA_STRUCT
MACRO tagAVISTREAMINFO = AVISTREAMINFOA_STRUCT

%AVISTREAMINFO_DISABLED      = &H00000001???
%AVISTREAMINFO_FORMATCHANGES = &H00010000???

'/*
' * --- AVIFILEINFO ----------------------------------------------------
' *
' */

' // Size = 108 bytes
TYPE AVIFILEINFOA_STRUCT DWORD
   dwMaxBytesPerSec      AS DWORD         ' DWORD // max. transfer rate
   dwFlags               AS DWORD         ' DWORD // the ever-present flags
   dwCaps                AS DWORD         ' DWORD
   dwStreams             AS DWORD         ' DWORD
   dwSuggestedBufferSize AS DWORD         ' DWORD
   dwWidth               AS DWORD         ' DWORD
   dwHeight              AS DWORD         ' DWORD
   dwScale               AS DWORD         ' DWORD
   dwRate                AS DWORD         ' DWORD /* dwRate / dwScale == samples/second */
   dwLength              AS DWORD         ' DWORD
   dwEditCount           AS DWORD         ' DWORD
   szFileType            AS ASCIIZ * 64   ' char // descriptive string for file type?
END TYPE

' // Size = 172 bytes
TYPE AVIFILEINFOW_STRUCT DWORD
   dwMaxBytesPerSec      AS DWORD             ' DWORD // max. transfer rate
   dwFlags               AS DWORD             ' DWORD // the ever-present flags
   dwCaps                AS DWORD             ' DWORD
   dwStreams             AS DWORD             ' DWORD
   dwSuggestedBufferSize AS DWORD             ' DWORD
   dwWidth               AS DWORD             ' DWORD
   dwHeight              AS DWORD             ' DWORD
   dwScale               AS DWORD             ' DWORD
   dwRate                AS DWORD             ' DWORD /* dwRate / dwScale == samples/second */
   dwLength              AS DWORD             ' DWORD
   dwEditCount           AS DWORD             ' DWORD
   szFileType            AS WSTRINGZ * 64     ' WCHAR // descriptive string for file type?
END TYPE

MACRO tagAVIFILEINFOA = AVIFILEINFOA_STRUCT
MACRO tagAVIFILEINFOW = AVIFILEINFOW_STRUCT
MACRO AVIFILEINFO_STRUCT = AVIFILEINFOA_STRUCT
MACRO tagAVIFILEINFO = AVIFILEINFOA_STRUCT

'// Flags for dwFlags
%AVIFILEINFO_HASINDEX       = &H00000010???
%AVIFILEINFO_MUSTUSEINDEX   = &H00000020???
%AVIFILEINFO_ISINTERLEAVED  = &H00000100???
%AVIFILEINFO_WASCAPTUREFILE = &H00010000???
%AVIFILEINFO_COPYRIGHTED    = &H00020000???

'// Flags for dwCaps
%AVIFILECAPS_CANREAD        = &H00000001???
%AVIFILECAPS_CANWRITE       = &H00000002???
%AVIFILECAPS_ALLKEYFRAMES   = &H00000010???
%AVIFILECAPS_NOCOMPRESSION  = &H00000020???

'typedef BOOL (FAR PASCAL * AVISAVECALLBACK)(int);
'FUNCTION AVISAVECALLBACK (BYVAL LONG) AS LONG

'/************************************************************************/
'/* Declaration for the AVICOMPRESSOPTIONS structure.  Make sure it    */
'/* matches the AutoDoc in avisave.c !!!                               */
'/************************************************************************/

' // Size = 44 bytes
TYPE AVICOMPRESSOPTIONS_STRUCT DWORD
   fccType           AS DWORD   ' DWORD /* stream type, for consistency */
   fccHandler        AS DWORD   ' DWORD /* compressor */
   dwKeyFrameEvery   AS DWORD   ' DWORD /* keyframe rate */
   dwQuality         AS DWORD   ' DWORD /* compress quality 0-10,000 */
   dwBytesPerSecond  AS DWORD   ' DWORD /* bytes per second */
   dwFlags           AS DWORD   ' DWORD /* flags... see below */
   lpFormat          AS DWORD   ' LPVOID /* save format */
   cbFormat          AS DWORD   ' DWORD
   lpParms           AS DWORD   ' LPVOID /* compressor options */
   cbParms           AS DWORD   ' DWORD
   dwInterleaveEvery AS DWORD   ' DWORD /* for non-video streams only */
END TYPE

MACRO tagAVICOMPRESSOPTIONS = AVICOMPRESSOPTIONS_STRUCT

'//
'// Defines for the dwFlags field of the AVICOMPRESSOPTIONS struct
'// Each of these flags determines if the appropriate field in the structure
'// (dwInterleaveEvery, dwBytesPerSecond, and dwKeyFrameEvery) is payed
'// attention to.  See the autodoc in avisave.c for details.
'//
%AVICOMPRESSF_INTERLEAVE = &H00000001???    ' // interleave
%AVICOMPRESSF_DATARATE   = &H00000002???    ' // use a data rate
%AVICOMPRESSF_KEYFRAMES  = &H00000004???    ' // use keyframes
%AVICOMPRESSF_VALID      = &H00000008???    ' // has valid data?

#INCLUDE ONCE "ole2.inc"

'/*   -   -   -   -   -   -   -   -   */

'/****** GUIDs *******************************************/

'#define DEFINE_AVIGUID(name, l, w1, w2) \
'    DEFINE_GUID(name, l, w1, w2, 0xC0,0,0,0,0,0,0,0x46)

$IID_IAVIFile             = GUID$("{00020020-0000-0000-C000-000000000046}")
$IID_IAVIStream           = GUID$("{00020021-0000-0000-C000-000000000046}")
$IID_IAVIStreaming        = GUID$("{00020022-0000-0000-C000-000000000046}")
$IID_IGetFrame            = GUID$("{00020023-0000-0000-C000-000000000046}")
$IID_IAVIEditStream       = GUID$("{00020024-0000-0000-C000-000000000046}")
$IID_IAVIPersistFile      = GUID$("{00020025-0000-0000-C000-000000000046}")
$CLSID_AVISimpleUnMarshal = GUID$("{00020009-0000-0000-C000-000000000046}")
$CLSID_AVIFile            = GUID$("{00020000-0000-0000-C000-000000000046}")


' ########################################################################################
' IAVIStream interface
' IID = 00020021-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAVIStream $IID_IAVIStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 12
     BYVAL lParam1 AS LONG _                            ' __in LPARAM lParam1
   , BYVAL lParam2 AS LONG _                            ' __in LPARAM lParam2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Info ( _                                      ' VTable offset = 16
     BYREF psi AS AVISTREAMINFOW_STRUCT _               ' __in AVISTREAMINFOW *psi
   , BYVAL lSize AS LONG _                              ' __in LONG lSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindSample ( _                                ' VTable offset = 20
     BYVAL lPos AS LONG _                               ' __in LONG lPos
   , BYVAL lFlags AS LONG _                             ' __in LONG lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadFormat ( _                                ' VTable offset = 24
     BYVAL lPos AS LONG _                               ' __in LONG lPos
   , BYVAL lpFormat AS DWORD _                          ' __in LPVOID lpFormat
   , BYREF lpcbFormat AS LONG _                         ' __out LONG *lpcbFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 28
     BYVAL lPos AS LONG _                               ' __in LONG lPos
   , BYVAL lpFormat AS DWORD _                          ' __in LPVOID lpFormat
   , BYVAL cbFormat AS LONG _                           ' __in LONG cbFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 32
     BYVAL lStart AS LONG _                             ' __in LONG lStart
   , BYVAL lSamples AS LONG _                           ' __in LONG lSamples
   , BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   , BYVAL cbBuffer AS LONG _                           ' __in LONG cbBuffer
   , BYREF plBytes AS LONG _                            ' __out LONG *plBytes
   , BYREF plSamples AS LONG _                          ' __out LONG *plSamples
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 36
     BYVAL lStart AS LONG _                             ' __in LONG lStart
   , BYVAL lSamples As LONG _                           ' __in LONG lSamples
   , BYVAL lpFormat AS DWORD _                          ' __in LPVOID lpFormat
   , BYVAL cbBuffer AS LONG _                           ' __in LONG cbBuffer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF plSampWritten AS LONG _                      ' __out LONG *plSampWritten
   , BYREF plBytesWritten AS LONG _                     ' __out LONG *plBytesWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 40
     BYVAL lStart AS LONG _                             ' __in LONG lStart
   , BYVAL lSamples AS LONG _                           ' __in LONG lSamples
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadData ( _                                  ' VTable offset = 44
     BYVAL fcc AS DWORD _                               ' __in DWORD fcc
   , BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   , BYREF lpcbBuffer AS LONG _                         ' __out LONG *lpcbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteData ( _                                 ' VTable offset = 48
     BYVAL fcc AS DWORD _                               ' __in DWORD fcc
   , BYVAL lpBuffer AS DWORD _                          ' __in LPVOID lpBuffer
   , BYVAL cbBuffer AS LONG _                           ' __in LONG cbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInfo ( _                                   ' VTable offset = 52
     BYREF lpInfo AS AVISTREAMINFOW_STRUCT _            ' __in AVISTREAMINFOW *lpInfo
   , BYVAL cbInfo AS LONG _                             ' __in LONG cbInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IAVIStreaming interface
' IID = 00020022-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAVIStreaming $IID_IAVIStreaming

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 12
     BYVAL lStart AS LONG _                             ' __in LONG lStart
   , BYVAL lEnd AS LONG _                               ' __in LONG lEnd
   , BYVAL lRate AS LONG _                              ' __in LONG lRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IAVIEditStream interface
' IID = 00020024-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAVIEditStream $IID_IAVIEditStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Cut ( _                                       ' VTable offset = 12
     BYREF LONG _                                       ' __out LONG *plStart
   , BYREF LONG _                                       ' __out LONG *plLength
   , BYREF IAVIStream _                                 ' __out PAVISTREAM *ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copy ( _                                      ' VTable offset = 16
     BYREF LONG _                                       ' __out LONG *plStart
   , BYREF LONG _                                       ' __out LONG *plLength
   , BYREF IAVIStream _                                 ' __out PAVISTREAM *ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Paste ( _                                     ' VTable offset = 20
     BYREF LONG _                                       ' __out LONG *plPos
   , BYREF LONG _                                       ' __out LONG *plLength
   , BYVAL IAVIStream _                                 ' __in PAVISTREAM pstream
   , BYVAL LONG _                                       ' __in LONG lStart
   , BYVAL LONG _                                       ' __in LONG lLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF IAVIStream _                                 ' __out PAVISTREAM *ppResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInfo ( _                                   ' VTable offset = 28
     BYREF AVISTREAMINFOW_STRUCT _                      ' __in AVISTREAMINFOW *lpInfo
   , BYVAL LONG _                                       ' __in LONG cbInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IAVIPersistFile interface
' IID = 00020025-0000-0000-C000-000000000046
' Inherited interface = IPersistFile
' ########################################################################################

INTERFACE IAVIPersistFile $IID_IAVIPersistFile

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersistFile Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirty ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   , BYVAL fRemember AS LONG _                          ' __in BOOL fRemember
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveCompleted ( _                             ' VTable offset = 28
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCOLESTR pszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurFile ( _                                ' VTable offset = 32
     BYREF ppszFileName AS DWORD _                      ' __out LPOLESTR *ppszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IAVIFile interface
' IID = 00020020-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAVIFile $IID_IAVIFile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Info ( _                                      ' VTable offset = 12
     BYREF pfi AS AVISTREAMINFOW_STRUCT _               ' __in AVIFILEINFOW *pfi
   , BYVAL lSize AS LONG _                              ' __in LONG lSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStream ( _                                 ' VTable offset = 16
     BYREF ppStream AS IAVIStream _                     ' __out PAVISTREAM *ppStream
   , BYVAL fccType AS DWORD _                           ' __in DWORD fccType
   , BYVAL lParam AS LONG _                             ' __in LONG lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateStream ( _                              ' VTable offset = 20
     BYREF ppStream AS IAVIStream _                     ' __out PAVISTREAM *ppStream
   , BYREF psi AS AVISTREAMINFOW_STRUCT _               ' __in AVISTREAMINFO *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteData ( _                                 ' VTable offset = 24
     BYVAL ckid AS DWORD _                              ' __in DWORD ckid
   , BYVAL lpData AS DWORD _                            ' __in LPVOID lpData
   , BYVAL cbData AS DWORD _                            ' __in LONG cbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadData ( _                                  ' VTable offset = 28
     BYVAL ckid AS DWORD _                              ' __in DWORD ckid
   , BYVAL lpData AS DWORD _                            ' __in LPVOID lpData
   , BYREF lpcbData AS DWORD _                          ' __out LONG *lpcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndRecord ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteStream ( _                              ' VTable offset = 36
     BYVAL fccType AS DWORD _                           ' __in DWORD fccType
   , BYVAL lParam AS LONG _                             ' __in LONG lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IGetFrame interface
' IID = 00020023-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IGetFrame $IID_IGetFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFrame ( _                                  ' VTable offset = 12
     BYVAL lPos AS LONG _                               ' __in LONG lPos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 16
     BYVAL lStart AS LONG _                             ' __in LONG lStart
   , BYVAL lEnd AS LONG _                               ' __in LONG lEnd
   , BYVAL lRate AS LONG _                              ' __in LONG lRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 24
     BYREF lpbi AS BITMAPINFOHEADER _                   ' __in LPBITMAPINFOHEADER lpbi
   , BYVAL lpBits AS DWORD _                            ' __in LPVOID lpBits
   , BYVAL x AS LONG _                                  ' __in int x
   , BYVAL y AS LONG _                                  ' __in int y
   , BYVAL dx AS LONG _                                 ' __in int dx
   , BYVAL dy AS LONG _                                 ' __in int dy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


%AVIFILEHANDLER_CANREAD         = &H0001
%AVIFILEHANDLER_CANWRITE        = &H0002
%AVIFILEHANDLER_CANACCEPTNONRGB = &H0004

'//
'// functions
'//

DECLARE SUB AVIFileInit IMPORT "AVIFIL32.DLL" ALIAS "AVIFileInit" ()   ' void

DECLARE SUB AVIFileExit IMPORT "AVIFIL32.DLL" ALIAS "AVIFileExit" ()   ' void

DECLARE FUNCTION AVIFileAddRef IMPORT "AVIFIL32.DLL" ALIAS "AVIFileAddRef" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION AVIFileRelease IMPORT "AVIFIL32.DLL" ALIAS "AVIFileRelease" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION AVIFileOpenA IMPORT "AVIFIL32.DLL" ALIAS "AVIFileOpenA" ( _
   BYREF ppfile AS DWORD _                              ' __out PAVIFILE * ppfile
 , BYREF szFile AS ASCIIZ _                             ' __in LPCTSTR szFile
 , BYVAL mode AS DWORD _                                ' __in UINT mode
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID pclsidHandler
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileOpenW IMPORT "AVIFIL32.DLL" ALIAS "AVIFileOpenW" ( _
   BYREF ppfile AS DWORD _                              ' __out PAVIFILE * ppfile
 , BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 , BYVAL mode AS DWORD _                                ' __in UINT mode
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID  pclsidHandler
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIFileOpen = AVIFileOpenW
#ELSE
   MACRO AVIFileOpen = AVIFileOpenA
#ENDIF

DECLARE FUNCTION AVIFileInfoA IMPORT "AVIFIL32.DLL" ALIAS "AVIFileInfoA" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYREF pfi AS AVIFILEINFOA_STRUCT _                   ' __out AVIFILEINFO * pfi
 , BYVAL lSize AS LONG _                                ' __in LONG lSize
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileInfoW IMPORT "AVIFIL32.DLL" ALIAS "AVIFileInfoW" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYREF AVIFILEINFOW_STRUCT _                          ' __out AVIFILEINFOW * pfi
 , BYVAL lSize AS LONG _                                ' __in LONG lSize
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIFileInfo = AVIFileInfoW
#ELSE
   MACRO AVIFileInfo = AVIFileInfoA
#ENDIF

DECLARE FUNCTION AVIFileGetStream IMPORT "AVIFIL32.DLL" ALIAS "AVIFileGetStream" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYREF ppavi AS DWORD _                               ' __out PAVISTREAM FAR * ppavi
 , BYVAL fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL lParam AS LONG _                               ' __in LONG lParam
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileCreateStreamA IMPORT "AVIFIL32.DLL" ALIAS "AVIFileCreateStreamA" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYREF ppavi AS DWORD _                               ' __out PAVISTREAM FAR *ppavi
 , BYREF psi AS AVISTREAMINFOA_STRUCT _                 ' __out AVISTREAMINFO FAR * psi
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileCreateStreamW IMPORT "AVIFIL32.DLL" ALIAS "AVIFileCreateStreamW" ( _
   BYVAL pfile AS DWORD _                               ' __in  PAVIFILE pfile
 , BYREF ppavi AS DWORD _                               ' __out PAVISTREAM FAR *ppavi
 , BYREF psi AS AVISTREAMINFOW_STRUCT _                 ' __out AVISTREAMINFOW FAR * psi
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIFileCreateStream = AVIFileCreateStreamW
#ELSE
   MACRO AVIFileCreateStream = AVIFileCreateStreamA
#ENDIF

DECLARE FUNCTION AVIFileWriteData IMPORT "AVIFIL32.DLL" ALIAS "AVIFileWriteData" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYVAL ckid AS DWORD _                                ' __in DWORD ckid
 , BYVAL lpData AS DWORD _                              ' __in LPVOID lpData
 , BYVAL cbData AS LONG _                               ' __in LONG cbData
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileReadData IMPORT "AVIFIL32.DLL" ALIAS "AVIFileReadData" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 , BYVAL ckid AS DWORD _                                ' __in DWORD ckid
 , BYVAL lpData AS DWORD _                              ' __inout LPVOID lpData
 , BYREF lpcbData AS LONG _                             ' __out LONG FAR *lpcbData
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIFileEndRecord IMPORT "AVIFIL32.DLL" ALIAS "AVIFileEndRecord" ( _
   BYVAL pfile AS DWORD _                               ' __in PAVIFILE pfile
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamAddRef IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamAddRef" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamRelease IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamRelease" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamInfoA IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamInfoA" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF psi AS AVISTREAMINFOA_STRUCT _                 ' __in LPAVISTREAMINFO psi
 , BYVAL lSize AS LONG _                                ' __in LONG lSize
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamInfoW IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamInfoW" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF psi AS AVISTREAMINFOW_STRUCT _                 ' __in LPAVISTREAMINFOW psi
 , BYVAL lSize AS LONG _                                ' __in LONG lSize
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIStreamInfo = AVIStreamInfoW
#ELSE
   MACRO AVIStreamInfo = AVIStreamInfoA
#ENDIF

DECLARE FUNCTION AVIStreamFindSample IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamFindSample" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lPos AS LONG _                                 ' __in LONG lPos
 , BYVAL lFlags AS LONG _                               ' __in LONG lFlags
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamReadFormat IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamReadFormat" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lPos AS LONG _                                 ' __in LONG lPos
 , BYVAL lpFormat AS DWORD _                            ' __inout LPVOID lpFormat
 , BYREF lpcbFormat AS LONG _                           ' __out LONG FAR *lpcbFormat
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamSetFormat IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamSetFormat" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lPos AS LONG _                                 ' __in LONG lPos
 , BYVAL lpFormat AS DWORD _                            ' __in LPVOID lpFormat
 , BYVAL cbFormat AS LONG _                             ' __in LONG cbFormat
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamReadData IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamReadData" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL fcc AS DWORD _                                 ' __in DWORD fcc
 , BYVAL lp AS DWORD _                                  ' __inout LPVOID lp
 , BYREF lpcb AS LONG _                                 ' __out LONG FAR *lpcb
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamWriteData IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamWriteData" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL fcc AS DWORD _                                 ' __in DWORD fcc
 , BYVAL lp AS DWORD _                                  ' __in LPVOID lp
 , BYVAL cb AS LONG _                                   ' __in LONG cb
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamRead IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamRead" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lStart AS LONG _                               ' __in LONG lStart
 , BYVAL lSamples AS LONG _                             ' __in LONG lSamples
 , BYVAL lpBuffer AS DWORD _                            ' __inout LPVOID lpBuffer
 , BYVAL cbBuffer AS LONG _                             ' __in LONG cbBuffer
 , BYREF plBytes AS LONG _                              ' __out LONG FAR * plBytes
 , BYREF plSamples AS LONG _                            ' __out LONG FAR * plSamples
 ) AS LONG                                              ' LONG

%AVISTREAMREAD_CONVENIENT = -1&

DECLARE FUNCTION AVIStreamWrite IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamWrite" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lStart AS LONG _                               ' __in LONG lStart
 , BYVAL lSamples AS LONG _                             ' __in LONG lSamples
 , BYVAL lpBuffer AS DWORD _                            ' __inout LPVOID lpBuffer
 , BYVAL cbBuffer AS LONG _                             ' __in LONG cbBuffer
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF plSampWritten AS LONG _                        ' __out LONG FAR *plSampWritten
 , BYREF plBytesWritten AS LONG _                       ' __out LONG FAR *plBytesWritten
 ) AS LONG                                              ' LONG

'// Right now, these just use AVIStreamInfo() to get information, then
'// return some of it.  Can they be more efficient?

DECLARE FUNCTION AVIStreamStart IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamStart" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamLength IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamLength" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamTimeToSample IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamTimeToSample" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lTime AS LONG _                                ' __in LONG lTime
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamSampleToTime IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamSampleToTime" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lSample AS LONG _                              ' __in LONG lSample
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamBeginStreaming IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamBeginStreaming" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lStart AS LONG _                               ' __in LONG lStart
 , BYVAL lEnd AS LONG _                                 ' __in LONG lEnd
 , BYVAL lRate AS LONG _                                ' __in LONG lRate
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamEndStreaming IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamEndStreaming" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 ) AS LONG                                              ' LONG

'//
'// helper functions for using IGetFrame
'//

DECLARE FUNCTION AVIStreamGetFrameOpen IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamGetFrameOpen" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF lpbiWanted AS BITMAPINFOHEADER _               ' __in LPBITMAPINFOHEADER lpbiWanted
 ) AS DWORD                                             ' PGETFRAME

DECLARE FUNCTION AVIStreamGetFrame IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamGetFrame" ( _
   BYVAL pg AS DWORD _                                  ' __in PGETFRAME pg
 , BYVAL lPos AS LONG _                                 ' __in LONG lPos
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION AVIStreamGetFrameClose IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamGetFrameClose" ( _
   BYVAL pg AS DWORD _                                  ' __in PGETFRAME pg
 ) AS LONG                                              ' LONG

'// !!! We need some way to place an advise on a stream....
'// STDAPI AVIStreamHasChanged   (PAVISTREAM pavi);

'// Shortcut function

DECLARE FUNCTION AVIStreamOpenFromFileA IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamOpenFromFileA" ( _
   BYREF ppavi AS DWORD _                              ' __out PAVISTREAM FAR *ppavi
 , BYREF szFile AS ASCIIZ _                             ' __in LPCSTR szFile
 , BYVAL fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL lParam AS LONG _                               ' __in LONG lParam
 , BYVAL mode AS DWORD _                                ' __in UINT mode
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIStreamOpenFromFileW IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamOpenFromFileW" ( _
   BYREF ppavi AS DWORD _                               ' __out PAVISTREAM FAR *ppavi
 , BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 , BYVAL fccType AS DWORD _                             ' __in DWORD fccType
 , BYVAL lParam AS LONG _                               ' __in LONG lParam
 , BYVAL mode AS DWORD _                                ' __in UINT mode
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIStreamOpenFromFile = AVIStreamOpenFromFileW
#ELSE
   MACRO AVIStreamOpenFromFile = AVIStreamOpenFromFileA
#ENDIF

'// Use to create disembodied streams

DECLARE FUNCTION AVIStreamCreate IMPORT "AVIFIL32.DLL" ALIAS "AVIStreamCreate" ( _
   BYREF ppavi AS DWORD _                               ' __out PAVISTREAM FAR *ppavi
 , BYVAL lParam1 AS LONG _                              ' __in LONG lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LONG lParam2
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 ) AS LONG                                              ' LONG

'// PHANDLER    AVIAPI AVIGetHandler         (PAVISTREAM pavi, PAVISTREAMHANDLER psh);
'// PAVISTREAM  AVIAPI AVIGetStream          (PHANDLER p);

'//
'// flags for AVIStreamFindSample
'//
%FIND_DIR        = &H0000000F???     ' // direction
%FIND_NEXT       = &H00000001???     ' // go forward
%FIND_PREV       = &H00000004???     ' // go backward
%FIND_FROM_START = &H00000008???     ' // start at the logical beginning

%FIND_TYPE       = &H000000F0???     ' // type mask
%FIND_KEY        = &H00000010???     ' // find key frame.
%FIND_ANY        = &H00000020???     ' // find any (non-empty) sample
%FIND_FORMAT     = &H00000040???     ' // find format change

%FIND_RET        = &H0000F000???     ' // return mask
%FIND_POS        = &H00000000???     ' // return logical position
%FIND_LENGTH     = &H00001000???     ' // return logical size
%FIND_OFFSET     = &H00002000???     ' // return physical position
%FIND_SIZE       = &H00003000???     ' // return physical size
%FIND_INDEX      = &H00004000???     ' // return physical index position


'//
'//  stuff to support backward compat.
'//
'#define AVIStreamFindKeyFrame AVIStreamFindSample
'#define FindKeyFrame   FindSample

'#define AVIStreamClose AVIStreamRelease
'#define AVIFileClose   AVIFileRelease
'#define AVIStreamInit  AVIFileInit
'#define AVIStreamExit  AVIFileExit

%SEARCH_NEAREST  = %FIND_PREV
%SEARCH_BACKWARD = %FIND_PREV
%SEARCH_FORWARD  = %FIND_NEXT
%SEARCH_KEY      = %FIND_KEY
%SEARCH_ANY      = %FIND_ANY

'//
'//  helper macros.
'//
'#define     AVIStreamSampleToSample(pavi1, pavi2, l) \
'            AVIStreamTimeToSample(pavi1,AVIStreamSampleToTime(pavi2, l))

FUNCTION AVIStreamSampleToSample(BYVAL pavi1 AS DWORD, BYVAL pavi2 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamTimeToSample(pavi1, AVIStreamSampleToTime(pavi2, l))
END FUNCTION

'#define     AVIStreamNextSample(pavi, l) \
'            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_ANY)

FUNCTION AVIStreamNextSample(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l+1, %FIND_NEXT OR %FIND_ANY)
END FUNCTION

'#define     AVIStreamPrevSample(pavi, l) \
'            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_ANY)

FUNCTION AVIStreamPrevSample(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l-1, %FIND_PREV OR %FIND_ANY)
END FUNCTION

'#define     AVIStreamNearestSample(pavi, l) \
'            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_ANY)

FUNCTION AVIStreamNearestSample(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l, %FIND_PREV OR %FIND_ANY)
END FUNCTION

'#define     AVIStreamNextKeyFrame(pavi,l) \
'            AVIStreamFindSample(pavi,l+1,FIND_NEXT|FIND_KEY)

FUNCTION AVIStreamNextKeyFrame(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l+1, %FIND_NEXT OR %FIND_KEY)
END FUNCTION

'#define     AVIStreamPrevKeyFrame(pavi, l) \
'            AVIStreamFindSample(pavi,l-1,FIND_PREV|FIND_KEY)

FUNCTION AVIStreamPrevKeyFrame(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l-1, %FIND_PREV OR %FIND_KEY)
END FUNCTION

'#define     AVIStreamNearestKeyFrame(pavi, l) \
'            AVIStreamFindSample(pavi,l,FIND_PREV|FIND_KEY)

FUNCTION AVIStreamNearestKeyFrame(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = AVIStreamFindSample(pavi1, l, %FIND_PREV OR %FIND_KEY)
END FUNCTION

'#define     AVIStreamIsKeyFrame(pavi, l) \
'            (AVIStreamNearestKeyFrame(pavi,l) == l)

FUNCTION AVIStreamIsKeyFrame(BYVAL pavi1 AS DWORD, BYVAL l AS LONG) AS LONG
   FUNCTION = (AVIStreamNearestKeyFrame(pavi1, l) = l)
END FUNCTION

'#define     AVIStreamPrevSampleTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamPrevSample(pavi,AVIStreamTimeToSample(pavi,t)))

FUNCTION AVIStreamPrevSampleTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamSampleToTime(pavi, AVIStreamPrevSample(pavi, AVIStreamTimeToSample(pavi, t))))
END FUNCTION

'#define     AVIStreamNextSampleTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamNextSample(pavi,AVIStreamTimeToSample(pavi,t)))

FUNCTION AVIStreamNextSampleTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamNextSample(pavi, AVIStreamTimeToSample(pavi, t)))
END FUNCTION

'#define     AVIStreamNearestSampleTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamNearestSample(pavi,AVIStreamTimeToSample(pavi,t)))

FUNCTION AVIStreamNearestSampleTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamNearestSample(pavi, AVIStreamTimeToSample(pavi, t)))
END FUNCTION

'#define     AVIStreamNextKeyFrameTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamNextKeyFrame(pavi,AVIStreamTimeToSample(pavi, t)))

FUNCTION AVIStreamNextKeyFrameTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamNextKeyFrame(pavi, AVIStreamTimeToSample(pavi, t)))
END FUNCTION

'#define     AVIStreamPrevKeyFrameTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamPrevKeyFrame(pavi,AVIStreamTimeToSample(pavi, t)))

FUNCTION AVIStreamPrevKeyFrameTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamPrevKeyFrame(pavi, AVIStreamTimeToSample(pavi, t)))
END FUNCTION

'#define     AVIStreamNearestKeyFrameTime(pavi, t) \
'            AVIStreamSampleToTime(pavi, AVIStreamNearestKeyFrame(pavi,AVIStreamTimeToSample(pavi, t)))

FUNCTION AVIStreamNearestKeyFrameTime(BYVAL pavi AS DWORD, BYVAL t AS LONG) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamNearestKeyFrame(pavi, AVIStreamTimeToSample(pavi, t)))
END FUNCTION

'#define     AVIStreamStartTime(pavi) \
'            AVIStreamSampleToTime(pavi, AVIStreamStart(pavi))

FUNCTION AVIStreamStartTime(BYVAL pavi AS DWORD) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamStart(pavi))
END FUNCTION

'#define     AVIStreamLengthTime(pavi) \
'            AVIStreamSampleToTime(pavi, AVIStreamLength(pavi))

FUNCTION AVIStreamLengthTime(BYVAL pavi AS DWORD) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamLength(pavi))
END FUNCTION

'#define     AVIStreamEnd(pavi) \
'            (AVIStreamStart(pavi) + AVIStreamLength(pavi))

FUNCTION AVIStreamEnd(BYVAL pavi AS DWORD) AS LONG
   FUNCTION = AVIStreamStart(pavi) + AVIStreamLength(pavi)
END FUNCTION

'#define     AVIStreamEndTime(pavi) \
'            AVIStreamSampleToTime(pavi, AVIStreamEnd(pavi))

FUNCTION AVIStreamEndTime(BYVAL pavi AS DWORD) AS LONG
   FUNCTION = AVIStreamSampleToTime(pavi, AVIStreamEnd(pavi))
END FUNCTION

'#define     AVIStreamSampleSize(pavi, lPos, plSize) \
'       AVIStreamRead(pavi,lPos,1,NULL,0,plSize,NULL)

FUNCTION AVIStreamSampleSize(BYVAL pavi AS DWORD, BYVAL lPos AS LONG, BYVAL plSize AS LONG) AS LONG
   FUNCTION = AVIStreamRead(pavi, lPos, 1, %NULL, 0, plSize, %NULL)
END FUNCTION

'#define     AVIStreamFormatSize(pavi, lPos, plSize) \
'            AVIStreamReadFormat(pavi,lPos,NULL,plSize)

FUNCTION AVIStreamFormatSize(BYVAL pavi AS DWORD, BYVAL lPos AS LONG, BYVAL plSize AS LONG) AS LONG
   FUNCTION = AVIStreamReadFormat(pavi, lPos, %NULL, plSize)
END FUNCTION

'#define     AVIStreamDataSize(pavi, fcc, plSize) \
'            AVIStreamReadData(pavi,fcc,NULL,plSize)

FUNCTION AVIStreamDataSize(BYVAL pavi AS DWORD, BYVAL fcc AS DWORD, BYVAL plSize AS LONG) AS LONG
   FUNCTION = AVIStreamReadData(pavi, fcc, %NULL, plSize)
END FUNCTION

'/****************************************************************************
' *
' *  AVISave routines and structures
' *
' ***************************************************************************/

'#ifndef comptypeDIB
'#define comptypeDIB         mmioFOURCC('D', 'I', 'B', ' ')
'#endif

#IF NOT %DEF(%comptypeDIB)
%comptypeDIB = &H20424944
#ENDIF

DECLARE FUNCTION AVIMakeCompressedStream IMPORT "AVIFIL32.DLL" ALIAS "AVIMakeCompressedStream" ( _
   BYREF ppsCompressed AS DWORD _                       ' __out PAVISTREAM FAR * ppsCompressed
 , BYVAL psSource AS DWORD _                            ' __in PAVISTREAM psSource
 , BYREF lpOptions AS AVICOMPRESSOPTIONS_STRUCT _       ' __in AVICOMPRESSOPTIONS FAR * lpOptions
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVISaveA CDECL IMPORT "AVIFIL32.DLL" ALIAS "AVISaveA" ( _
   BYREF szFile AS ASCIIZ _                             ' __in LPCSTR szFile
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 , BYVAL lpfnCallback AS DWORD _                        ' __in AVISAVECALLBACK lpfnCallback
 , BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYVAL pfile AS DWORD _                               ' __in PAVISTREAM pfile
 , BYREF lpOptions AS AVICOMPRESSOPTIONS_STRUCT _       ' __in LPAVICOMPRESSOPTIONS lpOptions
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AVISaveW CDECL IMPORT "AVIFIL32.DLL" ALIAS "AVISaveW" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 , BYVAL lpfnCallback AS DWORD _                        ' __in AVISAVECALLBACK lpfnCallback
 , BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYVAL pfile AS DWORD _                               ' __in PAVISTREAM pfile
 , BYREF lpOptions AS AVICOMPRESSOPTIONS_STRUCT _       ' __in LPAVICOMPRESSOPTIONS lpOptions
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVISave = AVISaveW
#ELSE
   MACRO AVISave = AVISaveA
#ENDIF

DECLARE FUNCTION AVISaveVA IMPORT "AVIFIL32.DLL" ALIAS "AVISaveVA" ( _
   BYREF szFile AS ASCIIZ _                             ' __in LPCSTR szFile
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 , BYVAL lpfnCallback AS DWORD _                        ' __in AVISAVECALLBACK lpfnCallback
 , BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYREF ppavi AS DWORD _                               ' __in PAVISTREAM FAR * ppavi [array]
 , BYREF plpOptions AS AVICOMPRESSOPTIONS_STRUCT _      ' __in LPAVICOMPRESSOPTIONS FAR *plpOptions [array]
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVISaveVW IMPORT "AVIFIL32.DLL" ALIAS "AVISaveVW" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 , BYREF pclsidHandler AS GUID _                        ' __in CLSID FAR *pclsidHandler
 , BYVAL lpfnCallback AS DWORD _                        ' __in AVISAVECALLBACK lpfnCallback
 , BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYREF ppavi AS DWORD _                               ' __in PAVISTREAM FAR * ppavi [array]
 , BYREF plpOptions AS AVICOMPRESSOPTIONS_STRUCT _      ' __in LPAVICOMPRESSOPTIONS FAR *plpOptions [array]
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVISaveV = AVISaveVW
#ELSE
   MACRO AVISaveV = AVISaveVA
#ENDIF

DECLARE FUNCTION AVISaveOptions IMPORT "AVIFIL32.DLL" ALIAS "AVISaveOptions" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL uiFlags AS DWORD _                             ' __in UINT uiFlags
 , BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYREF ppavi AS DWORD _                               ' __in PAVISTREAM FAR * ppavi [array]
 , BYREF plpOptions AS AVICOMPRESSOPTIONS_STRUCT _      ' __in LPAVICOMPRESSOPTIONS FAR *plpOptions [array]
 ) AS DWORD                                             ' INT_PTR

DECLARE FUNCTION AVISaveOptionsFree IMPORT "AVIFIL32.DLL" ALIAS "AVISaveOptionsFree" ( _
   BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYREF plpOptions AS AVICOMPRESSOPTIONS_STRUCT _      ' __in LPAVICOMPRESSOPTIONS FAR *plpOptions [array]
 ) AS DWORD                                             ' INT_PTR

'// FLAGS FOR uiFlags:
'//
'// Same as the flags for ICCompressorChoose (see compman.h)
'// These determine what the compression options dialog for video streams
'// will look like.

DECLARE FUNCTION AVIBuildFilterW IMPORT "AVIFIL32.DLL" ALIAS "AVIBuildFilterW" ( _
   BYREF lpszFilter AS WSTRINGZ _                       ' __in LPWSTR lpszFilter
 , BYVAL fSaving AS LONG _                              ' __in BOOL fSaving
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIBuildFilterA IMPORT "AVIFIL32.DLL" ALIAS "AVIBuildFilterA" ( _
   BYREF lpszFilter AS ASCIIZ _                         ' __in LPSTR lpszFilter
 , BYVAL fSaving AS LONG _                              ' __in BOOL fSaving
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO AVIBuildFilter = AVIBuildFilterW
#ELSE
   MACRO AVIBuildFilter = AVIBuildFilterA
#ENDIF

DECLARE FUNCTION AVIMakeFileFromStreams IMPORT "AVIFIL32.DLL" ALIAS "AVIMakeFileFromStreams" ( _
   BYVAL nStreams AS LONG _                             ' __in int nStreams
 , BYREF papStreams AS DWORD _                          ' __in PAVISTREAM FAR * papStreams [array]
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIMakeStreamFromClipboard IMPORT "AVIFIL32.DLL" ALIAS "AVIMakeStreamFromClipboard" ( _
   BYVAL cfFormat AS DWORD _                            ' __in UINT cfFormat
 , BYVAL hGlobal AS DWORD _                             ' __in HANDLE hGlobal
 , BYREF ppstream AS DWORD _                            ' __out AVISTREAM FAR *ppstream
 ) AS LONG                                              ' LONG

'/****************************************************************************
' *
' *  Clipboard routines
' *
' ***************************************************************************/

DECLARE FUNCTION AVIPutFileOnClipboard IMPORT "AVIFIL32.DLL" ALIAS "AVIPutFileOnClipboard" ( _
   BYVAL pf AS DWORD _                                  ' __in PAVIFILE pf
 ) AS LONG                                              ' LONG

DECLARE FUNCTION AVIGetFromClipboard IMPORT "AVIFIL32.DLL" ALIAS "AVIGetFromClipboard" ( _
   BYREF lppf AS DWORD _                                ' __in PAVIFILE FAR * lppf
 ) AS LONG                                              ' LONG

DECLARE SUB AVIClearClipboard IMPORT "AVIFIL32.DLL" ALIAS "AVIClearClipboard" ( _
 )                                                      ' void

'/****************************************************************************
' *
' *  Editing routines
' *
' ***************************************************************************/

DECLARE FUNCTION CreateEditableStream IMPORT "AVIFIL32.DLL" ALIAS "CreateEditableStream" ( _
   BYREF ppsEditable AS DWORD _                         ' __out PAVISTREAM FAR * ppsEditable
 , BYVAL psSource AS DWORD _                            ' __in PAVISTREAM psSource
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamCut IMPORT "AVIFIL32.DLL" ALIAS "EditStreamCut" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF plStart AS LONG _                              ' __out LONG FAR *plStart
 , BYREF plLength AS LONG _                             ' __out LONG FAR *plLength
 , BYREF ppResult AS DWORD _                            ' __out PAVISTREAM FAR * ppResult
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamCopy IMPORT "AVIFIL32.DLL" ALIAS "EditStreamCopy" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF plStart AS LONG _                              ' __out LONG FAR *plStart
 , BYREF plLength AS LONG _                             ' __out LONG FAR *plLength
 , BYREF ppResult AS DWORD _                            ' __out PAVISTREAM FAR * ppResult
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamPaste IMPORT "AVIFIL32.DLL" ALIAS "EditStreamPaste" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF plPos AS LONG _                                ' __out LONG FAR *plPos
 , BYREF plLength AS LONG _                             ' __out LONG FAR *plLength
 , BYVAL pstream AS DWORD _                             ' __in PAVISTREAM pstream
 , BYVAL lStart AS LONG _                               ' __in LONG lStart
 , BYVAL lEnd AS LONG _                                 ' __in LONG lEnd
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamClone IMPORT "AVIFIL32.DLL" ALIAS "EditStreamClone" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF ppResult AS DWORD _                            ' __out PAVISTREAM FAR * ppResult
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamSetNameA IMPORT "AVIFIL32.DLL" ALIAS "EditStreamSetNameA" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF lpszName AS ASCIIZ _                           ' __in LPCSTR lpszName
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamSetNameW IMPORT "AVIFIL32.DLL" ALIAS "EditStreamSetNameW" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYVAL lpszName AS DWORD _                            ' __in LPCSWTR lpszName
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO EditStreamSetName = EditStreamSetNameW
#ELSE
   MACRO EditStreamSetName = EditStreamSetNameA
#ENDIF

DECLARE FUNCTION EditStreamSetInfoA IMPORT "AVIFIL32.DLL" ALIAS "EditStreamSetInfoA" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF lpInfo AS AVISTREAMINFOA_STRUCT _              ' __in LPAVISTREAMINFOA lpInfo
 , BYVAL cbInfo AS LONG _                               ' __in LONG cbInfo
 ) AS LONG                                              ' LONG

DECLARE FUNCTION EditStreamSetInfoW IMPORT "AVIFIL32.DLL" ALIAS "EditStreamSetInfoW" ( _
   BYVAL pavi AS DWORD _                                ' __in PAVISTREAM pavi
 , BYREF lpInfo AS AVISTREAMINFOW_STRUCT _              ' __in LPAVISTREAMINFOW lpInfo
 , BYVAL cbInfo AS LONG _                               ' __in LONG cbInfo
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO EditStreamSetInfo = EditStreamSetInfoW
#ELSE
   MACRO EditStreamSetInfo = EditStreamSetInfoA
#ENDIF

'/*   -   -   -   -   -   -   -   -   */

#IF NOT %DEF(%AVIERR_OK)
%AVIERR_OK = 0

'#define MAKE_AVIERR(error)   MAKE_SCODE(SEVERITY_ERROR, FACILITY_ITF, 0x4000 + error)

FUNCTION MAKE_AVIERR (BYVAL dwError AS DWORD) AS DWORD
   FUNCTION = MAKE_SCODE(%SEVERITY_ERROR, %FACILITY_ITF, &H4000 + dwError)
END FUNCTION

'// !!! Questions to be answered:
'// How can you get a string form of these errors?
'// Which of these errors should be replaced by errors in SCODE.H?
%AVIERR_UNSUPPORTED      = &H80044065
%AVIERR_BADFORMAT        = &H80044066
%AVIERR_MEMORY           = &H80044067
%AVIERR_INTERNAL         = &H80044068
%AVIERR_BADFLAGS         = &H80044069
%AVIERR_BADPARAM         = &H8004406A
%AVIERR_BADSIZE          = &H8004406B
%AVIERR_BADHANDLE        = &H8004406C
%AVIERR_FILEREAD         = &H8004406D
%AVIERR_FILEWRITE        = &H8004406E
%AVIERR_FILEOPEN         = &H8004406F
%AVIERR_COMPRESSOR       = &H80044070
%AVIERR_NOCOMPRESSOR     = &H80044071
%AVIERR_READONLY         = &H80044072
%AVIERR_NODATA           = &H80044073
%AVIERR_BUFFERTOOSMALL   = &H80044074
%AVIERR_CANTCOMPRESS     = &H80044075
%AVIERR_USERABORT        = &H800440C6
%AVIERR_ERROR            = &H800440C7
'#endif

#ENDIF  ' /* NOAVIFILE */  ---------------------------------------------------------------

'/****************************************************************************
' *
' *  MCIWnd - Window class for MCI objects
' *
' ***************************************************************************/

#IF NOT %DEF(%NOMCIWND) ' ----------------------------------------------------------------

'/*----------------------------------------------------------------------------*\
' *
' *  MCIWnd
' *
' *    MCIWnd window class header file.
' *
' *    the MCIWnd window class is a window class for controling MCI devices
' *    MCI devices include, wave files, midi files, AVI Video, cd audio,
' *    vcr, video disc, and others..
' *
' *    to learn more about MCI and mci command sets see the
' *    "Microsoft Multimedia Programmers's guide" in the Win31 SDK
' *
' *    the easiest use of the MCIWnd class is like so:
' *
' *          hwnd = MCIWndCreate(hwndParent, hInstance, 0, "chimes.wav");
' *          ...
' *          MCIWndPlay(hwnd);
' *          MCIWndStop(hwnd);
' *          MCIWndPause(hwnd);
' *          ....
' *          MCIWndDestroy(hwnd);
' *
' *    this will create a window with a play/pause, stop and a playbar
' *    and start the wave file playing.
' *
' *    mciwnd.h defines macros for all the most common MCI commands, but
' *    any string command can be used if needed.
' *
' *    Note: unlike the mciSendString() API, no alias or file name needs
' *    to be specifed, since the device to use is implied by the window handle.
' *
' *          MCIWndSendString(hwnd, "setaudio stream to 2");
' *
' *    (C) Copyright Microsoft Corp. 1991-1995.  All rights reserved.
' *
' *    You have a royalty-free right to use, modify, reproduce and
' *    distribute the Sample Files (and/or any modified version) in
' *    any way you find useful, provided that you agree that
' *    Microsoft has no warranty obligations or liability for any
' *    Sample Application Files.
' *
' *    If you did not get this from Microsoft Sources, then it may not be the
' *    most current version.  This sample code in particular will be updated
' *    and include more documentation.
' *
' *    Sources are:
' *       CompuServe: WINSDK forum, MDK section.
' *       Anonymous FTP from ftp.uu.net vendor\microsoft\multimedia
' *
' * WIN32:
' *
' *    MCIWnd supports both ansi and unicode interfaces. For any message that
' *    takes or returns a text string, two versions of the message are defined,
' *    appended with A or W for Ansi or Wide Char. The message or api itself
' *    is defined to be one or other of these depending on whether you have
' *    UNICODE defined in your application.
' *    Thus for the api MCIWndCreate, there are in fact two apis,
' *    MCIWndCreateA and MCIWndCreateW. If you call MCIWndCreate, this will be
' *    re-routed to MCIWndCreateA unless UNICODE is defined when building your
' *    application. In any one application, you can mix calls to the
' *    Ansi and Unicode entrypoints.
' *
' *    If you use SendMessage instead of the macros below such as MCIWndOpen(),
' *    you will see that the messages have changed for WIN32, to support Ansi
' *    and Unicode entrypoints. In particular, MCI_OPEN has been replaced by
' *    MCWNDM_OPENA, or MCIWNDM_OPENW (MCIWNDM_OPEN is defined to be one or
' *    other of these).
' *
' *    Also, note that the WIN32 implementation of MCIWnd uses UNICODE
' *    so all apis and messages supporting ANSI strings do so by mapping them
' *    UNICODE strings and then calling the corresponding UNICODE entrypoint.
' *
' *----------------------------------------------------------------------------*/

'#ifdef __cplusplus
'// MFC Redefines SendMessage, so make sure we get the global one....
'#define MCIWndSM ::SendMessage  /* SendMessage in C++*/
'#else
'#define MCIWndSM SendMessage    /* SendMessage in C */
'#endif  /* __cplusplus */
'#define MCIWND_WINDOW_CLASS TEXT("MCIWndClass")

$MCIWND_WINDOW_CLASS = "MCIWndClass"

DECLARE FUNCTION MCIWndCreateA IMPORT "MSVFW32.DLL" ALIAS "MCIWndCreateA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF szFile AS ASCIIZ _                             ' __in LPCSTR szFile
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION MCIWndCreateW IMPORT "MSVFW32.DLL" ALIAS "MCIWndCreateW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYREF szFile AS WSTRINGZ _                           ' __in LPCWSTR szFile
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO MCIWndCreate = MCIWndCreateW
#ELSE
   MACRO MCIWndCreate = MCIWndCreateA
#ENDIF

DECLARE FUNCTION MCIWndRegisterClass IMPORT "MSVFW32.DLL" ALIAS "MCIWndRegisterClass" ( _
 ) AS LONG                                              ' BOOL


'// Flags for the MCIWndOpen command
%MCIWNDOPENF_NEW             = &H0001??? ' // open a new file

'// window styles
%MCIWNDF_NOAUTOSIZEWINDOW    = &H0001??? ' // when movie size changes
%MCIWNDF_NOPLAYBAR           = &H0002??? ' // no toolbar
%MCIWNDF_NOAUTOSIZEMOVIE     = &H0004??? ' // when window size changes
%MCIWNDF_NOMENU              = &H0008??? ' // no popup menu from RBUTTONDOWN
%MCIWNDF_SHOWNAME            = &H0010??? ' // show name in caption
%MCIWNDF_SHOWPOS             = &H0020??? ' // show position in caption
%MCIWNDF_SHOWMODE            = &H0040??? ' // show mode in caption
%MCIWNDF_SHOWALL             = &H0070??? ' // show all

%MCIWNDF_NOTIFYMODE          = &H0100??? ' // tell parent of mode change
%MCIWNDF_NOTIFYPOS           = &H0200??? ' // tell parent of pos change
%MCIWNDF_NOTIFYSIZE          = &H0400??? ' // tell parent of size change
%MCIWNDF_NOTIFYERROR         = &H1000??? ' // tell parent of an error
%MCIWNDF_NOTIFYALL           = &H1F00??? ' // tell all

%MCIWNDF_NOTIFYANSI          = &H0080???


'// The MEDIA notification includes a text string.
'// To receive notifications in ANSI instead of unicode set the
'// MCIWNDF_NOTIFYANSI style bit. The macro below includes this bit
'// by default unless you define UNICODE in your application.

%MCIWNDF_NOTIFYMEDIA         = &H0880??? ' // tell parent of media change
%MCIWNDF_NOTIFYMEDIAA        = &H0880??? ' // tell parent of media change
%MCIWNDF_NOTIFYMEDIAW        = &H0800??? ' // tell parent of media change

%MCIWNDF_RECORD              = &H2000??? ' // Give a record button
%MCIWNDF_NOERRORDLG          = &H4000??? ' // Show Error Dlgs for MCI cmds?
%MCIWNDF_NOOPEN              = &H8000??? ' // Don't allow user to open things

'// Messages an app will send to MCIWND

'// all the text-related messages are defined out of order above (they need
'// to be defined before the MCIWndOpen() macros

%MCIWNDM_GETDEVICEID      = (%WM_USER + 100)
%MCIWNDM_GETSTART         = (%WM_USER + 103)
%MCIWNDM_GETLENGTH        = (%WM_USER + 104)
%MCIWNDM_GETEND           = (%WM_USER + 105)
%MCIWNDM_EJECT            = (%WM_USER + 107)
%MCIWNDM_SETZOOM          = (%WM_USER + 108)
%MCIWNDM_GETZOOM          = (%WM_USER + 109)
%MCIWNDM_SETVOLUME        = (%WM_USER + 110)
%MCIWNDM_GETVOLUME        = (%WM_USER + 111)
%MCIWNDM_SETSPEED         = (%WM_USER + 112)
%MCIWNDM_GETSPEED         = (%WM_USER + 113)
%MCIWNDM_SETREPEAT        = (%WM_USER + 114)
%MCIWNDM_GETREPEAT        = (%WM_USER + 115)
%MCIWNDM_REALIZE          = (%WM_USER + 118)
%MCIWNDM_VALIDATEMEDIA    = (%WM_USER + 121)
%MCIWNDM_PLAYFROM         = (%WM_USER + 122)
%MCIWNDM_PLAYTO           = (%WM_USER + 123)
%MCIWNDM_GETPALETTE       = (%WM_USER + 126)
%MCIWNDM_SETPALETTE       = (%WM_USER + 127)
%MCIWNDM_SETTIMERS        = (%WM_USER + 129)
%MCIWNDM_SETACTIVETIMER   = (%WM_USER + 130)
%MCIWNDM_SETINACTIVETIMER = (%WM_USER + 131)
%MCIWNDM_GETACTIVETIMER   = (%WM_USER + 132)
%MCIWNDM_GETINACTIVETIMER = (%WM_USER + 133)
%MCIWNDM_CHANGESTYLES     = (%WM_USER + 135)
%MCIWNDM_GETSTYLES        = (%WM_USER + 136)
%MCIWNDM_GETALIAS         = (%WM_USER + 137)
%MCIWNDM_PLAYREVERSE      = (%WM_USER + 139)
%MCIWNDM_GET_SOURCE       = (%WM_USER + 140)
%MCIWNDM_PUT_SOURCE       = (%WM_USER + 141)
%MCIWNDM_GET_DEST         = (%WM_USER + 142)
%MCIWNDM_PUT_DEST         = (%WM_USER + 143)
%MCIWNDM_CAN_PLAY         = (%WM_USER + 144)
%MCIWNDM_CAN_WINDOW       = (%WM_USER + 145)
%MCIWNDM_CAN_RECORD       = (%WM_USER + 146)
%MCIWNDM_CAN_SAVE         = (%WM_USER + 147)
%MCIWNDM_CAN_EJECT        = (%WM_USER + 148)
%MCIWNDM_CAN_CONFIG       = (%WM_USER + 149)
%MCIWNDM_PALETTEKICK      = (%WM_USER + 150)
%MCIWNDM_OPENINTERFACE    = (%WM_USER + 151)
%MCIWNDM_SETOWNER         = (%WM_USER + 152)

'//define both A and W messages
%MCIWNDM_SENDSTRINGA      = (%WM_USER + 101)
%MCIWNDM_GETPOSITIONA     = (%WM_USER + 102)
%MCIWNDM_GETMODEA         = (%WM_USER + 106)
%MCIWNDM_SETTIMEFORMATA   = (%WM_USER + 119)
%MCIWNDM_GETTIMEFORMATA   = (%WM_USER + 120)
%MCIWNDM_GETFILENAMEA     = (%WM_USER + 124)
%MCIWNDM_GETDEVICEA       = (%WM_USER + 125)
%MCIWNDM_GETERRORA        = (%WM_USER + 128)
%MCIWNDM_NEWA             = (%WM_USER + 134)
%MCIWNDM_RETURNSTRINGA    = (%WM_USER + 138)
%MCIWNDM_OPENA            = (%WM_USER + 153)

%MCIWNDM_SENDSTRINGW      = (%WM_USER + 201)
%MCIWNDM_GETPOSITIONW     = (%WM_USER + 202)
%MCIWNDM_GETMODEW         = (%WM_USER + 206)
%MCIWNDM_SETTIMEFORMATW   = (%WM_USER + 219)
%MCIWNDM_GETTIMEFORMATW   = (%WM_USER + 220)
%MCIWNDM_GETFILENAMEW     = (%WM_USER + 224)
%MCIWNDM_GETDEVICEW       = (%WM_USER + 225)
%MCIWNDM_GETERRORW        = (%WM_USER + 228)
%MCIWNDM_NEWW             = (%WM_USER + 234)
%MCIWNDM_RETURNSTRINGW    = (%WM_USER + 238)
%MCIWNDM_OPENW            = (%WM_USER + 252)

'// map defaults to A or W depending on app's UNICODE setting
'#ifdef UNICODE
'#define MCIWNDM_SENDSTRING      MCIWNDM_SENDSTRINGW
'#define MCIWNDM_GETPOSITION     MCIWNDM_GETPOSITIONW
'#define MCIWNDM_GETMODE         MCIWNDM_GETMODEW
'#define MCIWNDM_SETTIMEFORMAT   MCIWNDM_SETTIMEFORMATW
'#define MCIWNDM_GETTIMEFORMAT   MCIWNDM_GETTIMEFORMATW
'#define MCIWNDM_GETFILENAME     MCIWNDM_GETFILENAMEW
'#define MCIWNDM_GETDEVICE       MCIWNDM_GETDEVICEW
'#define MCIWNDM_GETERROR        MCIWNDM_GETERRORW
'#define MCIWNDM_NEW             MCIWNDM_NEWW
'#define MCIWNDM_RETURNSTRING    MCIWNDM_RETURNSTRINGW
'#define MCIWNDM_OPEN      MCIWNDM_OPENW
'#else
'#define MCIWNDM_SENDSTRING      MCIWNDM_SENDSTRINGA
'#define MCIWNDM_GETPOSITION     MCIWNDM_GETPOSITIONA
'#define MCIWNDM_GETMODE         MCIWNDM_GETMODEA
'#define MCIWNDM_SETTIMEFORMAT   MCIWNDM_SETTIMEFORMATA
'#define MCIWNDM_GETTIMEFORMAT   MCIWNDM_GETTIMEFORMATA
'#define MCIWNDM_GETFILENAME     MCIWNDM_GETFILENAMEA
'#define MCIWNDM_GETDEVICE       MCIWNDM_GETDEVICEA
'#define MCIWNDM_GETERROR        MCIWNDM_GETERRORA
'#define MCIWNDM_NEW             MCIWNDM_NEWA
'#define MCIWNDM_RETURNSTRING    MCIWNDM_RETURNSTRINGA
'#define MCIWNDM_OPEN      MCIWNDM_OPENA
'#endif

%MCIWNDM_SENDSTRING     = %MCIWNDM_SENDSTRINGA
%MCIWNDM_GETPOSITION    = %MCIWNDM_GETPOSITIONA
%MCIWNDM_GETMODE        = %MCIWNDM_GETMODEA
%MCIWNDM_SETTIMEFORMAT  = %MCIWNDM_SETTIMEFORMATA
%MCIWNDM_GETTIMEFORMAT  = %MCIWNDM_GETTIMEFORMATA
%MCIWNDM_GETFILENAME    = %MCIWNDM_GETFILENAMEA
%MCIWNDM_GETDEVICE      = %MCIWNDM_GETDEVICEA
%MCIWNDM_GETERROR       = %MCIWNDM_GETERRORA
%MCIWNDM_NEW            = %MCIWNDM_NEWA
%MCIWNDM_RETURNSTRING   = %MCIWNDM_RETURNSTRINGA
%MCIWNDM_OPEN           = %MCIWNDM_OPENA

'// note that the source text for MCIWND will thus contain
'// support for eg MCIWNDM_SENDSTRING (both the 16-bit entrypoint and
'// in win32 mapped to MCIWNDM_SENDSTRINGW), and MCIWNDM_SENDSTRINGA (the
'// win32 ansi thunk).

'// Messages MCIWND will send to an app
'// !!! Use less messages and use a code instead to indicate the type of notify? /* ;Internal */
%MCIWNDM_NOTIFYMODE  = (%WM_USER + 200) ' // wp = hwnd, lp = mode
%MCIWNDM_NOTIFYPOS   = (%WM_USER + 201) ' // wp = hwnd, lp = pos
%MCIWNDM_NOTIFYSIZE  = (%WM_USER + 202) ' // wp = hwnd
%MCIWNDM_NOTIFYMEDIA = (%WM_USER + 203) ' // wp = hwnd, lp = fn
%MCIWNDM_NOTIFYERROR = (%WM_USER + 205) ' // wp = hwnd, lp = error

'// special seek values for START and END
%MCIWND_START = -1
%MCIWND_END   = -2

'#ifndef MCI_PLAY
'    /* MCI command message identifiers */
'#ifndef _WIN32
'    // win32 apps send MCIWNDM_OPEN
'    #define MCI_OPEN                        0x0803
'#endif
'    #define MCI_CLOSE                       0x0804
'    #define MCI_PLAY                        0x0806
'    #define MCI_SEEK                        0x0807
'    #define MCI_STOP                        0x0808
'    #define MCI_PAUSE                       0x0809
'    #define MCI_STEP                        0x080E
'    #define MCI_RECORD                      0x080F
'    #define MCI_SAVE                        0x0813
'    #define MCI_CUT                         0x0851
'    #define MCI_COPY                        0x0852
'    #define MCI_PASTE                       0x0853
'    #define MCI_RESUME                      0x0855
'    #define MCI_DELETE                      0x0856
'#endif

%MCI_CLOSE                       = &H0804???
%MCI_PLAY                        = &H0806???
%MCI_SEEK                        = &H0807???
%MCI_STOP                        = &H0808???
%MCI_PAUSE                       = &H0809???
%MCI_STEP                        = &H080E???
%MCI_RECORD                      = &H080F???
%MCI_SAVE                        = &H0813???
%MCI_CUT                         = &H0851???
%MCI_COPY                        = &H0852???
%MCI_PASTE                       = &H0853???
%MCI_RESUME                      = &H0855???
%MCI_DELETE                      = &H0856???

' /* return values for 'status mode' command */
%MCI_MODE_NOT_READY     = 524
%MCI_MODE_STOP          = 525
%MCI_MODE_PLAY          = 526
%MCI_MODE_RECORD        = 527
%MCI_MODE_SEEK          = 528
%MCI_MODE_PAUSE         = 529
%MCI_MODE_OPEN          = 530

'// can macros

'#define MCIWndCanPlay(hwnd)         (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_PLAY,0,0)

FUNCTION MCIWndCanPlay (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_PLAY, 0, 0)
END FUNCTION

'#define MCIWndCanRecord(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_RECORD,0,0)

FUNCTION MCIWndCanRecord (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_RECORD, 0, 0)
END FUNCTION

'#define MCIWndCanSave(hwnd)         (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_SAVE,0,0)

FUNCTION MCIWndCanSave (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_SAVE, 0, 0)
END FUNCTION

'#define MCIWndCanWindow(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_WINDOW,0,0)

FUNCTION MCIWndCanWindow (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_WINDOW, 0, 0)
END FUNCTION

'#define MCIWndCanEject(hwnd)        (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_EJECT,0,0)

FUNCTION MCIWndCanEject (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_EJECT, 0, 0)
END FUNCTION

'#define MCIWndCanConfig(hwnd)       (BOOL)MCIWndSM(hwnd,MCIWNDM_CAN_CONFIG,0,0)

FUNCTION MCIWndCanConfig (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CAN_CONFIG, 0, 0)
END FUNCTION

'#define MCIWndPaletteKick(hwnd)     (BOOL)MCIWndSM(hwnd,MCIWNDM_PALETTEKICK,0,0)

FUNCTION MCIWndPaletteKick (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PALETTEKICK, 0, 0)
END FUNCTION

'#define MCIWndSave(hwnd, szFile)    (LONG)MCIWndSM(hwnd, MCI_SAVE, 0, (LPARAM)(LPVOID)(szFile))

FUNCTION MCIWndSave (BYVAL hwnd AS DWORD, BYREF szFile AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_SAVE, 0, BYVAL VARPTR(szFile))
END FUNCTION

'#define MCIWndSaveDialog(hwnd)      MCIWndSave(hwnd, -1)

FUNCTION MCIWndSaveDialog (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_SAVE, 0, -1)
END FUNCTION

'// if you dont give a device it will use the current device....
'#define MCIWndNew(hwnd, lp)         (LONG)MCIWndSM(hwnd, MCIWNDM_NEW, 0, (LPARAM)(LPVOID)(lp))

FUNCTION MCIWndNew (BYVAL hwnd AS DWORD, BYVAL lp AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_NEW, 0, lp)
END FUNCTION

'#define MCIWndRecord(hwnd)          (LONG)MCIWndSM(hwnd, MCI_RECORD, 0, 0)

FUNCTION MCIWndRecord (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_RECORD, 0, 0)
END FUNCTION

'#define MCIWndOpen(hwnd, sz, f)     (LONG)MCIWndSM(hwnd, MCIWNDM_OPEN, (WPARAM)(UINT)(f),(LPARAM)(LPVOID)(sz))

FUNCTION MCIWndOpen (BYVAL hwnd AS DWORD, BYREF szFile AS ASCIIZ, BYVAL wFlags AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_OPEN, BYVAL VARPTR(szFile), wFlags)
END FUNCTION

'#define MCIWndOpenDialog(hwnd)      MCIWndOpen(hwnd, -1, 0)

FUNCTION MCIWndOpenDialog (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_OPEN, -1, 0)
END FUNCTION

'#define MCIWndClose(hwnd)           (LONG)MCIWndSM(hwnd, MCI_CLOSE, 0, 0)

FUNCTION MCIWndClose (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_CLOSE, 0, 0)
END FUNCTION

'#define MCIWndPlay(hwnd)            (LONG)MCIWndSM(hwnd, MCI_PLAY, 0, 0)

FUNCTION MCIWndPlay (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_PLAY, 0, 0)
END FUNCTION

'#define MCIWndStop(hwnd)            (LONG)MCIWndSM(hwnd, MCI_STOP, 0, 0)

FUNCTION MCIWndStop (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_STOP, 0, 0)
END FUNCTION

'#define MCIWndPause(hwnd)           (LONG)MCIWndSM(hwnd, MCI_PAUSE, 0, 0)

FUNCTION MCIWndPause (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_PAUSE, 0, 0)
END FUNCTION

'#define MCIWndResume(hwnd)          (LONG)MCIWndSM(hwnd, MCI_RESUME, 0, 0)

FUNCTION MCIWndResume (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_RESUME, 0, 0)
END FUNCTION

'#define MCIWndSeek(hwnd, lPos)      (LONG)MCIWndSM(hwnd, MCI_SEEK, 0, (LPARAM)(LONG)(lPos))

FUNCTION MCIWndSeek (BYVAL hwnd AS DWORD, BYVAL lPos AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_SEEK, 0, lPos)
END FUNCTION

'#define MCIWndEject(hwnd)           (LONG)MCIWndSM(hwnd, MCIWNDM_EJECT, 0, 0)

FUNCTION MCIWndEject (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_EJECT, 0, 0)
END FUNCTION

'#define MCIWndHome(hwnd)            MCIWndSeek(hwnd, MCIWND_START)

FUNCTION MCIWndHome (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_SEEK, 0, %MCIWND_START)
END FUNCTION

'#define MCIWndEnd(hwnd)             MCIWndSeek(hwnd, MCIWND_END)

FUNCTION MCIWndEnd (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_SEEK, 0, %MCIWND_END)
END FUNCTION

'#define MCIWndGetSource(hwnd, prc)  (LONG)MCIWndSM(hwnd, MCIWNDM_GET_SOURCE, 0, (LPARAM)(LPRECT)(prc))

FUNCTION MCIWndGetSource (BYVAL hwnd AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GET_SOURCE, 0, BYVAL VARPTR(prc))
END FUNCTION

'#define MCIWndPutSource(hwnd, prc)  (LONG)MCIWndSM(hwnd, MCIWNDM_PUT_SOURCE, 0, (LPARAM)(LPRECT)(prc))

FUNCTION MCIWndPutSource (BYVAL hwnd AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PUT_SOURCE, 0, BYVAL VARPTR(prc))
END FUNCTION

'#define MCIWndGetDest(hwnd, prc)    (LONG)MCIWndSM(hwnd, MCIWNDM_GET_DEST, 0, (LPARAM)(LPRECT)(prc))

FUNCTION MCIWndGetDest (BYVAL hwnd AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GET_DEST, 0, BYVAL VARPTR(prc))
END FUNCTION

'#define MCIWndPutDest(hwnd, prc)    (LONG)MCIWndSM(hwnd, MCIWNDM_PUT_DEST, 0, (LPARAM)(LPRECT)(prc))

FUNCTION MCIWndPutDest (BYVAL hwnd AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PUT_DEST, 0, BYVAL VARPTR(prc))
END FUNCTION

'#define MCIWndPlayReverse(hwnd)     (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYREVERSE, 0, 0)

FUNCTION MCIWndPlayReverse (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PLAYREVERSE, 0, 0)
END FUNCTION

'#define MCIWndPlayFrom(hwnd, lPos)  (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYFROM, 0, (LPARAM)(LONG)(lPos))

FUNCTION MCIWndPlayFrom (BYVAL hwnd AS DWORD, BYVAL lPos AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PLAYFROM, 0, lPos)
END FUNCTION

'#define MCIWndPlayTo(hwnd, lPos)    (LONG)MCIWndSM(hwnd, MCIWNDM_PLAYTO,   0, (LPARAM)(LONG)(lPos))

FUNCTION MCIWndPlayTo (BYVAL hwnd AS DWORD, BYVAL lPos AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_PLAYTO, 0, lPos)
END FUNCTION

'#define MCIWndPlayFromTo(hwnd, lStart, lEnd) (MCIWndSeek(hwnd, lStart), MCIWndPlayTo(hwnd, lEnd))

FUNCTION MCIWndPlayFromTo (BYVAL hwnd AS DWORD, BYVAL lStart AS LONG, BYVAL lEnd AS LONG) AS LONG
   LOCAL hr AS LONG
   hr = MCIWndSeek(hwnd, lStart)
   IF hr = 0 THEN
      hr = MCIWndPlayTo(hwnd, lEnd)
   END IF
   FUNCTION = hr
END FUNCTION

'#define MCIWndGetDeviceID(hwnd)     (UINT)MCIWndSM(hwnd, MCIWNDM_GETDEVICEID, 0, 0)

FUNCTION MCIWndGetDeviceID (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETDEVICEID, 0, 0)
END FUNCTION

'#define MCIWndGetAlias(hwnd)        (UINT)MCIWndSM(hwnd, MCIWNDM_GETALIAS, 0, 0)

FUNCTION MCIWndGetAlias (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETALIAS, 0, 0)
END FUNCTION

'#define MCIWndGetMode(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETMODE, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))

FUNCTION MCIWndGetMode (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETMODE, ln, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndGetPosition(hwnd)     (LONG)MCIWndSM(hwnd, MCIWNDM_GETPOSITION, 0, 0)

FUNCTION MCIWndGetPosition (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETPOSITION, 0, 0)
END FUNCTION

'#define MCIWndGetPositionString(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETPOSITION, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))

FUNCTION MCIWndGetPositionString (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETPOSITION, ln, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndGetStart(hwnd)        (LONG)MCIWndSM(hwnd, MCIWNDM_GETSTART, 0, 0)

FUNCTION MCIWndGetStart (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETSTART, 0, 0)
END FUNCTION

'#define MCIWndGetLength(hwnd)       (LONG)MCIWndSM(hwnd, MCIWNDM_GETLENGTH, 0, 0)

FUNCTION MCIWndGetLength (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETLENGTH, 0, 0)
END FUNCTION

'#define MCIWndGetEnd(hwnd)          (LONG)MCIWndSM(hwnd, MCIWNDM_GETEND, 0, 0)

FUNCTION MCIWndGetEnd (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETEND, 0, 0)
END FUNCTION

'#define MCIWndStep(hwnd, n)         (LONG)MCIWndSM(hwnd, MCI_STEP, 0,(LPARAM)(long)(n))

FUNCTION MCIWndStep (BYVAL hwnd AS DWORD, BYVAL n AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %MCI_STEP, 0, n)
END FUNCTION

'#define MCIWndDestroy(hwnd)         (VOID)MCIWndSM(hwnd, WM_CLOSE, 0, 0)

SUB MCIWndDestroy (BYVAL hwnd AS DWORD)
   SendMessage hwnd, %WM_CLOSE, 0, 0
END SUB

'#define MCIWndSetZoom(hwnd,iZoom)   (VOID)MCIWndSM(hwnd, MCIWNDM_SETZOOM, 0, (LPARAM)(UINT)(iZoom))

SUB MCIWndSetZoom (BYVAL hwnd AS DWORD, BYVAL iZoom AS INTEGER)
   SendMessage hwnd, %MCIWNDM_SETZOOM, 0, iZoom
END SUB

'#define MCIWndGetZoom(hwnd)         (UINT)MCIWndSM(hwnd, MCIWNDM_GETZOOM, 0, 0)

FUNCTION MCIWndGetZoom (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETZOOM, 0, 0)
END FUNCTION

'#define MCIWndSetVolume(hwnd,iVol)  (LONG)MCIWndSM(hwnd, MCIWNDM_SETVOLUME, 0, (LPARAM)(UINT)(iVol))

FUNCTION MCIWndSetVolume (BYVAL hwnd AS DWORD, BYVAL iVol AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETVOLUME, 0, iVol)
END FUNCTION

'#define MCIWndGetVolume(hwnd)       (LONG)MCIWndSM(hwnd, MCIWNDM_GETVOLUME, 0, 0)

FUNCTION MCIWndGetVolume (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETVOLUME, 0, 0)
END FUNCTION

'#define MCIWndSetSpeed(hwnd,iSpeed) (LONG)MCIWndSM(hwnd, MCIWNDM_SETSPEED, 0, (LPARAM)(UINT)(iSpeed))

FUNCTION MCIWndSetSpeed (BYVAL hwnd AS DWORD, BYVAL iSpeed AS INTEGER) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETSPEED, 0, iSpeed)
END FUNCTION

'#define MCIWndGetSpeed(hwnd)        (LONG)MCIWndSM(hwnd, MCIWNDM_GETSPEED, 0, 0)

FUNCTION MCIWndGetSpeed (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETSPEED, 0, 0)
END FUNCTION

'#define MCIWndSetTimeFormat(hwnd, lp) (LONG)MCIWndSM(hwnd, MCIWNDM_SETTIMEFORMAT, 0, (LPARAM)(LPTSTR)(lp))

FUNCTION MCIWndSetTimeFormat (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETTIMEFORMAT, 0, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndGetTimeFormat(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETTIMEFORMAT, (WPARAM)(UINT)(len), (LPARAM)(LPTSTR)(lp))

FUNCTION MCIWndGetTimeFormat (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETTIMEFORMAT, ln, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndValidateMedia(hwnd)   (VOID)MCIWndSM(hwnd, MCIWNDM_VALIDATEMEDIA, 0, 0)

SUB MCIWndValidateMedia (BYVAL hwnd AS DWORD)
   SendMessage hwnd, %MCIWNDM_VALIDATEMEDIA, 0, 0
END SUB

'#define MCIWndSetRepeat(hwnd,f)     (void)MCIWndSM(hwnd, MCIWNDM_SETREPEAT, 0, (LPARAM)(BOOL)(f))

SUB MCIWndSetRepeat (BYVAL hwnd AS DWORD, BYVAL f AS WORD)
   SendMessage hwnd, %MCIWNDM_SETREPEAT, 0, f
END SUB

'#define MCIWndGetRepeat(hwnd)       (BOOL)MCIWndSM(hwnd, MCIWNDM_GETREPEAT, 0, 0)

SUB MCIWndGetRepeat (BYVAL hwnd AS DWORD)
   SendMessage hwnd, %MCIWNDM_GETREPEAT, 0, 0
END SUB

'#define MCIWndUseFrames(hwnd)       MCIWndSetTimeFormat(hwnd, TEXT("frames"))

FUNCTION MCIWndUseFrames (BYVAL hwnd AS DWORD) AS LONG
   LOCAL sz AS ASCIIZ * 7
   sz = "frames"
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETTIMEFORMAT, 0, BYVAL VARPTR(sz))
END FUNCTION

'#define MCIWndUseTime(hwnd)         MCIWndSetTimeFormat(hwnd, TEXT("ms"))

FUNCTION MCIWndUseTime (BYVAL hwnd AS DWORD) AS LONG
   LOCAL sz AS ASCIIZ * 3
   sz = "ms"
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETTIMEFORMAT, 0, BYVAL VARPTR(sz))
END FUNCTION

'#define MCIWndSetActiveTimer(hwnd, active)            \
'   (VOID)MCIWndSM(hwnd, MCIWNDM_SETACTIVETIMER,         \
'   (WPARAM)(UINT)(active), 0L)

FUNCTION MCIWndSetActiveTimer (BYVAL hwnd AS DWORD, BYVAL active AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETTIMEFORMAT, active, 0)
END FUNCTION

'#define MCIWndSetInactiveTimer(hwnd, inactive)            \
'   (VOID)MCIWndSM(hwnd, MCIWNDM_SETINACTIVETIMER,      \
'   (WPARAM)(UINT)(inactive), 0L)

FUNCTION MCIWndSetInactiveTimer (BYVAL hwnd AS DWORD, BYVAL inactive AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETINACTIVETIMER, inactive, 0)
END FUNCTION

'#define MCIWndSetTimers(hwnd, active, inactive)                  \
'       (VOID)MCIWndSM(hwnd, MCIWNDM_SETTIMERS,(WPARAM)(UINT)(active), \
'       (LPARAM)(UINT)(inactive))

FUNCTION MCIWndSetTimers (BYVAL hwnd AS DWORD, BYVAL active AS DWORD, BYVAL inactive AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETTIMERS, active, inactive)
END FUNCTION

'#define MCIWndGetActiveTimer(hwnd)               \
'   (UINT)MCIWndSM(hwnd, MCIWNDM_GETACTIVETIMER,   0, 0L);

FUNCTION MCIWndGetActiveTimer (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETACTIVETIMER, 0, 0)
END FUNCTION

'#define MCIWndGetInactiveTimer(hwnd)               \
'   (UINT)MCIWndSM(hwnd, MCIWNDM_GETINACTIVETIMER, 0, 0L);

FUNCTION MCIWndGetInactiveTimer (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETINACTIVETIMER, 0, 0)
END FUNCTION

'#define MCIWndRealize(hwnd, fBkgnd) (LONG)MCIWndSM(hwnd, MCIWNDM_REALIZE,(WPARAM)(BOOL)(fBkgnd),0)

FUNCTION MCIWndRealize (BYVAL hwnd AS DWORD, BYVAL fBkgnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_REALIZE, fBkgnd, 0)
END FUNCTION

'#define MCIWndSendString(hwnd, sz)  (LONG)MCIWndSM(hwnd, MCIWNDM_SENDSTRING, 0, (LPARAM)(LPTSTR)(sz))

FUNCTION MCIWndSendString (BYVAL hwnd AS DWORD, BYREF sz AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SENDSTRING, 0, BYVAL VARPTR(sz))
END FUNCTION

'#define MCIWndReturnString(hwnd, lp, len)  (LONG)MCIWndSM(hwnd, MCIWNDM_RETURNSTRING, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

FUNCTION MCIWndReturnString (BYVAL hwnd AS DWORD, BYREF sz AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_RETURNSTRING, ln, BYVAL VARPTR(sz))
END FUNCTION

'#define MCIWndGetError(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETERROR, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

FUNCTION MCIWndGetError (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETERROR, ln, BYVAL VARPTR(lp))
END FUNCTION

'//#define MCIWndActivate(hwnd, f)     (void)MCIWndSM(hwnd, WM_ACTIVATE, (WPARAM)(BOOL)(f), 0)

'FUNCTION MCIWndActivate (BYVAL hwnd AS DWORD, BYVAL fAS DWORD) AS LONG
'   FUNCTION = SendMessage(hwnd, %WM_ACTIVATE, f, 0)
'END FUNCTION

'#define MCIWndGetPalette(hwnd)      (HPALETTE)MCIWndSM(hwnd, MCIWNDM_GETPALETTE, 0, 0)

FUNCTION MCIWndGetPalette (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETPALETTE, 0, 0)
END FUNCTION

'#define MCIWndSetPalette(hwnd, hpal) (LONG)MCIWndSM(hwnd, MCIWNDM_SETPALETTE, (WPARAM)(HPALETTE)(hpal), 0)

FUNCTION MCIWndSetPalette (BYVAL hwnd AS DWORD, BYVAL hPal AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETPALETTE, hPal, 0)
END FUNCTION

'#define MCIWndGetFileName(hwnd, lp, len) (LONG)MCIWndSM(hwnd, MCIWNDM_GETFILENAME, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

FUNCTION MCIWndGetFileName (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETPALETTE, ln, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndGetDevice(hwnd, lp, len)   (LONG)MCIWndSM(hwnd, MCIWNDM_GETDEVICE, (WPARAM)(UINT)(len), (LPARAM)(LPVOID)(lp))

FUNCTION MCIWndGetDevice (BYVAL hwnd AS DWORD, BYREF lp AS ASCIIZ, BYVAL ln AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETDEVICE, ln, BYVAL VARPTR(lp))
END FUNCTION

'#define MCIWndGetStyles(hwnd) (UINT)MCIWndSM(hwnd, MCIWNDM_GETSTYLES, 0, 0L)

FUNCTION MCIWndGetStyles (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_GETSTYLES, 0, 0)
END FUNCTION

'#define MCIWndChangeStyles(hwnd, mask, value) (LONG)MCIWndSM(hwnd, MCIWNDM_CHANGESTYLES, (WPARAM)(UINT)(mask), (LPARAM)(LONG)(value))

FUNCTION MCIWndChangeStyles (BYVAL hwnd AS DWORD, BYVAL mask AS DWORD, BYVAL value AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_CHANGESTYLES, mask, value)
END FUNCTION

'#define MCIWndOpenInterface(hwnd, pUnk)  (LONG)MCIWndSM(hwnd, MCIWNDM_OPENINTERFACE, 0, (LPARAM)(LPUNKNOWN)(pUnk))

FUNCTION MCIWndOpenInterface (BYVAL hwnd AS DWORD, BYVAL pUnk AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_OPENINTERFACE, 0, pUnk)
END FUNCTION

'#define MCIWndSetOwner(hwnd, hwndP)  (LONG)MCIWndSM(hwnd, MCIWNDM_SETOWNER, (WPARAM)(hwndP), 0)

FUNCTION MCIWndSetOwner (BYVAL hwnd AS DWORD, BYVAL hwndP AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %MCIWNDM_SETOWNER, hwndP, 0)
END FUNCTION

#ENDIF  ' /* NOMCIWND */  ----------------------------------------------------------------

'/****************************************************************************
' *
' *  VIDEO - Video Capture Driver Interface
' *
' ****************************************************************************/

'#if !defined(NOAVICAP) || !defined(NOVIDEO)

#IF NOT %DEF(%NOAVICAP) ' ----------------------------------------------------------------
#IF NOT %DEF(%NOVIDEO)  ' ----------------------------------------------------------------

'#ifndef _RCINVOKED


'/* video data types */
'DECLARE_HANDLE(HVIDEO);                 // generic handle
'typedef HVIDEO FAR * LPHVIDEO;
'#endif                                  // ifndef RCINVOKED

'/****************************************************************************

'                        version api

'****************************************************************************/

'DWORD FAR PASCAL VideoForWindowsVersion(void);

'/****************************************************************************

'                            Error Return Values

'****************************************************************************/
%DV_ERR_OK               = (0)                  ' /* No error */
%DV_ERR_BASE             = (1)                  ' /* Error Base */
%DV_ERR_NONSPECIFIC      = (%DV_ERR_BASE)
%DV_ERR_BADFORMAT        = (%DV_ERR_BASE + 1)   ' /* unsupported video format */
%DV_ERR_STILLPLAYING     = (%DV_ERR_BASE + 2)   ' /* still something playing */
%DV_ERR_UNPREPARED       = (%DV_ERR_BASE + 3)   ' /* header not prepared */
%DV_ERR_SYNC             = (%DV_ERR_BASE + 4)   ' /* device is synchronous */
%DV_ERR_TOOMANYCHANNELS  = (%DV_ERR_BASE + 5)   ' /* number of channels exceeded */
%DV_ERR_NOTDETECTED      = (%DV_ERR_BASE + 6)   ' /* HW not detected */
%DV_ERR_BADINSTALL       = (%DV_ERR_BASE + 7)   ' /* Can not get Profile */
%DV_ERR_CREATEPALETTE    = (%DV_ERR_BASE + 8)
%DV_ERR_SIZEFIELD        = (%DV_ERR_BASE + 9)
%DV_ERR_PARAM1           = (%DV_ERR_BASE + 10)
%DV_ERR_PARAM2           = (%DV_ERR_BASE + 11)
%DV_ERR_CONFIG1          = (%DV_ERR_BASE + 12)
%DV_ERR_CONFIG2          = (%DV_ERR_BASE + 13)
%DV_ERR_FLAGS            = (%DV_ERR_BASE + 14)
%DV_ERR_13               = (%DV_ERR_BASE + 15)

%DV_ERR_NOTSUPPORTED     = (%DV_ERR_BASE + 16)  ' /* function not suported */
%DV_ERR_NOMEM            = (%DV_ERR_BASE + 17)  ' /* out of memory */
%DV_ERR_ALLOCATED        = (%DV_ERR_BASE + 18)  ' /* device is allocated */
%DV_ERR_BADDEVICEID      = (%DV_ERR_BASE + 19)
%DV_ERR_INVALHANDLE      = (%DV_ERR_BASE + 20)
%DV_ERR_BADERRNUM        = (%DV_ERR_BASE + 21)
%DV_ERR_NO_BUFFERS       = (%DV_ERR_BASE + 22)  ' /* out of buffers */

%DV_ERR_MEM_CONFLICT     = (%DV_ERR_BASE + 23)  ' /* Mem conflict detected */
%DV_ERR_IO_CONFLICT      = (%DV_ERR_BASE + 24)  ' /* I/O conflict detected */
%DV_ERR_DMA_CONFLICT     = (%DV_ERR_BASE + 25)  ' /* DMA conflict detected */
%DV_ERR_INT_CONFLICT     = (%DV_ERR_BASE + 26)  ' /* Interrupt conflict detected */
%DV_ERR_PROTECT_ONLY     = (%DV_ERR_BASE + 27)  ' /* Can not run in standard mode */
%DV_ERR_LASTERROR        = (%DV_ERR_BASE + 27)

' //%DV_IDS_PROFILING       = (%DV_ERR_BASE + 900)
' //%DV_IDS_LISTBOX         = (%DV_ERR_BASE + 901)

%DV_ERR_USER_MSG         = (%DV_ERR_BASE + 1000) ' /* Hardware specific errors */

'/****************************************************************************

'                         Callback Messages

'Note that the values for all installable driver callback messages are
'identical, (ie. MM_DRVM_DATA has the same value for capture drivers,
'installable video codecs, and the audio compression manager).
'****************************************************************************/
'#ifndef _RCINVOKED

%MM_DRVM_OPEN       = &H3D0
%MM_DRVM_CLOSE      = &H3D1
%MM_DRVM_DATA       = &H3D2
%MM_DRVM_ERROR      = &H3D3

'#endif

%DV_VM_OPEN         = %MM_DRVM_OPEN        ' // Obsolete messages
%DV_VM_CLOSE        = %MM_DRVM_CLOSE
%DV_VM_DATA         = %MM_DRVM_DATA
%DV_VM_ERROR        = %MM_DRVM_ERROR

'/****************************************************************************

'                         Structures

'****************************************************************************/
'/* video data block header */
' // Size = 40 bytes
TYPE VIDEOHDR DWORD
   lpData         AS BYTE  PTR   ' LPBYTE /* pointer to locked data buffer */
   dwBufferLength AS DWORD       ' DWORD /* Length of data buffer */
   dwBytesUsed    AS DWORD       ' DWORD /* Bytes actually used */
   dwTimeCaptured AS DWORD       ' DWORD /* Milliseconds from start of stream */
   dwUser         AS DWORD       ' DWORD_PTR /* for client's use */
   dwFlags        AS DWORD       ' DWORD /* assorted flags (see defines) */
   dwReserved(3)  AS DWORD       ' DWORD_PTR[4] /* reserved for driver */
END TYPE

'/* dwFlags field of VIDEOHDR */
%VHDR_DONE       = &H00000001???        ' /* Done bit */
%VHDR_PREPARED   = &H00000002???        ' /* Set if this header has been prepared */
%VHDR_INQUEUE    = &H00000004???        ' /* Reserved for driver */
%VHDR_KEYFRAME   = &H00000008???        ' /* Key Frame */
%VHDR_VALID      = &H0000000F???        ' /* valid flags */     ' /* ;Internal */

'/* Channel capabilities structure */
' // Size = 36 bytes
TYPE CHANNEL_CAPS DWORD
   dwFlags            AS DWORD   ' DWORD /* Capability flags*/
   dwSrcRectXMod      AS DWORD   ' DWORD /* Granularity of src rect in x */
   dwSrcRectYMod      AS DWORD   ' DWORD /* Granularity of src rect in y */
   dwSrcRectWidthMod  AS DWORD   ' DWORD /* Granularity of src rect width */
   dwSrcRectHeightMod AS DWORD   ' DWORD /* Granularity of src rect height */
   dwDstRectXMod      AS DWORD   ' DWORD /* Granularity of dst rect in x */
   dwDstRectYMod      AS DWORD   ' DWORD /* Granularity of dst rect in y */
   dwDstRectWidthMod  AS DWORD   ' DWORD /* Granularity of dst rect width */
   dwDstRectHeightMod AS DWORD   ' DWORD /* Granularity of dst rect height */
END TYPE

'/* dwFlags of CHANNEL_CAPS */
%VCAPS_OVERLAY       = &H00000001???    ' /* overlay channel */
%VCAPS_SRC_CAN_CLIP  = &H00000002???    ' /* src rect can clip */
%VCAPS_DST_CAN_CLIP  = &H00000004???    ' /* dst rect can clip */
%VCAPS_CAN_SCALE     = &H00000008???    ' /* allows src != dst */


'/****************************************************************************

'         API Flags

'****************************************************************************/

'// Types of channels to open with the videoOpen function
%VIDEO_EXTERNALIN             = &H0001???
%VIDEO_EXTERNALOUT            = &H0002???
%VIDEO_IN                     = &H0004???
%VIDEO_OUT                    = &H0008???

'// Is a driver dialog available for this channel?
%VIDEO_DLG_QUERY              = &H0010???

'// videoConfigure (both GET and SET)
%VIDEO_CONFIGURE_QUERY        = &H8000???

'// videoConfigure (SET only)
%VIDEO_CONFIGURE_SET          = &H1000???

'// videoConfigure (GET only)
%VIDEO_CONFIGURE_GET          = &H2000???
%VIDEO_CONFIGURE_QUERYSIZE    = &H0001???

%VIDEO_CONFIGURE_CURRENT      = &H0010???
%VIDEO_CONFIGURE_NOMINAL      = &H0020???
%VIDEO_CONFIGURE_MIN          = &H0040???
%VIDEO_CONFIGURE_MAX          = &H0080???

'/****************************************************************************

'         CONFIGURE MESSAGES

'****************************************************************************/
%DVM_USER              = &H4000???

%DVM_CONFIGURE_START   = &H1000???
%DVM_CONFIGURE_END     = &H1FFF???

%DVM_PALETTE           = (%DVM_CONFIGURE_START + 1)
%DVM_FORMAT            = (%DVM_CONFIGURE_START + 2)
%DVM_PALETTERGB555     = (%DVM_CONFIGURE_START + 3)
%DVM_SRC_RECT          = (%DVM_CONFIGURE_START + 4)
%DVM_DST_RECT          = (%DVM_CONFIGURE_START + 5)

'#endif  /* ifndef _RCINVOKED */

'#endif  /* NOVIDEO */

#ENDIF ' /* NOVIDEO */  ' ----------------------------------------------------------------
#ENDIF ' /* NOAVICAP */ ' ----------------------------------------------------------------

'/****************************************************************************
' *
' *  AVICAP - Window class for AVI capture
' *
' ***************************************************************************/

'#ifndef NOAVICAP
'#ifdef __cplusplus
'/* SendMessage in C++*/
'#define AVICapSM(hwnd,m,w,l) ( (::IsWindow(hwnd)) ? ::SendMessage(hwnd,m,w,l) : 0)
'#else
'/* SendMessage in C */
'#define AVICapSM(hwnd,m,w,l) ( (IsWindow(hwnd)) ?   SendMessage(hwnd,m,w,l) : 0)
'#endif  /* __cplusplus */

'#ifndef RC_INVOKED

'// ------------------------------------------------------------------
'//  Window Messages  WM_CAP... which can be sent to an AVICAP window
'// ------------------------------------------------------------------

'// UNICODE
'//
'// The Win32 version of AVICAP on NT supports UNICODE applications:
'// for each API or message that takes a char or string parameter, there are
'// two versions, ApiNameA and ApiNameW. The default name ApiName is #defined
'// to one or other depending on whether UNICODE is defined. Apps can call
'// the A and W apis directly, and mix them.
'//
'// The 32-bit AVICAP on NT uses unicode exclusively internally.
'// ApiNameA() will be implemented as a call to ApiNameW() together with
'// translation of strings.

'// Defines start of the message range
%WM_CAP_START                    = %WM_USER

'// start of unicode messages
%WM_CAP_UNICODE_START            = %WM_USER + 100

%WM_CAP_GET_CAPSTREAMPTR         = %WM_CAP_START + 1

'#define WM_CAP_SET_CALLBACK_ERRORW     (WM_CAP_UNICODE_START+  2)
'#define WM_CAP_SET_CALLBACK_STATUSW    (WM_CAP_UNICODE_START+  3)
'#define WM_CAP_SET_CALLBACK_ERRORA     (WM_CAP_START+  2)
'#define WM_CAP_SET_CALLBACK_STATUSA    (WM_CAP_START+  3)
'#ifdef UNICODE
'#define WM_CAP_SET_CALLBACK_ERROR       WM_CAP_SET_CALLBACK_ERRORW
'#define WM_CAP_SET_CALLBACK_STATUS      WM_CAP_SET_CALLBACK_STATUSW
'#else
'#define WM_CAP_SET_CALLBACK_ERROR       WM_CAP_SET_CALLBACK_ERRORA
'#define WM_CAP_SET_CALLBACK_STATUS      WM_CAP_SET_CALLBACK_STATUSA
'#endif

%WM_CAP_SET_CALLBACK_ERRORW      = %WM_CAP_UNICODE_START + 2
%WM_CAP_SET_CALLBACK_STATUSW     = %WM_CAP_UNICODE_START + 3
%WM_CAP_SET_CALLBACK_ERRORA      = %WM_CAP_START + 2
%WM_CAP_SET_CALLBACK_STATUSA     = %WM_CAP_START + 3
%WM_CAP_SET_CALLBACK_ERROR       = %WM_CAP_START + 2
%WM_CAP_SET_CALLBACK_STATUS      = %WM_CAP_START + 3

%WM_CAP_SET_CALLBACK_YIELD       = %WM_CAP_START + 4
%WM_CAP_SET_CALLBACK_FRAME       = %WM_CAP_START + 5
%WM_CAP_SET_CALLBACK_VIDEOSTREAM = %WM_CAP_START + 6
%WM_CAP_SET_CALLBACK_WAVESTREAM  = %WM_CAP_START + 7
%WM_CAP_GET_USER_DATA            = %WM_CAP_START + 8
%WM_CAP_SET_USER_DATA            = %WM_CAP_START + 9

%WM_CAP_DRIVER_CONNECT           = %WM_CAP_START + 10
%WM_CAP_DRIVER_DISCONNECT        = %WM_CAP_START + 11

'#define WM_CAP_DRIVER_GET_NAMEA        (WM_CAP_START+  12)
'#define WM_CAP_DRIVER_GET_VERSIONA     (WM_CAP_START+  13)
'#define WM_CAP_DRIVER_GET_NAMEW        (WM_CAP_UNICODE_START+  12)
'#define WM_CAP_DRIVER_GET_VERSIONW     (WM_CAP_UNICODE_START+  13)
'#ifdef UNICODE
'#define WM_CAP_DRIVER_GET_NAME          WM_CAP_DRIVER_GET_NAMEW
'#define WM_CAP_DRIVER_GET_VERSION       WM_CAP_DRIVER_GET_VERSIONW
'#else
'#define WM_CAP_DRIVER_GET_NAME          WM_CAP_DRIVER_GET_NAMEA
'#define WM_CAP_DRIVER_GET_VERSION       WM_CAP_DRIVER_GET_VERSIONA
'#endif

%WM_CAP_DRIVER_GET_NAMEA         = %WM_CAP_START + 12
%WM_CAP_DRIVER_GET_VERSIONA      = %WM_CAP_START + 13
%WM_CAP_DRIVER_GET_NAMEW         = %WM_CAP_UNICODE_START + 12
%WM_CAP_DRIVER_GET_VERSIONW      = %WM_CAP_UNICODE_START + 13
%WM_CAP_DRIVER_GET_NAME          = %WM_CAP_DRIVER_GET_NAMEA
%WM_CAP_DRIVER_GET_VERSION       = %WM_CAP_DRIVER_GET_VERSIONA

%WM_CAP_DRIVER_GET_CAPS          = %WM_CAP_START + 14

'#define WM_CAP_FILE_SET_CAPTURE_FILEA  (WM_CAP_START+  20)
'#define WM_CAP_FILE_GET_CAPTURE_FILEA  (WM_CAP_START+  21)
'#define WM_CAP_FILE_SAVEASA            (WM_CAP_START+  23)
'#define WM_CAP_FILE_SAVEDIBA           (WM_CAP_START+  25)
'#define WM_CAP_FILE_SET_CAPTURE_FILEW  (WM_CAP_UNICODE_START+  20)
'#define WM_CAP_FILE_GET_CAPTURE_FILEW  (WM_CAP_UNICODE_START+  21)
'#define WM_CAP_FILE_SAVEASW            (WM_CAP_UNICODE_START+  23)
'#define WM_CAP_FILE_SAVEDIBW           (WM_CAP_UNICODE_START+  25)
'#ifdef UNICODE
'#define WM_CAP_FILE_SET_CAPTURE_FILE    WM_CAP_FILE_SET_CAPTURE_FILEW
'#define WM_CAP_FILE_GET_CAPTURE_FILE    WM_CAP_FILE_GET_CAPTURE_FILEW
'#define WM_CAP_FILE_SAVEAS              WM_CAP_FILE_SAVEASW
'#define WM_CAP_FILE_SAVEDIB             WM_CAP_FILE_SAVEDIBW
'#else
'#define WM_CAP_FILE_SET_CAPTURE_FILE    WM_CAP_FILE_SET_CAPTURE_FILEA
'#define WM_CAP_FILE_GET_CAPTURE_FILE    WM_CAP_FILE_GET_CAPTURE_FILEA
'#define WM_CAP_FILE_SAVEAS              WM_CAP_FILE_SAVEASA
'#define WM_CAP_FILE_SAVEDIB             WM_CAP_FILE_SAVEDIBA
'#endif

%WM_CAP_FILE_SET_CAPTURE_FILEA   = %WM_CAP_START + 20
%WM_CAP_FILE_GET_CAPTURE_FILEA   = %WM_CAP_START + 21
%WM_CAP_FILE_SAVEASA             = %WM_CAP_START + 23
%WM_CAP_FILE_SAVEDIBA            = %WM_CAP_START + 25
%WM_CAP_FILE_SET_CAPTURE_FILEW   = %WM_CAP_UNICODE_START + 20
%WM_CAP_FILE_GET_CAPTURE_FILEW   = %WM_CAP_UNICODE_START + 21
%WM_CAP_FILE_SAVEASW             = %WM_CAP_UNICODE_START + 23
%WM_CAP_FILE_SAVEDIBW            = %WM_CAP_UNICODE_START + 25
%WM_CAP_FILE_SET_CAPTURE_FILE    = %WM_CAP_FILE_SET_CAPTURE_FILEA
%WM_CAP_FILE_GET_CAPTURE_FILE    = %WM_CAP_FILE_GET_CAPTURE_FILEA
%WM_CAP_FILE_SAVEAS              = %WM_CAP_FILE_SAVEASA
%WM_CAP_FILE_SAVEDIB             = %WM_CAP_FILE_SAVEDIBA

'// out of order to save on ifdefs
%WM_CAP_FILE_ALLOCATE            = %WM_CAP_START + 22
%WM_CAP_FILE_SET_INFOCHUNK       = %WM_CAP_START + 24

%WM_CAP_EDIT_COPY                = %WM_CAP_START + 30

%WM_CAP_SET_AUDIOFORMAT          = %WM_CAP_START + 35
%WM_CAP_GET_AUDIOFORMAT          = %WM_CAP_START + 36

%WM_CAP_DLG_VIDEOFORMAT          = %WM_CAP_START + 41
%WM_CAP_DLG_VIDEOSOURCE          = %WM_CAP_START + 42
%WM_CAP_DLG_VIDEODISPLAY         = %WM_CAP_START + 43
%WM_CAP_GET_VIDEOFORMAT          = %WM_CAP_START + 44
%WM_CAP_SET_VIDEOFORMAT          = %WM_CAP_START + 45
%WM_CAP_DLG_VIDEOCOMPRESSION     = %WM_CAP_START + 46

%WM_CAP_SET_PREVIEW              = %WM_CAP_START + 50
%WM_CAP_SET_OVERLAY              = %WM_CAP_START + 51
%WM_CAP_SET_PREVIEWRATE          = %WM_CAP_START + 52
%WM_CAP_SET_SCALE                = %WM_CAP_START + 53
%WM_CAP_GET_STATUS               = %WM_CAP_START + 54
%WM_CAP_SET_SCROLL               = %WM_CAP_START + 55

%WM_CAP_GRAB_FRAME               = %WM_CAP_START + 60
%WM_CAP_GRAB_FRAME_NOSTOP        = %WM_CAP_START + 61

%WM_CAP_SEQUENCE                 = %WM_CAP_START + 62
%WM_CAP_SEQUENCE_NOFILE          = %WM_CAP_START + 63
%WM_CAP_SET_SEQUENCE_SETUP       = %WM_CAP_START + 64
%WM_CAP_GET_SEQUENCE_SETUP       = %WM_CAP_START + 65

'#define WM_CAP_SET_MCI_DEVICEA         (WM_CAP_START+  66)
'#define WM_CAP_GET_MCI_DEVICEA         (WM_CAP_START+  67)
'#define WM_CAP_SET_MCI_DEVICEW         (WM_CAP_UNICODE_START+  66)
'#define WM_CAP_GET_MCI_DEVICEW         (WM_CAP_UNICODE_START+  67)
'#ifdef UNICODE
'#define WM_CAP_SET_MCI_DEVICE           WM_CAP_SET_MCI_DEVICEW
'#define WM_CAP_GET_MCI_DEVICE           WM_CAP_GET_MCI_DEVICEW
'#else
'#define WM_CAP_SET_MCI_DEVICE           WM_CAP_SET_MCI_DEVICEA
'#define WM_CAP_GET_MCI_DEVICE           WM_CAP_GET_MCI_DEVICEA
'#endif

%WM_CAP_SET_MCI_DEVICEA          = %WM_CAP_START + 66
%WM_CAP_GET_MCI_DEVICEA          = %WM_CAP_START + 67
%WM_CAP_SET_MCI_DEVICEW          = %WM_CAP_UNICODE_START + 66
%WM_CAP_GET_MCI_DEVICEW          = %WM_CAP_UNICODE_START + 67
%WM_CAP_SET_MCI_DEVICE           = %WM_CAP_SET_MCI_DEVICEA
%WM_CAP_GET_MCI_DEVICE           = %WM_CAP_GET_MCI_DEVICEA

%WM_CAP_STOP                     = %WM_CAP_START + 68
%WM_CAP_ABORT                    = %WM_CAP_START + 69

%WM_CAP_SINGLE_FRAME_OPEN        = %WM_CAP_START + 70
%WM_CAP_SINGLE_FRAME_CLOSE       = %WM_CAP_START + 71
%WM_CAP_SINGLE_FRAME             = %WM_CAP_START + 72

'#define WM_CAP_PAL_OPENA               (WM_CAP_START+  80)
'#define WM_CAP_PAL_SAVEA               (WM_CAP_START+  81)
'#define WM_CAP_PAL_OPENW               (WM_CAP_UNICODE_START+  80)
'#define WM_CAP_PAL_SAVEW               (WM_CAP_UNICODE_START+  81)
'#ifdef UNICODE
'#define WM_CAP_PAL_OPEN                 WM_CAP_PAL_OPENW
'#define WM_CAP_PAL_SAVE                 WM_CAP_PAL_SAVEW
'#else
'#define WM_CAP_PAL_OPEN                 WM_CAP_PAL_OPENA
'#define WM_CAP_PAL_SAVE                 WM_CAP_PAL_SAVEA
'#endif

%WM_CAP_PAL_OPENA                = %WM_CAP_START + 80
%WM_CAP_PAL_SAVEA                = %WM_CAP_START + 81
%WM_CAP_PAL_OPENW                = %WM_CAP_UNICODE_START + 80
%WM_CAP_PAL_SAVEW                = %WM_CAP_UNICODE_START + 81
%WM_CAP_PAL_OPEN                 = %WM_CAP_PAL_OPENA
%WM_CAP_PAL_SAVE                 = %WM_CAP_PAL_SAVEA

%WM_CAP_PAL_PASTE                = %WM_CAP_START + 82
%WM_CAP_PAL_AUTOCREATE           = %WM_CAP_START + 83
%WM_CAP_PAL_MANUALCREATE         = %WM_CAP_START + 84

'// Following added post VFW 1.1
%WM_CAP_SET_CALLBACK_CAPCONTROL  = %WM_CAP_START + 85

'// Defines end of the message range
%WM_CAP_UNICODE_END              = %WM_CAP_PAL_SAVEW
%WM_CAP_END                      = %WM_CAP_UNICODE_END


'// ------------------------------------------------------------------
'//  Structures
'// ------------------------------------------------------------------

' // Size = 44 bytes
TYPE CAPDRIVERCAPS DWORD
   wDeviceIndex            AS DWORD   ' UINT // Driver index in system.ini
   fHasOverlay             AS LONG    ' BOOL // Can device overlay?
   fHasDlgVideoSource      AS LONG    ' BOOL // Has Video source dlg?
   fHasDlgVideoFormat      AS LONG    ' BOOL // Has Format dlg?
   fHasDlgVideoDisplay     AS LONG    ' BOOL // Has External out dlg?
   fCaptureInitialized     AS LONG    ' BOOL // Driver ready to capture?
   fDriverSuppliesPalettes AS LONG    ' BOOL // Can driver make palettes?
    ' // following always NULL on Win32.
   hVideoIn                AS DWORD   ' HANDLE // Driver In channel
   hVideoOut               AS DWORD   ' HANDLE // Driver Out channel
   hVideoExtIn             AS DWORD   ' HANDLE // Driver Ext In channel
   hVideoExtOut            AS DWORD   ' HANDLE // Driver Ext Out channel
END TYPE


' // Size = 76 bytes
TYPE CAPSTATUS DWORD
   uiImageWidth                AS DWORD   ' UINT // Width of the image
   uiImageHeight               AS DWORD   ' UINT // Height of the image
   fLiveWindow                 AS LONG    ' BOOL // Now Previewing video?
   fOverlayWindow              AS LONG    ' BOOL // Now Overlaying video?
   fScale                      AS LONG    ' BOOL // Scale image to client?
   ptScroll                    AS POINT   ' POINT // Scroll position
   fUsingDefaultPalette        AS LONG    ' BOOL // Using default driver palette?
   fAudioHardware              AS LONG    ' BOOL // Audio hardware present?
   fCapFileExists              AS LONG    ' BOOL // Does capture file exist?
   dwCurrentVideoFrame         AS DWORD   ' DWORD // # of video frames cap'td
   dwCurrentVideoFramesDropped AS DWORD   ' DWORD // # of video frames dropped
   dwCurrentWaveSamples        AS DWORD   ' DWORD // # of wave samples cap'td
   dwCurrentTimeElapsedMS      AS DWORD   ' DWORD // Elapsed capture duration
   hPalCurrent                 AS DWORD   ' HPALETTE // Current palette in use
   fCapturingNow               AS LONG    ' BOOL // Capture in progress?
   dwReturn                    AS DWORD   ' DWORD // Error value after any operation
   wNumVideoAllocated          AS DWORD   ' UINT // Actual number of video buffers
   wNumAudioAllocated          AS DWORD   ' UINT // Actual number of audio buffers
END TYPE

' // Size = 96 bytes
TYPE CAPTUREPARMS DWORD
   dwRequestMicroSecPerFrame AS DWORD   ' DWORD // Requested capture rate
   fMakeUserHitOKToCapture   AS LONG    ' BOOL // Show "Hit OK to cap" dlg?
   wPercentDropForError      AS DWORD   ' UINT // Give error msg if > (10%)
   fYield                    AS LONG    ' BOOL // Capture via background task?
   dwIndexSize               AS DWORD   ' DWORD // Max index size in frames (32K)
   wChunkGranularity         AS DWORD   ' UINT // Junk chunk granularity (2K)
   fUsingDOSMemory           AS LONG    ' BOOL // Use DOS buffers?
   wNumVideoRequested        AS DWORD   ' UINT // # video buffers, If 0, autocalc
   fCaptureAudio             AS LONG    ' BOOL // Capture audio?
   wNumAudioRequested        AS DWORD   ' UINT // # audio buffers, If 0, autocalc
   vKeyAbort                 AS DWORD   ' UINT // Virtual key causing abort
   fAbortLeftMouse           AS LONG    ' BOOL // Abort on left mouse?
   fAbortRightMouse          AS LONG    ' BOOL // Abort on right mouse?
   fLimitEnabled             AS LONG    ' BOOL // Use wTimeLimit?
   wTimeLimit                AS DWORD   ' UINT // Seconds to capture
   fMCIControl               AS LONG    ' BOOL // Use MCI video source?
   fStepMCIDevice            AS LONG    ' BOOL // Step MCI device?
   dwMCIStartTime            AS DWORD   ' DWORD // Time to start in MS
   dwMCIStopTime             AS DWORD   ' DWORD // Time to stop in MS
   fStepCaptureAt2x          AS LONG    ' BOOL // Perform spatial averaging 2x
   wStepCaptureAverageFrames AS DWORD   ' UINT // Temporal average n Frames
   dwAudioBufferSize         AS DWORD   ' DWORD // Size of audio bufs (0 = default)
   fDisableWriteCache        AS LONG    ' BOOL // Attempt to disable write cache
   AVStreamMaster            AS DWORD   ' UINT // Which stream controls length?
END TYPE

'// ------------------------------------------------------------------
'//  AVStreamMaster
'//  Since Audio and Video streams generally use non-synchronized capture
'//  clocks, this flag determines whether the audio stream is to be considered
'//  the master or controlling clock when writing the AVI file:
'//
'//  AVSTREAMMASTER_AUDIO  - Audio is master, video frame duration is forced
'//                          to match audio duration (VFW 1.0, 1.1 default)
'//  AVSTREAMMASTER_NONE   - No master, audio and video streams may be of
'//                          different lengths
'// ------------------------------------------------------------------
%AVSTREAMMASTER_AUDIO         = 0  ' /* Audio master (VFW 1.0, 1.1) */
%AVSTREAMMASTER_NONE          = 1  ' /* No master */

' // Size = 12 bytes
TYPE CAPINFOCHUNK DWORD
   fccInfoID AS DWORD   ' // Chunk ID, "ICOP" for copyright
   lpData    AS DWORD   ' // pointer to data
   cbData    AS LONG    ' // size of lpData
END TYPE

'// ------------------------------------------------------------------
'//  Message crackers for above
'// ------------------------------------------------------------------

'// message wrapper macros are defined for the default messages only. Apps
'// that wish to mix Ansi and UNICODE message sending will have to
'// reference the _A and _W messages directly

'#define capSetCallbackOnError(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_ERROR, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnError (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_ERROR, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnStatus(hwnd, fpProc)       ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_STATUS, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnStatus (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_STATUS, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnYield(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_YIELD, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnYield (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_YIELD, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnFrame(hwnd, fpProc)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_FRAME, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnFrame (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_FRAME, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnVideoStream(hwnd, fpProc)  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnVideoStream (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_VIDEOSTREAM, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnWaveStream(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_WAVESTREAM, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnWaveStream (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_WAVESTREAM, 0, fpProc)
END FUNCTION

'#define capSetCallbackOnCapControl(hwnd, fpProc)   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_CALLBACK_CAPCONTROL, 0, (LPARAM)(LPVOID)(fpProc)))

FUNCTION capSetCallbackOnCapControl (BYVAL hwnd AS DWORD, BYVAL fpProc AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_CALLBACK_CAPCONTROL, 0, fpProc)
END FUNCTION

'#define capSetUserData(hwnd, lUser)        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_USER_DATA, 0, (LPARAM)lUser))

FUNCTION capSetUserData (BYVAL hwnd AS DWORD, BYVAL lUser AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_USER_DATA, 0, lUser)
END FUNCTION

'#define capGetUserData(hwnd)               (AVICapSM(hwnd, WM_CAP_GET_USER_DATA, 0, 0))

FUNCTION capGetUserData (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_USER_DATA, 0, 0)
END FUNCTION

'#define capDriverConnect(hwnd, i)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_CONNECT, (WPARAM)(i), 0L))

FUNCTION capDriverConnect (BYVAL hwnd AS DWORD, BYVAL i AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DRIVER_CONNECT, i, 0)
END FUNCTION

'#define capDriverDisconnect(hwnd)                  ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_DISCONNECT, (WPARAM)0, 0L))

FUNCTION capDriverDisconnect (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DRIVER_DISCONNECT, 0, 0)
END FUNCTION

'#define capDriverGetName(hwnd, szName, wSize)      ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_NAME, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capDriverGetName (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DRIVER_GET_NAME, wSize, VARPTR(szName))
END FUNCTION

'#define capDriverGetVersion(hwnd, szVer, wSize)    ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_VERSION, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szVer)))

FUNCTION capDriverGetVersion (BYVAL hwnd AS DWORD, BYREF szVer AS ASCIIZ, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DRIVER_GET_VERSION, wSize, VARPTR(szVer))
END FUNCTION

'#define capDriverGetCaps(hwnd, s, wSize)           ((BOOL)AVICapSM(hwnd, WM_CAP_DRIVER_GET_CAPS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPDRIVERCAPS)(s)))

FUNCTION capDriverGetCaps (BYVAL hwnd AS DWORD, BYREF s AS CAPDRIVERCAPS, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DRIVER_GET_VERSION, wSize, VARPTR(s))
END FUNCTION

'#define capFileSetCaptureFile(hwnd, szName)        ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_CAPTURE_FILE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capFileSetCaptureFile (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_SET_CAPTURE_FILE, 0, VARPTR(szName))
END FUNCTION

'#define capFileGetCaptureFile(hwnd, szName, wSize) ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_GET_CAPTURE_FILE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capFileGetCaptureFile (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_GET_CAPTURE_FILE, wSize, VARPTR(szName))
END FUNCTION

'#define capFileAlloc(hwnd, dwSize)                 ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_ALLOCATE, 0, (LPARAM)(DWORD)(dwSize)))

FUNCTION capFileAlloc (BYVAL hwnd AS DWORD, BYVAL dwSize AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_ALLOCATE, 0, dwSize)
END FUNCTION

'#define capFileSaveAs(hwnd, szName)                ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEAS, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capFileSaveAs (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_SAVEAS, 0, VARPTR(szName))
END FUNCTION

'#define capFileSetInfoChunk(hwnd, lpInfoChunk)     ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SET_INFOCHUNK, (WPARAM)0, (LPARAM)(LPCAPINFOCHUNK)(lpInfoChunk)))

FUNCTION capFileSetInfoChunk (BYVAL hwnd AS DWORD, BYREF lpInfoChunk AS CAPINFOCHUNK) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_SET_INFOCHUNK, 0, VARPTR(lpInfoChunk))
END FUNCTION

'#define capFileSaveDIB(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_FILE_SAVEDIB, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capFileSaveDIB (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_FILE_SAVEDIB, 0, VARPTR(szName))
END FUNCTION

'#define capEditCopy(hwnd)                          ((BOOL)AVICapSM(hwnd, WM_CAP_EDIT_COPY, 0, 0L))

FUNCTION capEditCopy (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_EDIT_COPY, 0, 0)
END FUNCTION

'#define capSetAudioFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))

FUNCTION capSetAudioFormat (BYVAL hwnd AS DWORD, BYREF s AS WAVEFORMATEX, wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_AUDIOFORMAT, wSize, VARPTR(s))
END FUNCTION

'#define capGetAudioFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPWAVEFORMATEX)(s)))

FUNCTION capGetAudioFormat (BYVAL hwnd AS DWORD, BYREF s AS WAVEFORMATEX, wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_AUDIOFORMAT, wSize, VARPTR(s))
END FUNCTION

'#define capGetAudioFormatSize(hwnd)                ((DWORD)AVICapSM(hwnd, WM_CAP_GET_AUDIOFORMAT, (WPARAM)0, (LPARAM)0L))

FUNCTION capGetAudioFormatSize (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_AUDIOFORMAT, 0, 0)
END FUNCTION

'#define capDlgVideoFormat(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOFORMAT, 0, 0L))

FUNCTION capDlgVideoFormat (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DLG_VIDEOFORMAT, 0, 0)
END FUNCTION

'#define capDlgVideoSource(hwnd)                    ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOSOURCE, 0, 0L))

FUNCTION capDlgVideoSource (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DLG_VIDEOSOURCE, 0, 0)
END FUNCTION

'#define capDlgVideoDisplay(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEODISPLAY, 0, 0L))

FUNCTION capDlgVideoDisplay (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DLG_VIDEODISPLAY, 0, 0)
END FUNCTION

'#define capDlgVideoCompression(hwnd)               ((BOOL)AVICapSM(hwnd, WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0L))

FUNCTION capDlgVideoCompression (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_DLG_VIDEOCOMPRESSION, 0, 0)
END FUNCTION

'#define capGetVideoFormat(hwnd, s, wSize)          ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))

FUNCTION capGetVideoFormat (BYVAL hwnd AS DWORD, BYVAL s AS DWORD, wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_VIDEOFORMAT, wSize, s)
END FUNCTION

'#define capGetVideoFormatSize(hwnd)            ((DWORD)AVICapSM(hwnd, WM_CAP_GET_VIDEOFORMAT, 0, 0L))

FUNCTION capGetVideoFormatSize (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_VIDEOFORMAT, 0, 0)
END FUNCTION

'#define capSetVideoFormat(hwnd, s, wSize)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_VIDEOFORMAT, (WPARAM)(wSize), (LPARAM)(LPVOID)(s)))

FUNCTION capSetVideoFormat (BYVAL hwnd AS DWORD, s AS DWORD, wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_VIDEOFORMAT, wSize, s)
END FUNCTION

'#define capPreview(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEW, (WPARAM)(BOOL)(f), 0L))

FUNCTION capPreview (BYVAL hwnd AS DWORD, BYVAL f AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_PREVIEW, f, 0)
END FUNCTION

'#define capPreviewRate(hwnd, wMS)                  ((BOOL)AVICapSM(hwnd, WM_CAP_SET_PREVIEWRATE, (WPARAM)(wMS), 0))

FUNCTION capPreviewRate (BYVAL hwnd AS DWORD, BYVAL wMS AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_PREVIEWRATE, wMS, 0)
END FUNCTION

'#define capOverlay(hwnd, f)                        ((BOOL)AVICapSM(hwnd, WM_CAP_SET_OVERLAY, (WPARAM)(BOOL)(f), 0L))

FUNCTION capOverlay (BYVAL hwnd AS DWORD, BYVAL f AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_OVERLAY, f, 0)
END FUNCTION

'#define capPreviewScale(hwnd, f)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCALE, (WPARAM)(BOOL)f, 0L))

FUNCTION capPreviewScale (BYVAL hwnd AS DWORD, BYVAL f AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_SCALE, f, 0)
END FUNCTION

'#define capGetStatus(hwnd, s, wSize)               ((BOOL)AVICapSM(hwnd, WM_CAP_GET_STATUS, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPSTATUS)(s)))

FUNCTION capGetStatus (BYVAL hwnd AS DWORD, BYREF s AS CAPSTATUS, wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_STATUS, wSize, VARPTR(s))
END FUNCTION

'#define capSetScrollPos(hwnd, lpP)                 ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SCROLL, (WPARAM)0, (LPARAM)(LPPOINT)(lpP)))

FUNCTION capSetScrollPos (BYVAL hwnd AS DWORD, BYREF lpP AS POINT) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_SCROLL, 0, VARPTR(lpP))
END FUNCTION

'#define capGrabFrame(hwnd)                         ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME, (WPARAM)0, (LPARAM)0L))

FUNCTION capGrabFrame (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GRAB_FRAME, 0, 0)
END FUNCTION

'#define capGrabFrameNoStop(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_GRAB_FRAME_NOSTOP, (WPARAM)0, (LPARAM)0L))

FUNCTION capGrabFrameNoStop (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GRAB_FRAME_NOSTOP, 0, 0)
END FUNCTION

'#define capCaptureSequence(hwnd)                   ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureSequence (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SEQUENCE, 0, 0)
END FUNCTION

'#define capCaptureSequenceNoFile(hwnd)             ((BOOL)AVICapSM(hwnd, WM_CAP_SEQUENCE_NOFILE, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureSequenceNoFile (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SEQUENCE_NOFILE, 0, 0)
END FUNCTION

'#define capCaptureStop(hwnd)                       ((BOOL)AVICapSM(hwnd, WM_CAP_STOP, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureStop (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_STOP, 0, 0)
END FUNCTION

'#define capCaptureAbort(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_ABORT, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureAbort (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_ABORT, 0, 0)
END FUNCTION

'#define capCaptureSingleFrameOpen(hwnd)            ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_OPEN, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureSingleFrameOpen (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SINGLE_FRAME_OPEN, 0, 0)
END FUNCTION

'#define capCaptureSingleFrameClose(hwnd)           ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME_CLOSE, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureSingleFrameClose (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SINGLE_FRAME_CLOSE, 0, 0)
END FUNCTION

'#define capCaptureSingleFrame(hwnd)                ((BOOL)AVICapSM(hwnd, WM_CAP_SINGLE_FRAME, (WPARAM)0, (LPARAM)0L))

FUNCTION capCaptureSingleFrame (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SINGLE_FRAME, 0, 0)
END FUNCTION

'#define capCaptureGetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_GET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))

FUNCTION capCaptureGetSetup (BYVAL hwnd AS DWORD, BYREF s AS CAPTUREPARMS, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_GET_SEQUENCE_SETUP, wSize, VARPTR(s))
END FUNCTION

'#define capCaptureSetSetup(hwnd, s, wSize)         ((BOOL)AVICapSM(hwnd, WM_CAP_SET_SEQUENCE_SETUP, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPCAPTUREPARMS)(s)))

FUNCTION capCaptureSetSetup (BYVAL hwnd AS DWORD, BYREF s AS CAPTUREPARMS, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_SEQUENCE_SETUP, wSize, VARPTR(s))
END FUNCTION

'#define capSetMCIDeviceName(hwnd, szName)          ((BOOL)AVICapSM(hwnd, WM_CAP_SET_MCI_DEVICE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capSetMCIDeviceName (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_MCI_DEVICE, 0, VARPTR(szName))
END FUNCTION

'#define capGetMCIDeviceName(hwnd, szName, wSize)   ((BOOL)AVICapSM(hwnd, WM_CAP_GET_MCI_DEVICE, (WPARAM)(wSize), (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capGetMCIDeviceName (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ, BYVAL wSize AS WORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_SET_MCI_DEVICE, wSize, VARPTR(szName))
END FUNCTION

'#define capPaletteOpen(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_OPEN, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capPaletteOpen (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_PAL_OPEN, 0, VARPTR(szName))
END FUNCTION

'#define capPaletteSave(hwnd, szName)               ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_SAVE, 0, (LPARAM)(LPVOID)(LPTSTR)(szName)))

FUNCTION capPaletteSave (BYVAL hwnd AS DWORD, BYREF szName AS ASCIIZ) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_PAL_SAVE, 0, VARPTR(szName))
END FUNCTION

'#define capPalettePaste(hwnd)                      ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_PASTE, (WPARAM) 0, (LPARAM)0L))

FUNCTION capPalettePaste (BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_PAL_PASTE, 0, 0)
END FUNCTION

'#define capPaletteAuto(hwnd, iFrames, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_AUTOCREATE, (WPARAM)(iFrames), (LPARAM)(DWORD)(iColors)))

FUNCTION capPaletteAuto (BYVAL hwnd AS DWORD, BYVAL iFrames AS LONG, BYVAL iColors AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_PAL_AUTOCREATE, iFrames, iColors)
END FUNCTION

'#define capPaletteManual(hwnd, fGrab, iColors)     ((BOOL)AVICapSM(hwnd, WM_CAP_PAL_MANUALCREATE, (WPARAM)(fGrab), (LPARAM)(DWORD)(iColors)))

FUNCTION capPaletteManual (BYVAL hwnd AS DWORD, BYVAL fGrab AS LONG, BYVAL iColors AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %WM_CAP_PAL_MANUALCREATE, fGrab, iColors)
END FUNCTION

'// ------------------------------------------------------------------
'//  Callback Definitions
'// ------------------------------------------------------------------

'typedef LRESULT (CALLBACK* CAPYIELDCALLBACK)  (HWND hWnd);
'typedef LRESULT (CALLBACK* CAPSTATUSCALLBACKW) (HWND hWnd, int nID, LPCWSTR lpsz);
'typedef LRESULT (CALLBACK* CAPERRORCALLBACKW)  (HWND hWnd, int nID, LPCWSTR lpsz);
'typedef LRESULT (CALLBACK* CAPSTATUSCALLBACKA) (HWND hWnd, int nID, LPCSTR lpsz);
'typedef LRESULT (CALLBACK* CAPERRORCALLBACKA)  (HWND hWnd, int nID, LPCSTR lpsz);
'#ifdef UNICODE
'#define CAPSTATUSCALLBACK  CAPSTATUSCALLBACKW
'#define CAPERRORCALLBACK   CAPERRORCALLBACKW
'#else
'#define CAPSTATUSCALLBACK  CAPSTATUSCALLBACKA
'#define CAPERRORCALLBACK   CAPERRORCALLBACKA
'#endif
'typedef LRESULT (CALLBACK* CAPVIDEOCALLBACK)  (HWND hWnd, LPVIDEOHDR lpVHdr);
'typedef LRESULT (CALLBACK* CAPWAVECALLBACK)   (HWND hWnd, LPWAVEHDR lpWHdr);
'typedef LRESULT (CALLBACK* CAPCONTROLCALLBACK)(HWND hWnd, int nState);

'FUNCTION CAPYIELDCALLBACK (BYVAL hwnd AS DWORD) AS LONG
'FUNCTION CAPSTATUSCALLBACKW (BYVAL hwnd AS DWORD, BYVAL nID AS LONG, BYVAL lpsz AS DWORD) AS LONG
'FUNCTION CAPERRORCALLBACKW (BYVAL hwnd AS DWORD, BYVAL nID AS LONG, BYVAL lpsz AS DWORD) AS LONG
'FUNCTION CAPSTATUSCALLBACKA (BYVAL hwnd AS DWORD, BYVAL nID AS LONG, BYREF lpsz AS ASCIIZ) AS LONG
'FUNCTION CAPERRORCALLBACKA (BYVAL hwnd AS DWORD, BYVAL nID AS LONG, BYREF lpsz AS ASCIIZ) AS LONG
'FUNCTION CAPVIDEOCALLBACK (BYVAL hwnd AS DWORD, BYREF lpVHdr AS VIDEOHDR) AS LONG
'FUNCTION CAPWAVECALLBACK (BYVAL hwnd AS DWORD, BYREF lpWHdr AS WAVEHDR) AS LONG
'FUNCTION CAPCONTROLCALLBACK (BYVAL hwnd AS DWORD, BYVAL nState AS LONG) AS LONG

'// ------------------------------------------------------------------
'//  CapControlCallback states
'// ------------------------------------------------------------------
%CONTROLCALLBACK_PREROLL   = 1  ' /* Waiting to start capture */
%CONTROLCALLBACK_CAPTURING = 2  ' /* Now capturing */

'// ------------------------------------------------------------------
'//  The only exported functions from AVICAP.DLL
'// ------------------------------------------------------------------

DECLARE FUNCTION capCreateCaptureWindowA IMPORT "AVICAP32.DLL" ALIAS "capCreateCaptureWindowA" ( _
   BYREF lpszWindowName AS ASCIIZ _                     ' __in LPCSTR lpszWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL nID AS LONG _                                  ' __in int nID
 ) AS DWORD                                             ' HWND

DECLARE FUNCTION capCreateCaptureWindowW IMPORT "AVICAP32.DLL" ALIAS "capCreateCaptureWindowW" ( _
   BYREF lpszWindowName AS WSTRINGZ _                   ' __in LPCWSTR lpszWindowName
 , BYVAL dwStyle AS DWORD _                             ' __in DWORD dwStyle
 , BYVAL x AS LONG _                                    ' __in int x
 , BYVAL y AS LONG _                                    ' __in int y
 , BYVAL nWidth AS LONG _                               ' __in int nWidth
 , BYVAL nHeight AS LONG _                              ' __in int nHeight
 , BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYVAL nID AS LONG _                                  ' __in int nID
 ) AS DWORD                                             ' HWND

#IF %DEF(%UNICODE)
   MACRO capCreateCaptureWindow = capCreateCaptureWindowW
#ELSE
   MACRO capCreateCaptureWindow = capCreateCaptureWindowA
#ENDIF

DECLARE FUNCTION capGetDriverDescriptionA IMPORT "AVICAP32.DLL" ALIAS "capGetDriverDescriptionA" ( _
   BYVAL wDriverIndex AS DWORD _                        ' __in wDriverIndex
 , BYREF lpszName AS ASCIIZ _                           ' __inout LPSTR lpszName
 , BYVAL cbName AS LONG _                               ' __in int cbName
 , BYREF lpszVer AS ASCIIZ  _                           ' __inout LPSTR lpszVer
 , BYVAL cbVer AS LONG _                                ' __in int cbVer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION capGetDriverDescriptionW IMPORT "AVICAP32.DLL" ALIAS "capGetDriverDescriptionW" ( _
   BYVAL wDriverIndex AS DWORD _                        ' __in wDriverIndex
 , BYREF lpszName AS WSTRINGZ _                         ' __inout LPWSTR lpszName
 , BYVAL cbName AS LONG _                               ' __in int cbName
 , BYREF lpszVer AS WSTRINGZ _                          ' __inout LPWSTR lpszVer
 , BYVAL cbVer AS LONG _                                ' __in int cbVer
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO capGetDriverDescription = capGetDriverDescriptionW
#ELSE
   MACRO capGetDriverDescription = capGetDriverDescriptionA
#ENDIF

'// ------------------------------------------------------------------
'// New Information chunk IDs
'// ------------------------------------------------------------------
'#define infotypeDIGITIZATION_TIME  mmioFOURCC ('I','D','I','T')
'#define infotypeSMPTE_TIME         mmioFOURCC ('I','S','M','P')

%infotypeDIGITIZATION_TIME = &H54494449
%infotypeSMPTE_TIME        = &H504D5349

'// ------------------------------------------------------------------
'// String IDs from status and error callbacks
'// ------------------------------------------------------------------

%IDS_CAP_BEGIN                = 300  ' /* "Capture Start" */
%IDS_CAP_END                  = 301  ' /* "Capture End" */

%IDS_CAP_INFO                 = 401  ' /* "%s" */
%IDS_CAP_OUTOFMEM             = 402  ' /* "Out of memory" */
%IDS_CAP_FILEEXISTS           = 403  ' /* "File '%s' exists -- overwrite it?" */
%IDS_CAP_ERRORPALOPEN         = 404  ' /* "Error opening palette '%s'" */
%IDS_CAP_ERRORPALSAVE         = 405  ' /* "Error saving palette '%s'" */
%IDS_CAP_ERRORDIBSAVE         = 406  ' /* "Error saving frame '%s'" */
%IDS_CAP_DEFAVIEXT            = 407  ' /* "avi" */
%IDS_CAP_DEFPALEXT            = 408  ' /* "pal" */
%IDS_CAP_CANTOPEN             = 409  ' /* "Cannot open '%s'" */
%IDS_CAP_SEQ_MSGSTART         = 410  ' /* "Select OK to start capture\nof video sequence\nto %s." */
%IDS_CAP_SEQ_MSGSTOP          = 411  ' /* "Hit ESCAPE or click to end capture" */

%IDS_CAP_VIDEDITERR           = 412  ' /* "An error occurred while trying to run VidEdit." */
%IDS_CAP_READONLYFILE         = 413  ' /* "The file '%s' is a read-only file." */
%IDS_CAP_WRITEERROR           = 414  ' /* "Unable to write to file '%s'.\nDisk may be full." */
%IDS_CAP_NODISKSPACE          = 415  ' /* "There is no space to create a capture file on the specified device." */
%IDS_CAP_SETFILESIZE          = 416  ' /* "Set File Size" */
%IDS_CAP_SAVEASPERCENT        = 417  ' /* "SaveAs: %2ld%%  Hit Escape to abort." */

%IDS_CAP_DRIVER_ERROR         = 418  ' /* Driver specific error message */

%IDS_CAP_WAVE_OPEN_ERROR      = 419  ' /* "Error: Cannot open the wave input device.\nCheck sample size, frequency, and channels." */
%IDS_CAP_WAVE_ALLOC_ERROR     = 420  ' /* "Error: Out of memory for wave buffers." */
%IDS_CAP_WAVE_PREPARE_ERROR   = 421  ' /* "Error: Cannot prepare wave buffers." */
%IDS_CAP_WAVE_ADD_ERROR       = 422  ' /* "Error: Cannot add wave buffers." */
%IDS_CAP_WAVE_SIZE_ERROR      = 423  ' /* "Error: Bad wave size." */

%IDS_CAP_VIDEO_OPEN_ERROR     = 424  ' /* "Error: Cannot open the video input device." */
%IDS_CAP_VIDEO_ALLOC_ERROR    = 425  ' /* "Error: Out of memory for video buffers." */
%IDS_CAP_VIDEO_PREPARE_ERROR  = 426  ' /* "Error: Cannot prepare video buffers." */
%IDS_CAP_VIDEO_ADD_ERROR      = 427  ' /* "Error: Cannot add video buffers." */
%IDS_CAP_VIDEO_SIZE_ERROR     = 428  ' /* "Error: Bad video size." */

%IDS_CAP_FILE_OPEN_ERROR      = 429  ' /* "Error: Cannot open capture file." */
%IDS_CAP_FILE_WRITE_ERROR     = 430  ' /* "Error: Cannot write to capture file.  Disk may be full." */
%IDS_CAP_RECORDING_ERROR      = 431  ' /* "Error: Cannot write to capture file.  Data rate too high or disk full." */
%IDS_CAP_RECORDING_ERROR2     = 432  ' /* "Error while recording" */
%IDS_CAP_AVI_INIT_ERROR       = 433  ' /* "Error: Unable to initialize for capture." */
%IDS_CAP_NO_FRAME_CAP_ERROR   = 434  ' /* "Warning: No frames captured.\nConfirm that vertical sync interrupts\nare configured and enabled." */
%IDS_CAP_NO_PALETTE_WARN      = 435  ' /* "Warning: Using default palette." */
%IDS_CAP_MCI_CONTROL_ERROR    = 436  ' /* "Error: Unable to access MCI device." */
%IDS_CAP_MCI_CANT_STEP_ERROR  = 437  ' /* "Error: Unable to step MCI device." */
%IDS_CAP_NO_AUDIO_CAP_ERROR   = 438  ' /* "Error: No audio data captured.\nCheck audio card settings." */
%IDS_CAP_AVI_DRAWDIB_ERROR    = 439  ' /* "Error: Unable to draw this data format." */
%IDS_CAP_COMPRESSOR_ERROR     = 440  ' /* "Error: Unable to initialize compressor." */
%IDS_CAP_AUDIO_DROP_ERROR     = 441  ' /* "Error: Audio data was lost during capture, reduce capture rate." */
%IDS_CAP_AUDIO_DROP_COMPERROR = 442  ' /* "Error: Audio data was lost during capture.  Try capturing without compressing." */

'/* status string IDs */
%IDS_CAP_STAT_LIVE_MODE       = 500  ' /* "Live window" */
%IDS_CAP_STAT_OVERLAY_MODE    = 501  ' /* "Overlay window" */
%IDS_CAP_STAT_CAP_INIT        = 502  ' /* "Setting up for capture - Please wait" */
%IDS_CAP_STAT_CAP_FINI        = 503  ' /* "Finished capture, now writing frame %ld" */
%IDS_CAP_STAT_PALETTE_BUILD   = 504  ' /* "Building palette map" */
%IDS_CAP_STAT_OPTPAL_BUILD    = 505  ' /* "Computing optimal palette" */
%IDS_CAP_STAT_I_FRAMES        = 506  ' /* "%d frames" */
%IDS_CAP_STAT_L_FRAMES        = 507  ' /* "%ld frames" */
%IDS_CAP_STAT_CAP_L_FRAMES    = 508  ' /* "Captured %ld frames" */
%IDS_CAP_STAT_CAP_AUDIO       = 509  ' /* "Capturing audio" */
%IDS_CAP_STAT_VIDEOCURRENT    = 510  ' /* "Captured %ld frames (%ld dropped) %d.%03d sec." */
%IDS_CAP_STAT_VIDEOAUDIO      = 511  ' /* "Captured %d.%03d sec.  %ld frames (%ld dropped) (%d.%03d fps).  %ld audio bytes (%d,%03d sps)" */
%IDS_CAP_STAT_VIDEOONLY       = 512  ' /* "Captured %d.%03d sec.  %ld frames (%ld dropped) (%d.%03d fps)" */
%IDS_CAP_STAT_FRAMESDROPPED   = 513  ' /* "Dropped %ld of %ld frames (%d.%02d%%) during capture." */

#ENDIF ' /* NOAVICAP */ ' ----------------------------------------------------------------

'/****************************************************************************
' *
' *  ACM (Audio compression manager)
' *
' ***************************************************************************/

#IF NOT %DEF(%NOMSACM)
    #INCLUDE ONCE "msacm.inc"
#ENDIF

'/****************************************************************************
' *
' *  FilePreview dialog.
' *
' ***************************************************************************/
'#ifdef OFN_READONLY

#IF NOT %DEF(%COMDLG_INC)
    #INCLUDE ONCE "commdlg.inc"    ' for OPENFILENAME structure
#ENDIF

DECLARE FUNCTION GetOpenFileNamePreviewA IMPORT "MSVFW32.DLL" ALIAS "GetOpenFileNamePreviewA" ( _
   BYREF lpofn AS OPENFILENAMEA _                       ' __inout LPOPENFILENAMEA lpofn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetOpenFileNamePreviewW IMPORT "MSVFW32.DLL" ALIAS "GetOpenFileNamePreviewW" ( _
   BYREF lpofn AS OPENFILENAMEW _                       ' __inout LPOPENFILENAMEW lpofn
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetOpenFileNamePreview = GetOpenFileNamePreviewW
#ELSE
   MACRO GetOpenFileNamePreview = GetOpenFileNamePreviewA
#ENDIF

DECLARE FUNCTION GetSaveFileNamePreviewA IMPORT "MSVFW32.DLL" ALIAS "GetSaveFileNamePreviewA" ( _
   BYREF lpofn AS OPENFILENAMEA _                       ' __inout LPOPENFILENAMEA lpofn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSaveFileNamePreviewW IMPORT "MSVFW32.DLL" ALIAS "GetSaveFileNamePreviewW" ( _
   BYREF lpofn AS OPENFILENAMEW _                       ' __inout LPOPENFILENAMEW lpofn
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetSaveFileNamePreview = GetSaveFileNamePreviewW
#ELSE
   MACRO GetSaveFileNamePreview = GetSaveFileNamePreviewA
#ENDIF

'#endif // OFN_READONLY
