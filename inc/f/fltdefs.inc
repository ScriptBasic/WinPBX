' ########################################################################################
' Microsoft Windows
' File: fltdefs.inc
' Contents: Definitions for the WIN32 filter APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FLTDEFS_INC = 1

'typedef PVOID  FILTER_HANDLE, *PFILTER_HANDLE;
'typedef PVOID  INTERFACE_HANDLE, *PINTERFACE_HANDLE;

' enum GLOBAL_FILTER
%GF_FRAGMENTS  = 2   ' // check consistency of fragments
%GF_STRONGHOST = 8   ' // check destination address of input frames
%GF_FRAGCACHE  = 9   ' // check fragments from cache

' enum PFFORWARD_ACTION
%PF_ACTION_FORWARD = 0
%PF_ACTION_DROP    = 1

' enum PFADDRESSTYPE
%PF_IPV4 = 0
%PF_IPV6 = 1

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The constants that should be used to set up the FILTER_INFO_STRUCTURE    //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'#define FILTER_PROTO(ProtoId)   MAKELONG(MAKEWORD((ProtoId),0x00),0x00000)
MACRO FILTER_PROTO(ProtoId) = MAK(LONG,MAK(WORD,ProtoID,&H00),&H00000)

'#define FILTER_PROTO_ANY        FILTER_PROTO(0x00)
'#define FILTER_PROTO_ICMP       FILTER_PROTO(0x01)
'#define FILTER_PROTO_TCP        FILTER_PROTO(0x06)
'#define FILTER_PROTO_UDP        FILTER_PROTO(0x11)

%FILTER_PROTO_ANY  = &H00&
%FILTER_PROTO_ICMP = &H01&
%FILTER_PROTO_TCP  = &H06&
%FILTER_PROTO_UDP  = &H11&

'#define FILTER_TCPUDP_PORT_ANY  (WORD)0x0000
%FILTER_TCPUDP_PORT_ANY = &H0000??

'#define FILTER_ICMP_TYPE_ANY    (BYTE)0xff
'#define FILTER_ICMP_CODE_ANY    (BYTE)0xff
%FILTER_ICMP_TYPE_ANY = &Hff?
%FILTER_ICMP_CODE_ANY = &Hff?

' // Size = 44 bytes
TYPE PF_FILTER_DESCRIPTOR DWORD FILL
   dwFilterFlags     AS DWORD      ' DWORD // see below
   dwRule            AS DWORD      ' DWORD // copied into the log when appropriate
   pfatType          AS LONG       ' PFADDRESSTYPE
   SrcAddr           AS BYTE PTR   ' PBYTE
   SrcMask           AS BYTE PTR   ' PBYTE
   DstAddr           AS BYTE PTR   ' PBYTE
   DstMask           AS BYTE PTR   ' PBYTE
   dwProtocol        AS DWORD      ' DWORD
   fLateBound        AS DWORD      ' DWORD
   wSrcPort          AS WORD       ' WORD
   wDstPort          AS WORD       ' WORD
   wSrcPortHighRange AS WORD       ' WORD
   wDstPortHighRange AS WORD       ' WORD
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Structure for PfGetInterfaceStatistics                                   //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

' // Size = 48 bytes
TYPE PF_FILTER_STATS DWORD FILL
   dwNumPacketsFiltered AS DWORD                  ' DWORD
   info                 AS PF_FILTER_DESCRIPTOR
END TYPE

' // Size = 120 bytes
TYPE PF_INTERFACE_STATS QWORD FILL
   pvDriverContext  AS DWORD             ' PVOID
   dwFlags          AS DWORD             ' DWORD // none as yet (28-Sept-1997)
   dwInDrops        AS DWORD             ' DWORD
   dwOutDrops       AS DWORD             ' DWORD
   eaInAction       AS LONG              ' PFFORWARD_ACTION
   eaOutAction      AS LONG              ' PFFORWARD_ACTION
   dwNumInFilters   AS DWORD             ' DWORD
   dwNumOutFilters  AS DWORD             ' DWORD
   dwFrag           AS DWORD             ' DWORD
   dwSpoof          AS DWORD             ' DWORD
   dwReserved1      AS DWORD             ' DWORD
   dwReserved2      AS DWORD             ' DWORD
   liSYN            AS QUAD              ' LARGE_INTEGER
   liTotalLogged    AS QUAD              ' LARGE_INTEGER
   dwLostLogEntries AS DWORD             ' DWORD
   FilterInfo(0)    AS PF_FILTER_STATS   ' PF_FILTER_STATS FilterInfo[1];
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The number of bytes starting at SrcAddr. If you add something to the     //
'// structure make sure this remains valid                                   //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'#define FILTERSIZE                                      \
'    (sizeof(PF_FILTER_DESCRIPTOR) -                     \
'     (DWORD)(&((PPF_FILTER_DESCRIPTOR)0)->SrcAddr))


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Flags for PF_FILTER_DESCRIPTOR                                           //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

'//
'// Disallows incoming SYN
'//

%FD_FLAGS_NOSYN = &H1???

'//
'// All legal flags
'//

%FD_FLAGS_ALLFLAGS = %FD_FLAGS_NOSYN


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Late bound defs. Go in fLateBound in a PF_FILTER_DESCRIPTOR and          //
'// describe which other fields of the filter are affected  by a             //
'// PfRebindFilters call. In general such filters are on  WAN interfaces     //
'// where one or the other address may change as the connection is           //
'// reconnected.                                                             //
'// The assumption is that such interfaces HAVE ONLY ONE ADDRESS.            //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////


%LB_SRC_ADDR_USE_SRCADDR_FLAG = &H00000001???
%LB_SRC_ADDR_USE_DSTADDR_FLAG = &H00000002???
%LB_DST_ADDR_USE_SRCADDR_FLAG = &H00000004???
%LB_DST_ADDR_USE_DSTADDR_FLAG = &H00000008???
%LB_SRC_MASK_LATE_FLAG        = &H00000010???
%LB_DST_MASK_LATE_FLAG        = &H00000020???

' // Size = 12 bytes
TYPE PF_LATEBIND_INFO DWORD FILL
   SrcAddr AS BYTE PTR   ' PBYTE
   DstAddr AS BYTE PTR   ' PBYTE
   Mask    AS BYTE PTR   ' PBYTE
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The format of a logged frame and defs for it.                            //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

' enum PFFRAMETYPE
%PFFT_FILTER = 1                    ' // a filter violation
%PFFT_FRAG   = 2                    ' // bad fragment
%PFFT_SPOOF  = 3                    ' // strong host failure

' // Size = 40 bytes
TYPE PFLOGFRAME   ' Must be 8 bytes aligned
   Timestamp             AS QUAD    ' LARGE_INTEGER
   pfeTypeOfFrame        AS LONG    ' PFFRAMETYPE
   dwTotalSizeUsed       AS DWORD   ' DWORD // used to find the next frame
   dwFilterRule          AS DWORD   ' DWORD // from the filter
   wSizeOfAdditionalData AS WORD    ' WORD
   wSizeOfIpHeader       AS WORD    ' WORD
   dwInterfaceName       AS DWORD   ' DWORD // the name of the interface
   dwIPIndex             AS DWORD   ' DWORD
   bPacketData(7)        AS BYTE    ' BYTE bPacketData[1] // the frame. wsizeOfIpHeader
                                    ' // and wsizeOfAdditionalData describe this
   ' // Note: We are using bPacketData(7) instead of bPacketData(0) to keep 8 byte alignment
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Error codes. These extend the WIN32 errors by having errors specific to  //
'// these APIs. Besides these errors, the APIs may return any of the WIN32   //
'// errors.                                                                  //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////


%ERROR_BASE = 23000

%PFERROR_NO_PF_INTERFACE    = %ERROR_BASE + 0   ' // never returned.
%PFERROR_NO_FILTERS_GIVEN   = %ERROR_BASE + 1
%PFERROR_BUFFER_TOO_SMALL   = %ERROR_BASE + 2
%ERROR_IPV6_NOT_IMPLEMENTED = %ERROR_BASE + 3


'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// The API prototypes                                                       //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION PfCreateInterface IMPORT "Iphlpapi.dll" ALIAS "PfCreateInterface" ( _
   BYVAL dwName AS DWORD _                              ' __in  DWORD            dwName
 , BYVAL inAction AS LONG _                             ' __in  PFFORWARD_ACTION inAction
 , BYVAL outAction AS LONG _                            ' __in  PFFORWARD_ACTION outAction
 , BYVAL bUseLog AS LONG _                              ' __in  BOOL             bUseLog
 , BYVAL bMustBeUnique AS LONG _                        ' __in  BOOL             bMustBeUnique
 , BYREF ppInterface AS DWORD _                         ' __out INTERFACE_HANDLE *ppInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfDeleteInterface IMPORT "Iphlpapi.dll" ALIAS "PfDeleteInterface" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE pInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfAddFiltersToInterface IMPORT "Iphlpapi.dll" ALIAS "PfAddFiltersToInterface" ( _
   BYVAL ih AS DWORD _                                  ' __in  INTERFACE_HANDLE      ih
 , BYVAL cInFilters AS DWORD _                          ' __in  DWORD                 cInFilters
 , BYREF pfiltIn AS PF_FILTER_DESCRIPTOR _              ' __in  PPF_FILTER_DESCRIPTOR pfiltIn
 , BYVAL cOutFilters AS DWORD _                         ' __in  DWORD                 cOutFilters
 , BYREF pfiltOut AS PF_FILTER_DESCRIPTOR _             ' __in  PPF_FILTER_DESCRIPTOR pfiltOut
 , BYREF pfHandle AS DWORD _                            ' __out PFILTER_HANDLE        pfHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfRemoveFiltersFromInterface IMPORT "Iphlpapi.dll" ALIAS "PfRemoveFiltersFromInterface" ( _
   BYVAL ih AS DWORD _                                  ' __in  INTERFACE_HANDLE      ih
 , BYVAL cInFilters AS DWORD _                          ' __in  DWORD                 cInFilters
 , BYREF pfiltIn AS PF_FILTER_DESCRIPTOR _              ' __in  PPF_FILTER_DESCRIPTOR pfiltIn
 , BYVAL cOutFilters AS DWORD _                         ' __in  DWORD                 cOutFilters
 , BYREF pfiltOut AS PF_FILTER_DESCRIPTOR _             ' __in  PPF_FILTER_DESCRIPTOR pfiltOut
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfRemoveFilterHandles IMPORT "Iphlpapi.dll" ALIAS "PfRemoveFilterHandles" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE   pInterface
 , BYVAL cFilters AS DWORD _                            ' __in  DWORD              cFilters
 , BYREF pvHandles AS DWORD _                           ' __in  PFILTER_HANDLE     pvHandles
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfUnBindInterface IMPORT "Iphlpapi.dll" ALIAS "PfUnBindInterface" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE   pInterface
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfBindInterfaceToIndex IMPORT "Iphlpapi.dll" ALIAS "PfBindInterfaceToIndex" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYVAL dwIndex AS DWORD _                             ' __in  DWORD               dwIndex
 , BYVAL pfatLinkType AS LONG _                         ' __in  PFADDRESSTYPE       pfatLinkType
 , BYVAL LinkIPAddress AS BYTE PTR _                    ' __in  PBYTE               LinkIPAddress
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfBindInterfaceToIPAddress IMPORT "Iphlpapi.dll" ALIAS "PfBindInterfaceToIPAddress" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYVAL pfatType AS LONG _                             ' __in  PFADDRESSTYPE       pfatType
 , BYVAL IPAddress AS BYTE PTR _                        ' __in  PBYTE               IPAddress
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfRebindFilters IMPORT "Iphlpapi.dll" ALIAS "PfRebindFilters" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYREF pLateBindInfo AS PF_LATEBIND_INFO _            ' __in  PPF_LATEBIND_INFO   pLateBindInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfAddGlobalFilterToInterface IMPORT "Iphlpapi.dll" ALIAS "PfAddGlobalFilterToInterface" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYVAL gfFilter AS LONG _                             ' __in  GLOBAL_FILTER       gfFilter
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION PfRemoveGlobalFilterFromInterface IMPORT "Iphlpapi.dll" ALIAS "PfRemoveGlobalFilterFromInterface" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYVAL gfFilter AS LONG _                             ' __in  GLOBAL_FILTER       gfFilter
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Log APIs. Note that there is at most one log and it must be created      //
'// before any interface needing it is created. There is no way to set a     //
'// log onto an existing interface. The log can be applied to any or all of  //
'// the interfaces.                                                          //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION PfMakeLog IMPORT "Iphlpapi.dll" ALIAS "PfMakeLog" ( _
   BYVAL hEvent AS DWORD _                              ' __in  HANDLE  hEvent
 ) AS DWORD                                             ' DWORD

'//
'// Provide a buffer, and notification parameters, and get back
'// the old buffer and status.
'//

DECLARE FUNCTION PfSetLogBuffer IMPORT "Iphlpapi.dll" ALIAS "PfSetLogBuffer" ( _
   BYVAL pbBuffer AS BYTE PTR _                         ' __in  PBYTE   pbBuffer
 , BYVAL dwSize AS DWORD _                              ' __in  DWORD   dwSize
 , BYVAL dwThreshold AS DWORD _                         ' __in  DWORD   dwThreshold
 , BYVAL dwEntries AS DWORD _                           ' __in  DWORD   dwEntries
 , BYREF pdwLoggedEntries AS DWORD _                    ' __out PDWORD  pdwLoggedEntries
 , BYREF pdwLostEntries AS DWORD _                      ' __out PDWORD  pdwLostEntries
 , BYREF pdwSizeUsed AS DWORD _                         ' __out PDWORD  pdwSizeUsed
 ) AS DWORD                                             ' DWORD

'//
'// Doing this will disable the log on any of the interfaces. But if
'// an interface was created with the log, the actual log will not be
'// completely deleted until that interface is deleted. This is a small
'// point, but it might explain a mystery or two.
'//

DECLARE FUNCTION PfDeleteLog IMPORT "Iphlpapi.dll" ALIAS "PfDeleteLog" ( _
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Get statistics. Note pdwBufferSize in an IN/OUT parameter. If            //
'// ERROR_INSUFFICIENT_BUFFER is returned, the common statistics are         //
'// available and the correct byte count is in *pdwBufferSize. If only the   //
'// interface statistics are needed, provide a buffer of size                //
'// PF_INTERFACE_STATS only.                                                 //
'// If the filter descriptions are also needed, then supply a large buffer,  //
'// or use the returned count from the first call to allocate a buffer of    //
'// sufficient size. Note that for a shared interface, this second call may  //
'// fail with ERROR_INSUFFICIENT_BUFFER. This can happen if the other        //
'// sharers add filters in the interim. This should not happen for a UNIQUE  //
'// interface.                                                               //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION PfGetInterfaceStatistics IMPORT "Iphlpapi.dll" ALIAS "PfGetInterfaceStatistics" ( _
   BYVAL pInterface AS DWORD _                          ' __in  INTERFACE_HANDLE    pInterface
 , BYREF ppfStats AS PF_INTERFACE_STATS _               ' __out PPF_INTERFACE_STATS ppfStats
 , BYREF pdwBufferSize AS DWORD _                       ' __out PDWORD              pdwBufferSize
 , BYVAL fResetCounters AS LONG _                       ' __in  BOOL                fResetCounters
 ) AS DWORD                                             ' DWORD

'//////////////////////////////////////////////////////////////////////////////
'//                                                                          //
'// Test a packet.                                                           //
'// This call will evaluate the packet against the given interfaces          //
'// and return the filtering action.                                         //
'//                                                                          //
'//////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION PfTestPacket IMPORT "Iphlpapi.dll" ALIAS "PfTestPacket" ( _
   BYVAL pInInterface AS DWORD _                        ' __in  INTERFACE_HANDLE   pInInterface  OPTIONAL
 , BYVAL pOutInterface AS DWORD _                       ' __In  INTERFACE_HANDLE   pOutInterface OPTIONAL
 , BYVAL cBytes AS DWORD _                              ' __in  DWORD              cBytes
 , BYVAL pbPacket AS BYTE PTR _                         ' __in  PBYTE              pbPacket
 , BYREF ppAction AS LONG _                             ' __out PPFFORWARD_ACTION  ppAction
 ) AS DWORD                                             ' DWORD
