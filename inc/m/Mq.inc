' ########################################################################################
' Microsoft Windows
' File: Mq.inc
' Contents: Master include file for Message Queuing applications
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MQ_INC = 1

#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "transact.inc"

'#ifndef __ITransaction_FWD_DEFINED__
'#define __ITransaction_FWD_DEFINED__
'typedef interface ITransaction ITransaction;
'#endif  // __ITransaction_FWD_DEFINED__

'typedef struct tagPROPVARIANT tagMQPROPVARIANT;
'typedef tagMQPROPVARIANT MQPROPVARIANT;

MACRO MQPROPVARIANT = PROPVARIANT


%PRLT   = 0
%PRLE   = 1
%PRGT   = 2
%PRGE   = 3
%PREQ   = 4
%PRNE   = 5

' // Size = 24 bytes
TYPE MQPROPERTYRESTRICTION DWORD
   rel   AS DWORD           ' ULONG
   prop  AS DWORD           ' PROPID
   prval AS MQPROPVARIANT
END TYPE

' // Size = 8 bytes
TYPE MQRESTRICTION DWORD
   cRes      AS DWORD                       ' /* [range] */ ULONG cRes
   paPropRes AS MQPROPERTYRESTRICTION PTR   ' /* [size_is] */ MQPROPERTYRESTRICTION *paPropRes
END TYPE

' // Size = 8 bytes
TYPE MQCOLUMNSET DWORD
   cCol AS DWORD       ' /* [range] */ ULONG cCol
   aCol AS DWORD PTR   ' /* [size_is] */ PROPID *aCol
END TYPE

%QUERY_SORTASCEND  = 0
%QUERY_SORTDESCEND = 1

' // Size = 8 bytes
TYPE MQSORTKEY DWORD
   propColumn AS DWORD   ' PROPID
   dwOrder    AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE MQSORTSET DWORD
   cCol AS DWORD
   aCol AS MQSORTKEY PTR
END TYPE

'typedef HANDLE QUEUEHANDLE;

'typedef PROPID MSGPROPID;
' // Size = 16 bytes
TYPE MQMSGPROPS DWORD
   cProp    AS DWORD               ' DWORD
   aPropID  AS DWORD PTR           ' MSGPROPID*
   aPropVar AS MQPROPVARIANT PTR   ' MQPROPVARIANT*
   aStatus  AS LONG PTR            ' HRESULT*
END TYPE

'typedef PROPID QUEUEPROPID;
' // Size = 16 bytes
TYPE MQQUEUEPROPS DWORD
   cProp    AS DWORD               ' DWORD
   aPropID  AS DWORD         PTR   ' QUEUEPROPID*
   aPropVar AS MQPROPVARIANT PTR   ' MQPROPVARIANT*
   aStatus  AS LONG          PTR   ' HRESULT*
END TYPE

'typedef PROPID QMPROPID;
' // Size = 16 bytes
TYPE MQQMPROPS DWORD
   cProp    AS DWORD               ' DWORD
   aPropID  AS DWORD         PTR   ' QMPROPID*
   aPropVar AS MQPROPVARIANT PTR   ' MQPROPVARIANT*
   aStatus  AS LONG          PTR   ' HRESULT*
END TYPE

' // Size = 16 bytes
TYPE MQPRIVATEPROPS DWORD
   cProp    AS DWORD               ' DWORD
   aPropID  AS DWORD         PTR   ' QMPROPID*
   aPropVar AS MQPROPVARIANT PTR   ' MQPROPVARIANT*
   aStatus  AS LONG          PTR   ' HRESULT*
END TYPE

'typedef PROPID MGMTPROPID;
' // Size = 16 bytes
TYPE MQMGMTPROPS DWORD
   cProp    AS DWORD               ' DWORD
   aPropID  AS DWORD         PTR   ' MGMTPROPID*
   aPropVar AS MQPROPVARIANT PTR   ' MQPROPVARIANT*
   aStatus  AS LONG          PTR   ' HRESULT*
END TYPE

' // Size = 16 bytes
TYPE SEQUENCE_INFO DWORD
   SeqID  AS QUAD    ' LONGLONG
   SeqNo  AS DWORD   ' ULONG
   PrevNo AS DWORD   ' ULONG
END TYPE


' enum MQConnectionState
%MQCONN_NOFAILURE                 = 0                                     ' // connection is in the process of establishment, no failures have occured
%MQCONN_ESTABLISH_PACKET_RECEIVED = 1                                     ' // NATIVE SESSION ONLY: connection establishment packed has been received
%MQCONN_READY                     = 2                                     ' // connection has been successfully established   and is ready to send messages

%MQCONN_UNKNOWN_FAILURE           = &H80000000???                         ' // exact reason for failure cannot be determined
%MQCONN_PING_FAILURE              = %MQCONN_UNKNOWN_FAILURE         + 1   ' // ping didnt answer (udp to 3527)
%MQCONN_CREATE_SOCKET_FAILURE     = %MQCONN_PING_FAILURE            + 1   ' // these 4 states represent failure to establish TCP connection on 1801
%MQCONN_BIND_SOCKET_FAILURE       = %MQCONN_CREATE_SOCKET_FAILURE   + 1
%MQCONN_CONNECT_SOCKET_FAILURE    = %MQCONN_BIND_SOCKET_FAILURE     + 1
%MQCONN_TCP_NOT_ENABLED           = %MQCONN_CONNECT_SOCKET_FAILURE  + 1
%MQCONN_SEND_FAILURE              = %MQCONN_TCP_NOT_ENABLED         + 1   ' // send operation on a socket (WSASend) failed
%MQCONN_NOT_READY                 = %MQCONN_SEND_FAILURE            + 1   ' // send operation failed because connection is not ready
%MQCONN_NAME_RESOLUTION_FAILURE   = %MQCONN_NOT_READY               + 1   ' // dns failure
%MQCONN_INVALID_SERVER_CERT       = %MQCONN_NAME_RESOLUTION_FAILURE + 1   ' // could not validate server certificate in https scenario
%MQCONN_LIMIT_REACHED             = %MQCONN_INVALID_SERVER_CERT     + 1   ' // connection limit reached, can't establish new session to a specific destination
%MQCONN_REFUSED_BY_OTHER_SIDE     = %MQCONN_LIMIT_REACHED           + 1   ' // connection refused by other side due to any reason(quota, invalid packet, connection limit reached)
%MQCONN_ROUTING_FAILURE           = %MQCONN_REFUSED_BY_OTHER_SIDE   + 1   ' // absense of DS connectivity prevented getting routing data
%MQCONN_OUT_OF_MEMORY             = %MQCONN_ROUTING_FAILURE         + 1   ' // failure due to low memory (e.g. bad_alloc exception when trying to send a packet)


'//********************************************************************
'//  API FLAGS
'//********************************************************************

'//
'//  MQOpenQueue - Access values
'//
%MQ_RECEIVE_ACCESS       = &H00000001???
%MQ_SEND_ACCESS          = &H00000002???
%MQ_PEEK_ACCESS          = &H00000020???
%MQ_ADMIN_ACCESS         = &H00000080???

'//
'//  MQOpenQueue - Share values
'//
%MQ_DENY_NONE            = &H00000000???
%MQ_DENY_RECEIVE_SHARE   = &H00000001???

'//
'//  MQReceiveMessage - Action values
'//
%MQ_ACTION_RECEIVE       = &H00000000???
%MQ_ACTION_PEEK_CURRENT  = &H80000000???
%MQ_ACTION_PEEK_NEXT     = &H80000001???

'//
'//  MQReceiveMessageByLookupId - Action values
'//
'#if(_WIN32_WINNT >= = &H0501)
%MQ_LOOKUP_PEEK_CURRENT    = &H40000010???
%MQ_LOOKUP_PEEK_NEXT       = &H40000011???
%MQ_LOOKUP_PEEK_PREV       = &H40000012???
%MQ_LOOKUP_PEEK_FIRST      = &H40000014???
%MQ_LOOKUP_PEEK_LAST       = &H40000018???

%MQ_LOOKUP_RECEIVE_CURRENT = &H40000020???
%MQ_LOOKUP_RECEIVE_NEXT    = &H40000021???
%MQ_LOOKUP_RECEIVE_PREV    = &H40000022???
%MQ_LOOKUP_RECEIVE_FIRST   = &H40000024???
%MQ_LOOKUP_RECEIVE_LAST    = &H40000028???
%MQ_LOOKUP_RECEIVE_ALLOW_PEEK  = &H40000120???   ' //TBD: exact value of this constant
'#endif

'//
'// MQSendMessage,  MQReceiveMessage:  special cases for the transaction parameter
'//
%MQ_NO_TRANSACTION             = 0      ' %NULL
%MQ_MTS_TRANSACTION            = 1???   ' (ITransaction *)1
%MQ_XA_TRANSACTION             = 2???   ' (ITransaction *)2
%MQ_SINGLE_MESSAGE             = 3???   ' (ITransaction *)3


'//********************************************************************
'//  PRIORITY LIMITS
'//********************************************************************

'//
'//  Message priorities
'//
%MQ_MIN_PRIORITY          = 0   ' // Minimal message priority
%MQ_MAX_PRIORITY          = 7   ' // Maximal message priority


'//********************************************************************
'//  MESSAGE PROPERTIES
'//********************************************************************
%PROPID_M_BASE                    = 0
%PROPID_M_CLASS                   = (%PROPID_M_BASE + 1)     ' /* VT_UI2           */
%PROPID_M_MSGID                   = (%PROPID_M_BASE + 2)     ' /* VT_UI1|VT_VECTOR */
%PROPID_M_CORRELATIONID           = (%PROPID_M_BASE + 3)     ' /* VT_UI1|VT_VECTOR */
%PROPID_M_PRIORITY                = (%PROPID_M_BASE + 4)     ' /* VT_UI1           */
%PROPID_M_DELIVERY                = (%PROPID_M_BASE + 5)     ' /* VT_UI1           */
%PROPID_M_ACKNOWLEDGE             = (%PROPID_M_BASE + 6)     ' /* VT_UI1           */
%PROPID_M_JOURNAL                 = (%PROPID_M_BASE + 7)     ' /* VT_UI1           */
%PROPID_M_APPSPECIFIC             = (%PROPID_M_BASE + 8)     ' /* VT_UI4           */
%PROPID_M_BODY                    = (%PROPID_M_BASE + 9)     ' /* VT_UI1|VT_VECTOR */
%PROPID_M_BODY_SIZE               = (%PROPID_M_BASE + 10)    ' /* VT_UI4           */
%PROPID_M_LABEL                   = (%PROPID_M_BASE + 11)    ' /* VT_LPWSTR        */
%PROPID_M_LABEL_LEN               = (%PROPID_M_BASE + 12)    ' /* VT_UI4           */
%PROPID_M_TIME_TO_REACH_QUEUE     = (%PROPID_M_BASE + 13)    ' /* VT_UI4           */
%PROPID_M_TIME_TO_BE_RECEIVED     = (%PROPID_M_BASE + 14)    ' /* VT_UI4           */
%PROPID_M_RESP_QUEUE              = (%PROPID_M_BASE + 15)    ' /* VT_LPWSTR        */
%PROPID_M_RESP_QUEUE_LEN          = (%PROPID_M_BASE + 16)    ' /* VT_UI4           */
%PROPID_M_ADMIN_QUEUE             = (%PROPID_M_BASE + 17)    ' /* VT_LPWSTR        */
%PROPID_M_ADMIN_QUEUE_LEN         = (%PROPID_M_BASE + 18)    ' /* VT_UI4           */
%PROPID_M_VERSION                 = (%PROPID_M_BASE + 19)    ' /* VT_UI4           */
%PROPID_M_SENDERID                = (%PROPID_M_BASE + 20)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_SENDERID_LEN            = (%PROPID_M_BASE + 21)    ' /* VT_UI4           */
%PROPID_M_SENDERID_TYPE           = (%PROPID_M_BASE + 22)    ' /* VT_UI4           */
%PROPID_M_PRIV_LEVEL              = (%PROPID_M_BASE + 23)    ' /* VT_UI4           */
%PROPID_M_AUTH_LEVEL              = (%PROPID_M_BASE + 24)    ' /* VT_UI4           */
%PROPID_M_AUTHENTICATED           = (%PROPID_M_BASE + 25)    ' /* VT_UI1           */
%PROPID_M_HASH_ALG                = (%PROPID_M_BASE + 26)    ' /* VT_UI4           */
%PROPID_M_ENCRYPTION_ALG          = (%PROPID_M_BASE + 27)    ' /* VT_UI4           */
%PROPID_M_SENDER_CERT             = (%PROPID_M_BASE + 28)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_SENDER_CERT_LEN         = (%PROPID_M_BASE + 29)    ' /* VT_UI4           */
%PROPID_M_SRC_MACHINE_ID          = (%PROPID_M_BASE + 30)    ' /* VT_CLSID         */
%PROPID_M_SENTTIME                = (%PROPID_M_BASE + 31)    ' /* VT_UI4           */
%PROPID_M_ARRIVEDTIME             = (%PROPID_M_BASE + 32)    ' /* VT_UI4           */
%PROPID_M_DEST_QUEUE              = (%PROPID_M_BASE + 33)    ' /* VT_LPWSTR        */
%PROPID_M_DEST_QUEUE_LEN          = (%PROPID_M_BASE + 34)    ' /* VT_UI4           */
%PROPID_M_EXTENSION               = (%PROPID_M_BASE + 35)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_EXTENSION_LEN           = (%PROPID_M_BASE + 36)    ' /* VT_UI4           */
%PROPID_M_SECURITY_CONTEXT        = (%PROPID_M_BASE + 37)    ' /* VT_UI4           */
%PROPID_M_CONNECTOR_TYPE          = (%PROPID_M_BASE + 38)    ' /* VT_CLSID         */
%PROPID_M_XACT_STATUS_QUEUE       = (%PROPID_M_BASE + 39)    ' /* VT_LPWSTR        */
%PROPID_M_XACT_STATUS_QUEUE_LEN   = (%PROPID_M_BASE + 40)    ' /* VT_UI4           */
%PROPID_M_TRACE                   = (%PROPID_M_BASE + 41)    ' /* VT_UI1           */
%PROPID_M_BODY_TYPE               = (%PROPID_M_BASE + 42)    ' /* VT_UI4           */
%PROPID_M_DEST_SYMM_KEY           = (%PROPID_M_BASE + 43)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_DEST_SYMM_KEY_LEN       = (%PROPID_M_BASE + 44)    ' /* VT_UI4           */
%PROPID_M_SIGNATURE               = (%PROPID_M_BASE + 45)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_SIGNATURE_LEN           = (%PROPID_M_BASE + 46)    ' /* VT_UI4           */
%PROPID_M_PROV_TYPE               = (%PROPID_M_BASE + 47)    ' /* VT_UI4           */
%PROPID_M_PROV_NAME               = (%PROPID_M_BASE + 48)    ' /* VT_LPWSTR        */
%PROPID_M_PROV_NAME_LEN           = (%PROPID_M_BASE + 49)    ' /* VT_UI4           */
%PROPID_M_FIRST_IN_XACT           = (%PROPID_M_BASE + 50)    ' /* VT_UI1           */
%PROPID_M_LAST_IN_XACT            = (%PROPID_M_BASE + 51)    ' /* VT_UI1           */
%PROPID_M_XACTID                  = (%PROPID_M_BASE + 52)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_AUTHENTICATED_EX        = (%PROPID_M_BASE + 53)    ' /* VT_UI1           */
'#if(_WIN32_WINNT >= 0x0501)
%PROPID_M_RESP_FORMAT_NAME        = (%PROPID_M_BASE + 54)    ' /* VT_LPWSTR        */
%PROPID_M_RESP_FORMAT_NAME_LEN    = (%PROPID_M_BASE + 55)    ' /* VT_UI4           */
%PROPID_M_DEST_FORMAT_NAME        = (%PROPID_M_BASE + 58)    ' /* VT_LPWSTR        */
%PROPID_M_DEST_FORMAT_NAME_LEN    = (%PROPID_M_BASE + 59)    ' /* VT_UI4           */
%PROPID_M_LOOKUPID                = (%PROPID_M_BASE + 60)    ' /* VT_UI8           */
%PROPID_M_SOAP_ENVELOPE           = (%PROPID_M_BASE + 61)    ' /* VT_LPWSTR        */
%PROPID_M_SOAP_ENVELOPE_LEN       = (%PROPID_M_BASE + 62)    ' /* VT_UI4           */
%PROPID_M_COMPOUND_MESSAGE        = (%PROPID_M_BASE + 63)    ' /* VT_UI1|VT_VECTOR */
%PROPID_M_COMPOUND_MESSAGE_SIZE   = (%PROPID_M_BASE + 64)    ' /* VT_UI4           */
%PROPID_M_SOAP_HEADER             = (%PROPID_M_BASE + 65)    ' /* VT_LPWSTR        */
%PROPID_M_SOAP_BODY               = (%PROPID_M_BASE + 66)    ' /* VT_LPWSTR        */
%PROPID_M_DEADLETTER_QUEUE        = (%PROPID_M_BASE + 67)    ' /* VT_LPWSTR        */
%PROPID_M_DEADLETTER_QUEUE_LEN    = (%PROPID_M_BASE + 68)    ' /* VT_UI4           */
%PROPID_M_ABORT_COUNT             = (%PROPID_M_BASE + 69)    ' /* VT_UI4           */
%PROPID_M_MOVE_COUNT              = (%PROPID_M_BASE + 70)    ' /* VT_UI4           */
%PROPID_M_LAST_MOVE_TIME          = (%PROPID_M_BASE + 75)    ' /* VT_UI4           */
'#endif

'//
'// Message Property Size
'//
%PROPID_M_MSGID_SIZE         = 20
%PROPID_M_CORRELATIONID_SIZE = 20
%PROPID_M_XACTID_SIZE        = 20


'//********************************************************************
'//  MESSAGE CLASS VALUES
'//********************************************************************
'//
'//  Message class values are 16 bits laid out as follows:
'//
'//   1 1 1 1 1 1
'//   5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +-+-+-+-------+-----------------+
'//  |S|R|H| Rsrve |    Class code   |
'//  +-+-+-+-------+-----------------+
'//
'//  where
'//
'//  Class code must be 9 bits, to accomodate http too. (40X, 50X codes).
'//
'//      S - is the severity flag
'//          0 - Normal Message/Positive Acknowledgment (ACK)
'//          1 - Negative Acknowledgment (NACK)
'//
'//      R - is the receive flag
'//          0 - Arrival ACK/NACK
'//          1 - Receive ACK/NACK
'//
'//      H - is http flag
'//          0 - no http
'//          1 - http


'#define MQCLASS_CODE(s, r, code) ((USHORT)(((s) << 15) | ((r) << 14) | (code)))
FUNCTION MQCLASS_CODE (BYVAL s AS WORD, BYVAL r AS WORD, BYVAL code AS WORD) AS WORD
  SHIFT LEFT s, 15
  SHIFT LEFT r, 14
  MQCLASS_CODE = (s OR r OR code)
END FUNCTION

'#define MQCLASS_NACK(c)     ((c) & 0x8000)
MACRO MQCLASS_NACK(c) = (c AND &H8000??)

'#define MQCLASS_RECEIVE(c)  ((c) & 0x4000)
MACRO MQCLASS_RECEIVE(c) = (c AND &H4000??)

'#define MQCLASS_NACK_HTTP(c) (((c) & 0xA000) == 0xA000)
MACRO MQCLASS_NACK_HTTP(c) = ((c AND &HA000??) = &HA000??)


'//
'//  Normal message
'//
'#define MQMSG_CLASS_NORMAL                      MQCLASS_CODE(0, 0, 0x00)
%MQMSG_CLASS_NORMAL = 0

'//
'//  Report message
'//
'#define MQMSG_CLASS_REPORT                      MQCLASS_CODE(0, 0, 0x01)
%MQMSG_CLASS_REPORT = 1

'//
'//  Arrival acknowledgment. The message has reached its destination queue
'//
'#define MQMSG_CLASS_ACK_REACH_QUEUE             MQCLASS_CODE(0, 0, 0x02)
%MQMSG_CLASS_ACK_REACH_QUEUE = 2

'//
'//  Receive acknowledgment. The message has been received by an application
'//
'#define MQMSG_CLASS_ACK_RECEIVE                 MQCLASS_CODE(0, 1, 0x00)
%MQMSG_CLASS_ACK_RECEIVE = &H4000??


'//-----------------------------------------------
'//
'//  Negative arrival acknowledgments
'//

'//
'//  Destination queue cannot be reached, the queue may have been deleted
'//
'#define MQMSG_CLASS_NACK_BAD_DST_Q              MQCLASS_CODE(1, 0, 0x00)
%MQMSG_CLASS_NACK_BAD_DST_Q = &H8000??

'//
'//  The message was purged before reaching its destination queue
'//
'#define MQMSG_CLASS_NACK_PURGED                 MQCLASS_CODE(1, 0, 0x01)
%MQMSG_CLASS_NACK_PURGED = &H8001??

'//
'//  Time to reach queue has expired
'//
'#define MQMSG_CLASS_NACK_REACH_QUEUE_TIMEOUT    MQCLASS_CODE(1, 0, 0x02)
%MQMSG_CLASS_NACK_REACH_QUEUE_TIMEOUT = &H8002??

'//
'//  The message has exceeded the queue quota
'//
'#define MQMSG_CLASS_NACK_Q_EXCEED_QUOTA         MQCLASS_CODE(1, 0, 0x03)
%MQMSG_CLASS_NACK_Q_EXCEED_QUOTA = &H8003??

'//
'//  The sender does not have send access rights to the queue.
'//
'#define MQMSG_CLASS_NACK_ACCESS_DENIED          MQCLASS_CODE(1, 0, 0x04)
%MQMSG_CLASS_NACK_ACCESS_DENIED = &H8004??

'//
'//  The message hop count was exceeded
'//
'#define MQMSG_CLASS_NACK_HOP_COUNT_EXCEEDED     MQCLASS_CODE(1, 0, 0x05)
%MQMSG_CLASS_NACK_HOP_COUNT_EXCEEDED = &H8005??

'//
'//  The message signature is bad. The message could not be authenticated.
'//
'#define MQMSG_CLASS_NACK_BAD_SIGNATURE          MQCLASS_CODE(1, 0, 0x06)
%MQMSG_CLASS_NACK_BAD_SIGNATURE = &H8006??

'//
'//  The message could not be decrypted.
'//
'#define MQMSG_CLASS_NACK_BAD_ENCRYPTION         MQCLASS_CODE(1, 0, 0x07)
%MQMSG_CLASS_NACK_BAD_ENCRYPTION = &H8007??

'//
'//  The message could not be encrypted for the destination.
'//
'#define MQMSG_CLASS_NACK_COULD_NOT_ENCRYPT      MQCLASS_CODE(1, 0, 0x08)
%MQMSG_CLASS_NACK_COULD_NOT_ENCRYPT = &H8008??

'//
'//  The message was sent to a non-transactional queue within a transaction.
'//
'#define MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_Q    MQCLASS_CODE(1, 0, 0x09)
%MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_Q = &H8009??

'//
'//  The message was sent to a transactional queue not within a transaction.
'//
'#define MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_MSG  MQCLASS_CODE(1, 0, 0x0A)
%MQMSG_CLASS_NACK_NOT_TRANSACTIONAL_MSG = &H800A??

'//
'//  The requested crypto provider for encryption is not supported by the destination.
'//
'#define MQMSG_CLASS_NACK_UNSUPPORTED_CRYPTO_PROVIDER  MQCLASS_CODE(1, 0, 0x0B)
%MQMSG_CLASS_NACK_UNSUPPORTED_CRYPTO_PROVIDER = &H800B??

'//
'// The QM GUID has changed and therefore the messages was thrown away.
'//
'#define MQMSG_CLASS_NACK_SOURCE_COMPUTER_GUID_CHANGED MQCLASS_CODE(1, 0, 0x0C)
%MQMSG_CLASS_NACK_SOURCE_COMPUTER_GUID_CHANGED = &H800C??

'//
'// The message was sent by downlevel machines (earlier than msmq4) and the message size
'// with the subqueue and IPV6 headers exceeded the max message size
'//
'#define MQMSG_CLASS_NACK_MESSAGE_TOO_LARGE MQCLASS_CODE(1, 0, 0x0D)
%MQMSG_CLASS_NACK_MESSAGE_TOO_LARGE = &H800D??

'//-----------------------------------------------
'//
'//  Negative receive acknowledgments
'//

'//
'//  The queue was deleted, after the message arrived
'//
'#define MQMSG_CLASS_NACK_Q_DELETED              MQCLASS_CODE(1, 1, 0x00)
%MQMSG_CLASS_NACK_Q_DELETED = &HC000??

'//
'//  The message was purged at the destination queue
'//
'#define MQMSG_CLASS_NACK_Q_PURGED               MQCLASS_CODE(1, 1, 0x01)
%MQMSG_CLASS_NACK_Q_PURGED = &HC001??

'//
'//  Time to receive has expired while the message was still in its destination queue
'//  (generated by destination)
'//
'#define MQMSG_CLASS_NACK_RECEIVE_TIMEOUT        MQCLASS_CODE(1, 1, 0x02)
%MQMSG_CLASS_NACK_RECEIVE_TIMEOUT = &HC002??

'//
'//  Time to receive has expired while the message was still in its local outgoing queue
'//  (generated locally by sender)
'//
'#define MQMSG_CLASS_NACK_RECEIVE_TIMEOUT_AT_SENDER  MQCLASS_CODE(1, 1, 0x03)
%MQMSG_CLASS_NACK_RECEIVE_TIMEOUT_AT_SENDER = &HC003??

'//
'// Message was rejected by a receiving application (by calling MQMarkRejected API)
'//
%MQMSG_CLASS_NACK_RECEIVE_REJECTED =  &HC004??


'//------ PROPID_M_ACKNOWLEDGE ---------------
%MQMSG_ACKNOWLEDGMENT_NONE           = &H00?

%MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL    = &H01?
%MQMSG_ACKNOWLEDGMENT_POS_RECEIVE    = &H02?
%MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL    = &H04?
%MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE    = &H08?

%MQMSG_ACKNOWLEDGMENT_NACK_REACH_QUEUE = %MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL

%MQMSG_ACKNOWLEDGMENT_FULL_REACH_QUEUE = %MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL OR _
                                         %MQMSG_ACKNOWLEDGMENT_POS_ARRIVAL

%MQMSG_ACKNOWLEDGMENT_NACK_RECEIVE = %MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL OR _
                                     %MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE

%MQMSG_ACKNOWLEDGMENT_FULL_RECEIVE = %MQMSG_ACKNOWLEDGMENT_NEG_ARRIVAL OR _
                                     %MQMSG_ACKNOWLEDGMENT_NEG_RECEIVE OR _
                                     %MQMSG_ACKNOWLEDGMENT_POS_RECEIVE

'//------ PROPID_M_DELIVERY ------------------
%MQMSG_DELIVERY_EXPRESS              = 0?
%MQMSG_DELIVERY_RECOVERABLE          = 1?

'//----- PROPID_M_JOURNAL --------------------
%MQMSG_JOURNAL_NONE                  = 0?
%MQMSG_DEADLETTER                    = 1?
%MQMSG_JOURNAL                       = 2?

'//----- PROPID_M_TRACE ----------------------
%MQMSG_TRACE_NONE                    = 0?
%MQMSG_SEND_ROUTE_TO_REPORT_QUEUE    = 1?

'//----- PROPID_M_SENDERID_TYPE --------------
%MQMSG_SENDERID_TYPE_NONE            = 0?
%MQMSG_SENDERID_TYPE_SID             = 1?

'//----- PROPID_M_PRIV_LEVEL -----------------
%MQMSG_PRIV_LEVEL_NONE               = 0?
%MQMSG_PRIV_LEVEL_BODY_BASE          = &H01?
%MQMSG_PRIV_LEVEL_BODY_ENHANCED      = &H03?

'//----- PROPID_M_AUTH_LEVEL -----------------
%MQMSG_AUTH_LEVEL_NONE               = 0?
%MQMSG_AUTH_LEVEL_ALWAYS             = 1?

'//
'// MQMSG_AUTH_LEVEL_MSMQxx are obsolete
'// you should use MQMSG_AUTH_LEVEL_SIGxx
'//
%MQMSG_AUTH_LEVEL_MSMQ10             = 2?
%MQMSG_AUTH_LEVEL_MSMQ20             = 4?

%MQMSG_AUTH_LEVEL_SIG10              = 2?
%MQMSG_AUTH_LEVEL_SIG20              = 4?
%MQMSG_AUTH_LEVEL_SIG30              = 8?


'//----- PROPID_M_AUTHENTICATED -----------------
'//----- PROPID_M_AUTHENTICATED_EX --------------
%MQMSG_AUTHENTICATION_NOT_REQUESTED  = 0?
%MQMSG_AUTHENTICATION_REQUESTED      = 1?

'//
'// MQMSG_AUTHENTICATION_REQUESTED_EX is obsolete
'// use the values MQMSG_AUTHENTICATED_SIGxx
'// for PROPID_M_AUTHENTICATED_EX
'//
%MQMSG_AUTHENTICATION_REQUESTED_EX = 3?

%MQMSG_AUTHENTICATED_SIG10         = 1?
%MQMSG_AUTHENTICATED_SIG20         = 3?
%MQMSG_AUTHENTICATED_SIG30         = 5?
%MQMSG_AUTHENTICATED_SIGXML        = 9?
%MQMSG_AUTHENTICATED_QM_MESSAGE    = 11

'//----- PROPID_M_FIRST_IN_XACT --------------
%MQMSG_NOT_FIRST_IN_XACT           = 0?
%MQMSG_FIRST_IN_XACT               = 1?

'//----- PROPID_M_LAST_IN_XACT  --------------
%MQMSG_NOT_LAST_IN_XACT            = 0?
%MQMSG_LAST_IN_XACT                = 1?


'//********************************************************************
'//  QUEUE PROPERTIES
'//********************************************************************
%PROPID_Q_BASE              = 100
%PROPID_Q_INSTANCE          = (%PROPID_Q_BASE +  1)  ' /* VT_CLSID     */
%PROPID_Q_TYPE              = (%PROPID_Q_BASE +  2)  ' /* VT_CLSID     */
%PROPID_Q_PATHNAME          = (%PROPID_Q_BASE +  3)  ' /* VT_LPWSTR    */
%PROPID_Q_JOURNAL           = (%PROPID_Q_BASE +  4)  ' /* VT_UI1       */
%PROPID_Q_QUOTA             = (%PROPID_Q_BASE +  5)  ' /* VT_UI4       */
%PROPID_Q_BASEPRIORITY      = (%PROPID_Q_BASE +  6)  ' /* VT_I2        */
%PROPID_Q_JOURNAL_QUOTA     = (%PROPID_Q_BASE +  7)  ' /* VT_UI4       */
%PROPID_Q_LABEL             = (%PROPID_Q_BASE +  8)  ' /* VT_LPWSTR    */
%PROPID_Q_CREATE_TIME       = (%PROPID_Q_BASE +  9)  ' /* VT_I4        */
%PROPID_Q_MODIFY_TIME       = (%PROPID_Q_BASE + 10)  ' /* VT_I4        */
%PROPID_Q_AUTHENTICATE      = (%PROPID_Q_BASE + 11)  ' /* VT_UI1       */
%PROPID_Q_PRIV_LEVEL        = (%PROPID_Q_BASE + 12)  ' /* VT_UI4       */
%PROPID_Q_TRANSACTION       = (%PROPID_Q_BASE + 13)  ' /* VT_UI1       */
%PROPID_Q_PATHNAME_DNS      = (%PROPID_Q_BASE + 24)  ' /* VT_LPWSTR    */
%PROPID_Q_MULTICAST_ADDRESS = (%PROPID_Q_BASE + 25)  ' /* VT_LPWSTR */
%PROPID_Q_ADS_PATH          = (%PROPID_Q_BASE + 26)  ' /* VT_LPWSTR    */


'//----- PROPID_Q_JOURNAL ------------------
%MQ_JOURNAL_NONE     = 0?   ' (unsigned char)0
%MQ_JOURNAL          = 1?   ' (unsigned char)1

'//----- PROPID_Q_TYPE ------------------
'//  {55EE8F32-CCE9-11CF-B108-0020AFD61CE9}
$MQ_QTYPE_REPORT = GUID$("{55EE8F32-CCE9-11CF-B108-0020AFD61CE9}")

'//  {55EE8F33-CCE9-11CF-B108-0020AFD61CE9}
$MQ_QTYPE_TEST = GUID$("{55EE8F33-CCE9-11CF-B108-0020AFD61CE9}")

'//----- PROPID_Q_TRANSACTION ------------------
%MQ_TRANSACTIONAL_NONE     = 0?   ' (unsigned char)0
%MQ_TRANSACTIONAL          = 1?   ' (unsigned char)1

'//----- PROPID_Q_AUTHENTICATE ------------------
%MQ_AUTHENTICATE_NONE      = 0?   ' (unsigned char)0
%MQ_AUTHENTICATE           = 1?   ' (unsigned char)1

'//----- PROPID_Q_PRIV_LEVEL ------------------
%MQ_PRIV_LEVEL_NONE        = 0???   ' (unsigned long)0
%MQ_PRIV_LEVEL_OPTIONAL    = 1???   ' (unsigned long)1
%MQ_PRIV_LEVEL_BODY        = 2???   ' (unsigned long)2


'//********************************************************************
'//  MACHINE PROPERTIES
'//********************************************************************
%PROPID_QM_BASE                       = 200

%PROPID_QM_SITE_ID                    = (%PROPID_QM_BASE +  1)  ' /* VT_CLSID            */
%PROPID_QM_MACHINE_ID                 = (%PROPID_QM_BASE +  2)  ' /* VT_CLSID            */
%PROPID_QM_PATHNAME                   = (%PROPID_QM_BASE +  3)  ' /* VT_LPWSTR           */
%PROPID_QM_CONNECTION                 = (%PROPID_QM_BASE +  4)  ' /* VT_LPWSTR|VT_VECTOR */
%PROPID_QM_ENCRYPTION_PK              = (%PROPID_QM_BASE +  5)  ' /* VT_UI1|VT_VECTOR    */
%PROPID_QM_ENCRYPTION_PK_BASE         = (%PROPID_QM_BASE + 31)  ' /* VT_UI1|VT_VECTOR  */
%PROPID_QM_ENCRYPTION_PK_ENHANCED     = (%PROPID_QM_BASE + 32)  ' /* VT_UI1|VT_VECTOR  */
%PROPID_QM_PATHNAME_DNS               = (%PROPID_QM_BASE + 33)  ' /* VT_LPWSTR         */
%PROPID_QM_ENCRYPTION_PK_AES          = (%PROPID_QM_BASE + 44)  ' /* VT_UI1|VT_VECTOR  */

'//********************************************************************
'//  PRIVATE COMPUTER PROPERTIES
'//********************************************************************
%PROPID_PC_BASE                       = 5800

%PROPID_PC_VERSION                    = (%PROPID_PC_BASE + 1)  ' /* VT_UI4            */
%PROPID_PC_DS_ENABLED                 = (%PROPID_PC_BASE + 2)  ' /* VT_BOOL           */

'//********************************************************************
'//  LOCAL ADMIN MSMQ MACHINE PROPERTIES
'//********************************************************************
%PROPID_MGMT_MSMQ_BASE                = 0
%PROPID_MGMT_MSMQ_ACTIVEQUEUES        = (%PROPID_MGMT_MSMQ_BASE + 1) ' /* VT_LPWSTR | VT_VECTOR  */
%PROPID_MGMT_MSMQ_PRIVATEQ            = (%PROPID_MGMT_MSMQ_BASE + 2) ' /* VT_LPWSTR | VT_VECTOR  */
%PROPID_MGMT_MSMQ_DSSERVER            = (%PROPID_MGMT_MSMQ_BASE + 3) ' /* VT_LPWSTR */
%PROPID_MGMT_MSMQ_CONNECTED           = (%PROPID_MGMT_MSMQ_BASE + 4) ' /* VT_LPWSTR */
%PROPID_MGMT_MSMQ_TYPE                = (%PROPID_MGMT_MSMQ_BASE + 5) ' /* VT_LPWSTR */
'#define PROPID_MGMT_MSMQ_BYTES_IN_ALL_QUEUES (PROPID_MGMT_QUEUE_BASE + 6)    /* VT_UI8    */
%PROPID_MGMT_MSMQ_BYTES_IN_ALL_QUEUES = 6                            ' /* VT_UI8    */

'//
'// Returned Value for PROPID_MGMT_MSMQ_CONNECTED property
'//
$$MSMQ_CONNECTED      = "CONNECTED"$$
$$MSMQ_DISCONNECTED   = "DISCONNECTED"$$

'//********************************************************************
'//  LOCAL ADMIN MSMQ QUEUE PROPERTIES
'//********************************************************************
%PROPID_MGMT_QUEUE_BASE                  = 0
%PROPID_MGMT_QUEUE_PATHNAME              = (%PROPID_MGMT_QUEUE_BASE + 1)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_FORMATNAME            = (%PROPID_MGMT_QUEUE_BASE + 2)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_TYPE                  = (%PROPID_MGMT_QUEUE_BASE + 3)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_LOCATION              = (%PROPID_MGMT_QUEUE_BASE + 4)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_XACT                  = (%PROPID_MGMT_QUEUE_BASE + 5)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_FOREIGN               = (%PROPID_MGMT_QUEUE_BASE + 6)    ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_MESSAGE_COUNT         = (%PROPID_MGMT_QUEUE_BASE + 7)    ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_BYTES_IN_QUEUE        = (%PROPID_MGMT_QUEUE_BASE + 8)    ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_JOURNAL_MESSAGE_COUNT = (%PROPID_MGMT_QUEUE_BASE + 9)    ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_BYTES_IN_JOURNAL      = (%PROPID_MGMT_QUEUE_BASE + 10)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_STATE                 = (%PROPID_MGMT_QUEUE_BASE + 11)   ' /* VT_LPWSTR */
%PROPID_MGMT_QUEUE_NEXTHOPS              = (%PROPID_MGMT_QUEUE_BASE + 12)   ' /* VT_LPWSTR|VT_VECTOR  */
%PROPID_MGMT_QUEUE_EOD_LAST_ACK          = (%PROPID_MGMT_QUEUE_BASE + 13)   ' /* VT_BLOB   */
%PROPID_MGMT_QUEUE_EOD_LAST_ACK_TIME     = (%PROPID_MGMT_QUEUE_BASE + 14)   ' /* VT_I4     */
%PROPID_MGMT_QUEUE_EOD_LAST_ACK_COUNT    = (%PROPID_MGMT_QUEUE_BASE + 15)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_EOD_FIRST_NON_ACK     = (%PROPID_MGMT_QUEUE_BASE + 16)   ' /* VT_BLOB   */
%PROPID_MGMT_QUEUE_EOD_LAST_NON_ACK      = (%PROPID_MGMT_QUEUE_BASE + 17)   ' /* VT_BLOB   */
%PROPID_MGMT_QUEUE_EOD_NEXT_SEQ          = (%PROPID_MGMT_QUEUE_BASE + 18)   ' /* VT_BLOB   */
%PROPID_MGMT_QUEUE_EOD_NO_READ_COUNT     = (%PROPID_MGMT_QUEUE_BASE + 19)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_EOD_NO_ACK_COUNT      = (%PROPID_MGMT_QUEUE_BASE + 20)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_EOD_RESEND_TIME       = (%PROPID_MGMT_QUEUE_BASE + 21)   ' /* VT_I4     */
%PROPID_MGMT_QUEUE_EOD_RESEND_INTERVAL   = (%PROPID_MGMT_QUEUE_BASE + 22)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_EOD_RESEND_COUNT      = (%PROPID_MGMT_QUEUE_BASE + 23)   ' /* VT_UI4    */
%PROPID_MGMT_QUEUE_EOD_SOURCE_INFO       = (%PROPID_MGMT_QUEUE_BASE + 24)   ' /* VT_VARIANT|VT_VECTOR */
%PROPID_MGMT_QUEUE_CONNECTION_HISTORY    = (%PROPID_MGMT_QUEUE_BASE + 25)   ' /* VT_BLOB | VT_VECTOR */
%PROPID_MGMT_QUEUE_SUBQUEUE_COUNT        = (%PROPID_MGMT_QUEUE_BASE + 26)   ' /* VT_UI4 */
%PROPID_MGMT_QUEUE_SUBQUEUE_NAMES        = (%PROPID_MGMT_QUEUE_BASE + 27)   ' /* VT_LPWSTR|VT_VECTOR  */


'//
'// Alternative names for "Bytes in ..."
'//
%PROPID_MGMT_QUEUE_USED_QUOTA            = %PROPID_MGMT_QUEUE_BYTES_IN_QUEUE
%PROPID_MGMT_QUEUE_JOURNAL_USED_QUOTA    = %PROPID_MGMT_QUEUE_BYTES_IN_JOURNAL

'//
'// Returned value for PROPID_MGMT_QUEUE_TYPE
'//
$$MGMT_QUEUE_TYPE_PUBLIC      = "PUBLIC"$$
$$MGMT_QUEUE_TYPE_PRIVATE     = "PRIVATE"$$
$$MGMT_QUEUE_TYPE_MACHINE     = "MACHINE"$$
$$MGMT_QUEUE_TYPE_CONNECTOR   = "CONNECTOR"$$
$$MGMT_QUEUE_TYPE_MULTICAST   = "MULTICAST"$$

'//
'// Returned value for PROPID_MGMT_QUEUE_STATE
'//
$$MGMT_QUEUE_STATE_LOCAL          = "LOCAL CONNECTION"$$
$$MGMT_QUEUE_STATE_NONACTIVE      = "INACTIVE"$$
$$MGMT_QUEUE_STATE_WAITING        = "WAITING"$$
$$MGMT_QUEUE_STATE_NEED_VALIDATE  = "NEED VALIDATION"$$
$$MGMT_QUEUE_STATE_ONHOLD         = "ONHOLD"$$
$$MGMT_QUEUE_STATE_CONNECTED      = "CONNECTED"$$
$$MGMT_QUEUE_STATE_DISCONNECTING  = "DISCONNECTING"$$
$$MGMT_QUEUE_STATE_DISCONNECTED   = "DISCONNECTED"$$
$$MGMT_QUEUE_STATE_LOCKED         = "LOCKED"$$

'//
'// Returned value for PROPID_MGMT_QUEUE_LOCATION
'//
$$MGMT_QUEUE_LOCAL_LOCATION   = "LOCAL"$$
$$MGMT_QUEUE_REMOTE_LOCATION  = "REMOTE"$$

'//
'// Returned Value for PROPID_MGMT_QUEUE_XACT and PROPID_MGMT_QUEUE_FOREIGN
'//
$$MGMT_QUEUE_UNKNOWN_TYPE     = "UNKNOWN"$$

'//
'// Obselete names left for backword compatibility.
'//
$$MGMT_QUEUE_CORRECT_TYPE     = "YES"$$
$$MGMT_QUEUE_INCORRECT_TYPE   = "NO"$$

'//
'// Names for Returned Value for PROPID_MGMT_QUEUE_XACT
'//

'//#define MGMT_QUEUE_UNKNOWN_TYPE        L"UNKNOWN"
$$MGMT_QUEUE_TRANSACTIONAL_TYPE     = "YES"$$
$$MGMT_QUEUE_NOT_TRANSACTIONAL_TYPE = "NO"$$

'//
'// Names for Returned Value for PROPID_MGMT_QUEUE_FOREIGN
'//

'//#define MGMT_QUEUE_UNKNOWN_TYPE        L"UNKNOWN"
$$MGMT_QUEUE_FOREIGN_TYPE         = "YES"$$
$$MGMT_QUEUE_NOT_FOREIGN_TYPE     = "NO"$$

'//
'// Object parameter values for MQMgmtAction API
'//
$$MO_MACHINE_TOKEN    = "MACHINE"$$
$$MO_QUEUE_TOKEN      = "QUEUE"$$

'//
'// Action parameter values for MQMgmtAction API
'//
$$MACHINE_ACTION_CONNECT      = "CONNECT"$$
$$MACHINE_ACTION_DISCONNECT   = "DISCONNECT"$$
$$MACHINE_ACTION_TIDY         = "TIDY"$$

$$QUEUE_ACTION_PAUSE      = "PAUSE"$$
$$QUEUE_ACTION_RESUME     = "RESUME"$$
$$QUEUE_ACTION_EOD_RESEND = "EOD_RESEND"$$

'//
'// LONG_LIVED is the default for PROPID_M_TIME_TO_REACH_QUEUE. If calls
'// to MQSendMessage() specify this value, or not specify this property at
'// all, then the actual timeout is obtained from Active Directory.
'//
%LONG_LIVED = &Hfffffffe???

%MQ_MAX_Q_NAME_LEN     = 124   '// Maximal WCHAR length of a queue name.
%MQ_MAX_Q_LABEL_LEN    = 124
%MQ_MAX_MSG_LABEL_LEN  = 250

'//+-----------------------------------------
'//
'// Flags for MQRegisterCertificate()
'//
'//+-----------------------------------------

%MQCERT_REGISTER_ALWAYS        = &H01
%MQCERT_REGISTER_IF_NOT_EXIST  = &H02


'//********************************************************************
'//  SECURITY Flags (Queue access control)
'//********************************************************************

%MQSEC_DELETE_MESSAGE                = &H1
%MQSEC_PEEK_MESSAGE                  = &H2
%MQSEC_WRITE_MESSAGE                 = &H4
%MQSEC_DELETE_JOURNAL_MESSAGE        = &H8
%MQSEC_SET_QUEUE_PROPERTIES          = &H10
%MQSEC_GET_QUEUE_PROPERTIES          = &H20
%MQSEC_DELETE_QUEUE                  = %DELETE
%MQSEC_GET_QUEUE_PERMISSIONS         = %READ_CONTROL
%MQSEC_CHANGE_QUEUE_PERMISSIONS      = %WRITE_DAC
%MQSEC_TAKE_QUEUE_OWNERSHIP          = %WRITE_OWNER

%MQSEC_RECEIVE_MESSAGE               = %MQSEC_DELETE_MESSAGE OR %MQSEC_PEEK_MESSAGE

%MQSEC_RECEIVE_JOURNAL_MESSAGE       = %MQSEC_DELETE_JOURNAL_MESSAGE OR %MQSEC_PEEK_MESSAGE

%MQSEC_QUEUE_GENERIC_READ            = %MQSEC_GET_QUEUE_PROPERTIES OR _
                                       %MQSEC_GET_QUEUE_PERMISSIONS OR _
                                       %MQSEC_RECEIVE_MESSAGE OR _
                                       %MQSEC_RECEIVE_JOURNAL_MESSAGE

%MQSEC_QUEUE_GENERIC_WRITE           = %MQSEC_GET_QUEUE_PROPERTIES OR _
                                       %MQSEC_GET_QUEUE_PERMISSIONS OR _
                                       %MQSEC_WRITE_MESSAGE

%MQSEC_QUEUE_GENERIC_EXECUTE         = 0

%MQSEC_QUEUE_GENERIC_ALL             = %MQSEC_RECEIVE_MESSAGE OR _
                                       %MQSEC_RECEIVE_JOURNAL_MESSAGE OR _
                                       %MQSEC_WRITE_MESSAGE OR _
                                       %MQSEC_SET_QUEUE_PROPERTIES OR _
                                       %MQSEC_GET_QUEUE_PROPERTIES OR _
                                       %MQSEC_DELETE_QUEUE OR _
                                       %MQSEC_GET_QUEUE_PERMISSIONS OR _
                                       %MQSEC_CHANGE_QUEUE_PERMISSIONS OR _
                                       %MQSEC_TAKE_QUEUE_OWNERSHIP


'/////////////////////////////////////////////////////////////////////////
'//
'// Message Queuing Success values
'//
'//
'/////////////////////////////////////////////////////////////////////////

'#define MQ_OK                       ((HRESULT)0L
%MQ_OK = 0&

'/////////////////////////////////////////////////////////////////////////
'//
'// Message Queuing Information values
'//
'//
'/////////////////////////////////////////////////////////////////////////

'//
'//  Values are 32 bit values layed out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +---+-+-+-----------------------+-------------------------------+
'//  |Sev|C|R|     Facility          |               Code            |
'//  +---+-+-+-----------------------+-------------------------------+
'//
'//  where
'//
'//      Sev - is the severity code
'//
'//          00 - Success
'//          01 - Informational
'//          10 - Warning
'//          11 - Error
'//
'//      C - is the Customer code flag
'//
'//      R - is a reserved bit
'//
'//      Facility - is the facility code
'//
'//      Code - is the facility's status code
'//
'//
'// Define the facility codes
'//


'//
'// Define the severity codes
'//


'//
'// MessageId: MQ_INFORMATION_PROPERTY
'//
'// MessageText:
'//
'//  One or more of the properties passed resulted in a warning, but the function completed.
'//
%MQ_INFORMATION_PROPERTY          = &H400E0001&

'//
'// MessageId: MQ_INFORMATION_ILLEGAL_PROPERTY
'//
'// MessageText:
'//
'//  The property ID is invalid.
'//
%MQ_INFORMATION_ILLEGAL_PROPERTY  = &H400E0002&

'//
'// MessageId: MQ_INFORMATION_PROPERTY_IGNORED
'//
'// MessageText:
'//
'//  The property specified was ignored for this operation (this occurs,
'//  for example, when PROPID_M_SENDERID is passed to SendMessage()).
'//
%MQ_INFORMATION_PROPERTY_IGNORED  = &H400E0003&

'//
'// MessageId: MQ_INFORMATION_UNSUPPORTED_PROPERTY
'//
'// MessageText:
'//
'//  The property specified is not supported and was ignored for this operation.
'//
%MQ_INFORMATION_UNSUPPORTED_PROPERTY = &H400E0004&

'//
'// MessageId: MQ_INFORMATION_DUPLICATE_PROPERTY
'//
'// MessageText:
'//
'//  The property specified is already in the property identifier array.
'//  The duplicate was ignored for this operation.
'//
%MQ_INFORMATION_DUPLICATE_PROPERTY = &H400E0005&

'//
'// MessageId: MQ_INFORMATION_OPERATION_PENDING
'//
'// MessageText:
'//
'//  An asynchronous operation is currently pending.
'//
%MQ_INFORMATION_OPERATION_PENDING = &H400E0006&

'//
'// MessageId: MQ_INFORMATION_FORMATNAME_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The format name buffer supplied to MQCreateQueue was too small
'//  to hold the format name, however the queue was created successfully.
'//
%MQ_INFORMATION_FORMATNAME_BUFFER_TOO_SMALL = &H400E0009&

'//
'// MessageId: MQ_INFORMATION_INTERNAL_USER_CERT_EXIST
'//
'// MessageText:
'//
'//  An internal Message Queuing certificate already exists for this user.
'//
%MQ_INFORMATION_INTERNAL_USER_CERT_EXIST = &H400E000A&

'//
'// MessageId: MQ_INFORMATION_OWNER_IGNORED
'//
'// MessageText:
'//
'//  The queue owner was not set during the processing of this call to MQSetQueueSecurity().
'//
%MQ_INFORMATION_OWNER_IGNORED     = &H400E000B&

'/////////////////////////////////////////////////////////////////////////
'//
'//  Message Queuing Error values
'//
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// MessageId: MQ_ERROR
'//
'// MessageText:
'//
'//  Generic error code.
'//
%MQ_ERROR                         = &HC00E0001&

'//
'// MessageId: MQ_ERROR_PROPERTY
'//
'// MessageText:
'//
'//  One or more of the properties passed are invalid.
'//
%MQ_ERROR_PROPERTY                = &HC00E0002&

'//
'// MessageId: MQ_ERROR_QUEUE_NOT_FOUND
'//
'// MessageText:
'//
'//  The queue does not exist or you do not have sufficient permissions to perform the operation.
'//
%MQ_ERROR_QUEUE_NOT_FOUND         = &HC00E0003&

'//
'// MessageId: MQ_ERROR_QUEUE_NOT_ACTIVE
'//
'// MessageText:
'//
'//  The queue is not open or may not exist.
'//
%MQ_ERROR_QUEUE_NOT_ACTIVE        = &HC00E0004&

'//
'// MessageId: MQ_ERROR_QUEUE_EXISTS
'//
'// MessageText:
'//
'//  A queue with the same path name already exists.
'//
%MQ_ERROR_QUEUE_EXISTS            = &HC00E0005&

'//
'// MessageId: MQ_ERROR_INVALID_PARAMETER
'//
'// MessageText:
'//
'//  An invalid parameter was passed to a function.
'//
%MQ_ERROR_INVALID_PARAMETER       = &HC00E0006&

'//
'// MessageId: MQ_ERROR_INVALID_HANDLE
'//
'// MessageText:
'//
'//  An invalid handle was passed to a function.
'//
%MQ_ERROR_INVALID_HANDLE          = &HC00E0007&

'//
'// MessageId: MQ_ERROR_OPERATION_CANCELLED
'//
'// MessageText:
'//
'//  The operation was canceled before it could be completed.
'//
%MQ_ERROR_OPERATION_CANCELLED     = &HC00E0008&

'//
'// MessageId: MQ_ERROR_SHARING_VIOLATION
'//
'// MessageText:
'//
'//  There is a sharing violation. The queue is already open for exclusive retrieval.
'//
%MQ_ERROR_SHARING_VIOLATION       = &HC00E0009&

'//
'// MessageId: MQ_ERROR_SERVICE_NOT_AVAILABLE
'//
'// MessageText:
'//
'//  The Message Queuing service is not available
'//
%MQ_ERROR_SERVICE_NOT_AVAILABLE   = &HC00E000B&

'//
'// MessageId: MQ_ERROR_MACHINE_NOT_FOUND
'//
'// MessageText:
'//
'//  The computer specified cannot be found.
'//
%MQ_ERROR_MACHINE_NOT_FOUND       = &HC00E000D&

'//
'// MessageId: MQ_ERROR_ILLEGAL_SORT
'//
'// MessageText:
'//
'//  The sort operation specified in MQLocateBegin is invalid (for example, there are duplicate columns).
'//
%MQ_ERROR_ILLEGAL_SORT            = &HC00E0010&

'//
'// MessageId: MQ_ERROR_ILLEGAL_USER
'//
'// MessageText:
'//
'//  The user specified is not a valid user.
'//
%MQ_ERROR_ILLEGAL_USER            = &HC00E0011&

'//
'// MessageId: MQ_ERROR_NO_DS
'//
'// MessageText:
'//
'//  A connection with Active Directory cannot be established. Verify that there are sufficient permissions to perform this operation.
'//
%MQ_ERROR_NO_DS                   = &HC00E0013&

'//
'// MessageId: MQ_ERROR_ILLEGAL_QUEUE_PATHNAME
'//
'// MessageText:
'//
'//  The queue path name specified is invalid.
'//
%MQ_ERROR_ILLEGAL_QUEUE_PATHNAME  = &HC00E0014&

'//
'// MessageId: MQ_ERROR_ILLEGAL_PROPERTY_VALUE
'//
'// MessageText:
'//
'//  The property value specified is invalid.
'//
%MQ_ERROR_ILLEGAL_PROPERTY_VALUE  = &HC00E0018&

'//
'// MessageId: MQ_ERROR_ILLEGAL_PROPERTY_VT
'//
'// MessageText:
'//
'//  The VARTYPE value specified is invalid.
'//
%MQ_ERROR_ILLEGAL_PROPERTY_VT     = &HC00E0019&

'//
'// MessageId: MQ_ERROR_BUFFER_OVERFLOW
'//
'// MessageText:
'//
'//  The buffer supplied to MQReceiveMessage for message property retrieval
'//  is too small. The message was not removed from the queue, but the part
'//  of the message property that was in the buffer was copied.
'//
%MQ_ERROR_BUFFER_OVERFLOW         = &HC00E001A&

'//
'// MessageId: MQ_ERROR_IO_TIMEOUT
'//
'// MessageText:
'//
'//  The time specified for MQReceiveMessage to wait for the message elapsed.
'//
%MQ_ERROR_IO_TIMEOUT              = &HC00E001B&

'//
'// MessageId: MQ_ERROR_ILLEGAL_CURSOR_ACTION
'//
'// MessageText:
'//
'//  The MQ_ACTION_PEEK_NEXT value specified for MQReceiveMessage cannot be used with
'//  the current cursor position.
'//
%MQ_ERROR_ILLEGAL_CURSOR_ACTION   = &HC00E001C&

'//
'// MessageId: MQ_ERROR_MESSAGE_ALREADY_RECEIVED
'//
'// MessageText:
'//
'//  The message at which the cursor is currently pointing was removed from
'//  the queue by another process or by another call to MQReceiveMessage
'//  without the use of this cursor.
'//
%MQ_ERROR_MESSAGE_ALREADY_RECEIVED = &HC00E001D&

'//
'// MessageId: MQ_ERROR_ILLEGAL_FORMATNAME
'//
'// MessageText:
'//
'//  The format name specified is invalid.
'//
%MQ_ERROR_ILLEGAL_FORMATNAME      = &HC00E001E&

'//
'// MessageId: MQ_ERROR_FORMATNAME_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The format name buffer supplied to the API was too small
'//  to hold the format name.
'//
%MQ_ERROR_FORMATNAME_BUFFER_TOO_SMALL = &HC00E001F&

'//
'// MessageId: MQ_ERROR_UNSUPPORTED_FORMATNAME_OPERATION
'//
'// MessageText:
'//
'//  Operations of the type requested (for example, deleting a queue using a direct format name)
'//  are not supported for the format name specified.
'//
%MQ_ERROR_UNSUPPORTED_FORMATNAME_OPERATION = &HC00E0020&

'//
'// MessageId: MQ_ERROR_ILLEGAL_SECURITY_DESCRIPTOR
'//
'// MessageText:
'//
'//  The specified security descriptor is invalid.
'//
%MQ_ERROR_ILLEGAL_SECURITY_DESCRIPTOR = &HC00E0021&

'//
'// MessageId: MQ_ERROR_SENDERID_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The size of the buffer for the user ID property is too small.
'//
%MQ_ERROR_SENDERID_BUFFER_TOO_SMALL = &HC00E0022&

'//
'// MessageId: MQ_ERROR_SECURITY_DESCRIPTOR_TOO_SMALL
'//
'// MessageText:
'//
'//  The size of the buffer passed to MQGetQueueSecurity is too small.
'//
%MQ_ERROR_SECURITY_DESCRIPTOR_TOO_SMALL = &HC00E0023&

'//
'// MessageId: MQ_ERROR_CANNOT_IMPERSONATE_CLIENT
'//
'// MessageText:
'//
'//  The security credentials cannot be verified because the RPC server
'//  cannot impersonate the client application.
'//
%MQ_ERROR_CANNOT_IMPERSONATE_CLIENT = &HC00E0024&

'//
'// MessageId: MQ_ERROR_ACCESS_DENIED
'//
'// MessageText:
'//
'//  Access is denied.
'//
%MQ_ERROR_ACCESS_DENIED           = &HC00E0025&

'//
'// MessageId: MQ_ERROR_PRIVILEGE_NOT_HELD
'//
'// MessageText:
'//
'//  The client does not have sufficient security privileges to perform the operation.
'//
%MQ_ERROR_PRIVILEGE_NOT_HELD      = &HC00E0026&

'//
'// MessageId: MQ_ERROR_INSUFFICIENT_RESOURCES
'//
'// MessageText:
'//
'//  There are insufficient resources to perform this operation.
'//
%MQ_ERROR_INSUFFICIENT_RESOURCES  = &HC00E0027&

'//
'// MessageId: MQ_ERROR_USER_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The request failed because the user buffer is too small to hold the information returned.
'//
%MQ_ERROR_USER_BUFFER_TOO_SMALL   = &HC00E0028&

'//
'// MessageId: MQ_ERROR_MESSAGE_STORAGE_FAILED
'//
'// MessageText:
'//
'//  A recoverable or journal message could not be stored. The message was not sent.
'//
%MQ_ERROR_MESSAGE_STORAGE_FAILED  = &HC00E002A&

'//
'// MessageId: MQ_ERROR_SENDER_CERT_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The buffer for the user certificate property is too small.
'//
%MQ_ERROR_SENDER_CERT_BUFFER_TOO_SMALL = &HC00E002B&

'//
'// MessageId: MQ_ERROR_INVALID_CERTIFICATE
'//
'// MessageText:
'//
'//  The user certificate is invalid.
'//
%MQ_ERROR_INVALID_CERTIFICATE     = &HC00E002C&

'//
'// MessageId: MQ_ERROR_CORRUPTED_INTERNAL_CERTIFICATE
'//
'// MessageText:
'//
'//  The internal Message Queuing certificate is corrupted.
'//
%MQ_ERROR_CORRUPTED_INTERNAL_CERTIFICATE = &HC00E002D&

'//
'// MessageId: MQ_ERROR_INTERNAL_USER_CERT_EXIST
'//
'// MessageText:
'//
'//  An internal Message Queuing certificate already exists for this user.
'//
%MQ_ERROR_INTERNAL_USER_CERT_EXIST = &HC00E002E&

'//
'// MessageId: MQ_ERROR_NO_INTERNAL_USER_CERT
'//
'// MessageText:
'//
'//  No internal Message Queuing certificate exists for the user.
'//
%MQ_ERROR_NO_INTERNAL_USER_CERT   = &HC00E002F&

'//
'// MessageId: MQ_ERROR_CORRUPTED_SECURITY_DATA
'//
'// MessageText:
'//
'//  A cryptographic function failed.
'//
%MQ_ERROR_CORRUPTED_SECURITY_DATA = &HC00E0030&

'//
'// MessageId: MQ_ERROR_CORRUPTED_PERSONAL_CERT_STORE
'//
'// MessageText:
'//
'//  The personal certificate store is corrupted.
'//
%MQ_ERROR_CORRUPTED_PERSONAL_CERT_STORE = &HC00E0031&

'//
'// MessageId: MQ_ERROR_COMPUTER_DOES_NOT_SUPPORT_ENCRYPTION
'//
'// MessageText:
'//
'//  The computer does not support encryption operations.
'//
%MQ_ERROR_COMPUTER_DOES_NOT_SUPPORT_ENCRYPTION = &HC00E0033&

'//
'// MessageId: MQ_ERROR_BAD_SECURITY_CONTEXT
'//
'// MessageText:
'//
'//  The security context is invalid.
'//
%MQ_ERROR_BAD_SECURITY_CONTEXT    = &HC00E0035&

'//
'// MessageId: MQ_ERROR_COULD_NOT_GET_USER_SID
'//
'// MessageText:
'//
'//  The SID cannot be obtained from the thread token.
'//
%MQ_ERROR_COULD_NOT_GET_USER_SID  = &HC00E0036&

'//
'// MessageId: MQ_ERROR_COULD_NOT_GET_ACCOUNT_INFO
'//
'// MessageText:
'//
'//  The account information for the user cannot be obtained.
'//
%MQ_ERROR_COULD_NOT_GET_ACCOUNT_INFO = &HC00E0037&

'//
'// MessageId: MQ_ERROR_ILLEGAL_MQCOLUMNS
'//
'// MessageText:
'//
'//  The MQCOLUMNS parameter is invalid.
'//
%MQ_ERROR_ILLEGAL_MQCOLUMNS       = &HC00E0038&

'//
'// MessageId: MQ_ERROR_ILLEGAL_PROPID
'//
'// MessageText:
'//
'//  A property identifier is invalid.
'//
%MQ_ERROR_ILLEGAL_PROPID          = &HC00E0039&

'//
'// MessageId: MQ_ERROR_ILLEGAL_RELATION
'//
'// MessageText:
'//
'//  A relationship parameter is invalid.
'//
%MQ_ERROR_ILLEGAL_RELATION        = &HC00E003A&

'//
'// MessageId: MQ_ERROR_ILLEGAL_PROPERTY_SIZE
'//
'// MessageText:
'//
'//  The size of the buffer for the message identifier or correlation identifier is invalid.
'//
%MQ_ERROR_ILLEGAL_PROPERTY_SIZE   = &HC00E003B&

'//
'// MessageId: MQ_ERROR_ILLEGAL_RESTRICTION_PROPID
'//
'// MessageText:
'//
'//  A property identifier specified in MQRESTRICTION is invalid.
'//
%MQ_ERROR_ILLEGAL_RESTRICTION_PROPID = &HC00E003C&

'//
'// MessageId: MQ_ERROR_ILLEGAL_MQQUEUEPROPS
'//
'// MessageText:
'//
'//  Either the pointer to the MQQUEUEPROPS structure has a null value, or no properties are specified in it.
'//
%MQ_ERROR_ILLEGAL_MQQUEUEPROPS    = &HC00E003D&

'//
'// MessageId: MQ_ERROR_PROPERTY_NOTALLOWED
'//
'// MessageText:
'//
'//  The property identifier specified (for example, PROPID_Q_INSTANCE in MQSetQueueProperties)
'//  is invalid for the operation requested.
'//
%MQ_ERROR_PROPERTY_NOTALLOWED     = &HC00E003E&

'//
'// MessageId: MQ_ERROR_INSUFFICIENT_PROPERTIES
'//
'// MessageText:
'//
'//  Not all the properties required for the operation were specified
'//  for the input parameters.
'//
%MQ_ERROR_INSUFFICIENT_PROPERTIES = &HC00E003F&

'//
'// MessageId: MQ_ERROR_MACHINE_EXISTS
'//
'// MessageText:
'//
'//  The MSMQ Configuration (msmq) object already exists in Active Directory.
'//
%MQ_ERROR_MACHINE_EXISTS          = &HC00E0040&

'//
'// MessageId: MQ_ERROR_ILLEGAL_MQQMPROPS
'//
'// MessageText:
'//
'//  Either the pointer to the MQQMROPS structure has a null value, or no properties are specified in it.
'//
%MQ_ERROR_ILLEGAL_MQQMPROPS       = &HC00E0041&

'//
'// MessageId: MQ_ERROR_DS_IS_FULL
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_DS_IS_FULL              = &HC00E0042&

'//
'// MessageId: MQ_ERROR_DS_ERROR
'//
'// MessageText:
'//
'//  There is an internal Active Directory error.
'//
%MQ_ERROR_DS_ERROR                = &HC00E0043&

'//
'// MessageId: MQ_ERROR_INVALID_OWNER
'//
'// MessageText:
'//
'//  The object owner is invalid (for example, MQCreateQueue failed because the QM
'//  object is invalid).
'//
%MQ_ERROR_INVALID_OWNER           = &HC00E0044&

'//
'// MessageId: MQ_ERROR_UNSUPPORTED_ACCESS_MODE
'//
'// MessageText:
'//
'//  The access mode specified is unsupported.
'//
%MQ_ERROR_UNSUPPORTED_ACCESS_MODE = &HC00E0045&

'//
'// MessageId: MQ_ERROR_RESULT_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The result buffer specified is too small.
'//
%MQ_ERROR_RESULT_BUFFER_TOO_SMALL = &HC00E0046&

'//
'// MessageId: MQ_ERROR_DELETE_CN_IN_USE
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_DELETE_CN_IN_USE        = &HC00E0048&

'//
'// MessageId: MQ_ERROR_NO_RESPONSE_FROM_OBJECT_SERVER
'//
'// MessageText:
'//
'//  There was no response from the object owner.
'//
%MQ_ERROR_NO_RESPONSE_FROM_OBJECT_SERVER = &HC00E0049&

'//
'// MessageId: MQ_ERROR_OBJECT_SERVER_NOT_AVAILABLE
'//
'// MessageText:
'//
'//  The object owner is not available.
'//
%MQ_ERROR_OBJECT_SERVER_NOT_AVAILABLE = &HC00E004A&

'//
'// MessageId: MQ_ERROR_QUEUE_NOT_AVAILABLE
'//
'// MessageText:
'//
'//  An error occurred while reading from a queue located on a remote computer.
'//
%MQ_ERROR_QUEUE_NOT_AVAILABLE     = &HC00E004B&

'//
'// MessageId: MQ_ERROR_DTC_CONNECT
'//
'// MessageText:
'//
'//  A connection cannot be established with the Distributed Transaction Coordinator.
'//
%MQ_ERROR_DTC_CONNECT             = &HC00E004C&

'//
'// MessageId: MQ_ERROR_TRANSACTION_IMPORT
'//
'// MessageText:
'//
'//  The transaction specified cannot be imported.
'//
%MQ_ERROR_TRANSACTION_IMPORT      = &HC00E004E&

'//
'// MessageId: MQ_ERROR_TRANSACTION_USAGE
'//
'// MessageText:
'//
'//  An attempted action cannot be performed within a transaction.
'//
%MQ_ERROR_TRANSACTION_USAGE       = &HC00E0050&

'//
'// MessageId: MQ_ERROR_TRANSACTION_SEQUENCE
'//
'// MessageText:
'//
'//  The transaction's operation sequence is incorrect.
'//
%MQ_ERROR_TRANSACTION_SEQUENCE    = &HC00E0051&

'//
'// MessageId: MQ_ERROR_MISSING_CONNECTOR_TYPE
'//
'// MessageText:
'//
'//  The connector type message property is not specified. This property is required for sending an acknowledgment message or a secure message.
'//
%MQ_ERROR_MISSING_CONNECTOR_TYPE  = &HC00E0055&

'//
'// MessageId: MQ_ERROR_STALE_HANDLE
'//
'// MessageText:
'//
'//  The Message Queuing service was restarted. Any open queue handles should be closed.
'//
%MQ_ERROR_STALE_HANDLE            = &HC00E0056&

'//
'// MessageId: MQ_ERROR_TRANSACTION_ENLIST
'//
'// MessageText:
'//
'//  The transaction specified cannot be enlisted.
'//
%MQ_ERROR_TRANSACTION_ENLIST      = &HC00E0058&

'//
'// MessageId: MQ_ERROR_QUEUE_DELETED
'//
'// MessageText:
'//
'//  The queue was deleted. Messages cannot be received anymore using this
'//  queue handle. The handle should be closed.
'//
%MQ_ERROR_QUEUE_DELETED           = &HC00E005A&

'//
'// MessageId: MQ_ERROR_ILLEGAL_CONTEXT
'//
'// MessageText:
'//
'//  The context parameter for MQLocateBegin is invalid.
'//
%MQ_ERROR_ILLEGAL_CONTEXT         = &HC00E005B&

'//
'// MessageId: MQ_ERROR_ILLEGAL_SORT_PROPID
'//
'// MessageText:
'//
'//  An invalid property identifier is specified in MQSORTSET.
'//
%MQ_ERROR_ILLEGAL_SORT_PROPID     = &HC00E005C&

'//
'// MessageId: MQ_ERROR_LABEL_TOO_LONG
'//
'// MessageText:
'//
'//  The message label is too long. Its length should be less than or equal to MQ_MAX_MSG_LABEL_LEN.
'//
%MQ_ERROR_LABEL_TOO_LONG          = &HC00E005D&

'//
'// MessageId: MQ_ERROR_LABEL_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The label buffer supplied to the API is too small.
'//
%MQ_ERROR_LABEL_BUFFER_TOO_SMALL  = &HC00E005E&

'//
'// MessageId: MQ_ERROR_MQIS_SERVER_EMPTY
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_MQIS_SERVER_EMPTY       = &HC00E005F&

'//
'// MessageId: MQ_ERROR_MQIS_READONLY_MODE
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_MQIS_READONLY_MODE      = &HC00E0060&

'//
'// MessageId: MQ_ERROR_SYMM_KEY_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The buffer passed for the symmetric key is too small.
'//
%MQ_ERROR_SYMM_KEY_BUFFER_TOO_SMALL = &HC00E0061&

'//
'// MessageId: MQ_ERROR_SIGNATURE_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The buffer passed for the signature property is too small.
'//
%MQ_ERROR_SIGNATURE_BUFFER_TOO_SMALL = &HC00E0062&

'//
'// MessageId: MQ_ERROR_PROV_NAME_BUFFER_TOO_SMALL
'//
'// MessageText:
'//
'//  The buffer passed for the provider name property is too small.
'//
%MQ_ERROR_PROV_NAME_BUFFER_TOO_SMALL = &HC00E0063&

'//
'// MessageId: MQ_ERROR_ILLEGAL_OPERATION
'//
'// MessageText:
'//
'//  The operation is invalid for a foreign message queuing system.
'//
%MQ_ERROR_ILLEGAL_OPERATION       = &HC00E0064&

'//
'// MessageId: MQ_ERROR_WRITE_NOT_ALLOWED
'//
'// MessageText:
'//
'//  Obsolete; another MQIS server is being installed. Write operations to the database are not allowed at this stage.
'//
%MQ_ERROR_WRITE_NOT_ALLOWED       = &HC00E0065&

'//
'// MessageId: MQ_ERROR_WKS_CANT_SERVE_CLIENT
'//
'// MessageText:
'//
'//  Independent clients cannot support dependent clients. A Message Queuing server is required.
'//
%MQ_ERROR_WKS_CANT_SERVE_CLIENT   = &HC00E0066&

'//
'// MessageId: MQ_ERROR_DEPEND_WKS_LICENSE_OVERFLOW
'//
'// MessageText:
'//
'//  The number of dependent clients served by the Message Queuing server reached its upper limit.
'//
%MQ_ERROR_DEPEND_WKS_LICENSE_OVERFLOW = &HC00E0067&

'//
'// MessageId: MQ_CORRUPTED_QUEUE_WAS_DELETED
'//
'// MessageText:
'//
'//  The file %1 for the queue %2 in the Lqs folder was deleted because it was corrupted.
'//
%MQ_CORRUPTED_QUEUE_WAS_DELETED   = &HC00E0068&

'//
'// MessageId: MQ_ERROR_REMOTE_MACHINE_NOT_AVAILABLE
'//
'// MessageText:
'//
'//  The remote computer is not available.
'//
%MQ_ERROR_REMOTE_MACHINE_NOT_AVAILABLE = &HC00E0069&

'//
'// MessageId: MQ_ERROR_UNSUPPORTED_OPERATION
'//
'// MessageText:
'//
'// This operation is not supported for Message Queuing installed in workgroup mode.
'//
%MQ_ERROR_UNSUPPORTED_OPERATION   = &HC00E006A&

'//
'// MessageId: MQ_ERROR_ENCRYPTION_PROVIDER_NOT_SUPPORTED
'//
'// MessageText:
'//
'//  The cryptographic service provider %1 is not supported by Message Queuing.
'//
%MQ_ERROR_ENCRYPTION_PROVIDER_NOT_SUPPORTED = &HC00E006B&

'//
'// MessageId: MQ_ERROR_CANNOT_SET_CRYPTO_SEC_DESCR
'//
'// MessageText:
'//
'//  The security descriptors for the cryptographic keys cannot be set.
'//
%MQ_ERROR_CANNOT_SET_CRYPTO_SEC_DESCR = &HC00E006C&

'//
'// MessageId: MQ_ERROR_CERTIFICATE_NOT_PROVIDED
'//
'// MessageText:
'//
'//  A user attempted to send an authenticated message without a certificate.
'//
%MQ_ERROR_CERTIFICATE_NOT_PROVIDED = &HC00E006D&

'//
'// MessageId: MQ_ERROR_Q_DNS_PROPERTY_NOT_SUPPORTED
'//
'// MessageText:
'//
'//  The column PROPID_Q_PATHNAME_DNS is not supported for the MQLocateBegin API.
'//
%MQ_ERROR_Q_DNS_PROPERTY_NOT_SUPPORTED = &HC00E006E&

'//
'// MessageId: MQ_ERROR_CANNOT_CREATE_CERT_STORE
'//
'// MessageText:
'//
'//  A certificate store cannot be created for the internal certificate.
'//
%MQ_ERROR_CANNOT_CREATE_CERT_STORE = &HC00E006F&

'//
'// MessageId: MQ_ERROR_CANNOT_OPEN_CERT_STORE
'//
'// MessageText:
'//
'//  The certificate store for the internal certificate cannot be opened.
'//
%MQ_ERROR_CANNOT_OPEN_CERT_STORE  = &HC00E0070&

'//
'// MessageId: MQ_ERROR_ILLEGAL_ENTERPRISE_OPERATION
'//
'// MessageText:
'//
'//  This operation is invalid for an MsmqServices object.
'//
%MQ_ERROR_ILLEGAL_ENTERPRISE_OPERATION = &HC00E0071&

'//
'// MessageId: MQ_ERROR_CANNOT_GRANT_ADD_GUID
'//
'// MessageText:
'//
'//  The Add GUID permission cannot be granted to the current user.
'//
%MQ_ERROR_CANNOT_GRANT_ADD_GUID   = &HC00E0072&

'//
'// MessageId: MQ_ERROR_CANNOT_LOAD_MSMQOCM
'//
'// MessageText:
'//
'//  Obsolete: The dynamic-link library Msmqocm.dll cannot be loaded.
'//
%MQ_ERROR_CANNOT_LOAD_MSMQOCM     = &HC00E0073&

'//
'// MessageId: MQ_ERROR_NO_ENTRY_POINT_MSMQOCM
'//
'// MessageText:
'//
'//  An entry point cannot be located in Msmqocm.dll.
'//
%MQ_ERROR_NO_ENTRY_POINT_MSMQOCM  = &HC00E0074&

'//
'// MessageId: MQ_ERROR_NO_MSMQ_SERVERS_ON_DC
'//
'// MessageText:
'//
'//  Message Queuing servers cannot be found on domain controllers.
'//
%MQ_ERROR_NO_MSMQ_SERVERS_ON_DC   = &HC00E0075&

'//
'// MessageId: MQ_ERROR_CANNOT_JOIN_DOMAIN
'//
'// MessageText:
'//
'//  The computer joined the domain, but Message Queuing will continue to run in workgroup mode because it failed to register itself in Active Directory.
'//
%MQ_ERROR_CANNOT_JOIN_DOMAIN      = &HC00E0076&

'//
'// MessageId: MQ_ERROR_CANNOT_CREATE_ON_GC
'//
'// MessageText:
'//
'//  The object was not created on the Global Catalog server specified.
'//
%MQ_ERROR_CANNOT_CREATE_ON_GC     = &HC00E0077&

'//
'// MessageId: MQ_ERROR_GUID_NOT_MATCHING
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_GUID_NOT_MATCHING       = &HC00E0078&

'//
'// MessageId: MQ_ERROR_PUBLIC_KEY_NOT_FOUND
'//
'// MessageText:
'//
'//  The public key for the computer %1 cannot be found.
'//
%MQ_ERROR_PUBLIC_KEY_NOT_FOUND    = &HC00E0079&

'//
'// MessageId: MQ_ERROR_PUBLIC_KEY_DOES_NOT_EXIST
'//
'// MessageText:
'//
'//  The public key for the computer %1 does not exist.
'//
%MQ_ERROR_PUBLIC_KEY_DOES_NOT_EXIST = &HC00E007A&

'//
'// MessageId: MQ_ERROR_ILLEGAL_MQPRIVATEPROPS
'//
'// MessageText:
'//
'//  The parameters in MQPRIVATEPROPS are invalid. Either the pointer to the MQPRIVATEPROPS structure has a null value, or no properties are specified in it.
'//
%MQ_ERROR_ILLEGAL_MQPRIVATEPROPS  = &HC00E007B&

'//
'// MessageId: MQ_ERROR_NO_GC_IN_DOMAIN
'//
'// MessageText:
'//
'//  Global Catalog servers cannot be found in the domain specified.
'//
%MQ_ERROR_NO_GC_IN_DOMAIN         = &HC00E007C&

'//
'// MessageId: MQ_ERROR_NO_MSMQ_SERVERS_ON_GC
'//
'// MessageText:
'//
'//  No Message Queuing servers were found on Global Catalog servers.
'//
%MQ_ERROR_NO_MSMQ_SERVERS_ON_GC   = &HC00E007D&

'//
'// MessageId: MQ_ERROR_CANNOT_GET_DN
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_CANNOT_GET_DN           = &HC00E007E&

'//
'// MessageId: MQ_ERROR_CANNOT_HASH_DATA_EX
'//
'// MessageText:
'//
'//  Data for an authenticated message cannot be hashed.
'//
%MQ_ERROR_CANNOT_HASH_DATA_EX     = &HC00E007F&

'//
'// MessageId: MQ_ERROR_CANNOT_SIGN_DATA_EX
'//
'// MessageText:
'//
'//  Data cannot be signed before sending an authenticated message.
'//
%MQ_ERROR_CANNOT_SIGN_DATA_EX     = &HC00E0080&

'//
'// MessageId: MQ_ERROR_CANNOT_CREATE_HASH_EX
'//
'// MessageText:
'//
'//  A hash object cannot be created for an authenticated message.
'//
%MQ_ERROR_CANNOT_CREATE_HASH_EX   = &HC00E0081&

'//
'// MessageId: MQ_ERROR_FAIL_VERIFY_SIGNATURE_EX
'//
'// MessageText:
'//
'//  The signature of the message received is not valid.
'//
%MQ_ERROR_FAIL_VERIFY_SIGNATURE_EX = &HC00E0082&

'//
'// MessageId: MQ_ERROR_CANNOT_DELETE_PSC_OBJECTS
'//
'// MessageText:
'//
'//  The object that will be deleted is owned by a primary site controller. The operation cannot be performed.
'//
%MQ_ERROR_CANNOT_DELETE_PSC_OBJECTS = &HC00E0083&

'//
'// MessageId: MQ_ERROR_NO_MQUSER_OU
'//
'// MessageText:
'//
'//  There is no MSMQ Users organizational unit object in Active Directory for the domain. Please create one manually.
'//
%MQ_ERROR_NO_MQUSER_OU            = &HC00E0084&

'//
'// MessageId: MQ_ERROR_CANNOT_LOAD_MQAD
'//
'// MessageText:
'//
'//  The dynamic-link library Mqad.dll cannot be loaded.
'//
%MQ_ERROR_CANNOT_LOAD_MQAD        = &HC00E0085&

'//
'// MessageId: MQ_ERROR_CANNOT_LOAD_MQDSSRV
'//
'// MessageText:
'//
'//  Obsolete, kept for backward compatibility
'//
%MQ_ERROR_CANNOT_LOAD_MQDSSRV     = &HC00E0086&

'//
'// MessageId: MQ_ERROR_PROPERTIES_CONFLICT
'//
'// MessageText:
'//
'//  Two or more of the properties passed cannot co-exist.
'//  For example, you cannot set both PROPID_M_RESP_QUEUE and PROPID_M_RESP_FORMAT_NAME when sending a message.
'//
%MQ_ERROR_PROPERTIES_CONFLICT     = &HC00E0087&

'//
'// MessageId: MQ_ERROR_MESSAGE_NOT_FOUND
'//
'// MessageText:
'//
'//  The message does not exist or was removed from the queue.
'//
%MQ_ERROR_MESSAGE_NOT_FOUND       = &HC00E0088&

'//
'// MessageId: MQ_ERROR_CANT_RESOLVE_SITES
'//
'// MessageText:
'//
'//  The sites where the computer resides cannot be resolved. Check that the subnets in your network are configured correctly in Active Directory and that each site is configured with the appropriate subnet.
'//
%MQ_ERROR_CANT_RESOLVE_SITES      = &HC00E0089&

'//
'// MessageId: MQ_ERROR_NOT_SUPPORTED_BY_DEPENDENT_CLIENTS
'//
'// MessageText:
'//
'//  This operation is not supported by dependent clients.
'//
%MQ_ERROR_NOT_SUPPORTED_BY_DEPENDENT_CLIENTS = &HC00E008A&

'//
'// MessageId: MQ_ERROR_OPERATION_NOT_SUPPORTED_BY_REMOTE_COMPUTER
'//
'// MessageText:
'//
'//  This operation is not supported by the remote Message Queuing service. For example, MQReceiveMessageByLookupId is not supported by MSMQ 1.0/2.0.
'//
%MQ_ERROR_OPERATION_NOT_SUPPORTED_BY_REMOTE_COMPUTER = &HC00E008B&

'//
'// MessageId: MQ_ERROR_NOT_A_CORRECT_OBJECT_CLASS
'//
'// MessageText:
'//
'//  The object whose properties are being retrieved from Active Directory does not belong to the class requested.
'//
%MQ_ERROR_NOT_A_CORRECT_OBJECT_CLASS = &HC00E008C&

'//
'// MessageId: MQ_ERROR_MULTI_SORT_KEYS
'//
'// MessageText:
'//
'//  The value of cCol in MQSORTSET cannot be greater than 1. Active Directory supports only a single sort key.
'//
%MQ_ERROR_MULTI_SORT_KEYS         = &HC00E008D&

'//
'// MessageId: MQ_ERROR_GC_NEEDED
'//
'// MessageText:
'//
'//  An MSMQ Configuration (msmq) object with the GUID supplied cannot be created. By default, a Windows Server 2003 forest does not support adding an object with a supplied GUID.
'//
%MQ_ERROR_GC_NEEDED               = &HC00E008E&

'//
'// MessageId: MQ_ERROR_DS_BIND_ROOT_FOREST
'//
'// MessageText:
'//
'//  Binding to the forest root failed. This error usually indicates a problem in the DNS configuration.
'//
%MQ_ERROR_DS_BIND_ROOT_FOREST     = &HC00E008F&

'//
'// MessageId: MQ_ERROR_DS_LOCAL_USER
'//
'// MessageText:
'//
'//  A local user is authenticated as an anonymous user and cannot access Active Directory. You need to log on as a domain user to access Active Directory.
'//
%MQ_ERROR_DS_LOCAL_USER           = &HC00E0090&

'//
'// MessageId: MQ_ERROR_Q_ADS_PROPERTY_NOT_SUPPORTED
'//
'// MessageText:
'//
'//  The column PROPID_Q_ADS_PATH is not supported for the MQLocateBegin API.
'//
%MQ_ERROR_Q_ADS_PROPERTY_NOT_SUPPORTED = &HC00E0091&

'//
'// MessageId: MQ_ERROR_BAD_XML_FORMAT
'//
'// MessageText:
'//
'//  The given property is not a valid XML document.
'//
%MQ_ERROR_BAD_XML_FORMAT          = &HC00E0092&

'//
'// MessageId: MQ_ERROR_UNSUPPORTED_CLASS
'//
'// MessageText:
'//
'//  The Active Directory object specified is not an instance of a supported class.
'//
%MQ_ERROR_UNSUPPORTED_CLASS       = &HC00E0093&

'//
'// MessageId: MQ_ERROR_UNINITIALIZED_OBJECT
'//
'// MessageText:
'//
'//  The MSMQManagement object must be initialized before it is used.
'//
%MQ_ERROR_UNINITIALIZED_OBJECT    = &HC00E0094&

'//
'// MessageId: MQ_ERROR_CANNOT_CREATE_PSC_OBJECTS
'//
'// MessageText:
'//
'//  The object that will be created should be owned by a primary site controller. The operation cannot be performed.
'//
%MQ_ERROR_CANNOT_CREATE_PSC_OBJECTS = &HC00E0095&

'//
'// MessageId: MQ_ERROR_CANNOT_UPDATE_PSC_OBJECTS
'//
'// MessageText:
'//
'//  The object that will be updated is owned by a primary site controller. The operation cannot be performed.
'//
%MQ_ERROR_CANNOT_UPDATE_PSC_OBJECTS = &HC00E0096&

'//
'// MessageId: MQ_ERROR_RESOLVE_ADDRESS
'//
'// MessageText:
'//
'// Message Queuing is not able to resolve the address specfied by the user. The address may be wrong or DNS look-up for address failed.
'//
%MQ_ERROR_RESOLVE_ADDRESS = &HC00E0099&

'//
'// MessageId: MQ_ERROR_TOO_MANY_PROPERTIES
'//
'// MessageText:
'//
'// Too many properties passed to the function. Message Queuing can process up to 128 properties in one call.
'//
%MQ_ERROR_TOO_MANY_PROPERTIES = &HC00E009A&

'//
'// MessageId: MQ_ERROR_MESSAGE_NOT_AUTHENTICATED
'//
'// MessageText:
'//
'// The queue only accepts authenticated messages.
'//
%MQ_ERROR_MESSAGE_NOT_AUTHENTICATED = &HC00E009B&

'//
'// MessageId: MQ_ERROR_MESSAGE_LOCKED_UNDER_TRANSACTION
'//
'// MessageText:
'//
'// The message is currently being processed under a transaction. Till the transaction outcome is determined, the message cannot be processed in any other transaction.
'//
%MQ_ERROR_MESSAGE_LOCKED_UNDER_TRANSACTION = &HC00E009C&


'//********************************************************************
'//  RECEIVE CALLBACK
'//********************************************************************

'typedef
'VOID
'(APIENTRY *PMQRECEIVECALLBACK)(
'    HRESULT hrStatus,
'    QUEUEHANDLE hSource,
'    DWORD dwTimeout,
'    DWORD dwAction,
'    MQMSGPROPS* pMessageProps,
'    LPOVERLAPPED lpOverlapped,
'    HANDLE hCursor
'    );

'SUB QRECEIVECALLBACK ( _
'   BYVAL DWORD _                              ' HRESULT hrStatus
' , BYVAL DWORD _                              ' QUEUEHANDLE hSource
' , BYVAL DWORD _                              ' DWORD dwTimeout
' , BYVAL DWORD _                              ' DWORD dwAction
' , BYREF MQMSGPROPS _                         ' MQMSGPROPS* pMessageProps
' , BYREF OVERLAPPED _                         ' LPOVERLAPPED lpOverlapped
' , BYVAL DWORD _                              ' HANDLE hCursor
')


'//********************************************************************
'// MSMQ API
'//********************************************************************

DECLARE FUNCTION MQCreateQueue IMPORT "MQRT.DLL" ALIAS "MQCreateQueue" ( _
   BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYREF pQueueProps AS MQQUEUEPROPS _                   ' __in_out MQQUEUEPROPS* pQueueProps
 , BYREF lpwcsFormatName AS WSTRINGZ _                   ' __out LPWSTR lpwcsFormatName
 , BYREF lpdwFormatNameLength AS DWORD _                 ' __in_out LPDWORD lpdwFormatNameLength
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQDeleteQueue IMPORT "MQRT.DLL" ALIAS "MQDeleteQueue" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQLocateBegin IMPORT "MQRT.DLL" ALIAS "MQLocateBegin" ( _
   BYREF lpwcsContext AS WSTRINGZ _                      ' __in LPCWSTR lpwcsContext
 , BYREF pRestriction AS MQRESTRICTION _                 ' __in MQRESTRICTION* pRestriction
 , BYREF pColumns AS MQCOLUMNSET _                       ' __in MQCOLUMNSET* pColumns
 , BYREF pSort AS MQSORTSET _                            ' __in MQSORTSET* pSort
 , BYREF phEnum AS DWORD _                               ' __out PHANDLE phEnum
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQLocateNext IMPORT "MQRT.DLL" ALIAS "MQLocateNext" ( _
   BYVAL hEnum AS DWORD _                                ' __in HANDLE hEnum
 , BYREF pcProps AS DWORD _                              ' __in_out DWORD* pcProps
 , BYREF aPropVar AS MQPROPVARIANT _                     ' __out MQPROPVARIANT aPropVar[]
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQLocateEnd IMPORT "MQRT.DLL" ALIAS "MQLocateEnd" ( _
   BYVAL hEnum AS DWORD _                                ' __in HANDLE hEnum
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQOpenQueue IMPORT "MQRT.DLL" ALIAS "MQOpenQueue" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 , BYVAL dwAccess AS DWORD _                             ' __in DWORD dwAccess
 , BYVAL dwShareMode AS DWORD _                          ' __in DWORD dwShareMode
 , BYREF phQueue AS DWORD _                              ' __out QUEUEHANDLE* phQueue
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQSendMessage IMPORT "MQRT.DLL" ALIAS "MQSendMessage" ( _
   BYVAL phQueue AS DWORD _                              ' __in QUEUEHANDLE hDestinationQueue
 , BYREF pMessageProps AS MQMSGPROPS _                   ' __in MQMSGPROPS* pMessageProps
 , BYVAL pTransaction AS ITransaction _                  ' __in ITransaction *pTransaction
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQReceiveMessage IMPORT "MQRT.DLL" ALIAS "MQReceiveMessage" ( _
   BYVAL hSource AS DWORD _                              ' __in QUEUEHANDLE hSource
 , BYVAL dwTimeout AS DWORD _                            ' __in DWORD dwTimeout
 , BYVAL dwAction AS DWORD _                             ' __in DWORD dwAction
 , BYREF pMessageProps AS MQMSGPROPS _                   ' __in_out MQMSGPROPS* pMessageProps
 , BYREF lpOverlapped AS OVERLAPPED _                    ' __in_out LPOVERLAPPED lpOverlapped
 , BYVAL fnReceiveCallback AS DWORD _                    ' __in PMQRECEIVECALLBACK fnReceiveCallback
 , BYVAL hCursor AS DWORD _                              ' __in HANDLE hCursor
 , BYVAL pTransaction AS ITransaction _                  ' __in ITransaction* pTransaction
 ) AS LONG                                               ' HRESULT

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION MQReceiveMessageByLookupId IMPORT "MQRT.DLL" ALIAS "MQReceiveMessageByLookupId" ( _
   BYVAL hSource AS DWORD _                              ' __in QUEUEHANDLE hSource
 , BYVAL ullLookupId AS QUAD _                           ' __in ULONGLONG ullLookupId
 , BYVAL dwLookupAction AS DWORD _                       ' __in DWORD dwLookupAction
 , BYREF pMessageProps AS MQMSGPROPS _                   ' __in_out MQMSGPROPS* pMessageProps
 , BYREF lpOverlapped AS OVERLAPPED _                    ' __in_out LPOVERLAPPED lpOverlapped
 , BYVAL fnReceiveCallback AS DWORD _                    ' __in PMQRECEIVECALLBACK fnReceiveCallback
 , BYVAL pTransaction AS ITransaction _                  ' __in ITransaction *pTransaction
 ) AS LONG                                               ' HRESULT

'#endif

DECLARE FUNCTION MQCreateCursor IMPORT "MQRT.DLL" ALIAS "MQCreateCursor" ( _
   BYVAL hQueue AS DWORD _                               ' __in QUEUEHANDLE hQueue
 , BYREF phCursor AS DWORD _                             ' __out PHANDLE phCursor
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQCloseCursor IMPORT "MQRT.DLL" ALIAS "MQCloseCursor" ( _
   BYVAL hCursor AS DWORD _                              ' __in HANDLE hCursor
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQCloseQueue IMPORT "MQRT.DLL" ALIAS "MQCloseQueue" ( _
   BYVAL hQueue AS DWORD _                               ' __in QUEUEHANDLE hQueue
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQSetQueueProperties IMPORT "MQRT.DLL" ALIAS "MQSetQueueProperties" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 , BYREF pQueueProps AS MQQUEUEPROPS _                   ' __in MQQUEUEPROPS* pQueueProps
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetQueueProperties IMPORT "MQRT.DLL" ALIAS "MQGetQueueProperties" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 , BYREF pQueueProps AS MQQUEUEPROPS _                   ' __out MQQUEUEPROPS* pQueueProps
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetQueueSecurity IMPORT "MQRT.DLL" ALIAS "MQGetQueueSecurity" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 , BYVAL RequestedInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION RequestedInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __out PSECURITY_DESCRIPTOR pSecurityDescriptor
 , BYVAL nLength AS DWORD _                              ' __in DWORD nLength
 , BYREF lpnLengthNeeded AS DWORD _                      ' __out LPDWORD lpnLengthNeeded
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQSetQueueSecurity IMPORT "MQRT.DLL" ALIAS "MQSetQueueSecurity" ( _
   BYREF lpwcsFormatName AS WSTRINGZ _                   ' __in LPCWSTR lpwcsFormatName
 , BYVAL RequestedInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION RequestedInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQPathNameToFormatName IMPORT "MQRT.DLL" ALIAS "MQPathNameToFormatName" ( _
   BYREF lpwcsPathName AS WSTRINGZ _                     ' __in LPCWSTR lpwcsPathName
 , BYREF lpwcsFormatName AS WSTRINGZ _                   ' __out LPWSTR lpwcsFormatName
 , BYREF lpdwFormatNameLength AS DWORD _                 ' __in_out LPDWORD lpdwFormatNameLength
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQHandleToFormatName IMPORT "MQRT.DLL" ALIAS "MQHandleToFormatName" ( _
   BYVAL hQueue AS DWORD _                               ' __in QUEUEHANDLE hQueue
 , BYREF lpwcsFormatName AS WSTRINGZ _                   ' __out LPWSTR lpwcsFormatName
 , BYREF lpdwFormatNameLength AS DWORD _                 ' __in_out LPDWORD lpdwFormatNameLength
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQInstanceToFormatName IMPORT "MQRT.DLL" ALIAS "MQInstanceToFormatName" ( _
   BYREF pGuid AS GUID _                                 ' __in GUID* pGuid
 , BYREF lpwcsFormatName AS WSTRINGZ _                   ' __out LPWSTR lpwcsFormatName
 , BYREF lpdwFormatNameLength AS DWORD _                 ' __in_out LPDWORD lpdwFormatNameLength
 ) AS LONG                                               ' HRESULT

'#if(_WIN32_WINNT >= 0x0501)

DECLARE FUNCTION MQADsPathToFormatName IMPORT "MQRT.DLL" ALIAS "MQADsPathToFormatName" ( _
   BYREF lpwcsADsPath AS WSTRINGZ _                      ' __in LPCWSTR lpwcsADsPath
 , BYREF lpwcsFormatName AS WSTRINGZ _                   ' __out LPWSTR lpwcsFormatName
 , BYREF lpdwFormatNameLength AS DWORD _                 ' __in_out LPDWORD lpdwFormatNameLength
 ) AS LONG                                               ' HRESULT

'#endif

DECLARE SUB MQFreeMemory IMPORT "MQRT.DLL" ALIAS "MQFreeMemory" ( _
   BYVAL pvMemory AS DWORD _                            ' __in PVOID pvMemory
 )                                                      ' void

DECLARE FUNCTION MQGetMachineProperties IMPORT "MQRT.DLL" ALIAS "MQGetMachineProperties" ( _
   BYREF lpwcsMachineName AS WSTRINGZ _                  ' __in LPCWSTR lpwcsMachineName
 , BYREF pguidMachineId AS GUID _                        ' __in const GUID* pguidMachineId
 , BYREF pQMProps AS MQQMPROPS _                         ' __in_out MQQMPROPS* pQMProps
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetSecurityContext IMPORT "MQRT.DLL" ALIAS "MQGetSecurityContext" ( _
   BYVAL lpCertBuffer AS DWORD _                         ' __in PVOID lpCertBuffer
 , BYVAL dwCertBufferLength AS DWORD _                   ' __in DWORD dwCertBufferLength
 , BYREF phSecurityContext AS DWORD _                    ' __out HANDLE* phSecurityContext
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetSecurityContextEx IMPORT "MQRT.DLL" ALIAS "MQGetSecurityContextEx" ( _
   BYVAL lpCertBuffer AS DWORD _                         ' __in PVOID lpCertBuffer
 , BYVAL dwCertBufferLength AS DWORD _                   ' __in DWORD dwCertBufferLength
 , BYREF phSecurityContext AS DWORD _                    ' __out HANDLE* phSecurityContext
 ) AS LONG                                               ' HRESULT

DECLARE SUB MQFreeSecurityContext IMPORT "MQRT.DLL" ALIAS "MQFreeSecurityContext" ( _
   BYVAL hSecurityContext AS DWORD _                    ' __in HANDLE hSecurityContext
 )                                                      ' void

DECLARE FUNCTION MQRegisterCertificate IMPORT "MQRT.DLL" ALIAS "MQRegisterCertificate" ( _
   BYVAL dwFlags AS DWORD _                              ' __in DWORD dwFlags
 , BYVAL lpCertBuffer AS DWORD _                         ' __in PVOID lpCertBuffer
 , BYVAL dwCertBufferLength AS DWORD _                   ' __in DWORD dwCertBufferLength
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQBeginTransaction IMPORT "MQRT.DLL" ALIAS "MQBeginTransaction" ( _
   BYREF ppTransaction AS ITransaction _                 ' __out ITransaction **ppTransaction
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetOverlappedResult IMPORT "MQRT.DLL" ALIAS "MQGetOverlappedResult" ( _
   BYREF lpOverlapped AS OVERLAPPED _                    ' __in LPOVERLAPPED lpOverlapped
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQGetPrivateComputerInformation IMPORT "MQRT.DLL" ALIAS "MQGetPrivateComputerInformation" ( _
   BYREF lpwcsComputerName AS WSTRINGZ _                 ' __in LPCWSTR lpwcsComputerName
 , BYREF pPrivateProps AS MQPRIVATEPROPS _               ' __in_out MQPRIVATEPROPS* pPrivateProps
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQPurgeQueue IMPORT "MQRT.DLL" ALIAS "MQPurgeQueue" ( _
   BYVAL hQueue AS DWORD _                               ' __in QUEUEHANDLE hQueue
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQMgmtGetInfo IMPORT "MQRT.DLL" ALIAS "MQMgmtGetInfo" ( _
   BYREF pComputerName AS WSTRINGZ _                     ' __in LPCWSTR pComputerName
 , BYREF pObjectName AS WSTRINGZ _                       ' __in LPCWSTR pObjectName
 , BYREF pMgmtProps AS MQMGMTPROPS _                     ' __in_out MQMGMTPROPS* pMgmtProps
 ) AS LONG                                               ' HRESULT

DECLARE FUNCTION MQMgmtAction IMPORT "MQRT.DLL" ALIAS "MQMgmtAction" ( _
   BYREF pComputerName AS WSTRINGZ _                     ' __in LPCWSTR pComputerName
 , BYREF pObjectName AS WSTRINGZ _                       ' __in LPCWSTR pObjectName
 , BYREF pAction AS WSTRINGZ _                           ' __in LPCWSTR pAction
 ) AS LONG                                               ' HRESULT

' Requires Windows Vista
DECLARE FUNCTION MQMarkMessageRejected IMPORT "MQOA.DLL" ALIAS "MQMarkMessageRejected" ( _
   BYVAL hQueue AS DWORD _                               ' __in HANDLE hQueue
 , BYVAL ullLookupId AS QUAD _                           ' __in ULONGLONG ullLookupId
 ) AS LONG                                               ' HRESULT

' Requires Windows Vista
DECLARE FUNCTION MQMoveMessage IMPORT "MQOA.DLL" ALIAS "MQMoveMessage" ( _
   BYVAL hSourceQueue AS DWORD _                         ' __in QUEUEHANDLE hSourceQueue
 , BYVAL hDestinationQueue AS DWORD _                    ' __in QUEUEHANDLE hDestinationQueue
 , BYVAL ullLookupId AS QUAD _                           ' __in ULONGLONG ullLookupId
 , BYVAL pTransaction AS ITransaction _                  ' __in_opt ITransaction *pTransaction
 ) AS LONG                                               ' HRESULT
