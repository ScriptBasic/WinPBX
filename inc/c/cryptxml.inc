' ########################################################################################
' Microsoft Windows
' File: CryptXml.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CRYPTXML_INC = 1

'#include <specstrings.h>        /* for SAL annotations */
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "bcrypt.inc"
#INCLUDE ONCE "ncrypt.inc"

'typedef struct _CRYPT_XML_BLOB                  CRYPT_XML_BLOB, *PCRYPT_XML_BLOB;
'typedef struct _CRYPT_XML_DATA_BLOB             CRYPT_XML_DATA_BLOB, *PCRYPT_XML_DATA_BLOB;
'typedef struct _CRYPT_XML_STATUS                CRYPT_XML_STATUS, *PCRYPT_XML_STATUS;
'typedef struct _CRYPT_XML_TRANSFORM_INFO        CRYPT_XML_TRANSFORM_INFO, *PCRYPT_XML_TRANSFORM_INFO;
'typedef struct _CRYPT_XML_TRANSFORM_CHAIN_CONFIG CRYPT_XML_TRANSFORM_CHAIN_CONFIG, *PCRYPT_XML_TRANSFORM_CHAIN_CONFIG;
'typedef struct _CRYPT_XML_KEY_INFO              CRYPT_XML_KEY_INFO, *PCRYPT_XML_KEY_INFO;
'typedef struct _CRYPT_XML_ALGORITHM             CRYPT_XML_ALGORITHM, *PCRYPT_XML_ALGORITHM;
'typedef struct _CRYPT_XML_REFERENCE             CRYPT_XML_REFERENCE, *PCRYPT_XML_REFERENCE;
'typedef struct _CRYPT_XML_REFERENCES            CRYPT_XML_REFERENCES, *PCRYPT_XML_REFERENCES;
'typedef struct _CRYPT_XML_SIGNED_INFO           CRYPT_XML_SIGNED_INFO, *PCRYPT_XML_SIGNED_INFO;
'typedef struct _CRYPT_XML_OBJECT                CRYPT_XML_OBJECT, *PCRYPT_XML_OBJECT;
'typedef struct _CRYPT_XML_SIGNATURE             CRYPT_XML_SIGNATURE, *PCRYPT_XML_SIGNATURE;
'typedef struct _CRYPT_XML_ALGORITHM_INFO        CRYPT_XML_ALGORITHM_INFO, *PCRYPT_XML_ALGORITHM_INFO;
'typedef struct _CRYPT_XML_CRYPTOGRAPHIC_INTERFACE CRYPT_XML_CRYPTOGRAPHIC_INTERFACE, *PCRYPT_XML_CRYPTO_PROVIDER;

'typedef void*   HCRYPTXML;

'#define wszXMLNS_DIGSIG                         L"http://www.w3.org/2000/09/xmldsig#"
$wszXMLNS_DIGSIG                         = "http://www.w3.org/2000/09/xmldsig#"

'#define wszXMLNS_DIGSIG_SignatureProperties     L"http://www.w3.org/2000/09/xmldsig#SignatureProperties"
$wszXMLNS_DIGSIG_SignatureProperties     = "http://www.w3.org/2000/09/xmldsig#SignatureProperties"

'//
'// The Id attribute must be unique withing the XML document.
'// It's used to identify same-document (internal) references.
'//

'#define wszXMLNS_DIGSIG_Id                       L"Id"
$wszXMLNS_DIGSIG_Id                       = "Id"

'#define wszURI_XMLNS_DIGSIG_BASE64               L"http://www.w3.org/2000/09/xmldsig#base64"
$wszURI_XMLNS_DIGSIG_BASE64               = "http://www.w3.org/2000/09/xmldsig#base64"

'#define wszURI_XMLNS_DIGSIG_SHA1                 L"http://www.w3.org/2000/09/xmldsig#sha1"
'#define wszURI_XMLNS_DIGSIG_SHA256               L"http://www.w3.org/2001/04/xmlenc#sha256"
'#define wszURI_XMLNS_DIGSIG_SHA384               L"http://www.w3.org/2001/04/xmldsig-more#sha384"
'#define wszURI_XMLNS_DIGSIG_SHA512               L"http://www.w3.org/2001/04/xmlenc#sha512"
$wszURI_XMLNS_DIGSIG_SHA1                 = "http://www.w3.org/2000/09/xmldsig#sha1"
$wszURI_XMLNS_DIGSIG_SHA256               = "http://www.w3.org/2001/04/xmlenc#sha256"
$wszURI_XMLNS_DIGSIG_SHA384               = "http://www.w3.org/2001/04/xmldsig-more#sha384"
$wszURI_XMLNS_DIGSIG_SHA512               = "http://www.w3.org/2001/04/xmlenc#sha512"

'#define wszURI_XMLNS_DIGSIG_RSA_SHA1             L"http://www.w3.org/2000/09/xmldsig#rsa-sha1"
'#define wszURI_XMLNS_DIGSIG_DSA_SHA1             L"http://www.w3.org/2000/09/xmldsig#dsa-sha1"
$wszURI_XMLNS_DIGSIG_RSA_SHA1             = "http://www.w3.org/2000/09/xmldsig#rsa-sha1"
$wszURI_XMLNS_DIGSIG_DSA_SHA1             = "http://www.w3.org/2000/09/xmldsig#dsa-sha1"

'#define wszURI_XMLNS_DIGSIG_RSA_SHA256           L"http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"
'#define wszURI_XMLNS_DIGSIG_RSA_SHA384           L"http://www.w3.org/2001/04/xmldsig-more#rsa-sha384"
'#define wszURI_XMLNS_DIGSIG_RSA_SHA512           L"http://www.w3.org/2001/04/xmldsig-more#rsa-sha512"
$wszURI_XMLNS_DIGSIG_RSA_SHA256           = "http://www.w3.org/2001/04/xmldsig-more#rsa-sha256"
$wszURI_XMLNS_DIGSIG_RSA_SHA384           = "http://www.w3.org/2001/04/xmldsig-more#rsa-sha384"
$wszURI_XMLNS_DIGSIG_RSA_SHA512           = "http://www.w3.org/2001/04/xmldsig-more#rsa-sha512"

'#define wszURI_XMLNS_DIGSIG_ECDSA_SHA1           L"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1"
'#define wszURI_XMLNS_DIGSIG_ECDSA_SHA256         L"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256"
'#define wszURI_XMLNS_DIGSIG_ECDSA_SHA384         L"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha384"
'#define wszURI_XMLNS_DIGSIG_ECDSA_SHA512         L"http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512"
$wszURI_XMLNS_DIGSIG_ECDSA_SHA1           = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha1"
$wszURI_XMLNS_DIGSIG_ECDSA_SHA256         = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha256"
$wszURI_XMLNS_DIGSIG_ECDSA_SHA384         = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha384"
$wszURI_XMLNS_DIGSIG_ECDSA_SHA512         = "http://www.w3.org/2001/04/xmldsig-more#ecdsa-sha512"

'#define wszURI_XMLNS_DIGSIG_HMAC_SHA1            L"http://www.w3.org/2000/09/xmldsig#hmac-sha1"
'#define wszURI_XMLNS_DIGSIG_HMAC_SHA256          L"http://www.w3.org/2001/04/xmldsig-more#hmac-sha256"
'#define wszURI_XMLNS_DIGSIG_HMAC_SHA384          L"http://www.w3.org/2001/04/xmldsig-more#hmac-sha384"
'#define wszURI_XMLNS_DIGSIG_HMAC_SHA512          L"http://www.w3.org/2001/04/xmldsig-more#hmac-sha512"
$wszURI_XMLNS_DIGSIG_HMAC_SHA1            = "http://www.w3.org/2000/09/xmldsig#hmac-sha1"
$wszURI_XMLNS_DIGSIG_HMAC_SHA256          = "http://www.w3.org/2001/04/xmldsig-more#hmac-sha256"
$wszURI_XMLNS_DIGSIG_HMAC_SHA384          = "http://www.w3.org/2001/04/xmldsig-more#hmac-sha384"
$wszURI_XMLNS_DIGSIG_HMAC_SHA512          = "http://www.w3.org/2001/04/xmldsig-more#hmac-sha512"

'#define wszURI_CANONICALIZATION_C14N             L"http://www.w3.org/TR/2001/REC-xml-c14n-20010315"
'#define wszURI_CANONICALIZATION_C14NC            L"http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments"
'#define wszURI_CANONICALIZATION_EXSLUSIVE_C14N   L"http://www.w3.org/2001/10/xml-exc-c14n#"
'#define wszURI_CANONICALIZATION_EXSLUSIVE_C14NC  L"http://www.w3.org/2001/10/xml-exc-c14n#WithComments"
$wszURI_CANONICALIZATION_C14N             = "http://www.w3.org/TR/2001/REC-xml-c14n-20010315"
$wszURI_CANONICALIZATION_C14NC            = "http://www.w3.org/TR/2001/REC-xml-c14n-20010315#WithComments"
$wszURI_CANONICALIZATION_EXSLUSIVE_C14N   = "http://www.w3.org/2001/10/xml-exc-c14n#"
$wszURI_CANONICALIZATION_EXSLUSIVE_C14NC  = "http://www.w3.org/2001/10/xml-exc-c14n#WithComments"

'#define wszURI_TRANSFORM_XPATH                   L"http://www.w3.org/TR/1999/REC-xpath-19991116"
'#define wszURI_XMLNS_TRANSFORM_BASE64            L"http://www.w3.org/2000/09/xmldsig#base64"
'#define wszURI_XMLNS_TRANSFORM_ENVELOPED         L"http://www.w3.org/2000/09/xmldsig#enveloped-signature"
$wszURI_TRANSFORM_XPATH                   = "http://www.w3.org/TR/1999/REC-xpath-19991116"
$wszURI_XMLNS_TRANSFORM_BASE64            = "http://www.w3.org/2000/09/xmldsig#base64"
$wszURI_XMLNS_TRANSFORM_ENVELOPED         = "http://www.w3.org/2000/09/xmldsig#enveloped-signature"

'/****************************************************************************
' Limits

'    reduce Integer overflows and security threats surface

'****************************************************************************/

'// Encoded data may not exceed 2 Gb
%CRYPT_XML_BLOB_MAX              = &H7FFFFFF8???

'// Id may not exceed 256 characters
%CRYPT_XML_ID_MAX                = 256

'// URI may not exceed 8K characters
%CRYPT_XML_URI_MAX               = 8*1024

'// Maximum number of signature elements per document, by default
%CRYPT_XML_SIGNATURES_MAX        = 16

'// Maximum number of transforms per reference
%CRYPT_XML_TRANSFORM_MAX         = 16

%CRYPT_XML_SIGNATURE_VALUE_MAX   = 2048

%CRYPT_XML_DIGEST_VALUE_MAX      = 128

'// Maximum number of Object elements per Signature
%CRYPT_XML_OBJECTS_MAX           = 256

'// Maximum number of Reference elements
%CRYPT_XML_REFERENCES_MAX        = &H7FF8???


'/****************************************************************************
' Error Codes

'****************************************************************************/

%CRYPT_XML_E_BASE                = &H80092100&

'// The value is too large
%CRYPT_XML_E_LARGE               = &H80092101&

'// Too many transforms
%CRYPT_XML_E_TOO_MANY_TRANSFORMS = &H80092102&

'// Unsupported XML Encoding
%CRYPT_XML_E_ENCODING            = &H80092103&

'// Unsupported XML Algorithm
%CRYPT_XML_E_ALGORITHM           = &H80092104&

'// Unsupported Transform
%CRYPT_XML_E_TRANSFORM           = &H80092105&

'// Invalid handle
%CRYPT_XML_E_HANDLE              = &H80092106&

'// Invalid operation
%CRYPT_XML_E_OPERATION           = &H80092107&

'// Unable to resolve Reference
%CRYPT_XML_E_UNRESOLVED_REFERENCE = &H80092108&

'// Invalid digest value
%CRYPT_XML_E_INVALID_DIGEST      = &H80092109&

'// Invalid signature value
%CRYPT_XML_E_INVALID_SIGNATURE   = &H8009210A&

'// Unable to create or calculate the hash
%CRYPT_XML_E_HASH_FAILED         = &H8009210B&

'// Cryptographic signature operation failed
%CRYPT_XML_E_SIGN_FAILED         = &H8009210C&

'// Signature verification failed
%CRYPT_XML_E_VERIFY_FAILED       = &H8009210D&

'// Too many signatures
%CRYPT_XML_E_TOO_MANY_SIGNATURES = &H8009210E&

'// Invalid key value
%CRYPT_XML_E_INVALID_KEYVALUE    = &H8009210F&

'// Unexpected XML
%CRYPT_XML_E_UNEXPECTED_XML      = &H80092110&

'// Unable to find signer's key
%CRYPT_XML_E_SIGNER              = &H80092111&

'// Non-unique Id attribute found
%CRYPT_XML_E_NON_UNIQUE_ID       = &H80092112&

%CRYPT_XML_E_LAST                = &H80092112&


'/****************************************************************************
' Global Flags

'****************************************************************************/

'// Serialization ensures mutual exclusion when two or more threads attempt
'// to simultaneously accept a CryptXml object, or memory.
'// There is a small performance cost to serialization,
'// but it must be used whenever multiple threads access a CryptXml object.
'// Set this flag to inhibit serialization.

%CRYPT_XML_FLAG_NO_SERIALIZE                     = &H80000000???

'// CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT flag is applicable to:
'//   CryptXmlOpenToEncode
'//   CryptXmlOpenToDecode
'// When this flag is set, then CRYPT_XML_OBJECT structure will always
'// return encoded <Object> element. See CRYPT_XML_OBJECT for details.

%CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT     = &H40000000???

'// CRYPT_XML_FLAG_ENFORCE_ID_NCNAME_FORMAT flag is applicable to:
'//   CryptXmlOpenToEncode
'//   CryptXmlOpenToDecode
'// When this flag is set, then Id attibutes must conform to
'// NCName syntax (http://www.w3.org/TR/1999/REC-xml-names-19990114/#NT-NCName).
'// By default, CryptXml accepts any valid string for Id attribute.

%CRYPT_XML_FLAG_ENFORCE_ID_NCNAME_FORMAT         = &H20000000???

'// CRYPT_XML_FLAG_DISABLE_EXTENSIONS flag is applicable to:
'//   CryptXmlOpenToEncode
'//   CryptXmlOpenToDecode
'//   CryptXmlEnumAlgorithmInfo
'// When this flag is set only default implementations for signature and
'// digest  will be utilized and no registered Extensions will be loaded.

%CRYPT_XML_FLAG_DISABLE_EXTENSIONS               = &H10000000???

'// CRYPT_XML_FLAG_ENFORCE_ID_NAME_FORMAT flag is applicable to:
'//   CryptXmlOpenToEncode
'//   CryptXmlOpenToDecode
'// When this flag is set, then Id attibutes must conform to
'// Name syntax (http://www.w3.org/TR/2000/WD-xml-2e-2000814#idref).
'// By default, CryptXml accepts any valid string for Id attribute.

%CRYPT_XML_FLAG_ENFORCE_ID_NAME_FORMAT           = &H08000000???


'/****************************************************************************
' CRYPT_XML_CHARSET

'****************************************************************************/
' enum CRYPT_XML_CHARSET
' //
' // CRYPT_XML_CHARSET_AUTO is supported only in CryptXmlOpenToDecode mode.
' // The encoded XML character set will be determined by the parser from
' // the XML declaration or the best guess on the characters.
%CRYPT_XML_CHARSET_AUTO        = 0???
%CRYPT_XML_CHARSET_UTF8        = 1???
%CRYPT_XML_CHARSET_UTF16LE     = 2???
%CRYPT_XML_CHARSET_UTF16BE     = 3???

'/****************************************************************************
' CRYPT_XML_BLOB

'****************************************************************************/
' // Size = 12 bytes
TYPE CRYPT_XML_BLOB DWORD
   dwCharset AS DWORD
   cbData    AS DWORD      ' ULONG
   pbData    AS BYTE PTR   ' BYTE *
END TYPE

'/****************************************************************************
' CRYPT_XML_DATA_BLOB

'****************************************************************************/
' // Size = 8 bytes
TYPE CRYPT_XML_DATA_BLOB DWORD
   cbData AS DWORD      ' ULONG
   pbData AS BYTE PTR   ' BYTE *
END TYPE


'/****************************************************************************
' CRYPT_XML_PROPERTY

'    CRYPT_XML_PROPERTY_MAX_HEAP_SIZE
'        Specifies the maximum heap size to be used by XML layer.
'        This property is also applied for intermediate buffers used to parse
'        or construct XML parts.
'        By default, the limit is equal to CRYPT_XML_BLOB_MAX.

'    CRYPT_XML_PROPERTY_SIGNATURE_LOCATION
'        Specifies the location in XML document where the Signature will be
'        created. The following formats are supported:
'            #id  - the Id Attribute of the element to insert the Signature;
'            /a/b/c - the absolute path of the element to insert the Signature;

'    CRYPT_XML_PROPERTY_MAX_SIGNATURES
'        Specifies the maximum number of <Signature> elements when
'        parsing an XML document.
'        This property overrides the default CRYPT_XML_SIGNATURES_MAX value.

'    CRYPT_XML_PROPERTY_DOC_DECLARATION
'        Specifies whether to write an XML document declaration.
'        This property is used with CryptXmlEncode. The default property is TRUE.

'    CRYPT_XML_PROPERTY_XML_OUTPUT_CHARSET
'        Specifies an encoding charset of XML fragments for custom elements.
'        This property is used with CryptXmlOpenToDecode.
'        The default charset is inherited from the opened document.

' NOTE: If a property value is defined as a pointer to data,
'       then the pointer must be valid for the entire period of signature
'       operation.

'****************************************************************************/
' enum CRYPT_XML_PROPERTY_ID
%CRYPT_XML_PROPERTY_MAX_HEAP_SIZE      = 1???   ' // ULONG, sizeof(ULONG)
%CRYPT_XML_PROPERTY_SIGNATURE_LOCATION = 2???   ' // LPCWSTR*, sizeof(LPCWSTR)
%CRYPT_XML_PROPERTY_MAX_SIGNATURES     = 3???   ' // ULONG, sizeof(ULONG)
%CRYPT_XML_PROPERTY_DOC_DECLARATION    = 4???   ' // BOOL, sizeof(BOOL)
%CRYPT_XML_PROPERTY_XML_OUTPUT_CHARSET = 5???   ' // CRYPT_XML_CHARSET, sizeof(CRYPT_XML_CHARSET)

' // Size = 12 bytes
TYPE CRYPT_XML_PROPERTY DWORD
   dwPropId AS DWORD   ' CRYPT_XML_PROPERTY_ID
   pvValue  AS DWORD   ' const void*
   cbValue  AS DWORD   ' ULONG
END TYPE

'/****************************************************************************
' PFN_CRYPT_XML_WRITE_CALLBACK

' Callback function used to write data.

' pvCallbackState
'    [in] An application defined argument for the callback.

' pbData
'    [in] Pointer to a block of data to be written.

' cbData
'    Size, in bytes, of the block of data at pbData.

'****************************************************************************/
'typedef
'__success( return == 0 )
'HRESULT
'(CALLBACK* PFN_CRYPT_XML_WRITE_CALLBACK)(
'    __inout         void                *pvCallbackState,
'    __in_bcount( cbData )
'                    const BYTE          *pbData,
'                    ULONG               cbData
'    );

'FUNCTION CRYPT_XML_WRITE_CALLBACK ( _
'   BYVAL pvCallbackState AS DWORD _                     ' __inout void *pvCallbackState
' , BYVAL pbData AS BYTE PTR _                           ' __in_bcount(cbData) const BYTE *pbData
' , BYVAL cbData AS DWORD _                              ' __in ULONG cbData
' ) AS LONG                                              ' HRESULT

'/****************************************************************************
' PFN_CRYPT_XML_DATA_PROVIDER_READ

' Callback function used to provide data.

' pvCallbackState
'    [in] An application defined argument for the callback.

' pbData
'    [out] Pointer to the buffer that receives the data.

' cbData
'    [in] Specifies the number of bites to read.

' pcbRead
'    [out] A pointer to the variable that receives the number of bytes read.

'Return Values:

'    The PFN_CRYPT_XML_DATA_PROVIDER callback returns when one of the
'    following conditions occurs:
'    - A write operation completes on the write end of the data provider.
'    - The number of bytes requested is read.
'    - An error occurs.

' If the function succeeds, the return value is NO_ERROR.
' If the function fails, the error code is determined by HRESULT.
' If the *pcbRead value is 0, then there is no more data available.

'Remarks:

' The callback shall not return unless number of bytes specified in cbData
' is available, or it's the last block of data.

'****************************************************************************/
'typedef
'__success( return == 0 )
'HRESULT
'(CALLBACK *PFN_CRYPT_XML_DATA_PROVIDER_READ)(
'    __inout         void                *pvCallbackState,
'    __out_bcount_part( cbData, *pcbRead )
'                    BYTE                *pbData,
'    __in            ULONG               cbData,
'    __out_range( 0, cbData )
'                    ULONG               *pcbRead
'    );

'FUNCTION CRYPT_XML_DATA_PROVIDER_READ ( _
'   BYVAL pvCallbackState AS DWORD _                     ' __inout void *pvCallbackState
' , BYVAL pbData AS BYTE PTR _                           ' __in_bcount(cbData) const BYTE *pbData
' , BYVAL cbData AS DWORD _                              ' __in ULONG cbData
' , BYREF pcbRead AS DWORD _                             ' __out ULONG pcbRead
' ) AS LONG                                              ' HRESULT

'/****************************************************************************
' PFN_CRYPT_XML_DATA_PROVIDER_CLOSE

' Callback function used to release the data provider.

' pvCallbackState
'    [in] An application defined argument for the callback.

'****************************************************************************/
'typedef
'__success( return == 0 )
'HRESULT
'(CALLBACK *PFN_CRYPT_XML_DATA_PROVIDER_CLOSE)(
'    __inout         void                *pvCallbackState
'    );

'FUNCTION CRYPT_XML_DATA_PROVIDER_CLOSE ( _
'   BYVAL pvCallbackState AS DWORD _                     ' __inout void *pvCallbackState
' ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CRYPT_XML_DATA_PROVIDER

' pvCallbackState
'    [in] An application defined argument to be passed to
'    the pfnRead and pfnClose callbacks.

' cbBufferSize
'    [in] Specifies the size of data provider's buffer,
'    that can be 0 if the size does not matter or can't be determined by the provider.
'    This value is used by a caller of pfnRead to determine a size of the receiving buffer.

' pfnRead
'    [in] Callback function used to read data.

' pfnClose
'    [in] Callback function used to release the data provider.
'    The caller must always release the data provider after using it,
'    even when the read operation failed.

'****************************************************************************/
' // Size = 16 bytes
TYPE CRYPT_XML_DATA_PROVIDER DWORD
   pvCallbackState AS DWORD   ' void *
   cbBufferSize    AS DWORD   ' ULONG
   pfnRead         AS DWORD   ' PFN_CRYPT_XML_DATA_PROVIDER_READ
   pfnClose        AS DWORD   ' PFN_CRYPT_XML_DATA_PROVIDER_CLOSE
END TYPE

'/****************************************************************************
' PFN_CRYPT_XML_CREATE_TRANSFORM

' Callback function used to create transform routine.

' pTransform
'    [in] Specifies the Transform to apply.

' pProviderIn
'    [in] Address of the data provider to be used as input for transform.

' pfpProviderOut
'    [out] Address of the variable that receives a pointer to
'    the transform's data provider.

' NOTE: In the transform chain, the output of the trasnform is the input of the next one.

' The pProviderOut implementation is responsible to call pProviderIn->pfnClose
' to relase the input provider. Usually it's implemented in its own pfnClose.

'****************************************************************************/
'typedef
'__success( return == 0 )
'HRESULT
'(CALLBACK *PFN_CRYPT_XML_CREATE_TRANSFORM)(
'    __in            const CRYPT_XML_ALGORITHM *pTransform,
'    __in            CRYPT_XML_DATA_PROVIDER *pProviderIn,
'    __out           CRYPT_XML_DATA_PROVIDER *pProviderOut
'    );

'FUNCTION CRYPT_XML_CREATE_TRANSFORM ( _
'   BYREF pTransform AS CRYPT_XML_ALGORITHM _            ' __in const CRYPT_XML_ALGORITHM *pTransform
' , BYREF pProviderIn AS CRYPT_XML_DATA_PROVIDER _       ' __in CRYPT_XML_DATA_PROVIDER *pProviderIn
' , BYREF pProviderOut AS CRYPT_XML_DATA_PROVIDER _      ' __in CRYPT_XML_DATA_PROVIDER *pProviderOut
' ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CRYPT_XML_STATUS

'  Structure contains information about signature validation status,
'  summary status information about a SignedInfo, or summary information
'  status about an array of Reference.

' cbSize
'    Size of this structure.

' dwErrorStatus
'    Error flags.

' dwInfoStatus
'    Informational flags.

'****************************************************************************/
' // Size = 12 bytes
TYPE CRYPT_XML_STATUS DWORD
   cbSize        AS DWORD   ' ULONG
   dwErrorStatus AS DWORD   ' DWORD
   dwInfoStatus  AS DWORD   ' DWORD
END TYPE

%CRYPT_XML_STATUS_NO_ERROR                           = &H00000000???

'//===========================================================================
'// Error Status
'//===========================================================================

'// One of the References could not be resolved to digest the data
%CRYPT_XML_STATUS_ERROR_NOT_RESOLVED                     = &H00000001???

'// Digest value was not verified successfully
%CRYPT_XML_STATUS_ERROR_DIGEST_INVALID                   = &H00000002???

'// One of the algorithm URIs specified in XML is not supported
%CRYPT_XML_STATUS_ERROR_NOT_SUPPORTED_ALGORITHM          = &H00000004???

'// One of the transform URIs specified in XML is not supported
%CRYPT_XML_STATUS_ERROR_NOT_SUPPORTED_TRANSFORM          = &H00000008???

'// Signature value was not verified successfully
%CRYPT_XML_STATUS_ERROR_SIGNATURE_INVALID                = &H00010000???

'// Unable to parse the KeyInfo element
%CRYPT_XML_STATUS_ERROR_KEYINFO_NOT_PARSED               = &H00020000???

'//===========================================================================
'// Info Status
'//===========================================================================

'// The Reference URI points to an internal element in XML
'// and can be resolved automatically
%CRYPT_XML_STATUS_INTERNAL_REFERENCE                     = &H00000001???

'// The KeyValue element parsed and a key handle imported successfully
%CRYPT_XML_STATUS_KEY_AVAILABLE                          = &H00000002???

'// The reference is being digetsed
%CRYPT_XML_STATUS_DIGESTING                              = &H00000004???

'// The digest value successfully verified
%CRYPT_XML_STATUS_DIGEST_VALID                           = &H00000008???

'// The signature value successfully verified
%CRYPT_XML_STATUS_SIGNATURE_VALID                        = &H00010000???

'// The document is opened to encode
%CRYPT_XML_STATUS_OPENED_TO_ENCODE                       = &H80000000???


'/****************************************************************************
' CRYPT_XML_ALGORITHM

' cbSize
'    Size of this structure.

' wszAlgorithm
'    Specifies the Algorithm attribute.
'    This parameter must be NULL, when Encoded is provided by an application.

' Encoded
'    [optional] Contains the XML encoded element.
'    This value is set only when ANY element is present.

'    <element name="CanonicalizationMethod" type="ds:CanonicalizationMethodType"/>
'    <complexType name="CanonicalizationMethodType" mixed="true">
'     <sequence>
'       <any namespace="##any" minOccurs="0" maxOccurs="unbounded"/>
'       <!-- (0,unbounded) elements from (1,1) namespace -->
'     </sequence>
'     <attribute name="Algorithm" type="anyURI" use="required"/>
'    </complexType>

'    <element name="SignatureMethod" type="ds:SignatureMethodType"/>
'    <complexType name="SignatureMethodType" mixed="true">
'     <sequence>
'       <element name="HMACOutputLength" minOccurs="0" type="ds:HMACOutputLengthType"/>
'       <any namespace="##other" minOccurs="0" maxOccurs="unbounded"/>
'       <!-- (0,unbounded) elements from (1,1) external namespace -->
'      </sequence>
'    <attribute name="Algorithm" type="anyURI" use="required"/>
'    </complexType>

'   <element name="DigestMethod" type="ds:DigestMethodType"/>
'   <complexType name="DigestMethodType" mixed="true">
'     <sequence>
'       <any namespace="##other" processContents="lax" minOccurs="0" maxOccurs="unbounded"/>
'     </sequence>
'     <attribute name="Algorithm" type="anyURI" use="required"/>
'   </complexType>

'    <element name="Transform" type="ds:TransformType"/>
'    <complexType name="TransformType" mixed="true">
'     <choice minOccurs="0" maxOccurs="unbounded">
'       <any namespace="##other" processContents="lax"/>
'       <!-- (1,1) elements from (0,unbounded) namespaces -->
'       <element name="XPath" type="string"/>
'     </choice>
'     <attribute name="Algorithm" type="anyURI" use="required"/>
'    </complexType>

'****************************************************************************/
' // Size = 20 bytes
TYPE CRYPT_XML_ALGORITHM DWORD
   cbSize       AS DWORD            ' ULONG
   wszAlgorithm AS WSTRINGZ PTR     ' LPCWSTR
   Encoded      AS CRYPT_XML_BLOB   ' CRYPT_XML_BLOB
END TYPE

'/****************************************************************************
' CRYPT_XML_TRANSFORM_INFO

' cbSize
'    Size of this structure.

' wszAlgorithm
'    Specifies the Algorithm attribute.

' cbBufferSize
'    Maximum buffer size for transformed data.
'    This value can be 0 if the size can't be determined at the initialization time.

' dwFlags
'    The following flags are supported
'            CRYPT_XML_TRANSFORM_ON_STREAM
'            CRYPT_XML_TRANSFORM_ON_NODESET
'            CRYPT_XML_TRANSFORM_URI_QUERY_STRING

' pfnCreateTransform
'    [callback] Pointer to a function to create a transform.

'****************************************************************************/
' // Size = 20 bytes
TYPE CRYPT_XML_TRANSFORM_INFO DWORD
   cbSize             AS DWORD          ' ULONG
   wszAlgorithm       AS WSTRINGZ PTR   ' LPCWSTR
   cbBufferSize       AS DWORD          ' ULONG
   dwFlags            AS DWORD          ' DWORD
   pfnCreateTransform AS DWORD          ' PFN_CRYPT_XML_CREATE_TRANSFORM
END TYPE

'//
'// Informational flag, specifies that transform is implemented
'// on a stream of bytes

%CRYPT_XML_TRANSFORM_ON_STREAM           = &H00000001???

'//
'// Informational flag, specifies that transform is implemented
'// on XML node set

%CRYPT_XML_TRANSFORM_ON_NODESET          = &H00000002???

'//
'// In some cases, the URI may contain additional information
'// in the QueryString after the & sign.
'// When this flag is set, the URI comparisson will be performed on the core URI
'// without the QueryString

%CRYPT_XML_TRANSFORM_URI_QUERY_STRING    = &H00000004???

'/****************************************************************************
' CRYPT_XML_TRANSFORM_CHAIN_CONFIG

' cTransformInfo
'    Count of elements in rgTransformInfo.

' rgTransformInfo
'    Array of  PCRYPT_XML_TRANSFORM_INFO

' ****************************************************************************/
' // Size = 12 bytes
TYPE CRYPT_XML_TRANSFORM_CHAIN_CONFIG DWORD
   cbSize           AS DWORD                          ' ULONG
   cTransformInfo   AS DWORD                          ' ULONG
   rgpTransformInfo AS CRYPT_XML_TRANSFORM_INFO PTR   ' PCRYPT_XML_TRANSFORM_INFO *
END TYPE

'/****************************************************************************
' CRYPT_XML_KEY_DSA_KEY_VALUE

' Encapsulates DSA key value.

'  P
'    BLOB containing DSA key P parameter.

'  Q
'    BLOB containing DSA key Q parameter.

'  G
'    BLOB containing DSA key G parameter.

'  Y
'    BLOB containing DSA key Y parameter.

'  J
'    BLOB containing DSA key J parameter.

'  Seed
'    BLOB containing DSA key seed.

'  Counter
'    BLOB containing DSA key counter.

'****************************************************************************/
' // Size = 56 bytes
TYPE CRYPT_XML_KEY_DSA_KEY_VALUE DWORD
   P       AS CRYPT_XML_DATA_BLOB
   Q       AS CRYPT_XML_DATA_BLOB
   G       AS CRYPT_XML_DATA_BLOB
   Y       AS CRYPT_XML_DATA_BLOB
   J       AS CRYPT_XML_DATA_BLOB
   Seed    AS CRYPT_XML_DATA_BLOB
   Counter AS CRYPT_XML_DATA_BLOB
END TYPE

'/****************************************************************************
' CRYPT_XML_KEY_ECDSA_KEY_VALUE

' Encapsulates ECDSA key value.

'  wszNamedCurve
'    Specifies named curve as a Unicode string in URN format,
'    for example "urn:oid:1.2.3.4"

'  X
'    BLOB containing ECDSA key X parameter.

'  Y
'    BLOB containing ECDSA key Y parameter.

'  ExplicitPara
'    [optional] XML part containing the <ExplicitParams> element.

' NOTE:
'    CryptXml does not support explicit parameters due to CNG ECDSA key support.

'****************************************************************************/
' // Size = 32 bytes
TYPE CRYPT_XML_KEY_ECDSA_KEY_VALUE DWORD
   wszNamedCurve AS WSTRINGZ PTR          ' // URN Format urn:oid:1.2.3.4
   X             AS CRYPT_XML_DATA_BLOB
   Y             AS CRYPT_XML_DATA_BLOB
   ExplicitPara  AS CRYPT_XML_BLOB        ' // Encoded <ExplicitParams>
END TYPE

'/****************************************************************************
' CRYPT_XML_KEY_RSA_KEY_VALUE

' Encapsulates RSA key value.

'  Modulus
'    BLOB containing RSA key modulus.

'  Exponent
'    BLOB containing RSA key exponent.

'****************************************************************************/
' // Size = 16 bytes
TYPE CRYPT_XML_KEY_RSA_KEY_VALUE DWORD
   Modulus  AS CRYPT_XML_DATA_BLOB
   Exponent AS CRYPT_XML_DATA_BLOB
END TYPE

'/****************************************************************************
' CRYPT_XML_KEY_VALUE

' Represents the KeyValueType choice in the <KeyValue> element.

' dwType
'    Indicates the union variant used for the key value.

'    This can be one of the following values:
'        CRYPT_XML_KEY_VALUE_TYPE_DSA
'        CRYPT_XML_KEY_VALUE_TYPE_RSA
'        CRYPT_XML_KEY_VALUE_TYPE_ECDSA
'        CRYPT_XML_KEY_VALUE_TYPE_CUSTOM

'  DSAKeyValue
'    CRYPT_XML_KEY_DSA_KEY_VALUE representing the DSA key

'  RSAKeyValue
'    CRYPT_XML_KEY_RSA_KEY_VALUE representing the RSA key

'  ECDSAKeyValue
'    CRYPT_XML_KEY_ECDSA_KEY_VALUE representing the ECDSA key

'  Custom
'    XML part containing unsupported elements of the <KeyValue> element.

'Schema:

'     <element name="KeyValue" type="ds:KeyValueType"/>
'       <complexType name="KeyValueType" mixed="true">
'        <choice>
'          <element ref="ds:DSAKeyValue"/>
'          <element ref="ds:RSAKeyValue"/>
'          <any namespace="##other" processContents="lax"/>
'        </choice>
'       </complexType>

'****************************************************************************/
' // Size = 56 bytes
UNION CRYPT_XML_KEY_VALUE_UNION DWORD
   DSAKeyValue   AS CRYPT_XML_KEY_DSA_KEY_VALUE
   RSAKeyValue   AS CRYPT_XML_KEY_RSA_KEY_VALUE
   ECDSAKeyValue AS CRYPT_XML_KEY_ECDSA_KEY_VALUE
   Custom        AS CRYPT_XML_BLOB                  ' // XML Encoded element
END UNION

' // Size = 60 bytes
TYPE CRYPT_XML_KEY_VALUE DWORD
   dwType AS DWORD   ' DWORD
   CRYPT_XML_KEY_VALUE_UNION
END TYPE

%CRYPT_XML_KEY_VALUE_TYPE_DSA    = &H00000001???
%CRYPT_XML_KEY_VALUE_TYPE_RSA    = &H00000002???
%CRYPT_XML_KEY_VALUE_TYPE_ECDSA  = &H00000003???
%CRYPT_XML_KEY_VALUE_TYPE_CUSTOM = &H00000004???

'/****************************************************************************
' CRYPT_XML_ISSUER_SERIAL

'   <complexType name="X509IssuerSerialType">
'     <sequence>
'       <element name="X509IssuerName" type="string"/>
'       <element name="X509SerialNumber" type="integer"/>
'     </sequence>
'   </complexType>

'****************************************************************************/
' // Size = 8 bytes
TYPE CRYPT_XML_ISSUER_SERIAL DWORD
   wszIssuer AS WSTRINGZ PTR   ' LPCWSTR
   wszSerial AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

'/****************************************************************************
' CRYPT_XML_X509DATA_ITEM

' Represents the X509DataType choice in the <X509Data> element.

' dwType
'    Indicates the union variant used for the X509Data.

'    This can be one of the following values:
'        CRYPT_XML_X509DATA_TYPE_ISSUER_SERIAL
'        CRYPT_XML_X509DATA_TYPE_SKI
'        CRYPT_XML_X509DATA_TYPE_SUBJECT_NAME
'        CRYPT_XML_X509DATA_TYPE_CERTIFICATE
'        CRYPT_XML_X509DATA_TYPE_CRL
'        CRYPT_XML_X509DATA_TYPE_CUSTOM

'  IssuerSerial
'    CRYPT_XML_ISSUER_SERIAL representing the <X509IssuerSerial> element

'  SKI
'    BLOB containing the <X509SKI> element

'  wszSubjectName
'    Subject name as a Unicode string

'  Certificate
'    BLOB containing X.509 certificate

'  CRL
'    BLOB containing X.509 certificate revocation list

'  Custom
'    XML part containing unsupported elements of the <X509Data> element.

'****************************************************************************/

' // Size =  12 bytes
UNION CRYPT_XML_X509DATA_ITEM_UNION DWORD
   IssuerSerial   AS CRYPT_XML_ISSUER_SERIAL
   SKI            AS CRYPT_XML_DATA_BLOB
   wszSubjectName AS WSTRINGZ PTR              ' LPCWSTR
   Certificate    AS CRYPT_XML_DATA_BLOB
   CRL            AS CRYPT_XML_DATA_BLOB
   Custom         AS CRYPT_XML_BLOB            ' // XML Encoded element
END UNION

' // Size = 16 bytes
TYPE CRYPT_XML_X509DATA_ITEM DWORD
   dwType AS DWORD   ' DWORD
   CRYPT_XML_X509DATA_ITEM_UNION
END TYPE

%CRYPT_XML_X509DATA_TYPE_ISSUER_SERIAL   = &H00000001???
%CRYPT_XML_X509DATA_TYPE_SKI             = &H00000002???
%CRYPT_XML_X509DATA_TYPE_SUBJECT_NAME    = &H00000003???
%CRYPT_XML_X509DATA_TYPE_CERTIFICATE     = &H00000004???
%CRYPT_XML_X509DATA_TYPE_CRL             = &H00000005???
%CRYPT_XML_X509DATA_TYPE_CUSTOM          = &H00000006???

'/****************************************************************************
' CRYPT_XML_X509DATA

'  Represents the sequence of choices in the <X509Data> element.

'  cX509Data
'    Number of elements in rgX509Data

'  rgX509Data
'    Array of CRYPT_XML_X509DATA_ITEM

'Schema:

'   <element name="X509Data" type="ds:X509DataType"/>
'   <complexType name="X509DataType">
'     <sequence maxOccurs="unbounded">
'       <choice>
'         <element name="X509IssuerSerial" type="ds:X509IssuerSerialType"/>
'         <element name="X509SKI" type="base64Binary"/>
'         <element name="X509SubjectName" type="string"/>
'         <element name="X509Certificate" type="base64Binary"/>
'         <element name="X509CRL" type="base64Binary"/>
'         <any namespace="##other" processContents="lax"/>
'       </choice>
'     </sequence>
'   </complexType>

'****************************************************************************/
' // Size = 8 bytes
TYPE CRYPT_XML_X509DATA DWORD
   cX509Data  AS DWORD   ' UINT
   rgX509Data AS CRYPT_XML_X509DATA_ITEM PTR   ' CRYPT_XML_X509DATA_ITEM *
END TYPE

'/****************************************************************************
' CRYPT_XML_KEY_INFO_ITEM

' Represents the KeyInfoType choice in the <KeyInfo> element.

' dwType
'    Indicates the union variant used for the key info.

'    This can be one of the following values:
'        CRYPT_XML_KEYINFO_TYPE_KEYNAME
'        CRYPT_XML_KEYINFO_TYPE_KEYVALUE
'        CRYPT_XML_KEYINFO_TYPE_RETRIEVAL
'        CRYPT_XML_KEYINFO_TYPE_X509DATA
'        CRYPT_XML_KEYINFO_TYPE_CUSTOM

'  wszKeyName
'    Key name is a Unicode string

'  KeyValue
'    CRYPT_XML_KEY_VALUE representing the <KeyValue> element

'  RetrievalMethod
'    BLOB containing the <RetrievalMethod> element

'  X509Data
'    CRYPT_XML_X509DATA representing the <X509Data> element

'  Custom
'    XML part containing unsupported elements of the key info.

'****************************************************************************/

' // Size = 60 bytes
UNION CRYPT_XML_KEY_INFO_ITEM_UNION
   wszKeyName      AS WSTRINGZ PTR         ' LPCWSTR
   KeyValue        AS CRYPT_XML_KEY_VALUE
   RetrievalMethod AS CRYPT_XML_BLOB       ' // XML Encoded element
   X509Data        AS CRYPT_XML_X509DATA
   Custom          AS CRYPT_XML_BLOB       ' // XML Encoded element
END UNION

' // Size = 64 bytes
TYPE CRYPT_XML_KEY_INFO_ITEM DWORD
   dwType AS DWORD   ' DWORD
   CRYPT_XML_KEY_INFO_ITEM_UNION
END TYPE

%CRYPT_XML_KEYINFO_TYPE_KEYNAME      = &H00000001???
%CRYPT_XML_KEYINFO_TYPE_KEYVALUE     = &H00000002???
%CRYPT_XML_KEYINFO_TYPE_RETRIEVAL    = &H00000003???
%CRYPT_XML_KEYINFO_TYPE_X509DATA     = &H00000004???
%CRYPT_XML_KEYINFO_TYPE_CUSTOM       = &H00000005???

'/****************************************************************************
' CRYPT_XML_KEY_INFO

' Encapsulates the <KeyInfo> which is an optional element that enables
' the recipient(s) to obtain the key needed to validate the signature.

' cbSize
'    Size of this structure.

' wszId
'    [optional] Specifies the ID attribute.

' cKeyInfo
'    Number of elements in rgKeyInfo

' rgKeyInfo
'    Array of CRYPT_XML_KEY_INFO_ITEM.

' hVerifyKey
'    A BCrypt key handle which is resolved from the first <KeyValue> element.
'    NOTE: If more than one <KeyValue> elements included, then only the first
'          one is used, and the rest are ignored.

'Schema:

'   <element name="KeyInfo" type="ds:KeyInfoType"/>
'   <complexType name="KeyInfoType" mixed="true">
'     <choice maxOccurs="unbounded">
'       <element ref="ds:KeyName"/>
'       <element ref="ds:KeyValue"/>
'       <element ref="ds:RetrievalMethod"/>
'       <element ref="ds:X509Data"/>
'       <element ref="ds:PGPData"/>
'       <element ref="ds:SPKIData"/>
'       <element ref="ds:MgmtData"/>
'       <any processContents="lax" namespace="##other"/>
'       <!-- (1,1) elements from (0,unbounded) namespaces -->
'     </choice>
'     <attribute name="Id" type="ID" use="optional"/>
'   </complexType>

'****************************************************************************/
' // Size = 20 bytes
TYPE CRYPT_XML_KEY_INFO DWORD
   cbSize     AS DWORD                         ' ULONG
   wszId      AS WSTRINGZ PTR                  ' LPCWSTR
   cKeyInfo   AS DWORD                         ' UINT
   rgKeyInfo  AS CRYPT_XML_KEY_INFO_ITEM PTR   ' CRYPT_XML_KEY_INFO_ITEM *
   hVerifyKey AS DWORD                         ' BCRYPT_KEY_HANDLE // <= A handle, resolved from the first KeyValue, if any
END TYPE


'/****************************************************************************
' CRYPT_XML_REFERENCE

' cbSize
'    Size of this structure.

' hReference
'    Handle to the Reference object.

' wszId
'    [optional] Specifies unique identifier attribute.

' wszUri
'    [optional] Specifies the URI attribute.

' wszType
'    [optional] Specifies the Type attribute.

' DigestMethod
'    Specifies digest method.

' DigestValue
'    Specifies hash value.

' cTransform
'    Number of elements in the array rgTransform.

' rgTransform
'    Array of structures  CRYPT_XML_TRANSFORM_INFO,
'    each holding information about Transform applied to the signed data.

'****************************************************************************/
' // Size = 56 bytes
TYPE CRYPT_XML_REFERENCE DWORD
   cbSize       AS DWORD                     ' ULONG
   hReference   AS DWORD                     ' HCRYPTXML
   wszId        AS WSTRINGZ PTR              ' LPCWSTR
   wszUri       AS WSTRINGZ PTR              ' LPCWSTR
   wszType      AS WSTRINGZ PTR              ' LPCWSTR
   DigestMethod AS CRYPT_XML_ALGORITHM
   DigestValue  AS CRYPT_DATA_BLOB
   cTransform   AS DWORD                     ' ULONG
   rgTransform  AS CRYPT_XML_ALGORITHM PTR   ' CRYPT_XML_ALGORITHM *
END TYPE

'/****************************************************************************
' CRYPT_XML_REFERENCES

'****************************************************************************/
' // Size = 8 bytes
TYPE CRYPT_XML_REFERENCES DWORD
   cReference   AS DWORD                     ' ULONG
   rgpReference AS CRYPT_XML_REFERENCE PTR   ' PCRYPT_XML_REFERENCE *
END TYPE

'/****************************************************************************
' CRYPT_XML_SIGNED_INFO

' cbSize
'    Size of this structure.

' wszId
'    [optional] Specifies unique identifier attribute.

' Canonicalization
'    Specifies a canonicalization algorithm.

' SignatureMethod
'    Specifies a signature algorithm.

' cReference
'    Number of elements in the array rgReference.

' rgpReference
'    Array of pointers to CRYPT_XML_REFERENCE.

' Encoded
'    Contains canonicalized <SignedInfo> element.

'****************************************************************************/
' // Size = 68 bytes
TYPE CRYPT_XML_SIGNED_INFO DWORD
   cbSize           AS DWORD                     ' ULONG
   wszId            AS WSTRINGZ PTR              ' LPCWSTR
   Canonicalization AS CRYPT_XML_ALGORITHM
   SignatureMethod  AS CRYPT_XML_ALGORITHM
   cReference       AS DWORD                     ' ULONG
   rgpReference     AS CRYPT_XML_REFERENCE PTR   ' PCRYPT_XML_REFERENCE *
   Encoded          AS CRYPT_XML_BLOB
END TYPE

'/****************************************************************************
' CRYPT_XML_OBJECT

' cbSize
'    Size of this structure.

' hObject
'    Handle to the Object object.

' wszId
'    [optional] Specifies unique identifier attribute.

' wszMimeType
'    [optional] Specifies MIME-type attribute.

' wszEncoding
'    [optional] Specifies encoding method attribute.

' Manifest
'    [optional] Specifies array of References in Manifest.

' Encoded
'    [optional] An XML part of the entire <Object> element.
'    This field is empty when the <Object> element does not contain
'    '##any' elements, therefore applications do not need to parse
'    it while validating the signature.
'    Applications may use CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT flag
'    to always receive encoded <Object> element.

' XML Schema:

'    <element name="Object" type="ds:ObjectType"/>
'    <complexType name="ObjectType" mixed="true">
'       <element ref="ds:Manifest" minOccurs="0" maxOccurs="1"/>
'        <sequence minOccurs="0" maxOccurs="unbounded">
'            <any namespace="##any" processContents="lax"/>
'        </sequence>
'        <attribute name="Id" type="ID" use="optional"/>
'        <attribute name="MimeType" type="string" use="optional"/>
'        <attribute name="Encoding" type="anyURI" use="optional"/>
'    </complexType>

'****************************************************************************/
' // Size = 40 bytes
TYPE CRYPT_XML_OBJECT DWORD
   cbSize      AS DWORD                  ' ULONG
   hObject     AS DWORD                  ' HCRYPTXML
   wszId       AS WSTRINGZ PTR           ' LPCWSTR
   wszMimeType AS WSTRINGZ PTR           ' LPCWSTR
   wszEncoding AS WSTRINGZ PTR           ' LPCWSTR
   Manifest    AS CRYPT_XML_REFERENCES   ' // OPTIONAL
   Encoded     AS CRYPT_XML_BLOB
END TYPE

'/****************************************************************************
' CRYPT_XML_SIGNATURE

' cbSize
'    Size of this structure.

' hSignature
'    Handle to the Signature object.

' SignedInfo
'    The structure of CRYPT_XML_SIGNED_INFO includes the canonicalization algorithm,
'    a signature algorithm, and one or more references.
'    The SignedInfo element may contain an optional ID attribute that will allow
'    it to be referenced by other signatures and objects.

'SignatureValue
'    CRYPT_DATA_BLOB that contains a cryptographic signature value over the <SignedInfo> element.

'KeyInfo
'    [optional] Specifies key info.

'cObject
'    Number of elements in the array rgObject.

'rgObject
'    Array of structures, each holding information of type CRYPT_XML_OBJECT.

' XML Schema:

'    <element name="Signature" type="ds:SignatureType"/>
'    <complexType name="SignatureType">
'        <sequence>
'            <element ref="ds:SignedInfo"/>
'            <element ref="ds:SignatureValue"/>
'            <element ref="ds:KeyInfo" minOccurs="0"/>
'            <element ref="ds:Object" minOccurs="0" maxOccurs="unbounded"/>
'        </sequence>
'        <attribute name="Id" type="ID" use="optional"/>
'    </complexType>

'****************************************************************************/
' // Size = 100 bytes
TYPE CRYPT_XML_SIGNATURE DWORD
   cbSize         AS DWORD                    ' ULONG
   hSignature     AS DWORD                    ' HCRYPTXML
   wszId          AS WSTRINGZ PTR             ' LPCWSTR
   SignedInfo     AS CRYPT_XML_SIGNED_INFO
   SignatureValue AS CRYPT_DATA_BLOB
   pKeyInfo       AS CRYPT_XML_KEY_INFO PTR   ' CRYPT_XML_KEY_INFO * // OPTIONAL
   cObject        AS DWORD                    ' ULONG
   rgpObject      AS CRYPT_XML_OBJECT PTR     ' PCRYPT_XML_OBJECT * // OPTIONAL
END TYPE

'/****************************************************************************
' CRYPT_XML_DOC_CTXT

' cbSize
'    Size of this structure.

' hDocCtxt
'    Handle to Document Context.

' cSignature
'    Number of elements in the array rgSignature.

' rgSignature
'    Array of structures, each holding information of type CRYPT_XML_SIGNATURE.

' pEncoded
'    Contains XML document.

'****************************************************************************/
' // Size = 20 bytes
TYPE CRYPT_XML_DOC_CTXT DWORD
   cbSize            AS DWORD                                  ' ULONG
   hDocCtxt          AS DWORD                                  ' HCRYPTXML
   pTransformsConfig AS CRYPT_XML_TRANSFORM_CHAIN_CONFIG PTR   ' CRYPT_XML_TRANSFORM_CHAIN_CONFIG *
   cSignature        AS DWORD                                  ' ULONG
   rgpSignature      AS CRYPT_XML_SIGNATURE PTR                ' PCRYPT_XML_SIGNATURE *
END TYPE

'/****************************************************************************
' CryptXmlClose

' The CryptXmlClose function closes a cryptographic XML object handle.
' At each call to this function, the reference count on the handle
' is reduced by one.  When the reference count reaches zero, an object
' encapsulated by the handle is fully released.

'****************************************************************************/

DECLARE FUNCTION CryptXmlClose IMPORT "Cryptxml.dll" ALIAS "CryptXmlClose" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlGetTransforms

' The CryptXmlGetTransforms function returns information on
' default Transform Chain Engine.

'****************************************************************************/

DECLARE FUNCTION CryptXmlGetTransforms IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetTransforms" ( _
   BYREF ppConfig AS CRYPT_XML_TRANSFORM_CHAIN_CONFIG _ ' __out CRYPT_XML_TRANSFORM_CHAIN_CONFIG **ppConfig
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlOpenToEncode

' The CryptXmlOpenToEndoce function opens an XML digital signature to encode
' and returns a handle of the opened signature object.
' The handle encapsulates a Document Context with single Signature object and
' remains open until CryptXmlClose is called.

' pConfig
'    [in, optional] Specifies the transform chain engine.
'    If this parameter is NULL,
'    then a default engine will be used to apply transforms.

' dwFlags
'    [in] Currently defined dwFlags are shown in the following table.

'        CRYPT_XML_FLAG_NO_SERIALIZE
'        CRYPT_XML_FLAG_DISABLE_EXTENSIONS
'        CRYPT_XML_FLAG_ENFORCE_ID_NCNAME_FORMAT | CRYPT_XML_FLAG_ENFORCE_ID_NAME_FORMAT

' wszId
'    [in, optional] Specifies the Id attribute of the <Signature> element.
'    If this parameter is NULL or an empty string, then no Id attribute will be produced.

' rgProperty
'    [in, optional] Specifies additional properties.
'    This pointer must be valid until CryptXmlClose is
'    called on the document context.

' phSignature
'    [out] Handle to the Signature object.

'****************************************************************************/

DECLARE FUNCTION CryptXmlOpenToEncode IMPORT "Cryptxml.dll" ALIAS "CryptXmlOpenToEncode" ( _
   BYREF pConfig AS CRYPT_XML_TRANSFORM_CHAIN_CONFIG _  ' __in_opt const CRYPT_XML_TRANSFORM_CHAIN_CONFIG *pConfig
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF wszId AS WSTRINGZ _                            ' __in_opt LPCWSTR wszId
 , BYREF rgProperty AS CRYPT_XML_PROPERTY _             ' __in_opt const CRYPT_XML_PROPERTY* rgProperty
 , BYVAL cProperty AS DWORD _                           ' __in ULONG cProperty
 , BYREF pEncoded AS CRYPT_XML_BLOB _                   ' __in_opt const CRYPT_XML_BLOB *pEncoded
 , BYREF phSignature AS DWORD _                         ' __out HCRYPTXML *phSignature
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlOpenToDecode

' The CryptXmlOpenToDecode function opens an XML digital signature to decode
' and returns a handle of the Document Context that encapsulates Signatures
' object. The handle remains open until CryptXmlClose is called.
' The Document Context may include one or more Signature objects.

' hEngine
'    [in, optional] Handle of the transform chain engine.
'    If this parameter is NULL, then a default engine will be
'    used to apply transforms.

' dwFlags
'    [in] Currently defined dwFlags are shown in the following table.

'        CRYPT_XML_FLAG_NO_SERIALIZE
'        CRYPT_XML_FLAG_DISABLE_EXTENSIONS
'        CRYPT_XML_FLAG_ALWAYS_RETURN_ENCODED_OBJECT
'        CRYPT_XML_FLAG_ENFORCE_ID_NCNAME_FORMAT | CRYPT_XML_FLAG_ENFORCE_ID_NAME_FORMAT

' rgProperty
'    [in, optional] Specifies additional properties.

' phCryptXml
'    [out] Handle to the Document Context object.

'****************************************************************************/

DECLARE FUNCTION CryptXmlOpenToDecode IMPORT "Cryptxml.dll" ALIAS "CryptXmlOpenToDecode" ( _
   BYREF pConfig AS CRYPT_XML_TRANSFORM_CHAIN_CONFIG _  ' __in_opt const CRYPT_XML_TRANSFORM_CHAIN_CONFIG *pConfig
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF rgProperty AS CRYPT_XML_PROPERTY _             ' __in_opt const CRYPT_XML_PROPERTY* rgProperty
 , BYVAL cProperty AS DWORD _                           ' __in ULONG cProperty
 , BYREF pEncoded AS CRYPT_XML_BLOB _                   ' __in_opt const CRYPT_XML_BLOB *pEncoded
 , BYREF phCryptXml AS DWORD _                          ' __out HCRYPTXML *phCryptXml
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlAddObject

' The CryptXmlAddObject function adds the <Object> element to Signature in
' the Document Context opened to encode.
' See Remarks.

' hSignatureOrObject
'    [in] Handle to the Signature returned by CryptXmlOpenToEncode;
'    or handle to a Reference returned by CryptXmlCreateReference with
'    CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT flag. See Remarks.

' dwFlags
'    [in] The following flags are defined.
'        CRYPT_XML_FLAG_ADD_OBJECT_CREATE_COPY

' rgProperty
'    [in, optional] Specifies additional properties used to decode the <Object> element.

' cProperty
'    [in] Specifies number of elements in the rgProperty array.

' pEncoded
'    [in] Specifies the <Object> element or a part of it, see Remarks.

' ppObject
'    [out, optional] Pointer to CRYPT_XML_OBJECT* to receive a decoded structure.
'    This parameter must be NULL when hSignatureOrObject is a handle to the Object.

' REMARKS:
'    When the hSignatureOrObject specifies a handle to a Reference returned
'    by CryptXmlCreateReference, then pEncoded specifies XML content to be included
'    inside the <Object> node after the optional <Manifest> element.
'    The pEncoded pointer must be valid till the signature is complete.
'    Otherwise, use CRYPT_XML_FLAG_ADD_OBJECT_CREATE_COPY flag to create in-memory copy.

'****************************************************************************/

DECLARE FUNCTION CryptXmlAddObject IMPORT "Cryptxml.dll" ALIAS "CryptXmlAddObject" ( _
   BYVAL hSignatureOrObject AS DWORD _                  ' __in HCRYPTXML hSignatureOrObject
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF rgProperty AS CRYPT_XML_PROPERTY _             ' __in_opt const CRYPT_XML_PROPERTY* rgProperty
 , BYVAL cProperty AS DWORD _                           ' __in ULONG cProperty
 , BYREF pEncoded AS CRYPT_XML_BLOB _                   ' __in const CRYPT_XML_BLOB *pEncoded
 , OPTIONAL BYREF ppObject AS CRYPT_XML_OBJECT _        ' __out_opt const CRYPT_XML_OBJECT **ppObject
 ) AS LONG                                              ' HRESULT

'// Used to create in-memory copy of XML part to be included in the <Object>
%CRYPT_XML_FLAG_ADD_OBJECT_CREATE_COPY   = &H00000001???

'/****************************************************************************
' CryptXmlCreateReference

' hCryptXml
'    [in] Handle of the XML signature.

' dwFlags
'    [in] Currently defined dwFlags are shown in the following table.
'        CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT

' pwszId
'    [in, optional] Specifies the Id attribute of the <Reference> element.
'   If this parameter is NULL, then the Id attribute will not be created.
'   If this parameter is an empty string, then the Id attribute with empty
'        value will be created.

' pwszURI
'    [in] Specifies the URI attribute of the <Reference> element.
'    If this parameter is an empty string,
'    then the Uri attribute with empty value will be created.

' pwszType
'    [in, optional] Specifies the Type attribute of the <Reference> element.
'    The processing Engine does not check or use this attribute.

' pDigestMethod
'    [in] Specifies the digest method.

' cTransform
'    [in] Number of elements in rgTransform array.

' rgTransform
'    [in, optional] Ordered array of transform algorithms to be applied to
'    the reference data before digest calculation.

' phReference
'    [out] Pointer to a Reference Handle.

'****************************************************************************/

DECLARE FUNCTION CryptXmlCreateReference IMPORT "Cryptxml.dll" ALIAS "CryptXmlCreateReference" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF wszId AS WSTRINGZ _                            ' __in_opt LPCWSTR wszId
 , BYREF wszURI AS WSTRINGZ _                           ' __in_opt LPCWSTR wszURI
 , BYREF wszType AS WSTRINGZ _                          ' __in_opt LPCWSTR wszType
 , BYREF pDigestMethod AS CRYPT_XML_ALGORITHM _         ' __in const CRYPT_XML_ALGORITHM *pDigestMethod
 , BYVAL cTransform AS DWORD _                          ' __in ULONG cTransform
 , BYREF rgTransform AS CRYPT_XML_ALGORITHM _           ' __in_opt const CRYPT_XML_ALGORITHM *rgTransform
 , BYREF phReference AS DWORD _                         ' __out HCRYPTXML *phReference
 ) AS LONG                                              ' HRESULT

'// When this flag is set an Object will be created and added to the Signature,
'// and a Reference to the Object will be created in SignedInfo.
'// The returned handle is encapsulated Object and can be used
'// in subsequent calls to CryptXmlCreateReference to create references in
'// Manifest.

%CRYPT_XML_FLAG_CREATE_REFERENCE_AS_OBJECT      = &H00000001???

'/****************************************************************************
' CryptXmlDigestReference

' The CryptXmlDigestReference function is used by an application to digest
' the resolved reference.
' This function applies Transforms before updating the digest.

' hReference
'    [in] Handle to Reference object.

' dwFlags
'    [in] Currently defined dwFlags are shown in the following table.

' pDataProviderIn
'    [in,out] Specifies the data provider.

'Remarks:

'    When CRYPT CRYPT_XML_DIGEST_REFERENCE_DATA_TRANSFORMED flag is set,
'    the processing engine directly digests received data without
'    applying the transform chain engine.

'    The CryptXmlDigestReference function always calls pDataProviderIn->fpnClose.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDigestReference IMPORT "Cryptxml.dll" ALIAS "CryptXmlDigestReference" ( _
   BYVAL hReference AS DWORD _                          ' __in HCRYPTXML hReference
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pDataProviderIn AS CRYPT_XML_DATA_PROVIDER _   ' __in CRYPT_XML_DATA_PROVIDER *pDataProviderIn
 ) AS LONG                                              ' HRESULT

'// Specifies that the processing engine creates the digest
'// without applying the transform chain engine.
%CRYPT_XML_DIGEST_REFERENCE_DATA_TRANSFORMED           = &H00000001???

'/****************************************************************************
' CryptXmlSetHMACSecret

' The CryptXmlSetHMACSecret function set HMAC secret on the handle before
' calling CryptXmlSign or CryptXmlVerify.

' hSignature
'    [in] Handle to Signature.

' pbSecret
'    [in] Pointer to a block of bytes.
'    The pointer must be valid during calls to CryptXmlSign or CryptXmlVerify.

' cbSecret
'    Size, in bytes, of the block of data at pbSecret.

' NOTE: When using HMAC, the key handles passed to CryptXmlSign or CryptXmlVerify
' must be NULL.

'****************************************************************************/

DECLARE FUNCTION CryptXmlSetHMACSecret IMPORT "Cryptxml.dll" ALIAS "CryptXmlSetHMACSecret" ( _
   BYVAL hSignature AS DWORD _                          ' __in HCRYPTXML hSignature
 , BYVAL pbSecret AS BYTE PTR _                         ' __in const BYTE *pbSecret
 , BYVAL cbSecret AS DWORD _                            ' __in ULONG cbSecret
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CRYPT_XML_KEYINFO_PARAMS

'  This structure is passed to CryptXmlSign specifying
'  the members of <KeyInfo> element to be encoded.

'  wszId
'    Specifies the Id attribute of the <KeyInfo> element

'  wszKeyName
'    Specifies value for the <KeyName> element

'  SKI
'    Specifies value for the <X509SKI> element

'  wszSubjectName
'    Specifies value for the <X509SubjectName> element

'  cCertificate
'    Specifies number of items in the rgCertificate array

'  rgCertificate
'    Specifies array of CERT_BLOB to populate <X509Certificate> elements

'  cCRL;
'    Specifies number of items in the rgCRL array

'  rgCRL
'    Specifies array of CERT_BLOB to populate <X509CRL> elements

'****************************************************************************/
' // Size = 36 bytes
TYPE CRYPT_XML_KEYINFO_PARAM DWORD
   wszId          AS WSTRINGZ PTR    ' LPCWSTR
   wszKeyName     AS WSTRINGZ PTR    ' LPCWSTR
   SKI            AS CERT_BLOB
   wszSubjectName AS WSTRINGZ PTR    ' LPCWSTR
   cCertificate   AS DWORD           ' ULONG
   rgCertificate  AS CERT_BLOB PTR   ' CERT_BLOB *
   cCRL           AS DWORD           ' ULONG
   rgCRL          AS CERT_BLOB PTR   ' CERT_BLOB *
END TYPE

'/****************************************************************************
' CRYPT_XML_KEYINFO_SPEC

'****************************************************************************/
' enum CRYPT_XML_KEYINFO_SPEC
%CRYPT_XML_KEYINFO_SPEC_NONE    = 0   ' // No KeyInfo
%CRYPT_XML_KEYINFO_SPEC_ENCODED = 1   ' // CRYPT_XML_BLOB*
%CRYPT_XML_KEYINFO_SPEC_PARAM   = 2   ' // CRYPT_XML_KEYINFO_PARAM*

'/****************************************************************************
' CryptXmlSign

' The CryptXmlSign function creates a cryptographic signature over SignedInfo
' element in a document context opened for encode.

' hSignature
'    [in] Handle to Signature.

' hKey
'    [in] Handle to a Private Key used to sign the SignedInfo element.
'    This parameter must be NULL for HMAC-based signature algorithms.

' dwKeySpec
'    [in] Identifies the private key to use from the provider's container.
'    It can be AT_KEYEXCHANGE, AT_SIGNATURE or 0.
'    This parameter is ignored if an NCRYPT_KEY_HANDLE is used in
'    the hCryptProvOrNCryptKey parameter.

' dwFlags
'    [in] The following value is defined.
'        CRYPT_XML_SIGN_ADD_KEYVALUE
'        CRYPT_XML_FLAG_DISABLE_EXTENSIONS

' dwKeyInfoSpec
'    [in] Specifies the type of pvKeyInfoSpec data structure.

' pvKeyInfoSpec
'    [in] Pointer to a structure determined by the value of dwKeyInfoSpec.
'    The following table specifies possible combinations for
'    dwKeyInfoSpec and pvKeyInfoSpec

'    dwKeyInfoSpec                           pvKeyInfoSpec
'    -----------------------------           ------------------------
'    CRYPT_XML_KEYINFO_SPEC_NONE             NULL
'    CRYPT_XML_KEYINFO_SPEC_ENCODED          CRYPT_XML_BLOB*
'    CRYPT_XML_KEYINFO_SPEC_PARAM            CRYPT_XML_KEYINFO_PARAM*

' pSignatureMethod
'    [in] Specifies the signature method.

' pCanonicalization
'    [in] Specifies the canonicalization method.

'****************************************************************************/

DECLARE FUNCTION CryptXmlSign IMPORT "Cryptxml.dll" ALIAS "CryptXmlSign" ( _
   BYVAL hSignature AS DWORD _                          ' __in HCRYPTXML hSignature
 , BYVAL hKey AS DWORD _                                ' __in_opt HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hKey
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwKeyInfoSpec AS DWORD _                       ' __in CRYPT_XML_KEYINFO_SPEC dwKeyInfoSpec
 , BYREF pvKeyInfoSpec AS ANY _                         ' __in_opt const void *pvKeyInfoSpec
 , BYREF pSignatureMethod AS CRYPT_XML_ALGORITHM _      ' __in const CRYPT_XML_ALGORITHM *pSignatureMethod
 , BYREF pCanonicalization AS CRYPT_XML_ALGORITHM _     ' __in const CRYPT_XML_ALGORITHM *pCanonicalization
 ) AS LONG                                              ' HRESULT

'// Specify this flag to populate <KeyValue> element from
'// the hKey handle.
'// NOTE: This flag can not be used when dwKeyInfoSpec is
'//       set to CRYPT_XML_KEYINFO_SPEC_ENCODED
%CRYPT_XML_SIGN_ADD_KEYVALUE         = &H00000001???

'/****************************************************************************
' CryptXmlImportPublicKey

'    dwFlags
'        The following flags are supported:
'            CRYPT_XML_FLAG_DISABLE_EXTENSIONS

'    pKeyValue
'        CRYPT_XML_KEY_VALUE to be imported.

'    phKey
'        [out] Pointer to BCRYPT_KEY_HANDLE that receives imported key handle.

'****************************************************************************/

DECLARE FUNCTION CryptXmlImportPublicKey IMPORT "Cryptxml.dll" ALIAS "CryptXmlImportPublicKey" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pKeyValue AS CRYPT_XML_KEY_VALUE _             ' __in const CRYPT_XML_KEY_VALUE *pKeyValue
 , BYREF phKey AS DWORD _                               ' __out BCRYPT_KEY_HANDLE *phKey
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlVerifySignature

' The CryptXmlVerifySignature function performs a cryptographic signature
' validation over SignedInfo element in a document context opened for decode.
' hSignature
'    [in] Handle to Signature.

' hKey
'    [in] Handle to a Public Key to verify the signature value on
'    the SignedInfo element.
'    This parameter must be NULL for HMAC-based signature algorithms.

' dwFlags
'    [in] The following flags are supported:
'        CRYPT_XML_FLAG_DISABLE_EXTENSIONS

'****************************************************************************/

DECLARE FUNCTION CryptXmlVerifySignature IMPORT "Cryptxml.dll" ALIAS "CryptXmlVerifySignature" ( _
   BYVAL hSignature AS DWORD _                          ' __in HCRYPTXML hSignature
 , BYVAL hKey AS DWORD _                                ' __in_opt BCRYPT_KEY_HANDLE hKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlGetDocContext

' The CryptXmlGetDocContext function returns data structure encapsulated by
' a handle to Document Context.

'****************************************************************************/

DECLARE FUNCTION CryptXmlGetDocContext IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetDocContext" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYREF ppStruct AS CRYPT_XML_DOC_CTXT _               ' __out const CRYPT_XML_DOC_CTXT **ppStruct
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlGetSignature

' The CryptXmlGetSignature function returns data structure encapsulated
' by a handle to Signature.

'****************************************************************************/

DECLARE FUNCTION CryptXmlGetSignature IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetSignature" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYREF ppStruct AS CRYPT_XML_SIGNATURE _              ' __out const CRYPT_XML_SIGNATURE **ppStruct
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlGetReference

'The CryptXmlGetReference function returns data structure encapsulated
'by a handle to Reference.
'****************************************************************************/

DECLARE FUNCTION CryptXmlGetReference IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetReference" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYREF ppStruct AS CRYPT_XML_REFERENCE _              ' __out const CRYPT_XML_REFERENCE **ppStruct
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlGetStatus

'The CryptXmlGetStatus function returns a CRYPT_XML_STATUS for array
'of Signature, single Signature, Reference or Manifest.

'****************************************************************************/

DECLARE FUNCTION CryptXmlGetStatus IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetStatus" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYREF pStatus AS CRYPT_XML_STATUS _                  ' __out CRYPT_XML_STATUS *pStatus
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlEncode

' The CryptXmlEncode function constructs XML document using the XML writer
' callback that allows applications to stream XML being constructed.

' hCryptXml
'    [in] Specifies the handle of an object to be serialized.
'    The handle can be of Signature, Object, Reference types.

' rgProperty
'    [in, optional] Specifies additional properties used to encode XML.

' cProperty
'    [in] Specifies number of elements in the rgProperty array.

' pvCallbackState
'    [in] An application-defined argument to be passed to the callback.

' pfnWrite
'    [in, callback] An application-defined callback to receive constructed XML.

'****************************************************************************/

DECLARE FUNCTION CryptXmlEncode IMPORT "Cryptxml.dll" ALIAS "CryptXmlEncode" ( _
   BYVAL hCryptXml AS DWORD _                           ' __in HCRYPTXML hCryptXml
 , BYVAL dwCharset AS DWORD _                           ' __in CRYPT_XML_CHARSET dwCharset
 , BYREF rgProperty AS CRYPT_XML_PROPERTY _             ' __in const CRYPT_XML_PROPERTY* rgProperty
 , BYVAL cProperty AS DWORD _                           ' __in ULONG cProperty
 , BYREF pvCallbackState AS ANY _                       ' __inout void *pvCallbackState
 , BYVAL pfnWrite AS DWORD _                            ' __in PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CRYPT_XML_ALGORITHM_INFO

'    cbSize
'        The size, in bytes, of this structure.

'    wszAlgorithmURI
'        The URI associated with attribute of the SignatureMethod or DigestMethod elements

'    wszName
'        [optional] Friendly name of the algorithm.

'    dwGroupId
'        Can be one of the following values:
'            CRYPT_XML_GROUP_ID_HASH         Hash algorithms
'            CRYPT_XML_GROUP_ID_SIGN         Signature algorithms

'    wszCNGAlgid
'        The algorithm identifier string passed to the CNG functions
'        CNG functions use algorithm identifier strings, such as L"SHA1",

'    wszCNGExtraAlgid
'        An extra algorithm string, other than the string in the pwszCNGAlgid member,
'        that can be passed to the CNG functions.

'    dwSignFlags
'        This value is passed to NCryptSignHash

'    dwVerifyFlags
'        This value is passed to BCryptVerifySignature.

'    pvPaddingInfo
'        A pointer to a structure that contains padding information.
'        The actual type of structure this parameter points to depends on
'        the value of the dwFlags parameter.
'        This pointer is passed to NCryptSignHash or BCryptVerifySignature

'    pvExtraInfo
'        [optional] A pointer to a structure that contains extra information
'        that can be passed to the CNG functions.

'NOTE: the BCrypt* and NCrypt* functions that are defined in Bcrypt.h and Ncrypt.h

'****************************************************************************/

' // Size = 40 bytes
TYPE CRYPT_XML_ALGORITHM_INFO DWORD
   cbSize           AS DWORD          ' DWORD
   wszAlgorithmURI  AS WSTRINGZ PTR   ' WCHAR *
   wszName          AS WSTRINGZ PTR   ' WCHAR *
   dwGroupId        AS DWORD          ' DWORD
   wszCNGAlgid      AS WSTRINGZ PTR   ' WCHAR *
   wszCNGExtraAlgid AS WSTRINGZ PTR   ' WCHAR *
   dwSignFlags      AS DWORD          ' DWORD // NCryptSignHash flags
   dwVerifyFlags    AS DWORD          ' DWORD // BCryptVerifySignature flags
   pvPaddingInfo    AS DWORD          ' void *
   pvExtraInfo      AS DWORD          ' void *
END TYPE

%CRYPT_XML_GROUP_ID_HASH = 1
%CRYPT_XML_GROUP_ID_SIGN = 2

'/****************************************************************************
' CryptXmlGetAlgorithmInfo

'    Decodes the XML Algorithm and returns information about the algorithm.

'    The following flags are supported:
'        CRYPT_XML_FLAG_DISABLE_EXTENSIONS

'    The caller must free ppAlgInfo by calling LocalFree()

'****************************************************************************/

DECLARE FUNCTION CryptXmlGetAlgorithmInfo IMPORT "Cryptxml.dll" ALIAS "CryptXmlGetAlgorithmInfo" ( _
   BYREF pXmlAlgorithm AS CRYPT_XML_ALGORITHM _         ' __in const CRYPT_XML_ALGORITHM *pXmlAlgorithm
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF ppAlgInfo AS CRYPT_XML_ALGORITHM_INFO _        ' __out CRYPT_XML_ALGORITHM_INFO **ppAlgInfo
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlFindAlgorithmInfo

'    dwFindByType
'        [in] Specifies the pvFindBy parameter type.
'            The following values are supported:
'                CRYPT_XML_ALGORITHM_INFO_FIND_BY_URI            - wszAlgorithmURI
'                CRYPT_XML_ALGORITHM_INFO_FIND_BY_NAME           - wszName
'                CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_ALGID      - wszCNGAlgid
'                CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_SIGN_ALGID - pwszCNGAlgid
'                        pwszCNGAlgid[0] - Hash pwszCNGAlgid
'                        pwszCNGAlgid[1] - PubKey pwszCNGAlgid

'    pvFindBy
'        [in] Specifies the search parameter.

'    dwGroupId
'        [in] Specifies the algorithm group.

'    dwFlags
'        [in] The following flags are supported:
'                CRYPT_XML_FLAG_DISABLE_EXTENSIONS

'    ppAlgInfo
'        [out] Pointer to CRYPT_XML_ALGORITHM_INFO pointer.

'****************************************************************************/

DECLARE FUNCTION CryptXmlFindAlgorithmInfo IMPORT "Cryptxml.dll" ALIAS "CryptXmlFindAlgorithmInfo" ( _
   BYVAL dwFindByType AS DWORD _                        ' __in DWORD dwFindByType
 , BYREF pvFindBy AS ANY _                              ' __in const void *pvFindBy
 , BYVAL dwGroupId AS DWORD _                           ' __in DWORD dwGroupId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' CRYPT_XML_ALGORITHM_INFO*

%CRYPT_XML_ALGORITHM_INFO_FIND_BY_URI            = 1
%CRYPT_XML_ALGORITHM_INFO_FIND_BY_NAME           = 2
%CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_ALGID      = 3
%CRYPT_XML_ALGORITHM_INFO_FIND_BY_CNG_SIGN_ALGID = 4

'/****************************************************************************
' CryptXmlEnumAlgorithmInfo

' The CryptXmlEnumAlgorithmInfo function enumerates predefined and registered
' CryptXml CRYPT_XML_ALGORITHM_INFO entries.
' This function enumerates either all of the predefined and registered
' entries or only structures identified by a selected URI group.
' For each URI information structure enumerated,
' an application provided callback function, pfnEnumAlgInfo, is called.

'    dwGroupId
'        [in] Specifies an algorithm group to be searched (Digest, Signature)

'    dwFlags
'        [in] The following flags are defined.

'        CRYPT_XML_INHIBIT_EXTENSIONS
'            Disable XML Cryptographic Extension algorithms.

'    pvArg
'        [in, optional] Specifies an application defined parameter for the callback.

'    pfnEnumAlgInfo
'        [callback] Address of the callback function that will be called
'        for each Algorithm found.

'****************************************************************************/

'//
'// If the callback returns FALSE, then stop the enumeration.
'//

'typedef BOOL (WINAPI * PFN_CRYPT_XML_ENUM_ALG_INFO)(
'    __in            const CRYPT_XML_ALGORITHM_INFO *pInfo,
'    __inout_opt     void                *pvArg
'    );

'FUNCTION CRYPT_XML_ENUM_ALG_INFO ( _
'   BYREF pInfo AS CRYPT_XML_ALGORITHM_INFO _            ' __in const CRYPT_XML_ALGORITHM_INFO *pInfo
' , BYVAL pvArg AS DWORD _                               ' __inout void *pvArg
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION CryptXmlEnumAlgorithmInfo IMPORT "Cryptxml.dll" ALIAS "CryptXmlEnumAlgorithmInfo" ( _
   BYVAL dwGroupId AS DWORD _                           ' __in DWORD dwGroupId
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pvArg AS ANY _                                 ' __inout_opt void *pvArg
 , BYVAL pfnEnumAlgInfo AS DWORD _                      ' __callback PFN_CRYPT_XML_ENUM_ALG_INFO pfnEnumAlgInfo
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' * CRYPTO EXTENSIBILITY
' *
' ***************************************************************************/

' *** Moved here because PB doesn't support forward references to structures ***
' // Size = 36 bytes
TYPE CRYPT_XML_CRYPTOGRAPHIC_INTERFACE DWORD
   cbSize                     AS DWORD   ' ULONG
   fpCryptXmlEncodeAlgorithm  AS DWORD   ' CryptXmlDllEncodeAlgorithm
   fpCryptXmlCreateDigest     AS DWORD   ' CryptXmlDllCreateDigest
   fpCryptXmlDigestData       AS DWORD   ' CryptXmlDllDigestData
   fpCryptXmlFinalizeDigest   AS DWORD   ' CryptXmlDllFinalizeDigest
   fpCryptXmlCloseDigest      AS DWORD   ' CryptXmlDllCloseDigest
   fpCryptXmlSignData         AS DWORD   ' CryptXmlDllSignData
   fpCryptXmlVerifySignature  AS DWORD   ' CryptXmlDllVerifySignature
   fpCryptXmlGetAlgorithmInfo AS DWORD   ' CryptXmlDllGetAlgorithmInfo
END TYPE

'/****************************************************************************
' CryptXmlGetInterface

' Cryptographic Extensions DLL must export CryptXmlGetInterface entry.

'    dwFlags
'        [in] Not used at the moment and must be 0.

'    pMethod
'        [in] A pointer to a CRYPT_XML_ALGORITHM_INFO structure
'        to retrieve the interface of.

'    pInterface
'        [out] A pointer to a CRYPT_XML_ALGORITHM_INFO structure
'        to receive the interface information.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllGetInterface IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllGetInterface" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pMethod AS CRYPT_XML_ALGORITHM_INFO _          ' __in const CRYPT_XML_ALGORITHM_INFO *pMethod
 , BYREF pInterface AS CRYPT_XML_CRYPTOGRAPHIC_INTERFACE _ ' __out CRYPT_XML_CRYPTOGRAPHIC_INTERFACE *pInterface
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllEncodeAlgorithm

'    The CryptXmlDllEncodeAlgorithm function is used to encode <SignatureMethod>
'    or <DigestMethod> elements for agile algorithms with default parameters.
'    The CryptXmlDllEncodeAlgorithm function is exposed though
'    the exported CryptXmlDllGetInterface fucntion.

'    pAlgInfo
'        [in] A pointer to a CRYPT_XML_ALGORITHM_INFO structure.

'    dwCharset
'        A CRYPT_XML_CHARSET value that specifies the character set of the encoded XML.

'    pvCallbackState
'        [in, out] A poniter to an argument that is passed to the callback
'        function pointed to by the pfnWrite parameter.

'    pfnWrite
'        [in] A PFN_CRYPT_XML_WRITE_CALLBACK callback to receive the encoded XML.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllEncodeAlgorithm IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllEncodeAlgorithm" ( _
   BYREF pAlgInfo AS CRYPT_XML_ALGORITHM_INFO _         ' __in const CRYPT_XML_ALGORITHM_INFO *pAlgInfo
 , BYVAL dwCharset AS DWORD _                           ' __in CRYPT_XML_CHARSET dwCharset
 , BYREF pvCallbackState AS ANY _                       ' __inout void *pvCallbackState
 , BYVAL pfnWrite AS DWORD _                            ' __in PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllCreateDigest

'    pDigestMethod
'        [in] A pointer to a CRYPT_XML_ALGORITHM structure that specifies
'        the algorithm to use to create the digest.

'    pcbSize
'        [out] A pointer to a ULONG value to receive the size,
'        in bytes, of the digest.

'    phDigest
'        [out] A pointer to a CRYPT_XML_DIGEST variable to receive a pointer
'        to the digest.
'        CryptXml uses CryptXmlDllCloseDigest to free resources allocated
'        in phDigest.

'****************************************************************************/
'typedef void*   CRYPT_XML_DIGEST;

DECLARE FUNCTION CryptXmlDllCreateDigest IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllCreateDigest" ( _
   BYREF pDigestMethod AS CRYPT_XML_ALGORITHM _         ' __in const CRYPT_XML_ALGORITHM *pDigestMethod
 , BYREF pcbSize AS DWORD _                             ' __out ULONG *pcbSize
 , BYREF phDigest AS DWORD _                            ' __out CRYPT_XML_DIGEST *phDigest
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllDigestData

'    The CryptXmlDllDigestData function is used to digest data.
'    The CryptXmlDllDigestData function is exposed though
'    the exported CryptXmlDllGetInterface fucntion.

'    hDigest
'        [in] The handle of the hash object used to perform the digest.
'        This handle is obtained by calling the CryptXmlDllCreateDigest function.

'    pbData
'        [in] A pointer to a block of data to be processed.

'    cbDigest
'        [in] The size, in bytes, of the block of data pointed
'        to bye the pbData parameter.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllDigestData IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllDigestData" ( _
   BYREF pDigestMethod AS CRYPT_XML_ALGORITHM _         ' __in const CRYPT_XML_ALGORITHM *pDigestMethod
 , BYREF pcbSize AS DWORD _                             ' __out ULONG *pcbSize
 , BYREF phDigest AS DWORD _                            ' __out CRYPT_XML_DIGEST *phDigest
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllFinalizeDigest

'    The CryptXmlDllFinalizeDigest function isused to retrieve the digest value.
'    The CryptXmlDllFinalizeDigest function is exposed though
'    the exported CryptXmlDllGetInterface fucntion.

'    hDigest
'        [in] The handle of the hash object used to perform the digest.
'        This handle is obtained by calling the CryptXmlDllCreateDigest function.

'    pbDigest
'        [out] A pointer to a buffer that receives the digest value.

'    cbDigest
'        [in] The size, in bytes, of the buffer pointed to by the pbDigest.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllFinalizeDigest IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllFinalizeDigest" ( _
   BYVAL hDigest AS DWORD _                             ' __in CRYPT_XML_DIGEST hDigest
 , BYVAL pbDigest AS BYTE PTR _                         ' __out BYTE *pbDigest
 , BYVAL cbDigest AS DWORD _                            ' __in ULONG cbDigest
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllCloseDigest

'    hDigest
'        [in] The handle of the digest object.
'        This handle is obtained by calling the CryptXmlCreateDigest function.
'        After the function has been called, the digest handle passed
'        to this function is released and cannot be used again.
'****************************************************************************/

DECLARE FUNCTION CryptXmlDllCloseDigest IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllCloseDigest" ( _
   BYVAL hDigest AS DWORD _                             ' __in CRYPT_XML_DIGEST hDigest
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllSignData

'    The CryptXmlDllSignData function is used to sign data.
'    The CryptXmlDllSignData function is exposed though
'    the exported CryptXmlDllGetInterface fucntion.

'    pSignatureMethod
'        [in] A pointer to a CRYPT_XML_ALGORITHM structure that specifies the algorithm.

'    hCryptProvOrNCryptKey
'        [in] The handle of the CSP that creates the signature.
'        This handle must be an HCRYPTPROV handle that obtained from a call to
'        the CryptAcquireContext function or an NCRYPT_KEY_HANDLE handle that has been
'        created by using the NCryptOpenKey function.
'        New applications should always pass in the NCRYPT_KEY_HANDLE handle.

'    dwKeySpec
'        [in] Identifies the private key to use from the provider's container.
'        It can be AT_KEYEXCHANGE or AT_SIGNATURE.
'        This parameter is ignored if an NCRYPT_KEY_HANDLE is used in
'        the hCryptProvOrNCryptKey parameter.

'    pbInput
'        [in] A pointer to a buffer that contains the digest value to sign.
'        The cbInput parameter contains the size of this buffer.

'    cbInput
'        [in] The size, in bytes, of the buffer pointed to by the pbInput parameter.

'    pbOutput
'        [out, optional] The address of a buffer to receive the signature
'        produced by this function. The cbOutput parameter contains the s
'        ize of this buffer.
'        If this parameter is NULL, this function will calculate the size needed for
'        the encrypted data and return the size in the location pointed to
'        by the pcbResult parameter.

'    cbOutput
'        [in] The size, in bytes, of the buffer pointed to by the pbOutput pramater.

'    pcbResult
'        [out] A pointer to a DWORD variable that receives the number of bytes copied
'        to the pbOutput buffer.
'        If pbOutput is NULL, this receives the size, in bytes, required
'        for the signature.


'****************************************************************************/

DECLARE FUNCTION CryptXmlDllSignData IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllSignData" ( _
   BYREF pSignatureMethod AS CRYPT_XML_ALGORITHM _      ' __in const CRYPT_XML_ALGORITHM *pSignatureMethod
 , BYVAL hCryptProvOrNCryptKey AS DWORD _               ' __in HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey
 , BYVAL dwKeySpec AS DWORD _                           ' __in DWORD dwKeySpec
 , BYVAL pbInput AS BYTE PTR _                          ' __in const BYTE *pbInput
 , BYVAL cbInput AS DWORD _                             ' __in ULONG cbInput
 , BYVAL pbOutput AS BYTE PTR _                         ' __out BYTE *pbOutput
 , BYVAL cbOutput AS DWORD _                            ' __in ULONG cbOutput
 , BYREF pcbResult AS DWORD _                           ' __out ULONG *pcbResult
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllVerifySignature

'    The CryptXmlDllVerifySignature function is used to verify signature.
'    The CryptXmlDllVerifySignature function is exposed though
'    the exported CryptXmlDllGetInterface fucntion.

'    pSignatureMethod
'        [in] A pointer to a CRYPT_XML_ALGORITHM structure that specifies the algorithm.

'    hCryptProv
'        [in] A handle to the cryptographic provider.
'        Windows Vista and higher:  Must be set to NULL with BCrypt key handle.
'        Windows XP:  Must be a HCRYPTPROV returned by the CryptAcquireContext function.

'    hKey
'        [in] A handle to the Public Key.

'    pbInput
'        [in] A pointer to a buffer that contains the signed data.
'        The cbInput parameter contains the size of this buffer.

'    cbInput
'        [in] The size, in bytes, of the buffer pointed to by teh pbInput paramter.

'    pbSignature
'        [in] A pointer to a buffer that contains the signature value to be verified.
'        The cbSignature parameter contains the size of this buffer.

'    cbSignature
'        [in] The size, in bytes, of the pbSignature buffer.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllVerifySignature IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllVerifySignature" ( _
   BYREF pSignatureMethod AS CRYPT_XML_ALGORITHM _      ' __in const CRYPT_XML_ALGORITHM *pSignatureMethod
 , BYVAL hKey AS DWORD _                                ' __in BCRYPT_KEY_HANDLE hKey
 , BYVAL pbInput AS BYTE PTR _                          ' __in const BYTE *pbInput
 , BYVAL cbInput AS DWORD _                             ' __in ULONG cbInput
 , BYVAL pbSignature AS BYTE PTR _                      ' __in const BYTE *pbSignature
 , BYVAL cbSignature AS DWORD _                         ' __in ULONG cbSignature
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllGetAlgorithmInfo

'  The CryptXmlDllGetAlgorithmInfo fucntion decodes the XML Algorithm and
'  returns information about the algorithm.
'  The CryptXmlDllGetAlgorithmInfo function is exposed though the exported
'  CryptXmlDllGetInterface fucntion.

'    pXmlAlgorithm
'        [in] A Pointer to a CRYPT_XML_ALGORITHM structure that specifies
'        the algorithm for which to return information.

'    ppAlgInfo
'        [out] A pointer to a pointer to a CRYPT_XML_ALGORITHM_INFO structure.
'        The caller must free ppAlgInfo by calling LocalFree()

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllGetAlgorithmInfo IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllGetAlgorithmInfo" ( _
   BYREF pXmlAlgorithm AS CRYPT_XML_ALGORITHM _         ' __in const CRYPT_XML_ALGORITHM *pXmlAlgorithm
 , BYREF ppAlgInfo AS CRYPT_XML_ALGORITHM_INFO _        ' __out CRYPT_XML_ALGORITHM_INFO **ppAlgInfo
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CRYPT_XML_CRYPTOGRAPHIC_INTERFACE

'    fpCryptXmlEncodeAlgorithm
'        A pointer to the implementation of the CryptXmlDllEncodeAlgorithm.

'    fpCryptXmlCreateDigest
'        A pointer to the implementation of the CryptXmlDllCreateDigest.

'    fpCryptXmlDigestData
'        A pointer to the implementation of the CryptXmlDllCreateDigest.

'    fpCryptXmlFinalizeDigest
'        A pointer to the implementation of the CryptXmlDllFinalizeDigest.

'    fpCryptXmlCloseDigest
'        A pointer to the implementation of the CryptXmlDllCloseDigest.

'    fpCryptXmlSignData
'        A pointer to the implementation of the CryptXmlDllSignData.

'    fpCryptXmlVerifySignature
'        A pointer to the implementation of the CryptXmlDllVerifySignature.

'    fpCryptXmlGetAlgorithmInfo
'        A pointer to the implementation of the CryptXmlDllGetAlgorithmInfo.

'****************************************************************************/
' *** Moved above ***
' // Size = 36 bytes
'TYPE CRYPT_XML_CRYPTOGRAPHIC_INTERFACE DWORD
'   cbSize                     AS DWORD   ' ULONG
'   fpCryptXmlEncodeAlgorithm  AS DWORD   ' CryptXmlDllEncodeAlgorithm
'   fpCryptXmlCreateDigest     AS DWORD   ' CryptXmlDllCreateDigest
'   fpCryptXmlDigestData       AS DWORD   ' CryptXmlDllDigestData
'   fpCryptXmlFinalizeDigest   AS DWORD   ' CryptXmlDllFinalizeDigest
'   fpCryptXmlCloseDigest      AS DWORD   ' CryptXmlDllCloseDigest
'   fpCryptXmlSignData         AS DWORD   ' CryptXmlDllSignData
'   fpCryptXmlVerifySignature  AS DWORD   ' CryptXmlDllVerifySignature
'   fpCryptXmlGetAlgorithmInfo AS DWORD   ' CryptXmlDllGetAlgorithmInfo
'END TYPE

'/****************************************************************************
' * KEYINFO EXTENSIBILITY
' *
' ***************************************************************************/

'/****************************************************************************
' CryptXmlDllEncodeKeyValue

'    Address of installable function used to encode <*KeyValue> element.

'    hKey
'        [in] The handle of the key value to encode.

'    dwCharset
'        [in] Specifies a charset of the XML to be written to pfnWrite.

'    pvCallbackState
'        [in] An argument to be passed to the callback.

'    pfnWrite
'        [in, callback] A CryptXml defined callback to receive constructed XML.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllEncodeKeyValue IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllEncodeKeyValue" ( _
   BYVAL hKey AS DWORD _                                ' __in NCRYPT_KEY_HANDLE hKey
 , BYVAL dwCharset AS DWORD _                           ' __in CRYPT_XML_CHARSET dwCharset
 , BYREF pvCallbackState AS ANY _                       ' __inout void *pvCallbackState
 , BYVAL pfnWrite AS DWORD _                            ' __in PFN_CRYPT_XML_WRITE_CALLBACK pfnWrite
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' CryptXmlDllCreateKey

'    Address of installable function used to parse <*KeyValue> element and
'    create a CNG NCrypt key handle to verify signature.

'    pEncoded
'        [in] Specifies XML encoded <*KeyValue>.

'    phKey
'        [out] A key handle used to verify signature.
'        CryptXml calls BCryptDestroyKey when it's done using it.

'****************************************************************************/

DECLARE FUNCTION CryptXmlDllCreateKey IMPORT "Cryptxml.dll" ALIAS "CryptXmlDllCreateKey" ( _
   BYREF pEncoded AS CRYPT_XML_BLOB _                   ' __in const CRYPT_XML_BLOB *pEncoded
 , BYREF phKey AS DWORD _                               ' __out BCRYPT_KEY_HANDLE *phKey
 ) AS LONG                                              ' HRESULT
