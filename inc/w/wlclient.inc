' ########################################################################################
' Microsoft Windows
' File: wlclient.inc
' Contents: Header file for wireless windows APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WLCLIENT_INC = 1

#INCLUDE ONCE "windot11.inc"

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 28 bytes
TYPE DOT11_ADAPTER DWORD
   gAdapterId         AS GUID           ' GUID
   pszDescription     AS WSTRINGZ PTR   ' LPWSTR
   Dot11CurrentOpMode AS DOT11_CURRENT_OPERATION_MODE
END TYPE

' // Size = 8 bytes
TYPE DOT11_BSS_LIST DWORD
   uNumOfBytes AS DWORD      ' ULONG
   pucBuffer   AS BYTE PTR   ' PUCHAR
END TYPE

' // Size = 20 bytes
TYPE DOT11_PORT_STATE DWORD
   PeerMacAddress  AS DOT11_MAC_ADDRESS   ' DOT11_MAC_ADDRESS // Unicast mac address of the peer
   uSessionId      AS DWORD               ' ULONG
   bPortControlled AS LONG                ' BOOL // TRUE, if the port is controlled by Security Module
   bPortAuthorized AS LONG                ' BOOL // TRUE, if the port is authorized for data packets
END TYPE

'#include <packon.h>
' // Size = 20 bytes
TYPE DOT11_SECURITY_PACKET_HEADER BYTE
   PeerMac     AS DOT11_MAC_ADDRESS
   usEtherType AS WORD   ' USHORT
   Data(0)     AS BYTE   ' UCHAR
END TYPE
'#include <packoff.h>

'#endif  // (NTDDI_VERSION > NTDDI_VISTA)
