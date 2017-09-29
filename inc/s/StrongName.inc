' ########################################################################################
' Microsoft Windows
' File: StrongName.inc
' Contents: Wrappers for signing and hashing functions needed to implement strong names
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRONGNAME_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "ole2.inc"

#INCLUDE ONCE "corerror.inc"

'// Public key blob binary format.
' // Size = 16 bytes
TYPE PublicKeyBlob DWORD
   SigAlgID     AS DWORD   ' unsigned int // (ALG_ID) signature algorithm used to create the signature
   HashAlgID    AS DWORD   ' unsigned int // (ALG_ID) hash algorithm used to create the signature
   cbPublicKey  AS DWORD   ' ULONG // length of the key in bytes
   PublicKey(0) AS BYTE    ' BYTE // variable length byte array containing the key value in format output by CryptoAPI
END TYPE

'// Location in the registry (under HKLM) that strong name configuration info is
'// stored.
$SN_CONFIG_KEY               = "Software\Microsoft\StrongName"
$SN_CONFIG_CSP               = "CSP"                  ' // REG_SZ
$SN_CONFIG_MACHINE_KEYSET    = "MachineKeyset"        ' // REG_DWORD
$SN_CONFIG_KEYSPEC           = "KeySpec"              ' // REG_DWORD
$SN_CONFIG_HASH_ALG          = "HashAlgorithm"        ' // REG_DWORD
$SN_CONFIG_SIGN_ALG          = "SignAlgorithm"        ' // REG_DWORD
$SN_CONFIG_VERIFICATION      = "Verification"         ' // Registry subkey
$SN_CONFIG_USERLIST          = "UserList"             ' // REG_MULTI_SZ
$SN_CONFIG_CACHE_VERIFY      = "CacheVerify"          ' // REG_DWORD

$$SN_CONFIG_KEY_W            = "Software\Microsoft\StrongName"$$
$$SN_CONFIG_CSP_W            = "CSP"$$                  ' // REG_SZ
$$SN_CONFIG_MACHINE_KEYSET_W = "MachineKeyset"$$        ' // REG_DWORD
$$SN_CONFIG_KEYSPEC_W        = "KeySpec"$$              ' // REG_DWORD
$$SN_CONFIG_HASH_ALG_W       = "HashAlgorithm"$$        ' // REG_DWORD
$$SN_CONFIG_SIGN_ALG_W       = "SignAlgorithm"$$        ' // REG_DWORD
$$SN_CONFIG_VERIFICATION_W   = "Verification"$$         ' // Registry subkey
$$SN_CONFIG_USERLIST_W       = "UserList"$$             ' // REG_MULTI_SZ
$$SN_CONFIG_CACHE_VERIFY_W   = "CacheVerify"$$          ' // REG_DWORD

'// VM related registry locations (Note, these values are under HKLM\Software\Microsoft\.NETFramework, rather
'// than SN_CONFIG_KEY
$SN_CONFIG_BYPASS_POLICY    = "AllowStrongNameBypass"     ' // REG_DWORD
$$SN_CONFIG_BYPASS_POLICY_W = "AllowStrongNameBypass"$$   ' // REG_DWORD

'#define SNAPI BOOLEAN __stdcall
'#define SNAPI_(_type) _type __stdcall

'// Return last error.
DECLARE FUNCTION StrongNameErrorInfo IMPORT "MsCorEE.dll" ALIAS "StrongNameErrorInfo" () AS DWORD

'// Free buffer allocated by routines below.
DECLARE SUB StrongNameFreeBuffer IMPORT "MsCorEE.dll" ALIAS "StrongNameFreeBuffer" ( _
   BYVAL pbMemory AS BYTE PTR _                         ' __in BYTE *pbMemory // address of memory to free
 )                                                      ' void

'// Generate a new key pair for strong name use.
DECLARE FUNCTION StrongNameKeyGen IMPORT "MsCorEE.dll" ALIAS "StrongNameKeyGen" ( _
   BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer // desired key container name
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags         // flags (see below)
 , BYREF ppbKeyBlob AS DWORD _                          ' __out BYTE   **ppbKeyBlob      // public/private key blob
 , BYREF pcbKeyBlob AS DWORD _                          ' __out ULONG   *pcbKeyBlob
 ) AS BYTE                                              ' BOOLEAN

'// Generate a new key pair with the specified key size for strong name use.
DECLARE FUNCTION StrongNameKeyGenEx IMPORT "MsCorEE.dll" ALIAS "StrongNameKeyGenEx" ( _
   BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer // desired key container name
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags         // flags (see below)
 , BYVAL dwKeySize AS DWORD _                           ' __in  DWORD    dwKeySize       // desired key size.
 , BYREF ppbKeyBlob AS DWORD _                          ' __out BYTE   **ppbKeyBlob      // public/private key blob
 , BYREF pcbKeyBlob AS DWORD _                          ' __out ULONG   *pcbKeyBlob
 ) AS BYTE                                              ' BOOLEAN

'// Flags for StrongNameKeyGen.
%SN_LEAVE_KEY    = &H00000001???            ' // Leave key pair registered with CSP

'// Import key pair into a key container.
DECLARE FUNCTION StrongNameKeyInstall IMPORT "MsCorEE.dll" ALIAS "StrongNameKeyInstall" ( _
   BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer // desired key container name
 , BYVAL pbKeyBlob AS BYTE PTR _                        ' __in  BYTE    *pbKeyBlob       // public/private key blob
 , BYVAL cbKeyBlob AS DWORD _                           ' __in  ULONG    cbKeyBlob
 ) AS BYTE                                              ' BOOLEAN

'// Delete a key pair.
DECLARE FUNCTION StrongNameKeyDelete IMPORT "MsCorEE.dll" ALIAS "StrongNameKeyDelete" ( _
   BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer // desired key container name
 ) AS BYTE                                              ' BOOLEAN

'// Retrieve the public portion of a key pair.
DECLARE FUNCTION StrongNameGetPublicKey IMPORT "MsCorEE.dll" ALIAS "StrongNameGetPublicKey" ( _
   BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer    // desired key container name
 , BYVAL pbKeyBlob AS BYTE PTR _                        ' __in  BYTE    *pbKeyBlob          // public/private key blob (optional)
 , BYVAL cbKeyBlob AS DWORD _                           ' __in  ULONG    cbKeyBlob
 , BYREF ppbPublicKeyBlob AS DWORD _                    ' __out BYTE   **ppbPublicKeyBlob   // public key blob
 , BYREF pcbPublicKeyBlob AS DWORD _                    ' __out ULONG   *pcbPublicKeyBlob
 ) AS BYTE                                              ' BOOLEAN

'// Hash and sign a manifest.
DECLARE FUNCTION StrongNameSignatureGeneration IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureGeneration" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath        // valid path to the PE file for the assembly
 , BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer    // desired key container name
 , BYVAL pbKeyBlob AS BYTE PTR _                        ' __in  BYTE    *pbKeyBlob          // public/private key blob (optional)
 , BYVAL cbKeyBlob AS DWORD _                           ' __in  ULONG    cbKeyBlob
 , BYREF ppbSignatureBlob AS DWORD _                    ' __out BYTE   **ppbSignatureBlob   // signature blob
 , BYREF pcbSignatureBlob AS DWORD _                    ' __out ULONG   *pcbSignatureBlob
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION StrongNameSignatureGenerationEx IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureGenerationEx" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath        // valid path to the PE file for the assembly
 , BYREF wszKeyContainer AS WSTRINGZ _                  ' __in  LPCWSTR  wszKeyContainer    // desired key container name
 , BYVAL pbKeyBlob AS BYTE PTR _                        ' __in  BYTE    *pbKeyBlob          // public/private key blob (optional)
 , BYVAL cbKeyBlob AS DWORD _                           ' __in  ULONG    cbKeyBlob
 , BYREF ppbSignatureBlob AS DWORD _                    ' __out BYTE   **ppbSignatureBlob   // signature blob
 , BYREF pcbSignatureBlob AS DWORD _                    ' __out ULONG   *pcbSignatureBlob
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD    dwFlags            // modifer flags
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%FEATURE_PLATFORM_ASSEMBLY_ALLOWLIST)
DECLARE FUNCTION StrongNameSetPlatformSignatureSequence IMPORT "MsCorEE.dll" ALIAS "StrongNameSetPlatformSignatureSequence" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in LPCWSTR wszFilePath // valid path to the PE file for the assembly
 , BYVAL flags AS DWORD _                               ' __in DWORD   flags       // flags detailing which parts of the signature to apply
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION StrongNameHasPlatformSignatureSequence IMPORT "MsCorEE.dll" ALIAS "StrongNameHasPlatformSignatureSequence" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in LPCWSTR wszFilePath // valid path to the PE file for the assembly
 ) AS BYTE                                              ' BOOLEAN
#ENDIF   ' // FEATURE_PLATFORM_ASSEMBLY_ALLOWLIST

%SN_SIGN_ALL_FILES   = &H00000001???     ' // Rehash all linked modules as well as resigning the manifest
%SN_TEST_SIGN        = &H00000002???     ' // Test sign the assembly

'// Create a strong name token from an assembly file.
DECLARE FUNCTION StrongNameTokenFromAssembly IMPORT "MsCorEE.dll" ALIAS "StrongNameTokenFromAssembly" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath          // valid path to the PE file for the assembly
 , BYREF ppbStrongNameToken AS DWORD _                  ' __out BYTE   **ppbStrongNameToken   // strong name token
 , BYREF pcbStrongNameToken AS DWORD _                  ' __out ULONG   *pcbStrongNameToken
 ) AS BYTE                                              ' BOOLEAN

'// Create a strong name token from an assembly file and additionally return the full public key.
DECLARE FUNCTION StrongNameTokenFromAssemblyEx IMPORT "MsCorEE.dll" ALIAS "StrongNameTokenFromAssemblyEx" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath          // valid path to the PE file for the assembly
 , BYREF ppbStrongNameToken AS DWORD _                  ' __out BYTE   **ppbStrongNameToken   // strong name token
 , BYREF pcbStrongNameToken AS DWORD _                  ' __out ULONG   *pcbStrongNameToken
 , BYREF ppbPublicKeyBlob AS DWORD _                    ' __out BYTE   **ppbPublicKeyBlob     // public key blob
 , BYREF pcbPublicKeyBlob AS DWORD _                    ' __out ULONG   *pcbPublicKeyBlob
 ) AS BYTE                                              ' BOOLEAN

'// Create a strong name token from a public key blob.
DECLARE FUNCTION StrongNameTokenFromPublicKey IMPORT "MsCorEE.dll" ALIAS "StrongNameTokenFromPublicKey" ( _
   BYVAL pbPublicKeyBlob AS BYTE PTR _                  ' __in  BYTE    *pbPublicKeyBlob      // public key blob
 , BYVAL cbPublicKeyBlob AS DWORD _                     ' __in  ULONG    cbPublicKeyBlob
 , BYREF ppbStrongNameToken AS DWORD _                  ' __out BYTE   **ppbStrongNameToken   // strong name token
 , BYREF pcbStrongNameToken AS DWORD _                  ' __out ULONG   *pcbStrongNameToken
 ) AS BYTE                                              ' BOOLEAN


'// Verify a strong name/manifest against a public key blob.
DECLARE FUNCTION StrongNameSignatureVerification IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureVerification" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath // valid path to the PE file for the assembly
 , BYVAL dwInFlags AS DWORD _                           ' __in  DWORD    dwInFlags   // flags modifying behaviour
 , BYREF pdwOutFlags AS DWORD _                         ' __out DWORD   *pdwOutFlags // additional output info
 ) AS BYTE                                              ' BOOLEAN

'// Verify a strong name/manifest against a public key blob.
DECLARE FUNCTION StrongNameSignatureVerificationEx IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureVerificationEx" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in  LPCWSTR  wszFilePath          // valid path to the PE file for the assembly
 , BYVAL fForceVerification AS BYTE _                   ' __in  BOOLEAN  fForceVerification   // verify even if settings in the registry disable it
 , BYREF pfWasVerified AS BYTE _                        ' __out BOOLEAN *pfWasVerified        // set to false if verify succeeded due to registry settings
 ) AS BYTE                                              ' BOOLEAN

'// Verify a strong name/manifest against a public key blob.
DECLARE FUNCTION StrongNameSignatureVerificationEx2 IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureVerificationEx2" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in LPCWSTR   wszFilePath          // valid path to the PE file for the assembly
 , BYVAL fForceVerification AS BYTE _                   ' __in BOOLEAN   fForceVerification   // verify even if settings in the registry disable it
 , BYREF pbEcmaPublicKey AS BYTE _                      ' __in BYTE     *pbEcmaPublicKey // [in] mapping from the ECMA public key to the real key used for verification
 , BYVAL cbEcmaPublicKey AS DWORD _                     ' __in DWORD     cbEcmaPublicKey // [in] length of the real ECMA public key
 , BYREF pfWasVerified AS BYTE _                        ' __out BOOLEAN *pfWasVerified        // set to false if verify succeeded due to registry settings
 ) AS BYTE                                              ' BOOLEAN

'// Verify a strong name/manifest against a public key blob when the assembly is
'// already memory mapped.
DECLARE FUNCTION StrongNameSignatureVerificationFromImage IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureVerificationFromImage" ( _
   BYVAL pbBase AS BYTE PTR _                           ' __in  BYTE  *pbBase       // base address of mapped manifest file
 , BYVAL dwLength AS DWORD _                            ' __in  DWORD  dwLength     // length of mapped image in bytes
 , BYVAL dwInFlags AS DWORD _                           ' __in  DWORD  dwInFlags    // flags modifying behaviour
 , BYREF pdwOutFlags AS DWORD _                         ' __out DWORD *pdwOutFlags  // additional output info
 ) AS BYTE                                              ' BOOLEAN

'// Flags for use with the verify routines.
%SN_INFLAG_FORCE_VER            = &H00000001???   ' // verify even if settings in the registry disable it
%SN_INFLAG_INSTALL              = &H00000002???   ' // verification is the first (on entry to the cache)
%SN_INFLAG_ADMIN_ACCESS         = &H00000004???   ' // cache protects assembly from all but admin access
%SN_INFLAG_USER_ACCESS          = &H00000008???   ' // cache protects user's assembly from other users
%SN_INFLAG_ALL_ACCESS           = &H00000010???   ' // cache provides no access restriction guarantees
#IF %DEF(%FEATURE_PLATFORM_ASSEMBLY_ALLOWLIST)
%SN_INFLAG_GAC_ASSEMBLY         = &H00000020???   ' // Flag that indicates the assembly is from the "GAC"
%SN_INFLAG_MAPPED_PEFILE        = &H00000040???   ' // Flag that indicates the assembly PE File is memory-mapped (not flat)
%SN_INFLAG_RELOCATED_PEFILE     = &H00000080???   ' // Flag that indicates the assembly PE File is memory-mapped (not flat) and relocated
#ENDIF   ' // FEATURE_PLATFORM_ASSEMBLY_ALLOWLIST
%SN_INFLAG_RUNTIME              = &H80000000???   ' // internal debugging use only

%SN_OUTFLAG_WAS_VERIFIED        = &H00000001???   ' // set to false if verify succeeded due to registry settings
%SN_OUTFLAG_MICROSOFT_SIGNATURE = &H00000002???   ' // set if the public key corresponds to SN_THE_KEY

#IF %DEF(%FEATURE_STRONGNAME_TESTKEY_ALLOWED)
%SN_OUTFLAG_TESTKEY_SIGNATURE   = &H00000004???   ' // set if the public key corresponds to SN_THE_TESTKEY
#ENDIF   ' // FEATURE_STRONGNAME_TESTKEY_ALLOWED
%SN_OUTFLAG_SILVERLIGHT_PLATFORM_SIGNATURE = &H00000008???   ' // set if the public key corresponds to the Silverlight Platform key

'// Verify that two assemblies differ only by signature blob.
DECLARE FUNCTION StrongNameCompareAssemblies IMPORT "MsCorEE.dll" ALIAS "StrongNameCompareAssemblies" ( _
   BYREF wszAssembly1 AS WSTRINGZ _                     ' __in  LPCWSTR  wszAssembly1 // file name of first assembly
 , BYREF wszAssembly2 AS WSTRINGZ _                     ' __in  LPCWSTR  wszAssembly2 // file name of second assembly
 , BYREF pdwResult AS DWORD _                           ' __out DWORD   *pdwResult    // result of comparison
 ) AS BYTE                                              ' BOOLEAN

%SN_CMP_DIFFERENT   = 0  ' // Assemblies contain different data
%SN_CMP_IDENTICAL   = 1  ' // Assemblies are exactly the same, even signatures
%SN_CMP_SIGONLY     = 2  ' // Assemblies differ only by signature (and checksum etc.)

'// Compute the size of buffer needed to hold a hash for a given hash algorithm.
DECLARE FUNCTION StrongNameHashSize IMPORT "MsCorEE.dll" ALIAS "StrongNameHashSize" ( _
   BYVAL ulHashAlg AS DWORD _                           ' __in  ULONG  ulHashAlg // hash algorithm
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize   // size of the hash in bytes
 ) AS BYTE                                              ' BOOLEAN

'// Compute the size that needs to be allocated for a signature in an assembly.
DECLARE FUNCTION StrongNameSignatureSize IMPORT "MsCorEE.dll" ALIAS "StrongNameSignatureSize" ( _
   BYVAL pbPublicKeyBlob AS BYTE PTR _                  ' __in  BYTE  *pbPublicKeyBlob // public key blob
 , BYVAL cbPublicKeyBlob AS DWORD _                     ' __in  ULONG  cbPublicKeyBlob
 , BYREF pcbSize AS DWORD _                             ' __out DWORD *pcbSize         // size of the signature in bytes
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION GetHashFromAssemblyFile IMPORT "MsCorEE.dll" ALIAS "GetHashFromAssemblyFile" ( _
   BYREF szFilePath AS ASCIIZ _                         ' __in     LPCSTR        szFilePath // location of file to be hashed
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg  // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash     // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash    // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash    // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetHashFromAssemblyFileW IMPORT "MsCorEE.dll" ALIAS "GetHashFromAssemblyFileW" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in     LPCWSTR       wszFilePath // location of file to be hashed
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg   // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash      // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash     // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash     // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetHashFromFile IMPORT "MsCorEE.dll" ALIAS "GetHashFromFile" ( _
   BYREF szFilePath AS ASCIIZ _                         ' __in     LPCSTR        szFilePath  // location of file to be hashed
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg   // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash      // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash     // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash     // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetHashFromFileW IMPORT "MsCorEE.dll" ALIAS "GetHashFromFileW" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in     LPCWSTR       wszFilePath // location of file to be hashed
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg   // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash      // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash     // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash     // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetHashFromHandle IMPORT "MsCorEE.dll" ALIAS "GetHashFromHandle" ( _
   BYVAL hFile AS DWORD _                               ' __in     HANDLE        hFile       // handle of file to be hashed
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg   // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash      // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash     // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash     // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetHashFromBlob IMPORT "MsCorEE.dll" ALIAS "GetHashFromBlob" ( _
   BYVAL pbBlob AS BYTE PTR _                           ' __in     BYTE         *pbBlob      // pointer to memory block to hash
 , BYVAL cchBlob AS DWORD _                             ' __in     DWORD         cchBlob     // length of blob
 , BYREF piHashAlg AS DWORD _                           ' __in_out unsigned int *piHashAlg   // constant specifying the hash algorithm (set to 0 if you want the default)
 , BYREF pbHash AS DWORD _                              ' __out    BYTE         *pbHash      // hash buffer
 , BYVAL cchHash AS DWORD _                             ' __in     ULONG         cchHash     // max size of buffer
 , BYREF pchHash AS DWORD _                             ' __out    DWORD        *pchHash     // length of hash byte array
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION StrongNameGetBlob IMPORT "MsCorEE.dll" ALIAS "StrongNameGetBlob" ( _
   BYREF wszFilePath AS WSTRINGZ _                      ' __in     LPCWSTR       wszFilePath // valid path to the PE file for the assembly
 , BYVAL pbBlob AS BYTE PTR _                           ' __in     BYTE         *pbBlob      // buffer to fill with blob
 , BYREF pcbBlob AS DWORD _                             ' __in_out DWORD        *pcbBlob     // size of buffer/number of bytes put into buffer
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION StrongNameGetBlobFromImage IMPORT "MsCorEE.dll" ALIAS "StrongNameGetBlobFromImage" ( _
   BYVAL pbBase AS BYTE PTR _                           ' __in     BYTE         *pbBase      // base address of mapped manifest file
 , BYVAL dwLength AS DWORD _                            ' __in     DWORD         dwLength    // length of mapped image in bytes
 , BYVAL pbBlob AS BYTE PTR _                           ' __in     BYTE         *pbBlob      // buffer to fill with blob
 , BYREF pcbBlob AS DWORD _                             ' __in_out DWORD        *pcbBlob     // size of buffer/number of bytes put into buffer
 ) AS BYTE                                              ' BOOLEAN
