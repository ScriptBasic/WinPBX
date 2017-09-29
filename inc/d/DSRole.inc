' ########################################################################################
' Microsoft Windows
' File: DSRole.inc
' Contents: Public interfaces to query the network roles of workstations, servers, and DCs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSROLE_INC = 1

'//
'// Domain information
'//

' enum DSROLE_MACHINE_ROLE
%DsRole_RoleStandaloneWorkstation   = 0
%DsRole_RoleMemberWorkstation       = 1
%DsRole_RoleStandaloneServer        = 2
%DsRole_RoleMemberServer            = 3
%DsRole_RoleBackupDomainController  = 4
%DsRole_RolePrimaryDomainController = 5

'//
'// Previous server state
'//

' enum DSROLE_SERVER_STATE {
%DsRoleServerUnknown = 0
%DsRoleServerPrimary = 1
%DsRoleServerBackup  = 2

' enum DSROLE_PRIMARY_DOMAIN_INFO_LEVEL {
%DsRolePrimaryDomainInfoBasic = 1
%DsRoleUpgradeStatus          = 2
%DsRoleOperationState         = 3

'//
'// Flags to be used with the PRIMARY_DOMAIN_INFO_LEVEL structures below
'//

%DSROLE_PRIMARY_DS_RUNNING           = &H00000001???
%DSROLE_PRIMARY_DS_MIXED_MODE        = &H00000002???
%DSROLE_UPGRADE_IN_PROGRESS          = &H00000004???
%DSROLE_PRIMARY_DOMAIN_GUID_PRESENT  = &H01000000???

'//
'// Structure that correspond to the DSROLE_PRIMARY_DOMAIN_INFO_LEVEL
'//

' // Size = 36 bytes
TYPE DSROLE_PRIMARY_DOMAIN_INFO_BASIC DWORD
   MachineRole      AS LONG           ' DSROLE_MACHINE_ROLE enum
   Flags            AS DWORD          ' ULONG
   DomainNameFlat   AS WSTRINGZ PTR   ' LPWSTR
   DomainNameDns    AS WSTRINGZ PTR   ' LPWSTR
   DomainForestName AS WSTRINGZ PTR   ' LPWSTR
   DomainGuid       AS GUID           ' GUID
END TYPE

' // Size = 8 bytes
TYPE DSROLE_UPGRADE_STATUS_INFO DWORD
   OperationState      AS DWORD   ' ULONG
   PreviousServerState AS LONG    ' DSROLE_SERVER_STATE enum
END TYPE

' enum DSROLE_OPERATION_STATE {
%DsRoleOperationIdle       = 0
%DsRoleOperationActive     = 1
%DsRoleOperationNeedReboot = 2

' // Size = 4 bytes
TYPE DSROLE_OPERATION_STATE_INFO DWORD
   OperationState AS LONG   ' DSROLE_OPERATION_STATE enum
END TYPE

DECLARE FUNCTION DsRoleGetPrimaryDomainInformation IMPORT "NETAPI32.DLL" ALIAS "DsRoleGetPrimaryDomainInformation" ( _
   BYREF lpServer AS WSTRINGZ _                         ' __in  LPCWSTR lpServer OPTIONAL
 , BYVAL InfoLevel AS LONG _                            ' __in  DSROLE_PRIMARY_DOMAIN_INFO_LEVEL InfoLevel
 , BYREF Buffer AS ANY _                                ' __out PBYTE *Buffer
 ) AS DWORD                                             ' DWORD

DECLARE SUB DsRoleFreeMemory IMPORT "NETAPI32.DLL" ALIAS "DsRoleFreeMemory" ( _
   BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 )                                                      ' void
