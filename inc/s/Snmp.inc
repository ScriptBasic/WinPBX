' ########################################################################################
' Microsoft Windows
' File: snmp.inc
' Contents: Definitions for SNMP development
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SNMP_INC = 1

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Type Definitions                                                     //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'#include <pshpack4.h>

' // Size = 12 bytes
TYPE AsnOctetString DWORD
   stream  AS BYTE PTR   ' BYTE *
   length  AS DWORD      ' UINT
   dynamic AS LONG       ' BOOL
END TYPE

' // Size = 8 bytes
TYPE AsnObjectIdentifier DWORD
   idLength AS DWORD       ' UINT
   ids      AS DWORD PTR   ' UINT *
END TYPE

'typedef LONG                    AsnInteger32;
'typedef ULONG                   AsnUnsigned32;
'typedef ULARGE_INTEGER          AsnCounter64;
'typedef AsnUnsigned32           AsnCounter32;
'typedef AsnUnsigned32           AsnGauge32;
'typedef AsnUnsigned32           AsnTimeticks;
'typedef AsnOctetString          AsnBits;
'typedef AsnOctetString          AsnSequence;
'typedef AsnOctetString          AsnImplicitSequence;
'typedef AsnOctetString          AsnIPAddress;
'typedef AsnOctetString          AsnNetworkAddress;
'typedef AsnOctetString          AsnDisplayString;
'typedef AsnOctetString          AsnOpaque;

MACRO AsnBits = AsnOctetString
MACRO AsnSequence = AsnOctetString
MACRO AsnImplicitSequence = AsnOctetString
MACRO AsnIPAddress = AsnOctetString
MACRO AsnNetworkAddress = AsnOctetString
MACRO AsnDisplayString = AsnOctetString
MACRO AsnOpaque = AsnOctetString

' // Size = 12 bytes
UNION AsnAny_UNION
   number     AS LONG                  ' AsnInteger32         // ASN_INTEGER
                                       '                      // ASN_INTEGER32
   unsigned32 AS DWORD                 ' AsnUnsigned32        // ASN_UNSIGNED32
   counter64  AS QUAD                  ' AsnCounter64         // ASN_COUNTER64
   string     AS AsnOctetString        ' AsnOctetString       // ASN_OCTETSTRING
   bits       AS AsnOctetString        ' AsnBits              // ASN_BITS
   object     AS AsnObjectIdentifier   ' AsnObjectIdentifier  // ASN_OBJECTIDENTIFIER
   sequence   AS AsnOctetString        ' AsnSequence          // ASN_SEQUENCE
   address    AS AsnOctetString        ' AsnIPAddress         // ASN_IPADDRESS
   counter    AS DWORD                 ' AsnCounter32         // ASN_COUNTER32
   gauge      AS DWORD                 ' AsnGauge32           // ASN_GAUGE32
   ticks      AS DWORD                 ' AsnTimeticks         // ASN_TIMETICKS
   arbitrary  AS AsnOctetString        ' AsnOpaque            // ASN_OPAQUE
END UNION

' // Size = 16 bytes
TYPE AsnAny DWORD
   asnType  AS BYTE   ' BYTE
   asnValue AS AsnAny_UNION
END TYPE

'typedef AsnObjectIdentifier     AsnObjectName;
'typedef AsnAny                  AsnObjectSyntax;

' // Size = 24 bytes
TYPE SnmpVarBind DWORD
   name  AS AsnObjectIdentifier
   value AS AsnAny
END TYPE

' // Size = 8 bytes
TYPE SnmpVarBindList DWORD
   list AS SnmpVarBind PTR   ' SnmpVarBind *
   len  AS DWORD             ' UINT
END TYPE

'#include <poppack.h>

#IF NOT %DEF(%WINSNMP_INC)

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// ASN/BER Base Types                                                        //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%ASN_UNIVERSAL                   = &H00
%ASN_APPLICATION                 = &H40
%ASN_CONTEXT                     = &H80
%ASN_PRIVATE                     = &HC0

%ASN_PRIMITIVE                   = &H00
%ASN_CONSTRUCTOR                 = &H20

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// PDU Type Values                                                           //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_PDU_GET               = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H0
%SNMP_PDU_GETNEXT           = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H1
%SNMP_PDU_RESPONSE          = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H2
%SNMP_PDU_SET               = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H3
%SNMP_PDU_V1TRAP            = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H4
%SNMP_PDU_GETBULK           = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H5
%SNMP_PDU_INFORM            = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H6
%SNMP_PDU_TRAP              = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H7

#ENDIF   ' #IF NOT %DEF(%WINSNMP_INC)

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Simple Syntax Values                                                 //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%ASN_INTEGER                = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H02
%ASN_BITS                   = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H03
%ASN_OCTETSTRING            = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H04
%ASN_NULL                   = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H05
%ASN_OBJECTIDENTIFIER       = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H06
%ASN_INTEGER32              = %ASN_INTEGER

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Constructor Syntax Values                                            //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%ASN_SEQUENCE               = %ASN_UNIVERSAL OR %ASN_CONSTRUCTOR OR &H10
%ASN_SEQUENCEOF             = %ASN_SEQUENCE

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Application Syntax Values                                            //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%ASN_IPADDRESS              = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H00
%ASN_COUNTER32              = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H01
%ASN_GAUGE32                = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H02
%ASN_TIMETICKS              = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H03
%ASN_OPAQUE                 = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H04
%ASN_COUNTER64              = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H06
%ASN_UINTEGER32             = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H07
%ASN_RFC2578_UNSIGNED32     = %ASN_GAUGE32

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Exception Conditions                                                 //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_EXCEPTION_NOSUCHOBJECT    = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H00
%SNMP_EXCEPTION_NOSUCHINSTANCE  = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H01
%SNMP_EXCEPTION_ENDOFMIBVIEW    = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H02

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Request Types (used in SnmpExtensionQueryEx)                         //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_EXTENSION_GET         = %SNMP_PDU_GET
%SNMP_EXTENSION_GET_NEXT    = %SNMP_PDU_GETNEXT
%SNMP_EXTENSION_GET_BULK    = %SNMP_PDU_GETBULK
%SNMP_EXTENSION_SET_TEST    = %ASN_PRIVATE OR %ASN_CONSTRUCTOR OR &H0
%SNMP_EXTENSION_SET_COMMIT  = %SNMP_PDU_SET
%SNMP_EXTENSION_SET_UNDO    = %ASN_PRIVATE OR %ASN_CONSTRUCTOR OR &H1
%SNMP_EXTENSION_SET_CLEANUP = %ASN_PRIVATE OR %ASN_CONSTRUCTOR OR &H2

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Error Codes                                                          //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_ERRORSTATUS_NOERROR              = 0
%SNMP_ERRORSTATUS_TOOBIG               = 1
%SNMP_ERRORSTATUS_NOSUCHNAME           = 2
%SNMP_ERRORSTATUS_BADVALUE             = 3
%SNMP_ERRORSTATUS_READONLY             = 4
%SNMP_ERRORSTATUS_GENERR               = 5
%SNMP_ERRORSTATUS_NOACCESS             = 6
%SNMP_ERRORSTATUS_WRONGTYPE            = 7
%SNMP_ERRORSTATUS_WRONGLENGTH          = 8
%SNMP_ERRORSTATUS_WRONGENCODING        = 9
%SNMP_ERRORSTATUS_WRONGVALUE           = 10
%SNMP_ERRORSTATUS_NOCREATION           = 11
%SNMP_ERRORSTATUS_INCONSISTENTVALUE    = 12
%SNMP_ERRORSTATUS_RESOURCEUNAVAILABLE  = 13
%SNMP_ERRORSTATUS_COMMITFAILED         = 14
%SNMP_ERRORSTATUS_UNDOFAILED           = 15
%SNMP_ERRORSTATUS_AUTHORIZATIONERROR   = 16
%SNMP_ERRORSTATUS_NOTWRITABLE          = 17
%SNMP_ERRORSTATUS_INCONSISTENTNAME     = 18

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMPv1 Trap Types                                                         //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_GENERICTRAP_COLDSTART            = 0
%SNMP_GENERICTRAP_WARMSTART            = 1
%SNMP_GENERICTRAP_LINKDOWN             = 2
%SNMP_GENERICTRAP_LINKUP               = 3
%SNMP_GENERICTRAP_AUTHFAILURE          = 4
%SNMP_GENERICTRAP_EGPNEIGHLOSS         = 5
%SNMP_GENERICTRAP_ENTERSPECIFIC        = 6

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Access Types                                                         //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_ACCESS_NONE                      = 0
%SNMP_ACCESS_NOTIFY                    = 1
%SNMP_ACCESS_READ_ONLY                 = 2
%SNMP_ACCESS_READ_WRITE                = 3
%SNMP_ACCESS_READ_CREATE               = 4

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP API Return Code Definitions                                          //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'#define SNMPAPI                                 INT
'#define SNMP_FUNC_TYPE                          WINAPI

%SNMPAPI_NOERROR                       = 1   ' %TRUE
%SNMPAPI_ERROR                         = 0   ' %FALSE

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Extension API Prototypes                                             //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'DECLARE FUNCTION SnmpExtensionInit IMPORT "INETMIB1.DLL" ALIAS "SnmpExtensionInit" ( _
'   BYVAL dwUptimeReference AS DWORD _                   ' DWORD                 dwUptimeReference
' , BYREF phSubagentTrapEvent AS DWORD _                 ' HANDLE *              phSubagentTrapEvent
' , BYREF pFirstSupportedRegion AS AsnObjectIdentifier _ ' AsnObjectIdentifier * pFirstSupportedRegion
' ) AS LONG                                              ' BOOL

'DECLARE FUNCTION SnmpExtensionInitEx IMPORT "INETMIB1.DLL" ALIAS "SnmpExtensionInitEx" ( _
'   BYREF pNextSupportedRegion AS AsnObjectIdentifier _  ' AsnObjectIdentifier * pNextSupportedRegion
' ) AS LONG                                              ' BOOL

'BOOL
'SNMP_FUNC_TYPE
'SnmpExtensionMonitor(
'    LPVOID            pAgentMgmtData
'    );

'DECLARE FUNCTION SnmpExtensionMonitor ( _
'   BYVAL pAgentMgmtData AS DWORD _                      ' LPVOID            pAgentMgmtData
' ) AS LONG                                              ' BOOL

'DECLARE FUNCTION SnmpExtensionQuery IMPORT "INETMIB1.DLL" ALIAS "SnmpExtensionQuery" ( _
'   BYVAL bPduType AS BYTE _                             ' BYTE              bPduType
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList * pVarBindList
' , BYREF pErrorStatus AS LONG _                         ' AsnInteger32 *    pErrorStatus
' , BYREF pErrorIndex AS LONG _                          ' AsnInteger32 *    pErrorIndex
' ) AS LONG                                              ' BOOL

'BOOL
'SNMP_FUNC_TYPE
'SnmpExtensionQueryEx(
'    UINT              nRequestType,
'    UINT              nTransactionId,
'    SnmpVarBindList * pVarBindList,
'    AsnOctetString *  pContextInfo,
'    AsnInteger32 *    pErrorStatus,
'    AsnInteger32 *    pErrorIndex
'    );

' Not exported by INETMIB1.DLL
'DECLARE FUNCTION SnmpExtensionQueryEx ( _
'   BYVAL nRequestType AS DWORD _                        ' UINT              nRequestType
' , BYVAL nTransactionId AS DWORD _                      ' UINT              nTransactionId
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList * pVarBindList
' , BYREF pContextInfo AS AsnOctetString _               ' AsnOctetString *  pContextInfo
' , BYREF pErrorStatus AS LONG _                         ' AsnInteger32 *    pErrorStatus
' , BYREF pErrorIndex AS LONG _                          ' AsnInteger32 *    pErrorIndex
' ) AS LONG                                              ' BOOL

'DECLARE FUNCTION SnmpExtensionTrap IMPORT "INETMIB1.DLL" ALIAS "SnmpExtensionTrap" ( _
'   BYREF pEnterpriseOid AS AsnObjectIdentifier _        ' AsnObjectIdentifier * pEnterpriseOid
' , BYREF pGenericTrapId AS LONG _                       ' AsnInteger32 *        pGenericTrapId
' , BYREF pSpecificTrapId AS LONG _                      ' AsnInteger32 *        pSpecificTrapId
' , BYREF pTimeStamp AS DWORD _                          ' AsnTimeticks *        pTimeStamp
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList *     pVarBindList
' ) AS LONG                                              ' BOOL

'VOID
'SNMP_FUNC_TYPE
'SnmpExtensionClose(
'    );

'DECLARE SUB SnmpExtensionClose ()

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Extension API Type Definitions                                       //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'FUNCTION PFNSNMPEXTENSIONINIT ( _
'   BYVAL dwUptimeReference AS DWORD _                   ' DWORD                 dwUptimeReference
' , BYREF phSubagentTrapEvent AS DWORD _                 ' HANDLE *              phSubagentTrapEvent
' , BYREF pFirstSupportedRegion AS AsnObjectIdentifier _ ' AsnObjectIdentifier * pFirstSupportedRegion
' ) AS LONG                                              ' BOOL

'FUNCTION PFNSNMPEXTENSIONINITEX ( _
'   BYREF pNextSupportedRegion AS AsnObjectIdentifier _  ' AsnObjectIdentifier * pNextSupportedRegion
' ) AS LONG                                              ' BOOL

'FUNCTION PFNSNMPEXTENSIONMONITOR ( _
'   BYVAL pAgentMgmtData AS DWORD _                      ' LPVOID            pAgentMgmtData
' ) AS LONG                                              ' BOOL

'FUNCTION PFNSNMPEXTENSIONQUERY ( _
'   BYVAL bPduType AS BYTE _                             ' BYTE              bPduType
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList * pVarBindList
' , BYREF pErrorStatus AS LONG _                         ' AsnInteger32 *    pErrorStatus
' , BYREF pErrorIndex AS LONG _                          ' AsnInteger32 *    pErrorIndex
' ) AS LONG                                              ' BOOL

'FUNCTION PFNSNMPEXTENSIONQUERYEX ( _
'   BYVAL nRequestType AS DWORD _                        ' UINT              nRequestType
' , BYVAL nTransactionId AS DWORD _                      ' UINT              nTransactionId
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList * pVarBindList
' , BYREF pContextInfo AS AsnOctetString _               ' AsnOctetString *  pContextInfo
' , BYREF pErrorStatus AS LONG _                         ' AsnInteger32 *    pErrorStatus
' , BYREF pErrorIndex AS LONG _                          ' AsnInteger32 *    pErrorIndex
' ) AS LONG                                              ' BOOL

'FUNCTION PFNSNMPEXTENSIONTRAP ( _
'   BYREF pEnterpriseOid AS AsnObjectIdentifier _        ' AsnObjectIdentifier * pEnterpriseOid
' , BYREF pGenericTrapId AS LONG _                       ' AsnInteger32 *        pGenericTrapId
' , BYREF pSpecificTrapId AS LONG _                      ' AsnInteger32 *        pSpecificTrapId
' , BYREF pTimeStamp AS DWORD _                          ' AsnTimeticks *        pTimeStamp
' , BYREF pVarBindList AS SnmpVarBindList _              ' SnmpVarBindList *     pVarBindList
' ) AS LONG                                              ' BOOL

'SUB PFNSNMPEXTENSIONCLOSE ()


'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP API Prototypes                                                       //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION SnmpUtilOidCpy IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidCpy" ( _
   BYREF pOidDst AS AsnObjectIdentifier _               ' __out AsnObjectIdentifier * pOidDst
 , BYREF pOidSrc AS AsnObjectIdentifier _               ' __in  AsnObjectIdentifier * pOidSrc
 ) AS LONG                                              ' INT

DECLARE FUNCTION SnmpUtilOidAppend IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidAppend" ( _
   BYREF pOidDst AS AsnObjectIdentifier _               ' __in_out AsnObjectIdentifier * pOidDst
 , BYREF pOidSrc AS AsnObjectIdentifier _               ' __in AsnObjectIdentifier * pOidSrc
 ) AS LONG                                              ' INT

DECLARE FUNCTION SnmpUtilOidNCmp IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidNCmp" ( _
   BYREF pOid1 AS AsnObjectIdentifier _                 ' __in AsnObjectIdentifier * pOid1
 , BYREF pOid2 AS AsnObjectIdentifier _                 ' __in AsnObjectIdentifier * pOid2
 , BYVAL nSubIds AS DWORD _                             ' __in UINT                  nSubIds
 ) AS LONG                                              ' INT

DECLARE FUNCTION SnmpUtilOidCmp IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidCmp" ( _
   BYREF pOid1 AS AsnObjectIdentifier _                 ' __in AsnObjectIdentifier * pOid1
 , BYREF pOid2 AS AsnObjectIdentifier _                 ' __in AsnObjectIdentifier * pOid2
 ) AS LONG                                              ' INT

DECLARE SUB SnmpUtilOidFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidFree" ( _
   BYREF pOid AS AsnObjectIdentifier _                  ' __in_out AsnObjectIdentifier * pOid
 )                                                      ' void

DECLARE FUNCTION SnmpUtilOctetsCmp IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOctetsCmp" ( _
   BYREF pOctets1 AS AsnOctetString _                   ' __in AsnOctetString * pOctets1
 , BYREF pOctets2 AS AsnOctetString _                   ' __in AsnOctetString * pOctets2
 ) AS LONG                                              ' INT

DECLARE FUNCTION SnmpUtilOctetsNCmp IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOctetsNCmp" ( _
   BYREF pOctets1 AS AsnOctetString _                   ' __in AsnOctetString * pOctets1
 , BYREF pOctets2 AS AsnOctetString _                   ' __in AsnOctetString * pOctets2
 , BYVAL nChars AS DWORD _                              ' __in UINT             nChars
 ) AS LONG                                              ' INT

DECLARE FUNCTION SnmpUtilOctetsCpy IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOctetsCpy" ( _
   BYREF pOctetsDst AS AsnOctetString _                 ' __out AsnOctetString * pOctetsDst
 , BYREF pOctetsSrc AS AsnOctetString _                 ' __in  AsnOctetString * pOctetsSrc
 ) AS LONG                                              ' INT

DECLARE SUB SnmpUtilOctetsFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOctetsFree" ( _
   BYREF pOctets AS AsnOctetString _                    ' __in AsnOctetString * pOctets
 )                                                      ' void

DECLARE FUNCTION SnmpUtilAsnAnyCpy IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilAsnAnyCpy" ( _
   BYREF pAnyDst AS AsnAny _                            ' __out AsnAny * pAnyDst
 , BYREF pAnySrc AS AsnAny _                            ' __in  AsnAny * pAnySrc
 ) AS LONG                                              ' INT

DECLARE SUB SnmpUtilAsnAnyFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilAsnAnyFree" ( _
   BYREF pAny AS AsnAny _                               ' __in AsnAny * pAny
 )                                                      ' void

DECLARE FUNCTION SnmpUtilVarBindCpy IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilVarBindCpy" ( _
   BYREF pVbDst AS SnmpVarBind _                        ' __out SnmpVarBind * pVbDst
 , BYREF pVbSrc AS SnmpVarBind _                        ' __in  SnmpVarBind * pVbSrc
 ) AS LONG                                              ' INT

DECLARE SUB SnmpUtilVarBindFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilVarBindFree" ( _
   BYREF pVb AS SnmpVarBind _                           ' __in_out SnmpVarBind * pVb
 )                                                      ' void

DECLARE FUNCTION SnmpUtilVarBindListCpy IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilVarBindListCpy" ( _
   BYREF pVblDst AS SnmpVarBindList _                   ' __out SnmpVarBindList * pVblDst
 , BYREF pVblSrc AS SnmpVarBindList _                   ' __in  SnmpVarBindList * pVblSrc
 ) AS LONG                                              ' INT

DECLARE SUB SnmpUtilVarBindListFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilVarBindListFree" ( _
   BYREF pVbl AS SnmpVarBindList _                      ' __in_out SnmpVarBindList * pVbl
 )                                                      ' void

DECLARE SUB SnmpUtilMemFree IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilMemFree" ( _
   BYVAL pMem AS DWORD _                                ' __in_out LPVOID pMem
 )                                                      ' void

DECLARE FUNCTION SnmpUtilMemAlloc IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilMemAlloc" ( _
   BYVAL nBytes AS DWORD _                              ' __in UINT nBytes
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION SnmpUtilMemReAlloc IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilMemReAlloc" ( _
   BYVAL pMem AS DWORD _                                ' __in LPVOID pMem
 , BYVAL nBytes AS DWORD _                              ' __in UINT nBytes
 ) AS DWORD                                             ' LPVOID

DECLARE FUNCTION SnmpUtilOidToA IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilOidToA" ( _
   BYREF Oid AS AsnObjectIdentifier _                   ' __in AsnObjectIdentifier *Oid
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION SnmpUtilIdsToA IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilIdsToA" ( _
   BYREF Ids AS DWORD _                                 ' __in UINT *Ids [array]
 , BYVAL IdLength AS DWORD _                            ' __in UINT IdLength
 ) AS DWORD                                             ' LPSTR

DECLARE SUB SnmpUtilPrintOid IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilPrintOid" ( _
   BYREF Oid AS AsnObjectIdentifier _                   ' __in AsnObjectIdentifier *Oid
 )                                                      ' void

DECLARE SUB SnmpUtilPrintAsnAny IMPORT "SNMPAPI.DLL" ALIAS "SnmpUtilPrintAsnAny" ( _
   BYREF pAny AS AsnAny _                               ' __in AsnAny *pAny
 )                                                      ' void

DECLARE FUNCTION SnmpSvcGetUptime IMPORT "SNMPAPI.DLL" ALIAS "SnmpSvcGetUptime" ( _
 ) AS DWORD                                             ' DWORD

DECLARE SUB SnmpSvcSetLogLevel IMPORT "SNMPAPI.DLL" ALIAS "SnmpSvcSetLogLevel" ( _
   BYVAL nLogLevel AS LONG _                            ' __in INT nLogLevel
 )                                                      ' void

DECLARE SUB SnmpSvcSetLogType IMPORT "SNMPAPI.DLL" ALIAS "SnmpSvcSetLogType" ( _
   BYVAL nLogLevel AS LONG _                            ' __in INT nLogLevel
 )                                                      ' void

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Debugging Definitions                                                //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_LOG_SILENT                 = &H0
%SNMP_LOG_FATAL                  = &H1
%SNMP_LOG_ERROR                  = &H2
%SNMP_LOG_WARNING                = &H3
%SNMP_LOG_TRACE                  = &H4
%SNMP_LOG_VERBOSE                = &H5

%SNMP_OUTPUT_TO_CONSOLE          = &H1
%SNMP_OUTPUT_TO_LOGFILE          = &H2
%SNMP_OUTPUT_TO_EVENTLOG         = &H4  ' // no longer supported
%SNMP_OUTPUT_TO_DEBUGGER         = &H8

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// SNMP Debugging Prototypes                                                 //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'VOID
'SNMP_FUNC_TYPE
'SnmpUtilDbgPrint(
'    IN INT nLogLevel,   // see log levels above...
'    IN LPSTR szFormat,
'    IN ...
'    );

'#if DBG
'#define SNMPDBG(_x_)                    SnmpUtilDbgPrint _x_
'#else
'#define SNMPDBG(_x_)
'#endif

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// Miscellaneous definitions                                                 //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'#define DEFINE_SIZEOF(Array)        (sizeof(Array)/sizeof((Array)[0]))
'#define DEFINE_OID(SubIdArray)      {DEFINE_SIZEOF(SubIdArray),(SubIdArray)}
'#define DEFINE_NULLOID()            {0,NULL}
'#define DEFINE_NULLOCTETS()         {NULL,0,FALSE}

%DEFAULT_SNMP_PORT_UDP     = 161
%DEFAULT_SNMP_PORT_IPX     = 36879
%DEFAULT_SNMPTRAP_PORT_UDP = 162
%DEFAULT_SNMPTRAP_PORT_IPX = 36880

%SNMP_MAX_OID_LEN          = 128

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// API Error Code Definitions                                                //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_MEM_ALLOC_ERROR          = 1
%SNMP_BERAPI_INVALID_LENGTH    = 10
%SNMP_BERAPI_INVALID_TAG       = 11
%SNMP_BERAPI_OVERFLOW          = 12
%SNMP_BERAPI_SHORT_BUFFER      = 13
%SNMP_BERAPI_INVALID_OBJELEM   = 14
%SNMP_PDUAPI_UNRECOGNIZED_PDU  = 20
%SNMP_PDUAPI_INVALID_ES        = 21
%SNMP_PDUAPI_INVALID_GT        = 22
%SNMP_AUTHAPI_INVALID_VERSION  = 30
%SNMP_AUTHAPI_INVALID_MSG_TYPE = 31
%SNMP_AUTHAPI_TRIV_AUTH_FAILED = 32

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// Support for old definitions (support disabled via SNMPSTRICT)             //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'#IF NOT %DEF(%SNMPSTRICT)

'#define SNMP_oidcpy                     SnmpUtilOidCpy
'#define SNMP_oidappend                  SnmpUtilOidAppend
'#define SNMP_oidncmp                    SnmpUtilOidNCmp
'#define SNMP_oidcmp                     SnmpUtilOidCmp
'#define SNMP_oidfree                    SnmpUtilOidFree

'#define SNMP_CopyVarBindList            SnmpUtilVarBindListCpy
'#define SNMP_FreeVarBindList            SnmpUtilVarBindListFree
'#define SNMP_CopyVarBind                SnmpUtilVarBindCpy
'#define SNMP_FreeVarBind                SnmpUtilVarBindFree

'#define SNMP_printany                   SnmpUtilPrintAsnAny

'#define SNMP_free                       SnmpUtilMemFree
'#define SNMP_malloc                     SnmpUtilMemAlloc
'#define SNMP_realloc                    SnmpUtilMemReAlloc

'#define SNMP_DBG_free                   SnmpUtilMemFree
'#define SNMP_DBG_malloc                 SnmpUtilMemAlloc
'#define SNMP_DBG_realloc                SnmpUtilMemReAlloc

'#define ASN_RFC1155_IPADDRESS           ASN_IPADDRESS
'#define ASN_RFC1155_COUNTER             ASN_COUNTER32
'#define ASN_RFC1155_GAUGE               ASN_GAUGE32
'#define ASN_RFC1155_TIMETICKS           ASN_TIMETICKS
'#define ASN_RFC1155_OPAQUE              ASN_OPAQUE
'#define ASN_RFC1213_DISPSTRING          ASN_OCTETSTRING

'#define ASN_RFC1157_GETREQUEST          SNMP_PDU_GET
'#define ASN_RFC1157_GETNEXTREQUEST      SNMP_PDU_GETNEXT
'#define ASN_RFC1157_GETRESPONSE         SNMP_PDU_RESPONSE
'#define ASN_RFC1157_SETREQUEST          SNMP_PDU_SET
'#define ASN_RFC1157_TRAP                SNMP_PDU_V1TRAP

'#define ASN_CONTEXTSPECIFIC             ASN_CONTEXT
'#define ASN_PRIMATIVE                   ASN_PRIMITIVE

'#define RFC1157VarBindList              SnmpVarBindList
'#define RFC1157VarBind                  SnmpVarBind
'#define AsnInteger                      AsnInteger32
'#define AsnCounter                      AsnCounter32
'#define AsnGauge                        AsnGauge32
'#define ASN_UNSIGNED32                  ASN_UINTEGER32

'#ENDIF   ' // SNMPSTRICT

#IF NOT %DEF(%SNMPSTRICT)

%ASN_RFC1155_IPADDRESS           = %ASN_IPADDRESS
%ASN_RFC1155_COUNTER             = %ASN_COUNTER32
%ASN_RFC1155_GAUGE               = %ASN_GAUGE32
%ASN_RFC1155_TIMETICKS           = %ASN_TIMETICKS
%ASN_RFC1155_OPAQUE              = %ASN_OPAQUE
%ASN_RFC1213_DISPSTRING          = %ASN_OCTETSTRING

%ASN_RFC1157_GETREQUEST          = %SNMP_PDU_GET
%ASN_RFC1157_GETNEXTREQUEST      = %SNMP_PDU_GETNEXT
%ASN_RFC1157_GETRESPONSE         = %SNMP_PDU_RESPONSE
%ASN_RFC1157_SETREQUEST          = %SNMP_PDU_SET
%ASN_RFC1157_TRAP                = %SNMP_PDU_V1TRAP

%ASN_CONTEXTSPECIFIC             = %ASN_CONTEXT
%ASN_PRIMATIVE                   = %ASN_PRIMITIVE

MACRO RFC1157VarBindList         = SnmpVarBindList
MACRO RFC1157VarBind             = SnmpVarBind
%ASN_UNSIGNED32                  = %ASN_UINTEGER32

#ENDIF
