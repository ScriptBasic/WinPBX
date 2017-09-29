' ########################################################################################
' Microsoft Windows
' File: SpOrder.inc
' Contents: This header prototypes the 32-Bit Windows functions that are used to change
' the order or WinSock2 transport service providers and name space providers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SPORDER_INC = 1

DECLARE FUNCTION WSCWriteProviderOrder IMPORT "Ws2_32.dll" ALIAS "WSCWriteProviderOrder" ( _
   BYREF lpwdCatalogEntryId AS DWORD _                  ' __in LPDWORD lpwdCatalogEntryId
 , BYVAL dwNumberOfEntries AS DWORD _                   ' __in DWORD dwNumberOfEntries
 ) AS LONG                                              ' int

'#ifdef _WIN64
'int
'WSPAPI
'WSCWriteProviderOrder32 (
'    IN LPDWORD lpwdCatalogEntryId,
'    IN DWORD dwNumberOfEntries
'    );
'#endif

DECLARE FUNCTION WSCWriteNameSpaceOrder IMPORT "Ws2_32.dll" ALIAS "WSCWriteNameSpaceOrder" ( _
   BYREF lpProviderId AS GUID _                         ' __in LPGUID lpProviderId
 , BYVAL dwNumberOfEntries AS DWORD _                   ' __in DWORD dwNumberOfEntries
 ) AS LONG                                              ' int

'#ifdef _WIN64
'int
'WSPAPI
'WSCWriteNameSpaceOrder32 (
'    IN LPGUID lpProviderId,
'    IN DWORD dwNumberOfEntries
'    );
'#endif
