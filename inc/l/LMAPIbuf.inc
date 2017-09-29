' ########################################################################################
' Microsoft Windows
' File: LMAPIbuf.inc
' Contents: This file contains information about NetApiBuffer APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMAPIBUF_INC = 1

'//
'// Function Prototypes
'//

DECLARE FUNCTION NetApiBufferAllocate IMPORT "NETAPI32.DLL" ALIAS "NetApiBufferAllocate" ( _
   BYVAL ByteCount AS DWORD _                           ' __in  DWORD ByteCount
 , BYREF Buffer AS ANY _                                ' __out LPVOID * Buffer
 ) AS DWORD                                             ' NET_API_STATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetApiBufferFree LIB "NetApi32.dll" _
    ALIAS "NetApiBufferFree" ( _
    pBuffer AS ANY _  ' LPVOID
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetApiBufferFree IMPORT "NETAPI32.DLL" ALIAS "NetApiBufferFree" ( _
   BYVAL Buffer AS DWORD _                              ' __in LPVOID Buffer
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetApiBufferReallocate LIB "NetApi32.dll" _
    ALIAS "NetApiBufferReallocate" ( _
    pOldBuffer         AS ANY, _  ' LPVOID
    BYVAL NewByteCount AS DWORD, _
    pNewBuffer         AS ANY _   ' LPVOID *
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetApiBufferReallocate IMPORT "NETAPI32.DLL" ALIAS "NetApiBufferReallocate" ( _
   BYVAL OldBuffer AS DWORD _                           ' __in  LPVOID OldBuffer OPTIONAL
 , BYVAL NewByteCount AS DWORD _                        ' __in  DWORD NewByteCount
 , BYREF NewBuffer AS ANY _                             ' __out LPVOID * NewBuffer
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetApiBufferSize LIB "NetApi32.dll" _
    ALIAS "NetApiBufferSize" ( _
    pBuffer   AS ANY, _  ' LPVOID
    ByteCount AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetApiBufferSize IMPORT "NETAPI32.DLL" ALIAS "NetApiBufferSize" ( _
   BYVAL Buffer AS DWORD _                              ' __in  LPVOID Buffer
 , BYREF ByteCount AS DWORD _                           ' __out LPDWORD ByteCount
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'//
'// The following private function will go away eventually.
'// Call NetApiBufferAllocate instead.
'//
'NET_API_STATUS NET_API_FUNCTION
'NetapipBufferAllocate (                 // Internal Function
'    IN DWORD ByteCount,
'    OUT LPVOID * Buffer
'    );
