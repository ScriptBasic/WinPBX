' ########################################################################################
' Microsoft Windows
' File: storprop.inc
' Contents: This module contains structures and definitions associated with exports from
' storprop.dll
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STORPROP_INC = 1

#INCLUDE ONCE "setupapi.inc"   ' // for HDEVINFO and PSP_DEVINFO_DATA

%REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO_VERSION = 1

'//
'// REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO is a structure which
'// defines what the OS believes the abilities of a CD-Rom
'// capable drive are with respect to Digital Audio Extraction (DAE)
'//
'// if Accurate is non-zero, then the drive is able to recover
'//     from loss-of-streaming conditions without losing any
'//     data.  this means the drive never requires what is commonly
'//     referred to as 'stitching' to get a correct audio stream
'// if Supported is non-zero, then the drive supports audio
'//     extraction.  this field does not suggest any quality.
'// AccurateMask0 reports what sized reads (in number of sectors)
'//     the OS believes to work.  this field is a bitmask, with the
'//     lowest bit indicating single-sector reads, and the high bit
'//     indictating 32-sector reads.  if reading a given number of
'//     sectors per read gives accurate results, the bit will be a
'//     '1'.  if Accurate is non-zero, all the bits should be '1'.
'//

' // Size = 16 bytes
TYPE REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO DWORD
   Version       AS DWORD   ' ULONG
   Accurate      AS DWORD   ' ULONG
   Supported     AS DWORD   ' ULONG
   AccurateMask0 AS DWORD   ' ULONG
   ' // more data may later be added to the end, but
   ' // backwards compatibility will be retained.
END TYPE

'DWORD
'CdromCddaInfo(
'    IN     HDEVINFO HDevInfo,
'    IN     PSP_DEVINFO_DATA DevInfoData,
'       OUT PREDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO CddaInfo,
'    IN OUT PULONG BufferSize
'    );

FUNCTION CdromCddaInfo ( _
   BYVAL HDevInfo AS DWORD, _
   BYREF DevInfoData AS SP_DEVINFO_DATA, _
   BYREF CddaInfo AS REDBOOK_DIGITAL_AUDIO_EXTRACTION_INFO, _
   BYREF BufferSize AS DWORD _
   ) AS DWORD

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Storprop.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "CdromCddaInfo")
   IF pProc THEN CALL DWORD pProc USING CdromCddaInfo(HDevInfo, DevInfoData, CddaInfo, BufferSize) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

'BOOL
'CdromKnownGoodDigitalPlayback(IN HDEVINFO HDevInfo,
'                              IN PSP_DEVINFO_DATA DevInfoData);

FUNCTION CdromKnownGoodDigitalPlayback ( _
   BYVAL HDevInfo AS DWORD, _
   BYREF DevInfoData AS SP_DEVINFO_DATA _
   ) AS LONG

   LOCAL bRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Storprop.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "CdromKnownGoodDigitalPlayback")
   IF pProc THEN CALL DWORD pProc USING CdromKnownGoodDigitalPlayback(HDevInfo, DevInfoData) TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION

'LONG
'CdromEnableDigitalPlayback(IN HDEVINFO DevInfo,
'                           IN PSP_DEVINFO_DATA DevInfoData,
'                           IN BOOLEAN ForceUnknown);

FUNCTION CdromEnableDigitalPlayback ( _
   BYVAL HDevInfo AS DWORD, _
   BYREF DevInfoData AS SP_DEVINFO_DATA, _
   BYVAL ForceUnknown AS BYTE _
   ) AS LONG

   LOCAL lRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Storprop.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "CdromEnableDigitalPlayback")
   IF pProc THEN CALL DWORD pProc USING CdromEnableDigitalPlayback(HDevInfo, DevInfoData, ForceUnknown) TO lRes
   FreeLibrary hLib
   FUNCTION = lRes

END FUNCTION

'LONG
'CdromDisableDigitalPlayback( IN HDEVINFO DevInfo,
'                             IN PSP_DEVINFO_DATA DevInfoData);

FUNCTION CdromDisableDigitalPlayback ( _
   BYVAL HDevInfo AS DWORD, _
   BYREF DevInfoData AS SP_DEVINFO_DATA _
   ) AS LONG

   LOCAL lRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Storprop.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "CdromDisableDigitalPlayback")
   IF pProc THEN CALL DWORD pProc USING CdromDisableDigitalPlayback(HDevInfo, DevInfoData) TO lRes
   FreeLibrary hLib
   FUNCTION = lRes

END FUNCTION

'LONG
'CdromIsDigitalPlaybackEnabled(
'    IN  HDEVINFO DevInfo,
'    IN  PSP_DEVINFO_DATA DevInfoData,
'    OUT PBOOLEAN Enabled
'    );

FUNCTION CdromIsDigitalPlaybackEnabled ( _
   BYVAL HDevInfo AS DWORD, _
   BYREF DevInfoData AS SP_DEVINFO_DATA, _
   BYREF Enabled AS BYTE _
   ) AS LONG

   LOCAL lRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD

   hLib = LoadLibrary("Storprop.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "CdromIsDigitalPlaybackEnabled")
   IF pProc THEN CALL DWORD pProc USING CdromIsDigitalPlaybackEnabled(HDevInfo, DevInfoData, Enabled) TO lRes
   FreeLibrary hLib
   FUNCTION = lRes

END FUNCTION
