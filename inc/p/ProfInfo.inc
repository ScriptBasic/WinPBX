' ########################################################################################
' Microsoft Windows
' File: ProfInfo.inc
' Contents: Header file for profile info structure
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROFINFO_INC = 1

' // Size = 32 bytes
TYPE PROFILEINFOA DWORD
   dwSize        AS DWORD        ' DWORD
   dwFlags       AS DWORD        ' DWORD
   lpUserName    AS ASCIIZ PTR   ' LPSTR
   lpProfilePath AS ASCIIZ PTR   ' LPSTR
   lpDefaultPath AS ASCIIZ PTR   ' LPSTR
   lpServerName  AS ASCIIZ PTR   ' LPSTR
   lpPolicyPath  AS ASCIIZ PTR   ' LPSTR
   hProfile      AS DWORD        ' HANDLE
END TYPE

' // Size = 32 bytes
TYPE PROFILEINFOW DWORD
   dwSize        AS DWORD          ' DWORD
   dwFlags       AS DWORD          ' DWORD
   lpUserName    AS WSTRINGZ PTR   ' LPWSTR
   lpProfilePath AS WSTRINGZ PTR   ' LPWSTR
   lpDefaultPath AS WSTRINGZ PTR   ' LPWSTR
   lpServerName  AS WSTRINGZ PTR   ' LPWSTR
   lpPolicyPath  AS WSTRINGZ PTR   ' LPWSTR
   hProfile      AS DWORD          ' HANDLE
END TYPE

#IF %DEF(%UNICODE)
   MACRO PROFILEINFO = PROFILEINFOW
#ELSE
   MACRO PROFILEINFO = PROFILEINFOA
#ENDIF
