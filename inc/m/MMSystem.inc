' ########################################################################################
' Microsoft Windows
' File: MMSystem.inc
' Contents: Include file for Multimedia API's
' Version 4.00
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MMSYSTEM_INC = 1

' *--------------------------------------------------------------------------
' *
' *  Define:         Prevent inclusion of:
' *  --------------  --------------------------------------------------------
' *  MMNODRV         Installable driver support
' *  MMNOSOUND       Sound support
' *  MMNOWAVE        Waveform support
' *  MMNOMIDI        MIDI support
' *  MMNOAUX         Auxiliary audio support
' *  MMNOMIXER       Mixer support
' *  MMNOTIMER       Timer support
' *  MMNOJOY         Joystick support
' *  MMNOMCI         MCI support
' *  MMNOMMIO        Multimedia file I/O support
' *
' *==========================================================================
' */

'#ifdef _WIN32
'#include <pshpack1.h>
'#else
'#ifndef RC_INVOKED
'#pragma pack(1)
'#endif
'#endif

#INCLUDE ONCE "windows.inc"

'/****************************************************************************
'                    General constants and data types
'****************************************************************************/


'/* general constants */
%MAXPNAMELEN     = 32  ' max product name length (including NULL)
%MAXERRORLENGTH  = 256  ' max error text length (including final NULL)
%MAX_JOYSTICKOEMVXDNAME  = 260

'/*
' *  Microsoft Manufacturer and Product ID's (these have been moved to
' *  MMREG.H for Windows 4.00 and above).
' */
#IF NOT %DEF(%MM_MICROSOFT)
%MM_MICROSOFT                  = 1     ' Microsoft Corporation
#ENDIF

#IF NOT %DEF(%MM_MIDI_MAPPER)
%MM_MIDI_MAPPER     = 1   ' MIDI Mapper
%MM_WAVE_MAPPER     = 2   ' Wave Mapper
%MM_SNDBLST_MIDIOUT = 3   ' Sound Blaster MIDI output port
%MM_SNDBLST_MIDIIN  = 4   ' Sound Blaster MIDI input port
%MM_SNDBLST_SYNTH   = 5   ' Sound Blaster internal synthesizer
%MM_SNDBLST_WAVEOUT = 6   ' Sound Blaster waveform output
%MM_SNDBLST_WAVEIN  = 7   ' Sound Blaster waveform input
%MM_ADLIB           = 9   ' Ad Lib-compatible synthesizer
%MM_MPU401_MIDIOUT  = 10  ' MPU401-compatible MIDI output port
%MM_MPU401_MIDIIN   = 11  ' MPU401-compatible MIDI input port
%MM_PC_JOYSTICK     = 12  ' Joystick adapter
#ENDIF

'/* general data types */

'#ifdef _WIN32
'typedef UINT        MMVERSION;  /* major (high byte), minor (low byte) */
'#else
'typedef UINT        VERSION;    /* major (high byte), minor (low byte) */
'#endif
'typedef UINT        MMRESULT;   /* error return code, 0 means no error */
'                                /* call as if(err=xxxx(...)) Error(err); else */
'#define _MMRESULT_

'typedef UINT FAR   *LPUINT;



'/* MMTIME data structure */
'typedef struct mmtime_tag
'{
'    UINT            wType;      /* indicates the contents of the union */
'    union
'    {
'        DWORD       ms;         /* milliseconds */
'        DWORD       sample;     /* samples */
'        DWORD       cb;         /* byte count */
'        DWORD       ticks;      /* ticks in MIDI stream */

'        /* SMPTE */
'        struct
'        {
'            BYTE    hour;       /* hours */
'            BYTE    min;        /* minutes */
'            BYTE    sec;        /* seconds */
'            BYTE    frame;      /* frames  */
'            BYTE    fps;        /* frames per second */
'            BYTE    dummy;      /* pad */
'#ifdef _WIN32
'            BYTE    pad[2];
'#endif
'        } smpte;

'        /* MIDI */
'        struct
'        {
'            DWORD songptrpos;   /* song pointer position */
'        } midi;
'    } u;
'} MMTIME, *PMMTIME, NEAR *NPMMTIME, FAR *LPMMTIME;

' // Size = 8 bytes
TYPE MMTIME_SMPTE BYTE
   hour   AS BYTE   ' BYTE
   MIN    AS BYTE   ' BYTE
   sec    AS BYTE   ' BYTE
   FRAME  AS BYTE   ' BYTE
   fps    AS BYTE   ' BYTE
   dummy  AS BYTE   ' BYTE
   pad(1) AS BYTE   ' BYTE[2]
END TYPE

' // Size = 4 bytes
TYPE MMTIME_MIDI BYTE
   songptrpos AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
UNION MMTIME_UNION BYTE
   ms     AS DWORD   ' DWORD
   sample AS DWORD   ' DWORD
   cb     AS DWORD   ' DWORD
   ticks  AS DWORD   ' DWORD
   smpte  AS MMTIME_SMPTE
   midi   AS MMTIME_MIDI
   ' // For compatibility with PB includes
   MMTIME_SMPTE
   MMTIME_MIDI
END UNION

' // Size = 12 bytes
TYPE MMTIME BYTE
   wType AS DWORD
   MMTIME_UNION
END TYPE

'/* types for wType field in MMTIME struct */
%TIME_MS       = &H0001???     ' time in Milliseconds
%TIME_SAMPLES  = &H0002???     ' number of wave samples
%TIME_BYTES    = &H0004???     ' current byte offset
%TIME_SMPTE    = &H0008???     ' SMPTE time
%TIME_MIDI     = &H0010???     ' MIDI time
%TIME_TICKS    = &H0020???     ' /* Ticks within MIDI stream */

'/*
' *
' *
' */
'#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
'                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
'                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))


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

'                    Multimedia Extensions Window Messages

'****************************************************************************/

%MM_JOY1MOVE         = &H3A0???  ' joystick
%MM_JOY2MOVE         = &H3A1???
%MM_JOY1ZMOVE        = &H3A2???
%MM_JOY2ZMOVE        = &H3A3???
%MM_JOY1BUTTONDOWN   = &H3B5???
%MM_JOY2BUTTONDOWN   = &H3B6???
%MM_JOY1BUTTONUP     = &H3B7???
%MM_JOY2BUTTONUP     = &H3B8???

'#define MM_MCINOTIFY        0x3B9           /* MCI */

%MM_MCINOTIFY        = &H3B9???  ' MCI

%MM_WOM_OPEN         = &H3BB???  ' waveform output
%MM_WOM_CLOSE        = &H3BC???
%MM_WOM_DONE         = &H3BD???

%MM_WIM_OPEN         = &H3BE???  ' waveform input
%MM_WIM_CLOSE        = &H3BF???
%MM_WIM_DATA         = &H3C0???

%MM_MIM_OPEN         = &H3C1???  ' MIDI input
%MM_MIM_CLOSE        = &H3C2???
%MM_MIM_DATA         = &H3C3???
%MM_MIM_LONGDATA     = &H3C4???
%MM_MIM_ERROR        = &H3C5???
%MM_MIM_LONGERROR    = &H3C6???

%MM_MOM_OPEN         = &H3C7???  ' MIDI output
%MM_MOM_CLOSE        = &H3C8???
%MM_MOM_DONE         = &H3C9???

'/* these are also in msvideo.h */
#IF NOT %DEF(%MM_DRVM_OPEN)
%MM_DRVM_OPEN        = &H3D0???          ' /* installable drivers */
%MM_DRVM_CLOSE       = &H3D1???
%MM_DRVM_DATA        = &H3D2???
%MM_DRVM_ERROR       = &H3D3???
#ENDIF

'/* these are used by msacm.h */
%MM_STREAM_OPEN      = &H3D4???
%MM_STREAM_CLOSE     = &H3D5???
%MM_STREAM_DONE      = &H3D6???
%MM_STREAM_ERROR     = &H3D7???

'#if(WINVER >= 0x0400)
%MM_MOM_POSITIONCB   = &H3CA???     ' Callback for MEVT_POSITIONCB

#IF NOT %DEF(%MM_MCISIGNAL)
%MM_MCISIGNAL        = &H3CB???
#ENDIF

%MM_MIM_MOREDATA     = &H3CC???     ' MIM_DONE w/ pending events


'#endif /* WINVER >= 0x0400 */
%MM_MIXM_LINE_CHANGE     = &H3D0???     ' /* mixer line change notify */
%MM_MIXM_CONTROL_CHANGE  = &H3D1???     ' /* mixer control change notify */


'/****************************************************************************

'                String resource number bases (internal use)

'****************************************************************************/

%MMSYSERR_BASE = 0
%WAVERR_BASE   = 32
%MIDIERR_BASE  = 64
%TIMERR_BASE   = 96   ' was 128, changed to match Win 31 Sonic
%JOYERR_BASE   = 160
%MCIERR_BASE   = 256
%MIXERR_BASE   = 1024

%MCI_STRING_OFFSET  = 512  ' if this number is changed you MUST
                           ' alter the MCI_DEVTYPE_... list below
%MCI_VD_OFFSET      = 1024
%MCI_CD_OFFSET      = 1088
%MCI_WAVE_OFFSET    = 1152
%MCI_SEQ_OFFSET     = 1216

'/****************************************************************************

'                        General error return values

'****************************************************************************/

'/* general error return values */
%MMSYSERR_NOERROR      = 0  ' no error
%MMSYSERR_ERROR        = %MMSYSERR_BASE + 1  ' unspecified error
%MMSYSERR_BADDEVICEID  = %MMSYSERR_BASE + 2  ' device ID out of range
%MMSYSERR_NOTENABLED   = %MMSYSERR_BASE + 3  ' driver failed enable
%MMSYSERR_ALLOCATED    = %MMSYSERR_BASE + 4  ' device already allocated
%MMSYSERR_INVALHANDLE  = %MMSYSERR_BASE + 5  ' device xHandle is invalid
%MMSYSERR_NODRIVER     = %MMSYSERR_BASE + 6  ' no device driver present
%MMSYSERR_NOMEM        = %MMSYSERR_BASE + 7  ' memory allocation error
%MMSYSERR_NOTSUPPORTED = %MMSYSERR_BASE + 8  ' function isn't supported
%MMSYSERR_BADERRNUM    = %MMSYSERR_BASE + 9  ' error value out of range
%MMSYSERR_INVALFLAG    = %MMSYSERR_BASE + 10 ' invalid flag passed
%MMSYSERR_INVALPARAM   = %MMSYSERR_BASE + 11 ' invalid parameter passed
%MMSYSERR_HANDLEBUSY   = %MMSYSERR_BASE + 12 ' xHandle being used
                                             ' simultaneously on another
                                             ' thread (eg callback)
%MMSYSERR_INVALIDALIAS = %MMSYSERR_BASE + 13 ' "Specified alias not found in WIN.INI
%MMSYSERR_BADDB        = %MMSYSERR_BASE + 14 ' /* bad registry database */
%MMSYSERR_KEYNOTFOUND  = %MMSYSERR_BASE + 15 ' /* registry key not found */
%MMSYSERR_READERROR    = %MMSYSERR_BASE + 16 ' /* registry read error */
%MMSYSERR_WRITEERROR   = %MMSYSERR_BASE + 17 ' /* registry write error */
%MMSYSERR_DELETEERROR  = %MMSYSERR_BASE + 18 ' /* registry delete error */
%MMSYSERR_VALNOTFOUND  = %MMSYSERR_BASE + 19 ' /* registry value not found */
%MMSYSERR_NODRIVERCB   = %MMSYSERR_BASE + 20 ' /* driver does not call DriverCallback */
%MMSYSERR_MOREDATA     = %MMSYSERR_BASE + 21 ' /* more data to be returned */
%MMSYSERR_LASTERROR    = %MMSYSERR_BASE + 21 ' /* last error in range */

'#if (WINVER < 0x030a) || defined(_WIN32)
'DECLARE_HANDLE(HDRVR);
'#endif /* ifdef WINVER < 0x030a */

#IF NOT %DEF(%MMNODRV)
'/****************************************************************************

'                        Installable driver support

'****************************************************************************/

' // Size = 16 bytes
TYPE DRVCONFIGINFOEX BYTE
   dwDCISize          AS DWORD          ' DWORD   dwDCISize
   lpszDCISectionName AS WSTRINGZ PTR   ' LPCWSTR  lpszDCISectionName
   lpszDCIAliasName   AS WSTRINGZ PTR   ' LPCWSTR  lpszDCIAliasName
   dnDevNode          AS DWORD          ' DWORD    dnDevNode
END TYPE

'#if (WINVER < 0x030a) || defined(_WIN32)

#IF NOT %DEF(%DRV_LOAD)
'#ifndef DRV_LOAD

'/* Driver messages */
%DRV_LOAD            = &H0001???
%DRV_ENABLE          = &H0002???
%DRV_OPEN            = &H0003???
%DRV_CLOSE           = &H0004???
%DRV_DISABLE         = &H0005???
%DRV_FREE            = &H0006???
%DRV_CONFIGURE       = &H0007???
%DRV_QUERYCONFIGURE  = &H0008???
%DRV_INSTALL         = &H0009???
%DRV_REMOVE          = &H000A???
%DRV_EXITSESSION     = &H000B???
%DRV_POWER           = &H000F???
%DRV_RESERVED        = &H0800???
%DRV_USER            = &H4000???

'/* LPARAM of DRV_CONFIGURE message */
' // Size = 12 bytes
TYPE DRVCONFIGINFO BYTE
  dwDCISize          AS DWORD          ' DWORD   dwDCISize
  lpszDCISectionName AS WSTRINGZ PTR   ' LPCWSTR  lpszDCISectionName
  lpszDCIAliasName   AS WSTRINGZ PTR   ' LPCWSTR  lpszDCIAliasName
END TYPE

'/* Supported return values for DRV_CONFIGURE message */
%DRVCNF_CANCEL  = &H0000???
%DRVCNF_OK      = &H0001???
%DRVCNF_RESTART = &H0002???

'/* installable driver function prototypes */
'#ifdef _WIN32

'typedef LRESULT (CALLBACK* DRIVERPROC)(DWORD_PTR, HDRVR, UINT, LPARAM, LPARAM);
'FUNCTION DRIVERPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG, BYVAL LONG) AS LONG

DECLARE FUNCTION CloseDriver IMPORT "WINMM.DLL" ALIAS "CloseDriver" ( _
   BYVAL hDriver AS DWORD _                             ' __in HDRVR hDriver
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION OpenDriver IMPORT "WINMM.DLL" ALIAS "OpenDriver" ( _
   BYREF szDriverName AS WSTRINGZ _                     ' __in LPCWSTR szDriverName
 , BYREF szSectionName AS WSTRINGZ _                    ' __in LPCWSTR szSectionName
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS DWORD                                             ' HDRVR

DECLARE FUNCTION SendDriverMessage IMPORT "WINMM.DLL" ALIAS "SendDriverMessage" ( _
   BYVAL hDriver AS DWORD _                             ' __in HDRVR hDriver
 , BYVAL message AS LONG _                              ' __in UINT message
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION DrvGetModuleHandle IMPORT "WINMM.DLL" ALIAS "DrvGetModuleHandle" ( _
   BYVAL hDriver AS DWORD _                             ' __in HDRVR hDriver
 ) AS DWORD                                             ' HMODULE

DECLARE FUNCTION GetDriverModuleHandle IMPORT "WINMM.DLL" ALIAS "GetDriverModuleHandle" ( _
   BYVAL hDriver AS DWORD _                             ' __in HDRVR hDriver
 ) AS DWORD                                             ' HMODULE

DECLARE FUNCTION DefDriverProc IMPORT "WINMM.DLL" ALIAS "DefDriverProc" ( _
   BYVAL dwDriverIdentifier AS DWORD _                  ' __in DWORD_PTR dwDriverIdentifier
 , BYVAL hdrvr AS DWORD _                               ' __in HDRVR hdrvr
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS LONG                                              ' LRESULT

#ENDIF   ' #IF NOT %DEF(%DRV_LOAD)
'#endif /* ifdef (WINVER < 0x030a) || defined(_WIN32) */

'#if (WINVER >= 0x030a)
'/* return values from DriverProc() function */
%DRV_CANCEL    = %DRVCNF_CANCEL
%DRV_OK        = %DRVCNF_OK
%DRV_RESTART   = %DRVCNF_RESTART

'#endif /* ifdef WINVER >= 0x030a */

%DRV_MCI_FIRST = %DRV_RESERVED
%DRV_MCI_LAST  = %DRV_RESERVED + &HFFF

#ENDIF   ' #IF NOT %DEF(%MMNODRV)


'/****************************************************************************

'                          Driver callback support

'****************************************************************************/

'/* flags used with waveOutOpen(), waveInOpen(), midiInOpen(), and */
'/* midiOutOpen() to specify the type of the dwCallback parameter. */

%CALLBACK_TYPEMASK = &H00070000???        ' callback type mask
%CALLBACK_NULL     = &H00000000???        ' no callback
%CALLBACK_WINDOW   = &H00010000???        ' dwCallback is a HWND
%CALLBACK_TASK     = &H00020000???        ' dwCallback is a HTASK
%CALLBACK_FUNCTION = &H00030000???        ' dwCallback is a FARPROC
%CALLBACK_THREAD   = %CALLBACK_TASK       ' thread ID replaces 16 bit task
%CALLBACK_EVENT    = &H00050000???        ' dwCallback is an EVENT Handle


#IF NOT %DEF(%MMNOSOUND)
'/****************************************************************************

'                            Sound support

'****************************************************************************/

'#ifdef _WIN32

DECLARE FUNCTION sndPlaySoundA IMPORT "WINMM.DLL" ALIAS "sndPlaySoundA" ( _
   BYREF pszSound AS ASCIIZ _                           ' __in LPCSTR pszSound
 , BYVAL fuSound AS DWORD _                             ' __in UINT fuSound
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION sndPlaySoundW IMPORT "WINMM.DLL" ALIAS "sndPlaySoundW" ( _
   BYREF pszSound AS WSTRINGZ _                         ' __in LPCWSTR pszSound
 , BYVAL fuSound AS DWORD _                             ' __in UINT fuSound
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO sndPlaySound = sndPlaySoundW
#ELSE
   MACRO sndPlaySound = sndPlaySoundA
#ENDIF

'/*
' *  flag values for fuSound and fdwSound arguments on [snd]PlaySound
' */
%SND_SYNC           = &H0000???         ' /* play synchronously (default) */
%SND_ASYNC          = &H0001???         ' /* play asynchronously */
%SND_NODEFAULT      = &H0002???         ' /* silence not default, if sound not found */
%SND_MEMORY         = &H0004???         ' /* lpszSoundName points to a memory file */
%SND_LOOP           = &H0008???         ' /* loop the sound until next sndPlaySound */
%SND_NOSTOP         = &H0010???         ' /* don't stop any currently playing sound */

%SND_NOWAIT         = &H00002000???     ' /* don't wait if the driver is busy */
%SND_ALIAS          = &H00010000???     ' /* name is a WIN.INI [sounds] entry */
%SND_ALIAS_ID       = &H00110000???     ' /* name is a WIN.INI [sounds] entry identifier */
%SND_FILENAME       = &H00020000???     ' /* name is a file name */
%SND_RESOURCE       = &H00040004???     ' /* name is a resource name or atom */
'#if(WINVER >= 0x0400)
%SND_PURGE          = &H0040???         ' /* purge non-static events for task */
%SND_APPLICATION    = &H0080???         ' /* look for application specific association */
'#endif /* WINVER >= 0x0400 */
%SND_SENTRY         = &H00080000???     ' /* Generate a SoundSentry event with this sound */
%SND_RING           = &H00100000???     ' /* Treat this as a "ring" from a communications app - don't duck me */
%SND_SYSTEM         = &H00200000???     ' /* Treat this as a system sound */

%SND_ALIAS_START    = 0  ' must be > 4096 to keep strings in same section of resource file

'#ifdef _WIN32
'#define sndAlias(ch0, ch1)      (SND_ALIAS_START + (DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8))

FUNCTION sndAlias (BYVAL strch0 AS STRING, BYVAL strch1 AS STRING) AS DWORD
   LOCAL ch0 AS DWORD, ch1 AS DWORD
   ch0 = ASC(strch0)
   ch1 = ASC(strch1)
   SHIFT LEFT ch1, 8
   FUNCTION = %SND_ALIAS_START + (ch0 OR ch1)
END FUNCTION

%SND_ALIAS_SYSTEMASTERISK       = &H00002A53   ' sndAlias('S', '*')
%SND_ALIAS_SYSTEMQUESTION       = &H00003F53   ' sndAlias('S', '?')
%SND_ALIAS_SYSTEMHAND           = &H00004853   ' sndAlias('S', 'H')
%SND_ALIAS_SYSTEMEXIT           = &H00004553   ' sndAlias('S', 'E')
%SND_ALIAS_SYSTEMSTART          = &H00005353   ' sndAlias('S', 'S')
%SND_ALIAS_SYSTEMWELCOME        = &H00005753   ' sndAlias('S', 'W')
%SND_ALIAS_SYSTEMEXCLAMATION    = &H00002153   ' sndAlias('S', '!')
%SND_ALIAS_SYSTEMDEFAULT        = &H00004453   ' sndAlias('S', 'D')

DECLARE FUNCTION PlaySoundA IMPORT "WINMM.DLL" ALIAS "PlaySoundA" ( _
   BYREF pszSound AS ASCIIZ _                           ' __in LPCSTR pszSound
 , BYVAL hmod AS DWORD _                                ' __in HMODULE hmod
 , BYVAL fdwSound AS DWORD _                            ' __in DWORD fdwSound
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PlaySoundW IMPORT "WINMM.DLL" ALIAS "PlaySoundW" ( _
   BYREF pszSound AS WSTRINGZ _                         ' __in LPCWSTR pszSound
 , BYVAL hmod AS DWORD _                                ' __in HMODULE hmod
 , BYVAL fdwSound AS DWORD _                            ' __in DWORD fdwSound
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PlaySound = PlaySoundW
#ELSE
   MACRO PlaySound = PlaySoundA
#ENDIF

#ENDIF   ' #IF NOT %DEF(%MMNOSOUND)

#IF NOT %DEF(%MMNOWAVE)
'/****************************************************************************

'                        Waveform audio support

'****************************************************************************/

'/* waveform audio error return values */
%WAVERR_BADFORMAT    = %WAVERR_BASE + 0    ' unsupported wave format
%WAVERR_STILLPLAYING = %WAVERR_BASE + 1    ' still something playing
%WAVERR_UNPREPARED   = %WAVERR_BASE + 2    ' header not prepared
%WAVERR_SYNC         = %WAVERR_BASE + 3    ' device is synchronous
%WAVERR_LASTERROR    = %WAVERR_BASE + 3    ' last error in range

'/* waveform audio data types */
'DECLARE_HANDLE(HWAVE);
'DECLARE_HANDLE(HWAVEIN);
'DECLARE_HANDLE(HWAVEOUT);
'typedef HWAVEIN FAR *LPHWAVEIN;
'typedef HWAVEOUT FAR *LPHWAVEOUT;
'typedef DRVCALLBACK WAVECALLBACK;
'typedef WAVECALLBACK FAR *LPWAVECALLBACK;

'/* wave callback messages */
%WOM_OPEN   = %MM_WOM_OPEN
%WOM_CLOSE  = %MM_WOM_CLOSE
%WOM_DONE   = %MM_WOM_DONE
%WIM_OPEN   = %MM_WIM_OPEN
%WIM_CLOSE  = %MM_WIM_CLOSE
%WIM_DATA   = %MM_WIM_DATA

'/* device ID for wave device mapper */
'#define WAVE_MAPPER     ((UINT)-1)
' Declared as %WAVE_MAPPER = -1& in WIN32API.INC.
%WAVE_MAPPER    = &HFFFFFFFF???

'/* flags for dwFlags parameter in waveOutOpen() and waveInOpen() */
%WAVE_FORMAT_QUERY        = &H0001???
%WAVE_ALLOWSYNC           = &H0002???
'#if(WINVER >= 0x0400)
%WAVE_MAPPED              = &H0004???
%WAVE_FORMAT_DIRECT       = &H0008???
%WAVE_FORMAT_DIRECT_QUERY = %WAVE_FORMAT_QUERY OR %WAVE_FORMAT_DIRECT
%WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE = &H0010???
'#endif /* WINVER >= 0x0400 */

'/* wave data block header */
' // Size = 32 bytes
TYPE WAVEHDR BYTE
   lpData          AS ASCIIZ PTR   ' LPSTR       lpData             /* pointer to locked data buffer */
   dwBufferLength  AS DWORD        ' DWORD       dwBufferLength     /* length of data buffer */
   dwBytesRecorded AS DWORD        ' DWORD       dwBytesRecorded    /* used for input only */
   dwUser          AS DWORD        ' DWORD_PTR   dwUser             /* for client's use */
   dwFlags         AS DWORD        ' DWORD       dwFlags            /* assorted flags (see defines) */
   dwLoops         AS DWORD        ' DWORD       dwLoops            /* loop control counter */
   lpNext          AS WAVEHDR PTR  ' struct wavehdr_tag FAR *lpNext /* reserved for driver */
   reserved        AS DWORD        ' DWORD_PTR   reserved           /* reserved for driver */
END TYPE

'/* flags for dwFlags field of WAVEHDR */
%WHDR_DONE      = &H00000001???   ' done bit
%WHDR_PREPARED  = &H00000002???   ' set if this header has been prepared
%WHDR_BEGINLOOP = &H00000004???   ' loop start block
%WHDR_ENDLOOP   = &H00000008???   ' loop end block
%WHDR_INQUEUE   = &H00000010???  ' reserved for driver

'/* waveform output device capabilities structure */
'#ifdef _WIN32

' // Size = 52 bytes
TYPE WAVEOUTCAPSA BYTE
   wMid           AS WORD                    ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                    ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                   ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN   ' CHAR    szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats      AS DWORD                   ' DWORD   dwFormats             /* formats supported */
   wChannels      AS WORD                    ' WORD    wChannels             /* number of sources supported */
   wReserved1     AS WORD                    ' WORD    wReserved1            /* packing */
   dwSupport      AS DWORD                   ' DWORD   dwSupport             /* functionality supported by driver */
END TYPE

' // Size = 84 bytes
TYPE WAVEOUTCAPSW BYTE
   wMid           AS WORD                        ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                        ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR   szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats      AS DWORD                       ' DWORD   dwFormats             /* formats supported */
   wChannels      AS WORD                        ' WORD    wChannels             /* number of sources supported */
   wReserved1     AS WORD                        ' WORD    wReserved1            /* packing */
   dwSupport      AS DWORD                       ' DWORD   dwSupport             /* functionality supported by driver */
END TYPE

MACRO WAVEOUTCAPS = WAVEOUTCAPSA

' // Size = 100 bytes
TYPE WAVEOUTCAPS2A BYTE
   wMid             AS WORD                    ' WORD    wMid                  /* manufacturer ID */
   wPid             AS WORD                    ' WORD    wPid                  /* product ID */
   vDriverVersion   AS DWORD                   ' MMVERSION vDriverVersion      /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN   ' CHAR    szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats        AS DWORD                   ' DWORD   dwFormats             /* formats supported */
   wChannels        AS WORD                    ' WORD    wChannels             /* number of sources supported */
   wReserved1       AS WORD                    ' WORD    wReserved1            /* packing */
   dwSupport        AS DWORD                   ' DWORD   dwSupport             /* functionality supported by driver */
   ManufacturerGuid AS GUID                    ' GUID    ManufacturerGuid      /* for extensible MID mapping */
   ProductGuid      AS GUID                    ' GUID    ProductGuid           /* for extensible PID mapping */
   NameGuid         AS GUID                    ' GUID    NameGuid              /* for name lookup in registry */
END TYPE

' // Size = 132 bytes
TYPE WAVEOUTCAPS2W BYTE
   wMid             AS WORD                        ' WORD    wMid                  /* manufacturer ID */
   wPid             AS WORD                        ' WORD    wPid                  /* product ID */
   vDriverVersion   AS DWORD                       ' MMVERSION vDriverVersion      /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR   szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats        AS DWORD                       ' DWORD   dwFormats             /* formats supported */
   wChannels        AS WORD                        ' WORD    wChannels             /* number of sources supported */
   wReserved1       AS WORD                        ' WORD    wReserved1            /* packing */
   dwSupport        AS DWORD                       ' DWORD   dwSupport             /* functionality supported by driver */
   ManufacturerGuid AS GUID                        ' GUID    ManufacturerGuid      /* for extensible MID mapping */
   ProductGuid      AS GUID                        ' GUID    ProductGuid           /* for extensible PID mapping */
   NameGuid         AS GUID                        ' GUID    NameGuid              /* for name lookup in registry */
END TYPE

MACRO WAVEOUTCAPS2 = WAVEOUTCAPS2A

'/* flags for dwSupport field of WAVEOUTCAPS */
%WAVECAPS_PITCH          = &H0001   ' supports pitch control
%WAVECAPS_PLAYBACKRATE   = &H0002   ' supports playback rate control
%WAVECAPS_VOLUME         = &H0004   ' supports volume control
%WAVECAPS_LRVOLUME       = &H0008   ' separate left-right volume control
%WAVECAPS_SYNC           = &H0010   '
%WAVECAPS_SAMPLEACCURATE = &H0020


'/* waveform input device capabilities structure */
'#ifdef _WIN32

' // Size = 48 bytes
TYPE WAVEINCAPSA BYTE
   wMid           AS WORD                       ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                       ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                      ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN      ' CHAR    szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats      AS DWORD                      ' DWORD   dwFormats             /* formats supported */
   wChannels      AS WORD                       ' WORD    wChannels             /* number of channels supported */
   wReserved1     AS WORD                       ' WORD    wReserved1            /* structure packing */
END TYPE

' // Size = 80 bytes
TYPE WAVEINCAPSW BYTE
   wMid           AS WORD                        ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                        ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR   szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   dwFormats      AS DWORD                       ' DWORD   dwFormats             /* formats supported */
   wChannels      AS WORD                        ' WORD    wChannels             /* number of channels supported */
   wReserved1     AS WORD                        ' WORD    wReserved1            /* structure packing */
END TYPE

MACRO WAVEINCAPS = WAVEINCAPSA

' // Size = 96 bytes
TYPE WAVEINCAPS2A BYTE
   wMid             AS WORD                       ' WORD    wMid                 /* manufacturer ID */
   wPid             AS WORD                       ' WORD    wPid                 /* product ID */
   vDriverVersion   AS DWORD                      ' MMVERSION vDriverVersion     /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN      ' CHAR    szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   dwFormats        AS DWORD                      ' DWORD   dwFormats            /* formats supported */
   wChannels        AS WORD                       ' WORD    wChannels            /* number of channels supported */
   wReserved1       AS WORD                       ' WORD    wReserved1           /* structure packing */
   ManufacturerGuid AS GUID                       ' GUID    ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                       ' GUID    ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                       ' GUID    NameGuid             /* for name lookup in registry */
END TYPE

' // Size = 128 bytes
TYPE WAVEINCAPS2W BYTE
   wMid             AS WORD                       ' WORD    wMid                 /* manufacturer ID */
   wPid             AS WORD                       ' WORD    wPid                 /* product ID */
   vDriverVersion   AS DWORD                      ' MMVERSION vDriverVersion     /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN    ' WCHAR   szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   dwFormats        AS DWORD                      ' DWORD   dwFormats            /* formats supported */
   wChannels        AS WORD                       ' WORD    wChannels            /* number of channels supported */
   wReserved1       AS WORD                       ' WORD    wReserved1           /* structure packing */
   ManufacturerGuid AS GUID                       ' GUID    ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                       ' GUID    ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                       ' GUID    NameGuid             /* for name lookup in registry */
END TYPE

MACRO WAVEINCAPS2 = WAVEINCAPS2A

'/* defines for dwFormat field of WAVEINCAPS and WAVEOUTCAPS */
%WAVE_INVALIDFORMAT = &H00000000???   ' invalid format
%WAVE_FORMAT_1M08   = &H00000001???   ' 11.025 kHz, Mono,   8-bit
%WAVE_FORMAT_1S08   = &H00000002???   ' 11.025 kHz, Stereo, 8-bit
%WAVE_FORMAT_1M16   = &H00000004???   ' 11.025 kHz, Mono,   16-bit
%WAVE_FORMAT_1S16   = &H00000008???   ' 11.025 kHz, Stereo, 16-bit
%WAVE_FORMAT_2M08   = &H00000010???   ' 22.05  kHz, Mono,   8-bit
%WAVE_FORMAT_2S08   = &H00000020???   ' 22.05  kHz, Stereo, 8-bit
%WAVE_FORMAT_2M16   = &H00000040???   ' 22.05  kHz, Mono,   16-bit
%WAVE_FORMAT_2S16   = &H00000080???   ' 22.05  kHz, Stereo, 16-bit
%WAVE_FORMAT_4M08   = &H00000100???   ' 44.1   kHz, Mono,   8-bit
%WAVE_FORMAT_4S08   = &H00000200???   ' 44.1   kHz, Stereo, 8-bit
%WAVE_FORMAT_4M16   = &H00000400???   ' 44.1   kHz, Mono,   16-bit
%WAVE_FORMAT_4S16   = &H00000800???   ' 44.1   kHz, Stereo, 16-bit

%WAVE_FORMAT_44M08  = &H00000100???   ' /* 44.1   kHz, Mono,   8-bit  */
%WAVE_FORMAT_44S08  = &H00000200???   ' /* 44.1   kHz, Stereo, 8-bit  */
%WAVE_FORMAT_44M16  = &H00000400???   ' /* 44.1   kHz, Mono,   16-bit */
%WAVE_FORMAT_44S16  = &H00000800???   ' /* 44.1   kHz, Stereo, 16-bit */
%WAVE_FORMAT_48M08  = &H00001000???   ' /* 48     kHz, Mono,   8-bit  */
%WAVE_FORMAT_48S08  = &H00002000???   ' /* 48     kHz, Stereo, 8-bit  */
%WAVE_FORMAT_48M16  = &H00004000???   ' /* 48     kHz, Mono,   16-bit */
%WAVE_FORMAT_48S16  = &H00008000???   ' /* 48     kHz, Stereo, 16-bit */
%WAVE_FORMAT_96M08  = &H00010000???   ' /* 96     kHz, Mono,   8-bit  */
%WAVE_FORMAT_96S08  = &H00020000???   ' /* 96     kHz, Stereo, 8-bit  */
%WAVE_FORMAT_96M16  = &H00040000???   ' /* 96     kHz, Mono,   16-bit */
%WAVE_FORMAT_96S16  = &H00080000???   ' /* 96     kHz, Stereo, 16-bit */

#IF NOT %DEF(%WAVE_FORMAT_PCM)

'/* OLD general waveform format structure (information common to all formats) */

' // Size = 14 bytes
TYPE WAVEFORMAT BYTE
   wFormatTag      AS WORD    ' WORD    wFormatTag;        /* format type */
   nChannels       AS WORD    ' WORD    nChannels;         /* number of channels (i.e. mono, stereo, etc.) */
   nSamplesPerSec  AS DWORD   ' DWORD   nSamplesPerSec;    /* sample rate */
   nAvgBytesPerSec AS DWORD   ' DWORD   nAvgBytesPerSec;   /* for buffer estimation */
   nBlockAlign     AS WORD    ' WORD    nBlockAlign;       /* block size of data */
END TYPE

'/* flags for wFormatTag field of WAVEFORMAT */
'#define WAVE_FORMAT_PCM     1
%WAVE_FORMAT_PCM = 1

'/* specific waveform format structure for PCM data */
' // Size = 16 bytes
TYPE PCMWAVEFORMAT BYTE
   wf             AS WAVEFORMAT   ' WAVEFORMAT  wf
   wBitsPerSample AS WORD         ' WORD        wBitsPerSample
END TYPE

#ENDIF   ' #IF NOT %DEF(%WAVE_FORMAT_PCM)

#IF NOT %DEF(%WAVEFORMATEX)
    %WAVEFORMATEX = 1
'/*
' *  extended waveform format structure used for all non-PCM formats. this
' *  structure is common to all non-PCM formats.
' */

' // Size = 18 bytes
TYPE WAVEFORMATEX BYTE
   wFormatTag      AS WORD    ' WORD  wFormatTag;         /* format type */
   nChannels       AS WORD    ' WORD  nChannels;          /* number of channels (i.e. mono, stereo...) */
   nSamplesPerSec  AS DWORD   ' DWORD nSamplesPerSec;     /* sample rate */
   nAvgBytesPerSec AS DWORD   ' DWORD nAvgBytesPerSec;    /* for buffer estimation */
   nBlockAlign     AS WORD    ' WORD  nBlockAlign;        /* block size of data */
   wBitsPerSample  AS WORD    ' WORD  wBitsPerSample;     /* number of bits per sample of mono data */
   cbSize          AS WORD    ' WORD  cbSize;             /* the count in bytes of the size of */
                              '                           /* extra information (after cbSize) */
END TYPE
#ENDIF   ' #IF NOT %DEF(%WAVEFORMATEX)

'/* waveform audio function prototypes */

DECLARE FUNCTION waveOutGetNumDevs IMPORT "WINMM.DLL" ALIAS "waveOutGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION waveOutGetDevCapsA IMPORT "WINMM.DLL" ALIAS "waveOutGetDevCapsA" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in  UINT uDeviceID
 , BYREF pwoc AS WAVEOUTCAPSA _                         ' __out LPWAVEOUTCAPS pwoc
 , BYVAL cbwoc AS DWORD _                               ' __in  UINT cbwoc
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetDevCapsW IMPORT "WINMM.DLL" ALIAS "waveOutGetDevCapsW" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in  UINT uDeviceID
 , BYREF pwoc AS WAVEOUTCAPSW _                         ' __out LPWAVEOUTCAPSW pwoc
 , BYVAL cbwoc AS DWORD _                               ' __in  UINT cbwoc
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO waveOutGetDevCaps = waveOutGetDevCapsW
#ELSE
   MACRO waveOutGetDevCaps = waveOutGetDevCapsA
#ENDIF

'#if (WINVER >= 0x0400)
DECLARE FUNCTION waveOutGetVolume IMPORT "WINMM.DLL" ALIAS "waveOutGetVolume" ( _
   BYVAL hwo AS DWORD _                                 ' __in  HWAVEOUT hwo
 , BYREF pdwVolume AS DWORD _                           ' __out LPDWORD pdwVolume
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutSetVolume IMPORT "WINMM.DLL" ALIAS "waveOutSetVolume" ( _
   BYVAL uId AS DWORD _                                 ' __in UINT uId
 , BYVAL dwVolume AS DWORD _                            ' __in DWORD dwVolume
 ) AS LONG                                              ' MMRESULT
'#endif

DECLARE FUNCTION waveOutGetErrorTextA IMPORT "WINMM.DLL" ALIAS "waveOutGetErrorTextA" ( _
   BYVAL mmrError AS LONG _                             ' __in  MMRESULT mmrError
 , BYREF pszText AS ASCIIZ _                            ' __out LPSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in  UINT cchText
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetErrorTextW IMPORT "WINMM.DLL" ALIAS "waveOutGetErrorTextW" ( _
   BYVAL mmrError AS LONG _                             ' __in  MMRESULT mmrError
 , BYREF pszText AS WSTRINGZ _                          ' __out LPWSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in  UINT cchText
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO waveOutGetErrorText = waveOutGetErrorTextW
#ELSE
   MACRO waveOutGetErrorText = waveOutGetErrorTextA
#ENDIF

DECLARE FUNCTION waveOutOpen IMPORT "WINMM.DLL" ALIAS "waveOutOpen" ( _
   BYREF phwo AS DWORD _                                ' __out LPHWAVEOUT phwo
 , BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYREF pwfx AS WAVEFORMATEX _                         ' __in LPCWAVEFORMATEX pwfx
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutClose IMPORT "WINMM.DLL" ALIAS "waveOutClose" ( _
   BYVAL hwo AS DWORD _                                 ' __in_out HWAVEOUT hwo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutPrepareHeader IMPORT "WINMM.DLL" ALIAS "waveOutPrepareHeader" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' __in UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutUnprepareHeader IMPORT "WINMM.DLL" ALIAS "waveOutUnprepareHeader" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' __in UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutWrite IMPORT "WINMM.DLL" ALIAS "waveOutWrite" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' __in UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutPause IMPORT "WINMM.DLL" ALIAS "waveOutPause" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutRestart IMPORT "WINMM.DLL" ALIAS "waveOutRestart" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutReset IMPORT "WINMM.DLL" ALIAS "waveOutReset" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutBreakLoop IMPORT "WINMM.DLL" ALIAS "waveOutBreakLoop" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetPosition IMPORT "WINMM.DLL" ALIAS "waveOutGetPosition" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pmmt AS MMTIME _                               ' __in_out LPMMTIME pmmt
 , BYVAL cbmmt AS DWORD _                               ' __in UINT cbmmt
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetPitch IMPORT "WINMM.DLL" ALIAS "waveOutGetPitch" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pdwPitch AS DWORD _                            ' __out LPDWORD pdwPitch
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutSetPitch IMPORT "WINMM.DLL" ALIAS "waveOutSetPitch" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYVAL dwPitch AS DWORD _                             ' __in DWORD dwPitch
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetPlaybackRate IMPORT "WINMM.DLL" ALIAS "waveOutGetPlaybackRate" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF pdwRate AS DWORD _                             ' __out LPDWORD pdwRate
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutSetPlaybackRate IMPORT "WINMM.DLL" ALIAS "waveOutSetPlaybackRate" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYVAL dwRate AS DWORD _                              ' __in DWORD dwRate
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveOutGetID IMPORT "WINMM.DLL" ALIAS "waveOutGetID" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYREF puDeviceID AS DWORD _                          ' __out LPUINT puDeviceID
 ) AS LONG                                              ' MMRESULT

'#if (WINVER >= 0x030a)
DECLARE FUNCTION waveOutMessage IMPORT "WINMM.DLL" ALIAS "waveOutMessage" ( _
   BYVAL hwo AS DWORD _                                 ' __in HWAVEOUT hwo
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD_PTR dw1
 , BYVAL dw2 as DWORD _                                 ' __in DWORD_PTR dw2
 ) AS LONG                                              ' MMRESULT
'#endif /* ifdef WINVER >= 0x030a */

DECLARE FUNCTION waveInGetNumDevs IMPORT "WINMM.DLL" ALIAS "waveInGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION waveInGetDevCapsA IMPORT "WINMM.DLL" ALIAS "waveInGetDevCapsA" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pwic AS WAVEINCAPSA _                          ' __out LPWAVEINCAPSA pwic
 , BYVAL cbwic AS DWORD _                               ' __in UINT cbwic
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInGetDevCapsW IMPORT "WINMM.DLL" ALIAS "waveInGetDevCapsW" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pwic AS WAVEINCAPSW _                          ' __out LPWAVEINCAPSW pwic
 , BYVAL cbwic AS DWORD _                               ' __in UINT cbwic
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO waveInGetDevCaps = waveInGetDevCapsW
#ELSE
   MACRO waveInGetDevCaps = waveInGetDevCapsA
#ENDIF

DECLARE FUNCTION waveInGetErrorTextA IMPORT "WINMM.DLL" ALIAS "waveInGetErrorTextA" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS ASCIIZ _                            ' __out LPSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInGetErrorTextW IMPORT "WINMM.DLL" ALIAS "waveInGetErrorTextW" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS WSTRINGZ _                          ' __out LPWSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO waveInGetErrorText = waveInGetErrorTextW
#ELSE
   MACRO waveInGetErrorText = waveInGetErrorTextA
#ENDIF

DECLARE FUNCTION waveInOpen IMPORT "WINMM.DLL" ALIAS "waveInOpen" ( _
   BYREF phwi AS DWORD _                                ' __out LPHWAVEIN phwi
 , BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYREF pwfx AS WAVEFORMATEX _                         ' __in LPCWAVEFORMATEX pwfx
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInClose IMPORT "WINMM.DLL" ALIAS "waveInClose" ( _
   BYVAL hwi AS DWORD _                                 ' __in_out HWAVEIN hwi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInPrepareHeader IMPORT "WINMM.DLL" ALIAS "waveInPrepareHeader" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' __in UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInUnprepareHeader IMPORT "WINMM.DLL" ALIAS "waveInUnprepareHeader" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInAddBuffer IMPORT "WINMM.DLL" ALIAS "waveInAddBuffer" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYREF pwh AS WAVEHDR _                               ' __in_out LPWAVEHDR pwh
 , BYVAL cbwh AS DWORD _                                ' __in UINT cbwh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInStart IMPORT "WINMM.DLL" ALIAS "waveInStart" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInStop IMPORT "WINMM.DLL" ALIAS "waveInStop" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInReset IMPORT "WINMM.DLL" ALIAS "waveInReset" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInGetPosition IMPORT "WINMM.DLL" ALIAS "waveInGetPosition" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYREF pmmt AS MMTIME _                               ' __in_out LPMMTIME pmmt
 , BYVAL cbmmt AS DWORD _                               ' __in UINT cbmmt
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION waveInGetID IMPORT "WINMM.DLL" ALIAS "waveInGetID" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYREF puDeviceID AS DWORD _                          ' __out LPUINT puDeviceID
 ) AS LONG                                              ' MMRESULT

'#if (WINVER >= 0x030a)
DECLARE FUNCTION waveInMessage IMPORT "WINMM.DLL" ALIAS "waveInMessage" ( _
   BYVAL hwi AS DWORD _                                 ' __in HWAVEIN hwi
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD dw1
 , BYVAL dw2 AS DWORD _                                 ' __in DWORD dw2
 ) AS LONG                                              ' MMRESULT
'#endif /* ifdef WINVER >= 0x030a */

#ENDIF   ' /* ifndef MMNOWAVE */

#IF NOT %DEF(%MMNOMIDI)
'/****************************************************************************

'                            MIDI audio support

'****************************************************************************/

'/* MIDI error return values */
%MIDIERR_UNPREPARED    = %MIDIERR_BASE + 0   ' header not prepared
%MIDIERR_STILLPLAYING  = %MIDIERR_BASE + 1   ' still something playing
%MIDIERR_NOMAP         = %MIDIERR_BASE + 2   ' no current map
%MIDIERR_NOTREADY      = %MIDIERR_BASE + 3   ' hardware is still busy
%MIDIERR_NODEVICE      = %MIDIERR_BASE + 4   ' port no longer connected
%MIDIERR_INVALIDSETUP  = %MIDIERR_BASE + 5   ' invalid setup
%MIDIERR_BADOPENMODE   = %MIDIERR_BASE + 6  ' /* operation unsupported w/ open mode */
%MIDIERR_DONT_CONTINUE = %MIDIERR_BASE + 7  ' /* thru device 'eating' a message */
%MIDIERR_LASTERROR     = %MIDIERR_BASE + 7  ' /* last error in range */

'/* MIDI audio data types */
'DECLARE_HANDLE(HMIDI);
'DECLARE_HANDLE(HMIDIIN);
'DECLARE_HANDLE(HMIDIOUT);
'DECLARE_HANDLE(HMIDISTRM);
'typedef HMIDI FAR *LPHMIDI;
'typedef HMIDIIN FAR *LPHMIDIIN;
'typedef HMIDIOUT FAR *LPHMIDIOUT;
'typedef HMIDISTRM FAR *LPHMIDISTRM;
'typedef DRVCALLBACK MIDICALLBACK;
'typedef MIDICALLBACK FAR *LPMIDICALLBACK;
'#define MIDIPATCHSIZE   128
'typedef WORD PATCHARRAY[MIDIPATCHSIZE];
'typedef WORD FAR *LPPATCHARRAY;
'typedef WORD KEYARRAY[MIDIPATCHSIZE];
'typedef WORD FAR *LPKEYARRAY;

'/* MIDI callback messages */
%MIM_OPEN      = %MM_MIM_OPEN
%MIM_CLOSE     = %MM_MIM_CLOSE
%MIM_DATA      = %MM_MIM_DATA
%MIM_LONGDATA  = %MM_MIM_LONGDATA
%MIM_ERROR     = %MM_MIM_ERROR
%MIM_LONGERROR = %MM_MIM_LONGERROR
%MOM_OPEN      = %MM_MOM_OPEN
%MOM_CLOSE     = %MM_MOM_CLOSE
%MOM_DONE      = %MM_MOM_DONE

'#if(WINVER >= 0x0400)
%MIM_MOREDATA   = %MM_MIM_MOREDATA
%MOM_POSITIONCB = %MM_MOM_POSITIONCB
'#endif /* WINVER >= 0x0400 */

'/* device ID for MIDI mapper */
%MIDIMAPPER   = &HFFFFFFFF???   ' ((UINT)-1)
%MIDI_MAPPER  = &HFFFFFFFF???   ' ((UINT)-1)

'#if(WINVER >= 0x0400)
'/* flags for dwFlags parm of midiInOpen() */
%MIDI_IO_STATUS = &H00000020&
'#endif /* WINVER >= 0x0400 */

'/* flags for wFlags parm of midiOutCachePatches(), midiOutCacheDrumPatches() */
%MIDI_CACHE_ALL     = 1
%MIDI_CACHE_BESTFIT = 2
%MIDI_CACHE_QUERY   = 3
%MIDI_UNCACHE       = 4

'/* MIDI output device capabilities structure */
' // Size = 52 bytes
TYPE MIDIOUTCAPSA BYTE
   wMid           AS WORD                       ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                       ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                      ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN      ' CHAR    szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   wTechnology    AS WORD                       ' WORD    wTechnology           /* type of device */
   wVoices        AS WORD                       ' WORD    wVoices               /* # of voices (internal synth only) */
   wNotes         AS WORD                       ' WORD    wNotes                /* max # of notes (internal synth only) */
   wChannelMask   AS WORD                       ' WORD    wChannelMask          /* channels used (internal synth only) */
   dwSupport      AS DWORD                      ' DWORD   dwSupport             /* functionality supported by driver */
END TYPE

' // Size = 84 bytes
TYPE MIDIOUTCAPSW BYTE
   wMid           AS WORD                       ' WORD    wMid                  /* manufacturer ID */
   wPid           AS WORD                       ' WORD    wPid                  /* product ID */
   vDriverVersion AS DWORD                      ' MMVERSION vDriverVersion      /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN    ' WCHAR   szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   wTechnology    AS WORD                       ' WORD    wTechnology           /* type of device */
   wVoices        AS WORD                       ' WORD    wVoices               /* # of voices (internal synth only) */
   wNotes         AS WORD                       ' WORD    wNotes                /* max # of notes (internal synth only) */
   wChannelMask   AS WORD                       ' WORD    wChannelMask          /* channels used (internal synth only) */
   dwSupport      AS DWORD                      ' DWORD   dwSupport             /* functionality supported by driver */
END TYPE

MACRO MIDIOUTCAPS = MIDIOUTCAPSA

' // Size = 100 bytes
TYPE MIDIOUTCAPS2A BYTE
   wMid             AS WORD                       ' WORD    wMid                  /* manufacturer ID */
   wPid             AS WORD                       ' WORD    wPid                  /* product ID */
   vDriverVersion   AS DWORD                      ' MMVERSION vDriverVersion      /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN      ' CHAR    szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   wTechnology      AS WORD                       ' WORD    wTechnology           /* type of device */
   wVoices          AS WORD                       ' WORD    wVoices               /* # of voices (internal synth only) */
   wNotes           AS WORD                       ' WORD    wNotes                /* max # of notes (internal synth only) */
   wChannelMask     AS WORD                       ' WORD    wChannelMask          /* channels used (internal synth only) */
   dwSupport        AS DWORD                      ' DWORD   dwSupport             /* functionality supported by driver */
   ManufacturerGuid AS GUID                       ' GUID    ManufacturerGuid      /* for extensible MID mapping */
   ProductGuid      AS GUID                       ' GUID    ProductGuid           /* for extensible PID mapping */
   NameGuid         AS GUID                       ' GUID    NameGuid              /* for name lookup in registry */
END TYPE

' // Size = 132 bytes
TYPE MIDIOUTCAPS2W BYTE
   wMid             AS WORD                       ' WORD    wMid                  /* manufacturer ID */
   wPid             AS WORD                       ' WORD    wPid                  /* product ID */
   vDriverVersion   AS DWORD                      ' MMVERSION vDriverVersion      /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN    ' WCHAR   szPname[MAXPNAMELEN]  /* product name (NULL terminated string) */
   wTechnology      AS WORD                       ' WORD    wTechnology           /* type of device */
   wVoices          AS WORD                       ' WORD    wVoices               /* # of voices (internal synth only) */
   wNotes           AS WORD                       ' WORD    wNotes                /* max # of notes (internal synth only) */
   wChannelMask     AS WORD                       ' WORD    wChannelMask          /* channels used (internal synth only) */
   dwSupport        AS DWORD                      ' DWORD   dwSupport             /* functionality supported by driver */
   ManufacturerGuid AS GUID                       ' GUID    ManufacturerGuid      /* for extensible MID mapping */
   ProductGuid      AS GUID                       ' GUID    ProductGuid           /* for extensible PID mapping */
   NameGuid         AS GUID                       ' GUID    NameGuid              /* for name lookup in registry */
END TYPE

MACRO MIDIOUTCAPS2 = MIDIOUTCAPS2A

'/* flags for wTechnology field of MIDIOUTCAPS structure */
%MOD_MIDIPORT   = 1  ' output port
%MOD_SYNTH      = 2  ' generic internal synth
%MOD_SQSYNTH    = 3  ' square wave internal synth
%MOD_FMSYNTH    = 4  ' FM internal synth
%MOD_MAPPER     = 5  ' MIDI mapper
%MOD_WAVETABLE  = 6 ' /* hardware wavetable synth */
%MOD_SWSYNTH    = 7 ' /* software synth */

'/* flags for dwSupport field of MIDIOUTCAPS structure */
%MIDICAPS_VOLUME   = &H0001???         ' supports volume control
%MIDICAPS_LRVOLUME = &H0002???         ' separate left-right volume control
%MIDICAPS_CACHE    = &H0004???

'#if(WINVER >= 0x0400)
%MIDICAPS_STREAM = &H0008???         ' driver supports midiStreamOut directly
'#endif /* WINVER >= 0x0400 */

'/* MIDI input device capabilities structure */

' // Size = 44 bytes
TYPE MIDIINCAPSA BYTE
   wMid           AS WORD                        ' WORD      wMid                   /* manufacturer ID */
   wPid           AS WORD                        ' WORD      wPid                   /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION vDriverVersion         /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN       ' CHAR      szPname[MAXPNAMELEN]   /* product name (NULL terminated string) */
'#if (WINVER >= 0x0400)
   dwSupport      AS DWORD                       ' DWORD     dwSupport             /* functionality supported by driver */
'#if (WINVER >= 0x0400)
END TYPE

' // Size = 76 bytes
TYPE MIDIINCAPSW BYTE
   wMid           AS WORD                        ' WORD      wMid                   /* manufacturer ID */
   wPid           AS WORD                        ' WORD      wPid                   /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION vDriverVersion         /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR     szPname[MAXPNAMELEN]   /* product name (NULL terminated string) */
'#if (WINVER >= 0x0400)
   dwSupport      AS DWORD                       ' DWORD     dwSupport             /* functionality supported by driver */
'#if (WINVER >= 0x0400)
END TYPE

MACRO MIDIINCAPS = MIDIINCAPSA

' // Size = 92 bytes
TYPE MIDIINCAPS2A BYTE
   wMid             AS WORD                      ' WORD        wMid;                   /* manufacturer ID */
   wPid             AS WORD                      ' WORD        wPid;                   /* product ID */
   vDriverVersion   AS DWORD                     ' MMVERSION   vDriverVersion;         /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN     ' CHAR        szPname[MAXPNAMELEN];   /* product name (NULL terminated string) */
'#if (WINVER >= 0x0400)
   dwSupport        AS DWORD                     ' DWORD       dwSupport;              /* functionality supported by driver */
'#endif
   ManufacturerGuid AS GUID                      ' GUID        ManufacturerGuid;       /* for extensible MID mapping */
   ProductGuid      AS GUID                      ' GUID        ProductGuid;            /* for extensible PID mapping */
   NameGuid         AS GUID                      ' GUID        NameGuid;               /* for name lookup in registry */
END TYPE

' // Size = 124 bytes
TYPE MIDIINCAPS2W BYTE
   wMid             AS WORD                      ' WORD        wMid;                   /* manufacturer ID */
   wPid             AS WORD                      ' WORD        wPid;                   /* product ID */
   vDriverVersion   AS DWORD                     ' MMVERSION   vDriverVersion;         /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN   ' WCHAR       szPname[MAXPNAMELEN];   /* product name (NULL terminated string) */
'#if (WINVER >= 0x0400)
   dwSupport        AS DWORD                     ' DWORD       dwSupport;              /* functionality supported by driver */
'#endif
   ManufacturerGuid AS GUID                      ' GUID        ManufacturerGuid;       /* for extensible MID mapping */
   ProductGuid      AS GUID                      ' GUID        ProductGuid;            /* for extensible PID mapping */
   NameGuid         AS GUID                      ' GUID        NameGuid;               /* for name lookup in registry */
END TYPE

MACRO MIDIINCAPS2 = MIDIINCAPS2A

' // Size = 64 bytes
TYPE MIDIHDR BYTE
  lpData          AS ASCIIZ PTR   ' LPSTR       lpData;               /* pointer to locked data block */
  dwBufferLength  AS DWORD        ' DWORD       dwBufferLength;       /* length of data in data block */
  dwBytesRecorded AS DWORD        ' DWORD       dwBytesRecorded;      /* used for input only */
  dwUser          AS DWORD        ' DWORD_PTR   dwUser;               /* for client's use */
  dwFlags         AS DWORD        ' DWORD       dwFlags;              /* assorted flags (see defines) */
  lpNext          AS LONG         ' struct midihdr_tag far *lpNext;   /* reserved for driver */
  Reserved        AS DWORD        ' DWORD_PTR   reserved;             /* reserved for driver */
'#if (WINVER >= 0x0400)
  dwOffset        AS DWORD        ' DWORD       dwOffset;             /* Callback offset into buffer */
  dwReserved(7)   AS  DWORD       ' DWORD_PTR   dwReserved[8];        /* Reserved for MMSYSTEM */
'#endif
END TYPE

' // Size = 16 bytes
TYPE MIDIEVENT BYTE
   dwDeltaTime AS DWORD   ' DWORD dwDeltaTime /* Ticks since last event */
   dwStreamID  AS DWORD   ' DWORD dwStreamID  /* Reserved; must be zero */
   dwEvent     AS DWORD   ' DWORD dwEvent     /* Event type and parameters */
   dwParms(0)  AS DWORD   ' DWORD dwParms[1]  /* Parameters if this is a long event */
END TYPE

' // Size = 12 bytes
TYPE MIDISTRMBUFFVER BYTE
   dwVersion    AS LONG   ' DWORD dwVersion;   /* Stream buffer format version */
   dwMid        AS LONG   ' DWORD dwMid;       /* Manufacturer ID as defined in MMREG.H */
   dwOEMVersion AS LONG   ' DWORD dwOEMVersion /* Manufacturer version for custom ext */
END TYPE
'#endif /* WINVER >= 0x0400 */

'/* flags for dwFlags field of MIDIHDR structure */
%MHDR_DONE     = &H00000001???   ' done bit
%MHDR_PREPARED = &H00000002???   ' set if header prepared
%MHDR_INQUEUE  = &H00000004???   ' reserved for driver
%MHDR_ISSTRM   = &H00000008???   ' Buffer is stream buffer

'#if(WINVER >= 0x0400)
'/* */
'/* Type codes which go in the high byte of the event DWORD of a stream buffer */
'/* */
'/* Type codes 00-7F contain parameters within the low 24 bits */
'/* Type codes 80-FF contain a length of their parameter in the low 24 */
'/* bits, followed by their parameter data in the buffer. The event */
'/* DWORD contains the exact byte length; the parm data itself must be */
'/* padded to be an even multiple of 4 bytes long. */
'/* */

%MEVT_F_SHORT    = &H00000000???
%MEVT_F_LONG     = &H80000000???
%MEVT_F_CALLBACK = &H40000000???

'#define MEVT_EVENTTYPE(x)   ((BYTE)(((x)>>24)&0xFF))
'#define MEVT_EVENTPARM(x)   ((DWORD)((x)&0x00FFFFFFL))

FUNCTION MEVT_EVENTTYPE (BYVAL dwEvent AS DWORD) AS BYTE
   SHIFT RIGHT dwEvent, 24
   FUNCTION = dwEvent AND &HFF?
END FUNCTION

FUNCTION MEVT_EVENTPARM (BYVAL dwEvent AS DWORD) AS DWORD
   FUNCTION = dwEvent AND &H00FFFFFF???
END FUNCTION

%MEVT_SHORTMSG       = &H00?   ' /* parm = shortmsg for midiOutShortMsg */
%MEVT_TEMPO          = &H01?   ' /* parm = new tempo in microsec/qn     */
%MEVT_NOP            = &H02?   ' /* parm = unused; does nothing         */

'/* 0x04-0x7F reserved */
%MEVT_LONGMSG        = &H80?   ' /* parm = bytes to send verbatim       */
%MEVT_COMMENT        = &H82?   ' /* parm = comment data                 */
%MEVT_VERSION        = &H84?   ' /* parm = MIDISTRMBUFFVER struct       */

'/* 0x81-0xFF reserved */

'#define MIDISTRM_ERROR      (-2)
%MIDISTRM_ERROR  = -2

'/* */
'/* Structures and defines for midiStreamProperty */
'/* */
%MIDIPROP_SET = &H80000000???
%MIDIPROP_GET = &H40000000???

'/* These are intentionally both non-zero so the app cannot accidentally */
'/* leave the operation off and happen to appear to work due to default */
'/* action. */

%MIDIPROP_TIMEDIV = &H00000001???
%MIDIPROP_TEMPO   = &H00000002???

' // Size = 8 bytes
TYPE MIDIPROPTIMEDIV BYTE
   cbStruct  AS DWORD   ' DWORD cbStruct
   dwTimeDiv AS DWORD   ' DWORD dwTimeDiv
END TYPE

' // Size = 8 bytes
TYPE MIDIPROPTEMPO BYTE
   cbStruct AS DWORD   ' DWORD cbStruct
   dwTempo  AS DWORD   ' DWORD dwTempo
END TYPE

'#endif /* WINVER >= 0x0400 */

'/* MIDI function prototypes */
DECLARE FUNCTION midiOutGetNumDevs IMPORT "WINMM.DLL" ALIAS "midiOutGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

'#if(WINVER >= 0x0400)

DECLARE FUNCTION midiStreamOpen IMPORT "WINMM.DLL" ALIAS "midiStreamOpen" ( _
   BYREF phms AS DWORD _                                ' __out LPHMIDISTRM phms
 , BYREF puDeviceID AS DWORD _                          ' __in LPUINT puDeviceID
 , BYVAL cMidi AS DWORD _                               ' __in DWORD cMidi
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamClose IMPORT "WINMM.DLL" ALIAS "midiStreamClose" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamProperty IMPORT "WINMM.DLL" ALIAS "midiStreamProperty" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 , BYREF lppropdata AS BYTE _                           ' __out LPBYTE lppropdata
 , BYVAL dwProperty AS DWORD _                          ' __in DWORD dwProperty
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamPosition IMPORT "WINMM.DLL" ALIAS "midiStreamPosition" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 , BYREF lpmmt AS MMTIME _                              ' __out LPMMTIME lpmmt
 , BYVAL cbmmt AS DWORD _                               ' __in UINT cbmmt
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamOut IMPORT "WINMM.DLL" ALIAS "midiStreamOut" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 , BYREF pmh aS MIDIHDR _                               ' __in LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamPause IMPORT "WINMM.DLL" ALIAS "midiStreamPause" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamRestart IMPORT "WINMM.DLL" ALIAS "midiStreamRestart" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiStreamStop IMPORT "WINMM.DLL" ALIAS "midiStreamStop" ( _
   BYVAL hms AS DWORD _                                 ' __in HMIDISTRM hms
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiConnect IMPORT "WINMM.DLL" ALIAS "midiConnect" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDI hmi
 , BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL pReserved AS DWORD _                           ' __in LPVOID pReserved
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiDisconnect IMPORT "WINMM.DLL" ALIAS "midiDisconnect" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDI hmi
 , BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL pReserved AS DWORD _                           ' __in LPVOID pReserved
 ) AS LONG                                              ' MMRESULT

'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION midiOutGetDevCapsA IMPORT "WINMM.DLL" ALIAS "midiOutGetDevCapsA" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pmoc AS MIDIOUTCAPSA _                         ' __out LPMIDIOUTCAPSA pmoc
 , BYVAL cbmoc AS DWORD _                               ' __in UINT cbmoc
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutGetDevCapsW IMPORT "WINMM.DLL" ALIAS "midiOutGetDevCapsW" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pmoc AS MIDIOUTCAPSW _                         ' __out LPMIDIOUTCAPSW pmoc
 , BYVAL cbmoc AS DWORD _                               ' __in UINT cbmoc
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO midiOutGetDevCaps = midiOutGetDevCapsW
#ELSE
   MACRO midiOutGetDevCaps = midiOutGetDevCapsA
#ENDIF

'#if (WINVER >= 0x0400)

DECLARE FUNCTION midiOutGetVolume IMPORT "WINMM.DLL" ALIAS "midiOutGetVolume" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYREF pdwVolume AS DWORD _                           ' __out LPDWORD pdwVolume
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutSetVolume IMPORT "WINMM.DLL" ALIAS "midiOutSetVolume" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL dwVolume AS DWORD _                            ' __in DWORD dwVolume
 ) AS LONG                                              ' MMRESULT

'#endif

DECLARE FUNCTION midiOutGetErrorTextA IMPORT "WINMM.DLL" ALIAS "midiOutGetErrorTextA" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS ASCIIZ _                            ' __out LPSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutGetErrorTextW IMPORT "WINMM.DLL" ALIAS "midiOutGetErrorTextW" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS WSTRINGZ _                          ' __out LPWSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO midiOutGetErrorText = midiOutGetErrorTextW
#ELSE
   MACRO midiOutGetErrorText = midiOutGetErrorTextA
#ENDIF

DECLARE FUNCTION midiOutOpen IMPORT "WINMM.DLL" ALIAS "midiOutOpen" ( _
   BYREF phmo AS DWORD _                                ' __out LPHMIDIOUT phmo
 , BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutClose IMPORT "WINMM.DLL" ALIAS "midiOutClose" ( _
   BYVAL hmo AS DWORD _                                 ' __in_out HMIDIOUT hmo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutPrepareHeader IMPORT "WINMM.DLL" ALIAS "midiOutPrepareHeader" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYREF pmh AS MIDIHDR _                               ' __in_out LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutUnprepareHeader IMPORT "WINMM.DLL" ALIAS "midiOutUnprepareHeader" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYREF pmh AS MIDIHDR _                               ' __in_out LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutShortMsg IMPORT "WINMM.DLL" ALIAS "midiOutShortMsg" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL dwMsg AS DWORD _                               ' __in DWORD dwMsg
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutLongMsg IMPORT "WINMM.DLL" ALIAS "midiOutLongMsg" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYREF pmh AS MIDIHDR _                               ' __in LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutReset IMPORT "WINMM.DLL" ALIAS "midiOutReset" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutCachePatches IMPORT "WINMM.DLL" ALIAS "midiOutCachePatches" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL uBank AS DWORD _                               ' __in UINT uBank
 , BYREF pwpa AS DWORD _                                ' __out LPWORD pwpa
 , BYVAL fuCache AS DWORD _                             ' __in UINT fuCache
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutCacheDrumPatches IMPORT "WINMM.DLL" ALIAS "midiOutCacheDrumPatches" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL uPatch AS DWORD _                              ' __in UINT uPatch
 , BYREF pwkya AS DWORD _                               ' __out LPWORD pwkya
 , BYVAL fuCache AS DWORD _                             ' __in UINT fuCache
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiOutGetID IMPORT "WINMM.DLL" ALIAS "midiOutGetID" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYREF puDeviceID AS DWORD _                          ' __out LPUINT puDeviceID
 ) AS LONG                                              ' MMRESULT

'#if (WINVER >= 0x030a)
DECLARE FUNCTION midiOutMessage IMPORT "WINMM.DLL" ALIAS "midiOutMessage" ( _
   BYVAL hmo AS DWORD _                                 ' __in HMIDIOUT hmo
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD_PTR dw1
 , BYVAL dw2 AS DWORD _                                 ' __in DWORD_PTR dw2
 ) AS LONG                                              ' MMRESULT
'#endif /* ifdef WINVER >= 0x030a */

DECLARE FUNCTION midiInGetNumDevs IMPORT "WINMM.DLL" ALIAS "midiInGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION midiInGetDevCapsA IMPORT "WINMM.DLL" ALIAS "midiInGetDevCapsA" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pmic AS MIDIINCAPSA  _                         ' __out LPMIDIINCAPSA pmic
 , BYVAL cbmic AS DWORD _                               ' __in UINT cbmic
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInGetDevCapsW IMPORT "WINMM.DLL" ALIAS "midiInGetDevCapsW" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pmic AS MIDIINCAPSW _                          ' __out LPMIDIINCAPSW pmic
 , BYVAL cbmic AS DWORD _                               ' __in UINT cbmic
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO midiInGetDevCaps = midiInGetDevCapsW
#ELSE
   MACRO midiInGetDevCaps = midiInGetDevCapsA
#ENDIF

DECLARE FUNCTION midiInGetErrorTextA IMPORT "WINMM.DLL" ALIAS "midiInGetErrorTextA" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS ASCIIZ _                            ' __out LPSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInGetErrorTextW IMPORT "WINMM.DLL" ALIAS "midiInGetErrorTextW" ( _
   BYVAL mmrError AS LONG _                             ' __in MMRESULT mmrError
 , BYREF pszText AS WSTRINGZ _                          ' __out LPWSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO midiInGetErrorText = midiInGetErrorTextW
#ELSE
   MACRO midiInGetErrorText = midiInGetErrorTextA
#ENDIF

DECLARE FUNCTION midiInOpen IMPORT "WINMM.DLL" ALIAS "midiInOpen" ( _
   BYREF phmi AS DWORD _                                ' __out LPHMIDIIN phmi
 , BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInClose IMPORT "WINMM.DLL" ALIAS "midiInClose" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInPrepareHeader IMPORT "WINMM.DLL" ALIAS "midiInPrepareHeader" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 , BYREF pmh AS MIDIHDR _                               ' __in_out LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInUnprepareHeader IMPORT "WINMM.DLL" ALIAS "midiInUnprepareHeader" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 , BYREF pmh AS MIDIHDR _                               ' __in_out LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInAddBuffer IMPORT "WINMM.DLL" ALIAS "midiInAddBuffer" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 , BYREF pmh AS MIDIHDR _                               ' __in LPMIDIHDR pmh
 , BYVAL cbmh AS DWORD _                                ' __in UINT cbmh
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInStart IMPORT "WINMM.DLL" ALIAS "midiInStart" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInStop IMPORT "WINMM.DLL" ALIAS "midiInStop" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInReset IMPORT "WINMM.DLL" ALIAS "midiInReset" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION midiInGetID IMPORT "WINMM.DLL" ALIAS "midiInGetID" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 , BYREF puDeviceID AS DWORD _                          ' __out LPUINT puDeviceID
 ) AS LONG                                              ' MMRESULT

'#if (WINVER >= 0x030a)
DECLARE FUNCTION midiInMessage IMPORT "WINMM.DLL" ALIAS "midiInMessage" ( _
   BYVAL hmi AS DWORD _                                 ' __in HMIDIIN hmi
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD_PTR dw1
 , BYVAL dw2 AS DWORD _                                 ' __in DWORD_PTR dw2
 ) AS LONG                                              ' MMRESULT
'#endif /* ifdef WINVER >= 0x030a */

#ENDIF   ' /* ifndef MMNOMIDI */

#IF NOT %DEF(%MMNOAUX)
'/****************************************************************************

'                        Auxiliary audio support

'****************************************************************************/

'/* device ID for aux device mapper */
%AUX_MAPPER = &HFFFFFFFF???   ' ((UINT)-1)

'/* Auxiliary audio device capabilities structure */

' // Size = 48 bytes
TYPE AUXCAPSA BYTE
   wMid           AS WORD                        ' WORD       wMid                 /* manufacturer ID */
   wPid           AS WORD                        ' WORD       wPid                 /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION  vDriverVersion       /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN       ' CHAR       szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   wTechnology    AS WORD                        ' WORD       wTechnology          /* type of device */
   wReserved1     AS WORD                        ' WORD       wReserved1           /* padding */
   dwSupport      AS DWORD                       ' DWORD      dwSupport            /* functionality supported by driver */
END TYPE

' // Size = 80 bytes
TYPE AUXCAPSW BYTE
   wMid           AS WORD                        ' WORD       wMid                 /* manufacturer ID */
   wPid           AS WORD                        ' WORD       wPid                 /* product ID */
   vDriverVersion AS DWORD                       ' MMVERSION  vDriverVersion       /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR      szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   wTechnology    AS WORD                        ' WORD       wTechnology          /* type of device */
   wReserved      AS WORD                        ' WORD       wReserved1           /* padding */
   dwSupport      AS DWORD                       ' DWORD      dwSupport            /* functionality supported by driver */
END TYPE

MACRO AUXCAPS = AUXCAPSA

' // Size = 96 bytes
TYPE AUXCAPS2A BYTE
   wMid             AS WORD                        ' WORD      wMid                 /* manufacturer ID */
   wPid             AS WORD                        ' WORD      wPid                 /* product ID */
   vDriverVersion   AS DWORD                       ' MMVERSION vDriverVersion       /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN       ' CHAR      szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   wTechnology      AS WORD                        ' WORD      wTechnology          /* type of device */
   dwReserved       AS WORD                        ' WORD      wReserved1           /* padding */
   dwSupport        AS DWORD                       ' DWORD     dwSupport            /* functionality supported by driver */
   ManufacturerGuid AS GUID                        ' GUID      ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                        ' GUID      ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                        ' GUID      NameGuid             /* for name lookup in registry */
END TYPE

' // Size = 128 bytes
TYPE AUXCAPS2W BYTE
   wMid             AS WORD                        ' WORD      wMid                 /* manufacturer ID */
   wPid             AS WORD                        ' WORD      wPid                 /* product ID */
   vDriverVersion   AS DWORD                       ' MMVERSION vDriverVersion       /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR     szPname[MAXPNAMELEN] /* product name (NULL terminated string) */
   wTechnology      AS WORD                        ' WORD      wTechnology          /* type of device */
   dwReserved       AS WORD                        ' WORD      wReserved1           /* padding */
   dwSupport        AS DWORD                       ' DWORD     dwSupport            /* functionality supported by driver */
   ManufacturerGuid AS GUID                        ' GUID      ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                        ' GUID      ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                        ' GUID      NameGuid             /* for name lookup in registry */
END TYPE

MACRO AUXCAPS2 = AUXCAPS2A

'/* flags for wTechnology field in AUXCAPS structure */
%AUXCAPS_CDAUDIO = 1  ' audio from internal CD-ROM drive
%AUXCAPS_AUXIN   = 2  ' audio from auxiliary input jacks

'/* flags for dwSupport field in AUXCAPS structure */
%AUXCAPS_VOLUME   = &H001???         ' supports volume control
%AUXCAPS_LRVOLUME = &H002???         ' separate left-right volume control

'/* auxiliary audio function prototypes */

DECLARE FUNCTION auxGetNumDevs IMPORT "WINMM.DLL" ALIAS "auxGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION auxGetDevCapsA IMPORT "WINMM.DLL" ALIAS "auxGetDevCapsA" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pac AS AUXCAPSA _                              ' __out LPAUXCAPSA pac
 , BYVAL cbac AS DWORD _                                ' __in UINT cbac
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION auxGetDevCapsW IMPORT "WINMM.DLL" ALIAS "auxGetDevCapsW" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT_PTR uDeviceID
 , BYREF pac AS AUXCAPSW _                              ' __out LPAUXCAPSW pac
 , BYVAL cbac AS DWORD _                                ' __in UINT cbac
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO auxGetDevCaps = auxGetDevCapsW
#ELSE
   MACRO auxGetDevCaps = auxGetDevCapsA
#ENDIF

DECLARE FUNCTION auxSetVolume IMPORT "WINMM.DLL" ALIAS "auxSetVolume" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYVAL dwVolume AS DWORD _                            ' __in DWORD dwVolume
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION auxGetVolume IMPORT "WINMM.DLL" ALIAS "auxGetVolume" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYREF pdwVolume AS DWORD _                           ' __out LPDWORD pdwVolume
 ) AS LONG                                              ' MMRESULT

'#if (WINVER >= 0x030a)
DECLARE FUNCTION auxOutMessage IMPORT "WINMM.DLL" ALIAS "auxOutMessage" ( _
   BYVAL uDeviceID AS DWORD _                           ' __in UINT uDeviceID
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dw1 AS DWORD _                                 ' __in DWORD_PTR dw1
 , BYVAL dw2 AS DWORD _                                 ' __in DWORD_PTR dw2
 ) AS LONG                                              ' MMRESULT
'#endif /* ifdef WINVER >= 0x030a */

#ENDIF   ' /* ifndef MMNOAUX */


#IF NOT %DEF(%MMNOMIXER)
'/****************************************************************************

'                            Mixer Support

'****************************************************************************/

'DECLARE_HANDLE(HMIXEROBJ);
'typedef HMIXEROBJ FAR *LPHMIXEROBJ;

'DECLARE_HANDLE(HMIXER);
'typedef HMIXER     FAR *LPHMIXER;

%MIXER_SHORT_NAME_CHARS = 16
%MIXER_LONG_NAME_CHARS  = 64

'/* */
'/*  MMRESULT error return values specific to the mixer API */
'/* */
'/* */
%MIXERR_INVALLINE    = %MIXERR_BASE + 0
%MIXERR_INVALCONTROL = %MIXERR_BASE + 1
%MIXERR_INVALVALUE   = %MIXERR_BASE + 2
%MIXERR_LASTERROR    = %MIXERR_BASE + 2

%MIXER_OBJECTF_HANDLE    = &H80000000???
%MIXER_OBJECTF_MIXER     = &H00000000???
%MIXER_OBJECTF_HMIXER    = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIXER
%MIXER_OBJECTF_WAVEOUT   = &H10000000???
%MIXER_OBJECTF_HWAVEOUT  = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEOUT
%MIXER_OBJECTF_WAVEIN    = &H20000000???
%MIXER_OBJECTF_HWAVEIN   = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_WAVEIN
%MIXER_OBJECTF_MIDIOUT   = &H30000000???
%MIXER_OBJECTF_HMIDIOUT  = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIOUT
%MIXER_OBJECTF_MIDIIN    = &H40000000???
%MIXER_OBJECTF_HMIDIIN   = %MIXER_OBJECTF_HANDLE OR %MIXER_OBJECTF_MIDIIN
%MIXER_OBJECTF_AUX       = &H50000000???


DECLARE FUNCTION mixerGetNumDevs IMPORT "WINMM.DLL" ALIAS "mixerGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

' // Size = 48 bytes
TYPE MIXERCAPSA BYTE
   wMid           AS WORD                       ' WORD      wMid                 /* manufacturer id */
   wPid           AS WORD                       ' WORD      wPid                 /* product id */
   vDriverVersion AS DWORD                      ' MMVERSION vDriverVersion       /* version of the driver */
   szPname        AS ASCIIZ * %MAXPNAMELEN      ' CHAR      szPname[MAXPNAMELEN] /* product name */
   fdwSupport     AS DWORD                      ' DWORD     fdwSupport           /* misc. support bits */
   cDestinations  AS DWORD                      ' DWORD     cDestinations        /* count of destinations */
END TYPE

' // Size = 80 bytes
TYPE MIXERCAPSW BYTE
   wMid           AS WORD                       ' WORD      wMid                 /* manufacturer id */
   wPid           AS WORD                       ' WORD      wPid                 /* product id */
   vDriverVersion AS DWORD                      ' MMVERSION vDriverVersion       /* version of the driver */
   szPname        AS WSTRINGZ * %MAXPNAMELEN    ' WCHAR     szPname[MAXPNAMELEN] /* product name */
   fdwSupport     AS DWORD                      ' DWORD     fdwSupport           /* misc. support bits */
   cDestinations  AS DWORD                      ' DWORD     cDestinations        /* count of destinations */
END TYPE

MACRO MIXERCAPS = MIXERCAPSA

' // Size = 96 bytes
TYPE MIXERCAPS2A BYTE
   wMid             AS WORD                        ' WORD      wMid                 /* manufacturer id */
   wPid             AS WORD                        ' WORD      wPid                 /* product id */
   vDriverVersion   AS DWORD                       ' MMVERSION vDriverVersion       /* version of the driver */
   szPname          AS ASCIIZ * %MAXPNAMELEN       ' CHAR      szPname[MAXPNAMELEN] /* product name */
   fdwSupport       AS DWORD                       ' DWORD     fdwSupport           /* misc. support bits */
   cDestinations    AS DWORD                       ' DWORD     cDestinations        /* count of destinations */
   ManufacturerGuid AS GUID                        ' GUID      ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                        ' GUID      ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                        ' GUID      NameGuid             /* for name lookup in registry */
END TYPE

' // Size = 96 bytes
TYPE MIXERCAPS2W BYTE
   wMid             AS WORD                        ' WORD      wMid                 /* manufacturer id */
   wPid             AS WORD                        ' WORD      wPid                 /* product id */
   vDriverVersion   AS DWORD                       ' MMVERSION vDriverVersion       /* version of the driver */
   szPname          AS WSTRINGZ * %MAXPNAMELEN     ' WCHAR     szPname[MAXPNAMELEN] /* product name */
   fdwSupport       AS DWORD                       ' DWORD     fdwSupport           /* misc. support bits */
   cDestinations    AS DWORD                       ' DWORD     cDestinations        /* count of destinations */
   ManufacturerGuid AS GUID                        ' GUID      ManufacturerGuid     /* for extensible MID mapping */
   ProductGuid      AS GUID                        ' GUID      ProductGuid          /* for extensible PID mapping */
   NameGuid         AS GUID                        ' GUID      NameGuid             /* for name lookup in registry */
END TYPE

MACRO MIXERCAPS2 = MIXERCAPS2A

DECLARE FUNCTION mixerGetDevCapsA IMPORT "WINMM.DLL" ALIAS "mixerGetDevCapsA" ( _
   BYVAL uMxId AS DWORD _                               ' __in UINT_PTR uMxId
 , BYREF pmxcaps AS MIXERCAPSA _                        ' __out LPMIXERCAPSA pmxcaps
 , BYVAL cbmxcaps AS DWORD _                            ' __in UINT cbmxcaps
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerGetDevCapsW IMPORT "WINMM.DLL" ALIAS "mixerGetDevCapsW" ( _
   BYVAL uMxId AS DWORD _                               ' __in UINT_PTR uMxId
 , BYREF pmxcaps AS MIXERCAPSW _                        ' __out LPMIXERCAPSW pmxcaps
 , BYVAL cbmxcaps AS DWORD _                            ' __in UINT cbmxcaps
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO mixerGetDevCaps = mixerGetDevCapsW
#ELSE
   MACRO mixerGetDevCaps = mixerGetDevCapsA
#ENDIF

DECLARE FUNCTION mixerOpen IMPORT "WINMM.DLL" ALIAS "mixerOpen" ( _
   BYREF phmx AS DWORD _                                ' __out LPHMIXER phmx
 , BYVAL uMxId AS DWORD _                               ' __in UINT uMxId
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR dwCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerClose IMPORT "WINMM.DLL" ALIAS "mixerClose" ( _
   BYVAL hmx AS DWORD _                                 ' __in_out HMIXER hmx
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerMessage IMPORT "WINMM.DLL" ALIAS "mixerMessage" ( _
   BYVAL hmx AS DWORD _                                 ' __in HMIXER hmx
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dwParam1 AS DWORD _                            ' __in DWORD_PTR dwParam1
 , BYVAL dwParam2 AS DWORD _                            ' __in DWORD_PTR dwParam2
 ) AS DWORD                                             ' DWORD


'typedef struct tagMIXERLINEA {
'    DWORD       cbStruct;               /* size of MIXERLINE structure */
'    DWORD       dwDestination;          /* zero based destination index */
'    DWORD       dwSource;               /* zero based source index (if source) */
'    DWORD       dwLineID;               /* unique line id for mixer device */
'    DWORD       fdwLine;                /* state/information about line */
'    DWORD_PTR   dwUser;                 /* driver specific information */
'    DWORD       dwComponentType;        /* component type line connects to */
'    DWORD       cChannels;              /* number of channels line supports */
'    DWORD       cConnections;           /* number of connections [possible] */
'    DWORD       cControls;              /* number of controls at this line */
'    CHAR        szShortName[MIXER_SHORT_NAME_CHARS];
'    CHAR        szName[MIXER_LONG_NAME_CHARS];
'    struct {
'        DWORD       dwType;                 /* MIXERLINE_TARGETTYPE_xxxx */
'        DWORD       dwDeviceID;             /* target device ID of device type */
'        WORD        wMid;                   /* of target device */
'        WORD        wPid;                   /*      " */
'        MMVERSION   vDriverVersion;         /*      " */
'        CHAR        szPname[MAXPNAMELEN];   /*      " */
'    } Target;
'} MIXERLINEA, *PMIXERLINEA, *LPMIXERLINEA;

' // Size = 48 bytes
TYPE MIXERLINE_Target BYTE
   dwType          AS DWORD                  ' DWORD       dwType                 /* MIXERLINE_TARGETTYPE_xxxx */
   dwDeviceID      AS DWORD                  ' DWORD       dwDeviceID             /* target device ID of device type */
   wMid            AS WORD                   ' WORD        wMid                   /* of target device */
   wPid            AS WORD                   ' WORD        wPid                   /*      " */
   vDriverVersion  AS DWORD                  ' MMVERSION   vDriverVersion         /*      " */
   szPname         AS ASCIIZ * %MAXPNAMELEN  ' CHAR        szPname[MAXPNAMELEN]   /*      " */
END TYPE

' // Size = 168 bytes
TYPE MIXERLINEA BYTE
   cbStruct        AS DWORD                             ' DWORD       cbStruct;               /* size of MIXERLINE structure */
   dwDestination   AS DWORD                             ' DWORD       dwDestination;          /* zero based destination index */
   dwSource        AS DWORD                             ' DWORD       dwSource;               /* zero based source index (if source) */
   dwLineID        AS DWORD                             ' DWORD       dwLineID;               /* unique line id for mixer device */
   fdwLine         AS DWORD                             ' DWORD       fdwLine;                /* state/information about line */
   dwUser          AS DWORD                             ' DWORD_PTR   dwUser;                 /* driver specific information */
   dwComponentType AS DWORD                             ' DWORD       dwComponentType;        /* component type line connects to */
   cChannels       AS DWORD                             ' DWORD       cChannels;              /* number of channels line supports */
   cConnections    AS DWORD                             ' DWORD       cConnections;           /* number of connections [possible] */
   cControls       AS DWORD                             ' DWORD       cControls;              /* number of controls at this line */
   szShortName     AS ASCIIZ * %MIXER_SHORT_NAME_CHARS  ' CHAR        szShortName[MIXER_SHORT_NAME_CHARS];
   szName          AS ASCIIZ * %MIXER_LONG_NAME_CHARS   ' CHAR        szName[MIXER_LONG_NAME_CHARS];
   lpTarget        AS MIXERLINE_Target
END TYPE

' // Size = 80 bytes
TYPE MIXERLINE_TargetW BYTE
   dwType          AS DWORD                      ' DWORD       dwType                 /* MIXERLINE_TARGETTYPE_xxxx */
   dwDeviceID      AS DWORD                      ' DWORD       dwDeviceID             /* target device ID of device type */
   wMid            AS WORD                       ' WORD        wMid                   /* of target device */
   wPid            AS WORD                       ' WORD        wPid                   /*      " */
   vDriverVersion  AS DWORD                      ' MMVERSION   vDriverVersion         /*      " */
   szPname         AS WSTRINGZ * %MAXPNAMELEN    ' WCHAR        szPname[MAXPNAMELEN]   /*      " */
END TYPE

'typedef struct tagMIXERLINEW {
'    DWORD       cbStruct;               /* size of MIXERLINE structure */
'    DWORD       dwDestination;          /* zero based destination index */
'    DWORD       dwSource;               /* zero based source index (if source) */
'    DWORD       dwLineID;               /* unique line id for mixer device */
'    DWORD       fdwLine;                /* state/information about line */
'    DWORD_PTR   dwUser;                 /* driver specific information */
'    DWORD       dwComponentType;        /* component type line connects to */
'    DWORD       cChannels;              /* number of channels line supports */
'    DWORD       cConnections;           /* number of connections [possible] */
'    DWORD       cControls;              /* number of controls at this line */
'    WCHAR       szShortName[MIXER_SHORT_NAME_CHARS];
'    WCHAR       szName[MIXER_LONG_NAME_CHARS];
'    struct {
'        DWORD       dwType;                 /* MIXERLINE_TARGETTYPE_xxxx */
'        DWORD       dwDeviceID;             /* target device ID of device type */
'        WORD        wMid;                   /* of target device */
'        WORD        wPid;                   /*      " */
'        MMVERSION   vDriverVersion;         /*      " */
'        WCHAR       szPname[MAXPNAMELEN];   /*      " */
'    } Target;
'} MIXERLINEW, *PMIXERLINEW, *LPMIXERLINEW;

' // Size = 280 bytes
TYPE MIXERLINEW BYTE
   cbStruct        AS DWORD                                ' DWORD       cbStruct;               /* size of MIXERLINE structure */
   dwDestination   AS DWORD                                ' DWORD       dwDestination;          /* zero based destination index */
   dwSource        AS DWORD                                ' DWORD       dwSource;               /* zero based source index (if source) */
   dwLineID        AS DWORD                                ' DWORD       dwLineID;               /* unique line id for mixer device */
   fdwLine         AS DWORD                                ' DWORD       fdwLine;                /* state/information about line */
   dwUser          AS DWORD                                ' DWORD_PTR   dwUser;                 /* driver specific information */
   dwComponentType AS DWORD                                ' DWORD       dwComponentType;        /* component type line connects to */
   cChannels       AS DWORD                                ' DWORD       cChannels;              /* number of channels line supports */
   cConnections    AS DWORD                                ' DWORD       cConnections;           /* number of connections [possible] */
   cControls       AS DWORD                                ' DWORD       cControls;              /* number of controls at this line */
   szShortName     AS WSTRINGZ * %MIXER_SHORT_NAME_CHARS   ' WCHAR        szShortName[MIXER_SHORT_NAME_CHARS];
   szName          AS WSTRINGZ * %MIXER_LONG_NAME_CHARS     ' WCHAR        szName[MIXER_LONG_NAME_CHARS];
   lpTarget        AS MIXERLINE_TargetW
END TYPE

MACRO MIXERLINE = MIXERLINEA

'/* */
'/*  MIXERLINE.fdwLine */
'/* */
'/* */
%MIXERLINE_LINEF_ACTIVE       = &H00000001???
%MIXERLINE_LINEF_DISCONNECTED = &H00008000???
%MIXERLINE_LINEF_SOURCE       = &H80000000???

'/* */
'/*  MIXERLINE.dwComponentType */
'/* */
'/*  component types for destinations and sources */
'/* */
'/* */
%MIXERLINE_COMPONENTTYPE_DST_FIRST       = &H00000000???
%MIXERLINE_COMPONENTTYPE_DST_UNDEFINED   = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 0
%MIXERLINE_COMPONENTTYPE_DST_DIGITAL     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 1
%MIXERLINE_COMPONENTTYPE_DST_LINE        = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 2
%MIXERLINE_COMPONENTTYPE_DST_MONITOR     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 3
%MIXERLINE_COMPONENTTYPE_DST_SPEAKERS    = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 4
%MIXERLINE_COMPONENTTYPE_DST_HEADPHONES  = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 5
%MIXERLINE_COMPONENTTYPE_DST_TELEPHONE   = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 6
%MIXERLINE_COMPONENTTYPE_DST_WAVEIN      = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 7
%MIXERLINE_COMPONENTTYPE_DST_VOICEIN     = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8
%MIXERLINE_COMPONENTTYPE_DST_LAST        = %MIXERLINE_COMPONENTTYPE_DST_FIRST + 8

%MIXERLINE_COMPONENTTYPE_SRC_FIRST       = &H00001000???
%MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0
%MIXERLINE_COMPONENTTYPE_SRC_DIGITAL     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1
%MIXERLINE_COMPONENTTYPE_SRC_LINE        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2
%MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE  = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3
%MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4
%MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5
%MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6
%MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7
%MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT     = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8
%MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY   = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9
%MIXERLINE_COMPONENTTYPE_SRC_ANALOG      = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10
%MIXERLINE_COMPONENTTYPE_SRC_LAST        = %MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10


'/* */
'/*  MIXERLINE.Target.dwType */
'/* */
'/* */
%MIXERLINE_TARGETTYPE_UNDEFINED = 0
%MIXERLINE_TARGETTYPE_WAVEOUT   = 1
%MIXERLINE_TARGETTYPE_WAVEIN    = 2
%MIXERLINE_TARGETTYPE_MIDIOUT   = 3
%MIXERLINE_TARGETTYPE_MIDIIN    = 4
%MIXERLINE_TARGETTYPE_AUX       = 5


'#ifdef _WIN32

DECLARE FUNCTION mixerGetLineInfoA IMPORT "WINMM.DLL" ALIAS "mixerGetLineInfoA" ( _
   BYVAL hmxobj AS DWORD _                              ' __in_opt HMIXEROBJ hmxobj
 , BYREF pmxl AS MIXERLINEA _                           ' __out LPMIXERLINEA pmxl
 , BYVAL fdwInfo AS DWORD _                             ' __in DWORD fdwInfo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerGetLineInfoW IMPORT "WINMM.DLL" ALIAS "mixerGetLineInfoW" ( _
   BYVAL hmxobj AS DWORD _                              ' __in_opt HMIXEROBJ hmxobj
 , BYREF pmxl AS MIXERLINEW _                           ' __out LPMIXERLINEW pmxl
 , BYVAL fdwInfo AS DWORD _                             ' __in DWORD fdwInfo
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO mixerGetLineInfo = mixerGetLineInfoW
#ELSE
   MACRO mixerGetLineInfo = mixerGetLineInfoA
#ENDIF

%MIXER_GETLINEINFOF_DESTINATION   = &H00000000&
%MIXER_GETLINEINFOF_SOURCE        = &H00000001&
%MIXER_GETLINEINFOF_LINEID        = &H00000002&
%MIXER_GETLINEINFOF_COMPONENTTYPE = &H00000003&
%MIXER_GETLINEINFOF_TARGETTYPE    = &H00000004&
%MIXER_GETLINEINFOF_QUERYMASK     = &H0000000F&


DECLARE FUNCTION mixerGetID IMPORT "WINMM.DLL" ALIAS "mixerGetID" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF puMxId AS DWORD _                              ' __out UINT FAR *puMxId
 , BYVAL fdwId AS DWORD _                               ' __in DWORD fdwId
 ) AS LONG                                              ' MMRESULT


'/* */
'/*  MIXERCONTROL */
'/* */
'/* */
'#ifdef _WIN32

'typedef struct tagMIXERCONTROLA {
'    DWORD           cbStruct;           /* size in bytes of MIXERCONTROL */
'    DWORD           dwControlID;        /* unique control id for mixer device */
'    DWORD           dwControlType;      /* MIXERCONTROL_CONTROLTYPE_xxx */
'    DWORD           fdwControl;         /* MIXERCONTROL_CONTROLF_xxx */
'    DWORD           cMultipleItems;     /* if MIXERCONTROL_CONTROLF_MULTIPLE set */
'    CHAR            szShortName[MIXER_SHORT_NAME_CHARS];
'    CHAR            szName[MIXER_LONG_NAME_CHARS];
'    union {
'        struct {
'            LONG    lMinimum;           /* signed minimum for this control */
'            LONG    lMaximum;           /* signed maximum for this control */
'        } DUMMYSTRUCTNAME;
'        struct {
'            DWORD   dwMinimum;          /* unsigned minimum for this control */
'            DWORD   dwMaximum;          /* unsigned maximum for this control */
'        } DUMMYSTRUCTNAME2;
'        DWORD       dwReserved[6];
'    } Bounds;
'    union {
'        DWORD       cSteps;             /* # of steps between min & max */
'        DWORD       cbCustomData;       /* size in bytes of custom data */
'        DWORD       dwReserved[6];      /* !!! needed? we have cbStruct.... */
'    } Metrics;
'} MIXERCONTROLA, *PMIXERCONTROLA, *LPMIXERCONTROLA;

' // Size = 8 bytes
TYPE MIXERCONTROL_lBounds BYTE
   lMinimum AS LONG     ' LONG    lMinimum  /* signed minimum for this control */
   lMaximum AS LONG     ' LONG    lMaximum  /* signed maximum for this control */
END TYPE

' // Size = 8 bytes
TYPE MIXERCONTROL_dwBounds BYTE
   dwMinimum AS DWORD   ' DWORD   dwMinimum  /* unsigned minimum for this control */
   dwMaximum AS DWORD   ' DWORD   dwMaximum  /* unsigned maximum for this control */
END TYPE

' // Size = 24 bytes
UNION MIXERCONTROL_Bounds BYTE
   lMinMax  AS MIXERCONTROL_lBounds
   dwMinMax AS MIXERCONTROL_dwBounds
   dwReserved(5) AS DWORD               ' DWORD       dwReserved[6]
END UNION

' // Size = 24 bytes
UNION MIXERCONTROL_Metrics BYTE
   cSteps        AS DWORD   ' DWORD cSteps;        /* # of steps between min & max */
   cbCustomData  AS DWORD   ' DWORD cbCustomData   /* size in bytes of custom data */
   dwReserved(5) AS DWORD   ' DWORD dwReserved[6]  /* !!! needed? we have cbStruct.... */
END UNION

' // Size = 148 bytes
TYPE MIXERCONTROLA BYTE
   cbStruct       AS DWORD                              ' DWORD           cbStruct           /* size in bytes of MIXERCONTROL */
   dwControlID    AS DWORD                              ' DWORD           dwControlID        /* unique control id for mixer device */
   dwControlType  AS DWORD                              ' DWORD           dwControlType      /* MIXERCONTROL_CONTROLTYPE_xxx */
   fdwControl     AS DWORD                              ' DWORD           fdwControl         /* MIXERCONTROL_CONTROLF_xxx */
   cMultipleItems AS DWORD                              ' DWORD           cMultipleItems     /* if MIXERCONTROL_CONTROLF_MULTIPLE set */
   szShortName    AS ASCIIZ * %MIXER_SHORT_NAME_CHARS   ' CHAR            szShortName[MIXER_SHORT_NAME_CHARS]
   szName         AS ASCIIZ * %MIXER_LONG_NAME_CHARS    ' CHAR            szName[MIXER_LONG_NAME_CHARS]
   Bounds         AS MIXERCONTROL_Bounds
   Metrics        AS MIXERCONTROL_Metrics
END TYPE

'typedef struct tagMIXERCONTROLW {
'    DWORD           cbStruct;           /* size in bytes of MIXERCONTROL */
'    DWORD           dwControlID;        /* unique control id for mixer device */
'    DWORD           dwControlType;      /* MIXERCONTROL_CONTROLTYPE_xxx */
'    DWORD           fdwControl;         /* MIXERCONTROL_CONTROLF_xxx */
'    DWORD           cMultipleItems;     /* if MIXERCONTROL_CONTROLF_MULTIPLE set */
'    WCHAR           szShortName[MIXER_SHORT_NAME_CHARS];
'    WCHAR           szName[MIXER_LONG_NAME_CHARS];
'    union {
'        struct {
'            LONG    lMinimum;           /* signed minimum for this control */
'            LONG    lMaximum;           /* signed maximum for this control */
'        } DUMMYSTRUCTNAME;
'        struct {
'            DWORD   dwMinimum;          /* unsigned minimum for this control */
'            DWORD   dwMaximum;          /* unsigned maximum for this control */
'        } DUMMYSTRUCTNAME2;
'        DWORD       dwReserved[6];
'    } Bounds;
'    union {
'        DWORD       cSteps;             /* # of steps between min & max */
'        DWORD       cbCustomData;       /* size in bytes of custom data */
'        DWORD       dwReserved[6];      /* !!! needed? we have cbStruct.... */
'    } Metrics;
'} MIXERCONTROLW, *PMIXERCONTROLW, *LPMIXERCONTROLW;

' // Size = 228 bytes
TYPE MIXERCONTROLW BYTE
   cbStruct       AS DWORD                                  ' DWORD cbStruct        /* size in bytes of MIXERCONTROL */
   dwControlID    AS DWORD                                  ' DWORD dwControlID     /* unique control id for mixer device */
   dwControlType  AS DWORD                                  ' DWORD dwControlType   /* MIXERCONTROL_CONTROLTYPE_xxx */
   fdwControl     AS DWORD                                  ' DWORD fdwControl      /* MIXERCONTROL_CONTROLF_xxx */
   cMultipleItems AS DWORD                                  ' DWORD cMultipleItems  /* if MIXERCONTROL_CONTROLF_MULTIPLE set */
   szShortName    AS WSTRINGZ * %MIXER_SHORT_NAME_CHARS     ' WCHAR szShortName[MIXER_SHORT_NAME_CHARS]
   szName         AS WSTRINGZ * %MIXER_LONG_NAME_CHARS      ' WCHAR szName[MIXER_LONG_NAME_CHARS]
   Bounds         AS MIXERCONTROL_Bounds
   Metrics        AS MIXERCONTROL_Metrics
END TYPE

MACRO MIXERCONTROL = MIXERCONTROLA

'/* */
'/*  MIXERCONTROL.fdwControl */
'/* */
'/* */
%MIXERCONTROL_CONTROLF_UNIFORM     = &H00000001???
%MIXERCONTROL_CONTROLF_MULTIPLE    = &H00000002???
%MIXERCONTROL_CONTROLF_DISABLED    = &H80000000???

'/* */
'/*  MIXERCONTROL_CONTROLTYPE_xxx building block defines */
'/* */
'/* */
%MIXERCONTROL_CT_CLASS_MASK        = &HF0000000???
%MIXERCONTROL_CT_CLASS_CUSTOM      = &H00000000???
%MIXERCONTROL_CT_CLASS_METER       = &H10000000???
%MIXERCONTROL_CT_CLASS_SWITCH      = &H20000000???
%MIXERCONTROL_CT_CLASS_NUMBER      = &H30000000???
%MIXERCONTROL_CT_CLASS_SLIDER      = &H40000000???
%MIXERCONTROL_CT_CLASS_FADER       = &H50000000???
%MIXERCONTROL_CT_CLASS_TIME        = &H60000000???
%MIXERCONTROL_CT_CLASS_LIST        = &H70000000???

%MIXERCONTROL_CT_SUBCLASS_MASK     = &H0F000000???

%MIXERCONTROL_CT_SC_SWITCH_BOOLEAN = &H00000000???
%MIXERCONTROL_CT_SC_SWITCH_BUTTON  = &H01000000???

%MIXERCONTROL_CT_SC_METER_POLLED   = &H00000000???

%MIXERCONTROL_CT_SC_TIME_MICROSECS = &H00000000???
%MIXERCONTROL_CT_SC_TIME_MILLISECS = &H01000000???

%MIXERCONTROL_CT_SC_LIST_SINGLE    = &H00000000???
%MIXERCONTROL_CT_SC_LIST_MULTIPLE  = &H01000000???


%MIXERCONTROL_CT_UNITS_MASK        = &H00FF0000???
%MIXERCONTROL_CT_UNITS_CUSTOM      = &H00000000???
%MIXERCONTROL_CT_UNITS_BOOLEAN     = &H00010000???
%MIXERCONTROL_CT_UNITS_SIGNED      = &H00020000???
%MIXERCONTROL_CT_UNITS_UNSIGNED    = &H00030000???
%MIXERCONTROL_CT_UNITS_DECIBELS    = &H00040000??? ' __in 10ths
%MIXERCONTROL_CT_UNITS_PERCENT     = &H00050000??? ' __in 10ths

'/* */
'/*  Commonly used control types for specifying MIXERCONTROL.dwControlType */
'/* */

%MIXERCONTROL_CONTROLTYPE_CUSTOM        = %MIXERCONTROL_CT_CLASS_CUSTOM OR %MIXERCONTROL_CT_UNITS_CUSTOM
%MIXERCONTROL_CONTROLTYPE_BOOLEANMETER  = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_SIGNEDMETER   = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PEAKMETER     = %MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1
%MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER = %MIXERCONTROL_CT_CLASS_METER OR %MIXERCONTROL_CT_SC_METER_POLLED OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_BOOLEAN       = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BOOLEAN OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_ONOFF         = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1
%MIXERCONTROL_CONTROLTYPE_MUTE          = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2
%MIXERCONTROL_CONTROLTYPE_MONO          = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3
%MIXERCONTROL_CONTROLTYPE_LOUDNESS      = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4
%MIXERCONTROL_CONTROLTYPE_STEREOENH     = %MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5
%MIXERCONTROL_CONTROLTYPE_BUTTON        = %MIXERCONTROL_CT_CLASS_SWITCH OR %MIXERCONTROL_CT_SC_SWITCH_BUTTON OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_DECIBELS      = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_DECIBELS
%MIXERCONTROL_CONTROLTYPE_SIGNED        = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_UNSIGNED      = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_PERCENT       = %MIXERCONTROL_CT_CLASS_NUMBER OR %MIXERCONTROL_CT_UNITS_PERCENT
%MIXERCONTROL_CONTROLTYPE_SLIDER        = %MIXERCONTROL_CT_CLASS_SLIDER OR %MIXERCONTROL_CT_UNITS_SIGNED
%MIXERCONTROL_CONTROLTYPE_PAN           = %MIXERCONTROL_CONTROLTYPE_SLIDER + 1
%MIXERCONTROL_CONTROLTYPE_QSOUNDPAN     = %MIXERCONTROL_CONTROLTYPE_SLIDER + 2
%MIXERCONTROL_CONTROLTYPE_FADER         = %MIXERCONTROL_CT_CLASS_FADER OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_VOLUME        = %MIXERCONTROL_CONTROLTYPE_FADER + 1
%MIXERCONTROL_CONTROLTYPE_BASS          = %MIXERCONTROL_CONTROLTYPE_FADER + 2
%MIXERCONTROL_CONTROLTYPE_TREBLE        = %MIXERCONTROL_CONTROLTYPE_FADER + 3
%MIXERCONTROL_CONTROLTYPE_EQUALIZER     = %MIXERCONTROL_CONTROLTYPE_FADER + 4
%MIXERCONTROL_CONTROLTYPE_SINGLESELECT  = %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_SINGLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MUX           = %MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT= %MIXERCONTROL_CT_CLASS_LIST OR %MIXERCONTROL_CT_SC_LIST_MULTIPLE OR %MIXERCONTROL_CT_UNITS_BOOLEAN
%MIXERCONTROL_CONTROLTYPE_MIXER         = %MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1
%MIXERCONTROL_CONTROLTYPE_MICROTIME     = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MICROSECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED
%MIXERCONTROL_CONTROLTYPE_MILLITIME     = %MIXERCONTROL_CT_CLASS_TIME OR %MIXERCONTROL_CT_SC_TIME_MILLISECS OR %MIXERCONTROL_CT_UNITS_UNSIGNED

'/* */
'/*  MIXERLINECONTROLS */
'/* */
'#ifdef _WIN32

'typedef struct tagMIXERLINECONTROLSA {
'    DWORD           cbStruct;       /* size in bytes of MIXERLINECONTROLS */
'    DWORD           dwLineID;       /* line id (from MIXERLINE.dwLineID) */
'    union {
'        DWORD       dwControlID;    /* MIXER_GETLINECONTROLSF_ONEBYID */
'        DWORD       dwControlType;  /* MIXER_GETLINECONTROLSF_ONEBYTYPE */
'    } DUMMYUNIONNAME;
'    DWORD           cControls;      /* count of controls pmxctrl points to */
'    DWORD           cbmxctrl;       /* size in bytes of _one_ MIXERCONTROL */
'    LPMIXERCONTROLA pamxctrl;       /* pointer to first MIXERCONTROL array */
'} MIXERLINECONTROLSA, *PMIXERLINECONTROLSA, *LPMIXERLINECONTROLSA;

' // Size = 4 bytes
UNION MIXERLINECONTROLS_UNION BYTE
   dwControlID   AS DWORD          ' DWORD  dwControlID    /* MIXER_GETLINECONTROLSF_ONEBYID */
   dwControlType AS DWORD          ' DWORD  dwControlType  /* MIXER_GETLINECONTROLSF_ONEBYTYPE */
END UNION

' // Size = 24 bytes
TYPE MIXERLINECONTROLSA BYTE
   cbStruct  AS DWORD              ' DWORD           cbStruct  /* size in bytes of MIXERLINECONTROLS */
   dwLineID  AS DWORD              ' DWORD           dwLineID  /* line id (from MIXERLINE.dwLineID) */
   MIXERLINECONTROLS_UNION
   cControls AS DWORD              ' DWORD           cControls /* count of controls pmxctrl points to */
   cbmxctrl  AS DWORD              ' DWORD           cbmxctrl  /* size in bytes of _one_ MIXERCONTROL */
   pamxctrl  AS MIXERCONTROL PTR   ' LPMIXERCONTROLA pamxctrl  /* pointer to first MIXERCONTROL array */
END TYPE

'typedef struct tagMIXERLINECONTROLSW {
'    DWORD           cbStruct;       /* size in bytes of MIXERLINECONTROLS */
'    DWORD           dwLineID;       /* line id (from MIXERLINE.dwLineID) */
'    union {
'        DWORD       dwControlID;    /* MIXER_GETLINECONTROLSF_ONEBYID */
'        DWORD       dwControlType;  /* MIXER_GETLINECONTROLSF_ONEBYTYPE */
'    } DUMMYUNIONNAME;
'    DWORD           cControls;      /* count of controls pmxctrl points to */
'    DWORD           cbmxctrl;       /* size in bytes of _one_ MIXERCONTROL */
'    LPMIXERCONTROLW pamxctrl;       /* pointer to first MIXERCONTROL array */
'} MIXERLINECONTROLSW, *PMIXERLINECONTROLSW, *LPMIXERLINECONTROLSW;

' // Size = 24 bytes
TYPE MIXERLINECONTROLSW BYTE
   cbStruct  AS DWORD               ' DWORD           cbStruct  /* size in bytes of MIXERLINECONTROLS */
   dwLineID  AS DWORD               ' DWORD           dwLineID  /* line id (from MIXERLINE.dwLineID) */
   MIXERLINECONTROLS_UNION
   cControls AS DWORD               ' DWORD           cControls /* count of controls pmxctrl points to */
   cbmxctrl  AS DWORD               ' DWORD           cbmxctrl  /* size in bytes of _one_ MIXERCONTROL */
   pamxctrl  AS MIXERCONTROLW PTR   ' LPMIXERCONTROLW pamxctrl  /* pointer to first MIXERCONTROL array */
END TYPE

MACRO MIXERLINECONTROLS = MIXERLINECONTROLSA

'/* */
'/* */
'/* */

DECLARE FUNCTION mixerGetLineControlsA IMPORT "WINMM.DLL" ALIAS "mixerGetLineControlsA" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF pmxlc AS MIXERLINECONTROLSA _                  ' __in_out LPMIXERLINECONTROLSA pmxlc
 , BYVAL fdwControls AS DWORD _                         ' __in DWORD fdwControls
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerGetLineControlsW IMPORT "WINMM.DLL" ALIAS "mixerGetLineControlsW" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF pmxlc AS MIXERLINECONTROLSW _                  ' __in_out LPMIXERLINECONTROLSW pmxlc
 , BYVAL fdwControls AS DWORD _                         ' __in DWORD fdwControls
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO mixerGetLineControls = mixerGetLineControlsW
#ELSE
   MACRO mixerGetLineControls = mixerGetLineControlsA
#ENDIF

%MIXER_GETLINECONTROLSF_ALL       = &H00000000???
%MIXER_GETLINECONTROLSF_ONEBYID   = &H00000001???
%MIXER_GETLINECONTROLSF_ONEBYTYPE = &H00000002???

%MIXER_GETLINECONTROLSF_QUERYMASK = &H0000000F???


'typedef struct tMIXERCONTROLDETAILS {
'    DWORD           cbStruct;       /* size in bytes of MIXERCONTROLDETAILS */
'    DWORD           dwControlID;    /* control id to get/set details on */
'    DWORD           cChannels;      /* number of channels in paDetails array */
'    union {
'        HWND        hwndOwner;      /* for MIXER_SETCONTROLDETAILSF_CUSTOM */
'        DWORD       cMultipleItems; /* if _MULTIPLE, the number of items per channel */
'    } DUMMYUNIONNAME;
'    DWORD           cbDetails;      /* size of _one_ details_XX struct */
'    LPVOID          paDetails;      /* pointer to array of details_XX structs */
'} MIXERCONTROLDETAILS, *PMIXERCONTROLDETAILS, FAR *LPMIXERCONTROLDETAILS;

' // Size = 4 bytes
UNION MIXERCONTROLDETAILS_UNION BYTE
   hwndOwner      AS DWORD   ' HWND   hwndOwner      /* for MIXER_SETCONTROLDETAILSF_CUSTOM */
   cMultipleItems AS DWORD   ' DWORD  cMultipleItems /* if _MULTIPLE, the number of items per channel */
END UNION

' // Size = 24 bytes
TYPE MIXERCONTROLDETAILS BYTE
   cbStruct    AS DWORD        ' DWORD  cbStruct       /* size in bytes of MIXERCONTROLDETAILS */
   dwControlID AS DWORD        ' DWORD  dwControlID    /* control id to get/set details on */
   cChannels   AS DWORD        ' DWORD  cChannels      /* number of channels in paDetails array */
   MIXERCONTROLDETAILS_UNION
   cbDetails   AS DWORD        ' DWORD  cbDetails      /* size of _one_ details_XX struct */
   paDetails   AS LONG         ' LPVOID paDetails      /* pointer to array of details_XX structs */
END TYPE

'/* */
'/*  MIXER_GETCONTROLDETAILSF_LISTTEXT */
'/* */
'/* */

' // Size = 72 bytes
TYPE MIXERCONTROLDETAILS_LISTTEXTA BYTE
   dwParam1 AS DWORD                                ' DWORD dwParam1
   dwParam2 AS DWORD                                ' DWORD dwParam2
   szName   AS ASCIIZ * %MIXER_LONG_NAME_CHARS      ' CHAR  szName[MIXER_LONG_NAME_CHARS]
END TYPE

' // Size = 136 bytes
TYPE MIXERCONTROLDETAILS_LISTTEXTW
   dwParam1 AS DWORD                                ' DWORD dwParam1
   dwParam2 AS DWORD                                ' DWORD dwParam2
   szName   AS WSTRINGZ * %MIXER_LONG_NAME_CHARS    ' WCHAR szName[MIXER_LONG_NAME_CHARS]
END TYPE

MACRO MIXERCONTROLDETAILS_LISTTEXT = MIXERCONTROLDETAILS_LISTTEXTA

'/* */
'/*  MIXER_GETCONTROLDETAILSF_VALUE */
'/* */
'/* */

' // Size = 4 bytes
TYPE MIXERCONTROLDETAILS_BOOLEAN BYTE
   fValue AS LONG   ' LONG fValue
END TYPE

' // Size = 4 bytes
TYPE MIXERCONTROLDETAILS_SIGNED BYTE
   lValue AS LONG   ' LONG lValue
END TYPE

' // Size = 4 bytes
TYPE MIXERCONTROLDETAILS_UNSIGNED BYTE
   dwValue AS DWORD   ' DWORD dwValue
END TYPE

DECLARE FUNCTION mixerGetControlDetailsA IMPORT "WINMM.DLL" ALIAS "mixerGetControlDetailsA" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF pmxcd AS MIXERCONTROLDETAILS _                 ' __in_out LPMIXERCONTROLDETAILS pmxcd
 , BYVAL fdwDetails AS DWORD _                          ' __in DWORD fdwDetails
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mixerGetControlDetailsW IMPORT "WINMM.DLL" ALIAS "mixerGetControlDetailsW" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF pmxcd AS MIXERCONTROLDETAILS _                 ' __in_out LPMIXERCONTROLDETAILS pmxcd
 , BYVAL fdwDetails AS DWORD _                          ' __in DWORD fdwDetails
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO mixerGetControlDetails = mixerGetControlDetailsW
#ELSE
   MACRO mixerGetControlDetails = mixerGetControlDetailsA
#ENDIF

%MIXER_GETCONTROLDETAILSF_VALUE     = &H00000000???
%MIXER_GETCONTROLDETAILSF_LISTTEXT  = &H00000001???

%MIXER_GETCONTROLDETAILSF_QUERYMASK = &H0000000F???

DECLARE FUNCTION mixerSetControlDetails IMPORT "WINMM.DLL" ALIAS "mixerSetControlDetails" ( _
   BYVAL hmxobj AS DWORD _                              ' __in HMIXEROBJ hmxobj
 , BYREF pmxcd AS MIXERCONTROLDETAILS _                 ' __in LPMIXERCONTROLDETAILS pmxcd
 , BYVAL fdwDetails AS DWORD _                          ' __in DWORD fdwDetails
 ) AS LONG                                              ' MMRESULT

%MIXER_SETCONTROLDETAILSF_VALUE     = &H00000000???
%MIXER_SETCONTROLDETAILSF_CUSTOM    = &H00000001???

%MIXER_SETCONTROLDETAILSF_QUERYMASK = &H0000000F???

#ENDIF   ' IF NOT %DEF(%MMNOMIXER)


#IF NOT %DEF(%MMNOTIMER)
'/****************************************************************************

'                            Timer support

'****************************************************************************/

'/* timer error return values */
%TIMERR_NOERROR = 0  ' no error
%TIMERR_NOCANDO = %TIMERR_BASE + 1 ' request not completed
%TIMERR_STRUCT  = %TIMERR_BASE + 33 ' time struct size

'/* timer data types */
'typedef void (CALLBACK TIMECALLBACK)(UINT uTimerID, UINT uMsg, DWORD_PTR dwUser, DWORD_PTR dw1, DWORD_PTR dw2);
'DECLARE SUB TIMECALLBACK (BYVAL uTimerID AS DWORD, BYVAL uMsg AS DWORD, BYVAL dwUser AS DWORD, BYVAL dw1 AS DWORD, BYVAL dw2 AS DWORD)

'typedef TIMECALLBACK FAR *LPTIMECALLBACK;

'/* flags for fuEvent parameter of timeSetEvent() function */
%TIME_ONESHOT  = &H0000???  ' program timer for single event
%TIME_PERIODIC = &H0001???  ' program for continuous periodic event

%TIME_CALLBACK_FUNCTION     = &H0000??? ' /* callback is function */
%TIME_CALLBACK_EVENT_SET    = &H0010??? ' /* callback is event - use SetEvent */
%TIME_CALLBACK_EVENT_PULSE  = &H0020??? ' /* callback is event - use PulseEvent */

'#if WINVER >= 0x0501
%TIME_KILL_SYNCHRONOUS      = &H0100??? ' /* This flag prevents the event from occurring */
'                                       ' /* after the user calls timeKillEvent() to */
'                                       ' /* destroy it. */
'#endif // WINVER >= 0x0501


'/* timer device capabilities data structure */
' // Size = 8 bytes
TYPE TIMECAPS BYTE
   wPeriodMin AS DWORD   ' UINT wPeriodMin /* minimum period supported  */
   wPeriodMax AS DWORD   ' UINT wPeriodMax /* maximum period supported  */
END TYPE

'/* timer function prototypes */
DECLARE FUNCTION timeGetSystemTime IMPORT "WINMM.DLL" ALIAS "timeGetSystemTime" ( _
   BYREF pmmt AS MMTIME _                               ' __out LPMMTIME pmmt
 , BYVAL cbmmt AS DWORD _                               ' __in UINT cbmmt
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION timeGetTime IMPORT "WINMM.DLL" ALIAS "timeGetTime" ( _
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION timeSetEvent IMPORT "WINMM.DLL" ALIAS "timeSetEvent" ( _
   BYVAL uDelay AS DWORD _                              ' __in UINT uDelay
 , BYVAL uResolution AS DWORD _                         ' __in UINT uResolution
 , BYVAL fptc AS DWORD _                                ' __in LPTIMECALLBACK fptc
 , BYVAL dwUser AS DWORD _                              ' __in DWORD_PTR dwUser
 , BYVAL fuEvent AS DWORD _                             ' __in UINT fuEvent
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION timeKillEvent IMPORT "WINMM.DLL" ALIAS "timeKillEvent" ( _
   BYVAL uTimerID AS DWORD _                            ' __in UINT uTimerID
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION timeGetDevCaps IMPORT "WINMM.DLL" ALIAS "timeGetDevCaps" ( _
   BYREF ptc AS TIMECAPS _                              ' __out LPTIMECAPS ptc
 , BYVAL cbtc AS DWORD _                                ' __in UINT cbtc
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION timeBeginPeriod IMPORT "WINMM.DLL" ALIAS "timeBeginPeriod" ( _
   BYVAL uPeriod AS DWORD _                             ' __in UINT uPeriod
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION timeEndPeriod IMPORT "WINMM.DLL" ALIAS "timeEndPeriod" ( _
   BYVAL uPeriod AS DWORD _                             ' __in UINT uPeriod
 ) AS LONG                                              ' MMRESULT

#ENDIF   ' /* ifndef MMNOTIMER */

#IF NOT %DEF(%MMNOJOY)
'/****************************************************************************

'                            Joystick support

'****************************************************************************/

'/* joystick error return values */
%JOYERR_NOERROR   = 0  ' no error
%JOYERR_PARMS     = %JOYERR_BASE + 5 ' bad parameters
%JOYERR_NOCANDO   = %JOYERR_BASE + 6 ' request not completed
%JOYERR_UNPLUGGED = %JOYERR_BASE + 7 ' joystick is unplugged

'/* constants used with JOYINFO and JOYINFOEX structures and MM_JOY* messages */
%JOY_BUTTON1         = &H0001???
%JOY_BUTTON2         = &H0002???
%JOY_BUTTON3         = &H0004???
%JOY_BUTTON4         = &H0008???
%JOY_BUTTON1CHG      = &H0100???
%JOY_BUTTON2CHG      = &H0200???
%JOY_BUTTON3CHG      = &H0400???
%JOY_BUTTON4CHG      = &H0800???

'/* constants used with JOYINFOEX */
%JOY_BUTTON5         = &H00000010???
%JOY_BUTTON6         = &H00000020???
%JOY_BUTTON7         = &H00000040???
%JOY_BUTTON8         = &H00000080???
%JOY_BUTTON9         = &H00000100???
%JOY_BUTTON10        = &H00000200???
%JOY_BUTTON11        = &H00000400???
%JOY_BUTTON12        = &H00000800???
%JOY_BUTTON13        = &H00001000???
%JOY_BUTTON14        = &H00002000???
%JOY_BUTTON15        = &H00004000???
%JOY_BUTTON16        = &H00008000???
%JOY_BUTTON17        = &H00010000???
%JOY_BUTTON18        = &H00020000???
%JOY_BUTTON19        = &H00040000???
%JOY_BUTTON20        = &H00080000???
%JOY_BUTTON21        = &H00100000???
%JOY_BUTTON22        = &H00200000???
%JOY_BUTTON23        = &H00400000???
%JOY_BUTTON24        = &H00800000???
%JOY_BUTTON25        = &H01000000???
%JOY_BUTTON26        = &H02000000???
%JOY_BUTTON27        = &H04000000???
%JOY_BUTTON28        = &H08000000???
%JOY_BUTTON29        = &H10000000???
%JOY_BUTTON30        = &H20000000???
%JOY_BUTTON31        = &H40000000???
%JOY_BUTTON32        = &H80000000???

'/* constants used with JOYINFOEX structure */
%JOY_POVCENTERED    = &HFFFF??   ' (WORD) -1
%JOY_POVFORWARD     = 0??
%JOY_POVRIGHT       = 9000??
%JOY_POVBACKWARD    = 18000??
%JOY_POVLEFT        = 27000??

%JOY_RETURNX             = &H00000001???
%JOY_RETURNY             = &H00000002???
%JOY_RETURNZ             = &H00000004???
%JOY_RETURNR             = &H00000008???
%JOY_RETURNU             = &H00000010???    ' /* axis 5 */
%JOY_RETURNV             = &H00000020???    ' /* axis 6 */
%JOY_RETURNPOV           = &H00000040???
%JOY_RETURNBUTTONS       = &H00000080???
%JOY_RETURNRAWDATA       = &H00000100???
%JOY_RETURNPOVCTS        = &H00000200???
%JOY_RETURNCENTERED      = &H00000400???
%JOY_USEDEADZONE         = &H00000800???
%JOY_RETURNALL           = %JOY_RETURNX OR %JOY_RETURNY OR %JOY_RETURNZ OR %JOY_RETURNR OR %JOY_RETURNU OR %JOY_RETURNV OR %JOY_RETURNPOV OR %JOY_RETURNBUTTONS
%JOY_CAL_READALWAYS      = &H00010000???
%JOY_CAL_READXYONLY      = &H00020000???
%JOY_CAL_READ3           = &H00040000???
%JOY_CAL_READ4           = &H00080000???
%JOY_CAL_READXONLY       = &H00100000???
%JOY_CAL_READYONLY       = &H00200000???
%JOY_CAL_READ5           = &H00400000???
%JOY_CAL_READ6           = &H00800000???
%JOY_CAL_READZONLY       = &H01000000???
%JOY_CAL_READRONLY       = &H02000000???
%JOY_CAL_READUONLY       = &H04000000???
%JOY_CAL_READVONLY       = &H08000000???

'/* joystick ID constants */
%JOYSTICKID1 = 0
%JOYSTICKID2 = 1

'/* joystick driver capabilites */
%JOYCAPS_HASZ            = &H0001???
%JOYCAPS_HASR            = &H0002???
%JOYCAPS_HASU            = &H0004???
%JOYCAPS_HASV            = &H0008???
%JOYCAPS_HASPOV          = &H0010???
%JOYCAPS_POV4DIR         = &H0020???
%JOYCAPS_POVCTS          = &H0040???


'/* joystick device capabilities data structure */
'#ifdef _WIN32

'typedef struct tagJOYCAPSA {
'    WORD    wMid;                /* manufacturer ID */
'    WORD    wPid;                /* product ID */
'    CHAR    szPname[MAXPNAMELEN];/* product name (NULL terminated string) */
'    UINT    wXmin;               /* minimum x position value */
'    UINT    wXmax;               /* maximum x position value */
'    UINT    wYmin;               /* minimum y position value */
'    UINT    wYmax;               /* maximum y position value */
'    UINT    wZmin;               /* minimum z position value */
'    UINT    wZmax;               /* maximum z position value */
'    UINT    wNumButtons;         /* number of buttons */
'    UINT    wPeriodMin;          /* minimum message period when captured */
'    UINT    wPeriodMax;          /* maximum message period when captured */
'#if (WINVER >= 0x0400)
'    UINT    wRmin;               /* minimum r position value */
'    UINT    wRmax;               /* maximum r position value */
'    UINT    wUmin;               /* minimum u (5th axis) position value */
'    UINT    wUmax;               /* maximum u (5th axis) position value */
'    UINT    wVmin;               /* minimum v (6th axis) position value */
'    UINT    wVmax;               /* maximum v (6th axis) position value */
'    UINT    wCaps;               /* joystick capabilites */
'    UINT    wMaxAxes;            /* maximum number of axes supported */
'    UINT    wNumAxes;            /* number of axes in use */
'    UINT    wMaxButtons;         /* maximum number of buttons supported */
'    CHAR    szRegKey[MAXPNAMELEN];/* registry key */
'    CHAR    szOEMVxD[MAX_JOYSTICKOEMVXDNAME]; /* OEM VxD in use */
'#endif
'} JOYCAPSA, *PJOYCAPSA, *NPJOYCAPSA, *LPJOYCAPSA;

' // Size = 404 bytes
TYPE JOYCAPSA BYTE
   wMid        AS WORD
   wPid        AS WORD
   szPname     AS ASCIIZ * %MAXPNAMELEN
   wXmin       AS DWORD
   wXmax       AS DWORD
   wYmin       AS DWORD
   wYmax       AS DWORD
   wZmin       AS DWORD
   wZmax       AS DWORD
   wNumButtons AS DWORD
   wPeriodMin  AS DWORD
   wPeriodMax  AS DWORD
   wRmin       AS DWORD
   wRmax       AS DWORD
   wUmin       AS DWORD
   wUmax       AS DWORD
   wVmin       AS DWORD
   wVmax       AS DWORD
   wCaps       AS DWORD
   wMaxAxes    AS DWORD
   wNumAxes    AS DWORD
   wMaxButtons AS DWORD
   szRegKey    AS ASCIIZ * %MAXPNAMELEN
   szOEMVxD    AS ASCIIZ * %MAX_JOYSTICKOEMVXDNAME
END TYPE

'typedef struct tagJOYCAPSW {
'    WORD    wMid;                /* manufacturer ID */
'    WORD    wPid;                /* product ID */
'    WCHAR   szPname[MAXPNAMELEN];/* product name (NULL terminated string) */
'    UINT    wXmin;               /* minimum x position value */
'    UINT    wXmax;               /* maximum x position value */
'    UINT    wYmin;               /* minimum y position value */
'    UINT    wYmax;               /* maximum y position value */
'    UINT    wZmin;               /* minimum z position value */
'    UINT    wZmax;               /* maximum z position value */
'    UINT    wNumButtons;         /* number of buttons */
'    UINT    wPeriodMin;          /* minimum message period when captured */
'    UINT    wPeriodMax;          /* maximum message period when captured */
'#if (WINVER >= 0x0400)
'    UINT    wRmin;               /* minimum r position value */
'    UINT    wRmax;               /* maximum r position value */
'    UINT    wUmin;               /* minimum u (5th axis) position value */
'    UINT    wUmax;               /* maximum u (5th axis) position value */
'    UINT    wVmin;               /* minimum v (6th axis) position value */
'    UINT    wVmax;               /* maximum v (6th axis) position value */
'    UINT    wCaps;               /* joystick capabilites */
'    UINT    wMaxAxes;            /* maximum number of axes supported */
'    UINT    wNumAxes;            /* number of axes in use */
'    UINT    wMaxButtons;         /* maximum number of buttons supported */
'    WCHAR   szRegKey[MAXPNAMELEN];/* registry key */
'    WCHAR   szOEMVxD[MAX_JOYSTICKOEMVXDNAME]; /* OEM VxD in use */
'#endif
'} JOYCAPSW, *PJOYCAPSW, *NPJOYCAPSW, *LPJOYCAPSW;

' // Size = 728 bytes
TYPE JOYCAPSW BYTE
   wMid        AS WORD
   wPid        AS WORD
   szPname     AS WSTRINGZ * %MAXPNAMELEN
   wXmin       AS DWORD
   wXmax       AS DWORD
   wYmin       AS DWORD
   wYmax       AS DWORD
   wZmin       AS DWORD
   wZmax       AS DWORD
   wNumButtons AS DWORD
   wPeriodMin  AS DWORD
   wPeriodMax  AS DWORD
   wRmin       AS DWORD
   wRmax       AS DWORD
   wUmin       AS DWORD
   wUmax       AS DWORD
   wVmin       AS DWORD
   wVmax       AS DWORD
   wCaps       AS DWORD
   wMaxAxes    AS DWORD
   wNumAxes    AS DWORD
   wMaxButtons AS DWORD
   szRegKey    AS WSTRINGZ * %MAXPNAMELEN
   szOEMVxD    AS WSTRINGZ * %MAX_JOYSTICKOEMVXDNAME
END TYPE

MACRO JOYCAPS = JOYCAPSA

'typedef struct tagJOYCAPS2A {
'    WORD    wMid;                /* manufacturer ID */
'    WORD    wPid;                /* product ID */
'    CHAR    szPname[MAXPNAMELEN];/* product name (NULL terminated string) */
'    UINT    wXmin;               /* minimum x position value */
'    UINT    wXmax;               /* maximum x position value */
'    UINT    wYmin;               /* minimum y position value */
'    UINT    wYmax;               /* maximum y position value */
'    UINT    wZmin;               /* minimum z position value */
'    UINT    wZmax;               /* maximum z position value */
'    UINT    wNumButtons;         /* number of buttons */
'    UINT    wPeriodMin;          /* minimum message period when captured */
'    UINT    wPeriodMax;          /* maximum message period when captured */
'    UINT    wRmin;               /* minimum r position value */
'    UINT    wRmax;               /* maximum r position value */
'    UINT    wUmin;               /* minimum u (5th axis) position value */
'    UINT    wUmax;               /* maximum u (5th axis) position value */
'    UINT    wVmin;               /* minimum v (6th axis) position value */
'    UINT    wVmax;               /* maximum v (6th axis) position value */
'    UINT    wCaps;               /* joystick capabilites */
'    UINT    wMaxAxes;            /* maximum number of axes supported */
'    UINT    wNumAxes;            /* number of axes in use */
'    UINT    wMaxButtons;         /* maximum number of buttons supported */
'    CHAR    szRegKey[MAXPNAMELEN];/* registry key */
'    CHAR    szOEMVxD[MAX_JOYSTICKOEMVXDNAME]; /* OEM VxD in use */
'    GUID    ManufacturerGuid;    /* for extensible MID mapping */
'    GUID    ProductGuid;         /* for extensible PID mapping */
'    GUID    NameGuid;            /* for name lookup in registry */
'} JOYCAPS2A, *PJOYCAPS2A, *NPJOYCAPS2A, *LPJOYCAPS2A;

' // Size = 452 bytes
TYPE JOYCAPS2A BYTE
   wMid             AS WORD
   wPid             AS WORD
   szPname          AS ASCIIZ * %MAXPNAMELEN
   wXmin            AS DWORD
   wXmax            AS DWORD
   wYmin            AS DWORD
   wYmax            AS DWORD
   wZmin            AS DWORD
   wZmax            AS DWORD
   wNumButtons      AS DWORD
   wPeriodMin       AS DWORD
   wPeriodMax       AS DWORD
   wRmin            AS DWORD
   wRmax            AS DWORD
   wUmin            AS DWORD
   wUmax            AS DWORD
   wVmin            AS DWORD
   wVmax            AS DWORD
   wCaps            AS DWORD
   wMaxAxes         AS DWORD
   wNumAxes         AS DWORD
   wMaxButtons      AS DWORD
   szRegKey         AS ASCIIZ * %MAXPNAMELEN
   szOEMVxD         AS ASCIIZ * %MAX_JOYSTICKOEMVXDNAME
   ManufacturerGuid AS GUID
   ProductGuid      AS GUID
   NameGuid         AS GUID
END TYPE

'typedef struct tagJOYCAPS2W {
'    WORD    wMid;                /* manufacturer ID */
'    WORD    wPid;                /* product ID */
'    WCHAR   szPname[MAXPNAMELEN];/* product name (NULL terminated string) */
'    UINT    wXmin;               /* minimum x position value */
'    UINT    wXmax;               /* maximum x position value */
'    UINT    wYmin;               /* minimum y position value */
'    UINT    wYmax;               /* maximum y position value */
'    UINT    wZmin;               /* minimum z position value */
'    UINT    wZmax;               /* maximum z position value */
'    UINT    wNumButtons;         /* number of buttons */
'    UINT    wPeriodMin;          /* minimum message period when captured */
'    UINT    wPeriodMax;          /* maximum message period when captured */
'    UINT    wRmin;               /* minimum r position value */
'    UINT    wRmax;               /* maximum r position value */
'    UINT    wUmin;               /* minimum u (5th axis) position value */
'    UINT    wUmax;               /* maximum u (5th axis) position value */
'    UINT    wVmin;               /* minimum v (6th axis) position value */
'    UINT    wVmax;               /* maximum v (6th axis) position value */
'    UINT    wCaps;               /* joystick capabilites */
'    UINT    wMaxAxes;            /* maximum number of axes supported */
'    UINT    wNumAxes;            /* number of axes in use */
'    UINT    wMaxButtons;         /* maximum number of buttons supported */
'    WCHAR   szRegKey[MAXPNAMELEN];/* registry key */
'    WCHAR   szOEMVxD[MAX_JOYSTICKOEMVXDNAME]; /* OEM VxD in use */
'    GUID    ManufacturerGuid;    /* for extensible MID mapping */
'    GUID    ProductGuid;         /* for extensible PID mapping */
'    GUID    NameGuid;            /* for name lookup in registry */
'} JOYCAPS2W, *PJOYCAPS2W, *NPJOYCAPS2W, *LPJOYCAPS2W;

' // Size = 776 bytes
TYPE JOYCAPS2W BYTE
   wMid             AS WORD
   wPid             AS WORD
   szPname          AS WSTRINGZ * %MAXPNAMELEN
   wXmin            AS DWORD
   wXmax            AS DWORD
   wYmin            AS DWORD
   wYmax            AS DWORD
   wZmin            AS DWORD
   wZmax            AS DWORD
   wNumButtons      AS DWORD
   wPeriodMin       AS DWORD
   wPeriodMax       AS DWORD
   wRmin            AS DWORD
   wRmax            AS DWORD
   wUmin            AS DWORD
   wUmax            AS DWORD
   wVmin            AS DWORD
   wVmax            AS DWORD
   wCaps            AS DWORD
   wMaxAxes         AS DWORD
   wNumAxes         AS DWORD
   wMaxButtons      AS DWORD
   szRegKey         AS WSTRINGZ * %MAXPNAMELEN
   szOEMVxD         AS WSTRINGZ * %MAX_JOYSTICKOEMVXDNAME
   ManufacturerGuid AS GUID
   ProductGuid      AS GUID
   NameGuid         AS GUID
END TYPE

MACRO JOYCAPS2 = JOYCAPS2A

'/* joystick information data structure */
'typedef struct joyinfo_tag {
'    UINT wXpos;                 /* x position */
'    UINT wYpos;                 /* y position */
'    UINT wZpos;                 /* z position */
'    UINT wButtons;              /* button states */
'} JOYINFO, *PJOYINFO, NEAR *NPJOYINFO, FAR *LPJOYINFO;

' // Size = 16 bytes
TYPE JOYINFO BYTE
   wXpos    AS DWORD
   wYpos    AS DWORD
   wZpos    AS DWORD
   wButtons AS DWORD
END TYPE

'#if(WINVER >= 0x0400)
'typedef struct joyinfoex_tag {
'    DWORD dwSize;                /* size of structure */
'    DWORD dwFlags;               /* flags to indicate what to return */
'    DWORD dwXpos;                /* x position */
'    DWORD dwYpos;                /* y position */
'    DWORD dwZpos;                /* z position */
'    DWORD dwRpos;                /* rudder/4th axis position */
'    DWORD dwUpos;                /* 5th axis position */
'    DWORD dwVpos;                /* 6th axis position */
'    DWORD dwButtons;             /* button states */
'    DWORD dwButtonNumber;        /* current button number pressed */
'    DWORD dwPOV;                 /* point of view state */
'    DWORD dwReserved1;           /* reserved for communication between winmm & driver */
'    DWORD dwReserved2;           /* reserved for future expansion */
'} JOYINFOEX, *PJOYINFOEX, NEAR *NPJOYINFOEX, FAR *LPJOYINFOEX;
'#endif /* WINVER >= 0x0400 */

' // Size = 52 bytes
TYPE JOYINFOEX BYTE
   dwSize         AS DWORD   ' size of structure
   dwFlags        AS DWORD   ' flags to indicate what to return
   dwXpos         AS DWORD   ' x position
   dwYpos         AS DWORD   ' y position
   dwZpos         AS DWORD   ' z position
   dwRpos         AS DWORD   ' rudder/4th axis position
   dwUpos         AS DWORD   ' 5th axis position
   dwVpos         AS DWORD   ' 6th axis position
   dwButtons      AS DWORD   ' button states
   dwButtonNumber AS DWORD   ' current button number pressed
   dwPOV          AS DWORD   ' point of view state
   dwReserved1    AS DWORD   ' reserved for communication between winmm driver
   dwReserved2    AS DWORD   ' reserved for future expansion
END TYPE

'/* joystick function prototypes */
DECLARE FUNCTION joyGetNumDevs IMPORT "WINMM.DLL" ALIAS "joyGetNumDevs" ( _
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION joyGetDevCapsA IMPORT "WINMM.DLL" ALIAS "joyGetDevCapsA" ( _
   BYVAL uJoyID AS LONG _                               ' __in UINT_PTR uJoyID
 , BYREF pjc AS JOYCAPSA _                              ' __out LPJOYCAPSA pjc
 , BYVAL cbjc AS DWORD _                                ' __in UINT cbjc
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION joyGetDevCapsW IMPORT "WINMM.DLL" ALIAS "joyGetDevCapsW" ( _
   BYVAL uJoyID AS LONG _                               ' __in UINT_PTR uJoyID
 , BYREF pjc AS JOYCAPSW _                              ' __out LPJOYCAPSW pjc
 , BYVAL cbjc AS DWORD _                                ' __in UINT cbjc
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO joyGetDevCaps = joyGetDevCapsW
#ELSE
   MACRO joyGetDevCaps = joyGetDevCapsA
#ENDIF

DECLARE FUNCTION joyGetPos IMPORT "WINMM.DLL" ALIAS "joyGetPos" ( _
   BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 , BYREF pji AS JOYINFO _                               ' __out LPJOYINFO pji
 ) AS LONG                                              ' MMRESULT

'#if(WINVER >= 0x0400)
'WINMMAPI MMRESULT WINAPI joyGetPosEx( IN UINT uJoyID, OUT LPJOYINFOEX pji);
DECLARE FUNCTION joyGetPosEx IMPORT "WINMM.DLL" ALIAS "joyGetPosEx" ( _
   BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 , BYREF pji AS JOYINFOEX _                             ' __out LPJOYINFOEX pji
 ) AS LONG                                              ' MMRESULT
'#endif /* WINVER >= 0x0400 */

DECLARE FUNCTION joyGetThreshold IMPORT "WINMM.DLL" ALIAS "joyGetThreshold" ( _
   BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 , BYREF puThreshold AS DWORD _                         ' __out LPUINT puThreshold
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION joyReleaseCapture IMPORT "WINMM.DLL" ALIAS "joyReleaseCapture" ( _
   BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION joySetCapture IMPORT "WINMM.DLL" ALIAS "joySetCapture" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 , BYVAL uPeriod AS DWORD _                             ' __in UINT uPeriod
 , BYVAL fChanged AS LONG _                             ' __in BOOL fChanged
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION joySetThreshold IMPORT "WINMM.DLL" ALIAS "joySetThreshold" ( _
   BYVAL uJoyID AS DWORD _                              ' __in UINT uJoyID
 , BYVAL uThreshold AS DWORD _                          ' __in UINT uThreshold
 ) AS LONG                                              ' MMRESULT

#ENDIF   ' /* ifndef MMNOJOY */


#IF NOT %DEF(%MMNOMMIO)
'/****************************************************************************

'                        Multimedia File I/O support

'****************************************************************************/

'/* MMIO error return values */
%MMIOERR_BASE             = 256
%MMIOERR_FILENOTFOUND     = %MMIOERR_BASE + 1  ' file not found
%MMIOERR_OUTOFMEMORY      = %MMIOERR_BASE + 2  ' __out of memory
%MMIOERR_CANNOTOPEN       = %MMIOERR_BASE + 3  ' cannot open
%MMIOERR_CANNOTCLOSE      = %MMIOERR_BASE + 4  ' cannot close
%MMIOERR_CANNOTREAD       = %MMIOERR_BASE + 5  ' cannot read
%MMIOERR_CANNOTWRITE      = %MMIOERR_BASE + 6  ' cannot write
%MMIOERR_CANNOTSEEK       = %MMIOERR_BASE + 7  ' cannot seek
%MMIOERR_CANNOTEXPAND     = %MMIOERR_BASE + 8  ' cannot expand file
%MMIOERR_CHUNKNOTFOUND    = %MMIOERR_BASE + 9  ' chunk not found
%MMIOERR_UNBUFFERED       = %MMIOERR_BASE + 10 ' file is unbuffered
%MMIOERR_PATHNOTFOUND     = %MMIOERR_BASE + 11 ' path incorrect
%MMIOERR_ACCESSDENIED     = %MMIOERR_BASE + 12 ' file was protected
%MMIOERR_SHARINGVIOLATION = %MMIOERR_BASE + 13 ' file in use
%MMIOERR_NETWORKERROR     = %MMIOERR_BASE + 14 ' network not responding
%MMIOERR_TOOMANYOPENFILES = %MMIOERR_BASE + 15 ' no more file handles
%MMIOERR_INVALIDFILE      = %MMIOERR_BASE + 16 ' default error file error

'/* MMIO constants */
$CFSEPCHAR               = "+"  ' compound file name separator char.

'/* MMIO data types */
'typedef DWORD           FOURCC;         /* a four character code */
'typedef char _huge *    HPSTR;          /* a huge version of LPSTR */
'DECLARE_HANDLE(HMMIO);                  /* a handle to an open file */
'typedef LRESULT (CALLBACK MMIOPROC)(LPSTR lpmmioinfo, UINT uMsg,
'            LPARAM lParam1, LPARAM lParam2);
'typedef MMIOPROC FAR *LPMMIOPROC;

'DECLARE FUNCTION MMIOPROC (BYREF lpmmioinfo AS ASCIIZ, BYVAL uMsg AS DWORD, BYVAL lParam1 AS LONG, BYVAL lParam2 AS LONG)

'/* general MMIO information data structure */
'typedef struct _MMIOINFO
'{
'        /* general fields */
'        DWORD           dwFlags;        /* general status flags */
'        FOURCC          fccIOProc;      /* pointer to I/O procedure */
'        LPMMIOPROC      pIOProc;        /* pointer to I/O procedure */
'        UINT            wErrorRet;      /* place for error to be returned */
'        HTASK           htask;          /* alternate local task */

'        /* fields maintained by MMIO functions during buffered I/O */
'        LONG            cchBuffer;      /* size of I/O buffer (or 0L) */
'        HPSTR           pchBuffer;      /* start of I/O buffer (or NULL) */
'        HPSTR           pchNext;        /* pointer to next byte to read/write */
'        HPSTR           pchEndRead;     /* pointer to last valid byte to read */
'        HPSTR           pchEndWrite;    /* pointer to last byte to write */
'        LONG            lBufOffset;     /* disk offset of start of buffer */

'        /* fields maintained by I/O procedure */
'        LONG            lDiskOffset;    /* disk offset of next read or write */
'        DWORD           adwInfo[3];     /* data specific to type of MMIOPROC */

'        /* other fields maintained by MMIO */
'        DWORD           dwReserved1;    /* reserved for MMIO use */
'        DWORD           dwReserved2;    /* reserved for MMIO use */
'        HMMIO           hmmio;          /* handle to open file */
'} MMIOINFO, *PMMIOINFO, NEAR *NPMMIOINFO, FAR *LPMMIOINFO;
'typedef const MMIOINFO FAR *LPCMMIOINFO;

' // Size = 72 bytes
TYPE MMIOINFO BYTE
   dwFlags     AS DWORD
   fccIOProc   AS DWORD
   pIOProc     AS LONG
   wErrorRet   AS DWORD
   htask       AS DWORD
   cchBuffer   AS LONG
   pchBuffer   AS ASCIIZ PTR
   pchNext     AS ASCIIZ PTR
   pchEndRead  AS ASCIIZ PTR
   pchEndWrite AS ASCIIZ PTR
   lBufOffset  AS LONG
   lDiskOffset AS LONG
   adwInfo(2)  AS DWORD
   dwReserved1 AS DWORD
   dwReserved2 AS DWORD
   hmmio       AS DWORD
END TYPE

'/* RIFF chunk information data structure */
'typedef struct _MMCKINFO
'{
'        FOURCC          ckid;           /* chunk ID */
'        DWORD           cksize;         /* chunk size */
'        FOURCC          fccType;        /* form type or list type */
'        DWORD           dwDataOffset;   /* offset of data portion of chunk */
'        DWORD           dwFlags;        /* flags used by MMIO functions */
'} MMCKINFO, *PMMCKINFO, NEAR *NPMMCKINFO, FAR *LPMMCKINFO;
'typedef const MMCKINFO *LPCMMCKINFO;

' // Size = 20 bytes
TYPE MMCKINFO BYTE
   ckid         AS DWORD
   ckSize       AS DWORD
   fccType      AS DWORD
   dwDataOffset AS DWORD
   dwFlags      AS DWORD
END TYPE

'/* bit field masks */
%MMIO_RWMODE           = &H00000003???         ' mask to get bits used for opening
%MMIO_SHAREMODE        = &H00000070???        ' file sharing mode number

'/* constants for dwFlags field of MMIOINFO */
%MMIO_CREATE           = &H00001000???  ' create new file (or truncate file)
%MMIO_PARSE            = &H00000100???  ' parse new file returning path
%MMIO_DELETE           = &H00000200???  ' create new file (or truncate file)
%MMIO_EXIST            = &H00004000???  ' checks for existence of file
%MMIO_ALLOCBUF         = &H00010000???  ' mmioOpen() should allocate a buffer
%MMIO_GETTEMP          = &H00020000???  ' mmioOpen() should retrieve temp name

%MMIO_DIRTY            = &H10000000???  ' I/O buffer is dirty

'/* read/write mode numbers (bit field MMIO_RWMODE) */
%MMIO_READ             = &H00000000???      ' open file for reading only
%MMIO_WRITE            = &H00000001???      ' open file for writing only
%MMIO_READWRITE        = &H00000002???      ' open file for reading and writing

'/* share mode numbers (bit field MMIO_SHAREMODE) */
%MMIO_COMPAT           = &H00000000???      ' compatibility mode
%MMIO_EXCLUSIVE        = &H00000010???      ' exclusive-access mode
%MMIO_DENYWRITE        = &H00000020???      ' deny writing to other processes
%MMIO_DENYREAD         = &H00000030???      ' deny reading to other processes
%MMIO_DENYNONE         = &H00000040???      ' deny nothing to other processes

'/* various MMIO flags */
%MMIO_FHOPEN           = &H0010???       ' mmioClose(): keep file xHandle open
%MMIO_EMPTYBUF         = &H0010???       ' mmioFlush(): empty the I/O buffer
%MMIO_TOUPPER          = &H0010???       ' mmioStringToFOURCC(): cvt. to u-case
%MMIO_INSTALLPROC      = &H00010000???   ' mmioInstallIOProc(): install MMIOProc
%MMIO_GLOBALPROC       = &H10000000???   ' mmioInstallIOProc: install Globally
%MMIO_REMOVEPROC       = &H00020000???   ' mmioInstallIOProc(): remove MMIOProc
%MMIO_UNICODEPROC      = &H01000000???   ' mmioInstallIOProc(): Unicode MMIOProc
%MMIO_FINDPROC         = &H00040000???   ' mmioInstallIOProc(): find an MMIOProc
%MMIO_FINDCHUNK        = &H0010???       ' mmioDescend(): find a chunk by ID
%MMIO_FINDRIFF         = &H0020???       ' mmioDescend(): find a LIST chunk
%MMIO_FINDLIST         = &H0040???       ' mmioDescend(): find a RIFF chunk
%MMIO_CREATERIFF       = &H0020???       ' mmioCreateChunk(): make a LIST chunk
%MMIO_CREATELIST       = &H0040???       ' mmioCreateChunk(): make a RIFF chunk

'/* message numbers for MMIOPROC I/O procedure functions */
'#if (WINVER >= 0x030a)
'#define MMIOM_RENAME            6       /* rename specified file */
'#endif /* ifdef WINVER >= 0x030a */

'#define MMIOM_USER         0x8000       /* beginning of user-defined messages */

%MMIOM_READ        = %MMIO_READ  ' read (must equal MMIO_READ!)
%MMIOM_WRITE       = %MMIO_WRITE  ' write (must equal MMIO_WRITE!)
%MMIOM_SEEK        = 2  ' seek to a new position in file
%MMIOM_OPEN        = 3  ' open file
%MMIOM_CLOSE       = 4  ' close file
%MMIOM_WRITEFLUSH  = 5  ' write and flush
%MMIOM_RENAME      = 6  ' rename specified file
%MMIOM_USER        = &H00008000???  ' beginning of user-defined messages

'/* standard four character codes */
'#define FOURCC_RIFF     mmioFOURCC('R', 'I', 'F', 'F')
'#define FOURCC_LIST     mmioFOURCC('L', 'I', 'S', 'T')

%FOURCC_RIFF     = &H46464952
%FOURCC_LIST     = &H5453494C

'/* four character codes used to identify standard built-in I/O procedures */
'#define FOURCC_DOS      mmioFOURCC('D', 'O', 'S', ' ')
'#define FOURCC_MEM      mmioFOURCC('M', 'E', 'M', ' ')

%FOURCC_DOS      = &HFF534F44
%FOURCC_MEM      = &HFF4D454D

'/* flags for mmioSeek() */
#IF NOT %DEF(%SEEK_SET)
%SEEK_SET = 0  ' seek to an absolute position
%SEEK_CUR = 1  ' seek relative to current position
%SEEK_END = 2  ' seek relative to end of file
#ENDIF

'/* other constants */
%MMIO_DEFAULTBUFFER = 8192  ' default buffer size

'/* MMIO macros */
'#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)

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

'/* MMIO function prototypes */

DECLARE FUNCTION mmioStringToFOURCCA IMPORT "WINMM.DLL" ALIAS "mmioStringToFOURCCA" ( _
   BYREF sz AS ASCIIZ _                                 ' __in LPCSTR sz
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' FOURCC

DECLARE FUNCTION mmioStringToFOURCCW IMPORT "WINMM.DLL" ALIAS "mmioStringToFOURCCW" ( _
   BYREF sz AS WSTRINGZ _                               ' __in LPCWSTR sz
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' FOURCC

#IF %DEF(%UNICODE)
   MACRO mmioStringToFOURCC = mmioStringToFOURCCW
#ELSE
   MACRO mmioStringToFOURCC = mmioStringToFOURCCA
#ENDIF

DECLARE FUNCTION mmioInstallIOProcA IMPORT "WINMM.DLL" ALIAS "mmioInstallIOProcA" ( _
   BYVAL fccIOProc AS DWORD _                           ' __in FOURCC fccIOProc
 , BYVAL pIOProc AS DWORD _                             ' __in LPMMIOPROC pIOProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPMMIOPROC

DECLARE FUNCTION mmioInstallIOProcW IMPORT "WINMM.DLL" ALIAS "mmioInstallIOProcW" ( _
   BYVAL fccIOProc AS DWORD _                           ' __in FOURCC fccIOProc
 , BYVAL pIOProc AS DWORD _                             ' __in LPMMIOPROC pIOProc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' LPMMIOPROC

#IF %DEF(%UNICODE)
   MACRO mmioInstallIOProc = mmioInstallIOProcW
#ELSE
   MACRO mmioInstallIOProc = mmioInstallIOProcA
#ENDIF

DECLARE FUNCTION mmioOpenA IMPORT "WINMM.DLL" ALIAS "mmioOpenA" ( _
   BYREF pszFileName AS ASCIIZ _                        ' __in_out LPSTR pszFileName
 , BYREF pmmioinfo AS MMIOINFO _                        ' __in_out LPMMIOINFO pmmioinfo
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS DWORD                                             ' HMMIO

DECLARE FUNCTION mmioOpenW IMPORT "WINMM.DLL" ALIAS "mmioOpenW" ( _
   BYREF pszFileName AS WSTRINGZ _                      ' __in_out LPWSTR pszFileName
 , BYREF pmmioinfo AS MMIOINFO _                        ' __in_out LPMMIOINFO pmmioinfo
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS DWORD                                             ' HMMIO

#IF %DEF(%UNICODE)
   MACRO mmioOpen = mmioOpenW
#ELSE
   MACRO mmioOpen = mmioOpenA
#ENDIF

DECLARE FUNCTION mmioRenameA IMPORT "WINMM.DLL" ALIAS "mmioRenameA" ( _
   BYREF pszFileName AS ASCIIZ _                        ' __in LPCSTR pszFileName
 , BYREF pszNewFileName AS ASCIIZ _                     ' __in LPCSTR pszNewFileName
 , BYREF pmmioinfo AS MMIOINFO _                        ' __in LPCMMIOINFO pmmioinfo
 , BYVAL fdwRename AS DWORD _                           ' __in DWORD fdwRename
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioRenameW IMPORT "WINMM.DLL" ALIAS "mmioRenameW" ( _
   BYREF pszFileName AS WSTRINGZ _                      ' __in LPCWSTR pszFileName
 , BYREF pszNewFileName AS WSTRINGZ _                   ' __in LPCWSTR pszNewFileName
 , BYREF pmmioinfo AS MMIOINFO  _                       ' __in LPCMMIOINFO pmmioinfo
 , BYVAL fdwRename AS DWORD _                           ' __in DWORD fdwRename
 ) AS LONG                                              ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO mmioRename = mmioRenameW
#ELSE
   MACRO mmioRename = mmioRenameA
#ENDIF

DECLARE FUNCTION mmioClose IMPORT "WINMM.DLL" ALIAS "mmioClose" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYVAL fuClose AS DWORD _                             ' __in UINT fuClose
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioRead IMPORT "WINMM.DLL" ALIAS "mmioRead" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pch AS ANY _                                   ' __out HPSTR pch
 , BYVAL cch AS LONG _                                  ' __in LONG cch
 ) AS LONG                                              ' LONG

DECLARE FUNCTION mmioWrite IMPORT "WINMM.DLL" ALIAS "mmioWrite" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pch AS ANY _                                   ' __in const char _huge* pch
 , BYVAL cch AS LONG _                                  ' __in LONG cch
 ) AS LONG                                              ' LONG

DECLARE FUNCTION mmioSeek IMPORT "WINMM.DLL" ALIAS "mmioSeek" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYVAL lOffset AS LONG _                              ' __in LONG lOffset
 , BYVAL iOrigin AS LONG _                              ' __in int iOrigin
 ) AS LONG                                              ' LONG

DECLARE FUNCTION mmioGetInfo IMPORT "WINMM.DLL" ALIAS "mmioGetInfo" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmioinfo AS MMIOINFO _                        ' __out LPMMIOINFO pmmioinfo
 , BYVAL fuInfo AS DWORD _                              ' __in UINT fuInfo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioSetInfo IMPORT "WINMM.DLL" ALIAS "mmioSetInfo" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmioinfo AS MMIOINFO _                        ' __in LPCMMIOINFO pmmioinfo
 , BYVAL fuInfo AS DWORD _                              ' __in UINT fuInfo
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioSetBuffer IMPORT "WINMM.DLL" ALIAS "mmioSetBuffer" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pchBuffer AS ASCIIZ _                          ' __in LPSTR pchBuffer
 , BYVAL cchBuffer AS LONG _                            ' __in LONG cchBuffer
 , BYVAL fuBuffer AS DWORD _                            ' __in UINT fuBuffer
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioFlush IMPORT "WINMM.DLL" ALIAS "mmioFlush" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYVAL fuFlush AS DWORD _                             ' __in UINT fuFlush
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioAdvance IMPORT "WINMM.DLL" ALIAS "mmioAdvance" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmioinfo AS MMIOINFO _                        ' __in_out LPMMIOINFO pmmioinfo
 , BYVAL fuAdvance AS DWORD _                           ' __in UINT fuAdvance
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioSendMessage IMPORT "WINMM.DLL" ALIAS "mmioSendMessage" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION mmioDescend IMPORT "WINMM.DLL" ALIAS "mmioDescend" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmcki AS MMCKINFO _                           ' __in_out LPMMCKINFO pmmcki
 , BYREF pmmckiParent AS MMCKINFO _                     ' __in const MMCKINFO FAR* pmmckiParent
 , BYVAL fuDescend AS DWORD _                           ' __in UINT fuDescend
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioAscend IMPORT "WINMM.DLL" ALIAS "mmioAscend" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmcki AS MMCKINFO _                           ' __in LPMMCKINFO pmmcki
 , BYVAL fuAscend AS DWORD _                            ' __in UINT fuAscend
 ) AS LONG                                              ' MMRESULT

DECLARE FUNCTION mmioCreateChunk IMPORT "WINMM.DLL" ALIAS "mmioCreateChunk" ( _
   BYVAL hmmio AS DWORD _                               ' __in HMMIO hmmio
 , BYREF pmmcki AS MMCKINFO _                           ' __in LPMMCKINFO pmmcki
 , BYVAL fuCreate AS DWORD _                            ' __in UINT fuCreate
 ) AS LONG                                              ' MMRESULT

#ENDIF   ' /* ifndef MMNOMMIO */


#IF NOT %DEF(%MMNOMCI)
'/****************************************************************************

'                            MCI support

'****************************************************************************/

'#ifndef _MCIERROR_              /* MCIERROR is defined in some post 3.1 apps */
'#define _MCIERROR_
'typedef DWORD   MCIERROR;       /* error return code, 0 means no error */
'#endif

'#ifndef _MCIDEVICEID_           /* Same with MCIDEVICEID */
'#define _MCIDEVICEID_
'typedef UINT    MCIDEVICEID;    /* MCI device ID type */
'#endif


'typedef UINT (CALLBACK *YIELDPROC)(MCIDEVICEID mciId, DWORD dwYieldData);
'DECLARE FUNCTION YIELDPROC (BYVAL mciId AS DWORD, BYVAL dwYieldData AS DWORD) AS DWORD

'/* MCI function prototypes */

DECLARE FUNCTION mciSendCommandA IMPORT "WINMM.DLL" ALIAS "mciSendCommandA" ( _
   BYVAL mciId AS DWORD _                               ' __in MCIDEVICEID mciId
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dwParam1 AS DWORD _                            ' __in DWORD dwParam1
 , BYVAL dwParam2 AS DWORD _                            ' __in DWORD dwParam2
 ) AS DWORD                                             ' MCIERROR

DECLARE FUNCTION mciSendCommandW IMPORT "WINMM.DLL" ALIAS "mciSendCommandW" ( _
   BYVAL mciId AS DWORD _                               ' __in MCIDEVICEID mciId
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL dwParam1 AS DWORD _                            ' __in DWORD dwParam1
 , BYVAL dwParam2 AS DWORD _                            ' __in DWORD dwParam2
 ) AS DWORD                                             ' MCIERROR

#IF %DEF(%UNICODE)
   MACRO mciSendCommand = mciSendCommandW
#ELSE
   MACRO mciSendCommand = mciSendCommandA
#ENDIF

DECLARE FUNCTION mciSendStringA IMPORT "WINMM.DLL" ALIAS "mciSendStringA" ( _
   BYREF lpstrCommand AS ASCIIZ _                       ' __in LPCSTR lpstrCommand
 , BYREF lpstrReturnString AS ASCIIZ _                  ' __out LPSTR lpstrReturnString
 , BYVAL uReturnLength AS DWORD _                       ' __in UINT uReturnLength
 , BYVAL hwndCallback AS DWORD _                        ' __in HWND hwndCallback
 ) AS DWORD                                             ' MCIERROR

DECLARE FUNCTION mciSendStringW IMPORT "WINMM.DLL" ALIAS "mciSendStringW" ( _
   BYREF lpstrCommand AS WSTRINGZ _                     ' __in LPCWSTR lpstrCommand
 , BYREF lpstrReturnString AS WSTRINGZ _                ' __out LPWSTR lpstrReturnString
 , BYVAL uReturnLength AS DWORD _                       ' __in UINT uReturnLength
 , BYVAL hwndCallback AS DWORD _                        ' __in HWND hwndCallback
 ) AS DWORD                                             ' MCIERROR

#IF %DEF(%UNICODE)
   MACRO mciSendString = mciSendStringW
#ELSE
   MACRO mciSendString = mciSendStringA
#ENDIF

DECLARE FUNCTION mciGetDeviceIDA IMPORT "WINMM.DLL" ALIAS "mciGetDeviceIDA" ( _
   BYREF pszDevice AS ASCIIZ _                          ' __in LPCSTR pszDevice
 ) AS DWORD                                             ' MCIDEVICEID

DECLARE FUNCTION mciGetDeviceIDW IMPORT "WINMM.DLL" ALIAS "mciGetDeviceIDW" ( _
   BYREF pszDevice AS WSTRINGZ _                        ' __in LPCWSTR pszDevice
 ) AS DWORD                                             ' MCIDEVICEID

#IF %DEF(%UNICODE)
   MACRO mciGetDeviceID = mciGetDeviceIDW
#ELSE
   MACRO mciGetDeviceID = mciGetDeviceIDA
#ENDIF

DECLARE FUNCTION mciGetDeviceIDFromElementIDA IMPORT "WINMM.DLL" ALIAS "mciGetDeviceIDFromElementIDA" ( _
   BYVAL dwElementID AS DWORD _                         ' __in DWORD dwElementID
 , BYREF lpstrType AS ASCIIZ _                          ' __in LPCSTR lpstrType
 ) AS DWORD                                             ' MCIDEVICEID

DECLARE FUNCTION mciGetDeviceIDFromElementIDW IMPORT "WINMM.DLL" ALIAS "mciGetDeviceIDFromElementIDW" ( _
   BYVAL dwElementID AS DWORD _                         ' __in DWORD dwElementID
 , BYREF lpstrType AS WSTRINGZ _                        ' __in LPCWSTR lpstrType
 ) AS DWORD                                             ' MCIDEVICEID

#IF %DEF(%UNICODE)
   MACRO mciGetDeviceIDFromElementID = mciGetDeviceIDFromElementIDW
#ELSE
   MACRO mciGetDeviceIDFromElementID = mciGetDeviceIDFromElementIDA
#ENDIF

DECLARE FUNCTION mciGetErrorStringA IMPORT "WINMM.DLL" ALIAS "mciGetErrorStringA" ( _
   BYVAL mcierr AS DWORD _                              ' __in MCIERROR mcierr
 , BYREF pszText AS ASCIIZ _                            ' __out LPSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION mciGetErrorStringW IMPORT "WINMM.DLL" ALIAS "mciGetErrorStringW" ( _
   BYVAL mcierr AS DWORD _                              ' __in MCIERROR mcierr
 , BYREF pszText AS WSTRINGZ   _                        ' __out LPWSTR pszText
 , BYVAL cchText AS DWORD _                             ' __in UINT cchText
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO mciGetErrorString = mciGetErrorStringW
#ELSE
   MACRO mciGetErrorString = mciGetErrorStringA
#ENDIF

DECLARE FUNCTION mciSetYieldProc IMPORT "WINMM.DLL" ALIAS "mciSetYieldProc" ( _
   BYVAL mciId AS DWORD _                               ' __in MCIDEVICEID mciId
 , BYVAL fpYieldProc AS DWORD _                         ' __in YIELDPROC fpYieldProc
 , BYVAL dwYieldData AS DWORD _                         ' __in DWORD dwYieldData
 ) AS LONG                                              ' BOOL

'#if (WINVER >= 0x030a)
DECLARE FUNCTION mciGetCreatorTask IMPORT "WINMM.DLL" ALIAS "mciGetCreatorTask" ( _
   BYVAL mciId AS DWORD _                               ' __in MCIDEVICEID mciId
 ) AS DWORD                                             ' HTASK

DECLARE FUNCTION mciGetYieldProc IMPORT "WINMM.DLL" ALIAS "mciGetYieldProc" ( _
   BYVAL mciId AS DWORD _                               ' __in MCIDEVICEID mciId
 , BYREF pdwYieldData AS DWORD _                        ' __in LPDWORD pdwYieldData
 ) AS DWORD                                             ' YIELDPROC
'#endif /* ifdef WINVER >= 0x030a */

'#if (WINVER < 0x030a)
DECLARE FUNCTION mciExecute IMPORT "WINMM.DLL" ALIAS "mciExecute" ( _
   BYREF pszCommand AS ASCIIZ _                         ' LPCSTR pszCommand
 ) AS LONG                                              ' BOOL
'#endif /* ifdef WINVER < 0x030a */

'/* MCI error return values */
%MCIERR_INVALID_DEVICE_ID       = %MCIERR_BASE + 1
%MCIERR_UNRECOGNIZED_KEYWORD    = %MCIERR_BASE + 3
%MCIERR_UNRECOGNIZED_COMMAND    = %MCIERR_BASE + 5
%MCIERR_HARDWARE                = %MCIERR_BASE + 6
%MCIERR_INVALID_DEVICE_NAME     = %MCIERR_BASE + 7
%MCIERR_OUT_OF_MEMORY           = %MCIERR_BASE + 8
%MCIERR_DEVICE_OPEN             = %MCIERR_BASE + 9
%MCIERR_CANNOT_LOAD_DRIVER      = %MCIERR_BASE + 10
%MCIERR_MISSING_COMMAND_STRING  = %MCIERR_BASE + 11
%MCIERR_PARAM_OVERFLOW          = %MCIERR_BASE + 12
%MCIERR_MISSING_STRING_ARGUMENT = %MCIERR_BASE + 13
%MCIERR_BAD_INTEGER             = %MCIERR_BASE + 14
%MCIERR_PARSER_INTERNAL         = %MCIERR_BASE + 15
%MCIERR_DRIVER_INTERNAL         = %MCIERR_BASE + 16
%MCIERR_MISSING_PARAMETER       = %MCIERR_BASE + 17
%MCIERR_UNSUPPORTED_FUNCTION    = %MCIERR_BASE + 18
%MCIERR_FILE_NOT_FOUND          = %MCIERR_BASE + 19
%MCIERR_DEVICE_NOT_READY        = %MCIERR_BASE + 20
%MCIERR_INTERNAL                = %MCIERR_BASE + 21
%MCIERR_DRIVER                  = %MCIERR_BASE + 22
%MCIERR_CANNOT_USE_ALL          = %MCIERR_BASE + 23
%MCIERR_MULTIPLE                = %MCIERR_BASE + 24
%MCIERR_EXTENSION_NOT_FOUND     = %MCIERR_BASE + 25
%MCIERR_OUTOFRANGE              = %MCIERR_BASE + 26
%MCIERR_FLAGS_NOT_COMPATIBLE    = %MCIERR_BASE + 28
%MCIERR_FILE_NOT_SAVED          = %MCIERR_BASE + 30
%MCIERR_DEVICE_TYPE_REQUIRED    = %MCIERR_BASE + 31
%MCIERR_DEVICE_LOCKED           = %MCIERR_BASE + 32
%MCIERR_DUPLICATE_ALIAS         = %MCIERR_BASE + 33
%MCIERR_BAD_CONSTANT            = %MCIERR_BASE + 34
%MCIERR_MUST_USE_SHAREABLE      = %MCIERR_BASE + 35
%MCIERR_MISSING_DEVICE_NAME     = %MCIERR_BASE + 36
%MCIERR_BAD_TIME_FORMAT         = %MCIERR_BASE + 37
%MCIERR_NO_CLOSING_QUOTE        = %MCIERR_BASE + 38
%MCIERR_DUPLICATE_FLAGS         = %MCIERR_BASE + 39
%MCIERR_INVALID_FILE            = %MCIERR_BASE + 40
%MCIERR_NULL_PARAMETER_BLOCK    = %MCIERR_BASE + 41
%MCIERR_UNNAMED_RESOURCE        = %MCIERR_BASE + 42
%MCIERR_NEW_REQUIRES_ALIAS      = %MCIERR_BASE + 43
%MCIERR_NOTIFY_ON_AUTO_OPEN     = %MCIERR_BASE + 44
%MCIERR_NO_ELEMENT_ALLOWED      = %MCIERR_BASE + 45
%MCIERR_NONAPPLICABLE_FUNCTION  = %MCIERR_BASE + 46
%MCIERR_ILLEGAL_FOR_AUTO_OPEN   = %MCIERR_BASE + 47
%MCIERR_FILENAME_REQUIRED       = %MCIERR_BASE + 48
%MCIERR_EXTRA_CHARACTERS        = %MCIERR_BASE + 49
%MCIERR_DEVICE_NOT_INSTALLED    = %MCIERR_BASE + 50
%MCIERR_GET_CD                  = %MCIERR_BASE + 51
%MCIERR_SET_CD                  = %MCIERR_BASE + 52
%MCIERR_SET_DRIVE               = %MCIERR_BASE + 53
%MCIERR_DEVICE_LENGTH           = %MCIERR_BASE + 54
%MCIERR_DEVICE_ORD_LENGTH       = %MCIERR_BASE + 55
%MCIERR_NO_INTEGER              = %MCIERR_BASE + 56

%MCIERR_WAVE_OUTPUTSINUSE        = %MCIERR_BASE + 64
%MCIERR_WAVE_SETOUTPUTINUSE      = %MCIERR_BASE + 65
%MCIERR_WAVE_INPUTSINUSE         = %MCIERR_BASE + 66
%MCIERR_WAVE_SETINPUTINUSE       = %MCIERR_BASE + 67
%MCIERR_WAVE_OUTPUTUNSPECIFIED   = %MCIERR_BASE + 68
%MCIERR_WAVE_INPUTUNSPECIFIED    = %MCIERR_BASE + 69
%MCIERR_WAVE_OUTPUTSUNSUITABLE   = %MCIERR_BASE + 70
%MCIERR_WAVE_SETOUTPUTUNSUITABLE = %MCIERR_BASE + 71
%MCIERR_WAVE_INPUTSUNSUITABLE    = %MCIERR_BASE + 72
%MCIERR_WAVE_SETINPUTUNSUITABLE  = %MCIERR_BASE + 73

%MCIERR_SEQ_DIV_INCOMPATIBLE    = %MCIERR_BASE + 80
%MCIERR_SEQ_PORT_INUSE          = %MCIERR_BASE + 81
%MCIERR_SEQ_PORT_NONEXISTENT    = %MCIERR_BASE + 82
%MCIERR_SEQ_PORT_MAPNODEVICE    = %MCIERR_BASE + 83
%MCIERR_SEQ_PORT_MISCERROR      = %MCIERR_BASE + 84
%MCIERR_SEQ_TIMER               = %MCIERR_BASE + 85
%MCIERR_SEQ_PORTUNSPECIFIED     = %MCIERR_BASE + 86
%MCIERR_SEQ_NOMIDIPRESENT       = %MCIERR_BASE + 87

%MCIERR_NO_WINDOW               = %MCIERR_BASE + 90
%MCIERR_CREATEWINDOW            = %MCIERR_BASE + 91
%MCIERR_FILE_READ               = %MCIERR_BASE + 92
%MCIERR_FILE_WRITE              = %MCIERR_BASE + 93

%MCIERR_NO_IDENTITY             = %MCIERR_BASE + 94

'/* all custom device driver errors must be >= than this value */
%MCIERR_CUSTOM_DRIVER_BASE = %MCIERR_BASE + 256

%MCI_FIRST       = %DRV_MCI_FIRST   ' &H0800
'/* MCI command message identifiers */
%MCI_OPEN        = &H0803???
%MCI_CLOSE       = &H0804???
%MCI_ESCAPE      = &H0805???
%MCI_PLAY        = &H0806???
%MCI_SEEK        = &H0807???
%MCI_STOP        = &H0808???
%MCI_PAUSE       = &H0809???
%MCI_INFO        = &H080A???
%MCI_GETDEVCAPS  = &H080B???
%MCI_SPIN        = &H080C???
%MCI_SET         = &H080D???
%MCI_STEP        = &H080E???
%MCI_RECORD      = &H080F???
%MCI_SYSINFO     = &H0810???
%MCI_BREAK       = &H0811???
%MCI_SOUND       = &H0812???
%MCI_SAVE        = &H0813???
%MCI_STATUS      = &H0814???
%MCI_CUE         = &H0830???
%MCI_REALIZE     = &H0840???
%MCI_WINDOW      = &H0841???
%MCI_PUT         = &H0842???
%MCI_WHERE       = &H0843???
%MCI_FREEZE      = &H0844???
%MCI_UNFREEZE    = &H0845???
%MCI_LOAD        = &H0850???
%MCI_CUT         = &H0851???
%MCI_COPY        = &H0852???
%MCI_PASTE       = &H0853???
%MCI_UPDATE      = &H0854???
%MCI_RESUME      = &H0855???
%MCI_DELETE      = &H0856???

'/* all custom MCI command messages must be >= than this value */
%MCI_USER_MESSAGES  = &H400 + %MCI_FIRST
%MCI_LAST        = &HFFF???

'/* device ID for "all devices" */
'#define MCI_ALL_DEVICE_ID               ((MCIDEVICEID)-1)
'%MCI_ALL_DEVICE_ID  = -1 ' Matches all MCI devices
%MCI_ALL_DEVICE_ID  = &HFFFFFFFF???

'/* constants for predefined MCI device types */
%MCI_DEVTYPE_VCR            = 513
%MCI_DEVTYPE_VIDEODISC      = 514
%MCI_DEVTYPE_OVERLAY        = 515
%MCI_DEVTYPE_CD_AUDIO       = 516
%MCI_DEVTYPE_DAT            = 517
%MCI_DEVTYPE_SCANNER        = 518
%MCI_DEVTYPE_ANIMATION      = 519
%MCI_DEVTYPE_DIGITAL_VIDEO  = 520
%MCI_DEVTYPE_OTHER          = 521
%MCI_DEVTYPE_WAVEFORM_AUDIO = 522
%MCI_DEVTYPE_SEQUENCER      = 523

%MCI_DEVTYPE_FIRST          = %MCI_DEVTYPE_VCR
%MCI_DEVTYPE_LAST           = %MCI_DEVTYPE_SEQUENCER

'#define MCI_DEVTYPE_FIRST_USER          0x1000
%MCI_DEVTYPE_FIRST_USER     = &H1000
'/* return values for 'status mode' command */
%MCI_MODE_NOT_READY = %MCI_STRING_OFFSET + 12
%MCI_MODE_STOP      = %MCI_STRING_OFFSET + 13
%MCI_MODE_PLAY      = %MCI_STRING_OFFSET + 14
%MCI_MODE_RECORD    = %MCI_STRING_OFFSET + 15
%MCI_MODE_SEEK      = %MCI_STRING_OFFSET + 16
%MCI_MODE_PAUSE     = %MCI_STRING_OFFSET + 17
%MCI_MODE_OPEN      = %MCI_STRING_OFFSET + 18

'/* constants used in 'set time format' and 'status time format' commands */
%MCI_FORMAT_MILLISECONDS  = 0
%MCI_FORMAT_HMS           = 1
%MCI_FORMAT_MSF           = 2
%MCI_FORMAT_FRAMES        = 3
%MCI_FORMAT_SMPTE_24      = 4
%MCI_FORMAT_SMPTE_25      = 5
%MCI_FORMAT_SMPTE_30      = 6
%MCI_FORMAT_SMPTE_30DROP  = 7
%MCI_FORMAT_BYTES         = 8
%MCI_FORMAT_SAMPLES       = 9
%MCI_FORMAT_TMSF          = 10

'/* MCI time format conversion macros */
'#define MCI_MSF_MINUTE(msf)             ((BYTE)(msf))
FUNCTION MCI_MSF_MINUTE (BYVAL msf AS DWORD) AS BYTE
   ! MOV AL, msf[0]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_MSF_SECOND(msf)             ((BYTE)(((WORD)(msf)) >> 8))
FUNCTION MCI_MSF_SECOND (BYVAL msf AS DWORD) AS BYTE
   ! MOV AL, msf[1]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_MSF_FRAME(msf)              ((BYTE)((msf)>>16))
FUNCTION MCI_MSF_FRAME (BYVAL msf AS DWORD) AS BYTE
   ! MOV AL, msf[2]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_MAKE_MSF(m, s, f)           ((DWORD)(((BYTE)(m) | \
'                                                  ((WORD)(s)<<8)) | \
'                                                 (((DWORD)(BYTE)(f))<<16)))
FUNCTION MCI_MAKE_MSF (BYVAL m AS BYTE, BYVAL s AS BYTE, BYVAL f AS BYTE) AS DWORD
   ! MOV AL, m
   ! MOV AH, s
   ! MOV DL, f
   ! Sub DH, DH
   ! MOV FUNCTION[0], AX
   ! MOV FUNCTION[2], DX
END FUNCTION

'#define MCI_TMSF_TRACK(tmsf)            ((BYTE)(tmsf))
FUNCTION MCI_TMSF_TRACK (BYVAL tmsf AS DWORD) AS BYTE
   ! MOV AL, tmsf[0]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_TMSF_MINUTE(tmsf)           ((BYTE)(((WORD)(tmsf)) >> 8))
FUNCTION MCI_TMSF_MINUTE (BYVAL tmsf AS DWORD) AS BYTE
   ! MOV AL, tmsf[1]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_TMSF_SECOND(tmsf)           ((BYTE)((tmsf)>>16))
FUNCTION MCI_TMSF_SECOND (BYVAL tmsf AS DWORD) AS BYTE
   ! MOV AL, tmsf[2]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_TMSF_FRAME(tmsf)            ((BYTE)((tmsf)>>24))
FUNCTION MCI_TMSF_FRAME (BYVAL tmsf AS DWORD) AS BYTE
   ! MOV AL, tmsf[3]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_MAKE_TMSF(t, m, s, f)       ((DWORD)(((BYTE)(t) | \
'                                                  ((WORD)(m)<<8)) | \
'                                                 (((DWORD)(BYTE)(s) | \
'                                                   ((WORD)(f)<<8))<<16)))
FUNCTION MCI_MAKE_TMSF(BYVAL t AS BYTE, BYVAL m AS BYTE, BYVAL s AS BYTE, BYVAL f AS BYTE) AS DWORD
   ! MOV AL, t
   ! MOV AH, m
   ! MOV DL, s
   ! MOV DH, f
   ! MOV FUNCTION[0], AX
   ! MOV FUNCTION[2], DX
END FUNCTION

'#define MCI_HMS_HOUR(hms)               ((BYTE)(hms))
FUNCTION MCI_HMS_HOUR (BYVAL hms AS DWORD) AS BYTE
   ! MOV AL, hms[0]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_HMS_MINUTE(hms)             ((BYTE)(((WORD)(hms)) >> 8))
FUNCTION MCI_HMS_MINUTE (BYVAL hms AS DWORD) AS BYTE
   ! MOV AL, hms[1]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_HMS_SECOND(hms)             ((BYTE)((hms)>>16))
FUNCTION MCI_HMS_SECOND (BYVAL hms AS DWORD) AS BYTE
   ! MOV AL, hms[2]
   ! MOV FUNCTION, AL
END FUNCTION

'#define MCI_MAKE_HMS(h, m, s)           ((DWORD)(((BYTE)(h) | \
'                                                  ((WORD)(m)<<8)) | \
'                                                 (((DWORD)(BYTE)(s))<<16)))
FUNCTION MCI_MAKE_HMS (BYVAL h AS BYTE, BYVAL m AS BYTE, BYVAL s AS BYTE) AS DWORD
   ! MOV AL, h
   ! MOV AH, m
   ! MOV DL, s
   ! Sub DH, DH
   ! MOV FUNCTION[0], AX
   ! MOV FUNCTION[2], DX
END FUNCTION


'/* flags for wParam of MM_MCINOTIFY message */
%MCI_NOTIFY_SUCCESSFUL = &H0001???
%MCI_NOTIFY_SUPERSEDED = &H0002???
%MCI_NOTIFY_ABORTED    = &H0004???
%MCI_NOTIFY_FAILURE    = &H0008???


'/* common flags for dwFlags parameter of MCI command messages */
%MCI_NOTIFY = &H00000001???
%MCI_WAIT   = &H00000002???
%MCI_FROM   = &H00000004???
%MCI_TO     = &H00000008???
%MCI_TRACK  = &H00000010???

'/* flags for dwFlags parameter of MCI_OPEN command message */
%MCI_OPEN_SHAREABLE  = &H00000100???
%MCI_OPEN_ELEMENT    = &H00000200???
%MCI_OPEN_ALIAS      = &H00000400???
%MCI_OPEN_ELEMENT_ID = &H00000800???
%MCI_OPEN_TYPE_ID    = &H00001000???
%MCI_OPEN_TYPE       = &H00002000???

'/* flags for dwFlags parameter of MCI_SEEK command message */
%MCI_SEEK_TO_START = &H00000100???
%MCI_SEEK_TO_END   = &H00000200???

'/* flags for dwFlags parameter of MCI_STATUS command message */
%MCI_STATUS_ITEM   = &H00000100???
%MCI_STATUS_START  = &H00000200???

'/* flags for dwItem field of the MCI_STATUS_PARMS parameter block */
%MCI_STATUS_LENGTH           = &H00000001???
%MCI_STATUS_POSITION         = &H00000002???
%MCI_STATUS_NUMBER_OF_TRACKS = &H00000003???
%MCI_STATUS_MODE             = &H00000004???
%MCI_STATUS_MEDIA_PRESENT    = &H00000005???
%MCI_STATUS_TIME_FORMAT      = &H00000006???
%MCI_STATUS_READY            = &H00000007???
%MCI_STATUS_CURRENT_TRACK    = &H00000008???

'/* flags for dwFlags parameter of MCI_INFO command message */
%MCI_INFO_PRODUCT        = &H00000100???
%MCI_INFO_FILE           = &H00000200???
%MCI_INFO_MEDIA_UPC      = &H00000400???
%MCI_INFO_MEDIA_IDENTITY = &H00000800???
%MCI_INFO_NAME           = &H00001000???
%MCI_INFO_COPYRIGHT      = &H00002000???

'/* flags for dwFlags parameter of MCI_GETDEVCAPS command message */
%MCI_GETDEVCAPS_ITEM = &H00000100???

'/* flags for dwItem field of the MCI_GETDEVCAPS_PARMS parameter block */
%MCI_GETDEVCAPS_CAN_RECORD       = &H00000001???
%MCI_GETDEVCAPS_HAS_AUDIO        = &H00000002???
%MCI_GETDEVCAPS_HAS_VIDEO        = &H00000003???
%MCI_GETDEVCAPS_DEVICE_TYPE      = &H00000004???
%MCI_GETDEVCAPS_USES_FILES       = &H00000005???
%MCI_GETDEVCAPS_COMPOUND_DEVICE  = &H00000006???
%MCI_GETDEVCAPS_CAN_EJECT        = &H00000007???
%MCI_GETDEVCAPS_CAN_PLAY         = &H00000008???
%MCI_GETDEVCAPS_CAN_SAVE         = &H00000009???

'/* flags for dwFlags parameter of MCI_SYSINFO command message */
%MCI_SYSINFO_QUANTITY    = &H00000100???
%MCI_SYSINFO_OPEN        = &H00000200???
%MCI_SYSINFO_NAME        = &H00000400???
%MCI_SYSINFO_INSTALLNAME = &H00000800???

'/* flags for dwFlags parameter of MCI_SET command message */
%MCI_SET_DOOR_OPEN   = &H00000100???
%MCI_SET_DOOR_CLOSED = &H00000200???
%MCI_SET_TIME_FORMAT = &H00000400???
%MCI_SET_AUDIO       = &H00000800???
%MCI_SET_VIDEO       = &H00001000???
%MCI_SET_ON          = &H00002000???
%MCI_SET_OFF         = &H00004000???

'/* flags for dwAudio field of MCI_SET_PARMS or MCI_SEQ_SET_PARMS */
%MCI_SET_AUDIO_ALL   = &H00000001???
%MCI_SET_AUDIO_LEFT  = &H00000002???
%MCI_SET_AUDIO_RIGHT = &H00000003???

'/* flags for dwFlags parameter of MCI_BREAK command message */
%MCI_BREAK_KEY  = &H00000100???
%MCI_BREAK_HWND = &H00000200???
%MCI_BREAK_OFF  = &H00000400???

'/* flags for dwFlags parameter of MCI_RECORD command message */
%MCI_RECORD_INSERT    = &H00000100???
%MCI_RECORD_OVERWRITE = &H00000200???

'/* flags for dwFlags parameter of MCI_SAVE command message */
%MCI_SAVE_FILE  = &H00000100???

'/* flags for dwFlags parameter of MCI_LOAD command message */
%MCI_LOAD_FILE  = &H00000100???

'/* generic parameter block for MCI command messages with no special parameters */
'typedef struct tagMCI_GENERIC_PARMS {
'    DWORD_PTR   dwCallback;
'} MCI_GENERIC_PARMS, *PMCI_GENERIC_PARMS, FAR *LPMCI_GENERIC_PARMS;

' // Size = 4 bytes
TYPE MCI_GENERIC_PARMS BYTE
   dwCallback AS DWORD
END TYPE

'/* parameter block for MCI_OPEN command message */

' // Size = 20 bytes
TYPE MCI_OPEN_PARMSA BYTE
   dwCallback       AS DWORD        ' DWORD_PTR   dwCallback
   wDeviceId        AS DWORD        ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS ASCIIZ PTR   ' LPCSTR     lpstrDeviceType
   lpstrElementName AS ASCIIZ PTR   ' LPCSTR     lpstrElementName
   lpstrAlias       AS ASCIIZ PTR   ' LPCSTR     lpstrAlias
END TYPE

' // Size = 20 bytes
TYPE MCI_OPEN_PARMSW BYTE
   dwCallback       AS DWORD          ' DWORD_PTR   dwCallback
   wDeviceId        AS DWORD          ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS WSTRINGZ PTR   ' LPCWSTR    lpstrDeviceType
   lpstrElementName AS WSTRINGZ PTR   ' LPCWSTR    lpstrElementName
   lpstrAlias       AS WSTRINGZ PTR   ' LPCWSTR    lpstrAlias
END TYPE

MACRO MCI_OPEN_PARMS = MCI_OPEN_PARMSA

'/* parameter block for MCI_PLAY command message */

' // Size = 12 bytes
TYPE MCI_PLAY_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwFrom     AS DWORD   ' DWORD       dwFrom
   dwTo       AS DWORD   ' DWORD       dwTo
END TYPE

'/* parameter block for MCI_SEEK command message */

' // Size = 8 bytes
TYPE MCI_SEEK_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwTo       AS DWORD   ' DWORD       dwTo
END TYPE

'/* parameter block for MCI_STATUS command message */

' // Size = 16 bytes
TYPE MCI_STATUS_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwReturn   AS DWORD   ' DWORD_PTR   dwReturn
   dwItem     AS DWORD   ' DWORD       dwItem
   dwTrack    AS DWORD   ' DWORD       dwTrack
END TYPE

'/* parameter block for MCI_INFO command message */

' // Size = 12 bytes
TYPE MCI_INFO_PARMSA BYTE
   dwCallback  AS DWORD        ' DWORD_PTR dwCallback
   lpstrReturn AS ASCIIZ PTR   ' LPSTR     lpstrReturn
   dwRetSize   AS DWORD        ' DWORD     dwRetSize
END TYPE

' // Size = 12 bytes
TYPE MCI_INFO_PARMSW BYTE
   dwCallback  AS DWORD          ' DWORD_PTR dwCallback
   lpstrReturn AS WSTRINGZ PTR   ' LPWSTR    lpstrReturn
   dwRetSize   AS DWORD          ' DWORD     dwRetSize
END TYPE

MACRO MCI_INFO_PARMS = MCI_INFO_PARMSA

'/* parameter block for MCI_GETDEVCAPS command message */

' // Size = 12 bytes
TYPE MCI_GETDEVCAPS_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwReturn   AS DWORD   ' DWORD       dwReturn
   dwItem     AS DWORD   ' DWORD       dwItem
END TYPE

'/* parameter block for MCI_SYSINFO command message */
'#ifdef _WIN32

' // Size = 20 bytes
TYPE MCI_SYSINFO_PARMSA BYTE
   dwCallback  AS DWORD        ' DWORD_PTR   dwCallback
   lpstrReturn AS ASCIIZ PTR   ' LPSTR       lpstrReturn
   dwRetSize   AS DWORD        ' DWORD       dwRetSize
   dwNumber    AS DWORD        ' DWORD       dwNumber
   wDeviceType AS DWORD        ' UINT        wDeviceType
END TYPE

' // Size = 20 bytes
TYPE MCI_SYSINFO_PARMSW BYTE
   dwCallback  AS DWORD          ' DWORD_PTR   dwCallback
   lpstrReturn AS WSTRINGZ PTR   ' LPWSTR      lpstrReturn
   dwRetSize   AS DWORD          ' DWORD       dwRetSize
   dwNumber    AS DWORD          ' DWORD       dwNumber
   wDeviceType AS DWORD          ' UINT        wDeviceType
END TYPE

MACRO MCI_SYSINFO_PARMS = MCI_SYSINFO_PARMSA

'/* parameter block for MCI_SET command message */

' // Size = 12 bytes
TYPE MCI_SET_PARMS BYTE
   dwCallback   AS DWORD   ' DWORD_PTR   dwCallback
   dwTimeFormat AS DWORD   ' DWORD       dwTimeFormat
   dwAudio      AS DWORD   ' DWORD       dwAudio
END TYPE

'/* parameter block for MCI_BREAK command message */

' // Size = 12 bytes
TYPE MCI_BREAK_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   nVirtKey   AS LONG    ' int         nVirtKey
   hwndBreak  AS LONG    ' HWND        hwndBreak
END TYPE

'/* parameter block for MCI_SAVE command message */

' // Size = 8 bytes
TYPE MCI_SAVE_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR    dwCallback
   lpFileName AS ASCIIZ PTR   ' LPCSTR       lpfilename
END TYPE

' // Size = 8 bytes
TYPE MCI_SAVE_PARMSW
   dwCallback AS DWORD          ' DWORD_PTR    dwCallback
   lpFileName AS WSTRINGZ PTR   ' LPCWSTR      lpfilename
END TYPE

MACRO MCI_SAVE_PARMS = MCI_SAVE_PARMSA

'/* parameter block for MCI_LOAD command message */
'#ifdef _WIN32

' // Size = 8 bytes
TYPE MCI_LOAD_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR    dwCallback
   lpFileName AS ASCIIZ PTR   ' LPCSTR       lpfilename
END TYPE

' // Size = 8 bytes
TYPE MCI_LOAD_PARMSW BYTE
   dwCallback AS DWORD          ' DWORD_PTR    dwCallback
   lpFileName AS WSTRINGZ PTR   ' LPCWSTR      lpfilename
END TYPE

MACRO MCI_LOAD_PARMS = MCI_LOAD_PARMSA

'/* parameter block for MCI_RECORD command message */

' // Size = 12 bytes
TYPE MCI_RECORD_PARMS
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwFrom     AS DWORD   ' DWORD       dwFrom
   dwTo       AS DWORD   ' DWORD       dwTo
END TYPE

'/* MCI extensions for videodisc devices */

'/* flag for dwReturn field of MCI_STATUS_PARMS */
'/* MCI_STATUS command, (dwItem == MCI_STATUS_MODE) */
%MCI_VD_MODE_PARK = %MCI_VD_OFFSET + 1

'/* flag for dwReturn field of MCI_STATUS_PARMS */
'/* MCI_STATUS command, (dwItem == MCI_VD_STATUS_MEDIA_TYPE) */
%MCI_VD_MEDIA_CLV   = %MCI_VD_OFFSET + 2
%MCI_VD_MEDIA_CAV   = %MCI_VD_OFFSET + 3
%MCI_VD_MEDIA_OTHER = %MCI_VD_OFFSET + 4

%MCI_VD_FORMAT_TRACK = &H00004001

'/* flags for dwFlags parameter of MCI_PLAY command message */
%MCI_VD_PLAY_REVERSE = &H00010000???
%MCI_VD_PLAY_FAST    = &H00020000???
%MCI_VD_PLAY_SPEED   = &H00040000???
%MCI_VD_PLAY_SCAN    = &H00080000???
%MCI_VD_PLAY_SLOW    = &H00100000???

'/* flag for dwFlags parameter of MCI_SEEK command message */
%MCI_VD_SEEK_REVERSE = &H00010000???

'/* flags for dwItem field of MCI_STATUS_PARMS parameter block */
%MCI_VD_STATUS_SPEED      = &H00004002???
%MCI_VD_STATUS_FORWARD    = &H00004003???
%MCI_VD_STATUS_MEDIA_TYPE = &H00004004???
%MCI_VD_STATUS_SIDE       = &H00004005???
%MCI_VD_STATUS_DISC_SIZE  = &H00004006???

'/* flags for dwFlags parameter of MCI_GETDEVCAPS command message */
%MCI_VD_GETDEVCAPS_CLV = &H00010000???
%MCI_VD_GETDEVCAPS_CAV = &H00020000???

%MCI_VD_SPIN_UP   = &H00010000???
%MCI_VD_SPIN_DOWN = &H00020000???

'/* flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block */
%MCI_VD_GETDEVCAPS_CAN_REVERSE = &H00004002???
%MCI_VD_GETDEVCAPS_FAST_RATE   = &H00004003???
%MCI_VD_GETDEVCAPS_SLOW_RATE   = &H00004004???
%MCI_VD_GETDEVCAPS_NORMAL_RATE = &H00004005???

'/* flags for the dwFlags parameter of MCI_STEP command message */
%MCI_VD_STEP_FRAMES  = &H00010000???
%MCI_VD_STEP_REVERSE = &H00020000???

'/* flag for the MCI_ESCAPE command message */
%MCI_VD_ESCAPE_STRING = &H00000100???


'/* parameter block for MCI_PLAY command message */
' // Size = 16 bytes
TYPE MCI_VD_PLAY_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwFrom     AS DWORD   ' DWORD       dwFrom
   dwTo       AS DWORD   ' DWORD       dwTo
   dwSpeed    AS DWORD   ' DWORD       dwSpeed
END TYPE

'/* parameter block for MCI_STEP command message */
' // Size = 8 bytes
TYPE MCI_VD_STEP_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwFrames   AS DWORD   ' DWORD       dwFrames
END TYPE

'/* parameter block for MCI_ESCAPE command message */
' // Size = 8 bytes
TYPE MCI_VD_ESCAPE_PARMSA BYTE
   dwCallback   AS DWORD        ' DWORD_PTR   dwCallback
   lpstrCommand AS ASCIIZ PTR   ' LPCSTR      lpstrCommand
END TYPE

' // Size = 8 bytes
TYPE MCI_VD_ESCAPE_PARMSW BYTE
   dwCallback   AS DWORD          ' DWORD_PTR   dwCallback
   lpstrCommand AS WSTRINGZ PTR   ' LPCWSTR     lpstrCommand
END TYPE

MACRO MCI_VD_ESCAPE_PARMS = MCI_VD_ESCAPE_PARMSA

'/* MCI extensions for CD audio devices */

'/* flags for the dwItem field of the MCI_STATUS_PARMS parameter block */
%MCI_CDA_STATUS_TYPE_TRACK      = &H00004001???

'/* flags for the dwReturn field of MCI_STATUS_PARMS parameter block */
'/* MCI_STATUS command, (dwItem == MCI_CDA_STATUS_TYPE_TRACK) */
%MCI_CDA_TRACK_AUDIO            = %MCI_CD_OFFSET + 0
%MCI_CDA_TRACK_OTHER            = %MCI_CD_OFFSET + 1

'/* MCI extensions for waveform audio devices */

%MCI_WAVE_PCM    = %MCI_WAVE_OFFSET + 0
%MCI_WAVE_MAPPER = %MCI_WAVE_OFFSET + 1

'/* flags for the dwFlags parameter of MCI_OPEN command message */
%MCI_WAVE_OPEN_BUFFER = &H00010000???

'/* flags for the dwFlags parameter of MCI_SET command message */
%MCI_WAVE_SET_FORMATTAG      = &H00010000???
%MCI_WAVE_SET_CHANNELS       = &H00020000???
%MCI_WAVE_SET_SAMPLESPERSEC  = &H00040000???
%MCI_WAVE_SET_AVGBYTESPERSEC = &H00080000???
%MCI_WAVE_SET_BLOCKALIGN     = &H00100000???
%MCI_WAVE_SET_BITSPERSAMPLE  = &H00200000???

'/* flags for the dwFlags parameter of MCI_STATUS, MCI_SET command messages */
%MCI_WAVE_INPUT  = &H00400000???
%MCI_WAVE_OUTPUT = &H00800000???

'/* flags for the dwItem field of MCI_STATUS_PARMS parameter block */
%MCI_WAVE_STATUS_FORMATTAG      = &H00004001???
%MCI_WAVE_STATUS_CHANNELS       = &H00004002???
%MCI_WAVE_STATUS_SAMPLESPERSEC  = &H00004003???
%MCI_WAVE_STATUS_AVGBYTESPERSEC = &H00004004???
%MCI_WAVE_STATUS_BLOCKALIGN     = &H00004005???
%MCI_WAVE_STATUS_BITSPERSAMPLE  = &H00004006???
%MCI_WAVE_STATUS_LEVEL          = &H00004007???

'/* flags for the dwFlags parameter of MCI_SET command message */
%MCI_WAVE_SET_ANYINPUT   = &H04000000???
%MCI_WAVE_SET_ANYOUTPUT  = &H08000000???

'/* flags for the dwFlags parameter of MCI_GETDEVCAPS command message */
%MCI_WAVE_GETDEVCAPS_INPUTS  = &H00004001???
%MCI_WAVE_GETDEVCAPS_OUTPUTS = &H00004002???

'/* parameter block for MCI_OPEN command message */
'#ifdef _WIN32

' // Size = 24 bytes
TYPE MCI_WAVE_OPEN_PARMSA BYTE
   dwCallback       AS DWORD        ' DWORD_PTR   dwCallback
   wDeviceID        AS DWORD        ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS ASCIIZ PTR   ' LPCSTR      lpstrDeviceType
   lpstrElementName AS ASCIIZ PTR   ' LPCSTR      lpstrElementName
   lpstrAlias       AS ASCIIZ PTR   ' LPCSTR      lpstrAlias
   dwBufferSeconds  AS DWORD        ' DWORD       dwBufferSeconds
END TYPE

' // Size = 24 bytes
TYPE MCI_WAVE_OPEN_PARMSW BYTE
   dwCallback       AS DWORD          ' DWORD_PTR   dwCallback
   wDeviceID        AS DWORD          ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS WSTRINGZ PTR   ' LPCWSTR     lpstrDeviceType
   lpstrElementName AS WSTRINGZ PTR   ' LPCWSTR     lpstrElementName
   lpstrAlias       AS WSTRINGZ PTR   ' LPCWSTR     lpstrAlias
   dwBufferSeconds  AS DWORD          ' DWORD       dwBufferSeconds
END TYPE

MACRO MCI_WAVE_OPEN_PARMS = MCI_WAVE_OPEN_PARMSA

'/* parameter block for MCI_DELETE command message */
' // Size = 12 bytes
TYPE MCI_WAVE_DELETE_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   dwFrom     AS DWORD   ' DWORD       dwFrom
   dwTo       AS DWORD   ' DWORD       dwTo
END TYPE

'/* parameter block for MCI_SET command message */
' // Size = 44 bytes
TYPE MCI_WAVE_SET_PARMS BYTE
   dwCallback      AS DWORD   ' DWORD_PTR   dwCallback
   dwTimeFormat    AS DWORD   ' DWORD       dwTimeFormat
   dwAudio         AS DWORD   ' DWORD       dwAudio
   wInput          AS DWORD   ' UINT        wInput
   wOutput         AS DWORD   ' UINT        wOutput
   wFormatTag      AS WORD    ' WORD        wFormatTag
   wReserved2      AS WORD    ' WORD        wReserved2
   nChannels       AS WORD    ' WORD        nChannels
   wReserved3      AS WORD    ' WORD        wReserved3
   nSamplesPerSec  AS DWORD   ' DWORD       nSamplesPerSec
   nAvgBytesPerSec AS DWORD   ' DWORD       nAvgBytesPerSec
   nBlockAlign     AS WORD    ' WORD        nBlockAlign
   wReserved4      AS WORD    ' WORD        wReserved4
   wBitsPerSample  AS WORD    ' WORD        wBitsPerSample
   wReserved5      AS WORD    ' WORD        wReserved5
END TYPE

'/* MCI extensions for MIDI sequencer devices */

'/* flags for the dwReturn field of MCI_STATUS_PARMS parameter block */
'/* MCI_STATUS command, (dwItem == MCI_SEQ_STATUS_DIVTYPE) */
%MCI_SEQ_DIV_PPQN         = %MCI_SEQ_OFFSET
%MCI_SEQ_DIV_SMPTE_24     = %MCI_SEQ_OFFSET + 1
%MCI_SEQ_DIV_SMPTE_25     = %MCI_SEQ_OFFSET + 2
%MCI_SEQ_DIV_SMPTE_30DROP = %MCI_SEQ_OFFSET + 3
%MCI_SEQ_DIV_SMPTE_30     = %MCI_SEQ_OFFSET + 4

'/* flags for the dwMaster field of MCI_SEQ_SET_PARMS parameter block */
'/* MCI_SET command, (dwFlags == MCI_SEQ_SET_MASTER) */
%MCI_SEQ_FORMAT_SONGPTR   = &H00004001???
%MCI_SEQ_FILE             = &H00004002???
%MCI_SEQ_MIDI             = &H00004003???
%MCI_SEQ_SMPTE            = &H00004004???
%MCI_SEQ_NONE             = 65533
%MCI_SEQ_MAPPER           = 65535

'/* flags for the dwItem field of MCI_STATUS_PARMS parameter block */
%MCI_SEQ_STATUS_TEMPO     = &H00004002???
%MCI_SEQ_STATUS_PORT      = &H00004003???
%MCI_SEQ_STATUS_SLAVE     = &H00004007???
%MCI_SEQ_STATUS_MASTER    = &H00004008???
%MCI_SEQ_STATUS_OFFSET    = &H00004009???
%MCI_SEQ_STATUS_DIVTYPE   = &H0000400A???
%MCI_SEQ_STATUS_NAME      = &H0000400B???
%MCI_SEQ_STATUS_COPYRIGHT = &H0000400C???

'/* flags for the dwFlags parameter of MCI_SET command message */
%MCI_SEQ_SET_TEMPO        = &H00010000???
%MCI_SEQ_SET_PORT         = &H00020000???
%MCI_SEQ_SET_SLAVE        = &H00040000???
%MCI_SEQ_SET_MASTER       = &H00080000???
%MCI_SEQ_SET_OFFSET       = &H01000000???

'/* parameter block for MCI_SET command message */
' // Size = 32 bytes
TYPE MCI_SEQ_SET_PARMS BYTE
   dwCallback   AS DWORD   ' DWORD_PTR   dwCallback
   dwTimeFormat AS DWORD   ' DWORD       dwTimeFormat
   dwAudio      AS DWORD   ' DWORD       dwAudio
   dwTempo      AS DWORD   ' DWORD       dwTempo
   dwPort       AS DWORD   ' DWORD       dwPort
   dwSlave      AS DWORD   ' DWORD       dwSlave
   dwMaster     AS DWORD   ' DWORD       dwMaster
   dwOffset     AS DWORD   ' DWORD       dwOffset
END TYPE

'/* MCI extensions for animation devices */

'/* flags for dwFlags parameter of MCI_OPEN command message */
%MCI_ANIM_OPEN_WS        = &H00010000???
%MCI_ANIM_OPEN_PARENT    = &H00020000???
%MCI_ANIM_OPEN_NOSTATIC  = &H00040000???

'/* flags for dwFlags parameter of MCI_PLAY command message */
%MCI_ANIM_PLAY_SPEED     = &H00010000???
%MCI_ANIM_PLAY_REVERSE   = &H00020000???
%MCI_ANIM_PLAY_FAST      = &H00040000???
%MCI_ANIM_PLAY_SLOW      = &H00080000???
%MCI_ANIM_PLAY_SCAN      = &H00100000???

'/* flags for dwFlags parameter of MCI_STEP command message */
%MCI_ANIM_STEP_REVERSE   = &H00010000???
%MCI_ANIM_STEP_FRAMES    = &H00020000???

'/* flags for dwItem field of MCI_STATUS_PARMS parameter block */
%MCI_ANIM_STATUS_SPEED   = &H00004001???
%MCI_ANIM_STATUS_FORWARD = &H00004002???
%MCI_ANIM_STATUS_HWND    = &H00004003???
%MCI_ANIM_STATUS_HPAL    = &H00004004???
%MCI_ANIM_STATUS_STRETCH = &H00004005???

'/* flags for the dwFlags parameter of MCI_INFO command message */
'#define MCI_ANIM_INFO_TEXT              0x00010000L
%MCI_ANIM_INFO_TEXT      = &H00010000???

'/* flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block */
%MCI_ANIM_GETDEVCAPS_CAN_REVERSE  = &H00004001???
%MCI_ANIM_GETDEVCAPS_FAST_RATE    = &H00004002???
%MCI_ANIM_GETDEVCAPS_SLOW_RATE    = &H00004003???
%MCI_ANIM_GETDEVCAPS_NORMAL_RATE  = &H00004004???
%MCI_ANIM_GETDEVCAPS_PALETTES     = &H00004006???
%MCI_ANIM_GETDEVCAPS_CAN_STRETCH  = &H00004007???
%MCI_ANIM_GETDEVCAPS_MAX_WINDOWS  = &H00004008???

'/* flags for the MCI_REALIZE command message */
%MCI_ANIM_REALIZE_NORM = &H00010000???
%MCI_ANIM_REALIZE_BKGD = &H00020000???

'/* flags for dwFlags parameter of MCI_WINDOW command message */
%MCI_ANIM_WINDOW_HWND            = &H00010000???
%MCI_ANIM_WINDOW_STATE           = &H00040000???
%MCI_ANIM_WINDOW_TEXT            = &H00080000???
%MCI_ANIM_WINDOW_ENABLE_STRETCH  = &H00100000???
%MCI_ANIM_WINDOW_DISABLE_STRETCH = &H00200000???

'/* flags for hWnd field of MCI_ANIM_WINDOW_PARMS parameter block */
'/* MCI_WINDOW command message, (dwFlags == MCI_ANIM_WINDOW_HWND) */
%MCI_ANIM_WINDOW_DEFAULT  = &H00000000???

'/* flags for dwFlags parameter of MCI_PUT command message */
%MCI_ANIM_RECT            = &H00010000???
%MCI_ANIM_PUT_SOURCE      = &H00020000???
%MCI_ANIM_PUT_DESTINATION = &H00040000???

'/* flags for dwFlags parameter of MCI_WHERE command message */
%MCI_ANIM_WHERE_SOURCE      = &H00020000???
%MCI_ANIM_WHERE_DESTINATION = &H00040000???

'/* flags for dwFlags parameter of MCI_UPDATE command message */
%MCI_ANIM_UPDATE_HDC        = &H00020000???


'/* parameter block for MCI_OPEN command message */

' // Size = 28 bytes
TYPE MCI_ANIM_OPEN_PARMSA BYTE
   dwCallback       AS DWORD        ' DWORD_PTR   dwCallback
   wDeviceID        AS DWORD        ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS ASCIIZ PTR   ' LPCSTR      lpstrDeviceType
   lpstrElementName AS ASCIIZ PTR   ' LPCSTR      lpstrElementName
   lpstrAlias       AS ASCIIZ PTR   ' LPCSTR      lpstrAlias
   dwStyle          AS DWORD        ' DWORD       dwStyle
   hwndParent       AS DWORD        ' HWND        hWndParent
END TYPE

' // Size = 28 bytes
TYPE MCI_ANIM_OPEN_PARMSW BYTE
   dwCallback       AS DWORD          ' DWORD_PTR   dwCallback
   wDeviceID        AS DWORD          ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS WSTRINGZ PTR   ' LPCWSTR     lpstrDeviceType
   lpstrElementName AS WSTRINGZ PTR   ' LPCWSTR     lpstrElementName
   lpstrAlias       AS WSTRINGZ PTR   ' LPCWSTR     lpstrAlias
   dwStyle          AS DWORD          ' DWORD       dwStyle
   hwndParent       AS DWORD          ' HWND        hWndParent
END TYPE

MACRO MCI_ANIM_OPEN_PARMS = MCI_ANIM_OPEN_PARMSA

'/* parameter block for MCI_PLAY command message */
' // Size = 16 bytes
TYPE MCI_ANIM_PLAY_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR dwCallback
   dwFrom     AS DWORD   ' DWORD     dwFrom
   dwTo       AS DWORD   ' DWORD     dwTo
   dwSpeed    AS DWORD   ' DWORD     dwSpeed
END TYPE

'/* parameter block for MCI_STEP command message */
' // Size = 8 bytes
TYPE MCI_ANIM_STEP_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR dwCallback
   dwFrames   AS DWORD   ' DWORD     dwFrames
END TYPE

'/* parameter block for MCI_WINDOW command message */

' // Size = 16 bytes
TYPE MCI_ANIM_WINDOW_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR dwCallback
   hWnd       AS DWORD        ' HWND      hWnd
   nCmdShow   AS DWORD        ' UINT      nCmdShow
   lpstrText  AS ASCIIZ PTR   ' LPCSTR    lpstrText
END TYPE

' // Size = 16 bytes
TYPE MCI_ANIM_WINDOW_PARMSW BYTE
   dwCallback AS DWORD          ' DWORD_PTR dwCallback
   hWnd       AS DWORD          ' HWND      hWnd
   nCmdShow   AS DWORD          ' UINT      nCmdShow
   lpstrText  AS WSTRINGZ PTR   ' LPCWSTR    lpstrText
END TYPE

MACRO MCI_ANIM_WINDOW_PARMS = MCI_ANIM_WINDOW_PARMSA

'/* parameter block for MCI_PUT, MCI_UPDATE, MCI_WHERE command messages */
' // Size = 20 bytes
TYPE MCI_ANIM_RECT_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR dwCallback
   rc         AS RECT    ' RECT      rc
END TYPE

'/* parameter block for MCI_UPDATE PARMS */
' // Size = 24 bytes
TYPE MCI_ANIM_UPDATE_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR dwCallback
   rc         AS RECT    ' RECT      rc
   hDC        AS DWORD   ' HDC       hDC
END TYPE


'/* MCI extensions for video overlay devices */

'/* flags for dwFlags parameter of MCI_OPEN command message */
%MCI_OVLY_OPEN_WS           = &H00010000???
%MCI_OVLY_OPEN_PARENT       = &H00020000???

'/* flags for dwFlags parameter of MCI_STATUS command message */
%MCI_OVLY_STATUS_HWND       = &H00004001???
%MCI_OVLY_STATUS_STRETCH    = &H00004002???

'/* flags for dwFlags parameter of MCI_INFO command message */
%MCI_OVLY_INFO_TEXT         = &H00010000???

'/* flags for dwItem field of MCI_GETDEVCAPS_PARMS parameter block */
%MCI_OVLY_GETDEVCAPS_CAN_STRETCH  = &H00004001???
%MCI_OVLY_GETDEVCAPS_CAN_FREEZE   = &H00004002???
%MCI_OVLY_GETDEVCAPS_MAX_WINDOWS  = &H00004003???

'/* flags for dwFlags parameter of MCI_WINDOW command message */
%MCI_OVLY_WINDOW_HWND             = &H00010000???
%MCI_OVLY_WINDOW_STATE            = &H00040000???
%MCI_OVLY_WINDOW_TEXT             = &H00080000???
%MCI_OVLY_WINDOW_ENABLE_STRETCH   = &H00100000???
%MCI_OVLY_WINDOW_DISABLE_STRETCH  = &H00200000???

'/* flags for hWnd parameter of MCI_OVLY_WINDOW_PARMS parameter block */
%MCI_OVLY_WINDOW_DEFAULT    = &H00000000???

'/* flags for dwFlags parameter of MCI_PUT command message */
%MCI_OVLY_RECT              = &H00010000???
%MCI_OVLY_PUT_SOURCE        = &H00020000???
%MCI_OVLY_PUT_DESTINATION   = &H00040000???
%MCI_OVLY_PUT_FRAME         = &H00080000???
%MCI_OVLY_PUT_VIDEO         = &H00100000???

'/* flags for dwFlags parameter of MCI_WHERE command message */
%MCI_OVLY_WHERE_SOURCE      = &H00020000???
%MCI_OVLY_WHERE_DESTINATION = &H00040000???
%MCI_OVLY_WHERE_FRAME       = &H00080000???
%MCI_OVLY_WHERE_VIDEO       = &H00100000???

'/* parameter block for MCI_OPEN command message */
'#ifdef _WIN32

' // Size = 28 bytes
TYPE MCI_OVLY_OPEN_PARMSA BYTE
   dwCallback       AS DWORD        ' DWORD_PTR   dwCallback
   wDeviceId        AS DWORD        ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS ASCIIZ PTR   ' LPCSTR      lpstrDeviceType
   lpstrElementName AS ASCIIZ PTR   ' LPCSTR      lpstrElementName
   lpstrAlias       AS ASCIIZ PTR   ' LPCSTR      lpstrAlias
   dwStyle          AS DWORD        ' DWORD       dwStyle
   hwndParent       AS DWORD        ' HWND        hWndParent
END TYPE

' // Size = 28 bytes
TYPE MCI_OVLY_OPEN_PARMSW BYTE
   dwCallback       AS DWORD          ' DWORD_PTR   dwCallback
   wDeviceId        AS DWORD          ' MCIDEVICEID wDeviceID
   lpstrDeviceType  AS WSTRINGZ PTR   ' LPCWSTR     lpstrDeviceType
   lpstrElementName AS WSTRINGZ PTR   ' LPCWSTR     lpstrElementName
   lpstrAlias       AS WSTRINGZ PTR   ' LPCWSTR     lpstrAlias
   dwStyle          AS DWORD          ' DWORD       dwStyle
   hwndParent       AS DWORD          ' HWND        hWndParent
END TYPE

MACRO MCI_OVLY_OPEN_PARMS = MCI_OVLY_OPEN_PARMSA

'/* parameter block for MCI_WINDOW command message */
'#ifdef _WIN32

' // Size = 16 bytes
TYPE MCI_OVLY_WINDOW_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR   dwCallback
   hWnd       AS DWORD        ' HWND        hWnd
   nCmdShow   AS DWORD        ' UINT        nCmdShow
   lpstrText  AS ASCIIZ PTR   ' LPCSTR      lpstrText
END TYPE

' // Size = 16 bytes
TYPE MCI_OVLY_WINDOW_PARMSW BYTE
   dwCallback AS DWORD          ' DWORD_PTR   dwCallback
   hWnd       AS DWORD          ' HWND        hWnd
   nCmdShow   AS DWORD          ' UINT        nCmdShow
   lpstrText  AS WSTRINGZ PTR   ' LPCWSTR     lpstrText
END TYPE

MACRO MCI_OVLY_WINDOW_PARMS = MCI_OVLY_WINDOW_PARMSA

'/* parameter block for MCI_PUT, MCI_UPDATE, and MCI_WHERE command messages */
' // Size = 20 bytes
TYPE MCI_OVLY_RECT_PARMS BYTE
   dwCallback AS DWORD   ' DWORD_PTR   dwCallback
   rc         AS RECT    ' RECT    rc
END TYPE

'/* parameter block for MCI_SAVE command message */
' // Size = 24 bytes
TYPE MCI_OVLY_SAVE_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR   dwCallback
   lpFileName AS ASCIIZ PTR   ' LPCSTR      lpfilename
   rc         AS RECT         ' RECT        rc
END TYPE

' // Size = 24 bytes
TYPE MCI_OVLY_SAVE_PARMSW BYTE
   dwCallback AS DWORD          ' DWORD_PTR   dwCallback
   lpFileName AS WSTRINGZ PTR   ' LPCWSTR     lpfilename
   rc         AS RECT           ' RECT        rc
END TYPE

MACRO MCI_OVLY_SAVE_PARMS = MCI_OVLY_SAVE_PARMSA

'/* parameter block for MCI_LOAD command message */

' // Size = 24 bytes
TYPE MCI_OVLY_LOAD_PARMSA BYTE
   dwCallback AS DWORD        ' DWORD_PTR   dwCallback
   lpFileName AS ASCIIZ PTR   ' LPCSTR      lpfilename
   rc         AS RECT         ' RECT    rc
END TYPE

' // Size = 24 bytes
TYPE MCI_OVLY_LOAD_PARMSW BYTE
   dwCallback AS DWORD          ' DWORD_PTR   dwCallback
   lpFileName AS WSTRINGZ PTR   ' LPCWSTR     lpfilename
   rc         AS RECT           ' RECT        rc
END TYPE

MACRO MCI_OVLY_LOAD_PARMS = MCI_OVLY_LOAD_PARMSA

#ENDIF   ' #IF NOT %DEF(%MMNOMCI)

'/****************************************************************************

'                        DISPLAY Driver extensions

'****************************************************************************/

' CAPS1 and C1_TRANSPARENT aren't defined in the Vista SDK
%CAPS1          = 94   ' other caps
%C1_TRANSPARENT = &H1  ' new raster cap

'#IF NOT %DEF(%NEWTRANSPARENT)
%NEWTRANSPARENT  = 3   ' use with SetBkMode()
%QUERYROPSUPPORT = 40  ' use to determine ROP support
'#ENDIF

'/****************************************************************************

'                        DIB Driver extensions

'****************************************************************************/

%SELECTDIB = 41  ' DIB.DRV select dib escape
'#define DIBINDEX(n)     MAKELONG((n),0x10FF)
MACRO DIBINDEX(n) = MAK(LONG, n, &H10FF)

'/****************************************************************************

'                        ScreenSaver support

'    The current application will receive a syscommand of SC_SCREENSAVE just
'    before the screen saver is invoked.  If the app wishes to prevent a
'    screen save, return non-zero value, otherwise call DefWindowProc().

'****************************************************************************/

#IF NOT %DEF(%SC_SCREENSAVE)
   %SC_SCREENSAVE   = &HF140???
#ENDIF

'#ifdef _WIN32
'#include <poppack.h>
'#else
'#ifndef RC_INVOKED
'#pragma pack()
'#endif
'#endif
