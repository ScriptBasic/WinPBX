' ########################################################################################
' Microsoft Windows
' File: MgmtAPI.inc
' Contents: Definitions for SNMP Management API Development
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MGMTAPI_INC = 1

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// Additional header files                                                   //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

#INCLUDE ONCE "snmp.inc"
#INCLUDE ONCE "winsock.inc"

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// MGMT API error code definitions                                           //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

%SNMP_MGMTAPI_TIMEOUT               = 40
%SNMP_MGMTAPI_SELECT_FDERRORS       = 41
%SNMP_MGMTAPI_TRAP_ERRORS           = 42
%SNMP_MGMTAPI_TRAP_DUPINIT          = 43
%SNMP_MGMTAPI_NOTRAPS               = 44
%SNMP_MGMTAPI_AGAIN                 = 45
%SNMP_MGMTAPI_INVALID_CTL           = 46
%SNMP_MGMTAPI_INVALID_SESSION       = 47
%SNMP_MGMTAPI_INVALID_BUFFER        = 48

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// MGMT API control codes
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////
%MGMCTL_SETAGENTPORT             = &H01

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// MGMT API type definitions                                                 //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'typedef PVOID LPSNMP_MGR_SESSION;

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// MGMT API prototypes                                                       //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION SnmpMgrOpen IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrOpen" ( _
   BYREF lpAgentAddress AS ASCIIZ _                     ' __in LPSTR lpAgentAddress
 , BYREF lpAgentCommunity AS ASCIIZ _                   ' __in LPSTR lpAgentCommunity
 , BYVAL nTimeOut AS LONG _                             ' __in INT   nTimeOut
 , BYVAL nRetries AS LONG _                             ' __in INT   nRetries
 ) AS DWORD                                             ' LPSNMP_MGR_SESSION

DECLARE FUNCTION SnmpMgrCtl IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrCtl" ( _
   BYVAL session AS DWORD _                             ' __in  LPSNMP_MGR_SESSION session
 , BYVAL dwCtlCode AS DWORD _                           ' __in  DWORD              dwCtlCode
 , BYVAL lpvInBuffer AS DWORD _                         ' __in  LPVOID             lpvInBuffer
 , BYVAL cbInBuffer AS DWORD _                          ' __in  DWORD              cbInBuffer
 , BYREF lpvOUTBuffer AS ANY _                          ' __out LPVOID             lpvOUTBuffer
 , BYVAL cbOUTBuffer AS DWORD _                         ' __in  DWORD              cbOUTBuffer
 , BYREF lpcbBytesReturned AS DWORD _                   ' __out LPDWORD            lpcbBytesReturned
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SnmpMgrClose IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrClose" ( _
   BYVAL session AS DWORD _                             ' __in LPSNMP_MGR_SESSION session
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SnmpMgrRequest IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrRequest" ( _
   BYVAL session AS DWORD _                             ' __in     LPSNMP_MGR_SESSION session
 , BYVAL requestType AS BYTE _                          ' __in     BYTE               requestType
 , BYREF variableBindings AS SnmpVarBindList _          ' __in_out RFC1157VarBindList *variableBindings
 , BYREF errorStatus AS LONG _                          ' __out    AsnInteger         *errorStatus
 , BYREF errorIndex AS LONG _                           ' __out    AsnInteger         *errorIndex
 ) AS LONG                                              ' SNMPAPI

DECLARE FUNCTION SnmpMgrStrToOid IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrStrToOid" ( _
   BYREF string AS ASCIIZ _                             ' __in  LPSTR               string
 , BYREF oid AS AsnObjectIdentifier _                   ' __out AsnObjectIdentifier *oid
 ) AS LONG                                              ' BOOL

' Note: The 2nd parameter should be BYREF ASCIIZ PTR, but it has been declared
' as DWORD because PowerBASIC doesn't allow byref pointer variables.
DECLARE FUNCTION SnmpMgrOidToStr IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrOidToStr" ( _
   BYREF oid AS AsnObjectIdentifier _                   ' __in  AsnObjectIdentifier *oid
 , BYREF string AS DWORD _                              ' __out LPSTR               *string
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SnmpMgrTrapListen IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrTrapListen" ( _
   BYREF phTrapAvailable AS DWORD _                     ' __out HANDLE *phTrapAvailable
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SnmpMgrGetTrap IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrGetTrap" ( _
   BYREF enterprise AS AsnObjectIdentifier _            ' __out AsnObjectIdentifier *enterprise
 , BYREF IPAddress AS AsnOctetString _                  ' __out AsnNetworkAddress   *IPAddress
 , BYREF genericTrap AS LONG _                          ' __out AsnInteger          *genericTrap
 , BYREF specificTrap AS LONG _                         ' __out AsnInteger          *specificTrap
 , BYREF timeStamp AS DWORD _                           ' __out AsnTimeticks        *timeStamp
 , BYREF variableBindings AS SnmpVarBindList _          ' __out RFC1157VarBindList  *variableBindings
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SnmpMgrGetTrapEx IMPORT "MGMTAPI.DLL" ALIAS "SnmpMgrGetTrapEx" ( _
   BYREF enterprise AS AsnObjectIdentifier _            ' __out AsnObjectIdentifier *enterprise
 , BYREF agentAddress AS AsnOctetString _               ' __out AsnNetworkAddress   *agentAddress
 , BYREF sourceAddress AS AsnOctetString _              ' __out AsnNetworkAddress   *sourceAddress
 , BYREF genericTrap AS LONG _                          ' __out AsnInteger          *genericTrap
 , BYREF specificTrap AS LONG _                         ' __out AsnInteger          *specificTrap
 , BYREF community AS AsnOctetString _                  ' __out AsnOctetString      *community
 , BYREF timeStamp AS DWORD _                           ' __out AsnTimeticks        *timeStamp
 , BYREF variableBindings AS SnmpVarBindList _          ' __out RFC1157VarBindList  *variableBindings
 ) AS LONG                                              ' BOOL
