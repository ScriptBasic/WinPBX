' ########################################################################################
' OpenAL - Open Audio Library
' ########################################################################################

#INCLUDE THIS ONCE
%ALC_INC = 1

%ALC_VERSION_0_1        = 1

'typedef struct ALCdevice_struct ALCdevice;
'typedef struct ALCcontext_struct ALCcontext;


'/** 8-bit boolean */
'typedef char ALCboolean;

'/** character */
'typedef char ALCchar;

'/** signed 8-bit 2's complement integer */
'typedef char ALCbyte;

'/** unsigned 8-bit integer */
'typedef unsigned char ALCubyte;

'/** signed 16-bit 2's complement integer */
'typedef short ALCshort;

'/** unsigned 16-bit integer */
'typedef unsigned short ALCushort;

'/** signed 32-bit 2's complement integer */
'typedef int ALCint;

'/** unsigned 32-bit integer */
'typedef unsigned int ALCuint;

'/** non-negative 32-bit binary integer size */
'typedef int ALCsizei;

'/** enumerated 32-bit value */
'typedef int ALCenum;

'/** 32-bit IEEE754 floating-point */
'typedef float ALCfloat;

'/** 64-bit IEEE754 floating-point */
'typedef double ALCdouble;

'/** void type (for opaque pointers only) */
'typedef void ALCvoid;


'/* Enumerant values begin at column 50. No tabs. */

'/* Boolean False. */
%ALC_FALSE                               = 0

'/* Boolean True. */
%ALC_TRUE                                = 1

'/**
' * followed by <int> Hz
' */
%ALC_FREQUENCY                           = &H1007&

'/**
' * followed by <int> Hz
' */
%ALC_REFRESH                             = &H1008&

'/**
' * followed by AL_TRUE, AL_FALSE
' */
%ALC_SYNC                                = &H1009&

'/**
' * followed by <int> Num of requested Mono (3D) Sources
' */
%ALC_MONO_SOURCES                        = &H1010&

'/**
' * followed by <int> Num of requested Stereo Sources
' */
%ALC_STEREO_SOURCES                      = &H1011&

'/**
' * errors
' */

'/**
' * No error
' */
%ALC_NO_ERROR                            = %ALC_FALSE

'/**
' * No device
' */
%ALC_INVALID_DEVICE                      = &HA001&

'/**
' * invalid context ID
' */
%ALC_INVALID_CONTEXT                     = &HA002&

'/**
' * bad enum
' */
%ALC_INVALID_ENUM                        = &HA003&

'/**
' * bad value
' */
%ALC_INVALID_VALUE                       = &HA004&

'/**
' * Out of memory.
' */
%ALC_OUT_OF_MEMORY                       = &HA005&


'/**
' * The Specifier string for default device
' */
%ALC_DEFAULT_DEVICE_SPECIFIER            = &H1004&
%ALC_DEVICE_SPECIFIER                    = &H1005&
%ALC_EXTENSIONS                          = &H1006&

%ALC_MAJOR_VERSION                       = &H1000&
%ALC_MINOR_VERSION                       = &H1001&

%ALC_ATTRIBUTES_SIZE                     = &H1002&
%ALC_ALL_ATTRIBUTES                      = &H1003&

'/**
' * ALC_ENUMERATE_ALL_EXT enums
' */
%ALC_DEFAULT_ALL_DEVICES_SPECIFIER       = &H1012&
%ALC_ALL_DEVICES_SPECIFIER               = &H1013&

'/**
' * Capture extension
' */
%ALC_CAPTURE_DEVICE_SPECIFIER            = &H310&
%ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER    = &H311&
%ALC_CAPTURE_SAMPLES                     = &H312&


'/*
' * Context Management
' */

' ========================================================================================
' ALC_API ALCcontext *    ALC_APIENTRY alcCreateContext( ALCdevice *device, const ALCint* attrlist );
' ========================================================================================
DECLARE FUNCTION alcCreateContext CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCreateContext" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYREF attrlist AS LONG _                             ' const ALCint* attrlist
 ) AS DWORD                                             ' ALCcontext*
' ========================================================================================

' ========================================================================================
' ALC_API ALCboolean      ALC_APIENTRY alcMakeContextCurrent( ALCcontext *context );
' ========================================================================================
DECLARE FUNCTION alcMakeContextCurrent CDECL IMPORT "OPENAL32.DLL" ALIAS "alcMakeContextCurrent" ( _
   BYVAL context AS DWORD _                             ' ALCcontext *context
 ) AS BYTE                                              ' ALCboolean
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcProcessContext( ALCcontext *context );
' ========================================================================================
DECLARE SUB alcProcessContext CDECL IMPORT "OPENAL32.DLL" ALIAS "alcProcessContext" ( _
   BYVAL context AS DWORD _                             ' ALCcontext *context
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcSuspendContext( ALCcontext *context );
' ========================================================================================
DECLARE SUB alcSuspendContext CDECL IMPORT "OPENAL32.DLL" ALIAS "alcSuspendContext" ( _
   BYVAL context AS DWORD _                             ' ALCcontext *context
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcDestroyContext( ALCcontext *context );
' ========================================================================================
DECLARE SUB alcDestroyContext CDECL IMPORT "OPENAL32.DLL" ALIAS "alcDestroyContext" ( _
   BYVAL context AS DWORD _                             ' ALCcontext *context
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( void );
' ========================================================================================
DECLARE FUNCTION alcGetCurrentContext CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetCurrentContext" ( _
 ) AS DWORD                                             ' ALCcontext*
' ========================================================================================

' ========================================================================================
' ALC_API ALCdevice*      ALC_APIENTRY alcGetContextsDevice( ALCcontext *context );
' ========================================================================================
DECLARE FUNCTION alcGetContextsDevice CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetContextsDevice" ( _
   BYVAL context AS DWORD _                             ' ALCcontext *context
 ) AS DWORD                                             ' ALCdevice*
' ========================================================================================


'/*
' * Device Management
' */

' ========================================================================================
' ALC_API ALCdevice *     ALC_APIENTRY alcOpenDevice( const ALCchar *devicename );
' ========================================================================================
DECLARE FUNCTION alcOpenDevice CDECL IMPORT "OPENAL32.DLL" ALIAS "alcOpenDevice" ( _
   BYREF devicename AS ASCIIZ _                         ' const ALCchar *devicename
 ) AS DWORD                                             ' ALCdevice*
' ========================================================================================

' ========================================================================================
' ALC_API ALCboolean      ALC_APIENTRY alcCloseDevice( ALCdevice *device );
' ========================================================================================
DECLARE FUNCTION alcCloseDevice CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCreateContext" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 ) AS BYTE                                              ' ALCboolean
' ========================================================================================


'/*
' * Error support.
' * Obtain the most recent Context error
' */

' ========================================================================================
' ALC_API ALCenum         ALC_APIENTRY alcGetError( ALCdevice *device );
' ========================================================================================
DECLARE FUNCTION alcGetError CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetError" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 ) AS LONG                                              ' ALCenum
' ========================================================================================


'/*
' * Extension support.
' * Query for the presence of an extension, and obtain any appropriate
' * function pointers and enum values.
' */

' ========================================================================================
' ALC_API ALCboolean      ALC_APIENTRY alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname );
' ========================================================================================
DECLARE FUNCTION alcIsExtensionPresent CDECL IMPORT "OPENAL32.DLL" ALIAS "alcIsExtensionPresent" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYREF extname AS ASCIIZ _                            ' const ALCchar *extname
 ) AS BYTE                                              ' ALCboolean
' ========================================================================================

' ========================================================================================
' ALC_API void  *         ALC_APIENTRY alcGetProcAddress( ALCdevice *device, const ALCchar *funcname );
' ========================================================================================
DECLARE FUNCTION alcGetProcAddress CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetProcAddress" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYREF funcname AS ASCIIZ _                           ' const ALCchar *funcname
 ) AS DWORD                                             ' void*
' ========================================================================================

' ========================================================================================
' ALC_API ALCenum         ALC_APIENTRY alcGetEnumValue( ALCdevice *device, const ALCchar *enumname );
' ========================================================================================
DECLARE FUNCTION alcGetEnumValue CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetEnumValue" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYREF enumname AS ASCIIZ _                           ' const ALCchar *enumname
 ) AS LONG                                              ' ALCenum
' ========================================================================================


'/*
' * Query functions
' */

' ========================================================================================
' ALC_API const ALCchar * ALC_APIENTRY alcGetString( ALCdevice *device, ALCenum param );
' ========================================================================================
DECLARE FUNCTION alcGetString CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetString" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYVAL param AS LONG _                                ' ALCenum param
 ) AS DWORD                                             ' const ALCchar *
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcGetIntegerv( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *data );
' ========================================================================================
DECLARE SUB alcGetIntegerv CDECL IMPORT "OPENAL32.DLL" ALIAS "alcGetIntegerv" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYVAL param AS LONG _                                ' ALCenum param
 , BYVAL size AS LONG _                                 ' ALCsizei size
 , BYREF data AS LONG _                                 ' ALCint *data
 )                                                      ' void
' ========================================================================================


'/*
' * Capture functions
' */

' ========================================================================================
' ALC_API ALCdevice*      ALC_APIENTRY alcCaptureOpenDevice( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );
' ========================================================================================
DECLARE FUNCTION alcCaptureOpenDevice CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCaptureOpenDevice" ( _
   BYREF devicename AS ASCIIZ _                         ' const ALCchar *devicename
 , BYVAL frequency AS DWORD _                           ' ALCuint frequency
 , BYVAL format AS LONG _                               ' ALCenum format
 , BYVAL buffersize AS LONG _                           ' ALCsizei buffersize
 ) AS DWORD                                             ' ALCdevice*
' ========================================================================================

' ========================================================================================
' ALC_API ALCboolean      ALC_APIENTRY alcCaptureCloseDevice( ALCdevice *device );
' ========================================================================================
DECLARE FUNCTION alcCaptureCloseDevice CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCaptureCloseDevice" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 ) AS BYTE                                              ' ALCboolean
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcCaptureStart( ALCdevice *device );
' ========================================================================================
DECLARE SUB alcCaptureStart CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCaptureStart" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcCaptureStop( ALCdevice *device );
' ========================================================================================
DECLARE SUB alcCaptureStop CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCaptureStop" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' ALC_API void            ALC_APIENTRY alcCaptureSamples( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );
' ========================================================================================
DECLARE SUB alcCaptureSamples CDECL IMPORT "OPENAL32.DLL" ALIAS "alcCaptureSamples" ( _
   BYVAL device AS DWORD _                              ' ALCdevice *device
 , BYREF buffer AS ANY _                                ' ALCvoid *buffer
 , BYVAL samples AS LONG _                              ' ALCsizei samples
 )                                                      ' void
' ========================================================================================
