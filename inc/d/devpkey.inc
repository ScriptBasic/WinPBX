' ########################################################################################
' Microsoft Windows
' File: devpkey.inc
' Contents: Property keys for the Plug and Play Device Property API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DEVPKEY_INC = 1

#INCLUDE ONCE "devpropdef.inc"

'//
'// DEVPKEY_NAME
'// Common DEVPKEY used to retrieve the display name for an object.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_NAME,                          0xb725f130, 0x47ef, 0x101a, 0xa5, 0xf1, 0x02, 0x60, 0x8c, 0x9e, 0xeb, 0xac, 10);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_NAME = GUID$("{B725F130-47EF-101A-A5F1-02608C9EEBAC}") & MKDWD$(10)

'//
'// Device properties
'// These DEVPKEYs correspond to the SetupAPI SPDRP_XXX device properties.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DeviceDesc,             0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 2);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DeviceDesc = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_HardwareIds,            0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 3);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_HardwareIds = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_CompatibleIds,          0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 4);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_CompatibleIds = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Service,                0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 6);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_Service = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(6)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Class,                  0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 9);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_Class = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(9)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ClassGuid,              0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 10);    // DEVPROP_TYPE_GUID
MACRO DEVPKEY_Device_ClassGuid = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(10)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Driver,                 0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 11);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_Driver = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(11)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ConfigFlags,            0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 12);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_ConfigFlags = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(12)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Manufacturer,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 13);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_Manufacturer = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(13)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_FriendlyName,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 14);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_FriendlyName = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(14)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_LocationInfo,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 15);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_LocationInfo = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(15)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_PDOName,                0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 16);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_PDOName = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(16)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Capabilities,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 17);    // DEVPROP_TYPE_UNINT32
MACRO DEVPKEY_Device_Capabilities = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(17)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_UINumber,               0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 18);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_UINumber = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(18)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_UpperFilters,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 19);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_UpperFilters = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(19)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_LowerFilters,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 20);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_LowerFilters = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(20)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_BusTypeGuid,            0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 21);    // DEVPROP_TYPE_GUID
MACRO DEVPKEY_Device_BusTypeGuid = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(21)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_LegacyBusType,          0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 22);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_LegacyBusType = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(22)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_BusNumber,              0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 23);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_BusNumber = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(23)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_EnumeratorName,         0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 24);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_EnumeratorName = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(24)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Security,               0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 25);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR
MACRO DEVPKEY_Device_Security = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(25)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_SecuritySDS,            0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 26);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING
MACRO DEVPKEY_Device_SecuritySDS = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(26)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DevType,                0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 27);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_DevType = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(27)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Exclusive,              0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 28);    // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_Exclusive = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(28)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Characteristics,        0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 29);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_Characteristics = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(29)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Address,                0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 30);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_Address = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(30)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_UINumberDescFormat,     0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 31);    // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_UINumberDescFormat = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(31)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_PowerData,              0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 32);    // DEVPROP_TYPE_BINARY
MACRO DEVPKEY_Device_PowerData = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(32)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_RemovalPolicy,          0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 33);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_RemovalPolicy = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(33)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_RemovalPolicyDefault,   0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 34);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_RemovalPolicyDefault = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(34)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_RemovalPolicyOverride,  0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 35);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_RemovalPolicyOverride = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(35)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_InstallState,           0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 36);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_InstallState = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(36)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_LocationPaths,          0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 37);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_LocationPaths = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(37)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_BaseContainerId,        0xa45c254e, 0xdf1c, 0x4efd, 0x80, 0x20, 0x67, 0xd1, 0x46, 0xa8, 0x50, 0xe0, 38);    // DEVPROP_TYPE_GUID
MACRO DEVPKEY_Device_BaseContainerId = GUID$("{A45C254E-DF1C-4EFD-8020-67D146A850E0}") & MKDWD$(38)

'//
'// Device properties
'// These DEVPKEYs correspond to a device's status and problem code.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DevNodeStatus,          0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 2);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_DevNodeStatus = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ProblemCode,            0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 3);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_ProblemCode = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(3)

'//
'// Device properties
'// These DEVPKEYs correspond to a device's relations.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_EjectionRelations,      0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 4);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_EjectionRelations = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_RemovalRelations,       0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 5);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_RemovalRelations = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(5)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_PowerRelations,         0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 6);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_PowerRelations = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(6)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_BusRelations,           0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 7);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_BusRelations = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(7)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Parent,                 0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 8);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_Parent = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(8)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Children,               0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 9);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_Children = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(9)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Siblings,               0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 10);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_Siblings = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(10)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_TransportRelations,     0x4340a6c5, 0x93fa, 0x4706, 0x97, 0x2c, 0x7b, 0x64, 0x80, 0x08, 0xa5, 0xa7, 11);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_TransportRelations = GUID$("{4340A6C5-93FA-4706-972C-7B648008A5A7}") & MKDWD$(11)

'//
'// Other Device properties
'// These DEVPKEYs are set for the corresponding types of root-enumerated devices.     ;comment
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Reported,               0x80497100, 0x8c73, 0x48b9, 0xaa, 0xd9, 0xce, 0x38, 0x7e, 0x19, 0xc5, 0x6e, 2);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_Reported = GUID$("{80497100-8C73-48B9-AAD9-CE387E19C56E}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Legacy,                 0x80497100, 0x8c73, 0x48b9, 0xaa, 0xd9, 0xce, 0x38, 0x7e, 0x19, 0xc5, 0x6e, 3);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_Legacy = GUID$("{80497100-8C73-48B9-AAD9-CE387E19C56E}") & MKDWD$(3)

'//
'// Device Instance Id
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_InstanceId,             0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 256);   // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_InstanceId = GUID$("{80497100-8C73-48B9-AAD9-CE387E19C56E}") & MKDWD$(256)

'//
'// Device Experience related Keys
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ModelId,                0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 2);     // DEVPROP_TYPE_GUID
MACRO DEVPKEY_Device_ModelId = GUID$("{80D81EA6-7473-4B0C-8216-EFC11A2C4C8B}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_FriendlyNameAttributes, 0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 3);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_FriendlyNameAttributes = GUID$("{80D81EA6-7473-4B0C-8216-EFC11A2C4C8B}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ManufacturerAttributes, 0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 4);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_ManufacturerAttributes = GUID$("{80D81EA6-7473-4B0C-8216-EFC11A2C4C8B}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_PresenceNotForDevice,   0x80d81ea6, 0x7473, 0x4b0c, 0x82, 0x16, 0xef, 0xc1, 0x1a, 0x2c, 0x4c, 0x8b, 5);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_PresenceNotForDevice = GUID$("{80D81EA6-7473-4B0C-8216-EFC11A2C4C8B}") & MKDWD$(5)

'//
'// Other Device properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Numa_Proximity_Domain,         0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 1);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Numa_Proximity_Domain = GUID$("{540B947E-8B40-45BC-A8A2-6A0B894CBDA2}") & MKDWD$(1)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DHP_Rebalance_Policy,   0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 2);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_DHP_Rebalance_Policy = GUID$("{540B947E-8B40-45BC-A8A2-6A0B894CBDA2}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_Numa_Node,              0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 3);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_Numa_Node = GUID$("{540B947E-8B40-45BC-A8A2-6A0B894CBDA2}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_BusReportedDeviceDesc,  0x540b947e, 0x8b40, 0x45bc, 0xa8, 0xa2, 0x6a, 0x0b, 0x89, 0x4c, 0xbd, 0xa2, 4);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_BusReportedDeviceDesc = GUID$("{540B947E-8B40-45BC-A8A2-6A0B894CBDA2}") & MKDWD$(4)

'//
'// Device Session Id
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_SessionId,              0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 6);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_SessionId = GUID$("{83DA6326-97A6-4088-9453-A1923F573B29}") & MKDWD$(6)

'//
'// Device activity timestamp properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_InstallDate,            0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 100);   // DEVPROP_TYPE_FILETIME
MACRO DEVPKEY_Device_InstallDate = GUID$("{83DA6326-97A6-4088-9453-A1923F573B29}") & MKDWD$(100)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_FirstInstallDate,       0x83da6326, 0x97a6, 0x4088, 0x94, 0x53, 0xa1, 0x92, 0x3f, 0x57, 0x3b, 0x29, 101);   // DEVPROP_TYPE_FILETIME
MACRO DEVPKEY_Device_FirstInstallDate = GUID$("{83DA6326-97A6-4088-9453-A1923F573B29}") & MKDWD$(101)

'//
'// Device driver properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverDate,             0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 2);      // DEVPROP_TYPE_FILETIME
MACRO DEVPKEY_Device_DriverDate = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverVersion,          0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 3);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverVersion = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverDesc,             0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 4);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverDesc = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverInfPath,          0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 5);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverInfPath = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(5)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverInfSection,       0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 6);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverInfSection = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(6)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverInfSectionExt,    0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 7);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverInfSectionExt = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(7)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_MatchingDeviceId,       0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 8);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_MatchingDeviceId = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(8)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverProvider,         0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 9);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverProvider = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(9)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverPropPageProvider, 0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 10);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_DriverPropPageProvider = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(10)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverCoInstallers,     0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 11);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_Device_DriverCoInstallers = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(11)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ResourcePickerTags,     0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 12);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_ResourcePickerTags = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(12)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_ResourcePickerExceptions, 0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 13);   // DEVPROP_TYPE_STRING
MACRO DEVPKEY_Device_ResourcePickerExceptions = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(13)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverRank,             0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 14);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_DriverRank = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(14)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_DriverLogoLevel,        0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 15);     // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_Device_DriverLogoLevel = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(15)

'//
'// Device properties
'// These DEVPKEYs may be set by the driver package installed for a device.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_NoConnectSound,         0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 17);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_NoConnectSound = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(17)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_GenericDriverInstalled, 0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 18);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_GenericDriverInstalled = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(18)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_AdditionalSoftwareRequested, 0xa8b865dd, 0x2e3d, 0x4094, 0xad, 0x97, 0xe5, 0x93, 0xa7, 0xc, 0x75, 0xd6, 19); //DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_AdditionalSoftwareRequested = GUID$("{A8B865DD-2E3D-4094-AD97-E593A70C75D6}") & MKDWD$(19)

'//
'// Device safe-removal properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_Device_SafeRemovalRequired,    0xafd97640,  0x86a3, 0x4210, 0xb6, 0x7c, 0x28, 0x9c, 0x41, 0xaa, 0xbe, 0x55, 2);    // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_SafeRemovalRequired = GUID$("{AFD97640-86A3-4210-B67C-289C41AABE55}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_Device_SafeRemovalRequiredOverride, 0xafd97640,  0x86a3, 0x4210, 0xb6, 0x7c, 0x28, 0x9c, 0x41, 0xaa, 0xbe, 0x55, 3); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_Device_SafeRemovalRequiredOverride = GUID$("{AFD97640-86A3-4210-B67C-289C41AABE55}") & MKDWD$(3)

'//
'// Device properties
'// These DEVPKEYs may be set by the driver package installed for a device.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_Model,                  0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 2);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DrvPkg_Model = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_VendorWebSite,          0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 3);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DrvPkg_VendorWebSite = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_DetailedDescription,    0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 4);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DrvPkg_DetailedDescription = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_DocumentationLink,      0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 5);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DrvPkg_DocumentationLink = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(5)
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_Icon,                   0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 6);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DrvPkg_Icon = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(6)
'DEFINE_DEVPROPKEY(DEVPKEY_DrvPkg_BrandingIcon,           0xcf73bb51, 0x3abf, 0x44a2, 0x85, 0xe0, 0x9a, 0x3d, 0xc7, 0xa1, 0x21, 0x32, 7);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DrvPkg_BrandingIcon = GUID$("{CF73BB51-3ABF-44A2-85E0-9A3DC7A12132}") & MKDWD$(7)


'//
'// Device setup class properties
'// These DEVPKEYs correspond to the SetupAPI SPCRP_XXX setup class properties.
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_UpperFilters,      0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 19);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DeviceClass_UpperFilters = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(19)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_LowerFilters,      0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 20);    // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DeviceClass_LowerFilters = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(20)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_Security,          0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 25);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR
MACRO DEVPKEY_DeviceClass_Security = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(25)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_SecuritySDS,       0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 26);    // DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING
MACRO DEVPKEY_DeviceClass_SecuritySDS = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(26)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_DevType,           0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 27);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_DeviceClass_DevType = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(27)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_Exclusive,         0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 28);    // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_Exclusive = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(28)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_Characteristics,   0x4321918b, 0xf69e, 0x470d, 0xa5, 0xde, 0x4d, 0x88, 0xc7, 0x5a, 0xd2, 0x4b, 29);    // DEVPROP_TYPE_UINT32
MACRO DEVPKEY_DeviceClass_Characteristics = GUID$("{4321918B-F69E-470D-A5DE-4D88C75AD24B}") & MKDWD$(29)

'//
'// Device setup class properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_Name,              0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 2);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_Name = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_ClassName,         0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 3);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_ClassName = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_Icon,              0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 4);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_Icon = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(4)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_ClassInstaller,    0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 5);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_ClassInstaller = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(5)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_PropPageProvider,  0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 6);      // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_PropPageProvider = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(6)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_NoInstallClass,    0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 7);      // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_NoInstallClass = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(7)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_NoDisplayClass,    0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 8);      // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_NoDisplayClass = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(8)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_SilentInstall,     0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 9);      // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_SilentInstall = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(9)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_NoUseClass,        0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 10);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_NoUseClass = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(10)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_DefaultService,    0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 11);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceClass_DefaultService = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(11)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_IconPath,          0x259abffc, 0x50a7, 0x47ce, 0xaf, 0x8, 0x68, 0xc9, 0xa7, 0xd7, 0x33, 0x66, 12);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DeviceClass_IconPath = GUID$("{259ABFFC-50A7-47CE-AF08-68C9A7D73366}") & MKDWD$(12)

'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_DHPRebalanceOptOut, 0xd14d3ef3, 0x66cf, 0x4ba2, 0x9d, 0x38, 0x0d, 0xdb, 0x37, 0xab, 0x47, 0x01, 2);    // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceClass_DHPRebalanceOptOut = GUID$("{D14D3EF3-66CF-4BA2-9D38-0DDB37AB4701}") & MKDWD$(2)

'//
'// Other Device setup class properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceClass_ClassCoInstallers, 0x713d1703, 0xa2e2, 0x49f5, 0x92, 0x14, 0x56, 0x47, 0x2e, 0xf3, 0xda, 0x5c, 2);     // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DeviceClass_ClassCoInstallers = GUID$("{713D1703-A2E2-49F5-9214-56472EF3DA5C}") & MKDWD$(2)


'//
'// Device interface properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceInterface_FriendlyName,  0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 2);     // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceInterface_FriendlyName = GUID$("{026E516E-B814-414B-83CD-856D6FEF4822}") & MKDWD$(2)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceInterface_Enabled,       0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 3);     // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceInterface_Enabled = GUID$("{026E516E-B814-414B-83CD-856D6FEF4822}") & MKDWD$(3)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceInterface_ClassGuid,     0x026e516e, 0xb814, 0x414b, 0x83, 0xcd, 0x85, 0x6d, 0x6f, 0xef, 0x48, 0x22, 4);     // DEVPROP_TYPE_GUID
MACRO DEVPKEY_DeviceInterface_ClassGuid = GUID$("{026E516E-B814-414B-83CD-856D6FEF4822}") & MKDWD$(4)


'//
'// Device interface class properties
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceInterfaceClass_DefaultInterface,  0x14c83a99, 0x0b3f, 0x44b7, 0xbe, 0x4c, 0xa1, 0x78, 0xd3, 0x99, 0x05, 0x64, 2); // DEVPROP_TYPE_STRING
MACRO DEVPKEY_DeviceInterfaceClass_DefaultInterface = GUID$("{14C83A99-0B3F-44B7-BE4C-A178D3990564}") & MKDWD$(2)

'//
'// DeviceDisplay properties that can be set on a devnode
'//
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_IsShowInDisconnectedState,  0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x44); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceDisplay_IsShowInDisconnectedState = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H44)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_IsNotInterestingForDisplay, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x4a); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceDisplay_IsNotInterestingForDisplay = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H4a)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_Category,                   0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x5a); // DEVPROP_TYPE_STRING_LIST
MACRO DEVPKEY_DeviceDisplay_Category = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H5a)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_UnpairUninstall,            0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x62); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceDisplay_UnpairUninstall = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H62)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_RequiresUninstallElevation, 0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x63); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceDisplay_RequiresUninstallElevation = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H63)
'DEFINE_DEVPROPKEY(DEVPKEY_DeviceDisplay_AlwaysShowDeviceAsConnected,  0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57, 0x65); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_DeviceDisplay_AlwaysShowDeviceAsConnected = GUID$("{78C34FC8-104A-4ACA-9EA4-524D52996E57}") & MKDWD$(&H65)
