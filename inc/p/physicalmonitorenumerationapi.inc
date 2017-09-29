' ########################################################################################
' Microsoft Windows
' File: PhysicalMonitorEnumerationAPI.inc (Windows Vista)
' Contents: Windows Installer (MSI)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PHYSICALMONITORENUMERATIONAPI_INC = 1

#INCLUDE ONCE "d3d9.inc"

'#pragma pack( push, 1  )

'/******************************************************************************
'    Physical Monitor Type Definitions
'******************************************************************************/

'typedef __success(return == TRUE) BOOL _BOOL;

'/******************************************************************************
'    Physical Monitor Constants
'******************************************************************************/

'// A physical monitor description is always an array of 128 characters.  Some
'// of the characters may not be used.
%PHYSICAL_MONITOR_DESCRIPTION_SIZE                  = 128

'/******************************************************************************
'    Physical Monitor Structures
'******************************************************************************/
' // Size = 260 bytes
TYPE PHYSICAL_MONITOR DWORD
   hPhysicalMonitor AS DWORD   ' HANDLE
   szPhysicalMonitorDescription AS STRING * %PHYSICAL_MONITOR_DESCRIPTION_SIZE * 2   ' WCHAR
END TYPE

'/******************************************************************************
'    Physical Monitor Enumeration Functions
'******************************************************************************/
DECLARE FUNCTION GetNumberOfPhysicalMonitorsFromHMONITOR IMPORT "dxva2.dll" ALIAS "GetNumberOfPhysicalMonitorsFromHMONITOR" ( _
   BYVAL hMonitor AS DWORD _                            ' HMONITOR hMonitor
 , BYREF pdwNumberOfPhysicalMonitors AS DWORD _         ' __out LPDWORD pdwNumberOfPhysicalMonitors
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetNumberOfPhysicalMonitorsFromIDirect3DDevice9 IMPORT "dxva2.dll" ALIAS "GetNumberOfPhysicalMonitorsFromIDirect3DDevice9" ( _
   BYVAL pDirect3DDevice9 AS IDirect3DDevice9 _         ' __in  IDirect3DDevice9* pDirect3DDevice9
 , BYREF pdwNumberOfPhysicalMonitors AS DWORD _         ' __out LPDWORD pdwNumberOfPhysicalMonitors
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetPhysicalMonitorsFromHMONITOR IMPORT "dxva2.dll" ALIAS "GetPhysicalMonitorsFromHMONITOR" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HMONITOR hMonitor
 , BYVAL dwPhysicalMonitorArraySize AS DWORD _          ' __in  DWORD dwPhysicalMonitorArraySize
 , BYREF pPhysicalMonitorArray AS PHYSICAL_MONITOR _    ' __out LPPHYSICAL_MONITOR pPhysicalMonitorArray
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetPhysicalMonitorsFromIDirect3DDevice9 IMPORT "dxva2.dll" ALIAS "GetPhysicalMonitorsFromIDirect3DDevice9" ( _
   BYVAL pDirect3DDevice9 AS IDirect3DDevice9 _         ' __in  IDirect3DDevice9* pDirect3DDevice9
 , BYVAL dwPhysicalMonitorArraySize AS DWORD _          ' __in  DWORD dwPhysicalMonitorArraySize
 , BYREF pPhysicalMonitorArray AS PHYSICAL_MONITOR _    ' __out LPPHYSICAL_MONITOR pPhysicalMonitorArray
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DestroyPhysicalMonitor IMPORT "dxva2.dll" ALIAS "DestroyPhysicalMonitor" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DestroyPhysicalMonitors IMPORT "dxva2.dll" ALIAS "DestroyPhysicalMonitors" ( _
   BYVAL dwPhysicalMonitorArraySize AS DWORD _          ' __in DWORD dwPhysicalMonitorArraySize
 , BYREF pPhysicalMonitorArray AS PHYSICAL_MONITOR _    ' __in LPPHYSICAL_MONITOR pPhysicalMonitorArray
 ) AS LONG                                              ' BOOL

'#pragma pack( pop )
