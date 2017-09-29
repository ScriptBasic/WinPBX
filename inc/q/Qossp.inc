' ########################################################################################
' Microsoft Windows
' File: Qossp.inc
' Contents: QoS definitions for NDIS components
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QOSSP_INC = 1

#INCLUDE ONCE "QOS.INC"
#INCLUDE ONCE "ws2def.inc"

'/*
' * Definition of object Types
' *
' *
' * define the values for ObjectType above - RSVP Objects ids start at an
' * offset from zero to allow for ATM objects that might be defined in the
' * lower number range.
' */
%RSVP_OBJECT_ID_BASE         = 1000
%RSVP_OBJECT_STATUS_INFO     = (&H00000000 + %RSVP_OBJECT_ID_BASE)
         ' /* RSVP_STATUS_INFO structure passed */
%RSVP_OBJECT_RESERVE_INFO    = (&H00000001 + %RSVP_OBJECT_ID_BASE)
         ' /* RSVP_RESERVE_INFO structure passed */
%RSVP_OBJECT_ADSPEC          = (&H00000002 + %RSVP_OBJECT_ID_BASE)
         ' /* RSVP_ADSPEC structure passed */
%RSVP_OBJECT_POLICY_INFO     = (&H00000003 + %RSVP_OBJECT_ID_BASE)
         ' /* RSVP POLICY ELEMENT(S) retrieved */
%RSVP_OBJECT_FILTERSPEC_LIST = (&H00000004 + %RSVP_OBJECT_ID_BASE)
         ' /* RSVP SENDER LIST returned */


'/*
' * IPV4 addressing for RSVP FILTERSPECS
' */
' // Size = 4 bytes
UNION IN_ADDR_IPV4 DWORD
   Addr         AS DWORD   ' ULONG
   AddrBytes(3) AS BYTE    ' UCHAR[4]
END UNION

'/*
' * IPV6 addressing for RSVP FILTERSPECS
' */
' // Size = 16 bytes
TYPE IN_ADDR_IPV6
   Addr(15) AS BYTE   ' UCHAR[16] //IPV6 address
END TYPE

'/*
' * IPV4 addressing for RSVP FILTERSPECS
' */
' // Size = 8 bytes
TYPE RSVP_FILTERSPEC_V4 WORD
   Address AS IN_ADDR_IPV4
   Unused  AS WORD   ' USHORT
   Port    AS WORD   ' USHORT
END TYPE

' // Size = 20 bytes
TYPE RSVP_FILTERSPEC_V6 WORD
   Address AS IN_ADDR_IPV6
   UnUsed  AS WORD   ' USHORT
   Port    AS WORD   ' USHORT
END TYPE

' // Size = 20 bytes
TYPE RSVP_FILTERSPEC_V6_FLOW BYTE
   Address      AS IN_ADDR_IPV6
   UnUsed       AS BYTE   ' UCHAR
   FlowLabel(2) AS BYTE   ' UCHAR[3]
END TYPE

' // Size = 8 bytes
TYPE RSVP_FILTERSPEC_V4_GPI DWORD
   Address       AS IN_ADDR_IPV4
   GeneralPortId AS DWORD   ' ULONG
END TYPE

' // Size = 20 bytes
TYPE RSVP_FILTERSPEC_V6_GPI DWORD
   Address       AS IN_ADDR_IPV6
   GeneralPortId AS DWORD   ' ULONG
END TYPE

'/*
' * FILTERSPEC TYPES used in making reservations.
' */
' enum FilterType
%FILTERSPECV4      = 1
%FILTERSPECV6      = 2
%FILTERSPECV6_FLOW = 3
%FILTERSPECV4_GPI  = 4
%FILTERSPECV6_GPI  = 5
%FILTERSPEC_END    = 6

' // Size = 20 bytes
UNION RSVP_FILTERSPEC_UNION
   FilterSpecV4     AS RSVP_FILTERSPEC_V4
   FilterSpecV6     AS RSVP_FILTERSPEC_V6
   FilterSpecV6Flow AS RSVP_FILTERSPEC_V6_FLOW
   FilterSpecV4Gpi  AS RSVP_FILTERSPEC_V4_GPI
   FilterSpecV6Gpi  AS RSVP_FILTERSPEC_V6_GPI
END UNION

' // Size = 24 bytes
TYPE RSVP_FILTERSPEC DWORD
   Type AS DWORD   ' FilterType
   RSVP_FILTERSPEC_UNION
END TYPE

'/*
' * FLOWDESCRIPTOR Structure used for specifying one or more
' * Filters per Flowspec.
' */
' // Size = 40 bytes
TYPE FLOWDESCRIPTOR DWORD
   FlowSpec   AS FLOWSPEC
   NumFilters AS DWORD                 ' DWORD
   FilterList AS RSVP_FILTERSPEC PTR   ' LPRSVP_FILTERSPEC
END TYPE

'/*
' * RSVP_POLICY contains undefined policy data.  RSVP transports this
' * data on behalf of the Policy Control component.
' */
' // Size = 8 bytes
TYPE RSVP_POLICY WORD
   Len     AS WORD   ' USHORT /* total length of this element object */
   Type    AS WORD   ' USHORT
   Info(3) AS BYTE   ' UCHAR[4]
END TYPE

'#define RSVP_POLICY_HDR_LEN    ( sizeof(USHORT) + sizeof(USHORT) )
%RSVP_POLICY_HDR_LEN = 2 + 2

'/*
' * RSVP_POLICY_INFO contains undefined policy element(s) retrieved from RSVP.
' */
' // Size = 20 bytes
TYPE RSVP_POLICY_INFO DWORD
   ObjectHdr        AS QOS_OBJECT_HDR
   NumPolicyElement AS DWORD         ' ULONG /* count of the number of policy elements */
   PolicyElement(0) AS RSVP_POLICY   ' /* a list of the policy elements retrieved */
END TYPE

'/*
' * RSVP_RESERVE_INFO Structure used for storing RSVP specific
' * information for fine tuning interaction via the Winsock2
' * Generic QoS API via the provider specific buffer. This structure
' * includes the QOS_OBJECT_HDR structure directly
' */

' // Size = 28 bytes
TYPE RSVP_RESERVE_INFO DWORD
   ObjectHdr         AS QOS_OBJECT_HDR         ' /* type and length of this object */
   Style             AS DWORD                  ' ULONG /* RSVP Style (FF,WF,SE) */
   ConfirmRequest    AS DWORD                  ' ULONG /* Non Zero for Confirm Request (receive only) */
   PolicyElementList AS RSVP_POLICY_INFO PTR   ' LPRSVP_POLICY_INFO /* Points to the set of policy elements */
   NumFlowDesc       AS DWORD                  ' ULONG /* Number of FlowDesc */
   FlowDescList      AS FLOWDESCRIPTOR   PTR   ' LPFLOWDESCRIPTOR /* Points to the FlowDesc list */
END TYPE

'/*
' * definitions for the ulStyle in the previous structure
' */
%RSVP_DEFAULT_STYLE            = &H00000000???
%RSVP_WILDCARD_STYLE           = &H00000001???
%RSVP_FIXED_FILTER_STYLE       = &H00000002???
%RSVP_SHARED_EXPLICIT_STYLE    = &H00000003???

'/*
' * RSVP_STATUS_INFO Structure used for storing RSVP specific
' * error of status indications.  This also serves as a header
' * for additional objects in the provider specific buffer when
' * interacting via Winsock2 Generic QoS API. This structure includes
' * the QOS_OBJECT_COUNT and QOS_OBJECT_HDR structures directly It is
' * expected to be the first structure in the provider specific structure
' * since it includes the QOS_OBJECT_COUNT
' */

' // Size = 20 bytes
TYPE RSVP_STATUS_INFO DWORD
   ObjectHdr       AS QOS_OBJECT_HDR   ' /* Object Hdr */
   StatusCode      AS DWORD            ' ULONG /* Error or Status Information see Winsock2.h */
   ExtendedStatus1 AS DWORD            ' ULONG /* Provider specific status extension */
   ExtendedStatus2 AS DWORD            ' ULONG /* Provider specific status extension */
END TYPE

'/*
' * QOS_DestAddr structure -- used for WSAIoctl(SIO_SET_QOS) when we
' * do not want to issue a connect for a sending socket.  The destination
' * address is required so we can generate the session information for
' * RSVP signalling.
'*/

' // Size = 16 bytes
TYPE QOS_DESTADDR DWORD
   ObjectHdr           AS QOS_OBJECT_HDR   ' /* Object header */
   SocketAddress       AS SOCKADDR PTR     ' const struct sockaddr * /* Destination socket address */
   SocketAddressLength AS DWORD            ' ULONG /* Length of the address structure */
END TYPE

'/*
' * this structure defines the "General Characterization Parameters" contained in
' * the RSVP Adspec object
' */
' // Size = 20 bytes
TYPE AD_GENERAL_PARAMS DWORD
   IntServAwareHopCount  AS DWORD   ' ULONG /* number of hops that conform to
                                    '        * Integrated Services requirements */
   PathBandwidthEstimate AS DWORD   ' ULONG /* minimum bandwidth available from
                                    '        * sender to receiver */
   MinimumLatency        AS DWORD   ' ULONG /* sum of minimum latency of the packet
                                    '        * forwarding process in routers
                                    '        * (in usec)*/
   PathMTU               AS DWORD   ' ULONG /* max transmission unit end to end that
                                    '        * will not incur fragmentation */
   Flags                 AS DWORD   ' ULONG /* used to hold break bits.*/
END TYPE

'/*
' * Minimum Latency may be set to this "undefined" value
' */
%INDETERMINATE_LATENCY = &HFFFFFFFF???

'/*
' * This Flag is used to indicate the existence of a network element not
' * supporting  QoS control services somewhere in the data path. If this bit
' * is set in the specific service override then it indicates that that
' * service was not supported at at least one hop.
' */
%AD_FLAG_BREAK_BIT    = &H00000001???

'/*
' * this structure describes the Guaranteed service parameters
' */
' // Size = 16 bytes
TYPE AD_GUARANTEED DWORD
   CTotal AS DWORD   ' ULONG
   DTotal AS DWORD   ' ULONG
   CSum   AS DWORD   ' ULONG
   DSum   AS DWORD   ' ULONG
END TYPE

'/*
' * this structure describes the format of the parameter buffer that can be
' * included in the Service_Type structure below.  This structure allows an
' * application to include any valid Int Serv service parameter in the Buffer
' * value, after providing the Int Serv parameter id in the ParameterId field.
' */
' // Size = 12 bytes
TYPE PARAM_BUFFER DWORD
   ParameterId AS DWORD   ' ULONG /* Int Server parameter ID */
   Length      AS DWORD   ' ULONG /* total length of this structure
                          ' * ( 8 bytes + length of Buffer ) */
   Buffer(0)   AS BYTE    '      /* Paramter itself */
END TYPE

' // Size = 16 bytes
UNION CONTROL_SERVICE_UNION
   Guaranteed     AS AD_GUARANTEED
   ParamBuffer(0) AS PARAM_BUFFER   ' /* allows for other services down the road */
END UNION

'/*
' * this structure contains the service types supported
' */
' // Size = 44 bytes
TYPE CONTROL_SERVICE DWORD
   ' /*
   '  * the length of this entire structure including the following buffer.
   '  * This length value can be added to the ptr to the structure to get the ptr
   '  * to the next SERVICE_TYPE structure in the list, until the
   '  * NumberOfServices count has been exhausted.
   '  */
   Length AS DWORD   ' ULONG
   Service AS DWORD   ' SERVICETYPE
   Overrides AS AD_GENERAL_PARAMS
   ' /*
   '  * service specific information ( controlled load has no service specific
   '  * info here )
   '  */
   CONTROL_SERVICE_UNION
END TYPE

'/*
' * This structure defines the information which is carried in the Rsvp
' * Adspec.  This Rsvp object typically indicates which service types are
' * available ( Controlled Load and/or Guaranteed Service ), if a non-Rsvp
' * hop has been encountered by the Path message, and the minumum MTU along
' * the path. The services array indicates which services are supported
' */
' // Size = 76 bytes
TYPE RSVP_ADSPEC DWORD
   ObjectHdr        AS QOS_OBJECT_HDR
   GeneralParams    AS AD_GENERAL_PARAMS   ' /* contains the general
                                           ' * characterization paramters */
   NumberOfServices AS DWORD               ' ULONG /* count of the number of services */
   Services(0)      AS CONTROL_SERVICE     ' /* a list of the services
                                           ' * supported/requested */
END TYPE

'//
'// Opcode for the SIO_CHK_QOS ioctl
'// (specific for the Microsoft QOS Service Provider
'//
'// Bascially:
'//
'// SIO_CHK_QOS = _WSAIORW(IOC_VENDOR,1)
'//             = mIOC_IN | mIOC_OUT | mIOC_VENDOR | mCOMPANY | ioctl_code
'//    where
'//         mIOC_IN     = 0x80000000
'//         mIOC_OUT    = 0x40000000
'//         mIOC_VENDOR = 0x04000000
'//         mCOMPANY    = 0x18000000
'//         ioctl_code  = 0x00000001
'//
'// See WSAIoctl man page for details.
'//

%mIOC_IN     = &H80000000???
%mIOC_OUT    = &H40000000???
%mIOC_VENDOR = &H04000000???
%mCOMPANY    = &H18000000???
%ioctl_code  = &H00000001???

%SIO_CHK_QOS = %mIOC_IN OR %mIOC_OUT OR %mIOC_VENDOR OR %mCOMPANY OR %ioctl_code

'//
'// The following may be specified in the input buffer
'// of the SIO_CHK_IOCTL ioctl call
'//

%QOSSPBASE          = 50000

%ALLOWED_TO_SEND_DATA  = (%QOSSPBASE+1)     ' // query the SBM/BEST_EFFORT limit
                                            ' //   -- result is based on a comparison between
                                            ' //      the user-specified token rate and the
                                            ' //      SBM/BEST_EFFORT bandwidth parameters in
                                            ' //      the system
                                            ' //   -- result is a YES(1) or NO(0) answer
                                            ' //      in the output buffer

%ABLE_TO_RECV_RSVP     = (%QOSSPBASE+2)     ' // query the SBM/BEST_EFFORT limit
                                            ' //   -- result is based on a comparison between
                                            ' //      the user-specified token rate and the
                                            ' //      SBM/BEST_EFFORT bandwidth parameters in
                                            ' //      the system
                                            ' //   -- result is a YES(1) or NO(0) answer
                                            ' //      in the output buffer

%LINE_RATE             = (%QOSSPBASE+3)     ' // query the interface capacity
                                            ' //   -- result returned in the output buffer
                                            ' //      in kilo-bits per second

%LOCAL_TRAFFIC_CONTROL = (%QOSSPBASE+4)     ' // check if Kernel Traffic Control is available or not
                                            ' //   -- 0 if not available
                                            ' //   -- 1 if avaiable
                                            ' //   -- INFO_NOT_AVAILABLE if there is no way to check

%LOCAL_QOSABILITY      = (%QOSSPBASE+5)     ' // The followings are for
                                            ' // the Discovery of Local QOSability
                                            ' //   -- 0 if no local QOS support
                                            ' //   -- 1 if local QOS support available
                                            ' //   -- INFO_NOT_AVAILABLE if there is no way to check

%END_TO_END_QOSABILITY = (%QOSSPBASE+6)     ' // The followings are for
                                            ' // the Discovery of End-to-End QOSability
                                            ' //   -- 0 if no end-to-end QOS support
                                            ' //   -- 1 if end-to-end QOS support available
                                            ' //   -- INFO_NOT_AVAILABLE if there is no way to check

%INFO_NOT_AVAILABLE  = &HFFFFFFFF           ' // used when LINE_RATE is not known


%ANY_DEST_ADDR       = &HFFFFFFFF           ' // for QOS_OBJECT_DEST_ADDR


'// The followings are for Guaranteed_Service+Latency -> ISSLOW_Traffic_Class Mapping

%MODERATELY_DELAY_SENSITIVE   = &HFFFFFFFD???

%HIGHLY_DELAY_SENSITIVE       = &HFFFFFFFE???

'//
'// QOSSP Error Code/Value
'//

%QOSSP_ERR_BASE                                 = (%QOSSPBASE+6000)

'// No error
%GQOS_NO_ERRORCODE                              = (0)

%GQOS_NO_ERRORVALUE                             = (0)

'// Unknown error
%GQOS_ERRORCODE_UNKNOWN                         = (&HFFFFFFFF???)

%GQOS_ERRORVALUE_UNKNOWN                        = (&HFFFFFFFF???)

'// Admission (Resource) Error
%GQOS_NET_ADMISSION                             = (%QOSSP_ERR_BASE+100)

%GQOS_OTHER                                     = (%QOSSP_ERR_BASE+100+1)
%GQOS_DELAYBND                                  = (%QOSSP_ERR_BASE+100+2)
%GQOS_BANDWIDTH                                 = (%QOSSP_ERR_BASE+100+3)
%GQOS_MTU                                       = (%QOSSP_ERR_BASE+100+4)
%GQOS_FLOW_RATE                                 = (%QOSSP_ERR_BASE+100+5)
%GQOS_PEAK_RATE                                 = (%QOSSP_ERR_BASE+100+6)
%GQOS_AGG_PEAK_RATE                             = (%QOSSP_ERR_BASE+100+7)

'// Policy Error
%GQOS_NET_POLICY                                = (%QOSSP_ERR_BASE+200)

%GQOS_POLICY_ERROR_UNKNOWN                      = (%QOSSP_ERR_BASE+200+0)

%GQOS_POLICY_GLOBAL_DEF_FLOW_COUNT              = (%QOSSP_ERR_BASE+200+1)
%GQOS_POLICY_GLOBAL_GRP_FLOW_COUNT              = (%QOSSP_ERR_BASE+200+2)
%GQOS_POLICY_GLOBAL_USER_FLOW_COUNT             = (%QOSSP_ERR_BASE+200+3)
%GQOS_POLICY_GLOBAL_UNK_USER_FLOW_COUNT         = (%QOSSP_ERR_BASE+200+4)
%GQOS_POLICY_SUBNET_DEF_FLOW_COUNT              = (%QOSSP_ERR_BASE+200+5)
%GQOS_POLICY_SUBNET_GRP_FLOW_COUNT              = (%QOSSP_ERR_BASE+200+6)
%GQOS_POLICY_SUBNET_USER_FLOW_COUNT             = (%QOSSP_ERR_BASE+200+7)
%GQOS_POLICY_SUBNET_UNK_USER_FLOW_COUNT         = (%QOSSP_ERR_BASE+200+8)

%GQOS_POLICY_GLOBAL_DEF_FLOW_DURATION           = (%QOSSP_ERR_BASE+200+9)
%GQOS_POLICY_GLOBAL_GRP_FLOW_DURATION           = (%QOSSP_ERR_BASE+200+10)
%GQOS_POLICY_GLOBAL_USER_FLOW_DURATION          = (%QOSSP_ERR_BASE+200+11)
%GQOS_POLICY_GLOBAL_UNK_USER_FLOW_DURATION      = (%QOSSP_ERR_BASE+200+12)
%GQOS_POLICY_SUBNET_DEF_FLOW_DURATION           = (%QOSSP_ERR_BASE+200+13)
%GQOS_POLICY_SUBNET_GRP_FLOW_DURATION           = (%QOSSP_ERR_BASE+200+14)
%GQOS_POLICY_SUBNET_USER_FLOW_DURATION          = (%QOSSP_ERR_BASE+200+15)
%GQOS_POLICY_SUBNET_UNK_USER_FLOW_DURATION      = (%QOSSP_ERR_BASE+200+16)

%GQOS_POLICY_GLOBAL_DEF_FLOW_RATE               = (%QOSSP_ERR_BASE+200+17)
%GQOS_POLICY_GLOBAL_GRP_FLOW_RATE               = (%QOSSP_ERR_BASE+200+18)
%GQOS_POLICY_GLOBAL_USER_FLOW_RATE              = (%QOSSP_ERR_BASE+200+19)
%GQOS_POLICY_GLOBAL_UNK_USER_FLOW_RATE          = (%QOSSP_ERR_BASE+200+20)
%GQOS_POLICY_SUBNET_DEF_FLOW_RATE               = (%QOSSP_ERR_BASE+200+21)
%GQOS_POLICY_SUBNET_GRP_FLOW_RATE               = (%QOSSP_ERR_BASE+200+22)
%GQOS_POLICY_SUBNET_USER_FLOW_RATE              = (%QOSSP_ERR_BASE+200+23)
%GQOS_POLICY_SUBNET_UNK_USER_FLOW_RATE          = (%QOSSP_ERR_BASE+200+24)

%GQOS_POLICY_GLOBAL_DEF_PEAK_RATE               = (%QOSSP_ERR_BASE+200+25)
%GQOS_POLICY_GLOBAL_GRP_PEAK_RATE               = (%QOSSP_ERR_BASE+200+26)
%GQOS_POLICY_GLOBAL_USER_PEAK_RATE              = (%QOSSP_ERR_BASE+200+27)
%GQOS_POLICY_GLOBAL_UNK_USER_PEAK_RATE          = (%QOSSP_ERR_BASE+200+28)
%GQOS_POLICY_SUBNET_DEF_PEAK_RATE               = (%QOSSP_ERR_BASE+200+29)
%GQOS_POLICY_SUBNET_GRP_PEAK_RATE               = (%QOSSP_ERR_BASE+200+30)
%GQOS_POLICY_SUBNET_USER_PEAK_RATE              = (%QOSSP_ERR_BASE+200+31)
%GQOS_POLICY_SUBNET_UNK_USER_PEAK_RATE          = (%QOSSP_ERR_BASE+200+32)

%GQOS_POLICY_GLOBAL_DEF_SUM_FLOW_RATE           = (%QOSSP_ERR_BASE+200+33)
%GQOS_POLICY_GLOBAL_GRP_SUM_FLOW_RATE           = (%QOSSP_ERR_BASE+200+34)
%GQOS_POLICY_GLOBAL_USER_SUM_FLOW_RATE          = (%QOSSP_ERR_BASE+200+35)
%GQOS_POLICY_GLOBAL_UNK_USER_SUM_FLOW_RATE      = (%QOSSP_ERR_BASE+200+36)
%GQOS_POLICY_SUBNET_DEF_SUM_FLOW_RATE           = (%QOSSP_ERR_BASE+200+37)
%GQOS_POLICY_SUBNET_GRP_SUM_FLOW_RATE           = (%QOSSP_ERR_BASE+200+38)
%GQOS_POLICY_SUBNET_USER_SUM_FLOW_RATE          = (%QOSSP_ERR_BASE+200+39)
%GQOS_POLICY_SUBNET_UNK_USER_SUM_FLOW_RATE      = (%QOSSP_ERR_BASE+200+40)

%GQOS_POLICY_GLOBAL_DEF_SUM_PEAK_RATE           = (%QOSSP_ERR_BASE+200+41)
%GQOS_POLICY_GLOBAL_GRP_SUM_PEAK_RATE           = (%QOSSP_ERR_BASE+200+42)
%GQOS_POLICY_GLOBAL_USER_SUM_PEAK_RATE          = (%QOSSP_ERR_BASE+200+43)
%GQOS_POLICY_GLOBAL_UNK_USER_SUM_PEAK_RATE      = (%QOSSP_ERR_BASE+200+44)
%GQOS_POLICY_SUBNET_DEF_SUM_PEAK_RATE           = (%QOSSP_ERR_BASE+200+45)
%GQOS_POLICY_SUBNET_GRP_SUM_PEAK_RATE           = (%QOSSP_ERR_BASE+200+46)
%GQOS_POLICY_SUBNET_USER_SUM_PEAK_RATE          = (%QOSSP_ERR_BASE+200+47)
%GQOS_POLICY_SUBNET_UNK_USER_SUM_PEAK_RATE      = (%QOSSP_ERR_BASE+200+48)

%GQOS_POLICY_UNKNOWN_USER                       = (%QOSSP_ERR_BASE+200+49)
%GQOS_POLICY_NO_PRIVILEGES                      = (%QOSSP_ERR_BASE+200+50)
%GQOS_POLICY_EXPIRED_USER_TOKEN                 = (%QOSSP_ERR_BASE+200+51)
%GQOS_POLICY_NO_RESOURCES                       = (%QOSSP_ERR_BASE+200+52)
%GQOS_POLICY_PRE_EMPTED                         = (%QOSSP_ERR_BASE+200+53)
%GQOS_POLICY_USER_CHANGED                       = (%QOSSP_ERR_BASE+200+54)
%GQOS_POLICY_NO_ACCEPTS                         = (%QOSSP_ERR_BASE+200+55)
%GQOS_POLICY_NO_MEMORY                          = (%QOSSP_ERR_BASE+200+56)
%GQOS_POLICY_CRAZY_FLOWSPEC                     = (%QOSSP_ERR_BASE+200+57)

%GQOS_POLICY_NO_MORE_INFO                       = (%QOSSP_ERR_BASE+200+58)
%GQOS_POLICY_UNSUPPORTED_CREDENTIAL_TYPE        = (%QOSSP_ERR_BASE+200+59)
%GQOS_POLICY_INSUFFICIENT_PRIVILEGES            = (%QOSSP_ERR_BASE+200+60)
%GQOS_POLICY_EXPIRED_CREDENTIAL                 = (%QOSSP_ERR_BASE+200+61)
%GQOS_POLICY_IDENTITY_CHANGED                   = (%QOSSP_ERR_BASE+200+62)
%GQOS_POLICY_NO_QOS_PROVIDED                    = (%QOSSP_ERR_BASE+200+63)
%GQOS_POLICY_DO_NOT_SEND                        = (%QOSSP_ERR_BASE+200+64)

%GQOS_POLICY_ERROR_USERID                       = (%QOSSP_ERR_BASE+200+99)

'// RSVP Error
%GQOS_RSVP                                      = (%QOSSP_ERR_BASE+300)

%GQOS_NO_PATH                                   = (%QOSSP_ERR_BASE+300+1)
%GQOS_NO_SENDER                                 = (%QOSSP_ERR_BASE+300+2)
%GQOS_BAD_STYLE                                 = (%QOSSP_ERR_BASE+300+3)
%GQOS_UNKNOWN_STYLE                             = (%QOSSP_ERR_BASE+300+4)
%GQOS_BAD_DSTPORT                               = (%QOSSP_ERR_BASE+300+5)
%GQOS_BAD_SNDPORT                               = (%QOSSP_ERR_BASE+300+6)
%GQOS_AMBIG_FILTER                              = (%QOSSP_ERR_BASE+300+7)
%GQOS_PREEMPTED                                 = (%QOSSP_ERR_BASE+300+8)
%GQOS_UNKN_OBJ_CLASS                            = (%QOSSP_ERR_BASE+300+9)
%GQOS_UNKNOWN_CTYPE                             = (%QOSSP_ERR_BASE+300+10)
%GQOS_INVALID                                   = (%QOSSP_ERR_BASE+300+11)

'// API Error
%GQOS_API                                       = (%QOSSP_ERR_BASE+400)

%GQOS_API_BADSEND                               = (%QOSSP_ERR_BASE+400+1)  ' /* Sender addr not my interface */
%GQOS_API_BADRECV                               = (%QOSSP_ERR_BASE+400+2)  ' /* Recv addr not my interface */
%GQOS_API_BADSPORT                              = (%QOSSP_ERR_BASE+400+3)  ' /* Sport !=0 but Dport == 0 */

'// TC System Error
%GQOS_KERNEL_TC_SYS                             = (%QOSSP_ERR_BASE+500)

%GQOS_TC_GENERIC                                = (%QOSSP_ERR_BASE+500+1)
%GQOS_TC_INVALID                                = (%QOSSP_ERR_BASE+500+2)
%GQOS_NO_MEMORY                                 = (%QOSSP_ERR_BASE+500+3)
%GQOS_BAD_ADDRESSTYPE                           = (%QOSSP_ERR_BASE+500+4)
%GQOS_BAD_DUPLICATE                             = (%QOSSP_ERR_BASE+500+5)
%GQOS_CONFLICT                                  = (%QOSSP_ERR_BASE+500+6)
%GQOS_NOTREADY                                  = (%QOSSP_ERR_BASE+500+7)
%GQOS_WOULDBLOCK                                = (%QOSSP_ERR_BASE+500+8)
%GQOS_INCOMPATIBLE                              = (%QOSSP_ERR_BASE+500+9)
%GQOS_BAD_SDMODE                                = (%QOSSP_ERR_BASE+500+10)
%GQOS_BAD_QOSPRIORITY                           = (%QOSSP_ERR_BASE+500+11)
%GQOS_BAD_TRAFFICCLASS                          = (%QOSSP_ERR_BASE+500+12)
%GQOS_NO_SYS_RESOURCES                          = (%QOSSP_ERR_BASE+500+13)

'// RSVP System Error
%GQOS_RSVP_SYS                                  = (%QOSSP_ERR_BASE+600)

%GQOS_OTHER_SYS                                 = (%QOSSP_ERR_BASE+600+1)
%GQOS_MEMORY_SYS                                = (%QOSSP_ERR_BASE+600+2)
%GQOS_API_SYS                                   = (%QOSSP_ERR_BASE+600+3)
%GQOS_SETQOS_NO_LOCAL_APPS                      = (%QOSSP_ERR_BASE+600+4)

'// TC Error
%GQOS_KERNEL_TC                                 = (%QOSSP_ERR_BASE+700)

%GQOS_CONFLICT_SERV                             = (%QOSSP_ERR_BASE+700+1)
%GQOS_NO_SERV                                   = (%QOSSP_ERR_BASE+700+2)
%GQOS_BAD_FLOWSPEC                              = (%QOSSP_ERR_BASE+700+3)
%GQOS_BAD_TSPEC                                 = (%QOSSP_ERR_BASE+700+4)
%GQOS_BAD_ADSPEC                                = (%QOSSP_ERR_BASE+700+5)

'// GQOS API ERRORS

'// WSAIoctl Error

%GQOS_IOCTL_SYSTEMFAILURE                       = (%QOSSP_ERR_BASE+800+1)
%GQOS_IOCTL_NOBYTESRETURNED                     = (%QOSSP_ERR_BASE+800+2)
%GQOS_IOCTL_INVALIDSOCKET                       = (%QOSSP_ERR_BASE+800+3)
%GQOS_IOCTL_INV_FUNCPTR                         = (%QOSSP_ERR_BASE+800+4)
%GQOS_IOCTL_INV_OVERLAPPED                      = (%QOSSP_ERR_BASE+800+5)

'// SIO_SET_QOS error

%GQOS_SETQOS_BADINBUFFER                        = (%QOSSP_ERR_BASE+810+1)
%GQOS_SETQOS_BADFLOWSPEC                        = (%QOSSP_ERR_BASE+810+2)
%GQOS_SETQOS_COLLISION                          = (%QOSSP_ERR_BASE+810+3)
%GQOS_SETQOS_BADPROVSPECBUF                     = (%QOSSP_ERR_BASE+810+4)
%GQOS_SETQOS_ILLEGALOP                          = (%QOSSP_ERR_BASE+810+5)
%GQOS_SETQOS_INVALIDADDRESS                     = (%QOSSP_ERR_BASE+810+6)
%GQOS_SETQOS_OUTOFMEMORY                        = (%QOSSP_ERR_BASE+810+7)
%GQOS_SETQOS_EXCEPTION                          = (%QOSSP_ERR_BASE+810+8)
%GQOS_SETQOS_BADADDRLEN                         = (%QOSSP_ERR_BASE+810+9)
%GQOS_SETQOS_NOSOCKNAME                         = (%QOSSP_ERR_BASE+810+10)
%GQOS_SETQOS_IPTOSFAIL                          = (%QOSSP_ERR_BASE+810+11)
%GQOS_SETQOS_OPENSESSIONFAIL                    = (%QOSSP_ERR_BASE+810+12)
%GQOS_SETQOS_SENDFAIL                           = (%QOSSP_ERR_BASE+810+13)
%GQOS_SETQOS_RECVFAIL                           = (%QOSSP_ERR_BASE+810+14)
%GQOS_SETQOS_BADPOLICYOBJECT                    = (%QOSSP_ERR_BASE+810+15)
%GQOS_SETQOS_UNKNOWNFILTEROBJ                   = (%QOSSP_ERR_BASE+810+16)
%GQOS_SETQOS_BADFILTERTYPE                      = (%QOSSP_ERR_BASE+810+17)
%GQOS_SETQOS_BADFILTERCOUNT                     = (%QOSSP_ERR_BASE+810+18)
%GQOS_SETQOS_BADOBJLENGTH                       = (%QOSSP_ERR_BASE+810+19)
%GQOS_SETQOS_BADFLOWCOUNT                       = (%QOSSP_ERR_BASE+810+20)
%GQOS_SETQOS_UNKNOWNPSOBJ                       = (%QOSSP_ERR_BASE+810+21)
%GQOS_SETQOS_BADPOLICYOBJ                       = (%QOSSP_ERR_BASE+810+22)
%GQOS_SETQOS_BADFLOWDESC                        = (%QOSSP_ERR_BASE+810+23)
%GQOS_SETQOS_BADPROVSPECOBJ                     = (%QOSSP_ERR_BASE+810+24)
%GQOS_SETQOS_NOLOOPBACK                         = (%QOSSP_ERR_BASE+810+25)
%GQOS_SETQOS_MODENOTSUPPORTED                   = (%QOSSP_ERR_BASE+810+26)
%GQOS_SETQOS_MISSINGFLOWDESC                    = (%QOSSP_ERR_BASE+810+27)

'// SIO_GET_QOS error

%GQOS_GETQOS_BADOUTBUFFER                       = (%QOSSP_ERR_BASE+840+1)
%GQOS_GETQOS_SYSTEMFAILURE                      = (%QOSSP_ERR_BASE+840+2)
%GQOS_GETQOS_EXCEPTION                          = (%QOSSP_ERR_BASE+840+3)
%GQOS_GETQOS_INTERNALFAILURE                    = (%QOSSP_ERR_BASE+840+4)

'// SIO_CHK_QOS error

%GQOS_CHKQOS_BADINBUFFER                        = (%QOSSP_ERR_BASE+850+1)
%GQOS_CHKQOS_BADOUTBUFFER                       = (%QOSSP_ERR_BASE+850+2)
%GQOS_CHKQOS_SYSTEMFAILURE                      = (%QOSSP_ERR_BASE+850+3)
%GQOS_CHKQOS_INTERNALFAILURE                    = (%QOSSP_ERR_BASE+850+4)
%GQOS_CHKQOS_BADPARAMETER                       = (%QOSSP_ERR_BASE+850+5)
%GQOS_CHKQOS_EXCEPTION                          = (%QOSSP_ERR_BASE+850+6)
