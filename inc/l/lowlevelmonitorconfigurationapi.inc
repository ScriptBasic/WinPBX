' ########################################################################################
' Microsoft Windows
' File: LowLevelMonitorConfigurationApi.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LOWLEVELMONITORCONFIGURATIONAPI_INC = 1

#INCLUDE ONCE "PhysicalMonitorEnumerationAPI.inc"

'#pragma pack( push, 1  )

' // Size = 9 bytes
TYPE MC_TIMING_REPORT BYTE
   dwHorizontalFrequencyInHZ AS DWORD   ' DWORD
   dwVerticalFrequencyInHZ   AS DWORD   ' DWORD
   bTimingStatusByte         AS BYTE    ' BYTE
END TYPE

' enum MC_VCP_CODE_TYPE
%MC_MOMENTARY     = 0
%MC_SET_PARAMETER = 1

DECLARE FUNCTION GetVCPFeatureAndVCPFeatureReply IMPORT "dxva2.dll" ALIAS "GetVCPFeatureAndVCPFeatureReply" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL bVCPCode AS BYTE _                             ' __in BYTE bVCPCode
 , BYREF pvct AS DWORD _                                ' __out_opt LPMC_VCP_CODE_TYPE pvct
 , BYREF pdwCurrentValue AS DWORD _                     ' __out LPDWORD pdwCurrentValue
 , BYREF pdwMaximumValue AS DWORD _                     ' __out_opt LPDWORD pdwMaximumValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetVCPFeature IMPORT "dxva2.dll" ALIAS "SetVCPFeature" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL bVCPCode AS BYTE _                             ' __in BYTE bVCPCode
 , BYVAL dwNewValue AS DWORD _                          ' __in DWORD dwNewValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaveCurrentSettings IMPORT "dxva2.dll" ALIAS "SaveCurrentSettings" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetCapabilitiesStringLength IMPORT "dxva2.dll" ALIAS "GetCapabilitiesStringLength" ( _
   BYVAL hMonitor AS DWORD _                                ' __in HANDLE hMonitor
 , BYREF pdwCapabilitiesStringLengthInCharacters AS DWORD _ ' __out LPDWORD pdwCapabilitiesStringLengthInCharacters
 ) AS LONG                                                  ' BOOL

DECLARE FUNCTION CapabilitiesRequestAndCapabilitiesReply IMPORT "dxva2.dll" ALIAS "CapabilitiesRequestAndCapabilitiesReply" ( _
   BYVAL hMonitor AS DWORD _                               ' __in HANDLE hMonitor
 , BYREF pszASCIICapabilitiesString AS ASCIIZ _            ' __out LPSTR pszASCIICapabilitiesString
 , BYVAL dwCapabilitiesStringLengthInCharacters AS DWORD _ ' __in DWORD dwCapabilitiesStringLengthInCharacters
 ) AS LONG                                                 ' BOOL

DECLARE FUNCTION GetTimingReport IMPORT "dxva2.dll" ALIAS "GetTimingReport" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYREF pmtrMonitorTimingReport AS DWORD _             ' __out LPMC_TIMING_REPORT pmtrMonitorTimingReport
 ) AS LONG                                              ' BOOL

'#pragma pack( pop )
