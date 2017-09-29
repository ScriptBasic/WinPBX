' ########################################################################################
' Microsoft Windows
' File: MSAcm.inc
' Contents: Audio Compression Manager Public Header File
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSACM_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "mmreg.inc"

'#include "pshpack1.h"   /* Assume byte packing throughout */

#IF NOT %DEF(%DRV_MAPPER_PREFERRED_INPUT_GET)
%DRV_MAPPER_PREFERRED_INPUT_GET = (%DRV_USER + 0)
#ENDIF

#IF NOT %DEF(%DRV_MAPPER_PREFERRED_OUTPUT_GET)
%DRV_MAPPER_PREFERRED_OUTPUT_GET = (%DRV_USER + 2)
#ENDIF

#IF NOT %DEF(%DRVM_MAPPER_STATUS)
%DRVM_MAPPER        = &H2000
%DRVM_MAPPER_STATUS = %DRVM_MAPPER + 0
#ENDIF

#IF NOT %DEF(%WIDM_MAPPER_STATUS)
%WIDM_MAPPER_STATUS          = %DRVM_MAPPER_STATUS + 0
%WAVEIN_MAPPER_STATUS_DEVICE = 0
%WAVEIN_MAPPER_STATUS_MAPPED = 1
%WAVEIN_MAPPER_STATUS_FORMAT = 2
#ENDIF

#IF NOT %DEF(%WODM_MAPPER_STATUS)
%WODM_MAPPER_STATUS           = (%DRVM_MAPPER_STATUS + 0)
%WAVEOUT_MAPPER_STATUS_DEVICE = 0
%WAVEOUT_MAPPER_STATUS_MAPPED = 1
%WAVEOUT_MAPPER_STATUS_FORMAT = 2
#ENDIF


'//--------------------------------------------------------------------------;
'//
'//  ACM General API's and Defines
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//
'//  there are four types of 'handles' used by the ACM. the first three
'//  are unique types that define specific objects:
'//
'//  HACMDRIVERID: used to _identify_ an ACM driver. this identifier can be
'//  used to _open_ the driver for querying details, etc about the driver.
'//
'//  HACMDRIVER: used to manage a driver (codec, filter, etc). this handle
'//  is much like a handle to other media drivers--you use it to send
'//  messages to the converter, query for capabilities, etc.
'//
'//  HACMSTREAM: used to manage a 'stream' (conversion channel) with the
'//  ACM. you use a stream handle to convert data from one format/type
'//  to another--much like dealing with a file handle.
'//
'//
'//  the fourth handle type is a generic type used on ACM functions that
'//  can accept two or more of the above handle types (for example the
'//  acmMetrics and acmDriverID functions).
'//
'//  HACMOBJ: used to identify ACM objects. this handle is used on functions
'//  that can accept two or more ACM handle types.
'//
'DECLARE_HANDLE(HACMDRIVERID);
'typedef HACMDRIVERID       *PHACMDRIVERID;
'typedef HACMDRIVERID   FAR *LPHACMDRIVERID;

'DECLARE_HANDLE(HACMDRIVER);
'typedef HACMDRIVER         *PHACMDRIVER;
'typedef HACMDRIVER     FAR *LPHACMDRIVER;

'DECLARE_HANDLE(HACMSTREAM);
'typedef HACMSTREAM         *PHACMSTREAM;
'typedef HACMSTREAM     FAR *LPHACMSTREAM;

'DECLARE_HANDLE(HACMOBJ);
'typedef HACMOBJ            *PHACMOBJ;
'typedef HACMOBJ        FAR *LPHACMOBJ;



'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  ACM Error Codes
'//
'//  Note that these error codes are specific errors that apply to the ACM
'//  directly--general errors are defined as MMSYSERR_*.
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifndef _MMRESULT_
'#define _MMRESULT_
'typedef UINT                MMRESULT;
'#endif

%ACMERR_BASE        = 512
%ACMERR_NOTPOSSIBLE = %ACMERR_BASE + 0
%ACMERR_BUSY        = %ACMERR_BASE + 1
%ACMERR_UNPREPARED  = %ACMERR_BASE + 2
%ACMERR_CANCELED    = %ACMERR_BASE + 3


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  ACM Window Messages
'//
'//  These window messages are sent by the ACM or ACM drivers to notify
'//  applications of events.
'//
'//  Note that these window message numbers will also be defined in
'//  mmsystem.
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

#IF NOT %DEF(%MM_STREAM_OPEN)
    %MM_STREAM_OPEN  = &H3D4
#ENDIF
#IF NOT %DEF(%MM_STREAM_CLOSE)
    %MM_STREAM_CLOSE = &H3D5
#ENDIF
#IF NOT %DEF(%MM_STREAM_DONE)
    %MM_STREAM_DONE  = &H3D6
#ENDIF

%MM_ACM_OPEN     = %MM_STREAM_OPEN   ' // conversion callback messages
%MM_ACM_CLOSE    = %MM_STREAM_CLOSE
%MM_ACM_DONE     = %MM_STREAM_DONE


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmGetVersion()
'//
'//  the ACM version is a 32 bit number that is broken into three parts as
'//  follows:
'//
'//      bits 24 - 31:   8 bit _major_ version number
'//      bits 16 - 23:   8 bit _minor_ version number
'//      bits  0 - 15:   16 bit build number
'//
'//  this is then displayed as follows:
'//
'//      bMajor = (BYTE)(dwVersion >> 24)
'//      bMinor = (BYTE)(dwVersion >> 16) &
'//      wBuild = LOWORD(dwVersion)
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmGetVersion IMPORT "MSACM32.DLL" ALIAS "acmGetVersion" ( _
 ) AS DWORD                                             ' DWORD

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmMetrics()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmMetrics IMPORT "MSACM32.DLL" ALIAS "acmMetrics" ( _
   BYVAL hao AS DWORD _                                 ' __in HACMOBJ hao
 , BYVAL uMetric AS DWORD _                             ' __in UINT uMetric
 , BYVAL pMetric AS DWORD _                             ' __in LPVOID pMetric
 ) AS DWORD                                             ' MMRESULT

%ACM_METRIC_COUNT_DRIVERS          = 1
%ACM_METRIC_COUNT_CODECS           = 2
%ACM_METRIC_COUNT_CONVERTERS       = 3
%ACM_METRIC_COUNT_FILTERS          = 4
%ACM_METRIC_COUNT_DISABLED         = 5
%ACM_METRIC_COUNT_HARDWARE         = 6
%ACM_METRIC_COUNT_LOCAL_DRIVERS    = 20
%ACM_METRIC_COUNT_LOCAL_CODECS     = 21
%ACM_METRIC_COUNT_LOCAL_CONVERTERS = 22
%ACM_METRIC_COUNT_LOCAL_FILTERS    = 23
%ACM_METRIC_COUNT_LOCAL_DISABLED   = 24
%ACM_METRIC_HARDWARE_WAVE_INPUT    = 30
%ACM_METRIC_HARDWARE_WAVE_OUTPUT   = 31
%ACM_METRIC_MAX_SIZE_FORMAT        = 50
%ACM_METRIC_MAX_SIZE_FILTER        = 51
%ACM_METRIC_DRIVER_SUPPORT         = 100
%ACM_METRIC_DRIVER_PRIORITY        = 101


'//--------------------------------------------------------------------------;
'//
'//  ACM Drivers
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverEnum()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'typedef BOOL (CALLBACK *ACMDRIVERENUMCB)
'(
'    HACMDRIVERID            hadid,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMDRIVERENUMCB ( _
' , BYVAL hadid AS DWORD _                               ' HACMDRIVERID hadid
' , BYVAL dwInstance AS DWORD _                          ' DWORD_PTR dwInstance
' , BYVAL fdwSupport AS DWORD _                          ' DWORD fdwSupport
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION acmDriverEnum IMPORT "MSACM32.DLL" ALIAS "acmDriverEnum" ( _
   BYVAL fnCallback AS DWORD _                          ' __in ACMDRIVERENUMCB fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

%ACM_DRIVERENUMF_NOLOCAL  = &H40000000???
%ACM_DRIVERENUMF_DISABLED = &H80000000???

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverID()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverID IMPORT "MSACM32.DLL" ALIAS "acmDriverID" ( _
   BYVAL hao AS DWORD _                                 ' __in HACMOBJ hao
 , BYVAL phadid AS DWORD _                              ' __in LPHACMDRIVERID phadid
 , BYVAL fdwDriverID AS DWORD _                         ' __in DWORD fdwDriverID
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverAdd()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverAdd IMPORT "MSACM32.DLL" ALIAS "acmDriverAddA" ( _
   BYVAL phadid AS DWORD _                              ' __in LPHACMDRIVERID phadid
 , BYVAL hinstModule AS DWORD _                         ' __in LPHACMDRIVERID hinstModule
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL dwPriority AS DWORD _                          ' __in DWORD dwPriority
 , BYVAL fdwAdd AS DWORD _                              ' __in DWORD fdwAdd
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmDriverAddW IMPORT "MSACM32.DLL" ALIAS "acmDriverAddW" ( _
   BYVAL phadid AS DWORD _                              ' __in LPHACMDRIVERID phadid
 , BYVAL hinstModule AS DWORD _                         ' __in LPHACMDRIVERID hinstModule
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 , BYVAL dwPriority AS DWORD _                          ' __in DWORD dwPriority
 , BYVAL fdwAdd AS DWORD _                              ' __in DWORD fdwAdd
 ) AS DWORD                                             ' MMRESULT

%ACM_DRIVERADDF_NAME         = &H00000001???
%ACM_DRIVERADDF_FUNCTION     = &H00000003???  ' // lParam is a procedure
%ACM_DRIVERADDF_NOTIFYHWND   = &H00000004???  ' // lParam is notify hwnd
%ACM_DRIVERADDF_TYPEMASK     = &H00000007???  ' // driver type mask
%ACM_DRIVERADDF_LOCAL        = &H00000000???  ' // is local to current task
%ACM_DRIVERADDF_GLOBAL       = &H00000008???  ' // is global

'//
'//  prototype for ACM driver procedures that are installed as _functions_
'//  or _notifations_ instead of as a standalone installable driver.
'//
'typedef LRESULT (CALLBACK *ACMDRIVERPROC)(DWORD_PTR, HACMDRIVERID, UINT, LPARAM, LPARAM);
'typedef ACMDRIVERPROC FAR *LPACMDRIVERPROC;
'DECLARE FUNCTION ACMDRIVERPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG, BYVAL LONG) AS LONG

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverRemove()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverRemove IMPORT "MSACM32.DLL" ALIAS "acmDriverRemove" ( _
   BYVAL hadid AS DWORD _                               ' __in HACMDRIVERID hadid
 , BYVAL fdwRemove AS DWORD _                           ' __in DWORD fdwRemove
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverOpen()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverOpen IMPORT "MSACM32.DLL" ALIAS "acmDriverOpen" ( _
   BYVAL phad AS DWORD _                                ' __in LPHACMDRIVER phad
 , BYVAL hadid AS DWORD _                               ' __in HACMDRIVERID hadid
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD fdwOpen
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverClose()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverClose IMPORT "MSACM32.DLL" ALIAS "acmDriverClose" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYVAL fdwClose AS DWORD _                            ' __in DWORD fdwClose
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverMessage()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverMessage IMPORT "MSACM32.DLL" ALIAS "acmDriverMessage" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
 ) AS LONG                                              ' LRESULT

'//
'//
'//
'//
%ACMDM_USER          = %DRV_USER + &H0000
%ACMDM_RESERVED_LOW  = %DRV_USER + &H2000
%ACMDM_RESERVED_HIGH = %DRV_USER + &H2FFF

%ACMDM_BASE          = %ACMDM_RESERVED_LOW

%ACMDM_DRIVER_ABOUT  = %ACMDM_BASE + 11


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverPriority
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmDriverPriority IMPORT "MSACM32.DLL" ALIAS "acmDriverPriority" ( _
   BYVAL hadid AS DWORD _                               ' __in HACMDRIVERID hadid
 , BYVAL dwPriority AS DWORD _                          ' __in DWORD dwPriority
 , BYVAL fdwPriority AS DWORD _                         ' __in DWORD fdwPriority
 ) AS DWORD                                             ' MMRESULT

%ACM_DRIVERPRIORITYF_ENABLE      = &H00000001???
%ACM_DRIVERPRIORITYF_DISABLE     = &H00000002???
%ACM_DRIVERPRIORITYF_ABLEMASK    = &H00000003???
%ACM_DRIVERPRIORITYF_BEGIN       = &H00010000???
%ACM_DRIVERPRIORITYF_END         = &H00020000???
%ACM_DRIVERPRIORITYF_DEFERMASK   = &H00030000???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmDriverDetails()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'//
'//  ACMDRIVERDETAILS
'//
'//  the ACMDRIVERDETAILS structure is used to get various capabilities from
'//  an ACM driver (codec, converter, filter).
'//

%ACMDRIVERDETAILS_SHORTNAME_CHARS = 32
%ACMDRIVERDETAILS_LONGNAME_CHARS  = 128
%ACMDRIVERDETAILS_COPYRIGHT_CHARS = 80
%ACMDRIVERDETAILS_LICENSING_CHARS = 128
%ACMDRIVERDETAILS_FEATURES_CHARS  = 512

' // Size = 920 bytes
TYPE tagACMDRIVERDETAILSA BYTE
   cbStruct    AS DWORD       ' DWORD // number of valid bytes in structure
   fccType     AS DWORD       ' FOURCC // compressor type 'audc'
   fccComp     AS DWORD       ' FOURCC // sub-type (not used; reserved)
   wMid        AS WORD        ' WORD // manufacturer id
   wPid        AS WORD        ' WORD // product id
   vdwACM      AS DWORD       ' DWORD // version of the ACM *compiled* for
   vdwDriver   AS DWORD       ' DWORD // version of the driver
   fdwSupport  AS DWORD       ' DWORD // misc. support flags
   cFormatTags AS DWORD       ' DWORD // total unique format tags supported
   cFilterTags AS DWORD       ' DWORD // total unique filter tags supported
   hicon       AS DWORD       ' HICON // handle to custom icon
   szShortName AS ASCIIZ * %ACMDRIVERDETAILS_SHORTNAME_CHARS   ' char
   szLongName  AS ASCIIZ * %ACMDRIVERDETAILS_LONGNAME_CHARS    ' char
   szCopyright AS ASCIIZ * %ACMDRIVERDETAILS_COPYRIGHT_CHARS   ' char
   szLicensing AS ASCIIZ * %ACMDRIVERDETAILS_LICENSING_CHARS   ' char
   szFeatures  AS ASCIIZ * %ACMDRIVERDETAILS_FEATURES_CHARS    ' char
END TYPE

' // Size = 1800 bytes
TYPE tagACMDRIVERDETAILSW BYTE
   cbStruct    AS DWORD       ' DWORD // number of valid bytes in structure
   fccType     AS DWORD       ' FOURCC // compressor type 'audc'
   fccComp     AS DWORD       ' FOURCC // sub-type (not used; reserved)
   wMid        AS WORD        ' WORD // manufacturer id
   wPid        AS WORD        ' WORD // product id
   vdwACM      AS DWORD       ' DWORD // version of the ACM *compiled* for
   vdwDriver   AS DWORD       ' DWORD // version of the driver
   fdwSupport  AS DWORD       ' DWORD // misc. support flags
   cFormatTags AS DWORD       ' DWORD // total unique format tags supported
   cFilterTags AS DWORD       ' DWORD // total unique filter tags supported
   hicon       AS DWORD       ' HICON // handle to custom icon
   szShortName AS WSTRINGZ * %ACMDRIVERDETAILS_SHORTNAME_CHARS  ' WCHAR
   szLongName  AS WSTRINGZ * %ACMDRIVERDETAILS_LONGNAME_CHARS   ' WCHAR
   szCopyright AS WSTRINGZ * %ACMDRIVERDETAILS_COPYRIGHT_CHARS  ' WCHAR
   szLicensing AS WSTRINGZ * %ACMDRIVERDETAILS_LICENSING_CHARS  ' WCHAR
   szFeatures  AS WSTRINGZ * %ACMDRIVERDETAILS_FEATURES_CHARS   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMDRIVERDETAILS = tagACMDRIVERDETAILSW
#ELSE
   MACRO tagACMDRIVERDETAILS = tagACMDRIVERDETAILSA
#ENDIF

'//
'//  ACMDRIVERDETAILS.fccType
'//
'//  ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC: the FOURCC used in the fccType
'//  field of the ACMDRIVERDETAILS structure to specify that this is an ACM
'//  codec designed for audio.
'//
'//
'//  ACMDRIVERDETAILS.fccComp
'//
'//  ACMDRIVERDETAILS_FCCCOMP_UNDEFINED: the FOURCC used in the fccComp
'//  field of the ACMDRIVERDETAILS structure. this is currently an unused
'//  field.
'//
'#define ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC mmioFOURCC('a', 'u', 'd', 'c')
'#define ACMDRIVERDETAILS_FCCCOMP_UNDEFINED  mmioFOURCC('\0', '\0', '\0', '\0')

%ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC = &H63647561
%ACMDRIVERDETAILS_FCCCOMP_UNDEFINED  = 0

'//
'//  the following flags are used to specify the type of conversion(s) that
'//  the converter/codec/filter supports. these are placed in the fdwSupport
'//  field of the ACMDRIVERDETAILS structure. note that a converter can
'//  support one or more of these flags in any combination.
'//
'//  ACMDRIVERDETAILS_SUPPORTF_CODEC: this flag is set if the driver supports
'//  conversions from one format tag to another format tag. for example, if a
'//  converter compresses WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, then this bit
'//  should be set.
'//
'//  ACMDRIVERDETAILS_SUPPORTF_CONVERTER: this flags is set if the driver
'//  supports conversions on the same format tag. as an example, the PCM
'//  converter that is built into the ACM sets this bit (and only this bit)
'//  because it converts only PCM formats (bits, sample rate).
'//
'//  ACMDRIVERDETAILS_SUPPORTF_FILTER: this flag is set if the driver supports
'//  transformations on a single format. for example, a converter that changed
'//  the 'volume' of PCM data would set this bit. 'echo' and 'reverb' are
'//  also filter types.
'//
'//  ACMDRIVERDETAILS_SUPPORTF_HARDWARE: this flag is set if the driver supports
'//  hardware input and/or output through a waveform device.
'//
'//  ACMDRIVERDETAILS_SUPPORTF_ASYNC: this flag is set if the driver supports
'//  async conversions.
'//
'//
'//  ACMDRIVERDETAILS_SUPPORTF_LOCAL: this flag is set _by the ACM_ if a
'//  driver has been installed local to the current task. this flag is also
'//  set in the fdwSupport argument to the enumeration callback function
'//  for drivers.
'//
'//  ACMDRIVERDETAILS_SUPPORTF_DISABLED: this flag is set _by the ACM_ if a
'//  driver has been disabled. this flag is also passed set in the fdwSupport
'//  argument to the enumeration callback function for drivers.
'//

%ACMDRIVERDETAILS_SUPPORTF_CODEC     = &H00000001???
%ACMDRIVERDETAILS_SUPPORTF_CONVERTER = &H00000002???
%ACMDRIVERDETAILS_SUPPORTF_FILTER    = &H00000004???
%ACMDRIVERDETAILS_SUPPORTF_HARDWARE  = &H00000008???
%ACMDRIVERDETAILS_SUPPORTF_ASYNC     = &H00000010???
%ACMDRIVERDETAILS_SUPPORTF_LOCAL     = &H40000000???
%ACMDRIVERDETAILS_SUPPORTF_DISABLED  = &H80000000???

DECLARE FUNCTION acmDriverDetails IMPORT "MSACM32.DLL" ALIAS "acmDriverDetailsA" ( _
   BYVAL hadid AS DWORD _                               ' __in  HACMDRIVERID        hadid
 , BYREF padd AS tagACMDRIVERDETAILSA _                 ' __out LPACMDRIVERDETAILSA padd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD               fdwDetails
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmDriverDetailsW IMPORT "MSACM32.DLL" ALIAS "acmDriverDetailsW" ( _
   BYVAL hadid AS DWORD _                               ' __in  HACMDRIVERID        hadid
 , BYREF padd AS tagACMDRIVERDETAILSW _                 ' __out LPACMDRIVERDETAILSW padd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD               fdwDetails
 ) AS DWORD                                             ' MMRESULT

'//--------------------------------------------------------------------------;
'//
'//  ACM Format Tags
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatTagDetails()
'//
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

%ACMFORMATTAGDETAILS_FORMATTAG_CHARS = 48

' // Size = 72 bytes
TYPE tagACMFORMATTAGDETAILSA BYTE
   cbStruct         AS DWORD   ' DWORD
   dwFormatTagIndex AS DWORD   ' DWORD
   dwFormatTag      AS DWORD   ' DWORD
   cbFormatSize     AS DWORD   ' DWORD
   fdwSupport       AS DWORD   ' DWORD
   cStandardFormats AS DWORD   ' DWORD
   szFormatTag      AS ASCIIZ * %ACMFORMATTAGDETAILS_FORMATTAG_CHARS  ' char
END TYPE

' // Size = 120 bytes
TYPE tagACMFORMATTAGDETAILSW BYTE
   cbStruct         AS DWORD   ' DWORD
   dwFormatTagIndex AS DWORD   ' DWORD
   dwFormatTag      AS DWORD   ' DWORD
   cbFormatSize     AS DWORD   ' DWORD
   fdwSupport       AS DWORD   ' DWORD
   cStandardFormats AS DWORD   ' DWORD
   szFormatTag      AS WSTRINGZ * %ACMFORMATTAGDETAILS_FORMATTAG_CHARS   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFORMATTAGDETAILS = tagACMFORMATTAGDETAILSW
#ELSE
   MACRO tagACMFORMATTAGDETAILS = tagACMFORMATTAGDETAILSA
#ENDIF

DECLARE FUNCTION acmFormatTagDetails IMPORT "MSACM32.DLL" ALIAS "acmFormatTagDetailsA" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftfd AS tagACMFORMATTAGDETAILSA _            ' __out LPACMFORMATTAGDETAILSA paftfd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFormatTagDetailsW IMPORT "MSACM32.DLL" ALIAS "acmFormatTagDetailsW" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftfd AS tagACMFORMATTAGDETAILSW _            ' __out LPACMFORMATTAGDETAILSW paftfd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

%ACM_FORMATTAGDETAILSF_INDEX       = &H00000000???
%ACM_FORMATTAGDETAILSF_FORMATTAG   = &H00000001???
%ACM_FORMATTAGDETAILSF_LARGESTSIZE = &H00000002???
%ACM_FORMATTAGDETAILSF_QUERYMASK   = &H0000000F???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatTagEnum()
'//
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifdef _WIN32
'typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATTAGDETAILSA  paftd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFORMATTAGENUMCBA ( _
'   BYVAL hadid AS DWORD _
' , BYREF paftd AS ACMFORMATTAGDETAILS _
' , BYVAL dwInstance, _
' , BYVAL fdwSupport _
' ) AS DWORD

DECLARE FUNCTION acmFormatTagEnum IMPORT "MSACM32.DLL" ALIAS "acmFormatTagEnumA" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftd AS tagACMFORMATTAGDETAILSA _             ' __out LPACMFORMATTAGDETAILSA paftd
 , BYVAL fnCallback AS DWORD _                          ' __in  ACMFORMATTAGENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in  DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in  DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'typedef BOOL (CALLBACK *ACMFORMATTAGENUMCBW)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATTAGDETAILSW  paftd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFORMATTAGENUMCBW ( _
'   BYVAL hadid AS DWORD _
' , BYREF paftd AS ACMFORMATTAGDETAILSW _
' , BYVAL dwInstance _
' , BYVAL fdwSupport _
' ) AS DWORD

DECLARE FUNCTION acmFormatTagEnumW IMPORT "MSACM32.DLL" ALIAS "acmFormatTagEnumW" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftd AS tagACMFORMATTAGDETAILSW _             ' __out LPACMFORMATTAGDETAILSW paftd
 , BYVAL fnCallback AS DWORD _                          ' __in  ACMFORMATTAGENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in  DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in  DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'//--------------------------------------------------------------------------;
'//
'//  ACM Formats
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatDetails()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

%ACMFORMATDETAILS_FORMAT_CHARS = 128

' // Size = 152 bytes
TYPE tagACMFORMATDETAILSA BYTE
   cbStruct      AS DWORD                                     ' DWORD
   dwFormatIndex AS DWORD                                     ' DWORD
   dwFormatTag   AS DWORD                                     ' DWORD
   fdwSupport    AS DWORD                                     ' DWORD
   pwfx          AS WAVEFORMATEX PTR                          ' LPWAVEFORMATEX
   cbwfx         AS DWORD                                     ' DWORD
   szFormat      AS ASCIIZ * %ACMFORMATDETAILS_FORMAT_CHARS   ' char
END TYPE

' // Size = 280 bytes
TYPE tagACMFORMATDETAILSW BYTE
   cbStruct      AS DWORD                                       ' DWORD
   dwFormatIndex AS DWORD                                       ' DWORD
   dwFormatTag   AS DWORD                                       ' DWORD
   fdwSupport    AS DWORD                                       ' DWORD
   pwfx          AS WAVEFORMATEX PTR                            ' LPWAVEFORMATEX
   cbwfx         AS DWORD                                       ' DWORD
   szFormat      AS WSTRINGZ * %ACMFORMATDETAILS_FORMAT_CHARS   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFORMATDETAILS = tagACMFORMATDETAILSW
#ELSE
   MACRO tagACMFORMATDETAILS = tagACMFORMATDETAILSA
#ENDIF

DECLARE FUNCTION acmFormatDetails IMPORT "MSACM32.DLL" ALIAS "acmFormatDetails" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFORMATDETAILSA _                 ' __in LPACMFORMATDETAILS pafd
 , BYVAL fdwDetails AS DWORD _                          ' __in DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFormatDetailsW IMPORT "MSACM32.DLL" ALIAS "acmFormatDetailsW" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFORMATDETAILSW _                 ' __in LPACMFORMATDETAILSW pafd
 , BYVAL fdwDetails AS DWORD _                          ' __in DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

%ACM_FORMATDETAILSF_INDEX     = &H00000000???
%ACM_FORMATDETAILSF_FORMAT    = &H00000001???
%ACM_FORMATDETAILSF_QUERYMASK = &H0000000F???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatEnum()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifdef _WIN32
'typedef BOOL (CALLBACK *ACMFORMATENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATDETAILSA     pafd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFORMATENUMCBA ( _
'   BYVAL hadid AS DWORD _
' , BYREF pafd AS PACMFORMATDETAILS _
' , BYVAL dwInstance AS DWORD _
' , BYVAL fdwSupport AS DWORD _
' ) AS LONG

DECLARE FUNCTION acmFormatEnum IMPORT "MSACM32.DLL" ALIAS "acmFormatEnumA" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFORMATDETAILSA _                 ' __in LPACMFORMATDETAILSA pafd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFORMATENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'typedef BOOL (CALLBACK *ACMFORMATENUMCBW)
'(
'    HACMDRIVERID            hadid,
'    LPACMFORMATDETAILSW     pafd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFORMATENUMCBW ( _
'   BYVAL hadid AS DWORD _
' , BYREF pafd AS PACMFORMATDETAILSW _
' , BYVAL dwInstance AS DWORD _
' , BYVAL fdwSupport AS DWORD _
' ) AS LONG

DECLARE FUNCTION acmFormatEnumW IMPORT "MSACM32.DLL" ALIAS "acmFormatEnumW" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFORMATDETAILSW _                 ' __in LPACMFORMATDETAILSW pafd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFORMATENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

%ACM_FORMATENUMF_WFORMATTAG     = &H00010000???
%ACM_FORMATENUMF_NCHANNELS      = &H00020000???
%ACM_FORMATENUMF_NSAMPLESPERSEC = &H00040000???
%ACM_FORMATENUMF_WBITSPERSAMPLE = &H00080000???
%ACM_FORMATENUMF_CONVERT        = &H00100000???
%ACM_FORMATENUMF_SUGGEST        = &H00200000???
%ACM_FORMATENUMF_HARDWARE       = &H00400000???
%ACM_FORMATENUMF_INPUT          = &H00800000???
%ACM_FORMATENUMF_OUTPUT         = &H01000000???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatSuggest()
'//
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmFormatSuggest IMPORT "MSACM32.DLL" ALIAS "acmFormatSuggest" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF pwfxSrc AS WAVEFORMATEX _                      ' __in  LPWAVEFORMATEX pwfxSrc
 , BYREF pwfxDst AS WAVEFORMATEX _                      ' __out LPWAVEFORMATEX pwfxDst
 , BYVAL cbwfxDst AS DWORD _                            ' __in  DWORD cbwfxDst
 , BYVAL fdwSuggest AS DWORD _                          ' __in  DWORD fdwSuggest
 ) AS DWORD                                             ' MMRESULT

%ACM_FORMATSUGGESTF_WFORMATTAG     = &H00010000???
%ACM_FORMATSUGGESTF_NCHANNELS      = &H00020000???
%ACM_FORMATSUGGESTF_NSAMPLESPERSEC = &H00040000???
%ACM_FORMATSUGGESTF_WBITSPERSAMPLE = &H00080000???

%ACM_FORMATSUGGESTF_TYPEMASK       = &H00FF0000???

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFormatChoose()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifdef _WIN32
'#define ACMHELPMSGSTRINGA       "acmchoose_help"
'#define ACMHELPMSGSTRINGW       L"acmchoose_help"
'#define ACMHELPMSGCONTEXTMENUA  "acmchoose_contextmenu"
'#define ACMHELPMSGCONTEXTMENUW  L"acmchoose_contextmenu"
'#define ACMHELPMSGCONTEXTHELPA  "acmchoose_contexthelp"
'#define ACMHELPMSGCONTEXTHELPW  L"acmchoose_contexthelp"
'#ifdef _UNICODE
'#define ACMHELPMSGSTRING        ACMHELPMSGSTRINGW
'#define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUW
'#define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPW
'#else
'#define ACMHELPMSGSTRING        ACMHELPMSGSTRINGA
'#define ACMHELPMSGCONTEXTMENU   ACMHELPMSGCONTEXTMENUA
'#define ACMHELPMSGCONTEXTHELP   ACMHELPMSGCONTEXTHELPA
'#endif
'#else
'#define ACMHELPMSGSTRING        "acmchoose_help"
'#define ACMHELPMSGCONTEXTMENU   "acmchoose_contextmenu"
'#define ACMHELPMSGCONTEXTHELP   "acmchoose_contexthelp"
'#endif

$ACMHELPMSGSTRINGA            = "acmchoose_help"
$ACMHELPMSGCONTEXTMENUA       = "acmchoose_contextmenu"
$ACMHELPMSGCONTEXTHELPA       = "acmchoose_contexthelp"

'//
'//  MM_ACM_FORMATCHOOSE is sent to hook callbacks by the Format Chooser
'//  Dialog...
'//
%MM_ACM_FORMATCHOOSE  = &H8000???

%FORMATCHOOSE_MESSAGE          = 0
%FORMATCHOOSE_FORMATTAG_VERIFY = %FORMATCHOOSE_MESSAGE + 0
%FORMATCHOOSE_FORMAT_VERIFY    = %FORMATCHOOSE_MESSAGE + 1
%FORMATCHOOSE_CUSTOM_VERIFY    = %FORMATCHOOSE_MESSAGE + 2


'typedef UINT (CALLBACK *ACMFORMATCHOOSEHOOKPROCA)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    LPARAM                  lParam
');

'DECLARE FUNCTION ACMFORMATCHOOSEHOOKPROCA ( _
'   BYVAL hwnd AS DWORD, _
'   BYVAL uMsg AS DWORD, _
'   BYVAL wParam AS DWORD, _
'   BYVAL lParam AS LONG _
'   ) AS DWORD

'typedef UINT (CALLBACK *ACMFORMATCHOOSEHOOKPROCW)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    LPARAM                  lParam
');

'DECLARE FUNCTION ACMFORMATCHOOSEHOOKPROCW ( _
'   BYVAL hwnd AS DWORD, _
'   BYVAL uMsg AS DWORD, _
'   BYVAL wParam AS DWORD, _
'   BYVAL lParam AS LONG _
'   ) AS DWORD

'//
'//
'//
'//

' // Size = 232 bytes
TYPE tagACMFORMATCHOOSEA BYTE
   cbStruct        AS DWORD              ' DWORD
   fdwStyle        AS DWORD              ' DWORD
   hwndOwner       AS DWORD              ' HWND
   pwfx            AS WAVEFORMATEX PTR   ' LPWAVEFORMATEX
   cbwfx           AS DWORD              ' DWORD
   pszTitle        AS ASCIIZ PTR         ' LPCSTR
   szFormatTag     AS ASCIIZ * %ACMFORMATTAGDETAILS_FORMATTAG_CHARS   ' char
   szFormat        AS ASCIIZ * %ACMFORMATDETAILS_FORMAT_CHARS         ' char
   pszName         AS ASCIIZ PTR         ' LPSTR
   cchName         AS DWORD              ' DWORD
   fdwEnum         AS DWORD              ' DWORD
   pwfxEnum        AS WAVEFORMATEX PTR   ' LPWAVEFORMATEX
   hInstance       AS DWORD              ' HINSTANCE
   pszTemplateName AS ASCIIZ PTR         ' LPCSTR
   lCustData       AS LONG               ' LPARAM
   pfnHook         AS DWORD              ' ACMFORMATCHOOSEHOOKPROCA
END TYPE

' // Size = 408 bytes
TYPE tagACMFORMATCHOOSEW BYTE
   cbStruct        AS DWORD              ' DWORD
   fdwStyle        AS DWORD              ' DWORD
   hwndOwner       AS DWORD              ' HWND
   pwfx            AS WAVEFORMATEX PTR   ' LPWAVEFORMATEX
   cbwfx           AS DWORD              ' DWORD
   pszTitle        AS WSTRINGZ PTR       ' LPCWSTR
   szFormatTag     AS WSTRINGZ * %ACMFORMATTAGDETAILS_FORMATTAG_CHARS   ' WCHAR
   szFormat        AS WSTRINGZ * %ACMFORMATDETAILS_FORMAT_CHARS         ' WCHAR
   pszName         AS WSTRINGZ PTR       ' LPWSTR
   cchName         AS DWORD              ' DWORD
   fdwEnum         AS DWORD              ' DWORD
   pwfxEnum        AS WAVEFORMATEX PTR   ' LPWAVEFORMATEX
   hInstance       AS DWORD              ' HINSTANCE
   pszTemplateName AS WSTRINGZ PTR       ' LPCWSTR
   lCustData       AS LONG               ' LPARAM
   pfnHook         AS DWORD              ' ACMFORMATCHOOSEHOOKPROCW
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFORMATCHOOSE = tagACMFORMATCHOOSEW
#ELSE
   MACRO tagACMFORMATCHOOSE = tagACMFORMATCHOOSEA
#ENDIF

'//
'//  ACMFORMATCHOOSE.fdwStyle
'//
'//
'//
%ACMFORMATCHOOSE_STYLEF_SHOWHELP             = &H00000004???
%ACMFORMATCHOOSE_STYLEF_ENABLEHOOK           = &H00000008???
%ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE       = &H00000010???
%ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = &H00000020???
%ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT      = &H00000040???
%ACMFORMATCHOOSE_STYLEF_CONTEXTHELP          = &H00000080???

DECLARE FUNCTION acmFormatChoose IMPORT "MSACM32.DLL" ALIAS "acmFormatChooseA" ( _
   BYREF pafmtc AS tagACMFORMATCHOOSEA _                ' __in_out LPACMFORMATCHOOSEA pafmtc
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFormatChooseW IMPORT "MSACM32.DLL" ALIAS "acmFormatChooseW" ( _
   BYREF pafmtc AS tagACMFORMATCHOOSEW _                ' __in_out LPACMFORMATCHOOSEW pafmtc
 ) AS DWORD                                             ' MMRESULT


'//--------------------------------------------------------------------------;
'//
'//  ACM Filter Tags
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFilterTagDetails()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

%ACMFILTERTAGDETAILS_FILTERTAG_CHARS = 48

' // Size = 72 bytes
TYPE tagACMFILTERTAGDETAILSA BYTE
   cbStruct         AS DWORD   ' DWORD
   dwFilterTagIndex AS DWORD   ' DWORD
   dwFilterTag      AS DWORD   ' DWORD
   cbFilterSize     AS DWORD   ' DWORD
   fdwSupport       AS DWORD   ' DWORD
   cStandardFilters AS DWORD   ' DWORD
   szFilterTag      AS ASCIIZ * %ACMFILTERTAGDETAILS_FILTERTAG_CHARS   ' char
END TYPE

' // Size = 120 bytes
TYPE tagACMFILTERTAGDETAILSW BYTE
   cbStruct         AS DWORD   ' DWORD
   dwFilterTagIndex AS DWORD   ' DWORD
   dwFilterTag      AS DWORD   ' DWORD
   cbFilterSize     AS DWORD   ' DWORD
   fdwSupport       AS DWORD   ' DWORD
   cStandardFilters AS DWORD   ' DWORD
   szFilterTag      AS WSTRINGZ * %ACMFILTERTAGDETAILS_FILTERTAG_CHARS   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFILTERTAGDETAILS = tagACMFILTERTAGDETAILSW
#ELSE
   MACRO tagACMFILTERTAGDETAILS = tagACMFILTERTAGDETAILSA
#ENDIF

DECLARE FUNCTION acmFilterTagDetails IMPORT "MSACM32.DLL" ALIAS "acmFilterTagDetailsA" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftd AS tagACMFILTERTAGDETAILSA _             ' __out LPACMFILTERTAGDETAILSA paftd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFilterTagDetailsW IMPORT "MSACM32.DLL" ALIAS "acmFilterTagDetailsW" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF paftd AS tagACMFILTERTAGDETAILSW _             ' __out LPACMFILTERTAGDETAILSW paftd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

%ACM_FILTERTAGDETAILSF_INDEX       = &H00000000???
%ACM_FILTERTAGDETAILSF_FILTERTAG   = &H00000001???
%ACM_FILTERTAGDETAILSF_LARGESTSIZE = &H00000002???
%ACM_FILTERTAGDETAILSF_QUERYMASK   = &H0000000F???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFilterTagEnum()
'//
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifdef _WIN32
'typedef BOOL (CALLBACK *ACMFILTERTAGENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFILTERTAGDETAILSA  paftd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

DECLARE FUNCTION acmFilterTagEnum IMPORT "MSACM32.DLL" ALIAS "acmFilterTagEnumA" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF paftd AS tagACMFILTERTAGDETAILSA _             ' __in LPACMFILTERTAGDETAILSA paftd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFILTERTAGENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'typedef BOOL (CALLBACK *ACMFILTERTAGENUMCBW)
'(
'    HACMDRIVERID            hadid,
'    LPACMFILTERTAGDETAILSW  paftd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFILTERTAGENUMCBW ( _
'   BYVAL hadid AS DWORD, _
'   BYREF paftd AS tagACMFILTERTAGDETAILSW, _
'   BYVAL dwInstance AS DWORD, _
'   BYVAL fdwSupport AS DWORD _
'   ) AS LONG

DECLARE FUNCTION acmFilterTagEnumW IMPORT "MSACM32.DLL" ALIAS "acmFilterTagEnumW" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF paftd AS tagACMFILTERTAGDETAILSW _             ' __in LPACMFILTERTAGDETAILSW paftd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFILTERTAGENUMCBW fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'MMRESULT ACMAPI acmFilterTagEnum
'(
'    HACMDRIVER              had,
'    LPACMFILTERTAGDETAILS   paftd,
'    ACMFILTERTAGENUMCB      fnCallback,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwEnum
');
'#endif


'//--------------------------------------------------------------------------;
'//
'//  ACM Filters
'//
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFilterDetails()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

%ACMFILTERDETAILS_FILTER_CHARS = 128

' // Size = 152 bytes
TYPE tagACMFILTERDETAILSA BYTE
   cbStruct      AS DWORD            ' DWORD
   dwFilterIndex AS DWORD            ' DWORD
   dwFilterTag   AS DWORD            ' DWORD
   fdwSupport    AS DWORD            ' DWORD
   pwfltr        AS WAVEFILTER PTR   ' LPWAVEFILTER
   cbwfltr       AS DWORD            ' DWORD
   szFilter      AS ASCIIZ * %ACMFILTERDETAILS_FILTER_CHARS  ' char
END TYPE

' // Size = 280 bytes
TYPE tagACMFILTERDETAILSW BYTE
   cbStruct      AS DWORD            ' DWORD
   dwFilterIndex AS DWORD            ' DWORD
   dwFilterTag   AS DWORD            ' DWORD
   fdwSupport    AS DWORD            ' DWORD
   pwfltr        AS WAVEFILTER PTR   ' LPWAVEFILTER
   cbwfltr       AS DWORD
   szFilter      AS WSTRINGZ * %ACMFILTERDETAILS_FILTER_CHARS   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFILTERDETAILS = tagACMFILTERDETAILSW
#ELSE
   MACRO tagACMFILTERDETAILS = tagACMFILTERDETAILSA
#ENDIF

DECLARE FUNCTION acmFilterDetails IMPORT "MSACM32.DLL" ALIAS "acmFilterDetailsA" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF tagACMFILTERDETAILSA _                         ' __out LPACMFILTERDETAILSA pafd
 , BYVAL pafd AS DWORD _                                ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFilterDetailsW IMPORT "MSACM32.DLL" ALIAS "acmFilterDetailsW" ( _
   BYVAL had AS DWORD _                                 ' __in  HACMDRIVER had
 , BYREF pafd AS tagACMFILTERDETAILSW _                 ' __out LPACMFILTERDETAILSW pafd
 , BYVAL fdwDetails AS DWORD _                          ' __in  DWORD fdwDetails
 ) AS DWORD                                             ' MMRESULT

%ACM_FILTERDETAILSF_INDEX     = &H00000000???
%ACM_FILTERDETAILSF_FILTER    = &H00000001???
%ACM_FILTERDETAILSF_QUERYMASK = &H0000000F???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFilterEnum()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'#ifdef _WIN32
'typedef BOOL (CALLBACK *ACMFILTERENUMCBA)
'(
'    HACMDRIVERID            hadid,
'    LPACMFILTERDETAILSA     pafd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFILTERENUMCBA ( _
'   BYVAL hadid AS DWORD _
' , BYREF pafd AS tagACMFILTERDETAILS _
' , BYVAL dwInstance AS DWORD _
' , BYVAL fdwSupport AS DWORD _
' ) AS LONG

DECLARE FUNCTION acmFilterEnum IMPORT "MSACM32.DLL" ALIAS "acmFilterEnumA" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFILTERDETAILSA _                 ' __in LPACMFILTERDETAILSA pafd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFILTERENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

'typedef BOOL (CALLBACK *ACMFILTERENUMCBW)
'(
'    HACMDRIVERID            hadid,
'    LPACMFILTERDETAILSW     pafd,
'    DWORD_PTR               dwInstance,
'    DWORD                   fdwSupport
');

'DECLARE FUNCTION ACMFILTERENUMCBW ( _
'   BYVAL hadid AS DWORD _
' , BYREF pafd AS tagACMFILTERDETAILSW _
' , BYVAL dwInstance AS DWORD _
' , BYVAL fdwSupport AS DWORD _
' ) AS LONG

DECLARE FUNCTION acmFilterEnumW IMPORT "MSACM32.DLL" ALIAS "acmFilterEnumW" ( _
   BYVAL had AS DWORD _                                 ' __in HACMDRIVER had
 , BYREF pafd AS tagACMFILTERDETAILSW _                 ' __in LPACMFILTERDETAILSW pafd
 , BYVAL fnCallback AS DWORD _                          ' __in ACMFILTERENUMCBA fnCallback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR dwInstance
 , BYVAL fdwEnum AS DWORD _                             ' __in DWORD fdwEnum
 ) AS DWORD                                             ' MMRESULT

%ACM_FILTERENUMF_DWFILTERTAG = &H00010000???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmFilterChoose()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

'//
'//  MM_ACM_FILTERCHOOSE is sent to hook callbacks by the Filter Chooser
'//  Dialog...
'//
%MM_ACM_FILTERCHOOSE           = &H8000???

%FILTERCHOOSE_MESSAGE          = 0
%FILTERCHOOSE_FILTERTAG_VERIFY = %FILTERCHOOSE_MESSAGE + 0
%FILTERCHOOSE_FILTER_VERIFY    = %FILTERCHOOSE_MESSAGE + 1
%FILTERCHOOSE_CUSTOM_VERIFY    = %FILTERCHOOSE_MESSAGE + 2

'#ifdef _WIN32
'typedef UINT (CALLBACK *ACMFILTERCHOOSEHOOKPROCA)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    LPARAM                  lParam
');

'DECLARE FUNCTION ACMFILTERCHOOSEHOOKPROCA ( _
'   BYVAL hwnd AS DWORD, _
'   BYVAL uMsg AS DWORD, _
'   BYVAL wParam AS DWORD, _
'   BYVAL lParam AS LONG _
'   ) AS DWORD

'typedef UINT (CALLBACK *ACMFILTERCHOOSEHOOKPROCW)
'(
'    HWND                    hwnd,
'    UINT                    uMsg,
'    WPARAM                  wParam,
'    LPARAM                  lParam
');

'DECLARE FUNCTION ACMFILTERCHOOSEHOOKPROCW ( _
'   BYVAL hwnd AS DWORD, _
'   BYVAL uMsg AS DWORD, _
'   BYVAL wParam AS DWORD, _
'   BYVAL lParam AS LONG _
'   ) AS DWORD

'//
'//  ACMFILTERCHOOSE
'//
'//
' // Size = 232 bytes
TYPE tagACMFILTERCHOOSEA BYTE
   cbStruct        AS DWORD            ' DWORD
   fdwStyle        AS DWORD            ' DWORD
   hwndOwner       AS DWORD            ' HWND
   pwfltr          AS WAVEFILTER PTR   ' LPWAVEFILTER
   cbwfltr         AS DWORD            ' DWORD
   pszTitle        AS ASCIIZ PTR       ' LPCSTR
   szFilterTag     AS ASCIIZ * %ACMFILTERTAGDETAILS_FILTERTAG_CHARS   ' char
   szFilter        AS ASCIIZ * %ACMFILTERDETAILS_FILTER_CHARS         ' char
   pszName         AS ASCIIZ PTR       ' LPSTR
   cchName         AS DWORD            ' DWORD
   fdwEnum         AS DWORD            ' DWORD
   pwfltrEnum      AS WAVEFILTER PTR   ' LPWAVEFILTER
   hInstance       AS DWORD            ' HINSTANCE
   pszTemplateName AS ASCIIZ PTR       ' LPCSTR
   lCustData       AS LONG             ' LPARAM
   pfnHook         AS DWORD            ' ACMFILTERCHOOSEHOOKPROCA
END TYPE

' // Size = 408 bytes
TYPE tagACMFILTERCHOOSEW BYTE
   cbStruct        AS DWORD            ' DWORD
   fdwStyle        AS DWORD            ' DWORD
   hwndOwner       AS DWORD            ' HWND
   pwfltr          AS WAVEFILTER PTR   ' LPWAVEFILTER
   cbwfltr         AS DWORD            ' DWORD
   pszTitle        AS WSTRINGZ PTR     ' LPCWSTR
   szFilterTag     AS WSTRINGZ * %ACMFILTERTAGDETAILS_FILTERTAG_CHARS   ' WCHAR
   szFilter        AS WSTRINGZ * %ACMFILTERDETAILS_FILTER_CHARS         ' WCHAR
   pszName         AS WSTRINGZ PTR     ' LPWSTR
   cchName         AS DWORD            ' DWORD
   fdwEnum         AS DWORD            ' DWORD
   pwfltrEnum      AS WAVEFILTER PTR   ' LPWAVEFILTER
   hInstance       AS DWORD            ' HINSTANCE
   pszTemplateName AS WSTRINGZ PTR     ' LPCWSTR
   lCustData       AS LONG             ' LPARAM
   pfnHook         AS DWORD            ' ACMFILTERCHOOSEHOOKPROCW
END TYPE

#IF %DEF(%UNICODE)
   MACRO tagACMFILTERCHOOSE = tagACMFILTERCHOOSEW
#ELSE
   MACRO tagACMFILTERCHOOSE = tagACMFILTERCHOOSEA
#ENDIF

'//
'//  ACMFILTERCHOOSE.fdwStyle
'//
'//
%ACMFILTERCHOOSE_STYLEF_SHOWHELP             = &H00000004???
%ACMFILTERCHOOSE_STYLEF_ENABLEHOOK           = &H00000008???
%ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE       = &H00000010???
%ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE = &H00000020???
%ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT   = &H00000040???
%ACMFILTERCHOOSE_STYLEF_CONTEXTHELP          = &H00000080???

DECLARE FUNCTION acmFilterChooseA IMPORT "MSACM32.DLL" ALIAS "acmFilterChoose" ( _
   BYREF pafltrc AS tagACMFILTERCHOOSEA _               ' __in_out LPACMFILTERCHOOSEA pafltrc
 ) AS DWORD                                             ' MMRESULT

DECLARE FUNCTION acmFilterChooseW IMPORT "MSACM32.DLL" ALIAS "acmFilterChooseW" ( _
   BYREF pafltrc AS tagACMFILTERCHOOSEW _               ' __in_out LPACMFILTERCHOOSEW pafltrc
 ) AS DWORD                                             ' MMRESULT

#IF %DEF(%UNICODE)
   MACRO acmFilterChoose = acmFilterChooseW
#ELSE
   MACRO acmFilterChoose = acmFilterChooseA
#ENDIF

'//--------------------------------------------------------------------------;
'//
'//  ACM Stream API's
'//
'//
'//
'//--------------------------------------------------------------------------;

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamOpen()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'#ifdef  _WIN64
'#define _DRVRESERVED    15
'#else
'#define _DRVRESERVED    10
'#endif  // _WIN64

%DRVRESERVED   = 10

' // Size = 84 bytes
TYPE tagACMSTREAMHEADER BYTE
   cbStruct        AS DWORD       ' DWORD
   fdwStatus       AS DWORD       ' DWORD
   dwUser          AS DWORD       ' DWORD_PTR
   pbSrc           AS BYTE PTR    ' LPBYTE
   cbSrcLength     AS DWORD       ' DWORD
   cbSrcLengthUsed AS DWORD       ' DWORD
   dwSrcUser       AS DWORD       ' DWORD_PTR
   pbDst           AS BYTE PTR    ' LPBYTE
   cbDstLength     AS DWORD       ' DWORD
   cbDstLengthUsed AS DWORD       ' DWORD
   dwDstUser       AS DWORD       ' DWORD_PTR
   dwReservedDriver(%DRVRESERVED - 1) AS DWORD   ' DWORD
END TYPE

'//
'//  ACMSTREAMHEADER.fdwStatus
'//
'//  ACMSTREAMHEADER_STATUSF_DONE: done bit for async conversions.
'//
%ACMSTREAMHEADER_STATUSF_DONE     = &H00010000???
%ACMSTREAMHEADER_STATUSF_PREPARED = &H00020000???
%ACMSTREAMHEADER_STATUSF_INQUEUE  = &H00100000???

DECLARE FUNCTION acmStreamOpen IMPORT "MSACM32.DLL" ALIAS "acmStreamOpen" ( _
   BYVAL phas AS DWORD _                                ' __in LPHACMSTREAM phas // pointer to stream handle
 , BYVAL had AS DWORD _                                 ' __in HACMDRIVER had    // optional driver handle
 , BYREF pwfxSrc AS WAVEFORMATEX _                      ' __in LPWAVEFORMATEX    // source format to convert
 , BYREF pwfxDst AS WAVEFORMATEX _                      ' __in LPWAVEFORMATEX    // required destination format
 , BYREF pwfltr AS WAVEFILTER _                         ' __in LPWAVEFILTER      // optional filter
 , BYVAL dwCallback AS DWORD _                          ' __in DWORD_PTR         // callback
 , BYVAL dwInstance AS DWORD _                          ' __in DWORD_PTR         // callback instance data
 , BYVAL fdwOpen AS DWORD _                             ' __in DWORD             // ACM_STREAMOPENF_* and CALLBACK_*
 ) AS DWORD                                             ' MMRESULT

%ACM_STREAMOPENF_QUERY       = &H00000001???
%ACM_STREAMOPENF_ASYNC       = &H00000002???
%ACM_STREAMOPENF_NONREALTIME = &H00000004???

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamClose()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamClose IMPORT "MSACM32.DLL" ALIAS "acmStreamClose" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYVAL fdwClose AS DWORD _                            ' __in DWORD fdwClose
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamSize()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamSize IMPORT "MSACM32.DLL" ALIAS "acmStreamSize" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYVAL cbInput AS DWORD _                             ' __in DWORD cbInput
 , BYREF pdwOutputBytes AS DWORD _                      ' __in_out LPDWORD pdwOutputBytes
 , BYVAL fdwSize AS DWORD _                             ' __in DWORD fdwSize
 ) AS DWORD                                             ' MMRESULT

%ACM_STREAMSIZEF_SOURCE      = &H00000000???
%ACM_STREAMSIZEF_DESTINATION = &H00000001???
%ACM_STREAMSIZEF_QUERYMASK   = &H0000000F???


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamReset()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamReset IMPORT "MSACM32.DLL" ALIAS "acmStreamReset" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYVAL fdwReset AS DWORD _                            ' __in DWORD fdwReset
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamMessage()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamMessage IMPORT "MSACM32.DLL" ALIAS "acmStreamMessage" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
 , BYVAL lParam2 AS DWORD _                             ' __in LPARAM lParam2
 ) AS DWORD                                             ' MMRESULT


'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamConvert()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamConvert IMPORT "MSACM32.DLL" ALIAS "acmStreamConvert" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYREF pash AS tagACMSTREAMHEADER _                   ' __in LPACMSTREAMHEADER pash
 , BYVAL fdwConvert AS DWORD _                          ' __in DWORD fdwConvert
 ) AS DWORD                                             ' MMRESULT

%ACM_STREAMCONVERTF_BLOCKALIGN = &H00000004???
%ACM_STREAMCONVERTF_START      = &H00000010???
%ACM_STREAMCONVERTF_END        = &H00000020???

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamPrepareHeader()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamPrepareHeader IMPORT "MSACM32.DLL" ALIAS "acmStreamPrepareHeader" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYREF pash AS tagACMSTREAMHEADER _                   ' __in LPACMSTREAMHEADER pash
 , BYVAL fdwPrepare AS DWORD _                          ' __in DWORD fdwPrepare
 ) AS DWORD                                             ' MMRESULT

'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
'//
'//  acmStreamUnprepareHeader()
'//
'//
'//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;

DECLARE FUNCTION acmStreamUnprepareHeader IMPORT "MSACM32.DLL" ALIAS "acmStreamUnprepareHeader" ( _
   BYVAL has AS DWORD _                                 ' __in HACMSTREAM has
 , BYREF pash AS tagACMSTREAMHEADER _                   ' __in LPACMSTREAMHEADER pash
 , BYVAL fdwUnprepare AS DWORD _                        ' __in DWORD fdwUnprepare
 ) AS DWORD                                             ' MMRESULT
