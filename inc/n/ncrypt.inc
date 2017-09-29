' ########################################################################################
' Microsoft Windows
' File: ncrypt.inc
' Contents: Cryptographic API Prototypes and Definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NCRYPT_INC = 1

'#ifndef __SECSTATUS_DEFINED__
'typedef LONG SECURITY_STATUS;
'#define __SECSTATUS_DEFINED__
'#endif

#INCLUDE ONCE "bcrypt.inc"

'//
'// Microsoft built-in providers.
'//

$$MS_KEY_STORAGE_PROVIDER            = "Microsoft Software Key Storage Provider"$$
$$MS_SMART_CARD_KEY_STORAGE_PROVIDER = "Microsoft Smart Card Key Storage Provider"$$

'//
'// Common algorithm identifiers.
'//

$$NCRYPT_RSA_ALGORITHM            = $$BCRYPT_RSA_ALGORITHM
$$NCRYPT_RSA_SIGN_ALGORITHM       = $$BCRYPT_RSA_SIGN_ALGORITHM
$$NCRYPT_DH_ALGORITHM             = $$BCRYPT_DH_ALGORITHM
$$NCRYPT_DSA_ALGORITHM            = $$BCRYPT_DSA_ALGORITHM
$$NCRYPT_MD2_ALGORITHM            = $$BCRYPT_MD2_ALGORITHM
$$NCRYPT_MD4_ALGORITHM            = $$BCRYPT_MD4_ALGORITHM
$$NCRYPT_MD5_ALGORITHM            = $$BCRYPT_MD5_ALGORITHM
$$NCRYPT_SHA1_ALGORITHM           = $$BCRYPT_SHA1_ALGORITHM
$$NCRYPT_SHA256_ALGORITHM         = $$BCRYPT_SHA256_ALGORITHM
$$NCRYPT_SHA384_ALGORITHM         = $$BCRYPT_SHA384_ALGORITHM
$$NCRYPT_SHA512_ALGORITHM         = $$BCRYPT_SHA512_ALGORITHM
$$NCRYPT_ECDSA_P256_ALGORITHM     = $$BCRYPT_ECDSA_P256_ALGORITHM
$$NCRYPT_ECDSA_P384_ALGORITHM     = $$BCRYPT_ECDSA_P384_ALGORITHM
$$NCRYPT_ECDSA_P521_ALGORITHM     = $$BCRYPT_ECDSA_P521_ALGORITHM
$$NCRYPT_ECDH_P256_ALGORITHM      = $$BCRYPT_ECDH_P256_ALGORITHM
$$NCRYPT_ECDH_P384_ALGORITHM      = $$BCRYPT_ECDH_P384_ALGORITHM
$$NCRYPT_ECDH_P521_ALGORITHM      = $$BCRYPT_ECDH_P521_ALGORITHM

$$NCRYPT_KEY_STORAGE_ALGORITHM            = "KEY_STORAGE"$$

'//
'// Interfaces
'//

%NCRYPT_HASH_INTERFACE                   = %BCRYPT_HASH_INTERFACE
%NCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE  = %BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE

%NCRYPT_SECRET_AGREEMENT_INTERFACE       = %BCRYPT_SECRET_AGREEMENT_INTERFACE

%NCRYPT_SIGNATURE_INTERFACE              = %BCRYPT_SIGNATURE_INTERFACE

%NCRYPT_KEY_STORAGE_INTERFACE            = &H00010001???
%NCRYPT_SCHANNEL_INTERFACE               = &H00010002???
%NCRYPT_SCHANNEL_SIGNATURE_INTERFACE     = &H00010003???

'//
'// algorithm groups.
'//

$$NCRYPT_RSA_ALGORITHM_GROUP      = $$NCRYPT_RSA_ALGORITHM
$$NCRYPT_DH_ALGORITHM_GROUP       = $$NCRYPT_DH_ALGORITHM
$$NCRYPT_DSA_ALGORITHM_GROUP      = $$NCRYPT_DSA_ALGORITHM
$$NCRYPT_ECDSA_ALGORITHM_GROUP    = "ECDSA"$$
$$NCRYPT_ECDH_ALGORITHM_GROUP     = "ECDH"$$

'//
'// NCrypt generic memory descriptors
'//

%NCRYPTBUFFER_VERSION               = 0

%NCRYPTBUFFER_EMPTY                 = 0
%NCRYPTBUFFER_DATA                  = 1
%NCRYPTBUFFER_SSL_CLIENT_RANDOM     = 20
%NCRYPTBUFFER_SSL_SERVER_RANDOM     = 21
%NCRYPTBUFFER_SSL_HIGHEST_VERSION   = 22
%NCRYPTBUFFER_SSL_CLEAR_KEY         = 23
%NCRYPTBUFFER_SSL_KEY_ARG_DATA      = 24

%NCRYPTBUFFER_PKCS_OID              = 40
%NCRYPTBUFFER_PKCS_ALG_OID          = 41
%NCRYPTBUFFER_PKCS_ALG_PARAM        = 42
%NCRYPTBUFFER_PKCS_ALG_ID           = 43
%NCRYPTBUFFER_PKCS_ATTRS            = 44
%NCRYPTBUFFER_PKCS_KEY_NAME         = 45
%NCRYPTBUFFER_PKCS_SECRET           = 46

%NCRYPTBUFFER_CERT_BLOB             = 47

'// NCRYPT shares the same BCRYPT definitions
'typedef BCryptBuffer     NCryptBuffer;
'typedef BCryptBuffer*    PNCryptBuffer;
'typedef BCryptBufferDesc NCryptBufferDesc;
'typedef BCryptBufferDesc* PNCryptBufferDesc;

MACRO NCryptBuffer     = BCryptBuffer
MACRO NCryptBufferDesc = BCryptBufferDesc

'//
'// NCrypt handles
'//

'typedef ULONG_PTR NCRYPT_HANDLE;
'typedef ULONG_PTR NCRYPT_PROV_HANDLE;
'typedef ULONG_PTR NCRYPT_KEY_HANDLE;
'typedef ULONG_PTR NCRYPT_HASH_HANDLE;
'typedef ULONG_PTR NCRYPT_SECRET_HANDLE;


'//
'// NCrypt API Flags
'//

%NCRYPT_NO_PADDING_FLAG      = %BCRYPT_PAD_NONE
%NCRYPT_PAD_PKCS1_FLAG       = %BCRYPT_PAD_PKCS1  ' // NCryptEncrypt/Decrypt NCryptSignHash/VerifySignature
%NCRYPT_PAD_OAEP_FLAG        = %BCRYPT_PAD_OAEP   ' // BCryptEncrypt/Decrypt
%NCRYPT_PAD_PSS_FLAG         = %BCRYPT_PAD_PSS    ' // BCryptSignHash/VerifySignature
%NCRYPT_NO_KEY_VALIDATION    = %BCRYPT_NO_KEY_VALIDATION

%NCRYPT_MACHINE_KEY_FLAG                 = &H00000020???  ' // same as CAPI CRYPT_MACHINE_KEYSET
%NCRYPT_SILENT_FLAG                      = &H00000040???  ' // same as CAPI CRYPT_SILENT
%NCRYPT_OVERWRITE_KEY_FLAG               = &H00000080???
%NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG   = &H00000200???
%NCRYPT_DO_NOT_FINALIZE_FLAG             = &H00000400???
%NCRYPT_PERSIST_ONLY_FLAG                = &H40000000???
%NCRYPT_PERSIST_FLAG                     = &H80000000???
%NCRYPT_REGISTER_NOTIFY_FLAG             = &H00000001???
%NCRYPT_UNREGISTER_NOTIFY_FLAG           = &H00000002???


'//
'// Functions used to manage persisted keys.
'//

DECLARE FUNCTION NCryptOpenStorageProvider IMPORT "NCRYPT.DLL" ALIAS "NCryptOpenStorageProvider" ( _
   BYREF phProvider AS DWORD _                          ' __out    NCRYPT_PROV_HANDLE *phProvider
 , BYREF pszProviderName AS WSTRINGZ _                  ' __in_opt LPCWSTR pszProviderName
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

'// AlgOperations flags for use with NCryptEnumAlgorithms()
%NCRYPT_CIPHER_OPERATION                 = %BCRYPT_CIPHER_OPERATION
%NCRYPT_HASH_OPERATION                   = %BCRYPT_HASH_OPERATION
%NCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION  = %BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION
%NCRYPT_SECRET_AGREEMENT_OPERATION       = %BCRYPT_SECRET_AGREEMENT_OPERATION
%NCRYPT_SIGNATURE_OPERATION              = %BCRYPT_SIGNATURE_OPERATION
%NCRYPT_RNG_OPERATION                    = %BCRYPT_RNG_OPERATION

'// USE EXTREME CAUTION: editing comments that contain "certenrolls_*" tokens
'// could break building CertEnroll idl files:
'// certenrolls_begin -- NCryptAlgorithmName
' // Size = 16 bytes
TYPE NCryptAlgorithmName DWORD
   pszName         AS WSTRINGZ PTR   ' LPWSTR
   dwClass         AS DWORD          ' DWORD // the CNG interface that supports this algorithm
   dwAlgOperations AS DWORD          ' DWORD // the types of operations supported by this algorithm
   dwFlags         AS DWORD          ' DWORD
END TYPE

DECLARE FUNCTION NCryptEnumAlgorithms IMPORT "NCRYPT.DLL" ALIAS "NCryptEnumAlgorithms" ( _
   BYVAL hProvider AS DWORD _                           ' __in    NCRYPT_PROV_HANDLE hProvider
 , BYVAL dwAlgOperations AS DWORD _                     ' __in    DWORD   dwAlgOperations
 , BYREF pdwAlgCount AS DWORD _                         ' __out   DWORD * pdwAlgCount
 , BYREF ppAlgList AS ANY _                             ' __out   NCryptAlgorithmName **ppAlgList
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptIsAlgSupported IMPORT "NCRYPT.DLL" ALIAS "NCryptIsAlgSupported" ( _
   BYVAL hProvider AS DWORD _                           ' __in    NCRYPT_PROV_HANDLE hProvider
 , BYREF pszAlgId AS WSTRINGZ _                         ' __in    LPCWSTR pszAlgId
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


'// NCryptEnumKeys flags
%NCRYPT_MACHINE_KEY_FLAG         = &H00000020???

' // Size = 16 bytes
TYPE NCryptKeyName DWORD
   pszName         AS WSTRINGZ PTR   ' LPWSTR
   pszAlgid        AS WSTRINGZ PTR   ' LPWSTR
   dwLegacyKeySpec AS DWORD          ' DWORD
   dwFlags         AS DWORD          ' DWORD
END TYPE

DECLARE FUNCTION NCryptEnumKeys IMPORT "NCRYPT.DLL" ALIAS "NCryptEnumKeys" ( _
   BYVAL hProvider AS DWORD _                           ' __in     NCRYPT_PROV_HANDLE hProvider
 , BYREF pszScope AS WSTRINGZ _                         ' __in_opt LPCWSTR pszScope
 , BYREF ppKeyName AS ANY _                             ' __out    NCryptKeyName **ppKeyName
 , BYREF ppEnumState AS DWORD _                         ' __inout  PVOID * ppEnumState
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

' // Size = 8 bytes
TYPE NCryptProviderName DWORD
   pszName    AS WSTRINGZ PTR   ' LPWSTR
   pszComment AS WSTRINGZ PTR   ' LPWSTR
END TYPE

DECLARE FUNCTION NCryptEnumStorageProviders IMPORT "NCRYPT.DLL" ALIAS "NCryptEnumStorageProviders" ( _
   BYREF pdwProviderCount AS DWORD _                    ' __out DWORD * pdwProviderCount
 , BYREF ppProviderList AS ANY _                        ' __out NCryptProviderName **ppProviderList
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptFreeBuffer IMPORT "NCRYPT.DLL" ALIAS "NCryptFreeBuffer" ( _
   BYVAL pvInput AS DWORD _                             ' __deref PVOID   pvInput
 ) AS LONG                                              ' SECURITY_STATUS


'// NCryptOpenKey flags
%NCRYPT_MACHINE_KEY_FLAG         = &H00000020???
%NCRYPT_SILENT_FLAG              = &H00000040???

DECLARE FUNCTION NCryptOpenKey IMPORT "NCRYPT.DLL" ALIAS "NCryptOpenKey" ( _
   BYVAL hProvider AS DWORD _                           ' __inout  NCRYPT_PROV_HANDLE hProvider
 , BYREF phKey AS DWORD _                               ' __out    NCRYPT_KEY_HANDLE *phKey
 , BYREF pszKeyName AS WSTRINGZ _                       ' __in     LPCWSTR pszKeyName
 , BYVAL dwLegacyKeySpec AS DWORD _                     ' __in_opt DWORD  dwLegacyKeySpec
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


'// NCryptCreatePersistedKey flags
%NCRYPT_MACHINE_KEY_FLAG         = &H00000020???
%NCRYPT_OVERWRITE_KEY_FLAG       = &H00000080???

DECLARE FUNCTION NCryptCreatePersistedKey IMPORT "NCRYPT.DLL" ALIAS "NCryptCreatePersistedKey" ( _
   BYVAL hProvider AS DWORD _                           ' __in     NCRYPT_PROV_HANDLE hProvider
 , BYREF phKey AS DWORD _                               ' __out    NCRYPT_KEY_HANDLE *phKey
 , BYREF pszAlgId AS WSTRINGZ _                         ' __in     LPCWSTR pszAlgId
 , BYREF pszKeyName AS WSTRINGZ _                       ' __in_opt LPCWSTR pszKeyName
 , BYVAL dwLegacyKeySpec AS DWORD _                     ' __in     DWORD   dwLegacyKeySpec
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


'// Standard property names.
$$NCRYPT_NAME_PROPERTY                    = "Name"$$
$$NCRYPT_UNIQUE_NAME_PROPERTY             = "Unique Name"$$
$$NCRYPT_ALGORITHM_PROPERTY               = "Algorithm Name"$$
$$NCRYPT_LENGTH_PROPERTY                  = "Length"$$
$$NCRYPT_LENGTHS_PROPERTY                 = "Lengths"$$
$$NCRYPT_BLOCK_LENGTH_PROPERTY            = "Block Length"$$
$$NCRYPT_UI_POLICY_PROPERTY               = "UI Policy"$$
$$NCRYPT_EXPORT_POLICY_PROPERTY           = "Export Policy"$$
$$NCRYPT_WINDOW_HANDLE_PROPERTY           = "HWND Handle"$$
$$NCRYPT_USE_CONTEXT_PROPERTY             = "Use Context"$$
$$NCRYPT_IMPL_TYPE_PROPERTY               = "Impl Type"$$
$$NCRYPT_KEY_USAGE_PROPERTY               = "Key Usage"$$
$$NCRYPT_KEY_TYPE_PROPERTY                = "Key Type"$$
$$NCRYPT_VERSION_PROPERTY                 = "Version"$$
$$NCRYPT_SECURITY_DESCR_SUPPORT_PROPERTY  = "Security Descr Support"$$
$$NCRYPT_SECURITY_DESCR_PROPERTY          = "Security Descr"$$
$$NCRYPT_USE_COUNT_ENABLED_PROPERTY       = "Enabled Use Count"$$
$$NCRYPT_USE_COUNT_PROPERTY               = "Use Count"$$
$$NCRYPT_LAST_MODIFIED_PROPERTY           = "Modified"$$
$$NCRYPT_MAX_NAME_LENGTH_PROPERTY         = "Max Name Length"$$
$$NCRYPT_ALGORITHM_GROUP_PROPERTY         = "Algorithm Group"$$
$$NCRYPT_DH_PARAMETERS_PROPERTY           = $$BCRYPT_DH_PARAMETERS
$$NCRYPT_PROVIDER_HANDLE_PROPERTY         = "Provider Handle"$$
$$NCRYPT_PIN_PROPERTY                     = "SmartCardPin"$$
$$NCRYPT_READER_PROPERTY                  = "SmartCardReader"$$
$$NCRYPT_SMARTCARD_GUID_PROPERTY          = "SmartCardGuid"$$
$$NCRYPT_CERTIFICATE_PROPERTY             = "SmartCardKeyCertificate"$$
$$NCRYPT_PIN_PROMPT_PROPERTY              = "SmartCardPinPrompt"$$
$$NCRYPT_USER_CERTSTORE_PROPERTY          = "SmartCardUserCertStore"$$
$$NCRYPT_ROOT_CERTSTORE_PROPERTY          = "SmartcardRootCertStore"$$
$$NCRYPT_SECURE_PIN_PROPERTY              = "SmartCardSecurePin"$$
$$NCRYPT_ASSOCIATED_ECDH_KEY              = "SmartCardAssociatedECDHKey"$$
$$NCRYPT_SCARD_PIN_ID                     = "SmartCardPinId"$$
$$NCRYPT_SCARD_PIN_INFO                   = "SmartCardPinInfo"$$

'// Maximum length of property name (in characters)
%NCRYPT_MAX_PROPERTY_NAME       = 64

'// Maximum length of property data (in bytes)
%NCRYPT_MAX_PROPERTY_DATA                = &H100000???

'// NCRYPT_EXPORT_POLICY_PROPERTY property flags.
%NCRYPT_ALLOW_EXPORT_FLAG                = &H00000001???
%NCRYPT_ALLOW_PLAINTEXT_EXPORT_FLAG      = &H00000002???
%NCRYPT_ALLOW_ARCHIVING_FLAG             = &H00000004???
%NCRYPT_ALLOW_PLAINTEXT_ARCHIVING_FLAG   = &H00000008???

'// NCRYPT_IMPL_TYPE_PROPERTY property flags.
%NCRYPT_IMPL_HARDWARE_FLAG               = &H00000001???
%NCRYPT_IMPL_SOFTWARE_FLAG               = &H00000002???
%NCRYPT_IMPL_REMOVABLE_FLAG              = &H00000008???
%NCRYPT_IMPL_HARDWARE_RNG_FLAG           = &H00000010???

'// NCRYPT_KEY_USAGE_PROPERTY property flags.
%NCRYPT_ALLOW_DECRYPT_FLAG               = &H00000001???
%NCRYPT_ALLOW_SIGNING_FLAG               = &H00000002???
%NCRYPT_ALLOW_KEY_AGREEMENT_FLAG         = &H00000004???
%NCRYPT_ALLOW_ALL_USAGES                 = &H00ffffff???

'// NCRYPT_UI_POLICY_PROPERTY property flags and structure
%NCRYPT_UI_PROTECT_KEY_FLAG              = &H00000001???
%NCRYPT_UI_FORCE_HIGH_PROTECTION_FLAG    = &H00000002???

' // Size = 20 bytes
TYPE NCRYPT_UI_POLICY_BLOB DWORD
   dwVersion       AS DWORD   ' DWORD
   dwFlags         AS DWORD   ' DWORD
   cbCreationTitle AS DWORD   ' DWORD
   cbFriendlyName  AS DWORD   ' DWORD
   cbDescription   AS DWORD   ' DWORD
   ' // creation title string
   ' // friendly name string
   ' // description string
END TYPE

' // Size = 20 bytes
TYPE NCRYPT_UI_POLICY DWORD
   dwVersion        AS DWORD          ' DWORD
   dwFlags          AS DWORD          ' DWORD
   pszCreationTitle AS WSTRINGZ PTR   ' LPCWSTR
   pszFriendlyName  AS WSTRINGZ PTR   ' LPCWSTR
   pszDescription   AS WSTRINGZ PTR   ' LPCWSTR
END TYPE


'// NCRYPT_LENGTHS_PROPERTY property structure.
' // Size = 16 bytes
TYPE NCRYPT_SUPPORTED_LENGTHS DWORD
   dwMinLength     AS DWORD   ' DWORD
   dwMaxLength     AS DWORD   ' DWORD
   dwIncrement     AS DWORD   ' DWORD
   dwDefaultLength AS DWORD   ' DWORD
END TYPE

'// NCryptGetProperty flags
%NCRYPT_PERSIST_ONLY_FLAG        = &H40000000???

DECLARE FUNCTION NCryptGetProperty IMPORT "NCRYPT.DLL" ALIAS "NCryptGetProperty" ( _
   BYVAL hObject AS DWORD _                             ' __in  NCRYPT_HANDLE hObject
 , BYREF pszProperty AS WSTRINGZ _                      ' __in  LPCWSTR pszProperty
 , BYVAL pbOutput AS DWORD _                            ' __out PBYTE pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in  DWORD   cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out DWORD * pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


'// NCryptSetProperty flags
%NCRYPT_PERSIST_FLAG             = &H80000000???
%NCRYPT_PERSIST_ONLY_FLAG        = &H40000000???

DECLARE FUNCTION NCryptSetProperty IMPORT "NCRYPT.DLL" ALIAS "NCryptSetProperty" ( _
   BYVAL hObject AS DWORD _                             ' __in NCRYPT_HANDLE hObject
 , BYREF pszProperty AS WSTRINGZ _                      ' __in LPCWSTR pszProperty
 , BYVAL pbInput AS BYTE PTR _                          ' __in PBYTE   pbInput
 , BYVAL cbInput AS DWORD _                             ' __in DWORD   cbInput
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


%NCRYPT_WRITE_KEY_TO_LEGACY_STORE_FLAG   = &H00000200???

DECLARE FUNCTION NCryptFinalizeKey IMPORT "NCRYPT.DLL" ALIAS "NCryptFinalizeKey" ( _
   BYVAL hKey AS DWORD _                                ' __in NCRYPT_KEY_HANDLE hKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptEncrypt IMPORT "NCRYPT.DLL" ALIAS "NCryptEncrypt" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PBYTE  pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     DWORD  cbInput
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID  *pPaddingInfo
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PBYTE  pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     DWORD  cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    DWORD *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptDecrypt IMPORT "NCRYPT.DLL" ALIAS "NCryptDecrypt" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PBYTE  pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     DWORD  cbInput
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID  *pPaddingInfo
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PBYTE  pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     DWORD  cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    DWORD *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

$$NCRYPT_PKCS7_ENVELOPE_BLOB      = "PKCS7_ENVELOPE"$$
$$NCRYPT_PKCS8_PRIVATE_KEY_BLOB   = "PKCS8_PRIVATEKEY"$$
$$NCRYPT_OPAQUETRANSPORT_BLOB     = "OpaqueTransport"$$

%NCRYPT_MACHINE_KEY_FLAG         = &H00000020???
%NCRYPT_DO_NOT_FINALIZE_FLAG     = &H00000400???
%NCRYPT_EXPORT_LEGACY_FLAG       = &H00000800???

DECLARE FUNCTION NCryptImportKey IMPORT "NCRYPT.DLL" ALIAS "NCryptImportKey" ( _
   BYVAL hProvider AS DWORD _                           ' __in     NCRYPT_PROV_HANDLE hProvider
 , BYVAL hImportKey AS DWORD _                          ' __in_opt NCRYPT_KEY_HANDLE hImportKey
 , BYREF pszBlobType AS WSTRINGZ _                      ' __in     LPCWSTR pszBlobType
 , BYREF pParameterList AS NCryptBufferDesc _           ' __in_opt NCryptBufferDesc *pParameterList
 , BYREF phKey AS DWORD _                               ' __out    NCRYPT_KEY_HANDLE *phKey
 , BYVAL pbData AS BYTE PTR _                           ' __in     PBYTE  pbData
 , BYVAL cbData AS DWORD _                              ' __in     DWORD  cbData
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD  dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptExportKey IMPORT "NCRYPT.DLL" ALIAS "NCryptExportKey" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYVAL hExportKey AS DWORD _                          ' __in_opt NCRYPT_KEY_HANDLE hExportKey
 , BYREF pszBlobType AS WSTRINGZ _                      ' __in     LPCWSTR pszBlobType
 , BYREF pParameterList AS NCryptBufferDesc _           ' __in_opt NCryptBufferDesc *pParameterList
 , BYVAL pbOutput AS DWORD _                            ' __out    PBYTE pbOutput
 , BYVAL pcbResult AS DWORD _                           ' __in     DWORD   cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    DWORD * pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptSignHash IMPORT "NCRYPT.DLL" ALIAS "NCryptSignHash" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID *pPaddingInfo
 , BYVAL pbHashValue AS BYTE PTR _                      ' __in     PBYTE pbHashValue
 , BYVAL cbHashValue AS DWORD _                         ' __in     DWORD cbHashValue
 , BYVAL pbSignature AS BYTE PTR _                      ' __out    PBYTE pbSignature
 , BYVAL cbSignature AS DWORD _                         ' __in     DWORD cbSignature
 , BYREF pcbResult AS DWORD _                           ' __out    DWORD *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptVerifySignature IMPORT "NCRYPT.DLL" ALIAS "NCryptVerifySignature" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID *pPaddingInfo
 , BYVAL pbHashValue AS BYTE PTR _                      ' __in     PBYTE pbHashValue
 , BYVAL cbHashValue AS DWORD _                         ' __in     DWORD cbHashValue
 , BYVAL pbSignature AS BYTE PTR _                      ' __in     PBYTE pbSignature
 , BYVAL cbSignature AS DWORD _                         ' __in     DWORD cbSignature
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptDeleteKey IMPORT "NCRYPT.DLL" ALIAS "NCryptDeleteKey" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptFreeObject IMPORT "NCRYPT.DLL" ALIAS "NCryptFreeObject" ( _
   BYVAL hObject AS DWORD _                             ' __in     NCRYPT_HANDLE hObject
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptIsKeyHandle IMPORT "NCRYPT.DLL" ALIAS "NCryptIsKeyHandle" ( _
   BYVAL hKey AS DWORD _                                ' __in     NCRYPT_KEY_HANDLE hKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION NCryptTranslateHandle IMPORT "NCRYPT.DLL" ALIAS "NCryptTranslateHandle" ( _
   BYREF phProvider AS DWORD _                          ' __out_opt NCRYPT_PROV_HANDLE *phProvider
 , BYREF phKey AS DWORD _                               ' __out     NCRYPT_KEY_HANDLE *phKey
 , BYVAL hLegacyProv AS DWORD _                         ' __in      HCRYPTPROV hLegacyProv
 , BYVAL hLegacyKey AS DWORD _                          ' __in_opt  HCRYPTKEY hLegacyKey
 , BYVAL dwLegacyKeySpec AS DWORD _                     ' __in_opt  DWORD     dwLegacyKeySpec
 , BYVAL dwFlags AS DWORD _                             ' __in      DWORD     dwFlags
 ) AS LONG                                              ' SECURITY_STATUS


'// NCryptNotifyChangeKey flags
%NCRYPT_REGISTER_NOTIFY_FLAG     = &H00000001???
%NCRYPT_UNREGISTER_NOTIFY_FLAG   = &H00000002???
%NCRYPT_MACHINE_KEY_FLAG         = &H00000020???

DECLARE FUNCTION NCryptNotifyChangeKey IMPORT "NCRYPT.DLL" ALIAS "NCryptNotifyChangeKey" ( _
   BYVAL hProvider AS DWORD _                           ' __in    NCRYPT_PROV_HANDLE hProvider
 , BYREF phEvent AS DWORD _                             ' __inout HANDLE *phEvent
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptSecretAgreement IMPORT "NCRYPT.DLL" ALIAS "NCryptSecretAgreement" ( _
   BYVAL hPrivKey AS DWORD _                            ' __in    NCRYPT_KEY_HANDLE hPrivKey
 , BYVAL hPubKey AS DWORD _                             ' __in    NCRYPT_KEY_HANDLE hPubKey
 , BYREF phAgreedSecret AS DWORD _                      ' __out   NCRYPT_SECRET_HANDLE *phAgreedSecret
 , BYVAL dwFlags AS DWORD _                             ' __in    DWORD   dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION NCryptDeriveKey IMPORT "NCRYPT.DLL" ALIAS "NCryptDeriveKey" ( _
   BYVAL hSharedSecret AS DWORD _                       ' __in      NCRYPT_SECRET_HANDLE hSharedSecret
 , BYREF pwszKDF AS WSTRINGZ _                          ' __in      LPCWSTR              pwszKDF
 , BYREF pParameterList AS NCryptBufferDesc _           ' __in_opt  NCryptBufferDesc     *pParameterList
 , BYVAL pbDerivedKey AS DWORD _                        ' __out     PBYTE                pbDerivedKey
 , BYVAL cbDerivedKey AS DWORD _                        ' __in      DWORD                cbDerivedKey
 , BYREF pcbResult AS DWORD _                           ' __out     DWORD                *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in      ULONG                dwFlags
 ) AS LONG                                              ' SECURITY_STATUS

'#define NCRYPT_KEY_STORAGE_INTERFACE_VERSION BCRYPT_MAKE_INTERFACE_VERSION(1,0)
