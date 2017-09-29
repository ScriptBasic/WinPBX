' ########################################################################################
' Microsoft Windows
' File: Traffic.inc
' Contents: API definitions for the traffic control interface.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TRADDIC_INC = 1

#INCLUDE ONCE "ntddndis.inc"
#INCLUDE ONCE "qosobjs.inc"

'//---------------------------------------------------------------------------
'//
'// Define's
'//
%CURRENT_TCI_VERSION         = &H0002

'//
'// Definitions of notification events. These may be passed
'// to the client's notification handler, to identify the
'// notification type
'//

'//
'// A TC interface has come up
'//
%TC_NOTIFY_IFC_UP       = 1
'//
'// A TC interface has come down
'//
%TC_NOTIFY_IFC_CLOSE    = 2
'//
'// A change on a TC interface, typically a change in the
'// list of supported network addresses
'//
%TC_NOTIFY_IFC_CHANGE   = 3
'//
'// A TC parameter has changed
'//
%TC_NOTIFY_PARAM_CHANGED = 4
'//
'// A flow has been closed by the TC interface
'// for example: after a remote call close, or the whole interface
'// is going down
'//
%TC_NOTIFY_FLOW_CLOSE    = 5

%TC_INVALID_HANDLE = 0???   '  ((HANDLE)0)

%MAX_STRING_LENGTH = 256


'//---------------------------------------------------------------------------
'//
'// Typedef's and structures
'//

'//
'// Handlers registered by the TCI client
'//

'typedef
'VOID (CALLBACK * TCI_NOTIFY_HANDLER)(
'    __in                 HANDLE      ClRegCtx,
'    __in                 HANDLE      ClIfcCtx,
'    __in                 ULONG       Event,      // See list below
'    __in                 HANDLE      SubCode,
'    __in                 ULONG       BufSize,
'    __in_bcount(BufSize) PVOID       Buffer
'    );

'SUB TCI_NOTIFY_HANDLER ( _
'   BYVAL ClRegCtx AS DWORD _
' , BYVAL ClIfcCtx AS DWORD _
' , BYVAL dwEevent AS DWORD _
' , BYVAL SubCode AS DWORD _
' , BYVAL BufSize AS DWORD _
' , BYVAL Buffer AS DWORD _
' )

'typedef
'VOID (CALLBACK * TCI_ADD_FLOW_COMPLETE_HANDLER)(
'    __in HANDLE   ClFlowCtx,
'    __in ULONG    Status
'    );

'SUB TCI_ADD_FLOW_COMPLETE_HANDLER ( _
'   BYVAL ClFlowCtx AS DWORD _
' , BYVAL dwStatus AS DWORD _
' )

'typedef
'VOID (CALLBACK * TCI_MOD_FLOW_COMPLETE_HANDLER)(
'    __in HANDLE   ClFlowCtx,
'    __in ULONG    Status
'    );

'SUB TCI_MOD_FLOW_COMPLETE_HANDLER ( _
'   BYVAL ClFlowCtx AS DWORD _
' , BYVAL dwStatus AS DWORD _
' )

'typedef
'VOID (CALLBACK * TCI_DEL_FLOW_COMPLETE_HANDLER)(
'    __in HANDLE   ClFlowCtx,
'    __in ULONG    Status
'    );

'SUB TCI_DEL_FLOW_COMPLETE_HANDLER ( _
'   BYVAL ClFlowCtx AS DWORD _
' , BYVAL dwStatus AS DWORD _
' )

' // Size = 16 bytes
TYPE TCI_CLIENT_FUNC_LIST DWORD
   ClNotifyHandler             AS DWORD   ' TCI_NOTIFY_HANDLER
   ClAddFlowCompleteHandler    AS DWORD   ' TCI_ADD_FLOW_COMPLETE_HANDLER
   ClModifyFlowCompleteHandler AS DWORD   ' TCI_MOD_FLOW_COMPLETE_HANDLER
   ClDeleteFlowCompleteHandler AS DWORD   ' TCI_DEL_FLOW_COMPLETE_HANDLER
END TYPE


'//
'// Network address descriptor
'//
' // Size = 16 bytes
TYPE ADDRESS_LIST_DESCRIPTOR DWORD
   MediaType   AS DWORD   ' ULONG
   AddressList AS NETWORK_ADDRESS_LIST
END TYPE


'//
'// An interface ID that is returned by the enumerator
'//
' // Size = 28 bytes
TYPE TC_IFC_DESCRIPTOR DWORD
   Length          AS DWORD          ' ULONG
   pInterfaceName  AS WSTRINGZ PTR   ' LPWSTR
   pInterfaceID    AS WSTRINGZ PTR   ' LPWSTR
   AddressListDesc AS ADDRESS_LIST_DESCRIPTOR
END TYPE


'//
'// This structure is returned by a QoS data provider in reply to
'// GUID_QOS_SUPPORTED query or with an interface UP notification
'//
' // Size = 544 bytes
TYPE TC_SUPPORTED_INFO_BUFFER QWORD FILL  ' Must be 8 byte aligned
   InstanceIDLength AS WORD   ' USHORT
   ' // device or interface ID
   InstanceID       AS WSTRINGZ * %MAX_STRING_LENGTH   ' WCHAR
   ' // the NET_LUID for the interface
   InterfaceLuid    AS QUAD   ' ULONG64
   ' // address list
   AddrListDesc     AS ADDRESS_LIST_DESCRIPTOR
END TYPE


'//
'// Filters are used to match packets. The Pattern field
'// indicates the values to which bits in corresponding
'// positions in candidate packets should be compared. The
'// Mask field indicates which bits are to be compared and
'// which bits are don't cares.
'//
'// Different filters can be submitted on the TCI interface.
'// The generic filter structure is defined to include an
'// AddressType, which indicates the specific type of filter to
'// follow.
'//

' // Size = 16 bytes
TYPE TC_GEN_FILTER DWORD
   AddressType AS WORD    ' USHORT // IP, IPX, etc.
   PatternSize AS DWORD   ' ULONG // byte count of the pattern
   Pattern     AS DWORD   ' PVOID // specific format, e.g. IP_PATTERN
   Mask        AS DWORD   ' PVOID // same type as Pattern
END TYPE


'//
'// A generic flow includes two flowspecs and a freeform
'// buffer which contains flow specific TC objects.
'//
' // Size = 76 bytes
TYPE TC_GEN_FLOW DWORD
   SendingFlowspec   AS FLOWSPEC
   ReceivingFlowspec AS FLOWSPEC
   TcObjectsLength   AS DWORD   ' ULONG // number of optional bytes
   TcObjects(0)      AS QOS_OBJECT_HDR
END TYPE


'//
'// Format of specific pattern or mask used by GPC for the IP protocol
'//

'typedef struct _IP_PATTERN {

'    ULONG       Reserved1;
'    ULONG       Reserved2;

'    ULONG       SrcAddr;
'    ULONG       DstAddr;

'    union {
'        struct { USHORT s_srcport,s_dstport; } S_un_ports;
'        struct { UCHAR s_type,s_code; USHORT filler; } S_un_icmp;
'        ULONG   S_Spi;
'    } S_un;

'    UCHAR       ProtocolId;
'    UCHAR       Reserved3[3];

'#define tcSrcPort S_un.S_un_ports.s_srcport
'#define tcDstPort S_un.S_un_ports.s_dstport
'#define tcIcmpType        S_un.S_un_icmp.s_type
'#define tcIcmpCode        S_un.S_un_icmp.s_code
'#define tcSpi             S_un.S_Spi

'} IP_PATTERN, *PIP_PATTERN;

' // Size = 4 bytes
TYPE S_un_ports BYTE
   s_srcport AS WORD   ' USHORT
   s_dstport AS WORD   ' USHORT
END TYPE

' // Size = 4 bytes
TYPE S_un_icmp BYTE
   s_type AS BYTE   ' UCHAR
   s_code AS BYTE   ' UCHAR
   filler AS WORD   ' USHORT
END TYPE

' // Size = 4 bytes
UNION IP_PATTERN_UNION BYTE
   S_un_ports
   S_un_icmp
   S_Spi AS DWORD   ' ULONG
END UNION

' // Size = 24 bytes
TYPE IP_PATTERN BYTE
   Reserved1    AS DWORD   ' ULONG
   Reserved2    AS DWORD   ' ULONG
   SrcAddr      AS DWORD   ' ULONG
   DstAddr      AS DWORD   ' ULONG
   IP_PATTERN_UNION
   ProtocolId   AS BYTE    ' UCHAR
   Reserved3(2) AS BYTE    ' UCHAR[3]
END TYPE

'//
'// Format of specific pattern or mask used by GPC for the IPX protocol
'//
'typedef struct _IPX_PATTERN {

'    struct {
'        ULONG   NetworkAddress;
'        UCHAR   NodeAddress[6];
'        USHORT  Socket;
'    } Src, Dest;

'} IPX_PATTERN, *PIPX_PATTERN;

' // Size = 12 bytes
TYPE IPX_PATTERN_STRUCT BYTE
   NetworkAddress AS DWORD   ' ULONG
   NodeAddress(5) AS BYTE    ' UCHAR[6]
   Socket         AS WORD    ' USHORT
END TYPE

' // Size = 24 bytes
TYPE IPX_PATTERN BYTE
   Src  AS IPX_PATTERN_STRUCT
   Dest AS IPX_PATTERN_STRUCT
END TYPE


'//
'// The enumeration buffer is the flow parameters + a list of filters
'//
' // Size = 548 bytes
TYPE ENUMERATION_BUFFER DWORD FILL
   Length           AS DWORD   ' ULONG
   OwnerProcessId   AS DWORD   ' ULONG
   FlowNameLength   AS WORD   ' USHORT
   FlowName         AS WSTRINGZ * %MAX_STRING_LENGTH   ' WCHAR
   pFlow            AS TC_GEN_FLOW PTR   ' PTC_GEN_FLOW
   NumberOfFilters  AS DWORD   ' ULONG
   GenericFilter(0) AS TC_GEN_FILTER   ' // one for each filter
END TYPE

'//---------------------------------------------------------------------------
'//
'// Interface Function Definitions
'//

DECLARE FUNCTION TcRegisterClient IMPORT "Traffic.dll" ALIAS "TcRegisterClient" ( _
   BYVAL TciVersion AS DWORD _                          ' __in ULONG TciVersion
 , BYVAL ClRegCtx AS DWORD _                            ' __in HANDLE ClRegCtx
 , BYREF ClientHandlerList AS TCI_CLIENT_FUNC_LIST _    ' __in PTCI_CLIENT_FUNC_LIST ClientHandlerList
 , BYREF pClientHandle AS DWORD _                       ' __out PHANDLE pClientHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcEnumerateInterfaces IMPORT "Traffic.dll" ALIAS "TcEnumerateInterfaces" ( _
   BYVAL ClientHandle AS DWORD _                        ' __in HANDLE ClientHandle
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF InterfaceBuffer AS TC_IFC_DESCRIPTOR _         ' __out PTC_IFC_DESCRIPTOR InterfaceBuffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcOpenInterfaceA IMPORT "Traffic.dll" ALIAS "TcOpenInterfaceA" ( _
   BYREF pInterfaceName AS ASCIIZ _                     ' __in LPSTR pInterfaceName
 , BYVAL ClientHandle AS DWORD _                        ' __in HANDLE ClientHandle
 , BYVAL ClIfcCtx AS DWORD _                            ' __in HANDLE ClIfcCtx
 , BYREF pIfcHandle AS DWORD _                          ' __out PHANDLE pIfcHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcOpenInterfaceW IMPORT "Traffic.dll" ALIAS "TcOpenInterfaceW" ( _
   BYREF pInterfaceName AS WSTRINGZ _                   ' __in LPWSTR pInterfaceName
 , BYVAL ClientHandle AS DWORD _                        ' __in HANDLE ClientHandle
 , BYVAL ClIfcCtx AS DWORD _                            ' __in HANDLE ClIfcCtx
 , BYREF pIfcHandle AS DWORD _                          ' __out PHANDLE pIfcHandle
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO TcOpenInterface = TcOpenInterfaceW
#ELSE
   MACRO TcOpenInterface = TcOpenInterfaceA
#ENDIF

DECLARE FUNCTION TcCloseInterface IMPORT "Traffic.dll" ALIAS "TcCloseInterface" ( _
   BYVAL IfcHandle AS DWORD _                           ' __in HANDLE IfcHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcQueryInterface IMPORT "Traffic.dll" ALIAS "TcQueryInterface" ( _
   BYVAL IfcHandle AS DWORD _                           ' __in HANDLE IfcHandle
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYVAL NotifyChange AS BYTE _                         ' __in BOOLEAN NotifyChange
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcSetInterface IMPORT "Traffic.dll" ALIAS "TcSetInterface" ( _
   BYVAL IfcHandle AS DWORD _                           ' __in HANDLE IfcHandle
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcQueryFlowA IMPORT "Traffic.dll" ALIAS "TcQueryFlowA" ( _
   BYREF pFlowName AS ASCIIZ _                          ' __in LPSTR pFlowName
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcQueryFlowW IMPORT "Traffic.dll" ALIAS "TcQueryFlowW" ( _
   BYREF pFlowName AS WSTRINGZ _                        ' __in LPWSTR pFlowName
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO TcQueryFlow = TcQueryFlowW
#ELSE
   MACRO TcQueryFlow = TcQueryFlowA
#ENDIF

DECLARE FUNCTION TcSetFlowA IMPORT "Traffic.dll" ALIAS "TcSetFlowA" ( _
   BYREF pFlowName AS ASCIIZ _                          ' __in LPSTR pFlowName
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcSetFlowW IMPORT "Traffic.dll" ALIAS "TcSetFlowW" ( _
   BYREF pFlowName AS WSTRINGZ _                        ' __in LPWSTR pFlowName
 , BYREF pGuidParam AS GUID _                           ' __in LPGUID pGuidParam
 , BYREF pBufferSize AS DWORD _                         ' __in_out PULONG pBufferSize
 , BYREF Buffer AS ANY _                                ' __out PVOID Buffer
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO TcSetFlow = TcSetFlowW
#ELSE
   MACRO TcSetFlow = TcSetFlowA
#ENDIF

DECLARE FUNCTION TcAddFlow IMPORT "Traffic.dll" ALIAS "TcAddFlow" ( _
   BYVAL IfcHandle AS DWORD _                           ' __in HANDLE IfcHandle
 , BYVAL ClFlowCtx AS DWORD _                           ' __in HANDLE ClFlowCtx
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
 , BYREF pGenericFlow AS TC_GEN_FLOW _                  ' __in PTC_GEN_FLOW pGenericFlow
 , BYREF pFlowHandle AS DWORD _                         ' __out PHANDLE pFlowHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcGetFlowNameA IMPORT "Traffic.dll" ALIAS "TcGetFlowNameA" ( _
   BYVAL FlowHandle AS DWORD _                          ' __in HANDLE FlowHandle
 , BYVAL StrSize AS DWORD _                             ' __in ULONG StrSize
 , BYREF pFlowName AS ASCIIZ _                          ' __out LPSTR pFlowName
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcGetFlowNameW IMPORT "Traffic.dll" ALIAS "TcGetFlowNameW" ( _
   BYVAL FlowHandle AS DWORD _                          ' __in HANDLE FlowHandle
 , BYVAL StrSize AS DWORD _                             ' __in ULONG StrSize
 , BYREF pFlowName AS WSTRINGZ _                        ' __out LPWSTR pFlowName
 ) AS DWORD                                             ' ULONG

#IF %DEF(%UNICODE)
   MACRO TcGetFlowName = TcGetFlowNameW
#ELSE
   MACRO TcGetFlowName = TcGetFlowNameA
#ENDIF

DECLARE FUNCTION TcModifyFlow IMPORT "Traffic.dll" ALIAS "TcModifyFlow" ( _
   BYVAL FlowHandle AS DWORD _                          ' __in HANDLE FlowHandle
 , BYREF pGenericFlow AS TC_GEN_FLOW _                  ' __in PTC_GEN_FLOW pGenericFlow
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcAddFilter IMPORT "Traffic.dll" ALIAS "TcAddFilter" ( _
   BYVAL FlowHandle AS DWORD _                          ' __in HANDLE FlowHandle
 , BYREF pGenericFilter AS TC_GEN_FILTER _              ' __in PTC_GEN_FILTER pGenericFilter
 , BYREF pFilterHandle AS DWORD _                       ' __out PHANDLE pFilterHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcDeregisterClient IMPORT "Traffic.dll" ALIAS "TcDeregisterClient" ( _
   BYVAL ClientHandle AS DWORD _                        ' __in HANDLE ClientHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcDeleteFlow IMPORT "Traffic.dll" ALIAS "TcDeleteFlow" ( _
   BYVAL FlowHandle AS DWORD _                          ' __in HANDLE FlowHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcDeleteFilter IMPORT "Traffic.dll" ALIAS "TcDeleteFilter" ( _
   BYVAL FilterHandle AS DWORD _                        ' __in HANDLE FilterHandle
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION TcEnumerateFlows IMPORT "Traffic.dll" ALIAS "TcEnumerateFlows" ( _
   BYVAL IfcHandle AS DWORD _                           ' __in HANDLE IfcHandle
 , BYREF pEnumHandle AS DWORD _                         ' __in_out PHANDLE pEnumHandle
 , BYREF pFlowCount AS DWORD _                          ' __in_out PULONG pFlowCount
 , BYREF pBufSize AS DWORD _                            ' __in_out PULONG pBufSize
 , BYREF Buffer AS ENUMERATION_BUFFER _                 ' __out ENUMERATION_BUFFER Buffer
 ) AS DWORD                                             ' ULONG
