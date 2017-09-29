' ########################################################################################
' Microsoft Windows
' File: WMPDevices.inc
' Contents: Structures and constants needed by a device implementer to support
' Windows Media Player device extension
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WMPDEVICES_INC = 1

#INCLUDE ONCE "windows.inc"

'#pragma once

'// This file defines Windows Media Player support for WMDM
'// service providers.
'//

'//
'// defines used to encode/decode WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC::dwFlags
'//
%WMP_MDRT_FLAGS_UNREPORTED_DELETED_ITEMS = &H00000001???  ' // bit 0
%WMP_MDRT_FLAGS_UNREPORTED_ADDED_ITEMS   = &H00000002???  ' // bit 1
'// all other bits are reserved for future use and should be returned as 0 (zero) for now

'#pragma pack(push, Old, 1)

%IOCTL_WMP_METADATA_ROUND_TRIP = &H31504d57???   ' // 'W' 'M' 'P' '1'

'// Windows Media Player sends and retrieves these structures using code similar to this:
'//   IWMDMDevice3 *pDevice3;
'//   WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE PC2Device = {0,0};
'//   DWORD dwSizeDevice2PC = sizeof(WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC) + 0x50000;
'//   WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC *pDevice2PC = (WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC *) new BYTE[dwSizeDevice2PC];
'//   HRESULT hr = pDevice3->DeviceIoControl(IOCTL_WMP_METADATA_ROUND_TRIP,
'//                                  &PC2Device, sizeof(WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE),
'//                                  pDevice2PC, &dwSizeDevice2PC);

'//
'// Structure sent by Windows Media Player to WMDM SP
'//

'typedef struct _WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE
'{
'    DWORD   dwChangesSinceTransactionID;    // 0 on first call ever to device (return all changes),
'                                            //   value of WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC::dwCurrentTransactionID
'                                            //   from last sync session
'    DWORD   dwResultSetStartingIndex;       // 0 based starting index into result set that should
'                                            //   be returned, always zero on first call

'    // WMDM SP should check the passed buffer size is at least sizeof(WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE).
'    // Future versions of WMP may pass larger structures which enable new functionality but these
'    //   first 2 DWORDs would always remain the same.
'} WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE;

' // Size = 8 bytes
TYPE WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE DWORD
   dwChangesSinceTransactionID AS DWORD
   dwResultSetStartingIndex    AS DWORD
END TYPE

'//
'// Response structure sent by WMDM SP to Windows Media Player
'//

'typedef struct _WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC
'{
'    DWORD   dwCurrentTransactionID;         // Device's current transaction ID (WMP will pass this
'                                            //   value as WMP_WMDM_METADATA_ROUND_TRIP_PC2DEVICE::dwChangesSinceTransactionID
'                                            //   during the next sync session)
'    DWORD   dwReturnedObjectCount;          // how many object pathnames are in wsObjectPathnameList
'    DWORD   dwUnretrievedObjectCount;       // how many objects have changes that were not returned in
'                                            //   this response (non-zero value implies at least one more
'                                            //   request must be made by WMP)
'    DWORD   dwDeletedObjectStartingOffset;  // wsObjectPathnameList[dwDeletedObjectStartingOffset] is
'                                            //   first character of first deleted object pathname
'                                            // pass 0 if wsObjectPathnameList only contains deleted
'                                            //   objects (contains no updated or added objects)
'                                            // pass the character offset of the last nul in
'                                            //   wsObjectPathnameList if the list only contains updated
'                                            //   or added objects (no deleted objects)
'    DWORD   dwFlags;                        // bit 0 (0==false, 1==true) indicating some items were
'                                            //   deleted before the first PUOID being reported
'                                            //   (normally means device was reformatted)
'                                            // bit 1 (0==false, 1==true) indicating some additional items
'                                            //   were added that were not returned in the list of PUOIDs
'                                            // bits 2-31 - reserved for future use
'                                            //   (must be returned as 0 for now)
'    WCHAR   wsObjectPathnameList[1];        // list of null terminated unicode pathname strings, one after
'                                            //   another, terminated with an extra null
'                                            // All the objects that have been added or have their
'                                            //   playcount, user rating or BuyNow properties changed come
'                                            //   first.  Then all the objects that have been deleted come
'                                            //   next.  This second set of objects starts at
'                                            //   dwDeletedObjectStartingOffset.
'                                            // The WMDM SP should return as many object pathnames as will
'                                            //   fit in the buffer passed to IMDSPDevice3::DeviceIoControl()
'                                            //   whose size is passed in *pnOutBufferSize.  If there isn't
'                                            //   enough room return what you can and set the
'                                            //   dwUnretrievedObjectCount to a non-zero value appropriately.
'} WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC;

' // Size = 22 bytes
TYPE WMP_WMDM_METADATA_ROUND_TRIP_DEVICE2PC BYTE
   dwCurrentTransactionID        AS DWORD
   dwReturnedObjectCount         AS DWORD
   dwUnretrievedObjectCount      AS DWORD
   dwDeletedObjectStartingOffset AS DWORD
   dwFlags                       AS DWORD
   wsObjectPathnameList          AS WSTRINGZ * 1
END TYPE

%IOCTL_WMP_DEVICE_CAN_SYNC = &H32504d57???   ' // 'W' 'M' 'P' '2'
'//
'// This IOCTL will pass no parameters and expects a DWORD return value (1 for able to sync,
'// 0 for not able to sync)
'//

'#pragma pack(pop, Old)

'//
'// Macros for notifying WMP that a device has arrived or been removed
'//
'__inline BOOL WMPNotifyDeviceArrival()
'{
'    return( ::PostMessage( HWND_BROADCAST, ::RegisterWindowMessageA( "WMPlayer_PluginAddRemove" ), 2, 0 ) );
'}

FUNCTION WMPNotifyDeviceArrival () AS LONG
   FUNCTION = PostMessageA(%HWND_BROADCAST, RegisterWindowMessageA("WMPlayer_PluginAddRemove"), 2, 0)
END FUNCTION

'__inline BOOL WMPNotifyDeviceRemoval()
'{
'    return( ::PostMessage( HWND_BROADCAST, ::RegisterWindowMessageA( "WMPlayer_PluginAddRemove" ), 3, 0 ) );
'}

FUNCTION WMPNotifyDeviceRemoval () AS LONG
   FUNCTION = PostMessageA(%HWND_BROADCAST, RegisterWindowMessageA("WMPlayer_PluginAddRemove"), 3, 0)
END FUNCTION
