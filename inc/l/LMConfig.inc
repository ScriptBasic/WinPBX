' ########################################################################################
' Microsoft Windows
' File: LMConfig.inc
' Contents: API function prototypes and data structures for the NetConfig group of NT API functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMCONFIG_INC = 1

'#define REVISED_CONFIG_APIS

'//
'// Function Prototypes - Config
'//

DECLARE FUNCTION NetConfigGet IMPORT "NETAPI32.DLL" ALIAS "NetConfigGet" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LPCWSTR  server OPTIONAL
 , BYREF component AS WSTRINGZ _                        ' __in  LPCWSTR  component
 , BYREF parameter AS WSTRINGZ _                        ' __in  LPCWSTR  parameter
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetConfigGetAll IMPORT "NETAPI32.DLL" ALIAS "NetConfigGetAll" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LPCWSTR  server OPTIONAL
 , BYREF component AS WSTRINGZ _                        ' __in  LPCWSTR  component
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetConfigSet IMPORT "NETAPI32.DLL" ALIAS "NetConfigSet" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LPCWSTR  server OPTIONAL
 , BYREF reserved1 AS WSTRINGZ _                        ' __in  LPCWSTR  reserved1 OPTIONAL
 , BYREF component AS WSTRINGZ _                        ' __in  LPCWSTR  component
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYVAL reserved2 AS DWORD _                           ' __in  DWORD    reserved2
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE   buf
 , BYVAL reserved3 AS DWORD _                           ' __in  DWORD    reserved3
 ) AS DWORD                                             ' NET_API_STATUS

' Removed in the Windows 7 SDK
'DECLARE FUNCTION NetRegisterDomainNameChangeNotification _
'   IMPORT "NETAPI32.DLL" ALIAS "NetRegisterDomainNameChangeNotification" ( _
'   BYREF NotificationEventHandle AS DWORD _             ' __out PHANDLE NotificationEventHandle
' ) AS DWORD                                             ' NET_API_STATUS

' Removed in the Windows 7 SDK
'DECLARE FUNCTION NetUnregisterDomainNameChangeNotification _
'   IMPORT "NETAPI32.DLL" ALIAS "NetUnregisterDomainNameChangeNotification" ( _
'   BYVAL NotificationEventHandle AS DWORD _             ' __in HANDLE NotificationEventHandle
' ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Config
'//

' // Size = 8 bytes
TYPE CONFIG_INFO_0 DWORD
   cfgi0_key  AS WSTRINGZ PTR   ' LPWSTR
   cfgi0_data AS WSTRINGZ PTR   ' LPWSTR
END TYPE
