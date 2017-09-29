' ########################################################################################
' Microsoft Windows
' File: WinCrypt.inc
' Contents: Cryptographic API Prototypes and Definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINCRYPT_INC = 1

#INCLUDE ONCE "windows.inc"

'typedef LONG HRESULT;

'//
'// Algorithm IDs and Flags
'//

'// ALG_ID crackers
'#define GET_ALG_CLASS(x)                (x & (7 << 13))
'#define GET_ALG_TYPE(x)                 (x & (15 << 9))
'#define GET_ALG_SID(x)                  (x & (511))

FUNCTION GET_ALG_CLASS (BYVAL x AS DWORD) AS DWORD
   LOCAL w AS DWORD
   w = 7
   SHIFT LEFT w, 13
   FUNCTION = x AND w
END FUNCTION

FUNCTION GET_ALG_TYPE (BYVAL x AS DWORD) AS DWORD
   LOCAL w AS DWORD
   w = 15
   SHIFT LEFT w, 9
   FUNCTION = x AND w
END FUNCTION

FUNCTION GET_ALG_SID (BYVAL x AS DWORD) AS DWORD
   FUNCTION = x AND 511
END FUNCTION

'// Algorithm classes
%ALG_CLASS_ANY          = 0???
%ALG_CLASS_SIGNATURE    = &H2000???   '(1 << 13)
%ALG_CLASS_MSG_ENCRYPT  = &H4000???   '(2 << 13)
%ALG_CLASS_DATA_ENCRYPT = &H6000???   '(3 << 13)
%ALG_CLASS_HASH         = &H8000???   '(4 << 13)
%ALG_CLASS_KEY_EXCHANGE = &HA000???   '(5 << 13)
%ALG_CLASS_ALL          = &HE000???   '(7 << 13)

'// Algorithm types
%ALG_TYPE_ANY           = 0???
%ALG_TYPE_DSS           = &H0200???   '(1 << 9)
%ALG_TYPE_RSA           = &H0400???   '(2 << 9)
%ALG_TYPE_BLOCK         = &H0600???   '(3 << 9)
%ALG_TYPE_STREAM        = &H0800???   '(4 << 9)
%ALG_TYPE_DH            = &H0A00???   '(5 << 9)
%ALG_TYPE_SECURECHANNEL = &H0C00???   '(6 << 9)

'// Generic sub-ids
%ALG_SID_ANY                    = 0???

'// Some RSA sub-ids
%ALG_SID_RSA_ANY                = 0???
%ALG_SID_RSA_PKCS               = 1???
%ALG_SID_RSA_MSATWORK           = 2???
%ALG_SID_RSA_ENTRUST            = 3???
%ALG_SID_RSA_PGP                = 4???

'// Some DSS sub-ids
'//
%ALG_SID_DSS_ANY                = 0???
%ALG_SID_DSS_PKCS               = 1???
%ALG_SID_DSS_DMS                = 2???
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%ALG_SID_ECDSA                  = 3???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'// Block cipher sub ids
'// DES sub_ids
%ALG_SID_DES                    = 1???
%ALG_SID_3DES                   = 3???
%ALG_SID_DESX                   = 4???
%ALG_SID_IDEA                   = 5???
%ALG_SID_CAST                   = 6???
%ALG_SID_SAFERSK64              = 7???
%ALG_SID_SAFERSK128             = 8???
%ALG_SID_3DES_112               = 9???
%ALG_SID_CYLINK_MEK             = 12???
%ALG_SID_RC5                    = 13???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%ALG_SID_AES_128                = 14???
%ALG_SID_AES_192                = 15???
%ALG_SID_AES_256                = 16???
%ALG_SID_AES                    = 17???
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

'// Fortezza sub-ids
%ALG_SID_SKIPJACK               = 10???
%ALG_SID_TEK                    = 11???

'// KP_MODE
%CRYPT_MODE_CBCI                = 6???      ' // ANSI CBC Interleaved
%CRYPT_MODE_CFBP                = 7???      ' // ANSI CFB Pipelined
%CRYPT_MODE_OFBP                = 8???      ' // ANSI OFB Pipelined
%CRYPT_MODE_CBCOFM              = 9???      ' // ANSI CBC + OF Masking
%CRYPT_MODE_CBCOFMI             = 10???     ' // ANSI CBC + OFM Interleaved

'// RC2 sub-ids
%ALG_SID_RC2                    = 2???

'// Stream cipher sub-ids
%ALG_SID_RC4                    = 1???
%ALG_SID_SEAL                   = 2???

'// Diffie-Hellman sub-ids
%ALG_SID_DH_SANDF               = 1???
%ALG_SID_DH_EPHEM               = 2???
%ALG_SID_AGREED_KEY_ANY         = 3???
%ALG_SID_KEA                    = 4???
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%ALG_SID_ECDH                   = 5???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'// Hash sub ids
%ALG_SID_MD2                    = 1???
%ALG_SID_MD4                    = 2???
%ALG_SID_MD5                    = 3???
%ALG_SID_SHA                    = 4???
%ALG_SID_SHA1                   = 4???
%ALG_SID_MAC                    = 5???
%ALG_SID_RIPEMD                 = 6???
%ALG_SID_RIPEMD160              = 7???
%ALG_SID_SSL3SHAMD5             = 8???
%ALG_SID_HMAC                   = 9???
%ALG_SID_TLS1PRF                = 10???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%ALG_SID_HASH_REPLACE_OWF       = 11???
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)
'#if (NTDDI_VERSION > NTDDI_WINXPSP2)
%ALG_SID_SHA_256                = 12???
%ALG_SID_SHA_384                = 13???
%ALG_SID_SHA_512                = 14???
'#endif //(NTDDI_VERSION > NTDDI_WINXPSP2)

'// secure channel sub ids
%ALG_SID_SSL3_MASTER            = 1???
%ALG_SID_SCHANNEL_MASTER_HASH   = 2???
%ALG_SID_SCHANNEL_MAC_KEY       = 3???
%ALG_SID_PCT1_MASTER            = 4???
%ALG_SID_SSL2_MASTER            = 5???
%ALG_SID_TLS1_MASTER            = 6???
%ALG_SID_SCHANNEL_ENC_KEY       = 7???

'#if (NTDDI_VERSION >= NTDDI_WINLH)
'// misc ECC sub ids
%ALG_SID_ECMQV                  = 1???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'// Our silly example sub-id
%ALG_SID_EXAMPLE                = 80???

'#ifndef ALGIDDEF
'#define ALGIDDEF
'typedef unsigned int ALG_ID;
'#endif

'// algorithm identifier definitions
%CALG_MD2                  = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_MD2
%CALG_MD4                  = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_MD4
%CALG_MD5                  = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_MD5
%CALG_SHA                  = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SHA
%CALG_SHA1                 = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SHA1
%CALG_MAC                  = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_MAC
%CALG_RSA_SIGN             = %ALG_CLASS_SIGNATURE OR %ALG_TYPE_RSA OR %ALG_SID_RSA_ANY
%CALG_DSS_SIGN             = %ALG_CLASS_SIGNATURE OR %ALG_TYPE_DSS OR %ALG_SID_DSS_ANY
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CALG_NO_SIGN              = %ALG_CLASS_SIGNATURE OR %ALG_TYPE_ANY OR %ALG_SID_ANY
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)
%CALG_RSA_KEYX             = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_RSA OR %ALG_SID_RSA_ANY
%CALG_DES                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_DES
%CALG_3DES_112             = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_3DES_112
%CALG_3DES                 = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_3DES
%CALG_DESX                 = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_DESX
%CALG_RC2                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_RC2
%CALG_RC4                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_STREAM OR %ALG_SID_RC4
%CALG_SEAL                 = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_STREAM OR %ALG_SID_SEAL
%CALG_DH_SF                = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_DH OR %ALG_SID_DH_SANDF
%CALG_DH_EPHEM             = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_DH OR %ALG_SID_DH_EPHEM
%CALG_AGREEDKEY_ANY        = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_DH OR %ALG_SID_AGREED_KEY_ANY
%CALG_KEA_KEYX             = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_DH OR %ALG_SID_KEA
%CALG_HUGHES_MD5           = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_ANY OR %ALG_SID_MD5
%CALG_SKIPJACK             = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_SKIPJACK
%CALG_TEK                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_TEK
%CALG_CYLINK_MEK           = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_CYLINK_MEK
%CALG_SSL3_SHAMD5          = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SSL3SHAMD5
%CALG_SSL3_MASTER          = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_SSL3_MASTER
%CALG_SCHANNEL_MASTER_HASH = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_SCHANNEL_MASTER_HASH
%CALG_SCHANNEL_MAC_KEY     = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_SCHANNEL_MAC_KEY
%CALG_SCHANNEL_ENC_KEY     = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_SCHANNEL_ENC_KEY
%CALG_PCT1_MASTER          = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_PCT1_MASTER
%CALG_SSL2_MASTER          = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_SSL2_MASTER
%CALG_TLS1_MASTER          = %ALG_CLASS_MSG_ENCRYPT OR %ALG_TYPE_SECURECHANNEL OR %ALG_SID_TLS1_MASTER
%CALG_RC5                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_RC5
%CALG_HMAC                 = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_HMAC
%CALG_TLS1PRF              = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_TLS1PRF
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CALG_HASH_REPLACE_OWF     = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_HASH_REPLACE_OWF
%CALG_AES_128              = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_AES_128
%CALG_AES_192              = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_AES_192
%CALG_AES_256              = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_AES_256
%CALG_AES                  = %ALG_CLASS_DATA_ENCRYPT OR %ALG_TYPE_BLOCK OR %ALG_SID_AES
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)
'#if (NTDDI_VERSION > NTDDI_WINXPSP2)
%CALG_SHA_256              = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SHA_256
%CALG_SHA_384              = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SHA_384
%CALG_SHA_512              = %ALG_CLASS_HASH OR %ALG_TYPE_ANY OR %ALG_SID_SHA_512
'#endif //(NTDDI_VERSION > NTDDI_WINXPSP2)
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%CALG_ECDH                 = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_DH OR %ALG_SID_ECDH
%CALG_ECMQV                = %ALG_CLASS_KEY_EXCHANGE OR %ALG_TYPE_ANY OR %ALG_SID_ECMQV
%CALG_ECDSA                = %ALG_CLASS_SIGNATURE OR %ALG_TYPE_DSS OR %ALG_SID_ECDSA
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'#if (NTDDI_VERSION < NTDDI_WINXP)
'// resource number for signatures in the CSP
%SIGNATURE_RESOURCE_NUMBER       = &H29A

' // Size = 20 bytes
TYPE VTableProvStruc DWORD
   Version         AS DWORD        ' DWORD
   FuncVerifyImage AS DWORD        ' FARPROC
   FuncReturnhWnd  AS DWORD        ' FARPROC
   dwProvType      AS DWORD        ' DWORD
   pbContextInfo   AS BYTE PTR     ' BYTE *
   cbContextInfo   AS DWORD        ' DWORD
   pszProvName     AS ASCIIZ PTR   ' LPSTR
END TYPE
'#endif //(NTDDI_VERSION < NTDDI_WINXP)

'typedef ULONG_PTR HCRYPTPROV;
'typedef ULONG_PTR HCRYPTKEY;
'typedef ULONG_PTR HCRYPTHASH;

'// dwFlags definitions for CryptAcquireContext
%CRYPT_VERIFYCONTEXT     = &HF0000000???
%CRYPT_NEWKEYSET         = &H00000008???
%CRYPT_DELETEKEYSET      = &H00000010???
%CRYPT_MACHINE_KEYSET    = &H00000020???
%CRYPT_SILENT            = &H00000040???
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%CRYPT_DEFAULT_CONTAINER_OPTIONAL = &H00000080???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'// dwFlag definitions for CryptGenKey
%CRYPT_EXPORTABLE        = &H00000001???
%CRYPT_USER_PROTECTED    = &H00000002???
%CRYPT_CREATE_SALT       = &H00000004???
%CRYPT_UPDATE_KEY        = &H00000008???
%CRYPT_NO_SALT           = &H00000010???
%CRYPT_PREGEN            = &H00000040???
%CRYPT_RECIPIENT         = &H00000010???
%CRYPT_INITIATOR         = &H00000040???
%CRYPT_ONLINE            = &H00000080???
%CRYPT_SF                = &H00000100???
%CRYPT_CREATE_IV         = &H00000200???
%CRYPT_KEK               = &H00000400???
%CRYPT_DATA_KEY          = &H00000800???
%CRYPT_VOLATILE          = &H00001000???
%CRYPT_SGCKEY            = &H00002000???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CRYPT_ARCHIVABLE        = &H00004000???
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%CRYPT_FORCE_KEY_PROTECTION_HIGH = &H00008000???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

%RSA1024BIT_KEY          = &H04000000???

'// dwFlags definitions for CryptDeriveKey
%CRYPT_SERVER            = &H00000400???

%KEY_LENGTH_MASK         = &HFFFF0000???

'// dwFlag definitions for CryptExportKey
%CRYPT_Y_ONLY            = &H00000001???
%CRYPT_SSL2_FALLBACK     = &H00000002???
%CRYPT_DESTROYKEY        = &H00000004???
%CRYPT_OAEP              = &H00000040???  ' // used with RSA encryptions/decryptions
'                                         ' // CryptExportKey, CryptImportKey,
'                                         ' // CryptEncrypt and CryptDecrypt

%CRYPT_BLOB_VER3         = &H00000080???  ' // export version 3 of a blob type
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CRYPT_IPSEC_HMAC_KEY    = &H00000100???  ' // CryptImportKey only
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_WS03)
'// dwFlags definitions for CryptDecrypt
'//  See also CRYPT_OAEP, above.
'//  Note, the following flag is not supported for CryptEncrypt
%CRYPT_DECRYPT_RSA_NO_PADDING_CHECK      = &H00000020???
'#endif //(NTDDI_VERSION >= NTDDI_WS03)

'// dwFlags definitions for CryptCreateHash
%CRYPT_SECRETDIGEST      = &H00000001???

'// dwFlags definitions for CryptHashData
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CRYPT_OWF_REPL_LM_HASH  = &H00000001???  ' // this is only for the OWF replacement CSP
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

'// dwFlags definitions for CryptHashSessionKey
%CRYPT_LITTLE_ENDIAN     = &H00000001???

'// dwFlags definitions for CryptSignHash and CryptVerifySignature
%CRYPT_NOHASHOID         = &H00000001???
%CRYPT_TYPE2_FORMAT      = &H00000002???
%CRYPT_X931_FORMAT       = &H00000004???

'// dwFlag definitions for CryptSetProviderEx and CryptGetDefaultProvider
%CRYPT_MACHINE_DEFAULT   = &H00000001???
%CRYPT_USER_DEFAULT      = &H00000002???
%CRYPT_DELETE_DEFAULT    = &H00000004???

'// exported key blob definitions
%SIMPLEBLOB              = &H1???
%PUBLICKEYBLOB           = &H6???
%PRIVATEKEYBLOB          = &H7???
%PLAINTEXTKEYBLOB        = &H8???
%OPAQUEKEYBLOB           = &H9???
%PUBLICKEYBLOBEX         = &HA???
%SYMMETRICWRAPKEYBLOB    = &HB???
'#if (NTDDI_VERSION >= NTDDI_WS03)
%KEYSTATEBLOB            = &HC???
'#endif //(NTDDI_VERSION >= NTDDI_WS03)

%AT_KEYEXCHANGE          = 1???
%AT_SIGNATURE            = 2???

%CRYPT_USERDATA          = 1???

'// dwParam
%KP_IV                   = 1???       ' // Initialization vector
%KP_SALT                 = 2???       ' // Salt value
%KP_PADDING              = 3???       ' // Padding values
%KP_MODE                 = 4???       ' // Mode of the cipher
%KP_MODE_BITS            = 5???       ' // Number of bits to feedback
%KP_PERMISSIONS          = 6???       ' // Key permissions DWORD
%KP_ALGID                = 7???       ' // Key algorithm
%KP_BLOCKLEN             = 8???       ' // Block size of the cipher
%KP_KEYLEN               = 9???       ' // Length of key in bits
%KP_SALT_EX              = 10???      ' // Length of salt in bytes
%KP_P                    = 11???      ' // DSS/Diffie-Hellman P value
%KP_G                    = 12???      ' // DSS/Diffie-Hellman G value
%KP_Q                    = 13???      ' // DSS Q value
%KP_X                    = 14???      ' // Diffie-Hellman X value
%KP_Y                    = 15???      ' // Y value
%KP_RA                   = 16???      ' // Fortezza RA value
%KP_RB                   = 17???      ' // Fortezza RB value
%KP_INFO                 = 18???      ' // for putting information into an RSA envelope
%KP_EFFECTIVE_KEYLEN     = 19???      ' // setting and getting RC2 effective key length
%KP_SCHANNEL_ALG         = 20???      ' // for setting the Secure Channel algorithms
%KP_CLIENT_RANDOM        = 21???      ' // for setting the Secure Channel client random data
%KP_SERVER_RANDOM        = 22???      ' // for setting the Secure Channel server random data
%KP_RP                   = 23???
%KP_PRECOMP_MD5          = 24???
%KP_PRECOMP_SHA          = 25???
%KP_CERTIFICATE          = 26???      ' // for setting Secure Channel certificate data (PCT1)
%KP_CLEAR_KEY            = 27???      ' // for setting Secure Channel clear key data (PCT1)
%KP_PUB_EX_LEN           = 28???
%KP_PUB_EX_VAL           = 29???
%KP_KEYVAL               = 30???
%KP_ADMIN_PIN            = 31???
%KP_KEYEXCHANGE_PIN      = 32???
%KP_SIGNATURE_PIN        = 33???
%KP_PREHASH              = 34???
'#if (NTDDI_VERSION >= NTDDI_WS03)
%KP_ROUNDS               = 35???
'#endif //(NTDDI_VERSION >= NTDDI_WS03)
%KP_OAEP_PARAMS          = 36???      ' // for setting OAEP params on RSA keys
%KP_CMS_KEY_INFO         = 37???
%KP_CMS_DH_KEY_INFO      = 38???
%KP_PUB_PARAMS           = 39???      ' // for setting public parameters
%KP_VERIFY_PARAMS        = 40???      ' // for verifying DSA and DH parameters
%KP_HIGHEST_VERSION      = 41???      ' // for TLS protocol version setting
'#if (NTDDI_VERSION >= NTDDI_WS03)
%KP_GET_USE_COUNT        = 42???      ' // for use with PP_CRYPT_COUNT_KEY_USE contexts
'#endif //(NTDDI_VERSION >= NTDDI_WS03)
%KP_PIN_ID               = 43???
%KP_PIN_INFO             = 44???

'// KP_PADDING
%PKCS5_PADDING           = 1???      ' // PKCS 5 (sec 6.2) padding method
%RANDOM_PADDING          = 2???
%ZERO_PADDING            = 3???

'// KP_MODE
%CRYPT_MODE_CBC          = 1???       ' // Cipher block chaining
%CRYPT_MODE_ECB          = 2???       ' // Electronic code book
%CRYPT_MODE_OFB          = 3???       ' // Output feedback mode
%CRYPT_MODE_CFB          = 4???       ' // Cipher feedback mode
%CRYPT_MODE_CTS          = 5???       ' // Ciphertext stealing mode

'// KP_PERMISSIONS
%CRYPT_ENCRYPT           = &H0001???  ' // Allow encryption
%CRYPT_DECRYPT           = &H0002???  ' // Allow decryption
%CRYPT_EXPORT            = &H0004???  ' // Allow key to be exported
%CRYPT_READ              = &H0008???  ' // Allow parameters to be read
%CRYPT_WRITE             = &H0010???  ' // Allow parameters to be set
%CRYPT_MAC               = &H0020???  ' // Allow MACs to be used with key
%CRYPT_EXPORT_KEY        = &H0040???  ' // Allow key to be used for exporting keys
%CRYPT_IMPORT_KEY        = &H0080???  ' // Allow key to be used for importing keys
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CRYPT_ARCHIVE           = &H0100???  ' // Allow key to be exported at creation only
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

%HP_ALGID                = &H0001???  ' // Hash algorithm
%HP_HASHVAL              = &H0002???  ' // Hash value
%HP_HASHSIZE             = &H0004???  ' // Hash value size
%HP_HMAC_INFO            = &H0005???  ' // information for creating an HMAC
%HP_TLS1PRF_LABEL        = &H0006???  ' // label for TLS1 PRF
%HP_TLS1PRF_SEED         = &H0007???  ' // seed for TLS1 PRF

%CRYPT_FAILED            = %FALSE
%CRYPT_SUCCEED           = %TRUE

'#define RCRYPT_SUCCEEDED(rt)     ((rt) == CRYPT_SUCCEED)
'#define RCRYPT_FAILED(rt)        ((rt) == CRYPT_FAILED)

MACRO RCRYPT_SUCCEEDED (rt) = (rt = %CRYPT_SUCCEED)
MACRO RCRYPT_FAILED (rt)    = (rt = %CRYPT_FAILED)

'//
'// CryptGetProvParam
'//
%PP_ENUMALGS            = 1???
%PP_ENUMCONTAINERS      = 2???
%PP_IMPTYPE             = 3???
%PP_NAME                = 4???
%PP_VERSION             = 5???
%PP_CONTAINER           = 6???
%PP_CHANGE_PASSWORD     = 7???
%PP_KEYSET_SEC_DESCR    = 8???      ' // get/set security descriptor of keyset
%PP_CERTCHAIN           = 9???      ' // for retrieving certificates from tokens
%PP_KEY_TYPE_SUBTYPE    = 10???
%PP_PROVTYPE            = 16???
%PP_KEYSTORAGE          = 17???
%PP_APPLI_CERT          = 18???
%PP_SYM_KEYSIZE         = 19???
%PP_SESSION_KEYSIZE     = 20???
%PP_UI_PROMPT           = 21???
%PP_ENUMALGS_EX         = 22???
%PP_ENUMMANDROOTS       = 25???
%PP_ENUMELECTROOTS      = 26???
%PP_KEYSET_TYPE         = 27???
%PP_ADMIN_PIN           = 31???
%PP_KEYEXCHANGE_PIN     = 32???
%PP_SIGNATURE_PIN       = 33???
%PP_SIG_KEYSIZE_INC     = 34???
%PP_KEYX_KEYSIZE_INC    = 35???
%PP_UNIQUE_CONTAINER    = 36???
%PP_SGC_INFO            = 37???
%PP_USE_HARDWARE_RNG    = 38???
%PP_KEYSPEC             = 39???
%PP_ENUMEX_SIGNING_PROT = 40???
'#if (NTDDI_VERSION >= NTDDI_WS03)
%PP_CRYPT_COUNT_KEY_USE = 41???
'#endif //(NTDDI_VERSION >= NTDDI_WS03)
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%PP_USER_CERTSTORE      = 42???
%PP_SMARTCARD_READER    = 43???
%PP_SMARTCARD_GUID      = 45???
%PP_ROOT_CERTSTORE      = 46???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

%CRYPT_FIRST            = 1???
%CRYPT_NEXT             = 2???
%CRYPT_SGC_ENUM         = 4???

%CRYPT_IMPL_HARDWARE    = 1???
%CRYPT_IMPL_SOFTWARE    = 2???
%CRYPT_IMPL_MIXED       = 3???
%CRYPT_IMPL_UNKNOWN     = 4???
%CRYPT_IMPL_REMOVABLE   = 8???

'// key storage flags
%CRYPT_SEC_DESCR         = &H00000001???
%CRYPT_PSTORE            = &H00000002???
%CRYPT_UI_PROMPT         = &H00000004???

'// protocol flags
%CRYPT_FLAG_PCT1         = &H0001???
%CRYPT_FLAG_SSL2         = &H0002???
%CRYPT_FLAG_SSL3         = &H0004???
%CRYPT_FLAG_TLS1         = &H0008???
%CRYPT_FLAG_IPSEC        = &H0010???
%CRYPT_FLAG_SIGNING      = &H0020???

'// SGC flags
%CRYPT_SGC               = &H0001???
%CRYPT_FASTSGC           = &H0002???

'//
'// CryptSetProvParam
'//
%PP_CLIENT_HWND            = 1???
%PP_CONTEXT_INFO           = 11???
%PP_KEYEXCHANGE_KEYSIZE    = 12???
%PP_SIGNATURE_KEYSIZE      = 13???
%PP_KEYEXCHANGE_ALG        = 14???
%PP_SIGNATURE_ALG          = 15???
%PP_DELETEKEY              = 24???
'#if (NTDDI_VERSION >= NTDDI_WINLH)
%PP_PIN_PROMPT_STRING      = 44???
%PP_SECURE_KEYEXCHANGE_PIN = 47???
%PP_SECURE_SIGNATURE_PIN   = 48???
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

%PROV_RSA_FULL          = 1???
%PROV_RSA_SIG           = 2???
%PROV_DSS               = 3???
%PROV_FORTEZZA          = 4???
%PROV_MS_EXCHANGE       = 5???
%PROV_SSL               = 6???
%PROV_RSA_SCHANNEL      = 12???
%PROV_DSS_DH            = 13???
%PROV_EC_ECDSA_SIG      = 14???
%PROV_EC_ECNRA_SIG      = 15???
%PROV_EC_ECDSA_FULL     = 16???
%PROV_EC_ECNRA_FULL     = 17???
%PROV_DH_SCHANNEL       = 18???
%PROV_SPYRUS_LYNKS      = 20???
%PROV_RNG               = 21???
%PROV_INTEL_SEC         = 22???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%PROV_REPLACE_OWF       = 23???
%PROV_RSA_AES           = 24???
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION <= NTDDI_WINXP)
'//
'// STT defined Providers
'//
%PROV_STT_MER           = 7
%PROV_STT_ACQ           = 8
%PROV_STT_BRND          = 9
%PROV_STT_ROOT          = 10
%PROV_STT_ISS           = 11
'#endif //(NTDDI_VERSION <= NTDDI_WINXP)

'//
'// Provider friendly names
'//
$MS_DEF_PROV_A               = "Microsoft Base Cryptographic Provider v1.0"
$$MS_DEF_PROV_W              = "Microsoft Base Cryptographic Provider v1.0"$$

$MS_ENHANCED_PROV_A          = "Microsoft Enhanced Cryptographic Provider v1.0"
$$MS_ENHANCED_PROV_W         = "Microsoft Enhanced Cryptographic Provider v1.0"$$

$MS_STRONG_PROV_A            = "Microsoft Strong Cryptographic Provider"
$$MS_STRONG_PROV_W           = "Microsoft Strong Cryptographic Provider"$$

$MS_DEF_RSA_SIG_PROV_A       = "Microsoft RSA Signature Cryptographic Provider"
$$MS_DEF_RSA_SIG_PROV_W      = "Microsoft RSA Signature Cryptographic Provider"$$

$MS_DEF_RSA_SCHANNEL_PROV_A  = "Microsoft RSA SChannel Cryptographic Provider"
$$MS_DEF_RSA_SCHANNEL_PROV_W = "Microsoft RSA SChannel Cryptographic Provider"$$

$MS_DEF_DSS_PROV_A           = "Microsoft Base DSS Cryptographic Provider"
$$MS_DEF_DSS_PROV_W          = "Microsoft Base DSS Cryptographic Provider"$$

$MS_DEF_DSS_DH_PROV_A        = "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"
$$MS_DEF_DSS_DH_PROV_W       = "Microsoft Base DSS and Diffie-Hellman Cryptographic Provider"$$

$MS_ENH_DSS_DH_PROV_A        = "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"
$$MS_ENH_DSS_DH_PROV_W       = "Microsoft Enhanced DSS and Diffie-Hellman Cryptographic Provider"$$

$MS_DEF_DH_SCHANNEL_PROV_A   = "Microsoft DH SChannel Cryptographic Provider"
$$MS_DEF_DH_SCHANNEL_PROV_W  = "Microsoft DH SChannel Cryptographic Provider"$$

$MS_SCARD_PROV_A             = "Microsoft Base Smart Card Crypto Provider"
$$MS_SCARD_PROV_W            = "Microsoft Base Smart Card Crypto Provider"$$

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'#define MS_ENH_RSA_AES_PROV_A   "Microsoft Enhanced RSA and AES Cryptographic Provider"
'#define MS_ENH_RSA_AES_PROV_W   L"Microsoft Enhanced RSA and AES Cryptographic Provider"
'#define MS_ENH_RSA_AES_PROV_XP_A "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
'#define MS_ENH_RSA_AES_PROV_XP_W L"Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
'#ifdef UNICODE
'#define MS_ENH_RSA_AES_PROV_XP  MS_ENH_RSA_AES_PROV_XP_W
'#define MS_ENH_RSA_AES_PROV     MS_ENH_RSA_AES_PROV_W
'#else
'#define MS_ENH_RSA_AES_PROV_XP  MS_ENH_RSA_AES_PROV_XP_A
'#define MS_ENH_RSA_AES_PROV     MS_ENH_RSA_AES_PROV_A
'#endif
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

$MS_ENH_RSA_AES_PROV_A       = "Microsoft Enhanced RSA and AES Cryptographic Provider"
$$MS_ENH_RSA_AES_PROV_W      = "Microsoft Enhanced RSA and AES Cryptographic Provider"$$
$MS_ENH_RSA_AES_PROV_XP_A    = "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"
$$MS_ENH_RSA_AES_PROV_XP_W   = "Microsoft Enhanced RSA and AES Cryptographic Provider (Prototype)"$$

#IF %DEF(%UNICODE)
   MACRO MS_DEF_PROV = $$MS_DEF_PROV_W
   MACRO MS_ENHANCED_PROV = $$MS_ENHANCED_PROV_W
   MACRO MS_STRONG_PROV = $$MS_STRONG_PROV_W
   MACRO MS_DEF_RSA_SIG_PROV = $$MS_DEF_RSA_SIG_PROV_W
   MACRO MS_DEF_RSA_SCHANNEL_PROV = $$MS_DEF_RSA_SCHANNEL_PROV_W
   MACRO MS_DEF_DSS_PROV = $$MS_DEF_DSS_PROV_W
   MACRO MS_DEF_DSS_DH_PROV = $$MS_DEF_DSS_DH_PROV_W
   MACRO MS_ENH_DSS_DH_PROV = $$MS_ENH_DSS_DH_PROV_W
   MACRO MS_DEF_DH_SCHANNEL_PROV = $$MS_DEF_DH_SCHANNEL_PROV_W
   MACRO MS_SCARD_PROV = $$MS_SCARD_PROV_W
   MACRO MS_ENH_RSA_AES_PROV = $$MS_ENH_RSA_AES_PROV_W
   MACRO MS_ENH_RSA_AES_PROV_XP = $$MS_ENH_RSA_AES_PROV_XP_W
#ELSE
   MACRO MS_DEF_PROV = $MS_DEF_PROV_A
   MACRO MS_ENHANCED_PROV = $MS_ENHANCED_PROV_A
   MACRO MS_STRONG_PROV = $MS_STRONG_PROV_A
   MACRO MS_DEF_RSA_SIG_PROV = $MS_DEF_RSA_SIG_PROV_A
   MACRO MS_DEF_RSA_SCHANNEL_PROV = $MS_DEF_RSA_SCHANNEL_PROV_A
   MACRO MS_DEF_DSS_PROV = $MS_DEF_DSS_PROV_A
   MACRO MS_DEF_DSS_DH_PROV = $MS_DEF_DSS_DH_PROV_A
   MACRO MS_ENH_DSS_DH_PROV = $MS_ENH_DSS_DH_PROV_A
   MACRO MS_DEF_DH_SCHANNEL_PROV = $MS_DEF_DH_SCHANNEL_PROV_A
   MACRO MS_SCARD_PROV = $MS_SCARD_PROV_A
   MACRO MS_ENH_RSA_AES_PROV = $MS_ENH_RSA_AES_PROV_A
   MACRO MS_ENH_RSA_AES_PROV_XP = $MS_ENH_RSA_AES_PROV_XP_A
#ENDIF

%MAXUIDLEN              = 64

'// Exponentiation Offload Reg Location
$EXPO_OFFLOAD_REG_VALUE = "ExpoOffload"
$EXPO_OFFLOAD_FUNC_NAME = "OffloadModExpo"

'//
'// Registry key in which the following private key-related
'// values are created.
'//
'#define szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS \
'    "Software\\Policies\\Microsoft\\Cryptography"

$szKEY_CRYPTOAPI_PRIVATE_KEY_OPTIONS = "Software\Policies\Microsoft\Cryptography"

'//
'// Registry value for controlling Data Protection API (DPAPI) UI settings.
'//
$szFORCE_KEY_PROTECTION              = "ForceKeyProtection"

%dwFORCE_KEY_PROTECTION_DISABLED     = &H0???
%dwFORCE_KEY_PROTECTION_USER_SELECT  = &H1???
%dwFORCE_KEY_PROTECTION_HIGH         = &H2???

'//
'// Registry values for enabling and controlling the caching (and timeout)
'// of private keys.  This feature is intended for UI-protected private
'// keys.
'//
'// Note that in Windows 2000 and later, private keys, once read from storage,
'// are cached in the associated HCRYPTPROV structure for subsequent use.
'//
'// In Server 2003 and XP SP1, new key caching behavior is available.  Keys
'// that have been read from storage and cached may now be considered "stale"
'// if a period of time has elapsed since the key was last used.  This forces
'// the key to be re-read from storage (which will make the DPAPI UI appear
'// again).
'//
'// Optional Key Timeouts:
'//
'// In Windows Server 2003, XP SP1, and later, new key caching behavior is
'// available.  Keys that have been read from storage and cached per-context
'// may now be considered "stale" if a period of time has elapsed since the
'// key was last used.  This forces the key to be re-read from storage (which
'// will make the Data Protection API dialog appear again if the key is
'// UI-protected).
'//
'// To enable the new behavior, create the registry DWORD value
'// szKEY_CACHE_ENABLED and set it to 1.  The registry DWORD value
'// szKEY_CACHE_SECONDS must also be created and set to the number of seconds
'// that a cached private key may still be considered usable.
'//
$szKEY_CACHE_ENABLED                    = "CachePrivateKeys"
$szKEY_CACHE_SECONDS                    = "PrivateKeyLifetimeSeconds"

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'//
'// In platforms later than (and not including) Windows Server 2003, private
'// keys are always cached for a period of time per-process, even when
'// not being used in any context.
'//
'// The differences between the process-wide caching settings described below
'// and the Optional Key Timeouts described above are subtle.
'//
'//  - The Optional Key Timeout policy is applied only when an attempt is made
'//    to use a specific private key with an open context handle (HCRYPTPROV).
'//    If szKEY_CACHE_SECONDS have elapsed since the key was last used, the
'//    private key will be re-read from storage.
'//
'//  - The Cache Purge Interval policy, below, is applied whenever any
'//    non-ephemeral private key is used or read from storage.  If
'//    szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS have elapsed since the last
'//    purge occurred, all cached keys that have not been referenced since the
'//    last purge will be removed from the cache.
'//
'//    If a private key that is purged from the cache is currently
'//    referenced in an open context, then the key will be re-read from storage
'//    the next time an attempt is made to use it (via any context).
'//
'// The following two registry DWORD values control this behavior.
'//

'//
'// Registry value for controlling the maximum number of persisted
'// (non-ephemeral) private keys that can be cached per-process.  If the cache
'// fills up, keys will be replaced on a least-recently-used basis.  If the
'// maximum number of cached keys is set to zero, no keys will be globally
'// cached.
'//
$szPRIV_KEY_CACHE_MAX_ITEMS             = "PrivKeyCacheMaxItems"
%cPRIV_KEY_CACHE_MAX_ITEMS_DEFAULT      = 20

'//
'// Registry value for controlling the interval at which the private key
'// cache is proactively purged of outdated keys.
'//
$szPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS = "PrivKeyCachePurgeIntervalSeconds"
%cPRIV_KEY_CACHE_PURGE_INTERVAL_SECONDS_DEFAULT = 86400 ' // 1 day
'#endif //(NTDDI_VERSION >= NTDDI_WINXP)

%CUR_BLOB_VERSION       = 2

'// structure for use with CryptSetKeyParam for CMS keys
'// DO NOT USE THIS STRUCTURE!!!!!
' // Size = 16 bytes
TYPE CMS_KEY_INFO DWORD
   dwVersion AS DWORD      ' DWORD   dwVersion // sizeof(CMS_KEY_INFO)
   Algid     AS DWORD      ' ALG_ID  Algid     // algorithmm id for the key to be converted
   pbOID     AS BYTE PTR   ' BYTE   *pbOID     // pointer to OID to hash in with Z
   cbOID     AS DWORD      ' DWORD   cbOID     // length of OID to hash in with Z
END TYPE

'// structure for use with CryptSetHashParam with CALG_HMAC
' // Size = 20 bytes
TYPE HMAC_INFO DWORD
   HashAlgid     AS DWORD      ' ALG_ID  HashAlgid
   pbInnerString AS BYTE PTR   ' BYTE   *pbInnerString
   cbInnerString AS DWORD      ' DWORD   cbInnerString
   pbOuterString AS BYTE PTR   ' BYTE   *pbOuterString
   cbOuterString AS DWORD      ' DWORD   cbOuterString
END TYPE

'// structure for use with CryptSetKeyParam with KP_SCHANNEL_ALG
' // Size = 20 bytes
TYPE SCHANNEL_ALG DWORD
   dwUse      AS DWORD   ' DWORD   dwUse
   Algid      AS DWORD   ' ALG_ID  Algid
   cBits      AS DWORD   ' DWORD   cBits
   dwFlags    AS DWORD   ' DWORD   dwFlags
   dwReserved AS DWORD   ' DWORD   dwReserved
END TYPE

'// uses of algortihms for SCHANNEL_ALG structure
%SCHANNEL_MAC_KEY = &H00000000???
%SCHANNEL_ENC_KEY = &H00000001???

'// uses of dwFlags SCHANNEL_ALG structure
%INTERNATIONAL_USAGE = &H00000001???

' // Size = 32 bytes
TYPE PROV_ENUMALGS DWORD
   aiAlgid   AS DWORD         ' ALG_ID    aiAlgid
   dwBitLen  AS DWORD         ' DWORD     dwBitLen
   dwNameLen AS DWORD         ' DWORD     dwNameLen
   szName    AS ASCIIZ * 20   ' CHAR      szName[20]
END TYPE

' // Size = 88 bytes
TYPE PROV_ENUMALGS_EX DWORD
   aiAlgid       AS DWORD         ' ALG_ID    aiAlgid
   dwDefaultLen  AS DWORD         ' DWORD     dwDefaultLen
   dwMinLen      AS DWORD         ' DWORD     dwMinLen
   dwMaxLen      AS DWORD         ' DWORD     dwMaxLen
   dwProtocols   AS DWORD         ' DWORD     dwProtocols
   dwNameLen     AS DWORD         ' DWORD     dwNameLen
   szName        AS ASCIIZ * 20   ' CHAR      szName[20]
   dwLongNameLen AS DWORD         ' DWORD     dwLongNameLen
   szLongName    AS ASCIIZ * 40   ' CHAR      szLongName[40]
END TYPE

' // Size = 8 bytes
TYPE BLOBHEADER DWORD FILL
   bType    AS BYTE    ' BYTE    bType
   bVersion AS BYTE    ' BYTE    bVersion
   reserved AS WORD    ' WORD    reserved
   aiKeyAlg AS DWORD   ' ALG_ID  aiKeyAlg
END TYPE

MACRO PUBLICKEYSTRUC = BLOBHEADER

' // Size = 12 bytes
TYPE RSAPUBKEY DWORD
   magic  AS DWORD   ' DWORD   magic  // Has to be RSA1
   bitlen AS DWORD   ' DWORD   bitlen // # of bits in modulus
   pubexp AS DWORD   ' DWORD   pubexp // public exponent
                     '                // Modulus data follows
END TYPE

' // Size = 8 bytes
TYPE DHPUBKEY DWORD
   magic  AS DWORD   ' DWORD   magic;
   bitlen AS DWORD   ' DWORD   bitlen // # of bits in modulus
END TYPE

MACRO DSSPUBKEY = DHPUBKEY
MACRO KEAPUBKEY = DHPUBKEY
MACRO TEKPUBKEY = DHPUBKEY

UNION DSSSEED_SEED_UNION
   seed    AS STRING * 20   ' BYTE    seed[20]
   ' // For compatibility with the PB declares
   seed(19) AS BYTE
END UNION

' // Size = 24 bytes
TYPE DSSSEED DWORD
   counter AS DWORD         ' DWORD   counter
   DSSSEED_SEED_UNION
END TYPE

UNION DHPUBKEY_VER3_DSSSEED_UNION
   DSSSeed AS DSSSEED   ' DSSSEED DSSSeed
   ' // For compatibility with the PB declares
   dss AS DSSSEED   ' DSSSEED DSSSeed
END UNION

' // Size = 40 bytes
TYPE DHPUBKEY_VER3 DWORD
   magic   AS DWORD     ' DWORD   magic
   bitlenP AS DWORD     ' DWORD   bitlenP  // # of bits in prime modulus
   bitlenQ AS DWORD     ' DWORD   bitlenQ  // # of bits in prime q, 0 if not available
   bitlenJ AS DWORD     ' DWORD   bitlenJ  // # of bits in (p-1)/q, 0 if not available
   DHPUBKEY_VER3_DSSSEED_UNION
END TYPE

MACRO DSSPUBKEY_VER3 = DHPUBKEY_VER3

UNION DHPRIVKEY_VER3_DSSSEED_UNION
   DSSSeed AS DSSSEED   ' DSSSEED DSSSeed
   ' // For compatibility with the PB declares
   dss AS DSSSEED   ' DSSSEED DSSSeed
END UNION

' // Size = 44 bytes
TYPE DHPRIVKEY_VER3 DWORD
   magic   AS DWORD     ' DWORD   magic
   bitlenP AS DWORD     ' DWORD   bitlenP  // # of bits in prime modulus
   bitlenQ AS DWORD     ' DWORD   bitlenQ  // # of bits in prime q, 0 if not available
   bitlenJ AS DWORD     ' DWORD   bitlenJ  // # of bits in (p-1)/q, 0 if not available
   bitlenX AS DWORD     ' DWORD   bitlenX  // # of bits in X
   DHPRIVKEY_VER3_DSSSEED_UNION
END TYPE

MACRO DSSPRIVKEY_VER3 = DHPRIVKEY_VER3

UNION KEY_TYPE_SUBTYPE_UNION
   Type      AS GUID    ' GUID    Type
   ' // For compatibility with the PB declares
   gType     AS GUID    ' GUID    Type
END UNION

' // Size = 36 bytes
TYPE KEY_TYPE_SUBTYPE DWORD
   dwKeySpec AS DWORD   ' DWORD   dwKeySpec
   KEY_TYPE_SUBTYPE_UNION
   Subtype   AS GUID    ' GUID    Subtype
END TYPE

UNION CERT_FORTEZZA_DATA_PROP_SERIALNUMBER_UNION
   SerialNumber AS STRING * 8    ' unsigned char   SerialNumber[8]
   ' // For compatibility with the PB declares
   SerialNumber(7) AS BYTE
END UNION

UNION CERT_FORTEZZA_DATA_PROP_CERTLABEL_UNION
   CertLabel    AS STRING * 36   ' unsigned char   CertLabel[36]
   ' // For compatibility with the PB declares
    CertLabel(35) AS BYTE
END UNION

' // Size = 48 bytes
TYPE CERT_FORTEZZA_DATA_PROP BYTE
   CERT_FORTEZZA_DATA_PROP_SERIALNUMBER_UNION
   CertIndex    AS LONG          ' int             CertIndex
   CERT_FORTEZZA_DATA_PROP_CERTLABEL_UNION
END TYPE

'#if (NTDDI_VERSION >= NTDDI_WS03)
UNION CRYPT_RC4_KEY_STATE_KEY_UNION
   Key  AS STRING * 16    ' unsigned char Key[16]
   ' // For compatibility with the PB declares
   bKey(15)  AS BYTE
END UNION

UNION CRYPT_RC4_KEY_STATE_SBOX_UNION
   SBox AS STRING * 256   ' unsigned char SBox[256]
   ' // For compatibility with the PB declares
   SBox(255) AS BYTE
END UNION

' // Size = 274 bytes
TYPE CRYPT_RC4_KEY_STATE BYTE
   CRYPT_RC4_KEY_STATE_KEY_UNION
   CRYPT_RC4_KEY_STATE_SBOX_UNION
   i    AS BYTE           ' unsigned char i
   j    AS BYTE           ' unsigned char j
END TYPE

UNION CRYPT_DES_KEY_STATE_KEY_UNION
   Key      AS STRING * 8   ' unsigned char Key[8]
   ' // For compatibility with the PB declares
   bKey(7)     AS BYTE
END UNION

UNION CRYPT_DES_KEY_STATE_IV_UNION
   IV       AS STRING * 8   ' unsigned char IV[8]
   ' // For compatibility with the PB declares
   IV(7)       AS BYTE
END UNION

UNION CRYPT_DES_KEY_STATE_FEEDBACK_UNION
   Feedback AS STRING * 8   ' unsigned char Feedback[8]
   ' // For compatibility with the PB declares
    Feedback(7) AS BYTE
END UNION

' // Size = 24 bytes
TYPE CRYPT_DES_KEY_STATE BYTE
   CRYPT_DES_KEY_STATE_KEY_UNION
   CRYPT_DES_KEY_STATE_IV_UNION
   CRYPT_DES_KEY_STATE_FEEDBACK_UNION
END TYPE

UNION CRYPT_3DES_KEY_STATE_KEY_UNION
   Key      AS STRING * 24   ' unsigned char Key[24]
   ' // For compatibility with the PB declares
    bKey(23)    AS BYTE
END UNION

UNION CRYPT_3DES_KEY_STATE_IV_UNION
   IV       AS STRING * 8   ' unsigned char IV[8]
   ' // For compatibility with the PB declares
   IV(7)       AS BYTE
END UNION

UNION CRYPT_3DES_KEY_STATE_FEEDBACK_UNION
   Feedback AS STRING * 8   ' unsigned char Feedback[8]
   ' // For compatibility with the PB declares
    Feedback(7) AS BYTE
END UNION

' // Size = 40 bytes
TYPE CRYPT_3DES_KEY_STATE BYTE
   CRYPT_3DES_KEY_STATE_KEY_UNION
   CRYPT_3DES_KEY_STATE_IV_UNION
   CRYPT_3DES_KEY_STATE_FEEDBACK_UNION
END TYPE
'#endif //(NTDDI_VERSION >= NTDDI_WS03)

'#if (NTDDI_VERSION >= NTDDI_WINLH)
'typedef struct _CRYPT_AES_128_KEY_STATE {
'    unsigned char Key[16];
'    unsigned char IV[16];
'    unsigned char EncryptionState[11][16];      // 10 rounds + 1
'    unsigned char DecryptionState[11][16];
'    unsigned char Feedback[16];
'} CRYPT_AES_128_KEY_STATE, *PCRYPT_AES_128_KEY_STATE;

'typedef struct _CRYPT_AES_256_KEY_STATE {
'    unsigned char Key[32];
'    unsigned char IV[16];
'    unsigned char EncryptionState[15][16];      // 14 rounds + 1
'    unsigned char DecryptionState[15][16];
'    unsigned char Feedback[16];
'} CRYPT_AES_256_KEY_STATE, *PCRYPT_AES_256_KEY_STATE;
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'#if (NTDDI_VERSION >= NTDDI_WINLH)

UNION CRYPT_AES_128_KEY_STATE_KEY_UNION
   Key(15) AS BYTE
   ' // For compatibility with the OB declares
   bKey(15) AS BYTE
END UNION

' // Size = 400 bytes
TYPE CRYPT_AES_128_KEY_STATE BYTE
   CRYPT_AES_128_KEY_STATE_KEY_UNION
   IV(15)                  AS BYTE
   EncryptionState(10, 15) AS BYTE   ' // 10 rounds + 1
   DecryptionState(10, 15) AS BYTE
   Feedback(15)            AS BYTE
END TYPE

UNION CRYPT_AES_256_KEY_STATE_KEY_UNION
   Key(31) AS BYTE
   ' // For compatibility with the OB declares
   bKey(31) AS BYTE
END UNION

' // Size = 544 bytes
TYPE CRYPT_AES_256_KEY_STATE BYTE
   CRYPT_AES_256_KEY_STATE_KEY_UNION
   IV(15)                  AS BYTE
   EncryptionState(14, 15) AS BYTE   ' // 14 rounds + 1
   DecryptionState(14, 15) AS BYTE
   Feedback(15)            AS BYTE
END TYPE
'#endif //(NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  CRYPTOAPI BLOB definitions
'//--------------------------------------------------------------------------
'#ifndef CRYPTO_BLOBS_DEFINED
'#define CRYPTO_BLOBS_DEFINED
'typedef struct _CRYPTOAPI_BLOB {
'    DWORD   cbData;
'    BYTE    *pbData;
'} CRYPT_INTEGER_BLOB, *PCRYPT_INTEGER_BLOB,
'CRYPT_UINT_BLOB, *PCRYPT_UINT_BLOB,
'CRYPT_OBJID_BLOB, *PCRYPT_OBJID_BLOB,
'CERT_NAME_BLOB, *PCERT_NAME_BLOB,
'CERT_RDN_VALUE_BLOB, *PCERT_RDN_VALUE_BLOB,
'CERT_BLOB, *PCERT_BLOB,
'CRL_BLOB, *PCRL_BLOB,
'DATA_BLOB, *PDATA_BLOB,
'CRYPT_DATA_BLOB, *PCRYPT_DATA_BLOB,
'CRYPT_HASH_BLOB, *PCRYPT_HASH_BLOB,
'CRYPT_DIGEST_BLOB, *PCRYPT_DIGEST_BLOB,
'CRYPT_DER_BLOB, *PCRYPT_DER_BLOB,
'CRYPT_ATTR_BLOB, *PCRYPT_ATTR_BLOB;
'#endif

' // Size = 8 bytes
TYPE CRYPTOAPI_BLOB DWORD
   cbData AS DWORD
   pbData AS BYTE PTR
END TYPE

MACRO CRYPT_INTEGER_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_UINT_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_OBJID_BLOB = CRYPTOAPI_BLOB
MACRO CERT_NAME_BLOB = CRYPTOAPI_BLOB
MACRO CERT_RDN_VALUE_BLOB = CRYPTOAPI_BLOB
MACRO CERT_BLOB = CRYPTOAPI_BLOB
MACRO CRL_BLOB = CRYPTOAPI_BLOB
MACRO DATA_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_DATA_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_HASH_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_DIGEST_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_DER_BLOB = CRYPTOAPI_BLOB
MACRO CRYPT_ATTR_BLOB = CRYPTOAPI_BLOB

'// structure for use with CryptSetKeyParam for CMS keys
' // Size = 24 bytes
TYPE CMS_DH_KEY_INFO DWORD
   dwVersion          AS DWORD                 ' DWORD           // sizeof(CMS_DH_KEY_INFO)
   Algid              AS DWORD                 ' ALG_ID          // algorithmm id for the key to be converted
   pszContentEncObjId AS ASCIIZ PTR            ' LPSTR           // pointer to OID to hash in with Z
   PubInfo            AS CRYPT_DATA_BLOB       ' CRYPT_DATA_BLOB // OPTIONAL - public information
   pReserved          AS DWORD                 ' void*           // reserved - should be NULL
END TYPE

DECLARE FUNCTION CryptAcquireContextA IMPORT "ADVAPI32.DLL" ALIAS "CryptAcquireContextA" ( _
   BYREF phProv AS DWORD _                              ' __out HCRYPTPROV *phProv
 , BYREF szContainer AS ASCIIZ _                        ' __in LPCSTR szContainer
 , BYREF szProvider AS ASCIIZ _                         ' __in LPCSTR szProvider
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptAcquireContextW IMPORT "ADVAPI32.DLL" ALIAS "CryptAcquireContextW" ( _
   BYREF phProv AS DWORD _                              ' __out HCRYPTPROV *phProv
 , BYREF szContainer AS WSTRINGZ _                      ' __in LPCWSTR szContainer
 , BYREF szProvider AS WSTRINGZ _                       ' __in LPCWSTR szProvider
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptAcquireContext = CryptAcquireContextW
#ELSE
   MACRO CryptAcquireContext = CryptAcquireContextA
#ENDIF

DECLARE FUNCTION CryptReleaseContext IMPORT "ADVAPI32.DLL" ALIAS "CryptReleaseContext" ( _
   BYVAL hProv AS DWORD  _                              ' __in HCRYPTPROV hProv
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptGenKey IMPORT "ADVAPI32.DLL" ALIAS "CryptGenKey" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL Algid AS DWORD _                               ' __in ALG_ID Algid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDeriveKey IMPORT "ADVAPI32.DLL" ALIAS "CryptDeriveKey" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL Algid AS DWORD _                               ' __in ALG_ID Algid
 , BYVAL hBaseData AS DWORD _                           ' __in HCRYPTHASH hBaseData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phKey AS DWORD _                               ' __inout HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDestroyKey IMPORT "ADVAPI32.DLL" ALIAS "CryptDestroyKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSetKeyParam LIB "AdvAPI32.dll" ALIAS "CryptSetKeyParam" _
    (BYVAL hKey AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptSetKeyParam IMPORT "ADVAPI32.DLL" ALIAS "CryptSetKeyParam" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __in CONST BYTE *pbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetKeyParam LIB "AdvAPI32.dll" ALIAS "CryptGetKeyParam" _
    (BYVAL hKey AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    pdwDataLen AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptGetKeyParam IMPORT "ADVAPI32.DLL" ALIAS "CryptGetKeyParam" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __out BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSetHashParam LIB "AdvAPI32.dll" ALIAS "CryptSetHashParam" _
    (BYVAL hHash AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptSetHashParam IMPORT "ADVAPI32.DLL" ALIAS "CryptSetHashParam" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __in CONST BYTE *pbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetHashParam LIB "AdvAPI32.dll" ALIAS "CryptGetHashParam" _
    (BYVAL hHash AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    pdwDataLen AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptGetHashParam IMPORT "ADVAPI32.DLL" ALIAS "CryptGetHashParam" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __out BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSetProvParam LIB "AdvAPI32.dll" ALIAS "CryptSetProvParam" _
    (BYVAL hProv AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptSetProvParam IMPORT "ADVAPI32.DLL" ALIAS "CryptSetProvParam" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __in CONST BYTE *pbData
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetProvParam LIB "AdvAPI32.dll" ALIAS "CryptGetProvParam" _
    (BYVAL hProv AS DWORD, BYVAL dwParam AS DWORD, BYVAL pbData AS BYTE PTR, _
    pdwDataLen AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptGetProvParam IMPORT "ADVAPI32.DLL" ALIAS "CryptGetProvParam" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParam
 , BYREF pbData AS ANY _                                ' __out BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CryptGenRandom IMPORT "ADVAPI32.DLL" ALIAS "CryptGenRandom" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL dwLen AS DWORD _                               ' __in DWORD dwLen
 , BYVAL pbBuffer AS BYTE PTR _                         ' __inout BYTE *pbBuffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptGetUserKey IMPORT "ADVAPI32.DLL" ALIAS "CryptGetUserKey" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYREF phUserKey AS DWORD _                           ' __out HCRYPTKEY *phUserKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptExportKey IMPORT "ADVAPI32.DLL" ALIAS "CryptExportKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL hExpKey AS DWORD _                             ' __in HCRYPTKEY hExpKey
 , BYVAL dwBlobType AS DWORD _                          ' __in DWORD dwBlobType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbData AS BYTE PTR _                           ' __out BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptImportKey IMPORT "ADVAPI32.DLL" ALIAS "CryptImportKey" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL pbData AS BYTE PTR _                           ' __in CONST BYTE *pbData
 , BYVAL dwDataLen AS DWORD _                           ' __in DWORD dwDataLen
 , BYVAL hPubKey AS DWORD _                             ' __in HCRYPTKEY hPubKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptEncrypt IMPORT "ADVAPI32.DLL" ALIAS "CryptEncrypt" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL Final AS LONG _                                ' __in BOOL Final
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbData AS BYTE PTR _                           ' __inout BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 , BYVAL dwBufLen AS DWORD _                            ' __in DWORD dwBufLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDecrypt IMPORT "ADVAPI32.DLL" ALIAS "CryptDecrypt" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL Final AS LONG _                                ' __in BOOL Final
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbData AS BYTE PTR _                           ' __inout BYTE *pbData
 , BYREF pdwDataLen AS DWORD _                          ' __inout DWORD *pdwDataLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptCreateHash IMPORT "ADVAPI32.DLL" ALIAS "CryptCreateHash" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYVAL Algid AS DWORD _                               ' __in ALG_ID Algid
 , BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phHash AS DWORD _                              ' __out HCRYPTHASH *phHash
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptHashData IMPORT "ADVAPI32.DLL" ALIAS "CryptHashData" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL pbData AS BYTE PTR _                           ' __in CONST BYTE *pbData
 , BYVAL dwDataLen AS DWORD _                           ' __in DWORD dwDataLen
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptHashSessionKey IMPORT "ADVAPI32.DLL" ALIAS "CryptHashSessionKey" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDestroyHash IMPORT "ADVAPI32.DLL" ALIAS "CryptDestroyHash" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptSignHashA IMPORT "ADVAPI32.DLL" ALIAS "CryptSignHashA" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYREF szDescription AS ASCIIZ _                      ' __in_opt LPCSTR szDescription
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbSignature AS BYTE PTR _                      ' __out BYTE *pbSignature
 , BYREF pdwSigLen AS DWORD _                           ' __inout DWORD *pdwSigLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptSignHashW IMPORT "ADVAPI32.DLL" ALIAS "CryptSignHashW" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYREF szDescription AS WSTRINGZ _                    ' __in_opt LPCWSTR szDescription
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbSignature AS BYTE PTR _                      ' __out BYTE *pbSignature
 , BYREF pdwSigLen AS DWORD _                           ' __inout DWORD *pdwSigLen
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptSignHash = CryptSignHashW
#ELSE
   MACRO CryptSignHash = CryptSignHashA
#ENDIF

DECLARE FUNCTION CryptVerifySignatureA IMPORT "ADVAPI32.DLL" ALIAS "CryptVerifySignatureA" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL pbSignature AS BYTE PTR _                      ' __in CONST BYTE *pbSignature
 , BYVAL dwSigLen AS DWORD _                            ' __in DWORD dwSigLen
 , BYVAL hPubKey AS DWORD _                             ' __in HCRYPTKEY hPubKey
 , BYREF szDescription AS ASCIIZ _                      ' __in_opt LPCSTR szDescription
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptVerifySignatureW IMPORT "ADVAPI32.DLL" ALIAS "CryptVerifySignatureW" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYVAL pbSignature AS BYTE PTR _                      ' __in CONST BYTE *pbSignature
 , BYVAL dwSigLen AS DWORD _                            ' __in DWORD dwSigLen
 , BYVAL hPubKey AS DWORD _                             ' __in HCRYPTKEY hPubKey
 , BYREF szDescription AS WSTRINGZ _                    ' __in_opt LPCWSTR szDescription
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptVerifySignature = CryptVerifySignatureW
#ELSE
   MACRO CryptVerifySignature = CryptVerifySignatureA
#ENDIF

DECLARE FUNCTION CryptSetProviderA IMPORT "ADVAPI32.DLL" ALIAS "CryptSetProviderA" ( _
   BYREF pszProvName AS ASCIIZ _                        ' __in LPCSTR pszProvName
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptSetProviderW IMPORT "ADVAPI32.DLL" ALIAS "CryptSetProviderW" ( _
   BYREF pszProvName AS WSTRINGZ _                      ' __in LPCWSTR pszProvName
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptSetProvider = CryptSetProviderW
#ELSE
   MACRO CryptSetProvider = CryptSetProviderA
#ENDIF

DECLARE FUNCTION CryptSetProviderExA IMPORT "ADVAPI32.DLL" ALIAS "CryptSetProviderExA" ( _
   BYREF pszProvName AS ASCIIZ _                        ' __in LPCSTR pszProvName
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptSetProviderExW IMPORT "ADVAPI32.DLL" ALIAS "CryptSetProviderExW" ( _
   BYREF pszProvName AS WSTRINGZ _                      ' __in LPCWSTR pszProvName
 , BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptSetProviderEx = CryptSetProviderExW
#ELSE
   MACRO CryptSetProviderEx = CryptSetProviderExA
#ENDIF

DECLARE FUNCTION CryptGetDefaultProviderA IMPORT "ADVAPI32.DLL" ALIAS "CryptGetDefaultProviderA" ( _
   BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszProvName AS ASCIIZ _                        ' __out LPSTR pszProvName
 , BYREF pcbProvName AS DWORD _                         ' __inout DWORD *pcbProvName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptGetDefaultProviderW IMPORT "ADVAPI32.DLL" ALIAS "CryptGetDefaultProviderW" ( _
   BYVAL dwProvType AS DWORD _                          ' __in DWORD dwProvType
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszProvName AS WSTRINGZ _                      ' __out LPWSTR pszProvName
 , BYREF pcbProvName AS DWORD _                         ' __inout DWORD *pcbProvName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptGetDefaultProvider = CryptGetDefaultProviderW
#ELSE
   MACRO CryptGetDefaultProvider = CryptGetDefaultProviderA
#ENDIF

DECLARE FUNCTION CryptEnumProviderTypesA IMPORT "ADVAPI32.DLL" ALIAS "CryptEnumProviderTypesA" ( _
   BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pdwProvType AS DWORD _                         ' __out DWORD *pdwProvType
 , BYREF szTypeName AS ASCIIZ _                         ' __out LPSTR szTypeName
 , BYREF pcbTypeName AS DWORD _                         ' __inout DWORD *pcbTypeName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptEnumProviderTypesW IMPORT "ADVAPI32.DLL" ALIAS "CryptEnumProviderTypesW" ( _
   BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pdwProvType AS DWORD _                         ' __out DWORD *pdwProvType
 , BYREF szTypeName AS WSTRINGZ _                       ' __out LPWSTR szTypeName
 , BYREF pcbTypeName AS DWORD _                         ' __inout DWORD *pcbTypeName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptEnumProviderTypes = CryptEnumProviderTypesW
#ELSE
   MACRO CryptEnumProviderTypes = CryptEnumProviderTypesA
#ENDIF

DECLARE FUNCTION CryptEnumProvidersA IMPORT "ADVAPI32.DLL" ALIAS "CryptEnumProvidersA" ( _
   BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pdwProvType AS DWORD _                         ' __out DWORD *pdwProvType
 , BYREF szProvName AS ASCIIZ _                         ' __out LPSTR szProvName
 , BYREF pcbProvName AS DWORD _                         ' __inout DWORD *pcbProvName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptEnumProvidersW IMPORT "ADVAPI32.DLL" ALIAS "CryptEnumProvidersW" ( _
   BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pdwProvType AS DWORD _                         ' __out DWORD *pdwProvType
 , BYREF szProvName AS WSTRINGZ _                       ' __out LPWSTR szProvName
 , BYREF pcbProvName AS DWORD _                         ' __inout DWORD *pcbProvName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptEnumProviders = CryptEnumProvidersW
#ELSE
   MACRO CryptEnumProviders = CryptEnumProvidersA
#ENDIF

DECLARE FUNCTION CryptContextAddRef IMPORT "ADVAPI32.DLL" ALIAS "CryptContextAddRef" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDuplicateKey IMPORT "ADVAPI32.DLL" ALIAS "CryptDuplicateKey" ( _
   BYVAL hKey AS DWORD _                                ' __in HCRYPTKEY hKey
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDuplicateHash IMPORT "ADVAPI32.DLL" ALIAS "CryptDuplicateHash" ( _
   BYVAL hHash AS DWORD _                               ' __in HCRYPTHASH hHash
 , BYREF pdwReserved AS DWORD _                         ' __in DWORD *pdwReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phHash AS DWORD _                              ' __out HCRYPTHASH *phHash
 ) AS LONG                                              ' BOOL

'//
'// This function is provided in Microsoft Windows 2000 as a means of
'// installing the 128-bit encryption provider. This function is unavailable
'// in Microsoft Windows XP, because Windows XP ships with the 128-bit
'// encryption provider.
'//
'BOOL
'__cdecl
'GetEncSChannel(
'    BYTE **pData,
'    DWORD *dwDecSize
'    );

'#if !defined(_DDK_DRIVER_)

'// In Vista, the following APIs were updated to support the new
'// CNG (Cryptography Next Generation) BCrypt* and NCrypt* APIs in addition
'// to the above CAPI1 APIs.

'// Include the definitions for the CNG APIs
#INCLUDE ONCE "bcrypt.inc"
#INCLUDE ONCE "ncrypt.inc"

'// This type is used when the API can take either the CAPI1 HCRYPTPROV or
'// the CNG NCRYPT_KEY_HANDLE. Where appropriate, the HCRYPTPROV will be
'// converted to a NCRYPT_KEY_HANDLE via the CNG NCryptTranslateHandle().
'typedef ULONG_PTR HCRYPTPROV_OR_NCRYPT_KEY_HANDLE;

'// This type is used where the HCRYPTPROV parameter is no longer used.
'// The caller should always pass in NULL.
'typedef ULONG_PTR HCRYPTPROV_LEGACY;

'//+-------------------------------------------------------------------------
'//  In a CRYPT_BIT_BLOB the last byte may contain 0-7 unused bits. Therefore, the
'//  overall bit length is cbData * 8 - cUnusedBits.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPT_BIT_BLOB DWORD
   cbData      AS DWORD      ' DWORD   cbData
   pbData      AS BYTE PTR   ' BYTE    *pbData
   cUnusedBits AS DWORD      ' DWORD   cUnusedBits
END TYPE

'//+-------------------------------------------------------------------------
'//  Type used for any algorithm
'//
'//  Where the Parameters CRYPT_OBJID_BLOB is in its encoded representation. For most
'//  algorithm types, the Parameters CRYPT_OBJID_BLOB is NULL (Parameters.cbData = 0).
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_ALGORITHM_IDENTIFIER DWORD
   pszObjId   AS ASCIIZ PTR         ' LPSTR               pszObjId
   Parameters AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB    Parameters
END TYPE

'// Following are the definitions of various algorithm object identifiers
'// RSA
$szOID_RSA              = "1.2.840.113549"
$szOID_PKCS             = "1.2.840.113549.1"
$szOID_RSA_HASH         = "1.2.840.113549.2"
$szOID_RSA_ENCRYPT      = "1.2.840.113549.3"

$szOID_PKCS_1           = "1.2.840.113549.1.1"
$szOID_PKCS_2           = "1.2.840.113549.1.2"
$szOID_PKCS_3           = "1.2.840.113549.1.3"
$szOID_PKCS_4           = "1.2.840.113549.1.4"
$szOID_PKCS_5           = "1.2.840.113549.1.5"
$szOID_PKCS_6           = "1.2.840.113549.1.6"
$szOID_PKCS_7           = "1.2.840.113549.1.7"
$szOID_PKCS_8           = "1.2.840.113549.1.8"
$szOID_PKCS_9           = "1.2.840.113549.1.9"
$szOID_PKCS_10          = "1.2.840.113549.1.10"
$szOID_PKCS_12          = "1.2.840.113549.1.12"

$szOID_RSA_RSA          = "1.2.840.113549.1.1.1"
$szOID_RSA_MD2RSA       = "1.2.840.113549.1.1.2"
$szOID_RSA_MD4RSA       = "1.2.840.113549.1.1.3"
$szOID_RSA_MD5RSA       = "1.2.840.113549.1.1.4"
$szOID_RSA_SHA1RSA      = "1.2.840.113549.1.1.5"
$szOID_RSA_SETOAEP_RSA  = "1.2.840.113549.1.1.6"

$szOID_RSAES_OAEP       = "1.2.840.113549.1.1.7"
$szOID_RSA_MGF1         = "1.2.840.113549.1.1.8"
$szOID_RSA_PSPECIFIED   = "1.2.840.113549.1.1.9"
$szOID_RSA_SSA_PSS      = "1.2.840.113549.1.1.10"
$szOID_RSA_SHA256RSA    = "1.2.840.113549.1.1.11"
$szOID_RSA_SHA384RSA    = "1.2.840.113549.1.1.12"
$szOID_RSA_SHA512RSA    = "1.2.840.113549.1.1.13"

$szOID_RSA_DH           = "1.2.840.113549.1.3.1"

$szOID_RSA_data          = "1.2.840.113549.1.7.1"
$szOID_RSA_signedData    = "1.2.840.113549.1.7.2"
$szOID_RSA_envelopedData = "1.2.840.113549.1.7.3"
$szOID_RSA_signEnvData   = "1.2.840.113549.1.7.4"
$szOID_RSA_digestedData  = "1.2.840.113549.1.7.5"
$szOID_RSA_hashedData    = "1.2.840.113549.1.7.5"
$szOID_RSA_encryptedData = "1.2.840.113549.1.7.6"

$szOID_RSA_emailAddr     = "1.2.840.113549.1.9.1"
$szOID_RSA_unstructName  = "1.2.840.113549.1.9.2"
$szOID_RSA_contentType   = "1.2.840.113549.1.9.3"
$szOID_RSA_messageDigest = "1.2.840.113549.1.9.4"
$szOID_RSA_signingTime   = "1.2.840.113549.1.9.5"
$szOID_RSA_counterSign   = "1.2.840.113549.1.9.6"
$szOID_RSA_challengePwd  = "1.2.840.113549.1.9.7"
$szOID_RSA_unstructAddr  = "1.2.840.113549.1.9.8"
$szOID_RSA_extCertAttrs  = "1.2.840.113549.1.9.9"
$szOID_RSA_certExtensions = "1.2.840.113549.1.9.14"
$szOID_RSA_SMIMECapabilities = "1.2.840.113549.1.9.15"
$szOID_RSA_preferSignedData = "1.2.840.113549.1.9.15.1"

$szOID_TIMESTAMP_TOKEN      = "1.2.840.113549.1.9.16.1.4"
$szOID_RFC3161_counterSign  = "1.3.6.1.4.1.311.3.3.1"

$szOID_RSA_SMIMEalg             = "1.2.840.113549.1.9.16.3"
$szOID_RSA_SMIMEalgESDH         = "1.2.840.113549.1.9.16.3.5"
$szOID_RSA_SMIMEalgCMS3DESwrap  = "1.2.840.113549.1.9.16.3.6"
$szOID_RSA_SMIMEalgCMSRC2wrap   = "1.2.840.113549.1.9.16.3.7"

$szOID_RSA_MD2          = "1.2.840.113549.2.2"
$szOID_RSA_MD4          = "1.2.840.113549.2.4"
$szOID_RSA_MD5          = "1.2.840.113549.2.5"

$szOID_RSA_RC2CBC       = "1.2.840.113549.3.2"
$szOID_RSA_RC4          = "1.2.840.113549.3.4"
$szOID_RSA_DES_EDE3_CBC = "1.2.840.113549.3.7"
$szOID_RSA_RC5_CBCPad   = "1.2.840.113549.3.9"

$szOID_ANSI_X942        = "1.2.840.10046"
$szOID_ANSI_X942_DH     = "1.2.840.10046.2.1"

$szOID_X957             = "1.2.840.10040"
$szOID_X957_DSA         = "1.2.840.10040.4.1"
$szOID_X957_SHA1DSA     = "1.2.840.10040.4.3"

'// iso(1) member-body(2) us(840) 10045 keyType(2) unrestricted(1)
$szOID_ECC_PUBLIC_KEY   = "1.2.840.10045.2.1"

'// iso(1) member-body(2) us(840) 10045 curves(3) prime(1) 7
$szOID_ECC_CURVE_P256   = "1.2.840.10045.3.1.7"

'// iso(1) identified-organization(3) certicom(132) curve(0) 34
$szOID_ECC_CURVE_P384   = "1.3.132.0.34"

'// iso(1) identified-organization(3) certicom(132) curve(0) 35
$szOID_ECC_CURVE_P521   = "1.3.132.0.35"


'// iso(1) member-body(2) us(840) 10045 signatures(4) sha1(1)
$szOID_ECDSA_SHA1       = "1.2.840.10045.4.1"

'// iso(1) member-body(2) us(840) 10045 signatures(4) specified(3)
$szOID_ECDSA_SPECIFIED  = "1.2.840.10045.4.3"

'// iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 2
$szOID_ECDSA_SHA256     = "1.2.840.10045.4.3.2"

'// iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 3
$szOID_ECDSA_SHA384     = "1.2.840.10045.4.3.3"

'// iso(1) member-body(2) us(840) 10045 signatures(4) specified(3) 4
$szOID_ECDSA_SHA512     = "1.2.840.10045.4.3.4"


'// NIST AES CBC Algorithms
'// joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistAlgorithms(4)  aesAlgs(1) }

$szOID_NIST_AES128_CBC       = "2.16.840.1.101.3.4.1.2"
$szOID_NIST_AES192_CBC       = "2.16.840.1.101.3.4.1.22"
$szOID_NIST_AES256_CBC       = "2.16.840.1.101.3.4.1.42"

'// For the above Algorithms, the AlgorithmIdentifier parameters must be
'// present and the parameters field MUST contain an AES-IV:
'//
'//  AES-IV ::= OCTET STRING (SIZE(16))

'// NIST AES WRAP Algorithms
$szOID_NIST_AES128_WRAP      = "2.16.840.1.101.3.4.1.5"
$szOID_NIST_AES192_WRAP      = "2.16.840.1.101.3.4.1.25"
$szOID_NIST_AES256_WRAP      = "2.16.840.1.101.3.4.1.45"


'//      x9-63-scheme OBJECT IDENTIFIER ::= { iso(1)
'//         identified-organization(3) tc68(133) country(16) x9(840)
'//         x9-63(63) schemes(0) }


'// ECDH single pass ephemeral-static KeyAgreement KeyEncryptionAlgorithm
$szOID_DH_SINGLE_PASS_STDDH_SHA1_KDF   = "1.3.133.16.840.63.0.2"
$szOID_DH_SINGLE_PASS_STDDH_SHA256_KDF = "1.3.132.1.11.1"
$szOID_DH_SINGLE_PASS_STDDH_SHA384_KDF = "1.3.132.1.11.2"

'// For the above KeyEncryptionAlgorithm the following wrap algorithms are
'// supported:
'//  szOID_RSA_SMIMEalgCMS3DESwrap
'//  szOID_RSA_SMIMEalgCMSRC2wrap
'//  szOID_NIST_AES128_WRAP
'//  szOID_NIST_AES192_WRAP
'//  szOID_NIST_AES256_WRAP

'// ITU-T UsefulDefinitions
$szOID_DS               = "2.5"
$szOID_DSALG            = "2.5.8"
$szOID_DSALG_CRPT       = "2.5.8.1"
$szOID_DSALG_HASH       = "2.5.8.2"
$szOID_DSALG_SIGN       = "2.5.8.3"
$szOID_DSALG_RSA        = "2.5.8.1.1"

'// NIST OSE Implementors' Workshop (OIW)
'// http://nemo.ncsl.nist.gov/oiw/agreements/stable/OSI/12s_9506.w51
'// http://nemo.ncsl.nist.gov/oiw/agreements/working/OSI/12w_9503.w51
$szOID_OIW              = "1.3.14"

'// NIST OSE Implementors' Workshop (OIW) Security SIG algorithm identifiers
$szOID_OIWSEC             = "1.3.14.3.2"
$szOID_OIWSEC_md4RSA      = "1.3.14.3.2.2"
$szOID_OIWSEC_md5RSA      = "1.3.14.3.2.3"
$szOID_OIWSEC_md4RSA2     = "1.3.14.3.2.4"
$szOID_OIWSEC_desECB      = "1.3.14.3.2.6"
$szOID_OIWSEC_desCBC      = "1.3.14.3.2.7"
$szOID_OIWSEC_desOFB      = "1.3.14.3.2.8"
$szOID_OIWSEC_desCFB      = "1.3.14.3.2.9"
$szOID_OIWSEC_desMAC      = "1.3.14.3.2.10"
$szOID_OIWSEC_rsaSign     = "1.3.14.3.2.11"
$szOID_OIWSEC_dsa         = "1.3.14.3.2.12"
$szOID_OIWSEC_shaDSA      = "1.3.14.3.2.13"
$szOID_OIWSEC_mdc2RSA     = "1.3.14.3.2.14"
$szOID_OIWSEC_shaRSA      = "1.3.14.3.2.15"
$szOID_OIWSEC_dhCommMod   = "1.3.14.3.2.16"
$szOID_OIWSEC_desEDE      = "1.3.14.3.2.17"
$szOID_OIWSEC_sha         = "1.3.14.3.2.18"
$szOID_OIWSEC_mdc2        = "1.3.14.3.2.19"
$szOID_OIWSEC_dsaComm     = "1.3.14.3.2.20"
$szOID_OIWSEC_dsaCommSHA  = "1.3.14.3.2.21"
$szOID_OIWSEC_rsaXchg     = "1.3.14.3.2.22"
$szOID_OIWSEC_keyHashSeal = "1.3.14.3.2.23"
$szOID_OIWSEC_md2RSASign  = "1.3.14.3.2.24"
$szOID_OIWSEC_md5RSASign  = "1.3.14.3.2.25"
$szOID_OIWSEC_sha1        = "1.3.14.3.2.26"
$szOID_OIWSEC_dsaSHA1     = "1.3.14.3.2.27"
$szOID_OIWSEC_dsaCommSHA1 = "1.3.14.3.2.28"
$szOID_OIWSEC_sha1RSASign = "1.3.14.3.2.29"

'// NIST OSE Implementors' Workshop (OIW) Directory SIG algorithm identifiers

$szOID_OIWDIR            = "1.3.14.7.2"
$szOID_OIWDIR_CRPT       = "1.3.14.7.2.1"
$szOID_OIWDIR_HASH       = "1.3.14.7.2.2"
$szOID_OIWDIR_SIGN       = "1.3.14.7.2.3"
$szOID_OIWDIR_md2        = "1.3.14.7.2.2.1"
$szOID_OIWDIR_md2RSA     = "1.3.14.7.2.3.1"

'// INFOSEC Algorithms
'// joint-iso-ccitt(2) country(16) us(840) organization(1) us-government(101) dod(2) id-infosec(1)
$szOID_INFOSEC                       = "2.16.840.1.101.2.1"
$szOID_INFOSEC_sdnsSignature         = "2.16.840.1.101.2.1.1.1"
$szOID_INFOSEC_mosaicSignature       = "2.16.840.1.101.2.1.1.2"
$szOID_INFOSEC_sdnsConfidentiality   = "2.16.840.1.101.2.1.1.3"
$szOID_INFOSEC_mosaicConfidentiality = "2.16.840.1.101.2.1.1.4"
$szOID_INFOSEC_sdnsIntegrity         = "2.16.840.1.101.2.1.1.5"
$szOID_INFOSEC_mosaicIntegrity       = "2.16.840.1.101.2.1.1.6"
$szOID_INFOSEC_sdnsTokenProtection   = "2.16.840.1.101.2.1.1.7"
$szOID_INFOSEC_mosaicTokenProtection = "2.16.840.1.101.2.1.1.8"
$szOID_INFOSEC_sdnsKeyManagement     = "2.16.840.1.101.2.1.1.9"
$szOID_INFOSEC_mosaicKeyManagement   = "2.16.840.1.101.2.1.1.10"
$szOID_INFOSEC_sdnsKMandSig          = "2.16.840.1.101.2.1.1.11"
$szOID_INFOSEC_mosaicKMandSig        = "2.16.840.1.101.2.1.1.12"
$szOID_INFOSEC_SuiteASignature       = "2.16.840.1.101.2.1.1.13"
$szOID_INFOSEC_SuiteAConfidentiality = "2.16.840.1.101.2.1.1.14"
$szOID_INFOSEC_SuiteAIntegrity       = "2.16.840.1.101.2.1.1.15"
$szOID_INFOSEC_SuiteATokenProtection = "2.16.840.1.101.2.1.1.16"
$szOID_INFOSEC_SuiteAKeyManagement   = "2.16.840.1.101.2.1.1.17"
$szOID_INFOSEC_SuiteAKMandSig        = "2.16.840.1.101.2.1.1.18"
$szOID_INFOSEC_mosaicUpdatedSig      = "2.16.840.1.101.2.1.1.19"
$szOID_INFOSEC_mosaicKMandUpdSig     = "2.16.840.1.101.2.1.1.20"
$szOID_INFOSEC_mosaicUpdatedInteg    = "2.16.840.1.101.2.1.1.21"

'// NIST Hash Algorithms
'// joint-iso-itu-t(2) country(16) us(840) organization(1) gov(101) csor(3) nistalgorithm(4) hashalgs(2)

$szOID_NIST_sha256                  = "2.16.840.1.101.3.4.2.1"
$szOID_NIST_sha384                  = "2.16.840.1.101.3.4.2.2"
$szOID_NIST_sha512                  = "2.16.840.1.101.3.4.2.3"

' // Size = 8 bytes
TYPE CRYPT_OBJID_TABLE DWORD
   dwAlgId  AS DWORD        ' DWORD   dwAlgId
   pszObjId AS ASCIIZ PTR   ' LPCSTR  pszObjId
END TYPE

'//+-------------------------------------------------------------------------
'//  PKCS #1 HashInfo (DigestInfo)
'//--------------------------------------------------------------------------
' // Size = 20 bytes
TYPE CRYPT_HASH_INFO DWORD
   HashAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER  HashAlgorithm
   Hash          AS CRYPT_HASH_BLOB              ' CRYPT_HASH_BLOB             Hash
END TYPE

'//+-------------------------------------------------------------------------
'//  Type used for an extension to an encoded content
'//
'//  Where the Value's CRYPT_OBJID_BLOB is in its encoded representation.
'//--------------------------------------------------------------------------
' // Size = 16 bytes
TYPE CERT_EXTENSION DWORD
   pszObjId  AS ASCIIZ PTR         ' LPSTR               pszObjId
   fCritical AS LONG               ' BOOL                fCritical
   Value     AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB    Value
END TYPE

'//+-------------------------------------------------------------------------
'//  AttributeTypeValue
'//
'//  Where the Value's CRYPT_OBJID_BLOB is in its encoded representation.
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_ATTRIBUTE_TYPE_VALUE DWORD
   pszObjId AS ASCIIZ PTR         ' LPSTR               pszObjId
   Value    AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB    Value
END TYPE

'//+-------------------------------------------------------------------------
'//  Attributes
'//
'//  Where the Value's PATTR_BLOBs are in their encoded representation.
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_ATTRIBUTE DWORD
   pszObjId AS ASCIIZ PTR            ' LPSTR               pszObjId
   cValue   AS DWORD                 ' DWORD               cValue
   rgValue  AS CRYPT_ATTR_BLOB PTR   ' PCRYPT_ATTR_BLOB    rgValue
END TYPE

' // Size = 8 bytes
TYPE CRYPT_ATTRIBUTES DWORD
   cAttr  AS DWORD                 ' __in DWORD                cAttr
   rgAttr AS CRYPT_ATTRIBUTE PTR   ' __in PCRYPT_ATTRIBUTE     rgAttr
END TYPE

'//+-------------------------------------------------------------------------
'//  Attributes making up a Relative Distinguished Name (CERT_RDN)
'//
'//  The interpretation of the Value depends on the dwValueType.
'//  See below for a list of the types.
'//--------------------------------------------------------------------------
' // Size = 16 bytes
TYPE CERT_RDN_ATTR DWORD
   pszObjId    AS ASCIIZ PTR            ' LPSTR                   pszObjId
   dwValueType AS DWORD                 ' DWORD                   dwValueType
   Value       AS CERT_RDN_VALUE_BLOB   ' CERT_RDN_VALUE_BLOB     Value
END TYPE

'//+-------------------------------------------------------------------------
'//  CERT_RDN attribute Object Identifiers
'//--------------------------------------------------------------------------
'// Labeling attribute types:
$szOID_COMMON_NAME                   = "2.5.4.3"  ' // case-ignore string
$szOID_SUR_NAME                      = "2.5.4.4"  ' // case-ignore string
$szOID_DEVICE_SERIAL_NUMBER          = "2.5.4.5"  ' // printable string

'// Geographic attribute types:
$szOID_COUNTRY_NAME                  = "2.5.4.6"  ' // printable 2char string
$szOID_LOCALITY_NAME                 = "2.5.4.7"  ' // case-ignore string
$szOID_STATE_OR_PROVINCE_NAME        = "2.5.4.8"  ' // case-ignore string
$szOID_STREET_ADDRESS                = "2.5.4.9"  ' // case-ignore string

'// Organizational attribute types:
$szOID_ORGANIZATION_NAME             = "2.5.4.10"  ' // case-ignore string
$szOID_ORGANIZATIONAL_UNIT_NAME      = "2.5.4.11"  ' // case-ignore string
$szOID_TITLE                         = "2.5.4.12"  ' // case-ignore string

'// Explanatory attribute types:
$szOID_DESCRIPTION                   = "2.5.4.13"  ' // case-ignore string
$szOID_SEARCH_GUIDE                  = "2.5.4.14"
$szOID_BUSINESS_CATEGORY             = "2.5.4.15"  ' // case-ignore string

'// Postal addressing attribute types:
$szOID_POSTAL_ADDRESS                = "2.5.4.16"
$szOID_POSTAL_CODE                   = "2.5.4.17"  ' // case-ignore string
$szOID_POST_OFFICE_BOX               = "2.5.4.18"  ' // case-ignore string
$szOID_PHYSICAL_DELIVERY_OFFICE_NAME = "2.5.4.19"  ' // case-ignore string

'// Telecommunications addressing attribute types:
$szOID_TELEPHONE_NUMBER              = "2.5.4.20"  ' // telephone number
$szOID_TELEX_NUMBER                  = "2.5.4.21"
$szOID_TELETEXT_TERMINAL_IDENTIFIER  = "2.5.4.22"
$szOID_FACSIMILE_TELEPHONE_NUMBER    = "2.5.4.23"
$szOID_X21_ADDRESS                   = "2.5.4.24"  ' // numeric string
$szOID_INTERNATIONAL_ISDN_NUMBER     = "2.5.4.25"  ' // numeric string
$szOID_REGISTERED_ADDRESS            = "2.5.4.26"
$szOID_DESTINATION_INDICATOR         = "2.5.4.27"  ' // printable string

'// Preference attribute types:
$szOID_PREFERRED_DELIVERY_METHOD     = "2.5.4.28"

'// OSI application attribute types:
$szOID_PRESENTATION_ADDRESS          = "2.5.4.29"
$szOID_SUPPORTED_APPLICATION_CONTEXT = "2.5.4.30"

'// Relational application attribute types:
$szOID_MEMBER                        = "2.5.4.31"
$szOID_OWNER                         = "2.5.4.32"
$szOID_ROLE_OCCUPANT                 = "2.5.4.33"
$szOID_SEE_ALSO                      = "2.5.4.34"

'// Security attribute types:
$szOID_USER_PASSWORD                 = "2.5.4.35"
$szOID_USER_CERTIFICATE              = "2.5.4.36"
$szOID_CA_CERTIFICATE                = "2.5.4.37"
$szOID_AUTHORITY_REVOCATION_LIST     = "2.5.4.38"
$szOID_CERTIFICATE_REVOCATION_LIST   = "2.5.4.39"
$szOID_CROSS_CERTIFICATE_PAIR        = "2.5.4.40"

'// Undocumented attribute types???
'//#define szOID_???                         "2.5.4.41"
$szOID_GIVEN_NAME                    = "2.5.4.42"  ' // case-ignore string
$szOID_INITIALS                      = "2.5.4.43"  ' // case-ignore string

'// The DN Qualifier attribute type specifies disambiguating information to add
'// to the relative distinguished name of an entry. It is intended to be used
'// for entries held in multiple DSAs which would otherwise have the same name,
'// and that its value be the same in a given DSA for all entries to which
'// the information has been added.
$szOID_DN_QUALIFIER                  = "2.5.4.46"

'// Pilot user attribute types:
$szOID_DOMAIN_COMPONENT  = "0.9.2342.19200300.100.1.25"  ' // IA5, UTF8 string

'// used for PKCS 12 attributes
$szOID_PKCS_12_FRIENDLY_NAME_ATTR     = "1.2.840.113549.1.9.20"
$szOID_PKCS_12_LOCAL_KEY_ID           = "1.2.840.113549.1.9.21"
$szOID_PKCS_12_KEY_PROVIDER_NAME_ATTR = "1.3.6.1.4.1.311.17.1"
$szOID_LOCAL_MACHINE_KEYSET           = "1.3.6.1.4.1.311.17.2"
$szOID_PKCS_12_EXTENDED_ATTRIBUTES    = "1.3.6.1.4.1.311.17.3"

'//+-------------------------------------------------------------------------
'//  Microsoft CERT_RDN attribute Object Identifiers
'//--------------------------------------------------------------------------
'// Special RDN containing the KEY_ID. Its value type is CERT_RDN_OCTET_STRING.
$szOID_KEYID_RDN                     = "1.3.6.1.4.1.311.10.7.1"

'//+-------------------------------------------------------------------------
'//  EV RDN OIDs
'//--------------------------------------------------------------------------
$szOID_EV_RDN_LOCALE            = "1.3.6.1.4.1.311.60.2.1.1"
$szOID_EV_RDN_STATE_OR_PROVINCE = "1.3.6.1.4.1.311.60.2.1.2"
$szOID_EV_RDN_COUNTRY           = "1.3.6.1.4.1.311.60.2.1.3"

'//+-------------------------------------------------------------------------
'//  CERT_RDN Attribute Value Types
'//
'//  For RDN_ENCODED_BLOB, the Value's CERT_RDN_VALUE_BLOB is in its encoded
'//  representation. Otherwise, its an array of bytes.
'//
'//  For all CERT_RDN types, Value.cbData is always the number of bytes, not
'//  necessarily the number of elements in the string. For instance,
'//  RDN_UNIVERSAL_STRING is an array of ints (cbData == intCnt * 4) and
'//  RDN_BMP_STRING is an array of unsigned shorts (cbData == ushortCnt * 2).
'//
'//  A RDN_UTF8_STRING is an array of UNICODE characters (cbData == charCnt *2).
'//  These UNICODE characters are encoded as UTF8 8 bit characters.
'//
'//  For CertDecodeName, two 0 bytes are always appended to the end of the
'//  string (ensures a CHAR or WCHAR string is null terminated).
'//  These added 0 bytes are't included in the BLOB.cbData.
'//--------------------------------------------------------------------------
%CERT_RDN_ANY_TYPE               = 0???
%CERT_RDN_ENCODED_BLOB           = 1???
%CERT_RDN_OCTET_STRING           = 2???
%CERT_RDN_NUMERIC_STRING         = 3???
%CERT_RDN_PRINTABLE_STRING       = 4???
%CERT_RDN_TELETEX_STRING         = 5???
%CERT_RDN_T61_STRING             = 5???
%CERT_RDN_VIDEOTEX_STRING        = 6???
%CERT_RDN_IA5_STRING             = 7???
%CERT_RDN_GRAPHIC_STRING         = 8???
%CERT_RDN_VISIBLE_STRING         = 9???
%CERT_RDN_ISO646_STRING          = 9???
%CERT_RDN_GENERAL_STRING         = 10???
%CERT_RDN_UNIVERSAL_STRING       = 11???
%CERT_RDN_INT4_STRING            = 11???
%CERT_RDN_BMP_STRING             = 12???
%CERT_RDN_UNICODE_STRING         = 12???
%CERT_RDN_UTF8_STRING            = 13???

%CERT_RDN_TYPE_MASK              = &H000000FF???
%CERT_RDN_FLAGS_MASK             = &HFF000000???

'//+-------------------------------------------------------------------------
'//  Flags that can be or'ed with the above Value Type when encoding/decoding
'//--------------------------------------------------------------------------
'// For encoding: when set, CERT_RDN_T61_STRING is selected instead of
'// CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF
%CERT_RDN_ENABLE_T61_UNICODE_FLAG    = &H80000000???

'// For encoding: when set, CERT_RDN_UTF8_STRING is selected instead of
'// CERT_RDN_UNICODE_STRING.
%CERT_RDN_ENABLE_UTF8_UNICODE_FLAG   = &H20000000???

'// For encoding: when set, CERT_RDN_UTF8_STRING is selected instead of
'// CERT_RDN_PRINTABLE_STRING for DirectoryString types. Also,
'// enables CERT_RDN_ENABLE_UTF8_UNICODE_FLAG.
%CERT_RDN_FORCE_UTF8_UNICODE_FLAG    = &H10000000???

'// For encoding: when set, the characters aren't checked to see if they
'// are valid for the Value Type.
%CERT_RDN_DISABLE_CHECK_TYPE_FLAG    = &H40000000???

'// For decoding: by default, CERT_RDN_T61_STRING values are initially decoded
'// as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'// Setting this flag skips the initial attempt to decode as UTF8.
%CERT_RDN_DISABLE_IE4_UTF8_FLAG      = &H01000000???

'// For encoding: If the string contains E/Email RDN, and the email-address
'// (in RDN value) contains unicode characters outside of ASCII character set,
'// the localpart and the hostname portion of the email-address would be first
'// encoded in punycode and then the resultant Email-Address would be attempted
'// to be encoded as IA5String. Punycode encoding of hostname is done on
'// label-by-label basis.
'// For decoding: If the name contains E/Email RDN, and local part or hostname
'// portion of the email-address contains punycode encoded IA5String,
'// The RDN string value is converted to its unicode equivalent.
%CERT_RDN_ENABLE_PUNYCODE_FLAG       = &H02000000???

'// Macro to check that the dwValueType is a character string and not an
'// encoded blob or octet string
'#define IS_CERT_RDN_CHAR_STRING(X)      \
'                (((X) & CERT_RDN_TYPE_MASK) >= CERT_RDN_NUMERIC_STRING)

MACRO IS_CERT_RDN_CHAR_STRING(X) = (X AND %CERT_RDN_TYPE_MASK) >= %CERT_RDN_NUMERIC_STRING

'//+-------------------------------------------------------------------------
'//  A CERT_RDN consists of an array of the above attributes
'//--------------------------------------------------------------------------
' // Size = 8 bytes
TYPE CERT_RDN DWORD
   cRDNAttr  AS DWORD               ' DWORD           cRDNAttr
   rgRDNAttr AS CERT_RDN_ATTR PTR   ' PCERT_RDN_ATTR  rgRDNAttr
END TYPE

'//+-------------------------------------------------------------------------
'//  Information stored in a subject's or issuer's name. The information
'//  is represented as an array of the above RDNs.
''//--------------------------------------------------------------------------

'//--------------------------------------------------------------------------
' // Size = 8 bytes
TYPE CERT_NAME_INFO DWORD
   cRDN  AS DWORD          ' DWORD       cRDN
   rgRDN AS CERT_RDN PTR   ' PCERT_RDN   rgRDN
END TYPE

'//+-------------------------------------------------------------------------
'//  Name attribute value without the Object Identifier
'//
'//  The interpretation of the Value depends on the dwValueType.
'//  See above for a list of the types.
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CERT_NAME_VALUE DWORD
   dwValueType AS DWORD                 ' DWORD               dwValueType
   Value       AS CERT_RDN_VALUE_BLOB   ' CERT_RDN_VALUE_BLOB Value
END TYPE

'//+-------------------------------------------------------------------------
'//  Public Key Info
'//
'//  The PublicKey is the encoded representation of the information as it is
'//  stored in the bit string
'//--------------------------------------------------------------------------
' // Size = 24 bytes
TYPE CERT_PUBLIC_KEY_INFO DWORD
   Algorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER    Algorithm
   PublicKey AS CRYPT_BIT_BLOB               ' CRYPT_BIT_BLOB                PublicKey
END TYPE

$CERT_RSA_PUBLIC_KEY_OBJID            = $szOID_RSA_RSA
$CERT_DEFAULT_OID_PUBLIC_KEY_SIGN     = $szOID_RSA_RSA
$CERT_DEFAULT_OID_PUBLIC_KEY_XCHG     = $szOID_RSA_RSA

'//+-------------------------------------------------------------------------
'//  structure that contains all the information in a PKCS#8 PrivateKeyInfo
'//--------------------------------------------------------------------------
' // Size = 28 bytes
TYPE CRYPT_PRIVATE_KEY_INFO DWORD
   Version     AS DWORD                        ' DWORD                       Version
   Algorithm   AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER  Algorithm
   PrivateKey  AS CRYPT_DER_BLOB               ' CRYPT_DER_BLOB              PrivateKey
   pAttributes AS CRYPT_ATTRIBUTES PTR         ' PCRYPT_ATTRIBUTES           pAttributes
END TYPE

'//+-------------------------------------------------------------------------
'//  structure that contains all the information in a PKCS#8
'//  EncryptedPrivateKeyInfo
'//--------------------------------------------------------------------------
' // Size = 20 bytes
TYPE CRYPT_ENCRYPTED_PRIVATE_KEY_INFO DWORD
   EncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedPrivateKey AS CRYPT_DATA_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'// this callback is given when an EncryptedProvateKeyInfo structure is
'// encountered during ImportPKCS8.  the caller is then expected to decrypt
'// the private key and hand back the decrypted contents.
'//
'// the parameters are:
'// Algorithm - the algorithm used to encrypt the PrivateKeyInfo
'// EncryptedPrivateKey - the encrypted private key blob
'// pClearTextKey - a buffer to receive the clear text
'// cbClearTextKey - the number of bytes of the pClearTextKey buffer
'//                  note the if this is zero then this should be
'//                  filled in with the size required to decrypt the
'//                  key into, and pClearTextKey should be ignored
'// pVoidDecryptFunc - this is the pVoid that was passed into the call
'//                    and is preserved and passed back as context
'//+-------------------------------------------------------------------------
'typedef BOOL (CALLBACK *PCRYPT_DECRYPT_PRIVATE_KEY_FUNC)(
'              CRYPT_ALGORITHM_IDENTIFIER  Algorithm,
'              CRYPT_DATA_BLOB             EncryptedPrivateKey,
'              BYTE                        *pbClearTextKey,
'              DWORD                       *pcbClearTextKey,
'              LPVOID                      pVoidDecryptFunc);

'FUNCTION CRYPT_DECRYPT_PRIVATE_KEY_FUNC ( _
'   BYREF Algorithm AS CRYPT_ALGORITHM_IDENTIFIER, _
'   BYREF EncryptedPrivateKey AS CRYPT_DATA_BLOB, _
'   BYVAL pbClearTextKey AS BYTE PTR, _
'   BYREF pcbClearTextKey AS DWORD, _
'   BYVAL pVoidDecryptFunc AS DWORD _
'   ) AS LONG

'//+-------------------------------------------------------------------------
'// this callback is given when creating a PKCS8 EncryptedPrivateKeyInfo.
'// The caller is then expected to encrypt the private key and hand back
'// the encrypted contents.
'//
'// the parameters are:
'// Algorithm - the algorithm used to encrypt the PrivateKeyInfo
'// pClearTextPrivateKey - the cleartext private key to be encrypted
'// pbEncryptedKey - the output encrypted private key blob
'// cbEncryptedKey - the number of bytes of the pbEncryptedKey buffer
'//                  note the if this is zero then this should be
'//                  filled in with the size required to encrypt the
'//                  key into, and pbEncryptedKey should be ignored
'// pVoidEncryptFunc - this is the pVoid that was passed into the call
'//                    and is preserved and passed back as context
'//+-------------------------------------------------------------------------
'typedef BOOL (CALLBACK *PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC)(
'              CRYPT_ALGORITHM_IDENTIFIER* pAlgorithm,
'              CRYPT_DATA_BLOB*            pClearTextPrivateKey,
'              BYTE                        *pbEncryptedKey,
'              DWORD                       *pcbEncryptedKey,
'              LPVOID                      pVoidEncryptFunc);

'FUNCTION CRYPT_ENCRYPT_PRIVATE_KEY_FUNC ( _
'   BYREF pAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER, _
'   BYREF pClearTextPrivateKey AS CRYPT_DATA_BLOB, _
'   BYVAL pbEncryptedKey AS BYTE PTR, _
'   BYREF pcbEncryptedKey AS DWORD, _
'   BYVAL pVoidEncryptFunc AS DWORD _
'   ) AS LONG

'//+-------------------------------------------------------------------------
'// this callback is given from the context of a ImportPKCS8 calls.  the caller
'// is then expected to hand back an HCRYPTPROV to receive the key being imported
'//
'// the parameters are:
'// pPrivateKeyInfo - pointer to a CRYPT_PRIVATE_KEY_INFO structure which
'//                   describes the key being imported
'// EncryptedPrivateKey - the encrypted private key blob
'// phCryptProv - a pointer to a HCRRYPTPROV to be filled in
'// pVoidResolveFunc - this is the pVoidResolveFunc passed in by the caller in the
'//                    CRYPT_PRIVATE_KEY_BLOB_AND_PARAMS struct
'//+-------------------------------------------------------------------------
'typedef BOOL (CALLBACK *PCRYPT_RESOLVE_HCRYPTPROV_FUNC)(
'              CRYPT_PRIVATE_KEY_INFO      *pPrivateKeyInfo,
'              HCRYPTPROV                  *phCryptProv,
'              LPVOID                      pVoidResolveFunc);

'FUNCTION CRYPT_RESOLVE_HCRYPTPROV_FUNC ( :
'   BYREF pPrivateKeyInfo AS CRYPT_PRIVATE_KEY_INFO, _
'   BYVAL phCryptProv AS DWORD
'   BYVAL pVoidResolveFunc) AS DWORD _
'   ) AS LONG

'//+-------------------------------------------------------------------------
'// this struct contains a PKCS8 private key and two pointers to callback
'// functions, with a corresponding pVoids.  the first callback is used to give
'// the caller the opportunity to specify where the key is imported to.  the callback
'// passes the caller the algoroithm OID and key size to use in making the decision.
'// the other callback is used to decrypt the private key if the PKCS8 contains an
'// EncryptedPrivateKeyInfo.  both pVoids are preserved and passed back to the caller
'// in the respective callback
'//+-------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CRYPT_PKCS8_IMPORT_PARAMS DWORD
   PrivateKey             AS  CRYPT_DIGEST_BLOB   ' CRYPT_DIGEST_BLOB
   pResolvehCryptProvFunc AS  DWORD               ' PCRYPT_RESOLVE_HCRYPTPROV_FUNC
   pVoidResolveFunc       AS  DWORD               ' LPVOID
   pDecryptPrivateKeyFunc AS  DWORD               ' PCRYPT_DECRYPT_PRIVATE_KEY_FUNC
   pVoidDecryptFunc       AS  DWORD               ' LPVOID
END TYPE

'//+-------------------------------------------------------------------------
'// this struct contains information identifying a private key and a pointer
'// to a callback function, with a corresponding pVoid. The callback is used
'// to encrypt the private key. If the pEncryptPrivateKeyFunc is NULL, the
'// key will not be encrypted and an EncryptedPrivateKeyInfo will not be generated.
'// The pVoid is preserved and passed back to the caller in the respective callback
'//+-------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPT_PKCS8_EXPORT_PARAMS DWORD
   hCryptProv             AS DWORD        ' HCRYPTPROV
   dwKeySpec              AS DWORD        ' DWORD
   pszPrivateKeyObjId     AS ASCIIZ PTR   ' LPSTR
   pEncryptPrivateKeyFunc AS DWORD        ' PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC
   pVoidEncryptFunc       AS DWORD        ' LPVOID
END TYPE

'//+-------------------------------------------------------------------------
'//  Information stored in a certificate
'//
'//  The Issuer, Subject, Algorithm, PublicKey and Extension BLOBs are the
'//  encoded representation of the information.
'//--------------------------------------------------------------------------

' // Size = 112 bytes
TYPE CERT_INFO DWORD
   dwVersion            AS DWORD                        ' DWORD
   SerialNumber         AS CRYPT_INTEGER_BLOB           ' CRYPT_INTEGER_BLOB
   SignatureAlgorithm   AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   Issuer               AS CERT_NAME_BLOB               ' CERT_NAME_BLOB
   NotBefore            AS FILETIME                     ' FILETIME
   NotAfter             AS FILETIME                     ' FILETIME
   Subject              AS CERT_NAME_BLOB               ' CERT_NAME_BLOB
   SubjectPublicKeyInfo AS CERT_PUBLIC_KEY_INFO         ' CERT_PUBLIC_KEY_INFO
   IssuerUniqueId       AS CRYPT_BIT_BLOB               ' CRYPT_BIT_BLOB
   SubjectUniqueId      AS CRYPT_BIT_BLOB               ' CRYPT_BIT_BLOB
   cExtension           AS DWORD                        ' DWORD
   rgExtension          AS CERT_EXTENSION PTR           ' PCERT_EXTENSION
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate versions
'//--------------------------------------------------------------------------
%CERT_V1    = 0
%CERT_V2    = 1
%CERT_V3    = 2

'//+-------------------------------------------------------------------------
'//  Certificate Information Flags
'//--------------------------------------------------------------------------
%CERT_INFO_VERSION_FLAG                     = 1???
%CERT_INFO_SERIAL_NUMBER_FLAG               = 2???
%CERT_INFO_SIGNATURE_ALGORITHM_FLAG         = 3???
%CERT_INFO_ISSUER_FLAG                      = 4???
%CERT_INFO_NOT_BEFORE_FLAG                  = 5???
%CERT_INFO_NOT_AFTER_FLAG                   = 6???
%CERT_INFO_SUBJECT_FLAG                     = 7???
%CERT_INFO_SUBJECT_PUBLIC_KEY_INFO_FLAG     = 8???
%CERT_INFO_ISSUER_UNIQUE_ID_FLAG            = 9???
%CERT_INFO_SUBJECT_UNIQUE_ID_FLAG           = 10???
%CERT_INFO_EXTENSION_FLAG                   = 11???

'//+-------------------------------------------------------------------------
'//  An entry in a CRL
'//
'//  The Extension BLOBs are the encoded representation of the information.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CRL_ENTRY DWORD
   SerialNumber   AS CRYPT_INTEGER_BLOB   ' CRYPT_INTEGER_BLOB
   RevocationDate AS FILETIME             ' FILETIME
   cExtension     AS DWORD                ' DWORD
   rgExtension    AS CERT_EXTENSION PTR   ' PCERT_EXTENSION
END TYPE

'//+-------------------------------------------------------------------------
'//  Information stored in a CRL
'//
'//  The Issuer, Algorithm and Extension BLOBs are the encoded
'//  representation of the information.
'//--------------------------------------------------------------------------

' // Size = 56 bytes
TYPE CRL_INFO DWORD
   dwVersion          AS DWORD                        ' DWORD
   SignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   Issuer             AS CERT_NAME_BLOB               ' CERT_NAME_BLOB
   ThisUpdate         AS FILETIME                     ' FILETIME
   NextUpdate         AS FILETIME                     ' FILETIME
   cCRLEntry          AS DWORD                        ' DWORD
   rgCRLEntry         AS CRL_ENTRY PTR                ' PCRL_ENTRY
   cExtension         AS DWORD                        ' DWORD
   rgExtension        AS CERT_EXTENSION PTR           ' PCERT_EXTENSION
END TYPE

'//+-------------------------------------------------------------------------
'//  CRL versions
'//--------------------------------------------------------------------------
%CRL_V1    = 0
%CRL_V2    = 1

'//+-------------------------------------------------------------------------
'// Certificate Bundle
'//--------------------------------------------------------------------------
%CERT_BUNDLE_CERTIFICATE = 0
%CERT_BUNDLE_CRL         = 1

' // Size = 12 bytes
TYPE CERT_OR_CRL_BLOB DWORD
   dwChoice  AS DWORD      ' DWORD
   cbEncoded AS DWORD      ' DWORD
   pbEncoded AS BYTE PTR   ' __field_bcount(cbEncoded) BYTE*
END TYPE

' // Size = 8 bytes
TYPE CERT_OR_CRL_BUNDLE DWORD
   cItem  AS DWORD                  ' DWORD
   rgItem AS CERT_OR_CRL_BLOB PTR   ' __field_ecount(cItem) PCERT_OR_CRL_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Information stored in a certificate request
'//
'//  The Subject, Algorithm, PublicKey and Attribute BLOBs are the encoded
'//  representation of the information.
'//--------------------------------------------------------------------------

' // Size = 44 bytes
TYPE CERT_REQUEST_INFO DWORD
   dwVersion            AS DWORD                  ' DWORD
   Subject              AS CERT_NAME_BLOB         ' CERT_NAME_BLOB
   SubjectPublicKeyInfo AS CERT_PUBLIC_KEY_INFO   ' CERT_PUBLIC_KEY_INFO
   cAttribute           AS DWORD                  ' DWORD
   rgAttribute          AS CRYPT_ATTRIBUTE PTR    ' PCRYPT_ATTRIBUTE
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate Request versions
'//--------------------------------------------------------------------------
%CERT_REQUEST_V1    = 0

'//+-------------------------------------------------------------------------
'//  Information stored in Netscape's Keygen request
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CERT_KEYGEN_REQUEST_INFO DWORD
   dwVersion            AS DWORD                  ' DWORD
   SubjectPublicKeyInfo AS CERT_PUBLIC_KEY_INFO   ' CERT_PUBLIC_KEY_INFO
   pwszChallengeString  AS WSTRINGZ PTR           ' LPWSTR
END TYPE

%CERT_KEYGEN_REQUEST_V1    = 0


'//+-------------------------------------------------------------------------
'//  Certificate, CRL, Certificate Request or Keygen Request Signed Content
'//
'//  The "to be signed" encoded content plus its signature. The ToBeSigned
'//  is the encoded CERT_INFO, CRL_INFO, CERT_REQUEST_INFO or
'//  CERT_KEYGEN_REQUEST_INFO.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CERT_SIGNED_CONTENT_INFO DWORD
   ToBeSigned         AS CRYPT_DER_BLOB
   SignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   Signature          AS CRYPT_BIT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate Trust List (CTL)
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CTL Usage. Also used for EnhancedKeyUsage extension.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CTL_USAGE DWORD
   cUsageIdentifier     AS DWORD        ' DWORD
   rgpszUsageIdentifier AS ASCIIZ PTR   ' LPSTR
END TYPE

MACRO CERT_ENHKEY_USAGE = CTL_USAGE

'//+-------------------------------------------------------------------------
'//  An entry in a CTL
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CTL_ENTRY DWORD
   SubjectIdentifier AS CRYPT_DATA_BLOB       ' CRYPT_DATA_BLOB
   cAttribute        AS DWORD                 ' DWORD
   rgAttribute       AS CRYPT_ATTRIBUTE PTR   ' PCRYPT_ATTRIBUTE
END TYPE

'//+-------------------------------------------------------------------------
'//  Information stored in a CTL
'//--------------------------------------------------------------------------

' // Size = 72 bytes
TYPE CTL_INFO DWORD
   dwVersion        AS DWORD                        ' DWORD
   SubjectUsage     AS CTL_USAGE                    ' CTL_USAGE
   ListIdentifier   AS CRYPT_DATA_BLOB              ' CRYPT_DATA_BLOB
   SequenceNumber   AS CRYPT_INTEGER_BLOB           ' CRYPT_INTEGER_BLOB
   ThisUpdate       AS FILETIME                     ' FILETIME
   NextUpdate       AS FILETIME                     ' FILETIME
   SubjectAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   cCTLEntry        AS DWORD                        ' DWORD
   rgCTLEntry       AS CTL_ENTRY PTR                ' PCTL_ENTRY
   cExtension       AS DWORD                        ' DWORD
   rgExtension      AS CERT_EXTENSION PTR           ' PCERT_EXTENSION
END TYPE

'//+-------------------------------------------------------------------------
'//  CTL versions
'//--------------------------------------------------------------------------
%CTL_V1    = 0


'//+-------------------------------------------------------------------------
'//  TimeStamp Request
'//
'//  The pszTimeStamp is the OID for the Time type requested
'//  The pszContentType is the Content Type OID for the content, usually DATA
'//  The Content is a un-decoded blob
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CRYPT_TIME_STAMP_REQUEST_INFO DWORD
   pszTimeStampAlgorithm AS ASCIIZ PTR            ' LPSTR
   pszContentType        AS ASCIIZ PTR            ' LPSTR
   Content               AS CRYPT_OBJID_BLOB      ' CRYPT_OBJID_BLOB
   cAttribute            AS DWORD                 ' DWORD
   rgAttribute           AS CRYPT_ATTRIBUTE PTR   ' PCRYPT_ATTRIBUTE
END TYPE

'//+-------------------------------------------------------------------------
'//  Name Value Attribute
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CRYPT_ENROLLMENT_NAME_VALUE_PAIR DWORD
   pwszName  AS WSTRINGZ PTR   ' LPWSTR
   pwszValue AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'//+-------------------------------------------------------------------------
'//  CSP Provider
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPT_CSP_PROVIDER DWORD
   dwKeySpec        AS DWORD            ' DWORD
   pwszProviderName AS WSTRINGZ PTR     ' LPWSTR
   Signature        AS CRYPT_BIT_BLOB   ' CRYPT_BIT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate and Message encoding types
'//
'//  The encoding type is a DWORD containing both the certificate and message
'//  encoding types. The certificate encoding type is stored in the LOWORD.
'//  The message encoding type is stored in the HIWORD. Some functions or
'//  structure fields require only one of the encoding types. The following
'//  naming convention is used to indicate which encoding type(s) are
'//  required:
'//      dwEncodingType              (both encoding types are required)
'//      dwMsgAndCertEncodingType    (both encoding types are required)
'//      dwMsgEncodingType           (only msg encoding type is required)
'//      dwCertEncodingType          (only cert encoding type is required)
'//
'//  Its always acceptable to specify both.
'//--------------------------------------------------------------------------
%CERT_ENCODING_TYPE_MASK     = &H0000FFFF???
%CMSG_ENCODING_TYPE_MASK     = &HFFFF0000???

MACRO GET_CERT_ENCODING_TYPE(X) = X AND %CERT_ENCODING_TYPE_MASK
MACRO GET_CMSG_ENCODING_TYPE(X) = X AND %CMSG_ENCODING_TYPE_MASK

%CRYPT_ASN_ENCODING          = &H00000001???
%CRYPT_NDR_ENCODING          = &H00000002???
%X509_ASN_ENCODING           = &H00000001???
%X509_NDR_ENCODING           = &H00000002???
%PKCS_7_ASN_ENCODING         = &H00010000???
%PKCS_7_NDR_ENCODING         = &H00020000???


'//+-------------------------------------------------------------------------
'//  format the specified data structure according to the certificate
'//  encoding type.
'//
'//  The default behavior of CryptFormatObject is to return single line
'//  display of the encoded data, that is, each subfield will be concatenated with
'//  a ", " on one line.  If user prefers to display the data in multiple line,
'//  set the flag CRYPT_FORMAT_STR_MULTI_LINE, that is, each subfield will be displayed
'//  on a seperate line.
'//
'//  If there is no formatting routine installed or registered
'//  for the lpszStructType, the hex dump of the encoded BLOB will be returned.
'//  User can set the flag CRYPT_FORMAT_STR_NO_HEX to disable the hex dump.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptFormatObject LIB "Crypt32.dll" ALIAS "CryptFormatObject" _
    (BYVAL dwCertEncodingType AS DWORD, BYVAL dwFormatType AS DWORD, _
    BYVAL dwFormatStrType AS DWORD, pFormatStruct AS ANY, _
    lpszStructType AS ASCIIZ, BYVAL pbEncoded AS BYTE PTR, _
    BYVAL cbEncoded AS DWORD, pbFormat AS ANY, pcbFormat AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptFormatObject IMPORT "CRYPT32.DLL" ALIAS "CryptFormatObject" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwFormatType AS DWORD _                        ' __in DWORD dwFormatType
 , BYVAL dwFormatStrType AS DWORD _                     ' __in DWORD dwFormatStrType
 , BYVAL pFormatStruct AS DWORD _                       ' __in void  *pFormatStruct
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR lpszStructType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYREF pbFormat AS DWORD _                            ' __out void *pbFormat
 , BYREF pcbFormat AS DWORD _                           ' __inout DWORD *pcbFormat
 ) AS LONG                                              ' BOOL
#ENDIF

'//-------------------------------------------------------------------------
'// constants for dwFormatStrType of function CryptFormatObject
'//-------------------------------------------------------------------------
%CRYPT_FORMAT_STR_MULTI_LINE         = &H0001???
%CRYPT_FORMAT_STR_NO_HEX             = &H0010???

'//-------------------------------------------------------------------------
'// constants for dwFormatType of function CryptFormatObject
'// when format X509_NAME or X509_UNICODE_NAME
'//-------------------------------------------------------------------------
'// Just get the simple string
%CRYPT_FORMAT_SIMPLE                 = &H0001???

'//Put an attribute name infront of the attribute
'//such as "O=Microsoft,DN=xiaohs"
%CRYPT_FORMAT_X509                   = &H0002???

'//Put an OID infront of the simple string, such as
'//"2.5.4.22=Microsoft,2.5.4.3=xiaohs"
%CRYPT_FORMAT_OID                    = &H0004???

'//Put a ";" between each RDN.  The default is ","
%CRYPT_FORMAT_RDN_SEMICOLON          = &H0100???

'//Put a "\n" between each RDN.
%CRYPT_FORMAT_RDN_CRLF               = &H0200???


'//Unquote the DN value, which is quoated by default va the following
'//rules: if the DN contains leading or trailing
'//white space or one of the following characters: ",", "+", "=",
'//""", "\n",  "<", ">", "#" or ";". The quoting character is ".
'//If the DN Value contains a " it is double quoted ("").
%CRYPT_FORMAT_RDN_UNQUOTE            = &H0400???

'//reverse the order of the RDNs before converting to the string
%CRYPT_FORMAT_RDN_REVERSE            = &H0800???


'//-------------------------------------------------------------------------
'//  contants dwFormatType of function CryptFormatObject when format a DN.:
'//
'//  The following three values are defined in the section above:
'//  CRYPT_FORMAT_SIMPLE:    Just a simple string
'//                          such as  "Microsoft+xiaohs+NT"
'//  CRYPT_FORMAT_X509       Put an attribute name infront of the attribute
'//                          such as "O=Microsoft+xiaohs+NT"
'//
'//  CRYPT_FORMAT_OID        Put an OID infront of the simple string,
'//                          such as "2.5.4.22=Microsoft+xiaohs+NT"
'//
'//  Additional values are defined as following:
'//----------------------------------------------------------------------------
'//Put a "," between each value.  Default is "+"
%CRYPT_FORMAT_COMMA                  = &H1000???

'//Put a ";" between each value
%CRYPT_FORMAT_SEMICOLON              = %CRYPT_FORMAT_RDN_SEMICOLON

'//Put a "\n" between each value
%CRYPT_FORMAT_CRLF                   = %CRYPT_FORMAT_RDN_CRLF

'//+-------------------------------------------------------------------------
'//  Encode / decode the specified data structure according to the certificate
'//  encoding type.
'//
'//  See below for a list of the predefined data structures.
'//--------------------------------------------------------------------------

'typedef LPVOID (WINAPI *PFN_CRYPT_ALLOC)(
'    IN size_t cbSize
'    );

'FUNCTION CRYPT_ALLOC ( _
'   BYVAL cbSize AS DWORD _             ' __in size_t cbSize
'   ) AS DWORD                          ' LPVOID

'typedef VOID (WINAPI *PFN_CRYPT_FREE)(
'    IN LPVOID pv
'    );

'SUB CRYPT_FREE ( _
'   BYVAL pv AS DWORD _                 ' __in LPVOID pv
'   )                                   ' void

' // Size = 12 bytes
TYPE CRYPT_ENCODE_PARA DWORD
   cbSize   AS DWORD   ' DWORD
   pfnAlloc AS DWORD   ' PFN_CRYPT_ALLOC
   pfnFree  AS DWORD   ' PFN_CRYPT_FREE
END TYPE

DECLARE FUNCTION CryptEncodeObjectEx IMPORT "CRYPT32.DLL" ALIAS "CryptEncodeObjectEx" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR lpszStructType
 , BYREF pvStructInfo AS ANY _                          ' __in const void   *pvStructInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pEncodePara AS CRYPT_ENCODE_PARA _             ' __in_opt PCRYPT_ENCODE_PARA pEncodePara
 , BYREF pvEncoded AS ANY _                             ' __out void *pvEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptEncodeObject IMPORT "CRYPT32.DLL" ALIAS "CryptEncodeObject" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD        dwCertEncodingType
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR       lpszStructType
 , BYREF pvStructInfo AS ANY _                          ' __in const void   *pvStructInfo
 , BYVAL pbEncoded AS BYTE PTR _                        ' __out BYTE        *pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD    *pcbEncoded
 ) AS LONG                                              ' BOOL

'// By default the signature bytes are reversed. The following flag can
'// be set to inhibit the byte reversal.
'//
'// This flag is applicable to
'//      X509_CERT_TO_BE_SIGNED
%CRYPT_ENCODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    = &H8???


'//  When the following flag is set the called encode function allocates
'//  memory for the encoded bytes. A pointer to the allocated bytes
'//  is returned in pvEncoded. If pEncodePara or pEncodePara->pfnAlloc is
'//  NULL, then, LocalAlloc is called for the allocation and LocalFree must
'//  be called to do the free. Otherwise, pEncodePara->pfnAlloc is called
'//  for the allocation.
'//
'//  *pcbEncoded is ignored on input and updated with the length of the
'//  allocated, encoded bytes.
'//
'//  If pfnAlloc is set, then, pfnFree should also be set.
%CRYPT_ENCODE_ALLOC_FLAG             = &H8000???


'//  The following flag is applicable when encoding X509_UNICODE_NAME.
'//  When set, CERT_RDN_T61_STRING is selected instead of
'//  CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF
%CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG = %CERT_RDN_ENABLE_T61_UNICODE_FLAG

'//  The following flag is applicable when encoding X509_UNICODE_NAME.
'//  When set, CERT_RDN_UTF8_STRING is selected instead of
'//  CERT_RDN_UNICODE_STRING.
%CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG = %CERT_RDN_ENABLE_UTF8_UNICODE_FLAG

'//  The following flag is applicable when encoding X509_UNICODE_NAME.
'//  When set, CERT_RDN_UTF8_STRING is selected instead of
'//  CERT_RDN_PRINTABLE_STRING for DirectoryString types. Also,
'//  enables CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG.
%CRYPT_UNICODE_NAME_ENCODE_FORCE_UTF8_UNICODE_FLAG = %CERT_RDN_FORCE_UTF8_UNICODE_FLAG

'//  The following flag is applicable when encoding X509_UNICODE_NAME,
'//  X509_UNICODE_NAME_VALUE or X509_UNICODE_ANY_STRING.
'//  When set, the characters aren't checked to see if they
'//  are valid for the specified Value Type.
%CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG = %CERT_RDN_DISABLE_CHECK_TYPE_FLAG

'//  The following flag is applicable when encoding the PKCS_SORTED_CTL. This
'//  flag should be set if the identifier for the TrustedSubjects is a hash,
'//  such as, MD5 or SHA1.
%CRYPT_SORTED_CTL_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG     = &H10000???

'// The following flag is applicable when encoding structures that require
'// IA5String encoding of host name(in DNS Name/ URL/ EmailAddress) containing
'// non-IA5 characters by encoding the host name in punycode first.
%CRYPT_ENCODE_ENABLE_PUNYCODE_FLAG   = &H20000???

' // Size = 12 bytes
TYPE CRYPT_DECODE_PARA DWORD
   cbSize   AS DWORD   ' DWORD
   pfnAlloc AS DWORD   ' PFN_CRYPT_ALLOC
   pfnFree  AS DWORD   ' PFN_CRYPT_FREE
END TYPE

DECLARE FUNCTION CryptDecodeObjectEx IMPORT "CRYPT32.DLL" ALIAS "CryptDecodeObjectEx" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR lpszStructType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pDecodePara AS CRYPT_DECODE_PARA _             ' __in_opt PCRYPT_DECODE_PARA pDecodePara
 , BYREF pvStructInfo AS ANY _                          ' __out_opt void *pvStructInfo
 , BYREF pcbStructInfo AS DWORD _                       ' __inout DWORD *pcbStructInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptDecodeObject IMPORT "CRYPT32.DLL" ALIAS "CryptDecodeObject" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD        dwCertEncodingType
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR       lpszStructType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE   *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD        cbEncoded
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD        dwFlags
 , BYREF pvStructInfo AS ANY _                          ' __out void        *pvStructInfo
 , BYREF pcbStructInfo AS DWORD _                       ' __inout DWORD    *pcbStructInfo
 ) AS LONG                                              ' BOOL

'// When the following flag is set the nocopy optimization is enabled.
'// This optimization where appropriate, updates the pvStructInfo fields
'// to point to content residing within pbEncoded instead of making a copy
'// of and appending to pvStructInfo.
'//
'// Note, when set, pbEncoded can't be freed until pvStructInfo is freed.
%CRYPT_DECODE_NOCOPY_FLAG            = &H1???

'// For CryptDecodeObject(), by default the pbEncoded is the "to be signed"
'// plus its signature. Set the following flag, if pbEncoded points to only
'// the "to be signed".
'//
'// This flag is applicable to
'//      X509_CERT_TO_BE_SIGNED
'//      X509_CERT_CRL_TO_BE_SIGNED
'//      X509_CERT_REQUEST_TO_BE_SIGNED
'//      X509_KEYGEN_REQUEST_TO_BE_SIGNED
%CRYPT_DECODE_TO_BE_SIGNED_FLAG      = &H2???

'// When the following flag is set, the OID strings are allocated in
'// crypt32.dll and shared instead of being copied into the returned
'// data structure. This flag may be set if crypt32.dll isn't unloaded
'// before the caller is unloaded.
%CRYPT_DECODE_SHARE_OID_STRING_FLAG  = &H4???

'// By default the signature bytes are reversed. The following flag can
'// be set to inhibit the byte reversal.
'//
'// This flag is applicable to
'//      X509_CERT_TO_BE_SIGNED
%CRYPT_DECODE_NO_SIGNATURE_BYTE_REVERSAL_FLAG    = &H8???


'// When the following flag is set the called decode function allocates
'// memory for the decoded structure. A pointer to the allocated structure
'// is returned in pvStructInfo. If pDecodePara or pDecodePara->pfnAlloc is
'// NULL, then, LocalAlloc is called for the allocation and LocalFree must
'// be called to do the free. Otherwise, pDecodePara->pfnAlloc is called
'// for the allocation.
'//
'// *pcbStructInfo is ignored on input and updated with the length of the
'// allocated, decoded structure.
'//
'// This flag may also be set in the CryptDecodeObject API. Since
'// CryptDecodeObject doesn't take a pDecodePara, LocalAlloc is always
'// called for the allocation which must be freed by calling LocalFree.
%CRYPT_DECODE_ALLOC_FLAG             = &H8000???

'// The following flag is applicable when decoding X509_UNICODE_NAME,
'// X509_UNICODE_NAME_VALUE or X509_UNICODE_ANY_STRING.
'// By default, CERT_RDN_T61_STRING values are initially decoded
'// as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'// Setting this flag skips the initial attempt to decode as UTF8.
%CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG = %CERT_RDN_DISABLE_IE4_UTF8_FLAG

'// The following flag is applicable when decoding structures that contain
'// IA5String encoding of punycode encoded host name (in DNS Name/ URL/
'// EmailAddress). Decoded value contains the the unicode equivalent of
'// punycode encoded data.
%CRYPT_DECODE_ENABLE_PUNYCODE_FLAG   = &H02000000???

'//+-------------------------------------------------------------------------
'//  Predefined X509 certificate data structures that can be encoded / decoded.
'//--------------------------------------------------------------------------
'#define CRYPT_ENCODE_DECODE_NONE            0
'#define X509_CERT                           ((LPCSTR) 1)
'#define X509_CERT_TO_BE_SIGNED              ((LPCSTR) 2)
'#define X509_CERT_CRL_TO_BE_SIGNED          ((LPCSTR) 3)
'#define X509_CERT_REQUEST_TO_BE_SIGNED      ((LPCSTR) 4)
'#define X509_EXTENSIONS                     ((LPCSTR) 5)
'#define X509_NAME_VALUE                     ((LPCSTR) 6)
'#define X509_NAME                           ((LPCSTR) 7)
'#define X509_PUBLIC_KEY_INFO                ((LPCSTR) 8)

%CRYPT_ENCODE_DECODE_NONE            = 0
%X509_CERT                           = 1
%X509_CERT_TO_BE_SIGNED              = 2
%X509_CERT_CRL_TO_BE_SIGNED          = 3
%X509_CERT_REQUEST_TO_BE_SIGNED      = 4
%X509_EXTENSIONS                     = 5
%X509_NAME_VALUE                     = 6
%X509_NAME                           = 7
%X509_PUBLIC_KEY_INFO                = 8

'//+-------------------------------------------------------------------------
'//  Predefined X509 certificate extension data structures that can be
'//  encoded / decoded.
'//--------------------------------------------------------------------------
'#define X509_AUTHORITY_KEY_ID               ((LPCSTR) 9)
'#define X509_KEY_ATTRIBUTES                 ((LPCSTR) 10)
'#define X509_KEY_USAGE_RESTRICTION          ((LPCSTR) 11)
'#define X509_ALTERNATE_NAME                 ((LPCSTR) 12)
'#define X509_BASIC_CONSTRAINTS              ((LPCSTR) 13)
'#define X509_KEY_USAGE                      ((LPCSTR) 14)
'#define X509_BASIC_CONSTRAINTS2             ((LPCSTR) 15)
'#define X509_CERT_POLICIES                  ((LPCSTR) 16)

%X509_AUTHORITY_KEY_ID               = 9
%X509_KEY_ATTRIBUTES                 = 10
%X509_KEY_USAGE_RESTRICTION          = 11
%X509_ALTERNATE_NAME                 = 12
%X509_BASIC_CONSTRAINTS              = 13
%X509_KEY_USAGE                      = 14
%X509_BASIC_CONSTRAINTS2             = 15
%X509_CERT_POLICIES                  = 16

'//+-------------------------------------------------------------------------
'//  Additional predefined data structures that can be encoded / decoded.
'//--------------------------------------------------------------------------
'#define PKCS_UTC_TIME                       ((LPCSTR) 17)
'#define PKCS_TIME_REQUEST                   ((LPCSTR) 18)
'#define RSA_CSP_PUBLICKEYBLOB               ((LPCSTR) 19)
'#define X509_UNICODE_NAME                   ((LPCSTR) 20)

'#define X509_KEYGEN_REQUEST_TO_BE_SIGNED    ((LPCSTR) 21)
'#define PKCS_ATTRIBUTE                      ((LPCSTR) 22)
'#define PKCS_CONTENT_INFO_SEQUENCE_OF_ANY   ((LPCSTR) 23)

%PKCS_UTC_TIME                       = 17
%PKCS_TIME_REQUEST                   = 18
%RSA_CSP_PUBLICKEYBLOB               = 19
%X509_UNICODE_NAME                   = 20

%X509_KEYGEN_REQUEST_TO_BE_SIGNED    = 21
%PKCS_ATTRIBUTE                      = 22
%PKCS_CONTENT_INFO_SEQUENCE_OF_ANY   = 23

'//+-------------------------------------------------------------------------
'//  Predefined primitive data structures that can be encoded / decoded.
'//--------------------------------------------------------------------------
'#define X509_UNICODE_NAME_VALUE             ((LPCSTR) 24)
'#define X509_ANY_STRING                     X509_NAME_VALUE
'#define X509_UNICODE_ANY_STRING             X509_UNICODE_NAME_VALUE
'#define X509_OCTET_STRING                   ((LPCSTR) 25)
'#define X509_BITS                           ((LPCSTR) 26)
'#define X509_INTEGER                        ((LPCSTR) 27)
'#define X509_MULTI_BYTE_INTEGER             ((LPCSTR) 28)
'#define X509_ENUMERATED                     ((LPCSTR) 29)
'#define X509_CHOICE_OF_TIME                 ((LPCSTR) 30)

%X509_UNICODE_NAME_VALUE             = 24
%X509_ANY_STRING                     = %X509_NAME_VALUE
%X509_UNICODE_ANY_STRING             = %X509_UNICODE_NAME_VALUE
%X509_OCTET_STRING                   = 25
%X509_BITS                           = 26
%X509_INTEGER                        = 27
%X509_MULTI_BYTE_INTEGER             = 28
%X509_ENUMERATED                     = 29
%X509_CHOICE_OF_TIME                 = 30

'//+-------------------------------------------------------------------------
'//  More predefined X509 certificate extension data structures that can be
'//  encoded / decoded.
'//--------------------------------------------------------------------------
'#define X509_AUTHORITY_KEY_ID2              ((LPCSTR) 31)
'#define X509_AUTHORITY_INFO_ACCESS          ((LPCSTR) 32)
'#define X509_CRL_REASON_CODE                X509_ENUMERATED
'#define PKCS_CONTENT_INFO                   ((LPCSTR) 33)
'#define X509_SEQUENCE_OF_ANY                ((LPCSTR) 34)
'#define X509_CRL_DIST_POINTS                ((LPCSTR) 35)
'#define X509_ENHANCED_KEY_USAGE             ((LPCSTR) 36)
'#define PKCS_CTL                            ((LPCSTR) 37)

'#define X509_MULTI_BYTE_UINT                ((LPCSTR) 38)
'#define X509_DSS_PUBLICKEY                  X509_MULTI_BYTE_UINT
'#define X509_DSS_PARAMETERS                 ((LPCSTR) 39)
'#define X509_DSS_SIGNATURE                  ((LPCSTR) 40)
'#define PKCS_RC2_CBC_PARAMETERS             ((LPCSTR) 41)
'#define PKCS_SMIME_CAPABILITIES             ((LPCSTR) 42)

%X509_AUTHORITY_KEY_ID2              = 31
%X509_AUTHORITY_INFO_ACCESS          = 32
%X509_CRL_REASON_CODE                = %X509_ENUMERATED
%PKCS_CONTENT_INFO                   = 33
%X509_SEQUENCE_OF_ANY                = 34
%X509_CRL_DIST_POINTS                = 35
%X509_ENHANCED_KEY_USAGE             = 36
%PKCS_CTL                            = 37

%X509_MULTI_BYTE_UINT                = 38
%X509_DSS_PUBLICKEY                  = %X509_MULTI_BYTE_UINT
%X509_DSS_PARAMETERS                 = 39
%X509_DSS_SIGNATURE                  = 40
%PKCS_RC2_CBC_PARAMETERS             = 41
%PKCS_SMIME_CAPABILITIES             = 42

'// Qualified Certificate Statements Extension uses the same encode/decode
'// function as PKCS_SMIME_CAPABILITIES. Its data structures are identical
'// except for the names of the fields.
'#define X509_QC_STATEMENTS_EXT              ((LPCSTR) 42)
%X509_QC_STATEMENTS_EXT              = 42   ' ((LPCSTR) 42)

'//+-------------------------------------------------------------------------
'//  data structures for private keys
'//--------------------------------------------------------------------------
'#define PKCS_RSA_PRIVATE_KEY                ((LPCSTR) 43)
'#define PKCS_PRIVATE_KEY_INFO               ((LPCSTR) 44)
'#define PKCS_ENCRYPTED_PRIVATE_KEY_INFO     ((LPCSTR) 45)

%PKCS_RSA_PRIVATE_KEY                = 43
%PKCS_PRIVATE_KEY_INFO               = 44
%PKCS_ENCRYPTED_PRIVATE_KEY_INFO     = 45

'//+-------------------------------------------------------------------------
'//  certificate policy qualifier
'//--------------------------------------------------------------------------
'#define X509_PKIX_POLICY_QUALIFIER_USERNOTICE ((LPCSTR) 46)
%X509_PKIX_POLICY_QUALIFIER_USERNOTICE = 46

'//+-------------------------------------------------------------------------
'//  Diffie-Hellman Key Exchange
'//--------------------------------------------------------------------------
'#define X509_DH_PUBLICKEY                   X509_MULTI_BYTE_UINT
'#define X509_DH_PARAMETERS                  ((LPCSTR) 47)
'#define PKCS_ATTRIBUTES                     ((LPCSTR) 48)
'#define PKCS_SORTED_CTL                     ((LPCSTR) 49)

%X509_DH_PUBLICKEY                   = %X509_MULTI_BYTE_UINT
%X509_DH_PARAMETERS                  = 47
%PKCS_ATTRIBUTES                     = 48
%PKCS_SORTED_CTL                     = 49

'//+-------------------------------------------------------------------------
'//  ECC Signature
'//--------------------------------------------------------------------------
'// Uses the same encode/decode function as X509_DH_PARAMETERS. Its data
'// structure is identical except for the names of the fields.
'#define X509_ECC_SIGNATURE                  ((LPCSTR) 47)
%X509_ECC_SIGNATURE                  = 47

'//+-------------------------------------------------------------------------
'//  X942 Diffie-Hellman
'//--------------------------------------------------------------------------
'#define X942_DH_PARAMETERS                  ((LPCSTR) 50)
%X942_DH_PARAMETERS                  = 50

'//+-------------------------------------------------------------------------
'//  The following is the same as X509_BITS, except before encoding,
'//  the bit length is decremented to exclude trailing zero bits.
'//--------------------------------------------------------------------------
'#define X509_BITS_WITHOUT_TRAILING_ZEROES   ((LPCSTR) 51)
%X509_BITS_WITHOUT_TRAILING_ZEROES   = 51

'//+-------------------------------------------------------------------------
'//  X942 Diffie-Hellman Other Info
'//--------------------------------------------------------------------------
'#define X942_OTHER_INFO                     ((LPCSTR) 52)

'#define X509_CERT_PAIR                      ((LPCSTR) 53)
'#define X509_ISSUING_DIST_POINT             ((LPCSTR) 54)
'#define X509_NAME_CONSTRAINTS               ((LPCSTR) 55)
'#define X509_POLICY_MAPPINGS                ((LPCSTR) 56)
'#define X509_POLICY_CONSTRAINTS             ((LPCSTR) 57)
'#define X509_CROSS_CERT_DIST_POINTS         ((LPCSTR) 58)

%X942_OTHER_INFO                     = 52

%X509_CERT_PAIR                      = 53
%X509_ISSUING_DIST_POINT             = 54
%X509_NAME_CONSTRAINTS               = 55
%X509_POLICY_MAPPINGS                = 56
%X509_POLICY_CONSTRAINTS             = 57
%X509_CROSS_CERT_DIST_POINTS         = 58

'//+-------------------------------------------------------------------------
'//  Certificate Management Messages over CMS (CMC) Data Structures
'//--------------------------------------------------------------------------
'#define CMC_DATA                            ((LPCSTR) 59)
'#define CMC_RESPONSE                        ((LPCSTR) 60)
'#define CMC_STATUS                          ((LPCSTR) 61)
'#define CMC_ADD_EXTENSIONS                  ((LPCSTR) 62)
'#define CMC_ADD_ATTRIBUTES                  ((LPCSTR) 63)

%CMC_DATA                            = 59
%CMC_RESPONSE                        = 60
%CMC_STATUS                          = 61
%CMC_ADD_EXTENSIONS                  = 62
%CMC_ADD_ATTRIBUTES                  = 63

'//+-------------------------------------------------------------------------
'//  Certificate Template
'//--------------------------------------------------------------------------
'#define X509_CERTIFICATE_TEMPLATE           ((LPCSTR) 64)
%X509_CERTIFICATE_TEMPLATE           = 64

'//+-------------------------------------------------------------------------
'//  Online Certificate Status Protocol (OCSP) Data Structures
'//--------------------------------------------------------------------------
'#define OCSP_SIGNED_REQUEST                 ((LPCSTR) 65)
'#define OCSP_REQUEST                        ((LPCSTR) 66)
'#define OCSP_RESPONSE                       ((LPCSTR) 67)
'#define OCSP_BASIC_SIGNED_RESPONSE          ((LPCSTR) 68)
'#define OCSP_BASIC_RESPONSE                 ((LPCSTR) 69)
%OCSP_SIGNED_REQUEST                 = 65
%OCSP_REQUEST                        = 66
%OCSP_RESPONSE                       = 67
%OCSP_BASIC_SIGNED_RESPONSE          = 68
%OCSP_BASIC_RESPONSE                 = 69

'//+-------------------------------------------------------------------------
'//  Logotype and Biometric Extensions
'//--------------------------------------------------------------------------
'#define X509_LOGOTYPE_EXT                   ((LPCSTR) 70)
'#define X509_BIOMETRIC_EXT                  ((LPCSTR) 71)

'#define CNG_RSA_PUBLIC_KEY_BLOB             ((LPCSTR) 72)
'#define X509_OBJECT_IDENTIFIER              ((LPCSTR) 73)
'#define X509_ALGORITHM_IDENTIFIER           ((LPCSTR) 74)
'#define PKCS_RSA_SSA_PSS_PARAMETERS         ((LPCSTR) 75)
'#define PKCS_RSAES_OAEP_PARAMETERS          ((LPCSTR) 76)

'#define ECC_CMS_SHARED_INFO                 ((LPCSTR) 77)

'//+-------------------------------------------------------------------------
'//  TIMESTAMP
'//--------------------------------------------------------------------------
'#define TIMESTAMP_REQUEST                  ((LPCSTR) 78)
'#define TIMESTAMP_RESPONSE                 ((LPCSTR) 79)
'#define TIMESTAMP_INFO                     ((LPCSTR) 80)

'//+-------------------------------------------------------------------------
'//  CertificateBundle
'//--------------------------------------------------------------------------
'#define X509_CERT_BUNDLE                   ((LPCSTR) 81)

%X509_LOGOTYPE_EXT                   = 70
%X509_BIOMETRIC_EXT                  = 71

%CNG_RSA_PUBLIC_KEY_BLOB             = 72
%X509_OBJECT_IDENTIFIER              = 73
%X509_ALGORITHM_IDENTIFIER           = 74
%PKCS_RSA_SSA_PSS_PARAMETERS         = 75
%PKCS_RSAES_OAEP_PARAMETERS          = 76

%ECC_CMS_SHARED_INFO                 = 77

%TIMESTAMP_REQUEST                   = 78
%TIMESTAMP_RESPONSE                  = 79
%TIMESTAMP_INFO                      = 80

%X509_CERT_BUNDLE                    = 81

'//+-------------------------------------------------------------------------
'//  Predefined PKCS #7 data structures that can be encoded / decoded.
'//--------------------------------------------------------------------------
'#define PKCS7_SIGNER_INFO                   ((LPCSTR) 500)
%PKCS7_SIGNER_INFO                   = 500

'//+-------------------------------------------------------------------------
'//  Predefined PKCS #7 data structures that can be encoded / decoded.
'//--------------------------------------------------------------------------
'#define CMS_SIGNER_INFO                     ((LPCSTR) 501)
%CMS_SIGNER_INFO                     = 501

'//+-------------------------------------------------------------------------
'//  Predefined Software Publishing Credential (SPC)  data structures that
'//  can be encoded / decoded.
'//
'//  Predefined values: 2000 .. 2999
'//
'//  See spc.h for value and data structure definitions.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Extension Object Identifiers
'//--------------------------------------------------------------------------
$szOID_AUTHORITY_KEY_IDENTIFIER  = "2.5.29.1"
$szOID_KEY_ATTRIBUTES            = "2.5.29.2"
$szOID_CERT_POLICIES_95          = "2.5.29.3"
$szOID_KEY_USAGE_RESTRICTION     = "2.5.29.4"
$szOID_SUBJECT_ALT_NAME          = "2.5.29.7"
$szOID_ISSUER_ALT_NAME           = "2.5.29.8"
$szOID_BASIC_CONSTRAINTS         = "2.5.29.10"
$szOID_KEY_USAGE                 = "2.5.29.15"
$szOID_PRIVATEKEY_USAGE_PERIOD   = "2.5.29.16"
$szOID_BASIC_CONSTRAINTS2        = "2.5.29.19"

$szOID_CERT_POLICIES             = "2.5.29.32"
$szOID_ANY_CERT_POLICY           = "2.5.29.32.0"
$szOID_INHIBIT_ANY_POLICY        = "2.5.29.54"

$szOID_AUTHORITY_KEY_IDENTIFIER2 = "2.5.29.35"
$szOID_SUBJECT_KEY_IDENTIFIER    = "2.5.29.14"
$szOID_SUBJECT_ALT_NAME2         = "2.5.29.17"
$szOID_ISSUER_ALT_NAME2          = "2.5.29.18"
$szOID_CRL_REASON_CODE           = "2.5.29.21"
$szOID_REASON_CODE_HOLD          = "2.5.29.23"
$szOID_CRL_DIST_POINTS           = "2.5.29.31"
$szOID_ENHANCED_KEY_USAGE        = "2.5.29.37"

$szOID_ANY_ENHANCED_KEY_USAGE    = "2.5.29.37.0"

'// szOID_CRL_NUMBER -- Base CRLs only.  Monotonically increasing sequence
'// number for each CRL issued by a CA.
$szOID_CRL_NUMBER                = "2.5.29.20"
'// szOID_DELTA_CRL_INDICATOR -- Delta CRLs only.  Marked critical.
'// Contains the minimum base CRL Number that can be used with a delta CRL.
$szOID_DELTA_CRL_INDICATOR       = "2.5.29.27"
$szOID_ISSUING_DIST_POINT        = "2.5.29.28"
'// szOID_FRESHEST_CRL -- Base CRLs only.  Formatted identically to a CDP
'// extension that holds URLs to fetch the delta CRL.
$szOID_FRESHEST_CRL              = "2.5.29.46"
$szOID_NAME_CONSTRAINTS          = "2.5.29.30"

'// Note on 1/1/2000 szOID_POLICY_MAPPINGS was changed from = "2.5.29.5"
$szOID_POLICY_MAPPINGS           = "2.5.29.33"
$szOID_LEGACY_POLICY_MAPPINGS    = "2.5.29.5"
$szOID_POLICY_CONSTRAINTS        = "2.5.29.36"


'// Microsoft PKCS10 Attributes
$szOID_RENEWAL_CERTIFICATE           = "1.3.6.1.4.1.311.13.1"
$szOID_ENROLLMENT_NAME_VALUE_PAIR    = "1.3.6.1.4.1.311.13.2.1"
$szOID_ENROLLMENT_CSP_PROVIDER       = "1.3.6.1.4.1.311.13.2.2"
$szOID_OS_VERSION                    = "1.3.6.1.4.1.311.13.2.3"

'//
'// Extension contain certificate type
$szOID_ENROLLMENT_AGENT          = "1.3.6.1.4.1.311.20.2.1"

'// Internet Public Key Infrastructure (PKIX)
$szOID_PKIX                      = "1.3.6.1.5.5.7"
$szOID_PKIX_PE                   = "1.3.6.1.5.5.7.1"
$szOID_AUTHORITY_INFO_ACCESS     = "1.3.6.1.5.5.7.1.1"
$szOID_SUBJECT_INFO_ACCESS       = "1.3.6.1.5.5.7.1.11"
$szOID_BIOMETRIC_EXT             = "1.3.6.1.5.5.7.1.2"
$szOID_QC_STATEMENTS_EXT         = "1.3.6.1.5.5.7.1.3"
$szOID_LOGOTYPE_EXT              = "1.3.6.1.5.5.7.1.12"

'// Microsoft extensions or attributes
$szOID_CERT_EXTENSIONS           = "1.3.6.1.4.1.311.2.1.14"
$szOID_NEXT_UPDATE_LOCATION      = "1.3.6.1.4.1.311.10.2"
$szOID_REMOVE_CERTIFICATE        = "1.3.6.1.4.1.311.10.8.1"
$szOID_CROSS_CERT_DIST_POINTS    = "1.3.6.1.4.1.311.10.9.1"

'//  Microsoft PKCS #7 ContentType Object Identifiers
$szOID_CTL                       = "1.3.6.1.4.1.311.10.1"

'//  Microsoft Sorted CTL Extension Object Identifier
$szOID_SORTED_CTL                = "1.3.6.1.4.1.311.10.1.1"

'// serialized serial numbers for PRS
'#ifndef szOID_SERIALIZED
$szOID_SERIALIZED                = "1.3.6.1.4.1.311.10.3.3.1"
'#endif

'// serialized serial numbers for PRS
'#ifndef szOID_SERIALIZED
$szOID_SERIALIZED                = "1.3.6.1.4.1.311.10.3.3.1"
'#endif

'// UPN principal name in SubjectAltName
'#ifndef szOID_NT_PRINCIPAL_NAME
$szOID_NT_PRINCIPAL_NAME         = "1.3.6.1.4.1.311.20.2.3"
'#endif

'// Windows product update unauthenticated attribute
'#ifndef szOID_PRODUCT_UPDATE
$szOID_PRODUCT_UPDATE            = "1.3.6.1.4.1.311.31.1"
'#endif

'// CryptUI
$szOID_ANY_APPLICATION_POLICY    = "1.3.6.1.4.1.311.10.12.1"

'//+-------------------------------------------------------------------------
'//  Object Identifiers for use with Auto Enrollment
'//--------------------------------------------------------------------------
$szOID_AUTO_ENROLL_CTL_USAGE     = "1.3.6.1.4.1.311.20.1"

'// Extension contain certificate type
$szOID_ENROLL_CERTTYPE_EXTENSION = "1.3.6.1.4.1.311.20.2"


$szOID_CERT_MANIFOLD             = "1.3.6.1.4.1.311.20.3"

'//+-------------------------------------------------------------------------
'//  Object Identifiers for use with the MS Certificate Server
'//--------------------------------------------------------------------------
'#ifndef szOID_CERTSRV_CA_VERSION
$szOID_CERTSRV_CA_VERSION        = "1.3.6.1.4.1.311.21.1"
'#endif


'// szOID_CERTSRV_PREVIOUS_CERT_HASH -- Contains the sha1 hash of the previous
'// version of the CA certificate.
$szOID_CERTSRV_PREVIOUS_CERT_HASH    = "1.3.6.1.4.1.311.21.2"

'// szOID_CRL_VIRTUAL_BASE -- Delta CRLs only.  Contains the base CRL Number
'// of the corresponding base CRL.
$szOID_CRL_VIRTUAL_BASE          = "1.3.6.1.4.1.311.21.3"

'// szOID_CRL_NEXT_PUBLISH -- Contains the time when the next CRL is expected
'// to be published.  This may be sooner than the CRL's NextUpdate field.
$szOID_CRL_NEXT_PUBLISH          = "1.3.6.1.4.1.311.21.4"

'// Enhanced Key Usage for CA encryption certificate
$szOID_KP_CA_EXCHANGE            = "1.3.6.1.4.1.311.21.5"

'// Enhanced Key Usage for key recovery agent certificate
$szOID_KP_KEY_RECOVERY_AGENT     = "1.3.6.1.4.1.311.21.6"

'// Certificate template extension (v2)
$szOID_CERTIFICATE_TEMPLATE      = "1.3.6.1.4.1.311.21.7"

'// The root oid for all enterprise specific oids
$szOID_ENTERPRISE_OID_ROOT       = "1.3.6.1.4.1.311.21.8"

'// Dummy signing Subject RDN
$szOID_RDN_DUMMY_SIGNER          = "1.3.6.1.4.1.311.21.9"

'// Application Policies extension -- same encoding as szOID_CERT_POLICIES
$szOID_APPLICATION_CERT_POLICIES     = "1.3.6.1.4.1.311.21.10"

'// Application Policy Mappings -- same encoding as szOID_POLICY_MAPPINGS
$szOID_APPLICATION_POLICY_MAPPINGS   = "1.3.6.1.4.1.311.21.11"

'// Application Policy Constraints -- same encoding as szOID_POLICY_CONSTRAINTS
$szOID_APPLICATION_POLICY_CONSTRAINTS    = "1.3.6.1.4.1.311.21.12"

$szOID_ARCHIVED_KEY_ATTR                = "1.3.6.1.4.1.311.21.13"
$szOID_CRL_SELF_CDP                     = "1.3.6.1.4.1.311.21.14"


'// Requires all certificates below the root to have a non-empty intersecting
'// issuance certificate policy usage.
$szOID_REQUIRE_CERT_CHAIN_POLICY        = "1.3.6.1.4.1.311.21.15"
$szOID_ARCHIVED_KEY_CERT_HASH           = "1.3.6.1.4.1.311.21.16"
$szOID_ISSUED_CERT_HASH                 = "1.3.6.1.4.1.311.21.17"

'// Enhanced key usage for DS email replication
$szOID_DS_EMAIL_REPLICATION             = "1.3.6.1.4.1.311.21.19"

$szOID_REQUEST_CLIENT_INFO              = "1.3.6.1.4.1.311.21.20"
$szOID_ENCRYPTED_KEY_HASH               = "1.3.6.1.4.1.311.21.21"
$szOID_CERTSRV_CROSSCA_VERSION          = "1.3.6.1.4.1.311.21.22"

'//+-------------------------------------------------------------------------
'//  Object Identifiers for use with the MS Directory Service
'//--------------------------------------------------------------------------
$szOID_NTDS_REPLICATION      = "1.3.6.1.4.1.311.25.1"


'//+-------------------------------------------------------------------------
'//  Extension Object Identifiers (currently not implemented)
'//--------------------------------------------------------------------------
$szOID_SUBJECT_DIR_ATTRS         = "2.5.29.9"

'//+-------------------------------------------------------------------------
'//  Enhanced Key Usage (Purpose) Object Identifiers
'//--------------------------------------------------------------------------
$szOID_PKIX_KP                   = "1.3.6.1.5.5.7.3"

'// Consistent key usage bits: DIGITAL_SIGNATURE, KEY_ENCIPHERMENT
'// or KEY_AGREEMENT
$szOID_PKIX_KP_SERVER_AUTH       = "1.3.6.1.5.5.7.3.1"

'// Consistent key usage bits: DIGITAL_SIGNATURE
$szOID_PKIX_KP_CLIENT_AUTH       = "1.3.6.1.5.5.7.3.2"

'// Consistent key usage bits: DIGITAL_SIGNATURE
$szOID_PKIX_KP_CODE_SIGNING      = "1.3.6.1.5.5.7.3.3"

'// Consistent key usage bits: DIGITAL_SIGNATURE, NON_REPUDIATION and/or
'// (KEY_ENCIPHERMENT or KEY_AGREEMENT)
$szOID_PKIX_KP_EMAIL_PROTECTION  = "1.3.6.1.5.5.7.3.4"

'// Consistent key usage bits: DIGITAL_SIGNATURE and/or
'// (KEY_ENCIPHERMENT or KEY_AGREEMENT)
$szOID_PKIX_KP_IPSEC_END_SYSTEM  = "1.3.6.1.5.5.7.3.5"

'// Consistent key usage bits: DIGITAL_SIGNATURE and/or
'// (KEY_ENCIPHERMENT or KEY_AGREEMENT)
$szOID_PKIX_KP_IPSEC_TUNNEL      = "1.3.6.1.5.5.7.3.6"

'// Consistent key usage bits: DIGITAL_SIGNATURE and/or
'// (KEY_ENCIPHERMENT or KEY_AGREEMENT)
$szOID_PKIX_KP_IPSEC_USER        = "1.3.6.1.5.5.7.3.7"

'// Consistent key usage bits: DIGITAL_SIGNATURE or NON_REPUDIATION
$szOID_PKIX_KP_TIMESTAMP_SIGNING = "1.3.6.1.5.5.7.3.8"

'// OCSP response signer
$szOID_PKIX_KP_OCSP_SIGNING      = "1.3.6.1.5.5.7.3.9"

'// Following extension is present to indicate no revocation checking
'// for the OCSP signer certificate
$szOID_PKIX_OCSP_NOCHECK         = "1.3.6.1.5.5.7.48.1.5"

'// OCSP Nonce
$szOID_PKIX_OCSP_NONCE           = "1.3.6.1.5.5.7.48.1.2"

'// IKE (Internet Key Exchange) Intermediate KP for an IPsec end entity.
'// Defined in draft-ietf-ipsec-pki-req-04.txt, December 14, 1999.
$szOID_IPSEC_KP_IKE_INTERMEDIATE = "1.3.6.1.5.5.8.2.2"

'// iso (1) org (3) dod (6) internet (1) security (5) kerberosv5 (2) pkinit (3) 5
$szOID_PKINIT_KP_KDC             = "1.3.6.1.5.2.3.5"

'//+-------------------------------------------------------------------------
'//  Microsoft Enhanced Key Usage (Purpose) Object Identifiers
'//+-------------------------------------------------------------------------

'//  Signer of CTLs
$szOID_KP_CTL_USAGE_SIGNING      = "1.3.6.1.4.1.311.10.3.1"

'//  Signer of TimeStamps
$szOID_KP_TIME_STAMP_SIGNING     = "1.3.6.1.4.1.311.10.3.2"

'#ifndef szOID_SERVER_GATED_CRYPTO
$szOID_SERVER_GATED_CRYPTO       = "1.3.6.1.4.1.311.10.3.3"
'#endif

'#ifndef szOID_SGC_NETSCAPE
$szOID_SGC_NETSCAPE              = "2.16.840.1.113730.4.1"
'#endif

$szOID_KP_EFS                    = "1.3.6.1.4.1.311.10.3.4"
$szOID_EFS_RECOVERY              = "1.3.6.1.4.1.311.10.3.4.1"

'// Can use Windows Hardware Compatible (WHQL)
$szOID_WHQL_CRYPTO               = "1.3.6.1.4.1.311.10.3.5"

'// Signed by the NT5 build lab
$szOID_NT5_CRYPTO                = "1.3.6.1.4.1.311.10.3.6"

'// Signed by and OEM of WHQL
$szOID_OEM_WHQL_CRYPTO           = "1.3.6.1.4.1.311.10.3.7"

'// Signed by the Embedded NT
$szOID_EMBEDDED_NT_CRYPTO        = "1.3.6.1.4.1.311.10.3.8"

'// Signer of a CTL containing trusted roots
$szOID_ROOT_LIST_SIGNER      = "1.3.6.1.4.1.311.10.3.9"

'// Can sign cross-cert and subordinate CA requests with qualified
'// subordination (name constraints, policy mapping, etc.)
$szOID_KP_QUALIFIED_SUBORDINATION    = "1.3.6.1.4.1.311.10.3.10"

'// Can be used to encrypt/recover escrowed keys
$szOID_KP_KEY_RECOVERY               = "1.3.6.1.4.1.311.10.3.11"

'// Signer of documents
$szOID_KP_DOCUMENT_SIGNING           = "1.3.6.1.4.1.311.10.3.12"

'// The default WinVerifyTrust Authenticode policy is to treat all time stamped
'// signatures as being valid forever. This OID limits the valid lifetime of the
'// signature to the lifetime of the certificate. This allows timestamped
'// signatures to expire. Normally this OID will be used in conjunction with
'// szOID_PKIX_KP_CODE_SIGNING to indicate new time stamp semantics should be
'// used. Support for this OID was added in WXP.
$szOID_KP_LIFETIME_SIGNING           = "1.3.6.1.4.1.311.10.3.13"

$szOID_KP_MOBILE_DEVICE_SOFTWARE     = "1.3.6.1.4.1.311.10.3.14"

$szOID_KP_SMART_DISPLAY              = "1.3.6.1.4.1.311.10.3.15"

$szOID_KP_CSP_SIGNATURE              = "1.3.6.1.4.1.311.10.3.16"

'#ifndef szOID_DRM
$szOID_DRM                           = "1.3.6.1.4.1.311.10.5.1"
'#endif

'// Microsoft DRM EKU
'#ifndef szOID_DRM_INDIVIDUALIZATION
$szOID_DRM_INDIVIDUALIZATION = "1.3.6.1.4.1.311.10.5.2"
'#endif

'#ifndef szOID_LICENSES
$szOID_LICENSES                  = "1.3.6.1.4.1.311.10.6.1"
'#endif

'#ifndef szOID_LICENSE_SERVER
$szOID_LICENSE_SERVER            = "1.3.6.1.4.1.311.10.6.2"
'#endif

'#ifndef szOID_KP_SMARTCARD_LOGON
$szOID_KP_SMARTCARD_LOGON        = "1.3.6.1.4.1.311.20.2.2"
'#endif

$szOID_KP_KERNEL_MODE_CODE_SIGNING = "1.3.6.1.4.1.311.61.1.1"

'// Signer of CRL
$szOID_REVOKED_LIST_SIGNER       = "1.3.6.1.4.1.311.10.3.19"

'//+-------------------------------------------------------------------------
'//  Microsoft Attribute Object Identifiers
'//+-------------------------------------------------------------------------
$szOID_YESNO_TRUST_ATTR          = "1.3.6.1.4.1.311.10.4.1"

'//+-------------------------------------------------------------------------
'//  Qualifiers that may be part of the szOID_CERT_POLICIES and
'//  szOID_CERT_POLICIES95 extensions
'//+-------------------------------------------------------------------------
$szOID_PKIX_POLICY_QUALIFIER_CPS               = "1.3.6.1.5.5.7.2.1"
$szOID_PKIX_POLICY_QUALIFIER_USERNOTICE        = "1.3.6.1.5.5.7.2.2"

$szOID_ROOT_PROGRAM_FLAGS                      = "1.3.6.1.4.1.311.60.1.1"

'//+-------------------------------------------------------------------------
'//  Root program qualifier flags, used in pbData field of
'//  CERT_POLICY_QUALIFIER_INFO structure.
'//+-------------------------------------------------------------------------

'// Validation of the Organization (O) field in the subject name meets
'// Root Program Requirements for display.
%CERT_ROOT_PROGRAM_FLAG_ORG          = &H80

'// Validation of the Locale (L), State (S), and Country (C) fields in
'// the subject name meets Program Requirements for display.
%CERT_ROOT_PROGRAM_FLAG_LSC          = &H40

'// Subject logotype
%CERT_ROOT_PROGRAM_FLAG_SUBJECT_LOGO = &H20

'// Validation of the OrganizationalUnit (OU) field in the subject name
'// meets Root Program Requirements for display.
%CERT_ROOT_PROGRAM_FLAG_OU           = &H10

'// Validation of the address field in the subject name meets Root
'// Program Requirements for display.
%CERT_ROOT_PROGRAM_FLAG_ADDRESS      = &H08

'// OID for old qualifer
$szOID_CERT_POLICIES_95_QUALIFIER1             = "2.16.840.1.113733.1.7.1.1"

'//+-------------------------------------------------------------------------
'//  X509_CERT
'//
'//  The "to be signed" encoded content plus its signature. The ToBeSigned
'//  content is the CryptEncodeObject() output for one of the following:
'//  X509_CERT_TO_BE_SIGNED, X509_CERT_CRL_TO_BE_SIGNED or
'//  X509_CERT_REQUEST_TO_BE_SIGNED.
'//
'//  pvStructInfo points to CERT_SIGNED_CONTENT_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CERT_TO_BE_SIGNED
'//
'//  pvStructInfo points to CERT_INFO.
'//
'//  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
'//  signature (output of a X509_CERT CryptEncodeObject()).
'//
'//  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CERT_CRL_TO_BE_SIGNED
'//
'//  pvStructInfo points to CRL_INFO.
'//
'//  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
'//  signature (output of a X509_CERT CryptEncodeObject()).
'//
'//  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CERT_REQUEST_TO_BE_SIGNED
'//
'//  pvStructInfo points to CERT_REQUEST_INFO.
'//
'//  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
'//  signature (output of a X509_CERT CryptEncodeObject()).
'//
'//  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_EXTENSIONS
'//  szOID_CERT_EXTENSIONS
'//
'//  pvStructInfo points to following CERT_EXTENSIONS.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CERT_EXTENSIONS DWORD
   cExtension  AS DWORD                ' DWORD
   rgExtension AS CERT_EXTENSION PTR   ' PCERT_EXTENSION
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_NAME_VALUE
'//  X509_ANY_STRING
'//
'//  pvStructInfo points to CERT_NAME_VALUE.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_UNICODE_NAME_VALUE
'//  X509_UNICODE_ANY_STRING
'//
'//  pvStructInfo points to CERT_NAME_VALUE.
'//
'//  The name values are unicode strings.
'//
'//  For CryptEncodeObject:
'//    Value.pbData points to the unicode string.
'//    If Value.cbData = 0, then, the unicode string is NULL terminated.
'//    Otherwise, Value.cbData is the unicode string byte count. The byte count
'//    is twice the character count.
'//
'//    If the unicode string contains an invalid character for the specified
'//    dwValueType, then, *pcbEncoded is updated with the unicode character
'//    index of the first invalid character. LastError is set to:
'//    CRYPT_E_INVALID_NUMERIC_STRING, CRYPT_E_INVALID_PRINTABLE_STRING or
'//    CRYPT_E_INVALID_IA5_STRING.
'//
'//    To disable the above check, either set CERT_RDN_DISABLE_CHECK_TYPE_FLAG
'//    in dwValueType or set CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG
'//    in dwFlags passed to CryptEncodeObjectEx.
'//
'//    The unicode string is converted before being encoded according to
'//    the specified dwValueType. If dwValueType is set to 0, LastError
'//    is set to E_INVALIDARG.
'//
'//    If the dwValueType isn't one of the character strings (its a
'//    CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING), then, CryptEncodeObject
'//    will return FALSE with LastError set to CRYPT_E_NOT_CHAR_STRING.
'//
'//  For CryptDecodeObject:
'//    Value.pbData points to a NULL terminated unicode string. Value.cbData
'//    contains the byte count of the unicode string excluding the NULL
'//    terminator. dwValueType contains the type used in the encoded object.
'//    Its not forced to CERT_RDN_UNICODE_STRING. The encoded value is
'//    converted to the unicode string according to the dwValueType.
'//
'//    If the encoded object isn't one of the character string types, then,
'//    CryptDecodeObject will return FALSE with LastError set to
'//    CRYPT_E_NOT_CHAR_STRING. For a non character string, decode using
'//    X509_NAME_VALUE or X509_ANY_STRING.
'//
'//    By default, CERT_RDN_T61_STRING values are initially decoded
'//    as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'//    Set CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG in dwFlags
'//    passed to either CryptDecodeObject or CryptDecodeObjectEx to
'//    skip the initial attempt to decode as UTF8.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_NAME
'//
'//  pvStructInfo points to CERT_NAME_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_UNICODE_NAME
'//
'//  pvStructInfo points to CERT_NAME_INFO.
'//
'//  The RDN attribute values are unicode strings except for the dwValueTypes of
'//  CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING. These dwValueTypes are
'//  the same as for a X509_NAME. Their values aren't converted to/from unicode.
'//
'//  For CryptEncodeObject:
'//    Value.pbData points to the unicode string.
'//    If Value.cbData = 0, then, the unicode string is NULL terminated.
'//    Otherwise, Value.cbData is the unicode string byte count. The byte count
'//    is twice the character count.
'//
'//    If dwValueType = 0 (CERT_RDN_ANY_TYPE), the pszObjId is used to find
'//    an acceptable dwValueType. If the unicode string contains an
'//    invalid character for the found or specified dwValueType, then,
'//    *pcbEncoded is updated with the error location of the invalid character.
'//    See below for details. LastError is set to:
'//    CRYPT_E_INVALID_NUMERIC_STRING, CRYPT_E_INVALID_PRINTABLE_STRING or
'//    CRYPT_E_INVALID_IA5_STRING.
'//
'//    To disable the above check, either set CERT_RDN_DISABLE_CHECK_TYPE_FLAG
'//    in dwValueType or set CRYPT_UNICODE_NAME_ENCODE_DISABLE_CHECK_TYPE_FLAG
'//    in dwFlags passed to CryptEncodeObjectEx.
'//
'//    Set CERT_RDN_UNICODE_STRING in dwValueType or set
'//    CRYPT_UNICODE_NAME_ENCODE_ENABLE_T61_UNICODE_FLAG in dwFlags passed
'//    to CryptEncodeObjectEx to select CERT_RDN_T61_STRING instead of
'//    CERT_RDN_UNICODE_STRING if all the unicode characters are <= 0xFF.
'//
'//    Set CERT_RDN_ENABLE_UTF8_UNICODE_STRING in dwValueType or set
'//    CRYPT_UNICODE_NAME_ENCODE_ENABLE_UTF8_UNICODE_FLAG in dwFlags passed
'//    to CryptEncodeObjectEx to select CERT_RDN_UTF8_STRING instead of
'//    CERT_RDN_UNICODE_STRING.
'//
'//    The unicode string is converted before being encoded according to
'//    the specified or ObjId matching dwValueType.
'//
'//  For CryptDecodeObject:
'//    Value.pbData points to a NULL terminated unicode string. Value.cbData
'//    contains the byte count of the unicode string excluding the NULL
'//    terminator. dwValueType contains the type used in the encoded object.
'//    Its not forced to CERT_RDN_UNICODE_STRING. The encoded value is
'//    converted to the unicode string according to the dwValueType.
'//
'//    If the dwValueType of the encoded value isn't a character string
'//    type, then, it isn't converted to UNICODE. Use the
'//    IS_CERT_RDN_CHAR_STRING() macro on the dwValueType to check
'//    that Value.pbData points to a converted unicode string.
'//
'//    By default, CERT_RDN_T61_STRING values are initially decoded
'//    as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'//    Set CRYPT_UNICODE_NAME_DECODE_DISABLE_IE4_UTF8_FLAG in dwFlags
'//    passed to either CryptDecodeObject or CryptDecodeObjectEx to
'//    skip the initial attempt to decode as UTF8.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Unicode Name Value Error Location Definitions
'//
'//  Error location is returned in *pcbEncoded by
'//  CryptEncodeObject(X509_UNICODE_NAME)
'//
'//  Error location consists of:
'//    RDN_INDEX     - 10 bits << 22
'//    ATTR_INDEX    - 6 bits << 16
'//    VALUE_INDEX   - 16 bits (unicode character index)
'//--------------------------------------------------------------------------
%CERT_UNICODE_RDN_ERR_INDEX_MASK     = &H3FF???
%CERT_UNICODE_RDN_ERR_INDEX_SHIFT    = 22???
%CERT_UNICODE_ATTR_ERR_INDEX_MASK    = &H003F???
%CERT_UNICODE_ATTR_ERR_INDEX_SHIFT   = 16???
%CERT_UNICODE_VALUE_ERR_INDEX_MASK   = &H0000FFFF???
%CERT_UNICODE_VALUE_ERR_INDEX_SHIFT  = 0???

'#define GET_CERT_UNICODE_RDN_ERR_INDEX(X)   \
'    ((X >> CERT_UNICODE_RDN_ERR_INDEX_SHIFT) & CERT_UNICODE_RDN_ERR_INDEX_MASK)
MACRO FUNCTION GET_CERT_UNICODE_RDN_ERR_INDEX(X)
   SHIFT RIGHT X, %CERT_UNICODE_RDN_ERR_INDEX_SHIFT
END MACRO = (X AND %CERT_UNICODE_RDN_ERR_INDEX_MASK)

'#define GET_CERT_UNICODE_ATTR_ERR_INDEX(X)  \
'    ((X >> CERT_UNICODE_ATTR_ERR_INDEX_SHIFT) & CERT_UNICODE_ATTR_ERR_INDEX_MASK)

MACRO FUNCTION GET_CERT_UNICODE_ATTR_ERR_INDEX(X)
   SHIDT RIGHT X, %CERT_UNICODE_ATTR_ERR_INDEX_SHIFT
END MACRO = (X AND %CERT_UNICODE_ATTR_ERR_INDEX_MASK)

'#define GET_CERT_UNICODE_VALUE_ERR_INDEX(X) \
'    (X & CERT_UNICODE_VALUE_ERR_INDEX_MASK)

MACRO GET_CERT_UNICODE_VALUE_ERR_INDEX(X) = (X AND %CERT_UNICODE_VALUE_ERR_INDEX_MASK)

'//+-------------------------------------------------------------------------
'//  X509_PUBLIC_KEY_INFO
'//
'//  pvStructInfo points to CERT_PUBLIC_KEY_INFO.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'//  X509_AUTHORITY_KEY_ID
'//  szOID_AUTHORITY_KEY_IDENTIFIER
'//
'//  pvStructInfo points to following CERT_AUTHORITY_KEY_ID_INFO.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CERT_AUTHORITY_KEY_ID_INFO DWORD
   KeyId            AS CRYPT_DATA_BLOB
   CertIssuer       AS CERT_NAME_BLOB
   CertSerialNumber AS CRYPT_INTEGER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_KEY_ATTRIBUTES
'//  szOID_KEY_ATTRIBUTES
'//
'//  pvStructInfo points to following CERT_KEY_ATTRIBUTES_INFO.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_PRIVATE_KEY_VALIDITY DWORD
   NotBefore AS FILETIME
   NotAfter  AS FILETIME
END TYPE

' // Size = 24 bytes
TYPE CERT_KEY_ATTRIBUTES_INFO DWORD
   KeyId                  AS CRYPT_DATA_BLOB
   IntendedKeyUsage       AS CRYPT_BIT_BLOB
   pPrivateKeyUsagePeriod AS CERT_PRIVATE_KEY_VALIDITY PTR
END TYPE

'// Byte[0]
%CERT_DIGITAL_SIGNATURE_KEY_USAGE     = &H80?
%CERT_NON_REPUDIATION_KEY_USAGE       = &H40?
%CERT_KEY_ENCIPHERMENT_KEY_USAGE      = &H20?
%CERT_DATA_ENCIPHERMENT_KEY_USAGE     = &H10?
%CERT_KEY_AGREEMENT_KEY_USAGE         = &H08?
%CERT_KEY_CERT_SIGN_KEY_USAGE         = &H04?
%CERT_OFFLINE_CRL_SIGN_KEY_USAGE      = &H02?
%CERT_CRL_SIGN_KEY_USAGE              = &H02?
%CERT_ENCIPHER_ONLY_KEY_USAGE         = &H01?
'// Byte[1]
%CERT_DECIPHER_ONLY_KEY_USAGE         = &H80?

'//+-------------------------------------------------------------------------
'//  X509_KEY_USAGE_RESTRICTION
'//  szOID_KEY_USAGE_RESTRICTION
'//
'//  pvStructInfo points to following CERT_KEY_USAGE_RESTRICTION_INFO.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CERT_POLICY_ID DWORD
   cCertPolicyElementId     AS DWORD        ' DWORD
   rgpszCertPolicyElementId AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 20 bytes
TYPE CERT_KEY_USAGE_RESTRICTION_INFO DWORD
   cCertPolicyId      AS DWORD                ' DWORD
   rgCertPolicyId     AS CERT_POLICY_ID PTR   ' PCERT_POLICY_ID
   RestrictedKeyUsage AS CRYPT_BIT_BLOB       ' CRYPT_BIT_BLOB
END TYPE

'// See CERT_KEY_ATTRIBUTES_INFO for definition of the RestrictedKeyUsage bits

'//+-------------------------------------------------------------------------
'//  X509_ALTERNATE_NAME
'//  szOID_SUBJECT_ALT_NAME
'//  szOID_ISSUER_ALT_NAME
'//  szOID_SUBJECT_ALT_NAME2
'//  szOID_ISSUER_ALT_NAME2
'//
'//  pvStructInfo points to following CERT_ALT_NAME_INFO.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CERT_OTHER_NAME DWORD
   pszObjId AS ASCIIZ PTR         ' LPSTR
   Value    AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB
END TYPE

'typedef struct _CERT_ALT_NAME_ENTRY {
'    DWORD   dwAltNameChoice;
'    union {
'        PCERT_OTHER_NAME            pOtherName;         // 1
'        LPWSTR                      pwszRfc822Name;     // 2  (encoded IA5)
'        LPWSTR                      pwszDNSName;        // 3  (encoded IA5)
'        // Not implemented          x400Address;        // 4
'        CERT_NAME_BLOB              DirectoryName;      // 5
'        // Not implemented          pEdiPartyName;      // 6
'        LPWSTR                      pwszURL;            // 7  (encoded IA5)
'        CRYPT_DATA_BLOB             IPAddress;          // 8  (Octet String)
'        LPSTR                       pszRegisteredID;    // 9  (Object Identifer)
'    };
'} CERT_ALT_NAME_ENTRY, *PCERT_ALT_NAME_ENTRY;

' // Size = 8 bytes
UNION CERT_ALT_NAME_ENTRY_UNION DWORD
   pOtherName      AS CERT_OTHER_NAME PTR   ' PCERT_OTHER_NAME
   pwszRfc822Name  AS WSTRINGZ PTR          ' LPWSTR
   pwszDNSName     AS WSTRINGZ PTR          ' LPWSTR
   DirectoryName   AS CERT_NAME_BLOB        ' CERT_NAME_BLOB
   pwszURL         AS WSTRINGZ PTR          ' LPWSTR
   IPAddress       AS CRYPT_DATA_BLOB       ' CRYPT_DATA_BLOB
   pszRegisteredID AS ASCIIZ PTR            ' LPSTR
END UNION

' // Size = 12 bytes
TYPE CERT_ALT_NAME_ENTRY DWORD
   dwAltNameChoice AS DWORD
   CERT_ALT_NAME_ENTRY_UNION
END TYPE

%CERT_ALT_NAME_OTHER_NAME        = 1???
%CERT_ALT_NAME_RFC822_NAME       = 2???
%CERT_ALT_NAME_DNS_NAME          = 3???
%CERT_ALT_NAME_X400_ADDRESS      = 4???
%CERT_ALT_NAME_DIRECTORY_NAME    = 5???
%CERT_ALT_NAME_EDI_PARTY_NAME    = 6???
%CERT_ALT_NAME_URL               = 7???
%CERT_ALT_NAME_IP_ADDRESS        = 8???
%CERT_ALT_NAME_REGISTERED_ID     = 9???

' // Size = 8 bytes
TYPE CERT_ALT_NAME_INFO DWORD
   cAltEntry  AS DWORD                     ' DWORD
   rgAltEntry AS CERT_ALT_NAME_ENTRY PTR   ' PCERT_ALT_NAME_ENTRY
END TYPE

'//+-------------------------------------------------------------------------
'//  Alternate name IA5 Error Location Definitions for
'//  CRYPT_E_INVALID_IA5_STRING.
'//
'//  Error location is returned in *pcbEncoded by
'//  CryptEncodeObject(X509_ALTERNATE_NAME)
'//
'//  Error location consists of:
'//    ENTRY_INDEX   - 8 bits << 16
'//    VALUE_INDEX   - 16 bits (unicode character index)
'//--------------------------------------------------------------------------
%CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK  = &HFF???
%CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT = 16???
%CERT_ALT_NAME_VALUE_ERR_INDEX_MASK  = &H0000FFFF???
%CERT_ALT_NAME_VALUE_ERR_INDEX_SHIFT = 0???

'#define GET_CERT_ALT_NAME_ENTRY_ERR_INDEX(X)   \
'    ((X >> CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT) & \
'    CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK)

MACRO FUNCTION GET_CERT_ALT_NAME_ENTRY_ERR_INDEX(X)
   SHIFT RIGHT X, %CERT_ALT_NAME_ENTRY_ERR_INDEX_SHIFT
END MACRO = (X AND %CERT_ALT_NAME_ENTRY_ERR_INDEX_MASK)

'#define GET_CERT_ALT_NAME_VALUE_ERR_INDEX(X) \
'    (X & CERT_ALT_NAME_VALUE_ERR_INDEX_MASK)

MACRO GET_CERT_ALT_NAME_VALUE_ERR_INDEX(X) = (X AND %CERT_ALT_NAME_VALUE_ERR_INDEX_MASK)

'//+-------------------------------------------------------------------------
'//  X509_BASIC_CONSTRAINTS
'//  szOID_BASIC_CONSTRAINTS
'//
'//  pvStructInfo points to following CERT_BASIC_CONSTRAINTS_INFO.
'//--------------------------------------------------------------------------

' // Size = 28 bytes
TYPE CERT_BASIC_CONSTRAINTS_INFO DWORD
   SubjectType          AS CRYPT_BIT_BLOB       ' CRYPT_BIT_BLOB
   fPathLenConstraint   AS LONG                 ' BOOL
   dwPathLenConstraint  AS DWORD                ' DWORD
   cSubtreesConstraint  AS DWORD                ' DWORD
   rgSubtreesConstraint AS CERT_NAME_BLOB PTR   ' CERT_NAME_BLOB*
END TYPE

%CERT_CA_SUBJECT_FLAG         = &H80???
%CERT_END_ENTITY_SUBJECT_FLAG = &H40???

'//+-------------------------------------------------------------------------
'//  X509_BASIC_CONSTRAINTS2
'//  szOID_BASIC_CONSTRAINTS2
'//
'//  pvStructInfo points to following CERT_BASIC_CONSTRAINTS2_INFO.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CERT_BASIC_CONSTRAINTS2_INFO DWORD
   fCA                 AS LONG    ' BOOL
   fPathLenConstraint  AS LONG    ' BOOL
   dwPathLenConstraint AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_KEY_USAGE
'//  szOID_KEY_USAGE
'//
'//  pvStructInfo points to a CRYPT_BIT_BLOB. Has same bit definitions as
'//  CERT_KEY_ATTRIBUTES_INFO's IntendedKeyUsage.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CERT_POLICIES
'//  szOID_CERT_POLICIES
'//  szOID_CERT_POLICIES_95   NOTE--Only allowed for decoding!!!
'//
'//  pvStructInfo points to following CERT_POLICIES_INFO.
'//
'//  NOTE: when decoding using szOID_CERT_POLICIES_95 the pszPolicyIdentifier
'//        may contain an empty string
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CERT_POLICY_QUALIFIER_INFO DWORD
   pszPolicyQualifierId AS ASCIIZ PTR         ' LPSTR
   Qualifier            AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB
END TYPE

' // Size = 12 bytes
TYPE CERT_POLICY_INFO DWORD
   pszPolicyIdentifier AS ASCIIZ PTR                       ' LPSTR
   cPolicyQualifier    AS DWORD                            ' DWORD
   rgPolicyQualifier   AS CERT_POLICY_QUALIFIER_INFO PTR   ' CERT_POLICY_QUALIFIER_INFO*
END TYPE

' // Size = 8 bytes
TYPE CERT_POLICIES_INFO DWORD
   cPolicyInfo  AS DWORD                  ' DWORD
   rgPolicyInfo AS CERT_POLICY_INFO PTR   ' CERT_POLICY_INFO
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_PKIX_POLICY_QUALIFIER_USERNOTICE
'//  szOID_PKIX_POLICY_QUALIFIER_USERNOTICE
'//
'//  pvStructInfo points to following CERT_POLICY_QUALIFIER_USER_NOTICE.
'//
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CERT_POLICY_QUALIFIER_NOTICE_REFERENCE DWORD
   pszOrganization AS ASCIIZ PTR   ' LPSTR
   cNoticeNumbers  AS DWORD        ' DWORD
   rgNoticeNumbers AS LONG PTR     ' int *
END TYPE

' // Size = 8 bytes
TYPE CERT_POLICY_QUALIFIER_USER_NOTICE DWORD
   pNoticeReference AS CERT_POLICY_QUALIFIER_NOTICE_REFERENCE PTR
   pszDisplayText   AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'//+-------------------------------------------------------------------------
'//  szOID_CERT_POLICIES_95_QUALIFIER1 - Decode Only!!!!
'//
'//  pvStructInfo points to following CERT_POLICY95_QUALIFIER1.
'//
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CPS_URLS DWORD
   pszURL     AS WSTRINGZ PTR                     ' LPWSTR
   pAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER PTR   ' CRYPT_ALGORITHM_IDENTIFIER*
   pDigest    AS CRYPT_DATA_BLOB PTR              ' CRYPT_DATA_BLOB*
END TYPE

' // Size = 20 bytes
TYPE CERT_POLICY95_QUALIFIER1 DWORD
   pszPracticesReference  AS WSTRINGZ PTR   ' LPWSTR
   pszNoticeIdentifier    AS ASCIIZ PTR     ' LPSTR
   pszNSINoticeIdentifier AS ASCIIZ PTR     ' LPSTR
   cCPSURLs               AS DWORD          ' DWORD
   rgCPSURLs              AS CPS_URLS PTR   ' CPS_URLS*
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_POLICY_MAPPINGS
'//  szOID_POLICY_MAPPINGS
'//  szOID_LEGACY_POLICY_MAPPINGS
'//
'//  pvStructInfo points to following CERT_POLICY_MAPPINGS_INFO.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CERT_POLICY_MAPPING DWORD
   pszIssuerDomainPolicy  AS ASCIIZ PTR   ' LPSTR
   pszSubjectDomainPolicy AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 8 bytes
TYPE CERT_POLICY_MAPPINGS_INFO DWORD
   cPolicyMapping  AS DWORD                     ' DWORD
   rgPolicyMapping AS CERT_POLICY_MAPPING PTR   ' PCERT_POLICY_MAPPING
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_POLICY_CONSTRAINTS
'//  szOID_POLICY_CONSTRAINTS
'//
'//  pvStructInfo points to following CERT_POLICY_CONSTRAINTS_INFO.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_POLICY_CONSTRAINTS_INFO DWORD
   fRequireExplicitPolicy           AS LONG    ' BOOL
   dwRequireExplicitPolicySkipCerts AS DWORD   ' DWORD
   fInhibitPolicyMapping            AS LONG    ' BOOL
   dwInhibitPolicyMappingSkipCerts  AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  RSA_CSP_PUBLICKEYBLOB
'//
'//  pvStructInfo points to a PUBLICKEYSTRUC immediately followed by a
'//  RSAPUBKEY and the modulus bytes.
'//
'//  CryptExportKey outputs the above StructInfo for a dwBlobType of
'//  PUBLICKEYBLOB. CryptImportKey expects the above StructInfo when
'//  importing a public key.
'//
'//  For dwCertEncodingType = X509_ASN_ENCODING, the RSA_CSP_PUBLICKEYBLOB is
'//  encoded as a PKCS #1 RSAPublicKey consisting of a SEQUENCE of a
'//  modulus INTEGER and a publicExponent INTEGER. The modulus is encoded
'//  as being a unsigned integer. When decoded, if the modulus was encoded
'//  as unsigned integer with a leading 0 byte, the 0 byte is removed before
'//  converting to the CSP modulus bytes.
'//
'//  For decode, the aiKeyAlg field of PUBLICKEYSTRUC is always set to
'//  CALG_RSA_KEYX.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_KEYGEN_REQUEST_TO_BE_SIGNED
'//
'//  pvStructInfo points to CERT_KEYGEN_REQUEST_INFO.
'//
'//  For CryptDecodeObject(), the pbEncoded is the "to be signed" plus its
'//  signature (output of a X509_CERT CryptEncodeObject()).
'//
'//  For CryptEncodeObject(), the pbEncoded is just the "to be signed".
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_ATTRIBUTE data structure
'//
'//  pvStructInfo points to a CRYPT_ATTRIBUTE.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_ATTRIBUTES data structure
'//
'//  pvStructInfo points to a CRYPT_ATTRIBUTES.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_CONTENT_INFO_SEQUENCE_OF_ANY data structure
'//
'//  pvStructInfo points to following CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY.
'//
'//  For X509_ASN_ENCODING: encoded as a PKCS#7 ContentInfo structure wrapping
'//  a sequence of ANY. The value of the contentType field is pszObjId,
'//  while the content field is the following structure:
'//      SequenceOfAny ::= SEQUENCE OF ANY
'//
'//  The CRYPT_DER_BLOBs point to the already encoded ANY content.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPT_CONTENT_INFO_SEQUENCE_OF_ANY DWORD
   pszObjId AS ASCIIZ PTR           ' LPSTR
   cValue   AS DWORD                ' DWORD
   rgValue  AS CRYPT_DER_BLOB PTR   ' PCRYPT_DER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  PKCS_CONTENT_INFO data structure
'//
'//  pvStructInfo points to following CRYPT_CONTENT_INFO.
'//
'//  For X509_ASN_ENCODING: encoded as a PKCS#7 ContentInfo structure.
'//  The CRYPT_DER_BLOB points to the already encoded ANY content.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPT_CONTENT_INFO DWORD
   pszObjId AS ASCIIZ PTR       ' LPSTR
   Content  AS CRYPT_DER_BLOB   ' CRYPT_DER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_OCTET_STRING data structure
'//
'//  pvStructInfo points to a CRYPT_DATA_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_BITS data structure
'//
'//  pvStructInfo points to a CRYPT_BIT_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_BITS_WITHOUT_TRAILING_ZEROES data structure
'//
'//  pvStructInfo points to a CRYPT_BIT_BLOB.
'//
'//  The same as X509_BITS, except before encoding, the bit length is
'//  decremented to exclude trailing zero bits.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_INTEGER data structure
'//
'//  pvStructInfo points to an int.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_MULTI_BYTE_INTEGER data structure
'//
'//  pvStructInfo points to a CRYPT_INTEGER_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_ENUMERATED data structure
'//
'//  pvStructInfo points to an int containing the enumerated value
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CHOICE_OF_TIME data structure
'//
'//  pvStructInfo points to a FILETIME.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_SEQUENCE_OF_ANY data structure
'//
'//  pvStructInfo points to following CRYPT_SEQUENCE_OF_ANY.
'//
'//  The CRYPT_DER_BLOBs point to the already encoded ANY content.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CRYPT_SEQUENCE_OF_ANY DWORD
   cValue  AS DWORD                ' DWORD
   rgValue AS CRYPT_DER_BLOB PTR   ' PCRYPT_DER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_AUTHORITY_KEY_ID2
'//  szOID_AUTHORITY_KEY_IDENTIFIER2
'//
'//  pvStructInfo points to following CERT_AUTHORITY_KEY_ID2_INFO.
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_AUTHORITY_KEY_ID2)
'//
'//  See X509_ALTERNATE_NAME for error location defines.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CERT_AUTHORITY_KEY_ID2_INFO DWORD
   KeyId                     AS CRYPT_DATA_BLOB
   AuthorityCertIssuer       AS CERT_ALT_NAME_INFO
   AuthorityCertSerialNumber AS CRYPT_INTEGER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  szOID_SUBJECT_KEY_IDENTIFIER
'//
'//  pvStructInfo points to a CRYPT_DATA_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_AUTHORITY_INFO_ACCESS
'//  szOID_AUTHORITY_INFO_ACCESS
'//
'//  pvStructInfo points to following CERT_AUTHORITY_INFO_ACCESS.
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_AUTHORITY_INFO_ACCESS)
'//
'//  Error location consists of:
'//    ENTRY_INDEX   - 8 bits << 16
'//    VALUE_INDEX   - 16 bits (unicode character index)
'//
'//  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
'//  defines.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_ACCESS_DESCRIPTION DWORD
   pszAccessMethod AS ASCIIZ PTR            ' LPSTR
   AccessLocation  AS CERT_ALT_NAME_ENTRY   ' CERT_ALT_NAME_ENTRY
END TYPE

' // Size = 8 bytes
TYPE CERT_AUTHORITY_INFO_ACCESS DWORD
   cAccDescr  AS DWORD                         ' DWORD
   rgAccDescr AS CERT_ACCESS_DESCRIPTION PTR   ' PCERT_ACCESS_DESCRIPTION
END TYPE

'//+-------------------------------------------------------------------------
'//  PKIX Access Description: Access Method Object Identifiers
'//--------------------------------------------------------------------------
$szOID_PKIX_ACC_DESCR           = "1.3.6.1.5.5.7.48"

'// For szOID_AUTHORITY_INFO_ACCESS
$szOID_PKIX_OCSP                = "1.3.6.1.5.5.7.48.1"
$szOID_PKIX_CA_ISSUERS          = "1.3.6.1.5.5.7.48.2"

'// For szOID_SUBJECT_INFO_ACCESS
$szOID_PKIX_TIME_STAMPING       = "1.3.6.1.5.5.7.48.3"
$szOID_PKIX_CA_REPOSITORY       = "1.3.6.1.5.5.7.48.5"

'//+-------------------------------------------------------------------------
'//  X509_CRL_REASON_CODE
'//  szOID_CRL_REASON_CODE
'//
'//  pvStructInfo points to an int which can be set to one of the following
'//  enumerated values:
'//--------------------------------------------------------------------------
%CRL_REASON_UNSPECIFIED             = 0&
%CRL_REASON_KEY_COMPROMISE          = 1&
%CRL_REASON_CA_COMPROMISE           = 2&
%CRL_REASON_AFFILIATION_CHANGED     = 3&
%CRL_REASON_SUPERSEDED              = 4&
%CRL_REASON_CESSATION_OF_OPERATION  = 5&
%CRL_REASON_CERTIFICATE_HOLD        = 6&
%CRL_REASON_REMOVE_FROM_CRL         = 8&


'//+-------------------------------------------------------------------------
'//  X509_CRL_DIST_POINTS
'//  szOID_CRL_DIST_POINTS
'//
'//  pvStructInfo points to following CRL_DIST_POINTS_INFO.
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_CRL_DIST_POINTS)
'//
'//  Error location consists of:
'//    CRL_ISSUER_BIT    - 1 bit  << 31 (0 for FullName, 1 for CRLIssuer)
'//    POINT_INDEX       - 7 bits << 24
'//    ENTRY_INDEX       - 8 bits << 16
'//    VALUE_INDEX       - 16 bits (unicode character index)
'//
'//  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
'//  defines.
'//--------------------------------------------------------------------------
'typedef struct _CRL_DIST_POINT_NAME {
'    DWORD   dwDistPointNameChoice;
'    union {
'        CERT_ALT_NAME_INFO      FullName;       // 1
'        // Not implemented      IssuerRDN;      // 2
'    };
'} CRL_DIST_POINT_NAME, *PCRL_DIST_POINT_NAME;

' // Size = 8 bytes
UNION CRL_DIST_POINT_NAME_UNION DWORD
   FullName AS CERT_ALT_NAME_INFO
END UNION

' // Size = 12 bytes
TYPE CRL_DIST_POINT_NAME DWORD
   dwDistPointNameChoice AS DWORD
   CRL_DIST_POINT_NAME_UNION
END TYPE

%CRL_DIST_POINT_NO_NAME         = 0&
%CRL_DIST_POINT_FULL_NAME       = 1&
%CRL_DIST_POINT_ISSUER_RDN_NAME = 2&

'typedef struct _CRL_DIST_POINT {
'    CRL_DIST_POINT_NAME     DistPointName;      // OPTIONAL
'    CRYPT_BIT_BLOB          ReasonFlags;        // OPTIONAL
'    CERT_ALT_NAME_INFO      CRLIssuer;          // OPTIONAL
'} CRL_DIST_POINT, *PCRL_DIST_POINT;

' // Size = 32 bytes
TYPE CRL_DIST_POINT DWORD
   DistPointName AS CRL_DIST_POINT_NAME
   ReasonFlags   AS CRYPT_BIT_BLOB
   CRLIssuer     AS CERT_ALT_NAME_INFO
END TYPE

%CRL_REASON_UNUSED_FLAG                  = &H80&
%CRL_REASON_KEY_COMPROMISE_FLAG          = &H40&
%CRL_REASON_CA_COMPROMISE_FLAG           = &H20&
%CRL_REASON_AFFILIATION_CHANGED_FLAG     = &H10&
%CRL_REASON_SUPERSEDED_FLAG              = &H08&
%CRL_REASON_CESSATION_OF_OPERATION_FLAG  = &H04&
%CRL_REASON_CERTIFICATE_HOLD_FLAG        = &H02&

' // Size = 8 bytes
TYPE CRL_DIST_POINTS_INFO DWORD
   cDistPoint  AS DWORD                ' DWORD
   rgDistPoint AS CRL_DIST_POINT PTR   ' PCRL_DIST_POINT
END TYPE

%CRL_DIST_POINT_ERR_INDEX_MASK          = &H7F&
%CRL_DIST_POINT_ERR_INDEX_SHIFT         = 24&

'#define GET_CRL_DIST_POINT_ERR_INDEX(X)   \
'    ((X >> CRL_DIST_POINT_ERR_INDEX_SHIFT) & CRL_DIST_POINT_ERR_INDEX_MASK)

MACRO FUNCTION GET_CRL_DIST_POINT_ERR_INDEX(X)
   SHIFT RIGHT X, %CRL_DIST_POINT_ERR_INDEX_SHIFT
END MACRO = (X AND %CRL_DIST_POINT_ERR_INDEX_MASK)

%CRL_DIST_POINT_ERR_CRL_ISSUER_BIT      = &H80000000&

'#define IS_CRL_DIST_POINT_ERR_CRL_ISSUER(X)   \
'    (0 != (X & CRL_DIST_POINT_ERR_CRL_ISSUER_BIT))

MACRO IS_CRL_DIST_POINT_ERR_CRL_ISSUER(X) = (X AND %CRL_DIST_POINT_ERR_CRL_ISSUER_BIT) <> 0

'//+-------------------------------------------------------------------------
'//  X509_CROSS_CERT_DIST_POINTS
'//  szOID_CROSS_CERT_DIST_POINTS
'//
'//  pvStructInfo points to following CROSS_CERT_DIST_POINTS_INFO.
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_CRL_DIST_POINTS)
'//
'//  Error location consists of:
'//    POINT_INDEX       - 8 bits << 24
'//    ENTRY_INDEX       - 8 bits << 16
'//    VALUE_INDEX       - 16 bits (unicode character index)
'//
'//  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
'//  defines.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CROSS_CERT_DIST_POINTS_INFO DWORD
   dwSyncDeltaTime AS DWORD                    ' DWORD
   cDistPoint      AS DWORD                    ' DWORD
   gDistPoint      AS CERT_ALT_NAME_INFO PTR   ' PCERT_ALT_NAME_INFO
END TYPE

%CROSS_CERT_DIST_POINT_ERR_INDEX_MASK   = &HFF&
%CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT  = 24&
'#define GET_CROSS_CERT_DIST_POINT_ERR_INDEX(X)   \
'    ((X >> CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT) & \
'                CROSS_CERT_DIST_POINT_ERR_INDEX_MASK)

MACRO FUNCTION GET_CROSS_CERT_DIST_POINT_ERR_INDEX(X)
   SHIFT RIGHT X, %CROSS_CERT_DIST_POINT_ERR_INDEX_SHIFT
END MACRO = (X AND %CROSS_CERT_DIST_POINT_ERR_INDEX_MASK)

'//+-------------------------------------------------------------------------
'//  X509_ENHANCED_KEY_USAGE
'//  szOID_ENHANCED_KEY_USAGE
'//
'//  pvStructInfo points to a CERT_ENHKEY_USAGE, CTL_USAGE.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_CERT_PAIR
'//
'//  pvStructInfo points to the following CERT_PAIR.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_PAIR DWORD
   Forward AS CERT_BLOB
   Reverse AS CERT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  szOID_CRL_NUMBER
'//
'//  pvStructInfo points to an int.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_DELTA_CRL_INDICATOR
'//
'//  pvStructInfo points to an int.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_ISSUING_DIST_POINT
'//  X509_ISSUING_DIST_POINT
'//
'//  pvStructInfo points to the following CRL_ISSUING_DIST_POINT.
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_ISSUING_DIST_POINT)
'//
'//  Error location consists of:
'//    ENTRY_INDEX       - 8 bits << 16
'//    VALUE_INDEX       - 16 bits (unicode character index)
'//
'//  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
'//  defines.
'//--------------------------------------------------------------------------

' // Size = 36 bytes
TYPE CRL_ISSUING_DIST_POINT DWORD
   DistPointName          AS CRL_DIST_POINT_NAME   ' CRL_DIST_POINT_NAME
   fOnlyContainsUserCerts AS LONG                  ' BOOL
   fOnlyContainsCACerts   AS LONG                  ' BOOL
   OnlySomeReasonFlags    AS CRYPT_BIT_BLOB        ' CRYPT_BIT_BLOB
   fIndirectCRL           AS LONG                  ' BOOL
END TYPE

'//+-------------------------------------------------------------------------
'//  szOID_FRESHEST_CRL
'//
'//  pvStructInfo points to CRL_DIST_POINTS_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NAME_CONSTRAINTS
'//  X509_NAME_CONSTRAINTS
'//
'//  pvStructInfo points to the following CERT_NAME_CONSTRAINTS_INFO
'//
'//  For CRYPT_E_INVALID_IA5_STRING, the error location is returned in
'//  *pcbEncoded by CryptEncodeObject(X509_NAME_CONSTRAINTS)
'//
'//  Error location consists of:
'//    EXCLUDED_SUBTREE_BIT  - 1 bit  << 31 (0 for permitted, 1 for excluded)
'//    ENTRY_INDEX           - 8 bits << 16
'//    VALUE_INDEX           - 16 bits (unicode character index)
'//
'//  See X509_ALTERNATE_NAME for ENTRY_INDEX and VALUE_INDEX error location
'//  defines.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CERT_GENERAL_SUBTREE DWORD
   Base      AS CERT_ALT_NAME_ENTRY   ' CERT_ALT_NAME_ENTRY
   dwMinimum AS DWORD                 ' DWORD
   fMaximum  AS LONG                  ' BOOL
   dwMaximum AS DWORD                 ' DWORD
END TYPE

' // Size = 16 bytes
TYPE CERT_NAME_CONSTRAINTS_INFO DWORD
   cPermittedSubtree  AS DWORD
   rgPermittedSubtree AS CERT_GENERAL_SUBTREE PTR
   cExcludedSubtree   AS DWORD
   rgExcludedSubtree  AS CERT_GENERAL_SUBTREE PTR
END TYPE

%CERT_EXCLUDED_SUBTREE_BIT       = &H80000000???

'#define IS_CERT_EXCLUDED_SUBTREE(X)     \
'    (0 != (X & CERT_EXCLUDED_SUBTREE_BIT))

MACRO IS_CERT_EXCLUDED_SUBTREE(X) = (X AND CERT_EXCLUDED_SUBTREE_BIT) <> 0

'//+-------------------------------------------------------------------------
'//  szOID_NEXT_UPDATE_LOCATION
'//
'//  pvStructInfo points to a CERT_ALT_NAME_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_REMOVE_CERTIFICATE
'//
'//  pvStructInfo points to an int which can be set to one of the following
'//   0 - Add certificate
'//   1 - Remove certificate
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_CTL
'//  szOID_CTL
'//
'//  pvStructInfo points to a CTL_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_SORTED_CTL
'//
'//  pvStructInfo points to a CTL_INFO.
'//
'//  Same as for PKCS_CTL, except, the CTL entries are sorted. The following
'//  extension containing the sort information is inserted as the first
'//  extension in the encoded CTL.
'//
'//  Only supported for Encoding. CRYPT_ENCODE_ALLOC_FLAG flag must be
'//  set.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'// Sorted CTL TrustedSubjects extension
'//
'//  Array of little endian DWORDs:
'//   [0] - Flags
'//   [1] - Count of HashBucket entry offsets
'//   [2] - Maximum HashBucket entry collision count
'//   [3 ..] (Count + 1) HashBucket entry offsets
'//
'//  When this extension is present in the CTL,
'//  the ASN.1 encoded sequence of TrustedSubjects are HashBucket ordered.
'//
'//  The entry offsets point to the start of the first encoded TrustedSubject
'//  sequence for the HashBucket. The encoded TrustedSubjects for a HashBucket
'//  continue until the encoded offset of the next HashBucket. A HashBucket has
'//  no entries if HashBucket[N] == HashBucket[N + 1].
'//
'//  The HashBucket offsets are from the start of the ASN.1 encoded CTL_INFO.
'//--------------------------------------------------------------------------
%SORTED_CTL_EXT_FLAGS_OFFSET         = (0*4)
%SORTED_CTL_EXT_COUNT_OFFSET         = (1*4)
%SORTED_CTL_EXT_MAX_COLLISION_OFFSET = (2*4)
%SORTED_CTL_EXT_HASH_BUCKET_OFFSET   = (3*4)

'// If the SubjectIdentifiers are a MD5 or SHA1 hash, the following flag is
'// set. When set, the first 4 bytes of the SubjectIdentifier are used as
'// the dwhash. Otherwise, the SubjectIdentifier bytes are hashed into dwHash.
'// In either case the HashBucket index = dwHash % cHashBucket.
%SORTED_CTL_EXT_HASHED_SUBJECT_IDENTIFIER_FLAG       = &H1???

'//+-------------------------------------------------------------------------
'//  X509_MULTI_BYTE_UINT
'//
'//  pvStructInfo points to a CRYPT_UINT_BLOB. Before encoding, inserts a
'//  leading 0x00. After decoding, removes a leading 0x00.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_DSS_PUBLICKEY
'//
'//  pvStructInfo points to a CRYPT_UINT_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_DSS_PARAMETERS
'//
'//  pvStructInfo points to following CERT_DSS_PARAMETERS data structure.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CERT_DSS_PARAMETERS DWORD
   p AS CRYPT_UINT_BLOB
   q AS CRYPT_UINT_BLOB
   g AS CRYPT_UINT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_DSS_SIGNATURE
'//
'//  pvStructInfo is a BYTE rgbSignature[CERT_DSS_SIGNATURE_LEN]. The
'//  bytes are ordered as output by the DSS CSP's CryptSignHash().
'//--------------------------------------------------------------------------
%CERT_DSS_R_LEN          = 20
%CERT_DSS_S_LEN          = 20
%CERT_DSS_SIGNATURE_LEN  = %CERT_DSS_R_LEN + %CERT_DSS_S_LEN

'// Sequence of 2 unsigned integers (the extra +1 is for a potential leading
'// 0x00 to make the integer unsigned)
%CERT_MAX_ASN_ENCODED_DSS_SIGNATURE_LEN = 2 + 2*(2 + 20 +1)

'//+-------------------------------------------------------------------------
'//  X509_DH_PUBLICKEY
'//
'//  pvStructInfo points to a CRYPT_UINT_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_DH_PARAMETERS
'//
'//  pvStructInfo points to following CERT_DH_PARAMETERS data structure.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_DH_PARAMETERS DWORD
   p AS CRYPT_UINT_BLOB
   g AS CRYPT_UINT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_ECC_SIGNATURE
'//
'//  pvStructInfo points to following CERT_ECC_SIGNATURE data structure.
'//
'//  Note, identical to the above except for the names of the fields. Same
'//  underlying encode/decode functions are used.
'//--------------------------------------------------------------------------
' // Size = 16 bytes
TYPE CERT_ECC_SIGNATURE DWORD
   r AS CRYPT_UINT_BLOB
   s AS CRYPT_UINT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  X942_DH_PARAMETERS
'//
'//  pvStructInfo points to following CERT_X942_DH_PARAMETERS data structure.
'//
'//  If q.cbData == 0, then, the following fields are zero'ed.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_X942_DH_VALIDATION_PARAMS DWORD
   seed        AS CRYPT_BIT_BLOB
   pgenCounter AS DWORD
END TYPE

' // Size = 36 bytes
TYPE CERT_X942_DH_PARAMETERS DWORD
   p                 AS CRYPT_UINT_BLOB
   g                 AS CRYPT_UINT_BLOB
   q                 AS CRYPT_UINT_BLOB
   j                 AS CRYPT_UINT_BLOB
   pValidationParams AS CERT_X942_DH_VALIDATION_PARAMS PTR
END TYPE

'//+-------------------------------------------------------------------------
'//  X942_OTHER_INFO
'//
'//  pvStructInfo points to following CRYPT_X942_OTHER_INFO data structure.
'//
'//  rgbCounter and rgbKeyLength are in Little Endian order.
'//--------------------------------------------------------------------------
%CRYPT_X942_COUNTER_BYTE_LENGTH      = 4
%CRYPT_X942_KEY_LENGTH_BYTE_LENGTH   = 4
'#define CRYPT_X942_PUB_INFO_BYTE_LENGTH     (512/8)
%CRYPT_X942_PUB_INFO_BYTE_LENGTH     = (512\8)

'typedef struct _CRYPT_X942_OTHER_INFO {
'    LPSTR               pszContentEncryptionObjId;
'    BYTE                rgbCounter[CRYPT_X942_COUNTER_BYTE_LENGTH];
'    BYTE                rgbKeyLength[CRYPT_X942_KEY_LENGTH_BYTE_LENGTH];
'    CRYPT_DATA_BLOB     PubInfo;    // OPTIONAL
'} CRYPT_X942_OTHER_INFO, *PCRYPT_X942_OTHER_INFO;

' // Size = 20 bytes
TYPE CRYPT_X942_OTHER_INFO DWORD
   pszContentEncryptionObjId AS ASCIIZ PTR
   rgbCounter (%CRYPT_X942_COUNTER_BYTE_LENGTH - 1) AS BYTE
   rgbKeyLength (%CRYPT_X942_KEY_LENGTH_BYTE_LENGTH - 1) AS BYTE
   PubInfo AS CRYPT_DATA_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  ECC_CMS_SHARED_INFO
'//
'//  pvStructInfo points to following ECC_CMS_SHARED_INFO data structure.
'//
'//  rgbSuppPubInfo is in Little Endian order.
'//--------------------------------------------------------------------------
%CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH = 4
' // Size = 24 bytes
TYPE CRYPT_ECC_CMS_SHARED_INFO DWORD
   Algorithm   AS CRYPT_ALGORITHM_IDENTIFIER
   EntityUInfo AS CRYPT_DATA_BLOB   ' // OPTIONAL
   rgbSuppPubInfo(%CRYPT_ECC_CMS_SHARED_INFO_SUPPPUBINFO_BYTE_LENGTH - 1) AS BYTE
END TYPE

'//+-------------------------------------------------------------------------
'//  PKCS_RC2_CBC_PARAMETERS
'//  szOID_RSA_RC2CBC
'//
'//  pvStructInfo points to following CRYPT_RC2_CBC_PARAMETERS data structure.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CRYPT_RC2_CBC_PARAMETERS DWORD
   dwVersion AS DWORD   ' DWORD dwVersion
   fIV       AS LONG    ' BOOL  fIV  // set if has following IV
   rgbIV(7)  AS BYTE    ' BYTE  rgbIV[8]
END TYPE

%CRYPT_RC2_40BIT_VERSION    = 160
%CRYPT_RC2_56BIT_VERSION    = 52
%CRYPT_RC2_64BIT_VERSION    = 120
%CRYPT_RC2_128BIT_VERSION   = 58


'//+-------------------------------------------------------------------------
'//  PKCS_SMIME_CAPABILITIES
'//  szOID_RSA_SMIMECapabilities
'//
'//  pvStructInfo points to following CRYPT_SMIME_CAPABILITIES data structure.
'//
'//  Note, for CryptEncodeObject(X509_ASN_ENCODING), Parameters.cbData == 0
'//  causes the encoded parameters to be omitted and not encoded as a NULL
'//  (05 00) as is done when encoding a CRYPT_ALGORITHM_IDENTIFIER. This
'//  is per the SMIME specification for encoding capabilities.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPT_SMIME_CAPABILITY DWORD
   pszObjId AS ASCIIZ PTR           ' LPSTR
   Parameters AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB
END TYPE

' // Size = 8 bytes
TYPE CRYPT_SMIME_CAPABILITIES DWORD
   cCapability  AS DWORD                        ' DWORD
   rgCapability AS CRYPT_SMIME_CAPABILITY PTR   ' PCRYPT_SMIME_CAPABILITY
END TYPE

'//+-------------------------------------------------------------------------
'//  Qualified Certificate Statements Extension Data Structures
'//
'//  X509_QC_STATEMENTS_EXT
'//  szOID_QC_STATEMENTS_EXT
'//
'//  pvStructInfo points to following CERT_QC_STATEMENTS_EXT_INFO
'//  data structure.
'//
'//  Note, identical to the above except for the names of the fields. Same
'//  underlying encode/decode functions are used.
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CERT_QC_STATEMENT DWORD
   pszStatementId AS ASCIIZ PTR         ' // pszObjId
   StatementInfo  AS CRYPT_OBJID_BLOB   ' // OPTIONAL
END TYPE

' // Size = 8 bytes
TYPE CERT_QC_STATEMENTS_EXT_INFO
   cStatement AS DWORD                    ' DWORD
   rgStatement AS CERT_QC_STATEMENT PTR   ' PCERT_QC_STATEMENT
END TYPE


'// QC Statment Ids

'// European Union
$szOID_QC_EU_COMPLIANCE         = "0.4.0.1862.1.1"
'// Secure Signature Creation Device
$szOID_QC_SSCD                  = "0.4.0.1862.1.4"

'//+-------------------------------------------------------------------------
'//  X509_OBJECT_IDENTIFIER
'//  szOID_ECC_PUBLIC_KEY
'//
'//  pvStructInfo points to a LPSTR of the dot representation.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  X509_ALGORITHM_IDENTIFIER
'//  szOID_ECDSA_SPECIFIED
'//
'//  pvStructInfo points to a CRYPT_ALGORITHM_IDENTIFIER.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  PKCS_RSA_SSA_PSS_PARAMETERS
'//  szOID_RSA_SSA_PSS
'//
'//  pvStructInfo points to the following CRYPT_RSA_SSA_PSS_PARAMETERS
'//  data structure.
'//
'//  For encoding uses the following defaults if the corresponding field
'//  is set to NULL or 0:
'//      HashAlgorithm.pszObjId : szOID_OIWSEC_sha1
'//      MaskGenAlgorithm.pszObjId : szOID_RSA_MGF1
'//      MaskGenAlgorithm.HashAlgorithm.pszObjId : HashAlgorithm.pszObjId
'//      dwSaltLength: cbHash
'//      dwTrailerField : PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC
'//
'//  Normally for encoding, only the HashAlgorithm.pszObjId field will
'//  need to be set.
'//
'//  For decoding, all of fields are explicitly set.
'//--------------------------------------------------------------------------
' // Size = 16 bytes
TYPE CRYPT_MASK_GEN_ALGORITHM DWORD
   pszObjId      AS ASCIIZ PTR
   HashAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
END TYPE

' // Size = 36 bytes
TYPE CRYPT_RSA_SSA_PSS_PARAMETERS DWORD
   HashAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   MaskGenAlgorithm AS CRYPT_MASK_GEN_ALGORITHM
   dwSaltLength     AS DWORD   ' DWORD
   dwTrailerField   AS DWORD   ' DWORD
END TYPE

%PKCS_RSA_SSA_PSS_TRAILER_FIELD_BC      = 1

'//+-------------------------------------------------------------------------
'//  PKCS_RSAES_OAEP_PARAMETERS
'//  szOID_RSAES_OAEP
'//
'//  pvStructInfo points to the following CRYPT_RSAES_OAEP_PARAMETERS
'//  data structure.
'//
'//  For encoding uses the following defaults if the corresponding field
'//  is set to NULL or 0:
'//      HashAlgorithm.pszObjId : szOID_OIWSEC_sha1
'//      MaskGenAlgorithm.pszObjId : szOID_RSA_MGF1
'//      MaskGenAlgorithm.HashAlgorithm.pszObjId : HashAlgorithm.pszObjId
'//      PSourceAlgorithm.pszObjId : szOID_RSA_PSPECIFIED
'//      PSourceAlgorithm.EncodingParameters.cbData : 0
'//      PSourceAlgorithm.EncodingParameters.pbData : NULL
'//
'//  Normally for encoding, only the HashAlgorithm.pszObjId field will
'//  need to be set.
'//
'//  For decoding, all of fields are explicitly set.
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_PSOURCE_ALGORITHM DWORD
   pszObjId           AS ASCIIZ PTR   ' LPSTR
   EncodingParameters AS CRYPT_DATA_BLOB
END TYPE

' // Size = 40 bytes
TYPE CRYPT_RSAES_OAEP_PARAMETERS DWORD
   HashAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   MaskGenAlgorithm AS CRYPT_MASK_GEN_ALGORITHM
   PSourceAlgorithm AS CRYPT_PSOURCE_ALGORITHM
END TYPE

'//+-------------------------------------------------------------------------
'//  PKCS7_SIGNER_INFO
'//
'//  pvStructInfo points to CMSG_SIGNER_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMS_SIGNER_INFO
'//
'//  pvStructInfo points to CMSG_CMS_SIGNER_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Verisign Certificate Extension Object Identifiers
'//--------------------------------------------------------------------------

'// Octet String containing Boolean
$szOID_VERISIGN_PRIVATE_6_9       = "2.16.840.1.113733.1.6.9"

'// Octet String containing IA5 string: lower case 32 char hex string
$szOID_VERISIGN_ONSITE_JURISDICTION_HASH = "2.16.840.1.113733.1.6.11"

'// Octet String containing Bit string
$szOID_VERISIGN_BITSTRING_6_13    = "2.16.840.1.113733.1.6.13"

'// EKU
$szOID_VERISIGN_ISS_STRONG_CRYPTO = "2.16.840.1.113733.1.8.1"


'//+-------------------------------------------------------------------------
'//  Netscape Certificate Extension Object Identifiers
'//--------------------------------------------------------------------------
$szOID_NETSCAPE                   = "2.16.840.1.113730"
$szOID_NETSCAPE_CERT_EXTENSION    = "2.16.840.1.113730.1"
$szOID_NETSCAPE_CERT_TYPE         = "2.16.840.1.113730.1.1"
$szOID_NETSCAPE_BASE_URL          = "2.16.840.1.113730.1.2"
$szOID_NETSCAPE_REVOCATION_URL    = "2.16.840.1.113730.1.3"
$szOID_NETSCAPE_CA_REVOCATION_URL = "2.16.840.1.113730.1.4"
$szOID_NETSCAPE_CERT_RENEWAL_URL  = "2.16.840.1.113730.1.7"
$szOID_NETSCAPE_CA_POLICY_URL     = "2.16.840.1.113730.1.8"
$szOID_NETSCAPE_SSL_SERVER_NAME   = "2.16.840.1.113730.1.12"
$szOID_NETSCAPE_COMMENT           = "2.16.840.1.113730.1.13"

'//+-------------------------------------------------------------------------
'//  Netscape Certificate Data Type Object Identifiers
'//--------------------------------------------------------------------------
$szOID_NETSCAPE_DATA_TYPE         = "2.16.840.1.113730.2"
$szOID_NETSCAPE_CERT_SEQUENCE     = "2.16.840.1.113730.2.5"


'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_CERT_TYPE extension
'//
'//  Its value is a bit string. CryptDecodeObject/CryptEncodeObject using
'//  X509_BITS or X509_BITS_WITHOUT_TRAILING_ZEROES.
'//
'//  The following bits are defined:
'//--------------------------------------------------------------------------
%NETSCAPE_SSL_CLIENT_AUTH_CERT_TYPE  = &H80
%NETSCAPE_SSL_SERVER_AUTH_CERT_TYPE  = &H40
%NETSCAPE_SMIME_CERT_TYPE            = &H20
%NETSCAPE_SIGN_CERT_TYPE             = &H10
%NETSCAPE_SSL_CA_CERT_TYPE           = &H04
%NETSCAPE_SMIME_CA_CERT_TYPE         = &H02
%NETSCAPE_SIGN_CA_CERT_TYPE          = &H01

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_BASE_URL extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  When present this string is added to the beginning of all relative URLs
'//  in the certificate.  This extension can be considered an optimization
'//  to reduce the size of the URL extensions.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_REVOCATION_URL extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a relative or absolute URL that can be used to check the
'//  revocation status of a certificate. The revocation check will be
'//  performed as an HTTP GET method using a url that is the concatenation of
'//  revocation-url and certificate-serial-number.
'//  Where the certificate-serial-number is encoded as a string of
'//  ascii hexadecimal digits. For example, if the netscape-base-url is
'//  https://www.certs-r-us.com/, the netscape-revocation-url is
'//  cgi-bin/check-rev.cgi?, and the certificate serial number is 173420,
'//  the resulting URL would be:
'//  https://www.certs-r-us.com/cgi-bin/check-rev.cgi?02a56c
'//
'//  The server should return a document with a Content-Type of
'//  application/x-netscape-revocation.  The document should contain
'//  a single ascii digit, '1' if the certificate is not curently valid,
'//  and '0' if it is curently valid.
'//
'//  Note: for all of the URLs that include the certificate serial number,
'//  the serial number will be encoded as a string which consists of an even
'//  number of hexadecimal digits.  If the number of significant digits is odd,
'//  the string will have a single leading zero to ensure an even number of
'//  digits is generated.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_CA_REVOCATION_URL extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a relative or absolute URL that can be used to check the
'//  revocation status of any certificates that are signed by the CA that
'//  this certificate belongs to. This extension is only valid in CA
'//  certificates.  The use of this extension is the same as the above
'//  szOID_NETSCAPE_REVOCATION_URL extension.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_CERT_RENEWAL_URL extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a relative or absolute URL that points to a certificate renewal
'//  form. The renewal form will be accessed with an HTTP GET method using a
'//  url that is the concatenation of renewal-url and
'//  certificate-serial-number. Where the certificate-serial-number is
'//  encoded as a string of ascii hexadecimal digits. For example, if the
'//  netscape-base-url is https://www.certs-r-us.com/, the
'//  netscape-cert-renewal-url is cgi-bin/check-renew.cgi?, and the
'//  certificate serial number is 173420, the resulting URL would be:
'//  https://www.certs-r-us.com/cgi-bin/check-renew.cgi?02a56c
'//  The document returned should be an HTML form that will allow the user
'//  to request a renewal of their certificate.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_CA_POLICY_URL extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a relative or absolute URL that points to a web page that
'//  describes the policies under which the certificate was issued.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_SSL_SERVER_NAME extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a "shell expression" that can be used to match the hostname of the
'//  SSL server that is using this certificate.  It is recommended that if
'//  the server's hostname does not match this pattern the user be notified
'//  and given the option to terminate the SSL connection.  If this extension
'//  is not present then the CommonName in the certificate subject's
'//  distinguished name is used for the same purpose.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_COMMENT extension
'//
'//  Its value is an IA5_STRING. CryptDecodeObject/CryptEncodeObject using
'//  X509_ANY_STRING or X509_UNICODE_ANY_STRING, where,
'//  dwValueType = CERT_RDN_IA5_STRING.
'//
'//  It is a comment that may be displayed to the user when the certificate
'//  is viewed.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  szOID_NETSCAPE_CERT_SEQUENCE
'//
'//  Its value is a PKCS#7 ContentInfo structure wrapping a sequence of
'//  certificates. The value of the contentType field is
'//  szOID_NETSCAPE_CERT_SEQUENCE, while the content field is the following
'//  structure:
'//      CertificateSequence ::= SEQUENCE OF Certificate.
'//
'//  CryptDecodeObject/CryptEncodeObject using
'//  PKCS_CONTENT_INFO_SEQUENCE_OF_ANY, where,
'//  pszObjId = szOID_NETSCAPE_CERT_SEQUENCE and the CRYPT_DER_BLOBs point
'//  to encoded X509 certificates.
'//--------------------------------------------------------------------------

'//+=========================================================================
'//  Certificate Management Messages over CMS (CMC) Data Structures
'//==========================================================================

'// Content Type (request)
$szOID_CT_PKI_DATA               = "1.3.6.1.5.5.7.12.2"

'// Content Type (response)
$szOID_CT_PKI_RESPONSE           = "1.3.6.1.5.5.7.12.3"

'// Signature value that only contains the hash octets. The parameters for
'// this algorithm must be present and must be encoded as NULL.
$szOID_PKIX_NO_SIGNATURE         = "1.3.6.1.5.5.7.6.2"

$szOID_CMC                       = "1.3.6.1.5.5.7.7"
$szOID_CMC_STATUS_INFO           = "1.3.6.1.5.5.7.7.1"
$szOID_CMC_IDENTIFICATION        = "1.3.6.1.5.5.7.7.2"
$szOID_CMC_IDENTITY_PROOF        = "1.3.6.1.5.5.7.7.3"
$szOID_CMC_DATA_RETURN           = "1.3.6.1.5.5.7.7.4"

'// Transaction Id (integer)
$szOID_CMC_TRANSACTION_ID        = "1.3.6.1.5.5.7.7.5"

'// Sender Nonce (octet string)
$szOID_CMC_SENDER_NONCE          = "1.3.6.1.5.5.7.7.6"

'// Recipient Nonce (octet string)
$szOID_CMC_RECIPIENT_NONCE       = "1.3.6.1.5.5.7.7.7"

$szOID_CMC_ADD_EXTENSIONS        = "1.3.6.1.5.5.7.7.8"
$szOID_CMC_ENCRYPTED_POP         = "1.3.6.1.5.5.7.7.9"
$szOID_CMC_DECRYPTED_POP         = "1.3.6.1.5.5.7.7.10"
$szOID_CMC_LRA_POP_WITNESS       = "1.3.6.1.5.5.7.7.11"

'// Issuer Name + Serial
$szOID_CMC_GET_CERT              = "1.3.6.1.5.5.7.7.15"

'// Issuer Name [+ CRL Name] + Time [+ Reasons]
$szOID_CMC_GET_CRL               = "1.3.6.1.5.5.7.7.16"

'// Issuer Name + Serial [+ Reason] [+ Effective Time] [+ Secret] [+ Comment]
$szOID_CMC_REVOKE_REQUEST        = "1.3.6.1.5.5.7.7.17"

'// (octet string) URL-style parameter list (IA5?)
$szOID_CMC_REG_INFO              = "1.3.6.1.5.5.7.7.18"

$szOID_CMC_RESPONSE_INFO         = "1.3.6.1.5.5.7.7.19"

'// (octet string)
$szOID_CMC_QUERY_PENDING         = "1.3.6.1.5.5.7.7.21"
$szOID_CMC_ID_POP_LINK_RANDOM    = "1.3.6.1.5.5.7.7.22"
$szOID_CMC_ID_POP_LINK_WITNESS   = "1.3.6.1.5.5.7.7.23"

'// optional Name + Integer
$szOID_CMC_ID_CONFIRM_CERT_ACCEPTANCE = "1.3.6.1.5.5.7.7.24"

$szOID_CMC_ADD_ATTRIBUTES        = "1.3.6.1.4.1.311.10.10.1"

'//+-------------------------------------------------------------------------
'//  CMC_DATA
'//  CMC_RESPONSE
'//
'//  Certificate Management Messages over CMS (CMC) PKIData and Response
'//  messages.
'//
'//  For CMC_DATA, pvStructInfo points to a CMC_DATA_INFO.
'//  CMC_DATA_INFO contains optional arrays of tagged attributes, requests,
'//  content info and/or arbitrary other messages.
'//
'//  For CMC_RESPONSE, pvStructInfo points to a CMC_RESPONSE_INFO.
'//  CMC_RESPONSE_INFO is the same as CMC_DATA_INFO without the tagged
'//  requests.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CMC_TAGGED_ATTRIBUTE DWORD
   dwBodyPartID AS DWORD
   Attribute    AS CRYPT_ATTRIBUTE
END TYPE

' // Size = 12 bytes
TYPE CMC_TAGGED_CERT_REQUEST DWORD
   dwBodyPartID      AS DWORD
   SignedCertRequest AS CRYPT_DER_BLOB
END TYPE

'typedef struct _CMC_TAGGED_REQUEST {
'    DWORD               dwTaggedRequestChoice;
'    union {
'        // CMC_TAGGED_CERT_REQUEST_CHOICE
'        PCMC_TAGGED_CERT_REQUEST   pTaggedCertRequest;
'    };
'} CMC_TAGGED_REQUEST, *PCMC_TAGGED_REQUEST;

' // Size = 4 bytes
UNION CMC_TAGGED_REQUEST_UNION DWORD
   pTaggedCertRequest AS CMC_TAGGED_CERT_REQUEST PTR
END UNION

' // Size = 8 bytes
TYPE CMC_TAGGED_REQUEST DWORD
   dwTaggedRequestChoice AS DWORD
   CMC_TAGGED_REQUEST_UNION
END TYPE

%CMC_TAGGED_CERT_REQUEST_CHOICE     = 1

' // Size = 12 bytes
TYPE CMC_TAGGED_CONTENT_INFO DWORD
   dwBodyPartID       AS DWORD
   EncodedContentInfo AS CRYPT_DER_BLOB
END TYPE

' // Size = 16 bytes
TYPE CMC_TAGGED_OTHER_MSG DWORD
   dwBodyPartID AS DWORD              ' DWORD
   pszObjId     AS ASCIIZ PTR         ' LPSTR
   Value        AS CRYPT_OBJID_BLOB   ' CRYPT_OBJID_BLOB
END TYPE

'// All the tagged arrays are optional
' // Size = 32 bytes
TYPE CMC_DATA_INFO DWORD
   cTaggedAttribute    AS DWORD
   rgTaggedAttribute   AS CMC_TAGGED_ATTRIBUTE PTR
   cTaggedRequest      AS DWORD
   rgTaggedRequest     AS CMC_TAGGED_REQUEST PTR
   cTaggedContentInfo  AS DWORD
   rgTaggedContentInfo AS CMC_TAGGED_CONTENT_INFO PTR
   cTaggedOtherMsg     AS DWORD
   rgTaggedOtherMsg    AS CMC_TAGGED_OTHER_MSG PTR
END TYPE

'// All the tagged arrays are optional
' // Size = 24 bytes
TYPE CMC_RESPONSE_INFO DWORD
   cTaggedAttribute    AS DWORD
   rgTaggedAttribute   AS CMC_TAGGED_ATTRIBUTE PTR
   cTaggedContentInfo  AS DWORD
   rgTaggedContentInfo AS CMC_TAGGED_CONTENT_INFO PTR
   cTaggedOtherMsg     AS DWORD
   rgTaggedOtherMsg    AS CMC_TAGGED_OTHER_MSG PTR
END TYPE

'//+-------------------------------------------------------------------------
'//  CMC_STATUS
'//
'//  Certificate Management Messages over CMS (CMC) Status.
'//
'//  pvStructInfo points to a CMC_STATUS_INFO.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CMC_PEND_INFO DWORD
   PendToken AS CRYPT_DATA_BLOB
   PendTime  AS FILETIME
END TYPE

'typedef struct _CMC_STATUS_INFO {
'    DWORD                       dwStatus;
'    DWORD                       cBodyList;
'    DWORD                       *rgdwBodyList;
'    LPWSTR                      pwszStatusString;   // OPTIONAL
'    DWORD                       dwOtherInfoChoice;
'    union  {
'        // CMC_OTHER_INFO_NO_CHOICE
'        //  none
'        // CMC_OTHER_INFO_FAIL_CHOICE
'        DWORD                       dwFailInfo;
'        // CMC_OTHER_INFO_PEND_CHOICE
'        PCMC_PEND_INFO              pPendInfo;
'    };
'} CMC_STATUS_INFO, *PCMC_STATUS_INFO;

' // Size = 4 bytes
UNION CMC_STATUS_INFO_UNION DWORD
   dwFailInfo AS DWORD
   pPendInfo  AS CMC_PEND_INFO PTR
END UNION

' // Size = 24 bytes
TYPE CMC_STATUS_INFO DWORD
   dwStatus          AS DWORD
   cBodyList         AS DWORD
   rgdwBodyList      AS DWORD PTR
   pwszStatusString  AS DWORD
   dwOtherInfoChoice AS DWORD
   CMC_STATUS_INFO_UNION
END TYPE

%CMC_OTHER_INFO_NO_CHOICE   = 0???
%CMC_OTHER_INFO_FAIL_CHOICE = 1???
%CMC_OTHER_INFO_PEND_CHOICE = 2???

'//
'// dwStatus values
'//

'// Request was granted
%CMC_STATUS_SUCCESS          = 0???

'// Request failed, more information elsewhere in the message
%CMC_STATUS_FAILED           = 2???

'// The request body part has not yet been processed. Requester is responsible
'// to poll back. May only be returned for certificate request operations.
%CMC_STATUS_PENDING          = 3???

'// The requested operation is not supported
%CMC_STATUS_NO_SUPPORT       = 4???

'// Confirmation using the idConfirmCertAcceptance control is required
'// before use of certificate
%CMC_STATUS_CONFIRM_REQUIRED = 5???


'//
'// dwFailInfo values
'//

'// Unrecognized or unsupported algorithm
%CMC_FAIL_BAD_ALG            = 0???

'// Integrity check failed
%CMC_FAIL_BAD_MESSAGE_CHECK  = 1???

'// Transaction not permitted or supported
%CMC_FAIL_BAD_REQUEST        = 2???

'// Message time field was not sufficiently close to the system time
%CMC_FAIL_BAD_TIME           = 3???

'// No certificate could be identified matching the provided criteria
%CMC_FAIL_BAD_CERT_ID        = 4???

'// A requested X.509 extension is not supported by the recipient CA.
%CMC_FAIL_UNSUPORTED_EXT     = 5???

'// Private key material must be supplied
%CMC_FAIL_MUST_ARCHIVE_KEYS  = 6???

'// Identification Attribute failed to verify
%CMC_FAIL_BAD_IDENTITY       = 7???

'// Server requires a POP proof before issuing certificate
%CMC_FAIL_POP_REQUIRED       = 8???

'// POP processing failed
%CMC_FAIL_POP_FAILED         = 9???

'// Server policy does not allow key re-use
%CMC_FAIL_NO_KEY_REUSE       = 10???

%CMC_FAIL_INTERNAL_CA_ERROR  = 11???

%CMC_FAIL_TRY_LATER          = 12???


'//+-------------------------------------------------------------------------
'//  CMC_ADD_EXTENSIONS
'//
'//  Certificate Management Messages over CMS (CMC) Add Extensions control
'//  attribute.
'//
'//  pvStructInfo points to a CMC_ADD_EXTENSIONS_INFO.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CMC_ADD_EXTENSIONS_INFO DWORD
   dwCmcDataReference AS DWORD                ' DWORD           dwCmcDataReference
   cCertReference     AS DWORD                ' DWORD           cCertReference
   rgdwCertReference  AS DWORD PTR            ' DWORD           *rgdwCertReference
   cExtension         AS DWORD                ' DWORD           cExtension
   rgExtension        AS CERT_EXTENSION PTR   ' PCERT_EXTENSION rgExtension
END TYPE

'//+-------------------------------------------------------------------------
'//  CMC_ADD_ATTRIBUTES
'//
'//  Certificate Management Messages over CMS (CMC) Add Attributes control
'//  attribute.
'//
'//  pvStructInfo points to a CMC_ADD_ATTRIBUTES_INFO.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CMC_ADD_ATTRIBUTES_INFO DWORD
   dwCmcDataReference AS DWORD                 ' DWORD            dwCmcDataReference
   cCertReference     AS DWORD                 ' DWORD            cCertReference
   rgdwCertReference  AS DWORD PTR             ' DWORD            *rgdwCertReference
   cAttribute         AS DWORD                 ' DWORD            cAttribute
   rgAttribute        AS CRYPT_ATTRIBUTE PTR   ' PCRYPT_ATTRIBUTE rgAttribute
END TYPE

'//+-------------------------------------------------------------------------
'//  X509_CERTIFICATE_TEMPLATE
'//  szOID_CERTIFICATE_TEMPLATE
'//
'//  pvStructInfo points to following CERT_TEMPLATE_EXT data structure.
'//
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_TEMPLATE_EXT DWORD
   pszObjId       AS ASCIIZ PTR   ' LPSTR
   dwMajorVersion AS DWORD        ' DWORD
   fMinorVersion  AS LONG         ' BOOL
   dwMinorVersion AS DWORD        ' DWORD
END TYPE

'//+=========================================================================
'//  Logotype Extension Data Structures
'//
'//  X509_LOGOTYPE_EXT
'//  szOID_LOGOTYPE_EXT
'//
'//  pvStructInfo points to a CERT_LOGOTYPE_EXT_INFO.
'//==========================================================================
' // Size = 24 bytes
TYPE CERT_HASHED_URL DWORD
   HashAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   Hash          AS CRYPT_HASH_BLOB
   pwszUrl       AS WSTRINGZ PTR   ' LPWSTR // Encoded as IA5, Optional for
                                   '        // biometric data
END TYPE

' // Size = 12 bytes
TYPE CERT_LOGOTYPE_DETAILS DWORD
   pwszMimeType AS WSTRINGZ PTR          ' LPWSTR // Encoded as IA5
   cHashedUrl   AS DWORD                 ' DWORD
   rgHashedUrl  AS CERT_HASHED_URL PTR   ' PCERT_HASHED_URL
END TYPE

' // Size = 8 bytes
TYPE CERT_LOGOTYPE_REFERENCE DWORD
   cHashedUrl  AS DWORD                 ' DWORD
   rgHashedUrl AS CERT_HASHED_URL PTR   ' PCERT_HASHED_URL
END TYPE

' // Size = 8 bytes
UNION CERT_LOGOTYPE_IMAGE_INFO_UNION DWORD
   ' // CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE
   ' // No resolution value
   ' // CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE
   dwNumBits   AS DWORD   ' DWORD // Resolution in bits
   ' // CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE
   dwTableSize AS DWORD   ' DWORD // Number of color or grey tones
END UNION

' // Size = 28 bytes
TYPE CERT_LOGOTYPE_IMAGE_INFO DWORD
   ' // CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE or
   ' // CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE
   dwLogotypeImageInfoChoice       AS DWORD          ' DWORD
   dwFileSize                      AS DWORD          ' DWORD // In octets
   dwXSize                         AS DWORD          ' DWORD // Horizontal size in pixels
   dwYSize                         AS DWORD          ' DWORD // Vertical size in pixels
   dwLogotypeImageResolutionChoice AS DWORD          ' DWORD
   CERT_LOGOTYPE_IMAGE_INFO_UNION
   pwszLanguage                    AS WSTRINGZ PTR   ' LPWSTR // Optional. Encoded as IA5.
                                                     '        // RFC 3066 Language Tag
END TYPE

%CERT_LOGOTYPE_GRAY_SCALE_IMAGE_INFO_CHOICE         = 1
%CERT_LOGOTYPE_COLOR_IMAGE_INFO_CHOICE              = 2

%CERT_LOGOTYPE_NO_IMAGE_RESOLUTION_CHOICE           = 0
%CERT_LOGOTYPE_BITS_IMAGE_RESOLUTION_CHOICE         = 1
%CERT_LOGOTYPE_TABLE_SIZE_IMAGE_RESOLUTION_CHOICE   = 2

TYPE CERT_LOGOTYPE_IMAGE
   LogotypeDetails    AS CERT_LOGOTYPE_DETAILS
   pLogotypeImageInfo AS CERT_LOGOTYPE_IMAGE_INFO PTR   ' PCERT_LOGOTYPE_IMAGE_INFO // Optional
END TYPE

' // Size = 20 bytes
TYPE CERT_LOGOTYPE_AUDIO_INFO DWORD
   dwFileSize   AS DWORD          ' DWORD // In octets
   dwPlayTime   AS DWORD          ' DWORD // In milliseconds
   dwChannels   AS DWORD          ' DWORD // 1=mono, 2=stereo, 4=quad
   dwSampleRate AS DWORD          ' DWORD   // Optional. 0 => not present.
                                  '         // Samples per second
   pwszLanguage AS WSTRINGZ PTR   ' LPWSTR // Optional. Encoded as IA5.
                                  '        // RFC 3066 Language Tag
END TYPE

' // Size = 16 bytes
TYPE CERT_LOGOTYPE_AUDIO DWORD
   LogotypeDetails    AS CERT_LOGOTYPE_DETAILS
   pLogotypeAudioInfo AS CERT_LOGOTYPE_AUDIO_INFO PTR   ' PCERT_LOGOTYPE_AUDIO_INFO // Optional
END TYPE

' // Size = 16 bytes
TYPE CERT_LOGOTYPE_DATA DWORD
   cLogotypeImage  AS DWORD                     ' DWORD
   rgLogotypeImage AS CERT_LOGOTYPE_IMAGE PTR   ' PCERT_LOGOTYPE_IMAGE
   cLogotypeAudio  AS DWORD                     ' DWORD
   rgLogotypeAudio AS CERT_LOGOTYPE_AUDIO PTR   ' PCERT_LOGOTYPE_AUDIO
END TYPE

' // Size = 4 bytes
UNION CERT_LOGOTYPE_INFO_UNION DWORD
   ' // CERT_LOGOTYPE_DIRECT_INFO_CHOICE
   pLogotypeDirectInfo   AS CERT_LOGOTYPE_DATA PTR   ' PCERT_LOGOTYPE_DATA
   ' // CERT_LOGOTYPE_INDIRECT_INFO_CHOICE
   pLogotypeIndirectInfo AS CERT_LOGOTYPE_REFERENCE PTR   ' PCERT_LOGOTYPE_REFERENCE
END UNION

' // Size = 8 bytes
TYPE CERT_LOGOTYPE_INFO DWORD
   dwLogotypeInfoChoice AS DWORD   ' DWORD
   CERT_LOGOTYPE_INFO_UNION
END TYPE

%CERT_LOGOTYPE_DIRECT_INFO_CHOICE   = 1
%CERT_LOGOTYPE_INDIRECT_INFO_CHOICE = 2

' // Size = 12 bytes
TYPE CERT_OTHER_LOGOTYPE_INFO DWORD
   pszObjId     AS ASCIIZ PTR   ' LPSTR
   LogotypeInfo AS CERT_LOGOTYPE_INFO
END TYPE

$szOID_LOYALTY_OTHER_LOGOTYPE               = "1.3.6.1.5.5.7.20.1"
$szOID_BACKGROUND_OTHER_LOGOTYPE            = "1.3.6.1.5.5.7.20.2"

' // Size = 24 bytes
TYPE CERT_LOGOTYPE_EXT_INFO DWORD
   cCommunityLogo  AS DWORD                          ' DWORD
   rgCommunityLogo AS CERT_LOGOTYPE_INFO PTR         ' PCERT_LOGOTYPE_INFO
   pIssuerLogo     AS CERT_LOGOTYPE_INFO PTR         ' PCERT_LOGOTYPE_INFO // Optional
   pSubjectLogo    AS CERT_LOGOTYPE_INFO PTR         ' PCERT_LOGOTYPE_INFO // Optional
   cOtherLogo      AS DWORD                          ' DWORD
   rgOtherLogo     AS CERT_OTHER_LOGOTYPE_INFO PTR   ' PCERT_OTHER_LOGOTYPE_INFO
END TYPE


'//+=========================================================================
'//  Biometric Extension Data Structures
'//
'//  X509_BIOMETRIC_EXT
'//  szOID_BIOMETRIC_EXT
'//
'//  pvStructInfo points to following CERT_BIOMETRIC_EXT_INFO data structure.
'//==========================================================================

' // Size = 4 bytes
UNION CERT_BIOMETRIC_DATA_UNION DWORD
   ' // CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE
   dwPredefined AS DWORD   ' DWORD
   ' // CERT_BIOMETRIC_OID_DATA_CHOICE
   pszObjId     AS ASCIIZ PTR   ' LPSTR
END UNION

' // Size = 32 bytes
TYPE CERT_BIOMETRIC_DATA DWORD
   dwTypeOfBiometricDataChoice AS DWORD   ' DWORD
   CERT_BIOMETRIC_DATA_UNION
   HashedUrl AS CERT_HASHED_URL   ' // pwszUrl is Optional.
END TYPE

%CERT_BIOMETRIC_PREDEFINED_DATA_CHOICE  = 1
%CERT_BIOMETRIC_OID_DATA_CHOICE         = 2

%CERT_BIOMETRIC_PICTURE_TYPE            = 0
%CERT_BIOMETRIC_SIGNATURE_TYPE          = 1

' // Size = 8 bytes
TYPE CERT_BIOMETRIC_EXT_INFO DWORD
   cBiometricData  AS DWORD                     ' DWORD
   rgBiometricData AS CERT_BIOMETRIC_DATA PTR   ' PCERT_BIOMETRIC_DATA
END TYPE



'//+=========================================================================
'//  Online Certificate Status Protocol (OCSP) Data Structures
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  OCSP_SIGNED_REQUEST
'//
'//  OCSP signed request.
'//
'//  Note, in most instances, pOptionalSignatureInfo will be NULL indicating
'//  no signature is present.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE OCSP_SIGNATURE_INFO DWORD
   SignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   Signature          AS CRYPT_BIT_BLOB
   cCertEncoded       AS DWORD           ' DWORD
   rgCertEncoded      AS CERT_BLOB PTR   ' PCERT_BLOB
END TYPE

' // Size = 12 bytes
TYPE OCSP_SIGNED_REQUEST_INFO DWORD
   ToBeSigned             AS CRYPT_DER_BLOB            ' // Encoded OCSP_REQUEST
   pOptionalSignatureInfo AS OCSP_SIGNATURE_INFO PTR   ' POCSP_SIGNATURE_INFO // NULL, no signature
END TYPE

'//+-------------------------------------------------------------------------
'//  OCSP_REQUEST
'//
'//  ToBeSigned OCSP request.
'//--------------------------------------------------------------------------

' // Size = 36 bytes
TYPE OCSP_CERT_ID DWORD
   HashAlgorithm  AS CRYPT_ALGORITHM_IDENTIFIER   ' // Normally SHA1
   IssuerNameHash AS CRYPT_HASH_BLOB              ' // Hash of encoded name
   IssuerKeyHash  AS CRYPT_HASH_BLOB              ' // Hash of PublicKey bits
   SerialNumber   AS CRYPT_INTEGER_BLOB
END TYPE

' // Size = 44 bytes
TYPE OCSP_REQUEST_ENTRY DWORD
   CertId      AS OCSP_CERT_ID
   cExtension  AS DWORD                ' DWORD
   rgExtension AS CERT_EXTENSION PTR   ' PCERT_EXTENSION
END TYPE

' // Size = 24 bytes
TYPE OCSP_REQUEST_INFO DWORD
   dwVersion      AS DWORD                      ' DWORD
   pRequestorName AS CERT_ALT_NAME_ENTRY PTR    ' PCERT_ALT_NAME_ENTRY // OPTIONAL
   cRequestEntry  AS DWORD                      ' DWORD
   rgRequestEntry AS OCSP_REQUEST_ENTRY PTR     ' POCSP_REQUEST_ENTRY
   cExtension     AS DWORD                      ' DWORD
   rgExtension    AS CERT_EXTENSION PTR         ' PCERT_EXTENSION
END TYPE

%OCSP_REQUEST_V1    = 0

'//+-------------------------------------------------------------------------
'//  OCSP_RESPONSE
'//
'//  OCSP outer, unsigned response wrapper.
'//--------------------------------------------------------------------------
' // Size = 16 bytes
TYPE OCSP_RESPONSE_INFO DWORD
   dwStatus AS DWORD              ' DWORD
   pszObjId AS ASCIIZ PTR         ' LPSTR // OPTIONAL, may be NULL
   Value    AS CRYPT_OBJID_BLOB   ' // OPTIONAL
END TYPE

%OCSP_SUCCESSFUL_RESPONSE           = 0
%OCSP_MALFORMED_REQUEST_RESPONSE    = 1
%OCSP_INTERNAL_ERROR_RESPONSE       = 2
%OCSP_TRY_LATER_RESPONSE            = 3
'// 4 is not used
%OCSP_SIG_REQUIRED_RESPONSE         = 5
%OCSP_UNAUTHORIZED_RESPONSE         = 6

$szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE   = "1.3.6.1.5.5.7.48.1.1"

'//+-------------------------------------------------------------------------
'//  OCSP_BASIC_SIGNED_RESPONSE
'//  szOID_PKIX_OCSP_BASIC_SIGNED_RESPONSE
'//
'//  OCSP basic signed response.
'//--------------------------------------------------------------------------
' // Size = 40 bytes
TYPE OCSP_BASIC_SIGNED_RESPONSE_INFO DWORD
   ToBeSigned    AS CRYPT_DER_BLOB   ' // Encoded OCSP_BASIC_RESPONSE
   SignatureInfo AS OCSP_SIGNATURE_INFO
END TYPE

'//+-------------------------------------------------------------------------
'//  OCSP_BASIC_RESPONSE
'//
'//  ToBeSigned OCSP basic response.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE OCSP_BASIC_REVOKED_INFO DWORD
   RevocationDate  AS FILETIME
   ' // See X509_CRL_REASON_CODE for list of reason codes
   dwCrlReasonCode AS DWORD   ' DWORD
END TYPE

' // Size = 4 bytes
UNION OCSP_BASIC_RESPONSE_ENTRY_UNION DWORD
   ' // OCSP_BASIC_GOOD_CERT_STATUS
   ' // OCSP_BASIC_UNKNOWN_CERT_STATUS
   ' //  No additional information
   ' // OCSP_BASIC_REVOKED_CERT_STATUS
   pRevokedInfo AS OCSP_BASIC_REVOKED_INFO PTR   ' POCSP_BASIC_REVOKED_INFO
END UNION

' // Size = 68 bytes
TYPE OCSP_BASIC_RESPONSE_ENTRY DWORD
   CertId       AS OCSP_CERT_ID
   dwCertStatus AS DWORD                ' DWORD
   OCSP_BASIC_RESPONSE_ENTRY_UNION
   ThisUpdate   AS FILETIME
   NextUpdate   AS FILETIME             ' // Optional, zero filetime implies never expires
   cExtension   AS DWORD                ' DWORD
   rgExtension  AS CERT_EXTENSION PTR   ' PCERT_EXTENSION
END TYPE

%OCSP_BASIC_GOOD_CERT_STATUS        = 0
%OCSP_BASIC_REVOKED_CERT_STATUS     = 1
%OCSP_BASIC_UNKNOWN_CERT_STATUS     = 2

' // Size = 8 bytes
UNION OCSP_BASIC_RESPONSE_INFO_UNION DWORD
   ' // OCSP_BASIC_BY_NAME_RESPONDER_ID
   ByNameResponderId AS CERT_NAME_BLOB
   ' // OCSP_BASIC_BY_KEY_RESPONDER_ID
   ByKeyResponderId AS CRYPT_HASH_BLOB
END UNION

' // Size = 40 bytes
TYPE OCSP_BASIC_RESPONSE_INFO DWORD
   dwVersion           AS DWORD                           ' DWORD
   dwResponderIdChoice AS DWORD                           ' DWORD
   OCSP_BASIC_RESPONSE_INFO_UNION
   ProducedAt          AS FILETIME
   cResponseEntry      AS DWORD                           ' DWORD
   rgResponseEntry     AS OCSP_BASIC_RESPONSE_ENTRY PTR   ' POCSP_BASIC_RESPONSE_ENTRY
   cExtension          AS DWORD                           ' DWORD
   rgExtension         AS CERT_EXTENSION PTR              ' PCERT_EXTENSION
END TYPE

%OCSP_BASIC_RESPONSE_V1 = 0

%OCSP_BASIC_BY_NAME_RESPONDER_ID = 1
%OCSP_BASIC_BY_KEY_RESPONDER_ID  = 2

'//+=========================================================================
'//  Object IDentifier (OID) Installable Functions:  Data Structures and APIs
'//==========================================================================

'typedef void *HCRYPTOIDFUNCSET;
'typedef void *HCRYPTOIDFUNCADDR;

'// Predefined OID Function Names
$CRYPT_OID_ENCODE_OBJECT_FUNC        = "CryptDllEncodeObject"
$CRYPT_OID_DECODE_OBJECT_FUNC        = "CryptDllDecodeObject"
$CRYPT_OID_ENCODE_OBJECT_EX_FUNC     = "CryptDllEncodeObjectEx"
$CRYPT_OID_DECODE_OBJECT_EX_FUNC     = "CryptDllDecodeObjectEx"
$CRYPT_OID_CREATE_COM_OBJECT_FUNC    = "CryptDllCreateCOMObject"
$CRYPT_OID_VERIFY_REVOCATION_FUNC    = "CertDllVerifyRevocation"
$CRYPT_OID_VERIFY_CTL_USAGE_FUNC     = "CertDllVerifyCTLUsage"
$CRYPT_OID_FORMAT_OBJECT_FUNC        = "CryptDllFormatObject"
$CRYPT_OID_FIND_OID_INFO_FUNC        = "CryptDllFindOIDInfo"
$CRYPT_OID_FIND_LOCALIZED_NAME_FUNC  = "CryptDllFindLocalizedName"


'// CryptDllEncodeObject has same function signature as CryptEncodeObject.

'// CryptDllDecodeObject has same function signature as CryptDecodeObject.

'// CryptDllEncodeObjectEx has same function signature as CryptEncodeObjectEx.
'// The Ex version MUST support the CRYPT_ENCODE_ALLOC_FLAG option.
'//
'// If an Ex function isn't installed or registered, then, attempts to find
'// a non-EX version. If the ALLOC flag is set, then, CryptEncodeObjectEx,
'// does the allocation and calls the non-EX version twice.

'// CryptDllDecodeObjectEx has same function signature as CryptDecodeObjectEx.
'// The Ex version MUST support the CRYPT_DECODE_ALLOC_FLAG option.
'//
'// If an Ex function isn't installed or registered, then, attempts to find
'// a non-EX version. If the ALLOC flag is set, then, CryptDecodeObjectEx,
'// does the allocation and calls the non-EX version twice.

'// CryptDllCreateCOMObject has the following signature:
'//      BOOL WINAPI CryptDllCreateCOMObject(
'//          IN DWORD dwEncodingType,
'//          IN LPCSTR pszOID,
'//          IN PCRYPT_DATA_BLOB pEncodedContent,
'//          IN DWORD dwFlags,
'//          IN REFIID riid,
'//          OUT void **ppvObj);

'// CertDllVerifyRevocation has the same signature as CertVerifyRevocation
'//  (See CertVerifyRevocation for details on when called)

'// CertDllVerifyCTLUsage has the same signature as CertVerifyCTLUsage

'// CryptDllFindOIDInfo currently is only used to store values used by
'// CryptFindOIDInfo. See CryptFindOIDInfo() for more details.

'// CryptDllFindLocalizedName is only used to store localized string
'// values used by CryptFindLocalizedName. See CryptFindLocalizedName() for
'// more details.

'//  Example of a complete OID Function Registry Name:
'//    HKEY_LOCAL_MACHINE\Software\Microsoft\Cryptography\OID
'//      Encoding Type 1\CryptDllEncodeObject\1.2.3
'//
'//  The key's L"Dll" value contains the name of the Dll.
'//  The key's L"FuncName" value overrides the default function name
$CRYPT_OID_REGPATH = "Software\Microsoft\Cryptography\OID"
$CRYPT_OID_REG_ENCODING_TYPE_PREFIX      = "EncodingType "
'#define CRYPT_OID_REG_DLL_VALUE_NAME        L"Dll"
$CRYPT_OID_REG_DLL_VALUE_NAME            = "Dll"
'#define CRYPT_OID_REG_FUNC_NAME_VALUE_NAME  L"FuncName"
$CRYPT_OID_REG_FUNC_NAME_VALUE_NAME_A    = "FuncName"

'// CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG can be set in the key's L"CryptFlags"
'// value to register the functions before the installed functions.
'//
'// CryptSetOIDFunctionValue must be called to set this value. L"CryptFlags"
'// must be set using a dwValueType of REG_DWORD.
' Must be Unicode
$CRYPT_OID_REG_FLAGS_VALUE_NAME      = "CryptFlags"

'// OID used for Default OID functions
$CRYPT_DEFAULT_OID                   = "DEFAULT"

' // Size = 8 bytes
TYPE CRYPT_OID_FUNC_ENTRY DWORD
   pszOID     AS ASCIIZ PTR   ' LPCSTR
   pvFuncAddr AS DWORD        ' void*
END TYPE

%CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG = 1???


'//+-------------------------------------------------------------------------
'//  Install a set of callable OID function addresses.
'//
'//  By default the functions are installed at end of the list.
'//  Set CRYPT_INSTALL_OID_FUNC_BEFORE_FLAG to install at beginning of list.
'//
'//  hModule should be updated with the hModule passed to DllMain to prevent
'//  the Dll containing the function addresses from being unloaded by
'//  CryptGetOIDFuncAddress/CryptFreeOIDFunctionAddress. This would be the
'//  case when the Dll has also regsvr32'ed OID functions via
'//  CryptRegisterOIDFunction.
'//
'//  DEFAULT functions are installed by setting rgFuncEntry[].pszOID =
'//  CRYPT_DEFAULT_OID.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptInstallOIDFunctionAddress IMPORT "CRYPT32.DLL" ALIAS "CryptInstallOIDFunctionAddress" ( _
   BYVAL hModule AS DWORD _                             ' __in HMODULE hModule
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYVAL cFuncEntry AS DWORD _                          ' __in DWORD cFuncEntry
 , BYREF rgFuncEntry AS CRYPT_OID_FUNC_ENTRY _          ' __in const CRYPT_OID_FUNC_ENTRY rgFuncEntry[]
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Initialize and return handle to the OID function set identified by its
'//  function name.
'//
'//  If the set already exists, a handle to the existing set is returned.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptInitOIDFunctionSet IMPORT "CRYPT32.DLL" ALIAS "CryptInitOIDFunctionSet" ( _
   BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HCRYPTOIDFUNCSET

'//+-------------------------------------------------------------------------
'//  Search the list of installed functions for an encoding type and OID match.
'//  If not found, search the registry.
'//
'//  For success, returns TRUE with *ppvFuncAddr updated with the function's
'//  address and *phFuncAddr updated with the function address's handle.
'//  The function's handle is AddRef'ed. CryptFreeOIDFunctionAddress needs to
'//  be called to release it.
'//
'//  For a registry match, the Dll containing the function is loaded.
'//
'//  By default, both the registered and installed function lists are searched.
'//  Set CRYPT_GET_INSTALLED_OID_FUNC_FLAG to only search the installed list
'//  of functions. This flag would be set by a registered function to get
'//  the address of a pre-installed function it was replacing. For example,
'//  the registered function might handle a new special case and call the
'//  pre-installed function to handle the remaining cases.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetOIDFunctionAddress IMPORT "CRYPT32.DLL" ALIAS "CryptGetOIDFunctionAddress" ( _
   BYVAL hFuncSet AS DWORD _                            ' __in HCRYPTOIDFUNCSET hFuncSet
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF ppvFuncAddr AS DWORD _                         ' __out void **ppvFuncAddr
 , BYREF phFuncAddr AS DWORD _                          ' __out HCRYPTOIDFUNCADDR *phFuncAddr
 ) AS LONG                                              ' BOOL

%CRYPT_GET_INSTALLED_OID_FUNC_FLAG       = &H1???


'//+-------------------------------------------------------------------------
'//  Get the list of registered default Dll entries for the specified
'//  function set and encoding type.
'//
'//  The returned list consists of none, one or more null terminated Dll file
'//  names. The list is terminated with an empty (L"\0") Dll file name.
'//  For example: L"first.dll" L"\0" L"second.dll" L"\0" L"\0"
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetDefaultOIDDllList IMPORT "CRYPT32.DLL" ALIAS "CryptGetDefaultOIDDllList" ( _
   BYVAL hFuncSet AS DWORD _                            ' __in HCRYPTOIDFUNCSET hFuncSet
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pwszDllList AS ANY _                           ' __out LPWSTR pwszDllList
 , BYREF pcchDllList AS DWORD _                         ' __inout DWORD *pcchDllList
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Either: get the first or next installed DEFAULT function OR
'//  load the Dll containing the DEFAULT function.
'//
'//  If pwszDll is NULL, search the list of installed DEFAULT functions.
'//  *phFuncAddr must be set to NULL to get the first installed function.
'//  Successive installed functions are returned by setting *phFuncAddr
'//  to the hFuncAddr returned by the previous call.
'//
'//  If pwszDll is NULL, the input *phFuncAddr
'//  is always CryptFreeOIDFunctionAddress'ed by this function, even for
'//  an error.
'//
'//  If pwszDll isn't NULL, then, attempts to load the Dll and the DEFAULT
'//  function. *phFuncAddr is ignored upon entry and isn't
'//  CryptFreeOIDFunctionAddress'ed.
'//
'//  For success, returns TRUE with *ppvFuncAddr updated with the function's
'//  address and *phFuncAddr updated with the function address's handle.
'//  The function's handle is AddRef'ed. CryptFreeOIDFunctionAddress needs to
'//  be called to release it or CryptGetDefaultOIDFunctionAddress can also
'//  be called for a NULL pwszDll.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetDefaultOIDFunctionAddress IMPORT "CRYPT32.DLL" ALIAS "CryptGetDefaultOIDFunctionAddress" ( _
   BYVAL hFuncSet AS DWORD _                            ' __in HCRYPTOIDFUNCSET hFuncSet
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pwszDll AS WSTRINGZ _                          ' __in_opt LPCWSTR pwszDll
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF ppvFuncAddr AS DWORD _                         ' __out void **ppvFuncAddr
 , BYREF phFuncAddr AS DWORD _                          ' __inout HCRYPTOIDFUNCADDR *phFuncAddr
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Releases the handle AddRef'ed and returned by CryptGetOIDFunctionAddress
'//  or CryptGetDefaultOIDFunctionAddress.
'//
'//  If a Dll was loaded for the function its unloaded. However, before doing
'//  the unload, the DllCanUnloadNow function exported by the loaded Dll is
'//  called. It should return S_FALSE to inhibit the unload or S_TRUE to enable
'//  the unload. If the Dll doesn't export DllCanUnloadNow, the Dll is unloaded.
'//
'//  DllCanUnloadNow has the following signature:
'//      STDAPI  DllCanUnloadNow(void);
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptFreeOIDFunctionAddress IMPORT "CRYPT32.DLL" ALIAS "CryptFreeOIDFunctionAddress" ( _
   BYVAL hFuncAddr AS DWORD _                           ' __in HCRYPTOIDFUNCADDR hFuncAddr
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Register the Dll containing the function to be called for the specified
'//  encoding type, function name and OID.
'//
'//  pwszDll may contain environment-variable strings
'//  which are ExpandEnvironmentStrings()'ed before loading the Dll.
'//
'//  In addition to registering the DLL, you may override the
'//  name of the function to be called. For example,
'//      pszFuncName = "CryptDllEncodeObject",
'//      pszOverrideFuncName = "MyEncodeXyz".
'//  This allows a Dll to export multiple OID functions for the same
'//  function name without needing to interpose its own OID dispatcher function.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptRegisterOIDFunction IMPORT "CRYPT32.DLL" ALIAS "CryptRegisterOIDFunction" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
 , OPTIONAL BYREF pwszDll AS WSTRINGZ _                 ' __in_opt LPCWSTR pwszDll
 , OPTIONAL BYREF pszOverrideFuncName AS ASCIIZ _       ' __in_opt LPCSTR pszOverrideFuncName
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Unregister the Dll containing the function to be called for the specified
'//  encoding type, function name and OID.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptUnregisterOIDFunction IMPORT "CRYPT32.DLL" ALIAS "CryptUnregisterOIDFunction" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Register the Dll containing the default function to be called for the
'//  specified encoding type and function name.
'//
'//  Unlike CryptRegisterOIDFunction, you can't override the function name
'//  needing to be exported by the Dll.
'//
'//  The Dll is inserted before the entry specified by dwIndex.
'//    dwIndex == 0, inserts at the beginning.
'//    dwIndex == CRYPT_REGISTER_LAST_INDEX, appends at the end.
'//
'//  pwszDll may contain environment-variable strings
'//  which are ExpandEnvironmentStrings()'ed before loading the Dll.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptRegisterDefaultOIDFunction IMPORT "CRYPT32.DLL" ALIAS "CryptRegisterDefaultOIDFunction" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pwszDll AS WSTRINGZ _                          ' __in LPCWSTR pwszDll
 ) AS LONG                                              ' BOOL

%CRYPT_REGISTER_FIRST_INDEX   = 0???
%CRYPT_REGISTER_LAST_INDEX    = &HFFFFFFFF???

'//+-------------------------------------------------------------------------
'//  Unregister the Dll containing the default function to be called for
'//  the specified encoding type and function name.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptUnregisterDefaultOIDFunction IMPORT "CRYPT32.DLL" ALIAS "CryptUnregisterDefaultOIDFunction" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYREF pwszDll AS WSTRINGZ _                          ' __in LPCWSTR pwszDll
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Set the value for the specified encoding type, function name, OID and
'//  value name.
'//
'//  See RegSetValueEx for the possible value types.
'//
'//  String types are UNICODE.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptSetOIDFunctionValue IMPORT "CRYPT32.DLL" ALIAS "CryptSetOIDFunctionValue" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
 , BYREF pwszValueName AS WSTRINGZ _                    ' __in LPCWSTR pwszValueName
 , BYVAL dwValueType AS DWORD _                         ' __in DWORD dwValueType
 , BYVAL pbValueData AS BYTE PTR _                      ' __in const BYTE *pbValueData
 , BYVAL cbValueData AS DWORD _                         ' __in DWORD cbValueData
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get the value for the specified encoding type, function name, OID and
'//  value name.
'//
'//  See RegEnumValue for the possible value types.
'//
'//  String types are UNICODE.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetOIDFunctionValue IMPORT "CRYPT32.DLL" ALIAS "CryptGetOIDFunctionValue" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
 , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
 , BYREF pwszValueName AS WSTRINGZ _                    ' __in LPCWSTR pwszValueName
 , BYREF pdwValueType AS DWORD _                        ' __out DWORD *pdwValueType
 , BYVAL pbValueData AS BYTE PTR _                      ' __out BYTE *pbValueData
 , BYREF pcbValueData AS DWORD _                        ' __inout DWORD *pcbValueData
 ) AS LONG                                              ' BOOL

'typedef BOOL (WINAPI *PFN_CRYPT_ENUM_OID_FUNC)(
'    IN DWORD dwEncodingType,
'    IN LPCSTR pszFuncName,
'    IN LPCSTR pszOID,
'    IN DWORD cValue,
'    IN const DWORD rgdwValueType[],
'    IN LPCWSTR const rgpwszValueName[],
'    IN const BYTE * const rgpbValueData[],
'    IN const DWORD rgcbValueData[],
'    IN void *pvArg
'    );

'FUNCTION CRYPT_ENUM_OID_FUNC ( _
'   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
' , BYREF pszFuncName AS ASCIIZ _                        ' __in LPCSTR pszFuncName
' , BYREF pszOID AS ASCIIZ _                             ' __in LPCSTR pszOID
' , BYVAL cValue AS DWORD _                              ' __in DWORD cValue
' , BYVAL rgdwValueType AS DWORD _                       ' __in const DWORD rgdwValueType[]
' , BYREF rgpwszValueName AS WSTRINGZ _                  ' __in LPCWSTR const rgpwszValueName[]
' , BYVAL rgpbValueData AS DWORD _                       ' __in const BYTE * const rgpbValueData[]
' , BYVAL rgcbValueData AS DWORD _                       ' __in const DWORD rgcbValueData[]
' , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
' ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Enumerate the OID functions identified by their encoding type,
'//  function name and OID.
'//
'//  pfnEnumOIDFunc is called for each registry key matching the input
'//  parameters. Setting dwEncodingType to CRYPT_MATCH_ANY_ENCODING_TYPE matches
'//  any. Setting pszFuncName or pszOID to NULL matches any.
'//
'//  Set pszOID == CRYPT_DEFAULT_OID to restrict the enumeration to only the
'//  DEFAULT functions
'//
'//  String types are UNICODE.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptEnumOIDFunction LIB "Crypt32.dll" _
    ALIAS "CryptEnumOIDFunction" (BYVAL dwEncodingType AS DWORD, _
    pszFuncName AS ASCIIZ, pszOID AS ASCIIZ, BYVAL dwFlags AS DWORD, _
    pvArg AS DWORD, pfnEnumOIDFunc AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptEnumOIDFunction IMPORT "CRYPT32.DLL" ALIAS "CryptEnumOIDFunction" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYREF pszFuncName AS ASCIIZ _                        ' __in_opt LPCSTR pszFuncName
 , BYREF pszOID AS ASCIIZ _                             ' __in_opt LPCSTR pszOID
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
 , BYVAL pfnEnumOIDFunc AS DWORD _                      ' __in PFN_CRYPT_ENUM_OID_FUNC pfnEnumOIDFunc
 ) AS LONG                                              ' BOOL
#ENDIF

%CRYPT_MATCH_ANY_ENCODING_TYPE   = &HFFFFFFFF???


'//+=========================================================================
'//  Object IDentifier (OID) Information:  Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Special ALG_ID's used in CRYPT_OID_INFO
'//--------------------------------------------------------------------------
'// Algorithm is only implemented in CNG.
%CALG_OID_INFO_CNG_ONLY                   = &HFFFFFFFF???

'// Algorithm is defined in the encoded parameters. Only supported
'// using CNG.
%CALG_OID_INFO_PARAMETERS                 = &HFFFFFFFE???

'// Macro to check for a special ALG_ID used in CRYPT_OID_INFO
'#define IS_SPECIAL_OID_INFO_ALGID(Algid)        (Algid >= CALG_OID_INFO_PARAMETERS)
MACRO IS_SPECIAL_OID_INFO_ALGID(Algid) = (Algid >= %CALG_OID_INFO_PARAMETERS)


'//+-------------------------------------------------------------------------
'// Special CNG Algorithms used in CRYPT_OID_INFO
'//--------------------------------------------------------------------------
$$CRYPT_OID_INFO_HASH_PARAMETERS_ALGORITHM     = "CryptOIDInfoHashParameters"$$
$$CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM      = "CryptOIDInfoECCParameters"$$
$$CRYPT_OID_INFO_MGF1_PARAMETERS_ALGORITHM     = "CryptOIDInfoMgf1Parameters"$$
$$CRYPT_OID_INFO_NO_SIGN_ALGORITHM             = "CryptOIDInfoNoSign"$$
$$CRYPT_OID_INFO_OAEP_PARAMETERS_ALGORITHM     = "CryptOIDInfoOAEPParameters"$$
$$CRYPT_OID_INFO_ECC_WRAP_PARAMETERS_ALGORITHM = "CryptOIDInfoECCWrapParameters"$$

'//+-------------------------------------------------------------------------
'//  OID Information
'//--------------------------------------------------------------------------
'typedef struct _CRYPT_OID_INFO {
'    DWORD           cbSize;
'    LPCSTR          pszOID;
'    LPCWSTR         pwszName;
'    DWORD           dwGroupId;
'    union {
'        DWORD       dwValue;
'        ALG_ID      Algid;
'        DWORD       dwLength;
'    };
'    CRYPT_DATA_BLOB ExtraInfo;
'} CRYPT_OID_INFO, *PCRYPT_OID_INFO;
'typedef const CRYPT_OID_INFO CCRYPT_OID_INFO, *PCCRYPT_OID_INFO;

' // Size = 4 bytes
UNION CRYPT_OID_INFO_UNION DWORD
   dwValue  AS DWORD
   Algid    AS DWORD
   dwLength AS DWORD
END UNION

' // Size = 28 bytes
TYPE CRYPT_OID_INFO DWORD
   cbSize    AS DWORD
   pszOID    AS ASCIIZ PTR
   pwszName  AS WSTRINGZ PTR
   dwGroupId AS DWORD
   CRYPT_OID_INFO_UNION
   ExtraInfo AS CRYPT_DATA_BLOB
#IF %DEF(%CRYPT_OID_INFO_HAS_EXTRA_FIELDS)
   ' // Note, if you #define CRYPT_OID_INFO_HAS_EXTRA_FIELDS, then, you
   ' // must zero all unused fields in this data structure.
   ' // More fields could be added in a future release.
   ' // The following 2 fields are set to an empty string, L"", if not defined.
   ' // This is the Algid string passed to the BCrypt* and NCrypt* APIs
   ' // defined in bcrypt.h and ncrypt.h.
   ' //
   ' // Its only applicable to the following groups:
   ' //  CRYPT_HASH_ALG_OID_GROUP_ID
   ' //  CRYPT_ENCRYPT_ALG_OID_GROUP_ID
   ' //  CRYPT_PUBKEY_ALG_OID_GROUP_ID
   ' //  CRYPT_SIGN_ALG_OID_GROUP_ID
   pwszCNGAlgid AS WTRINGZ PTR   ' LPCWSTR
   ' // Following is only applicable to the following groups:
   ' //  CRYPT_SIGN_ALG_OID_GROUP_ID
   ' //      The public key pwszCNGAlgid. For ECC,
   ' //      CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM.
   ' //  CRYPT_PUBKEY_ALG_OID_GROUP_ID
   ' //      For the ECC algorithms, CRYPT_OID_INFO_ECC_PARAMETERS_ALGORITHM.
   pwszCNGExtraAlgid AS WTRINGZ PTR   ' LPCWSTR
#ENDIF
END TYPE

'//+-------------------------------------------------------------------------
'//  OID Group IDs
'//--------------------------------------------------------------------------
%CRYPT_HASH_ALG_OID_GROUP_ID            = 1
%CRYPT_ENCRYPT_ALG_OID_GROUP_ID         = 2
%CRYPT_PUBKEY_ALG_OID_GROUP_ID          = 3
%CRYPT_SIGN_ALG_OID_GROUP_ID            = 4
%CRYPT_RDN_ATTR_OID_GROUP_ID            = 5
%CRYPT_EXT_OR_ATTR_OID_GROUP_ID         = 6
%CRYPT_ENHKEY_USAGE_OID_GROUP_ID        = 7
%CRYPT_POLICY_OID_GROUP_ID              = 8
%CRYPT_TEMPLATE_OID_GROUP_ID            = 9
%CRYPT_KDF_OID_GROUP_ID                 = 10
%CRYPT_LAST_OID_GROUP_ID                = 10

%CRYPT_FIRST_ALG_OID_GROUP_ID           = %CRYPT_HASH_ALG_OID_GROUP_ID
%CRYPT_LAST_ALG_OID_GROUP_ID            = %CRYPT_SIGN_ALG_OID_GROUP_ID


'// The CRYPT_*_ALG_OID_GROUP_ID's have an Algid. The CRYPT_RDN_ATTR_OID_GROUP_ID
'// has a dwLength. The CRYPT_EXT_OR_ATTR_OID_GROUP_ID,
'// CRYPT_ENHKEY_USAGE_OID_GROUP_ID, CRYPT_POLICY_OID_GROUP_ID or
'// CRYPT_TEMPLATE_OID_GROUP_ID don't have a dwValue.
'//

'// CRYPT_PUBKEY_ALG_OID_GROUP_ID has the following optional ExtraInfo:
'//  DWORD[0] - Flags. CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG can be set to
'//             inhibit the reformatting of the signature before
'//             CryptVerifySignature is called or after CryptSignHash
'//             is called. CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG can
'//             be set to include the public key algorithm's parameters
'//             in the PKCS7's digestEncryptionAlgorithm's parameters.
'//             CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG can be set to omit
'//             NULL parameters when encoding.

%CRYPT_OID_INHIBIT_SIGNATURE_FORMAT_FLAG  = &H1???
%CRYPT_OID_USE_PUBKEY_PARA_FOR_PKCS7_FLAG = &H2???
%CRYPT_OID_NO_NULL_ALGORITHM_PARA_FLAG    = &H4???

%CRYPT_OID_PUBKEY_SIGN_ONLY_FLAG          = &H80000000???
%CRYPT_OID_PUBKEY_ENCRYPT_ONLY_FLAG       = &H40000000???

'// CRYPT_SIGN_ALG_OID_GROUP_ID has the following optional ExtraInfo:
'//  DWORD[0] - Public Key Algid.
'//  DWORD[1] - Flags. Same as above for CRYPT_PUBKEY_ALG_OID_GROUP_ID.
'//  DWORD[2] - Optional CryptAcquireContext(CRYPT_VERIFYCONTEXT)'s dwProvType.
'//             If omitted or 0, uses Public Key Algid to select
'//             appropriate dwProvType for signature verification.

'// CRYPT_RDN_ATTR_OID_GROUP_ID has the following optional ExtraInfo:
'//  Array of DWORDs:
'//   [0 ..] - Null terminated list of acceptable RDN attribute
'//            value types. An empty list implies CERT_RDN_PRINTABLE_STRING,
'//            CERT_RDN_UNICODE_STRING, 0.

'//+-------------------------------------------------------------------------
'//  Find OID information. Returns NULL if unable to find any information
'//  for the specified key and group. Note, returns a pointer to a constant
'//  data structure. The returned pointer MUST NOT be freed.
'//
'//  dwKeyType's:
'//    CRYPT_OID_INFO_OID_KEY, pvKey points to a szOID
'//    CRYPT_OID_INFO_NAME_KEY, pvKey points to a wszName
'//    CRYPT_OID_INFO_ALGID_KEY, pvKey points to an ALG_ID
'//    CRYPT_OID_INFO_SIGN_KEY, pvKey points to an array of two ALG_ID's:
'//      ALG_ID[0] - Hash Algid
'//      ALG_ID[1] - PubKey Algid
'//
'//  Setting dwGroupId to 0, searches all groups according to the dwKeyType.
'//  Otherwise, only the dwGroupId is searched.
'//--------------------------------------------------------------------------
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptFindOIDInfo LIB "Crypt32.dll" ALIAS "CryptFindOIDInfo" _
    (BYVAL dwKeyType AS DWORD, pvKey AS DWORD, BYVAL dwGroupId AS DWORD) _
    AS DWORD
#ELSE
DECLARE FUNCTION CryptFindOIDInfo IMPORT "CRYPT32.DLL" ALIAS "CryptFindOIDInfo" ( _
   BYVAL dwKeyType AS DWORD _                           ' __in DWORD dwKeyType
 , BYVAL pvKey AS DWORD _                               ' __in void *pvKey
 , BYVAL dwGroupId AS DWORD _                           ' __in DWORD dwGroupId
 ) AS DWORD                                             ' PCCRYPT_OID_INFO
#ENDIF

%CRYPT_OID_INFO_OID_KEY          = 1???
%CRYPT_OID_INFO_NAME_KEY         = 2???
%CRYPT_OID_INFO_ALGID_KEY        = 3???
%CRYPT_OID_INFO_SIGN_KEY         = 4???
%CRYPT_OID_INFO_CNG_ALGID_KEY    = 5???
%CRYPT_OID_INFO_CNG_SIGN_KEY     = 6???

'// Set the following in the above dwKeyType parameter to restrict public keys
'// valid for signing or encrypting
%CRYPT_OID_INFO_OID_KEY_FLAGS_MASK           = &HFFFF0000???
%CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG         = &H80000000???
%CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG      = &H40000000???

'// The following flag can be set in above dwGroupId parameter to disable
'// searching the directory server
%CRYPT_OID_DISABLE_SEARCH_DS_FLAG            = &H80000000???

'#ifdef CRYPT_OID_INFO_HAS_EXTRA_FIELDS

'// The following flag can be set in above dwGroupId parameter to search
'// through CRYPT_OID_INFO records. If there are multiple records that meet
'// the search criteria, the first record with defined pwszCNGAlgid would be
'// returned. If none of the records (meeting the search criteria) have
'// pwszCNGAlgid defined, first record (meeting the search criteria) would be
'// returned.
%CRYPT_OID_PREFER_CNG_ALGID_FLAG            = &H40000000???

'#endif

'// The bit length shifted left 16 bits can be OR'ed into the above
'// dwGroupId parameter. Only applicable to the CRYPT_ENCRYPT_ALG_OID_GROUP_ID.
'// Also, only applicable to encryption algorithms having a dwBitLen ExtraInfo.
'// Currently, only the AES encryption algorithms have this.
'//
'// For example, to find the OIDInfo for BCRYPT_AES_ALGORITHM, bit length 192,
'// CryptFindOIDInfo would be called as follows:
'//  PCCRYPT_OID_INFO pOIDInfo =
'//      CryptFindOIDInfo(
'//          CRYPT_OID_INFO_CNG_ALGID_KEY,
'//          (void *) BCRYPT_AES_ALGORITHM,
'//          CRYPT_ENCRYPT_ALG_OID_GROUP_ID |
'//              (192 << CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT)
'//          );

%CRYPT_OID_INFO_OID_GROUP_BIT_LEN_MASK       = &H0FFF0000???
%CRYPT_OID_INFO_OID_GROUP_BIT_LEN_SHIFT      = 16???

'//+-------------------------------------------------------------------------
'//  Register OID information. The OID information specified in the
'//  CCRYPT_OID_INFO structure is persisted to the registry.
'//
'//  crypt32.dll contains information for the commonly known OIDs. This function
'//  allows applications to augment crypt32.dll's OID information. During
'//  CryptFindOIDInfo's first call, the registered OID information is installed.
'//
'//  By default the registered OID information is installed after crypt32.dll's
'//  OID entries. Set CRYPT_INSTALL_OID_INFO_BEFORE_FLAG to install before.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptRegisterOIDInfo IMPORT "CRYPT32.DLL" ALIAS "CryptRegisterOIDInfo" ( _
   BYREF pInfo AS CRYPT_OID_INFO _                      ' __in PCCRYPT_OID_INFO pInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

%CRYPT_INSTALL_OID_INFO_BEFORE_FLAG = 1???

'//+-------------------------------------------------------------------------
'//  Unregister OID information. Only the pszOID and dwGroupId fields are
'//  used to identify the OID information to be unregistered.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptUnregisterOIDInfo IMPORT "CRYPT32.DLL" ALIAS "CryptUnregisterOIDInfo" ( _
   BYREF pInfo AS CRYPT_OID_INFO _                      ' __in PCCRYPT_OID_INFO pInfo
 ) AS LONG                                              ' BOOL

'// If the callback returns FALSE, stops the enumeration.
'typedef BOOL (WINAPI *PFN_CRYPT_ENUM_OID_INFO)(
'    IN PCCRYPT_OID_INFO pInfo,
'    IN void *pvArg
'    );

'FUNCTION CRYPT_ENUM_OID_INFO ( _
'   BYREF pInfo AS CCRYPT_OID_INFO, _                    ' __in PCCRYPT_OID_INFO pInfo
'   BYVAL pvArg AS DWORD _                               ' __in void *pvArg
' ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Enumerate the OID information.
'//
'//  pfnEnumOIDInfo is called for each OID information entry.
'//
'//  Setting dwGroupId to 0 matches all groups. Otherwise, only enumerates
'//  entries in the specified group.
'//
'//  dwFlags currently isn't used and must be set to 0.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptEnumOIDInfo LIB "Crypt32.dll" ALIAS "CryptEnumOIDInfo" _
    (BYVAL dwGroupId AS DWORD, BYVAL dwFlags AS DWORD, pvArg AS DWORD, _
    pfnEnumOIDInfo AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION CryptEnumOIDInfo IMPORT "CRYPT32.DLL" ALIAS "CryptEnumOIDInfo" ( _
   BYVAL dwGroupId AS DWORD _                           ' __in DWORD dwGroupId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
 , BYVAL pfnEnumOIDInfo AS DWORD _                      ' __in PFN_CRYPT_ENUM_OID_INFO pfnEnumOIDInfo
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Find the localized name for the specified name. For example, find the
'//  localized name for the "Root" system store name. A case insensitive
'//  string comparison is done.
'//
'//  Returns NULL if unable to find the the specified name.
'//
'//  Localized names for the predefined system stores ("Root", "My") and
'//  predefined physical stores (".Default", ".LocalMachine") are pre-installed
'//  as resource strings in crypt32.dll. CryptSetOIDFunctionValue can be called
'//  as follows to register additional localized strings:
'//      dwEncodingType = CRYPT_LOCALIZED_NAME_ENCODING_TYPE
'//      pszFuncName = CRYPT_OID_FIND_LOCALIZED_NAME_FUNC
'//      pszOID = CRYPT_LOCALIZED_NAME_OID
'//      pwszValueName = Name to be localized, for example, L"ApplicationStore"
'//      dwValueType = REG_SZ
'//      pbValueData = pointer to the UNICODE localized string
'//      cbValueData = (wcslen(UNICODE localized string) + 1) * sizeof(WCHAR)
'//
'//  To unregister, set pbValueData to NULL and cbValueData to 0.
'//
'//  The registered names are searched before the pre-installed names.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptFindLocalizedName IMPORT "CRYPT32.DLL" ALIAS "CryptFindLocalizedName" ( _
   BYREF pwszCryptName AS WSTRINGZ _                    ' __in LPCWSTR pwszCryptName
 ) AS DWORD                                             ' LPCWSTR

%CRYPT_LOCALIZED_NAME_ENCODING_TYPE = 0
$CRYPT_LOCALIZED_NAME_OID           = "LocalizedNames"

'//+=========================================================================
'//  Low Level Cryptographic Message Data Structures and APIs
'//==========================================================================

'typedef void *HCRYPTMSG;

$szOID_PKCS_7_DATA               = "1.2.840.113549.1.7.1"
$szOID_PKCS_7_SIGNED             = "1.2.840.113549.1.7.2"
$szOID_PKCS_7_ENVELOPED          = "1.2.840.113549.1.7.3"
$szOID_PKCS_7_SIGNEDANDENVELOPED = "1.2.840.113549.1.7.4"
$szOID_PKCS_7_DIGESTED           = "1.2.840.113549.1.7.5"
$szOID_PKCS_7_ENCRYPTED          = "1.2.840.113549.1.7.6"

$szOID_PKCS_9_CONTENT_TYPE       = "1.2.840.113549.1.9.3"
$szOID_PKCS_9_MESSAGE_DIGEST     = "1.2.840.113549.1.9.4"

'//+-------------------------------------------------------------------------
'//  Message types
'//--------------------------------------------------------------------------
%CMSG_DATA                   = 1
%CMSG_SIGNED                 = 2
%CMSG_ENVELOPED              = 3
%CMSG_SIGNED_AND_ENVELOPED   = 4
%CMSG_HASHED                 = 5
%CMSG_ENCRYPTED              = 6

'//+-------------------------------------------------------------------------
'//  Message Type Bit Flags
'//--------------------------------------------------------------------------
'#define CMSG_ALL_FLAGS                   (~0UL)
'#define CMSG_DATA_FLAG                   (1 << CMSG_DATA)
'#define CMSG_SIGNED_FLAG                 (1 << CMSG_SIGNED)
'#define CMSG_ENVELOPED_FLAG              (1 << CMSG_ENVELOPED)
'#define CMSG_SIGNED_AND_ENVELOPED_FLAG   (1 << CMSG_SIGNED_AND_ENVELOPED)
'#define CMSG_HASHED_FLAG                 (1 << CMSG_HASHED)
'#define CMSG_ENCRYPTED_FLAG              (1 << CMSG_ENCRYPTED)

%CMSG_ALL_FLAGS                 = &HFFFFFFFF???
%CMSG_DATA_FLAG                 = &H00000002???
%CMSG_SIGNED_FLAG               = &H00000004???
%CMSG_ENVELOPED_FLAG            = &H00000008???
%CMSG_SIGNED_AND_ENVELOPED_FLAG = &H00000010???
%CMSG_HASHED_FLAG               = &H00000020???
%CMSG_ENCRYPTED_FLAG            = &H00000040???

'//+-------------------------------------------------------------------------
'//  Certificate Issuer and SerialNumber
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CERT_ISSUER_SERIAL_NUMBER DWORD
   Issuer       AS CERT_NAME_BLOB
   SerialNumber AS CRYPT_INTEGER_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate Identifier
'//--------------------------------------------------------------------------
'typedef struct _CERT_ID {
'    DWORD   dwIdChoice;
'    union {
'        // CERT_ID_ISSUER_SERIAL_NUMBER
'        CERT_ISSUER_SERIAL_NUMBER   IssuerSerialNumber;
'        // CERT_ID_KEY_IDENTIFIER
'        CRYPT_HASH_BLOB             KeyId;
'        // CERT_ID_SHA1_HASH
'        CRYPT_HASH_BLOB             HashId;
'    };
'} CERT_ID, *PCERT_ID;

' // Size = 16 bytes
UNION CERT_ID_UNION DWORD
   IssuerSerialNumber AS CERT_ISSUER_SERIAL_NUMBER
   KeyId              AS CRYPT_HASH_BLOB
   HashId             AS CRYPT_HASH_BLOB
END UNION

' // Size = 20 bytes
TYPE CERT_ID DWORD
   dwIdChoice AS DWORD
   CERT_ID_UNION
END TYPE

%CERT_ID_ISSUER_SERIAL_NUMBER = 1
%CERT_ID_KEY_IDENTIFIER       = 2
%CERT_ID_SHA1_HASH            = 3


'//+-------------------------------------------------------------------------
'//  The message encode information (pvMsgEncodeInfo) is message type dependent
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_DATA: pvMsgEncodeInfo = NULL
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNED
'//
'//  The pCertInfo in the CMSG_SIGNER_ENCODE_INFO provides the Issuer, SerialNumber
'//  and PublicKeyInfo.Algorithm. The PublicKeyInfo.Algorithm implicitly
'//  specifies the HashEncryptionAlgorithm to be used.
'//
'//  If the SignerId is present with a nonzero dwIdChoice its used instead
'//  of the Issuer and SerialNumber in pCertInfo.
'//
'//  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs. PKCS #7
'//  version 1.5 only supports the ISSUER_SERIAL_NUMBER CERT_ID choice.
'//
'//  If HashEncryptionAlgorithm is present and not NULL its used instead of
'//  the PublicKeyInfo.Algorithm.
'//
'//  Note, for RSA, the hash encryption algorithm is normally the same as
'//  the public key algorithm. For DSA, the hash encryption algorithm is
'//  normally a DSS signature algorithm.
'//
'//  pvHashEncryptionAuxInfo currently isn't used and must be set to NULL if
'//  present in the data structure.
'//
'//  The hCryptProv and dwKeySpec specify the private key to use. If dwKeySpec
'//  == 0, then, defaults to AT_SIGNATURE.
'//
'//  If the HashEncryptionAlgorithm is set to szOID_PKIX_NO_SIGNATURE, then,
'//  the signature value only contains the hash octets. hCryptProv must still
'//  be specified. However, since a private key isn't used the hCryptProv can be
'//  acquired using CRYPT_VERIFYCONTEXT.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), the signer hCryptProv's are released.
'//
'//  pvHashAuxInfo currently isn't used and must be set to NULL.
'//
'//  CMS signed messages allow the inclusion of Attribute Certs.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_SIGNER_ENCODE_INFO {
'    DWORD                       cbSize;
'    PCERT_INFO                  pCertInfo;
'    HCRYPTPROV                  hCryptProv;
'    DWORD                       dwKeySpec;
'    CRYPT_ALGORITHM_IDENTIFIER  HashAlgorithm;
'    void                        *pvHashAuxInfo;
'    DWORD                       cAuthAttr;
'    PCRYPT_ATTRIBUTE            rgAuthAttr;
'    DWORD                       cUnauthAttr;
'    PCRYPT_ATTRIBUTE            rgUnauthAttr;

'#ifdef CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS
'    CERT_ID                     SignerId;
'    CRYPT_ALGORITHM_IDENTIFIER  HashEncryptionAlgorithm;
'    void                        *pvHashEncryptionAuxInfo;
'#endif
'} CMSG_SIGNER_ENCODE_INFO, *PCMSG_SIGNER_ENCODE_INFO;

UNION CMSG_SIGNER_ENCODE_INFO_UNION
    hCryptProv AS DWORD   ' HCRYPTPROV
    hNCryptKey AS DWORD   ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 48 bytes
TYPE CMSG_SIGNER_ENCODE_INFO DWORD
   cbSize                  AS DWORD
   pCertInfo               AS CERT_INFO PTR
   CMSG_SIGNER_ENCODE_INFO_UNION
   dwKeySpec               AS DWORD
   HashAlgorithm           AS CRYPT_ALGORITHM_IDENTIFIER
   pvHashAuxInfo           AS DWORD
   cAuthAttr               AS DWORD
   rgAuthAttr              AS CRYPT_ATTRIBUTE PTR
   cUnauthAttr             AS DWORD
   rgUnauthAttr            AS CRYPT_ATTRIBUTE PTR
#IF %DEF(%CMSG_SIGNER_ENCODE_INFO_HAS_CMS_FIELDS)
   SignerId                AS CERT_ID
   HashEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvHashEncryptionAuxInfo AS DWORD
#ENDIF
END TYPE

'typedef struct _CMSG_SIGNED_ENCODE_INFO {
'    DWORD                       cbSize;
'    DWORD                       cSigners;
'    PCMSG_SIGNER_ENCODE_INFO    rgSigners;
'    DWORD                       cCertEncoded;
'    PCERT_BLOB                  rgCertEncoded;
'    DWORD                       cCrlEncoded;
'    PCRL_BLOB                   rgCrlEncoded;

'#ifdef CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS
'    DWORD                       cAttrCertEncoded;
'    PCERT_BLOB                  rgAttrCertEncoded;
'#endif
'} CMSG_SIGNED_ENCODE_INFO, *PCMSG_SIGNED_ENCODE_INFO;

' // Size = 28 bytes
TYPE CMSG_SIGNED_ENCODE_INFO DWORD
   cbSize             AS DWORD
   cSigners           AS DWORD
   rgSigners          AS CMSG_SIGNER_ENCODE_INFO PTR
   cCertEncoded       AS DWORD
   rgCertEncoded      AS CERT_BLOB PTR
   cCrlEncoded        AS DWORD
   rgCrlEncoded       AS CRL_BLOB PTR
#IF %DEF(%CMSG_SIGNED_ENCODE_INFO_HAS_CMS_FIELDS)
   cAttrCertEncoded   AS DWORD
   rgAttrCertEncoded  AS CERT_BLOB PTR
#ENDIF
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_ENVELOPED
'//
'//  The PCERT_INFO for the rgRecipients provides the Issuer, SerialNumber
'//  and PublicKeyInfo. The PublicKeyInfo.Algorithm implicitly
'//  specifies the KeyEncryptionAlgorithm to be used.
'//
'//  The PublicKeyInfo.PublicKey in PCERT_INFO is used to encrypt the content
'//  encryption key for the recipient.
'//
'//  hCryptProv is used to do the content encryption, recipient key encryption
'//  and export. The hCryptProv's private keys aren't used. If hCryptProv
'//  is NULL, a default hCryptProv is chosen according to the
'//  ContentEncryptionAlgorithm and the first recipient KeyEncryptionAlgorithm.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), the envelope's hCryptProv is released.
'//
'//  Note: CAPI currently doesn't support more than one KeyEncryptionAlgorithm
'//  per provider. This will need to be fixed.
'//
'//  Currently, pvEncryptionAuxInfo is only defined for RC2 or RC4 encryption
'//  algorithms. Otherwise, its not used and must be set to NULL.
'//  See CMSG_RC2_AUX_INFO for the RC2 encryption algorithms.
'//  See CMSG_RC4_AUX_INFO for the RC4 encryption algorithms.
'//
'//  To enable SP3 compatible encryption, pvEncryptionAuxInfo should point to
'//  a CMSG_SP3_COMPATIBLE_AUX_INFO data structure.
'//
'//  To enable the CMS envelope enhancements, rgpRecipients must be set to
'//  NULL, and rgCmsRecipients updated to point to an array of
'//  CMSG_RECIPIENT_ENCODE_INFO's.
'//
'//  Also, CMS envelope enhancements support the inclusion of a bag of
'//  Certs, CRLs, Attribute Certs and/or Unprotected Attributes.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_RECIPIENT_ENCODE_INFO CMSG_RECIPIENT_ENCODE_INFO,
'    *PCMSG_RECIPIENT_ENCODE_INFO;

' Note: Defined after CMSG_RECIPIENT_ENCODE_INFO because of forward reference.

'typedef struct _CMSG_ENVELOPED_ENCODE_INFO {
'    DWORD                       cbSize;
'    HCRYPTPROV                  hCryptProv;
'    CRYPT_ALGORITHM_IDENTIFIER  ContentEncryptionAlgorithm;
'    void                        *pvEncryptionAuxInfo;
'    DWORD                       cRecipients;

''    // The following array may only be used for transport recipients identified
''    // by their IssuereAndSerialNumber. If rgpRecipients != NULL, then,
''    // the rgCmsRecipients must be NULL.
'    PCERT_INFO                  *rgpRecipients;

'#ifdef CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS
'    // If rgCmsRecipients != NULL, then, the above rgpRecipients must be
'    // NULL.
'    PCMSG_RECIPIENT_ENCODE_INFO rgCmsRecipients;
'    DWORD                       cCertEncoded;
'    PCERT_BLOB                  rgCertEncoded;
'    DWORD                       cCrlEncoded;
'    PCRL_BLOB                   rgCrlEncoded;
'    DWORD                       cAttrCertEncoded;
'    PCERT_BLOB                  rgAttrCertEncoded;
'    DWORD                       cUnprotectedAttr;
'    PCRYPT_ATTRIBUTE            rgUnprotectedAttr;
'#endif
'} CMSG_ENVELOPED_ENCODE_INFO, *PCMSG_ENVELOPED_ENCODE_INFO;

' // Size = 32 bytes
TYPE CMSG_ENVELOPED_ENCODE_INFO DWORD
   cbSize                     AS DWORD   ' DWORD
   hCryptProv                 AS DWORD   ' HCRYPTPROV_LEGACY
   ContentEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvEncryptionAuxInfo        AS DWORD   ' void *
   cRecipients                AS DWORD   ' DWORD
   ' // The following array may only be used for transport recipients identified
   ' // by their IssuereAndSerialNumber. If rgpRecipients != NULL, then,
   ' // the rgCmsRecipients must be NULL.
   rgpRecipients              AS CERT_INFO PTR   ' PCERT_INFO *
#IF %DEF(%CMSG_ENVELOPED_ENCODE_INFO_HAS_CMS_FIELDS)
   ' // If rgCmsRecipients != NULL, then, the above rgpRecipients must be
   ' // NULL.
   rgCmsRecipients            AS CMSG_RECIPIENT_ENCODE_INFO PTR   ' PCMSG_RECIPIENT_ENCODE_INFO
   cCertEncoded               AS DWORD                  ' DWORD
   rgCertEncoded              AS CERT_BLOB PTR          ' PCERT_BLOB
   cCrlEncoded                AS DWORD                  ' DWORD
   rgCrlEncoded               AS CRL_BLOB PTR           ' PCRL_BLOB
   cAttrCertEncoded           AS DWORD                  ' DWORD
   rgAttrCertEncoded          AS CERT_BLOB PTR          ' PCERT_BLOB
   cUnprotectedAttr           AS DWORD                  ' DWORD
   rgUnprotectedAttr          AS PCRYPT_ATTRIBUTE PTR   ' PCRYPT_ATTRIBUTE
#ENDIF
END TYPE

'//+-------------------------------------------------------------------------
'//  Key Transport Recipient Encode Info
'//
'//  hCryptProv is used to do the recipient key encryption
'//  and export. The hCryptProv's private keys aren't used.
'//
'//  If hCryptProv is NULL, then, the hCryptProv specified in
'//  CMSG_ENVELOPED_ENCODE_INFO is used.
'//
'//  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
'//
'//  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs. PKCS #7
'//  version 1.5 only supports the ISSUER_SERIAL_NUMBER CERT_ID choice.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO {
'    DWORD                       cbSize;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
'    void                        *pvKeyEncryptionAuxInfo;
'    HCRYPTPROV                  hCryptProv;
'    CRYPT_BIT_BLOB              RecipientPublicKey;
'    CERT_ID                     RecipientId;
'} CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO;

' // Size = 56 bytes
TYPE CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO DWORD
   cbSize                 AS DWORD
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyEncryptionAuxInfo AS DWORD
   hCryptProv             AS DWORD
   RecipientPublicKey     AS CRYPT_BIT_BLOB
   RecipientId            AS CERT_ID
END TYPE

'//+-------------------------------------------------------------------------
'//  Key Agreement Recipient Encode Info
'//
'//  If hCryptProv is NULL, then, the hCryptProv specified in
'//  CMSG_ENVELOPED_ENCODE_INFO is used.
'//
'//  For the CMSG_KEY_AGREE_STATIC_KEY_CHOICE, both the hCryptProv and
'//  dwKeySpec must be specified to select the sender's private key.
'//
'//  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
'//
'//  CMS supports the KEY_IDENTIFIER and ISSUER_SERIAL_NUMBER CERT_IDs.
'//
'//  There is 1 key choice, ephemeral originator. The originator's ephemeral
'//  key is generated using the public key algorithm parameters shared
'//  amongst all the recipients.
'//
'//  There are 2 key choices: ephemeral originator or static sender. The
'//  originator's ephemeral key is generated using the public key algorithm
'//  parameters shared amongst all the recipients. For the static sender its
'//  private key is used. The hCryptProv and dwKeySpec specify the private key.
'//  The pSenderId identifies the certificate containing the sender's public key.
'//
'//  Currently, pvKeyEncryptionAuxInfo isn't used and must be set to NULL.
'//
'//  If KeyEncryptionAlgorithm.Parameters.cbData == 0, then, its Parameters
'//  are updated with the encoded KeyWrapAlgorithm.
'//
'//  Currently, pvKeyWrapAuxInfo is only defined for algorithms with
'//  RC2. Otherwise, its not used and must be set to NULL.
'//  When set for RC2 algorithms, points to a CMSG_RC2_AUX_INFO containing
'//  the RC2 effective key length.
'//
'//  Note, key agreement recipients are not supported in PKCS #7 version 1.5.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO {
'    DWORD                       cbSize;
'    CRYPT_BIT_BLOB              RecipientPublicKey;
'    CERT_ID                     RecipientId;

''    // Following fields are optional and only applicable to KEY_IDENTIFIER
''    // CERT_IDs.
'    FILETIME                    Date;
'    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
'} CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO,
'    *PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO;

' // Size = 48 bytes
TYPE CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO DWORD
   cbSize             AS DWORD
   RecipientPublicKey AS CRYPT_BIT_BLOB
   RecipientId        AS CERT_ID
   ' // Following fields are optional and only applicable to KEY_IDENTIFIER
   ' / CERT_IDs.
   Date               AS FILETIME
   pOtherAttr         AS CRYPT_ATTRIBUTE_TYPE_VALUE PTR
END TYPE

'typedef struct _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO {
'    DWORD                       cbSize;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
'    void                        *pvKeyEncryptionAuxInfo;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyWrapAlgorithm;
'    void                        *pvKeyWrapAuxInfo;

''    // The following hCryptProv and dwKeySpec must be specified for the
''    // CMSG_KEY_AGREE_STATIC_KEY_CHOICE.
''    //
''    // For CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE, dwKeySpec isn't applicable
''    // and hCryptProv is optional.
'    HCRYPTPROV                  hCryptProv;
'    DWORD                       dwKeySpec;

'    DWORD                       dwKeyChoice;
'    union {
''        // CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE
''        //
''        // The ephemeral public key algorithm and parameters.
'        PCRYPT_ALGORITHM_IDENTIFIER pEphemeralAlgorithm;

''        // CMSG_KEY_AGREE_STATIC_KEY_CHOICE
''        //
''        // The CertId of the sender's certificate
'        PCERT_ID                    pSenderId;
'    };
'    CRYPT_DATA_BLOB             UserKeyingMaterial;     // OPTIONAL

'    DWORD                                       cRecipientEncryptedKeys;
'    PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO   *rgpRecipientEncryptedKeys;
'} CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO;

' // Size = 4 bytes
UNION CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO_UNION DWORD
   pEphemeralAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER PTR
   pSenderId AS CERT_ID PTR
END UNION

' // Size = 68 bytes
TYPE CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO DWORD
   cbSize                    AS DWORD
   KeyEncryptionAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyEncryptionAuxInfo    AS DWORD
   KeyWrapAlgorithm          AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyWrapAuxInfo          AS DWORD
   hCryptProv                AS DWORD
   dwKeySpec                 AS DWORD
   dwKeyChoice               AS DWORD
   CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO_UNION
   UserKeyingMaterial        AS CRYPT_DATA_BLOB
   cRecipientEncryptedKeys   AS DWORD
   rgpRecipientEncryptedKeys AS CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO PTR
END TYPE

%CMSG_KEY_AGREE_EPHEMERAL_KEY_CHOICE = 1???
%CMSG_KEY_AGREE_STATIC_KEY_CHOICE    = 2???

'//+-------------------------------------------------------------------------
'//  Mail List Recipient Encode Info
'//
'//  There is 1 choice for the KeyEncryptionKey: an already created CSP key
'//  handle. For the key handle choice, hCryptProv must be nonzero. This key
'//  handle isn't destroyed.
'//
'//  Note, even if CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), this hCryptProv isn't released.
'//
'//  Currently, pvKeyEncryptionAuxInfo is only defined for RC2 key wrap
'//  algorithms. Otherwise, its not used and must be set to NULL.
'//  When set for RC2 algorithms, points to a CMSG_RC2_AUX_INFO containing
'//  the RC2 effective key length.
'//
'//  Note, mail list recipients are not supported in PKCS #7 version 1.5.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO {
'    DWORD                       cbSize;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
'    void                        *pvKeyEncryptionAuxInfo;
'    HCRYPTPROV                  hCryptProv;
'    DWORD                       dwKeyChoice;
'    union {
'        // CMSG_MAIL_LIST_HANDLE_KEY_CHOICE
'        HCRYPTKEY                   hKeyEncryptionKey;
'        // Reserve space for a potential pointer choice
'        void                        *pvKeyEncryptionKey;
'    };
'    CRYPT_DATA_BLOB             KeyId;

'    // Following fields are optional.
'    FILETIME                    Date;
'    PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
'} CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, *PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO;

' // Size = 4 bytes
UNION CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO_UNION DWORD
   hKeyEncryptionKey AS DWORD
   pvKeyEncryptionKey AS DWORD
END UNION

' // Size = 52 bytes
TYPE CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO DWORD
   cbSize                 AS DWORD
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvKeyEncryptionAuxInfo AS DWORD
   hCryptProv             AS DWORD
   dwKeyChoice            AS DWORD
   CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO_UNION
   KeyId                  AS CRYPT_DATA_BLOB
   ' // Following fields are optional.
   Date                   AS FILETIME
   pOtherAttr             AS CRYPT_ATTRIBUTE_TYPE_VALUE PTR
END TYPE

%CMSG_MAIL_LIST_HANDLE_KEY_CHOICE = 1???

'//+-------------------------------------------------------------------------
'//  Recipient Encode Info
'//
'//  Note, only key transport recipients are supported in PKCS #7 version 1.5.
'//--------------------------------------------------------------------------
'struct _CMSG_RECIPIENT_ENCODE_INFO {
'    DWORD   dwRecipientChoice;
'    union {
'        // CMSG_KEY_TRANS_RECIPIENT
'        PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO   pKeyTrans;
'        // CMSG_KEY_AGREE_RECIPIENT
'        PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO   pKeyAgree;
'        // CMSG_MAIL_LIST_RECIPIENT
'        PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO   pMailList;
'    };
'};

' // Size = 4 bytes
UNION CMSG_RECIPIENT_ENCODE_INFO_UNION DWORD
   pKeyTrans AS CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO PTR
   pKeyAgree AS CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO PTR
   pMailList AS CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO PTR
END UNION

' // Size = 8 bytes
TYPE CMSG_RECIPIENT_ENCODE_INFO DWORD
   dwRecipientChoice AS DWORD
   CMSG_RECIPIENT_ENCODE_INFO_UNION
END TYPE

%CMSG_KEY_TRANS_RECIPIENT = 1???
%CMSG_KEY_AGREE_RECIPIENT = 2???
%CMSG_MAIL_LIST_RECIPIENT = 3???

'//+-------------------------------------------------------------------------
'//  CMSG_RC2_AUX_INFO
'//
'//  AuxInfo for RC2 encryption algorithms. The pvEncryptionAuxInfo field
'//  in CMSG_ENCRYPTED_ENCODE_INFO should be updated to point to this
'//  structure. If not specified, defaults to 40 bit.
'//
'//  Note, this AuxInfo is only used when, the ContentEncryptionAlgorithm's
'//  Parameter.cbData is zero. Otherwise, the Parameters is decoded to
'//  get the bit length.
'//
'//  If CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG is set in dwBitLen, then, SP3
'//  compatible encryption is done and the bit length is ignored.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CMSG_RC2_AUX_INFO DWORD
   cbSize   AS DWORD   ' DWORD
   dwBitLen AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_SP3_COMPATIBLE_AUX_INFO
'//
'//  AuxInfo for enabling SP3 compatible encryption.
'//
'//  The CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG is set in dwFlags to enable SP3
'//  compatible encryption. When set, uses zero salt instead of no salt,
'//  the encryption algorithm parameters are NULL instead of containing the
'//  encoded RC2 parameters or encoded IV octet string and the encrypted
'//  symmetric key is encoded little endian instead of big endian.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CMSG_SP3_COMPATIBLE_AUX_INFO DWORD
   cbSize  AS DWORD   ' DWORD
   dwFlags AS DWORD   ' DWORD
END TYPE

%CMSG_SP3_COMPATIBLE_ENCRYPT_FLAG    = &H80000000???

'//+-------------------------------------------------------------------------
'//  CMSG_RC4_AUX_INFO
'//
'//  AuxInfo for RC4 encryption algorithms. The pvEncryptionAuxInfo field
'//  in CMSG_ENCRYPTED_ENCODE_INFO should be updated to point to this
'//  structure. If not specified, uses the CSP's default bit length with no
'//  salt. Note, the base CSP has a 40 bit default and the enhanced CSP has
'//  a 128 bit default.
'//
'//  If CMSG_RC4_NO_SALT_FLAG is set in dwBitLen, then, no salt is generated.
'//  Otherwise, (128 - dwBitLen)/8 bytes of salt are generated and encoded
'//  as an OCTET STRING in the algorithm parameters field.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CMSG_RC4_AUX_INFO DWORD
   cbSize   AS DWORD   ' DWORD
   dwBitLen AS DWORD   ' DWORD
END TYPE

%CMSG_RC4_NO_SALT_FLAG               = &H40000000???

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNED_AND_ENVELOPED
'//
'//  For PKCS #7, a signed and enveloped message doesn't have the
'//  signer's authenticated or unauthenticated attributes. Otherwise, a
'//  combination of the CMSG_SIGNED_ENCODE_INFO and CMSG_ENVELOPED_ENCODE_INFO.
'//--------------------------------------------------------------------------

' // Size = 64 bytes
TYPE CMSG_SIGNED_AND_ENVELOPED_ENCODE_INFO DWORD
   cbSize        AS DWORD
   SignedInfo    AS CMSG_SIGNED_ENCODE_INFO
   EnvelopedInfo AS CMSG_ENVELOPED_ENCODE_INFO
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_HASHED
'//
'//  hCryptProv is used to do the hash. Doesn't need to use a private key.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags
'//  passed to CryptMsgOpenToEncode(), the hCryptProv is released.
'//
'//  If fDetachedHash is set, then, the encoded message doesn't contain
'//  any content (its treated as NULL Data)
'//
'//  pvHashAuxInfo currently isn't used and must be set to NULL.
'//--------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CMSG_HASHED_ENCODE_INFO DWORD
   cbSize        AS DWORD                        ' DWORD
   hCryptProv    AS DWORD                        ' HCRYPTPROV
   HashAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   pvHashAuxInfo AS DWORD                        ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_ENCRYPTED
'//
'//  The key used to encrypt the message is identified outside of the message
'//  content (for example, password).
'//
'//  The content input to CryptMsgUpdate has already been encrypted.
'//
'//  pvEncryptionAuxInfo currently isn't used and must be set to NULL.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CMSG_ENCRYPTED_ENCODE_INFO DWORD
   cbSize                     AS DWORD                        ' DWORD
   ContentEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   pvEncryptionAuxInfo        AS DWORD                        ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  This parameter allows messages to be of variable length with streamed
'//  output.
'//
'//  By default, messages are of a definite length and
'//  CryptMsgGetParam(CMSG_CONTENT_PARAM) is
'//  called to get the cryptographically processed content. Until closed,
'//  the handle keeps a copy of the processed content.
'//
'//  With streamed output, the processed content can be freed as its streamed.
'//
'//  If the length of the content to be updated is known at the time of the
'//  open, then, ContentLength should be set to that length. Otherwise, it
'//  should be set to CMSG_INDEFINITE_LENGTH.
'//--------------------------------------------------------------------------
'typedef BOOL (WINAPI *PFN_CMSG_STREAM_OUTPUT)(
'    IN const void *pvArg,
'    IN BYTE *pbData,
'    IN DWORD cbData,
'    IN BOOL fFinal
'    );

'FUNCTION CMSG_STREAM_OUTPUT ( _
'   BYVAL pvArg AS DWORD, _                 ' __in const void *pvArg
'   BYVAL pbData AS BYTE PTR, _             ' __in BYTE *pbData
'   BYVAL cbData AS DWORD, _                ' __in DWORD cbData
'   BYVAL fFinal AS LONG _                  ' __in BOOL fFinal
' ) AS LONG                                 ' BOOL

%CMSG_INDEFINITE_LENGTH       = &HFFFFFFFF???

' // Size = 12 bytes
TYPE CMSG_STREAM_INFO DWORD
   cbContent       AS DWORD   ' DWORD
   pfnStreamOutput AS DWORD   ' PFN_CMSG_STREAM_OUTPUT
   pvArg           AS DWORD   ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  Open dwFlags
'//--------------------------------------------------------------------------
%CMSG_BARE_CONTENT_FLAG              = &H00000001???
%CMSG_LENGTH_ONLY_FLAG               = &H00000002???
%CMSG_DETACHED_FLAG                  = &H00000004???
%CMSG_AUTHENTICATED_ATTRIBUTES_FLAG  = &H00000008???
%CMSG_CONTENTS_OCTETS_FLAG           = &H00000010???
%CMSG_MAX_LENGTH_FLAG                = &H00000020???

'// When set, nonData type inner content is encapsulated within an
'// OCTET STRING. Applicable to both Signed and Enveloped messages.
%CMSG_CMS_ENCAPSULATED_CONTENT_FLAG  = &H00000040???

'// If set, then, the hCryptProv passed to CryptMsgOpenToEncode or
'// CryptMsgOpenToDecode is released on the final CryptMsgClose.
'// Not released if CryptMsgOpenToEncode or CryptMsgOpenToDecode fails.
'//
'// Note, the envelope recipient hCryptProv's aren't released.
%CMSG_CRYPT_RELEASE_CONTEXT_FLAG     = &H00008000???

'//+-------------------------------------------------------------------------
'//  Open a cryptographic message for encoding
'//
'//  If CMSG_BARE_CONTENT_FLAG is specified for a streamed message,
'//  the streamed output will not have an outer ContentInfo wrapper. This
'//  makes it suitable to be streamed into an enclosing message.
'//
'//  The pStreamInfo parameter needs to be set to stream the encoded message
'//  output.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgOpenToEncode LIB "Crypt32.dll" _
    ALIAS "CryptMsgOpenToEncode" ( _
    BYVAL dwMsgEncodingType AS DWORD, _
    BYVAL dwFlags           AS DWORD, _
    BYVAL dwMsgType         AS DWORD, _
    pvMsgEncodeInfo         AS DWORD, _  ' void *
    pszInnerContentObjID    AS ASCIIZ, _
    BYVAL pStreamInfo       AS CMSG_STREAM_INFO PTR _
    ) AS DWORD  ' HCRYPTMSG
#ELSE
DECLARE FUNCTION CryptMsgOpenToEncode IMPORT "CRYPT32.DLL" ALIAS "CryptMsgOpenToEncode" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwMsgType AS DWORD _                           ' __in DWORD dwMsgType
 , BYREF pvMsgEncodeInfo AS ANY _                       ' __in void const *pvMsgEncodeInfo
 , OPTIONAL BYREF pszInnerContentObjID AS ASCIIZ _      ' __in_opt LPSTR pszInnerContentObjID
 , OPTIONAL BYREF pStreamInfo AS CMSG_STREAM_INFO _     ' __in_opt PCMSG_STREAM_INFO pStreamInfo
 ) AS DWORD                                             ' CryptMsgOpenToEncode
#ENDIF

'//+-------------------------------------------------------------------------
'//  Calculate the length of an encoded cryptographic message.
'//
'//  Calculates the length of the encoded message given the
'//  message type, encoding parameters and total length of
'//  the data to be updated. Note, this might not be the exact length. However,
'//  it will always be greater than or equal to the actual length.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgCalculateEncodedLength IMPORT "CRYPT32.DLL" ALIAS "CryptMsgCalculateEncodedLength" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwMsgType AS DWORD _                           ' __in DWORD dwMsgType
 , BYREF pvMsgEncodeInfo AS ANY _                       ' __in void const *pvMsgEncodeInfo
 , BYREF pszInnerContentObjID AS ASCIIZ _               ' __in_opt LPSTR pszInnerContentObjID
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 ) AS DWORD                                             ' DWORD

'//+-------------------------------------------------------------------------
'//  Open a cryptographic message for decoding
'//
'//  hCryptProv specifies the crypto provider to use for hashing and/or
'//  decrypting the message. If hCryptProv is NULL, a default crypt provider
'//  is used.
'//
'//  Currently pRecipientInfo isn't used and should be set to NULL.
'//
'//  The pStreamInfo parameter needs to be set to stream the decoded content
'//  output.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgOpenToDecode LIB "Crypt32.dll" _
    ALIAS "CryptMsgOpenToDecode" ( _
    BYVAL dwMsgEncodingType AS DWORD, _
    BYVAL dwFlags           AS DWORD, _
    BYVAL dwMsgType         AS DWORD, _
    BYVAL hCryptProv        AS DWORD, _  ' HCRYPTPROV_LEGACY
    pRecipientInfo          AS CERT_INFO, _
    BYVAL pStreamInfo       AS CMSG_STREAM_INFO PTR _
    ) AS DWORD  ' HCRYPTMSG
#ELSE
DECLARE FUNCTION CryptMsgOpenToDecode IMPORT "CRYPT32.DLL" ALIAS "CryptMsgOpenToDecode" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwMsgType AS DWORD _                           ' __in DWORD dwMsgType
 , BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , OPTIONAL BYREF pRecipientInfo AS CERT_INFO _         ' __in_opt PCERT_INFO pRecipientInfo
 , OPTIONAL BYREF pStreamInfo AS CMSG_STREAM_INFO _     ' __in_opt PCMSG_STREAM_INFO pStreamInfo
 ) AS DWORD                                             ' HCRYPTMSG
#ENDIF

'//+-------------------------------------------------------------------------
'//  Duplicate a cryptographic message handle
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgDuplicate IMPORT "CRYPT32.DLL" ALIAS "CryptMsgDuplicate" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 ) AS DWORD                                             ' HCRYPTMSG

'//+-------------------------------------------------------------------------
'//  Close a cryptographic message handle
'//
'//  LastError is preserved unless FALSE is returned.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgClose IMPORT "CRYPT32.DLL" ALIAS "CryptMsgClose" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Update the content of a cryptographic message. Depending on how the
'//  message was opened, the content is either encoded or decoded.
'//
'//  This function is repetitively called to append to the message content.
'//  fFinal is set to identify the last update. On fFinal, the encode/decode
'//  is completed. The encoded/decoded content and the decoded parameters
'//  are valid until the open and all duplicated handles are closed.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgUpdate IMPORT "CRYPT32.DLL" ALIAS "CryptMsgUpdate" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 , BYVAL pbData AS BYTE PTR _                           ' __in const BYTE *pbData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL fFinal AS LONG _                               ' __in BOOL fFinal
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get a parameter after encoding/decoding a cryptographic message. Called
'//  after the final CryptMsgUpdate. Only the CMSG_CONTENT_PARAM and
'//  CMSG_COMPUTED_HASH_PARAM are valid for an encoded message.
'//
'//  For an encoded HASHED message, the CMSG_COMPUTED_HASH_PARAM can be got
'//  before any CryptMsgUpdates to get its length.
'//
'//  The pvData type definition depends on the dwParamType value.
'//
'//  Elements pointed to by fields in the pvData structure follow the
'//  structure. Therefore, *pcbData may exceed the size of the structure.
'//
'//  Upon input, if *pcbData == 0, then, *pcbData is updated with the length
'//  of the data and the pvData parameter is ignored.
'//
'//  Upon return, *pcbData is updated with the length of the data.
'//
'//  The OBJID BLOBs returned in the pvData structures point to
'//  their still encoded representation. The appropriate functions
'//  must be called to decode the information.
'//
'//  See below for a list of the parameters to get.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgGetParam IMPORT "CRYPT32.DLL" ALIAS "CryptMsgGetParam" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 , BYVAL dwParam AS DWORD _                             ' __in DWORD dwParamType,
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get parameter types and their corresponding data structure definitions.
'//--------------------------------------------------------------------------
%CMSG_TYPE_PARAM                              = 1???
%CMSG_CONTENT_PARAM                           = 2???
%CMSG_BARE_CONTENT_PARAM                      = 3???
%CMSG_INNER_CONTENT_TYPE_PARAM                = 4???
%CMSG_SIGNER_COUNT_PARAM                      = 5???
%CMSG_SIGNER_INFO_PARAM                       = 6???
%CMSG_SIGNER_CERT_INFO_PARAM                  = 7???
%CMSG_SIGNER_HASH_ALGORITHM_PARAM             = 8???
%CMSG_SIGNER_AUTH_ATTR_PARAM                  = 9???
%CMSG_SIGNER_UNAUTH_ATTR_PARAM                = 10???
%CMSG_CERT_COUNT_PARAM                        = 11???
%CMSG_CERT_PARAM                              = 12???
%CMSG_CRL_COUNT_PARAM                         = 13???
%CMSG_CRL_PARAM                               = 14???
%CMSG_ENVELOPE_ALGORITHM_PARAM                = 15???
%CMSG_RECIPIENT_COUNT_PARAM                   = 17???
%CMSG_RECIPIENT_INDEX_PARAM                   = 18???
%CMSG_RECIPIENT_INFO_PARAM                    = 19???
%CMSG_HASH_ALGORITHM_PARAM                    = 20???
%CMSG_HASH_DATA_PARAM                         = 21???
%CMSG_COMPUTED_HASH_PARAM                     = 22???
%CMSG_ENCRYPT_PARAM                           = 26???
%CMSG_ENCRYPTED_DIGEST                        = 27???
%CMSG_ENCODED_SIGNER                          = 28???
%CMSG_ENCODED_MESSAGE                         = 29???
%CMSG_VERSION_PARAM                           = 30???
%CMSG_ATTR_CERT_COUNT_PARAM                   = 31???
%CMSG_ATTR_CERT_PARAM                         = 32???
%CMSG_CMS_RECIPIENT_COUNT_PARAM               = 33???
%CMSG_CMS_RECIPIENT_INDEX_PARAM               = 34???
%CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM = 35???
%CMSG_CMS_RECIPIENT_INFO_PARAM                = 36???
%CMSG_UNPROTECTED_ATTR_PARAM                  = 37???
%CMSG_SIGNER_CERT_ID_PARAM                    = 38???
%CMSG_CMS_SIGNER_INFO_PARAM                   = 39???

'//+-------------------------------------------------------------------------
'//  CMSG_TYPE_PARAM
'//
'//  The type of the decoded message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CONTENT_PARAM
'//
'//  The encoded content of a cryptographic message. Depending on how the
'//  message was opened, the content is either the whole PKCS#7
'//  message (opened to encode) or the inner content (opened to decode).
'//  In the decode case, the decrypted content is returned, if enveloped.
'//  If not enveloped, and if the inner content is of type DATA, the returned
'//  data is the contents octets of the inner content.
'//
'//  pvData points to the buffer receiving the content bytes
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_BARE_CONTENT_PARAM
'//
'//  The encoded content of an encoded cryptographic message, without the
'//  outer layer of ContentInfo. That is, only the encoding of the
'//  ContentInfo.content field is returned.
'//
'//  pvData points to the buffer receiving the content bytes
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_INNER_CONTENT_TYPE_PARAM
'//
'//  The type of the inner content of a decoded cryptographic message,
'//  in the form of a NULL-terminated object identifier string
'//  (eg. "1.2.840.113549.1.7.1").
'//
'//  pvData points to the buffer receiving the object identifier string
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_COUNT_PARAM
'//
'//  Count of signers in a SIGNED or SIGNED_AND_ENVELOPED message
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_CERT_INFO_PARAM
'//
'//  To get all the signers, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. SignerCount - 1.
'//
'//  pvData points to a CERT_INFO struct.
'//
'//  Only the following fields have been updated in the CERT_INFO struct:
'//  Issuer and SerialNumber.
'//
'//  Note, if the KEYID choice was selected for a CMS SignerId, then, the
'//  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
'//  single Attribute whose OID is szOID_KEYID_RDN, value type is
'//  CERT_RDN_OCTET_STRING and value is the KEYID. When the
'//  CertGetSubjectCertificateFromStore and
'//  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
'//  special KEYID Issuer and SerialNumber, they do a KEYID match.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_INFO_PARAM
'//
'//  To get all the signers, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. SignerCount - 1.
'//
'//  pvData points to a CMSG_SIGNER_INFO struct.
'//
'//  Note, if the KEYID choice was selected for a CMS SignerId, then, the
'//  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
'//  single Attribute whose OID is szOID_KEYID_RDN, value type is
'//  CERT_RDN_OCTET_STRING and value is the KEYID. When the
'//  CertGetSubjectCertificateFromStore and
'//  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
'//  special KEYID Issuer and SerialNumber, they do a KEYID match.
'//--------------------------------------------------------------------------

' // Size = 68 bytes
TYPE CMSG_SIGNER_INFO DWORD
   dwVersion               AS DWORD
   Issuer                  AS CERT_NAME_BLOB
   SerialNumber            AS CRYPT_INTEGER_BLOB
   HashAlgorithm           AS CRYPT_ALGORITHM_IDENTIFIER
   HashEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedHash           AS CRYPT_DATA_BLOB
   AuthAttrs               AS CRYPT_ATTRIBUTES
   UnauthAttrs             AS CRYPT_ATTRIBUTES
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_CERT_ID_PARAM
'//
'//  To get all the signers, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. SignerCount - 1.
'//
'//  pvData points to a CERT_ID struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CMS_SIGNER_INFO_PARAM
'//
'//  Same as CMSG_SIGNER_INFO_PARAM, except, contains SignerId instead of
'//  Issuer and SerialNumber.
'//
'//  To get all the signers, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. SignerCount - 1.
'//
'//  pvData points to a CMSG_CMS_SIGNER_INFO struct.
'//--------------------------------------------------------------------------

' // Size = 72 bytes
TYPE CMSG_CMS_SIGNER_INFO DWORD
   dwVersion               AS DWORD
   SignerId                AS CERT_ID
   HashAlgorithm           AS CRYPT_ALGORITHM_IDENTIFIER
   HashEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedHash           AS CRYPT_DATA_BLOB
   AuthAttrs               AS CRYPT_ATTRIBUTES
   UnauthAttrs             AS CRYPT_ATTRIBUTES
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_HASH_ALGORITHM_PARAM
'//
'//  This parameter specifies the HashAlgorithm that was used for the signer.
'//
'//  Set dwIndex to iterate through all the signers.
'//
'//  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_AUTH_ATTR_PARAM
'//
'//  The authenticated attributes for the signer.
'//
'//  Set dwIndex to iterate through all the signers.
'//
'//  pvData points to a CMSG_ATTR struct.
'//--------------------------------------------------------------------------
'typedef CRYPT_ATTRIBUTES CMSG_ATTR;
'typedef CRYPT_ATTRIBUTES *PCMSG_ATTR;

'//+-------------------------------------------------------------------------
'//  CMSG_SIGNER_UNAUTH_ATTR_PARAM
'//
'//  The unauthenticated attributes for the signer.
'//
'//  Set dwIndex to iterate through all the signers.
'//
'//  pvData points to a CMSG_ATTR struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CERT_COUNT_PARAM
'//
'//  Count of certificates in a SIGNED or SIGNED_AND_ENVELOPED message.
'//
'//  CMS, also supports certificates in an ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CERT_PARAM
'//
'//  To get all the certificates, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. CertCount - 1.
'//
'//  pvData points to an array of the certificate's encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CRL_COUNT_PARAM
'//
'//  Count of CRLs in a SIGNED or SIGNED_AND_ENVELOPED message.
'//
'//  CMS, also supports CRLs in an ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CRL_PARAM
'//
'//  To get all the CRLs, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. CrlCount - 1.
'//
'//  pvData points to an array of the CRL's encoded bytes.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'//  CMSG_ENVELOPE_ALGORITHM_PARAM
'//
'//  The ContentEncryptionAlgorithm that was used in
'//  an ENVELOPED or SIGNED_AND_ENVELOPED message.
'//
'//  For streaming you must be able to successfully get this parameter before
'//  doing a CryptMsgControl decrypt.
'//
'//  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_RECIPIENT_COUNT_PARAM
'//
'//  Count of recipients in an ENVELOPED or SIGNED_AND_ENVELOPED message.
'//
'//  Count of key transport recepients.
'//
'//  The CMSG_CMS_RECIPIENT_COUNT_PARAM has the total count of
'//  recipients (it also includes key agree and mail list recipients).
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_RECIPIENT_INDEX_PARAM
'//
'//  Index of the recipient used to decrypt an ENVELOPED or SIGNED_AND_ENVELOPED
'//  message.
'//
'//  Index of a key transport recipient. If a non key transport
'//  recipient was used to decrypt, fails with LastError set to
'//  CRYPT_E_INVALID_INDEX.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_RECIPIENT_INFO_PARAM
'//
'//  To get all the recipients, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. RecipientCount - 1.
'//
'//  Only returns the key transport recepients.
'//
'//  The CMSG_CMS_RECIPIENT_INFO_PARAM returns all recipients.
'//
'//  pvData points to a CERT_INFO struct.
'//
'//  Only the following fields have been updated in the CERT_INFO struct:
'//  Issuer, SerialNumber and PublicKeyAlgorithm. The PublicKeyAlgorithm
'//  specifies the KeyEncryptionAlgorithm that was used.
'//
'//  Note, if the KEYID choice was selected for a key transport recipient, then,
'//  the SerialNumber is 0 and the Issuer is encoded containing a single RDN
'//  with a single Attribute whose OID is szOID_KEYID_RDN, value type is
'//  CERT_RDN_OCTET_STRING and value is the KEYID. When the
'//  CertGetSubjectCertificateFromStore and
'//  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
'//  special KEYID Issuer and SerialNumber, they do a KEYID match.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_HASH_ALGORITHM_PARAM
'//
'//  The HashAlgorithm in a HASHED message.
'//
'//  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_HASH_DATA_PARAM
'//
'//  The hash in a HASHED message.
'//
'//  pvData points to an array of bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_COMPUTED_HASH_PARAM
'//
'//  The computed hash for a HASHED message.
'//  This may be called for either an encoded or decoded message.
'//
'//  Also, the computed hash for one of the signer's in a SIGNED message.
'//  It may be called for either an encoded or decoded message after the
'//  final update.  Set dwIndex to iterate through all the signers.
'//
'//  pvData points to an array of bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_ENCRYPT_PARAM
'//
'//  The ContentEncryptionAlgorithm that was used in an ENCRYPTED message.
'//
'//  pvData points to an CRYPT_ALGORITHM_IDENTIFIER struct.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_ENCODED_MESSAGE
'//
'//  The full encoded message. This is useful in the case of a decoded
'//  message which has been modified (eg. a signed-data or
'//  signed-and-enveloped-data message which has been countersigned).
'//
'//  pvData points to an array of the message's encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_VERSION_PARAM
'//
'//  The version of the decoded message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

%CMSG_SIGNED_DATA_V1                    = 1
%CMSG_SIGNED_DATA_V3                    = 3
%CMSG_SIGNED_DATA_PKCS_1_5_VERSION      = %CMSG_SIGNED_DATA_V1
%CMSG_SIGNED_DATA_CMS_VERSION           = %CMSG_SIGNED_DATA_V3

%CMSG_SIGNER_INFO_V1                    = 1
%CMSG_SIGNER_INFO_V3                    = 3
%CMSG_SIGNER_INFO_PKCS_1_5_VERSION      = %CMSG_SIGNER_INFO_V1
%CMSG_SIGNER_INFO_CMS_VERSION           = %CMSG_SIGNER_INFO_V3

%CMSG_HASHED_DATA_V0                    = 0
%CMSG_HASHED_DATA_V2                    = 2
%CMSG_HASHED_DATA_PKCS_1_5_VERSION      = %CMSG_HASHED_DATA_V0
%CMSG_HASHED_DATA_CMS_VERSION           = %CMSG_HASHED_DATA_V2

%CMSG_ENVELOPED_DATA_V0                 = 0
%CMSG_ENVELOPED_DATA_V2                 = 2
%CMSG_ENVELOPED_DATA_PKCS_1_5_VERSION   = %CMSG_ENVELOPED_DATA_V0
%CMSG_ENVELOPED_DATA_CMS_VERSION        = %CMSG_ENVELOPED_DATA_V2

'//+-------------------------------------------------------------------------
'//  CMSG_ATTR_CERT_COUNT_PARAM
'//
'//  Count of attribute certificates in a SIGNED or ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_ATTR_CERT_PARAM
'//
'//  To get all the attribute certificates, repetitively call CryptMsgGetParam,
'//  with dwIndex set to 0 .. AttrCertCount - 1.
'//
'//  pvData points to an array of the attribute certificate's encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CMS_RECIPIENT_COUNT_PARAM
'//
'//  Count of all CMS recipients in an ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CMS_RECIPIENT_INDEX_PARAM
'//
'//  Index of the CMS recipient used to decrypt an ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CMS_RECIPIENT_ENCRYPTED_KEY_INDEX_PARAM
'//
'//  For a CMS key agreement recipient, the index of the encrypted key
'//  used to decrypt an ENVELOPED message.
'//
'//  pvData points to a DWORD
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CMS_RECIPIENT_INFO_PARAM
'//
'//  To get all the CMS recipients, repetitively call CryptMsgGetParam, with
'//  dwIndex set to 0 .. CmsRecipientCount - 1.
'//
'//  pvData points to a CMSG_CMS_RECIPIENT_INFO struct.
'//--------------------------------------------------------------------------

' // Size = 44 bytes
TYPE CMSG_KEY_TRANS_RECIPIENT_INFO DWORD
   dwVersion              AS DWORD
   RecipientId            AS CERT_ID
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedKey           AS CRYPT_DATA_BLOB
END TYPE

' // Size = 40 bytes
TYPE CMSG_RECIPIENT_ENCRYPTED_KEY_INFO DWORD
   RecipientId  AS CERT_ID
   EncryptedKey AS CRYPT_DATA_BLOB
   Date         AS FILETIME
   pOtherAttr   AS CRYPT_ATTRIBUTE_TYPE_VALUE PTR
END TYPE

'typedef struct _CMSG_KEY_AGREE_RECIPIENT_INFO {
'    DWORD                       dwVersion;
'    DWORD                       dwOriginatorChoice;
'    union {
'        // CMSG_KEY_AGREE_ORIGINATOR_CERT
'        CERT_ID                     OriginatorCertId;
'        // CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY
'        CERT_PUBLIC_KEY_INFO        OriginatorPublicKeyInfo;
'    };
'    CRYPT_DATA_BLOB             UserKeyingMaterial;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;

'    DWORD                                cRecipientEncryptedKeys;
'    PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO   *rgpRecipientEncryptedKeys;
'} CMSG_KEY_AGREE_RECIPIENT_INFO, *PCMSG_KEY_AGREE_RECIPIENT_INFO;

' // Size = 24 bytes
UNION CMSG_KEY_AGREE_RECIPIENT_INFO_UNION DWORD
   OriginatorCertId        AS CERT_ID
   OriginatorPublicKeyInfo AS CERT_PUBLIC_KEY_INFO
END UNION

' // Size = 60 bytes
TYPE CMSG_KEY_AGREE_RECIPIENT_INFO DWORD
   dwVersion                 AS DWORD
   dwOriginatorChoice        AS DWORD
   CMSG_KEY_AGREE_RECIPIENT_INFO_UNION
   UserKeyingMaterial        AS CRYPT_DATA_BLOB
   KeyEncryptionAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   cRecipientEncryptedKeys   AS DWORD
   rgpRecipientEncryptedKeys AS CMSG_RECIPIENT_ENCRYPTED_KEY_INFO PTR
END TYPE

%CMSG_KEY_AGREE_ORIGINATOR_CERT       = 1???
%CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY = 2???

' // Size = 44 bytes
TYPE CMSG_MAIL_LIST_RECIPIENT_INFO DWORD
   dwVersion              AS DWORD
   KeyId                  AS CRYPT_DATA_BLOB
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedKey           AS CRYPT_DATA_BLOB
   Date                   AS FILETIME
   pOtherAttr             AS CRYPT_ATTRIBUTE_TYPE_VALUE PTR
END TYPE

'typedef struct _CMSG_CMS_RECIPIENT_INFO {
'    DWORD   dwRecipientChoice;
'    union {
'        // CMSG_KEY_TRANS_RECIPIENT
'        PCMSG_KEY_TRANS_RECIPIENT_INFO   pKeyTrans;
'        // CMSG_KEY_AGREE_RECIPIENT
'        PCMSG_KEY_AGREE_RECIPIENT_INFO   pKeyAgree;
'        // CMSG_MAIL_LIST_RECIPIENT
'        PCMSG_MAIL_LIST_RECIPIENT_INFO   pMailList;
'    };
'} CMSG_CMS_RECIPIENT_INFO, *PCMSG_CMS_RECIPIENT_INFO;

' // Size = 4 bytes
UNION CMSG_CMS_RECIPIENT_INFO_UNION DWORD
   pKeyTrans AS CMSG_KEY_TRANS_RECIPIENT_INFO PTR
   pKeyAgree AS CMSG_KEY_TRANS_RECIPIENT_INFO PTR
   pMailList AS CMSG_KEY_TRANS_RECIPIENT_INFO PTR
END UNION

' // Size = 8 bytes
TYPE CMSG_CMS_RECIPIENT_INFO DWORD
   dwRecipientChoice AS DWORD
   CMSG_CMS_RECIPIENT_INFO_UNION
END TYPE

'// dwVersion numbers for the KeyTrans, KeyAgree and MailList recipients
%CMSG_ENVELOPED_RECIPIENT_V0            = 0???
%CMSG_ENVELOPED_RECIPIENT_V2            = 2???
%CMSG_ENVELOPED_RECIPIENT_V3            = 3???
%CMSG_ENVELOPED_RECIPIENT_V4            = 4???
%CMSG_KEY_TRANS_PKCS_1_5_VERSION        = %CMSG_ENVELOPED_RECIPIENT_V0
%CMSG_KEY_TRANS_CMS_VERSION             = %CMSG_ENVELOPED_RECIPIENT_V2
%CMSG_KEY_AGREE_VERSION                 = %CMSG_ENVELOPED_RECIPIENT_V3
%CMSG_MAIL_LIST_VERSION                 = %CMSG_ENVELOPED_RECIPIENT_V4

'//+-------------------------------------------------------------------------
'//  CMSG_UNPROTECTED_ATTR_PARAM
'//
'//  The unprotected attributes in the envelped message.
'//
'//  pvData points to a CMSG_ATTR struct.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'//  Perform a special "control" function after the final CryptMsgUpdate of a
'//  encoded/decoded cryptographic message.
'//
'//  The dwCtrlType parameter specifies the type of operation to be performed.
'//
'//  The pvCtrlPara definition depends on the dwCtrlType value.
'//
'//  See below for a list of the control operations and their pvCtrlPara
'//  type definition.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgControl IMPORT "CRYPT32.DLL" ALIAS "CryptMsgControl" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwCtrlType AS DWORD _                          ' __in DWORD dwCtrlType
 , BYREF pvCtrlPara AS ANY _                            ' __in void const *pvCtrlPara
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Message control types
'//--------------------------------------------------------------------------
%CMSG_CTRL_VERIFY_SIGNATURE       = 1???
%CMSG_CTRL_DECRYPT                = 2???
%CMSG_CTRL_VERIFY_HASH            = 5???
%CMSG_CTRL_ADD_SIGNER             = 6???
%CMSG_CTRL_DEL_SIGNER             = 7???
%CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR = 8???
%CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR = 9???
%CMSG_CTRL_ADD_CERT               = 10???
%CMSG_CTRL_DEL_CERT               = 11???
%CMSG_CTRL_ADD_CRL                = 12???
%CMSG_CTRL_DEL_CRL                = 13???
%CMSG_CTRL_ADD_ATTR_CERT          = 14???
%CMSG_CTRL_DEL_ATTR_CERT          = 15???
%CMSG_CTRL_KEY_TRANS_DECRYPT      = 16???
%CMSG_CTRL_KEY_AGREE_DECRYPT      = 17???
%CMSG_CTRL_MAIL_LIST_DECRYPT      = 18???
%CMSG_CTRL_VERIFY_SIGNATURE_EX    = 19???
%CMSG_CTRL_ADD_CMS_SIGNER_INFO    = 20???

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_VERIFY_SIGNATURE
'//
'//  Verify the signature of a SIGNED or SIGNED_AND_ENVELOPED
'//  message after it has been decoded.
'//
'//  For a SIGNED_AND_ENVELOPED message, called after
'//  CryptMsgControl(CMSG_CTRL_DECRYPT), if CryptMsgOpenToDecode was called
'//  with a NULL pRecipientInfo.
'//
'//  pvCtrlPara points to a CERT_INFO struct.
'//
'//  The CERT_INFO contains the Issuer and SerialNumber identifying
'//  the Signer of the message. The CERT_INFO also contains the
'//  PublicKeyInfo
'//  used to verify the signature. The cryptographic provider specified
'//  in CryptMsgOpenToDecode is used.
'//
'//  Note, if the message contains CMS signers identified by KEYID, then,
'//  the CERT_INFO's Issuer and SerialNumber is ignored and only the public
'//  key is used to find a signer whose signature verifies.
'//
'//  The following CMSG_CTRL_VERIFY_SIGNATURE_EX should be used instead.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_VERIFY_SIGNATURE_EX
'//
'//  Verify the signature of a SIGNED message after it has been decoded.
'//
'//  pvCtrlPara points to the following CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA.
'//
'//  If hCryptProv is NULL, uses the cryptographic provider specified in
'//  CryptMsgOpenToDecode. If CryptMsgOpenToDecode's hCryptProv is also NULL,
'//  gets default provider according to the signer's public key OID.
'//
'//  dwSignerIndex is the index of the signer to use to verify the signature.
'//
'//  The signer can be a pointer to a CERT_PUBLIC_KEY_INFO, certificate
'//  context or a chain context.
'//
'//  If the signer's HashEncryptionAlgorithm is szOID_PKIX_NO_SIGNATURE, then,
'//  the signature is expected to contain the hash octets. Only dwSignerType
'//  of CMSG_VERIFY_SIGNER_NULL may be specified to verify this no signature
'//  case.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA DWORD
   cbSize        AS DWORD   ' DWORD
   hCryptProv    AS DWORD   ' HCRYPTPROV
   dwSignerIndex AS DWORD   ' DWORD
   dwSignerType  AS DWORD   ' DWORD
   pvSigner      AS DWORD   ' void*
END TYPE

'// Signer Types
%CMSG_VERIFY_SIGNER_PUBKEY                  = 1???
'    // pvSigner :: PCERT_PUBLIC_KEY_INFO
%CMSG_VERIFY_SIGNER_CERT                    = 2???
'    // pvSigner :: PCCERT_CONTEXT
%CMSG_VERIFY_SIGNER_CHAIN                   = 3???
'    // pvSigner :: PCCERT_CHAIN_CONTEXT
%CMSG_VERIFY_SIGNER_NULL                    = 4???
'    // pvSigner :: NULL


'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DECRYPT
'//
'//  Decrypt an ENVELOPED or SIGNED_AND_ENVELOPED message after it has been
'//  decoded.
'//
'//  This decrypt is only applicable to key transport recipients.
'//
'//  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
'//  0, defaults to AT_KEYEXCHANGE.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
'//  to CryptMsgControl, then, the hCryptProv is released on the final
'//  CryptMsgClose. Not released if CryptMsgControl fails.
'//
'//  dwRecipientIndex is the index of the recipient in the message associated
'//  with the hCryptProv's private key.
'//
'//  The dwRecipientIndex is the index of a key transport recipient.
'//
'//  Note, the message can only be decrypted once.
'//--------------------------------------------------------------------------

UNION CMSG_CTRL_DECRYPT_PARA_UNION DWORD
    hCryptProv AS DWORD   ' HCRYPTPROV
    hNCryptKey AS DWORD   ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 16 bytes
TYPE CMSG_CTRL_DECRYPT_PARA DWORD
   cbSize           AS DWORD   ' DWORD
   CMSG_CTRL_DECRYPT_PARA_UNION
   dwKeySpec        AS DWORD   ' DWORD
   dwRecipientIndex AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_KEY_TRANS_DECRYPT
'//
'//  Decrypt an ENVELOPED message after it has been decoded for a key
'//  transport recipient.
'//
'//  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
'//  0, defaults to AT_KEYEXCHANGE.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
'//  to CryptMsgControl, then, the hCryptProv is released on the final
'//  CryptMsgClose. Not released if CryptMsgControl fails.
'//
'//  pKeyTrans points to the CMSG_KEY_TRANS_RECIPIENT_INFO obtained via
'//  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM)
'//
'//  dwRecipientIndex is the index of the recipient in the message associated
'//  with the hCryptProv's private key.
'//
'//  Note, the message can only be decrypted once.
'//--------------------------------------------------------------------------

UNION CMSG_CTRL_KEY_TRANS_DECRYPT_PARA_UNION DWORD
    hCryptProv AS DWORD   ' HCRYPTPROV
    hNCryptKey AS DWORD   ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 20 bytes
TYPE CMSG_CTRL_KEY_TRANS_DECRYPT_PARA DWORD
   cbSize           AS DWORD                               ' DWORD
   CMSG_CTRL_KEY_TRANS_DECRYPT_PARA_UNION
   dwKeySpec        AS DWORD                               ' DWORD
   pKeyTrans        AS CMSG_KEY_TRANS_RECIPIENT_INFO PTR   ' PCMSG_KEY_TRANS_RECIPIENT_INFO
   dwRecipientIndex AS DWORD                               ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_KEY_AGREE_DECRYPT
'//
'//  Decrypt an ENVELOPED message after it has been decoded for a key
'//  agreement recipient.
'//
'//  hCryptProv and dwKeySpec specify the private key to use. For dwKeySpec ==
'//  0, defaults to AT_KEYEXCHANGE.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
'//  to CryptMsgControl, then, the hCryptProv is released on the final
'//  CryptMsgClose. Not released if CryptMsgControl fails.
'//
'//  pKeyAgree points to the CMSG_KEY_AGREE_RECIPIENT_INFO obtained via
'//  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM) for dwRecipientIndex.
'//
'//  dwRecipientIndex, dwRecipientEncryptedKeyIndex are the indices of the
'//  recipient's encrypted key in the message associated with the hCryptProv's
'//  private key.
'//
'//  OriginatorPublicKey is the originator's public key obtained from either
'//  the originator's certificate or the CMSG_KEY_AGREE_RECIPIENT_INFO obtained
'//  via the CMSG_CMS_RECIPIENT_INFO_PARAM.
'//
'//  Note, the message can only be decrypted once.
'//--------------------------------------------------------------------------

UNION CMSG_CTRL_KEY_AGREE_DECRYPT_PARA_UNION DWORD
    hCryptProv AS DWORD   ' HCRYPTPROV
    hNCryptKey AS DWORD   ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 36 bytes
TYPE CMSG_CTRL_KEY_AGREE_DECRYPT_PARA DWORD
   cbSize                       AS DWORD                               ' DWORD
   CMSG_CTRL_KEY_AGREE_DECRYPT_PARA_UNION
   dwKeySpec                    AS DWORD                               ' DWORD
   pKeyAgree                    AS CMSG_KEY_AGREE_RECIPIENT_INFO PTR   ' PCMSG_KEY_AGREE_RECIPIENT_INFO
   dwRecipientIndex             AS DWORD                               ' DWORD
   dwRecipientEncryptedKeyIndex AS DWORD                               ' DWORD
   OriginatorPublicKey          AS CRYPT_BIT_BLOB                      ' CRYPT_BIT_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_MAIL_LIST_DECRYPT
'//
'//  Decrypt an ENVELOPED message after it has been decoded for a mail
'//  list recipient.
'//
'//  pMailList points to the CMSG_MAIL_LIST_RECIPIENT_INFO obtained via
'//  CryptMsgGetParam(CMSG_CMS_RECIPIENT_INFO_PARAM) for dwRecipientIndex.
'//
'//  There is 1 choice for the KeyEncryptionKey: an already created CSP key
'//  handle. For the key handle choice, hCryptProv must be nonzero. This key
'//  handle isn't destroyed.
'//
'//  If CMSG_CRYPT_RELEASE_CONTEXT_FLAG is set in the dwFlags passed
'//  to CryptMsgControl, then, the hCryptProv is released on the final
'//  CryptMsgClose. Not released if CryptMsgControl fails.
'//
'//  For RC2 wrap, the effective key length is obtained from the
'//  KeyEncryptionAlgorithm parameters and set on the hKeyEncryptionKey before
'//  decrypting.
'//
'//  Note, the message can only be decrypted once.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA {
'    DWORD                           cbSize;
'    HCRYPTPROV                      hCryptProv;
'    PCMSG_MAIL_LIST_RECIPIENT_INFO  pMailList;
'    DWORD                           dwRecipientIndex;
'    DWORD                           dwKeyChoice;
'    union {
'        // CMSG_MAIL_LIST_HANDLE_KEY_CHOICE
'        HCRYPTKEY                       hKeyEncryptionKey;
'        // Reserve space for a potential pointer choice
'        void                            *pvKeyEncryptionKey;
'    };
'} CMSG_CTRL_MAIL_LIST_DECRYPT_PARA, *PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA;

' // Size = 4 bytes
UNION CMSG_CTRL_MAIL_LIST_DECRYPT_PARA_UNION DWORD
   hKeyEncryptionKey  AS DWORD
   pvKeyEncryptionKey AS DWORD
END UNION

' // Size = 24 bytes
TYPE CMSG_CTRL_MAIL_LIST_DECRYPT_PARA DWORD
   cbSize           AS DWORD
   hCryptProv       AS DWORD
   pMailList        AS CMSG_MAIL_LIST_RECIPIENT_INFO PTR
   dwRecipientIndex AS DWORD
   dwKeyChoice      AS DWORD
   CMSG_CTRL_MAIL_LIST_DECRYPT_PARA_UNION
END TYPE


'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_VERIFY_HASH
'//
'//  Verify the hash of a HASHED message after it has been decoded.
'//
'//  Only the hCryptMsg parameter is used, to specify the message whose
'//  hash is being verified.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_SIGNER
'//
'//  Add a signer to a signed-data message.
'//
'//  pvCtrlPara points to a CMSG_SIGNER_ENCODE_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_CMS_SIGNER_INFO
'//
'//  Add a signer to a signed-data message.
'//
'//  Differs from the above, CMSG_CTRL_ADD_SIGNER, wherein, the signer info
'//  already contains the signature.
'//
'//  pvCtrlPara points to a CMSG_CMS_SIGNER_INFO.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DEL_SIGNER
'//
'//  Remove a signer from a signed-data or signed-and-enveloped-data message.
'//
'//  pvCtrlPara points to a DWORD containing the 0-based index of the
'//  signer to be removed.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR
'//
'//  Add an unauthenticated attribute to the SignerInfo of a signed-data or
'//  signed-and-enveloped-data message.
'//
'//  The unauthenticated attribute is input in the form of an encoded blob.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CMSG_CTRL_ADD_SIGNER_UNAUTH_ATTR_PARA DWORD
   cbSize        AS DWORD
   dwSignerIndex AS DWORD
   blob          AS CRYPT_DATA_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR
'//
'//  Delete an unauthenticated attribute from the SignerInfo of a signed-data
'//  or signed-and-enveloped-data message.
'//
'//  The unauthenticated attribute to be removed is specified by
'//  a 0-based index.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CMSG_CTRL_DEL_SIGNER_UNAUTH_ATTR_PARA DWORD
   cbSize            AS DWORD
   dwSignerIndex     AS DWORD
   dwUnauthAttrIndex AS DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_CERT
'//
'//  Add a certificate to a signed-data or signed-and-enveloped-data message.
'//
'//  pvCtrlPara points to a CRYPT_DATA_BLOB containing the certificate's
'//  encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DEL_CERT
'//
'//  Delete a certificate from a signed-data or signed-and-enveloped-data
'//  message.
'//
'//  pvCtrlPara points to a DWORD containing the 0-based index of the
'//  certificate to be removed.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_CRL
'//
'//  Add a CRL to a signed-data or signed-and-enveloped-data message.
'//
'//  pvCtrlPara points to a CRYPT_DATA_BLOB containing the CRL's
'//  encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DEL_CRL
'//
'//  Delete a CRL from a signed-data or signed-and-enveloped-data message.
'//
'//  pvCtrlPara points to a DWORD containing the 0-based index of the CRL
'//  to be removed.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_ADD_ATTR_CERT
'//
'//  Add an attribute certificate to a signed-data message.
'//
'//  pvCtrlPara points to a CRYPT_DATA_BLOB containing the attribute
'//  certificate's encoded bytes.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CMSG_CTRL_DEL_ATTR_CERT
'//
'//  Delete an attribute certificate from a signed-data message.
'//
'//  pvCtrlPara points to a DWORD containing the 0-based index of the
'//  attribute certificate to be removed.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'//  Verify a countersignature, at the SignerInfo level.
'//  ie. verify that pbSignerInfoCountersignature contains the encrypted
'//  hash of the encryptedDigest field of pbSignerInfo.
'//
'//  hCryptProv is used to hash the encryptedDigest field of pbSignerInfo.
'//  The only fields referenced from pciCountersigner are SerialNumber, Issuer,
'//  and SubjectPublicKeyInfo.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgVerifyCountersignatureEncoded LIB "Crypt32.dll" _
    ALIAS "CryptMsgVerifyCountersignatureEncoded" ( _
    BYVAL hCryptProv                   AS DWORD, _  ' HCRYPTPROV_LEGACY
    BYVAL dwEncodingType               AS DWORD, _
    BYVAL pbSignerInfo                 AS BYTE PTR, _
    BYVAL cbSignerInfo                 AS DWORD, _
    BYVAL pbSignerInfoCountersignature AS BYTE PTR, _
    BYVAL cbSignerInfoCountersignature AS DWORD, _
    BYVAL pciCountersigner             AS CERT_INFO PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptMsgVerifyCountersignatureEncoded IMPORT "CRYPT32.DLL" ALIAS "CryptMsgVerifyCountersignatureEncoded" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV   hCryptProv
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD        dwEncodingType
 , BYVAL pbSignerInfo AS BYTE PTR _                     ' __in PBYTE        pbSignerInfo
 , BYVAL cbSignerInfo AS DWORD _                        ' __in DWORD        cbSignerInfo
 , BYVAL pbSignerInfoCountersignature AS BYTE PTR _     ' __in PBYTE        pbSignerInfoCountersignature
 , BYVAL cbSignerInfoCountersignature AS DWORD _        ' __in DWORD        cbSignerInfoCountersignature
 , BYREF pciCountersigner AS CERT_INFO _                ' __in PCERT_INFO   pciCountersigner
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Verify a countersignature, at the SignerInfo level.
'//  ie. verify that pbSignerInfoCountersignature contains the encrypted
'//  hash of the encryptedDigest field of pbSignerInfo.
'//
'//  hCryptProv is used to hash the encryptedDigest field of pbSignerInfo.
'//
'//  The signer can be a CERT_PUBLIC_KEY_INFO, certificate context or a
'//  chain context.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgVerifyCountersignatureEncodedEx LIB "Crypt32.dll" _
    ALIAS "CryptMsgVerifyCountersignatureEncodedEx" ( _
    BYVAL hCryptProv                   AS DWORD, _  ' HCRYPTPROV_LEGACY
    BYVAL dwEncodingType               AS DWORD, _
    BYVAL pbSignerInfo                 AS BYTE PTR, _
    BYVAL cbSignerInfo                 AS DWORD, _
    BYVAL pbSignerInfoCountersignature AS BYTE PTR, _
    BYVAL cbSignerInfoCountersignature AS DWORD, _
    BYVAL dwSignerType                 AS DWORD, _
    pvSigner                           AS ANY, _    ' void *
    BYVAL dwFlags                      AS DWORD, _
    pvReserved                         AS ANY _     ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptMsgVerifyCountersignatureEncodedEx IMPORT "CRYPT32.DLL" ALIAS "CryptMsgVerifyCountersignatureEncodedEx" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD      dwEncodingType
 , BYVAL pbSignerInfo AS BYTE PTR _                     ' __in PBYTE      pbSignerInfo
 , BYVAL cbSignerInfo AS DWORD _                        ' __in DWORD      cbSignerInfo
 , BYVAL pbSignerInfoCountersignature AS BYTE PTR _     ' __in PBYTE      pbSignerInfoCountersignature
 , BYVAL cbSignerInfoCountersignature AS DWORD _        ' __in DWORD      cbSignerInfoCountersignature
 , BYVAL dwSignerType AS DWORD _                        ' __in DWORD      dwSignerType
 , BYREF pvSigner AS ANY _                              ' __in void       *pvSigner
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD      dwFlags
 , OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in_opt void   *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'// See CMSG_CTRL_VERIFY_SIGNATURE_EX_PARA for dwSignerType definitions


'//+-------------------------------------------------------------------------
'//  Countersign an already-existing signature in a message
'//
'//  dwIndex is a zero-based index of the SignerInfo to be countersigned.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgCountersign LIB "Crypt32.dll" _
    ALIAS "CryptMsgCountersign" ( _
    BYVAL hCryptMsg        AS DWORD, _  ' HCRYPTMSG
    BYVAL dwIndex          AS DWORD, _
    BYVAL cCountersigners  AS DWORD, _
    BYVAL rgCountersigners AS CMSG_SIGNER_ENCODE_INFO PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptMsgCountersign IMPORT "CRYPT32.DLL" ALIAS "CryptMsgCountersign" ( _
   BYREF hCryptMsg AS DWORD _                           ' __inout HCRYPTMSG             hCryptMsg
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD                    dwIndex
 , BYVAL cCountersigners AS DWORD _                     ' __in DWORD                    cCountersigners
 , BYREF rgCountersigners AS CMSG_SIGNER_ENCODE_INFO _  ' __in PCMSG_SIGNER_ENCODE_INFO rgCountersigners
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Countersign an already-existing signature (encoded SignerInfo).
'//  Output an encoded SignerInfo blob, suitable for use as a countersignature
'//  attribute in the unauthenticated attributes of a signed-data or
'//  signed-and-enveloped-data message.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgCountersignEncoded LIB "Crypt32.dll" _
    ALIAS "CryptMsgCountersignEncoded" ( _
    BYVAL dwEncodingType     AS DWORD, _
    BYVAL pbSignerInfo       AS BYTE PTR, _
    BYVAL cbSignerInfo       AS DWORD, _
    BYVAL cCountersigners    AS DWORD, _
    BYVAL rgCountersigners   AS CMSG_SIGNER_ENCODE_INFO PTR, _
    BYVAL pbCountersignature AS BYTE PTR, _
    pcbCountersignature      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptMsgCountersignEncoded IMPORT "CRYPT32.DLL" ALIAS "CryptMsgCountersignEncoded" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD                    dwEncodingType
 , BYVAL pbSignerInfo AS BYTE PTR _                     ' __in PBYTE                    pbSignerInfo
 , BYVAL cbSignerInfo AS DWORD _                        ' __in DWORD                    cbSignerInfo
 , BYVAL cCountersigners AS DWORD _                     ' __in DWORD                    cCountersigners
 , BYREF rgCountersigners AS CMSG_SIGNER_ENCODE_INFO _  ' __in PCMSG_SIGNER_ENCODE_INFO rgCountersigners
 , BYREF pbCountersignature AS DWORD _                  ' __out PBYTE                   pbCountersignature
 , BYREF pcbCountersignature AS DWORD _                 ' __inout PDWORD                pcbCountersignature
 ) AS LONG                                              ' BOOL
#ENDIF


'//+-------------------------------------------------------------------------
'//  CryptMsg OID installable functions
'//--------------------------------------------------------------------------

'typedef void * (WINAPI *PFN_CMSG_ALLOC) (
'    IN size_t cb
'    );

'FUNCTION CMSG_ALLOC ( _
'   BYVAL cb AS DWORD _                 ' __in size_t cb
'   ) AS DWORD                          ' void*

'typedef void (WINAPI *PFN_CMSG_FREE)(
'    IN void *pv
'    );

'SUB CMSG_FREE ( _
'   BYVAL pv AS DWORD _                 ' __in void *pv
'   )                                   ' void

'// Note, the following 3 installable functions are obsolete and have been
'// replaced with GenContentEncryptKey, ExportKeyTrans, ExportKeyAgree,
'// ExportMailList, ImportKeyTrans, ImportKeyAgree and ImportMailList
'// installable functions.

'// If *phCryptProv is NULL upon entry, then, if supported, the installable
'// function should acquire a default provider and return. Note, its up
'// to the installable function to release at process detach.
'//
'// If paiEncrypt->Parameters.cbData is 0, then, the callback may optionally
'// return default encoded parameters in *ppbEncryptParameters and
'// *pcbEncryptParameters. pfnAlloc must be called for the allocation.

$CMSG_OID_GEN_ENCRYPT_KEY_FUNC = "CryptMsgDllGenEncryptKey"

'typedef BOOL (WINAPI *PFN_CMSG_GEN_ENCRYPT_KEY) (
'    IN OUT HCRYPTPROV               *phCryptProv,
'    IN PCRYPT_ALGORITHM_IDENTIFIER  paiEncrypt,
'    IN PVOID                        pvEncryptAuxInfo,
'    IN PCERT_PUBLIC_KEY_INFO        pPublicKeyInfo,
'    IN PFN_CMSG_ALLOC               pfnAlloc,
'    OUT HCRYPTKEY                   *phEncryptKey,
'    OUT PBYTE                       *ppbEncryptParameters,
'    OUT PDWORD                      pcbEncryptParameters
'    );

'typedef BOOL (WINAPI *PFN_CMSG_GEN_ENCRYPT_KEY) (
'    IN OUT HCRYPTPROV               *phCryptProv,
'    IN PCRYPT_ALGORITHM_IDENTIFIER  paiEncrypt,
'    IN PVOID                        pvEncryptAuxInfo,
'    IN PCERT_PUBLIC_KEY_INFO        pPublicKeyInfo,
'    IN PFN_CMSG_ALLOC               pfnAlloc,
'    OUT HCRYPTKEY                   *phEncryptKey,
'    OUT PBYTE                       *ppbEncryptParameters,
'    OUT PDWORD                      pcbEncryptParameters
'    );

'FUNCTION CMSG_GEN_ENCRYPT_KEY ( _
'   BYREF phCryptProv AS DWORD, _                        ' __inout HCRYPTPROV               *phCryptProv,
'   BYREF paiEncrypt AS CRYPT_ALGORITHM_IDENTIFIER, _    ' __in PCRYPT_ALGORITHM_IDENTIFIER  paiEncrypt,
'   BYVAL pvEncryptAuxInfo AS DWORD, _                   ' __in PVOID                        pvEncryptAuxInfo,
'   BYREF pPublicKeyInfo AS CERT_PUBLIC_KEY_INFO, _      ' __in PCERT_PUBLIC_KEY_INFO        pPublicKeyInfo,
'   BYVAL pfnAlloc AS DWORD, _                           ' __in PFN_CMSG_ALLOC               pfnAlloc,
'   BYREF phEncryptKey AS DWORD, _                       ' __out HCRYPTKEY                   *phEncryptKey,
'   BYREF ppbEncryptParameters AS DWORD, _               ' __out PBYTE                       *ppbEncryptParameters,
'   BYREF pcbEncryptParameters AS DWORD _                ' __out PDWORD                      pcbEncryptParameters
'   ) AS LONG                                            ' BOOL

$CMSG_OID_EXPORT_ENCRYPT_KEY_FUNC = "CryptMsgDllExportEncryptKey"

'typedef BOOL (WINAPI *PFN_CMSG_EXPORT_ENCRYPT_KEY) (
'    IN HCRYPTPROV                   hCryptProv,
'    IN HCRYPTKEY                    hEncryptKey,
'    IN PCERT_PUBLIC_KEY_INFO        pPublicKeyInfo,
'    OUT PBYTE                       pbData,
'    IN OUT PDWORD                   pcbData
'    );

'FUNCTION CMSG_EXPORT_ENCRYPT_KEY ( _
'   BYVAL hCryptProv AS DWORD, _                         ' __in HCRYPTPROV                   hCryptProv,
'   BYVAL hEncryptKey AS DWORD, _                        ' __in HCRYPTKEY                    hEncryptKey,
'   BYREF pPublicKeyInfo AS CERT_PUBLIC_KEY_INFO, _      ' __in PCERT_PUBLIC_KEY_INFO        pPublicKeyInfo,
'   BYREF pbData AS DWORD, _                             ' __out PBYTE                       pbData,
'   BYREF pcbData AS DWORD _                             ' __inout PDWORD                   pcbData
'   ) AS LONG                                            ' BOOL

$CMSG_OID_IMPORT_ENCRYPT_KEY_FUNC = "CryptMsgDllImportEncryptKey"

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_ENCRYPT_KEY) (
'    IN HCRYPTPROV                   hCryptProv,
'    IN DWORD                        dwKeySpec,
'    IN PCRYPT_ALGORITHM_IDENTIFIER  paiEncrypt,
'    IN PCRYPT_ALGORITHM_IDENTIFIER  paiPubKey,
'    IN PBYTE                        pbEncodedKey,
'    IN DWORD                        cbEncodedKey,
'    OUT HCRYPTKEY                   *phEncryptKey
'    );

'FUNCTION CMSG_IMPORT_ENCRYPT_KEY ( _
'   BYVAL hCryptProv AS DWORD, _                         ' __in HCRYPTPROV                   hCryptProv,
'   BYVAL dwKeySpec AS DWORD, _                          ' __in DWORD                        dwKeySpec,
'   BYREF paiEncrypt AS CRYPT_ALGORITHM_IDENTIFIER, _    ' __in PCRYPT_ALGORITHM_IDENTIFIER  paiEncrypt,
'   BYREF paiPubKey AS CRYPT_ALGORITHM_IDENTIFIER, _     ' __in PCRYPT_ALGORITHM_IDENTIFIER  paiPubKey,
'   BYVAL pbEncodedKey AS BYTE PTR, _                    ' __in PBYTE                        pbEncodedKey,
'   BYVAL cbEncodedKey AS DWORD, _                       ' __in DWORD                        cbEncodedKey,
'   BYREF phEncryptKey AS DWORD _                        ' __out HCRYPTKEY                   *phEncryptKey
'   ) AS LONG                                            ' BOOL

'// To get the default installable function for GenContentEncryptKey,
'// ExportKeyTrans, ExportKeyAgree, ExportMailList, ImportKeyTrans,
'// ImportKeyAgree or ImportMailList call CryptGetOIDFunctionAddress()
'// with the pszOID argument set to the following constant. dwEncodingType
'// should be set to CRYPT_ASN_ENCODING or X509_ASN_ENCODING.
'#define CMSG_DEFAULT_INSTALLABLE_FUNC_OID   ((LPCSTR) 1)
%CMSG_DEFAULT_INSTALLABLE_FUNC_OID = 1

'//+-------------------------------------------------------------------------
'//  Content Encrypt Info
'//
'//  The following data structure contains the information shared between
'//  the GenContentEncryptKey and the ExportKeyTrans, ExportKeyAgree and
'//  ExportMailList installable functions.
'//
'//  For a ContentEncryptionAlgorithm.pszObjId having a "Special" algid, only
'//  supported via CNG, for example, AES, then, fCNG will be set.
'//  fCNG will also be set to TRUE for any ECC agreement or OAEP RSA transport
'//  recipients.
'//
'//  When, fCNG is TRUE, the hCNGContentEncryptKey choice is selected and
'//  pbCNGContentEncryptKeyObject and pbContentEncryptKey will be pfnAlloc'ed.
'//--------------------------------------------------------------------------

UNION CMSG_CONTENT_ENCRYPT_INFO_UNION
   ' // fCNG == FALSE
   hContentEncryptKey    AS DWORD   ' HCRYPTKEY
   ' // fCNG == TRUE
   hCNGContentEncryptKey AS DWORD   ' BCRYPT_KEY_HANDLE
END UNION

' // Size = 68 bytes
TYPE CMSG_CONTENT_ENCRYPT_INFO DWORD
   cbSize                       AS DWORD                            ' DWORD
   hCryptProv                   AS DWORD                            ' HCRYPTPROV
   ContentEncryptionAlgorithm   AS CRYPT_ALGORITHM_IDENTIFIER       ' CRYPT_ALGORITHM_IDENTIFIER
   pvEncryptionAuxInfo          AS DWORD                            ' void*
   cRecipients                  AS DWORD                            ' DWORD
   rgCmsRecipients              AS CMSG_RECIPIENT_ENCODE_INFO PTR   ' PCMSG_RECIPIENT_ENCODE_INFO
   pfnAlloc                     AS DWORD                            ' PFN_CMSG_ALLOC
   pfnFree                      AS DWORD                            ' PFN_CMSG_FREE
   dwEncryptFlags               AS DWORD                            ' DWORD
   CMSG_CONTENT_ENCRYPT_INFO_UNION
   dwFlags                      AS DWORD                            ' DWORD
   fCNG                         AS LONG                             ' BOOL
   ' // When fCNG == TRUE, pfnAlloc'ed
   pbCNGContentEncryptKeyObject AS BYTE PTR                         ' BYTE *
   pbContentEncryptKey          AS BYTE PTR                         ' BYTE *
   cbContentEncryptKey          AS DWORD                            ' DWORD
END TYPE

%CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG   = &H00000001???

%CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG         = &H00000001???
%CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG   = &H00008000???
%CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG   = &H00008000???

'//+-------------------------------------------------------------------------
'// Upon input, ContentEncryptInfo has been initialized from the
'// EnvelopedEncodeInfo.
'//
'// Note, if rgpRecipients instead of rgCmsRecipients are set in the
'// EnvelopedEncodeInfo, then, the rgpRecipients have been converted
'// to rgCmsRecipients in the ContentEncryptInfo.
'//
'// The following fields may be changed in ContentEncryptInfo:
'//      hContentEncryptKey
'//      hCryptProv
'//      ContentEncryptionAlgorithm.Parameters
'//      dwFlags
'//
'// All other fields in the ContentEncryptInfo are READONLY.
'//
'// If CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG is set upon entry
'// in dwEncryptFlags, then, any potentially variable length encoded
'// output should be padded with zeroes to always obtain the
'// same maximum encoded length. This is necessary for
'// CryptMsgCalculateEncodedLength() or CryptMsgOpenToEncode() with
'// definite length streaming.
'//
'// The hContentEncryptKey must be updated.
'//
'// If hCryptProv is NULL upon input, then, it must be updated.
'// If a HCRYPTPROV is acquired that must be released, then, the
'// CMSG_CONTENT_ENCRYPT_RELEASE_CONTEXT_FLAG must be set in dwFlags.
'//
'// If ContentEncryptionAlgorithm.Parameters is updated, then, the
'// CMSG_CONTENT_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags. pfnAlloc and
'// pfnFree must be used for doing the allocation.
'//
'// ContentEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------

'// The following CAPI1 installable function is called when fCNG == FALSE.
$CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC = "CryptMsgDllGenContentEncryptKey"
$CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC = $CMSG_OID_GEN_CONTENT_ENCRYPT_KEY_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY) (
'    IN OUT PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved
'    );

'FUNCTION CMSG_GEN_CONTENT_ENCRYPT_KEY ( _
'   BYREF pContentEncryptInfo AS CMSG_CONTENT_ENCRYPT_INFO, _  ' __inout PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo
'   BYVAL dwFlags AS DWORD, _                                  ' __in DWORD dwFlags
'   OPTIONAL BYVAL pvReserved AS DWORD _                       ' __in_opt void *pvReserved
' ) AS LONG                                                    ' BOOL

'// The following installable function is called when fCNG == TRUE. It has the
'// same API signature as for the above
'// CMSG_OID_CAPI1_GEN_CONTENT_ENCRYPT_KEY_FUNC.
$CMSG_OID_CNG_GEN_CONTENT_ENCRYPT_KEY_FUNC  = "CryptMsgDllCNGGenContentEncryptKey"

'//+-------------------------------------------------------------------------
'//  Key Transport Encrypt Info
'//
'//  The following data structure contains the information updated by the
'//  ExportKeyTrans installable function.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CMSG_KEY_TRANS_ENCRYPT_INFO DWORD
   cbSize                 AS DWORD
   dwRecipientIndex       AS DWORD
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedKey           AS CRYPT_DATA_BLOB
   dwFlags                AS DWORD
END TYPE

%CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG  = &H00000001???
%CMSG_KEY_TRANS_ENCRYPT_FREE_OBJID_FLAG = &H00000002???


'//+-------------------------------------------------------------------------
'// Upon input, KeyTransEncryptInfo has been initialized from the
'// KeyTransEncodeInfo.
'//
'// The following fields may be changed in KeyTransEncryptInfo:
'//      EncryptedKey
'//      KeyEncryptionAlgorithm.Parameters
'//      dwFlags
'//
'// All other fields in the KeyTransEncryptInfo are READONLY.
'//
'// The EncryptedKey must be updated. The pfnAlloc and pfnFree specified in
'// ContentEncryptInfo must be used for doing the allocation.
'//
'// If the KeyEncryptionAlgorithm.Parameters is updated, then, the
'// CMSG_KEY_TRANS_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
'// The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
'// for doing the allocation.
'//
'// KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------

'// The following CAPI1 installable function is called when
'// pContentEncryptInfo->fCNG == FALSE.
$CMSG_OID_EXPORT_KEY_TRANS_FUNC = "CryptMsgDllExportKeyTrans"
$CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC = $CMSG_OID_EXPORT_KEY_TRANS_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_EXPORT_KEY_TRANS) (
'    IN PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
'    IN PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTransEncodeInfo,
'    IN OUT PCMSG_KEY_TRANS_ENCRYPT_INFO pKeyTransEncryptInfo,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved
'    );

'FUNCTION CMSG_EXPORT_KEY_TRANS ( _
'   BYREF pContentEncryptInfo AS CMSG_CONTENT_ENCRYPT_INFO, _            ' __in PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo
'   BYREF pKeyTransEncodeInfo AS CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, _ ' __in PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTransEncodeInfo
'   BYREF pKeyTransEncryptInfo AS CMSG_KEY_TRANS_ENCRYPT_INFO, _         ' __inout PCMSG_KEY_TRANS_ENCRYPT_INFO pKeyTransEncryptInfo
'   BYVAL dwFlags AS DWORD, _                                            ' __in DWORD dwFlags
'   OPTIONAL BYVAL pvReserved AS DWORD _                                 ' __in_opt void *pvReserved
'   ) AS LONG                                                            ' BOOL

'// The following CNG installable function is called when
'// pContentEncryptInfo->fCNG == TRUE. It has the same API signature as for
'// the above CMSG_OID_CAPI1_EXPORT_KEY_TRANS_FUNC.
$CMSG_OID_CNG_EXPORT_KEY_TRANS_FUNC = "CryptMsgDllCNGExportKeyTrans"

'//+-------------------------------------------------------------------------
'//  Key Agree Key Encrypt Info
'//
'//  The following data structure contains the information updated by the
'//  ExportKeyAgree installable function for each encrypted key agree
'//  recipient.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CMSG_KEY_AGREE_KEY_ENCRYPT_INFO DWORD
   cbSize       AS DWORD
   EncryptedKey AS CRYPT_DATA_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Key Agree Encrypt Info
'//
'//  The following data structure contains the information applicable to
'//  all recipients. Its updated by the ExportKeyAgree installable function.
'//--------------------------------------------------------------------------
'typedef struct _CMSG_KEY_AGREE_ENCRYPT_INFO {
'    DWORD                       cbSize;
'    DWORD                       dwRecipientIndex;
'    CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
'    CRYPT_DATA_BLOB             UserKeyingMaterial;
'    DWORD                       dwOriginatorChoice;
'    union {
'        // CMSG_KEY_AGREE_ORIGINATOR_CERT
'        CERT_ID                     OriginatorCertId;
'        // CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY
'        CERT_PUBLIC_KEY_INFO        OriginatorPublicKeyInfo;
'    };
'    DWORD                       cKeyAgreeKeyEncryptInfo;
'    PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO *rgpKeyAgreeKeyEncryptInfo;
'    DWORD                       dwFlags;
'} CMSG_KEY_AGREE_ENCRYPT_INFO, *PCMSG_KEY_AGREE_ENCRYPT_INFO;

' // Size = 24 bytes
UNION CMSG_KEY_AGREE_ENCRYPT_INFO_UNION DWORD
   OriginatorCertId        AS CERT_ID
   OriginatorPublicKeyInfo AS CERT_PUBLIC_KEY_INFO
END UNION

' // Size = 68 bytes
TYPE CMSG_KEY_AGREE_ENCRYPT_INFO DWORD
   cbSize                    AS DWORD
   dwRecipientIndex          AS DWORD
   KeyEncryptionAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   UserKeyingMaterial        AS CRYPT_DATA_BLOB
   dwOriginatorChoice        AS DWORD
   CMSG_KEY_AGREE_ENCRYPT_INFO_UNION
   cKeyAgreeKeyEncryptInfo   AS DWORD
   rgpKeyAgreeKeyEncryptInfo AS CMSG_KEY_AGREE_KEY_ENCRYPT_INFO PTR
   dwFlags                   AS DWORD
END TYPE

%CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG           = &H00000001???
%CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG       = &H00000002???
%CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_ALG_FLAG     = &H00000004???
%CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_PARA_FLAG    = &H00000008???
%CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_BITS_FLAG    = &H00000010???
%CMSG_KEY_AGREE_ENCRYPT_FREE_OBJID_FLAG          = &H00000020???

'//+-------------------------------------------------------------------------
'// Upon input, KeyAgreeEncryptInfo has been initialized from the
'// KeyAgreeEncodeInfo.
'//
'// The following fields may be changed in KeyAgreeEncryptInfo:
'//      KeyEncryptionAlgorithm.Parameters
'//      UserKeyingMaterial
'//      dwOriginatorChoice
'//      OriginatorCertId
'//      OriginatorPublicKeyInfo
'//      dwFlags
'//
'// All other fields in the KeyAgreeEncryptInfo are READONLY.
'//
'// If the KeyEncryptionAlgorithm.Parameters is updated, then, the
'// CMSG_KEY_AGREE_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
'// The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
'// for doing the allocation.
'//
'// If the UserKeyingMaterial is updated, then, the
'// CMSG_KEY_AGREE_ENCRYPT_FREE_MATERIAL_FLAG must be set in dwFlags.
'// pfnAlloc and pfnFree must be used for doing the allocation.
'//
'// The dwOriginatorChoice must be updated to either
'// CMSG_KEY_AGREE_ORIGINATOR_CERT or CMSG_KEY_AGREE_ORIGINATOR_PUBLIC_KEY.
'//
'// If the OriginatorPublicKeyInfo is updated, then, the appropriate
'// CMSG_KEY_AGREE_ENCRYPT_FREE_PUBKEY_*_FLAG must be set in dwFlags and
'// pfnAlloc and pfnFree must be used for doing the allocation.
'//
'// If CMSG_CONTENT_ENCRYPT_PAD_ENCODED_LEN_FLAG is set upon entry
'// in pContentEncryptInfo->dwEncryptFlags, then, the OriginatorPublicKeyInfo's
'// Ephemeral PublicKey should be padded with zeroes to always obtain the
'// same maximum encoded length. Note, the length of the generated ephemeral Y
'// public key can vary depending on the number of leading zero bits.
'//
'// Upon input, the array of *rgpKeyAgreeKeyEncryptInfo has been initialized.
'// The EncryptedKey must be updated for each recipient key.
'// The pfnAlloc and pfnFree specified in
'// ContentEncryptInfo must be used for doing the allocation.
'//
'// KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------

'// The following CAPI1 installable function is called when
'// pContentEncryptInfo->fCNG == FALSE.
$CMSG_OID_EXPORT_KEY_AGREE_FUNC = "CryptMsgDllExportKeyAgree"
$CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC = $CMSG_OID_EXPORT_KEY_AGREE_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_EXPORT_KEY_AGREE) (
'    IN PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
'    IN PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgreeEncodeInfo,
'    IN OUT PCMSG_KEY_AGREE_ENCRYPT_INFO pKeyAgreeEncryptInfo,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved
'    );

'FUNCTION CMSG_EXPORT_KEY_AGREE ( _
'   BYREF pContentEncryptInfo AS CMSG_CONTENT_ENCRYPT_INFO, _             ' __in PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo
'   BYREF pKeyAgreeEncodeInfo AS CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, _  ' __in PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgreeEncodeInfo
'   BYREF pKeyAgreeEncryptInfo AS CMSG_KEY_AGREE_ENCRYPT_INFO, _          ' __inout PCMSG_KEY_AGREE_ENCRYPT_INFO pKeyAgreeEncryptInfo
'   BYVAL dwFlags AS DWORD, _                                             ' __in DWORD dwFlags
'   OPTIONAL BYVAL pvReserved AS DWORD _                                  ' __in_opt void *pvReserved
' ) AS LONG                                                               ' BOOL

'// The following CNG installable function is called when
'// pContentEncryptInfo->fCNG == TRUE. It has the same API signature as for
'// the above CMSG_OID_CAPI1_EXPORT_KEY_AGREE_FUNC.
$CMSG_OID_CNG_EXPORT_KEY_AGREE_FUNC = "CryptMsgDllCNGExportKeyAgree"

'//+-------------------------------------------------------------------------
'//  Mail List Encrypt Info
'//
'//  The following data structure contains the information updated by the
'//  ExportMailList installable function.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CMSG_MAIL_LIST_ENCRYPT_INFO DWORD
   cbSize                 AS DWORD
   dwRecipientIndex       AS DWORD
   KeyEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   EncryptedKey           AS CRYPT_DATA_BLOB
   dwFlags                AS DWORD
END TYPE

%CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG  = &H00000001???
%CMSG_MAIL_LIST_ENCRYPT_FREE_OBJID_FLAG = &H00000002???

'//+-------------------------------------------------------------------------
'// Upon input, MailListEncryptInfo has been initialized from the
'// MailListEncodeInfo.
'//
'// The following fields may be changed in MailListEncryptInfo:
'//      EncryptedKey
'//      KeyEncryptionAlgorithm.Parameters
'//      dwFlags
'//
'// All other fields in the MailListEncryptInfo are READONLY.
'//
'// The EncryptedKey must be updated. The pfnAlloc and pfnFree specified in
'// ContentEncryptInfo must be used for doing the allocation.
'//
'// If the KeyEncryptionAlgorithm.Parameters is updated, then, the
'// CMSG_MAIL_LIST_ENCRYPT_FREE_PARA_FLAG must be set in dwFlags.
'// The pfnAlloc and pfnFree specified in ContentEncryptInfo must be used
'// for doing the allocation.
'//
'// KeyEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------

'// The following CAPI1 installable function is called when
'// pContentEncryptInfo->fCNG == FALSE.
$CMSG_OID_EXPORT_MAIL_LIST_FUNC = "CryptMsgDllExportMailList"
$CMSG_OID_CAPI1_EXPORT_MAIL_LIST_FUNC = $CMSG_OID_EXPORT_MAIL_LIST_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_EXPORT_MAIL_LIST) (
'    IN PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
'    IN PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailListEncodeInfo,
'    IN OUT PCMSG_MAIL_LIST_ENCRYPT_INFO pMailListEncryptInfo,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved
'    );

'FUNCTION CMSG_EXPORT_MAIL_LIST ( _
'   BYREF pContentEncryptInfo AS CMSG_CONTENT_ENCRYPT_INFO, _            ' __in PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo
'   BYREF pMailListEncodeInfo AS CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, _ ' __in PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailListEncodeInfo
'   BYREF pMailListEncryptInfo AS CMSG_MAIL_LIST_ENCRYPT_INFO, _         ' __inout PCMSG_MAIL_LIST_ENCRYPT_INFO pMailListEncryptInfo
'   BYVAL dwFlags AS DWORD, _                                            ' __in DWORD dwFlags
'   OPTIONAL BYVAL pvReserved AS DWORD _                                 ' __in_opt void *pvReserved
' ) AS LONG                                                              ' BOOL

'//+-------------------------------------------------------------------------
'// OID Installable functions for importing an encoded and encrypted content
'// encryption key.
'//
'// There's a different installable function for each CMS Recipient choice:
'//  ImportKeyTrans
'//  ImportKeyAgree
'//  ImportMailList
'//
'// Iterates through the following OIDs to get the OID installable function:
'//   KeyEncryptionOID!ContentEncryptionOID
'//   KeyEncryptionOID
'//   ContentEncryptionOID
'//
'// If the OID installable function doesn't support the specified
'// KeyEncryption and ContentEncryption OIDs, then, return FALSE with
'// LastError set to E_NOTIMPL.
'//--------------------------------------------------------------------------

$CMSG_OID_IMPORT_KEY_TRANS_FUNC = "CryptMsgDllImportKeyTrans"
$CMSG_OID_CAPI1_IMPORT_KEY_TRANS_FUNC = $CMSG_OID_IMPORT_KEY_TRANS_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_KEY_TRANS) (
'    IN PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
'    IN PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved,
'    OUT HCRYPTKEY *phContentEncryptKey
'    );

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_KEY_TRANS) (
'   BYREF pContentEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER, _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm
'   BYREF pKeyTransDecryptPara AS CMSG_CTRL_KEY_TRANS_DECRYPT_PARA, _  ' __in PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara
'   BYVAL dwFlags AS DWORD, _                                          ' __in DWORD dwFlags
'   BYVAL pvReserved AS DWORD, _                                       ' __in_opt void *pvReserved
'   BYREF phContentEncryptKey AS DWORD _                               ' __out HCRYPTKEY *phContentEncryptKey
' ) AS LONG                                                            ' BOOL

$CMSG_OID_IMPORT_KEY_AGREE_FUNC = "CryptMsgDllImportKeyAgree"
$CMSG_OID_CAPI1_IMPORT_KEY_AGREE_FUNC = $CMSG_OID_IMPORT_KEY_AGREE_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_KEY_AGREE) (
'    IN PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
'    IN PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved,
'    OUT HCRYPTKEY *phContentEncryptKey
'    );

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_KEY_AGREE) (
'   BYREF CRYPT_ALGORITHM_IDENTIFIER, _       ' I PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm
'   BYREF CMSG_CTRL_KEY_AGREE_DECRYPT_PARA, _ ' __in PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara
'   BYVAL DWORD, _                            ' __in DWORD dwFlags
'   BYVAL DWORD, _                            ' __in_opt void *pvReserved
'   BYREF DWORD _                             ' __out HCRYPTKEY *phContentEncryptKey
' ) AS LONG                                   ' BOOL

$CMSG_OID_IMPORT_MAIL_LIST_FUNC = "CryptMsgDllImportMailList"
$CMSG_OID_CAPI1_IMPORT_MAIL_LIST_FUNC  = $CMSG_OID_IMPORT_MAIL_LIST_FUNC

'typedef BOOL (WINAPI *PFN_CMSG_IMPORT_MAIL_LIST) (
'    IN PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
'    IN PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA pMailListDecryptPara,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved,
'    OUT HCRYPTKEY *phContentEncryptKey
'    );

'FUNCTION CMSG_IMPORT_MAIL_LIST ( _
'   BYREF pContentEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER, _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm
'   BYREF pMailListDecryptPara AS CMSG_CTRL_MAIL_LIST_DECRYPT_PARA, _  ' __in PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA pMailListDecryptPara
'   BYVAL dwFlags AS DWORD, _                                          ' __in DWORD dwFlags
'   BYVAL pvReserved AS DWORD, _                                       ' __in_opt void *pvReserved
'   BYREF phContentEncryptKey AS DWORD _                               ' __out HCRYPTKEY *phContentEncryptKey
' ) AS LONG                                                            ' BOOL

'//+-------------------------------------------------------------------------
'//  CNG Content Decrypt Info
'//
'//  The following data structure contains the information shared between
'//  CNGImportKeyTrans, CNGImportKeyAgree and CNGImportContentEncryptKey
'//  installable functions.
'//
'//  pbContentEncryptKey and pbCNGContentEncryptKeyObject are allocated
'//  and freed via pfnAlloc and pfnFree.
'//--------------------------------------------------------------------------
' // Size = 44 bytes
TYPE CMSG_CNG_CONTENT_DECRYPT_INFO DWORD
   cbSize                        AS DWORD      ' DWORD
   ContentEncryptionAlgorithm    AS CRYPT_ALGORITHM_IDENTIFIER
   pfnAlloc                      AS DWORD      ' PFN_CMSG_ALLOC
   pfnFree                       AS DWORD      ' PFN_CMSG_FREE
   ' // This key must be used over the one in the DecryptPara. An
   ' // HCRYPTPROV in the DecryptPara may have been converted to a
   ' // NCRYPT_KEY_HANDLE.
   hNCryptKey                    AS DWORD      ' NCRYPT_KEY_HANDLE
   pbContentEncryptKey           AS BYTE PTR   ' BYTE *
   cbContentEncryptKey           AS DWORD      ' DWORD
   hCNGContentEncryptKey         AS DWORD      ' BCRYPT_KEY_HANDLE
   pbCNGContentEncryptKeyObject  AS BYTE PTR   ' BYTE *
END TYPE

'//+-------------------------------------------------------------------------
'// CNG OID Installable function for importing and decrypting a key transport
'// recipient encrypted content encryption key.
'//
'// Upon input, CNGContentDecryptInfo has been initialized.
'//
'// The following fields must be updated using hNCryptKey to decrypt
'// pKeyTransDecryptPara->pKeyTrans->EncryptedKey.
'//      pbContentEncryptKey (pfnAlloc'ed)
'//      cbContentEncryptKey
'//
'// All other fields in the CNGContentEncryptInfo are READONLY.
'//
'// pKeyTransDecryptPara->pKeyTrans->KeyEncryptionAlgorithm.pszObjId is used
'// to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------
$CMSG_OID_CNG_IMPORT_KEY_TRANS_FUNC = "CryptMsgDllCNGImportKeyTrans"
'typedef BOOL (WINAPI *PFN_CMSG_CNG_IMPORT_KEY_TRANS) (
'    __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
'    __in PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
'    __in DWORD dwFlags,
'    __reserved void *pvReserved
'    );

'FUNCTION CMSG_CNG_IMPORT_KEY_TRANS ( _
'   BYREF pCNGContentDecryptInfo AS CMSG_CNG_CONTENT_DECRYPT_INFO _   ' __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo
' , BYREF pKeyTransDecryptPara AS CMSG_CTRL_KEY_TRANS_DECRYPT_PARA _  ' __in PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara
' , BYVAL dwFlags AS DWORD _                                          ' __in DWORD dwFlags
' , BYVAL pvReserved AS DWORD _                                       ' __reserved void *pvReserved
' ) AS LONG                                                           ' BOOL

'//+-------------------------------------------------------------------------
'// CNG OID Installable function for importing and decrypting a key agreement
'// recipient encrypted content encryption key.
'//
'// Upon input, CNGContentDecryptInfo has been initialized.
'//
'// The following fields must be updated using hNCryptKey to decrypt
'// pKeyAgreeDecryptPara->pKeyAgree->rgpRecipientEncryptedKeys[
'//  pKeyAgreeDecryptPara->dwRecipientEncryptedKeyIndex]->EncryptedKey.
'//      pbContentEncryptKey (pfnAlloc'ed)
'//      cbContentEncryptKey
'//
'// All other fields in the CNGContentEncryptInfo are READONLY.
'//
'// pKeyAgreeDecryptPara->pKeyAgree->KeyEncryptionAlgorithm.pszObjId is used
'// to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------
$CMSG_OID_CNG_IMPORT_KEY_AGREE_FUNC = "CryptMsgDllCNGImportKeyAgree"
'typedef BOOL (WINAPI *PFN_CMSG_CNG_IMPORT_KEY_AGREE) (
'    __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
'    __in PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
'    __in DWORD dwFlags,
'    __reserved void *pvReserved
'    );

'FUNCTION CMSG_CNG_IMPORT_KEY_AGREE ( _
'   BYREF pCNGContentDecryptInfo AS CMSG_CNG_CONTENT_DECRYPT_INFO _   ' __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo
' , BYREF pKeyTransDecryptPara AS CMSG_CTRL_KEY_TRANS_DECRYPT_PARA _  ' __in PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara
' , BYVAL dwFlags AS DWORD _                                          ' __in DWORD dwFlags
' , BYVAL pvReserved AS DWORD _                                       ' __reserved void *pvReserved
' ) AS LONG                                                           ' BOOL

'//+-------------------------------------------------------------------------
'// CNG OID Installable function for importing an already decrypted
'// content encryption key.
'//
'// Upon input, CNGContentDecryptInfo has been initialized.
'//
'// The following fields must be updated using pbContentEncryptKey and
'// cbContentEncryptKey:
'//      hCNGContentEncryptKey
'//      pbCNGContentEncryptKeyObject (pfnAlloc'ed)
'//
'// The hCNGContentEncryptKey will be destroyed when hCryptMsg is closed.
'//
'// All other fields in the CNGContentEncryptInfo are READONLY.
'//
'// ContentEncryptionAlgorithm.pszObjId is used to get the OIDFunctionAddress.
'//--------------------------------------------------------------------------
$CMSG_OID_CNG_IMPORT_CONTENT_ENCRYPT_KEY_FUNC = "CryptMsgDllCNGImportContentEncryptKey"
'typedef BOOL (WINAPI *PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY) (
'    __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
'    __in DWORD dwFlags,
'    __reserved void *pvReserved
'    );

'FUNCTION CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY ( _
'   BYREF pCNGContentDecryptInfo AS CMSG_CNG_CONTENT_DECRYPT_INFO _   ' __inout PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo
' , BYVAL dwFlags AS DWORD _                                          ' __in DWORD dwFlags
' , BYVAL pvReserved AS DWORD _                                       ' __reserved void *pvReserved
' ) AS LONG                                                           ' BOOL

'//+=========================================================================
'//  Certificate Store Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//              In its most basic implementation, a cert store is simply a
'//              collection of certificates and/or CRLs. This is the case when
'//              a cert store is opened with all of its certificates and CRLs
'//              coming from a PKCS #7 encoded cryptographic message.
'//
'//              Nonetheless, all cert stores have the following properties:
'//               - A public key may have more than one certificate in the store.
'//                 For example, a private/public key used for signing may have a
'//                 certificate issued for VISA and another issued for
'//                 Mastercard. Also, when a certificate is renewed there might
'//                 be more than one certificate with the same subject and
'//                 issuer.
'//               - However, each certificate in the store is uniquely
'//                 identified by its Issuer and SerialNumber.
'//               - There's an issuer of subject certificate relationship. A
'//                 certificate's issuer is found by doing a match of
'//                 pSubjectCert->Issuer with pIssuerCert->Subject.
'//                 The relationship is verified by using
'//                 the issuer's public key to verify the subject certificate's
'//                 signature. Note, there might be X.509 v3 extensions
'//                 to assist in finding the issuer certificate.
'//               - Since issuer certificates might be renewed, a subject
'//                 certificate might have more than one issuer certificate.
'//               - There's an issuer of CRL relationship. An
'//                 issuer's CRL is found by doing a match of
'//                 pIssuerCert->Subject with pCrl->Issuer.
'//                 The relationship is verified by using
'//                 the issuer's public key to verify the CRL's
'//                 signature. Note, there might be X.509 v3 extensions
'//                 to assist in finding the CRL.
'//               - Since some issuers might support the X.509 v3 delta CRL
'//                 extensions, an issuer might have more than one CRL.
'//               - The store shouldn't have any redundant certificates or
'//                 CRLs. There shouldn't be two certificates with the same
'//                 Issuer and SerialNumber. There shouldn't be two CRLs with
'//                 the same Issuer, ThisUpdate and NextUpdate.
'//               - The store has NO policy or trust information. No
'//                 certificates are tagged as being "root". Its up to
'//                 the application to maintain a list of CertIds (Issuer +
'//                 SerialNumber) for certificates it trusts.
'//               - The store might contain bad certificates and/or CRLs.
'//                 The issuer's signature of a subject certificate or CRL may
'//                 not verify. Certificates or CRLs may not satisfy their
'//                 time validity requirements. Certificates may be
'//                 revoked.
'//
'//              In addition to the certificates and CRLs, properties can be
'//              stored. There are two predefined property IDs for a user
'//              certificate: CERT_KEY_PROV_HANDLE_PROP_ID and
'//              CERT_KEY_PROV_INFO_PROP_ID. The CERT_KEY_PROV_HANDLE_PROP_ID
'//              is a HCRYPTPROV handle to the private key assoicated
'//              with the certificate. The CERT_KEY_PROV_INFO_PROP_ID contains
'//              information to be used to call
'//              CryptAcquireContext and CryptSetProvParam to get a handle
'//              to the private key associated with the certificate.
'//
'//              There exists two more predefined property IDs for certificates
'//              and CRLs, CERT_SHA1_HASH_PROP_ID and CERT_MD5_HASH_PROP_ID.
'//              If these properties don't already exist, then, a hash of the
'//              content is computed. (CERT_HASH_PROP_ID maps to the default
'//              hash algorithm, currently, CERT_SHA1_HASH_PROP_ID).
'//
'//              There are additional APIs for creating certificate and CRL
'//      contexts not in a store (CertCreateCertificateContext and
'//      CertCreateCRLContext).
'//
'//--------------------------------------------------------------------------

'typedef void *HCERTSTORE;

'//+-------------------------------------------------------------------------
'//  Certificate context.
'//
'//  A certificate context contains both the encoded and decoded representation
'//  of a certificate. A certificate context returned by a cert store function
'//  must be freed by calling the CertFreeCertificateContext function. The
'//  CertDuplicateCertificateContext function can be called to make a duplicate
'//  copy (which also must be freed by calling CertFreeCertificateContext).
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CERT_CONTEXT DWORD
   dwCertEncodingType AS DWORD           ' DWORD
   pbCertEncoded      AS BYTE PTR        ' BYTE*
   cbCertEncoded      AS DWORD           ' DWORD
   pCertInfo          AS CERT_INFO PTR   ' PCERT_INFO
   hCertStore         AS DWORD           ' HCERTSTORE
END TYPE

'//+-------------------------------------------------------------------------
'//  CRL context.
'//
'//  A CRL context contains both the encoded and decoded representation
'//  of a CRL. A CRL context returned by a cert store function
'//  must be freed by calling the CertFreeCRLContext function. The
'//  CertDuplicateCRLContext function can be called to make a duplicate
'//  copy (which also must be freed by calling CertFreeCRLContext).
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRL_CONTEXT DWORD
   dwCertEncodingType AS DWORD          ' DWORD
   pbCrlEncoded       AS BYTE PTR       ' BYTE*
   cbCrlEncoded       AS DWORD          ' DWORD
   pCrlInfo           AS CRL_INFO PTR   ' PCRL_INFO
   hCertStore         AS DWORD          ' HCERTSTORE
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate Trust List (CTL) context.
'//
'//  A CTL context contains both the encoded and decoded representation
'//  of a CTL. Also contains an opened HCRYPTMSG handle to the decoded
'//  cryptographic signed message containing the CTL_INFO as its inner content.
'//  pbCtlContent is the encoded inner content of the signed message.
'//
'//  The CryptMsg APIs can be used to extract additional signer information.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CTL_CONTEXT DWORD
   dwMsgAndCertEncodingType AS DWORD          ' DWORD
   pbCtlEncoded             AS BYTE PTR       ' BYTE*
   cbCtlEncoded             AS DWORD          ' DWORD
   pCtlInfo                 AS CTL_INFO PTR   ' PCTL_INFO
   hCertStore               AS DWORD          ' HCERTSTORE
   hCryptMsg                AS DWORD          ' HCRYPTMSG
   pbCtlContent             AS BYTE PTR       ' BYTE*
   cbCtlContent             AS DWORD          ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate, CRL and CTL property IDs
'//
'//  See CertSetCertificateContextProperty or CertGetCertificateContextProperty
'//  for usage information.
'//--------------------------------------------------------------------------
%CERT_KEY_PROV_HANDLE_PROP_ID                 = 1???
%CERT_KEY_PROV_INFO_PROP_ID                   = 2???
%CERT_SHA1_HASH_PROP_ID                       = 3???
%CERT_MD5_HASH_PROP_ID                        = 4???
%CERT_HASH_PROP_ID                            = %CERT_SHA1_HASH_PROP_ID
%CERT_KEY_CONTEXT_PROP_ID                     = 5???
%CERT_KEY_SPEC_PROP_ID                        = 6???
%CERT_IE30_RESERVED_PROP_ID                   = 7???
%CERT_PUBKEY_HASH_RESERVED_PROP_ID            = 8???
%CERT_ENHKEY_USAGE_PROP_ID                    = 9???
%CERT_CTL_USAGE_PROP_ID                       = %CERT_ENHKEY_USAGE_PROP_ID
%CERT_NEXT_UPDATE_LOCATION_PROP_ID            = 10???
%CERT_FRIENDLY_NAME_PROP_ID                   = 11???
%CERT_PVK_FILE_PROP_ID                        = 12???
%CERT_DESCRIPTION_PROP_ID                     = 13???
%CERT_ACCESS_STATE_PROP_ID                    = 14???
%CERT_SIGNATURE_HASH_PROP_ID                  = 15???
%CERT_SMART_CARD_DATA_PROP_ID                 = 16???
%CERT_EFS_PROP_ID                             = 17???
%CERT_FORTEZZA_DATA_PROP_ID                   = 18???
%CERT_ARCHIVED_PROP_ID                        = 19???
%CERT_KEY_IDENTIFIER_PROP_ID                  = 20???
%CERT_AUTO_ENROLL_PROP_ID                     = 21???   ' // string:Template name
%CERT_PUBKEY_ALG_PARA_PROP_ID                 = 22???
%CERT_CROSS_CERT_DIST_POINTS_PROP_ID          = 23???
%CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID      = 24???
%CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID     = 25???
%CERT_ENROLLMENT_PROP_ID                      = 26???
%CERT_DATE_STAMP_PROP_ID                      = 27???
%CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID   = 28???
%CERT_SUBJECT_NAME_MD5_HASH_PROP_ID           = 29???
%CERT_EXTENDED_ERROR_INFO_PROP_ID             = 30???

'// Note, 32 - 35 are reserved for the CERT, CRL, CTL and KeyId file element IDs.
'//       36 - 62 are reserved for future element IDs.

%CERT_RENEWAL_PROP_ID                         = 64???
%CERT_ARCHIVED_KEY_HASH_PROP_ID               = 65???
%CERT_AUTO_ENROLL_RETRY_PROP_ID               = 66???
%CERT_AIA_URL_RETRIEVED_PROP_ID               = 67???
%CERT_AUTHORITY_INFO_ACCESS_PROP_ID           = 68???
%CERT_BACKED_UP_PROP_ID                       = 69???   ' // VARIANT_BOOL+FILETIME
%CERT_OCSP_RESPONSE_PROP_ID                   = 70???
%CERT_REQUEST_ORIGINATOR_PROP_ID              = 71???
%CERT_SOURCE_LOCATION_PROP_ID                 = 72???   ' // string
%CERT_SOURCE_URL_PROP_ID                      = 73???   ' // string
%CERT_NEW_KEY_PROP_ID                         = 74???
%CERT_OCSP_CACHE_PREFIX_PROP_ID               = 75???   ' // string
%CERT_SMART_CARD_ROOT_INFO_PROP_ID            = 76???   ' // CRYPT_SMART_CARD_ROOT_INFO
%CERT_NO_AUTO_EXPIRE_CHECK_PROP_ID            = 77???
%CERT_NCRYPT_KEY_HANDLE_PROP_ID               = 78???
%CERT_HCRYPTPROV_OR_NCRYPT_KEY_HANDLE_PROP_ID = 79???

%CERT_SUBJECT_INFO_ACCESS_PROP_ID                = 80???
%CERT_CA_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID      = 81???
%CERT_CA_DISABLE_CRL_PROP_ID                     = 82???
%CERT_ROOT_PROGRAM_CERT_POLICIES_PROP_ID         = 83???
%CERT_ROOT_PROGRAM_NAME_CONSTRAINTS_PROP_ID      = 84???
%CERT_SUBJECT_OCSP_AUTHORITY_INFO_ACCESS_PROP_ID = 85???
%CERT_SUBJECT_DISABLE_CRL_PROP_ID                = 86???
%CERT_CEP_PROP_ID                                = 87???   ' // Version+PropFlags+AuthType+UrlFlags+CESAuthType+Url+Id+CESUrl+ReqId
'// 88 reserved, originally used for CERT_CEP_PROP_ID
%CERT_SIGN_HASH_CNG_ALG_PROP_ID                  = 89???
%CERT_SCARD_PIN_ID_PROP_ID                       = 90
%CERT_SCARD_PIN_INFO_PROP_ID                     = 91

%CERT_FIRST_RESERVED_PROP_ID                     = 92
%CERT_LAST_RESERVED_PROP_ID                      = &H00007FFF???
%CERT_FIRST_USER_PROP_ID                         = &H00008000???
%CERT_LAST_USER_PROP_ID                          = &H0000FFFF???

'#define IS_CERT_HASH_PROP_ID(X)     (CERT_SHA1_HASH_PROP_ID == (X) || \
'                                     CERT_MD5_HASH_PROP_ID == (X) || \
'                                     CERT_SIGNATURE_HASH_PROP_ID == (X))

MACRO IS_CERT_HASH_PROP_ID(X) = %CERT_SHA1_HASH_PROP_ID = X OR %CERT_MD5_HASH_PROP_ID = X OR %CERT_SIGNATURE_HASH_PROP_ID = X

'#define IS_PUBKEY_HASH_PROP_ID(X)     (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
'                                       CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X))

MACRO IS_PUBKEY_HASH_PROP_ID(X) = %CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID = X OR %CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID = X

'#define IS_CHAIN_HASH_PROP_ID(X)     (CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
'                                      CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID == (X) || \
'                                      CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID == (X) || \
'                                      CERT_SUBJECT_NAME_MD5_HASH_PROP_ID == (X))

MACRO IS_CHAIN_HASH_PROP_ID(X) = %CERT_ISSUER_PUBLIC_KEY_MD5_HASH_PROP_ID = X OR %CERT_SUBJECT_PUBLIC_KEY_MD5_HASH_PROP_ID = X OR %CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID = X OR %CERT_SUBJECT_NAME_MD5_HASH_PROP_ID = X


'//+-------------------------------------------------------------------------
'//  Property OIDs
'//--------------------------------------------------------------------------
'// The OID component following the prefix contains the PROP_ID (decimal)
$szOID_CERT_PROP_ID_PREFIX         = "1.3.6.1.4.1.311.10.11."

'#define _szPROP_ID(PropId)       #PropId

'// Ansi OID string from Property Id:
'#define szOID_CERT_PROP_ID(PropId) szOID_CERT_PROP_ID_PREFIX _szPROP_ID(PropId)

'// Unicode OID string from Property Id:
'#define __CRYPT32WTEXT(quote)           L##quote
'#define _CRYPT32WTEXT(quote)            __CRYPT32WTEXT(quote)
'#define wszOID_CERT_PROP_ID(PropId) \
'        _CRYPT32WTEXT(szOID_CERT_PROP_ID_PREFIX) _CRYPT32WTEXT(_szPROP_ID(PropId))

'// Use szOID_CERT_PROP_ID(CERT_KEY_IDENTIFIER_PROP_ID) instead:
$szOID_CERT_KEY_IDENTIFIER_PROP_ID = "1.3.6.1.4.1.311.10.11.20"

'// Use szOID_CERT_PROP_ID(CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID) instead:
$szOID_CERT_ISSUER_SERIAL_NUMBER_MD5_HASH_PROP_ID = "1.3.6.1.4.1.311.10.11.28"

'// Use szOID_CERT_PROP_ID(CERT_SUBJECT_NAME_MD5_HASH_PROP_ID) instead:
$szOID_CERT_SUBJECT_NAME_MD5_HASH_PROP_ID = "1.3.6.1.4.1.311.10.11.29"

'// Use szOID_CERT_PROP_ID(CERT_MD5_HASH_PROP_ID) instead:
$szOID_CERT_MD5_HASH_PROP_ID        = "1.3.6.1.4.1.311.10.11.4"

'//+-------------------------------------------------------------------------
'//  Access State flags returned by CERT_ACCESS_STATE_PROP_ID. Note,
'//  CERT_ACCESS_PROP_ID is read only.
'//--------------------------------------------------------------------------

'// Set if context property writes are persisted. For instance, not set for
'// memory store contexts. Set for registry based stores opened as read or write.
'// Not set for registry based stores opened as read only.
%CERT_ACCESS_STATE_WRITE_PERSIST_FLAG    = &H1???

'// Set if context resides in a SYSTEM or SYSTEM_REGISTRY store.
%CERT_ACCESS_STATE_SYSTEM_STORE_FLAG     = &H2???

'// Set if context resides in a LocalMachine SYSTEM or SYSTEM_REGISTRY store.
%CERT_ACCESS_STATE_LM_SYSTEM_STORE_FLAG  = &H4???

'// Set if context resides in a GroupPolicy SYSTEM or SYSTEM_REGISTRY store.
%CERT_ACCESS_STATE_GP_SYSTEM_STORE_FLAG  = &H8???

'//+-------------------------------------------------------------------------
'//  Cryptographic Key Provider Information
'//
'//  CRYPT_KEY_PROV_INFO defines the CERT_KEY_PROV_INFO_PROP_ID's pvData.
'//
'//  The CRYPT_KEY_PROV_INFO fields are passed to CryptAcquireContext
'//  to get a HCRYPTPROV handle. The optional CRYPT_KEY_PROV_PARAM fields are
'//  passed to CryptSetProvParam to further initialize the provider.
'//
'//  The dwKeySpec field identifies the private key to use from the container
'//  For example, AT_KEYEXCHANGE or AT_SIGNATURE.
'//--------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CRYPT_KEY_PROV_PARAM DWORD
   dwParam AS DWORD      ' DWORD
   pbData  AS BYTE PTR   ' BYTE*
   cbData  AS DWORD      ' DWORD
   dwFlags AS DWORD      ' DWORD
END TYPE

' // Size = 28 bytes
TYPE CRYPT_KEY_PROV_INFO DWORD
   pwszContainerName AS WSTRINGZ PTR               ' LPWSTR
   pwszProvName      AS WSTRINGZ PTR               ' LPWSTR
   dwProvType        AS DWORD                      ' DWORD
   dwFlags           AS DWORD                      ' DWORD
   cProvParam        AS DWORD                      ' DWORD
   rgProvParam       AS CRYPT_KEY_PROV_PARAM PTR   ' PCRYPT_KEY_PROV_PARAM
   dwKeySpec         AS DWORD                      ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  The following flag should be set in the above dwFlags to enable
'//  a CertSetCertificateContextProperty(CERT_KEY_CONTEXT_PROP_ID) after a
'//  CryptAcquireContext is done in the Sign or Decrypt Message functions.
'//
'//  The following define must not collide with any of the
'//  CryptAcquireContext dwFlag defines.
'//--------------------------------------------------------------------------
%CERT_SET_KEY_PROV_HANDLE_PROP_ID    = &H00000001???
%CERT_SET_KEY_CONTEXT_PROP_ID        = &H00000001???

'//+-------------------------------------------------------------------------
'//  Certificate Key Context
'//
'//  CERT_KEY_CONTEXT defines the CERT_KEY_CONTEXT_PROP_ID's pvData.
'//--------------------------------------------------------------------------

' // Size = 4 bytes
UNION CERT_KEY_CONTEXT_UNION DWORD
   hCryptProv AS DWORD   ' HCRYPTPROV
   ' // dwKeySpec == CERT_NCRYPT_KEY_SPEC
   hNCryptKey AS DWORD   ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 12 bytes
TYPE CERT_KEY_CONTEXT DWORD
   cbSize     AS DWORD   ' DWORD
   CERT_KEY_CONTEXT_UNION
   dwKeySpec  AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Cryptographic Smart Card Root Information
'//
'//  CRYPT_SMART_CARD_ROOT_INFO defines the
'//  CERT_SMART_CARD_ROOT_INFO_PROP_ID's pvData.
'//--------------------------------------------------------------------------

TYPE ROOT_INFO_LUID_STRUCT DWORD
  LowPart  AS DWORD
  HighPart AS LONG
END TYPE

UNION ROOT_INFO_LUID_UNION DWORD
   ROOT_INFO_LUID_STRUCT
   QuadPart AS QUAD
END UNION

' // Size = 8 bytes
TYPE ROOT_INFO_LUID DWORD
   ROOT_INFO_LUID_UNION
END TYPE

' // Size = 24 bytes
TYPE CRYPT_SMART_CARD_ROOT_INFO
   rgbCardID(15) AS BYTE
   luid          AS ROOT_INFO_LUID
END TYPE

'//+-------------------------------------------------------------------------
'//  Certificate Store Provider Types
'//--------------------------------------------------------------------------
%CERT_STORE_PROV_MSG                 = 1    ' ((LPCSTR) 1)
%CERT_STORE_PROV_MEMORY              = 2    ' ((LPCSTR) 2)
%CERT_STORE_PROV_FILE                = 3    ' ((LPCSTR) 3)
%CERT_STORE_PROV_REG                 = 4    ' ((LPCSTR) 4)

%CERT_STORE_PROV_PKCS7               = 5    ' ((LPCSTR) 5)
%CERT_STORE_PROV_SERIALIZED          = 6    ' ((LPCSTR) 6)
%CERT_STORE_PROV_FILENAME_A          = 7    ' ((LPCSTR) 7)
%CERT_STORE_PROV_FILENAME_W          = 8    ' ((LPCSTR) 8)
%CERT_STORE_PROV_FILENAME            = %CERT_STORE_PROV_FILENAME_W
%CERT_STORE_PROV_SYSTEM_A            = 9    ' ((LPCSTR) 9)
%CERT_STORE_PROV_SYSTEM_W            = 10   ' ((LPCSTR) 10)
%CERT_STORE_PROV_SYSTEM              = %CERT_STORE_PROV_SYSTEM_W

%CERT_STORE_PROV_COLLECTION          = 11   ' ((LPCSTR) 11)
%CERT_STORE_PROV_SYSTEM_REGISTRY_A   = 12   ' ((LPCSTR) 12)
%CERT_STORE_PROV_SYSTEM_REGISTRY_W   = 13   ' ((LPCSTR) 13)
%CERT_STORE_PROV_SYSTEM_REGISTRY     = %CERT_STORE_PROV_SYSTEM_REGISTRY_W
%CERT_STORE_PROV_PHYSICAL_W          = 14   ' ((LPCSTR) 14)
%CERT_STORE_PROV_PHYSICAL            = %CERT_STORE_PROV_PHYSICAL_W
%CERT_STORE_PROV_SMART_CARD_W        = 15   ' ((LPCSTR) 15)
%CERT_STORE_PROV_SMART_CARD          = %CERT_STORE_PROV_SMART_CARD_W
%CERT_STORE_PROV_LDAP_W              = 16   ' ((LPCSTR) 16)
%CERT_STORE_PROV_LDAP                = %CERT_STORE_PROV_LDAP_W

$sz_CERT_STORE_PROV_MEMORY           = "Memory"
$sz_CERT_STORE_PROV_FILENAME_W       = "File"
$sz_CERT_STORE_PROV_FILENAME         = $sz_CERT_STORE_PROV_FILENAME_W
$sz_CERT_STORE_PROV_SYSTEM_W         = "System"
$sz_CERT_STORE_PROV_SYSTEM           = $sz_CERT_STORE_PROV_SYSTEM_W
$sz_CERT_STORE_PROV_PKCS7            = "PKCS7"
$sz_CERT_STORE_PROV_SERIALIZED       = "Serialized"

$sz_CERT_STORE_PROV_COLLECTION        = "Collection"
$sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W = "SystemRegistry"
$sz_CERT_STORE_PROV_SYSTEM_REGISTRY   = $sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
$sz_CERT_STORE_PROV_PHYSICAL_W        = "Physical"
$sz_CERT_STORE_PROV_PHYSICAL          = $sz_CERT_STORE_PROV_PHYSICAL_W

'// SmartCard Store Provider isn't supported
$sz_CERT_STORE_PROV_SMART_CARD_W      = "SmartCard"
$sz_CERT_STORE_PROV_SMART_CARD        = $sz_CERT_STORE_PROV_SMART_CARD_W

$sz_CERT_STORE_PROV_LDAP_W            = "Ldap"
$sz_CERT_STORE_PROV_LDAP              = $sz_CERT_STORE_PROV_LDAP_W

'//+-------------------------------------------------------------------------
'//  Certificate Store verify/results flags
'//--------------------------------------------------------------------------
%CERT_STORE_SIGNATURE_FLAG           = &H00000001???
%CERT_STORE_TIME_VALIDITY_FLAG       = &H00000002???
%CERT_STORE_REVOCATION_FLAG          = &H00000004???
%CERT_STORE_NO_CRL_FLAG              = &H00010000???
%CERT_STORE_NO_ISSUER_FLAG           = &H00020000???

%CERT_STORE_BASE_CRL_FLAG            = &H00000100???
%CERT_STORE_DELTA_CRL_FLAG           = &H00000200???


'//+-------------------------------------------------------------------------
'//  Certificate Store open/property flags
'//--------------------------------------------------------------------------
%CERT_STORE_NO_CRYPT_RELEASE_FLAG                = &H00000001???
%CERT_STORE_SET_LOCALIZED_NAME_FLAG              = &H00000002???
%CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG     = &H00000004???
%CERT_STORE_DELETE_FLAG                          = &H00000010???
%CERT_STORE_UNSAFE_PHYSICAL_FLAG                 = &H00000020???
%CERT_STORE_SHARE_STORE_FLAG                     = &H00000040???
%CERT_STORE_SHARE_CONTEXT_FLAG                   = &H00000080???
%CERT_STORE_MANIFOLD_FLAG                        = &H00000100???
%CERT_STORE_ENUM_ARCHIVED_FLAG                   = &H00000200???
%CERT_STORE_UPDATE_KEYID_FLAG                    = &H00000400???
%CERT_STORE_BACKUP_RESTORE_FLAG                  = &H00000800???
%CERT_STORE_READONLY_FLAG                        = &H00008000???
%CERT_STORE_OPEN_EXISTING_FLAG                   = &H00004000???
%CERT_STORE_CREATE_NEW_FLAG                      = &H00002000???
%CERT_STORE_MAXIMUM_ALLOWED_FLAG                 = &H00001000???

'//+-------------------------------------------------------------------------
'//  Certificate Store Provider flags are in the HiWord (0xFFFF0000)
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Certificate System Store Flag Values
'//--------------------------------------------------------------------------
'// Includes flags and location
%CERT_SYSTEM_STORE_MASK                  = &HFFFF0000???

'// Set if pvPara points to a CERT_SYSTEM_STORE_RELOCATE_PARA structure
%CERT_SYSTEM_STORE_RELOCATE_FLAG         = &H80000000???

'typedef struct _CERT_SYSTEM_STORE_RELOCATE_PARA {
'    union {
'        HKEY                hKeyBase;
'        void                *pvBase;
'    };
'    union {
'        void                *pvSystemStore;
'        LPCSTR              pszSystemStore;
'        LPCWSTR             pwszSystemStore;
'    };
'} CERT_SYSTEM_STORE_RELOCATE_PARA, *PCERT_SYSTEM_STORE_RELOCATE_PARA;

' // Size = 4 bytes
UNION CERT_SYSTEM_STORE_RELOCATE_PARA_UNION1 DWORD
   hKeyBase AS DWORD
   pvBase   AS DWORD
END UNION

' // Size = 4 bytes
UNION CERT_SYSTEM_STORE_RELOCATE_PARA_UNION2 DWORD
   pvSystemStore   AS DWORD
   pszSystemStore  AS ASCIIZ PTR
   pwszSystemStore AS WSTRINGZ PTR
END UNION

' // Size = 8 bytes
TYPE CERT_SYSTEM_STORE_RELOCATE_PARA DWORD
   CERT_SYSTEM_STORE_RELOCATE_PARA_UNION1
   CERT_SYSTEM_STORE_RELOCATE_PARA_UNION2
END TYPE

'// By default, when the CurrentUser "Root" store is opened, any SystemRegistry
'// roots not also on the protected root list are deleted from the cache before
'// CertOpenStore() returns. Set the following flag to return all the roots
'// in the SystemRegistry without checking the protected root list.
%CERT_SYSTEM_STORE_UNPROTECTED_FLAG      = &H40000000???

'// Location of the system store:
%CERT_SYSTEM_STORE_LOCATION_MASK         = &H00FF0000???
%CERT_SYSTEM_STORE_LOCATION_SHIFT        = 16???


'//  Registry: HKEY_CURRENT_USER or HKEY_LOCAL_MACHINE
%CERT_SYSTEM_STORE_CURRENT_USER_ID       = 1???
%CERT_SYSTEM_STORE_LOCAL_MACHINE_ID      = 2???
'//  Registry: HKEY_LOCAL_MACHINE\Software\Microsoft\Cryptography\Services
%CERT_SYSTEM_STORE_CURRENT_SERVICE_ID    = 4???
%CERT_SYSTEM_STORE_SERVICES_ID           = 5???
'//  Registry: HKEY_USERS
%CERT_SYSTEM_STORE_USERS_ID              = 6???

'//  Registry: HKEY_CURRENT_USER\Software\Policies\Microsoft\SystemCertificates
%CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID    = 7???
'//  Registry: HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\SystemCertificates
%CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID   = 8???

'//  Registry: HKEY_LOCAL_MACHINE\Software\Microsoft\EnterpriseCertificates
%CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID     = 9???

'#define CERT_SYSTEM_STORE_CURRENT_USER          \
'    (CERT_SYSTEM_STORE_CURRENT_USER_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_CURRENT_USER = &H10000???

'#define CERT_SYSTEM_STORE_LOCAL_MACHINE         \
'    (CERT_SYSTEM_STORE_LOCAL_MACHINE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_LOCAL_MACHINE = &H20000???

'#define CERT_SYSTEM_STORE_CURRENT_SERVICE       \
'    (CERT_SYSTEM_STORE_CURRENT_SERVICE_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_CURRENT_SERVICE = &H40000???

'#define CERT_SYSTEM_STORE_SERVICES              \
'    (CERT_SYSTEM_STORE_SERVICES_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_SERVICES = &H50000???

'#define CERT_SYSTEM_STORE_USERS                 \
'    (CERT_SYSTEM_STORE_USERS_ID << CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_USERS = &H60000???

'#define CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY   \
'    (CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY_ID << \
'        CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY = &H70000???

'#define CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY  \
'    (CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY_ID << \
'        CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY = &H80000???

'#define CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE  \
'    (CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE_ID << \
'        CERT_SYSTEM_STORE_LOCATION_SHIFT)
%CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE = &H90000???

'//+-------------------------------------------------------------------------
'//  Group Policy Store Defines
'//--------------------------------------------------------------------------
'// Registry path to the Group Policy system stores
'#define CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH \
'    L"Software\\Policies\\Microsoft\\SystemCertificates"

$CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH = "Software\Policies\Microsoft\SystemCertificates"

'//+-------------------------------------------------------------------------
'//  EFS Defines
'//--------------------------------------------------------------------------
'// Registry path to the EFS EFSBlob SubKey - Value type is REG_BINARY
'#define CERT_EFSBLOB_REGPATH    \
'    CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\EFS"
$CERT_EFSBLOB_REGPATH = "Software\Policies\Microsoft\SystemCertificates\EFS"

'#define CERT_EFSBLOB_VALUE_NAME L"EFSBlob"
$CERT_EFSBLOB_VALUE_NAME = "EFSBlob"

'//+-------------------------------------------------------------------------
'//  Protected Root Defines
'//--------------------------------------------------------------------------
'// Registry path to the Protected Roots Flags SubKey
'#define CERT_PROT_ROOT_FLAGS_REGPATH    \
'    CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\Root\\ProtectedRoots"
$CERT_PROT_ROOT_FLAGS_REGPATH = "Software\Policies\Microsoft\SystemCertificates\Root\ProtectedRoots"

'#define CERT_PROT_ROOT_FLAGS_VALUE_NAME L"Flags"
$CERT_PROT_ROOT_FLAGS_VALUE_NAME = "Flags"

'// Set the following flag to inhibit the opening of the CurrentUser's
'// .Default physical store when opening the CurrentUser's "Root" system store.
'// The .Default physical store open's the CurrentUser SystemRegistry "Root"
'// store.
%CERT_PROT_ROOT_DISABLE_CURRENT_USER_FLAG    = &H1???

'// Set the following flag to inhibit the adding of roots from the
'// CurrentUser SystemRegistry "Root" store to the protected root list
'// when the "Root" store is initially protected.
%CERT_PROT_ROOT_INHIBIT_ADD_AT_INIT_FLAG     = &H2???

'// Set the following flag to inhibit the purging of protected roots from the
'// CurrentUser SystemRegistry "Root" store that are
'// also in the LocalMachine SystemRegistry "Root" store. Note, when not
'// disabled, the purging is done silently without UI.
%CERT_PROT_ROOT_INHIBIT_PURGE_LM_FLAG        = &H4???

'// Set the following flag to inhibit the opening of the LocalMachine's
'// .AuthRoot physical store when opening the LocalMachine's "Root" system store.
'// The .AuthRoot physical store open's the LocalMachine SystemRegistry
'// "AuthRoot" store. The "AuthRoot" store contains the pre-installed
'// SSL ServerAuth and the ActiveX Authenticode "root" certificates.
%CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG         = &H8???

'// The semantics for the following legacy definition has been changed to be
'// the same as for the CERT_PROT_ROOT_DISABLE_LM_AUTH_FLAG.
%CERT_PROT_ROOT_ONLY_LM_GPT_FLAG             = &H8???

'// Set the following flag to disable the requiring of the issuing CA
'// certificate being in the "NTAuth" system registry store found in the
'// CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE store location.
'//
'// When set, CertVerifyCertificateChainPolicy(CERT_CHAIN_POLICY_NT_AUTH)
'// will check that the chain has a valid name constraint for all name
'// spaces, including UPN if the issuing CA isn't in the "NTAuth" store.
%CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG = &H10???

'// Set the following flag to disable checking for not defined name
'// constraints.
'//
'// When set, CertGetCertificateChain won't check for or set the following
'// dwErrorStatus: CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT.
%CERT_PROT_ROOT_DISABLE_NOT_DEFINED_NAME_CONSTRAINT_FLAG = &H20???

'// Set the following flag to disallow the users to trust peer-trust
%CERT_PROT_ROOT_DISABLE_PEER_TRUST                       = &H10000???

'// The following is a REG_MULTI_SZ containing the list of user allowed
'// Enhanced Key Usages for peer trust.
'#define CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME     L"PeerUsages"
'#define CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME_A   "PeerUsages"
$CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME   = "PeerUsages"
$CERT_PROT_ROOT_PEER_USAGES_VALUE_NAME_A = "PeerUsages"

'// If the above REG_MULTI_SZ isn't defined or is empty, defaults to
'// the following multi-string value
'#define CERT_PROT_ROOT_PEER_USAGES_DEFAULT_A      \
'    szOID_PKIX_KP_CLIENT_AUTH "\0"                  \
'    szOID_PKIX_KP_EMAIL_PROTECTION "\0"             \
'    szOID_KP_EFS "\0"

$CERT_PROT_ROOT_PEER_USAGES_DEFAULT_A = _
   $szOID_PKIX_KP_CLIENT_AUTH & CHR$(0) & _
   $szOID_PKIX_KP_EMAIL_PROTECTION & CHR$(0) & _
   $szOID_KP_EFS & CHR$(0)

'//+-------------------------------------------------------------------------
'//  Trusted Publisher Definitions
'//--------------------------------------------------------------------------
'// Registry path to the trusted publisher "Safer" group policy subkey
'#define CERT_TRUST_PUB_SAFER_GROUP_POLICY_REGPATH    \
'    CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\TrustedPublisher\\Safer"
$CERT_TRUST_PUB_SAFER_GROUP_POLICY_REGPATH = "Software\Policies\Microsoft\SystemCertificates\TrustedPublisher\Safer"

'// Registry path to the Local Machine system stores
'#define CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH \
'    L"Software\\Microsoft\\SystemCertificates"
$CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH = "Software\Microsoft\SystemCertificates"

'// Registry path to the trusted publisher "Safer" local machine subkey
'#define CERT_TRUST_PUB_SAFER_LOCAL_MACHINE_REGPATH    \
'    CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L"\\TrustedPublisher\\Safer"
$CERT_TRUST_PUB_SAFER_LOCAL_MACHINE_REGPATH = "Software\Microsoft\SystemCertificates\TrustedPublisher\Safer"

'// "Safer" subkey value names. All values are DWORDs.
'#define CERT_TRUST_PUB_AUTHENTICODE_FLAGS_VALUE_NAME    L"AuthenticodeFlags"
$CERT_TRUST_PUB_AUTHENTICODE_FLAGS_VALUE_NAME = "AuthenticodeFlags"


'// AuthenticodeFlags definitions

'// Definition of who is allowed to trust publishers
'//
'// Setting allowed trust to MACHINE_ADMIN or ENTERPRISE_ADMIN disables UI,
'// only trusts publishers in the "TrustedPublisher" system store and
'// inhibits the opening of the CurrentUser's .Default physical store when
'// opening the CurrentUsers's "TrustedPublisher" system store.
'//
'// The .Default physical store open's the CurrentUser SystemRegistry
'// "TrustedPublisher" store.
'//
'// Setting allowed trust to ENTERPRISE_ADMIN only opens the
'// LocalMachine's .GroupPolicy and .Enterprise physical stores when opening
'// the CurrentUser's "TrustedPublisher" system store or when opening the
'// LocalMachine's "TrustedPublisher" system store.

%CERT_TRUST_PUB_ALLOW_TRUST_MASK                 = &H00000003???
%CERT_TRUST_PUB_ALLOW_END_USER_TRUST             = &H00000000???
%CERT_TRUST_PUB_ALLOW_MACHINE_ADMIN_TRUST        = &H00000001???
%CERT_TRUST_PUB_ALLOW_ENTERPRISE_ADMIN_TRUST     = &H00000002???

'// Set the following flag to enable revocation checking of the publisher
'// chain.
%CERT_TRUST_PUB_CHECK_PUBLISHER_REV_FLAG         = &H00000100???

'// Set the following flag to enable revocation checking of the time stamp
'// chain.
%CERT_TRUST_PUB_CHECK_TIMESTAMP_REV_FLAG         = &H00000200???


'//+-------------------------------------------------------------------------
'//  OCM Subcomponents Definitions
'//
'//  Reading of the following registry key has been deprecated on Vista.
'//--------------------------------------------------------------------------

'// Registry path to the OCM Subcomponents local machine subkey
'#define CERT_OCM_SUBCOMPONENTS_LOCAL_MACHINE_REGPATH        \
'    L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Setup\\OC Manager\\Subcomponents"
$CERT_OCM_SUBCOMPONENTS_LOCAL_MACHINE_REGPATH = "SOFTWARE\Microsoft\Windows\CurrentVersion\Setup\OC Manager\Subcomponents"

'// REG_DWORD, 1 is installed, 0 is NOT installed
'#define CERT_OCM_SUBCOMPONENTS_ROOT_AUTO_UPDATE_VALUE_NAME  L"RootAutoUpdate"
$CERT_OCM_SUBCOMPONENTS_ROOT_AUTO_UPDATE_VALUE_NAME = "RootAutoUpdate"

'//+-------------------------------------------------------------------------
'//  DisableRootAutoUpdate Defines
'//--------------------------------------------------------------------------
'// Registry path to the DisableRootAutoUpdate SubKey
'#define CERT_DISABLE_ROOT_AUTO_UPDATE_REGPATH    \
'    CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\AuthRoot"

$CERT_DISABLE_ROOT_AUTO_UPDATE_REGPATH = $CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH & "\AuthRoot"

'// REG_DWORD Value Name, 1 - disables, 0 - enables
'#define CERT_DISABLE_ROOT_AUTO_UPDATE_VALUE_NAME L"DisableRootAutoUpdate"
$CERT_DISABLE_ROOT_AUTO_UPDATE_VALUE_NAME = "DisableRootAutoUpdate"

'//+-------------------------------------------------------------------------
'//  AuthRoot Auto Update Definitions
'//--------------------------------------------------------------------------

'// Registry path to the AuthRoot "Auto Update" local machine subkey
'#define CERT_AUTH_ROOT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH    \
'    CERT_LOCAL_MACHINE_SYSTEM_STORE_REGPATH L"\\AuthRoot\\AutoUpdate"
$CERT_AUTH_ROOT_AUTO_UPDATE_LOCAL_MACHINE_REGPATH = "Software\Microsoft\SystemCertificates\AuthRoot\AutoUpdate"

'// AuthRoot Auto Update subkey value names.

'// REG_SZ, URL to the directory containing the AuthRoots, CTL and Seq files
'#define CERT_AUTH_ROOT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME      L"RootDirUrl"
$CERT_AUTH_ROOT_AUTO_UPDATE_ROOT_DIR_URL_VALUE_NAME = "RootDirUrl"

'// REG_DWORD, seconds between syncs. 0 implies use default.
'#define CERT_AUTH_ROOT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME   L"SyncDeltaTime"
$CERT_AUTH_ROOT_AUTO_UPDATE_SYNC_DELTA_TIME_VALUE_NAME = "SyncDeltaTime"

'// REG_DWORD, misc flags
'#define CERT_AUTH_ROOT_AUTO_UPDATE_FLAGS_VALUE_NAME             L"Flags"
$CERT_AUTH_ROOT_AUTO_UPDATE_FLAGS_VALUE_NAME = "Flags"

%CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_UNTRUSTED_ROOT_LOGGING_FLAG  = &H1???
%CERT_AUTH_ROOT_AUTO_UPDATE_DISABLE_PARTIAL_CHAIN_LOGGING_FLAG   = &H2???


'// AuthRoot Auto Update filenames

'// CTL containing the list of certs in the AuthRoot store
'#define CERT_AUTH_ROOT_CTL_FILENAME                             L"authroot.stl"
'#define CERT_AUTH_ROOT_CTL_FILENAME_A                           "authroot.stl"

$CERT_AUTH_ROOT_CTL_FILENAME = "authroot.stl"
$CERT_AUTH_ROOT_CTL_FILENAME_A = "authroot.stl"

'// Cab containing the above CTL
'#define CERT_AUTH_ROOT_CAB_FILENAME                             L"authrootstl.cab"
$CERT_AUTH_ROOT_CAB_FILENAME = "authrootstl.cab"

'// SequenceNumber (Formatted as big endian ascii hex)
'#define CERT_AUTH_ROOT_SEQ_FILENAME                             L"authrootseq.txt"
$CERT_AUTH_ROOT_SEQ_FILENAME = "authrootseq.txt"

'// Root certs extension
'#define CERT_AUTH_ROOT_CERT_EXT                                 L".crt"
$CERT_AUTH_ROOT_CERT_EXT = ".crt"


'//+-------------------------------------------------------------------------
'//  Certificate Registry Store Flag Values (CERT_STORE_REG)
'//--------------------------------------------------------------------------

'// Set this flag if the HKEY passed in pvPara points to a remote computer
'// registry key.
%CERT_REGISTRY_STORE_REMOTE_FLAG         = &H10000???

'// Set this flag if the contexts are to be persisted as a single serialized
'// store in the registry. Mainly used for stores downloaded from the GPT.
'// Such as the CurrentUserGroupPolicy or LocalMachineGroupPolicy stores.
%CERT_REGISTRY_STORE_SERIALIZED_FLAG     = &H20000???

'// The following flags are for internal use. When set, the
'// pvPara parameter passed to CertOpenStore is a pointer to the following
'// data structure and not the HKEY. The above CERT_REGISTRY_STORE_REMOTE_FLAG
'// is also set if hKeyBase was obtained via RegConnectRegistry().
%CERT_REGISTRY_STORE_CLIENT_GPT_FLAG     = &H80000000???
%CERT_REGISTRY_STORE_LM_GPT_FLAG         = &H01000000???

' // Size = 8 bytes
TYPE CERT_REGISTRY_STORE_CLIENT_GPT_PARA DWORD
   hKeyBase    AS DWORD          ' HKEY
   pwszRegPath AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'// The following flag is for internal use. When set, the contexts are
'// persisted into roaming files instead of the registry. Such as, the
'// CurrentUser "My" store. When this flag is set, the following data structure
'// is passed to CertOpenStore instead of HKEY.
%CERT_REGISTRY_STORE_ROAMING_FLAG        = &H40000???

'// hKey may be NULL or non-NULL. When non-NULL, existing contexts are
'// moved from the registry to roaming files.

' // Size = 8 bytes
TYPE CERT_REGISTRY_STORE_ROAMING_PARA DWORD
   hKey               AS DWORD          ' HKEY
   pwszStoreDirectory AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'// The following flag is for internal use. When set, the "My" DWORD value
'// at HKLM\Software\Microsoft\Cryptography\IEDirtyFlags is set to 0x1
'// whenever a certificate is added to the registry store.
'//
'// Legacy definition, no longer supported after 01-May-02 (Server 2003)
%CERT_REGISTRY_STORE_MY_IE_DIRTY_FLAG    = &H80000???

'// Registry path to the subkey containing the "My" DWORD value to be set
'//
'// Legacy definition, no longer supported after 01-May-02 (Server 2003)
'#define CERT_IE_DIRTY_FLAGS_REGPATH \
'    L"Software\\Microsoft\\Cryptography\\IEDirtyFlags"
$CERT_IE_DIRTY_FLAGS_REGPATH = "Software\Microsoft\Cryptography\IEDirtyFlags"

'//+-------------------------------------------------------------------------
'//  Certificate File Store Flag Values for the providers:
'//      CERT_STORE_PROV_FILE
'//      CERT_STORE_PROV_FILENAME
'//      CERT_STORE_PROV_FILENAME_A
'//      CERT_STORE_PROV_FILENAME_W
'//      sz_CERT_STORE_PROV_FILENAME_W
'//--------------------------------------------------------------------------

'// Set this flag if any store changes are to be committed to the file.
'// The changes are committed at CertCloseStore or by calling
'// CertControlStore(CERT_STORE_CTRL_COMMIT).
'//
'// The open fails with E_INVALIDARG if both CERT_FILE_STORE_COMMIT_ENABLE_FLAG
'// and CERT_STORE_READONLY_FLAG are set in dwFlags.
'//
'// For the FILENAME providers:  if the file contains an X509 encoded
'// certificate, the open fails with ERROR_ACCESS_DENIED.
'//
'// For the FILENAME providers: if CERT_STORE_CREATE_NEW_FLAG is set, the
'// CreateFile uses CREATE_NEW. If CERT_STORE_OPEN_EXISTING is set, uses
'// OPEN_EXISTING. Otherwise, defaults to OPEN_ALWAYS.
'//
'// For the FILENAME providers:  the file is committed as either a PKCS7 or
'// serialized store depending on the type read at open. However, if the
'// file is empty then, if the filename has either a ".p7c" or ".spc"
'// extension its committed as a PKCS7. Otherwise, its committed as a
'// serialized store.
'//
'// For CERT_STORE_PROV_FILE, the file handle is duplicated. Its always
'// committed as a serialized store.
'//
%CERT_FILE_STORE_COMMIT_ENABLE_FLAG      = &H10000???


'//+-------------------------------------------------------------------------
'//  Certificate LDAP Store Flag Values for the providers:
'//      CERT_STORE_PROV_LDAP
'//      CERT_STORE_PROV_LDAP_W
'//      sz_CERT_STORE_PROV_LDAP_W
'//      sz_CERT_STORE_PROV_LDAP
'//--------------------------------------------------------------------------

'// Set this flag to digitally sign all of the ldap traffic to and from a
'// Windows 2000 LDAP server using the Kerberos authentication protocol.
'// This feature provides integrity required by some applications.
'//
%CERT_LDAP_STORE_SIGN_FLAG               = &H10000???

'// Performs an A-Record only DNS lookup on the supplied host string.
'// This prevents bogus DNS queries from being generated when resolving host
'// names. Use this flag whenever passing a hostname as opposed to a
'// domain name for the hostname parameter.
'//
'// See LDAP_OPT_AREC_EXCLUSIVE defined in winldap.h for more details.
%CERT_LDAP_STORE_AREC_EXCLUSIVE_FLAG     = &H20000???

'// Set this flag if the LDAP session handle has already been opened. When
'// set, pvPara points to the following CERT_LDAP_STORE_OPENED_PARA structure.
%CERT_LDAP_STORE_OPENED_FLAG             = &H40000???

' // Size = 8 bytes
TYPE CERT_LDAP_STORE_OPENED_PARA DWORD
   pvLdapSessionHandle AS DWORD          ' void*
   pwszLdapUrl         AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'// Set this flag if the above CERT_LDAP_STORE_OPENED_FLAG is set and
'// you want an ldap_unbind() of the above pvLdapSessionHandle when the
'// store is closed. Note, if CertOpenStore() fails, then, ldap_unbind()
'// isn't called.
%CERT_LDAP_STORE_UNBIND_FLAG             = &H80000???

'//+-------------------------------------------------------------------------
'//  Open the cert store using the specified store provider.
'//
'//  If CERT_STORE_DELETE_FLAG is set, then, the store is deleted. NULL is
'//  returned for both success and failure. However, GetLastError() returns 0
'//  for success and nonzero for failure.
'//
'//  If CERT_STORE_SET_LOCALIZED_NAME_FLAG is set, then, if supported, the
'//  provider sets the store's CERT_STORE_LOCALIZED_NAME_PROP_ID property.
'//  The store's localized name can be retrieved by calling
'//  CertSetStoreProperty(dwPropID = CERT_STORE_LOCALIZED_NAME_PROP_ID).
'//  This flag is supported by the following providers (and their sz_
'//  equivalent):
'//      CERT_STORE_PROV_FILENAME_A
'//      CERT_STORE_PROV_FILENAME_W
'//      CERT_STORE_PROV_SYSTEM_A
'//      CERT_STORE_PROV_SYSTEM_W
'//      CERT_STORE_PROV_SYSTEM_REGISTRY_A
'//      CERT_STORE_PROV_SYSTEM_REGISTRY_W
'//      CERT_STORE_PROV_PHYSICAL_W
'//
'//  If CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG is set, then, the
'//  closing of the store's provider is deferred until all certificate,
'//  CRL and CTL contexts obtained from the store are freed. Also,
'//  if a non NULL HCRYPTPROV was passed, then, it will continue to be used.
'//  By default, the store's provider is closed on the final CertCloseStore.
'//  If this flag isn't set, then, any property changes made to previously
'//  duplicated contexts after the final CertCloseStore will not be persisted.
'//  By setting this flag, property changes made
'//  after the CertCloseStore will be persisted. Note, setting this flag
'//  causes extra overhead in doing context duplicates and frees.
'//  If CertCloseStore is called with CERT_CLOSE_STORE_FORCE_FLAG, then,
'//  the CERT_STORE_DEFER_CLOSE_UNTIL_LAST_FREE_FLAG flag is ignored.
'//
'//  CERT_STORE_MANIFOLD_FLAG can be set to check for certificates having the
'//  manifold extension and archive the "older" certificates with the same
'//  manifold extension value. A certificate is archived by setting the
'//  CERT_ARCHIVED_PROP_ID.
'//
'//  By default, contexts having the CERT_ARCHIVED_PROP_ID, are skipped
'//  during enumeration. CERT_STORE_ENUM_ARCHIVED_FLAG can be set to include
'//  archived contexts when enumerating. Note, contexts having the
'//  CERT_ARCHIVED_PROP_ID are still found for explicit finds, such as,
'//  finding a context with a specific hash or finding a certificate having
'//  a specific issuer and serial number.
'//
'//  CERT_STORE_UPDATE_KEYID_FLAG can be set to also update the Key Identifier's
'//  CERT_KEY_PROV_INFO_PROP_ID property whenever a certificate's
'//  CERT_KEY_IDENTIFIER_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID property is set
'//  and the other property already exists. If the Key Identifier's
'//  CERT_KEY_PROV_INFO_PROP_ID already exists, it isn't updated. Any
'//  errors encountered are silently ignored.
'//
'//  By default, this flag is implicitly set for the "My\.Default" CurrentUser
'//  and LocalMachine physical stores.
'//
'//  CERT_STORE_READONLY_FLAG can be set to open the store as read only.
'//  Otherwise, the store is opened as read/write.
'//
'//  CERT_STORE_OPEN_EXISTING_FLAG can be set to only open an existing
'//  store. CERT_STORE_CREATE_NEW_FLAG can be set to create a new store and
'//  fail if the store already exists. Otherwise, the default is to open
'//  an existing store or create a new store if it doesn't already exist.
'//
'//  hCryptProv specifies the crypto provider to use to create the hash
'//  properties or verify the signature of a subject certificate or CRL.
'//  The store doesn't need to use a private
'//  key. If the CERT_STORE_NO_CRYPT_RELEASE_FLAG isn't set, hCryptProv is
'//  CryptReleaseContext'ed on the final CertCloseStore.
'//
'//  Note, if the open fails, hCryptProv is released if it would have been
'//  released when the store was closed.
'//
'//  If hCryptProv is zero, then, the default provider and container for the
'//  PROV_RSA_FULL provider type is CryptAcquireContext'ed with
'//  CRYPT_VERIFYCONTEXT access. The CryptAcquireContext is deferred until
'//  the first create hash or verify signature. In addition, once acquired,
'//  the default provider isn't released until process exit when crypt32.dll
'//  is unloaded. The acquired default provider is shared across all stores
'//  and threads.
'//
'//  After initializing the store's data structures and optionally acquiring a
'//  default crypt provider, CertOpenStore calls CryptGetOIDFunctionAddress to
'//  get the address of the CRYPT_OID_OPEN_STORE_PROV_FUNC specified by
'//  lpszStoreProvider. Since a store can contain certificates with different
'//  encoding types, CryptGetOIDFunctionAddress is called with dwEncodingType
'//  set to 0 and not the dwEncodingType passed to CertOpenStore.
'//  PFN_CERT_DLL_OPEN_STORE_FUNC specifies the signature of the provider's
'//  open function. This provider open function is called to load the
'//  store's certificates and CRLs. Optionally, the provider may return an
'//  array of functions called before a certificate or CRL is added or deleted
'//  or has a property that is set.
'//
'//  Use of the dwEncodingType parameter is provider dependent. The type
'//  definition for pvPara also depends on the provider.
'//
'//  Store providers are installed or registered via
'//  CryptInstallOIDFunctionAddress or CryptRegisterOIDFunction, where,
'//  dwEncodingType is 0 and pszFuncName is CRYPT_OID_OPEN_STORE_PROV_FUNC.
'//
'//  Here's a list of the predefined provider types (implemented in crypt32.dll):
'//
'//  CERT_STORE_PROV_MSG:
'//      Gets the certificates and CRLs from the specified cryptographic message.
'//      dwEncodingType contains the message and certificate encoding types.
'//      The message's handle is passed in pvPara. Given,
'//          HCRYPTMSG hCryptMsg; pvPara = (const void *) hCryptMsg;
'//
'//  CERT_STORE_PROV_MEMORY
'//  sz_CERT_STORE_PROV_MEMORY:
'//      Opens a store without any initial certificates or CRLs. pvPara
'//      isn't used.
'//
'//  CERT_STORE_PROV_FILE:
'//      Reads the certificates and CRLs from the specified file. The file's
'//      handle is passed in pvPara. Given,
'//          HANDLE hFile; pvPara = (const void *) hFile;
'//
'//      For a successful open, the file pointer is advanced past
'//      the certificates and CRLs and their properties read from the file.
'//      Note, only expects a serialized store and not a file containing
'//      either a PKCS #7 signed message or a single encoded certificate.
'//
'//      The hFile isn't closed.
'//
'//  CERT_STORE_PROV_REG:
'//      Reads the certificates and CRLs from the registry. The registry's
'//      key handle is passed in pvPara. Given,
'//          HKEY hKey; pvPara = (const void *) hKey;
'//
'//      The input hKey isn't closed by the provider. Before returning, the
'//      provider opens it own copy of the hKey.
'//
'//      If CERT_STORE_READONLY_FLAG is set, then, the registry subkeys are
'//      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry subkeys
'//      are RegCreateKey'ed with KEY_ALL_ACCESS.
'//
'//      This provider returns the array of functions for reading, writing,
'//      deleting and property setting certificates and CRLs.
'//      Any changes to the opened store are immediately pushed through to
'//      the registry. However, if CERT_STORE_READONLY_FLAG is set, then,
'//      writing, deleting or property setting results in a
'//      SetLastError(E_ACCESSDENIED).
'//
'//      Note, all the certificates and CRLs are read from the registry
'//      when the store is opened. The opened store serves as a write through
'//      cache.
'//
'//      If CERT_REGISTRY_STORE_SERIALIZED_FLAG is set, then, the
'//      contexts are persisted as a single serialized store subkey in the
'//      registry.
'//
'//  CERT_STORE_PROV_PKCS7:
'//  sz_CERT_STORE_PROV_PKCS7:
'//      Gets the certificates and CRLs from the encoded PKCS #7 signed message.
'//      dwEncodingType specifies the message and certificate encoding types.
'//      The pointer to the encoded message's blob is passed in pvPara. Given,
'//          CRYPT_DATA_BLOB EncodedMsg; pvPara = (const void *) &EncodedMsg;
'//
'//      Note, also supports the IE3.0 special version of a
'//      PKCS #7 signed message referred to as a "SPC" formatted message.
'//
'//  CERT_STORE_PROV_SERIALIZED:
'//  sz_CERT_STORE_PROV_SERIALIZED:
'//      Gets the certificates and CRLs from memory containing a serialized
'//      store.  The pointer to the serialized memory blob is passed in pvPara.
'//      Given,
'//          CRYPT_DATA_BLOB Serialized; pvPara = (const void *) &Serialized;
'//
'//  CERT_STORE_PROV_FILENAME_A:
'//  CERT_STORE_PROV_FILENAME_W:
'//  CERT_STORE_PROV_FILENAME:
'//  sz_CERT_STORE_PROV_FILENAME_W:
'//  sz_CERT_STORE_PROV_FILENAME:
'//      Opens the file and first attempts to read as a serialized store. Then,
'//      as a PKCS #7 signed message. Finally, as a single encoded certificate.
'//      The filename is passed in pvPara. The filename is UNICODE for the
'//      "_W" provider and ASCII for the "_A" provider. For "_W": given,
'//          LPCWSTR pwszFilename; pvPara = (const void *) pwszFilename;
'//      For "_A": given,
'//          LPCSTR pszFilename; pvPara = (const void *) pszFilename;
'//
'//      Note, the default (without "_A" or "_W") is unicode.
'//
'//      Note, also supports the reading of the IE3.0 special version of a
'//      PKCS #7 signed message file referred to as a "SPC" formatted file.
'//
'//  CERT_STORE_PROV_SYSTEM_A:
'//  CERT_STORE_PROV_SYSTEM_W:
'//  CERT_STORE_PROV_SYSTEM:
'//  sz_CERT_STORE_PROV_SYSTEM_W:
'//  sz_CERT_STORE_PROV_SYSTEM:
'//      Opens the specified logical "System" store. The upper word of the
'//      dwFlags parameter is used to specify the location of the system store.
'//
'//      A "System" store is a collection consisting of one or more "Physical"
'//      stores. A "Physical" store is registered via the
'//      CertRegisterPhysicalStore API. Each of the registered physical stores
'//      is CertStoreOpen'ed and added to the collection via
'//      CertAddStoreToCollection.
'//
'//      The CERT_SYSTEM_STORE_CURRENT_USER, CERT_SYSTEM_STORE_LOCAL_MACHINE,
'//      CERT_SYSTEM_STORE_CURRENT_SERVICE, CERT_SYSTEM_STORE_SERVICES,
'//      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_CURRENT_USER_GROUP_POLICY,
'//      CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY and
'//      CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRSE
'//      system stores by default have a "SystemRegistry" store that is
'//      opened and added to the collection.
'//
'//      The system store name is passed in pvPara. The name is UNICODE for the
'//      "_W" provider and ASCII for the "_A" provider. For "_W": given,
'//          LPCWSTR pwszSystemName; pvPara = (const void *) pwszSystemName;
'//      For "_A": given,
'//          LPCSTR pszSystemName; pvPara = (const void *) pszSystemName;
'//
'//      Note, the default (without "_A" or "_W") is UNICODE.
'//
'//      The system store name can't contain any backslashes.
'//
'//      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
'//      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
'//      of pointing to a null terminated UNICODE or ASCII string.
'//      Sibling physical stores are also opened as relocated using
'//      pvPara's hKeyBase.
'//
'//      The CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS system
'//      store name must be prefixed with the ServiceName or UserName.
'//      For example, "ServiceName\Trust".
'//
'//      Stores on remote computers can be accessed for the
'//      CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
'//      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
'//      or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
'//      locations by prepending the computer name. For example, a remote
'//      local machine store is accessed via "\\ComputerName\Trust" or
'//      "ComputerName\Trust". A remote service store is accessed via
'//      "\\ComputerName\ServiceName\Trust". The leading "\\" backslashes are
'//      optional in the ComputerName.
'//
'//      If CERT_STORE_READONLY_FLAG is set, then, the registry is
'//      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry is
'//      RegCreateKey'ed with KEY_ALL_ACCESS.
'//
'//      The "root" store is treated differently from the other system
'//      stores. Before a certificate is added to or deleted from the "root"
'//      store, a pop up message box is displayed. The certificate's subject,
'//      issuer, serial number, time validity, sha1 and md5 thumbprints are
'//      displayed. The user is given the option to do the add or delete.
'//      If they don't allow the operation, LastError is set to E_ACCESSDENIED.
'//
'//  CERT_STORE_PROV_SYSTEM_REGISTRY_A
'//  CERT_STORE_PROV_SYSTEM_REGISTRY_W
'//  CERT_STORE_PROV_SYSTEM_REGISTRY
'//  sz_CERT_STORE_PROV_SYSTEM_REGISTRY_W
'//  sz_CERT_STORE_PROV_SYSTEM_REGISTRY
'//      Opens the "System" store's default "Physical" store residing in the
'//      registry. The upper word of the dwFlags
'//      parameter is used to specify the location of the system store.
'//
'//      After opening the registry key associated with the system name,
'//      the CERT_STORE_PROV_REG provider is called to complete the open.
'//
'//      The system store name is passed in pvPara. The name is UNICODE for the
'//      "_W" provider and ASCII for the "_A" provider. For "_W": given,
'//          LPCWSTR pwszSystemName; pvPara = (const void *) pwszSystemName;
'//      For "_A": given,
'//          LPCSTR pszSystemName; pvPara = (const void *) pszSystemName;
'//
'//      Note, the default (without "_A" or "_W") is UNICODE.
'//
'//      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
'//      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
'//      of pointing to a null terminated UNICODE or ASCII string.
'//
'//      See above for details on prepending a ServiceName and/or ComputerName
'//      to the store name.
'//
'//      If CERT_STORE_READONLY_FLAG is set, then, the registry is
'//      RegOpenKey'ed with KEY_READ_ACCESS. Otherwise, the registry is
'//      RegCreateKey'ed with KEY_ALL_ACCESS.
'//
'//      The "root" store is treated differently from the other system
'//      stores. Before a certificate is added to or deleted from the "root"
'//      store, a pop up message box is displayed. The certificate's subject,
'//      issuer, serial number, time validity, sha1 and md5 thumbprints are
'//      displayed. The user is given the option to do the add or delete.
'//      If they don't allow the operation, LastError is set to E_ACCESSDENIED.
'//
'//  CERT_STORE_PROV_PHYSICAL_W
'//  CERT_STORE_PROV_PHYSICAL
'//  sz_CERT_STORE_PROV_PHYSICAL_W
'//  sz_CERT_STORE_PROV_PHYSICAL
'//      Opens the specified "Physical" store in the "System" store.
'//
'//      Both the system store and physical names are passed in pvPara. The
'//      names are separated with an intervening "\". For example,
'//      "Root\.Default". The string is UNICODE.
'//
'//      The system and physical store names can't contain any backslashes.
'//
'//      If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvPara
'//      points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure instead
'//      of pointing to a null terminated UNICODE string.
'//      The specified physical store is opened as relocated using pvPara's
'//      hKeyBase.
'//
'//      For CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS,
'//      the system and physical store names
'//      must be prefixed with the ServiceName or UserName. For example,
'//      "ServiceName\Root\.Default".
'//
'//      Physical stores on remote computers can be accessed for the
'//      CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
'//      CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
'//      or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
'//      locations by prepending the computer name. For example, a remote
'//      local machine store is accessed via "\\ComputerName\Root\.Default"
'//      or "ComputerName\Root\.Default". A remote service store is
'//      accessed via "\\ComputerName\ServiceName\Root\.Default". The
'//      leading "\\" backslashes are optional in the ComputerName.
'//
'//  CERT_STORE_PROV_COLLECTION
'//  sz_CERT_STORE_PROV_COLLECTION
'//      Opens a store that is a collection of other stores. Stores are
'//      added or removed to/from the collection via the CertAddStoreToCollection
'//      and CertRemoveStoreFromCollection APIs.
'//
'//  CERT_STORE_PROV_SMART_CARD_W
'//  CERT_STORE_PROV_SMART_CARD
'//  sz_CERT_STORE_PROV_SMART_CARD_W
'//  sz_CERT_STORE_PROV_SMART_CARD
'//      Opens a store instantiated over a particular smart card storage.  pvPara
'//      identifies where on the card the store is located and is of the
'//      following format:
'//
'//                Card Name\Provider Name\Provider Type[\Container Name]
'//
'//      Container Name is optional and if NOT specified the Card Name is used
'//      as the Container Name.  Future versions of the provider will support
'//      instantiating the store over the entire card in which case just
'//      Card Name ( or id ) will be sufficient.
'//
'//  Here's a list of the predefined provider types (implemented in
'//  cryptnet.dll):
'//
'//  CERT_STORE_PROV_LDAP_W
'//  CERT_STORE_PROV_LDAP
'//  sz_CERT_STORE_PROV_LDAP_W
'//  sz_CERT_STORE_PROV_LDAP
'//      Opens a store over the results of the query specified by and LDAP
'//      URL which is passed in via pvPara.  In order to do writes to the
'//      store the URL must specify a BASE query, no filter and a single
'//      attribute.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertOpenStore IMPORT "CRYPT32.DLL" ALIAS "CertOpenStore" ( _
   BYREF lpszStoreProvider AS ASCIIZ _                  ' __in LPCSTR lpszStoreProvider
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvPara AS ANY _                                ' __in const void *pvPara
 ) AS DWORD                                             ' HCERTSTORE

'//+-------------------------------------------------------------------------
'//  OID Installable Certificate Store Provider Data Structures
'//--------------------------------------------------------------------------

'// Handle returned by the store provider when opened.
'typedef void *HCERTSTOREPROV;

'// Store Provider OID function's pszFuncName.
'#define CRYPT_OID_OPEN_STORE_PROV_FUNC   "CertDllOpenStoreProv"
$CRYPT_OID_OPEN_STORE_PROV_FUNC = "CertDllOpenStoreProv"

'// Note, the Store Provider OID function's dwEncodingType is always 0.

'// The following information is returned by the provider when opened. Its
'// zeroed with cbSize set before the provider is called. If the provider
'// doesn't need to be called again after the open it doesn't need to
'// make any updates to the CERT_STORE_PROV_INFO.

' // Size = 24 bytes
TYPE CERT_STORE_PROV_INFO DWORD
   cbSize              AS DWORD   ' DWORD
   cStoreProvFunc      AS DWORD   ' DWORD
   rgpvStoreProvFunc   AS DWORD   ' void**
   hStoreProv          AS DWORD   ' HCERTSTOREPROV
   dwStoreProvFlags    AS DWORD   ' DWORD
   hStoreProvFuncAddr2 AS DWORD   ' HCRYPTOIDFUNCADDR
END TYPE

'// Definition of the store provider's open function.
'//
'// *pStoreProvInfo has been zeroed before the call.
'//
'// Note, pStoreProvInfo->cStoreProvFunc should be set last.  Once set,
'// all subsequent store calls, such as CertAddSerializedElementToStore will
'// call the appropriate provider callback function.
'typedef BOOL (WINAPI *PFN_CERT_DLL_OPEN_STORE_PROV_FUNC)(
'    IN LPCSTR lpszStoreProvider,
'    IN DWORD dwEncodingType,
'    IN HCRYPTPROV hCryptProv,
'    IN DWORD dwFlags,
'    IN const void *pvPara,
'    IN HCERTSTORE hCertStore,
'    IN OUT PCERT_STORE_PROV_INFO pStoreProvInfo
'    );

'FUNCTION CERT_DLL_OPEN_STORE_PROV_FUNC( _
'   BYREF lpszStoreProvider AS ASCIIZ, _                 ' __in LPCSTR lpszStoreProvider
'   BYVAL dwEncodingType AS DWORD, _                     ' __in DWORD dwEncodingType
'   BYVAL hCryptProv AS DWORD, _                         ' __in HCRYPTPROV hCryptProv
'   BYVAL dwFlags AS DWORD, _                            ' __in DWORD dwFlags
'   BYVAL pvPara AS DWORD, _                             ' __in const void *pvPara
'   BYVAL hCertStore AS DWORD, _                         ' __in HCERTSTORE hCertStore
'   BYREF pStoreProvInfo AS CERT_STORE_PROV_INFO _       ' __inout PCERT_STORE_PROV_INFO pStoreProvInfo
' ) AS LONG                                              ' BOOL

'// The open callback sets the following flag, if it maintains its
'// contexts externally and not in the cached store.
%CERT_STORE_PROV_EXTERNAL_FLAG           = &H1???

'// The open callback sets the following flag for a successful delete.
'// When set, the close callback isn't called.
%CERT_STORE_PROV_DELETED_FLAG            = &H2???

'// The open callback sets the following flag if it doesn't persist store
'// changes.
%CERT_STORE_PROV_NO_PERSIST_FLAG         = &H4???

'// The open callback sets the following flag if the contexts are persisted
'// to a system store.
%CERT_STORE_PROV_SYSTEM_STORE_FLAG       = &H8???

'// The open callback sets the following flag if the contexts are persisted
'// to a LocalMachine system store.
%CERT_STORE_PROV_LM_SYSTEM_STORE_FLAG    = &H10???

'// The open callback sets the following flag if the contexts are persisted
'// to a GroupPolicy system store.
%CERT_STORE_PROV_GP_SYSTEM_STORE_FLAG    = &H20???

'// Indices into the store provider's array of callback functions.
'//
'// The provider can implement any subset of the following functions. It
'// sets pStoreProvInfo->cStoreProvFunc to the last index + 1 and any
'// preceding not implemented functions to NULL.
%CERT_STORE_PROV_CLOSE_FUNC              = 0
%CERT_STORE_PROV_READ_CERT_FUNC          = 1
%CERT_STORE_PROV_WRITE_CERT_FUNC         = 2
%CERT_STORE_PROV_DELETE_CERT_FUNC        = 3
%CERT_STORE_PROV_SET_CERT_PROPERTY_FUNC  = 4
%CERT_STORE_PROV_READ_CRL_FUNC           = 5
%CERT_STORE_PROV_WRITE_CRL_FUNC          = 6
%CERT_STORE_PROV_DELETE_CRL_FUNC         = 7
%CERT_STORE_PROV_SET_CRL_PROPERTY_FUNC   = 8
%CERT_STORE_PROV_READ_CTL_FUNC           = 9
%CERT_STORE_PROV_WRITE_CTL_FUNC          = 10
%CERT_STORE_PROV_DELETE_CTL_FUNC         = 11
%CERT_STORE_PROV_SET_CTL_PROPERTY_FUNC   = 12
%CERT_STORE_PROV_CONTROL_FUNC            = 13
%CERT_STORE_PROV_FIND_CERT_FUNC          = 14
%CERT_STORE_PROV_FREE_FIND_CERT_FUNC     = 15
%CERT_STORE_PROV_GET_CERT_PROPERTY_FUNC  = 16
%CERT_STORE_PROV_FIND_CRL_FUNC           = 17
%CERT_STORE_PROV_FREE_FIND_CRL_FUNC      = 18
%CERT_STORE_PROV_GET_CRL_PROPERTY_FUNC   = 19
%CERT_STORE_PROV_FIND_CTL_FUNC           = 20
%CERT_STORE_PROV_FREE_FIND_CTL_FUNC      = 21
%CERT_STORE_PROV_GET_CTL_PROPERTY_FUNC   = 22


'// Called by CertCloseStore when the store's reference count is
'// decremented to 0.
'typedef void (WINAPI *PFN_CERT_STORE_PROV_CLOSE)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN DWORD dwFlags
'    );

'SUB CERT_STORE_PROV_CLOSE ( _
'   BYVAL hStoreProv AS DWORD, _        ' __in HCERTSTOREPROV hStoreProv
'   BYVAL dwFlags AS DWORD _            ' __in DWORD dwFlags
'   )                                   ' void

'// Currently not called directly by the store APIs. However, may be exported
'// to support other providers based on it.
'//
'// Reads the provider's copy of the certificate context. If it exists,
'// creates a new certificate context.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CERT)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pStoreCertContext,
'    IN DWORD dwFlags,
'    OUT PCCERT_CONTEXT *ppProvCertContext
'    );

'FUNCTION CERT_STORE_PROV_READ_CERT ( _
'   BYVAL hStoreProv AS DWORD, _                    ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pStoreCertContext AS CERT_CONTEXT PTR, _  ' __in PCCERT_CONTEXT pStoreCertContext
'   BYVAL dwFlags AS DWORD, _                       ' __in DWORD dwFlags
'   BYREF ppProvCertContext AS DWORD _              ' __out PCCERT_CONTEXT *ppProvCertContext
' ) AS LONG                                         ' BOOL

%CERT_STORE_PROV_WRITE_ADD_FLAG      = &H1???

'// Called by CertAddEncodedCertificateToStore,
'// CertAddCertificateContextToStore or CertAddSerializedElementToStore before
'// adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
'// addition to the encoded certificate, the added pCertContext might also
'// have properties.
'//
'// Returns TRUE if its OK to update the the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CERT)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pCertContext,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_WRITE_CERT ( _
'   BYVAL hStoreProv AS DWORD, _                ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCertContext AS CERT_CONTEXT PTR, _   ' __in PCCERT_CONTEXT pCertContext
'   BYVAL dwFlags AS DWORD _                    ' __in DWORD dwFlags
' ) AS LONG                                     ' BOOL

'// Called by CertDeleteCertificateFromStore before deleting from the
'// store.
'//
'// Returns TRUE if its OK to delete from the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CERT)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pCertContext,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_DELETE_CERT ( _
'   BYVAL hStoreProv AS DWORD, _                ' __in HCERTSTOREPROV hStoreProv,
'   BYVAL pCertContext AS CERT_CONTEXT PTR, _   ' __in PCCERT_CONTEXT pCertContext,
'   BYVAL dwFlags AS DWORD _                    ' __in DWORD dwFlags
' ) AS LONG                                     ' BOOL

'// Called by CertSetCertificateContextProperty before setting the
'// certificate's property. Also called by CertGetCertificateContextProperty,
'// when getting a hash property that needs to be created and then persisted
'// via the set.
'//
'// Upon input, the property hasn't been set for the pCertContext parameter.
'//
'// Returns TRUE if its OK to set the property.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CERT_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pCertContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    IN const void *pvData
'    );

'FUNCTION CERT_STORE_PROV_SET_CERT_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _                ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCertContext AS CERT_CONTEXT PTR, _   ' __in PCCERT_CONTEXT pCertContext
'   BYVAL dwPropId AS DWORD, _                  ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                   ' __in DWORD dwFlags
'   BYVAL pvData AS DWORD _                     ' __in const void *pvData
' ) AS LONG                                     ' BOOL

'// Currently not called directly by the store APIs. However, may be exported
'// to support other providers based on it.
'//
'// Reads the provider's copy of the CRL context. If it exists,
'// creates a new CRL context.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CRL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pStoreCrlContext,
'    IN DWORD dwFlags,
'    OUT PCCRL_CONTEXT *ppProvCrlContext
'    );

'FUNCTION CERT_STORE_PROV_READ_CRL ( _
'   BYVAL hStoreProv AS DWORD, _                  ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pStoreCrlContext AS CRL_CONTEXT PTR, _  ' __in PCCRL_CONTEXT pStoreCrlContext
'   BYVAL dwFlags AS DWORD, _                     ' __in DWORD dwFlags
'   BYVAL ppProvCrlContext AS CRL_CONTEXT PTR _   ' __out PCCRL_CONTEXT *ppProvCrlContext
'   )                                             ' BOOL

'// Called by CertAddEncodedCRLToStore,
'// CertAddCRLContextToStore or CertAddSerializedElementToStore before
'// adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
'// addition to the encoded CRL, the added pCertContext might also
'// have properties.
'//
'// Returns TRUE if its OK to update the the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CRL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pCrlContext,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_WRITE_CRL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCrlContext AS CRL_CONTEXT PTR, _    ' __in PCCRL_CONTEXT pCrlContext
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'// Called by CertDeleteCRLFromStore before deleting from the store.
'//
'// Returns TRUE if its OK to delete from the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CRL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pCrlContext,
'    IN DWORD dwFlags
'    );

'FUBNCTION FN_CERT_STORE_PROV_DELETE_CRL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCrlContext AS CRL_CONTEXT PTR, _    ' __in PCCRL_CONTEXT pCrlContext
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'// Called by CertSetCRLContextProperty before setting the
'// CRL's property. Also called by CertGetCRLContextProperty,
'// when getting a hash property that needs to be created and then persisted
'// via the set.
'//
'// Upon input, the property hasn't been set for the pCrlContext parameter.
'//
'// Returns TRUE if its OK to set the property.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CRL_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pCrlContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    IN const void *pvData
'    );

'FUNCTION CERT_STORE_PROV_SET_CRL_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCrlContext AS CRL_CONTEXT PTR, _    ' __in PCCRL_CONTEXT pCrlContext
'   BYVAL dwPropId AS DWORD, _                 ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                  ' __in DWORD dwFlags
'   BYVAL pvData AS DWORD _                    ' __in const void *pvData
' ) AS LONG                                    ' BOOL

'// Currently not called directly by the store APIs. However, may be exported
'// to support other providers based on it.
'//
'// Reads the provider's copy of the CTL context. If it exists,
'// creates a new CTL context.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_READ_CTL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pStoreCtlContext,
'    IN DWORD dwFlags,
'    OUT PCCTL_CONTEXT *ppProvCtlContext
'    );

'FUNCTION CERT_STORE_PROV_READ_CTL ( _
'   BYVAL hStoreProv AS DWORD, _                  ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pStoreCtlContext AS CTL_CONTEXT PTR, _  ' __in PCCTL_CONTEXT pStoreCtlContext
'   BYVAL dwFlags AS DWORD, _                     ' __in DWORD dwFlags
'   BYREF ppProvCtlContext AS DWORD _             ' __out PCCTL_CONTEXT *ppProvCtlContext
' ) AS LONG                                       ' BOOL

'// Called by CertAddEncodedCTLToStore,
'// CertAddCTLContextToStore or CertAddSerializedElementToStore before
'// adding to the store. The CERT_STORE_PROV_WRITE_ADD_FLAG is set. In
'// addition to the encoded CTL, the added pCertContext might also
'// have properties.
'//
'// Returns TRUE if its OK to update the the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_WRITE_CTL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pCtlContext,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_WRITE_CTL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCtlContext AS CTL_CONTEXT PTR, _    ' __in PCCTL_CONTEXT pCtlContext
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'// Called by CertDeleteCTLFromStore before deleting from the store.
'//
'// Returns TRUE if its OK to delete from the store.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_DELETE_CTL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pCtlContext,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_DELETE_CTL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCtlContext AS CTL_CONTEXT PTR, _    ' __in PCCTL_CONTEXT pCtlContext
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'// Called by CertSetCTLContextProperty before setting the
'// CTL's property. Also called by CertGetCTLContextProperty,
'// when getting a hash property that needs to be created and then persisted
'// via the set.
'//
'// Upon input, the property hasn't been set for the pCtlContext parameter.
'//
'// Returns TRUE if its OK to set the property.
'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_SET_CTL_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pCtlContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    IN const void *pvData
'    );

'FUNCTION CERT_STORE_PROV_SET_CTL_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCtlContext AS CTL_CONTEXT PTR, _    ' __in PCCTL_CONTEXT pCtlContext
'   BYVAL dwPropId AS DWORD, _                 ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                  ' __in DWORD dwFlags
'   BYVAL pvData AS DWORD _                    ' __in const void *pvData
' ) AS LONG                                    ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_CONTROL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN DWORD dwFlags,
'    IN DWORD dwCtrlType,
'    IN void const *pvCtrlPara
'    );

'FUNCTION CERT_STORE_PROV_CONTROL ( _
'   BYVAL hStoreProv AS DWORD, _            ' __in HCERTSTOREPROV hStoreProv
'   BYVAL dwFlags AS DWORD, _               ' __in DWORD dwFlags
'   BYVAL dwCtrlType AS DWORD, _            ' __in DWORD dwCtrlType
'   BYVAL pvCtrlPara AS DWORD _             ' __in void const *pvCtrlPara
' ) AS LONG                                 ' BOOL

' // Size = 20 bytes
TYPE CERT_STORE_PROV_FIND_INFO DWORD
   cbSize                   AS DWORD   ' DWORD
   dwMsgAndCertEncodingType AS DWORD   ' DWORD
   dwFindFlags              AS DWORD   ' DWORD
   dwFindType               AS DWORD   ' DWORD
   pvFindPara               AS DWORD   ' const void*
END TYPE

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CERT)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_STORE_PROV_FIND_INFO pFindInfo,
'    IN PCCERT_CONTEXT pPrevCertContext,
'    IN DWORD dwFlags,
'    IN OUT void **ppvStoreProvFindInfo,
'    OUT PCCERT_CONTEXT *ppProvCertContext
'    );

'FUNCTION CERT_STORE_PROV_FIND_CERT ( _
'   BYVAL hStoreProv AS DWORD, _                     ' __in HCERTSTOREPROV hStoreProv
'   BYREF pFindInfo AS CERT_STORE_PROV_FIND_INFO, _  ' __in PCCERT_STORE_PROV_FIND_INFO pFindInfo
'   BYVAL pPrevCertContext AS CERT_CONTEXT PTR, _    ' __in PCCERT_CONTEXT pPrevCertContext
'   BYVAL dwFlags AS DWORD, _                        ' __in DWORD dwFlags
'   BYREF ppvStoreProvFindInfo AS DWORD, _           ' __inout void **ppvStoreProvFindInfo
'   BYREF ppProvCertContext AS DWORD _               ' __out PCCERT_CONTEXT *ppProvCertContext
' ) AS LONG                                          ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CERT)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pCertContext,
'    IN void *pvStoreProvFindInfo,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_FREE_FIND_CERT ( _
'   BYVAL hStoreProv AS DWORD, _                ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCertContext AS CERT_CONTEXT PTR, _   ' __in PCCERT_CONTEXT pCertContext
'   BYVAL pvStoreProvFindInfo AS DWORD, _       ' __in void *pvStoreProvFindInfo
'   BYVAL dwFlags AS DWORD, _                   ' __in DWORD dwFlags
' ) AS LONG                                     ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CERT_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_CONTEXT pCertContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    OUT void *pvData,
'    IN OUT DWORD *pcbData
'    );

'FUNCTION CERT_STORE_PROV_GET_CERT_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _                ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCertContext AS CERT_CONTEXT PTR, _   ' __in PCCERT_CONTEXT pCertContext
'   BYVAL dwPropId AS DWORD, _                  ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                   ' __in DWORD dwFlags
'   BYREF pvData AS DWORD, _                    ' __out void *pvData
'   BYREF pcbData AS DWORD _                    ' __inout DWORD *pcbData
' ) AS LONG                                     ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CRL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_STORE_PROV_FIND_INFO pFindInfo,
'    IN PCCRL_CONTEXT pPrevCrlContext,
'    IN DWORD dwFlags,
'    IN OUT void **ppvStoreProvFindInfo,
'    OUT PCCRL_CONTEXT *ppProvCrlContext
'    );

'FUNCTION CERT_STORE_PROV_FIND_CRL ( _
'   BYVAL hStoreProv AS DWORD, _                     ' __in HCERTSTOREPROV hStoreProv
'   BYREF pFindInfo AS CERT_STORE_PROV_FIND_INFO, _  ' __in PCCERT_STORE_PROV_FIND_INFO pFindInfo
'   BYVAL pPrevCrlContext AS CRL_CONTEXT PTR, _      ' __in PCCRL_CONTEXT pPrevCrlContext
'   BYVAL dwFlags AS DWORD, _                        ' __in DWORD dwFlags
'   BYREF ppvStoreProvFindInfo AS DWORD, _           ' __inout void **ppvStoreProvFindInfo
'   BYVAL ppProvCrlContext AS CRL_CONTEXT PTR _      ' __out PCCRL_CONTEXT *ppProvCrlContext
' ) AS LONG                                          ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CRL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pCrlContext,
'    IN void *pvStoreProvFindInfo,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_FREE_FIND_CRL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCrlContext AS CRL_CONTEXT PTR, _    ' __in PCCRL_CONTEXT pCrlContext
'   BYVAL pvStoreProvFindInfo AS DWORD, _      ' __in void *pvStoreProvFindInfo
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CRL_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCRL_CONTEXT pCrlContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    OUT void *pvData,
'    IN OUT DWORD *pcbData
'    );

'FUNCTION CERT_STORE_PROV_GET_CRL_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVALF pCrlContext AS CRL_CONTEXT PTR, _   ' __in PCCRL_CONTEXT pCrlContext
'   BYVAL dwPropId AS DWORD, _                 ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                  ' __in DWORD dwFlags
'   BYREF pvData AS DWORD, _                   ' __out void *pvData
'   BYREF pcbData AS DWORD, _                  ' __inout DWORD *pcbData
' ) AS LONG                                    ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FIND_CTL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCERT_STORE_PROV_FIND_INFO pFindInfo,
'    IN PCCTL_CONTEXT pPrevCtlContext,
'    IN DWORD dwFlags,
'    IN OUT void **ppvStoreProvFindInfo,
'    OUT PCCTL_CONTEXT *ppProvCtlContext
'    );

'FUNCTION CERT_STORE_PROV_FIND_CTL ( _
'   BYVAL hStoreProv AS DWORD, _                     ' __in HCERTSTOREPROV hStoreProv
'   BYREF pFindInfo AS CERT_STORE_PROV_FIND_INFO, _  ' __in PCCERT_STORE_PROV_FIND_INFO pFindInfo
'   BYVAL pPrevCtlContext AS CTL_CONTEXT PTR, _      ' __in PCCTL_CONTEXT pPrevCtlContext
'   BYVAL dwFlags AS DWORD, _                        ' __in DWORD dwFlags
'   BYREF ppvStoreProvFindInfo AS DWORD, _           ' __inout void **ppvStoreProvFindInfo
'   BYREF ppProvCtlContext AS DWORD _                ' __out PCCTL_CONTEXT *ppProvCtlContext
' ) AS LONG                                          ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_FREE_FIND_CTL)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pCtlContext,
'    IN void *pvStoreProvFindInfo,
'    IN DWORD dwFlags
'    );

'FUNCTION CERT_STORE_PROV_FREE_FIND_CTL ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCtlContext AS CTL_CONTEXT PTR, _    ' __in PCCTL_CONTEXT pCtlContext
'   BYREF pvStoreProvFindInfo AS DWORD, _      ' __in void *pvStoreProvFindInfo
'   BYVAL dwFlags AS DWORD _                   ' __in DWORD dwFlags
' ) AS LONG                                    ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_STORE_PROV_GET_CTL_PROPERTY)(
'    IN HCERTSTOREPROV hStoreProv,
'    IN PCCTL_CONTEXT pCtlContext,
'    IN DWORD dwPropId,
'    IN DWORD dwFlags,
'    OUT void *pvData,
'    IN OUT DWORD *pcbData
'    );

'FUNCTION CERT_STORE_PROV_GET_CTL_PROPERTY ( _
'   BYVAL hStoreProv AS DWORD, _               ' __in HCERTSTOREPROV hStoreProv
'   BYVAL pCtlContext AS CTL_CONTEXT PTR, _    ' __in PCCTL_CONTEXT pCtlContext
'   BYVAL dwPropId AS DWORD, _                 ' __in DWORD dwPropId
'   BYVAL dwFlags AS DWORD, _                  ' __in DWORD dwFlags
'   BYREF pvData AS DWORD, _                   ' __out void *pvData
'   BYREF pcbData AS DWORD _                   ' __inout DWORD *pcbData
' ) AS LONG                                    ' BOOL

'//+-------------------------------------------------------------------------
'//  Duplicate a cert store handle
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertDuplicateStore IMPORT "CRYPT32.DLL" ALIAS "CertDuplicateStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 ) AS DWORD                                             ' HCERTSTORE

%CERT_STORE_SAVE_AS_STORE        = 1???
%CERT_STORE_SAVE_AS_PKCS7        = 2???
%CERT_STORE_SAVE_AS_PKCS12       = 3???

%CERT_STORE_SAVE_TO_FILE         = 1???
%CERT_STORE_SAVE_TO_MEMORY       = 2???
%CERT_STORE_SAVE_TO_FILENAME_A   = 3???
%CERT_STORE_SAVE_TO_FILENAME_W   = 4???
%CERT_STORE_SAVE_TO_FILENAME     = %CERT_STORE_SAVE_TO_FILENAME_W

'//+-------------------------------------------------------------------------
'//  Save the cert store. Extended version with lots of options.
'//
'//  According to the dwSaveAs parameter, the store can be saved as a
'//  serialized store (CERT_STORE_SAVE_AS_STORE) containing properties in
'//  addition to encoded certificates, CRLs and CTLs or the store can be saved
'//  as a PKCS #7 signed message (CERT_STORE_SAVE_AS_PKCS7) which doesn't
'//  include the properties or CTLs.
'//
'//  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
'//  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't saved into
'//  a serialized store.
'//
'//  For CERT_STORE_SAVE_AS_PKCS7, the dwEncodingType specifies the message
'//  encoding type. The dwEncodingType parameter isn't used for
'//  CERT_STORE_SAVE_AS_STORE.
'//
'//  The dwFlags parameter currently isn't used and should be set to 0.
'//
'//  The dwSaveTo and pvSaveToPara parameters specify where to save the
'//  store as follows:
'//    CERT_STORE_SAVE_TO_FILE:
'//      Saves to the specified file. The file's handle is passed in
'//      pvSaveToPara. Given,
'//          HANDLE hFile; pvSaveToPara = (void *) hFile;
'//
'//      For a successful save, the file pointer is positioned after the
'//      last write.
'//
'//    CERT_STORE_SAVE_TO_MEMORY:
'//      Saves to the specified memory blob. The pointer to
'//      the memory blob is passed in pvSaveToPara. Given,
'//          CRYPT_DATA_BLOB SaveBlob; pvSaveToPara = (void *) &SaveBlob;
'//      Upon entry, the SaveBlob's pbData and cbData need to be initialized.
'//      Upon return, cbData is updated with the actual length.
'//      For a length only calculation, pbData should be set to NULL. If
'//      pbData is non-NULL and cbData isn't large enough, FALSE is returned
'//      with a last error of ERRROR_MORE_DATA.
'//
'//    CERT_STORE_SAVE_TO_FILENAME_A:
'//    CERT_STORE_SAVE_TO_FILENAME_W:
'//    CERT_STORE_SAVE_TO_FILENAME:
'//      Opens the file and saves to it. The filename is passed in pvSaveToPara.
'//      The filename is UNICODE for the "_W" option and ASCII for the "_A"
'//      option. For "_W": given,
'//          LPCWSTR pwszFilename; pvSaveToPara = (void *) pwszFilename;
'//      For "_A": given,
'//          LPCSTR pszFilename; pvSaveToPara = (void *) pszFilename;
'//
'//      Note, the default (without "_A" or "_W") is UNICODE.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertSaveStore IMPORT "CRYPT32.DLL" ALIAS "CertSaveStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL dwSaveAs AS DWORD _                            ' __in DWORD dwSaveAs
 , BYVAL dwSaveTo AS DWORD _                            ' __in DWORD dwSaveTo
 , BYREF pvSaveToPara AS ANY _                          ' __inout void *pvSaveToPara
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Certificate Store close flags
'//--------------------------------------------------------------------------
%CERT_CLOSE_STORE_FORCE_FLAG         = &H00000001???
%CERT_CLOSE_STORE_CHECK_FLAG         = &H00000002???

'//+-------------------------------------------------------------------------
'//  Close a cert store handle.
'//
'//  There needs to be a corresponding close for each open and duplicate.
'//
'//  Even on the final close, the cert store isn't freed until all of its
'//  certificate and CRL contexts have also been freed.
'//
'//  On the final close, the hCryptProv passed to CertStoreOpen is
'//  CryptReleaseContext'ed.
'//
'//  To force the closure of the store with all of its memory freed, set the
'//  CERT_STORE_CLOSE_FORCE_FLAG. This flag should be set when the caller does
'//  its own reference counting and wants everything to vanish.
'//
'//  To check if all the store's certificates and CRLs have been freed and that
'//  this is the last CertCloseStore, set the CERT_CLOSE_STORE_CHECK_FLAG. If
'//  set and certs, CRLs or stores still need to be freed/closed, FALSE is
'//  returned with LastError set to CRYPT_E_PENDING_CLOSE. Note, for FALSE,
'//  the store is still closed. This is a diagnostic flag.
'//
'//  LastError is preserved unless CERT_CLOSE_STORE_CHECK_FLAG is set and FALSE
'//  is returned.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCloseStore IMPORT "CRYPT32.DLL" ALIAS "CertCloseStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwFlags AS DWORD _                             ' DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get the subject certificate context uniquely identified by its Issuer and
'//  SerialNumber from the store.
'//
'//  If the certificate isn't found, NULL is returned. Otherwise, a pointer to
'//  a read only CERT_CONTEXT is returned. CERT_CONTEXT must be freed by calling
'//  CertFreeCertificateContext. CertDuplicateCertificateContext can be called to make a
'//  duplicate.
'//
'//  The returned certificate might not be valid. Normally, it would be
'//  verified when getting its issuer certificate (CertGetIssuerCertificateFromStore).
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertGetSubjectCertificateFromStore IMPORT "CRYPT32.DLL" ALIAS "CertGetSubjectCertificateFromStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pCertId AS CERT_INFO _                         ' __in PCERT_INFO pCertId
 ) AS DWORD                                             ' PCCERT_CONTEXT

'//+-------------------------------------------------------------------------
'//  Enumerate the certificate contexts in the store.
'//
'//  If a certificate isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
'//  must be freed by calling CertFreeCertificateContext or is freed when passed as the
'//  pPrevCertContext on a subsequent call. CertDuplicateCertificateContext
'//  can be called to make a duplicate.
'//
'//  pPrevCertContext MUST BE NULL to enumerate the first
'//  certificate in the store. Successive certificates are enumerated by setting
'//  pPrevCertContext to the CERT_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCertContext is always CertFreeCertificateContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCertificatesInStore LIB "Crypt32.dll" _
    ALIAS "CertEnumCertificatesInStore" ( _
    BYVAL hCertStore AS DWORD, _  ' HCERTSTORE
    pPrevCertContext AS CERT_CONTEXT _
    ) AS DWORD  ' CERT_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertEnumCertificatesInStore IMPORT "CRYPT32.DLL" ALIAS "CertEnumCertificatesInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pPrevCertContext AS CERT_CONTEXT PTR _         ' __in PCCERT_CONTEXT pPrevCertContext
 ) AS DWORD                                             ' PCCERT_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Find the first or next certificate context in the store.
'//
'//  The certificate is found according to the dwFindType and its pvFindPara.
'//  See below for a list of the find types and its parameters.
'//
'//  Currently dwFindFlags is only used for CERT_FIND_SUBJECT_ATTR,
'//  CERT_FIND_ISSUER_ATTR or CERT_FIND_CTL_USAGE. Otherwise, must be set to 0.
'//
'//  Usage of dwCertEncodingType depends on the dwFindType.
'//
'//  If the first or next certificate isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
'//  must be freed by calling CertFreeCertificateContext or is freed when passed as the
'//  pPrevCertContext on a subsequent call. CertDuplicateCertificateContext
'//  can be called to make a duplicate.
'//
'//  pPrevCertContext MUST BE NULL on the first
'//  call to find the certificate. To find the next certificate, the
'//  pPrevCertContext is set to the CERT_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCertContext is always CertFreeCertificateContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindCertificateInStore LIB "Crypt32.dll" _
    ALIAS "CertFindCertificateInStore" ( _
    BYVAL hCertStore         AS DWORD, _ ' HCERTSTORE
    BYVAL dwCertEncodingType AS DWORD, _
    BYVAL dwFindFlags        AS DWORD, _
    BYVAL dwFindType         AS DWORD, _
    pvFindPara               AS ANY, _  ' void *
    pPrevCertContext         AS CERT_CONTEXT _
    ) AS DWORD  ' CERT_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertFindCertificateInStore IMPORT "CRYPT32.DLL" ALIAS "CertFindCertificateInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwFindFlags AS DWORD _                         ' __in DWORD dwFindFlags
 , BYVAL dwFindType AS DWORD _                          ' __in DWORD dwFindType
 , BYREF pvFindPara AS ANY _                            ' __in const void *pvFindPara
 , BYVAL pPrevCertContext AS CERT_CONTEXT PTR _         ' __in PCCERT_CONTEXT pPrevCertContext
 ) AS DWORD                                             ' PCCERT_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'// Certificate comparison functions
'//--------------------------------------------------------------------------
%CERT_COMPARE_MASK           = &HFFFF???
%CERT_COMPARE_SHIFT          = 16???
%CERT_COMPARE_ANY            = 0???
%CERT_COMPARE_SHA1_HASH      = 1???
%CERT_COMPARE_NAME           = 2???
%CERT_COMPARE_ATTR           = 3???
%CERT_COMPARE_MD5_HASH       = 4???
%CERT_COMPARE_PROPERTY       = 5???
%CERT_COMPARE_PUBLIC_KEY     = 6???
%CERT_COMPARE_HASH           = %CERT_COMPARE_SHA1_HASH
%CERT_COMPARE_NAME_STR_A     = 7???
%CERT_COMPARE_NAME_STR_W     = 8???
%CERT_COMPARE_KEY_SPEC       = 9???
%CERT_COMPARE_ENHKEY_USAGE   = 10???
%CERT_COMPARE_CTL_USAGE      = %CERT_COMPARE_ENHKEY_USAGE
%CERT_COMPARE_SUBJECT_CERT   = 11???
%CERT_COMPARE_ISSUER_OF      = 12???
%CERT_COMPARE_EXISTING       = 13???
%CERT_COMPARE_SIGNATURE_HASH = 14???
%CERT_COMPARE_KEY_IDENTIFIER = 15???
%CERT_COMPARE_CERT_ID        = 16???
%CERT_COMPARE_CROSS_CERT_DIST_POINTS = 17???

%CERT_COMPARE_PUBKEY_MD5_HASH = 18???

%CERT_COMPARE_SUBJECT_INFO_ACCESS = 19???

'//+-------------------------------------------------------------------------
'//  dwFindType
'//
'//  The dwFindType definition consists of two components:
'//   - comparison function
'//   - certificate information flag
'//--------------------------------------------------------------------------
'#define CERT_FIND_ANY           (CERT_COMPARE_ANY << CERT_COMPARE_SHIFT)
%CERT_FIND_ANY = 0???
'#define CERT_FIND_SHA1_HASH     (CERT_COMPARE_SHA1_HASH << CERT_COMPARE_SHIFT)
%CERT_FIND_SHA1_HASH = &H10000???
'#define CERT_FIND_MD5_HASH      (CERT_COMPARE_MD5_HASH << CERT_COMPARE_SHIFT)
%CERT_FIND_MD5_HASH = &H40000???
'#define CERT_FIND_SIGNATURE_HASH (CERT_COMPARE_SIGNATURE_HASH << CERT_COMPARE_SHIFT)
%CERT_FIND_SIGNATURE_HASH = &HE0000???
'#define CERT_FIND_KEY_IDENTIFIER (CERT_COMPARE_KEY_IDENTIFIER << CERT_COMPARE_SHIFT)
%CERT_FIND_KEY_IDENTIFIER = &HF0000???
'#define CERT_FIND_HASH          CERT_FIND_SHA1_HASH
%CERT_FIND_HASH = %CERT_FIND_SHA1_HASH
'#define CERT_FIND_PROPERTY      (CERT_COMPARE_PROPERTY << CERT_COMPARE_SHIFT)
%CERT_FIND_PROPERTY = &H50000???
'#define CERT_FIND_PUBLIC_KEY    (CERT_COMPARE_PUBLIC_KEY << CERT_COMPARE_SHIFT)
%CERT_FIND_PUBLIC_KEY = &H60000???
'#define CERT_FIND_SUBJECT_NAME  (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_SUBJECT_FLAG)
%CERT_FIND_SUBJECT_NAME = &H20007???
'#define CERT_FIND_SUBJECT_ATTR  (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_SUBJECT_FLAG)
%CERT_FIND_SUBJECT_ATTR = &H30007???
'#define CERT_FIND_ISSUER_NAME   (CERT_COMPARE_NAME << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_ISSUER_FLAG)
%CERT_FIND_ISSUER_NAME = &H20004???
'#define CERT_FIND_ISSUER_ATTR   (CERT_COMPARE_ATTR << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_ISSUER_FLAG)
%CERT_FIND_ISSUER_ATTR = &H30004???
'#define CERT_FIND_SUBJECT_STR_A (CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_SUBJECT_FLAG)
%CERT_FIND_SUBJECT_STR_A = &H70007???
'#define CERT_FIND_SUBJECT_STR_W (CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_SUBJECT_FLAG)
%CERT_FIND_SUBJECT_STR_W = &H80007???
'#define CERT_FIND_SUBJECT_STR   CERT_FIND_SUBJECT_STR_W
%CERT_FIND_SUBJECT_STR = %CERT_FIND_SUBJECT_STR_W
'#define CERT_FIND_ISSUER_STR_A  (CERT_COMPARE_NAME_STR_A << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_ISSUER_FLAG)
%CERT_FIND_ISSUER_STR_A = &H70004???
'#define CERT_FIND_ISSUER_STR_W  (CERT_COMPARE_NAME_STR_W << CERT_COMPARE_SHIFT | \
'                                 CERT_INFO_ISSUER_FLAG)
%CERT_FIND_ISSUER_STR_W = &H80004???
'#define CERT_FIND_ISSUER_STR    CERT_FIND_ISSUER_STR_W
%CERT_FIND_ISSUER_STR = %CERT_FIND_ISSUER_STR_W
'#define CERT_FIND_KEY_SPEC      (CERT_COMPARE_KEY_SPEC << CERT_COMPARE_SHIFT)
%CERT_FIND_KEY_SPEC = &H90000???
'#define CERT_FIND_ENHKEY_USAGE  (CERT_COMPARE_ENHKEY_USAGE << CERT_COMPARE_SHIFT)
%CERT_FIND_ENHKEY_USAGE = &HA0000???
'#define CERT_FIND_CTL_USAGE     CERT_FIND_ENHKEY_USAGE
%CERT_FIND_CTL_USAGE = %CERT_FIND_ENHKEY_USAGE

'#define CERT_FIND_SUBJECT_CERT  (CERT_COMPARE_SUBJECT_CERT << CERT_COMPARE_SHIFT)
%CERT_FIND_SUBJECT_CERT = &HB0000???
'#define CERT_FIND_ISSUER_OF     (CERT_COMPARE_ISSUER_OF << CERT_COMPARE_SHIFT)
%CERT_FIND_ISSUER_OF = &HC0000???
'#define CERT_FIND_EXISTING      (CERT_COMPARE_EXISTING << CERT_COMPARE_SHIFT)
%CERT_FIND_EXISTING = &HD0000???
'#define CERT_FIND_CERT_ID       (CERT_COMPARE_CERT_ID << CERT_COMPARE_SHIFT)
%CERT_FIND_CERT_ID = &H100000???
'#define CERT_FIND_CROSS_CERT_DIST_POINTS \
'                    (CERT_COMPARE_CROSS_CERT_DIST_POINTS << CERT_COMPARE_SHIFT)
%CERT_FIND_CROSS_CERT_DIST_POINTS = &H110000???

'#define CERT_FIND_PUBKEY_MD5_HASH \
'                    (CERT_COMPARE_PUBKEY_MD5_HASH << CERT_COMPARE_SHIFT)
%CERT_FIND_PUBKEY_MD5_HASH = &H120000???
'#define CERT_FIND_SUBJECT_INFO_ACCESS \
'                    (CERT_COMPARE_SUBJECT_INFO_ACCESS << CERT_COMPARE_SHIFT)
%CERT_FIND_SUBJECT_INFO_ACCESS = &H00130000???

'//+-------------------------------------------------------------------------
'//  CERT_FIND_ANY
'//
'//  Find any certificate.
'//
'//  pvFindPara isn't used.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_HASH
'//
'//  Find a certificate with the specified hash.
'//
'//  pvFindPara points to a CRYPT_HASH_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_KEY_IDENTIFIER
'//
'//  Find a certificate with the specified KeyIdentifier. Gets the
'//  CERT_KEY_IDENTIFIER_PROP_ID property and compares with the input
'//  CRYPT_HASH_BLOB.
'//
'//  pvFindPara points to a CRYPT_HASH_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_PROPERTY
'//
'//  Find a certificate having the specified property.
'//
'//  pvFindPara points to a DWORD containing the PROP_ID
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_PUBLIC_KEY
'//
'//  Find a certificate matching the specified public key.
'//
'//  pvFindPara points to a CERT_PUBLIC_KEY_INFO containing the public key
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_SUBJECT_NAME
'//  CERT_FIND_ISSUER_NAME
'//
'//  Find a certificate with the specified subject/issuer name. Does an exact
'//  match of the entire name.
'//
'//  Restricts search to certificates matching the dwCertEncodingType.
'//
'//  pvFindPara points to a CERT_NAME_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_SUBJECT_ATTR
'//  CERT_FIND_ISSUER_ATTR
'//
'//  Find a certificate with the specified subject/issuer attributes.
'//
'//  Compares the attributes in the subject/issuer name with the
'//  Relative Distinguished Name's (CERT_RDN) array of attributes specified in
'//  pvFindPara. The comparison iterates through the CERT_RDN attributes and looks
'//  for an attribute match in any of the subject/issuer's RDNs.
'//
'//  The CERT_RDN_ATTR fields can have the following special values:
'//    pszObjId == NULL              - ignore the attribute object identifier
'//    dwValueType == RDN_ANY_TYPE   - ignore the value type
'//    Value.pbData == NULL          - match any value
'//
'//  CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG should be set in dwFindFlags to do
'//  a case insensitive match. Otherwise, defaults to an exact, case sensitive
'//  match.
'//
'//  CERT_UNICODE_IS_RDN_ATTRS_FLAG should be set in dwFindFlags if the RDN was
'//  initialized with unicode strings as for
'//  CryptEncodeObject(X509_UNICODE_NAME).
'//
'//  Restricts search to certificates matching the dwCertEncodingType.
'//
'//  pvFindPara points to a CERT_RDN (defined in wincert.h).
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_SUBJECT_STR_A
'//  CERT_FIND_SUBJECT_STR_W | CERT_FIND_SUBJECT_STR
'//  CERT_FIND_ISSUER_STR_A
'//  CERT_FIND_ISSUER_STR_W  | CERT_FIND_ISSUER_STR
'//
'//  Find a certificate containing the specified subject/issuer name string.
'//
'//  First, the certificate's subject/issuer is converted to a name string
'//  via CertNameToStrA/CertNameToStrW(CERT_SIMPLE_NAME_STR). Then, a
'//  case insensitive substring within string match is performed.
'//
'//  Restricts search to certificates matching the dwCertEncodingType.
'//
'//  For *_STR_A, pvFindPara points to a null terminated character string.
'//  For *_STR_W, pvFindPara points to a null terminated wide character string.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_KEY_SPEC
'//
'//  Find a certificate having a CERT_KEY_SPEC_PROP_ID property matching
'//  the specified KeySpec.
'//
'//  pvFindPara points to a DWORD containing the KeySpec.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_ENHKEY_USAGE
'//
'//  Find a certificate having the szOID_ENHANCED_KEY_USAGE extension or
'//  the CERT_ENHKEY_USAGE_PROP_ID and matching the specified pszUsageIdentifers.
'//
'//  pvFindPara points to a CERT_ENHKEY_USAGE data structure. If pvFindPara
'//  is NULL or CERT_ENHKEY_USAGE's cUsageIdentifier is 0, then, matches any
'//  certificate having enhanced key usage.
'//
'//  If the CERT_FIND_VALID_ENHKEY_USAGE_FLAG is set, then, only does a match
'//  for certificates that are valid for the specified usages. By default,
'//  the ceriticate must be valid for all usages. CERT_FIND_OR_ENHKEY_USAGE_FLAG
'//  can be set, if the certificate only needs to be valid for one of the
'//  specified usages. Note, CertGetValidUsages() is called to get the
'//  certificate's list of valid usages. Only the CERT_FIND_OR_ENHKEY_USAGE_FLAG
'//  is applicable when this flag is set.
'//
'//  The CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG can be set in dwFindFlags to
'//  also match a certificate without either the extension or property.
'//
'//  If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set in dwFindFlags, finds
'//  certificates without the key usage extension or property. Setting this
'//  flag takes precedence over pvFindPara being NULL.
'//
'//  If the CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG is set, then, only does a match
'//  using the extension. If pvFindPara is NULL or cUsageIdentifier is set to
'//  0, finds certificates having the extension. If
'//  CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG is set, also matches a certificate
'//  without the extension. If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set, finds
'//  certificates without the extension.
'//
'//  If the CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG is set, then, only does a match
'//  using the property. If pvFindPara is NULL or cUsageIdentifier is set to
'//  0, finds certificates having the property. If
'//  CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG is set, also matches a certificate
'//  without the property. If CERT_FIND_NO_ENHKEY_USAGE_FLAG is set, finds
'//  certificates without the property.
'//
'//  If CERT_FIND_OR_ENHKEY_USAGE_FLAG is set, does an "OR" match of any of
'//  the specified pszUsageIdentifiers. If not set, then, does an "AND" match
'//  of all of the specified pszUsageIdentifiers.
'//--------------------------------------------------------------------------

%CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG  = &H1???
%CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG  = &H2???
%CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG = &H4???
%CERT_FIND_NO_ENHKEY_USAGE_FLAG        = &H8???
%CERT_FIND_OR_ENHKEY_USAGE_FLAG        = &H10???
%CERT_FIND_VALID_ENHKEY_USAGE_FLAG     = &H20???

%CERT_FIND_OPTIONAL_CTL_USAGE_FLAG  = %CERT_FIND_OPTIONAL_ENHKEY_USAGE_FLAG

%CERT_FIND_EXT_ONLY_CTL_USAGE_FLAG  = %CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG

%CERT_FIND_PROP_ONLY_CTL_USAGE_FLAG = %CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG

%CERT_FIND_NO_CTL_USAGE_FLAG        = %CERT_FIND_NO_ENHKEY_USAGE_FLAG
%CERT_FIND_OR_CTL_USAGE_FLAG        = %CERT_FIND_OR_ENHKEY_USAGE_FLAG
%CERT_FIND_VALID_CTL_USAGE_FLAG     = %CERT_FIND_VALID_ENHKEY_USAGE_FLAG

'//+-------------------------------------------------------------------------
'//  CERT_FIND_CERT_ID
'//
'//  Find a certificate with the specified CERT_ID.
'//
'//  pvFindPara points to a CERT_ID.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_FIND_CROSS_CERT_DIST_POINTS
'//
'//  Find a certificate having either a cross certificate distribution
'//  point extension or property.
'//
'//  pvFindPara isn't used.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Get the certificate context from the store for the first or next issuer
'//  of the specified subject certificate. Perform the enabled
'//  verification checks on the subject. (Note, the checks are on the subject
'//  using the returned issuer certificate.)
'//
'//  If the first or next issuer certificate isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CONTEXT is returned. CERT_CONTEXT
'//  must be freed by calling CertFreeCertificateContext or is freed when passed as the
'//  pPrevIssuerContext on a subsequent call. CertDuplicateCertificateContext
'//  can be called to make a duplicate.
'//
'//  For a self signed subject certificate, NULL is returned with LastError set
'//  to CERT_STORE_SELF_SIGNED. The enabled verification checks are still done.
'//
'//  The pSubjectContext may have been obtained from this store, another store
'//  or created by the caller application. When created by the caller, the
'//  CertCreateCertificateContext function must have been called.
'//
'//  An issuer may have multiple certificates. This may occur when the validity
'//  period is about to change. pPrevIssuerContext MUST BE NULL on the first
'//  call to get the issuer. To get the next certificate for the issuer, the
'//  pPrevIssuerContext is set to the CERT_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevIssuerContext is always CertFreeCertificateContext'ed by
'//  this function, even for an error.
'//
'//  The following flags can be set in *pdwFlags to enable verification checks
'//  on the subject certificate context:
'//      CERT_STORE_SIGNATURE_FLAG     - use the public key in the returned
'//                                      issuer certificate to verify the
'//                                      signature on the subject certificate.
'//                                      Note, if pSubjectContext->hCertStore ==
'//                                      hCertStore, the store provider might
'//                                      be able to eliminate a redo of
'//                                      the signature verify.
'//      CERT_STORE_TIME_VALIDITY_FLAG - get the current time and verify that
'//                                      its within the subject certificate's
'//                                      validity period
'//      CERT_STORE_REVOCATION_FLAG    - check if the subject certificate is on
'//                                      the issuer's revocation list
'//
'//  If an enabled verification check fails, then, its flag is set upon return.
'//  If CERT_STORE_REVOCATION_FLAG was enabled and the issuer doesn't have a
'//  CRL in the store, then, CERT_STORE_NO_CRL_FLAG is set in addition to
'//  the CERT_STORE_REVOCATION_FLAG.
'//
'//  If CERT_STORE_SIGNATURE_FLAG or CERT_STORE_REVOCATION_FLAG is set, then,
'//  CERT_STORE_NO_ISSUER_FLAG is set if it doesn't have an issuer certificate
'//  in the store.
'//
'//  For a verification check failure, a pointer to the issuer's CERT_CONTEXT
'//  is still returned and SetLastError isn't updated.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetIssuerCertificateFromStore LIB "Crypt32.dll" _
    ALIAS "CertGetIssuerCertificateFromStore" ( _
    BYVAL hCertStore   AS DWORD, _  ' HCERTSTORE
    pSubjectContext    AS CERT_CONTEXT, _
    pPrevIssuerContext AS CERT_CONTEXT, _
    pdwFlags           AS DWORD _
    ) AS DWORD  ' CERT_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertGetIssuerCertificateFromStore IMPORT "CRYPT32.DLL" ALIAS "CertGetIssuerCertificateFromStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pSubjectContext AS CERT_CONTEXT PTR _          ' __in PCCERT_CONTEXT pSubjectContext
 , BYVAL pPrevIssuerContext AS CERT_CONTEXT PTR _       ' __in_opt PCCERT_CONTEXT pPrevIssuerContext
 , BYREF pdwFlags AS DWORD _                            ' __inout DWORD *pdwFlags
 ) AS DWORD                                             ' PCCERT_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Perform the enabled verification checks on the subject certificate
'//  using the issuer. Same checks and flags definitions as for the above
'//  CertGetIssuerCertificateFromStore.
'//
'//  If you are only checking CERT_STORE_TIME_VALIDITY_FLAG, then, the
'//  issuer can be NULL.
'//
'//  For a verification check failure, SUCCESS is still returned.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertVerifySubjectCertificateContext LIB "Crypt32.dll" _
    ALIAS "CertVerifySubjectCertificateContext" ( _
    pSubject AS CERT_CONTEXT, _
    pIssuer  AS CERT_CONTEXT, _
    pdwFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertVerifySubjectCertificateContext IMPORT "CRYPT32.DLL" ALIAS "CertVerifySubjectCertificateContext" ( _
   BYVAL pSubject AS CERT_CONTEXT PTR _                 ' __in PCCERT_CONTEXT pSubject
 , BYVAL pIssuer AS CERT_CONTEXT PTR _                  ' __in_opt PCCERT_CONTEXT pIssuer
 , BYREF pdwFlags AS DWORD _                            ' __inout DWORD *pdwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Duplicate a certificate context
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDuplicateCertificateContext LIB "Crypt32.dll" _
    ALIAS "CertDuplicateCertificateContext" ( _
    pCertContext AS CERT_CONTEXT _
    ) AS DWORD  ' CERT_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertDuplicateCertificateContext IMPORT "CRYPT32.DLL" ALIAS "CertDuplicateCertificateContext" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 ) AS DWORD                                             ' PCCERT_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Create a certificate context from the encoded certificate. The created
'//  context isn't put in a store.
'//
'//  Makes a copy of the encoded certificate in the created context.
'//
'//  If unable to decode and create the certificate context, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CONTEXT is returned.
'//  CERT_CONTEXT must be freed by calling CertFreeCertificateContext.
'//  CertDuplicateCertificateContext can be called to make a duplicate.
'//
'//  CertSetCertificateContextProperty and CertGetCertificateContextProperty can be called
'//  to store properties for the certificate.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCreateCertificateContext IMPORT "CRYPT32.DLL" ALIAS "CertCreateCertificateContext" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbCertEncoded AS BYTE PTR _                    ' __in const BYTE *pbCertEncoded
 , BYVAL cbCertEncoded AS DWORD _                       ' __in DWORD cbCertEncoded
 ) AS DWORD                                             ' PCCERT_CONTEXT

'//+-------------------------------------------------------------------------
'//  Free a certificate context
'//
'//  There needs to be a corresponding free for each context obtained by a
'//  get, find, duplicate or create.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFreeCertificateContext LIB "Crypt32.dll" _
    ALIAS "CertFreeCertificateContext" ( _
    pCertContext AS CERT_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertFreeCertificateContext IMPORT "CRYPT32.DLL" ALIAS "CertFreeCertificateContext" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Set the property for the specified certificate context.
'//
'//  The type definition for pvData depends on the dwPropId value. There are
'//  five predefined types:
'//      CERT_KEY_PROV_HANDLE_PROP_ID - a HCRYPTPROV for the certificate's
'//      private key is passed in pvData. Updates the hCryptProv field
'//      of the CERT_KEY_CONTEXT_PROP_ID. If the CERT_KEY_CONTEXT_PROP_ID
'//      doesn't exist, its created with all the other fields zeroed out. If
'//      CERT_STORE_NO_CRYPT_RELEASE_FLAG isn't set, HCRYPTPROV is implicitly
'//      released when either the property is set to NULL or on the final
'//      free of the CertContext.
'//
'//      CERT_KEY_PROV_INFO_PROP_ID - a PCRYPT_KEY_PROV_INFO for the certificate's
'//      private key is passed in pvData.
'//
'//      CERT_SHA1_HASH_PROP_ID       -
'//      CERT_MD5_HASH_PROP_ID        -
'//      CERT_SIGNATURE_HASH_PROP_ID  - normally, a hash property is implicitly
'//      set by doing a CertGetCertificateContextProperty. pvData points to a
'//      CRYPT_HASH_BLOB.
'//
'//      CERT_KEY_CONTEXT_PROP_ID - a PCERT_KEY_CONTEXT for the certificate's
'//      private key is passed in pvData. The CERT_KEY_CONTEXT contains both the
'//      hCryptProv and dwKeySpec for the private key.
'//      See the CERT_KEY_PROV_HANDLE_PROP_ID for more information about
'//      the hCryptProv field and dwFlags settings. Note, more fields may
'//      be added for this property. The cbSize field value will be adjusted
'//      accordingly.
'//
'//      CERT_KEY_SPEC_PROP_ID - the dwKeySpec for the private key. pvData
'//      points to a DWORD containing the KeySpec
'//
'//      CERT_ENHKEY_USAGE_PROP_ID - enhanced key usage definition for the
'//      certificate. pvData points to a CRYPT_DATA_BLOB containing an
'//      ASN.1 encoded CERT_ENHKEY_USAGE (encoded via
'//      CryptEncodeObject(X509_ENHANCED_KEY_USAGE).
'//
'//      CERT_NEXT_UPDATE_LOCATION_PROP_ID - location of the next update.
'//      Currently only applicable to CTLs. pvData points to a CRYPT_DATA_BLOB
'//      containing an ASN.1 encoded CERT_ALT_NAME_INFO (encoded via
'//      CryptEncodeObject(X509_ALTERNATE_NAME)).
'//
'//      CERT_FRIENDLY_NAME_PROP_ID - friendly name for the cert, CRL or CTL.
'//      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
'//      terminated unicode, wide character string.
'//      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
'//
'//      CERT_DESCRIPTION_PROP_ID - description for the cert, CRL or CTL.
'//      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
'//      terminated unicode, wide character string.
'//      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
'//
'//      CERT_ARCHIVED_PROP_ID - when this property is set, the certificate
'//      is skipped during enumeration. Note, certificates having this property
'//      are still found for explicit finds, such as, finding a certificate
'//      with a specific hash or finding a certificate having a specific issuer
'//      and serial number. pvData points to a CRYPT_DATA_BLOB. This blob
'//      can be NULL (pbData = NULL, cbData = 0).
'//
'//      CERT_PUBKEY_ALG_PARA_PROP_ID - for public keys supporting
'//      algorithm parameter inheritance. pvData points to a CRYPT_OBJID_BLOB
'//      containing the ASN.1 encoded PublicKey Algorithm Parameters. For
'//      DSS this would be the parameters encoded via
'//      CryptEncodeObject(X509_DSS_PARAMETERS). This property may be set
'//      by CryptVerifyCertificateSignatureEx().
'//
'//      CERT_CROSS_CERT_DIST_POINTS_PROP_ID - location of the cross certs.
'//      Currently only applicable to certs. pvData points to a CRYPT_DATA_BLOB
'//      containing an ASN.1 encoded CROSS_CERT_DIST_POINTS_INFO (encoded via
'//      CryptEncodeObject(X509_CROSS_CERT_DIST_POINTS)).
'//
'//      CERT_ENROLLMENT_PROP_ID - enrollment information of the pending request.
'//      It contains RequestID, CADNSName, CAName, and FriendlyName.
'//      The data format is defined as: the first 4 bytes - pending request ID,
'//      next 4 bytes - CADNSName size in characters including null-terminator
'//      followed by CADNSName string with null-terminator,
'//      next 4 bytes - CAName size in characters including null-terminator
'//      followed by CAName string with null-terminator,
'//      next 4 bytes - FriendlyName size in characters including null-terminator
'//      followed by FriendlyName string with null-terminator.
'//
'//      CERT_DATE_STAMP_PROP_ID - contains the time when added to the store
'//      by an admin tool. pvData points to a CRYPT_DATA_BLOB containing
'//      the FILETIME.
'//
'//      CERT_RENEWAL_PROP_ID - contains the hash of renewed certificate
'//
'//      CERT_OCSP_RESPONSE_PROP_ID - contains the encoded OCSP response.
'//      CryptDecodeObject/CryptEncodeObject using
'//      lpszStructType = OCSP_RESPONSE.
'//      pvData points to a CRYPT_DATA_BLOB containing the encoded OCSP response.
'//      If this property is present, CertVerifyRevocation() will first attempt
'//      to use before doing an URL retrieval.
'//
'//      CERT_SOURCE_LOCATION_PROP_ID - contains source location of the CRL or
'//      OCSP. pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
'//      terminated unicode, wide character string. Where,
'//      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
'//
'//      CERT_SOURCE_URL_PROP_ID - contains URL for the CRL or OCSP. pvData
'//      is the same as for CERT_SOURCE_LOCATION_PROP_ID.
'//
'//      CERT_CEP_PROP_ID - contains Version, PropertyFlags, AuthType,
'//      UrlFlags and CESAuthType, followed by the CEPUrl, CEPId, CESUrl and
'//      RequestId strings
'//      The data format is defined as: the first 4 bytes - property version,
'//      next 4 bytes - Property Flags
'//      next 4 bytes - Authentication Type
'//      next 4 bytes - Url Flags
'//      next 4 bytes - CES Authentication Type
'//      followed by Url string with null-terminator,
'//      followed by Id string with null-terminator,
'//      followed by CES Url string with null-terminator,
'//      followed by RequestId string with null-terminator.
'//      a single null-terminator indicates no string is present.
'//
'//  For all the other PROP_IDs: an encoded PCRYPT_DATA_BLOB is passed in pvData.
'//
'//  If the property already exists, then, the old value is deleted and silently
'//  replaced. Setting, pvData to NULL, deletes the property.
'//
'//  CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG can be set to ignore any
'//  provider write errors and always update the cached context's property.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSetCertificateContextProperty LIB "Crypt32.dll" _
    ALIAS "CertSetCertificateContextProperty" ( _
    pCertContext   AS CERT_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    BYVAL dwFlags  AS DWORD, _
    pvData         AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSetCertificateContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertSetCertificateContextProperty" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvData AS ANY _                                ' __in const void *pvData
 ) AS LONG                                              ' BOOL
#ENDIF

'// Set this flag to ignore any store provider write errors and always update
'// the cached context's property
%CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG     = &H80000000???

'// Set this flag to inhibit the persisting of this property
%CERT_SET_PROPERTY_INHIBIT_PERSIST_FLAG          = &H40000000???

'//+-------------------------------------------------------------------------
'//  Get the property for the specified certificate context.
'//
'//  For CERT_KEY_PROV_HANDLE_PROP_ID, pvData points to a HCRYPTPROV.
'//
'//  For CERT_KEY_PROV_INFO_PROP_ID, pvData points to a CRYPT_KEY_PROV_INFO structure.
'//  Elements pointed to by fields in the pvData structure follow the
'//  structure. Therefore, *pcbData may exceed the size of the structure.
'//
'//  For CERT_KEY_CONTEXT_PROP_ID, pvData points to a CERT_KEY_CONTEXT structure.
'//
'//  For CERT_KEY_SPEC_PROP_ID, pvData points to a DWORD containing the KeySpec.
'//  If the CERT_KEY_CONTEXT_PROP_ID exists, the KeySpec is obtained from there.
'//  Otherwise, if the CERT_KEY_PROV_INFO_PROP_ID exists, its the source
'//  of the KeySpec.
'//
'//  For CERT_SHA1_HASH_PROP_ID or CERT_MD5_HASH_PROP_ID, if the hash
'//  doesn't already exist, then, its computed via CryptHashCertificate()
'//  and then set. pvData points to the computed hash. Normally, the length
'//  is 20 bytes for SHA and 16 for MD5.
'//
'//  For CERT_SIGNATURE_HASH_PROP_ID, if the hash
'//  doesn't already exist, then, its computed via CryptHashToBeSigned()
'//  and then set. pvData points to the computed hash. Normally, the length
'//  is 20 bytes for SHA and 16 for MD5.
'//
'//  For CERT_ACCESS_STATE_PROP_ID, pvData points to a DWORD containing the
'//  access state flags. The appropriate CERT_ACCESS_STATE_*_FLAG's are set
'//  in the returned DWORD. See the CERT_ACCESS_STATE_*_FLAG definitions
'//  above. Note, this property is read only. It can't be set.
'//
'//  For CERT_KEY_IDENTIFIER_PROP_ID, if property doesn't already exist,
'//  first searches for the szOID_SUBJECT_KEY_IDENTIFIER extension. Next,
'//  does SHA1 hash of the certficate's SubjectPublicKeyInfo. pvData
'//  points to the key identifier bytes. Normally, the length is 20 bytes.
'//
'//  For CERT_PUBKEY_ALG_PARA_PROP_ID, pvPara points to the ASN.1 encoded
'//  PublicKey Algorithm Parameters. This property will only be set
'//  for public keys supporting algorithm parameter inheritance and when the
'//  parameters have been omitted from the encoded and signed certificate.
'//
'//  For CERT_DATE_STAMP_PROP_ID, pvPara points to a FILETIME updated by
'//  an admin tool to indicate when the certificate was added to the store.
'//
'//  For all other PROP_IDs, pvData points to an encoded array of bytes.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetCertificateContextProperty LIB "Crypt32.dll" _
    ALIAS "CertGetCertificateContextProperty" ( _
    pCertContext   AS CERT_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    pvData         AS ANY, _
    pcbData        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetCertificateContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertGetCertificateContextProperty" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the properties for the specified certificate context.
'//
'//  To get the first property, set dwPropId to 0. The ID of the first
'//  property is returned. To get the next property, set dwPropId to the
'//  ID returned by the last call. To enumerate all the properties continue
'//  until 0 is returned.
'//
'//  CertGetCertificateContextProperty is called to get the property's data.
'//
'//  Note, since, the CERT_KEY_PROV_HANDLE_PROP_ID and CERT_KEY_SPEC_PROP_ID
'//  properties are stored as fields in the CERT_KEY_CONTEXT_PROP_ID
'//  property, they aren't enumerated individually.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCertificateContextProperties LIB "Crypt32.dll" _
    ALIAS "CertEnumCertificateContextProperties" ( _
    pCertContext   AS CERT_CONTEXT, _
    BYVAL dwPropId AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CertEnumCertificateContextProperties IMPORT "CRYPT32.DLL" ALIAS "CertEnumCertificateContextProperties" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 ) AS DWORD                                             ' DWORD
#ENDIF

'//+-------------------------------------------------------------------------
'//  Creates a CTL entry whose attributes are the certificate context's
'//  properties.
'//
'//  The SubjectIdentifier in the CTL entry is the SHA1 hash of the certificate.
'//
'//  The certificate properties are added as attributes. The property attribute
'//  OID is the decimal PROP_ID preceded by szOID_CERT_PROP_ID_PREFIX. Each
'//  property value is copied as a single attribute value.
'//
'//  Any additional attributes to be included in the CTL entry can be passed
'//  in via the cOptAttr and rgOptAttr parameters.
'//
'//  CTL_ENTRY_FROM_PROP_CHAIN_FLAG can be set in dwFlags, to force the
'//  inclusion of the chain building hash properties as attributes.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertCreateCTLEntryFromCertificateContextProperties _
    LIB "Crypt32.dll" _
    ALIAS "CertCreateCTLEntryFromCertificateContextProperties" ( _
    pCertContext   AS CERT_CONTEXT, _
    BYVAL cOptAttr AS DWORD, _
    rgOptAttr      AS CRYPT_ATTRIBUTE, _
    BYVAL dwFlags  AS DWORD, _
    pvReserved     AS ANY, _  ' void *
    pCtlEntry      AS CTL_ENTRY, _
    pcbCtlEntry    AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertCreateCTLEntryFromCertificateContextProperties _
   IMPORT "CRYPT32.DLL" ALIAS "CertCreateCTLEntryFromCertificateContextProperties" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL cOptAttr AS DWORD _                            ' __in DWORD cOptAttr
 , BYREF rgOptAttr AS CRYPT_ATTRIBUTE _                 ' __in_opt PCRYPT_ATTRIBUTE rgOptAttr
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYREF pCtlEntry AS CTL_ENTRY _                       ' __out_opt PCTL_ENTRY pCtlEntry
 , BYREF pcbCtlEntry AS DWORD _                         ' __inout DWORD *pcbCtlEntry
 ) AS LONG                                              ' BOOL
#ENDIF

'// Set this flag to get and include the chain building hash properties
'// as attributes in the CTL entry
%CTL_ENTRY_FROM_PROP_CHAIN_FLAG                  = &H1???


'//+-------------------------------------------------------------------------
'//  Sets properties on the certificate context using the attributes in
'//  the CTL entry.
'//
'//  The property attribute OID is the decimal PROP_ID preceded by
'//  szOID_CERT_PROP_ID_PREFIX. Only attributes containing such an OID are
'//  copied.
'//
'//  CERT_SET_PROPERTY_IGNORE_PERSIST_ERROR_FLAG may be set in dwFlags.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSetCertificateContextPropertiesFromCTLEntry _
    LIB "Crypt32.dll" _
    ALIAS "CertSetCertificateContextPropertiesFromCTLEntry" ( _
    pCertContext  AS CERT_CONTEXT, _
    pCtlEntry     AS CTL_ENTRY, _
    BYVAL dwFlags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSetCertificateContextPropertiesFromCTLEntry _
   IMPORT "CRYPT32.DLL" ALIAS "CertSetCertificateContextPropertiesFromCTLEntry" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYREF pCtlEntry AS CTL_ENTRY _                       ' __out_opt PCTL_ENTRY pCtlEntry
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Get the first or next CRL context from the store for the specified
'//  issuer certificate. Perform the enabled verification checks on the CRL.
'//
'//  If the first or next CRL isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
'//  must be freed by calling CertFreeCRLContext. However, the free must be
'//  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
'//  can be called to make a duplicate.
'//
'//  The pIssuerContext may have been obtained from this store, another store
'//  or created by the caller application. When created by the caller, the
'//  CertCreateCertificateContext function must have been called.
'//
'//  If pIssuerContext == NULL, finds all the CRLs in the store.
'//
'//  An issuer may have multiple CRLs. For example, it generates delta CRLs
'//  using a X.509 v3 extension. pPrevCrlContext MUST BE NULL on the first
'//  call to get the CRL. To get the next CRL for the issuer, the
'//  pPrevCrlContext is set to the CRL_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
'//  this function, even for an error.
'//
'//  The following flags can be set in *pdwFlags to enable verification checks
'//  on the returned CRL:
'//      CERT_STORE_SIGNATURE_FLAG     - use the public key in the
'//                                      issuer's certificate to verify the
'//                                      signature on the returned CRL.
'//                                      Note, if pIssuerContext->hCertStore ==
'//                                      hCertStore, the store provider might
'//                                      be able to eliminate a redo of
'//                                      the signature verify.
'//      CERT_STORE_TIME_VALIDITY_FLAG - get the current time and verify that
'//                                      its within the CRL's ThisUpdate and
'//                                      NextUpdate validity period.
'//      CERT_STORE_BASE_CRL_FLAG      - get base CRL.
'//      CERT_STORE_DELTA_CRL_FLAG     - get delta CRL.
'//
'//  If only one of CERT_STORE_BASE_CRL_FLAG or CERT_STORE_DELTA_CRL_FLAG is
'//  set, then, only returns either a base or delta CRL. In any case, the
'//  appropriate base or delta flag will be cleared upon returned. If both
'//  flags are set, then, only one of flags will be cleared.
'//
'//  If an enabled verification check fails, then, its flag is set upon return.
'//
'//  If pIssuerContext == NULL, then, an enabled CERT_STORE_SIGNATURE_FLAG
'//  always fails and the CERT_STORE_NO_ISSUER_FLAG is also set.
'//
'//  For a verification check failure, a pointer to the first or next
'//  CRL_CONTEXT is still returned and SetLastError isn't updated.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetCRLFromStore LIB "Crypt32.dll" _
    ALIAS "CertGetCRLFromStore" ( _
    BYVAL hCertStore AS DWORD, _  ' HCERTSTORE
    pIssuerContext   AS CERT_CONTEXT, _
    pPrevCrlContext  AS CRL_CONTEXT, _
    pdwFlags         AS DWORD _
    ) AS DWORD  ' CRL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertGetCRLFromStore IMPORT "CRYPT32.DLL" ALIAS "CertGetCRLFromStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pIssuerContext AS CERT_CONTEXT PTR _           ' __in_opt PCCERT_CONTEXT pIssuerContext
 , BYVAL pPrevCrlContext AS CRL_CONTEXT PTR _           ' __in PCCRL_CONTEXT pPrevCrlContext
 , BYREF pdwFlags AS DWORD _                            ' __inout DWORD *pdwFlags
 ) AS DWORD                                             ' PCCRL_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the CRL contexts in the store.
'//
'//  If a CRL isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
'//  must be freed by calling CertFreeCRLContext or is freed when passed as the
'//  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
'//  can be called to make a duplicate.
'//
'//  pPrevCrlContext MUST BE NULL to enumerate the first
'//  CRL in the store. Successive CRLs are enumerated by setting
'//  pPrevCrlContext to the CRL_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCRLsInStore LIB "Crypt32.dll" _
    ALIAS "CertEnumCRLsInStore" ( _
    BYVAL hCertStore AS DWORD, _  ' HCERTSTORE
    pPrevCrlContext  AS CRL_CONTEXT _
    ) AS DWORD  ' CRL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertEnumCRLsInStore IMPORT "CRYPT32.DLL" ALIAS "CertEnumCRLsInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pPrevCrlContext AS CRL_CONTEXT PTR _           ' __in PCCRL_CONTEXT pPrevCrlContext
 ) AS DWORD                                             ' PCCRL_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Find the first or next CRL context in the store.
'//
'//  The CRL is found according to the dwFindType and its pvFindPara.
'//  See below for a list of the find types and its parameters.
'//
'//  Currently dwFindFlags isn't used and must be set to 0.
'//
'//  Usage of dwCertEncodingType depends on the dwFindType.
'//
'//  If the first or next CRL isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CRL_CONTEXT is returned. CRL_CONTEXT
'//  must be freed by calling CertFreeCRLContext or is freed when passed as the
'//  pPrevCrlContext on a subsequent call. CertDuplicateCRLContext
'//  can be called to make a duplicate.
'//
'//  pPrevCrlContext MUST BE NULL on the first
'//  call to find the CRL. To find the next CRL, the
'//  pPrevCrlContext is set to the CRL_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCrlContext is always CertFreeCRLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindCRLInStore LIB "Crypt32.dll" _
    ALIAS "CertFindCRLInStore" ( _
    BYVAL hCertStore         AS DWORD, _  ' HCERTSTORE
    BYVAL dwCertEncodingType AS DWORD, _
    BYVAL dwFindFlags        AS DWORD, _
    BYVAL dwFindType         AS DWORD, _
    pvFindPara               AS ANY, _  ' void *
    pPrevCrlContext          AS CRL_CONTEXT _
    ) AS DWORD  ' CRL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertFindCRLInStore IMPORT "CRYPT32.DLL" ALIAS "CertFindCRLInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwFindFlags AS DWORD _                         ' __in DWORD dwFindFlags
 , BYVAL dwFindType AS DWORD _                          ' __in DWORD dwFindType
 , BYREF pvFindPara AS ANY _                            ' __in const void *pvFindPara
 , BYVAL pPrevCrlContext AS CRL_CONTEXT PTR _           ' __in PCCRL_CONTEXT pPrevCrlContext
 ) AS DWORD                                             ' PCCRL_CONTEXT
#ENDIF

%CRL_FIND_ANY               = 0???
%CRL_FIND_ISSUED_BY         = 1???
%CRL_FIND_EXISTING          = 2???
%CRL_FIND_ISSUED_FOR        = 3???

'//+-------------------------------------------------------------------------
'//  CRL_FIND_ANY
'//
'//  Find any CRL.
'//
'//  pvFindPara isn't used.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CRL_FIND_ISSUED_BY
'//
'//  Find CRL matching the specified issuer.
'//
'//  pvFindPara is the PCCERT_CONTEXT of the CRL issuer. May be NULL to
'//  match any issuer.
'//
'//  By default, only does issuer name matching. The following flags can be
'//  set in dwFindFlags to do additional filtering.
'//
'//  If CRL_FIND_ISSUED_BY_AKI_FLAG is set in dwFindFlags, then, checks if the
'//  CRL has an Authority Key Identifier (AKI) extension. If the CRL has an
'//  AKI, then, only returns a CRL whose AKI matches the issuer.
'//
'//  Note, the AKI extension has the following OID:
'//  szOID_AUTHORITY_KEY_IDENTIFIER2 and its corresponding data structure.
'//
'//  If CRL_FIND_ISSUED_BY_SIGNATURE_FLAG is set in dwFindFlags, then,
'//  uses the public key in the issuer's certificate to verify the
'//  signature on the CRL. Only returns a CRL having a valid signature.
'//
'//  If CRL_FIND_ISSUED_BY_DELTA_FLAG is set in dwFindFlags, then, only
'//  returns a delta CRL.
'//
'//  If CRL_FIND_ISSUED_BY_BASE_FLAG is set in dwFindFlags, then, only
'//  returns a base CRL.
'//--------------------------------------------------------------------------
%CRL_FIND_ISSUED_BY_AKI_FLAG        = &H1???
%CRL_FIND_ISSUED_BY_SIGNATURE_FLAG  = &H2???
%CRL_FIND_ISSUED_BY_DELTA_FLAG      = &H4???
%CRL_FIND_ISSUED_BY_BASE_FLAG       = &H8???

'//+-------------------------------------------------------------------------
'//  CRL_FIND_EXISTING
'//
'//  Find existing CRL in the store.
'//
'//  pvFindPara is the PCCRL_CONTEXT of the CRL to check if it already
'//  exists in the store.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CRL_FIND_ISSUED_FOR
'//
'//  Find CRL for the specified subject and its issuer.
'//
'//  pvFindPara points to the following CRL_FIND_ISSUED_FOR_PARA which contains
'//  both the subject and issuer certificates. Not optional.
'//
'//  The subject's issuer name is used to match the CRL's issuer name. Otherwise,
'//  the issuer's certificate is used the same as in the above
'//  CRL_FIND_ISSUED_BY.
'//
'//  Note, when cross certificates are used, the subject name in the issuer's
'//  certificate may not match the issuer name in the subject certificate and
'//  its corresponding CRL.
'//
'//  All of the above CRL_FIND_ISSUED_BY_*_FLAGS apply to this find type.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CRL_FIND_ISSUED_FOR_PARA DWORD
   pSubjectCert AS CERT_CONTEXT PTR
   pIssuerCert  AS CERT_CONTEXT PTR
END TYPE

'//+-------------------------------------------------------------------------
'//  Duplicate a CRL context
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDuplicateCRLContext LIB "Crypt32.dll" _
    ALIAS "CertDuplicateCRLContext" ( _
    pCrlContext AS CRL_CONTEXT _
    ) AS DWORD  ' CRL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertDuplicateCRLContext IMPORT "CRYPT32.DLL" ALIAS "CertDuplicateCRLContext" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 ) AS DWORD                                             ' PCCRL_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Create a CRL context from the encoded CRL. The created
'//  context isn't put in a store.
'//
'//  Makes a copy of the encoded CRL in the created context.
'//
'//  If unable to decode and create the CRL context, NULL is returned.
'//  Otherwise, a pointer to a read only CRL_CONTEXT is returned.
'//  CRL_CONTEXT must be freed by calling CertFreeCRLContext.
'//  CertDuplicateCRLContext can be called to make a duplicate.
'//
'//  CertSetCRLContextProperty and CertGetCRLContextProperty can be called
'//  to store properties for the CRL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCreateCRLContext IMPORT "CRYPT32.DLL" ALIAS "CertCreateCRLContext" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbCrlEncoded AS BYTE PTR _                     ' __in const BYTE *pbCrlEncoded
 , BYVAL cbCrlEncoded AS DWORD _                        ' __in DWORD cbCrlEncoded
 ) AS DWORD                                             ' PCCRL_CONTEXT

'//+-------------------------------------------------------------------------
'//  Free a CRL context
'//
'//  There needs to be a corresponding free for each context obtained by a
'//  get, duplicate or create.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFreeCRLContext LIB "Crypt32.dll" _
    ALIAS "CertFreeCRLContext" ( _
    pCrlContext AS CRL_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertFreeCRLContext IMPORT "CRYPT32.DLL" ALIAS "CertFreeCRLContext" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Set the property for the specified CRL context.
'//
'//  Same Property Ids and semantics as CertSetCertificateContextProperty.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSetCRLContextProperty LIB "Crypt32.dll" _
    ALIAS "CertSetCRLContextProperty" ( _
    pCrlContext    AS CRL_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    BYVAL dwFlags  AS DWORD, _
    pvData         AS ANY _  ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSetCRLContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertSetCRLContextProperty" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvData AS ANY _                                ' __in const void *pvData
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Get the property for the specified CRL context.
'//
'//  Same Property Ids and semantics as CertGetCertificateContextProperty.
'//
'//  CERT_SHA1_HASH_PROP_ID, CERT_MD5_HASH_PROP_ID or
'//  CERT_SIGNATURE_HASH_PROP_ID is the predefined property of most interest.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetCRLContextProperty LIB "Crypt32.dll" _
    ALIAS "CertGetCRLContextProperty" ( _
    pCrlContext    AS CRL_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    pvData         AS ANY, _   ' void *
    pcbData        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetCRLContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertGetCRLContextProperty" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the properties for the specified CRL context.
'//
'//  To get the first property, set dwPropId to 0. The ID of the first
'//  property is returned. To get the next property, set dwPropId to the
'//  ID returned by the last call. To enumerate all the properties continue
'//  until 0 is returned.
'//
'//  CertGetCRLContextProperty is called to get the property's data.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCRLContextProperties LIB "Crypt32.dll" _
    ALIAS "CertEnumCRLContextProperties" ( _
    pCrlContext    AS CRL_CONTEXT, _
    BYVAL dwPropId AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CertEnumCRLContextProperties IMPORT "CRYPT32.DLL" ALIAS "CertEnumCRLContextProperties" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 ) AS DWORD                                             ' DWORD
#ENDIF

'//+-------------------------------------------------------------------------
'//  Search the CRL's list of entries for the specified certificate.
'//
'//  TRUE is returned if we were able to search the list. Otherwise, FALSE is
'//  returned,
'//
'//  For success, if the certificate was found in the list, *ppCrlEntry is
'//  updated with a pointer to the entry. Otherwise, *ppCrlEntry is set to NULL.
'//  The returned entry isn't allocated and must not be freed.
'//
'//  dwFlags and pvReserved currently aren't used and must be set to 0 or NULL.
'//--------------------------------------------------------------------------
'    );

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindCertificateInCRL LIB "Crypt32.dll" _
    ALIAS "CertFindCertificateInCRL" ( _
    pCert         AS CERT_CONTEXT, _
    pCrlContext   AS CRL_CONTEXT, _
    BYVAL dwFlags AS DWORD, _
    pvReserved    AS ANY, _   ' void *
    ppCrlEntry    AS ANY _    ' PCRL_ENTRY *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertFindCertificateInCRL IMPORT "CRYPT32.DLL" ALIAS "CertFindCertificateInCRL" ( _
   BYVAL pCert AS CERT_CONTEXT PTR _                    ' __in PCCERT_CONTEXT pCert
 , BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYREF ppCrlEntry AS ANY _                            ' __out PCRL_ENTRY *ppCrlEntry
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Is the specified CRL valid for the certificate.
'//
'//  Returns TRUE if the CRL's list of entries would contain the certificate
'//  if it was revoked. Note, doesn't check that the certificate is in the
'//  list of entries.
'//
'//  If the CRL has an Issuing Distribution Point (IDP) extension, checks
'//  that it's valid for the subject certificate.
'//
'//  dwFlags and pvReserved currently aren't used and must be set to 0 and NULL.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertIsValidCRLForCertificate LIB "Crypt32.dll" _
    ALIAS "CertIsValidCRLForCertificate" ( _
    pCert         AS CERT_CONTEXT, _
    pCrl          AS CRL_CONTEXT, _
    BYVAL dwFlags AS DWORD, _
    pvReserved    AS ANY _  ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertIsValidCRLForCertificate IMPORT "CRYPT32.DLL" ALIAS "CertIsValidCRLForCertificate" ( _
   BYVAL pCert AS CERT_CONTEXT PTR _                    ' __in PCCERT_CONTEXT pCert
 , BYVAL pCrl AS CRL_CONTEXT PTR _                      ' __in PCCRL_CONTEXT pCrl
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'// Add certificate/CRL, encoded, context or element disposition values.
'//--------------------------------------------------------------------------
%CERT_STORE_ADD_NEW                                 = 1???
%CERT_STORE_ADD_USE_EXISTING                        = 2???
%CERT_STORE_ADD_REPLACE_EXISTING                    = 3???
%CERT_STORE_ADD_ALWAYS                              = 4???
%CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES = 5???
%CERT_STORE_ADD_NEWER                               = 6???
%CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES            = 7???


'//+-------------------------------------------------------------------------
'//  Add the encoded certificate to the store according to the specified
'//  disposition action.
'//
'//  Makes a copy of the encoded certificate before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the certificate
'//  already exists in the store. This parameter must be one of the following
'//  values:
'//    CERT_STORE_ADD_NEW
'//      Fails if the certificate already exists in the store. LastError
'//      is set to CRYPT_E_EXISTS.
'//    CERT_STORE_ADD_USE_EXISTING
'//      If the certifcate already exists, then, its used and if ppCertContext
'//      is non-NULL, the existing context is duplicated.
'//    CERT_STORE_ADD_REPLACE_EXISTING
'//      If the certificate already exists, then, the existing certificate
'//      context is deleted before creating and adding the new context.
'//    CERT_STORE_ADD_ALWAYS
'//      No check is made to see if the certificate already exists. A
'//      new certificate context is always created. This may lead to
'//      duplicates in the store.
'//    CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES
'//      If the certificate already exists, then, its used.
'//    CERT_STORE_ADD_NEWER
'//      Fails if the certificate already exists in the store AND the NotBefore
'//      time of the existing certificate is equal to or greater than the
'//      NotBefore time of the new certificate being added. LastError
'//      is set to CRYPT_E_EXISTS.
'//
'//      If an older certificate is replaced, same as
'//      CERT_STORE_ADD_REPLACE_EXISTING.
'//
'//      For CRLs or CTLs compares the ThisUpdate times.
'//
'//    CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES
'//      Same as CERT_STORE_ADD_NEWER. However, if an older certificate is
'//      replaced, same as CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES.
'//
'//  CertGetSubjectCertificateFromStore is called to determine if the
'//  certificate already exists in the store.
'//
'//  ppCertContext can be NULL, indicating the caller isn't interested
'//  in getting the CERT_CONTEXT of the added or existing certificate.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertAddEncodedCertificateToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddEncodedCertificateToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbCertEncoded AS BYTE PTR _                    ' __in const BYTE *pbCertEncoded
 , BYVAL cbCertEncoded AS DWORD _                       ' __in DWORD cbCertEncoded
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppCertContext AS ANY _                ' __out_opt PCCERT_CONTEXT *ppCertContext
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Add the certificate context to the store according to the specified
'//  disposition action.
'//
'//  In addition to the encoded certificate, the context's properties are
'//  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
'//  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
'//
'//  Makes a copy of the certificate context before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the certificate
'//  already exists in the store. This parameter must be one of the following
'//  values:
'//    CERT_STORE_ADD_NEW
'//      Fails if the certificate already exists in the store. LastError
'//      is set to CRYPT_E_EXISTS.
'//    CERT_STORE_ADD_USE_EXISTING
'//      If the certifcate already exists, then, its used and if ppStoreContext
'//      is non-NULL, the existing context is duplicated. Iterates
'//      through pCertContext's properties and only copies the properties
'//      that don't already exist. The SHA1 and MD5 hash properties aren't
'//      copied.
'//    CERT_STORE_ADD_REPLACE_EXISTING
'//      If the certificate already exists, then, the existing certificate
'//      context is deleted before creating and adding a new context.
'//      Properties are copied before doing the add.
'//    CERT_STORE_ADD_ALWAYS
'//      No check is made to see if the certificate already exists. A
'//      new certificate context is always created and added. This may lead to
'//      duplicates in the store. Properties are
'//      copied before doing the add.
'//    CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES
'//      If the certificate already exists, then, the existing certificate
'//      context is used. Properties from the added context are copied and
'//      replace existing properties. However, any existing properties not
'//      in the added context remain and aren't deleted.
'//    CERT_STORE_ADD_NEWER
'//      Fails if the certificate already exists in the store AND the NotBefore
'//      time of the existing context is equal to or greater than the
'//      NotBefore time of the new context being added. LastError
'//      is set to CRYPT_E_EXISTS.
'//
'//      If an older context is replaced, same as
'//      CERT_STORE_ADD_REPLACE_EXISTING.
'//
'//      For CRLs or CTLs compares the ThisUpdate times.
'//
'//    CERT_STORE_ADD_NEWER_INHERIT_PROPERTIES
'//      Same as CERT_STORE_ADD_NEWER. However, if an older context is
'//      replaced, same as CERT_STORE_ADD_REPLACE_EXISTING_INHERIT_PROPERTIES.
'//
'//  CertGetSubjectCertificateFromStore is called to determine if the
'//  certificate already exists in the store.
'//
'//  ppStoreContext can be NULL, indicating the caller isn't interested
'//  in getting the CERT_CONTEXT of the added or existing certificate.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCertificateContextToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCertificateContextToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCertContext           AS CERT_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCertificateContextToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCertificateContextToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCERT_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate Store Context Types
'//--------------------------------------------------------------------------
%CERT_STORE_CERTIFICATE_CONTEXT = 1???
%CERT_STORE_CRL_CONTEXT         = 2???
%CERT_STORE_CTL_CONTEXT         = 3???

'//+-------------------------------------------------------------------------
'//  Certificate Store Context Bit Flags
'//--------------------------------------------------------------------------
'#define CERT_STORE_ALL_CONTEXT_FLAG             (~0UL)
'#define CERT_STORE_CERTIFICATE_CONTEXT_FLAG     \
'                (1 << CERT_STORE_CERTIFICATE_CONTEXT)
'#define CERT_STORE_CRL_CONTEXT_FLAG             \
'                (1 << CERT_STORE_CRL_CONTEXT)
'#define CERT_STORE_CTL_CONTEXT_FLAG             \
'                (1 << CERT_STORE_CTL_CONTEXT)

%CERT_STORE_ALL_CONTEXT_FLAG         = &HFFFFFFFF???
%CERT_STORE_CERTIFICATE_CONTEXT_FLAG = &H2???
%CERT_STORE_CRL_CONTEXT_FLAG         = &H4???
%CERT_STORE_CTL_CONTEXT_FLAG         = &H8???

'//+-------------------------------------------------------------------------
'//  Add the serialized certificate or CRL element to the store.
'//
'//  The serialized element contains the encoded certificate, CRL or CTL and
'//  its properties, such as, CERT_KEY_PROV_INFO_PROP_ID.
'//
'//  If hCertStore is NULL, creates a certificate, CRL or CTL context not
'//  residing in any store.
'//
'//  dwAddDispostion specifies the action to take if the certificate or CRL
'//  already exists in the store. See CertAddCertificateContextToStore for a
'//  list of and actions taken.
'//
'//  dwFlags currently isn't used and should be set to 0.
'//
'//  dwContextTypeFlags specifies the set of allowable contexts. For example, to
'//  add either a certificate or CRL, set dwContextTypeFlags to:
'//      CERT_STORE_CERTIFICATE_CONTEXT_FLAG | CERT_STORE_CRL_CONTEXT_FLAG
'//
'//  *pdwContextType is updated with the type of the context returned in
'//  *ppvContxt. pdwContextType or ppvContext can be NULL, indicating the
'//  caller isn't interested in getting the output. If *ppvContext is
'//  returned it must be freed by calling CertFreeCertificateContext or
'//  CertFreeCRLContext.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertAddSerializedElementToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddSerializedElementToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pbElement AS BYTE PTR _                        ' __in const BYTE *pbElement
 , BYVAL cbElement AS DWORD _                           ' __in DWORD cbElement
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwContextTypeFlags AS DWORD _                  ' __in DWORD dwContextTypeFlags
 , OPTIONAL BYREF pdwContextType AS DWORD _             ' __out_opt DWORD *pdwContextType
 , OPTIONAL BYREF ppvContext AS ANY _                   ' __out_opt const void **ppvContext
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Delete the specified certificate from the store.
'//
'//  All subsequent gets or finds for the certificate will fail. However,
'//  memory allocated for the certificate isn't freed until all of its contexts
'//  have also been freed.
'//
'//  The pCertContext is obtained from a get, enum, find or duplicate.
'//
'//  Some store provider implementations might also delete the issuer's CRLs
'//  if this is the last certificate for the issuer in the store.
'//
'//  NOTE: the pCertContext is always CertFreeCertificateContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDeleteCertificateFromStore LIB "Crypt32.dll" _
    ALIAS "CertDeleteCertificateFromStore" ( _
    pCertContext AS CERT_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertDeleteCertificateFromStore IMPORT "CRYPT32.DLL" ALIAS "CertDeleteCertificateFromStore" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Add the encoded CRL to the store according to the specified
'//  disposition option.
'//
'//  Makes a copy of the encoded CRL before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the CRL
'//  already exists in the store. See CertAddEncodedCertificateToStore for a
'//  list of and actions taken.
'//
'//  Compares the CRL's Issuer to determine if the CRL already exists in the
'//  store.
'//
'//  ppCrlContext can be NULL, indicating the caller isn't interested
'//  in getting the CRL_CONTEXT of the added or existing CRL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertAddEncodedCRLToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddEncodedCRLToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbCrlEncoded AS BYTE PTR _                     ' __in const BYTE *pbCrlEncoded
 , BYVAL cbCrlEncoded AS DWORD _                        ' __in DWORD cbCrlEncoded
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppCrlContext AS ANY _                 ' __out_opt PCCRL_CONTEXT *ppCrlContext
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Add the CRL context to the store according to the specified
'//  disposition option.
'//
'//  In addition to the encoded CRL, the context's properties are
'//  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
'//  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
'//
'//  Makes a copy of the encoded CRL before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the CRL
'//  already exists in the store. See CertAddCertificateContextToStore for a
'//  list of and actions taken.
'//
'//  Compares the CRL's Issuer, ThisUpdate and NextUpdate to determine
'//  if the CRL already exists in the store.
'//
'//  ppStoreContext can be NULL, indicating the caller isn't interested
'//  in getting the CRL_CONTEXT of the added or existing CRL.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCRLContextToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCRLContextToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCrlContext            AS CRL_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CRL_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCRLContextToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCRLContextToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCRL_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Delete the specified CRL from the store.
'//
'//  All subsequent gets for the CRL will fail. However,
'//  memory allocated for the CRL isn't freed until all of its contexts
'//  have also been freed.
'//
'//  The pCrlContext is obtained from a get or duplicate.
'//
'//  NOTE: the pCrlContext is always CertFreeCRLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDeleteCRLFromStore LIB "Crypt32.dll" _
    ALIAS "CertDeleteCRLFromStore" ( _
    pCrlContext AS CRL_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertDeleteCRLFromStore IMPORT "CRYPT32.DLL" ALIAS "CertDeleteCRLFromStore" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Serialize the certificate context's encoded certificate and its
'//  properties.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSerializeCertificateStoreElement LIB "Crypt32.dll" _
    ALIAS "CertSerializeCertificateStoreElement" ( _
    pCertContext    AS CERT_CONTEXT, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL pbElement AS BYTE PTR, _
    pcbElement      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSerializeCertificateStoreElement IMPORT "CRYPT32.DLL" ALIAS "CertSerializeCertificateStoreElement" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbElement AS BYTE PTR _                        ' __out BYTE *pbElement
 , BYREF pcbElement AS DWORD _                          ' __inout DWORD *pcbElement
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Serialize the CRL context's encoded CRL and its properties.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSerializeCRLStoreElement LIB "Crypt32.dll" _
    ALIAS "CertSerializeCRLStoreElement" ( _
    pCrlContext     AS CRL_CONTEXT, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL pbElement AS BYTE PTR, _
    pcbElement      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSerializeCRLStoreElement IMPORT "CRYPT32.DLL" ALIAS "CertSerializeCRLStoreElement" ( _
   BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbElement AS BYTE PTR _                        ' __out BYTE *pbElement
 , BYREF pcbElement AS DWORD _                          ' __inout DWORD *pcbElement
 ) AS LONG                                              ' BOOL
#ENDIF

'//+=========================================================================
'//  Certificate Trust List (CTL) Store Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Duplicate a CTL context
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDuplicateCTLContext LIB "Crypt32.dll" _
    ALIAS "CertDuplicateCTLContext" ( _
    pCtlContext AS CTL_CONTEXT _
    ) AS DWORD  ' CTL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertDuplicateCTLContext IMPORT "CRYPT32.DLL" ALIAS "CertDuplicateCTLContext" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 ) AS DWORD                                             ' PCCTL_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Create a CTL context from the encoded CTL. The created
'//  context isn't put in a store.
'//
'//  Makes a copy of the encoded CTL in the created context.
'//
'//  If unable to decode and create the CTL context, NULL is returned.
'//  Otherwise, a pointer to a read only CTL_CONTEXT is returned.
'//  CTL_CONTEXT must be freed by calling CertFreeCTLContext.
'//  CertDuplicateCTLContext can be called to make a duplicate.
'//
'//  CertSetCTLContextProperty and CertGetCTLContextProperty can be called
'//  to store properties for the CTL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCreateCTLContext IMPORT "CRYPT32.DLL" ALIAS "CertCreateCTLContext" ( _
   BYVAL dwMsgAndCertEncodingType AS DWORD _            ' __in DWORD dwMsgAndCertEncodingType
 , BYVAL pbCtlEncoded AS BYTE PTR _                     ' __in const BYTE *pbCtlEncoded
 , BYVAL cbCtlEncoded AS DWORD _                        ' __in DWORD cbCtlEncoded
 ) AS DWORD                                             ' PCCTL_CONTEXT

'//+-------------------------------------------------------------------------
'//  Free a CTL context
'//
'//  There needs to be a corresponding free for each context obtained by a
'//  get, duplicate or create.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFreeCTLContext LIB "Crypt32.dll" _
    ALIAS "CertFreeCTLContext" ( _
    pCtlContext AS CTL_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertFreeCTLContext IMPORT "CRYPT32.DLL" ALIAS "CertFreeCTLContext" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Set the property for the specified CTL context.
'//
'//  Same Property Ids and semantics as CertSetCertificateContextProperty.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSetCTLContextProperty LIB "Crypt32.dll" _
    ALIAS "CertSetCTLContextProperty" ( _
    pCtlContext    AS CTL_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    BYVAL dwFlags  AS DWORD, _
    pvData         AS ANY _  ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSetCTLContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertSetCTLContextProperty" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvData AS ANY _                                ' __in const void *pvData
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Get the property for the specified CTL context.
'//
'//  Same Property Ids and semantics as CertGetCertificateContextProperty.
'//
'//  CERT_SHA1_HASH_PROP_ID or CERT_NEXT_UPDATE_LOCATION_PROP_ID are the
'//  predefined properties of most interest.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetCTLContextProperty LIB "Crypt32.dll" _
    ALIAS "CertGetCTLContextProperty" ( _
    pCtlContext    AS CTL_CONTEXT, _
    BYVAL dwPropId AS DWORD, _
    pvData         AS ANY, _  ' void *
    pcbData        AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetCTLContextProperty IMPORT "CRYPT32.DLL" ALIAS "CertGetCTLContextProperty" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the properties for the specified CTL context.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCTLContextProperties LIB "Crypt32.dll" _
    ALIAS "CertEnumCTLContextProperties" ( _
    pCtlContext    AS CTL_CONTEXT, _
    BYVAL dwPropId AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CertEnumCTLContextProperties IMPORT "CRYPT32.DLL" ALIAS "CertEnumCTLContextProperties" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 ) AS DWORD                                             ' DWORD
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the CTL contexts in the store.
'//
'//  If a CTL isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CTL_CONTEXT is returned. CTL_CONTEXT
'//  must be freed by calling CertFreeCTLContext or is freed when passed as the
'//  pPrevCtlContext on a subsequent call. CertDuplicateCTLContext
'//  can be called to make a duplicate.
'//
'//  pPrevCtlContext MUST BE NULL to enumerate the first
'//  CTL in the store. Successive CTLs are enumerated by setting
'//  pPrevCtlContext to the CTL_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCtlContext is always CertFreeCTLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumCTLsInStore LIB "Crypt32.dll" _
    ALIAS "CertEnumCTLsInStore" ( _
    BYVAL hCertStore AS DWORD, _  ' HCERTSTORE
    pPrevCtlContext  AS CTL_CONTEXT _
    ) AS DWORD  ' CTL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertEnumCTLsInStore IMPORT "CRYPT32.DLL" ALIAS "CertEnumCTLsInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore,
 , BYVAL pPrevCtlContext AS CTL_CONTEXT PTR _           ' __in PCCTL_CONTEXT pPrevCtlContext
 ) AS DWORD                                             ' PCCTL_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  Attempt to find the specified subject in the CTL.
'//
'//  For CTL_CERT_SUBJECT_TYPE, pvSubject points to a CERT_CONTEXT. The CTL's
'//  SubjectAlgorithm is examined to determine the representation of the
'//  subject's identity. Initially, only SHA1 or MD5 hash will be supported.
'//  The appropriate hash property is obtained from the CERT_CONTEXT.
'//
'//  For CTL_ANY_SUBJECT_TYPE, pvSubject points to the CTL_ANY_SUBJECT_INFO
'//  structure which contains the SubjectAlgorithm to be matched in the CTL
'//  and the SubjectIdentifer to be matched in one of the CTL entries.
'//
'//  The certificate's hash or the CTL_ANY_SUBJECT_INFO's SubjectIdentifier
'//  is used as the key in searching the subject entries. A binary
'//  memory comparison is done between the key and the entry's SubjectIdentifer.
'//
'//  dwEncodingType isn't used for either of the above SubjectTypes.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindSubjectInCTL LIB "Crypt32.dll" _
    ALIAS "CertFindSubjectInCTL" ( _
    BYVAL dwEncodingType AS DWORD, _
    BYVAL dwSubjectType  AS DWORD, _
    pvSubject            AS ANY, _  ' void *
    pCtlContext          AS CTL_CONTEXT, _
    BYVAL dwFlags        AS DWORD _
    ) AS DWORD  ' CTL_ENTRY PTR
#ELSE
DECLARE FUNCTION CertFindSubjectInCTL IMPORT "CRYPT32.DLL" ALIAS "CertFindSubjectInCTL" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL dwSubjectType AS DWORD _                       ' __in DWORD dwSubjectType
 , BYREF pvSubject AS ANY _                             ' __in void *pvSubject
 , BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' PCTL_ENTRY
#ENDIF

'// Subject Types:
'//  CTL_ANY_SUBJECT_TYPE, pvSubject points to following CTL_ANY_SUBJECT_INFO.
'//  CTL_CERT_SUBJECT_TYPE, pvSubject points to CERT_CONTEXT.
%CTL_ANY_SUBJECT_TYPE           = 1???
%CTL_CERT_SUBJECT_TYPE          = 2???

' // Size = 20 bytes
TYPE CTL_ANY_SUBJECT_INFO DWORD
   SubjectAlgorithm  AS CRYPT_ALGORITHM_IDENTIFIER
   SubjectIdentifier AS CRYPT_DATA_BLOB
END TYPE

'//+-------------------------------------------------------------------------
'//  Find the first or next CTL context in the store.
'//
'//  The CTL is found according to the dwFindType and its pvFindPara.
'//  See below for a list of the find types and its parameters.
'//
'//  Currently dwFindFlags isn't used and must be set to 0.
'//
'//  Usage of dwMsgAndCertEncodingType depends on the dwFindType.
'//
'//  If the first or next CTL isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CTL_CONTEXT is returned. CTL_CONTEXT
'//  must be freed by calling CertFreeCTLContext or is freed when passed as the
'//  pPrevCtlContext on a subsequent call. CertDuplicateCTLContext
'//  can be called to make a duplicate.
'//
'//  pPrevCtlContext MUST BE NULL on the first
'//  call to find the CTL. To find the next CTL, the
'//  pPrevCtlContext is set to the CTL_CONTEXT returned by a previous call.
'//
'//  NOTE: a NON-NULL pPrevCtlContext is always CertFreeCTLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindCTLInStore LIB "Crypt32.dll" _
    ALIAS "CertFindCTLInStore" ( _
    BYVAL hCertStore               AS DWORD, _  ' HCERTSTORE
    BYVAL dwMsgAndCertEncodingType AS DWORD, _
    BYVAL dwFindFlags              AS DWORD, _
    BYVAL dwFindType               AS DWORD, _
    pvFindPara                     AS ANY, _
    pPrevCtlContext                AS CTL_CONTEXT _
    ) AS DWORD  ' CTL_CONTEXT PTR
#ELSE
DECLARE FUNCTION CertFindCTLInStore IMPORT "CRYPT32.DLL" ALIAS "CertFindCTLInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwMsgAndCertEncodingType AS DWORD _            ' __in DWORD dwMsgAndCertEncodingType
 , BYVAL dwFindFlags AS DWORD _                         ' __in DWORD dwFindFlags
 , BYVAL dwFindType AS DWORD _                          ' __in DWORD dwFindType
 , BYREF pvFindPara AS ANY _                            ' __in const void *pvFindPara
 , BYVAL pPrevCtlContext AS CTL_CONTEXT PTR _           ' __in PCCTL_CONTEXT pPrevCtlContext
 ) AS DWORD                                             ' PCCTL_CONTEXT
#ENDIF

%CTL_FIND_ANY               = 0???
%CTL_FIND_SHA1_HASH         = 1???
%CTL_FIND_MD5_HASH          = 2???
%CTL_FIND_USAGE             = 3???
%CTL_FIND_SUBJECT           = 4???
%CTL_FIND_EXISTING          = 5???

' // Size = 24 bytes
TYPE CTL_FIND_USAGE_PARA DWORD
   cbSize         AS DWORD
   SubjectUsage   AS CTL_USAGE
   ListIdentifier AS CRYPT_DATA_BLOB
   pSigner        AS CERT_INFO PTR
END TYPE

'#define CTL_FIND_NO_LIST_ID_CBDATA  0xFFFFFFFF
'#define CTL_FIND_NO_SIGNER_PTR      ((PCERT_INFO) -1)

%CTL_FIND_NO_LIST_ID_CBDATA  = &HFFFFFFFF???
%CTL_FIND_NO_SIGNER_PTR      = &HFFFFFFFF???

%CTL_FIND_SAME_USAGE_FLAG    = &H1???

' // Size = 16 bytes
TYPE CTL_FIND_SUBJECT_PARA DWORD
   cbSize        AS DWORD                     ' DWORD
   pUsagePara    AS CTL_FIND_USAGE_PARA PTR   ' PCTL_FIND_USAGE_PARA
   dwSubjectType AS DWORD                     ' DWORD
   pvSubject     AS DWORD                     ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  CTL_FIND_ANY
'//
'//  Find any CTL.
'//
'//  pvFindPara isn't used.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CTL_FIND_SHA1_HASH
'//  CTL_FIND_MD5_HASH
'//
'//  Find a CTL with the specified hash.
'//
'//  pvFindPara points to a CRYPT_HASH_BLOB.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CTL_FIND_USAGE
'//
'//  Find a CTL having the specified usage identifiers, list identifier or
'//  signer. The CertEncodingType of the signer is obtained from the
'//  dwMsgAndCertEncodingType parameter.
'//
'//  pvFindPara points to a CTL_FIND_USAGE_PARA data structure. The
'//  SubjectUsage.cUsageIdentifer can be 0 to match any usage. The
'//  ListIdentifier.cbData can be 0 to match any list identifier. To only match
'//  CTLs without a ListIdentifier, cbData must be set to
'//  CTL_FIND_NO_LIST_ID_CBDATA. pSigner can be NULL to match any signer. Only
'//  the Issuer and SerialNumber fields of the pSigner's PCERT_INFO are used.
'//  To only match CTLs without a signer, pSigner must be set to
'//  CTL_FIND_NO_SIGNER_PTR.
'//
'//  The CTL_FIND_SAME_USAGE_FLAG can be set in dwFindFlags to
'//  only match CTLs with the same usage identifiers. CTLs having additional
'//  usage identifiers aren't matched. For example, if only "1.2.3" is specified
'//  in CTL_FIND_USAGE_PARA, then, for a match, the CTL must only contain
'//  "1.2.3" and not any additional usage identifers.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CTL_FIND_SUBJECT
'//
'//  Find a CTL having the specified subject. CertFindSubjectInCTL can be
'//  called to get a pointer to the subject's entry in the CTL.  pUsagePara can
'//  optionally be set to enable the above CTL_FIND_USAGE matching.
'//
'//  pvFindPara points to a CTL_FIND_SUBJECT_PARA data structure.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Add the encoded CTL to the store according to the specified
'//  disposition option.
'//
'//  Makes a copy of the encoded CTL before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the CTL
'//  already exists in the store. See CertAddEncodedCertificateToStore for a
'//  list of and actions taken.
'//
'//  Compares the CTL's SubjectUsage, ListIdentifier and any of its signers
'//  to determine if the CTL already exists in the store.
'//
'//  ppCtlContext can be NULL, indicating the caller isn't interested
'//  in getting the CTL_CONTEXT of the added or existing CTL.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddEncodedCTLToStore LIB "Crypt32.dll" _
    ALIAS "CertAddEncodedCTLToStore" ( _
    BYVAL hCertStore               AS DWORD, _  ' HCERTSTORE
    BYVAL dwMsgAndCertEncodingType AS DWORD, _
    BYVAL pbCtlEncoded             AS BYTE PTR, _
    BYVAL cbCtlEncoded             AS DWORD, _
    BYVAL dwAddDisposition         AS DWORD, _
    ppCtlContext                   AS ANY _  ' PCCTL_CONTEXT *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddEncodedCTLToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddEncodedCTLToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwMsgAndCertEncodingType AS DWORD _            ' __in DWORD dwMsgAndCertEncodingType
 , BYVAL pbCtlEncoded AS BYTE PTR _                     ' __in const BYTE *pbCtlEncoded
 , BYVAL cbCtlEncoded AS DWORD _                        ' __in DWORD cbCtlEncoded
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppCtlContext AS ANY _                 ' __out_opt PCCTL_CONTEXT *ppCtlContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Add the CTL context to the store according to the specified
'//  disposition option.
'//
'//  In addition to the encoded CTL, the context's properties are
'//  also copied.  Note, the CERT_KEY_CONTEXT_PROP_ID property (and its
'//  CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_SPEC_PROP_ID) isn't copied.
'//
'//  Makes a copy of the encoded CTL before adding to the store.
'//
'//  dwAddDispostion specifies the action to take if the CTL
'//  already exists in the store. See CertAddCertificateContextToStore for a
'//  list of and actions taken.
'//
'//  Compares the CTL's SubjectUsage, ListIdentifier and any of its signers
'//  to determine if the CTL already exists in the store.
'//
'//  ppStoreContext can be NULL, indicating the caller isn't interested
'//  in getting the CTL_CONTEXT of the added or existing CTL.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCTLContextToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCTLContextToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCtlContext            AS CTL_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CTL_CONTEXT **
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCTLContextToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCTLContextToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCTL_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Serialize the CTL context's encoded CTL and its properties.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSerializeCTLStoreElement LIB "Crypt32.dll" _
    ALIAS "CertSerializeCTLStoreElement" ( _
    pCtlContext     AS CTL_CONTEXT, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL pbElement AS BYTE PTR, _
    pcbElement      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSerializeCTLStoreElement IMPORT "CRYPT32.DLL" ALIAS "CertSerializeCTLStoreElement" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbElement AS BYTE PTR _                        ' __out BYTE *pbElement
 , BYREF pcbElement AS DWORD _                          ' __inout DWORD *pcbElement
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Delete the specified CTL from the store.
'//
'//  All subsequent gets for the CTL will fail. However,
'//  memory allocated for the CTL isn't freed until all of its contexts
'//  have also been freed.
'//
'//  The pCtlContext is obtained from a get or duplicate.
'//
'//  NOTE: the pCtlContext is always CertFreeCTLContext'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertDeleteCTLFromStore LIB "Crypt32.dll" _
    ALIAS "CertDeleteCTLFromStore" ( _
    pCtlContext AS CTL_CONTEXT _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertDeleteCTLFromStore IMPORT "CRYPT32.DLL" ALIAS "CertDeleteCTLFromStore" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCertificateLinkToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCertificateLinkToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCertContext           AS CERT_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCertificateLinkToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCertificateLinkToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCERT_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCRLLinkToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCRLLinkToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCrlContext            AS CRL_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CRL_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCRLLinkToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCRLLinkToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCrlContext AS CRL_CONTEXT PTR _               ' __in PCCRL_CONTEXT pCrlContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCRL_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddCTLLinkToStore LIB "Crypt32.dll" _
    ALIAS "CertAddCTLLinkToStore" ( _
    BYVAL hCertStore       AS DWORD, _  ' HCERTSTORE
    pCtlContext            AS CTL_CONTEXT, _
    BYVAL dwAddDisposition AS DWORD, _
    ppStoreContext         AS ANY _  ' CTL_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddCTLLinkToStore IMPORT "CRYPT32.DLL" ALIAS "CertAddCTLLinkToStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwAddDisposition AS DWORD _                    ' __in DWORD dwAddDisposition
 , OPTIONAL BYREF ppStoreContext AS ANY _               ' __out_opt PCCTL_CONTEXT *ppStoreContext
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CertAddStoreToCollection IMPORT "CRYPT32.DLL" ALIAS "CertAddStoreToCollection" ( _
   BYVAL hCollectionStore AS DWORD _                    ' __in HCERTSTORE hCollectionStore
 , BYVAL hSiblingStore AS DWORD _                       ' __in_opt HCERTSTORE hSiblingStore
 , BYVAL dwUpdateFlags AS DWORD _                       ' __in DWORD dwUpdateFlags
 , BYVAL dwPriority AS DWORD _                          ' __in DWORD dwPriority
 ) AS LONG                                              ' BOOL

DECLARE SUB CertRemoveStoreFromCollection IMPORT "CRYPT32.DLL" ALIAS "CertRemoveStoreFromCollection" ( _
   BYVAL hCollectionStore AS DWORD _                    ' __in HCERTSTORE hCollectionStore
 , BYVAL hSiblingStore AS DWORD _                       ' __in HCERTSTORE hSiblingStore
 )                                                      ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertControlStore LIB "Crypt32.dll" _
    ALIAS "CertControlStore" ( _
    BYVAL hCertStore AS DWORD, _  ' HCERTSTORE
    BYVAL dwFlags    AS DWORD, _
    BYVAL dwCtrlType AS DWORD, _
    pvCtrlPara       AS ANY _     ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertControlStore IMPORT "CRYPT32.DLL" ALIAS "CertControlStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwCtrlType AS DWORD _                          ' __in DWORD dwCtrlType
 , BYVAL pvCtrlPara AS DWORD _                          ' __in void const *pvCtrlPara
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate Store control types
'//--------------------------------------------------------------------------
%CERT_STORE_CTRL_RESYNC             = 1???
%CERT_STORE_CTRL_NOTIFY_CHANGE      = 2???
%CERT_STORE_CTRL_COMMIT             = 3???
%CERT_STORE_CTRL_AUTO_RESYNC        = 4???
%CERT_STORE_CTRL_CANCEL_NOTIFY      = 5???

%CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG = &H1???

'//+-------------------------------------------------------------------------
'//  CERT_STORE_CTRL_RESYNC
'//
'//  Re-synchronize the store.
'//
'//  The pvCtrlPara points to the event HANDLE to be signaled on
'//  the next store change. Normally, this would be the same
'//  event HANDLE passed to CERT_STORE_CTRL_NOTIFY_CHANGE during initialization.
'//
'//  If pvCtrlPara is NULL, no events are re-armed.
'//
'//  By default the event HANDLE is DuplicateHandle'd.
'//  CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG can be set in dwFlags
'//  to inhibit a DupicateHandle of the event HANDLE. If this flag
'//  is set, then, CertControlStore(CERT_STORE_CTRL_CANCEL_NOTIFY) must be
'//  called for this event HANDLE before closing the hCertStore.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_STORE_CTRL_NOTIFY_CHANGE
'//
'//  Signal the event when the underlying store is changed.
'//
'//  pvCtrlPara points to the event HANDLE to be signaled.
'//
'//  pvCtrlPara can be NULL to inform the store of a subsequent
'//  CERT_STORE_CTRL_RESYNC and allow it to optimize by only doing a resync
'//  if the store has changed. For the registry based stores, an internal
'//  notify change event is created and registered to be signaled.
'//
'//  Recommend calling CERT_STORE_CTRL_NOTIFY_CHANGE once for each event to
'//  be passed to CERT_STORE_CTRL_RESYNC. This should only happen after
'//  the event has been created. Not after each time the event is signaled.
'//
'//  By default the event HANDLE is DuplicateHandle'd.
'//  CERT_STORE_CTRL_INHIBIT_DUPLICATE_HANDLE_FLAG can be set in dwFlags
'//  to inhibit a DupicateHandle of the event HANDLE. If this flag
'//  is set, then, CertControlStore(CERT_STORE_CTRL_CANCEL_NOTIFY) must be
'//  called for this event HANDLE before closing the hCertStore.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_STORE_CTRL_CANCEL_NOTIFY
'//
'//  Cancel notification signaling of the event HANDLE passed in a previous
'//  CERT_STORE_CTRL_NOTIFY_CHANGE or CERT_STORE_CTRL_RESYNC.
'//
'//  pvCtrlPara points to the event HANDLE to be canceled.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_STORE_CTRL_AUTO_RESYNC
'//
'//  At the start of every enumeration or find store API call, check if the
'//  underlying store has changed. If it has changed, re-synchronize.
'//
'//  This check is only done in the enumeration or find APIs when the
'//  pPrevContext is NULL.
'//
'//  The pvCtrlPara isn't used and must be set to NULL.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_STORE_CTRL_COMMIT
'//
'//  If any changes have been to the cached store, they are committed to
'//  persisted storage. If no changes have been made since the store was
'//  opened or the last commit, this call is ignored. May also be ignored by
'//  store providers that persist changes immediately.
'//
'//  CERT_STORE_CTRL_COMMIT_FORCE_FLAG can be set to force the store
'//  to be committed even if it hasn't been touched.
'//
'//  CERT_STORE_CTRL_COMMIT_CLEAR_FLAG can be set to inhibit a commit on
'//  store close.
'//--------------------------------------------------------------------------

%CERT_STORE_CTRL_COMMIT_FORCE_FLAG = &H1???
%CERT_STORE_CTRL_COMMIT_CLEAR_FLAG = &H2???


'//+=========================================================================
'//  Cert Store Property Defines and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Store property IDs. This is a property applicable to the entire store.
'//  Its not a property on an individual certificate, CRL or CTL context.
'//
'//  Currently, no store properties are persisted. (This differs from
'//  most context properties which are persisted.)
'//
'//  See CertSetStoreProperty or CertGetStoreProperty for usage information.
'//
'//  Note, the range for predefined store properties should be outside
'//  the range of predefined context properties. We will start at 4096.
'//--------------------------------------------------------------------------
%CERT_STORE_LOCALIZED_NAME_PROP_ID = &H1000???

'//+-------------------------------------------------------------------------
'//  Set a store property.
'//
'//  The type definition for pvData depends on the dwPropId value.
'//      CERT_STORE_LOCALIZED_NAME_PROP_ID - localized name of the store.
'//      pvData points to a CRYPT_DATA_BLOB. pbData is a pointer to a NULL
'//      terminated unicode, wide character string.
'//      cbData = (wcslen((LPWSTR) pbData) + 1) * sizeof(WCHAR).
'//
'//  For all the other PROP_IDs: an encoded PCRYPT_DATA_BLOB is passed in pvData.
'//
'//  If the property already exists, then, the old value is deleted and silently
'//  replaced. Setting, pvData to NULL, deletes the property.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertSetStoreProperty IMPORT "CRYPT32.DLL" ALIAS "CertSetStoreProperty" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvData AS ANY _                                ' __in const void *pvData
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get a store property.
'//
'//  The type definition for pvData depends on the dwPropId value.
'//      CERT_STORE_LOCALIZED_NAME_PROP_ID - localized name of the store.
'//      pvData points to a NULL terminated unicode, wide character string.
'//      cbData = (wcslen((LPWSTR) pvData) + 1) * sizeof(WCHAR).
'//
'//  For all other PROP_IDs, pvData points to an array of bytes.
'//
'//  If the property doesn't exist, returns FALSE and sets LastError to
'//  CRYPT_E_NOT_FOUND.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertGetStoreProperty IMPORT "CRYPT32.DLL" ALIAS "CertGetStoreProperty" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'// If the callback returns FALSE, stops the sort. CertCreateContext
'// will return FALSE and set last error to ERROR_CANCELLED if the sort
'// was stopped.
'//
'// Where:
'//  cbTotalEncoded  - total byte count of the encoded entries.
'//  cbRemainEncoded - remaining byte count of the encoded entries.
'//  cEntry          - running count of sorted entries
'//  pvSort          - value passed in pCreatePara
'//--------------------------------------------------------------------------
'typedef BOOL (WINAPI *PFN_CERT_CREATE_CONTEXT_SORT_FUNC)(
'    __in DWORD cbTotalEncoded,
'    __in DWORD cbRemainEncoded,
'    __in DWORD cEntry,
'    __inout_opt void *pvSort
'    );

'FUNCTION CERT_CREATE_CONTEXT_SORT_FUNC ( _
'   BYVAL cbTotalEncoded AS DWORD _                      ' __in DWORD cbTotalEncoded
' , BYVAL cbRemainEncoded AS DWORD _                     ' __in DWORD cbRemainEncoded
' , BYVAL cEntry AS DWORD _                              ' __in DWORD cEntry
' , OPTIONAL BYREF pvSort AS DWORD _                     ' __inout_opt void *pvSort
' ) AS LONG                                              ' BOOL

' // Size = 20 bytes
TYPE CERT_CREATE_CONTEXT_PARA DWORD
   cbSize  AS DWORD   ' DWORD
   pfnFree AS DWORD   ' PFN_CRYPT_FREE
   pvFree  AS DWORD   ' void*
   ' // Only applicable to CERT_STORE_CTL_CONTEXT when
   ' // CERT_CREATE_CONTEXT_SORTED_FLAG is set in dwFlags.
   pfnSort AS DWORD   ' PFN_CERT_CREATE_CONTEXT_SORT_FUNC // OPTIONAL
   pvSort  AS DWORD   ' void * // OPTIONAL
END TYPE

'//+-------------------------------------------------------------------------
'//  Creates the specified context from the encoded bytes. The created
'//  context isn't put in a store.
'//
'//  dwContextType values:
'//      CERT_STORE_CERTIFICATE_CONTEXT
'//      CERT_STORE_CRL_CONTEXT
'//      CERT_STORE_CTL_CONTEXT
'//
'//  If CERT_CREATE_CONTEXT_NOCOPY_FLAG is set, the created context points
'//  directly to the pbEncoded instead of an allocated copy. See flag
'//  definition for more details.
'//
'//  If CERT_CREATE_CONTEXT_SORTED_FLAG is set, the context is created
'//  with sorted entries. This flag may only be set for CERT_STORE_CTL_CONTEXT.
'//  Setting this flag implicitly sets CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG and
'//  CERT_CREATE_CONTEXT_NO_ENTRY_FLAG. See flag definition for
'//  more details.
'//
'//  If CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG is set, the context is created
'//  without creating a HCRYPTMSG handle for the context. This flag may only be
'//  set for CERT_STORE_CTL_CONTEXT.  See flag definition for more details.
'//
'//  If CERT_CREATE_CONTEXT_NO_ENTRY_FLAG is set, the context is created
'//  without decoding the entries. This flag may only be set for
'//  CERT_STORE_CTL_CONTEXT.  See flag definition for more details.
'//
'//  If unable to decode and create the context, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CONTEXT, CRL_CONTEXT or
'//  CTL_CONTEXT is returned. The context must be freed by the appropriate
'//  free context API. The context can be duplicated by calling the
'//  appropriate duplicate context API.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCreateContext IMPORT "CRYPT32.DLL" ALIAS "CertCreateContext" ( _
   BYVAL dwContextType AS DWORD _                       ' __in DWORD dwContextType
 , BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF pCreatePara AS CERT_CREATE_CONTEXT_PARA _ ' __in_opt PCERT_CREATE_CONTEXT_PARA pCreatePara
 ) AS DWORD                                             ' void*

'// When the following flag is set, the created context points directly to the
'// pbEncoded instead of an allocated copy. If pCreatePara and
'// pCreatePara->pfnFree are non-NULL, then, pfnFree is called to free
'// the pbEncoded when the context is last freed. Otherwise, no attempt is
'// made to free the pbEncoded. If pCreatePara->pvFree is non-NULL, then its
'// passed to pfnFree instead of pbEncoded.
'//
'// Note, if CertCreateContext fails, pfnFree is still called.
%CERT_CREATE_CONTEXT_NOCOPY_FLAG     = &H1???

'// When the following flag is set, a context with sorted entries is created.
'// Currently only applicable to a CTL context.
'//
'// For CTLs: the cCTLEntry in the returned CTL_INFO is always
'// 0. CertFindSubjectInSortedCTL and CertEnumSubjectInSortedCTL must be called
'// to find or enumerate the CTL entries.
'//
'// The Sorted CTL TrustedSubjects extension isn't returned in the created
'// context's CTL_INFO.
%CERT_CREATE_CONTEXT_SORTED_FLAG     = &H2???

'// By default when a CTL context is created, a HCRYPTMSG handle to its
'// SignedData message is created. This flag can be set to improve performance
'// by not creating the HCRYPTMSG handle.
'//
'// This flag is only applicable to a CTL context.
%CERT_CREATE_CONTEXT_NO_HCRYPTMSG_FLAG   = &H4???

'// By default when a CTL context is created, its entries are decoded.
'// This flag can be set to improve performance by not decoding the
'// entries.
'//
'// This flag is only applicable to a CTL context.
%CERT_CREATE_CONTEXT_NO_ENTRY_FLAG       = &H8???


'//+=========================================================================
'//  Certificate System Store Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  System Store Information
'//
'//  Currently, no system store information is persisted.
'//--------------------------------------------------------------------------

' // Size = 4 bytes
TYPE CERT_SYSTEM_STORE_INFO DWORD
   cbSize AS DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Physical Store Information
'//
'//  The Open fields are passed directly to CertOpenStore() to open
'//  the physical store.
'//
'//  By default all system stores located in the registry have an
'//  implicit SystemRegistry physical store that is opened. To disable the
'//  opening of this store, the SystemRegistry
'//  physical store corresponding to the System store must be registered with
'//  CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG set in dwFlags. Alternatively,
'//  a physical store with the name of ".Default" may be registered.
'//
'//  Depending on the store location and store name, additional predefined
'//  physical stores may be opened. For example, system stores in
'//  CURRENT_USER have the predefined physical store, .LocalMachine.
'//  To disable the opening of these predefined physical stores, the
'//  corresponding physical store must be registered with
'//  CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG set in dwFlags.
'//
'//  The CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG must be set in dwFlags
'//  to enable the adding of a context to the store.
'//
'//  When a system store is opened via the SERVICES or USERS store location,
'//  the ServiceName\ is prepended to the OpenParameters
'//  for CERT_SYSTEM_STORE_CURRENT_USER or CERT_SYSTEM_STORE_CURRENT_SERVICE
'//  physical stores and the dwOpenFlags store location is changed to
'//  CERT_SYSTEM_STORE_USERS or CERT_SYSTEM_STORE_SERVICES.
'//
'//  By default the SYSTEM, SYSTEM_REGISTRY and PHYSICAL provider
'//  stores are also opened remotely when the outer system store is opened.
'//  The CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG may be set in dwFlags
'//  to disable remote opens.
'//
'//  When opened remotely, the \\ComputerName is implicitly prepended to the
'//  OpenParameters for the SYSTEM, SYSTEM_REGISTRY and PHYSICAL provider types.
'//  To also prepend the \\ComputerName to other provider types, set the
'//  CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG in dwFlags.
'//
'//  When the system store is opened, its physical stores are ordered
'//  according to the dwPriority. A larger dwPriority indicates higher priority.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CERT_PHYSICAL_STORE_INFO DWORD
   cbSize               AS DWORD             ' DWORD
   pszOpenStoreProvider AS ASCIIZ PTR        ' LPSTR
   dwOpenEncodingType   AS DWORD             ' DWORD
   dwOpenFlags          AS DWORD             ' DWORD
   OpenParameters       AS CRYPT_DATA_BLOB   ' CRYPT_DATA_BLOB
   dwFlags              AS DWORD             ' DWORD
   dwPriority           AS DWORD             ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Physical Store Information dwFlags
'//--------------------------------------------------------------------------
%CERT_PHYSICAL_STORE_ADD_ENABLE_FLAG                     = &H1???
%CERT_PHYSICAL_STORE_OPEN_DISABLE_FLAG                   = &H2???
%CERT_PHYSICAL_STORE_REMOTE_OPEN_DISABLE_FLAG            = &H4???
%CERT_PHYSICAL_STORE_INSERT_COMPUTER_NAME_ENABLE_FLAG    = &H8???


'//+-------------------------------------------------------------------------
'//  Register a system store.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  The CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS system store
'//  name must be prefixed with the ServiceName or UserName. For example,
'//  "ServiceName\Trust".
'//
'//  Stores on remote computers can be registered for the
'//  CERT_SYSTEM_STORE_LOCAL_MACHINE, CERT_SYSTEM_STORE_SERVICES,
'//  CERT_SYSTEM_STORE_USERS, CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY
'//  or CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE
'//  locations by prepending the computer name. For example, a remote
'//  local machine store is registered via "\\ComputerName\Trust" or
'//  "ComputerName\Trust". A remote service store is registered via
'//  "\\ComputerName\ServiceName\Trust". The leading "\\" backslashes are
'//  optional in the ComputerName.
'//
'//  Set CERT_STORE_CREATE_NEW_FLAG to cause a failure if the system store
'//  already exists in the store location.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertRegisterSystemStore LIB "Crypt32.dll" _
    ALIAS "CertRegisterSystemStore" ( _
    pvSystemStore AS ANY, _  ' void *
    BYVAL dwFlags AS DWORD, _
    pStoreInfo    AS CERT_SYSTEM_STORE_INFO, _
    pvReserved    AS ANY _  ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertRegisterSystemStore IMPORT "CRYPT32.DLL" ALIAS "CertRegisterSystemStore" ( _
   BYREF pvSystemStore AS ANY _                         ' __in const void *pvSystemStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pStoreInfo AS CERT_SYSTEM_STORE_INFO _         ' __in PCERT_SYSTEM_STORE_INFO pStoreInfo
 , OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in_opt void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Register a physical store for the specified system store.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  See CertRegisterSystemStore for details on prepending a ServiceName
'//  and/or ComputerName to the system store name.
'//
'//  Set CERT_STORE_CREATE_NEW_FLAG to cause a failure if the physical store
'//  already exists in the system store.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertRegisterPhysicalStore LIB "Crypt32.dll" _
    ALIAS "CertRegisterPhysicalStore" ( _
    pvSystemStore AS ANY, _   ' void *
    BYVAL dwFlags AS DWORD, _
    pwszStoreName AS WSTRINGZ, _
    pStoreInfo    AS CERT_PHYSICAL_STORE_INFO, _
    pvReserved    AS ANY _  ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertRegisterPhysicalStore IMPORT "CRYPT32.DLL" ALIAS "CertRegisterPhysicalStore" ( _
   BYREF pvSystemStore AS ANY _                         ' __in const void *pvSystemStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszStoreName AS WSTRINGZ _                    ' __in LPCWSTR pwszStoreName
 , BYREF pStoreInfo AS CERT_PHYSICAL_STORE_INFO _       ' __in PCERT_PHYSICAL_STORE_INFO pStoreInfo
 , OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in_opt void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Unregister the specified system store.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  See CertRegisterSystemStore for details on prepending a ServiceName
'//  and/or ComputerName to the system store name.
'//
'//  CERT_STORE_DELETE_FLAG can optionally be set in dwFlags.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertUnregisterSystemStore IMPORT "CRYPT32.DLL" ALIAS "CertUnregisterSystemStore" ( _
   BYREF pvSystemStore AS ANY _                         ' __in const void *pvSystemStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Unregister the physical store from the specified system store.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  See CertRegisterSystemStore for details on prepending a ServiceName
'//  and/or ComputerName to the system store name.
'//
'//  CERT_STORE_DELETE_FLAG can optionally be set in dwFlags.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertUnregisterPhysicalStore IMPORT "CRYPT32.DLL" ALIAS "CertUnregisterPhysicalStore" ( _
   BYREF pvSystemStore AS ANY _                         ' __in const void *pvSystemStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszStoreName AS WSTRINGZ _                    ' __in LPCWSTR pwszStoreName
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Enum callbacks
'//
'//  The CERT_SYSTEM_STORE_LOCATION_MASK bits in the dwFlags parameter
'//  specifies the location of the system store
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  The callback returns FALSE and sets LAST_ERROR to stop the enumeration.
'//  The LAST_ERROR is returned to the caller of the enumeration.
'//
'//  The pvSystemStore passed to the callback has leading ComputerName and/or
'//  ServiceName prefixes where appropriate.
'//--------------------------------------------------------------------------

'typedef BOOL (WINAPI *PFN_CERT_ENUM_SYSTEM_STORE_LOCATION)(
'    IN LPCWSTR pwszStoreLocation,
'    IN DWORD dwFlags,
'    IN OPTIONAL void *pvReserved,
'    IN OPTIONAL void *pvArg
'    );

'FUNCTION CERT_ENUM_SYSTEM_STORE_LOCATION ( _
'   BYREF pwszStoreLocation AS WSTRINGZ, _               ' __in LPCWSTR pwszStoreLocation
'   BYVAL dwFlags AS DWORD, _                            ' __in DWORD dwFlags
'   OPTIONAL BYVAL pvReserved AS DWORD, _                ' __in_opt void *pvReserved
'   OPTIONAL BYVAL pvArg AS DWORD _                      ' __in_opt void *pvArg
' ) AS LONG                                              ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_ENUM_SYSTEM_STORE)(
'    IN const void *pvSystemStore,
'    IN DWORD dwFlags,
'    IN PCERT_SYSTEM_STORE_INFO pStoreInfo,
'    IN OPTIONAL void *pvReserved,
'    IN OPTIONAL void *pvArg
'    );

'FUNCTION CERT_ENUM_SYSTEM_STORE ( _
'   BYVAL pvSystemStore AS DWORD, _                      ' __in const void *pvSystemStore
'   BYVAL dwFlags AS DWORD, _                            ' __in DWORD dwFlags
'   BYREF pStoreInfo AS CERT_SYSTEM_STORE_INFO, _        ' __in PCERT_SYSTEM_STORE_INFO pStoreInfo
'   OPTIONAL BYVAL pvReserved AS DWORD, _                ' __in_opt void *pvReserved
'   OPTIONAL BYVAL pvArg AS DWORD _                      ' __in_opt void *pvArg
' ) AS LONG                                              ' BOOL

'typedef BOOL (WINAPI *PFN_CERT_ENUM_PHYSICAL_STORE)(
'    IN const void *pvSystemStore,
'    IN DWORD dwFlags,
'    IN LPCWSTR pwszStoreName,
'    IN PCERT_PHYSICAL_STORE_INFO pStoreInfo,
'    IN OPTIONAL void *pvReserved,
'    IN OPTIONAL void *pvArg
'    );

'FUNCTION CERT_ENUM_PHYSICAL_STORE ( _
'   BYVAL pvSystemStore AS DWORD, _                      ' __in const void *pvSystemStore
'   BYVAL dwFlags AS DWORD, _                            ' __in DWORD dwFlags
'   BYREF pwszStoreName AS WSTRINGZ, _                   ' __in LPCWSTR pwszStoreName
'   BYREF pStoreInfo AS CERT_PHYSICAL_STORE_INFO, _      ' __in PCERT_PHYSICAL_STORE_INFO pStoreInfo
'   OPTIONAL BYVAL pvReserved AS DWORD, _                ' __in_opt void *pvReserved
'   OPTIONAL BYVAL pvArg AS DWORD _                      ' __in_opt void *pvArg
' ) AS LONG                                              ' BOOL

'// In the PFN_CERT_ENUM_PHYSICAL_STORE callback the following flag is
'// set if the physical store wasn't registered and is an implicitly created
'// predefined physical store.
%CERT_PHYSICAL_STORE_PREDEFINED_ENUM_FLAG    = &H1???

'// Names of implicitly created predefined physical stores
'#define CERT_PHYSICAL_STORE_DEFAULT_NAME            L".Default"
'#define CERT_PHYSICAL_STORE_GROUP_POLICY_NAME       L".GroupPolicy"
'#define CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME      L".LocalMachine"
'#define CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME L".UserCertificate"
'#define CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME \
'            L".LocalMachineGroupPolicy"
'#define CERT_PHYSICAL_STORE_ENTERPRISE_NAME         L".Enterprise"
'#define CERT_PHYSICAL_STORE_AUTH_ROOT_NAME          L".AuthRoot"
'#define CERT_PHYSICAL_STORE_SMART_CARD_NAME         L".SmartCard"
$CERT_PHYSICAL_STORE_DEFAULT_NAME            = ".Default"
$CERT_PHYSICAL_STORE_GROUP_POLICY_NAME       = ".GroupPolicy"
$CERT_PHYSICAL_STORE_LOCAL_MACHINE_NAME      = ".LocalMachine"
$CERT_PHYSICAL_STORE_DS_USER_CERTIFICATE_NAME = ".UserCertificate"
$CERT_PHYSICAL_STORE_LOCAL_MACHINE_GROUP_POLICY_NAME = ".LocalMachineGroupPolicy"
$CERT_PHYSICAL_STORE_ENTERPRISE_NAME         = ".Enterprise"
$CERT_PHYSICAL_STORE_AUTH_ROOT_NAME          = ".AuthRoot"
$CERT_PHYSICAL_STORE_SMART_CARD_NAME         = ".SmartCard"

'//+-------------------------------------------------------------------------
'//  Enumerate the system store locations.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumSystemStoreLocation LIB "Crypt32.dll" _
    ALIAS "CertEnumSystemStoreLocation" ( _
    BYVAL dwFlags AS DWORD, _
    pvArg         AS ANY, _  ' void *
    BYVAL pfnEnum AS DWORD _ ' PFN_CERT_ENUM_SYSTEM_STORE_LOCATION
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertEnumSystemStoreLocation IMPORT "CRYPT32.DLL" ALIAS "CertEnumSystemStoreLocation" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
 , BYVAL pfnEnum AS DWORD _                             ' __in PFN_CERT_ENUM_SYSTEM_STORE_LOCATION pfnEnum
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the system stores.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags,
'//  pvSystemStoreLocationPara points to a CERT_SYSTEM_STORE_RELOCATE_PARA
'//  data structure. Otherwise, pvSystemStoreLocationPara points to a null
'//  terminated UNICODE string.
'//
'//  For CERT_SYSTEM_STORE_LOCAL_MACHINE,
'//  CERT_SYSTEM_STORE_LOCAL_MACHINE_GROUP_POLICY or
'//  CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE, pvSystemStoreLocationPara can
'//  optionally be set to a unicode computer name for enumerating local machine
'//  stores on a remote computer. For example, "\\ComputerName" or
'//  "ComputerName".  The leading "\\" backslashes are optional in the
'//  ComputerName.
'//
'//  For CERT_SYSTEM_STORE_SERVICES or CERT_SYSTEM_STORE_USERS,
'//  if pvSystemStoreLocationPara is NULL, then,
'//  enumerates both the service/user names and the stores for each service/user
'//  name. Otherwise, pvSystemStoreLocationPara is a unicode string specifying a
'//  remote computer name and/or service/user name. For example:
'//      "ServiceName"
'//      "\\ComputerName" or "ComputerName\"
'//      "ComputerName\ServiceName"
'//  Note, if only the ComputerName is specified, then, it must have either
'//  the leading "\\" backslashes or a trailing backslash. Otherwise, its
'//  interpretted as the ServiceName or UserName.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumSystemStore LIB "Crypt32.dll" _
    ALIAS "CertEnumSystemStore" ( _
    BYVAL dwFlags             AS DWORD, _
    pvSystemStoreLocationPara AS ANY, _   ' void *
    pvArg                     AS ANY, _   ' void *
    BYVAL pfnEnum             AS DWORD _  ' PFN_CERT_ENUM_SYSTEM_STORE
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertEnumSystemStore IMPORT "CRYPT32.DLL" ALIAS "CertEnumSystemStore" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvSystemStoreLocationPara AS ANY _             ' __in_opt void *pvSystemStoreLocationPara
 , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
 , BYVAL pfnEnum AS DWORD _                             ' __in PFN_CERT_ENUM_SYSTEM_STORE pfnEnum
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerate the physical stores for the specified system store.
'//
'//  The upper word of the dwFlags parameter is used to specify the location of
'//  the system store.
'//
'//  If CERT_SYSTEM_STORE_RELOCATE_FLAG is set in dwFlags, pvSystemStore
'//  points to a CERT_SYSTEM_STORE_RELOCATE_PARA data structure. Otherwise,
'//  pvSystemStore points to a null terminated UNICODE string.
'//
'//  See CertRegisterSystemStore for details on prepending a ServiceName
'//  and/or ComputerName to the system store name.
'//
'//  If the system store location only supports system stores and doesn't
'//  support physical stores, LastError is set to ERROR_CALL_NOT_IMPLEMENTED.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumPhysicalStore LIB "Crypt32.dll" _
    ALIAS "CertEnumPhysicalStore" ( _
    pvSystemStore AS ANY, _   ' void *
    BYVAL dwFlags AS DWORD, _
    pvArg         AS ANY, _   ' void *
    BYVAL pfnEnum AS DWORD _  ' PFN_CERT_ENUM_PHYSICAL_STORE
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertEnumPhysicalStore IMPORT "CRYPT32.DLL" ALIAS "CertEnumPhysicalStore" ( _
   BYREF pvSystemStore AS ANY _                         ' __in const void *pvSystemStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
 , BYVAL pfnEnum AS DWORD _                             ' __in PFN_CERT_ENUM_PHYSICAL_STORE pfnEnum
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate System Store Installable Functions
'//
'//  The CERT_SYSTEM_STORE_LOCATION_MASK bits in the dwFlags parameter passed
'//  to the CertOpenStore(for "System", "SystemRegistry" or "Physical"
'//  Provider), CertRegisterSystemStore,
'//  CertUnregisterSystemStore, CertEnumSystemStore, CertRegisterPhysicalStore,
'//  CertUnregisterPhysicalStore and CertEnumPhysicalStore APIs is used as the
'//  constant pszOID value passed to the OID installable functions.
'//  Therefore, the pszOID is restricted to a constant <= (LPCSTR) 0x0FFF.
'//
'//  The EncodingType is 0.
'//--------------------------------------------------------------------------

'// Installable System Store Provider OID pszFuncNames.
$CRYPT_OID_OPEN_SYSTEM_STORE_PROV_FUNC    = "CertDllOpenSystemStoreProv"
$CRYPT_OID_REGISTER_SYSTEM_STORE_FUNC     = "CertDllRegisterSystemStore"
$CRYPT_OID_UNREGISTER_SYSTEM_STORE_FUNC   = "CertDllUnregisterSystemStore"
$CRYPT_OID_ENUM_SYSTEM_STORE_FUNC         = "CertDllEnumSystemStore"
$CRYPT_OID_REGISTER_PHYSICAL_STORE_FUNC   = "CertDllRegisterPhysicalStore"
$CRYPT_OID_UNREGISTER_PHYSICAL_STORE_FUNC = "CertDllUnregisterPhysicalStore"
$CRYPT_OID_ENUM_PHYSICAL_STORE_FUNC       = "CertDllEnumPhysicalStore"

'// CertDllOpenSystemStoreProv has the same function signature as the
'// installable "CertDllOpenStoreProv" function. See CertOpenStore for
'// more details.

'// CertDllRegisterSystemStore has the same function signature as
'// CertRegisterSystemStore.
'//
'// The "SystemStoreLocation" REG_SZ value must also be set for registered
'// CertDllEnumSystemStore OID functions.
$CRYPT_OID_SYSTEM_STORE_LOCATION_VALUE_NAME = "SystemStoreLocation"

'// The remaining Register, Enum and Unregister OID installable functions
'// have the same signature as their Cert Store API counterpart.


'//+=========================================================================
'//  Enhanced Key Usage Helper Functions
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Get the enhanced key usage extension or property from the certificate
'//  and decode.
'//
'//  If the CERT_FIND_EXT_ONLY_ENHKEY_USAGE_FLAG is set, then, only get the
'//  extension.
'//
'//  If the CERT_FIND_PROP_ONLY_ENHKEY_USAGE_FLAG is set, then, only get the
'//  property.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetEnhancedKeyUsage LIB "Crypt32.dll" _
    ALIAS "CertGetEnhancedKeyUsage" ( _
    pCertContext  AS CERT_CONTEXT, _
    BYVAL dwFlags AS DWORD, _
    pUsage        AS CERT_ENHKEY_USAGE, _
    pcbUsage      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetEnhancedKeyUsage IMPORT "CRYPT32.DLL" ALIAS "CertGetEnhancedKeyUsage" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pUsage AS CERT_ENHKEY_USAGE _                  ' __out PCERT_ENHKEY_USAGE pUsage
 , BYREF pcbUsage AS DWORD _                            ' __inout DWORD *pcbUsage
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Set the enhanced key usage property for the certificate.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSetEnhancedKeyUsage LIB "Crypt32.dll" _
    ALIAS "CertSetEnhancedKeyUsage" ( _
    pCertContext AS CERT_CONTEXT, _
    pUsage       AS CERT_ENHKEY_USAGE _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSetEnhancedKeyUsage IMPORT "CRYPT32.DLL" ALIAS "CertSetEnhancedKeyUsage" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYREF pUsage AS CERT_ENHKEY_USAGE _                  ' __in PCERT_ENHKEY_USAGE pUsage
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Add the usage identifier to the certificate's enhanced key usage property.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertAddEnhancedKeyUsageIdentifier LIB "Crypt32.dll" _
    ALIAS "CertAddEnhancedKeyUsageIdentifier" ( _
    pCertContext       AS CERT_CONTEXT, _
    pszUsageIdentifier AS ASCIIZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertAddEnhancedKeyUsageIdentifier IMPORT "CRYPT32.DLL" ALIAS "CertAddEnhancedKeyUsageIdentifier" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL pszUsageIdentifier AS DWORD _                  ' __in LPCSTR pszUsageIdentifier
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Remove the usage identifier from the certificate's enhanced key usage
'//  property.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertRemoveEnhancedKeyUsageIdentifier LIB "Crypt32.dll" _
    ALIAS "CertRemoveEnhancedKeyUsageIdentifier" ( _
    pCertContext       AS CERT_CONTEXT, _
    pszUsageIdentifier AS ASCIIZ _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertRemoveEnhancedKeyUsageIdentifier IMPORT "CRYPT32.DLL" ALIAS "CertRemoveEnhancedKeyUsageIdentifier" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL pszUsageIdentifier AS DWORD _                  ' __in LPCSTR pszUsageIdentifier
 ) AS LONG                                              ' BOOL
#ENDIF

'//+---------------------------------------------------------------------------
'//
'//
'//  Takes an array of certs and returns an array of usages
'//  which consists of the intersection of the valid usages for each cert.
'//  If each cert is good for all possible usages then the cNumOIDs is set to -1.
'//
'//----------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetValidUsages LIB "Crypt32.dll" _
    ALIAS "CertGetValidUsages" ( _
    BYVAL cCerts  AS DWORD, _
    rghCerts      AS ANY, _   ' CERT_CONTEXT PTR PTR
    cNumOIDs      AS LONG, _
    rghOIDs       AS ANY, _   ' LPSTR *
    pcbOIDs       AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetValidUsages IMPORT "CRYPT32.DLL" ALIAS "CertGetValidUsages" ( _
   BYVAL cCerts AS DWORD _                              ' __in DWORD cCerts
 , BYVAL rghCerts AS CERT_CONTEXT PTR _                 ' __in PCCERT_CONTEXT *rghCerts
 , BYREF cNumOIDs AS LONG _                             ' __out int *cNumOIDs
 , BYREF rghOIDs AS ANY _                               ' __out LPSTR *rghOIDs
 , BYREF pcbOIDs AS DWORD _                             ' __inout DWORD *pcbOIDs
 ) AS LONG                                              ' BOOL
#ENDIF

'//+=========================================================================
'//  Cryptographic Message helper functions for verifying and signing a
'//  CTL.
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Get and verify the signer of a cryptographic message.
'//
'//  To verify a CTL, the hCryptMsg is obtained from the CTL_CONTEXT's
'//  hCryptMsg field.
'//
'//  If CMSG_TRUSTED_SIGNER_FLAG is set, then, treat the Signer stores as being
'//  trusted and only search them to find the certificate corresponding to the
'//  signer's issuer and serial number.  Otherwise, the SignerStores are
'//  optionally provided to supplement the message's store of certificates.
'//  If a signer certificate is found, its public key is used to verify
'//  the message signature. The CMSG_SIGNER_ONLY_FLAG can be set to
'//  return the signer without doing the signature verify.
'//
'//  If CMSG_USE_SIGNER_INDEX_FLAG is set, then, only get the signer specified
'//  by *pdwSignerIndex. Otherwise, iterate through all the signers
'//  until a signer verifies or no more signers.
'//
'//  For a verified signature, *ppSigner is updated with certificate context
'//  of the signer and *pdwSignerIndex is updated with the index of the signer.
'//  ppSigner and/or pdwSignerIndex can be NULL, indicating the caller isn't
'//  interested in getting the CertContext and/or index of the signer.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMsgGetAndVerifySigner LIB "Crypt32.dll" _
    ALIAS "CryptMsgGetAndVerifySigner" ( _
    BYVAL hCryptMsg    AS DWORD, _   ' HCRYPTMSG
    BYVAL cSignerStore AS DWORD, _
    rghSignerStore     AS DWORD, _   ' HCERTSTORE *
    BYVAL dwFlags      AS DWORD, _
    ppSigner           AS ANY, _     ' PCCERT_CONTEXT *
    pdwSignerIndex     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptMsgGetAndVerifySigner IMPORT "CRYPT32.DLL" ALIAS "CryptMsgGetAndVerifySigner" ( _
   BYVAL hCryptMsg AS DWORD _                           ' __in HCRYPTMSG hCryptMsg
 , BYVAL cSignerStore AS DWORD _                        ' __in DWORD cSignerStore
 , BYVAL rghSignerStore AS DWORD _                      ' __in_opt HCERTSTORE *rghSignerStore
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF ppSigner AS DWORD _                            ' __out_opt PCCERT_CONTEXT *ppSigner
 , BYREF pdwSignerIndex AS DWORD _                      ' __inout OPTIONAL DWORD *pdwSignerIndex
 ) AS LONG                                              ' BOOL
#ENDIF

%CMSG_TRUSTED_SIGNER_FLAG            = &H1???
%CMSG_SIGNER_ONLY_FLAG               = &H2???
%CMSG_USE_SIGNER_INDEX_FLAG          = &H4???

'//+-------------------------------------------------------------------------
'//  Sign an encoded CTL.
'//
'//  The pbCtlContent can be obtained via a CTL_CONTEXT's pbCtlContent
'//  field or via a CryptEncodeObject(PKCS_CTL or PKCS_SORTED_CTL).
'//
'//  CMSG_CMS_ENCAPSULATED_CTL_FLAG can be set to encode a CMS compatible
'//  V3 SignedData message.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgSignCTL IMPORT "CRYPT32.DLL" ALIAS "CryptMsgSignCTL" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYVAL pbCtlContent AS BYTE PTR _                     ' __in BYTE *pbCtlContent
 , BYVAL cbCtlContent AS DWORD _                        ' __in DWORD cbCtlContent
 , BYREF pSignInfo AS CMSG_SIGNED_ENCODE_INFO _         ' __in PCMSG_SIGNED_ENCODE_INFO pSignInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbEncoded AS BYTE PTR _                        ' __out BYTE *pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 ) AS LONG                                              ' BOOL

'// When set, CTL inner content is encapsulated within an OCTET STRING
%CMSG_CMS_ENCAPSULATED_CTL_FLAG  = &H00008000???

'//+-------------------------------------------------------------------------
'//  Encode the CTL and create a signed message containing the encoded CTL.
'//
'//  Set CMSG_ENCODE_SORTED_CTL_FLAG if the CTL entries are to be sorted
'//  before encoding. This flag should be set, if the
'//  CertFindSubjectInSortedCTL or CertEnumSubjectInSortedCTL APIs will
'//  be called. If the identifier for the CTL entries is a hash, such as,
'//  MD5 or SHA1, then, CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG should
'//  also be set.
'//
'//  CMSG_CMS_ENCAPSULATED_CTL_FLAG can be set to encode a CMS compatible
'//  V3 SignedData message.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptMsgEncodeAndSignCTL IMPORT "CRYPT32.DLL" ALIAS "CryptMsgEncodeAndSignCTL" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYREF pCtlInfo AS CTL_INFO _                         ' __in PCTL_INFO pCtlInfo
 , BYREF pSignInfo AS CMSG_SIGNED_ENCODE_INFO _         ' __in PCMSG_SIGNED_ENCODE_INFO pSignInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbEncoded AS BYTE PTR _                        ' __out BYTE *pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 ) AS LONG                                              ' BOOL

'//  The following flag is set if the CTL is to be encoded with sorted
'//  trusted subjects and the szOID_SORTED_CTL extension is inserted containing
'//  sorted offsets to the encoded subjects.
%CMSG_ENCODE_SORTED_CTL_FLAG                     = &H1???

'//  If the above sorted flag is set, then, the following flag should also
'//  be set if the identifier for the TrustedSubjects is a hash,
'//  such as, MD5 or SHA1.
%CMSG_ENCODE_HASHED_SUBJECT_IDENTIFIER_FLAG      = &H2???


'//+-------------------------------------------------------------------------
'//  Returns TRUE if the SubjectIdentifier exists in the CTL. Optionally
'//  returns a pointer to and byte count of the Subject's encoded attributes.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertFindSubjectInSortedCTL LIB "Crypt32.dll" _
    ALIAS "CertFindSubjectInSortedCTL" ( _
    pSubjectIdentifier AS CRYPT_DATA_BLOB, _
    pCtlContext        AS CTL_CONTEXT, _
    BYVAL dwFlags      AS DWORD, _
    pvReserved         AS ANY, _  ' void *
    pEncodedAttributes AS CRYPT_DER_BLOB _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertFindSubjectInSortedCTL IMPORT "CRYPT32.DLL" ALIAS "CertFindSubjectInSortedCTL" ( _
   BYREF pSubjectIdentifier AS CRYPT_DATA_BLOB _        ' __in PCRYPT_DATA_BLOB pSubjectIdentifier
 , BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 , OPTIONAL BYREF pEncodedAttributes AS CRYPT_DER_BLOB _ ' __out_opt PCRYPT_DER_BLOB pEncodedAttributes
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Enumerates through the sequence of TrustedSubjects in a CTL context
'//  created with CERT_CREATE_CONTEXT_SORTED_FLAG set.
'//
'//  To start the enumeration, *ppvNextSubject must be NULL. Upon return,
'//  *ppvNextSubject is updated to point to the next TrustedSubject in
'//  the encoded sequence.
'//
'//  Returns FALSE for no more subjects or invalid arguments.
'//
'//  Note, the returned DER_BLOBs point directly into the encoded
'//  bytes (not allocated, and must not be freed).
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertEnumSubjectInSortedCTL LIB "Crypt32.dll" _
    ALIAS "CertEnumSubjectInSortedCTL" ( _
    pCtlContext        AS CTL_CONTEXT, _
    ppvNextSubject     AS ANY, _  ' void **
    pSubjectIdentifier AS CRYPT_DER_BLOB, _
    pEncodedAttributes AS CRYPT_DER_BLOB _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertEnumSubjectInSortedCTL IMPORT "CRYPT32.DLL" ALIAS "CertEnumSubjectInSortedCTL" ( _
   BYVAL pCtlContext AS CTL_CONTEXT PTR _               ' __in PCCTL_CONTEXT pCtlContext
 , BYREF ppvNextSubject AS DWORD _                      ' __inout void **ppvNextSubject
 , OPTIONAL BYREF pSubjectIdentifier AS CRYPT_DER_BLOB _ ' __out_opt PCRYPT_DER_BLOB pSubjectIdentifier
 , OPTIONAL BYREF pEncodedAttributes AS CRYPT_DER_BLOB _ ' __out_opt PCRYPT_DER_BLOB pEncodedAttributes
 ) AS LONG                                              ' BOOL
#ENDIF

'//+=========================================================================
'//  Certificate Verify CTL Usage Data Structures and APIs
'//==========================================================================

' // Size = 28 bytes
TYPE CTL_VERIFY_USAGE_PARA DWORD
   cbSize         AS DWORD             ' DWORD
   ListIdentifier AS CRYPT_DATA_BLOB   ' CRYPT_DATA_BLOB
   cCtlStore      AS DWORD             ' DWORD
   rghCtlStore    AS DWORD PTR         ' HCERTSTORE*
   cSignerStore   AS DWORD             ' DWORD
   rghSignerStore AS DWORD PTR         ' HCERTSTORE*
END TYPE

' // Size = 28 bytes
TYPE CTL_VERIFY_USAGE_STATUS DWORD
   cbSize          AS DWORD             ' DWORD
   dwError         AS DWORD             ' DWORD
   dwFlags         AS DWORD             ' DWORD
   ppCtl           AS CTL_CONTEXT PTR   ' PCCTL_CONTEXT
   dwCtlEntryIndex AS DWORD             ' DWORD
   ppSigner        AS CERT_CONTEXT PTR  ' PCCERT_CONTEXT
   dwSignerIndex   AS DWORD             ' DWORD
END TYPE

%CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG     = &H1???
%CERT_VERIFY_TRUSTED_SIGNERS_FLAG        = &H2???
%CERT_VERIFY_NO_TIME_CHECK_FLAG          = &H4???
%CERT_VERIFY_ALLOW_MORE_USAGE_FLAG       = &H8???

%CERT_VERIFY_UPDATED_CTL_FLAG            = &H1???

'//+-------------------------------------------------------------------------
'//  Verify that a subject is trusted for the specified usage by finding a
'//  signed and time valid CTL with the usage identifiers and containing the
'//  the subject. A subject can be identified by either its certificate context
'//  or any identifier such as its SHA1 hash.
'//
'//  See CertFindSubjectInCTL for definition of dwSubjectType and pvSubject
'//  parameters.
'//
'//  Via pVerifyUsagePara, the caller can specify the stores to be searched
'//  to find the CTL. The caller can also specify the stores containing
'//  acceptable CTL signers. By setting the ListIdentifier, the caller
'//  can also restrict to a particular signer CTL list.
'//
'//  Via pVerifyUsageStatus, the CTL containing the subject, the subject's
'//  index into the CTL's array of entries, and the signer of the CTL
'//  are returned. If the caller is not interested, ppCtl and ppSigner can be set
'//  to NULL. Returned contexts must be freed via the store's free context APIs.
'//
'//  If the CERT_VERIFY_INHIBIT_CTL_UPDATE_FLAG isn't set, then, a time
'//  invalid CTL in one of the CtlStores may be replaced. When replaced, the
'//  CERT_VERIFY_UPDATED_CTL_FLAG is set in pVerifyUsageStatus->dwFlags.
'//
'//  If the CERT_VERIFY_TRUSTED_SIGNERS_FLAG is set, then, only the
'//  SignerStores specified in pVerifyUsageStatus are searched to find
'//  the signer. Otherwise, the SignerStores provide additional sources
'//  to find the signer's certificate.
'//
'//  If CERT_VERIFY_NO_TIME_CHECK_FLAG is set, then, the CTLs aren't checked
'//  for time validity.
'//
'//  If CERT_VERIFY_ALLOW_MORE_USAGE_FLAG is set, then, the CTL may contain
'//  additional usage identifiers than specified by pSubjectUsage. Otherwise,
'//  the found CTL will contain the same usage identifers and no more.
'//
'//  CertVerifyCTLUsage will be implemented as a dispatcher to OID installable
'//  functions. First, it will try to find an OID function matching the first
'//  usage object identifier in the pUsage sequence. Next, it will dispatch
'//  to the default CertDllVerifyCTLUsage functions.
'//
'//  If the subject is trusted for the specified usage, then, TRUE is
'//  returned. Otherwise, FALSE is returned with dwError set to one of the
'//  following:
'//      CRYPT_E_NO_VERIFY_USAGE_DLL
'//      CRYPT_E_NO_VERIFY_USAGE_CHECK
'//      CRYPT_E_VERIFY_USAGE_OFFLINE
'//      CRYPT_E_NOT_IN_CTL
'//      CRYPT_E_NO_TRUSTED_SIGNER
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyCTLUsage IMPORT "CRYPT32.DLL" ALIAS "CertVerifyCTLUsage" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL dwSubjectType AS DWORD _                       ' __in DWORD dwSubjectType
 , BYREF pvSubject AS ANY _                             ' __in void *pvSubject
 , BYREF pSubjectUsage AS CTL_USAGE _                   ' __in PCTL_USAGE pSubjectUsage
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pVerifyUsagePara AS CTL_VERIFY_USAGE_PARA _    ' __in_opt PCTL_VERIFY_USAGE_PARA pVerifyUsagePara
 , BYREF pVerifyUsageStatus AS CTL_VERIFY_USAGE_STATUS _ ' __inout PCTL_VERIFY_USAGE_STATUS pVerifyUsageStatus
 ) AS LONG                                              ' BOOL

'//+=========================================================================
'//  Certificate Revocation Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  This data structure is updated by a CRL revocation type handler
'//  with the base and possibly the delta CRL used.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CERT_REVOCATION_CRL_INFO DWORD
   cbSize           AS DWORD             ' DWORD
   pBaseCrlContext  AS CRL_CONTEXT PTR   ' PCCRL_CONTEXT
   pDeltaCrlContext AS CRL_CONTEXT PTR   ' PCCRL_CONTEXT
   pCrlEntry        AS CRL_ENTRY   PTR   ' PCRL_ENTRY
   fDeltaCrlEntry   AS LONG              ' BOOL
END TYPE

'//+-------------------------------------------------------------------------
'//  This data structure is optionally pointed to by the pChainPara field
'//  in the CERT_REVOCATION_PARA and CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
'//  data structures. CertGetCertificateChain() populates when it calls
'//  the CertVerifyRevocation() API.
'//--------------------------------------------------------------------------

' // Size = 32 bytes
TYPE CERT_REVOCATION_CHAIN_PARA DWORD
   cbSize                     AS DWORD          ' DWORD
   hChainEngine               AS DWORD          ' HCERTCHAINENGINE
   hAdditionalStore           AS DWORD          ' HCERTSTORE
   dwChainFlags               AS DWORD          ' DWORD
   dwUrlRetrievalTimeout      AS DWORD          ' DWORD
   pftCurrentTime             AS FILETIME PTR   ' LPFILETIME
   pftCacheResync             AS FILETIME PTR   ' LPFILETIME
   cbMaxUrlRetrievalByteCount AS DWORD          ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  The following data structure may be passed to CertVerifyRevocation to
'//  assist in finding the issuer of the context to be verified.
'//
'//  When pIssuerCert is specified, pIssuerCert is the issuer of
'//  rgpvContext[cContext - 1].
'//
'//  When cCertStore and rgCertStore are specified, these stores may contain
'//  an issuer certificate.
'//
'//  When hCrlStore is specified then a handler which uses CRLs can search this
'//  store for them
'//
'//  When pftTimeToUse is specified then the handler (if possible) must determine
'//  revocation status relative to the time given otherwise the answer may be
'//  independent of time or relative to current time
'//--------------------------------------------------------------------------
'typedef struct _CERT_REVOCATION_PARA {
'    DWORD                       cbSize;
'    PCCERT_CONTEXT              pIssuerCert;
'    DWORD                       cCertStore;
'    HCERTSTORE                  *rgCertStore;
'    HCERTSTORE                  hCrlStore;
'    LPFILETIME                  pftTimeToUse;

'#ifdef CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS
'    // Note, if you #define CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS, then, you
'    // must zero all unused fields in this data structure.
'    // More fields could be added in a future release.

'    // 0 uses revocation handler's default timeout.
'    DWORD                       dwUrlRetrievalTimeout;  // milliseconds

'    // When set, checks and attempts to retrieve a CRL where
'    // ThisUpdate >= (CurrentTime - dwFreshnessTime). Otherwise, defaults
'    // to using the CRL's NextUpdate.
'    BOOL                        fCheckFreshnessTime;
'    DWORD                       dwFreshnessTime;        // seconds

'    // If NULL, revocation handler gets the current time
'    LPFILETIME                  pftCurrentTime;

'    // If nonNULL, a CRL revocation type handler updates with the base and
'    // possibly the delta CRL used. Note, *pCrlInfo must be initialized
'    // by the caller. Any nonNULL CRL contexts are freed. Any updated
'    // CRL contexts must be freed by the caller.
'    //
'    // The CRL info is only applicable to the last context checked. If
'    // interested in this information, then, CertVerifyRevocation should be
'    // called with cContext = 1.
'    PCERT_REVOCATION_CRL_INFO   pCrlInfo;
'    // If nonNULL, any cached information before this time is considered
'    // time invalid and forces a wire retrieval.
'    LPFILETIME                  pftCacheResync;

'    // If nonNULL, CertGetCertificateChain() parameters used by the caller.
'    // Enables independent OCSP signer certificate chain verification.
'    PCERT_REVOCATION_CHAIN_PARA pChainPara;
'#endif
'} CERT_REVOCATION_PARA, *PCERT_REVOCATION_PARA;

' // Size = 24 bytes
TYPE CERT_REVOCATION_PARA DWORD
   cbSize                AS DWORD
   pIssuerCert           AS CERT_CONTEXT PTR
   cCertStore            AS DWORD
   rgCertStore           AS DWORD PTR
   hCrlStore             AS DWORD
   pftTimeToUse          AS FILETIME PTR
#IF %DEF(%CERT_REVOCATION_PARA_HAS_EXTRA_FIELDS)
   dwUrlRetrievalTimeout AS DWORD
   fCheckFreshnessTime   AS LONG
   dwFreshnessTime       AS DWORD
   pftCurrentTime        AS FILETIME PTR
   pCrlInfo              AS CERT_REVOCATION_CRL_INFO PTR
   pftCacheResync        AS FILETIME PTR                     ' LPFILETIME
   pChainPara            AS CERT_REVOCATION_CHAIN_PARA PTR   ' PCERT_REVOCATION_CHAIN_PARA
#ENDIF
END TYPE


'//+-------------------------------------------------------------------------
'//  The following data structure is returned by CertVerifyRevocation to
'//  specify the status of the revoked or unchecked context. Review the
'//  following CertVerifyRevocation comments for details.
'//
'//  Upon input to CertVerifyRevocation, cbSize must be set to a size
'//  >= (offsetof(CERT_REVOCATION_STATUS, dwReason) + sizeof(DWORD) ).
'//  Otherwise, CertVerifyRevocation returns FALSE and sets LastError to
'//  E_INVALIDARG.
'//
'//  Upon input to the installed or registered CRYPT_OID_VERIFY_REVOCATION_FUNC
'//  functions, the dwIndex, dwError and dwReason have been zero'ed.
'//  If present, fHasFreshnessTime and dwFreshnessTime have been zero'ed.
'//--------------------------------------------------------------------------
'typedef struct _CERT_REVOCATION_STATUS {
'    DWORD                   cbSize;
'    DWORD                   dwIndex;
'    DWORD                   dwError;
'    DWORD                   dwReason;

''    // Depending on cbSize, the following fields may optionally be returned.

''    // The Freshness time is only applicable to the last context checked. If
''    // interested in this information, then, CertVerifyRevocation should be
''    // called with cContext = 1.
''    //
''    // fHasFreshnessTime is only set if we are able to retrieve revocation
''    // information. For a CRL its CurrentTime - ThisUpdate.
'    BOOL                    fHasFreshnessTime;
'    DWORD                   dwFreshnessTime;    // seconds
'} CERT_REVOCATION_STATUS, *PCERT_REVOCATION_STATUS;

' // Size = 24 bytes
TYPE CERT_REVOCATION_STATUS DWORD
   cbSize            AS DWORD
   dwIndex           AS DWORD
   dwError           AS DWORD
   dwReason          AS DWORD
   fHasFreshnessTime AS LONG
   dwFreshnessTime   AS DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Verifies the array of contexts for revocation. The dwRevType parameter
'//  indicates the type of the context data structure passed in rgpvContext.
'//  Currently only the revocation of certificates is defined.
'//
'//  If the CERT_VERIFY_REV_CHAIN_FLAG flag is set, then, CertVerifyRevocation
'//  is verifying a chain of certs where, rgpvContext[i + 1] is the issuer
'//  of rgpvContext[i]. Otherwise, CertVerifyRevocation makes no assumptions
'//  about the order of the contexts.
'//
'//  To assist in finding the issuer, the pRevPara may optionally be set. See
'//  the CERT_REVOCATION_PARA data structure for details.
'//
'//  The contexts must contain enough information to allow the
'//  installable or registered revocation DLLs to find the revocation server. For
'//  certificates, this information would normally be conveyed in an
'//  extension such as the IETF's AuthorityInfoAccess extension.
'//
'//  CertVerifyRevocation returns TRUE if all of the contexts were successfully
'//  checked and none were revoked. Otherwise, returns FALSE and updates the
'//  returned pRevStatus data structure as follows:
'//    dwIndex
'//      Index of the first context that was revoked or unable to
'//      be checked for revocation
'//    dwError
'//      Error status. LastError is also set to this error status.
'//      dwError can be set to one of the following error codes defined
'//      in winerror.h:
'//        ERROR_SUCCESS - good context
'//        CRYPT_E_REVOKED - context was revoked. dwReason contains the
'//           reason for revocation
'//        CRYPT_E_REVOCATION_OFFLINE - unable to connect to the
'//           revocation server
'//        CRYPT_E_NOT_IN_REVOCATION_DATABASE - the context to be checked
'//           was not found in the revocation server's database.
'//        CRYPT_E_NO_REVOCATION_CHECK - the called revocation function
'//           wasn't able to do a revocation check on the context
'//        CRYPT_E_NO_REVOCATION_DLL - no installed or registered Dll was
'//           found to verify revocation
'//    dwReason
'//      The dwReason is currently only set for CRYPT_E_REVOKED and contains
'//      the reason why the context was revoked. May be one of the following
'//      CRL reasons defined by the CRL Reason Code extension ("2.5.29.21")
'//          CRL_REASON_UNSPECIFIED              0
'//          CRL_REASON_KEY_COMPROMISE           1
'//          CRL_REASON_CA_COMPROMISE            2
'//          CRL_REASON_AFFILIATION_CHANGED      3
'//          CRL_REASON_SUPERSEDED               4
'//          CRL_REASON_CESSATION_OF_OPERATION   5
'//          CRL_REASON_CERTIFICATE_HOLD         6
'//
'//  For each entry in rgpvContext, CertVerifyRevocation iterates
'//  through the CRYPT_OID_VERIFY_REVOCATION_FUNC
'//  function set's list of installed DEFAULT functions.
'//  CryptGetDefaultOIDFunctionAddress is called with pwszDll = NULL. If no
'//  installed functions are found capable of doing the revocation verification,
'//  CryptVerifyRevocation iterates through CRYPT_OID_VERIFY_REVOCATION_FUNC's
'//  list of registered DEFAULT Dlls. CryptGetDefaultOIDDllList is called to
'//  get the list. CryptGetDefaultOIDFunctionAddress is called to load the Dll.
'//
'//  The called functions have the same signature as CertVerifyRevocation. A
'//  called function returns TRUE if it was able to successfully check all of
'//  the contexts and none were revoked. Otherwise, the called function returns
'//  FALSE and updates pRevStatus. dwIndex is set to the index of
'//  the first context that was found to be revoked or unable to be checked.
'//  dwError and LastError are updated. For CRYPT_E_REVOKED, dwReason
'//  is updated. Upon input to the called function, dwIndex, dwError and
'//  dwReason have been zero'ed. cbSize has been checked to be >=
'//  sizeof(CERT_REVOCATION_STATUS).
'//
'//  If the called function returns FALSE, and dwError isn't set to
'//  CRYPT_E_REVOKED, then, CertVerifyRevocation either continues on to the
'//  next DLL in the list for a returned dwIndex of 0 or for a returned
'//  dwIndex > 0, restarts the process of finding a verify function by
'//  advancing the start of the context array to the returned dwIndex and
'//  decrementing the count of remaining contexts.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyRevocation IMPORT "CRYPT32.DLL" ALIAS "CertVerifyRevocation" ( _
   BYVAL dwEncodingType AS DWORD _                      ' __in DWORD dwEncodingType
 , BYVAL dwRevType AS DWORD _                           ' __in DWORD dwRevType
 , BYVAL cContext AS DWORD _                            ' __in DWORD cContext
 , BYREF rgpvContext AS ANY _                           ' __in PVOID rgpvContext[]
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pRevPara AS CERT_REVOCATION_PARA _             ' __in_opt PCERT_REVOCATION_PARA pRevPara
 , BYREF pRevStatus AS CERT_REVOCATION_STATUS _         ' __inout PCERT_REVOCATION_STATUS pRevStatus
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Revocation types
'//--------------------------------------------------------------------------
%CERT_CONTEXT_REVOCATION_TYPE            = 1???

'//+-------------------------------------------------------------------------
'//  When the following flag is set, vContext[] consists of a chain
'//  of certificates, where rgpvContext[i + 1] is the issuer of rgpvContext[i].
'//--------------------------------------------------------------------------
%CERT_VERIFY_REV_CHAIN_FLAG              = &H00000001???

'//+-------------------------------------------------------------------------
'// CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION prevents the revocation handler from
'// accessing any network based resources for revocation checking
'//--------------------------------------------------------------------------
%CERT_VERIFY_CACHE_ONLY_BASED_REVOCATION = &H00000002???

'//+-------------------------------------------------------------------------
'//  By default, the dwUrlRetrievalTimeout in pRevPara is the timeout used
'//  for each URL wire retrieval. When the following flag is set,
'//  dwUrlRetrievalTimeout is the accumulative timeout across all URL wire
'//  retrievals.
'//--------------------------------------------------------------------------
%CERT_VERIFY_REV_ACCUMULATIVE_TIMEOUT_FLAG = &H00000004???

'//+-------------------------------------------------------------------------
'//  When the following flag is set, only OCSP responses are used for
'//  doing revocation checking. If the certificate doesn't have any
'//  OCSP AIA URLs, dwError is set to CRYPT_E_NOT_IN_REVOCATION_DATABASE.
'//--------------------------------------------------------------------------
%CERT_VERIFY_REV_SERVER_OCSP_FLAG          = &H00000008???

'//+-------------------------------------------------------------------------
'//  CERT_CONTEXT_REVOCATION_TYPE
'//
'//  pvContext points to a const CERT_CONTEXT.
'//--------------------------------------------------------------------------

'//+=========================================================================
'//  Certificate Helper APIs
'//==========================================================================


'//+-------------------------------------------------------------------------
'//  Compare two multiple byte integer blobs to see if they are identical.
'//
'//  Before doing the comparison, leading zero bytes are removed from a
'//  positive number and leading 0xFF bytes are removed from a negative
'//  number.
'//
'//  The multiple byte integers are treated as Little Endian. pbData[0] is the
'//  least significant byte and pbData[cbData - 1] is the most significant
'//  byte.
'//
'//  Returns TRUE if the integer blobs are identical after removing leading
'//  0 or 0xFF bytes.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCompareIntegerBlob IMPORT "CRYPT32.DLL" ALIAS "CertCompareIntegerBlob" ( _
   BYREF pInt1 AS CRYPT_INTEGER_BLOB _                  ' __in PCRYPT_INTEGER_BLOB pInt1
 , BYREF pInt2 AS CRYPT_INTEGER_BLOB _                  ' __in PCRYPT_INTEGER_BLOB pInt2
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Compare two certificates to see if they are identical.
'//
'//  Since a certificate is uniquely identified by its Issuer and SerialNumber,
'//  these are the only fields needing to be compared.
'//
'//  Returns TRUE if the certificates are identical.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCompareCertificate IMPORT "CRYPT32.DLL" ALIAS "CertCompareCertificate" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pCertId1 AS CERT_INFO _                        ' __in PCERT_INFO pCertId1
 , BYREF pCertId2 AS CERT_INFO _                        ' __in PCERT_INFO pCertId2
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Compare two certificate names to see if they are identical.
'//
'//  Returns TRUE if the names are identical.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCompareCertificateName IMPORT "CRYPT32.DLL" ALIAS "CertCompareCertificateName" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pCertName1 AS CERT_NAME_BLOB _                 ' __in PCERT_NAME_BLOB pCertName1
 , BYREF pCertName2 AS CERT_NAME_BLOB _                 ' __in PCERT_NAME_BLOB pCertName2
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Compare the attributes in the certificate name with the specified
'//  Relative Distinguished Name's (CERT_RDN) array of attributes.
'//  The comparison iterates through the CERT_RDN attributes and looks for an
'//  attribute match in any of the certificate name's RDNs.
'//  Returns TRUE if all the attributes are found and match.
'//
'//  The CERT_RDN_ATTR fields can have the following special values:
'//    pszObjId == NULL              - ignore the attribute object identifier
'//    dwValueType == RDN_ANY_TYPE   - ignore the value type
'//
'//  CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG should be set to do
'//  a case insensitive match. Otherwise, defaults to an exact, case sensitive
'//  match.
'//
'//  CERT_UNICODE_IS_RDN_ATTRS_FLAG should be set if the pRDN was initialized
'//  with unicode strings as for CryptEncodeObject(X509_UNICODE_NAME).
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertIsRDNAttrsInCertificateName IMPORT "CRYPT32.DLL" ALIAS "CertIsRDNAttrsInCertificateName" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pCertName AS CERT_NAME_BLOB _                  ' __in PCERT_NAME_BLOB pCertName
 , BYREF pRDN AS CERT_RDN _                             ' __in PCERT_RDN pRDN
 ) AS LONG                                              ' BOOL

%CERT_UNICODE_IS_RDN_ATTRS_FLAG              = &H1???
%CERT_CASE_INSENSITIVE_IS_RDN_ATTRS_FLAG     = &H2???

'//+-------------------------------------------------------------------------
'//  Compare two public keys to see if they are identical.
'//
'//  Returns TRUE if the keys are identical.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertComparePublicKeyInfo IMPORT "CRYPT32.DLL" ALIAS "CertComparePublicKeyInfo" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pPublicKey1 AS CERT_PUBLIC_KEY_INFO _          ' __in PCERT_PUBLIC_KEY_INFO pPublicKey1
 , BYREF pPublicKey2 AS CERT_PUBLIC_KEY_INFO _          ' __in PCERT_PUBLIC_KEY_INFO pPublicKey2
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Get the public/private key's bit length.
'//
'//  Returns 0 if unable to determine the key's length.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertGetPublicKeyLength IMPORT "CRYPT32.DLL" ALIAS "CertGetPublicKeyLength" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pPublicKey AS CERT_PUBLIC_KEY_INFO _           ' __in PCERT_PUBLIC_KEY_INFO pPublicKey
 ) AS DWORD                                             ' DWORD

'//+-------------------------------------------------------------------------
'//  Verify the signature of a subject certificate or a CRL using the
'//  public key info
'//
'//  Returns TRUE for a valid signature.
'//
'//  hCryptProv specifies the crypto provider to use to verify the signature.
'//  It doesn't need to use a private key.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptVerifyCertificateSignature IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyCertificateSignature" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV               hCryptProv
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD                    dwCertEncodingType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *             pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD                    cbEncoded
 , BYREF pPublicKey AS CERT_PUBLIC_KEY_INFO _           ' __in PCERT_PUBLIC_KEY_INFO    pPublicKey
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify the signature of a subject certificate, CRL, certificate request
'//  or keygen request using the issuer's public key.
'//
'//  Returns TRUE for a valid signature.
'//
'//  The subject can be an encoded blob or a context for a certificate or CRL.
'//  For a subject certificate context, if the certificate is missing
'//  inheritable PublicKey Algorithm Parameters, the context's
'//  CERT_PUBKEY_ALG_PARA_PROP_ID is updated with the issuer's public key
'//  algorithm parameters for a valid signature.
'//
'//  The issuer can be a pointer to a CERT_PUBLIC_KEY_INFO, certificate
'//  context or a chain context.
'//
'//  hCryptProv specifies the crypto provider to use to verify the signature.
'//  Its private key isn't used. If hCryptProv is NULL, a default
'//  provider is picked according to the PublicKey Algorithm OID.
'//
'//  If the signature algorithm is a hashing algorithm, then, the
'//  signature is expected to contain the hash octets. Only dwIssuerType
'//  of CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL may be specified
'//  to verify this no signature case. If any other dwIssuerType is
'//  specified, the verify will fail with LastError set to E_INVALIDARG.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptVerifyCertificateSignatureEx LIB "Crypt32.dll" _
    ALIAS "CryptVerifyCertificateSignatureEx" ( _
    BYVAL hCryptProv         AS DWORD, _  ' HCRYPTPROV_LEGACY
    BYVAL dwCertEncodingType AS DWORD, _
    BYVAL dwSubjectType      AS DWORD, _
    pvSubject                AS ANY, _    ' void *
    BYVAL dwIssuerType       AS DWORD, _
    pvIssuer                 AS ANY, _
    BYVAL dwFlags            AS DWORD, _
    pvReserved               AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptVerifyCertificateSignatureEx IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyCertificateSignatureEx" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in_opt HCRYPTPROV hCryptProv
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwSubjectType AS DWORD _                       ' __in DWORD dwSubjectType
 , BYREF pvSubject AS ANY _                             ' __in void *pvSubject
 , BYVAL dwIssuerType AS DWORD _                        ' __in DWORD dwIssuerType
 , BYREF pvIssuer AS ANY _                              ' __in void *pvIssuer
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in_opt void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF


'// Subject Types
%CRYPT_VERIFY_CERT_SIGN_SUBJECT_BLOB        = 1???
'    // pvSubject :: PCRYPT_DATA_BLOB
%CRYPT_VERIFY_CERT_SIGN_SUBJECT_CERT        = 2???
'    // pvSubject :: PCCERT_CONTEXT
%CRYPT_VERIFY_CERT_SIGN_SUBJECT_CRL         = 3???
'    // pvSubject :: PCCRL_CONTEXT

'// Issuer Types
%CRYPT_VERIFY_CERT_SIGN_ISSUER_PUBKEY       = 1???
'    // pvIssuer :: PCERT_PUBLIC_KEY_INFO
%CRYPT_VERIFY_CERT_SIGN_ISSUER_CERT         = 2???
'    // pvIssuer :: PCCERT_CONTEXT
%CRYPT_VERIFY_CERT_SIGN_ISSUER_CHAIN        = 3???
'    // pvIssuer :: PCCERT_CHAIN_CONTEXT
%CRYPT_VERIFY_CERT_SIGN_ISSUER_NULL         = 4???
'    // pvIssuer :: NULL

'//+-------------------------------------------------------------------------
'//  Compute the hash of the "to be signed" information in the encoded
'//  signed content (CERT_SIGNED_CONTENT_INFO).
'//
'//  hCryptProv specifies the crypto provider to use to compute the hash.
'//  It doesn't need to use a private key.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptHashToBeSigned IMPORT "CRYPT32.DLL" ALIAS "CryptHashToBeSigned" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Hash the encoded content.
'//
'//  hCryptProv specifies the crypto provider to use to compute the hash.
'//  It doesn't need to use a private key.
'//
'//  Algid specifies the CAPI hash algorithm to use. If Algid is 0, then, the
'//  default hash algorithm (currently SHA1) is used.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptHashCertificate IMPORT "CRYPT32.DLL" ALIAS "CryptHashCertificate" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL Algid AS DWORD _                               ' __in ALG_ID Algid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL

'#if (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Hash the encoded content using the CNG hash algorithm provider.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptHashCertificate2 LIB "Crypt32.dll" _
    ALIAS "CryptHashCertificate2" ( _
    pwszCNGHashAlgid     AS WSTRINGZ, _
    BYVAL dwFlags        AS DWORD, _
    pvReserved           AS ANY, _  ' void *
    BYVAL pbEncoded      AS BYTE PTR, _
    BYVAL cbEncoded      AS DWORD, _
    BYVAL pbComputedHash AS BYTE PTR, _
    pcbComputedHash      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptHashCertificate2 IMPORT "CRYPT32.DLL" ALIAS "CryptHashCertificate2" ( _
   BYREF pwszCNGHashAlgid AS WSTRINGZ _                 ' __in LPCWSTR pwszCNGHashAlgid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 , BYVAL pbEncoded AS BYTE PTR _                        ' __in const BYTE *pbEncoded
 , BYVAL cbEncoded AS DWORD _                           ' __in DWORD cbEncoded
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Sign the "to be signed" information in the encoded signed content.
'//
'//  hCryptProv specifies the crypto provider to use to do the signature.
'//  It uses the specified private key.
'//
'//  If the SignatureAlgorithm is a hash algorithm, then, the signature
'//  contains the hash octets. A private key isn't used to encrypt the hash.
'//  dwKeySpec isn't used and hCryptProv can be NULL where an appropriate
'//  default provider will be used for hashing.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSignCertificate LIB "Crypt32.dll" _
    ALIAS "CryptSignCertificate" ( _
    BYVAL hCryptProvOrNCryptKey AS DWORD, _  ' HCRYPTPROV_OR_NCRYPT_KEY_HANDLE
    BYVAL dwKeySpec             AS DWORD, _  ' not applicable for NCRYPT_KEY_HANDLE
    BYVAL dwCertEncodingType    AS DWORD, _
    BYVAL pbEncodedToBeSigned   AS BYTE PTR, _
    BYVAL cbEncodedToBeSigned   AS DWORD, _
    pSignatureAlgorithm         AS CRYPT_ALGORITHM_IDENTIFIER, _
    pvHashAuxInfo               AS ANY, _  ' void *
    BYVAL pbSignature           AS BYTE PTR, _
    pcbSignature                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptSignCertificate IMPORT "CRYPT32.DLL" ALIAS "CryptSignCertificate" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL pbEncodedToBeSigned AS BYTE PTR _              ' __in const BYTE *pbEncodedToBeSigned
 , BYVAL cbEncodedToBeSigned AS DWORD _                 ' __in DWORD cbEncodedToBeSigned
 , BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
 , BYVAL pvHashAuxInfo AS DWORD _                       ' __in_opt const void *pvHashAuxInfo
 , BYVAL pbSignature AS BYTE PTR _                      ' __out BYTE *pbSignature
 , BYREF pcbSignature AS DWORD _                        ' __inout DWORD *pcbSignature
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Encode the "to be signed" information. Sign the encoded "to be signed".
'//  Encode the "to be signed" and the signature.
'//
'//  hCryptProv specifies the crypto provider to use to do the signature.
'//  It uses the specified private key.
'//
'//  If the SignatureAlgorithm is a hash algorithm, then, the signature
'//  contains the hash octets. A private key isn't used to encrypt the hash.
'//  dwKeySpec isn't used and hCryptProv can be NULL where an appropriate
'//  default provider will be used for hashing.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSignAndEncodeCertificate LIB "Crypt32.dll" _
    ALIAS "CryptSignAndEncodeCertificate" ( _
    BYVAL hCryptProvOrNCryptKey AS DWORD, _  ' HCRYPTPROV_OR_NCRYPT_KEY_HANDLE
    BYVAL dwKeySpec             AS DWORD, _  ' not applicable for NCRYPT_KEY_HANDLE
    BYVAL dwCertEncodingType    AS DWORD, _
    lpszStructType              AS ASCIIZ, _ ' "to be signed"
    pvStructInfo                AS ANY, _    ' void *
    pSignatureAlgorithm         AS CRYPT_ALGORITHM_IDENTIFIER, _
    pvHashAuxInfo               AS ANY, _    ' void *
    BYVAL pbEncoded             AS BYTE PTR, _
    pcbEncoded                  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptSignAndEncodeCertificate IMPORT "CRYPT32.DLL" ALIAS "CryptSignAndEncodeCertificate" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF lpszStructType AS ASCIIZ _                     ' __in LPCSTR lpszStructType
 , BYREF pvStructInfo AS ANY _                          ' __in const void *pvStructInfo
 , BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
 , BYVAL pvHashAuxInfo AS DWORD _                       ' __in_opt const void *pvHashAuxInfo
 , BYVAL pbEncoded AS DWORD _                           ' __out PBYTE pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate and CryptMsg encoded signature OID installable functions
'//--------------------------------------------------------------------------


'// The dwCertEncodingType and pSignatureAlgorithm->pszObjId are used
'// to call the signature OID installable functions.
'//
'// If the OID installable function doesn't support the signature,
'// it should return FALSE with LastError set to ERROR_NOT_SUPPORTED.


'// Called if the signature has encoded parameters. Returns the CNG
'// hash algorithm identifier string. Optionally returns the decoded
'// signature parameters passed to either the SignAndEncodeHash or
'// VerifyEncodedSignature OID installable function.
'//
'// Returned allocated parameters are freed via LocalFree().
$CRYPT_OID_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC = "CryptDllExtractEncodedSignatureParameters"
'typedef BOOL (WINAPI *PFN_CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC)(
'    __in DWORD dwCertEncodingType,
'    __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
'    __deref_out_opt void **ppvDecodedSignPara, // LocalFree()
'    __deref_out LPWSTR *ppwszCNGHashAlgid      // LocalFree()
'    );

'FUNCTION CRYPT_EXTRACT_ENCODED_SIGNATURE_PARAMETERS_FUNC ( _
'   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
' , BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
' , BYREF ppvDecodedSignPara AS DWORD _                  ' __deref_out_opt void **ppvDecodedSignPara // LocalFree()
' , BYREF ppwszCNGHashAlgid AS DWORD _                   ' __deref_out LPWSTR *ppwszCNGHashAlgid     // LocalFree()
' ) AS LONG                                              ' BOOL

'// Called to sign the computed hash and encode it.
$CRYPT_OID_SIGN_AND_ENCODE_HASH_FUNC = "CryptDllSignAndEncodeHash"
'typedef BOOL (WINAPI *PFN_CRYPT_SIGN_AND_ENCODE_HASH_FUNC)(
'    __in NCRYPT_KEY_HANDLE hKey,
'    __in DWORD dwCertEncodingType,
'    __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
'    __in_opt void *pvDecodedSignPara,
'    __in LPCWSTR pwszCNGPubKeyAlgid,    // obtained from signature OID
'    __in LPCWSTR pwszCNGHashAlgid,
'    __in_bcount(cbComputedHash) BYTE *pbComputedHash,
'    __in DWORD cbComputedHash,
'    __out_bcount_part_opt(*pcbSignature, *pcbSignature) BYTE *pbSignature,
'    __inout DWORD *pcbSignature
'    );

'FUNCTION CRYPT_SIGN_AND_ENCODE_HASH_FUNC ( _
'   BYVAL hKey AS DWORD _                                ' __in NCRYPT_KEY_HANDLE hKey
' , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
' , BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
' , BYVAL pvDecodedSignPara AS DWORD _                   ' __in_opt void *pvDecodedSignPara
' , BYREF pwszCNGPubKeyAlgid AS WSTRINGZ _               ' __in LPCWSTR pwszCNGPubKeyAlgid    // obtained from signature OID
' , BYREF pwszCNGHashAlgid AS WSTRINGZ _                 ' __in LPCWSTR pwszCNGHashAlgid
' , BYVAL pbComputedHash AS BYTE PTR _                   ' __in_bcount(cbComputedHash) BYTE *pbComputedHash
' , BYVAL cbComputedHash AS DWORD _                      ' __in DWORD cbComputedHash
' , BYREF pbSignature AS DWORD _                         ' __out_bcount_part_opt(*pcbSignature, *pcbSignature) BYTE *pbSignature
' , BYREF pcbSignature AS DWORD _                        ' __inout DWORD *pcbSignature
' ) AS LONG                                              ' BOOL

'// Called to decode and decrypt the encoded signature and compare it with the
'// computed hash.
$CRYPT_OID_VERIFY_ENCODED_SIGNATURE_FUNC = "CryptDllVerifyEncodedSignature"
'typedef BOOL (WINAPI *PFN_CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC)(
'    __in DWORD dwCertEncodingType,
'    __in PCERT_PUBLIC_KEY_INFO pPubKeyInfo,
'    __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
'    __in_opt void *pvDecodedSignPara,
'    __in LPCWSTR pwszCNGPubKeyAlgid,    // obtained from signature OID
'    __in LPCWSTR pwszCNGHashAlgid,
'    __in_bcount(cbComputedHash) BYTE *pbComputedHash,
'    __in DWORD cbComputedHash,
'    __in_bcount(cbSignature) BYTE *pbSignature,
'    __in DWORD cbSignature
'    );

'FUNCTION CRYPT_VERIFY_ENCODED_SIGNATURE_FUNC ( _
'   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
' , BYREF pPubKeyInfo AS CERT_PUBLIC_KEY_INFO _          ' __in PCERT_PUBLIC_KEY_INFO pPubKeyInfo
' , BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __in PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
' , BYVAL pvDecodedSignPara AS DWORD _                   ' __in_opt void *pvDecodedSignPara
' , BYREF pwszCNGPubKeyAlgid AS WSTRINGZ _               ' __in LPCWSTR pwszCNGPubKeyAlgid    // obtained from signature OID
' , BYREF pwszCNGHashAlgid AS WSTRINGZ _                 ' __in LPCWSTR pwszCNGHashAlgid
' , BYVAL pbComputedHash AS BYTE PTR _                   ' __in_bcount(cbComputedHash) BYTE *pbComputedHash
' , BYVAL cbComputedHash AS DWORD _                      ' __in DWORD cbComputedHash
' , BYREF pbSignature AS DWORD _                         ' __in_bcount(cbSignature) BYTE *pbSignature
' , BYVAL cbSignature AS DWORD _                         ' __in DWORD cbSignature
' ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify the time validity of a certificate.
'//
'//  Returns -1 if before NotBefore, +1 if after NotAfter and otherwise 0 for
'//  a valid certificate
'//
'//  If pTimeToVerify is NULL, uses the current time.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyTimeValidity IMPORT "CRYPT32.DLL" ALIAS "CertVerifyTimeValidity" ( _
   BYREF pTimeToVerify AS FILETIME _                    ' __in LPFILETIME pTimeToVerify
 , BYREF pCertInfo AS CERT_INFO _                       ' __in PCERT_INFO pCertInfo
 ) AS LONG                                              ' LONG

'//+-------------------------------------------------------------------------
'//  Verify the time validity of a CRL.
'//
'//  Returns -1 if before ThisUpdate, +1 if after NextUpdate and otherwise 0 for
'//  a valid CRL
'//
'//  If pTimeToVerify is NULL, uses the current time.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyCRLTimeValidity IMPORT "CRYPT32.DLL" ALIAS "CertVerifyCRLTimeValidity" ( _
   BYREF pTimeToVerify AS FILETIME _                    ' __in LPFILETIME pTimeToVerify
 , BYREF pCrlInfo AS CRL_INFO _                         ' __in PCRL_INFO pCrlInfo
 ) AS LONG                                              ' LONG

'//+-------------------------------------------------------------------------
'//  Verify that the subject's time validity nests within the issuer's time
'//  validity.
'//
'//  Returns TRUE if it nests. Otherwise, returns FALSE.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyValidityNesting IMPORT "CRYPT32.DLL" ALIAS "CertVerifyValidityNesting" ( _
   BYREF pSubjectInfo AS CERT_INFO _                    ' __in PCERT_INFO pSubjectInfo
 , BYREF pIssuerInfo AS CERT_INFO _                     ' __in PCERT_INFO pIssuerInfo
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify that the subject certificate isn't on its issuer CRL.
'//
'//  Returns true if the certificate isn't on the CRL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyCRLRevocation IMPORT "CRYPT32.DLL" ALIAS "CertVerifyCRLRevocation" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pCertId AS CERT_INFO _                         ' __in PCERT_INFO pCertId
 , BYVAL cCrlInfo AS DWORD _                            ' __in DWORD cCrlInfo
 , BYREF rgpCrlInfo AS CRL_INFO _                       ' __in PCRL_INFO rgpCrlInfo[]
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Convert the CAPI AlgId to the ASN.1 Object Identifier string
'//
'//  Returns NULL if there isn't an ObjId corresponding to the AlgId.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertAlgIdToOID IMPORT "CRYPT32.DLL" ALIAS "CertAlgIdToOID" ( _
   BYVAL dwAlgId AS DWORD _                             ' __in DWORD dwAlgId
 ) AS DWORD                                             ' LPCSTR

'//+-------------------------------------------------------------------------
'//  Convert the ASN.1 Object Identifier string to the CAPI AlgId.
'//
'//  Returns 0 if there isn't an AlgId corresponding to the ObjId.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertOIDToAlgId IMPORT "CRYPT32.DLL" ALIAS "CertOIDToAlgId" ( _
   BYREF pszObjId AS ASCIIZ _                           ' __in LPCSTR pszObjId
 ) AS DWORD                                             ' DWORD

'//+-------------------------------------------------------------------------
'//  Find an extension identified by its Object Identifier.
'//
'//  If found, returns pointer to the extension. Otherwise, returns NULL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertFindExtension IMPORT "CRYPT32.DLL" ALIAS "CertFindExtension" ( _
   BYREF pszObjId AS ASCIIZ _                           ' __in LPCSTR pszObjId
 , BYVAL cExtensions AS DWORD _                         ' __in DWORD cExtensions
 , BYREF rgExtensions AS CERT_EXTENSION _               ' __in CERT_EXTENSION rgExtensions[]
 ) AS DWORD                                             ' PCERT_EXTENSION

'//+-------------------------------------------------------------------------
'//  Find the first attribute identified by its Object Identifier.
'//
'//  If found, returns pointer to the attribute. Otherwise, returns NULL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertFindAttribute IMPORT "CRYPT32.DLL" ALIAS "CertFindAttribute" ( _
   BYREF pszObjId AS ASCIIZ _                           ' __in LPCSTR pszObjId
 , BYVAL cAttr AS DWORD _                               ' __in DWORD cAttr
 , BYREF rgAttr AS CRYPT_ATTRIBUTE _                    ' __in CRYPT_ATTRIBUTE rgAttr[]
 ) AS DWORD                                             ' PCRYPT_ATTRIBUTE

'//+-------------------------------------------------------------------------
'//  Find the first CERT_RDN attribute identified by its Object Identifier in
'//  the name's list of Relative Distinguished Names.
'//
'//  If found, returns pointer to the attribute. Otherwise, returns NULL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertFindRDNAttr IMPORT "CRYPT32.DLL" ALIAS "CertFindRDNAttr" ( _
   BYREF pszObjId AS ASCIIZ _                           ' __in LPCSTR pszObjId
 , BYREF pName AS CERT_NAME_INFO _                      ' __in PCERT_NAME_INFO pName
 ) AS DWORD                                             ' PCERT_RDN_ATTR

'//+-------------------------------------------------------------------------
'//  Get the intended key usage bytes from the certificate.
'//
'//  If the certificate doesn't have any intended key usage bytes, returns FALSE
'//  and *pbKeyUsage is zeroed. Otherwise, returns TRUE and up through
'//  cbKeyUsage bytes are copied into *pbKeyUsage. Any remaining uncopied
'//  bytes are zeroed.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertGetIntendedKeyUsage IMPORT "CRYPT32.DLL" ALIAS "CertGetIntendedKeyUsage" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pCertInfo AS CERT_INFO _                       ' __in PCERT_INFO pCertInfo
 , BYVAL pbKeyUsage AS BYTE PTR _                       ' __out BYTE *pbKeyUsage
 , BYVAL cbKeyUsage AS DWORD _                          ' __in DWORD cbKeyUsage
 ) AS LONG                                              ' BOOL

'typedef void *HCRYPTDEFAULTCONTEXT;

'//+-------------------------------------------------------------------------
'//  Install a previously CryptAcquiredContext'ed HCRYPTPROV to be used as
'//  a default context.
'//
'//  dwDefaultType and pvDefaultPara specify where the default context is used.
'//  For example, install the HCRYPTPROV to be used to verify certificate's
'//  having szOID_OIWSEC_md5RSA signatures.
'//
'//  By default, the installed HCRYPTPROV is only applicable to the current
'//  thread. Set CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG to allow the HCRYPTPROV
'//  to be used by all threads in the current process.
'//
'//  For a successful install, TRUE is returned and *phDefaultContext is
'//  updated with the HANDLE to be passed to CryptUninstallDefaultContext.
'//
'//  The installed HCRYPTPROVs are stack ordered (the last installed
'//  HCRYPTPROV is checked first). All thread installed HCRYPTPROVs are
'//  checked before any process HCRYPTPROVs.
'//
'//  The installed HCRYPTPROV remains available for default usage until
'//  CryptUninstallDefaultContext is called or the thread or process exits.
'//
'//  If CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG is set, then, the HCRYPTPROV
'//  is CryptReleaseContext'ed at thread or process exit. However,
'//  not CryptReleaseContext'ed if CryptUninstallDefaultContext is
'//  called.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptInstallDefaultContext LIB "Crypt32.dll" _
    ALIAS "CryptInstallDefaultContext" ( _
    BYVAL hCryptProv    AS DWORD, _  ' HCRYPTPROV
    BYVAL dwDefaultType AS DWORD, _
    pvDefaultPara       AS ANY, _    ' void *
    BYVAL dwFlags       AS DWORD, _
    pvReserved          AS ANY, _    ' void *
    phDefaultContext    AS DWORD _   ' HCRYPTDEFAULTCONTEXT PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptInstallDefaultContext IMPORT "CRYPT32.DLL" ALIAS "CryptInstallDefaultContext" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwDefaultType AS DWORD _                       ' __in DWORD dwDefaultType
 , BYREF pvDefaultPara AS ANY _                         ' __in const void *pvDefaultPara
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 , BYREF phDefaultContext AS DWORD _                    ' __out HCRYPTDEFAULTCONTEXT *phDefaultContext
 ) AS LONG                                              ' BOOL
#ENDIF

'// dwFlags
%CRYPT_DEFAULT_CONTEXT_AUTO_RELEASE_FLAG   = &H00000001???
%CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG        = &H00000002???

'// List of dwDefaultType's
%CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID       = 1???
%CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID = 2???


'//+-------------------------------------------------------------------------
'//  CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID
'//
'//  Install a default HCRYPTPROV used to verify a certificate
'//  signature. pvDefaultPara points to the szOID of the certificate
'//  signature algorithm, for example, szOID_OIWSEC_md5RSA. If
'//  pvDefaultPara is NULL, then, the HCRYPTPROV is used to verify all
'//  certificate signatures. Note, pvDefaultPara can't be NULL when
'//  CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG is set.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CRYPT_DEFAULT_CONTEXT_MULTI_CERT_SIGN_OID
'//
'//  Same as CRYPT_DEFAULT_CONTEXT_CERT_SIGN_OID. However, the default
'//  HCRYPTPROV is to be used for multiple signature szOIDs. pvDefaultPara
'//  points to a CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA structure containing
'//  an array of szOID pointers.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE CRYPT_DEFAULT_CONTEXT_MULTI_OID_PARA DWORD
   cOID     AS DWORD        ' DWORD
   rgpszOID AS ASCIIZ PTR   ' LPSTR*
END TYPE

'//+-------------------------------------------------------------------------
'//  Uninstall a default context previously installed by
'//  CryptInstallDefaultContext.
'//
'//  For a default context installed with CRYPT_DEFAULT_CONTEXT_PROCESS_FLAG
'//  set, if any other threads are currently using this context,
'//  this function will block until they finish.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptUninstallDefaultContext LIB "Crypt32.dll" _
    ALIAS "CryptUninstallDefaultContext" ( _
    BYVAL hDefaultContext AS DWORD, _  ' HCRYPTDEFAULTCONTEXT
    BYVAL dwFlags         AS DWORD, _
    pvReserved            AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptUninstallDefaultContext IMPORT "CRYPT32.DLL" ALIAS "CryptUninstallDefaultContext" ( _
   BYVAL hDefaultContext AS DWORD _                     ' __in HCRYPTDEFAULTCONTEXT hDefaultContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Export the public key info associated with the provider's corresponding
'//  private key.
'//
'//  Calls CryptExportPublicKeyInfoEx with pszPublicKeyObjId = NULL,
'//  dwFlags = 0 and pvAuxInfo = NULL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptExportPublicKeyInfo IMPORT "CRYPT32.DLL" ALIAS "CryptExportPublicKeyInfo" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __out PCERT_PUBLIC_KEY_INFO pInfo
 , BYREF pcbInfo AS DWORD _                             ' __inout DWORD *pcbInfo
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Export the public key info associated with the provider's corresponding
'//  private key.
'//
'//  Uses the dwCertEncodingType and pszPublicKeyObjId to call the
'//  installable CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC. The called function
'//  has the same signature as CryptExportPublicKeyInfoEx.
'//
'//  If unable to find an installable OID function for the pszPublicKeyObjId,
'//  attempts to export as a RSA Public Key (szOID_RSA_RSA).
'//
'//  The dwFlags and pvAuxInfo aren't used for szOID_RSA_RSA.
'//--------------------------------------------------------------------------
$CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC = "CryptDllExportPublicKeyInfoEx"

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptExportPublicKeyInfoEx LIB "Crypt32.dll" _
    ALIAS "CryptExportPublicKeyInfoEx" ( _
    BYVAL hCryptProvOrNCryptKey AS DWORD, _  ' HCRYPTPROV_OR_NCRYPT_KEY_HANDLE
    BYVAL dwKeySpec             AS DWORD, _  ' not applicable for NCRYPT_KEY_HANDLE
    BYVAL dwCertEncodingType    AS DWORD, _
    pszPublicKeyObjId           AS ASCIIZ, _
    BYVAL dwFlags               AS DWORD, _
    pvAuxInfo                   AS ANY, _    ' void *
    pInfo                       AS CERT_PUBLIC_KEY_INFO, _
    pcbInfo                     AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptExportPublicKeyInfoEx IMPORT "CRYPT32.DLL" ALIAS "CryptExportPublicKeyInfoEx" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pszPublicKeyObjId AS ASCIIZ _                  ' __in LPSTR pszPublicKeyObjId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __out PCERT_PUBLIC_KEY_INFO pInfo
 , BYREF pcbInfo AS DWORD _                             ' __inout DWORD *pcbInfo
 ) AS LONG                                              ' BOOL
#ENDIF

'// Legacy define used for exporting CAPI1 HCRYPTPROV public keys.
$CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FUNC = "CryptDllExportPublicKeyInfoEx"

'//+-------------------------------------------------------------------------
'//  Export CNG PublicKeyInfo OID installable function. Note, not called
'//  for a HCRYPTPROV choice.
'//--------------------------------------------------------------------------
$CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC = "CryptDllExportPublicKeyInfoEx2"
'typedef BOOL (WINAPI *PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC) (
'    __in NCRYPT_KEY_HANDLE hNCryptKey,
'    __in DWORD dwCertEncodingType,
'    __in LPSTR pszPublicKeyObjId,
'    __in DWORD dwFlags,
'    __in_opt void *pvAuxInfo,
'    __out_bcount_part_opt(*pcbInfo, *pcbInfo) PCERT_PUBLIC_KEY_INFO pInfo,
'    __inout DWORD *pcbInfo
'    );

'FUNCTION CRYPT_EXPORT_PUBLIC_KEY_INFO_EX2_FUNC ( _
'   BYVAL hNCryptKey AS DWORD _                          ' __in NCRYPT_KEY_HANDLE hNCryptKey
' , BYVAL dwCertEncodingType As DWORD _                  ' __in DWORD dwCertEncodingType
' , BYREF pszPublicKeyObjId AS ASCIIZ _                  ' __in LPSTR pszPublicKeyObjId
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
' , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __out_bcount_part_opt(*pcbInfo, *pcbInfo) PCERT_PUBLIC_KEY_INFO pInfo
' , BYREF pcbInfo AS DWORD _                             ' __inout DWORD *pcbInfo
' ) AS LONG                                              ' BOOL

'#if (NTDDI_VERSION >= NTDDI_WIN7)

'//+-------------------------------------------------------------------------
'//  Export the public key info associated with the provider's corresponding
'//  private key.
'//
'//  Uses the dwCertEncodingType and pszPublicKeyObjId to call the
'//  installable CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC. The
'//  called function has the same signature as
'//  CryptExportPublicKeyInfoFromBCryptKeyHandle.
'//
'//  If unable to find an installable OID function for the pszPublicKeyObjId,
'//  attempts to export as a RSA Public Key (szOID_RSA_RSA).
'//
'//  The dwFlags and pvAuxInfo aren't used for szOID_RSA_RSA.
'//
'//  In addition dwFlags can be set with the following 2 flags passed directly
'//  to CryptFindOIDInfo:
'//      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG
'//      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptExportPublicKeyInfoFromBCryptKeyHandle IMPORT "CRYPT32.DLL" ALIAS "CryptExportPublicKeyInfoFromBCryptKeyHandle" ( _
   BYVAL hBCryptKey AS DWORD _                          ' __in BCRYPT_KEY_HANDLE hBCryptKey
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pszPublicKeyObjId AS ASCIIZ _                  ' __in_opt LPSTR pszPublicKeyObjId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __out PCERT_PUBLIC_KEY_INFO pInfo
 , BYREF pcbInfo AS DWORD _                             ' __inout DWORD *pcbInfo
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Export CNG PublicKeyInfo OID installable function. Note, not called
'//  for a HCRYPTPROV or NCRYPT_KEY_HANDLE choice.
'//--------------------------------------------------------------------------
$CRYPT_OID_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC = "CryptDllExportPublicKeyInfoFromBCryptKeyHandle"
'typedef BOOL (WINAPI *PFN_CRYPT_EXPORT_PUBLIC_KEY_INFO_FROM_BCRYPT_HANDLE_FUNC) (
'    __in BCRYPT_KEY_HANDLE hBCryptKey,
'    __in DWORD dwCertEncodingType,
'    __in LPSTR pszPublicKeyObjId,
'    __in DWORD dwFlags,
'    __in_opt void *pvAuxInfo,
'    __out_bcount_part_opt(*pcbInfo, *pcbInfo) PCERT_PUBLIC_KEY_INFO pInfo,
'    __inout DWORD *pcbInfo
'    );

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'//+-------------------------------------------------------------------------
'//  Convert and import the public key info into the provider and return a
'//  handle to the public key.
'//
'//  Calls CryptImportPublicKeyInfoEx with aiKeyAlg = 0, dwFlags = 0 and
'//  pvAuxInfo = NULL.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptImportPublicKeyInfo IMPORT "CRYPT32.DLL" ALIAS "CryptImportPublicKeyInfo" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __in PCERT_PUBLIC_KEY_INFO pInfo
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Convert and import the public key info into the provider and return a
'//  handle to the public key.
'//
'//  Uses the dwCertEncodingType and pInfo->Algorithm.pszObjId to call the
'//  installable CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC. The called function
'//  has the same signature as CryptImportPublicKeyInfoEx.
'//
'//  If unable to find an installable OID function for the pszObjId,
'//  attempts to import as a RSA Public Key (szOID_RSA_RSA).
'//
'//  For szOID_RSA_RSA: aiKeyAlg may be set to CALG_RSA_SIGN or CALG_RSA_KEYX.
'//  Defaults to CALG_RSA_KEYX. The dwFlags and pvAuxInfo aren't used.
'//--------------------------------------------------------------------------
$CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_FUNC = "CryptDllImportPublicKeyInfoEx"

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptImportPublicKeyInfoEx LIB "Crypt32.dll" _
    ALIAS "CryptImportPublicKeyInfoEx" ( _
    BYVAL hCryptProv         AS DWORD, _ ' HCRYPTPROV
    BYVAL dwCertEncodingType AS DWORD, _
    pInfo                    AS CERT_PUBLIC_KEY_INFO, _
    BYVAL aiKeyAlg           AS DWORD, _
    BYVAL dwFlags            AS DWORD, _
    pvAuxInfo                AS ANY, _
    phKey                    AS DWORD _  ' HCRYPTKEY PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptImportPublicKeyInfoEx IMPORT "CRYPT32.DLL" ALIAS "CryptImportPublicKeyInfoEx" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __in PCERT_PUBLIC_KEY_INFO pInfo
 , BYVAL aiKeyAlg AS DWORD _                            ' __in ALG_ID aiKeyAlg
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Convert and import the public key info into the CNG asymmetric or
'//  signature algorithm provider and return a BCRYPT_KEY_HANDLE to it.
'//
'//  Uses the dwCertEncodingType and pInfo->Algorithm.pszObjId to call the
'//  installable CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC. The called function
'//  has the same signature as CryptImportPublicKeyInfoEx2.
'//
'//  dwFlags can be set with the following 2 flags passed directly to
'//  CryptFindOIDInfo:
'//      CRYPT_OID_INFO_PUBKEY_SIGN_KEY_FLAG
'//      CRYPT_OID_INFO_PUBKEY_ENCRYPT_KEY_FLAG
'//  dwFlags can also have BCRYPT_NO_KEY_VALIDATION OR'd in. This flag is
'//  passed to BCryptImportKeyPair.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptImportPublicKeyInfoEx2 LIB "Crypt32.dll" _
    ALIAS "CryptImportPublicKeyInfoEx2" ( _
    BYVAL dwCertEncodingType AS DWORD, _
    pInfo                    AS CERT_PUBLIC_KEY_INFO, _
    BYVAL dwFlags            AS DWORD, _
    pvAuxInfo                AS ANY, _   ' void *
    phKey                    AS DWORD _  ' BCRYPT_KEY_HANDLE PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptImportPublicKeyInfoEx2 IMPORT "CRYPT32.DLL" ALIAS "CryptImportPublicKeyInfoEx2" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __in PCERT_PUBLIC_KEY_INFO pInfo
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
 , BYREF phKey AS DWORD _                               ' __out HCRYPTKEY *phKey
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Import CNG PublicKeyInfo OID installable function
'//--------------------------------------------------------------------------
$CRYPT_OID_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC = "CryptDllImportPublicKeyInfoEx2"
'typedef BOOL (WINAPI *PFN_IMPORT_PUBLIC_KEY_INFO_EX2_FUNC) (
'    __in DWORD dwCertEncodingType,
'    __in PCERT_PUBLIC_KEY_INFO pInfo,
'    __in DWORD dwFlags,
'    __in_opt void *pvAuxInfo,
'    __out BCRYPT_KEY_HANDLE *phKey
'    );

'#endif // (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Acquire a HCRYPTPROV handle and dwKeySpec for the specified certificate
'//  context. Uses the certificate's CERT_KEY_PROV_INFO_PROP_ID property.
'//  The returned HCRYPTPROV handle may optionally be cached using the
'//  certificate's CERT_KEY_CONTEXT_PROP_ID property.
'//
'//  If CRYPT_ACQUIRE_CACHE_FLAG is set, then, if an already acquired and
'//  cached HCRYPTPROV exists for the certificate, its returned. Otherwise,
'//  a HCRYPTPROV is acquired and then cached via the certificate's
'//  CERT_KEY_CONTEXT_PROP_ID.
'//
'//  The CRYPT_ACQUIRE_USE_PROV_INFO_FLAG can be set to use the dwFlags field of
'//  the certificate's CERT_KEY_PROV_INFO_PROP_ID property's CRYPT_KEY_PROV_INFO
'//  data structure to determine if the returned HCRYPTPROV should be cached.
'//  HCRYPTPROV caching is enabled if the CERT_SET_KEY_CONTEXT_PROP_ID flag was
'//  set.
'//
'//  If CRYPT_ACQUIRE_COMPARE_KEY_FLAG is set, then,
'//  the public key in the certificate is compared with the public
'//  key returned by the cryptographic provider. If the keys don't match, the
'//  acquire fails and LastError is set to NTE_BAD_PUBLIC_KEY. Note, if
'//  a cached HCRYPTPROV is returned, the comparison isn't done. We assume the
'//  comparison was done on the initial acquire.
'//
'//  The CRYPT_ACQUIRE_SILENT_FLAG can be set to suppress any UI by the CSP.
'//  See CryptAcquireContext's CRYPT_SILENT flag for more details.
'//
'//  *pfCallerFreeProv is returned set to FALSE for:
'//    - Acquire or public key comparison fails.
'//    - CRYPT_ACQUIRE_CACHE_FLAG is set.
'//    - CRYPT_ACQUIRE_USE_PROV_INFO_FLAG is set AND
'//      CERT_SET_KEY_CONTEXT_PROP_ID flag is set in the dwFlags field of the
'//      certificate's CERT_KEY_PROV_INFO_PROP_ID property's
'//      CRYPT_KEY_PROV_INFO data structure.
'//  When *pfCallerFreeProv is FALSE, the caller must not release. The
'//  returned HCRYPTPROV will be released on the last free of the certificate
'//  context.
'//
'//  Otherwise, *pfCallerFreeProv is TRUE and the returned HCRYPTPROV must
'//  be released by the caller by calling CryptReleaseContext.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptAcquireCertificatePrivateKey LIB "Crypt32.dll" _
    ALIAS "CryptAcquireCertificatePrivateKey" ( _
    pCert                       AS CERT_CONTEXT, _
    BYVAL dwFlags               AS DWORD, _
    pvReserved                  AS ANY, _
    phCryptProvOrNCryptKey      AS DWORD, _  ' HCRYPTPROV_OR_NCRYPT_KEY_HANDLE PTR
    pdwKeySpec                  AS DWORD, _
    pfCallerFreeProvOrNCryptKey AS LONG _    ' BOOL PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptAcquireCertificatePrivateKey IMPORT "CRYPT32.DLL" ALIAS "CryptAcquireCertificatePrivateKey" ( _
   BYVAL pCert AS CERT_CONTEXT PTR _                    ' __in PCCERT_CONTEXT pCert
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 , BYREF phCryptProv AS DWORD _                         ' __out HCRYPTPROV *phCryptProv
 , OPTIONAL BYREF pdwKeySpec AS DWORD _                 ' __out_opt DWORD *pdwKeySpec
 , OPTIONAL BYREF pfCallerFreeProv AS LONG _            ' __out_opt BOOL *pfCallerFreeProv
 ) AS LONG                                              ' BOOL
#ENDIF

%CRYPT_ACQUIRE_CACHE_FLAG                = &H00000001???
%CRYPT_ACQUIRE_USE_PROV_INFO_FLAG        = &H00000002???
%CRYPT_ACQUIRE_COMPARE_KEY_FLAG          = &H00000004???
%CRYPT_ACQUIRE_NO_HEALING                = &H00000008???

%CRYPT_ACQUIRE_SILENT_FLAG               = &H00000040???

%CRYPT_ACQUIRE_NCRYPT_KEY_FLAGS_MASK     = &H00070000???
%CRYPT_ACQUIRE_ALLOW_NCRYPT_KEY_FLAG     = &H00010000???
%CRYPT_ACQUIRE_PREFER_NCRYPT_KEY_FLAG    = &H00020000???
%CRYPT_ACQUIRE_ONLY_NCRYPT_KEY_FLAG      = &H00040000???

'//+-------------------------------------------------------------------------
'//  Enumerates the cryptographic providers and their containers to find the
'//  private key corresponding to the certificate's public key. For a match,
'//  the certificate's CERT_KEY_PROV_INFO_PROP_ID property is updated.
'//
'//  If the CERT_KEY_PROV_INFO_PROP_ID is already set, then, its checked to
'//  see if it matches the provider's public key. For a match, the above
'//  enumeration is skipped.
'//
'//  By default both the user and machine key containers are searched.
'//  The CRYPT_FIND_USER_KEYSET_FLAG or CRYPT_FIND_MACHINE_KEYSET_FLAG
'//  can be set in dwFlags to restrict the search to either of the containers.
'//
'//  The CRYPT_FIND_SILENT_KEYSET_FLAG can be set to suppress any UI by the CSP.
'//  See CryptAcquireContext's CRYPT_SILENT flag for more details.
'//
'//  If a container isn't found, returns FALSE with LastError set to
'//  NTE_NO_KEY.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptFindCertificateKeyProvInfo LIB "Crypt32.dll" _
    ALIAS "CryptFindCertificateKeyProvInfo" ( _
    pCert         AS CERT_CONTEXT, _
    BYVAL dwFlags AS DWORD, _
    pvReserved    AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptFindCertificateKeyProvInfo IMPORT "CRYPT32.DLL" ALIAS "CryptFindCertificateKeyProvInfo" ( _
   BYVAL pCert AS CERT_CONTEXT PTR _                    ' __in PCCERT_CONTEXT pCert
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

%CRYPT_FIND_USER_KEYSET_FLAG        = &H00000001???
%CRYPT_FIND_MACHINE_KEYSET_FLAG     = &H00000002???
%CRYPT_FIND_SILENT_KEYSET_FLAG      = &H00000040???


'//+-------------------------------------------------------------------------
'//  This is the prototype for the installable function which is called to
'//  actually import a key into a CSP.  an installable of this type is called
'//  from CryptImportPKCS8.  the algorithm OID of the private key is used
'//  to look up the proper installable function to call.
'//
'//  hCryptProv - the provider to import the key to
'//  pPrivateKeyInfo - describes the key to be imported
'//  dwFlags - The available flags are:
'//              CRYPT_EXPORTABLE
'//              this flag is used when importing private keys, for a full
'//              explanation please see the documentation for CryptImportKey.
'//  pvAuxInfo - reserved for future, must be NULL
'//--------------------------------------------------------------------------
'typedef BOOL (WINAPI *PFN_IMPORT_PRIV_KEY_FUNC) (
'    HCRYPTPROV              hCryptProv,         // in
'    CRYPT_PRIVATE_KEY_INFO  *pPrivateKeyInfo,   // in
'    DWORD                   dwFlags,            // in, optional
'    void                    *pvAuxInfo          // in, optional
'    );

'FUNCTION IMPORT_PRIV_KEY_FUNC ( _
'   BYVAL hCryptProv AS DWORD, _                         ' HCRYPTPROV              hCryptProv
'   BYREF pPrivateKeyInfo AS CRYPT_PRIVATE_KEY_INFO, _   ' CRYPT_PRIVATE_KEY_INFO  *pPrivateKeyInfo
'   BYVAL dwFlags AS DWORD, _                            ' DWORD                   dwFlags
'   BYVAL pvAuxInfo AS DWORD _                           ' void                    *pvAuxInfo
' ) AS LONG                                              ' BOOL

$CRYPT_OID_IMPORT_PRIVATE_KEY_INFO_FUNC = "CryptDllImportPrivateKeyInfoEx"

'//+-------------------------------------------------------------------------
'// Convert (from PKCS8 format) and import the private key into a provider
'// and return a handle to the provider as well as the KeySpec used to import to.
'//
'// This function will call the PRESOLVE_HCRYPTPROV_FUNC in the
'// privateKeyAndParams to obtain a handle of provider to import the key to.
'// if the PRESOLVE_HCRYPTPROV_FUNC is NULL then the default provider will be used.
'//
'// privateKeyAndParams - private key blob and corresponding parameters
'// dwFlags - The available flags are:
'//              CRYPT_EXPORTABLE
'//              this flag is used when importing private keys, for a full
'//              explanation please see the documentation for CryptImportKey.
'// phCryptProv - filled in with the handle of the provider the key was
'//               imported to, the caller is responsible for freeing it
'// pvAuxInfo - This parameter is reserved for future use and should be set
'//             to NULL in the interim.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptImportPKCS8 LIB "Crypt32.dll" _
    ALIAS "CryptImportPKCS8" ( _
    BYVAL sPrivateKeyAndParams AS CRYPT_PKCS8_IMPORT_PARAMS, _   ' in
    BYVAL dwFlags AS DWORD, _  ' in
    phCryptProv   AS DWORD, _  ' HCRYPTPROV PTR  ' out, optional
    pvAuxInfo     AS ANY _     ' void *  ' in, optional
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptImportPKCS8 IMPORT "CRYPT32.DLL" ALIAS "CryptImportPKCS8" ( _
   BYREF sImportParams AS CRYPT_PKCS8_IMPORT_PARAMS _   ' __in CRYPT_PKCS8_IMPORT_PARAMS sImportParams
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD                     dwFlags
 , BYREF phCryptProv AS DWORD _                         ' __out_opt HCRYPTPROV           *phCryptProv
 , OPTIONAL BYVAL pvAuxInfo AS DWORD _                  ' __in_opt void                  *pvAuxInfo
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'// this is the prototype for installable functions for exporting the private key
'//--------------------------------------------------------------------------
'typedef BOOL (WINAPI *PFN_EXPORT_PRIV_KEY_FUNC) (
'    HCRYPTPROV              hCryptProv,         // in
'    DWORD                   dwKeySpec,          // in
'    LPSTR                   pszPrivateKeyObjId, // in
'    DWORD                   dwFlags,            // in
'    void                    *pvAuxInfo,         // in
'    CRYPT_PRIVATE_KEY_INFO  *pPrivateKeyInfo,   // out
'    DWORD                   *pcbPrivateKeyBlob  // in, out
'    );

'FUNCTION EXPORT_PRIV_KEY_FUNC ( _
'   BYVAL hCryptProv AS DWORD, _                         ' HCRYPTPROV              hCryptProv
'   BYVAL dwKeySpec AS DWORD, _                          ' DWORD                   dwKeySpec
'   BYREF pszPrivateKeyObjId AS ASCIIZ, _                ' LPSTR                   pszPrivateKeyObjId
'   BYVAL dwFlags AS DWORD, _                            ' DWORD                   dwFlags
'   BYVAL pvAuxInfo AS DWORD, _                          ' void                    *pvAuxInfo
'   BYREF pPrivateKeyInfo AS CRYPT_PRIVATE_KEY_INFO, _   ' CRYPT_PRIVATE_KEY_INFO  *pPrivateKeyInfo
'   BYVAL pcbPrivateKeyBlob AS DWORD _                   ' DWORD                   *pcbPrivateKeyBlob
' ) AS LONG                                              ' BOOL


$CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC = "CryptDllExportPrivateKeyInfoEx"

%CRYPT_DELETE_KEYSET = %CRYPT_DELETEKEYSET

'//+-------------------------------------------------------------------------
'//  CryptExportPKCS8 -- superseded by CryptExportPKCS8Ex
'//
'//  Export the private key in PKCS8 format
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptExportPKCS8 LIB "Crypt32.dll" _
    ALIAS "CryptExportPKCS8" ( _
    BYVAL hCryptProv       AS DWORD, _     ' HCRYPTPROV ' in
    BYVAL dwKeySpec        AS DWORD, _     ' in
    pszPrivateKeyObjId     AS ASCIIZ, _    ' in
    BYVAL dwFlags          AS DWORD, _     ' in
    pvAuxInfo              AS ANY, _       ' in
    BYVAL pbPrivateKeyBlob AS BYTE PTR, _  ' out
    pcbPrivateKeyBlob      AS DWORD _      ' in, out
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptExportPKCS8 IMPORT "CRYPT32.DLL" ALIAS "CryptExportPKCS8" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV  hCryptProv
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD       dwKeySpec
 , BYREF pszPrivateKeyObjId AS ASCIIZ _                 ' __in LPSTR       pszPrivateKeyObjId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD       dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void    *pvAuxInfo
 , BYVAL pbPrivateKeyBlob AS BYTE PTR _                 ' __out_opt BYTE   *pbPrivateKeyBlob
 , BYREF pcbPrivateKeyBlob AS DWORD _                   ' __inout DWORD    *pcbPrivateKeyBlob
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'// CryptExportPKCS8Ex
'//
'//  Export the private key in PKCS8 format
'//
'//
'//  Uses the pszPrivateKeyObjId to call the
'//  installable CRYPT_OID_EXPORT_PRIVATE_KEY_INFO_FUNC. The called function
'//  has the signature defined by PFN_EXPORT_PRIV_KEY_FUNC.
'//
'//  If unable to find an installable OID function for the pszPrivateKeyObjId,
'//  attempts to export as a RSA Private Key (szOID_RSA_RSA).
'//
'// psExportParams - specifies information about the key to export
'// dwFlags - The flag values. None currently supported
'// pvAuxInfo - This parameter is reserved for future use and should be set to
'//                         NULL in the interim.
'// pbPrivateKeyBlob - A pointer to the private key blob.  It will be encoded
'//                                        as a PKCS8 PrivateKeyInfo.
'// pcbPrivateKeyBlob - A pointer to a DWORD that contains the size, in bytes,
'//                                         of the private key blob being exported.
'//+-------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptExportPKCS8Ex LIB "Crypt32.dll" _
    ALIAS "CryptExportPKCS8Ex" ( _
    psExportParams         AS CRYPT_PKCS8_EXPORT_PARAMS, _   ' in
    BYVAL dwFlags          AS DWORD, _     ' in
    pvAuxInfo              AS ANY, _       ' in
    BYVAL pbPrivateKeyBlob AS BYTE PTR, _  ' out
    pcbPrivateKeyBlob      AS DWORD _      ' in, out
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptExportPKCS8Ex IMPORT "CRYPT32.DLL" ALIAS "CryptExportPKCS8Ex" ( _
   BYREF psExportParams AS CRYPT_PKCS8_EXPORT_PARAMS _  ' __in CRYPT_PKCS8_EXPORT_PARAMS* psExportParams
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvAuxInfo AS DWORD _                           ' __in_opt void *pvAuxInfo
 , BYVAL pbPrivateKeyBlob AS BYTE PTR _                 ' __out_opt BYTE *pbPrivateKeyBlob
 , BYREF pcbPrivateKeyBlob AS DWORD _                   ' __inout DWORD *pcbPrivateKeyBlob
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Compute the hash of the encoded public key info.
'//
'//  The public key info is encoded and then hashed.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptHashPublicKeyInfo IMPORT "CRYPT32.DLL" ALIAS "CryptHashPublicKeyInfo" ( _
   BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL Algid AS DWORD _                               ' __in ALG_ID Algid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pInfo AS CERT_PUBLIC_KEY_INFO _                ' __in PCERT_PUBLIC_KEY_INFO pInfo
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Convert a Name Value to a null terminated char string
'//
'//  Returns the number of characters converted including the terminating null
'//  character. If psz is NULL or csz is 0, returns the required size of the
'//  destination string (including the terminating null char).
'//
'//  If psz != NULL && csz != 0, returned psz is always NULL terminated.
'//
'//  Note: csz includes the NULL char.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertRDNValueToStrA IMPORT "CRYPT32.DLL" ALIAS "CertRDNValueToStrA" ( _
   BYVAL dwValueType AS DWORD _                         ' __in DWORD dwValueType
 , BYREF pValue AS CERT_RDN_VALUE_BLOB _                ' __in PCERT_RDN_VALUE_BLOB pValue
 , BYREF psz AS ASCIIZ _                                ' __out_opt LPSTR psz
 , BYVAL csz AS DWORD _                                 ' __in DWORD csz
 ) AS DWORD                                             ' DWORD

'//+-------------------------------------------------------------------------
'//  Convert a Name Value to a null terminated char string
'//
'//  Returns the number of characters converted including the terminating null
'//  character. If psz is NULL or csz is 0, returns the required size of the
'//  destination string (including the terminating null char).
'//
'//  If psz != NULL && csz != 0, returned psz is always NULL terminated.
'//
'//  Note: csz includes the NULL char.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertRDNValueToStrW IMPORT "CRYPT32.DLL" ALIAS "CertRDNValueToStrW" ( _
   BYVAL dwValueType AS DWORD _                         ' __in DWORD dwValueType
 , BYREF pValue AS CERT_RDN_VALUE_BLOB _                ' __in PCERT_RDN_VALUE_BLOB pValue
 , BYREF psz AS WSTRINGZ _                              ' __out_opt LPWSTR psz
 , BYVAL csz AS DWORD _                                 ' __in DWORD csz
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CertRDNValueToStr = CertRDNValueToStrW
#ELSE
   MACRO CertRDNValueToStr = CertRDNValueToStrA
#ENDIF

'//+-------------------------------------------------------------------------
'//  Convert the certificate name blob to a null terminated char string.
'//
'//  Follows the string representation of distinguished names specified in
'//  RFC 1779. (Note, added double quoting "" for embedded quotes, quote
'//  empty strings and don't quote strings containing consecutive spaces).
'//  RDN values of type CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING are
'//  formatted in hexadecimal (e.g. #0A56CF).
'//
'//  The name string is formatted according to the dwStrType:
'//    CERT_SIMPLE_NAME_STR
'//      The object identifiers are discarded. CERT_RDN entries are separated
'//      by ", ". Multiple attributes per CERT_RDN are separated by " + ".
'//      For example:
'//          Microsoft, Joe Cool + Programmer
'//    CERT_OID_NAME_STR
'//      The object identifiers are included with a "=" separator from their
'//      attribute value. CERT_RDN entries are separated by ", ".
'//      Multiple attributes per CERT_RDN are separated by " + ". For example:
'//          2.5.4.11=Microsoft, 2.5.4.3=Joe Cool + 2.5.4.12=Programmer
'//    CERT_X500_NAME_STR
'//      The object identifiers are converted to their X500 key name. Otherwise,
'//      same as CERT_OID_NAME_STR. If the object identifier doesn't have
'//      a corresponding X500 key name, then, the object identifier is used with
'//      a "OID." prefix. For example:
'//          OU=Microsoft, CN=Joe Cool + T=Programmer, OID.1.2.3.4.5.6=Unknown
'//
'//  We quote the RDN value if it contains leading or trailing whitespace
'//  or one of the following characters: ",", "+", "=", """, "\n",  "<", ">",
'//  "#" or ";". The quoting character is ". If the the RDN Value contains
'//  a " it is double quoted (""). For example:
'//      OU="  Microsoft", CN="Joe ""Cool""" + T="Programmer, Manager"
'//
'//  CERT_NAME_STR_SEMICOLON_FLAG can be or'ed into dwStrType to replace
'//  the ", " separator with a "; " separator.
'//
'//  CERT_NAME_STR_CRLF_FLAG can be or'ed into dwStrType to replace
'//  the ", " separator with a "\r\n" separator.
'//
'//  CERT_NAME_STR_NO_PLUS_FLAG can be or'ed into dwStrType to replace the
'//  " + " separator with a single space, " ".
'//
'//  CERT_NAME_STR_NO_QUOTING_FLAG can be or'ed into dwStrType to inhibit
'//  the above quoting.
'//
'//  CERT_NAME_STR_REVERSE_FLAG can be or'ed into dwStrType to reverse the
'//  order of the RDNs before converting to the string.
'//
'//  By default, CERT_RDN_T61_STRING encoded values are initially decoded
'//  as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'//  CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG can be or'ed into dwStrType to
'//  skip the initial attempt to decode as UTF8.
'//
'//  CERT_NAME_STR_ENABLE_PUNYCODE_FLAG can be or'ed into dwStrType to enable
'//  encoding/decoding of unicode characters in email RDN value.
'//
'//  Returns the number of characters converted including the terminating null
'//  character. If psz is NULL or csz is 0, returns the required size of the
'//  destination string (including the terminating null char).
'//
'//  If psz != NULL && csz != 0, returned psz is always NULL terminated.
'//
'//  Note: csz includes the NULL char.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertNameToStrA IMPORT "CRYPT32.DLL" ALIAS "CertNameToStrA" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pName AS CERT_NAME_BLOB _                      ' __in PCERT_NAME_BLOB pName
 , BYVAL dwStrType AS DWORD _                           ' __in DWORD dwStrType
 , BYREF psz AS ASCIIZ _                                ' __out_opt LPSTR psz
 , BYVAL csz AS DWORD _                                 ' __in DWORD csz
 ) AS DWORD                                             ' DWORD

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertNameToStrW IMPORT "CRYPT32.DLL" ALIAS "CertNameToStrW" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pName AS CERT_NAME_BLOB _                      ' __in PCERT_NAME_BLOB pName
 , BYVAL dwStrType AS DWORD _                           ' __in DWORD dwStrType
 , BYREF psz AS WSTRINGZ _                              ' __out_opt LPWSTR psz
 , BYVAL csz AS DWORD _                                 ' __in DWORD csz
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CertNameToStr = CertNameToStrW
#ELSE
   MACRO CertNameToStr = CertNameToStrA
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate name string types
'//--------------------------------------------------------------------------
%CERT_SIMPLE_NAME_STR       = 1???
%CERT_OID_NAME_STR          = 2???
%CERT_X500_NAME_STR         = 3???
%CERT_XML_NAME_STR          = 4???

'//+-------------------------------------------------------------------------
'//  Certificate name string type flags OR'ed with the above types
'//--------------------------------------------------------------------------
%CERT_NAME_STR_SEMICOLON_FLAG            = &H40000000???
%CERT_NAME_STR_NO_PLUS_FLAG              = &H20000000???
%CERT_NAME_STR_NO_QUOTING_FLAG           = &H10000000???
%CERT_NAME_STR_CRLF_FLAG                 = &H08000000???
%CERT_NAME_STR_COMMA_FLAG                = &H04000000???
%CERT_NAME_STR_REVERSE_FLAG              = &H02000000???
%CERT_NAME_STR_FORWARD_FLAG              = &H01000000???

%CERT_NAME_STR_DISABLE_IE4_UTF8_FLAG     = &H00010000???
%CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG   = &H00020000???
%CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG  = &H00040000???
%CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG   = &H00080000???
%CERT_NAME_STR_DISABLE_UTF8_DIR_STR_FLAG = &H00100000???
%CERT_NAME_STR_ENABLE_PUNYCODE_FLAG      = &H00200000???

'//+-------------------------------------------------------------------------
'//  Convert the null terminated X500 string to an encoded certificate name.
'//
'//  The input string is expected to be formatted the same as the output
'//  from the above CertNameToStr API.
'//
'//  The CERT_SIMPLE_NAME_STR type isn't supported. Otherwise, when dwStrType
'//  is set to 0, CERT_OID_NAME_STR or CERT_X500_NAME_STR, allow either a
'//  case insensitive X500 key (CN=), case insensitive "OID." prefixed
'//  object identifier (OID.1.2.3.4.5.6=) or an object identifier (1.2.3.4=).
'//
'//  If no flags are OR'ed into dwStrType, then, allow "," or ";" as RDN
'//  separators and "+" as the multiple RDN value separator. Quoting is
'//  supported. A quote may be included in a quoted value by double quoting,
'//  for example (CN="Joe ""Cool"""). A value starting with a "#" is treated
'//  as ascii hex and converted to a CERT_RDN_OCTET_STRING. Embedded whitespace
'//  is skipped (1.2.3 = # AB CD 01  is the same as 1.2.3=#ABCD01).
'//
'//  Whitespace surrounding the keys, object identifers and values is removed.
'//
'//  CERT_NAME_STR_COMMA_FLAG can be or'ed into dwStrType to only allow the
'//  "," as the RDN separator.
'//
'//  CERT_NAME_STR_SEMICOLON_FLAG can be or'ed into dwStrType to only allow the
'//  ";" as the RDN separator.
'//
'//  CERT_NAME_STR_CRLF_FLAG can be or'ed into dwStrType to only allow
'//  "\r" or "\n" as the RDN separator.
'//
'//  CERT_NAME_STR_NO_PLUS_FLAG can be or'ed into dwStrType to ignore "+"
'//  as a separator and not allow multiple values per RDN.
'//
'//  CERT_NAME_STR_NO_QUOTING_FLAG can be or'ed into dwStrType to inhibit
'//  quoting.
'//
'//  CERT_NAME_STR_REVERSE_FLAG can be or'ed into dwStrType to reverse the
'//  order of the RDNs after converting from the string and before encoding.
'//
'//  CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG can be or'ed into dwStrType to
'//  to select the CERT_RDN_T61_STRING encoded value type instead of
'//  CERT_RDN_UNICODE_STRING if all the UNICODE characters are <= 0xFF.
'//
'//  CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG can be or'ed into dwStrType to
'//  to select the CERT_RDN_UTF8_STRING encoded value type instead of
'//  CERT_RDN_UNICODE_STRING.
'//
'//  CERT_NAME_STR_FORCE_UTF8_DIR_STR_FLAG can be or'ed into dwStrType
'//  to force the CERT_RDN_UTF8_STRING encoded value type instead of
'//  allowing CERT_RDN_PRINTABLE_STRING for DirectoryString types.
'//  Applies to the X500 Keys below which allow "Printable, Unicode".
'//  Also, enables CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG.
'//
'//  Support the following X500 Keys:
'//
'//  Key         Object Identifier               RDN Value Type(s)
'//  ---         -----------------               -----------------
'//  CN          szOID_COMMON_NAME               Printable, Unicode
'//  L           szOID_LOCALITY_NAME             Printable, Unicode
'//  O           szOID_ORGANIZATION_NAME         Printable, Unicode
'//  OU          szOID_ORGANIZATIONAL_UNIT_NAME  Printable, Unicode
'//  E           szOID_RSA_emailAddr             Only IA5
'//  Email       szOID_RSA_emailAddr             Only IA5
'//  C           szOID_COUNTRY_NAME              Only Printable
'//  S           szOID_STATE_OR_PROVINCE_NAME    Printable, Unicode
'//  ST          szOID_STATE_OR_PROVINCE_NAME    Printable, Unicode
'//  STREET      szOID_STREET_ADDRESS            Printable, Unicode
'//  T           szOID_TITLE                     Printable, Unicode
'//  Title       szOID_TITLE                     Printable, Unicode
'//  G           szOID_GIVEN_NAME                Printable, Unicode
'//  GN          szOID_GIVEN_NAME                Printable, Unicode
'//  GivenName   szOID_GIVEN_NAME                Printable, Unicode
'//  I           szOID_INITIALS                  Printable, Unicode
'//  Initials    szOID_INITIALS                  Printable, Unicode
'//  SN          szOID_SUR_NAME                  Printable, Unicode
'//  DC          szOID_DOMAIN_COMPONENT          IA5, UTF8
'//  SERIALNUMBER szOID_DEVICE_SERIAL_NUMBER     Only Printable
'//
'//  Note, T61 is selected instead of Unicode if
'//  CERT_NAME_STR_ENABLE_T61_UNICODE_FLAG is set and all the unicode
'//  characters are <= 0xFF.
'//
'//  Note, UTF8 is selected instead of Unicode if
'//  CERT_NAME_STR_ENABLE_UTF8_UNICODE_FLAG is set.
'//
'//  Returns TRUE if successfully parsed the input string and encoded
'//  the name.
'//
'//  If the input string is detected to be invalid, *ppszError is updated
'//  to point to the beginning of the invalid character sequence. Otherwise,
'//  *ppszError is set to NULL. *ppszError is updated with a non-NULL pointer
'//  for the following errors:
'//      CRYPT_E_INVALID_X500_STRING
'//      CRYPT_E_INVALID_NUMERIC_STRING
'//      CRYPT_E_INVALID_PRINTABLE_STRING
'//      CRYPT_E_INVALID_IA5_STRING
'//
'//  ppszError can be set to NULL if not interested in getting a pointer
'//  to the invalid character sequence.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertStrToNameA LIB "Crypt32.dll" ALIAS "CertStrToNameA" ( _
    BYVAL dwCertEncodingType AS DWORD, _
    pszX500                  AS ASCIIZ, _
    BYVAL dwStrType          AS DWORD, _
    pvReserved               AS ANY, _
    BYVAL pbEncoded          AS BYTE PTR, _
    pcbEncoded               AS DWORD, _
    ppszError                AS ANY _  ' LPSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertStrToNameA IMPORT "CRYPT32.DLL" ALIAS "CertStrToNameA" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pszX500 AS ASCIIZ _                            ' __in LPCSTR pszX500
 , BYVAL dwStrType AS DWORD _                           ' __in DWORD dwStrType
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYVAL pbEncoded AS BYTE PTR _                        ' __out BYTE *pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 , OPTIONAL BYREF ppszError AS ASCIIZ _                 ' __out_opt LPCSTR *ppszError
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertStrToNameW LIB "Crypt32.dll" ALIAS "CertStrToNameW" ( _
    BYVAL dwCertEncodingType AS DWORD, _
    pszX500                  AS WSTRINGZ, _
    BYVAL dwStrType          AS DWORD, _
    pvReserved               AS ANY, _
    BYVAL pbEncoded          AS BYTE PTR, _
    pcbEncoded               AS DWORD, _
    ppszError                AS ANY _   ' LPCWSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertStrToNameW IMPORT "CRYPT32.DLL" ALIAS "CertStrToNameW" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pszX500 AS WSTRINGZ _                          ' __in LPWCSTR pszX500
 , BYVAL dwStrType AS DWORD _                           ' __in DWORD dwStrType
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYVAL pbEncoded AS BYTE PTR _                        ' __out BYTE *pbEncoded
 , BYREF pcbEncoded AS DWORD _                          ' __inout DWORD *pcbEncoded
 , OPTIONAL BYREF ppszError AS DWORD _                  ' __out_opt LPCSTR *ppszError
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO CertStrToName = CertStrToNameW
#ELSE
   MACRO CertStrToName = CertStrToNameA
#ENDIF

'//+-------------------------------------------------------------------------
'//  Get the subject or issuer name from the certificate and
'//  according to the specified format type, convert to a null terminated
'//  character string.
'//
'//  CERT_NAME_ISSUER_FLAG can be set to get the issuer's name. Otherwise,
'//  gets the subject's name.
'//
'//  By default, CERT_RDN_T61_STRING encoded values are initially decoded
'//  as UTF8. If the UTF8 decoding fails, then, decoded as 8 bit characters.
'//  CERT_NAME_DISABLE_IE4_UTF8_FLAG can be set in dwFlags to
'//  skip the initial attempt to decode as UTF8.
'//
'//  The name string is formatted according to the dwType:
'//    CERT_NAME_EMAIL_TYPE
'//      If the certificate has a Subject Alternative Name extension (for
'//      issuer, Issuer Alternative Name), searches for first rfc822Name choice.
'//      If the rfc822Name choice isn't found in the extension, searches the
'//      Subject Name field for the Email OID, "1.2.840.113549.1.9.1".
'//      If the rfc822Name or Email OID is found, returns the string. Otherwise,
'//      returns an empty string (returned character count is 1).
'//    CERT_NAME_DNS_TYPE
'//      If the certificate has a Subject Alternative Name extension (for
'//      issuer, Issuer Alternative Name), searches for first DNSName choice.
'//      If the DNSName choice isn't found in the extension, searches the
'//      Subject Name field for the CN OID, "2.5.4.3".
'//      If the DNSName or CN OID is found, returns the string. Otherwise,
'//      returns an empty string.
'//    CERT_NAME_URL_TYPE
'//      If the certificate has a Subject Alternative Name extension (for
'//      issuer, Issuer Alternative Name), searches for first URL choice.
'//      If the URL choice is found, returns the string. Otherwise,
'//      returns an empty string.
'//    CERT_NAME_UPN_TYPE
'//      If the certificate has a Subject Alternative Name extension,
'//      searches the OtherName choices looking for a
'//      pszObjId == szOID_NT_PRINCIPAL_NAME, "1.3.6.1.4.1.311.20.2.3".
'//      If the UPN OID is found, the blob is decoded as a
'//      X509_UNICODE_ANY_STRING and the decoded string is returned.
'//      Otherwise, returns an empty string.
'//    CERT_NAME_RDN_TYPE
'//      Converts the Subject Name blob by calling CertNameToStr. pvTypePara
'//      points to a DWORD containing the dwStrType passed to CertNameToStr.
'//      If the Subject Name field is empty and the certificate has a
'//      Subject Alternative Name extension, searches for and converts
'//      the first directoryName choice.
'//    CERT_NAME_ATTR_TYPE
'//      pvTypePara points to the Object Identifier specifying the name attribute
'//      to be returned. For example, to get the CN,
'//      pvTypePara = szOID_COMMON_NAME ("2.5.4.3"). Searches, the Subject Name
'//      field for the attribute.
'//      If the Subject Name field is empty and the certificate has a
'//      Subject Alternative Name extension, checks for
'//      the first directoryName choice and searches it.
'//
'//      Note, searches the RDNs in reverse order.
'//
'//    CERT_NAME_SIMPLE_DISPLAY_TYPE
'//      Iterates through the following list of name attributes and searches
'//      the Subject Name and then the Subject Alternative Name extension
'//      for the first occurrence of:
'//          szOID_COMMON_NAME ("2.5.4.3")
'//          szOID_ORGANIZATIONAL_UNIT_NAME ("2.5.4.11")
'//          szOID_ORGANIZATION_NAME ("2.5.4.10")
'//          szOID_RSA_emailAddr ("1.2.840.113549.1.9.1")
'//
'//      If none of the above attributes is found, then, searches the
'//      Subject Alternative Name extension for a rfc822Name choice.
'//
'//      If still no match, then, returns the first attribute.
'//
'//      Note, like CERT_NAME_ATTR_TYPE, searches the RDNs in reverse order.
'//
'//    CERT_NAME_FRIENDLY_DISPLAY_TYPE
'//      First checks if the certificate has a CERT_FRIENDLY_NAME_PROP_ID
'//      property. If it does, then, this property is returned. Otherwise,
'//      returns the above CERT_NAME_SIMPLE_DISPLAY_TYPE.
'//
'//  Returns the number of characters converted including the terminating null
'//  character. If pwszNameString is NULL or cchNameString is 0, returns the
'//  required size of the destination string (including the terminating null
'//  char). If the specified name type isn't found. returns an empty string
'//  with a returned character count of 1.
'//
'//  If pwszNameString != NULL && cwszNameString != 0, returned pwszNameString
'//  is always NULL terminated.
'//
'//  Note: cchNameString includes the NULL char.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetNameStringA LIB "Crypt32.dll" _
    ALIAS "CertGetNameStringA" ( _
    pCertContext        AS CERT_CONTEXT, _
    BYVAL dwType        AS DWORD, _
    BYVAL dwFlags       AS DWORD, _
    pvTypePara          AS ANY, _
    pszNameString       AS ASCIIZ, _
    BYVAL cchNameString AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CertGetNameStringA IMPORT "CRYPT32.DLL" ALIAS "CertGetNameStringA" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvTypePara AS ANY _                            ' __in void *pvTypePara
 , BYREF pszNameString AS ASCIIZ _                      ' __out_opt LPSTR pszNameString
 , BYVAL cchNameString AS DWORD _                       ' __in DWORD cchNameString
 ) AS DWORD                                             ' DWORD
#ENDIF

'//+-------------------------------------------------------------------------
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetNameStringW LIB "Crypt32.dll" _
    ALIAS "CertGetNameStringW" ( _
    pCertContext        AS CERT_CONTEXT, _
    BYVAL dwType        AS DWORD, _
    BYVAL dwFlags       AS DWORD, _
    pvTypePara          AS ANY, _
    pszNameString       AS WSTRINGZ, _
    BYVAL cchNameString AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION CertGetNameStringW IMPORT "CRYPT32.DLL" ALIAS "CertGetNameStringW" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvTypePara AS ANY _                            ' __in void *pvTypePara
 , BYREF pszNameString AS WSTRINGZ _                    ' __out_opt LPWSTR pszNameString
 , BYVAL cchNameString AS DWORD _                       ' __in DWORD cchNameString
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO CertGetNameString = CertGetNameStringW
#ELSE
   MACRO CertGetNameString = CertGetNameStringA
#ENDIF

'//+-------------------------------------------------------------------------
'//  Certificate name types
'//--------------------------------------------------------------------------
%CERT_NAME_EMAIL_TYPE            = 1???
%CERT_NAME_RDN_TYPE              = 2???
%CERT_NAME_ATTR_TYPE             = 3???
%CERT_NAME_SIMPLE_DISPLAY_TYPE   = 4???
%CERT_NAME_FRIENDLY_DISPLAY_TYPE = 5???
%CERT_NAME_DNS_TYPE              = 6???
%CERT_NAME_URL_TYPE              = 7???
%CERT_NAME_UPN_TYPE              = 8???

'//+-------------------------------------------------------------------------
'//  Certificate name flags
'//--------------------------------------------------------------------------
%CERT_NAME_ISSUER_FLAG           = &H1???
%CERT_NAME_DISABLE_IE4_UTF8_FLAG = &H00010000???


'//+=========================================================================
'//  Simplified Cryptographic Message Data Structures and APIs
'//==========================================================================


'//+-------------------------------------------------------------------------
'//              Conventions for the *pb and *pcb output parameters:
'//
'//              Upon entry to the function:
'//                  if pcb is OPTIONAL && pcb == NULL, then,
'//                      No output is returned
'//                  else if pb == NULL && pcb != NULL, then,
'//                      Length only determination. No length error is
'//                      returned.
'//                  otherwise where (pb != NULL && pcb != NULL && *pcb != 0)
'//                      Output is returned. If *pcb isn't big enough a
'//                      length error is returned. In all cases *pcb is updated
'//                      with the actual length needed/returned.
'//--------------------------------------------------------------------------


'//+-------------------------------------------------------------------------
'//  Type definitions of the parameters used for doing the cryptographic
'//  operations.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  Callback to get and verify the signer's certificate.
'//
'//  Passed the CertId of the signer (its Issuer and SerialNumber) and a
'//  handle to its cryptographic signed message's cert store.
'//
'//  For CRYPT_E_NO_SIGNER, called with pSignerId == NULL.
'//
'//  For a valid signer certificate, returns a pointer to a read only
'//  CERT_CONTEXT. The returned CERT_CONTEXT is either obtained from a
'//  cert store or was created via CertCreateCertificateContext. For either case,
'//  its freed via CertFreeCertificateContext.
'//
'//  If a valid certificate isn't found, this callback returns NULL with
'//  LastError set via SetLastError().
'//
'//  The NULL implementation tries to get the Signer certificate from the
'//  message cert store. It doesn't verify the certificate.
'//
'//  Note, if the KEYID choice was selected for a CMS SignerId, then, the
'//  SerialNumber is 0 and the Issuer is encoded containing a single RDN with a
'//  single Attribute whose OID is szOID_KEYID_RDN, value type is
'//  CERT_RDN_OCTET_STRING and value is the KEYID. When the
'//  CertGetSubjectCertificateFromStore and
'//  CertFindCertificateInStore(CERT_FIND_SUBJECT_CERT) APIs see this
'//  special KEYID Issuer and SerialNumber, they do a KEYID match.
'//--------------------------------------------------------------------------
'typedef PCCERT_CONTEXT (WINAPI *PFN_CRYPT_GET_SIGNER_CERTIFICATE)(
'    IN void *pvGetArg,
'    IN DWORD dwCertEncodingType,
'    IN PCERT_INFO pSignerId,    // Only the Issuer and SerialNumber
'                                // fields have been updated
'    IN HCERTSTORE hMsgCertStore
'    );

'FUNCTION CRYPT_GET_SIGNER_CERTIFICATE ( _
'   BYVAL pvGetArg AS DWORD, _              ' __in void *pvGetArg
'   BYVAL dwCertEncodingType AS DWORD, _    ' __in DWORD dwCertEncodingType
'   BYREF pSignerId AS CERT_INFO, _         ' __in PCERT_INFO pSignerId
'   BYVAL hMsgCertStore AS DWORD _          ' __in HCERTSTORE hMsgCertStore
'   ) AS DWORD                              ' PCCERT_CONTEXT

'//+-------------------------------------------------------------------------
'//  The CRYPT_SIGN_MESSAGE_PARA are used for signing messages using the
'//  specified signing certificate context.
'//
'//  Either the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID must
'//  be set for each rgpSigningCert[]. Either one specifies the private
'//  signature key to use.
'//
'//  If any certificates and/or CRLs are to be included in the signed message,
'//  then, the MsgCert and MsgCrl parameters need to be updated. If the
'//  rgpSigningCerts are to be included, then, they must also be in the
'//  rgpMsgCert array.
'//
'//  cbSize must be set to the sizeof(CRYPT_SIGN_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//
'//  pvHashAuxInfo currently isn't used and must be set to NULL.
'//
'//  dwFlags normally is set to 0. However, if the encoded output
'//  is to be a CMSG_SIGNED inner content of an outer cryptographic message,
'//  such as a CMSG_ENVELOPED, then, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG
'//  should be set. If not set, then it would be encoded as an inner content
'//  type of CMSG_DATA.
'//
'//  dwInnerContentType is normally set to 0. It needs to be set if the
'//  ToBeSigned input is the encoded output of another cryptographic
'//  message, such as, an CMSG_ENVELOPED. When set, it's one of the cryptographic
'//  message types, for example, CMSG_ENVELOPED.
'//
'//  If the inner content of a nested cryptographic message is data (CMSG_DATA
'//  the default), then, neither dwFlags or dwInnerContentType need to be set.
'//
'//  For CMS messages, CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG may be
'//  set to encapsulate nonData inner content within an OCTET STRING.
'//
'//  For CMS messages, CRYPT_MESSAGE_KEYID_SIGNER_FLAG may be set to identify
'//  signers by their Key Identifier and not their Issuer and Serial Number.
'//
'//  The CRYPT_MESSAGE_SILENT_KEYSET_FLAG can be set to suppress any UI by the
'//  CSP. See CryptAcquireContext's CRYPT_SILENT flag for more details.
'//
'//  If HashEncryptionAlgorithm is present and not NULL its used instead of
'//  the SigningCert's PublicKeyInfo.Algorithm.
'//
'//  Note, for RSA, the hash encryption algorithm is normally the same as
'//  the public key algorithm. For DSA, the hash encryption algorithm is
'//  normally a DSS signature algorithm.
'//
'//  pvHashEncryptionAuxInfo currently isn't used and must be set to NULL if
'//  present in the data structure.
'//--------------------------------------------------------------------------
'typedef struct _CRYPT_SIGN_MESSAGE_PARA {
'    DWORD                       cbSize;
'    DWORD                       dwMsgEncodingType;
'    PCCERT_CONTEXT              pSigningCert;
'    CRYPT_ALGORITHM_IDENTIFIER  HashAlgorithm;
'    void                        *pvHashAuxInfo;
'    DWORD                       cMsgCert;
'    PCCERT_CONTEXT              *rgpMsgCert;
'    DWORD                       cMsgCrl;
'    PCCRL_CONTEXT               *rgpMsgCrl;
'    DWORD                       cAuthAttr;
'    PCRYPT_ATTRIBUTE            rgAuthAttr;
'    DWORD                       cUnauthAttr;
'    PCRYPT_ATTRIBUTE            rgUnauthAttr;
'    DWORD                       dwFlags;
'    DWORD                       dwInnerContentType;

'#ifdef CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS
'    CRYPT_ALGORITHM_IDENTIFIER  HashEncryptionAlgorithm;
'    void                        *pvHashEncryptionAuxInfo;
'#endif
'} CRYPT_SIGN_MESSAGE_PARA, *PCRYPT_SIGN_MESSAGE_PARA;

' // Size = 68 bytes
TYPE CRYPT_SIGN_MESSAGE_PARA DWORD
   cbSize                  AS DWORD
   dwMsgEncodingType       AS DWORD
   pSigningCert            AS CERT_CONTEXT PTR
   HashAlgorithm           AS CRYPT_ALGORITHM_IDENTIFIER
   pvHashAuxInfo           AS DWORD
   cMsgCert                AS DWORD
   rgpMsgCert              AS CERT_CONTEXT PTR
   cMsgCrl                 AS DWORD
   rgpMsgCrl               AS CRL_CONTEXT PTR
   cAuthAttr               AS DWORD
   rgAuthAttr              AS CRYPT_ATTRIBUTE PTR
   cUnauthAttr             AS DWORD
   rgUnauthAttr            AS CRYPT_ATTRIBUTE PTR
   dwFlags                 AS DWORD
   dwInnerContentType      AS DWORD
#IF %DEF(%CRYPT_SIGN_MESSAGE_PARA_HAS_CMS_FIELDS)
   HashEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   pvHashEncryptionAuxInfo AS DWORD
#ENDIF
END TYPE

%CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG         = &H00000001???

'// When set, nonData type inner content is encapsulated within an
'// OCTET STRING
%CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG = &H00000002???

'// When set, signers are identified by their Key Identifier and not
'// their Issuer and Serial Number.
%CRYPT_MESSAGE_KEYID_SIGNER_FLAG             = &H00000004???

'// When set, suppresses any UI by the CSP.
'// See CryptAcquireContext's CRYPT_SILENT flag for more details.
%CRYPT_MESSAGE_SILENT_KEYSET_FLAG            = &H00000040???

'//+-------------------------------------------------------------------------
'//  The CRYPT_VERIFY_MESSAGE_PARA are used to verify signed messages.
'//
'//  hCryptProv is used to do hashing and signature verification.
'//
'//  The dwCertEncodingType specifies the encoding type of the certificates
'//  and/or CRLs in the message.
'//
'//  pfnGetSignerCertificate is called to get and verify the message signer's
'//  certificate.
'//
'//  cbSize must be set to the sizeof(CRYPT_VERIFY_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//--------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPT_VERIFY_MESSAGE_PARA DWORD
   cbSize                   AS DWORD   ' DWORD
   dwMsgAndCertEncodingType AS DWORD   ' DWORD
   hCryptProv               AS DWORD   ' HCRYPTPROV
   pfnGetSignerCertificate  AS DWORD   ' PFN_CRYPT_GET_SIGNER_CERTIFICATE
   pvGetArg                 AS DWORD   ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  The CRYPT_ENCRYPT_MESSAGE_PARA are used for encrypting messages.
'//
'//  hCryptProv is used to do content encryption, recipient key
'//  encryption, and recipient key export. Its private key
'//  isn't used.
'//
'//  Currently, pvEncryptionAuxInfo is only defined for RC2 or RC4 encryption
'//  algorithms. Otherwise, its not used and must be set to NULL.
'//  See CMSG_RC2_AUX_INFO for the RC2 encryption algorithms.
'//  See CMSG_RC4_AUX_INFO for the RC4 encryption algorithms.
'//
'//  To enable SP3 compatible encryption, pvEncryptionAuxInfo should point to
'//  a CMSG_SP3_COMPATIBLE_AUX_INFO data structure.
'//
'//  cbSize must be set to the sizeof(CRYPT_ENCRYPT_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//
'//  dwFlags normally is set to 0. However, if the encoded output
'//  is to be a CMSG_ENVELOPED inner content of an outer cryptographic message,
'//  such as a CMSG_SIGNED, then, the CRYPT_MESSAGE_BARE_CONTENT_OUT_FLAG
'//  should be set. If not set, then it would be encoded as an inner content
'//  type of CMSG_DATA.
'//
'//  dwInnerContentType is normally set to 0. It needs to be set if the
'//  ToBeEncrypted input is the encoded output of another cryptographic
'//  message, such as, an CMSG_SIGNED. When set, it's one of the cryptographic
'//  message types, for example, CMSG_SIGNED.
'//
'//  If the inner content of a nested cryptographic message is data (CMSG_DATA
'//  the default), then, neither dwFlags or dwInnerContentType need to be set.
'//
'//  For CMS messages, CRYPT_MESSAGE_ENCAPSULATED_CONTENT_OUT_FLAG may be
'//  set to encapsulate nonData inner content within an OCTET STRING before
'//  encrypting.
'//
'//  For CMS messages, CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG may be set to identify
'//  recipients by their Key Identifier and not their Issuer and Serial Number.
'//--------------------------------------------------------------------------

' // Size = 36 bytes
TYPE CRYPT_ENCRYPT_MESSAGE_PARA DWORD
   cbSize                     AS DWORD                        ' DWORD
   dwMsgEncodingType          AS DWORD                        ' DWORD
   hCryptProv                 AS DWORD                        ' HCRYPTPROV
   ContentEncryptionAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   pvEncryptionAuxInfo        AS DWORD                        ' void*
   dwFlags                    AS DWORD                        ' DWORD
   dwInnerContentType         AS DWORD                        ' DWORD
END TYPE

'// When set, recipients are identified by their Key Identifier and not
'// their Issuer and Serial Number.
%CRYPT_MESSAGE_KEYID_RECIPIENT_FLAG          = &H4???

'//+-------------------------------------------------------------------------
'//  The CRYPT_DECRYPT_MESSAGE_PARA are used for decrypting messages.
'//
'//  The CertContext to use for decrypting a message is obtained from one
'//  of the specified cert stores. An encrypted message can have one or
'//  more recipients. The recipients are identified by their CertId (Issuer
'//  and SerialNumber). The cert stores are searched to find the CertContext
'//  corresponding to the CertId.
'//
'//  For CMS, the recipients may also be identified by their KeyId.
'//  CMS also allows Key Agreement (Diffie Hellman) in addition to
'//  Key Transport (RSA) recipients.
'//
'//  Only CertContexts in the store with either
'//  the CERT_KEY_PROV_HANDLE_PROP_ID or CERT_KEY_PROV_INFO_PROP_ID set
'//  can be used. Either property specifies the private exchange key to use.
'//
'//  cbSize must be set to the sizeof(CRYPT_DECRYPT_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//--------------------------------------------------------------------------
'typedef struct _CRYPT_DECRYPT_MESSAGE_PARA {
'    DWORD                   cbSize;
'    DWORD                   dwMsgAndCertEncodingType;
'    DWORD                   cCertStore;
'    HCERTSTORE              *rghCertStore;

'#ifdef CRYPT_DECRYPT_MESSAGE_PARA_HAS_EXTRA_FIELDS
''// The above defined, CRYPT_MESSAGE_SILENT_KEYSET_FLAG, can be set to
''// suppress UI by the CSP.  See CryptAcquireContext's CRYPT_SILENT
''// flag for more details.

'    DWORD                   dwFlags;
'#endif

'} CRYPT_DECRYPT_MESSAGE_PARA, *PCRYPT_DECRYPT_MESSAGE_PARA;

' // Size = 16 bytes
TYPE CRYPT_DECRYPT_MESSAGE_PARA DWORD
   cbSize                   AS DWORD
   dwMsgAndCertEncodingType AS DWORD
   cCertStore               AS DWORD
   rghCertStore             AS DWORD PTR
#IF %DEF(%CRYPT_DECRYPT_MESSAGE_PARA_HAS_EXTRA_FIELDS)
   dwFlags                  AS DWORD
#ENDIF
END TYPE

'//+-------------------------------------------------------------------------
'//  The CRYPT_HASH_MESSAGE_PARA are used for hashing or unhashing
'//  messages.
'//
'//  hCryptProv is used to compute the hash.
'//
'//  pvHashAuxInfo currently isn't used and must be set to NULL.
'//
'//  cbSize must be set to the sizeof(CRYPT_HASH_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//--------------------------------------------------------------------------

' // Size = 28 bytes
TYPE CRYPT_HASH_MESSAGE_PARA DWORD
   cbSize            AS DWORD                        ' DWORD
   dwMsgEncodingType AS DWORD                        ' DWORD
   hCryptProv        AS DWORD                        ' HCRYPTPROV
   HashAlgorithm     AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   pvHashAuxInfo     AS DWORD                        ' void*
END TYPE

'//+-------------------------------------------------------------------------
'//  The CRYPT_KEY_SIGN_MESSAGE_PARA are used for signing messages until a
'//  certificate has been created for the signature key.
'//
'//  pvHashAuxInfo currently isn't used and must be set to NULL.
'//
'//  If PubKeyAlgorithm isn't set, defaults to szOID_RSA_RSA.
'//
'//  cbSize must be set to the sizeof(CRYPT_KEY_SIGN_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//--------------------------------------------------------------------------

UNION CRYPT_KEY_SIGN_MESSAGE_PARA_UNION DWORD
   hCryptProv               AS DWORD                        ' HCRYPTPROV
   hNCryptKey               AS DWORD                        ' NCRYPT_KEY_HANDLE
END UNION

' // Size = 44 bytes
TYPE CRYPT_KEY_SIGN_MESSAGE_PARA DWORD
   cbSize                   AS DWORD                        ' DWORD
   dwMsgAndCertEncodingType AS DWORD                        ' DWORD
   CRYPT_KEY_SIGN_MESSAGE_PARA_UNION
   dwKeySpec                AS DWORD                        ' DWORD
   HashAlgorithm            AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
   pvHashAuxInfo            AS DWORD                        ' void*
   PubKeyAlgorithm          AS CRYPT_ALGORITHM_IDENTIFIER   ' CRYPT_ALGORITHM_IDENTIFIER
END TYPE

'//+-------------------------------------------------------------------------
'//  The CRYPT_KEY_VERIFY_MESSAGE_PARA are used to verify signed messages without
'//  a certificate for the signer.
'//
'//  Normally used until a certificate has been created for the key.
'//
'//  hCryptProv is used to do hashing and signature verification.
'//
'//  cbSize must be set to the sizeof(CRYPT_KEY_VERIFY_MESSAGE_PARA) or else
'//  LastError will be updated with E_INVALIDARG.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPT_KEY_VERIFY_MESSAGE_PARA DWORD
   cbSize            AS DWORD   ' DWORD
   dwMsgEncodingType AS DWORD   ' DWORD
   hCryptProv        AS DWORD   ' HCRYPTPROV
END TYPE

'//+-------------------------------------------------------------------------
'//  Sign the message.
'//
'//  If fDetachedSignature is TRUE, the "to be signed" content isn't included
'//  in the encoded signed blob.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptSignMessage IMPORT "CRYPT32.DLL" ALIAS "CryptSignMessage" ( _
   BYREF pSignPara AS CRYPT_SIGN_MESSAGE_PARA _         ' __in PCRYPT_SIGN_MESSAGE_PARA pSignPara
 , BYVAL fDetachedSignature AS LONG _                   ' __in BOOL fDetachedSignature
 , BYVAL cToBeSigned AS DWORD _                         ' __in DWORD cToBeSigned
 , BYVAL rgpbToBeSigned AS BYTE PTR _                   ' __in const BYTE *rgpbToBeSigned[]
 , BYREF rgcbToBeSigned AS DWORD _                      ' __in DWORD rgcbToBeSigned[]
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __out BYTE *pbSignedBlob
 , BYREF pcbSignedBlob AS DWORD _                       ' __inout DWORD *pcbSignedBlob
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify a signed message.
'//
'//  If pbDecoded == NULL, then, *pcbDecoded is implicitly set to 0 on input.
'//  For *pcbDecoded == 0 && ppSignerCert == NULL on input, the signer isn't
'//  verified.
'//
'//  A message might have more than one signer. Set dwSignerIndex to iterate
'//  through all the signers. dwSignerIndex == 0 selects the first signer.
'//
'//  pVerifyPara's pfnGetSignerCertificate is called to get the signer's
'//  certificate.
'//
'//  For a verified signer and message, *ppSignerCert is updated
'//  with the CertContext of the signer. It must be freed by calling
'//  CertFreeCertificateContext. Otherwise, *ppSignerCert is set to NULL.
'//
'//  ppSignerCert can be NULL, indicating the caller isn't interested
'//  in getting the CertContext of the signer.
'//
'//  pcbDecoded can be NULL, indicating the caller isn't interested in getting
'//  the decoded content. Furthermore, if the message doesn't contain any
'//  content or signers, then, pcbDecoded must be set to NULL, to allow the
'//  pVerifyPara->pfnGetCertificate to be called. Normally, this would be
'//  the case when the signed message contains only certficates and CRLs.
'//  If pcbDecoded is NULL and the message doesn't have the indicated signer,
'//  pfnGetCertificate is called with pSignerId set to NULL.
'//
'//  If the message doesn't contain any signers || dwSignerIndex > message's
'//  SignerCount, then, an error is returned with LastError set to
'//  CRYPT_E_NO_SIGNER. Also, for CRYPT_E_NO_SIGNER, pfnGetSignerCertificate
'//  is still called with pSignerId set to NULL.
'//
'//  Note, an alternative way to get the certificates and CRLs from a
'//  signed message is to call CryptGetMessageCertificates.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptVerifyMessageSignature IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyMessageSignature" ( _
   BYREF pVerifyPara AS CRYPT_VERIFY_MESSAGE_PARA _     ' __in PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara
 , BYVAL dwSignerIndex AS DWORD _                       ' __in DWORD dwSignerIndex
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __in const BYTE *pbSignedBlob
 , BYVAL cbSignedBlob AS DWORD _                        ' __in DWORD cbSignedBlob
 , BYVAL pbDecoded AS BYTE PTR _                        ' __out BYTE OPTIONAL *pbDecoded
 , BYREF pcbDecoded AS DWORD _                          ' __inout OPTIONAL DWORD *pcbDecoded
 , OPTIONAL BYREF ppSignerCert AS ANY _                 ' __out_opt PCCERT_CONTEXT *ppSignerCert
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Returns the count of signers in the signed message. For no signers, returns
'//  0. For an error returns -1 with LastError updated accordingly.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetMessageSignerCount IMPORT "CRYPT32.DLL" ALIAS "CryptGetMessageSignerCount" ( _
   BYVAL dwMsgEncodingType AS DWORD _                   ' __in DWORD dwMsgEncodingType
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __in const BYTE *pbSignedBlob
 , BYVAL cbSignedBlob AS DWORD _                        ' __in DWORD cbSignedBlob
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Returns the cert store containing the message's certs and CRLs.
'//  For an error, returns NULL with LastError updated.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptGetMessageCertificates IMPORT "CRYPT32.DLL" ALIAS "CryptGetMessageCertificates" ( _
   BYVAL dwMsgAndCertEncodingType AS DWORD _            ' __in DWORD dwMsgAndCertEncodingType
 , BYVAL hCryptProv AS DWORD _                          ' __in HCRYPTPROV hCryptProv
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __in const BYTE *pbSignedBlob
 , BYVAL cbSignedBlob AS DWORD _                        ' __in DWORD cbSignedBlob
 ) AS DWORD                                             ' HCERTSTORE

'//+-------------------------------------------------------------------------
'//  Verify a signed message containing detached signature(s).
'//  The "to be signed" content is passed in separately. No
'//  decoded output. Otherwise, identical to CryptVerifyMessageSignature.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptVerifyDetachedMessageSignature LIB "Crypt32.dll" _
    ALIAS "CryptVerifyDetachedMessageSignature" ( _
    pVerifyPara              AS CRYPT_VERIFY_MESSAGE_PARA, _
    BYVAL dwSignerIndex      AS DWORD, _
    BYVAL pbDetachedSignBlob AS BYTE PTR, _
    BYVAL cbDetachedSignBlob AS DWORD, _
    BYVAL cToBeSigned        AS DWORD, _
    BYVAL rgpbToBeSigned     AS BYTE PTR, _
    BYVAL rgcbToBeSigned     AS DWORD PTR, _
    ppSignerCert             AS ANY _  ' CCERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptVerifyDetachedMessageSignature IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyDetachedMessageSignature" ( _
   BYREF pVerifyPara AS CRYPT_VERIFY_MESSAGE_PARA _     ' __in PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara
 , BYVAL dwSignerIndex AS DWORD _                       ' __in DWORD dwSignerIndex
 , BYVAL pbDetachedSignBlob AS BYTE PTR _               ' __in const BYTE *pbDetachedSignBlob
 , BYVAL cbDetachedSignBlob AS DWORD _                  ' __in DWORD cbDetachedSignBlob
 , BYVAL cToBeSigned AS DWORD _                         ' __in DWORD cToBeSigned
 , BYVAL rgpbToBeSigned AS BYTE PTR _                   ' __in const BYTE *rgpbToBeSigned[]
 , BYREF rgcbToBeSigned AS DWORD _                      ' __in DWORD rgcbToBeSigned[]
 , OPTIONAL BYREF ppSignerCert AS ANY _                 ' __out_opt PCCERT_CONTEXT *ppSignerCert
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Encrypts the message for the recipient(s).
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptEncryptMessage LIB "Crypt32.dll" _
    ALIAS "CryptEncryptMessage" ( _
    pEncryptPara          AS CRYPT_ENCRYPT_MESSAGE_PARA, _
    BYVAL cRecipientCert  AS DWORD, _
    rgpRecipientCert      AS ANY, _  ' CCERT_CONTEXT PTR PTR
    BYVAL pbToBeEncrypted AS BYTE PTR, _
    BYVAL cbToBeEncrypted AS DWORD, _
    BYVAL pbEncryptedBlob AS BYTE PTR, _
    pcbEncryptedBlob      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptEncryptMessage IMPORT "CRYPT32.DLL" ALIAS "CryptEncryptMessage" ( _
   BYREF pEncryptPara AS CRYPT_ENCRYPT_MESSAGE_PARA _   ' __in PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara
 , BYVAL cRecipientCert AS DWORD _                      ' __in DWORD cRecipientCert
 , BYVAL rgpRecipientCert AS CERT_CONTEXT PTR _         ' __in PCCERT_CONTEXT rgpRecipientCert[]
 , BYVAL pbToBeEncrypted AS BYTE PTR _                  ' __in const BYTE *pbToBeEncrypted
 , BYVAL cbToBeEncrypted AS DWORD _                     ' __in DWORD cbToBeEncrypted
 , BYVAL pbEncryptedBlob AS BYTE PTR _                  ' __out BYTE *pbEncryptedBlob
 , BYREF pcbEncryptedBlob AS DWORD _                    ' __inout DWORD *pcbEncryptedBlob
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Decrypts the message.
'//
'//  If pbDecrypted == NULL, then, *pcbDecrypted is implicitly set to 0 on input.
'//  For *pcbDecrypted == 0 && ppXchgCert == NULL on input, the message isn't
'//  decrypted.
'//
'//  For a successfully decrypted message, *ppXchgCert is updated
'//  with the CertContext used to decrypt. It must be freed by calling
'//  CertStoreFreeCert. Otherwise, *ppXchgCert is set to NULL.
'//
'//  ppXchgCert can be NULL, indicating the caller isn't interested
'//  in getting the CertContext used to decrypt.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptDecryptMessage LIB "Crypt32.dll" _
    ALIAS "CryptDecryptMessage" ( _
    pDecryptPara          AS CRYPT_DECRYPT_MESSAGE_PARA, _
    BYVAL pbEncryptedBlob AS BYTE PTR, _
    BYVAL cbEncryptedBlob AS DWORD, _
    BYVAL pbDecrypted     AS BYTE PTR, _
    BYVAL pcbDecrypted    AS DWORD PTR, _
    ppXchgCert            AS ANY _  ' CCERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptDecryptMessage IMPORT "CRYPT32.DLL" ALIAS "CryptDecryptMessage" ( _
   BYREF pDecryptPara AS CRYPT_DECRYPT_MESSAGE_PARA _   ' __in PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara
 , BYVAL pbEncryptedBlob AS BYTE PTR _                  ' __in const BYTE *pbEncryptedBlob
 , BYVAL cbEncryptedBlob AS DWORD _                     ' __in DWORD cbEncryptedBlob
 , BYVAL pbDecrypted AS BYTE PTR _                      ' __out_opt BYTE *pbDecrypted
 , BYREF pcbDecrypted AS DWORD _                        ' __inout OPTIONAL DWORD *pcbDecrypted
 , OPTIONAL BYREF ppXchgCert AS DWORD _                 ' __out_opt PCCERT_CONTEXT *ppXchgCert
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Sign the message and encrypt for the recipient(s). Does a CryptSignMessage
'//  followed with a CryptEncryptMessage.
'//
'//  Note: this isn't the CMSG_SIGNED_AND_ENVELOPED. Its a CMSG_SIGNED
'//  inside of an CMSG_ENVELOPED.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSignAndEncryptMessage LIB "Crypt32.dll" _
    ALIAS "CryptSignAndEncryptMessage" ( _
    pSignPara                      AS CRYPT_SIGN_MESSAGE_PARA, _
    pEncryptPara                   AS CRYPT_ENCRYPT_MESSAGE_PARA, _
    BYVAL cRecipientCert           AS DWORD, _
    rgpRecipientCert               AS ANY, _  ' CCERT_CONTEXT PTR PTR
    BYVAL pbToBeSignedAndEncrypted AS BYTE PTR, _
    BYVAL cbToBeSignedAndEncrypted AS DWORD, _
    BYVAL pbSignedAndEncryptedBlob AS BYTE PTR, _
    pcbSignedAndEncryptedBlob      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptSignAndEncryptMessage IMPORT "CRYPT32.DLL" ALIAS "CryptSignAndEncryptMessage" ( _
   BYREF pSignPara AS CRYPT_SIGN_MESSAGE_PARA _         ' __in PCRYPT_SIGN_MESSAGE_PARA pSignPara
 , BYREF pEncryptPara AS CRYPT_ENCRYPT_MESSAGE_PARA _   ' __in PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara
 , BYVAL cRecipientCert AS DWORD _                      ' __in DWORD cRecipientCert
 , BYVAL rgpRecipientCert AS CERT_CONTEXT PTR _         ' __in PCCERT_CONTEXT rgpRecipientCert[]
 , BYVAL pbToBeSignedAndEncrypted AS BYTE PTR _         ' __in const BYTE *pbToBeSignedAndEncrypted
 , BYVAL cbToBeSignedAndEncrypted AS DWORD _            ' __in DWORD cbToBeSignedAndEncrypted
 , BYVAL pbSignedAndEncryptedBlob AS BYTE PTR _         ' __out BYTE *pbSignedAndEncryptedBlob
 , BYREF pcbSignedAndEncryptedBlob AS DWORD _           ' __inout DWORD *pcbSignedAndEncryptedBlob
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Decrypts the message and verifies the signer. Does a CryptDecryptMessage
'//  followed with a CryptVerifyMessageSignature.
'//
'//  If pbDecrypted == NULL, then, *pcbDecrypted is implicitly set to 0 on input.
'//  For *pcbDecrypted == 0 && ppSignerCert == NULL on input, the signer isn't
'//  verified.
'//
'//  A message might have more than one signer. Set dwSignerIndex to iterate
'//  through all the signers. dwSignerIndex == 0 selects the first signer.
'//
'//  The pVerifyPara's VerifySignerPolicy is called to verify the signer's
'//  certificate.
'//
'//  For a successfully decrypted and verified message, *ppXchgCert and
'//  *ppSignerCert are updated. They must be freed by calling
'//  CertStoreFreeCert. Otherwise, they are set to NULL.
'//
'//  ppXchgCert and/or ppSignerCert can be NULL, indicating the
'//  caller isn't interested in getting the CertContext.
'//
'//  Note: this isn't the CMSG_SIGNED_AND_ENVELOPED. Its a CMSG_SIGNED
'//  inside of an CMSG_ENVELOPED.
'//
'//  The message always needs to be decrypted to allow access to the
'//  signed message. Therefore, if ppXchgCert != NULL, its always updated.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptDecryptAndVerifyMessageSignature LIB "Crypt32.dll" _
    ALIAS "CryptDecryptAndVerifyMessageSignature" ( _
    pDecryptPara          AS CRYPT_DECRYPT_MESSAGE_PARA, _
    pVerifyPara           AS CRYPT_VERIFY_MESSAGE_PARA, _
    BYVAL dwSignerIndex   AS DWORD, _
    BYVAL pbEncryptedBlob AS BYTE PTR, _
    BYVAL cbEncryptedBlob AS DWORD, _
    BYVAL pbDecrypted     AS BYTE PTR, _
    BYVAL pcbDecrypted    AS DWORD PTR, _
    ppXchgCert            AS ANY, _  ' CCERT_CONTEXT PTR PTR
    ppSignerCert          AS ANY _   ' CCERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptDecryptAndVerifyMessageSignature IMPORT "CRYPT32.DLL" ALIAS "CryptDecryptAndVerifyMessageSignature" ( _
   BYREF pDecryptPara AS CRYPT_DECRYPT_MESSAGE_PARA _   ' __in PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara
 , BYREF pVerifyPara AS CRYPT_VERIFY_MESSAGE_PARA _     ' __in PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara
 , BYVAL dwSignerIndex AS DWORD _                       ' __in DWORD dwSignerIndex
 , BYVAL pbEncryptedBlob AS BYTE PTR _                  ' __in const BYTE *pbEncryptedBlob
 , BYVAL cbEncryptedBlob AS DWORD _                     ' __in DWORD cbEncryptedBlob
 , BYVAL pbDecrypted AS BYTE PTR _                      ' __out_opt BYTE *pbDecrypted
 , BYREF pcbDecrypted AS DWORD _                        ' __inout OPTIONAL DWORD *pcbDecrypted
 , OPTIONAL BYREF ppXchgCert AS ANY _                   ' __out_opt PCCERT_CONTEXT *ppXchgCert
 , OPTIONAL BYREF ppSignerCert AS ANY _                 ' __out_opt PCCERT_CONTEXT *ppSignerCert
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Decodes a cryptographic message which may be one of the following types:
'//    CMSG_DATA
'//    CMSG_SIGNED
'//    CMSG_ENVELOPED
'//    CMSG_SIGNED_AND_ENVELOPED
'//    CMSG_HASHED
'//
'//  dwMsgTypeFlags specifies the set of allowable messages. For example, to
'//  decode either SIGNED or ENVELOPED messages, set dwMsgTypeFlags to:
'//      CMSG_SIGNED_FLAG | CMSG_ENVELOPED_FLAG.
'//
'//  dwProvInnerContentType is only applicable when processing nested
'//  crytographic messages. When processing an outer crytographic message
'//  it must be set to 0. When decoding a nested cryptographic message
'//  its the dwInnerContentType returned by a previous CryptDecodeMessage
'//  of the outer message. The InnerContentType can be any of the CMSG types,
'//  for example, CMSG_DATA, CMSG_SIGNED, ...
'//
'//  The optional *pdwMsgType is updated with the type of message.
'//
'//  The optional *pdwInnerContentType is updated with the type of the inner
'//  message. Unless there is cryptographic message nesting, CMSG_DATA
'//  is returned.
'//
'//  For CMSG_DATA: returns decoded content.
'//  For CMSG_SIGNED: same as CryptVerifyMessageSignature.
'//  For CMSG_ENVELOPED: same as CryptDecryptMessage.
'//  For CMSG_SIGNED_AND_ENVELOPED: same as CryptDecryptMessage plus
'//      CryptVerifyMessageSignature.
'//  For CMSG_HASHED: verifies the hash and returns decoded content.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptDecodeMessage LIB "Crypt32.dll" _
    ALIAS "CryptDecodeMessage" ( _
    BYVAL dwMsgTypeFlags         AS DWORD, _
    pDecryptPara                 AS CRYPT_DECRYPT_MESSAGE_PARA, _
    pVerifyPara                  AS CRYPT_VERIFY_MESSAGE_PARA, _
    BYVAL dwSignerIndex          AS DWORD, _
    BYVAL pbEncodedBlob          AS BYTE PTR, _
    BYVAL cbEncodedBlob          AS DWORD, _
    BYVAL dwPrevInnerContentType AS DWORD, _
    pdwMsgType                   AS DWORD, _
    pdwInnerContentType          AS DWORD, _
    BYVAL pbDecoded              AS BYTE PTR, _
    pcbDecoded                   AS DWORD, _
    ppXchgCert                   AS ANY, _  ' CCERT_CONTEXT PTR PTR
    ppSignerCert                 AS ANY _  ' CCERT_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptDecodeMessage IMPORT "CRYPT32.DLL" ALIAS "CryptDecodeMessage" ( _
   BYVAL dwMsgTypeFlags AS DWORD _                      ' __in DWORD dwMsgTypeFlags
 , BYREF pDecryptPara AS CRYPT_DECRYPT_MESSAGE_PARA _   ' __in PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara
 , BYREF pVerifyPara AS CRYPT_VERIFY_MESSAGE_PARA _     ' __in PCRYPT_VERIFY_MESSAGE_PARA pVerifyPara
 , BYVAL dwSignerIndex AS DWORD _                       ' __in DWORD dwSignerIndex
 , BYVAL pbEncodedBlob AS BYTE PTR _                    ' __in const BYTE *pbEncodedBlob
 , BYVAL cbEncodedBlob AS DWORD _                       ' __in DWORD cbEncodedBlob
 , BYVAL dwPrevInnerContentType AS DWORD _              ' __in DWORD dwPrevInnerContentType
 , BYREF pdwMsgType AS DWORD _                          ' __out_opt DWORD *pdwMsgType
 , BYREF pdwInnerContentType AS DWORD _                 ' __out_opt DWORD *pdwInnerContentType
 , BYVAL pbDecoded AS BYTE PTR _                        ' __out_opt BYTE *pbDecoded
 , BYREF pcbDecoded AS DWORD _                          ' __inout OPTIONAL DWORD *pcbDecoded
 , OPTIONAL BYREF ppXchgCert AS ANY _                   ' __out_opt PCCERT_CONTEXT *ppXchgCert
 , OPTIONAL BYREF ppSignerCert AS ANY _                 ' __out_opt PCCERT_CONTEXT *ppSignerCert
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Hash the message.
'//
'//  If fDetachedHash is TRUE, only the ComputedHash is encoded in the
'//  pbHashedBlob. Otherwise, both the ToBeHashed and ComputedHash
'//  are encoded.
'//
'//  pcbHashedBlob or pcbComputedHash can be NULL, indicating the caller
'//  isn't interested in getting the output.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptHashMessage LIB "Crypt32.dll" _
    ALIAS "CryptHashMessage" ( _
    pHashPara            AS CRYPT_HASH_MESSAGE_PARA, _
    BYVAL fDetachedHash  AS LONG, _  ' BOOL
    BYVAL cToBeHashed    AS DWORD, _
    rgpbToBeHashed       AS ANY, _
    rgcbToBeHashed       AS ANY, _
    BYVAL pbHashedBlob   AS BYTE PTR, _
    pcbHashedBlob        AS DWORD, _
    BYVAL pbComputedHash AS BYTE PTR, _
    pcbComputedHash      AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptHashMessage IMPORT "CRYPT32.DLL" ALIAS "CryptHashMessage" ( _
   BYREF pHashPara AS CRYPT_HASH_MESSAGE_PARA _         ' __in PCRYPT_HASH_MESSAGE_PARA pHashPara
 , BYVAL fDetachedHash AS LONG _                        ' __in BOOL fDetachedHash
 , BYVAL cToBeHashed AS DWORD _                         ' __in DWORD cToBeHashed
 , BYVAL rgpbToBeHashed AS BYTE PTR _                   ' __in const BYTE *rgpbToBeHashed[]
 , BYREF rgcbToBeHashed AS DWORD _                      ' __in DWORD rgcbToBeHashed[]
 , BYVAL pbHashedBlob AS BYTE PTR _                     ' __out_opt BYTE *pbHashedBlob
 , BYREF pcbHashedBlob AS DWORD _                       ' __inout OPTIONAL DWORD *pcbHashedBlob
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out_opt BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout OPTIONAL DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Verify a hashed message.
'//
'//  pcbToBeHashed or pcbComputedHash can be NULL,
'//  indicating the caller isn't interested in getting the output.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptVerifyMessageHash IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyMessageHash" ( _
   BYREF pHashPara AS CRYPT_HASH_MESSAGE_PARA _         ' __in PCRYPT_HASH_MESSAGE_PARA pHashPara
 , BYVAL pbHashedBlob AS BYTE PTR _                     ' __in BYTE *pbHashedBlob
 , BYVAL cbHashedBlob AS DWORD _                        ' __in DWORD cbHashedBlob
 , BYVAL pbToBeHashed AS BYTE PTR _                     ' __out_opt BYTE *pbToBeHashed
 , BYREF pcbToBeHashed AS DWORD _                       ' __inout OPTIONAL DWORD *pcbToBeHashed
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out_opt BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout OPTIONAL DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify a hashed message containing a detached hash.
'//  The "to be hashed" content is passed in separately. No
'//  decoded output. Otherwise, identical to CryptVerifyMessageHash.
'//
'//  pcbComputedHash can be NULL, indicating the caller isn't interested
'//  in getting the output.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptVerifyDetachedMessageHash LIB "Crypt32.dll" _
    ALIAS "CryptVerifyDetachedMessageHash" ( _
    pHashPara                AS CRYPT_HASH_MESSAGE_PARA, _
    BYVAL pbDetachedHashBlob AS BYTE PTR, _
    BYVAL cbDetachedHashBlob AS DWORD, _
    BYVAL cToBeHashed        AS DWORD, _
    rgpbToBeHashed           AS ANY, _
    rgcbToBeHashed           AS ANY, _
    BYVAL pbComputedHash     AS BYTE PTR, _
    pcbComputedHash          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptVerifyDetachedMessageHash IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyDetachedMessageHash" ( _
   BYREF pHashPara AS CRYPT_HASH_MESSAGE_PARA _         ' __in PCRYPT_HASH_MESSAGE_PARA pHashPara
 , BYVAL pbDetachedHashBlob AS BYTE PTR _               ' __in BYTE *pbDetachedHashBlob
 , BYVAL cbDetachedHashBlob AS DWORD _                  ' __in DWORD cbDetachedHashBlob
 , BYVAL cToBeHashed AS DWORD _                         ' __in DWORD cToBeHashed
 , BYVAL rgpbToBeHashed AS BYTE PTR _                   ' __in const BYTE *rgpbToBeHashed[]
 , BYREF rgcbToBeHashed AS DWORD _                      ' __in DWORD rgcbToBeHashed[]
 , BYVAL pbComputedHash AS BYTE PTR _                   ' __out_opt BYTE *pbComputedHash
 , BYREF pcbComputedHash AS DWORD _                     ' __inout OPTIONAL DWORD *pcbComputedHash
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Sign the message using the provider's private key specified in the
'//  parameters. A dummy SignerId is created and stored in the message.
'//
'//  Normally used until a certificate has been created for the key.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptSignMessageWithKey IMPORT "CRYPT32.DLL" ALIAS "CryptSignMessageWithKey" ( _
   BYREF pSignPara AS CRYPT_KEY_SIGN_MESSAGE_PARA _     ' __in PCRYPT_KEY_SIGN_MESSAGE_PARA pSignPara
 , BYVAL pbToBeSigned AS BYTE PTR _                     ' __in const BYTE *pbToBeSigned
 , BYVAL cbToBeSigned AS DWORD _                        ' __in DWORD cbToBeSigned
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __out BYTE *pbSignedBlob
 , BYREF pcbSignedBlob AS DWORD _                       ' __inout DWORD *pcbSignedBlob
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Verify a signed message using the specified public key info.
'//
'//  Normally called by a CA until it has created a certificate for the
'//  key.
'//
'//  pPublicKeyInfo contains the public key to use to verify the signed
'//  message. If NULL, the signature isn't verified (for instance, the decoded
'//  content may contain the PublicKeyInfo).
'//
'//  pcbDecoded can be NULL, indicating the caller isn't interested
'//  in getting the decoded content.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptVerifyMessageSignatureWithKey IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyMessageSignatureWithKey" ( _
   BYREF pVerifyPara AS CRYPT_KEY_VERIFY_MESSAGE_PARA _ ' __in PCRYPT_KEY_VERIFY_MESSAGE_PARA pVerifyPara
 , BYREF pPublicKeyInfo AS CERT_PUBLIC_KEY_INFO _       ' __in_opt PCERT_PUBLIC_KEY_INFO pPublicKeyInfo
 , BYVAL pbSignedBlob AS BYTE PTR _                     ' __in const BYTE *pbSignedBlob
 , BYVAL cbSignedBlob AS DWORD _                        ' __in DWORD cbSignedBlob
 , BYVAL pbDecoded AS BYTE PTR _                        ' __out_opt BYTE *pbDecoded
 , BYREF pcbDecoded AS DWORD _                          ' __inout OPTIONAL DWORD *pcbDecoded
 ) AS LONG                                              ' BOOL

'//+=========================================================================
'//  System Certificate Store Data Structures and APIs
'//==========================================================================


'//+-------------------------------------------------------------------------
'//  Get a system certificate store based on a subsystem protocol.
'//
'//  Current examples of subsystems protocols are:
'//      "MY"    Cert Store hold certs with associated Private Keys
'//      "CA"    Certifying Authority certs
'//      "ROOT"  Root Certs
'//      "SPC"   Software publisher certs
'//
'//
'//  If hProv is NULL the default provider "1" is opened for you.
'//  When the store is closed the provider is release. Otherwise
'//  if hProv is not NULL, no provider is created or released.
'//
'//  The returned Cert Store can be searched for an appropriate Cert
'//  using the Cert Store API's (see certstor.h)
'//
'//  When done, the cert store should be closed using CertStoreClose
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertOpenSystemStoreA IMPORT "CRYPT32.DLL" ALIAS "CertOpenSystemStoreA" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYREF szSubsystemProtocol AS ASCIIZ _                ' __in LPCSTR     szSubsystemProtocol
 ) AS DWORD                                             ' HCERTSTORE

DECLARE FUNCTION CertOpenSystemStoreW IMPORT "CRYPT32.DLL" ALIAS "CertOpenSystemStoreW" ( _
   BYVAL hProv AS DWORD _                               ' __in HCRYPTPROV hProv
 , BYREF szSubsystemProtocol AS WSTRINGZ _              ' __in LPCWSTR    szSubsystemProtocol
 ) AS DWORD                                             ' HCERTSTORE

#IF %DEF(%UNICODE)
   MACRO CertOpenSystemStore = CertOpenSystemStoreW
#ELSE
   MACRO CertOpenSystemStore = CertOpenSystemStoreA
#ENDIF

DECLARE FUNCTION CertAddEncodedCertificateToSystemStoreA IMPORT "CRYPT32.DLL" ALIAS "CertAddEncodedCertificateToSystemStoreA" ( _
   BYREF szCertStoreName AS ASCIIZ _                    ' __in LPCSTR      szCertStoreName
 , BYVAL pbCertEncoded AS BYTE PTR _                    ' __in const BYTE *pbCertEncoded
 , BYVAL cbCertEncoded AS DWORD _                       ' __in DWORD       cbCertEncoded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CertAddEncodedCertificateToSystemStoreW IMPORT "CRYPT32.DLL" ALIAS "CertAddEncodedCertificateToSystemStoreW" ( _
   BYREF szCertStoreName AS WSTRINGZ _                  ' __in LPCWSTR     szCertStoreName
 , BYVAL pbCertEncoded AS BYTE PTR _                    ' __in const BYTE *pbCertEncoded
 , BYVAL cbCertEncoded AS DWORD _                       ' __in DWORD       cbCertEncoded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CertAddEncodedCertificateToSystemStore = CertAddEncodedCertificateToSystemStoreW
#ELSE
   MACRO CertAddEncodedCertificateToSystemStore = CertAddEncodedCertificateToSystemStoreA
#ENDIF

'//+-------------------------------------------------------------------------
'//  Find all certificate chains tying the given issuer name to any certificate
'//  that the current user has a private key for.
'//
'//  If no certificate chain is found, FALSE is returned with LastError set
'//  to CRYPT_E_NOT_FOUND and the counts zeroed.
'//
'//  IE 3.0 ASSUMPTION:
'//   The client certificates are in the "My" system store. The issuer
'//   cerificates may be in the "Root", "CA" or "My" system stores.
'//--------------------------------------------------------------------------

' // Size = 36 bytes
TYPE CERT_CHAIN DWORD
   cCerts         AS DWORD
   certs          AS CERT_BLOB PTR
   keyLocatorInfo AS CRYPT_KEY_PROV_INFO
END TYPE

'// WINCRYPT32API    This is not exported by crypt32, it is exported by softpub

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FindCertsByIssuer LIB "SoftPub.dll" _
    ALIAS "FindCertsByIssuer" ( _
    pCertChains               AS CERT_CHAIN, _
    BYVAL pcbCertChains       AS DWORD PTR, _
    BYVAL pcCertChains        AS DWORD PTR, _  ' count of certificates chains returned
    BYVAL pbEncodedIssuerName AS BYTE PTR, _   ' DER encoded issuer name
    BYVAL cbEncodedIssuerName AS DWORD, _      ' count in bytes of encoded issuer name
    pwszPurpose               AS WSTRINGZ, _   ' "ClientAuth" or "CodeSigning"
    BYVAL dwKeySpec           AS DWORD _       ' only return signers supporting this keyspec
    ) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION FindCertsByIssuer IMPORT "CRYPT32.DLL" ALIAS "FindCertsByIssuer" ( _
   BYREF pCertChains AS CERT_CHAIN _                    ' __out PCERT_CHAIN pCertChains
 , BYREF pcbCertChains AS DWORD _                       ' __inout DWORD *pcbCertChains
 , BYREF pcCertChains AS DWORD _                        ' __out DWORD *pcCertChains
 , BYVAL pbEncodedIssuerName AS BYTE PTR _              ' __in BYTE* pbEncodedIssuerName
 , BYVAL cbEncodedIssuerName AS DWORD _                 ' __in DWORD cbEncodedIssuerName
 , BYREF pwszPurpose AS WSTRINGZ _                      ' __in LPCWSTR pwszPurpose
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 ) AS LONG                                              ' HRESULT
#ENDIF

'//-------------------------------------------------------------------------
'//
'//  CryptQueryObject takes a CERT_BLOB or a file name and returns the
'//  information about the content in the blob or in the file.
'//
'//  Parameters:
'//  INPUT   dwObjectType:
'//                       Indicate the type of the object.  Should be one of the
'//                       following:
'//                          CERT_QUERY_OBJECT_FILE
'//                          CERT_QUERY_OBJECT_BLOB
'//
'//  INPUT   pvObject:
'//                        If dwObjectType == CERT_QUERY_OBJECT_FILE, it is a
'//                        LPWSTR, that is, the pointer to a wchar file name
'//                        if dwObjectType == CERT_QUERY_OBJECT_BLOB, it is a
'//                        PCERT_BLOB, that is, a pointer to a CERT_BLOB
'//
'//  INPUT   dwExpectedContentTypeFlags:
'//                        Indicate the expected contenet type.
'//                        Can be one of the following:
'//                              CERT_QUERY_CONTENT_FLAG_ALL  (the content can be any type)
'//                              CERT_QUERY_CONTENT_FLAG_CERT
'//                              CERT_QUERY_CONTENT_FLAG_CTL
'//                              CERT_QUERY_CONTENT_FLAG_CRL
'//                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE
'//                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT
'//                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL
'//                              CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL
'//                              CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED
'//                              CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED
'//                              CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED
'//                              CERT_QUERY_CONTENT_FLAG_PKCS10
'//                              CERT_QUERY_CONTENT_FLAG_PFX
'//                              CERT_QUERY_CONTENT_FLAG_CERT_PAIR
'//
'//  INPUT   dwExpectedFormatTypeFlags:
'//                        Indicate the expected format type.
'//                        Can be one of the following:
'//                              CERT_QUERY_FORMAT_FLAG_ALL (the content can be any format)
'//                              CERT_QUERY_FORMAT_FLAG_BINARY
'//                              CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED
'//                              CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED
'//
'//
'//  INPUT   dwFlags
'//                        Reserved flag.  Should always set to 0
'//
'//  OUTPUT  pdwMsgAndCertEncodingType
'//                        Optional output.  If NULL != pdwMsgAndCertEncodingType,
'//                        it contains the encoding type of the content as any
'//                        combination of the following:
'//                              X509_ASN_ENCODING
'//                              PKCS_7_ASN_ENCODING
'//
'//  OUTPUT  pdwContentType
'//                        Optional output.  If NULL!=pdwContentType, it contains
'//                        the content type as one of the the following:
'//                              CERT_QUERY_CONTENT_CERT
'//                              CERT_QUERY_CONTENT_CTL
'//                              CERT_QUERY_CONTENT_CRL
'//                              CERT_QUERY_CONTENT_SERIALIZED_STORE
'//                              CERT_QUERY_CONTENT_SERIALIZED_CERT
'//                              CERT_QUERY_CONTENT_SERIALIZED_CTL
'//                              CERT_QUERY_CONTENT_SERIALIZED_CRL
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED
'//                              CERT_QUERY_CONTENT_PKCS7_UNSIGNED
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
'//                              CERT_QUERY_CONTENT_PKCS10
'//                              CERT_QUERY_CONTENT_PFX
'//                              CERT_QUERY_CONTENT_CERT_PAIR
'//
'//  OUTPUT  pdwFormatType
'//                        Optional output.  If NULL !=pdwFormatType, it
'//                        contains the format type of the content as one of the
'//                        following:
'//                              CERT_QUERY_FORMAT_BINARY
'//                              CERT_QUERY_FORMAT_BASE64_ENCODED
'//                              CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED
'//
'//
'//  OUTPUT  phCertStore
'//                        Optional output.  If NULL !=phStore,
'//                        it contains a cert store that includes all of certificates,
'//                        CRL, and CTL in the object if the object content type is
'//                        one of the following:
'//                              CERT_QUERY_CONTENT_CERT
'//                              CERT_QUERY_CONTENT_CTL
'//                              CERT_QUERY_CONTENT_CRL
'//                              CERT_QUERY_CONTENT_SERIALIZED_STORE
'//                              CERT_QUERY_CONTENT_SERIALIZED_CERT
'//                              CERT_QUERY_CONTENT_SERIALIZED_CTL
'//                              CERT_QUERY_CONTENT_SERIALIZED_CRL
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
'//                              CERT_QUERY_CONTENT_CERT_PAIR
'//
'//                       Caller should free *phCertStore via CertCloseStore.
'//
'//
'//  OUTPUT  phMsg        Optional output.  If NULL != phMsg,
'//                        it contains a handle to a opened message if
'//                        the content type is one of the following:
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED
'//                              CERT_QUERY_CONTENT_PKCS7_UNSIGNED
'//                              CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED
'//
'//                       Caller should free *phMsg via CryptMsgClose.
'//
'//  OUTPUT pContext     Optional output.  If NULL != pContext,
'//                      it contains either a PCCERT_CONTEXT or PCCRL_CONTEXT,
'//                      or PCCTL_CONTEXT based on the content type.
'//
'//                      If the content type is CERT_QUERY_CONTENT_CERT or
'//                      CERT_QUERY_CONTENT_SERIALIZED_CERT, it is a PCCERT_CONTEXT;
'//                      Caller should free the pContext via CertFreeCertificateContext.
'//
'//                      If the content type is CERT_QUERY_CONTENT_CRL or
'//                      CERT_QUERY_CONTENT_SERIALIZED_CRL, it is a PCCRL_CONTEXT;
'//                      Caller should free the pContext via CertFreeCRLContext.
'//
'//                      If the content type is CERT_QUERY_CONTENT_CTL or
'//                      CERT_QUERY_CONTENT_SERIALIZED_CTL, it is a PCCTL_CONTEXT;
'//                      Caller should free the pContext via CertFreeCTLContext.
'//
'//  If the *pbObject is of type CERT_QUERY_CONTENT_PKCS10 or CERT_QUERY_CONTENT_PFX, CryptQueryObject
'//  will not return anything in *phCertstore, *phMsg, or *ppvContext.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptQueryObject IMPORT "CRYPT32.DLL" ALIAS "CryptQueryObject" ( _
   BYVAL dwObjectType AS DWORD _                        ' __in  DWORD      dwObjectType
 , BYREF pvObject AS ANY _                              ' __in  const void *pvObject
 , BYVAL dwExpectedContentTypeFlags AS DWORD _          ' __in  DWORD      dwExpectedContentTypeFlags
 , BYVAL dwExpectedFormatTypeFlags AS DWORD _           ' __in  DWORD      dwExpectedFormatTypeFlags
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD      dwFlags
 , BYREF pdwMsgAndCertEncodingType AS DWORD _           ' __out DWORD      *pdwMsgAndCertEncodingType
 , BYREF pdwContentType AS DWORD _                      ' __out DWORD      *pdwContentType
 , BYREF pdwFormatType AS DWORD _                       ' __out DWORD      *pdwFormatType
 , BYREF phCertStore AS DWORD _                         ' __out HCERTSTORE *phCertStore
 , BYREF phMsg AS DWORD _                               ' __out HCRYPTMSG  *phMsg
 , BYREF ppvContext AS ANY _                            ' __out const void **ppvContext
 ) AS LONG                                              ' BOOL

'//-------------------------------------------------------------------------
'//dwObjectType for CryptQueryObject
'//-------------------------------------------------------------------------
%CERT_QUERY_OBJECT_FILE         = &H00000001???
%CERT_QUERY_OBJECT_BLOB         = &H00000002???

'//-------------------------------------------------------------------------
'//dwContentType for CryptQueryObject
'//-------------------------------------------------------------------------
'//encoded single certificate
%CERT_QUERY_CONTENT_CERT                = 1???
'//encoded single CTL
%CERT_QUERY_CONTENT_CTL                 = 2???
'//encoded single CRL
%CERT_QUERY_CONTENT_CRL                 = 3???
'//serialized store
%CERT_QUERY_CONTENT_SERIALIZED_STORE    = 4???
'//serialized single certificate
%CERT_QUERY_CONTENT_SERIALIZED_CERT     = 5???
'//serialized single CTL
%CERT_QUERY_CONTENT_SERIALIZED_CTL      = 6???
'//serialized single CRL
%CERT_QUERY_CONTENT_SERIALIZED_CRL      = 7???
'//a PKCS#7 signed message
%CERT_QUERY_CONTENT_PKCS7_SIGNED        = 8???
'//a PKCS#7 message, such as enveloped message.  But it is not a signed message,
%CERT_QUERY_CONTENT_PKCS7_UNSIGNED      = 9???
'//a PKCS7 signed message embedded in a file
%CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED  = 10???
'//an encoded PKCS#10
%CERT_QUERY_CONTENT_PKCS10              = 11???
'//an encoded PKX BLOB
%CERT_QUERY_CONTENT_PFX                 = 12???
'//an encoded CertificatePair (contains forward and/or reverse cross certs)
%CERT_QUERY_CONTENT_CERT_PAIR           = 13???
'//an encoded PFX BLOB, which was loaded to phCertStore
%CERT_QUERY_CONTENT_PFX_AND_LOAD        = 14???


'//-------------------------------------------------------------------------
'//dwExpectedConentTypeFlags for CryptQueryObject
'//-------------------------------------------------------------------------

'//encoded single certificate
'#define     CERT_QUERY_CONTENT_FLAG_CERT   \
'                ( 1 << CERT_QUERY_CONTENT_CERT)
%CERT_QUERY_CONTENT_FLAG_CERT = &H2???

'//encoded single CTL
'#define     CERT_QUERY_CONTENT_FLAG_CTL   \
'                ( 1 << CERT_QUERY_CONTENT_CTL)
%CERT_QUERY_CONTENT_FLAG_CTL = &H4???

'//encoded single CRL
'#define     CERT_QUERY_CONTENT_FLAG_CRL   \
'                ( 1 << CERT_QUERY_CONTENT_CRL)
%CERT_QUERY_CONTENT_FLAG_CRL = &H8???

'//serialized store
'#define     CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE   \
'                ( 1 << CERT_QUERY_CONTENT_SERIALIZED_STORE)
%CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE = &H10???

'//serialized single certificate
'#define     CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT   \
'                ( 1 << CERT_QUERY_CONTENT_SERIALIZED_CERT)
%CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT = &H20???

'//serialized single CTL
'#define     CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL   \
'                ( 1 << CERT_QUERY_CONTENT_SERIALIZED_CTL)
%CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL = &H40???

'//serialized single CRL
'#define     CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL   \
'                ( 1 << CERT_QUERY_CONTENT_SERIALIZED_CRL)
%CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL = &H80???

'//an encoded PKCS#7 signed message
'#define     CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED   \
'                ( 1 << CERT_QUERY_CONTENT_PKCS7_SIGNED)
%CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED = &H100???

'//an encoded PKCS#7 message.  But it is not a signed message
'#define     CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED   \
'                ( 1 << CERT_QUERY_CONTENT_PKCS7_UNSIGNED)
%CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED = &H200???

'//the content includes an embedded PKCS7 signed message
'#define     CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED  \
'                ( 1 << CERT_QUERY_CONTENT_PKCS7_SIGNED_EMBED)
%CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED = &H400???

'//an encoded PKCS#10
'#define     CERT_QUERY_CONTENT_FLAG_PKCS10   \
'                ( 1 << CERT_QUERY_CONTENT_PKCS10)
%CERT_QUERY_CONTENT_FLAG_PKCS10 = &H800???

'//an encoded PFX BLOB
'#define     CERT_QUERY_CONTENT_FLAG_PFX      \
'                ( 1 << CERT_QUERY_CONTENT_PFX)
%CERT_QUERY_CONTENT_FLAG_PFX = &H1000???

'//an encoded CertificatePair (contains forward and/or reverse cross certs)
'#define     CERT_QUERY_CONTENT_FLAG_CERT_PAIR   \
'                ( 1 << CERT_QUERY_CONTENT_CERT_PAIR)
%CERT_QUERY_CONTENT_FLAG_CERT_PAIR = &H2000???

'//an encoded PFX BLOB, and we do want to load it (not included in
'//CERT_QUERY_CONTENT_FLAG_ALL)
'#define     CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD    \
'                ( 1 << CERT_QUERY_CONTENT_PFX_AND_LOAD)

%CERT_QUERY_CONTENT_FLAG_PFX_AND_LOAD = &H4000???

'//content can be any type
%CERT_QUERY_CONTENT_FLAG_ALL = _
                %CERT_QUERY_CONTENT_FLAG_CERT OR _
                %CERT_QUERY_CONTENT_FLAG_CTL OR _
                %CERT_QUERY_CONTENT_FLAG_CRL OR _
                %CERT_QUERY_CONTENT_FLAG_SERIALIZED_STORE OR _
                %CERT_QUERY_CONTENT_FLAG_SERIALIZED_CERT OR _
                %CERT_QUERY_CONTENT_FLAG_SERIALIZED_CTL OR _
                %CERT_QUERY_CONTENT_FLAG_SERIALIZED_CRL OR _
                %CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED OR _
                %CERT_QUERY_CONTENT_FLAG_PKCS7_UNSIGNED OR _
                %CERT_QUERY_CONTENT_FLAG_PKCS7_SIGNED_EMBED OR _
                %CERT_QUERY_CONTENT_FLAG_PKCS10 OR _
                %CERT_QUERY_CONTENT_FLAG_PFX OR _
                %CERT_QUERY_CONTENT_FLAG_CERT_PAIR

'//-------------------------------------------------------------------------
'//dwFormatType for CryptQueryObject
'//-------------------------------------------------------------------------
'//the content is in binary format
%CERT_QUERY_FORMAT_BINARY                = 1???

'//the content is base64 encoded
%CERT_QUERY_FORMAT_BASE64_ENCODED        = 2???

'//the content is ascii hex encoded with "{ASN}" prefix
%CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED = 3???
'//-------------------------------------------------------------------------
'//dwExpectedFormatTypeFlags for CryptQueryObject
'//-------------------------------------------------------------------------
'//the content is in binary format
'#define     CERT_QUERY_FORMAT_FLAG_BINARY         \
'                ( 1 << CERT_QUERY_FORMAT_BINARY)
%CERT_QUERY_FORMAT_FLAG_BINARY = &H2???

'//the content is base64 encoded
'#define     CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED \
'                ( 1 << CERT_QUERY_FORMAT_BASE64_ENCODED)
%CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED = &H4???

'//the content is ascii hex encoded with "{ASN}" prefix
'#define     CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED \
'                ( 1 << CERT_QUERY_FORMAT_ASN_ASCII_HEX_ENCODED)
%CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED = &H8???

'//the content can be of any format
'#define     CERT_QUERY_FORMAT_FLAG_ALL              \
'            CERT_QUERY_FORMAT_FLAG_BINARY   |       \
'            CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED | \
'            CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED

%CERT_QUERY_FORMAT_FLAG_ALL = _
            %CERT_QUERY_FORMAT_FLAG_BINARY OR _
            %CERT_QUERY_FORMAT_FLAG_BASE64_ENCODED OR _
            %CERT_QUERY_FORMAT_FLAG_ASN_ASCII_HEX_ENCODED


'//
'// Crypt32 Memory Management Routines.  All Crypt32 API which return allocated
'// buffers will do so via CryptMemAlloc, CryptMemRealloc.  Clients can free
'// those buffers using CryptMemFree.  Also included is CryptMemSize
'//

DECLARE FUNCTION CryptMemAlloc IMPORT "CRYPT32.DLL" ALIAS "CryptMemAlloc" ( _
   BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 ) AS DWORD                                             ' LPVOID

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptMemRealloc LIB "Crypt32.dll" ALIAS "CryptMemRealloc" ( _
    pv           AS ANY, _  ' LPVOID
    BYVAL cbSize AS DWORD _
    ) AS DWORD  ' LPVOID
#ELSE
DECLARE FUNCTION CryptMemRealloc IMPORT "CRYPT32.DLL" ALIAS "CryptMemRealloc" ( _
   BYVAL pv AS DWORD _                                  ' __in LPVOID pv
 , BYVAL cbSize AS DWORD _                              ' __in ULONG cbSize
 ) AS DWORD                                             ' LPVOID
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB CryptMemFree LIB "Crypt32.dll" ALIAS "CryptMemFree" ( _
    pv AS ANY _  ' LPVOID
    )
#ELSE
DECLARE SUB CryptMemFree IMPORT "CRYPT32.DLL" ALIAS "CryptMemFree" ( _
   BYVAL pv AS DWORD _                                  ' __in LPVOID pv
 )                                                      ' void
#ENDIF

'//
'// Crypt32 Asynchronous Parameter Management Routines.  All Crypt32 API which
'// expose asynchronous mode operation use a Crypt32 Async Handle to pass
'// around information about the operation e.g. callback routines.  The
'// following API are used for manipulation of the async handle
'//

'typedef HANDLE HCRYPTASYNC, *PHCRYPTASYNC;

'typedef VOID (WINAPI *PFN_CRYPT_ASYNC_PARAM_FREE_FUNC) (
'    LPSTR pszParamOid,
'    LPVOID pvParam
'    );

'SUB CRYPT_ASYNC_PARAM_FREE_FUNC ( _
'   BYREF pszParamOid AS ASCIIZ _                        ' LPSTR pszParamOid
' , BYVAL pvParam AS DWORD _                             ' LPVOID pvParam
' )                                                      ' void

DECLARE FUNCTION CryptCreateAsyncHandle IMPORT "CRYPT32.DLL" ALIAS "CryptCreateAsyncHandle" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phAsync AS DWORD _                             ' __out PHCRYPTASYNC phAsync
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSetAsyncParam LIB "Crypt32.dll" _
    ALIAS "CryptSetAsyncParam" ( _
    BYVAL hAsync  AS DWORD, _   ' HCRYPTASYNC
    pszParamOid   AS ASCIIZ, _
    pvParam       AS ANY, _     ' LPVOID
    BYVAL pfnFree AS DWORD _    ' PFN_CRYPT_ASYNC_PARAM_FREE_FUNC
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptSetAsyncParam IMPORT "CRYPT32.DLL" ALIAS "CryptSetAsyncParam" ( _
   BYVAL hAsync AS DWORD _                              ' __in HCRYPTASYNC hAsync
 , BYREF pszParamOid AS ASCIIZ _                        ' __in LPSTR pszParamOid
 , BYVAL pvParam AS DWORD _                             ' __in LPVOID pvParam
 , OPTIONAL BYVAL pfnFree AS DWORD _                    ' __in_opt PFN_CRYPT_ASYNC_PARAM_FREE_FUNC pfnFree
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CryptGetAsyncParam IMPORT "CRYPT32.DLL" ALIAS "CryptGetAsyncParam" ( _
   BYVAL hAsync AS DWORD _                              ' __in HCRYPTASYNC hAsync
 , BYREF pszParamOid AS ASCIIZ _                        ' __in LPSTR pszParamOid
 , BYREF ppvParam AS ANY _                              ' __out LPVOID* ppvParam
 , OPTIONAL BYREF ppfnFree AS DWORD _                   ' __out_opt PFN_CRYPT_ASYNC_PARAM_FREE_FUNC* ppfnFree
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptCloseAsyncHandle IMPORT "CRYPT32.DLL" ALIAS "CryptCloseAsyncHandle" ( _
   BYVAL hAsync AS DWORD _                              ' __in HCRYPTASYNC hAsync
 ) AS LONG                                              ' BOOL

'//
'// Crypt32 Remote Object Retrieval Routines.  This API allows retrieval of
'// remote PKI objects where the location is given by an URL.  The remote
'// object retrieval manager exposes two provider models.  One is the "Scheme
'// Provider" model which allows for installable protocol providers as defined
'// by the URL scheme e.g. ldap, http, ftp.  The scheme provider entry point is
'// the same as the CryptRetrieveObjectByUrl however the *ppvObject returned
'// is ALWAYS a counted array of encoded bits (one per object retrieved).  The
'// second provider model is the "Context Provider" model which allows for
'// installable creators of CAPI2 context handles (objects) based on the
'// retrieved encoded bits.  These are dispatched based on the object OID given
'// in the call to CryptRetrieveObjectByUrl.
'//

' // Size = 8 bytes
TYPE CRYPT_BLOB_ARRAY DWORD
   cBlob  AS DWORD
   rgBlob AS CRYPT_DATA_BLOB PTR
END TYPE

' // Size = 12 bytes
TYPE CRYPT_CREDENTIALS DWORD
   cbSize            AS DWORD        ' DWORD
   pszCredentialsOid AS ASCIIZ PTR   ' LPCSTR
   pvCredentials     AS DWORD        ' LPVOID
END TYPE

'#define CREDENTIAL_OID_PASSWORD_CREDENTIALS_A ((LPCSTR)1)
'#define CREDENTIAL_OID_PASSWORD_CREDENTIALS_W ((LPCSTR)2)

%CREDENTIAL_OID_PASSWORD_CREDENTIALS   = 1
%CREDENTIAL_OID_PASSWORD_CREDENTIALS_A = 1
%CREDENTIAL_OID_PASSWORD_CREDENTIALS_W = 2

' // Size = 12 bytes
TYPE CRYPT_PASSWORD_CREDENTIALSA DWORD
   cbSize      AS DWORD        ' DWORD
   pszUsername AS ASCIIZ PTR   ' LPSTR
   pszPassword AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE CRYPT_PASSWORD_CREDENTIALSW DWORD
   cbSize      AS DWORD          ' DWORD
   pszUsername AS WSTRINGZ PTR   ' LPWSTR
   pszPassword AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO CRYPT_PASSWORD_CREDENTIALS = CRYPT_PASSWORD_CREDENTIALSW
#ELSE
   MACRO CRYPT_PASSWORD_CREDENTIALS = CRYPT_PASSWORD_CREDENTIALSA
#ENDIF

'//
'// Scheme Provider Signatures
'//

'// The following is obsolete and has been replaced with the following
'// definition
$SCHEME_OID_RETRIEVE_ENCODED_OBJECT_FUNC = "SchemeDllRetrieveEncodedObject"

'// 2-8-02 Server 2003 changed to use UNICODE Url strings instead of multibyte
$SCHEME_OID_RETRIEVE_ENCODED_OBJECTW_FUNC = "SchemeDllRetrieveEncodedObjectW"

'typedef VOID (WINAPI *PFN_FREE_ENCODED_OBJECT_FUNC) (
'    LPCSTR pszObjectOid,
'    PCRYPT_BLOB_ARRAY pObject,
'    LPVOID pvFreeContext
'    );

'SUB FREE_ENCODED_OBJECT_FUNC ( _
'   BYREF pszObjectOid AS ASCIIZ, _                      ' LPCSTR pszObjectOid
' , BYREF pObject AS CRYPT_BLOB_ARRAY, _                 ' PCRYPT_BLOB_ARRAY pObject
' , BYVAL pvFreeContext AS DWORD _                       ' LPVOID pvFreeContext
' )                                                      ' void

'//
'// SchemeDllRetrieveEncodedObject was replaced in Server 2003 with
'// the following. (Changed to use UNICODE Url Strings.)
'//

'//
'// SchemeDllRetrieveEncodedObjectW has the following signature:
'//
'// BOOL WINAPI SchemeDllRetrieveEncodedObjectW (
'//                   IN LPCWSTR pwszUrl,
'//                   IN LPCSTR pszObjectOid,
'//                   IN DWORD dwRetrievalFlags,
'//                   IN DWORD dwTimeout,                // milliseconds
'//                   OUT PCRYPT_BLOB_ARRAY pObject,
'//                   OUT PFN_FREE_ENCODED_OBJECT_FUNC* ppfnFreeObject,
'//                   OUT LPVOID* ppvFreeContext,
'//                   IN HCRYPTASYNC hAsyncRetrieve,
'//                   IN PCRYPT_CREDENTIALS pCredentials,
'//                   IN PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
'//                   )
'//

'//
'// Context Provider Signatures
'//

$CONTEXT_OID_CREATE_OBJECT_CONTEXT_FUNC = "ContextDllCreateObjectContext"

%CONTEXT_OID_CERTIFICATE = 1   ' ((LPCSTR)1)
%CONTEXT_OID_CRL         = 2   ' ((LPCSTR)2)
%CONTEXT_OID_CTL         = 3   ' ((LPCSTR)3)
%CONTEXT_OID_PKCS7       = 4   ' ((LPCSTR)4)
%CONTEXT_OID_CAPI2_ANY   = 5   ' ((LPCSTR)5)
%CONTEXT_OID_OCSP_RESP   = 6   ' ((LPCSTR)6)

'//
'// ContextDllCreateObjectContext has the following signature:
'//
'// BOOL WINAPI ContextDllCreateObjectContext (
'//                    IN LPCSTR pszObjectOid,
'//                    IN DWORD dwRetrievalFlags,
'//                    IN PCRYPT_BLOB_ARRAY pObject,
'//                    OUT LPVOID* ppvContext
'//                    )
'//

'//
'// Remote Object Retrieval API
'//

'//
'// Retrieval flags
'//

%CRYPT_RETRIEVE_MULTIPLE_OBJECTS         = &H00000001???
%CRYPT_CACHE_ONLY_RETRIEVAL              = &H00000002???
%CRYPT_WIRE_ONLY_RETRIEVAL               = &H00000004???
%CRYPT_DONT_CACHE_RESULT                 = &H00000008???
%CRYPT_ASYNC_RETRIEVAL                   = &H00000010???
%CRYPT_STICKY_CACHE_RETRIEVAL            = &H00001000???
%CRYPT_LDAP_SCOPE_BASE_ONLY_RETRIEVAL    = &H00002000???
%CRYPT_OFFLINE_CHECK_RETRIEVAL           = &H00004000???

'// When the following flag is set, the following 2 NULL terminated ascii
'// strings are inserted at the beginning of each returned blob:
'//  "%d\0%s\0", dwEntryIndex, pszAttribute
'//
'//  The first dwEntryIndex is 0, "0\0".
'//
'// When set, pszObjectOid must be NULL, so that a PCRYPT_BLOB_ARRAY is returned.
%CRYPT_LDAP_INSERT_ENTRY_ATTRIBUTE       = &H00008000???

'// Set this flag to digitally sign all of the ldap traffic to and from a
'// Windows 2000 LDAP server using the Kerberos authentication protocol.
'// This feature provides integrity required by some applications.
%CRYPT_LDAP_SIGN_RETRIEVAL               = &H00010000???

'// Set this flag to inhibit automatic authentication handling. See the
'// wininet flag, INTERNET_FLAG_NO_AUTH, for more details.
%CRYPT_NO_AUTH_RETRIEVAL                 = &H00020000???

'// Performs an A-Record only DNS lookup on the supplied host string.
'// This prevents bogus DNS queries from being generated when resolving host
'// names. Use this flag whenever passing a hostname as opposed to a
'// domain name for the hostname parameter.
'//
'// See LDAP_OPT_AREC_EXCLUSIVE defined in winldap.h for more details.
%CRYPT_LDAP_AREC_EXCLUSIVE_RETRIEVAL     = &H00040000???

'// Apply AIA URL restrictions, such as, validate retrieved content before
'// writing to cache.
%CRYPT_AIA_RETRIEVAL                     = &H00080000???

'// For HTTP: use POST instead of the default GET
'//
'// The POST additional binary data and header strings are appended to
'// the host name and path URL as follows:
'//  + L'/'<Optional url escaped and base64 encoded additional data>
'//  + L'?'<Optional additional headers>
'//
'// Here's an example of an OCSP POST URL:
'//  http://ocsp.openvalidation.org/MEIwQDA%2BMDwwOjAJBgUrDgMCGgUABBQdKNE
'//      wjytjKBQADcgM61jfflNpyQQUv1NDgnjQnsOA5RtnygUA37lIg6UCA
'//      QI%3D?Content-Type: application/ocsp-request
'//
'//
'// When this flag is set, CryptRetrieveObjectByUrl, searches for the
'// last L'/' and L'?' POST marker characters in the URL string.
'// These are removed from the URL before it is passed to the WinHttp
'// APIs. The L'?' string is passed as the AdditionHeaders to
'// WinHttpSendRequest. The L'/' string is url unescaped (%xx converted
'// to appropriate character) and base64 decoded into binary. This
'// decoded binary is passed as the additional data to WinHttpSendRequest.
%CRYPT_HTTP_POST_RETRIEVAL               = &H00100000???

'// When this flag is set we won't attempt to bypass any potential proxy caches.
'// If a proxy cache wasn't explicitly bypassed, fProxyCacheRetrieval will be
'// set in pAuxInfo. Only applicable to http URL retrievals.
%CRYPT_PROXY_CACHE_RETRIEVAL             = &H00200000???

'// When this flag is set, for a conditional retrieval returning not modified,
'// TRUE is returned and *ppvObject is set to NULL. For a nonNULL pAuxInfo,
'// dwHttpStatusCode is set to winhttp.h's HTTP_STATUS_NOT_MODIFIED. Otherwise,
'// *ppvObject is updated for a successful retrieval. Only applicable to
'// http URL retrievals.
%CRYPT_NOT_MODIFIED_RETRIEVAL            = &H00400000???

'//
'// Data verification retrieval flags
'//
'// CRYPT_VERIFY_CONTEXT_SIGNATURE is used to get signature verification
'// on the context created.  In this case pszObjectOid must be non-NULL and
'// pvVerify points to the signer certificate context
'//
'// CRYPT_VERIFY_DATA_HASH is used to get verification of the blob data
'// retrieved by the protocol.  The pvVerify points to an URL_DATA_HASH
'// structure (TBD)
'//

%CRYPT_VERIFY_CONTEXT_SIGNATURE  = &H00000020???
%CRYPT_VERIFY_DATA_HASH          = &H00000040???

'//
'// Time Valid Object flags
'//

%CRYPT_KEEP_TIME_VALID               = &H00000080???
%CRYPT_DONT_VERIFY_SIGNATURE         = &H00000100???
%CRYPT_DONT_CHECK_TIME_VALIDITY      = &H00000200???

'// The default checks if ftNextUpdate >= ftValidFor. Set this flag to
'// check if ftThisUpdate >= ftValidFor.
%CRYPT_CHECK_FRESHNESS_TIME_VALIDITY = &H00000400???

%CRYPT_ACCUMULATIVE_TIMEOUT          = &H00000800???

'// Set this flag to only use OCSP AIA URLs.
%CRYPT_OCSP_ONLY_RETRIEVAL           = &H01000000???

'//
'// Cryptnet URL Cache Pre-Fetch Info
'//
' // Size = 40 bytes
TYPE CRYPTNET_URL_CACHE_PRE_FETCH_INFO DWORD
   cbSize         AS DWORD   ' DWORD
   dwObjectType   AS DWORD   ' DWORD
   ' // Possible errors:
   ' //  S_OK                - Pending
   ' //  ERROR_MEDIA_OFFLINE - CRL pre-fetch disabled due to OCSP offline.
   ' //  ERROR_FILE_OFFLINE  - Unchanged pre-fetch content
   ' //  ERROR_INVALID_DATA  - Invalid pre-fetch content
   ' //  Other errors        - Unable to retrieve pre-fetch content
   dwError        AS DWORD   ' DWORD
   dwReserved     AS DWORD   ' DWORD
   ThisUpdateTime AS FILETIME
   NextUpdateTime AS FILETIME
   PublishTime    AS FILETIME   ' // May be zero
END TYPE

'// Pre-fetch ObjectTypes
%CRYPTNET_URL_CACHE_PRE_FETCH_NONE         = 0
%CRYPTNET_URL_CACHE_PRE_FETCH_BLOB         = 1
%CRYPTNET_URL_CACHE_PRE_FETCH_CRL          = 2
%CRYPTNET_URL_CACHE_PRE_FETCH_OCSP         = 3
%CRYPTNET_URL_CACHE_PRE_FETCH_AUTOROOT_CAB = 5

'//
'// Cryptnet URL Cache Flush Info
'//
' // Size = 16 bytes
TYPE CRYPTNET_URL_CACHE_FLUSH_INFO DWORD
   cbSize          AS DWORD   ' DWORD
   ' // If pre-fetching is enabled, following is ignored
   ' //
   ' // 0          - use default flush exempt seconds (2 weeks)
   ' // 0xFFFFFFFF - disable flushing
   dwExemptSeconds AS DWORD   ' DWORD
   ' // Time the object expires. The above dwExemptSeconds is added to
   ' // to determine the flush time. The LastSyncTime is used if
   ' // after this time.
   ExpireTime      AS FILETIME
END TYPE

%CRYPTNET_URL_CACHE_DEFAULT_FLUSH               = 0
%CRYPTNET_URL_CACHE_DISABLE_FLUSH               = &HFFFFFFFF???

'//
'// Cryptnet URL Cache Response Info
'//
' // Size = 28 bytes
TYPE CRYPTNET_URL_CACHE_RESPONSE_INFO DWORD FILL
   cbSize           AS DWORD          ' DWORD
   wResponseType    AS WORD           ' WORD
   wResponseFlags   AS WORD           ' WORD
   ' // The following are zero if not present
   LastModifiedTime AS FILETIME
   dwMaxAge         AS DWORD          ' DWORD
   pwszETag         AS WSTRINGZ PTR   ' LPCWSTR
   dwProxyId        AS DWORD          ' DWORD
END TYPE


'// ResponseTypes
%CRYPTNET_URL_CACHE_RESPONSE_NONE           = 0
%CRYPTNET_URL_CACHE_RESPONSE_HTTP           = 1

'// ResponseFlags
%CRYPTNET_URL_CACHE_RESPONSE_VALIDATED      = &H8000???

'//
'// CryptRetrieveObjectByUrl Auxilliary Info
'//
'//
'// All unused fields in this data structure must be zeroed. More fields
'// could be added in a future release.
'//

'typedef struct _CRYPT_RETRIEVE_AUX_INFO {
'    DWORD                               cbSize;
'    FILETIME                            *pLastSyncTime;

'    // 0 => implies no limit
'    DWORD                               dwMaxUrlRetrievalByteCount;

'    // To get any PreFetchInfo, set the following pointer to a
'    // CRYPTNET_URL_CACHE_PRE_FETCH_INFO structure with its cbSize set
'    // upon input. For no PreFetchInfo, except for cbSize, the data
'    // structure is zeroed upon return.
'    PCRYPTNET_URL_CACHE_PRE_FETCH_INFO  pPreFetchInfo;

'    // To get any FlushInfo, set the following pointer to a
'    // CRYPTNET_URL_CACHE_FLUSH_INFO structure with its cbSize set
'    // upon input. For no FlushInfo, except for cbSize, the data structure
'    // is zeroed upon return.
'    PCRYPTNET_URL_CACHE_FLUSH_INFO      pFlushInfo;

'    // To get any ResponseInfo, set the following pointer to the address
'    // of a PCRYPTNET_URL_CACHE_RESPONSE_INFO pointer updated with
'    // the allocated structure. For no ResponseInfo, *ppResponseInfo is set
'    // to NULL. Otherwise, *ppResponseInfo must be free via CryptMemFree().
'    PCRYPTNET_URL_CACHE_RESPONSE_INFO   *ppResponseInfo;

'    // If nonNULL, the specified prefix string is prepended to the
'    // cached filename.
'    LPWSTR                              pwszCacheFileNamePrefix;

'    // If nonNULL, any cached information before this time is considered
'    // time invalid. For CRYPT_CACHE_ONLY_RETRIEVAL, if there is a
'    // cached entry before this time, LastError is set to ERROR_INVALID_TIME.
'    // Also used to set max-age for http retrievals.
'    LPFILETIME                          pftCacheResync;

'    // The following flag is set upon return if CRYPT_PROXY_CACHE_RETRIEVAL
'    // was set in dwRetrievalFlags and the proxy cache wasn't explicitly
'    // bypassed for the retrieval. This flag won't be explicitly cleared.
'    // This flag will only be set for http URL retrievals.
'    BOOL                                fProxyCacheRetrieval;

'    // This value is only updated upon return for a nonSuccessful status code
'    // returned in a HTTP response header. This value won't be explicitly
'    // cleared. This value will only be updated for http or https URL
'    // retrievals.
'    //
'    // If CRYPT_NOT_MODIFIED_RETRIEVAL was set in dwFlags, set to winhttp.h's
'    // HTTP_STATUS_NOT_MODIFIED if the retrieval returned not modified. In
'    // this case TRUE is returned with *ppvObject set to NULL.
'    DWORD                               dwHttpStatusCode;
'} CRYPT_RETRIEVE_AUX_INFO, *PCRYPT_RETRIEVE_AUX_INFO;

' // Size = 40 bytes
TYPE CRYPT_RETRIEVE_AUX_INFO DWORD
   cbSize                     AS DWORD          ' DWORD
   pLastSyncTime              AS FILETIME PTR   ' FILETIME*
   dwMaxUrlRetrievalByteCount AS DWORD          ' DWORD
   pPreFetchInfo              AS CRYPTNET_URL_CACHE_PRE_FETCH_INFO PTR   ' PCRYPTNET_URL_CACHE_PRE_FETCH_INFO
   pFlushInfo                 AS CRYPTNET_URL_CACHE_FLUSH_INFO PTR       ' PCRYPTNET_URL_CACHE_FLUSH_INFO
   ppResponseInfo             AS CRYPTNET_URL_CACHE_RESPONSE_INFO PTR    ' PCRYPTNET_URL_CACHE_RESPONSE_INFO *
   pwszCacheFileNamePrefix    AS WSTRINGZ PTR   ' LPWSTR
   pftCacheResync             AS FILETIME PTR   ' LPFILETIME
   fProxyCacheRetrieval       AS LONG           ' BOOL
   dwHttpStatusCode           AS DWORD          ' DWORD
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptRetrieveObjectByUrlA LIB "CryptNet.dll" _
    ALIAS "CryptRetrieveObjectByUrlA" ( _
    pszUrl                 AS ASCIIZ, _
    pszObjectOid           AS ASCIIZ, _
    BYVAL dwRetrievalFlags AS DWORD, _
    BYVAL dwTimeout        AS DWORD, _  ' milliseconds
    ppvObject              AS ANY, _    ' LPVOID *
    BYVAL hAsyncRetrieve   AS DWORD, _  ' HCRYPTASYNC
    pCredentials           AS CRYPT_CREDENTIALS, _
    pvVerify               AS ANY, _    ' LPVOID
    pAuxInfo               AS CRYPT_RETRIEVE_AUX_INFO _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptRetrieveObjectByUrlA IMPORT "CRYPT32.DLL" ALIAS "CryptRetrieveObjectByUrlA" ( _
   BYREF pszUrl AS ASCIIZ _                             ' __in LPCSTR pszUrl
 , BYREF pszObjectOid AS ASCIIZ _                       ' __in LPCSTR pszObjectOid
 , BYVAL dwRetrievalFlags AS DWORD _                    ' __in DWORD dwRetrievalFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYREF ppvObject AS ANY _                             ' __out LPVOID* ppvObject
 , BYVAL hAsyncRetrieve AS DWORD _                      ' __in HCRYPTASYNC hAsyncRetrieve
 , OPTIONAL BYREF pCredentials AS CRYPT_CREDENTIALS _   ' __in_opt PCRYPT_CREDENTIALS pCredentials
 , OPTIONAL BYVAL pvVerify AS DWORD _                   ' __in_opt LPVOID pvVerify
 , OPTIONAL BYREF pAuxInfo AS CRYPT_RETRIEVE_AUX_INFO _ ' __in_opt PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptRetrieveObjectByUrlW LIB "CryptNet.dll" _
    ALIAS "CryptRetrieveObjectByUrlW" ( _
    pszUrl                 AS WSTRINGZ, _
    pszObjectOid           AS WSTRINGZ, _
    BYVAL dwRetrievalFlags AS DWORD, _
    BYVAL dwTimeout        AS DWORD, _  ' milliseconds
    ppvObject              AS ANY, _    ' LPVOID *
    BYVAL hAsyncRetrieve   AS DWORD, _  ' HCRYPTASYNC
    pCredentials           AS CRYPT_CREDENTIALS, _
    pvVerify               AS ANY, _    ' LPVOID
    pAuxInfo               AS CRYPT_RETRIEVE_AUX_INFO _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptRetrieveObjectByUrlW IMPORT "CRYPT32.DLL" ALIAS "CryptRetrieveObjectByUrlW" ( _
   BYREF pszUrl AS WSTRINGZ _                           ' __in LPCWSTR pszUrl
 , BYREF pszObjectOid AS WSTRINGZ _                     ' __in LPCWSTR pszObjectOid
 , BYVAL dwRetrievalFlags AS DWORD _                    ' __in DWORD dwRetrievalFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYREF ppvObject AS ANY _                             ' __out LPVOID* ppvObject
 , BYVAL hAsyncRetrieve AS DWORD _                      ' __in HCRYPTASYNC hAsyncRetrieve
 , OPTIONAL BYREF pCredentials AS CRYPT_CREDENTIALS _   ' __in_opt PCRYPT_CREDENTIALS pCredentials
 , OPTIONAL BYVAL pvVerify AS DWORD _                   ' __in_opt LPVOID pvVerify
 , OPTIONAL BYREF pAuxInfo AS CRYPT_RETRIEVE_AUX_INFO _ ' __in_opt PCRYPT_RETRIEVE_AUX_INFO pAuxInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO CryptRetrieveObjectByUrl = CryptRetrieveObjectByUrlW
#ELSE
   MACRO CryptRetrieveObjectByUrl = CryptRetrieveObjectByUrlA
#ENDIF

'//
'// Call back function to cancel object retrieval
'//
'// The function can be installed on a per thread basis.
'// If CryptInstallCancelRetrieval is called for multiple times, only the most recent
'// installation will be kept.
'//
'// This is only effective for http, https, gopher, and ftp protocol.
'// It is ignored by the rest of the protocols.


'typedef BOOL (WINAPI *PFN_CRYPT_CANCEL_RETRIEVAL)(
'    IN DWORD dwFlags,
'    IN void  *pvArg
'    );

'FUNCTION CRYPT_CANCEL_RETRIEVAL ( _
'   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' , BYVAL pvArg AS DWORD _                               ' __in void  *pvArg
' ) AS LONG                                              ' BOOL

'//
'// PFN_CRYPT_CANCEL_RETRIEVAL
'//
'// This function should return FALSE when the object retrieval should be continued
'// and return TRUE when the object retrieval should be cancelled.
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptInstallCancelRetrieval LIB "CryptNet.dll" _
    ALIAS "CryptInstallCancelRetrieval" ( _
    BYVAL pfnCancel AS DWORD, _ ' PFN_CRYPT_CANCEL_RETRIEVAL
    pvArg           AS ANY, _   ' LPVOID
    BYVAL dwFlags   AS DWORD, _
    pvReserved      AS ANY _    ' LPVOID
) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptInstallCancelRetrieval IMPORT "CRYPT32.DLL" ALIAS "CryptInstallCancelRetrieval" ( _
   BYVAL pfnCancel AS DWORD _                           ' __in PFN_CRYPT_CANCEL_RETRIEVAL pfnCancel
 , BYVAL pvArg AS DWORD _                               ' __in const void *pvArg
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptUninstallCancelRetrieval LIB "CryptNet.dll" _
    ALIAS "CryptUninstallCancelRetrieval" ( _
    BYVAL dwFlags AS DWORD, _
    pvReserved    AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptUninstallCancelRetrieval IMPORT "CRYPT32.DLL" ALIAS "CryptUninstallCancelRetrieval" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void  *pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION CryptCancelAsyncRetrieval IMPORT "CRYPT32.DLL" ALIAS "CryptCancelAsyncRetrieval" ( _
   BYVAL hAsyncRetrieval AS DWORD _                     ' __in HCRYPTASYNC hAsyncRetrieval
 ) AS LONG                                              ' BOOL

'//
'// Remote Object Async Retrieval parameters
'//

'//
'// A client that wants to be notified of asynchronous object retrieval
'// completion sets this parameter on the async handle
'//

'#define CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION ((LPCSTR)1)
%CRYPT_PARAM_ASYNC_RETRIEVAL_COMPLETION = 1

'typedef VOID (WINAPI *PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC) (
'    IN LPVOID pvCompletion,
'    IN DWORD dwCompletionCode,
'    IN LPCSTR pszUrl,
'    IN LPSTR pszObjectOid,
'    IN LPVOID pvObject
'    );

'SUB CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC ( _
'   BYVAL pvCompletion AS DWORD _                       ' __in LPVOID pvCompletion
' , BYVAL dwCompletionCode AS DWORD _                   ' __in DWORD dwCompletionCode
' , BYREF pszUrl AS ASCIIZ _                            ' __in LPCSTR pszUrl
' , BYREF pszObjectOid AS ASCIIZ _                      ' __in LPSTR pszObjectOid
' , BYVAL pvObject AS DWORD _                           ' __in LPVOID pvObject
' )                                                     ' void

' // Size = 8 bytes
TYPE CRYPT_ASYNC_RETRIEVAL_COMPLETION DWORD
   pfnCompletion AS DWORD   ' PFN_CRYPT_ASYNC_RETRIEVAL_COMPLETION_FUNC
   pvCompletion  AS DWORD   ' LPVOID
END TYPE

'//
'// This function is set on the async handle by a scheme provider that
'// supports asynchronous retrieval
'//

'#define CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL ((LPCSTR)2)
%CRYPT_PARAM_CANCEL_ASYNC_RETRIEVAL = 2

'typedef BOOL (WINAPI *PFN_CANCEL_ASYNC_RETRIEVAL_FUNC) (
'    HCRYPTASYNC hAsyncRetrieve
'    );

'FUNCTION CANCEL_ASYNC_RETRIEVAL_FUNC ( _
'   BYVAL DWORD _                                        ' HCRYPTASYNC hAsyncRetrieve
' ) AS LONG                                              ' BOOL

'//
'// Get the locator for a CAPI object
'//

%CRYPT_GET_URL_FROM_PROPERTY         = &H00000001???
%CRYPT_GET_URL_FROM_EXTENSION        = &H00000002???
%CRYPT_GET_URL_FROM_UNAUTH_ATTRIBUTE = &H00000004???
%CRYPT_GET_URL_FROM_AUTH_ATTRIBUTE   = &H00000008???

' // Size = 8 bytes
TYPE CRYPT_URL_ARRAY DWORD
   cUrl     AS DWORD          ' DWORD
   rgwszUrl AS WSTRINGZ PTR   ' LPWSTR*
END TYPE

' // Size = 16 bytes
TYPE CRYPT_URL_INFO DWORD
   cbSize          AS DWORD       ' DWORD
   dwSyncDeltaTime AS DWORD       ' DWORD
   cGroup          AS DWORD       ' DWORD
   rgcGroupEntry   AS DWORD PTR   ' DWORD*
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetObjectUrl LIB "CryptNet.dll" _
    ALIAS "CryptGetObjectUrl" ( _
    pszUrlOid     AS ASCIIZ, _
    pvPara        AS ANY, _   ' LPVOID
    BYVAL dwFlags AS DWORD, _
    pUrlArray     AS CRYPT_URL_ARRAY, _
    pcbUrlArray   AS DWORD, _
    pUrlInfo      AS CRYPT_URL_INFO, _
    pcbUrlInfo    AS DWORD, _
    pvReserved    AS ANY _   ' LPVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptGetObjectUrl IMPORT "CRYPT32.DLL" ALIAS "CryptGetObjectUrl" ( _
   BYREF pszUrlOid AS ASCIIZ _                          ' __in LPCSTR pszUrlOid
 , BYVAL pvPara AS DWORD _                              ' __in LPVOID pvPara
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pUrlArray AS CRYPT_URL_ARRAY _                 ' __out_opt PCRYPT_URL_ARRAY pUrlArray
 , BYREF pcbUrlArray AS DWORD _                         ' __inout DWORD* pcbUrlArray
 , BYREF pUrlInfo AS CRYPT_URL_INFO _                   ' __out_opt PCRYPT_URL_INFO pUrlInfo
 , BYREF pcbUrlInfo AS DWORD _                          ' __inout OPTIONAL DWORD* pcbUrlInfo
 , OPTIONAL BYVAL pvReserved AS DWORD _                 ' __in_opt LPVOID pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

$URL_OID_GET_OBJECT_URL_FUNC = "UrlDllGetObjectUrl"

'//
'// UrlDllGetObjectUrl has the same signature as CryptGetObjectUrl
'//

'//
'// URL_OID_CERTIFICATE_ISSUER
'//
'// pvPara == PCCERT_CONTEXT, certificate whose issuer's URL is being requested
'//
'// This will be retrieved from the authority info access extension or property
'// on the certificate
'//
'// URL_OID_CERTIFICATE_CRL_DIST_POINT
'//
'// pvPara == PCCERT_CONTEXT, certificate whose CRL distribution point is being
'// requested
'//
'// This will be retrieved from the CRL distribution point extension or property
'// on the certificate
'//
'// URL_OID_CTL_ISSUER
'//
'// pvPara == PCCTL_CONTEXT, Signer Index, CTL whose issuer's URL (identified
'// by the signer index) is being requested
'//
'// This will be retrieved from an authority info access attribute method encoded
'// in each signer info in the PKCS7 (CTL)
'//
'// URL_OID_CTL_NEXT_UPDATE
'//
'// pvPara == PCCTL_CONTEXT, Signer Index, CTL whose next update URL is being
'// requested and an optional signer index in case we need to check signer
'// info attributes
'//
'// This will be retrieved from an authority info access CTL extension, property,
'// or signer info attribute method
'//
'// URL_OID_CRL_ISSUER
'//
'// pvPara == PCCRL_CONTEXT, CRL whose issuer's URL is being requested
'//
'// This will be retrieved from a property on the CRL which has been inherited
'// from the subject cert (either from the subject cert issuer or the subject
'// cert distribution point extension).  It will be encoded as an authority
'// info access extension method.
'//
'// URL_OID_CERTIFICATE_FRESHEST_CRL
'//
'// pvPara == PCCERT_CONTEXT, certificate whose freshest CRL distribution point
'// is being requested
'//
'// This will be retrieved from the freshest CRL extension or property
'// on the certificate
'//
'// URL_OID_CRL_FRESHEST_CRL
'//
'// pvPara == PCCERT_CRL_CONTEXT_PAIR, certificate's base CRL whose
'// freshest CRL distribution point is being requested
'//
'// This will be retrieved from the freshest CRL extension or property
'// on the CRL
'//
'// URL_OID_CROSS_CERT_DIST_POINT
'//
'// pvPara == PCCERT_CONTEXT, certificate whose cross certificate distribution
'// point is being requested
'//
'// This will be retrieved from the cross certificate distribution point
'// extension or property on the certificate
'//
'// URL_OID_CERTIFICATE_OCSP
'//
'// pvPara == PCCERT_CONTEXT, certificate whose OCSP URL is being requested
'//
'// This will be retrieved from the authority info access extension or property
'// on the certificate
'//
'// URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT
'//
'// pvPara == PCCERT_CONTEXT, certificate whose OCSP URL and
'// CRL distribution point are being requested
'//
'// This will be retrieved from the authority info access and
'// CRL distribution point extension or property on the certificate.
'// If any OCSP URLs are present, they will be first with each URL prefixed
'// with L"ocsp:". The L"ocsp:" prefix should be removed before using.
'//
'// URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP
'//
'// Same as URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT, except,
'// the CRL URLs will be first
'//
'// URL_OID_CERTIFICATE_ONLY_OCSP
'//
'// Same as URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT, except,
'// only OCSP URLs are retrieved.
'//
'// URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS
'//
'// pvPara == PCCERT_CONTEXT, certificate whose cross certificates
'// are being requested
'//
'// This will be retrieved from the Authority Info Access
'// extension or property on the certificate. Only access methods
'// matching szOID_PKIX_CA_REPOSITORY will be returned.

%URL_OID_CERTIFICATE_ISSUER                  = 1    ' ((LPCSTR)1)
%URL_OID_CERTIFICATE_CRL_DIST_POINT          = 2    ' ((LPCSTR)2)
%URL_OID_CTL_ISSUER                          = 3    ' ((LPCSTR)3)
%URL_OID_CTL_NEXT_UPDATE                     = 4    ' ((LPCSTR)4)
%URL_OID_CRL_ISSUER                          = 5    ' ((LPCSTR)5)
%URL_OID_CERTIFICATE_FRESHEST_CRL            = 6    ' ((LPCSTR)6)
%URL_OID_CRL_FRESHEST_CRL                    = 7    ' ((LPCSTR)7)
%URL_OID_CROSS_CERT_DIST_POINT               = 8    ' ((LPCSTR)8)
%URL_OID_CERTIFICATE_OCSP                    = 9    ' ((LPCSTR)9)
%URL_OID_CERTIFICATE_OCSP_AND_CRL_DIST_POINT = 10   ' ((LPCSTR)10)
%URL_OID_CERTIFICATE_CRL_DIST_POINT_AND_OCSP = 11   ' ((LPCSTR)11)
%URL_OID_CROSS_CERT_SUBJECT_INFO_ACCESS      = 12   ' ((LPCSTR)12)
%URL_OID_CERTIFICATE_ONLY_OCSP               = 13   ' ((LPCSTR)13)

' // Size = 8 bytes
TYPE CERT_CRL_CONTEXT_PAIR DWORD
   pCertContext AS CERT_CONTEXT PTR   ' PCCERT_CONTEXT
   pCrlContext  AS CRL_CONTEXT PTR    ' PCCRL_CONTEXT
END TYPE

'//
'// Get a time valid CAPI2 object
'//

'//+-------------------------------------------------------------------------
'//  The following optional Extra Info may be passed to
'//  CryptGetTimeValidObject().
'//
'//  All unused fields in this data structure must be zeroed. More fields
'//  could be added in a future release.
'//--------------------------------------------------------------------------
' // Size = 28 bytes
TYPE CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO DWORD
   cbSize             AS DWORD   ' DWORD
   ' // If > 0, check that the CRL's number is >=
   iDeltaCrlIndicator AS LONG   ' int
   ' // If nonNULL, any cached information before this time is considered
   ' // time invalid and forces a wire retrieval.
   pftCacheResync     AS FILETIME PTR   ' LPFILETIME
   ' // If nonNull, returns the cache's LastSyncTime
   pLastSyncTime      AS FILETIME PTR   ' LPFILETIME
   ' // If nonNull, returns the internal MaxAge expiration time
   ' // for the object. If the object doesn't have a MaxAge expiration, set
   ' // to zero.
   pMaxAgeTime        AS FILETIME PTR   ' LPFILETIME
   ' // If nonNULL, CertGetCertificateChain() parameters used by the caller.
   ' // Enables independent OCSP signer certificate chain verification.
   pChainPara         AS CERT_REVOCATION_CHAIN_PARA PTR   ' PCERT_REVOCATION_CHAIN_PARA
   ' // Should be used if the DeltaCrlIndicator value is more than 4 bytes
   ' // If nonNull and iDeltaCrlIndicator == MAXLONG, check that the CRL's number is >=
   pDeltaCrlIndicator AS CRYPT_INTEGER_BLOB PTR   ' PCRYPT_INTEGER_BLOB
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetTimeValidObject LIB "CryptNet.dll" _
    ALIAS "CryptGetTimeValidObject" ( _
    pszTimeValidOid AS ASCIIZ, _
    pvPara          AS ANY, _    ' LPVOID
    pIssuer         AS CERT_CONTEXT, _
    pftValidFor     AS FILETIME, _
    BYVAL dwFlags   AS DWORD, _
    BYVAL dwTimeout AS DWORD, _    ' milliseconds
    ppvObject       AS ANY, _    ' LPVOID *
    pCredentials    AS CRYPT_CREDENTIALS, _
    pExtraInfo      AS CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptGetTimeValidObject IMPORT "CRYPT32.DLL" ALIAS "CryptGetTimeValidObject" ( _
   BYREF pszTimeValidOid AS ASCIIZ _                    ' __in LPCSTR pszTimeValidOid
 , BYVAL pvPara AS DWORD _                              ' __in LPVOID pvPara
 , BYVAL pIssuer AS CERT_CONTEXT PTR _                  ' __in PCCERT_CONTEXT pIssuer
 , BYREF pftValidFor AS FILETIME _                      ' __in_opt LPFILETIME pftValidFor
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , OPTIONAL BYREF ppvObject AS ANY _                    ' __out_opt LPVOID* ppvObject
 , OPTIONAL BYREF pCredentials AS CRYPT_CREDENTIALS _   ' __in_opt PCRYPT_CREDENTIALS pCredentials
 , OPTIONAL BYREF pExtraInfo AS DWORD _                 ' __inout_opt PCRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO pExtraInfo
 ) AS LONG                                              ' BOOL
#ENDIF

$TIME_VALID_OID_GET_OBJECT_FUNC = "TimeValidDllGetObject"

'//
'// TimeValidDllGetObject has the same signature as CryptGetTimeValidObject
'//

'//
'// TIME_VALID_OID_GET_CTL
'//
'// pvPara == PCCTL_CONTEXT, the current CTL
'//
'// TIME_VALID_OID_GET_CRL
'//
'// pvPara == PCCRL_CONTEXT, the current CRL
'//
'// TIME_VALID_OID_GET_CRL_FROM_CERT
'//
'// pvPara == PCCERT_CONTEXT, the subject cert
'//
'// TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT
'//
'// pvPara == PCCERT_CONTEXT, the subject cert
'//
'// TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL
'//
'// pvPara == PCCERT_CRL_CONTEXT_PAIR, the subject cert and its base CRL
'//

%TIME_VALID_OID_GET_CTL                    = 1   ' ((LPCSTR)1)
%TIME_VALID_OID_GET_CRL                    = 2   ' ((LPCSTR)2)
%TIME_VALID_OID_GET_CRL_FROM_CERT          = 3   ' ((LPCSTR)3)

%TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CERT = 4   ' ((LPCSTR)4)
%TIME_VALID_OID_GET_FRESHEST_CRL_FROM_CRL  = 5   ' ((LPCSTR)5)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptFlushTimeValidObject LIB "CryptNet.dll" _
    ALIAS "CryptFlushTimeValidObject" ( _
    pszFlushTimeValidOid AS ASCIIZ, _
    pvPara               AS ANY, _  ' LPVOID
    pIssuer              AS CERT_CONTEXT, _
    BYVAL dwFlags        AS DWORD, _
    pvReserved           AS ANY _  ' LPVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptFlushTimeValidObject IMPORT "CRYPT32.DLL" ALIAS "CryptFlushTimeValidObject" ( _
   BYREF pszFlushTimeValidOid AS ASCIIZ _               ' __in LPCSTR pszFlushTimeValidOid
 , BYVAL pvPara AS DWORD _                              ' __in LPVOID pvPara
 , BYVAL pIssuer AS CERT_CONTEXT PTR _                  ' __in PCCERT_CONTEXT pIssuer
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' BOOL
#ENDIF

$TIME_VALID_OID_FLUSH_OBJECT_FUNC = "TimeValidDllFlushObject"

'//
'// TimeValidDllFlushObject has the same signature as CryptFlushTimeValidObject
'//

'//
'// TIME_VALID_OID_FLUSH_CTL
'//
'// pvPara == PCCTL_CONTEXT, the CTL to flush
'//
'// TIME_VALID_OID_FLUSH_CRL
'//
'// pvPara == PCCRL_CONTEXT, the CRL to flush
'//
'// TIME_VALID_OID_FLUSH_CRL_FROM_CERT
'//
'// pvPara == PCCERT_CONTEXT, the subject cert's CRL to flush
'//
'// TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT
'//
'// pvPara == PCCERT_CONTEXT, the subject cert's freshest CRL to flush
'//
'// TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL
'//
'// pvPara == PCCERT_CRL_CONTEXT_PAIR, the subject cert and its base CRL's
'// freshest CRL to flush
'//

%TIME_VALID_OID_FLUSH_CTL                    = 1   ' ((LPCSTR)1)
%TIME_VALID_OID_FLUSH_CRL                    = 2   ' ((LPCSTR)2)
%TIME_VALID_OID_FLUSH_CRL_FROM_CERT          = 3   ' ((LPCSTR)3)

%TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CERT = 4   ' ((LPCSTR)4)
%TIME_VALID_OID_FLUSH_FRESHEST_CRL_FROM_CRL  = 5   ' ((LPCSTR)5)

'//-------------------------------------------------------------------------
'// Data Protection APIs
'//-------------------------------------------------------------------------

'//
'// Data protection APIs enable applications to easily secure data.
'//
'// The base provider provides protection based on the users' logon
'// credentials. The data secured with these APIs follow the same
'// roaming characteristics as HKCU -- if HKCU roams, the data
'// protected by the base provider may roam as well. This makes
'// the API ideal for the munging of data stored in the registry.
'//

'//
'// Prompt struct -- what to tell users about the access
'//
' // Size = 16 bytes
TYPE CRYPTPROTECT_PROMPTSTRUCT DWORD
   cbSize        AS DWORD          ' DWORD
   dwPromptFlags AS DWORD          ' DWORD
   hwndApp       AS DWORD          ' HWND
   szPrompt      AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'//
'// base provider action
'//
'#define CRYPTPROTECT_DEFAULT_PROVIDER   { 0xdf9d8cd0, 0x1501, 0x11d1, {0x8c, 0x7a, 0x00, 0xc0, 0x4f, 0xc2, 0x97, 0xeb} }
$CRYPTPROTECT_DEFAULT_PROVIDER = GUID$("{df9d8cd0-1501-11d1-8c7a-00c04fc297eb}")

'//
'// CryptProtect PromptStruct dwPromtFlags
'//
'//
'// prompt on unprotect
%CRYPTPROTECT_PROMPT_ON_UNPROTECT     = &H1???  ' // 1<<0
'//
'// prompt on protect
%CRYPTPROTECT_PROMPT_ON_PROTECT       = &H2???  ' // 1<<1
%CRYPTPROTECT_PROMPT_RESERVED         = &H04??? ' // reserved, do not use.

'//
'// default to strong variant UI protection (user supplied password currently).
%CRYPTPROTECT_PROMPT_STRONG           = &H08???  ' // 1<<3

'//
'// require strong variant UI protection (user supplied password currently).
%CRYPTPROTECT_PROMPT_REQUIRE_STRONG   = &H10???  ' // 1<<4

'//
'// CryptProtectData and CryptUnprotectData dwFlags
'//
'// for remote-access situations where ui is not an option
'// if UI was specified on protect or unprotect operation, the call
'// will fail and GetLastError() will indicate ERROR_PASSWORD_RESTRICTION
%CRYPTPROTECT_UI_FORBIDDEN        = &H1???

'//
'// per machine protected data -- any user on machine where CryptProtectData
'// took place may CryptUnprotectData
%CRYPTPROTECT_LOCAL_MACHINE       = &H4???

'//
'// force credential synchronize during CryptProtectData()
'// Synchronize is only operation that occurs during this operation
%CRYPTPROTECT_CRED_SYNC           = &H8???

'//
'// Generate an Audit on protect and unprotect operations
'//
%RYPTPROTECT_AUDIT                = &H10???

'//
'// Protect data with a non-recoverable key
'//
%CRYPTPROTECT_NO_RECOVERY         = &H20???


'//
'// Verify the protection of a protected blob
'//
%CRYPTPROTECT_VERIFY_PROTECTION   = &H40???

'//
'// Regenerate the local machine protection
'//
%CRYPTPROTECT_CRED_REGENERATE     = &H80???

'// flags reserved for system use
%CRYPTPROTECT_FIRST_RESERVED_FLAGVAL = &H0FFFFFFF???
%CRYPTPROTECT_LAST_RESERVED_FLAGVAL  = &HFFFFFFFF???

'//
'// flags specific to base provider
'//


#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptProtectData LIB "Crypt32.dll" _
    ALIAS "CryptProtectData" ( _
    BYVAL pDataIn          AS DATA_BLOB PTR, _
    szDataDescr            AS WSTRINGZ, _
    BYVAL pOptionalEntropy AS DATA_BLOB PTR, _
    pvReserved             AS ANY, _   ' LPVOID
    BYVAL pPromptStruct    AS CRYPTPROTECT_PROMPTSTRUCT PTR, _
    BYVAL dwFlags          AS DWORD, _
    BYVAL pDataOut         AS DATA_BLOB PTR _   ' out encr blob
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptProtectData IMPORT "CRYPT32.DLL" ALIAS "CryptProtectData" ( _
   BYREF pDataIn AS DATA_BLOB _                         ' __in DATA_BLOB* pDataIn
 , BYREF szDataDescr AS WSTRINGZ _                      ' __in LPCWSTR szDataDescr
 , BYREF pOptionalEntropy AS DATA_BLOB _                ' __in_opt DATA_BLOB* pOptionalEntropy
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 , BYREF pPromptStruct AS CRYPTPROTECT_PROMPTSTRUCT _   ' __in_opt CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pDataOut AS DATA_BLOB _                        ' __out DATA_BLOB* pDataOut
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptUnprotectData LIB "Crypt32.dll" _
    ALIAS "CryptUnprotectData" ( _
    BYVAL pDataIn          AS DATA_BLOB PTR, _            ' in encr blob
    ppszDataDescr          AS ANY, _  ' LPWSTR *      ' out
    BYVAL pOptionalEntropy AS DATA_BLOB PTR, _
    pvReserved             AS ANY, _  ' PVOID
    BYVAL pPromptStruct    AS CRYPTPROTECT_PROMPTSTRUCT PTR, _
    BYVAL dwFlags          AS DWORD, _
    BYVAL pDataOut         AS DATA_BLOB PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptUnprotectData IMPORT "CRYPT32.DLL" ALIAS "CryptUnprotectData" ( _
   BYREF pDataIn AS DATA_BLOB _                         ' __in DATA_BLOB* pDataIn
 , BYREF ppszDataDescr AS DWORD _                       ' __out_opt LPWSTR* ppszDataDescr
 , BYREF pOptionalEntropy AS DATA_BLOB _                ' __in_opt DATA_BLOB* pOptionalEntropy
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 , BYREF pPromptStruct AS CRYPTPROTECT_PROMPTSTRUCT _   ' __in_opt CRYPTPROTECT_PROMPTSTRUCT* pPromptStruct
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pDataOut AS DATA_BLOB _                        ' __out DATA_BLOB* pDataOut
 ) AS LONG                                              ' BOOL
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINLH)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptUpdateProtectedState LIB "Crypt32.dll" _
    ALIAS "CryptUpdateProtectedState" ( _
    pOldSid         AS SID, _
    pwszOldPassword AS WSTRINGZ, _
    BYVAL dwFlags   AS DWORD, _
    pdwSuccessCount AS DWORD, _
    pdwFailureCount AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptUpdateProtectedState IMPORT "CRYPT32.DLL" ALIAS "CryptUpdateProtectedState" ( _
   BYVAL pOldSid AS DWORD _                             ' __in_opt PSID pOldSid
 , BYREF pwszOldPassword AS WSTRINGZ _                  ' __in_opt LPCWSTR pwszOldPassword
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF pdwSuccessCount AS DWORD _            ' __out_opt DWORD *pdwSuccessCount
 , OPTIONAL BYREF pdwFailureCount AS DWORD _            ' __out_opt DWORD *pdwFailureCount
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WINLH)

'//
'// The buffer length passed into CryptProtectMemory and CryptUnprotectMemory
'// must be a multiple of this length (or zero).
'//

%CRYPTPROTECTMEMORY_BLOCK_SIZE           = 16


'//
'// CryptProtectMemory/CryptUnprotectMemory dwFlags
'//

'//
'// Encrypt/Decrypt within current process context.
'//

%CRYPTPROTECTMEMORY_SAME_PROCESS         = &H00???

'//
'// Encrypt/Decrypt across process boundaries.
'// eg: encrypted buffer passed across LPC to another process which calls CryptUnprotectMemory.
'//

%CRYPTPROTECTMEMORY_CROSS_PROCESS        = &H01???

'//
'// Encrypt/Decrypt across callers with same LogonId.
'// eg: encrypted buffer passed across LPC to another process which calls CryptUnprotectMemory whilst impersonating.
'//

%CRYPTPROTECTMEMORY_SAME_LOGON           = &H02???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptProtectMemory LIB "Crypt32.dll" _
    ALIAS "CryptProtectMemory" ( _
    pDataIn        AS ANY, _   ' LPVOID ' in out data to encrypt
    BYVAL cbDataIn AS DWORD, _ ' multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE
    BYVAL dwFlags  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptProtectMemory IMPORT "CRYPT32.DLL" ALIAS "CryptProtectMemory" ( _
   BYVAL pDataIn AS DWORD _                             ' __inout LPVOID pDataIn
 , BYVAL cbDataIn AS DWORD _                            ' __in DWORD cbDataIn
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptUnprotectMemory LIB "Crypt32.dll" _
    ALIAS "CryptUnprotectMemory" ( _
    pDataIn        AS ANY, _     ' LPVOID ' in out data to decrypt
    BYVAL cbDataIn AS DWORD, _   ' multiple of CRYPTPROTECTMEMORY_BLOCK_SIZE
    BYVAL dwFlags  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptUnprotectMemory IMPORT "CRYPT32.DLL" ALIAS "CryptUnprotectMemory" ( _
   BYVAL pDataIn AS DWORD _                             ' __inout LPVOID pDataIn
 , BYVAL cbDataIn AS DWORD _                            ' __in DWORD cbDataIn
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

'//+=========================================================================
'//  Helper functions to build certificates
'//==========================================================================

'//+-------------------------------------------------------------------------
'//
'// Builds a self-signed certificate and returns a PCCERT_CONTEXT representing
'// the certificate. A hProv must be specified to build the cert context.
'//
'// pSubjectIssuerBlob is the DN for the certifcate. If an alternate subject
'// name is desired it must be specified as an extension in the pExtensions
'// parameter. pSubjectIssuerBlob can NOT be NULL, so minimually an empty DN
'// must be specified.
'//
'// By default:
'// pKeyProvInfo - The CSP is queried for the KeyProvInfo parameters. Only the Provider,
'// Provider Type and Container is queried. Many CSPs don't support these
'// queries and will cause a failure. In such cases the pKeyProvInfo
'// must be specified (RSA BASE works fine).
'//
'// pSignatureAlgorithm - will default to SHA1RSA
'// pStartTime will default to the current time
'// pEndTime will default to 1 year
'// pEntensions will be empty.
'//
'// The returned PCCERT_CONTEXT will reference the private keys by setting the
'// CERT_KEY_PROV_INFO_PROP_ID. However, if this property is not desired specify the
'// CERT_CREATE_SELFSIGN_NO_KEY_INFO in dwFlags.
'//
'// If the cert being built is only a dummy placeholder cert for speed it may not
'// need to be signed. Signing of the cert is skipped if CERT_CREATE_SELFSIGN_NO_SIGN
'// is specified in dwFlags.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertCreateSelfSignCertificate IMPORT "CRYPT32.DLL" ALIAS "CertCreateSelfSignCertificate" ( _
   BYVAL hProv AS DWORD _                               ' __in  HCRYPTPROV                  hProv
 , BYREF pSubjectIssuerBlob AS CERT_NAME_BLOB _         ' __in  PCERT_NAME_BLOB             pSubjectIssuerBlob
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD                       dwFlags
 , OPTIONAL BYREF pKeyProvInfo AS CRYPT_KEY_PROV_INFO _ ' __opt PCRYPT_KEY_PROV_INFO        pKeyProvInfo
 , OPTIONAL BYREF pSignatureAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER _ ' __opt PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm
 , OPTIONAL BYREF pStartTime AS SYSTEMTIME _            ' __opt PSYSTEMTIME                 pStartTime
 , OPTIONAL BYREF pEndTime AS SYSTEMTIME _              ' __opt PSYSTEMTIME                 pEndTime
 , OPTIONAL BYREF pExtensions AS CERT_EXTENSIONS _      ' __opt PCERT_EXTENSIONS            pExtensions
 ) AS DWORD                                             ' PCCERT_CONTEXT

%CERT_CREATE_SELFSIGN_NO_SIGN     = 1
%CERT_CREATE_SELFSIGN_NO_KEY_INFO = 2

'//+=========================================================================
'//  Key Identifier Property Data Structures and APIs
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  Get the property for the specified Key Identifier.
'//
'//  The Key Identifier is the SHA1 hash of the encoded CERT_PUBLIC_KEY_INFO.
'//  The Key Identifier for a certificate can be obtained by getting the
'//  certificate's CERT_KEY_IDENTIFIER_PROP_ID. The
'//  CryptCreateKeyIdentifierFromCSP API can be called to create the Key
'//  Identifier from a CSP Public Key Blob.
'//
'//  A Key Identifier can have the same properties as a certificate context.
'//  CERT_KEY_PROV_INFO_PROP_ID is the property of most interest.
'//  For CERT_KEY_PROV_INFO_PROP_ID, pvData points to a CRYPT_KEY_PROV_INFO
'//  structure. Elements pointed to by fields in the pvData structure follow the
'//  structure. Therefore, *pcbData will exceed the size of the structure.
'//
'//  If CRYPT_KEYID_ALLOC_FLAG is set, then, *pvData is updated with a
'//  pointer to allocated memory. LocalFree() must be called to free the
'//  allocated memory.
'//
'//  By default, searches the CurrentUser's list of Key Identifiers.
'//  CRYPT_KEYID_MACHINE_FLAG can be set to search the LocalMachine's list
'//  of Key Identifiers. When CRYPT_KEYID_MACHINE_FLAG is set, pwszComputerName
'//  can also be set to specify the name of a remote computer to be searched
'//  instead of the local machine.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptGetKeyIdentifierProperty LIB "Crypt32.dll" _
    ALIAS "CryptGetKeyIdentifierProperty" ( _
    pKeyIdentifier   AS CRYPT_HASH_BLOB, _
    BYVAL dwPropId   AS DWORD, _
    BYVAL dwFlags    AS DWORD, _
    pwszComputerName AS WSTRINGZ, _
    pvReserved       AS ANY, _  ' void *
    pvData           AS ANY, _  ' void *
    pcbData          AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptGetKeyIdentifierProperty IMPORT "CRYPT32.DLL" ALIAS "CryptGetKeyIdentifierProperty" ( _
   BYREF pKeyIdentifier AS CRYPT_HASH_BLOB _            ' __in const CRYPT_HASH_BLOB *pKeyIdentifier
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszComputerName AS WSTRINGZ _                 ' __in_opt LPCWSTR pwszComputerName
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYREF pvData AS ANY _                                ' __out void *pvData
 , BYREF pcbData AS DWORD _                             ' __inout DWORD *pcbData
 ) AS LONG                                              ' BOOL
#ENDIF

'// When the following flag is set, searches the LocalMachine instead of the
'// CurrentUser. This flag is applicable to all the KeyIdentifierProperty APIs.
%CRYPT_KEYID_MACHINE_FLAG        = &H00000020???

'// When the following flag is set, *pvData is updated with a pointer to
'// allocated memory. LocalFree() must be called to free the allocated memory.
%CRYPT_KEYID_ALLOC_FLAG          = &H00008000???


'//+-------------------------------------------------------------------------
'//  Set the property for the specified Key Identifier.
'//
'//  For CERT_KEY_PROV_INFO_PROP_ID pvData points to the
'//  CRYPT_KEY_PROV_INFO data structure. For all other properties, pvData
'//  points to a CRYPT_DATA_BLOB.
'//
'//  Setting pvData == NULL, deletes the property.
'//
'//  Set CRYPT_KEYID_MACHINE_FLAG to set the property for a LocalMachine
'//  Key Identifier. Set pwszComputerName, to select a remote computer.
'//
'//  If CRYPT_KEYID_DELETE_FLAG is set, the Key Identifier and all its
'//  properties is deleted.
'//
'//  If CRYPT_KEYID_SET_NEW_FLAG is set, the set fails if the property already
'//  exists. For an existing property, FALSE is returned with LastError set to
'//  CRYPT_E_EXISTS.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptSetKeyIdentifierProperty LIB "Crypt32.dll" _
    ALIAS "CryptSetKeyIdentifierProperty" ( _
    pKeyIdentifier   AS CRYPT_HASH_BLOB, _
    BYVAL dwPropId   AS DWORD, _
    BYVAL dwFlags    AS DWORD, _
    pwszComputerName AS WSTRINGZ, _
    pvReserved       AS ANY, _  ' void *
    pvData           AS ANY _   ' void *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptSetKeyIdentifierProperty IMPORT "CRYPT32.DLL" ALIAS "CryptSetKeyIdentifierProperty" ( _
   BYREF pKeyIdentifier AS CRYPT_HASH_BLOB _            ' __in const CRYPT_HASH_BLOB *pKeyIdentifier
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszComputerName AS WSTRINGZ _                 ' __in_opt LPCWSTR pwszComputerName
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYREF pvData AS ANY _                                ' __in const void *pvData
 ) AS LONG                                              ' BOOL
#ENDIF

'// When the following flag is set, the Key Identifier and all its properties
'// are deleted.
%CRYPT_KEYID_DELETE_FLAG         = &H00000010???

'// When the following flag is set, the set fails if the property already
'// exists.
%CRYPT_KEYID_SET_NEW_FLAG        = &H00002000???


'//+-------------------------------------------------------------------------
'//  For CERT_KEY_PROV_INFO_PROP_ID, rgppvData[] points to a
'//  CRYPT_KEY_PROV_INFO.
'//
'//  Return FALSE to stop the enumeration.
'//--------------------------------------------------------------------------
'typedef BOOL (WINAPI *PFN_CRYPT_ENUM_KEYID_PROP)(
'    IN const CRYPT_HASH_BLOB *pKeyIdentifier,
'    IN DWORD dwFlags,
'    IN void *pvReserved,
'    IN void *pvArg,
'    IN DWORD cProp,
'    IN DWORD *rgdwPropId,
'    IN void **rgpvData,
'    IN DWORD *rgcbData
'    );

'FUNCTION CRYPT_ENUM_KEYID_PROP ( _
'   BYREF pKeyIdentifier AS CRYPT_HASH_BLOB _            ' __in const CRYPT_HASH_BLOB *pKeyIdentifier
' , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
' , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
' , BYVAL pvArg AS DWORD _                               ' __in void *pvArg
' , BYVAL cProp AS DWORD _                               ' __in DWORD cProp
' , BYVAL rgdwPropId AS DWORD PTR _                      ' __in DWORD *rgdwPropId
' , BYVAL rgpvData AS DWORD PTR _                        ' __in void **rgpvData
' , BYVAL rgcbData AS DWORD PTR _                        ' __in DWORD *rgcbData
' ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//  Enumerate the Key Identifiers.
'//
'//  If pKeyIdentifier is NULL, enumerates all Key Identifers. Otherwise,
'//  calls the callback for the specified KeyIdentifier. If dwPropId is
'//  0, calls the callback with all the properties. Otherwise, only calls
'//  the callback with the specified property (cProp = 1).
'//  Furthermore, when dwPropId is specified, skips KeyIdentifiers not
'//  having the property.
'//
'//  Set CRYPT_KEYID_MACHINE_FLAG to enumerate the LocalMachine
'//  Key Identifiers. Set pwszComputerName, to enumerate Key Identifiers on
'//  a remote computer.
'//--------------------------------------------------------------------------
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptEnumKeyIdentifierProperties LIB "Crypt32.dll" _
    ALIAS "CryptEnumKeyIdentifierProperties" ( _
    pKeyIdentifier   AS CRYPT_HASH_BLOB, _
    BYVAL dwPropId   AS DWORD, _
    BYVAL dwFlags    AS DWORD, _
    pwszComputerName AS WSTRINGZ, _
    pvReserved       AS ANY, _  ' void *
    pvArg            AS ANY, _  ' void *
    BYVAL pfnEnum    AS DWORD _  ' PFN_CRYPT_ENUM_KEYID_PROP
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptEnumKeyIdentifierProperties IMPORT "CRYPT32.DLL" ALIAS "CryptEnumKeyIdentifierProperties" ( _
   BYREF pKeyIdentifier AS CRYPT_HASH_BLOB _            ' __in_opt const CRYPT_HASH_BLOB *pKeyIdentifier
 , BYVAL dwPropId AS DWORD _                            ' __in DWORD dwPropId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pwszComputerName AS WSTRINGZ _                 ' __in_opt LPCWSTR pwszComputerName
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYVAL pvArg As DWORD _                               ' __in_opt void *pvArg
 , BYVAL pfnEnum AS DWORD _                             ' __in PFN_CRYPT_ENUM_KEYID_PROP pfnEnum
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Create a KeyIdentifier from the CSP Public Key Blob.
'//
'//  Converts the CSP PUBLICKEYSTRUC into a X.509 CERT_PUBLIC_KEY_INFO and
'//  encodes. The encoded CERT_PUBLIC_KEY_INFO is SHA1 hashed to obtain
'//  the Key Identifier.
'//
'//  By default, the pPubKeyStruc->aiKeyAlg is used to find the appropriate
'//  public key Object Identifier. pszPubKeyOID can be set to override
'//  the default OID obtained from the aiKeyAlg.
'//--------------------------------------------------------------------------
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptCreateKeyIdentifierFromCSP LIB "Crypt32.dll" _
    ALIAS "CryptCreateKeyIdentifierFromCSP" ( _
    BYVAL dwCertEncodingType AS DWORD, _
    pszPubKeyOID             AS ASCIIZ, _
    pPubKeyStruc             AS PUBLICKEYSTRUC, _
    BYVAL cbPubKeyStruc      AS DWORD, _
    BYVAL dwFlags            AS DWORD, _
    pvReserved               AS ANY, _
    BYVAL pbHash             AS BYTE PTR, _
    pcbHash                  AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptCreateKeyIdentifierFromCSP IMPORT "CRYPT32.DLL" ALIAS "CryptCreateKeyIdentifierFromCSP" ( _
   BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYREF pszPubKeyOID AS ASCIIZ _                       ' __in_opt LPCSTR pszPubKeyOID
 , BYREF pPubKeyStruc AS PUBLICKEYSTRUC _               ' __in const PUBLICKEYSTRUC *pPubKeyStruc
 , BYVAL cbPubKeyStruc AS DWORD _                       ' __in DWORD cbPubKeyStruc
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in_opt void *pvReserved
 , BYVAL pbHash AS BYTE PTR _                           ' __out BYTE *pbHash
 , BYREF pcbHash AS DWORD _                             ' __inout DWORD *pcbHash
 ) AS LONG                                              ' BOOL
#ENDIF

'//+=========================================================================
'//  Certificate Chaining Infrastructure
'//==========================================================================

'#define CERT_CHAIN_CONFIG_REGPATH \
'    L"Software\\Microsoft\\Cryptography\\OID\\EncodingType 0\\CertDllCreateCertificateChainEngine\\Config"
$CERT_CHAIN_CONFIG_REGPATH = "Software\Microsoft\Cryptography\OID\EncodingType 0\CertDllCreateCertificateChainEngine\Config"

'// max size of the cryptographic object to download, in bytes
'// NOTE: AIA has different configuration
'#define CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME      \
'    L"MaxUrlRetrievalByteCount"
$CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME = "MaxUrlRetrievalByteCount"
%CERT_CHAIN_MAX_URL_RETRIEVAL_BYTE_COUNT_DEFAULT = (100*1024*1024)

'// The following is a REG_BINARY. It contains the cache resync FILETIME.
'// Any cached information before this time is considered time invalid
'// and forces a wire retrieval. By default this is disabled.

'#define CERT_CHAIN_CACHE_RESYNC_FILETIME_VALUE_NAME    \
'    L"ChainCacheResyncFiletime"
$CERT_CHAIN_CACHE_RESYNC_FILETIME_VALUE_NAME = "ChainCacheResyncFiletime"

'// The following are REG_DWORD's. These configuration parameters are used
'// to disable different chain building semantics enabled by default. Set
'// the appropriate registry value to nonzero to disable.

'#define CERT_CHAIN_DISABLE_MANDATORY_BASIC_CONSTRAINTS_VALUE_NAME  \
'    L"DisableMandatoryBasicConstraints"
$CERT_CHAIN_DISABLE_MANDATORY_BASIC_CONSTRAINTS_VALUE_NAME = "DisableMandatoryBasicConstraints"
'// By default the BasicConstraints extension must be present with CA enabled
'// for non-Root intermediate CA certificates.

'#define CERT_CHAIN_DISABLE_CA_NAME_CONSTRAINTS_VALUE_NAME  \
'    L"DisableCANameConstraints"
$CERT_CHAIN_DISABLE_CA_NAME_CONSTRAINTS_VALUE_NAME = "DisableCANameConstraints"
'// By default the NameConstraints extension is applied to the intermediate
'// CA certificates in addition to the end entity certificate.

'#define CERT_CHAIN_DISABLE_UNSUPPORTED_CRITICAL_EXTENSIONS_VALUE_NAME  \
'    L"DisableUnsupportedCriticalExtensions"
$CERT_CHAIN_DISABLE_UNSUPPORTED_CRITICAL_EXTENSIONS_VALUE_NAME = "DisableUnsupportedCriticalExtensions"
'// By default any unsupported extension marked critical sets the following
'// dwErrorStatus bit: CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT.

'// The following are REG_DWORD's. These configuration parameters are used
'// to restrict Authority Info Access (AIA) URL retrieval.

'#define CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_VALUE_NAME             \
'    L"MaxAIAUrlCountInCert"
$CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_VALUE_NAME = "MaxAIAUrlCountInCert"
%CERT_CHAIN_MAX_AIA_URL_COUNT_IN_CERT_DEFAULT    = 5

'#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_VALUE_NAME \
'    L"MaxAIAUrlRetrievalCountPerChain"
$CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_VALUE_NAME = "MaxAIAUrlRetrievalCountPerChain"
%CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_COUNT_PER_CHAIN_DEFAULT    = 3

'#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME      \
'    L"MaxAIAUrlRetrievalByteCount"
$CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_VALUE_NAME = "MaxAIAUrlRetrievalByteCount"
%CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_BYTE_COUNT_DEFAULT    = 100000

'#define CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_VALUE_NAME      \
'    L"MaxAIAUrlRetrievalCertCount"
$CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_VALUE_NAME = "MaxAIAUrlRetrievalCertCount"
%CERT_CHAIN_MAX_AIA_URL_RETRIEVAL_CERT_COUNT_DEFAULT    = 10

'// The following is a REG_DWORD. If the OCSP response NextUpdate is zero,
'// this value is added to the ThisUpdate to get a nonzero NextUpdate.
'#define CERT_CHAIN_OCSP_VALIDITY_SECONDS_VALUE_NAME                 \
'    L"OcspValiditySeconds"
$CERT_CHAIN_OCSP_VALIDITY_SECONDS_VALUE_NAME = "OcspValiditySeconds"
'// 12 hours
%CERT_CHAIN_OCSP_VALIDITY_SECONDS_DEFAULT    = (12 * 60 * 60)


'// The following are REG_DWORD's. These configuration parameters are
'// used by the following APIs to get a non-blocking, time valid OCSP
'// response for a server certificate chain:
'//   CertOpenServerOcspResponse
'//   CertAddRefServerOcspResponse
'//   CertCloseServerOcspResponse
'//   CertGetServerOcspResponseContext
'//   CertAddRefServerOcspResponseContext
'//   CertFreeServerOcspResponseContext

'// This is the minimum validity of the server OCSP response to be
'// returned by CertGetServerOcspResponseContext(). Since this OCSP
'// response will be returned to the client, it must be sufficiently long
'// so that the client will treat it as being time valid.
'#define CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME \
'    L"SrvOcspRespMinValiditySeconds"
'// 10 minutes
$CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_VALUE_NAME = "SrvOcspRespMinValiditySeconds"
%CERT_SRV_OCSP_RESP_MIN_VALIDITY_SECONDS_DEFAULT = (10 * 60)

'// This is the maximum number of milliseconds for each server OCSP response
'// pre-fetch wire URL retrieval.
'#define CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME \
'    L"SrvOcspRespUrlRetrievalTimeoutMilliseconds"
'// 15 seconds
$CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME = "SrvOcspRespUrlRetrievalTimeoutMilliseconds"
%CERT_SRV_OCSP_RESP_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT = (15 * 1000)

'// This is the maximum number of seconds to do a server OCSP response
'// pre-fetch retrieval before the OCSP response's NextUpdate. The
'// server OCSP response pre-fetch thread will wait until CurrentTime >=
'// NextUpdate - MaxBeforeNextUpdateSeconds before doing the next retrieval.
'#define CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME \
'    L"SrvOcspRespMaxBeforeNextUpdateSeconds"
'// 4 hours
$CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME = "SrvOcspRespMaxBeforeNextUpdateSeconds"
%CERT_SRV_OCSP_RESP_MAX_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT = (4 * 60 * 60)

'// This is the minimum number of seconds to do a server OCSP response
'// pre-fetch retrieval before the OCSP response's NextUpdate.
'// If CurrentTime >= NextUpdate - MinBeforeNextUpdateSeconds, will wait until
'// after NextUpdate + MinAfterNextUpdateSeconds.
'#define CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME \
'    L"SrvOcspRespMinBeforeNextUpdateSeconds"
$CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_VALUE_NAME = "SrvOcspRespMinBeforeNextUpdateSeconds"
'// 2 minutes
%CERT_SRV_OCSP_RESP_MIN_BEFORE_NEXT_UPDATE_SECONDS_DEFAULT = (2 * 60)

'// This is the minimum number of seconds to do a server OCSP response
'// pre-fetch retrieval after the OCSP response's NextUpdate when
'// (NextUpdate - MinBeforeNextUpdateSeconds) < CurrentTime < NextUpdate.
'#define CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME\
'    L"SrvOcspRespMinAfterNextUpdateSeconds"
'// 1 minute
$CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_VALUE_NAME = "SrvOcspRespMinAfterNextUpdateSeconds"
%CERT_SRV_OCSP_RESP_MIN_AFTER_NEXT_UPDATE_SECONDS_DEFAULT = (1 * 60)


'// The following are REG_DWORD's. These configuration parameters are used
'// in the ordering of the revocation retrieval URLs.


'// When the number of cached OCSP URLs associated with the same CDP extension
'// equal or exceed this number, the OCSP AIA URLs aren't used.
'#define CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_VALUE_NAME \
'    L"CryptnetMaxCachedOcspPerCrlCount"
$CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_VALUE_NAME = "CryptnetMaxCachedOcspPerCrlCount"
%CRYPTNET_MAX_CACHED_OCSP_PER_CRL_COUNT_DEFAULT = 500

'// The above registry value can be set to this value, to disable OCSP
'// when a CDP extension is present. Note, a registry value of 0, uses the
'// above default value.
%CRYPTNET_OCSP_AFTER_CRL_DISABLE = &HFFFFFFFF???

'// The following are REG_DWORD's. These configuration parameters are
'// used by the Cryptnet Url Cache Service (CUCS).

'// The following parameter is used as the default flush exempt seconds
'#define CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME \
'    L"CryptnetDefaultFlushExemptSeconds"
$CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_VALUE_NAME = "CryptnetDefaultFlushExemptSeconds"

'// 4 Weeks : 28 days * 24 hours * 60 minutes * 60 seconds
%CRYPTNET_URL_CACHE_DEFAULT_FLUSH_EXEMPT_SECONDS_DEFAULT = (28 * 24 * 60 * 60)

'// Following 2 parameters are used to set the lower and upper limit
'// on the max-age retrievals done before the Publish and NextUpdate times.
'#define CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchMinMaxAgeSeconds"
$CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_VALUE_NAME = "CryptnetPreFetchMinMaxAgeSeconds"
'// 1 hour
%CRYPTNET_PRE_FETCH_MIN_MAX_AGE_SECONDS_DEFAULT = (1 * 60 * 60)

'#define CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchMaxMaxAgeSeconds"
$CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_VALUE_NAME = "CryptnetPreFetchMaxMaxAgeSeconds"
'// 2 Weeks : 14 days * 24 hours * 60 minutes * 60 seconds
%CRYPTNET_PRE_FETCH_MAX_MAX_AGE_SECONDS_DEFAULT = (14 * 24 * 60 * 60)

'// Following 3 parameters are used to calculate the PreFetch start before
'// the NextUpdate
'//
'// Where PreFetchStartTime = PublishTime +
'//                              PublishPeriod / AfterPublishPreFetchDivisor
'//       PreFetchEndTime = NextUpdate -
'//                              PublishPeriod / BeforeNextUpdatePreFetchDivisor
'//
'//       PreFetchPeriod = PreFetchEndTime - PreFetchStartTime
'//
'//       if (PreFetchPeriod < MinBeforeNextUpdatePreFetchPeriodSeconds)
'//          - No PreFetch is done before NextUpdate
'//       else
'//          - PreFetch starts are randomized over this period

'// The start of the PreFetch period is delayed after the start of the
'// Publish period by dividing the PublishPeriod (NextUpdate - PublishTime)
'// by this integer divisor.
'#define CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_VALUE_NAME \
'    L"CryptnetPreFetchAfterPublishPreFetchDivisor"
$CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_VALUE_NAME = "CryptnetPreFetchAfterPublishPreFetchDivisor"
'// 10, where 12 hours / 10 = 72 minutes or 1.2 hours / 10 = 7.2 minutes
%CRYPTNET_PRE_FETCH_AFTER_PUBLISH_PRE_FETCH_DIVISOR_DEFAULT = 10

'// The finish of the PreFetch period occurs before NextUpdate
'// by dividing the PublishPeriod (NextUpdate - PublishTime)
'// by this integer divisor.
'#define CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME \
'    L"CryptnetPreFetchBeforeNextUpdatePreFetchDivisor"
$CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME = "CryptnetPreFetchBeforeNextUpdatePreFetchDivisor"
'// 20, where 12 hours / 20 = 36 minutes or 1.2 hours / 10 = 3.6 minutes
%CRYPTNET_PRE_FETCH_BEFORE_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT = 20

'// The PreFetch period must exceed this minimum duration in seconds
'// to do a PreFetch before NextUpdate
'#define CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchMinBeforeNextUpdatePreFetchSeconds"
$CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME = "CryptnetPreFetchMinBeforeNextUpdatePreFetchSeconds"
'// 1 hour
'//
'// For the default OCSP period of 12 hours using above defaults,
'// PreFetchPeriod = 72 minutes - 7.2 minutes - 3.6 mintes = 61.2 minutes
%CRYPTNET_PRE_FETCH_MIN_BEFORE_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT = (1 * 60 * 60)

'// Following 4 parameters are used to calculate the PreFetch start after
'// the NextUpdate
'//
'// ValidityPeriod = NextUpdate - ThisUpdate
'//
'// PreFetchPeriod = ValidityPeriod / AfterNextUpdatePreFetchDivisor
'//
'// Where PreFetchPeriod is decreased to MaxAfterNextUpdatePreFetchPeriodSeconds
'// or increased to MinAfterNextUpdatePreFetchPeriodSeconds;
'//
'// PreFetchStartTime = NextUpdate
'// PreFetchEndTime = PreFetchStartTime + PreFetchPeriod
'//
'// PreFetch starts are randomized over the above PreFetchPeriod
'//
'// If CurrentTime > RandomPreFetchStartTime, then, the
'// AfterCurrentTimePreFetchPeriodSeconds is randomized and added to
'// CurrentTime for the RandomPreFetchStartTime

'// The PreFetch period after NextUpdate is initially calculated by
'// dividing the ValidityPeriod (NextUpdate - ThisUpdate) by this integer
'// divisor.
'#define CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME \
'    L"CryptnetPreFetchValidityPeriodAfterNextUpdatePreFetchDivisor"
$CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_VALUE_NAME = "CryptnetPreFetchValidityPeriodAfterNextUpdatePreFetchDivisor"
'// 10, where 1 week / 10 = 16.8 hours
%CRYPTNET_PRE_FETCH_VALIDITY_PERIOD_AFTER_NEXT_UPDATE_PRE_FETCH_DIVISOR_DEFAULT = 10

'// If necessary, the above PreFetch period will be decreased
'// to this maximum duration in seconds.
'#define CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchMaxAfterNextUpdatePreFetchPeriodSeconds"
$CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME = "CryptnetPreFetchMaxAfterNextUpdatePreFetchPeriodSeconds"
'// 4 hours
%CRYPTNET_PRE_FETCH_MAX_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT = (4 * 60 * 60)

'// If necessary, the above PreFetch period will be increased
'// to this minimum duration in seconds.
'#define CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchMinAfterNextUpdatePreFetchPeriodSeconds"
$CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME = "CryptnetPreFetchMinAfterNextUpdatePreFetchPeriodSeconds"
'// 30 minutes
%CRYPTNET_PRE_FETCH_MIN_AFTER_NEXT_UPDATE_PRE_FETCH_PERIOD_SECONDS_DEFAULT = (30 * 60)

'// If the CurrentTime is after the above randomized start time, the following
'// parameter will be randomized and added to the CurrentTime.
'#define CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchAfterCurrentTimePreFetchPeriodSeconds"
$CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_VALUE_NAME = "CryptnetPreFetchAfterCurrentTimePreFetchPeriodSeconds"
'// 30 minutes
%CRYPTNET_PRE_FETCH_AFTER_CURRENT_TIME_PRE_FETCH_PERIOD_SECONDS_DEFAULT = (30 * 60)


'// Following parameter specifies the minimum time period between sending
'// trigger URL cache PreFetch LRPC messages to cryptsvc after doing online
'// revocation enabled chain builds.
'#define CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchTriggerPeriodSeconds"
'// 10 minutes
$CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_VALUE_NAME = "CryptnetPreFetchTriggerPeriodSeconds"
%CRYPTNET_PRE_FETCH_TRIGGER_PERIOD_SECONDS_DEFAULT = (10 * 60)

'// The above registry value can be set to this value, to disable the
'// sending of trigger URL cache PreFetch LRPC messages. Note, a registry
'// value of 0, uses the above default value.
%CRYPTNET_PRE_FETCH_TRIGGER_DISABLE = &HFFFFFFFF???

'// Following parameter specifies the delay time to wait to scan the
'// URL cache directory after receiving a trigger LRPC message request.
'#define CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchScanAfterTriggerDelaySeconds"
$CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_VALUE_NAME = "CryptnetPreFetchScanAfterTriggerDelaySeconds"
'// 30 seconds
%CRYPTNET_PRE_FETCH_SCAN_AFTER_TRIGGER_DELAY_SECONDS_DEFAULT = 30

'// Following parameter specifies the maximum amount of time to wait for any
'// PreFetch retrieval to complete
'#define CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_VALUE_NAME \
'    L"CryptnetPreFetchRetrievalTimeoutSeconds"
$CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_VALUE_NAME = "CryptnetPreFetchRetrievalTimeoutSeconds"
'// 5 minutes
%CRYPTNET_PRE_FETCH_RETRIEVAL_TIMEOUT_SECONDS_DEFAULT = (5 * 60)

'//+-------------------------------------------------------------------------
'// The following configuration parameters are store in HKLM group policy
'//--------------------------------------------------------------------------

'#define CERT_GROUP_POLICY_CHAIN_CONFIG_REGPATH \
'    CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH L"\\ChainEngine\\Config"
$CERT_GROUP_POLICY_CHAIN_CONFIG_REGPATH = $CERT_GROUP_POLICY_SYSTEM_STORE_REGPATH & "\ChainEngine\Config"

'// In Vista, the following have been moved from the above HKLM
'// configuration parameters:

'// The following are REG_DWORD's. These configuration parameters are used
'// to override the default URL timeouts in chain building

'// This is the default URL timeout in milliseconds
'#define CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME    \
'    L"ChainUrlRetrievalTimeoutMilliseconds"
$CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME = "ChainUrlRetrievalTimeoutMilliseconds"
'// 15 seconds
%CERT_CHAIN_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT = (15 * 1000)

'// This is the default revocation accumulative URL timeout in milliseconds
'// The first revocation URL retrieval uses half of this timeout
'#define CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME \
'    L"ChainRevAccumulativeUrlRetrievalTimeoutMilliseconds"
$CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_VALUE_NAME = "ChainRevAccumulativeUrlRetrievalTimeoutMilliseconds"
'// 20 seconds
%CERT_CHAIN_REV_ACCUMULATIVE_URL_RETRIEVAL_TIMEOUT_MILLISECONDS_DEFAULT = (20 * 1000)

'// REG_DWORD: Set this value to non-zero in order to enable Internet connections
'// with Unknown Authorization
'#define CERT_RETR_BEHAVIOR_INET_AUTH_VALUE_NAME     L"EnableInetUnknownAuth"
$CERT_RETR_BEHAVIOR_INET_AUTH_VALUE_NAME     = "EnableInetUnknownAuth"

'// REG_DWORD: Set this value to non-zero in order to override Internet
'// connectivity status allowing LOCAL to be treated as INTERNET.
'#define CERT_RETR_BEHAVIOR_INET_STATUS_VALUE_NAME   L"EnableInetLocal"
$CERT_RETR_BEHAVIOR_INET_STATUS_VALUE_NAME   = "EnableInetLocal"

'// REG_DWORD: Set this value to non-zero in order to allow
'// file:// URL scheme.
'#define CERT_RETR_BEHAVIOR_FILE_VALUE_NAME          L"AllowFileUrlScheme"
$CERT_RETR_BEHAVIOR_FILE_VALUE_NAME          = "AllowFileUrlScheme"

'// REG_DWORD: Set this value to non-zero in order to disable
'// LDAP mutual authentication and & encryption.
'#define CERT_RETR_BEHAVIOR_LDAP_VALUE_NAME          L"DisableLDAPSignAndEncrypt"
$CERT_RETR_BEHAVIOR_LDAP_VALUE_NAME          = "DisableLDAPSignAndEncrypt"

'// Note, will allow the machine setting to be used if this value isn't
'// defined.


'// By default AIA OCSP URLs are before CDP CRL URLs. When the number of cached
'// OCSP URLs associated with the same CDP extension equal or exceed this
'// number, the CRL URLs are placed before the OCSP URLs.
'#define CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_VALUE_NAME \
'    L"CryptnetCachedOcspSwitchToCrlCount"
$CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_VALUE_NAME = "CryptnetCachedOcspSwitchToCrlCount"
%CRYPTNET_CACHED_OCSP_SWITCH_TO_CRL_COUNT_DEFAULT = 50

'// The above registry value can be set to this value, to always place
'// the CRL URLs before the OCSP URLs. Note, a registry value of 0, uses the
'// above default value.
%CRYPTNET_CRL_BEFORE_OCSP_ENABLE = &HFFFFFFFF???

'// Support for the following was removed in Vista Changed to use
'// the following OPTIONS flags in HKLM Group Policy

'#define CERT_CHAIN_DISABLE_AIA_URL_RETRIEVAL_VALUE_NAME             \
'    L"DisableAIAUrlRetrieval"
$CERT_CHAIN_DISABLE_AIA_URL_RETRIEVAL_VALUE_NAME = "DisableAIAUrlRetrieval"
'// By default AIA Url Retrieval is enabled. Set this registry value to nonzero
'// to disable

'// This is the name of the REG_DWORD for chain engine Options
'#define CERT_CHAIN_OPTIONS_VALUE_NAME \
'    L"Options"
$CERT_CHAIN_OPTIONS_VALUE_NAME = "Options"
'// Disable AIA URL retrieval when this bit is set in the Options
%CERT_CHAIN_OPTION_DISABLE_AIA_URL_RETRIEVAL                 = &H2
'// Enable SIA URL retrieval when this bit is set in the Options
%CERT_CHAIN_OPTION_ENABLE_SIA_URL_RETRIEVAL                  = &H4

'#define CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_VALUE_NAME \
'    L"CrossCertDownloadIntervalHours"
$CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_VALUE_NAME = "CrossCertDownloadIntervalHours"
'// 7 days
%CERT_CHAIN_CROSS_CERT_DOWNLOAD_INTERVAL_HOURS_DEFAULT       = (24 * 7)

'// When not defined or zero, the CRL validity isn't extended
'#define CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_VALUE_NAME \
'    L"CRLValidityExtensionPeriod"
$CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_VALUE_NAME = "CRLValidityExtensionPeriod"
'// 12 hour
%CERT_CHAIN_CRL_VALIDITY_EXT_PERIOD_HOURS_DEFAULT            = 12

'//
'// The chain engine defines the store namespace and cache partitioning for
'// the Certificate Chaining infrastructure.  A default chain engine
'// is defined for the process which uses all default system stores e.g.
'// Root, CA, Trust, for chain building and caching.  If an application
'// wishes to define its own store namespace or have its own partitioned
'// cache then it can create its own chain engine.  It is advisable to create
'// a chain engine at application startup and use it throughout the lifetime
'// of the application in order to get optimal caching behavior
'//

'typedef HANDLE HCERTCHAINENGINE;

'#define HCCE_CURRENT_USER  ((HCERTCHAINENGINE)NULL)
'#define HCCE_LOCAL_MACHINE ((HCERTCHAINENGINE)0x1)

%HCCE_CURRENT_USER  = 0???
%HCCE_LOCAL_MACHINE = &H1???

'//
'// Create a certificate chain engine.
'//

'//
'// Configuration parameters for the certificate chain engine
'//
'//      hRestrictedRoot - restrict the root store (must be a subset of "Root")
'//
'//      hRestrictedTrust - restrict the store for CTLs
'//
'//      hRestrictedOther - restrict the store for certs and CRLs
'//
'//      cAdditionalStore, rghAdditionalStore - additional stores
'//
'//      hExclusiveRoot - the root store to be used exclusively.
'//                       If not NULL, then the restricted  stores
'//                       the system "Root" and "TrustedPeople" are not used
'//
'//      hExclusiveTrustedPeople - the trusted people store to be used exclusively.
'//                       If not NULL, then the restricted  stores
'//                       the system "Root" and "TrustedPeople" are not used
'//
'//      NOTE:
'//
'//        (hExclusiveRoot, hExclusiveTrustedPeople) are mutually exclusive
'//        with (hRestrictedRoot, hRestrictedTrust, hRestrictedOther).
'//        If either hExclusiveRoot or hExclusiveTrustedPeople are used,
'//        then all restricted handles must be NULL and non of the system
'//        "Root" and "TrustedPeople" are used.
'//
'//      The algorithm used to define the stores for the engine is as
'//            follows:
'//
'//          If NULL!=hExclusiveRoot or NULL!=hExclusiveTrustedPeople
'//              hRoot = hExclusiveRoot
'//
'//              hTrust = hWorld (defined later)
'//
'//              hOther = hWorld
'//
'//              hWorld = hRoot + hExclusiveTrustedPeople + "CA" + "My" + rghAdditionalStore
'//
'//          Else
'//            hRoot = hRestrictedRoot or System Store "Root"
'//
'//            hTrust = hRestrictedTrust or hWorld (defined later)
'//
'//            hOther = hRestrictedOther or (hRestrictedTrust == NULL) ? hWorld :
'//                     hRestrictedTrust + hWorld
'//
'//            hWorld = hRoot + "CA" + "My" + "Trust" + rghAdditionalStore
'//          Endif
'//
'//      dwFlags  - flags
'//
'//          CERT_CHAIN_CACHE_END_CERT - information will be cached on
'//                                      the end cert as well as the other
'//                                      certs in the chain
'//
'//          CERT_CHAIN_THREAD_STORE_SYNC - use separate thread for store syncs
'//                                         and related cache updates
'//
'//          CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL - don't hit the wire to get
'//                                                URL based objects
'//
'//      dwUrlRetrievalTimeout - timeout for wire based URL object retrievals
'//                              (milliseconds)
'//

%CERT_CHAIN_CACHE_END_CERT           = &H00000001???
%CERT_CHAIN_THREAD_STORE_SYNC        = &H00000002???
%CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL = &H00000004???
%CERT_CHAIN_USE_LOCAL_MACHINE_STORE  = &H00000008???
%CERT_CHAIN_ENABLE_CACHE_AUTO_UPDATE = &H00000010???
%CERT_CHAIN_ENABLE_SHARE_STORE       = &H00000020???

' // Size = 48 bytes
TYPE CERT_CHAIN_ENGINE_CONFIG DWORD
   cbSize                    AS DWORD       ' DWORD
   hRestrictedRoot           AS DWORD       ' HCERTSTORE
   hRestrictedTrust          AS DWORD       ' HCERTSTORE
   hRestrictedOther          AS DWORD       ' HCERTSTORE
   cAdditionalStore          AS DWORD       ' DWORD
   rghAdditionalStore        AS DWORD PTR   ' HCERTSTORE*
   dwFlags                   AS DWORD       ' DWORD
   dwUrlRetrievalTimeout     AS DWORD       ' DWORD
   MaximumCachedCertificates AS DWORD       ' DWORD
   CycleDetectionModulus     AS DWORD       ' DWORD
#IF %WINVER >= &H0601
   hExclusiveRoot            AS DWORD       ' HCERTSTORE
   hExclusiveTrustedPeople   AS DWORD       ' HCERTSTORE
#ENDIF
END TYPE

DECLARE FUNCTION CertCreateCertificateChainEngine IMPORT "CRYPT32.DLL" ALIAS "CertCreateCertificateChainEngine" ( _
   BYREF pConfig AS CERT_CHAIN_ENGINE_CONFIG _          ' __in PCERT_CHAIN_ENGINE_CONFIG pConfig
 , BYREF phChainEngine AS DWORD _                       ' __out HCERTCHAINENGINE* phChainEngine
 ) AS LONG                                              ' BOOL

'//
'// Free a certificate trust engine
'//

DECLARE SUB CertFreeCertificateChainEngine IMPORT "CRYPT32.DLL" ALIAS "CertFreeCertificateChainEngine" ( _
   BYVAL hChainEngine AS DWORD _                        ' __in HCERTCHAINENGINE hChainEngine
 )                                                      ' void

'//
'// Resync the certificate chain engine.  This resync's the stores backing
'// the engine and updates the engine caches.
'//

DECLARE FUNCTION CertResyncCertificateChainEngine IMPORT "CRYPT32.DLL" ALIAS "CertResyncCertificateChainEngine" ( _
   BYVAL hChainEngine AS DWORD _                        ' __in HCERTCHAINENGINE hChainEngine
 ) AS LONG                                              ' BOOL

'//
'// When an application requests a certificate chain, the data structure
'// returned is in the form of a CERT_CHAIN_CONTEXT.  This contains
'// an array of CERT_SIMPLE_CHAIN where each simple chain goes from
'// an end cert to a self signed cert and the chain context connects simple
'// chains via trust lists.  Each simple chain contains the chain of
'// certificates, summary trust information about the chain and trust information
'// about each certificate element in the chain.
'//

'//
'// Trust status bits
'//

' // Size = 8 bytes
TYPE CERT_TRUST_STATUS DWORD
   dwErrorStatus AS DWORD   ' DWORD
   dwInfoStatus  AS DWORD   ' DWORD
END TYPE

'//
'// The following are error status bits
'//

'// These can be applied to certificates and chains

%CERT_TRUST_NO_ERROR                             = &H00000000???
%CERT_TRUST_IS_NOT_TIME_VALID                    = &H00000001???
%CERT_TRUST_IS_NOT_TIME_NESTED                   = &H00000002???
%CERT_TRUST_IS_REVOKED                           = &H00000004???
%CERT_TRUST_IS_NOT_SIGNATURE_VALID               = &H00000008???
%CERT_TRUST_IS_NOT_VALID_FOR_USAGE               = &H00000010???
%CERT_TRUST_IS_UNTRUSTED_ROOT                    = &H00000020???
%CERT_TRUST_REVOCATION_STATUS_UNKNOWN            = &H00000040???
%CERT_TRUST_IS_CYCLIC                            = &H00000080???

%CERT_TRUST_INVALID_EXTENSION                    = &H00000100???
%CERT_TRUST_INVALID_POLICY_CONSTRAINTS           = &H00000200???
%CERT_TRUST_INVALID_BASIC_CONSTRAINTS            = &H00000400???
%CERT_TRUST_INVALID_NAME_CONSTRAINTS             = &H00000800???
%CERT_TRUST_HAS_NOT_SUPPORTED_NAME_CONSTRAINT    = &H00001000???

'// In LH, this error will never be set.
%CERT_TRUST_HAS_NOT_DEFINED_NAME_CONSTRAINT      = &H00002000???

%CERT_TRUST_HAS_NOT_PERMITTED_NAME_CONSTRAINT    = &H00004000???
%CERT_TRUST_HAS_EXCLUDED_NAME_CONSTRAINT         = &H00008000???

%CERT_TRUST_IS_OFFLINE_REVOCATION                = &H01000000???
%CERT_TRUST_NO_ISSUANCE_CHAIN_POLICY             = &H02000000???
%CERT_TRUST_IS_EXPLICIT_DISTRUST                 = &H04000000???
%CERT_TRUST_HAS_NOT_SUPPORTED_CRITICAL_EXT       = &H08000000???


'// These can be applied to chains only

%CERT_TRUST_IS_PARTIAL_CHAIN                     = &H00010000???
%CERT_TRUST_CTL_IS_NOT_TIME_VALID                = &H00020000???
%CERT_TRUST_CTL_IS_NOT_SIGNATURE_VALID           = &H00040000???
%CERT_TRUST_CTL_IS_NOT_VALID_FOR_USAGE           = &H00080000???

'//
'// The following are info status bits
'//

'// These can be applied to certificates only

%CERT_TRUST_HAS_EXACT_MATCH_ISSUER               = &H00000001???
%CERT_TRUST_HAS_KEY_MATCH_ISSUER                 = &H00000002???
%CERT_TRUST_HAS_NAME_MATCH_ISSUER                = &H00000004???
%CERT_TRUST_IS_SELF_SIGNED                       = &H00000008???

'// These can be applied to certificates and chains

%CERT_TRUST_HAS_PREFERRED_ISSUER                 = &H00000100???
%CERT_TRUST_HAS_ISSUANCE_CHAIN_POLICY            = &H00000200???
%CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS           = &H00000400???
%CERT_TRUST_IS_PEER_TRUSTED                      = &H00000800???
%CERT_TRUST_HAS_CRL_VALIDITY_EXTENDED            = &H00001000???

'// Indicates that the certificate was found in
'// a store specified by hExclusiveRoot or hExclusiveTrustedPeople
%CERT_TRUST_IS_FROM_EXCLUSIVE_TRUST_STORE        = &H00002000???

'// These can be applied to chains only

%CERT_TRUST_IS_COMPLEX_CHAIN                     = &H00010000???


'//
'// Each certificate context in a simple chain has a corresponding chain element
'// in the simple chain context
'//
'// dwErrorStatus has CERT_TRUST_IS_REVOKED, pRevocationInfo set
'// dwErrorStatus has CERT_TRUST_REVOCATION_STATUS_UNKNOWN, pRevocationInfo set

'//
'//         Note that the post processing revocation supported in the first
'//         version only sets cbSize and dwRevocationResult.  Everything else
'//         is NULL
'//

'//
'// Revocation Information
'//

' // Size = 28 bytes
TYPE CERT_REVOCATION_INFO DWORD
   cbSize             AS DWORD                          ' DWORD
   dwRevocationResult AS DWORD                          ' DWORD
   pszRevocationOid   AS ASCIIZ PTR                     ' LPCSTR
   pvOidSpecificInfo  AS DWORD                          ' LPVOID
   fHasFreshnessTime  AS LONG                           ' BOOL
   dwFreshnessTime    AS DWORD                          ' DWORD
   pCrlInfo           AS CERT_REVOCATION_CRL_INFO PTR   ' PCERT_REVOCATION_CRL_INFO
END TYPE

'//
'// Trust List Information
'//

' // Size = 12 bytes
TYPE CERT_TRUST_LIST_INFO DWORD
   cbSize      AS DWORD             ' DWORD
   pCtlEntry   AS CTL_ENTRY PTR     ' PCTL_ENTRY
   pCtlContext AS CTL_CONTEXT PTR   ' PCCTL_CONTEXT
END TYPE

'//
'// Chain Element
'//

' // Size = 32 bytes
TYPE CERT_CHAIN_ELEMENT DWORD
   cbSize                AS DWORD                      ' DWORD
   pCertContext          AS CERT_CONTEXT PTR           ' PCCERT_CONTEXT
   TrustStatus           AS CERT_TRUST_STATUS          ' CERT_TRUST_STATUS
   pRevocationInfo       AS CERT_REVOCATION_INFO PTR   ' PCERT_REVOCATION_INFO
   pIssuanceUsage        AS CERT_ENHKEY_USAGE PTR      ' PCERT_ENHKEY_USAGE
   pApplicationUsage     AS CERT_ENHKEY_USAGE PTR      ' PCERT_ENHKEY_USAGE
   pwszExtendedErrorInfo AS WSTRINGZ PTR               ' LPCWSTR
END TYPE

'//
'// The simple chain is an array of chain elements and a summary trust status
'// for the chain
'//
'// rgpElements[0] is the end certificate chain element
'//
'// rgpElements[cElement-1] is the self-signed "root" certificate chain element
'//

' // Size = 32 bytes
TYPE CERT_SIMPLE_CHAIN DWORD
   cbSize                      AS DWORD                      ' DWORD
   TrustStatus                 AS CERT_TRUST_STATUS          ' CERT_TRUST_STATUS
   cElement                    AS DWORD                      ' DWORD
   rgpElement                  AS CERT_CHAIN_ELEMENT PTR     ' PCERT_CHAIN_ELEMENT*
   pTrustListInfo              AS CERT_TRUST_LIST_INFO PTR   ' PCERT_TRUST_LIST_INFO
   fHasRevocationFreshnessTime AS LONG                       ' BOOL
   dwRevocationFreshnessTime   AS DWORD                      ' DWORD
END TYPE

'//
'// And the chain context contains an array of simple chains and summary trust
'// status for all the connected simple chains
'//
'// rgpChains[0] is the end certificate simple chain
'//
'// rgpChains[cChain-1] is the final (possibly trust list signer) chain which
'// ends in a certificate which is contained in the root store
'//

'typedef struct _CERT_CHAIN_CONTEXT CERT_CHAIN_CONTEXT, *PCERT_CHAIN_CONTEXT;
'typedef const CERT_CHAIN_CONTEXT *PCCERT_CHAIN_CONTEXT;

' // Size = 56 bytes
TYPE CERT_CHAIN_CONTEXT DWORD
   cbSize                      AS DWORD                    ' DWORD
   TrustStatus                 AS CERT_TRUST_STATUS        ' CERT_TRUST_STATUS
   cChain                      AS DWORD                    ' DWORD
   rgpChain                    AS CERT_SIMPLE_CHAIN PTR    ' PCERT_SIMPLE_CHAIN*
   ' // Following is returned when CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS is set in dwFlags
   cLowerQualityChainContext   AS DWORD                    ' DWORD
   rgpLowerQualityChainContext AS CERT_CHAIN_CONTEXT PTR   ' PCCERT_CHAIN_CONTEXT*
   ' // fHasRevocationFreshnessTime is only set if we are able to retrieve
   ' // revocation information for all elements checked for revocation.
   ' // For a CRL its CurrentTime - ThisUpdate.
   fHasRevocationFreshnessTime AS LONG                     ' BOOL
   ' // dwRevocationFreshnessTime is the largest time across all elements checked.
   dwRevocationFreshnessTime   AS DWORD                    ' DWORD
   ' // Flags passed when created via CertGetCertificateChain
   dwCreateFlags               AS DWORD                    ' DWORD
   ' // Following is updated with unique Id when the chain context is logged.
   ChainId                     AS GUID                     ' GUID
END TYPE

'//
'// When building a chain, the there are various parameters used for finding
'// issuing certificates and trust lists.  They are identified in the
'// following structure
'//

'// Default usage match type is AND with value zero
%USAGE_MATCH_TYPE_AND = &H00000000???
%USAGE_MATCH_TYPE_OR  = &H00000001???

' // Size = 12 bytes
TYPE CERT_USAGE_MATCH DWORD
   dwType AS DWORD               ' DWORD
   Usage  AS CERT_ENHKEY_USAGE   ' CERT_ENHKEY_USAGE
END TYPE

' // Size = 12 bytes
TYPE CTL_USAGE_MATCH DWORD
   dwType AS DWORD       ' DWORD
   Usage  AS CTL_USAGE   ' CTL_USAGE
END TYPE

'typedef struct _CERT_CHAIN_PARA {

'    DWORD            cbSize;
'    CERT_USAGE_MATCH RequestedUsage;

'#ifdef CERT_CHAIN_PARA_HAS_EXTRA_FIELDS

''    // Note, if you #define CERT_CHAIN_PARA_HAS_EXTRA_FIELDS, then, you
''    // must zero all unused fields in this data structure.
''    // More fields could be added in a future release.

'    CERT_USAGE_MATCH RequestedIssuancePolicy;
'    DWORD            dwUrlRetrievalTimeout;     // milliseconds
'    BOOL             fCheckRevocationFreshnessTime;
'    DWORD            dwRevocationFreshnessTime; // seconds

'#endif

'} CERT_CHAIN_PARA, *PCERT_CHAIN_PARA;

' // Size = 16 bytes
TYPE CERT_CHAIN_PARA DWORD
   cbSize                        AS DWORD
   RequestedUsage                AS CERT_USAGE_MATCH
#IF %DEF(%CERT_CHAIN_PARA_HAS_EXTRA_FIELDS)
   RequestedIssuancePolicy       AS CERT_USAGE_MATCH
   dwUrlRetrievalTimeout         AS DWORD
   fCheckRevocationFreshnessTime AS LONG
   dwRevocationFreshnessTime     AS DWORD
#ENDIF
END TYPE

'//
'// The following API is used for retrieving certificate chains
'//
'// Parameters:
'//
'//      hChainEngine     - the chain engine (namespace and cache) to use, NULL
'//                         mean use the default chain engine
'//
'//      pCertContext     - the context we are retrieving the chain for, it
'//                         will be the zero index element in the chain
'//
'//      pTime            - the point in time that we want the chain validated
'//                         for.  Note that the time does not affect trust list,
'//                         revocation, or root store checking.  NULL means use
'//                         the current system time
'//
'//      hAdditionalStore - additional store to use when looking up objects
'//
'//      pChainPara       - parameters for chain building
'//
'//      dwFlags          - flags such as should revocation checking be done
'//                         on the chain?
'//
'//      pvReserved       - reserved parameter, must be NULL
'//
'//      ppChainContext   - chain context returned
'//

'// CERT_CHAIN_CACHE_END_CERT can be used here as well
'// Revocation flags are in the high nibble
%CERT_CHAIN_REVOCATION_CHECK_END_CERT           = &H10000000???
%CERT_CHAIN_REVOCATION_CHECK_CHAIN              = &H20000000???
%CERT_CHAIN_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT = &H40000000???
%CERT_CHAIN_REVOCATION_CHECK_CACHE_ONLY         = &H80000000???

'// By default, the dwUrlRetrievalTimeout in pChainPara is the timeout used
'// for each revocation URL wire retrieval. When the following flag is set,
'// dwUrlRetrievalTimeout is the accumulative timeout across all
'// revocation URL wire retrievals.
%CERT_CHAIN_REVOCATION_ACCUMULATIVE_TIMEOUT     = &H08000000???

'// Revocation checking for an independent OCSP signer certificate.
'//
'// The above revocation flags indicate if just the signer certificate or all
'// the certificates in the chain, excluding the root should be checked
'// for revocation. If the signer certificate contains the
'// szOID_PKIX_OCSP_NOCHECK extension, then, revocation checking is skipped
'// for the leaf signer certificate. Both OCSP and CRL checking are allowed.
'// However, recursive, independent OCSP signer certs are disabled.
%CERT_CHAIN_REVOCATION_CHECK_OCSP_CERT          = &H04000000???

'// First pass determines highest quality based upon:
'//  - Chain signature valid (higest quality bit of this set)
'//  - Complete chain
'//  - Trusted root          (lowestest quality bit of this set)
'// By default, second pass only considers paths >= highest first pass quality
%CERT_CHAIN_DISABLE_PASS1_QUALITY_FILTERING  = &H00000040???

%CERT_CHAIN_RETURN_LOWER_QUALITY_CONTEXTS    = &H00000080???

%CERT_CHAIN_DISABLE_AUTH_ROOT_AUTO_UPDATE    = &H00000100???


'// When this flag is set, pTime will be used as the timestamp time.
'// pTime will be used to determine if the end certificate was valid at this
'// time. Revocation checking will be relative to pTime.
'// In addition, current time will also be used
'// to determine if the certificate is still time valid. All remaining
'// CA and root certificates will be checked using current time and not pTime.
'//
'// This flag was added 4/5/01 in WXP.
%CERT_CHAIN_TIMESTAMP_TIME                   = &H00000200???

'// When this flag is set, "My" certificates having a private key or end
'// entity certificates in the "TrustedPeople" store are trusted without
'// doing any chain building. Neither the CERT_TRUST_IS_PARTIAL_CHAIN or
'// CERT_TRUST_IS_UNTRUSTED_ROOT dwErrorStatus bits will be set for
'// such certificates.
'//
'// This flag was added 6/9/03 in LH.
%CERT_CHAIN_ENABLE_PEER_TRUST                = &H00000400???

'// When this flag is set, "My" certificates aren't considered for
'// PEER_TRUST.
'//
'// This flag was added 11/12/04 in LH.
'//
'// On 8-05-05 changed to never consider "My" certificates for PEER_TRUST.
%CERT_CHAIN_DISABLE_MY_PEER_TRUST            = &H00000800???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetCertificateChain LIB "Crypt32.dll" _
    ALIAS "CertGetCertificateChain" ( _
    BYVAL hChainEngine AS DWORD, _  ' HCERTCHAINENGINE
    pCertContext       AS CERT_CONTEXT, _
    pTime              AS FILETIME, _
    hAdditionalStore   AS DWORD, _  ' HCERTSTORE
    pChainPara         AS CERT_CHAIN_PARA, _
    BYVAL dwFlags      AS DWORD, _
    pvReserved         AS ANY, _    ' LPVOID
    ppChainContext     AS ANY _     ' CERT_CHAIN_CONTEXT PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertGetCertificateChain IMPORT "CRYPT32.DLL" ALIAS "CertGetCertificateChain" ( _
   BYVAL hChainEngine AS DWORD _                        ' __in_opt HCERTCHAINENGINE hChainEngine
 , BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in PCCERT_CONTEXT pCertContext
 , BYREF pTime AS FILETIME _                            ' __in_opt LPFILETIME pTime
 , BYVAL hAdditionalStore AS DWORD _                    ' __in_opt HCERTSTORE hAdditionalStore
 , BYREF pChainPara AS CERT_CHAIN_PARA _                ' __in PCERT_CHAIN_PARA pChainPara
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 , BYREF ppChainContext AS CERT_CHAIN_CONTEXT _         ' __out PCCERT_CHAIN_CONTEXT* ppChainContext
 ) AS LONG                                              ' BOOL
#ENDIF

'//
'// Free a certificate chain
'//

DECLARE SUB CertFreeCertificateChain IMPORT "CRYPT32.DLL" ALIAS "CertFreeCertificateChain" ( _
   BYREF pChainContext AS CERT_CHAIN_CONTEXT _          ' __in PCCERT_CHAIN_CONTEXT pChainContext
 )                                                      ' void

'//
'// Duplicate (add a reference to) a certificate chain
'//

DECLARE FUNCTION CertDuplicateCertificateChain IMPORT "CRYPT32.DLL" ALIAS "CertDuplicateCertificateChain" ( _
   BYREF pChainContext AS CERT_CHAIN_CONTEXT _          ' __in PCCERT_CHAIN_CONTEXT pChainContext
 ) AS DWORD                                             ' PCCERT_CHAIN_CONTEXT

'//+-------------------------------------------------------------------------
'//  This data structure is optionally pointed to by the pChainPara field
'//  in the CERT_REVOCATION_PARA and CRYPT_GET_TIME_VALID_OBJECT_EXTRA_INFO
'//  data structures. CertGetCertificateChain() populates when it calls
'//  the CertVerifyRevocation() API.
'//--------------------------------------------------------------------------

' Note: Moved above because PB doesn't support forward reference for structures.

'struct _CERT_REVOCATION_CHAIN_PARA {
'    DWORD                       cbSize;
'    HCERTCHAINENGINE            hChainEngine;
'    HCERTSTORE                  hAdditionalStore;
'    DWORD                       dwChainFlags;
'    DWORD                       dwUrlRetrievalTimeout;     // milliseconds
'    LPFILETIME                  pftCurrentTime;
'    LPFILETIME                  pftCacheResync;

'    // Max size of the URL object to download, in bytes.
'    // 0 value means no limit.
'    DWORD                       cbMaxUrlRetrievalByteCount;
'};

'//
'// Specific Revocation Type OID and structure definitions
'//

'//
'// CRL Revocation OID
'//

%REVOCATION_OID_CRL_REVOCATION = 1   ' ((LPCSTR)1)

'//
'// For the CRL revocation OID the pvRevocationPara is NULL
'//

'//
'// CRL Revocation Info
'//

' // Size = 12 bytes
TYPE CRL_REVOCATION_INFO DWORD
   pCrlEntry       AS CRL_ENTRY PTR
   pCrlContext     AS CRL_CONTEXT PTR
   pCrlIssuerChain AS CERT_CHAIN_CONTEXT PTR
END TYPE

'//+-------------------------------------------------------------------------
'//  Find the first or next certificate chain context in the store.
'//
'//  The chain context is found according to the dwFindFlags, dwFindType and
'//  its pvFindPara. See below for a list of the find types and its parameters.
'//
'//  If the first or next chain context isn't found, NULL is returned.
'//  Otherwise, a pointer to a read only CERT_CHAIN_CONTEXT is returned.
'//  CERT_CHAIN_CONTEXT must be freed by calling CertFreeCertificateChain
'//  or is freed when passed as the
'//  pPrevChainContext on a subsequent call. CertDuplicateCertificateChain
'//  can be called to make a duplicate.
'//
'//  pPrevChainContext MUST BE NULL on the first
'//  call to find the chain context. To find the next chain context, the
'//  pPrevChainContext is set to the CERT_CHAIN_CONTEXT returned by a previous
'//  call.
'//
'//  NOTE: a NON-NULL pPrevChainContext is always CertFreeCertificateChain'ed by
'//  this function, even for an error.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertFindChainInStore IMPORT "CRYPT32.DLL" ALIAS "CertFindChainInStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL dwCertEncodingType AS DWORD _                  ' __in DWORD dwCertEncodingType
 , BYVAL dwFindFlags AS DWORD _                         ' __in DWORD dwFindFlags
 , BYVAL dwFindType AS DWORD _                          ' __in DWORD dwFindType
 , BYREF pvFindPara AS ANY _                            ' __in const void *pvFindPara
 , BYREF pPrevChainContext AS CERT_CHAIN_CONTEXT _      ' __in PCCERT_CHAIN_CONTEXT pPrevChainContext
 ) AS DWORD                                             ' PCCERT_CHAIN_CONTEXT

%CERT_CHAIN_FIND_BY_ISSUER      = 1


'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_FIND_BY_ISSUER
'//
'//  Find a certificate chain having a private key for the end certificate and
'//  matching one of the given issuer names. A matching dwKeySpec and
'//  enhanced key usage can also be specified. Additionally a callback can
'//  be provided for even more caller provided filtering before building the
'//  chain.
'//
'//  By default, only the issuers in the first simple chain are compared
'//  for a name match. CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG can
'//  be set in dwFindFlags to match issuers in all the simple chains.
'//
'//  CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG can be set in dwFindFlags to
'//  not check if the end certificate has a private key.
'//
'//  CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG can be set in dwFindFlags
'//  to compare the public key in the end certificate with the crypto
'//  provider's public key. The dwAcquirePrivateKeyFlags can be set
'//  in CERT_CHAIN_FIND_BY_ISSUER_PARA to enable caching of the private key's
'//  HKEY returned by the CSP.
'//
'//  If dwCertEncodingType == 0, defaults to X509_ASN_ENCODING for the
'//  array of encoded issuer names.
'//
'//  By default, the hCertStore passed to CertFindChainInStore, is passed
'//  as an additional store to CertGetCertificateChain.
'//  CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG can be set in dwFindFlags
'//  to improve performance by only searching the cached system stores
'//  (root, my, ca, trust) to find the issuer certificates. If you are doing
'//  a find in the "my" system store, than, this flag should be set to
'//  improve performance.
'//
'//  Setting CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG in dwFindFlags
'//  restricts CertGetCertificateChain to search the Local Machine
'//  cached system stores instead of the Current User's.
'//
'//  Setting CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG in dwFindFlags
'//  restricts CertGetCertificateChain to only search the URL cache
'//  and not hit the wire.
'//--------------------------------------------------------------------------

'// Returns FALSE to skip this certificate. Otherwise, returns TRUE to
'// build a chain for this certificate.
'typedef BOOL (WINAPI *PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK)(
'    IN PCCERT_CONTEXT pCert,
'    IN void *pvFindArg
'    );

'FUNCTION CERT_CHAIN_FIND_BY_ISSUER_CALLBACK ( _
'   BYVAL pCert AS CERT_CONTEXT PTR _                    ' __in PCCERT_CONTEXT pCert
' , BYVAL pvFindArg AS DWORD _                           ' __in void *pvFindArg
' ) AS LONG                                              ' BOOL

'typedef struct _CERT_CHAIN_FIND_BY_ISSUER_PARA {
'    DWORD                                   cbSize;

'    // If pszUsageIdentifier == NULL, matches any usage.
'    LPCSTR                                  pszUsageIdentifier;

'    // If dwKeySpec == 0, matches any KeySpec
'    DWORD                                   dwKeySpec;

''    // When CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG is set in dwFindFlags,
''    // CryptAcquireCertificatePrivateKey is called to do the public key
''    // comparison. The following flags can be set to enable caching
''    // of the acquired private key or suppress CSP UI. See the API for more
''    // details on these flags.
'    DWORD                                   dwAcquirePrivateKeyFlags;

''    // Pointer to an array of X509, ASN.1 encoded issuer name blobs. If
''    // cIssuer == 0, matches any issuer
'    DWORD                                   cIssuer;
'    CERT_NAME_BLOB                          *rgIssuer;

''    // If NULL or Callback returns TRUE, builds the chain for the end
''    // certificate having a private key with the specified KeySpec and
''    // enhanced key usage.
'    PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK pfnFindCallback;
'    void                                    *pvFindArg;

'#ifdef CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS
''    // Note, if you #define CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS,
''    // then, you must zero all unused fields in this data structure.
''    // More fields could be added in a future release.

''    // If the following pointers are nonNull, returns the index of the
''    // matching issuer certificate, which is at:
''    // pChainContext->
''    //      rgpChain[*pdwIssuerChainIndex]->rgpElement[*pdwIssuerElementIndex].
''    //
''    // The issuer name blob is compared against the Issuer field in the
''    // certificate. The *pdwIssuerElementIndex is set to the index of this
''    // subject certificate + 1. Therefore, its possible for a partial chain or
''    // a self signed certificate matching the name blob, where
''    // *pdwIssuerElementIndex points past the last certificate in the chain.
''    //
''    // Note, not updated if the above cIssuer == 0.
'    DWORD                                   *pdwIssuerChainIndex;
'    DWORD                                   *pdwIssuerElementIndex;
'#endif
'} CERT_CHAIN_FIND_ISSUER_PARA, *PCERT_CHAIN_FIND_ISSUER_PARA,
'    CERT_CHAIN_FIND_BY_ISSUER_PARA, *PCERT_CHAIN_FIND_BY_ISSUER_PARA;

' // Size = 32 bytes
TYPE CERT_CHAIN_FIND_BY_ISSUER_PARA DWORD
   cbSize                   AS DWORD
   pszUsageIdentifier       AS ASCIIZ PTR
   dwKeySpec                AS DWORD
   dwAcquirePrivateKeyFlags AS DWORD
   cIssuer                  AS DWORD
   rgIssuer                 AS CERT_NAME_BLOB PTR
   pfnFindCallback          AS DWORD
   pvFindArg                AS DWORD
#IF %DEF(%CERT_CHAIN_FIND_BY_ISSUER_PARA_HAS_EXTRA_FIELDS)
   pdwIssuerChainIndex      AS DWORD PTR
   pdwIssuerElementIndex    AS DWORD PTR
#ENDIF
END TYPE

'// The following dwFindFlags can be set for CERT_CHAIN_FIND_BY_ISSUER

'// If set, compares the public key in the end certificate with the crypto
'// provider's public key. This comparison is the last check made on the
'// build chain.
%CERT_CHAIN_FIND_BY_ISSUER_COMPARE_KEY_FLAG          = &H0001???

'// If not set, only checks the first simple chain for an issuer name match.
'// When set, also checks second and subsequent simple chains.
%CERT_CHAIN_FIND_BY_ISSUER_COMPLEX_CHAIN_FLAG        = &H0002???

'// If set, CertGetCertificateChain only searches the URL cache and
'// doesn't hit the wire.
%CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_URL_FLAG       = &H0004???

'// If set, CertGetCertificateChain only opens the Local Machine
'// certificate stores instead of the Current User's.
%CERT_CHAIN_FIND_BY_ISSUER_LOCAL_MACHINE_FLAG        = &H0008???

'// If set, no check is made to see if the end certificate has a private
'// key associated with it.
%CERT_CHAIN_FIND_BY_ISSUER_NO_KEY_FLAG               = &H4000???


'// By default, the hCertStore passed to CertFindChainInStore, is passed
'// as the additional store to CertGetCertificateChain. This flag can be
'// set to improve performance by only searching the cached system stores
'// (root, my, ca, trust) to find the issuer certificates. If not set, then,
'// the hCertStore is always searched in addition to the cached system
'// stores.
%CERT_CHAIN_FIND_BY_ISSUER_CACHE_ONLY_FLAG           = &H8000???



'//+=========================================================================
'//  Certificate Chain Policy Data Structures and APIs
'//==========================================================================

' // Size = 12 bytes
TYPE CERT_CHAIN_POLICY_PARA DWORD
   cbSize            AS DWORD   ' DWORD
   dwFlags           AS DWORD   ' DWORD
   pvExtraPolicyPara AS DWORD   ' void*
END TYPE

'// If both lChainIndex and lElementIndex are set to -1, the dwError applies
'// to the whole chain context. If only lElementIndex is set to -1, the
'// dwError applies to the lChainIndex'ed chain. Otherwise, the dwError applies
'// to the certificate element at
'// pChainContext->rgpChain[lChainIndex]->rgpElement[lElementIndex].

' // Size = 20 bytes
TYPE CERT_CHAIN_POLICY_STATUS DWORD
   cbSize              AS DWORD   ' DWORD
   dwError             AS DWORD   ' DWORD
   lChainIndex         AS LONG    ' LONG
   lElementIndex       AS LONG    ' LONG
   pvExtraPolicyStatus AS DWORD   ' void*
END TYPE

'// Common chain policy flags
%CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG            = &H00000001???
%CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG        = &H00000002???
%CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG           = &H00000004???
%CERT_CHAIN_POLICY_IGNORE_INVALID_BASIC_CONSTRAINTS_FLAG = &H00000008???

%CERT_CHAIN_POLICY_IGNORE_ALL_NOT_TIME_VALID_FLAGS = _
   %CERT_CHAIN_POLICY_IGNORE_NOT_TIME_VALID_FLAG OR _
   %CERT_CHAIN_POLICY_IGNORE_CTL_NOT_TIME_VALID_FLAG OR _
   %CERT_CHAIN_POLICY_IGNORE_NOT_TIME_NESTED_FLAG

%CERT_CHAIN_POLICY_ALLOW_UNKNOWN_CA_FLAG                 = &H00000010???
%CERT_CHAIN_POLICY_IGNORE_WRONG_USAGE_FLAG               = &H00000020???
%CERT_CHAIN_POLICY_IGNORE_INVALID_NAME_FLAG              = &H00000040???
%CERT_CHAIN_POLICY_IGNORE_INVALID_POLICY_FLAG            = &H00000080???

%CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG           = &H00000100???
%CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG    = &H00000200???
%CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG            = &H00000400???
%CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG          = &H00000800???

%CERT_CHAIN_POLICY_IGNORE_ALL_REV_UNKNOWN_FLAGS = _
   %CERT_CHAIN_POLICY_IGNORE_END_REV_UNKNOWN_FLAG OR _
   %CERT_CHAIN_POLICY_IGNORE_CTL_SIGNER_REV_UNKNOWN_FLAG OR _
   %CERT_CHAIN_POLICY_IGNORE_CA_REV_UNKNOWN_FLAG OR _
   %CERT_CHAIN_POLICY_IGNORE_ROOT_REV_UNKNOWN_FLAG

%CERT_CHAIN_POLICY_ALLOW_TESTROOT_FLAG                   = &H00008000???
%CERT_CHAIN_POLICY_TRUST_TESTROOT_FLAG                   = &H00004000???

%CERT_CHAIN_POLICY_IGNORE_NOT_SUPPORTED_CRITICAL_EXT_FLAG    = &H00002000???
%CERT_CHAIN_POLICY_IGNORE_PEER_TRUST_FLAG                    = &H00001000???

'//+-------------------------------------------------------------------------
'//  Verify that the certificate chain satisfies the specified policy
'//  requirements. If we were able to verify the chain policy, TRUE is returned
'//  and the dwError field of the pPolicyStatus is updated. A dwError of 0
'//  (ERROR_SUCCESS, S_OK) indicates the chain satisfies the specified policy.
'//
'//  If dwError applies to the entire chain context, both lChainIndex and
'//  lElementIndex are set to -1. If dwError applies to a simple chain,
'//  lElementIndex is set to -1 and lChainIndex is set to the index of the
'//  first offending chain having the error. If dwError applies to a
'//  certificate element, lChainIndex and lElementIndex are updated to
'//  index the first offending certificate having the error, where, the
'//  the certificate element is at:
'//      pChainContext->rgpChain[lChainIndex]->rgpElement[lElementIndex].
'//
'//  The dwFlags in pPolicyPara can be set to change the default policy checking
'//  behaviour. In addition, policy specific parameters can be passed in
'//  the pvExtraPolicyPara field of pPolicyPara.
'//
'//  In addition to returning dwError, in pPolicyStatus, policy OID specific
'//  extra status may be returned via pvExtraPolicyStatus.
'//--------------------------------------------------------------------------

DECLARE FUNCTION CertVerifyCertificateChainPolicy IMPORT "CRYPT32.DLL" ALIAS "CertVerifyCertificateChainPolicy" ( _
   BYREF pszPolicyOID AS ASCIIZ _                       ' __in LPCSTR pszPolicyOID
 , BYREF pChainContext AS CERT_CHAIN_CONTEXT _          ' __in PCCERT_CHAIN_CONTEXT pChainContext
 , BYREF pPolicyPara AS CERT_CHAIN_POLICY_PARA _        ' __in PCERT_CHAIN_POLICY_PARA pPolicyPara
 , BYREF pPolicyStatus AS CERT_CHAIN_POLICY_STATUS _    ' __inout PCERT_CHAIN_POLICY_STATUS pPolicyStatus
 ) AS LONG                                              ' BOOL

'// Predefined OID Function Names
'#define CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC  \
'    "CertDllVerifyCertificateChainPolicy"

$CRYPT_OID_VERIFY_CERTIFICATE_CHAIN_POLICY_FUNC = "CertDllVerifyCertificateChainPolicy"

'// CertDllVerifyCertificateChainPolicy has same function signature as
'// CertVerifyCertificateChainPolicy.

'//+-------------------------------------------------------------------------
'//  Predefined verify chain policies
'//--------------------------------------------------------------------------
%CERT_CHAIN_POLICY_BASE              = 1   ' ((LPCSTR) 1)
%CERT_CHAIN_POLICY_AUTHENTICODE      = 2   ' ((LPCSTR) 2)
%CERT_CHAIN_POLICY_AUTHENTICODE_TS   = 3   ' ((LPCSTR) 3)
%CERT_CHAIN_POLICY_SSL               = 4   ' ((LPCSTR) 4)
%CERT_CHAIN_POLICY_BASIC_CONSTRAINTS = 5   ' ((LPCSTR) 5)
%CERT_CHAIN_POLICY_NT_AUTH           = 6   ' ((LPCSTR) 6)
%CERT_CHAIN_POLICY_MICROSOFT_ROOT    = 7   ' ((LPCSTR) 7)
%CERT_CHAIN_POLICY_EV                = 8   ' ((LPCSTR) 8)

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_BASE
'//
'//  Implements the base chain policy verification checks. dwFlags can
'//  be set in pPolicyPara to alter the default policy checking behaviour.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_AUTHENTICODE
'//
'//  Implements the Authenticode chain policy verification checks.
'//
'//  pvExtraPolicyPara may optionally be set to point to the following
'//  AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA.
'//
'//  pvExtraPolicyStatus may optionally be set to point to the following
'//  AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS.
'//--------------------------------------------------------------------------

'// dwRegPolicySettings are defined in wintrust.h
' // Size = 12 bytes
TYPE AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_PARA
   cbSize              AS DWORD                  ' DWORD
   dwRegPolicySettings AS DWORD                  ' DWORD
   pSignerInfo         AS CMSG_SIGNER_INFO PTR   ' PCMSG_SIGNER_INFO
END TYPE

' // Size = 8 bytes
TYPE AUTHENTICODE_EXTRA_CERT_CHAIN_POLICY_STATUS DWORD
   cbSize      AS DWORD   ' DWORD
   fCommercial AS LONG    ' BOOL
END TYPE

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_AUTHENTICODE_TS
'//
'//  Implements the Authenticode Time Stamp chain policy verification checks.
'//
'//  pvExtraPolicyPara may optionally be set to point to the following
'//  AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA.
'//
'//  pvExtraPolicyStatus isn't used and must be set to NULL.
'//--------------------------------------------------------------------------

'// dwRegPolicySettings are defined in wintrust.h
' // Size = 12 bytes
TYPE AUTHENTICODE_TS_EXTRA_CERT_CHAIN_POLICY_PARA DWORD
   cbSize              AS DWORD   ' DWORD
   dwRegPolicySettings AS DWORD   ' DWORD
   fCommercial         AS LONG    ' BOOL
END TYPE

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_SSL
'//
'//  Implements the SSL client/server chain policy verification checks.
'//
'//  pvExtraPolicyPara may optionally be set to point to the following
'//  SSL_EXTRA_CERT_CHAIN_POLICY_PARA data structure
'//--------------------------------------------------------------------------

'// fdwChecks flags are defined in wininet.h
'typedef struct _HTTPSPolicyCallbackData
'{
'    union {
'        DWORD           cbStruct;       // sizeof(HTTPSPolicyCallbackData);
'        DWORD           cbSize;         // sizeof(HTTPSPolicyCallbackData);
'    };

'    DWORD           dwAuthType;
'#                       define      AUTHTYPE_CLIENT         1
'#                       define      AUTHTYPE_SERVER         2

'    DWORD           fdwChecks;

'    WCHAR           *pwszServerName; // used to check against CN=xxxx

'} HTTPSPolicyCallbackData, *PHTTPSPolicyCallbackData,
'    SSL_EXTRA_CERT_CHAIN_POLICY_PARA, *PSSL_EXTRA_CERT_CHAIN_POLICY_PARA;

%AUTHTYPE_CLIENT        = 1
%AUTHTYPE_SERVER        = 2

' // Size = 4 bytes
UNION HTTPSPolicyCallbackData_UNION DWORD
   cbStruct AS DWORD
   cbSize AS DWORD
END UNION

' // Size = 16 bytes
TYPE HTTPSPolicyCallbackData DWORD
   HTTPSPolicyCallbackData_UNION
   dwAuthType     AS DWORD
   fdwChecks      AS DWORD
   pwszServerName AS WSTRINGZ PTR
END TYPE

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_BASIC_CONSTRAINTS
'//
'//  Implements the basic constraints chain policy.
'//
'//  Iterates through all the certificates in the chain checking for either
'//  a szOID_BASIC_CONSTRAINTS or a szOID_BASIC_CONSTRAINTS2 extension. If
'//  neither extension is present, the certificate is assumed to have
'//  valid policy. Otherwise, for the first certificate element, checks if
'//  it matches the expected CA_FLAG or END_ENTITY_FLAG specified in
'//  pPolicyPara->dwFlags. If neither or both flags are set, then, the first
'//  element can be either a CA or END_ENTITY. All other elements must be
'//  a CA. If the PathLenConstraint is present in the extension, its
'//  checked.
'//
'//  The first elements in the remaining simple chains (ie, the certificate
'//  used to sign the CTL) are checked to be an END_ENTITY.
'//
'//  If this verification fails, dwError will be set to
'//  TRUST_E_BASIC_CONSTRAINTS.
'//--------------------------------------------------------------------------

%BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_CA_FLAG         = &H80000000???
%BASIC_CONSTRAINTS_CERT_CHAIN_POLICY_END_ENTITY_FLAG = &H40000000???

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_NT_AUTH
'//
'//  Implements the NT Authentication chain policy.
'//
'//  The NT Authentication chain policy consists of 3 distinct chain
'//  verifications in the following order:
'//      [1] CERT_CHAIN_POLICY_BASE - Implements the base chain policy
'//          verification checks. The LOWORD of dwFlags can be set in
'//          pPolicyPara to alter the default policy checking behaviour. See
'//          CERT_CHAIN_POLICY_BASE for more details.
'//
'//      [2] CERT_CHAIN_POLICY_BASIC_CONSTRAINTS - Implements the basic
'//          constraints chain policy. The HIWORD of dwFlags can be set
'//          to specify if the first element must be either a CA or END_ENTITY.
'//          See CERT_CHAIN_POLICY_BASIC_CONSTRAINTS for more details.
'//
'//      [3] Checks if the second element in the chain, the CA that issued
'//          the end certificate, is a trusted CA for NT
'//          Authentication. A CA is considered to be trusted if it exists in
'//          the "NTAuth" system registry store found in the
'//          CERT_SYSTEM_STORE_LOCAL_MACHINE_ENTERPRISE store location.
'//          If this verification fails, whereby the CA isn't trusted,
'//          dwError is set to CERT_E_UNTRUSTEDCA.
'//
'//          If CERT_PROT_ROOT_DISABLE_NT_AUTH_REQUIRED_FLAG is set
'//          in the "Flags" value of the HKLM policy "ProtectedRoots" subkey
'//          defined by CERT_PROT_ROOT_FLAGS_REGPATH, then,
'//          if the above check fails, checks if the chain
'//          has CERT_TRUST_HAS_VALID_NAME_CONSTRAINTS set in dwInfoStatus. This
'//          will only be set if there was a valid name constraint for all
'//          name spaces including UPN. If the chain doesn't have this info
'//          status set, dwError is set to CERT_E_UNTRUSTEDCA.
'//--------------------------------------------------------------------------

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_MICROSOFT_ROOT
'//
'//  Checks if the last element of the first simple chain contains a
'//  Microsoft root public key. If it doesn't contain a Microsoft root
'//  public key, dwError is set to CERT_E_UNTRUSTEDROOT.
'//
'//  pPolicyPara is optional. However,
'//  MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG can be set in
'//  the dwFlags in pPolicyPara to also check for the Microsoft Test Roots.
'//
'//  pvExtraPolicyPara and pvExtraPolicyStatus aren't used and must be set
'//  to NULL.
'//--------------------------------------------------------------------------
%MICROSOFT_ROOT_CERT_CHAIN_POLICY_ENABLE_TEST_ROOT_FLAG = &H00010000???

'//+-------------------------------------------------------------------------
'//  CERT_CHAIN_POLICY_EV
'//
'//  Verify the issuance policy in the end certificate of the first simple
'//  chain matches with the root certificate EV policy.
'//
'//  pvExtraPolicyPara may optionally be set to point to the following
'//  EV_EXTRA_CERT_CHAIN_POLICY_PARA. The dwRootProgramQualifierFlags member
'//  can be set to one or more of the CERT_ROOT_PROGRAM_FLAG_* to define
'//  which of the EV policy qualifier bits are required for validation.
'//
'//  pvExtraPolicyStatus may optionally be set to point to the following
'//  EV_EXTRA_CERT_CHAIN_POLICY_STATUS. The fQualifiers member will contain
'//  a combination of CERT_ROOT_PROGRAM_FLAG_* flags.
'//--------------------------------------------------------------------------

' // Size = 8 bytes
TYPE EV_EXTRA_CERT_CHAIN_POLICY_PARA DWORD
   cbSize                      AS DWORD   ' DWORD
   dwRootProgramQualifierFlags AS DWORD   'DWORD
END TYPE

' // Size = 12 bytes
TYPE EV_EXTRA_CERT_CHAIN_POLICY_STATUS DWORD
   cbSize               AS DWORD   ' DWORD
   dwQualifiers         AS DWORD   ' DWORD
   dwIssuanceUsageIndex AS DWORD   ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'// convert formatted string to binary
'// If cchString is 0, then pszString is NULL terminated and
'// cchString is obtained via strlen() + 1.
'// dwFlags defines string format
'// if pbBinary is NULL, *pcbBinary returns the size of required memory
'// *pdwSkip returns the character count of skipped strings, optional
'// *pdwFlags returns the actual format used in the conversion, optional
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptStringToBinaryA IMPORT "CRYPT32.DLL" ALIAS "CryptStringToBinaryA" ( _
   BYREF pszString AS ASCIIZ _                          ' __in     LPCSTR  pszString
 , BYVAL cchString AS DWORD _                           ' __in     DWORD   cchString
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD   dwFlags
 , BYVAL pbBinary AS BYTE PTR _                         ' __in     BYTE    *pbBinary
 , BYREF pcbBinary AS DWORD _                           ' __inout DWORD   *pcbBinary
 , BYREF pdwSkip AS DWORD _                             ' __out    DWORD   *pdwSkip
 , BYREF pdwFlags AS DWORD _                            ' __out    DWORD   *pdwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'// convert formatted string to binary
'// If cchString is 0, then pszString is NULL terminated and
'// cchString is obtained via strlen() + 1.
'// dwFlags defines string format
'// if pbBinary is NULL, *pcbBinary returns the size of required memory
'// *pdwSkip returns the character count of skipped strings, optional
'// *pdwFlags returns the actual format used in the conversion, optional
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptStringToBinaryW IMPORT "CRYPT32.DLL" ALIAS "CryptStringToBinaryW" ( _
   BYREF pszString AS WSTRINGZ _                        ' __in     LPCWSTR  pszString
 , BYVAL cchString AS DWORD _                           ' __in     DWORD    cchString
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD    dwFlags
 , BYVAL pbBinary AS BYTE PTR _                         ' __in     BYTE     *pbBinary
 , BYREF pcbBinary AS DWORD _                           ' __inout  DWORD    *pcbBinary
 , BYREF pdwSkip AS DWORD _                             ' __out    DWORD    *pdwSkip
 , BYREF pdwFlags AS DWORD _                            ' __out    DWORD    *pdwFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptStringToBinary = CryptStringToBinaryW
#ELSE
   MACRO CryptStringToBinary = CryptStringToBinaryA
#ENDIF

'//+-------------------------------------------------------------------------
'// convert binary to formatted string
'// dwFlags defines string format
'// if pszString is NULL, *pcchString returns size in characters
'// including null-terminator
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptBinaryToStringA IMPORT "CRYPT32.DLL" ALIAS "CryptBinaryToStringA" ( _
   BYVAL pbBinary AS BYTE PTR _                         ' __in     CONST BYTE  *pbBinary
 , BYVAL cbBinary AS DWORD _                            ' __in     DWORD        cbBinary
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD        dwFlags
 , BYREF pszString AS ASCIIZ _                          ' __in     LPSTR        pszString
 , BYREF pcchString AS DWORD _                          ' __inout DWORD       *pcchString
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'// convert binary to formatted string
'// dwFlags defines string format
'// if pszString is NULL, *pcchString returns size in characters
'// including null-terminator
'//--------------------------------------------------------------------------

DECLARE FUNCTION CryptBinaryToStringW IMPORT "CRYPT32.DLL" ALIAS "CryptBinaryToStringW" ( _
   BYVAL pbBinary AS BYTE PTR _                         ' __in     CONST BYTE  *pbBinary
 , BYVAL cbBinary AS DWORD _                            ' __in     DWORD        cbBinary
 , BYVAL dwFlags AS DWORD _                             ' __in     DWORD        dwFlags
 , BYREF pszString AS WSTRINGZ _                        ' __in     LPWSTR       pszString
 , BYREF pcchString AS DWORD _                          ' __inout  DWORD       *pcchString
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptBinaryToString = CryptBinaryToStringW
#ELSE
   MACRO CryptBinaryToString = CryptBinaryToStringA
#ENDIF

'// dwFlags has the following defines
%CRYPT_STRING_BASE64HEADER           = &H00000000???
%CRYPT_STRING_BASE64                 = &H00000001???
%CRYPT_STRING_BINARY                 = &H00000002???
%CRYPT_STRING_BASE64REQUESTHEADER    = &H00000003???
%CRYPT_STRING_HEX                    = &H00000004???
%CRYPT_STRING_HEXASCII               = &H00000005???
%CRYPT_STRING_BASE64_ANY             = &H00000006???
%CRYPT_STRING_ANY                    = &H00000007???
%CRYPT_STRING_HEX_ANY                = &H00000008???
%CRYPT_STRING_BASE64X509CRLHEADER    = &H00000009???
%CRYPT_STRING_HEXADDR                = &H0000000a???
%CRYPT_STRING_HEXASCIIADDR           = &H0000000b???
%CRYPT_STRING_HEXRAW                 = &H0000000c???

%CRYPT_STRING_HASHDATA               = &H10000000???
%CRYPT_STRING_STRICT                 = &H20000000???
%CRYPT_STRING_NOCRLF                 = &H40000000???
%CRYPT_STRING_NOCR                   = &H80000000???

'// CryptBinaryToString uses the following flags
'// CRYPT_STRING_BASE64HEADER - base64 format with certificate begin
'//                             and end headers
'// CRYPT_STRING_BASE64 - only base64 without headers
'// CRYPT_STRING_BINARY - pure binary copy
'// CRYPT_STRING_BASE64REQUESTHEADER - base64 format with request begin
'//                                    and end headers
'// CRYPT_STRING_BASE64X509CRLHEADER - base64 format with x509 crl begin
'//                                    and end headers
'// CRYPT_STRING_HEX - only hex format
'// CRYPT_STRING_HEXASCII - hex format with ascii char display
'// CRYPT_STRING_HEXADDR - hex format with address display
'// CRYPT_STRING_HEXASCIIADDR - hex format with ascii char and address display
'//
'// CryptBinaryToString accepts CRYPT_STRING_NOCR or'd into one of the above.
'// When set, line breaks contain only LF, instead of CR-LF pairs.

'// CryptStringToBinary uses the following flags
'// CRYPT_STRING_BASE64_ANY tries the following, in order:
'//    CRYPT_STRING_BASE64HEADER
'//    CRYPT_STRING_BASE64
'// CRYPT_STRING_ANY tries the following, in order:
'//    CRYPT_STRING_BASE64_ANY
'//    CRYPT_STRING_BINARY -- should always succeed
'// CRYPT_STRING_HEX_ANY tries the following, in order:
'//    CRYPT_STRING_HEXADDR
'//    CRYPT_STRING_HEXASCIIADDR
'//    CRYPT_STRING_HEXASCII
'//    CRYPT_STRING_HEX


'//+=========================================================================
'//  PFX (PKCS #12) function defintions and types
'//==========================================================================

'//+-------------------------------------------------------------------------
'//  PKCS#12 OIDs
'//--------------------------------------------------------------------------

$szOID_PKCS_12_PbeIds                       = "1.2.840.113549.1.12.1"
$szOID_PKCS_12_pbeWithSHA1And128BitRC4      = "1.2.840.113549.1.12.1.1"
$szOID_PKCS_12_pbeWithSHA1And40BitRC4       = "1.2.840.113549.1.12.1.2"
$szOID_PKCS_12_pbeWithSHA1And3KeyTripleDES  = "1.2.840.113549.1.12.1.3"
$szOID_PKCS_12_pbeWithSHA1And2KeyTripleDES  = "1.2.840.113549.1.12.1.4"
$szOID_PKCS_12_pbeWithSHA1And128BitRC2      = "1.2.840.113549.1.12.1.5"
$szOID_PKCS_12_pbeWithSHA1And40BitRC2       = "1.2.840.113549.1.12.1.6"


'//+-------------------------------------------------------------------------
'//  PBE parameters as defined in PKCS#12 as pkcs-12PbeParams.
'//
'//  NOTE that the salt bytes will immediately follow this structure.
'//  we avoid using pointers in this structure for easy of passing
'//  it into NCryptExportKey() as a NCryptBuffer (may be sent via RPC
'//  to the key isolation process).
'//--------------------------------------------------------------------------
' // Size = 8 bytes
TYPE CRYPT_PKCS12_PBE_PARAMS DWORD
   iIterations AS LONG    ' int /* iteration count              */
   cbSalt      AS DWORD   ' ULONG /* byte size of the salt        */
END TYPE

'//+-------------------------------------------------------------------------
'//      PFXImportCertStore
'//
'//  Import the PFX blob and return a store containing certificates
'//
'//  If the password parameter is incorrect or any other problems decoding
'//  the PFX blob are encountered, the function will return NULL and the
'//      error code can be found from GetLastError().
'//
'//  The dwFlags parameter may be set to the following:
'//  CRYPT_EXPORTABLE - specify that any imported keys should be marked as
'//                     exportable (see documentation on CryptImportKey)
'//  CRYPT_USER_PROTECTED - (see documentation on CryptImportKey)
'//  CRYPT_MACHINE_KEYSET - used to force the private key to be stored in the
'//                        the local machine and not the current user.
'//  CRYPT_USER_KEYSET - used to force the private key to be stored in the
'//                      the current user and not the local machine, even if
'//                      the pfx blob specifies that it should go into local
'//                      machine.
'//--------------------------------------------------------------------------

DECLARE FUNCTION PFXImportCertStore IMPORT "CRYPT32.DLL" ALIAS "PFXImportCertStore" ( _
   BYREF pPFX AS CRYPT_DATA_BLOB _                      ' __in CRYPT_DATA_BLOB* pPFX
 , BYREF szPassword AS WSTRINGZ _                       ' __in LPCWSTR szPassword
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' HCERTSTORE

'// dwFlags definitions for PFXImportCertStore
'//#define CRYPT_EXPORTABLE        0x00000001  // CryptImportKey dwFlags
'//#define CRYPT_USER_PROTECTED    0x00000002  // CryptImportKey dwFlags
'//#define CRYPT_MACHINE_KEYSET    0x00000020  // CryptAcquireContext dwFlags
'//#define PKCS12_INCLUDE_EXTENDED_PROPERTIES 0x10

%CRYPT_USER_KEYSET           = &H00001000???
%PKCS12_PREFER_CNG_KSP       = &H00000100  ' // prefer using CNG KSP
%PKCS12_ALWAYS_CNG_KSP       = &H00000200  ' // always use CNG KSP
%PKCS12_ALLOW_OVERWRITE_KEY  = &H00004000  ' // allow overwrite existing key
%PKCS12_NO_PERSIST_KEY       = &H00008000  ' // key will not be persisted
%PKCS12_IMPORT_RESERVED_MASK = &Hffff0000???


'//+-------------------------------------------------------------------------
'//      PFXIsPFXBlob
'//
'//  This function will try to decode the outer layer of the blob as a pfx
'//  blob, and if that works it will return TRUE, it will return FALSE otherwise
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION PFXIsPFXBlob IMPORT "CRYPT32.DLL" ALIAS "PFXIsPFXBlob" ( _
   BYREF pPFX AS CRYPT_DATA_BLOB _                      ' __in CRYPT_DATA_BLOB* pPFX
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//      PFXVerifyPassword
'//
'//  This function will attempt to decode the outer layer of the blob as a pfx
'//  blob and decrypt with the given password. No data from the blob will be
'//  imported.
'//
'//  Return value is TRUE if password appears correct, FALSE otherwise.
'//
'//--------------------------------------------------------------------------

DECLARE FUNCTION PFXVerifyPassword IMPORT "CRYPT32.DLL" ALIAS "PFXVerifyPassword" ( _
   BYREF pPFX AS CRYPT_DATA_BLOB _                      ' __in CRYPT_DATA_BLOB* pPFX
 , BYREF szPassword AS WSTRINGZ _                       ' __in LPCWSTR szPassword
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+-------------------------------------------------------------------------
'//      PFXExportCertStoreEx
'//
'//  Export the certificates and private keys referenced in the passed-in store
'//
'//  This API encodes the blob under a stronger algorithm. The resulting
'//  PKCS12 blobs are incompatible with the earlier PFXExportCertStore API.
'//
'//  The value passed in the password parameter will be used to encrypt and
'//  verify the integrity of the PFX packet. If any problems encoding the store
'//  are encountered, the function will return FALSE and the error code can
'//  be found from GetLastError().
'//
'//  The dwFlags parameter may be set to any combination of
'//      EXPORT_PRIVATE_KEYS
'//      REPORT_NO_PRIVATE_KEY
'//      REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY
'//
'//  The encoded PFX blob is returned in *pPFX. If pPFX->pbData is NULL upon
'//  input, this is a length only calculation, whereby, pPFX->cbData is updated
'//  with the number of bytes required for the encoded blob. Otherwise,
'//  the memory pointed to by pPFX->pbData is updated with the encoded bytes
'//  and pPFX->cbData is updated with the encoded byte length.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION PFXExportCertStoreEx LIB "Crypt32.dll" _
    ALIAS "PFXExportCertStoreEx" (BYVAL hStore AS DWORD, pPFX AS CRYPT_DATA_BLOB, _
    szPassword AS WSTRINGZ, pvReserved AS ANY, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION PFXExportCertStoreEx IMPORT "CRYPT32.DLL" ALIAS "PFXExportCertStoreEx" ( _
   BYVAL hStore AS DWORD _                              ' __in HCERTSTORE hStore
 , BYREF pPFX AS CRYPT_DATA_BLOB _                      ' __inout CRYPT_DATA_BLOB* pPFX
 , BYREF szPassword AS WSTRINGZ _                       ' __in LPCWSTR szPassword
 , BYVAL pvReserved AS DWORD _                          ' __in void* pvReserved
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL
#ENDIF

'// dwFlags definitions for PFXExportCertStoreEx
%REPORT_NO_PRIVATE_KEY                   = &H0001???
%REPORT_NOT_ABLE_TO_EXPORT_PRIVATE_KEY   = &H0002???
%EXPORT_PRIVATE_KEYS                     = &H0004???
%PKCS12_INCLUDE_EXTENDED_PROPERTIES      = &H0010???
%PKCS12_EXPORT_RESERVED_MASK             = &Hffff0000???


'//+-------------------------------------------------------------------------
'//      PFXExportCertStore
'//
'//  Export the certificates and private keys referenced in the passed-in store
'//
'//  This is an old API kept for compatibility with IE4 clients. New applications
'//  should call the above PfxExportCertStoreEx for enhanced security.
'//--------------------------------------------------------------------------

DECLARE FUNCTION PFXExportCertStore IMPORT "CRYPT32.DLL" ALIAS "PFXExportCertStore" ( _
   BYVAL hStore AS DWORD _                              ' __in HCERTSTORE hStore
 , BYREF pPFX AS CRYPT_DATA_BLOB _                      ' __inout CRYPT_DATA_BLOB* pPFX
 , BYREF szPassword AS WSTRINGZ _                       ' __in LPCWSTR szPassword
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' BOOL

'//+=========================================================================
'//  APIs to get a non-blocking, time valid OCSP response for
'//  a server certificate chain.
'//
'//  Normally, this OCSP response will be included along with the server
'//  certificate in a message returned to the client. As a result only the
'//  server should need to contact the OCSP responser for its certificate.
'//==========================================================================
'#if (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Server OCSP response handle.
'//--------------------------------------------------------------------------
'typedef VOID *HCERT_SERVER_OCSP_RESPONSE;

'//+-------------------------------------------------------------------------
'//  Open a handle to an OCSP response associated with a server certificate
'//  chain. If the end certificate doesn't have an OCSP AIA URL, NULL is
'//  returned with LastError set to CRYPT_E_NOT_IN_REVOCATION_DATABASE. NULL
'//  will also be returned if unable to allocate memory or create system
'//  objects.
'//
'//  This API will try to retrieve an initial OCSP response before returning.
'//  This API will block during the retrieval. If unable to successfully
'//  retrieve the first OCSP response, a non-NULL handle will still be returned
'//  if not one of the error cases mentioned above.
'//
'//  A background thread is created that will pre-fetch time valid
'//  OCSP responses.
'//
'//  The input chain context will be AddRef'ed and not freed until
'//  the returned handle is closed.
'//
'//  CertCloseServerOcspResponse() must be called to close the returned
'//  handle.
'//
'//  dwFlags and pvReserved aren't currently used and must be set to 0
'//  and NULL.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertOpenServerOcspResponse LIB "Crypt32.dll" _
    ALIAS "CertOpenServerOcspResponse" (pChainContext AS CERT_CHAIN_CONTEXT, _
    BYVAL dwFlags AS DWORD, pvReserved AS ANY) AS DWORD
#ELSE
DECLARE FUNCTION CertOpenServerOcspResponse IMPORT "CRYPT32.DLL" ALIAS "CertOpenServerOcspResponse" ( _
   BYREF pChainContext AS CERT_CHAIN_CONTEXT _          ' __in PCCERT_CHAIN_CONTEXT pChainContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS DWORD                                             ' HCERT_SERVER_OCSP_RESPONSE
#ENDIF

'//+-------------------------------------------------------------------------
'//  AddRef a HCERT_SERVER_OCSP_RESPONSE returned by
'//  CertOpenServerOcspResponse(). Each Open and AddRef requires a
'//  corresponding CertCloseServerOcspResponse().
'//--------------------------------------------------------------------------

DECLARE SUB CertAddRefServerOcspResponse IMPORT "CRYPT32.DLL" ALIAS "CertAddRefServerOcspResponse" ( _
   BYVAL hServerOcspResponse AS DWORD _                 ' __in_opt HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse
 )                                                      ' void

'//+-------------------------------------------------------------------------
'//  Close the handle returned by CertOpenServerOcspResponse() or AddRef'ed
'//  by CertAddRefServerOcspResponse().
'//
'//  dwFlags isn't currently used and must be set to 0.
'//--------------------------------------------------------------------------

DECLARE SUB CertCloseServerOcspResponse IMPORT "CRYPT32.DLL" ALIAS "CertCloseServerOcspResponse" ( _
   BYVAL hServerOcspResponse AS DWORD _                 ' __in_opt HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 )                                                      ' void


'//+-------------------------------------------------------------------------
'//  Server OCSP response context.
'//--------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CERT_SERVER_OCSP_RESPONSE_CONTEXT DWORD
   cbSize                AS DWORD      ' DWORD
   pbEncodedOcspResponse AS BYTE PTR   ' BYTE *
   cbEncodedOcspResponse AS DWORD      ' DWORD
END TYPE

'//+-------------------------------------------------------------------------
'//  Get a time valid OCSP response context for the handle created for
'//  the server certificate chain.
'//
'//  This API won't block to retrieve the OCSP response. It will return
'//  the current pre-fetched OCSP response. If a time valid OCSP response
'//  isn't available, NULL will be returned with LAST_ERROR set to
'//  CRYPT_E_REVOCATION_OFFLINE.
'//
'//  CertFreeServerOcspResponseContext() must be called to free the
'//  returned OCSP response context.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertGetServerOcspResponseContext LIB "Crypt32.dll" _
    ALIAS "CertGetServerOcspResponseContext" _
    (BYVAL hServerOcspResponse AS DWORD, BYVAL dwFlags AS DWORD, _
    pvReserved AS ANY) AS DWORD
#ELSE
DECLARE FUNCTION CertGetServerOcspResponseContext IMPORT "CRYPT32.DLL" ALIAS "CertGetServerOcspResponseContext" ( _
   BYVAL hServerOcspResponse AS DWORD _                 ' __in HCERT_SERVER_OCSP_RESPONSE hServerOcspResponse
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS DWORD                                             ' PCCERT_SERVER_OCSP_RESPONSE_CONTEXT
#ENDIF

'//+-------------------------------------------------------------------------
'//  AddRef a PCCERT_SERVER_OCSP_RESPONSE_CONTEXT returned by
'//  CertGetServerOcspResponseContext(). Each Get and AddRef requires a
'//  corresponding CertFreeServerOcspResponseContext().
'//--------------------------------------------------------------------------

DECLARE SUB CertAddRefServerOcspResponseContext IMPORT "CRYPT32.DLL" ALIAS "CertAddRefServerOcspResponseContext" ( _
   BYREF pServerOcspResponseContext AS CERT_SERVER_OCSP_RESPONSE_CONTEXT _ ' __in_opt PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
 )                                                      ' void

'//+-------------------------------------------------------------------------
'//  Free the OCSP response context returned by
'//  CertGetServerOcspResponseContext().
'//--------------------------------------------------------------------------

DECLARE SUB CertFreeServerOcspResponseContext IMPORT "CRYPT32.DLL" ALIAS "CertFreeServerOcspResponseContext" ( _
   BYREF pServerOcspResponseContext AS CERT_SERVER_OCSP_RESPONSE_CONTEXT _ ' __in_opt PCCERT_SERVER_OCSP_RESPONSE_CONTEXT pServerOcspResponseContext
 )                                                      ' void

'#endif // (NTDDI_VERSION >= NTDDI_WINLH)

'//+-------------------------------------------------------------------------
'//  Helper function to do URL retrieval of logo or biometric information
'//  specified in either the szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT
'//  certificate extension.
'//
'//  Only the first hashed URL matching lpszLogoOrBiometricType is used
'//  to do the URL retrieval. Only direct logotypes are supported.
'//  The bytes at the first URL are retrieved via
'//  CryptRetrieveObjectByUrlW and hashed. The computed hash is compared
'//  against the hash in the certificate.  For success, ppbData, pcbData
'//  and optionally ppwszMimeType are updated with
'//  CryptMemAlloc'ed memory which must be freed by calling CryptMemFree().
'//  For failure, *ppbData, *pcbData and optionally *ppwszMimeType are
'//  zero'ed.
'//
'//  For failure, the following errors may be set in LastError:
'//      E_INVALIDARG - invalid lpszLogoOrBiometricType, not one of the
'//          acceptable predefined types.
'//      CRYPT_E_NOT_FOUND - certificate doesn't have the
'//          szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT extension or a matching
'//          lpszLogoOrBiometricType wasn't found with a non-empty
'//          hashed URL.
'//      ERROR_NOT_SUPPORTED - matched the unsupported indirect logotype
'//      NTE_BAD_ALGID - unknown hash algorithm OID
'//      ERROR_INVALID_DATA - no bytes were retrieved at the specified URL
'//          in the certificate extension
'//      CRYPT_E_HASH_VALUE - the computed hash doesn't match the hash
'//          in the certificate
'//  CertRetrieveLogoOrBiometricInfo calls the following functions which
'//  will set LastError for failure:
'//      CryptDecodeObjectEx(szOID_LOGOTYPE_EXT or szOID_BIOMETRIC_EXT)
'//      CryptRetrieveObjectByUrlW
'//      CryptHashCertificate
'//      CryptMemAlloc
'//
'//  lpszLogoOrBiometricType is one of the predefined logotype or biometric
'//  types, an other logotype OID or a biometric OID.
'//
'//  dwRetrievalFlags - see CryptRetrieveObjectByUrlW
'//  dwTimeout - see CryptRetrieveObjectByUrlW
'//
'//  dwFlags - reserved, must be set to 0
'//  pvReserved - reserved, must be set to NULL
'//
'//  *ppwszMimeType is always NULL for the biometric types. For success,
'//  the caller must always check if non-NULL before dereferencing.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertRetrieveLogoOrBiometricInfo LIB "Crypt32.dll" _
    ALIAS "CertRetrieveLogoOrBiometricInfo" (pCertContext AS CERT_CONTEXT, _
    lpszLogoOrBiometricType AS ASCIIZ, BYVAL dwRetrievalFlags AS DWORD, _
    BYVAL dwTimeout AS DWORD, BYVAL dwFlags AS DWORD, pvReserved AS ANY, _
    ppbData AS ANY, pcbData AS DWORD, ppwszMimeType AS ANY) AS LONG
#ELSE
DECLARE FUNCTION CertRetrieveLogoOrBiometricInfo IMPORT "CRYPT32.DLL" ALIAS "CertRetrieveLogoOrBiometricInfo" ( _
   BYVAL pCertContext AS CERT_CONTEXT PTR _             ' __in  PCCERT_CONTEXT pCertContext
 , BYVAL lpszLogoOrBiometricType AS DWORD _             ' __in  LPCSTR lpszLogoOrBiometricType
 , BYVAL dwRetrievalFlags AS DWORD _                    ' __in  DWORD dwRetrievalFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in  DWORD dwTimeout                             // milliseconds
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in  void *pvReserved
 , BYREF ppbData AS DWORD _                             ' __out BYTE **ppbData  // CryptMemFree()
 , BYREF pcbData AS DWORD _                             ' __out DWORD *pcbData
 , BYREF ppwszMimeType AS DWORD _                       ' __out LPWSTR *ppwszMimeType // CryptMemFree()
 ) AS LONG                                              ' BOOL
#ENDIF

'// Predefined Logotypes
%CERT_RETRIEVE_ISSUER_LOGO                    = 1      ' ((LPCSTR) 1)
%CERT_RETRIEVE_SUBJECT_LOGO                   = 2      '  ((LPCSTR) 2)
%CERT_RETRIEVE_COMMUNITY_LOGO                 = 3      ' ((LPCSTR) 3)

'// Predefined Biometric types
%CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE = 1000   ' ((LPCSTR) 1000)

%CERT_RETRIEVE_BIOMETRIC_PICTURE_TYPE = %CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + %CERT_BIOMETRIC_PICTURE_TYPE
%CERT_RETRIEVE_BIOMETRIC_SIGNATURE_TYPE = %CERT_RETRIEVE_BIOMETRIC_PREDEFINED_BASE_TYPE + %CERT_BIOMETRIC_SIGNATURE_TYPE

'//
'// Certificate Selection API
'//

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' // Size = 20 bytes
TYPE CERT_SELECT_CHAIN_PARA DWORD
   hChainEngine     AS DWORD                 ' HCERTCHAINENGINE
   pTime            AS FILETIME PTR          ' PFILETIME
   hAdditionalStore AS DWORD                 ' HCERTSTORE
   pChainPara       AS CERT_CHAIN_PARA PTR   ' PCERT_CHAIN_PARA
   dwFlags          AS DWORD                 ' DWORD
END TYPE

%CERT_SELECT_MAX_PARA               = 500

' // Size = 12 bytes
TYPE CERT_SELECT_CRITERIA DWORD
   dwType AS DWORD   ' DWORD
   cPara  AS DWORD   ' DWORD
   ppPara AS DWORD   ' __field_ecount(cPara) void**
END TYPE

'// Selection Criteria

%CERT_SELECT_BY_ENHKEY_USAGE         = 1
%CERT_SELECT_BY_KEY_USAGE            = 2
%CERT_SELECT_BY_POLICY_OID           = 3
%CERT_SELECT_BY_PROV_NAME            = 4
%CERT_SELECT_BY_EXTENSION            = 5
%CERT_SELECT_BY_SUBJECT_HOST_NAME    = 6
%CERT_SELECT_BY_ISSUER_ATTR          = 7
%CERT_SELECT_BY_SUBJECT_ATTR         = 8
%CERT_SELECT_BY_ISSUER_NAME          = 9
%CERT_SELECT_BY_PUBLIC_KEY           = 10
%CERT_SELECT_BY_TLS_SIGNATURES       = 11

%CERT_SELECT_LAST                    = %CERT_SELECT_BY_TLS_SIGNATURES
%CERT_SELECT_MAX                     = %CERT_SELECT_LAST * 3

'// Selection Flags

%CERT_SELECT_ALLOW_EXPIRED                   = &H00000001???
%CERT_SELECT_TRUSTED_ROOT                    = &H00000002???
%CERT_SELECT_DISALLOW_SELFSIGNED             = &H00000004???
%CERT_SELECT_HAS_PRIVATE_KEY                 = &H00000008???
%CERT_SELECT_HAS_KEY_FOR_SIGNATURE           = &H00000010???
%CERT_SELECT_HAS_KEY_FOR_KEY_EXCHANGE        = &H00000020???
%CERT_SELECT_HARDWARE_ONLY                   = &H00000040???
%CERT_SELECT_ALLOW_DUPLICATES                = &H00000080???


'//+-------------------------------------------------------------------------
'//  Build certificate chains from the certificates in the store and select
'//  the matching ones based on the flags and selection criteria.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CertSelectCertificateChains LIB "Crypt32.dll" _
    ALIAS "CertSelectCertificateChains" ( _
    pSelectionContext AS GUID, _
    BYVAL dwFlags     AS DWORD, _
    pChainParameters  AS CERT_SELECT_CHAIN_PARA, _
    BYVAL cCriteria   AS DWORD, _
    BYVAL rgpCriteria AS CERT_SELECT_CRITERIA PTR, _
    BYVAL hStore      AS DWORD, _  ' HCERTSTORE
    pcSelection       AS DWORD, _
    pprgpSelection    AS ANY _     ' CERT_CHAIN_CONTEXT PTR PTR PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CertSelectCertificateChains IMPORT "CRYPT32.DLL" ALIAS "CertSelectCertificateChains" ( _
   BYREF pSelectionContext AS GUID _                    '  __in_opt LPCGUID pSelectionContext
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pChainParameters AS CERT_SELECT_CHAIN_PARA _   ' __in_opt PCCERT_SELECT_CHAIN_PARA pChainParameters
 , BYVAL cCriteria AS DWORD _                           ' __in DWORD cCriteria
 , BYREF rgpCriteria AS CERT_SELECT_CRITERIA _          ' __in PCCERT_SELECT_CRITERIA rgpCriteria
 , BYVAL hStore AS DWORD _                              ' __in HCERTSTORE hStore
 , BYREF pcSelection AS DWORD _                         ' __out PDWORD pcSelection
 , BYREF pprgpSelection AS CERT_CHAIN_CONTEXT _         ' __out PCCERT_CHAIN_CONTEXT** pprgpSelection
 ) AS LONG                                              ' BOOL
#ENDIF

'//+-------------------------------------------------------------------------
'//  Free the array of pointers to chain contexts.
'//  CertFreeCertificateChain is NOT called for each entry.
'//--------------------------------------------------------------------------

DECLARE SUB CertFreeCertificateChainList IMPORT "CRYPT32.DLL" ALIAS "CertFreeCertificateChainList" ( _
   BYREF prgpSelection AS CERT_CHAIN_CONTEXT _          ' __in PCCERT_CHAIN_CONTEXT* prgpSelection
 )                                                      ' VOID

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'//
'// Time stamp API
'//

'#if (NTDDI_VERSION >= NTDDI_WIN7)

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_REQUEST
'//
'//--------------------------------------------------------------------------
%TIMESTAMP_VERSION = 1

' // Size = 48 bytes
TYPE CRYPT_TIMESTAMP_REQUEST DWORD
   dwVersion      AS DWORD                        ' DWORD // v1
   HashAlgorithm  AS CRYPT_ALGORITHM_IDENTIFIER
   HashedMessage  AS CRYPT_DER_BLOB
   pszTSAPolicyId AS ASCIIZ PTR                   ' LPSTR // OPTIONAL
   Nonce          AS CRYPT_INTEGER_BLOB           ' // OPTIONAL
   fCertReq       AS LONG                         ' BOOL // DEFAULT FALSE
   cExtension     AS DWORD                        ' DWORD
   rgExtension    AS CERT_EXTENSION PTR           ' PCERT_EXTENSION // OPTIONAL
END TYPE

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_RESPONSE
'//
'//--------------------------------------------------------------------------
' // Size = 32 bytes
TYPE CRYPT_TIMESTAMP_RESPONSE DWORD
   dwStatus    AS DWORD            ' DWORD
   cFreeText   AS DWORD            ' DWORD // OPTIONAL
   rgFreeText  AS WSTRINGZ PTR     ' LPWSTR*
   FailureInfo AS CRYPT_BIT_BLOB   ' // OPTIONAL
   ContentInfo AS CRYPT_DER_BLOB   ' // OPTIONAL
END TYPE

%TIMESTAMP_STATUS_GRANTED                       = 0
%TIMESTAMP_STATUS_GRANTED_WITH_MODS             = 1
%TIMESTAMP_STATUS_REJECTED                      = 2
%TIMESTAMP_STATUS_WAITING                       = 3
%TIMESTAMP_STATUS_REVOCATION_WARNING            = 4
%TIMESTAMP_STATUS_REVOKED                       = 5

%TIMESTAMP_FAILURE_BAD_ALG                      = 0
%TIMESTAMP_FAILURE_BAD_REQUEST                  = 2
%TIMESTAMP_FAILURE_BAD_FORMAT                   = 5
%TIMESTAMP_FAILURE_TIME_NOT_AVAILABLE           = 14
%TIMESTAMP_FAILURE_POLICY_NOT_SUPPORTED         = 15
%TIMESTAMP_FAILURE_EXTENSION_NOT_SUPPORTED      = 16
%TIMESTAMP_FAILURE_INFO_NOT_AVAILABLE           = 17
%TIMESTAMP_FAILURE_SYSTEM_FAILURE               = 25

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_ACCURACY
'//
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_TIMESTAMP_ACCURACY DWORD
   dwSeconds AS DWORD   ' DWORD // OPTIONAL
   dwMillis  AS DWORD   ' DWORD // OPTIONAL
   dwMicros  AS DWORD   ' DWORD // OPTIONAL
END TYPE

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_INFO
'//
'//--------------------------------------------------------------------------
' // Size = 76 bytes
TYPE CRYPT_TIMESTAMP_INFO DWORD
   dwVersion      AS DWORD                          ' DWORD // v1
   pszTSAPolicyId AS ASCIIZ PTR                     ' LPSTR
   HashAlgorithm  AS CRYPT_ALGORITHM_IDENTIFIER
   HashedMessage  AS CRYPT_DER_BLOB
   SerialNumber   AS CRYPT_INTEGER_BLOB
   ftTime         AS FILETIME
   pvAccuracy     AS CRYPT_TIMESTAMP_ACCURACY PTR   ' PCRYPT_TIMESTAMP_ACCURACY // OPTIONAL
   fOrdering      AS LONG                           ' BOOL // OPTIONAL
   Nonce          AS CRYPT_DER_BLOB                 ' // OPTIONAL
   Tsa            AS CRYPT_DER_BLOB                 ' // OPTIONAL
   cExtension     AS DWORD                          ' DWORD
   rgExtension    AS CERT_EXTENSION PTR             ' PCERT_EXTENSION // OPTIONAL
END TYPE

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_CONTEXT
'//
'//--------------------------------------------------------------------------
' // Size = 12 bytes
TYPE CRYPT_TIMESTAMP_CONTEXT DWORD
   cbEncoded  AS DWORD                      ' DWORD
   pbEncoded  AS BYTE PTR                   ' __field_bcount(cbEncoded) BYTE*
   pTimeStamp AS CRYPT_TIMESTAMP_INFO PTR   ' PCRYPT_TIMESTAMP_INFO
END TYPE

'//+-------------------------------------------------------------------------
'//  CRYPT_TIMESTAMP_PARA
'//
'//  pszTSAPolicyId
'//      [optional] Specifies the TSA policy under which the time stamp token
'//      should be provided.
'//
'//  Nonce
'//      [optional] Specifies the nonce value used by the client to verify the
'//      timeliness of the response when no local clock is available.
'//
'//  fCertReq
'//      Specifies whether the TSA must include in response the certificates
'//      used to sign the time stamp token.
'//
'//  rgExtension
'//      [optional]  Specifies Extensions to be included in request.

'//--------------------------------------------------------------------------
' // Size = 24 bytes
TYPE CRYPT_TIMESTAMP_PARA DWORD
   pszTSAPolicyId AS ASCIIZ PTR           ' LPCSTR // OPTIONAL
   fRequestCerts  AS LONG                 ' BOOL // Default is TRUE
   Nonce          AS CRYPT_INTEGER_BLOB   ' // OPTIONAL
   cExtension     AS DWORD                ' DWORD
   rgExtension    AS CERT_EXTENSION PTR   ' __field_ecount(cExtension) PCERT_EXTENSION // OPTIONAL
END TYPE

'//+-------------------------------------------------------------------------
'//  CryptRetrieveTimeStamp
'//
'//  wszUrl
'//     [in] Specifies TSA where to send request to.
'//
'//  dwRetrievalFlags
'//     [in]
'//         TIMESTAMP_VERIFY_CONTEXT_SIGNATURE
'//         TIMESTAMP_NO_AUTH_RETRIEVAL
'//         TIMESTAMP_DONT_HASH_DATA
'//
'//  dwTimeout
'//     [in] Specifies the maximum number of milliseconds to wait for retrieval.
'//     If a value of zero is specified, this function does not time-out.
'//
'//  pszHashId
'//      [in] Specifies hash algorithm OID.
'//
'//  pPara
'//      [in, optional] Specifies additional request parameters.
'//
'//  pbData
'//      [in] Points to array of bytes to be timestamped.
'//
'//  cbData
'//      [in] Number of bytes in pbData.
'//
'//  ppTsContext
'//     [out] The caller must free ppTsContext with CryptMemFree.
'//
'//  ppTsSigner
'//     [out, optional] The address of a CERT_CONTEXT structure pointer that
'//     receives the certificate of the signer.
'//     When you have finished using this structure, free it by passing this
'//     pointer to the CertFreeCertificateContext function.
'//     This parameter can be NULL if the TSA signer's certificate is not needed.
'//
'// Remarks:
'//
'//     The TIMESTAMP_VERIFY_CONTEXT_SIGNATURE flag can be only used,
'//     if fRequestCerts value is TRUE.
'//
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptRetrieveTimeStamp LIB "Crypt32.dll" _
    ALIAS "CryptRetrieveTimeStamp" ( _
    wszUrl                 AS WSTRINGZ, _
    BYVAL dwRetrievalFlags AS DWORD, _
    BYVAL dwTimeout        AS DWORD, _
    pszHashId              AS ASCIIZ, _
    pPara                  AS CRYPT_TIMESTAMP_PARA, _
    BYVAL pbData           AS BYTE PTR, _
    BYVAL cbData           AS DWORD, _
    ppTsContext            AS ANY, _      ' CRYPT_TIMESTAMP_CONTEXT PTR PTR
    ppTsSigner             AS ANY, _      ' CERT_CONTEXT PTR PTR
    phStore                AS DWORD _ ' HCERTSTORE PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptRetrieveTimeStamp IMPORT "CRYPT32.DLL" ALIAS "CryptRetrieveTimeStamp" ( _
   BYREF wszUrl AS WSTRINGZ _                           ' __in LPCWSTR wszUrl
 , BYVAL dwRetrievalFlags AS DWORD _                    ' __in DWORD dwRetrievalFlags
 , BYVAL dwTimeout AS DWORD _                           ' __in DWORD dwTimeout
 , BYREF pszHashId AS ASCIIZ _                          ' __in LPCSTR pszHashId
 , BYREF pPara AS CRYPT_TIMESTAMP_PARA _                ' __in_opt const CRYPT_TIMESTAMP_PARA *pPara
 , BYVAL pbData AS BYTE PTR _                           ' __in_bcount(cbData) const BYTE *pbData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF ppTsContext AS DWORD _                         ' __out PCRYPT_TIMESTAMP_CONTEXT *ppTsContext
 , OPTIONAL BYREF ppTsSigner AS DWORD _                 ' __out_opt PCCERT_CONTEXT *ppTsSigner
 , OPTIONAL BYREF phStore AS DWORD _                    ' __out_opt HCERTSTORE *phStore
 ) AS LONG                                              ' BOOL
#ENDIF

'// Set this flag to inhibit hash calculation on pbData
%TIMESTAMP_DONT_HASH_DATA                = &H00000001???

'// Set this flag to enforce signature validation on retrieved time stamp.
%TIMESTAMP_VERIFY_CONTEXT_SIGNATURE      = &H00000020???   ' // CRYPT_VERIFY_CONTEXT_SIGNATURE

'// Set this flag to inhibit automatic authentication handling. See the
'// wininet flag, INTERNET_FLAG_NO_AUTH, for more details.
%TIMESTAMP_NO_AUTH_RETRIEVAL             = &H00020000???   ' //  CRYPT_NO_AUTH_RETRIEVAL

'//+-------------------------------------------------------------------------
'// CryptVerifyTimeStampSignature
'//
'//  pbTSContentInfo
'//      [in] Points to a buffer with timestamp content.
'//      These bytes are the same as returned in response by CRYPT_TIMESTAMP_CONTEXT::pbEncoded
'//
'//  cbTSContentInfo
'//      [in] Number of bytes in pbTSContentInfo.
'//
'//  pbData
'//      [in] Points to array of bytes to be timestamped.
'//
'//  cbData
'//      [in] Number of bytes in pbData.
'//
'// hAdditionalStore
'//    [in] Handle of any additional store to search for supporting
'//    TSA's signing certificates and certificate trust lists (CTLs).
'//    This parameter can be NULL if no additional store is to be searched.
'//
'// ppTsContext
'//    [out] The caller must free ppTsContext with CryptMemFree
'//
'// ppTsSigner
'//    [out, optional] The address of a CERT_CONTEXT structure pointer that
'//    receives the certificate of the signer.
'//    When you have finished using this structure, free it by passing this
'//    pointer to the CertFreeCertificateContext function.
'//    This parameter can be NULL if the TSA signer's certificate is not needed.
'//
'// NOTE:
'//    The caller should validate pszTSAPolicyId, if any was specified in the request,
'//    and ftTime.
'//    The caller should also build a chain for ppTsSigner and validate the trust.
'//--------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CryptVerifyTimeStampSignature LIB "Crypt32.dll" _
    ALIAS "CryptVerifyTimeStampSignature" ( _
    BYVAL pbTSContentInfo  AS BYTE PTR, _
    BYVAL cbTSContentInfo  AS DWORD, _
    BYVAL pbData           AS BYTE PTR, _
    BYVAL cbData           AS DWORD, _
    BYVAL hAdditionalStore AS DWORD, _  ' HCERTSTORE
    ppTsContext            AS ANY, _    ' CRYPT_TIMESTAMP_CONTEXT PTR PTR
    ppTsSigner             AS ANY, _    ' CERT_CONTEXT PTR PTR
    phStore                AS DWORD _   ' HCERTSTORE PTR
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION CryptVerifyTimeStampSignature IMPORT "CRYPT32.DLL" ALIAS "CryptVerifyTimeStampSignature" ( _
   BYVAL pbTSContentInfo AS BYTE PTR _                  ' __in const BYTE *pbTSContentInfo
 , BYVAL cbTSContentInfo AS DWORD _                     ' __in DWORD cbTSContentInfo
 , BYVAL pbData AS BYTE PTR _                           ' __in const BYTE *pbData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL hAdditionalStore AS DWORD _                    ' __in_opt HCERTSTORE hAdditionalStore
 , BYREF ppTsContext AS DWORD _                         ' __out PCRYPT_TIMESTAMP_CONTEXT *ppTsContext
 , OPTIONAL BYREF ppTsSigner AS DWORD _                 ' __out_opt PCCERT_CONTEXT *ppTsSigner
 , OPTIONAL BYREF phStore AS DWORD _                    ' __out_opt HCERTSTORE *phStore
 ) AS LONG                                              ' BOOL
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'#endif //!defined(_DDK_DRIVER_)
