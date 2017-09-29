' ########################################################################################
' Microsoft Windows
' File: Mgm.inc
' Contents: Data structures and entry points into MGM
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MGM_INC = 1

#INCLUDE ONCE "ipmib.inc"

'//----------------------------------------------------------------------------
'//
'// typedefs for callback interface
'//
'//----------------------------------------------------------------------------


'//
'// MGM_IF_ENTRY
'//
'// structure used in MGM_CREATION_ALERT_CALLBACK.  In the process of
'// creating an MFE the routing protocol needs to enable/disable
'// multicast forwarding on each interface
'//

' // Size = 16 bytes
TYPE MGM_IF_ENTRY DWORD
   dwIfIndex       AS DWORD   ' DWORD
   dwIfNextHopAddr AS DWORD   ' DWORD
   bIGMP           AS LONG    ' BOOL
   bIsEnabled      AS LONG    ' BOOL
END TYPE

'//----------------------------------------------------------------------------
'//
'// Callbacks into routing protocols
'//
'//----------------------------------------------------------------------------

'//
'// call into a routing protocol to perform RPF check.
'//
'// Invoked in the context of MgmNewPacketReceived into protocol component
'// owning the incoming interface.
'//

'typedef DWORD
'(*PMGM_RPF_CALLBACK)(
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN  OUT         PDWORD          pdwInIfIndex,
'    IN  OUT         PDWORD          pdwInIfNextHopAddr,
'    IN  OUT         PDWORD          pdwUpStreamNbr,
'    IN              DWORD           dwHdrSize,
'    IN              PBYTE           pbPacketHdr,
'    IN  OUT         PBYTE           pbRoute
');

'FUNCTION MGM_RPF_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in    DWORD  dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in    DWORD  dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in    DWORD  dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in    DWORD  dwGroupMask
' , BYREF pdwInIfIndex AS DWORD _                        ' __inout PDWORD pdwInIfIndex
' , BYREF pdwInIfNextHopAddr AS DWORD _                  ' __inout PDWORD pdwInIfNextHopAddr
' , BYREF pdwUpStreamNbr AS DWORD _                      ' __inout PDWORD pdwUpStreamNbr
' , BYVAL dwHdrSize AS DWORD _                           ' __in    DWORD  dwHdrSize
' , BYVAL pbPacketHdr AS BYTE PTR _                      ' __in    PBYTE  pbPacketHdr
' , BYVAL pbRoute AS BYTE PTR _                          ' __inout PBYTE  pbRoute
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into a routing protocol to determine the subset of interfaces
'// (owned by the routing protocol) on which a multicast packet from a
'// "new" source should be forwarded.
'//
'// Invoked in the context of MgmNewPacketReceived into all
'// routing protocols that have outgoing interfaces for this source.
'//

'typedef
'DWORD (*PMGM_CREATION_ALERT_CALLBACK)(
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN              DWORD           dwInIfIndex,
'    IN              DWORD           dwInIfNextHopAddr,
'    IN              DWORD           dwIfCount,
'    IN  OUT         PMGM_IF_ENTRY   pmieOutIfList
');

'FUNCTION MGM_CREATION_ALERT_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in    DWORD  dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in    DWORD  dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in    DWORD  dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in    DWORD  dwGroupMask
' , BYVAL dwInIfIndex AS DWORD _                         ' __in    DWORD  dwInIfIndex
' , BYVAL dwInIfNextHopAddr AS DWORD _                   ' __in    DWORD  dwInIfNextHopAddr
' , BYVAL dwIfCount AS DWORD _                           ' __in    DWORD  dwIfCount
' , BYREF pmieOutIfList AS MGM_IF_ENTRY _                ' __inout PMGM_IF_ENTRY pmieOutIfList
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into routing protocol to notify protocol that an interface has
'// been deleted from the outgoing interface list of a group entry / MFE
'//
'// invoked in the context of MgmDeleteMembershipEntry()
'//

'typedef
'DWORD (*PMGM_PRUNE_ALERT_CALLBACK)(
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr,
'    IN              BOOL            bMemberDelete,
'    IN  OUT         PDWORD          pdwTimeout
');

'FUNCTION MGM_PRUNE_ALERT_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in    DWORD  dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in    DWORD  dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in    DWORD  dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in    DWORD  dwGroupMask
' , BYVAL dwIfIndex AS DWORD _                           ' __in    DWORD  dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in    DWORD  dwIfNextHopAddr
' , BYVAL bMemberDelete AS LONG _                        ' __in    BOOL   bMemberDelete
' , BYREF pdwTimeout AS DWORD _                          ' __inout PDWORD pdwTimeout
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into routing protocol to notify protocol that an interface has
'// been added to the outgoing interface list of a group entry / MFE
'//
'// invoked in the context of MgmAddMembershipEntry()
'//

'typedef
'DWORD (*PMGM_JOIN_ALERT_CALLBACK)(
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN              BOOL            bMemberUpdate
');

'FUNCTION MGM_JOIN_ALERT_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD  dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in DWORD  dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD  dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in DWORD  dwGroupMask
' , BYVAL bMemberUpdate AS LONG _                        ' __in BOOL   bMemberUpdate
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into routing protocol to notify protocol that a packet
'// has been received from a (source, group) on a wrong interface
'//

'typedef
'DWORD (*PMGM_WRONG_IF_CALLBACK)(
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr,
'    IN              DWORD           dwHdrSize,
'    IN              PBYTE           pbPacketHdr
');

'FUNCTION MGM_WRONG_IF_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD dwSourceAddr
' , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD dwGroupAddr
' , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
' , BYVAL dwHdrSize AS DWORD _                           ' __in DWORD dwHdrSize
' , BYVAL pbPacketHdr AS BYTE PTR _                      ' __in PBYTE pbPacketHdr
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into routing protocol to notify protocol that IGMP needs to add
'// an interface to the outgoing interface list of a group entry / MFE
'//
'// invoked in the context of MgmLocalGroupJoin()
'//

'typedef DWORD
'(*PMGM_LOCAL_JOIN_CALLBACK) (
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr
');

'FUNCTION MGM_LOCAL_JOIN_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in DWORD dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in DWORD dwGroupMask
' , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into routing protocol to notify protocol that IGMP needs to
'// delete an interface to the outgoing interface list of a group
'// entry / MFE
'//
'// invoked in the context of MgmLocalGroupJoin()
'//

'typedef DWORD
'(*PMGM_LOCAL_LEAVE_CALLBACK) (
'    IN              DWORD           dwSourceAddr,
'    IN              DWORD           dwSourceMask,
'    IN              DWORD           dwGroupAddr,
'    IN              DWORD           dwGroupMask,
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr
');

'FUNCTION MGM_LOCAL_LEAVE_CALLBACK ( _
'   BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD dwSourceAddr
' , BYVAL dwSourceMask AS DWORD _                        ' __in DWORD dwSourceMask
' , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD dwGroupAddr
' , BYVAL dwGroupMask AS DWORD _                         ' __in DWORD dwGroupMask
' , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into IGMP to notify it that a protocol is taking or
'// releasing ownership of an interface that has IGMP enabled on it.
'//
'// When this callback is invoked IGMP should stop adding/deleting
'// group memberships on the specified interface.
'//

'typedef DWORD
'(*PMGM_DISABLE_IGMP_CALLBACK) (
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr
');

'FUNCTION MGM_DISABLE_IGMP_CALLBACK ( _
'   BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//
'// call into IGMP to notify it that a protocol has finished taking
'// or releasing ownership of an interface.
'//
'// When this callback is invoked IGMP should add all its group memberships
'// on the interface.
'//

'typedef DWORD
'(*PMGM_ENABLE_IGMP_CALLBACK) (
'    IN              DWORD           dwIfIndex,
'    IN              DWORD           dwIfNextHopAddr
');

'FUNCTION MGM_ENABLE_IGMP_CALLBACK ( _
'   BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
' , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
' ) AS DWORD                                             ' DWORD
'END FUNCTION

'//----------------------------------------------------------------------------
'//
'// typedefs for MGM API interface
'//
'//----------------------------------------------------------------------------


'//
'// ROUTING_PROTOCOL_CONFIG
'//
'// routing protocol configuration that is passed to MGM at registration.
'//
'//
'// Callbacks into routing protocols
'//

' // Size = 40 bytes
TYPE ROUTING_PROTOCOL_CONFIG DWORD
   dwCallbackFlags          AS DWORD   ' DWORD
   pfnRpfCallback           AS DWORD   ' PMGM_RPF_CALLBACK
   pfnCreationAlertCallback AS DWORD   ' PMGM_CREATION_ALERT_CALLBACK
   pfnPruneAlertCallback    AS DWORD   ' PMGM_PRUNE_ALERT_CALLBACK
   pfnJoinAlertCallback     AS DWORD   ' PMGM_JOIN_ALERT_CALLBACK
   pfnWrongIfCallback       AS DWORD   ' PMGM_WRONG_IF_CALLBACK
   ' // callbacks into Routing protocols
   pfnLocalJoinCallback     AS DWORD   ' PMGM_LOCAL_JOIN_CALLBACK
   pfnLocalLeaveCallback    AS DWORD   ' PMGM_LOCAL_LEAVE_CALLBACK
   ' // callbacks into IGMP
   pfnDisableIgmpCallback   AS DWORD   ' PMGM_DISABLE_IGMP_CALLBACK
   pfnEnableIgmpCallback    AS DWORD   ' PMGM_ENABLE_IGMP_CALLBACK
END TYPE


'//
'// MGM_ENUM_TYPES
'//
'// Enumeration types to be specified when the
'//

' enum MGM_ENUM_TYPES
%ANY_SOURCE  = 0                   ' // enumerate group entries with
                                   ' // atleast one source
%ALL_SOURCES = 1                   ' // enumerate all source entries
                                   ' // for a group entry


'//
'// SOURCE_GROUP_ENTRY
'//
'// (S, G) entry that is returned by the group entry enumeration API.
'//

' // Size = 16 bytes
TYPE SOURCE_GROUP_ENTRY DWORD
   dwSourceAddr AS DWORD   ' DWORD
   dwSourceMask AS DWORD   ' DWORD
   dwGroupAddr  AS DWORD   ' DWORD
   dwGroupMask  AS DWORD   ' DWORD
END TYPE


'//----------------------------------------------------------------------------
'//
'// Entry points into MGM.
'//
'//----------------------------------------------------------------------------

'//============================================================================
'// Routing protocol registration / de-registration API
'//============================================================================

DECLARE FUNCTION MgmRegisterMProtocol IMPORT "Rtm.dll" ALIAS "MgmRegisterMProtocol" ( _
   BYREF prpiInfo AS ROUTING_PROTOCOL_CONFIG _          ' __in PROUTING_PROTOCOL_CONFIG prpiInfo
 , BYVAL dwProtocolId AS DWORD _                        ' __in DWORD dwProtocolId
 , BYVAL dwComponentId AS DWORD _                       ' __in DWORD dwComponentId
 , BYREF phProtocol AS DWORD _                          ' __out HANDLE * phProtocol
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmDeRegisterMProtocol IMPORT "Rtm.dll" ALIAS "MgmDeRegisterMProtocol" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 ) AS DWORD                                             ' DWORD

'//============================================================================
'// Interface ownership API
'//============================================================================

DECLARE FUNCTION MgmTakeInterfaceOwnership IMPORT "Rtm.dll" ALIAS "MgmTakeInterfaceOwnership" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
 , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmReleaseInterfaceOwnership IMPORT "Rtm.dll" ALIAS "MgmReleaseInterfaceOwnership" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
 , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGetProtocolOnInterface IMPORT "Rtm.dll" ALIAS "MgmGetProtocolOnInterface" ( _
   BYVAL dwIfIndex AS DWORD _                           ' __in DWORD dwIfIndex
 , BYVAL dwIfNextHopAddr AS DWORD _                     ' __in DWORD dwIfNextHopAddr
 , BYREF pdwIfProtocolId AS DWORD _                     ' __inout PDWORD pdwIfProtocolId
 , BYREF pdwIfComponentId AS DWORD _                    ' __inout PDWORD pdwIfComponentId
 ) AS DWORD                                             ' DWORD

'//============================================================================
'// Group membership manipulation API. (addition / deletion )
'//============================================================================

%MGM_JOIN_STATE_FLAG    = &H00000001???
%MGM_FORWARD_STATE_FLAG = &H00000002???

DECLARE FUNCTION MgmAddGroupMembershipEntry IMPORT "Rtm.dll" ALIAS "MgmAddGroupMembershipEntry" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD  dwSourceAddr
 , BYVAL dwSourceMask AS DWORD _                        ' __in DWORD  dwSourceMask
 , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD  dwGroupAddr
 , BYVAL dwGroupMask AS DWORD _                         ' __in DWORD  dwGroupMask
 , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD  dwIfIndex
 , BYVAL dwIfNextHopIPAddr AS DWORD _                   ' __in DWORD  dwIfNextHopIPAddr
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmDeleteGroupMembershipEntry IMPORT "Rtm.dll" ALIAS "MgmDeleteGroupMembershipEntry" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYVAL dwSourceAddr AS DWORD _                        ' __in DWORD  dwSourceAddr
 , BYVAL dwSourceMask AS DWORD _                        ' __in DWORD  dwSourceMask
 , BYVAL dwGroupAddr AS DWORD _                         ' __in DWORD  dwGroupAddr
 , BYVAL dwGroupMask AS DWORD _                         ' __in DWORD  dwGroupMask
 , BYVAL dwIfIndex AS DWORD _                           ' __in DWORD  dwIfIndex
 , BYVAL dwIfNextHopIPAddr AS DWORD _                   ' __in DWORD  dwIfNextHopIPAddr
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS DWORD                                             ' DWORD

'//============================================================================
'//
'// Enumeration API
'//
'//============================================================================


'//----------------------------------------------------------------------------
'// MFE enumeration API
'//----------------------------------------------------------------------------

DECLARE FUNCTION MgmGetMfe IMPORT "Rtm.dll" ALIAS "MgmGetMfe" ( _
   BYREF pimm AS MIB_IPMCAST_MFE _                      ' __in PMIB_IPMCAST_MFE pimm
 , BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE  pbBuffer
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGetFirstMfe IMPORT "Rtm.dll" ALIAS "MgmGetFirstMfe" ( _
   BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE  pbBuffer
 , BYVAL pdwNumEntries AS BYTE PTR _                    ' __inout PDWORD pdwNumEntries
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGetNextMfe IMPORT "Rtm.dll" ALIAS "MgmGetNextMfe" ( _
   BYREF pimmStart AS MIB_IPMCAST_MFE _                 ' __in PMIB_IPMCAST_MFE pimmStart
 , BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE  pbBuffer
 , BYREF pdwNumEntries AS DWORD _                       ' __inout PDWORD pdwNumEntries
 ) AS DWORD                                             ' DWORD

'//
'// Include statistics corresponding to MIB_IPMCAST_MFE_STATS
'//

%MGM_MFE_STATS_0             = &H00000001???

'//
'// Include statistics corresponding to MIB_IPMCAST_MFE_STATS_EX
'//

%MGM_MFE_STATS_1             = &H00000002???


DECLARE FUNCTION MgmGetMfeStats IMPORT "Rtm.dll" ALIAS "MgmGetMfeStats" ( _
   BYREF pimm AS MIB_IPMCAST_MFE _                      ' __in PMIB_IPMCAST_MFE pimm
 , BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE pbBuffer
 , BYVAL dwFlags AS DWORD _                             ' __in PDWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGetFirstMfeStats IMPORT "Rtm.dll" ALIAS "MgmGetFirstMfeStats" ( _
   BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE pbBuffer
 , BYREF pdwNumEntries AS DWORD _                       ' __inout PDWORD pdwNumEntries
 , BYVAL dwFlags AS DWORD _                             ' __in PDWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGetNextMfeStats IMPORT "Rtm.dll" ALIAS "MgmGetNextMfeStats" ( _
   BYREF pimmStart AS MIB_IPMCAST_MFE _                 ' __in PMIB_IPMCAST_MFE pimmStart
 , BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE pbBuffer
 , BYREF pdwNumEntries AS DWORD _                       ' __inout PDWORD pdwNumEntries
 , BYVAL dwFlags AS DWORD _                             ' __in PDWORD dwFlags
 ) AS DWORD                                             ' DWORD

'//----------------------------------------------------------------------------
'// Group menbership entry enumeration API
'//----------------------------------------------------------------------------

DECLARE FUNCTION MgmGroupEnumerationStart IMPORT "Rtm.dll" ALIAS "MgmGroupEnumerationStart" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYVAL metEnumType AS LONG _                          ' __in MGM_ENUM_TYPES metEnumType
 , BYREF phEnumHandle AS DWORD _                        ' __out HANDLE * phEnumHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGroupEnumerationGetNext IMPORT "Rtm.dll" ALIAS "MgmGroupEnumerationGetNext" ( _
   BYVAL hEnum AS DWORD _                               ' __in HANDLE hEnum
 , BYREF pdwBufferSize AS DWORD _                       ' __inout PDWORD pdwBufferSize
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout PBYTE pbBuffer
 , BYREF pdwNumEntries AS DWORD _                       ' __inout PDWORD pdwNumEntries
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION MgmGroupEnumerationEnd IMPORT "Rtm.dll" ALIAS "MgmGroupEnumerationEnd" ( _
   BYVAL hEnum AS DWORD _                               ' __in HANDLE hEnum
 ) AS DWORD                                             ' DWORD


'//-----------------------------------------------------------------
'// Mgm MFE Update API.
'//
'//-----------------------------------------------------------------

DECLARE FUNCTION MgmSetMfe IMPORT "Rtm.dll" ALIAS "MgmSetMfe" ( _
   BYVAL hProtocol AS DWORD _                           ' __in HANDLE hProtocol
 , BYREF pmimm AS MIB_IPMCAST_MFE  _                    ' __in PMIB_IPMCAST_MFE pmimm
 ) AS DWORD                                             ' DWORD
