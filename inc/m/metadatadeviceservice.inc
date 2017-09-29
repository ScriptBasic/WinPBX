' ########################################################################################
' Microsoft Windows
' File: MetadataDeviceService.inc
' Contents:Definitions of the Device Metadata Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%METADATADEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"

'/*****************************************************************************/
'/*  Device Metadata Service Info                                             */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(SERVICE_DeviceMetadata,
'    0x332ffe6a, 0xaf65, 0x41e1, 0xa0, 0xaf, 0xd3, 0xe2, 0x62, 0x7b, 0xdf, 0x54);
$SERVICE_DeviceMetadata = GUID$("{332ffe6a-af65-41e1-a0af-d3e2627bdf54}")

$$NAME_DeviceMetadataSvc             = "Metadata"$$
'#define TYPE_DeviceMetadataSvc              DEVSVCTYPE_DEFAULT
%TYPE_DeviceMetadataSvc              = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Device Metadata Service Object Formats                                   */
'/*****************************************************************************/

'/*  FORMAT_DeviceMetadataCAB
' *
' *  CAB object format
' */

'DEFINE_DEVSVCGUID(FORMAT_DeviceMetadataCAB,
'    0xe1809599, 0x4303, 0x4e3b, 0x92, 0x44, 0x99, 0xc6, 0x2c, 0x25, 0x45, 0x51);
$FORMAT_DeviceMetadataCAB = GUID$("{e1809599-4303-4e3b-9244-99c62c254551}")

$$NAME_DeviceMetadataCAB             = "DeviceMetadataCAB"$$


'/*****************************************************************************/
'/*  Device Metadata Service Object Property Keys                             */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(NAMESPACE_DeviceMetadataObj,
'    0x68bb7eeb, 0x9eef, 0x45bd, 0x8d, 0xe6, 0x3b, 0x92, 0xa5, 0x7c, 0xae, 0x1e);
$NAMESPACE_DeviceMetadataObj = GUID$("{68bb7eeb-9eef-45bd-8de6-3b92a57cae1e}")

'/*  PKEY_DeviceMetadataObj_ContentID
' *
' *  Contains the GUID that uniquely identifies the object cab contents.
' *
' *  Type: UInt128
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_DeviceMetadataObj_ContentID,
'    0x68bb7eeb, 0x9eef, 0x45bd, 0x8d, 0xe6, 0x3b, 0x92, 0xa5, 0x7c, 0xae, 0x1e,
'    3);
MACRO PKEY_DeviceMetadataObj_ContentID = GUID$("{68bb7eeb-9eef-45bd-8de6-3b92a57cae1e}") & MKDWD$(3)

$$NAME_DeviceMetadataObj_ContentID   = "ContentID"$$


'/*  PKEY_DeviceMetadataObj_DefaultCAB
' *
' *  Indicates whether this object is the default cab.  Each service shall have
' *  only one object marked as default.
' *
' *  Type: UInt8 Boolean
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_DeviceMetadataObj_DefaultCAB,
'    0x68bb7eeb, 0x9eef, 0x45bd, 0x8d, 0xe6, 0x3b, 0x92, 0xa5, 0x7c, 0xae, 0x1e,
'    4);
MACRO PKEY_DeviceMetadataObj_DefaultCAB = GUID$("{68bb7eeb-9eef-45bd-8de6-3b92a57cae1e}") & MKDWD$(4)

$$NAME_DeviceMetadataObj_DefaultCAB  = "DefaultCAB"$$

%ENUM_DeviceMetadataObj_DefaultCABFalse = 0
%ENUM_DeviceMetadataObj_DefaultCABTrue  = 1
