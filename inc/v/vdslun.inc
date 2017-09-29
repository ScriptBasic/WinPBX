' ########################################################################################
' Microsoft Windows
' File: vdslun.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%VDSLUN_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' enum VDS_STORAGE_IDENTIFIER_CODE_SET
%VDSStorageIdCodeSetReserved = 0
%VDSStorageIdCodeSetBinary   = 1
%VDSStorageIdCodeSetAscii    = 2
%VDSStorageIdCodeSetUtf8     = 3

' enum VDS_STORAGE_IDENTIFIER_TYPE
%VDSStorageIdTypeVendorSpecific           = 0
%VDSStorageIdTypeVendorId                 = 1
%VDSStorageIdTypeEUI64                    = 2
%VDSStorageIdTypeFCPHName                 = 3
%VDSStorageIdTypePortRelative             = 4
%VDSStorageIdTypeTargetPortGroup          = 5
%VDSStorageIdTypeLogicalUnitGroup         = 6
%VDSStorageIdTypeMD5LogicalUnitIdentifier = 7
%VDSStorageIdTypeScsiNameString           = 8

' enum VDS_STORAGE_BUS_TYPE
%VDSBusTypeUnknown           = 0
%VDSBusTypeScsi              = &H1
%VDSBusTypeAtapi             = &H2
%VDSBusTypeAta               = &H3
%VDSBusType1394              = &H4
%VDSBusTypeSsa               = &H5
%VDSBusTypeFibre             = &H6
%VDSBusTypeUsb               = &H7
%VDSBusTypeRAID              = &H8
%VDSBusTypeiScsi             = &H9
%VDSBusTypeSas               = &Ha
%VDSBusTypeSata              = &Hb
%VDSBusTypeSd                = &Hc
%VDSBusTypeMmc               = &Hd
%VDSBusTypeMax               = &He
%VDSBusTypeFileBackedVirtual = &Hf
%VDSBusTypeMaxReserved       = &H7f

' // Size = 16 bytes
TYPE VDS_STORAGE_IDENTIFIER DWORD
   m_CodeSet       AS LONG       ' VDS_STORAGE_IDENTIFIER_CODE_SET
   m_Type          AS LONG       ' VDS_STORAGE_IDENTIFIER_TYPE
   m_cbIdentifier  AS DWORD      ' ULONG
   m_rgbIdentifier AS BYTE PTR   ' BYTE*
END TYPE

' // Size = 12 bytes
TYPE VDS_STORAGE_DEVICE_ID_DESCRIPTOR
   m_version       AS DWORD                        ' ULONG
   m_cIdentifiers  AS DWORD                        ' ULONG
   m_rgIdentifiers AS VDS_STORAGE_IDENTIFIER PTR   ' VDS_STORAGE_IDENTIFIER*
END TYPE

' enum VDS_INTERCONNECT_ADDRESS_TYPE
%VDS_IA_UNKNOWN = 0
%VDS_IA_FCFS    = 1
%VDS_IA_FCPH    = 2
%VDS_IA_FCPH3   = 3
%VDS_IA_MAC     = 4
%VDS_IA_SCSI    = 5

' // Size = 20 bytes
TYPE VDS_INTERCONNECT DWORD
   m_addressType AS LONG       ' VDS_INTERCONNECT_ADDRESS_TYPE
   m_cbPort      AS DWORD      ' ULONG
   m_pbPort      AS BYTE PTR   ' BYTE*
   m_cbAddress   AS DWORD      ' ULONG
   m_pbAddress   AS BYTE PTR   ' BYTE*
END TYPE

' // Size = 68 bytes
TYPE VDS_LUN_INFORMATION DWORD FILL
   m_version            AS DWORD                  ' ULONG
   m_DeviceType         AS BYTE                   ' BYTE
   m_DeviceTypeModifier AS BYTE                   ' BYTE
   m_bCommandQueueing   AS LONG                   ' BOOL
   m_BusType            AS LONG                   ' VDS_STORAGE_BUS_TYPE
   m_szVendorId         AS ASCIIZ PTR             ' char*
   m_szProductId        AS ASCIIZ PTR             ' char*
   m_szProductRevision  AS ASCIIZ PTR             ' char*
   m_szSerialNumber     AS ASCIIZ PTR             ' char*
   m_diskSignature      AS GUID                   ' GUID
   m_deviceIdDescriptor AS VDS_STORAGE_DEVICE_ID_DESCRIPTOR
   m_cInterconnects     AS DWORD                  ' ULONG
   m_rgInterconnects    AS VDS_INTERCONNECT PTR   ' VDS_INTERCONNECT*
END TYPE

%VER_VDS_LUN_INFORMATION = 1
