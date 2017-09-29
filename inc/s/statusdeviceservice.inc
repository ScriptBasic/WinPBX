' ########################################################################################
' Microsoft Windows
' File: StatusDeviceService.inc
' Contents: Contains definitions of the Status Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STATUSDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"

'/*****************************************************************************/
'/*  Status Service Info                                                      */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(SERVICE_Status,
'    0x0B9F1048, 0xB94B, 0xDC9A, 0x4e, 0xd7, 0xfe, 0x4f, 0xed, 0x3a, 0x0d, 0xeb);
$SERVICE_Status = GUID$("{0B9F1048-B94B-DC9A-4ed7-fe4fed3a0deb}")

$$NAME_StatusSvc                     = "Status"$$
%TYPE_StatusSvc                      = %DEVSVCTYPE_DEFAULT

'/*****************************************************************************/
'/*  Status Service Property Keys                                             */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(NAMESPACE_StatusSvc,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13);
$NAMESPACE_StatusSvc = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}")


'/*  PKEY_StatusSvc_SignalStrength
' *
' *  Signal strength in "bars" from 0 (no signal) to 4 (excellent signal)
' *
' *  Type: UInt8
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_SignalStrength,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    2);
MACRO PKEY_StatusSvc_SignalStrength = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(2)

$$NAME_StatusSvc_SignalStrength      = "SignalStrength"$$

%RANGEMIN_StatusSvc_SignalStrength  = 0
%RANGEMAX_StatusSvc_SignalStrength  = 4
%RANGESTEP_StatusSvc_SignalStrength = 1

'/*  PKEY_StatusSvc_TextMessages
' *
' *  Number of unread text messages (255 max)
' *
' *  Type: UInt8
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_TextMessages,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    3);
MACRO PKEY_StatusSvc_TextMessages = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(3)

$$NAME_StatusSvc_TextMessages        = "TextMessages"$$
%RANGEMAX_StatusSvc_TextMessages     = 255

'/*  PKEY_StatusSvc_NewPictures
' *
' *  Number of "new" pictures on the device (65535 max)
' *
' *  Type: UInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_NewPictures,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    4);
MACRO PKEY_StatusSvc_NewPictures = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(4)

$$NAME_StatusSvc_NewPictures         = "NewPictures"$$
%RANGEMAX_StatusSvc_NewPictures      = 65535

'/*  PKEY_StatusSvc_MissedCalls
' *
' *  Number of missed calls on the device (255 max)
' *
' *  Type: UInt8
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_MissedCalls,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    5);
MACRO PKEY_StatusSvc_MissedCalls = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(5)

$$NAME_StatusSvc_MissedCalls         = "MissedCalls"$$
%RANGEMAX_StatusSvc_MissedCalls      = 255

'/*  PKEY_StatusSvc_VoiceMail
' *
' *  Number of "available" voice mail messages (255 max)
' *
' *  Type: UInt8
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_VoiceMail,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    6);
MACRO PKEY_StatusSvc_VoiceMail = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(6)

$$NAME_StatusSvc_VoiceMail           = "VoiceMail"$$
%RANGEMAX_StatusSvc_VoiceMail        = 255

'/*  PKEY_StatusSvc_NetworkName
' *
' *  Network provider network name
' *
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_NetworkName,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    7);
MACRO PKEY_StatusSvc_NetworkName = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(7)

$$NAME_StatusSvc_NetworkName         = "NetworkName"$$


'/*  PKEY_StatusSvc_NetworkType
' *
' *  Network "type" (e.g. GPRS, EDGE, UMTS, 1xRTT, EVDO, or operator branded)
' *
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_NetworkType,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    8);
MACRO PKEY_StatusSvc_NetworkType = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(8)

$$NAME_StatusSvc_NetworkType         = "NetworkType"$$


'/*  PKEY_StatusSvc_Roaming
' *
' *  Current network roaming state
' *
' *  Type: UInt8
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_Roaming,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    9);
MACRO PKEY_StatusSvc_Roaming = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(9)

$$NAME_StatusSvc_Roaming             = "Roaming"$$

%ENUM_StatusSvc_RoamingInactive = &H00
%ENUM_StatusSvc_RoamingActive   = &H01
%ENUM_StatusSvc_RoamingUnknown  = &H02


'/*  PKEY_StatusSvc_BatteryLife
' *
' *  Remaining battery life on the device as a percentage between 100 and 0.
' *
' *  Type: UInt8
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_BatteryLife,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    10);
MACRO PKEY_StatusSvc_BatteryLife = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(10)

$$NAME_StatusSvc_BatteryLife         = "BatteryLife"$$

%RANGEMIN_StatusSvc_BatteryLife  = 0
%RANGEMAX_StatusSvc_BatteryLife  = 100
%RANGESTEP_StatusSvc_BatteryLife = 1


'/*  PKEY_StatusSvc_ChargingState
' *
' *  Current charging state of the device
' *
' *  Type: UInt8
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_ChargingState,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    11);
MACRO PKEY_StatusSvc_ChargingState = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(11)

$$NAME_StatusSvc_ChargingState       = "ChargingState"$$

%ENUM_StatusSvc_ChargingInactive = &H00
%ENUM_StatusSvc_ChargingActive   = &H01
%ENUM_StatusSvc_ChargingUnknown  = &H02


'/*  PKEY_StatusSvc_StorageCapacity
' *
' *  Total storage capacity on the device (across all storages)
' *
' *  Type: UInt64
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_StorageCapacity,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    12);
MACRO PKEY_StatusSvc_StorageCapacity = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(12)

$$NAME_StatusSvc_StorageCapacity     = "StorageCapacity"$$


'/*  PKEY_StatusSvc_StorageFreeSpace
' *
' *  Total free storage capacity on the device (across all storages)
' *
' *  Type: UInt64
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_StatusSvc_StorageFreeSpace,
'    0x49cd1f76, 0x5626, 0x4b17, 0xa4, 0xe8, 0x18, 0xb4, 0xaa, 0x1a, 0x22, 0x13,
'    13);
MACRO PKEY_StatusSvc_StorageFreeSpace = GUID$("{49cd1f76-5626-4b17-a4e8-18b4aa1a2213}") & MKDWD$(13)

$$NAME_StatusSvc_StorageFreeSpace    = "StorageFreeSpace"$$
