' ########################################################################################
' Microsoft Windows
' File: cfgmgr32.inc
' Contents: User APIs for the Configuration Manager
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CFGMGR32_INC = 1

#INCLUDE ONCE "cfg.inc"

#IF NOT %DEF(%GUID_DEFINED)
#include ONCE "guiddef.inc"
#ENDIF

'typedef  CONST VOID *PCVOID;

'//--------------------------------------------------------------
'// General size definitions
'//--------------------------------------------------------------

%MAX_DEVICE_ID_LEN     = 200
%MAX_DEVNODE_ID_LEN    = %MAX_DEVICE_ID_LEN

%MAX_GUID_STRING_LEN   = 39          ' // 38 chars + terminator null
%MAX_CLASS_NAME_LEN    = 32
%MAX_PROFILE_LEN       = 80

%MAX_CONFIG_VALUE      = 9999
%MAX_INSTANCE_VALUE    = 9999

%MAX_MEM_REGISTERS     = 9     ' // Win95 compatibility--not applicable to 32-bit ConfigMgr
%MAX_IO_PORTS          = 20    ' // Win95 compatibility--not applicable to 32-bit ConfigMgr
%MAX_IRQS              = 7     ' // Win95 compatibility--not applicable to 32-bit ConfigMgr
%MAX_DMA_CHANNELS      = 7     ' // Win95 compatibility--not applicable to 32-bit ConfigMgr

'DWORD_MAX             0xffffffffUL
'DWORDLONG_MAX         0xffffffffffffffffui64

%CONFIGMG_VERSION      = &H0400

'//--------------------------------------------------------------
'// Data types
'//--------------------------------------------------------------

'#ifdef NT_INCLUDED

'typedef unsigned __int64 DWORDLONG;
'typedef DWORDLONG *PDWORDLONG;

'#endif /* NT_INCLUDED */

'//
'// Standardized Return Value data type
'//
'typedef DWORD        RETURN_TYPE;
'typedef RETURN_TYPE  CONFIGRET;

'//
'// Device Instance Handle data type
'//
'typedef DWORD       DEVNODE, DEVINST;
'typedef DEVNODE    *PDEVNODE, *PDEVINST;

'//
'// Device Instance Identifier data type
'// The device instance ID specifies the registry path, relative to the
'// Enum key , for a device instance.  For example:  \Root\*PNP0500\0000.
'//
'typedef __nullterminated CHAR  *DEVNODEID_A, *DEVINSTID_A; // Device ID ANSI name.
'typedef __nullterminated WCHAR *DEVNODEID_W, *DEVINSTID_W; // Device ID Unicode name.
'#ifdef UNICODE
'typedef DEVNODEID_W DEVNODEID;
'typedef DEVINSTID_W DEVINSTID;
'#else
'typedef DEVNODEID_A DEVNODEID;
'typedef DEVINSTID_A DEVINSTID;
'#endif

'//
'// Logical Configuration Handle data type
'//
'typedef DWORD_PTR      LOG_CONF;
'typedef LOG_CONF      *PLOG_CONF;

'//
'// Resource Descriptor Handle data type
'//
'typedef DWORD_PTR      RES_DES;
'typedef RES_DES       *PRES_DES;

'//
'// Resource ID data type (may take any of the ResType_* values)
'//
'typedef ULONG          RESOURCEID;
'typedef RESOURCEID    *PRESOURCEID;

'//
'// Priority data type (may take any of the LCPRI_* values)
'//
'typedef ULONG          PRIORITY;
'typedef PRIORITY      *PPRIORITY;

'//
'// Range List Handle data type
'//
'typedef DWORD_PTR      RANGE_LIST;
'typedef RANGE_LIST    *PRANGE_LIST;

'//
'// Range Element Handle data type
'//
'typedef DWORD_PTR      RANGE_ELEMENT;
'typedef RANGE_ELEMENT *PRANGE_ELEMENT;

'//
'// Machine Handle data type
'//
'typedef  HANDLE        HMACHINE;
'typedef  HMACHINE     *PHMACHINE;

'//
'// Conflict List data types
'//
'typedef ULONG_PTR      CONFLICT_LIST;
'typedef CONFLICT_LIST *PCONFLICT_LIST;

' // Size = 280 bytes
TYPE CONFLICT_DETAILS_A DWORD
   CD_ulSize        AS DWORD                ' ULONG // size of structure, ie: sizeof(CONFLICT_DETAILS)
   CD_ulMask        AS DWORD                ' ULONG // indicates what information is required/valid
   CD_dnDevInst     AS DWORD                ' DEVINST // filled with DevInst of conflicting device if CM_CDMASK_DEVINST set
   CD_rdResDes      AS DWORD                ' RES_DES // filled with a ResDes of conflict if CM_CDMASK_RESDES set
   CD_ulFlags       AS DWORD                ' ULONG // various flags regarding conflict
   CD_szDescription AS ASCIIZ * %MAX_PATH   ' CHAR // description of conflicting device
END TYPE

' // Size = 540 bytes
TYPE CONFLICT_DETAILS_W DWORD
   CD_ulSize        AS DWORD                    ' ULONG // size of structure, ie: sizeof(CONFLICT_DETAILS)
   CD_ulMask        AS DWORD                    ' ULONG // indicates what information is required/valid
   CD_dnDevInst     AS DWORD                    ' DEVINST // filled with DevInst of conflicting device if CM_CDMASK_DEVINST set
   CD_rdResDes      AS DWORD                    ' RES_DES // filled with a ResDes of conflict if CM_CDMASK_RESDES set
   CD_ulFlags       AS DWORD                    ' ULONG // various flags regarding conflict
   CD_szDescription AS WSTRINGZ * %MAX_PATH     ' WCHAR // description of conflicting device
END TYPE

#IF %DEF(%UNICODE)
MACRO CONFLICT_DETAILS = CONFLICT_DETAILS_W
#ELSE
MACRO CONFLICT_DETAILS = CONFLICT_DETAILS_A
#ENDIF

%CM_CDMASK_DEVINST      = &H00000001???   ' // mask to retrieve CD_dnDevInst attribute for conflict
%CM_CDMASK_RESDES       = &H00000002???   ' // mask to retrieve CD_rdResDes attribute for conflict
%CM_CDMASK_FLAGS        = &H00000004???   ' // mask to retrieve CD_ulFlags attribute for conflict
%CM_CDMASK_DESCRIPTION  = &H00000008???   ' // mask to retrieve CD_szDescription attribute for conflict
%CM_CDMASK_VALID        = &H0000000F???   ' // valid bits

%CM_CDFLAGS_DRIVER      = &H00000001???     ' // CD_ulFlags: CD_szDescription reports back legacy driver name
%CM_CDFLAGS_ROOT_OWNED  = &H00000002???     ' // CD_ulFlags: Root owned device
%CM_CDFLAGS_RESERVED    = &H00000004???     ' // CD_ulFlags: Specified range is not available for use

'typedef  ULONG             REGDISPOSITION;

'//
'// use 1 byte packing for the data structures
'//
'#include "pshpack1.h"

'//--------------------------------------------------------------
'// Memory resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for memory ranges.  Each bit flag is
'// identified by a constant bitmask.  Following the bitmask definition,
'// are the two possible values.
'//
%mMD_MemoryType              = &H1???                  ' // Bitmask, whether memory is writable
%fMD_MemoryType              = %mMD_MemoryType         ' // compatibility
%fMD_ROM                     = &H0???                  ' // Memory range is read-only
%fMD_RAM                     = &H1???                  ' // Memory range may be written to

%mMD_32_24                   = &H2                     ' // Bitmask, memory is 24 or 32-bit
%fMD_32_24                   = %mMD_32_24              ' // compatibility
%fMD_24                      = &H0???                  ' // Memory range is 24-bit
%fMD_32                      = &H2???                  ' // Memory range is 32-bit

%mMD_Prefetchable            = &H4???                  ' // Bitmask,whether memory prefetchable
%fMD_Prefetchable            = %mMD_Prefetchable       ' // compatibility
%fMD_Pref                    = %mMD_Prefetchable       ' // compatibility
%fMD_PrefetchDisallowed      = &H0???                  ' // Memory range is not prefetchable
%fMD_PrefetchAllowed         = &H4???                  ' // Memory range is prefetchable

%mMD_Readable                = &H8???                  ' // Bitmask,whether memory is readable
%fMD_Readable                = %mMD_Readable           ' // compatibility
%fMD_ReadAllowed             = &H0???                  ' // Memory range is readable
%fMD_ReadDisallowed          = &H8???                  ' // Memory range is write-only

%mMD_CombinedWrite           = &H10???                 ' // Bitmask,supports write-behind
%fMD_CombinedWrite           = %mMD_CombinedWrite      ' // compatibility
%fMD_CombinedWriteDisallowed = &H0???                  ' // no combined-write caching
%fMD_CombinedWriteAllowed    = &H10???                 ' // supports combined-write caching

%mMD_Cacheable               = &H20???                 ' // Bitmask,whether memory is cacheable
%fMD_NonCacheable            = &H0???                  ' // Memory range is non-cacheable
%fMD_Cacheable               = &H20???                 ' // Memory range is cacheable

%fMD_WINDOW_DECODE           = &H40???                 ' // Memory range is bridge window decode.
%fMD_MEMORY_BAR              = &H80???                 ' // Memory BAR resource.

'//
'// MEM_RANGE Structure
'//
' // Size = 36 bytes
TYPE MEM_RANGE DWORD
   MR_Align    AS QUAD    ' DWORDLONG // specifies mask for base alignment
   MR_nBytes   AS DWORD   ' ULONG // specifies number of bytes required
   MR_Min      AS QUAD    ' DWORDLONG // specifies minimum address of the range
   MR_Max      AS QUAD    ' DWORDLONG // specifies maximum address of the range
   MR_Flags    AS DWORD   ' DWORD // specifies flags describing range (fMD flags)
   MR_Reserved AS DWORD   ' DWORD
END TYPE

'//
'// MEM_DES structure
'//
' // Size = 32 bytes
TYPE MEM_DES DWORD
   MD_Count      AS DWORD   ' DWORD // number of MEM_RANGE structs in MEM_RESOURCE
   MD_Type       AS DWORD   ' DWORD // size (in bytes) of MEM_RANGE (MType_Range)
   MD_Alloc_Base AS QUAD    ' DWORDLONG // base memory address of range allocated
   MD_Alloc_End  AS QUAD    ' DWORDLONG // end of allocated range
   MD_Flags      AS DWORD   ' DWORD // flags describing allocated range (fMD flags)
   MD_Reserved   AS DWORD   ' DWORD
END TYPE

'//
'// MEM_RESOURCE structure
'//
' // Size = 68 bytes
TYPE MEM_RESOURCE DWORD
   MEM_Header  AS MEM_DES     ' MEM_DES // info about memory range list
   MEM_Data(0) AS MEM_RANGE   ' MEM_RANGE - variable-length array // list of memory ranges
END TYPE

'//
'// Define the size of each range structure
'//
'#define MType_Range     sizeof(struct Mem_Range_s)

'//--------------------------------------------------------------
'// Large Memory Resource
'//--------------------------------------------------------------

'//
'// Note that large memory ranges use the same attribute flags as memory ranges.
'//

'//
'// MEM_LARGE_RANGE Structure
'//
' // Size = 40 bytes
TYPE MEM_LARGE_RANGE DWORD
   MLR_Align    AS QUAD    ' DWORDLONG ' // specifies mask for base alignment
   MLR_nBytes   AS QUAD    ' ULONGLONG // specifies number of bytes required
   MLR_Min      AS QUAD    ' DWORDLONG // specifies minimum address of the range
   MLR_Max      AS QUAD    ' DWORDLONG // specifies maximum address of the range
   MLR_Flags    AS DWORD   ' DWORD // specifies flags describing range (fMD flags)
   MLR_Reserved AS DWORD   ' DWORD
END TYPE

'//
'// MEM_LARGE_DES structure
'//
' // Size = 32 bytes
TYPE MEM_LARGE_DES DWORD
   MLD_Count      AS DWORD   ' DWORD // number of LARGE_MEM_RANGE structs in LARGE_MEM_RESOURCE
   MLD_Type       AS DWORD   ' DWORD // size (in bytes) of MEM_RANGE (MType_Range)
   MLD_Alloc_Base AS QUAD    ' DWORDLONG // base memory address of range allocated
   MLD_Alloc_End  AS QUAD    ' DWORDLONG // end of allocated range
   MLD_Flags      AS DWORD   ' DWORD // flags describing allocated range (fMD flags)
   MLD_Reserved   AS DWORD   ' DWORD
END TYPE

'//
'// MEM_LARGE_RESOURCE structure
'//
' // Size = 72 bytes
TYPE MEM_LARGE_RESOURCE DWORD
   MEM_LARGE_Header  AS MEM_LARGE_DES     ' // info about memory range list
   MEM_LARGE_Data(0) AS MEM_LARGE_RANGE   '  // list of memory ranges
END TYPE

'//
'// Define the size of each range structure
'//
'#define MLType_Range     sizeof(struct Mem_Large_Range_s)

'//--------------------------------------------------------------
'// I/O Port Resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for port resources.  Each bit flag is
'// identified by a constant bitmask.  Following the bitmask definition,
'// are the two possible values.
'//
%fIOD_PortType        = &H1???      ' // Bitmask,whether port is IO or memory
%fIOD_Memory          = &H0???      ' // Port resource really uses memory
%fIOD_IO              = &H1???      ' // Port resource uses IO ports
%fIOD_DECODE          = &H00fc???   ' // decode flags
%fIOD_10_BIT_DECODE   = &H0004???
%fIOD_12_BIT_DECODE   = &H0008???
%fIOD_16_BIT_DECODE   = &H0010???
%fIOD_POSITIVE_DECODE = &H0020???
%fIOD_PASSIVE_DECODE  = &H0040???
%fIOD_WINDOW_DECODE   = &H0080???
%fIOD_PORT_BAR        = &H0100???

'//
'// these are for compatiblity
'//
%IO_ALIAS_10_BIT_DECODE   = &H00000004???
%IO_ALIAS_12_BIT_DECODE   = &H00000010???
%IO_ALIAS_16_BIT_DECODE   = &H00000000???
%IO_ALIAS_POSITIVE_DECODE = &H000000FF???

'//
'// IO_RANGE structure
'//
' // Size = 40 bytes
TYPE IO_RANGE DWORD
   IOR_Align      AS QUAD    ' DWORDLONG // mask for base alignment
   IOR_nPorts     AS DWORD   ' DWORD // number of ports
   IOR_Min        AS QUAD    ' DWORDLONG // minimum port address
   IOR_Max        AS QUAD    ' DWORDLONG // maximum port address
   IOR_RangeFlags AS DWORD   ' DWORD // flags for this port range
   IOR_Alias      AS QUAD    ' DWORDLONG // multiplier that generates aliases for port(s)
END TYPE

'//
'// IO_DES structure
'//
' // Size = 28 bytes
TYPE IO_DES DWORD
   IOD_Count      AS DWORD   ' DWORD // number of IO_RANGE structs in IO_RESOURCE
   IOD_Type       AS DWORD   ' DWORD // size (in bytes) of IO_RANGE (IOType_Range)
   IOD_Alloc_Base AS QUAD    ' DWORDLONG // base of allocated port range
   IOD_Alloc_End  AS QUAD    ' DWORDLONG // end of allocated port range
   IOD_DesFlags   AS DWORD   ' DWORD // flags relating to allocated port range
END TYPE

'//
'// IO_RESOURCE
'//
' // Size = 68 bytes
TYPE IO_RESOURCE DWORD
   IO_Header  AS IO_DES     ' IO_DES // info about I/O port range list
   IO_Data(0) AS IO_RANGE   ' IO_RANGE - variable-length array    // list of I/O port ranges
END TYPE

%IOA_Local       = &Hff???

'//
'// Define the size of each range structure
'//
'#define IOType_Range    sizeof(struct IO_Range_s)

'//--------------------------------------------------------------
'// DMA Resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for a DMA resource range.  Each bit flag is
'// identified with a constant bitmask.  Following the bitmask definition
'// are the possible values.
'//
%mDD_Width         = &H3???    ' // Bitmask, width of the DMA channel:
%fDD_BYTE          = &H0???    ' //   8-bit DMA channel
%fDD_WORD          = &H1???    ' //   16-bit DMA channel
%fDD_DWORD         = &H2???    ' //   32-bit DMA channel
%fDD_BYTE_AND_WORD = &H3???    ' //   8-bit and 16-bit DMA channel

%mDD_BusMaster     = &H4???    ' // Bitmask, whether bus mastering is supported
%fDD_NoBusMaster   = &H0???    ' //   no bus mastering
%fDD_BusMaster     = &H4???    ' //   bus mastering

%mDD_Type          = &H18???   ' // Bitmask, specifies type of DMA
%fDD_TypeStandard  = &H00???   ' //   standard DMA
%fDD_TypeA         = &H08???   ' //   Type-A DMA
%fDD_TypeB         = &H10???   ' //   Type-B DMA
%fDD_TypeF         = &H18???   ' //   Type-F DMA

'//
'// DMA_RANGE structure
'//
' // Size = 12 bytes
TYPE DMA_RANGE DWORD
   DR_Min   AS DWORD   ' ULONG // minimum DMA port in the range
   DR_Max   AS DWORD   ' ULONG // maximum DMA port in the range
   DR_Flags AS DWORD   ' ULONG // flags describing the range (fDD flags)
END TYPE

'//
'// DMA_DES structure
'//
' // Size = 16 bytes
TYPE DMA_DES DWORD
   DD_Count      AS DWORD   ' DWORD // number of DMA_RANGE structs in DMA_RESOURCE
   DD_Type       AS DWORD   ' DWORD // size (in bytes) of DMA_RANGE struct (DType_Range)
   DD_Flags      AS DWORD   ' DWORD // Flags describing DMA channel (fDD flags)
   DD_Alloc_Chan AS DWORD   ' ULONG // Specifies the DMA channel that was allocated
END TYPE

'//
'// DMA_RESOURCE
'//
' // Size = 28 bytes
TYPE DMA_RESOURCE DWORD
   DMA_Header  AS DMA_DES     ' DMA_DES // info about DMA channel range list
   DMA_Data(0) AS DMA_RANGE   ' DMA_RANGE variable-length array// list of DMA ranges
END TYPE

'//
'// Define the size of each range structure
'//
'#define DType_Range     sizeof(struct DMA_Range_s)

'//--------------------------------------------------------------
'// Interrupt Resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for an interrupt resource range.  Each bit flag
'// is identified with a constant bitmask.  Following the bitmask definition
'// are the possible values.
'//
%mIRQD_Share        = &H1???  ' // Bitmask,whether the IRQ may be shared:
%fIRQD_Exclusive    = &H0???  ' //   The IRQ may not be shared
%fIRQD_Share        = &H1???  ' //   The IRQ may be shared

%fIRQD_Share_Bit    = 0      ' // compatibility
%fIRQD_Level_Bit    = 1      ' // compatibility

' ' //
' ' // ** NOTE: 16-bit ConfigMgr uses fIRQD_Level_Bit being set to indicate that the
' ' // ** interrupt is _level-sensitive_.  For 32-bit ConfigMgr, if this bit is set,
' ' // ** then the interrupt is _edge-sensitive_.
' ' //
%mIRQD_Edge_Level   = &H2???  ' // Bitmask,whether edge or level triggered:
%fIRQD_Level        = &H0???  ' //   The IRQ is level-sensitive
%fIRQD_Edge         = &H2???  ' //   The IRQ is edge-sensitive

'//
'// IRQ_RANGE
'//
' // Size = 12 bytes
TYPE IRQ_RANGE DWORD FILL
   IRQR_Min   AS DWORD   ' ULONG // minimum IRQ in the range
   IRQR_Max   AS DWORD   ' ULONG // maximum IRQ in the range
#IF %DEF(%NT_PROCESSOR_GROUPS)
   IRQR_Flags AS WORD    ' USHORT // flags describing the range (fIRQD flags)
   IRQR_Rsvdz AS WORD    ' USHORT // Reserved, must be zero.
#ELSE
   IRQR_Flags AS DWORD   ' ULONG // flags describing the range (fIRQD flags)
#ENDIF
END TYPE

'//
'// IRQ_DES structure
'//
' // Size = 20 bytes
TYPE IRQ_DES_32 DWORD FILL
   IRQD_Count     AS DWORD   ' DWORD // number of IRQ_RANGE structs in IRQ_RESOURCE
   IRQD_Type      AS DWORD   ' DWORD // size (in bytes) of IRQ_RANGE (IRQType_Range)
#IF %DEF(%NT_PROCESSOR_GROUPS)
   IRQD_Flags     AS WORD    ' USHORT // flags describing the range (fIRQD flags)
   IRQD_Group     AS WORD    ' USHORT // Reserved, must be zero.
#ELSE
   IRQD_Flags     AS DWORD   ' DWORD // flags describing the IRQ (fIRQD flags)
#ENDIF
   IRQD_Alloc_Num AS DWORD   ' ULONG // specifies the IRQ that was allocated
   IRQD_Affinity  AS DWORD   ' ULONG32
END TYPE

' // Size = 24 bytes
TYPE IRQ_DES_64 DWORD FILL
   IRQD_Count     AS DWORD   ' DWORD // number of IRQ_RANGE structs in IRQ_RESOURCE
   IRQD_Type      AS DWORD   ' DWORD // size (in bytes) of IRQ_RANGE (IRQType_Range)
#IF %DEF(%NT_PROCESSOR_GROUPS)
   IRQD_Flags     AS WORD    ' USHORT // flags describing the range (fIRQD flags)
   IRQD_Group     AS WORD    ' USHORT // Reserved, must be zero.
#ELSE
   IRQD_Flags     AS DWORD   ' DWORD // flags describing the IRQ (fIRQD flags)
#ENDIF
   IRQD_Alloc_Num AS DWORD   ' ULONG // specifies the IRQ that was allocated
   IRQD_Affinity  AS QUAD    ' ULONG64
END TYPE

'#ifdef _WIN64
'typedef IRQ_DES_64   IRQ_DES;
'typedef PIRQ_DES_64  PIRQ_DES;
'#else
'typedef IRQ_DES_32   IRQ_DES;
'typedef PIRQ_DES_32  PIRQ_DES;
'#endif

MACRO IRQ_DES = IRQ_DES_32

'//
'// IRQ_RESOURCE structure
'//
' // Size = 32 bytes
TYPE IRQ_RESOURCE_32 DWORD FILL
   IRQ_Header  AS IRQ_DES_32   ' IRQ_DES_32 // info about IRQ range list
   IRQ_Data(0) AS IRQ_RANGE    ' IRQ_RANGE variable-length array // list of IRQ ranges
END TYPE

' // Size = 36 bytes
TYPE IRQ_RESOURCE_64 DWORD FILL
   IRQ_Header  AS IRQ_DES_64   ' IRQ_DES_64 // info about IRQ range list
   IRQ_Data(0) AS IRQ_RANGE    ' IRQ_RANGE variable-length array // list of IRQ ranges
END TYPE

'#ifdef _WIN64
'typedef IRQ_RESOURCE_64  IRQ_RESOURCE;
'typedef PIRQ_RESOURCE_64 PIRQ_RESOURCE;
'#else
'typedef IRQ_RESOURCE_32  IRQ_RESOURCE;
'typedef PIRQ_RESOURCE_32 PIRQ_RESOURCE;
'#endif

MACRO IRQ_RESOURCE = IRQ_RESOURCE_32

'//
'// Define the size of each range structure
'//
'#define IRQType_Range   sizeof(struct IRQ_Range_s)

'#if (WINVER >= _WIN32_WINNT_WINXP)
'//
'// Flags for resource descriptor APIs indicating the width of certain
'// variable-size resource descriptor structure fields, where applicable.
'//
%CM_RESDES_WIDTH_DEFAULT = &H00000000???   ' // 32 or 64-bit IRQ_RESOURCE / IRQ_DES, based on client
%CM_RESDES_WIDTH_32      = &H00000001???   ' // 32-bit IRQ_RESOURCE / IRQ_DES
%CM_RESDES_WIDTH_64      = &H00000002???   ' // 64-bit IRQ_RESOURCE / IRQ_DES
%CM_RESDES_WIDTH_BITS    = &H00000003???
'#endif // (WINVER >= _WIN32_WINNT_WINXP)

'//--------------------------------------------------------------
'// Device Private Resource
'//--------------------------------------------------------------

'//
'// DEVICEPRIVATE_RANGE structure
'//

' // Size = 12 bytes
TYPE DEVPRIVATE_RANGE DWORD
   PR_Data1 AS DWORD   ' DWORD // mask for base alignment
   PR_Data2 AS DWORD   ' DWORD // number of bytes
   PR_Data3 AS DWORD   ' DWORD // minimum address
END TYPE

'//
'// DEVPRIVATE_DES structure
'//
' // Size = 24 bytes
TYPE DEVPRIVATE_DES DWORD
   PD_Count AS DWORD
   PD_Type  AS DWORD
   PD_Data1 AS DWORD
   PD_Data2 AS DWORD
   PD_Data3 AS DWORD
   PD_Flags AS DWORD
END TYPE

'//
'// DEVPRIVATE_RESOURCE
'//
' // Size = 36 bytes
TYPE DEVPRIVATE_RESOURCE DWORD
   PRV_Header  AS DEVPRIVATE_DES
   PRV_Data(0) AS DEVPRIVATE_RANGE
END TYPE

'//
'// Define the size of each range structure
'//
'#define PType_Range    sizeof(struct DevPrivate_Range_s)

'//--------------------------------------------------------------
'// Class-Specific Resource
'//--------------------------------------------------------------

' // Size = 33 bytes
TYPE CS_DES BYTE
   CSD_SignatureLength  AS DWORD
   CSD_LegacyDataOffset AS DWORD
   CSD_LegacyDataSize   AS DWORD
   CSD_Flags            AS DWORD
   CSD_ClassGuid        AS GUID
   CSD_Signature(0)     AS BYTE    ' BYTE - variable-length array
END TYPE

' // Size = 33 bytes
TYPE CS_RESOURCE BYTE
   CS_Header AS CS_DES
END TYPE

'//--------------------------------------------------------------
'// PC Card Configuration Resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for a PC Card configuration resource descriptor.
'// Each bit flag is identified with a constant bitmask.  Following the bitmask
'// definition are the possible values.
'//
%mPCD_IO_8_16        = &H1???    ' // Bitmask, whether I/O is 8 or 16 bits
%fPCD_IO_8           = &H0???    ' // I/O is 8-bit
%fPCD_IO_16          = &H1???    ' // I/O is 16-bit
%mPCD_MEM_8_16       = &H2???    ' // Bitmask, whether MEM is 8 or 16 bits
%fPCD_MEM_8          = &H0???    ' // MEM is 8-bit
%fPCD_MEM_16         = &H2???    ' // MEM is 16-bit
%mPCD_MEM_A_C        = &HC???    ' // Bitmask, whether MEMx is Attribute or Common
%fPCD_MEM1_A         = &H4???    ' // MEM1 is Attribute
%fPCD_MEM2_A         = &H8???    ' // MEM2 is Attribute
%fPCD_IO_ZW_8        = &H10???   ' // zero wait on 8 bit I/O
%fPCD_IO_SRC_16      = &H20???   ' // iosrc 16
%fPCD_IO_WS_16       = &H40???   ' // wait states on 16 bit io
%mPCD_MEM_WS         = &H300???  ' // Bitmask, for additional wait states on memory windows
%fPCD_MEM_WS_ONE     = &H100???  ' // 1 wait state
%fPCD_MEM_WS_TWO     = &H200???  ' // 2 wait states
%fPCD_MEM_WS_THREE   = &H300???  ' // 3 wait states

'#if (WINVER >= _WIN32_WINNT_WINXP)
%fPCD_MEM_A          = &H4???    ' // MEM is Attribute

%fPCD_ATTRIBUTES_PER_WINDOW = &H8000???

%fPCD_IO1_16         = &H00010000???   ' // I/O window 1 is 16-bit
%fPCD_IO1_ZW_8       = &H00020000???   ' // I/O window 1 zero wait on 8 bit I/O
%fPCD_IO1_SRC_16     = &H00040000???   ' // I/O window 1 iosrc 16
%fPCD_IO1_WS_16      = &H00080000???   ' // I/O window 1 wait states on 16 bit io

%fPCD_IO2_16         = &H00100000???   ' // I/O window 2 is 16-bit
%fPCD_IO2_ZW_8       = &H00200000???   ' // I/O window 2 zero wait on 8 bit I/O
%fPCD_IO2_SRC_16     = &H00400000???   ' // I/O window 2 iosrc 16
%fPCD_IO2_WS_16      = &H00800000???   ' // I/O window 2 wait states on 16 bit io

%mPCD_MEM1_WS        = &H03000000???   ' // MEM window 1 Bitmask, for additional wait states on memory windows
%fPCD_MEM1_WS_ONE    = &H01000000???   ' // MEM window 1, 1 wait state
%fPCD_MEM1_WS_TWO    = &H02000000???   ' // MEM window 1, 2 wait states
%fPCD_MEM1_WS_THREE  = &H03000000???   ' // MEM window 1, 3 wait states
%fPCD_MEM1_16        = &H04000000???   ' // MEM window 1 is 16-bit

%mPCD_MEM2_WS        = &H30000000???   ' // MEM window 2 Bitmask, for additional wait states on memory windows
%fPCD_MEM2_WS_ONE    = &H10000000???   ' // MEM window 2, 1 wait state
%fPCD_MEM2_WS_TWO    = &H20000000???   ' // MEM window 2, 2 wait states
%fPCD_MEM2_WS_THREE  = &H30000000???   ' // MEM window 2, 3 wait states
%fPCD_MEM2_16        = &H40000000???   ' // MEM window 2 is 16-bit

%PCD_MAX_MEMORY   = 2
%PCD_MAX_IO       = 2
'#endif // (WINVER >= _WIN32_WINNT_WINXP)

' // Size = 38 bytes
TYPE PCCARD_DES BYTE
   PCD_Count                               AS DWORD   ' DWORD
   PCD_Type                                AS DWORD   ' DWORD
   PCD_Flags                               AS DWORD   ' DWORD
   PCD_ConfigIndex                         AS BYTE    ' BYTE
   PCD_Reserved(2)                         AS BYTE    ' BYTE[3]
   PCD_MemoryCardBase1                     AS DWORD   ' DWORD
   PCD_MemoryCardBase2                     AS DWORD   ' DWORD
'#if (WINVER >= _WIN32_WINNT_WINXP)
   PCD_MemoryCardBase(%PCD_MAX_MEMORY - 1) AS DWORD   ' DWORD ' // will soon be removed
   PCD_MemoryFlags(%PCD_MAX_MEMORY - 1)    AS WORD    ' WORD ' // will soon be removed
   PCD_IoFlags(%PCD_MAX_IO - 1)            AS BYTE    ' BYTE ' // will soon be removed
'#endif // (WINVER >= _WIN32_WINNT_WINXP)
END TYPE

' // Size = 38 bytes
TYPE PCCARD_RESOURCE BYTE
   PcCard_Header AS PCCARD_DES
END TYPE

'//--------------------------------------------------------------
'// MF (multifunction) PCCard Configuration Resource
'//--------------------------------------------------------------

%mPMF_AUDIO_ENABLE = &H8   ' // Bitmask, whether audio is enabled or not
%fPMF_AUDIO_ENABLE = &H8   ' // Audio is enabled

' // Size = 20 bytes
TYPE MFCARD_DES BYTE
   PMF_Count              AS DWORD   ' DWORD
   PMF_Type               AS DWORD   ' DWORD
   PMF_Flags              AS DWORD   ' DWORD
   PMF_ConfigOptions      AS BYTE    ' BYTE
   PMF_IoResourceIndex    AS BYTE    ' BYTE
   PMF_Reserved(1)        AS BYTE    ' BYTE[2]
   PMF_ConfigRegisterBase AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE MFCARD_RESOURCE BYTE
   MfCard_Header AS MFCARD_DES
END TYPE

'//--------------------------------------------------------------
'// Bus Number Resource
'//--------------------------------------------------------------

'//
'// Define the attribute flags for a Bus Number resource descriptor.
'// Each bit flag is identified with a constant bitmask.  Following the bitmask
'// definition are the possible values.
'//
'// Currently unused.
'//

'//
'// BUSNUMBER_RANGE
'//
' // Size = 16 bytes
TYPE BUSNUMBER_RANGE DWORD
   BUSR_Min         AS DWORD   ' ULONG // minimum Bus Number in the range
   BUSR_Max         AS DWORD   ' ULONG // maximum Bus Number in the range
   BUSR_nBusNumbers AS DWORD   ' ULONG // specifies number of buses required
   BUSR_Flags       AS DWORD   ' ULONG // flags describing the range (currently unused)
END TYPE

'//
'// BUSNUMBER_DES structure
'//
' // Size = 20 bytes
TYPE BUSNUMBER_DES DWORD
   BUSD_Count      AS DWORD   ' DWORD // number of BUSNUMBER_RANGE structs in BUSNUMBER_RESOURCE
   BUSD_Type       AS DWORD   ' DWORD // size (in bytes) of BUSNUMBER_RANGE (BusNumberType_Range)
   BUSD_Flags      AS DWORD   ' DWORD // flags describing the range (currently unused)
   BUSD_Alloc_Base AS DWORD   ' ULONG // specifies the first Bus that was allocated
   BUSD_Alloc_End  AS DWORD   ' ULONG // specifies the last Bus number that was allocated
END TYPE

'//
'// BUSNUMBER_RESOURCE structure
'//
' // Size = 36 bytes
TYPE BUSNUMBER_RESOURCE DWORD
   BusNumber_Header  AS BUSNUMBER_DES     ' BUSNUMBER_DES // info about Bus Number range list
   BusNumber_Data(0) AS BUSNUMBER_RANGE   ' BUSNUMBER_RANGE - variable-length array  // list of Bus Number ranges
END TYPE

'//
'// Define the size of each range structure
'//
'#define BusNumberType_Range   sizeof(struct BusNumber_Range_s)

'//--------------------------------------------------------------
'// Hardware Profile Information
'//--------------------------------------------------------------

'//
'// Define flags relating to hardware profiles
'//
%CM_HWPI_NOT_DOCKABLE  = &H00000000???   ' // machine is not dockable
%CM_HWPI_UNDOCKED      = &H00000001???   ' // hw profile for docked config
%CM_HWPI_DOCKED        = &H00000002???   ' // hw profile for undocked config

'//
'// HWPROFILEINFO structure
'//
' // Size = 88 bytes
TYPE HWPROFILEINFO_A DWORD
   HWPI_ulHWProfile    AS DWORD                       ' ULONG // handle of hw profile
   HWPI_szFriendlyName AS ASCIIZ * %MAX_PROFILE_LEN   ' CHAR // friendly name of hw profile
   HWPI_dwFlags        AS DWORD                       ' DWORD // profile flags (CM_HWPI_*)
END TYPE

' // Size = 88 bytes
TYPE HWPROFILEINFO_W DWORD
   HWPI_ulHWProfile    AS DWORD                           ' ULONG // handle of hw profile
   HWPI_szFriendlyName AS WSTRINGZ * %MAX_PROFILE_LEN     ' WCHAR // friendly name of hw profile
   HWPI_dwFlags        AS DWORD                           ' DWORD // profile flags (CM_HWPI_*)
END TYPE

#IF %DEF(%UNICODE)
MACRO HWPROFILEINFO = HWPROFILEINFO_W
#ELSE
MACRO HWPROFILEINFO = HWPROFILEINFO_A
#ENDIF

'//
'// revert back to normal default packing
'//
'#include "poppack.h"

'//--------------------------------------------------------------
'// Miscellaneous
'//--------------------------------------------------------------

'//
'// Resource types
'//
%ResType_All           = &H00000000???   ' // Return all resource types
%ResType_None          = &H00000000???   ' // Arbitration always succeeded
%ResType_Mem           = &H00000001???   ' // Physical address resource
%ResType_IO            = &H00000002???   ' // Physical I/O address resource
%ResType_DMA           = &H00000003???   ' // DMA channels resource
%ResType_IRQ           = &H00000004???   ' // IRQ resource
%ResType_DoNotUse      = &H00000005???   ' // Used as spacer to sync subsequent ResTypes w/NT
%ResType_BusNumber     = &H00000006???   ' // bus number resource
%ResType_MemLarge      = &H00000007???   ' // Memory resources >= 4GB
%ResType_MAX           = &H00000007???   ' // Maximum known (arbitrated??? ResType

%ResType_Ignored_Bit   = &H00008000???   ' // Ignore this resource
%ResType_ClassSpecific = &H0000FFFF???   ' // class-specific resource
%ResType_Reserved      = &H00008000???   ' // reserved for internal use
%ResType_DevicePrivate = &H00008001???   ' // device private data
%ResType_PcCardConfig  = &H00008002???   ' // PC Card configuration data
%ResType_MfCardConfig  = &H00008003???   ' // MF Card configuration data

'//
'// Flags specifying options for ranges that conflict with ranges already in
'// the range list (CM_Add_Range???
'//
%CM_ADD_RANGE_ADDIFCONFLICT        = &H00000000??? ' // merg with conflicting range
%CM_ADD_RANGE_DONOTADDIFCONFLICT   = &H00000001??? ' // error if range conflicts
%CM_ADD_RANGE_BITS                 = &H00000001???

'//
'// Logical Config Flags (specified in call to CM_Get_First_Log_Conf
'//
%BASIC_LOG_CONF    = &H00000000???  ' // Specifies the req list.
%FILTERED_LOG_CONF = &H00000001???  ' // Specifies the filtered req list.
%ALLOC_LOG_CONF    = &H00000002???  ' // Specifies the Alloc Element.
%BOOT_LOG_CONF     = &H00000003???  ' // Specifies the RM Alloc Element.
%FORCED_LOG_CONF   = &H00000004???  ' // Specifies the Forced Log Conf
%OVERRIDE_LOG_CONF = &H00000005???  ' // Specifies the Override req list.
%NUM_LOG_CONF      = &H00000006???  ' // Number of Log Conf type
%LOG_CONF_BITS     = &H00000007???  ' // The bits of the log conf type.

%PRIORITY_EQUAL_FIRST  = &H00000008??? ' // Same priority, new one first
%PRIORITY_EQUAL_LAST   = &H00000000??? ' // Same priority, new one last
%PRIORITY_BIT          = &H00000008???

'//
'// Registry disposition values
'// (specified in call to CM_Open_DevNode_Key and CM_Open_Class_Key???
'//
%RegDisposition_OpenAlways   = &H00000000???   ' // open if exists else create
%RegDisposition_OpenExisting = &H00000001???   ' // open key only if exists
%RegDisposition_Bits         = &H00000001???

'//
'// ulFlags values for CM API routines
'//

'//
'// Flags for CM_Add_ID
'//
%CM_ADD_ID_HARDWARE                = &H00000000???
%CM_ADD_ID_COMPATIBLE              = &H00000001???
%CM_ADD_ID_BITS                    = &H00000001???

'//
'// Device Node creation flags
'//
%CM_CREATE_DEVNODE_NORMAL          = &H00000000???   ' // install later
%CM_CREATE_DEVNODE_NO_WAIT_INSTALL = &H00000001???   ' // NOT SUPPORTED ON NT
%CM_CREATE_DEVNODE_PHANTOM         = &H00000002???
%CM_CREATE_DEVNODE_GENERATE_ID     = &H00000004???
%CM_CREATE_DEVNODE_DO_NOT_INSTALL  = &H00000008???
%CM_CREATE_DEVNODE_BITS            = &H0000000F???

%CM_CREATE_DEVINST_NORMAL          = %CM_CREATE_DEVNODE_NORMAL
%CM_CREATE_DEVINST_NO_WAIT_INSTALL = %CM_CREATE_DEVNODE_NO_WAIT_INSTALL
%CM_CREATE_DEVINST_PHANTOM         = %CM_CREATE_DEVNODE_PHANTOM
%CM_CREATE_DEVINST_GENERATE_ID     = %CM_CREATE_DEVNODE_GENERATE_ID
%CM_CREATE_DEVINST_DO_NOT_INSTALL  = %CM_CREATE_DEVNODE_DO_NOT_INSTALL
%CM_CREATE_DEVINST_BITS            = %CM_CREATE_DEVNODE_BITS

'//
'// Flags for CM_Delete_Class_Key
'//
%CM_DELETE_CLASS_ONLY        = &H00000000???
%CM_DELETE_CLASS_SUBKEYS     = &H00000001???

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
%CM_DELETE_CLASS_INTERFACE   = &H00000002???
'#endif ' // (WINVER >= _WIN32_WINNT_LONGHORN)

%CM_DELETE_CLASS_BITS        = &H00000003???

'//
'// Detection reason flags (specified in call to CM_Run_Detection???
'//
%CM_DETECT_NEW_PROFILE       = &H00000001??? ' // detection for new hw profile
%CM_DETECT_CRASHED           = &H00000002??? ' // Previous detection crashed
%CM_DETECT_HWPROF_FIRST_BOOT = &H00000004???
%CM_DETECT_RUN               = &H80000000???
%CM_DETECT_BITS              = &H80000007???

%CM_DISABLE_POLITE           = &H00000000???    ' // Ask the driver
%CM_DISABLE_ABSOLUTE         = &H00000001???    ' // Don't ask the driver
%CM_DISABLE_HARDWARE         = &H00000002???    ' // Don't ask the driver, and won't be restarteable
%CM_DISABLE_UI_NOT_OK        = &H00000004???    ' // Don't popup any veto API
%CM_DISABLE_BITS             = &H00000007???    ' // The bits for the disable function

'//
'// Flags for CM_Get_Device_ID_List, CM_Get_Device_ID_List_Size
'//
%CM_GETIDLIST_FILTER_NONE                = &H00000000???
%CM_GETIDLIST_FILTER_ENUMERATOR          = &H00000001???
%CM_GETIDLIST_FILTER_SERVICE             = &H00000002???
%CM_GETIDLIST_FILTER_EJECTRELATIONS      = &H00000004???
%CM_GETIDLIST_FILTER_REMOVALRELATIONS    = &H00000008???
%CM_GETIDLIST_FILTER_POWERRELATIONS      = &H00000010???
%CM_GETIDLIST_FILTER_BUSRELATIONS        = &H00000020???
%CM_GETIDLIST_DONOTGENERATE              = &H10000040???
'#if (WINVER <= _WIN32_WINNT_LONGHORN)
#IF %WINVER <= &H0600
%CM_GETIDLIST_FILTER_BITS                = &H1000007F???
#ENDIF
'#endif // (WINVER <= _WIN32_WINNT_LONGHORN)
'#if (WINVER >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0600
%CM_GETIDLIST_FILTER_TRANSPORTRELATIONS  = &H00000080???
%CM_GETIDLIST_FILTER_PRESENT             = &H00000100???
%CM_GETIDLIST_FILTER_CLASS               = &H00000200???
%CM_GETIDLIST_FILTER_BITS                = &H100003FF???
#ENDIF ' // (WINVER >= _WIN32_WINNT_WIN7)

'//
'// Flags for CM_Get_Device_Interface_List, CM_Get_Device_Interface_List_Size
'//
%CM_GET_DEVICE_INTERFACE_LIST_PRESENT     = &H00000000???  ' // only currently 'live' device interfaces
%CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES = &H00000001???  ' // all registered device interfaces, live or not
%CM_GET_DEVICE_INTERFACE_LIST_BITS        = &H00000001???

'//
'// Registry properties (specified in call to CM_Get_DevInst_Registry_Property or CM_Get_Class_Registry_Property,
'// some are allowed in calls to CM_Set_DevInst_Registry_Property and CM_Set_Class_Registry_Property???
'// CM_DRP_xxxx values should be used for CM_Get_DevInst_Registry_Property / CM_Set_DevInst_Registry_Property
'// CM_CRP_xxxx values should be used for CM_Get_Class_Registry_Property / CM_Set_Class_Registry_Property
'// DRP/CRP values that overlap must have a 1:1 correspondence with each other
'//
%CM_DRP_DEVICEDESC                  = &H00000001??? ' // DeviceDesc REG_SZ property (RW???
%CM_DRP_HARDWAREID                  = &H00000002??? ' // HardwareID REG_MULTI_SZ property (RW???
%CM_DRP_COMPATIBLEIDS               = &H00000003??? ' // CompatibleIDs REG_MULTI_SZ property (RW???
%CM_DRP_UNUSED0                     = &H00000004??? ' // unused
%CM_DRP_SERVICE                     = &H00000005??? ' // Service REG_SZ property (RW???
%CM_DRP_UNUSED1                     = &H00000006??? ' // unused
%CM_DRP_UNUSED2                     = &H00000007??? ' // unused
%CM_DRP_CLASS                       = &H00000008??? ' // Class REG_SZ property (RW???
%CM_DRP_CLASSGUID                   = &H00000009??? ' // ClassGUID REG_SZ property (RW???
%CM_DRP_DRIVER                      = &H0000000A??? ' // Driver REG_SZ property (RW???
%CM_DRP_CONFIGFLAGS                 = &H0000000B??? ' // ConfigFlags REG_DWORD property (RW???
%CM_DRP_MFG                         = &H0000000C??? ' // Mfg REG_SZ property (RW???
%CM_DRP_FRIENDLYNAME                = &H0000000D??? ' // FriendlyName REG_SZ property (RW???
%CM_DRP_LOCATION_INFORMATION        = &H0000000E??? ' // LocationInformation REG_SZ property (RW???
%CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME = &H0000000F??? ' // PhysicalDeviceObjectName REG_SZ property (R???
%CM_DRP_CAPABILITIES                = &H00000010??? ' // Capabilities REG_DWORD property (R???
%CM_DRP_UI_NUMBER                   = &H00000011??? ' // UiNumber REG_DWORD property (R???
%CM_DRP_UPPERFILTERS                = &H00000012??? ' // UpperFilters REG_MULTI_SZ property (RW???

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
'%CM_CRP_UPPERFILTERS                CM_DRP_UPPERFILTERS ' // UpperFilters REG_MULTI_SZ property (RW???
'#endif ' // (WINVER >= _WIN32_WINNT_LONGHORN)

%CM_DRP_LOWERFILTERS                = &H00000013??? ' // LowerFilters REG_MULTI_SZ property (RW???

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
%CM_CRP_LOWERFILTERS                = %CM_DRP_LOWERFILTERS ' // LowerFilters REG_MULTI_SZ property (RW???
'#endif ' // (WINVER >= _WIN32_WINNT_LONGHORN)

%CM_DRP_BUSTYPEGUID                 = &H00000014??? ' // Bus Type Guid, GUID, (R???
%CM_DRP_LEGACYBUSTYPE               = &H00000015??? ' // Legacy bus type, INTERFACE_TYPE, (R???
%CM_DRP_BUSNUMBER                   = &H00000016??? ' // Bus Number, DWORD, (R???
%CM_DRP_ENUMERATOR_NAME             = &H00000017??? ' // Enumerator Name REG_SZ property (R???
%CM_DRP_SECURITY                    = &H00000018??? ' // Security - Device override (RW???
%CM_CRP_SECURITY                    = %CM_DRP_SECURITY   ' // Class default security (RW???
%CM_DRP_SECURITY_SDS                = &H00000019??? ' // Security - Device override (RW???
%CM_CRP_SECURITY_SDS                = %CM_DRP_SECURITY_SDS ' // Class default security (RW???
%CM_DRP_DEVTYPE                     = &H0000001A??? ' // Device Type - Device override (RW???
%CM_CRP_DEVTYPE                     = %CM_DRP_DEVTYPE    ' // Class default Device-type (RW???
%CM_DRP_EXCLUSIVE                   = &H0000001B??? ' // Exclusivity - Device override (RW???
%CM_CRP_EXCLUSIVE                   = %CM_DRP_EXCLUSIVE  ' // Class default (RW???
%CM_DRP_CHARACTERISTICS             = &H0000001C??? ' // Characteristics - Device Override (RW???
%CM_CRP_CHARACTERISTICS             = %CM_DRP_CHARACTERISTICS  ' // Class default (RW???
%CM_DRP_ADDRESS                     = &H0000001D??? ' // Device Address (R???
%CM_DRP_UI_NUMBER_DESC_FORMAT       = &H0000001E??? ' // UINumberDescFormat REG_SZ property (RW???

'#if (WINVER >= _WIN32_WINNT_WINXP)
%CM_DRP_DEVICE_POWER_DATA           = &H0000001F??? ' // CM_POWER_DATA REG_BINARY property (R???
%CM_DRP_REMOVAL_POLICY              = &H00000020??? ' // CM_DEVICE_REMOVAL_POLICY REG_DWORD (R???
%CM_DRP_REMOVAL_POLICY_HW_DEFAULT   = &H00000021??? ' // CM_DRP_REMOVAL_POLICY_HW_DEFAULT REG_DWORD (R???
%CM_DRP_REMOVAL_POLICY_OVERRIDE     = &H00000022??? ' // CM_DRP_REMOVAL_POLICY_OVERRIDE REG_DWORD (RW???
%CM_DRP_INSTALL_STATE               = &H00000023??? ' // CM_DRP_INSTALL_STATE REG_DWORD (R???
'#endif ' // (WINVER >= _WIN32_WINNT_WINXP)

'#if (WINVER >= _WIN32_WINNT_WS03)
%CM_DRP_LOCATION_PATHS              = &H00000024??? ' // CM_DRP_LOCATION_PATHS REG_MULTI_SZ (R???
'#endif ' // (WINVER >= _WIN32_WINNT_WS03)

'#if (WINVER >= _WIN32_WINNT_WIN7)
%CM_DRP_BASE_CONTAINERID            = &H00000025??? ' // Base ContainerID REG_SZ property (R)
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

%CM_DRP_MIN                         = &H00000001??? ' // First device register
%CM_CRP_MIN                         = %CM_DRP_MIN   ' // First class register
%CM_DRP_MAX                         = &H00000025??? ' // Last device register
%CM_CRP_MAX                         = %CM_DRP_MAX   ' // Last class register

'//
'// Capabilities bits (the capability value is returned from calling
'// CM_Get_DevInst_Registry_Property with CM_DRP_CAPABILITIES property???
'//
%CM_DEVCAP_LOCKSUPPORTED     = &H00000001???
%CM_DEVCAP_EJECTSUPPORTED    = &H00000002???
%CM_DEVCAP_REMOVABLE         = &H00000004???
%CM_DEVCAP_DOCKDEVICE        = &H00000008???
%CM_DEVCAP_UNIQUEID          = &H00000010???
%CM_DEVCAP_SILENTINSTALL     = &H00000020???
%CM_DEVCAP_RAWDEVICEOK       = &H00000040???
%CM_DEVCAP_SURPRISEREMOVALOK = &H00000080???
%CM_DEVCAP_HARDWAREDISABLED  = &H00000100???
%CM_DEVCAP_NONDYNAMIC        = &H00000200???

'#if (WINVER >= _WIN32_WINNT_WINXP)
'//
'// Removal policies (retrievable via CM_Get_DevInst_Registry_Property with
'// the CM_DRP_REMOVAL_POLICY, CM_DRP_REMOVAL_POLICY_OVERRIDE, or
'// CM_DRP_REMOVAL_POLICY_HW_DEFAULT properties???
'//
%CM_REMOVAL_POLICY_EXPECT_NO_REMOVAL            = 1
%CM_REMOVAL_POLICY_EXPECT_ORDERLY_REMOVAL       = 2
%CM_REMOVAL_POLICY_EXPECT_SURPRISE_REMOVAL      = 3

'//
'// Device install states (retrievable via CM_Get_DevInst_Registry_Property with
'// the CM_DRP_INSTALL_STATE properties???
'//
%CM_INSTALL_STATE_INSTALLED                     = 0
%CM_INSTALL_STATE_NEEDS_REINSTALL               = 1
%CM_INSTALL_STATE_FAILED_INSTALL                = 2
%CM_INSTALL_STATE_FINISH_INSTALL                = 3
'#endif ' // (WINVER >= _WIN32_WINNT_WINXP)

'//
'// Flags for CM_Locate_DevNode
'//
%CM_LOCATE_DEVNODE_NORMAL       = &H00000000???
%CM_LOCATE_DEVNODE_PHANTOM      = &H00000001???
%CM_LOCATE_DEVNODE_CANCELREMOVE = &H00000002???
%CM_LOCATE_DEVNODE_NOVALIDATION = &H00000004???
%CM_LOCATE_DEVNODE_BITS         = &H00000007???

%CM_LOCATE_DEVINST_NORMAL       = %CM_LOCATE_DEVNODE_NORMAL
%CM_LOCATE_DEVINST_PHANTOM      = %CM_LOCATE_DEVNODE_PHANTOM
%CM_LOCATE_DEVINST_CANCELREMOVE = %CM_LOCATE_DEVNODE_CANCELREMOVE
%CM_LOCATE_DEVINST_NOVALIDATION = %CM_LOCATE_DEVNODE_NOVALIDATION
%CM_LOCATE_DEVINST_BITS         = %CM_LOCATE_DEVNODE_BITS

'//
'// Flags for CM_Open_Class_Key
'//
%CM_OPEN_CLASS_KEY_INSTALLER        = &H00000000???
%CM_OPEN_CLASS_KEY_INTERFACE        = &H00000001???
%CM_OPEN_CLASS_KEY_BITS             = &H00000001???

'//
'// Flags for CM_Query_And_Remove_SubTree
'//
%CM_REMOVE_UI_OK             = &H00000000???
%CM_REMOVE_UI_NOT_OK         = &H00000001???
%CM_REMOVE_NO_RESTART        = &H00000002???
%CM_REMOVE_BITS              = &H00000003???

'//
'// Backward compatibility--do not use
'// (use above CM_REMOVE_* flags instead)
'//
%CM_QUERY_REMOVE_UI_OK       = %CM_REMOVE_UI_OK
%CM_QUERY_REMOVE_UI_NOT_OK   = %CM_REMOVE_UI_NOT_OK
%CM_QUERY_REMOVE_BITS        = %CM_QUERY_REMOVE_UI_OK OR %CM_QUERY_REMOVE_UI_NOT_OK

'//
'// Flags for CM_Reenumerate_DevNode
'//
%CM_REENUMERATE_NORMAL                   = &H00000000???
%CM_REENUMERATE_SYNCHRONOUS              = &H00000001???

'#if (WINVER >= _WIN32_WINNT_WINXP)
%CM_REENUMERATE_RETRY_INSTALLATION       = &H00000002???
%CM_REENUMERATE_ASYNCHRONOUS             = &H00000004???
'#endif ' // (WINVER >= _WIN32_WINNT_WINXP)

%CM_REENUMERATE_BITS                     = &H00000007???

'//
'// Flags for CM_Register_Device_Driver
'//
%CM_REGISTER_DEVICE_DRIVER_STATIC        = &H00000000???
%CM_REGISTER_DEVICE_DRIVER_DISABLEABLE   = &H00000001???
%CM_REGISTER_DEVICE_DRIVER_REMOVABLE     = &H00000002???
%CM_REGISTER_DEVICE_DRIVER_BITS          = &H00000003???

'//
'// Registry Branch Locations (for CM_Open_DevNode_Key???
'//
%CM_REGISTRY_HARDWARE        = &H00000000???
%CM_REGISTRY_SOFTWARE        = &H00000001???
%CM_REGISTRY_USER            = &H00000100???
%CM_REGISTRY_CONFIG          = &H00000200???
%CM_REGISTRY_BITS            = &H00000301???

'//
'// Flags for CM_Set_DevNode_Problem
'//
%CM_SET_DEVNODE_PROBLEM_NORMAL    = &H00000000???  ' // only set problem if currently no problem
%CM_SET_DEVNODE_PROBLEM_OVERRIDE  = &H00000001???  ' // override current problem with new problem
%CM_SET_DEVNODE_PROBLEM_BITS      = &H00000001???

%CM_SET_DEVINST_PROBLEM_NORMAL    = %CM_SET_DEVNODE_PROBLEM_NORMAL
%CM_SET_DEVINST_PROBLEM_OVERRIDE  = %CM_SET_DEVNODE_PROBLEM_OVERRIDE
%CM_SET_DEVINST_PROBLEM_BITS      = %CM_SET_DEVNODE_PROBLEM_BITS

'//
'// Flags for CM_Set_HW_Prof_Flags
'//
%CM_SET_HW_PROF_FLAGS_UI_NOT_OK  = &H00000001???    ' // Don't popup any veto UI
%CM_SET_HW_PROF_FLAGS_BITS       = &H00000001???

'//
'// Re-enable and configuration actions (specified in call to CM_Setup_DevInst???
'//
%CM_SETUP_DEVNODE_READY   = &H00000000??? ' // Reenable problem devinst
%CM_SETUP_DEVINST_READY   = %CM_SETUP_DEVNODE_READY
%CM_SETUP_DOWNLOAD        = &H00000001??? ' // Get info about devinst
%CM_SETUP_WRITE_LOG_CONFS = &H00000002???
%CM_SETUP_PROP_CHANGE     = &H00000003???

'#if (WINVER >= _WIN32_WINNT_WINXP)
%CM_SETUP_DEVNODE_RESET   = &H00000004??? ' // Reset problem devinst without starting
%CM_SETUP_DEVINST_RESET   = %CM_SETUP_DEVNODE_RESET
'#endif ' // (WINVER >= _WIN32_WINNT_WINXP)

%CM_SETUP_BITS            = &H00000007???

'//
'// Flags for CM_Query_Arbitrator_Free_Data and
'// CM_Query_Arbitrator_Free_Data_Size.
'//
%CM_QUERY_ARBITRATOR_RAW         = &H00000000???
%CM_QUERY_ARBITRATOR_TRANSLATED  = &H00000001???
%CM_QUERY_ARBITRATOR_BITS        = &H00000001???

'#if (WINVER >= _WIN32_WINNT_WINXP)
'//
'// Flags for CM_Get_DevNode_Custom_Property
'//
%CM_CUSTOMDEVPROP_MERGE_MULTISZ  = &H00000001???
%CM_CUSTOMDEVPROP_BITS           = &H00000001???
'#endif ' // (WINVER >= _WIN32_WINNT_WINXP)

'//
'// Name attribute bitmasks
'//
%CM_NAME_ATTRIBUTE_NAME_RETRIEVED_FROM_DEVICE = &H1???
%CM_NAME_ATTRIBUTE_USER_ASSIGNED_NAME         = &H2???

'//--------------------------------------------------------------
'// Function prototypes
'//--------------------------------------------------------------

DECLARE FUNCTION CM_Add_Empty_Log_Conf IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_Empty_Log_Conf" ( _
   BYREF plcLogConf AS DWORD _                          ' __out PLOG_CONF     plcLogConf
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL Priority AS DWORD _                            ' __in  PRIORITY      Priority
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_Empty_Log_Conf_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_Empty_Log_Conf_Ex" ( _
   BYREF plcLogConf AS DWORD _                          ' __out PLOG_CONF     plcLogConf
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL Priority AS DWORD _                            ' __in  PRIORITY      Priority
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_IDA IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_IDA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszID AS ASCIIZ _                              ' __in  PSTR          pszID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_IDW IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_IDW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszID AS WSTRINGZ _                            ' __in  PWSTR         pszID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Add_ID = CM_Add_IDW
#ELSE
MACRO CM_Add_ID = CM_Add_IDA
#ENDIF

DECLARE FUNCTION CM_Add_ID_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_ID_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszID AS ASCIIZ _                              ' __in  PSTR          pszID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_ID_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_ID_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszID AS WSTRINGZ _                            ' __in  PWSTR         pszID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Add_ID_Ex = CM_Add_ID_ExW
#ELSE
MACRO CM_Add_ID_Ex = CM_Add_ID_ExA
#ENDIF

DECLARE FUNCTION CM_Add_Range IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_Range" ( _
   BYVAL ullStartValue AS QUAD _                        ' __in  DWORDLONG     ullStartValue
 , BYVAL ullEndValue AS QUAD _                          ' __in  DWORDLONG     ullEndValue
 , BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_Res_Des IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_Res_Des" ( _
   BYREF prdResDes AS DWORD _                           ' __out_opt PRES_DES  prdResDes
 , BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Add_Res_Des_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Add_Res_Des_Ex" ( _
   BYREF prdResDes AS DWORD _                           ' __out_opt PRES_DES  prdResDes
 , BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Connect_MachineA IMPORT "SETUPAPI.DLL" ALIAS "CM_Connect_MachineA" ( _
   BYREF UNCServerName AS ASCIIZ _                      ' __in_opt PCSTR      UNCServerName
 , BYREF hMachine AS DWORD _                            ' __out PHMACHINE     phMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Connect_MachineW IMPORT "SETUPAPI.DLL" ALIAS "CM_Connect_MachineW" ( _
   BYREF UNCServerName AS WSTRINGZ _                    ' __in_opt PCWSTR     UNCServerName
 , BYREF hMachine AS DWORD _                            ' __out PHMACHINE     phMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Connect_Machine = CM_Connect_MachineW
#ELSE
MACRO CM_Connect_Machine = CM_Connect_MachineA
#ENDIF

DECLARE FUNCTION CM_Create_DevNodeA IMPORT "SETUPAPI.DLL" ALIAS "CM_Create_DevNodeA" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL dnParent AS DWORD _                            ' __in  DEVINST       dnParent
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Create_DevNodeW IMPORT "SETUPAPI.DLL" ALIAS "CM_Create_DevNodeW" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL dnParent AS DWORD _                            ' __in  DEVINST       dnParent
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Create_DevNode = CM_Create_DevNodeW
#ELSE
MACRO CM_Create_DevNode = CM_Create_DevNodeA
#ENDIF

DECLARE FUNCTION CM_Create_DevNode_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Create_DevNode_ExA" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL dnParent AS DWORD _                            ' __in  DEVINST       dnParent
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Create_DevNode_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Create_DevNode_ExW" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL dnParent AS DWORD _                            ' __in  DEVINST       dnParent
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Create_DevNode_Ex = CM_Create_DevNode_ExW
#ELSE
MACRO CM_Create_DevNode_Ex = CM_Create_DevNode_ExA
#ENDIF

DECLARE FUNCTION CM_Create_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Create_Range_List" ( _
   BYREF prlh AS DWORD _                                ' __out PRANGE_LIST   prlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_Class_Key IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Class_Key" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_Class_Key_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Class_Key_Ex" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_DevNode_Key IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_DevNode_Key" ( _
   BYVAL dnDevNode AS DWORD _                           ' __in  DEVNODE       dnDevNode
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_DevNode_Key_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_DevNode_Key_Ex" ( _
   BYVAL dnDevNode AS DWORD _                           ' __in  DEVNODE       dnDevNode
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_Range IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Range" ( _
   BYVAL ullStartValue AS QUAD _                        ' __in  DWORDLONG     ullStartValue
 , BYVAL ullEndValue AS QUAD _                          ' __in  DWORDLONG     ullEndValue
 , BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Detect_Resource_Conflict IMPORT "SETUPAPI.DLL" ALIAS "CM_Detect_Resource_Conflict" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYREF pbConflictDetected AS LONG _                   ' __out PBOOL         pbConflictDetected
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Detect_Resource_Conflict_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Detect_Resource_Conflict_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYREF pbConflictDetected AS LONG _                   ' __out PBOOL         pbConflictDetected
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Disable_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Disable_DevNode" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Disable_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Disable_DevNode_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Disconnect_Machine IMPORT "SETUPAPI.DLL" ALIAS "CM_Disconnect_Machine" ( _
   OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Dup_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Dup_Range_List" ( _
   BYVAL rlhOld AS DWORD _                              ' __in  RANGE_LIST    rlhOld
 , BYVAL rlhNew AS DWORD _                              ' __in  RANGE_LIST    rlhNew
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enable_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Enable_DevNode" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enable_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Enable_DevNode_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enumerate_Classes IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_Classes" ( _
   BYVAL ulClassIndex AS DWORD _                        ' __in  ULONG         ulClassIndex
 , BYREF ClassGuid AS GUID _                            ' __out LPGUID        ClassGuid
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enumerate_Classes_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_Classes_Ex" ( _
   BYVAL ulClassIndex AS DWORD _                        ' __in  ULONG         ulClassIndex
 , BYREF ClassGuid AS GUID _                            ' __out LPGUID        ClassGuid
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enumerate_EnumeratorsA IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_EnumeratorsA" ( _
   BYVAL ulEnumIndex AS DWORD _                         ' __in  ULONG         ulEnumIndex
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(*pulLength) PSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enumerate_EnumeratorsW IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_EnumeratorsW" ( _
   BYVAL ulEnumIndex AS DWORD _                         ' __in  ULONG         ulEnumIndex
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(*pulLength) PWSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Enumerate_Enumerators = CM_Enumerate_EnumeratorsW
#ELSE
MACRO CM_Enumerate_Enumerators = CM_Enumerate_EnumeratorsA
#ENDIF

DECLARE FUNCTION CM_Enumerate_Enumerators_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_Enumerators_ExA" ( _
   BYVAL ulEnumIndex AS DWORD _                         ' __in  ULONG         ulEnumIndex
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(*pulLength) PSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Enumerate_Enumerators_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Enumerate_Enumerators_ExW" ( _
   BYVAL ulEnumIndex AS DWORD _                         ' __in  ULONG         ulEnumIndex
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(*pulLength) PWSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Enumerate_Enumerators_Ex = CM_Enumerate_Enumerators_ExW
#ELSE
MACRO CM_Enumerate_Enumerators_Ex = CM_Enumerate_Enumerators_ExA
#ENDIF

DECLARE FUNCTION CM_Find_Range IMPORT "SETUPAPI.DLL" ALIAS "CM_Find_Range" ( _
   BYREF pullStart AS QUAD _                            ' __out PDWORDLONG    pullStart
 , BYVAL ullStart AS QUAD _                             ' __in  DWORDLONG     ullStart
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ullAlignment AS QUAD _                         ' __in  DWORDLONG     ullAlignment
 , BYVAL ullEnd AS QUAD _                               ' __in  DWORDLONG     ullEnd
 , BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_First_Range IMPORT "SETUPAPI.DLL" ALIAS "CM_First_Range" ( _
   BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYREF pullStart AS QUAD _                            ' __out PDWORDLONG    pullStart
 , BYREF pullEnd AS QUAD _                              ' __out PDWORDLONG    pullEnd
 , BYREF preElement AS DWORD _                          ' __out PRANGE_ELEMENT preElemen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Log_Conf IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Log_Conf" ( _
   BYVAL lcLogConfToBeFreed AS DWORD _                  ' __in  LOG_CONF      lcLogConfToBeFreed
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Log_Conf_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Log_Conf_Ex" ( _
   BYVAL lcLogConfToBeFreed AS DWORD _                  ' __in  LOG_CONF      lcLogConfToBeFreed
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Log_Conf_Handle IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Log_Conf_Handle" ( _
   BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Range_List" ( _
   BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Res_Des IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Res_Des" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Res_Des_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Res_Des_Ex" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Res_Des_Handle IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Res_Des_Handle" ( _
   BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Child IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Child" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Child_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Child_Ex" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_NameA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_NameA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount_opt(*pulLength) PSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_NameW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_NameW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount_opt(*pulLength) PWSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Class_Name = CM_Get_Class_NameW
#ELSE
MACRO CM_Get_Class_Name = CM_Get_Class_NameA
#ENDIF

DECLARE FUNCTION CM_Get_Class_Name_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Name_ExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount_opt(*pulLength) PSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_Name_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Name_ExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount_opt(*pulLength) PWSTR Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Class_Name_Ex = CM_Get_Class_Name_ExW
#ELSE
MACRO CM_Get_Class_Name_Ex = CM_Get_Class_Name_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Class_Key_NameA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Key_NameA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF pszKeyName AS ASCIIZ _                         ' __out_ecount_opt(*pulLength) LPSTR pszKeyName
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_Key_NameW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Key_NameW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF pszKeyName AS WSTRINGZ _                       ' __out_ecount_opt(*pulLength) LPWSTR pszKeyName
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Class_Key_Name = CM_Get_Class_Key_NameW
#ELSE
MACRO CM_Get_Class_Key_Name = CM_Get_Class_Key_NameA
#ENDIF

DECLARE FUNCTION CM_Get_Class_Key_Name_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Key_Name_ExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF pszKeyName AS ASCIIZ _                         ' __out_ecount_opt(*pulLength) LPSTR pszKeyName
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_Key_Name_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Key_Name_ExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYREF pszKeyName AS WSTRINGZ _                       ' __out_ecount_opt(*pulLength) LPWSTR pszKeyName
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Class_Key_Name_Ex = CM_Get_Class_Key_Name_ExW
#ELSE
MACRO CM_Get_Class_Key_Name_Ex = CM_Get_Class_Key_Name_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Depth IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Depth" ( _
   BYREF pulDepth AS DWORD _                            ' __out PULONG        pulDepth
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Depth_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Depth_Ex" ( _
   BYREF pulDepth AS DWORD _                            ' __out PULONG        pulDepth
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_IDA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_IDA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PSTR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_IDW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_IDW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWSTR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID = CM_Get_Device_IDW
#ELSE
MACRO CM_Get_Device_ID = CM_Get_Device_IDA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PSTR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWSTR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID_Ex = CM_Get_Device_ID_ExW
#ELSE
MACRO CM_Get_Device_ID_Ex = CM_Get_Device_ID_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_ListA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_ListA" ( _
   BYREF pszFilter AS ASCIIZ _                          ' __in_opt PCSTR      pszFilter
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_ListW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_ListW" ( _
   BYREF pszFilter AS WSTRINGZ _                        ' __in_opt PCWSTR     pszFilter
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID_List = CM_Get_Device_ID_ListW
#ELSE
MACRO CM_Get_Device_ID_List = CM_Get_Device_ID_ListA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_List_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_ExA" ( _
   BYREF pszFilter AS ASCIIZ _                          ' __in_opt PCSTR      pszFilter
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_List_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_ExW" ( _
   BYREF pszFilter AS WSTRINGZ _                        ' __in_opt PCWSTR     pszFilter
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID_List_Ex = CM_Get_Device_ID_List_ExW
#ELSE
MACRO CM_Get_Device_ID_List_Ex = CM_Get_Device_ID_List_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_List_SizeA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_SizeA" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF pszFilter AS ASCIIZ _                          ' __in_opt PCSTR      pszFilter
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_List_SizeW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_SizeW" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF pszFilter AS WSTRINGZ _                        ' __in_opt PCWSTR     pszFilter
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID_List_Size = CM_Get_Device_ID_List_SizeW
#ELSE
MACRO CM_Get_Device_ID_List_Size = CM_Get_Device_ID_List_SizeA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_List_Size_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_Size_ExA" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF pszFilter AS ASCIIZ _                          ' __in_opt PCSTR      pszFilter
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_List_Size_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_List_Size_ExW" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF pszFilter AS WSTRINGZ _                        ' __in_opt PCWSTR     pszFilter
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_ID_List_Size_Ex = CM_Get_Device_ID_List_Size_ExW
#ELSE
MACRO CM_Get_Device_ID_List_Size_Ex = CM_Get_Device_ID_List_Size_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_ID_Size IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_Size" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_ID_Size_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_ID_Size_Ex" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Registry_PropertyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Registry_PropertyA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Registry_PropertyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Registry_PropertyW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_DevNode_Registry_Property = CM_Get_DevNode_Registry_PropertyW
#ELSE
MACRO CM_Get_DevNode_Registry_Property = CM_Get_DevNode_Registry_PropertyA
#ENDIF

DECLARE FUNCTION CM_Get_DevNode_Registry_Property_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Registry_Property_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Registry_Property_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Registry_Property_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_DevNode_Registry_Property_Ex = CM_Get_DevNode_Registry_Property_ExW
#ELSE
MACRO CM_Get_DevNode_Registry_Property_Ex = CM_Get_DevNode_Registry_Property_ExA
#ENDIF

'#if (WINVER >= _WIN32_WINNT_WINXP)

DECLARE FUNCTION CM_Get_DevNode_Custom_PropertyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Custom_PropertyA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszCustomPropertyName AS ASCIIZ _              ' __in  PCSTR         pszCustomPropertyName
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Custom_PropertyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Custom_PropertyW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszCustomPropertyName AS WSTRINGZ _            ' __in  PCWSTR        pszCustomPropertyName
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_DevNode_Custom_Property = CM_Get_DevNode_Custom_PropertyW
#ELSE
MACRO CM_Get_DevNode_Custom_Property = CM_Get_DevNode_Custom_PropertyA
#ENDIF

DECLARE FUNCTION CM_Get_DevNode_Custom_Property_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Custom_Property_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszCustomPropertyName AS ASCIIZ _              ' __in  PCSTR         pszCustomPropertyName
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Custom_Property_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Custom_Property_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pszCustomPropertyName AS WSTRINGZ _            ' __in  PCWSTR        pszCustomPropertyName
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_DevNode_Custom_Property_Ex = CM_Get_DevNode_Custom_Property_ExW
#ELSE
MACRO CM_Get_DevNode_Custom_Property_Ex = CM_Get_DevNode_Custom_Property_ExA
#ENDIF

'#endif // (WINVER >= _WIN32_WINNT_WINXP)

DECLARE FUNCTION CM_Get_DevNode_Status IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Status" ( _
   BYREF pulStatus AS DWORD _                           ' __out PULONG        pulStatus
 , BYREF pulProblemNumber AS DWORD _                    ' __out PULONG        pulProblemNumber
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_DevNode_Status_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_DevNode_Status_Ex" ( _
   BYREF pulStatus AS DWORD _                           ' __out PULONG        pulStatus
 , BYREF pulProblemNumber AS DWORD _                    ' __out PULONG        pulProblemNumber
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_First_Log_Conf IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_First_Log_Conf" ( _
   BYREF plcLogConf AS DWORD _                          ' __out_opt PLOG_CONF plcLogConf
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_First_Log_Conf_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_First_Log_Conf_Ex" ( _
   BYREF plcLogConf AS DWORD _                          ' __out_opt PLOG_CONF plcLogConf
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Global_State IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Global_State" ( _
   BYREF pulState AS DWORD _                            ' __out PULONG        pulState
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Global_State_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Global_State_Ex" ( _
   BYREF pulState AS DWORD _                            ' __out PULONG        pulState
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

%CM_GLOBAL_STATE_CAN_DO_UI            = &H00000001??? ' // Can  do UI
%CM_GLOBAL_STATE_ON_BIG_STACK         = &H00000002??? ' // Not used (reserved)
%CM_GLOBAL_STATE_SERVICES_AVAILABLE   = &H00000004??? ' // CM APIs available?
%CM_GLOBAL_STATE_SHUTTING_DOWN        = &H00000008??? ' // CM shutting down
%CM_GLOBAL_STATE_DETECTION_PENDING    = &H00000010??? ' // Not used (reserved)
'#if (WINVER >= _WIN32_WINNT_WIN7)
%CM_GLOBAL_STATE_REBOOT_REQUIRED      = &H00000020??? ' // system reboot is required
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

DECLARE FUNCTION CM_Get_Hardware_Profile_InfoA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Hardware_Profile_InfoA" ( _
   BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pHWProfileInfo AS HWPROFILEINFO_A _            ' __out PHWPROFILEINFO_A pHWProfileInfo
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Hardware_Profile_InfoW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Hardware_Profile_InfoW" ( _
   BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pHWProfileInfo AS HWPROFILEINFO_W _            ' __out PHWPROFILEINFO_W pHWProfileInfo
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Hardware_Profile_Info = CM_Get_Hardware_Profile_InfoW
#ELSE
MACRO CM_Get_Hardware_Profile_Info = CM_Get_Hardware_Profile_InfoA
#ENDIF

DECLARE FUNCTION CM_Get_Hardware_Profile_Info_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Hardware_Profile_Info_ExA" ( _
   BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pHWProfileInfo AS HWPROFILEINFO_A _            ' __out PHWPROFILEINFO_A pHWProfileInfo
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Hardware_Profile_Info_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Hardware_Profile_Info_ExW" ( _
   BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pHWProfileInfo AS HWPROFILEINFO_W _            ' __out PHWPROFILEINFO_W pHWProfileInfo
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Hardware_Profile_Info_Ex = CM_Get_Hardware_Profile_Info_ExW
#ELSE
MACRO CM_Get_Hardware_Profile_Info_Ex = CM_Get_Hardware_Profile_Info_ExA
#ENDIF

DECLARE FUNCTION CM_Get_HW_Prof_FlagsA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_HW_Prof_FlagsA" ( _
   BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYREF pulValue AS DWORD _                            ' __out PULONG        pulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_HW_Prof_FlagsW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_HW_Prof_FlagsW" ( _
   BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYREF pulValue AS DWORD _                            ' __out PULONG        pulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_HW_Prof_Flags = CM_Get_HW_Prof_FlagsW
#ELSE
MACRO CM_Get_HW_Prof_Flags = CM_Get_HW_Prof_FlagsA
#ENDIF

DECLARE FUNCTION CM_Get_HW_Prof_Flags_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_HW_Prof_Flags_ExA" ( _
   BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYREF pulValue AS DWORD _                            ' __out PULONG        pulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_HW_Prof_Flags_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_HW_Prof_Flags_ExW" ( _
   BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYREF pulValue AS DWORD _                            ' __out PULONG        pulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_HW_Prof_Flags_Ex = CM_Get_HW_Prof_Flags_ExW
#ELSE
MACRO CM_Get_HW_Prof_Flags_Ex = CM_Get_HW_Prof_Flags_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_AliasA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_AliasA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYREF AliasInterfaceGuid AS GUID _                   ' __in  LPGUID        AliasInterfaceGuid
 , BYREF pszAliasDeviceInterface AS ASCIIZ _            ' __out_ecount(*pulLength) LPSTR pszAliasDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_AliasW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_AliasW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYREF AliasInterfaceGuid AS GUID _                   ' __in  LPGUID        AliasInterfaceGuid
 , BYREF pszAliasDeviceInterface AS WSTRINGZ _          ' __out_ecount(*pulLength) LPWSTR pszAliasDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_Alias = CM_Get_Device_Interface_AliasW
#ELSE
MACRO CM_Get_Device_Interface_Alias = CM_Get_Device_Interface_AliasA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_Alias_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_Alias_ExA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYREF AliasInterfaceGuid AS GUID _                   ' __in  LPGUID        AliasInterfaceGuid
 , BYREF pszAliasDeviceInterface AS ASCIIZ _            ' __out_ecount(*pulLength) LPSTR pszAliasDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_Alias_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_Alias_ExW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYREF AliasInterfaceGuid AS GUID _                   ' __in  LPGUID        AliasInterfaceGuid
 , BYREF pszAliasDeviceInterface AS WSTRINGZ _          ' __out_ecount(*pulLength) LPWSTR pszAliasDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_Alias_Ex = CM_Get_Device_Interface_Alias_ExW
#ELSE
MACRO CM_Get_Device_Interface_Alias_Ex = CM_Get_Device_Interface_Alias_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_ListA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_ListA" ( _
   BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_ListW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_ListW" ( _
   BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_List = CM_Get_Device_Interface_ListW
#ELSE
MACRO CM_Get_Device_Interface_List = CM_Get_Device_Interface_ListA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_List_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_ExA" ( _
   BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYREF Buffer AS ASCIIZ _                             ' __out_ecount(BufferLen) PCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_List_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_ExW" ( _
   BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYREF Buffer AS WSTRINGZ _                           ' __out_ecount(BufferLen) PWCHAR Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_List_Ex = CM_Get_Device_Interface_List_ExW
#ELSE
MACRO CM_Get_Device_Interface_List_Ex = CM_Get_Device_Interface_List_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_List_SizeA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_SizeA" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_List_SizeW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_SizeW" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_List_Size = CM_Get_Device_Interface_List_SizeW
#ELSE
MACRO CM_Get_Device_Interface_List_Size = CM_Get_Device_Interface_List_SizeA
#ENDIF

DECLARE FUNCTION CM_Get_Device_Interface_List_Size_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_Size_ExA" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Device_Interface_List_Size_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Device_Interface_List_Size_ExW" ( _
   BYREF pulLen AS DWORD _                              ' __out PULONG        pulLen
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Device_Interface_List_Size_Ex = CM_Get_Device_Interface_List_Size_ExW
#ELSE
MACRO CM_Get_Device_Interface_List_Size_Ex = CM_Get_Device_Interface_List_Size_ExA
#ENDIF

DECLARE FUNCTION CM_Get_Log_Conf_Priority IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Log_Conf_Priority" ( _
   BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYREF pPriority AS DWORD _                           ' __out PPRIORITY     pPriority
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Log_Conf_Priority_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Log_Conf_Priority_Ex" ( _
   BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYREF pPriority AS DWORD _                           ' __out PPRIORITY     pPriority
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Next_Log_Conf IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Next_Log_Conf" ( _
   BYREF plcLogConf AS DWORD _                          ' __out_opt PLOG_CONF plcLogConf
 , BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Next_Log_Conf_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Next_Log_Conf_Ex" ( _
   BYREF plcLogConf AS DWORD _                          ' __out_opt PLOG_CONF plcLogConf
 , BYVAL lcLogConf AS DWORD _                           ' __in  LOG_CONF      lcLogConf
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Parent IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Parent" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Parent_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Parent_Ex" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Res_Des_Data IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Res_Des_Data" ( _
   BYREF rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLen) PVOID Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Res_Des_Data_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Res_Des_Data_Ex" ( _
   BYREF rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYREF Buffer AS ANY _                                ' __out_bcount(BufferLen) PVOID Buffer
 , BYVAL BufferLen AS DWORD _                           ' __in  ULONG         BufferLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Res_Des_Data_Size IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Res_Des_Data_Size" ( _
   BYREF pulSize AS DWORD _                             ' __out PULONG        pulSize
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Res_Des_Data_Size_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Res_Des_Data_Size_Ex" ( _
   BYREF pulSize AS DWORD _                             ' __out PULONG        pulSize
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Sibling IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Sibling" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Sibling_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Sibling_Ex" ( _
   BYREF pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Version IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Version" ( _
 ) AS WORD                                              ' WORD

DECLARE FUNCTION CM_Get_Version_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Version_Ex" ( _
   OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS WORD                                              ' WORD

'#if (WINVER >= _WIN32_WINNT_WINXP)
DECLARE FUNCTION CM_Is_Version_Available IMPORT "SETUPAPI.DLL" ALIAS "CM_Is_Version_Available" ( _
   BYVAL wVersion AS WORD _                             ' __in  WORD          wVersion
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CM_Is_Version_Available_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Is_Version_Available_Ex" ( _
   BYVAL wVersion AS WORD _                             ' __in  WORD          wVersion
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS LONG                                              ' BOOL
'#endif // (WINVER >= _WIN32_WINNT_WINXP)

DECLARE FUNCTION CM_Intersect_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Intersect_Range_List" ( _
   BYVAL rlhOld1 AS DWORD _                             ' __in  RANGE_LIST    rlhOld1
 , BYVAL rlhOld2 AS DWORD _                             ' __in  RANGE_LIST    rlhOld2
 , BYVAL rlhNew AS DWORD _                              ' __in  RANGE_LIST    rlhNew
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Invert_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Invert_Range_List" ( _
   BYVAL rlhOld AS DWORD _                              ' __in  RANGE_LIST    rlhOld
 , BYVAL rlhNew AS DWORD _                              ' __in  RANGE_LIST    rlhNew
 , BYVAL ullMaxValue AS QUAD _                          ' __in  DWORDLONG     ullMaxValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Locate_DevNodeA IMPORT "SETUPAPI.DLL" ALIAS "CM_Locate_DevNodeA" ( _
   BYVAL pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Locate_DevNodeW IMPORT "SETUPAPI.DLL" ALIAS "CM_Locate_DevNodeW" ( _
   BYVAL pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Locate_DevNode = CM_Locate_DevNodeW
#ELSE
MACRO CM_Locate_DevNode = CM_Locate_DevNodeA
#ENDIF

DECLARE FUNCTION CM_Locate_DevNode_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Locate_DevNode_ExA" ( _
   BYVAL pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYREF pDeviceID AS ASCIIZ _                          ' __in_opt DEVINSTID_A pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Locate_DevNode_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Locate_DevNode_ExW" ( _
   BYVAL pdnDevInst AS DWORD _                          ' __out PDEVINST      pdnDevInst
 , BYVAL pDeviceID AS DWORD _                           ' __in_opt DEVINSTID_W pDeviceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Locate_DevNode_Ex = CM_Locate_DevNode_ExW
#ELSE
MACRO CM_Locate_DevNode_Ex = CM_Locate_DevNode_ExA
#ENDIF

DECLARE FUNCTION CM_Merge_Range_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Merge_Range_List" ( _
   BYVAL rlhOld1 AS DWORD _                             ' __in  RANGE_LIST    rlhOld1
 , BYVAL rlhOld2 AS DWORD _                             ' __in  RANGE_LIST    rlhOld2
 , BYVAL rlhNew AS DWORD _                              ' __in  RANGE_LIST    rlhNew
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Modify_Res_Des IMPORT "SETUPAPI.DLL" ALIAS "CM_Modify_Res_Des" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Modify_Res_Des_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Modify_Res_Des_Ex" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Move_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Move_DevNode" ( _
   BYVAL dnFromDevInst AS DWORD _                       ' __in  DEVINST       dnFromDevInst
 , BYVAL dnToDevInst AS DWORD _                         ' __in  DEVINST       dnToDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Move_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Move_DevNode_Ex" ( _
   BYVAL dnFromDevInst AS DWORD _                       ' __in  DEVINST       dnFromDevInst
 , BYVAL dnToDevInst AS DWORD _                         ' __in  DEVINST       dnToDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Next_Range IMPORT "SETUPAPI.DLL" ALIAS "CM_Next_Range" ( _
   BYREF preElement AS DWORD _                          ' __inout PRANGE_ELEMENT preElement
 , BYREF pullStart AS QUAD _                            ' __out PDWORDLONG    pullStart
 , BYREF pullEnd AS QUAD _                              ' __out PDWORDLONG    pullEnd
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Next_Res_Des IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Next_Res_Des" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ForResource AS DWORD _                         ' __in  RESOURCEID    ForResource
 , BYREF pResourceID AS DWORD _                         ' __out_opt PRESOURCEID pResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Next_Res_Des_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Next_Res_Des_Ex" ( _
   BYREF prdResDes AS DWORD _                           ' __out PRES_DES      prdResDes
 , BYVAL rdResDes AS DWORD _                            ' __in  RES_DES       rdResDes
 , BYVAL ForResource AS DWORD _                         ' __in  RESOURCEID    ForResource
 , BYREF pResourceID AS DWORD _                         '  __out_opt PRESOURCEID pResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_Class_KeyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Class_KeyA" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt LPGUID     ClassGuid
 , BYREF pszClassName AS ASCIIZ _                       ' __in_opt LPCSTR     pszClassName
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkClass AS DWORD _                            ' __out PHKEY         phkClass
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_Class_KeyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Class_KeyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt LPGUID     ClassGuid
 , BYREF pszClassName AS WSTRINGZ _                     ' __in_opt LPCWSTR    pszClassName
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkClass AS DWORD _                            ' __out PHKEY         phkClass
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Open_Class_Key = CM_Open_Class_KeyW
#ELSE
MACRO CM_Open_Class_Key = CM_Open_Class_KeyA
#ENDIF

DECLARE FUNCTION CM_Open_Class_Key_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Class_Key_ExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt LPGUID     ClassGuid
 , BYREF pszClassName AS ASCIIZ _                       ' __in_opt LPCSTR     pszClassName
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkClass AS DWORD _                            ' __out PHKEY         phkClass
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_Class_Key_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Class_Key_ExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt LPGUID     ClassGuid
 , BYREF pszClassName AS WSTRINGZ _                     ' __in_opt LPCWSTR    pszClassName
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkClass AS DWORD _                            ' __out PHKEY         phkClass
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Open_Class_Key_Ex = CM_Open_Class_Key_ExW
#ELSE
MACRO CM_Open_Class_Key_Ex = CM_Open_Class_Key_ExA
#ENDIF

DECLARE FUNCTION CM_Open_DevNode_Key IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_DevNode_Key" ( _
   BYVAL dnDevNode AS DWORD _                           ' __in  DEVINST       dnDevNode
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDevice AS DWORD _                           ' __out PHKEY         phkDevice
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_DevNode_Key_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_DevNode_Key_Ex" ( _
   BYVAL dnDevNode AS DWORD _                           ' __in  DEVINST       dnDevNode
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDevice AS DWORD _                           ' __out PHKEY         phkDevice
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

'#if (WINVER >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION CM_Open_Device_Interface_KeyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Device_Interface_KeyA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDeviceInterface AS DWORD _                  ' __out PHKEY         phkDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_Device_Interface_KeyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Device_Interface_KeyW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDeviceInterface AS DWORD _                  ' __out PHKEY         phkDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Open_Device_Interface_Key = CM_Open_Device_Interface_KeyW
#ELSE
MACRO CM_Open_Device_Interface_Key = CM_Open_Device_Interface_KeyA
#ENDIF

DECLARE FUNCTION CM_Open_Device_Interface_Key_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Device_Interface_Key_ExA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDeviceInterface AS DWORD _                  ' __out PHKEY         phkDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Open_Device_Interface_Key_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Open_Device_Interface_Key_ExW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL samDesired AS REGSAM _                         ' __in  REGSAM        samDesired
 , BYVAL Disposition AS DWORD _                         ' __in  REGDISPOSITION Disposition
 , BYREF phkDeviceInterface AS DWORD _                  ' __out PHKEY         phkDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Open_Device_Interface_Key_Ex = CM_Open_Device_Interface_Key_ExW
#ELSE
MACRO CM_Open_Device_Interface_Key_Ex = CM_Open_Device_Interface_Key_ExA
#ENDIF

DECLARE FUNCTION CM_Delete_Device_Interface_KeyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Device_Interface_KeyA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_Device_Interface_KeyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Device_Interface_KeyW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Delete_Device_Interface_Key = CM_Delete_Device_Interface_KeyW
#ELSE
MACRO CM_Delete_Device_Interface_Key = CM_Delete_Device_Interface_KeyA
#ENDIF

DECLARE FUNCTION CM_Delete_Device_Interface_Key_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Device_Interface_Key_ExA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_Device_Interface_Key_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_Device_Interface_Key_ExW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Delete_Device_Interface_Key_Ex = CM_Delete_Device_Interface_Key_ExW
#ELSE
MACRO CM_Delete_Device_Interface_Key_Ex = CM_Delete_Device_Interface_Key_ExA
#ENDIF

'#endif // (WINVER >= _WIN32_WINNT_LONGHORN)

DECLARE FUNCTION CM_Query_Arbitrator_Free_Data IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Arbitrator_Free_Data" ( _
   BYREF pData AS ANY _                                 ' __out_bcount(DataLen) PVOID pData
 , BYVAL DataLen AS DWORD _                             ' __in  ULONG         DataLen
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Arbitrator_Free_Data_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Arbitrator_Free_Data_Ex" ( _
   BYREF pData AS ANY _                                 ' __out_bcount(DataLen) PVOID pData
 , BYVAL DataLen AS DWORD _                             ' __in  ULONG         DataLen
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Arbitrator_Free_Size IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Arbitrator_Free_Size" ( _
   BYREF pulSize AS DWORD _                             ' __out PULONG        pulSize
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Arbitrator_Free_Size_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Arbitrator_Free_Size_Ex" ( _
   BYREF pulSize AS DWORD _                             ' __out PULONG        pulSize
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Remove_SubTree IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Remove_SubTree" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Remove_SubTree_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Remove_SubTree_Ex" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_And_Remove_SubTree IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_And_Remove_SubTreeA" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS ASCIIZ _                        ' __out_ecount_opt(ulNameLength) LPSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_And_Remove_SubTree_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_And_Remove_SubTree_ExA" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS ASCIIZ _                        ' __out_ecount_opt(ulNameLength) LPSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_And_Remove_SubTreeW IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_And_Remove_SubTreeW" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS WSTRINGZ _                      ' __out_ecount_opt(ulNameLength) LPWSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_And_Remove_SubTree_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_And_Remove_SubTree_ExW" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS WSTRINGZ _                      ' __out_ecount_opt(ulNameLength) LPWSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Query_And_Remove_SubTree_Ex = CM_Query_And_Remove_SubTree_ExW
#ELSE
MACRO CM_Query_And_Remove_SubTree_Ex = CM_Query_And_Remove_SubTree_ExA
#ENDIF

DECLARE FUNCTION CM_Request_Device_EjectA IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Device_EjectA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS ASCIIZ _                        ' __out_ecount_opt(ulNameLength) LPSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Request_Device_EjectW IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Device_EjectW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS WSTRINGZ _                      ' __out_ecount_opt(ulNameLength) LPWSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Request_Device_Eject = CM_Request_Device_EjectW
#ELSE
MACRO CM_Request_Device_Eject = CM_Request_Device_EjectA
#ENDIF

DECLARE FUNCTION CM_Request_Device_Eject_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Device_Eject_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS ASCIIZ _                        ' __out_ecount_opt(ulNameLength) LPSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Request_Device_Eject_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Device_Eject_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF pVetoType AS LONG _                            ' __out_opt PPNP_VETO_TYPE pVetoType
 , BYREF pszVetoName AS WSTRINGZ _                      ' __out_ecount_opt(ulNameLength) LPWSTR pszVetoName
 , BYVAL ulNameLength AS DWORD _                        ' __in  ULONG         ulNameLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Request_Device_Eject_Ex = CM_Request_Device_Eject_ExW
#ELSE
MACRO CM_Request_Device_Eject_Ex = CM_Request_Device_Eject_ExA
#ENDIF

DECLARE FUNCTION CM_Reenumerate_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Reenumerate_DevNode" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Reenumerate_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Reenumerate_DevNode_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Register_Device_InterfaceA IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_InterfaceA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pszReference AS ASCIIZ _                       ' __in_opt LPCSTR     pszReference
 , BYREF pszDeviceInterface AS ASCIIZ _                 ' __out_ecount(*pulLength) LPSTR pszDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Register_Device_InterfaceW IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_InterfaceW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pszReference AS WSTRINGZ _                     ' __in_opt LPCWSTR    pszReference
 , BYVAL pszDeviceInterface AS DWORD _                  ' __out_ecount(*pulLength) LPWSTR pszDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Register_Device_Interface = CM_Register_Device_InterfaceW
#ELSE
MACRO CM_Register_Device_Interface = CM_Register_Device_InterfaceA
#ENDIF

DECLARE FUNCTION CM_Register_Device_Interface_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_Interface_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pszReference AS ASCIIZ _                       ' __in_opt LPCSTR     pszReference
 , BYREF pszDeviceInterface AS ASCIIZ _                 ' __out_ecount(*pulLength) LPSTR pszDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Register_Device_Interface_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_Interface_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYREF InterfaceClassGuid AS GUID _                   ' __in  LPGUID        InterfaceClassGuid
 , BYREF pszReference AS WSTRINGZ _                     ' __in_opt LPCWSTR    pszReference
 , BYREF pszDeviceInterface AS WSTRINGZ _               ' __out_ecount(*pulLength) LPWSTR pszDeviceInterface
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Register_Device_Interface_Ex = CM_Register_Device_Interface_ExW
#ELSE
MACRO CM_Register_Device_Interface_Ex = CM_Register_Device_Interface_ExA
#ENDIF

DECLARE FUNCTION CM_Set_DevNode_Problem_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Problem_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProblem AS DWORD _                           ' __in  ULONG         ulProblem
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_DevNode_Problem IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Problem" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProblem AS DWORD _                           ' __in  ULONG         ulProblem
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Unregister_Device_InterfaceA IMPORT "SETUPAPI.DLL" ALIAS "CM_Unregister_Device_InterfaceA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Unregister_Device_InterfaceW IMPORT "SETUPAPI.DLL" ALIAS "CM_Unregister_Device_InterfaceW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Unregister_Device_Interface = CM_Unregister_Device_InterfaceW
#ELSE
MACRO CM_Unregister_Device_Interface = CM_Unregister_Device_InterfaceA
#ENDIF

DECLARE FUNCTION CM_Unregister_Device_Interface_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Unregister_Device_Interface_ExA" ( _
   BYREF pszDeviceInterface AS ASCIIZ _                 ' __in  LPCSTR        pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Unregister_Device_Interface_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Unregister_Device_Interface_ExW" ( _
   BYREF pszDeviceInterface AS WSTRINGZ _               ' __in  LPCWSTR       pszDeviceInterface
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Unregister_Device_Interface_Ex = CM_Unregister_Device_Interface_ExW
#ELSE
MACRO CM_Unregister_Device_Interface_Ex = CM_Unregister_Device_Interface_ExA
#ENDIF

DECLARE FUNCTION CM_Register_Device_Driver IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_Driver" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Register_Device_Driver_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Register_Device_Driver_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Remove_SubTree IMPORT "SETUPAPI.DLL" ALIAS "CM_Remove_SubTree" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Remove_SubTree_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Remove_SubTree_Ex" ( _
   BYVAL dnAncestor AS DWORD _                          ' __in  DEVINST       dnAncestor
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_DevNode_Registry_PropertyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Registry_PropertyA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF Buffer AS ANY _                                ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_DevNode_Registry_PropertyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Registry_PropertyW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF Buffer AS ANY _                                ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Set_DevNode_Registry_Property = CM_Set_DevNode_Registry_PropertyW
#ELSE
MACRO CM_Set_DevNode_Registry_Property = CM_Set_DevNode_Registry_PropertyA
#ENDIF

DECLARE FUNCTION CM_Set_DevNode_Registry_Property_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Registry_Property_ExA" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF Buffer AS ANY _                                ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_DevNode_Registry_Property_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_DevNode_Registry_Property_ExW" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF Buffer AS ANY _                                ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Set_DevNode_Registry_Property_Ex = CM_Set_DevNode_Registry_Property_ExW
#ELSE
MACRO CM_Set_DevNode_Registry_Property_Ex = CM_Set_DevNode_Registry_Property_ExA
#ENDIF

DECLARE FUNCTION CM_Is_Dock_Station_Present IMPORT "SETUPAPI.DLL" ALIAS "CM_Is_Dock_Station_Present" ( _
   BYREF pbPresent AS LONG _                            ' __out PBOOL         pbPresent
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Is_Dock_Station_Present_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Is_Dock_Station_Present_Ex" ( _
   BYREF pbPresent AS LONG _                            ' __out PBOOL         pbPresent
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Request_Eject_PC IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Eject_PC" ( _
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Request_Eject_PC_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Request_Eject_PC_Ex" ( _
   OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_HW_Prof_FlagsA IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof_FlagsA" ( _
   BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL ulConfig AS DWORD _                            ' __in  ULONG         ulConfig
 , BYVAL ulValue AS DWORD _                             ' __in  ULONG         ulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_HW_Prof_FlagsW IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof_FlagsW" ( _
   BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL ulConfig AS DWORD _                            ' __in  ULONG         ulConfig
 , BYVAL ulValue AS DWORD _                             ' __in  ULONG         ulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Set_HW_Prof_Flags = CM_Set_HW_Prof_FlagsW
#ELSE
MACRO CM_Set_HW_Prof_Flags = CM_Set_HW_Prof_FlagsA
#ENDIF

DECLARE FUNCTION CM_Set_HW_Prof_Flags_ExA IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof_Flags_ExA" ( _
   BYREF pDeviceID AS ASCIIZ _                          ' __in  DEVINSTID_A   pDeviceID
 , BYVAL ulConfig AS DWORD _                            ' __in  ULONG         ulConfig
 , BYVAL ulValue AS DWORD _                             ' __in  ULONG         ulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_HW_Prof_Flags_ExW IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof_Flags_ExW" ( _
   BYVAL pDeviceID AS DWORD _                           ' __in  DEVINSTID_W   pDeviceID
 , BYVAL ulConfig AS DWORD _                            ' __in  ULONG         ulConfig
 , BYVAL ulValue AS DWORD _                             ' __in  ULONG         ulValue
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Set_HW_Prof_Flags_Ex = CM_Set_HW_Prof_Flags_ExW
#ELSE
MACRO CM_Set_HW_Prof_Flags_Ex = CM_Set_HW_Prof_Flags_ExA
#ENDIF

DECLARE FUNCTION CM_Setup_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Setup_DevNode" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Setup_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Setup_DevNode_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Test_Range_Available IMPORT "SETUPAPI.DLL" ALIAS "CM_Test_Range_Available" ( _
   BYVAL ullStartValue AS QUAD _                        ' __in  DWORDLONG     ullStartValue
 , BYVAL ullEndValue AS QUAD _                          ' __in  DWORDLONG     ullEndValue
 , BYVAL rlh AS DWORD _                                 ' __in  RANGE_LIST    rlh
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Uninstall_DevNode IMPORT "SETUPAPI.DLL" ALIAS "CM_Uninstall_DevNode" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Uninstall_DevNode_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Uninstall_DevNode_Ex" ( _
   BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Run_Detection IMPORT "SETUPAPI.DLL" ALIAS "CM_Run_Detection" ( _
   BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Run_Detection_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Run_Detection_Ex" ( _
   BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

'#if (WINVER >= _WIN32_WINNT_LONGHORN)

DECLARE FUNCTION CM_Apply_PowerScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Apply_PowerScheme" ( _
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Write_UserPowerKey IMPORT "SETUPAPI.DLL" ALIAS "CM_Write_UserPowerKey" ( _
   BYREF SchemeGuid AS GUID _                           ' __in_opt CONST GUID *SchemeGuid
 , BYREF SubGroupOfPowerSettingsGuid AS GUID _          ' __in_opt CONST GUID *SubGroupOfPowerSettingsGuid
 , BYREF PowerSettingGuid AS GUID _                     ' __in_opt CONST GUID *PowerSettingGuid
 , BYVAL AccessFlags AS DWORD _                         ' __in ULONG AccessFlags
 , BYVAL Type AS DWORD _                                ' __in ULONG Type
 , BYVAL Buffer AS DWORD _                              ' __in_bcount(BufferSize) UCHAR *Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in DWORD BufferSize
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_ActiveScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_ActiveScheme" ( _
   BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Restore_DefaultPowerScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Restore_DefaultPowerScheme" ( _
   BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_RestoreAll_DefaultPowerSchemes IMPORT "SETUPAPI.DLL" ALIAS "CM_RestoreAll_DefaultPowerSchemes" ( _
   BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Duplicate_PowerScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Duplicate_PowerScheme" ( _
   BYREF SourceSchemeGuid AS GUID _                     ' __in CONST GUID *SourceSchemeGuid
 , BYREF DestinationSchemeGuid AS GUID _                ' __in GUID **DestinationSchemeGuid
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Delete_PowerScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Delete_PowerScheme" ( _
   BYREF SchemeGuid AS GUID _                           ' __in CONST GUID *SchemeGuid
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Import_PowerScheme IMPORT "SETUPAPI.DLL" ALIAS "CM_Import_PowerScheme" ( _
   BYREF ImportFileNamePath AS WSTRINGZ _               ' __in LPCWSTR ImportFileNamePath
 , BYREF DestinationSchemeGuid AS GUID _                ' __deref_inout GUID **DestinationSchemeGuid
 , BYREF Error AS DWORD _                               ' __out PDWORD Error
 ) AS DWORD                                             ' CONFIGRET

'#endif // (WINVER >= _WIN32_WINNT_LONGHORN)

DECLARE FUNCTION CM_Set_HW_Prof IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof" ( _
   BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_HW_Prof_Ex IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_HW_Prof_Ex" ( _
   BYVAL ulHardwareProfile AS DWORD _                   ' __in  ULONG         ulHardwareProfile
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Query_Resource_Conflict_List IMPORT "SETUPAPI.DLL" ALIAS "CM_Query_Resource_Conflict_List" ( _
   BYREF pclConflictList AS DWORD _                     ' __out PCONFLICT_LIST pclConflictList
 , BYVAL dnDevInst AS DWORD _                           ' __in  DEVINST       dnDevInst
 , BYVAL ResourceID AS DWORD _                          ' __in  RESOURCEID    ResourceID
 , BYREF ResourceData AS ANY _                          ' __in_bcount(ResourceLen) PCVOID ResourceData
 , BYVAL ResourceLen AS DWORD _                         ' __in  ULONG         ResourceLen
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Free_Resource_Conflict_Handle IMPORT "SETUPAPI.DLL" ALIAS "CM_Free_Resource_Conflict_Handle" ( _
   BYVAL clConflictList AS DWORD _                      ' __in  CONFLICT_LIST clConflictList
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Resource_Conflict_Count IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Resource_Conflict_Count" ( _
   BYVAL clConflictList AS DWORD _                      ' __in  CONFLICT_LIST clConflictList
 , BYREF pulCount AS DWORD _                            ' __out PULONG        pulCount
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Resource_Conflict_DetailsA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Resource_Conflict_DetailsA" ( _
   BYVAL clConflictList AS DWORD _                      ' __in  CONFLICT_LIST clConflictList
 , BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pConflictDetails AS CONFLICT_DETAILS_A _       ' __inout PCONFLICT_DETAILS_A pConflictDetails
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Resource_Conflict_DetailsW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Resource_Conflict_DetailsW" ( _
   BYVAL clConflictList AS DWORD _                      ' __in  CONFLICT_LIST clConflictList
 , BYVAL ulIndex AS DWORD _                             ' __in  ULONG         ulIndex
 , BYREF pConflictDetails AS CONFLICT_DETAILS_W _       ' __inout PCONFLICT_DETAILS_W pConflictDetails
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Resource_Conflict_Details = CM_Get_Resource_Conflict_DetailsW
#ELSE
MACRO CM_Get_Resource_Conflict_Details = CM_Get_Resource_Conflict_DetailsA
#ENDIF

DECLARE FUNCTION CM_Get_Class_Registry_PropertyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Registry_PropertyA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Get_Class_Registry_PropertyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Get_Class_Registry_PropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYREF pulRegDataType AS DWORD _                      ' __out_opt PULONG    pulRegDataType
 , BYREF Buffer AS ANY _                                ' __out_bcount_opt(*pulLength) PVOID Buffer
 , BYREF pulLength AS DWORD _                           ' __inout PULONG      pulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Get_Class_Registry_Property = CM_Get_Class_Registry_PropertyW
#ELSE
MACRO CM_Get_Class_Registry_Property = CM_Get_Class_Registry_PropertyA
#ENDIF

DECLARE FUNCTION CM_Set_Class_Registry_PropertyA IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_Class_Registry_PropertyA" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYVAL Buffer AS DWORD _                              ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

DECLARE FUNCTION CM_Set_Class_Registry_PropertyW IMPORT "SETUPAPI.DLL" ALIAS "CM_Set_Class_Registry_PropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in  LPGUID        ClassGuid
 , BYVAL ulProperty AS DWORD _                          ' __in  ULONG         ulProperty
 , BYVAL Buffer AS DWORD _                              ' __in_bcount_opt(ulLength) PCVOID Buffer
 , BYVAL ulLength AS DWORD _                            ' __in  ULONG         ulLength
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG         ulFlags
 , OPTIONAL BYVAL hMachine AS DWORD _                   ' __in_opt HMACHINE   hMachine
 ) AS DWORD                                             ' CONFIGRET

#IF %DEF(%UNICODE)
MACRO CM_Set_Class_Registry_Property = CM_Set_Class_Registry_PropertyW
#ELSE
MACRO CM_Set_Class_Registry_Property = CM_Set_Class_Registry_PropertyA
#ENDIF

'#if (WINVER >= _WIN32_WINNT_WIN2K)
DECLARE FUNCTION CM_WaitNoPendingInstallEvents IMPORT "SETUPAPI.DLL" ALIAS "CM_WaitNoPendingInstallEvents" ( _
   BYVAL dwTimeout AS DWORD _                           ' __in  DWORD dwTimeout
 ) AS DWORD                                             ' DWORD
'#endif // (WINVER >= _WIN32_WINNT_WIN2K)


'//--------------------------------------------------------------
'// Configuration Manager return status codes
'//--------------------------------------------------------------

%CR_SUCCESS                  = &H00000000???
%CR_DEFAULT                  = &H00000001???
%CR_OUT_OF_MEMORY            = &H00000002???
%CR_INVALID_POINTER          = &H00000003???
%CR_INVALID_FLAG             = &H00000004???
%CR_INVALID_DEVNODE          = &H00000005???
%CR_INVALID_DEVINST          = %CR_INVALID_DEVNODE
%CR_INVALID_RES_DES          = &H00000006???
%CR_INVALID_LOG_CONF         = &H00000007???
%CR_INVALID_ARBITRATOR       = &H00000008???
%CR_INVALID_NODELIST         = &H00000009???
%CR_DEVNODE_HAS_REQS         = &H0000000A???
%CR_DEVINST_HAS_REQS         = %CR_DEVNODE_HAS_REQS
%CR_INVALID_RESOURCEID       = &H0000000B???
%CR_DLVXD_NOT_FOUND          = &H0000000C???   ' // WIN 95 ONLY
%CR_NO_SUCH_DEVNODE          = &H0000000D???
%CR_NO_SUCH_DEVINST          = %CR_NO_SUCH_DEVNODE
%CR_NO_MORE_LOG_CONF         = &H0000000E???
%CR_NO_MORE_RES_DES          = &H0000000F???
%CR_ALREADY_SUCH_DEVNODE     = &H00000010???
%CR_ALREADY_SUCH_DEVINST     = %CR_ALREADY_SUCH_DEVNODE
%CR_INVALID_RANGE_LIST       = &H00000011???
%CR_INVALID_RANGE            = &H00000012???
%CR_FAILURE                  = &H00000013???
%CR_NO_SUCH_LOGICAL_DEV      = &H00000014???
%CR_CREATE_BLOCKED           = &H00000015???
%CR_NOT_SYSTEM_VM            = &H00000016???   ' // WIN 95 ONLY
%CR_REMOVE_VETOED            = &H00000017???
%CR_APM_VETOED               = &H00000018???
%CR_INVALID_LOAD_TYPE        = &H00000019???
%CR_BUFFER_SMALL             = &H0000001A???
%CR_NO_ARBITRATOR            = &H0000001B???
%CR_NO_REGISTRY_HANDLE       = &H0000001C???
%CR_REGISTRY_ERROR           = &H0000001D???
%CR_INVALID_DEVICE_ID        = &H0000001E???
%CR_INVALID_DATA             = &H0000001F???
%CR_INVALID_API              = &H00000020???
%CR_DEVLOADER_NOT_READY      = &H00000021???
%CR_NEED_RESTART             = &H00000022???
%CR_NO_MORE_HW_PROFILES      = &H00000023???
%CR_DEVICE_NOT_THERE         = &H00000024???
%CR_NO_SUCH_VALUE            = &H00000025???
%CR_WRONG_TYPE               = &H00000026???
%CR_INVALID_PRIORITY         = &H00000027???
%CR_NOT_DISABLEABLE          = &H00000028???
%CR_FREE_RESOURCES           = &H00000029???
%CR_QUERY_VETOED             = &H0000002A???
%CR_CANT_SHARE_IRQ           = &H0000002B???
%CR_NO_DEPENDENT             = &H0000002C???
%CR_SAME_RESOURCES           = &H0000002D???
%CR_NO_SUCH_REGISTRY_KEY     = &H0000002E???
%CR_INVALID_MACHINENAME      = &H0000002F???   ' // NT ONLY
%CR_REMOTE_COMM_FAILURE      = &H00000030???   ' // NT ONLY
%CR_MACHINE_UNAVAILABLE      = &H00000031???   ' // NT ONLY
%CR_NO_CM_SERVICES           = &H00000032???   ' // NT ONLY
%CR_ACCESS_DENIED            = &H00000033???   ' // NT ONLY
%CR_CALL_NOT_IMPLEMENTED     = &H00000034???
%CR_INVALID_PROPERTY         = &H00000035???
%CR_DEVICE_INTERFACE_ACTIVE  = &H00000036???
%CR_NO_SUCH_DEVICE_INTERFACE = &H00000037???
%CR_INVALID_REFERENCE_STRING = &H00000038???
%CR_INVALID_CONFLICT_LIST    = &H00000039???
%CR_INVALID_INDEX            = &H0000003A???
%CR_INVALID_STRUCTURE_SIZE   = &H0000003B???
%NUM_CR_RESULTS              = &H0000003C???
