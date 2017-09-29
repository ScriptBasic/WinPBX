' ########################################################################################
' Microsoft Windows
' File: casetup.inc
' Library name: CertSrvSetupLib
' Version: 1.0, Locale ID = 0
' Library GUID: {8ABC9D1A-02D4-42E4-B542-17B1EBCB2F51}
' Contents: Certificate Server Installer Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CASETUP_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "oaidl.inc"

$LIBID_CertSrvSetupLib = GUID$("{8ABC9D1A-02D4-42E4-B542-17B1EBCB2F51}")

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CCertificateEnrollmentPolicyServerSetup = GUID$("{AFE2FA32-41B1-459D-A5DE-49ADD8A72182}")
$CLSID_CCertificateEnrollmentServerSetup = GUID$("{9902F3BC-88AF-4CF8-AE62-7140531552B6}")
$CLSID_CCertSrvSetup = GUID$("{961F180F-F55C-413D-A9B3-7D2AF4D8E42F}")
$CLSID_CCertSrvSetupKeyInformation = GUID$("{38373906-5433-4633-B0FB-29B7E78262E1}")
$CLSID_CMSCEPSetup = GUID$("{AA4F5C02-8E7C-49C4-94FA-67A5CC5EADB4}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_ICertificateEnrollmentPolicyServerSetup = GUID$("{859252CC-238C-4A88-B8FD-A37E7D04E68B}")
$IID_ICertificateEnrollmentServerSetup = GUID$("{70027FDB-9DD9-4921-8944-B35CB31BD2EC}")
$IID_ICertSrvSetup = GUID$("{B760A1BB-4784-44C0-8F12-555F0780FF25}")
$IID_ICertSrvSetupKeyInformation = GUID$("{6BA73778-36DA-4C39-8A85-BCFA7D000793}")
$IID_ICertSrvSetupKeyInformationCollection = GUID$("{E65C8B00-E58F-41F9-A9EC-A28D7427C844}")
$IID_IMSCEPSetup = GUID$("{4F7761BB-9F3B-4592-9EE0-9A73259C313E}")

' ########################################################################################
' Interface name = ICertSrvSetupKeyInformation
' IID = {6BA73778-36DA-4C39-8A85-BCFA7D000793}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertSrvSetupKeyInformation_INTERFACE_DEFINED)
    %ICertSrvSetupKeyInformation_INTERFACE_DEFINED = 1

INTERFACE ICertSrvSetupKeyInformation $IID_ICertSrvSetupKeyInformation

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ProviderName <1> ( _                    ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ProviderName <1> ( _                    ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Length <2> ( _                          ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY SET Length <2> ( _                          ' VTable offset = 40
     BYVAL pVal AS LONG _                               ' __in LONG pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Existing <3> ( _                        ' VTable offset = 44
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pVal
   ' =====================================================================================
   PROPERTY SET Existing <3> ( _                        ' VTable offset = 48
     BYVAL pVal AS INTEGER _                            ' __in VARIANT_BOOL pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ContainerName <4> ( _                   ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ContainerName <4> ( _                   ' VTable offset = 56
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET HashAlgorithm <5> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET HashAlgorithm <5> ( _                   ' VTable offset = 64
     BYVAL pVal AS WSTRING _                            ' __in BSTR pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ExistingCACertificate <6> ( _           ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY SET ExistingCACertificate <6> ( _           ' VTable offset = 72
     BYVAL pVal AS VARIANT _                            ' __in VARIANT pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertSrvSetupKeyInformation_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ICertSrvSetupKeyInformationCollection
' IID = {E65C8B00-E58F-41F9-A9EC-A28D7427C844}
' Attributes = 4288 [&H10C0] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertSrvSetupKeyInformationCollection_INTERFACE_DEFINED)
    %ICertSrvSetupKeyInformationCollection_INTERFACE_DEFINED = 1

INTERFACE ICertSrvSetupKeyInformationCollection $IID_ICertSrvSetupKeyInformationCollection

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 28
   ) AS IUnknown                                        ' __retval_out IUnknown **ppVal
   ' =====================================================================================
   PROPERTY GET Item <0> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in LONG Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   METHOD Add <1610743811> ( _                          ' VTable offset = 40
     BYVAL pIKeyInformation AS ICertSrvSetupKeyInformation _ ' __in ICertSrvSetupKeyInformation *pIKeyInformation
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertSrvSetupKeyInformationCollection_INTERFACE_DEFINED__ */

' ========================================================================================
' CASetupProperty enum <alias> __MIDL___MIDL_itf_casetup_0000_0002_0001
' ========================================================================================

MACRO CASETUPPROPERTY_ENUM = LONG
%ENUM_SETUPPROP_INVALID                                 = -1
%ENUM_SETUPPROP_CATYPE                                  = 0
%ENUM_SETUPPROP_CAKEYINFORMATION                        = 1
%ENUM_SETUPPROP_INTERACTIVE                             = 2
%ENUM_SETUPPROP_CANAME                                  = 3
%ENUM_SETUPPROP_CADSSUFFIX                              = 4
%ENUM_SETUPPROP_VALIDITYPERIOD                          = 5
%ENUM_SETUPPROP_VALIDITYPERIODUNIT                      = 6
%ENUM_SETUPPROP_EXPIRATIONDATE                          = 7
%ENUM_SETUPPROP_PRESERVEDATABASE                        = 8
%ENUM_SETUPPROP_DATABASEDIRECTORY                       = 9
%ENUM_SETUPPROP_LOGDIRECTORY                            = 10
%ENUM_SETUPPROP_SHAREDFOLDER                            = 11
%ENUM_SETUPPROP_PARENTCAMACHINE                         = 12
%ENUM_SETUPPROP_PARENTCANAME                            = 13
%ENUM_SETUPPROP_REQUESTFILE                             = 14
%ENUM_SETUPPROP_WEBCAMACHINE                            = 15
%ENUM_SETUPPROP_WEBCANAME                               = 16

' ########################################################################################
' Interface name = ICertSrvSetup
' IID = {B760A1BB-4784-44C0-8F12-555F0780FF25}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertSrvSetup_INTERFACE_DEFINED)
    %ICertSrvSetup_INTERFACE_DEFINED = 1

INTERFACE ICertSrvSetup $IID_ICertSrvSetup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CAErrorId <1> ( _                       ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET CAErrorString <2> ( _                   ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD InitializeDefaults <1610743810> ( _           ' VTable offset = 36
     BYVAL bServer AS INTEGER _                         ' __in VARIANT_BOOL bServer
   , BYVAL bClient AS INTEGER _                         ' __in VARIANT_BOOL bClient
   )                                                    ' void
   ' =====================================================================================
   METHOD GetCASetupProperty <1610743811> ( _           ' VTable offset = 40
     BYVAL propertyId AS CASETUPPROPERTY_ENUM _         ' __in CASetupProperty propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *pPropertyValue
   ' =====================================================================================
   METHOD SetCASetupProperty <1610743812> ( _           ' VTable offset = 44
     BYVAL propertyId AS CASETUPPROPERTY_ENUM _         ' __in CASetupProperty propertyId
   , BYREF pPropertyValue AS VARIANT _                  ' __in VARIANT *pPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD IsPropertyEditable <1610743813> ( _           ' VTable offset = 48
     BYVAL propertyId AS CASETUPPROPERTY_ENUM _         ' __in CASetupProperty propertyId
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEditable
   ' =====================================================================================
   METHOD GetSupportedCATypes <1610743814> ( _          ' VTable offset = 52
   ) AS VARIANT                                         ' __retval_out VARIANT *pCATypes
   ' =====================================================================================
   METHOD GetProviderNameList <1610743815> ( _          ' VTable offset = 56
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetKeyLengthList <1610743816> ( _             ' VTable offset = 60
     BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetHashAlgorithmList <1610743817> ( _         ' VTable offset = 64
     BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetPrivateKeyContainerList <1610743818> ( _   ' VTable offset = 68
     BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetExistingCACertificates <1610743819> ( _    ' VTable offset = 72
   ) AS ICertSrvSetupKeyInformationCollection           ' __retval_out ICertSrvSetupKeyInformationCollection **ppVal
   ' =====================================================================================
   METHOD CAImportPFX <1610743820> ( _                  ' VTable offset = 76
     BYVAL bstrFileName AS WSTRING _                    ' __in BSTR bstrFileName
   , BYVAL bstrPasswd AS WSTRING _                      ' __in BSTR bstrPasswd
   , BYVAL bOverwriteExistingKey AS INTEGER _           ' __in VARIANT_BOOL bOverwriteExistingKey
   ) AS ICertSrvSetupKeyInformation                     ' __retval_out ICertSrvSetupKeyInformation **ppVal
   ' =====================================================================================
   METHOD SetCADistinguishedName <1610743821> ( _       ' VTable offset = 80
     BYVAL bstrCADN AS WSTRING _                        ' __in BSTR bstrCADN
   , BYVAL bIgnoreUnicode AS INTEGER _                  ' __in VARIANT_BOOL bIgnoreUnicode
   , BYVAL bOverwriteExistingKey AS INTEGER _           ' __in VARIANT_BOOL bOverwriteExistingKey
   , BYVAL bOverwriteExistingCAInDS AS INTEGER _        ' __in VARIANT_BOOL bOverwriteExistingCAInDS
   )                                                    ' void
   ' =====================================================================================
   METHOD SetDatabaseInformation <1610743822> ( _       ' VTable offset = 84
     BYVAL bstrDBDirectory AS WSTRING _                 ' __in BSTR bstrDBDirectory
   , BYVAL bstrLogDirectory AS WSTRING _                ' __in BSTR bstrLogDirectory
   , BYVAL bstrSharedFolder AS WSTRING _                ' __in BSTR bstrSharedFolder
   , BYVAL bForceOverwrite AS INTEGER _                 ' __in VARIANT_BOOL bForceOverwrite
   )                                                    ' void
   ' =====================================================================================
   METHOD SetParentCAInformation <1610743823> ( _       ' VTable offset = 88
     BYVAL bstrCAConfiguration AS WSTRING _             ' __in BSTR bstrCAConfiguration
   )                                                    ' void
   ' =====================================================================================
   METHOD SetWebCAInformation <1610743824> ( _          ' VTable offset = 92
     BYVAL bstrCAConfiguration AS WSTRING _             ' __in BSTR bstrCAConfiguration
   )                                                    ' void
   ' =====================================================================================
   METHOD Install <1610743825> ( _                      ' VTable offset = 96
   )                                                    ' void
   ' =====================================================================================
   METHOD PreUnInstall <1610743826> ( _                 ' VTable offset = 100
     BYVAL bClientOnly AS INTEGER _                     ' __in VARIANT_BOOL bClientOnly
   )                                                    ' void
   ' =====================================================================================
   METHOD PostUnInstall <1610743827> ( _                ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertSrvSetup_INTERFACE_DEFINED__ */

' ========================================================================================
' MSCEPSetupProperty enum <alias> __MIDL___MIDL_itf_casetup_0000_0003_0001
' ========================================================================================

MACRO MSCEPSETUPPROPERTY_ENUM = LONG
%ENUM_CEPSETUPPROP_USELOCALSYSTEM                       = 0
%ENUM_CEPSETUPPROP_USECHALLENGE                         = 1
%ENUM_CEPSETUPPROP_RANAME_CN                            = 2
%ENUM_CEPSETUPPROP_RANAME_EMAIL                         = 3
%ENUM_CEPSETUPPROP_RANAME_COMPANY                       = 4
%ENUM_CEPSETUPPROP_RANAME_DEPT                          = 5
%ENUM_CEPSETUPPROP_RANAME_CITY                          = 6
%ENUM_CEPSETUPPROP_RANAME_STATE                         = 7
%ENUM_CEPSETUPPROP_RANAME_COUNTRY                       = 8
%ENUM_CEPSETUPPROP_SIGNINGKEYINFORMATION                = 9
%ENUM_CEPSETUPPROP_EXCHANGEKEYINFORMATION               = 10
%ENUM_CEPSETUPPROP_CAINFORMATION                        = 11
%ENUM_CEPSETUPPROP_MSCEPURL                             = 12
%ENUM_CEPSETUPPROP_CHALLENGEURL                         = 13

' ########################################################################################
' Interface name = IMSCEPSetup
' IID = {4F7761BB-9F3B-4592-9EE0-9A73259C313E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSCEPSetup_INTERFACE_DEFINED)
    %IMSCEPSetup_INTERFACE_DEFINED = 1

INTERFACE IMSCEPSetup $IID_IMSCEPSetup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET MSCEPErrorId <1> ( _                    ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *pVal
   ' =====================================================================================
   PROPERTY GET MSCEPErrorString <2> ( _                ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD InitializeDefaults <1610743810> ( _           ' VTable offset = 36
   )                                                    ' void
   ' =====================================================================================
   METHOD GetMSCEPSetupProperty <1610743811> ( _        ' VTable offset = 40
     BYVAL propertyId AS MSCEPSETUPPROPERTY_ENUM _      ' __in MSCEPSetupProperty propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD SetMSCEPSetupProperty <1610743812> ( _        ' VTable offset = 44
     BYVAL propertyId AS MSCEPSETUPPROPERTY_ENUM _      ' __in MSCEPSetupProperty propertyId
   , BYREF pPropertyValue AS VARIANT _                  ' __in VARIANT *pPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetAccountInformation <1610743813> ( _        ' VTable offset = 48
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD IsMSCEPStoreEmpty <1610743814> ( _            ' VTable offset = 52
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *pbEmpty
   ' =====================================================================================
   METHOD GetProviderNameList <1610743815> ( _          ' VTable offset = 56
     BYVAL bExchange AS INTEGER _                       ' __in VARIANT_BOOL bExchange
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD GetKeyLengthList <1610743816> ( _             ' VTable offset = 60
     BYVAL bExchange AS INTEGER _                       ' __in VARIANT_BOOL bExchange
   , BYVAL bstrProviderName AS WSTRING _                ' __in BSTR bstrProviderName
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   METHOD Install <1610743817> ( _                      ' VTable offset = 64
   )                                                    ' void
   ' =====================================================================================
   METHOD PreUnInstall <1610743818> ( _                 ' VTable offset = 68
   )                                                    ' void
   ' =====================================================================================
   METHOD PostUnInstall <1610743819> ( _                ' VTable offset = 72
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSCEPSetup_INTERFACE_DEFINED__ */

' ========================================================================================
' CESSetupProperty enum <alias> __MIDL___MIDL_itf_casetup_0000_0004_0001
' ========================================================================================

MACRO CESSETUPPROPERTY_ENUM = LONG
%ENUM_CESSETUPPROP_USE_IISAPPPOOLIDENTITY               = 0
%ENUM_CESSETUPPROP_CACONFIG                             = 1
%ENUM_CESSETUPPROP_AUTHENTICATION                       = 2
%ENUM_CESSETUPPROP_SSLCERTHASH                          = 3
%ENUM_CESSETUPPROP_URL                                  = 4
%ENUM_CESSETUPPROP_RENEWALONLY                          = 5

' ########################################################################################
' Interface name = ICertificateEnrollmentServerSetup
' IID = {70027FDB-9DD9-4921-8944-B35CB31BD2EC}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificateEnrollmentServerSetup_INTERFACE_DEFINED)
    %ICertificateEnrollmentServerSetup_INTERFACE_DEFINED = 1

INTERFACE ICertificateEnrollmentServerSetup $IID_ICertificateEnrollmentServerSetup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ErrorString <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                          ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD InitializeInstallDefaults <1610743809> ( _    ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <1610743810> ( _                  ' VTable offset = 36
     BYVAL propertyId AS CESSETUPPROPERTY_ENUM _        ' __in CESSetupProperty propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *pPropertyValue
   ' =====================================================================================
   METHOD SetProperty <1610743811> ( _                  ' VTable offset = 40
     BYVAL propertyId AS CESSETUPPROPERTY_ENUM _        ' __in CESSetupProperty propertyId
   , BYREF pPropertyValue AS VARIANT _                  ' __in VARIANT *pPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD SetApplicationPoolCredentials <1610743812> ( _  ' VTable offset = 44
     BYVAL bstrUserName AS WSTRING _                    ' __in BSTR bstrUserName
   , BYVAL bstrPassword AS WSTRING _                    ' __in BSTR bstrPassword
   )                                                    ' void
   ' =====================================================================================
   METHOD Install <1610743813> ( _                      ' VTable offset = 48
   )                                                    ' void
   ' =====================================================================================
   METHOD UnInstall <1610743814> ( _                    ' VTable offset = 52
     OPTIONAL BYREF pCAConfig AS VARIANT _              ' __in_opt VARIANT *pCAConfig
   , OPTIONAL BYREF pAuthentication AS VARIANT _        ' __in_opt VARIANT *pAuthentication
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificateEnrollmentServerSetup_INTERFACE_DEFINED__ */

' ========================================================================================
' CEPSetupProperty enum <alias> __MIDL___MIDL_itf_casetup_0000_0005_0001
' ========================================================================================

MACRO CEPSETUPPROPERTY_ENUM = LONG
%ENUM_CEPSETUPPROP_AUTHENTICATION                       = 0
%ENUM_CEPSETUPPROP_SSLCERTHASH                          = 1
%ENUM_CEPSETUPPROP_URL                                  = 2

' ########################################################################################
' Interface name = ICertificateEnrollmentPolicyServerSetup
' IID = {859252CC-238C-4A88-B8FD-A37E7D04E68B}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ICertificateEnrollmentPolicyServerSetup_INTERFACE_DEFINED)
    %ICertificateEnrollmentPolicyServerSetup_INTERFACE_DEFINED = 1

INTERFACE ICertificateEnrollmentPolicyServerSetup $IID_ICertificateEnrollmentPolicyServerSetup

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ErrorString <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   METHOD InitializeInstallDefaults <1610743809> ( _    ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetProperty <1610743810> ( _                  ' VTable offset = 36
     BYVAL propertyId AS CEPSETUPPROPERTY_ENUM _        ' __in CEPSetupProperty propertyId
   ) AS VARIANT                                         ' __retval_out VARIANT *pPropertyValue
   ' =====================================================================================
   METHOD SetProperty <1610743811> ( _                  ' VTable offset = 40
     BYVAL propertyId AS CEPSETUPPROPERTY_ENUM _        ' __in CEPSetupProperty propertyId
   , BYREF pPropertyValue AS VARIANT _                  ' __in VARIANT *pPropertyValue
   )                                                    ' void
   ' =====================================================================================
   METHOD Install <1610743812> ( _                      ' VTable offset = 44
   )                                                    ' void
   ' =====================================================================================
   METHOD UnInstall <1610743813> ( _                    ' VTable offset = 48
     OPTIONAL BYREF pReserved AS VARIANT _              ' __in_opt VARIANT *pReserved
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICertificateEnrollmentPolicyServerSetup_INTERFACE_DEFINED__ */
