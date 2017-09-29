' ########################################################################################
' Microsoft Windows
' File: WinTrust.inc
' Contents: Microsoft Internet Security Trust Provider Model
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINTRUST_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "mssip.inc"

'#ifndef WIN_CERT_REVISION_1_0   // there were duplicate definitions in winbase.h
'#   define  WT_DEFINE_ALL_APIS
'#else
'#   undef   WT_DEFINE_ALL_APIS
'#endif

'#include <pshpack8.h>

'//////////////////////////////////////////////////////////////////////////////
'//
'// Wintrust Registry Configuration Definitions.
'//
'//////////////////////////////////////////////////////////////////////////////

$$WINTRUST_CONFIG_REGPATH = "Software\Microsoft\Cryptography\Wintrust\Config"$$

'// The following are REG_DWORD's. These configuration parameters are used
'// to limit the number of file bytes mapped at a time. Should be a multiple of
'// dwAllocationGranularity returned by GetSystemInfo(). This allows
'// very large files, > 2Gig bytes, to be authenticated signed and verified
'// using a much smaller virtual memory address range.

'// The length of the header bytes for a PE, CAB or any file that is
'// authenticode signed must be less than the following value.
$$WINTRUST_MAX_HEADER_BYTES_TO_MAP_VALUE_NAME    = "MaxHeaderBytesToMap"$$
'// 0x00A0'0000 (10,485,760) Bytes
%WINTRUST_MAX_HEADER_BYTES_TO_MAP_DEFAULT        = &H00A00000???

'// If the file size doesn't fit within the above header length, the following
'// value is used to set the maximum number of remaining file bytes that are
'// mapped/hashed/unmapped at time.
$$WINTRUST_MAX_HASH_BYTES_TO_MAP_VALUE_NAME      = "MaxHashBytesToMap"$$
'// 0x0010'0000 (1,048,576) Bytes
%WINTRUST_MAX_HASH_BYTES_TO_MAP_DEFAULT          = &H00100000???


'//////////////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////
'//
'//      Client definitions, typedefs, and prototypes
'//
'//////////////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_FILE_INFO Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust against an individual file.
'//

' // Size = 16 bytes
TYPE WINTRUST_FILE_INFO DWORD
   cbStruct       AS DWORD          ' DWORD   // = sizeof(WINTRUST_FILE_INFO)
   pcwszFilePath  AS WSTRINGZ PTR   ' LPCWSTR // required, file name to be verified
   hFile          AS DWORD          ' HANDLE  // optional, open handle to pcwszFilePath
   pgKnownSubject AS GUID PTR       ' GUID *  // optional: fill if the subject type is known.
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_CATALOG_INFO Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust against a member of a Microsoft Catalog
'//  file.
'//
' // Size = 36 bytes
TYPE WINTRUST_CATALOG_INFO DWORD
   cbStruct             AS DWORD             ' DWORD
   dwCatalogVersion     AS DWORD             ' DWORD
   pcwszCatalogFilePath AS WSTRINGZ PTR      ' LPCWSTR
   pcwszMemberTag       AS WSTRINGZ PTR      ' LPCWSTR
   pcwszMemberFilePath  AS WSTRINGZ PTR      ' LPCWSTR
   hMemberFile          AS DWORD             ' HANDLE
   pbCalculatedFileHash AS BYTE PTR          ' BYTE *
   cbCalculatedFileHash AS DWORD             ' DWORD
   pcCatalogContext     AS CTL_CONTEXT PTR   ' PCCTL_CONTEXT
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_BLOB_INFO Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust against a memory blob.
'//

' // Size = 40 bytes
TYPE WINTRUST_BLOB_INFO DWORD
   cbStruct         AS DWORD          ' DWORD   // = sizeof(WINTRUST_BLOB_INFO)
   gSubject         AS GUID           ' GUID    // SIP to load
   pcwszDisplayName AS WSTRINGZ PTR   ' LPCWSTR // display name of object
   cbMemObject      AS DWORD          ' DWORD
   pbMemObject      AS BYTE PTR       ' BYTE *
   cbMemSignedMsg   AS DWORD          ' DWORD
   pbMemSignedMsg   AS BYTE PTR       ' BYTE *
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_SGNR_INFO Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust against a CMSG_SIGNER_INFO Structure
'//

' // Size = 20 bytes
TYPE WINTRUST_SGNR_INFO DWORD
   cbStruct         AS DWORD                  ' DWORD
   pcwszDisplayName AS WSTRINGZ PTR           ' LPCWSTR
   psSignerInfo     AS CMSG_SIGNER_INFO PTR   ' CMSG_SIGNER_INFO *
   chStores         AS DWORD                  ' DWORD
   pahStores        AS DWORD PTR              ' HCERTSTORE *
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_CERT_INFO Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust against a CERT_CONTEXT Structure
'//

%WTCI_DONT_OPEN_STORES   = &H00000001   ' // only open dummy "root" all other are in pahStores.
%WTCI_OPEN_ONLY_ROOT     = &H00000002
%WTCI_USE_LOCAL_MACHINE  = &H00000004   ' // Local machine context

' // Size = 28 bytes
TYPE WINTRUST_CERT_INFO DWORD
   cbStruct         AS DWORD             ' DWORD
   pcwszDisplayName AS WSTRINGZ PTR      ' LPCWSTR
   psCertContext    AS CERT_CONTEXT PTR  ' CERT_CONTEXT
   chStores         AS DWORD             ' DWPRD
   pahStores        AS DWORD PTR         ' HCERTSTORE
   dwFlags          AS DWORD             ' DWORD
   psftVerifyAsOf   AS FILETIME PTR      ' FILETIME *
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST_DATA Structure
'//----------------------------------------------------------------------------
'//  Used when calling WinVerifyTrust to pass necessary information into
'//  the Providers.
'//

%WTD_UI_ALL                               = 1???
%WTD_UI_NONE                              = 2???
%WTD_UI_NOBAD                             = 3???
%WTD_UI_NOGOOD                            = 4???

%WTD_REVOKE_NONE                          = &H00000000???
%WTD_REVOKE_WHOLECHAIN                    = &H00000001???

%WTD_CHOICE_FILE                          = 1???
%WTD_CHOICE_CATALOG                       = 2???
%WTD_CHOICE_BLOB                          = 3???
%WTD_CHOICE_SIGNER                        = 4???
%WTD_CHOICE_CERT                          = 5???

%WTD_STATEACTION_IGNORE                   = &H00000000???
%WTD_STATEACTION_VERIFY                   = &H00000001???
%WTD_STATEACTION_CLOSE                    = &H00000002???
%WTD_STATEACTION_AUTO_CACHE               = &H00000003???
%WTD_STATEACTION_AUTO_CACHE_FLUSH         = &H00000004???

%WTD_PROV_FLAGS_MASK                      = &H0000FFFF???
%WTD_USE_IE4_TRUST_FLAG                   = &H00000001???
%WTD_NO_IE4_CHAIN_FLAG                    = &H00000002???
%WTD_NO_POLICY_USAGE_FLAG                 = &H00000004???
%WTD_REVOCATION_CHECK_NONE                = &H00000010???
%WTD_REVOCATION_CHECK_END_CERT            = &H00000020???
%WTD_REVOCATION_CHECK_CHAIN               = &H00000040???
%WTD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT  = &H00000080???
%WTD_SAFER_FLAG                           = &H00000100???
%WTD_HASH_ONLY_FLAG                       = &H00000200???
%WTD_USE_DEFAULT_OSVER_CHECK              = &H00000400???
%WTD_LIFETIME_SIGNING_FLAG                = &H00000800???
%WTD_CACHE_ONLY_URL_RETRIEVAL             = &H00001000???   ' // affects CRL retrieval and AIA retrieval

%WTD_UICONTEXT_EXECUTE                    = 0???
%WTD_UICONTEXT_INSTALL                    = 1???

' // Size = 4 bytes
UNION WINTRUST_DATA_UNION DWORD
   pFile    AS WINTRUST_FILE_INFO PTR      ' struct WINTRUST_FILE_INFO_ *
   pCatalog AS WINTRUST_CATALOG_INFO PTR   ' struct WINTRUST_CATALOG_INFO_ *
   pBlob    AS WINTRUST_BLOB_INFO PTR      ' struct WINTRUST_BLOB_INFO_ *
   pSgnr    AS WINTRUST_SGNR_INFO PTR      ' struct WINTRUST_SGNR_INFO_ *
   pCert    AS WINTRUST_CERT_INFO PTR     ' struct WINTRUST_CERT_INFO_ *
END UNION

' // Size = 48 bytes
TYPE WINTRUST_DATA DWORD
   cbStruct            AS DWORD          ' DWORD
   pPolicyCallbackData AS DWORD          ' LPVOID
   pSIPClientData      AS DWORD          ' LPVOID
   dwUIChoice          AS DWORD          ' DWORD
   fdwRevocationChecks AS DWORD          ' DWORD
   dwUnionChoice       AS DWORD          ' DWORD
   WINTRUST_DATA_UNION
   dwStateAction       AS DWORD          ' DWORD
   hWVTStateData       AS DWORD          ' HANDLE
   pwszURLReference    AS WSTRINGZ PTR   ' WCHAR *
   dwProvFlags         AS DWORD          ' DWORD
   dwUIContext         AS DWORD          ' DWORD
END TYPE

'#include <poppack.h>

'//////////////////////////////////////////////////////////////////////////////
'//
'// WinVerifyTrust
'//----------------------------------------------------------------------------
'//  Exported from WINTRUST.DLL.
'//  Call this function to verify the trust based on a digital signer.
'//
'//  pWVTData points to a WINTRUST_DATA data structure.
'//
'//  WTD_SAFER_FLAG should be set in WINTRUST_DATA's dwProvFlags to enable
'//  the following semantics for the WINTRUST_ACTION_GENERIC_VERIFY_V2
'//  policy provider specified in pgActionID:
'//   - return TRUST_E_NOSIGNATURE if the subject isn't signed, has an
'//     invalid signature or unable to find the signer certificate.
'//     UI will never be displayed when not signed.
'//   - ignore NO_CHECK revocation errors. Otherwise, continue to return
'//     CERT_E_REVOCATION_FAILURE.
'//   - search the code hash and publisher databases for the WTD_UI_NONE
'//     dwUIChoice case. The default is to only search these databases when
'//     UI has been enabled or user trust has been disabled.
'//
'//
'//  Returns:
'//          ERROR_SUCCESS               If the trust is authenticated or
'//                                      if the user accepted the risk.
'//
'//          TRUST_E_PROVIDER_UNKNOWN    there was an error loading one of the
'//                                      required Providers.
'//
'//          all error codes passed back are based on the Policy Provider used.
'//
'//  The following errors are returned when the
'//  WINTRUST_ACTION_GENERIC_VERIFY_V2 policy provider is specified in
'//  pgActionID:
'//
'//    TRUST_E_NOSIGNATURE (when WTD_SAFER_FLAG is set in dwProvFlags)
'//      The subject isn't signed, has an invalid signature or unable
'//      to find the signer certificate. All signature verification
'//      errors will map to this error. Basically all errors except for
'//      publisher or timestamp certificate verification.
'//
'//      Call GetLastError() to get the underlying reason for not having
'//      a valid signature.
'//
'//      The following LastErrors indicate that the file doesn't have a
'//      signature: TRUST_E_NOSIGNATURE, TRUST_E_SUBJECT_FORM_UNKNOWN or
'//      TRUST_E_PROVIDER_UNKNOWN.
'//
'//      UI will never be displayed for this case.
'//
'//    TRUST_E_EXPLICIT_DISTRUST
'//      Returned if the hash representing the subject is trusted as
'//      AUTHZLEVELID_DISALLOWED or the publisher is in the "Disallowed"
'//      store. Also returned if the publisher certificate is revoked.
'//
'//      UI will never be displayed for this case.
'//
'//    ERROR_SUCCESS
'//      No UI unless noted below.
'//
'//      Returned for the following:
'//       - Hash representing the subject is trusted as
'//         AUTHZLEVELID_FULLYTRUSTED
'//       - The publisher certificate exists in the
'//         "TrustedPublisher" store and there weren't any verification errors.
'//       - UI was enabled and the user clicked "Yes" when asked
'//         to install and run the signed subject.
'//       - UI was disabled. No publisher or timestamp chain error.
'//
'//    TRUST_E_SUBJECT_NOT_TRUSTED
'//      UI was enabled and the the user clicked "No" when asked to install
'//      and run the signed subject.
'//
'//    CRYPT_E_SECURITY_SETTINGS
'//      The subject hash or publisher wasn't explicitly trusted and
'//      user trust wasn't allowed in the safer authenticode flags.
'//      No UI will be displayed for this case.
'//
'//      The subject is signed and its signature successfully
'//      verified.
'//
'//    Any publisher or timestamp chain error. If WTD_SAFER_FLAG wasn't set in
'//    dwProvFlags, any signed code verification error.
'//

DECLARE FUNCTION WinVerifyTrust IMPORT "WINTRUST.DLL" ALIAs "WinVerifyTrust" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND    hwnd
 , BYREF pgActionID AS GUID _                           ' __in GUID   *pgActionID
 , BYREF pWVTData AS ANY _                              ' __in LPVOID  pWVTData
 ) AS LONG                                              ' LONG


'//////////////////////////////////////////////////////////////////////////////
'//
'// WinVerifyTrustEx
'//----------------------------------------------------------------------------
'//      *** DO NOT USE ***
'//
'//

DECLARE FUNCTION WinVerifyTrustEx IMPORT "WINTRUST.DLL" ALIAs "WinVerifyTrustEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND           hwnd
 , BYREF pgActionID AS GUID _                           ' __in GUID          *pgActionID
 , BYREF pWinTrustData AS ANY _                         ' __in WINTRUST_DATA *pWinTrustData
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////
'//
'//      Trust, Policy, and UI Provider definitions, typedefs, and prototypes
'//
'//  Model:
'//      A client wishing to validate trust through WinVerifyTrust will
'//      select an appropriate Action ID guid for the call.
'//      This guid is defined by each Policy Provider and represents the
'//      functions called based on the policy for the given object.
'//
'//      In this model, the Policy Provider determines which style of UI
'//      will be shown to the user (this only applies to style, the
'//      determination of whether UI is displayed is set by the calling client
'//      in the UI flags member of WINTRUST_DATA).
'//
'//      Since the function entry points are common (same return value and
'//      parameters), it allows Policy Provider developers to take advantage
'//      of existing, generic, code to fill the CRYPT_PROVIDER_DATA structure.
'//
'//      This also allows the developer to simply add the specific policy they
'//      need, then, call the generic Policy Provider - if appropriate.
'//
'//////////////////////////////////////////////////////////////////////////////
'//////////////////////////////////////////////////////////////////////////////


'//////////////////////////////////////////////////////////////////////////////
'//
'// Wintrust Policy Flags
'//----------------------------------------------------------------------------
'//  These are set during install and can be modified by the user
'//  through various means.  The SETREG.EXE utility (found in the Authenticode
'//  Tools Pack) will select/deselect each of them.
'//
%WTPF_TRUSTTEST              = &H00000020???  ' // trust any "TEST" certificate
%WTPF_TESTCANBEVALID         = &H00000080???
%WTPF_IGNOREEXPIRATION       = &H00000100???  ' // Use expiration date
%WTPF_IGNOREREVOKATION       = &H00000200???  ' // Do revocation check
%WTPF_OFFLINEOK_IND          = &H00000400???  ' // off-line is ok individual certs
%WTPF_OFFLINEOK_COM          = &H00000800???  ' // off-line is ok commercial certs
%WTPF_OFFLINEOKNBU_IND       = &H00001000???  ' // off-line is ok individual certs, no bad ui
%WTPF_OFFLINEOKNBU_COM       = &H00002000???  ' // off-line is ok commercial certs, no bad ui
%WTPF_VERIFY_V1_OFF          = &H00010000???  ' // turn verify of v1 certs off
%WTPF_IGNOREREVOCATIONONTS   = &H00020000???  ' // ignore TimeStamp revocation checks
%WTPF_ALLOWONLYPERTRUST      = &H00040000???  ' // allow only items in personal trust db.

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustGetRegPolicyFlags
'//----------------------------------------------------------------------------
'//  This API call is exported from WINTRUST.DLL and is the recommended method
'//  of retrieving the DWORD representing the Policy Flags.
'//

DECLARE SUB WintrustGetRegPolicyFlags IMPORT "WINTRUST.DLL" ALIAs "WintrustGetRegPolicyFlags" ( _
   BYREF pdwPolicyFlags AS DWORD _                      ' __in DWORD *pdwPolicyFlags
 )                                                      ' void

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustSetRegPolicyFlags
'//----------------------------------------------------------------------------
'//  This API call is exported from WINTRUST.DLL and is the recommended method
'//  of setting the DWORD representing the Policy Flags.  MAKE SURE to call
'//  WintrustGetRegPolicyFlags to get the current value and or/and the value
'//  you need then call the set the flags.
'//

DECLARE FUNCTION WintrustSetRegPolicyFlags IMPORT "WINTRUST.DLL" ALIAs "WintrustSetRegPolicyFlags" ( _
   BYVAL dwPolicyFlags AS DWORD _                       ' __in DWORD dwPolicyFlags
 ) AS LONG                                              ' BOOL


'//////////////////////////////////////////////////////////////////////////////
'//
'// Trust Provider "Step" Error defines
'//----------------------------------------------------------------------------
'//  Each "step" of the Trust process has an error "slot" associated with it.
'//  If an error occurs, the "step" will assign its result to this "slot".  These
'//  errors can be any valid WINERROR.H HRESULT code.
'//

'    //
'    //  step errors 0 through 20 are reserved for Authenticode specific.  If
'    //  you are not calling any of the SOFTPUB.DLL (Authenticode) providers, you
'    //  may use these as needed.
'    //
%TRUSTERROR_STEP_WVTPARAMS                   = 0
%TRUSTERROR_STEP_FILEIO                      = 2
%TRUSTERROR_STEP_SIP                         = 3
%TRUSTERROR_STEP_SIPSUBJINFO                 = 5
%TRUSTERROR_STEP_CATALOGFILE                 = 6
%TRUSTERROR_STEP_CERTSTORE                   = 7
%TRUSTERROR_STEP_MESSAGE                     = 8
%TRUSTERROR_STEP_MSG_SIGNERCOUNT             = 9
%TRUSTERROR_STEP_MSG_INNERCNTTYPE            = 10
%TRUSTERROR_STEP_MSG_INNERCNT                = 11
%TRUSTERROR_STEP_MSG_STORE                   = 12
%TRUSTERROR_STEP_MSG_SIGNERINFO              = 13
%TRUSTERROR_STEP_MSG_SIGNERCERT              = 14
%TRUSTERROR_STEP_MSG_CERTCHAIN               = 15
%TRUSTERROR_STEP_MSG_COUNTERSIGINFO          = 16
%TRUSTERROR_STEP_MSG_COUNTERSIGCERT          = 17
%TRUSTERROR_STEP_VERIFY_MSGHASH              = 18
%TRUSTERROR_STEP_VERIFY_MSGINDIRECTDATA      = 19

'    //
'    //  step errors 30 through 37 are reserved for the ending error code for each
'    //  entry point in the Trust Model.
'    //
%TRUSTERROR_STEP_FINAL_WVTINIT               = 30
%TRUSTERROR_STEP_FINAL_INITPROV              = 31
%TRUSTERROR_STEP_FINAL_OBJPROV               = 32
%TRUSTERROR_STEP_FINAL_SIGPROV               = 33
%TRUSTERROR_STEP_FINAL_CERTPROV              = 34
%TRUSTERROR_STEP_FINAL_CERTCHKPROV           = 35
%TRUSTERROR_STEP_FINAL_POLICYPROV            = 36
%TRUSTERROR_STEP_FINAL_UIPROV                = 37

%TRUSTERROR_MAX_STEPS                        = 38

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVIDER_PRIVDATA structure
'//----------------------------------------------------------------------------
'//  This structure is to allow Policy Provider functions to share
'//  POLICY SPECIFIC data between Policy Functions.
'//  The Policy must use the pfnAddPrivateData2Chain function and
'//  must free any data within the member before the Final Policy returns
'//  to WVT.
'//  To allow multiple providers to use this feature, each provider that
'//  uses this member must set the provider ID to it's Action ID so that
'//  the provider can find its data and ignore any other.
'//

'} CRYPT_PROVIDER_PRIVDATA, *PCRYPT_PROVIDER_PRIVDATA;

' // Size = 28 bytes
TYPE CRYPT_PROVIDER_PRIVDATA DWORD
   cbStruct    AS DWORD   ' DWORD
   gProviderID AS GUID    ' GUID
   cbProvData  AS DWORD   ' DWORD
   pvProvData  AS DWORD   ' void
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVIDER_CERT structure
'//----------------------------------------------------------------------------
'//  After the Signature and Certificate Providers are finished there will
'//  be zero to many of these filled out in the CRYPT_PROVIDER_SGNR
'//  structure.  One for each certificate in the chain.
'//
'//

%CERT_CONFIDENCE_SIG             = &H10000000???    ' // this cert
%CERT_CONFIDENCE_TIME            = &H01000000???    ' // issuer cert
%CERT_CONFIDENCE_TIMENEST        = &H00100000???    ' // this cert
%CERT_CONFIDENCE_AUTHIDEXT       = &H00010000???    ' // this cert
%CERT_CONFIDENCE_HYGIENE         = &H00001000???    ' // this cert
%CERT_CONFIDENCE_HIGHEST         = &H11111000???

' // Size = 60 bytes
TYPE CRYPT_PROVIDER_CERT DWORD
   cbStruct             AS DWORD                    ' DWORD
   pCert                AS CERT_CONTEXT PTR         ' PCCERT_CONTEXT
   fCommercial          AS LONG                     ' BOOL
   fTrustedRoot         AS LONG                     ' BOOL
   fSelfSigned          AS LONG                     ' BOOL
   fTestCert            AS LONG                     ' BOOL
   dwRevokedReason      AS DWORD                    ' DWORD
   dwConfidence         AS DWORD                    ' DWORD
   dwError              AS DWORD                    ' DWORD
   pTrustListContext    AS CTL_CONTEXT PTR          ' CTL_CONTEXT *
   fTrustListSignerCert AS LONG                     ' BOOL
   pCtlContext          AS CTL_CONTEXT PTR          ' PCCTL_CONTEXT
   dwCtlError           AS DWORD                    ' DWORD
   fIsCyclic            AS LONG                     ' BOOL
   pChainElement        AS CERT_CHAIN_ELEMENT PTR   ' PCERT_CHAIN_ELEMENT
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVIDER_SGNR structure
'//----------------------------------------------------------------------------
'//  After the Signature Provider is finished there will be zero to many of these
'//  filled out.  One for each signer of the message.  Also, there will be zero
'//  to many of these filled out inside this structure.  One for each counter
'//  signer of the signer.
'//
'//  IMPORTANT:  1.  All dynamically allocated members MUST use allocation
'//                  and Add2 functions provided.
'//

%SGNR_TYPE_TIMESTAMP     = &H00000010???

' // Size = 44 bytes
TYPE CRYPT_PROVIDER_SGNR DWORD
   cbStruct          AS DWORD                     ' DWORD
   sftVerifyAsOf     AS FILETIME                  ' FILETIME
   csCertChain       AS DWORD                     ' DWORD
   pasCertChain      AS CRYPT_PROVIDER_CERT PTR   ' struct _CRYPT_PROVIDER_CERT *
   dwSignerType      AS DWORD                     ' DWORD
   psSigner          AS CMSG_SIGNER_INFO PTR      ' CMSG_SIGNER_INFO *
   dwError           AS DWORD                     ' DWORD
   csCounterSigners  AS DWORD                     ' DWORD
   pasCounterSigners AS CRYPT_PROVIDER_SGNR PTR   ' struct _CRYPT_PROVIDER_SGNR *
   pChainContext     AS CERT_CHAIN_CONTEXT PTR    ' PCCERT_CHAIN_CONTEXT
END TYPE


'//////////////////////////////////////////////////////////////////////////////
'//
'//  allocation and free function prototypes
'//----------------------------------------------------------------------------
'//
'typedef void        *(*PFN_CPD_MEM_ALLOC)(__in DWORD cbSize);
'SUB CPD_MEM_ALLOC (BYVAL cbSize AS DWORD)

'typedef void        (*PFN_CPD_MEM_FREE)(__in void *pvMem2Free);
'SUB CPD_MEM_FREE (BYVAL pvMem2Free AS DWORD)

'struct _CRYPT_PROVIDER_DATA;
'struct _CRYPT_PROVIDER_SGNR;
'struct _CRYPT_PROVIDER_PRIVDATA;

'typedef BOOL        (*PFN_CPD_ADD_STORE)(__in struct _CRYPT_PROVIDER_DATA *pProvData,
'                                         __in HCERTSTORE hStore2Add);
'FUNCTION CPD_ADD_STORE (BYREF pProvData AS CRYPT_PROVIDER_DATA, _
'                        BYVAL hStore2Add AS DWORD) AS LONG

'typedef BOOL        (*PFN_CPD_ADD_SGNR)(__in          struct _CRYPT_PROVIDER_DATA *pProvData,
'                                        __in          BOOL fCounterSigner,
'                                        __in_opt      DWORD idxSigner,
'                                        __in          struct _CRYPT_PROVIDER_SGNR *pSgnr2Add);
'FUNCTION CPD_ADD_SGNR (BYREF pProvData AS CRYPT_PROVIDER_DATA, _
'                       BYVAL fCounterSigner AS LONG, _
'                       BYVAL idxSigner AS DWORD, _
'                       BYREF pSgnr2Add AS CRYPT_PROVIDER_SGNR) AS LONG

'typedef BOOL        (*PFN_CPD_ADD_CERT)(__in          struct _CRYPT_PROVIDER_DATA *pProvData,
'                                        __in          DWORD idxSigner,
'                                        __in          BOOL fCounterSigner,
'                                        __in_opt      DWORD idxCounterSigner,
'                                        __in          PCCERT_CONTEXT pCert2Add);

'FUNCTION CPD_ADD_CERT (BYREF pProvData AS CRYPT_PROVIDER_DATA, _
'                       BYVAL idxSigner AS DWORD, _
'                       BYVAL fCounterSigner AS LONG, _
'                       BYVAL idxCounterSigner AS DWORD, _
'                       BYREF pCert2Add AS CERT_CONTEXT) AS LONG

'typedef BOOL        (*PFN_CPD_ADD_PRIVDATA)(__in struct _CRYPT_PROVIDER_DATA *pProvData,
'                                            __in struct _CRYPT_PROVIDER_PRIVDATA *pPrivData2Add);

'FUNCTION CPD_ADD_PRIVDATA (BYREF pProvData AS CRYPT_PROVIDER_DATA, _
'                           BYREF pPrivData2Add AS CRYPT_PROVIDER_PRIVDATA) AS LONG

'//////////////////////////////////////////////////////////////////////////////
'//
'//  Provider function prototypes
'//----------------------------------------------------------------------------
'//

'//
'//  entry point for the object provider
'//
'typedef HRESULT     (*PFN_PROVIDER_INIT_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_INIT_CALL ( BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the object provider
'//
'typedef HRESULT     (*PFN_PROVIDER_OBJTRUST_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_OBJTRUST_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Signature Provider
'//
'typedef HRESULT     (*PFN_PROVIDER_SIGTRUST_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_SIGTRUST_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Certificate Provider
'//
'typedef HRESULT     (*PFN_PROVIDER_CERTTRUST_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_CERTTRUST_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Policy Provider's final call (from the trust provider)
'//
'typedef HRESULT     (*PFN_PROVIDER_FINALPOLICY_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_FINALPOLICY_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Policy Provider's "dump structure" call
'//
'typedef HRESULT     (*PFN_PROVIDER_TESTFINALPOLICY_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_TESTFINALPOLICY_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Policy Provider's clean up routine for any PRIVDATA allocated
'//
'typedef HRESULT     (*PFN_PROVIDER_CLEANUP_CALL)(__inout struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVIDER_CLEANUP_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

'//
'//  entry point for the Policy Provider's Cert Check call.  This will return
'//  true if the Trust Provider is to continue building the certificate chain.
'//  If the PP returns FALSE, it is assumed that we have reached a "TRUSTED",
'//  self-signed, root.  it is also the CertCheck's responsibility to set the
'//  fTrustedRoot flag in the certificate structure.
'//
'typedef BOOL        (*PFN_PROVIDER_CERTCHKPOLICY_CALL)( __in          struct _CRYPT_PROVIDER_DATA *pProvData,
'                                                        __in          DWORD idxSigner,
'                                                        __in          BOOL fCounterSignerChain,
'                                                        __in_opt      DWORD idxCounterSigner);


'FUNCTION PROVIDER_CERTCHKPOLICY_CALL (BYREF pProvData AS CRYPT_PROVIDER_DATA, _
'                                      BYVAL idxSigner AS DWORD, _
'                                      BYVAL fCounterSignerChain AS LONG, _
'                                      BYVAL idxCounterSigner AS DWORD) AS LONG

'#define WVT_OFFSETOF(t,f)   ((ULONG)((ULONG_PTR)(&((t*)0)->f)))

'#define WVT_ISINSTRUCT(structtypedef, structpassedsize, member) \
'                    ((WVT_OFFSETOF(structtypedef, member) < structpassedsize) ? TRUE : FALSE)


'#define WVT_IS_CBSTRUCT_GT_MEMBEROFFSET(structtypedef, structpassedsize, member) \
'                    WVT_ISINSTRUCT(structtypedef, structpassedsize, member)

'#include <pshpack8.h>

'//////////////////////////////////////////////////////////////////////////////
'//
'// PROVDATA_SIP
'//----------------------------------------------------------------------------
'//

' // Size = 40 bytes
TYPE PROVDATA_SIP DWORD
   cbStruct            AS DWORD                   ' DWORD
   gSubject            AS GUID                    ' GUID
   pSip                AS SIP_DISPATCH_INFO PTR   ' struct SIP_DISPATCH_INFO_ *
   pCATSip             AS SIP_DISPATCH_INFO PTR   ' struct SIP_DISPATCH_INFO_ *
   psSipSubjectInfo    AS SIP_SUBJECTINFO   PTR   ' struct SIP_SUBJECTINFO_ *
   psSipCATSubjectInfo AS SIP_SUBJECTINFO   PTR   ' struct SIP_SUBJECTINFO_ *
   psIndirectData      AS SIP_INDIRECT_DATA PTR   ' struct SIP_INDIRECT_DATA_ *
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVUI_DATA
'//----------------------------------------------------------------------------
'//
' // Size = 36 bytes
TYPE CRYPT_PROVUI_DATA DWORD
   cbStruct                 AS DWORD          ' DWORD
   dwFinalError             AS DWORD          ' DWORD
   pYesButtonText           AS WSTRINGZ PTR   ' WCHAR *
   pNoButtonText            AS WSTRINGZ PTR   ' WCHAR *
   pMoreInfoButtonText      AS WSTRINGZ PTR   ' WCHAR *
   pAdvancedLinkText        AS WSTRINGZ PTR   ' WCHAR *
   pCopyActionText          AS WSTRINGZ PTR   ' WCHAR *
   pCopyActionTextNoTS      AS WSTRINGZ PTR   ' WCHAR *
   pCopyActionTextNotSigned AS WSTRINGZ PTR   ' WCHAR *
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVUI_FUNCS structure
'//----------------------------------------------------------------------------
'//

'typedef BOOL        (*PFN_PROVUI_CALL)(IN HWND hWndSecurityDialog, IN struct _CRYPT_PROVIDER_DATA *pProvData);
'FUNCTION PROVUI_CALL (BYVAL hWndSecurityDialog AS DWORD, BYREF pProvData AS CRYPT_PROVIDER_DATA) AS LONG

' // Size = 24 bytes
TYPE CRYPT_PROVUI_FUNCS DWORD
   cbStruct                  AS DWORD                   ' DWORD
   psUIData                  AS CRYPT_PROVUI_DATA PTR   ' struct _CRYPT_PROVUI_DATA *
   pfnOnMoreInfoClick        AS DWORD                   ' PFN_PROVUI_CALL
   pfnOnMoreInfoClickDefault AS DWORD                   ' PFN_PROVUI_CALL
   pfnOnAdvancedClick        AS DWORD                   ' PFN_PROVUI_CALL
   pfnOnAdvancedClickDefault AS DWORD                   ' PFN_PROVUI_CALL
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVIDER_FUNCTIONS structure
'//----------------------------------------------------------------------------
'//

' // Size = 64 bytes
TYPE CRYPT_PROVIDER_FUNCTIONS DWORD
   cbStruct             AS DWORD                    ' DWORD
   pfnAlloc             AS DWORD                    ' PFN_CPD_MEM_ALLOC
   pfnFree              AS DWORD                    ' PFN_CPD_MEM_FREE
   pfnAddStore2Chain    AS DWORD                    ' PFN_CPD_ADD_STORE
   pfnAddSgnr2Chain     AS DWORD                    ' PFN_CPD_ADD_SGNR
   pfnAddCert2Chain     AS DWORD                    ' PFN_CPD_ADD_CERT
   pfnAddPrivData2Chain AS DWORD                    ' PFN_CPD_ADD_PRIVDATA
   pfnInitialize        AS DWORD                    ' PFN_PROVIDER_INIT_CALL
   pfnObjectTrust       AS DWORD                    ' PFN_PROVIDER_OBJTRUST_CALL
   pfnSignatureTrust    AS DWORD                    ' PFN_PROVIDER_SIGTRUST_CALL
   pfnCertificateTrust  AS DWORD                    ' PFN_PROVIDER_CERTTRUST_CALL
   pfnFinalPolicy       AS DWORD                    ' PFN_PROVIDER_FINALPOLICY_CALL
   pfnCertCheckPolicy   AS DWORD                    ' PFN_PROVIDER_CERTCHKPOLICY_CALL
   pfnTestFinalPolicy   AS DWORD                    ' PFN_PROVIDER_TESTFINALPOLICY_CALL
   psUIpfns             AS CRYPT_PROVUI_FUNCS PTR   ' struct _CRYPT_PROVUI_FUNCS
   pfnCleanupPolicy     AS DWORD                    ' PFN_PROVIDER_CLEANUP_CALL
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// CRYPT_PROVIDER_DATA Structure
'//----------------------------------------------------------------------------
'//  Used to pass information between WinVerifyTrust and all of the Provider
'//  calls.
'//
'//  IMPORTANT:  1.  All dynamically allocated members MUST use the allocation
'//                  and Add2 functions provided.
'//
'typedef struct _CRYPT_PROVIDER_DATA
'{
'    DWORD                               cbStruct;               // = sizeof(TRUST_PROVIDER_DATA) (set in WVT)

'    WINTRUST_DATA                       *pWintrustData;         // NOT verified (set in WVT)
'    BOOL                                fOpenedFile;            // the provider opened the file handle (if applicable)
'    HWND                                hWndParent;             // if passed in, else, Desktop hWnd (set in WVT).
'    GUID                                *pgActionID;            // represents the Provider combination (set in WVT).

'    HCRYPTPROV                          hProv;                  // set to NULL to let CryptoAPI to assign.

'    DWORD                               dwError;                // error if a low-level, system error was encountered

'    DWORD                               dwRegSecuritySettings;  // ie security settings (set in WVT)
'    DWORD                               dwRegPolicySettings;    // setreg settings (set in WVT)

'    struct _CRYPT_PROVIDER_FUNCTIONS    *psPfns;                // set in WVT.

'    DWORD                               cdwTrustStepErrors;     // set in WVT.
'    DWORD                               *padwTrustStepErrors;   // allocated in WVT.  filled in WVT & Trust Provider

'    DWORD                               chStores;               // number of stores in pahStores (root set in WVT)
'    HCERTSTORE                          *pahStores;             // array of known stores (root set in WVT) root is ALWAYS #0!!!

'    DWORD                               dwEncoding;             // message encoding type (set in WVT and Signature Prov)
'    HCRYPTMSG                           hMsg;                   // set in Signature Prov.

'    DWORD                               csSigners;              // use Add2 and Get functions!
'    struct _CRYPT_PROVIDER_SGNR         *pasSigners;            // use Add2 and Get functions!

'    DWORD                               csProvPrivData;         // use Add2 and Get functions!
'    struct _CRYPT_PROVIDER_PRIVDATA     *pasProvPrivData;       // use Add2 and Get functions!

'    DWORD                               dwSubjectChoice;
'#                       define              CPD_CHOICE_SIP          1

'    union
'    {
'        struct _PROVDATA_SIP            *pPDSip;
'    };

'    char                                *pszUsageOID;           // set in Init Provider

'    BOOL                                fRecallWithState;       // state was maintained for Catalog Files.

'    FILETIME                            sftSystemTime;

'    char                                *pszCTLSignerUsageOID;

'    // LOWORD intialized from WINTRUST_DATA's dwProvFlags.
'    DWORD                               dwProvFlags;
'#       define CPD_USE_NT5_CHAIN_FLAG                   0x80000000
'#       define CPD_REVOCATION_CHECK_NONE                0x00010000
'#       define CPD_REVOCATION_CHECK_END_CERT            0x00020000
'#       define CPD_REVOCATION_CHECK_CHAIN               0x00040000
'#       define CPD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT  0x00080000

'    DWORD                               dwFinalError;

'    PCERT_USAGE_MATCH                                   pRequestUsage;

'    DWORD                               dwTrustPubSettings;

'    DWORD           dwUIStateFlags;
'#       define CPD_UISTATE_MODE_PROMPT                  0x00000000
'#       define CPD_UISTATE_MODE_BLOCK                   0x00000001
'#       define CPD_UISTATE_MODE_ALLOW                   0x00000002
'#       define CPD_UISTATE_MODE_MASK                    0x00000003

'} CRYPT_PROVIDER_DATA, *PCRYPT_PROVIDER_DATA;

%CPD_CHOICE_SIP                           = 1???
%CPD_USE_NT5_CHAIN_FLAG                   = &H80000000???
%CPD_REVOCATION_CHECK_NONE                = &H00010000???
%CPD_REVOCATION_CHECK_END_CERT            = &H00020000???
%CPD_REVOCATION_CHECK_CHAIN               = &H00040000???
%CPD_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT  = &H00080000???
%CPD_UISTATE_MODE_PROMPT                  = &H00000000???
%CPD_UISTATE_MODE_BLOCK                   = &H00000001???
%CPD_UISTATE_MODE_ALLOW                   = &H00000002???
%CPD_UISTATE_MODE_MASK                    = &H00000003???

' // Size = 4 bytes
UNION CRYPT_PROVIDER_DATA_UNION DWORD
   pPDSip AS PROVDATA_SIP PTR
END UNION

' // Size = 128 bytes
TYPE CRYPT_PROVIDER_DATA DWORD
   cbStruct              AS DWORD                          ' DWORD
   pWintrustData         AS WINTRUST_DATA PTR              ' WINTRUST_DATA *
   fOpenedFile           AS LONG                           ' BOOL
   hWndParent            AS DWORD                          ' HWND
   pgActionID            AS GUID PTR                       ' GUID *
   hProv                 AS DWORD                          ' HCRYPTPROV
   dwError               AS DWORD                          ' DWORD
   dwRegSecuritySettings AS DWORD                          ' DWORD
   dwRegPolicySettings   AS DWORD                          ' DWORD
   psPfns                AS CRYPT_PROVIDER_FUNCTIONS PTR   ' struct _CRYPT_PROVIDER_FUNCTIONS *
   cdwTrustStepErrors    AS DWORD                          ' DWORD
   padwTrustStepErrors   AS DWORD PTR                      ' DWORD *
   chStores              AS DWORD                          ' DWORD
   pahStores             AS DWORD PTR                      ' DWORD *
   dwEncoding            AS DWORD                          ' DWORD
   hMsg                  AS DWORD                          ' HCRYPTMSG
   csSigners             AS DWORD                          ' DWORD
   pasSigners            AS CRYPT_PROVIDER_SGNR PTR        ' struct _CRYPT_PROVIDER_SGNR *
   csProvPrivData        AS DWORD                          ' DWORD
   pasProvPrivData       AS CRYPT_PROVIDER_PRIVDATA PTR    ' struct _CRYPT_PROVIDER_PRIVDATA *
   wSubjectChoice        AS DWORD                          ' DWORD
   CRYPT_PROVIDER_DATA_UNION
   pszUsageOID           AS ASCIIZ PTR                     ' char *
   fRecallWithState      AS LONG                           ' BOOL
   sftSystemTime         AS FILETIME                       ' FILETIME
   pszCTLSignerUsageOID  AS ASCIIZ PTR                     ' char *
   ' // LOWORD intialized from WINTRUST_DATA's dwProvFlags.
   dwProvFlags           AS DWORD                          ' DWORD
   dwFinalError          AS DWORD                          ' DWORD
   pRequestUsage         AS CERT_USAGE_MATCH PTR           ' PCERT_USAGE_MATCH
   dwTrustPubSettings    AS DWORD                          ' DWORD
   dwUIStateFlags        AS DWORD                          ' DWORD
END TYPE

'//////////////////////////////////////////////////////////////////////////////
'//
'// structures used to register action IDs
'//----------------------------------------------------------------------------
'//
%WT_CURRENT_VERSION                  = &H00000200???

' // Size = 12 bytes
TYPE CRYPT_TRUST_REG_ENTRY DWORD
   cbStruct         AS DWORD          ' DWORD
   pwszDLLName      AS WSTRINGZ PTR   ' WCHAR *
   pwszFunctionName AS WSTRINGZ PTR   ' WCHAR *
END TYPE

' // Size = 100 bytes
TYPE CRYPT_REGISTER_ACTIONID DWORD
   cbStruct                   AS DWORD                   ' DWORD
   sInitProvider              AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sObjectProvider            AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sSignatureProvider         AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sCertificateProvider       AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sCertificatePolicyProvider AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sFinalPolicyProvider       AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sTestPolicyProvider        AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
   sCleanupProvider           AS CRYPT_TRUST_REG_ENTRY   ' CRYPT_TRUST_REG_ENTRY
END TYPE

'typedef BOOL (*PFN_ALLOCANDFILLDEFUSAGE)(__in const char *pszUsageOID,
'                                         __in struct _CRYPT_PROVIDER_DEFUSAGE *psDefUsage);
'FUNCTION ALLOCANDFILLDEFUSAGE (BYREF pszUsageOID AS ASCIIZ, _
'                               BYREF psDefUsage AS CRYPT_PROVIDER_DEFUSAGE) AS LONG

'typedef BOOL (*PFN_FREEDEFUSAGE)(__in const char *pszUsageOID,
'                                 __in struct _CRYPT_PROVIDER_DEFUSAGE *psDefUsage);
'FUNCTION FREEDEFUSAGE (BYREF pszUsageOID AS ASCIIZ, _
'                       BYREF psDefUsage AS CRYPT_PROVIDER_DEFUSAGE) AS LONG

' // Size = 20 bytes
TYPE CRYPT_PROVIDER_REGDEFUSAGE DWORD
   cbStruct                         AS DWORD          ' DWORD
   pgActionID                       AS GUID PTR       ' GUID *
   pwszDllName                      AS WSTRINGZ PTR   ' WCHAR *
   pwszLoadCallbackDataFunctionName AS ASCIIZ PTR     ' char *
   pwszFreeCallbackDataFunctionName AS ASCIIZ PTR     ' char *
END TYPE

' // Size = 28 bytes
TYPE CRYPT_PROVIDER_DEFUSAGE DWORD
   cbStruct               AS DWORD   ' DWORD
   gActionID              AS GUID    ' GUID
   pDefPolicyCallbackData AS DWORD   ' LPVOID
   pDefSIPClientData      AS DWORD   ' LPVOID
END TYPE

'#include <poppack.h>

'//////////////////////////////////////////////////////////////////////////////
'//
'// WINTRUST.DLL Provider defines
'//----------------------------------------------------------------------------
'//  The following are definitions of the Microsoft Generic Cert Provider
'//
$$WT_PROVIDER_DLL_NAME                = "WINTRUST.DLL"$$
$$WT_PROVIDER_CERTTRUST_FUNCTION      = "WintrustCertificateTrust"$$

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustAddActionID
'//----------------------------------------------------------------------------
'//  Adds a new Provider combination to the users'
'//  system.  Creates all necessary registry entries, etc.  This should be done
'//  during the Policy Provider's DllRegisterServer.
'//
'//  *** THE ONLY ONE WHO SHOULD CALL THIS IS THE POLICY PROVIDER ***
'//
'// Returns:
'//      TRUE:                           No fatal errors
'//      FALSE:                          Errors occured.  See GetLastError()
'//

DECLARE FUNCTION WintrustAddActionID IMPORT "WINTRUST.DLL" ALIAS "WintrustAddActionID" ( _
   BYVAL fdwFlags AS DWORD _                            ' __in DWORD fdwFlags
 , BYREF psProvInfo AS CRYPT_REGISTER_ACTIONID _        ' __in CRYPT_REGISTER_ACTIONID *psProvInfo
 ) AS LONG                                              ' BOOL

'// By default, WintrustAddActionID doesn't return registry errors.
'// Set this flag to return registry errors. If FALSE is returned,
'// LastError is set.
%WT_ADD_ACTION_ID_RET_RESULT_FLAG    = &H1???


'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustRemoveActionID
'//----------------------------------------------------------------------------
'//  Removes the Provider action combination from the users'
'//  system.
'//
'// Returns:
'//      TRUE:                           No fatal errors
'//      FALSE:                          Errors occured.  See GetLastError()
'//

DECLARE FUNCTION WintrustRemoveActionID IMPORT "WINTRUST.DLL" ALIAS "WintrustRemoveActionID" ( _
   BYREF pgActionID AS GUID _                           ' __in GUID *pgActionID
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustLoadFunctionPointers
'//----------------------------------------------------------------------------
'//  Retrieves the function entry points based on the Action ID given.
'//
'// Returns:
'//      TRUE                            success.
'//      FALSE                           fail.
'//

DECLARE FUNCTION WintrustLoadFunctionPointers IMPORT "WINTRUST.DLL" ALIAS "WintrustLoadFunctionPointers" ( _
   BYREF pgActionID AS GUID _                           ' __in  GUID *pgActionID
 , BYREF pPfns AS CRYPT_PROVIDER_FUNCTIONS _            ' __out CRYPT_PROVIDER_FUNCTIONS *pPfns
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustAddDefaultForUsage
'//----------------------------------------------------------------------------
'//  Sets the default Action ID for the usage.  If the provider uses this
'//  function, and the provider requires any of the "callback" data in
'//  WINTRUST_DATA to be filled out, it MUST completely fill out the
'//  CRYPT_PROVIDER_REGDEFUSAGE structure.
'//
'// Returns:
'//      TRUE                            success.
'//      FALSE                           fail.
'//

DECLARE FUNCTION WintrustAddDefaultForUsage IMPORT "WINTRUST.DLL" ALIAS "WintrustAddDefaultForUsage" ( _
   BYREF pszUsageOID AS ASCIIZ _                        ' __in const char *pszUsageOID
 , BYREF psDefUsage AS CRYPT_PROVIDER_REGDEFUSAGE _     ' __in CRYPT_PROVIDER_REGDEFUSAGE *psDefUsage
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustGetDefaultForUsage
'//----------------------------------------------------------------------------
'//  Retrieves the Action ID and default callback data for the specified usage
'//
'//  this function must be called again with dwAction set to FREE to deallocate
'//
'//
'// Returns:
'//      TRUE                            success.
'//      FALSE                           fail.
'//
%DWACTION_ALLOCANDFILL = 1
%DWACTION_FREE         = 2

DECLARE FUNCTION WintrustGetDefaultForUsage IMPORT "WINTRUST.DLL" ALIAS "WintrustGetDefaultForUsage" ( _
   BYVAL dwAction AS DWORD _                            ' __in DWORD dwAction
 , BYREF pszUsageOID AS ASCIIZ _                        ' __in const char *pszUsageOID
 , BYREF psUsage AS CRYPT_PROVIDER_DEFUSAGE _           ' __in_out CRYPT_PROVIDER_DEFUSAGE *psUsage
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WTHelperGetProvSignerFromChain IMPORT "WINTRUST.DLL" ALIAS "WTHelperGetProvSignerFromChain" ( _
   BYREF pProvData AS CRYPT_PROVIDER_DATA _             ' __in CRYPT_PROVIDER_DATA *pProvData
 , BYVAL idxSigner AS DWORD _                           ' __in DWORD idxSigner
 , BYVAL fCounterSigner AS LONG _                       ' __in BOOL fCounterSigner
 , BYVAL idxCounterSigner AS DWORD _                    ' __in DWORD idxCounterSigner
 ) AS DWORD                                             ' CRYPT_PROVIDER_SGNR

DECLARE FUNCTION WTHelperGetProvCertFromChain IMPORT "WINTRUST.DLL" ALIAS "WTHelperGetProvCertFromChain" ( _
   BYREF pSgnr AS CRYPT_PROVIDER_SGNR _                 ' __in CRYPT_PROVIDER_SGNR *pSgnr
 , BYVAL idxCert AS DWORD _                             ' __in DWORD idxCert
 ) AS DWORD                                             ' CRYPT_PROVIDER_CERT

DECLARE FUNCTION WTHelperProvDataFromStateData IMPORT "WINTRUST.DLL" ALIAS "WTHelperProvDataFromStateData" ( _
   BYVAL hStateData AS DWORD _                          ' __in HANDLE hStateData
 ) AS DWORD                                             ' CRYPT_PROVIDER_DATA

DECLARE FUNCTION WTHelperGetProvPrivateDataFromChain IMPORT "WINTRUST.DLL" ALIAS "WTHelperGetProvPrivateDataFromChain" ( _
   BYREF pProvData AS CRYPT_PROVIDER_DATA _             ' __in CRYPT_PROVIDER_DATA *pProvData
 , BYREF pgProviderID AS GUID _                         ' __in GUID *pgProviderID
 ) AS DWORD                                             ' CRYPT_PROVIDER_PRIVDATA

DECLARE FUNCTION WTHelperCertIsSelfSigned IMPORT "WINTRUST.DLL" ALIAS "WTHelperCertIsSelfSigned" ( _
   BYVAL dwEncoding AS DWORD _                          ' __in DWORD dwEncoding
 , BYREF pCert AS CERT_INFO _                           ' __in CERT_INFO *pCert
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WTHelperCertCheckValidSignature IMPORT "WINTRUST.DLL" ALIAS "WTHelperCertCheckValidSignature" ( _
   BYREF pProvData AS CRYPT_PROVIDER_DATA _             ' __in CRYPT_PROVIDER_DATA *pProvData
 ) AS LONG                                              ' HRESULT

'//////////////////////////////////////////////////////////////////////////////
'//
'// Supported ASN structures contained in WINTRUST.DLL
'//----------------------------------------------------------------------------
'//
'#include <pshpack8.h>

'//
'//  CTL Trusted CA Lists
'//
$szOID_TRUSTED_CODESIGNING_CA_LIST   = "1.3.6.1.4.1.311.2.2.1"
$szOID_TRUSTED_CLIENT_AUTH_CA_LIST   = "1.3.6.1.4.1.311.2.2.2"
$szOID_TRUSTED_SERVER_AUTH_CA_LIST   = "1.3.6.1.4.1.311.2.2.3"

'//
'//  encode/decode OID defines
'//
$SPC_COMMON_NAME_OBJID               = $szOID_COMMON_NAME
$SPC_TIME_STAMP_REQUEST_OBJID        = "1.3.6.1.4.1.311.3.2.1"
$SPC_INDIRECT_DATA_OBJID             = "1.3.6.1.4.1.311.2.1.4"
$SPC_SP_AGENCY_INFO_OBJID            = "1.3.6.1.4.1.311.2.1.10"
$SPC_STATEMENT_TYPE_OBJID            = "1.3.6.1.4.1.311.2.1.11"
$SPC_SP_OPUS_INFO_OBJID              = "1.3.6.1.4.1.311.2.1.12"
$SPC_CERT_EXTENSIONS_OBJID           = "1.3.6.1.4.1.311.2.1.14"
$SPC_PE_IMAGE_DATA_OBJID             = "1.3.6.1.4.1.311.2.1.15"
$SPC_RAW_FILE_DATA_OBJID             = "1.3.6.1.4.1.311.2.1.18"
$SPC_STRUCTURED_STORAGE_DATA_OBJID   = "1.3.6.1.4.1.311.2.1.19"
$SPC_JAVA_CLASS_DATA_OBJID           = "1.3.6.1.4.1.311.2.1.20"
$SPC_INDIVIDUAL_SP_KEY_PURPOSE_OBJID = "1.3.6.1.4.1.311.2.1.21"
$SPC_COMMERCIAL_SP_KEY_PURPOSE_OBJID = "1.3.6.1.4.1.311.2.1.22"
$SPC_CAB_DATA_OBJID                  = "1.3.6.1.4.1.311.2.1.25"
$SPC_GLUE_RDN_OBJID                  = "1.3.6.1.4.1.311.2.1.25"   ' // obsolete!
$SPC_MINIMAL_CRITERIA_OBJID          = "1.3.6.1.4.1.311.2.1.26"
$SPC_FINANCIAL_CRITERIA_OBJID        = "1.3.6.1.4.1.311.2.1.27"
$SPC_LINK_OBJID                      = "1.3.6.1.4.1.311.2.1.28"
$SPC_SIGINFO_OBJID                   = "1.3.6.1.4.1.311.2.1.30"

'//
'//  Page hash versions
'//
$SPC_PE_IMAGE_PAGE_HASHES_V1_OBJID   = "1.3.6.1.4.1.311.2.3.1"   ' // V1
$SPC_PE_IMAGE_PAGE_HASHES_V2_OBJID   = "1.3.6.1.4.1.311.2.3.2"   ' // V2

'//
'//  Catalog entries
'//
$CAT_NAMEVALUE_OBJID                 = "1.3.6.1.4.1.311.12.2.1"
$CAT_MEMBERINFO_OBJID                = "1.3.6.1.4.1.311.12.2.2"


'//
'//  encode/decode internal defines
'//

%SPC_SP_AGENCY_INFO_STRUCT           = 2000   ' ((LPCSTR) 2000)
%SPC_MINIMAL_CRITERIA_STRUCT         = 2001   ' ((LPCSTR) 2001)
%SPC_FINANCIAL_CRITERIA_STRUCT       = 2002   ' ((LPCSTR) 2002)
%SPC_INDIRECT_DATA_CONTENT_STRUCT    = 2003   ' ((LPCSTR) 2003)
%SPC_PE_IMAGE_DATA_STRUCT            = 2004   ' ((LPCSTR) 2004)
%SPC_LINK_STRUCT                     = 2005   ' ((LPCSTR) 2005)
%SPC_STATEMENT_TYPE_STRUCT           = 2006   ' ((LPCSTR) 2006)
%SPC_SP_OPUS_INFO_STRUCT             = 2007   ' ((LPCSTR) 2007)
%SPC_CAB_DATA_STRUCT                 = 2008   ' ((LPCSTR) 2008)
%SPC_JAVA_CLASS_DATA_STRUCT          = 2009   ' ((LPCSTR) 2009)

%SPC_SIGINFO_STRUCT                  = 2130   ' ((LPCSTR) 2130)

%CAT_NAMEVALUE_STRUCT                = 2221   ' ((LPCSTR) 2221)
%CAT_MEMBERINFO_STRUCT               = 2222   ' ((LPCSTR) 2222)


%SPC_UUID_LENGTH    = 16
'typedef BYTE SPC_UUID[SPC_UUID_LENGTH];

'#define SpcSerializedObjectAttributesClassId    {0xA6, 0xB5, 0x86, 0xD5, \
'                                                 0xB4, 0xA1, 0x24, 0x66, \
'                                                 0xAE, 0x05, 0xA2, 0x17, \
'                                                 0xDA, 0x8E, 0x60, 0xD6}

$SpcSerializedObjectAttributesClassId = GUID$("{A6B586D5-B4A1-2466-AE05-A217DA8E60D6}")

' // Size = 24 bytes
TYPE SPC_SERIALIZED_OBJECT DWORD
   ClassId        AS GUID              ' SPC_UUID
   SerializedData AS CRYPT_DATA_BLOB   ' CRYPT_DATA_BLOB
END TYPE

' // Size = 40 bytes
TYPE SPC_SIGINFO DWORD
   dwSipVersion AS DWORD   ' DWORD
   gSIPGuid     AS GUID    ' GUID
   dwReserved1  AS DWORD   ' DWORD
   dwReserved2  AS DWORD   ' DWORD
   dwReserved3  AS DWORD   ' DWORD
   dwReserved4  AS DWORD   ' DWORD
   dwReserved5  AS DWORD   ' DWORD
END TYPE

%SPC_URL_LINK_CHOICE        = 1
%SPC_MONIKER_LINK_CHOICE    = 2
%SPC_FILE_LINK_CHOICE       = 3

' // Size = 24 bytes
UNION SPC_LINK_UNION DWORD
   pwszUrl  AS WSTRINGZ PTR            ' LPWSTR
   Moniker  AS SPC_SERIALIZED_OBJECT   ' SPC_SERIALIZED_OBJECT
   pwszFile AS WSTRINGZ PTR            ' LPWSTR
END UNION

' // Size = 28 bytes
TYPE SPC_LINK DWORD
   dwLinkChoice AS DWORD   ' DWORD
   SPC_LINK_UNION
END TYPE

' // Size = 16 bytes
TYPE SPC_PE_IMAGE_DATA DWORD
   Flags AS CRYPT_BIT_BLOB   ' CRYPT_BIT_BLOB
   pFile AS SPC_LINK PTR     ' PSPC_LINK
END TYPE

' // Size = 32 bytes
TYPE SPC_INDIRECT_DATA_CONTENT DWORD
   Data            AS CRYPT_ATTRIBUTE_TYPE_VALUE
   DigestAlgorithm AS CRYPT_ALGORITHM_IDENTIFIER
   Digest          AS CRYPT_HASH_BLOB
END TYPE

' // Size = 8 bytes
TYPE SPC_FINANCIAL_CRITERIA DWORD
   fFinancialInfoAvailable AS LONG   ' BOOL
   fMeetsCriteria          AS LONG   ' BOOL
END TYPE

' // Size = 36 bytes
TYPE SPC_IMAGE DWORD
   pImageLink       AS SPC_LINK PTR      ' struct SPC_LINK_
   Bitmap           AS CRYPT_DATA_BLOB
   Metafile         AS CRYPT_DATA_BLOB
   EnhancedMetafile AS CRYPT_DATA_BLOB
   GifFile          AS CRYPT_DATA_BLOB
END TYPE

' // Size = 16 bytes
TYPE SPC_SP_AGENCY_INFO DWORD
   pPolicyInformation    AS SPC_LINK PTR    ' struct SPC_LINK_
   pwszPolicyDisplayText AS WSTRINGZ PTR    ' LPWSTR
   pLogoImage            AS SPC_IMAGE PTR   ' PSPC_IMAGE
   pLogoLink             AS SPC_LINK PTR    ' struct SPC_LINK_
END TYPE

' // Size = 8 bytes
TYPE SPC_STATEMENT_TYPE DWORD
   cKeyPurposeId     AS DWORD        ' DWORD
   rgpszKeyPurposeId AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE SPC_SP_OPUS_INFO DWORD
   pwszProgramName AS WSTRINGZ PTR   ' LPCWSTR
   pMoreInfo       AS SPC_LINK PTR   ' struct SPC_LINK_
   pPublisherInfo  AS SPC_LINK PTR   ' struct SPC_LINK_
END TYPE

' // Size = 16 bytes
TYPE CAT_NAMEVALUE DWORD
   pwszTag  AS WSTRINGZ PTR   ' LPWSTR
   fdwFlags AS DWORD          ' DWORD
   Value    AS CRYPT_DATA_BLOB
END TYPE

' // Size = 8 bytes
TYPE CAT_MEMBERINFO DWORD
   pwszSubjGuid  AS WSTRINGZ PTR   ' LPWSTR
   dwCertVersion AS DWORD          ' DWORD
END TYPE

'#include <poppack.h>



'//////////////////////////////////////////////////////////////////////////////////
'//
'//  support for old calling convention: *** DO NOT USE ***
'//
'#ifdef WT_DEFINE_ALL_APIS

' // Size = 12 bytes
TYPE WIN_CERTIFICATE DWORD FILL
   dwLength         AS DWORD   ' DWORD
   wRevision        AS WORD    ' WORD
   wCertificateType AS WORD    ' WORD // WIN_CERT_TYPE_xxx
   bCertificate(3)  AS BYTE    ' BYTE - variable length array
   ' Note: We are using bCertificate(3) instead of bCertificate(0) to keep DWORD alignment
END TYPE

%WIN_CERT_REVISION_1_0               = &H0100
%WIN_CERT_REVISION_2_0               = &H0200

%WIN_CERT_TYPE_X509                  = &H0001   ' // bCertificate contains an X.509 Certificate
%WIN_CERT_TYPE_PKCS_SIGNED_DATA      = &H0002   ' // bCertificate contains a PKCS SignedData structure
%WIN_CERT_TYPE_RESERVED_1            = &H0003   ' // Reserved
%WIN_CERT_TYPE_TS_STACK_SIGNED       = &H0004   ' // Terminal Server Protocol Stack Certificate signing


'typedef LPVOID WIN_TRUST_SUBJECT;

' // Size = 12 bytes
TYPE WIN_TRUST_ACTDATA_CONTEXT_WITH_SUBJECT DWORD
   hClientToken AS DWORD      ' HANDLE
   SubjectType  AS GUID PTR   ' GUID *
   Subject      AS DWORD      ' WIN_TRUST_SUBJECT
END TYPE

' // Size = 8 bytes
TYPE WIN_TRUST_ACTDATA_SUBJECT_ONLY DWORD
   SubjectType AS GUID PTR   ' GUID *
   Subject     AS DWORD      ' WIN_TRUST_SUBJECT
END TYPE

'/* RawFile == 959dc450-8d9e-11cf-8736-00aa00a485eb */
$WIN_TRUST_SUBJTYPE_RAW_FILE = GUID$("{959dc450-8d9e-11cf-8736-00aa00a485eb}")

'/* PeImage == 43c9a1e0-8da0-11cf-8736-00aa00a485eb */
$WIN_TRUST_SUBJTYPE_PE_IMAGE = GUID$("{43c9a1e0-8da0-11cf-8736-00aa00a485eb}")

'/* JavaClass = 08ad3990-8da1-11cf-8736-00aa00a485eb */
$WIN_TRUST_SUBJTYPE_JAVA_CLASS = GUID$("{08ad3990-8da1-11cf-8736-00aa00a485eb}")

'/* Cabinet = d17c5374-a392-11cf-9df5-00aa00c184e0 */
$WIN_TRUST_SUBJTYPE_CABINET = GUID$("{d17c5374-a392-11cf-9df5-00aa00c184e0}")

' // Size = 8 bytes
TYPE WIN_TRUST_SUBJECT_FILE DWORD
   hFile  AS DWORD          ' HANDLE
   lpPath AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

$WIN_TRUST_SUBJTYPE_RAW_FILEEX = GUID$("{6f458110-c2f1-11cf-8a69-00aa006c3706}")
$WIN_TRUST_SUBJTYPE_PE_IMAGEEX = GUID$("{6f458111-c2f1-11cf-8a69-00aa006c3706}")
$WIN_TRUST_SUBJTYPE_JAVA_CLASSEX = GUID$("{6f458113-c2f1-11cf-8a69-00aa006c3706}")
$WIN_TRUST_SUBJTYPE_CABINETEX = GUID$("{6f458114-c2f1-11cf-8a69-00aa006c3706}")

' // Size = 12 bytes
TYPE WIN_TRUST_SUBJECT_FILE_AND_DISPLAY DWORD
   hFile         AS DWORD          ' HANDLE   // handle to the open file if you got it
   lpPath        AS WSTRINGZ PTR   ' LPCWSTR // the path to open if you don't
   lpDisplayName AS WSTRINGZ PTR   ' LPCWSTR // (optional) display name to show to user
END TYPE

'/* OleStorage == c257e740-8da0-11cf-8736-00aa00a485eb */
$WIN_TRUST_SUBJTYPE_OLE_STORAGE = GUID$("{c257e740-8da0-11cf-8736-00aa00a485eb}")

'/* TrustedPublisher == 66426730-8da1-11cf-8736-00aa00a485eb */
$WIN_SPUB_ACTION_TRUSTED_PUBLISHER = GUID$("{66426730-8da1-11cf-8736-00aa00a485eb}")

'/* NtActivateImage == 8bc96b00-8da1-11cf-8736-00aa00a485eb */
$WIN_SPUB_ACTION_NT_ACTIVATE_IMAGE = GUID$("{8bc96b00-8da1-11cf-8736-00aa00a485eb}")

'/* PublishedSoftware == 64b9d180-8da2-11cf-8736-00aa00a485eb */
$WIN_SPUB_ACTION_PUBLISHED_SOFTWARE = GUID$("{64b9d180-8da2-11cf-8736-00aa00a485eb}")

' // Size = 8 bytes
TYPE WIN_SPUB_TRUSTED_PUBLISHER_DATA DWORD
   hClientToken  AS DWORD                 ' HANDLE
   lpCertificate AS WIN_CERTIFICATE PTR   ' LPWIN_CERTIFICATE
END TYPE

'#endif

'// Open the cert manager UI dialog's TrustedPublisher Tab.
'//
'// The following flags may be set:
'//   WT_TRUSTDBDIALOG_NO_UI_FLAG
'//      Set this flag in conjunction with
'//      WT_TRUSTDBDIALOG_WRITE_LEGACY_REG_FLAG and/or
'//      WT_TRUSTDBDIALOG_WRITE_IEAK_STORE_FLAG to do the registry and/or
'//      store write without any UI.
'//   WT_TRUSTDBDIALOG_ONLY_PUB_TAB_FLAG
'//      By default all of the UI tabs are displayed with TrustedPublisher
'//      as the initial tab. Setting this flag only displays the
'//      TrustedPublisher tab.
'//   WT_TRUSTDBDIALOG_WRITE_LEGACY_REG_FLAG
'//      Setting this flag causes the trusted publishers to be written to the
'//      following legacy registry location:
'//          "HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\
'//              WinTrust\Trust Providers\Software Publishing\Trust Database\0"
'//      The registry value names are constructed as ascii generated
'//      representations of the md5 hash of the issuer name and the cert's serial
'//      number. The string value is the subject display name.
'//
'//      Note, the above registry key is initially deleted to force the removal
'//      of any previous publisher values.
'//   WT_TRUSTDBDIALOG_WRITE_IEAK_STORE_FLAG
'//      Setting this flag causes all of the trusted publishers to be copied to
'//      the "TrustedPublisher_IEAK" system registry store at the following
'//      location:
'//          "HKEY_CURRENT_USER\Software\Microsoft\SystemCertificates\
'//              TrustedPublisher_IEAK\Certificates\..."
'//      Note, the logical HKCU TrustedPublisher store inherits from HKLM and
'//      GroupPolicy. The TrustedPublisher_IEAK will contain the entire set
'//      under a single registry subkey.
'//
'//      Note, initially all certs are removed from the above store.
'//

DECLARE FUNCTION OpenPersonalTrustDBDialogEx IMPORT "WINTRUST.DLL" ALIAs "OpenPersonalTrustDBDialogEx" ( _
   BYVAL hwndParent AS DWORD _                          ' __in OPTIONAL HWND hwndParent
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , OPTIONAL BYREF pvReserved AS ANY _                   ' __in_out OPTIONAL PVOID *pvReserved
 ) AS LONG                                              ' BOOL

%WT_TRUSTDBDIALOG_NO_UI_FLAG             = &H00000001???
%WT_TRUSTDBDIALOG_ONLY_PUB_TAB_FLAG      = &H00000002???
%WT_TRUSTDBDIALOG_WRITE_LEGACY_REG_FLAG  = &H00000100???
%WT_TRUSTDBDIALOG_WRITE_IEAK_STORE_FLAG  = &H00000200???

'// Calls above with dwFlags = 0 and pvReserved = NULL
DECLARE FUNCTION OpenPersonalTrustDBDialog IMPORT "WINTRUST.DLL" ALIAs "OpenPersonalTrustDBDialog" ( _
   OPTIONAL BYVAL hwndParent AS WORD _                  ' __in OPTIONAL HWND hwndParent
 ) AS LONG                                              ' BOOL

'//////////////////////////////////////////////////////////////////////////////
'//
'// WintrustSetDefaultIncludePEPageHashes
'//----------------------------------------------------------------------------
'//  This API may be called to set the default setting for including page
'//  hashes when creating SIP indirect data for PE files.
'//
'//  Unless explicitly set, the default is not to include page hashes.
'//

DECLARE SUB WintrustSetDefaultIncludePEPageHashes IMPORT "WINTRUST.DLL" ALIAs "WintrustSetDefaultIncludePEPageHashes" ( _
   BYVAL fIncludePEPageHashes AS LONG _                 ' __in BOOL fIncludePEPageHashes
 )                                                      ' void
