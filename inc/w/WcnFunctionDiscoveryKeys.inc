' ########################################################################################
' Microsoft Windows
' File: WcnFunctionDiscoveryKeys.inc
' Contents: Function Discovery PKEYs used by WCN API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WCNFUNCTIONDISCOVERYKEYS_INC = 1

'#if NTDDI_VERSION >= NTDDI_WIN7

#INCLUDE ONCE "PropKeyDef.inc"

'// C100BECA-D33A-4a4b-BF23-BBEF4663D017
'DEFINE_GUID( SID_WcnProvider, 0xC100BECA,0xD33A,0x4A4B,0xBF,0x23,0xBB,0xEF,0x46,0x63,0xD0,0x17);
$SID_WcnProvider = GUID$("{C100BECA-D33A-4a4b-BF23-BBEF4663D017}")

'DEFINE_PROPERTYKEY(PKEY_WCN_DeviceType_Category,       0x88190b8b, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000010); // VT_UINT
'DEFINE_PROPERTYKEY(PKEY_WCN_DeviceType_SubCategoryOUI, 0x88190b8b, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000011); // VT_UINT
'DEFINE_PROPERTYKEY(PKEY_WCN_DeviceType_SubCategory,    0x88190b8b, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000012); // VT_UINT
'DEFINE_PROPERTYKEY(PKEY_WCN_SSID,                      0x88190b8b, 0x4684, 0x11da, 0xa2, 0x6a, 0x00, 0x02, 0xb3, 0x98, 0x8e, 0x81, 0x00000020); // VT_LPWSTR
' (should be VT_UI1|VT_VECTOR, but that's not supported by IFunctionInstanceCollectionQuery::AddPropertyConstraint)

MACRO PKEY_WCN_DeviceType_Category = GUID$("{88190b8b-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000010)   ' // VT_UINT
MACRO PKEY_WCN_DeviceType_SubCategoryOUI = GUID$("{88190b8b-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000011)   ' // VT_UINT
MACRO PKEY_WCN_DeviceType_SubCategory = GUID$("{88190b8b-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000012)   ' // VT_UINT
' (should be VT_UI1|VT_VECTOR, but that's not supported by IFunctionInstanceCollectionQuery::AddPropertyConstraint)
MACRO PKEY_WCN_SSID = GUID$("{88190b8b-4684-11da-a26a-0002b3988e81}") & MKDWD$(&H00000020)   ' // VT_UINT


'#endif // NTDDI_VERSION >= NTDDI_WIN7
