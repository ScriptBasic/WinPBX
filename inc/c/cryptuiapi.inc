' ########################################################################################
' Microsoft Windows
' File: cryptuiapi.inc
' Contents: Cryptographic UI API Prototypes and Definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CRYPTUIAPI_INC = 1

#INCLUDE ONCE "wintrust.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "prsht.inc"

'#include <pshpack8.h>

%CERT_CREDENTIAL_PROVIDER_ID = -509

'//+----------------------------------------------------------------------------
'//  Dialog viewer of a certificate, CTL or CRL context.
'//
'//  dwContextType and associated pvContext's
'//      CERT_STORE_CERTIFICATE_CONTEXT  PCCERT_CONTEXT
'//      CERT_STORE_CRL_CONTEXT          PCCRL_CONTEXT
'//      CERT_STORE_CTL_CONTEXT          PCCTL_CONTEXT
'//
'//  dwFlags currently isn't used and should be set to 0.
'//-----------------------------------------------------------------------------

DECLARE FUNCTION CryptUIDlgViewContext IMPORT "Cryptui.dll" ALIAS "CryptUIDlgViewContext" ( _
   BYVAL dwContextType AS DWORD _                       ' __in DWORD dwContextType
 , BYVAL pvContext AS DWORD _                           ' __in const void *pvContext
 , BYVAL hwnd AS DWORD _                                ' __in OPTIONAL HWND hwnd         // Defaults to the desktop window
 , BYREF pwszTitle AS WSTRINGZ _                        ' __in OPTIONAL LPCWSTR pwszTitle // Defaults to the context type title
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS LONG                                              ' BOOL


'//+----------------------------------------------------------------------------
'//  Dialog to select a certificate from the specified store.
'//
'//  Returns the selected certificate context. If no certificate was
'//  selected, NULL is returned.
'//
'//  pwszTitle is either NULL or the title to be used for the dialog.
'//  If NULL, the default title is used.  The default title is
'//  "Select Certificate".
'//
'//  pwszDisplayString is either NULL or the text statement __in the selection
'//  dialog.  If NULL, the default phrase
'//  "Select a certificate you wish to use" is used __in the dialog.
'//
'//  dwDontUseColumn can be set to exclude columns from the selection
'//  dialog. See the CRYPTDLG_SELECTCERT_*_COLUMN definitions below.
'//
'//  dwFlags currently isn't used and should be set to 0.
'//-----------------------------------------------------------------------------

DECLARE FUNCTION CryptUIDlgSelectCertificateFromStore IMPORT "Cryptui.dll" ALIAS "CryptUIDlgSelectCertificateFromStore" ( _
   BYVAL hCertStore AS DWORD _                          ' __in HCERTSTORE hCertStore
 , BYVAL hwnd AS DWORD _                                ' __in OPTIONAL HWND hwnd // Defaults to the desktop window
 , BYREF pwszTitle AS WSTRINGZ _                        ' __in OPTIONAL LPCWSTR pwszTitle
 , BYREF pwszDisplayString AS WSTRINGZ _                ' __in OPTIONAL LPCWSTR pwszDisplayString
 , BYVAL dwDontUseColumn AS DWORD _                     ' __in DWORD dwDontUseColumn
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in void *pvReserved
 ) AS DWORD                                             ' PCCERT_CONTEXT

'// flags for dwDontUseColumn
%CRYPTUI_SELECT_ISSUEDTO_COLUMN                   = &H000000001???
%CRYPTUI_SELECT_ISSUEDBY_COLUMN                   = &H000000002???
%CRYPTUI_SELECT_INTENDEDUSE_COLUMN                = &H000000004???
%CRYPTUI_SELECT_FRIENDLYNAME_COLUMN               = &H000000008???
%CRYPTUI_SELECT_LOCATION_COLUMN                   = &H000000010???
%CRYPTUI_SELECT_EXPIRATION_COLUMN                 = &H000000020???

'//+----------------------------------------------------------------------------
'//
'// The select cert dialog can be passed a filter proc to reduce the set of
'// certificates displayed.  Return TRUE to display the certificate and FALSE to
'// hide it.  If TRUE is returned then optionally the pfInitialSelectedCert
'// boolean may be set to TRUE to indicate to the dialog that this cert should
'// be the initially selected cert.  Note that the most recent cert that had the
'// pfInitialSelectedCert boolean set during the callback will be the initially
'// selected cert.
'//
'//-----------------------------------------------------------------------------

'FUNCTION CFILTERPROC ( _
'   BYREF pCertContext AS CERT_CONTEXT _                 ' PCCERT_CONTEXT  pCertContext
' , BYVAL pfInitialSelectedCert AS LONG _                ' BOOL           *pfInitialSelectedCert
' , BYVAL pvCallbackData AS DWORD _                      ' void           *pvCallbackData
' ) AS LONG                                              ' BOOL

' // Size = 12 bytes
TYPE CERT_SELECTUI_INPUT DWORD
   hStore    AS DWORD                    ' HCERTSTORE
   prgpChain AS CERT_CHAIN_CONTEXT PTR   ' PCCERT_CHAIN_CONTEXT * prgpChain
   cChain    AS DWORD                    ' DWORD
END TYPE

'//+----------------------------------------------------------------------------
'//
'// CertSelectionGetSerializedBlob
'//
'// The API to obtain serialized blob from an input struct
'//
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION CertSelectionGetSerializedBlob IMPORT "Cryptui.dll" ALIAS "CertSelectionGetSerializedBlob" ( _
   BYREF pcsi AS CERT_SELECTUI_INPUT _                  ' __in PCERT_SELECTUI_INPUT pcsi
 , BYREF ppOutBuffer AS DWORD _                         ' __out void ** ppOutBuffer
 , BYREF pulOutBufferSize AS DWORD _                    ' __out ULONG *pulOutBufferSize
 ) AS LONG                                              ' HRESULT

'//+----------------------------------------------------------------------------
'// Valid values for dwFlags __in CRYPTUI_CERT_MGR_STRUCT struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_CERT_MGR_TAB_MASK                       = &H0000000F???
%CRYPTUI_CERT_MGR_PUBLISHER_TAB                  = &H00000004???
%CRYPTUI_CERT_MGR_SINGLE_TAB_FLAG                = &H00008000???

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_CERT_MGR_STRUCT
'//
'// dwSize               __in Required: Should be set to
'//                                   sizeof(CRYPTUI_CERT_MGR_STRUCT)
'//
'// hwndParent           __in Optional: Parent of this dialog.
'//
'// dwFlags              __in Optional: Personal is the default initially selected
'//                                   tab.
'//
'//                                   CRYPTUI_CERT_MGR_PUBLISHER_TAB may be set
'//                                   to select Trusted Publishers as the
'//                                   initially selected tab.
'//
'//                                   CRYPTUI_CERT_MGR_SINGLE_TAB_FLAG may also
'//                                   be set to only display the Trusted
'//                                   Publishers tab.
'//
'// pwszTitle            __in Optional: Title of the dialog.
'//
'// pszInitUsageOID      __in Optional: The enhanced key usage object identifier
'//                                   (OID). Certificates with this OID will
'//                                   initially be shown as a default. User
'//                                   can then choose different OIDs. NULL
'//                                   means all certificates will be shown
'//                                   initially.
'//
'//-----------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPTUI_CERT_MGR_STRUCT DWORD
   dwSize          AS DWORD          ' DWORD
   hwndParent      AS DWORD          ' HWND
   dwFlags         AS DWORD          ' DWORD
   pwszTitle       AS WSTRINGZ PTR   ' LPCWSTR
   pszInitUsageOID AS ASCIIZ PTR     ' LPCSTR
END TYPE


'//+----------------------------------------------------------------------------
'//
'// CryptUIDlgCertMgr
'//
'// The wizard to manage certificates __in store.
'//
'// pCryptUICertMgr      __in  Required: Poitner to CRYPTUI_CERT_MGR_STRUCT
'//                                    structure.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION CryptUIDlgCertMgr IMPORT "Cryptui.dll" ALIAS "CryptUIDlgCertMgr" ( _
   BYREF pCryptUICertMgr AS CRYPTUI_CERT_MGR_STRUCT _   ' __in PCCRYPTUI_CERT_MGR_STRUCT pCryptUICertMgr
 ) AS LONG                                              ' BOOL

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO
'//
'// dwSize               __in Required: Should be set to
'//                                   sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO)
'//
'// pGuidSubject         __in Required: Idenfity the sip functions to load
'//
'// cbBlob               __in Required: The size of blob, __in bytes
'//
'// pwszDispalyName      __in Optional: The display name of the blob to sign
'//
'//-----------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO DWORD
   dwSize          AS DWORD          ' DWORD
   pGuidSubject    AS GUID PTR       ' GUID *
   cbBlob          AS DWORD          ' DWORD
   pbBlob          AS BYTE PTR       ' BYTE *
   pwszDisplayName AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO
'//
'// dwSize               __in Required: Should be set to
'//                                   sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO)
'//
'// cCertStore           __in Required: The acount of certificate store array that
'//                                   includes potentical sining certs
'//
'// rghCertStore         __in Required: The certificate store array that includes
'//                                   potential signing certs
'//
'// pFilterCallback      __in Optional: The filter call back function for display
'//                                   the certificate
'//
'// pvCallbackData       __in Optional: The call back data
'//
'//-----------------------------------------------------------------------------

' // Size = 20 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO DWORD
   dwSize          AS DWORD       ' DWORD
   cCertStore      AS DWORD       ' DWORD
   rghCertStore    AS DWORD PTR   ' HCERTSTORE *
   pFilterCallback AS DWORD       ' PFNCFILTERPROC
   pvCallbackData  AS DWORD       ' void *
END TYPE

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO
'//
'// dwSize               __in Required: Should be set to
'//                                   sizeof(CRYPT_WIZ_DIGITAL_SIGN_PVK_FILE_INFO)
'//
'// pwszPvkFileName      __in Required: The PVK file name
'//
'// pwszProvName         __in Required: The provider name
'//
'// dwProvType           __in Required: The provider type
'//
'//-----------------------------------------------------------------------------

' // Size = 16 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO DWORD
   dwSize          AS DWORD          ' DWORD
   pwszPvkFileName AS WSTRINGZ PTR   ' LPWSTR
   pwszProvName    AS WSTRINGZ PTR   ' LPWSTR
   dwProvType      AS DWORD          ' DWORD
END TYPE

'//+----------------------------------------------------------------------------
'// Valid values for dwPvkChoice __in CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO
'// struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE                = &H01???
%CRYPTUI_WIZ_DIGITAL_SIGN_PVK_PROV                = &H02???

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO
'//
'// dwSize                   __in Required: Should be set to
'//                                       sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO)
'//
'// pwszSigningCertFileName  __in Required: The file name that contains the
'//                                       signing cert(s)
'//
'// dwPvkChoice              __in Required: Indicate the private key type.
'//                                       It can be one of the following:
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_PVK_PROV
'//
'//  pPvkFileInfo            __in Required: If dwPvkChoice == CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE
'//
'//  pPvkProvInfo            __in Required: If dwPvkContainer == CRYPTUI_WIZ_DIGITAL_SIGN_PVK_PROV
'//
'//-----------------------------------------------------------------------------

' // Size = 4 bytes
UNION CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO_UNION DWORD
   pPvkFileInfo AS CRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO PTR   ' PCCRYPTUI_WIZ_DIGITAL_SIGN_PVK_FILE_INFO
   pPvkProvInfo AS CRYPT_KEY_PROV_INFO PTR                      ' PCRYPT_KEY_PROV_INFO
END UNION

' // Size = 16 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO DWORD
   dwSize                  AS DWORD          ' DWORD
   pwszSigningCertFileName AS WSTRINGZ PTR   ' LPWSTR
   dwPvkChoice             AS DWORD          ' DWORD
   CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO_UNION
END TYPE

'//+----------------------------------------------------------------------------
'// Valid values for dwAttrFlags __in CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO
'// struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_DIGITAL_SIGN_COMMERCIAL              = &H0001???
%CRYPTUI_WIZ_DIGITAL_SIGN_INDIVIDUAL              = &H0002???

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO
'//
'// dwSize                       __in Required: Should be set to
'//                                           sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO)
'//
'// dwAttrFlags                  __in Required: Flag to indicate signing options.
'//                                           It can be one of the following:
'//                                               CRYPTUI_WIZ_DIGITAL_SIGN_COMMERCIAL
'//                                               CRYPTUI_WIZ_DIGITAL_SIGN_INDIVIDUAL
'//
'// pwszDescription              __in Optional: The description of the signing
'//                                           subject.

'// pwszMoreInfoLocation         __in Optional: The localtion to get more
'//                                           information about file this
'//                                           information will be shown upon
'//                                           download time.
'//
'// pszHashAlg                   __in Optional: The hashing algorithm for the
'//                                           signature. NULL means using SHA1
'//                                           hashing algorithm.
'//
'// pwszSigningCertDisplayString __in Optional: The display string to be
'//                                           displayed on the signing
'//                                           certificate wizard page. The
'//                                           string should prompt user to
'//                                           select a certificate for a
'//                                           particular purpose.
'//
'// hAddtionalCertStores         __in Optional: The addtional cert store to add to
'//                                           the signature.
'//
'// psAuthenticated              __in Optional: User supplied authenticated
'//                                           attributes added to the signature.
'//
'// psUnauthenticated           __in Optional: User supplied unauthenticated
'//                                           attributes added to the signature.
'//
'//-----------------------------------------------------------------------------

' // Size = 36 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO DWORD
   dwSize                       AS DWORD                  ' DWORD
   dwAttrFlags                  AS DWORD                  ' DWORD
   pwszDescription              AS WSTRINGZ PTR           ' LPCWSTR
   pwszMoreInfoLocation         AS WSTRINGZ PTR           ' LPCWSTR
   pszHashAlg                   AS ASCIIZ PTR             ' LPCSTR
   pwszSigningCertDisplayString AS WSTRINGZ PTR           ' LPCWSTR
   hAdditionalCertStore         AS DWORD                  ' HCERTSTORE
   psAuthenticated              AS CRYPT_ATTRIBUTES PTR   ' PCRYPT_ATTRIBUTES
   psUnauthenticated            AS CRYPT_ATTRIBUTES PTR   ' PCRYPT_ATTRIBUTES
END TYPE

'//+----------------------------------------------------------------------------
'// Valid values for dwSubjectChoice __in CRYPTUI_WIZ_DIGITAL_SIGN_INFO struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE            = &H01???
%CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB            = &H02???

'//+----------------------------------------------------------------------------
'// Valid values for dwSigningCertChoice __in CRYPTUI_WIZ_DIGITAL_SIGN_INFO
'// struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_DIGITAL_SIGN_CERT                    = &H01???
%CRYPTUI_WIZ_DIGITAL_SIGN_STORE                   = &H02???
%CRYPTUI_WIZ_DIGITAL_SIGN_PVK                     = &H03???

'//+----------------------------------------------------------------------------
'// Valid values for dwAddtionalCertChoice __in CRYPTUI_WIZ_DIGITAL_SIGN_INFO
'// struct.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN               = &H00000001???
%CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN_NO_ROOT       = &H00000002???

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_INFO
'//
'// dwSize                   __in Required: Should be set to
'//                                       sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_INFO)
'//
'// dwSubjectChoice          __in Required: If CRYPTUI_WIZ_NO_UI is set __in dwFlags
'//                                       of the CryptUIWizDigitalSign call.
'//
'//                             Optional: If CRYPTUI_WIZ_NO_UI is not set __in
'//                                       dwFlags of the CryptUIWizDigitalSign
'//                                       call.
'//
'//                                       Indicate whether to sign a file or to
'//                                       sign a memory blob. 0 means promting
'//                                       user for the file to sign.
'//
'//                                       It can be one of the following:
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB
'//
'// pwszFileName             __in Required: If dwSubjectChoice == CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_FILE
'//
'// pSignBlobInfo            __in Required: If dwSubhectChoice == CRYPTUI_WIZ_DIGITAL_SIGN_SUBJECT_BLOB
'//
'// dwSigningCertChoice      __in Optional: Indicate the signing certificate.
'//                                       0 means using the certificates in
'//                                       "My" store".
'//
'//                                       It can be one of the following choices:
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_CERT
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_STORE
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_PVK
'//
'//                                       If CRYPTUI_WIZ_NO_UI is set __in dwFlags
'//                                       of the CryptUIWizDigitalSign call,
'//                                       dwSigningCertChoice has to be
'//                                       CRYPTUI_WIZ_DIGITAL_SIGN_CERT or
'//                                       CRYPTUI_WIZ_DIGITAL_SIGN_PVK
'//
'// pSigningCertContext      __in Required: If dwSigningCertChoice == CRYPTUI_WIZ_DIGITAL_SIGN_CERT
'//
'// pSigningCertStore        __in Required: If dwSigningCertChoice == CRYPTUI_WIZ_DIGITAL_SIGN_STORE
'//
'// pSigningCertPvkInfo      __in Required: If dwSigningCertChoise == CRYPTUI_WIZ_DIGITAL_SIGN_PVK
'//
'// pwszTimestampURL         __in Optional: The timestamp URL address.
'//
'// dwAdditionalCertChoice   __in Optional: Indicate additional certificates to be
'//                                       included __in the signature. 0 means no
'//                                       addtional certificates will be added.
'//
'//                                       The following flags are mutually
'//                                       exclusive.
'//                                       Only one of them can be set:
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN
'//                                           CRYPTUI_WIZ_DIGITAL_SIGN_ADD_CHAIN_NO_ROOT
'//
'// pSignExtInfo             __in Optional: The extended information for signing.
'//
'//-----------------------------------------------------------------------------

' // Size = 4 bytes
UNION CRYPTUI_WIZ_DIGITAL_SIGN_INFO_UNION1 DWORD
   pwszFileName  AS WSTRINGZ PTR                             ' LPCWSTR
   pSignBlobInfo AS CRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO PTR   ' PCCRYPTUI_WIZ_DIGITAL_SIGN_BLOB_INFO
END UNION

' // Size = 4 bytes
UNION CRYPTUI_WIZ_DIGITAL_SIGN_INFO_UNION2 DWORD
   pSigningCertContext AS CERT_CONTEXT PTR                             ' PCCERT_CONTEXT
   pSigningCertStore AS CRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO PTR        ' PCCRYPTUI_WIZ_DIGITAL_SIGN_STORE_INFO
   pSigningCertPvkInfo AS CRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO PTR   ' PCCRYPTUI_WIZ_DIGITAL_SIGN_CERT_PVK_INFO
END UNION

' // Size = 32 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_INFO DWORD
   dwSize                               AS DWORD                                        ' DWORD
   dwSubjectChoice                      AS DWORD                                        ' DWORD
   CRYPTUI_WIZ_DIGITAL_SIGN_INFO_UNION1
   dwSigningCertChoice                  AS DWORD                                        ' DWORD
   CRYPTUI_WIZ_DIGITAL_SIGN_INFO_UNION2
   pwszTimestampURL                     AS WSTRINGZ PTR                                 ' LPCWSTR
   dwAdditionalCertChoice               AS DWORD                                        ' DWORD
   pSignExtInfo                         AS CRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO PTR   ' PCCRYPTUI_WIZ_DIGITAL_SIGN_EXTENDED_INFO
END TYPE

'//+----------------------------------------------------------------------------
'//
'// CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT
'//
'// dwSize               __in Required: Should be set to
'//                                   sizeof(CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT)
'//
'// cbBlob               __in Required: The size of pbBlob __in bytes.
'//
'// pbBlob               __in Required: The signed blob.
'//
'//-----------------------------------------------------------------------------

' // Size = 12 bytes
TYPE CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT DWORD
   dwSize AS DWORD      ' DWORD
   cbBlob AS DWORD      ' DWORD
   pbBlob AS BYTE PTR   ' BYTE *
END TYPE

'//+----------------------------------------------------------------------------
'// Valid values for dwFlags parameter to CryptUIWizDigitalSign.
'//-----------------------------------------------------------------------------
%CRYPTUI_WIZ_NO_UI                               = &H0001???
%CRYPTUI_WIZ_DIGITAL_SIGN_EXCLUDE_PAGE_HASHES    = &H0002???

'// The above CRYPTUI_WIZ_DIGITAL_SIGN_EXCLUDE_PAGE_HASHES takes precedence if
'// also set.
%CRYPTUI_WIZ_DIGITAL_SIGN_INCLUDE_PAGE_HASHES    = &H0004???

'//+----------------------------------------------------------------------------
'//
'// CryptUIWizDigitalSign
'//
'// The wizard to digitally sign a document or a blob.
'//
'// If CRYPTUI_WIZ_NO_UI is set __in dwFlags, no UI will be shown.  Otherwise,
'// user will be prompted for input through a wizard.
'//
'// dwFlags              __in Required: See dwFlags values above.
'//
'// hwndParent           __in Optional: The parent window handle.
'//
'// pwszWizardTitle      __in Optional: The title of the wizard.
'//
'// pDigitalSignInfo     __in Required: The information about the signing process.
'//
'// ppSignContext        __out Optional: The context pointer points to the signed
'//                                    blob.
'//
'//-----------------------------------------------------------------------------

DECLARE FUNCTION CryptUIWizDigitalSign IMPORT "Cryptui.dll" ALIAS "CryptUIWizDigitalSign" ( _
   BYVAL dwFlags AS DWORD _                             ' __in      DWORD                               dwFlags
 , BYVAL hwndParent AS DWORD _                          ' __in_opt  HWND                                hwndParent
 , BYREF pwszWizardTitle AS WSTRINGZ _                  ' __in_opt  LPCWSTR                             pwszWizardTitle
 , BYREF pDigitalSignInfo AS CRYPTUI_WIZ_DIGITAL_SIGN_INFO _ ' __in      PCCRYPTUI_WIZ_DIGITAL_SIGN_INFO     pDigitalSignInfo
 , OPTIONAL BYREF ppSignContext AS CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT _ ' __out_opt PCCRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT *ppSignContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptUIWizFreeDigitalSignContext IMPORT "Cryptui.dll" ALIAS "CryptUIWizFreeDigitalSignContext" ( _
   BYREF pSignContext AS CRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT _ ' __in PCCRYPTUI_WIZ_DIGITAL_SIGN_CONTEXT pSignContext
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////////////////////////////
'//
'// dwSize                          size of this struct
'// hwndParent                      parent of this dialog                                    (OPTIONAL)
'// dwFlags                         flags, may a combination of any of the flags below       (OPTIONAL)
'// szTitle                         title for the window                                     (OPTIONAL)
'// pCertContext                    the cert context that is to be displayed
'// rgszPurposes                    array of purposes that this cert is to be validated for  (OPTIONAL)
'// cPurposes                       number of purposes                                       (OPTIONAL)
'// pCryptProviderData/hWVTStateData if WinVerifyTrust has already been called for the cert  (OPTIONAL)
'//                                 then pass __in a pointer to the state struct that was
'//                                 acquired through a call to WTHelperProvDataFromStateData(),
'//                                 or pass __in the hWVTStateData of the WINTRUST_DATA struct
'//                                 if WTHelperProvDataFromStateData() was not called.
'//                                 if pCryptProviderData/hWVTStateData is used then
'//                                 fpCryptProviderDataTrustedUsage, idxSigner, idxCert, and
'//                                 fCounterSignature must be set
'// fpCryptProviderDataTrustedUsage if WinVerifyTrust was called this is the result of whether (OPTIONAL)
'//                                 the cert was trusted
'// idxSigner                       the index of the signer to view                          (OPTIONAL)
'// idxCert                         the index of the cert that is being viewed within the    (OPTIONAL)
'//                                 signer chain.  the cert context of this cert MUST match
'//                                 pCertContext
'// fCounterSigner                  set to TRUE if a counter signature is being viewed.  if  (OPTIONAL)
'//                                 this is TRUE then idxCounterSigner must be valid
'// idxCounterSigner                the index of the counter signer to view                  (OPTIONAL)
'// cStores                         Count of other stores to search when building and        (OPTIONAL)
'//                                 validating chain
'// rghStores                       Array of other stores to search when buliding and        (OPTIONAL)
'//                                 validating chain
'// cPropSheetPages                 number of extra pages to add to the dialog.              (OPTIONAL)
'// rgPropSheetPages                extra pages to add to the dialog.                        (OPTIONAL)
'//                                 each page __in this array will NOT recieve the lParam in
'//                                 the PROPSHEET structure as the lParam __in the
'//                                 WM_INITDIALOG, instead it will receive a pointer to a
'//                                 CRYPTUI_INITDIALOG_STRUCT (defined below) which contains
'//                                 the lParam __in the PROPSSHEET structure AND the
'//                                 PCCERT_CONTEXT for which the page is being displayed.
'// nStartPage                      this is the index of the initial page that will be
'//                                 displayed.  if the upper most bit (0x8000) is set then
'//                                 the index is assumed to index rgPropSheetPages
'//                                 (after the upper most bit has been stripped off.  eg.
'//                                 0x8000 will indicate the first page __in rgPropSheetPages),
'//                                 if the upper most bit is 0 then nStartPage will be the
'//                                 starting index of the default certificate dialog pages.
'//
'/////////////////////////////////////////////////////////////////////////////////////////////////////

'// dwFlags
%CRYPTUI_HIDE_HIERARCHYPAGE          = &H00000001???
%CRYPTUI_HIDE_DETAILPAGE             = &H00000002???
%CRYPTUI_DISABLE_EDITPROPERTIES      = &H00000004???
%CRYPTUI_ENABLE_EDITPROPERTIES       = &H00000008???
%CRYPTUI_DISABLE_ADDTOSTORE          = &H00000010???
%CRYPTUI_ENABLE_ADDTOSTORE           = &H00000020???
%CRYPTUI_ACCEPT_DECLINE_STYLE        = &H00000040???
%CRYPTUI_IGNORE_UNTRUSTED_ROOT       = &H00000080???
%CRYPTUI_DONT_OPEN_STORES            = &H00000100???
%CRYPTUI_ONLY_OPEN_ROOT_STORE        = &H00000200???
%CRYPTUI_WARN_UNTRUSTED_ROOT         = &H00000400???   ' // For use with viewing of certificates on remote
                                                       ' // machines only.  If this flag is used rghStores[0]
                                                       ' // must be the handle of the root store on the remote machine.
%CRYPTUI_ENABLE_REVOCATION_CHECKING  = &H00000800???   ' // This flag is only valid if pCryptProviderData/hWVTStateData
                                                       ' // is not passed in.
%CRYPTUI_WARN_REMOTE_TRUST           = &H00001000???
%CRYPTUI_DISABLE_EXPORT              = &H00002000???   ' // If this flag is set, then the "Copy to file" button will be
                                                       ' // disabled on the Detail page.

' // Revocation flags is only valid if pCryptProviderData/hWVTStateData is not passed in.
%CRYPTUI_ENABLE_REVOCATION_CHECK_END_CERT           = &H00004000???
%CRYPTUI_ENABLE_REVOCATION_CHECK_CHAIN              = &H00008000???
%CRYPTUI_ENABLE_REVOCATION_CHECK_CHAIN_EXCLUDE_ROOT = %CRYPTUI_ENABLE_REVOCATION_CHECKING   ' // Changed the default behavior
                                                                                            ' // to not check root.
%CRYPTUI_DISABLE_HTMLLINK                           = &H00010000???   ' // to disable helplink __in viewing certificate
%CRYPTUI_DISABLE_ISSUERSTATEMENT                    = &H00020000???   ' // to disable issuer statement button

%CRYPTUI_CACHE_ONLY_URL_RETRIEVAL                   = &H00040000???   ' // to disable online revocation checking
'//
'// this struct is passed as the lParam __in the WM_INITDIALOG call to each
'// property sheet that is __in the rgPropSheetPages array of the
'// CRYPTUI_VIEWCERTIFICATE_STRUCT structure
'//

' // Size = 8 bytes
TYPE CRYPTUI_INITDIALOG_STRUCT DWORD
   lParam       AS LONG               ' LPARAM
   pCertContext AS CERT_CONTEXT PTR   ' PCCERT_CONTEXT
END TYPE

' // Size = 4 bytes
UNION CRYPTUI_VIEWCERTIFICATE_STRUCTW_UNION DWORD
   pCryptProviderData AS CRYPT_PROVIDER_DATA PTR   ' CRYPT_PROVIDER_DATA const * // OPTIONAL
   hWVTStateData      AS DWORD                     ' HANDLE // OPTIONAL
END UNION

' // Size = 72 bytes
TYPE CRYPTUI_VIEWCERTIFICATE_STRUCTW DWORD
   dwSize                          AS DWORD                ' DWORD
   hwndParent                      AS DWORD                ' HWND // OPTIONAL
   dwFlags                         AS DWORD                ' DWORD // OPTIONAL
   szTitle                         AS WSTRINGZ PTR         ' LPCWSTR // OPTIONAL
   pCertContext                    AS CERT_CONTEXT PTR     ' PCCERT_CONTEXT
   rgszPurposes                    AS ASCIIZ PTR           ' LPCSTR* // OPTIONAL
   cPurposes                       AS DWORD                ' DWORD // OPTIONAL
   CRYPTUI_VIEWCERTIFICATE_STRUCTW_UNION
   fpCryptProviderDataTrustedUsage AS LONG                 ' BOOL // OPTIONAL
   idxSigner                       AS DWORD                ' DWORD // OPTIONAL
   idxCert                         AS DWORD                ' DWORD // OPTIONAL
   fCounterSigner                  AS LONG                 ' BOOL // OPTIONAL
   idxCounterSigner                AS DWORD                ' DWORD // OPTIONAL
   cStores                         AS DWORD                ' DWORD // OPTIONAL
   rghStores                       AS DWORD PTR            ' HCERTSTORE* // OPTIONAL
   cPropSheetPages                 AS DWORD                ' DWORD // OPTIONAL
   rgPropSheetPages                AS PROPSHEETPAGEW PTR   ' LPCPROPSHEETPAGEW // OPTIONAL
   nStartPage                      AS DWORD                ' DWORD
END TYPE

' // Size = 4 bytes
UNION CRYPTUI_VIEWCERTIFICATE_STRUCTA_UNION DWORD
   pCryptProviderData AS CRYPT_PROVIDER_DATA PTR   ' CRYPT_PROVIDER_DATA const * // OPTIONAL
   hWVTStateData      AS DWORD                     ' HANDLE // OPTIONAL
END UNION

' // Size = 72 bytes
TYPE CRYPTUI_VIEWCERTIFICATE_STRUCTA DWORD
   dwSize                          AS DWORD                ' DWORD
   hwndParent                      AS DWORD                ' HWND // OPTIONAL
   dwFlags                         AS DWORD                ' DWORD // OPTIONAL
   szTitle                         AS ASCIIZ PTR           ' LPCSTR // OPTIONAL
   pCertContext                    AS CERT_CONTEXT PTR     ' PCCERT_CONTEXT
   rgszPurposes                    AS ASCIIZ PTR           ' LPCSTR* // OPTIONAL
   cPurposes                       AS DWORD                ' DWORD // OPTIONAL
   CRYPTUI_VIEWCERTIFICATE_STRUCTA_UNION
   fpCryptProviderDataTrustedUsage AS LONG                 ' BOOL // OPTIONAL
   idxSigner                       AS DWORD                ' DWORD // OPTIONAL
   idxCert                         AS DWORD                ' DWORD // OPTIONAL
   fCounterSigner                  AS LONG                 ' BOOL // OPTIONAL
   idxCounterSigner                AS DWORD                ' DWORD // OPTIONAL
   cStores                         AS DWORD                ' DWORD // OPTIONAL
   rghStores                       AS DWORD PTR            ' HCERTSTORE* // OPTIONAL
   cPropSheetPages                 AS DWORD                ' DWORD // OPTIONAL
   rgPropSheetPages                AS PROPSHEETPAGEA PTR   ' LPCPROPSHEETPAGEA // OPTIONAL
   nStartPage                      AS DWORD                ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO CRYPTUI_VIEWCERTIFICATE_STRUCT = CRYPTUI_VIEWCERTIFICATE_STRUCTW
#ELSE
   MACRO CRYPTUI_VIEWCERTIFICATE_STRUCT = CRYPTUI_VIEWCERTIFICATE_STRUCTA
#ENDIF

'//
'// pfPropertiesChanged             this will be set by the dialog proc to inform the caller
'//                                 if any properties have been changed on certs __in the chain
'//                                 while the dialog was open
'//

DECLARE FUNCTION CryptUIDlgViewCertificateW IMPORT "Cryptui.dll" ALIAS "CryptUIDlgViewCertificateW" ( _
   BYREF pCertViewInfo AS CRYPTUI_VIEWCERTIFICATE_STRUCTW _ ' __in  PCCRYPTUI_VIEWCERTIFICATE_STRUCTW pCertViewInfo
 , BYREF pfPropertiesChanged AS LONG _                  ' __out BOOL *pfPropertiesChanged  // OPTIONAL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptUIDlgViewCertificateA IMPORT "Cryptui.dll" ALIAS "CryptUIDlgViewCertificateA" ( _
   BYREF pCertViewInfo AS CRYPTUI_VIEWCERTIFICATE_STRUCTA _ ' __in  PCCRYPTUI_VIEWCERTIFICATE_STRUCTA pCertViewInfo
 , BYREF pfPropertiesChanged AS LONG _                  ' __out BOOL *pfPropertiesChanged  // OPTIONAL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CryptUIDlgViewCertificate = CryptUIDlgViewCertificateW
#ELSE
   MACRO CryptUIDlgViewCertificate = CryptUIDlgViewCertificateA
#ENDIF

'//-------------------------------------------------------------------------
'//
'//   Valid values for dwSubjectChoice __in CRYPTUI_WIZ_EXPORT_INFO
'//-------------------------------------------------------------------------
%CRYPTUI_WIZ_EXPORT_CERT_CONTEXT                 = 1???
%CRYPTUI_WIZ_EXPORT_CTL_CONTEXT                  = 2???
%CRYPTUI_WIZ_EXPORT_CRL_CONTEXT                  = 3???
%CRYPTUI_WIZ_EXPORT_CERT_STORE                   = 4???
%CRYPTUI_WIZ_EXPORT_CERT_STORE_CERTIFICATES_ONLY = 5???
%CRYPTUI_WIZ_EXPORT_FORMAT_CRL                   = 6???
%CRYPTUI_WIZ_EXPORT_FORMAT_CTL                   = 7???

'//-------------------------------------------------------------------------
'//
'//   Struct to define the object to be exported and where to export it to
'//
'//  CRYPTUI_WIZ_EXPORT_SUBJECT_INFO
'//
'//-------------------------------------------------------------------------

' // Size = 4 bytes
UNION CRYPTUI_WIZ_EXPORT_INFO_UNION DWORD
   pCTLContext AS CTL_CONTEXT PTR   ' PCCTL_CONTEXT
   pCRLContext AS CTL_CONTEXT PTR   ' PCCTL_CONTEXT
   hCertStore  AS DWORD             ' HCERTSTORE
END UNION

' // Size = 24 bytes
TYPE CRYPTUI_WIZ_EXPORT_INFO DWORD
   dwSize             AS DWORD          ' DWORD //Required: should be set to sizeof(CRYPTUI_WIZ_EXPORT_INFO)
   pwszExportFileName AS WSTRINGZ PTR   ' LPCWSTR //Required if the CRYPTUI_WIZ_NO_UI flag is set, Optional otherwise.
                                        ' //The fully qualified file name to export to, if this is
                                        ' //non-NULL and the CRYPTUI_WIZ_NO_UI flag is NOT set, then it is
                                        ' //displayed to the user as the default file name
   dwSubjectChoice    AS DWORD          ' DWORD //Required:   indicate the type of the subject:
                                        ' //          If can one of the following:
                                        ' //          CRYPTUI_WIZ_EXPORT_CERT_CONTEXT
                                        ' //          CRYPTUI_WIZ_EXPORT_CTL_CONTEXT
                                        ' //          CRYPTUI_WIZ_EXPORT_CRL_CONTEXT
                                        ' //          CRYPTUI_WIZ_EXPORT_CERT_STORE
                                        ' //           CRYPTUI_WIZ_EXPORT_CERT_STORE_CERTIFICATES_ONLY
   CRYPTUI_WIZ_EXPORT_INFO_UNION
   cStores            AS DWORD          ' DWORD // Optional: count of extra stores to search for the certs __in the
                                        ' //           trust chain if the chain is being exported with a cert.
                                        ' //           this is ignored if dwSubjectChoice is anything other
                                        ' //           than CRYPTUI_WIZ_EXPORT_CERT_CONTEXT
   rghStores          AS DWORD PTR      ' HCERTSTORE* // Optional: array of extra stores to search for the certs __in the
                                        ' //           trust chain if the chain is being exported with a cert.
                                        ' //           this is ignored if dwSubjectChoice is anything other
                                        ' //           than CRYPTUI_WIZ_EXPORT_CERT_CONTEXT

END TYPE

'//-------------------------------------------------------------------------
'//
'//   Valid values for dwExportFormat __in CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO
'//-------------------------------------------------------------------------
%CRYPTUI_WIZ_EXPORT_FORMAT_DER                   = 1
%CRYPTUI_WIZ_EXPORT_FORMAT_PFX                   = 2
%CRYPTUI_WIZ_EXPORT_FORMAT_PKCS7                 = 3
%CRYPTUI_WIZ_EXPORT_FORMAT_BASE64                = 4
%CRYPTUI_WIZ_EXPORT_FORMAT_SERIALIZED_CERT_STORE = 5   ' // NOTE: not currently supported!!

'//-------------------------------------------------------------------------
'//
'//   Struct to define the information needed to export a CERT_CONTEXT
'//
'//  CRYPTUI_WIZ_EXPORT_NOUI_INFO
'//
'//-------------------------------------------------------------------------

' // Size = 24 bytes
TYPE CRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO DWORD
   dwSize             AS DWORD          ' DWORD // Required: should be set to sizeof(CRYPTUI_WIZ_EXPORT_NOUI_INFO)
   dwExportFormat     AS DWORD          ' DWORD // Required:
                                        ' //          It can be one of the following:
                                        ' //          CRYPTUI_WIZ_EXPORT_FORMAT_DER
                                        ' //          CRYPTUI_WIZ_EXPORT_FORMAT_PFX
                                        ' //          CRYPTUI_WIZ_EXPORT_FORMAT_PKCS7
                                        ' //          CRYPTUI_WIZ_EXPORT_FORMAT_SERIALIZED_CERT_STORE

   fExportChain       AS LONG           ' BOOL // Required
   fExportPrivateKeys AS LONG           ' BOOL // Required
   pwszPassword       AS WSTRINGZ PTR   ' LPCWSTR // Required if the fExportPrivateKeys boolean is TRUE, otherwise,
                                        '         // it is ignored
   fStrongEncryption  AS LONG           ' BOOL // Required if dwExportFormat is CRYPTUI_WIZ_EXPORT_FORMAT_PFX
                                        '      // Note that if this flag is TRUE then the PFX blob produced is
                                        '      // NOT compatible with IE4.
END TYPE

'//-----------------------------------------------------------------------
'//
'// CryptUIWizExport
'//
'//  The export wizard to export public key related objects to a file
'//
'//  If dwFlags is set to CRYPTUI_WIZ_NO_UI, no UI will be shown.  Otherwise,
'//  User will be prompted for input through a wizard.
'//
'//  If CRYPTUI_WIZ_NO_UI is set __in dwFlags:
'//      hwndParent:         Ignored
'//      pwszWizardTitle:    Ignored
'//      pExportInfo:        __in Required:    The subject to export.
'//      pvoid:              __in Required:    Contains information about how to do the export based on what
'//                                          is being exported
'//
'//                                          dwSubjectChoice                     INPUT TYPE
'//                                          -------------------------------------------------------------------------
'//                                          CRYPTUI_WIZ_EXPORT_CERT_CONTEXT     PCCRYPTUI_WIZ_EXPORT_CERTCONTEXT_INFO
'//                                          CRYPTUI_WIZ_EXPORT_CTL_CONTEXT      NULL
'//                                          CRYPTUI_WIZ_EXPORT_CRL_CONTEXT      NULL
'//                                          CRYPTUI_WIZ_EXPORT_CERT_STORE       NULL
'//
'//  If CRYPTUI_WIZ_NO_UI is not set __in dwFlags:
'//      hwndPrarent:        __in Optional:    The parent window for the wizard
'//      pwszWizardTitle:    __in Optional:    The title of the wizard
'//                                          If NULL, the default will be IDS_EXPORT_WIZARD_TITLE
'//      pExportInfo:        __in Required:    The subject to export.
'//      pvoid:              __in Optional:    Contains information about how to do the export based on what
'//                                          is being exported.  See above table for values, if this is non-NULL
'//                                          the values are displayed to the user as the default choices.
'//------------------------------------------------------------------------

DECLARE FUNCTION CryptUIWizExport IMPORT "Cryptui.dll" ALIAS "CryptUIWizExport" ( _
   BYVAL dwFlags AS DWORD _                             ' DWORD                      dwFlags
 , BYVAL hwndParent AS DWORD _                          ' HWND                       hwndParent
 , BYREF pwszWizardTitle AS WSTRINGZ _                  ' LPCWSTR                    pwszWizardTitle
 , BYREF pExportInfo AS CRYPTUI_WIZ_EXPORT_INFO _       ' PCCRYPTUI_WIZ_EXPORT_INFO  pExportInfo
 , BYVAL pvoid AS DWORD _                               '  void                      *pvoid
 ) AS LONG                                              ' BOOL

'//-------------------------------------------------------------------------
'//
'//   Valid values for dwSubjectChoice __in IMPORT_SUBJECT_INFO
'//-------------------------------------------------------------------------
%CRYPTUI_WIZ_IMPORT_SUBJECT_FILE                = 1
%CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_CONTEXT        = 2
%CRYPTUI_WIZ_IMPORT_SUBJECT_CTL_CONTEXT         = 3
%CRYPTUI_WIZ_IMPORT_SUBJECT_CRL_CONTEXT         = 4
%CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_STORE          = 5

'//-------------------------------------------------------------------------
'//
'//   Struct to define the subject CertImportWizard
'//
'//  CRYPTUI_WIZ_IMPORT_SUBJECT_INFO
'//
'//-------------------------------------------------------------------------

' // Size = 4 bytes
UNION CRYPTUI_WIZ_IMPORT_SRC_INFO_UNION DWORD
   pwszFileName AS WSTRINGZ PTR       ' LPCWSTR
   pCertContext AS CERT_CONTEXT PTR   ' PCCERT_CONTEXT
   pCTLContext  AS CTL_CONTEXT  PTR   ' PCCTL_CONTEXT
   pCRLContext  AS CRL_CONTEXT  PTR   ' PCCRL_CONTEXT
   hCertStore   AS DWORD              ' HCERTSTORE
END UNION

' // Size = 20 bytes
TYPE CRYPTUI_WIZ_IMPORT_SRC_INFO DWORD
   dwSize          AS DWORD          ' DWORD // Required: should be set to sizeof(IMPORT_SUBJECT_INFO)
   dwSubjectChoice AS DWORD          ' DWORD // Required:   indicate the type of the subject:
                                     ' //          If can one of the following:
                                     ' //          CRYPTUI_WIZ_IMPORT_SUBJECT_FILE
                                     ' //          CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_CONTEXT
                                     ' //          CRYPTUI_WIZ_IMPORT_SUBJECT_CTL_CONTEXT
                                     ' //          CRYPTUI_WIZ_IMPORT_SUBJECT_CRL_CONTEXT
                                     ' //          CRYPTUI_WIZ_IMPORT_SUBJECT_CERT_STORE
   CRYPTUI_WIZ_IMPORT_SRC_INFO_UNION
   dwFlags         AS DWORD          ' DWORD // Required if pwszFileName contains a PFX BLOB.
                                     ' // Ignored otherwise
                                     ' // This is the same flag for PFXImportCertStore
   pwszPassword    AS WSTRINGZ PTR   ' LPCWSTR // Required if pwszFileName contains a PFX BLOB.
                                     ' // ignored otherwise
END TYPE

'//-----------------------------------------------------------------------
'//
'// Valid flags for dwFlags __in CryptUIWizImport
'//
'//-----------------------------------------------------------------------
'// if this flag is set __in dwFlags, user will not be allowed to change
'// the hDesCertStore __in the wizard page
%CRYPTUI_WIZ_IMPORT_NO_CHANGE_DEST_STORE           = &H00010000???

'// Allow importing certificate
%CRYPTUI_WIZ_IMPORT_ALLOW_CERT                     = &H00020000???

'// Allow importing certificate revocation list
%CRYPTUI_WIZ_IMPORT_ALLOW_CRL                      = &H00040000???

'// Allow importing certificate trust list
%CRYPTUI_WIZ_IMPORT_ALLOW_CTL                      = &H00080000???

'// import contents to local machine (currently only applicable for PFX imports)
%CRYPTUI_WIZ_IMPORT_TO_LOCALMACHINE                = &H00100000???

'// import contents to current user (currently only applicable for PFX imports)
%CRYPTUI_WIZ_IMPORT_TO_CURRENTUSER                 = &H00200000???

'// if the hDesCertStore is a remote store handle, this flag should be set
%CRYPTUI_WIZ_IMPORT_REMOTE_DEST_STORE              = &H00400000???

'//-----------------------------------------------------------------------
'//
'// CryptUIWizImport
'//
'//  The import wizard to import public key related files to a certificate
'//  store
'//
'//  dwFlags can be set to any combination of the following flags:
'//  CRYPTUI_WIZ_NO_UI                           No UI will be shown.  Otherwise, User will be
'//                                              prompted by a wizard.
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CERT               Allow importing certificate
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CRL                Allow importing CRL(certificate revocation list)
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CTL                Allow importing CTL(certificate trust list)
'//  CRYPTUI_WIZ_IMPORT_NO_CHANGE_DEST_STORE     user will not be allowed to change
'//                                              the hDesCertStore __in the wizard page
'//  CRYPTUI_WIZ_IMPORT_TO_LOCALMACHINE          the contents should be imported to local machine
'//                                              (currently only applicable for PFX imports)
'//  CRYPTUI_WIZ_IMPORT_TO_CURRENTUSER           the contents should be imported to current user
'//                                              (currently only applicable for PFX imports)
'//
'//  Please notice that if neither of following three flags is __in dwFlags, default to is
'//  allow everything.
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CERT
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CRL
'//  CRYPTUI_WIZ_IMPORT_ALLOW_CTL
'//
'//  Also, note that the CRYPTUI_WIZ_IMPORT_TO_LOCALMACHINE and CRYPTUI_WIZ_IMPORT_TO_CURRENTUSER
'//  flags are used force the content of a pfx blob into either local machine or current user.
'//  If neither of these flags are used and hDesCertStore is NULL then:
'//  1) The private key __in the pfx blob will be forced to be imported into current user.
'//  2) If CRYPTUI_WIZ_NO_UI is NOT set, the wizard will prompt the user to select a certificate
'//     store from the current user stores.
'//
'//
'//
'//  If CRYPTUI_WIZ_NO_UI is set __in dwFlags:
'//      hwndParent:         Ignored
'//      pwszWizardTitle:    Ignored
'//      pImportSubject:     __in Required:    The subject to import.
'//      hDesCertStore:      __in Optional:    The destination certficate store
'//
'//  If CRYPTUI_WIZ_NO_UI is not set __in dwFlags:
'//      hwndPrarent:        __in Optional:    The parent window for the wizard
'//      pwszWizardTitle:    __in Optional:    The title of the wizard
'//                                          If NULL, the default will be IDS_IMPORT_WIZARD_TITLE
'//      pImportSubject:     __in Optional:    The file name to import.
'//                                          If NULL, the wizard will prompt user to enter the file name
'//      hDesCertStore:      __in Optional:    The destination certificate store where the file wil be
'//                                          imported to.  The store should be opened with
'//                                          flag CERT_STORE_SET_LOCALIZED_NAME_FLAG.  If NULL, the wizard will prompt user to select
'//                                          a certificate store.
'//------------------------------------------------------------------------

DECLARE FUNCTION CryptUIWizImport IMPORT "Cryptui.dll" ALIAS "CryptUIWizImport" ( _
   BYVAL dwFlags AS DWORD _                             ' DWORD                         dwFlags
 , BYVAL hwndParent AS DWORD _                          ' HWND                          hwndParent
 , BYREF pwszWizardTitle AS WSTRINGZ _                  ' LPCWSTR                       pwszWizardTitle
 , BYREF pImportSrc AS CRYPTUI_WIZ_IMPORT_SRC_INFO  _   ' PCCRYPTUI_WIZ_IMPORT_SRC_INFO pImportSrc
 , BYVAL hDestCertStore AS DWORD _                      ' HCERTSTORE                    hDestCertStore
 ) AS LONG                                              ' BOOL

'#include <poppack.h>
