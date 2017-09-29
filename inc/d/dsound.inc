' ########################################################################################
' Microsoft Windows
' File: dsound.inc
' Contents: DirectSound include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSOUND_INC = 1

#INCLUDE ONCE "objbase.inc"

#IF NOT %DEF(%DIRECTSOUND_VERSION)
%DIRECTSOUND_VERSION = &H0900   '   /* Version 9.0 */
#ENDIF

'#ifndef DX_SHARED_DEFINES
'typedef float D3DVALUE, *LPD3DVALUE;
'#ifndef D3DCOLOR_DEFINED
'typedef DWORD D3DCOLOR;
'#define D3DCOLOR_DEFINED
'#endif

'#define _FACDS  0x878   /* DirectSound's facility code */
'#define MAKE_DSHRESULT(code)  MAKE_HRESULT(1, _FACDS, code)

#IF NOT %DEF(%D3DVECTOR_DEFINED)
' // Size = 12 bytes
TYPE D3DVECTOR DWORD
   x AS SINGLE
   y AS SINGLE
   z AS SINGLE
END TYPE
%D3DVECTOR_DEFINED = 1
#ENDIF

%FACDS = &H878

FUNCTION MAKE_DSHRESULT (BYVAL dwCode AS DWORD) AS DWORD
   LOCAL sev AS DWORD
   LOCAL fac AS DWORD
   sev = 1
   fac = &H878
   SHIFT LEFT sev, 31
   SHIFT LEFT fac, 16
   FUNCTION = (sev OR fac OR dwCode)
END FUNCTION

'#define DX_SHARED_DEFINES
'#endif // DX_SHARED_DEFINES

'// DirectSound Component GUID {47D4D946-62E8-11CF-93BC-444553540000}
$CLSID_DirectSound                     = GUID$("{47D4D946-62E8-11CF-93BC-444553540000}")

'// DirectSound 8.0 Component GUID {3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}
$CLSID_DirectSound8                    = GUID$("{3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}")

'// DirectSound Capture Component GUID {B0210780-89CD-11D0-AF08-00A0C925CD16}
$CLSID_DirectSoundCapture              = GUID$("{B0210780-89CD-11D0-AF08-00A0C925CD16}")

'// DirectSound 8.0 Capture Component GUID {E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}
$CLSID_DirectSoundCapture8             = GUID$("{E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}")

'// DirectSound Full Duplex Component GUID {FEA4300C-7959-4147-B26A-2377B9E7A91D}
$CLSID_DirectSoundFullDuplex           = GUID$("{FEA4300C-7959-4147-B26A-2377B9E7A91D}")

'// DirectSound default playback device GUID {DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}
$DSDEVID_DefaultPlayback               = GUID$("{DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}")

'// DirectSound default capture device GUID {DEF00001-9C6D-47ED-AAF1-4DDA8F2B5C03}
$DSDEVID_DefaultCapture                = GUID$("{DEF00001-9C6D-47ED-AAF1-4DDA8F2B5C03}")

'// DirectSound default device for voice playback {DEF00002-9C6D-47ED-AAF1-4DDA8F2B5C03}
$DSDEVID_DefaultVoicePlayback          = GUID$("{DEF00002-9C6D-47ED-AAF1-4DDA8F2B5C03}")

'// DirectSound default device for voice capture {DEF00003-9C6D-47ED-AAF1-4DDA8F2B5C03}
$DSDEVID_DefaultVoiceCapture           = GUID$("{DEF00003-9C6D-47ED-AAF1-4DDA8F2B5C03}")


' DirectSound Interface GUIDs
' The following GUIDs are used as interface identifiers (IIDs) to obtain DirectSound interfaces.
' Note   Where an interface has not changed from previous versions of DirectX, the IID in the
' table is defined in Dsound.h as the original IID. For example, IID_IDirectSound3DBuffer8 is
' defined as IID_IDirectSound3DBuffer, because IDirectSoundBuffer8 is the same as
' IDirectSoundBuffer.

$IID_IDirectSound                       = GUID$("{279AFA83-4981-11CE-A521-0020AF0BE560}")
$IID_IDirectSound8                      = GUID$("{C50A7E93-F395-4834-9EF6-7FA99DE50966}")
$IID_IDirectSoundBuffer                 = GUID$("{279AFA85-4981-11CE-A521-0020AF0BE560}")
$IID_IDirectSoundBuffer8                = GUID$("{6825a449-7524-4d82-920f-50e36ab3ab1e}")
$IID_IDirectSound3DBuffer               = GUID$("{279AFA86-4981-11CE-A521-0020AF0BE560}")
$IID_IDirectSound3DListener             = GUID$("{279AFA84-4981-11CE-A521-0020AF0BE560}")
$IID_IDirectSoundCapture                = GUID$("{b0210781-89cd-11d0-af08-00a0c925cd16}")
$IID_IDirectSoundCapture8               = GUID$("{b0210781-89cd-11d0-af08-00a0c925cd16}")
$IID_IDirectSoundCaptureBuffer          = GUID$("{b0210782-89cd-11d0-af08-00a0c925cd16}")
$IID_IDirectSoundCaptureBuffer8         = GUID$("{00990df4-0dbb-4872-833e-6d303e80aeb6}")
$IID_IDirectSoundCaptureFXAec           = GUID$("{ad74143d-903d-4ab7-8066-28d363036d65}")
$IID_IDirectSoundCaptureFXNoiseSuppress = GUID$("{ed311e41-fbae-4175-9625-cd0854f693ca}")
$IID_IDirectSoundFullDuplex             = GUID$("{edcb4c7a-daab-4216-a42e-6c50596ddc1d}")
$IID_IDirectSoundFXChorus               = GUID$("{880842e3-145f-43e6-a934-a71806e50547}")
$IID_IDirectSoundFXCompressor           = GUID$("{4bbd1154-62f6-4e2c-a15c-d3b6c417f7a0}")
$IID_IDirectSoundFXDistortion           = GUID$("{8ecf4326-455f-4d8b-bda9-8d5d3e9e3e0b}")
$IID_IDirectSoundFXEcho                 = GUID$("{8bd28edf-50db-4e92-a2bd-445488d1ed42}")
$IID_IDirectSoundFXFlanger              = GUID$("{903e9878-2c92-4072-9b2c-ea68f5396783}")
$IID_IDirectSoundFXGargle               = GUID$("{d616f352-d622-11ce-aac5-0020af0b99a3}")
$IID_IDirectSoundFXI3DL2Reverb          = GUID$("{4b166a6a-0d66-43f3-80e3-ee6280dee1a4}")
$IID_IDirectSoundFXParamEq              = GUID$("{c03ca9fe-fe90-4204-8078-82334cd177da}")
$IID_IDirectSoundFXWavesReverb          = GUID$("{46858c3a-0dc6-45e3-b760-d4eef16cb325}")
$IID_IDirectSoundNotify                 = GUID$("{b0210783-89cd-11d0-af08-00a0c925cd16}")

' // Size = 96 bytes
TYPE DSCAPS DWORD
   dwSize                         AS DWORD
   dwFlags                        AS DWORD
   dwMinSecondarySampleRate       AS DWORD
   dwMaxSecondarySampleRate       AS DWORD
   dwPrimaryBuffers               AS DWORD
   dwMaxHwMixingAllBuffers        AS DWORD
   dwMaxHwMixingStaticBuffers     AS DWORD
   dwMaxHwMixingStreamingBuffers  AS DWORD
   dwFreeHwMixingAllBuffers       AS DWORD
   dwFreeHwMixingStaticBuffers    AS DWORD
   dwFreeHwMixingStreamingBuffers AS DWORD
   dwMaxHw3DAllBuffers            AS DWORD
   dwMaxHw3DStaticBuffers         AS DWORD
   dwMaxHw3DStreamingBuffers      AS DWORD
   dwFreeHw3DAllBuffers           AS DWORD
   dwFreeHw3DStaticBuffers        AS DWORD
   dwFreeHw3DStreamingBuffers     AS DWORD
   dwTotalHwMemBytes              AS DWORD
   dwFreeHwMemBytes               AS DWORD
   dwMaxContigFreeHwMemBytes      AS DWORD
   dwUnlockTransferRateHwBuffers  AS DWORD
   dwPlayCpuOverheadSwBuffers     AS DWORD
   dwReserved1                    AS DWORD
   dwReserved2                    AS DWORD
END TYPE

' // Size = 20 bytes
TYPE DSBCAPS DWORD
   dwSize               AS DWORD
   dwFlags              AS DWORD
   dwBufferBytes        AS DWORD
   dwUnlockTransferRate AS DWORD
   dwPlayCpuOverhead    AS DWORD
END TYPE

#IF %DIRECTSOUND_VERSION >= &H0800

' // Size = 32 bytes
TYPE DSEFFECTDESC DWORD
   dwSize        AS DWORD
   dwFlags       AS DWORD
   guidDSFXClass AS GUID
   dwReserved1   AS DWORD PTR
   dwReserved2   AS DWORD PTR
END TYPE

%DSFX_LOCHARDWARE = &H00000001???
%DSFX_LOCSOFTWARE = &H00000002???

%DSFXR_PRESENT          = 0
%DSFXR_LOCHARDWARE      = 1
%DSFXR_LOCSOFTWARE      = 2
%DSFXR_UNALLOCATED      = 3
%DSFXR_FAILED           = 4
%DSFXR_UNKNOWN          = 5
%DSFXR_SENDLOOP         = 6

' // Size = 48 bytes
TYPE DSCEFFECTDESC DWORD
   dwSize            AS DWORD
   dwFlags           AS DWORD
   guidDSCFXClass    AS GUID
   guidDSCFXInstance AS GUID
   dwReserved1       AS DWORD
   dwReserved2       AS DWORD
END TYPE

%DSCFX_LOCHARDWARE  = &H00000001???
%DSCFX_LOCSOFTWARE  = &H00000002???

%DSCFXR_LOCHARDWARE = &H00000010???
%DSCFXR_LOCSOFTWARE = &H00000020???

' // Size = 36 bytes
TYPE DSBUFFERDESC DWORD
   dwSize          AS DWORD
   dwFlags         AS DWORD
   dwBufferBytes   AS DWORD
   dwReserved      AS DWORD
   lpwfxFormat     AS WAVEFORMATEX PTR
#IF %DIRECTSOUND_VERSION >= &H0700
   guid3DAlgorithm AS GUID
#ENDIF
END TYPE

#ENDIF  ' // DIRECTSOUND_VERSION >= 0x0800

'// Older version of this structure:

' // Size = 20 bytes
TYPE DSBUFFERDESC1 DWORD
   dwSize        AS DWORD
   dwFlags       AS DWORD
   dwBufferBytes AS DWORD
   dwReserved    AS DWORD
   lpwfxFormat   AS WAVEFORMATEX PTR
END TYPE

' // Size = 64 bytes
TYPE DS3DBUFFER DWORD
   dwSize             AS DWORD
   vPosition          AS D3DVECTOR
   vVelocity          AS D3DVECTOR
   dwInsideConeAngle  AS DWORD
   dwOutsideConeAngle AS DWORD
   vConeOrientation   AS D3DVECTOR
   lConeOutsideVolume AS LONG
   flMinDistance      AS SINGLE   ' D3DVALUE
   flMaxDistance      AS SINGLE   ' D3DVALUE
   dwMode             AS DWORD
END TYPE

' // Size = 64 bytes
TYPE DS3DLISTENER DWORD
   dwSize           AS DWORD
   vPosition        AS D3DVECTOR
   vVelocity        AS D3DVECTOR
   vOrientFront     AS D3DVECTOR
   vOrientTop       AS D3DVECTOR
   flDistanceFactor AS SINGLE   ' D3DVALUE
   flRolloffFactor  AS SINGLE   ' D3DVALUE
   flDopplerFactor  AS SINGLE   ' D3DVALUE
END TYPE

' // Size = 16 bytes
TYPE DSCCAPS DWORD
   dwSize     AS DWORD
   dwFlags    AS DWORD
   dwFormats  AS DWORD
   dwChannels AS DWORD
END TYPE

' // Size = 20 bytes
TYPE DSCBUFFERDESC1 DWORD
   dwSize        AS DWORD
   dwFlags       AS DWORD
   dwBufferBytes AS DWORD
   dwReserved    AS DWORD
   lpwfxFormat   AS WAVEFORMATEX PTR
END TYPE

' // Size = 28 bytes
TYPE DSCBUFFERDESC DWORD
   dwSize        AS DWORD
   dwFlags       AS DWORD
   dwBufferBytes AS DWORD
   dwReserved    AS DWORD
   lpwfxFormat   AS WAVEFORMATEX PTR
#IF %DIRECTSOUND_VERSION >= &H0800
   dwFXCount     AS DWORD
   lpDSCFXDesc   AS DSCEFFECTDESC PTR
#ENDIF
END TYPE

' // Size = 16 bytes
TYPE DSCBCAPS DWORD
   dwSize        AS DWORD
   dwFlags       AS DWORD
   dwBufferBytes AS DWORD
   dwReserved    AS DWORD
END TYPE

' // Size = 8 bytes
TYPE DSBPOSITIONNOTIFY DWORD
   dwOffset     AS DWORD
   hEventNotify AS DWORD
END TYPE

'//
'// DirectSound API
'//

'typedef BOOL (CALLBACK *LPDSENUMCALLBACKA)(LPGUID, LPCSTR, LPCSTR, LPVOID);
'typedef BOOL (CALLBACK *LPDSENUMCALLBACKW)(LPGUID, LPCWSTR, LPCWSTR, LPVOID);

' DSEnumCallback
' The DSEnumCallback function is an application-defined callback function that enumerates
' the DirectSound drivers. The system calls this function in response to the application's
' call to the DirectSoundEnumerate or DirectSoundCaptureEnumerate function.

'Syntax

'BOOL CALLBACK DSEnumCallback(
'  LPGUID  lpGuid,
'  LPCSTR  lpcstrDescription,
'  LPCSTR  lpcstrModule,
'  LPVOID  lpContext
');

'FUNCTION DSEnumCallBackA (BYREF lpGuid AS GUID, _
'                          BYREF lpcstrDescription AS ASCIIZ, _
'                          BYREF lpcstrModule AS ASCIIZ, _
'                          BYVAL lpContext AS DWORD) AS LONG

'FUNCTION DSEnumCallBackW (BYREF lpGuid AS GUID, _
'                          BYREF lpcstrDescription AS WSTRINGZ, _
'                          BYREF lpcstrModule AS WSTRINGZ, _
'                          BYVAL lpContext AS DWORD) AS LONG

'END FUNCTION

' ========================================================================================
' The DirectSoundCreate function creates and initializes an IDirectSound interface.
' ========================================================================================
DECLARE FUNCTION DirectSoundCreate IMPORT "dsound.dll" ALIAS "DirectSoundCreate" ( _
   BYREF lpcGuidDevice AS GUID _                        ' __in  LPCGUID lpcGuidDevice
 , BYREF ppDS AS IDirectSound _                         ' __out LPDIRECTSOUND * ppDS
 , OPTIONAL BYVAL pUnkOuter AS IUnknown _               ' __in LPUNKNOWN pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Enumerates the DirectSound drivers installed in the system.
' ========================================================================================
DECLARE FUNCTION DirectSoundEnumerate IMPORT "dsound.dll" ALIAS "DirectSoundEnumerateA" ( _
   BYVAL lpDSEnumCallback AS DWORD _                    ' __in PDSENUMCALLBACKA lpDSEnumCallback
 , BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Unicode version of DirectSoundEnumerateA.
' ========================================================================================
DECLARE FUNCTION DirectSoundEnumerateW IMPORT "dsound.dll" ALIAS "DirectSoundEnumerateW" ( _
   BYVAL lpDSEnumCallback AS DWORD _                    ' __in PDSENUMCALLBACKW lpDSEnumCallback
 , BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' creates and initializes an object that supports the IDirectSoundCapture interface.
' ========================================================================================
DECLARE FUNCTION DirectSoundCaptureCreate IMPORT "dsound.dll" ALIAS "DirectSoundCaptureCreate" ( _
   BYREF lpcGuidDevice AS GUID _                        ' __in LPCGUID lpcGuidDevice
 , BYREF ppDS AS IDirectSoundCapture _                  ' __in LPDIRECTSOUNDCAPTURE * ppDS
 , OPTIONAL BYVAL pUnkOuter AS IUnknown _               ' __in LPUNKNOWN pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Enumerates the DirectSoundCapture objects installed in the system.
' ========================================================================================
DECLARE FUNCTION DirectSoundCaptureEnumerate IMPORT "dsound.dll" ALIAS "DirectSoundCaptureEnumerateA" ( _
   BYVAL lpDSEnumCallback AS DWORD _                    ' __in PDSENUMCALLBACKA lpDSEnumCallback
 , BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Unicode version of DirectSoundCaptureEnumerateA
' ========================================================================================
DECLARE FUNCTION DirectSoundCaptureEnumerateW IMPORT "dsound.dll" ALIAS "DirectSoundCaptureEnumerateW" ( _
   BYVAL lpDSEnumCallback AS DWORD _                    ' __in PDSENUMCALLBACKW lpDSEnumCallback
 , BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
 ) AS LONG                                              ' HRESULT


#IF %DIRECTSOUND_VERSION >= &H0800

' ========================================================================================
' Creates and initializes an object that supports the IDirectSound8 interface.
' ========================================================================================
DECLARE FUNCTION DirectSoundCreate8 IMPORT "dsound.dll" ALIAS "DirectSoundCreate8" ( _
   BYREF lpcGuidDevice AS GUID _                        ' __in  LPCGUID  lpcGuidDevice
 , BYREF ppDS8 AS IDirectSound8 _                       ' __out LPDIRECTSOUND8 * ppDS8
 , OPTIONAL BYVAL pUnkOuter AS IUnknown _               ' __in  LPUNKNOWN  pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates and initializes an object that supports the IDirectSoundCapture8 interface.
' This function creates an object that supports capture effects. Although the older
' DirectSoundCaptureCreate function can also be used to obtain the IDirectSoundCapture8
' interface, the object created by that function cannot be used to create capture buffers
' that support the IDirectSoundCaptureBuffer8 interface.
' ========================================================================================
DECLARE FUNCTION DirectSoundCaptureCreate8 IMPORT "dsound.dll" ALIAS "DirectSoundCaptureCreate8" ( _
   BYREF lpcGUID AS GUID _                              ' __in  LPCGUID lpcGUID
 , BYREF lplpDSC AS IDirectSoundCapture8 _              ' __out LPDIRECTSOUNDCAPTURE8 *lplpDSC
 , OPTIONAL BYVAL pUnkOuter AS IUnknown _               ' __in  LPUNKNOWN pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Creates the DirectSound and DirectSoundCapture objects and returns the
' IDirectSoundFullDuplex8 interface. This function requires Microsoft Windows XP. Full
' duplex can be implemented on other operating systems, but the capture and rendering
' devices must be created separately.
' ========================================================================================
DECLARE FUNCTION DirectSoundFullDuplexCreate IMPORT "dsound.dll" ALIAS "DirectSoundFullDuplexCreate" ( _
   BYREF pcGuidCaptureDevice AS GUID _                  ' __in  LPCGUID  pcGuidCaptureDevice
 , BYREF pcGuidRenderDevice AS GUID _                   ' __in  LPCGUID  pcGuidRenderDevice
 , BYREF pcDSCBufferDesc AS DSCBUFFERDESC _             ' __in  LPCDSCBUFFERDESC  pcDSCBufferDesc
 , BYREF pcDSBufferDesc AS DSBUFFERDESC _               ' __in  LPCDSBUFFERDESC  pcDSBufferDesc
 , BYVAL hWnd AS DWORD _                                ' __in  HWND  hWnd
 , BYVAL dwLevel AS DWORD _                             ' __in  DWORD  dwLevel
 , BYREF ppDSFD AS IDirectSoundFullDuplex _             ' __out LPDIRECTSOUNDFULLDUPLEX*  ppDSFD
 , BYREF ppDSCBuffer8 AS IDirectSoundCaptureBuffer8 _   ' __out LPDIRECTSOUNDCAPTUREBUFFER8  *ppDSCBuffer8
 , BYREF ppDSBuffer8 AS IDirectSoundBuffer8 _           ' __out LPDIRECTSOUNDBUFFER8  *ppDSBuffer8
 , OPTIONAL BYVAL pUnkOuter AS IUnknown _               ' __in LPUNKNOWN  pUnkOuter
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Retrieves the unique device identifier of the default playback and capture devices
' selected by the user in Control Panel.
' ========================================================================================
DECLARE FUNCTION GetDeviceID IMPORT "dsound.dll" ALIAS "GetDeviceID" ( _
   BYREF pcGuidSrc AS GUID _                            ' __in LPCGUID pcGuidSrc
 , BYREF pGuidDest AS GUID _                            ' __out LPGUID  pGuidDest
 ) AS LONG                                              ' HRESULT

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800


' ########################################################################################
' IReferenceClock interface
' Inherited interface = IUnknown
' Note: Also defined in strminf.inc
' ########################################################################################

#IF NOT %DEF(%IReferenceClock_INTERFACE_DEFINED)
    %IReferenceClock_INTERFACE_DEFINED = 1

'typedef LONGLONG REFERENCE_TIME;

$IID_IReferenceClock = GUID$("{56a86897-0ad4-11ce-b03a-0020af0ba770}")

INTERFACE IReferenceClock $IID_IReferenceClock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 12
     BYREF pTime AS QUAD _                              ' __out REFERENCE_TIME *pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseTime ( _                                ' VTable offset = 16
     BYVAL rtBaseTime AS QUAD _                         ' __in REFERENCE_TIME rtBaseTime
   , BYVAL rtStreamTime AS QUAD _                       ' __in REFERENCE_TIME rtStreamTime
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out LPDWORD pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdvisePeriodic ( _                            ' VTable offset = 24
     BYVAL rtStartTime AS QUAD _                        ' __in REFERENCE_TIME rtStartTime
   , BYVAL rtPeriodTime AS QUAD _                       ' __in REFERENCE_TIME rtPeriodTime
   , BYVAL hSemaphore AS DWORD _                        ' __in HANDLE hSemaphore
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out LPDWORD pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 28
     BYVAL dwAdviseCookie AS DWORD _                    ' __in DWORD dwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' // __IReferenceClock_INTERFACE_DEFINED__


' ########################################################################################
' IDirectSound interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSound $IID_IDirectSound

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateSoundBuffer ( _                         ' VTable offset = 12
     BYREF pcDSBufferDesc AS DSBUFFERDESC _             ' __in LPCDSBUFFERDESC pcDSBufferDesc
   , BYREF ppDSBuffer AS IDirectSoundBuffer _           ' __out LPDIRECTSOUNDBUFFER *ppDSBuffer
   , OPTIONAL BYVAL pUnkOuter AS IUnknown _             ' __in LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 16
     BYREF pDSCaps AS DSCAPS _                          ' __out LPDSCAPS pDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSoundBuffer ( _                      ' VTable offset = 20
     BYVAL pDSBufferOriginal AS IDirectSoundBuffer _    ' __in LPDIRECTSOUNDBUFFER pDSBufferOriginal
   , BYREF ppDSBufferDuplicate AS IDirectSoundBuffer _  ' __out LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwLevel AS DWORD _                           ' __in dwLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpeakerConfig ( _                          ' VTable offset = 32
     BYREF pdwSpeakerConfig AS DWORD _                  ' __out LPDWORD pdwSpeakerConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpeakerConfig ( _                          ' VTable offset = 36
     BYVAL dwSpeakerConfig AS DWORD _                   ' __in DWORD dwSpeakerConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 40
     BYREF pcGuidDevice AS GUID _                       ' __in LPCGUID pcGuidDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


#IF %DIRECTSOUND_VERSION >= &H0800

' ########################################################################################
' IDirectSound8 interface
' Inherited interface = IDirectSound
' ########################################################################################

INTERFACE IDirectSound8 $IID_IDirectSound8

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectSound methods
   ' =====================================================================================
   METHOD CreateSoundBuffer ( _                         ' VTable offset = 12
     BYREF pcDSBufferDesc AS DSBUFFERDESC _             ' __in LPCDSBUFFERDESC pcDSBufferDesc
   , BYREF ppDSBuffer AS IDirectSoundBuffer _           ' __out LPDIRECTSOUNDBUFFER *ppDSBuffer
   , OPTIONAL BYVAL pUnkOuter AS IUnknown _             ' __in LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 16
     BYREF pDSCaps AS DSCAPS _                          ' __out LPDSCAPS pDSCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DuplicateSoundBuffer ( _                      ' VTable offset = 20
     BYVAL pDSBufferOriginal AS IDirectSoundBuffer _    ' __in LPDIRECTSOUNDBUFFER pDSBufferOriginal
   , BYREF ppDSBufferDuplicate AS IDirectSoundBuffer _  ' __out LPDIRECTSOUNDBUFFER *ppDSBufferDuplicate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwLevel AS DWORD _                           ' __in dwLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compact ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpeakerConfig ( _                          ' VTable offset = 32
     BYREF pdwSpeakerConfig AS DWORD _                  ' __out LPDWORD pdwSpeakerConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpeakerConfig ( _                          ' VTable offset = 36
     BYVAL dwSpeakerConfig AS DWORD _                   ' __in DWORD dwSpeakerConfig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 40
     BYREF pcGuidDevice AS GUID _                       ' __in LPCGUID pcGuidDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectSound8 methods
   ' =====================================================================================
   METHOD VerifyCertification ( _                       ' VTable offset = 44
     BYREF pdwCertified AS DWORD _                      ' LPDWORD pdwCertified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800


' ########################################################################################
' IDirectSoundBuffer interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundBuffer $IID_IDirectSoundBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYREF pDSBufferCaps AS DSBCAPS _                   ' __out LPDSBCAPS pDSBufferCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 16
     BYREF pdwCurrentPlayCursor AS DWORD _              ' __out LPDWORD pdwCurrentPlayCursor
   , BYREF pdwCurrentWriteCursor AS DWORD _             ' __out LPDWORD pdwCurrentWriteCursor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 20
     BYREF pwfxFormat AS WAVEFORMATEX _                 ' __out LPWAVEFORMATEX pwfxFormat
   , BYVAL dwSizeAllocated AS DWORD _                   ' __in DWORD dwSizeAllocated
   , BYREF pdwSizeWritten AS DWORD _                    ' __out LPDWORD pdwSizeWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolume ( _                                 ' VTable offset = 24
     BYREF plVolume AS LONG _                           ' __out LPLONG plVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPan ( _                                    ' VTable offset = 28
     BYREF plPan AS LONG _                              ' __out LPLONG plPan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 32
     BYREF pdwFrequency AS DWORD _                      ' __out LPDWORD pdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 36
     BYREF pdwStatus AS DWORD _                         ' __out LPDWORD pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 40
     BYVAL pDirectSound AS IDirectSound _               ' __in LPDIRECTSOUND pDirectSound
   , BYREF pcDSBufferDesc AS DSBUFFERDESC _             ' __in LPCDSBUFFERDESC pcDSBufferDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 44
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwBytes AS DWORD _                           ' __in DWORD dwBytes
   , BYREF ppvAudioPtr1 AS DWORD _                      ' __out LPVOID *ppvAudioPtr1
   , BYREF pdwAudioBytes1 AS DWORD _                    ' __out LPDWORD pdwAudioBytes1
   , BYREF ppvAudioPtr2 AS DWORD _                      ' __out LPVOID *ppvAudioPtr2
   , BYREF pdwAudioBytes2 AS DWORD _                    ' __out LPDWORD pdwAudioBytes2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Play ( _                                      ' VTable offset = 48
     BYVAL dwReserved1 AS DWORD _                       ' __in DWORD dwReserved1
   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPosition ( _                        ' VTable offset = 52
     BYVAL dwNewPosition AS DWORD _                     ' __in DWORD dwNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 56
     BYREF pcfxFormat AS WAVEFORMATEX _                 ' __in LPCWAVEFORMATEX pcfxFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVolume ( _                                 ' VTable offset = 60
     BYVAL lVolume AS LONG _                            ' __in LONG lVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPan ( _                                    ' VTable offset = 64
     BYVAL lPan AS LONG _                               ' __in LONG lPan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrequency ( _                              ' VTable offset = 68
     BYVAL dwFrequency AS DWORD _                       ' __in DWORD dwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 76
     BYVAL pvAudioPtr1 AS DWORD _                       ' __in LPVOID pvAudioPtr1
   , BYVAL dwAudioBytes1 AS DWORD _                     ' __in DWORD dwAudioBytes1
   , BYVAL pvAudioPtr2 AS DWORD _                       ' __in LPVOID pvAudioPtr2
   , BYVAL dwAudioBytes2 AS DWORD _                     ' __in DWORD dwAudioBytes2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


#IF %DIRECTSOUND_VERSION >= &H0800

' ########################################################################################
' IDirectSoundBuffer8 interface
' Inherited interface = IDirectSoundBuffer
' ########################################################################################

INTERFACE IDirectSoundBuffer8 $IID_IDirectSoundBuffer8

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectSoundBuffer methods
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYREF pDSBufferCaps AS DSBCAPS _                   ' __out LPDSBCAPS pDSBufferCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 16
     BYREF pdwCurrentPlayCursor AS DWORD _              ' __out LPDWORD pdwCurrentPlayCursor
   , BYREF pdwCurrentWriteCursor AS DWORD _             ' __out LPDWORD pdwCurrentWriteCursor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 20
     BYREF pwfxFormat AS WAVEFORMATEX _                 ' __out LPWAVEFORMATEX pwfxFormat
   , BYVAL dwSizeAllocated AS DWORD _                   ' __in DWORD dwSizeAllocated
   , BYREF pdwSizeWritten AS DWORD _                    ' __out LPDWORD pdwSizeWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolume ( _                                 ' VTable offset = 24
     BYREF plVolume AS LONG _                           ' __out LPLONG plVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPan ( _                                    ' VTable offset = 28
     BYREF plPan AS LONG _                              ' __out LPLONG plPan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 32
     BYREF pdwFrequency AS DWORD _                      ' __out LPDWORD pdwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 36
     BYREF pdwStatus AS DWORD _                         ' __out LPDWORD pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 40
     BYVAL pDirectSound AS IDirectSound _               ' __in LPDIRECTSOUND pDirectSound
   , BYREF pcDSBufferDesc AS DSBUFFERDESC _             ' __in LPCDSBUFFERDESC pcDSBufferDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 44
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwBytes AS DWORD _                           ' __in DWORD dwBytes
   , BYREF ppvAudioPtr1 AS DWORD _                      ' __out LPVOID *ppvAudioPtr1
   , BYREF pdwAudioBytes1 AS DWORD _                    ' __out LPDWORD pdwAudioBytes1
   , BYREF ppvAudioPtr2 AS DWORD _                      ' __out LPVOID *ppvAudioPtr2
   , BYREF pdwAudioBytes2 AS DWORD _                    ' __out LPDWORD pdwAudioBytes2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Play ( _                                      ' VTable offset = 48
     BYVAL dwReserved1 AS DWORD _                       ' __in DWORD dwReserved1
   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPosition ( _                        ' VTable offset = 52
     BYVAL dwNewPosition AS DWORD _                     ' __in DWORD dwNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 56
     BYREF pcfxFormat AS WAVEFORMATEX _                 ' __in LPCWAVEFORMATEX pcfxFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVolume ( _                                 ' VTable offset = 60
     BYVAL lVolume AS LONG _                            ' __in LONG lVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPan ( _                                    ' VTable offset = 64
     BYVAL lPan AS LONG _                               ' __in LONG lPan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFrequency ( _                              ' VTable offset = 68
     BYVAL dwFrequency AS DWORD _                       ' __in DWORD dwFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 76
     BYVAL pvAudioPtr1 AS DWORD _                       ' __in LPVOID pvAudioPtr1
   , BYVAL dwAudioBytes1 AS DWORD _                     ' __in DWORD dwAudioBytes1
   , BYVAL pvAudioPtr2 AS DWORD _                       ' __in LPVOID pvAudioPtr2
   , BYVAL dwAudioBytes2 AS DWORD _                     ' __in DWORD dwAudioBytes2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Restore ( _                                   ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectSoundBuffer8 methods
   ' =====================================================================================
   METHOD SetFX ( _                                     ' VTable offset = 84
     BYVAL dwEffectsCount AS DWORD _                    ' __in DWORD dwEffectsCount
   , BYREF pDSFXDesc AS DSEFFECTDESC _                  ' __in LPDSEFFECTDESC pDSFXDesc
   , BYREF pdwResultCodes AS DWORD _                    ' __out LPDWORD pdwResultCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AcquireResources ( _                          ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwEffectsCount AS DWORD _                    ' __in DWORD dwEffectsCount
   , BYREF pdwResultCodes AS DWORD _                    ' __out LPDWORD pdwResultCodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInPath ( _                           ' VTable offset = 92
     BYREF rguidObject AS GUID _                        ' __in REFGUID rguidObject
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF rguidInterface AS GUID _                     ' __in REFGUID rguidInterface
   , BYREF ppObject AS IUnknown _                       ' __out LPVOID *ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800

'// Special GUID meaning "select all objects" for use in GetObjectInPath()
$GUID_All_Objects = GUID$("{aa114de5-c262-4169-a1c8-23d698cc73b5}")

' ########################################################################################
' IDirectSound3DListener interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSound3DListener $IID_IDirectSound3DListener

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 12
     BYREF pListener AS DS3DLISTENER _                  ' __out LPDS3DLISTENER pListener
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDistanceFactor ( _                         ' VTable offset = 20
     BYREF pflDistanceFactor AS SINGLE _                ' __out D3DVALUE* pflDistanceFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDopplerFactor ( _                          ' VTable offset = 24
     BYREF pflDopplerFactor AS SINGLE _                 ' __out D3DVALUE* pflDopplerFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOrientation ( _                            ' VTable offset = 28
     BYREF pvOrientFront AS D3DVECTOR _                 ' __out D3DVECTOR* pvOrientFront
   , BYREF pvOrientTop AS D3DVECTOR _                   ' __out D3DVECTOR* pvOrientTop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 32
     BYREF pvPosition AS D3DVECTOR _                    ' __out D3DVECTOR* pvPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRolloffFactor ( _                          ' VTable offset = 36
     BYREF pflRolloffFactor AS SINGLE _                 ' __out D3DVALUE* pflRolloffFactor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVelocity ( _                               ' VTable offset = 40
     BYREF pvVelocity AS D3DVECTOR _                    ' __out D3DVECTOR* pvVelocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 44
     BYREF pcListener AS DS3DLISTENER _                 ' __in LPCDS3DLISTENER pcListener
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDistanceFactor ( _                         ' VTable offset = 48
     BYVAL flDistanceFactor AS SINGLE _                 ' __in D3DVALUE flDistanceFactor
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDopplerFactor ( _                          ' VTable offset = 52
     BYVAL flDopplerFactor AS SINGLE _                  ' __in D3DVALUE flDopplerFactor
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOrientation ( _                            ' VTable offset = 56
     BYVAL xFront AS SINGLE _                           ' __in D3DVALUE xFront
   , BYVAL yFront AS SINGLE _                           ' __in D3DVALUE yFront
   , BYVAL zFront AS SINGLE _                           ' __in D3DVALUE zFront
   , BYVAL xTop AS SINGLE _                             ' __in D3DVALUE xTop
   , BYVAL yTop AS SINGLE _                             ' __in D3DVALUE yTop
   , BYVAL zTop AS SINGLE _                             ' __in D3DVALUE zTop
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 60
     BYVAL x AS SINGLE _                                ' __in D3DVALUE x
   , BYVAL y AS SINGLE _                                ' __in D3DVALUE y
   , BYVAL z AS SINGLE _                                ' __in D3DVALUE z
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRolloffFactor ( _                          ' VTable offset = 64
     BYVAL flRolloffFactor AS SINGLE _                  ' __in D3DVALUE flRolloffFactor
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 68
     BYVAL x AS SINGLE _                                ' __in D3DVALUE x
   , BYVAL y AS SINGLE _                                ' __in D3DVALUE y
   , BYVAL z AS SINGLE _                                ' __in D3DVALUE z
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitDeferredSettings ( _                    ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSound3DBuffer interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSound3DBuffer $IID_IDirectSound3DBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 12
     BYREF pDs3dBuffer AS DS3DBUFFER _                  ' __out LPDS3DBUFFER pDs3dBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConeAngles ( _                             ' VTable offset = 16
     BYREF pdwInsideConeAngle AS DWORD _                ' __out LPDWORD pdwInsideConeAngle
   , BYREF pdwOutsideConeAngle AS DWORD _               ' __out LPDWORD pdwOutsideConeAngle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConeOrientation ( _                        ' VTable offset = 20
     BYREF pvOrientation AS D3DVECTOR _                 ' __out D3DVECTOR* pvOrientation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConeOutsideVolume ( _                      ' VTable offset = 24
     BYREF plConeOutsideVolume AS LONG _                ' __out LPLONG plConeOutsideVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxDistance ( _                            ' VTable offset = 28
     BYREF pflMaxDistance AS SINGLE   _                 ' __out D3DVALUE* pflMaxDistance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinDistance ( _                            ' VTable offset = 32
     BYREF pflMinDistance AS SINGLE _                   ' __out D3DVALUE* pflMinDistance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 36
     BYREF pdwMode AS DWORD _                           ' __out LPDWORD pdwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 40
     BYREF pvPosition AS D3DVECTOR _                    ' __out D3DVECTOR* pvPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVelocity ( _                               ' VTable offset = 44
     BYREF pvVelocity AS D3DVECTOR _                    ' __out D3DVECTOR* pvVelocity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 48
     BYREF pvVelocity AS DS3DBUFFER _                   ' __in D3DVECTOR* pvVelocity
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConeAngles ( _                             ' VTable offset = 52
     BYVAL dwInsideConeAngle AS DWORD _                 ' __in DWORD dwInsideConeAngle
   , BYVAL dwOutsideConeAngle AS DWORD _                ' __in DWORD dwOutsideConeAngle
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConeOrientation ( _                        ' VTable offset = 56
     BYVAL x AS SINGLE _                                ' __in D3DVALUE x
   , BYVAL y AS SINGLE _                                ' __in D3DVALUE y
   , BYVAL z AS SINGLE _                                ' __in D3DVALUE z
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetConeOutsideVolume ( _                      ' VTable offset = 60
     BYVAL lConeOutsideVolume AS LONG _                 ' __in LONG lConeOutsideVolume
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxDistance ( _                            ' VTable offset = 64
     BYVAL flMaxDistance AS SINGLE _                    ' __in D3DVALUE flMaxDistance
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMinDistance ( _                            ' VTable offset = 68
     BYVAL flMinDistance AS SINGLE _                    ' __in D3DVALUE flMinDistance
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 72
     BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 76
     BYVAL x AS SINGLE _                                ' __in D3DVALUE x
   , BYVAL y AS SINGLE _                                ' __in D3DVALUE y
   , BYVAL z AS SINGLE _                                ' __in D3DVALUE z
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVelocity ( _                               ' VTable offset = 80
     BYVAL x AS SINGLE _                                ' __in D3DVALUE x
   , BYVAL y AS SINGLE _                                ' __in D3DVALUE y
   , BYVAL z AS SINGLE _                                ' __in D3DVALUE z
   , BYVAL dwApply AS DWORD _                           ' __in DWORD dwApply
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundCapture interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundCapture $IID_IDirectSoundCapture

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateCaptureBuffer ( _                       ' VTable offset = 12
     BYREF pcDSCBufferDesc AS DSCBUFFERDESC _           ' __in LPCDSCBUFFERDESC pcDSCBufferDesc
   , BYREF ppDSCBuffer AS IDirectSoundCaptureBuffer _   ' __in LPDIRECTSOUNDCAPTUREBUFFER *ppDSCBuffer
   , OPTIONAL BYVAL pUnkOuter AS IUnknown _             ' __in LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 16
     BYREF pDSCCaps AS DSCCAPS _                        ' __out LPDSCCAPS pDSCCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYREF pcGuidDevice AS GUID _                       ' __in LPCGUID pcGuidDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectSoundCapture8 interface
' Inherited interface = IUnknown
' IDirectSoundCapture8 is a define for IDirectSoundCapture. The two interface names are
' interchangeable. However, objects supporting this interface can have different
' functionality, depending on their class.
' ########################################################################################

INTERFACE IDirectSoundCapture8 $IID_IDirectSoundCapture8

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateCaptureBuffer ( _                       ' VTable offset = 12
     BYREF pcDSCBufferDesc AS DSCBUFFERDESC _           ' __in LPCDSCBUFFERDESC pcDSCBufferDesc
   , BYREF ppDSCBuffer AS IDirectSoundCaptureBuffer _   ' __in LPDIRECTSOUNDCAPTUREBUFFER *ppDSCBuffer
   , OPTIONAL BYVAL pUnkOuter AS IUnknown _             ' __in LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 16
     BYREF pDSCCaps AS DSCCAPS _                        ' __out LPDSCCAPS pDSCCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYREF pcGuidDevice AS GUID _                       ' __in LPCGUID pcGuidDevice
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectSoundCaptureBuffer interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundCaptureBuffer $IID_IDirectSoundCaptureBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYREF pDSCCaps AS DSCCAPS _                        ' __out LPDSCCAPS pDSCCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 16
     BYREF pdwCapturePosition AS DWORD _                ' __out LPDWORD pdwCapturePosition
   , BYREF pdwReadPosition AS DWORD _                   ' __out LPDWORD pdwReadPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 20
     BYREF pwfxFormat AS WAVEFORMATEX _                 ' __out LPWAVEFORMATEX pwfxFormat
   , BYVAL dwSizeAllocated AS DWORD _                   ' __in DWORD dwSizeAllocated
   , BYREF pdwSizeWritten AS DWORD _                    ' __out LPDWORD pdwSizeWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdwStatus AS DWORD _                         ' __out LPDWORD pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL pDirectSoundCapture AS IDirectSoundCapture _ ' __in LPDIRECTSOUNDCAPTURE pDirectSoundCapture
   , BYREF pcDSCBufferDesc AS DSCBUFFERDESC _           ' __in LPCDSCBUFFERDESC pcDSCBufferDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 32
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwBytes AS DWORD _                           ' __in DWORD dwBytes
   , BYREF ppvAudioPtr1 AS DWORD _                      ' __out LPVOID *ppvAudioPtr1
   , BYREF pdwAudioBytes1 AS DWORD _                    ' __out LPDWORD pdwAudioBytes1
   , BYREF ppvAudioPtr2 AS DWORD _                      ' __out LPVOID *ppvAudioPtr2
   , BYREF pdwAudioBytes2 AS DWORD _                    ' __out LPDWORD pdwAudioBytes2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 44
     BYVAL pvAudioPtr1 AS DWORD _                       ' __in LPVOID pvAudioPtr1
   , BYVAL dwAudioBytes1 AS DWORD _                     ' __in DWORD dwAudioBytes1
   , BYVAL pvAudioPtr2 AS DWORD _                       ' __in LPVOID pvAudioPtr2
   , BYVAL dwAudioBytes2 AS DWORD _                     ' __in DWORD dwAudioBytes2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


#IF %DIRECTSOUND_VERSION >= &H0800

' ########################################################################################
' IDirectSoundCaptureBuffer8 interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundCaptureBuffer8 $IID_IDirectSoundCaptureBuffer8

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectSoundCaptureBuffer methods
   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYREF pDSCCaps AS DSCCAPS _                        ' __out LPDSCCAPS pDSCCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 16
     BYREF pdwCapturePosition AS DWORD _                ' __out LPDWORD pdwCapturePosition
   , BYREF pdwReadPosition AS DWORD _                   ' __out LPDWORD pdwReadPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 20
     BYREF pwfxFormat AS WAVEFORMATEX _                 ' __out LPWAVEFORMATEX pwfxFormat
   , BYVAL dwSizeAllocated AS DWORD _                   ' __in DWORD dwSizeAllocated
   , BYREF pdwSizeWritten AS DWORD _                    ' __out LPDWORD pdwSizeWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 24
     BYREF pdwStatus AS DWORD _                         ' __out LPDWORD pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL pDirectSoundCapture AS IDirectSoundCapture _ ' __in LPDIRECTSOUNDCAPTURE pDirectSoundCapture
   , BYREF pcDSCBufferDesc AS DSCBUFFERDESC _           ' __in LPCDSCBUFFERDESC pcDSCBufferDesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 32
     BYVAL dwOffset AS DWORD _                          ' __in DWORD dwOffset
   , BYVAL dwBytes AS DWORD _                           ' __in DWORD dwBytes
   , BYREF ppvAudioPtr1 AS DWORD _                      ' __out LPVOID *ppvAudioPtr1
   , BYREF pdwAudioBytes1 AS DWORD _                    ' __out LPDWORD pdwAudioBytes1
   , BYREF ppvAudioPtr2 AS DWORD _                      ' __out LPVOID *ppvAudioPtr2
   , BYREF pdwAudioBytes2 AS DWORD _                    ' __out LPDWORD pdwAudioBytes2
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 44
     BYVAL pvAudioPtr1 AS DWORD _                       ' __in LPVOID pvAudioPtr1
   , BYVAL dwAudioBytes1 AS DWORD _                     ' __in DWORD dwAudioBytes1
   , BYVAL pvAudioPtr2 AS DWORD _                       ' __in LPVOID pvAudioPtr2
   , BYVAL dwAudioBytes2 AS DWORD _                     ' __in DWORD dwAudioBytes2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectSoundCaptureBuffer8 methods
   ' =====================================================================================
   METHOD GetObjectInPath ( _                           ' VTable offset = 48
     BYREF rguidObject AS GUID _                        ' __in REFGUID rguidObject
   , BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF rguidInterface AS GUID _                     ' __in REFGUID rguidInterface
   , BYREF ppObject AS IUnknown _                       ' __out LPVOID *ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFXStatus ( _                               ' VTable offset = 52
     BYVAL dwFXCount AS DWORD _                         ' __in DWORD dwFXCount
   , BYREF pdwFXStatus AS DWORD _                       ' __out LPDWORD pdwFXStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800


' ########################################################################################
' IDirectSoundNotify interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundNotify $IID_IDirectSoundNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNotificationPositions ( _                  ' VTable offset = 12
     BYVAL dwPositionNotifies AS DWORD _                ' __in DWORD dwPositionNotifies
   , BYREF pcPositionNotifies AS DSBPOSITIONNOTIFY _    ' __in LPCDSBPOSITIONNOTIFY pcPositionNotifies
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IKsPropertySet interface
' Inherited interface = IUnknown
' Note: Also defined in strminf.inc
' Note: dsound.h wrongly declares the first method as Get and the second as Set.
' ########################################################################################

#IF NOT %DEF(%IKsPropertySet)
   %IKsPropertySet = 1

%KSPROPERTY_SUPPORT_GET = &H00000001???
%KSPROPERTY_SUPPORT_SET = &H00000002???

#IF NOT %DEF(%IKsPropertySet_INTERFACE_DEFINED)
    %IKsPropertySet_INTERFACE_DEFINED = 1

$IID_IKsPropertySet = GUID$("{31efac30-515c-11d0-a9aa-00aa0061be93}")

INTERFACE IKsPropertySet $IID_IKsPropertySet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 12
     BYREF guidPropSet AS GUID _                        ' __in REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in DWORD dwPropID
   , BYVAL pInstanceData AS DWORD _                     ' __in LPVOID pInstanceData
   , BYVAL cbInstanceData AS DWORD _                    ' __in DWORD cbInstanceData
   , BYVAL pPropData AS DWORD _                         ' __in LPVOID pPropData
   , BYVAL cbPropData AS DWORD _                        ' __in DWORD cbPropData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF guidPropSet AS GUID _                        ' __in REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in DWORD dwPropID
   , BYVAL pInstanceData AS DWORD _                     ' __in LPVOID pInstanceData
   , BYVAL cbInstanceData AS DWORD _                    ' __in DWORD cbInstanceData
   , BYREF pPropData AS DWORD _                         ' __out LPVOID pPropData
   , BYVAL cbPropData AS DWORD _                        ' __in DWORD cbPropData
   , BYREF pcbReturned AS DWORD _                       ' __out DWORD *pcbReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySupported ( _                            ' VTable offset = 20
     BYREF guidPropSet AS GUID _                        ' __in REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in DWORD dwPropID
   , BYREF pTypeSupport AS DWORD _                      ' __out DWORD *pTypeSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsPropertySet_INTERFACE_DEFINED)__*/

#ENDIF   ' // _IKsPropertySet_


#IF %DIRECTSOUND_VERSION >= &H0800

' ########################################################################################
' IDirectSoundFXGargle interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 8 bytes
TYPE DSFXGargle DWORD
   dwRateHz    AS DWORD          '  // Rate of modulation in hz
   dwWaveShape AS DWORD          '  // DSFXGARGLE_WAVE_xxx
END TYPE

%DSFXGARGLE_WAVE_TRIANGLE = 0
%DSFXGARGLE_WAVE_SQUARE   = 1

%DSFXGARGLE_RATEHZ_MIN = 1
%DSFXGARGLE_RATEHZ_MAX = 1000

INTERFACE IDirectSoundFXGargle $IID_IDirectSoundFXGargle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxGargle AS DSFXGargle _                 ' __in LPCDSFXGargle pcDsFxGargle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxGargle AS DSFXGargle _                 ' __out LPDSFXGargle pcDsFxGargle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXChorus interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 28 bytes
TYPE DSFXChorus DWORD
   fWetDryMix AS SINGLE
   fDepth     AS SINGLE
   fFeedback  AS SINGLE
   fFrequency AS SINGLE
   lWaveform  AS LONG         ' // LFO shape; DSFXCHORUS_WAVE_xxx
   fDelay     AS SINGLE
   lPhase     AS LONG
END TYPE

%DSFXCHORUS_WAVE_TRIANGLE       = 0
%DSFXCHORUS_WAVE_SIN            = 1

MACRO DSFXCHORUS_WETDRYMIX_MIN  = 0.0!
MACRO DSFXCHORUS_WETDRYMIX_MAX  = 100.0!
MACRO DSFXCHORUS_DEPTH_MIN      = 0.0!
MACRO DSFXCHORUS_DEPTH_MAX      = 100.0!
MACRO DSFXCHORUS_FEEDBACK_MIN   = -99.0!
MACRO DSFXCHORUS_FEEDBACK_MAX   = 99.0!
MACRO DSFXCHORUS_FREQUENCY_MIN  = 0.0!
MACRO DSFXCHORUS_FREQUENCY_MAX  = 10.0!
MACRO DSFXCHORUS_DELAY_MIN      = 0.0!
MACRO DSFXCHORUS_DELAY_MAX      = 20.0!
%DSFXCHORUS_PHASE_MIN           = 0
%DSFXCHORUS_PHASE_MAX           = 4

%DSFXCHORUS_PHASE_NEG_180       = 0
%DSFXCHORUS_PHASE_NEG_90        = 1
%DSFXCHORUS_PHASE_ZERO          = 2
%DSFXCHORUS_PHASE_90            = 3
%DSFXCHORUS_PHASE_180           = 4


INTERFACE IDirectSoundFXChorus $IID_IDirectSoundFXChorus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxChorus AS DSFXChorus _                 ' __in LPCDSFXChorus pcDsFxChorus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxChorus AS DSFXChorus _                 ' __out LPDSFXChorus pcDsFxChorus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXFlanger interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 28 bytes
TYPE DSFXFlanger DWORD
   fWetDryMix AS SINGLE
   fDepth     AS SINGLE
   fFeedback  AS SINGLE
   fFrequency AS SINGLE
   lWaveform  AS LONG
   fDelay     AS SINGLE
   lPhase     AS LONG
END TYPE

%DSFXFLANGER_WAVE_TRIANGLE      = 0
%DSFXFLANGER_WAVE_SIN           = 1

MACRO DSFXFLANGER_WETDRYMIX_MIN = 0.0!
MACRO DSFXFLANGER_WETDRYMIX_MAX = 100.0!
MACRO DSFXFLANGER_FREQUENCY_MIN = 0.0!
MACRO DSFXFLANGER_FREQUENCY_MAX = 10.0!
MACRO DSFXFLANGER_DEPTH_MIN     = 0.0!
MACRO DSFXFLANGER_DEPTH_MAX     = 100.0!
%DSFXFLANGER_PHASE_MIN          = 0
%DSFXFLANGER_PHASE_MAX          = 4
MACRO DSFXFLANGER_FEEDBACK_MIN  = -99.0!
MACRO DSFXFLANGER_FEEDBACK_MAX  = 99.0!
MACRO DSFXFLANGER_DELAY_MIN     = 0.0!
MACRO DSFXFLANGER_DELAY_MAX     = 4.0!

%DSFXFLANGER_PHASE_NEG_180      = 0
%DSFXFLANGER_PHASE_NEG_90       = 1
%DSFXFLANGER_PHASE_ZERO         = 2
%DSFXFLANGER_PHASE_90           = 3
%DSFXFLANGER_PHASE_180          = 4

INTERFACE IDirectSoundFXFlanger $IID_IDirectSoundFXFlanger

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxFlanger AS DSFXFlanger _               ' __in LPCDSFXFlanger pcDsFxFlanger
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxFlanger AS DSFXFlanger _               ' __out LPDSFXFlanger pcDsFxFlanger
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXEcho interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 20 bytes
TYPE DSFXEcho DWORD
   fWetDryMix  AS SINGLE
   fFeedback   AS SINGLE
   fLeftDelay  AS SINGLE
   fRightDelay AS SINGLE
   lPanDelay   AS LONG
END TYPE

MACRO DSFXECHO_WETDRYMIX_MIN  = 0.0!
MACRO DSFXECHO_WETDRYMIX_MAX  = 100.0!
MACRO DSFXECHO_FEEDBACK_MIN   = 0.0!
MACRO DSFXECHO_FEEDBACK_MAX   = 100.0!
MACRO DSFXECHO_LEFTDELAY_MIN  = 1.0!
MACRO DSFXECHO_LEFTDELAY_MAX  = 2000.0!
MACRO DSFXECHO_RIGHTDELAY_MIN = 1.0!
MACRO DSFXECHO_RIGHTDELAY_MAX = 2000.0!
%DSFXECHO_PANDELAY_MIN        = 0
%DSFXECHO_PANDELAY_MAX        = 1

INTERFACE IDirectSoundFXEcho $IID_IDirectSoundFXEcho

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxEcho AS DSFXEcho _                     ' __in LPCDSFXEcho pcDsFxEcho
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxEcho AS DSFXEcho _                     ' __out LPDSFXEcho pcDsFxEcho
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXDistortion interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 20 bytes
TYPE DSFXDistortion DWORD
   fGain                  AS SINGLE
   fEdge                  AS SINGLE
   fPostEQCenterFrequency AS SINGLE
   fPostEQBandwidth       AS SINGLE
   fPreLowpassCutoff      AS SINGLE
END TYPE

MACRO DSFXDISTORTION_GAIN_MIN                  = -60.0!
MACRO DSFXDISTORTION_GAIN_MAX                  = 0.0!
MACRO DSFXDISTORTION_EDGE_MIN                  = 0.0!
MACRO DSFXDISTORTION_EDGE_MAX                  = 100.0!
MACRO DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN = 100.0!
MACRO DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX = 8000.0!
MACRO DSFXDISTORTION_POSTEQBANDWIDTH_MIN       = 100.0!
MACRO DSFXDISTORTION_POSTEQBANDWIDTH_MAX       = 8000.0!
MACRO DSFXDISTORTION_PRELOWPASSCUTOFF_MIN      = 100.0!
MACRO DSFXDISTORTION_PRELOWPASSCUTOFF_MAX      = 8000.0!

INTERFACE IDirectSoundFXDistortion $IID_IDirectSoundFXDistortion

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxDistortion AS DSFXDistortion _         ' __in LPCDSFXDistortion pcDsFxDistortion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxDistortion AS DSFXDistortion _         ' __out LPDSFXDistortion pcDsFxDistortion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXCompressor interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 24 bytes
TYPE DSFXCompressor DWORD
   fGain      AS SINGLE
   fAttack    AS SINGLE
   fRelease   AS SINGLE
   fThreshold AS SINGLE
   fRatio     AS SINGLE
   fPredelay  AS SINGLE
END TYPE

MACRO DSFXCOMPRESSOR_GAIN_MIN           =  -60.0!
MACRO DSFXCOMPRESSOR_GAIN_MAX           =  60.0!
MACRO DSFXCOMPRESSOR_ATTACK_MIN         =  0.01!
MACRO DSFXCOMPRESSOR_ATTACK_MAX         =  500.0!
MACRO DSFXCOMPRESSOR_RELEASE_MIN        =  50.0!
MACRO DSFXCOMPRESSOR_RELEASE_MAX        =  3000.0!
MACRO DSFXCOMPRESSOR_THRESHOLD_MIN      =  -60.0!
MACRO DSFXCOMPRESSOR_THRESHOLD_MAX      =  0.0!
MACRO DSFXCOMPRESSOR_RATIO_MIN          =  1.0!
MACRO DSFXCOMPRESSOR_RATIO_MAX          =  100.0!
MACRO DSFXCOMPRESSOR_PREDELAY_MIN       =  0.0!
MACRO DSFXCOMPRESSOR_PREDELAY_MAX       =  4.0!

INTERFACE IDirectSoundFXCompressor $IID_IDirectSoundFXCompressor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxCompressor AS DSFXCompressor _         ' __in LPCDSFXCompressor pcDsFxCompressor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxCompressor AS DSFXCompressor _         ' __out LPDSFXCompressor pcDsFxCompressor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXParamEq interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 12 bytes
TYPE DSFXParamEq DWORD
   fCenter    AS SINGLE
   fBandwidth AS SINGLE
   fGain      AS SINGLE
END TYPE

MACRO DSFXPARAMEQ_CENTER_MIN     = 80.0!
MACRO DSFXPARAMEQ_CENTER_MAX     = 16000.0!
MACRO DSFXPARAMEQ_BANDWIDTH_MIN  = 1.0!
MACRO DSFXPARAMEQ_BANDWIDTH_MAX  = 36.0!
MACRO DSFXPARAMEQ_GAIN_MIN       = -15.0!
MACRO DSFXPARAMEQ_GAIN_MAX       = 15.0!

INTERFACE IDirectSoundFXParamEq $IID_IDirectSoundFXParamEq

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxParamEq AS DSFXParamEq _               ' __in LPCDSFXParamEq pcDsFxParamEq
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxParamEq AS DSFXParamEq _               ' __out LPDSFXParamEq pcDsFxParamEq
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXI3DL2Reverb interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 48 bytes
TYPE DSFXI3DL2Reverb DWORD
   lRoom               AS LONG     ' // [-10000, 0]      default: -1000 mB
   lRoomHF             AS LONG     ' // [-10000, 0]      default: 0 mB
   flRoomRolloffFactor AS SINGLE   ' // [0.0, 10.0]      default: 0.0
   flDecayTime         AS SINGLE   ' // [0.1, 20.0]      default: 1.49s
   flDecayHFRatio      AS SINGLE   ' // [0.1, 2.0]       default: 0.83
   lReflections        AS LONG     ' // [-10000, 1000]   default: -2602 mB
   flReflectionsDelay  AS SINGLE   ' // [0.0, 0.3]       default: 0.007 s
   lReverb             AS LONG     ' // [-10000, 2000]   default: 200 mB
   flReverbDelay       AS SINGLE   ' // [0.0, 0.1]       default: 0.011 s
   flDiffusion         AS SINGLE   ' // [0.0, 100.0]     default: 100.0 %
   flDensity           AS SINGLE   ' // [0.0, 100.0]     default: 100.0 %
   flHFReference       AS SINGLE   ' // [20.0, 20000.0]  default: 5000.0 Hz
END TYPE

%DSFX_I3DL2REVERB_ROOM_MIN                       = -10000
%DSFX_I3DL2REVERB_ROOM_MAX                       = 0
%DSFX_I3DL2REVERB_ROOM_DEFAULT                   = -1000

%DSFX_I3DL2REVERB_ROOMHF_MIN                     = -10000
%DSFX_I3DL2REVERB_ROOMHF_MAX                     = 0
%DSFX_I3DL2REVERB_ROOMHF_DEFAULT                 = -100

MACRO DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MIN     = 0.0!
MACRO DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MAX     = 10.0!
MACRO DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_DEFAULT = 0.0!

MACRO DSFX_I3DL2REVERB_DECAYTIME_MIN             = 0.1!
MACRO DSFX_I3DL2REVERB_DECAYTIME_MAX             = 20.0!
MACRO DSFX_I3DL2REVERB_DECAYTIME_DEFAULT         = 1.49!

MACRO DSFX_I3DL2REVERB_DECAYHFRATIO_MIN          = 0.1!
MACRO DSFX_I3DL2REVERB_DECAYHFRATIO_MAX          = 2.0!
MACRO DSFX_I3DL2REVERB_DECAYHFRATIO_DEFAULT      = 0.83!

%DSFX_I3DL2REVERB_REFLECTIONS_MIN                = -10000
%DSFX_I3DL2REVERB_REFLECTIONS_MAX                = 1000
%DSFX_I3DL2REVERB_REFLECTIONS_DEFAULT            = -2602

MACRO DSFX_I3DL2REVERB_REFLECTIONSDELAY_MIN      = 0.0!
MACRO DSFX_I3DL2REVERB_REFLECTIONSDELAY_MAX      = 0.3!
MACRO DSFX_I3DL2REVERB_REFLECTIONSDELAY_DEFAULT  = 0.007!

%DSFX_I3DL2REVERB_REVERB_MIN                     = -10000
%DSFX_I3DL2REVERB_REVERB_MAX                     = 2000
%DSFX_I3DL2REVERB_REVERB_DEFAULT                 = 200

MACRO DSFX_I3DL2REVERB_REVERBDELAY_MIN           = 0.0!
MACRO DSFX_I3DL2REVERB_REVERBDELAY_MAX           = 0.1!
MACRO DSFX_I3DL2REVERB_REVERBDELAY_DEFAULT       = 0.011!

MACRO DSFX_I3DL2REVERB_DIFFUSION_MIN             = 0.0!
MACRO DSFX_I3DL2REVERB_DIFFUSION_MAX             = 100.0!
MACRO DSFX_I3DL2REVERB_DIFFUSION_DEFAULT         = 100.0!

MACRO DSFX_I3DL2REVERB_DENSITY_MIN               = 0.0!
MACRO DSFX_I3DL2REVERB_DENSITY_MAX               = 100.0!
MACRO DSFX_I3DL2REVERB_DENSITY_DEFAULT           = 100.0!

MACRO DSFX_I3DL2REVERB_HFREFERENCE_MIN           = 20.0!
MACRO DSFX_I3DL2REVERB_HFREFERENCE_MAX           = 20000.0!
MACRO DSFX_I3DL2REVERB_HFREFERENCE_DEFAULT       = 5000.0!

%DSFX_I3DL2REVERB_QUALITY_MIN                    = 0
%DSFX_I3DL2REVERB_QUALITY_MAX                    = 3
%DSFX_I3DL2REVERB_QUALITY_DEFAULT                = 2

INTERFACE IDirectSoundFXI3DL2Reverb $IID_IDirectSoundFXI3DL2Reverb

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxI3DL2Reverb AS DSFXI3DL2Reverb _       ' __in LPCDSFXI3DL2Reverb pcDsFxI3DL2Reverb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxI3DL2Reverb AS DSFXI3DL2Reverb _       ' __out LPDSFXI3DL2Reverb pcDsFxI3DL2Reverb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreset ( _                                 ' VTable offset = 20
     BYVAL dwPreset AS DWORD _                          ' __in DWORD dwPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreset ( _                                 ' VTable offset = 24
     BYREF pdwPreset AS DWORD _                         ' __out LPDWORD pdwPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQuality ( _                                ' VTable offset = 28
     BYVAL lQuality AS LONG _                           ' __in LONG lQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQuality ( _                                ' VTable offset = 32
     BYREF plQuality AS LONG _                          ' __out LONG *plQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFXWavesReverb interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 16 bytes
TYPE DSFXWavesReverb DWORD
   fInGain          AS SINGLE   ' // [-96.0,0.0]            default: 0.0 dB
   fReverbMix       AS SINGLE   ' // [-96.0,0.0]            default: 0.0 db
   fReverbTime      AS SINGLE   ' // [0.001,3000.0]         default: 1000.0 ms
   fHighFreqRTRatio AS SINGLE   ' // [0.001,0.999]          default: 0.001
END TYPE

MACRO DSFX_WAVESREVERB_INGAIN_MIN                = -96.0!
MACRO DSFX_WAVESREVERB_INGAIN_MAX                = 0.0!
MACRO DSFX_WAVESREVERB_INGAIN_DEFAULT            = 0.0!
MACRO DSFX_WAVESREVERB_REVERBMIX_MIN             = -96.0!
MACRO DSFX_WAVESREVERB_REVERBMIX_MAX             = 0.0!
MACRO DSFX_WAVESREVERB_REVERBMIX_DEFAULT         = 0.0!
MACRO DSFX_WAVESREVERB_REVERBTIME_MIN            = 0.001!
MACRO DSFX_WAVESREVERB_REVERBTIME_MAX            = 3000.0!
MACRO DSFX_WAVESREVERB_REVERBTIME_DEFAULT        = 1000.0!
MACRO DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN       = 0.001!
MACRO DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX       = 0.999!
MACRO DSFX_WAVESREVERB_HIGHFREQRTRATIO_DEFAULT   = 0.001!


INTERFACE IDirectSoundFXWavesReverb $IID_IDirectSoundFXWavesReverb

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDsFxWavesReverb AS DSFXWavesReverb _       ' __in LPCDSFXWavesReverb pcDsFxWavesReverb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDsFxWavesReverb AS DSFXWavesReverb _       ' __out LPDSFXWavesReverb pcDsFxWavesReverb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundCaptureFXAec interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 12 bytes
TYPE DSCFXAec DWORD
   fEnable AS LONG
   fNoiseFill AS LONG
   dwMode AS DWORD
END TYPE

'// These match the AEC_MODE_* constants in the DDK's ksmedia.h file
%DSCFX_AEC_MODE_PASS_THROUGH                     = &H0
%DSCFX_AEC_MODE_HALF_DUPLEX                      = &H1
%DSCFX_AEC_MODE_FULL_DUPLEX                      = &H2

'// These match the AEC_STATUS_* constants in ksmedia.h
%DSCFX_AEC_STATUS_HISTORY_UNINITIALIZED          = &H0
%DSCFX_AEC_STATUS_HISTORY_CONTINUOUSLY_CONVERGED = &H1
%DSCFX_AEC_STATUS_HISTORY_PREVIOUSLY_DIVERGED    = &H2
%DSCFX_AEC_STATUS_CURRENTLY_CONVERGED            = &H8

INTERFACE IDirectSoundCaptureFXAec $IID_IDirectSoundCaptureFXAec

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pDscFxAec AS DSCFXAec _                      ' __in LPCDSCFXAec pDscFxAec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pDscFxAec AS DSCFXAec _                      ' __out LPDSCFXAec pDscFxAec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 20
     BYREF pdwStatus AS DWORD _                         ' __out PDWORD pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundCaptureFXNoiseSuppress interface
' Inherited interface = IUnknown
' ########################################################################################

' // Size = 4 bytes
TYPE DSCFXNoiseSuppress DWORD
   fEnable AS LONG
END TYPE

INTERFACE IDirectSoundCaptureFXNoiseSuppress $IID_IDirectSoundCaptureFXNoiseSuppress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAllParameters ( _                          ' VTable offset = 12
     BYREF pcDscFxNoiseSuppress AS DSCFXNoiseSuppress _ ' __in LPCDSCFXNoiseSuppress pcDscFxNoiseSuppress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllParameters ( _                          ' VTable offset = 16
     BYREF pcDscFxNoiseSuppress AS DSCFXNoiseSuppress _ ' __out LPDSCFXNoiseSuppress pcDscFxNoiseSuppress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' IDirectSoundFullDuplex interface
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectSoundFullDuplex $IID_IDirectSoundFullDuplex

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pCaptureGuid AS GUID _                       ' __in LPCGUID pCaptureGuid
   , BYREF pRenderGuid AS GUID _                        ' __in LPCGUID pRenderGuid
   , BYREF lpDscBufferDesc AS DSCBUFFERDESC _           ' __in LPCDSCBUFFERDESC lpDscBufferDesc
   , BYREF lpDsBufferDesc AS DSCBUFFERDESC _            ' __in LPCDSBUFFERDESC lpDsBufferDesc
   , BYVAL hWmd AS DWORD _                              ' __in HWND hWmd
   , BYVAL dwLevel AS DWORD _                           ' __in DWORD dwLevel
   , BYREF lplpDirectSoundCaptureBuffer8 AS IDirectSoundCaptureBuffer8 _  ' __out LPLPDIRECTSOUNDCAPTUREBUFFER8 lplpDirectSoundCaptureBuffer8
   , BYREF lplpDirectSoundBuffer8 AS IDirectSoundBuffer8 _                ' __out LPLPDIRECTSOUNDBUFFER8 lplpDirectSoundBuffer8
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800


'//
'// Return Codes
'//

'// The function completed successfully
%DS_OK                         =  %S_OK

'// The call succeeded, but we had to substitute the 3D algorithm
'#define DS_NO_VIRTUALIZATION            MAKE_HRESULT(0, _FACDS, 10)
%DS_NO_VIRTUALIZATION = &H878000A

'// The call failed because resources (such as a priority level)
'// were already being used by another caller
'#define DSERR_ALLOCATED                 MAKE_DSHRESULT(10)
%DSERR_ALLOCATED = &H8878000A

'// The control (vol, pan, etc.) requested by the caller is not available
'#define DSERR_CONTROLUNAVAIL            MAKE_DSHRESULT(30)
%DSERR_CONTROLUNAVAIL = &H8878001E

'// An invalid parameter was passed to the returning function
%DSERR_INVALIDPARAM            =  %E_INVALIDARG

'// This call is not valid for the current state of this object
'#define DSERR_INVALIDCALL               MAKE_DSHRESULT(50)

'// An undetermined error occurred inside the DirectSound subsystem
%DSERR_GENERIC                 =  %E_FAIL

'// The caller does not have the priority level required for the function to
'// succeed
'#define DSERR_PRIOLEVELNEEDED           MAKE_DSHRESULT(70)
%DSERR_PRIOLEVELNEEDED = &H88780046

'// Not enough free memory is available to complete the operation
%DSERR_OUTOFMEMORY             =  %E_OUTOFMEMORY

'// The specified WAVE format is not supported
'#define DSERR_BADFORMAT                 MAKE_DSHRESULT(100)
%DSERR_BADFORMAT = &H88780064

'// The function called is not supported at this time
%DSERR_UNSUPPORTED             =  %E_NOTIMPL

'// No sound driver is available for use
'#define DSERR_NODRIVER                  MAKE_DSHRESULT(120)
%DSERR_NODRIVER = &H88780078

'// This object is already initialized
'#define DSERR_ALREADYINITIALIZED        MAKE_DSHRESULT(130)
%DSERR_ALREADYINITIALIZED = &H88780082

'// This object does not support aggregation
%DSERR_NOAGGREGATION            = %CLASS_E_NOAGGREGATION

'// The buffer memory has been lost, and must be restored
'#define DSERR_BUFFERLOST                MAKE_DSHRESULT(150)
%DSERR_BUFFERLOST = &H88780096

'// Another app has a higher priority level, preventing this call from
'// succeeding
'#define DSERR_OTHERAPPHASPRIO           MAKE_DSHRESULT(160)
%DSERR_OTHERAPPHASPRIO = &H887800A0

'// This object has not been initialized
'#define DSERR_UNINITIALIZED             MAKE_DSHRESULT(170)
%DSERR_UNINITIALIZED = &H887800AA

'// The requested COM interface is not available
%DSERR_NOINTERFACE              =  %E_NOINTERFACE

'// Access is denied
%DSERR_ACCESSDENIED             =  %E_ACCESSDENIED

'// Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds
'#define DSERR_BUFFERTOOSMALL            MAKE_DSHRESULT(180)
%DSERR_BUFFERTOOSMALL = &H887800B4

'// Attempt to use DirectSound 8 functionality on an older DirectSound object
'#define DSERR_DS8_REQUIRED              MAKE_DSHRESULT(190)
%DSERR_DS8_REQUIRED = &H887800BE

'// A circular loop of send effects was detected
'#define DSERR_SENDLOOP                  MAKE_DSHRESULT(200)
%DSERR_SENDLOOP = &H887800C8

'// The GUID specified in an audiopath file does not match a valid MIXIN buffer
'#define DSERR_BADSENDBUFFERGUID         MAKE_DSHRESULT(210)
%DSERR_BADSENDBUFFERGUID = &H887800D2

'// The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)
'#define DSERR_OBJECTNOTFOUND            MAKE_DSHRESULT(4449)
%DSERR_OBJECTNOTFOUND = &H88781161

'// The effects requested could not be found on the system, or they were found
'// but in the wrong order, or in the wrong hardware/software locations.
'#define DSERR_FXUNAVAILABLE             MAKE_DSHRESULT(220)
%DSERR_FXUNAVAILABLE = &H887800DC

'//
'// Flags
'//

%DSCAPS_PRIMARYMONO          = &H00000001???
%DSCAPS_PRIMARYSTEREO        = &H00000002???
%DSCAPS_PRIMARY8BIT          = &H00000004???
%DSCAPS_PRIMARY16BIT         = &H00000008???
%DSCAPS_CONTINUOUSRATE       = &H00000010???
%DSCAPS_EMULDRIVER           = &H00000020???
%DSCAPS_CERTIFIED            = &H00000040???
%DSCAPS_SECONDARYMONO        = &H00000100???
%DSCAPS_SECONDARYSTEREO      = &H00000200???
%DSCAPS_SECONDARY8BIT        = &H00000400???
%DSCAPS_SECONDARY16BIT       = &H00000800???

%DSSCL_NORMAL                = &H00000001???
%DSSCL_PRIORITY              = &H00000002???
%DSSCL_EXCLUSIVE             = &H00000003???
%DSSCL_WRITEPRIMARY          = &H00000004???

%DSSPEAKER_DIRECTOUT         = &H00000000???
%DSSPEAKER_HEADPHONE         = &H00000001???
%DSSPEAKER_MONO              = &H00000002???
%DSSPEAKER_QUAD              = &H00000003???
%DSSPEAKER_STEREO            = &H00000004???
%DSSPEAKER_SURROUND          = &H00000005???
%DSSPEAKER_5POINT1           = &H00000006???
%DSSPEAKER_7POINT1           = &H00000007???

%DSSPEAKER_GEOMETRY_MIN      = &H00000005???  ' //   5 degrees
%DSSPEAKER_GEOMETRY_NARROW   = &H0000000A???  ' //  10 degrees
%DSSPEAKER_GEOMETRY_WIDE     = &H00000014???  ' //  20 degrees
%DSSPEAKER_GEOMETRY_MAX      = &H000000B4???  ' // 180 degrees

' Macros
'#define DSSPEAKER_COMBINED(c, g)    ((DWORD)(((BYTE)(c)) | ((DWORD)((BYTE)(g))) << 16))
FUNCTION DSSPEAKER_COMBINED (BYVAL c AS BYTE, BYVAL g AS BYTE) AS DWORD
   LOCAL dwc AS DWORD
   LOCAL dwg AS DWORD
   SHIFT LEFT g, 16
   dwc = c
   dwg = g
   FUNCTION = dwc OR dwg
END FUNCTION

'#define DSSPEAKER_CONFIG(a)         ((BYTE)(a))
FUNCTION DSSPEAKER_CONFIG (BYVAL a AS DWORD) AS BYTE
   FUNCTION = BITS(BYTE, a)
END FUNCTION

'#define DSSPEAKER_GEOMETRY(a)       ((BYTE)(((DWORD)(a) >> 16) & 0x00FF))
FUNCTION DSSPEAKER_GEOMETRY (BYVAL a AS DWORD) AS BYTE
    SHIFT RIGHT a, 16
    a = a AND &H00FF
    FUNCTION = BITS(BYTE, a)
END FUNCTION

%DSBCAPS_PRIMARYBUFFER        = &H00000001???
%DSBCAPS_STATIC               = &H00000002???
%DSBCAPS_LOCHARDWARE          = &H00000004???
%DSBCAPS_LOCSOFTWARE          = &H00000008???
%DSBCAPS_CTRL3D               = &H00000010???
%DSBCAPS_CTRLFREQUENCY        = &H00000020???
%DSBCAPS_CTRLPAN              = &H00000040???
%DSBCAPS_CTRLVOLUME           = &H00000080???
%DSBCAPS_CTRLPOSITIONNOTIFY   = &H00000100???
%DSBCAPS_CTRLFX               = &H00000200???
%DSBCAPS_STICKYFOCUS          = &H00004000???
%DSBCAPS_GLOBALFOCUS          = &H00008000???
%DSBCAPS_GETCURRENTPOSITION2  = &H00010000???
%DSBCAPS_MUTE3DATMAXDISTANCE  = &H00020000???
%DSBCAPS_LOCDEFER             = &H00040000???

%DSBPLAY_LOOPING              = &H00000001???
%DSBPLAY_LOCHARDWARE          = &H00000002???
%DSBPLAY_LOCSOFTWARE          = &H00000004???
%DSBPLAY_TERMINATEBY_TIME     = &H00000008???
%DSBPLAY_TERMINATEBY_DISTANCE = &H00000010???
%DSBPLAY_TERMINATEBY_PRIORITY = &H00000020???

%DSBSTATUS_PLAYING            = &H00000001???
%DSBSTATUS_BUFFERLOST         = &H00000002???
%DSBSTATUS_LOOPING            = &H00000004???
%DSBSTATUS_LOCHARDWARE        = &H00000008???
%DSBSTATUS_LOCSOFTWARE        = &H00000010???
%DSBSTATUS_TERMINATED         = &H00000020???

%DSBLOCK_FROMWRITECURSOR      = &H00000001???
%DSBLOCK_ENTIREBUFFER         = &H00000002???

%DSBFREQUENCY_ORIGINAL        = 0
%DSBFREQUENCY_MIN             = 100
'#if DIRECTSOUND_VERSION >= 0x0900
%DSBFREQUENCY_MAX             = 200000
'#else
'#define DSBFREQUENCY_MAX            100000
'#endif

%DSBPAN_LEFT                  = -10000
%DSBPAN_CENTER                = 0
%DSBPAN_RIGHT                 = 10000

%DSBVOLUME_MIN                = -10000
%DSBVOLUME_MAX                = 0

%DSBSIZE_MIN                  = 4
%DSBSIZE_MAX                  = &H0FFFFFFF???
%DSBSIZE_FX_MIN               = 150  ' // NOTE: Milliseconds, not bytes

%DS3DMODE_NORMAL              = &H00000000???
%DS3DMODE_HEADRELATIVE        = &H00000001???
%DS3DMODE_DISABLE             = &H00000002???

%DS3D_IMMEDIATE               = &H00000000???
%DS3D_DEFERRED                = &H00000001???

MACRO DS3D_MINDISTANCEFACTOR     = 1.175494351e-38   ' FLT_MIN
MACRO DS3D_MAXDISTANCEFACTOR     = 3.402823466e+38   ' FLT_MAX
MACRO DS3D_DEFAULTDISTANCEFACTOR = 1.0!

MACRO DS3D_MINROLLOFFFACTOR      = 0.0!
MACRO DS3D_MAXROLLOFFFACTOR      = 10.0!
MACRO DS3D_DEFAULTROLLOFFFACTOR  = 1.0!

MACRO DS3D_MINDOPPLERFACTOR      = 0.0!
MACRO DS3D_MAXDOPPLERFACTOR      = 10.0!
MACRO DS3D_DEFAULTDOPPLERFACTOR  = 1.0!

MACRO DS3D_DEFAULTMINDISTANCE    = 1.0!
MACRO DS3D_DEFAULTMAXDISTANCE    = 1000000000.0!

%DS3D_MINCONEANGLE          = 0
%DS3D_MAXCONEANGLE          = 360
%DS3D_DEFAULTCONEANGLE      = 360

%DS3D_DEFAULTCONEOUTSIDEVOLUME = %DSBVOLUME_MAX

'// IDirectSoundCapture attributes

%DSCCAPS_EMULDRIVER        =  %DSCAPS_EMULDRIVER
%DSCCAPS_CERTIFIED         =  %DSCAPS_CERTIFIED
%DSCCAPS_MULTIPLECAPTURE   =  &H00000001???

'// IDirectSoundCaptureBuffer attributes

%DSCBCAPS_WAVEMAPPED       =  &H80000000???

'#if DIRECTSOUND_VERSION >= 0x0800
%DSCBCAPS_CTRLFX           =  &H00000200???
'#endif


%DSCBLOCK_ENTIREBUFFER     =  &H00000001???

%DSCBSTATUS_CAPTURING      =  &H00000001???
%DSCBSTATUS_LOOPING        =  &H00000002???

%DSCBSTART_LOOPING         =  &H00000001???

%DSBPN_OFFSETSTOP          =  &HFFFFFFFF???

%DS_CERTIFIED              =  &H00000000???
%DS_UNCERTIFIED            =  &H00000001???


'//
'// Flags for the I3DL2 effects
'//

'//
'// I3DL2 Material Presets
'//

' enum
%DSFX_I3DL2_MATERIAL_PRESET_SINGLEWINDOW = 0
%DSFX_I3DL2_MATERIAL_PRESET_DOUBLEWINDOW = 1
%DSFX_I3DL2_MATERIAL_PRESET_THINDOOR     = 2
%DSFX_I3DL2_MATERIAL_PRESET_THICKDOOR    = 3
%DSFX_I3DL2_MATERIAL_PRESET_WOODWALL     = 4
%DSFX_I3DL2_MATERIAL_PRESET_BRICKWALL    = 5
%DSFX_I3DL2_MATERIAL_PRESET_STONEWALL    = 6
%DSFX_I3DL2_MATERIAL_PRESET_CURTAIN      = 7

MACRO I3DL2_MATERIAL_PRESET_SINGLEWINDOW   = -2800,0.71!
MACRO I3DL2_MATERIAL_PRESET_DOUBLEWINDOW   = -5000,0.40!
MACRO I3DL2_MATERIAL_PRESET_THINDOOR       = -1800,0.66!
MACRO I3DL2_MATERIAL_PRESET_THICKDOOR      = -4400,0.64!
MACRO I3DL2_MATERIAL_PRESET_WOODWALL       = -4000,0.50!
MACRO I3DL2_MATERIAL_PRESET_BRICKWALL      = -5000,0.60!
MACRO I3DL2_MATERIAL_PRESET_STONEWALL      = -6000,0.68!
MACRO I3DL2_MATERIAL_PRESET_CURTAIN        = -1200,0.15!

' enum
%DSFX_I3DL2_ENVIRONMENT_PRESET_DEFAULT         = 0
%DSFX_I3DL2_ENVIRONMENT_PRESET_GENERIC         = 1
%DSFX_I3DL2_ENVIRONMENT_PRESET_PADDEDCELL      = 2
%DSFX_I3DL2_ENVIRONMENT_PRESET_ROOM            = 3
%DSFX_I3DL2_ENVIRONMENT_PRESET_BATHROOM        = 4
%DSFX_I3DL2_ENVIRONMENT_PRESET_LIVINGROOM      = 5
%DSFX_I3DL2_ENVIRONMENT_PRESET_STONEROOM       = 6
%DSFX_I3DL2_ENVIRONMENT_PRESET_AUDITORIUM      = 7
%DSFX_I3DL2_ENVIRONMENT_PRESET_CONCERTHALL     = 8
%DSFX_I3DL2_ENVIRONMENT_PRESET_CAVE            = 9
%DSFX_I3DL2_ENVIRONMENT_PRESET_ARENA           = 10
%DSFX_I3DL2_ENVIRONMENT_PRESET_HANGAR          = 11
%DSFX_I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY = 12
%DSFX_I3DL2_ENVIRONMENT_PRESET_HALLWAY         = 13
%DSFX_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR   = 14
%DSFX_I3DL2_ENVIRONMENT_PRESET_ALLEY           = 15
%DSFX_I3DL2_ENVIRONMENT_PRESET_FOREST          = 16
%DSFX_I3DL2_ENVIRONMENT_PRESET_CITY            = 17
%DSFX_I3DL2_ENVIRONMENT_PRESET_MOUNTAINS       = 18
%DSFX_I3DL2_ENVIRONMENT_PRESET_QUARRY          = 19
%DSFX_I3DL2_ENVIRONMENT_PRESET_PLAIN           = 20
%DSFX_I3DL2_ENVIRONMENT_PRESET_PARKINGLOT      = 21
%DSFX_I3DL2_ENVIRONMENT_PRESET_SEWERPIPE       = 22
%DSFX_I3DL2_ENVIRONMENT_PRESET_UNDERWATER      = 23
%DSFX_I3DL2_ENVIRONMENT_PRESET_SMALLROOM       = 24
%DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM      = 25
%DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEROOM       = 26
%DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL      = 27
%DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEHALL       = 28
%DSFX_I3DL2_ENVIRONMENT_PRESET_PLATE           = 29

'//
'// I3DL2 Reverberation Presets Values
'//

MACRO I3DL2_ENVIRONMENT_PRESET_DEFAULT         = -1000,-100,0.0!,1.49!,0.83!,-2602,0.007!,200,0.011!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_GENERIC         = -1000,-100,0.0!,1.491,0.83!,-2602,0.007!,200,0.011!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_PADDEDCELL      = -1000,-6000,0.0!,0.17!,0.10!,-1204,0.001!,207,0.002!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_ROOM            = -1000,-454,0.0!,0.40!,0.83!,-1646,0.002!,53,0.003!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_BATHROOM        = -1000,-1200,0.0!,1.49!,0.54!,-370,0.007!,1030,0.011!,100.0!,60.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_LIVINGROOM      = -1000,-6000,0.0!,0.50!,0.10!,-1376,0.003!,-1104,0.004!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_STONEROOM       = -1000,-300,0.0!,2.31!,0.64!,-711,0.012!,83,0.017!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_AUDITORIUM      = -1000,-476,0.0!,4.32!,0.59!,-789,0.020!,-289,0.030!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_CONCERTHALL     = -1000,-500,0.0!,3.92!,0.70!,-1230,0.020!,-2,0.029!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_CAVE            = -1000,0,0.0!,2.91!,1.30!,-602,0.015!,-302,0.022!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_ARENA           = -1000,-698,0.0!,7.24!,0.33!,-1166,0.020!,16,0.030!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_HANGAR          = -1000,-1000,0.0!,10.05!,0.23!,-602,0.020!,198,0.030!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY = -1000,-4000,0.0!,0.30!,0.10!,-1831,0.002!,-1630,0.030!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_HALLWAY         = -1000,-300,0.0!,1.49!,0.59!,-1219,0.007!,441,0.011!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR   = -1000,-237,0.0!,2.70!,0.79!,-1214,0.013!,395,0.020!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_ALLEY           = -1000,-270,0.0!,1.49!,0.86!,-1204,0.007!,-4,0.011!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_FOREST          = -1000,-3300,0.0!,1.49!,0.54!,-2560,0.162!,-613,0.088!,79.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_CITY            = -1000,-800,0.0!,1.49!,0.67!,-2273,0.007!,-2217,0.011!,50.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_MOUNTAINS       = -1000,-2500,0.0!,1.49!,0.21!,-2780,0.300!,-2014,0.100!,27.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_QUARRY          = -1000,-1000,0.0!,1.49!,0.83!,-10000,0.061!,500,0.025!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_PLAIN           = -1000,-2000,0.0!,1.49!,0.50!,-2466,0.179!,-2514,0.100!,21.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_PARKINGLOT      = -1000,0,0.0!,1.651,1.50!,-1363,0.008!,-1153,0.012!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_SEWERPIPE       = -1000,-1000,0.0!,2.811,0.14!,429,0.014!,648,0.021!,80.0!,60.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_UNDERWATER      = -1000,-4000,0.0!,1.49!,0.10!,-449,0.007!,1700,0.011!,100.0!,100.0!,5000.0!

'//
'// Examples simulating 'musical' reverb presets
'//
'// Name       Decay time   Description
'// Small Room    1.1s      A small size room with a length of 5m or so.
'// Medium Room   1.3s      A medium size room with a length of 10m or so.
'// Large Room    1.5s      A large size room suitable for live performances.
'// Medium Hall   1.8s      A medium size concert hall.
'// Large Hall    1.8s      A large size concert hall suitable for a full orchestra.
'// Plate         1.3s      A plate reverb simulation.
'//

MACRO I3DL2_ENVIRONMENT_PRESET_SMALLROOM      = -1000,-600, 0.0!,1.10!,0.83!,-400,0.005!,500,0.010!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM     = -1000,-600, 0.0!,1.30!,0.83!,-1000,0.010!,-200,0.020!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_LARGEROOM      = -1000,-600, 0.0!,1.50!,0.83!,-1600,0.020!,-1000,0.040!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL     = -1000,-600, 0.0!,1.80!,0.70!,-1300,0.015!,-800,0.030!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_LARGEHALL      = -1000,-600, 0.0!,1.80!,0.70!,-2000,0.030!,-1400,0.060!,100.0!,100.0!,5000.0!
MACRO I3DL2_ENVIRONMENT_PRESET_PLATE          = -1000,-200, 0.01,1.30!,0.90!,0,0.002!,0,0.010!,100.0!,75.0!,5000.0!


'//
'// DirectSound3D Algorithms
'//

'// Default DirectSound3D algorithm {00000000-0000-0000-0000-000000000000}
$DS3DALG_DEFAULT                       = GUID$("{00000000-0000-0000-0000-000000000000}")

'// No virtualization (Pan3D) {C241333F-1C1B-11d2-94F5-00C04FC28ACA}
$DS3DALG_NO_VIRTUALIZATION             = GUID$("{C241333F-1C1B-11d2-94F5-00C04FC28ACA}")

'// High-quality HRTF algorithm {C2413340-1C1B-11d2-94F5-00C04FC28ACA}
$DS3DALG_HRTF_FULL                     = GUID$("{C2413340-1C1B-11d2-94F5-00C04FC28ACA}")

'// Lower-quality HRTF algorithm {C2413342-1C1B-11d2-94F5-00C04FC28ACA}
$DS3DALG_HRTF_LIGHT                    = GUID$("{C2413342-1C1B-11d2-94F5-00C04FC28ACA}")


#IF %DIRECTSOUND_VERSION >= &H0800

'//
'// DirectSound Internal Effect Algorithms
'//

'// Gargle {DAFD8210-5711-4B91-9FE3-F75B7AE279BF}
$GUID_DSFX_STANDARD_GARGLE             = GUID$("{DAFD8210-5711-4B91-9FE3-F75B7AE279BF}")

'// Chorus {EFE6629C-81F7-4281-BD91-C9D604A95AF6}
$GUID_DSFX_STANDARD_CHORUS             = GUID$("{EFE6629C-81F7-4281-BD91-C9D604A95AF6}")

'// Flanger {EFCA3D92-DFD8-4672-A603-7420894BAD98}
$GUID_DSFX_STANDARD_FLANGER            = GUID$("{EFCA3D92-DFD8-4672-A603-7420894BAD98}")

'// Echo/Delay {EF3E932C-D40B-4F51-8CCF-3F98F1B29D5D}
$GUID_DSFX_STANDARD_ECHO               = GUID$("{EF3E932C-D40B-4F51-8CCF-3F98F1B29D5D}")

'// Distortion {EF114C90-CD1D-484E-96E5-09CFAF912A21}
$GUID_DSFX_STANDARD_DISTORTION         = GUID$("{EF114C90-CD1D-484E-96E5-09CFAF912A21}")

'// Compressor/Limiter {EF011F79-4000-406D-87AF-BFFB3FC39D57}
$GUID_DSFX_STANDARD_COMPRESSOR         = GUID$("{EF011F79-4000-406D-87AF-BFFB3FC39D57}")

'// Parametric Equalization {120CED89-3BF4-4173-A132-3CB406CF3231}
$GUID_DSFX_STANDARD_PARAMEQ            = GUID$("{120CED89-3BF4-4173-A132-3CB406CF3231}")

'// I3DL2 Environmental Reverberation: Reverb (Listener) Effect {EF985E71-D5C7-42D4-BA4D-2D073E2E96F4}
$GUID_DSFX_STANDARD_I3DL2REVERB        = GUID$("{EF985E71-D5C7-42D4-BA4D-2D073E2E96F4}")

'// Waves Reverberation {87FC0268-9A55-4360-95AA-004A1D9DE26C}
$GUID_DSFX_WAVES_REVERB                = GUID$("{87FC0268-9A55-4360-95AA-004A1D9DE26C}")

'//
'// DirectSound Capture Effect Algorithms
'//

'// Acoustic Echo Canceller {BF963D80-C559-11D0-8A2B-00A0C9255AC1}
'// Matches KSNODETYPE_ACOUSTIC_ECHO_CANCEL in ksmedia.h
$GUID_DSCFX_CLASS_AEC                  = GUID$("{BF963D80-C559-11D0-8A2B-00A0C9255AC1}")

'// Microsoft AEC {CDEBB919-379A-488a-8765-F53CFD36DE40}
$GUID_DSCFX_MS_AEC                     = GUID$("{CDEBB919-379A-488a-8765-F53CFD36DE40}")

'// System AEC {1C22C56D-9879-4f5b-A389-27996DDC2810}
$GUID_DSCFX_SYSTEM_AEC                 = GUID$("{1C22C56D-9879-4f5b-A389-27996DDC2810}")

'// Noise Supression {E07F903F-62FD-4e60-8CDD-DEA7236665B5}
'// Matches KSNODETYPE_NOISE_SUPPRESS in post Windows ME DDK's ksmedia.h
$GUID_DSCFX_CLASS_NS                   = GUID$("{E07F903F-62FD-4e60-8CDD-DEA7236665B5}")

'// Microsoft Noise Suppresion {11C5C73B-66E9-4ba1-A0BA-E814C6EED92D}
$GUID_DSCFX_MS_NS                      = GUID$("{11C5C73B-66E9-4ba1-A0BA-E814C6EED92D}")

'// System Noise Suppresion {5AB0882E-7274-4516-877D-4EEE99BA4FD0}
$GUID_DSCFX_SYSTEM_NS                  = GUID$("{5AB0882E-7274-4516-877D-4EEE99BA4FD0}")

#ENDIF   ' // DIRECTSOUND_VERSION >= 0x0800
