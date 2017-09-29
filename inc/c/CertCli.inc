' ########################################################################################
' Microsoft Windows
' File: CertCli.inc
' Library name: CERTCLIENTLib
' Version: 1.0, Locale ID = 0
' Library GUID: {372FCE32-4324-11D0-8810-00A0C903B83C}
' Path: C:\WINDOWS\system32\certcli.dll
' Contents: CertCli 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CERTCLI_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "certif.inc"

$LIBID_CERTCLIENTLib = GUID$("{372FCE32-4324-11D0-8810-00A0C903B83C}")

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {372FCE38-4324-11D0-8810-00A0C903B83C}
$PROGID_CertificateAuthorityConfig1 = "CertificateAuthority.Config.1"
' CLSID = {C6CC49B0-CE17-11D0-8833-00A0C903B83C}
$PROGID_CertificateAuthorityGetConfig1 = "CertificateAuthority.GetConfig.1"
' CLSID = {98AFF3F0-5524-11D0-8812-00A0C903B83C}
$PROGID_CertificateAuthorityRequest1 = "CertificateAuthority.Request.1"
' CLSID = {4C4A5E40-732C-11D0-8816-00A0C903B83C}
$PROGID_CertificateAuthorityServerExit1 = "CertificateAuthority.ServerExit.1"
' CLSID = {AA000926-FFBE-11CF-8800-00A0C903B83C}
$PROGID_CertificateAuthorityServerPolicy1 = "CertificateAuthority.ServerPolicy.1"

' ========================================================================================
' Version independent ProgIDs
' ========================================================================================

' CLSID = {372FCE38-4324-11D0-8810-00A0C903B83C}
$PROGID_CertificateAuthorityConfig = "CertificateAuthority.Config"
' CLSID = {C6CC49B0-CE17-11D0-8833-00A0C903B83C}
$PROGID_CertificateAuthorityGetConfig = "CertificateAuthority.GetConfig"
' CLSID = {98AFF3F0-5524-11D0-8812-00A0C903B83C}
$PROGID_CertificateAuthorityRequest = "CertificateAuthority.Request"
' CLSID = {4C4A5E40-732C-11D0-8816-00A0C903B83C}
$PROGID_CertificateAuthorityServerExit = "CertificateAuthority.ServerExit"
' CLSID = {AA000926-FFBE-11CF-8800-00A0C903B83C}
$PROGID_CertificateAuthorityServerPolicy = "CertificateAuthority.ServerPolicy"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CCertConfig       = GUID$("{372FCE38-4324-11D0-8810-00A0C903B83C}")
$CLSID_CCertGetConfig    = GUID$("{C6CC49B0-CE17-11D0-8833-00A0C903B83C}")
$CLSID_CCertRequest      = GUID$("{98AFF3F0-5524-11D0-8812-00A0C903B83C}")
$CLSID_CCertServerExit   = GUID$("{4C4A5E40-732C-11D0-8816-00A0C903B83C}")
$CLSID_CCertServerPolicy = GUID$("{AA000926-FFBE-11CF-8800-00A0C903B83C}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICertConfig         = GUID$("{372FCE34-4324-11D0-8810-00A0C903B83C}")
$IID_ICertConfig2        = GUID$("{7A18EDDE-7E78-4163-8DED-78E2C9CEE924}")
$IID_ICertGetConfig      = GUID$("{C7EA09C0-CE17-11D0-8833-00A0C903B83C}")
$IID_ICertRequest        = GUID$("{014E4840-5523-11D0-8812-00A0C903B83C}")
$IID_ICertRequest2       = GUID$("{A4772988-4A85-4FA9-824E-B5CF5C16405A}")
$IID_ICertRequest3       = GUID$("{AFC8F92B-33A2-4861-BF36-2933B7CD67B3}")


' ########################################################################################
' Interface name = ICertGetConfig
' IID = {C7EA09C0-CE17-11D0-8833-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertGetConfig_INTERFACE_DEFINED)
    %ICertGetConfig_INTERFACE_DEFINED = 1

INTERFACE ICertGetConfig $IID_ICertGetConfig

   INHERIT IDispatch

   ' =====================================================================================
   METHOD GetConfig ( _                                 ' VTable offset = 28
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertGetConfig_INTERFACE_DEFINED__ */

$$wszCONFIG_COMMONNAME           = "CommonName"$$
$$wszCONFIG_ORGUNIT              = "OrgUnit"$$
$$wszCONFIG_ORGANIZATION         = "Organization"$$
$$wszCONFIG_LOCALITY             = "Locality"$$
$$wszCONFIG_STATE                = "State"$$
$$wszCONFIG_COUNTRY              = "Country"$$
$$wszCONFIG_CONFIG               = "Config"$$
$$wszCONFIG_EXCHANGECERTIFICATE  = "ExchangeCertificate"$$
$$wszCONFIG_SIGNATURECERTIFICATE = "SignatureCertificate"$$
$$wszCONFIG_DESCRIPTION          = "Description"$$
$$wszCONFIG_COMMENT              = "Comment"$$   ' // obsolete: use Description
$$wszCONFIG_SERVER               = "Server"$$
$$wszCONFIG_AUTHORITY            = "Authority"$$
$$wszCONFIG_SANITIZEDNAME        = "SanitizedName"$$
$$wszCONFIG_SHORTNAME            = "ShortName"$$
$$wszCONFIG_SANITIZEDSHORTNAME   = "SanitizedShortName"$$
$$wszCONFIG_FLAGS                = "Flags"$$
$$wszCONFIG_WEBENROLLMENTSERVERS = "WebEnrollmentServers"$$

%CAIF_DSENTRY           = &H1
%CAIF_SHAREDFOLDERENTRY = &H2
%CAIF_REGISTRY          = &H4
%CAIF_LOCAL             = &H8
%CAIF_REGISTRYPARENT    = &H10


' ########################################################################################
' Interface name = ICertConfig
' IID = {372FCE34-4324-11D0-8810-00A0C903B83C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertConfig_INTERFACE_DEFINED)
    %ICertConfig_INTERFACE_DEFINED = 1

INTERFACE ICertConfig $IID_ICertConfig

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD GetField ( _                                  ' VTable offset = 36
     BYVAL strFieldName AS WSTRING _                    ' __in const BSTR strFieldName
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetConfig ( _                                 ' VTable offset = 40
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = ICertConfig2
' IID = {7A18EDDE-7E78-4163-8DED-78E2C9CEE924}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertConfig
' ########################################################################################

#IF NOT %DEF(%ICertConfig2_INTERFACE_DEFINED)
    %ICertConfig2_INTERFACE_DEFINED = 1

INTERFACE ICertConfig2 $IID_ICertConfig2

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS LONG                                            ' __retval_out LONG *pCount
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 32
   ) AS LONG                                            ' __retval_out LONG *pIndex
   ' =====================================================================================
   METHOD GetField ( _                                  ' VTable offset = 36
     BYVAL strFieldName AS WSTRING _                    ' __in const BSTR strFieldName
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD GetConfig ( _                                 ' VTable offset = 40
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrOut
   ' =====================================================================================
   METHOD SetSharedFolder ( _                           ' VTable offset = 44
     BYVAL strSharedFolder AS WSTRING _                 ' __in const BSTR strSharedFolder
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertConfig2_INTERFACE_DEFINED__ */


%CR_IN_BASE64HEADER         = 0
%CR_IN_BASE64               = &H1
%CR_IN_BINARY               = &H2
%CR_IN_ENCODEANY            = &Hff
%CR_IN_ENCODEMASK           = &Hff
%CR_IN_FORMATANY            = 0
%CR_IN_PKCS10               = &H100
%CR_IN_KEYGEN               = &H200
%CR_IN_PKCS7                = &H300
%CR_IN_CMC                  = &H400
%CR_IN_FORMATMASK           = &Hff00
%CR_IN_RPC                  = &H20000
%CR_IN_FULLRESPONSE         = &H40000
%CR_IN_CRLS                 = &H80000
%CR_IN_MACHINE              = &H100000
%CR_IN_ROBO                 = &H200000
%CR_IN_CLIENTIDNONE         = &H400000
%CR_IN_CONNECTONLY          = &H800000
%CR_IN_CLIENTFLAGSMASK      = (((((%CR_IN_ENCODEMASK OR %CR_IN_RPC) OR %CR_IN_MACHINE) OR %CR_IN_CLIENTIDNONE) OR %CR_IN_CONNECTONLY))

%CC_DEFAULTCONFIG           = 0
%CC_UIPICKCONFIG            = &H1
%CC_FIRSTCONFIG             = &H2
%CC_LOCALCONFIG             = &H3
%CC_LOCALACTIVECONFIG       = &H4
%CC_UIPICKCONFIGSKIPLOCALCA = &H5

%CR_DISP_INCOMPLETE         = 0
%CR_DISP_ERROR              = &H1
%CR_DISP_DENIED             = &H2
%CR_DISP_ISSUED             = &H3
%CR_DISP_ISSUED_OUT_OF_BAND = &H4
%CR_DISP_UNDER_SUBMISSION   = &H5
%CR_DISP_REVOKED            = &H6
%CR_OUT_BASE64HEADER        = 0
%CR_OUT_BASE64              = &H1
%CR_OUT_BINARY              = &H2
%CR_OUT_ENCODEMASK          = &Hff
%CR_OUT_CHAIN               = &H100
%CR_OUT_CRLS                = &H200
%CR_GEMT_HRESULT_STRING     = &H1

%CR_PROP_NONE               = 0   ' // Invalid
%CR_PROP_FILEVERSION        = 1   ' // String
%CR_PROP_PRODUCTVERSION     = 2   ' // String
%CR_PROP_EXITCOUNT          = 3   ' // Long

'// CR_PROP_EXITCOUNT Elements:
%CR_PROP_EXITDESCRIPTION    = 4   ' // String, Indexed

%CR_PROP_POLICYDESCRIPTION  = 5   ' // String
%CR_PROP_CANAME             = 6   ' // String
%CR_PROP_SANITIZEDCANAME    = 7   ' // String
%CR_PROP_SHAREDFOLDER       = 8   ' // String
%CR_PROP_PARENTCA           = 9   ' // String
%CR_PROP_CATYPE             = 10  ' // Long
%CR_PROP_CASIGCERTCOUNT     = 11  ' // Long

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CASIGCERT          = 12   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CASIGCERTCHAIN     = 13   ' // Binary, Indexed

%CR_PROP_CAXCHGCERTCOUNT    = 14   ' // Long

'// CR_PROP_CAXCHGCERTCOUNT Elements:
%CR_PROP_CAXCHGCERT         = 15   ' // Binary, Indexed

'// CR_PROP_CAXCHGCERTCOUNT Elements:
%CR_PROP_CAXCHGCERTCHAIN    = 16   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
'// Fetch only if CR_PROP_CRLSTATE[i] == CA_DISP_VALID
'// May also be available if CR_PROP_CRLSTATE[i] == CA_DISP_INVALID
%CR_PROP_BASECRL            = 17   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
'// Fetch only if Delta CRLs enabled && CR_PROP_CRLSTATE[i] == CA_DISP_VALID
'// May also be available if CR_PROP_CRLSTATE[i] == CA_DISP_INVALID
%CR_PROP_DELTACRL           = 18   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CACERTSTATE        = 19   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CRLSTATE           = 20   ' // Long, Indexed

%CR_PROP_CAPROPIDMAX        = 21   ' // Long
%CR_PROP_DNSNAME            = 22   ' // String
%CR_PROP_ROLESEPARATIONENABLED = 23  ' // Long
%CR_PROP_KRACERTUSEDCOUNT   = 24   ' // Long
%CR_PROP_KRACERTCOUNT       = 25   ' // Long

'// CR_PROP_KRACERTCOUNT Elements:
%CR_PROP_KRACERT            = 26   ' // Binary, Indexed

'// CR_PROP_KRACERTCOUNT Elements:
%CR_PROP_KRACERTSTATE       = 27   ' // Long, Indexed

%CR_PROP_ADVANCEDSERVER     = 28   ' // Long
%CR_PROP_TEMPLATES          = 29   ' // String

'// CR_PROP_CASIGCERTCOUNT Elements:
'// Fetch only if CR_PROP_CRLSTATE[i] == CA_DISP_VALID
%CR_PROP_BASECRLPUBLISHSTATUS = 30   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
'// Fetch only if Delta CRLs enabled && CR_PROP_CRLSTATE[i] == CA_DISP_VALID
%CR_PROP_DELTACRLPUBLISHSTATUS = 31   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CASIGCERTCRLCHAIN = 32   ' // Binary, Indexed

'// CR_PROP_CAXCHGCERTCOUNT Elements:
%CR_PROP_CAXCHGCERTCRLCHAIN = 33  ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CACERTSTATUSCODE  = 34   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CAFORWARDCROSSCERT = 35   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CABACKWARDCROSSCERT = 36   ' // Binary, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CAFORWARDCROSSCERTSTATE = 37   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CABACKWARDCROSSCERTSTATE = 38   ' // Long, Indexed

'// CR_PROP_CASIGCERTCOUNT Elements:
%CR_PROP_CACERTVERSION        = 39   ' // Long, Indexed
%CR_PROP_SANITIZEDCASHORTNAME = 40   ' // String

'// CR_PROP_CERTCDPURLS Elements:
%CR_PROP_CERTCDPURLS = 41   ' // String, Indexed

'// CR_PROP_CERTAIAURLS Elements:
%CR_PROP_CERTAIAURLS = 42   ' // String, Indexed

'// CR_PROP_CERTAIAOCSPURLS Elements:
%CR_PROP_CERTAIAOCSPURLS = 43   ' // String, Indexed

'// CR_PROP_LOCALENAME Elements:
%CR_PROP_LOCALENAME = 44   ' // String


%FR_PROP_NONE                    = 0   ' // Invalid
%FR_PROP_FULLRESPONSE            = 1   ' // Binary
%FR_PROP_STATUSINFOCOUNT         = 2   ' // Long

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_BODYPARTSTRING          = 3   ' // String, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_STATUS                  = 4   ' // Long, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_STATUSSTRING            = 5   ' // String, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_OTHERINFOCHOICE         = 6   ' // Long, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_FAILINFO                = 7   ' // Long, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_PENDINFOTOKEN           = 8   ' // Binary, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_PENDINFOTIME            = 9   ' // Date, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_ISSUEDCERTIFICATEHASH  = 10   ' // Binary, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_ISSUEDCERTIFICATE      = 11   ' // Binary, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_ISSUEDCERTIFICATECHAIN = 12   ' // Binary, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_ISSUEDCERTIFICATECRLCHAIN = 13   ' // Binary, Indexed

'// FR_PROP_STATUSINFOCOUNT Elements:
%FR_PROP_ENCRYPTEDKEYHASH       = 14   ' // Binary, Indexed

%FR_PROP_FULLRESPONSENOPKCS7    = 15  ' // Binary


' ########################################################################################
' Interface name = ICertRequest
' IID = {014E4840-5523-11D0-8812-00A0C903B83C}
' ICertRequest Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertRequest_INTERFACE_DEFINED)
    %ICertRequest_INTERFACE_DEFINED = 1

INTERFACE ICertRequest $IID_ICertRequest

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Submit ( _                                    ' VTable offset = 28
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strRequest AS WSTRING _                      ' __in const BSTR strRequest
   , BYVAL strAttributes AS WSTRING _                   ' __in const BSTR strAttributes
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD RetrievePending ( _                           ' VTable offset = 32
     BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetLastStatus ( _                             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pStatus
   ' =====================================================================================
   METHOD GetRequestId ( _                              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pRequestId
   ' =====================================================================================
   METHOD GetDispositionMessage ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDispositionMessage
   ' =====================================================================================
   METHOD GetCACertificate ( _                          ' VTable offset = 48
     BYVAL fExchangeCertificate AS LONG _               ' __in LONG fExchangeCertificate
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 52
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertRequest_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertRequest2
' IID = {A4772988-4A85-4FA9-824E-B5CF5C16405A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertRequest
' ########################################################################################

#IF NOT %DEF(%ICertRequest2_INTERFACE_DEFINED)
    %ICertRequest2_INTERFACE_DEFINED = 1

INTERFACE ICertRequest2 $IID_ICertRequest2

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertRequest methods
   ' =====================================================================================
   METHOD Submit ( _                                    ' VTable offset = 28
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strRequest AS WSTRING _                      ' __in const BSTR strRequest
   , BYVAL strAttributes AS WSTRING _                   ' __in const BSTR strAttributes
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD RetrievePending ( _                           ' VTable offset = 32
     BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetLastStatus ( _                             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pStatus
   ' =====================================================================================
   METHOD GetRequestId ( _                              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pRequestId
   ' =====================================================================================
   METHOD GetDispositionMessage ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDispositionMessage
   ' =====================================================================================
   METHOD GetCACertificate ( _                          ' VTable offset = 48
     BYVAL fExchangeCertificate AS LONG _               ' __in LONG fExchangeCertificate
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 52
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================

   ' =====================================================================================
   ' ICertRequest2 methods
   ' =====================================================================================
   METHOD GetIssuedCertificate ( _                      ' VTable offset = 56
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetErrorMessageText ( _                       ' VTable offset = 60
     BYVAL hrMessage AS LONG _                          ' __in LONG hrMessage
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrErrorMessageText
   ' =====================================================================================
   METHOD GetCAProperty ( _                             ' VTable offset = 64
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD GetCAPropertyFlags ( _                        ' VTable offset = 68
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS LONG                                            ' __retval_out LONG *pPropFlags
   ' =====================================================================================
   METHOD GetCAPropertyDisplayName ( _                  ' VTable offset = 72
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   METHOD GetFullResponseProperty ( _                   ' VTable offset = 76
     BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertRequest2_INTERFACE_DEFINED__ */

' enum X509EnrollmentAuthFlags
%X509AuthNone        = 0
%X509AuthAnonymous   = 1
%X509AuthKerberos    = 2
%X509AuthUsername    = 4
%X509AuthCertificate = 8

' ########################################################################################
' Interface name = ICertRequest3
' IID = AFC8F92B-33A2-4861-BF36-2933B7CD67B3
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = ICertRequest2
' ########################################################################################

#IF NOT %DEF(%ICertRequest3_INTERFACE_DEFINED)
    %ICertRequest3_INTERFACE_DEFINED = 1

INTERFACE ICertRequest3 $IID_ICertRequest3

   INHERIT IDispatch

   ' =====================================================================================
   ' ICertRequest methods
   ' =====================================================================================
   METHOD Submit ( _                                    ' VTable offset = 28
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   , BYVAL strRequest AS WSTRING _                      ' __in const BSTR strRequest
   , BYVAL strAttributes AS WSTRING _                   ' __in const BSTR strAttributes
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD RetrievePending ( _                           ' VTable offset = 32
     BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetLastStatus ( _                             ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pStatus
   ' =====================================================================================
   METHOD GetRequestId ( _                              ' VTable offset = 40
   ) AS LONG                                            ' __retval_out LONG *pRequestId
   ' =====================================================================================
   METHOD GetDispositionMessage ( _                     ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDispositionMessage
   ' =====================================================================================
   METHOD GetCACertificate ( _                          ' VTable offset = 48
     BYVAL fExchangeCertificate AS LONG _               ' __in LONG fExchangeCertificate
   , BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 52
     BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrCertificate
   ' =====================================================================================

   ' =====================================================================================
   ' ICertRequest2 methods
   ' =====================================================================================
   METHOD GetIssuedCertificate ( _                      ' VTable offset = 56
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL RequestId AS LONG _                          ' __in LONG RequestId
   , BYVAL strSerialNumber AS WSTRING _                 ' __in const BSTR strSerialNumber
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetErrorMessageText ( _                       ' VTable offset = 60
     BYVAL hrMessage AS LONG _                          ' __in LONG hrMessage
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS WSTRING                                         ' __retval_out BSTR *pstrErrorMessageText
   ' =====================================================================================
   METHOD GetCAProperty ( _                             ' VTable offset = 64
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================
   METHOD GetCAPropertyFlags ( _                        ' VTable offset = 68
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS LONG                                            ' __retval_out LONG *pPropFlags
   ' =====================================================================================
   METHOD GetCAPropertyDisplayName ( _                  ' VTable offset = 72
     BYVAL strConfig AS WSTRING _                       ' __in const BSTR strConfig
   , BYVAL PropId AS LONG _                             ' __in LONG PropId
   ) AS WSTRING                                         ' __retval_out BSTR *pstrDisplayName
   ' =====================================================================================
   METHOD GetFullResponseProperty ( _                   ' VTable offset = 76
     BYVAL PropId AS LONG _                             ' __in LONG PropId
   , BYVAL PropIndex AS LONG _                          ' __in LONG PropIndex
   , BYVAL PropType AS LONG _                           ' __in LONG PropType
   , BYVAL Flags AS LONG _                              ' __in LONG Flags
   ) AS VARIANT                                         ' __retval_out VARIANT *pvarPropertyValue
   ' =====================================================================================

   ' =====================================================================================
   ' ICertRequest3 methods
   ' =====================================================================================
   METHOD SetCredential ( _                             ' VTable offset = 80
     BYVAL hWnd AS LONG _                               ' __in LONG hWnd
   , BYVAL AuthType AS LONG _                           ' __in X509EnrollmentAuthFlags AuthType
   , BYVAL strCredential AS WSTRING _                   ' __in BSTR strCredential
   , BYVAL strPassword AS WSTRING _                     ' __in BSTR strPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRequestIdString ( _                        ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pstrRequestId
   ' =====================================================================================
   METHOD GetIssuedCertificate2 ( _                     ' VTable offset = 88
     BYVAL strConfig AS WSTRING _                       ' __in BSTR strConfig
   , BYVAL strRequestId AS WSTRING _                    ' __in BSTR strRequestId
   , BYVAL strSerialNumber AS WSTRING _                 ' __in BSTR strSerialNumber
   ) AS LONG                                            ' __retval_out LONG *pDisposition
   ' =====================================================================================
   METHOD GetRefreshPolicy ( _                          ' VTable offset = 92
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pValue
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertRequest3_INTERFACE_DEFINED__ */
