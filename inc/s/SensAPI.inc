' ########################################################################################
' Microsoft Windows
' File: SensAPI.inc
' Contents: Public header file for the SENS Connectivity APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SENSAPI_INC = 1

%NETWORK_ALIVE_LAN      = &H00000001???
%NETWORK_ALIVE_WAN      = &H00000002???
%NETWORK_ALIVE_AOL      = &H00000004???
%NETWORK_ALIVE_INTERNET = &H00000008???

' // Size = 16 bytes
TYPE QOCINFO DWORD
   dwSize     AS DWORD   ' DWORD dwSize
   dwFlags    AS DWORD   ' DWORD dwFlags
   dwInSpeed  AS DWORD   ' DWORD dwInSpeed
   dwOutSpeed AS DWORD   ' DWORD dwOutSpeed
END TYPE

DECLARE FUNCTION IsDestinationReachableA IMPORT "sensapi.dll" ALIAS "IsDestinationReachableA" ( _
   BYREF lpszDestination AS ASCIIZ _                    ' __in LPCSTR lpszDestination
 , BYREF lpQOCInfo AS QOCINFO _                         ' __in_out LPQOCINFO lpQOCInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsDestinationReachableW IMPORT "sensapi.dll" ALIAS "IsDestinationReachableW" ( _
   BYREF lpszDestination AS WSTRINGZ _                  ' __in LPCWSTR lpszDestination
 , BYREF lpQOCInfo AS QOCINFO _                         ' __in_out LPQOCINFO lpQOCInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsDestinationReachable = IsDestinationReachableW
#ELSE
   MACRO IsDestinationReachable = IsDestinationReachableA
#ENDIF

DECLARE FUNCTION IsNetworkAlive IMPORT "sensapi.dll" ALIAS "IsNetworkAlive" ( _
   BYREF lpdwFlags AS DWORD _                           ' __out LPDWORD lpdwFlags
 ) AS LONG                                              ' BOOL
