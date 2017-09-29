' ########################################################################################
' Microsoft Windows
' File: DeviceServices.inc
' Contents: Definitions for the core Device Services platform
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DEVICESERVICES_INC = 1

#INCLUDE ONCE "BridgeDeviceService.inc"

'/*****************************************************************************/
'/*  Service Info                                                             */
'/*****************************************************************************/

'/*  Service Info Version
' */

%DEVSVC_SERVICEINFO_VERSION      = &H00000064???

'/*  Service Flags
' */

%DEVSVCTYPE_DEFAULT              = &H00000000???
%DEVSVCTYPE_ABSTRACT             = &H00000001???

'/*****************************************************************************/
'/*  Common Service Properties                                                */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(NAMESPACE_Services,
'    0x14fa7268, 0x0b6c, 0x4214, 0x94, 0x87, 0x43, 0x5b, 0x48, 0x0a, 0x8c, 0x4f);
$NAMESPACE_Services = GUID$("{14fa7268-0b6c-4214-9487-435b480a8c4f}")


'/*  PKEY_Services_ServiceDisplayName
' *
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_Services_ServiceDisplayName,
'    0x14fa7268, 0x0b6c, 0x4214, 0x94, 0x87, 0x43, 0x5b, 0x48, 0x0a, 0x8c, 0x4f,
'    2);
MACRO PKEY_Services_ServiceDisplayName = GUID$("{14fa7268-0b6c-4214-9487-435b480a8c4f}") & MKDWD$(2)

$$NAME_Services_ServiceDisplayName = "ServiceDisplayName"$$


'/*  PKEY_Services_ServiceIcon
' *
' *  Type: AUInt8
' *  Form: ByteArray
' */

'DEFINE_DEVSVCPROPKEY(PKEY_Services_ServiceIcon,
'    0x14fa7268, 0x0b6c, 0x4214, 0x94, 0x87, 0x43, 0x5b, 0x48, 0x0a, 0x8c, 0x4f,
'    3);
MACRO PKEY_Services_ServiceIcon = GUID$("{14fa7268-0b6c-4214-9487-435b480a8c4f}") & MKDWD$(3)

$$NAME_Services_ServiceIcon = "ServiceIcon"$$


'/*  PKEY_Services_ServiceLocale
' *
' *  Contains the RFC4646 compliant language string for data in this service
' *
' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_Services_ServiceLocale,
'    0x14fa7268, 0x0b6c, 0x4214, 0x94, 0x87, 0x43, 0x5b, 0x48, 0x0a, 0x8c, 0x4f,
'    4);
MACRO PKEY_Services_ServiceLocale = GUID$("{14fa7268-0b6c-4214-9487-435b480a8c4f}") & MKDWD$(4)

$$NAME_Services_ServiceLocale = "ServiceLocale"$$
