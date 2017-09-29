' ########################################################################################
' Microsoft Windows
' File: NtDDNdis.inc
' Contents: Constants and types for accessing the Network driver interface device.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTDDNDIS_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "winioctl.inc"

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'#include <ifdef.h>
'#include <devpkey.h>
'#include <pciprop.h>
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#INCLUDE ONCE "ifdef.inc"
#INCLUDE ONCE "devpkey.inc"
#INCLUDE ONCE "pciprop.inc"

'//
'// Something to identify new (Win7 and up) applications.
'// User-mode only. For drivers, NDIS_SUPPORT_NDIS620 is already
'// defined in ndismain.w.
'//
'#if !defined(NDIS_SUPPORT_NDIS620)
'#if  (defined (UM_NDIS620))
'#define NDIS_SUPPORT_NDIS620      1
'#else
'#define NDIS_SUPPORT_NDIS620      0
'#endif
'#endif // !defined(NDIS_SUPPORT_NDIS620)

'#IF NOT %DEF(%NDIS_SUPPORT_NDIS620)
'%NDIS_SUPPORT_NDIS620 = 1
'#ENDIF

'//
'// Something to identify new (LH Server and up) applications.
'// User-mode only. For drivers, NDIS_SUPPORT_NDIS61 is already
'// defined in ndismain.w.
'//
'#if !defined(NDIS_SUPPORT_NDIS61)
'#if  (defined (UM_NDIS61) || defined (UM_NDIS620))
'#define NDIS_SUPPORT_NDIS61      1
'#else
'#define NDIS_SUPPORT_NDIS61      0
'#endif
'#endif // !defined(NDIS_SUPPORT_NDIS61)

'#IF NOT %DEF(%NDIS_SUPPORT_NDIS61)
'%NDIS_SUPPORT_NDIS61 = 1
'#ENDIF

'//
'// Device Name - this string is the name of the device. It is the name
'// that should be passed to NtOpenFile when accessing the device.

'//
'// Note: For devices that support multiple units, it should be suffixed
'//       with the Ascii representation of the unit number.
'//

'#define DD_NDIS_DEVICE_NAME "\\Device\\UNKNOWN"
$DD_NDIS_DEVICE_NAME = "\Device\UNKNOWN"


'//
'// NtDeviceIoControlFile IoControlCode values for this device.
'//
'// Warning: Remember that the low two bits of the code specify how the
'//          buffers are passed to the driver!
'//

'#define _NDIS_CONTROL_CODE(request,method) \
'            CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, request, method, FILE_ANY_ACCESS)
FUNCTION NDIS_CONTROL_CODE(BYVAL dwRequest AS DWORD, BYVAL dwMethod AS DWORD) AS DWORD
   FUNCTION = CTL_CODE(%FILE_DEVICE_PHYSICAL_NETCARD, dwRequest, dwMethod, %FILE_ANY_ACCESS)
END FUNCTION

%IOCTL_NDIS_QUERY_GLOBAL_STATS   = &H00170002???   ' _NDIS_CONTROL_CODE(0, METHOD_OUT_DIRECT)
%IOCTL_NDIS_QUERY_ALL_STATS      = &H00170006???   ' _NDIS_CONTROL_CODE(1, METHOD_OUT_DIRECT)
%IOCTL_NDIS_DO_PNP_OPERATION     = &H00170008???   ' _NDIS_CONTROL_CODE(2, METHOD_BUFFERED)
%IOCTL_NDIS_QUERY_SELECTED_STATS = &H0017000E???   ' _NDIS_CONTROL_CODE(3, METHOD_OUT_DIRECT)
%IOCTL_NDIS_ENUMERATE_INTERFACES = &H00170010???   ' _NDIS_CONTROL_CODE(4, METHOD_BUFFERED)
%IOCTL_NDIS_ADD_TDI_DEVICE       = &H00170014???   ' _NDIS_CONTROL_CODE(5, METHOD_BUFFERED)
%IOCTL_NDIS_GET_LOG_DATA         = &H0017001E???   ' _NDIS_CONTROL_CODE(7, METHOD_OUT_DIRECT)
%IOCTL_NDIS_GET_VERSION          = &H00170020???   ' _NDIS_CONTROL_CODE(8, METHOD_BUFFERED)

%IOCTL_NDIS_RESERVED1            = &H00170024???   ' _NDIS_CONTROL_CODE(9, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED2            = &H00170028???   ' _NDIS_CONTROL_CODE(0xA, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED3            = &H0017002C???   ' _NDIS_CONTROL_CODE(0xB, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED4            = &H00170030???   ' _NDIS_CONTROL_CODE(0xC, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED5            = &H00170034???   ' CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, 0xD, METHOD_BUFFERED, FILE_ANY_ACCESS)
%IOCTL_NDIS_RESERVED6            = &H00178038???   ' CTL_CODE(FILE_DEVICE_PHYSICAL_NETCARD, 0xE, METHOD_BUFFERED, FILE_WRITE_ACCESS)
%IOCTL_NDIS_RESERVED7            = &H0017003E???   ' _NDIS_CONTROL_CODE(0xF, METHOD_OUT_DIRECT)
%IOCTL_NDIS_RESERVED8            = &H00170040???   ' _NDIS_CONTROL_CODE(0x10, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED9            = &H00170044???   ' _NDIS_CONTROL_CODE(0x11, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED10           = &H00170048???   ' _NDIS_CONTROL_CODE(0x12, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED11           = &H0017004C???   ' _NDIS_CONTROL_CODE(0x13, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED12           = &H00170050???   ' _NDIS_CONTROL_CODE(0x14, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED13           = &H00170054???   ' _NDIS_CONTROL_CODE(0x15, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED14           = &H00170058???   ' _NDIS_CONTROL_CODE(0x16, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED15           = &H0017005C???   ' _NDIS_CONTROL_CODE(0x17, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED16           = &H00170060???   ' _NDIS_CONTROL_CODE(0x18, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED17           = &H00170064???   ' _NDIS_CONTROL_CODE(0x19, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED18           = &H00170068???   ' _NDIS_CONTROL_CODE(0x1A, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED19           = &H0017006C???   ' _NDIS_CONTROL_CODE(0x1B, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED20           = &H00170070???   ' _NDIS_CONTROL_CODE(0x1C, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED21           = &H00170074???   ' _NDIS_CONTROL_CODE(0x1D, METHOD_BUFFERED)
%IOCTL_NDIS_RESERVED22           = &H00170078???   ' _NDIS_CONTROL_CODE(0x1E, METHOD_BUFFERED)

'//
'// NtDeviceIoControlFile InputBuffer/OutputBuffer record structures for
'// this device.
'//

'//
'// This is the type of an NDIS OID value.
'//

'typedef ULONG NDIS_OID, *PNDIS_OID;

'//
'// IOCTL_NDIS_QUERY_ALL_STATS returns a sequence of these, packed
'// together.  This structure is unaligned because not all statistics
'// have a length that is a ULONG multiple.
'//

UNION NDIS_STATISTICS_VALUE_DATA_UNION
   Data(0)    AS BYTE    ' UCHAR  // variable length
   ' // For compatibility with the PB declares
   bData(0)   AS BYTE    ' UCHAR  // variable length
END UNION

' // Size = 12 bytes
TYPE NDIS_STATISTICS_VALUE DWORD
   Oid        AS DWORD   ' NDIS_OID
   DataLength AS DWORD   ' ULONG
   NDIS_STATISTICS_VALUE_DATA_UNION
END TYPE

'typedef NDIS_STATISTICS_VALUE UNALIGNED *PNDIS_STATISTICS_VALUE;

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
UNION NDIS_STATISTICS_VALUE_EX_DATA_UNION
   Data(0)    AS BYTE    ' UCHAR  // variable length
   ' // For compatibility with the PB declares
   bData(0)   AS BYTE    ' UCHAR  // variable length
END UNION

' // Size = 16 bytes
TYPE NDIS_STATISTICS_VALUE_EX DWORD
   Oid        AS DWORD   ' NDIS_OID
   DataLength AS DWORD   ' ULONG // the length of the OID data
   Length     AS DWORD   ' ULONG // the length of this instance of NDIS_STATISTICS_VALUE_EX
   NDIS_STATISTICS_VALUE_EX_DATA_UNION
END TYPE
'typedef NDIS_STATISTICS_VALUE_EX UNALIGNED *PNDIS_STATISTICS_VALUE_EX;
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)


'//
'// Structure used to define a self-contained variable data structure
'//
' // Size = 8 bytes
TYPE NDIS_VAR_DATA_DESC WORD
   Length        AS WORD    ' USHORT // # of octects of data
   MaximumLength AS WORD    ' USHORT // # of octects available
   Offset        AS DWORD   ' ULONG_PTR // Offset of data relative to the descriptor
END TYPE

#IF NOT %DEF(%GUID_DEFINED)
#INCLUDE ONCE "guiddef.inc"
#ENDIF ' // !GUID_DEFINED

'//
'// NDIS Object Types used in NDIS_OBJECT_HEADER
'//
%NDIS_OBJECT_TYPE_DEFAULT                                          = &H80   ' // used when object type is implicit in the API call
%NDIS_OBJECT_TYPE_MINIPORT_INIT_PARAMETERS                         = &H81   ' // used by NDIS in NDIS_MINIPORT_INIT_PARAMETERS
%NDIS_OBJECT_TYPE_SG_DMA_DESCRIPTION                               = &H83   ' // used by miniport drivers in NDIS_SG_DMA_DESCRIPTION
%NDIS_OBJECT_TYPE_MINIPORT_INTERRUPT                               = &H84   ' // used by miniport drivers in NDIS_MINIPORT_INTERRUPT_EX
%NDIS_OBJECT_TYPE_DEVICE_OBJECT_ATTRIBUTES                         = &H85   ' // used by miniport or filter drivers in NDIS_DEVICE_OBJECT_ATTRIBUTES
%NDIS_OBJECT_TYPE_BIND_PARAMETERS                                  = &H86   ' // used by NDIS in NDIS_BIND_PARAMETERS
%NDIS_OBJECT_TYPE_OPEN_PARAMETERS                                  = &H87   ' // used by protocols in NDIS_OPEN_PARAMETERS
%NDIS_OBJECT_TYPE_RSS_CAPABILITIES                                 = &H88   ' // used by miniport in NDIS_RECEIVE_SCALE_CAPABILITIES
%NDIS_OBJECT_TYPE_RSS_PARAMETERS                                   = &H89   ' // used by miniport and protocol in NDIS_RECEIVE_SCALE_PARAMETERS
%NDIS_OBJECT_TYPE_MINIPORT_DRIVER_CHARACTERISTICS                  = &H8A
%NDIS_OBJECT_TYPE_FILTER_DRIVER_CHARACTERISTICS                    = &H8B
%NDIS_OBJECT_TYPE_FILTER_PARTIAL_CHARACTERISTICS                   = &H8C
%NDIS_OBJECT_TYPE_FILTER_ATTRIBUTES                                = &H8D
%NDIS_OBJECT_TYPE_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS   = &H8E
%NDIS_OBJECT_TYPE_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS = &H8F
%NDIS_OBJECT_TYPE_CO_PROTOCOL_CHARACTERISTICS                      = &H90
%NDIS_OBJECT_TYPE_CO_MINIPORT_CHARACTERISTICS                      = &H91
%NDIS_OBJECT_TYPE_MINIPORT_PNP_CHARACTERISTICS                     = &H92
%NDIS_OBJECT_TYPE_CLIENT_CHIMNEY_OFFLOAD_CHARACTERISTICS           = &H93
%NDIS_OBJECT_TYPE_PROVIDER_CHIMNEY_OFFLOAD_CHARACTERISTICS         = &H94
%NDIS_OBJECT_TYPE_PROTOCOL_DRIVER_CHARACTERISTICS                  = &H95
%NDIS_OBJECT_TYPE_REQUEST_EX                                       = &H96
%NDIS_OBJECT_TYPE_OID_REQUEST                                      = &H96
%NDIS_OBJECT_TYPE_TIMER_CHARACTERISTICS                            = &H97
%NDIS_OBJECT_TYPE_STATUS_INDICATION                                = &H98
%NDIS_OBJECT_TYPE_FILTER_ATTACH_PARAMETERS                         = &H99
%NDIS_OBJECT_TYPE_FILTER_PAUSE_PARAMETERS                          = &H9A
%NDIS_OBJECT_TYPE_FILTER_RESTART_PARAMETERS                        = &H9B
%NDIS_OBJECT_TYPE_PORT_CHARACTERISTICS                             = &H9C
%NDIS_OBJECT_TYPE_PORT_STATE                                       = &H9D
%NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES         = &H9E
%NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES              = &H9F
%NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES              = &HA0
%NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES        = &HA1
%NDIS_OBJECT_TYPE_RESTART_GENERAL_ATTRIBUTES                       = &HA2
%NDIS_OBJECT_TYPE_PROTOCOL_RESTART_PARAMETERS                      = &HA3
%NDIS_OBJECT_TYPE_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES      = &HA4
%NDIS_OBJECT_TYPE_CO_CALL_MANAGER_OPTIONAL_HANDLERS                = &HA5
%NDIS_OBJECT_TYPE_CO_CLIENT_OPTIONAL_HANDLERS                      = &HA6
%NDIS_OBJECT_TYPE_OFFLOAD                                          = &HA7
%NDIS_OBJECT_TYPE_OFFLOAD_ENCAPSULATION                            = &HA8
%NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT                             = &HA9
%NDIS_OBJECT_TYPE_DRIVER_WRAPPER_OBJECT                            = &HAA
'#IF %NDIS_SUPPORT_NDIS61
%NDIS_OBJECT_TYPE_HD_SPLIT_ATTRIBUTES                              = &HAB
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)
%NDIS_OBJECT_TYPE_NSI_NETWORK_RW_STRUCT                            = &HAC
%NDIS_OBJECT_TYPE_NSI_COMPARTMENT_RW_STRUCT                        = &HAD
%NDIS_OBJECT_TYPE_NSI_INTERFACE_PERSIST_RW_STRUCT                  = &HAE
'#IF %NDIS_SUPPORT_NDIS61
%NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES      = &HAF
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)
'#IF %NDIS_SUPPORT_NDIS620
%NDIS_OBJECT_TYPE_SHARED_MEMORY_PROVIDER_CHARACTERISTICS           = &HB0
%NDIS_OBJECT_TYPE_RSS_PROCESSOR_INFO                               = &HB1
'#ENDIF   ' // (NDIS_SUPPORT_NDIS620)

UNION NDIS_OBJECT_HEADER_TYPE_UNION
   Type     AS BYTE   ' UCHAR
   ' // For compatibility with the PB declares
   bType    AS BYTE   ' UCHAR
END UNION

' // Size = 4 bytes
TYPE NDIS_OBJECT_HEADER BYTE
   NDIS_OBJECT_HEADER_TYPE_UNION
   Revision AS BYTE   ' UCHAR
   Size     AS WORD   ' USHORT
END TYPE

%NDIS_OBJECT_REVISION_1 = 1

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)

'//
'// flags for NDIS_STATISTICS_INFO->SupportedStatistics structure
'//
%NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_RCV             = &H00000001???
%NDIS_STATISTICS_FLAGS_VALID_MULTICAST_FRAMES_RCV            = &H00000002???
%NDIS_STATISTICS_FLAGS_VALID_BROADCAST_FRAMES_RCV            = &H00000004???
%NDIS_STATISTICS_FLAGS_VALID_BYTES_RCV                       = &H00000008???
%NDIS_STATISTICS_FLAGS_VALID_RCV_DISCARDS                    = &H00000010???
%NDIS_STATISTICS_FLAGS_VALID_RCV_ERROR                       = &H00000020???
%NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_XMIT            = &H00000040???
%NDIS_STATISTICS_FLAGS_VALID_MULTICAST_FRAMES_XMIT           = &H00000080???
%NDIS_STATISTICS_FLAGS_VALID_BROADCAST_FRAMES_XMIT           = &H00000100???
%NDIS_STATISTICS_FLAGS_VALID_BYTES_XMIT                      = &H00000200???
%NDIS_STATISTICS_FLAGS_VALID_XMIT_ERROR                      = &H00000400???
%NDIS_STATISTICS_FLAGS_VALID_XMIT_DISCARDS                   = &H00008000???
%NDIS_STATISTICS_FLAGS_VALID_DIRECTED_BYTES_RCV              = &H00010000???
%NDIS_STATISTICS_FLAGS_VALID_MULTICAST_BYTES_RCV             = &H00020000???
%NDIS_STATISTICS_FLAGS_VALID_BROADCAST_BYTES_RCV             = &H00040000???
%NDIS_STATISTICS_FLAGS_VALID_DIRECTED_BYTES_XMIT             = &H00080000???
%NDIS_STATISTICS_FLAGS_VALID_MULTICAST_BYTES_XMIT            = &H00100000???
%NDIS_STATISTICS_FLAGS_VALID_BROADCAST_BYTES_XMIT            = &H00200000???


%NDIS_STATISTICS_INFO_REVISION_1 = 1
'//
'// structure used in OID_GEN_STATISTICS
'//
' // Size = 152 bytes
TYPE NDIS_STATISTICS_INFO QWORD FILL
   Header                 AS NDIS_OBJECT_HEADER
   SupportedStatistics    AS DWORD   ' ULONG
   ifInDiscards           AS QUAD    ' ULONG64   // OID_GEN_RCV_ERROR + OID_GEN_RCV_NO_BUFFER = OID_GEN_RCV_DISCARDS
   ifInErrors             AS QUAD    ' ULONG64   // OID_GEN_RCV_ERROR
   ifHCInOctets           AS QUAD    ' ULONG64   // OID_GEN_BYTES_RCV = OID_GEN_DIRECTED_BYTES_RCV + OID_GEN_MULTICAST_BYTES_RCV + OID_GEN_BROADCAST_BYTES_RCV
   ifHCInUcastPkts        AS QUAD    ' ULONG64   // OID_GEN_DIRECTED_FRAMES_RCV
   ifHCInMulticastPkts    AS QUAD    ' ULONG64   // OID_GEN_MULTICAST_FRAMES_RCV
   ifHCInBroadcastPkts    AS QUAD    ' ULONG64   // OID_GEN_BROADCAST_FRAMES_RCV
   ifHCOutOctets          AS QUAD    ' ULONG64   // OID_GEN_BYTES_XMIT = OID_GEN_DIRECTED_BYTES_XMIT + OID_GEN_MULTICAST_BYTES_XMIT + OID_GEN_BROADCAST_BYTES_XMIT
   ifHCOutUcastPkts       AS QUAD    ' ULONG64   // OID_GEN_DIRECTED_FRAMES_XMIT
   ifHCOutMulticastPkts   AS QUAD    ' ULONG64   // OID_GEN_MULTICAST_FRAMES_XMIT
   ifHCOutBroadcastPkts   AS QUAD    ' ULONG64   // OID_GEN_BROADCAST_FRAMES_XMIT
   ifOutErrors            AS QUAD    ' ULONG64   // OID_GEN_XMIT_ERROR
   ifOutDiscards          AS QUAD    ' ULONG64   // OID_GEN_XMIT_DISCARDS
   ifHCInUcastOctets      AS QUAD    ' ULONG64   // OID_GEN_DIRECTED_BYTES_RCV
   ifHCInMulticastOctets  AS QUAD    ' ULONG64   // OID_GEN_MULTICAST_BYTES_RCV
   ifHCInBroadcastOctets  AS QUAD    ' ULONG64   // OID_GEN_BROADCAST_BYTES_RCV
   ifHCOutUcastOctets     AS QUAD    ' ULONG64   // OID_GEN_DIRECTED_BYTES_XMIT
   ifHCOutMulticastOctets AS QUAD    ' ULONG64   // OID_GEN_MULTICAST_BYTES_XMIT
   ifHCOutBroadcastOctets AS QUAD    ' ULONG64   // OID_GEN_BROADCAST_BYTES_XMIT
END TYPE

'#define NDIS_SIZEOF_STATISTICS_INFO_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_STATISTICS_INFO, ifHCOutBroadcastOctets)
'//
'//  interrupt moderation structures and definitions
'//

'//
'// enum value used in NDIS_INTERRUPT_MODERATION_PARAMETERS structure
'//
' enum NDIS_INTERRUPT_MODERATION
%NdisInterruptModerationUnknown      = 0
%NdisInterruptModerationNotSupported = 1
%NdisInterruptModerationEnabled      = 2
%NdisInterruptModerationdisabled     = 3

'//
'// Bits used in Flags parameter of NDIS_INTERRUPT_MODERATION_PARAMETERS structure:
'//
%NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_RESET        = &H00000001???
%NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_REINITIALIZE = &H00000002???


'//
'// structure used in OID_GEN_INTERRUPT_MODERATION
'//

%NDIS_INTERRUPT_MODERATION_PARAMETERS_REVISION_1 = 1

' // Size = 12 bytes
TYPE NDIS_INTERRUPT_MODERATION_PARAMETERS DWORD
   Header              AS NDIS_OBJECT_HEADER
   Flags               AS DWORD                ' ULONG
   InterruptModeration AS LONG                 ' NDIS_INTERRUPT_MODERATION
END TYPE

'#define NDIS_SIZEOF_INTERRUPT_MODERATION_PARAMETERS_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_INTERRUPT_MODERATION_PARAMETERS, InterruptModeration)

'//
'// structure used in OID_GEN_TIMEOUT_DPC_REQUEST_CAPABILITIES
'//

%NDIS_TIMEOUT_DPC_REQUEST_CAPABILITIES_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_TIMEOUT_DPC_REQUEST_CAPABILITIES DWORD
   Header             AS NDIS_OBJECT_HEADER
   Flags              AS DWORD                ' ULONG
   TimeoutArrayLength AS DWORD                ' ULONG
   TimeoutArray(0)    AS DWORD                ' ULONG
END TYPE

'#define NDIS_SIZEOF_TIMEOUT_DPC_REQUEST_CAPABILITIES_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_TIMEOUT_DPC_REQUEST_CAPABILITIES, TimeoutArray)

'//
'// PCI custom properties. used in OID_GEN_PCI_DEVICE_CUSTOM_PROPERTIES
'//

%NDIS_OBJECT_TYPE_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_1 = 1

'#if ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)
%NDIS_OBJECT_TYPE_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_2 = 2
'#endif

' // Size = 52 bytes
TYPE NDIS_PCI_DEVICE_CUSTOM_PROPERTIES DWORD
   Header               AS NDIS_OBJECT_HEADER
   DeviceType           AS DWORD   ' UINT32 // conventional, PCI-X, PCI-E, etc.
   CurrentSpeedAndMode  AS DWORD   ' UINT32 // PCI_DEVICE_CONVENTIONAL_xx or PCIX_MODExxx. valid only for conventional and PCI-X devices
   CurrentPayloadSize   AS DWORD   ' UINT32 // PCI_EXPRESS_MAX_PAYLOAD_SIZE, valid only for PCI-E devices
   MaxPayloadSize       AS DWORD   ' UINT32 // PCI_EXPRESS_MAX_PAYLOAD_SIZE, valid only for PCI-E devices
   MaxReadRequestSize   AS DWORD   ' UINT32 // PCI_EXPRESS_MAX_PAYLOAD_SIZE, valid only for PCI-E devices
   CurrentLinkSpeed     AS DWORD   ' UINT32 // PCI_EXPRESS_LINK_SPEED_xxx. valid only for PCI-E devices
   CurrentLinkWidth     AS DWORD   ' UINT32 // PCI_EXPRESS_LINK_WIDTH_xx. valid only for PCI-E devices
   MaxLinkSpeed         AS DWORD   ' UINT32 // PCI_EXPRESS_LINK_SPEED_xxx. valid only for PCI-E devices
   MaxLinkWidth         AS DWORD   ' UINT32 // PCI_EXPRESS_LINK_WIDTH_xx. valid only for PCI-E devices
'#if ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)
   PciExpressVersion    AS DWORD   ' UINT32 // DevProp_PciExpressDevice_Spec_Version_xx, valid for PCI -E devices
   InterruptType        AS DWORD   ' UINT32 // DevProp_PciDevice_InterruptType_xx
   MaxInterruptMessages AS DWORD   ' UINT32
'#endif
END TYPE

'#define NDIS_SIZEOF_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PCI_DEVICE_CUSTOM_PROPERTIES, MaxLinkWidth)

'#if ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)
'#define NDIS_SIZEOF_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_2    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PCI_DEVICE_CUSTOM_PROPERTIES, MaxInterruptMessages)
'#endif

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// General Objects
'//

'//
'//  Required OIDs
'//
%OID_GEN_SUPPORTED_LIST                  = &H00010101???
%OID_GEN_HARDWARE_STATUS                 = &H00010102???
%OID_GEN_MEDIA_SUPPORTED                 = &H00010103???
%OID_GEN_MEDIA_IN_USE                    = &H00010104???
%OID_GEN_MAXIMUM_LOOKAHEAD               = &H00010105???
%OID_GEN_MAXIMUM_FRAME_SIZE              = &H00010106???
%OID_GEN_LINK_SPEED                      = &H00010107???
%OID_GEN_TRANSMIT_BUFFER_SPACE           = &H00010108???
%OID_GEN_RECEIVE_BUFFER_SPACE            = &H00010109???
%OID_GEN_TRANSMIT_BLOCK_SIZE             = &H0001010A???
%OID_GEN_RECEIVE_BLOCK_SIZE              = &H0001010B???
%OID_GEN_VENDOR_ID                       = &H0001010C???
%OID_GEN_VENDOR_DESCRIPTION              = &H0001010D???
%OID_GEN_CURRENT_PACKET_FILTER           = &H0001010E???
%OID_GEN_CURRENT_LOOKAHEAD               = &H0001010F???
%OID_GEN_DRIVER_VERSION                  = &H00010110???
%OID_GEN_MAXIMUM_TOTAL_SIZE              = &H00010111???
%OID_GEN_PROTOCOL_OPTIONS                = &H00010112???
%OID_GEN_MAC_OPTIONS                     = &H00010113???
%OID_GEN_MEDIA_CONNECT_STATUS            = &H00010114???
%OID_GEN_MAXIMUM_SEND_PACKETS            = &H00010115???

'//
'//  Optional OIDs
'//
%OID_GEN_VENDOR_DRIVER_VERSION           = &H00010116???
%OID_GEN_SUPPORTED_GUIDS                 = &H00010117???
%OID_GEN_NETWORK_LAYER_ADDRESSES         = &H00010118???  ' // Set only
%OID_GEN_TRANSPORT_HEADER_OFFSET         = &H00010119???  ' // Set only
%OID_GEN_MEDIA_CAPABILITIES              = &H00010201???
%OID_GEN_PHYSICAL_MEDIUM                 = &H00010202???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'//
'// new optional for NDIS 6.0
'//
%OID_GEN_RECEIVE_SCALE_CAPABILITIES      = &H00010203???  ' // query only
%OID_GEN_RECEIVE_SCALE_PARAMETERS        = &H00010204???  ' // query and set

'//
'// new for NDIS 6.0. NDIS will handle on behalf of the miniports
'//
%OID_GEN_MAC_ADDRESS                     = &H00010205???  ' // query and set
%OID_GEN_MAX_LINK_SPEED                  = &H00010206???  ' // query only
%OID_GEN_LINK_STATE                      = &H00010207???  ' // query only

'//
'// new and required for NDIS 6 miniports
'//
%OID_GEN_LINK_PARAMETERS                 = &H00010208???  ' // set only
%OID_GEN_INTERRUPT_MODERATION            = &H00010209???  ' // query and set
%OID_GEN_NDIS_RESERVED_3                 = &H0001020A???
%OID_GEN_NDIS_RESERVED_4                 = &H0001020B???
%OID_GEN_NDIS_RESERVED_5                 = &H0001020C???


'//
'// Port related OIDs
'//
%OID_GEN_ENUMERATE_PORTS                 = &H0001020D???  ' // query only, handled by NDIS
%OID_GEN_PORT_STATE                      = &H0001020E???  ' // query only, handled by NDIS
%OID_GEN_PORT_AUTHENTICATION_PARAMETERS  = &H0001020F???  ' // Set only

'//
'// optional OID for NDIS 6 miniports
'//
%OID_GEN_TIMEOUT_DPC_REQUEST_CAPABILITIES = &H00010210???  ' // query only

'//
'// this OID is handled by NDIS for PCI devices
'//
%OID_GEN_PCI_DEVICE_CUSTOM_PROPERTIES    = &H00010211???  ' // query only
%OID_GEN_NDIS_RESERVED_6                 = &H00010212???
%OID_GEN_PHYSICAL_MEDIUM_EX              = &H00010213???  ' // query only


'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

%OID_GEN_MACHINE_NAME                    = &H0001021A???  ' // set only
%OID_GEN_RNDIS_CONFIG_PARAMETER          = &H0001021B???  ' // Set only
%OID_GEN_VLAN_ID                         = &H0001021C???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
%OID_GEN_RECEIVE_HASH                    = &H0001021F???  ' // query and set
%OID_GEN_MINIPORT_RESTART_ATTRIBUTES     = &H0001021D???

'#IF %NDIS_SUPPORT_NDIS61
'//
'// Optional OID for header data/split
'//
%OID_GEN_HD_SPLIT_PARAMETERS             = &H0001021E???   ' // Set only
%OID_GEN_HD_SPLIT_CURRENT_CONFIG         = &H00010220???   ' // Query only
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

'//
'// the following OIDs are used in querying interfaces
'//
%OID_GEN_PROMISCUOUS_MODE                = &H00010280???  ' // used in querying interfaces
%OID_GEN_LAST_CHANGE                     = &H00010281???  ' // used in querying interfaces
%OID_GEN_DISCONTINUITY_TIME              = &H00010282???  ' // used in querying interfaces
%OID_GEN_OPERATIONAL_STATUS              = &H00010283???  ' // used in querying interfaces
%OID_GEN_XMIT_LINK_SPEED                 = &H00010284???  ' // used in querying interfaces
%OID_GEN_RCV_LINK_SPEED                  = &H00010285???  ' // used in querying interfaces
%OID_GEN_UNKNOWN_PROTOS                  = &H00010286???  ' // used in querying interfaces
%OID_GEN_INTERFACE_INFO                  = &H00010287???  ' // used in querying interfaces
%OID_GEN_ADMIN_STATUS                    = &H00010288???  ' // used in querying interfaces
%OID_GEN_ALIAS                           = &H00010289???  ' // used in querying interfaces
%OID_GEN_MEDIA_CONNECT_STATUS_EX         = &H0001028A???  ' // used in querying interfaces
%OID_GEN_LINK_SPEED_EX                   = &H0001028B???  ' // used in querying interfaces
%OID_GEN_MEDIA_DUPLEX_STATE              = &H0001028C???  ' // used in querying interfaces
%OID_GEN_IP_OPER_STATUS                  = &H0001028D???  ' // used in querying interfaces

'//
'// WWAN specific oids
'//
%OID_WWAN_DRIVER_CAPS                    = &H0e010100???
%OID_WWAN_DEVICE_CAPS                    = &H0e010101???
%OID_WWAN_READY_INFO                     = &H0e010102???
%OID_WWAN_RADIO_STATE                    = &H0e010103???
%OID_WWAN_PIN                            = &H0e010104???
%OID_WWAN_PIN_LIST                       = &H0e010105???
%OID_WWAN_HOME_PROVIDER                  = &H0e010106???
%OID_WWAN_PREFERRED_PROVIDERS            = &H0e010107???
%OID_WWAN_VISIBLE_PROVIDERS              = &H0e010108???
%OID_WWAN_REGISTER_STATE                 = &H0e010109???
%OID_WWAN_PACKET_SERVICE                 = &H0e01010a???
%OID_WWAN_SIGNAL_STATE                   = &H0e01010b???
%OID_WWAN_CONNECT                        = &H0e01010c???
%OID_WWAN_PROVISIONED_CONTEXTS           = &H0e01010d???
%OID_WWAN_SERVICE_ACTIVATION             = &H0e01010e???
%OID_WWAN_SMS_CONFIGURATION              = &H0e01010f???
%OID_WWAN_SMS_READ                       = &H0e010110???
%OID_WWAN_SMS_SEND                       = &H0e010111???
%OID_WWAN_SMS_DELETE                     = &H0e010112???
%OID_WWAN_SMS_STATUS                     = &H0e010113???
%OID_WWAN_VENDOR_SPECIFIC                = &H0e010114???

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//
'//  Required statistics
'//
%OID_GEN_XMIT_OK                         = &H00020101???
%OID_GEN_RCV_OK                          = &H00020102???
%OID_GEN_XMIT_ERROR                      = &H00020103???
%OID_GEN_RCV_ERROR                       = &H00020104???
%OID_GEN_RCV_NO_BUFFER                   = &H00020105???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'//
'// mandatory for NDIS 6.0 and higher miniports
'//
%OID_GEN_STATISTICS                      = &H00020106???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//
'//  Optional statistics
'//
%OID_GEN_DIRECTED_BYTES_XMIT             = &H00020201???
%OID_GEN_DIRECTED_FRAMES_XMIT            = &H00020202???
%OID_GEN_MULTICAST_BYTES_XMIT            = &H00020203???
%OID_GEN_MULTICAST_FRAMES_XMIT           = &H00020204???
%OID_GEN_BROADCAST_BYTES_XMIT            = &H00020205???
%OID_GEN_BROADCAST_FRAMES_XMIT           = &H00020206???
%OID_GEN_DIRECTED_BYTES_RCV              = &H00020207???
%OID_GEN_DIRECTED_FRAMES_RCV             = &H00020208???
%OID_GEN_MULTICAST_BYTES_RCV             = &H00020209???
%OID_GEN_MULTICAST_FRAMES_RCV            = &H0002020A???
%OID_GEN_BROADCAST_BYTES_RCV             = &H0002020B???
%OID_GEN_BROADCAST_FRAMES_RCV            = &H0002020C???
%OID_GEN_RCV_CRC_ERROR                   = &H0002020D???
%OID_GEN_TRANSMIT_QUEUE_LENGTH           = &H0002020E???

%OID_GEN_GET_TIME_CAPS                   = &H0002020F???
%OID_GEN_GET_NETCARD_TIME                = &H00020210???
%OID_GEN_NETCARD_LOAD                    = &H00020211???
%OID_GEN_DEVICE_PROFILE                  = &H00020212???

'//
'// The following are exported by NDIS itself and are only queryable.
'//

'//
'// the time in milliseconds a driver took to initialize.
'//
%OID_GEN_INIT_TIME_MS                    = &H00020213???

'//
'// the number of times the miniport adapter was reset
'//
%OID_GEN_RESET_COUNTS                    = &H00020214???

'//
'// the number of timer the miniport reported a media state change
'//
%OID_GEN_MEDIA_SENSE_COUNTS              = &H00020215???

'//
'// the friendly name of the adapter
'//
%OID_GEN_FRIENDLY_NAME                   = &H00020216???

'//
'// returns miniport information such as whether the driver is serialized or not
'// if it supports sending multiple packets, etc. refer to NDIS_MINIPORT_XXX flags
'//
%OID_GEN_NDIS_RESERVED_1                 = &H00020217???

'//
'// handled by NDIS to reset the test verification paramters on the
'// miniport
'//
%OID_GEN_NDIS_RESERVED_2                 = &H00020218???
%OID_GEN_NDIS_RESERVED_5                 = &H0001020C???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'//
'// more optional OIDs new for NDIS 6.0
'//

%OID_GEN_BYTES_RCV                       = &H00020219???
%OID_GEN_BYTES_XMIT                      = &H0002021A???
%OID_GEN_RCV_DISCARDS                    = &H0002021B???
%OID_GEN_XMIT_DISCARDS                   = &H0002021C???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)



'//
'//  These are connection-oriented general OIDs.
'//  These replace the above OIDs for connection-oriented media.
'//
%OID_GEN_CO_SUPPORTED_LIST              = %OID_GEN_SUPPORTED_LIST
%OID_GEN_CO_HARDWARE_STATUS             = %OID_GEN_HARDWARE_STATUS
%OID_GEN_CO_MEDIA_SUPPORTED             = %OID_GEN_MEDIA_SUPPORTED
%OID_GEN_CO_MEDIA_IN_USE                = %OID_GEN_MEDIA_IN_USE
%OID_GEN_CO_LINK_SPEED                  = %OID_GEN_LINK_SPEED
%OID_GEN_CO_VENDOR_ID                   = %OID_GEN_VENDOR_ID
%OID_GEN_CO_VENDOR_DESCRIPTION          = %OID_GEN_VENDOR_DESCRIPTION
%OID_GEN_CO_DRIVER_VERSION              = %OID_GEN_DRIVER_VERSION
%OID_GEN_CO_PROTOCOL_OPTIONS            = %OID_GEN_PROTOCOL_OPTIONS
%OID_GEN_CO_MAC_OPTIONS                 = %OID_GEN_MAC_OPTIONS
%OID_GEN_CO_MEDIA_CONNECT_STATUS        = %OID_GEN_MEDIA_CONNECT_STATUS
%OID_GEN_CO_VENDOR_DRIVER_VERSION       = %OID_GEN_VENDOR_DRIVER_VERSION
%OID_GEN_CO_SUPPORTED_GUIDS             = %OID_GEN_SUPPORTED_GUIDS
%OID_GEN_CO_GET_TIME_CAPS               = %OID_GEN_GET_TIME_CAPS
%OID_GEN_CO_GET_NETCARD_TIME            = %OID_GEN_GET_NETCARD_TIME
%OID_GEN_CO_MINIMUM_LINK_SPEED          = &H00020120???

'//
'//  These are connection-oriented statistics OIDs.
'//
%OID_GEN_CO_XMIT_PDUS_OK                 = %OID_GEN_XMIT_OK
%OID_GEN_CO_RCV_PDUS_OK                  = %OID_GEN_RCV_OK
%OID_GEN_CO_XMIT_PDUS_ERROR              = %OID_GEN_XMIT_ERROR
%OID_GEN_CO_RCV_PDUS_ERROR               = %OID_GEN_RCV_ERROR
%OID_GEN_CO_RCV_PDUS_NO_BUFFER           = %OID_GEN_RCV_NO_BUFFER


%OID_GEN_CO_RCV_CRC_ERROR                = %OID_GEN_RCV_CRC_ERROR
%OID_GEN_CO_TRANSMIT_QUEUE_LENGTH        = %OID_GEN_TRANSMIT_QUEUE_LENGTH
%OID_GEN_CO_BYTES_XMIT                   = %OID_GEN_DIRECTED_BYTES_XMIT
%OID_GEN_CO_BYTES_RCV                    = %OID_GEN_DIRECTED_BYTES_RCV
%OID_GEN_CO_NETCARD_LOAD                 = %OID_GEN_NETCARD_LOAD
%OID_GEN_CO_DEVICE_PROFILE               = %OID_GEN_DEVICE_PROFILE
%OID_GEN_CO_BYTES_XMIT_OUTSTANDING       = &H00020221???

'//
'// 802.3 Objects (Ethernet)
'//
%OID_802_3_PERMANENT_ADDRESS             = &H01010101???
%OID_802_3_CURRENT_ADDRESS               = &H01010102???
%OID_802_3_MULTICAST_LIST                = &H01010103???
%OID_802_3_MAXIMUM_LIST_SIZE             = &H01010104???
'//
'// This OID has been deprecated for NDIS 6 drivers.
'//
%OID_802_3_MAC_OPTIONS                   = &H01010105???  ' // deprecated


'//
'// This Flag has been deprecated for NDIS 6 drivers.
'//
%NDIS_802_3_MAC_OPTION_PRIORITY          = &H00000001???  ' // deprecated

%OID_802_3_RCV_ERROR_ALIGNMENT           = &H01020101???
%OID_802_3_XMIT_ONE_COLLISION            = &H01020102???
%OID_802_3_XMIT_MORE_COLLISIONS          = &H01020103???

%OID_802_3_XMIT_DEFERRED                 = &H01020201???
%OID_802_3_XMIT_MAX_COLLISIONS           = &H01020202???
%OID_802_3_RCV_OVERRUN                   = &H01020203???
%OID_802_3_XMIT_UNDERRUN                 = &H01020204???
%OID_802_3_XMIT_HEARTBEAT_FAILURE        = &H01020205???
%OID_802_3_XMIT_TIMES_CRS_LOST           = &H01020206???
%OID_802_3_XMIT_LATE_COLLISIONS          = &H01020207???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'//
'// new for NDIS 6
'//
%OID_802_3_ADD_MULTICAST_ADDRESS         = &H01010208???
%OID_802_3_DELETE_MULTICAST_ADDRESS      = &H01010209???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)


'//
'// 802.5 Objects (Token-Ring)
'//
%OID_802_5_PERMANENT_ADDRESS             = &H02010101???
%OID_802_5_CURRENT_ADDRESS               = &H02010102???
%OID_802_5_CURRENT_FUNCTIONAL            = &H02010103???
%OID_802_5_CURRENT_GROUP                 = &H02010104???
%OID_802_5_LAST_OPEN_STATUS              = &H02010105???
%OID_802_5_CURRENT_RING_STATUS           = &H02010106???
%OID_802_5_CURRENT_RING_STATE            = &H02010107???


%OID_802_5_LINE_ERRORS                   = &H02020101???
%OID_802_5_LOST_FRAMES                   = &H02020102???

%OID_802_5_BURST_ERRORS                  = &H02020201???
%OID_802_5_AC_ERRORS                     = &H02020202???
%OID_802_5_ABORT_DELIMETERS              = &H02020203???
%OID_802_5_FRAME_COPIED_ERRORS           = &H02020204???
%OID_802_5_FREQUENCY_ERRORS              = &H02020205???
%OID_802_5_TOKEN_ERRORS                  = &H02020206???
%OID_802_5_INTERNAL_ERRORS               = &H02020207???


'//
'// FDDI Objects
'//
%OID_FDDI_LONG_PERMANENT_ADDR            = &H03010101???
%OID_FDDI_LONG_CURRENT_ADDR              = &H03010102???
%OID_FDDI_LONG_MULTICAST_LIST            = &H03010103???
%OID_FDDI_LONG_MAX_LIST_SIZE             = &H03010104???
%OID_FDDI_SHORT_PERMANENT_ADDR           = &H03010105???
%OID_FDDI_SHORT_CURRENT_ADDR             = &H03010106???
%OID_FDDI_SHORT_MULTICAST_LIST           = &H03010107???
%OID_FDDI_SHORT_MAX_LIST_SIZE            = &H03010108???

%OID_FDDI_ATTACHMENT_TYPE                = &H03020101???
%OID_FDDI_UPSTREAM_NODE_LONG             = &H03020102???
%OID_FDDI_DOWNSTREAM_NODE_LONG           = &H03020103???
%OID_FDDI_FRAME_ERRORS                   = &H03020104???
%OID_FDDI_FRAMES_LOST                    = &H03020105???
%OID_FDDI_RING_MGT_STATE                 = &H03020106???
%OID_FDDI_LCT_FAILURES                   = &H03020107???
%OID_FDDI_LEM_REJECTS                    = &H03020108???
%OID_FDDI_LCONNECTION_STATE              = &H03020109???

%OID_FDDI_SMT_STATION_ID                 = &H03030201???
%OID_FDDI_SMT_OP_VERSION_ID              = &H03030202???
%OID_FDDI_SMT_HI_VERSION_ID              = &H03030203???
%OID_FDDI_SMT_LO_VERSION_ID              = &H03030204???
%OID_FDDI_SMT_MANUFACTURER_DATA          = &H03030205???
%OID_FDDI_SMT_USER_DATA                  = &H03030206???
%OID_FDDI_SMT_MIB_VERSION_ID             = &H03030207???
%OID_FDDI_SMT_MAC_CT                     = &H03030208???
%OID_FDDI_SMT_NON_MASTER_CT              = &H03030209???
%OID_FDDI_SMT_MASTER_CT                  = &H0303020A???
%OID_FDDI_SMT_AVAILABLE_PATHS            = &H0303020B???
%OID_FDDI_SMT_CONFIG_CAPABILITIES        = &H0303020C???
%OID_FDDI_SMT_CONFIG_POLICY              = &H0303020D???
%OID_FDDI_SMT_CONNECTION_POLICY          = &H0303020E???
%OID_FDDI_SMT_T_NOTIFY                   = &H0303020F???
%OID_FDDI_SMT_STAT_RPT_POLICY            = &H03030210???
%OID_FDDI_SMT_TRACE_MAX_EXPIRATION       = &H03030211???
%OID_FDDI_SMT_PORT_INDEXES               = &H03030212???
%OID_FDDI_SMT_MAC_INDEXES                = &H03030213???
%OID_FDDI_SMT_BYPASS_PRESENT             = &H03030214???
%OID_FDDI_SMT_ECM_STATE                  = &H03030215???
%OID_FDDI_SMT_CF_STATE                   = &H03030216???
%OID_FDDI_SMT_HOLD_STATE                 = &H03030217???
%OID_FDDI_SMT_REMOTE_DISCONNECT_FLAG     = &H03030218???
%OID_FDDI_SMT_STATION_STATUS             = &H03030219???
%OID_FDDI_SMT_PEER_WRAP_FLAG             = &H0303021A???
%OID_FDDI_SMT_MSG_TIME_STAMP             = &H0303021B???
%OID_FDDI_SMT_TRANSITION_TIME_STAMP      = &H0303021C???
%OID_FDDI_SMT_SET_COUNT                  = &H0303021D???
%OID_FDDI_SMT_LAST_SET_STATION_ID        = &H0303021E???
%OID_FDDI_MAC_FRAME_STATUS_FUNCTIONS     = &H0303021F???
%OID_FDDI_MAC_BRIDGE_FUNCTIONS           = &H03030220???
%OID_FDDI_MAC_T_MAX_CAPABILITY           = &H03030221???
%OID_FDDI_MAC_TVX_CAPABILITY             = &H03030222???
%OID_FDDI_MAC_AVAILABLE_PATHS            = &H03030223???
%OID_FDDI_MAC_CURRENT_PATH               = &H03030224???
%OID_FDDI_MAC_UPSTREAM_NBR               = &H03030225???
%OID_FDDI_MAC_DOWNSTREAM_NBR             = &H03030226???
%OID_FDDI_MAC_OLD_UPSTREAM_NBR           = &H03030227???
%OID_FDDI_MAC_OLD_DOWNSTREAM_NBR         = &H03030228???
%OID_FDDI_MAC_DUP_ADDRESS_TEST           = &H03030229???
%OID_FDDI_MAC_REQUESTED_PATHS            = &H0303022A???
%OID_FDDI_MAC_DOWNSTREAM_PORT_TYPE       = &H0303022B???
%OID_FDDI_MAC_INDEX                      = &H0303022C???
%OID_FDDI_MAC_SMT_ADDRESS                = &H0303022D???
%OID_FDDI_MAC_LONG_GRP_ADDRESS           = &H0303022E???
%OID_FDDI_MAC_SHORT_GRP_ADDRESS          = &H0303022F???
%OID_FDDI_MAC_T_REQ                      = &H03030230???
%OID_FDDI_MAC_T_NEG                      = &H03030231???
%OID_FDDI_MAC_T_MAX                      = &H03030232???
%OID_FDDI_MAC_TVX_VALUE                  = &H03030233???
%OID_FDDI_MAC_T_PRI0                     = &H03030234???
%OID_FDDI_MAC_T_PRI1                     = &H03030235???
%OID_FDDI_MAC_T_PRI2                     = &H03030236???
%OID_FDDI_MAC_T_PRI3                     = &H03030237???
%OID_FDDI_MAC_T_PRI4                     = &H03030238???
%OID_FDDI_MAC_T_PRI5                     = &H03030239???
%OID_FDDI_MAC_T_PRI6                     = &H0303023A???
%OID_FDDI_MAC_FRAME_CT                   = &H0303023B???
%OID_FDDI_MAC_COPIED_CT                  = &H0303023C???
%OID_FDDI_MAC_TRANSMIT_CT                = &H0303023D???
%OID_FDDI_MAC_TOKEN_CT                   = &H0303023E???
%OID_FDDI_MAC_ERROR_CT                   = &H0303023F???
%OID_FDDI_MAC_LOST_CT                    = &H03030240???
%OID_FDDI_MAC_TVX_EXPIRED_CT             = &H03030241???
%OID_FDDI_MAC_NOT_COPIED_CT              = &H03030242???
%OID_FDDI_MAC_LATE_CT                    = &H03030243???
%OID_FDDI_MAC_RING_OP_CT                 = &H03030244???
%OID_FDDI_MAC_FRAME_ERROR_THRESHOLD      = &H03030245???
%OID_FDDI_MAC_FRAME_ERROR_RATIO          = &H03030246???
%OID_FDDI_MAC_NOT_COPIED_THRESHOLD       = &H03030247???
%OID_FDDI_MAC_NOT_COPIED_RATIO           = &H03030248???
%OID_FDDI_MAC_RMT_STATE                  = &H03030249???
%OID_FDDI_MAC_DA_FLAG                    = &H0303024A???
%OID_FDDI_MAC_UNDA_FLAG                  = &H0303024B???
%OID_FDDI_MAC_FRAME_ERROR_FLAG           = &H0303024C???
%OID_FDDI_MAC_NOT_COPIED_FLAG            = &H0303024D???
%OID_FDDI_MAC_MA_UNITDATA_AVAILABLE      = &H0303024E???
%OID_FDDI_MAC_HARDWARE_PRESENT           = &H0303024F???
%OID_FDDI_MAC_MA_UNITDATA_ENABLE         = &H03030250???
%OID_FDDI_PATH_INDEX                     = &H03030251???
%OID_FDDI_PATH_RING_LATENCY              = &H03030252???
%OID_FDDI_PATH_TRACE_STATUS              = &H03030253???
%OID_FDDI_PATH_SBA_PAYLOAD               = &H03030254???
%OID_FDDI_PATH_SBA_OVERHEAD              = &H03030255???
%OID_FDDI_PATH_CONFIGURATION             = &H03030256???
%OID_FDDI_PATH_T_R_MODE                  = &H03030257???
%OID_FDDI_PATH_SBA_AVAILABLE             = &H03030258???
%OID_FDDI_PATH_TVX_LOWER_BOUND           = &H03030259???
%OID_FDDI_PATH_T_MAX_LOWER_BOUND         = &H0303025A???
%OID_FDDI_PATH_MAX_T_REQ                 = &H0303025B???
%OID_FDDI_PORT_MY_TYPE                   = &H0303025C???
%OID_FDDI_PORT_NEIGHBOR_TYPE             = &H0303025D???
%OID_FDDI_PORT_CONNECTION_POLICIES       = &H0303025E???
%OID_FDDI_PORT_MAC_INDICATED             = &H0303025F???
%OID_FDDI_PORT_CURRENT_PATH              = &H03030260???
%OID_FDDI_PORT_REQUESTED_PATHS           = &H03030261???
%OID_FDDI_PORT_MAC_PLACEMENT             = &H03030262???
%OID_FDDI_PORT_AVAILABLE_PATHS           = &H03030263???
%OID_FDDI_PORT_MAC_LOOP_TIME             = &H03030264???
%OID_FDDI_PORT_PMD_CLASS                 = &H03030265???
%OID_FDDI_PORT_CONNECTION_CAPABILITIES   = &H03030266???
%OID_FDDI_PORT_INDEX                     = &H03030267???
%OID_FDDI_PORT_MAINT_LS                  = &H03030268???
%OID_FDDI_PORT_BS_FLAG                   = &H03030269???
%OID_FDDI_PORT_PC_LS                     = &H0303026A???
%OID_FDDI_PORT_EB_ERROR_CT               = &H0303026B???
%OID_FDDI_PORT_LCT_FAIL_CT               = &H0303026C???
%OID_FDDI_PORT_LER_ESTIMATE              = &H0303026D???
%OID_FDDI_PORT_LEM_REJECT_CT             = &H0303026E???
%OID_FDDI_PORT_LEM_CT                    = &H0303026F???
%OID_FDDI_PORT_LER_CUTOFF                = &H03030270???
%OID_FDDI_PORT_LER_ALARM                 = &H03030271???
%OID_FDDI_PORT_CONNNECT_STATE            = &H03030272???
%OID_FDDI_PORT_PCM_STATE                 = &H03030273???
%OID_FDDI_PORT_PC_WITHHOLD               = &H03030274???
%OID_FDDI_PORT_LER_FLAG                  = &H03030275???
%OID_FDDI_PORT_HARDWARE_PRESENT          = &H03030276???
%OID_FDDI_SMT_STATION_ACTION             = &H03030277???
%OID_FDDI_PORT_ACTION                    = &H03030278???
%OID_FDDI_IF_DESCR                       = &H03030279???
%OID_FDDI_IF_TYPE                        = &H0303027A???
%OID_FDDI_IF_MTU                         = &H0303027B???
%OID_FDDI_IF_SPEED                       = &H0303027C???
%OID_FDDI_IF_PHYS_ADDRESS                = &H0303027D???
%OID_FDDI_IF_ADMIN_STATUS                = &H0303027E???
%OID_FDDI_IF_OPER_STATUS                 = &H0303027F???
%OID_FDDI_IF_LAST_CHANGE                 = &H03030280???
%OID_FDDI_IF_IN_OCTETS                   = &H03030281???
%OID_FDDI_IF_IN_UCAST_PKTS               = &H03030282???
%OID_FDDI_IF_IN_NUCAST_PKTS              = &H03030283???
%OID_FDDI_IF_IN_DISCARDS                 = &H03030284???
%OID_FDDI_IF_IN_ERRORS                   = &H03030285???
%OID_FDDI_IF_IN_UNKNOWN_PROTOS           = &H03030286???
%OID_FDDI_IF_OUT_OCTETS                  = &H03030287???
%OID_FDDI_IF_OUT_UCAST_PKTS              = &H03030288???
%OID_FDDI_IF_OUT_NUCAST_PKTS             = &H03030289???
%OID_FDDI_IF_OUT_DISCARDS                = &H0303028A???
%OID_FDDI_IF_OUT_ERRORS                  = &H0303028B???
%OID_FDDI_IF_OUT_QLEN                    = &H0303028C???
%OID_FDDI_IF_SPECIFIC                    = &H0303028D???

'//
'// WAN objects
'//
%OID_WAN_PERMANENT_ADDRESS               = &H04010101???
%OID_WAN_CURRENT_ADDRESS                 = &H04010102???
%OID_WAN_QUALITY_OF_SERVICE              = &H04010103???
%OID_WAN_PROTOCOL_TYPE                   = &H04010104???
%OID_WAN_MEDIUM_SUBTYPE                  = &H04010105???
%OID_WAN_HEADER_FORMAT                   = &H04010106???

%OID_WAN_GET_INFO                        = &H04010107???
%OID_WAN_SET_LINK_INFO                   = &H04010108???
%OID_WAN_GET_LINK_INFO                   = &H04010109???

%OID_WAN_LINE_COUNT                      = &H0401010A???
%OID_WAN_PROTOCOL_CAPS                   = &H0401010B???

%OID_WAN_GET_BRIDGE_INFO                 = &H0401020A???
%OID_WAN_SET_BRIDGE_INFO                 = &H0401020B???
%OID_WAN_GET_COMP_INFO                   = &H0401020C???
%OID_WAN_SET_COMP_INFO                   = &H0401020D???
%OID_WAN_GET_STATS_INFO                  = &H0401020E???

'//
'//  These are connection-oriented WAN OIDs.
'//  These replace the above OIDs for CoNDIS WAN Miniports
'//
%OID_WAN_CO_GET_INFO                     = &H04010180???
%OID_WAN_CO_SET_LINK_INFO                = &H04010181???
%OID_WAN_CO_GET_LINK_INFO                = &H04010182???
%OID_WAN_CO_GET_COMP_INFO                = &H04010280???
%OID_WAN_CO_SET_COMP_INFO                = &H04010281???
%OID_WAN_CO_GET_STATS_INFO               = &H04010282???


'//
'// LocalTalk objects
'//
%OID_LTALK_CURRENT_NODE_ID               = &H05010102???

%OID_LTALK_IN_BROADCASTS                 = &H05020101???
%OID_LTALK_IN_LENGTH_ERRORS              = &H05020102???

%OID_LTALK_OUT_NO_HANDLERS               = &H05020201???
%OID_LTALK_COLLISIONS                    = &H05020202???
%OID_LTALK_DEFERS                        = &H05020203???
%OID_LTALK_NO_DATA_ERRORS                = &H05020204???
%OID_LTALK_RANDOM_CTS_ERRORS             = &H05020205???
%OID_LTALK_FCS_ERRORS                    = &H05020206???


'//
'// Arcnet objects
'//
%OID_ARCNET_PERMANENT_ADDRESS            = &H06010101???
%OID_ARCNET_CURRENT_ADDRESS              = &H06010102???

%OID_ARCNET_RECONFIGURATIONS             = &H06020201???

'//
'// TAPI objects
'//
%OID_TAPI_ACCEPT                         = &H07030101???
%OID_TAPI_ANSWER                         = &H07030102???
%OID_TAPI_CLOSE                          = &H07030103???
%OID_TAPI_CLOSE_CALL                     = &H07030104???
%OID_TAPI_CONDITIONAL_MEDIA_DETECTION    = &H07030105???
%OID_TAPI_CONFIG_DIALOG                  = &H07030106???
%OID_TAPI_DEV_SPECIFIC                   = &H07030107???
%OID_TAPI_DIAL                           = &H07030108???
%OID_TAPI_DROP                           = &H07030109???
%OID_TAPI_GET_ADDRESS_CAPS               = &H0703010A???
%OID_TAPI_GET_ADDRESS_ID                 = &H0703010B???
%OID_TAPI_GET_ADDRESS_STATUS             = &H0703010C???
%OID_TAPI_GET_CALL_ADDRESS_ID            = &H0703010D???
%OID_TAPI_GET_CALL_INFO                  = &H0703010E???
%OID_TAPI_GET_CALL_STATUS                = &H0703010F???
%OID_TAPI_GET_DEV_CAPS                   = &H07030110???
%OID_TAPI_GET_DEV_CONFIG                 = &H07030111???
%OID_TAPI_GET_EXTENSION_ID               = &H07030112???
%OID_TAPI_GET_ID                         = &H07030113???
%OID_TAPI_GET_LINE_DEV_STATUS            = &H07030114???
%OID_TAPI_MAKE_CALL                      = &H07030115???
%OID_TAPI_NEGOTIATE_EXT_VERSION          = &H07030116???
%OID_TAPI_OPEN                           = &H07030117???
%OID_TAPI_PROVIDER_INITIALIZE            = &H07030118???
%OID_TAPI_PROVIDER_SHUTDOWN              = &H07030119???
%OID_TAPI_SECURE_CALL                    = &H0703011A???
%OID_TAPI_SELECT_EXT_VERSION             = &H0703011B???
%OID_TAPI_SEND_USER_USER_INFO            = &H0703011C???
%OID_TAPI_SET_APP_SPECIFIC               = &H0703011D???
%OID_TAPI_SET_CALL_PARAMS                = &H0703011E???
%OID_TAPI_SET_DEFAULT_MEDIA_DETECTION    = &H0703011F???
%OID_TAPI_SET_DEV_CONFIG                 = &H07030120???
%OID_TAPI_SET_MEDIA_MODE                 = &H07030121???
%OID_TAPI_SET_STATUS_MESSAGES            = &H07030122???
%OID_TAPI_GATHER_DIGITS                  = &H07030123???
%OID_TAPI_MONITOR_DIGITS                 = &H07030124???

'//
'// ATM Connection Oriented OIDs
'//
%OID_ATM_SUPPORTED_VC_RATES              = &H08010101???
%OID_ATM_SUPPORTED_SERVICE_CATEGORY      = &H08010102???
%OID_ATM_SUPPORTED_AAL_TYPES             = &H08010103???
%OID_ATM_HW_CURRENT_ADDRESS              = &H08010104???
%OID_ATM_MAX_ACTIVE_VCS                  = &H08010105???
%OID_ATM_MAX_ACTIVE_VCI_BITS             = &H08010106???
%OID_ATM_MAX_ACTIVE_VPI_BITS             = &H08010107???
%OID_ATM_MAX_AAL0_PACKET_SIZE            = &H08010108???
%OID_ATM_MAX_AAL1_PACKET_SIZE            = &H08010109???
%OID_ATM_MAX_AAL34_PACKET_SIZE           = &H0801010A???
%OID_ATM_MAX_AAL5_PACKET_SIZE            = &H0801010B???

%OID_ATM_SIGNALING_VPIVCI                = &H08010201???
%OID_ATM_ASSIGNED_VPI                    = &H08010202???
%OID_ATM_ACQUIRE_ACCESS_NET_RESOURCES    = &H08010203???
%OID_ATM_RELEASE_ACCESS_NET_RESOURCES    = &H08010204???
%OID_ATM_ILMI_VPIVCI                     = &H08010205???
%OID_ATM_DIGITAL_BROADCAST_VPIVCI        = &H08010206???
%OID_ATM_GET_NEAREST_FLOW                = &H08010207???
%OID_ATM_ALIGNMENT_REQUIRED              = &H08010208???
%OID_ATM_LECS_ADDRESS                    = &H08010209???
%OID_ATM_SERVICE_ADDRESS                 = &H0801020A???

%OID_ATM_CALL_PROCEEDING                 = &H0801020B???  ' // UNI 4.0
%OID_ATM_CALL_ALERTING                   = &H0801020C???  ' // UNI 4.0
%OID_ATM_PARTY_ALERTING                  = &H0801020D???  ' // UNI 4.0
%OID_ATM_CALL_NOTIFY                     = &H0801020E???  ' // UNI 4.0

%OID_ATM_MY_IP_NM_ADDRESS                = &H0801020F???


'//
'//  ATM specific statistics OIDs.
'//
%OID_ATM_RCV_CELLS_OK                    = &H08020101???
%OID_ATM_XMIT_CELLS_OK                   = &H08020102???
%OID_ATM_RCV_CELLS_DROPPED               = &H08020103???

%OID_ATM_RCV_INVALID_VPI_VCI             = &H08020201???
%OID_ATM_CELLS_HEC_ERROR                 = &H08020202???
%OID_ATM_RCV_REASSEMBLY_ERROR            = &H08020203???


'//
'// IEEE 802.11 OIDs
'//
%OID_802_11_BSSID                        = &H0D010101???
%OID_802_11_SSID                         = &H0D010102???
%OID_802_11_NETWORK_TYPES_SUPPORTED      = &H0D010203???
%OID_802_11_NETWORK_TYPE_IN_USE          = &H0D010204???
%OID_802_11_TX_POWER_LEVEL               = &H0D010205???
%OID_802_11_RSSI                         = &H0D010206???
%OID_802_11_RSSI_TRIGGER                 = &H0D010207???
%OID_802_11_INFRASTRUCTURE_MODE          = &H0D010108???
%OID_802_11_FRAGMENTATION_THRESHOLD      = &H0D010209???
%OID_802_11_RTS_THRESHOLD                = &H0D01020A???
%OID_802_11_NUMBER_OF_ANTENNAS           = &H0D01020B???
%OID_802_11_RX_ANTENNA_SELECTED          = &H0D01020C???
%OID_802_11_TX_ANTENNA_SELECTED          = &H0D01020D???
%OID_802_11_SUPPORTED_RATES              = &H0D01020E???
%OID_802_11_DESIRED_RATES                = &H0D010210???
%OID_802_11_CONFIGURATION                = &H0D010211???
%OID_802_11_STATISTICS                   = &H0D020212???
%OID_802_11_ADD_WEP                      = &H0D010113???
%OID_802_11_REMOVE_WEP                   = &H0D010114???
%OID_802_11_DISASSOCIATE                 = &H0D010115???
%OID_802_11_POWER_MODE                   = &H0D010216???
%OID_802_11_BSSID_LIST                   = &H0D010217???
%OID_802_11_AUTHENTICATION_MODE          = &H0D010118???
%OID_802_11_PRIVACY_FILTER               = &H0D010119???
%OID_802_11_BSSID_LIST_SCAN              = &H0D01011A???
%OID_802_11_WEP_STATUS                   = &H0D01011B???
'// Renamed to reflect better the extended set of encryption status
%OID_802_11_ENCRYPTION_STATUS            = %OID_802_11_WEP_STATUS
%OID_802_11_RELOAD_DEFAULTS              = &H0D01011C???
'// Added to allow key mapping and default keys
%OID_802_11_ADD_KEY                      = &H0D01011D???
%OID_802_11_REMOVE_KEY                   = &H0D01011E???
%OID_802_11_ASSOCIATION_INFORMATION      = &H0D01011F???
%OID_802_11_TEST                         = &H0D010120???
%OID_802_11_MEDIA_STREAM_MODE            = &H0D010121???
%OID_802_11_CAPABILITY                   = &H0D010122???
%OID_802_11_PMKID                        = &H0D010123???
%OID_802_11_NON_BCAST_SSID_LIST          = &H0D010124???
%OID_802_11_RADIO_STATUS                 = &H0D010125???


'//
'// some of well known Ethernet frame types (in big endian notation)
'//
%NDIS_ETH_TYPE_IPV4              = &H0800???  ' // IPV4
%NDIS_ETH_TYPE_ARP               = &H0806???  ' // ARP
%NDIS_ETH_TYPE_IPV6              = &H86dd???  ' // IPV6
%NDIS_ETH_TYPE_802_1X            = &H888e???  ' // 802.1x
%NDIS_ETH_TYPE_802_1Q            = &H8100???  ' // 802.1p
%NDIS_ETH_TYPE_SLOW_PROTOCOL     = &H8809???  ' // Slow protocols (LACP, etc.)

%NDIS_802_11_LENGTH_SSID         = 32
%NDIS_802_11_LENGTH_RATES        = 8
%NDIS_802_11_LENGTH_RATES_EX     = 16

'//
'// IEEE 802.11 Structures and definitions
'//
'// new types for Media Specific Indications
' enum _NDIS_802_11_STATUS_TYPE
%Ndis802_11StatusType_Authentication      = 0
%Ndis802_11StatusType_MediaStreamMode     = 1
%Ndis802_11StatusType_PMKID_CandidateList = 2
%Ndis802_11StatusTypeMax                  = 3   ' // not a real type, defined as an upper bound

'typedef UCHAR   NDIS_802_11_MAC_ADDRESS[6];

' // Size = 4 bytes
TYPE NDIS_802_11_STATUS_INDICATION DWORD
   StatusType AS LONG   ' NDIS_802_11_STATUS_TYPE
END TYPE

'// mask for authentication/integrity fields
%NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS      = &H0f

%NDIS_802_11_AUTH_REQUEST_REAUTH           = &H01
%NDIS_802_11_AUTH_REQUEST_KEYUPDATE        = &H02
%NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR   = &H06
%NDIS_802_11_AUTH_REQUEST_GROUP_ERROR      = &H0E

UNION NDIS_802_11_AUTHENTICATION_REQUEST_BSSID_UNION
   Bssid(5) AS BYTE    ' NDIS_802_11_MAC_ADDRESS[6]
   ' // For compatibility with the PB declares
   Bssid    AS STRING * 6
END UNION

' // Size = 16 bytes
TYPE NDIS_802_11_AUTHENTICATION_REQUEST DWORD
   Length   AS DWORD   ' ULONG // Length of structure
   NDIS_802_11_AUTHENTICATION_REQUEST_BSSID_UNION
   Flags    AS DWORD   ' ULONG
END TYPE

'//Added new types for PMKID Candidate lists.

UNION PMKID_CANDIDATE_BSSID_UNION
   Bssid(5) AS BYTE    ' NDIS_802_11_MAC_ADDRESS[6]
   ' // For compatibility with the PB declares
   Bssid    AS STRING * 6
END UNION

' // Size = 12 bytes
TYPE PMKID_CANDIDATE DWORD
   PMKID_CANDIDATE_BSSID_UNION
   Flags    AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_802_11_PMKID_CANDIDATE_LIST DWORD
   Version          AS DWORD             ' ULONG // Version of the structure
   NumCandidates    AS DWORD             ' ULONG // No. of pmkid candidates
   CandidateList(0) AS PMKID_CANDIDATE
END TYPE

'//Flags for PMKID Candidate list structure
%NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED = &H01???

'// Added new types for OFDM 5G and 2.4G
' enum _NDIS_802_11_NETWORK_TYPE
%Ndis802_11FH             = 0
%Ndis802_11DS             = 1
%Ndis802_11OFDM5          = 2
%Ndis802_11OFDM24         = 3
%Ndis802_11Automode       = 4
%Ndis802_11NetworkTypeMax = 5   ' // not a real type, defined as an upper bound

' // Size = 8 bytes
TYPE NDIS_802_11_NETWORK_TYPE_LIST DWORD
   NumberOfItems  AS DWORD  ' ULONG // in list below, at least 1
   NetworkType(0) AS LONG   ' NDIS_802_11_NETWORK_TYPE enum
END TYPE

' enum _NDIS_802_11_POWER_MODE
%Ndis802_11PowerModeCAM      = 0
%Ndis802_11PowerModeMAX_PSP  = 1
%Ndis802_11PowerModeFast_PSP = 2
%Ndis802_11PowerModeMax      = 3   ' // not a real mode, defined as an upper bound

'typedef ULONG   NDIS_802_11_TX_POWER_LEVEL; // in milliwatts

'//
'// Received Signal Strength Indication
'//
'typedef LONG   NDIS_802_11_RSSI;           // in dBm

' // Size = 16 bytes
TYPE NDIS_802_11_CONFIGURATION_FH DWORD
   Length     AS DWORD   ' ULONG // Length of structure
   HopPattern AS DWORD   ' ULONG // As defined by 802.11, MSB set
   HopSet     AS DWORD   ' ULONG // to one if non-802.11
   DwellTime  AS DWORD   ' ULONG // units are Kusec
END TYPE

' // Size = 32 bytes
TYPE NDIS_802_11_CONFIGURATION DWORD
   Length       AS DWORD   ' ULONG // Length of structure
   BeaconPeriod AS DWORD   ' ULONG // units are Kusec
   ATIMWindow   AS DWORD   ' ULONG // units are Kusec
   DSConfig     AS DWORD   ' ULONG // Frequency, units are kHz
   FHConfig     AS NDIS_802_11_CONFIGURATION_FH
END TYPE

' // Size = 200 bytes
TYPE NDIS_802_11_STATISTICS QWORD FILL
   Length                         AS DWORD  ' ULONG // Length of structure
   TransmittedFragmentCount       AS QUAD   ' LARGE_INTEGER
   MulticastTransmittedFrameCount AS QUAD   ' LARGE_INTEGER
   FailedCount                    AS QUAD   ' LARGE_INTEGER
   RetryCount                     AS QUAD   ' LARGE_INTEGER
   MultipleRetryCount             AS QUAD   ' LARGE_INTEGER
   RTSSuccessCount                AS QUAD   ' LARGE_INTEGER
   RTSFailureCount                AS QUAD   ' LARGE_INTEGER
   ACKFailureCount                AS QUAD   ' LARGE_INTEGER
   FrameDuplicateCount            AS QUAD   ' LARGE_INTEGER
   ReceivedFragmentCount          AS QUAD   ' LARGE_INTEGER
   MulticastReceivedFrameCount    AS QUAD   ' LARGE_INTEGER
   FCSErrorCount                  AS QUAD   ' LARGE_INTEGER
   TKIPLocalMICFailures           AS QUAD   ' LARGE_INTEGER
   TKIPICVErrorCount              AS QUAD   ' LARGE_INTEGER
   TKIPCounterMeasuresInvoked     AS QUAD   ' LARGE_INTEGER
   TKIPReplays                    AS QUAD   ' LARGE_INTEGER
   CCMPFormatErrors               AS QUAD   ' LARGE_INTEGER
   CCMPReplays                    AS QUAD   ' LARGE_INTEGER
   CCMPDecryptErrors              AS QUAD   ' LARGE_INTEGER
   FourWayHandshakeFailures       AS QUAD   ' LARGE_INTEGER
   WEPUndecryptableCount          AS QUAD   ' LARGE_INTEGER
   WEPICVErrorCount               AS QUAD   ' LARGE_INTEGER
   DecryptSuccessCount            AS QUAD   ' LARGE_INTEGER
   DecryptFailureCount            AS QUAD   ' LARGE_INTEGER
END TYPE

'typedef  ULONG  NDIS_802_11_KEY_INDEX;
'typedef ULONGLONG   NDIS_802_11_KEY_RSC;

'// Key mapping keys require a BSSID

UNION NDIS_802_11_KEY_BSSID_UNION
   Bssid(5) AS BYTE    ' NDIS_802_11_MAC_ADDRESS[6]
   ' // For compatibility with the PB declares
   Bssid    AS STRING * 6
END UNION

' // Size in C++ = 40 bytes
TYPE NDIS_802_11_KEY QWORD FILL
   Length         AS DWORD   ' ULONG // Length of this structure
   KeyIndex       AS DWORD   ' ULONG
   KeyLength      AS DWORD   ' ULONG // length of key in bytes
   NDIS_802_11_KEY_BSSID_UNION
   KeyRSC         AS QUAD    ' NDIS_802_11_KEY_RSC
   KeyMaterial(0) AS BYTE    ' UCHAR // variable length depending on above field
END TYPE

UNION NDIS_802_11_REMOVE_KEY_UNION
   Bssid(5) AS BYTE    ' NDIS_802_11_MAC_ADDRESS[6]
   ' // For compatibility with the PB declares
   Bssid    AS STRING * 6
END UNION

' // Size = 16 bytes
TYPE NDIS_802_11_REMOVE_KEY DWORD
   Length   AS DWORD   ' ULONG // Length of this structure
   KeyIndex AS DWORD   ' ULONG
   NDIS_802_11_REMOVE_KEY_UNION
END TYPE

' // Size = 16 bytes
TYPE NDIS_802_11_WEP DWORD
   Length         AS DWORD   ' ULONG // Length of this structure
   KeyIndex       AS DWORD   ' ULONG // 0 is the per-client key, 1-N are the
                             '       // global keys
   KeyLength      AS DWORD   ' ULONG // length of key in bytes
   KeyMaterial(0) AS BYTE    ' // variable length depending on above field
END TYPE


' enum NDIS_802_11_NETWORK_INFRASTRUCTURE
%Ndis802_11IBSS              = 0
%Ndis802_11Infrastructure    = 1
%Ndis802_11AutoUnknown       = 2
%Ndis802_11InfrastructureMax = 3   ' // Not a real value, defined as upper bound

'// Add new authentication modes
' enum _NDIS_802_11_AUTHENTICATION_MODE
%Ndis802_11AuthModeOpen       = 0
%Ndis802_11AuthModeShared     = 1
%Ndis802_11AuthModeAutoSwitch = 2
%Ndis802_11AuthModeWPA        = 3
%Ndis802_11AuthModeWPAPSK     = 4
%Ndis802_11AuthModeWPANone    = 5
%Ndis802_11AuthModeWPA2       = 6
%Ndis802_11AuthModeWPA2PSK    = 7
%Ndis802_11AuthModeMax        = 8   ' // Not a real mode, defined as upper bound

'typedef UCHAR   NDIS_802_11_RATES[NDIS_802_11_LENGTH_RATES];        // Set of 8 data rates
'typedef UCHAR   NDIS_802_11_RATES_EX[NDIS_802_11_LENGTH_RATES_EX];  // Set of 16 data rates

' // Size = 16 bytes
TYPE NDIS_802_11_SSID DWORD
   SsidLength AS DWORD   ' ULONG // length of SSID field below, in bytes this can be zero.
   Ssid(%NDIS_802_11_LENGTH_SSID - 1) AS BYTE   ' UCHAR // SSID information field
END TYPE

UNION NDIS_WLAN_BSSID_MACADDRESS_UNION
   MacAddress(5)      AS BYTE                        ' NDIS_802_11_MAC_ADDRESS // BSSID
   ' // For compatibility with the PB declares
   MacAddress         AS STRING * 6
END UNION

UNION NDIS_WLAN_BSSID_SUPPORTEDRATES_UNION
   SupportedRates(7)  AS BYTE                        ' NDIS_802_11_RATES
   ' // For compatibility with the PB declares
   SupportedRates     AS STRING * 8
END UNION

' // Size = 104 bytes
TYPE NDIS_WLAN_BSSID DWORD FILL
   Length             AS DWORD                       ' ULONG // Length of this structure
   NDIS_WLAN_BSSID_MACADDRESS_UNION
   Reserved(1)        AS BYTE                        ' UCHAR
   Ssid               AS NDIS_802_11_SSID            ' // SSID
   Privacy            AS DWORD                       ' ULONG // WEP encryption requirement
   Rssi               AS LONG                        ' NDIS_802_11_RSSI // receive signal strength in dBm
   NetworkTypeInUse   AS LONG                        ' NDIS_802_11_NETWORK_TYPE enum
   Configuration      AS NDIS_802_11_CONFIGURATION
   InfrastructureMode AS LONG                        ' NDIS_802_11_NETWORK_INFRASTRUCTURE
   NDIS_WLAN_BSSID_SUPPORTEDRATES_UNION
END TYPE

' // Size = 108 bytes
TYPE NDIS_802_11_BSSID_LIST DWORD
   NumberOfItems AS DWORD             ' ULONG // in list below, at least 1
   Bssid(0)      AS NDIS_WLAN_BSSID
END TYPE

'// Added Capabilities, IELength and IEs for each BSSID

UNION NDIS_WLAN_BSSID_EX_MACADDRESS_UNION
   MacAddress(5)      AS BYTE                        ' NDIS_802_11_MAC_ADDRESS // BSSID
   ' // For compatibility with the PB declares
   MacAddress         AS STRING * 6
END UNION

UNION NDIS_WLAN_BSSID_EX_SUPPORTEDRATES_UNION
   SupportedRates(15) AS BYTE                        ' NDIS_802_11_RATES_EX
   ' // For compatibility with the PB declares
   SupportedRates     AS STRING * 16
END UNION

' // Size = 120 bytes
TYPE NDIS_WLAN_BSSID_EX DWORD FILL
   Length             AS DWORD                       ' ULONG // Length of this structure
   NDIS_WLAN_BSSID_EX_MACADDRESS_UNION
   Reserved(1)        AS BYTE                        ' UCHAR
   Ssid               AS NDIS_802_11_SSID            ' // SSID
   Privacy            AS DWORD                       ' ULONG // WEP encryption requirement
   Rssi               AS LONG                        ' NDIS_802_11_RSSI // receive signal strength in dBm
   NetworkTypeInUse   AS LONG                        ' NDIS_802_11_NETWORK_TYPE
   Configuration      AS NDIS_802_11_CONFIGURATION
   InfrastructureMode AS LONG                        ' NDIS_802_11_NETWORK_INFRASTRUCTURE
   NDIS_WLAN_BSSID_EX_SUPPORTEDRATES_UNION
   IELength           AS DWORD                       ' ULONG
   IEs(0)             AS BYTE                        ' UCHAR
   alignment__(2)     AS BYTE
END TYPE

' // Size = 124 bytes
TYPE NDIS_802_11_BSSID_LIST_EX DWORD
   NumberOfItems AS DWORD                ' ULONG // in list below, at least 1
   Bssid(0)      AS NDIS_WLAN_BSSID_EX
END TYPE

' // Size = 12 bytes
TYPE NDIS_802_11_FIXED_IEs WORD
   Timestamp(7)   AS BYTE   ' UCHAR
   BeaconInterval AS WORD   ' USHORT
   Capabilities   AS WORD   ' USHORT
END TYPE

UNION NDIS_802_11_VARIABLE_IEs_DATA_UNION
   data(0)   AS BYTE
   ' // For compability with the PB declares
   bData(0)  AS BYTE
END UNION

' // Size = 3 bytes
TYPE NDIS_802_11_VARIABLE_IEs BYTE
   ElementID AS BYTE
   Length    AS BYTE   ' // Number of bytes in data field
   NDIS_802_11_VARIABLE_IEs_DATA_UNION
END TYPE

'typedef  ULONG   NDIS_802_11_FRAGMENTATION_THRESHOLD;

'typedef  ULONG   NDIS_802_11_RTS_THRESHOLD;

'typedef  ULONG   NDIS_802_11_ANTENNA;

' enum _NDIS_802_11_PRIVACY_FILTER
%Ndis802_11PrivFilterAcceptAll = 0
%Ndis802_11PrivFilter8021xWEP  = 1

'// Added new encryption types
'// Also aliased typedef to new name
' enum _NDIS_802_11_WEP_STATUS aka NDIS_802_11_ENCRYPTION_STATUS
%Ndis802_11WEPEnabled             = 0
%Ndis802_11Encryption1Enabled     = %Ndis802_11WEPEnabled
%Ndis802_11WEPDisabled            = 1
%Ndis802_11Encryptiondisabled     = %Ndis802_11WEPDisabled
%Ndis802_11WEPKeyAbsent           = 2
%Ndis802_11Encryption1KeyAbsent   = %Ndis802_11WEPKeyAbsent
%Ndis802_11WEPNotSupported        = 3
%Ndis802_11EncryptionNotSupported = %Ndis802_11WEPNotSupported
%Ndis802_11Encryption2Enabled     = 4
%Ndis802_11Encryption2KeyAbsent   = 5
%Ndis802_11Encryption3Enabled     = 6
%Ndis802_11Encryption3KeyAbsent   = 7

' enum _NDIS_802_11_RELOAD_DEFAULTS
%Ndis802_11ReloadWEPKeys = 0

%NDIS_802_11_AI_REQFI_CAPABILITIES     = 1
%NDIS_802_11_AI_REQFI_LISTENINTERVAL   = 2
%NDIS_802_11_AI_REQFI_CURRENTAPADDRESS = 4

%NDIS_802_11_AI_RESFI_CAPABILITIES     = 1
%NDIS_802_11_AI_RESFI_STATUSCODE       = 2
%NDIS_802_11_AI_RESFI_ASSOCIATIONID    = 4

UNION NDIS_802_11_AI_REQFI_CURRENTAPADDRESS_UNION
   CurrentAPAddress(5) AS BYTE   ' NDIS_802_11_MAC_ADDRESS
   ' // For compatibility with the PB declares
   CurrentAPAddress    AS STRING * 6
END UNION

' // Size = 10 bytes
TYPE NDIS_802_11_AI_REQFI WORD
   Capabilities        AS WORD   ' USHORT
   ListenInterval      AS WORD   ' USHORT
   NDIS_802_11_AI_REQFI_CURRENTAPADDRESS_UNION
END TYPE

' // Size = 6 bytes
TYPE NDIS_802_11_AI_RESFI WORD
   Capabilities  AS WORD   ' USHORT
   StatusCode    AS WORD   ' USHORT
   AssociationId AS WORD   ' USHORT
END TYPE

' // Size = 40 bytes
TYPE NDIS_802_11_ASSOCIATION_INFORMATION WORD
   Length                    AS DWORD                  ' ULONG
   AvailableRequestFixedIEs  AS WORD                   ' USHORT
   RequestFixedIEs           AS NDIS_802_11_AI_REQFI
   RequestIELength           AS DWORD                  ' ULONG
   OffsetRequestIEs          AS DWORD                  ' ULONG
   AvailableResponseFixedIEs AS WORD                   ' USHORT
   ResponseFixedIEs          AS NDIS_802_11_AI_RESFI
   ResponseIELength          AS DWORD                  ' ULONG
   OffsetResponseIEs         AS DWORD                  ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_802_11_AUTHENTICATION_EVENT DWORD
   Status     AS NDIS_802_11_STATUS_INDICATION
   Request(0) AS NDIS_802_11_AUTHENTICATION_REQUEST
END TYPE

' // Size = 20 bytes
UNION NDIS_802_11_TEST_UNION DWORD
   AuthenticationEvent AS NDIS_802_11_AUTHENTICATION_EVENT
   RssiTrigger         AS LONG   ' NDIS_802_11_RSSI
END UNION

UNION NDIS_802_11_TEST_TYPE_UNION
   Type   AS DWORD   ' ULONG
   ' // For compatibility with the PB declares
   dType  AS DWORD   ' ULONG
END UNION

' // Size = 28 bytes
TYPE NDIS_802_11_TEST DWORD
   Length AS DWORD   ' ULONG
   NDIS_802_11_TEST_TYPE_UNION
   NDIS_802_11_TEST_UNION
END TYPE

'// 802.11 Media stream constraints, associated with OID_802_11_MEDIA_STREAM_MODE
' enum NDIS_802_11_MEDIA_STREAM_MODE
%Ndis802_11MediaStreamOff = 0
%Ndis802_11MediaStreamOn  = 1

'// PMKID Structures
'typedef UCHAR   NDIS_802_11_PMKID_VALUE[16];

UNION BSSID_INFO_BSSID_UNION
   BSSID(5)  AS BYTE   ' NDIS_802_11_MAC_ADDRESS
   ' // For compatibility with the PB declares
   BSSID AS STRING * 6
END UNION

UNION BSSID_INFO_PMKID_UNION
   PMKID(15) AS BYTE   ' NDIS_802_11_PMKID_VALUE
   ' // For compatibility with the PB declares
   PMKID AS STRING * 16
END UNION

' // Size = 28 bytes
TYPE BSSID_INFO BYTE
   BSSID_INFO_BSSID_UNION
   BSSID_INFO_PMKID_UNION
END TYPE

' // Size = 32 bytes
TYPE NDIS_802_11_PMKID DWORD
   Length         AS DWORD        ' ULONG
   BSSIDInfoCount AS DWORD        ' ULONG
   BSSIDInfo(0)   AS BSSID_INFO
END TYPE

' // Size = 32 bytes
TYPE NDIS_802_11_AUTHENTICATION_ENCRYPTION DWORD
   AuthModeSupported      AS LONG   ' NDIS_802_11_AUTHENTICATION_MODE
   EncryptStatusSupported AS LONG   ' NDIS_802_11_ENCRYPTION_STATUS
END TYPE

' // Size = 24 bytes
TYPE NDIS_802_11_CAPABILITY DWORD
   Length                               AS DWORD   ' ULONG
   Version                              AS DWORD   ' ULONG
   NoOfPMKIDs                           AS DWORD   ' ULONG
   NoOfAuthEncryptPairsSupported        AS DWORD   ' ULONG
   AuthenticationEncryptionSupported(0) AS NDIS_802_11_AUTHENTICATION_ENCRYPTION
END TYPE

' // Size = 40 bytes
TYPE NDIS_802_11_NON_BCAST_SSID_LIST DWORD
   NumberOfItems     AS DWORD              ' ULONG
   Non_Bcast_Ssid(0) AS NDIS_802_11_SSID
END TYPE

'// for OID_802_11_RADIO_STATUS
' enum _NDIS_802_11_RADIO_STATUS
%Ndis802_11RadioStatusOn                  = 0
%Ndis802_11RadioStatusHardwareOff         = 1
%Ndis802_11RadioStatusSoftwareOff         = 2
%Ndis802_11RadioStatusHardwareSoftwareOff = 3
%Ndis802_11RadioStatusMax                 = 4   ' // not a real mode, defined as an upper bound

'//
'// IRDA objects
'//
%OID_IRDA_RECEIVING                      = &H0A010100???
%OID_IRDA_TURNAROUND_TIME                = &H0A010101???
%OID_IRDA_SUPPORTED_SPEEDS               = &H0A010102???
%OID_IRDA_LINK_SPEED                     = &H0A010103???
%OID_IRDA_MEDIA_BUSY                     = &H0A010104???

%OID_IRDA_EXTRA_RCV_BOFS                 = &H0A010200???
%OID_IRDA_RATE_SNIFF                     = &H0A010201???
%OID_IRDA_UNICAST_LIST                   = &H0A010202???
%OID_IRDA_MAX_UNICAST_LIST_SIZE          = &H0A010203???
%OID_IRDA_MAX_RECEIVE_WINDOW_SIZE        = &H0A010204???
%OID_IRDA_MAX_SEND_WINDOW_SIZE           = &H0A010205???
%OID_IRDA_RESERVED1                      = &H0A01020A???  ' // The range between OID_IRDA_RESERVED1
%OID_IRDA_RESERVED2                      = &H0A01020F???  ' // and OID_IRDA_RESERVED2 is reserved


'//
'// IEEE1394 mandatory general OIDs.
'//
%OID_1394_LOCAL_NODE_INFO                = &H0C010101???
%OID_1394_VC_INFO                        = &H0C010102???

'//
'// The following OIDs are not specific to a media.
'//

'//
'// These are objects for Connection-oriented media call-managers.
'//
%OID_CO_ADD_PVC                          = &HFE000001???
%OID_CO_DELETE_PVC                       = &HFE000002???
%OID_CO_GET_CALL_INFORMATION             = &HFE000003???
%OID_CO_ADD_ADDRESS                      = &HFE000004???
%OID_CO_DELETE_ADDRESS                   = &HFE000005???
%OID_CO_GET_ADDRESSES                    = &HFE000006???
%OID_CO_ADDRESS_CHANGE                   = &HFE000007???
%OID_CO_SIGNALING_ENABLED                = &HFE000008???
%OID_CO_SIGNALING_DISABLED               = &HFE000009???
%OID_CO_AF_CLOSE                         = &HFE00000A???

'//
'// Objects for call-managers and MCMs that support TAPI access.
'//
%OID_CO_TAPI_CM_CAPS                     = &HFE001001???
%OID_CO_TAPI_LINE_CAPS                   = &HFE001002???
%OID_CO_TAPI_ADDRESS_CAPS                = &HFE001003???
%OID_CO_TAPI_TRANSLATE_TAPI_CALLPARAMS   = &HFE001004???
%OID_CO_TAPI_TRANSLATE_NDIS_CALLPARAMS   = &HFE001005???
%OID_CO_TAPI_TRANSLATE_TAPI_SAP          = &HFE001006???
%OID_CO_TAPI_GET_CALL_DIAGNOSTICS        = &HFE001007???
%OID_CO_TAPI_REPORT_DIGITS               = &HFE001008???
%OID_CO_TAPI_DONT_REPORT_DIGITS          = &HFE001009???

'//
'//  PnP and PM OIDs
'//
%OID_PNP_CAPABILITIES                    = &HFD010100???
%OID_PNP_SET_POWER                       = &HFD010101???
%OID_PNP_QUERY_POWER                     = &HFD010102???
%OID_PNP_ADD_WAKE_UP_PATTERN             = &HFD010103???
%OID_PNP_REMOVE_WAKE_UP_PATTERN          = &HFD010104???
%OID_PNP_WAKE_UP_PATTERN_LIST            = &HFD010105???
%OID_PNP_ENABLE_WAKE_UP                  = &HFD010106???

'//
'//  PnP/PM Statistics (Optional).
'//
%OID_PNP_WAKE_UP_OK                      = &HFD020200???
%OID_PNP_WAKE_UP_ERROR                   = &HFD020201???

'#if ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)
'//
'// new power management OIDs for NDIS 6.20 drivers
'//

%OID_PM_CURRENT_CAPABILITIES             = &HFD010107???
%OID_PM_HARDWARE_CAPABILITIES            = &HFD010108???
%OID_PM_PARAMETERS                       = &HFD010109???
%OID_PM_ADD_WOL_PATTERN                  = &HFD01010A???
%OID_PM_REMOVE_WOL_PATTERN               = &HFD01010B???
%OID_PM_WOL_PATTERN_LIST                 = &HFD01010C???
%OID_PM_ADD_PROTOCOL_OFFLOAD             = &HFD01010D???
%OID_PM_GET_PROTOCOL_OFFLOAD             = &HFD01010E???
%OID_PM_REMOVE_PROTOCOL_OFFLOAD          = &HFD01010F???
%OID_PM_PROTOCOL_OFFLOAD_LIST            = &HFD010110???

'//
'// new NDIS 6.20 OIDs for generic packet filtering
'//
%OID_RECEIVE_FILTER_HARDWARE_CAPABILITIES        = &H00010221???   ' // query only
%OID_RECEIVE_FILTER_GLOBAL_PARAMETERS            = &H00010222???   ' // query only
%OID_RECEIVE_FILTER_ALLOCATE_QUEUE               = &H00010223???   ' // method only
%OID_RECEIVE_FILTER_FREE_QUEUE                   = &H00010224???   ' // set only
%OID_RECEIVE_FILTER_ENUM_QUEUES                  = &H00010225???   ' // query only
%OID_RECEIVE_FILTER_QUEUE_PARAMETERS             = &H00010226???   ' // method and set
%OID_RECEIVE_FILTER_SET_FILTER                   = &H00010227???   ' // method only
%OID_RECEIVE_FILTER_CLEAR_FILTER                 = &H00010228???   ' // set only
%OID_RECEIVE_FILTER_ENUM_FILTERS                 = &H00010229???   ' // method only
%OID_RECEIVE_FILTER_PARAMETERS                   = &H0001022A???   ' // method only
%OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE    = &H0001022B???   ' // method only
%OID_RECEIVE_FILTER_CURRENT_CAPABILITIES         = &H0001022D???   ' // query only
%OID_NIC_SWITCH_HARDWARE_CAPABILITIES            = &H0001022E???   ' // query only
%OID_NIC_SWITCH_CURRENT_CAPABILITIES             = &H0001022F???   ' // query only


%OID_VLAN_RESERVED1                              = &H00010231???
%OID_VLAN_RESERVED2                              = &H00010232???
%OID_VLAN_RESERVED3                              = &H00010233???
%OID_VLAN_RESERVED4                              = &H00010234???

'#endif // ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)

'//
'//  The following bits are defined for OID_PNP_ENABLE_WAKE_UP
'//
%NDIS_PNP_WAKE_UP_MAGIC_PACKET           = &H00000001???
%NDIS_PNP_WAKE_UP_PATTERN_MATCH          = &H00000002???
%NDIS_PNP_WAKE_UP_LINK_CHANGE            = &H00000004???

'//
'//  TCP/IP OIDs
'//
%OID_TCP_TASK_OFFLOAD                    = &HFC010201???
%OID_TCP_TASK_IPSEC_ADD_SA               = &HFC010202???
%OID_TCP_TASK_IPSEC_DELETE_SA            = &HFC010203???
%OID_TCP_SAN_SUPPORT                     = &HFC010204???
%OID_TCP_TASK_IPSEC_ADD_UDPESP_SA        = &HFC010205???
%OID_TCP_TASK_IPSEC_DELETE_UDPESP_SA     = &HFC010206???
%OID_TCP4_OFFLOAD_STATS                  = &HFC010207???
%OID_TCP6_OFFLOAD_STATS                  = &HFC010208???
%OID_IP4_OFFLOAD_STATS                   = &HFC010209???
%OID_IP6_OFFLOAD_STATS                   = &HFC01020A???
'//
'// new offload OIDs for NDIS 6
'//
%OID_TCP_OFFLOAD_CURRENT_CONFIG          = &HFC01020B???          ' // query only, handled by NDIS
%OID_TCP_OFFLOAD_PARAMETERS              = &HFC01020C???          ' // set only
%OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES   = &HFC01020D???          ' // query only
%OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG = &HFC01020E???        ' // query only
%OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES = &HFC01020F??? ' // query only
%OID_OFFLOAD_ENCAPSULATION               = &H0101010A???

'#IF %NDIS_SUPPORT_NDIS61
'//
'// IPsec Task offload V2 OIDs
'//
%OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA    = &HFC030202???
%OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA = &HFC030203???
%OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA = &HFC030204???
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

'//
'//  Defines for FFP, obsolete
'//
%OID_FFP_SUPPORT                         = &HFC010210???
%OID_FFP_FLUSH                           = &HFC010211???
%OID_FFP_CONTROL                         = &HFC010212???
%OID_FFP_PARAMS                          = &HFC010213???
%OID_FFP_DATA                            = &HFC010214???

%OID_FFP_DRIVER_STATS                    = &HFC020210???
%OID_FFP_ADAPTER_STATS                   = &HFC020211???


'//
'// TCP Connection offload OID
'//
%OID_TCP_CONNECTION_OFFLOAD_PARAMETERS   = &HFC030201???

'#if ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)
'//
'// New Tunnel driver direct OIDs for NDIS 6.20
'//
%OID_TUNNEL_INTERFACE_SET_OID            = &H0f010106???
%OID_TUNNEL_INTERFACE_RELEASE_OID        = &H0f010107???
'#endif // ((NTDDI_VERSION >= NTDDI_WIN7) || NDIS_SUPPORT_NDIS620)

'//
'//  Defines for QOS
'//
%OID_QOS_RESERVED1                       = &HFB010100???
%OID_QOS_RESERVED2                       = &HFB010101???
%OID_QOS_RESERVED3                       = &HFB010102???
%OID_QOS_RESERVED4                       = &HFB010103???
%OID_QOS_RESERVED5                       = &HFB010104???
%OID_QOS_RESERVED6                       = &HFB010105???
%OID_QOS_RESERVED7                       = &HFB010106???
%OID_QOS_RESERVED8                       = &HFB010107???
%OID_QOS_RESERVED9                       = &HFB010108???
%OID_QOS_RESERVED10                      = &HFB010109???
%OID_QOS_RESERVED11                      = &HFB01010A???
%OID_QOS_RESERVED12                      = &HFB01010B???
%OID_QOS_RESERVED13                      = &HFB01010C???
%OID_QOS_RESERVED14                      = &HFB01010D???
%OID_QOS_RESERVED15                      = &HFB01010E???
%OID_QOS_RESERVED16                      = &HFB01010F???
%OID_QOS_RESERVED17                      = &HFB010110???
%OID_QOS_RESERVED18                      = &HFB010111???
%OID_QOS_RESERVED19                      = &HFB010112???
%OID_QOS_RESERVED20                      = &HFB010113???


'//
'// NDIS Proxy OID_GEN_CO_DEVICE_PROFILE structure. The optional OID and
'// this structure is a generic means of describing a CO device's
'// capabilites, and is used by the NDIS Proxy to construct a TAPI device
'// capabilities structure.
'//
' // Size = 120 bytes
TYPE NDIS_CO_DEVICE_PROFILE DWORD
   DeviceDescription           AS NDIS_VAR_DATA_DESC ' // e.g. 'GigabitATMNet'
   DevSpecificInfo             AS NDIS_VAR_DATA_DESC   ' // special features
   ulTAPISupplementaryPassThru AS DWORD    ' ULONG// reserved in NT5
   ulAddressModes              AS DWORD    ' ULONG
   ulNumAddresses              AS DWORD    ' ULONG
   ulBearerModes               AS DWORD    ' ULONG
   ulMaxTxRate                 AS DWORD    ' ULONG // bytes per second
   ulMinTxRate                 AS DWORD    ' ULONG // bytes per second
   ulMaxRxRate                 AS DWORD    ' ULONG // bytes per second
   ulMinRxRate                 AS DWORD    ' ULONG // bytes per second
   ulMediaModes                AS DWORD    ' ULONG
   ' // Tone/digit generation and recognition capabilities
   ulGenerateToneModes         AS DWORD    ' ULONG
   ulGenerateToneMaxNumFreq    AS DWORD    ' ULONG
   ulGenerateDigitModes        AS DWORD    ' ULONG
   ulMonitorToneMaxNumFreq     AS DWORD    ' ULONG
   ulMonitorToneMaxNumEntries  AS DWORD    ' ULONG
   ulMonitorDigitModes         AS DWORD    ' ULONG
   ulGatherDigitsMinTimeout    AS DWORD    ' ULONG // milliseconds
   ulGatherDigitsMaxTimeout    AS DWORD    ' ULONG // milliseconds
   ulDevCapFlags               AS DWORD    ' ULONG // Misc. capabilities
   ulMaxNumActiveCalls         AS DWORD    ' ULONG // (This * ulMinRate) = total bandwidth (which may equal ulMaxRate)
   ulAnswerMode                AS DWORD    ' ULONG // Effect of answering a new call when an
   ' // User-User info sizes allowed to accompany each operation
   ulUUIAcceptSize             AS DWORD    ' ULONG // bytes
   ulUUIAnswerSize             AS DWORD    ' ULONG // bytes
   ulUUIMakeCallSize           AS DWORD    ' ULONG // bytes
   ulUUIDropSize               AS DWORD    ' ULONG      // bytes
   ulUUISendUserUserInfoSize   AS DWORD    ' ULONG // bytes
   ulUUICallInfoSize           AS DWORD    ' ULONG // bytes
END TYPE

'//
'//  Structures for TCP IPsec.
'//
'#ifndef IP_EXPORT_INCLUDED
'typedef ULONG   IPAddr, IPMask;
'#endif
'typedef ULONG   SPI_TYPE;

' enum OFFLOAD_OPERATION_E
'AUTHENTICATE;
'ENCRYPT;
%OFFLOAD_OPERATION_E_AUTHENTICATE = 1
%OFFLOAD_OPERATION_E_ENCRYPT = 2

' // Size = 12 bytes
TYPE OFFLOAD_ALGO_INFO DWORD
   algoIdentifier AS DWORD   ' ULONG
   algoKeylen     AS DWORD   ' ULONG
   algoRounds     AS DWORD   ' ULONG
END TYPE

' enum OFFLOAD_CONF_ALGO
%OFFLOAD_IPSEC_CONF_NONE     = 0
%OFFLOAD_IPSEC_CONF_DES      = 1
%OFFLOAD_IPSEC_CONF_RESERVED = 2
%OFFLOAD_IPSEC_CONF_3_DES    = 3
%OFFLOAD_IPSEC_CONF_MAX      = 4

' enum _OFFLOAD_INTEGRITY_ALGO
%OFFLOAD_IPSEC_INTEGRITY_NONE = 0
%OFFLOAD_IPSEC_INTEGRITY_MD5  = 1
%OFFLOAD_IPSEC_INTEGRITY_SHA  = 2
%OFFLOAD_IPSEC_INTEGRITY_MAX  = 3

' // Size = 44 bytes
TYPE OFFLOAD_SECURITY_ASSOCIATION DWORD
   Operation     AS LONG                ' OFFLOAD_OPERATION_E
   SPI           AS DWORD               ' SPI_TYPE
   IntegrityAlgo AS OFFLOAD_ALGO_INFO
   ConfAlgo      AS OFFLOAD_ALGO_INFO
   Reserved      AS OFFLOAD_ALGO_INFO
END TYPE

%OFFLOAD_MAX_SAS            = 3

%OFFLOAD_INBOUND_SA         = &H0001???
%OFFLOAD_OUTBOUND_SA        = &H0002???

' // Size = 180 bytes
TYPE OFFLOAD_IPSEC_ADD_SA
   SrcAddr        AS DWORD     ' IPAddr
   SrcMask        AS DWORD     ' IPMask
   DestAddr       AS DWORD     ' IPAddr
   DestMask       AS DWORD     ' IPMask
   Protocol       AS DWORD     ' ULONG
   SrcPort        AS WORD      ' USHORT
   DestPort       AS WORD      ' USHORT
   SrcTunnelAddr  AS DWORD     ' IPAddr
   DestTunnelAddr AS DWORD     ' IPAddr
   Flags          AS WORD      ' USHORT
   NumSAs         AS INTEGER   ' INTEGER
   SecAssoc(%OFFLOAD_MAX_SAS - 1) AS OFFLOAD_SECURITY_ASSOCIATION
   OffloadHandle  AS DWORD     ' HANDLE
   KeyLen         AS DWORD     ' ULONG
   KeyMat(3)      AS BYTE      ' UCHAR
   ' Note: We are using KeyMat(3) instead of KeyMat(0) to keep DWORD alignment
END TYPE

' // Size = 4 bytes
TYPE OFFLOAD_IPSEC_DELETE_SA DWORD
   OffloadHandle AS DWORD   ' HANDLE
END TYPE

' enum _UDP_ENCAP_TYPE
%OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_IKE   = 0
%OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_OTHER = 1

' // Size = 8 bytes
TYPE OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY DWORD
   UdpEncapType AS LONG   ' UDP_ENCAP_TYPE
   DstEncapPort AS WORD   ' USHORT
END TYPE

' // Size = 192 bytes
TYPE OFFLOAD_IPSEC_ADD_UDPESP_SA
   SrcAddr                        AS DWORD   ' IPAddr
   SrcMask                        AS DWORD   ' IPMask
   DstAddr                        AS DWORD   ' IPAddr
   DstMask                        AS DWORD   ' IPMask
   Protocol                       AS DWORD   ' ULONG
   SrcPort                        AS WORD   'USHORT
   DstPort                        AS WORD   ' USHORT
   SrcTunnelAddr                  AS DWORD   ' IPAddr
   DstTunnelAddr                  AS DWORD   ' IPAddr
   Flags                          AS WORD   ' USHORT
   NumSAs                         AS INTEGER   ' SHORT
   SecAssoc(%OFFLOAD_MAX_SAS - 1) AS OFFLOAD_SECURITY_ASSOCIATION
   OffloadHandle                  AS DWORD   ' HANDLE
   EncapTypeEntry                 AS OFFLOAD_IPSEC_UDPESP_ENCAPTYPE_ENTRY
   EncapTypeEntryOffldHandle      AS DWORD   ' HANDLE
   KeyLen                         AS DWORD   ' ULONG
   KeyMat(3)                      AS BYTE    ' UCHAR
   ' Note: We are using KeyMat(3) instead of KeyMat(0) to keep DWORD alignment
END TYPE


' // Size = 8 bytes
TYPE OFFLOAD_IPSEC_DELETE_UDPESP_SA DWORD
   OffloadHandle             AS DWORD   ' HANDLE
   EncapTypeEntryOffldHandle AS DWORD   ' HANDLE
END TYPE


'//
'// Type to go with OID_GEN_VLAN_ID: the least significant 12 bits are
'// used as the VLAN ID (VID) per IEEE 802.1Q. Higher order bits are
'// reserved and must be set to 0.
'//
'typedef ULONG NDIS_VLAN_ID;

'//
'// Medium the Ndis Driver is running on (OID_GEN_MEDIA_SUPPORTED/ OID_GEN_MEDIA_IN_USE).
'//
' enum _NDIS_MEDIUM
%NdisMedium802_3        = 0
%NdisMedium802_5        = 1
%NdisMediumFddi         = 2
%NdisMediumWan          = 3
%NdisMediumLocalTalk    = 4
%NdisMediumDix          = 5    ' // defined for convenience, not a real medium
%NdisMediumArcnetRaw    = 6
%NdisMediumArcnet878_2  = 7
%NdisMediumAtm          = 8
%NdisMediumWirelessWan  = 9
%NdisMediumIrda         = 10
%NdisMediumBpc          = 11
%NdisMediumCoWan        = 12
%NdisMedium1394         = 13
%NdisMediumInfiniBand   = 14
'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
%NdisMediumTunnel       = 15
%NdisMediumNative802_11 = 16
%NdisMediumLoopback     = 17
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%NdisMediumWiMAX        = 18
%NdisMediumIP           = 19
'#endif
%NdisMediumMax          = 20   ' // Not a real medium, defined as an upper-bound


'//
'// Physical Medium Type definitions. Used with OID_GEN_PHYSICAL_MEDIUM.
'//
' enum _NDIS_PHYSICAL_MEDIUM
%NdisPhysicalMediumUnspecified  = 0
%NdisPhysicalMediumWirelessLan  = 1
%NdisPhysicalMediumCableModem   = 2
%NdisPhysicalMediumPhoneLine    = 3
%NdisPhysicalMediumPowerLine    = 4
%NdisPhysicalMediumDSL          = 5    ' // includes ADSL and UADSL (G.Lite)
%NdisPhysicalMediumFibreChannel = 6
%NdisPhysicalMedium1394         = 7
%NdisPhysicalMediumWirelessWan  = 8
%NdisPhysicalMediumNative802_11 = 9
%NdisPhysicalMediumBluetooth    = 10
%NdisPhysicalMediumInfiniband   = 11
%NdisPhysicalMediumWiMax        = 12
%NdisPhysicalMediumUWB          = 13
%NdisPhysicalMedium802_3        = 14
%NdisPhysicalMedium802_5        = 15
%NdisPhysicalMediumIrda         = 16
%NdisPhysicalMediumWiredWAN     = 17
%NdisPhysicalMediumWiredCoWan   = 18
%NdisPhysicalMediumOther        = 19
%NdisPhysicalMediumMax          = 20   ' // Not a real physical type =  defined as an upper-bound


'//
'//  Protocol types supported by ndis. These values need to be consistent with ADDRESS_TYPE_XXX defined in TDI.H
'//
%NDIS_PROTOCOL_ID_DEFAULT        = &H00
%NDIS_PROTOCOL_ID_TCP_IP         = &H02
%NDIS_PROTOCOL_ID_IPX            = &H06
%NDIS_PROTOCOL_ID_NBF            = &H07
%NDIS_PROTOCOL_ID_MAX            = &H0F
%NDIS_PROTOCOL_ID_MASK           = &H0F

'//
'// The following is used with OID_GEN_TRANSPORT_HEADER_OFFSET to indicate the length of the layer-2 header
'// for packets sent by a particular protocol.
'//
' // Size = 4 bytes
TYPE TRANSPORT_HEADER_OFFSET WORD
   ProtocolType AS WORD   ' USHORT // The protocol that is sending this OID (NDIS_PROTOCOL_ID_XXX above)
   HeaderOffset AS WORD   ' USHORT // The header offset
END TYPE


'//
'// The structures below need to be consistent with TRANSPORT_ADDRESS structures in TDI.H
'//
' // Size = 6 bytes
TYPE NETWORK_ADDRESS WORD
   AddressLength AS WORD   ' USHORT // length in bytes of Address[] in this
   AddressType   AS WORD   ' USHORT // type of this address (NDIS_PROTOCOL_ID_XXX above)
   Address(0)    AS BYTE   ' UCHAR // actually AddressLength bytes long
END TYPE

'//
'// The following is used with OID_GEN_NETWORK_LAYER_ADDRESSES to set network layer addresses on an interface
'//
' // Size = 12 bytes
TYPE NETWORK_ADDRESS_LIST WORD
   AddressCount AS LONG              ' LONG // number of addresses following
   AddressType  AS WORD              ' USHORT // type of this address (NDIS_PROTOCOL_ID_XXX above)
   Address(0)   AS NETWORK_ADDRESS   ' // actually AddressCount elements long
END TYPE

'//
'// IP address - This must remain consistent with TDI_ADDRESS_IP in tdi.h
'//
' // Size = 16 bytes
TYPE NETWORK_ADDRESS_IP DWORD
   sin_port    AS WORD    ' USHORT
   in_addr     AS DWORD   ' ULONG
   sin_zero(7) AS BYTE    ' UCHAR
END TYPE

'#define NETWORK_ADDRESS_LENGTH_IP sizeof (NETWORK_ADDRESS_IP)

'//
'// IPX address - This must remain consistent with TDI_ADDRESS_IPX in tdi.h.
'//
' // Size = 12 bytes
TYPE NETWORK_ADDRESS_IPX WORD
   NetworkAddress AS DWORD   ' ULONG
   NodeAddress(5) AS BYTE    ' UCHAR
   Socket         AS WORD    ' USHORT
END TYPE

'#define NETWORK_ADDRESS_LENGTH_IPX sizeof (NETWORK_ADDRESS_IPX)

'//
'// Hardware status codes (OID_GEN_HARDWARE_STATUS).
'//

' enum _NDIS_HARDWARE_STATUS
%NdisHardwareStatusReady        = 0
%NdisHardwareStatusInitializing = 1
%NdisHardwareStatusReset        = 2
%NdisHardwareStatusClosing      = 3
%NdisHardwareStatusNotReady     = 4

'//
'// this is the type passed in the OID_GEN_GET_TIME_CAPS request
'//
' // Size = 8 bytes
TYPE GEN_GET_TIME_CAPS DWORD
   Flags          AS DWORD   ' ULONG // Bits defined below
   ClockPrecision AS DWORD   ' ULONG
END TYPE

%READABLE_LOCAL_CLOCK                    = &H00000001???
%CLOCK_NETWORK_DERIVED                   = &H00000002???
%CLOCK_PRECISION                         = &H00000004???
%RECEIVE_TIME_INDICATION_CAPABLE         = &H00000008???
%TIMED_SEND_CAPABLE                      = &H00000010???
%TIME_STAMP_CAPABLE                      = &H00000020???

'//
'// this is the type passed in the OID_GEN_GET_NETCARD_TIME request
'//
' // Size = 8 bytes
TYPE GEN_GET_NETCARD_TIME QWORD
   ReadTime AS QUAD   ' ULONGLONG
END TYPE

'//
'//  NDIS PnP routines and definitions.
'//
' // Size = 24 bytes
TYPE NDIS_PM_PACKET_PATTERN DWORD
   Priority      AS DWORD   ' ULONG // Importance of the given pattern.
   Reserved      AS DWORD   ' ULONG // Context information for transports.
   MaskSize      AS DWORD   ' ULONG // Size in bytes of the pattern mask.
   PatternOffset AS DWORD   ' ULONG // Offset from beginning of this
                                       ' // structure to the pattern bytes.
   PatternSize   AS DWORD   ' ULONG // Size in bytes of the pattern.
   PatternFlags  AS DWORD   ' ULONG // Flags (TBD).
END TYPE


'//
'//  The following structure defines the device power states.
'//
' enum _NDIS_DEVICE_POWER_STATE
%NdisDeviceStateUnspecified = 0
%NdisDeviceStateD0          = 1
%NdisDeviceStateD1          = 2
%NdisDeviceStateD2          = 3
%NdisDeviceStateD3          = 4
%NdisDeviceStateMaximum     = 5

'//
'//  The following structure defines the wake-up capabilities of the device.
'//
' // Size = 12 bytes
TYPE NDIS_PM_WAKE_UP_CAPABILITIES DWORD
   MinMagicPacketWakeUp AS LONG   ' NDIS_DEVICE_POWER_STATE
   MinPatternWakeUp     AS LONG   ' NDIS_DEVICE_POWER_STATE
   MinLinkChangeWakeUp  AS LONG   ' NDIS_DEVICE_POWER_STATE
END TYPE

'//
'// the following flags define the -enabled- wake-up capabilities of the device
'// passed in the Flags field of NDIS_PNP_CAPABILITIES structure
'//
%NDIS_DEVICE_WAKE_UP_ENABLE                          = &H00000001???
%NDIS_DEVICE_WAKE_ON_PATTERN_MATCH_ENABLE            = &H00000002???
%NDIS_DEVICE_WAKE_ON_MAGIC_PACKET_ENABLE             = &H00000004???

'//
'//  This structure defines general PnP capabilities of the miniport driver.
'//
' // Size = 16 bytes
TYPE NDIS_PNP_CAPABILITIES DWORD
   Flags              AS DWORD   ' ULONG
   WakeUpCapabilities AS NDIS_PM_WAKE_UP_CAPABILITIES
END TYPE

'//
'// Defines the attachment types for FDDI (OID_FDDI_ATTACHMENT_TYPE).
'//
' enum _NDIS_FDDI_ATTACHMENT_TYPE
%NdisFddiTypeIsolated = 1
%NdisFddiTypeLocalA   = 2
%NdisFddiTypeLocalB   = 3
%NdisFddiTypeLocalAB  = 4
%NdisFddiTypeLocalS   = 5
%NdisFddiTypeWrapA    = 6
%NdisFddiTypeWrapB    = 7
%NdisFddiTypeWrapAB   = 8
%NdisFddiTypeWrapS    = 9
%NdisFddiTypeCWrapA   = 10
%NdisFddiTypeCWrapB   = 11
%NdisFddiTypeCWrapS   = 12
%NdisFddiTypeThrough  = 13

'//
'// Defines the ring management states for FDDI (OID_FDDI_RING_MGT_STATE).
'//
' enum _NDIS_FDDI_RING_MGT_STATE
%NdisFddiRingIsolated          = 1
%NdisFddiRingNonOperational    = 2
%NdisFddiRingOperational       = 3
%NdisFddiRingDetect            = 4
%NdisFddiRingNonOperationalDup = 5
%NdisFddiRingOperationalDup    = 6
%NdisFddiRingDirected          = 7
%NdisFddiRingTrace             = 8

'//
'// Defines the Lconnection state for FDDI (OID_FDDI_LCONNECTION_STATE).
'//
' enum _NDIS_FDDI_LCONNECTION_STATE
%NdisFddiStateOff         = 1
%NdisFddiStateBreak       = 2
%NdisFddiStateTrace       = 3
%NdisFddiStateConnect     = 4
%NdisFddiStateNext        = 5
%NdisFddiStateSignal      = 6
%NdisFddiStateJoin        = 7
%NdisFddiStateVerify      = 8
%NdisFddiStateActive      = 9
%NdisFddiStateMaintenance = 10

'//
'// Defines the medium subtypes for WAN medium (OID_WAN_MEDIUM_SUBTYPE).
'// Sub-medium used only by connection-oriented WAN devices
'// i.e. NdisMediumWan, NdisMediumCoWan.
'//
' enum _NDIS_WAN_MEDIUM_SUBTYPE
%NdisWanMediumHub        = 0
%NdisWanMediumX_25       = 1
%NdisWanMediumIsdn       = 2
%NdisWanMediumSerial     = 3
%NdisWanMediumFrameRelay = 4
%NdisWanMediumAtm        = 5
%NdisWanMediumSonet      = 6
%NdisWanMediumSW56K      = 7
%NdisWanMediumPPTP       = 8
%NdisWanMediumL2TP       = 9
%NdisWanMediumIrda       = 10
%NdisWanMediumParallel   = 11
%NdisWanMediumPppoe      = 12
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%NdisWanMediumSSTP       = 13
%NdisWanMediumAgileVPN   = 14
'#endif //(NTDDI_VERSION >= NTDDI_VISTA)

'//
'// Defines the header format for WAN medium (OID_WAN_HEADER_FORMAT).
'//
' enum _NDIS_WAN_HEADER_FORMAT
%NdisWanHeaderNative   = 0   ' // src/dest based on subtype, followed by NLPID
%NdisWanHeaderEthernet = 1   ' // emulation of ethernet header

'//
'// Defines the line quality on a WAN line (OID_WAN_QUALITY_OF_SERVICE).
'//
' enum _NDIS_WAN_QUALITY
%NdisWanRaw          = 0
%NdisWanErrorControl = 1
%NdisWanReliable     = 2

'//
'// Defines a protocol's WAN specific capabilities (OID_WAN_PROTOCOL_CAPS).
'//
' // Size = 8 bytes
TYPE NDIS_WAN_PROTOCOL_CAPS DWORD
   Flags    AS DWORD   ' __in ULONG
   Reserved AS DWORD   ' __in ULONG
END TYPE


'//
'// Flags used in NDIS_WAN_PROTOCOL_CAPS
'//
%WAN_PROTOCOL_KEEPS_STATS    = &H00000001???


'//
'// Defines the state of a token-ring adapter (OID_802_5_CURRENT_RING_STATE).
'//
' enum _NDIS_802_5_RING_STATE
%NdisRingStateOpened      = 1
%NdisRingStateClosed      = 2
%NdisRingStateOpening     = 3
%NdisRingStateClosing     = 4
%NdisRingStateOpenFailure = 5
%NdisRingStateRingFailure = 6

'//
'// Defines the state of the LAN media
'//
' enum _NDIS_MEDIA_STATE
%NdisMediaStateConnected    = 0
%NdisMediaStateDisconnected = 1

'//
'// The following is set on a per-packet basis as OOB data with NdisClass802_3Priority
'//
'typedef ULONG   Priority_802_3;         // 0-7 priority levels

'//
'//  The following structure is used to query OID_GEN_CO_LINK_SPEED and
'//  OID_GEN_CO_MINIMUM_LINK_SPEED. The first OID will return the current
'//  link speed of the adapter. The second will return the minimum link speed
'//  the adapter is capable of.
'//
' // Size = 8 bytes
TYPE NDIS_CO_LINK_SPEED DWORD
   Outbound AS DWORD   ' ULONG
   Inbound  AS DWORD   ' ULONG
END TYPE

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)

'//
'// The following structure is used in OID_GEN_LINK_SPEED_EX for interfaces
'// and is expressed in bits per second.
'//

' // Size = 16 bytes
TYPE NDIS_LINK_SPEED QWORD
   XmitLinkSpeed AS QUAD   ' ULONG64
   RcvLinkSpeed  AS QUAD   ' ULONG64
END TYPE

'// miniports or interfaces that do not know their current link speed
'// can report NDIS_LINK_SPEED_UNKNOWN == ((ULONG64)-1)
%NDIS_LINK_SPEED_UNKNOWN = %NET_IF_LINK_SPEED_UNKNOWN
'#endif

'#ifndef _NDIS_
'typedef int NDIS_STATUS, *PNDIS_STATUS;
'#endif

'//
'//  Structure to be used for OID_GEN_SUPPORTED_GUIDS.
'//  This structure describes an OID to GUID mapping.
'//  Or a Status to GUID mapping.
'//  When ndis receives a request for a give GUID it will
'//  query the miniport with the supplied OID.
'//
'typedef struct _NDIS_GUID
'{
'    GUID            Guid;
'    union
'    {
'        NDIS_OID    Oid;
'        NDIS_STATUS Status;
'    };
'    ULONG       Size;               //  Size of the data element. If the GUID
'                                    //  represents an array then this is the
'                                    //  size of an element in the array.
'                                    //  This is -1 for strings.
'    ULONG       Flags;
'} NDIS_GUID, *PNDIS_GUID;

' // Size = 4 bytes
UNION NDIS_GUID_UNION DWORD
   Oid    AS DWORD   ' NDIS_OID
   Status AS LONG    ' NDIS_STATUS
END UNION

' // Size = 28 bytes
TYPE NDIS_GUID DWORD
   Guid  AS GUID
   NDIS_GUID_UNION
   Size  AS DWORD   ' ULONG //  Size of the data element. If the GUID
                    '       //  represents an array then this is the
                    '       //  size of an element in the array.
                    '       //  This is -1 for strings.
   Flags AS DWORD   ' ULONG
END TYPE

%fNDIS_GUID_TO_OID                   = &H00000001???
%fNDIS_GUID_TO_STATUS                = &H00000002???
%fNDIS_GUID_ANSI_STRING              = &H00000004???
%fNDIS_GUID_UNICODE_STRING           = &H00000008???
%fNDIS_GUID_ARRAY                    = &H00000010???
%fNDIS_GUID_ALLOW_READ               = &H00000020???
%fNDIS_GUID_ALLOW_WRITE              = &H00000040???
%fNDIS_GUID_METHOD                   = &H00000080???
%fNDIS_GUID_NDIS_RESERVED            = &H00000100???
%fNDIS_GUID_SUPPORT_COMMON_HEADER    = &H00000200???

'//
'// Ndis Packet Filter Bits (OID_GEN_CURRENT_PACKET_FILTER).
'//
%NDIS_PACKET_TYPE_DIRECTED               = &H00000001???
%NDIS_PACKET_TYPE_MULTICAST              = &H00000002???
%NDIS_PACKET_TYPE_ALL_MULTICAST          = &H00000004???
%NDIS_PACKET_TYPE_BROADCAST              = &H00000008???
%NDIS_PACKET_TYPE_SOURCE_ROUTING         = &H00000010???
%NDIS_PACKET_TYPE_PROMISCUOUS            = &H00000020???
%NDIS_PACKET_TYPE_SMT                    = &H00000040???
%NDIS_PACKET_TYPE_ALL_LOCAL              = &H00000080???
%NDIS_PACKET_TYPE_GROUP                  = &H00001000???
%NDIS_PACKET_TYPE_ALL_FUNCTIONAL         = &H00002000???
%NDIS_PACKET_TYPE_FUNCTIONAL             = &H00004000???
%NDIS_PACKET_TYPE_MAC_FRAME              = &H00008000???
%NDIS_PACKET_TYPE_NO_LOCAL               = &H00010000???

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)
'// Native 802.11 Definitions
#IF %DEF(%NDIS_SUPPORT_NDIS6) OR %WINVER >= &H0600
#IF NOT %DEF(%WINDOT11_INC)
#INCLUDE ONCE "windot11.inc"
#ENDIF
#ENDIF
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// Ndis Token-Ring Ring Status Codes (OID_802_5_CURRENT_RING_STATUS).
'//
%NDIS_RING_SIGNAL_LOSS                   = &H00008000???
%NDIS_RING_HARD_ERROR                    = &H00004000???
%NDIS_RING_SOFT_ERROR                    = &H00002000???
%NDIS_RING_TRANSMIT_BEACON               = &H00001000???
%NDIS_RING_LOBE_WIRE_FAULT               = &H00000800???
%NDIS_RING_AUTO_REMOVAL_ERROR            = &H00000400???
%NDIS_RING_REMOVE_RECEIVED               = &H00000200???
%NDIS_RING_COUNTER_OVERFLOW              = &H00000100???
%NDIS_RING_SINGLE_STATION                = &H00000080???
%NDIS_RING_RING_RECOVERY                 = &H00000040???


'//
'// Ndis protocol option bits (OID_GEN_PROTOCOL_OPTIONS).
'//
%NDIS_PROT_OPTION_ESTIMATED_LENGTH               = &H00000001???
%NDIS_PROT_OPTION_NO_LOOPBACK                    = &H00000002???
%NDIS_PROT_OPTION_NO_RSVD_ON_RCVPKT              = &H00000004???
%NDIS_PROT_OPTION_SEND_RESTRICTED                = &H00000008???

'//
'// Ndis MAC option bits (OID_GEN_MAC_OPTIONS).
'//
%NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA             = &H00000001???
%NDIS_MAC_OPTION_RECEIVE_SERIALIZED              = &H00000002???
%NDIS_MAC_OPTION_TRANSFERS_NOT_PEND              = &H00000004???
%NDIS_MAC_OPTION_NO_LOOPBACK                     = &H00000008???

'//
'// This flag has been deprecated. Deserialized drivers are
'// full duplex drivers
'//
%NDIS_MAC_OPTION_FULL_DUPLEX                     = &H00000010???  ' // deprecated


%NDIS_MAC_OPTION_EOTX_INDICATION                 = &H00000020???
%NDIS_MAC_OPTION_8021P_PRIORITY                  = &H00000040???
%NDIS_MAC_OPTION_SUPPORTS_MAC_ADDRESS_OVERWRITE  = &H00000080???
%NDIS_MAC_OPTION_RECEIVE_AT_DPC                  = &H00000100???
%NDIS_MAC_OPTION_8021Q_VLAN                      = &H00000200???
%NDIS_MAC_OPTION_RESERVED                        = &H80000000???

'//
'//  NDIS media capabilities bits (OID_GEN_MEDIA_CAPABILITIES).
'//
%NDIS_MEDIA_CAP_TRANSMIT                 = &H00000001???  ' // Supports sending data
%NDIS_MEDIA_CAP_RECEIVE                  = &H00000002???  ' // Supports receiving data

'//
'//  NDIS MAC option bits for OID_GEN_CO_MAC_OPTIONS.
'//
%NDIS_CO_MAC_OPTION_DYNAMIC_LINK_SPEED   = &H00000001???

'//
'// The following is set on a per-packet basis as OOB data with NdisClassIrdaPacketInfo
'// This is the per-packet info specified on a per-packet basis
'//
' // Size = 8 bytes
TYPE NDIS_IRDA_PACKET_INFO DWORD
   ExtraBOFs         AS DWORD   ' ULONG
   MinTurnAroundTime AS DWORD   ' ULONG
END TYPE


'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)

'//
'// The following macro is used to build a NET_LUID
'//

'#define NDIS_MAKE_NET_LUID(_pNetLuid, _IfType, _NetLuidIndex)       \
'{                                                                   \
'    (_pNetLuid)->Info.IfType = _IfType;                             \
'    (_pNetLuid)->Info.NetLuidIndex = _NetLuidIndex;                 \
'    (_pNetLuid)->Info.Reserved = 0;                                 \
'}

%NDIS_IF_MAX_STRING_SIZE = %IF_MAX_STRING_SIZE
'typedef IF_COUNTED_STRING NDIS_IF_COUNTED_STRING, *PNDIS_IF_COUNTED_STRING;
MACRO NDIS_IF_COUNTED_STRING = IF_COUNTED_STRING

%NDIS_MAX_PHYS_ADDRESS_LENGTH = %IF_MAX_PHYS_ADDRESS_LENGTH
'typedef IF_PHYSICAL_ADDRESS NDIS_IF_PHYSICAL_ADDRESS, *PNDIS_IF_PHYSICAL_ADDRESS;
MACRO NDIS_IF_PHYSICAL_ADDRESS = IF_PHYSICAL_ADDRESS

'//
'// NDIS_MEDIA_CONNECT_STATE enum type is used in OID_GEN_MEDIA_CONNECT_STATUS_EX
'//
'typedef NET_IF_MEDIA_CONNECT_STATE NDIS_MEDIA_CONNECT_STATE, *PNDIS_MEDIA_CONNECT_STATE;

'//
'// NET_IF_MEDIA_DUPLEX_STATE enum type is used in OID_GEN_MEDIA_DUPLEX_STATE
'//
'typedef NET_IF_MEDIA_DUPLEX_STATE NDIS_MEDIA_DUPLEX_STATE, *PNDIS_MEDIA_DUPLEX_STATE;

' enum _NDIS_SUPPORTED_PAUSE_FUNCTIONS
%NdisPauseFunctionsUnsupported    = 0
%NdisPauseFunctionsSendOnly       = 1
%NdisPauseFunctionsReceiveOnly    = 2
%NdisPauseFunctionsSendAndReceive = 3
%NdisPauseFunctionsUnknown        = 4

%NDIS_LINK_STATE_XMIT_LINK_SPEED_AUTO_NEGOTIATED = &H00000001???
%NDIS_LINK_STATE_RCV_LINK_SPEED_AUTO_NEGOTIATED  = &H00000002???
%NDIS_LINK_STATE_DUPLEX_AUTO_NEGOTIATED          = &H00000004???
%NDIS_LINK_STATE_PAUSE_FUNCTIONS_AUTO_NEGOTIATED = &H00000008???

'//
'// structure used in NDIS_STATUS_LINK_STATE and OID_GEN_LINK_STATE
'//

%NDIS_LINK_STATE_REVISION_1 = 1

' // Size = 40 bytes
TYPE NDIS_LINK_STATE QWORD FILL
   Header               AS NDIS_OBJECT_HEADER
   MediaConnectState    AS LONG    ' NDIS_MEDIA_CONNECT_STATE enum
   MediaDuplexState     AS LONG    ' NDIS_MEDIA_DUPLEX_STATE
   XmitLinkSpeed        AS QUAD    ' ULONG64
   RcvLinkSpeed         AS QUAD    ' ULONG64
   PauseFunctions       AS LONG    ' NDIS_SUPPORTED_PAUSE_FUNCTIONS
   AutoNegotiationFlags AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_LINK_STATE_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_LINK_STATE, AutoNegotiationFlags)

'//
'// the following structure is used in OID_GEN_LINK_PARAMETERS
'//

%NDIS_LINK_PARAMETERS_REVISION_1 = 1

' // Size = 32 bytes
TYPE NDIS_LINK_PARAMETERS QWORD FILL
   Header               AS NDIS_OBJECT_HEADER
   MediaDuplexState     AS LONG    ' NDIS_MEDIA_DUPLEX_STATE
   XmitLinkSpeed        AS QUAD    ' ULONG64
   RcvLinkSpeed         AS QUAD    ' ULONG64
   PauseFunctions       AS LONG    ' NDIS_SUPPORTED_PAUSE_FUNCTIONS
   AutoNegotiationFlags AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_LINK_PARAMETERS_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_LINK_PARAMETERS, AutoNegotiationFlags)

'//
'// structure used in NDIS_STATUS_LINK_STATE and OID_GEN_LINK_STATE
'//

%NDIS_OPER_STATE_REVISION_1 = 1

' // Size = 12 bytes
TYPE NDIS_OPER_STATE DWORD
   Header                 AS NDIS_OBJECT_HEADER
   OperationalStatus      AS LONG    ' NET_IF_OPER_STATUS
   OperationalStatusFlags AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_OPER_STATE_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_OPER_STATE, OperationalStatusFlags)

'//
'// Structure used in OID_GEN_IP_OPER_STATUS.
'//

' // Size = 12 bytes
TYPE NDIS_IP_OPER_STATUS DWORD
   AddressFamily          AS DWORD   ' ULONG
   OperationalStatus      AS LONG    ' NET_IF_OPER_STATUS
   OperationalStatusFlags AS DWORD   ' ULONG
END TYPE

'//
'// Don't change the value for this macro definition.
'//
%MAXIMUM_IP_OPER_STATUS_ADDRESS_FAMILIES_SUPPORTED = 32

%NDIS_IP_OPER_STATUS_INFO_REVISION_1 = 1

' // Size = 396 bytes
TYPE NDIS_IP_OPER_STATUS_INFO DWORD
   Header                          AS NDIS_OBJECT_HEADER
   Flags                           AS DWORD   ' ULONG
   NumberofAddressFamiliesReturned AS DWORD   ' ULONG
   IpOperationalStatus(%MAXIMUM_IP_OPER_STATUS_ADDRESS_FAMILIES_SUPPORTED - 1) AS NDIS_IP_OPER_STATUS
END TYPE

'#define NDIS_SIZEOF_IP_OPER_STATUS_INFO_REVISION_1    \
'        FIELD_OFFSET(NDIS_IP_OPER_STATUS_INFO, IpOperationalStatus) + \
'        MAXIMUM_IP_OPER_STATUS_ADDRESS_FAMILIES_SUPPORTED * sizeof(NDIS_IP_OPER_STATUS)

'//
'// structure used in NDIS_STATUS_IP_OPER_STATUS
'//

%NDIS_IP_OPER_STATE_REVISION_1 = 1

' // Size = 20 bytes
TYPE NDIS_IP_OPER_STATE DWORD
   Header              AS NDIS_OBJECT_HEADER
   Flags               AS DWORD   ' ULONG
   IpOperationalStatus AS NDIS_IP_OPER_STATUS
END TYPE

'#define NDIS_SIZEOF_IP_OPER_STATE_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_IP_OPER_STATE, IpOperationalStatus)

'//
'// These defines and structures are used with
'// OID_TCP_OFFLOAD_PARAMETERS
'//

%NDIS_OFFLOAD_PARAMETERS_NO_CHANGE                   = 0

'//
'// values used in IPv4Checksum, TCPIPv4Checksum, UDPIPv4Checksum
'// TCPIPv6Checksum and UDPIPv6Checksum
'//
%NDIS_OFFLOAD_PARAMETERS_TX_RX_DISABLED              = 1
%NDIS_OFFLOAD_PARAMETERS_TX_ENABLED_RX_DISABLED      = 2
%NDIS_OFFLOAD_PARAMETERS_RX_ENABLED_TX_DISABLED      = 3
%NDIS_OFFLOAD_PARAMETERS_TX_RX_ENABLED               = 4

'//
'// values used in LsoV1
'//
%NDIS_OFFLOAD_PARAMETERS_LSOV1_DISABLED              = 1
%NDIS_OFFLOAD_PARAMETERS_LSOV1_ENABLED               = 2

'//
'// values used in IPsecV1
'//
%NDIS_OFFLOAD_PARAMETERS_IPSECV1_DISABLED            = 1
%NDIS_OFFLOAD_PARAMETERS_IPSECV1_AH_ENABLED          = 2
%NDIS_OFFLOAD_PARAMETERS_IPSECV1_ESP_ENABLED         = 3
%NDIS_OFFLOAD_PARAMETERS_IPSECV1_AH_AND_ESP_ENABLED  = 4

'//
'// values used in LsoV2
'//
%NDIS_OFFLOAD_PARAMETERS_LSOV2_DISABLED              = 1
%NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED               = 2

'#IF %NDIS_SUPPORT_NDIS61
'//
'// values used in IPsecV2 and IPsecV2IPv4
'//
%NDIS_OFFLOAD_PARAMETERS_IPSECV2_DISABLED            = 1
%NDIS_OFFLOAD_PARAMETERS_IPSECV2_AH_ENABLED          = 2
%NDIS_OFFLOAD_PARAMETERS_IPSECV2_ESP_ENABLED         = 3
%NDIS_OFFLOAD_PARAMETERS_IPSECV2_AH_AND_ESP_ENABLED  = 4
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

'//
'// values used in TcpConnectionIPv4 and TcpConnectionIPv6 fields
'// of NDIS_OFFLOAD_PARAMETERS
'//
%NDIS_OFFLOAD_PARAMETERS_CONNECTION_OFFLOAD_DISABLED = 1
%NDIS_OFFLOAD_PARAMETERS_CONNECTION_OFFLOAD_ENABLED  = 2

'//
'// Used in OID_TCP_OFFLOAD_PARAMETERS for setting
'// the offload parameters of a NIC
'//

%NDIS_OFFLOAD_PARAMETERS_REVISION_1 = 1

'#IF %NDIS_SUPPORT_NDIS61
%NDIS_OFFLOAD_PARAMETERS_REVISION_2 = 2
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

' // Size = 20/24 bytes
TYPE NDIS_OFFLOAD_PARAMETERS DWORD FILL
   Header            AS NDIS_OBJECT_HEADER
   IPv4Checksum      AS BYTE    ' UCHAR
   TCPIPv4Checksum   AS BYTE    ' UCHAR
   UDPIPv4Checksum   AS BYTE    ' UCHAR
   TCPIPv6Checksum   AS BYTE    ' UCHAR
   UDPIPv6Checksum   AS BYTE    ' UCHAR
   LsoV1             AS BYTE    ' UCHAR
   IPsecV1           AS BYTE    ' UCHAR
   LsoV2IPv4         AS BYTE    ' UCHAR
   LsoV2IPv6         AS BYTE    ' UCHAR
   TcpConnectionIPv4 AS BYTE    ' UCHAR
   TcpConnectionIPv6 AS BYTE    ' UCHAR
   Flags             AS DWORD   ' ULONG
'#IF %NDIS_SUPPORT_NDIS61
   IPsecV2           AS BYTE    ' UCHAR
   IPsecV2IPv4       AS BYTE    ' UCHAR
   Reserved1         AS BYTE    ' UCHAR
   Reserved2         AS BYTE    ' UCHAR
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)
END TYPE

'#define NDIS_SIZEOF_OFFLOAD_PARAMETERS_REVISION_1 RTL_SIZEOF_THROUGH_FIELD(NDIS_OFFLOAD_PARAMETERS, Flags)

'#if (NDIS_SUPPORT_NDIS61)
'#define NDIS_SIZEOF_OFFLOAD_PARAMETERS_REVISION_2 RTL_SIZEOF_THROUGH_FIELD(NDIS_OFFLOAD_PARAMETERS, IPsecV2IPv4)
'#endif // (NDIS_SUPPORT_NDIS61)

%NDIS_OFFLOAD_NOT_SUPPORTED            = 0
%NDIS_OFFLOAD_SUPPORTED                = 1

%NDIS_OFFLOAD_SET_NO_CHANGE            = 0
%NDIS_OFFLOAD_SET_ON                   = 1
%NDIS_OFFLOAD_SET_OFF                  = 2

'//
'// Encapsulation types that are used during offload in query and set
'//
%NDIS_ENCAPSULATION_NOT_SUPPORTED                = &H00000000???
%NDIS_ENCAPSULATION_NULL                         = &H00000001???
%NDIS_ENCAPSULATION_IEEE_802_3                   = &H00000002???
%NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q           = &H00000004???
%NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB    = &H00000008???
%NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED         = &H00000010???

'#pragma warning(push)
'#pragma warning(disable:4214) //nonstandard extension used : bit field types other than int

'//
'// Describes the large send offload version 1 capabilities
'// or configuration of the NIC. Used in NDIS_OFFLOAD structure
'//

' // Size = 16 bytes
TYPE NDIS_TCP_LARGE_SEND_OFFLOAD_V1_IPv4 DWORD
   Encapsulation   AS DWORD              ' ULONG
   MaxOffLoadSize  AS DWORD              ' ULONG
   MinSegmentCount AS DWORD              ' ULONG
   TcpOptions      AS BIT * 2 IN DWORD   ' ULONG
   IpOptions       AS BIT * 2
END TYPE

' // Size = 16 bytes
TYPE NDIS_TCP_LARGE_SEND_OFFLOAD_V1 DWORD
   IPv4 AS NDIS_TCP_LARGE_SEND_OFFLOAD_V1_IPv4
END TYPE

'//
'// Describes the checksum task offload capabilities or configuration
'// of the NIC. used in NDIS_OFFLOAD structure
'//

' // Size = 8 bytes
TYPE NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv4Transmit DWORD
   Encapsulation       AS DWORD              ' ULONG
   IpOptionsSupported  AS BIT * 2 IN DWORD   ' ULONG
   TcpOptionsSupported AS BIT * 2
   TcpChecksum         AS BIT * 2
   UdpChecksum         AS BIT * 2
   IpChecksum          AS BIT * 2
END TYPE

' // Size = 8 bytes
TYPE NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv4Receive DWORD
   Encapsulation         AS  DWORD              ' ULONG
   IpOptionsSupported    AS  BIT * 2 IN DWORD   ' ULONG
   TcpOptionsSupportedAS AS  BIT *  2
   TcpChecksum           AS  BIT * 2
   UdpChecksum           AS  BIT * 2
   IpChecksum            AS  BIT * 2
END TYPE

' // Size = 8 bytes
TYPE NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv6Transmit DWORD
   Encapsulation               AS DWORD              ' ULONG
   IpExtensionHeadersSupported AS BIT * 2 IN DWORD   ' ULONG
   TcpOptionsSupported         AS BIT * 2
   TcpChecksum                 AS BIT * 2
   UdpChecksum                 AS BIT * 2
END TYPE

' // Size = 8 bytes
TYPE NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv6Receive DWORD
   Encapsulation               AS DWORD             ' ULONG
   IpExtensionHeadersSupported AS BIT * 2 IN DWORD   ' ULONG
   TcpOptionsSupported         AS BIT * 2
   TcpChecksum                 AS BIT * 2
   UdpChecksum                 AS BIT * 2
END TYPE

' // Size = 32 bytes
TYPE NDIS_TCP_IP_CHECKSUM_OFFLOAD DWORD
   IPv4Transmit AS NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv4Transmit
   IPv4Receive  AS NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv4Receive
   IPv6Transmit AS NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv6Transmit
   IPv6Receive  AS NDIS_TCP_IP_CHECKSUM_OFFLOAD_IPv6Receive
END TYPE


'//
'// Describes the IPsec task offload version 1 capabilities
'// or configuration of the NIC. Used in NDIS_OFFLOAD structure
'//

' // Size = 20 bytes
TYPE NDIS_IPSEC_OFFLOAD_V1_Supported DWORD
   Encapsulation           AS DWORD   ' ULONG
   AhEspCombined           AS DWORD   ' ULONG
   TransportTunnelCombined AS DWORD   ' ULONG
   IPv4Options             AS DWORD   ' ULONG
   Flags                   AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE NDIS_IPSEC_OFFLOAD_V1_IPv4AH DWORD
   Md5       AS BIT * 2 IN DWORD
   Sha_1     AS BIT * 2
   Transport AS BIT * 2
   Tunnel    AS BIT * 2
   Send      AS BIT * 2
   Receive   AS BIT * 2
END TYPE

' // Size = 4 bytes
TYPE NDIS_IPSEC_OFFLOAD_V1_IPv4ESP DWORD
   Des       AS BIT * 2 IN DWORD
   Reserved  AS BIT * 2
   TripleDes AS BIT * 2
   NullEsp   AS BIT * 2
   Transport AS BIT * 2
   Tunnel    AS BIT * 2
   Send      AS BIT * 2
   Receive   AS BIT * 2
END TYPE

' // Size = 28 bytes
TYPE NDIS_IPSEC_OFFLOAD_V1 DWORD
   Supported AS NDIS_IPSEC_OFFLOAD_V1_Supported
   IPv4AH    AS NDIS_IPSEC_OFFLOAD_V1_IPv4AH
   IPv4ESP   AS NDIS_IPSEC_OFFLOAD_V1_IPv4ESP
END TYPE

'//
'// Describes the large send offload version 2 capabilities
'// or configuration of the NIC. Used in NDIS_OFFLOAD structure
'//

' // Size = 12 bytes
TYPE NDIS_TCP_LARGE_SEND_OFFLOAD_V2_IPv4 DWORD
   Encapsulation   AS DWORD   ' ULONG
   MaxOffLoadSize  AS DWORD   ' ULONG
   MinSegmentCount AS DWORD   ' ULONG
END TYPE

' // Size = 16 bytes
TYPE NDIS_TCP_LARGE_SEND_OFFLOAD_V2_IPv6 DWORD
   Encapsulation               AS DWORD   ' ULONG
   MaxOffLoadSize              AS DWORD   ' ULONG
   MinSegmentCount             AS DWORD   ' ULONG
   IpExtensionHeadersSupported AS BIT * 2 IN DWORD
   TcpOptionsSupported         AS BIT * 2
END TYPE

' // Size = 28 bytes
TYPE NDIS_TCP_LARGE_SEND_OFFLOAD_V2 DWORD
   IPv4 AS NDIS_TCP_LARGE_SEND_OFFLOAD_V2_IPv4
   IPv6 AS NDIS_TCP_LARGE_SEND_OFFLOAD_V2_IPv6
END TYPE

'#IF %NDIS_SUPPORT_NDIS61
'//
'//  Structures for IPSec Task Offload V2.
'//

'//
'// IPsec Algorithms for Authentication used in AuthenticationAlgorithms field
'// of NDIS_IPSEC_OFFLOAD_V2 structure
'//
%IPSEC_OFFLOAD_V2_AUTHENTICATION_MD5                      = &H00000001???
%IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_1                    = &H00000002???
%IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_256                  = &H00000004???
%IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_128              = &H00000008???
%IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_192              = &H00000010???
%IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_256              = &H00000020???

'//
'// IPsec Algorithms for Encryption used in EncryptionAlgorithms field of
'// NDIS_IPSEC_OFFLOAD_V2 structure
'//
%IPSEC_OFFLOAD_V2_ENCRYPTION_NONE                          = &H00000001???
%IPSEC_OFFLOAD_V2_ENCRYPTION_DES_CBC                       = &H00000002???
%IPSEC_OFFLOAD_V2_ENCRYPTION_3_DES_CBC                     = &H00000004???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_128                   = &H00000008???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_192                   = &H00000010???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_256                   = &H00000020???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_128                   = &H00000040???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_192                   = &H00000080???
%IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_256                   = &H00000100???

'//
'// IPsec offload V2 capabilities used in  NDIS_OFFLOAD
'//
' // Size = 32 bytes
TYPE NDIS_IPSEC_OFFLOAD_V2 DWORD FILL
   Encapsulation                AS DWORD   ' ULONG   // MAC encap types supported
   IPv6Supported                AS BYTE    ' BOOLEAN // IPv6 Supported
   IPv4Options                  AS BYTE    ' BOOLEAN // Supports offload of packets with IPv4 options
   IPv6NonIPsecExtensionHeaders AS BYTE    ' BOOLEAN // Supports offload of packets with non IPsec Extension headers
   Ah                           AS BYTE    ' BOOLEAN
   Esp                          AS BYTE    ' BOOLEAN
   AhEspCombined                AS BYTE    ' BOOLEAN
   Transport                    AS BYTE    ' BOOLEAN
   Tunnel                       AS BYTE    ' BOOLEAN
   TransportTunnelCombined      AS BYTE    ' BOOLEAN
   LsoSupported                 AS BYTE    ' BOOLEAN
   ExtendedSequenceNumbers      AS BYTE    ' BOOLEAN
   UdpEsp                       AS DWORD   ' ULONG
   AuthenticationAlgorithms     AS DWORD   ' ULONG   // Bit Mask of Authentication Algorithms
   EncryptionAlgorithms         AS DWORD   ' ULONG   // Bit Mask of Encryption Algorithms
   SaOffloadCapacity            AS DWORD   ' ULONG   // Number of SAs that can be offloaded
END TYPE

'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

'#pragma warning(pop)

'//
'// flags used in Flags field of NDIS_OFFLOAD structure
'//
%NDIS_OFFLOAD_FLAGS_GROUP_CHECKSUM_CAPABILITIES = &H00000001???

'//
'// Describes TCP/IP task offload capabilities or configuration
'// of the NIC. Used in OID_TCP_OFFLOAD_CURRENT_CONFIG
'// and OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES
'//
%NDIS_OFFLOAD_REVISION_1 = 1
'#IF %NDIS_SUPPORT_NDIS61
%NDIS_OFFLOAD_REVISION_2 = 2
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

' // Size = 112/144 bytes
TYPE NDIS_OFFLOAD DWORD
   Header   AS NDIS_OBJECT_HEADER
   ' // Checksum Offload information
   Checksum AS NDIS_TCP_IP_CHECKSUM_OFFLOAD
   ' // Large Send Offload information
   LsoV1    AS NDIS_TCP_LARGE_SEND_OFFLOAD_V1
   ' // IPsec Offload Information
   IPsecV1  AS NDIS_IPSEC_OFFLOAD_V1
   ' // Large Send Offload version 2Information
   LsoV2    AS NDIS_TCP_LARGE_SEND_OFFLOAD_V2
   Flags    AS DWORD   ' ULONG
'#IF %NDIS_SUPPORT_NDIS61
'  //
'  //IPsec offload V2
'  //
   IPsecV2  AS NDIS_IPSEC_OFFLOAD_V2
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)
END TYPE

'#define NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_1   RTL_SIZEOF_THROUGH_FIELD(NDIS_OFFLOAD, Flags)

'#if (NDIS_SUPPORT_NDIS61)
'#define NDIS_SIZEOF_NDIS_OFFLOAD_REVISION_2   RTL_SIZEOF_THROUGH_FIELD(NDIS_OFFLOAD, IPsecV2)
'#endif // (NDIS_SUPPORT_NDIS61)

'//
'// The following data structures are used with offload related WMI
'// guids. NDIS will trnaslate these data structures to those used
'// in OID and status indications
'//

' // Size = 20 bytes
TYPE NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V1_IPv4 DWORD
   Encapsulation   AS DWORD   ' ULONG
   MaxOffLoadSize  AS DWORD   ' ULONG
   MinSegmentCount AS DWORD   ' ULONG
   TcpOptions      AS DWORD   ' ULONG
   IpOptions       AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V1 DWORD
   IPv4 AS NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V1_IPv4
END TYPE

' // Size = 24 bytes
TYPE NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv4Transmit DWORD
   Encapsulation       AS DWORD   ' ULONG
   IpOptionsSupported  AS DWORD   ' ULONG
   TcpOptionsSupported AS DWORD   ' ULONG
   TcpChecksum         AS DWORD   ' ULONG
   UdpChecksum         AS DWORD   ' ULONG
   IpChecksum          AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
TYPE NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv4Receive DWORD
   Encapsulation       AS DWORD   ' ULONG
   IpOptionsSupported  AS DWORD   ' ULONG
   TcpOptionsSupported AS DWORD   ' ULONG
   TcpChecksum         AS DWORD   ' ULONG
   UdpChecksum         AS DWORD   ' ULONG
   IpChecksum          AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv6Transmit DWORD
   Encapsulation               AS DWORD   ' ULONG
   IpExtensionHeadersSupported AS DWORD   ' ULONG
   TcpOptionsSupported         AS DWORD   ' ULONG
   TcpChecksum                 AS DWORD   ' ULONG
   UdpChecksum                 AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv6Receive DWORD
   Encapsulation               AS DWORD   ' ULONG
   IpExtensionHeadersSupported AS DWORD   ' ULONG
   TcpOptionsSupported         AS DWORD   ' ULONG
   TcpChecksum                 AS DWORD   ' ULONG
   UdpChecksum                 AS DWORD   ' ULONG
END TYPE

' // Size = 88 bytes
TYPE NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD DWORD
   IPv4Transmit AS NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv4Transmit
   IPv4Receive  AS NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv4Receive
   IPv6Transmit AS NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv6Transmit
   IPv6Receive  AS NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD_IPv6Receive
END TYPE

' // Size = 20 bytes
TYPE NDIS_WMI_IPSEC_OFFLOAD_V1_Supported DWORD
   Encapsulation           AS DWORD   ' ULONG
   AhEspCombined           AS DWORD   ' ULONG
   TransportTunnelCombined AS DWORD   ' ULONG
   IPv4Options             AS DWORD   ' ULONG
   Flags                   AS DWORD   ' ULONG
END TYPE

' // Size = 24 bytes
TYPE NDIS_WMI_IPSEC_OFFLOAD_V1_IPv4AH DWORD
   Md5       AS DWORD   ' ULONG
   Sha_1     AS DWORD   ' ULONG
   Transport AS DWORD   ' ULONG
   Tunnel    AS DWORD   ' ULONG
   Send      AS DWORD   ' ULONG
   Receive   AS DWORD   ' ULONG
END TYPE

' // Size = 32 bytes
TYPE NDIS_WMI_IPSEC_OFFLOAD_V1_IPv4ESP DWORD
   Des       AS DWORD   ' ULONG
   Reserved  AS DWORD   ' ULONG
   TripleDes AS DWORD   ' ULONG
   NullEsp   AS DWORD   ' ULONG
   Transport AS DWORD   ' ULONG
   Tunnel    AS DWORD   ' ULONG
   Send      AS DWORD   ' ULONG
   Receive   AS DWORD   ' ULONG
END TYPE

' // Size = 76 bytes
TYPE NDIS_WMI_IPSEC_OFFLOAD_V1 DWORD
   Supported AS NDIS_WMI_IPSEC_OFFLOAD_V1_Supported
   IPv4AH    AS NDIS_WMI_IPSEC_OFFLOAD_V1_IPv4AH
   IPv4ESP   AS NDIS_WMI_IPSEC_OFFLOAD_V1_IPv4ESP
END TYPE

' // Size = 12 bytes
TYPE NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2_IPv4 DWORD
   Encapsulation   AS DWORD   ' ULONG
   MaxOffLoadSize  AS DWORD   ' ULONG
   MinSegmentCount AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2_IPv6 DWORD
   Encapsulation               AS DWORD   ' ULONG
   MaxOffLoadSize              AS DWORD   ' ULONG
   MinSegmentCount             AS DWORD   ' ULONG
   IpExtensionHeadersSupported AS DWORD   ' ULONG
   TcpOptionsSupported         AS DWORD   ' ULONG
END TYPE

' // Size = 32 bytes
TYPE NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2 DWORD
   IPv4 AS NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2_IPv4
   IPv6 AS NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2_IPv6
END TYPE

' // Size = 224/256 bytes
TYPE NDIS_WMI_OFFLOAD DWORD
   ' // Header.Type = NDIS_OBJECT_TYPE_OFFLOAD;
   ' // Header.Size = sizeof(NDIS_OFFLOAD);
   ' // Header.Revision  = NDIS_OFFLOAD_REVISION_1;
   Header   AS NDIS_OBJECT_HEADER
   ' // Checksum Offload information
   Checksum AS NDIS_WMI_TCP_IP_CHECKSUM_OFFLOAD
   ' // Large Send Offload information
   LsoV1    AS NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V1
   ' // IPsec Offload Information
   IPsecV1  AS NDIS_WMI_IPSEC_OFFLOAD_V1
   ' // Large Send Offload version 2Information
   LsoV2    AS NDIS_WMI_TCP_LARGE_SEND_OFFLOAD_V2
   Flags    AS DWORD   ' ULONG
'#IF %NDIS_SUPPORT_NDIS61
'  //
'  // IPsec offload version 2 information
'  //
   IPsecV2 AS NDIS_IPSEC_OFFLOAD_V2
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)
END TYPE

'#define NDIS_SIZEOF_NDIS_WMI_OFFLOAD_REVISION_1   RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_OFFLOAD, Flags)

'#if (NDIS_SUPPORT_NDIS61)
'#define NDIS_SIZEOF_NDIS_WMI_OFFLOAD_REVISION_2   RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_OFFLOAD, IPsecV2)
'#endif // (NDIS_SUPPORT_NDIS61)
'#pragma warning(push)
'#pragma warning(disable:4214) //nonstandard extension used : bit field types other than int

'//
'// Describes TCP connection offload capabilities or configuration
'// of the NIC. Used in OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG,
'// OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES and
'// NDIS_STATUS_OFFLOAD_RESUME
'//
%NDIS_TCP_CONNECTION_OFFLOAD_REVISION_1 = 1
'#IF %NDIS_SUPPORT_NDIS61
%NDIS_TCP_CONNECTION_OFFLOAD_REVISION_2 = 2
'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

' // Size = 20 bytes
TYPE NDIS_TCP_CONNECTION_OFFLOAD DWORD
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_TCP_CONNECTION_OFFLOAD_REVISION_1;
   ' // Header.Size = sizeof(NDIS_TCP_CONNECTION_OFFLOAD);
   Header                       AS NDIS_OBJECT_HEADER
   Encapsulation                AS DWORD    ' ULONG
   SupportIPv4                  AS BIT * 2 IN DWORD
   SupportIPv6                  AS BIT * 2
   SupportIPv6ExtensionHeaders  AS BIT * 2
   SupportSack                  AS BIT * 2
'#IF %NDIS_SUPPORT_NDIS61
   CongestionAlgorithm          AS BIT * 4
'#ENDIF    ' // (NDIS_SUPPORT_NDIS61)
   TcpConnectionOffloadCapacity AS DWORD   ' ULONG
   Flags                        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_TCP_CONNECTION_OFFLOAD_REVISION_1 RTL_SIZEOF_THROUGH_FIELD(NDIS_TCP_CONNECTION_OFFLOAD, Flags)
'#if (NDIS_SUPPORT_NDIS61)
'#define NDIS_SIZEOF_TCP_CONNECTION_OFFLOAD_REVISION_2 RTL_SIZEOF_THROUGH_FIELD(NDIS_TCP_CONNECTION_OFFLOAD, Flags)
'#endif // (NDIS_SUPPORT_NDIS61)

'#pragma warning(pop)


' // Size = 32 bytes
TYPE NDIS_WMI_TCP_CONNECTION_OFFLOAD DWORD
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_TCP_CONNECTION_OFFLOAD_REVISION_1;
   ' // Header.Size = sizeof(NDIS_TCP_CONNECTION_OFFLOAD);
   Header                       AS NDIS_OBJECT_HEADER
   Encapsulation                AS DWORD   ' ULONG
   SupportIPv4                  AS DWORD   ' ULONG
   SupportIPv6                  AS DWORD   ' ULONG
   SupportIPv6ExtensionHeaders  AS DWORD   ' ULONG
   SupportSack                  AS DWORD   ' ULONG
   TcpConnectionOffloadCapacity AS DWORD   ' ULONG
   Flags                        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_WMI_TCP_CONNECTION_OFFLOAD_REVISION_1 RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_TCP_CONNECTION_OFFLOAD, Flags)

%NDIS_MAXIMUM_PORTS = &H1000000???

'//
'// definitions for NDIS PORTs
'//

'typedef ULONG NDIS_PORT_NUMBER, *PNDIS_PORT_NUMBER;

'//
'// port related data structures
'//
'#define NDIS_DEFAULT_PORT_NUMBER ((NDIS_PORT_NUMBER)0)
%NDIS_DEFAULT_PORT_NUMBER = 0???

'//
'// NDIS_PORT_TYPE defines the application of a port
'//

' enum NDIS_PORT_TYPE
%NdisPortTypeUndefined       = 0
%NdisPortTypeBridge          = 1
%NdisPortTypeRasConnection   = 2
%NdisPortType8021xSupplicant = 3
%NdisPortTypeMax             = 4

'//
'// NDIS_PORT_AUTHENTICATION_STATE defines the authentication state of a port
'// on a particular data path
'//

' enum NDIS_PORT_AUTHORIZATION_STATE
%NdisPortAuthorizationUnknown = 0
%NdisPortAuthorized           = 1
%NdisPortUnauthorized         = 2
%NdisPortReauthorizing        = 3

'//
'// NDIS_PORT_CONTROLL_STATE specifies if a port is "controlled"
'// i.e. if it needs authentication, on a particular data path
'//

' enum NDIS_PORT_CONTROL_STATE aka NDIS_PORT_CONTROLL_STATE
%NdisPortControlStateUnknown      = 0
%NdisPortControlStateControlled   = 1
%NdisPortControlStateUncontrolled = 2

'//
'// NDIS_PORT_STATE is used in port state change status indications
'// as well as OID_GEN_PORT_STATE query OID
'//

%NDIS_PORT_STATE_REVISION_1 = 1

' // Size = 48 bytes
TYPE NDIS_PORT_STATE QWORD FILL
   Header                 AS NDIS_OBJECT_HEADER
   MediaConnectState      AS LONG    ' NDIS_MEDIA_CONNECT_STATE enum
   XmitLinkSpeed          AS QUAD    ' ULONG64
   RcvLinkSpeed           AS QUAD    ' ULONG64
   Direction              AS LONG    ' NET_IF_DIRECTION_TYPE enum
   SendControlState       AS LONG    ' NDIS_PORT_CONTROLL_STATE enum
   RcvControlState        AS LONG    ' NDIS_PORT_CONTROLL_STATE enum
   SendAuthorizationState AS LONG    ' NDIS_PORT_AUTHORIZATION_STATE enum
   RcvAuthorizationState  AS LONG    ' NDIS_PORT_AUTHORIZATION_STATE enum
   Flags                  AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_PORT_STATE_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PORT_STATE, Flags)

'//
'// NDIS_PORT_PARAMETERS is used in OID_GEN_PORT_PARAMETERS set OID
'//
%NDIS_PORT_AUTHENTICATION_PARAMETERS_REVISION_1 = 1

' // Size = 20 bytes
TYPE NDIS_PORT_AUTHENTICATION_PARAMETERS DWORD
   Header                 AS NDIS_OBJECT_HEADER
   SendControlState       AS LONG   ' NDIS_PORT_CONTROLL_STATE enum
   RcvControlState        AS LONG   ' NDIS_PORT_CONTROLL_STATE enum
   SendAuthorizationState AS LONG   ' NDIS_PORT_AUTHORIZATION_STATE enum
   RcvAuthorizationState  AS LONG   ' NDIS_PORT_AUTHORIZATION_STATE enum
END TYPE

'#define NDIS_SIZEOF_PORT_AUTHENTICATION_PARAMETERS_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PORT_AUTHENTICATION_PARAMETERS, RcvAuthorizationState)

'//
'// Flags used in NDIS_PORT_CHARACTERISTICS Flags field.
'//
%NDIS_PORT_CHAR_USE_DEFAULT_AUTH_SETTINGS = &H00000001???

'//
'// NDIS_PORT_CHARACTERISTICS is used in port allocation and
'// arrival notification as part of NDIS_PORT structure
'//
%NDIS_PORT_CHARACTERISTICS_REVISION_1 = 1

' // Size = 64 bytes
TYPE NDIS_PORT_CHARACTERISTICS QWORD FILL
   Header                 AS NDIS_OBJECT_HEADER
   PortNumber             AS DWORD   ' NDIS_PORT_NUMBER
   Flags                  AS DWORD   ' ULONG
   Type                   AS LONG    ' NDIS_PORT_TYPE
   MediaConnectState      AS LONG    ' NDIS_MEDIA_CONNECT_STATE
   XmitLinkSpeed          AS QUAD    ' ULONG64
   RcvLinkSpeed           AS QUAD    ' ULONG64
   Direction              AS LONG    ' NET_IF_DIRECTION_TYPE enum
   SendControlState       AS LONG    ' NDIS_PORT_CONTROLL_STATE enum
   RcvControlState        AS LONG    ' NDIS_PORT_CONTROLL_STATE enum
   SendAuthorizationState AS LONG    ' NDIS_PORT_AUTHORIZATION_STATE enum
   RcvAuthorizationState  AS LONG    ' NDIS_PORT_AUTHORIZATION_STATE enum
   alignment__            AS DWORD
END TYPE

'#define NDIS_SIZEOF_PORT_CHARACTERISTICS_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PORT_CHARACTERISTICS, RcvAuthorizationState)

'//
'// NDIS_PORT structure is used in port activation
'// PnP notification
'//
'typedef struct _NDIS_PORT NDIS_PORT, *PNDIS_PORT;

' // Size = 80 bytes
TYPE NDIS_PORT QWORD FILL
#IF %DEF(%USEPBDECL)
   pNext               AS NDIS_PORT PTR   ' PNDIS_PORT
#ELSE
   Next                AS NDIS_PORT PTR   ' PNDIS_PORT
#ENDIF
   NdisReserved        AS DWORD           ' PVOID
   MiniportReserved    AS DWORD           ' PVOID
   ProtocolReserved    AS DWORD           ' PVOID
   PortCharacteristics AS NDIS_PORT_CHARACTERISTICS
END TYPE


%NDIS_PORT_ARRAY_REVISION_1 = 1
'//
'// NDIS_PORT_ARRAY is used in enumerating the ports
'//
' // Size = 80 bytes
TYPE NDIS_PORT_ARRAY QWORD FILL
   Header          AS NDIS_OBJECT_HEADER
   NumberOfPorts   AS DWORD   ' ULONG
   OffsetFirstPort AS DWORD   ' ULONG
   ElementSize     AS DWORD   ' ULONG
   Ports(0)        AS NDIS_PORT_CHARACTERISTICS
END TYPE

'#define NDIS_SIZEOF_PORT_ARRAY_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_PORT_ARRAY, Ports)

' enum NDIS_NETWORK_CHANGE_TYPE
%NdisPossibleNetworkChange         = 1
%NdisDefinitelyNetworkChange       = 2
%NdisNetworkChangeFromMediaConnect = 3
%NdisNetworkChangeMax              = 4

%NDIS_WMI_DEFAULT_METHOD_ID            = 1

%NDIS_WMI_OBJECT_TYPE_SET              = &H01
%NDIS_WMI_OBJECT_TYPE_METHOD           = &H02
%NDIS_WMI_OBJECT_TYPE_EVENT            = &H03
%NDIS_WMI_OBJECT_TYPE_ENUM_ADAPTER     = &H04
%NDIS_WMI_OBJECT_TYPE_OUTPUT_INFO      = &H05

%NDIS_WMI_METHOD_HEADER_REVISION_1     = 1

' // Size = 32 bytes
TYPE NDIS_WMI_METHOD_HEADER
   Header     AS NDIS_OBJECT_HEADER
   PortNumber AS DWORD      ' NDIS_PORT_NUMBER
   NetLuid    AS NET_LUID
   RequestId  AS QUAD       ' ULONG64
   Timeout    AS DWORD      ' ULONG
   Padding(3) AS BYTE       ' UCHAR[4]
END TYPE

'#define NDIS_SIZEOF_WMI_METHOD_HEADER_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_METHOD_HEADER, Padding)

%NDIS_WMI_SET_HEADER_REVISION_1 = 1

' // Size = 32 bytes
TYPE NDIS_WMI_SET_HEADER
   Header     AS NDIS_OBJECT_HEADER
   PortNumber AS DWORD      ' NDIS_PORT_NUMBER
   NetLuid    AS NET_LUID
   RequestId  AS QUAD       ' ULONG64
   Timeout    AS DWORD      ' ULONG
   Padding(3) AS BYTE       ' UCHAR[4]
END TYPE

'#define NDIS_SIZEOF_WMI_SET_HEADER_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_SET_HEADER, Padding)

%NDIS_WMI_EVENT_HEADER_REVISION_1 = 1

' // Size = 40 bytes
TYPE NDIS_WMI_EVENT_HEADER
   Header           AS NDIS_OBJECT_HEADER
   IfIndex          AS DWORD      ' NET_IFINDEX
   NetLuid          AS NET_LUID
   RequestId        AS QUAD       ' ULONG64
   PortNumber       AS DWORD      ' NDIS_PORT_NUMBER
   DeviceNameLength AS DWORD      ' ULONG
   DeviceNameOffset AS DWORD      ' ULONG
   Padding(3)       AS BYTE       ' UCHAR
END TYPE

'#define NDIS_SIZEOF_WMI_EVENT_HEADER_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_EVENT_HEADER, Padding)

%NDIS_WMI_ENUM_ADAPTER_REVISION_1 = 1

' // Size = 24 bytes
TYPE NDIS_WMI_ENUM_ADAPTER DWORD
   Header           AS NDIS_OBJECT_HEADER
   IfIndex          AS DWORD      ' NET_IFINDEX
   NetLuid          AS NET_LUID
   DeviceNameLength AS WORD       ' USHORT
   DeviceName(0)    AS BYTE       ' CHAR
END TYPE

'#define NDIS_SIZEOF_WMI_ENUM_ADAPTER_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_ENUM_ADAPTER, DeviceName)

'//
'// Flags used in standardized keyword *NdisDeviceType
'//
%NDIS_DEVICE_TYPE_ENDPOINT = &H00000001???

'#IF %NDIS_SUPPORT_NDIS61

'//
'// Structure and defines for
'// OID_GEN_HD_SPLIT_PARAMETERS
'//
%NDIS_HD_SPLIT_PARAMETERS_REVISION_1     = 1

' // Size = 8 bytes
TYPE NDIS_HD_SPLIT_PARAMETERS DWORD
   ' //
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_HD_SPLIT_PARAMETERS_REVISION_1;
   ' // Header.Size = sizeof(NDIS_HD_SPLIT_PARAMETERS);
   ' //
   Header AS NDIS_OBJECT_HEADER
   HDSplitCombineFlags AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_HD_SPLIT_PARAMETERS_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_HD_SPLIT_PARAMETERS, HDSplitCombineFlags)

'//
'// Flags used in NDIS_HD_SPLIT_PARAMETERS->HDSplitCombineFlags
'// and NDIS_HD_SPLIT_CURRENT_CONFIG->HDSplitCombineFlags
'//
%NDIS_HD_SPLIT_COMBINE_ALL_HEADERS          = &H00000001???

'//
'// Structure and defines for
'// OID_GEN_HD_SPLIT_CURRENT_CONFIG
'//
%NDIS_HD_SPLIT_CURRENT_CONFIG_REVISION_1     = 1

' // Size = 28 bytes
TYPE NDIS_HD_SPLIT_CURRENT_CONFIG DWORD
   ' //
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_HD_SPLIT_CURRENT_CONFIG_REVISION_1;
   ' // Header.Size = sizeof(NDIS_HD_SPLIT_CURRENT_CONFIG);
   ' //
   Header               AS NDIS_OBJECT_HEADER
   HardwareCapabilities AS DWORD   ' ULONG
   CurrentCapabilities  AS DWORD   ' ULONG
   HDSplitFlags         AS DWORD   ' ULONG
   HDSplitCombineFlags  AS DWORD   ' ULONG
   BackfillSize         AS DWORD   ' ULONG
   MaxHeaderSize        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_HD_SPLIT_CURRENT_CONFIG_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_HD_SPLIT_CURRENT_CONFIG, MaxHeaderSize)

'//
'// Flags used in NDIS_HD_SPLIT_ATTRIBUTES->HardwareCapabilities
'// and NDIS_HD_SPLIT_ATTRIBUTES->CurrentCapabilities. They are also
'// used in NDIS_HD_SPLIT_CURRENT_CONFIG->HardwareCapabilities
'// and NDIS_HD_SPLIT_CURRENT_CONFIG->CurrentCapabilities.
'//
%NDIS_HD_SPLIT_CAPS_SUPPORTS_HEADER_DATA_SPLIT         = &H00000001???
%NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV4_OPTIONS              = &H00000002???
%NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV6_EXTENSION_HEADERS    = &H00000004???
%NDIS_HD_SPLIT_CAPS_SUPPORTS_TCP_OPTIONS               = &H00000008???

'//
'// Flags used in NDIS_HD_SPLIT_ATTRIBUTES->HDSplitFlags and
'// NDIS_HD_SPLIT_CURRENT_CONFIG->HDSplitFlags
'//
%NDIS_HD_SPLIT_ENABLE_HEADER_DATA_SPLIT     = &H00000001???

'#ENDIF   ' // (NDIS_SUPPORT_NDIS61)

%NDIS_WMI_OUTPUT_INFO_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_WMI_OUTPUT_INFO DWORD
   Header            AS NDIS_OBJECT_HEADER
   Flags             AS DWORD   ' ULONG
   SupportedRevision AS BYTE    ' UCHAR
   DataOffset        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_WMI_OUTPUT_INFO_REVISION_1     \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_OUTPUT_INFO, DataOffset)

'#if (NDIS_SUPPORT_NDIS620)

'//
'// NDIS 6.20 power management
'//

'//
'// flags used in SupportedWoLPatterns field of NDIS_PM_CAPABILITIES
'// to advertise WOL pattern capabilities
'//

%NDIS_PM_WOL_BITMAP_PATTERN_SUPPORTED                    = &H00000001???
%NDIS_PM_WOL_MAGIC_PACKET_SUPPORTED                      = &H00000002???
%NDIS_PM_WOL_IPV4_TCP_SYN_SUPPORTED                      = &H00000004???
%NDIS_PM_WOL_IPV6_TCP_SYN_SUPPORTED                      = &H00000008???
%NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_SUPPORTED           = &H00000200???
%NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_SUPPORTED           = &H00000800???
%NDIS_PM_WOL_EAPOL_REQUEST_ID_MESSAGE_SUPPORTED          = &H00010000???

'//
'// flags used in EnabledWoLPacketPatterns field of NDIS_PM_PARAMETERS
'// to advertise WOL pattern capabilities
'//
%NDIS_PM_WOL_BITMAP_PATTERN_ENABLED                      = &H00000001???
%NDIS_PM_WOL_MAGIC_PACKET_ENABLED                        = &H00000002???
%NDIS_PM_WOL_IPV4_TCP_SYN_ENABLED                        = &H00000004???
%NDIS_PM_WOL_IPV6_TCP_SYN_ENABLED                        = &H00000008???
%NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_ENABLED             = &H00000200???
%NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_ENABLED             = &H00000800???
%NDIS_PM_WOL_EAPOL_REQUEST_ID_MESSAGE_ENABLED            = &H00010000???

'//
'// Values used in Priority field of NDIS_PM_WOL_PATTERN
'//
%NDIS_PM_WOL_PRIORITY_LOWEST                             = &HFFFFFFFF???
%NDIS_PM_WOL_PRIORITY_NORMAL                             = &H10000000???
%NDIS_PM_WOL_PRIORITY_HIGHEST                            = &H00000001???

'//
'// flags used in SupportedProtocolOffloads field of NDIS_PM_CAPABILITIES
'// to advertise protocol offload capabilities
'//
%NDIS_PM_PROTOCOL_OFFLOAD_ARP_SUPPORTED                    = &H00000001???
%NDIS_PM_PROTOCOL_OFFLOAD_NS_SUPPORTED                     = &H00000002???
%NDIS_PM_PROTOCOL_OFFLOAD_80211_RSN_REKEY_SUPPORTED        = &H00000080???

'//
'// flags used in EnabledProtocolOffloads field of NDIS_PM_PARAMETERS
'// to advertise protocol offload capabilities
'//
%NDIS_PM_PROTOCOL_OFFLOAD_ARP_ENABLED                      = &H00000001???
%NDIS_PM_PROTOCOL_OFFLOAD_NS_ENABLED                       = &H00000002???
%NDIS_PM_PROTOCOL_OFFLOAD_80211_RSN_REKEY_ENABLED          = &H00000080???

'//
'// Values used in Priority field of NDIS_PM_PROTOCOL_OFFLOAD
'//
%NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_LOWEST                  = &HFFFFFFFF???
%NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_NORMAL                  = &H10000000???
%NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_HIGHEST                 = &H00000001???


'//
'// Values used in WakeUpFlags field of NDIS_PM_PARAMETERS
'//
%NDIS_PM_WAKE_ON_LINK_CHANGE_ENABLED                       = &H00000001???

'//
'// enum type for wake on lan patterns based on packet type
'// used in WoLPacketType field of NDIS_PM_WOL_PATTERN structure
'//
' enum NDIS_PM_WOL_PACKET
%NdisPMWoLPacketUnspecified           = 0
%NdisPMWoLPacketBitmapPattern         = 1
%NdisPMWoLPacketMagicPacket           = 2
%NdisPMWoLPacketIPv4TcpSyn            = 3
%NdisPMWoLPacketIPv6TcpSyn            = 4
%NdisPMWoLPacketEapolRequestIdMessage = 5
%NdisPMWoLPacketMaximum               = 6

'//
'// enum types for offloaded protocols used in ProtocolOffloadType
'// field of NDIS_PM_PROTOCOL_OFFLOAD structure
'//
' enum NDIS_PM_PROTOCOL_OFFLOAD_TYPE
%NdisPMProtocolOffloadIdUnspecified = 0
%NdisPMProtocolOffloadIdIPv4ARP     = 1
%NdisPMProtocolOffloadIdIPv6NS      = 2
%NdisPMProtocolOffload80211RSNRekey = 3
%NdisPMProtocolOffloadIdMaximum     = 4

'//
'// Limited size string used in NSID power management structures
'//
%NDIS_PM_MAX_STRING_SIZE = 64

UNION NDIS_PM_COUNTED_STRING_UNION
   String AS WSTRINGZ * (%NDIS_PM_MAX_STRING_SIZE + 1)   ' WCHAR String[NDIS_PM_MAX_STRING_SIZE + 1]
   ' // For compatibility with the PB headers
   sString AS WSTRINGZ * (%NDIS_PM_MAX_STRING_SIZE + 1)   ' WCHAR String[NDIS_PM_MAX_STRING_SIZE + 1]
END UNION

' // Size = 132 bytes
TYPE NDIS_PM_COUNTED_STRING WORD
   Length AS WORD                                        ' USHORT // in -Bytes-
   NDIS_PM_COUNTED_STRING_UNION
END TYPE


'//
'// NDIS_PM_CAPABILITIES structure is used in PowerManagementCapabilitiesEx field of
'// NDIS_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES and NDIS_BIND_PARAMETERS
'//
%NDIS_PM_CAPABILITIES_REVISION_1  = 1

' // Size = 52 bytes
TYPE NDIS_PM_CAPABILITIES DWORD
   Header                     AS NDIS_OBJECT_HEADER
   Flags                      AS DWORD   ' ULONG
   SupportedWoLPacketPatterns AS DWORD   ' ULONG
   NumTotalWoLPatterns        AS DWORD   ' ULONG
   MaxWoLPatternSize          AS DWORD   ' ULONG // maximum bytes that can be compared against a pattern
   MaxWoLPatternOffset        AS DWORD   ' ULONG // strting from MAC header, how many bytes in the packet can be examined
   MaxWoLPacketSaveBuffer     AS DWORD   ' ULONG // how many bytes of WOL packet can be saved to a buffer and indicated up
   SupportedProtocolOffloads  AS DWORD   ' ULONG
   NumArpOffloadIPv4Addresses AS DWORD   ' ULONG
   NumNSOffloadIPv6Addresses  AS DWORD   ' ULONG
   MinMagicPacketWakeUp       AS LONG   ' NDIS_DEVICE_POWER_STATE
   MinPatternWakeUp           AS LONG   ' NDIS_DEVICE_POWER_STATE
   MinLinkChangeWakeUp        AS LONG   ' NDIS_DEVICE_POWER_STATE
END TYPE

'#define NDIS_SIZEOF_NDIS_PM_CAPABILITIES_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_PM_CAPABILITIES, MinLinkChangeWakeUp)

'//
'// NDIS_PM_PARAMETERS structure is used in OID_PM_PARAMETERS for quering and
'// updating currently enabled power management hardware capabilities.
'//
%NDIS_PM_PARAMETERS_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_PM_PARAMETERS DWORD
   Header                   AS NDIS_OBJECT_HEADER
   EnabledWoLPacketPatterns AS DWORD   ' ULONG // NDIS_PM_WOL_XXX flags
   EnabledProtocolOffloads  AS DWORD   ' ULONG // NDIS_PM_PROTOCOL_OFFLOAD_XXX flags
   WakeUpFlags              AS DWORD   ' ULONG // NDIS_PM_WAKE_XXX flags
END TYPE

'#define NDIS_SIZEOF_NDIS_PM_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_PM_PARAMETERS, WakeUpFlags)


'//
'// Used in _EAPOL_REQUEST_ID_MESSAGE_WOL_PACKET_PARAMETERS
'// When the following flag is set, the packet must be encrypted.
'//
%EAPOL_REQUEST_ID_WOL_FLAG_MUST_ENCRYPT      = &H00000001???

'//
'// Pattern IDs above this number are treated as pre-assigned
'//
%NDIS_PM_MAX_PATTERN_ID  = &H0000FFFF???

'//
'// This value is used in the Flags field of the NDIS_PM_WOL_PATTERN structure
'// It indicates that the a pre-assigned ID is used
'//
%NDIS_PM_PRIVATE_PATTERN_ID  = &H00000001???


'//
'// structure used in OID_PM_ADD_WOL_PATTERN and OID_PM_WOL_PATTERN_LIST
'//
%NDIS_PM_WOL_PATTERN_REVISION_1 = 1

'//
'// IPv4 TCP SYN information
'//
' // Size = 20 bytes
TYPE IPV4_TCP_SYN_WOL_PACKET_PARAMETERS DWORD
   Flags                AS DWORD   ' ULONG
   IPv4SourceAddress(3) AS BYTE    ' UCHAR[4] // IPv4 source address
   IPv4DestAddress(3)   AS BYTE    ' UCHAR[4] // IPv4 destination address
   TCPSourcePortNumber  AS WORD    ' USHORT // TCP source port
   TCPDestPortNumber    AS WORD    ' USHORT // TCP destination port
END TYPE

'//
'// IPv6 TCP SYN information
'//
' // Size = 40 bytes
TYPE IPV6_TCP_SYN_WOL_PACKET_PARAMETERS WORD
   Flags                 AS DWORD   ' ULONG
   IPv6SourceAddress(15) AS BYTE   ' UCHAR // source IPv6 address
   IPv6DestAddress(15)   AS BYTE   ' UCHAR // destination IPv6 address
   TCPSourcePortNumber   AS WORD   ' USHORT // source TCP port
   TCPDestPortNumber     AS WORD   ' USHORT // destination TCP port
END TYPE

'//
'// 802.1X EAPOL request identity message parameters
'//
' // Size = 4 bytes
TYPE EAPOL_REQUEST_ID_MESSAGE_WOL_PACKET_PARAMETERS DWORD
   Flags AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE WOL_BITMAP_PATTERN DWORD
   Flags         AS DWORD   ' ULONG
   MaskOffset    AS DWORD   ' ULONG // offset for mask buffer from the beginning of NDIS_PM_WOL_PATTERN structure
   MaskSize      AS DWORD   ' ULONG // Mask size
   PatternOffset AS DWORD   ' ULONG // offset for pattern buffer from the beginning of NDIS_PM_WOL_PATTERN structure
   PatternSize   AS DWORD   ' ULONG // pattern size
END TYPE

' // Size = 40 bytes
UNION WOL_PATTERN
   IPv4TcpSynParameters            AS IPV4_TCP_SYN_WOL_PACKET_PARAMETERS
   IPv6TcpSynParameters            AS IPV6_TCP_SYN_WOL_PACKET_PARAMETERS
   EapolRequestIdMessageParameters AS EAPOL_REQUEST_ID_MESSAGE_WOL_PACKET_PARAMETERS
   WoLBitMapPattern                AS WOL_BITMAP_PATTERN
END UNION

' // Size = 196 bytes
TYPE NDIS_PM_WOL_PATTERN DWORD
   Header               AS NDIS_OBJECT_HEADER
   Flags                AS DWORD                    ' ULONG
   Priority             AS DWORD                    ' ULONG
   WoLPacketType        AS LONG                     ' NDIS_PM_WOL_PACKET
   FriendlyName         AS NDIS_PM_COUNTED_STRING
   PatternId            AS DWORD                    ' ULONG // Pattern ID set by NDIS
   NextWoLPatternOffset AS DWORD                    ' ULONG
   WoLPattern           AS WOL_PATTERN
END TYPE

'#define NDIS_SIZEOF_NDIS_PM_WOL_PATTERN_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_PM_WOL_PATTERN, WoLPattern)


'//
'// 802.11 RSN handshake values
'// Used in DOT11_RSN_REKEY_PARAMETERS structure
'//
%DOT11_RSN_KEK_LENGTH = 16
%DOT11_RSN_KCK_LENGTH = 16

'//
'// structure is used in OID_PM_ADD_PROTOCOL_OFFLOAD and
'// OID_PM_PROTOCOL_OFFLOAD_LIST OID requests
'//
%NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1 = 1

'//
'// IPv4 ARP
'//
' // Size = 20 bytes
TYPE IPV4_ARP_PARAMETERS DWORD
   Flags                AS DWORD   ' ULONG
   RemoteIPv4Address(3) AS BYTE    ' UCHAR[4] // source IPv4 address (optional)
   HostIPv4Address(3)   AS BYTE    ' UCHAR[4] // destination IPv4 address
   MacAddress(5)        AS BYTE    ' UCHAR[6] // MAC address
END TYPE

'//
'// IPv6 NS. ICMPv6 type 135
'// flags determine link local or global address. Discovery, reachability or dup address detection
'// multicat MAC address: 3333WXYZ where WXYZ is the least significant 4 bytes from
'// the solicited node IPv6 address
'//
' // Size = 76 bytes
TYPE IPV6_NS_PARAMETERS DWORD
   Flags                        AS DWORD   ' ULONG
   RemoteIPv6Address(15)        AS BYTE    ' UCHAR[16] // source IPv6 address (optional)
   SolicitedNodeIPv6Address(15) AS BYTE    ' UCHAR[16] // solicited node IPv6 address
   MacAddress(5)                AS BYTE    ' UCHAR[6] // MAC address
   TargetIPv6Addresses(1, 15)   AS BYTE    ' UCHAR [2][16] // An array of local IPv6 addesses
END TYPE

'//
'// 802.11 RSN handshake
'//
' // Size = 48 bytes
TYPE DOT11_RSN_REKEY_PARAMETERS QWORD FILL
   Flags                          AS DWORD   ' ULONG
   KCK(%DOT11_RSN_KCK_LENGTH - 1) AS BYTE   ' UCHAR
   KEK(%DOT11_RSN_KCK_LENGTH - 1) AS BYTE   ' UCHAR
   KeyReplayCounter               AS QUAD   ' ULONGLONG
END TYPE

' // Size = 80 bytes
UNION PROTOCOL_OFFLOAD_PARAMETERS QWORD FILL
   IPv4ARPParameters       AS IPV4_ARP_PARAMETERS
   IPv6NSParameters        AS IPV6_NS_PARAMETERS
   Dot11RSNRekeyParameters AS DOT11_RSN_REKEY_PARAMETERS
END UNION

' // Size = 240 bytes
TYPE NDIS_PM_PROTOCOL_OFFLOAD QWORD FILL
   Header                    AS NDIS_OBJECT_HEADER
   Flags                     AS DWORD                         ' ULONG
   Priority                  AS DWORD                         ' ULONG
   ProtocolOffloadType       AS LONG                          ' NDIS_PM_PROTOCOL_OFFLOAD_TYPE
   FriendlyName              AS NDIS_PM_COUNTED_STRING
   ProtocolOffloadId         AS DWORD                         ' ULONG // offloaded protocol ID set by NDIS
   NextProtocolOffloadOffset AS DWORD                         ' ULONG
   ProtocolOffloadParameters AS PROTOCOL_OFFLOAD_PARAMETERS
END TYPE

'#define NDIS_SIZEOF_NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_PM_PROTOCOL_OFFLOAD, ProtocolOffloadParameters)


'//
'// enum values used in NDIS_WMI_PM_ADMIN_CONFIG structure
'//
' enum NDIS_PM_ADMIN_CONFIG_STATE
%NdisPMAdminConfigUnspecified = 0
%NdisPMAdminConfigDisabled    = 1
%NdisPMAdminConfigEnabled     = 2

'//
'// NDIS_WMI_PM_ADMIN_CONFIG struct is used with
'// GUID_NDIS_PM_ADMIN_CONFIG WMI method
'//
%NDIS_WMI_PM_ADMIN_CONFIG_REVISION_1 = 1

' // Size = 28 bytes
TYPE NDIS_WMI_PM_ADMIN_CONFIG DWORD
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_WMI_PM_ADMIN_CONFIG_REVISION_1;
   ' // Header.Size = sizeof(NDIS_WMI_PM_ADMIN_CONFIG);
   Header                  AS NDIS_OBJECT_HEADER
   WakeOnPattern           AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
   WakeOnMagicPacket       AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
   DeviceSleepOnDisconnect AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
   PMARPOffload            AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
   PMNSOffload             AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
   PMWiFiRekeyOffload      AS LONG   ' NDIS_PM_ADMIN_CONFIG_STATE
END TYPE

'#define NDIS_SIZEOF_WMI_PM_ADMIN_CONFIG_REVISION_1 RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_PM_ADMIN_CONFIG, PMWiFiRekeyOffload)

'//
'// enum values used in NDIS_WMI_PM_ACTIVE_CAPABILITIES structure
'//
' enum _NDIS_PM_CAPABILITY_STATE
%NdisPMAdminConfigUnsupported = 0
%NdisPMAdminConfigInactive    = 1
%NdisPMAdminConfigActive      = 2

'//
'// NDIS_WMI_PM_ACTIVE_CAPABILITIES struct is used with
'// GUID_NDIS_PM_ACTIVE_CAPABILITIES WMI method
'//
%NDIS_WMI_PM_ACTIVE_CAPABILITIES_REVISION_1 = 1

' // Size = 28 bytes
TYPE NDIS_WMI_PM_ACTIVE_CAPABILITIES DWORD
   ' // Header.Type = NDIS_OBJECT_TYPE_DEFAULT;
   ' // Header.Revision = NDIS_WMI_PM_ACTIVE_CAPABILITIES_REVISION_1;
   ' // Header.Size = sizeof(NDIS_WMI_PM_ACTIVE_CAPABILITIES);
   Header                  AS NDIS_OBJECT_HEADER
   WakeOnPattern           AS LONG   ' NDIS_PM_CAPABILITY_STATE
   WakeOnMagicPacket       AS LONG   ' NDIS_PM_CAPABILITY_STATE
   DeviceSleepOnDisconnect AS LONG   ' NDIS_PM_CAPABILITY_STATE
   PMARPOffload            AS LONG   ' NDIS_PM_CAPABILITY_STATE
   PMNSOffload             AS LONG   ' NDIS_PM_CAPABILITY_STATE
   PMWiFiRekeyOffload      AS LONG   ' NDIS_PM_CAPABILITY_STATE
END TYPE

'#define NDIS_SIZEOF_WMI_PM_ACTIVE_CAPABILITIES_REVISION_1 RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_PM_ACTIVE_CAPABILITIES, PMWiFiRekeyOffload)


'//
'// receive filter data structures and definitions
'//


'//
'// used in SupportedHeaders field of NDIS_RECEIVE_FILTER_CAPABILITIES
'// structure
'//
%NDIS_RECEIVE_FILTER_MAC_HEADER_SUPPORTED            = &H00000001???


'//
'// used in SupportedMacHeaderFields field of NDIS_RECEIVE_FILTER_CAPABILITIES
'// structure
'//
%NDIS_RECEIVE_FILTER_MAC_HEADER_DEST_ADDR_SUPPORTED      = &H00000001???
%NDIS_RECEIVE_FILTER_MAC_HEADER_SOURCE_ADDR_SUPPORTED    = &H00000002???
%NDIS_RECEIVE_FILTER_MAC_HEADER_PROTOCOL_SUPPORTED       = &H00000004???
%NDIS_RECEIVE_FILTER_MAC_HEADER_VLAN_ID_SUPPORTED        = &H00000008???
%NDIS_RECEIVE_FILTER_MAC_HEADER_PRIORITY_SUPPORTED       = &H00000010???



'//
'// used in SupportedFilterTests field of NDIS_RECEIVE_FILTER_CAPABILITIES
'// structure
'//
%NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_EQUAL_SUPPORTED      = &H00000001???
%NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_MASK_EQUAL_SUPPORTED = &H00000002???


'//
'// used in SupportedQueueProperties field of NDIS_RECEIVE_FILTER_CAPABILITIES
'// structure
'//
%NDIS_RECEIVE_FILTER_MSI_X_SUPPORTED                         = &H00000001???
%NDIS_RECEIVE_FILTER_VM_QUEUE_SUPPORTED                      = &H00000002???
%NDIS_RECEIVE_FILTER_LOOKAHEAD_SPLIT_SUPPORTED               = &H00000004???



'//
'// The following bits are used in EnabledFilterTypes field of
'// NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS structure and
'// EnabledFilterTypes field of NDIS_RECEIVE_FILTER_CAPABILITIES structure
'//
%NDIS_RECEIVE_FILTER_VMQ_FILTERS_ENABLED                     = &H00000001???



'//
'// The following bits are used in EnabledQueueTypes field of
'// NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS structure and
'// EnabledQueueTypes field of NDIS_RECEIVE_FILTER_CAPABILITIES structure
'//
%NDIS_RECEIVE_FILTER_VM_QUEUES_ENABLED                       = &H00000001???



'//
'// Data structures for advertising generic filtering capabilities
'// in ReceiveFilterCapabilities field of NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES
'// structure, OID_RECEIVE_FILTER_HARDWARE_CAPABILITIES  and
'// OID_RECEIVE_FILTER_CURRENT_CAPABILITIES query OIDs
'//
%NDIS_RECEIVE_FILTER_CAPABILITIES_REVISION_1 = 1

' // Size = 56 bytes
TYPE NDIS_RECEIVE_FILTER_CAPABILITIES DWORD
   Header                   AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   Flags                    AS DWORD                ' ULONG
   EnabledFilterTypes       AS DWORD                ' ULONG
   EnabledQueueTypes        AS DWORD                ' ULONG
   NumQueues                AS DWORD                ' ULONG
   SupportedQueueProperties AS DWORD                ' ULONG
   SupportedFilterTests     AS DWORD                ' ULONG
   SupportedHeaders         AS DWORD                ' ULONG
   SupportedMacHeaderFields AS DWORD                ' ULONG
   MaxMacHeaderFilters      AS DWORD                ' ULONG
   MaxQueueGroups           AS DWORD                ' ULONG
   MaxQueuesPerQueueGroup   AS DWORD                ' ULONG
   MinLookaheadSplitSize    AS DWORD                ' ULONG
   MaxLookaheadSplitSize    AS DWORD                ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_CAPABILITIES_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_CAPABILITIES, MaxLookaheadSplitSize)


'//
'// Data structure for advertising the NIC VMQ capabilities
'// Used in HardwareNicSwitchCapabilities and CurrentNicSwitchCapabilities
'// fields of NDIS_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES,
'// OID_NIC_SWITCH_HARDWARE_CAPABILITIES and OID_NIC_SWITCH_CURRENT_CAPABILITIES
'//
%NDIS_NIC_SWITCH_CAPABILITIES_REVISION_1 = 1

' // Size = 32 bytes
TYPE NDIS_NIC_SWITCH_CAPABILITIES DWORD
   Header                 AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   Flags                  AS DWORD                ' ULONG
   NdisReserved1          AS DWORD                ' ULONG
   NumTotalMacAddresses   AS DWORD                ' ULONG
   NumMacAddressesPerPort AS DWORD                ' ULONG
   NumVlansPerPort        AS DWORD                ' ULONG
   NdisReserved2          AS DWORD                ' ULONG
   NdisReserved3          AS DWORD                ' ULONG
END TYPE

'#define NDIS_SIZEOF_NIC_SWITCH_CAPABILITIES_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_NIC_SWITCH_CAPABILITIES, NdisReserved3)

'//
'// NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS is used in
'// OID_RECEIVE_FILTER_GLOBAL_PARAMETERS query OID
'// in order to query particular aspects
'// of receive filtering for a miniport adapter
'//
%NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS DWORD
   Header             AS NDIS_OBJECT_HEADER   ' NDIS_OBJECT_HEADER
   Flags              AS DWORD                ' ULONG
   EnabledFilterTypes AS DWORD                ' ULONG
   EnabledQueueTypes  AS DWORD                ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_GLOBAL_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS, EnabledQueueTypes)

'typedef ULONG NDIS_RECEIVE_QUEUE_ID, *PNDIS_RECEIVE_QUEUE_ID;
'typedef ULONG NDIS_RECEIVE_QUEUE_GROUP_ID, *PNDIS_RECEIVE_QUEUE_GROUP_ID;

%NDIS_DEFAULT_RECEIVE_QUEUE_ID       = 0
%NDIS_DEFAULT_RECEIVE_QUEUE_GROUP_ID = 0
%NDIS_DEFAULT_RECEIVE_FILTER_ID      = 0

'typedef ULONG NDIS_RECEIVE_FILTER_ID, *PNDIS_RECEIVE_FILTER_ID;

' enum NDIS_RECEIVE_FILTER_TYPE
%NdisReceiveFilterTypeUndefined = 0
%NdisReceiveFilterTypeVMQueue   = 1
%NdisReceiveFilterTypeMaximum   = 2

' enum NDIS_FRAME_HEADER
%NdisFrameHeaderUndefined = 0
%NdisFrameHeaderMac       = 1
%NdisFrameHeaderMaximum   = 2

' enum NDIS_MAC_HEADER_FIELD
%NdisMacHeaderFieldUndefined          = 0
%NdisMacHeaderFieldDestinationAddress = 1
%NdisMacHeaderFieldSourceAddress      = 2
%NdisMacHeaderFieldProtocol           = 3
%NdisMacHeaderFieldVlanId             = 4
%NdisMacHeaderFieldPriority           = 5
%NdisMacHeaderFieldMaximum            = 6


' enum NDIS_RECEIVE_FILTER_TEST
%NdisReceiveFilterTestUndefined = 0
%NdisReceiveFilterTestEqual     = 1
%NdisReceiveFilterTestMaskEqual = 2
%NdisReceiveFilterTestMaximum   = 3


'//
'// Flags used in NDIS_RECEIVE_FILTER_FIELD_PARAMETERS.Flags field
'//
%NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO = &H00000001???

'//
'// NDIS_RECEIVE_FILTER_FIELD_PARAMETERS is used in
'// NDIS_RECEIVE_FILTER_PARAMETERS structure
'//
%NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_1 = 1

' // Size = 4 bytes
UNION NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_HEADER_FIELD
   MacHeaderField AS LONG   ' NDIS_MAC_HEADER_FIELD
END UNION

' // Size = 16 bytes
UNION NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_FIELD_VALUE
   FieldByteValue          AS BYTE    ' UCHAR
   FieldShortValue         AS WORD    ' USHORT
   FieldLongValue          AS DWORD   ' ULONG
   FieldLong64Value        AS QUAD    ' ULONG64
   FieldByteArrayValue(15) AS BYTE    ' UCHAR[16]
END UNION

' // Size = 16 bytes
UNION NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_RESULT_VALUE
   ResultByteValue          AS BYTE    ' UCHAR
   ResultShortValue         AS WORD    ' USHORT
   ResultLongValue          AS DWORD   ' ULONG
   ResultLong64Value        AS QUAD    ' ULONG64
   ResultByteArrayValue(15) AS BYTE    ' UCHAR[16]
END UNION

' // Size = 56 bytes
TYPE NDIS_RECEIVE_FILTER_FIELD_PARAMETERS QWORD FILL
   Header            AS NDIS_OBJECT_HEADER
   Flags             AS DWORD   ' ULONG
   FrameHeader       AS LONG    ' NDIS_FRAME_HEADER
   ReceiveFilterTest AS LONG    ' NDIS_RECEIVE_FILTER_TEST
   HeaderField       AS NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_HEADER_FIELD
   FieldValue        AS NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_FIELD_VALUE
   ResultValue       AS NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_RESULT_VALUE
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_FIELD_PARAMETERS, ResultValue)


'//
'// NDIS_RECEIVE_FILTER_PARAMETERS is used in
'// OID_RECEIVE_FILTER_PARAMETERS and OID_RECEIVE_FILTER_SET_FILTER
'//
%NDIS_RECEIVE_FILTER_PARAMETERS_REVISION_1 = 1

' // Size = 36 bytes
TYPE NDIS_RECEIVE_FILTER_PARAMETERS DWORD
   Header                          AS NDIS_OBJECT_HEADER
   Flags                           AS DWORD   ' ULONG
   FilterType                      AS LONG    ' NDIS_RECEIVE_FILTER_TYPE
   QueueId                         AS DWORD   ' NDIS_RECEIVE_QUEUE_ID
   FilterId                        AS DWORD   ' NDIS_RECEIVE_FILTER_ID
   FieldParametersArrayOffset      AS DWORD   ' ULONG // from the beginning of this structure
   FieldParametersArrayNumElements AS DWORD   ' ULONG
   FieldParametersArrayElementSize AS DWORD   ' ULONG
   RequestedFilterIdBitCount       AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_PARAMETERS, RequestedFilterIdBitCount)


'//
'// NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS is used in
'// OID_RECEIVE_FILTER_CLEAR_FILTER
'//
%NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS DWORD
   Header   AS NDIS_OBJECT_HEADER
   Flags    AS DWORD   ' ULONG
   QueueId  AS DWORD   ' NDIS_RECEIVE_QUEUE_ID
   FilterId AS DWORD   ' NDIS_RECEIVE_FILTER_ID
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_CLEAR_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS, FilterId)


'//
'// enum value used in QueueType field of NDIS_RECEIVE_QUEUE_PARAMETERS structure
'//
' enum NDIS_RECEIVE_QUEUE_TYPE
%NdisReceiveQueueTypeUnspecified = 0
%NdisReceiveQueueTypeVMQueue     = 1
%NdisReceiveQueueTypeMaximum     = 2


'//
'// bits used in Flags field of NDIS_RECEIVE_QUEUE_PARAMETERS in OID_RECEIVE_FILTER_ALLOCATE_QUEUE
'// and OID_RECEIVE_FILTER_QUEUE_PARAMETERS -query- OID
'//
%NDIS_RECEIVE_QUEUE_PARAMETERS_PER_QUEUE_RECEIVE_INDICATION = &H00000001???
%NDIS_RECEIVE_QUEUE_PARAMETERS_LOOKAHEAD_SPLIT_REQUIRED     = &H00000002???

'//
'// bits used in Flags field of NDIS_RECEIVE_QUEUE_PARAMETERS in OID_RECEIVE_FILTER_QUEUE_PARAMETERS -set- OID
'//
%NDIS_RECEIVE_QUEUE_PARAMETERS_FLAGS_CHANGED                         = &H00010000???
%NDIS_RECEIVE_QUEUE_PARAMETERS_PROCESSOR_AFFINITY_CHANGED            = &H00020000???
%NDIS_RECEIVE_QUEUE_PARAMETERS_SUGGESTED_RECV_BUFFER_NUMBERS_CHANGED = &H00040000???
%NDIS_RECEIVE_QUEUE_PARAMETERS_NAME_CHANGED                          = &H00080000???


%NDIS_RECEIVE_QUEUE_PARAMETERS_CHANGE_MASK                           = &HFFFF0000???

'typedef NDIS_IF_COUNTED_STRING NDIS_QUEUE_NAME, *PNDIS_QUEUE_NAME;
MACRO NDIS_QUEUE_NAME = NDIS_IF_COUNTED_STRING
'typedef NDIS_IF_COUNTED_STRING NDIS_VM_NAME, *PNDIS_VM_NAME;
MACRO NDIS_VM_NAME = NDIS_IF_COUNTED_STRING

'//
'// NDIS_RECEIVE_QUEUE_PARAMETERS is used in
'// OID_RECEIVE_FILTER_ALLOCATE_QUEUE and OID_RECEIVE_FILTER_QUEUE_PARAMETERS
'//
%NDIS_RECEIVE_QUEUE_PARAMETERS_REVISION_1 = 1

' // Size = 1076 bytes
TYPE NDIS_RECEIVE_QUEUE_PARAMETERS DWORD
   Header                     AS NDIS_OBJECT_HEADER
   Flags                      AS DWORD                ' ULONG
   QueueType                  AS LONG                 ' NDIS_RECEIVE_QUEUE_TYPE
   QueueId                    AS DWORD                ' NDIS_RECEIVE_QUEUE_ID
   QueueGroupId               AS DWORD                ' NDIS_RECEIVE_QUEUE_GROUP_ID
   ProcessorAffinity          AS GROUP_AFFINITY
   NumSuggestedReceiveBuffers AS DWORD                ' ULONG
   MSIXTableEntry             AS DWORD                ' ULONG
   LookaheadSize              AS DWORD                ' ULONG
   VmName                     AS NDIS_VM_NAME
   QueueName                  AS NDIS_QUEUE_NAME
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_PARAMETERS, QueueName)

'//
'// NDIS_RECEIVE_QUEUE_FREE_PARAMETERS is used in
'// OID_RECEIVE_FILTER_FREE_QUEUE
'//
%NDIS_RECEIVE_QUEUE_FREE_PARAMETERS_REVISION_1 = 1

' // Size = 12 bytes
TYPE NDIS_RECEIVE_QUEUE_FREE_PARAMETERS DWORD
   Header  AS NDIS_OBJECT_HEADER
   Flags   AS DWORD   ' ULONG
   QueueId AS DWORD   ' NDIS_RECEIVE_QUEUE_ID
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_FREE_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_FREE_PARAMETERS, QueueId)

'//
'// the following enum type is used in NDIS_RECEIVE_QUEUE_STATE
'// and NDIS_RECEIVE_QUEUE_INFO
'//
' enum NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE
%NdisReceiveQueueOperationalStateUndefined  = 0
%NdisReceiveQueueOperationalStateRunning    = 1
%NdisReceiveQueueOperationalStatePaused     = 2
%NdisReceiveQueueOperationalStateDmaStopped = 3
%NdisReceiveQueueOperationalStateMaximum    = 4

'//
'// NDIS_RECEIVE_QUEUE_INFO is used with NDIS_RECEIVE_QUEUE_INFO_ARRAY
'// in OID_RECEIVE_FILTER_ENUM_QUEUES that enumerates receive queues
'// on a miniport or open
'//
%NDIS_RECEIVE_QUEUE_INFO_REVISION_1 = 1

' // Size = 1080 bytes
TYPE NDIS_RECEIVE_QUEUE_INFO DWORD
   Header                     AS NDIS_OBJECT_HEADER
   Flags                      AS DWORD                ' ULONG
   QueueType                  AS LONG                 ' NDIS_RECEIVE_QUEUE_TYPE
   QueueId                    AS DWORD                ' NDIS_RECEIVE_QUEUE_ID
   QueueGroupId               AS DWORD                ' NDIS_RECEIVE_QUEUE_GROUP_ID
   QueueState                 AS LONG                 ' NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE
   ProcessorAffinity          AS GROUP_AFFINITY
   NumSuggestedReceiveBuffers AS DWORD                ' ULONG
   MSIXTableEntry             AS DWORD                ' ULONG
   LookaheadSize              AS DWORD                ' ULONG
   VmName                     AS NDIS_VM_NAME
   QueueName                  AS NDIS_QUEUE_NAME
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_INFO_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_INFO, QueueName)


'//
'// NDIS_RECEIVE_QUEUE_INFO_ARRAY is used in OID_RECEIVE_FILTER_ENUM_QUEUES
'// that enumerates receive queues on a miniport or open. Each element in the
'// array is an NDIS_RECEIVE_QUEUE_INFO structure
'//
%NDIS_RECEIVE_QUEUE_INFO_ARRAY_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_RECEIVE_QUEUE_INFO_ARRAY DWORD
   Header             AS NDIS_OBJECT_HEADER
   FirstElementOffset AS DWORD   ' ULONG
   NumElements        AS DWORD   ' ULONG
   ElementSize        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_INFO_ARRAY_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_INFO_ARRAY, ElementSize)

'//
'// NDIS_RECEIVE_FILTER_INFO is used with NDIS_RECEIVE_FILTER_INFO_ARRAY
'// in OID_RECEIVE_FILTER_ENUM_FILTERS that enumerates receive
'// filters on a queue
'//
%NDIS_RECEIVE_FILTER_INFO_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_RECEIVE_FILTER_INFO DWORD
   Header     AS NDIS_OBJECT_HEADER
   Flags      AS DWORD   ' ULONG
   FilterType AS LONG    ' NDIS_RECEIVE_FILTER_TYPE
   FilterId   AS DWORD   ' NDIS_RECEIVE_FILTER_ID
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_INFO_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_INFO, FilterId)

'//
'// NDIS_RECEIVE_FILTER_INFO_ARRAY is used in OID_RECEIVE_FILTER_ENUM_FILTERS
'// that enumerates receive filters on a queue. Each element in the array
'// is an NDIS_RECEIVE_FILTER_INFO structure
'//
%NDIS_RECEIVE_FILTER_INFO_ARRAY_REVISION_1 = 1

' // Size = 20 bytes
TYPE NDIS_RECEIVE_FILTER_INFO_ARRAY DWORD
   Header             AS NDIS_OBJECT_HEADER
   QueueId            AS DWORD   ' NDIS_RECEIVE_QUEUE_ID
   FirstElementOffset AS DWORD   ' ULONG
   NumElements        AS DWORD   ' ULONG
   ElementSize        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_FILTER_INFO_ARRAY_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_FILTER_INFO_ARRAY, ElementSize)

'//
'// NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS is used
'// in OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE OID.
'//
%NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS_REVISION_1 = 1

' // Size = 16 bytes
TYPE NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS DWORD
   Header           AS NDIS_OBJECT_HEADER
   Flags            AS DWORD   ' ULONG
   QueueId          AS DWORD   ' NDIS_RECEIVE_QUEUE_ID
   CompletionStatus AS LONG    ' NDIS_STATUS
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS_REVISION_1 \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS, CompletionStatus)

'//
'// NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY is used in
'// OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE OID request.
'// Each element in array is an NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS
'// structure.
'//
%NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY_REVISION_1 = 1

' // Size = 20 bytes
TYPE NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY DWORD
   Header             AS NDIS_OBJECT_HEADER
   Flags              AS DWORD   ' ULONG
   FirstElementOffset AS DWORD   ' ULONG // offset to an array of NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS
   NumElements        AS DWORD   ' ULONG
   ElementSize        AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY_REVISION_1 \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY, ElementSize)


'#endif // #if (NDIS_SUPPORT_NDIS620)

'#if ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)

%NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_1 = 1

'//
'// What kind the receive scale capabilities the miniport can support, miniport drivers return
'// some of these flags as CapabilitiesFlags in a structure _NDIS_RECEIVE_SCALE_CAPABILITIES
'// when they get a query about theire receive side scale capabilities.
'//
%NDIS_RSS_CAPS_MESSAGE_SIGNALED_INTERRUPTS                    = &H01000000???
%NDIS_RSS_CAPS_CLASSIFICATION_AT_ISR                          = &H02000000???
%NDIS_RSS_CAPS_CLASSIFICATION_AT_DPC                          = &H04000000???

'#if NDIS_SUPPORT_NDIS620

%NDIS_RSS_CAPS_USING_MSI_X                                    = &H08000000???

'#endif
'//
'// What kind of hash field type the miniport can support
'//
%NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV4                             = &H00000100???
%NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6                             = &H00000200???
%NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6_EX                          = &H00000400???

'//
'// the following structure defines the Receive scale capabilities of the miniport
'//
' // Size = 16 bytes
TYPE NDIS_RECEIVE_SCALE_CAPABILITIES DWORD
   Header                    AS NDIS_OBJECT_HEADER
   CapabilitiesFlags         AS DWORD   ' ULONG
   NumberOfInterruptMessages AS DWORD   ' ULONG
   NumberOfReceiveQueues     AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_SCALE_CAPABILITIES_REVISION_1   \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_SCALE_CAPABILITIES, NumberOfReceiveQueues)

'//
'// What hash functions does NDIS support
'//
%NdisHashFunctionToeplitz                            = &H00000001???   ' // supported hash function 1 -- Main RSS hash function
%NdisHashFunctionReserved1                           = &H00000002???  ' // supported hash function 2
%NdisHashFunctionReserved2                           = &H00000004???   ' // supported hash function 3
%NdisHashFunctionReserved3                           = &H00000008???   ' // supported hash function 4

%NDIS_HASH_FUNCTION_MASK                             = &H000000FF???
%NDIS_HASH_TYPE_MASK                                 = &H00FFFF00???

'#define NDIS_RSS_HASH_FUNC_FROM_HASH_INFO(_HashInfo)  \
'        ((_HashInfo) & (NDIS_HASH_FUNCTION_MASK))
MACRO NDIS_RSS_HASH_FUNC_FROM_HASH_INFO(HashInfo_) = (HashInfo_ AND %NDIS_HASH_FUNCTION_MASK)

'#define NDIS_RSS_HASH_TYPE_FROM_HASH_INFO(_HashInfo)  \
'        ((_HashInfo) & (NDIS_HASH_TYPE_MASK))
MACRO NDIS_RSS_HASH_TYPE_FROM_HASH_INFO(HashInfo_) = (HashInfo_ AND %NDIS_HASH_TYPE_MASK)

'#define NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC(_HashType, _HashFunction) \
'        ((_HashType) | (_HashFunction))
MACRO NDIS_RSS_HASH_INFO_FROM_TYPE_AND_FUNC(HashInfo_, HashFunction_) = (HashInfo_ OR HashFunction_)

'//
'// What kind of hash field type the protocol what the miniport to do
'//
%NDIS_HASH_IPV4                                      = &H00000100???
%NDIS_HASH_TCP_IPV4                                  = &H00000200???
%NDIS_HASH_IPV6                                      = &H00000400???
%NDIS_HASH_IPV6_EX                                   = &H00000800???
%NDIS_HASH_TCP_IPV6                                  = &H00001000???
%NDIS_HASH_TCP_IPV6_EX                               = &H00002000???

'//
'// Flags to denote the parameters that are kept unmodified.
'//
%NDIS_RSS_PARAM_FLAG_BASE_CPU_UNCHANGED              = &H0001???
%NDIS_RSS_PARAM_FLAG_HASH_INFO_UNCHANGED             = &H0002???
%NDIS_RSS_PARAM_FLAG_ITABLE_UNCHANGED                = &H0004???
%NDIS_RSS_PARAM_FLAG_HASH_KEY_UNCHANGED              = &H0008???
%NDIS_RSS_PARAM_FLAG_DISABLE_RSS                     = &H0010???

%NDIS_RSS_INDIRECTION_TABLE_SIZE_REVISION_1          = 128
%NDIS_RSS_HASH_SECRET_KEY_SIZE_REVISION_1            = 40

'//
'// used in OID_GEN_RECEIVE_SCALE_PARAMETERS
'//
%NDIS_RECEIVE_SCALE_PARAMETERS_REVISION_1 = 1

'#if NDIS_SUPPORT_NDIS620

%NDIS_RECEIVE_SCALE_PARAMETERS_REVISION_2 = 2

'#endif

' // Size = 40 bytes
TYPE NDIS_RECEIVE_SCALE_PARAMETERS DWORD FILL
   Header                  AS NDIS_OBJECT_HEADER
   ' // Qualifies the rest of the information.
   Flags                   AS WORD   ' USHORT
   ' // The base CPU number to do receive processing. not used.
   BaseCpuNumber           AS WORD   ' USHORT
   ' // This describes the hash function and type being enabled.
   HashInformation         AS DWORD   ' ULONG
   ' // The size of indirection table array.
   IndirectionTableSize    AS WORD   ' USHORT
   ' // The offset of the indirection table from the beginning of this structure.
   IndirectionTableOffset  AS DWORD   ' ULONG
   ' // The size of the secret key.
   HashSecretKeySize       AS WORD   ' USHORT
   ' // The offset of the secret key from the beginning of this structure.
   HashSecretKeyOffset     AS DWORD   ' ULONG
'#if NDIS_SUPPORT_NDIS620
   ProcessorMasksOffset    AS DWORD   ' ULONG
   NumberOfProcessorMasks  AS DWORD   ' ULONG // Array of type GROUP_AFFINITY representing procs used in the indirection table
   ProcessorMasksEntrySize AS DWORD   ' ULONG
'#endif
   ' // The hash map table is a CCHAR array for Revision 1.
   ' // It is a PROCESSOR_NUMBER array for Revision 2
END TYPE

'#define NDIS_SIZEOF_RECEIVE_SCALE_PARAMETERS_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_SCALE_PARAMETERS, HashSecretKeyOffset)

'//
'// Maximum indirection table and private key sizes for revision 1
'//
%NDIS_RSS_INDIRECTION_TABLE_MAX_SIZE_REVISION_1 = 128
%NDIS_RSS_HASH_SECRET_KEY_MAX_SIZE_REVISION_1   = 40

'#if NDIS_SUPPORT_NDIS620

'#define NDIS_SIZEOF_RECEIVE_SCALE_PARAMETERS_REVISION_2    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_SCALE_PARAMETERS, ProcessorMasksEntrySize)

'//
'// Maximum indirection table and private key sizes for revision 2
'//
%NDIS_RSS_INDIRECTION_TABLE_MAX_SIZE_REVISION_2 = 128 * 4   ' (128*sizeof(PROCESSOR_NUMBER))
%NDIS_RSS_HASH_SECRET_KEY_MAX_SIZE_REVISION_2   =  40

'#endif

'//
'// Used in OID_GEN_RECEIVE_HASH
'//
%NDIS_RECEIVE_HASH_FLAG_ENABLE_HASH                      = &H00000001???
%NDIS_RECEIVE_HASH_FLAG_HASH_INFO_UNCHANGED              = &H00000002???
%NDIS_RECEIVE_HASH_FLAG_HASH_KEY_UNCHANGED               = &H00000004???

%NDIS_RECEIVE_HASH_PARAMETERS_REVISION_1                 = 1

' // Size = 20 bytes
TYPE NDIS_RECEIVE_HASH_PARAMETERS DWORD FILL
   Header              AS NDIS_OBJECT_HEADER
   ' // Qualifies the rest of the information.
   Flags               AS DWORD   ' ULONG
   ' // This describes the hash function and type being enabled.
   HashInformation     AS DWORD   ' ULONG
   ' // The size of the secret key.
   HashSecretKeySize   AS WORD   ' USHORT
   ' // The offset of the secret key from the beginning of this structure.
   HashSecretKeyOffset AS DWORD   ' ULONG
END TYPE

'#define NDIS_SIZEOF_RECEIVE_HASH_PARAMETERS_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RECEIVE_HASH_PARAMETERS, HashSecretKeyOffset)


' enum NDIS_PROCESSOR_VENDOR
%NdisProcessorVendorUnknown      = 0
%NdisProcessorVendorGenuinIntel  = 1
%NdisProcessorVendorGenuineIntel = %NdisProcessorVendorGenuinIntel
%NdisProcessorVendorAuthenticAMD = 2

'#if NDIS_SUPPORT_NDIS620

'//
'// Used in the RssProcessorArray in NDIS_RSS_PROCESSOR_INFO
'//
' // Size = 8 bytes
TYPE NDIS_RSS_PROCESSOR BYTE
   ProcNum         AS PROCESSOR_NUMBER
   PreferenceIndex AS WORD               ' USHORT
   Reserved        AS WORD               ' USHORT
END TYPE

'#define NDIS_SIZEOF_RSS_PROCESSOR_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RSS_PROCESSOR, PreferenceIndex)

%NDIS_RSS_PROCESSOR_INFO_REVISION_1 = 1

'//
'// Used in NdisGetRssProcessorInformation API
'//
' // Size = 32 bytes
TYPE NDIS_RSS_PROCESSOR_INFO DWORD FILL
   Header                  AS NDIS_OBJECT_HEADER
   Flags                   AS DWORD                ' ULONG
   RssBaseProcessor        AS PROCESSOR_NUMBER
   MaxNumRssProcessors     AS DWORD                ' ULONG
   PreferredNumaNode       AS WORD                 ' USHORT
   RssProcessorArrayOffset AS DWORD                ' ULONG
   RssProcessorCount       AS DWORD                ' ULONG  // | Array of NDIS_RSS_PROCESSOR
   RssProcessorEntrySize   AS DWORD                ' ULONG
END TYPE

'C_ASSERT(sizeof(NDIS_RSS_PROCESSOR_INFO) % __alignof(NDIS_RSS_PROCESSOR) == 0);

'#define NDIS_SIZEOF_RSS_PROCESSOR_INFO_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_RSS_PROCESSOR_INFO, RssProcessorEntrySize)


'//
'// Used in ProcessorInfo array in NDIS_SYSTEM_PROCESSOR_INFO_EX
'//
' // Size = 20 bytes
TYPE NDIS_PROCESSOR_INFO_EX BYTE
   ProcNum       AS PROCESSOR_NUMBER
   SocketId      AS DWORD   ' ULONG
   CoreId        AS DWORD   ' ULONG
   HyperThreadId AS DWORD   ' ULONG
   NodeId        AS WORD    ' USHORT
   NodeDistance  AS WORD    ' USHORT
END TYPE

%NDIS_SYSTEM_PROCESSOR_INFO_EX_REVISION_1 = 1

'//
'// Used in NdisGetProcessorInformationEx API
'//
' // Size = 40 bytes
TYPE NDIS_SYSTEM_PROCESSOR_INFO_EX DWORD
   Header                        AS NDIS_OBJECT_HEADER
   Flags                         AS DWORD   ' ULONG
   ProcessorVendor               AS LONG    ' NDIS_PROCESSOR_VENDOR
   NumSockets                    AS DWORD   ' ULONG
   NumCores                      AS DWORD   ' ULONG
   NumCoresPerSocket             AS DWORD   ' ULONG
   MaxHyperThreadingProcsPerCore AS DWORD   ' ULONG
   ProcessorInfoOffset           AS DWORD   ' ULONG
   NumberOfProcessors            AS DWORD   ' ULONG // | Array of NDIS_PROCESSOR_INFO_EX
   ProcessorInfoEntrySize        AS DWORD   ' ULONG
END TYPE

'C_ASSERT(sizeof(NDIS_SYSTEM_PROCESSOR_INFO_EX) % __alignof(NDIS_PROCESSOR_INFO_EX) == 0);

'#define NDIS_SIZEOF_SYSTEM_PROCESSOR_INFO_EX_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_SYSTEM_PROCESSOR_INFO_EX, ProcessorInfoEntrySize)

'//
'// Enum to identify Hypervisor Parition type
'// Used in NDIS_HYPERVISOR_INFO.PartitionType
'//
' enum NDIS_HYPERVISOR_PARTITION_TYPE
%NdisHypervisorPartitionTypeUnknown    = 0
%NdisHypervisorPartitionTypeMsHvParent = 1
%NdisHypervisorPartitionMsHvChild      = 2
%NdisHypervisorPartitionTypeMax        = 3

'//
'// Flags used in NDIS_HYPERVISOR_INFO.Flags field
'//
%NDIS_HYPERVISOR_INFO_FLAG_HYPERVISOR_PRESENT            = &H00000001???

%NDIS_HYPERVISOR_INFO_REVISION_1 = 1

'//
'// Structure used to return Hypervisor related information
'// in NdisGetHypervisorInfo API
'//
' // Size = 12 bytes
TYPE NDIS_HYPERVISOR_INFO DWORD
   Header        AS NDIS_OBJECT_HEADER
   Flags         AS DWORD   ' ULONG
   PartitionType AS LONG    ' NDIS_HYPERVISOR_PARTITION_TYPE
END TYPE

'#define NDIS_SIZEOF_HYPERVISOR_INFO_REVISION_1    \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_HYPERVISOR_INFO, PartitionType)

'//
'// The following data structures are used with Receive Queue related WMI
'// guids. NDIS will translate these data structures to those used
'// in OIDs
'//

' // Size = 16 bytes
TYPE NDIS_WMI_GROUP_AFFINITY   ' Must be 8 byte aligned
   Mask        AS QUAD   ' ULONG64
   Group       AS WORD   ' USHORT
   Reserved(2) AS WORD   ' USHORT[3]
END TYPE

'//
'// NDIS_WMI_RECEIVE_QUEUE_PARAMETERS is used in GUID_NDIS_RECEIVE_FILTER_QUEUE_PARAMETERS
'//
%NDIS_WMI_RECEIVE_QUEUE_PARAMETERS_REVISION_1 = 1

' // Size = 1088 bytes
TYPE NDIS_WMI_RECEIVE_QUEUE_PARAMETERS   ' Must be 8 byte aligned
   Header                     AS NDIS_OBJECT_HEADER
   Flags                      AS DWORD                     ' ULONG
   QueueType                  AS LONG                      ' NDIS_RECEIVE_QUEUE_TYPE
   QueueId                    AS DWORD                     ' NDIS_RECEIVE_QUEUE_ID
   QueueGroupId               AS DWORD                     ' NDIS_RECEIVE_QUEUE_GROUP_ID
   ProcessorAffinity          AS NDIS_WMI_GROUP_AFFINITY
   alignment1__               AS DWORD
   NumSuggestedReceiveBuffers AS DWORD                     ' ULONG
   MSIXTableEntry             AS DWORD                     ' ULONG
   LookaheadSize              AS DWORD                     ' ULONG
   VmName                     AS NDIS_VM_NAME
   QueueName                  AS NDIS_QUEUE_NAME
   alignment2__               AS DWORD
END TYPE

'#define NDIS_SIZEOF_WMI_RECEIVE_QUEUE_PARAMETERS_REVISION_1     \
'    RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_RECEIVE_QUEUE_PARAMETERS, QueueName)

'//
'// NDIS_WMI_RECEIVE_QUEUE_INFO is used in GUID_NDIS_RECEIVE_FILTER_ENUM_QUEUES
'//
%NDIS_WMI_RECEIVE_QUEUE_INFO_REVISION_1 = 1

' // Size = 1088 bytes
TYPE NDIS_WMI_RECEIVE_QUEUE_INFO   ' Must be 8 byte aligned
   Header                     AS NDIS_OBJECT_HEADER
   Flags                      AS DWORD                     ' ULONG
   QueueType                  AS LONG                      ' NDIS_RECEIVE_QUEUE_TYPE
   QueueId                    AS DWORD                     ' NDIS_RECEIVE_QUEUE_ID
   QueueGroupId               AS DWORD                     ' NDIS_RECEIVE_QUEUE_GROUP_ID
   QueueState                 AS LONG                      ' NDIS_RECEIVE_QUEUE_OPERATIONAL_STATE
   ProcessorAffinity          AS NDIS_WMI_GROUP_AFFINITY
   NumSuggestedReceiveBuffers AS DWORD                     ' ULONG
   MSIXTableEntry             AS DWORD                     ' ULONG
   LookaheadSize              AS DWORD                     ' ULONG
   VmName                     AS NDIS_VM_NAME
   QueueName                  AS NDIS_QUEUE_NAME
   alignment2__               AS DWORD
END TYPE

'#define NDIS_SIZEOF_WMI_RECEIVE_QUEUE_INFO_REVISION_1      \
'        RTL_SIZEOF_THROUGH_FIELD(NDIS_WMI_RECEIVE_QUEUE_INFO, QueueName)


'#endif // NDIS_SUPPORT_NDIS620

'#endif // ((NTDDI_VERSION >= NTDDI_VISTA) || NDIS_SUPPORT_NDIS6)

'#endif // NTDDI_VERSION >= NTDDI_VISTA
