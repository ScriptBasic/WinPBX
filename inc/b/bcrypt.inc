' ########################################################################################
' Microsoft Windows
' File: bcrypt.inc
' Contents: Cryptographic Primitive API Prototypes and Definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BCRYPT_INC = 1

'#ifndef _NTDEF_
'typedef __success(return >= 0) LONG NTSTATUS;
'typedef NTSTATUS *PNTSTATUS;
'#endif

'#ifndef BCRYPT_SUCCESS
'#define BCRYPT_SUCCESS(Status) (((NTSTATUS)(Status)) >= 0)
'#endif

#IF NOT %DEF(%BCRYPT_SUCCESS)
%BCRYPT_SUCCESS = 1
FUNCTION BCRYPT_SUCCESS (BYVAL nStatus AS LONG) AS LONG
   FUNCTION = -(nStatus >= 0)
END FUNCTION
#ENDIF

'//
'//  Alignment macros
'//

'//
'// BCRYPT_OBJECT_ALIGNMENT must be a power of 2
'// We align all our internal data structures to 16 to
'// allow fast XMM memory accesses.
'// BCrypt callers do not need to take any alignment precautions.
'//
%BCRYPT_OBJECT_ALIGNMENT = 16

'//
'// BCRYPT_STRUCT_ALIGNMENT is an alignment macro that we no longer use.
'// It used to align declspec(align(4)) on x86 and declspec(align(8)) on x64/ia64 but
'// all structures that used it contained a pointer so they were already 4/8 aligned.
'//
'#define BCRYPT_STRUCT_ALIGNMENT

'//
'// DeriveKey KDF Types
'//
$$BCRYPT_KDF_HASH            = "HASH"$$
$$BCRYPT_KDF_HMAC            = "HMAC"$$
$$BCRYPT_KDF_TLS_PRF         = "TLS_PRF"$$
$$BCRYPT_KDF_SP80056A_CONCAT = "SP800_56A_CONCAT"$$

'//
'// DeriveKey KDF BufferTypes
'//
'// For BCRYPT_KDF_HASH and BCRYPT_KDF_HMAC operations, there may be an arbitrary
'// number of KDF_SECRET_PREPEND and KDF_SECRET_APPEND buffertypes in the
'// parameter list.  The BufferTypes are processed in order of appearence
'// within the parameter list.
'//
%KDF_HASH_ALGORITHM   = &H0???
%KDF_SECRET_PREPEND   = &H1???
%KDF_SECRET_APPEND    = &H2???
%KDF_HMAC_KEY         = &H3???
%KDF_TLS_PRF_LABEL    = &H4???
%KDF_TLS_PRF_SEED     = &H5???
%KDF_SECRET_HANDLE    = &H6???
%KDF_TLS_PRF_PROTOCOL = &H7???
%KDF_ALGORITHMID      = &H8???
%KDF_PARTYUINFO       = &H9???
%KDF_PARTYVINFO       = &HA???
%KDF_SUPPPUBINFO      = &HB???
%KDF_SUPPPRIVINFO     = &HC???

'//
'// DeriveKey Flags:
'//
'// KDF_USE_SECRET_AS_HMAC_KEY_FLAG causes the secret agreement to serve also
'// as the HMAC key.  If this flag is used, the KDF_HMAC_KEY parameter should
'// NOT be specified.
'//
%KDF_USE_SECRET_AS_HMAC_KEY_FLAG = &H1???

'//
'// BCrypt structs
'//

' // Size = 12 bytes
TYPE BCRYPT_KEY_LENGTHS_STRUCT DWORD
   dwMinLength AS DWORD   ' ULONG
   dwMaxLength AS DWORD   ' ULONG
   dwIncrement AS DWORD   ' ULONG
END TYPE

'typedef BCRYPT_KEY_LENGTHS_STRUCT BCRYPT_AUTH_TAG_LENGTHS_STRUCT;
MACRO BCRYPT_AUTH_TAG_LENGTHS_STRUCT = BCRYPT_KEY_LENGTHS_STRUCT

' // Size = 8 bytes
TYPE BCRYPT_OID DWORD
   cbOID AS DWORD      ' ULONG
   pbOID AS BYTE PTR   ' PUCHAR
END TYPE

' // Size = 8 bytes
TYPE BCRYPT_OID_LIST DWORD
   dwOIDCount AS DWORD            ' ULONG
   pOIDs      AS BCRYPT_OID PTR   ' BCRYPT_OID *
END TYPE

' // Size = 4 bytes
TYPE BCRYPT_PKCS1_PADDING_INFO DWORD
   pszAlgId AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 8 bytes
TYPE BCRYPT_PSS_PADDING_INFO DWORD
   pszAlgId AS WSTRINGZ PTR   ' LPCWSTR
   cbSalt   AS DWORD          ' ULONG
END TYPE

' // Size = 12 bytes
TYPE BCRYPT_OAEP_PADDING_INFO DWORD
   pszAlgId AS WSTRINGZ PTR   ' LPCWSTR
   pbLabel  AS BYTE PTR       ' PUCHAR
   cbLabel  AS DWORD          ' ULONG
END TYPE

%BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION = 1

%BCRYPT_AUTH_MODE_CHAIN_CALLS_FLAG = &H00000001???
%BCRYPT_AUTH_MODE_IN_PROGRESS_FLAG = &H00000002???

' // Size = 64 bytes
TYPE BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO DWORD
   cbSize        AS DWORD      ' ULONG
   dwInfoVersion AS DWORD      ' ULONG
   pbNonce       AS BYTE PTR   ' PUCHAR
   cbNonce       AS DWORD      ' ULONG
   pbAuthData    AS BYTE PTR   ' PUCHAR
   cbAuthData    AS DWORD      ' ULONG
   pbTag         AS BYTE PTR   ' PUCHAR
   cbTag         AS DWORD      ' ULONG
   pbMacContext  AS BYTE PTR   ' PUCHAR
   cbMacContext  AS DWORD      ' ULONG
   cbAAD         AS DWORD      ' ULONG
   filler1       AS DWORD      ' // To keep QWORD alignment
   cbData        AS QUAD       ' ULONGLONG
   dwFlags       AS DWORD      ' ULONG
   filler2       AS DWORD      ' // To keep QWORD alignment
END TYPE

'#define BCRYPT_INIT_AUTH_MODE_INFO(_AUTH_INFO_STRUCT_)    \
'            RtlZeroMemory((&_AUTH_INFO_STRUCT_), sizeof(BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO));  \
'            (_AUTH_INFO_STRUCT_).cbSize = sizeof(BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO);          \
'            (_AUTH_INFO_STRUCT_).dwInfoVersion = BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION;

#IF %DEF(%USEPBDECL)
MACRO BCRYPT_INIT_AUTH_MODE_INFO(AUTH_INFO_STRUCT)
    MACROTEMP bacmi
    LOCAL bacmi AS BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO
    LSET AUTH_INFO_STRUCT = STRING$(SIZEOF(AUTH_INFO_STRUCT), 0)
    AUTH_INFO_STRUCT.cbSize = SIZEOF(bacmi)
    AUTH_INFO_STRUCT.dwInfoVersion = %BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION
END MACRO
#ELSE
SUB BCRYPT_INIT_AUTH_MODE_INFO (BYREF bacmi AS BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO)
   bacmi.cbSize = SIZEOF(BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO)
   bacmi.dwInfoVersion = %BCRYPT_AUTHENTICATED_CIPHER_MODE_INFO_VERSION
END SUB
#ENDIF

'//
'// BCrypt String Properties
'//

'// BCrypt(Import/Export)Key BLOB types
$$BCRYPT_OPAQUE_KEY_BLOB      = "OpaqueKeyBlob"$$
$$BCRYPT_KEY_DATA_BLOB        = "KeyDataBlob"$$
$$BCRYPT_AES_WRAP_KEY_BLOB    = "Rfc3565KeyWrapBlob"$$

'// BCryptGetProperty strings
$$BCRYPT_OBJECT_LENGTH        = "ObjectLength"$$
$$BCRYPT_ALGORITHM_NAME       = "AlgorithmName"$$
$$BCRYPT_PROVIDER_HANDLE      = "ProviderHandle"$$
$$BCRYPT_CHAINING_MODE        = "ChainingMode"$$
$$BCRYPT_BLOCK_LENGTH         = "BlockLength"$$
$$BCRYPT_KEY_LENGTH           = "KeyLength"$$
$$BCRYPT_KEY_OBJECT_LENGTH    = "KeyObjectLength"$$
$$BCRYPT_KEY_STRENGTH         = "KeyStrength"$$
$$BCRYPT_KEY_LENGTHS          = "KeyLengths"$$
$$BCRYPT_BLOCK_SIZE_LIST      = "BlockSizeList"$$
$$BCRYPT_EFFECTIVE_KEY_LENGTH = "EffectiveKeyLength"$$
$$BCRYPT_HASH_LENGTH          = "HashDigestLength"$$
$$BCRYPT_HASH_OID_LIST        = "HashOIDList"$$
$$BCRYPT_PADDING_SCHEMES      = "PaddingSchemes"$$
$$BCRYPT_SIGNATURE_LENGTH     = "SignatureLength"$$
$$BCRYPT_HASH_BLOCK_LENGTH    = "HashBlockLength"$$
$$BCRYPT_AUTH_TAG_LENGTH      = "AuthTagLength"$$
$$BCRYPT_PRIMITIVE_TYPE       = "PrimitiveType"$$
$$BCRYPT_IS_KEYED_HASH        = "IsKeyedHash"$$

'// BCryptSetProperty strings
'#define BCRYPT_INITIALIZATION_VECTOR    L"IV"
$$BCRYPT_INITIALIZATION_VECTOR    = "IV"$$

'// Property Strings
$$BCRYPT_CHAIN_MODE_NA        = "ChainingModeN/A"$$
$$BCRYPT_CHAIN_MODE_CBC       = "ChainingModeCBC"$$
$$BCRYPT_CHAIN_MODE_ECB       = "ChainingModeECB"$$
$$BCRYPT_CHAIN_MODE_CFB       = "ChainingModeCFB"$$
$$BCRYPT_CHAIN_MODE_CCM       = "ChainingModeCCM"$$
$$BCRYPT_CHAIN_MODE_GCM       = "ChainingModeGCM"$$

'// Supported RSA Padding Types
%BCRYPT_SUPPORTED_PAD_ROUTER     = &H00000001
%BCRYPT_SUPPORTED_PAD_PKCS1_ENC  = &H00000002
%BCRYPT_SUPPORTED_PAD_PKCS1_SIG  = &H00000004
%BCRYPT_SUPPORTED_PAD_OAEP       = &H00000008
%BCRYPT_SUPPORTED_PAD_PSS        = &H00000010

'//
'//      BCrypt Flags
'//

%BCRYPT_PROV_DISPATCH        = &H00000001???   ' // BCryptOpenAlgorithmProvider

%BCRYPT_BLOCK_PADDING        = &H00000001???   ' // BCryptEncrypt/Decrypt

'// RSA padding schemes
%BCRYPT_PAD_NONE             = &H00000001???
%BCRYPT_PAD_PKCS1            = &H00000002???   ' // BCryptEncrypt/Decrypt BCryptSignHash/VerifySignature
%BCRYPT_PAD_OAEP             = &H00000004???   ' // BCryptEncrypt/Decrypt
%BCRYPT_PAD_PSS              = &H00000008???   ' // BCryptSignHash/VerifySignature

%BCRYPTBUFFER_VERSION        = 0

' // Size = 12 bytes
TYPE BCryptBuffer DWORD
   cbBuffer   AS DWORD   ' ULONG // Length of buffer, in bytes
   BufferType AS DWORD   ' ULONG // Buffer type
   pvBuffer   AS DWORD   ' PVOID // Pointer to buffer
END TYPE

' // Size = 12 bytes
TYPE BCryptBufferDesc DWORD
   ulVersion AS DWORD              ' ULONG // Version number
   cBuffers  AS DWORD              ' ULONG // Number of buffers
   pBuffers  AS BCryptBuffer PTR   ' PBCryptBuffer // Pointer to array of buffers
END TYPE

'//
'// Primitive handles
'//

'typedef PVOID BCRYPT_HANDLE;
'typedef PVOID BCRYPT_ALG_HANDLE;
'typedef PVOID BCRYPT_KEY_HANDLE;
'typedef PVOID BCRYPT_HASH_HANDLE;
'typedef PVOID BCRYPT_SECRET_HANDLE;

'//
'// Structures used to represent key blobs.
'//

$$BCRYPT_PUBLIC_KEY_BLOB       = "PUBLICBLOB"$$
$$BCRYPT_PRIVATE_KEY_BLOB      = "PRIVATEBLOB"$$

' // Size = 4 bytes
TYPE BCRYPT_KEY_BLOB DWORD
   Magic AS DWORD   ' ULONG
END TYPE

'// The BCRYPT_RSAPUBLIC_BLOB and BCRYPT_RSAPRIVATE_BLOB blob types are used
'// to transport plaintext RSA keys. These blob types will be supported by
'// all RSA primitive providers.
'// The BCRYPT_RSAPRIVATE_BLOB includes the following values:
'// Public Exponent
'// Modulus
'// Prime1
'// Prime2

$$BCRYPT_RSAPUBLIC_BLOB      = "RSAPUBLICBLOB"$$
$$BCRYPT_RSAPRIVATE_BLOB     = "RSAPRIVATEBLOB"$$
$$LEGACY_RSAPUBLIC_BLOB      = "CAPIPUBLICBLOB"$$
$$LEGACY_RSAPRIVATE_BLOB     = "CAPIPRIVATEBLOB"$$

%BCRYPT_RSAPUBLIC_MAGIC      = &H31415352  ' // RSA1
%BCRYPT_RSAPRIVATE_MAGIC     = &H32415352  ' // RSA2

' // Size = 24 bytes
TYPE BCRYPT_RSAKEY_BLOB DWORD
   Magic       AS DWORD   ' ULONG
   BitLength   AS DWORD   ' ULONG
   cbPublicExp AS DWORD   ' ULONG
   cbModulus   AS DWORD   ' ULONG
   cbPrime1    AS DWORD   ' ULONG
   cbPrime2    AS DWORD   ' ULONG
END TYPE

'// The BCRYPT_RSAFULLPRIVATE_BLOB blob type is used to transport
'// plaintext private RSA keys.  It includes the following values:
'// Public Exponent
'// Modulus
'// Prime1
'// Prime2
'// Private Exponent mod (Prime1 - 1)
'// Private Exponent mod (Prime2 - 1)
'// Inverse of Prime2 mod Prime1
'// PrivateExponent
$$BCRYPT_RSAFULLPRIVATE_BLOB     = "RSAFULLPRIVATEBLOB"$$

%BCRYPT_RSAFULLPRIVATE_MAGIC     = &H33415352  ' // RSA3

'// The BCRYPT_ECCPUBLIC_BLOB and BCRYPT_ECCPRIVATE_BLOB blob types are used
'// to transport plaintext ECC keys. These blob types will be supported by
'// all ECC primitive providers.
$$BCRYPT_ECCPUBLIC_BLOB          = "ECCPUBLICBLOB"$$
$$BCRYPT_ECCPRIVATE_BLOB         = "ECCPRIVATEBLOB"$$

%BCRYPT_ECDH_PUBLIC_P256_MAGIC   = &H314B4345  ' // ECK1
%BCRYPT_ECDH_PRIVATE_P256_MAGIC  = &H324B4345  ' // ECK2
%BCRYPT_ECDH_PUBLIC_P384_MAGIC   = &H334B4345  ' // ECK3
%BCRYPT_ECDH_PRIVATE_P384_MAGIC  = &H344B4345  ' // ECK4
%BCRYPT_ECDH_PUBLIC_P521_MAGIC   = &H354B4345  ' // ECK5
%BCRYPT_ECDH_PRIVATE_P521_MAGIC  = &H364B4345  ' // ECK6

%BCRYPT_ECDSA_PUBLIC_P256_MAGIC  = &H31534345  ' // ECS1
%BCRYPT_ECDSA_PRIVATE_P256_MAGIC = &H32534345  ' // ECS2
%BCRYPT_ECDSA_PUBLIC_P384_MAGIC  = &H33534345  ' // ECS3
%BCRYPT_ECDSA_PRIVATE_P384_MAGIC = &H34534345  ' // ECS4
%BCRYPT_ECDSA_PUBLIC_P521_MAGIC  = &H35534345  ' // ECS5
%BCRYPT_ECDSA_PRIVATE_P521_MAGIC = &H36534345  ' // ECS6

' // Size = 8 bytes
TYPE BCRYPT_ECCKEY_BLOB
   dwMagic AS DWORD   ' ULONG
   cbKey   AS DWORD   ' ULONG
END TYPE

'// The BCRYPT_DH_PUBLIC_BLOB and BCRYPT_DH_PRIVATE_BLOB blob types are used
'// to transport plaintext DH keys. These blob types will be supported by
'// all DH primitive providers.
$$BCRYPT_DH_PUBLIC_BLOB          = "DHPUBLICBLOB"$$
$$BCRYPT_DH_PRIVATE_BLOB         = "DHPRIVATEBLOB"$$
$$LEGACY_DH_PUBLIC_BLOB          = "CAPIDHPUBLICBLOB"$$
$$LEGACY_DH_PRIVATE_BLOB         = "CAPIDHPRIVATEBLOB"$$

%BCRYPT_DH_PUBLIC_MAGIC          = &H42504844  ' // DHPB
%BCRYPT_DH_PRIVATE_MAGIC         = &H56504844  ' // DHPV

' // Size = 8 bytes
TYPE BCRYPT_DH_KEY_BLOB DWORD
   dwMagic AS DWORD   ' ULONG
   cbKey   AS DWORD   ' ULONG
END TYPE

'// Property Strings for DH
$$BCRYPT_DH_PARAMETERS           = "DHParameters"$$

%BCRYPT_DH_PARAMETERS_MAGIC      = &H4d504844  ' // DHPM

' // Size = 12 bytes
TYPE BCRYPT_DH_PARAMETER_HEADER DWORD
   cbLength    AS DWORD   ' ULONG
   dwMagic     AS DWORD   ' ULONG
   cbKeyLength AS DWORD   ' ULONG
END TYPE

'// The BCRYPT_DSA_PUBLIC_BLOB and BCRYPT_DSA_PRIVATE_BLOB blob types are used
'// to transport plaintext DSA keys. These blob types will be supported by
'// all DSA primitive providers.
$$BCRYPT_DSA_PUBLIC_BLOB         = "DSAPUBLICBLOB"$$
$$BCRYPT_DSA_PRIVATE_BLOB        = "DSAPRIVATEBLOB"$$
$$LEGACY_DSA_PUBLIC_BLOB         = "CAPIDSAPUBLICBLOB"$$
$$LEGACY_DSA_PRIVATE_BLOB        = "CAPIDSAPRIVATEBLOB"$$
$$LEGACY_DSA_V2_PUBLIC_BLOB      = "V2CAPIDSAPUBLICBLOB"$$
$$LEGACY_DSA_V2_PRIVATE_BLOB     = "V2CAPIDSAPRIVATEBLOB"$$

%BCRYPT_DSA_PUBLIC_MAGIC         = &H42505344  ' // DSPB
%BCRYPT_DSA_PRIVATE_MAGIC        = &H56505344  ' // DSPV

' // Size = 52 bytes
TYPE BCRYPT_DSA_KEY_BLOB DWORD
   dwMagic  AS DWORD   ' ULONG
   cbKey    AS DWORD   ' ULONG
   Count(3) AS BYTE    ' UCHAR[4]
   Seed(19) AS BYTE    ' UCHAR[20]
   q(19)    AS BYTE    ' UCHAR[20]
END TYPE

' // Size = 12 bytes
TYPE BCRYPT_KEY_DATA_BLOB_HEADER DWORD
   dwMagic   AS DWORD   ' ULONG
   dwVersion AS DWORD   ' ULONG
   cbKeyData AS DWORD   ' ULONG
END TYPE

%BCRYPT_KEY_DATA_BLOB_MAGIC       = &H4d42444b  ' //Key Data Blob Magic (KDBM)

%BCRYPT_KEY_DATA_BLOB_VERSION1    = &H1

'// Property Strings for DSA
$$BCRYPT_DSA_PARAMETERS      = "DSAParameters"$$

%BCRYPT_DSA_PARAMETERS_MAGIC = &H4d505344  ' // DSPM

' // Size = 56 bytes
TYPE BCRYPT_DSA_PARAMETER_HEADER DWORD
   cbLength    AS DWORD   ' ULONG
   dwMagic     AS DWORD   ' ULONG
   cbKeyLength AS DWORD   ' ULONG
   Count(3)    AS BYTE    ' UCHAR[4]
   Seed(19)    AS BYTE    ' UCHAR[20]
   q(19)       AS BYTE    ' UCHAR[20]
END TYPE

'//
'// Microsoft built-in providers.
'//

$$MS_PRIMITIVE_PROVIDER                  = "Microsoft Primitive Provider"$$

'//
'// Common algorithm identifiers.
'//

$$BCRYPT_RSA_ALGORITHM                   = "RSA"$$
$$BCRYPT_RSA_SIGN_ALGORITHM              = "RSA_SIGN"$$
$$BCRYPT_DH_ALGORITHM                    = "DH"$$
$$BCRYPT_DSA_ALGORITHM                   = "DSA"$$
$$BCRYPT_RC2_ALGORITHM                   = "RC2"$$
$$BCRYPT_RC4_ALGORITHM                   = "RC4"$$
$$BCRYPT_AES_ALGORITHM                   = "AES"$$
$$BCRYPT_DES_ALGORITHM                   = "DES"$$
$$BCRYPT_DESX_ALGORITHM                  = "DESX"$$
$$BCRYPT_3DES_ALGORITHM                  = "3DES"$$
$$BCRYPT_3DES_112_ALGORITHM              = "3DES_112"$$
$$BCRYPT_MD2_ALGORITHM                   = "MD2"$$
$$BCRYPT_MD4_ALGORITHM                   = "MD4"$$
$$BCRYPT_MD5_ALGORITHM                   = "MD5"$$
$$BCRYPT_SHA1_ALGORITHM                  = "SHA1"$$
$$BCRYPT_SHA256_ALGORITHM                = "SHA256"$$
$$BCRYPT_SHA384_ALGORITHM                = "SHA384"$$
$$BCRYPT_SHA512_ALGORITHM                = "SHA512"$$
$$BCRYPT_AES_GMAC_ALGORITHM              = "AES-GMAC"$$
$$BCRYPT_ECDSA_P256_ALGORITHM            = "ECDSA_P256"$$
$$BCRYPT_ECDSA_P384_ALGORITHM            = "ECDSA_P384"$$
$$BCRYPT_ECDSA_P521_ALGORITHM            = "ECDSA_P521"$$
$$BCRYPT_ECDH_P256_ALGORITHM             = "ECDH_P256"$$
$$BCRYPT_ECDH_P384_ALGORITHM             = "ECDH_P384"$$
$$BCRYPT_ECDH_P521_ALGORITHM             = "ECDH_P521"$$
$$BCRYPT_RNG_ALGORITHM                   = "RNG"$$
$$BCRYPT_RNG_FIPS186_DSA_ALGORITHM       = "FIPS186DSARNG"$$
$$BCRYPT_RNG_DUAL_EC_ALGORITHM           = "DUALECRNG"$$

'//
'// Interfaces
'//

%BCRYPT_CIPHER_INTERFACE                 = &H00000001???
%BCRYPT_HASH_INTERFACE                   = &H00000002???
%BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE  = &H00000003???
%BCRYPT_SECRET_AGREEMENT_INTERFACE       = &H00000004???
%BCRYPT_SIGNATURE_INTERFACE              = &H00000005???
%BCRYPT_RNG_INTERFACE                    = &H00000006???

'//
'// Primitive algorithm provider functions.
'//

%BCRYPT_ALG_HANDLE_HMAC_FLAG     = &H00000008???

DECLARE FUNCTION BCryptOpenAlgorithmProvider IMPORT "BCRYPT.DLL" ALIAS "BCryptOpenAlgorithmProvider" ( _
   BYREF phAlgorithm AS DWORD _                         ' __out       BCRYPT_ALG_HANDLE *phAlgorithm
 , BYREF pszAlgId AS WSTRINGZ _                         ' __in        LPCWSTR pszAlgId
 , BYREF pszImplementation AS WSTRINGZ _                ' __in_opt    LPCWSTR pszImplementation
 , BYVAL dwFlags AS DWORD _                             ' __in        ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS


'// AlgOperations flags for use with BCryptEnumAlgorithms()
%BCRYPT_CIPHER_OPERATION                 = &H00000001???
%BCRYPT_HASH_OPERATION                   = &H00000002???
%BCRYPT_ASYMMETRIC_ENCRYPTION_OPERATION  = &H00000004???
%BCRYPT_SECRET_AGREEMENT_OPERATION       = &H00000008???
%BCRYPT_SIGNATURE_OPERATION              = &H00000010???
%BCRYPT_RNG_OPERATION                    = &H00000020???

'// USE EXTREME CAUTION: editing comments that contain "certenrolls_*" tokens
'// could break building CertEnroll idl files:
'// certenrolls_begin -- BCRYPT_ALGORITHM_IDENTIFIER
' // Size = 12 bytes
TYPE BCRYPT_ALGORITHM_IDENTIFIER DWORD
   pszName AS WSTRINGZ PTR   ' LPWSTR
   dwClass AS DWORD          ' ULONG
   dwFlags AS DWORD          ' ULONG
END TYPE

DECLARE FUNCTION BCryptEnumAlgorithms IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumAlgorithms" ( _
   BYVAL dwAlgOperations AS DWORD _                     ' __in    ULONG   dwAlgOperations
 , BYREF pAlgCount AS DWORD _                           ' __out   ULONG   *pAlgCount
 , BYREF ppAlgList AS ANY _                             ' __out   BCRYPT_ALGORITHM_IDENTIFIER **ppAlgList
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

' // Size = 4 bytes
TYPE BCRYPT_PROVIDER_NAME DWORD
   pszProviderName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

DECLARE FUNCTION BCryptEnumProviders IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumProviders" ( _
   BYREF pszAlgId AS WSTRINGZ _                         ' __in    LPCWSTR pszAlgId
 , BYREF pImplCount AS DWORD _                          ' __out   ULONG   *pImplCount
 , BYREF ppImplList AS ANY _                            ' __out   BCRYPT_PROVIDER_NAME **ppImplList
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

'// Flags for use with BCryptGetProperty and BCryptSetProperty
%BCRYPT_PUBLIC_KEY_FLAG                  = &H00000001???
%BCRYPT_PRIVATE_KEY_FLAG                 = &H00000002???

DECLARE FUNCTION BCryptGetProperty IMPORT "BCRYPT.DLL" ALIAS "BCryptGetProperty" ( _
   BYVAL hObject AS DWORD _                             ' __in  BCRYPT_HANDLE  hObject
 , BYREF pszProperty AS WSTRINGZ _                      ' __in  LPCWSTR        pszProperty
 , BYVAL pbOutput AS BYTE PTR _                         ' __out PUCHAR         pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in  ULONG          cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out ULONG         *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG          dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptSetProperty IMPORT "BCRYPT.DLL" ALIAS "BCryptSetProperty" ( _
   BYVAL hObject AS DWORD _                             ' __inout BCRYPT_HANDLE hObject
 , BYREF pszProperty AS WSTRINGZ _                      ' __in    LPCWSTR       pszProperty
 , BYVAL pbInput AS BYTE PTR _                          ' __in    PUCHAR        pbInput
 , BYVAL cbInput AS DWORD _                             ' __in    ULONG         cbInput
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG         dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptCloseAlgorithmProvider IMPORT "BCRYPT.DLL" ALIAS "BCryptCloseAlgorithmProvider" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __inout BCRYPT_ALG_HANDLE hAlgorithm
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG             dwFlags
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
' Note: This PB declaration forces to use the BYVAL override to pass the pointer to free
' and may cause memory leaks if the user forgets to do it.
DECLARE SUB BCryptFreeBuffer LIB "BCrypt.dll" ALIAS "BCryptFreeBuffer" _
    (pvBuffer AS ANY)
#ELSE
DECLARE SUB BCryptFreeBuffer IMPORT "BCRYPT.DLL" ALIAS "BCryptFreeBuffer" ( _
   BYVAL pvBuffer AS DWORD _                            ' __in    PVOID   pvBuffer
 )                                                      ' VOID
#ENDIF

'//
'// Primitive encryption functions.
'//

DECLARE FUNCTION BCryptGenerateSymmetricKey IMPORT "BCRYPT.DLL" ALIAS "BCryptGenerateSymmetricKey" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __inout BCRYPT_ALG_HANDLE  hAlgorithm
 , BYREF phKey AS DWORD _                               ' __out   BCRYPT_KEY_HANDLE *phKey
 , BYVAL pbKeyObject AS BYTE PTR _                      ' __out   PUCHAR             pbKeyObject
 , BYVAL cbKeyObject AS DWORD _                         ' __in    ULONG              cbKeyObject
 , BYVAL pbSecret AS BYTE PTR _                         ' __in    PUCHAR             pbSecret
 , BYVAL cbSecret AS DWORD _                            ' __in    ULONG              cbSecret
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG              dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptGenerateKeyPair IMPORT "BCRYPT.DLL" ALIAS "BCryptGenerateKeyPair" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __inout BCRYPT_ALG_HANDLE  hAlgorithm
 , BYREF phKey AS DWORD _                               ' __out   BCRYPT_KEY_HANDLE *phKey
 , BYVAL dwLength AS DWORD _                            ' __in    ULONG              dwLength
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG              dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptEncrypt IMPORT "BCRYPT.DLL" ALIAS "BCryptEncrypt" ( _
   BYVAL hKey AS DWORD _                                ' __inout  BCRYPT_KEY_HANDLE hKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PUCHAR   pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     ULONG    cbInput
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID    *pPaddingInfo
 , BYVAL pbIV AS BYTE PTR _                             ' __inout  PUCHAR   pbIV
 , BYVAL cbIV AS DWORD _                                ' __in     ULONG    cbIV
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PUCHAR   pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     ULONG    cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    ULONG   *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG    dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDecrypt IMPORT "BCRYPT.DLL" ALIAS "BCryptDecrypt" ( _
   BYVAL hKey AS DWORD _                                ' __inout  BCRYPT_KEY_HANDLE hKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PUCHAR   pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     ULONG    cbInput
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID    *pPaddingInfo
 , BYVAL pbIV AS BYTE PTR _                             ' __inout  PUCHAR   pbIV
 , BYVAL cbIV AS DWORD _                                ' __in     ULONG    cbIV
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PUCHAR   pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     ULONG    cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    ULONG   *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG    dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptExportKey IMPORT "BCRYPT.DLL" ALIAS "BCryptExportKey" ( _
   BYVAL hKey AS DWORD _                                ' __in     BCRYPT_KEY_HANDLE hKey
 , BYVAL hExportKey AS DWORD _                          ' __in_opt BCRYPT_KEY_HANDLE hExportKey
 , BYREF pszBlobType AS WSTRINGZ _                      ' __in     LPCWSTR pszBlobType
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PUCHAR  pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     ULONG   cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    ULONG  *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptImportKey IMPORT "BCRYPT.DLL" ALIAS "BCryptImportKey" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __in     BCRYPT_ALG_HANDLE hAlgorithm
 , BYVAL hImportKey AS DWORD _                          ' __in_opt BCRYPT_KEY_HANDLE hImportKey
 , BYREF pszBlobType AS WSTRINGZ _                      ' __in     LPCWSTR pszBlobType
 , BYREF phKey AS DWORD _                               ' __out    BCRYPT_KEY_HANDLE *phKey
 , BYVAL pbKeyObject AS BYTE PTR _                      ' __out    PUCHAR   pbKeyObject
 , BYVAL cbKeyObject AS DWORD _                         ' __in     ULONG    cbKeyObject
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PUCHAR   pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     ULONG    cbInput
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG    dwFlags
 ) AS LONG                                              ' NTSTATUS

%BCRYPT_NO_KEY_VALIDATION    = &H00000008???

DECLARE FUNCTION BCryptImportKeyPair IMPORT "BCRYPT.DLL" ALIAS "BCryptImportKeyPair" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __in     BCRYPT_ALG_HANDLE hAlgorithm
 , BYVAL hImportKey AS DWORD _                          ' __in_opt BCRYPT_KEY_HANDLE hImportKey
 , BYREF pszBlobType AS WSTRINGZ _                      ' __in     LPCWSTR pszBlobType
 , BYREF phKey AS DWORD _                               ' __out    BCRYPT_KEY_HANDLE *phKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PUCHAR   pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     ULONG   cbInput
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDuplicateKey IMPORT "BCRYPT.DLL" ALIAS "BCryptDuplicateKey" ( _
   BYVAL hKey AS DWORD _                                ' __in  BCRYPT_KEY_HANDLE  hKey
 , BYREF phNewKey AS DWORD _                            ' __out BCRYPT_KEY_HANDLE *phNewKey
 , BYVAL pbKeyObject AS BYTE PTR _                      ' __out PUCHAR  pbKeyObject
 , BYVAL cbKeyObject AS DWORD _                         ' __in  ULONG   cbKeyObject
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptFinalizeKeyPair IMPORT "BCRYPT.DLL" ALIAS "BCryptFinalizeKeyPair" ( _
   BYVAL hKey AS DWORD _                                '  __inout BCRYPT_KEY_HANDLE hKey
 , BYVAL dwFlags As DWORD _                             ' __in     ULONG             dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDestroyKey IMPORT "BCRYPT.DLL" ALIAS "BCryptDestroyKey" ( _
   BYVAL hKey AS DWORD _                                ' __inout BCRYPT_KEY_HANDLE hKey
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDestroySecret IMPORT "BCRYPT.DLL" ALIAS "BCryptDestroySecret" ( _
   BYVAL hSecret AS DWORD _                             ' __inout BCRYPT_SECRET_HANDLE hSecret
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptSignHash IMPORT "BCRYPT.DLL" ALIAS "BCryptSignHash" ( _
   BYVAL hKey AS DWORD _                                ' __in     BCRYPT_KEY_HANDLE hKey
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID   *pPaddingInfo
 , BYVAL pbInput AS BYTE PTR _                          ' __in     PUCHAR  pbInput
 , BYVAL cbInput AS DWORD _                             ' __in     ULONG   cbInput
 , BYVAL pbOutput AS BYTE PTR _                         ' __out    PUCHAR  pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in     ULONG   cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out    ULONG  *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptVerifySignature IMPORT "BCRYPT.DLL" ALIAS "BCryptVerifySignature" ( _
   BYVAL hKey AS DWORD _                                ' __in     BCRYPT_KEY_HANDLE hKey
 , BYREF pPaddingInfo AS ANY _                          ' __in_opt VOID   *pPaddingInfo
 , BYVAL pbHash AS BYTE PTR _                           ' __in     PUCHAR  pbHash
 , BYVAL cbHash AS DWORD _                              ' __in     ULONG   cbHash
 , BYVAL pbSignature AS BYTE PTR _                      ' __in     PUCHAR  pbSignature
 , BYVAL cbSignature AS DWORD _                         ' __in     ULONG   cbSignature
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptSecretAgreement IMPORT "BCRYPT.DLL" ALIAS "BCryptSecretAgreement" ( _
   BYVAL hPrivKey AS DWORD _                            ' __in  BCRYPT_KEY_HANDLE     hPrivKey
 , BYVAL hPubKey AS DWORD _                             ' __in  BCRYPT_KEY_HANDLE     hPubKey
 , BYREF phAgreedSecret AS DWORD _                      ' __out BCRYPT_SECRET_HANDLE *phAgreedSecret
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG                 dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDeriveKey IMPORT "BCRYPT.DLL" ALIAS "BCryptDeriveKey" ( _
   BYVAL hSharedSecret AS DWORD _                       ' __in     BCRYPT_SECRET_HANDLE  hSharedSecret
 , BYREF pwszKDF AS WSTRINGZ _                          ' __in     LPCWSTR               pwszKDF
 , BYVAL pParameterList AS BCryptBufferDesc PTR _       ' __in_opt BCryptBufferDesc     *pParameterList
 , BYVAL pbDerivedKey AS BYTE PTR _                     ' __out    PUCHAR                pbDerivedKey
 , BYVAL cbDerivedKey AS DWORD _                        ' __in     ULONG                 cbDerivedKey
 , BYREF pcbResult AS DWORD _                           ' __out    ULONG                *pcbResult
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG                 dwFlags
 ) AS LONG                                              ' NTSTATUS

'//
'// Primitive hashing functions.
'//

DECLARE FUNCTION BCryptCreateHash IMPORT "BCRYPT.DLL" ALIAS "BCryptCreateHash" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __inout BCRYPT_ALG_HANDLE   hAlgorithm
 , BYREF phHash AS DWORD _                              ' __out   BCRYPT_HASH_HANDLE  *phHash
 , BYVAL pbHashObject AS BYTE PTR _                     ' __out   PUCHAR   pbHashObject
 , BYVAL cbHashObject AS DWORD _                        ' __in    ULONG    cbHashObject
 , BYVAL pbSecret AS BYTE PTR _                         ' __in    PUCHAR   pbSecret   // optional
 , BYVAL cbSecret AS DWORD _                            ' __in    ULONG    cbSecret   // optional
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG    dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptHashData IMPORT "BCRYPT.DLL" ALIAS "BCryptHashData" ( _
   BYVAL hHash AS DWORD _                               ' __inout BCRYPT_HASH_HANDLE  hHash
 , BYVAL pbInput AS BYTE PTR _                          ' __in    PUCHAR  pbInput
 , BYVAL cbInput AS DWORD _                             ' __in    ULONG   cbInput
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptFinishHash IMPORT "BCRYPT.DLL" ALIAS "BCryptFinishHash" ( _
   BYVAL hHash AS DWORD _                               ' __inout BCRYPT_HASH_HANDLE hHash
 , BYVAL pbOutput AS BYTE PTR _                         ' __out   PUCHAR  pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in    ULONG   cbOutput
 , BYVAL dwFlags AS DWORD _                             ' __in    ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDuplicateHash IMPORT "BCRYPT.DLL" ALIAS "BCryptDuplicateHash" ( _
   BYVAL hHash AS DWORD _                               ' __in  BCRYPT_HASH_HANDLE  hHash
 , BYREF phNewHash AS DWORD _                           ' __out BCRYPT_HASH_HANDLE  *phNewHash
 , BYVAL pbHashObject AS BYTE PTR _                     ' __out PUCHAR  pbHashObject
 , BYVAL cbHashObject AS DWORD _                        ' __in  ULONG   cbHashObject
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDestroyHash IMPORT "BCRYPT.DLL" ALIAS "BCryptDestroyHash" ( _
   BYVAL hHash AS DWORD _                               ' __inout BCRYPT_HASH_HANDLE  hHash
 ) AS LONG                                              ' NTSTATUS

'//
'// Primitive random number generation.
'//

'// Flags to BCryptGenRandom
%BCRYPT_RNG_USE_ENTROPY_IN_BUFFER    = &H00000001???
%BCRYPT_USE_SYSTEM_PREFERRED_RNG     = &H00000002???

DECLARE FUNCTION BCryptGenRandom IMPORT "BCRYPT.DLL" ALIAS "BCryptGenRandom" ( _
   BYVAL hAlgorithm AS DWORD _                          ' __in_opt BCRYPT_ALG_HANDLE hAlgorithm
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout  PUCHAR  pbBuffer
 , BYVAL cbBuffer AS DWORD _                            ' __in     ULONG   cbBuffer
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG   dwFlags
 ) AS LONG                                              ' NTSTATUS

'//
'// Primitive key derivation functions.
'//

DECLARE FUNCTION BCryptDeriveKeyCapi IMPORT "BCRYPT.DLL" ALIAS "BCryptDeriveKeyCapi" ( _
   BYVAL hHash AS DWORD _                               ' __in BCRYPT_HASH_HANDLE    hHash
 , BYVAL hTargetAlg AS DWORD _                          ' __in_opt BCRYPT_ALG_HANDLE hTargetAlg
 , BYVAL pbDerivedKey AS BYTE PTR _                     ' __out PUCHAR               pbDerivedKey
 , BYVAL cbDerivedKey AS DWORD _                        ' __in  ULONG                cbDerivedKey
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG                dwFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDeriveKeyPBKDF2 IMPORT "BCRYPT.DLL" ALIAS "BCryptDeriveKeyPBKDF2" ( _
   BYVAL hPrf AS DWORD _                                ' __in     BCRYPT_ALG_HANDLE hPrf
 , BYVAL pbPassword AS BYTE PTR _                       ' __in_opt PUCHAR            pbPassword
 , BYVAL cbPassword AS DWORD _                          ' __in     ULONG             cbPassword
 , BYVAL pbSalt AS BYTE PTR _                           ' __in_opt PUCHAR            pbSalt
 , BYVAL cbSalt AS DWORD _                              ' __in     ULONG             cbSalt
 , BYVAL cIterations AS QUAD _                          ' __in     ULONGLONG         cIterations
 , BYVAL pbDerivedKey AS BYTE PTR _                     ' __out    PUCHAR            pbDerivedKey
 , BYVAL cbDerivedKey AS DWORD _                        ' __in     ULONG             cbDerivedKey
 , BYVAL dwFlags AS DWORD _                             ' __in     ULONG             dwFlags
 ) AS LONG                                              ' NTSTATUS

'//
'// Interface version control...
'//
' // Size = 4 bytes
TYPE BCRYPT_INTERFACE_VERSION WORD
   MajorVersion AS WORD   ' USHORT
   MinorVersion AS WORD   ' USHORT
END TYPE

'#define BCRYPT_MAKE_INTERFACE_VERSION(major,minor) {(USHORT)major, (USHORT)minor}

'#define BCRYPT_IS_INTERFACE_VERSION_COMPATIBLE(loader, provider)    \
'    ((loader).MajorVersion <= (provider).MajorVersion)

'//
'// Primitive provider interfaces.
'//

'#define BCRYPT_CIPHER_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'#define BCRYPT_HASH_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'#define BCRYPT_ASYMMETRIC_ENCRYPTION_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'#define BCRYPT_SECRET_AGREEMENT_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'#define BCRYPT_SIGNATURE_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)
'#define BCRYPT_RNG_INTERFACE_VERSION_1    BCRYPT_MAKE_INTERFACE_VERSION(1,0)


'//////////////////////////////////////////////////////////////////////////////
'// CryptoConfig Definitions //////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'// Interface registration flags
%CRYPT_MIN_DEPENDENCIES      = &H00000001???
%CRYPT_PROCESS_ISOLATE       = &H00010000???   ' // User-mode only

'// Processor modes supported by a provider
'//
'// (Valid for BCryptQueryProviderRegistration and BCryptResolveProviders???:
'//
%CRYPT_UM                    = &H00000001???   ' // User mode only
%CRYPT_KM                    = &H00000002???   ' // Kernel mode only
%CRYPT_MM                    = &H00000003???   ' // Multi-mode: Must support BOTH UM and KM
'//
'// (Valid only for BCryptQueryProviderRegistration???:
'//
%CRYPT_ANY                   = &H00000004???   ' // Wildcard: Either UM, or KM, or both


'// Write behavior flags
%CRYPT_OVERWRITE             = &H00000001???

'// Configuration tables
%CRYPT_LOCAL                 = &H00000001???
%CRYPT_DOMAIN                = &H00000002???

'// Context configuration flags
%CRYPT_EXCLUSIVE             = &H00000001???
%CRYPT_OVERRIDE              = &H00010000???  ' // Enterprise table only

'// Resolution and enumeration flags
%CRYPT_ALL_FUNCTIONS         = &H00000001???
%CRYPT_ALL_PROVIDERS         = &H00000002???

'// Priority list positions
%CRYPT_PRIORITY_TOP          = &H00000000???
#IF %DEF(%USEPBDECL)
%CRYPT_PRIORITY_BOTTOM       = &HFFFFFFFF
#ELSE
%CRYPT_PRIORITY_BOTTOM       = &HFFFFFFFF???
#ENDIF

'// Default system-wide context
$CRYPT_DEFAULT_CONTEXT       = "Default"

'//////////////////////////////////////////////////////////////////////////////
'// CryptoConfig Structures ///////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//
'// Provider Registration Structures
'//

' // Size = 16 bytes
TYPE CRYPT_INTERFACE_REG DWORD
   dwInterface    AS DWORD          ' ULONG
   dwFlags        AS DWORD          ' ULONG
   cFunctions     AS DWORD          ' ULONG
   rgpszFunctions AS WSTRINGZ PTR   ' PWSTR *
END TYPE

' // Size = 12 bytes
TYPE CRYPT_IMAGE_REG DWORD
   pszImage      AS WSTRINGZ PTR              ' PWSTR
   cInterfaces   AS DWORD                     ' ULONG
#IF %DEF(%USEPBDECL)
   rgpInterfaces AS DWORD
#ELSE
   rgpInterfaces AS CRYPT_INTERFACE_REG PTR   ' PCRYPT_INTERFACE_REG *
#ENDIF
END TYPE

' // Size = 16 bytes
TYPE CRYPT_PROVIDER_REG DWORD
   cAliases     AS DWORD                 ' ULONG
#IF %DEF(%USEPBDECL)
   rgpszAliases AS DWORD
#ELSE
   rgpszAliases AS WSTRINGZ PTR          ' PWSTR *
#ENDIF
   pUM          AS CRYPT_IMAGE_REG PTR   ' PCRYPT_IMAGE_REG
   pKM          AS CRYPT_IMAGE_REG PTR   ' PCRYPT_IMAGE_REG
END TYPE

' // Size = 8 bytes
TYPE CRYPT_PROVIDERS DWORD
   cProviders     AS DWORD          ' ULONG
#IF %DEF(%USEPBDECL)
   rgpszProviders AS DWORD
#ELSE
   rgpszProviders AS WSTRINGZ PTR   ' PWSTR *
#ENDIF
END TYPE

'//
'// Context Configuration Structures
'//

' // Size = 8 bytes
TYPE CRYPT_CONTEXT_CONFIG DWORD
   dwFlags    AS DWORD   ' ULONG
   dwReserved AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE CRYPT_CONTEXT_FUNCTION_CONFIG DWORD
   dwFlags    AS DWORD   ' ULONG
   dwReserved AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE CRYPT_CONTEXTS DWORD
   cContexts     AS DWORD          ' ULONG
#IF %DEF(%USEPBDECL)
   rgpszContexts AS DWORD
#ELSE
   rgpszContexts AS WSTRINGZ PTR   ' PWSTR *
#ENDIF
END TYPE

' // Size = 8 bytes
TYPE CRYPT_CONTEXT_FUNCTIONS DWORD
   cFunctions     AS DWORD          ' ULONG
#IF %DEF(%USEPBDECL)
   rgpszFunctions AS DWORD
#ELSE
   rgpszFunctions AS WSTRINGZ PTR   ' PWSTR *
#ENDIF
END TYPE

' // Size = 8 bytes
TYPE CRYPT_CONTEXT_FUNCTION_PROVIDERS DWORD
   cProviders     AS DWORD          ' ULONG
#IF %DEF(%USEPBDECL)
   rgpszProviders AS DWORD
#ELSE
   rgpszProviders AS WSTRINGZ PTR   ' PWSTR *
#ENDIF
END TYPE

'//
'// Provider Resolution Structures
'//

' // Size = 12 bytes
TYPE CRYPT_PROPERTY_REF DWORD
   pszProperty AS WSTRINGZ PTR   ' PWSTR
   cbValue     AS DWORD          ' ULONG
   pbValue     AS BYTE PTR       ' PUCHAR
END TYPE

' // Size = 8 bytes
TYPE CRYPT_IMAGE_REF DWORD
   pszImage AS WSTRINGZ PTR   ' PWSTR
   dwFlags  AS DWORD          ' ULONG
END TYPE

' // Size = 28 bytes
TYPE CRYPT_PROVIDER_REF DWORD
   dwInterface   AS DWORD                    ' ULONG
   pszFunction   AS WSTRINGZ PTR             ' PWSTR
   pszProvider   AS WSTRINGZ PTR             ' PWSTR
   cProperties   AS DWORD                    ' ULONG
#IF %DEF(%USEPBDECL)
   rgpProperties AS DWORD
#ELSE
   rgpProperties AS CRYPT_PROPERTY_REF PTR   ' PCRYPT_PROPERTY_REF *
#ENDIF
   pUM           AS CRYPT_IMAGE_REF    PTR   ' PCRYPT_IMAGE_REF
   pKM           AS CRYPT_IMAGE_REF    PTR   ' PCRYPT_IMAGE_REF
END TYPE

' // Size = 8 bytes
TYPE CRYPT_PROVIDER_REFS DWORD
   cProviders   AS DWORD                    ' ULONG
#IF %DEF(%USEPBDECL)
   rgpProviders AS DWORD
#ELSE
   rgpProviders AS CRYPT_PROVIDER_REF PTR   ' PCRYPT_PROVIDER_REF
#ENDIF
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'// CryptoConfig Functions ////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

#IF NOT %DEF(%KERNEL_MODE_CNG)

DECLARE FUNCTION BCryptQueryProviderRegistration IMPORT "BCRYPT.DLL" ALIAS "BCryptQueryProviderRegistration" ( _
   BYREF pszProvider AS WSTRINGZ _                      ' __in LPCWSTR pszProvider
 , BYVAL dwMode AS DWORD _                              ' __in ULONG dwMode
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_PROVIDER_REG *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptEnumRegisteredProviders IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumRegisteredProviders" ( _
   BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_PROVIDERS *ppBuffer
 ) AS LONG                                              ' NTSTATUS

'//
'// Context Configuration Functions
'//

DECLARE FUNCTION BCryptCreateContext IMPORT "BCRYPT.DLL" ALIAS "BCryptCreateContext" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , OPTIONAL BYREF pConfig AS CRYPT_CONTEXT_CONFIG _     ' __in_opt PCRYPT_CONTEXT_CONFIG pConfig // Optional
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptDeleteContext IMPORT "BCRYPT.DLL" ALIAS "BCryptDeleteContext" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptEnumContexts IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumContexts" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_CONTEXTS *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptConfigureContext IMPORT "BCRYPT.DLL" ALIAS "BCryptConfigureContext" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYREF pConfig AS CRYPT_CONTEXT_CONFIG _              ' __in PCRYPT_CONTEXT_CONFIG pConfig
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptQueryContextConfiguration IMPORT "BCRYPT.DLL" ALIAS "BCryptQueryContextConfiguration" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_CONTEXT_CONFIG *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptAddContextFunction IMPORT "BCRYPT.DLL" ALIAS "BCryptAddContextFunction" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYVAL dwPosition AS DWORD _                          ' __in ULONG dwPosition
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptRemoveContextFunction IMPORT "BCRYPT.DLL" ALIAS "BCryptRemoveContextFunction" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptEnumContextFunctions IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumContextFunctions" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_CONTEXT_FUNCTIONS *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptConfigureContextFunction IMPORT "BCRYPT.DLL" ALIAS "BCryptConfigureContextFunction" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYREF pConfig AS CRYPT_CONTEXT_FUNCTION_CONFIG _     ' __in PCRYPT_CONTEXT_FUNCTION_CONFIG pConfig
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptQueryContextFunctionConfiguration IMPORT "BCRYPT.DLL" ALIAS "BCryptQueryContextFunctionConfiguration" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_CONTEXT_FUNCTION_CONFIG *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptEnumContextFunctionProviders IMPORT "BCRYPT.DLL" ALIAS "BCryptEnumContextFunctionProviders" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_CONTEXT_FUNCTION_PROVIDERS *ppBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptSetContextFunctionProperty IMPORT "BCRYPT.DLL" ALIAS "BCryptSetContextFunctionProperty" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYREF pszProperty AS WSTRINGZ _                      ' __in LPCWSTR pszProperty
 , BYVAL cbValue AS DWORD _                             ' __in ULONG cbValue
 , BYVAL pbValue AS BYTE PTR _                          ' __in PUCHAR pbValue
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION BCryptQueryContextFunctionProperty IMPORT "BCRYPT.DLL" ALIAS "BCryptQueryContextFunctionProperty" ( _
   BYVAL dwTable AS DWORD _                             ' __in ULONG dwTable
 , BYREF pszContext AS WSTRINGZ _                       ' __in LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in LPCWSTR pszFunction
 , BYREF pszProperty AS WSTRINGZ _                      ' __in LPCWSTR pszProperty
 , BYREF pcbValue AS DWORD _                            ' __inout ULONG* pcbValue
 , BYREF ppbValue AS ANY _                              ' __inout PUCHAR *ppbValue
 ) AS LONG                                              ' NTSTATUS

#ENDIF ' //#ifndef KERNEL_MODE_CNG

'//
'// Configuration Change Notification Functions
'//

'#ifdef KERNEL_MODE_CNG
'NTSTATUS
'WINAPI
'BCryptRegisterConfigChangeNotify(
'    __in PRKEVENT pEvent);
'#else
'NTSTATUS
'WINAPI
'BCryptRegisterConfigChangeNotify(
'    __out HANDLE *phEvent);
'#endif

DECLARE FUNCTION BCryptRegisterConfigChangeNotify IMPORT "BCRYPT.DLL" ALIAS "BCryptRegisterConfigChangeNotify" ( _
   BYREF phEvent AS DWORD _                             ' __out HANDLE *phEvent
 ) AS LONG                                              ' NTSTATUS

'#ifdef KERNEL_MODE_CNG
'NTSTATUS
'WINAPI
'BCryptUnregisterConfigChangeNotify(
'    __in PRKEVENT pEvent);
'#else
'NTSTATUS
'WINAPI
'BCryptUnregisterConfigChangeNotify(
'    __in HANDLE hEvent);
'#endif

DECLARE FUNCTION BCryptUnregisterConfigChangeNotify IMPORT "BCRYPT.DLL" ALIAS "BCryptUnregisterConfigChangeNotify" ( _
   BYVAL hEvent AS DWORD _                              ' __in HANDLE hEvent
 ) AS LONG                                              ' NTSTATUS

'//
'// Provider Resolution Functions
'//

DECLARE FUNCTION BCryptResolveProviders IMPORT "BCRYPT.DLL" ALIAS "BCryptResolveProviders" ( _
   BYREF pszContext AS WSTRINGZ _                       ' __in_opt LPCWSTR pszContext
 , BYVAL dwInterface AS DWORD _                         ' __in_opt ULONG dwInterface
 , BYREF pszFunction AS WSTRINGZ _                      ' __in_opt LPCWSTR pszFunction
 , BYREF pszProvider AS WSTRINGZ _                      ' __in_opt LPCWSTR pszProvider
 , BYVAL dwMode AS DWORD _                              ' __in ULONG dwMode
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG dwFlags
 , BYREF pcbBuffer AS DWORD _                           ' __inout ULONG* pcbBuffer
 , BYREF ppBuffer AS ANY _                              ' __inout PCRYPT_PROVIDER_REFS *ppBuffer
 ) AS LONG                                              ' NTSTATUS

'//
'// Miscellaneous queries about the crypto environment
'//

DECLARE FUNCTION BCryptGetFipsAlgorithmMode IMPORT "BCRYPT.DLL" ALIAS "BCryptGetFipsAlgorithmMode" ( _
   BYREF pfEnabled AS LONG _                            ' __out BOOLEAN *pfEnabled
 ) AS LONG                                              ' NTSTATUS
