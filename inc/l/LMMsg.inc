' ########################################################################################
' Microsoft Windows
' File: LMMsg.inc
' Contents: Structures, function prototypes, and definitions for the NetMessage API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMMSG_INC = 1

'//
'// Function Prototypes
'//

DECLARE FUNCTION NetMessageNameAdd IMPORT "NETAPI32.DLL" ALIAS "NetMessageNameAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername
 , BYREF msgname AS WSTRINGZ _                          ' __in  LPCWSTR  msgname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetMessageNameEnum IMPORT "NETAPI32.DLL" ALIAS "NetMessageNameEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR     servername
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD  resume_handle
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetMessageNameGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetMessageNameGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername
 , BYREF msgname AS WSTRINGZ _                          ' __in  LPCWSTR msgname
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetMessageNameDel IMPORT "NETAPI32.DLL" ALIAS "NetMessageNameDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername
 , BYREF msgname AS WSTRINGZ _                          ' __in  LPCWSTR   msgname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetMessageBufferSend IMPORT "NETAPI32.DLL" ALIAS "NetMessageBufferSend" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername
 , BYREF msgname AS WSTRINGZ _                          ' __in  LPCWSTR  msgname
 , BYREF fromname AS WSTRINGZ _                         ' __in  LPCWSTR  fromname
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE   buf
 , BYVAL buflen AS DWORD _                              ' __in  DWORD    buflen
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Data Structures
'//

' // Size = 4 bytes
TYPE MSG_INFO_0 DWORD
   msgi0_name AS WSTRINGZ PTR   ' LPWSTR  msgi0_name
END TYPE

' // Size = 12 bytes
TYPE MSG_INFO_1 DWORD
   msgi1_name         AS WSTRINGZ PTR   ' LPWSTR  msgi1_name
   msgi1_forward_flag AS DWORD          ' DWORD   msgi1_forward_flag
   msgi1_forward      AS WSTRINGZ PTR   ' LPWSTR  msgi1_forward
END TYPE

'//
'// Special Values and Constants
'//

'//
'// Values for msgi1_forward_flag.
'//

%MSGNAME_NOT_FORWARDED   = 0       ' // Name not forwarded
%MSGNAME_FORWARDED_TO    = &H04    ' // Name forward to remote station
%MSGNAME_FORWARDED_FROM  = &H10    ' // Name forwarded from remote station
