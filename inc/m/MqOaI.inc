' ########################################################################################
' Microsoft Windows
' File: MqOaI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSMQ
' Version: 3.0
' Documentation string: Microsoft Message Queue 3.0 Object Library
' Path: C:\Archivos de programa\Microsoft Platform SDK for Windows Server 2003 R2\Lib\MqOA.Tlb
' Library GUID: {D7D6E071-DCCD-11D0-AA4B-0060970DEBAE}
' Note: Must not be used with MQ.INC because there will be conflicts.
' ########################################################################################

#INCLUDE THIS ONCE
%MQOAI_INC = 1

$LIBID_MSMQ = GUID$("{D7D6E071-DCCD-11D0-AA4B-0060970DEBAE}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {D7D6E086-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQApplication1 = "MSMQ.MSMQApplication.1"
$PROGID_MSMQMSMQCoordinatedTransactionDispenser1 = "MSMQ.MSMQCoordinatedTransactionDispenser.1"
' CLSID = {EBA96B18-2168-11D3-898C-00E02C074F6B}
$PROGID_MSMQMSMQDestination1 = "MSMQ.MSMQDestination.1"
' CLSID = {D7D6E07A-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQEvent1 = "MSMQ.MSMQEvent.1"
' CLSID = {39CE96FE-F4C5-4484-A143-4C2D5D324229}
$PROGID_MSMQMSMQManagement1 = "MSMQ.MSMQManagement.1"
' CLSID = {D7D6E075-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQMessage1 = "MSMQ.MSMQMessage.1"
' CLSID = {D7D6E073-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQuery1 = "MSMQ.MSMQQuery.1"
' CLSID = {D7D6E079-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueue1 = "MSMQ.MSMQQueue.1"
' CLSID = {D7D6E07C-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueueInfo1 = "MSMQ.MSMQQueueInfo.1"
' CLSID = {D7D6E07E-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueueInfos1 = "MSMQ.MSMQQueueInfos.1"
' CLSID = {D7D6E080-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQTransaction1 = "MSMQ.MSMQTransaction.1"
' CLSID = {D7D6E084-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQTransactionDispenser1 = "MSMQ.MSMQTransactionDispenser.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {D7D6E086-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQApplication = "MSMQ.MSMQApplication"
' CLSID = {D7D6E082-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQCoordinatedTransactionDispenser = "MSMQ.MSMQCoordinatedTransactionDispenser"
' CLSID = {EBA96B18-2168-11D3-898C-00E02C074F6B}
$PROGID_MSMQMSMQDestination = "MSMQ.MSMQDestination"
' CLSID = {D7D6E07A-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQEvent = "MSMQ.MSMQEvent"
' CLSID = {39CE96FE-F4C5-4484-A143-4C2D5D324229}
$PROGID_MSMQMSMQManagement = "MSMQ.MSMQManagement"
' CLSID = {D7D6E075-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQMessage = "MSMQ.MSMQMessage"
' CLSID = {D7D6E073-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQuery = "MSMQ.MSMQQuery"
' CLSID = {D7D6E079-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueue = "MSMQ.MSMQQueue"
' CLSID = {D7D6E07C-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueueInfo = "MSMQ.MSMQQueueInfo"
' CLSID = {D7D6E07E-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQQueueInfos = "MSMQ.MSMQQueueInfos"
' CLSID = {D7D6E080-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQTransaction = "MSMQ.MSMQTransaction"
' CLSID = {D7D6E084-DCCD-11D0-AA4B-0060970DEBAE}
$PROGID_MSMQMSMQTransactionDispenser = "MSMQ.MSMQTransactionDispenser"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSMQCollection = GUID$("{F72B9031-2F0C-43E8-924E-E6052CDC493F}")
$CLSID_MSMQOutgoingQueueManagement = GUID$("{0188401C-247A-4FED-99C6-BF14119D7055}")
$CLSID_MSMQQueueManagement = GUID$("{33B6D07E-F27D-42FA-B2D7-BF82E11E9374}")
$CLSID_MSMQApplication = GUID$("{D7D6E086-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQCoordinatedTransactionDispenser = GUID$("{D7D6E082-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQDestination = GUID$("{EBA96B18-2168-11D3-898C-00E02C074F6B}")
$CLSID_MSMQEvent = GUID$("{D7D6E07A-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQManagement = GUID$("{39CE96FE-F4C5-4484-A143-4C2D5D324229}")
$CLSID_MSMQMessage = GUID$("{D7D6E075-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQQuery = GUID$("{D7D6E073-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQQueue = GUID$("{D7D6E079-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQQueueInfo = GUID$("{D7D6E07C-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQQueueInfos = GUID$("{D7D6E07E-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQTransaction = GUID$("{D7D6E080-DCCD-11D0-AA4B-0060970DEBAE}")
$CLSID_MSMQTransactionDispenser = GUID$("{D7D6E084-DCCD-11D0-AA4B-0060970DEBAE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IMSMQApplication = GUID$("{D7D6E085-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQApplication2 = GUID$("{12A30900-7300-11D2-B0E6-00E02C074F6B}")
$IID_IMSMQApplication3 = GUID$("{EBA96B1F-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQCollection = GUID$("{0188AC2F-ECB3-4173-9779-635CA2039C72}")
$IID_IMSMQCoordinatedTransactionDispenser = GUID$("{D7D6E081-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQCoordinatedTransactionDispenser2 = GUID$("{EBA96B10-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQCoordinatedTransactionDispenser3 = GUID$("{EBA96B14-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQDestination = GUID$("{EBA96B16-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQEvent = GUID$("{D7D6E077-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQEvent2 = GUID$("{EBA96B12-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQEvent3 = GUID$("{EBA96B1C-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQManagement = GUID$("{BE5F0241-E489-4957-8CC4-A452FCF3E23E}")
$IID_IMSMQMessage = GUID$("{D7D6E074-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQMessage2 = GUID$("{D9933BE0-A567-11D2-B0F3-00E02C074F6B}")
$IID_IMSMQMessage3 = GUID$("{EBA96B1A-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQMessage4 = GUID$("{EBA96B23-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQOutgoingQueueManagement = GUID$("{64C478FB-F9B0-4695-8A7F-439AC94326D3}")
$IID_IMSMQPrivateDestination = GUID$("{EBA96B17-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQPrivateEvent = GUID$("{D7AB3341-C9D3-11D1-BB47-0080C7C5A2C0}")
$IID_IMSMQQuery = GUID$("{D7D6E072-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQQuery2 = GUID$("{EBA96B0E-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQuery3 = GUID$("{EBA96B19-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQuery4 = GUID$("{EBA96B24-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueue = GUID$("{D7D6E076-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQQueue2 = GUID$("{EF0574E0-06D8-11D3-B100-00E02C074F6B}")
$IID_IMSMQQueue3 = GUID$("{EBA96B1B-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueue4 = GUID$("{EBA96B20-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueInfo = GUID$("{D7D6E07B-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQQueueInfo2 = GUID$("{FD174A80-89CF-11D2-B0F2-00E02C074F6B}")
$IID_IMSMQQueueInfo3 = GUID$("{EBA96B1D-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueInfo4 = GUID$("{EBA96B21-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueInfos = GUID$("{D7D6E07D-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQQueueInfos2 = GUID$("{EBA96B0F-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueInfos3 = GUID$("{EBA96B1E-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueInfos4 = GUID$("{EBA96B22-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQQueueManagement = GUID$("{7FBE7759-5760-444D-B8A5-5E7AB9A84CCE}")
$IID_IMSMQTransaction = GUID$("{D7D6E07F-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQTransaction2 = GUID$("{2CE0C5B0-6E67-11D2-B0E6-00E02C074F6B}")
$IID_IMSMQTransaction3 = GUID$("{EBA96B13-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQTransactionDispenser = GUID$("{D7D6E083-DCCD-11D0-AA4B-0060970DEBAE}")
$IID_IMSMQTransactionDispenser2 = GUID$("{EBA96B11-2168-11D3-898C-00E02C074F6B}")
$IID_IMSMQTransactionDispenser3 = GUID$("{EBA96B15-2168-11D3-898C-00E02C074F6B}")
$IID__DMSMQEventEvents = GUID$("{D7D6E078-DCCD-11D0-AA4B-0060970DEBAE}")


' ========================================================================================
' MQCALG enum
' ========================================================================================

%MQMSG_CALG_MD2      = &H8000 + 0     + 1
%MQMSG_CALG_MD4      = &H8000 + 0     + 2
%MQMSG_CALG_MD5      = &H8000 + 0     + 3
%MQMSG_CALG_SHA      = &H8000 + 0     + 4
%MQMSG_CALG_SHA1     = &H8000 + 0     + 4
%MQMSG_CALG_MAC      = &H8000 + 0     + 5
%MQMSG_CALG_RSA_SIGN = &H2000 + &H400 + 0
%MQMSG_CALG_DSS_SIGN = &H2000 + &H200 + 0
%MQMSG_CALG_RSA_KEYX = &Ha000 + &H400 + 0
%MQMSG_CALG_DES      = &H6000 + &H600 + 1
%MQMSG_CALG_RC2      = &H6000 + &H600 + 2
%MQMSG_CALG_RC4      = &H6000 + &H800 + 1
%MQMSG_CALG_SEAL     = &H6000 + &H800 + 2

' ========================================================================================
' MQTRANSACTION enum
' ========================================================================================

%MQ_NO_TRANSACTION  = 0
%MQ_MTS_TRANSACTION = 1
%MQ_XA_TRANSACTION  = 2
%MQ_SINGLE_MESSAGE  = 3

' ========================================================================================
' RELOPS enum
' ========================================================================================

%REL_NOP = 0
%REL_EQ  = %REL_NOP + 1
%REL_NEQ = %REL_EQ  + 1
%REL_LT  = %REL_NEQ + 1
%REL_GT  = %REL_LT  + 1
%REL_LE  = %REL_GT  + 1
%REL_GE  = %REL_LE  + 1

' ========================================================================================
' MQCERT_REGISTER enum
' ========================================================================================

%MQCERT_REGISTER_ALWAYS       = 1
%MQCERT_REGISTER_IF_NOT_EXIST = 2

' ========================================================================================
' MQMSGCURSOR enum
' ========================================================================================

%MQMSG_FIRST   = 0
%MQMSG_CURRENT = 1
%MQMSG_NEXT    = 2

' ========================================================================================
' MQMSGCLASS enum
' ========================================================================================

%MQMSG_CLASS_NORMAL                            = 0      + 0      + 0
%MQMSG_CLASS_REPORT                            = 0      + 0      + &H1
%MQMSG_CLASS_ACK_REACH_QUEUE                   = 0      + 0      + &H2
%MQMSG_CLASS_ACK_RECEIVE                       = 0      + &H4000 + 0
%MQMSG_CLASS_NACK_BAD_DST_Q                    = &H8000 + 0      + 0
%MQMSG_CLASS_NACK_PURGED                       = &H8000 + 0      + &H1
%MQMSG_CLASS_NACK_REACH_QUEUE_TIMEOUT          = &H8000 + 0      + &H2
%MQMSG_CLASS_NACK_Q_EXCEED_QUOTA               = &H8000 + 0      + &H3
%MQMSG_CLASS_NACK_ACCESS_DENIED                = &H8000 + 0      + &H4
%MQMSG_CLASS_NACK_HOP_COUNT_EXCEEDED           = &H8000 + 0      + &H5
%MQMSG_CLASS_NACK_BAD_SIGNATURE                = &H8000 + 0      + &H6
%MQMSG_CLASS_NACK_BAD_ENCRYPTION               = &H8000 + 0      + &H7
%MQMSG_CLASS_NACK_COULD_NOT_ENCRYPT            = &H8000 + 0      + &H8
%MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_Q          = &H8000 + 0      + &H9
%MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_MSG        = &H8000 + 0      + &Ha
%MQMSG_CLASS_NACK_UNSUPPORTED_CRYPTO_PROVIDER  = &H8000 + 0      + &Hb
%MQMSG_CLASS_NACK_SOURCE_COMPUTER_GUID_CHANGED = &H8000 + 0      + &Hc
%MQMSG_CLASS_NACK_Q_DELETED                    = &H8000 + &H4000 + 0
%MQMSG_CLASS_NACK_Q_PURGED                     = &H8000 + &H4000 + &H1
%MQMSG_CLASS_NACK_RECEIVE_TIMEOUT              = &H8000 + &H4000 + &H2
%MQMSG_CLASS_NACK_RECEIVE_TIMEOUT_AT_SENDER    = &H8000 + &H4000 + &H3

' ========================================================================================
' MQMSGDELIVERY enum
' ========================================================================================

%MQMSG_DELIVERY_EXPRESS     = &H0
%MQMSG_DELIVERY_RECOVERABLE = &H1

' ========================================================================================
' MQMSGACKNOWLEDGEMENT enum
' ========================================================================================

%MQMSG_ACKNOWLEDGMENT_NONE             = 0
%MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL      = &H1
%MQMSG_ACKNOWLEDGMENT_POS_RECEIVE      = &H2
%MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL      = &H4
%MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE      = &H8
%MQMSG_ACKNOWLEDGMENT_NACK_REACH_QUEUE = &H4
%MQMSG_ACKNOWLEDGMENT_FULL_REACH_QUEUE = &H4  + &H1
%MQMSG_ACKNOWLEDGMENT_NACK_RECEIVE     = &H4  + &H8
%MQMSG_ACKNOWLEDGMENT_FULL_RECEIVE     = &H4  + &H8  + &H2

' ========================================================================================
' MQMSGJOURNAL enum
' ========================================================================================

%MQMSG_JOURNAL_NONE = 0
%MQMSG_DEADLETTER   = 1
%MQMSG_JOURNAL      = 2

' ========================================================================================
' MQMSGTRACE enum
' ========================================================================================

%MQMSG_TRACE_NONE                 = 0
%MQMSG_SEND_ROUTE_TO_REPORT_QUEUE = 1

' ========================================================================================
' MQMSGSENDERIDTYPE enum
' ========================================================================================

%MQMSG_SENDERID_TYPE_NONE = 0
%MQMSG_SENDERID_TYPE_SID  = 1

' ========================================================================================
' MQMSGPRIVLEVEL enum
' ========================================================================================

%MQMSG_PRIV_LEVEL_NONE          = 0
%MQMSG_PRIV_LEVEL_BODY_BASE     = 1
%MQMSG_PRIV_LEVEL_BODY_ENHANCED = 3

' ========================================================================================
' MQMSGAUTHLEVEL enum
' ========================================================================================

%MQMSG_AUTH_LEVEL_NONE   = 0
%MQMSG_AUTH_LEVEL_ALWAYS = 1
%MQMSG_AUTH_LEVEL_MSMQ10 = 2
%MQMSG_AUTH_LEVEL_SIG10  = 2
%MQMSG_AUTH_LEVEL_MSMQ20 = 4
%MQMSG_AUTH_LEVEL_SIG20  = 4
%MQMSG_AUTH_LEVEL_SIG30  = 8


' ========================================================================================
' MQMSGIDSIZE enum
' ========================================================================================

%MQMSG_MSGID_SIZE         = 20
%MQMSG_CORRELATIONID_SIZE = 20
%MQMSG_XACTID_SIZE        = 20

' ========================================================================================
' MQMSGMAX enum
' Note: This constant is defined as 250 in MQ.INC because it is a C++ header and must
' allow for the terminating null.
' ========================================================================================

%MQ_MAX_MSG_LABEL_LEN = 249

' ========================================================================================
' MQMSGAUTHENTICATION enum
' ========================================================================================

%MQMSG_AUTHENTICATION_NOT_REQUESTED = 0
%MQMSG_AUTHENTICATION_REQUESTED     = 1
%MQMSG_AUTHENTICATED_SIG10          = 1
%MQMSG_AUTHENTICATION_REQUESTED_EX  = 3
%MQMSG_AUTHENTICATED_SIG20          = 3
%MQMSG_AUTHENTICATED_SIG30          = 5
%MQMSG_AUTHENTICATED_SIGXML         = 9

' ========================================================================================
' MQSHARE enum
' ========================================================================================

%MQ_DENY_NONE          = 0
%MQ_DENY_RECEIVE_SHARE = 1

' ========================================================================================
' MQACCESS enum
' ========================================================================================

%MQ_RECEIVE_ACCESS = 1
%MQ_SEND_ACCESS    = 2
%MQ_PEEK_ACCESS    = &H20
%MQ_ADMIN_ACCESS   = &H80

' ========================================================================================
' MQJOURNAL enum
' ========================================================================================

%MQ_JOURNAL_NONE = 0
%MQ_JOURNAL      = 1

' ========================================================================================
' MQTRANSACTIONAL enum
' ========================================================================================

%MQ_TRANSACTIONAL_NONE = 0
%MQ_TRANSACTIONAL      = 1

' ========================================================================================
' MQAUTHENTICATE enum
' ========================================================================================

%MQ_AUTHENTICATE_NONE = 0
%MQ_AUTHENTICATE      = 1

' ========================================================================================
' MQPRIVLEVEL enum
' ========================================================================================

%MQ_PRIV_LEVEL_NONE     = 0
%MQ_PRIV_LEVEL_OPTIONAL = 1
%MQ_PRIV_LEVEL_BODY     = 2

' ========================================================================================
' MQPRIORITY enum
' ========================================================================================

%MQ_MIN_PRIORITY = 0
%MQ_MAX_PRIORITY = 7

' ========================================================================================
' MQMAX enum
' ========================================================================================

%MQ_MAX_Q_NAME_LEN  = 124
%MQ_MAX_Q_LABEL_LEN = 124

' ========================================================================================
' QUEUE_TYPE enum
' ========================================================================================

%MQ_TYPE_PUBLIC    = 0
%MQ_TYPE_PRIVATE   = %MQ_TYPE_PUBLIC    + 1
%MQ_TYPE_MACHINE   = %MQ_TYPE_PRIVATE   + 1
%MQ_TYPE_CONNECTOR = %MQ_TYPE_MACHINE   + 1
%MQ_TYPE_MULTICAST = %MQ_TYPE_CONNECTOR + 1

' ========================================================================================
' FOREIGN_STATUS enum
' ========================================================================================

%MQ_STATUS_FOREIGN     = 0
%MQ_STATUS_NOT_FOREIGN = %MQ_STATUS_FOREIGN     + 1
%MQ_STATUS_UNKNOWN     = %MQ_STATUS_NOT_FOREIGN + 1

' ========================================================================================
' XACT_STATUS enum
' ========================================================================================

%MQ_XACT_STATUS_XACT     = 0
%MQ_XACT_STATUS_NOT_XACT = %MQ_XACT_STATUS_XACT     + 1
%MQ_XACT_STATUS_UNKNOWN  = %MQ_XACT_STATUS_NOT_XACT + 1

' ========================================================================================
' QUEUE_STATE enum
' ========================================================================================

%MQ_QUEUE_STATE_LOCAL_CONNECTION = 0
%MQ_QUEUE_STATE_DISCONNECTED     = %MQ_QUEUE_STATE_LOCAL_CONNECTION + 1
%MQ_QUEUE_STATE_WAITING          = %MQ_QUEUE_STATE_DISCONNECTED     + 1
%MQ_QUEUE_STATE_NEEDVALIDATE     = %MQ_QUEUE_STATE_WAITING          + 1
%MQ_QUEUE_STATE_ONHOLD           = %MQ_QUEUE_STATE_NEEDVALIDATE     + 1
%MQ_QUEUE_STATE_NONACTIVE        = %MQ_QUEUE_STATE_ONHOLD           + 1
%MQ_QUEUE_STATE_CONNECTED        = %MQ_QUEUE_STATE_NONACTIVE        + 1
%MQ_QUEUE_STATE_DISCONNECTING    = %MQ_QUEUE_STATE_CONNECTED        + 1
%MQ_QUEUE_STATE_LOCKED           = %MQ_QUEUE_STATE_DISCONNECTING    + 1

' ========================================================================================
' MQDEFAULT enum
' ========================================================================================

%DEFAULT_M_PRIORITY      = 3
%DEFAULT_M_DELIVERY      = 0
%DEFAULT_M_ACKNOWLEDGE   = 0
%DEFAULT_M_JOURNAL       = 0
%DEFAULT_M_APPSPECIFIC   = 0
%DEFAULT_M_PRIV_LEVEL    = 0
%DEFAULT_M_AUTH_LEVEL    = 0
%DEFAULT_M_SENDERID_TYPE = 1
%DEFAULT_Q_JOURNAL       = 0
%DEFAULT_Q_BASEPRIORITY  = 0
%DEFAULT_Q_QUOTA         = &Hffffffff
%DEFAULT_Q_JOURNAL_QUOTA = &Hffffffff
%DEFAULT_Q_TRANSACTION   = 0
%DEFAULT_Q_AUTHENTICATE  = 0
%DEFAULT_Q_PRIV_LEVEL    = 1
%DEFAULT_M_LOOKUPID      = 0

' ========================================================================================
' MQERROR enum
' ========================================================================================

%MQ_ERROR                                            = &Hc00e0001&
%MQ_ERROR_PROPERTY                                   = &Hc00e0002&
%MQ_ERROR_QUEUE_NOT_FOUND                            = &Hc00e0003&
%MQ_ERROR_QUEUE_NOT_ACTIVE                           = &Hc00e0004&
%MQ_ERROR_QUEUE_EXISTS                               = &Hc00e0005&
%MQ_ERROR_INVALID_PARAMETER                          = &Hc00e0006&
%MQ_ERROR_INVALID_HANDLE                             = &Hc00e0007&
%MQ_ERROR_OPERATION_CANCELLED                        = &Hc00e0008&
%MQ_ERROR_SHARING_VIOLATION                          = &Hc00e0009&
%MQ_ERROR_SERVICE_NOT_AVAILABLE                      = &Hc00e000b&
%MQ_ERROR_MACHINE_NOT_FOUND                          = &Hc00e000d&
%MQ_ERROR_ILLEGAL_SORT                               = &Hc00e0010&
%MQ_ERROR_ILLEGAL_USER                               = &Hc00e0011&
%MQ_ERROR_NO_DS                                      = &Hc00e0013&
%MQ_ERROR_ILLEGAL_QUEUE_PATHNAME                     = &Hc00e0014&
%MQ_ERROR_ILLEGAL_PROPERTY_VALUE                     = &Hc00e0018&
%MQ_ERROR_ILLEGAL_PROPERTY_VT                        = &Hc00e0019&
%MQ_ERROR_BUFFER_OVERFLOW                            = &Hc00e001a&
%MQ_ERROR_IO_TIMEOUT                                 = &Hc00e001b&
%MQ_ERROR_ILLEGAL_CURSOR_ACTION                      = &Hc00e001c&
%MQ_ERROR_MESSAGE_ALREADY_RECEIVED                   = &Hc00e001d&
%MQ_ERROR_ILLEGAL_FORMATNAME                         = &Hc00e001e&
%MQ_ERROR_FORMATNAME_BUFFER_TOO_SMALL                = &Hc00e001f&
%MQ_ERROR_UNSUPPORTED_FORMATNAME_OPERATION           = &Hc00e0020&
%MQ_ERROR_ILLEGAL_SECURITY_DESCRIPTOR                = &Hc00e0021&
%MQ_ERROR_SENDERID_BUFFER_TOO_SMALL                  = &Hc00e0022&
%MQ_ERROR_SECURITY_DESCRIPTOR_TOO_SMALL              = &Hc00e0023&
%MQ_ERROR_CANNOT_IMPERSONATE_CLIENT                  = &Hc00e0024&
%MQ_ERROR_ACCESS_DENIED                              = &Hc00e0025&
%MQ_ERROR_PRIVILEGE_NOT_HELD                         = &Hc00e0026&
%MQ_ERROR_INSUFFICIENT_RESOURCES                     = &Hc00e0027&
%MQ_ERROR_USER_BUFFER_TOO_SMALL                      = &Hc00e0028&
%MQ_ERROR_MESSAGE_STORAGE_FAILED                     = &Hc00e002a&
%MQ_ERROR_SENDER_CERT_BUFFER_TOO_SMALL               = &Hc00e002b&
%MQ_ERROR_INVALID_CERTIFICATE                        = &Hc00e002c&
%MQ_ERROR_CORRUPTED_INTERNAL_CERTIFICATE             = &Hc00e002d&
%MQ_ERROR_INTERNAL_USER_CERT_EXIST                   = &Hc00e002e&
%MQ_ERROR_NO_INTERNAL_USER_CERT                      = &Hc00e002f&
%MQ_ERROR_CORRUPTED_SECURITY_DATA                    = &Hc00e0030&
%MQ_ERROR_CORRUPTED_PERSONAL_CERT_STORE              = &Hc00e0031&
%MQ_ERROR_COMPUTER_DOES_NOT_SUPPORT_ENCRYPTION       = &Hc00e0033&
%MQ_ERROR_BAD_SECURITY_CONTEXT                       = &Hc00e0035&
%MQ_ERROR_COULD_NOT_GET_USER_SID                     = &Hc00e0036&
%MQ_ERROR_COULD_NOT_GET_ACCOUNT_INFO                 = &Hc00e0037&
%MQ_ERROR_ILLEGAL_MQCOLUMNS                          = &Hc00e0038&
%MQ_ERROR_ILLEGAL_PROPID                             = &Hc00e0039&
%MQ_ERROR_ILLEGAL_RELATION                           = &Hc00e003a&
%MQ_ERROR_ILLEGAL_PROPERTY_SIZE                      = &Hc00e003b&
%MQ_ERROR_ILLEGAL_RESTRICTION_PROPID                 = &Hc00e003c&
%MQ_ERROR_ILLEGAL_MQQUEUEPROPS                       = &Hc00e003d&
%MQ_ERROR_PROPERTY_NOTALLOWED                        = &Hc00e003e&
%MQ_ERROR_INSUFFICIENT_PROPERTIES                    = &Hc00e003f&
%MQ_ERROR_MACHINE_EXISTS                             = &Hc00e0040&
%MQ_ERROR_ILLEGAL_MQQMPROPS                          = &Hc00e0041&
%MQ_ERROR_DS_IS_FULL                                 = &Hc00e0042&
%MQ_ERROR_DS_ERROR                                   = &Hc00e0043&
%MQ_ERROR_INVALID_OWNER                              = &Hc00e0044&
%MQ_ERROR_UNSUPPORTED_ACCESS_MODE                    = &Hc00e0045&
%MQ_ERROR_RESULT_BUFFER_TOO_SMALL                    = &Hc00e0046&
%MQ_ERROR_DELETE_CN_IN_USE                           = &Hc00e0048&
%MQ_ERROR_NO_RESPONSE_FROM_OBJECT_SERVER             = &Hc00e0049&
%MQ_ERROR_OBJECT_SERVER_NOT_AVAILABLE                = &Hc00e004a&
%MQ_ERROR_QUEUE_NOT_AVAILABLE                        = &Hc00e004b&
%MQ_ERROR_DTC_CONNECT                                = &Hc00e004c&
%MQ_ERROR_TRANSACTION_IMPORT                         = &Hc00e004e&
%MQ_ERROR_TRANSACTION_USAGE                          = &Hc00e0050&
%MQ_ERROR_TRANSACTION_SEQUENCE                       = &Hc00e0051&
%MQ_ERROR_MISSING_CONNECTOR_TYPE                     = &Hc00e0055&
%MQ_ERROR_STALE_HANDLE                               = &Hc00e0056&
%MQ_ERROR_TRANSACTION_ENLIST                         = &Hc00e0058&
%MQ_ERROR_QUEUE_DELETED                              = &Hc00e005a&
%MQ_ERROR_ILLEGAL_CONTEXT                            = &Hc00e005b&
%MQ_ERROR_ILLEGAL_SORT_PROPID                        = &Hc00e005c&
%MQ_ERROR_LABEL_TOO_LONG                             = &Hc00e005d&
%MQ_ERROR_LABEL_BUFFER_TOO_SMALL                     = &Hc00e005e&
%MQ_ERROR_MQIS_SERVER_EMPTY                          = &Hc00e005f&
%MQ_ERROR_MQIS_READONLY_MODE                         = &Hc00e0060&
%MQ_ERROR_SYMM_KEY_BUFFER_TOO_SMALL                  = &Hc00e0061&
%MQ_ERROR_SIGNATURE_BUFFER_TOO_SMALL                 = &Hc00e0062&
%MQ_ERROR_PROV_NAME_BUFFER_TOO_SMALL                 = &Hc00e0063&
%MQ_ERROR_ILLEGAL_OPERATION                          = &Hc00e0064&
%MQ_ERROR_WRITE_NOT_ALLOWED                          = &Hc00e0065&
%MQ_ERROR_WKS_CANT_SERVE_CLIENT                      = &Hc00e0066&
%MQ_ERROR_DEPEND_WKS_LICENSE_OVERFLOW                = &Hc00e0067&
%MQ_CORRUPTED_QUEUE_WAS_DELETED                      = &Hc00e0068&
%MQ_ERROR_REMOTE_MACHINE_NOT_AVAILABLE               = &Hc00e0069&
%MQ_ERROR_UNSUPPORTED_OPERATION                      = &Hc00e006a&
%MQ_ERROR_ENCRYPTION_PROVIDER_NOT_SUPPORTED          = &Hc00e006b&
%MQ_ERROR_CANNOT_SET_CRYPTO_SEC_DESCR                = &Hc00e006c&
%MQ_ERROR_CERTIFICATE_NOT_PROVIDED                   = &Hc00e006d&
%MQ_ERROR_Q_DNS_PROPERTY_NOT_SUPPORTED               = &Hc00e006e&
%MQ_ERROR_CANT_CREATE_CERT_STORE                     = &Hc00e006f&
%MQ_ERROR_CANNOT_CREATE_CERT_STORE                   = &Hc00e006f&
%MQ_ERROR_CANT_OPEN_CERT_STORE                       = &Hc00e0070&
%MQ_ERROR_CANNOT_OPEN_CERT_STORE                     = &Hc00e0070&
%MQ_ERROR_ILLEGAL_ENTERPRISE_OPERATION               = &Hc00e0071&
%MQ_ERROR_CANNOT_GRANT_ADD_GUID                      = &Hc00e0072&
%MQ_ERROR_CANNOT_LOAD_MSMQOCM                        = &Hc00e0073&
%MQ_ERROR_NO_ENTRY_POINT_MSMQOCM                     = &Hc00e0074&
%MQ_ERROR_NO_MSMQ_SERVERS_ON_DC                      = &Hc00e0075&
%MQ_ERROR_CANNOT_JOIN_DOMAIN                         = &Hc00e0076&
%MQ_ERROR_CANNOT_CREATE_ON_GC                        = &Hc00e0077&
%MQ_ERROR_GUID_NOT_MATCHING                          = &Hc00e0078&
%MQ_ERROR_PUBLIC_KEY_NOT_FOUND                       = &Hc00e0079&
%MQ_ERROR_PUBLIC_KEY_DOES_NOT_EXIST                  = &Hc00e007a&
%MQ_ERROR_ILLEGAL_MQPRIVATEPROPS                     = &Hc00e007b&
%MQ_ERROR_NO_GC_IN_DOMAIN                            = &Hc00e007c&
%MQ_ERROR_NO_MSMQ_SERVERS_ON_GC                      = &Hc00e007d&
%MQ_ERROR_CANNOT_GET_DN                              = &Hc00e007e&
%MQ_ERROR_CANNOT_HASH_DATA_EX                        = &Hc00e007f&
%MQ_ERROR_CANNOT_SIGN_DATA_EX                        = &Hc00e0080&
%MQ_ERROR_CANNOT_CREATE_HASH_EX                      = &Hc00e0081&
%MQ_ERROR_FAIL_VERIFY_SIGNATURE_EX                   = &Hc00e0082&
%MQ_ERROR_CANNOT_DELETE_PSC_OBJECTS                  = &Hc00e0083&
%MQ_ERROR_NO_MQUSER_OU                               = &Hc00e0084&
%MQ_ERROR_CANNOT_LOAD_MQAD                           = &Hc00e0085&
%MQ_ERROR_CANNOT_LOAD_MQDSSRV                        = &Hc00e0086&
%MQ_ERROR_PROPERTIES_CONFLICT                        = &Hc00e0087&
%MQ_ERROR_MESSAGE_NOT_FOUND                          = &Hc00e0088&
%MQ_ERROR_CANT_RESOLVE_SITES                         = &Hc00e0089&
%MQ_ERROR_NOT_SUPPORTED_BY_DEPENDENT_CLIENTS         = &Hc00e008a&
%MQ_ERROR_OPERATION_NOT_SUPPORTED_BY_REMOTE_COMPUTER = &Hc00e008b&
%MQ_ERROR_NOT_A_CORRECT_OBJECT_CLASS                 = &Hc00e008c&
%MQ_ERROR_MULTI_SORT_KEYS                            = &Hc00e008d&
%MQ_ERROR_GC_NEEDED                                  = &Hc00e008e&
%MQ_ERROR_DS_BIND_ROOT_FOREST                        = &Hc00e008f&
%MQ_ERROR_DS_LOCAL_USER                              = &Hc00e0090&
%MQ_ERROR_Q_ADS_PROPERTY_NOT_SUPPORTED               = &Hc00e0091&
%MQ_ERROR_BAD_XML_FORMAT                             = &Hc00e0092&
%MQ_ERROR_UNSUPPORTED_CLASS                          = &Hc00e0093&
%MQ_ERROR_UNINITIALIZED_OBJECT                       = &Hc00e0094&
%MQ_ERROR_CANNOT_CREATE_PSC_OBJECTS                  = &Hc00e0095&
%MQ_ERROR_CANNOT_UPDATE_PSC_OBJECTS                  = &Hc00e0096&

' ========================================================================================
' MQWARNING enum
' ========================================================================================

%MQ_INFORMATION_PROPERTY                    = &H400e0001&
%MQ_INFORMATION_ILLEGAL_PROPERTY            = &H400e0002&
%MQ_INFORMATION_PROPERTY_IGNORED            = &H400e0003&
%MQ_INFORMATION_UNSUPPORTED_PROPERTY        = &H400e0004&
%MQ_INFORMATION_DUPLICATE_PROPERTY          = &H400e0005&
%MQ_INFORMATION_OPERATION_PENDING           = &H400e0006&
%MQ_INFORMATION_FORMATNAME_BUFFER_TOO_SMALL = &H400e0009&
%MQ_INFORMATION_INTERNAL_USER_CERT_EXIST    = &H400e000a&
%MQ_INFORMATION_OWNER_IGNORED               = &H400e000b&


' ########################################################################################
' Interface name = IMSMQQuery
' IID = {D7D6E072-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQuery_INTERFACE_DEFINED)
    %IMSMQQuery_INTERFACE_DEFINED = 1

INTERFACE IMSMQQuery $IID_IMSMQQuery

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LookupQueue <1610743808> ( _                  ' VTable offset = 28
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   ) AS IMSMQQueueInfos                                 ' __retval_out IMSMQQueueInfos **ppqinfos
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQuery_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfo
' IID = {D7D6E07B-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfo_INTERFACE_DEFINED)
    %IMSMQQueueInfo_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfo $IID_IMSMQQueueInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET QueueGuid <0> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidQueue
   ' =====================================================================================
   PROPERTY GET ServiceTypeGuid <1> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidServiceType
   ' =====================================================================================
   PROPERTY SET ServiceTypeGuid <1> ( _                 ' VTable offset = 36
     BYVAL bstrGuidServiceType AS WSTRING _             ' __in BSTR bstrGuidServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <2> ( _                           ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <2> ( _                           ' VTable offset = 44
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathName <3> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathName
   ' =====================================================================================
   PROPERTY SET PathName <3> ( _                        ' VTable offset = 52
     BYVAL bstrPathName AS WSTRING _                    ' __in BSTR bstrPathName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <5> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY SET FormatName <5> ( _                      ' VTable offset = 60
     BYVAL bstrFormatName AS WSTRING _                  ' __in BSTR bstrFormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional <6> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out Boolean *pisTransactional
   ' =====================================================================================
   PROPERTY GET PrivLevel <7> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <7> ( _                       ' VTable offset = 72
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <8> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <8> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quota <13> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plQuota
   ' =====================================================================================
   PROPERTY SET Quota <13> ( _                          ' VTable offset = 88
     BYVAL lQuota AS LONG _                             ' __in long lQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BasePriority <9> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plBasePriority
   ' =====================================================================================
   PROPERTY SET BasePriority <9> ( _                    ' VTable offset = 96
     BYVAL lBasePriority AS LONG _                      ' __in long lBasePriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreateTime <10> ( _                     ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCreateTime
   ' =====================================================================================
   PROPERTY GET ModifyTime <11> ( _                     ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModifyTime
   ' =====================================================================================
   PROPERTY GET Authenticate <12> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plAuthenticate
   ' =====================================================================================
   PROPERTY SET Authenticate <12> ( _                   ' VTable offset = 112
     BYVAL lAuthenticate AS LONG _                      ' __in long lAuthenticate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET JournalQuota <14> ( _                   ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plJournalQuota
   ' =====================================================================================
   PROPERTY SET JournalQuota <14> ( _                   ' VTable offset = 120
     BYVAL lJournalQuota AS LONG _                      ' __in long lJournalQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsWorldReadable <15> ( _                ' VTable offset = 124
   ) AS BYTE                                            ' __retval_out Boolean *pisWorldReadable
   ' =====================================================================================
   METHOD Create <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYREF IsTransactional AS VARIANT _        ' __in_opt VARIANT *IsTransactional
   , OPTIONAL BYREF IsWorldReadable AS VARIANT _        ' __in_opt VARIANT *IsWorldReadable
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743834> ( _                       ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1610743835> ( _                         ' VTable offset = 136
     BYVAL Access AS LONG _                             ' __in long Access
   , BYVAL ShareMode AS LONG _                          ' __in long ShareMode
   ) AS IMSMQQueue                                      ' __retval_out IMSMQQueue **ppq
   ' =====================================================================================
   METHOD Refresh <1610743836> ( _                      ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1610743837> ( _                       ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfo2
' IID = {FD174A80-89CF-11D2-B0F2-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfo2_INTERFACE_DEFINED)
    %IMSMQQueueInfo2_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfo2 $IID_IMSMQQueueInfo2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET QueueGuid <0> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidQueue
   ' =====================================================================================
   PROPERTY GET ServiceTypeGuid <1> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidServiceType
   ' =====================================================================================
   PROPERTY SET ServiceTypeGuid <1> ( _                 ' VTable offset = 36
     BYVAL bstrGuidServiceType AS WSTRING _             ' __in BSTR bstrGuidServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <2> ( _                           ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <2> ( _                           ' VTable offset = 44
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathName <3> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathName
   ' =====================================================================================
   PROPERTY SET PathName <3> ( _                        ' VTable offset = 52
     BYVAL bstrPathName AS WSTRING _                    '  __in BSTR bstrPathName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <5> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY SET FormatName <5> ( _                      ' VTable offset = 60
     BYVAL bstrFormatName AS WSTRING _                  ' __in BSTR bstrFormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional <6> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out Boolean *pisTransactional
   ' =====================================================================================
   PROPERTY GET PrivLevel <7> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <7> ( _                       ' VTable offset = 72
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <8> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <8> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quota <13> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plQuota
   ' =====================================================================================
   PROPERTY SET Quota <13> ( _                          ' VTable offset = 88
     BYVAL lQuota AS LONG _                             ' __in long lQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BasePriority <9> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plBasePriority
   ' =====================================================================================
   PROPERTY SET BasePriority <9> ( _                    ' VTable offset = 96
     BYVAL lBasePriority AS LONG _                      ' __in long lBasePriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreateTime <10> ( _                     ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCreateTime
   ' =====================================================================================
   PROPERTY GET ModifyTime <11> ( _                     ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModifyTime
   ' =====================================================================================
   PROPERTY GET Authenticate <12> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plAuthenticate
   ' =====================================================================================
   PROPERTY SET Authenticate <12> ( _                   ' VTable offset = 112
     BYVAL lAuthenticate AS LONG _                      ' __in long lAuthenticate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET JournalQuota <14> ( _                   ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plJournalQuota
   ' =====================================================================================
   PROPERTY SET JournalQuota <14> ( _                   ' VTable offset = 120
     BYVAL lJournalQuota AS LONG _                      ' __in long lJournalQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsWorldReadable <15> ( _                ' VTable offset = 124
   ) AS BYTE                                            ' __retval_out Boolean *pisWorldReadable
   ' =====================================================================================
   METHOD Create <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYREF IsTransactional AS VARIANT _        ' __in_opt VARIANT *IsTransactional
   , OPTIONAL BYREF IsWorldReadable AS VARIANT _        ' __in_opt VARIANT *IsWorldReadable
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743834> ( _                       ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1610743835> ( _                         ' VTable offset = 136
     BYVAL Access AS LONG _                             ' __in long Access
   , BYVAL ShareMode AS LONG _                          ' __in long ShareMode
   ) AS IMSMQQueue2                                     ' __retval_out IMSMQQueue2 **ppq
   ' =====================================================================================
   METHOD Refresh <1610743836> ( _                      ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1610743837> ( _                       ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathNameDNS <16> ( _                    ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathNameDNS
   ' =====================================================================================
   PROPERTY GET Properties <17> ( _                     ' VTable offset = 152
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET Security <18> ( _                       ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSecurity
   ' =====================================================================================
   PROPERTY SET Security <18> ( _                       ' VTable offset = 160
     BYVAL varSecurity AS VARIANT _                     ' __in VARIANT varSecurity
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfo2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfo3
' IID = {EBA96B1D-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfo3_INTERFACE_DEFINED)
    %IMSMQQueueInfo3_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfo3 $IID_IMSMQQueueInfo3

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET QueueGuid <0> ( _                       ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidQueue
   ' =====================================================================================
   PROPERTY GET ServiceTypeGuid <1> ( _                 ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidServiceType
   ' =====================================================================================
   PROPERTY SET ServiceTypeGuid <1> ( _                 ' VTable offset = 36
     BYVAL bstrGuidServiceType AS WSTRING _             ' __in BSTR bstrGuidServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <2> ( _                           ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <2> ( _                           ' VTable offset = 44
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathName <3> ( _                        ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathName
   ' =====================================================================================
   PROPERTY SET PathName <3> ( _                        ' VTable offset = 52
     BYVAL bstrPathName AS WSTRING _                    ' __in BSTR bstrPathName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <5> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY SET FormatName <5> ( _                      ' VTable offset = 60
     BYVAL bstrFormatName AS WSTRING _                  ' __in BSTR bstrFormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional <6> ( _                 ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out Boolean *pisTransactional
   ' =====================================================================================
   PROPERTY GET PrivLevel <7> ( _                       ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <7> ( _                       ' VTable offset = 72
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <8> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <8> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quota <13> ( _                          ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plQuota
   ' =====================================================================================
   PROPERTY SET Quota <13> ( _                          ' VTable offset = 88
     BYVAL lQuota AS LONG _                             ' __in long lQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BasePriority <9> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plBasePriority
   ' =====================================================================================
   PROPERTY SET BasePriority <9> ( _                    ' VTable offset = 96
     BYVAL lBasePriority AS LONG _                      ' __in long lBasePriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreateTime <10> ( _                     ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCreateTime
   ' =====================================================================================
   PROPERTY GET ModifyTime <11> ( _                     ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModifyTime
   ' =====================================================================================
   PROPERTY GET Authenticate <12> ( _                   ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plAuthenticate
   ' =====================================================================================
   PROPERTY SET Authenticate <12> ( _                   ' VTable offset = 112
     BYVAL lAuthenticate AS LONG _                      ' __in long lAuthenticate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET JournalQuota <14> ( _                   ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plJournalQuota
   ' =====================================================================================
   PROPERTY SET JournalQuota <14> ( _                   ' VTable offset = 120
     BYVAL lJournalQuota AS LONG _                      ' __in long lJournalQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsWorldReadable <15> ( _                ' VTable offset = 124
   ) AS BYTE                                            ' __retval_out Boolean *pisWorldReadable
   ' =====================================================================================
   METHOD Create <1610743833> ( _                       ' VTable offset = 128
     OPTIONAL BYREF IsTransactional AS VARIANT _        ' __in_opt VARIANT *IsTransactional
   , OPTIONAL BYREF IsWorldReadable AS VARIANT _        ' __in_opt VARIANT *IsWorldReadable
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete <1610743834> ( _                       ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Open <1610743835> ( _                         ' VTable offset = 136
     BYVAL Access AS LONG _                             ' __in long Access
   , BYVAL ShareMode AS LONG _                          ' __in long ShareMode
   ) AS IMSMQQueue3                                     ' __retval_out IMSMQQueue3 **ppq
   ' =====================================================================================
   METHOD Refresh <1610743836> ( _                      ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD Update <1610743837> ( _                       ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathNameDNS <16> ( _                    ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathNameDNS
   ' =====================================================================================
   PROPERTY GET Properties <17> ( _                     ' VTable offset = 152
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET Security <18> ( _                       ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSecurity
   ' =====================================================================================
   PROPERTY SET Security <18> ( _                       ' VTable offset = 160
     BYVAL varSecurity AS VARIANT _                     ' __in VARIANT varSecurity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional2 <20> ( _               ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisTransactional
   ' =====================================================================================
   PROPERTY GET IsWorldReadable2 <21> ( _               ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisWorldReadable
   ' =====================================================================================
   PROPERTY GET MulticastAddress <22> ( _               ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMulticastAddress
   ' =====================================================================================
   PROPERTY SET MulticastAddress <22> ( _               ' VTable offset = 176
     BYVAL bstrMulticastAddress AS WSTRING _            ' __in BSTR bstrMulticastAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ADsPath <19> ( _                        ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrADsPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfo3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfo4
' IID = {EBA96B21-2168-11D3-898C-00E02C074F6B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfo4_INTERFACE_DEFINED)
    %IMSMQQueueInfo4_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfo4 $IID_IMSMQQueueInfo4

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET QueueGuid ( _                           ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidQueue
   ' =====================================================================================
   PROPERTY GET ServiceTypeGuid ( _                     ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidServiceType
   ' =====================================================================================
   PROPERTY SET ServiceTypeGuid ( _                     ' VTable offset = 36
     BYVAL bstrGuidServiceType AS WSTRING _             ' __in BSTR bstrGuidServiceType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label ( _                               ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label ( _                               ' VTable offset = 44
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathName ( _                            ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathName
   ' =====================================================================================
   PROPERTY SET PathName ( _                            ' VTable offset = 52
     BYVAL bstrPathName AS WSTRING _                    ' __in BSTR bstrPathName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName ( _                          ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY SET FormatName ( _                          ' VTable offset = 60
     BYVAL bstrFormatName AS WSTRING _                  ' __in BSTR bstrFormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional ( _                     ' VTable offset = 64
   ) AS BYTE                                            ' __retval_out Boolean *pisTransactional
   ' =====================================================================================
   PROPERTY GET PrivLevel ( _                           ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel ( _                           ' VTable offset = 72
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal ( _                             ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal ( _                             ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Quota ( _                               ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *plQuota
   ' =====================================================================================
   PROPERTY SET Quota ( _                               ' VTable offset = 88
     BYVAL lQuota AS LONG _                             ' __in long lQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BasePriority ( _                        ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plBasePriority
   ' =====================================================================================
   PROPERTY SET BasePriority ( _                        ' VTable offset = 96
     BYVAL lBasePriority AS LONG _                      ' __in long lBasePriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CreateTime ( _                          ' VTable offset = 100
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCreateTime
   ' =====================================================================================
   PROPERTY GET ModifyTime ( _                          ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarModifyTime
   ' =====================================================================================
   PROPERTY GET Authenticate ( _                        ' VTable offset = 108
   ) AS LONG                                            ' __retval_out long *plAuthenticate
   ' =====================================================================================
   PROPERTY SET Authenticate ( _                        ' VTable offset = 112
     BYVAL lAuthenticate AS LONG _                      ' __in long lAuthenticate
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET JournalQuota ( _                        ' VTable offset = 116
   ) AS LONG                                            ' __retval_out long *plJournalQuota
   ' =====================================================================================
   PROPERTY SET JournalQuota ( _                        ' VTable offset = 120
     BYVAL lJournalQuota AS LONG _                      ' __in long lJournalQuota
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsWorldReadable ( _                     ' VTable offset = 124
   ) AS BYTE                                            ' __retval_out Boolean *pisWorldReadable
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 128
     OPTIONAL BYREF IsTransactional AS VARIANT _        ' __in_opt VARIANT *IsTransactional,
   , OPTIONAL BYREF IsWorldReadable AS VARIANT _        ' __in_opt VARIANT *IsWorldReadable) = 0;
   )                                                    ' void
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 132
   )                                                    ' void
   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 136
     BYVAL Access AS LONG _                             ' __in long Access
   , BYVAL ShareMode AS LONG _                          ' __in long ShareMode
   ) AS IMSMQQueue4                                     ' __retval_out IMSMQQueue4 **ppq
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 140
   )                                                    ' void
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 144
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathNameDNS ( _                         ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathNameDNS
   ' =====================================================================================
   PROPERTY GET Properties ( _                          ' VTable offset = 152
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET Security ( _                            ' VTable offset = 156
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSecurity
   ' =====================================================================================
   PROPERTY SET Security ( _                            ' VTable offset = 160
     BYVAL varSecurity AS VARIANT _                     ' __in VARIANT varSecurity
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsTransactional2 ( _                    ' VTable offset = 164
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisTransactional
   ' =====================================================================================
   PROPERTY GET IsWorldReadable2 ( _                    ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisWorldReadable
   ' =====================================================================================
   PROPERTY GET MulticastAddress ( _                    ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMulticastAddress
   ' =====================================================================================
   PROPERTY SET MulticastAddress ( _                    ' VTable offset = 176
     BYVAL bstrMulticastAddress AS WSTRING _            ' __in BSTR bstrMulticastAddress
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ADsPath ( _                             ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrADsPath
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfo4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueue
' IID = {D7D6E076-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueue_INTERFACE_DEFINED)
    %IMSMQQueue_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueue $IID_IMSMQQueue

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Access <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plAccess
   ' =====================================================================================
   PROPERTY GET ShareMode <2> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plShareMode
   ' =====================================================================================
   PROPERTY GET QueueInfo <3> ( _                       ' VTable offset = 36
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfo
   ' =====================================================================================
   PROPERTY GET Handle <0> ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plHandle
   ' =====================================================================================
   PROPERTY GET IsOpen <4> ( _                          ' VTable offset = 44
   ) AS BYTE                                            ' __retval_out Boolean *pisOpen
   ' =====================================================================================
   METHOD Close <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Receive <1610743814> ( _                      ' VTable offset = 52
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Peek <1610743815> ( _                         ' VTable offset = 56
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD EnableNotification <1610743816> ( _           ' VTable offset = 60
     BYVAL Event AS IMSMQEvent _                        ' __in IMSMQEvent *Event
   , OPTIONAL BYREF Cursor AS VARIANT _                 ' __in_opt VARIANT *Cursor
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743817> ( _                        ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD ReceiveCurrent <1610743818> ( _               ' VTable offset = 68
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekNext <1610743819> ( _                     ' VTable offset = 72
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent <1610743820> ( _                  ' VTable offset = 76
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueue_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueue2
' IID = {EF0574E0-06D8-11D3-B100-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueue2_INTERFACE_DEFINED)
    %IMSMQQueue2_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueue2 $IID_IMSMQQueue2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Access <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plAccess
   ' =====================================================================================
   PROPERTY GET ShareMode <2> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plShareMode
   ' =====================================================================================
   PROPERTY GET QueueInfo <3> ( _                       ' VTable offset = 36
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfo
   ' =====================================================================================
   PROPERTY GET Handle <0> ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plHandle
   ' =====================================================================================
   PROPERTY GET IsOpen <4> ( _                          ' VTable offset = 44
   ) AS BYTE                                            ' __retval_out Boolean *pisOpen
   ' =====================================================================================
   METHOD Close <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Receive_v1 <1610743814> ( _                   ' VTable offset = 52
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Peek_v1 <1610743815> ( _                      ' VTable offset = 56
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD EnableNotification <1610743816> ( _           ' VTable offset = 60
     BYVAL Event AS IMSMQEvent2 _                       ' __in IMSMQEvent2 *Event
   , OPTIONAL BYREF Cursor AS VARIANT _                 ' __in_opt VARIANT *Cursor
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743817> ( _                        ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD ReceiveCurrent_v1 <1610743818> ( _            ' VTable offset = 68
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekNext_v1 <1610743819> ( _                  ' VTable offset = 72
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent_v1 <1610743820> ( _               ' VTable offset = 76
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Receive <1610743821> ( _                      ' VTable offset = 80
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         '__in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage2                                   ' __retval_out IMSMQMessage2 **ppmsg
   ' =====================================================================================
   METHOD Peek <1610743822> ( _                         ' VTable offset = 84
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage2                                   ' __retval_out IMSMQMessage2 **ppmsg
   ' =====================================================================================
   METHOD ReceiveCurrent <1610743823> ( _               ' VTable offset = 88
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage2                                   ' __retval_out IMSMQMessage2 **ppmsg
   ' =====================================================================================
   METHOD PeekNext <1610743824> ( _                     ' VTable offset = 92
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage2                                   ' __retval_out IMSMQMessage2 **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent <1610743825> ( _                  ' VTable offset = 96
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage2                                   ' __retval_out IMSMQMessage2 **ppmsg
   ' =====================================================================================
   PROPERTY GET Properties <5> ( _                      ' VTable offset = 100
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueue2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueue3
' IID = {EBA96B1B-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueue3_INTERFACE_DEFINED)
    %IMSMQQueue3_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueue3 $IID_IMSMQQueue3

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Access <1> ( _                          ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plAccess
   ' =====================================================================================
   PROPERTY GET ShareMode <2> ( _                       ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plShareMode
   ' =====================================================================================
   PROPERTY GET QueueInfo <3> ( _                       ' VTable offset = 36
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfo
   ' =====================================================================================
   PROPERTY GET Handle <0> ( _                          ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plHandle
   ' =====================================================================================
   PROPERTY GET IsOpen <4> ( _                          ' VTable offset = 44
   ) AS BYTE                                            ' __retval_out Boolean *pisOpen
   ' =====================================================================================
   METHOD Close <1610743813> ( _                        ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Receive_v1 <1610743814> ( _                   ' VTable offset = 52
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Peek_v1 <1610743815> ( _                      ' VTable offset = 56
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD EnableNotification <1610743816> ( _           ' VTable offset = 60
     BYVAL Event AS IMSMQEvent3 _                       ' __in IMSMQEvent3 *Event
   , OPTIONAL BYREF Cursor AS VARIANT _                 ' __in_opt VARIANT *Cursor
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset <1610743817> ( _                        ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD ReceiveCurrent_v1 <1610743818> ( _            ' VTable offset = 68
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekNext_v1 <1610743819> ( _                  ' VTable offset = 72
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent_v1 <1610743820> ( _               ' VTable offset = 76
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Receive <1610743821> ( _                      ' VTable offset = 80
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD Peek <1610743822> ( _                         ' VTable offset = 84
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD ReceiveCurrent <1610743823> ( _               ' VTable offset = 88
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekNext <1610743824> ( _                     ' VTable offset = 92
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent <1610743825> ( _                  ' VTable offset = 96
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   PROPERTY GET Properties <5> ( _                      ' VTable offset = 100
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET Handle2 <6> ( _                         ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarHandle
   ' =====================================================================================
   METHOD ReceiveByLookupId <1610743828> ( _            ' VTable offset = 108
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD ReceiveNextByLookupId <1610743829> ( _        ' VTable offset = 112
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD ReceivePreviousByLookupId <1610743830> ( _    ' VTable offset = 116
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD ReceiveFirstByLookupId <1610743831> ( _       ' VTable offset = 120
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD ReceiveLastByLookupId <1610743832> ( _        ' VTable offset = 124
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekByLookupId <1610743833> ( _               ' VTable offset = 128
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekNextByLookupId <1610743834> ( _           ' VTable offset = 132
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekPreviousByLookupId <1610743835> ( _       ' VTable offset = 136
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekFirstByLookupId <1610743836> ( _          ' VTable offset = 140
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD PeekLastByLookupId <1610743837> ( _           ' VTable offset = 144
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage3                                   ' __retval_out IMSMQMessage3 **ppmsg
   ' =====================================================================================
   METHOD Purge <1610743838> ( _                        ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsOpen2 <7> ( _                         ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisOpen
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueue3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueue4
' IID = {EBA96B20-2168-11D3-898C-00E02C074F6B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueue4_INTERFACE_DEFINED)
    %IMSMQQueue4_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueue4 $IID_IMSMQQueue4

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Access ( _                              ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plAccess
   ' =====================================================================================
   PROPERTY GET ShareMode ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plShareMode
   ' =====================================================================================
   PROPERTY GET QueueInfo ( _                           ' VTable offset = 36
   ) AS IMSMQQueueInfo4                                 ' __retval_out IMSMQQueueInfo4 **ppqinfo
   ' =====================================================================================
   PROPERTY GET Handle ( _                              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plHandle
   ' =====================================================================================
   PROPERTY GET IsOpen ( _                              ' VTable offset = 44
   ) AS BYTE                                            ' __retval_out Boolean *pisOpen
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD Receive_v1 ( _                                ' VTable offset = 52
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Peek_v1 ( _                                   ' VTable offset = 56
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD EnableNotification ( _                        ' VTable offset = 60
     BYVAL Event AS IMSMQEvent3 _                       ' __in IMSMQEvent3 *Event
   , OPTIONAL BYREF Cursor AS VARIANT _                 ' __in_opt VARIANT *Cursor
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   )                                                    ' void
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD ReceiveCurrent_v1 ( _                         ' VTable offset = 68
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekNext_v1 ( _                               ' VTable offset = 72
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent_v1 ( _                            ' VTable offset = 76
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   ) AS IMSMQMessage                                    ' __retval_out IMSMQMessage **ppmsg
   ' =====================================================================================
   METHOD Receive ( _                                   ' VTable offset = 80
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD Peek ( _                                      ' VTable offset = 84
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD ReceiveCurrent ( _                            ' VTable offset = 88
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekNext ( _                                  ' VTable offset = 92
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekCurrent ( _                               ' VTable offset = 96
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF ReceiveTimeout AS VARIANT _         ' __in_opt VARIANT *ReceiveTimeout
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   PROPERTY GET Properties ( _                          ' VTable offset = 100
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET Handle2 ( _                             ' VTable offset = 104
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarHandle
   ' =====================================================================================
   METHOD ReceiveByLookupId ( _                         ' VTable offset = 108
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD ReceiveNextByLookupId ( _                     ' VTable offset = 112
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD ReceivePreviousByLookupId ( _                 ' VTable offset = 116
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD ReceiveFirstByLookupId ( _                    ' VTable offset = 120
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD ReceiveLastByLookupId ( _                     ' VTable offset = 124
     OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekByLookupId ( _                            ' VTable offset = 128
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekNextByLookupId ( _                        ' VTable offset = 132
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekPreviousByLookupId ( _                    ' VTable offset = 136
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekFirstByLookupId ( _                       ' VTable offset = 140
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD PeekLastByLookupId ( _                        ' VTable offset = 144
     OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================
   METHOD Purge ( _                                     ' VTable offset = 148
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsOpen2 ( _                             ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisOpen
   ' =====================================================================================
   METHOD ReceiveByLookupIdAllowPeek ( _                ' VTable offset = 156
     BYVAL LookupId AS VARIANT _                        ' __in VARIANT LookupId
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   , OPTIONAL BYREF WantDestinationQueue AS VARIANT _   ' __in_opt VARIANT *WantDestinationQueue
   , OPTIONAL BYREF WantBody AS VARIANT _               ' __in_opt VARIANT *WantBody
   , OPTIONAL BYREF WantConnectorType AS VARIANT _      ' __in_opt VARIANT *WantConnectorType
   ) AS IMSMQMessage4                                   ' __retval_out IMSMQMessage4 **ppmsg
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueue4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQMessage
' IID = {D7D6E074-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQMessage_INTERFACE_DEFINED)
    %IMSMQMessage_INTERFACE_DEFINED = 1

INTERFACE IMSMQMessage $IID_IMSMQMessage

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Class <7> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plClass
   ' =====================================================================================
   PROPERTY GET PrivLevel <25> ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <25> ( _                      ' VTable offset = 36
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthLevel <26> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plAuthLevel
   ' =====================================================================================
   PROPERTY SET AuthLevel <26> ( _                      ' VTable offset = 44
     BYVAL lAuthLevel AS LONG _                         ' __in long lAuthLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAuthenticated <27> ( _                ' VTable offset = 48
   ) AS BYTE                                            ' __retval_out Boolean *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET Delivery <1> ( _                        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plDelivery
   ' =====================================================================================
   PROPERTY SET Delivery <1> ( _                        ' VTable offset = 56
     BYVAL lDelivery AS LONG _                          ' __in long lDelivery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Trace <24> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plTrace
   ' =====================================================================================
   PROPERTY SET Trace <24> ( _                          ' VTable offset = 64
     BYVAL lTrace AS LONG _                             ' __in long lTrace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <2> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPriority
   ' =====================================================================================
   PROPERTY SET Priority <2> ( _                        ' VTable offset = 72
     BYVAL lPriority AS LONG _                          ' __in long lPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <3> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <3> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo <4> ( _               ' VTable offset = 84
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo <4> ( _        ' VTable offset = 88
     BYVAL pqinfoResponse AS IMSMQQueueInfo _           ' __in IMSMQQueueInfo *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppSpecific <5> ( _                     ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY SET AppSpecific <5> ( _                     ' VTable offset = 96
     BYVAL lAppSpecific AS LONG _                       ' __in long lAppSpecific
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceMachineGuid <6> ( _               ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidSrcMachine
   ' =====================================================================================
   PROPERTY GET BodyLength <13> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pcbBody
   ' =====================================================================================
   PROPERTY GET Body <0> ( _                            ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBody
   ' =====================================================================================
   PROPERTY SET Body <0> ( _                            ' VTable offset = 112
     BYVAL varBody AS VARIANT _                         ' __in VARIANT varBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo <8> ( _                  ' VTable offset = 116
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo <8> ( _           ' VTable offset = 120
     BYVAL pqinfoAdmin AS IMSMQQueueInfo _              ' __in IMSMQQueueInfo *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id <9> ( _                              ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY GET CorrelationId <10> ( _                  ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY SET CorrelationId <10> ( _                  ' VTable offset = 132
     BYVAL varMsgId AS VARIANT _                        ' __in VARIANT varMsgId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ack <11> ( _                            ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *plAck
   ' =====================================================================================
   PROPERTY SET Ack <11> ( _                            ' VTable offset = 140
     BYVAL lAck AS LONG _                               ' __in long lAck
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <12> ( _                          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <12> ( _                          ' VTable offset = 148
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReachQueue <14> ( _            ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReachQueue
   ' =====================================================================================
   PROPERTY SET MaxTimeToReachQueue <14> ( _            ' VTable offset = 156
     BYVAL lMaxTimeToReachQueue AS LONG _               ' __in long lMaxTimeToReachQueue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReceive <15> ( _               ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReceive
   ' =====================================================================================
   PROPERTY SET MaxTimeToReceive <15> ( _               ' VTable offset = 164
     BYVAL lMaxTimeToReceive AS LONG _                  ' __in long lMaxTimeToReceive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <17> ( _                  ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *plHashAlg
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <17> ( _                  ' VTable offset = 172
     BYVAL lHashAlg AS LONG _                           ' __in long lHashAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptAlgorithm <16> ( _               ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long *plEncryptAlg
   ' =====================================================================================
   PROPERTY SET EncryptAlgorithm <16> ( _               ' VTable offset = 180
     BYVAL LONG _                                       ' __in long lEncryptAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SentTime <18> ( _                       ' VTable offset = 184
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSentTime
   ' =====================================================================================
   PROPERTY GET ArrivedTime <19> ( _                    ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *plArrivedTime
   ' =====================================================================================
   PROPERTY GET DestinationQueueInfo <20> ( _           ' VTable offset = 192
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoDest
   ' =====================================================================================
   PROPERTY GET SenderCertificate <21> ( _              ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderCert
   ' =====================================================================================
   PROPERTY SET SenderCertificate <21> ( _              ' VTable offset = 200
     BYVAL varSenderCert AS VARIANT _                   ' __in VARIANT varSenderCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderId <22> ( _                       ' VTable offset = 204
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderId
   ' =====================================================================================
   PROPERTY GET SenderIdType <23> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *plSenderIdType
   ' =====================================================================================
   PROPERTY SET SenderIdType <23> ( _                   ' VTable offset = 212
     BYVAL lSenderIdType AS LONG _                      ' __in long lSenderIdType
   )                                                    ' void
   ' =====================================================================================
   METHOD Send <1610743855> ( _                         ' VTable offset = 216
     BYVAL DestinationQueue AS IMSMQQueue _             ' __in IMSMQQueue *DestinationQueue
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext <1610743856> ( _ ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQMessage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfos
' IID = {D7D6E07D-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfos_INTERFACE_DEFINED)
    %IMSMQQueueInfos_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfos $IID_IMSMQQueueInfos

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset <1610743808> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Next <1610743809> ( _                         ' VTable offset = 32
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoNext
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfos_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfos2
' IID = {EBA96B0F-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfos2_INTERFACE_DEFINED)
    %IMSMQQueueInfos2_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfos2 $IID_IMSMQQueueInfos2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset <1610743808> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Next <1610743809> ( _                         ' VTable offset = 32
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoNext
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfos2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfos3
' IID = {EBA96B1E-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfos3_INTERFACE_DEFINED)
    %IMSMQQueueInfos3_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfos3 $IID_IMSMQQueueInfos3

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset <1610743808> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Next <1610743809> ( _                         ' VTable offset = 32
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoNext
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfos3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueInfos4
' IID = {EBA96B22-2168-11D3-898C-00E02C074F6B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueInfos4_INTERFACE_DEFINED)
    %IMSMQQueueInfos4_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueInfos4 $IID_IMSMQQueueInfos4

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset <1610743808> ( _                        ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Next <1610743809> ( _                         ' VTable offset = 32
   ) AS IMSMQQueueInfo4                                 ' __retval_out IMSMQQueueInfo4 **ppqinfoNext
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 36
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueInfos4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQEvent
' IID = {D7D6E077-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQEvent_INTERFACE_DEFINED)
    %IMSMQEvent_INTERFACE_DEFINED = 1

INTERFACE IMSMQEvent $IID_IMSMQEvent

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* __IMSMQEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQEvent2
' IID = {EBA96B12-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQEvent
' ########################################################################################

#IF NOT %DEF(%IMSMQEvent2_INTERFACE_DEFINED)
    %IMSMQEvent2_INTERFACE_DEFINED = 1

INTERFACE IMSMQEvent2 $IID_IMSMQEvent2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQEvent2 Methods
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQEvent2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQEvent3
' IID = {EBA96B1C-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQEvent2
' ########################################################################################

#IF NOT %DEF(%IMSMQEvent3_INTERFACE_DEFINED)
    %IMSMQEvent3_INTERFACE_DEFINED = 1

INTERFACE IMSMQEvent3 $IID_IMSMQEvent3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQEvent3 Methods
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQEvent3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransaction
' IID = {D7D6E07F-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQTransaction_INTERFACE_DEFINED)
    %IMSMQTransaction_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransaction $IID_IMSMQTransaction

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Transaction <0> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plTransaction
   ' =====================================================================================
   METHOD Commit <1610743809> ( _                       ' VTable offset = 32
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF grfTC AS VARIANT _                  ' __in_opt VARIANT *grfTC
   , OPTIONAL BYREF grfRM AS VARIANT _                  ' __in_opt VARIANT *grfRM
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort <1610743810> ( _                        ' VTable offset = 36
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF fAsync AS VARIANT _                 ' __in_opt VARIANT *fAsync
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransaction_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQCoordinatedTransactionDispenser
' IID = {D7D6E081-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQCoordinatedTransactionDispenser_INTERFACE_DEFINED)
    %IMSMQCoordinatedTransactionDispenser_INTERFACE_DEFINED = 1

INTERFACE IMSMQCoordinatedTransactionDispenser $IID_IMSMQCoordinatedTransactionDispenser

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction                                ' __retval_out IMSMQTransaction **ptransaction
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQCoordinatedTransactionDispenser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransactionDispenser
' IID = {D7D6E083-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQTransactionDispenser_INTERFACE_DEFINED)
    %IMSMQTransactionDispenser_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransactionDispenser $IID_IMSMQTransactionDispenser

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction                                ' __retval_out IMSMQTransaction **ptransaction
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransactionDispenser_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQuery2
' IID = {EBA96B0E-2168-11D3-898C-00E02C074F6B}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQuery2_INTERFACE_DEFINED)
    %IMSMQQuery2_INTERFACE_DEFINED = 1

INTERFACE IMSMQQuery2 $IID_IMSMQQuery2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LookupQueue <1610743808> ( _                  ' VTable offset = 28
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   ) AS IMSMQQueueInfos2                                ' __retval_out IMSMQQueueInfos2 **ppqinfos
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQuery2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQuery3
' IID = {EBA96B19-2168-11D3-898C-00E02C074F6B}
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQuery3_INTERFACE_DEFINED)
    %IMSMQQuery3_INTERFACE_DEFINED = 1

INTERFACE IMSMQQuery3 $IID_IMSMQQuery3

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LookupQueue_v2 <1610743808> ( _               ' VTable offset = 28
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   ) AS IMSMQQueueInfos3                                ' __retval_out IMSMQQueueInfos3 **ppqinfos
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   METHOD LookupQueue <1610743810> ( _                  ' VTable offset = 36
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   , OPTIONAL BYREF MulticastAddress AS VARIANT _       ' __in_opt VARIANT *MulticastAddress
   , OPTIONAL BYREF RelMulticastAddress AS VARIANT _    ' __in_opt VARIANT *RelMulticastAddress
   ) AS IMSMQQueueInfos3                                ' __retval_out IMSMQQueueInfos3 **ppqinfos
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQuery3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQuery4
' IID = {EBA96B24-2168-11D3-898C-00E02C074F6B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQQuery4_INTERFACE_DEFINED)
    %IMSMQQuery4_INTERFACE_DEFINED = 1

INTERFACE IMSMQQuery4 $IID_IMSMQQuery4

   INHERIT IDispatch

   ' =====================================================================================
   METHOD LookupQueue_v2 <1610743808> ( _               ' VTable offset = 28
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   ) AS IMSMQQueueInfos4                                ' __retval_out IMSMQQueueInfos4 **ppqinfos
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   METHOD LookupQueue <1610743810> ( _                  ' VTable offset = 36
     OPTIONAL BYREF QueueGuid AS VARIANT _              ' __in_opt VARIANT *QueueGuid
   , OPTIONAL BYREF ServiceTypeGuid AS VARIANT _        ' __in_opt VARIANT *ServiceTypeGuid
   , OPTIONAL BYREF Label AS VARIANT _                  ' __in_opt VARIANT *Label
   , OPTIONAL BYREF CreateTime AS VARIANT _             ' __in_opt VARIANT *CreateTime
   , OPTIONAL BYREF ModifyTime AS VARIANT _             ' __in_opt VARIANT *ModifyTime
   , OPTIONAL BYREF RelServiceType AS VARIANT _         ' __in_opt VARIANT *RelServiceType
   , OPTIONAL BYREF RelLabel AS VARIANT _               ' __in_opt VARIANT *RelLabel
   , OPTIONAL BYREF RelCreateTime AS VARIANT _          ' __in_opt VARIANT *RelCreateTime
   , OPTIONAL BYREF RelModifyTime AS VARIANT _          ' __in_opt VARIANT *RelModifyTime
   , OPTIONAL BYREF MulticastAddress AS VARIANT _       ' __in_opt VARIANT *MulticastAddress
   , OPTIONAL BYREF RelMulticastAddress AS VARIANT _    ' __in_opt VARIANT *RelMulticastAddress
   ) AS IMSMQQueueInfos4                                ' __retval_out IMSMQQueueInfos4 **ppqinfos
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQuery4_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQMessage2
' IID = {D9933BE0-A567-11D2-B0F3-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQMessage2_INTERFACE_DEFINED)
    %IMSMQMessage2_INTERFACE_DEFINED = 1

INTERFACE IMSMQMessage2 $IID_IMSMQMessage2

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Class <7> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plClass
   ' =====================================================================================
   PROPERTY GET PrivLevel <25> ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <25> ( _                      ' VTable offset = 36
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthLevel <26> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plAuthLevel
   ' =====================================================================================
   PROPERTY SET AuthLevel <26> ( _                      ' VTable offset = 44
     BYVAL lAuthLevel AS LONG _                         ' __in long lAuthLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAuthenticated <27> ( _                ' VTable offset = 48
   ) AS BYTE                                            ' __retval_out Boolean *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET Delivery <1> ( _                        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plDelivery
   ' =====================================================================================
   PROPERTY SET Delivery <1> ( _                        ' VTable offset = 56
     BYVAL lDelivery AS LONG _                          ' __in long lDelivery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Trace <24> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plTrace
   ' =====================================================================================
   PROPERTY SET Trace <24> ( _                          ' VTable offset = 64
     BYVAL lTrace AS LONG _                             ' __in long lTrace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <2> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPriority
   ' =====================================================================================
   PROPERTY SET Priority <2> ( _                        ' VTable offset = 72
     BYVAL lPriority AS LONG _                          ' __in long lPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <3> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <3> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo_v1 <4> ( _            ' VTable offset = 84
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo_v1 <4> ( _     ' VTable offset = 88
     BYVAL pqinfoResponse AS IMSMQQueueInfo _           ' __in IMSMQQueueInfo *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppSpecific <5> ( _                     ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY SET AppSpecific <5> ( _                     ' VTable offset = 96
     BYVAL lAppSpecific AS LONG _                       ' __in long lAppSpecific
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceMachineGuid <6> ( _               ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidSrcMachine
   ' =====================================================================================
   PROPERTY GET BodyLength <13> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pcbBody
   ' =====================================================================================
   PROPERTY GET Body <0> ( _                            ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBody
   ' =====================================================================================
   PROPERTY SET Body <0> ( _                            ' VTable offset = 112
     BYVAL varBody AS VARIANT _                         ' __in VARIANT varBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo_v1 <8> ( _               ' VTable offset = 116
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo_v1 <8> ( _        ' VTable offset = 120
     BYVAL pqinfoAdmin AS IMSMQQueueInfo _              ' __in IMSMQQueueInfo *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id <9> ( _                              ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY GET CorrelationId <10> ( _                  ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY SET CorrelationId <10> ( _                  ' VTable offset = 132
     BYVAL varMsgId AS VARIANT _                        ' __in VARIANT varMsgId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ack <11> ( _                            ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *plAck
   ' =====================================================================================
   PROPERTY SET Ack <11> ( _                            ' VTable offset = 140
     BYVAL lAck AS LONG _                               ' __in long lAck
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <12> ( _                          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <12> ( _                          ' VTable offset = 148
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReachQueue <14> ( _            ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReachQueue
   ' =====================================================================================
   PROPERTY SET MaxTimeToReachQueue <14> ( _            ' VTable offset = 156
     BYVAL lMaxTimeToReachQueue AS LONG _               ' __in long lMaxTimeToReachQueue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReceive <15> ( _               ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReceive
   ' =====================================================================================
   PROPERTY SET MaxTimeToReceive <15> ( _               ' VTable offset = 164
     BYVAL lMaxTimeToReceive AS LONG _                  ' __in long lMaxTimeToReceive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <17> ( _                  ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *plHashAlg
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <17> ( _                  ' VTable offset = 172
     BYVAL lHashAlg AS LONG _                           ' __in long lHashAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptAlgorithm <16> ( _               ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long *plEncryptAlg
   ' =====================================================================================
   PROPERTY SET EncryptAlgorithm <16> ( _               ' VTable offset = 180
     BYVAL lEncryptAlg AS LONG _                        ' __in long lEncryptAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SentTime <18> ( _                       ' VTable offset = 184
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSentTime
   ' =====================================================================================
   PROPERTY GET ArrivedTime <19> ( _                    ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *plArrivedTime
   ' =====================================================================================
   PROPERTY GET DestinationQueueInfo <20> ( _           ' VTable offset = 192
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoDest
   ' =====================================================================================
   PROPERTY GET SenderCertificate <21> ( _              ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderCert
   ' =====================================================================================
   PROPERTY SET SenderCertificate <21> ( _              ' VTable offset = 200
     BYVAL varSenderCert AS VARIANT _                   ' __in VARIANT varSenderCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderId <22> ( _                       ' VTable offset = 204
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderId
   ' =====================================================================================
   PROPERTY GET SenderIdType <23> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *plSenderIdType
   ' =====================================================================================
   PROPERTY SET SenderIdType <23> ( _                   ' VTable offset = 212
     BYVAL lSenderIdType AS LONG _                      ' __in long lSenderIdType
   )                                                    ' void
   ' =====================================================================================
   METHOD Send <1610743855> ( _                         ' VTable offset = 216
     BYVAL DestinationQueue AS IMSMQQueue2 _            ' __in IMSMQQueue2 *DestinationQueue
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext <1610743856> ( _ ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderVersion <28> ( _                  ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *plSenderVersion
   ' =====================================================================================
   PROPERTY GET Extension <29> ( _                      ' VTable offset = 228
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarExtension
   ' =====================================================================================
   PROPERTY SET Extension <29> ( _                      ' VTable offset = 232
     BYVAL varExtension AS VARIANT _                    ' __in VARIANT varExtension
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectorTypeGuid <30> ( _              ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidConnectorType
   ' =====================================================================================
   PROPERTY SET ConnectorTypeGuid <30> ( _              ' VTable offset = 240
     BYVAL bstrGuidConnectorType AS WSTRING _           ' __in BSTR bstrGuidConnectorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransactionStatusQueueInfo <31> ( _     ' VTable offset = 244
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoXactStatus
   ' =====================================================================================
   PROPERTY GET DestinationSymmetricKey <32> ( _        ' VTable offset = 248
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDestSymmKey
   ' =====================================================================================
   PROPERTY SET DestinationSymmetricKey <32> ( _        ' VTable offset = 252
     BYVAL varDestSymmKey AS VARIANT _                  ' __in VARIANT varDestSymmKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Signature <33> ( _                      ' VTable offset = 256
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSignature
   ' =====================================================================================
   PROPERTY SET Signature <33> ( _                      ' VTable offset = 260
     BYVAL varSignature AS VARIANT _                    ' __in VARIANT varSignature
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderType <34> ( _     ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *plAuthProvType
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderType <34> ( _     ' VTable offset = 268
     BYVAL lAuthProvType AS LONG _                      ' __in long lAuthProvType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderName <35> ( _     ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAuthProvName
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderName <35> ( _     ' VTable offset = 276
     BYVAL bstrAuthProvName AS WSTRING _                ' __in BSTR bstrAuthProvName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SenderId <22> ( _                       ' VTable offset = 280
     BYVAL varSenderId AS VARIANT _                     ' __in VARIANT varSenderId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MsgClass <36> ( _                       ' VTable offset = 284
   ) AS LONG                                            ' __retval_out long *plMsgClass
   ' =====================================================================================
   PROPERTY SET MsgClass <36> ( _                       ' VTable offset = 288
     BYVAL lMsgClass AS LONG _                          ' __in long lMsgClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <37> ( _                     ' VTable offset = 292
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET TransactionId <38> ( _                  ' VTable offset = 296
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarXactId
   ' =====================================================================================
   PROPERTY GET IsFirstInTransaction <39> ( _           ' VTable offset = 300
   ) AS BYTE                                            ' __retval_out Boolean *pisFirstInXact
   ' =====================================================================================
   PROPERTY GET IsLastInTransaction <40> ( _            ' VTable offset = 304
   ) AS BYTE                                            ' __retval_out Boolean *pisLastInXact
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo <41> ( _              ' VTable offset = 308
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo <41> ( _       ' VTable offset = 312
     BYVAL pqinfoResponse AS IMSMQQueueInfo2 _          ' __in IMSMQQueueInfo2 *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo <42> ( _                 ' VTable offset = 316
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo <42> ( _          ' VTable offset = 320
     BYVAL pqinfoAdmin AS IMSMQQueueInfo2 _             ' __in IMSMQQueueInfo2 *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedAuthenticationLevel <43> ( _    ' VTable offset = 324
   ) AS INTEGER                                         ' __retval_out short *psReceivedAuthenticationLevel
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQMessage2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQMessage3
' IID = {EBA96B1A-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQMessage3_INTERFACE_DEFINED)
    %IMSMQMessage3_INTERFACE_DEFINED = 1

INTERFACE IMSMQMessage3 $IID_IMSMQMessage3

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Class <7> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plClass
   ' =====================================================================================
   PROPERTY GET PrivLevel <25> ( _                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel <25> ( _                      ' VTable offset = 36
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthLevel <26> ( _                      ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plAuthLevel
   ' =====================================================================================
   PROPERTY SET AuthLevel <26> ( _                      ' VTable offset = 44
     BYVAL lAuthLevel AS LONG _                         ' __in long lAuthLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAuthenticated <27> ( _                ' VTable offset = 48
   ) AS BYTE                                            ' __retval_out Boolean *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET Delivery <1> ( _                        ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plDelivery
   ' =====================================================================================
   PROPERTY SET Delivery <1> ( _                        ' VTable offset = 56
     BYVAL lDelivery AS LONG _                          ' __in long lDelivery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Trace <24> ( _                          ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plTrace
   ' =====================================================================================
   PROPERTY SET Trace <24> ( _                          ' VTable offset = 64
     BYVAL lTrace AS LONG _                             ' __in long lTrace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <2> ( _                        ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPriority
   ' =====================================================================================
   PROPERTY SET Priority <2> ( _                        ' VTable offset = 72
     BYVAL lPriority AS LONG _                          ' __in long lPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal <3> ( _                         ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal <3> ( _                         ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo_v1 <4> ( _            ' VTable offset = 84
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo_v1 <4> ( _     ' VTable offset = 88
     BYVAL pqinfoResponse AS IMSMQQueueInfo _           ' __in IMSMQQueueInfo *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppSpecific <5> ( _                     ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY SET AppSpecific <5> ( _                     ' VTable offset = 96
     BYVAL lAppSpecific AS LONG _                       ' __in long lAppSpecific
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceMachineGuid <6> ( _               ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidSrcMachine
   ' =====================================================================================
   PROPERTY GET BodyLength <13> ( _                     ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pcbBody
   ' =====================================================================================
   PROPERTY GET Body <0> ( _                            ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBody
   ' =====================================================================================
   PROPERTY SET Body <0> ( _                            ' VTable offset = 112
     BYVAL varBody AS VARIANT _                         ' __in VARIANT varBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo_v1 <8> ( _               ' VTable offset = 116
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo_v1 <8> ( _        ' VTable offset = 120
     BYVAL IMSMQQueueInfo _                             ' __in IMSMQQueueInfo *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id <9> ( _                              ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY GET CorrelationId <10> ( _                  ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY SET CorrelationId <10> ( _                  ' VTable offset = 132
     BYVAL varMsgId AS VARIANT _                        ' __in VARIANT varMsgId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ack <11> ( _                            ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *plAck
   ' =====================================================================================
   PROPERTY SET Ack <11> ( _                            ' VTable offset = 140
     BYVAL lAck AS LONG _                               ' __in long lAck
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label <12> ( _                          ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label <12> ( _                          ' VTable offset = 148
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReachQueue <14> ( _            ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReachQueue
   ' =====================================================================================
   PROPERTY SET MaxTimeToReachQueue <14> ( _            ' VTable offset = 156
     BYVAL lMaxTimeToReachQueue AS LONG _               ' __in long lMaxTimeToReachQueue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReceive <15> ( _               ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReceive
   ' =====================================================================================
   PROPERTY SET MaxTimeToReceive <15> ( _               ' VTable offset = 164
     BYVAL lMaxTimeToReceive AS LONG _                  ' __in long lMaxTimeToReceive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <17> ( _                  ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *plHashAlg
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <17> ( _                  ' VTable offset = 172
     BYVAL lHashAlg AS LONG _                           ' __in long lHashAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptAlgorithm <16> ( _               ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long *plEncryptAlg
   ' =====================================================================================
   PROPERTY SET EncryptAlgorithm <16> ( _               ' VTable offset = 180
     BYVAL lEncryptAlg AS LONG _                        ' __in long lEncryptAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SentTime <18> ( _                       ' VTable offset = 184
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSentTime
   ' =====================================================================================
   PROPERTY GET ArrivedTime <19> ( _                    ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *plArrivedTime
   ' =====================================================================================
   PROPERTY GET DestinationQueueInfo <20> ( _           ' VTable offset = 192
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoDest
   ' =====================================================================================
   PROPERTY GET SenderCertificate <21> ( _              ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderCert
   ' =====================================================================================
   PROPERTY SET SenderCertificate <21> ( _              ' VTable offset = 200
     BYVAL varSenderCert AS VARIANT _                   ' __in VARIANT varSenderCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderId <22> ( _                       ' VTable offset = 204
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderId
   ' =====================================================================================
   PROPERTY GET SenderIdType <23> ( _                   ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *plSenderIdType
   ' =====================================================================================
   PROPERTY SET SenderIdType <23> ( _                   ' VTable offset = 212
     BYVAL lSenderIdType AS LONG _                      ' __in long lSenderIdType
   )                                                    ' void
   ' =====================================================================================
   METHOD Send <1610743855> ( _                         ' VTable offset = 216
     BYVAL DestinationQueue AS IDispatch _              ' __in IDispatch *DestinationQueue
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext <1610743856> ( _ ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderVersion <28> ( _                  ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *plSenderVersion
   ' =====================================================================================
   PROPERTY GET Extension <29> ( _                      ' VTable offset = 228
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarExtension
   ' =====================================================================================
   PROPERTY SET Extension <29> ( _                      ' VTable offset = 232
     BYVAL varExtension AS VARIANT _                    ' __in VARIANT varExtension
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectorTypeGuid <30> ( _              ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidConnectorType
   ' =====================================================================================
   PROPERTY SET ConnectorTypeGuid <30> ( _              ' VTable offset = 240
     BYVAL bstrGuidConnectorType AS WSTRING _           ' __in BSTR bstrGuidConnectorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransactionStatusQueueInfo <31> ( _     ' VTable offset = 244
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoXactStatus
   ' =====================================================================================
   PROPERTY GET DestinationSymmetricKey <32> ( _        ' VTable offset = 248
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDestSymmKey
   ' =====================================================================================
   PROPERTY SET DestinationSymmetricKey <32> ( _        ' VTable offset = 252
     BYVAL varDestSymmKey AS VARIANT _                  ' __in VARIANT varDestSymmKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Signature <33> ( _                      ' VTable offset = 256
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSignature
   ' =====================================================================================
   PROPERTY SET Signature <33> ( _                      ' VTable offset = 260
     BYVAL varSignature AS VARIANT _                    ' __in VARIANT varSignature
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderType <34> ( _     ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *plAuthProvType
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderType <34> ( _     ' VTable offset = 268
     BYVAL lAuthProvType AS LONG _                      ' __in long lAuthProvType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderName <35> ( _     ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAuthProvName
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderName <35> ( _     ' VTable offset = 276
     BYVAL bstrAuthProvName AS WSTRING _                ' __in BSTR bstrAuthProvName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SenderId <22> ( _                       ' VTable offset = 280
     BYVAL varSenderId AS VARIANT _                     ' __in VARIANT varSenderId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MsgClass <36> ( _                       ' VTable offset = 284
   ) AS LONG                                            ' __retval_out long *plMsgClass
   ' =====================================================================================
   PROPERTY SET MsgClass <36> ( _                       ' VTable offset = 288
     BYVAL lMsgClass AS LONG _                          ' __in long lMsgClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <37> ( _                     ' VTable offset = 292
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET TransactionId <38> ( _                  ' VTable offset = 296
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarXactId
   ' =====================================================================================
   PROPERTY GET IsFirstInTransaction <39> ( _           ' VTable offset = 300
   ) AS BYTE                                            ' __retval_out Boolean *pisFirstInXact
   ' =====================================================================================
   PROPERTY GET IsLastInTransaction <40> ( _            ' VTable offset = 304
   ) AS BYTE                                            ' __retval_out Boolean *pisLastInXact
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo_v2 <41> ( _           ' VTable offset = 308
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo_v2 <41> ( _    ' VTable offset = 312
     BYVAL pqinfoResponse AS IMSMQQueueInfo2 _          ' __in IMSMQQueueInfo2 *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo_v2 <42> ( _              ' VTable offset = 316
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo_v2 <42> ( _       ' VTable offset = 320
     BYVAL pqinfoAdmin AS IMSMQQueueInfo2 _             ' __in IMSMQQueueInfo2 *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedAuthenticationLevel <43> ( _    ' VTable offset = 324
   ) AS INTEGER                                         ' __retval_out short *psReceivedAuthenticationLevel
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo <44> ( _              ' VTable offset = 328
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo <44> ( _       ' VTable offset = 332
     BYVAL pqinfoResponse AS IMSMQQueueInfo3 _          ' __in IMSMQQueueInfo3 *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo <45> ( _                 ' VTable offset = 336
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo <45> ( _          ' VTable offset = 340
     BYVAL pqinfoAdmin AS IMSMQQueueInfo3 _             ' __in IMSMQQueueInfo3 *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseDestination <46> ( _            ' VTable offset = 344
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdestResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseDestination <46> ( _     ' VTable offset = 348
     BYVAL pdestResponse AS IDispatch _                 ' __in IDispatch *pdestResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Destination <48> ( _                    ' VTable offset = 352
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdestDestination
   ' =====================================================================================
   PROPERTY GET LookupId <49> ( _                       ' VTable offset = 356
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarLookupId
   ' =====================================================================================
   PROPERTY GET IsAuthenticated2 <50> ( _               ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET IsFirstInTransaction2 <51> ( _          ' VTable offset = 364
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisFirstInXact
   ' =====================================================================================
   PROPERTY GET IsLastInTransaction2 <52> ( _           ' VTable offset = 368
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisLastInXact
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext2 <1610743894> ( _ ' VTable offset = 372
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SoapEnvelope <53> ( _                   ' VTable offset = 376
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSoapEnvelope
   ' =====================================================================================
   PROPERTY GET CompoundMessage <54> ( _                ' VTable offset = 380
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCompoundMessage
   ' =====================================================================================
   PROPERTY SET SoapHeader <55> ( _                     ' VTable offset = 384
     BYVAL bstrSoapHeader AS WSTRING _                  ' __in BSTR bstrSoapHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SoapBody <56> ( _                       ' VTable offset = 388
     BYVAL bstrSoapBody AS WSTRING _                    ' __in BSTR bstrSoapBody
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQMessage3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQMessage4
' IID = {EBA96B23-2168-11D3-898C-00E02C074F6B}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQMessage4_INTERFACE_DEFINED)
    %IMSMQMessage4_INTERFACE_DEFINED = 1

INTERFACE IMSMQMessage4 $IID_IMSMQMessage4

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Class ( _                               ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plClass
   ' =====================================================================================
   PROPERTY GET PrivLevel ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *plPrivLevel
   ' =====================================================================================
   PROPERTY SET PrivLevel ( _                           ' VTable offset = 36
     BYVAL lPrivLevel AS LONG _                         ' __in long lPrivLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthLevel ( _                           ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plAuthLevel
   ' =====================================================================================
   PROPERTY SET AuthLevel ( _                           ' VTable offset = 44
     BYVAL lAuthLevel AS LONG _                         ' __in long lAuthLevel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsAuthenticated ( _                     ' VTable offset = 48
   ) AS BYTE                                            ' __retval_out Boolean *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET Delivery ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *plDelivery
   ' =====================================================================================
   PROPERTY SET Delivery ( _                            ' VTable offset = 56
     BYVAL lDelivery AS LONG _                          ' __in long lDelivery
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Trace ( _                               ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *plTrace
   ' =====================================================================================
   PROPERTY SET Trace ( _                               ' VTable offset = 64
     BYVAL lTrace AS LONG _                             ' __in long lTrace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority ( _                            ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *plPriority
   ' =====================================================================================
   PROPERTY SET Priority ( _                            ' VTable offset = 72
     BYVAL lPriority AS LONG _                          ' __in long lPriority
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Journal ( _                             ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *plJournal
   ' =====================================================================================
   PROPERTY SET Journal ( _                             ' VTable offset = 80
     BYVAL lJournal AS LONG _                           ' __in long lJournal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo_v1 ( _                ' VTable offset = 84
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo_v1 ( _         ' VTable offset = 88
     BYVAL pqinfoResponse AS IMSMQQueueInfo _           ' __in IMSMQQueueInfo *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AppSpecific ( _                         ' VTable offset = 92
   ) AS LONG                                            ' __retval_out long *plAppSpecific
   ' =====================================================================================
   PROPERTY SET AppSpecific ( _                         ' VTable offset = 96
     BYVAL lAppSpecific AS LONG _                       ' __in long lAppSpecific
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SourceMachineGuid ( _                   ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidSrcMachine
   ' =====================================================================================
   PROPERTY GET BodyLength ( _                          ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pcbBody
   ' =====================================================================================
   PROPERTY GET Body ( _                                ' VTable offset = 108
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarBody
   ' =====================================================================================
   PROPERTY SET Body ( _                                ' VTable offset = 112
     BYVAL varBody AS VARIANT _                         ' __in VARIANT varBody
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo_v1 ( _                   ' VTable offset = 116
   ) AS IMSMQQueueInfo                                  ' __retval_out IMSMQQueueInfo **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo_v1 ( _            ' VTable offset = 120
     BYVAL pqinfoAdmin AS IMSMQQueueInfo _              ' __in IMSMQQueueInfo *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Id ( _                                  ' VTable offset = 124
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY GET CorrelationId ( _                       ' VTable offset = 128
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarMsgId
   ' =====================================================================================
   PROPERTY SET CorrelationId ( _                       ' VTable offset = 132
     BYVAL varMsgId AS VARIANT _                        ' __in VARIANT varMsgId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Ack ( _                                 ' VTable offset = 136
   ) AS LONG                                            ' __retval_out long *plAck
   ' =====================================================================================
   PROPERTY SET Ack ( _                                 ' VTable offset = 140
     BYVAL lAck AS LONG _                               ' __in long lAck
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Label ( _                               ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrLabel
   ' =====================================================================================
   PROPERTY SET Label ( _                               ' VTable offset = 148
     BYVAL bstrLabel AS WSTRING _                       ' __in BSTR bstrLabel
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReachQueue ( _                 ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReachQueue
   ' =====================================================================================
   PROPERTY SET MaxTimeToReachQueue ( _                 ' VTable offset = 156
     BYVAL lMaxTimeToReachQueue AS LONG _               ' __in long lMaxTimeToReachQueue
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MaxTimeToReceive ( _                    ' VTable offset = 160
   ) AS LONG                                            ' __retval_out long *plMaxTimeToReceive
   ' =====================================================================================
   PROPERTY SET MaxTimeToReceive ( _                    ' VTable offset = 164
     BYVAL lMaxTimeToReceive AS LONG _                  ' __in long lMaxTimeToReceive
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm ( _                       ' VTable offset = 168
   ) AS LONG                                            ' __retval_out long *plHashAlg
   ' =====================================================================================
   PROPERTY SET HashAlgorithm ( _                       ' VTable offset = 172
     BYVAL lHashAlg AS LONG _                           ' __in long lHashAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EncryptAlgorithm ( _                    ' VTable offset = 176
   ) AS LONG                                            ' __retval_out long *plEncryptAlg
   ' =====================================================================================
   PROPERTY SET EncryptAlgorithm ( _                    ' VTable offset = 180
     BYVAL lEncryptAlg AS LONG _                        ' __in long lEncryptAlg
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SentTime ( _                            ' VTable offset = 184
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSentTime
   ' =====================================================================================
   PROPERTY GET ArrivedTime ( _                         ' VTable offset = 188
   ) AS VARIANT                                         ' __retval_out VARIANT *plArrivedTime
   ' =====================================================================================
   PROPERTY GET DestinationQueueInfo ( _                ' VTable offset = 192
   ) AS IMSMQQueueInfo3                                 ' __retval_out IMSMQQueueInfo3 **ppqinfoDest
   ' =====================================================================================
   PROPERTY GET SenderCertificate ( _                   ' VTable offset = 196
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderCert
   ' =====================================================================================
   PROPERTY SET SenderCertificate ( _                   ' VTable offset = 200
     BYVAL varSenderCert AS VARIANT _                   ' __in VARIANT varSenderCert
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderId ( _                            ' VTable offset = 204
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSenderId
   ' =====================================================================================
   PROPERTY GET SenderIdType ( _                        ' VTable offset = 208
   ) AS LONG                                            ' __retval_out long *plSenderIdType
   ' =====================================================================================
   PROPERTY SET SenderIdType ( _                        ' VTable offset = 212
     BYVAL lSenderIdType AS LONG _                      ' __in long lSenderIdType
   )                                                    ' void
   ' =====================================================================================
   METHOD Send ( _                                      ' VTable offset = 216
     BYVAL DestinationQueue AS IDispatch _              ' __in IDispatch *DestinationQueue
   , OPTIONAL BYREF Transaction AS VARIANT _            ' __in_opt VARIANT *Transaction
   )                                                    ' void
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext ( _              ' VTable offset = 220
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderVersion ( _                       ' VTable offset = 224
   ) AS LONG                                            ' __retval_out long *plSenderVersion
   ' =====================================================================================
   PROPERTY GET Extension ( _                           ' VTable offset = 228
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarExtension
   ' =====================================================================================
   PROPERTY SET Extension ( _                           ' VTable offset = 232
     BYVAL varExtension AS VARIANT _                    ' __in VARIANT varExtension
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ConnectorTypeGuid ( _                   ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuidConnectorType
   ' =====================================================================================
   PROPERTY SET ConnectorTypeGuid ( _                   ' VTable offset = 240
     BYVAL bstrGuidConnectorType AS WSTRING _           ' __in BSTR bstrGuidConnectorType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET TransactionStatusQueueInfo ( _          ' VTable offset = 244
   ) AS IMSMQQueueInfo4                                 ' __retval_out IMSMQQueueInfo4 **ppqinfoXactStatus
   ' =====================================================================================
   PROPERTY GET DestinationSymmetricKey ( _             ' VTable offset = 248
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarDestSymmKey
   ' =====================================================================================
   PROPERTY SET DestinationSymmetricKey ( _             ' VTable offset = 252
     BYVAL varDestSymmKey AS VARIANT _                  ' __in VARIANT varDestSymmKey
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Signature ( _                           ' VTable offset = 256
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarSignature
   ' =====================================================================================
   PROPERTY SET Signature ( _                           ' VTable offset = 260
     BYVAL varSignature AS VARIANT _                    ' __in VARIANT varSignature
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderType ( _          ' VTable offset = 264
   ) AS LONG                                            ' __retval_out long *plAuthProvType
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderType ( _          ' VTable offset = 268
     BYVAL lAuthProvType AS LONG _                      ' __in long lAuthProvType
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AuthenticationProviderName ( _          ' VTable offset = 272
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrAuthProvName
   ' =====================================================================================
   PROPERTY SET AuthenticationProviderName ( _          ' VTable offset = 276
     BYVAL bstrAuthProvName AS WSTRING _                ' __in BSTR bstrAuthProvName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SenderId ( _                            ' VTable offset = 280
     BYVAL varSenderId AS VARIANT _                     ' __in VARIANT varSenderId
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET MsgClass ( _                            ' VTable offset = 284
   ) AS LONG                                            ' __retval_out long *plMsgClass
   ' =====================================================================================
   PROPERTY SET MsgClass ( _                            ' VTable offset = 288
     BYVAL lMsgClass AS LONG _                          ' __in long lMsgClass
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties ( _                          ' VTable offset = 292
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================
   PROPERTY GET TransactionId ( _                       ' VTable offset = 296
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarXactId
   ' =====================================================================================
   PROPERTY GET IsFirstInTransaction ( _                ' VTable offset = 300
   ) AS BYTE                                            ' __retval_out Boolean *pisFirstInXact
   ' =====================================================================================
   PROPERTY GET IsLastInTransaction ( _                 ' VTable offset = 304
   ) AS BYTE                                            ' __retval_out Boolean *pisLastInXact
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo_v2 ( _                ' VTable offset = 308
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo_v2 ( _         ' VTable offset = 312
     BYVAL pqinfoResponse AS IMSMQQueueInfo2 _          ' __in IMSMQQueueInfo2 *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo_v2 ( _                   ' VTable offset = 316
   ) AS IMSMQQueueInfo2                                 ' __retval_out IMSMQQueueInfo2 **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo_v2 ( _            ' VTable offset = 320
     BYVAL pqinfoAdmin AS IMSMQQueueInfo2 _             ' __in IMSMQQueueInfo2 *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ReceivedAuthenticationLevel ( _         ' VTable offset = 324
   ) AS INTEGER                                         ' __retval_out short *psReceivedAuthenticationLevel
   ' =====================================================================================
   PROPERTY GET ResponseQueueInfo ( _                   ' VTable offset = 328
   ) AS IMSMQQueueInfo4                                 ' __retval_out IMSMQQueueInfo4 **ppqinfoResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseQueueInfo ( _            ' VTable offset = 332
     BYVAL pqinfoResponse AS IMSMQQueueInfo4 _          ' __in IMSMQQueueInfo4 *pqinfoResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET AdminQueueInfo ( _                      ' VTable offset = 336
   ) AS IMSMQQueueInfo4                                 ' __retval_out IMSMQQueueInfo4 **ppqinfoAdmin
   ' =====================================================================================
   PROPERTY SET putref_AdminQueueInfo ( _               ' VTable offset = 340
     BYVAL pqinfoAdmin AS IMSMQQueueInfo4 _             ' __in IMSMQQueueInfo4 *pqinfoAdmin
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ResponseDestination ( _                 ' VTable offset = 344
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdestResponse
   ' =====================================================================================
   PROPERTY SET putref_ResponseDestination ( _          ' VTable offset = 348
     BYVAL pdestResponse AS IDispatch _                 ' __in IDispatch *pdestResponse
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Destination ( _                         ' VTable offset = 352
   ) AS IDispatch                                       ' __retval_out IDispatch **ppdestDestination
   ' =====================================================================================
   PROPERTY GET LookupId ( _                            ' VTable offset = 356
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarLookupId
   ' =====================================================================================
   PROPERTY GET IsAuthenticated2 ( _                    ' VTable offset = 360
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisAuthenticated
   ' =====================================================================================
   PROPERTY GET IsFirstInTransaction2 ( _               ' VTable offset = 364
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisFirstInXact
   ' =====================================================================================
   PROPERTY GET IsLastInTransaction2 ( _                ' VTable offset = 368
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pisLastInXact
   ' =====================================================================================
   METHOD AttachCurrentSecurityContext2 ( _             ' VTable offset = 372
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SoapEnvelope ( _                        ' VTable offset = 376
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrSoapEnvelope
   ' =====================================================================================
   PROPERTY GET CompoundMessage ( _                     ' VTable offset = 380
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarCompoundMessage
   ' =====================================================================================
   PROPERTY SET SoapHeader ( _                          ' VTable offset = 384
     BYVAL bstrSoapHeader AS WSTRING _                  ' __in BSTR bstrSoapHeader
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET SoapBody ( _                            ' VTable offset = 388
     BYVAL bstrSoapBody AS WSTRING _                    ' __in BSTR bstrSoapBody
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQMessage4_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMSMQPrivateEvent
' IID = {D7AB3341-C9D3-11D1-BB47-0080C7C5A2C0}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQPrivateEvent_INTERFACE_DEFINED)
    %IMSMQPrivateEvent_INTERFACE_DEFINED = 1

INTERFACE IMSMQPrivateEvent $IID_IMSMQPrivateEvent

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Hwnd <1610743808> ( _                   ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *phwnd
   ' =====================================================================================
   METHOD FireArrivedEvent <1610743809> ( _             ' VTable offset = 32
     BYVAL pq AS IMSMQQueue _                           ' __in IMSMQQueue *pq
   , BYVAL msgcursor AS LONG _                          ' __in long msgcursor
   )                                                    ' void
   ' =====================================================================================
   METHOD FireArrivedErrorEvent <1610743810> ( _        ' VTable offset = 36
     BYVAL pq AS IMSMQQueue _                           ' __in IMSMQQueue *pq
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL msgcursor AS LONG _                          ' __in long msgcursor
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQPrivateEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = _DMSMQEventEvents
' IID = {D7D6E078-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%DMSMQEventEvents_DISPINTERFACE_DEFINED)
    %DMSMQEventEvents_DISPINTERFACE_DEFINED = 1

INTERFACE DMSMQEventEvents $IID__DMSMQEventEvents

   INHERIT IDispatch

END INTERFACE

#ENDIF   ' /* ___DMSMQEventEvents_DISPINTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransaction2
' IID = {2CE0C5B0-6E67-11D2-B0E6-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQTransaction
' ########################################################################################

#IF NOT %DEF(%IMSMQTransaction2_INTERFACE_DEFINED)
    %IMSMQTransaction2_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransaction2 $IID_IMSMQTransaction2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQTransaction Methods
   ' =====================================================================================
   PROPERTY GET Transaction <0> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plTransaction
   ' =====================================================================================
   METHOD Commit <1610743809> ( _                       ' VTable offset = 32
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF grfTC AS VARIANT _                  ' __in_opt VARIANT *grfTC
   , OPTIONAL BYREF grfRM AS VARIANT _                  ' __in_opt VARIANT *grfRM
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort <1610743810> ( _                        ' VTable offset = 36
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF fAsync AS VARIANT _                 ' __in_opt VARIANT *fAsync
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQTransaction2 Methods
   ' =====================================================================================
   METHOD InitNew <1610809344> ( _                      ' VTable offset = 40
     BYVAL varTransaction AS VARIANT _                  ' __in VARIANT varTransaction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <1> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransaction2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransaction3
' IID = {EBA96B13-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQTransaction2
' ########################################################################################

#IF NOT %DEF(%IMSMQTransaction3_INTERFACE_DEFINED)
    %IMSMQTransaction3_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransaction3 $IID_IMSMQTransaction3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQTransaction Methods
   ' =====================================================================================
   PROPERTY GET Transaction <0> ( _                     ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *plTransaction
   ' =====================================================================================
   METHOD Commit <1610743809> ( _                       ' VTable offset = 32
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF grfTC AS VARIANT _                  ' __in_opt VARIANT *grfTC
   , OPTIONAL BYREF grfRM AS VARIANT _                  ' __in_opt VARIANT *grfRM
   )                                                    ' void
   ' =====================================================================================
   METHOD Abort <1610743810> ( _                        ' VTable offset = 36
     OPTIONAL BYREF fRetaining AS VARIANT _             ' __in_opt VARIANT *fRetaining
   , OPTIONAL BYREF fAsync AS VARIANT _                 ' __in_opt VARIANT *fAsync
   )                                                    ' void
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQTransaction2 Methods
   ' =====================================================================================
   METHOD InitNew <1610809344> ( _                      ' VTable offset = 40
     BYVAL varTransaction AS VARIANT _                  ' __in VARIANT varTransaction
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <1> ( _                      ' VTable offset = 44
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQTransaction3 Methods
   ' =====================================================================================
   PROPERTY GET ITransaction <2> ( _                    ' VTable offset = 48
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarITransaction
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransaction3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQCoordinatedTransactionDispenser2
' IID = {EBA96B10-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQCoordinatedTransactionDispenser2_INTERFACE_DEFINED)
    %IMSMQCoordinatedTransactionDispenser2_INTERFACE_DEFINED = 1

INTERFACE IMSMQCoordinatedTransactionDispenser2 $IID_IMSMQCoordinatedTransactionDispenser2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction2                               ' __retval_out IMSMQTransaction2 **ptransaction
   ' =====================================================================================
   PROPERTY GET Properties ( _                          ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQCoordinatedTransactionDispenser2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQCoordinatedTransactionDispenser3
' IID = {EBA96B14-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQCoordinatedTransactionDispenser3_INTERFACE_DEFINED)
    %IMSMQCoordinatedTransactionDispenser3_INTERFACE_DEFINED = 1

INTERFACE IMSMQCoordinatedTransactionDispenser3 $IID_IMSMQCoordinatedTransactionDispenser3

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction3                               ' __retval_out IMSMQTransaction3 **ptransaction
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQCoordinatedTransactionDispenser3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransactionDispenser2
' IID = {EBA96B11-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQTransactionDispenser2_INTERFACE_DEFINED)
    %IMSMQTransactionDispenser2_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransactionDispenser2 $IID_IMSMQTransactionDispenser2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction2                               ' __retval_out IMSMQTransaction2 **ptransaction
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransactionDispenser2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQTransactionDispenser3
' IID = {EBA96B15-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQTransactionDispenser3_INTERFACE_DEFINED)
    %IMSMQTransactionDispenser3_INTERFACE_DEFINED = 1

INTERFACE IMSMQTransactionDispenser3 $IID_IMSMQTransactionDispenser3

   INHERIT IDispatch

   ' =====================================================================================
   METHOD BeginTransaction <1610743808> ( _             ' VTable offset = 28
   ) AS IMSMQTransaction3                               ' __retval_out IMSMQTransaction3 **ptransaction
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQTransactionDispenser3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQApplication
' IID = {D7D6E085-DCCD-11D0-AA4B-0060970DEBAE}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQApplication_INTERFACE_DEFINED)
    %IMSMQApplication_INTERFACE_DEFINED = 1

INTERFACE IMSMQApplication $IID_IMSMQApplication

   INHERIT IDispatch

   ' =====================================================================================
   METHOD MachineIdOfMachineName <1610743808> ( _       ' VTable offset = 28
     BYVAL MachineName AS WSTRING _                     ' __in BSTR MachineName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuid
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQApplication_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQApplication2
' IID = {12A30900-7300-11D2-B0E6-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQApplication
' ########################################################################################

#IF NOT %DEF(%IMSMQApplication2_INTERFACE_DEFINED)
    %IMSMQApplication2_INTERFACE_DEFINED = 1

INTERFACE IMSMQApplication2 $IID_IMSMQApplication2

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQApplication Methods
   ' =====================================================================================
   METHOD MachineIdOfMachineName <1610743808> ( _       ' VTable offset = 28
     BYVAL MachineName AS WSTRING _                     ' __in BSTR MachineName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuid
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQApplication2 Methods
   ' =====================================================================================
   METHOD RegisterCertificate <1610809344> ( _          ' VTable offset = 32
     OPTIONAL BYREF Flags AS VARIANT _                  ' __in_opt VARIANT *Flags
   , OPTIONAL BYREF ExternalCertificate AS VARIANT _    ' __in_opt VARIANT *ExternalCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD MachineNameOfMachineId <1610809345> ( _       ' VTable offset = 36
     BYVAL bstrGuid AS WSTRING _                        ' __in BSTR bstrGuid
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachineName
   ' =====================================================================================
   PROPERTY GET MSMQVersionMajor <1> ( _                ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionMajor
   ' =====================================================================================
   PROPERTY GET MSMQVersionMinor <2> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionMinor
   ' =====================================================================================
   PROPERTY GET MSMQVersionBuild <3> ( _                ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionBuild
   ' =====================================================================================
   PROPERTY GET IsDsEnabled <4> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsDsEnabled
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQApplication2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQApplication3
' IID = {EBA96B1F-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IMSMQApplication2
' ########################################################################################

#IF NOT %DEF(%IMSMQApplication3_INTERFACE_DEFINED)
    %IMSMQApplication3_INTERFACE_DEFINED = 1

INTERFACE IMSMQApplication3 $IID_IMSMQApplication3

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQApplication Methods
   ' =====================================================================================
   METHOD MachineIdOfMachineName <1610743808> ( _       ' VTable offset = 28
     BYVAL MachineName AS WSTRING _                     ' __in BSTR MachineName
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrGuid
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQApplication2 Methods
   ' =====================================================================================
   METHOD RegisterCertificate <1610809344> ( _          ' VTable offset = 32
     OPTIONAL BYREF Flags AS VARIANT _                  ' __in_opt VARIANT *Flags
   , OPTIONAL BYREF ExternalCertificate AS VARIANT _    ' __in_opt VARIANT *ExternalCertificate
   )                                                    ' void
   ' =====================================================================================
   METHOD MachineNameOfMachineId <1610809345> ( _       ' VTable offset = 36
     BYVAL bstrGuid AS WSTRING _                        ' __in BSTR bstrGuid
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachineName
   ' =====================================================================================
   PROPERTY GET MSMQVersionMajor <1> ( _                ' VTable offset = 40
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionMajor
   ' =====================================================================================
   PROPERTY GET MSMQVersionMinor <2> ( _                ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionMinor
   ' =====================================================================================
   PROPERTY GET MSMQVersionBuild <3> ( _                ' VTable offset = 48
   ) AS INTEGER                                         ' __retval_out short *psMSMQVersionBuild
   ' =====================================================================================
   PROPERTY GET IsDsEnabled <4> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsDsEnabled
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 56
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQApplication3 Methods
   ' =====================================================================================
   PROPERTY GET ActiveQueues <5> ( _                    ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvActiveQueues
   ' =====================================================================================
   PROPERTY GET PrivateQueues <6> ( _                   ' VTable offset = 64
   ) AS VARIANT                                         ' __retval_out VARIANT *pvPrivateQueues
   ' =====================================================================================
   PROPERTY GET DirectoryServiceServer <7> ( _          ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrDirectoryServiceServer
   ' =====================================================================================
   PROPERTY GET IsConnected <8> ( _                     ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsConnected
   ' =====================================================================================
   PROPERTY GET BytesInAllQueues <9> ( _                ' VTable offset = 76
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBytesInAllQueues
   ' =====================================================================================
   PROPERTY SET Machine <10> ( _                        ' VTable offset = 80
     BYVAL bstrMachine AS WSTRING _                     ' __in BSTR bstrMachine
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Machine <10> ( _                        ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachine
   ' =====================================================================================
   METHOD Connect <1610874887> ( _                      ' VTable offset = 88
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <1610874888> ( _                   ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================
   METHOD Tidy <1610874889> ( _                         ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQApplication3_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQDestination
' IID = {EBA96B16-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQDestination_INTERFACE_DEFINED)
    %IMSMQDestination_INTERFACE_DEFINED = 1

INTERFACE IMSMQDestination $IID_IMSMQDestination

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Open <1610743808> ( _                         ' VTable offset = 28
   )                                                    ' void
   ' =====================================================================================
   METHOD Close <1610743809> ( _                        ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET IsOpen <1> ( _                          ' VTable offset = 36
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsOpen
   ' =====================================================================================
   PROPERTY GET IADs <2> ( _                            ' VTable offset = 40
   ) AS IDispatch                                       ' __retval_out IDispatch **ppIADs
   ' =====================================================================================
   PROPERTY SET putref_IADs <2> ( _                     ' VTable offset = 44
     BYVAL pIADs AS IDispatch _                         ' __in IDispatch *pIADs
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ADsPath <3> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrADsPath
   ' =====================================================================================
   PROPERTY SET ADsPath <3> ( _                         ' VTable offset = 52
     BYVAL bstrADsPath AS WSTRING _                     ' __in BSTR bstrADsPath
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PathName <4> ( _                        ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrPathName
   ' =====================================================================================
   PROPERTY SET PathName <4> ( _                        ' VTable offset = 60
     BYVAL bstrPathName AS WSTRING _                    ' __in BSTR bstrPathName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <5> ( _                      ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY SET FormatName <5> ( _                      ' VTable offset = 68
     BYVAL bstrFormatName AS WSTRING _                  ' __in BSTR bstrFormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Destinations <6> ( _                    ' VTable offset = 72
   ) AS IDispatch                                       ' __retval_out IDispatch **ppDestinations
   ' =====================================================================================
   PROPERTY SET putref_Destinations <6> ( _             ' VTable offset = 76
     BYVAL pDestinations AS IDispatch _                 ' __in IDispatch *pDestinations
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Properties <0> ( _                      ' VTable offset = 80
   ) AS IDispatch                                       ' __retval_out IDispatch **ppcolProperties
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQDestination_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQPrivateDestination
' IID = {EBA96B17-2168-11D3-898C-00E02C074F6B}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQPrivateDestination_INTERFACE_DEFINED)
    %IMSMQPrivateDestination_INTERFACE_DEFINED = 1

INTERFACE IMSMQPrivateDestination $IID_IMSMQPrivateDestination

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Handle <7> ( _                          ' VTable offset = 28
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarHandle
   ' =====================================================================================
   PROPERTY SET Handle <7> ( _                          ' VTable offset = 32
     BYVAL varHandle AS VARIANT _                       ' __in VARIANT varHandle
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQPrivateDestination_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQCollection
' IID = {0188AC2F-ECB3-4173-9779-635CA2039C72}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQCollection_INTERFACE_DEFINED)
    %IMSMQCollection_INTERFACE_DEFINED = 1

INTERFACE IMSMQCollection $IID_IMSMQCollection

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Item <0> ( _                                  ' VTable offset = 28
     BYREF Index AS VARIANT _                           ' __in VARIANT *Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarRet
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pCount
   ' =====================================================================================
   METHOD NewEnum_ <-4> ( _                             ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IUnknown **ppunk
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQCollection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQManagement
' IID = {BE5F0241-E489-4957-8CC4-A452FCF3E23E}
' Attributes = 4176 [&H1050] [Hidden] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSMQManagement_INTERFACE_DEFINED)
    %IMSMQManagement_INTERFACE_DEFINED = 1

INTERFACE IMSMQManagement $IID_IMSMQManagement

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Init <0> ( _                                  ' VTable offset = 28
     OPTIONAL BYREF Machine AS VARIANT _                ' __in_opt VARIANT *Machine
   , OPTIONAL BYREF Pathname AS VARIANT _               ' __in_opt VARIANT *Pathname
   , OPTIONAL BYREF FormatName AS VARIANT _             ' __in_opt VARIANT *FormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <1> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY GET Machine <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachine
   ' =====================================================================================
   PROPERTY GET MessageCount <3> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMessageCount
   ' =====================================================================================
   PROPERTY GET ForeignStatus <4> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plForeignStatus
   ' =====================================================================================
   PROPERTY GET QueueType <5> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plQueueType
   ' =====================================================================================
   PROPERTY GET IsLocal <6> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsLocal
   ' =====================================================================================
   PROPERTY GET TransactionalStatus <7> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plTransactionalStatus
   ' =====================================================================================
   PROPERTY GET BytesInQueue <8> ( _                    ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBytesInQueue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQManagement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQOutgoingQueueManagement
' IID = {64C478FB-F9B0-4695-8A7F-439AC94326D3}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSMQManagement
' ########################################################################################

#IF NOT %DEF(%IMSMQOutgoingQueueManagement_INTERFACE_DEFINED)
    %IMSMQOutgoingQueueManagement_INTERFACE_DEFINED = 1

INTERFACE IMSMQOutgoingQueueManagement $IID_IMSMQOutgoingQueueManagement

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQManagement Methods
   ' =====================================================================================
   METHOD Init <0> ( _                                  ' VTable offset = 28
     OPTIONAL BYREF Machine AS VARIANT _                ' __in_opt VARIANT *Machine
   , OPTIONAL BYREF Pathname AS VARIANT _               ' __in_opt VARIANT *Pathname
   , OPTIONAL BYREF FormatName AS VARIANT _             ' __in_opt VARIANT *FormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <1> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY GET Machine <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachine
   ' =====================================================================================
   PROPERTY GET MessageCount <3> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMessageCount
   ' =====================================================================================
   PROPERTY GET ForeignStatus <4> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plForeignStatus
   ' =====================================================================================
   PROPERTY GET QueueType <5> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plQueueType
   ' =====================================================================================
   PROPERTY GET IsLocal <6> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsLocal
   ' =====================================================================================
   PROPERTY GET TransactionalStatus <7> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plTransactionalStatus
   ' =====================================================================================
   PROPERTY GET BytesInQueue <8> ( _                    ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBytesInQueue
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQOutgoingQueueManagement Methods
   ' =====================================================================================
   PROPERTY GET State <1610809344> ( _                  ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plState
   ' =====================================================================================
   PROPERTY GET NextHops <1610809345> ( _               ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvNextHops
   ' =====================================================================================
   METHOD EodGetSendInfo <1610809346> ( _               ' VTable offset = 72
   ) AS IMSMQCollection                                 ' __retval_out IMSMQCollection **ppCollection
   ' =====================================================================================
   METHOD Resume <1610809347> ( _                       ' VTable offset = 76
   )                                                    ' void
   ' =====================================================================================
   METHOD Pause <1610809348> ( _                        ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================
   METHOD EodResend <1610809349> ( _                    ' VTable offset = 84
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQOutgoingQueueManagement_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMSMQQueueManagement
' IID = {7FBE7759-5760-444D-B8A5-5E7AB9A84CCE}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IMSMQManagement
' ########################################################################################

#IF NOT %DEF(%IMSMQQueueManagement_INTERFACE_DEFINED)
    %IMSMQQueueManagement_INTERFACE_DEFINED = 1

INTERFACE IMSMQQueueManagement $IID_IMSMQQueueManagement

   INHERIT IDispatch

   ' =====================================================================================
   ' IMSMQManagement Methods
   ' =====================================================================================
   METHOD Init <0> ( _                                  ' VTable offset = 28
     OPTIONAL BYREF Machine AS VARIANT _                ' __in_opt VARIANT *Machine
   , OPTIONAL BYREF Pathname AS VARIANT _               ' __in_opt VARIANT *Pathname
   , OPTIONAL BYREF FormatName AS VARIANT _             ' __in_opt VARIANT *FormatName
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET FormatName <1> ( _                      ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrFormatName
   ' =====================================================================================
   PROPERTY GET Machine <2> ( _                         ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pbstrMachine
   ' =====================================================================================
   PROPERTY GET MessageCount <3> ( _                    ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *plMessageCount
   ' =====================================================================================
   PROPERTY GET ForeignStatus <4> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *plForeignStatus
   ' =====================================================================================
   PROPERTY GET QueueType <5> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *plQueueType
   ' =====================================================================================
   PROPERTY GET IsLocal <6> ( _                         ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pfIsLocal
   ' =====================================================================================
   PROPERTY GET TransactionalStatus <7> ( _             ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *plTransactionalStatus
   ' =====================================================================================
   PROPERTY GET BytesInQueue <8> ( _                    ' VTable offset = 60
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBytesInQueue
   ' =====================================================================================

   ' =====================================================================================
   ' IMSMQQueueManagement Methods
   ' =====================================================================================
   PROPERTY GET JournalMessageCount <1610809344> ( _    ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *plJournalMessageCount
   ' =====================================================================================
   PROPERTY GET BytesInJournal <1610809345> ( _         ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pvBytesInJournal
   ' =====================================================================================
   METHOD EodGetReceiveInfo <1610809346> ( _            ' VTable offset = 72
   ) AS VARIANT                                         ' __retval_out VARIANT *pvCollection
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSMQQueueManagement_INTERFACE_DEFINED__ */
