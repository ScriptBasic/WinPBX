' ########################################################################################
' Microsoft Windows
' File: WinSnmp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'/* WinSNMP.h */
'/* Copyright (C) 1993-1999 Microsoft Corporation */
'/* v1.0 - Sep 13, 1993 */
'/* v1.1 - Jun 12, 1994 */
'/* v2.0 - Nov  1, 1997 */
'/*      - Nov 17, 1997: inc limits.h, tests for ULONG/UINT_MAX */
'/*      - Mar 23, 1998: fixed typo in "lpClientData" */

'/* Questions/comments to Bob Natale, bnatale@acecomm.com */

#INCLUDE THIS ONCE
%WINSNMP_INC = 1

#INCLUDE ONCE "windows.inc"

'#include <limits.h>

'/* WinSNMP API Type Definitions  */
'typedef  HANDLE        HSNMP_SESSION,      FAR *LPHSNMP_SESSION;
'typedef  HANDLE        HSNMP_ENTITY,       FAR *LPHSNMP_ENTITY;
'typedef  HANDLE        HSNMP_CONTEXT,      FAR *LPHSNMP_CONTEXT;
'typedef  HANDLE        HSNMP_PDU,          FAR *LPHSNMP_PDU;
'typedef  HANDLE        HSNMP_VBL,          FAR *LPHSNMP_VBL;
'typedef unsigned char    smiBYTE,          FAR *smiLPBYTE;

'/* SNMP-related types */
'#if ULONG_MAX == 4294967295U
'typedef signed long      smiINT,           FAR *smiLPINT;
'typedef smiINT           smiINT32,         FAR *smiLPINT32;
'typedef unsigned long    smiUINT32,        FAR *smiLPUINT32;
'#elif UINT_MAX == 4294967295U
'typedef int              smiINT,           FAR *smiLPINT;
'typedef smiINT           smiINT32,         FAR *smiLPINT32;
'typedef unsigned int     smiUINT32,        FAR *smiLPUINT32;
'#else
'#error can not define smiINT and smiUINT
'#endif

' // Size = 8 bytes
TYPE smiOCTETS DWORD
   len AS DWORD      ' smiUINT32
   ptr AS BYTE PTR   ' smiLPBYTE
END TYPE

' // Size = 8 bytes
TYPE smiOID DWORD
   len AS DWORD       ' smiUINT32
   ptr AS DWORD PTR   ' smiLPUINT32
END TYPE

'typedef const smiOID                       FAR *smiLPCOID;
'typedef smiOCTETS        smiIPADDR,        FAR *smiLPIPADDR;
'typedef smiUINT32        smiCNTR32,        FAR *smiLPCNTR32;
'typedef smiUINT32        smiGAUGE32,       FAR *smiLPGAUGE32;
'typedef smiUINT32        smiTIMETICKS,     FAR *smiLPTIMETICKS;
'typedef smiOCTETS        smiOPAQUE,        FAR *smiLPOPAQUE;
'typedef smiOCTETS        smiNSAPADDR,      FAR *smiLPNSAPADDR;

' // Size = 8 bytes
TYPE smiCNTR64 DWORD
   hipart AS DWORD   ' smiUINT32
   lopart AS DWORD   ' smiUINT32
END TYPE

'/* ASN/BER Base Types */
'/* (used in forming SYNTAXes and certain SNMP types/values) */

%ASN_UNIVERSAL              = &H00
%ASN_APPLICATION            = &H40
%ASN_CONTEXT                = &H80
%ASN_PRIVATE                = &HC0
%ASN_PRIMITIVE              = &H00
%ASN_CONSTRUCTOR            = &H20

'/* SNMP ObjectSyntax Values */
%SNMP_SYNTAX_SEQUENCE       = %ASN_UNIVERSAL OR %ASN_CONSTRUCTOR OR &H10

'/* These values are used in the "syntax" member of the smiVALUE structure which follows */
%SNMP_SYNTAX_INT            = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H02
%SNMP_SYNTAX_BITS           = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H03
%SNMP_SYNTAX_OCTETS         = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H04
%SNMP_SYNTAX_NULL           = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H05
%SNMP_SYNTAX_OID            = %ASN_UNIVERSAL OR %ASN_PRIMITIVE OR &H06
%SNMP_SYNTAX_INT32          = %SNMP_SYNTAX_INT
%SNMP_SYNTAX_IPADDR         = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H00
%SNMP_SYNTAX_CNTR32         = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H01
%SNMP_SYNTAX_GAUGE32        = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H02
%SNMP_SYNTAX_TIMETICKS      = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H03
%SNMP_SYNTAX_OPAQUE         = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H04
%SNMP_SYNTAX_NSAPADDR       = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H05
%SNMP_SYNTAX_CNTR64         = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H06
%SNMP_SYNTAX_UINT32         = %ASN_APPLICATION OR %ASN_PRIMITIVE OR &H07
%SNMP_SYNTAX_UNSIGNED32     = %SNMP_SYNTAX_GAUGE32

'/* Exception conditions in response PDUs for SNMPv2 */
%SNMP_SYNTAX_NOSUCHOBJECT   = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H00
%SNMP_SYNTAX_NOSUCHINSTANCE = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H01
%SNMP_SYNTAX_ENDOFMIBVIEW   = %ASN_CONTEXT OR %ASN_PRIMITIVE OR &H02

' // Size = 8 bytes
UNION smiVALUE_UNION DWORD
   sNumber AS INTEGER     ' smiINT
   uNumber AS DWORD       ' smiUINT32
   hNumber AS QUAD        ' smiCNTR64
   string  AS smiOCTETS   ' smiOCTETS
   oid     AS smiOID      ' smiOID
   empty   AS BYTE        ' smiBYTE
END UNION

' // Size = 12 bytes
TYPE smiVALUE DWORD
   syntax AS DWORD   ' smiUINT32
   value  AS smiVALUE_UNION
END TYPE

'/* SNMP Limits   */
%MAXOBJIDSIZE    = 128  ' /* Max number of components in an OID */
%MAXOBJIDSTRSIZE = 1408 ' /* Max len of decoded MAXOBJIDSIZE OID */

'/* PDU Type Values */
%SNMP_PDU_GET               = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H0
%SNMP_PDU_GETNEXT           = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H1
%SNMP_PDU_RESPONSE          = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H2
%SNMP_PDU_SET               = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H3

'/* SNMP_PDU_V1TRAP is obsolete in SNMPv2 */
%SNMP_PDU_V1TRAP            = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H4
%SNMP_PDU_GETBULK           = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H5
%SNMP_PDU_INFORM            = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H6
%SNMP_PDU_TRAP              = %ASN_CONTEXT OR %ASN_CONSTRUCTOR OR &H7

'/*Constants for SnmpListenEx*/
%SNMPLISTEN_USEENTITY_ADDR  = 0  ' /*Use entity address*/
%SNMPLISTEN_ALL_ADDR        = 1  ' /*Use any address based on address family and port no*/

'/* SNMPv1 Trap Values */
'/* (These values might be superfluous wrt WinSNMP applications) */
%SNMP_TRAP_COLDSTART            = 0
%SNMP_TRAP_WARMSTART            = 1
%SNMP_TRAP_LINKDOWN             = 2
%SNMP_TRAP_LINKUP               = 3
%SNMP_TRAP_AUTHFAIL             = 4
%SNMP_TRAP_EGPNEIGHBORLOSS      = 5
%SNMP_TRAP_ENTERPRISESPECIFIC   = 6

'/* SNMP Error Codes Returned in Error_status Field of PDU */
'/* (these are NOT WinSNMP API Error Codes */
'/* Error Codes Common to SNMPv1 and SNMPv2 */
%SNMP_ERROR_NOERROR             = 0
%SNMP_ERROR_TOOBIG              = 1
%SNMP_ERROR_NOSUCHNAME          = 2
%SNMP_ERROR_BADVALUE            = 3
%SNMP_ERROR_READONLY            = 4
%SNMP_ERROR_GENERR              = 5

'' /* Error Codes Added for SNMPv2 */
%SNMP_ERROR_NOACCESS            = 6
%SNMP_ERROR_WRONGTYPE           = 7
%SNMP_ERROR_WRONGLENGTH         = 8
%SNMP_ERROR_WRONGENCODING       = 9
%SNMP_ERROR_WRONGVALUE          = 10
%SNMP_ERROR_NOCREATION          = 11
%SNMP_ERROR_INCONSISTENTVALUE   = 12
%SNMP_ERROR_RESOURCEUNAVAILABLE = 13
%SNMP_ERROR_COMMITFAILED        = 14
%SNMP_ERROR_UNDOFAILED          = 15
%SNMP_ERROR_AUTHORIZATIONERROR  = 16
%SNMP_ERROR_NOTWRITABLE         = 17
%SNMP_ERROR_INCONSISTENTNAME    = 18

' /* WinSNMP API Values */
' /* Values used to indicate entity/context translation modes */
%SNMPAPI_TRANSLATED        = 0
%SNMPAPI_UNTRANSLATED_V1   = 1
%SNMPAPI_UNTRANSLATED_V2   = 2

' /* Values used to indicate "SNMP level" supported by the implementation */
%SNMPAPI_NO_SUPPORT        = 0
%SNMPAPI_V1_SUPPORT        = 1
%SNMPAPI_V2_SUPPORT        = 2
%SNMPAPI_M2M_SUPPORT       = 3

' /* Values used to indicate retransmit mode in the implementation */
%SNMPAPI_OFF               = 0    ' /* Refuse support */
%SNMPAPI_ON                = 1    ' /* Request support */

' /* WinSNMP API Function Return Codes */
'typedef smiUINT32    SNMPAPI_STATUS;    ' /* Used for function ret values */
%SNMPAPI_FAILURE           = 0    ' /* Generic error code */
%SNMPAPI_SUCCESS           = 1    ' /* Generic success code */

' /* WinSNMP API Error Codes (for SnmpGetLastError) */
' /* (NOT SNMP Response-PDU error_status codes) */
%SNMPAPI_ALLOC_ERROR       = 2    ' /* Error allocating memory */
%SNMPAPI_CONTEXT_INVALID   = 3    ' /* Invalid context parameter */
%SNMPAPI_CONTEXT_UNKNOWN   = 4    ' /* Unknown context parameter */
%SNMPAPI_ENTITY_INVALID    = 5    ' /* Invalid entity parameter */
%SNMPAPI_ENTITY_UNKNOWN    = 6    ' /* Unknown entity parameter */
%SNMPAPI_INDEX_INVALID     = 7    ' /* Invalid VBL index parameter */
%SNMPAPI_NOOP              = 8    ' /* No operation performed */
%SNMPAPI_OID_INVALID       = 9    ' /* Invalid OID parameter */
%SNMPAPI_OPERATION_INVALID = 10   ' /* Invalid/unsupported operation */
%SNMPAPI_OUTPUT_TRUNCATED  = 11   ' /* Insufficient output buf len */
%SNMPAPI_PDU_INVALID       = 12   ' /* Invalid PDU parameter */
%SNMPAPI_SESSION_INVALID   = 13   ' /* Invalid session parameter */
%SNMPAPI_SYNTAX_INVALID    = 14   ' /* Invalid syntax in smiVALUE */
%SNMPAPI_VBL_INVALID       = 15   ' /* Invalid VBL parameter */
%SNMPAPI_MODE_INVALID      = 16   ' /* Invalid mode parameter */
%SNMPAPI_SIZE_INVALID      = 17   ' /* Invalid size/length parameter */
%SNMPAPI_NOT_INITIALIZED   = 18   ' /* SnmpStartup failed/not called */
%SNMPAPI_MESSAGE_INVALID   = 19   ' /* Invalid SNMP message format */
%SNMPAPI_HWND_INVALID      = 20   ' /* Invalid Window handle */
%SNMPAPI_OTHER_ERROR       = 99   ' /* For internal/undefined errors */

' /* Generic Transport Layer (TL) Errors */
%SNMPAPI_TL_NOT_INITIALIZED = 100  ' /* TL not initialized */
%SNMPAPI_TL_NOT_SUPPORTED   = 101  ' /* TL does not support protocol */
%SNMPAPI_TL_NOT_AVAILABLE   = 102  ' /* Network subsystem has failed */
%SNMPAPI_TL_RESOURCE_ERROR  = 103  ' /* TL resource error */
%SNMPAPI_TL_UNDELIVERABLE   = 104  ' /* Destination unreachable */
%SNMPAPI_TL_SRC_INVALID     = 105  ' /* Source endpoint invalid */
%SNMPAPI_TL_INVALID_PARAM   = 106  ' /* Input parameter invalid */
%SNMPAPI_TL_IN_USE          = 107  ' /* Source endpoint in use */
%SNMPAPI_TL_TIMEOUT         = 108  ' /* No response before timeout */
%SNMPAPI_TL_PDU_TOO_BIG     = 109  ' /* PDU too big for send/receive */
%SNMPAPI_TL_OTHER           = 199  ' /* Undefined TL error */

'/* WinSNMP API Function Prototypes */

'/* v2.0: Structure for SnmpGetVendorInfo() output */

%MAXVENDORINFO = 32

' // Size = 196 bytes
TYPE smiVENDORINFO DWORD
   vendorName        AS ASCIIZ * %MAXVENDORINFO * 2   ' char[MAXVENDORINFO*2]
   vendorContact     AS ASCIIZ * %MAXVENDORINFO * 2   ' char[MAXVENDORINFO*2]
   vendorVersionId   AS ASCIIZ * %MAXVENDORINFO       ' char[MAXVENDORINFO]
   vendorVersionDate AS ASCIIZ * %MAXVENDORINFO       ' char[MAXVENDORINFO]
   vendorEnterprise  AS DWORD                         ' smiUINT32
END TYPE

'/* v2.0: Callback format for SnmpCreateSession() fCallback parameter */

'typedef SNMPAPI_STATUS (CALLBACK *SNMPAPI_CALLBACK)
'                        (IN HSNMP_SESSION hSession,
'                         IN HWND hWnd,
'                         IN UINT wMsg,
'                         IN WPARAM wParam,
'                         IN LPARAM lParam,
'                         IN LPVOID lpClientData);

'FUNCTION SNMPAPI_CALLBACK ( _
'   BYVAL DWORD _                            ' __in HSNMP_SESSION hSession
' , BYVAL DWORD _                            ' __in HWND hWnd
' , BYVAL DWORD _                            ' __in UINT wMsg
' , BYVAL DWORD _                            ' __in WPARAM wParam
' , BYVAL LONG _                             ' __in LPARAM lParam
' , BYVAL DWORD _                            ' __in LPVOID lpClientData
'   ) AS DWORD

'/* Local Database Functions */

DECLARE FUNCTION SnmpGetTranslateMode IMPORT "WSNMP32.DLL" ALIAS "SnmpGetTranslateMode" ( _
   BYREF nTranslateMode AS DWORD _                      ' __out smiLPUINT32 nTranslateMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetTranslateMode IMPORT "WSNMP32.DLL" ALIAS "SnmpSetTranslateMode" ( _
   BYVAL nTranslateMode AS DWORD _                      ' __in smiUINT32 nTranslateMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpGetRetransmitMode IMPORT "WSNMP32.DLL" ALIAS "SnmpGetRetransmitMode" ( _
   BYREF nRetransmitMode AS DWORD _                     ' __out smiLPUINT32 nRetransmitMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetRetransmitMode IMPORT "WSNMP32.DLL" ALIAS "SnmpSetRetransmitMode" ( _
   BYVAL nRetransmitMode AS DWORD _                     ' __in smiUINT32 nRetransmitMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpGetTimeout IMPORT "WSNMP32.DLL" ALIAS "SnmpGetTimeout" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYREF nPolicyTimeout AS DWORD _                      ' __out smiLPTIMETICKS nPolicyTimeout
 , BYREF nActualTimeout AS DWORD _                      ' __out smiLPTIMETICKS nActualTimeout
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetTimeout IMPORT "WSNMP32.DLL" ALIAS "SnmpSetTimeout" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYVAL nPolicyTimeout AS DWORD _                      ' __in smiLPTIMETICKS nPolicyTimeout
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpGetRetry IMPORT "WSNMP32.DLL" ALIAS "SnmpGetRetry" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYREF nPolicyRetry AS DWORD _                        ' __out smiLPUINT32 nPolicyRetry
 , BYREF nActualRetry AS DWORD _                        ' __out smiLPUINT32 nActualRetry
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetRetry IMPORT "WSNMP32.DLL" ALIAS "SnmpSetRetry" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYVAL nPolicyRetry AS DWORD _                        ' __in smiUINT32 nPolicyRetry
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Following Local Database Functions added in v2.0 */

DECLARE FUNCTION SnmpGetVendorInfo IMPORT "WSNMP32.DLL" ALIAS "SnmpGetVendorInfo" ( _
   BYREF vendorInfo AS smiVENDORINFO _                  ' __out smiLPVENDORINFO vendorInfo
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Communications Functions */

DECLARE FUNCTION SnmpStartup IMPORT "WSNMP32.DLL" ALIAS "SnmpStartup" ( _
   BYREF nMajorVersion AS DWORD _                       ' __out smiLPUINT32 nMajorVersion
 , BYREF nMinorVersion AS DWORD _                       ' __out smiLPUINT32 nMinorVersion
 , BYREF nLevel AS DWORD _                              ' __out smiLPUINT32 nLevel
 , BYREF nTranslateMode AS DWORD _                      ' __out smiLPUINT32 nTranslateMode
 , BYREF nRetransmitMode AS DWORD _                     ' __out smiLPUINT32 nRetransmitMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpCleanup IMPORT "WSNMP32.DLL" ALIAS "SnmpCleanup" ( _
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpOpen IMPORT "WSNMP32.DLL" ALIAS "SnmpOpen" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in UINT wMsg
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpClose IMPORT "WSNMP32.DLL" ALIAS "SnmpClose" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSendMsg IMPORT "WSNMP32.DLL" ALIAS "SnmpSendMsg" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL srcEntity AS DWORD _                           ' __in HSNMP_ENTITY srcEntity
 , BYVAL dstEntity AS DWORD _                           ' __in HSNMP_ENTITY dstEntity
 , BYVAL context AS DWORD _                             ' __in HSNMP_CONTEXT context
 , BYVAL PDU AS DWORD _                                 ' __in HSNMP_PDU PDU
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpRecvMsg IMPORT "WSNMP32.DLL" ALIAS "SnmpRecvMsg" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYREF srcEntity AS DWORD _                           ' __out LPHSNMP_ENTITY srcEntity
 , BYREF dstEntity AS DWORD _                           ' __out LPHSNMP_ENTITY dstEntity
 , BYREF context AS DWORD _                             ' __out LPHSNMP_CONTEXT  context
 , BYREF PDU AS DWORD _                                 ' __out LPHSNMP_PDU PDU
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpRegister IMPORT "WSNMP32.DLL" ALIAS "SnmpRegister" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL srcEntity AS DWORD _                           ' __in HSNMP_ENTITY srcEntity
 , BYVAL dstEntity AS DWORD _                           ' __in HSNMP_ENTITY dstEntity
 , BYVAL context AS DWORD _                             ' __in HSNMP_CONTEXT context
 , BYREF notification AS smiOID _                       ' __in smiLPCOID notification
 , BYVAL state AS DWORD _                               ' __in smiUINT32 state
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Following Communications Functions added in v2.0 */

DECLARE FUNCTION SnmpCreateSession IMPORT "WSNMP32.DLL" ALIAS "SnmpCreateSession" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL wMsg AS DWORD _                                ' __in UINT wMsg
 , BYVAL fCallBack AS DWORD _                           ' __in SNMPAPI_CALLBACK fCallBack
 , BYVAL lpClientData AS DWORD _                        ' __in LPVOID lpClientData
   ) AS DWORD                                           ' HSNMP_SESSION

DECLARE FUNCTION SnmpListen IMPORT "WSNMP32.DLL" ALIAS "SnmpListen" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYVAL lStatus AS DWORD _                             ' __in SNMPAPI_STATUS lStatus
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpListenEx IMPORT "WSNMP32.DLL" ALIAS "SnmpListenEx" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYVAL lStatus AS DWORD _                             ' __in SNMPAPI_STATUS lStatus
 , BYVAL nUseEntityAddr AS DWORD _                      ' __in smiUINT32 nUseEntityAddr
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpCancelMsg IMPORT "WSNMP32.DLL" ALIAS "SnmpCancelMsg" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL reqId AS DWORD _                               ' __in smiINT32 reqId
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Extensions to Communications Functions */

DECLARE FUNCTION SnmpStartupEx IMPORT "WSNMP32.DLL" ALIAS "SnmpStartupEx" ( _
   BYREF nMajorVersion AS DWORD _                       ' __out smiLPUINT32 nMajorVersion
 , BYREF nMinorVersion AS DWORD _                       ' __out smiLPUINT32 nMinorVersion
 , BYREF nLevel AS DWORD _                              ' __out smiLPUINT32 nLevel
 , BYREF nTranslateMode AS DWORD _                      ' __out smiLPUINT32 nTranslateMode
 , BYREF nRetransmitMode As DWORD _                     ' __out smiLPUINT32 nRetransmitMode
 ) AS DWORD                                             ' SNMPAPI_STATUS

'typedef SNMPAPI_STATUS (__stdcall * PFNSNMPSTARTUPEX)(  smiLPUINT32,
'                                                        smiLPUINT32,
'                                                        smiLPUINT32,
'                                                        smiLPUINT32,

DECLARE FUNCTION SnmpCleanupEx IMPORT "WSNMP32.DLL" ALIAS "SnmpCleanupEx" ( _
 ) AS DWORD                                             ' SNMPAPI_STATUS

'typedef SNMPAPI_STATUS (__stdcall * PFNSNMPCLEANUPEX)(void);

'/* Entity/Context Functions */

DECLARE FUNCTION SnmpStrToEntity IMPORT "WSNMP32.DLL" ALIAS "SnmpStrToEntity" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYREF string AS ASCIIZ _                             ' __in LPCSTR string
 ) AS DWORD                                             ' HSNMP_ENTITY

DECLARE FUNCTION SnmpEntityToStr IMPORT "WSNMP32.DLL" ALIAS "SnmpEntityToStr" ( _
   BYVAL entity AS DWORD _                              ' __in HSNMP_ENTITY entity
 , BYVAL size AS DWORD _                                ' __in smiUINT32 size
 , BYREF string AS ASCIIZ _                             ' __out LPSTR string
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpFreeEntity IMPORT "WSNMP32.DLL" ALIAS "SnmpFreeEntity" ( _
   BYVAL entity AS DWORD _                              ' __in HSNMP_ENTITY entity
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpStrToContext IMPORT "WSNMP32.DLL" ALIAS "SnmpStrToContext" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYREF string As smiOCTETS _                          ' __in smiLPCOCTETS string
 ) AS DWORD                                             ' HSNMP_CONTEXT

DECLARE FUNCTION SnmpContextToStr IMPORT "WSNMP32.DLL" ALIAS "SnmpContextToStr" ( _
   BYVAL context AS DWORD _                             ' __in HSNMP_CONTEXT context
 , BYREF string AS smiOCTETS _                          ' __out smiLPOCTETS string
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpFreeContext IMPORT "WSNMP32.DLL" ALIAS "SnmpFreeContext" ( _
   BYVAL context AS DWORD _                             ' __in HSNMP_CONTEXT context
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Following Entity/Context Functions added in v2.0 */

DECLARE FUNCTION SnmpSetPort IMPORT "WSNMP32.DLL" ALIAS "SnmpSetPort" ( _
   BYVAL hEntity AS DWORD _                             ' __in HSNMP_ENTITY hEntity
 , BYVAL nPort AS DWORD _                               ' __in UINT nPort
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* PDU Functions */

DECLARE FUNCTION SnmpCreatePdu IMPORT "WSNMP32.DLL" ALIAS "SnmpCreatePdu" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL PDU_type AS LONG _                             ' __in smiINT PDU_type
 , BYVAL request_id AS DWORD _                          ' __in smiINT32 request_id
 , BYVAL error_status AS LONG _                         ' __in smiINT error_status
 , BYVAL error_index AS LONG _                          ' __in smiINT error_index
 , BYVAL varbindlist AS DWORD _                         ' __in HSNMP_VBL varbindlist
   ) AS DWORD                                           ' HSNMP_PDU

DECLARE FUNCTION SnmpGetPduData IMPORT "WSNMP32.DLL" ALIAS "SnmpGetPduData" ( _
   BYVAL PDU AS DWORD _                                 ' __in HSNMP_PDU PDU
 , BYREF PDU_type AS LONG _                             ' __out smiLPINT PDU_type
 , BYREF request_id AS DWORD _                          ' __out smiLPINT32 request_id
 , BYREF error_status AS LONG _                         ' __out smiLPINT error_status
 , BYREF error_index AS LONG _                          ' __out smiLPINT error_index
 , BYREF varbindlist AS DWORD _                         ' __out LPHSNMP_VBL varbindlist
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetPduData IMPORT "WSNMP32.DLL" ALIAS "SnmpSetPduData" ( _
   BYVAL PDU AS DWORD _                                 ' __in HSNMP_PDU PDU
 , BYREF PDU_type AS LONG _                             ' __in const smiINT FAR *PDU_type
 , BYREF request_id AS DWORD _                          ' __in const smiINT32 FAR *request_id
 , BYREF non_repeaters AS LONG _                        ' __in const smiINT FAR *non_repeaters
 , BYREF max_repetitions AS LONG _                      ' __in const smiINT FAR *max_repetitions
 , BYREF varbindlist AS DWORD _                         ' __in const HSNMP_VBL FAR *varbindlist
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpDuplicatePdu IMPORT "WSNMP32.DLL" ALIAS "SnmpDuplicatePdu" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL PDU AS DWORD _                                 ' __in HSNMP_PDU PDU
   ) AS DWORD                                           ' HSNMP_PDU

DECLARE FUNCTION SnmpFreePdu IMPORT "WSNMP32.DLL" ALIAS "SnmpFreePdu" ( _
   BYVAL PDU AS DWORD _                                 ' __in HSNMP_PDU PDU
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Variable-Binding Functions */

DECLARE FUNCTION SnmpCreateVbl IMPORT "WSNMP32.DLL" ALIAS "SnmpCreateVbl" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYREF name AS smiOID _                               ' __in smiLPCOID name
 , BYREF value AS smiVALUE _                            ' __in smiLPCVALUE value
   ) AS DWORD                                           ' HSNMP_VBL

DECLARE FUNCTION SnmpDuplicateVbl IMPORT "WSNMP32.DLL" ALIAS "SnmpDuplicateVbl" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
   ) AS DWORD                                           ' HSNMP_VBL

DECLARE FUNCTION SnmpFreeVbl IMPORT "WSNMP32.DLL" ALIAS "SnmpFreeVbl" ( _
   BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpCountVbl IMPORT "WSNMP32.DLL" ALIAS "SnmpCountVbl" ( _
   BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpGetVb IMPORT "WSNMP32.DLL" ALIAS "SnmpGetVb" ( _
   BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
 , BYVAL index AS DWORD _                               ' __in smiUINT32 index
 , BYREF name AS smiOID _                               ' __out smiLPOID name
 , BYREF value AS smiVALUE _                            ' __out smiLPVALUE value
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpSetVb IMPORT "WSNMP32.DLL" ALIAS "SnmpSetVb" ( _
   BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
 , BYVAL index AS DWORD _                               ' __in smiUINT32 index
 , BYREF name AS smiOID _                               ' __in smiLPCOID name
 , BYREF value AS smiVALUE _                            ' __in smiLPCVALUE value
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpDeleteVb IMPORT "WSNMP32.DLL" ALIAS "SnmpDeleteVb" ( _
   BYVAL vbl AS DWORD _                                 ' __in HSNMP_VBL vbl
 , BYVAL index AS DWORD _                               ' __in smiUINT32 index
 ) AS DWORD                                             ' SNMPAPI_STATUS

'/* Utility Functions */

DECLARE FUNCTION SnmpGetLastError IMPORT "WSNMP32.DLL" ALIAS "SnmpGetLastError" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpStrToOid IMPORT "WSNMP32.DLL" ALIAS "SnmpStrToOid" ( _
   BYREF string AS ASCIIZ _                             ' __in LPCSTR string
 , BYREF dstOID AS smiOID _                             ' __out smiLPOID dstOID
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpOidToStr IMPORT "WSNMP32.DLL" ALIAS "SnmpOidToStr" ( _
   BYREF srcOID AS smiOID _                             ' __in smiLPCOID srcOID
 , BYVAL size AS DWORD _                                ' __in smiUINT32 size
 , BYREF string AS ASCIIZ _                             ' __out LPSTR string
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpOidCopy IMPORT "WSNMP32.DLL" ALIAS "SnmpOidCopy" ( _
   BYREF srcOID AS smiOID _                             ' __in smiLPCOID srcOID
 , BYREF dstOID AS smiOID _                             ' __out smiLPOID dstOID
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpOidCompare IMPORT "WSNMP32.DLL" ALIAS "SnmpOidCompare" ( _
   BYREF xOID AS smiOID _                               ' __in smiLPCOID xOID
 , BYREF yOID AS smiOID _                               ' __in smiLPCOID yOID
 , BYVAL maxlen AS DWORD _                              ' __in smiUINT32 maxlen
 , BYREF result AS LONG _                               ' __out smiLPINT result
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpEncodeMsg IMPORT "WSNMP32.DLL" ALIAS "SnmpEncodeMsg" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYVAL srcEntity AS DWORD _                           ' __in HSNMP_ENTITY srcEntity
 , BYVAL dstEntity AS DWORD _                           ' __in HSNMP_ENTITY dstEntity
 , BYVAL context AS DWORD _                             ' __in HSNMP_CONTEXT context
 , BYVAL pdu AS DWORD _                                 ' __in HSNMP_PDU pdu
 , BYREF msgBufDesc AS smiOCTETS _                      ' __out smiLPOCTETS msgBufDesc
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpDecodeMsg IMPORT "WSNMP32.DLL" ALIAS "SnmpDecodeMsg" ( _
   BYVAL session AS DWORD _                             ' __in HSNMP_SESSION session
 , BYREF srcEntity AS DWORD _                           ' __out LPHSNMP_ENTITY srcEntity
 , BYREF dstEntity AS DWORD _                           ' __out LPHSNMP_ENTITY dstEntity
 , BYREF context AS DWORD _                             ' __out LPHSNMP_CONTEXT context
 , BYREF pdu AS DWORD _                                 ' __out LPHSNMP_PDU pdu
 , BYREF msgBufDesc AS smiOCTETS _                      ' __in smiLPCOCTETS msgBufDesc
 ) AS DWORD                                             ' SNMPAPI_STATUS

DECLARE FUNCTION SnmpFreeDescriptor IMPORT "WSNMP32.DLL" ALIAS "SnmpFreeDescriptor" ( _
   BYVAL syntax AS DWORD _                              ' __in smiUINT32 syntax
 , BYREF descriptor AS smiOCTETS _                      ' __in smiLPOPAQUE descriptor
 ) AS DWORD                                             ' SNMPAPI_STATUS
