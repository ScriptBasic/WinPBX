' ########################################################################################
' OpenAL - Open Audio Library
' ########################################################################################

#INCLUDE THIS ONCE
%AL_INC = 1

'/** 8-bit boolean */
'typedef char ALboolean;

'/** character */
'typedef char ALchar;

'/** signed 8-bit 2's complement integer */
'typedef char ALbyte;

'/** unsigned 8-bit integer */
'typedef unsigned char ALubyte;

'/** signed 16-bit 2's complement integer */
'typedef short ALshort;

'/** unsigned 16-bit integer */
'typedef unsigned short ALushort;

'/** signed 32-bit 2's complement integer */
'typedef int ALint;

'/** unsigned 32-bit integer */
'typedef unsigned int ALuint;

'/** non-negative 32-bit binary integer size */
'typedef int ALsizei;

'/** enumerated 32-bit value */
'typedef int ALenum;

'/** 32-bit IEEE754 floating-point */
'typedef float ALfloat;

'/** 64-bit IEEE754 floating-point */
'typedef double ALdouble;

'/** void type (for opaque pointers only) */
'typedef void ALvoid;


'/* Enumerant values begin at column 50. No tabs. */

'/* bad value */
%AL_INVALID = -1

%AL_NONE = 0

'/* Boolean False. */
%AL_FALSE = 0

'/** Boolean True. */
%AL_TRUE = 1

'/** Indicate Source has relative coordinates. */
%AL_SOURCE_RELATIVE = &H202&


'/**
' * Directional source, inner cone angle, in degrees.
' * Range:    [0-360]
' * Default:  360
' */
%AL_CONE_INNER_ANGLE = &H1001&

'/**
' * Directional source, outer cone angle, in degrees.
' * Range:    [0-360]
' * Default:  360
' */
%AL_CONE_OUTER_ANGLE = &H1002&

'/**
' * Specify the pitch to be applied, either at source,
' *  or on mixer results, at listener.
' * Range:   [0.5-2.0]
' * Default: 1.0
' */
%AL_PITCH = &H1003&

'/**
' * Specify the current location in three dimensional space.
' * OpenAL, like OpenGL, uses a right handed coordinate system,
' *  where in a frontal default view X (thumb) points right,
' *  Y points up (index finger), and Z points towards the
' *  viewer/camera (middle finger).
' * To switch from a left handed coordinate system, flip the
' *  sign on the Z coordinate.
' * Listener position is always in the world coordinate system.
' */
%AL_POSITION = &H1004&

'/** Specify the current direction. */
%AL_DIRECTION = &H1005&

'/** Specify the current velocity in three dimensional space. */
%AL_VELOCITY = &H1006&

'/**
' * Indicate whether source is looping.
' * Type: ALboolean?
' * Range:   [AL_TRUE, AL_FALSE]
' * Default: FALSE.
' */
%AL_LOOPING = &H1007&

'/**
' * Indicate the buffer to provide sound samples.
' * Type: ALuint.
' * Range: any valid Buffer id.
' */
%AL_BUFFER = &H1009&

'/**
' * Indicate the gain (volume amplification) applied.
' * Type:   ALfloat.
' * Range:  ]0.0-  ]
' * A value of 1.0 means un-attenuated/unchanged.
' * Each division by 2 equals an attenuation of -6dB.
' * Each multiplicaton with 2 equals an amplification of +6dB.
' * A value of 0.0 is meaningless with respect to a logarithmic
' *  scale; it is interpreted as zero volume - the channel
' *  is effectively disabled.
' */
%AL_GAIN = &H100A&

'/*
' * Indicate minimum source attenuation
' * Type: ALfloat
' * Range:  [0.0 - 1.0]
' *
' * Logarthmic
' */
%AL_MIN_GAIN = &H100D&

'/**
' * Indicate maximum source attenuation
' * Type: ALfloat
' * Range:  [0.0 - 1.0]
' *
' * Logarthmic
' */
%AL_MAX_GAIN = &H100E&

'/**
' * Indicate listener orientation.
' *
' * at/up
' */
%AL_ORIENTATION = &H100F&

'/**
' * Specify the channel mask. (Creative)
' * Type: ALuint
' * Range: [0 - 255]
' */
%AL_CHANNEL_MASK = &H3000&


'/**
' * Source state information.
' */
%AL_SOURCE_STATE                           = &H1010&
%AL_INITIAL                                = &H1011&
%AL_PLAYING                                = &H1012&
%AL_PAUSED                                 = &H1013&
%AL_STOPPED                                = &H1014&

'/**
' * Buffer Queue params
' */
%AL_BUFFERS_QUEUED                         = &H1015&
%AL_BUFFERS_PROCESSED                      = &H1016&

'/**
' * Source buffer position information
' */
%AL_SEC_OFFSET                             = &H1024&
%AL_SAMPLE_OFFSET                          = &H1025&
%AL_BYTE_OFFSET                            = &H1026&

'/*
' * Source type (Static, Streaming or undetermined)
' * Source is Static if a Buffer has been attached using AL_BUFFER
' * Source is Streaming if one or more Buffers have been attached using alSourceQueueBuffers
' * Source is undetermined when it has the NULL buffer attached
' */
%AL_SOURCE_TYPE                            = &H1027&
%AL_STATIC                                 = &H1028&
%AL_STREAMING                              = &H1029&
%AL_UNDETERMINED                           = &H1030&

'/** Sound samples: format specifier. */
%AL_FORMAT_MONO8                           = &H1100&
%AL_FORMAT_MONO16                          = &H1101&
%AL_FORMAT_STEREO8                         = &H1102&
%AL_FORMAT_STEREO16                        = &H1103&

'/**
' * source specific reference distance
' * Type: ALfloat
' * Range:  0.0 - +inf
' *
' * At 0.0, no distance attenuation occurs.  Default is
' * 1.0.
' */
%AL_REFERENCE_DISTANCE                     = &H1020&

'/**
' * source specific rolloff factor
' * Type: ALfloat
' * Range:  0.0 - +inf
' *
' */
%AL_ROLLOFF_FACTOR                         = &H1021&

'/**
' * Directional source, outer cone gain.
' *
' * Default:  0.0
' * Range:    [0.0 - 1.0]
' * Logarithmic
' */
%AL_CONE_OUTER_GAIN                        = &H1022&

'/**
' * Indicate distance above which sources are not
' * attenuated using the inverse clamped distance model.
' *
' * Default: +inf
' * Type: ALfloat
' * Range:  0.0 - +inf
' */
%AL_MAX_DISTANCE                           = &H1023&

'/**
' * Sound samples: frequency, in units of Hertz [Hz].
' * This is the number of samples per second. Half of the
' *  sample frequency marks the maximum significant
' *  frequency component.
' */
%AL_FREQUENCY                              = &H2001&
%AL_BITS                                   = &H2002&
%AL_CHANNELS                               = &H2003&
%AL_SIZE                                   = &H2004&

'/**
' * Buffer state.
' *
' * Not supported for public use (yet).
' */
%AL_UNUSED                                 = &H2010&
%AL_PENDING                                = &H2011&
%AL_PROCESSED                              = &H2012&


'/** Errors: No Error. */
%AL_NO_ERROR                               = %AL_FALSE

'/**
' * Invalid Name paramater passed to AL call.
' */
%AL_INVALID_NAME                           = &HA001&

'/**
' * Invalid parameter passed to AL call.
' */
%AL_ILLEGAL_ENUM                           = &HA002&
%AL_INVALID_ENUM                           = &HA002&

'/**
' * Invalid enum parameter value.
' */
%AL_INVALID_VALUE                          = &HA003&

'/**
' * Illegal call.
' */
%AL_ILLEGAL_COMMAND                        = &HA004&
%AL_INVALID_OPERATION                      = &HA004&


'/**
' * No mojo.
' */
%AL_OUT_OF_MEMORY                          = &HA005&


'/** Context strings: Vendor Name. */
%AL_VENDOR                                 = &HB001&
%AL_VERSION                                = &HB002&
%AL_RENDERER                               = &HB003&
%AL_EXTENSIONS                             = &HB004&

'/** Global tweakage. */

'/**
' * Doppler scale.  Default 1.0
' */
%AL_DOPPLER_FACTOR                         = &HC000&

'/**
' * Tweaks speed of propagation.
' */
%AL_DOPPLER_VELOCITY                       = &HC001&

'/**
' * Speed of Sound in units per second
' */
%AL_SPEED_OF_SOUND                         = &HC003&

'/**
' * Distance models
' *
' * used in conjunction with DistanceModel
' *
' * implicit: NONE, which disances distance attenuation.
' */
%AL_DISTANCE_MODEL                         = &HD000&
%AL_INVERSE_DISTANCE                       = &HD001&
%AL_INVERSE_DISTANCE_CLAMPED               = &HD002&
%AL_LINEAR_DISTANCE                        = &HD003&
%AL_LINEAR_DISTANCE_CLAMPED                = &HD004&
%AL_EXPONENT_DISTANCE                      = &HD005&
%AL_EXPONENT_DISTANCE_CLAMPED              = &HD006&


'/*
' * Renderer State management
' */

' ========================================================================================
' AL_API void AL_APIENTRY alEnable( ALenum capability );
' ========================================================================================
DECLARE SUB alEnable CDECL IMPORT "OPENAL32.DLL" ALIAS "alEnable" ( _
   BYVAL capability AS LONG _                           ' ALenum capability
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alDisable( ALenum capability );
' ========================================================================================
DECLARE SUB alDisable CDECL IMPORT "OPENAL32.DLL" ALIAS "alDisable" ( _
   BYVAL capability AS LONG _                           ' ALenum capability
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API ALboolean AL_APIENTRY alIsEnabled( ALenum capability );
' ========================================================================================
DECLARE FUNCTION alIsEnabled CDECL IMPORT "OPENAL32.DLL" ALIAS "alIsEnabled" ( _
   BYVAL capability AS LONG _                        ' ALenum capability
 ) AS BYTE                                           ' ALboolean
' ========================================================================================


'/*
' * State retrieval
' */

' ========================================================================================
' AL_API const ALchar* AL_APIENTRY alGetString( ALenum param );
' ========================================================================================
DECLARE FUNCTION alGetString CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetString" ( _
   BYVAL param AS LONG _                                ' ALenum param
 ) AS DWORD                                             ' ALchar*
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBooleanv( ALenum param, ALboolean* data );
' ========================================================================================
DECLARE SUB alGetBooleanv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBooleanv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF data AS BYTE _                                 ' ALboolean* data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetIntegerv( ALenum param, ALint* data );
' ========================================================================================
DECLARE SUB alGetIntegerv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetIntegerv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF data AS LONG _                                 ' ALint* data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetFloatv( ALenum param, ALfloat* data );
' ========================================================================================
DECLARE SUB alGetFloatv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetFloatv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF data AS SINGLE _                               ' ALfloat* data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetDoublev( ALenum param, ALdouble* data );
' ========================================================================================
DECLARE SUB alGetDoublev CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetDoublev" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF data AS DOUBLE _                               ' ALdouble* data
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API ALboolean AL_APIENTRY alGetBoolean( ALenum param );
' ========================================================================================
DECLARE FUNCTION alGetBoolean CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBoolean" ( _
   BYVAL param AS LONG _                                ' ALenum param
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

' ========================================================================================
' AL_API ALint AL_APIENTRY alGetInteger( ALenum param );
' ========================================================================================
DECLARE FUNCTION alGetInteger CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetInteger" ( _
   BYVAL param AS LONG _                                ' ALenum param
 ) AS LONG                                              ' ALint
' ========================================================================================

' ========================================================================================
' AL_API ALfloat AL_APIENTRY alGetFloat( ALenum param );
' ========================================================================================
DECLARE FUNCTION alGetFloat CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetFloat" ( _
   BYVAL param AS LONG _                                ' ALenum param
 ) AS SINGLE                                            ' ALfloat
' ========================================================================================

' ========================================================================================
' AL_API ALdouble AL_APIENTRY alGetDouble( ALenum param );
' ========================================================================================
DECLARE FUNCTION alGetDouble CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetDouble" ( _
   BYVAL param AS LONG _                                ' ALenum param
 ) AS DOUBLE                                            ' ALdouble
' ========================================================================================


'/*
' * Error support.
' * Obtain the most recent error generated in the AL state machine.
' */

' ========================================================================================
' AL_API ALenum AL_APIENTRY alGetError( void );
' ========================================================================================
DECLARE FUNCTION alGetError CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetError" ( _
 ) AS LONG                                              ' ALenum
' ========================================================================================


'/*
' * Extension support.
' * Query for the presence of an extension, and obtain any appropriate
' * function pointers and enum values.
' */

' ========================================================================================
' AL_API ALboolean AL_APIENTRY alIsExtensionPresent( const ALchar* extname );
' ========================================================================================
DECLARE FUNCTION alIsExtensionPresent CDECL IMPORT "OPENAL32.DLL" ALIAS "alIsExtensionPresent" ( _
   BYREF extname AS ASCIIZ _                            ' const ALchar* extname
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

' ========================================================================================
' AL_API void* AL_APIENTRY alGetProcAddress( const ALchar* fname );
' ========================================================================================
DECLARE FUNCTION alGetProcAddress CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetProcAddress" ( _
   BYREF fname AS ASCIIZ _                              ' const ALchar* fname
 ) AS DWORD                                             ' void*
' ========================================================================================

' ========================================================================================
' AL_API ALenum AL_APIENTRY alGetEnumValue( const ALchar* ename );
' ========================================================================================
DECLARE FUNCTION alGetEnumValue CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetEnumValue" ( _
   BYREF ename AS ASCIIZ _                              ' const ALchar* ename
 ) AS LONG                                              ' ALenum
' ========================================================================================


'/*
' * LISTENER
' * Listener represents the location and orientation of the
' * 'user' in 3D-space.
' *
' * Properties include: -
' *
' * Gain         AL_GAIN         ALfloat
' * Position     AL_POSITION     ALfloat[3]
' * Velocity     AL_VELOCITY     ALfloat[3]
' * Orientation  AL_ORIENTATION  ALfloat[6] (Forward then Up vectors)
'*/

'/*
' * Set Listener parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alListenerf( ALenum param, ALfloat value );
' ========================================================================================
DECLARE SUB alListenerf CDECL IMPORT "OPENAL32.DLL" ALIAS "alListenerf" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alListener3f( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
' ========================================================================================
DECLARE SUB alListener3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alListener3f" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS SINGLE _                             ' ALfloat value1
 , BYVAL value2 AS SINGLE _                             ' ALfloat value2
 , BYVAL value3 AS SINGLE _                             ' ALfloat value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alListenerfv( ALenum param, const ALfloat* values );
' ========================================================================================
DECLARE SUB alListenerfv CDECL IMPORT "OPENAL32.DLL" ALIAS "alListenerfv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' const ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alListeneri( ALenum param, ALint value );
' ========================================================================================
DECLARE SUB alListeneri CDECL IMPORT "OPENAL32.DLL" ALIAS "alListeneri" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS LONG _                                ' ALint value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alListener3i( ALenum param, ALint value1, ALint value2, ALint value3 );
' ========================================================================================
DECLARE SUB alListener3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alListener3i" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS LONG _                               ' ALint value1
 , BYVAL value2 AS LONG _                               ' ALint value2
 , BYVAL value3 AS LONG _                               ' ALint value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alListeneriv( ALenum param, const ALint* values );
' ========================================================================================
DECLARE SUB alListeneriv CDECL IMPORT "OPENAL32.DLL" ALIAS "alListeneriv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' const ALfloat* values
 )                                                      ' void
' ========================================================================================

'/*
' * Get Listener parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alGetListenerf( ALenum param, ALfloat* value );
' ========================================================================================
DECLARE SUB alGetListenerf CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListenerf" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF value AS SINGLE _                              ' ALfloat* value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetListener3f( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 );
' ========================================================================================
DECLARE SUB alGetListener3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListener3f" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS SINGLE _                             ' ALfloat *value1
 , BYREF value2 AS SINGLE _                             ' ALfloat *value2
 , BYREF value3 AS SINGLE _                             ' ALfloat *value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetListenerfv( ALenum param, ALfloat* values );
' ========================================================================================
DECLARE SUB alGetListenerfv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListenerfv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetListeneri( ALenum param, ALint* value );
' ========================================================================================
DECLARE SUB alGetListeneri CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListeneri" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF value AS LONG _                                ' ALint* value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetListener3i( ALenum param, ALint *value1, ALint *value2, ALint *value3 );
' ========================================================================================
DECLARE SUB alGetListener3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListener3i" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS LONG _                               ' ALint *value1
 , BYREF value2 AS LONG _                               ' ALint *value2
 , BYREF value3 AS LONG _                               ' ALint *value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetListeneriv( ALenum param, ALint* values );
' ========================================================================================
DECLARE SUB alGetListeneriv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetListeneriv" ( _
   BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' ALint* values
 )                                                      ' void
' ========================================================================================


'/**
' * SOURCE
' * Sources represent individual sound objects in 3D-space.
' * Sources take the PCM data provided in the specified Buffer,
' * apply Source-specific modifications, and then
' * submit them to be mixed according to spatial arrangement etc.
' *
' * Properties include: -
' *
' * Gain                              AL_GAIN                 ALfloat
' * Min Gain                          AL_MIN_GAIN             ALfloat
' * Max Gain                          AL_MAX_GAIN             ALfloat
' * Position                          AL_POSITION             ALfloat[3]
' * Velocity                          AL_VELOCITY             ALfloat[3]
' * Direction                         AL_DIRECTION            ALfloat[3]
' * Head Relative Mode                AL_SOURCE_RELATIVE      ALint (AL_TRUE or AL_FALSE)
' * Reference Distance                AL_REFERENCE_DISTANCE   ALfloat
' * Max Distance                      AL_MAX_DISTANCE         ALfloat
' * RollOff Factor                    AL_ROLLOFF_FACTOR       ALfloat
' * Inner Angle                       AL_CONE_INNER_ANGLE     ALint or ALfloat
' * Outer Angle                       AL_CONE_OUTER_ANGLE     ALint or ALfloat
' * Cone Outer Gain                   AL_CONE_OUTER_GAIN      ALint or ALfloat
' * Pitch                             AL_PITCH                ALfloat
' * Looping                           AL_LOOPING              ALint (AL_TRUE or AL_FALSE)
' * MS Offset                         AL_MSEC_OFFSET          ALint or ALfloat
' * Byte Offset                       AL_BYTE_OFFSET          ALint or ALfloat
' * Sample Offset                     AL_SAMPLE_OFFSET        ALint or ALfloat
' * Attached Buffer                   AL_BUFFER               ALint
' * State (Query only)                AL_SOURCE_STATE         ALint
' * Buffers Queued (Query only)       AL_BUFFERS_QUEUED       ALint
' * Buffers Processed (Query only)    AL_BUFFERS_PROCESSED    ALint
' */

'/* Create Source objects */
' ========================================================================================
' AL_API void AL_APIENTRY alGenSources( ALsizei n, ALuint* sources );
' ========================================================================================
DECLARE SUB alGenSources CDECL IMPORT "OPENAL32.DLL" ALIAS "alGenSources" ( _
   BYVAL n AS LONG _                                    ' ALsizei n
 , BYREF sources AS DWORD _                             ' ALuint* sources
 )                                                      ' void
' ========================================================================================

'/* Delete Source objects */
' ========================================================================================
'AL_API void AL_APIENTRY alDeleteSources( ALsizei n, const ALuint* sources );
' ========================================================================================
DECLARE SUB alDeleteSources CDECL IMPORT "OPENAL32.DLL" ALIAS "alDeleteSources" ( _
   BYVAL n AS LONG _                                    ' ALsizei n
 , BYREF sources AS DWORD _                             ' ALuint* sources
 )                                                      ' void
' ========================================================================================

'/* Verify a handle is a valid Source */
' ========================================================================================
' AL_API ALboolean AL_APIENTRY alIsSource( ALuint sid );
' ========================================================================================
DECLARE FUNCTION alIsSource CDECL IMPORT "OPENAL32.DLL" ALIAS "alIsSource" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

'/*
' * Set Source parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alSourcef( ALuint sid, ALenum param, ALfloat value );
' ========================================================================================
DECLARE SUB alSourcef CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcef" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSource3f( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
' ========================================================================================
DECLARE SUB alSource3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alSource3f" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS SINGLE _                             ' ALfloat value1
 , BYVAL value2 AS SINGLE _                             ' ALfloat value2
 , BYVAL value3 AS SINGLE _                             ' ALfloat value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSourcefv( ALuint sid, ALenum param, const ALfloat* values );
' ========================================================================================
DECLARE SUB alSourcefv CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcefv" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSourcei( ALuint sid, ALenum param, ALint value );
' ========================================================================================
DECLARE SUB alSourcei CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcei" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS LONG _                                ' ALint value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSource3i( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 );
' ========================================================================================
DECLARE SUB alSource3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alSource3i" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS LONG _                               ' ALint value1
 , BYVAL value2 AS LONG _                               ' ALint value2
 , BYVAL value3 AS LONG _                               ' ALint value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSourceiv( ALuint sid, ALenum param, const ALint* values );
' ========================================================================================
DECLARE SUB alSourceiv CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceiv" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' const ALint* values
 )                                                      ' void
' ========================================================================================

'/*
' * Get Source parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alGetSourcef( ALuint sid, ALenum param, ALfloat* value );
' ========================================================================================
DECLARE SUB alGetSourcef CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSourcef" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value AS SINGLE _                              ' ALfloat* value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetSource3f( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
' ========================================================================================
DECLARE SUB alGetSource3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSource3f" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS SINGLE _                             ' ALfloat* value1
 , BYREF value2 AS SINGLE _                             ' ALfloat* value2
 , BYREF value3 AS SINGLE _                             ' ALfloat* value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetSourcefv( ALuint sid, ALenum param, ALfloat* values );
' ========================================================================================
DECLARE SUB alGetSourcefv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSourcefv" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetSourcei( ALuint sid,  ALenum param, ALint* value );
' ========================================================================================
DECLARE SUB alGetSourcei CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSourcei" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' ALint* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetSource3i( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
' ========================================================================================
DECLARE SUB alGetSource3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSource3i" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS LONG _                               ' ALint* value1
 , BYREF value2 AS LONG _                               ' ALint* value2
 , BYREF value3 AS LONG _                               ' ALint* value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetSourceiv( ALuint sid,  ALenum param, ALint* values );
' ========================================================================================
DECLARE SUB alGetSourceiv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetSourceiv" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' ALint* values
 )                                                      ' void
' ========================================================================================


'/*
' * Source vector based playback calls
' */

'/* Play, replay, or resume (if paused) a list of Sources */
' ========================================================================================
' AL_API void AL_APIENTRY alSourcePlayv( ALsizei ns, const ALuint *sids );
' ========================================================================================
DECLARE SUB alSourcePlayv CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcePlayv" ( _
   BYVAL ns AS LONG _                                   ' ALsizei ns
 , BYREF sids AS DWORD _                                ' const ALuint *sids
 )                                                      ' void
' ========================================================================================

'/* Stop a list of Sources */
' ========================================================================================
' AL_API void AL_APIENTRY alSourceStopv( ALsizei ns, const ALuint *sids );
' ========================================================================================
DECLARE SUB alSourceStopv CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceStopv" ( _
   BYVAL ns AS LONG _                                   ' ALsizei ns
 , BYREF sids AS DWORD _                                ' const ALuint *sids
 )                                                      ' void
' ========================================================================================

'/* Rewind a list of Sources */
' ========================================================================================
' AL_API void AL_APIENTRY alSourceRewindv( ALsizei ns, const ALuint *sids );
' ========================================================================================
DECLARE SUB alSourceRewindv CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceRewindv" ( _
   BYVAL ns AS LONG _                                   ' ALsizei ns
 , BYREF sids AS DWORD _                                ' const ALuint *sids
 )                                                      ' void
' ========================================================================================

'/* Pause a list of Sources */
' ========================================================================================
' AL_API void AL_APIENTRY alSourcePausev( ALsizei ns, const ALuint *sids );
' ========================================================================================
DECLARE SUB alSourcePausev CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcePausev" ( _
   BYVAL ns AS LONG _                                   ' ALsizei ns
 , BYREF sids AS DWORD _                                ' const ALuint *sids
 )                                                      ' void
' ========================================================================================

'/*
' * Source based playback calls
' */

'/* Play, replay, or resume a Source */
' ========================================================================================
' AL_API void AL_APIENTRY alSourcePlay( ALuint sid );
' ========================================================================================
DECLARE SUB alSourcePlay CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcePlay" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 )                                                      ' void
' ========================================================================================

'/* Stop a Source */
' ========================================================================================
' AL_API void AL_APIENTRY alSourceStop( ALuint sid );
' ========================================================================================
DECLARE SUB alSourceStop CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceStop" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 )                                                      ' void
' ========================================================================================

'/* Rewind a Source (set playback postiton to beginning) */
' ========================================================================================
' AL_API void AL_APIENTRY alSourceRewind( ALuint sid );
' ========================================================================================
DECLARE SUB alSourceRewind CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceRewind" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 )                                                      ' void
' ========================================================================================

'/* Pause a Source */
' ========================================================================================
' AL_API void AL_APIENTRY alSourcePause( ALuint sid );
' ========================================================================================
DECLARE SUB alSourcePause CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourcePause" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 )                                                      ' void
' ========================================================================================

'/*
' * Source Queuing
' */

' ========================================================================================
' AL_API void AL_APIENTRY alSourceQueueBuffers( ALuint sid, ALsizei numEntries, const ALuint *bids );
' ========================================================================================
DECLARE SUB alSourceQueueBuffers CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceQueueBuffers" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL numEntries AS LONG _                           ' ALsizei numEntries
 , BYREF bids AS DWORD _                                ' const ALuint *bids
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSourceUnqueueBuffers( ALuint sid, ALsizei numEntries, ALuint *bids );
' ========================================================================================
DECLARE SUB alSourceUnqueueBuffers CDECL IMPORT "OPENAL32.DLL" ALIAS "alSourceUnqueueBuffers" ( _
   BYVAL sid AS DWORD _                                 ' ALuint sid
 , BYVAL numEntries AS LONG _                           ' ALsizei numEntries
 , BYREF bids AS DWORD _                                ' ALuint *bids
 )                                                      ' void
' ========================================================================================


'/**
' * BUFFER
' * Buffer objects are storage space for sample data.
' * Buffers are referred to by Sources. One Buffer can be used
' * by multiple Sources.
' *
' * Properties include: -
' *
' * Frequency (Query only)    AL_FREQUENCY      ALint
' * Size (Query only)         AL_SIZE           ALint
' * Bits (Query only)         AL_BITS           ALint
' * Channels (Query only)     AL_CHANNELS       ALint
' */

'/* Create Buffer objects */
' ========================================================================================
' AL_API void AL_APIENTRY alGenBuffers( ALsizei n, ALuint* buffers );
' ========================================================================================
DECLARE SUB alGenBuffers CDECL IMPORT "OPENAL32.DLL" ALIAS "alGenBuffers" ( _
   BYVAL n AS LONG _                                    ' ALsizei n
 , BYREF buffers AS DWORD _                             ' ALuint* buffers
 )                                                      ' void
' ========================================================================================

'/* Delete Buffer objects */
' ========================================================================================
' AL_API void AL_APIENTRY alDeleteBuffers( ALsizei n, const ALuint* buffers );
' ========================================================================================
DECLARE SUB alDeleteBuffers CDECL IMPORT "OPENAL32.DLL" ALIAS "alDeleteBuffers" ( _
   BYVAL n AS LONG _                                    ' ALsizei n
 , BYREF buffers AS DWORD _                             ' const ALuint* buffers
 )                                                      ' void
' ========================================================================================

'/* Verify a handle is a valid Buffer */
' ========================================================================================
' AL_API ALboolean AL_APIENTRY alIsBuffer( ALuint bid );
' ========================================================================================
DECLARE FUNCTION alIsBuffer CDECL IMPORT "OPENAL32.DLL" ALIAS "alIsBuffer" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

'/* Specify the data to be copied into a buffer */
' ========================================================================================
' AL_API void AL_APIENTRY alBufferData( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq );
' ========================================================================================
DECLARE SUB alBufferData CDECL IMPORT "OPENAL32.DLL" ALIAS "alBufferData" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL format AS LONG _                               ' ALenum format
 , BYREF data AS ANY _                                  ' const ALvoid* data
 , BYVAL size AS LONG _                                 ' ALsizei size
 , BYVAL freq AS LONG _                                 ' ALsizei freq
 )                                                      ' void
' ========================================================================================

'/*
' * Set Buffer parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alBufferf( ALuint bid, ALenum param, ALfloat value );
' ========================================================================================
DECLARE SUB alBufferf CDECL IMPORT "OPENAL32.DLL" ALIAS "alBufferf" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alBuffer3f( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
' ========================================================================================
DECLARE SUB alBuffer3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alBuffer3f" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS SINGLE _                             ' ALfloat value1
 , BYVAL value2 AS SINGLE _                             ' ALfloat value2
 , BYVAL value3 AS SINGLE _                             ' ALfloat value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alBufferfv( ALuint bid, ALenum param, const ALfloat* values );
' ========================================================================================
DECLARE SUB alBufferfv CDECL IMPORT "OPENAL32.DLL" ALIAS "alBufferfv" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' const ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alBufferi( ALuint bid, ALenum param, ALint value );
' ========================================================================================
DECLARE SUB alBufferi CDECL IMPORT "OPENAL32.DLL" ALIAS "alBufferi" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value AS LONG _                                ' ALint value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alBuffer3i( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 );
' ========================================================================================
DECLARE SUB alBuffer3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alBuffer3i" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYVAL value1 AS LONG _                               ' ALint value1
 , BYVAL value2 AS LONG _                               ' ALint value2
 , BYVAL value3 AS LONG _                               ' ALint value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alBufferiv( ALuint bid, ALenum param, const ALint* values );
' ========================================================================================
DECLARE SUB alBufferiv CDECL IMPORT "OPENAL32.DLL" ALIAS "alBufferiv" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' const ALint* values
 )                                                      ' void
' ========================================================================================

'/*
' * Get Buffer parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alGetBufferf( ALuint bid, ALenum param, ALfloat* value );
' ========================================================================================
DECLARE SUB alGetBufferf CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBufferf" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value AS SINGLE _                              ' ALfloat* value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBuffer3f( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
' ========================================================================================
DECLARE SUB alGetBuffer3f CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBuffer3f" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS SINGLE _                             ' ALfloat* value1
 , BYREF value2 AS SINGLE _                             ' ALfloat* value2
 , BYREF value3 AS SINGLE _                             ' ALfloat* value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBufferfv( ALuint bid, ALenum param, ALfloat* values );
' ========================================================================================
DECLARE SUB alGetBufferfv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBufferfv" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS SINGLE _                             ' ALfloat* values
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBufferi( ALuint bid, ALenum param, ALint* value );
' ========================================================================================
DECLARE SUB alGetBufferi CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBufferi" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value AS LONG _                                ' ALint* value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBuffer3i( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
' ========================================================================================
DECLARE SUB alGetBuffer3i CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBuffer3i" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF value1 AS LONG _                               ' ALint* value1
 , BYREF value2 AS LONG _                               ' ALint* value2
 , BYREF value3 AS LONG _                               ' ALint* value3
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alGetBufferiv( ALuint bid, ALenum param, ALint* values );
' ========================================================================================
DECLARE SUB alGetBufferiv CDECL IMPORT "OPENAL32.DLL" ALIAS "alGetBufferiv" ( _
   BYVAL bid AS DWORD _                                 ' ALuint bid
 , BYVAL param AS LONG _                                ' ALenum param
 , BYREF values AS LONG _                               ' ALint* values
 )                                                      ' void
' ========================================================================================


'/*
' * Global Parameters
' */

' ========================================================================================
' AL_API void AL_APIENTRY alDopplerFactor( ALfloat value );
' ========================================================================================
DECLARE SUB alDopplerFactor CDECL IMPORT "OPENAL32.DLL" ALIAS "alDopplerFactor" ( _
   BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alDopplerVelocity( ALfloat value );
' ========================================================================================
DECLARE SUB alDopplerVelocity CDECL IMPORT "OPENAL32.DLL" ALIAS "alDopplerVelocity" ( _
   BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alSpeedOfSound( ALfloat value );
' ========================================================================================
DECLARE SUB alSpeedOfSound CDECL IMPORT "OPENAL32.DLL" ALIAS "alSpeedOfSound" ( _
   BYVAL value AS SINGLE _                              ' ALfloat value
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' AL_API void AL_APIENTRY alDistanceModel( ALenum distanceModel );
' ========================================================================================
DECLARE SUB alDistanceModel CDECL IMPORT "OPENAL32.DLL" ALIAS "alDistanceModel" ( _
   BYVAL distanceModel AS LONG _                        ' ALenum distanceModel
 )                                                      ' void
' ========================================================================================
