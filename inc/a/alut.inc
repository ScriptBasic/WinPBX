' ########################################################################################
' OpenAL - Open Audio Library
' ########################################################################################

#INCLUDE THIS ONCE
%ALUT_INC = 1

#INCLUDE ONCE "alc.inc"
#INCLUDE ONCE "al.inc"

%ALUT_API_MAJOR_VERSION                 = 1
%ALUT_API_MINOR_VERSION                 = 1

%ALUT_ERROR_NO_ERROR                    = 0
%ALUT_ERROR_OUT_OF_MEMORY               = &H200&
%ALUT_ERROR_INVALID_ENUM                = &H201&
%ALUT_ERROR_INVALID_VALUE               = &H202&
%ALUT_ERROR_INVALID_OPERATION           = &H203&
%ALUT_ERROR_NO_CURRENT_CONTEXT          = &H204&
%ALUT_ERROR_AL_ERROR_ON_ENTRY           = &H205&
%ALUT_ERROR_ALC_ERROR_ON_ENTRY          = &H206&
%ALUT_ERROR_OPEN_DEVICE                 = &H207&
%ALUT_ERROR_CLOSE_DEVICE                = &H208&
%ALUT_ERROR_CREATE_CONTEXT              = &H209&
%ALUT_ERROR_MAKE_CONTEXT_CURRENT        = &H20A&
%ALUT_ERROR_DESTROY_CONTEXT             = &H20B&
%ALUT_ERROR_GEN_BUFFERS                 = &H20C&
%ALUT_ERROR_BUFFER_DATA                 = &H20D&
%ALUT_ERROR_IO_ERROR                    = &H20E&
%ALUT_ERROR_UNSUPPORTED_FILE_TYPE       = &H20F&
%ALUT_ERROR_UNSUPPORTED_FILE_SUBTYPE    = &H210&
%ALUT_ERROR_CORRUPT_OR_TRUNCATED_DATA   = &H211&

%ALUT_WAVEFORM_SINE                     = &H100&
%ALUT_WAVEFORM_SQUARE                   = &H101&
%ALUT_WAVEFORM_SAWTOOTH                 = &H102&
%ALUT_WAVEFORM_WHITENOISE               = &H103&
%ALUT_WAVEFORM_IMPULSE                  = &H104&

%ALUT_LOADER_BUFFER                     = &H300&
%ALUT_LOADER_MEMORY                     = &H301&

' ========================================================================================
' ALUT_API ALboolean ALUT_APIENTRY alutInit (int *argcp, char **argv);
' ========================================================================================
DECLARE FUNCTION alutInit CDECL IMPORT "ALUT.DLL" ALIAS "alutInit" ( _
   BYREF argcp AS LONG _                                ' int *argcp
 , BYREF argv AS STRING _                               ' char **argv
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

' ========================================================================================
' ALUT_API ALboolean ALUT_APIENTRY alutInitWithoutContext (int *argcp, char **argv);
' ========================================================================================
DECLARE FUNCTION alutInitWithoutContext CDECL IMPORT "ALUT.DLL" ALIAS "alutInitWithoutContext" ( _
   BYREF argcp AS LONG _                                ' int *argcp
 , BYREF argv AS STRING _                               ' char **argv
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

' ========================================================================================
' ALUT_API ALboolean ALUT_APIENTRY alutExit (void);
' ========================================================================================
DECLARE FUNCTION alutExit CDECL IMPORT "ALUT.DLL" ALIAS "alutExit" ( _
 ) AS BYTE                                              ' ALboolean
' ========================================================================================

' ========================================================================================
' ALUT_API ALenum ALUT_APIENTRY alutGetError (void);
' ========================================================================================
DECLARE FUNCTION alutGetError CDECL IMPORT "ALUT.DLL" ALIAS "alutGetError" ( _
 ) AS LONG                                              ' ALenum
' ========================================================================================

' ========================================================================================
' ALUT_API const char *ALUT_APIENTRY alutGetErrorString (ALenum error);
' ========================================================================================
DECLARE FUNCTION alutGetErrorString CDECL IMPORT "ALUT.DLL" ALIAS "alutGetErrorString" ( _
   BYVAL error AS LONG _                                ' ALenum error
 ) AS DWORD                                             ' const char*
' ========================================================================================

' ========================================================================================
' ALUT_API ALuint ALUT_APIENTRY alutCreateBufferFromFile (const char *fileName);
' ========================================================================================
DECLARE FUNCTION alutCreateBufferFromFile CDECL IMPORT "ALUT.DLL" ALIAS "alutCreateBufferFromFile" ( _
   BYREF filename AS ASCIIZ _                           ' const char *filename
 ) AS DWORD                                             ' ALuint
' ========================================================================================

' ========================================================================================
' ALUT_API ALuint ALUT_APIENTRY alutCreateBufferFromFileImage (const ALvoid *data, ALsizei length);
' ========================================================================================
DECLARE FUNCTION alutCreateBufferFromFileImage CDECL IMPORT "ALUT.DLL" ALIAS "alutCreateBufferFromFileImage" ( _
   BYREF data AS ANY _                                  ' const ALvoid *data
 , BYVAL length AS LONG _                               ' ALsizei length
 ) AS DWORD                                             ' ALuint
' ========================================================================================

' ========================================================================================
' ALUT_API ALuint ALUT_APIENTRY alutCreateBufferHelloWorld (void);
' ========================================================================================
DECLARE FUNCTION alutCreateBufferHelloWorld CDECL IMPORT "ALUT.DLL" ALIAS "alutCreateBufferHelloWorld" ( _
 ) AS DWORD                                             ' ALuint
' ========================================================================================

' ========================================================================================
' ALUT_API ALuint ALUT_APIENTRY alutCreateBufferWaveform (ALenum waveshape, ALfloat frequency, ALfloat phase, ALfloat duration);
' ========================================================================================
DECLARE FUNCTION alutCreateBufferWaveform CDECL IMPORT "ALUT.DLL" ALIAS "alutCreateBufferWaveform" ( _
   BYVAL waveshape AS DWORD _                           ' ALenum waveshape
 , BYVAL frequency AS SINGLE _                          ' ALfloat frequency
 , BYVAL phase AS SINGLE _                              ' ALfloat phase
 , BYVAL duration AS SINGLE _                           ' ALfloat duration
 ) AS DWORD                                             ' ALuint
' ========================================================================================

' ========================================================================================
' ALUT_API ALvoid *ALUT_APIENTRY alutLoadMemoryFromFile (const char *fileName, ALenum *format, ALsizei *size, ALfloat *frequency);
' ========================================================================================
DECLARE FUNCTION alutLoadMemoryFromFile CDECL IMPORT "ALUT.DLL" ALIAS "alutLoadMemoryFromFile" ( _
   BYREF fileName AS ASCIIZ _                           ' const char *fileName
 , BYREF format AS LONG _                               ' ALenum *format
 , BYREF size AS LONG _                                 ' ALsizei *size
 , BYREF frequency AS SINGLE _                          ' ALfloat *frequency
 ) AS DWORD                                             ' ALvoid*
' ========================================================================================

' ========================================================================================
' ALUT_API ALvoid *ALUT_APIENTRY alutLoadMemoryFromFileImage (const ALvoid *data, ALsizei length, ALenum *format, ALsizei *size, ALfloat *frequency);
' ========================================================================================
DECLARE FUNCTION alutLoadMemoryFromFileImage CDECL IMPORT "ALUT.DLL" ALIAS "alutLoadMemoryFromFileImage" ( _
   BYREF data AS ANY _                                  ' const ALvoid *data
 , BYVAL length AS LONG _                               ' ALsizei length
 , BYREF format AS LONG _                               ' ALenum *format
 , BYREF size AS LONG _                                 ' ALsizei *size
 , BYREF frequency AS SINGLE _                          ' ALfloat *frequency
 ) AS DWORD                                             ' ALvoid*
' ========================================================================================

' ========================================================================================
' ALUT_API ALvoid *ALUT_APIENTRY alutLoadMemoryHelloWorld (ALenum *format, ALsizei *size, ALfloat *frequency);
' ========================================================================================
DECLARE FUNCTION alutLoadMemoryHelloWorld CDECL IMPORT "ALUT.DLL" ALIAS "alutLoadMemoryHelloWorld" ( _
   BYREF format AS LONG _                               ' ALenum *format
 , BYREF size AS LONG _                                 ' ALsizei *size
 , BYREF frequency AS SINGLE _                          ' ALfloat *frequency
 ) AS DWORD                                             ' ALvoid*
' ========================================================================================

' ========================================================================================
' ALUT_API ALvoid *ALUT_APIENTRY alutLoadMemoryWaveform (ALenum waveshape, ALfloat frequency, ALfloat phase, ALfloat duration, ALenum *format, ALsizei *size, ALfloat *freq);
' ========================================================================================
DECLARE FUNCTION alutLoadMemoryWaveform CDECL IMPORT "ALUT.DLL" ALIAS "alutLoadMemoryWaveform" ( _
   BYVAL waveshape AS LONG _                            ' ALenum waveshape
 , BYVAL frequency AS SINGLE _                          ' ALfloat frequency
 , BYVAL phase AS SINGLE _                              ' ALfloat phase
 , BYVAL duration AS SINGLE _                           ' ALfloat duration
 , BYREF format AS LONG _                               ' ALenum *format
 , BYREF size AS LONG _                                 ' ALsizei *size
 , BYREF freq AS SINGLE _                               ' ALfloat *freq
 ) AS DWORD                                             ' ALvoid*
' ========================================================================================

' ========================================================================================
' ALUT_API const char *ALUT_APIENTRY alutGetMIMETypes (ALenum loader);
' ========================================================================================
DECLARE FUNCTION alutGetMIMETypes CDECL IMPORT "ALUT.DLL" ALIAS "alutGetMIMETypes" ( _
   BYVAL loader AS LONG _                               ' ALenum loader
 ) AS DWORD                                             ' const char*
' ========================================================================================

' ========================================================================================
' ALUT_API ALint ALUT_APIENTRY alutGetMajorVersion (void);
' ========================================================================================
DECLARE FUNCTION alutGetMajorVersion CDECL IMPORT "ALUT.DLL" ALIAS "alutGetMajorVersion" ( _
 ) AS LONG                                              ' ALint
' ========================================================================================

' ========================================================================================
' ALUT_API ALint ALUT_APIENTRY alutGetMinorVersion (void);
' ========================================================================================
DECLARE FUNCTION alutGetMinorVersion CDECL IMPORT "ALUT.DLL" ALIAS "alutGetMinorVersion" ( _
 ) AS LONG                                              ' ALint
' ========================================================================================

' ========================================================================================
' ALUT_API ALboolean ALUT_APIENTRY alutSleep (ALfloat duration);
' ========================================================================================
DECLARE FUNCTION alutSleep CDECL IMPORT "ALUT.DLL" ALIAS "alutSleep" ( _
   BYVAL duration AS SINGLE _                           ' ALfloat duration
 ) AS BYTE                                              ' ALboolean
' ========================================================================================
