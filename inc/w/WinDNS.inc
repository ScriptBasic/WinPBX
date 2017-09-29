' ########################################################################################
' Microsoft Windows
' File: WinDns.inc
' Contents: Domain Name System (DNS) API
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINDNS_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'//  Define QWORD -- not yet defined globally
'//

'typedef unsigned __int64 QWORD, *PQWORD;

'//
'//  DNS public types
'//

'typedef __success(return == 0) LONG    DNS_STATUS;
'typedef DNS_STATUS                    *PDNS_STATUS;

'//
'//  IP Address
'//

'typedef DWORD   IP4_ADDRESS, *PIP4_ADDRESS;

%SIZEOF_IP4_ADDRESS                  = 4
%IP4_ADDRESS_STRING_LENGTH           = 16

'//  Backcompat only -- length def contains terminating NULL

%IP4_ADDRESS_STRING_BUFFER_LENGTH    = 16


'//
'//  IP Address Array type
'//

'typedef struct  _IP4_ARRAY
'{
'    DWORD           AddrCount;
'#ifdef MIDL_PASS
'    [size_is( AddrCount )]  IP4_ADDRESS  AddrArray[];
'#else
'    IP4_ADDRESS     AddrArray[1];
'#endif
'}
'IP4_ARRAY, *PIP4_ARRAY;

' // Size = 8 bytes
TYPE IP4_ARRAY
   AddrCount    AS DWORD
   AddrArray(0) AS DWORD
END TYPE

'//
'//  IPv6 Address
'//

'#ifdef MIDL_PASS

'#ifdef _WIN64
'#pragma pack(push, 8)
'#else
'#pragma pack(push, 4)
'#endif

'typedef struct
'{
'    QWORD       IP6Qword[2];
'}
'IP6_ADDRESS, *PIP6_ADDRESS;

'#pragma pack(pop)

'#else // MIDL_PASS

'typedef union
'{
'#ifdef _WIN64
'    QWORD       IP6Qword[2];
'#endif
'    DWORD       IP6Dword[4];
'    WORD        IP6Word[8];
'    BYTE        IP6Byte[16];
'#ifdef  IN6_ADDR
'    IN6_ADDR    In6;
'#endif
'}
'IP6_ADDRESS, *PIP6_ADDRESS;

'#endif // MIDL_PASS

' // Size = 16 bytes
UNION IP6_ADDRESS BYTE
   IP6Dword(3) AS DWORD
   IP6Word(7)  AS WORD
   IP6Byte(15) AS BYTE
END UNION

'//
'//  IP6 string max is 45 bytes
'//      - 6 WORDs in colon+hex (5 chars)
'//      - last DWORD as IP4 (15 chars)
'//  but include
'//      - 11 bytes for scope ID
'//      - 6 bytes for port (inc. colon)
'//      - two bytes to bracket address with port
'//      - terminating NULL
'//
'//  Note:  this is a change to previous def, but a single
'//      definition continaing space for ALL possible IPv6
'//      address strings, we elminate many possible errors

%IP6_ADDRESS_STRING_LENGTH           = 65
%IP6_ADDRESS_STRING_BUFFER_LENGTH    = 65

'//
'//  IP4/IP6 combined maximum
'//

%DNS_ADDRESS_STRING_LENGTH           = %IP6_ADDRESS_STRING_LENGTH

'//
'//  Inline byte flipping -- can be done in registers
'//

'#define INLINE_WORD_FLIP(out, in)   \
'        {                           \
'            WORD _in = (in);        \
'            (out) = (_in << 8) | (_in >> 8);  \
'        }

SUB INLINE_WORD_FLIP (BYREF wOut AS WORD, BYVAL wIn AS WORD)
   LOCAL wTmp1, wTmp2 AS WORD
   wTmp1 = wIn
   wTmp2 = wIn
   SHIFT LEFT wTmp1, 8
   SHIFT RIGHT wTmp2, 8
   wOut = wTmp1 OR wTmp2
END SUB

'#define INLINE_HTONS(out, in)   INLINE_WORD_FLIP(out, in)
'#define INLINE_NTOHS(out, in)   INLINE_WORD_FLIP(out, in)

MACRO INLINE_HTONS(wOut, wIn) = INLINE_WORD_FLIP(wOut, wIn)
MACRO INLINE_NTONS(wOut, wIn) = INLINE_WORD_FLIP(wOut, wIn)

'#define INLINE_DWORD_FLIP(out, in)  \
'        {                           \
'            DWORD _in = (in);       \
'            (out) = ((_in << 8) & 0x00ff0000) | \
'                    (_in << 24)               | \
'                    ((_in >> 8) & 0x0000ff00) | \
'                    (_in >> 24);                \
'        }

SUB INLINE_DWORD_FLIP (BYREF dwOut AS DWORD, BYVAL dwIn AS DWORD)
   LOCAL dwTmp1, dwTmp2, dwTmp3, dwTmp4 AS DWORD
   dwTmp1 = dwIn
   dwTmp2 = dwIn
   dwTmp3 = dwIn
   dwTmp4 = dwIn
   SHIFT LEFT dwTmp1, 8
   dwTmp1 = dwTmp1 AND &H00ff0000???
   SHIFT LEFT dwTmp2, 24
   SHIFT RIGHT dwTmp3, 8
   dwTmp3 = dwTmp3 AND &H0000ff00???
   SHIFT RIGHT dwTmp4, 24
   dwOut = dwTmp1 OR dwTmp2 OR dwTmp3 OR dwTmp4
END SUB

'#define INLINE_NTOHL(out, in) INLINE_DWORD_FLIP(out, in)
'#define INLINE_HTONL(out, in) INLINE_DWORD_FLIP(out, in)

MACRO INLINE_NTOHL(dwOut, dwIn) = INLINE_DWORD_FLIP(dwOut, dwIn)
MACRO INLINE_HTONL(dwOut, dwIn) = INLINE_DWORD_FLIP(dwOut, dwIn)

'//
'//  Inline byte flip and write to packet (unaligned)
'//

'#define INLINE_WRITE_FLIPPED_WORD( pout, in ) \
'            INLINE_WORD_FLIP( *((UNALIGNED WORD *)(pout)), in )

'#define INLINE_WRITE_FLIPPED_DWORD( pout, in ) \
'            INLINE_DWORD_FLIP( *((UNALIGNED DWORD *)(pout)), in )

SUB INLINE_WRITE_FLIPPED_WORD (BYVAL pwOut AS WORD PTR, BYVAL wIn AS WORD)
   INLINE_WORD_FLIP @pwOut, wIn
END SUB

SUB INLINE_WRITE_FLIPPED_DWORD (BYVAL pdwOut AS DWORD PTR, BYVAL dwIn AS DWORD)
   INLINE_DWORD_FLIP @pdwOut, dwIn
END SUB

'//
'//  Basic DNS definitions
'//

'//
'//  DNS port for both UDP and TCP is 53.
'//

%DNS_PORT_HOST_ORDER     = &H0035   ' // port 53
%DNS_PORT_NET_ORDER      = &H3500

'//
'//  DNS UDP packets no more than 512 bytes
'//

%DNS_RFC_MAX_UDP_PACKET_LENGTH = 512


'//
'//  DNS Names limited to 255, 63 in any one label
'//

%DNS_MAX_NAME_LENGTH           = 255
%DNS_MAX_LABEL_LENGTH          = 63

%DNS_MAX_NAME_BUFFER_LENGTH    = 256
%DNS_MAX_LABEL_BUFFER_LENGTH   = 64

'//
'//  Reverse lookup domain names
'//

'#define DNS_IP4_REVERSE_DOMAIN_STRING_A ("in-addr.arpa.")
'#define DNS_IP4_REVERSE_DOMAIN_STRING_W (L"in-addr.arpa.")
$DNS_IP4_REVERSE_DOMAIN_STRING = "in-addr.arpa."

'#define DNS_MAX_IP4_REVERSE_NAME_LENGTH     (IP4_ADDRESS_STRING_LENGTH+15)
'            //(IP4_ADDRESS_STRING_LENGTH+1+sizeof(DNS_IP4_REVERSE_DOMAIN_STRING_A))

%DNS_MAX_IP4_REVERSE_NAME_LENGTH = %IP4_ADDRESS_STRING_LENGTH + 15

'#define DNS_IP6_REVERSE_DOMAIN_STRING_A ("ip6.arpa.")
'#define DNS_IP6_REVERSE_DOMAIN_STRING_W (L"ip6.arpa.")
$DNS_IP6_REVERSE_DOMAIN_STRING = "ip6.arpa."

'#define DNS_MAX_IP6_REVERSE_NAME_LENGTH     (75)
'            //(64+sizeof(DNS_IP6_REVERSE_DOMAIN_STRING_A))

%DNS_MAX_IP6_REVERSE_NAME_LENGTH = 75

'//  Combined

%DNS_MAX_REVERSE_NAME_LENGTH     = %DNS_MAX_IP6_REVERSE_NAME_LENGTH

'#ifdef UNICODE
'#define DNS_IP4_REVERSE_DOMAIN_STRING   DNS_IP4_REVERSE_DOMAIN_STRING_W
'#define DNS_IP6_REVERSE_DOMAIN_STRING   DNS_IP6_REVERSE_DOMAIN_STRING_W
'#else
'#define DNS_IP4_REVERSE_DOMAIN_STRING   DNS_IP4_REVERSE_DOMAIN_STRING_A
'#define DNS_IP6_REVERSE_DOMAIN_STRING   DNS_IP6_REVERSE_DOMAIN_STRING_A
'#endif

'//
'//  Backcompat only -- name def contains terminating NULL
'//

%DNS_MAX_IP4_REVERSE_NAME_BUFFER_LENGTH  = %DNS_MAX_IP4_REVERSE_NAME_LENGTH
%DNS_MAX_IP6_REVERSE_NAME_BUFFER_LENGTH  = %DNS_MAX_IP6_REVERSE_NAME_LENGTH
%DNS_MAX_REVERSE_NAME_BUFFER_LENGTH      = %DNS_MAX_REVERSE_NAME_LENGTH

'//
'//  DNS Text string limited by size representable
'//      in a single byte length field

%DNS_MAX_TEXT_STRING_LENGTH = 255

'//
'//  DNS On-The-Wire Structures
'//

'#pragma pack(1)

'//
'//  DNS Message Header
'//

'typedef struct _DNS_HEADER
'{
'    WORD    Xid;

'    BYTE    RecursionDesired : 1;
'    BYTE    Truncation : 1;
'    BYTE    Authoritative : 1;
'    BYTE    Opcode : 4;
'    BYTE    IsResponse : 1;

'    BYTE    ResponseCode : 4;
'    BYTE    Reserved : 3;
'    BYTE    RecursionAvailable : 1;

'    WORD    QuestionCount;
'    WORD    AnswerCount;
'    WORD    NameServerCount;
'    WORD    AdditionalCount;
'}
'DNS_HEADER, *PDNS_HEADER;

' // Size = 12 bytes
TYPE DNS_HEADER BYTE
   Xid                AS WORD
   RecursionDesired   AS BIT * 1 IN BYTE
   Truncation         AS BIT * 1
   Authoritative      AS BIT * 1
   Opcode             AS BIT * 4
   IsResponse         AS BIT * 1
   ResponseCode       AS BIT * 4 IN BYTE
   CheckingDisabled   AS BIT * 1
   AuthenticatedData  AS BIT * 1
   Reserved           AS BIT * 1
   RecursionAvailable AS BIT * 1
   QuestionCount      AS WORD
   AnswerCount        AS WORD
   NameServerCount    AS WORD
   AdditionalCount    AS WORD
END TYPE

' // Size = 4 bytes
TYPE DNS_HEADER_EXT BYTE
   Reserved  AS BIT * 15 IN WORD
   DnssecOk  AS BIT * 1
   chRcode   AS BYTE
   chVersion AS BYTE
END TYPE

'//
'//  Flags as WORD
'//

'#define DNS_HEADER_FLAGS(pHead)     ( *((PWORD)(pHead)+1) )

'//
'//  Byte flip DNS header to\from host order.
'//
'//  Note that this does NOT flip flags, as definition above defines
'//  flags as individual bytes for direct access to net byte order.
'//

'#define DNS_BYTE_FLIP_HEADER_COUNTS(pHeader)       \
'        {                                   \
'            PDNS_HEADER _head = (pHeader);  \
'            INLINE_HTONS(_head->Xid,            _head->Xid             ); \
'            INLINE_HTONS(_head->QuestionCount,  _head->QuestionCount   ); \
'            INLINE_HTONS(_head->AnswerCount,    _head->AnswerCount     ); \
'            INLINE_HTONS(_head->NameServerCount,_head->NameServerCount ); \
'            INLINE_HTONS(_head->AdditionalCount,_head->AdditionalCount ); \
'        }

'//
'//  Question name follows header
'//

'#define DNS_OFFSET_TO_QUESTION_NAME     sizeof(DNS_HEADER)

'//
'//  Question immediately follows header so compressed question name
'//      0xC000 | sizeof(DNS_HEADER)

%DNS_COMPRESSED_QUESTION_NAME = &HC00C


'//
'//  Packet extraction macros
'//

'#define DNS_QUESTION_NAME_FROM_HEADER( _pHeader_ ) \
'            ( (PCHAR)( (PDNS_HEADER)(_pHeader_) + 1 ) )

'#define DNS_ANSWER_FROM_QUESTION( _pQuestion_ ) \
'            ( (PCHAR)( (PDNS_QUESTION)(_pQuestion_) + 1 ) )


'//
'//  DNS Question
'//

'typedef struct _DNS_WIRE_QUESTION
'{
'    //  Preceded by question name

'    WORD    QuestionType;
'    WORD    QuestionClass;
'}
'DNS_WIRE_QUESTION, *PDNS_WIRE_QUESTION;

' // Size = 4 bytes
TYPE DNS_WIRE_QUESTION WORD
   QuestionType  AS WORD
   QuestionClass AS WORD
END TYPE

'//
'//  DNS Resource Record
'//

'typedef struct _DNS_WIRE_RECORD
'{
'    //  Preceded by record owner name

'    WORD    RecordType;
'    WORD    RecordClass;
'    DWORD   TimeToLive;
'    WORD    DataLength;

'    //  Followed by record data
'}
'DNS_WIRE_RECORD, *PDNS_WIRE_RECORD;

' // Size = 10 bytes
TYPE DNS_WIRE_RECORD WORD
   RecordType  AS WORD
   RecordClass AS WORD
   TimeToLive  AS DWORD
   DataLength  AS WORD
END TYPE

'#pragma pack()


'//
'//  DNS Query Types
'//

%DNS_OPCODE_QUERY           = 0   ' // Query
%DNS_OPCODE_IQUERY          = 1   ' // Obsolete: IP to name
%DNS_OPCODE_SERVER_STATUS   = 2   ' // Obsolete: DNS ping
%DNS_OPCODE_UNKNOWN         = 3   ' // Unknown
%DNS_OPCODE_NOTIFY          = 4   ' // Notify
%DNS_OPCODE_UPDATE          = 5   ' // Dynamic Update

'//
'//  DNS response codes.
'//
'//  Sent in the "ResponseCode" field of a DNS_HEADER.
'//

%DNS_RCODE_NOERROR      = 0
%DNS_RCODE_FORMERR      = 1       ' // Format error
%DNS_RCODE_SERVFAIL     = 2       ' // Server failure
%DNS_RCODE_NXDOMAIN     = 3       ' // Name error
%DNS_RCODE_NOTIMPL      = 4       ' // Not implemented
%DNS_RCODE_REFUSED      = 5       ' // Refused
%DNS_RCODE_YXDOMAIN     = 6       ' // Domain name should not exist
%DNS_RCODE_YXRRSET      = 7       ' // RR set should not exist
%DNS_RCODE_NXRRSET      = 8       ' // RR set does not exist
%DNS_RCODE_NOTAUTH      = 9       ' // Not authoritative for zone
%DNS_RCODE_NOTZONE      = 10      ' // Name is not zone
%DNS_RCODE_MAX          = 15

'//
'//  Extended RCODEs
'//

%DNS_RCODE_BADVERS      = 16      ' // Bad EDNS version
%DNS_RCODE_BADSIG       = 16      ' // Bad signature
%DNS_RCODE_BADKEY       = 17      ' // Bad key
%DNS_RCODE_BADTIME      = 18      ' // Bad timestamp

'//
'//  Mappings to friendly names
'//

%DNS_RCODE_NO_ERROR        = %DNS_RCODE_NOERROR
%DNS_RCODE_FORMAT_ERROR    = %DNS_RCODE_FORMERR
%DNS_RCODE_SERVER_FAILURE  = %DNS_RCODE_SERVFAIL
%DNS_RCODE_NAME_ERROR      = %DNS_RCODE_NXDOMAIN
%DNS_RCODE_NOT_IMPLEMENTED = %DNS_RCODE_NOTIMPL


'//
'//  DNS Classes
'//
'//  Classes are on the wire as WORDs.
'//
'//  _CLASS_ defines in host order.
'//  _RCLASS_ defines in net byte order.
'//
'//  Generally we'll avoid byte flip and test class in net byte order.
'//

%DNS_CLASS_INTERNET  = &h0001??      ' //  1
%DNS_CLASS_CSNET     = &h0002??      ' //  2
%DNS_CLASS_CHAOS     = &h0003??      ' //  3
%DNS_CLASS_HESIOD    = &h0004??      ' //  4
%DNS_CLASS_NONE      = &h00fe??      ' //  254
%DNS_CLASS_ALL       = &h00ff??      ' //  255
%DNS_CLASS_ANY       = &h00ff??      ' //  255

%DNS_RCLASS_INTERNET = &h0100??      ' //  1
%DNS_RCLASS_CSNET    = &h0200??      ' //  2
%DNS_RCLASS_CHAOS    = &h0300??      ' //  3
%DNS_RCLASS_HESIOD   = &h0400??      ' //  4
%DNS_RCLASS_NONE     = &hfe00??      ' //  254
%DNS_RCLASS_ALL      = &hff00??      ' //  255
%DNS_RCLASS_ANY      = &hff00??      ' //  255


'//
'//  DNS Record Types
'//
'//  _TYPE_ defines are in host byte order.
'//  _RTYPE_ defines are in net byte order.
'//
'//  Generally always deal with types in host byte order as we index
'//  resource record functions by type.
'//

%DNS_TYPE_ZERO       = &h0000

'//  RFC 1034/1035
%DNS_TYPE_A          = &h0001      ' //  1
%DNS_TYPE_NS         = &h0002      ' //  2
%DNS_TYPE_MD         = &h0003      ' //  3
%DNS_TYPE_MF         = &h0004      ' //  4
%DNS_TYPE_CNAME      = &h0005      ' //  5
%DNS_TYPE_SOA        = &h0006      ' //  6
%DNS_TYPE_MB         = &h0007      ' //  7
%DNS_TYPE_MG         = &h0008      ' //  8
%DNS_TYPE_MR         = &h0009      ' //  9
%DNS_TYPE_NULL       = &h000a      ' //  10
%DNS_TYPE_WKS        = &h000b      ' //  11
%DNS_TYPE_PTR        = &h000c      ' //  12
%DNS_TYPE_HINFO      = &h000d      ' //  13
%DNS_TYPE_MINFO      = &h000e      ' //  14
%DNS_TYPE_MX         = &h000f      ' //  15
%DNS_TYPE_TEXT       = &h0010      ' //  16

'//  RFC 1183
%DNS_TYPE_RP         = &h0011      ' //  17
%DNS_TYPE_AFSDB      = &h0012      ' //  18
%DNS_TYPE_X25        = &h0013      ' //  19
%DNS_TYPE_ISDN       = &h0014      ' //  20
%DNS_TYPE_RT         = &h0015      ' //  21

'//  RFC 1348
%DNS_TYPE_NSAP       = &h0016      ' //  22
%DNS_TYPE_NSAPPTR    = &h0017      ' //  23

'//  RFC 2065    (DNS security)
%DNS_TYPE_SIG        = &h0018      ' //  24
%DNS_TYPE_KEY        = &h0019      ' //  25

'//  RFC 1664    (X.400 mail)
%DNS_TYPE_PX         = &h001a      ' //  26

'//  RFC 1712    (Geographic position)
%DNS_TYPE_GPOS       = &h001b      ' //  27

'//  RFC 1886    (IPv6 Address)
%DNS_TYPE_AAAA       = &h001c      ' //  28

'//  RFC 1876    (Geographic location)
%DNS_TYPE_LOC        = &h001d      ' //  29

'//  RFC 2065    (Secure negative response)
%DNS_TYPE_NXT        = &h001e      ' //  30

'//  Patton      (Endpoint Identifier)
%DNS_TYPE_EID        = &h001f      ' //  31

'//  Patton      (Nimrod Locator)
%DNS_TYPE_NIMLOC     = &h0020      ' //  32

'//  RFC 2052    (Service location)
%DNS_TYPE_SRV        = &h0021      ' //  33

'//  ATM Standard something-or-another (ATM Address)
%DNS_TYPE_ATMA       = &h0022      ' //  34

'//  RFC 2168    (Naming Authority Pointer)
%DNS_TYPE_NAPTR      = &h0023      ' //  35

'//  RFC 2230    (Key Exchanger)
%DNS_TYPE_KX         = &h0024      ' //  36

'//  RFC 2538    (CERT)
%DNS_TYPE_CERT       = &h0025      ' //  37

'//  A6 Draft    (A6)
%DNS_TYPE_A6         = &h0026      ' //  38

'//  DNAME Draft (DNAME)
%DNS_TYPE_DNAME      = &h0027      ' //  39

'//  Eastlake    (Kitchen Sink)
%DNS_TYPE_SINK       = &h0028      ' //  40

'//  RFC 2671    (EDNS OPT)
%DNS_TYPE_OPT        = &h0029      ' //  41

'//  RFC 4034    (DNSSEC DS)
%DNS_TYPE_DS         = &H002b      ' //  43

'//  RFC 4034    (DNSSEC RRSIG)
%DNS_TYPE_RRSIG      = &H002e      ' //  46

'//  RFC 4034    (DNSSEC NSEC)
%DNS_TYPE_NSEC       = &H002f      ' //  47

'//  RFC 4034    (DNSSEC DNSKEY)
%DNS_TYPE_DNSKEY     = &H0030      ' //  48

'//  RFC 4701    (DHCID)
%DNS_TYPE_DHCID      = &H0031      ' //  49

'//
'//  IANA Reserved
'//

%DNS_TYPE_UINFO      = &h0064      ' //  100
%DNS_TYPE_UID        = &h0065      ' //  101
%DNS_TYPE_GID        = &h0066      ' //  102
%DNS_TYPE_UNSPEC     = &h0067      ' //  103

'//
'//  Query only types (1035, 1995)
'//      - Crawford      (ADDRS)
'//      - TKEY draft    (TKEY)
'//      - TSIG draft    (TSIG)
'//      - RFC 1995      (IXFR)
'//      - RFC 1035      (AXFR up)
'//

%DNS_TYPE_ADDRS      = &h00f8      ' //  248
%DNS_TYPE_TKEY       = &h00f9      ' //  249
%DNS_TYPE_TSIG       = &h00fa      ' //  250
%DNS_TYPE_IXFR       = &h00fb      ' //  251
%DNS_TYPE_AXFR       = &h00fc      ' //  252
%DNS_TYPE_MAILB      = &h00fd      ' //  253
%DNS_TYPE_MAILA      = &h00fe      ' //  254
%DNS_TYPE_ALL        = &h00ff      ' //  255
%DNS_TYPE_ANY        = &h00ff      ' //  255

'//
'//  Temp Microsoft types -- use until get IANA approval for real type
'//

%DNS_TYPE_WINS       = &hff01??      ' //  64K - 255
%DNS_TYPE_WINSR      = &hff02??      ' //  64K - 254
%DNS_TYPE_NBSTAT     = %DNS_TYPE_WINSR


'//
'//  DNS Record Types -- Net Byte Order
'//

%DNS_RTYPE_A         = &h0100      ' //  1
%DNS_RTYPE_NS        = &h0200      ' //  2
%DNS_RTYPE_MD        = &h0300      ' //  3
%DNS_RTYPE_MF        = &h0400      ' //  4
%DNS_RTYPE_CNAME     = &h0500      ' //  5
%DNS_RTYPE_SOA       = &h0600      ' //  6
%DNS_RTYPE_MB        = &h0700      ' //  7
%DNS_RTYPE_MG        = &h0800      ' //  8
%DNS_RTYPE_MR        = &h0900      ' //  9
%DNS_RTYPE_NULL      = &h0a00      ' //  10
%DNS_RTYPE_WKS       = &h0b00      ' //  11
%DNS_RTYPE_PTR       = &h0c00      ' //  12
%DNS_RTYPE_HINFO     = &h0d00      ' //  13
%DNS_RTYPE_MINFO     = &h0e00      ' //  14
%DNS_RTYPE_MX        = &h0f00      ' //  15
%DNS_RTYPE_TEXT      = &h1000      ' //  16
%DNS_RTYPE_RP        = &h1100      ' //  17
%DNS_RTYPE_AFSDB     = &h1200      ' //  18
%DNS_RTYPE_X25       = &h1300      ' //  19
%DNS_RTYPE_ISDN      = &h1400      ' //  20
%DNS_RTYPE_RT        = &h1500      ' //  21
%DNS_RTYPE_NSAP      = &h1600      ' //  22
%DNS_RTYPE_NSAPPTR   = &h1700      ' //  23
%DNS_RTYPE_SIG       = &h1800      ' //  24
%DNS_RTYPE_KEY       = &h1900      ' //  25
%DNS_RTYPE_PX        = &h1a00      ' //  26
%DNS_RTYPE_GPOS      = &h1b00      ' //  27
%DNS_RTYPE_AAAA      = &h1c00      ' //  28
%DNS_RTYPE_LOC       = &h1d00      ' //  29
%DNS_RTYPE_NXT       = &h1e00      ' //  30
%DNS_RTYPE_EID       = &h1f00      ' //  31
%DNS_RTYPE_NIMLOC    = &h2000      ' //  32
%DNS_RTYPE_SRV       = &h2100      ' //  33
%DNS_RTYPE_ATMA      = &h2200      ' //  34
%DNS_RTYPE_NAPTR     = &h2300      ' //  35
%DNS_RTYPE_KX        = &h2400      ' //  36
%DNS_RTYPE_CERT      = &h2500      ' //  37
%DNS_RTYPE_A6        = &h2600      ' //  38
%DNS_RTYPE_DNAME     = &h2700      ' //  39
%DNS_RTYPE_SINK      = &h2800      ' //  40
%DNS_RTYPE_OPT       = &h2900      ' //  41

%DNS_RTYPE_DS        = &H2b00      ' //  43
%DNS_RTYPE_RRSIG     = &H2e00      ' //  46
%DNS_RTYPE_NSEC      = &H2f00      ' //  47
%DNS_RTYPE_DNSKEY    = &H3000      ' //  48
%DNS_RTYPE_DHCID     = &H3100      ' //  49

'//
'//  IANA Reserved
'//

%DNS_RTYPE_UINFO     = &h6400      ' //  100
%DNS_RTYPE_UID       = &h6500      ' //  101
%DNS_RTYPE_GID       = &h6600      ' //  102
%DNS_RTYPE_UNSPEC    = &h6700      ' //  103

'//
'//  Query only types
'//

%DNS_RTYPE_TKEY      = &hf900??      ' //  249
%DNS_RTYPE_TSIG      = &hfa00??      ' //  250
%DNS_RTYPE_IXFR      = &hfb00??      ' //  251
%DNS_RTYPE_AXFR      = &hfc00??      ' //  252
%DNS_RTYPE_MAILB     = &hfd00??      ' //  253
%DNS_RTYPE_MAILA     = &hfe00??      ' //  254
%DNS_RTYPE_ALL       = &hff00??      ' //  255
%DNS_RTYPE_ANY       = &hff00??      ' //  255

'//
'//  Temp Microsoft types -- use until get IANA approval for real type
'//

%DNS_RTYPE_WINS      = &h01ff      ' //  64K - 255
%DNS_RTYPE_WINSR     = &h02ff      ' //  64K - 254


'//
'//  Record type specific definitions
'//

'//
'//  ATMA (ATM address type) formats
'//
'//  Define these directly for any environment (ex NT4)
'//  without winsock2 ATM support (ws2atm.h)
'//

#IF NOT %DEF(%ATMA_E164)
%DNS_ATMA_FORMAT_E164           = 1
%DNS_ATMA_FORMAT_AESA           = 2
%DNS_ATMA_MAX_ADDR_LENGTH       = 20
#ELSE
%DNS_ATMA_FORMAT_E164           = %ATM_E164
%DNS_ATMA_FORMAT_AESA           = %ATM_AESA
%DNS_ATMA_MAX_ADDR_LENGTH       = %ATM_ADDR_SIZE
#ENDIF

%DNS_ATMA_AESA_ADDR_LENGTH      = 20
%DNS_ATMA_MAX_RECORD_LENGTH     = %DNS_ATMA_MAX_ADDR_LENGTH + 1


'//
'//  DNSSEC defs
'//

'//  DNSSEC algorithms

%DNSSEC_ALGORITHM_RSAMD5    = 1
%DNSSEC_ALGORITHM_RSASHA1   = 5
%DNSSEC_ALGORITHM_NULL      = 253
%DNSSEC_ALGORITHM_PRIVATE   = 254

'//  DNSSEC KEY protocol table

%DNSSEC_PROTOCOL_NONE       = 0
%DNSSEC_PROTOCOL_TLS        = 1
%DNSSEC_PROTOCOL_EMAIL      = 2
%DNSSEC_PROTOCOL_DNSSEC     = 3
%DNSSEC_PROTOCOL_IPSEC      = 4

'//  DNSSEC KEY flag field

%DNSSEC_KEY_FLAG_NOAUTH          = &H0001??
%DNSSEC_KEY_FLAG_NOCONF          = &H0002??
%DNSSEC_KEY_FLAG_FLAG2           = &H0004??
%DNSSEC_KEY_FLAG_EXTEND          = &H0008??
%DNSSEC_KEY_FLAG_FLAG4           = &H0010??
%DNSSEC_KEY_FLAG_FLAG5           = &H0020??

'// bits 6,7 are name type

%DNSSEC_KEY_FLAG_USER            = &H0000??
%DNSSEC_KEY_FLAG_ZONE            = &H0040??
%DNSSEC_KEY_FLAG_HOST            = &H0080??
%DNSSEC_KEY_FLAG_NTPE3           = &H00c0??

'// bits 8-11 are reserved for future use

%DNSSEC_KEY_FLAG_FLAG8           = &H0100??
%DNSSEC_KEY_FLAG_FLAG9           = &H0200??
%DNSSEC_KEY_FLAG_FLAG10          = &H0400??
%DNSSEC_KEY_FLAG_FLAG11          = &H0800??

'// bits 12-15 are sig field

%DNSSEC_KEY_FLAG_SIG0            = &H0000??
%DNSSEC_KEY_FLAG_SIG1            = &H1000??
%DNSSEC_KEY_FLAG_SIG2            = &H2000??
%DNSSEC_KEY_FLAG_SIG3            = &H3000??
%DNSSEC_KEY_FLAG_SIG4            = &H4000??
%DNSSEC_KEY_FLAG_SIG5            = &H5000??
%DNSSEC_KEY_FLAG_SIG6            = &H6000??
%DNSSEC_KEY_FLAG_SIG7            = &H7000??
%DNSSEC_KEY_FLAG_SIG8            = &H8000??
%DNSSEC_KEY_FLAG_SIG9            = &H9000??
%DNSSEC_KEY_FLAG_SIG10           = &Ha000??
%DNSSEC_KEY_FLAG_SIG11           = &Hb000??
%DNSSEC_KEY_FLAG_SIG12           = &Hc000??
%DNSSEC_KEY_FLAG_SIG13           = &Hd000??
%DNSSEC_KEY_FLAG_SIG14           = &He000??
%DNSSEC_KEY_FLAG_SIG15           = &Hf000??


'//
'//  TKEY modes
'//

%DNS_TKEY_MODE_SERVER_ASSIGN       = 1
%DNS_TKEY_MODE_DIFFIE_HELLMAN      = 2
%DNS_TKEY_MODE_GSS                 = 3
%DNS_TKEY_MODE_RESOLVER_ASSIGN     = 4

'//
'//  WINS + NBSTAT flag field
'//

%DNS_WINS_FLAG_SCOPE     = &H80000000???
%DNS_WINS_FLAG_LOCAL     = &H00010000???


'//
'//  Helpful checks
'//

'#define IS_WORD_ALIGNED(p)      ( !((UINT_PTR)(p) & (UINT_PTR)1) )
'#define IS_DWORD_ALIGNED(p)     ( !((UINT_PTR)(p) & (UINT_PTR)3) )
'#define IS_QWORD_ALIGNED(p)     ( !((UINT_PTR)(p) & (UINT_PTR)7) )

MACRO IS_WORD_ALIGNED(p) = NOT (p AND 1)
MACRO IS_DWORD_ALIGNED(p) = NOT (p AND 3)
MACRO IS_QWORD_ALIGNED(p) = NOT (p AND 7)

'//
'//  DNS config API
'//

'//
'//  Types of DNS configuration info
'//

'typedef enum
'{
'    //  In Win2K
'    DnsConfigPrimaryDomainName_W,
'    DnsConfigPrimaryDomainName_A,
'    DnsConfigPrimaryDomainName_UTF8,

'    //  Not available yet
'    DnsConfigAdapterDomainName_W,
'    DnsConfigAdapterDomainName_A,
'    DnsConfigAdapterDomainName_UTF8,

'    //  In Win2K
'    DnsConfigDnsServerList,

'    //  Not available yet
'    DnsConfigSearchList,
'    DnsConfigAdapterInfo,

'    //  In Win2K
'    DnsConfigPrimaryHostNameRegistrationEnabled,
'    DnsConfigAdapterHostNameRegistrationEnabled,
'    DnsConfigAddressRegistrationMaxCount,

'    //  In WindowsXP
'    DnsConfigHostName_W,
'    DnsConfigHostName_A,
'    DnsConfigHostName_UTF8,
'    DnsConfigFullHostName_W,
'    DnsConfigFullHostName_A,
'    DnsConfigFullHostName_UTF8

'    //  In XP-SP1 (Server.net)
'}
'DNS_CONFIG_TYPE;

' DNS_CONFIG_TYPE enum
%DnsConfigPrimaryDomainName_W                = 0
%DnsConfigPrimaryDomainName_A                = 1
%DnsConfigPrimaryDomainName_UTF8             = 2
%DnsConfigAdapterDomainName_W                = 3
%DnsConfigAdapterDomainName_A                = 4
%DnsConfigAdapterDomainName_UTF8             = 5
%DnsConfigDnsServerList                      = 6
%DnsConfigSearchList                         = 7
%DnsConfigAdapterInfo                        = 8
%DnsConfigPrimaryHostNameRegistrationEnabled = 9
%DnsConfigAdapterHostNameRegistrationEnabled = 10
%DnsConfigAddressRegistrationMaxCount        = 11
%DnsConfigHostName_W                         = 12
%DnsConfigHostName_A                         = 13
%DnsConfigHostName_UTF8                      = 14
%DnsConfigFullHostName_W                     = 15
%DnsConfigFullHostName_A                     = 16
%DnsConfigFullHostName_UTF8                  = 17

'//
'//  Config API flags
'//

'//
'//  DNS_CONFIG_FLAG_ALLOC -- Causes config info to be allocated.
'//      Free with LocalFree().
'//

%DNS_CONFIG_FLAG_ALLOC   = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsQueryConfig LIB "DnsApi.dll" ALIAS "DnsQueryConfig" ( _
    BYVAL Config   AS LONG, _
    BYVAL Flag     AS DWORD, _
    pwsAdapterName AS WSTRINGZ, _
    pReserved      AS ANY, _   ' PVOID
    pBuffer        AS ANY, _   ' PVOID
    pBufLen        AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsQueryConfig IMPORT "DNSAPI.DLL" ALIAS "DnsQueryConfig" ( _
   BYVAL Config AS LONG _                               ' __in      DNS_CONFIG_TYPE Config
 , BYVAL Flag AS DWORD _                                ' __in      DWORD           Flag
 , BYREF pwsAdapterName AS WSTRINGZ _                   ' __in_opt  PWSTR           pwsAdapterName
 , BYVAL pReserved AS DWORD _                           ' __in_opt  PVOID           pReserved
 , BYREF pBuffer AS ANY _                               ' __out     PVOID           pBuffer
 , BYREF pBufferLength AS DWORD _                       ' __inout   PDWORD          pBufferLength
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

'//
'//  DNS resource record structure
'//

'//
'//  Record data for specific types
'//

' // Size = 4 bytes
TYPE DNS_A_DATA DWORD
   IpAddress AS DWORD   ' IP4_ADDRESS
END TYPE

' // Size = 4 bytes
TYPE DNS_PTR_DATAW DWORD
   pNameHost AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 4 bytes
TYPE DNS_PTR_DATAA DWORD
   pNameHost AS ASCIIZ PTR   ' PSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_PTR_DATA = DNS_PTR_DATAW
#ELSE
   MACRO DNS_PTR_DATA = DNS_PTR_DATAA
#ENDIF

' // Size = 28 bytes
TYPE DNS_SOA_DATAW DWORD
   pNamePrimaryServer AS WSTRINGZ PTR   ' PWSTR
   pNameAdministrator AS WSTRINGZ PTR   ' PWSTR
   dwSerialNo         AS DWORD          ' DWORD
   dwRefresh          AS DWORD          ' DWORD
   dwRetry            AS DWORD          ' DWORD
   dwExpire           AS DWORD          ' DWORD
   dwDefaultTtl       AS DWORD          ' DWORD
END TYPE

' // Size = 28 bytes
TYPE DNS_SOA_DATAA DWORD
   pNamePrimaryServer AS ASCIIZ PTR   ' PSTR
   pNameAdministrator AS ASCIIZ PTR   ' PSTR
   dwSerialNo         AS DWORD        ' DWORD
   dwRefresh          AS DWORD        ' DWORD
   dwRetry            AS DWORD        ' DWORD
   dwExpire           AS DWORD        ' DWORD
   dwDefaultTtl       AS DWORD        ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_SOA_DATA = DNS_SOA_DATAW
#ELSE
   MACRO DNS_SOA_DATA = DNS_SOA_DATAA
#ENDIF

' // Size = 8 bytes
TYPE DNS_MINFO_DATAW DWORD
   pNameMailbox       AS WSTRINGZ PTR   ' PWSTR
   pNameErrorsMailbox AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 8 bytes
TYPE DNS_MINFO_DATAA DWORD
   pNameMailbox       AS ASCIIZ PTR   ' PSTR
   pNameErrorsMailbox AS ASCIIZ PTR   ' PSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_MINFO_DATA = DNS_MINFO_DATAW
#ELSE
   MACRO DNS_MINFO_DATA = DNS_MINFO_DATAA
#ENDIF

' // Size = 8 bytes
TYPE DNS_MX_DATAW WORD
   pNameExchange AS WSTRINGZ PTR
   wPreference   AS WORD
   Pad           AS WORD    ' // keep ptrs DWORD aligned
END TYPE

' // Size = 8 bytes
TYPE DNS_MX_DATAA WORD
   pNameExchange AS ASCIIZ PTR
   wPreference   AS WORD
   Pad           AS WORD        ' // keep ptrs DWORD aligned
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_MX_DATA = DNS_MX_DATAW
#ELSE
   MACRO DNS_MX_DATA = DNS_MX_DATAA
#ENDIF

' // Size = 8 bytes
TYPE DNS_TXT_DATAW DWORD
   dwStringCount   AS DWORD
   pStringArray(0) AS WSTRINGZ PTR
END TYPE

' // Size = 8 bytes
TYPE DNS_TXT_DATAA DWORD
   dwStringCount   AS DWORD
   pStringArray(0) AS ASCIIZ PTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_TXT_DATA = DNS_TXT_DATAW
#ELSE
   MACRO DNS_TXT_DATA = DNS_TXT_DATAA
#ENDIF

' // Size = 8 bytes
TYPE DNS_NULL_DATA DWORD
   dwByteCount AS DWORD
   Data(0)     AS BYTE
END TYPE

' // Size = 8 bytes
TYPE DNS_WKS_DATA BYTE
   IpAddress  AS DWORD   ' IP4_ADDRESS
   chProtocol AS BYTE    ' UCHAR
   BitMask(2) AS BYTE
   ' Note: We are using BitMask(2) instead of BitMask(0) to keep DWORD alignment
END TYPE

' // Size = 16 bytes
TYPE DNS_AAAA_DATA BYTE
   Ip6Address AS IP6_ADDRESS
END TYPE

' // Size = 28 bytes
TYPE DNS_SIG_DATAW BYTE
   pNameSigner   AS WSTRINGZ PTR   ' PWSTR
   wTypeCovered  AS WORD
   chAlgorithm   AS BYTE
   chLabelCount  AS BYTE
   dwOriginalTtl AS DWORD
   dwExpiration  AS DWORD
   dwTimeSigned  AS DWORD
   wKeyTag       AS WORD
   Pad           AS WORD       ' // keep byte field aligned
   Signature(3)  AS BYTE
   ' Note: We are using Signature(3) instead of Signature(0) to keep DWORD alignment
END TYPE

' // Size = 28 bytes
TYPE DNS_SIG_DATAA BYTE
   pNameSigner   AS ASCIIZ PTR   ' PSTR
   wTypeCovered  AS WORD
   chAlgorithm   AS BYTE
   chLabelCount  AS BYTE
   dwOriginalTtl AS DWORD
   dwExpiration  AS DWORD
   dwTimeSigned  AS DWORD
   wKeyTag       AS WORD
   Pad           AS WORD    ' // keep byte field aligned
   Signature(3)  AS BYTE
   ' Note: We are using Signature(3) instead of Signature(0) to keep DWORD alignment
END TYPE

MACRO DNS_RRSIG_DATAW = DNS_SIG_DATAW
MACRO DNS_RRSIG_DATAA = DNS_SIG_DATAA
#IF %DEF(%UNICODE)
   MACRO DNS_SIG_DATA = DNS_SIG_DATAW
#ELSE
   MACRO DNS_SIG_DATA = DNS_SIG_DATAA
#ENDIF

' // Size = 10 bytes
TYPE DNS_KEY_DATA BYTE
   wFlags      AS WORD
   chProtocol  AS BYTE
   chAlgorithm AS BYTE
   wKeyLength  AS WORD
   wPad        AS WORD   ' // keep byte field aligned
   Key(1)      AS BYTE
   ' Note: We are using Key(1) instead of Key(0) to keep WORD alignment
END TYPE

MACRO DNS_DNSKEY_DATA = DNS_KEY_DATA

' // Size = 8 bytes
TYPE DNS_DHCID_DATA BYTE
   dwByteCount AS DWORD   ' DWORD
   DHCID(3)    AS BYTE    ' BYTE[1]
   ' Note: We are using DHCID(3) instead of DHCID(0) to keep DWORD alignment
END TYPE

' // Size = 12 bytes
TYPE DNS_NSEC_DATAW BYTE
   pNextDomainName    AS WSTRINGZ PTR   ' PWSTR
   wTypeBitMapsLength AS WORD           ' WORD
   wPad               AS WORD           ' WORD // keep byte field aligned
   TypeBitMaps(3)     AS BYTE           ' BYTE[1]
   ' Note: We are using TypeBitMaps(3) instead of TypeBitMaps(0) to keep DWORD alignment
END TYPE

' // Size = 12 bytes
TYPE DNS_NSEC_DATAA BYTE
   pNextDomainName    AS ASCIIZ PTR   ' PSTR
   wTypeBitMapsLength AS WORD         ' WORD
   wPad               AS WORD         ' WORD // keep byte field aligned
   TypeBitMaps(3)     AS BYTE
   ' Note: We are using TypeBitMaps(3) instead of TypeBitMaps(0) to keep DWORD alignment
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_NSEC_DATA = DNS_NSEC_DATAW
#ELSE
   MACRO DNS_NSEC_DATA = DNS_NSEC_DATAA
#ENDIF

' // Size = 10 bytes
TYPE DNS_DS_DATA BYTE
   wKeyTag       AS WORD   ' WORD
   chAlgorithm   AS BYTE   ' BYTE
   chDigestType  AS BYTE   ' BYTE
   wDigestLength AS WORD   ' WORD
   wPad          AS WORD   ' WORD // keep byte field aligned
   Digest(1)     AS BYTE   ' BYTE[1]
   ' Note: We are using Digest(1) instead of Digest(0) to keep DWORD alignment
END TYPE

' // Size = 6 bytes
TYPE DNS_OPT_DATA
   wDataLength AS WORD   ' WORD
   wPad        AS WORD   ' WORD // keep byte field aligned
   Data(1)     AS BYTE   ' BYTE[1]
   ' Note: We are using Data(1) instead of Data(0) to keep DWORD alignment
END TYPE

' // Size = 20 bytes
TYPE DNS_LOC_DATA DWORD FILL
   wVersion    AS WORD
   wSize       AS WORD
   wHorPrec    AS WORD
   wVerPrec    AS WORD
   dwLatitude  AS DWORD
   dwLongitude AS DWORD
   dwAltitude  AS DWORD
END TYPE

' // Size = 8 bytes
TYPE DNS_NXT_DATAW DWORD FILL
   pNameNext AS WSTRINGZ PTR   ' PWSTR
   wNumTypes AS WORD
   wTypes(0) AS WORD
END TYPE

' // Size = 8 bytes
TYPE DNS_NXT_DATAA DWORD FILL
   pNameNext AS ASCIIZ PTR   ' PSTR
   wNumTypes AS WORD
   wTypes(0) AS WORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_NXT_DATA = DNS_NXT_DATAW
#ELSE
   MACRO DNS_NXT_DATA = DNS_NXT_DATAA
#ENDIF

' // Size = 12 bytes
TYPE DNS_SRV_DATAW DWORD FILL
   pNameTarget AS WSTRINGZ PTR   ' PWSTR
   wPriority   AS WORD
   wWeight     AS WORD
   wPort       AS WORD
   Pad         AS WORD           ' // keep ptrs DWORD aligned
END TYPE

' // Size = 12 bytes
TYPE DNS_SRV_DATAA DWORD FILL
   pNameTarget AS ASCIIZ PTR   ' PSTR
   wPriority   AS WORD
   wWeight     AS WORD
   wPort       AS WORD
   Pad         AS WORD         ' // keep ptrs DWORD aligned
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_SRV_DATA = DNS_SRV_DATAW
#ELSE
   MACRO DNS_SRV_DATA = DNS_SRV_DATAA
#ENDIF

' // Size = 20 bytes
TYPE DNS_NAPTR_DATAW DWORD FILL
   wOrder             AS WORD           ' WORD
   wPreference        AS WORD           ' WORD
   pFlags             AS WSTRINGZ PTR   ' PWSTR
   pService           AS WSTRINGZ PTR   ' PWSTR
   pRegularExpression AS WSTRINGZ PTR   ' PWSTR
   pReplacement       AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 20 bytes
TYPE DNS_NAPTR_DATAA DWORD FILL
   wOrder             AS WORD         ' WORD
   wPreference        AS WORD         ' WORD
   pFlags             AS ASCIIZ PTR   ' PSTR
   pService           AS ASCIIZ PTR   ' PSTR
   pRegularExpression AS ASCIIZ PTR   ' PSTR
   pReplacement       AS ASCIIZ PTR   ' PSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_NAPTR_DATA = DNS_NAPTR_DATAW
#ELSE
   MACRO DNS_NAPTR_DATA = DNS_NAPTR_DATAA
#ENDIF

' // Size = 21 bytes
TYPE DNS_ATMA_DATA BYTE
   AddressType AS BYTE
   Address(%DNS_ATMA_MAX_ADDR_LENGTH - 1) AS BYTE
   ' //  E164 -- Null terminated string of less than
   ' //      DNS_ATMA_MAX_ADDR_LENGTH
   ' //
   ' //  For NSAP (AESA) BCD encoding of exactly
   ' //      DNS_ATMA_AESA_ADDR_LENGTH
END TYPE

' // Size = 40 bytes
TYPE DNS_TKEY_DATAW DWORD FILL
   pNameAlgorithm   AS WSTRINGZ PTR   ' PWSTR
   pAlgorithmPacket AS BYTE PTR       ' PBYTE
   pKey             AS BYTE PTR       ' PBYTE
   pOtherData       AS BYTE PTR       ' PBYTE
   dwCreateTime     AS DWORD
   dwExpireTime     AS DWORD
   wMode            AS WORD
   wError           AS WORD
   wKeyLength       AS WORD
   wOtherLength     AS WORD
   cAlgNameLength   AS BYTE           ' UCHAR
   bPacketPointers  AS LONG           ' BOOL
END TYPE

' // Size = 40 bytes
TYPE DNS_TKEY_DATAA DWORD FILL
   pNameAlgorithm   AS ASCIIZ PTR ' PSTR
   pAlgorithmPacket AS BYTE PTR   ' PBYTE
   pKey             AS BYTE PTR   ' PBYTE
   pOtherData       AS BYTE PTR   ' PBYTE
   dwCreateTime     AS DWORD
   dwExpireTime     AS DWORD
   wMode            AS WORD
   wError           AS WORD
   wKeyLength       AS WORD
   wOtherLength     AS WORD
   cAlgNameLength   AS BYTE       ' UCHAR
   bPacketPointers  AS LONG       ' BOOL
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_TKEY_DATA = DNS_TKEY_DATAW
#ELSE
   MACRO DNS_TKEY_DATA = DNS_TKEY_DATAA
#ENDIF

' // Size = 40 bytes
TYPE DNS_TSIG_DATAW DWORD FILL
   pNameAlgorithm   AS WSTRINGZ PTR   ' PWSTR
   pAlgorithmPacket AS BYTE PTR       ' PBYTE
   pSignature       AS BYTE PTR       ' PBYTE
   pOtherData       AS BYTE PTR       ' PBYTE
   i64CreateTime    AS QUAD           ' LONGLONG
   wFudgeTime       AS WORD           ' WORD
   wOriginalXid     AS WORD           ' WORD
   wError           AS WORD           ' WORD
   wSigLength       AS WORD           ' WORD
   wOtherLength     AS WORD           ' WORD
   cAlgNameLength   AS BYTE           ' UCHAR
   bPacketPointers  AS LONG           ' BOOL
END TYPE

' // Size = 40 bytes
TYPE DNS_TSIG_DATAA DWORD FILL
   pNameAlgorithm   AS ASCIIZ PTR ' PSTR
   pAlgorithmPacket AS BYTE PTR   ' PBYTE
   pSignature       AS BYTE PTR   ' PBYTE
   pOtherData       AS BYTE PTR   ' PBYTE
   i64CreateTime    AS QUAD       ' LONGLONG
   wFudgeTime       AS WORD       ' WORD
   wOriginalXid     AS WORD       ' WORD
   wError           AS WORD       ' WORD
   wSigLength       AS WORD       ' WORD
   wOtherLength     AS WORD       ' WORD
   cAlgNameLength   AS BYTE       ' UCHAR
   bPacketPointers  AS LONG       ' BOOL
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_TSIG_DATA = DNS_TSIG_DATAW
#ELSE
   MACRO DNS_TSIG_DATA = DNS_TSIG_DATAA
#ENDIF

'//
'//  MS only types -- only hit the wire in MS-MS zone transfer
'//

' // Size = 20 bytes
TYPE DNS_WINS_DATA DWORD
   dwMappingFlag    AS DWORD
   dwLookupTimeout  AS DWORD
   dwCacheTimeout   AS DWORD
   cWinsServerCount AS DWORD
   WinsServers(0)   AS DWORD   ' IP4_ADDRESS
END TYPE

' // Size = 16 bytes
TYPE DNS_WINSR_DATAW DWORD
   dwMappingFlag     AS DWORD
   dwLookupTimeout   AS DWORD
   dwCacheTimeout    AS DWORD
   pNameResultDomain AS WSTRINGZ PTR   ' PWSTR
END TYPE

' // Size = 16 bytes
TYPE DNS_WINSR_DATAA DWORD
   dwMappingFlag     AS DWORD
   dwLookupTimeout   AS DWORD
   dwCacheTimeout    AS DWORD
   pNameResultDomain AS ASCIIZ PTR   ' PSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_WINSR_DATA = DNS_WINSR_DATAW
#ELSE
   MACRO DNS_WINSR_DATA = DNS_WINSR_DATAA
#ENDIF

'//
'//  Length of non-fixed-length data types
'//

'#define DNS_TEXT_RECORD_LENGTH(StringCount) \
'            (FIELD_OFFSET(DNS_TXT_DATA, pStringArray) + ((StringCount) * sizeof(PCHAR)))

'#define DNS_NULL_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_NULL_DATA, Data) + (ByteCount))

'#define DNS_WKS_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_WKS_DATA, BitMask) + (ByteCount))

'#define DNS_WINS_RECORD_LENGTH(IpCount) \
'            (FIELD_OFFSET(DNS_WINS_DATA, WinsServers) + ((IpCount) * sizeof(IP4_ADDRESS)))

'#define DNS_KEY_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_KEY_DATA, Key) + (ByteCount))

'#define DNS_SIG_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_SIG_DATA, Signature) + (ByteCount))

'#define DNS_NSEC_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_NSEC_DATA, TypeBitMaps) + (ByteCount))

'#define DNS_DS_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_DS_DATA, Digest) + (ByteCount))

'#define DNS_OPT_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_OPT_DATA, Data) + (ByteCount))

'#define DNS_DHCID_RECORD_LENGTH(ByteCount) \
'            (FIELD_OFFSET(DNS_DHCID_DATA, DHCID) + (ByteCount))

'//
'//  Record flags
'//

' // Size = 4 bytes
TYPE DNS_RECORD_FLAGS DWORD
   Section  AS BIT * 2  IN DWORD
   Delete   AS BIT * 1
   CharSet  AS BIT * 2
   Unused   AS BIT * 3
   Reserved AS BIT * 24
END TYPE


'//
'//  Wire Record Sections
'//
'//  Useable both in record flags "Section" and as index into
'//  wire message header section counts.
'//

' enum DNS_SECTION
%DnsSectionQuestion  = 0
%DnsSectionAnswer    = 1
%DnsSectionAuthority = 2
%DnsSectionAddtional = 3

'//  Update message section names

%DnsSectionZone      = %DnsSectionQuestion
%DnsSectionPrereq    = %DnsSectionAnswer
%DnsSectionUpdate    = %DnsSectionAuthority


'//
'//  Record flags as bit flags
'//  These may be or'd together to set the fields
'//

'//  RR Section in packet

%DNSREC_SECTION      = &H00000003???

%DNSREC_QUESTION     = &H00000000???
%DNSREC_ANSWER       = &H00000001???
%DNSREC_AUTHORITY    = &H00000002???
%DNSREC_ADDITIONAL   = &H00000003???

'//  RR Section in packet (update)

%DNSREC_ZONE         = &H00000000???
%DNSREC_PREREQ       = &H00000001???
%DNSREC_UPDATE       = &H00000002???

'//  Delete RR (update or No-exist (prerequisite)

%DNSREC_DELETE       = &H00000004???
%DNSREC_NOEXIST      = &H00000004???


'//
'//  Record \ RR set structure
'//
'//  Note:  The dwReserved flag serves to insure that the substructures
'//  start on 64-bit boundaries.  Do NOT pack this structure, as the
'//  substructures may contain pointers or int64 values which are
'//  properly aligned unpacked.
'//

'#ifdef MIDL_PASS
'#define PDNS_RECORD     PVOID
'#else

' // Size = 4 bytes
UNION DNS_RECORD_UNION_Flags DWORD
   DW AS DWORD              ' // flags as DWORD
   S  AS DNS_RECORD_FLAGS   ' // flags as structure
END UNION

' // Size = 40 bytes
UNION DNS_RECORDW_UNION_Data DWORD
   A      AS DNS_A_DATA
   Soa    AS DNS_SOA_DATAW
   Ptr    AS DNS_PTR_DATAW
   Ns     AS DNS_PTR_DATAW
   Cname  AS DNS_PTR_DATAW
   Dname  AS DNS_PTR_DATAW
   Mb     AS DNS_PTR_DATAW
   Md     AS DNS_PTR_DATAW
   Mf     AS DNS_PTR_DATAW
   Mg     AS DNS_PTR_DATAW
   Mr     AS DNS_PTR_DATAW
   Minfo  AS DNS_MINFO_DATAW
   Rp     AS DNS_MINFO_DATAW
   Mx     AS DNS_MX_DATAW
   Afsdb  AS DNS_MX_DATAW
   Rt     AS DNS_MX_DATAW
   Hinfo  AS DNS_TXT_DATAW
   Isdn   AS DNS_TXT_DATAW
   Txt    AS DNS_TXT_DATAW
   X25    AS DNS_TXT_DATAW
   Null   AS DNS_NULL_DATA
   Wks    AS DNS_WKS_DATA
   AAAA   AS DNS_AAAA_DATA
   Key    AS DNS_KEY_DATA
   Sig    AS DNS_SIG_DATAW
   Atma   AS DNS_ATMA_DATA
   Nxt    AS DNS_NXT_DATAW
   Srv    AS DNS_SRV_DATAW
   Naptr  AS DNS_NAPTR_DATAW
   Opt    AS DNS_OPT_DATA
   Ds     AS DNS_DS_DATA
   Rrsig  AS DNS_RRSIG_DATAW
   Nsec   AS DNS_NSEC_DATAW
   Dnskey AS DNS_DNSKEY_DATA
   Tkey   AS DNS_TKEY_DATAW
   Tsig   AS DNS_TSIG_DATAW
   Wins   AS DNS_WINS_DATA
   WinsR  AS DNS_WINSR_DATAW
   Nbstat AS DNS_WINSR_DATAW
   DHCID  AS DNS_DHCID_DATA
END UNION

' // Size = 64 bytes
TYPE DNS_RECORDW DWORD FILL
   pNext       AS DNS_RECORDW PTR   ' struct _DnsRecordW *
   pName       AS WSTRINGZ PTR      ' PWSTR
   wType       AS WORD              ' WORD
   wDataLength AS WORD              ' WORD // Not referenced for DNS record types defined above.
   Flags       AS DNS_RECORD_UNION_Flags
   dwTtl       AS DWORD             ' DWORD
   dwReserved  AS DWORD             ' DWORD
   ' //  Record Data
   Data        AS DNS_RECORDW_UNION_Data
END TYPE

' // Size = 4 bytes
UNION DNS_RECORD_OPTW_UNION_Flags
   DW AS DWORD              ' DWORD // flags as DWORD
   S  AS DNS_RECORD_FLAGS   ' DNS_RECORD_FLAGS // flags as structure
END UNION

' // Size = 6 bytes
UNION DNS_RECORD_OPTW_UNION_Data
   Opt AS DNS_OPT_DATA
END UNION

' // Size = 32 bytes
TYPE DNS_RECORD_OPTW
   pNext        AS DNS_RECORDW PTR   ' struct _DnsRecordW *
   pName        AS WSTRINGZ PTR      ' PWSTR
   wType        AS WORD              ' WORD
   wDataLength  AS WORD              ' WORD // Not referenced for DNS record types defined above.
   DNS_RECORD_OPTW_UNION_Flags
   ExtHeader    AS DNS_HEADER_EXT    ' DNS_HEADER_EXT // TTL
   wPayloadSize AS WORD              ' WORD // dwReserved;
   wReserved    AS WORD              ' WORD
   ' //  Record Data
   DNS_RECORD_OPTW_UNION_Data
   alignment__  AS WORD              ' // To keep DWORD alignment
END TYPE

' // Size = 40 bytes
UNION DNS_RECORDA_UNION_Data DWORD
   A      AS DNS_A_DATA
   Soa    AS DNS_SOA_DATAA
   Ptr    AS DNS_PTR_DATAA
   Ns     AS DNS_PTR_DATAA
   Cname  AS DNS_PTR_DATAA
   Dname  AS DNS_PTR_DATAA
   Mb     AS DNS_PTR_DATAA
   Md     AS DNS_PTR_DATAA
   Mf     AS DNS_PTR_DATAA
   Mg     AS DNS_PTR_DATAA
   Mr     AS DNS_PTR_DATAA
   Minfo  AS DNS_MINFO_DATAA
   Rp     AS DNS_MINFO_DATAA
   Mx     AS DNS_MX_DATAA
   Afsdb  AS DNS_MX_DATAA
   Rt     AS DNS_MX_DATAA
   Hinfo  AS DNS_TXT_DATAA
   Isdn   AS DNS_TXT_DATAA
   Txt    AS DNS_TXT_DATAA
   X25    AS DNS_TXT_DATAA
   Null   AS DNS_NULL_DATA
   Wks    AS DNS_WKS_DATA
   AAAA   AS DNS_AAAA_DATA
   Key    AS DNS_KEY_DATA
   Sig    AS DNS_SIG_DATAA
   Atma   AS DNS_ATMA_DATA
   Nxt    AS DNS_NXT_DATAA
   Srv    AS DNS_SRV_DATAA
   Naptr  AS DNS_NAPTR_DATAA
   Opt    AS DNS_OPT_DATA
   Ds     AS DNS_DS_DATA
   Rrsig  AS DNS_RRSIG_DATAA
   Nsec   AS DNS_NSEC_DATAA
   Dnskey AS DNS_DNSKEY_DATA
   Tkey   AS DNS_TKEY_DATAA
   Tsig   AS DNS_TSIG_DATAA
   Wins   AS DNS_WINS_DATA
   WinsR  AS DNS_WINSR_DATAA
   Nbstat AS DNS_WINSR_DATAA
   DHCID  AS DNS_DHCID_DATA
END UNION

' // Size = 64 bytes
TYPE DNS_RECORDA DWORD FILL
   pNext       AS DNS_RECORDA PTR   ' struct _DnsRecordA *
   pName       AS ASCIIZ PTR        ' PSTR
   wType       AS WORD              ' WORD
   wDataLength AS WORD              ' WORD // Not referenced for DNS record types
                                    '      // defined above.
   Flags       AS DNS_RECORD_UNION_Flags
   dwTtl       AS DWORD             ' DWORD
   dwReserved  AS DWORD             ' DWORD
   ' //  Record Data
   Data        AS DNS_RECORDA_UNION_Data
END TYPE

' // Size = 4 bytes
UNION DNS_RECORD_OPTA_UNION_Flags
   DW AS DWORD              ' DWORD // flags as DWORD
   S  AS DNS_RECORD_FLAGS   ' DNS_RECORD_FLAGS // flags as structure
END UNION

' // Size = 6 bytes
UNION DNS_RECORD_OPTA_UNION_Data
   Opt AS DNS_OPT_DATA
END UNION

' // Size = 32 bytes
TYPE DNS_RECORD_OPTA
   pNext        AS DNS_RECORDA PTR   ' struct _DnsRecordA *
   pName        AS ASCIIZ PTR        ' PSTR
   wType        AS WORD              ' WORD
   wDataLength  AS WORD              ' WORD // Not referenced for DNS record types defined above.
   DNS_RECORD_OPTA_UNION_Flags
   ExtHeader    AS DNS_HEADER_EXT    ' DNS_HEADER_EXT // TTL
   wPayloadSize AS WORD              ' WORD // dwReserved;
   wReserved    AS WORD              ' WORD
   ' //  Record Data
   DNS_RECORD_OPTA_UNION_Data
   alignment__  AS WORD              ' // To keep DWORD alignment
END TYPE

#IF %DEF(%UNICODE)
   MACRO DNS_RECORD_OPT = DNS_RECORD_OPTW
   MACRO DNS_RECORD = DNS_RECORDW
#ELSE
   MACRO DNS_RECORD_OPT = DNS_RECORD_OPTA
   MACRO DNS_RECORD = DNS_RECORDA
#ENDIF

'//
'//  Header or fixed size of DNS_RECORD
'//

'#define DNS_RECORD_FIXED_SIZE       FIELD_OFFSET( DNS_RECORD, Data )
'#define SIZEOF_DNS_RECORD_HEADER    DNS_RECORD_FIXED_SIZE

'//
'//  Resource record set building
'//
'//  pFirst points to first record in list.
'//  pLast points to last record in list.
'//

' // Size = 8 bytes
TYPE DNS_RRSET DWORD
   pFirstRR AS DNS_RECORD PTR   ' PDNS_RECORD
   pLastRR  AS DNS_RECORD PTR   ' PDNS_RECORD
END TYPE


'//
'//  To init pFirst is NULL.
'//  But pLast points at the location of the pFirst pointer -- essentially
'//  treating the pFirst ptr as a DNS_RECORD.  (It is a DNS_RECORD with
'//  only a pNext field, but that's the only part we use.)
'//
'//  Then when the first record is added to the list, the pNext field of
'//  this dummy record (which corresponds to pFirst's value) is set to
'//  point at the first record.  So pFirst then properly points at the
'//  first record.
'//
'//  (This works only because pNext is the first field in a
'//  DNS_RECORD structure and hence casting a PDNS_RECORD ptr to
'//  PDNS_RECORD* and dereferencing yields its pNext field)
'//
'//  Use TERMINATE when have built RR set by grabbing records out of
'//  existing set.   This makes sure that at the end, the last RR is
'//  properly NULL terminated.
'//

'#define DNS_RRSET_INIT( rrset )                 \
'        {                                       \
'            PDNS_RRSET  _prrset = &(rrset);     \
'            _prrset->pFirstRR = NULL;           \
'            _prrset->pLastRR = (PDNS_RECORD) &_prrset->pFirstRR; \
'        }

'#define DNS_RRSET_ADD( rrset, pnewRR )          \
'        {                                       \
'            PDNS_RRSET  _prrset = &(rrset);     \
'            PDNS_RECORD _prrnew = (pnewRR);     \
'            _prrset->pLastRR->pNext = _prrnew;  \
'            _prrset->pLastRR = _prrnew;         \
'        }

'#define DNS_RRSET_TERMINATE( rrset )            \
'        {                                       \
'            PDNS_RRSET  _prrset = &(rrset);     \
'            _prrset->pLastRR->pNext = NULL;     \
'        }

'typedef
'VOID
'(WINAPI *DNS_PROXY_COMPLETION_ROUTINE) (
'    __in_opt void *completionContext,
'    __in DNS_STATUS status);

'SUB DNS_PROXY_COMPLETION_ROUTINE ( _
'   BYVAL completionContext AS DWORD _                   ' __in_opt void *completionContext
' , BYVAL status AS LONG _                               ' __in DNS_STATUS status
' )                                                      ' VOID

' enum DNS_PROXY_INFORMATION_TYPE
%DNS_PROXY_INFORMATION_DIRECT           = 0
%DNS_PROXY_INFORMATION_DEFAULT_SETTINGS = 1
%DNS_PROXY_INFORMATION_PROXY_NAME       = 2
%DNS_PROXY_INFORMATION_DOES_NOT_EXIST   = 3

' // Size = 12 bytes
TYPE DNS_PROXY_INFORMATION DWORD
   version              AS DWORD          ' __in ULONG version // Current version is 1
   proxyInformationType AS LONG           ' __out DNS_PROXY_INFORMATION_TYPE proxyInformationType
   proxyName            AS WSTRINGZ PTR   ' __out_opt PWSTR proxyName
END TYPE

'//
'//  Record set manipulation
'//

'//
'//  Record Copy
'//  Record copy functions also do conversion between character sets.
'//
'//  Note, it might be advisable to directly expose non-Ex copy
'//  functions _W, _A for record and set, to avoid exposing the
'//  conversion enum.
'//

' enum DNS_CHARSET
%DnsCharSetUnknown = 0
%DnsCharSetUnicode = 1
%DnsCharSetUtf8    = 2
%DnsCharSetAnsi    = 3

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
DECLARE FUNCTION DnsRecordCopyEx IMPORT "DNSAPI.DLL" ALIAS "DnsRecordCopyEx" ( _
   BYREF pRecord AS ANY _                               ' __in PDNS_RECORD pRecord
 , BYVAL CharSetIn AS LONG _                            ' __in DNS_CHARSET CharSetIn
 , BYVAL CharSetOut AS LONG _                           ' __in DNS_CHARSET CharSetOut
 ) AS DWORD                                             ' PDNS_RECORD

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsRecordSetCopyEx LIB "DnsApi.dll" _
    ALIAS "DnsRecordSetCopyEx" ( _
    BYVAL pRecordSet AS DNS_RECORD PTR, _
    BYVAL CharSetIn AS LONG, _
    BYVAL CharSetOut AS LONG _
    ) AS DWORD  ' DNS_RECORD PTR
#ELSE
DECLARE FUNCTION DnsRecordSetCopyEx IMPORT "DNSAPI.DLL" ALIAS "DnsRecordSetCopyEx" ( _
   BYREF pRecordSet AS ANY _                            ' __in PDNS_RECORD pRecordSet
 , BYVAL CharSetIn AS LONG _                            ' __in DNS_CHARSET CharSetIn
 , BYVAL CharSetOut AS LONG _                           ' __in DNS_CHARSET CharSetOut
 ) AS DWORD                                             ' PDNS_RECORD
#ENDIF

'#ifdef UNICODE
'#define DnsRecordCopy(pRR)  \
'        DnsRecordCopyEx( (pRR), DnsCharSetUnicode, DnsCharSetUnicode )
'#define DnsRecordSetCopy(pRR)  \
'        DnsRecordSetCopyEx( (pRR), DnsCharSetUnicode, DnsCharSetUnicode )
'#else
'#define DnsRecordCopy(pRR)  \
'        DnsRecordCopyEx( (pRR), DnsCharSetAnsi, DnsCharSetAnsi )
'#define DnsRecordSetCopy(pRR)  \
'        DnsRecordSetCopyEx( (pRR), DnsCharSetAnsi, DnsCharSetAnsi )
'#endif

#IF %DEF(%USEPBDECL)
#IF %DEF(%UNICODE)
MACRO DnsRecordCopy(pRR)=DnsRecordCopyEx((pRR), DnsCharSetUnicode, DnsCharSetUnicode)
MACRO DnsRecordSetCopy(pRR)=DnsRecordSetCopyEx((pRR), DnsCharSetUnicode, DnsCharSetUnicode)
#ELSE
MACRO DnsRecordCopy(pRR)=DnsRecordCopyEx((pRR), DnsCharSetAnsi, DnsCharSetAnsi)
MACRO DnsRecordSetCopy(pRR)=DnsRecordSetCopyEx((pRR), DnsCharSetAnsi, DnsCharSetAnsi)
#ENDIF
#ELSE
FUNCTION DnsRecordCopyW (BYREF pRR AS DNS_RECORDW) AS DWORD
   FUNCTION = DnsRecordCopyEx(pRR, %DnsCharSetUnicode, %DnsCharSetUnicode)
END FUNCTION

FUNCTION DnsRecordCopyA (BYREF pRR AS DNS_RECORDA) AS DWORD
   FUNCTION = DnsRecordCopyEx(pRR, %DnsCharSetAnsi, %DnsCharSetAnsi)
END FUNCTION

FUNCTION DnsRecordSetCopyW (BYREF pRR AS DNS_RECORDW) AS DWORD
   FUNCTION = DnsRecordSetCopyEx(pRR, %DnsCharSetUnicode, %DnsCharSetUnicode)
END FUNCTION

FUNCTION DnsRecordSetCopyA (BYREF pRR AS DNS_RECORDA) AS DWORD
   FUNCTION = DnsRecordSetCopyEx(pRR, %DnsCharSetAnsi, %DnsCharSetAnsi)
END FUNCTION

#IF %DEF(%UNICODE)
   MACRO DnsRecordCopy = DnsRecordCopyW
   MACRO DnsRecordSetCopy = DnsRecordSetCopyW
#ELSE
   MACRO DnsRecordCopy = DnsRecordCopyA
   MACRO DnsRecordSetCopy = DnsRecordSetCopyA
#ENDIF

#ENDIF
'//
'//  Record Compare
'//
'//  Note:  these routines only compare records of the SAME character set.
'//  (ANSI, unicode or UTF8).  Furthermore the routines assume the character
'//  set is indicated within the record.  If compare of user created, rather
'//  than DNS API created record lists is desired, then caller should use
'//  DnsRecordCopy API and compare copies.
'//

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
DECLARE FUNCTION DnsRecordCompare IMPORT "DNSAPI.DLL" ALIAS "DnsRecordCompare" ( _
   BYREF pRecord1 AS ANY _                              ' __in PDNS_RECORD pRecord1
 , BYREF pRecord2 AS ANY _                              ' __in PDNS_RECORD pRecord2
 ) AS LONG                                              ' BOOL

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
DECLARE FUNCTION DnsRecordSetCompare IMPORT "DNSAPI.DLL" ALIAS "DnsRecordSetCompare" ( _
   BYREF pRR1 AS ANY _                                  ' __inout  PDNS_RECORD pRR1
 , BYREF pRR2 AS ANY _                                  ' __inout  PDNS_RECORD pRR2
 , BYREF ppDiff1 AS ANY _                               ' __out    PDNS_RECORD * ppDiff1
 , BYREF ppDiff2 AS ANY _                               ' __out    PDNS_RECORD * ppDiff2
 ) AS LONG                                              ' BOOL

'//
'//  Detach next record set from record list
'//

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
DECLARE FUNCTION DnsRecordSetDetach IMPORT "DNSAPI.DLL" ALIAS "DnsRecordSetDetach" ( _
   BYREF pRecordList AS ANY _                           ' __inout  PDNS_RECORD pRecordList
 ) AS DWORD                                             ' PDNS_RECORD

'//
'//  Free structures returned from dnsapi.dll
'//
'//  Currently supported free structures:
'//      Flat -- flat structure, including those allocated by DnsQueryConfig()
'//      RecordList -- deep record list free, including sub-fields of DNS_RECORD;
'//          includes those returned by DnsQuery() or DnsRecordSetCopy()
'//

' enum DNS_FREE_TYPE
%DnsFreeFlat = 0
%DnsFreeRecordList = 1
%DnsFreeParsedMessageFields = 2

#IF %DEF(%USEPBDECL)
DECLARE SUB DnsFree LIB "DnsApi.dll" ALIAS "DnsFree" ( _
    pData    AS ANY, _  ' PVOID
    FreeType AS LONG _
    )
#ELSE
DECLARE SUB DnsFree IMPORT "DNSAPI.DLL" ALIAS "DnsFree" ( _
   BYVAL pData AS DWORD _                               ' __inout  PVOID         pData
 , BYVAL FreeType AS LONG _                             ' __in     DNS_FREE_TYPE FreeType
 )                                                      ' VOID
#ENDIF

'//
'//  Backward compatibility with Win2K, do not use for XP+ applications
'//
'//  To free record lists, code
'//      DnsFree( pRecordList, DnsFreeRecordList );
'//

'#define DnsFreeRecordListDeep   DnsFreeRecordList

' PDNS_RECORD declared AS ANY to allow to pass a DNS_RECORDA or DNS_RECORDW structure
'#if(_WIN32_WINNT >= 0x0501)
'#define DnsRecordListFree(p,t)  DnsFree(p,DnsFreeRecordList)
'#else
#IF %DEF(%USEPBDECL)
DECLARE SUB DnsRecordListFree LIB "DnsApi.dll" ALIAS "DnsRecordListFree" ( _
    pRecordList AS DNS_RECORD, _
    FreeType    AS LONG _
 )                                                      ' VOID
#ELSE
DECLARE SUB DnsRecordListFree IMPORT "DNSAPI.DLL" ALIAS "DnsRecordListFree" ( _
   BYREF pRecordList AS ANY _                           ' __inout  PDNS_RECORD pRecordList
 , BYVAL FreeType AS LONG _                             ' __in     DNS_FREE_TYPE FreeType
 )                                                      ' VOID
#ENDIF
'#endif /* _WIN32_WINNT >= 0x0501 */

'//
'//  DNS Query API
'//

'//
'//  Options for DnsQuery
'//

%DNS_QUERY_STANDARD                  = &H00000000???
%DNS_QUERY_ACCEPT_TRUNCATED_RESPONSE = &H00000001???
%DNS_QUERY_USE_TCP_ONLY              = &H00000002???
%DNS_QUERY_NO_RECURSION              = &H00000004???
%DNS_QUERY_BYPASS_CACHE              = &H00000008???

%DNS_QUERY_NO_WIRE_QUERY             = &H00000010???
%DNS_QUERY_NO_LOCAL_NAME             = &H00000020???
%DNS_QUERY_NO_HOSTS_FILE             = &H00000040???
%DNS_QUERY_NO_NETBT                  = &H00000080???

%DNS_QUERY_WIRE_ONLY                 = &H00000100???
%DNS_QUERY_RETURN_MESSAGE            = &H00000200???

%DNS_QUERY_MULTICAST_ONLY            = &H00000400???
%DNS_QUERY_NO_MULTICAST              = &H00000800???

%DNS_QUERY_TREAT_AS_FQDN             = &H00001000???
%DNS_QUERY_APPEND_MULTILABEL         = &H00800000???

%DNS_QUERY_DONT_RESET_TTL_VALUES     = &H00100000???
%DNS_QUERY_RESERVED                  = &Hf0000000???



'//  Backward compatibility with Win2K
'//  Do not use

%DNS_QUERY_CACHE_ONLY                = %DNS_QUERY_NO_WIRE_QUERY


#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsQuery_A LIB "DnsApi.dll" ALIAS "DnsQuery_A" ( _
    pszName        AS ASCIIZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsQuery_A IMPORT "DNSAPI.DLL" ALIAS "DnsQuery_A" ( _
   BYREF pszName AS ASCIIZ _                            ' __in      PCSTR           pszName
 , BYVAL wType AS WORD _                                ' __in      WORD            wType
 , BYVAL Options AS DWORD _                             ' __in      DWORD           Options
 , BYREF aipServers AS IP4_ARRAY _                      ' __in      PIP4_ARRAY      aipServers            OPTIONAL
 , BYREF ppQueryResults AS ANY _                        ' __inout   PDNS_RECORD *   ppQueryResults        OPTIONAL
 , BYREF pReserved AS ANY _                             ' __inout   PVOID *         pReserved             OPTIONAL
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsQuery_W LIB "DnsApi.dll" ALIAS "DnsQuery_W" ( _
    pszName        AS WSTRINGZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsQuery_W IMPORT "DNSAPI.DLL" ALIAS "DnsQuery_W" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in      PCWSTR          pszName
 , BYVAL wType AS WORD _                                ' __in      WORD            wType
 , BYVAL Options AS DWORD _                             ' __in      DWORD           Options
 , BYREF aipServers AS IP4_ARRAY _                      ' __in      PIP4_ARRAY      aipServers            OPTIONAL
 , BYREF ppQueryResults AS ANY _                        ' __inout   PDNS_RECORD *   ppQueryResults        OPTIONAL
 , BYREF pReserved AS ANY _                             ' __inout   PVOID *         pReserved             OPTIONAL
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO DnsQuery = DnsQuery_W
#ELSE
   MACRO DnsQuery = DnsQuery_A
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsQuery_UTF8 LIB "DnsApi.dll" ALIAS "DnsQuery_UTF8" ( _
    pszName        AS ASCIIZ, _
    BYVAL wType    AS WORD, _
    BYVAL Options  AS DWORD, _
    pExtra         AS ANY, _   ' PVOID
    ppQueryResults AS ANY, _   ' DNS_RECORD PTR PTR
    pReserved      AS ANY _    ' PVOID *
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsQuery_UTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsQuery_UTF8" ( _
   BYREF pszName AS ASCIIZ _                            ' __in      PCSTR           pszName
 , BYVAL wType AS WORD _                                ' __in      WORD            wType
 , BYVAL Options AS DWORD _                             ' __in      DWORD           Options
 , BYREF aipServers AS IP4_ARRAY _                      ' __in      PIP4_ARRAY      aipServers            OPTIONAL
 , BYREF ppQueryResults AS ANY _                        ' __inout   PDNS_RECORD *   ppQueryResults        OPTIONAL
 , BYREF pReserved AS ANY _                             ' __inout   PVOID *         pReserved             OPTIONAL
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

'//
'//  DNS Update API
'//
'//      DnsAcquireContextHandle
'//      DnsReleaseContextHandle
'//      DnsModifyRecordsInSet
'//      DnsReplaceRecordSet
'//

'//
'//  Update flags
'//

%DNS_UPDATE_SECURITY_USE_DEFAULT     = &H00000000???
%DNS_UPDATE_SECURITY_OFF             = &H00000010???
%DNS_UPDATE_SECURITY_ON              = &H00000020???
%DNS_UPDATE_SECURITY_ONLY            = &H00000100???
%DNS_UPDATE_CACHE_SECURITY_CONTEXT   = &H00000200???
%DNS_UPDATE_TEST_USE_LOCAL_SYS_ACCT  = &H00000400???
%DNS_UPDATE_FORCE_SECURITY_NEGO      = &H00000800???
%DNS_UPDATE_TRY_ALL_MASTER_SERVERS   = &H00001000???
%DNS_UPDATE_SKIP_NO_UPDATE_ADAPTERS  = &H00002000???
%DNS_UPDATE_REMOTE_SERVER            = &H00004000???
%DNS_UPDATE_RESERVED                 = &Hffff0000???


'//
'//  Note:  pCredentials paramater is currently respectively
'//  PSEC_WINNT_AUTH_IDENTITY_W or PSEC_WINNT_AUTH_IDENTITY_A.
'//  Using PVOID to obviate the need for including rpcdce.h
'//  in order to include this file and to leave open the
'//  possibility of alternative credential specifications in
'//  the future.
'//

DECLARE FUNCTION DnsAcquireContextHandleW IMPORT "DNSAPI.DLL" ALIAS "DnsAcquireContextHandle_W" ( _
   BYVAL CredentialFlags AS DWORD _                     ' __in  DWORD   CredentialFlags
 , BYREF pCredentials AS ANY _                          ' __in  PVOID   pCredentials
 , BYREF pContextHandle AS DWORD _                      ' __out PHANDLE pContextHandle
 ) AS LONG                                              ' DNS_STATUS

DECLARE FUNCTION DnsAcquireContextHandleA IMPORT "DNSAPI.DLL" ALIAS "DnsAcquireContextHandle_A" ( _
   BYVAL CredentialFlags AS DWORD _                     ' __in  DWORD   CredentialFlags
 , BYREF pCredentials AS ANY _                          ' __in  PVOID   pCredentials
 , BYREF pContextHandle AS DWORD _                      ' __out PHANDLE pContextHandle
 ) AS LONG                                              ' DNS_STATUS

#IF %DEF(%UNICODE)
   MACRO DnsAcquireContextHandle = DnsAcquireContextHandleW
#ELSE
   MACRO DnsAcquireContextHandle = DnsAcquireContextHandleA
#ENDIF

DECLARE SUB DnsReleaseContextHandle IMPORT "DNSAPI.DLL" ALIAS "DnsReleaseContextHandle" ( _
   BYVAL hContext AS DWORD _                            ' __in  HANDLE hContext
 )                                                      ' VOID

'//
'//  Dynamic Update API
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsModifyRecordsInSet_W LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_W" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsModifyRecordsInSet_W IMPORT "DNSAPI.DLL" ALIAS "DnsModifyRecordsInSet_W" ( _
   BYREF pAddRecords AS ANY _                           ' __in PDNS_RECORD pAddRecords
 , BYREF pDeleteRecords AS ANY _                        ' __in PDNS_RECORD pDeleteRecords
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext       OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList    OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsModifyRecordsInSet_A LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_A" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsModifyRecordsInSet_A IMPORT "DNSAPI.DLL" ALIAS "DnsModifyRecordsInSet_A" ( _
   BYREF pAddRecords AS ANY _                           ' __in PDNS_RECORD pAddRecords
 , BYREF pDeleteRecords AS ANY _                        ' __in PDNS_RECORD pDeleteRecords
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext       OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList    OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO DnsModifyRecordsInSet = DnsModifyRecordsInSet_W
#ELSE
   MACRO DnsModifyRecordsInSet = DnsModifyRecordsInSet_A
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsModifyRecordsInSet_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsModifyRecordsInSet_UTF8" ( _
    pAddRecords        AS DNS_RECORD, _
    pDeleteRecords     AS DNS_RECORD, _
    BYVAL Options      AS DWORD, _
    BYVAL hCredentials AS DWORD, _  ' HANDLE
    pExtraList         AS ANY, _    ' PVOID
    pReserved          AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsModifyRecordsInSet_UTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsModifyRecordsInSet_UTF8" ( _
   BYREF pAddRecords AS ANY _                           ' __in PDNS_RECORD pAddRecords
 , BYREF pDeleteRecords AS ANY _                        ' __in PDNS_RECORD pDeleteRecords
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext       OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList    OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsReplaceRecordSetW LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetW" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsReplaceRecordSetW IMPORT "DNSAPI.DLL" ALIAS "DnsReplaceRecordSetW" ( _
   BYREF pNewSet AS ANY _                               ' __in PDNS_RECORD pNewSet
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext    OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsReplaceRecordSetA LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetA" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsReplaceRecordSetA IMPORT "DNSAPI.DLL" ALIAS "DnsReplaceRecordSetA" ( _
   BYREF pNewSet AS ANY _                               ' __in PDNS_RECORD pNewSet
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext    OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO DnsReplaceRecordSet = DnsReplaceRecordSetW
#ELSE
   MACRO DnsReplaceRecordSet = DnsReplaceRecordSetA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsReplaceRecordSetUTF8 LIB "DnsApi.dll" _
    ALIAS "DnsReplaceRecordSetUTF8" ( _
    pReplaceSet    AS DNS_RECORD, _
    BYVAL Options  AS DWORD, _
    BYVAL hContext AS DWORD, _  ' HANDLE
    pExtraInfo     AS ANY, _    ' PVOID
    pReserved      AS ANY _     ' PVOID
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsReplaceRecordSetUTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsReplaceRecordSetUTF8" ( _
   BYREF pNewSet AS ANY _                               ' __in PDNS_RECORD pNewSet
 , BYVAL Options AS DWORD _                             ' __in DWORD       Options
 , BYVAL hContext AS DWORD _                            ' __in HANDLE      hContext    OPTIONAL
 , BYREF pServerList AS IP4_ARRAY _                     ' __in PIP4_ARRAY  pServerList OPTIONAL
 , BYVAL pReserved AS DWORD _                           ' __in PVOID       pReserved
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

'//
'//  DNS name validation
'//

' enum DNS_NAME_FORMAT
%DnsNameDomain        = 0
%DnsNameDomainLabel   = 1
%DnsNameHostnameFull  = 2
%DnsNameHostnameLabel = 3
%DnsNameWildcard      = 4
%DnsNameSrvRecord     = 5
%DnsNameValidateTld   = 6

DECLARE FUNCTION DnsValidateNameW IMPORT "DNSAPI.DLL" ALIAS "DnsValidateName_W" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR         pszName
 , BYVAL Format AS LONG _                               ' __in DNS_NAME_FORMAT Format
 ) AS LONG                                              ' DNS_STATUS

DECLARE FUNCTION DnsValidateNameA IMPORT "DNSAPI.DLL" ALIAS "DnsValidateName_A" ( _
   BYREF pszName AS ASCIIZ _                            ' __in LPCSTR          pszName
 , BYVAL Format AS LONG _                               ' __in DNS_NAME_FORMAT Format
 ) AS LONG                                              ' DNS_STATUS

#IF %DEF(%UNICODE)
   MACRO DnsValidateName = DnsValidateNameW
#ELSE
   MACRO DnsValidateName = DnsValidateNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsValidateName_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsValidateName_UTF8" ( _
    pszName AS ASCIIZ, _
    Format  AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsValidateName_UTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsValidateName_UTF8" ( _
   BYREF pszName AS ASCIIZ _                            ' __in LPCSTR          pszName
 , BYVAL Format AS LONG _                               ' __in DNS_NAME_FORMAT Format
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

'//
'// DNS server validation
'//

'// DNS server validation error codes
%DNS_VALSVR_ERROR_INVALID_ADDR               = &H01
%DNS_VALSVR_ERROR_INVALID_NAME               = &H02
%DNS_VALSVR_ERROR_UNREACHABLE                = &H03
%DNS_VALSVR_ERROR_NO_RESPONSE                = &H04
%DNS_VALSVR_ERROR_NO_AUTH                    = &H05
%DNS_VALSVR_ERROR_REFUSED                    = &H06

%DNS_VALSVR_ERROR_NO_TCP                     = &H10
%DNS_VALSVR_ERROR_UNKNOWN                    = &HFF

'// Winsock2.h must be included before windns.h to use the validate server function
#IF %DEF(%WINSOCK2_INC)
DECLARE FUNCTION DnsValidateServerStatus IMPORT "DNSAPI.DLL" ALIAS "DnsValidateServerStatus" ( _
   BYREF server AS SOCKADDR _                           ' __in  PSOCKADDR server
 , BYREF queryName AS WSTRINGZ _                        ' __in  PCWSTR    queryName
 , BYREF serverStatus AS DWORD _                        ' __out PDWORD    serverStatus
 ) AS LONG                                              ' DNS_STATUS
#ENDIF

'//
'//  DNS name comparison
'//

DECLARE FUNCTION DnsNameCompareA IMPORT "DNSAPI.DLL" ALIAS "DnsNameCompare_A" ( _
   BYREF pName1 AS ASCIIZ _                             ' __in LPSTR pName1
 , BYREF pName2 AS ASCIIZ _                             ' __in LPSTR pName2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DnsNameCompareW IMPORT "DNSAPI.DLL" ALIAS "DnsNameCompare_W" ( _
   BYREF pName1 AS WSTRINGZ _                           ' __in LPWSTR pName1
 , BYREF pName2 AS WSTRINGZ _                           ' __in LPWSTR pName2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO DnsNameCompare = DnsNameCompareW
#ELSE
   MACRO DnsNameCompare = DnsNameCompareA
#ENDIF

'//
'//  DNS message "roll-your-own" routines
'//

' // Size = 8 bytes
TYPE DNS_MESSAGE_BUFFER BYTE
   MessageHead    AS DNS_HEADER   ' DNS_HEADER
   MessageBody(0) AS BYTE         ' CHAR
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsWriteQuestionToBuffer_W LIB "DnsApi.dll" _
    ALIAS "DnsWriteQuestionToBuffer_W" ( _
    BYVAL pDnsBuffer        AS DNS_MESSAGE_BUFFER PTR, _
    pdwBufferSize           AS DWORD, _
    pszName                 AS WSTRINGZ, _
    BYVAL wType             AS WORD, _
    BYVAL Xid               AS WORD, _
    BYVAL fRecursionDesired AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION DnsWriteQuestionToBuffer_W IMPORT "DNSAPI.DLL" ALIAS "DnsWriteQuestionToBuffer_W" ( _
   BYREF pDnsBuffer AS DNS_MESSAGE_BUFFER _             ' __inout   PDNS_MESSAGE_BUFFER pDnsBuffer
 , BYREF pdwBufferSize AS DWORD _                       ' __inout   PDWORD              pdwBufferSize
 , BYREF pszName AS WSTRINGZ _                          ' __in      LPWSTR              pszName
 , BYVAL wType AS WORD _                                ' __in      WORD                wType
 , BYVAL Xid AS WORD _                                  ' __in      WORD                Xid
 , BYVAL fRecursionDesired AS LONG _                    ' __in      BOOL                fRecursionDesired
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO DnsWriteQuestionToBuffer = DnsWriteQuestionToBuffer_W

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsWriteQuestionToBuffer_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsWriteQuestionToBuffer_UTF8" ( _
    BYVAL pDnsBuffer        AS DNS_MESSAGE_BUFFER PTR, _
    pdwBufferSize           AS DWORD, _
    pszName                 AS ASCIIZ, _
    BYVAL wType             AS WORD, _
    BYVAL Xid               AS WORD, _
    BYVAL fRecursionDesired AS LONG _  ' BOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION DnsWriteQuestionToBuffer_UTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsWriteQuestionToBuffer_UTF8" ( _
   BYREF pDnsBuffer AS DNS_MESSAGE_BUFFER _             ' __inout   PDNS_MESSAGE_BUFFER pDnsBuffer
 , BYREF pdwBufferSize AS DWORD _                       ' __inout   PDWORD              pdwBufferSize
 , BYREF pszName AS ASCIIZ _                            ' __in      LPSTR               pszName
 , BYVAL wType AS WORD _                                ' __in      WORD                wType
 , BYVAL Xid AS WORD _                                  ' __in      WORD                Xid
 , BYVAL fRecursionDesired AS LONG _                    ' __in      BOOL                fRecursionDesired
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsExtractRecordsFromMessage_W LIB "DnsApi.dll" _
    ALIAS "DnsExtractRecordsFromMessage_W" ( _
    BYVAL pDnsBuffer     AS DNS_MESSAGE_BUFFER PTR, _
    BYVAL wMessageLength AS WORD, _
    ppRecord             AS ANY _  ' PDNS_RECORD *
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsExtractRecordsFromMessage_W IMPORT "DNSAPI.DLL" ALIAS "DnsExtractRecordsFromMessage_W" ( _
   BYREF pDnsBuffer AS DNS_MESSAGE_BUFFER _             ' __in  PDNS_MESSAGE_BUFFER pDnsBuffer
 , BYVAL wMessageLength AS WORD _                       ' __in  WORD                wMessageLength
 , BYREF ppRecord AS ANY _                              ' __out PDNS_RECORD *       ppRecord
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO DnsExtractRecordsFromMessage = DnsExtractRecordsFromMessage_W

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsExtractRecordsFromMessage_UTF8 LIB "DnsApi.dll" _
    ALIAS "DnsExtractRecordsFromMessage_UTF8" ( _
    BYVAL pDnsBuffer     AS DNS_MESSAGE_BUFFER PTR, _
    BYVAL wMessageLength AS WORD, _
    ppRecord             AS ANY _  ' PDNS_RECORD *
    ) AS LONG
#ELSE
DECLARE FUNCTION DnsExtractRecordsFromMessage_UTF8 IMPORT "DNSAPI.DLL" ALIAS "DnsExtractRecordsFromMessage_UTF8" ( _
   BYREF pDnsBuffer AS DNS_MESSAGE_BUFFER _             ' __in  PDNS_MESSAGE_BUFFER pDnsBuffer
 , BYVAL wMessageLength AS WORD _                       ' __in  WORD                wMessageLength
 , BYREF ppRecord AS ANY _                              ' __out PDNS_RECORD *       ppRecord
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DnsGetProxyInformation LIB "DnsApi.dll" _
    ALIAS "DnsGetProxyInformation" ( _
    hostName                AS WSTRINGZ, _
    proxyInformation        AS DNS_PROXY_INFORMATION, _
    defaultProxyInformation AS DNS_PROXY_INFORMATION, _
    BYVAL completionRoutine AS DWORD, _  ' DNS_PROXY_COMPLETION_ROUTINE
    completionContext       AS ANY _  ' void *
    ) AS DWORD
#ELSE
DECLARE FUNCTION DnsGetProxyInformation IMPORT "DNSAPI.DLL" ALIAS "DnsGetProxyInformation" ( _
   BYREF hostName AS WSTRINGZ _                         ' __in PCWSTR                           hostName
 , BYVAL proxyInformation AS LONG _                     ' __inout DNS_PROXY_INFORMATION         *proxyInformation
 , OPTIONAL BYREF defaultProxyInformation AS LONG _     ' __inout_opt DNS_PROXY_INFORMATION     *defaultProxyInformation
 , OPTIONAL BYVAL completionRoutine AS DWORD _          ' __in_opt DNS_PROXY_COMPLETION_ROUTINE completionRoutine
 , OPTIONAL BYVAL completionContext AS DWORD _          ' __in_opt void                         *completionContext
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB DnsFreeProxyName LIB "DnsApi.dll" ALIAS "DnsFreeProxyName" ( _
    proxyName AS WSTRINGZ)
#ELSE
DECLARE SUB DnsFreeProxyName IMPORT "DNSAPI.DLL" ALIAS "DnsFreeProxyName" ( _
   BYVAL proxyName AS WSTRINGZ PTR _                    ' __inout PWSTR proxyName
 )                                                      ' VOID
#ENDIF
