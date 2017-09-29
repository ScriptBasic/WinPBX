' ########################################################################################
' Microsoft Windows
' File: schannel.inc
' Contents: Public Definitions for SCHANNEL Security Provider
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SCHANNEL_INC = 1

#INCLUDE ONCE "wincrypt.inc"

'//
'// Security package names.
'//

$UNISP_NAME_A     = "Microsoft Unified Security Protocol Provider"
$$UNISP_NAME_W    = "Microsoft Unified Security Protocol Provider"$$
#IF %DEF(%UNICODE)
   MACRO UNISP_NAME = $$UNISP_NAME_W
#ELSE
   MACRO UNISP_NAME = $UNISP_NAME_A
#ENDIF

$SSL2SP_NAME_A    = "Microsoft SSL 2.0"
$$SSL2SP_NAME_W   = "Microsoft SSL 2.0"$$
#IF %DEF(%UNICODE)
   MACRO SSL2SP_NAME = $$SSL2SP_NAME_W
#ELSE
   MACRO SSL2SP_NAME = $SSL2SP_NAME_A
#ENDIF

$SSL3SP_NAME_A    = "Microsoft SSL 3.0"
$$SSL3SP_NAME_W   = "Microsoft SSL 3.0"$$
#IF %DEF(%UNICODE)
   MACRO SSL3SP_NAME = $$SSL3SP_NAME_W
#ELSE
   MACRO SSL3SP_NAME = $SSL3SP_NAME_A
#ENDIF

$TLS1SP_NAME_A    = "Microsoft TLS 1.0"
$$TLS1SP_NAME_W   = "Microsoft TLS 1.0"$$
#IF %DEF(%UNICODE)
   MACRO TLS1SP_NAME = $$TLS1SP_NAME_W
#ELSE
   MACRO TLS1SP_NAME = $TLS1SP_NAME_A
#ENDIF

$PCT1SP_NAME_A    = "Microsoft PCT 1.0"
$$PCT1SP_NAME_W   = "Microsoft PCT 1.0"$$
#IF %DEF(%UNICODE)
   MACRO PCT1SP_NAME = $$PCT1SP_NAME_W
#ELSE
   MACRO PCT1SP_NAME = $PCT1SP_NAME_A
#ENDIF

$SCHANNEL_NAME_A  = "Schannel"
$$SCHANNEL_NAME_W  = "Schannel"$$
#IF %DEF(%UNICODE)
   MACRO SCHANNEL_NAME = $$SCHANNEL_NAME_W
#ELSE
   MACRO SCHANNEL_NAME = $SCHANNEL_NAME_A
#ENDIF

' enum eTlsSignatureAlgorithm
%TlsSignatureAlgorithm_Anonymous = 0
%TlsSignatureAlgorithm_Rsa       = 1
%TlsSignatureAlgorithm_Dsa       = 2
%TlsSignatureAlgorithm_Ecdsa     = 3

' enum eTlsHashAlgorithm
%TlsHashAlgorithm_None           = 0
%TlsHashAlgorithm_Md5            = 1
%TlsHashAlgorithm_Sha1           = 2
%TlsHashAlgorithm_Sha224         = 3
%TlsHashAlgorithm_Sha256         = 4
%TlsHashAlgorithm_Sha384         = 5
%TlsHashAlgorithm_Sha512         = 6

'//
'// RPC constants.
'//

%UNISP_RPC_ID   = 14


'//
'// QueryContextAttributes/QueryCredentialsAttribute extensions
'//

%SECPKG_ATTR_ISSUER_LIST          = &H50   ' // (OBSOLETE) returns SecPkgContext_IssuerListInfo
%SECPKG_ATTR_REMOTE_CRED          = &H51   ' // (OBSOLETE) returns SecPkgContext_RemoteCredentialInfo
%SECPKG_ATTR_LOCAL_CRED           = &H52   ' // (OBSOLETE) returns SecPkgContext_LocalCredentialInfo
%SECPKG_ATTR_REMOTE_CERT_CONTEXT  = &H53   ' // returns PCCERT_CONTEXT
%SECPKG_ATTR_LOCAL_CERT_CONTEXT   = &H54   ' // returns PCCERT_CONTEXT
%SECPKG_ATTR_ROOT_STORE           = &H55   ' // returns HCERTCONTEXT to the root store
%SECPKG_ATTR_SUPPORTED_ALGS       = &H56   ' // returns SecPkgCred_SupportedAlgs
%SECPKG_ATTR_CIPHER_STRENGTHS     = &H57   ' // returns SecPkgCred_CipherStrengths
%SECPKG_ATTR_SUPPORTED_PROTOCOLS  = &H58   ' // returns SecPkgCred_SupportedProtocols
%SECPKG_ATTR_ISSUER_LIST_EX       = &H59   ' // returns SecPkgContext_IssuerListInfoEx
%SECPKG_ATTR_CONNECTION_INFO      = &H5a   ' // returns SecPkgContext_ConnectionInfo
%SECPKG_ATTR_EAP_KEY_BLOCK        = &H5b   ' // returns SecPkgContext_EapKeyBlock
%SECPKG_ATTR_MAPPED_CRED_ATTR     = &H5c   ' // returns SecPkgContext_MappedCredAttr
%SECPKG_ATTR_SESSION_INFO         = &H5d   ' // returns SecPkgContext_SessionInfo
%SECPKG_ATTR_APP_DATA             = &H5e   ' // sets/returns SecPkgContext_SessionAppData
%SECPKG_ATTR_REMOTE_CERTIFICATES  = &H5F   ' // returns SecPkgContext_Certificates
%SECPKG_ATTR_CLIENT_CERT_POLICY   = &H60   ' // sets    SecPkgCred_ClientCertCtlPolicy
%SECPKG_ATTR_CC_POLICY_RESULT     = &H61   ' // returns SecPkgContext_ClientCertPolicyResult
%SECPKG_ATTR_USE_NCRYPT           = &H62   ' // Sets the CRED_FLAG_USE_NCRYPT_PROVIDER FLAG on cred group
%SECPKG_ATTR_LOCAL_CERT_INFO      = &H63   ' // returns SecPkgContext_CertInfo
%SECPKG_ATTR_CIPHER_INFO          = &H64   ' // returns new CNG SecPkgContext_CipherInfo
%SECPKG_ATTR_EAP_PRF_INFO         = &H65   ' // sets    SecPkgContext_EapPrfInfo
%SECPKG_ATTR_SUPPORTED_SIGNATURES = &H66   ' // returns SecPkgContext_SupportedSignatures

'// OBSOLETE - included here for backward compatibility only
' // Size = 20 bytes
TYPE SecPkgContext_RemoteCredentialInfo DWORD
   cbCertificateChain AS DWORD      ' DWORD
   pbCertificateChain AS BYTE PTR   ' PBYTE
   cCertificates      AS DWORD      ' DWORD
   fFlags             AS DWORD      ' DWORD
   dwBits             AS DWORD      ' DWORD
END TYPE

%RCRED_STATUS_NOCRED          = &H00000000???
%RCRED_CRED_EXISTS            = &H00000001???
%RCRED_STATUS_UNKNOWN_ISSUER  = &H00000002???


'// OBSOLETE - included here for backward compatibility only
' // Size = 20 bytes
TYPE SecPkgContext_LocalCredentialInfo DWORD
   cbCertificateChain AS DWORD      ' DWORD
   pbCertificateChain AS BYTE PTR   ' PBYTE
   cCertificates      AS DWORD      ' DWORD
   fFlags             AS DWORD      ' DWORD
   dwBits             AS DWORD      ' DWORD
END TYPE

%LCRED_STATUS_NOCRED          = &H00000000???
%LCRED_CRED_EXISTS            = &H00000001???
%LCRED_STATUS_UNKNOWN_ISSUER  = &H00000002???

' // Size = 8 bytes
TYPE SecPkgCred_SupportedAlgs DWORD
   cSupportedAlgs    AS DWORD       ' DWORD
   palgSupportedAlgs AS DWORD PTR   ' ALG_ID *
END TYPE

' // Size = 8 bytes
TYPE SecPkgCred_CipherStrengths DWORD
   dwMinimumCipherStrength AS DWORD   ' DWORD
   dwMaximumCipherStrength AS DWORD   ' DWORD
END TYPE

' // Size = 4 bytes
TYPE SecPkgCred_SupportedProtocols DWORD
   grbitProtocol AS DWORD   ' DWORD
END TYPE

' // Size = 48 bytes
TYPE SecPkgCred_ClientCertPolicy DWORD
   dwFlags                       AS DWORD          ' DWORD
   guidPolicyId                  AS GUID           ' GUID
   dwCertFlags                   AS DWORD          ' DWORD
   dwUrlRetrievalTimeout         AS DWORD          ' DWORD
   fCheckRevocationFreshnessTime AS LONG           ' BOOL
   dwRevocationFreshnessTime     AS DWORD          ' DWORD
   fOmitUsageCheck               AS LONG           ' BOOL
   pwszSslCtlStoreName           AS WSTRINGZ PTR   ' LPWSTR
   pwszSslCtlIdentifier          AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 20 bytes
TYPE SecPkgContext_ClientCertPolicyResult DWORD
   dwPolicyResult AS LONG   ' HRESULT
   guidPolicyId   AS GUID   ' GUID
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_IssuerListInfoEx DWORD
   aIssuers AS CERT_NAME_BLOB PTR   ' PCERT_NAME_BLOB
   cIssuers AS DWORD                ' DWORD
END TYPE

' // Size = 28 bytes
TYPE SecPkgContext_ConnectionInfo DWORD
   dwProtocol       AS DWORD   ' DWORD
   aiCipher         AS DWORD   ' ALG_ID
   dwCipherStrength AS DWORD   ' DWORD
   aiHash           AS DWORD   ' ALG_ID
   dwHashStrength   AS DWORD   ' DWORD
   aiExch           AS DWORD   ' ALG_ID
   dwExchStrength   AS DWORD   ' DWORD
END TYPE

%SZ_ALG_MAX_SIZE             = 64
%SECPKGCONTEXT_CIPHERINFO_V1 = 1

' // Size = 680 bytes
TYPE SecPkgContext_CipherInfo DWORD
   dwVersion         AS DWORD                         ' DWORD
   dwProtocol        AS DWORD                         ' DWORD
   dwCipherSuite     AS DWORD                         ' DWORD
   dwBaseCipherSuite AS DWORD                         ' DWORD
   szCipherSuite     AS WSTRINGZ * %SZ_ALG_MAX_SIZE   ' WCHAR
   szCipher          AS WSTRINGZ * %SZ_ALG_MAX_SIZE   ' WCHAR
   dwCipherLen       AS DWORD                         ' DWORD
   dwCipherBlockLen  AS DWORD                         ' DWORD // in bytes
   szHash            AS WSTRINGZ * %SZ_ALG_MAX_SIZE   ' WCHAR
   dwHashLen         AS DWORD                         ' DWORD
   szExchange        AS WSTRINGZ * %SZ_ALG_MAX_SIZE   ' WCHAR
   dwMinExchangeLen  AS DWORD                         ' DWORD
   dwMaxExchangeLen  AS DWORD                         ' DWORD
   szCertificate     AS WSTRINGZ * %SZ_ALG_MAX_SIZE   ' WCHAR
   dwKeyType         AS DWORD                         ' DWORD
END TYPE

' // Size = 192 bytes
TYPE SecPkgContext_EapKeyBlock DWORD
   rgbKeys(127) AS BYTE   ' BYTE[128]
   rgbIVs(63)   AS BYTE   ' BYTE[64]
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_MappedCredAttr DWORD
   dwAttribute AS DWORD   ' DWORD
   pvBuffer    AS DWORD   ' PVOID
END TYPE

'// Flag values for SecPkgContext_SessionInfo
%SSL_SESSION_RECONNECT = 1

' // Size = 40 bytes
TYPE SecPkgContext_SessionInfo DWORD
   dwFlags          AS DWORD   ' DWORD
   cbSessionId      AS DWORD   ' DWORD
   rgbSessionId(31) AS BYTE    ' BYTE[32]
END TYPE

' // Size = 12 bytes
TYPE SecPkgContext_SessionAppData DWORD
   dwFlags   AS DWORD      ' DWORD
   cbAppData AS DWORD      ' DWORD
   pbAppData AS BYTE PTR   ' __field_bcount(cbAppData) PBYTE
END TYPE

' // Size = 12 bytes
TYPE SecPkgContext_EapPrfInfo DWORD
   dwVersion AS DWORD      ' DWORD
   cbPrfData AS DWORD      ' DWORD
   pbPrfData AS BYTE PTR   ' __field_bcount(cbPrfData) PBYTE
END TYPE

'typedef struct _SecPkgContext_SupportedSignatures
'{
'    WORD cSignatureAndHashAlgorithms;

'    //
'    // Upper byte (from TLS 1.2, RFC 4346):
'    //     enum {
'    //         anonymous(0), rsa(1), dsa(2), ecdsa(3), (255)
'    //     } SignatureAlgorithm;
'    //
'    // enum eTlsSignatureAlgorithm

'    //
'    // Lower byte (from TLS 1.2, RFC 4346):
'    //     enum {
'    //         none(0), md5(1), sha1(2), sha224(3), sha256(4), sha384(5),
'    //         sha512(6), (255)
'    //     } HashAlgorithm;
'    //
'    //
'    // enum eTlsHashAlgorithm

'    __field_ecount(cSignatureAndHashAlgorithms)
'        WORD *pSignatureAndHashAlgorithms;
'} SecPkgContext_SupportedSignatures, *PSecPkgContext_SupportedSignatures;

' // Size = 8 bytes
TYPE SecPkgContext_SupportedSignatures DWORD
   cSignatureAndHashAlgorithms AS WORD
   pSignatureAndHashAlgorithms AS WORD PTR
END TYPE

'//
'// This property returns the raw binary certificates that were received
'// from the remote party. The format of the buffer that's returned is as
'// follows.
'//
'//     <4 bytes> length of certificate #1
'//     <n bytes> certificate #1
'//     <4 bytes> length of certificate #2
'//     <n bytes> certificate #2
'//     ...
'//
'// After this data is processed, the caller of QueryContextAttributes
'// must free the pbCertificateChain buffer using FreeContextBuffer.
'//
' // Size = 12 bytes
TYPE SecPkgContext_Certificates DWORD
   cCertificates      AS DWORD      ' DWORD
   cbCertificateChain AS DWORD      ' DWORD
   pbCertificateChain AS BYTE PTR   ' PBYTE
END TYPE

'//
'// This property returns information about a certificate. In particular
'// it is useful (and only available) in the kernel where CAPI2 is not
'// available.
'//
' // Size = 24 bytes
TYPE SecPkgContext_CertInfo DWORD
   dwVersion       AS DWORD          ' DWORD
   cbSubjectName   AS DWORD          ' DWORD
   pwszSubjectName AS WSTRINGZ PTR   ' LPWSTR
   cbIssuerName    AS DWORD          ' DWORD
   pwszIssuerName  AS WSTRINGZ PTR   ' LPWSTR
   dwKeySize       AS DWORD          ' DWORD
END TYPE

%KERN_CONTEXT_CERT_INFO_V1 = &H00000000???

'//
'// Schannel credentials data structure.
'//

%SCH_CRED_V1              = &H00000001
%SCH_CRED_V2              = &H00000002  ' // for legacy code
%SCH_CRED_VERSION         = &H00000002  ' // for legacy code
%SCH_CRED_V3              = &H00000003  ' // for legacy code
%SCHANNEL_CRED_VERSION    = &H00000004

'struct _HMAPPER;

' // Size = 56 bytes
TYPE SCHANNEL_CRED DWORD
   dwVersion               AS DWORD              ' DWORD // always SCHANNEL_CRED_VERSION
   cCreds                  AS DWORD              ' DWORD
   paCred                  AS CERT_CONTEXT PTR   ' PCCERT_CONTEXT *
   hRootStore              AS DWORD              ' HCERTSTORE
   cMappers                AS DWORD              ' DWORD
   aphMappers              AS DWORD              ' struct _HMAPPER **
   cSupportedAlgs          AS DWORD              ' DWORD
   palgSupportedAlgs       AS DWORD PTR          ' ALG_ID *
   grbitEnabledProtocols   AS DWORD              ' DWORD
   dwMinimumCipherStrength AS DWORD              ' DWORD
   dwMaximumCipherStrength AS DWORD              ' DWORD
   dwSessionLifespan       AS DWORD              ' DWORD
   dwFlags                 AS DWORD              ' DWORD
   dwCredFormat            AS DWORD              ' DWORD
END TYPE


'// Values for SCHANNEL_CRED dwCredFormat field.
%SCH_CRED_FORMAT_CERT_CONTEXT    = &H00000000???
%SCH_CRED_FORMAT_CERT_HASH       = &H00000001???
%SCH_CRED_FORMAT_CERT_HASH_STORE = &H00000002???

%SCH_CRED_MAX_STORE_NAME_SIZE    = 128
%SCH_CRED_MAX_SUPPORTED_ALGS     = 256
%SCH_CRED_MAX_SUPPORTED_CERTS    = 100

' // Size = 32 bytes
TYPE SCHANNEL_CERT_HASH DWORD
   dwLength    AS DWORD   ' DWORD
   dwFlags     AS DWORD   ' DWORD
   hProv       AS DWORD   ' HCRYPTPROV
   ShaHash(19) AS BYTE    ' BYTE[20]
END TYPE

' // Size = 288 bytes
TYPE SCHANNEL_CERT_HASH_STORE DWORD
   dwLength      AS DWORD   ' DWORD
   dwFlags       AS DWORD   ' DWORD
   hProv         AS DWORD   ' HCRYPTPROV
   ShaHash(19)   AS BYTE    ' BYTE[20]
   pwszStoreName AS WSTRINGZ * %SCH_CRED_MAX_STORE_NAME_SIZE   ' WCHAR
END TYPE

'// Values for SCHANNEL_CERT_HASH dwFlags field.
%SCH_MACHINE_CERT_HASH           = &H00000001???


'//+-------------------------------------------------------------------------
'// Flags for use with SCHANNEL_CRED
'//
'// SCH_CRED_NO_SYSTEM_MAPPER
'//      This flag is intended for use by server applications only. If this
'//      flag is set, then schannel does *not* attempt to map received client
'//      certificate chains to an NT user account using the built-in system
'//      certificate mapper.This flag is ignored by non-NT5 versions of
'//      schannel.
'//
'// SCH_CRED_NO_SERVERNAME_CHECK
'//      This flag is intended for use by client applications only. If this
'//      flag is set, then when schannel validates the received server
'//      certificate chain, is does *not* compare the passed in target name
'//      with the subject name embedded in the certificate. This flag is
'//      ignored by non-NT5 versions of schannel. This flag is also ignored
'//      if the SCH_CRED_MANUAL_CRED_VALIDATION flag is set.
'//
'// SCH_CRED_MANUAL_CRED_VALIDATION
'//      This flag is intended for use by client applications only. If this
'//      flag is set, then schannel will *not* automatically attempt to
'//      validate the received server certificate chain. This flag is
'//      ignored by non-NT5 versions of schannel, but all client applications
'//      that wish to validate the certificate chain themselves should
'//      specify this flag, so that there's at least a chance they'll run
'//      correctly on NT5.
'//
'// SCH_CRED_NO_DEFAULT_CREDS
'//      This flag is intended for use by client applications only. If this
'//      flag is set, and the server requests client authentication, then
'//      schannel will *not* attempt to automatically acquire a suitable
'//      default client certificate chain. This flag is ignored by non-NT5
'//      versions of schannel, but all client applications that wish to
'//      manually specify their certicate chains should specify this flag,
'//      so that there's at least a chance they'll run correctly on NT5.
'//
'// SCH_CRED_AUTO_CRED_VALIDATION
'//      This flag is the opposite of SCH_CRED_MANUAL_CRED_VALIDATION.
'//      Conservatively written client applications will always specify one
'//      flag or the other.
'//
'// SCH_CRED_USE_DEFAULT_CREDS
'//      This flag is the opposite of SCH_CRED_NO_DEFAULT_CREDS.
'//      Conservatively written client applications will always specify one
'//      flag or the other.
'//
'// SCH_CRED_DISABLE_RECONNECTS
'//      This flag is intended for use by server applications only. If this
'//      flag is set, then full handshakes performed with this credential
'//      will not be marked suitable for reconnects. A cache entry will still
'//      be created, however, so the session can be made resumable later
'//      via a call to ApplyControlToken.
'//
'//
'// SCH_CRED_REVOCATION_CHECK_END_CERT
'// SCH_CRED_REVOCATION_CHECK_CHAIN
'// SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT
'//      These flags specify that when schannel automatically validates a
'//      received certificate chain, some or all of the certificates are to
'//      be checked for revocation. Only one of these flags may be specified.
'//      See the CertGetCertificateChain function. These flags are ignored by
'//      non-NT5 versions of schannel.
'//
'// SCH_CRED_IGNORE_NO_REVOCATION_CHECK
'// SCH_CRED_IGNORE_REVOCATION_OFFLINE
'//      These flags instruct schannel to ignore the
'//      CRYPT_E_NO_REVOCATION_CHECK and CRYPT_E_REVOCATION_OFFLINE errors
'//      respectively if they are encountered when attempting to check the
'//      revocation status of a received certificate chain. These flags are
'//      ignored if none of the above flags are set.
'//
'// SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE
'//      This flag instructs schannel to pass CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL
'//      flags to CertGetCertificateChain when validating the specified
'//      credentials during a call to AcquireCredentialsHandle. The default for
'//      vista is to not specify CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL. Use
'//      SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE to override this behavior.
'//      NOTE: Prior to Vista, this flag(CERT_CHAIN_CACHE_ONLY_URL_RETRIEVAL) was
'//      specified by default.
'//
'//  SCH_SEND_ROOT_CERT
'//      This flag instructs schannel to send the root cert as part of the
'//      certificate message.
'//+-------------------------------------------------------------------------
%SCH_CRED_NO_SYSTEM_MAPPER                    = &H00000002???
%SCH_CRED_NO_SERVERNAME_CHECK                 = &H00000004???
%SCH_CRED_MANUAL_CRED_VALIDATION              = &H00000008???
%SCH_CRED_NO_DEFAULT_CREDS                    = &H00000010???
%SCH_CRED_AUTO_CRED_VALIDATION                = &H00000020???
%SCH_CRED_USE_DEFAULT_CREDS                   = &H00000040???
%SCH_CRED_DISABLE_RECONNECTS                  = &H00000080???

%SCH_CRED_REVOCATION_CHECK_END_CERT           = &H00000100???
%SCH_CRED_REVOCATION_CHECK_CHAIN              = &H00000200???
%SCH_CRED_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT = &H00000400???
%SCH_CRED_IGNORE_NO_REVOCATION_CHECK          = &H00000800???
%SCH_CRED_IGNORE_REVOCATION_OFFLINE           = &H00001000???

%SCH_CRED_RESTRICTED_ROOTS                    = &H00002000???
%SCH_CRED_REVOCATION_CHECK_CACHE_ONLY         = &H00004000???
%SCH_CRED_CACHE_ONLY_URL_RETRIEVAL            = &H00008000???

%SCH_CRED_MEMORY_STORE_CERT                   = &H00010000???

%SCH_CRED_CACHE_ONLY_URL_RETRIEVAL_ON_CREATE  = &H00020000???

%SCH_SEND_ROOT_CERT                           = &H00040000???

'//
'//
'// ApplyControlToken PkgParams types
'//
'// These identifiers are the DWORD types
'// to be passed into ApplyControlToken
'// through a PkgParams buffer.

%SCHANNEL_RENEGOTIATE   = 0   ' // renegotiate a connection
%SCHANNEL_SHUTDOWN      = 1   ' // gracefully close down a connection
%SCHANNEL_ALERT         = 2   ' // build an error message
%SCHANNEL_SESSION       = 3   ' // session control


'// Alert token structure.
' // Size = 12 bytes
TYPE SCHANNEL_ALERT_TOKEN DWORD
   dwTokenType   AS DWORD   ' DWORD // SCHANNEL_ALERT
   dwAlertType   AS DWORD   ' DWORD
   dwAlertNumber AS DWORD   ' DWORD
END TYPE

'// Alert types.
%TLS1_ALERT_WARNING              = 1
%TLS1_ALERT_FATAL                = 2

'' // Alert messages.
%TLS1_ALERT_CLOSE_NOTIFY         = 0       ' // warning
%TLS1_ALERT_UNEXPECTED_MESSAGE   = 10      ' // error
%TLS1_ALERT_BAD_RECORD_MAC       = 20      ' // error
%TLS1_ALERT_DECRYPTION_FAILED    = 21      ' // reserved
%TLS1_ALERT_RECORD_OVERFLOW      = 22      ' // error
%TLS1_ALERT_DECOMPRESSION_FAIL   = 30      ' // error
%TLS1_ALERT_HANDSHAKE_FAILURE    = 40      ' // error
%TLS1_ALERT_BAD_CERTIFICATE      = 42      ' // warning or error
%TLS1_ALERT_UNSUPPORTED_CERT     = 43      ' // warning or error
%TLS1_ALERT_CERTIFICATE_REVOKED  = 44      ' // warning or error
%TLS1_ALERT_CERTIFICATE_EXPIRED  = 45      ' // warning or error
%TLS1_ALERT_CERTIFICATE_UNKNOWN  = 46      ' // warning or error
%TLS1_ALERT_ILLEGAL_PARAMETER    = 47      ' // error
%TLS1_ALERT_UNKNOWN_CA           = 48      ' // error
%TLS1_ALERT_ACCESS_DENIED        = 49      ' // error
%TLS1_ALERT_DECODE_ERROR         = 50      ' // error
%TLS1_ALERT_DECRYPT_ERROR        = 51      ' // error
%TLS1_ALERT_EXPORT_RESTRICTION   = 60      ' // reserved
%TLS1_ALERT_PROTOCOL_VERSION     = 70      ' // error
%TLS1_ALERT_INSUFFIENT_SECURITY  = 71      ' // error
%TLS1_ALERT_INTERNAL_ERROR       = 80      ' // error
%TLS1_ALERT_USER_CANCELED        = 90      ' // warning or error
%TLS1_ALERT_NO_RENEGOTIATION     = 100     ' // warning
%TLS1_ALERT_UNSUPPORTED_EXT      = 110     ' // error


' // Session control flags
%SSL_SESSION_ENABLE_RECONNECTS  = 1
%SSL_SESSION_DISABLE_RECONNECTS = 2

'// Session control token structure.
' // Size = 8 bytes
TYPE SCHANNEL_SESSION_TOKEN DWORD
   dwTokenType AS DWORD   ' DWORD // SCHANNEL_SESSION
   dwFlags     AS DWORD   ' DWORD
END TYPE

' // Size = 68 bytes
TYPE SCHANNEL_CLIENT_SIGNATURE DWORD
   cbLength           AS DWORD   ' DWORD
   aiHash             AS DWORD   ' ALG_ID
   cbHash             AS DWORD   ' DWORD
   HashValue(35)      AS BYTE    ' BYTE[36]
   CertThumbprint(19) AS BYTE    ' BYTE[20]
END TYPE

'//
'// Flags for identifying the various different protocols.
'//

'/* flag/identifiers for protocols we support */
%SP_PROT_PCT1_SERVER             = &H00000001???
%SP_PROT_PCT1_CLIENT             = &H00000002???
%SP_PROT_PCT1                    = %SP_PROT_PCT1_SERVER OR %SP_PROT_PCT1_CLIENT

%SP_PROT_SSL2_SERVER             = &H00000004???
%SP_PROT_SSL2_CLIENT             = &H00000008???
%SP_PROT_SSL2                    = %SP_PROT_SSL2_SERVER OR %SP_PROT_SSL2_CLIENT

%SP_PROT_SSL3_SERVER             = &H00000010???
%SP_PROT_SSL3_CLIENT             = &H00000020???
%SP_PROT_SSL3                    = %SP_PROT_SSL3_SERVER OR %SP_PROT_SSL3_CLIENT

%SP_PROT_TLS1_SERVER             = &H00000040???
%SP_PROT_TLS1_CLIENT             = &H00000080???
%SP_PROT_TLS1                    = %SP_PROT_TLS1_SERVER OR %SP_PROT_TLS1_CLIENT

%SP_PROT_SSL3TLS1_CLIENTS        = %SP_PROT_TLS1_CLIENT OR %SP_PROT_SSL3_CLIENT
%SP_PROT_SSL3TLS1_SERVERS        = %SP_PROT_TLS1_SERVER OR %SP_PROT_SSL3_SERVER
%SP_PROT_SSL3TLS1                = %SP_PROT_SSL3 OR %SP_PROT_TLS1

%SP_PROT_UNI_SERVER              = &H40000000???
%SP_PROT_UNI_CLIENT              = &H80000000???
%SP_PROT_UNI                     = %SP_PROT_UNI_SERVER OR %SP_PROT_UNI_CLIENT

%SP_PROT_ALL                     = &Hffffffff???
%SP_PROT_NONE                    = 0???
%SP_PROT_CLIENTS                 = %SP_PROT_PCT1_CLIENT OR %SP_PROT_SSL2_CLIENT OR %SP_PROT_SSL3_CLIENT OR %SP_PROT_UNI_CLIENT OR %SP_PROT_TLS1_CLIENT
%SP_PROT_SERVERS                 = %SP_PROT_PCT1_SERVER OR %SP_PROT_SSL2_SERVER OR %SP_PROT_SSL3_SERVER OR %SP_PROT_UNI_SERVER OR %SP_PROT_TLS1_SERVER

%SP_PROT_TLS1_0_SERVER           = %SP_PROT_TLS1_SERVER
%SP_PROT_TLS1_0_CLIENT           = %SP_PROT_TLS1_CLIENT
%SP_PROT_TLS1_0                  = %SP_PROT_TLS1_0_SERVER OR %SP_PROT_TLS1_0_CLIENT

%SP_PROT_TLS1_1_SERVER           = &H00000100???
%SP_PROT_TLS1_1_CLIENT           = &H00000200???
%SP_PROT_TLS1_1                  = %SP_PROT_TLS1_1_SERVER OR %SP_PROT_TLS1_1_CLIENT

%SP_PROT_TLS1_2_SERVER           = &H00000400???
%SP_PROT_TLS1_2_CLIENT           = &H00000800???
%SP_PROT_TLS1_2                  = %SP_PROT_TLS1_2_SERVER OR %SP_PROT_TLS1_2_CLIENT

%SP_PROT_TLS1_1PLUS_SERVER       = %SP_PROT_TLS1_1_SERVER OR %SP_PROT_TLS1_2_SERVER
%SP_PROT_TLS1_1PLUS_CLIENT       = %SP_PROT_TLS1_1_CLIENT OR %SP_PROT_TLS1_2_CLIENT
%SP_PROT_TLS1_1PLUS              = %SP_PROT_TLS1_1PLUS_SERVER OR %SP_PROT_TLS1_1PLUS_CLIENT

%SP_PROT_TLS1_X_SERVER           = %SP_PROT_TLS1_0_SERVER OR %SP_PROT_TLS1_1_SERVER OR %SP_PROT_TLS1_2_SERVER
%SP_PROT_TLS1_X_CLIENT           = %SP_PROT_TLS1_0_CLIENT OR %SP_PROT_TLS1_1_CLIENT OR %SP_PROT_TLS1_2_CLIENT
%SP_PROT_TLS1_X                  = %SP_PROT_TLS1_X_SERVER OR %SP_PROT_TLS1_X_CLIENT

%SP_PROT_SSL3TLS1_X_CLIENTS      = %SP_PROT_TLS1_X_CLIENT OR %SP_PROT_SSL3_CLIENT
%SP_PROT_SSL3TLS1_X_SERVERS      = %SP_PROT_TLS1_X_SERVER OR %SP_PROT_SSL3_SERVER
%SP_PROT_SSL3TLS1_X              = %SP_PROT_SSL3 OR %SP_PROT_TLS1_X

%SP_PROT_X_CLIENTS               = %SP_PROT_CLIENTS OR %SP_PROT_TLS1_X_CLIENT
%SP_PROT_X_SERVERS               = %SP_PROT_SERVERS OR %SP_PROT_TLS1_X_SERVER


'//
'// Helper function used to flush the SSL session cache.
'//

DECLARE FUNCTION SslEmptyCache IMPORT "SCHANNEL.DLL" ALIAS "SslEmptyCacheA" ( _
   BYREF pszTargetName AS ASCIIZ _                      ' __in LPSTR  pszTargetName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SslEmptyCacheW IMPORT "SCHANNEL.DLL" ALIAS "SslEmptyCacheW" ( _
   BYREF pszTargetName AS WSTRINGZ _                    ' __in LPWSTR pszTargetName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 ) AS LONG                                              ' BOOL


'// Structures for compatability with the
'// NT 4.0 SP2 / IE 3.0 schannel interface, do
'// not use.

' // Size = 20 bytes
TYPE SSL_CREDENTIAL_CERTIFICATE DWORD
   cbPrivateKey  AS DWORD        ' DWORD
   pPrivateKey   AS BYTE PTR     ' PBYTE
   cbCertificate AS DWORD        ' DWORD
   pCertificate  AS BYTE PTR     ' PBYTE
   pszPassword   AS ASCIIZ PTR   ' PSTR
END TYPE


'// Structures for use with the
'// NT 4.0 SP3 Schannel interface,
'// do not use.
%SCHANNEL_SECRET_TYPE_CAPI   = &H00000001???
%SCHANNEL_SECRET_PRIVKEY     = &H00000002???
%SCH_CRED_X509_CERTCHAIN     = &H00000001???
%SCH_CRED_X509_CAPI          = &H00000002???
%SCH_CRED_CERT_CONTEXT       = &H00000003???

'struct _HMAPPER;

' // Size = 24 bytes
TYPE SCH_CRED DWORD
   dwVersion  AS DWORD   ' DWORD // always SCH_CRED_VERSION.
   cCreds     AS DWORD   ' DWORD // Number of credentials.
   paSecret   AS DWORD   ' PVOID * // Array of SCH_CRED_SECRET_* pointers
   paPublic   AS DWORD   ' PVOID * // Array of SCH_CRED_PUBLIC_* pointers
   cMappers   AS DWORD   ' DWORD // Number of credential mappers.
   aphMappers AS DWORD   ' struct _HMAPPER ** // pointer to an array of pointers to credential mappers
END TYPE

'// Structures for use with the
'// NT 4.0 SP3 Schannel interface,
'// do not use.
' // Size = 8 bytes
TYPE SCH_CRED_SECRET_CAPI DWORD
   dwType AS DWORD   ' DWORD // SCHANNEL_SECRET_TYPE_CAPI
   hProv  AS DWORD   ' HCRYPTPROV // credential secret information.
END TYPE


'// Structures for use with the
'// NT 4.0 SP3 Schannel interface,
'// do not use.
' // Size = 16 bytes
TYPE SCH_CRED_SECRET_PRIVKEY DWORD
   dwType       AS DWORD        ' DWORD // SCHANNEL_SECRET_PRIVKEY
   pPrivateKey  AS BYTE PTR     ' PBYTE // Der encoded private key
   cbPrivateKey AS DWORD        ' DWORD
   pszPassword  AS ASCIIZ PTR   ' PSTR  // Password to crack the private key.
END TYPE


'// Structures for use with the
'// NT 4.0 SP3 Schannel interface,
'// do not use.
' // Size = 12 bytes
TYPE SCH_CRED_PUBLIC_CERTCHAIN DWORD
   dwType      AS DWORD      ' DWORD
   cbCertChain AS DWORD      ' DWORD
   pCertChain  AS BYTE PTR   ' PBYTE
END TYPE


'// Structures needed for Pre NT4.0 SP2 calls.
' // Size = 12 bytes
TYPE PctPublicKey DWORD
   Type    AS DWORD   ' DWORD
   cbKey   AS DWORD   ' DWORD
   pKey(0) AS BYTE    ' UCHAR
END TYPE

' // Size = 52 bytes
TYPE X509Certificate DWORD
   Version            AS DWORD              ' DWORD
   SerialNumber(3)    AS DWORD              ' DWORD[4]
   SignatureAlgorithm AS DWORD              ' ALG_ID
   ValidFrom          AS FILETIME           ' FILETIME
   ValidUntil         AS FILETIME           ' FILETIME
   pszIssuer          AS ASCIIZ PTR         ' PSTR
   pszSubject         AS ASCIIZ PTR         ' PSTR
   pPublicKey         AS PctPublicKey PTR   ' PctPublicKey *
END TYPE


'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.

DECLARE FUNCTION SslGenerateKeyPair IMPORT "SCHANNEL.DLL" ALIAS "SslGenerateKeyPair" ( _
   BYREF pCerts AS SSL_CREDENTIAL_CERTIFICATE _         ' PSSL_CREDENTIAL_CERTIFICATE pCerts
 , BYREF pszDN AS ASCIIZ _                              ' __in PSTR pszDN
 , BYREF pszPassword AS ASCIIZ _                        ' __in PSTR pszPassword
 , BYVAL Bits AS DWORD _                                ' __in DWORD Bits
 ) AS LONG                                              ' BOOL

'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.

DECLARE SUB SslGenerateRandomBits IMPORT "SCHANNEL.DLL" ALIAS "SslGenerateRandomBits" ( _
   BYVAL pRandomData AS BYTE PTR _                      ' PUCHAR      pRandomData
 , BYVAL cRandomData AS LONG _                          ' LONG        cRandomData
 )                                                      ' VOID

'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.

DECLARE FUNCTION SslCrackCertificate IMPORT "SCHANNEL.DLL" ALIAS "SslCrackCertificate" ( _
   BYVAL pbCertificate AS BYTE PTR _                    ' PUCHAR              pbCertificate
 , BYVAL cbCertificate AS DWORD _                       ' DWORD               cbCertificate
 , BYVAL dwFlags AS DWORD _                             ' DWORD               dwFlags
 , BYREF ppCertificate AS ANY _                         ' PX509Certificate *  ppCertificate
 ) AS LONG                                              ' BOOL

'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.

DECLARE SUB SslFreeCertificate IMPORT "SCHANNEL.DLL" ALIAS "SslFreeCertificate" ( _
   BYREF pCertificate AS X509Certificate _              ' PX509Certificate    pCertificate
 )                                                      ' VOID

DECLARE FUNCTION SslGetMaximumKeySize IMPORT "SCHANNEL.DLL" ALIAS "SslGetMaximumKeySize" ( _
   BYVAL Reserved AS DWORD _                            ' DWORD   Reserved
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SslGetDefaultIssuers IMPORT "SCHANNEL.DLL" ALIAS "SslGetDefaultIssuers" ( _
   BYVAL pbIssuers AS BYTE PTR _                        ' PBYTE pbIssuers
 , BYREF pcbIssuers AS DWORD _                          ' DWORD *pcbIssuers
 ) AS LONG                                              ' BOOL

$SSL_CRACK_CERTIFICATE_NAME = "SslCrackCertificate"
$SSL_FREE_CERTIFICATE_NAME  = "SslFreeCertificate"

' Note: Use the CertCreateCertificateContext function instead.
'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.
'typedef BOOL
'(WINAPI * SSL_CRACK_CERTIFICATE_FN)
'(
'    PUCHAR              pbCertificate,
'    DWORD               cbCertificate,
'    BOOL                VerifySignature,
'    PX509Certificate *  ppCertificate
');


' Note: Use the CertFreeCertificateContext function instead.
'// Pre NT4.0 SP2 calls.  Call CAPI1 or CAPI2
'// to get the same functionality instead.
'typedef VOID
'(WINAPI * SSL_FREE_CERTIFICATE_FN)
'(
'    PX509Certificate    pCertificate
');
