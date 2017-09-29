' ########################################################################################
' Microsoft Windows
' File: xpsdigitalsignature.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSXPSSIG
' Version: 0.0, Locale ID = 0
' Library GUID: {8223A7EB-C4D5-474D-9BCC-FF67185E64A0}
' ########################################################################################

#INCLUDE THIS ONCE
%XPSDIGITALSIGNATURE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "msopc.inc"

'//+-------------------------------------------------------------------------
'//
'//  Microsoft Windows
'//  Copyright (c) Microsoft Corporation. All rights reserved.
'//
'//--------------------------------------------------------------------------
'#if (NTDDI_VERSION >= NTDDI_WIN7)

$LIBID_MSXPSSIG = GUID$("{8223A7EB-C4D5-474D-9BCC-FF67185E64A0}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_XpsSignatureManager = GUID$("{B0C43320-2315-44A2-B70A-0943A140A8EE}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

'$IID_IOpcCertificateEnumerator = GUID$("{85131937-8F24-421F-B439-59AB24D140B8}")
'$IID_IOpcCertificateSet = GUID$("{56EA4325-8E2D-4167-B1A4-E486D24C8FA7}")
'$IID_IOpcPartUri = GUID$("{7D3BABE7-88B2-46BA-85CB-4203CB016C87}")
'$IID_IOpcSignatureCustomObject = GUID$("{5D77A19E-62C1-44E7-BECD-45DA5AE51A56}")
'$IID_IOpcSignatureCustomObjectEnumerator = GUID$("{5EE4FE1D-E1B0-4683-8079-7EA0FCF80B4C}")
'$IID_IOpcSignatureCustomObjectSet = GUID$("{8F792AC5-7947-4E11-BC3D-2659FF046AE1}")
'$IID_IOpcSignatureReference = GUID$("{1B47005E-3011-4EDC-BE6F-0F65E5AB0342}")
'$IID_IOpcSignatureReferenceEnumerator = GUID$("{CFA59A45-28B1-4868-969E-FA8097FDC12A}")
'$IID_IOpcSignatureReferenceSet = GUID$("{F3B02D31-AB12-42DD-9E2F-2B16761C3C1E}")
'$IID_IOpcUri = GUID$("{BC9C1B9B-D62C-49EB-AEF0-3B4E0B28EBED}")
'$IID_ISequentialStream = GUID$("{0C733A30-2A1C-11CE-ADE5-00AA0044773D}")
'$IID_IStream = GUID$("{0000000C-0000-0000-C000-000000000046}")
'$IID_IUri = GUID$("{A39EE748-6A27-4817-A6F2-13914BEF5890}")

$IID_IXpsSignature = GUID$("{6AE4C93E-1ADE-42FB-898B-3A5658284857}")
$IID_IXpsSignatureBlock = GUID$("{151FAC09-0B97-4AC6-A323-5E4297D4322B}")
$IID_IXpsSignatureBlockCollection = GUID$("{23397050-FE99-467A-8DCE-9237F074FFE4}")
$IID_IXpsSignatureCollection = GUID$("{A2D1D95D-ADD2-4DFF-AB27-6B9C645FF322}")
$IID_IXpsSignatureManager = GUID$("{D3E8D338-FDC4-4AFC-80B5-D532A1782EE1}")
$IID_IXpsSignatureRequest = GUID$("{AC58950B-7208-4B2D-B2C4-951083D3B8EB}")
$IID_IXpsSignatureRequestCollection = GUID$("{F0253E68-9F19-412E-9B4F-54D3B0AC6CD9}")
$IID_IXpsSigningOptions = GUID$("{7718EAE4-3215-49BE-AF5B-594FEF7FCFA6}")

' enum XPS_SIGNATURE_STATUS
%XPS_SIGNATURE_STATUS_INCOMPLIANT           = 1
%XPS_SIGNATURE_STATUS_INCOMPLETE            = 2
%XPS_SIGNATURE_STATUS_BROKEN                = 3
%XPS_SIGNATURE_STATUS_QUESTIONABLE          = 4
%XPS_SIGNATURE_STATUS_VALID                 = 5

' enum XPS_SIGN_POLICY
%XPS_SIGN_POLICY_NONE                       = 0???
%XPS_SIGN_POLICY_CORE_PROPERTIES            = &H1???
%XPS_SIGN_POLICY_SIGNATURE_RELATIONSHIPS    = &H2???
%XPS_SIGN_POLICY_PRINT_TICKET               = &H4???
%XPS_SIGN_POLICY_DISCARD_CONTROL            = &H8???
%XPS_SIGN_POLICY_ALL                        = &Hf???

' enum XPS_SIGN_FLAGS
%XPS_SIGN_FLAGS_NONE                        = 0???
%XPS_SIGN_FLAGS_IGNORE_MARKUP_COMPATIBILITY = &H1???

' ########################################################################################
' Interface name = IXpsSigningOptions
' IID = {7718EAE4-3215-49BE-AF5B-594FEF7FCFA6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSigningOptions_INTERFACE_DEFINED)
    %IXpsSigningOptions_INTERFACE_DEFINED = 1

INTERFACE IXpsSigningOptions $IID_IXpsSigningOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSignatureId ( _                            ' VTable offset = 12
     BYREF signatureId AS DWORD _                       ' __out LPWSTR *signatureId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignatureId ( _                            ' VTable offset = 16
     BYREF signatureId AS WSTRINGZ _                    ' __in LPCWSTR signatureId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureMethod ( _                        ' VTable offset = 20
     BYREF signatureMethod AS DWORD _                   ' __out LPWSTR *signatureMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignatureMethod ( _                        ' VTable offset = 24
     BYREF signatureMethod AS WSTRINGZ _                ' __in LPCWSTR signatureMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDigestMethod ( _                           ' VTable offset = 28
     BYREF digestMethod AS DWORD _                      ' __out LPWSTR *digestMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDigestMethod ( _                           ' VTable offset = 32
     BYREF digestMethod AS WSTRINGZ _                   ' __in LPCWSTR digestMethod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignaturePartName ( _                      ' VTable offset = 36
     BYREF signaturePartName AS IOpcPartUri _           ' __out IOpcPartUri **signaturePartName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignaturePartName ( _                      ' VTable offset = 40
     BYVAL signaturePartName AS IOpcPartUri _           ' __in IOpcPartUri *signaturePartName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicy ( _                                 ' VTable offset = 44
     BYREF policy AS DWORD _                            ' __out XPS_SIGN_POLICY *policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPolicy ( _                                 ' VTable offset = 48
     BYVAL policy AS DWORD _                            ' __in XPS_SIGN_POLICY policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningTimeFormat ( _                      ' VTable offset = 52
     BYREF timeFormat AS DWORD _                        ' __out OPC_SIGNATURE_TIME_FORMAT *timeFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSigningTimeFormat ( _                      ' VTable offset = 56
     BYVAL timeFormat AS LONG _                         ' __in OPC_SIGNATURE_TIME_FORMAT timeFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomObjects ( _                          ' VTable offset = 60
     BYREF customObjectSet AS IOpcSignatureCustomObjectSet _ ' __out IOpcSignatureCustomObjectSet **customObjectSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomReferences ( _                       ' VTable offset = 64
     BYREF customReferenceSet AS IOpcSignatureReferenceSet _ ' __out IOpcSignatureReferenceSet **customReferenceSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificateSet ( _                         ' VTable offset = 68
     BYREF certificateSet AS IOpcCertificateSet _       ' __out IOpcCertificateSet **certificateSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 72
     BYREF flags AS DWORD _                             ' __out XPS_SIGN_FLAGS *flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 76
     BYVAL flags AS DWORD _                             ' __in XPS_SIGN_FLAGS flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSigningOptions_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureCollection
' IID = {A2D1D95D-ADD2-4DFF-AB27-6B9C645FF322}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureCollection_INTERFACE_DEFINED)
    %IXpsSignatureCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureCollection $IID_IXpsSignatureCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF signature AS IXpsSignature _                 ' __out IXpsSignature **signature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignature
' IID = {6AE4C93E-1ADE-42FB-898B-3A5658284857}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignature_INTERFACE_DEFINED)
    %IXpsSignature_INTERFACE_DEFINED = 1

INTERFACE IXpsSignature $IID_IXpsSignature

   INHERIT IAutomation

   ' =====================================================================================
   METHOD GetSignatureId ( _                            ' VTable offset = 12
     BYREF sigId AS DWORD _                             ' __out LPWSTR *sigId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureValue ( _                         ' VTable offset = 16
     BYREF signatureHashValue AS DWORD _                ' __out UINT8 **signatureHashValue
   , BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificateEnumerator ( _                  ' VTable offset = 20
     BYREF certificateEnumerator AS IOpcCertificateEnumerator _ ' __out IOpcCertificateEnumerator **certificateEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningTime ( _                            ' VTable offset = 24
     BYREF sigDateTimeString AS DWORD _                 ' __out LPWSTR *sigDateTimeString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningTimeFormat ( _                      ' VTable offset = 28
     BYREF timeFormat AS LONG _                         ' __out OPC_SIGNATURE_TIME_FORMAT *timeFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignaturePartName ( _                      ' VTable offset = 32
     BYREF signaturePartName AS IOpcPartUri _           ' __out IOpcPartUri **signaturePartName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Verify ( _                                    ' VTable offset = 36
     BYREF x509Certificate AS CERT_CONTEXT _            ' __in CERT_CONTEXT *x509Certificate
   , BYREF sigStatus AS LONG _                          ' __out XPS_SIGNATURE_STATUS *sigStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicy ( _                                 ' VTable offset = 40
     BYREF policy AS LONG _                             ' __out XPS_SIGN_POLICY *policy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomObjectEnumerator ( _                 ' VTable offset = 44
     BYREF customObjectEnumerator AS IOpcSignatureCustomObjectEnumerator _ ' __out IOpcSignatureCustomObjectEnumerator **customObjectEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCustomReferenceEnumerator ( _              ' VTable offset = 48
     BYREF customReferenceEnumerator AS IOpcSignatureReferenceEnumerator _ ' __out IOpcSignatureReferenceEnumerator **customReferenceEnumerator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureXml ( _                           ' VTable offset = 52
     BYREF signatureXml AS DWORD _                      ' __out UINT8 **signatureXml
   , BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignatureXml ( _                           ' VTable offset = 56
     BYVAL signatureXml AS DWORD _                      ' __in UINT8 *signatureXml
   , BYVAL count AS DWORD _                             ' __in UINT32 count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignature_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureBlockCollection
' IID = {23397050-FE99-467A-8DCE-9237F074FFE4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureBlockCollection_INTERFACE_DEFINED)
    %IXpsSignatureBlockCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureBlockCollection $IID_IXpsSignatureBlockCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF signatureBlock AS IXpsSignatureBlock _       ' __out IXpsSignatureBlock **signatureBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureBlockCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureBlock
' IID = {151FAC09-0B97-4AC6-A323-5E4297D4322B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureBlock_INTERFACE_DEFINED)
    %IXpsSignatureBlock_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureBlock $IID_IXpsSignatureBlock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRequests ( _                               ' VTable offset = 12
     BYREF requests AS IXpsSignatureRequestCollection _ ' __out IXpsSignatureRequestCollection **requests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPartName ( _                               ' VTable offset = 16
     BYREF partName AS IOpcPartUri _                    ' __out IOpcPartUri **partName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentIndex ( _                          ' VTable offset = 20
     BYREF fixedDocumentIndex AS DWORD _                ' __out UINT32 *fixedDocumentIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocumentName ( _                           ' VTable offset = 24
     BYREF fixedDocumentName AS IOpcPartUri _           ' __out IOpcPartUri **fixedDocumentName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateRequest ( _                             ' VTable offset = 28
     BYREF requestId AS WSTRINGZ _                      ' __in LPCWSTR requestId
   , BYREF signatureRequest AS IXpsSignatureRequest _   ' __out IXpsSignatureRequest **signatureRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureBlock_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureRequestCollection
' IID = {F0253E68-9F19-412E-9B4F-54D3B0AC6CD9}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureRequestCollection_INTERFACE_DEFINED)
    %IXpsSignatureRequestCollection_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureRequestCollection $IID_IXpsSignatureRequestCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF count AS DWORD _                             ' __out UINT32 *count
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAt ( _                                     ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in UINT32 index
   , BYREF signatureRequest AS IXpsSignatureRequest _   ' __out IXpsSignatureRequest **signatureRequest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAt ( _                                  ' VTable offset = 20
     BYVAL index AS DWORD _                             ' __in UINT32 index
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureRequestCollection_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureRequest
' IID = {AC58950B-7208-4B2D-B2C4-951083D3B8EB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureRequest_INTERFACE_DEFINED)
    %IXpsSignatureRequest_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureRequest $IID_IXpsSignatureRequest

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIntent ( _                                 ' VTable offset = 12
     BYREF intent AS DWORD _                            ' __out LPWSTR *intent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIntent ( _                                 ' VTable offset = 16
     BYREF intent AS WSTRINGZ _                         ' __in LPCWSTR intent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRequestedSigner ( _                        ' VTable offset = 20
     BYREF signerName AS DWORD _                        ' __out LPWSTR *signerName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRequestedSigner ( _                        ' VTable offset = 24
     BYREF signerName AS WSTRINGZ _                     ' __in LPCWSTR signerName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRequestSignByDate ( _                      ' VTable offset = 28
     BYREF dateString AS DWORD _                        ' __out LPWSTR dateString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRequestSignByDate ( _                      ' VTable offset = 32
     BYREF dateString AS WSTRINGZ _                     ' __in LPCWSTR dateString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSigningLocale ( _                          ' VTable offset = 36
     BYREF place AS DWORD _                             ' __out LPWSTR *place
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSigningLocale ( _                          ' VTable offset = 40
     BYREF place AS WSTRINGZ _                          ' __in LPCWSTR place
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpotLocation ( _                           ' VTable offset = 44
     BYREF pageIndex AS LONG _                          ' __out INT32 *pageIndex
   , BYREF pagePartName AS IOpcPartUri _                ' __out IOpcPartUri **pagePartName
   , BYREF x AS SINGLE _                                ' __out float *x
   , BYREF y AS SINGLE _                                ' __out float *y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSpotLocation ( _                           ' VTable offset = 48
     BYVAL pageIndex AS LONG _                          ' __in INT32 pageIndex
   , BYVAL x AS SINGLE _                                ' __in float x
   , BYVAL y AS SINGLE _                                ' __in float y
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRequestId ( _                              ' VTable offset = 52
     BYREF requestId AS DWORD _                         ' __out LPWSTR *requestId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignature ( _                              ' VTable offset = 56
     BYREF signature AS IXpsSignature _                 ' __out IXpsSignature **signature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXpsSignatureManager
' IID = {D3E8D338-FDC4-4AFC-80B5-D532A1782EE1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXpsSignatureManager_INTERFACE_DEFINED)
    %IXpsSignatureManager_INTERFACE_DEFINED = 1

INTERFACE IXpsSignatureManager $IID_IXpsSignatureManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadPackageFile ( _                           ' VTable offset = 12
     BYREF fileName AS WSTRINGZ _                       ' __in LPCWSTR fileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadPackageStream ( _                         ' VTable offset = 16
     BYVAL stream AS IStream _                          ' __in IStream *stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Sign ( _                                      ' VTable offset = 20
     BYVAL signOptions AS IXpsSigningOptions _          ' __in IXpsSigningOptions *signOptions
   , BYREF x509Certificate AS CERT_CONTEXT _            ' __in const CERT_CONTEXT *x509Certificat
   , BYREF signature AS IXpsSignature _                 ' __out IXpsSignature **signature
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureOriginPartName ( _                ' VTable offset = 24
     BYREF signatureOriginPartName AS IOpcPartUri _     ' __out IOpcPartUri **signatureOriginPartName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSignatureOriginPartName ( _                ' VTable offset = 28
     BYVAL signatureOriginPartName AS IOpcPartUri _     ' __in IOpcPartUri *signatureOriginPartName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatures ( _                             ' VTable offset = 32
     BYREF signatures AS IXpsSignatureCollection _      ' __out IXpsSignatureCollection **signatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSignatureBlock ( _                         ' VTable offset = 36
     BYVAL partName AS IOpcPartUri _                    ' __in IOpcPartUri *partName
   , BYVAL fixedDocumentIndex AS DWORD _                ' __in UINT32 fixedDocumentIndex
   , BYREF signatureBlock AS IXpsSignatureBlock _       ' __out IXpsSignatureBlock **signatureBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSignatureBlocks ( _                        ' VTable offset = 40
     BYREF signatureBlocks AS IXpsSignatureBlockCollection _ ' __out IXpsSignatureBlockCollection **signatureBlocks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSigningOptions ( _                      ' VTable offset = 44
     BYREF signingOptions AS IXpsSigningOptions _       ' __out IXpsSigningOptions **signingOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SavePackageToFile ( _                         ' VTable offset = 48
     BYREF fileName AS WSTRINGZ _                       ' __in LPCWSTR fileName
   , BYREF securityAttributes AS SECURITY_ATTRIBUTES _  ' __in LPSECURITY_ATTRIBUTES securityAttributes
   , BYVAL flagsAndAttributes AS DWORD _                ' __in DWORD flagsAndAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SavePackageToStream ( _                       ' VTable offset = 52
     BYVAL stream AS IStream _                          ' __in IStream *stream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXpsSignatureManager_INTERFACE_DEFINED__ */


%XPS_E_SIGREQUESTID_DUP               = &H80520385&   ' MAKE_HRESULT(1, FACILITY_XPS, 901)
%XPS_E_PACKAGE_NOT_OPENED             = &H80520386&   ' MAKE_HRESULT(1, FACILITY_XPS, 902)
%XPS_E_PACKAGE_ALREADY_OPENED         = &H80520387&   ' MAKE_HRESULT(1, FACILITY_XPS, 903)
%XPS_E_SIGNATUREID_DUP                = &H80520388&   ' MAKE_HRESULT(1, FACILITY_XPS, 904)
%XPS_E_MARKUP_COMPATIBILITY_ELEMENTS  = &H80520389&   ' MAKE_HRESULT(1, FACILITY_XPS, 905)
%XPS_E_OBJECT_DETACHED                = &H8052038a&   ' MAKE_HRESULT(1, FACILITY_XPS, 906)
%XPS_E_INVALID_SIGNATUREBLOCK_MARKUP  = &H8052038b&   ' MAKE_HRESULT(1, FACILITY_XPS, 907)

'#endif // (NTDDI >= NTDDI_WIN7)
