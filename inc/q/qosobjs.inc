' ########################################################################################
' Microsoft Windows
' File: qosobjs.inc
' Contents: QoS object definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QOSOBJS_INC = 1

#INCLUDE ONCE "qos.inc"

%QOS_MAX_OBJECT_STRING_LENGTH = 256

'//
'// QoS objects supported by traffic control
'//
%QOS_TRAFFIC_GENERAL_ID_BASE = 4000???

%QOS_OBJECT_DS_CLASS                    = &H00000001??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'       /* QOS_DS_CLASS structure passed */
%QOS_OBJECT_TRAFFIC_CLASS               = &H00000002??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'        /* QOS_Traffic class structure passed */
%QOS_OBJECT_DIFFSERV                    = &H00000003??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'        /* QOS_DIFFSERV Structure */
%QOS_OBJECT_TCP_TRAFFIC                 = &H00000004??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'       /* QOS_TCP_TRAFFIC structure */
%QOS_OBJECT_FRIENDLY_NAME               = &H00000005??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'       /* QOS_FRIENDLY_NAME structure */
%QOS_OBJECT_STARTING_RATE               = &H00000006??? + %QOS_TRAFFIC_GENERAL_ID_BASE
'       /* QOS_STARTING_RATE structure */


'//
'// This structure is used to associate a friendly name with the flow
'//

' // Size = 520 bytes
TYPE QOS_FRIENDLY_NAME DWORD
   ObjectHdr    AS QOS_OBJECT_HDR
   FriendlyName AS WSTRINGZ * %QOS_MAX_OBJECT_STRING_LENGTH   ' WCHAR
END TYPE

'//
'// This structure may carry an 802.1 TrafficClass parameter which
'// has been provided to the host by a layer 2 network, for example,
'// in an 802.1 extended RSVP RESV message. If this object is obtained
'// from the network, hosts will stamp the MAC headers of corresponding
'// transmitted packets, with the value in the object. Otherwise, hosts
'// may select a value based on the standard Intserv mapping of
'// ServiceType to 802.1 TrafficClass.
'//
'//

' // Size = 12 bytes
TYPE QOS_TRAFFIC_CLASS DWORD
   ObjectHdr    AS QOS_OBJECT_HDR
   TrafficClass AS DWORD   ' ULONG
END TYPE

'//
'// This structure may carry an DSField parameter which  has been provided to
'// the host by a layer 3 network, for example, in an extended RSVP RESV message.
'// If this object is obtained from the network, hosts will stamp the DS Field on the
'// IP header of transmitted packets, with the value in the object. Otherwise, hosts
'// may select a value based on the standard Intserv mapping of ServiceType to DS Field
'//

' // Size = 12 bytes
TYPE QOS_DS_CLASS DWORD
   ObjectHdr AS QOS_OBJECT_HDR
   DSField   AS DWORD   ' ULONG
END TYPE


'//
'// This structure is used to create DiffServ Flows. This creates flows in the packet scheduler
'// and allows it to classify to packets based on a particular DS field. This structure takes
'// a variable length array of QOS_DIFFSERV_RULE, where each DS field is specified by a
'// QOS_DIFFSERV_RULE
'//
' // Size = 16 bytes
TYPE QOS_DIFFSERV DWORD
   ObjectHdr       AS QOS_OBJECT_HDR
   DSFieldCount    AS DWORD   ' ULONG
   DiffservRule(0) AS BYTE   ' UCHAR
END TYPE

'//
'// The rule for a Diffserv DS codepoint.
'//
' // Size = 5 bytes
TYPE QOS_DIFFSERV_RULE BYTE
   InboundDSField               AS BYTE   ' UCHAR
   ConformingOutboundDSField    AS BYTE   ' UCHAR
   NonConformingOutboundDSField AS BYTE   ' UCHAR
   ConformingUserPriority       AS BYTE   ' UCHAR
   NonConformingUserPriority    AS BYTE   ' UCHAR
END TYPE

'//
'// This structure is passed to indicate that the IP Precedence and UserPriority mappings for the flow
'// have to be set to the system defaults for TCP traffic. If this object is passed,
'// the ServiceType ==> DSField mapping, ServiceType ==> UserPriorityMapping, QOS_OBJECT_DS_CLASS
'// and QOS_OBJECT_TRAFFIC_CLASS will be ignored.
'//

' // Size = 8 bytes
TYPE QOS_TCP_TRAFFIC DWORD
   ObjectHdr AS QOS_OBJECT_HDR
END TYPE

' // Size = 16 bytes
TYPE QOS_STARTING_RATE DWORD
   ObjectHdr         AS QOS_OBJECT_HDR
   StartingTokenRate AS DWORD            ' ULONG // In bytes per second
   RampingTime       AS DWORD            ' ULONG // In Milliseconds
END TYPE
