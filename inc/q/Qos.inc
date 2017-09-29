' ########################################################################################
' Microsoft Windows
' File: qos.inc
' Contents: Quality of Service structures and types used by Winsock applications
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QOS_INC = 1

'/*
' *  Definitions for valued-based Service Type for each direction of data flow.
' */

'typedef ULONG   SERVICETYPE;

%SERVICETYPE_NOTRAFFIC           = &H00000000???  ' No data in this direction
%SERVICETYPE_BESTEFFORT          = &H00000001???  ' Best Effort
%SERVICETYPE_CONTROLLEDLOAD      = &H00000002???  ' Controlled Load
%SERVICETYPE_GUARANTEED          = &H00000003???  ' Guaranteed
%SERVICETYPE_NETWORK_UNAVAILABLE = &H00000004???  ' Used to notify change to user
%SERVICETYPE_GENERAL_INFORMATION = &H00000005???  ' corresponds to "General Parameters" defined by IntServ
%SERVICETYPE_NOCHANGE            = &H00000006???  ' used to indicate that the flow spec contains no change from any previous one
%SERVICETYPE_NONCONFORMING       = &H00000009???  ' Non-Conforming Traffic
%SERVICETYPE_NETWORK_CONTROL     = &H0000000A???  ' Network Control traffic
%SERVICETYPE_QUALITATIVE         = &H0000000D???  ' Qualitative applications


'/*********  The usage of these is currently not supported.  ***************/
%SERVICE_BESTEFFORT              = &H80010000???
%SERVICE_CONTROLLEDLOAD          = &H80020000???
%SERVICE_GUARANTEED              = &H80040000???
%SERVICE_QUALITATIVE             = &H80200000???
'/* **************************** ***** ************************************ */

'/*
' * Flags to control the usage of RSVP on this flow.
' */

'/*
' * to turn off traffic control, 'OR' ( | ) this flag with the
' * ServiceType field in the FLOWSPEC
' */
'#define SERVICE_NO_TRAFFIC_CONTROL   0x81000000
%SERVICE_NO_TRAFFIC_CONTROL = &H81000000???

'/*
' * this flag can be used to prevent any rsvp signaling messages from being
' * sent. Local traffic control will be invoked, but no RSVP Path messages
' * will be sent.This flag can also be used in conjunction with a receiving
' * flowspec to suppress the automatic generation of a Reserve message.
' * The application would receive notification that a Path  message had arrived
' * and would then need to alter the QOS by issuing WSAIoctl( SIO_SET_QOS ),
' * to unset this flag and thereby causing Reserve messages to go out.
' */

'#define SERVICE_NO_QOS_SIGNALING   0x40000000
%SERVICE_NO_QOS_SIGNALING   = &H40000000???


'/*
' *  Flow Specifications for each direction of data flow.
' */
' // Size = 32 bytes
TYPE FLOWSPEC DWORD
   TokenRate          AS DWORD   ' ULONG /* In Bytes/sec */
   TokenBucketSize    AS DWORD   ' ULONG /* In Bytes */
   PeakBandwidth      AS DWORD   ' ULONG /* In Bytes/sec */
   Latency            AS DWORD   ' ULONG /* In microseconds */
   DelayVariation     AS DWORD   ' ULONG /* In microseconds */
   ServiceType        AS DWORD   ' SERVICETYPE
   MaxSduSize         AS DWORD   ' ULONG /* In Bytes */
   MinimumPolicedSize AS DWORD   ' ULONG /* In Bytes */
END TYPE

'/*
' * this value can be used in the FLOWSPEC structure to instruct the Rsvp Service
' * provider to derive the appropriate default value for the parameter.  Note
' * that not all values in the FLOWSPEC structure can be defaults. In the
' * ReceivingFlowspec, all parameters can be defaulted except the ServiceType.
' * In the SendingFlowspec, the MaxSduSize and MinimumPolicedSize can be
' * defaulted. Other defaults may be possible. Refer to the appropriate
' * documentation.
' */
'#define QOS_NOT_SPECIFIED     0xFFFFFFFF
%QOS_NOT_SPECIFIED = &HFFFFFFFF???

'/*
' * define a value that can be used for the PeakBandwidth, which will map into
' * positive infinity when the FLOWSPEC is converted into IntServ floating point
' * format.  We can't use (-1) because that value was previously defined to mean
' * "select the default".
' */
'#define   POSITIVE_INFINITY_RATE     0xFFFFFFFE
%POSITIVE_INFINITY_RATE = &HFFFFFFFE???

'/*
' * the provider specific structure can have a number of objects in it.
' * Each next structure in the
' * ProviderSpecific will be the QOS_OBJECT_HDR struct that prefaces the actual
' * data with a type and length for that object.  This QOS_OBJECT struct can
' * repeat several times if there are several objects.  This list of objects
' * terminates either when the buffer length has been reached ( WSABUF ) or
' * an object of type QOS_END_OF_LIST is encountered.
' */

' // Size = 8 bytes
TYPE QOS_OBJECT_HDR DWORD
   ObjectType   AS DWORD   ' ULONG
   ObjectLength AS DWORD   ' ULONG
END TYPE


'/*
' * general QOS objects start at this offset from the base and have a range
' * of 1000
' */
%QOS_GENERAL_ID_BASE = 2000

%QOS_OBJECT_END_OF_LIST = &H00000001 + %QOS_GENERAL_ID_BASE
          ' QOS_End_of_list structure passed
%QOS_OBJECT_SD_MODE = &H00000002 + %QOS_GENERAL_ID_BASE
          ' QOS_ShapeDiscard structure passed
%QOS_OBJECT_SHAPING_RATE = &H00000003 + %QOS_GENERAL_ID_BASE
          ' QOS_ShapingRate structure
%QOS_OBJECT_DESTADDR = &H00000004 + %QOS_GENERAL_ID_BASE
          ' QOS_DestAddr structure (defined in qossp.h)

'/*
' * This structure is used to define the behaviour that the traffic
' * control packet shaper will apply to the flow.
' *
' * TC_NONCONF_BORROW - the flow will receive resources remaining
' *  after all higher priority flows have been serviced. If a
' *  TokenRate is specified, packets may be non-conforming and
' *  will be demoted to less than best-effort priority.
' *
' * TC_NONCONF_SHAPE - TokenRate must be specified. Non-conforming
' *  packets will be retianed in the packet shaper until they become
' *  conforming.
' *
' * TC_NONCONF_DISCARD - TokenRate must be specified. Non-conforming
' *  packets will be discarded.
' *
' */

' // Size = 12 bytes
TYPE QOS_SD_MODE DWORD
  ObjectHdr        AS QOS_OBJECT_HDR   ' QOS_OBJECT_HDR
  ShapeDiscardMode AS DWORD            ' ULONG
END TYPE

%TC_NONCONF_BORROW      = 0
%TC_NONCONF_SHAPE       = 1
%TC_NONCONF_DISCARD     = 2
%TC_NONCONF_BORROW_PLUS = 3   ' // Not supported currently

'/*
' * This structure allows an app to specify a prorated "average token rate" using by
' * the traffic shaper under SHAPE modehaper queue. It is expressed in bytes per sec.
' *
' * ShapingRate (bytes per sec.)
' *
' */

' // Size = 12 bytes
TYPE QOS_SHAPING_RATE DWORD
   ObjectHdr   AS QOS_OBJECT_HDR   ' QOS_OBJECT_HDR
   ShapingRate AS DWORD            ' ULONG
END TYPE
