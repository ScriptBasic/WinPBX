' ########################################################################################
' Microsoft Windows
' File: MSChapp.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MSCHAPP_INC = 1

'/*++

'Copyright (C) Microsoft Corporation, 1999

'Module Name:

'    mschapp - MS-CHAP Password Change API

'Abstract:

'    These APIs correspond to the MS-CHAP RFC -2433 sections 9 and 10. In order
'    to develop an MS-CHAP RAS server that works with an NT domain, these APIs
'    are required.

'    Only wide (Unicode) versions of these apis will be available. These are the
'    2 callable APIs:

'    *   MSChapSrvChangePassword
'    *   MsChapSrvChangePassword2

'--*/

'#ifndef _NTCRYPT_

#INCLUDE ONCE "subauth.inc"

' Declared in subauth.inc
'%CYPHER_BLOCK_LENGTH = 8

' Declared in subauth.inc
'TYPE CYPHER_BLOCK
'   data AS STRING * %CYPHER_BLOCK_LENGTH   ' CHAR    data[CYPHER_BLOCK_LENGTH]
'END TYPE

' Declared in subauth.inc
'TYPE LM_OWF_PASSWORD
'   data(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2]
'END TYPE

'MACRO NT_OWF_PASSWORD = LM_OWF_PASSWORD

' // Size = 516 bytes
TYPE SAMPR_ENCRYPTED_USER_PASSWORD BYTE
   Buffer AS STRING * (256 * 2) + 4   ' UCHAR Buffer[ (256 * 2) + 4 ];
END TYPE

' // Size = 16 bytes
TYPE ENCRYPTED_LM_OWF_PASSWORD BYTE
   data(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2];
END TYPE

MACRO ENCRYPTED_NT_OWF_PASSWORD = ENCRYPTED_LM_OWF_PASSWORD

'#endif


'//
'// Change a password.
'//

DECLARE FUNCTION MSChapSrvChangePassword IMPORT "Advapi32.dll" ALIAS "MSChapSrvChangePassword" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in PWSTR ServerName
 , BYREF UserName AS WSTRINGZ _                         ' __in PWSTR UserName
 , BYVAL LmOldPresent AS BYTE _                         ' __in BOOLEAN LmOldPresent
 , BYREF LmOldOwfPassword AS LM_OWF_PASSWORD _          ' __in PLM_OWF_PASSWORD LmOldOwfPassword
 , BYREF LmNewOwfPassword AS LM_OWF_PASSWORD _          ' __in PLM_OWF_PASSWORD LmNewOwfPassword
 , BYREF NtOldOwfPassword AS NT_OWF_PASSWORD _          ' __in PNT_OWF_PASSWORD NtOldOwfPassword
 , BYREF NtNewOwfPassword AS NT_OWF_PASSWORD _          ' __in PNT_OWF_PASSWORD NtNewOwfPassword
 ) AS DWORD                                             ' DWORD


'//
'// Change a password using mutual encryption.
'//

DECLARE FUNCTION MSChapSrvChangePassword2 IMPORT "Advapi32.dll" ALIAS "MSChapSrvChangePassword2" ( _
   BYREF ServerName AS WSTRINGZ _                                              ' __in PWSTR ServerName
 , BYREF UserName AS WSTRINGZ _                                                ' __in PWSTR UserName
 , BYREF NewPasswordEncryptedWithOldNt AS SAMPR_ENCRYPTED_USER_PASSWORD _      ' __in PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldNt
 , BYREF OldNtOwfPasswordEncryptedWithNewNt AS ENCRYPTED_NT_OWF_PASSWORD _     ' __in PENCRYPTED_NT_OWF_PASSWORD OldNtOwfPasswordEncryptedWithNewNt
 , BYVAL LmPresent AS BYTE _                                                   ' __in BOOLEAN LmPresent
 , BYREF NewPasswordEncryptedWithOldLm AS SAMPR_ENCRYPTED_USER_PASSWORD _      ' __in PSAMPR_ENCRYPTED_USER_PASSWORD NewPasswordEncryptedWithOldLm
 , BYREF OldLmOwfPasswordEncryptedWithNewLmOrNt AS ENCRYPTED_LM_OWF_PASSWORD _ ' __in PENCRYPTED_LM_OWF_PASSWORD OldLmOwfPasswordEncryptedWithNewLmOrNt
 ) AS DWORD                                                                    ' DWORD
