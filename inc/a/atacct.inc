' ########################################################################################
' Microsoft Windows
' File: atacct.inc
' Contents: Prototypes for the AT Service Account API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ATACCT_INC = 1

DECLARE FUNCTION GetNetScheduleAccountInformation IMPORT "Mstask.dll" ALIAS "GetNetScheduleAccountInformation" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in LPCWSTR pwszServerName
 , BYVAL ccAccount AS DWORD _                           ' __in DWORD ccAccount
 , BYREF wszAccount AS WSTRINGZ _                       ' __out WCHAR wszAccount[]
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SetNetScheduleAccountInformation IMPORT "Mstask.dll" ALIAS "SetNetScheduleAccountInformation" ( _
   BYREF pwszServerName AS WSTRINGZ _                   ' __in LPCWSTR pwszServerName
 , BYREF pwszAccount AS WSTRINGZ _                      ' __in LPCWSTR pwszAccount
 , BYREF pwszPassword AS WSTRINGZ _                     ' __in LPCWSTR pwszPassword
 ) AS LONG                                              ' HRESULT
