' ########################################################################################
' Microsoft Windows
' File: WinEFS.inc
' Contents: EFS Data and prototypes
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINEFS_INC = 1

#INCLUDE "wtypes.inc"

'// winefs.h was not available at all pre-W2K
'#if (NTDDI_VERSION >= NTDDI_WIN2K)

%WINEFS_SETUSERKEY_SET_CAPABILITIES      = &H00000001???
'%WINEFS_SETUSERKEY_BLOCK_CACHE_FLUSH     = &H00000002???   ' // Removed from Windows 7 SDK

'//+---------------------------------------------------------------------------------/
'//                                                                                  /
'//                                                                                  /
'//                          Data Structures                                         /
'//                                                                                  /
'//                                                                                  /
'//----------------------------------------------------------------------------------/

'// ALG_ID define is used as part of EFS_KEY_INFO (not available pre-WXP)
'#if (NTDDI_VERSION >= NTDDI_WINXP)

'#ifndef ALGIDDEF
'#define ALGIDDEF
'typedef unsigned int ALG_ID;
'#endif

'#endif

'//
'//  Encoded Certificate
'//

' // Size = 12 bytes
TYPE EFS_CERTIFICATE_BLOB
   dwCertEncodingType AS DWORD      ' DWORD
   cbData             AS DWORD      ' DWORD
   pbData             AS BYTE PTR   ' PBYTE
END TYPE

'//
'//  Certificate Hash
'//

' // Size = 8 bytes
TYPE EFS_HASH_BLOB DWORD
   cbData AS DWORD      ' DWORD
   pbData AS BYTE PTR   ' PBYTE
END TYPE

'//
'//  RPC blob
'//

' // Size = 8 bytes
TYPE EFS_RPC_BLOB DWORD
   cbData AS DWORD      ' DWORD
   pbData AS BYTE PTR   ' PBYTE
END TYPE

'// EFS_PIN_BLOB was not available pre-LH
'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 12 bytes
TYPE EFS_PIN_BLOB DWORD
   cbPadding AS DWORD   ' DWORD
   cbData    AS DWORD   ' DWORD
   pbData    AS BYTE PTR   ' PBYTE
END TYPE
'#endif // #if (NTDDI_VERSION >= NTDDI_VISTA)

'// EFS_KEY_INFO was not available pre-WXP
'#if (NTDDI_VERSION >= NTDDI_WINXP)
' // Size = 16 bytes
TYPE EFS_KEY_INFO DWORD
   dwVersion AS DWORD   ' DWORD
   Entropy   AS DWORD   ' ULONG
   Algorithm AS DWORD   ' ALG_ID
   KeyLength AS DWORD   ' ULONG
END TYPE
'#endif // #if (NTDDI_VERSION >= NTDDI_WINXP)

'// EFS_COMPATIBILITY_INFO was not available pre-Windows 7
'#if (NTDDI_VERSION >= NTDDI_WIN7)

' // Size = 4 bytes
TYPE EFS_COMPATIBILITY_INFO DWORD
   EfsVersion AS DWORD   ' DWORD
END TYPE

'#endif // #if (NTDDI_VERSION >= NTDDI_WIN7)

'// EFS_(EN/DE)CRYPTION_STATUS_INFO was not available pre-LH
'#if (NTDDI_VERSION >= NTDDI_VISTA)

' // Size = 12 bytes
TYPE EFS_DECRYPTION_STATUS_INFO DWORD
   dwDecryptionError AS DWORD   ' DWORD
   dwHashOffset      AS DWORD   ' DWORD
   cbHash            AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE EFS_ENCRYPTION_STATUS_INFO DWORD
   bHasCurrentKey    AS LONG    ' BOOL
   dwEncryptionError AS DWORD   ' DWORD
END TYPE

'#endif // #if (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// Input to add a user to an encrypted file
'//

' // Size = 12 bytes
TYPE ENCRYPTION_CERTIFICATE DWORD
   cbTotalLength AS DWORD                      ' DWORD
   pUserSid      AS DWORD                      ' SID*
   pCertBlob     AS EFS_CERTIFICATE_BLOB PTR   ' PEFS_CERTIFICATE_BLOB
END TYPE

'#define MAX_SID_SIZE 256
%MAX_SID_SIZE = 256

' // Size = 16 bytes
TYPE ENCRYPTION_CERTIFICATE_HASH DWORD
   cbTotalLength        AS DWORD               ' DWORD
   pUserSid             AS DWORD               ' SID *
   pHash                AS EFS_HASH_BLOB PTR   ' PEFS_HASH_BLOB
   lpDisplayInformation AS WSTRINGZ PTR        ' LPWSTR
END TYPE

' // Size = 8 bytes
TYPE ENCRYPTION_CERTIFICATE_HASH_LIST DWORD
   nCert_Hash AS DWORD                             ' DWORD
   pUsers     AS ENCRYPTION_CERTIFICATE_HASH PTR   ' PENCRYPTION_CERTIFICATE_HASH*
END TYPE

' // Size = 8 bytes
TYPE ENCRYPTION_CERTIFICATE_LIST DWORD
   nUsers AS DWORD                        ' DWORD
   pUsers AS ENCRYPTION_CERTIFICATE PTR   ' PENCRYPTION_CERTIFICATE*
END TYPE

'// ENCRYPTED_FILE_METADATA_SIGNATURE was not available pre-LH
'#if (NTDDI_VERSION >= NTDDI_VISTA)

%EFS_METADATA_ADD_USER      = &H00000001???
%EFS_METADATA_REMOVE_USER   = &H00000002???
%EFS_METADATA_REPLACE_USER  = &H00000004???
%EFS_METADATA_GENERAL_OP    = &H00000008???

' // Size = 16 bytes
TYPE ENCRYPTED_FILE_METADATA_SIGNATURE DWORD
   dwEfsAccessType        AS DWORD                                  ' DWORD
   pCertificatesAdded     AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR   ' PENCRYPTION_CERTIFICATE_HASH_LIST
   pEncryptionCertificate AS ENCRYPTION_CERTIFICATE PTR             ' PENCRYPTION_CERTIFICATE
   pEfsStreamSignature    AS EFS_RPC_BLOB PTR                       ' PEFS_RPC_BLOB
END TYPE

'#endif // #if (NTDDI_VERSION >= NTDDI_VISTA)

'//+---------------------------------------------------------------------------------/
'//                                                                                  /
'//                                                                                  /
'//                               Prototypes                                         /
'//                                                                                  /
'//                                                                                  /
'//----------------------------------------------------------------------------------/


DECLARE FUNCTION QueryUsersOnEncryptedFile IMPORT "ADVAPI32.DLL" ALIAS "QueryUsersOnEncryptedFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF pUsers AS ENCRYPTION_CERTIFICATE_HASH_LIST _   ' __out PENCRYPTION_CERTIFICATE_HASH_LIST * pUsers
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION QueryRecoveryAgentsOnEncryptedFile IMPORT "ADVAPI32.DLL" ALIAS "QueryRecoveryAgentsOnEncryptedFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF pRecoveryAgents AS ENCRYPTION_CERTIFICATE_HASH_LIST _ ' __out PENCRYPTION_CERTIFICATE_HASH_LIST * pRecoveryAgents
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RemoveUsersFromEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "RemoveUsersFromEncryptedFile" (lpFileName AS WSTRINGZ, _
    BYVAL pHashes AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR) AS DWORD
#ELSE
DECLARE FUNCTION RemoveUsersFromEncryptedFile IMPORT "ADVAPI32.DLL" ALIAS "RemoveUsersFromEncryptedFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF pHashes AS ENCRYPTION_CERTIFICATE_HASH_LIST _  ' __in PENCRYPTION_CERTIFICATE_HASH_LIST pHashes
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AddUsersToEncryptedFile LIB "ADVAPI32.DLL" _
    ALIAS "AddUsersToEncryptedFile" (lpFileName AS WSTRINGZ, _
    BYVAL pEncryptionCertificates AS ENCRYPTION_CERTIFICATE_LIST PTR) AS DWORD
#ELSE
DECLARE FUNCTION AddUsersToEncryptedFile IMPORT "ADVAPI32.DLL" ALIAS "AddUsersToEncryptedFile" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
 , BYREF pUsers AS ENCRYPTION_CERTIFICATE_LIST _        ' __in PENCRYPTION_CERTIFICATE_LIST pUsers
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE FUNCTION SetUserFileEncryptionKey IMPORT "ADVAPI32.DLL" ALIAS "SetUserFileEncryptionKey" ( _
   BYREF pEncryptionCertificate AS ENCRYPTION_CERTIFICATE _ ' __in_opt PENCRYPTION_CERTIFICATE pEncryptionCertificate
 ) AS DWORD                                             ' DWORD

'// SetUserFileEncryptionKeyEx was not available pre-LH
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetUserFileEncryptionKeyEx LIB "ADVAPI32.DLL" _
    ALIAS "SetUserFileEncryptionKeyEx" _
    (pEncryptionCertificate AS ENCRYPTION_CERTIFICATE, _
    BYVAL dwCapabilities AS DWORD, BYVAL dwFlags AS DWORD, pvReserved AS ANY) _
    AS DWORD
#ELSE
DECLARE FUNCTION SetUserFileEncryptionKeyEx IMPORT "ADVAPI32.DLL" ALIAS "SetUserFileEncryptionKeyEx" ( _
   BYREF pEncryptionCertificate AS ENCRYPTION_CERTIFICATE _ ' __in PENCRYPTION_CERTIFICATE pEncryptionCertificate
 , BYVAL dwCapabilities AS DWORD _                      ' __in DWORD  dwCapabilities
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS DWORD                                             ' DWORD
#ENDIF
'#endif // #if (NTDDI_VERSION >= NTDDI_VISTA)

#IF %DEF(%USEPBDECL)
DECLARE SUB FreeEncryptionCertificateHashList LIB "ADVAPI32.DLL" _
    ALIAS "FreeEncryptionCertificateHashList" _
    (BYVAL pUsers AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR)
#ELSE
DECLARE SUB FreeEncryptionCertificateHashList IMPORT "ADVAPI32.DLL" ALIAS "FreeEncryptionCertificateHashList" ( _
   BYREF pHashes AS ENCRYPTION_CERTIFICATE_HASH_LIST _  ' __in_opt PENCRYPTION_CERTIFICATE_HASH_LIST pHashes
 )                                                      ' void
#ENDIF

DECLARE FUNCTION EncryptionDisable IMPORT "ADVAPI32.DLL" ALIAS "EncryptionDisable" ( _
   BYREF DirPath AS WSTRINGZ _                          ' __in LPCWSTR DirPath
 , BYVAL Disable AS LONG _                              ' __in BOOL Disable
 ) AS LONG                                              ' BOOL

'// DuplicateEncryptionInfoFile signature changed
'// DuplicateEncryptionInfoFile didn't exist pre-WXP
'#elif (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION DuplicateEncryptionInfoFile IMPORT "ADVAPI32.DLL" ALIAS "DuplicateEncryptionInfoFile" ( _
   BYREF SrcFileName AS WSTRINGZ _                      ' __in LPCWSTR SrcFileName
 , BYREF DstFileName AS WSTRINGZ _                      ' __in LPCWSTR DstFileName
 , BYVAL dwCreationDistribution AS DWORD _              ' __in DWORD dwCreationDistribution
 , BYVAL dwAttributes AS DWORD _                        ' __in DWORD dwAttributes
 , BYREF lpSecurityAttributes AS SECURITY_ATTRIBUTES _  ' __in CONST LPSECURITY_ATTRIBUTES lpSecurityAttributes
 ) AS DWORD                                             ' DWORD
'#endif

'// *EncryptedFileMetadata routines were not available pre-LH
'#if (NTDDI_VERSION >= NTDDI_VISTA)

DECLARE FUNCTION GetEncryptedFileMetadata IMPORT "ADVAPI32.DLL" ALIAS "GetEncryptedFileMetadata" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in  LPCWSTR lpFileName
 , BYREF pcbMetadata AS DWORD _                         ' __out PDWORD  pcbMetadata
 , BYREF ppbMetadata AS ANY _                           ' __out PBYTE  *ppbMetadata
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetEncryptedFileMetadata LIB "ADVAPI32.DLL" _
    ALIAS "SetEncryptedFileMetadata" (lpFileName AS WSTRINGZ, _
    BYVAL pbOldMetadata AS BYTE PTR, BYVAL pbNewMetadata AS BYTE PTR, _
    pOwnerHash AS ENCRYPTION_CERTIFICATE_HASH, BYVAL dwOperation AS DWORD, _
    BYVAL pCertificatesAddes AS ENCRYPTION_CERTIFICATE_HASH_LIST PTR) AS DWORD
#ELSE
DECLARE FUNCTION SetEncryptedFileMetadata IMPORT "ADVAPI32.DLL" ALIAS "SetEncryptedFileMetadata" ( _
   BYREF lpFileName AS WSTRINGZ _                       ' __in     LPCWSTR                           lpFileName
 , BYVAL pbOldMetadata AS BYTE PTR _                    ' __in_opt PBYTE                             pbOldMetadata
 , BYVAL pbNewMetadata AS BYTE PTR _                    ' __in     PBYTE                             pbNewMetadata
 , BYREF pOwnerHash AS ENCRYPTION_CERTIFICATE_HASH _    ' __in     PENCRYPTION_CERTIFICATE_HASH      pOwnerHash
 , BYVAL dwOperation AS DWORD _                         ' __in     DWORD                             dwOperation
 , BYREF pCertificatesAdded AS ENCRYPTION_CERTIFICATE_HASH_LIST _ ' __in_opt PENCRYPTION_CERTIFICATE_HASH_LIST pCertificatesAdded
 ) AS DWORD                                             ' DWORD
#ENDIF

DECLARE SUB FreeEncryptedFileMetadata IMPORT "ADVAPI32.DLL" ALIAS "FreeEncryptedFileMetadata" ( _
   BYVAL BYTE PTR _                           ' __in PBYTE pbMetadata
 )                                            ' void

'#endif // #if (NTDDI_VERSION >= NTDDI_VISTA)

'#endif // #if (NTDDI_VERSION >= NTDDI_WIN2K)
