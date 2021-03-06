' ########################################################################################
' Microsoft Windows
' File: pciprop.inc
' Contents: Custom property definitions for a PCI root bus and a PCI device
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PCIPROP_INC = 1

'//
'// The GUID {D817FC28-793E-4b9e-9970-469D8BE63073} is a seed for all properties
'// defined for a root bus.
'//

'#define DEFINE_PCI_ROOT_BUS_DEVPKEY(_DevPkeyName, _Pid) \
'    DEFINE_DEVPROPKEY((_DevPkeyName), 0xd817fc28, 0x793e, 0x4b9e, 0x99, 0x70, 0x46, 0x9d, 0x8b, 0xe6, 0x30, 0x73, (_Pid))

'//
'// This property describes the secondary side characteristics of a root bus.
'// The values for this property field are interpreted as below:
'//

%DevProp_PciRootBus_SecondaryInterface_PciConventional = 0
%DevProp_PciRootBus_SecondaryInterface_PciXMode1       = 1
%DevProp_PciRootBus_SecondaryInterface_PciXMode2       = 2
%DevProp_PciRootBus_SecondaryInterface_PciExpress      = 3

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SecondaryInterface, 1); //DEVPROP_TYPE_UINT32
MACRO DEVPKEY_PciRootBus_SecondaryInterface = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(1)

'//
'// This field is valid for conventional PCI and PCI-X host bridges.
'// The values for this property field are interpreted as below:
'//

%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_33Mhz = 0
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_66Mhz = 1
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_66Mhz      = 2
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_100Mhz     = 3
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_133Mhz     = 4
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_66Mhz  = 5
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_100Mhz = 6
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_133Mhz = 7
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_66Mhz  = 8
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_100Mhz = 9
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_133Mhz = 10
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_66Mhz  = 11
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_100Mhz = 12
%DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_133Mhz = 13

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_CurrentSpeedAndMode, 2); //DEVPROP_TYPE_UINT32
MACRO DEVPKEY_PciRootBus_CurrentSpeedAndMode = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(2)

'//
'// This field is valid for conventional PCI and PCI-X host bridges.
'// The values for this property field are interpreted as below:
'//

%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_33Mhz = 1
%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_66Mhz = 2
%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_66Mhz            = 4
%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_133Mhz           = 8
%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_266Mhz           = 16
%DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_533Mhz           = 32

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SupportedSpeedsAndModes, 3); //DEVPROP_TYPE_UINT32
MACRO DEVPKEY_PciRootBus_SupportedSpeedsAndModes = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(3)

'//
'// This is boolean indicating if the host bridge is capable of forwarding
'// Device ID Message transactions.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_DeviceIDMessagingCapable, 4); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_DeviceIDMessagingCapable = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(4)

'//
'// Provides the width of a root bus interface.
'//

%DevProp_PciRootBus_BusWidth_32Bits = 0
%DevProp_PciRootBus_BusWidth_64Bits = 1

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SecondaryBusWidth, 5); //DEVPROP_TYPE_UINT32
MACRO DEVPKEY_PciRootBus_SecondaryBusWidth = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(5)

'//
'// This is a boolean indicating that an extended config space is available
'// on the secondary side of the root bus.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ExtendedConfigAvailable, 6); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_ExtendedConfigAvailable = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(6)

'//
'// This is a boolean indicating an operating system support for an extended
'// PCI config op region.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ExtendedPCIConfigOpRegionSupport, 7); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_ExtendedPCIConfigOpRegionSupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(7)

'//
'// This is a boolean indicating an operating system support for ASPM.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ASPMSupport, 8); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_ASPMSupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(8)

'//
'// This is a boolean indicating an operating system support for clock power
'// management.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ClockPowerManagementSupport, 9); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_ClockPowerManagementSupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(9)

'//
'// This is a boolean indicating an operating system support for PCI Segments.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCISegmentGroupsSupport, 10); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_PCISegmentGroupsSupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(10)

'//
'// This is a boolean indicating an operating system support for Message
'// Signaled Interrupts.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_MSISupport, 11); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_MSISupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(11)

'//
'// This is a boolean indicating that the firmware has granted control of native
'// hot plug interrupts to the operating system.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressNativeHotPlugControl, 12);  // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_PCIExpressNativeHotPlugControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(12)

'//
'// This is a boolean indicating that the firmware has granted control of native
'// SHPC to the operating system.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SHPCNativeHotPlugControl, 13);   // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_SHPCNativeHotPlugControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(13)

'//
'// This is a boolean indicating that the firmware has granted control over
'// native PME interrupts to the operating system.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressNativePMEControl, 14); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_PCIExpressNativePMEControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(14)

'//
'// This is a boolean indicating that the firmware has granted control over
'// AER to the operating system.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressAERControl, 15); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_PCIExpressAERControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(15)

'//
'// This is a boolean indicating that the firmware has granted control over the
'// PCI Express capability to the operating system.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressCapabilityControl, 16); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_PCIExpressCapabilityControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(16)

'//
'// This is a boolean indicating that the operating system is controlling PCI
'// Express features natively.  Generally this will be a reflection of the
'// individual feature controls granted by the firmware and exposed by properties
'// above, but the operating system might override the firmware.  The final
'// control disposition is reflected here.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_NativePciExpressControl, 17); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_NativePciExpressControl = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(17)

'//
'// This is a boolean indicating that the system is configured to support MSI.
'// If this is FALSE no message-signaled interrupts will be allocated to devices
'// on this system, even if the operating system supports MSI.
'//

'DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SystemMsiSupport, 18); // DEVPROP_TYPE_BOOLEAN
MACRO DEVPKEY_PciRootBus_SystemMsiSupport = GUID$("{D817FC28-793E-4B9E-9970-469D8BE63073}") & MKDWD$(18)


'//
'// The GUID {3AB22E31-8264-4b4e-9AF5-A8D2D8E33E62} is a seed for all properties
'// defined for a PCI device.
'//

'#define DEFINE_PCI_DEVICE_DEVPKEY(_DevPkeyName, _Pid) \
'   DEFINE_DEVPROPKEY((_DevPkeyName), 0x3ab22e31, 0x8264, 0x4b4e, 0x9a, 0xf5, 0xa8, 0xd2, 0xd8, 0xe3, 0x3e, 0x62, (_Pid))

'//
'// This property is defined to display the type of PCI device. The possible
'// values are shown below.
'//

%DevProp_PciDevice_DeviceType_PciConventional                         = 0
%DevProp_PciDevice_DeviceType_PciX                                    = 1
%DevProp_PciDevice_DeviceType_PciExpressEndpoint                      = 2
%DevProp_PciDevice_DeviceType_PciExpressLegacyEndpoint                = 3
%DevProp_PciDevice_DeviceType_PciExpressRootComplexIntegratedEndpoint = 4
%DevProp_PciDevice_DeviceType_PciExpressTreatedAsPci                  = 5
%DevProp_PciDevice_BridgeType_PciConventional                         = 6
%DevProp_PciDevice_BridgeType_PciX                                    = 7
%DevProp_PciDevice_BridgeType_PciExpressRootPort                      = 8
%DevProp_PciDevice_BridgeType_PciExpressUpstreamSwitchPort            = 9
%DevProp_PciDevice_BridgeType_PciExpressDownstreamSwitchPort          = 10
%DevProp_PciDevice_BridgeType_PciExpressToPciXBridge                  = 11
%DevProp_PciDevice_BridgeType_PciXToExpressBridge                     = 12
%DevProp_PciDevice_BridgeType_PciExpressTreatedAsPci                  = 13

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_DeviceType, 1);
MACRO DEVPKEY_PciDevice_DeviceType = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(1)


'//
'// This property is valid for conventional PCI or PCI-X devices.
'// For conventional PCI devices, the speed/mode is described by the following
'// fields.
'//

%DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_33MHz = 0
%DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_66MHz = 1

'//
'// For PCI-X devices, the speed/mode is encoded in the following fashion.
'//

%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode_Conventional_Pci = &H0
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_66Mhz           = &H1
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_100Mhz          = &H2
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_133MHZ          = &H3
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_66Mhz       = &H5
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_100Mhz      = &H6
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_133Mhz      = &H7
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_66MHz       = &H9
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_100MHz      = &HA
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_133MHz      = &HB
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_66MHz       = &HD
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_100MHz      = &HE
%DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_133MHz      = &HF

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentSpeedAndMode, 2);
MACRO DEVPKEY_PciDevice_CurrentSpeedAndMode = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(2)

'//
'// The BaseClass, SubClass and ProgIf fields are valid for all PCI devices.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_BaseClass, 3);
MACRO DEVPKEY_PciDevice_BaseClass = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(3)

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_SubClass, 4);
MACRO DEVPKEY_PciDevice_SubClass = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(4)

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ProgIf, 5);
MACRO DEVPKEY_PciDevice_ProgIf = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(5)

'//
'// This property describes the current payload size in the transaction layer
'// for a PCI Express device. The encodings for this field are described below.
'//

%DevProp_PciExpressDevice_PayloadOrRequestSize_128Bytes  = 0
%DevProp_PciExpressDevice_PayloadOrRequestSize_256Bytes  = 1
%DevProp_PciExpressDevice_PayloadOrRequestSize_512Bytes  = 2
%DevProp_PciExpressDevice_PayloadOrRequestSize_1024Bytes = 3
%DevProp_PciExpressDevice_PayloadOrRequestSize_2048Bytes = 4
%DevProp_PciExpressDevice_PayloadOrRequestSize_4096Bytes = 5

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentPayloadSize, 6);
MACRO DEVPKEY_PciDevice_CurrentPayloadSize = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(6)

'//
'// This property describes the maximum payload size supported by an express
'// device/function. The encodings are described above.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxPayloadSize, 7);
MACRO DEVPKEY_PciDevice_MaxPayloadSize = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(7)

'//
'// This property describes the maximum read request size for an express device.
'// The encoding for this field are given above.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxReadRequestSize, 8);
MACRO DEVPKEY_PciDevice_MaxReadRequestSize = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(8)

'//
'// This property is applicable to an express device with an express link. It
'// describes the current link speed for the device. The encodings are defined
'// as follows.
'//

%DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps = 1
%DevProp_PciExpressDevice_LinkSpeed_Five_Gbps       = 2

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentLinkSpeed, 9);
MACRO DEVPKEY_PciDevice_CurrentLinkSpeed = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(9)

'//
'// This property is applicable to an express device with an express link. It
'// describes the current link width whose encoding is as follows.
'//

%DevProp_PciExpressDevice_LinkWidth_By_1  = 1
%DevProp_PciExpressDevice_LinkWidth_By_2  = 2
%DevProp_PciExpressDevice_LinkWidth_By_4  = 4
%DevProp_PciExpressDevice_LinkWidth_By_8  = 8
%DevProp_PciExpressDevice_LinkWidth_By_12 = 12
%DevProp_PciExpressDevice_LinkWidth_By_16 = 16
%DevProp_PciExpressDevice_LinkWidth_By_32 = 32

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentLinkWidth, 10);
MACRO DEVPKEY_PciDevice_CurrentLinkWidth = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(10)

'//
'// This property describes the maximum link speed of an express link for an
'// express device. The encodings for this field are:
'//

%DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps = 1

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxLinkSpeed, 11);
MACRO DEVPKEY_PciDevice_MaxLinkSpeed = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(11)

'//
'// This property describes the maximum link width implemented by an express
'// link for an express devce. The encodings are same as described above.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxLinkWidth, 12);
MACRO DEVPKEY_PciDevice_MaxLinkWidth = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(12)

'//
'// This property describes the specification version to which an express device
'// was built.  The encodings for this field are:
'//

%DevProp_PciExpressDevice_Spec_Version_10 = 1
%DevProp_PciExpressDevice_Spec_Version_11 = 2

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ExpressSpecVersion, 13);
MACRO DEVPKEY_PciDevice_ExpressSpecVersion = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(13)

'//
'// This property describes the hardware support for interrupts on the device.
'// It is a bitmask of supported interrupt types, with the following values:
'//

%DevProp_PciDevice_InterruptType_LineBased = 1
%DevProp_PciDevice_InterruptType_Msi       = 2
%DevProp_PciDevice_InterruptType_MsiX      = 4

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_InterruptSupport, 14);
MACRO DEVPKEY_PciDevice_InterruptSupport = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(14)

'//
'// This property describes the number of message interrupts a device supports
'// in hardware.  This property is only valid if the device supports message
'// interrupts.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_InterruptMessageMaximum, 15);
MACRO DEVPKEY_PciDevice_InterruptMessageMaximum = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(15)

'//
'// This property describes the number of Base Address Registers of various types
'// supported by the device hardware.  The property data is a 32 bit value
'// interpreted by the following macros:
'//

'#define DevProp_PciDevice_IoBarCount(_PropertyData)                             ((_PropertyData) & 0xFF)
'#define DevProp_PciDevice_NonPrefetchable_MemoryBarCount(_PropertyData)         (((_PropertyData) >> 8) & 0xFF)
'#define DevProp_PciDevice_32BitPrefetchable_MemoryBarCount(_PropertyData)       (((_PropertyData) >> 16) & 0xFF)
'#define DevProp_PciDevice_64BitPrefetchable_MemoryBarCount(_PropertyData)       (((_PropertyData) >> 24) & 0xFF)

FUNCTION DevProp_PciDevice_IoBarCount(BYVAL m_PropertyData AS DWORD) AS DWORD
   FUNCTION = (m_PropertyData AND &HFF)
END FUNCTION

FUNCTION DevProp_PciDevice_NonPrefetchable_MemoryBarCount(BYVAL m_PropertyData AS DWORD) AS DWORD
   SHIFT RIGHT m_PropertyData, 8
   FUNCTION = m_PropertyData OR &HFF
END FUNCTION

FUNCTION DevProp_PciDevice_32BitPrefetchable_MemoryBarCount(BYVAL m_PropertyData AS DWORD) AS DWORD
   SHIFT RIGHT m_PropertyData, 16
   FUNCTION = m_PropertyData OR &HFF
END FUNCTION

FUNCTION DevProp_PciDevice_64BitPrefetchable_MemoryBarCount(BYVAL m_PropertyData AS DWORD) AS DWORD
   SHIFT RIGHT m_PropertyData, 24
   FUNCTION = m_PropertyData OR &HFF
END FUNCTION

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_BarTypes, 16);
MACRO DEVPKEY_PciDevice_BarTypes = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(16)

'//
'// This property is a BOOLEAN indicating if AER capability is present on an
'// endpoint.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AERCapabilityPresent, 17);
MACRO DEVPKEY_PciDevice_AERCapabilityPresent = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(17)

'//
'// This property indicates if a device is configured for a firmware first
'// error handling.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_FirmwareErrorHandling, 18);
MACRO DEVPKEY_PciDevice_FirmwareErrorHandling = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(18)

'//
'// This property provides the uncorrectable error mask for an endpoint. This
'// field is interpreted in accordance to its definition in the PCI Express
'// Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Uncorrectable_Error_Mask, 19);
MACRO DEVPKEY_PciDevice_Uncorrectable_Error_Mask = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(19)

'//
'// This property provides the uncorrectable error severity for an endpoint.
'// This field is interpreted in accordance to its definition in the PCI Express
'// Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Uncorrectable_Error_Severity, 20);
MACRO DEVPKEY_PciDevice_Uncorrectable_Error_Severity = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(20)

'//
'// This property provides the correctable error mask for an endpoint. This
'// field is interpreted in accordance to its definition in the PCI Express
'// Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Correctable_Error_Mask, 21);
MACRO DEVPKEY_PciDevice_Correctable_Error_Mask = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(21)

'//
'// This property indicates if a device is capable of ECRC generation and
'// checking. This field is interpreted in according to the advanced error
'// capabilities and control register value in the PCI Express Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ECRC_Errors, 22);
MACRO DEVPKEY_PciDevice_ECRC_Errors = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(22)

'//
'// This property indicates if an endpoint is enabled for reporting different
'// types of error messages. This field is interpreted in accordance to the
'// device control register value as described in the PCI Express Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Error_Reporting, 23);
MACRO DEVPKEY_PciDevice_Error_Reporting = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(23)

'//
'// This property indicates if a root port is enabled for reporting different
'// types of error messages. This field is interpreted in accordance to the
'// root control register value as described in the PCI Express Base spec.
'//

'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_RootError_Reporting, 24);
MACRO DEVPKEY_PciDevice_RootError_Reporting = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(24)

'//
'// This property indicates if a device can wake up via PME while the system is
'// in S0.  Some platforms do not support runtime wakeup on some device types.
'//
'DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_S0WakeupSupported, 25);
MACRO DEVPKEY_PciDevice_S0WakeupSupported = GUID$("{3AB22E31-8264-4B4E-9AF5-A8D2D8E33E62}") & MKDWD$(25)
