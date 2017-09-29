' ########################################################################################
' Microsoft Windows
' File: FunctionDiscoveryKeys.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FUNCTIONDISCOVERYKEYS_INC = 1

'#pragma once

'#ifndef DEFINE_API_PKEY
'#include <propkey.h>
'#endif

#INCLUDE ONCE "propkey.inc"

#INCLUDE ONCE "FunctionDiscoveryKeys_devpkey.inc"

'/* 08c0c253-a154-4746-9005-82de5317148b */
'DEFINE_PROPERTYKEY(PKEY_FunctionInstance, 0x08c0c253, 0xa154, 0x4746, 0x90, 0x05, 0x82, 0xde, 0x53, 0x17, 0x14, 0x8b, 0x00000001);  // VT_UNKNOWN
MACRO PKEY_FunctionInstance = GUID$("{08c0c253-a154-4746-9005-82de5317148b}") & MKDWD$(&H00000001???)

'// FMTID_FD = {904b03a2-471d-423c-a584-f3483238a146}
'DEFINE_GUID(FMTID_FD, 0x904b03a2, 0x471d, 0x423c, 0xa5, 0x84, 0xf3, 0x48, 0x32, 0x38, 0xa1, 0x46);
$FMTID_FD = GUID$("{904b03a2-471d-423c-a584-f3483238a146}")

'DEFINE_API_PKEY(PKEY_FD_Visibility, VisibilityFlags, 0x904b03a2, 0x471d, 0x423c, 0xa5, 0x84, 0xf3, 0x48, 0x32, 0x38, 0xa1, 0x46, 0x00000001); //    VT_UINT

%FD_Visibility_Default = 0
%FD_Visibility_Hidden  = 1

'// FMTID_Device = {78C34FC8-104A-4aca-9EA4-524D52996E57}
'DEFINE_GUID(FMTID_Device, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57);
$FMTID_Device = GUID$("{78C34FC8-104A-4aca-9EA4-524D52996E57}")

'DEFINE_API_PKEY(PKEY_Device_NotPresent,     DeviceNotPresent   , 0x904b03a2, 0x471d, 0x423c, 0xa5, 0x84, 0xf3, 0x48, 0x32, 0x38, 0xa1, 0x46, 0x00000002); //    VT_UINT
MACRO PKEY_Device_NotPresent = GUID$("{904b03a2-471d-423c-a584-f3483238a146}") & MKDWD$(&H00000002???)   '  // VT_UINT
'DEFINE_API_PKEY(PKEY_Device_QueueSize,      DeviceQueueSize    , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000024); //    VT_UI4
MACRO PKEY_Device_QueueSize = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000024???)   '  // VT_UI4
'DEFINE_API_PKEY(PKEY_Device_Status,         DeviceStatus       , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000025); //    VT_LPWSTR
MACRO PKEY_Device_Status = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000025???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_Device_Comment,        DeviceComment      , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000026); //    VT_LPWSTR
MACRO PKEY_Device_Comment = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000026???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_Device_Model,          DeviceModel        , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000027); //    VT_LPWSTR
MACRO PKEY_Device_Model = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000027???)   '  // VT_LPWSTR

'// FMTID_Device = {53808008-07BB-4661-BC3C-B5953E708560}
'DEFINE_GUID(FMTID_DeviceInterface, 0x53808008, 0x07BB, 0x4661, 0xBC, 0x3C, 0xB5, 0x95, 0x3E, 0x70, 0x85, 0x60);
$FMTID_DeviceInterface = GUID$("{53808008-07BB-4661-BC3C-B5953E708560}")

'DEFINE_API_PKEY(PKEY_DeviceInterface_DevicePath, DevicePath    , 0x53808008, 0x07BB, 0x4661, 0xBC, 0x3C, 0xB5, 0x95, 0x3E, 0x70, 0x85, 0x60, 0x00000001); //    VT_LPWSTR
MACRO PKEY_DeviceInterface_DevicePath = GUID$("{53808008-07BB-4661-BC3C-B5953E708560}") & MKDWD$(&H00000001???)   '  // VT_LPWSTR

'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Address,                  0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000033);  // VT_LPWSTR or VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_Address = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000033???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_DiscoveryMethod,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000034);  // VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_DiscoveryMethod = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000034???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsEncrypted,              0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000035);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsEncrypted = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000035???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsAuthenticated,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000036);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsAuthenticated = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000036???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsConnected,              0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000037);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsConnected = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000037???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsPaired,                 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000038);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsPaired = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000038???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Icon,                     0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000039);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_Icon = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000039???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Version,                  0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000041);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_Version = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000041???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Last_Seen,                0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000042);  // VT_FIELTIME
MACRO PKEY_DeviceDisplay_Last_Seen = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000042???)   '  // VT_FIELTIME
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Last_Connected,           0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000043);  // VT_FILETIME
MACRO PKEY_DeviceDisplay_Last_Connected = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000043???)   '  // VT_FIELTIME
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsShowInDisconnectedState, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000044);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsShowInDisconnectedState = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000044???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsLocalMachine,           0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000046);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsLocalMachine = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000046???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_MetadataPath,             0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000047);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_MetadataPath = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000047???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsMetadataSearchInProgress, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000048);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsMetadataSearchInProgress = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000048???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_MetadataChecksum,         0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000049);  // VT_UI1 | VT_VECTOR
MACRO PKEY_DeviceDisplay_MetadataChecksum = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000049???)   '  // VT_UI1 | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsNotInterestingForDisplay, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000004A);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsNotInterestingForDisplay = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000004A???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_LaunchDeviceStageOnDeviceConnect, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000004C);  // VT_BOOL
MACRO PKEY_DeviceDisplay_LaunchDeviceStageOnDeviceConnect = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000004C???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_LaunchDeviceStageFromExplorer, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000004D);  // VT_BOOL
MACRO PKEY_DeviceDisplay_LaunchDeviceStageFromExplorer = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000004D???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_BaselineExperienceId,     0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000004E);  // VT_CLSID
MACRO PKEY_DeviceDisplay_BaselineExperienceId = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000004E???)   '  // VT_CLSID
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsDeviceUniquelyIdentifiable, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000004F);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsDeviceUniquelyIdentifiable = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000004F???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_AssociationArray,         0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000050);  // VT_LPWSTR  | VT_VECTOR
MACRO PKEY_DeviceDisplay_AssociationArray = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000050???)   '  // VT_LPWSTR  | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_DeviceDescription1,       0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000051);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_DeviceDescription1 = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000051???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_DeviceDescription2,       0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000052);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_DeviceDescription2 = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000052???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsNotWorkingProperly,     0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000053);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsNotWorkingProperly = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000053???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsSharedDevice,           0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000054);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsSharedDevice = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000054???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsNetworkDevice,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000055);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsNetworkDevice = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000055???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_IsDefaultDevice,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000056);  // VT_BOOL
MACRO PKEY_DeviceDisplay_IsDefaultDevice = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000056???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_MetadataCabinet,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000057);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_MetadataCabinet = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000057???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_RequiresPairingElevation, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000058);  // VT_BOOL
MACRO PKEY_DeviceDisplay_RequiresPairingElevation = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000058???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_ExperienceId,             0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000059);  // VT_CLSID
MACRO PKEY_DeviceDisplay_ExperienceId = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000059???)   '  // VT_CLSID
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Category,                 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005A);  // VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_Category = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005A???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Category_Desc_Singular,   0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005B);  // VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_Category_Desc_Singular = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005B???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Category_Desc_Plural,     0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005C);  // VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_Category_Desc_Plural = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005C???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Category_Icon,            0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005D);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_Category_Icon = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005D???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_CategoryGroup_Desc,       0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005E);  // VT_LPWSTR | VT_VECTOR
MACRO PKEY_DeviceDisplay_CategoryGroup_Desc = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005E???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_CategoryGroup_Icon,       0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x0000005F);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_CategoryGroup_Icon = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H0000005F???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_PrimaryCategory,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000061);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_PrimaryCategory = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000061???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_UnpairUninstall,          0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000062);  // VT_BOOL
MACRO PKEY_DeviceDisplay_UnpairUninstall = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000062???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_RequiresUninstallElevation, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000063);  // VT_BOOL
MACRO PKEY_DeviceDisplay_RequiresUninstallElevation = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000063???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_DeviceFunctionSubRank,    0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000064);  // VT_UI4
MACRO PKEY_DeviceDisplay_DeviceFunctionSubRank = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000064???)   '  // VT_UI4
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_AlwaysShowDeviceAsConnected, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000065);  // VT_BOOL
MACRO PKEY_DeviceDisplay_AlwaysShowDeviceAsConnected = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000065???)   '  // VT_BOOL

'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_FriendlyName,             0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003000);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_FriendlyName = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003000???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_Manufacturer,             0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002000);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_Manufacturer = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002000???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_ModelName,                0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002002);  // VT_LPWSTR (localizable)
MACRO PKEY_DeviceDisplay_ModelName = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002002???)   '  // VT_LPWSTR (localizable)
'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_ModelNumber,              0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002003);  // VT_LPWSTR
MACRO PKEY_DeviceDisplay_ModelNumber = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002003???)   '  // VT_LPWSTR

'DEFINE_PROPERTYKEY(PKEY_DeviceDisplay_InstallInProgress,        0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 9);     // DEVPROP_TYPE_BOOLEAN
MACRO PKEY_DeviceDisplay_InstallInProgress = GUID$("{83da6326-97a6-4088-9453-a1923f573b29}") & MKDWD$(9)   '  // DEVPROP_TYPE_BOOLEAN

'// FMTID_Pairing = {8807CAE6-7DB6-4f10-8EE4-435EAA1392BC}
'DEFINE_GUID(FMTID_Pairing, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc);
$FMTID_Pairing = GUID$("{8807CAE6-7DB6-4f10-8EE4-435EAA1392BC}")
'DEFINE_PROPERTYKEY(PKEY_Pairing_ListItemText, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc, 0x0000001);        // VT_LPWSTR
MACRO PKEY_Pairing_ListItemText = GUID$("{8807cae6-7db6-4f10-8ee4-435eaa1392bc}") & MKDWD$(&H0000001???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_Pairing_ListItemDescription, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc, 0x0000002); // VT_LPWSTR
MACRO PKEY_Pairing_ListItemDescription = GUID$("{8807cae6-7db6-4f10-8ee4-435eaa1392bc}") & MKDWD$(&H0000002???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_Pairing_ListItemIcon, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc, 0x0000003);        // VT_LPWSTR
MACRO PKEY_Pairing_ListItemIcon = GUID$("{8807cae6-7db6-4f10-8ee4-435eaa1392bc}") & MKDWD$(&H0000003???)   '  // VT_LPWSTR
'DEFINE_PROPERTYKEY(PKEY_Pairing_ListItemDefault, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc, 0x0000004);     // VT_BOOL
MACRO PKEY_Pairing_ListItemDefault = GUID$("{8807cae6-7db6-4f10-8ee4-435eaa1392bc}") & MKDWD$(&H0000004???)   '  // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_Pairing_IsWifOnlyDevice, 0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc, 0x0000010);    // VT_BOOL
MACRO PKEY_Pairing_IsWifiOnlyDevice = GUID$("{8807cae6-7db6-4f10-8ee4-435eaa1392bc}") & MKDWD$(&H0000010???)   '  // VT_BOOL

'// DiscoveryMethod values
$$DEVICEDISPLAY_DISCOVERYMETHOD_BLUETOOTH         = "Bluetooth"$$
$$DEVICEDISPLAY_DISCOVERYMETHOD_NETBIOS           = "NetBIOS"$$
$$DEVICEDISPLAY_DISCOVERYMETHOD_PNP               = "PnP"$$
$$DEVICEDISPLAY_DISCOVERYMETHOD_UPNP              = "UPnP"$$
$$DEVICEDISPLAY_DISCOVERYMETHOD_WSD               = "WSD"$$
$$DEVICEDISPLAY_DISCOVERYMETHOD_WUSB              = "WUSB"$$


'//  Name:     System.Device.BIOSVersion -- PKEY_Device_BIOSVersion
'//  Type:     String -- VT_LPWSTR  (For variants: VT_BSTR)  Legacy code may treat this as VT_BSTR.
'//  FormatID: EAEE7F1D-6A33-44D1-9441-5F46DEF23198, 9
'DEFINE_PROPERTYKEY(PKEY_Device_BIOSVersion, 0xEAEE7F1D, 0x6A33, 0x44D1, 0x94, 0x41, 0x5F, 0x46, 0xDE, 0xF2, 0x31, 0x98, 9);
MACRO PKEY_Device_BIOSVersion = GUID$("{EAEE7F1D-6A33-44D1-9441-5F46DEF23198}") & MKDWD$(9)

'DEFINE_API_PKEY(PKEY_Write_Time,            WriteTime          , 0xf53b7e1c, 0x77e0, 0x4450, 0x8c, 0x5f, 0xa7, 0x6c, 0xc7, 0xfd, 0xe0, 0x58, 0x00000100); //    VT_FILETIME
MACRO PKEY_Write_Time = GUID$("{f53b7e1c-77e0-4450-8c5f-a76cc7fde058}") & MKDWD$(&H00000100???)   '  // VT_FILETIME
'DEFINE_API_PKEY(PKEY_Create_Time,           CreateTime         , 0xf53b7e1c, 0x77e0, 0x4450, 0x8c, 0x5f, 0xa7, 0x6c, 0xc7, 0xfd, 0xe0, 0x58, 0x00000101); //    VT_FILETIME
MACRO PKEY_Create_Time = GUID$("{f53b7e1c-77e0-4450-8c5f-a76cc7fde058}") & MKDWD$(&H00000101???)   '  // VT_FILETIME

'#ifdef FD_XP
'DEFINE_API_PKEY(PKEY_Device_InstanceId, DeviceInstanceId   , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000100); //    VT_LPWSTR
'MACRO PKEY_Device_InstanceId = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000100???)   '  // VT_LPWSTR
' Already defined in FunctionDiscoverykeys_devpkey.inc
'#endif
'DEFINE_API_PKEY(PKEY_Device_Interface,  DeviceInterface    , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00000101); //    VT_CLSID
MACRO PKEY_Device_Interface = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00000101???)   '  // VT_CLSID

'DEFINE_API_PKEY(PKEY_ExposedIIDs,           ExposedIIDs       , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00003002); //  VT_VECTOR | VT_CLSID
MACRO PKEY_ExposedIIDs = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00003002???)   '  // VT_VECTOR | VT_CLSID
'DEFINE_API_PKEY(PKEY_ExposedCLSIDs,         ExposedCLSIDs     , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00003003); //  VT_VECTOR | VT_CLSID
MACRO PKEY_ExposedCLSIDs = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00003003???)   '  // VT_VECTOR | VT_CLSID
'DEFINE_API_PKEY(PKEY_InstanceValidatorClsid,InstanceValidator , 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x00003004); // VT_CLSID
MACRO PKEY_InstanceValidatorClsid = GUID$("{78c34fc8-104a-4aca-9ea4-524d52996e57}") & MKDWD$(&H00003004???)   '  // VT_CLSID

'// FMTID_WSD = {92506491-FF95-4724-A05A-5B81885A7C92}
'DEFINE_GUID(FMTID_WSD, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92);
$FMTID_WSD = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}")

'DEFINE_API_PKEY(PKEY_WSD_AddressURI, WSD_AddressURI, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001000);   // VT_LPWSTR
MACRO PKEY_WSD_AddressURI = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001000???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_WSD_Types, WSD_Types, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001001); // VT_LPWSTR
MACRO PKEY_WSD_Types = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001001???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_WSD_Scopes, WSD_Scopes, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001002);   // VT_LPWSTR
MACRO PKEY_WSD_Scopes = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001002???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_WSD_MetadataVersion, WSD_MetadataVersion, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001003); //VT_UI8
MACRO PKEY_WSD_MetadataVersion = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001003???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_WSD_AppSeqInstanceID, WSD_AppSeqInstanceID, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001004);   // VT_UI8
MACRO PKEY_WSD_AppSeqInstanceID = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001004???)   '  // VT_UI8
'DEFINE_API_PKEY(PKEY_WSD_AppSeqSessionID, WSD_AppSeqSessionID, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001005); // VT_LPWSTR
MACRO PKEY_WSD_AppSeqSessionID = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001005???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_WSD_AppSeqMessageNumber, WSD_AppSeqMessageNumber, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00001006); // VT_UI8
MACRO WSD_AppSeqMessageNumber = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00001006???)   '  // VT_UI8
'DEFINE_API_PKEY(PKEY_WSD_XAddrs, WSD_XAddrs, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00002000); // VT_LPWSTR or VT_VECTOR | VT_LPWSTR
MACRO WSD_XAddrs = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00002000???)   '  // VT_LPWSTR or VT_VECTOR | VT_LPWSTR

'DEFINE_API_PKEY(PKEY_WSD_MetadataClean, WSD_MetadataClean, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00000001);   // VT_BOOL
MACRO PKEY_WSD_MetadataClean = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00000001???)   '  // VT_BOOL
'DEFINE_API_PKEY(PKEY_WSD_ServiceInfo, WSD_ServiceInfo, 0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92, 0x00000002);   // VT_VECTOR|VT_VARIANT (variants are VT_UNKNOWN)
MACRO PKEY_WSD_ServiceInfo = GUID$("{92506491-FF95-4724-A05A-5B81885A7C92}") & MKDWD$(&H00000002???)   '  // VT_VECTOR|VT_VARIANT (variants are VT_UNKNOWN)

'DEFINE_API_PKEY(PKEY_PUBSVCS_TYPE, PUBSVCS_TYPE, 0xF1B88AD3, 0x109C, 0x4FD2, 0xBA, 0x3F, 0x53, 0x5A, 0x76, 0x5F, 0x82, 0xF4, 0x00005001); // VT_LPWSTR
MACRO PKEY_PUBSVCS_TYPE = GUID$("{F1B88AD3-109C-4FD2-BA3F-535A765F82F4}") & MKDWD$(&H00005001???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_PUBSVCS_SCOPE, PUBSVCS_SCOPE, 0x2AE2B567, 0xEECB, 0x4A3E, 0xB7, 0x53, 0x54, 0xC7, 0x25, 0x49, 0x43, 0x66, 0x00005002);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PUBSVCS_SCOPE = GUID$("{2AE2B567-EECB-4A3E-B753-54C725494366}") & MKDWD$(&H00005002???)   '  // VT_LPWSTR | VT_VECTOR
'DEFINE_API_PKEY(PKEY_PUBSVCS_METADATA, PUBSVCS_METADATA, 0x63C6D5B8, 0xF73A, 0x4ACA, 0x96, 0x7E, 0x0C, 0xC7, 0x87, 0xE0, 0xB5, 0x59, 0x00005003); // VT_LPWSTR
MACRO PKEY_PUBSVCS_METADATA = GUID$("{63C6D5B8-F73A-4ACA-967E-0CC7-87E0B559}") & MKDWD$(&H00005003???)   '  // VT_LPWSTR
'DEFINE_API_PKEY(PKEY_PUBSVCS_METADATA_VERSION, PUBSVCS_METADATA_VERSION, 0xC0C96C15, 0x1823, 0x4E5B, 0x93, 0x48, 0xE8, 0x25, 0x19, 0x92, 0x3F, 0x04, 0x00005004); // VT_UI8
MACRO PKEY_PUBSVCS_METADATA_VERSION = GUID$("{C0C96C15-1823-4E5B-9348-E82519923F04}") & MKDWD$(&H00005004???)   '  // VT_UI8
'DEFINE_API_PKEY(PKEY_PUBSVCS_NETWORK_PROFILES_ALLOWED, PUBSVCS_NETWORK_PROFILES_ALLOWED, 0x63C6D5B8, 0xF73A, 0x4ACA, 0x96, 0x7E, 0x0C, 0xC7, 0x87, 0xE0, 0xB5, 0x59, 0x00005005); // VT_VECTOR | VT_LPWSTR
MACRO PKEY_PUBSVCS_NETWORK_PROFILES_ALLOWED = GUID$("{63C6D5B8-F73A-4ACA-967E-0CC787E0B559}") & MKDWD$(&H00005005???)   '  // VT_VECTOR | VT_LPWSTR
'DEFINE_API_PKEY(PKEY_PUBSVCS_NETWORK_PROFILES_DENIED, PUBSVCS_NETWORK_PROFILES_DENIED, 0x63C6D5B8, 0xF73A, 0x4ACA, 0x96, 0x7E, 0x0C, 0xC7, 0x87, 0xE0, 0xB5, 0x59, 0x00005006); // VT_VECTOR | VT_LPWSTR
MACRO PKEY_PUBSVCS_NETWORK_PROFILES_DENIED = GUID$("{63C6D5B8-F73A-4ACA-967E-0CC787E0B559}") & MKDWD$(&H00005006???)   '  // VT_VECTOR | VT_LPWSTR
'DEFINE_API_PKEY(PKEY_PUBSVCS_NETWORK_PROFILES_DEFAULT, PUBSVCS_NETWORK_PROFILES_DEFAULT, 0x63C6D5B8, 0xF73A, 0x4ACA, 0x96, 0x7E, 0x0C, 0xC7, 0x87, 0xE0, 0xB5, 0x59, 0x00005007); // VT_BOOL
MACRO PKEY_PUBSVCS_NETWORK_PROFILES_DEFAULT = GUID$("{63C6D5B8-F73A-4ACA-967E-0CC787E0B559}") & MKDWD$(&H00005007???)   '  // VT_BOOL

'// FMTID_PNPX = {656A3BB3-ECC0-43FD-8477-4AE0404A96CD}
'DEFINE_GUID(FMTID_PNPX, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD);
$FMTID_PNPX = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}")

'        // from Discovery messages
'DEFINE_PROPERTYKEY(PKEY_PNPX_GlobalIdentity, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001000);   // VT_LPWSTR
MACRO PKEY_PNPX_GlobalIdentity = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001000???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_Types, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001001);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_Types = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001001???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_Scopes, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001002);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_Scopes = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001002???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_XAddrs, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001003);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_XAddrs = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001003???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_MetadataVersion, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001004);   // VT_UI8
MACRO PKEY_PNPX_MetadataVersion = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001004???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_ID, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001005);   // VT_LPWSTR
MACRO PKEY_PNPX_ID = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001005???)

'        // for Directed Discovery
'DEFINE_PROPERTYKEY(PKEY_PNPX_RemoteAddress, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001006);   // VT_LPWSTR
MACRO PKEY_PNPX_RemoteAddress = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001006???)
'       // for installable ssdp root devices
'DEFINE_PROPERTYKEY(PKEY_PNPX_RootProxy, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00001006);   // VT_BOOL
MACRO PKEY_PNPX_RootProxy = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00001006???)

'        // from ThisModel metadata
'#define PKEY_PNPX_Manufacturer PKEY_DeviceDisplay_Manufacturer // Deprecated! Please use PKEY_DeviceDisplay_Manufacturer
MACRO PKEY_PNPX_Manufacturer = PKEY_DeviceDisplay_Manufacturer
'DEFINE_PROPERTYKEY(PKEY_PNPX_ManufacturerUrl, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002001);   // VT_LPWSTR
MACRO PKEY_PNPX_ManufacturerUrl = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002001???)
'#define PKEY_PNPX_ModelName PKEY_DeviceDisplay_ModelName // Deprecated! Please use PKEY_DeviceDisplay_ModelName
'#define PKEY_PNPX_ModelNumber PKEY_DeviceDisplay_ModelNumber //Depricated! Please use PKEY_DeviceDisplayModelNumber
MACRO PKEY_PNPX_ModelName = PKEY_DeviceDisplay_ModelName
MACRO PKEY_PNPX_ModelNumber = PKEY_DeviceDisplay_ModelNumber
'DEFINE_PROPERTYKEY(PKEY_PNPX_ModelUrl, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002004);   // VT_LPWSTR
MACRO PKEY_PNPX_ModelUrl = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002004???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_Upc, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002005);   // VT_LPWSTR
MACRO PKEY_PNPX_Upc = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002005???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_PresentationUrl, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00002006);   // VT_LPWSTR
MACRO PKEY_PNPX_PresentationUrl = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00002006???)

'        // from ThisDevice metadata
'#define PKEY_PNPX_FriendlyName PKEY_DeviceDisplay_FriendlyName // Deprecated! Please use PKEY_DeviceDisplay_Name
MACRO PKEY_PNPX_FriendlyName = PKEY_DeviceDisplay_FriendlyName
'DEFINE_PROPERTYKEY(PKEY_PNPX_FirmwareVersion, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003001);   // VT_LPWSTR
MACRO PKEY_PNPX_FirmwareVersion = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003001???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_SerialNumber, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003002);   // VT_LPWSTR
MACRO PKEY_PNPX_SerialNumber = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003003???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_DeviceCategory, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003004);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_DeviceCategory = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003004???)

'    // for secure devices
'DEFINE_PROPERTYKEY(PKEY_PNPX_SecureChannel, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00007001);   // VT_BOOL
MACRO PKEY_PNPX_SecureChannel = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00007001???)   ' // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_PNPX_CompactSignature, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00007002);   // VT_BOOL
MACRO PKEY_PNPX_CompactSignature = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00007002???)   ' // VT_BOOL

'        // DeviceCategory values
$$PNPX_DEVICECATEGORY_COMPUTER                            = "Computers"$$
$$PNPX_DEVICECATEGORY_INPUTDEVICE                         = "Input"$$
$$PNPX_DEVICECATEGORY_PRINTER                             = "Printers"$$
$$PNPX_DEVICECATEGORY_SCANNER                             = "Scanners"$$
$$PNPX_DEVICECATEGORY_FAX                                 = "FAX"$$
$$PNPX_DEVICECATEGORY_MFP                                 = "MFP"$$
$$PNPX_DEVICECATEGORY_CAMERA                              = "Cameras"$$
$$PNPX_DEVICECATEGORY_STORAGE                             = "Storage"$$
$$PNPX_DEVICECATEGORY_NETWORK_INFRASTRUCTURE              = "NetworkInfrastructure"$$
$$PNPX_DEVICECATEGORY_DISPLAYS                            = "Displays"$$
$$PNPX_DEVICECATEGORY_MULTIMEDIA_DEVICE                   = "MediaDevices"$$
$$PNPX_DEVICECATEGORY_GAMING_DEVICE                       = "Gaming"$$
$$PNPX_DEVICECATEGORY_TELEPHONE                           = "Phones"$$
$$PNPX_DEVICECATEGORY_HOME_AUTOMATION_SYSTEM              = "HomeAutomation"$$
$$PNPX_DEVICECATEGORY_HOME_SECURITY_SYSTEM                = "HomeSecurity"$$
$$PNPX_DEVICECATEGORY_OTHER                               = "Other"$$

'DEFINE_PROPERTYKEY(PKEY_PNPX_DeviceCategory_Desc, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003005);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_DeviceCategory_Desc = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003005???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_Category_Desc_NonPlural,  0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003010);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_Category_Desc_NonPlural = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003010???)   ' // VT_LPWSTR | VT_VECTOR

'DEFINE_PROPERTYKEY(PKEY_PNPX_PhysicalAddress, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003006);   // VT_UI1 | VT_VECTOR
MACRO PKEY_PNPX_PhysicalAddress = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003006???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_NetworkInterfaceLuid, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003007);   // VT_UI8
MACRO PKEY_PNPX_NetworkInterfaceLuid = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003007???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_NetworkInterfaceGuid, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003008);   // VT_LPWSTR
MACRO PKEY_PNPX_NetworkInterfaceGuid = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003008???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_IpAddress, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00003009);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_IpAddress = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00003009???)

'        // from Relationship metadata
'DEFINE_PROPERTYKEY(PKEY_PNPX_ServiceAddress, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00004000);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_ServiceAddress = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00004000???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_ServiceId, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00004001);   // VT_LPWSTR
MACRO PKEY_PNPX_ServiceId = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00004001???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_ServiceTypes, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00004002);   // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_ServiceTypes = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00004002???)

'        // Association DB PKEYs
'DEFINE_API_PKEY(PKEY_PNPX_Devnode, PnPXDevNode, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00000001); // VT_BOOL
MACRO PKEY_PNPX_Devnode = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00000001???)
'DEFINE_API_PKEY(PKEY_PNPX_AssociationState, AssociationState, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00000002); // VT_UINT
MACRO PKEY_PNPX_AssociationState = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00000002???)
'DEFINE_API_PKEY(PKEY_PNPX_AssociatedInstanceId, AssociatedInstanceId, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00000003); // VT_LPWSTR
MACRO PKEY_PNPX_AssociatedInstanceId = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00000003???)
'DEFINE_API_PKEY(PKEY_PNPX_LastNotificationTime, LastNotificationTime, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00000004); // VT_DATE
MACRO PKEY_PNPX_LastNotificationTime = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00000004???)
'        // for Computer Discovery
'DEFINE_PROPERTYKEY(PKEY_PNPX_DomainName, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00005000);   // VT_LPWSTR
MACRO PKEY_PNPX_DomainName = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00005000???)
'// Use PKEY_ComputerName (propkey.h) DEFINE_PROPERTYKEY(PKEY_PNPX_MachineName, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00005001);   // VT_LPWSTR
'MACRO PKEY_PNPX_MachineName = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00005001???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_ShareName, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00005002);   // VT_LPWSTR
MACRO PKEY_PNPX_ShareName = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00005002???)

'    // SSDP Provider custom properties
'DEFINE_PROPERTYKEY(PKEY_SSDP_AltLocationInfo, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00006000);   // VT_LPWSTR
MACRO PKEY_SSDP_AltLocationInfo = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00006000???)
'DEFINE_PROPERTYKEY(PKEY_SSDP_DevLifeTime, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00006001);   // VT_UI4
MACRO PKEY_SSDP_DevLifeTime = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00006001???)
'DEFINE_PROPERTYKEY(PKEY_SSDP_NetworkInterface, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00006002);   // VT_BOOL
MACRO PKEY_SSDP_NetworkInterface = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00006002???)

'// FMTID_PNPXDynamicProperty = {4FC5077E-B686-44BE-93E3-86CAFE368CCD}
'DEFINE_GUID(FMTID_PNPXDynamicProperty, 0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD);
$FMTID_PNPXDynamicProperty = GUID$("{4FC5077E-B686-44BE-93E3-86CAFE368CCD}")

'DEFINE_PROPERTYKEY(PKEY_PNPX_Installable, 0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD, 0x00000001); // VT_BOOL
MACRO PKEY_PNPX_Installable = GUID$("{4FC5077E-B686-44BE-93E3-86CAFE368CCD}") & MKDWD$(&H00000001???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_Associated, 0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD, 0x00000002); // VT_BOOL
MACRO PKEY_PNPX_Associated = GUID$("{4FC5077E-B686-44BE-93E3-86CAFE368CCD}") & MKDWD$(&H00000002???)
'// PKEY_PNPX_Installed is deprecated this PKEY really represents Associated state
'#define PKEY_PNPX_Installed PKEY_PNPX_Associated    // Deprecated! Please use PKEY_PNPX_Associated
MACRO PKEY_PNPX_Installed = PKEY_PNPX_Associated
'DEFINE_PROPERTYKEY(PKEY_PNPX_CompatibleTypes, 0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD, 0x00000003); // VT_LPWSTR | VT_VECTOR
MACRO PKEY_PNPX_CompatibleTypes = GUID$("{4FC5077E-B686-44BE-93E3-86CAFE368CCD}") & MKDWD$(&H00000003???)
'DEFINE_PROPERTYKEY(PKEY_PNPX_InstallState, 0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD, 0x00000004); // VT_UI4 | VT_VECTOR
MACRO PKEY_PNPX_InstallState = GUID$("{4FC5077E-B686-44BE-93E3-86CAFE368CCD}") & MKDWD$(&H00000004???)    ' // VT_UI4 | VT_VECTOR

%PNPX_INSTALLSTATE_NOTINSTALLED = 0   ' // vector length = 1
%PNPX_INSTALLSTATE_INSTALLED    = 1   ' // vector length = 3, CM_Get_DevNode_Status in 2nd and 3rd elements
%PNPX_INSTALLSTATE_INSTALLING   = 2   ' // vector length = 1 or 3, CM_Get_DevNode_Status in 2nd and 3rd elements if available
%PNPX_INSTALLSTATE_FAILED       = 3   ' // vector length = 3, CM_Get_DevNode_Status in 2nd and 3rd elements

'// Other
'DEFINE_PROPERTYKEY(PKEY_PNPX_Removable, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00007000);   // VT_BOOL
MACRO PKEY_PNPX_Removable = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00007000???)   ' // VT_BOOL
'DEFINE_PROPERTYKEY(PKEY_PNPX_IPBusEnumerated, 0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD, 0x00007010);   // VT_BOOL
MACRO PKEY_PNPX_IPBusEnumerated = GUID$("{656A3BB3-ECC0-43FD-8477-4AE0404A96CD}") & MKDWD$(&H00007010???)   ' // VT_BOOL

'    // WNET Provider properties
'DEFINE_PROPERTYKEY(PKEY_WNET_Scope, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000001); // VT_UINT
MACRO PKEY_WNET_Scope = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000001???)
'DEFINE_PROPERTYKEY(PKEY_WNET_Type, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000002); // VT_UINT
MACRO PKEY_WNET_Type = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000002???)
'DEFINE_PROPERTYKEY(PKEY_WNET_DisplayType, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000003); // VT_UINT
MACRO PKEY_WNET_DisplayType = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000003???)
'DEFINE_PROPERTYKEY(PKEY_WNET_Usage, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000004); // VT_UINT
MACRO PKEY_WNET_Usage = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000004???)
'DEFINE_PROPERTYKEY(PKEY_WNET_LocalName, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000005); // VT_LPWSTR
MACRO PKEY_WNET_LocalName = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000005???)
'DEFINE_PROPERTYKEY(PKEY_WNET_RemoteName, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000006); // VT_LPWSTR
MACRO PKEY_WNET_RemoteName = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000006???)
'DEFINE_PROPERTYKEY(PKEY_WNET_Comment, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000007); // VT_LPWSTR
MACRO PKEY_WNET_Comment = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000007???)
'DEFINE_PROPERTYKEY(PKEY_WNET_Provider, 0xdebda43a, 0x37b3, 0x4383, 0x91, 0xE7, 0x44, 0x98, 0xda, 0x29, 0x95, 0xab, 0x00000008); // VT_LPWSTR
MACRO PKEY_WNET_Provider = GUID$("{debda43a-37b3-4383-91E7-4498da2995ab}") & MKDWD$(&H00000008???)

'    // WCN Provider properties

'DEFINE_PROPERTYKEY(PKEY_WCN_Version, 0x88190b80, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000001); // VT_UI1
MACRO PKEY_WCN_Version = GUID$("{88190b80-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000001???)
'DEFINE_PROPERTYKEY(PKEY_WCN_RequestType, 0x88190b81, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000002); // VT_INT
MACRO PKEY_WCN_RequestType = GUID$("{88190b81-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000002???)
'DEFINE_PROPERTYKEY(PKEY_WCN_AuthType, 0x88190b82, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000003); // VT_INT
MACRO PKEY_WCN_AuthType = GUID$("{88190b82-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000003???)
'DEFINE_PROPERTYKEY(PKEY_WCN_EncryptType, 0x88190b83, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000004); // VT_INT
MACRO PKEY_WCN_EncryptType = GUID$("{88190b83-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000004???)
'DEFINE_PROPERTYKEY(PKEY_WCN_ConnType, 0x88190b84, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000005); // VT_INT
MACRO PKEY_WCN_ConnType = GUID$("{88190b84-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000005???)
'DEFINE_PROPERTYKEY(PKEY_WCN_ConfigMethods, 0x88190b85, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000006); // VT_INT
MACRO PKEY_WCN_ConfigMethods = GUID$("{88190b85-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000006???)
'// map WCN DeviceType to PKEY_PNPX_DeviceCategory
'//DEFINE_PROPERTYKEY(PKEY_WCN_DeviceType, 0x88190b86, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000007); // VT_INT
'MACRO PKEY_WCN_DeviceType = GUID$("{88190b86-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000007???)
'DEFINE_PROPERTYKEY(PKEY_WCN_RfBand, 0x88190b87, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000008); // VT_INT
MACRO PKEY_WCN_RfBand = GUID$("{88190b87-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000008???)
'DEFINE_PROPERTYKEY(PKEY_WCN_AssocState, 0x88190b88, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000009); // VT_INT
MACRO PKEY_WCN_AssocState = GUID$("{88190b88-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000009???)
'DEFINE_PROPERTYKEY(PKEY_WCN_ConfigError, 0x88190b89, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000a); // VT_INT
MACRO PKEY_WCN_ConfigError = GUID$("{88190b89-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000a???)
'DEFINE_PROPERTYKEY(PKEY_WCN_ConfigState, 0x88190b89, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000b); // VT_UI1
MACRO PKEY_WCN_ConfigState = GUID$("{88190b89-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000b???)
'DEFINE_PROPERTYKEY(PKEY_WCN_DevicePasswordId, 0x88190b89, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000c); // VT_INT
MACRO PKEY_WCN_DevicePasswordId = GUID$("{88190b89-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000c???)
'DEFINE_PROPERTYKEY(PKEY_WCN_OSVersion, 0x88190b89, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000d); // VT_UINT
MACRO PKEY_WCN_OSVersion = GUID$("{88190b89-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000d???)
'DEFINE_PROPERTYKEY(PKEY_WCN_VendorExtension, 0x88190b8a, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000e); // VT_UI1 | VT_VECTOR
MACRO PKEY_WCN_VendorExtension = GUID$("{88190b8a-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000e???)
'DEFINE_PROPERTYKEY(PKEY_WCN_RegistrarType, 0x88190b8b, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x0000000f); // VT_INT
MACRO PKEY_WCN_RegistrarType = GUID$("{88190b8b-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H0000000f???)

'//-----------------------------------------------------------------------------
'// DriverPackage properties

'#define PKEY_DriverPackage_Model                PKEY_DrvPkg_Model
MACRO PKEY_DriverPackage_Model = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(2)
'#define PKEY_DriverPackage_VendorWebSite        PKEY_DrvPkg_VendorWebSite
MACRO PKEY_DriverPackage_VendorWebSite = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(3)
'#define PKEY_DriverPackage_DetailedDescription  PKEY_DrvPkg_DetailedDescription
MACRO PKEY_DriverPackage_DetailedDescription = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(4)
'#define PKEY_DriverPackage_DocumentationLink    PKEY_DrvPkg_DocumentationLink
MACRO PKEY_DriverPackage_DocumentationLink = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(5)
'#define PKEY_DriverPackage_Icon                 PKEY_DrvPkg_Icon
MACRO PKEY_DriverPackage_Icon = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(6)
'#define PKEY_DriverPackage_BrandingIcon         PKEY_DrvPkg_BrandingIcon
MACRO PKEY_DriverPackage_BrandingIcon = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(7)

'//-----------------------------------------------------------------------------
'// Hardware properties

'DEFINE_PROPERTYKEY(PKEY_Hardware_Devinst, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 4097);

'//  Name:     System.Hardware.DisplayAttribute -- PKEY_Hardware_DisplayAttribute
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 5
'DEFINE_PROPERTYKEY(PKEY_Hardware_DisplayAttribute, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 5);
MACRO PKEY_Hardware_DisplayAttribute = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(5)

'//  Name:     System.Hardware.DriverDate -- PKEY_Hardware_DriverDate
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 11
'DEFINE_PROPERTYKEY(PKEY_Hardware_DriverDate, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 11);
MACRO PKEY_Hardware_DriverDate = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(11)

'//  Name:     System.Hardware.DriverProvider -- PKEY_Hardware_DriverProvider
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 10
'DEFINE_PROPERTYKEY(PKEY_Hardware_DriverProvider, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 10);
MACRO PKEY_Hardware_DriverProvider = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(10)

'//  Name:     System.Hardware.DriverVersion -- PKEY_Hardware_DriverVersion
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 9
'DEFINE_PROPERTYKEY(PKEY_Hardware_DriverVersion, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 9);
MACRO PKEY_Hardware_DriverVersion = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(9)

'//  Name:     System.Hardware.Function -- PKEY_Hardware_Function
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 4099
'DEFINE_PROPERTYKEY(PKEY_Hardware_Function, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 4099);
MACRO PKEY_Hardware_Function = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(4099)

'//  Name:     System.Hardware.Icon -- PKEY_Hardware_Icon
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 3
'DEFINE_PROPERTYKEY(PKEY_Hardware_Icon, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 3);
MACRO PKEY_Hardware_Icon = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(3)

'//  Name:     System.Hardware.Image -- PKEY_Hardware_Image
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 4098
'DEFINE_PROPERTYKEY(PKEY_Hardware_Image, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 4098);
MACRO PKEY_Hardware_Image = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(4098)

'//  Name:     System.Hardware.Manufacturer -- PKEY_Hardware_Manufacturer
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 6
'DEFINE_PROPERTYKEY(PKEY_Hardware_Manufacturer, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 6);
MACRO PKEY_Hardware_Manufacturer = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(6)

'//  Name:     System.Hardware.Model -- PKEY_Hardware_Model
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 7
'DEFINE_PROPERTYKEY(PKEY_Hardware_Model, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 7);
MACRO PKEY_Hardware_Model = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(7)

'//  Name:     System.Hardware.Name -- PKEY_Hardware_Name
'//  Type:     String -- VT_LPWSTR  (For variants: VT_BSTR)
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 2
'DEFINE_PROPERTYKEY(PKEY_Hardware_Name, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 2);
MACRO PKEY_Hardware_Name = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(2)

'//  Name:     System.Hardware.SerialNumber -- PKEY_Hardware_SerialNumber
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 8
'DEFINE_PROPERTYKEY(PKEY_Hardware_SerialNumber, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 8);
MACRO PKEY_Hardware_SerialNumber = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(8)

'//  Name:     System.Hardware.ShellAttributes -- PKEY_Hardware_ShellAttributes
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 4100
'DEFINE_PROPERTYKEY(PKEY_Hardware_ShellAttributes, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 4100);
MACRO PKEY_Hardware_ShellAttributes = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(4100)

'//  Name:     System.Hardware.Status -- PKEY_Hardware_Status
'//  Type:     Unspecified -- VT_NULL
'//  FormatID: 5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953, 4096
'DEFINE_PROPERTYKEY(PKEY_Hardware_Status, 0x5EAF3EF2, 0xE0CA, 0x4598, 0xBF, 0x06, 0x71, 0xED, 0x1D, 0x9D, 0xD9, 0x53, 4096);
MACRO PKEY_Hardware_Status = GUID$("{5EAF3EF2-E0CA-4598-BF06-71ED1D9DD953}") & MKDWD$(4096)
